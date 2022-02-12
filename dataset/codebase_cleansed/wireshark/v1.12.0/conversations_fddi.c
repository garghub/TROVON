static int
fddi_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
const fddi_hdr *ehdr=(const fddi_hdr *)vip;
add_conversation_table_data((conversations_table *)pct, &ehdr->src, &ehdr->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, SAT_FDDI, PT_NONE);
return 1;
}
static void
fddi_conversation_init(const char *opt_arg, void* userdata _U_ )
{
const char *filter=NULL;
if(!strncmp(opt_arg,"conv,fddi,",10)){
filter=opt_arg+10;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "FDDI", "fddi", filter, fddi_conversation_packet);
}
void
fddi_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
fddi_conversation_init("conv,fddi",NULL);
}
void
register_tap_listener_fddi_conversation(void)
{
register_stat_cmd_arg("conv,fddi", fddi_conversation_init,NULL);
register_conversation_table(TRUE, "FDDI", "fddi", NULL , fddi_conversation_packet);
}
