static void gfp_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "UPI %u as",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_gfp, 0)));
}
static gpointer gfp_value(packet_info *pinfo)
{
return p_get_proto_data(pinfo->pool, pinfo, proto_gfp, 0);
}
static void
gfp_add_hec_tree(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint *offset, const guint len, const int field, const int field_good, const int field_bad, const gint ett, expert_field *ei_bad)
{
proto_item* ti = NULL;
proto_tree* hec_tree = NULL;
guint hec, hec_calc;
hec_calc = crc16_r3_ccitt_tvb(tvb, *offset, len);
*offset += len;
hec = tvb_get_ntohs(tvb, *offset);
if ( hec == hec_calc ) {
ti = proto_tree_add_uint_format_value(tree, field, tvb, *offset, 2, hec, "0x%04x [correct]", hec);
hec_tree = proto_item_add_subtree(ti, ett);
ti = proto_tree_add_boolean(hec_tree, field_good, tvb, *offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(hec_tree, field_bad, tvb, *offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
} else {
ti = proto_tree_add_uint_format_value(tree, field, tvb, *offset, 2, hec, "0x%04x [incorrect, should be 0x%04x]", hec, hec_calc);
hec_tree = proto_item_add_subtree(ti, ett);
ti = proto_tree_add_boolean(hec_tree, field_good, tvb, *offset, 2, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(hec_tree, field_bad, tvb, *offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info(pinfo, ti, ei_bad);
}
*offset += 2;
}
static void
dissect_gfp_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *gfp_tree, guint *offset, guint payload_len)
{
tvbuff_t *payload_tvb;
proto_item *type_ti = NULL;
proto_item *fcs_ti;
proto_tree *fcs_tree = NULL;
guint pti, pfi, exi, upi;
guint fcs, fcs_calc;
guint fcs_len = 0;
tvb_ensure_bytes_exist(tvb, *offset, 4);
payload_len -= 4;
pti = tvb_get_bits8(tvb, 8*(*offset), 3);
pfi = tvb_get_bits8(tvb, 8*(*offset)+3, 1);
exi = tvb_get_bits8(tvb, 8*(*offset)+4, 4);
upi = tvb_get_guint8(tvb, *offset+1);
p_add_proto_data(pinfo->pool, pinfo, proto_gfp, 0, GUINT_TO_POINTER(upi));
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(pti, gfp_pti_vals, "Reserved PTI (%d)"));
if (pti == GFP_USER_DATA ||
pti == GFP_MANAGEMENT_COMMUNICATIONS) {
type_ti = proto_tree_add_bitmask_with_flags(gfp_tree, tvb, *offset, hf_gfp_type,
ett_gfp_type, gfp_type_data_fields, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
col_append_sep_str(pinfo->cinfo, COL_INFO, ": ", rval_to_str(upi, gfp_upi_data_rvals, "Unknown 0x%02x"));
} else if (pti == GFP_CLIENT_MANAGEMENT) {
type_ti = proto_tree_add_bitmask_with_flags(gfp_tree, tvb, *offset, hf_gfp_type,
ett_gfp_type, gfp_type_management_fields, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
col_append_sep_str(pinfo->cinfo, COL_INFO, ": ", rval_to_str(upi, gfp_upi_management_rvals, "Unknown 0x%02x"));
}
gfp_add_hec_tree(tvb, pinfo, gfp_tree, offset, 2, hf_gfp_thec, hf_gfp_thec_good, hf_gfp_thec_bad, ett_gfp_thec, &ei_gfp_thec_bad);
switch (exi) {
case GFP_EXT_NULL:
break;
case GFP_EXT_LINEAR:
if (payload_len < 4) {
expert_add_info(pinfo, type_ti, &ei_gfp_exi_short);
payload_len = 0;
}
else {
payload_len -= 4;
}
proto_tree_add_item(gfp_tree, hf_gfp_cid, tvb, *offset, 1, ENC_BIG_ENDIAN);
gfp_add_hec_tree(tvb, pinfo, gfp_tree, offset, 2, hf_gfp_ehec, hf_gfp_ehec_good, hf_gfp_ehec_bad, ett_gfp_ehec, &ei_gfp_ehec_bad);
break;
case GFP_EXT_RING:
default:
break;
}
proto_item_set_end(gfp_tree, tvb, *offset);
if (pfi == 1) {
if (payload_len < 4) {
expert_add_info(pinfo, type_ti, &ei_gfp_pfi_short);
fcs_len = payload_len;
payload_len = 0;
} else {
fcs_len = 4;
payload_len -= 4;
}
proto_tree_set_appendix(gfp_tree, tvb, *offset + payload_len, fcs_len);
fcs = tvb_get_ntohl(tvb, *offset + payload_len);
fcs_calc = crc32_mpeg2_tvb_offset(tvb, *offset, payload_len);
if (fcs == ~fcs_calc) {
fcs_ti = proto_tree_add_uint_format_value(gfp_tree, hf_gfp_fcs, tvb, *offset+payload_len, 4, fcs, "0x%08x [correct]", fcs);
fcs_tree = proto_item_add_subtree(fcs_ti, ett_gfp_fcs);
fcs_ti = proto_tree_add_boolean(fcs_tree, hf_gfp_fcs_good, tvb, *offset+payload_len, 4, TRUE);
PROTO_ITEM_SET_GENERATED(fcs_ti);
fcs_ti = proto_tree_add_boolean(fcs_tree, hf_gfp_fcs_bad, tvb, *offset+payload_len, 4, FALSE);
PROTO_ITEM_SET_GENERATED(fcs_ti);
} else {
fcs_ti = proto_tree_add_uint_format_value(gfp_tree, hf_gfp_fcs, tvb, *offset+payload_len, 4, fcs, "0x%08x [incorrect, should be 0x%08x]", fcs, fcs_calc);
fcs_tree = proto_item_add_subtree(fcs_ti, ett_gfp_fcs);
fcs_ti = proto_tree_add_boolean(fcs_tree, hf_gfp_fcs_good, tvb, *offset+payload_len, 4, FALSE);
PROTO_ITEM_SET_GENERATED(fcs_ti);
fcs_ti = proto_tree_add_boolean(fcs_tree, hf_gfp_fcs_bad, tvb, *offset+payload_len, 4, TRUE);
PROTO_ITEM_SET_GENERATED(fcs_ti);
expert_add_info(pinfo, fcs_ti, &ei_gfp_fcs_bad);
}
}
payload_tvb = tvb_new_subset_length(tvb, *offset, payload_len);
switch (pti) {
case GFP_USER_DATA:
case GFP_MANAGEMENT_COMMUNICATIONS:
if (!dissector_try_uint(gfp_dissector_table, upi, payload_tvb, pinfo, tree)) {
expert_add_info_format(pinfo, type_ti, &ei_gfp_payload_undecoded, "Payload type 0x%02x (%s) unsupported", upi, rval_to_str_const(upi, gfp_upi_data_rvals, "UNKNOWN"));
call_data_dissector(payload_tvb, pinfo, tree);
}
break;
case GFP_CLIENT_MANAGEMENT:
call_data_dissector(payload_tvb, pinfo, tree);
break;
default:
break;
}
*offset += payload_len;
*offset += fcs_len;
}
static int
dissect_gfp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *pli_ti;
proto_tree *gfp_tree;
guint offset = 0;
int len = 0;
guint pli;
if (tvb_reported_length(tvb) < GFP_MIN_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GFP");
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
ti = proto_tree_add_item(tree, proto_gfp, tvb, 0, GFP_MIN_LENGTH, ENC_NA);
gfp_tree = proto_item_add_subtree(ti, ett_gfp);
len = 2;
pli_ti = proto_tree_add_item_ret_uint(gfp_tree, hf_gfp_pli, tvb,
offset, len, ENC_BIG_ENDIAN, &pli);
if (pli < 4) {
proto_item_append_text(pli_ti, " (%s)", rval_to_str_const(pli, gfp_pli_rvals, "Unknown"));
}
col_set_str(pinfo->cinfo, COL_INFO, rval_to_str_const(pli, gfp_pli_rvals, "Unknown"));
gfp_add_hec_tree(tvb, pinfo, gfp_tree, &offset, len, hf_gfp_chec, hf_gfp_chec_good, hf_gfp_chec_bad, ett_gfp_chec, &ei_gfp_chec_bad);
if (pli == 0) {
if (tvb_reported_length_remaining(tvb, offset)) {
expert_add_info(pinfo, pli_ti, &ei_gfp_pli_idle_nonempty);
}
} else if (pli < 4) {
expert_add_info(pinfo, pli_ti, &ei_gfp_pli_unknown);
} else {
if (tvb_reported_length(tvb) < pli + offset) {
proto_item_append_text(pli_ti, " (invalid, reported length is %u)", tvb_reported_length_remaining(tvb, offset));
expert_add_info(pinfo, pli_ti, &ei_gfp_pli_invalid);
}
dissect_gfp_payload(tvb, pinfo, tree, gfp_tree, &offset, pli);
}
return offset;
}
void
proto_register_gfp(void)
{
static hf_register_info hf[] = {
{ &hf_gfp_pli,
{ "Payload Length Indicator", "gfp.pli", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_gfp_chec,
{ "Core HEC", "gfp.chec", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_gfp_chec_good,
{ "Good cHEC", "gfp.chec_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: cHEC matches core header; False: doesn't match", HFILL }
},
{ &hf_gfp_chec_bad,
{ "Bad cHEC", "gfp.chec_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: cHEC doesn't match core header; False: matches", HFILL }
},
{ &hf_gfp_type,
{ "Type Field", "gfp.type", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gfp_pti,
{ "PTI", "gfp.pti", FT_UINT16, BASE_HEX, VALS(gfp_pti_vals),
0xE000, "Payload Type Identifier", HFILL }
},
{ &hf_gfp_pfi,
{ "PFI", "gfp.pfi", FT_BOOLEAN, 16, TFS(&tfs_present_absent),
0x1000, "Payload FCS Indicator", HFILL }
},
{ &hf_gfp_exi,
{ "EXI", "gfp.exi", FT_UINT16, BASE_HEX, VALS(gfp_exi_vals),
0x0F00, "Extension Header Identifier", HFILL }
},
{ &hf_gfp_upi_data,
{ "UPI", "gfp.upi", FT_UINT16, BASE_HEX|BASE_RANGE_STRING,
RVALS(gfp_upi_data_rvals),
0xFF, "User Payload Identifier for Client Data Frame (or Management Communications Frame)", HFILL }
},
{ &hf_gfp_upi_management,
{ "UPI", "gfp.upi", FT_UINT16, BASE_HEX|BASE_RANGE_STRING,
RVALS(gfp_upi_management_rvals),
0xFF, "User Payload Identifier for Client Management Frame", HFILL }
},
{ &hf_gfp_thec,
{ "Type HEC", "gfp.thec", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gfp_thec_good,
{ "Good tHEC", "gfp.thec_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: tHEC matches type header; False: doesn't match", HFILL }
},
{ &hf_gfp_thec_bad,
{ "Bad tHEC", "gfp.thec_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: tHEC doesn't match type header; False: matches", HFILL }
},
{ &hf_gfp_cid,
{ "Channel ID", "gfp.cid", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gfp_ehec,
{ "Extension HEC", "gfp.ehec", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gfp_ehec_good,
{ "Good eHEC", "gfp.ehec_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: eHEC matches extension header; False: doesn't match", HFILL }
},
{ &hf_gfp_ehec_bad,
{ "Bad eHEC", "gfp.ehec_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: eHEC doesn't match extension header; False: matches", HFILL }
},
{ &hf_gfp_fcs,
{ "Payload FCS", "gfp.fcs", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gfp_fcs_good,
{ "Good FCS", "gfp.fcs_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: FCS matches payload; False: doesn't match", HFILL }
},
{ &hf_gfp_fcs_bad,
{ "Bad eHEC", "gfp.fcs_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: FCS doesn't match payload; False: matches", HFILL }
}
};
static gint *ett[] = {
&ett_gfp,
&ett_gfp_chec,
&ett_gfp_type,
&ett_gfp_thec,
&ett_gfp_ehec,
&ett_gfp_fcs
};
static ei_register_info ei[] = {
{ &ei_gfp_pli_idle_nonempty,
{ "gfp.pli.idle.nonempty", PI_MALFORMED, PI_ERROR,
"Payload present on idle frame", EXPFILL }
},
{ &ei_gfp_pli_unknown,
{ "gfp.pli.unknown", PI_UNDECODED, PI_WARN,
"Unknown control frame type", EXPFILL }
},
{ &ei_gfp_pli_invalid,
{ "gfp.pli.invalid", PI_MALFORMED, PI_WARN,
"Bogus PLI does not match reported length", EXPFILL }
},
{ &ei_gfp_chec_bad,
{ "gfp.chec.bad", PI_CHECKSUM, PI_WARN,
"Bad cHEC", EXPFILL }
},
{ &ei_gfp_thec_bad,
{ "gfp.thec.bad", PI_CHECKSUM, PI_WARN,
"Bad tHEC", EXPFILL }
},
{ &ei_gfp_ehec_bad,
{ "gfp.ehec.bad", PI_CHECKSUM, PI_WARN,
"Bad eHEC", EXPFILL }
},
{ &ei_gfp_exi_short,
{ "gfp.exi.missing", PI_MALFORMED, PI_ERROR,
"EXI bit set but PLI too short for extension header", EXPFILL}
},
{ &ei_gfp_pfi_short,
{ "gfp.pfi.missing", PI_MALFORMED, PI_ERROR,
"PFI bit set but PLI too short for payload FCS", EXPFILL}
},
{ &ei_gfp_payload_undecoded,
{ "gfp.payload.undecoded", PI_UNDECODED, PI_WARN,
"Payload type not supported yet by the dissector", EXPFILL}
},
{ &ei_gfp_fcs_bad,
{ "gfp.fcs.bad", PI_CHECKSUM, PI_WARN,
"Bad FCS", EXPFILL }
}
};
static build_valid_func gfp_da_build_value[1] = {gfp_value};
static decode_as_value_t gfp_da_values = {gfp_prompt, 1, gfp_da_build_value};
static decode_as_t gfp_da = {"gfp", "GFP", "gfp.upi", 1, 0, &gfp_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
expert_module_t *expert_gfp;
proto_gfp = proto_register_protocol("Generic Framing Procedure",
"GFP", "gfp");
proto_register_field_array(proto_gfp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gfp = expert_register_protocol(proto_gfp);
expert_register_field_array(expert_gfp, ei, array_length(ei));
gfp_dissector_table = register_dissector_table("gfp.upi", "GFP UPI (for Client Data frames)",
proto_gfp, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_decode_as(&gfp_da);
}
void
proto_reg_handoff_gfp(void)
{
static dissector_handle_t gfp_handle;
gfp_handle = create_dissector_handle(dissect_gfp,
proto_gfp);
dissector_add_uint("wtap_encap", WTAP_ENCAP_GFP_T, gfp_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_GFP_F, gfp_handle);
dissector_add_uint("gfp.upi", 1, find_dissector("eth_withfcs"));
dissector_add_uint("gfp.upi", 2, find_dissector("ppp_hdlc"));
dissector_add_uint("gfp.upi", 12, find_dissector("mpls"));
dissector_add_uint("gfp.upi", 13, find_dissector("mpls"));
dissector_add_uint("gfp.upi", 16, find_dissector("ip"));
dissector_add_uint("gfp.upi", 17, find_dissector("ipv6"));
}
