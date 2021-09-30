
#include <cstddef>
#include "Client.h"

bool Client::CheckCorrupt(const Packet &packet)
{

    byte checksum = 0;
    checksum = packet.checksum;

   if(GenerateChecksum(packet).checksum == checksum && GenerateChecksum(packet).sequenceNmb == packet.sequenceNmb)
   { 
       return true;
   }
   else
   {
       return false;
   }
	
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

