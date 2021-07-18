#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketMC : public AOPacket
{
    PacketMC(QStringList p_contents);

    /**
     * @brief Implements [Switch area](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#switch-area) and
     * [Music](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#music)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
