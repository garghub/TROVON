static int
fddi_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const fddi_hdr *ehdr=(fddi_hdr *)vip;
add_hostlist_table_data(hosts, &ehdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_FDDI, PT_NONE);
add_hostlist_table_data(hosts, &ehdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_FDDI, PT_NONE);
return 1;
}
static void
gtk_fddi_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,fddi,",11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "FDDI", "fddi", filter, fddi_hostlist_packet);
}
void
gtk_fddi_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_fddi_hostlist_init("hosts,fddi",NULL);
}
void
register_tap_listener_fddi_hostlist(void)
{
register_stat_cmd_arg("hosts,fddi", gtk_fddi_hostlist_init,NULL);
register_hostlist_table(TRUE, "FDDI", "fddi", NULL , fddi_hostlist_packet);
}
