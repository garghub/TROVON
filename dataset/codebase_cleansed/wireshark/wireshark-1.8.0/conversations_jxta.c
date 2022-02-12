static int
jxta_conversation_packet(void *pct, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *vip)
{
const jxta_tap_header *jxtahdr = (const jxta_tap_header *) vip;
add_conversation_table_data((conversations_table *)pct,
&jxtahdr->src_address,
&jxtahdr->dest_address,
0,
0,
1,
jxtahdr->size,
NULL,
SAT_JXTA,
PT_NONE);
return 1;
}
static void
jxta_conversation_init(const char *optarg, void* userdata _U_)
{
const char *filter=NULL;
if(!strncmp(optarg,"conv,jxta,",10)){
filter=optarg+10;
} else {
filter=NULL;
}
init_conversation_table(TRUE, "JXTA", "jxta", filter, jxta_conversation_packet);
}
void
jxta_conversation_cb(GtkAction *action _U_, gpointer user_data _U_)
{
jxta_conversation_init("conv,jxta",NULL);
}
void
register_tap_listener_jxta_conversation(void)
{
register_stat_cmd_arg("conv,jxta", jxta_conversation_init,NULL);
register_conversation_table(TRUE, "JXTA", "jxta", NULL , jxta_conversation_packet);
}
