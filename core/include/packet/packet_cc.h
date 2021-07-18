#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketCC : public AOPacket
{
    PacketCC(QStringList p_contents);

    /**
     * @brief Implements [Choose character](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#choose-character).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
