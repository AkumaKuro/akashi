#include "include/packet/aopacket.h"
#include "include/area_data.h"
#include "include/aoclient.h"

class PacketRT : public AOPacket
{
    PacketRT(QStringList p_contents);

    /**
     * @brief Implements [Witness Testimony/Cross Examination (WT/CE)](https://github.com/AttorneyOnline/docs/blob/master/docs/development/network.md#witness-testimonycross-examination-wtce)
     */
    virtual void handlePacket(AreaData* area, AOClient& client);
};
