static int dissect_bctp(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
proto_item* pi = proto_tree_add_item(tree, proto_bctp, tvb,0,2, ENC_NA);
proto_tree* pt = proto_item_add_subtree(pi,ett_bctp);
tvbuff_t* sub_tvb = tvb_new_subset_remaining(tvb, 2);
guint8 tpi = tvb_get_guint8(tvb,1) & 0x3f;
proto_tree_add_item(pt, hf_bctp_bvei, tvb,0,2, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_bctp_bvi, tvb,0,2, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_bctp_tpei, tvb,0,2, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_bctp_tpi, tvb,0,2, ENC_BIG_ENDIAN);
if (!dissector_try_uint(bctp_dissector_table, tpi, sub_tvb, pinfo, tree) ) {
if (tpi <= 0x22) {
call_data_dissector(sub_tvb, pinfo, tree);
} else {
call_dissector(text_handle,sub_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_bctp (void)
{
static hf_register_info hf[] = {
{&hf_bctp_bvei, {"BVEI", "bctp.bvei", FT_UINT16, BASE_HEX, VALS(bvei_vals), 0x4000, "BCTP Version Error Indicator", HFILL }},
{&hf_bctp_bvi, {"BVI", "bctp.bvi", FT_UINT16, BASE_HEX, NULL, 0x1F00, "BCTP Version Indicator", HFILL }},
{&hf_bctp_tpei, {"TPEI", "bctp.tpei", FT_UINT16, BASE_HEX, NULL, 0x0040, "Tunneled Protocol Error Indicator", HFILL }},
{&hf_bctp_tpi, {"TPI", "bctp.tpi", FT_UINT16, BASE_HEX, NULL, 0x003F, "Tunneled Protocol Indicator", HFILL }},
};
static gint *ett[] = {
&ett_bctp
};
proto_bctp = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_bctp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bctp", dissect_bctp, proto_bctp);
bctp_dissector_table = register_dissector_table("bctp.tpi", "BCTP Tunneled Protocol Indicator", proto_bctp, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_bctp(void)
{
text_handle = find_dissector_add_dependency("data-text-lines", proto_bctp);
}
