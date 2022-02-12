static int
fc_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const fc_hdr *fchdr=(fc_hdr *)vip;
add_hostlist_table_data(hosts, &fchdr->s_id, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
add_hostlist_table_data(hosts, &fchdr->d_id, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
return 1;
}
static void
gtk_fc_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,fc,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "Fibre Channel", "fc", filter, fc_hostlist_packet);
}
void
gtk_fc_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_fc_hostlist_init("hosts,fc",NULL);
}
void
register_tap_listener_fc_hostlist(void)
{
register_stat_cmd_arg("hosts,fc", gtk_fc_hostlist_init,NULL);
register_hostlist_table(TRUE, "Fibre Channel", "fc", NULL , fc_hostlist_packet);
}
