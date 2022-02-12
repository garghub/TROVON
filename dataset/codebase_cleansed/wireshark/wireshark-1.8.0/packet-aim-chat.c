static int dissect_aim_chat_userinfo_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree)
{
int offset = 0;
while(tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_userinfo(tvb, pinfo, offset, chat_tree);
}
return offset;
}
static int dissect_aim_chat_outgoing_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree _U_)
{
guchar *buddyname;
guchar *msg;
int buddyname_length;
buddyname=(guchar *)ep_alloc(MAX_BUDDYNAME_LENGTH+1);
msg=(guchar *)ep_alloc(1000);
buddyname_length = aim_get_buddyname( buddyname, tvb, 30, 31 );
aim_get_message( msg, tvb, 40 + buddyname_length, tvb_length(tvb)
- 40 - buddyname_length );
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s", msg);
return tvb_length(tvb);
}
static int dissect_aim_chat_incoming_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *chat_tree)
{
guchar *buddyname;
guchar *msg;
int buddyname_length;
buddyname=(guchar *)ep_alloc(MAX_BUDDYNAME_LENGTH+1);
msg=(guchar *)ep_alloc(1000);
buddyname_length = aim_get_buddyname( buddyname, tvb, 30, 31 );
aim_get_message( msg, tvb, 36 + buddyname_length, tvb_length(tvb)
- 36 - buddyname_length );
col_append_fstr(pinfo->cinfo, COL_INFO, "from: %s", buddyname);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s", msg);
if(chat_tree) {
proto_tree_add_text(chat_tree, tvb, 31, buddyname_length,
"Screen Name: %s",
format_text(buddyname, buddyname_length));
}
return tvb_length(tvb);
}
void
proto_register_aim_chat(void)
{
#if 0
static hf_register_info hf[] = {
};
#endif
static gint *ett[] = {
&ett_aim_chat,
};
proto_aim_chat = proto_register_protocol("AIM Chat Service", "AIM Chat", "aim_chat");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_chat(void)
{
aim_init_family(proto_aim_chat, ett_aim_chat, FAMILY_CHAT, aim_fnac_family_chat);
}
