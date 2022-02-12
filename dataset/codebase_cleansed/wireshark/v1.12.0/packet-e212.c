gchar *
dissect_e212_mcc_mnc_wmem_packet_str(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean little_endian)
{
int start_offset, mcc_mnc;
guint8 octet;
guint16 mcc, mnc;
guint8 mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
proto_item *item;
gchar *mcc_mnc_str;
gboolean long_mnc = FALSE;
start_offset = offset;
mcc_mnc = tvb_get_ntoh24(tvb,offset);
octet = tvb_get_guint8(tvb,offset);
mcc1 = octet & 0x0f;
mcc2 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mcc3 = octet & 0x0f;
mnc3 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mnc1 = octet & 0x0f;
mnc2 = octet >> 4;
mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
mnc = 10 * mnc1 + mnc2;
if ((mnc3 != 0xf) || (mcc_mnc == 0xffffff)) {
long_mnc = TRUE;
if(little_endian)
mnc = 10 * mnc + mnc3;
else
mnc = 100 * mnc3 + mnc;
}
item = proto_tree_add_uint(tree, hf_E212_mcc , tvb, start_offset, 2, mcc );
if (((mcc1 > 9) || (mcc2 > 9) || (mcc3 > 9)) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mcc_non_decimal);
if (long_mnc) {
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_codes_ext, "Unknown"),
mnc);
mcc_mnc_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %u %s, MNC %03u %s",
mcc,
val_to_str_ext_const(mcc,&E212_codes_ext,""),
mnc,
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_codes_ext, ""));
} else {
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 1000 + 10 * mnc, &mcc_mnc_codes_ext, "Unknown"),
mnc);
mcc_mnc_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %u %s, MNC %02u %s",
mcc,
val_to_str_ext_const(mcc,&E212_codes_ext,""),
mnc,
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_codes_ext, ""));
}
if (((mnc1 > 9) || (mnc2 > 9) || ((mnc3 > 9) && (mnc3 != 0x0f))) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mnc_non_decimal);
return mcc_mnc_str;
}
int
dissect_e212_mcc_mnc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean little_endian)
{
dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, little_endian);
return offset +3;
}
int
dissect_e212_mcc_mnc_in_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 start_offset, mcc_mnc;
guint8 octet;
guint16 mcc, mnc;
guint8 mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
proto_item *item;
gboolean long_mnc;
long_mnc = FALSE;
start_offset = offset;
mcc_mnc = tvb_get_ntoh24(tvb,offset);
octet = tvb_get_guint8(tvb,offset);
mcc1 = octet & 0x0f;
mcc2 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mcc3 = octet & 0x0f;
mnc1 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mnc2 = octet & 0x0f;
mnc3 = octet >> 4;
mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
mnc = 10 * mnc1 + mnc2;
if (!try_val_to_str_ext(mcc * 1000 + 10 * mnc, &mcc_mnc_codes_ext)) {
mnc = 10 * mnc + mnc3;
long_mnc = TRUE;
}
item = proto_tree_add_uint(tree, hf_E212_mcc , tvb, start_offset, 2, mcc );
if (((mcc1 > 9) || (mcc2 > 9) || (mcc3 > 9)) & (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mcc_non_decimal);
if (long_mnc)
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_codes_ext, "Unknown"),
mnc);
else
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 1000 + 10 * mnc, &mcc_mnc_codes_ext, "Unknown"),
mnc);
if (((mnc1 > 9) || (mnc2 > 9) || (long_mnc && (mnc3 > 9))) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mnc_non_decimal);
if (long_mnc)
return 6;
else
return 5;
}
void
proto_register_e212(void)
{
static hf_register_info hf[] = {
{ &hf_E212_mcc,
{ "Mobile Country Code (MCC)","e212.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mnc,
{ "Mobile Network Code (MNC)","e212.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
#if 0
{ &hf_E212_msin,
{ "Mobile Subscriber Identification Number (MSIN)", "e212.msin",
FT_STRING, BASE_NONE, NULL, 0,
"Mobile Subscriber Identification Number(MSIN)", HFILL }},
#endif
};
static ei_register_info ei[] = {
{ &ei_E212_mcc_non_decimal, { "e212.mcc.non_decimal", PI_MALFORMED, PI_WARN, "MCC contains non-decimal digits", EXPFILL }},
{ &ei_E212_mnc_non_decimal, { "e212.mnc.non_decimal", PI_MALFORMED, PI_WARN, "MNC contains non-decimal digits", EXPFILL }},
};
expert_module_t* expert_e212;
proto_e212 = proto_register_protocol(
"ITU-T E.212 number",
"E.212",
"e212");
proto_register_field_array(proto_e212, hf, array_length(hf));
expert_e212 = expert_register_protocol(proto_e212);
expert_register_field_array(expert_e212, ei, array_length(ei));
}
