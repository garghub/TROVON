static int
wlan_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const wlan_hdr *whdr=(const wlan_hdr *)vip;
add_conversation_table_data((conversations_table *)pct, &whdr->src, &whdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_WLAN, PT_NONE);
return 1;
}
static void
wlan_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,wlan,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "WLAN", "wlan", filter, wlan_conversation_packet);
}
void
wlan_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
wlan_conversation_init("conv,wlan",NULL);
}
void
register_tap_listener_wlan_conversation(void)
{
register_stat_cmd_arg("conv,wlan", wlan_conversation_init,NULL);
register_conversation_table(TRUE, "WLAN", "wlan", NULL , wlan_conversation_packet);
}
