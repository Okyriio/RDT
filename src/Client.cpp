
#include <cstddef>
#include "Client.h"

bool Client::CheckCorrupt(const Packet &packet)
{

    byte checksum = packet.checksum;
   

   if(GenerateChecksum(packet).checksum == checksum && packet.sequenceNmb == GenerateChecksum(packet).sequenceNmb)
   { 
       return true;
   }

   
     return false;
 	
}

Packet Client::GenerateChecksum(const Packet &packet)
{
    Packet generatedPacket = packet;
    byte checksum = generatedPacket.sequenceNmb;
    

    for (auto packetData : generatedPacket.data)
    {
        checksum += packetData;
    }

    
    generatedPacket.checksum = checksum;
    return generatedPacket;
}

