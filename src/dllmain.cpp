#include <Windows.h>
#include "Logger/Logger.h"
void Init();

BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        static const auto rangeStart = (void*)GetModuleHandleA("Minecraft.Windows.exe");
        Info("Minecraft Base: {}",rangeStart);
        Init();
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}