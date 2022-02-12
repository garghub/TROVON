static void
dissect_hp_erm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *hp_erm_tree = NULL;
tvbuff_t *eth_tvb;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME ":");
if (tree) {
ti = proto_tree_add_item(tree, proto_hp_erm, tvb, 0, -1, ENC_NA);
hp_erm_tree = proto_item_add_subtree(ti, ett_hp_erm);
}
proto_tree_add_item(hp_erm_tree, hf_hp_erm_unknown1, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(hp_erm_tree, hf_hp_erm_unknown2, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hp_erm_tree, hf_hp_erm_priority, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hp_erm_tree, hf_hp_erm_cfi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hp_erm_tree, hf_hp_erm_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hp_erm_tree, hf_hp_erm_unknown3, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
eth_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(eth_withoutfcs_handle, eth_tvb, pinfo, tree);
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
{ "CFI", "hp_erm.cfi", FT_UINT32, BASE_DEC, VALS(hp_erm_cfi_vals),
0x00100000, NULL, HFILL }},
{ &hf_hp_erm_vlan,
{ "Vlan", "hp_erm.vlan", FT_UINT32, BASE_DEC, NULL,
0x000FFF00, NULL, HFILL }},
{ &hf_hp_erm_unknown3,
{ "Unknown3", "hp_erm.unknown3", FT_UINT32, BASE_DEC, NULL,
0x000000FF, NULL, HFILL }}
};
static gint *ett[] = {
&ett_hp_erm,
};
module_t *hp_erm_module;
proto_hp_erm = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "hp_erm");
hp_erm_module = prefs_register_protocol(proto_hp_erm, proto_reg_handoff_hp_erm);
prefs_register_uint_preference(hp_erm_module, "udp.port", "HP_ERM UDP Port",
"Set the UDP port (source or destination) used for HP"
" encapsulated remote mirroring frames;\n"
"0 (default) means that the HP_ERM dissector is not active",
10, &global_hp_erm_udp_port);
proto_register_field_array(proto_hp_erm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_hp_erm(void)
{
static dissector_handle_t hp_erm_handle;
static guint hp_erm_udp_port;
static gboolean initialized = FALSE;
if (!initialized) {
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
hp_erm_handle = create_dissector_handle(dissect_hp_erm, proto_hp_erm);
initialized = TRUE;
} else {
if (hp_erm_udp_port != 0)
dissector_delete_uint("udp.port", hp_erm_udp_port, hp_erm_handle);
}
hp_erm_udp_port = global_hp_erm_udp_port;
if (hp_erm_udp_port != 0)
dissector_add_uint("udp.port", hp_erm_udp_port, hp_erm_handle);
}
