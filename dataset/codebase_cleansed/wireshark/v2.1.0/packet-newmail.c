static int
dissect_newmail(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *newmail_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NEWMAIL");
col_set_str(pinfo->cinfo, COL_INFO, "Microsoft Exchange new mail notification");
if (tree) {
ti = proto_tree_add_item(tree, proto_newmail, tvb, 0, -1, ENC_NA);
newmail_tree = proto_item_add_subtree(ti, ett_newmail);
proto_tree_add_item(newmail_tree, hf_newmail_payload, tvb, 0, 8, ENC_NA);
}
return tvb_captured_length(tvb);
}
void
proto_register_newmail(void)
{
static hf_register_info hf[] = {
{ &hf_newmail_payload,
{ "Notification payload", "newmail.notification_payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Payload requested by client in the MAPI register push notification packet", HFILL }
},
};
static gint *ett[] = {
&ett_newmail,
};
module_t *newmail_module;
proto_newmail = proto_register_protocol("Microsoft Exchange New Mail Notification",
"NEWMAIL", "newmail");
proto_register_field_array(proto_newmail, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("newmail", dissect_newmail, proto_newmail);
newmail_module = prefs_register_protocol(proto_newmail,
proto_reg_handoff_newmail);
prefs_register_uint_preference(newmail_module,
"default_port",
"Default UDP port (optional)",
"Always dissect this port's traffic as newmail notifications."
" Additional ports will be dynamically registered as they"
" are seen in MAPI register push notification packets.",
10, &preference_default_port);
}
void
proto_reg_handoff_newmail(void)
{
static gboolean inited = FALSE;
static dissector_handle_t newmail_handle;
static guint preference_default_port_last;
if(!inited) {
newmail_handle = find_dissector("newmail");
dissector_add_for_decode_as("udp.port", newmail_handle);
inited = TRUE;
} else {
if (preference_default_port_last != 0) {
dissector_delete_uint("udp.port", preference_default_port_last, newmail_handle);
}
}
if(preference_default_port != 0) {
dissector_add_uint("udp.port", preference_default_port, newmail_handle);
}
preference_default_port_last = preference_default_port;
}
