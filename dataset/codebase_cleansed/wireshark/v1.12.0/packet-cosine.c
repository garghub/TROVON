static void
dissect_cosine(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
proto_item *ti;
union wtap_pseudo_header *pseudo_header = pinfo->pseudo_header;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "CoSine IPNOS L2 debug output");
if(tree) {
ti = proto_tree_add_protocol_format(tree, proto_cosine, tvb, 0, 0,
"CoSine IPNOS L2 debug output (%s)",
pseudo_header->cosine.if_name);
fh_tree = proto_item_add_subtree(ti, ett_raw);
proto_tree_add_uint(fh_tree, hf_pro, tvb, 0, 0, pseudo_header->cosine.pro);
proto_tree_add_uint(fh_tree, hf_off, tvb, 0, 0, pseudo_header->cosine.off);
proto_tree_add_uint(fh_tree, hf_pri, tvb, 0, 0, pseudo_header->cosine.pri);
proto_tree_add_uint(fh_tree, hf_rm, tvb, 0, 0, pseudo_header->cosine.rm);
proto_tree_add_uint(fh_tree, hf_err, tvb, 0, 0, pseudo_header->cosine.err);
switch (pseudo_header->cosine.encap) {
case COSINE_ENCAP_ETH:
break;
case COSINE_ENCAP_ATM:
case COSINE_ENCAP_PPoATM:
proto_tree_add_text(fh_tree, tvb, 0, 16, "SAR header");
break;
case COSINE_ENCAP_PPP:
case COSINE_ENCAP_FR:
case COSINE_ENCAP_PPoFR:
proto_tree_add_text(fh_tree, tvb, 0, 4, "Channel handle ID");
break;
case COSINE_ENCAP_HDLC:
if (pseudo_header->cosine.direction == COSINE_DIR_TX) {
proto_tree_add_text(fh_tree, tvb, 0, 2,
"Channel handle ID");
} else if (pseudo_header->cosine.direction == COSINE_DIR_RX) {
proto_tree_add_text(fh_tree, tvb, 0, 4,
"Channel handle ID");
}
break;
default:
break;
}
}
switch (pseudo_header->cosine.encap) {
case COSINE_ENCAP_ETH:
call_dissector(eth_withoutfcs_handle, tvb_new_subset_remaining(tvb, 0),
pinfo, tree);
break;
case COSINE_ENCAP_ATM:
case COSINE_ENCAP_PPoATM:
call_dissector(llc_handle, tvb_new_subset_remaining(tvb, 16),
pinfo, tree);
break;
case COSINE_ENCAP_PPP:
call_dissector(ppp_hdlc_handle, tvb_new_subset_remaining(tvb, 4),
pinfo, tree);
break;
case COSINE_ENCAP_HDLC:
if (pseudo_header->cosine.direction == COSINE_DIR_TX) {
call_dissector(chdlc_handle, tvb_new_subset_remaining(tvb, 2),
pinfo, tree);
} else if (pseudo_header->cosine.direction == COSINE_DIR_RX) {
call_dissector(chdlc_handle, tvb_new_subset_remaining(tvb, 4),
pinfo, tree);
}
break;
case COSINE_ENCAP_FR:
case COSINE_ENCAP_PPoFR:
call_dissector(fr_handle, tvb_new_subset_remaining(tvb, 4),
pinfo, tree);
break;
case COSINE_ENCAP_TEST:
case COSINE_ENCAP_UNKNOWN:
call_dissector(data_handle, tvb, pinfo, tree);
break;
default:
break;
}
}
void
proto_register_cosine(void)
{
static hf_register_info hf[] = {
{ &hf_pro,
{ "Protocol", "cosine.pro", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_off,
{ "Offset", "cosine.off", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_pri,
{ "Priority", "cosine.pri", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_rm,
{ "Rate Marking", "cosine.rm", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_err,
{ "Error Code", "cosine.err", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_raw,
};
proto_cosine = proto_register_protocol("CoSine IPNOS L2 debug output",
"CoSine", "cosine");
proto_register_field_array(proto_cosine, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cosine(void)
{
dissector_handle_t cosine_handle;
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
ppp_hdlc_handle = find_dissector("ppp_hdlc");
llc_handle = find_dissector("llc");
chdlc_handle = find_dissector("chdlc");
fr_handle = find_dissector("fr");
data_handle = find_dissector("data");
cosine_handle = create_dissector_handle(dissect_cosine, proto_cosine);
dissector_add_uint("wtap_encap", WTAP_ENCAP_COSINE, cosine_handle);
}
