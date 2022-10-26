//
// Created by Admin on 2022/10/25.
//
#include "../GlobalService.h"
#include "../MC/Global.h"
#include "../MC/ClientInstance.h"
#include "../Logger/Logger.h"

bool ClientInstanceTick = false;
SHook2("ClientInstance::Tick",
       __int64,"48 89 ?? ?? ?? 48 89 ?? ?? ?? 57 48 ?? ?? ?? 48 8B F9 48 8B 01 48 8D ?? ?? ?? FF ?? ?? ?? ?? ?? 90 48 8B 08 48 85 C9 74 ??",ClientInstance* client) {
    if(!ClientInstanceTick) {
        Global<ClientInstance> = client;
        Info("ClientInstance base: {}", (void *) client);
        ClientInstanceTick = true;
    }
    return original(client);
}

//sendMsg
#include "../MC/Vec3.h"
SHook(__int64,"48 89 ?? ?? ?? 55 56 57 41 54 41 55 41 56 41 57 48 8D ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? 48 33 C4 48 89 ?? ?? ?? ?? ?? 4C 8B EA 4C 8B F9 48 8B ?? ?? 48 8B 01",void* a1,std::string message){
    if (message.length() > 0) {
        if (message.at(0) == '.' && message.length() > 1) {
            Global<LocalPlayer>->displayChatMessage("你世界","你世界");

            return 0;
        }
    }
    return original(a1,message);
}

SHook(LocalPlayer*,"40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? ?? 48 33 C4 48 89 ?? ?? ?? ?? ?? 4C 89 ?? ?? 4C 89 ?? ?? 48 8B DA 48 89 ?? ?? 48 89 ?? ??"
      ,LocalPlayer *a1,
      __int64 a2,
      __int64 *a3,
      __int64 a4,
      int a5,
      __int64 a6,
      char a7,
      __int64 *a8,
      __int64 a9,
      __int64 a10,
      __int64 *a11,
      __int64 *a12){
    auto out = original(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);\
    Global<LocalPlayer> = out;
    return out;
}
