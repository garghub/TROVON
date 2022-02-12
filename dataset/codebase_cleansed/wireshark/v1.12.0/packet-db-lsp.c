static int
dissect_db_lsp_pdu (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *db_lsp_tree;
proto_item *db_lsp_item;
gint offset = 0;
guint8 type, opvalue;
guint16 magic, length;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_set_str (pinfo->cinfo, COL_INFO, PNAME);
db_lsp_item = proto_tree_add_item (tree, proto_db_lsp, tvb, offset, -1, ENC_NA);
db_lsp_tree = proto_item_add_subtree (db_lsp_item, ett_db_lsp);
type = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (db_lsp_tree, hf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (type == 0x80) {
offset += 2;
}
magic = tvb_get_ntohs (tvb, offset);
proto_tree_add_item (db_lsp_tree, hf_magic, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length = tvb_get_ntohs (tvb, offset);
proto_tree_add_item (db_lsp_tree, hf_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (magic != 0x0301 || length > tvb_length_remaining (tvb, offset)) {
return 0;
}
if (type == TYPE_CONFIG) {
opvalue = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (db_lsp_tree, hf_opvalue, tvb, offset, 1, ENC_BIG_ENDIAN);
if (opvalue == OP_CERT) {
tvbuff_t *cert_tvb = tvb_new_subset (tvb, offset+10, length-10, length-10);
dissect_x509af_Certificate_PDU (cert_tvb, pinfo, db_lsp_tree);
} else {
proto_tree_add_item (db_lsp_tree, hf_value, tvb, offset, length, ENC_NA);
}
} else if (type == TYPE_DATA) {
proto_tree_add_item (db_lsp_tree, hf_data, tvb, offset, length, ENC_NA);
} else {
proto_tree_add_item (db_lsp_tree, hf_value, tvb, offset, length, ENC_NA);
}
proto_item_append_text (db_lsp_item, ", Type: %d, Length: %d", type, length);
proto_item_set_len (db_lsp_item, length + 5);
return tvb_length(tvb);
}
static guint
get_db_lsp_pdu_len (packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
if (tvb_get_ntohs (tvb, offset + 1) != 0x0301) {
return tvb_length_remaining (tvb, offset);
}
return tvb_get_ntohs (tvb, offset + 3) + 5;
}
static int
dissect_db_lsp_tcp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus (tvb, pinfo, tree, db_lsp_desegment, 5,
get_db_lsp_pdu_len, dissect_db_lsp_pdu, data);
return tvb_length(tvb);
}
static void
dissect_db_lsp_disc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *db_lsp_tree;
proto_item *db_lsp_item;
gint offset = 0;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME_DISC);
col_set_str (pinfo->cinfo, COL_INFO, PNAME_DISC);
db_lsp_item = proto_tree_add_item (tree, proto_db_lsp_disc, tvb, offset, -1, ENC_NA);
db_lsp_tree = proto_item_add_subtree (db_lsp_item, ett_db_lsp);
proto_tree_add_item (db_lsp_tree, hf_text, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
void
proto_register_db_lsp (void)
{
static hf_register_info hf[] = {
{ &hf_type,
{ "Type", "db-lsp.type",
FT_UINT8, BASE_DEC_HEX, VALS(type_vals), 0x0,
NULL, HFILL } },
{ &hf_magic,
{ "Magic", "db-lsp.magic",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"Magic number", HFILL } },
{ &hf_length,
{ "Length", "db-lsp.length",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"Length in bytes", HFILL } },
{ &hf_opvalue,
{ "OP Value", "db-lsp.op",
FT_UINT8, BASE_DEC_HEX, VALS(op_vals), 0x0,
NULL, HFILL } },
{ &hf_value,
{ "Value", "db-lsp.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_data,
{ "Data", "db-lsp.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_text,
{ "Text", "db-lsp.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
};
static gint *ett[] = {
&ett_db_lsp,
};
module_t *db_lsp_module;
proto_db_lsp = proto_register_protocol (PNAME, PSNAME, PFNAME);
proto_db_lsp_disc = proto_register_protocol (PNAME_DISC, PSNAME_DISC, PFNAME_DISC);
new_register_dissector ("db-lsp.tcp", dissect_db_lsp_tcp, proto_db_lsp);
register_dissector ("db-lsp.udp", dissect_db_lsp_disc, proto_db_lsp_disc);
proto_register_field_array (proto_db_lsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
db_lsp_module = prefs_register_protocol (proto_db_lsp, NULL);
prefs_register_bool_preference (db_lsp_module, "desegment_pdus",
"Reassemble PDUs spanning multiple TCP segments",
"Whether the LAN sync dissector should reassemble PDUs"
" spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors"
" to reassemble TCP streams\" in the TCP protocol settings.",
&db_lsp_desegment);
}
void
proto_reg_handoff_db_lsp (void)
{
dissector_handle_t db_lsp_tcp_handle;
dissector_handle_t db_lsp_udp_handle;
db_lsp_tcp_handle = find_dissector ("db-lsp.tcp");
db_lsp_udp_handle = find_dissector ("db-lsp.udp");
dissector_add_uint ("tcp.port", DB_LSP_PORT, db_lsp_tcp_handle);
dissector_add_uint ("udp.port", DB_LSP_PORT, db_lsp_udp_handle);
}
