static int
tr_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const tr_hdr *trhdr=vip;
add_conversation_table_data((conversations_table *)pct, &trhdr->src, &trhdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_TOKENRING, PT_NONE);
return 1;
}
static void
tr_conversation_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"conv,tr,",8)){
filter=optarg+8;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "Token Ring", "tr", filter, tr_conversation_packet);
}
void
tr_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
tr_conversation_init("conv,tr",NULL);
}
void
register_tap_listener_tr_conversation(void)
{
register_stat_cmd_arg("conv,tr", tr_conversation_init, NULL);
register_conversation_table(TRUE, "Token Ring", "tr", NULL , tr_conversation_packet);
}
