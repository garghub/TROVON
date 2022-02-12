static int
ipv6_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const struct ip6_hdr *ip6h = vip;
address src;
address dst;
src.type = dst.type = AT_IPv6;
src.len = dst.len = sizeof(struct e_in6_addr);
src.data = &ip6h->ip6_src;
dst.data = &ip6h->ip6_dst;
add_conversation_table_data((conversations_table *)pct, &src, &dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
ipv6_conversation_init(const char *optarg, void *userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg, "conv,ipv6,", 10)) {
filter = optarg + 10;
}
else {
filter = NULL;
}
init_conversation_table(TRUE, "IPv6", "ipv6", filter, ipv6_conversation_packet);
}
void
ipv6_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
ipv6_conversation_init("conv,ipv6", NULL);
}
void
register_tap_listener_ipv6_conversation(void)
{
register_stat_cmd_arg("conv,ipv6", ipv6_conversation_init, NULL);
register_conversation_table(TRUE, "IPv6", "ipv6", NULL , ipv6_conversation_packet);
}
