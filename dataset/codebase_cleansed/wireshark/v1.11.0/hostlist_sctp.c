static int
sctp_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const struct _sctp_info *sctphdr=(struct _sctp_info *)vip;
add_hostlist_table_data(hosts, &sctphdr->ip_src, sctphdr->sport, TRUE, 1,
pinfo->fd->pkt_len, SAT_NONE, PT_SCTP);
add_hostlist_table_data(hosts, &sctphdr->ip_dst, sctphdr->dport, FALSE, 1,
pinfo->fd->pkt_len, SAT_NONE, PT_SCTP);
return 1;
}
static void
gtk_sctp_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,sctp,",11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
init_hostlist_table(FALSE, "SCTP", "sctp", filter, sctp_hostlist_packet);
}
void
gtk_sctp_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_sctp_hostlist_init("hosts,sctp",NULL);
}
void
register_tap_listener_sctp_hostlist(void)
{
register_stat_cmd_arg("hosts,sctp", gtk_sctp_hostlist_init,NULL);
register_hostlist_table(FALSE, "SCTP", "sctp", NULL , sctp_hostlist_packet);
}
