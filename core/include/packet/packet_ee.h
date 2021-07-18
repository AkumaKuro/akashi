#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketEE : public AOPacket
{
    PacketEE(QStringList p_contents);

    /**
     * @brief Implements [Evidence edit](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#edit).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
