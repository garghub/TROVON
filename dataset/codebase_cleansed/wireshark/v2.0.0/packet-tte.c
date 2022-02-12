static int
dissect_tte(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int is_frame_pcf;
ethertype_data_t ethertype_data;
proto_item *tte_root_item, *tte_macdest_item;
proto_tree *tte_tree, *tte_macdest_tree;
if (tvb_reported_length(tvb) < TTE_HEADER_LENGTH)
return 0;
is_frame_pcf =
(tvb_get_ntohs(tvb, TTE_MAC_LENGTH * 2) == ETHERTYPE_TTE_PCF);
if (!is_frame_pcf)
{
if ( (tvb_get_ntohl(tvb, 0) & tte_pref_ct_mask) != tte_pref_ct_marker)
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TTE ");
if (tvb_get_ntohs(tvb, TTE_MAC_LENGTH * 2) <= IEEE_802_3_MAX_LEN)
{
col_set_str(pinfo->cinfo, COL_INFO, "TTEthernet Frame");
}
else
{
col_set_str(pinfo->cinfo, COL_INFO, "Bogus TTEthernet Frame");
}
if (tree) {
tte_root_item = proto_tree_add_item(tree, proto_tte, tvb, 0,
TTE_HEADER_LENGTH, ENC_NA);
tte_tree = proto_item_add_subtree(tte_root_item, ett_tte);
tte_macdest_item = proto_tree_add_item(tte_tree,
hf_eth_dst, tvb, 0, TTE_MAC_LENGTH, ENC_NA);
proto_tree_add_item(tte_tree,
hf_eth_src, tvb, TTE_MAC_LENGTH, TTE_MAC_LENGTH, ENC_NA);
proto_tree_add_item(tte_tree,
hf_eth_type, tvb, TTE_MAC_LENGTH*2, TTE_ETHERTYPE_LENGTH,
ENC_BIG_ENDIAN);
tte_macdest_tree = proto_item_add_subtree(tte_macdest_item,
ett_tte_macdest);
proto_tree_add_item(tte_macdest_tree,
hf_tte_dst_cf, tvb, 0, TTE_MACDEST_CF_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(tte_macdest_tree,
hf_tte_ctid, tvb, TTE_MACDEST_CF_LENGTH,
TTE_MACDEST_CTID_LENGTH, ENC_BIG_ENDIAN);
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
ethertype_data.etype = tvb_get_ntohs(tvb, TTE_MAC_LENGTH * 2);
ethertype_data.offset_after_ethertype = 14;
ethertype_data.fh_tree = NULL;
ethertype_data.etype_id = hf_eth_type;
ethertype_data.trailer_id = 0;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
return tvb_reported_length(tvb);
}
void
proto_register_tte(void)
{
module_t *tte_module;
static hf_register_info hf[] = {
{ &hf_tte_dst_cf,
{ "Constant Field", "tte.cf",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tte_ctid,
{ "Critical Traffic Identifier", "tte.ctid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_tte,
&ett_tte_macdest
};
proto_tte = proto_register_protocol("TTEthernet", "TTE", "tte");
proto_register_field_array(proto_tte, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tte_module = prefs_register_protocol(proto_tte, NULL);
prefs_register_uint_preference(tte_module, "ct_mask_value",
"CT Mask (in hex)",
"Critical Traffic Mask (base hex)",
16, &tte_pref_ct_mask);
prefs_register_uint_preference(tte_module, "ct_marker_value",
"CT Marker (in hex)",
"Critical Traffic Marker (base hex)",
16, &tte_pref_ct_marker);
}
void
proto_reg_handoff_tte(void)
{
heur_dissector_add("eth", dissect_tte, "TTEthernet", "tte_eth", proto_tte, HEURISTIC_ENABLE);
hf_eth_dst = proto_registrar_get_id_byname ("eth.dst");
hf_eth_src = proto_registrar_get_id_byname ("eth.src");
hf_eth_type = proto_registrar_get_id_byname ("eth.type");
ethertype_handle = find_dissector("ethertype");
}
