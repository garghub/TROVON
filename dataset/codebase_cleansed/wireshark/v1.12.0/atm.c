void
atm_guess_traffic_type(struct wtap_pkthdr *phdr, const guint8 *pd)
{
phdr->pseudo_header.atm.aal = AAL_5;
phdr->pseudo_header.atm.type = TRAF_UNKNOWN;
phdr->pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
if (phdr->pseudo_header.atm.vpi == 0) {
switch (phdr->pseudo_header.atm.vci) {
case 5:
phdr->pseudo_header.atm.aal = AAL_SIGNALLING;
return;
case 16:
phdr->pseudo_header.atm.type = TRAF_ILMI;
return;
}
}
if (phdr->caplen >= 3) {
if (pd[0] == 0xaa && pd[1] == 0xaa && pd[2] == 0x03) {
phdr->pseudo_header.atm.type = TRAF_LLCMX;
} else if ((phdr->pseudo_header.atm.aal5t_len && phdr->pseudo_header.atm.aal5t_len < 16) ||
phdr->caplen < 16) {
phdr->pseudo_header.atm.aal = AAL_SIGNALLING;
} else if (pd[0] == 0x83 || pd[0] == 0x81) {
phdr->pseudo_header.atm.aal = AAL_SIGNALLING;
} else {
phdr->pseudo_header.atm.type = TRAF_LANE;
atm_guess_lane_type(phdr, pd);
}
} else {
phdr->pseudo_header.atm.aal = AAL_SIGNALLING;
}
}
void
atm_guess_lane_type(struct wtap_pkthdr *phdr, const guint8 *pd)
{
if (phdr->caplen >= 2) {
if (pd[0] == 0xff && pd[1] == 0x00) {
phdr->pseudo_header.atm.subtype = TRAF_ST_LANE_LE_CTRL;
} else {
phdr->pseudo_header.atm.subtype = TRAF_ST_LANE_802_3;
}
}
}
