static void
dissect_slow_protocols(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 subtype;
proto_tree *pdu_tree;
proto_item *pdu_item;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Slow Protocols");
subtype = tvb_get_guint8(tvb, 0);
col_add_fstr(pinfo->cinfo, COL_INFO, "Subtype = %u", subtype);
if (tree)
{
pdu_item = proto_tree_add_item(tree, proto_slow, tvb, 0, 1, ENC_NA);
pdu_tree = proto_item_add_subtree(pdu_item, ett_slow);
proto_tree_add_item(pdu_tree, hf_slow_subtype, tvb, 0, 1, ENC_NA);
}
next_tvb = tvb_new_subset_remaining(tvb, 1);
if (!dissector_try_uint_new(slow_protocols_dissector_table, subtype,
next_tvb, pinfo, tree, TRUE, NULL))
call_dissector(dh_data, next_tvb, pinfo, tree);
}
void
proto_register_slow_protocols(void)
{
static hf_register_info hf[] = {
{ &hf_slow_subtype,
{ "Slow Protocols subtype", "slow.subtype",
FT_UINT8, BASE_HEX, VALS(subtype_vals), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_slow,
};
proto_slow = proto_register_protocol("Slow Protocols", "802.3 Slow protocols", "slow");
proto_register_field_array(proto_slow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
slow_protocols_dissector_table = register_dissector_table("slow.subtype",
"Slow protocol subtype",
FT_UINT8, BASE_DEC);
}
void
proto_reg_handoff_slow_protocols(void)
{
dissector_handle_t slow_protocols_handle;
slow_protocols_handle = create_dissector_handle(dissect_slow_protocols, proto_slow);
dissector_add_uint("ethertype", ETHERTYPE_SLOW_PROTOCOLS, slow_protocols_handle);
dh_data = find_dissector("data");
}
