static int
ip_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const ws_ip *iph=vip;
add_hostlist_table_data(hosts, &iph->ip_src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
add_hostlist_table_data(hosts, &iph->ip_dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
return 1;
}
static void
gtk_ip_hostlist_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"hosts,ip,",9)){
filter=optarg+9;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "IPv4", "ip", filter, ip_hostlist_packet);
}
void
gtk_ip_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_ip_hostlist_init("hosts,ip",NULL);
}
void
register_tap_listener_ip_hostlist(void)
{
register_stat_cmd_arg("hosts,ip", gtk_ip_hostlist_init,NULL);
register_hostlist_table(TRUE, "IPv4", "ip", NULL , ip_hostlist_packet);
}
