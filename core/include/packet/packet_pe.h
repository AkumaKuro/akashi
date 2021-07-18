#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketPE : public AOPacket
{
    PacketPE(QStringList p_contents);

    /**
     * @brief Implements [Evidence add](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#add)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
