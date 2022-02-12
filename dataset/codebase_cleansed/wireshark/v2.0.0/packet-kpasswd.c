static void
dissect_kpasswd_ap_req_data(packet_info *pinfo _U_, tvbuff_t *tvb, proto_tree *parent_tree)
{
proto_item *it;
proto_tree *tree=NULL;
if(parent_tree){
it=proto_tree_add_item(parent_tree, hf_kpasswd_ap_req_data, tvb, 0, -1, ENC_NA);
tree=proto_item_add_subtree(it, ett_ap_req_data);
}
dissect_kerberos_main(tvb, pinfo, tree, FALSE, NULL);
}
static int
dissect_kpasswd_user_data_request(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree)
{
int offset=0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset=dissect_kerberos_ChangePasswdData (FALSE, tvb, offset, &asn1_ctx, tree, hf_kpasswd_ChangePasswdData);
return offset;
}
static int
dissect_kpasswd_user_data_reply(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree)
{
int offset=0;
guint16 result;
result = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_kpasswd_result, tvb, offset, 2, result);
offset+=2;
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(result, kpasswd_result_types, "Result: %u"));
if(tvb_reported_length_remaining(tvb, offset) > 0){
proto_tree_add_item(tree, hf_kpasswd_result_string, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_ASCII|ENC_NA);
offset = tvb_reported_length(tvb);
}
return offset;
}
static gint
dissect_kpasswd_krb_priv_message(packet_info *pinfo _U_, tvbuff_t *tvb, proto_tree *parent_tree, gboolean isrequest)
{
proto_item *it;
proto_tree *tree=NULL;
gint offset;
if(parent_tree){
it=proto_tree_add_item(parent_tree, hf_kpasswd_krb_priv_message, tvb, 0, -1, ENC_NA);
tree=proto_item_add_subtree(it, ett_krb_priv_message);
}
if(isrequest){
offset = dissect_kerberos_main(tvb, pinfo, tree, FALSE, cb_req);
} else {
offset = dissect_kerberos_main(tvb, pinfo, tree, FALSE, cb_rep);
}
return offset;
}
static gint
dissect_kpasswd_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean have_rm)
{
proto_item *kpasswd_item=NULL;
proto_tree *kpasswd_tree=NULL;
int offset = 0;
guint16 message_len, version, ap_req_len;
tvbuff_t *next_tvb;
guint32 krb_rm = 0;
gint krb_reclen = 0;
gint krb_rm_size = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KPASSWD");
col_clear(pinfo->cinfo, COL_INFO);
if (have_rm) {
krb_rm = tvb_get_ntohl(tvb, offset);
krb_reclen = kerberos_rm_to_reclen(krb_rm);
krb_rm_size = 4;
if (krb_reclen > 10 * 1024 * 1024) {
return (-1);
}
offset += krb_rm_size;
}
if(tvb_get_guint8(tvb, offset)==0x7e){
next_tvb=tvb_new_subset_remaining(tvb, offset);
return dissect_kerberos_main(next_tvb, pinfo, tree, FALSE, NULL);
}
message_len=tvb_get_ntohs(tvb, offset);
version=tvb_get_ntohs(tvb, offset+2);
ap_req_len=tvb_get_ntohs(tvb, offset+4);
if(tree){
kpasswd_item=proto_tree_add_item(tree, proto_kpasswd, tvb, offset-krb_rm_size, message_len+krb_rm_size, ENC_NA);
kpasswd_tree=proto_item_add_subtree(kpasswd_item, ett_kpasswd);
if (have_rm) {
show_krb_recordmark(kpasswd_tree, tvb, offset-krb_rm_size, krb_rm);
}
}
proto_tree_add_uint(kpasswd_tree, hf_kpasswd_message_len, tvb, offset, 2, message_len);
proto_tree_add_uint(kpasswd_tree, hf_kpasswd_version, tvb, offset+2, 2, version);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(version, vers_vals, "Unknown command"));
proto_tree_add_uint(kpasswd_tree, hf_kpasswd_ap_req_len, tvb, offset+4, 2, ap_req_len);
offset+=6;
next_tvb=tvb_new_subset_length(tvb, offset, ap_req_len);
dissect_kpasswd_ap_req_data(pinfo, next_tvb, kpasswd_tree);
offset+=ap_req_len;
next_tvb=tvb_new_subset_remaining(tvb, offset);
offset += dissect_kpasswd_krb_priv_message(pinfo, next_tvb, kpasswd_tree, (version==0xff80));
proto_item_set_len(kpasswd_item, offset);
return offset;
}
static void
dissect_kpasswd_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_kpasswd_common(tvb, pinfo, tree, FALSE);
}
static int
dissect_kpasswd_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
pinfo->fragmented = TRUE;
if (dissect_kpasswd_common(tvb, pinfo, tree, TRUE) < 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
}
return tvb_captured_length(tvb);
}
static int
dissect_kpasswd_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KPASSWD");
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, kpasswd_desegment, 4, get_krb_pdu_len, dissect_kpasswd_tcp_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_kpasswd(void)
{
static hf_register_info hf[] = {
{ &hf_kpasswd_message_len,
{ "Message Length", "kpasswd.message_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_kpasswd_ap_req_len,
{ "AP_REQ Length", "kpasswd.ap_req_len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of AP_REQ data", HFILL }},
{ &hf_kpasswd_version,
{ "Version", "kpasswd.version", FT_UINT16, BASE_HEX,
VALS(vers_vals), 0, NULL, HFILL }},
{ &hf_kpasswd_result,
{ "Result", "kpasswd.result", FT_UINT16, BASE_DEC,
VALS(kpasswd_result_types), 0, NULL, HFILL }},
{ &hf_kpasswd_result_string,
{ "Result String", "kpasswd.result_string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_kpasswd_newpassword,
{ "New Password", "kpasswd.new_password", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_kpasswd_ap_req_data,
{ "AP_REQ", "kpasswd.ap_req", FT_NONE, BASE_NONE,
NULL, 0, "AP_REQ structure", HFILL }},
{ &hf_kpasswd_krb_priv_message,
{ "KRB-PRIV", "kpasswd.krb_priv", FT_NONE, BASE_NONE,
NULL, 0, "KRB-PRIV message", HFILL }},
{ &hf_kpasswd_ChangePasswdData, {
"ChangePasswdData", "kpasswd.ChangePasswdData", FT_NONE, BASE_NONE,
NULL, 0, "Change Password Data structure", HFILL }},
};
static gint *ett[] = {
&ett_kpasswd,
&ett_ap_req_data,
&ett_krb_priv_message,
};
module_t *kpasswd_module;
proto_kpasswd = proto_register_protocol("MS Kpasswd",
"Kpasswd", "kpasswd");
proto_register_field_array(proto_kpasswd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
kpasswd_module = prefs_register_protocol(proto_kpasswd, NULL);
prefs_register_bool_preference(kpasswd_module, "desegment",
"Reassemble Kpasswd over TCP messages spanning multiple TCP segments",
"Whether the Kpasswd dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&kpasswd_desegment);
}
void
proto_reg_handoff_kpasswd(void)
{
dissector_handle_t kpasswd_handle_udp;
dissector_handle_t kpasswd_handle_tcp;
kpasswd_handle_udp = create_dissector_handle(dissect_kpasswd_udp, proto_kpasswd);
kpasswd_handle_tcp = new_create_dissector_handle(dissect_kpasswd_tcp, proto_kpasswd);
dissector_add_uint("udp.port", UDP_PORT_KPASSWD, kpasswd_handle_udp);
dissector_add_uint("tcp.port", TCP_PORT_KPASSWD, kpasswd_handle_tcp);
}
