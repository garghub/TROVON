static int
tcpip_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const struct tcpheader *tcphdr=(const struct tcpheader *)vip;
add_hostlist_table_data(hosts, &tcphdr->ip_src, tcphdr->th_sport, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_TCP);
add_hostlist_table_data(hosts, &tcphdr->ip_dst, tcphdr->th_dport, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_TCP);
return 1;
}
static void
gtk_tcpip_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"endpoints,tcp,",14)){
filter=opt_arg+14;
} else {
filter=NULL;
}
init_hostlist_table(FALSE, "TCP", "tcp", filter, tcpip_hostlist_packet);
}
void
gtk_tcpip_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_tcpip_hostlist_init("endpoints,tcp",NULL);
}
void
register_tap_listener_tcpip_hostlist(void)
{
register_stat_cmd_arg("endpoints,tcp", gtk_tcpip_hostlist_init,NULL);
register_hostlist_table(FALSE, "TCP", "tcp", NULL , tcpip_hostlist_packet);
}
