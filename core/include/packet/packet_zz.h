#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketZZ : public AOPacket
{
    PacketZZ(QStringList p_contents);

    /**
     * @brief Implements [Call mod](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#call-mod)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
