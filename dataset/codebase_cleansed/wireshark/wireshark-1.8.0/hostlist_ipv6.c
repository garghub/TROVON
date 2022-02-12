static int
ipv6_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts = (hostlist_table *)pit;
const struct ip6_hdr *ip6h = vip;
address src;
address dst;
src.type = dst.type = AT_IPv6;
src.len = dst.len = sizeof(struct e_in6_addr);
src.data = &ip6h->ip6_src;
dst.data = &ip6h->ip6_dst;
add_hostlist_table_data(hosts, &src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
add_hostlist_table_data(hosts, &dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
return 1;
}
static void
gtk_ipv6_hostlist_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"hosts,ipv6,",10)){
filter = optarg + 10;
} else {
filter = NULL;
}
init_hostlist_table(TRUE, "IPv6", "ipv6", filter, ipv6_hostlist_packet);
}
void
gtk_ipv6_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_ipv6_hostlist_init("hosts,ipv6", NULL);
}
void
register_tap_listener_ipv6_hostlist(void)
{
register_stat_cmd_arg("hosts,ipv6", gtk_ipv6_hostlist_init, NULL);
register_hostlist_table(TRUE, "IPv6", "ipv6", NULL , ipv6_hostlist_packet);
}
