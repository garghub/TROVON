static int
ipx_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const ipxhdr_t *ipxh=(const ipxhdr_t *)vip;
add_conversation_table_data((conversations_table *)pct, &ipxh->ipx_src, &ipxh->ipx_dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
ipx_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,ipx,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "IPX", "ipx", filter, ipx_conversation_packet);
}
void
ipx_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
ipx_conversation_init("conv,ipx",NULL);
}
void
register_tap_listener_ipx_conversation(void)
{
register_stat_cmd_arg("conv,ipx", ipx_conversation_init,NULL);
register_conversation_table(TRUE, "IPX", "ipx", NULL , ipx_conversation_packet);
}
