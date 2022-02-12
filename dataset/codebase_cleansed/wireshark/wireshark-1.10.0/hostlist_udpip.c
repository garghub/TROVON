static int
udpip_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const e_udphdr *udphdr=(e_udphdr *)vip;
add_hostlist_table_data(hosts, &udphdr->ip_src, udphdr->uh_sport, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_UDP);
add_hostlist_table_data(hosts, &udphdr->ip_dst, udphdr->uh_dport, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_UDP);
return 1;
}
static void
gtk_udpip_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"endpoints,udp,",14)){
filter=opt_arg+14;
} else {
filter=NULL;
}
init_hostlist_table(FALSE, "UDP", "udp", filter, udpip_hostlist_packet);
}
void
gtk_udpip_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_udpip_hostlist_init("endpoints,udp",NULL);
}
void
register_tap_listener_udpip_hostlist(void)
{
register_stat_cmd_arg("endpoints,udp", gtk_udpip_hostlist_init,NULL);
register_hostlist_table(FALSE, "UDP", "udp", NULL , udpip_hostlist_packet);
}
