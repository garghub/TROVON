static int dissect_bjnp (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *bjnp_tree;
proto_item *ti;
gint offset = 0;
guint32 payload_len;
guint8 dev_type, cmd_code;
gchar *info;
col_set_str (pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear (pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item (tree, proto_bjnp, tvb, offset, -1, ENC_NA);
bjnp_tree = proto_item_add_subtree (ti, ett_bjnp);
proto_tree_add_item (bjnp_tree, hf_bjnp_id, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
dev_type = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (bjnp_tree, hf_dev_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
cmd_code = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (bjnp_tree, hf_cmd_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
info = g_strdup_printf ("%s: %s",val_to_str (dev_type, dev_type_vals, "Unknown type (%d)"),
val_to_str (cmd_code, cmd_code_vals, "Unknown code (%d)"));
proto_item_append_text (ti, ", %s", info);
col_add_str (pinfo->cinfo, COL_INFO, info);
g_free (info);
proto_tree_add_item (bjnp_tree, hf_seq_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item (bjnp_tree, hf_session_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
payload_len = tvb_get_ntohl (tvb, offset);
proto_tree_add_item (bjnp_tree, hf_payload_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (payload_len > 0) {
proto_tree_add_item (bjnp_tree, hf_payload, tvb, offset, payload_len, ENC_NA);
offset += payload_len;
}
return offset;
}
void proto_register_bjnp (void)
{
static hf_register_info hf[] = {
{ &hf_bjnp_id,
{ "Id", "bjnp.id", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_dev_type,
{ "Type", "bjnp.type", FT_UINT8, BASE_DEC,
VALS(dev_type_vals), 0x0, NULL, HFILL } },
{ &hf_cmd_code,
{ "Code", "bjnp.code", FT_UINT8, BASE_DEC,
VALS(cmd_code_vals), 0x0, NULL, HFILL } },
{ &hf_seq_no,
{ "Sequence Number", "bjnp.seq_no", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_session_id,
{ "Session Id", "bjnp.session_id", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_payload_len,
{ "Payload Length", "bjnp.payload_len", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL } },
{ &hf_payload,
{ "Payload", "bjnp.payload", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_bjnp
};
proto_bjnp = proto_register_protocol (PNAME, PSNAME, PFNAME);
new_register_dissector (PFNAME, dissect_bjnp, proto_bjnp);
proto_register_field_array (proto_bjnp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void proto_reg_handoff_bjnp (void)
{
dissector_handle_t bjnp_handle;
bjnp_handle = find_dissector (PFNAME);
dissector_add_uint ("udp.port", BJNP_PORT1, bjnp_handle);
dissector_add_uint ("udp.port", BJNP_PORT2, bjnp_handle);
dissector_add_uint ("udp.port", BJNP_PORT3, bjnp_handle);
dissector_add_uint ("udp.port", BJNP_PORT4, bjnp_handle);
}
