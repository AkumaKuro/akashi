#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketWSIP : public AOPacket
{
    PacketWSIP(QStringList p_contents);

    /**
     * @brief Implements [Websocket IP]()
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
