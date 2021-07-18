#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketCH : public AOPacket
{
    PacketCH(QStringList p_contents);

    /**
     * @brief Implements [Keep alive](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#keep-alive).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
