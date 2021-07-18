#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketPW : public AOPacket
{
    PacketPW(QStringList p_contents);

    /**
     * @brief Implements [?]()
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
