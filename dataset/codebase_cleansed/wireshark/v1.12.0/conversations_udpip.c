static int
udpip_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const e_udphdr *udphdr=(const e_udphdr *)vip;
add_conversation_table_data((conversations_table *)pct, &udphdr->ip_src, &udphdr->ip_dst, udphdr->uh_sport, udphdr->uh_dport, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_NONE, PT_UDP);
return 1;
}
static void
udpip_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,udp,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_conversation_table(FALSE, "UDP", "udp", filter, udpip_conversation_packet);
}
void
udpip_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
udpip_conversation_init("conv,udp",NULL);
}
void
register_tap_listener_udpip_conversation(void)
{
register_stat_cmd_arg("conv,udp", udpip_conversation_init, NULL);
register_conversation_table(FALSE, "UDP", "udp", NULL , udpip_conversation_packet);
}
