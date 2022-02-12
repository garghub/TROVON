static int
dissect_ipmi_session(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sess_tree = NULL, *s_tree;
proto_item *ti = NULL;
tvbuff_t *next_tvb;
guint32 session_id;
guint8 authtype, payloadtype = 0;
guint32 msg_start, msg_len, offset = 0;
gboolean payloadtype_auth = 0, payloadtype_enc = 0;
authtype = tvb_get_guint8(tvb, 0);
if (authtype == IPMI_AUTH_RMCPP) {
payloadtype = tvb_get_guint8(tvb, 1);
payloadtype_auth = (payloadtype >> 6) & 1;
payloadtype_enc = (payloadtype >> 7);
payloadtype &= 0x3f;
if (payloadtype == IPMI_OEM_EXPLICIT) {
session_id = tvb_get_letohl(tvb, 8);
msg_start = 18;
msg_len = tvb_get_letohs(tvb, 16);
} else {
session_id = tvb_get_letohl(tvb, 2);
msg_start = 12;
msg_len = tvb_get_letohs(tvb, 10);
}
} else {
session_id = tvb_get_letohl(tvb, 5);
if (authtype == IPMI_AUTH_NONE) {
msg_start = 10;
msg_len = tvb_get_guint8(tvb, 9);
} else {
msg_start = 26;
msg_len = tvb_get_guint8(tvb, 25);
}
}
if (check_col(pinfo->cinfo, COL_PROTOCOL)) {
if (authtype == IPMI_AUTH_RMCPP) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RMCP+");
} else {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPMI");
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Session ID 0x%x", session_id);
if (authtype == IPMI_AUTH_RMCPP) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", payload type: %s",
val_to_str(payloadtype, ipmi_payload_vals, "Unknown"));
}
}
if (tree) {
offset = 0;
ti = proto_tree_add_protocol_format(tree, proto_ipmi_session,
tvb, 0, tvb_length(tvb),
"IPMI v%s Session Wrapper, session ID 0x%x",
authtype == IPMI_AUTH_RMCPP ? "2.0+" : "1.5",
session_id);
sess_tree = proto_item_add_subtree(ti, ett_ipmi_session);
proto_tree_add_item(sess_tree, hf_ipmi_session_authtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (authtype == IPMI_AUTH_RMCPP) {
ti = proto_tree_add_text(sess_tree, tvb, offset, 1,
"Payload type: %s (0x%02x), %sencrypted, %sauthenticated",
val_to_str(payloadtype, ipmi_payload_vals, "Unknown"),
payloadtype,
payloadtype_enc ? "" : "not ",
payloadtype_auth ? "" : "not ");
s_tree = proto_item_add_subtree(ti, ett_ipmi_session_payloadtype);
proto_tree_add_item(s_tree, hf_ipmi_session_payloadtype_enc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(s_tree, hf_ipmi_session_payloadtype_auth, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(s_tree, hf_ipmi_session_payloadtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (payloadtype == IPMI_OEM_EXPLICIT) {
proto_tree_add_item(sess_tree, hf_ipmi_session_oem_iana, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(sess_tree, hf_ipmi_session_oem_payload_id, tvb, offset, 2, ENC_NA);
offset += 2;
}
proto_tree_add_item(sess_tree, hf_ipmi_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sess_tree, hf_ipmi_session_sequence, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sess_tree, hf_ipmi_session_msg_len_2b, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
proto_tree_add_item(sess_tree, hf_ipmi_session_sequence, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(sess_tree, hf_ipmi_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (authtype != IPMI_AUTH_NONE) {
proto_tree_add_item(sess_tree, hf_ipmi_session_authcode,
tvb, offset, 16, ENC_NA);
offset += 16;
}
proto_tree_add_item(sess_tree, hf_ipmi_session_msg_len_1b, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
next_tvb = tvb_new_subset(tvb, msg_start, msg_len, -1);
if (payloadtype_enc) {
call_dissector(data_handle, next_tvb, pinfo, tree);
} else if (authtype != IPMI_AUTH_RMCPP || payloadtype == IPMI_IPMI_MESSAGE) {
call_dissector(ipmi_handle, next_tvb, pinfo, tree);
} else {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
if (tree) {
offset += msg_len;
if (offset < tvb_length(tvb)) {
proto_tree_add_item(sess_tree, hf_ipmi_session_trailer,
tvb, offset, tvb_length(tvb) - offset, ENC_NA);
}
}
return tvb_length(tvb);
}
void
proto_register_ipmi_session(void)
{
static hf_register_info hf[] = {
{ &hf_ipmi_session_authtype, {
"Authentication Type", "ipmi.session.authtype",
FT_UINT8, BASE_HEX, VALS(ipmi_authtype_vals), 0, NULL, HFILL }},
{ &hf_ipmi_session_payloadtype,{
"Payload Type", "ipmi.session.payloadtype",
FT_UINT8, BASE_HEX, VALS(ipmi_payload_vals), 0x3f, NULL, HFILL }},
{ &hf_ipmi_session_payloadtype_auth,{
"Authenticated","ipmi.session.payloadtype.auth",
FT_BOOLEAN,8, TFS(&ipmi_payload_aut_val), 0x40, NULL, HFILL }},
{ &hf_ipmi_session_payloadtype_enc,{
"Encryption","ipmi.session.payloadtype.enc",
FT_BOOLEAN,8, TFS(&ipmi_payload_enc_val), 0x80, NULL, HFILL }},
{ &hf_ipmi_session_oem_iana, {
"OEM IANA", "ipmi.session.oem.iana",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_oem_payload_id, {
"OEM Payload ID", "ipmi.session.oem.payloadid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_sequence, {
"Session Sequence Number", "ipmi.session.sequence",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_id, {
"Session ID", "ipmi.session.id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_authcode, {
"Authentication Code", "ipmi.session.authcode",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_msg_len_1b, {
"Message Length", "ipmi.msg.len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_msg_len_2b, {
"Message Length", "ipmi.msg.len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_session_trailer, {
"IPMI Session Wrapper (trailer)", "ipmi.sess.trailer",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = { &ett_ipmi_session, &ett_ipmi_session_payloadtype };
proto_ipmi_session = proto_register_protocol(
"Intelligent Platform Management Interface (Session Wrapper)", "IPMI Session",
"ipmi-session");
proto_register_field_array(proto_ipmi_session, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipmi_session(void)
{
dissector_handle_t ipmi_session_handle;
ipmi_session_handle = new_create_dissector_handle(dissect_ipmi_session, proto_ipmi_session);
dissector_add_uint("rmcp.class", RMCP_CLASS_IPMI, ipmi_session_handle);
data_handle = find_dissector("data");
ipmi_handle = find_dissector("ipmi");
}
