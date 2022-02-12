static void
dissect_retix_bpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *retix_bpdu_tree;
proto_tree *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "R-STP");
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "Bridge MAC %s", tvb_ether_to_str(tvb, 10));
retix_bpdu_tree = NULL;
if (tree) {
ti = proto_tree_add_item(tree, proto_retix_bpdu, tvb, 0, -1, ENC_NA);
retix_bpdu_tree = proto_item_add_subtree(ti, ett_retix_bpdu);
}
proto_tree_add_item(retix_bpdu_tree, hf_retix_bpdu_root_mac, tvb, 0, 6, ENC_NA);
proto_tree_add_item(retix_bpdu_tree, hf_retix_bpdu_bridge_mac, tvb, 10, 6, ENC_NA);
proto_tree_add_item(retix_bpdu_tree, hf_retix_bpdu_max_age, tvb, 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(retix_bpdu_tree, hf_retix_bpdu_hello_time, tvb, 22, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(retix_bpdu_tree, hf_retix_bpdu_forward_delay, tvb, 24, 2, ENC_BIG_ENDIAN);
}
void
proto_register_retix_bpdu(void)
{
static hf_register_info hf[] = {
{ &hf_retix_bpdu_root_mac,
{ "Root MAC", "r-stp.root.hw", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_retix_bpdu_bridge_mac,
{ "Bridge MAC", "r-stp.bridge.hw", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_retix_bpdu_max_age,
{ "Max Age", "r-stp.maxage", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_retix_bpdu_hello_time,
{ "Hello Time", "r-stp.hello", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_retix_bpdu_forward_delay,
{ "Forward Delay", "r-stp.forward", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] ={
&ett_retix_bpdu,
};
proto_retix_bpdu = proto_register_protocol("Retix Spanning Tree Protocol", "R-STP", "r-stp");
proto_register_field_array(proto_retix_bpdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rbpdu", dissect_retix_bpdu, proto_retix_bpdu);
}
void
proto_reg_handoff_retix_bpdu(void)
{
}
