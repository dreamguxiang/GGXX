//
// Created by Admin on 2022/10/26.
//

#ifndef GGXX_PACKET_H
#define GGXX_PACKET_H

#endif //GGXX_PACKET_H
#include "Global.h"

enum class PacketReliability {
    Relible,
    RelibleOrdered
};

class Packet {

#define AFTER_EXTRA
// Add Member There
public:
    unsigned unk2 = 2;                                                     // 8
    PacketReliability reliableOrdered = PacketReliability::RelibleOrdered; // 12
    unsigned char clientSubId = 0;                                         // 16
    uint64_t unk24 = 0;                                                    // 24
    uint64_t unk40 = 0;                                                    // 32
    uint32_t incompressible = 0;                                           // 40

    inline Packet(unsigned compress)
            : incompressible(!compress)
    { }
#define DISABLE_CONSTRUCTOR_PREVENTION_PACKET
    inline Packet() {}
    class Packet& operator=(class Packet const&) = delete;
    Packet(class Packet const&) = delete;

    inline StreamReadResult read(class ReadOnlyBinaryStream& binaryStream)
    {
        return _read(binaryStream);
    }

public:
    virtual ~Packet();
    virtual enum class MinecraftPacketIds getId() const = 0;
    virtual std::string getName() const = 0;
    virtual void write(class BinaryStream &) const = 0;
    virtual struct ExtendedStreamReadResult readExtended(class ReadOnlyBinaryStream &);
    virtual bool disallowBatching() const;
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &) = 0;

};