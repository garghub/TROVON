static int
ncp_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const struct ncp_common_header *ncph=vip;
guint32 connection;
connection = (ncph->conn_high * 256)+ncph->conn_low;
if (connection < 65535) {
add_conversation_table_data((conversations_table *)pct, &pinfo->src, &pinfo->dst, connection, connection, 1, pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_NONE, PT_NCP);
}
return 1;
}
static void
ncp_conversation_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"conv,ncp,",9)){
filter=optarg+9;
} else {
filter=NULL;
}
init_conversation_table(FALSE, "NCP", "ncp_hdr", filter, ncp_conversation_packet);
}
void
ncp_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
ncp_conversation_init("conv,ncp",NULL);
}
void
register_tap_listener_ncp_conversation(void)
{
register_stat_cmd_arg("conv,ncp", ncp_conversation_init,NULL);
register_conversation_table(FALSE, "NCP", "ncp_hdr", NULL , ncp_conversation_packet);
}
