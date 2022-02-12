static int
rsvp_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts=(hostlist_table *)pit;
const rsvp_conversation_info *rsvph = (const rsvp_conversation_info *)vip;
add_hostlist_table_data(hosts, &rsvph->source, 0, TRUE, 1,
pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
add_hostlist_table_data(hosts, &rsvph->destination, 0, FALSE, 1,
pinfo->fd->pkt_len, SAT_NONE, PT_NONE);
return 1;
}
static void
gtk_rsvp_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,rsvp,",11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "RSVP", "rsvp", filter,
rsvp_hostlist_packet);
}
void
gtk_rsvp_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_rsvp_hostlist_init("hosts,rsvp",NULL);
}
void
register_tap_listener_rsvp_hostlist(void)
{
register_stat_cmd_arg("hosts,rsvp", gtk_rsvp_hostlist_init,NULL);
register_hostlist_table(TRUE, "RSVP", "rsvp", NULL ,
rsvp_hostlist_packet);
}
