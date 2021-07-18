#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketASKCHAA : public AOPacket
{
    PacketASKCHAA(QStringList p_contents);

    /**
     * @brief Implements [Resource counts](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#resource-counts).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
