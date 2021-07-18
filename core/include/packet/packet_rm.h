#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketRM : public AOPacket
{
    PacketRM(QStringList p_contents);

    /**
     * @brief Implements [Music List](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#music-list)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
