static void
dissect_interlink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *il_tree;
proto_item *il_item;
proto_tree *ilh_tree = NULL;
proto_tree *ilb_tree = NULL;
guint8 ilb_type;
guint8 ilb_version;
guint16 type_version = 0;
dissector_handle_t handle;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "INTERLINK");
col_clear(pinfo->cinfo, COL_INFO);
il_item = proto_tree_add_item(tree, proto_interlink,
tvb, 0, 16, ENC_NA);
il_tree = proto_item_add_subtree(il_item, ett_interlink);
ilh_tree = proto_tree_add_subtree(il_tree, tvb, 0, 12, ett_interlink_header, NULL, "Interlink Header");
if (ilh_tree) {
proto_tree_add_item(ilh_tree, hf_interlink_id, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(ilh_tree, hf_interlink_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ilh_tree, hf_interlink_cmd, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ilh_tree, hf_interlink_seq, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
offset += 10;
}
if (ilh_tree) {
proto_item *flags_item;
proto_tree *flags_tree;
flags_item = proto_tree_add_item(ilh_tree, hf_interlink_flags,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_interlink_flags);
if (flags_tree) {
guint16 il_flags;
il_flags = tvb_get_letohs(tvb, offset);
proto_tree_add_boolean(flags_tree, hf_interlink_flags_req_ack, tvb, offset, 2, il_flags);
proto_tree_add_boolean(flags_tree, hf_interlink_flags_inc_ack_port, tvb, offset, 2, il_flags);
}
}
offset += 2;
ilb_tree = proto_tree_add_subtree(il_tree, tvb, offset, 4, ett_interlink_block, NULL, "Block Header");
ilb_type = tvb_get_guint8(tvb, offset);
ilb_version = tvb_get_guint8(tvb, offset + 1);
type_version = ilb_type << 8 | ilb_version;
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: %d, Version: %d",
ilb_type, ilb_version);
if (ilb_tree) {
proto_tree_add_item(ilb_tree, hf_interlink_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ilb_tree, hf_interlink_block_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ilb_tree, hf_interlink_block_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
offset += 4;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
handle = dissector_get_uint_handle(subdissector_table, type_version);
if (handle == NULL) handle = data_handle;
call_dissector(handle, next_tvb, pinfo, tree);
}
static gboolean
dissect_interlink_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (!tvb_bytes_exist(tvb, 0, 4)) {
return FALSE;
}
if (
tvb_get_guint8(tvb,0) != 'I' ||
tvb_get_guint8(tvb,1) != 'L' ||
tvb_get_guint8(tvb,2) != 'N' ||
tvb_get_guint8(tvb,3) != 'K'
)
return FALSE;
dissect_interlink(tvb, pinfo, tree);
return TRUE;
}
void
proto_register_interlink(void)
{
static hf_register_info hf[] = {
{ &hf_interlink_id, {
"Magic ID", "interlink.id", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_interlink_version, {
"Version", "interlink.version", FT_UINT16,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_interlink_cmd, {
"Command", "interlink.cmd", FT_UINT16,
BASE_DEC, VALS(names_cmd), 0, NULL, HFILL }},
{ &hf_interlink_seq, {
"Sequence", "interlink.seq", FT_UINT16,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_interlink_flags, {
"Flags", "interlink.flags", FT_UINT16,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_interlink_flags_req_ack, {
"REQ_ACK", "interlink.flags.req_ack", FT_BOOLEAN,
16, TFS(&flags_set_notset), 0x01, NULL, HFILL }},
{ &hf_interlink_flags_inc_ack_port, {
"INC_ACK_PORT", "interlink.flags.inc_ack_port", FT_BOOLEAN,
16, TFS(&flags_set_notset), 0x02, NULL, HFILL }},
{ &hf_interlink_block_type, {
"Type", "interlink.type", FT_UINT8,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_interlink_block_version, {
"Version", "interlink.block_version", FT_UINT8,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_interlink_block_length, {
"Length", "interlink.length", FT_UINT16,
BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_interlink,
&ett_interlink_header,
&ett_interlink_flags,
&ett_interlink_block,
};
proto_interlink = proto_register_protocol("Interlink Protocol",
"Interlink",
"interlink");
proto_register_field_array(proto_interlink, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("interlink", dissect_interlink, proto_interlink);
subdissector_table = register_dissector_table("interlink.type_version",
"Interlink type_version", FT_UINT16, BASE_HEX);
}
void
proto_reg_handoff_interlink(void)
{
dissector_handle_t interlink_handle;
interlink_handle = find_dissector("interlink");
dissector_add_for_decode_as("udp.port", interlink_handle);
heur_dissector_add("udp", dissect_interlink_heur, proto_interlink);
data_handle = find_dissector("data");
}
