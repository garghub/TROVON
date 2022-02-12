static int
ncp_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip _U_)
{
hostlist_table *hosts=(hostlist_table *)pit;
add_hostlist_table_data(hosts, &pinfo->src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_ETHER, PT_NCP);
add_hostlist_table_data(hosts, &pinfo->dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_ETHER, PT_NCP);
return 1;
}
static void
gtk_ncp_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,ncp,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "NCP", "ncp_hdr", filter, ncp_hostlist_packet);
}
void
gtk_ncp_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_ncp_hostlist_init("hosts,ncp",NULL);
}
void
register_tap_listener_ncp_hostlist(void)
{
register_stat_cmd_arg("hosts,ncp", gtk_ncp_hostlist_init,NULL);
register_hostlist_table(TRUE, "NCP", "ncp_hdr", NULL , ncp_hostlist_packet);
}
