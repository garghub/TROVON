static int
fc_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const fc_hdr *fchdr=vip;
add_conversation_table_data((conversations_table *)pct, &fchdr->s_id, &fchdr->d_id, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
fc_conversation_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"conv,fc,",8)){
filter=optarg+8;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "Fibre Channel", "fc", filter, fc_conversation_packet);
}
void
fc_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
fc_conversation_init("conv,fc",NULL);
}
void
register_tap_listener_fc_conversation(void)
{
register_stat_cmd_arg("conv,fc", fc_conversation_init, NULL);
register_conversation_table(TRUE, "Fibre Channel", "fc", NULL , fc_conversation_packet);
}
