static void
dissect_wfleet_hdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
tvbuff_t *next_tvb;
guint8 addr;
guint8 cmd;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WHDLC");
col_clear(pinfo->cinfo, COL_INFO);
addr = tvb_get_guint8(tvb, 0);
cmd = tvb_get_guint8(tvb, 1);
if (tree) {
ti = proto_tree_add_item(tree, proto_wfleet_hdlc, tvb, 0, 2, ENC_NA);
fh_tree = proto_item_add_subtree(ti, ett_wfleet_hdlc);
proto_tree_add_uint(fh_tree, hf_wfleet_hdlc_addr, tvb, 0, 1, addr);
proto_tree_add_uint(fh_tree, hf_wfleet_hdlc_cmd, tvb, 1, 1, cmd);
}
next_tvb = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
}
void
proto_register_wfleet_hdlc(void)
{
static hf_register_info hf[] = {
{ &hf_wfleet_hdlc_addr,
{ "Address", "wfleet_hdlc.address", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_wfleet_hdlc_cmd,
{ "Command", "wfleet_hdlc.command", FT_UINT8, BASE_HEX,
VALS(wfleet_hdlc_cmd_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_wfleet_hdlc,
};
proto_wfleet_hdlc = proto_register_protocol("Wellfleet HDLC", "WHDLC", "whdlc");
proto_register_field_array(proto_wfleet_hdlc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wfleet_hdlc", dissect_wfleet_hdlc, proto_wfleet_hdlc);
}
void
proto_reg_handoff_wfleet_hdlc(void)
{
dissector_handle_t wfleet_hdlc_handle;
wfleet_hdlc_handle = find_dissector("wfleet_hdlc");
dissector_add_uint("wtap_encap", WTAP_ENCAP_WFLEET_HDLC, wfleet_hdlc_handle);
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
}
