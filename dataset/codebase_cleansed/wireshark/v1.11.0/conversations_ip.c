static int
ip_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const ws_ip *iph=(ws_ip *)vip;
add_conversation_table_data((conversations_table *)pct, &iph->ip_src, &iph->ip_dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
ip_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,ip,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "IPv4", "ip", filter, ip_conversation_packet);
}
void
ip_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
ip_conversation_init("conv,ip",NULL);
}
void
register_tap_listener_ip_conversation(void)
{
register_stat_cmd_arg("conv,ip", ip_conversation_init,NULL);
register_conversation_table(TRUE, "IPv4", "ip", NULL , ip_conversation_packet);
}
