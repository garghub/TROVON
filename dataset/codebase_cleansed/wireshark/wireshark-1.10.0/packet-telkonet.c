static void
dissect_telkonet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ti, *telkonet_tree;
int offset = 0;
telkonet_type_t type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TELKONET");
col_clear(pinfo->cinfo, COL_INFO);
type = (telkonet_type_t)tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Telkonet type: %s",
val_to_str(type, telkonet_type_vals, "Unknown (0x%02x)"));
}
telkonet_tree = NULL;
ti = proto_tree_add_item(tree, proto_telkonet, tvb, 0, 8, ENC_NA);
telkonet_tree = proto_item_add_subtree(ti, ett_telkonet);
proto_tree_add_item(telkonet_tree, hf_telkonet_type, tvb, 0, 8, ENC_NA);
offset += 8;
if (type == TELKONET_TYPE_TUNNEL)
call_dissector(eth_withoutfcs_handle, tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
}
void
proto_register_telkonet(void)
{
static hf_register_info hf[] = {
{ &hf_telkonet_type,
{ "Type", "telkonet.type", FT_BYTES, BASE_NONE, NULL,
0x0, "TELKONET type", HFILL }},
};
static gint *ett[] = {
&ett_telkonet,
};
proto_telkonet = proto_register_protocol("Telkonet powerline", "TELKONET", "telkonet");
proto_register_field_array(proto_telkonet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_telkonet(void)
{
dissector_handle_t telkonet_handle;
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
telkonet_handle = create_dissector_handle(dissect_telkonet, proto_telkonet);
dissector_add_uint("ethertype", ETHERTYPE_TELKONET, telkonet_handle);
}
