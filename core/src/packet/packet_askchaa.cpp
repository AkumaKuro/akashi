#include "include/packet/packet_askchaa.h"

PacketASKCHAA::PacketASKCHAA(QStringList p_contents)
    : AOPacket(p_contents)
{
    header = "ASKCHAA";
    acl_mask = ACLFlags.value("NONE");
    min_args = 0;
}

void PacketASKCHAA::handlePacket(AreaData *area, AOClient &client)
{
    sendPacket("SI", {QString::number(server->characters.length()), "0", QString::number(server->area_names.length() + server->music_list.length())});
}
