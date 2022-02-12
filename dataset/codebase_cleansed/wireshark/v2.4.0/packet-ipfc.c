static gboolean
capture_ipfc (const guchar *pd, int offset _U_, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
if (!BYTES_ARE_IN_FRAME(0, len, 16))
return FALSE;
return call_capture_dissector(llc_cap_handle, pd, 16, len, cpinfo, pseudo_header);
}
static int
dissect_ipfc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
return tvb_captured_length(tvb);
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
capture_dissector_handle_t ipfc_cap_handle;
ipfc_handle = create_dissector_handle (dissect_ipfc, proto_ipfc);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IP_OVER_FC, ipfc_handle);
llc_handle = find_dissector_add_dependency("llc", proto_ipfc);
ipfc_cap_handle = create_capture_dissector_handle(capture_ipfc, proto_ipfc);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_IP_OVER_FC, ipfc_cap_handle);
llc_cap_handle = find_capture_dissector("llc");
}
