#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketMS : public AOPacket
{
    PacketMS(QStringList p_contents);

    /**
     * @brief Implements [In-character message](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#in-character-message)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
