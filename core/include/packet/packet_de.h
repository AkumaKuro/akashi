#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketDE : public AOPacket
{
    PacketDE(QStringList p_contents);

    /**
     * @brief Implements [Evidence remove](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#remove).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
