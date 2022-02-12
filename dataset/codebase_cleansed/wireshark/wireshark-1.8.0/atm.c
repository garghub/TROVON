void
atm_guess_traffic_type(const guint8 *pd, guint32 len,
union wtap_pseudo_header *pseudo_header)
{
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
if (pseudo_header->atm.vpi == 0) {
switch (pseudo_header->atm.vci) {
case 5:
pseudo_header->atm.aal = AAL_SIGNALLING;
return;
case 16:
pseudo_header->atm.type = TRAF_ILMI;
return;
}
}
if (len >= 3) {
if (pd[0] == 0xaa && pd[1] == 0xaa && pd[2] == 0x03) {
pseudo_header->atm.type = TRAF_LLCMX;
} else if ((pseudo_header->atm.aal5t_len &&
pseudo_header->atm.aal5t_len < 16) || len<16) {
pseudo_header->atm.aal = AAL_SIGNALLING;
} else if (pd[0] == 0x83 || pd[0] == 0x81) {
pseudo_header->atm.aal = AAL_SIGNALLING;
} else {
pseudo_header->atm.type = TRAF_LANE;
atm_guess_lane_type(pd, len, pseudo_header);
}
} else {
pseudo_header->atm.aal = AAL_SIGNALLING;
}
}
void
atm_guess_lane_type(const guint8 *pd, guint32 len,
union wtap_pseudo_header *pseudo_header)
{
if (len >= 2) {
if (pd[0] == 0xff && pd[1] == 0x00) {
pseudo_header->atm.subtype = TRAF_ST_LANE_LE_CTRL;
} else {
pseudo_header->atm.subtype = TRAF_ST_LANE_802_3;
}
}
}
