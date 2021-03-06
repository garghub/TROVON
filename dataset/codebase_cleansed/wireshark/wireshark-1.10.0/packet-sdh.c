static int
get_sdh_level(tvbuff_t *tvb, packet_info *pinfo)
{
if(sdh_data_rate != -1) return sdh_data_rate;
switch((pinfo->pseudo_header->erf.ehdr_list[0].ehdr & 0xff00) >> 8){
case 1:
return 1;
case 2:
return 4;
case 3:
return 16;
default:
;
}
switch(tvb_reported_length(tvb)){
case 2430:
return 1;
case 9720:
return 4;
case 19440:
return 8;
case 38880:
return 16;
}
return 1;
}
static void
dissect_sdh(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SDH");
col_clear(pinfo->cinfo,COL_INFO);
if (tree) {
proto_tree *sdh_tree;
proto_item *sdh_item;
int level = get_sdh_level(tvb, pinfo);
guint8 h1;
guint8 h2;
guint16 au;
sdh_item = proto_tree_add_protocol_format(tree, proto_sdh, tvb, 0, -1, "SDH");
sdh_tree = proto_item_add_subtree(sdh_item, ett_sdh);
h1 = tvb_get_guint8(tvb, 0+(3*level*COLUMNS));
h2 = tvb_get_guint8(tvb, 3+(3*level*COLUMNS));
au = (h2 | ((0x03 & h1) << 8));
proto_tree_add_item(sdh_tree, hf_sdh_a1, tvb, 0, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_a2, tvb, 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_j0, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_b1, tvb, 0+(1*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_e1, tvb, 3+(1*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_f1, tvb, 6+(1*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d1, tvb, 0+(2*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d2, tvb, 3+(2*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d3, tvb, 6+(2*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_h1, tvb, 0+(3*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_h2, tvb, 3+(3*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(sdh_tree, hf_sdh_au, tvb, 0+(3*level*COLUMNS), 4, au);
proto_tree_add_item(sdh_tree, hf_sdh_b2, tvb, 0+(4*level*COLUMNS), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_k1, tvb, 3+(4*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_k2, tvb, 6+(4*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d4, tvb, 0+(5*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d5, tvb, 3+(5*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d6, tvb, 6+(5*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d7, tvb, 0+(6*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d8, tvb, 3+(6*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d9, tvb, 6+(6*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d10, tvb, 0+(7*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d11, tvb, 3+(7*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_d12, tvb, 6+(7*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_s1, tvb, 0+(8*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_m1, tvb, 5+(8*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_e2, tvb, 6+(7*level*COLUMNS), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sdh_tree, hf_sdh_j1, tvb, au, 1, ENC_BIG_ENDIAN);
}
}
void
proto_register_sdh(void)
{
static hf_register_info hf[] = {
{ &hf_sdh_a1,
{ "A1", "sdh.a1", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_a2,
{ "A2", "sdh.a2", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_j0,
{ "J0", "sdh.j0", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_b1,
{ "B1", "sdh.b1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_e1,
{ "E1", "sdh.e1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_f1,
{ "F1", "sdh.f1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d1,
{ "D1", "sdh.d1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d2,
{ "D2", "sdh.d2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d3,
{ "D3", "sdh.d3", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_au,
{ "AU", "sdh.au", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_b2,
{ "B2", "sdh.b2", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_k1,
{ "K1", "sdh.k1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_k2,
{ "K2", "sdh.k2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d4,
{ "D4", "sdh.d4", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d5,
{ "D5", "sdh.d5", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d6,
{ "D6", "sdh.d6", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d7,
{ "D7", "sdh.d7", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d8,
{ "D8", "sdh.d8", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d9,
{ "D9", "sdh.d9", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d10,
{ "D10", "sdh.d10", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d11,
{ "D11", "sdh.d11", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_d12,
{ "D12", "sdh.d12", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_s1,
{ "S1", "sdh.s1", FT_UINT8, BASE_HEX, VALS(sdh_s1_vals), 0x0, NULL, HFILL }},
{ &hf_sdh_m1,
{ "M1", "sdh.m1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_e2,
{ "E2", "sdh.e2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_j1,
{ "J1", "sdh.j1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_h1,
{ "H1", "sdh.h1", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sdh_h2,
{ "H2", "sdh.h2", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_sdh,
};
module_t *sdh_module;
proto_sdh = proto_register_protocol("SDH/SONET Protocol", "SDH", "sdh");
proto_register_field_array(proto_sdh, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sdh_module = prefs_register_protocol(proto_sdh, NULL);
prefs_register_enum_preference(sdh_module, "data.rate",
"Data rate",
"Data rate",
&sdh_data_rate, data_rates, ENC_BIG_ENDIAN);
register_dissector("sdh", dissect_sdh, proto_sdh);
}
void
proto_reg_handoff_sdh(void)
{
dissector_handle_t sdh_handle;
sdh_handle = find_dissector("sdh");
dissector_add_uint("wtap_encap", WTAP_ENCAP_SDH, sdh_handle);
data_handle = find_dissector("data");
}
