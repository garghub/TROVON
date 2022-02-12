static int
sctp_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const struct _sctp_info *sctphdr=(struct _sctp_info *)vip;
add_conversation_table_data((conversations_table *)pct,
&sctphdr->ip_src,
&sctphdr->ip_dst,
sctphdr->sport,
sctphdr->dport,
1,
pinfo->fd->pkt_len,
&pinfo->fd->rel_ts,
SAT_NONE,
PT_SCTP);
return 1;
}
static void
sctp_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,sctp,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_conversation_table(FALSE, "SCTP", "sctp", filter, sctp_conversation_packet);
}
void
sctp_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
sctp_conversation_init("conv,sctp",NULL);
}
void
register_tap_listener_sctp_conversation(void)
{
register_stat_cmd_arg("conv,sctp", sctp_conversation_init,NULL);
register_conversation_table(FALSE, "SCTP", "sctp", NULL , sctp_conversation_packet);
}
