static int
wlan_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const wlan_hdr *whdr=(const wlan_hdr *)vip;
add_hostlist_table_data(hosts, &whdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_WLAN, PT_NONE);
add_hostlist_table_data(hosts, &whdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_WLAN, PT_NONE);
return 1;
}
static void
gtk_wlan_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,wlan,",11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "WLAN", "wlan", filter, wlan_hostlist_packet);
}
void
gtk_wlan_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_wlan_hostlist_init("hosts,wlan",NULL);
}
void
register_tap_listener_wlan_hostlist(void)
{
register_stat_cmd_arg("hosts,wlan", gtk_wlan_hostlist_init,NULL);
register_hostlist_table(TRUE, "WLAN", "wlan", NULL , wlan_hostlist_packet);
}
