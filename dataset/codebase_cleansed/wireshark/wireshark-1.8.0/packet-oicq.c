static int
dissect_oicq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *oicq_tree;
proto_item *ti;
int offset = 0;
if ( (match_strval(tvb_get_guint8(tvb, 0), oicq_flag_vals) == NULL) ||
(match_strval(tvb_get_ntohs(tvb, 3), oicq_command_vals) == NULL) )
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OICQ");
col_set_str(pinfo->cinfo, COL_INFO, "OICQ Protocol ");
if (tree) {
ti = proto_tree_add_item(tree, proto_oicq, tvb, 0, -1, ENC_NA);
oicq_tree = proto_item_add_subtree(ti, ett_oicq);
proto_tree_add_item(oicq_tree, hf_oicq_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(oicq_tree, hf_oicq_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oicq_tree, hf_oicq_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oicq_tree, hf_oicq_seq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(oicq_tree, hf_oicq_qqid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(oicq_tree, hf_oicq_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
return tvb_length(tvb);
}
void
proto_register_oicq(void)
{
static hf_register_info hf[] = {
{ &hf_oicq_flag, {
"Flag", "oicq.flag", FT_UINT8, BASE_HEX,
VALS(oicq_flag_vals), 0, "Protocol Flag", HFILL }},
{ &hf_oicq_version, {
"Version", "oicq.version", FT_UINT16, BASE_HEX,
NULL, 0, "Version-zz", HFILL }},
{ &hf_oicq_command, {
"Command", "oicq.command", FT_UINT16, BASE_DEC,
VALS(oicq_command_vals), 0, NULL, HFILL }},
{ &hf_oicq_seq, {
"Sequence", "oicq.seq", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_oicq_qqid, {
"Data(OICQ Number,if sender is client)", "oicq.qqid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_oicq_data, {
"Data", "oicq.data", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_oicq,
};
proto_oicq = proto_register_protocol("OICQ - IM software, popular in China", "OICQ",
"oicq");
proto_register_field_array(proto_oicq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_oicq(void)
{
dissector_handle_t oicq_handle;
oicq_handle = new_create_dissector_handle(dissect_oicq, proto_oicq);
dissector_add_uint("udp.port", UDP_PORT_OICQ, oicq_handle);
}
