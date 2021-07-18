#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketSETCASE : public AOPacket
{
    PacketSETCASE(QStringList p_contents);

    /**
     * @brief Implements [Case preferences update](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#case-preferences-update)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
