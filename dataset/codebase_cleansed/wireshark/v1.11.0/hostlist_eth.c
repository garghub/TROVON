static int
eth_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const eth_hdr *ehdr=(eth_hdr *)vip;
add_hostlist_table_data(hosts, &ehdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_ETHER, PT_NONE);
add_hostlist_table_data(hosts, &ehdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_ETHER, PT_NONE);
return 1;
}
static void
gtk_eth_hostlist_init(const char *opt_arg,
void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,eth,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "Ethernet", "eth", filter, eth_hostlist_packet);
}
void
gtk_eth_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_eth_hostlist_init("hosts,eth",NULL);
}
void
register_tap_listener_eth_hostlist(void)
{
register_stat_cmd_arg("hosts,eth", gtk_eth_hostlist_init,NULL);
register_hostlist_table(TRUE, "Ethernet", "eth", NULL , eth_hostlist_packet);
}
