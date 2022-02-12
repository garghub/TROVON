static int
jxta_hostlist_packet(void *pit, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *vip)
{
hostlist_table *hosts = (hostlist_table *) pit;
const jxta_tap_header *jxtahdr = (const jxta_tap_header *)vip;
add_hostlist_table_data(hosts, &jxtahdr->src_address, 0, TRUE, 1, jxtahdr->size, SAT_JXTA, PT_NONE);
add_hostlist_table_data(hosts, &jxtahdr->dest_address, 0, FALSE, 1, jxtahdr->size, SAT_JXTA, PT_NONE);
return 1;
}
static void
gtk_jxta_hostlist_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"hosts,jxta,",11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
init_hostlist_table(TRUE, "JXTA", "jxta", filter, jxta_hostlist_packet);
}
void
gtk_jxta_hostlist_cb(GtkAction *action _U_, gpointer user_data _U_)
{
gtk_jxta_hostlist_init("hosts,jxta",NULL);
}
void
register_tap_listener_jxta_hostlist(void)
{
register_stat_cmd_arg("hosts,jxta", gtk_jxta_hostlist_init,NULL);
register_hostlist_table(TRUE, "JXTA", "jxta", NULL , jxta_hostlist_packet);
}
