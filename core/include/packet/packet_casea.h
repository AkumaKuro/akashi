#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketCASEA : public AOPacket
{
    PacketCASEA(QStringList p_contents);

    /**
     * @brief Implements [Case alert](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#case-alert).
     */
    virtual void handlePacket(AreaData* area, AOClient& client);

    QString case_title;
};
