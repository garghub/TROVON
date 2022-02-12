static int
ipx_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const ipxhdr_t *ipxh=(const ipxhdr_t *)vip;
add_hostlist_table_data(hosts, &ipxh->ipx_src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
add_hostlist_table_data(hosts, &ipxh->ipx_dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
return 1;
}
static void
gtk_ipx_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,ipx,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "IPX", "ipx", filter, ipx_hostlist_packet);
}
void
gtk_ipx_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_ipx_hostlist_init("hosts,ipx",NULL);
}
void
register_tap_listener_ipx_hostlist(void)
{
register_stat_cmd_arg("hosts,ipx", gtk_ipx_hostlist_init,NULL);
register_hostlist_table(TRUE, "IPX", "ipx", NULL , ipx_hostlist_packet);
}
