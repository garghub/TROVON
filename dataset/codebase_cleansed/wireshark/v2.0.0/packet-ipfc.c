void
capture_ipfc (const guchar *pd, int len, packet_counts *ld)
{
if (!BYTES_ARE_IN_FRAME(0, len, 16)) {
ld->other++;
return;
}
capture_llc(pd, 16, len, ld);
}
static void
dissect_ipfc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *ipfc_tree;
int offset = 0;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IP/FC");
if (tree) {
ti = proto_tree_add_protocol_format (tree, proto_ipfc, tvb, offset, 16,
"IP Over FC Network_Header");
ipfc_tree = proto_item_add_subtree (ti, ett_ipfc);
proto_tree_add_item (ipfc_tree, hf_ipfc_network_da, tvb, offset, 8, ENC_NA);
proto_tree_add_item (ipfc_tree, hf_ipfc_network_sa, tvb, offset+8, 8, ENC_NA);
}
next_tvb = tvb_new_subset_remaining (tvb, 16);
call_dissector(llc_handle, next_tvb, pinfo, tree);
}
void
proto_register_ipfc (void)
{
static hf_register_info hf[] = {
{ &hf_ipfc_network_da,
{"Network DA", "ipfc.nh.da", FT_FCWWN, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_ipfc_network_sa,
{"Network SA", "ipfc.nh.sa", FT_FCWWN, BASE_NONE, NULL,
0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_ipfc,
};
proto_ipfc = proto_register_protocol("IP Over FC", "IPFC", "ipfc");
proto_register_field_array(proto_ipfc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipfc (void)
{
dissector_handle_t ipfc_handle;
ipfc_handle = create_dissector_handle (dissect_ipfc, proto_ipfc);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IP_OVER_FC, ipfc_handle);
llc_handle = find_dissector ("llc");
}
