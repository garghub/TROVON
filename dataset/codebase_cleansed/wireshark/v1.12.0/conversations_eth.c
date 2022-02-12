static int
eth_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const eth_hdr *ehdr=(const eth_hdr *)vip;
add_conversation_table_data((conversations_table *)pct, &ehdr->src, &ehdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_ETHER, PT_NONE);
return 1;
}
static void
eth_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,eth,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "Ethernet", "eth", filter, eth_conversation_packet);
}
void
eth_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
eth_conversation_init("conv,eth",NULL);
}
void
register_tap_listener_eth_conversation(void)
{
register_stat_cmd_arg("conv,eth", eth_conversation_init,NULL);
register_conversation_table(TRUE, "Ethernet", "eth", NULL , eth_conversation_packet);
}
