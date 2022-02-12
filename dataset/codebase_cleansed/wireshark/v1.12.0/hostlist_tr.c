static int
tr_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const tr_hdr *trhdr=(const tr_hdr *)vip;
add_hostlist_table_data(hosts, &trhdr->src, 0, TRUE, 1, pinfo->fd->pkt_len, SAT_TOKENRING, PT_NONE);
add_hostlist_table_data(hosts, &trhdr->dst, 0, FALSE, 1, pinfo->fd->pkt_len, SAT_TOKENRING, PT_NONE);
return 1;
}
static void
gtk_tr_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,tr,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "Token Ring", "tr", filter, tr_hostlist_packet);
}
void
gtk_tr_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_tr_hostlist_init("hosts,tr",NULL);
}
void
register_tap_listener_tr_hostlist(void)
{
register_stat_cmd_arg("hosts,tr", gtk_tr_hostlist_init,NULL);
register_hostlist_table(TRUE, "Token Ring", "tr", NULL , tr_hostlist_packet);
}
