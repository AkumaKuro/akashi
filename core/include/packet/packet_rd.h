#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketRD : public AOPacket
{
    PacketRD(QStringList p_contents);

    /**
     * @brief Implements [Final confirmation](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#final-confirmation)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
