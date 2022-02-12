static void
dissect_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 encap_proto;
ethertype_data_t ethertype_data;
proto_tree *cmd_tree = NULL;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMD");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti = proto_tree_add_item(tree, proto_cmd, tvb, 0, 6, ENC_NA);
cmd_tree = proto_item_add_subtree(ti, ett_cmd);
proto_tree_add_item(cmd_tree, hf_cmd_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cmd_tree, hf_cmd_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cmd_tree, hf_cmd_options, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cmd_tree, hf_cmd_sgt, tvb, offset, 2, ENC_BIG_ENDIAN);
}
encap_proto = tvb_get_ntohs(tvb, 6);
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2 = TRUE;
if (tvb_captured_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, cmd_tree, hf_eth_type, hf_cmd_trailer, 0);
} else {
#endif
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = 8;
ethertype_data.fh_tree = cmd_tree;
ethertype_data.etype_id = hf_eth_type;
ethertype_data.trailer_id = hf_cmd_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
}
void
proto_register_cmd(void)
{
static hf_register_info hf[] = {
{ &hf_cmd_version,
{ "Version", "cmd.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cmd_length,
{ "Length", "cmd.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cmd_options,
{ "Options", "cmd.options", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_cmd_sgt,
{ "SGT", "cmd.sgt", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_eth_type,
{ "Type", "cmd.type", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0, NULL, HFILL }
},
{ &hf_cmd_trailer,
{ "Trailer", "cmd.trailer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_cmd
};
proto_cmd = proto_register_protocol("Cisco MetaData", "Cisco MetaData", "cmd");
proto_register_field_array(proto_cmd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cmd(void)
{
dissector_handle_t cmd_handle;
ethertype_handle = find_dissector("ethertype");
cmd_handle = create_dissector_handle(dissect_cmd, proto_cmd);
dissector_add_uint("ethertype", ETHERTYPE_CMD, cmd_handle);
}
