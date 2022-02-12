static int
dissect_hp_erm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *hp_erm_tree;
tvbuff_t *eth_tvb;
int offset = 0;
const gint *flags[] = {
&hf_hp_erm_unknown2,
&hf_hp_erm_priority,
&hf_hp_erm_cfi,
&hf_hp_erm_vlan,
&hf_hp_erm_is_tagged,
&hf_hp_erm_unknown3,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME ":");
ti = proto_tree_add_item(tree, proto_hp_erm, tvb, 0, -1, ENC_NA);
hp_erm_tree = proto_item_add_subtree(ti, ett_hp_erm);
proto_tree_add_item(hp_erm_tree, hf_hp_erm_unknown1, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_bitmask_list(hp_erm_tree, tvb, offset, 4, flags, ENC_BIG_ENDIAN);
offset += 4;
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(eth_withoutfcs_handle, eth_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_hp_erm(void)
{
static hf_register_info hf[] = {
{ &hf_hp_erm_unknown1,
{ "Unknown1", "hp_erm.unknown1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_hp_erm_unknown2,
{ "Unknown2", "hp_erm.unknown2", FT_UINT32, BASE_DEC, NULL,
0xFF000000, NULL, HFILL }},
{ &hf_hp_erm_priority,
{ "Priority", "hp_erm.priority", FT_UINT32, BASE_DEC, VALS(hp_erm_pri_vals),
0x00E00000, NULL, HFILL }},
{ &hf_hp_erm_cfi,
{ "CFI", "hp_erm.cfi", FT_BOOLEAN, 32, TFS(&hp_erm_canonical),
0x00100000, NULL, HFILL }},
{ &hf_hp_erm_vlan,
{ "Vlan", "hp_erm.vlan", FT_UINT32, BASE_DEC, NULL,
0x000FFF00, NULL, HFILL }},
{ &hf_hp_erm_is_tagged,
{ "Is_Tagged", "hp_erm.is_tagged", FT_BOOLEAN, 32, TFS(&tfs_yes_no),
0x00000080, NULL, HFILL }},
{ &hf_hp_erm_unknown3,
{ "Unknown3", "hp_erm.unknown3", FT_UINT32, BASE_DEC, NULL,
0x0000007F, NULL, HFILL }}
};
static gint *ett[] = {
&ett_hp_erm,
};
proto_hp_erm = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "hp_erm");
proto_register_field_array(proto_hp_erm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_hp_erm(void)
{
dissector_handle_t hp_erm_handle;
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_hp_erm);
hp_erm_handle = create_dissector_handle(dissect_hp_erm, proto_hp_erm);
dissector_add_for_decode_as_with_preference("udp.port", hp_erm_handle);
}
