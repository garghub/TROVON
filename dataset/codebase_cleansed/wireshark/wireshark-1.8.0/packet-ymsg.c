static int get_content_item_length(tvbuff_t *tvb, int offset)
{
int origoffset = offset;
while (tvb_length_remaining(tvb, offset) >= 2) {
if (tvb_get_ntohs(tvb, offset) == 0xc080) {
break;
}
offset += 1;
}
return offset - origoffset;
}
static gboolean
dissect_ymsg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_length(tvb) < 4) {
return FALSE;
}
if (tvb_memeql(tvb, 0, "YMSG", 4) == -1) {
return FALSE;
}
tcp_dissect_pdus(tvb, pinfo, tree, ymsg_desegment, 10, get_ymsg_pdu_len,
dissect_ymsg_pdu);
return TRUE;
}
static guint
get_ymsg_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint plen;
plen = tvb_get_ntohs(tvb, offset + 8);
return plen + YAHOO_HEADER_SIZE;
}
static void
dissect_ymsg_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ymsg_tree, *ti;
proto_item *content_item;
proto_tree *content_tree;
char *keybuf;
char *valbuf;
int keylen;
int vallen;
int content_len;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "YMSG");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (status=%s) ",
val_to_str(tvb_get_ntohs(tvb, offset + 10),
ymsg_service_vals, "Unknown Service: %u"),
val_to_str(tvb_get_ntohl(tvb, offset + 12),
ymsg_status_vals, "Unknown Status: %u")
);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ymsg, tvb, offset, -1, ENC_NA);
ymsg_tree = proto_item_add_subtree(ti, ett_ymsg);
offset += 4;
proto_tree_add_item(ymsg_tree, hf_ymsg_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ymsg_tree, hf_ymsg_vendor, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
content_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ymsg_tree, hf_ymsg_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_append_text(ti, " (%s)",
val_to_str_const(tvb_get_ntohs(tvb, offset),
ymsg_service_vals,
"Unknown"));
proto_tree_add_item(ymsg_tree, hf_ymsg_service, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ymsg_tree, hf_ymsg_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ymsg_tree, hf_ymsg_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (content_len) {
content_item = proto_tree_add_item(ymsg_tree, hf_ymsg_content, tvb,
offset, -1, ENC_ASCII|ENC_NA);
content_tree = proto_item_add_subtree(content_item, ett_ymsg_content);
for (;;)
{
proto_item *ti_2;
proto_tree *content_line_tree;
if (offset >= (YAHOO_HEADER_SIZE+content_len-4))
{
break;
}
keylen = get_content_item_length(tvb, offset);
keybuf = tvb_format_text(tvb, offset, keylen);
vallen = get_content_item_length(tvb, offset+keylen+2);
valbuf = tvb_format_text(tvb, offset+keylen+2, vallen);
ti_2 = proto_tree_add_string_format(content_tree, hf_ymsg_content_line, tvb,
offset, keylen+2+vallen+2,
"", "%s:%s", keybuf, valbuf);
content_line_tree = proto_item_add_subtree(ti_2, ett_ymsg_content_line);
proto_tree_add_item(content_line_tree, hf_ymsg_content_line_key, tvb,
offset, keylen, ENC_ASCII|ENC_NA);
proto_tree_add_item(content_line_tree, hf_ymsg_content_line_value, tvb,
offset+keylen+2, vallen, ENC_ASCII|ENC_NA);
offset += keylen+2+vallen+2;
}
}
}
col_set_fence(pinfo->cinfo, COL_INFO);
return;
}
void
proto_register_ymsg(void)
{
static hf_register_info hf[] = {
{ &hf_ymsg_version, {
"Version", "ymsg.version", FT_UINT16, BASE_DEC,
NULL, 0, "Packet version identifier", HFILL }},
{ &hf_ymsg_vendor, {
"Vendor ID", "ymsg.vendor", FT_UINT16, BASE_DEC,
NULL, 0, "Vendor identifier", HFILL }},
{ &hf_ymsg_len, {
"Packet Length", "ymsg.len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ymsg_service, {
"Service", "ymsg.service", FT_UINT16, BASE_DEC,
VALS(ymsg_service_vals), 0, "Service Type", HFILL }},
{ &hf_ymsg_status, {
"Status", "ymsg.status", FT_UINT32, BASE_DEC,
VALS(ymsg_status_vals), 0, "Message Type Flags", HFILL }},
{ &hf_ymsg_session_id, {
"Session ID", "ymsg.session_id", FT_UINT32, BASE_HEX,
NULL, 0, "Connection ID", HFILL }},
{ &hf_ymsg_content, {
"Content", "ymsg.content", FT_STRING, BASE_NONE,
NULL, 0, "Data portion of the packet", HFILL }},
{ &hf_ymsg_content_line, {
"Content-line", "ymsg.content-line", FT_STRING, BASE_NONE,
NULL, 0, "Data portion of the packet", HFILL }},
{ &hf_ymsg_content_line_key, {
"Key", "ymsg.content-line.key", FT_STRING, BASE_NONE,
NULL, 0, "Content line key", HFILL }},
{ &hf_ymsg_content_line_value, {
"Value", "ymsg.content-line.value", FT_STRING, BASE_NONE,
NULL, 0, "Content line value", HFILL }}
};
static gint *ett[] = {
&ett_ymsg,
&ett_ymsg_content,
&ett_ymsg_content_line
};
module_t *ymsg_module;
proto_ymsg = proto_register_protocol("Yahoo YMSG Messenger Protocol",
"YMSG", "ymsg");
proto_register_field_array(proto_ymsg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ymsg_module = prefs_register_protocol(proto_ymsg, NULL);
prefs_register_bool_preference(ymsg_module, "desegment",
"Reassemble YMSG messages spanning multiple TCP segments",
"Whether the YMSG dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ymsg_desegment);
}
void
proto_reg_handoff_ymsg(void)
{
heur_dissector_add("tcp", dissect_ymsg, proto_ymsg);
}
