static int
tcpip_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const struct tcpheader *tcphdr=(const struct tcpheader *)vip;
add_conversation_table_data_with_conv_id((conversations_table *)pct, &tcphdr->ip_src, &tcphdr->ip_dst, tcphdr->th_sport, tcphdr->th_dport, (conv_id_t) tcphdr->th_stream, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_NONE, PT_TCP);
return 1;
}
static void
tcpip_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,tcp,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_conversation_table(FALSE, "TCP", "tcp", filter, tcpip_conversation_packet);
}
void
tcpip_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
tcpip_conversation_init("conv,tcp",NULL);
}
void
register_tap_listener_tcpip_conversation(void)
{
register_stat_cmd_arg("conv,tcp", tcpip_conversation_init,NULL);
register_conversation_table(FALSE, "TCP", "tcp", NULL , tcpip_conversation_packet);
}
