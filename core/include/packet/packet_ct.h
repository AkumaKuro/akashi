#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketCT : public AOPacket
{
    PacketCT(QStringList p_contents);

    /**
     * @brief Implements [Out-of-character message](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#out-of-character-message).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
