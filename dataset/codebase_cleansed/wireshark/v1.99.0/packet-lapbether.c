static void
dissect_lapbether(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *lapbether_tree, *ti;
int len;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LAPBETHER");
col_clear(pinfo->cinfo, COL_INFO);
len = tvb_get_guint8(tvb, 0) + tvb_get_guint8(tvb, 1) * 256;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_lapbether, tvb, 0, 2,
"LAPBETHER");
lapbether_tree = proto_item_add_subtree(ti, ett_lapbether);
proto_tree_add_uint_format(lapbether_tree, hf_lapbether_length, tvb, 0, 2,
len, "Length: %u", len);
}
next_tvb = tvb_new_subset_length(tvb, 2, len);
call_dissector(lapb_handle, next_tvb, pinfo, tree);
}
void
proto_register_lapbether(void)
{
static hf_register_info hf[] = {
{ &hf_lapbether_length,
{ "Length Field", "lapbether.length", FT_UINT16, BASE_DEC, NULL, 0x0,
"LAPBEther Length Field", HFILL }},
};
static gint *ett[] = {
&ett_lapbether,
};
proto_lapbether = proto_register_protocol ("Link Access Procedure Balanced Ethernet (LAPBETHER)",
"LAPBETHER", "lapbether");
proto_register_field_array (proto_lapbether, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lapbether(void)
{
dissector_handle_t lapbether_handle;
lapb_handle = find_dissector("lapb");
lapbether_handle = create_dissector_handle(dissect_lapbether,
proto_lapbether);
dissector_add_uint("ethertype", ETHERTYPE_DEC, lapbether_handle);
}
