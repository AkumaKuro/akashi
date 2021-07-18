#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketRC : public AOPacket
{
    PacketRC(QStringList p_contents);

    /**
     * @brief Implements [Character list](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#character-list)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
