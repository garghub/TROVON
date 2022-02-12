static gboolean
dissect_yhoo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *yhoo_tree, *ti;
int offset = 0;
if (pinfo->srcport != TCP_PORT_YHOO && pinfo->destport != TCP_PORT_YHOO) {
return FALSE;
}
if ( tvb_captured_length(tvb) < YAHOO_RAWPACKET_LEN ) {
return FALSE;
}
if (tvb_memeql(tvb, offset, "YPNS", 4) != 0 &&
tvb_memeql(tvb, offset, "YHOO", 4) != 0) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "YHOO");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
( tvb_memeql(tvb, offset + 0, "YPNS", 4) == 0 ) ? "Request" : "Response",
val_to_str(tvb_get_letohl(tvb, offset + 12),
yhoo_service_vals, "Unknown Service: %u"));
if (tree) {
ti = proto_tree_add_item(tree, proto_yhoo, tvb,
offset, -1, ENC_NA);
yhoo_tree = proto_item_add_subtree(ti, ett_yhoo);
proto_tree_add_item(yhoo_tree, hf_yhoo_version, tvb,
offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(yhoo_tree, hf_yhoo_len, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_service, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_connection_id, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_magic_id, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_unknown1, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_msgtype, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(yhoo_tree, hf_yhoo_nick1, tvb,
offset, 36, ENC_ASCII|ENC_NA);
offset += 36;
proto_tree_add_item(yhoo_tree, hf_yhoo_nick2, tvb,
offset, 36, ENC_ASCII|ENC_NA);
offset += 36;
proto_tree_add_item(yhoo_tree, hf_yhoo_content, tvb, -1,
offset, ENC_ASCII|ENC_NA);
}
return TRUE;
}
void
proto_register_yhoo(void)
{
static hf_register_info hf[] = {
{ &hf_yhoo_service, {
"Service Type", "yhoo.service", FT_UINT32, BASE_DEC,
VALS(yhoo_service_vals), 0, NULL, HFILL }},
{ &hf_yhoo_msgtype, {
"Message Type", "yhoo.msgtype", FT_UINT32, BASE_DEC,
VALS(yhoo_msgtype_vals), 0, "Message Type Flags", HFILL }},
{ &hf_yhoo_connection_id, {
"Connection ID", "yhoo.connection_id", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_magic_id, {
"Magic ID", "yhoo.magic_id", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_unknown1, {
"Unknown 1", "yhoo.unknown1", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_len, {
"Packet Length", "yhoo.len", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_nick1, {
"Real Nick (nick1)", "yhoo.nick1", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_nick2, {
"Active Nick (nick2)", "yhoo.nick2", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_yhoo_content, {
"Content", "yhoo.content", FT_STRING, BASE_NONE,
NULL, 0, "Data portion of the packet", HFILL }},
{ &hf_yhoo_version, {
"Version", "yhoo.version", FT_STRING, BASE_NONE,
NULL, 0, "Packet version identifier", HFILL }},
};
static gint *ett[] = {
&ett_yhoo,
};
proto_yhoo = proto_register_protocol("Yahoo Messenger Protocol",
"YHOO", "yhoo");
proto_register_field_array(proto_yhoo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_yhoo(void)
{
heur_dissector_add("tcp", dissect_yhoo, "Yahoo Messenger over TCP", "yhoo_tcp", proto_yhoo, HEURISTIC_ENABLE);
}
