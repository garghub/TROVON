static int
rsvp_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const rsvp_conversation_info *rsvph = (rsvp_conversation_info *)vip;
add_conversation_table_data((conversations_table *)pct,
&rsvph->source, &rsvph->destination, 0, 0, 1,
pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
rsvp_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,rsvp,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "RSVP", "rsvp", filter,
rsvp_conversation_packet);
}
void
rsvp_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
rsvp_conversation_init("conv,rsvp",NULL);
}
void
register_tap_listener_rsvp_conversation(void)
{
register_stat_cmd_arg("conv,rsvp", rsvp_conversation_init,NULL);
register_conversation_table(TRUE, "RSVP", "rsvp", NULL ,
rsvp_conversation_packet);
}
