static int
usb_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip _U_)
{
add_conversation_table_data((conversations_table *)pct, &pinfo->src, &pinfo->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->fd->rel_ts, SAT_NONE, PT_NONE);
return 1;
}
static void
usb_conversation_init(const char *opt_arg, void* userdata _U_)
{
const char *filter=NULL;
if (!strncmp(opt_arg, "conv,usb,", 9)) {
filter = opt_arg + 9;
} else {
filter = NULL;
}
init_conversation_table(TRUE, "USB", "usb", filter, usb_conversation_packet);
}
void
usb_endpoints_cb(GtkAction *action _U_, gpointer user_data _U_)
{
usb_conversation_init("conv,usb", NULL);
}
void
register_tap_listener_usb_conversation(void)
{
register_stat_cmd_arg("conv,usb", usb_conversation_init, NULL);
register_conversation_table(TRUE, "USB", "usb", NULL , usb_conversation_packet);
}
