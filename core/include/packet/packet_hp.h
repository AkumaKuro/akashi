#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketHP : public AOPacket
{
    PacketHP(QStringList p_contents);

    /**
     * @brief Implements [Penalty (health) bars](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#penalty-health-bars).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
