static void
dissect_ncs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ncs_tree;
proto_item *ti;
ti = proto_tree_add_item(tree, proto_ncs, tvb, 0, -1, ENC_NA);
ncs_tree = proto_item_add_subtree(ti, ett_ncs);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NCS");
col_set_str(pinfo->cinfo, COL_INFO, "Novell Cluster Services Heartbeat");
proto_tree_add_item(ncs_tree, hf_panning_id, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ncs_tree, hf_incarnation, tvb, 8, 4, ENC_BIG_ENDIAN);
}
void
proto_register_ncs(void)
{
static hf_register_info hf[] = {
{ &hf_panning_id,
{ "Panning ID", "ncs.pan_id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_incarnation,
{ "Incarnation", "ncs.incarnation", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_ncs,
};
proto_ncs = proto_register_protocol("Novell Cluster Services",
"NCS", "ncs");
proto_register_field_array(proto_ncs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ncs(void)
{
dissector_handle_t ncs_handle;
ncs_handle = create_dissector_handle(dissect_ncs, proto_ncs);
dissector_add_uint("ip.proto", IP_PROTO_NCS_HEARTBEAT, ncs_handle);
}
