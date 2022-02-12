gchar *
dissect_e212_mcc_mnc_wmem_packet_str(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, e212_number_type_t number_type, gboolean little_endian)
{
int start_offset, mcc_mnc;
guint8 octet;
guint16 mcc, mnc;
guint8 mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
proto_item *item;
gchar *mcc_mnc_str;
gboolean long_mnc = FALSE;
int hf_E212_mcc_id, hf_E212_mnc_id;
switch(number_type){
case E212_LAI:
hf_E212_mcc_id = hf_E212_mcc_lai;
hf_E212_mnc_id = hf_E212_mnc_lai;
break;
case E212_RAI:
hf_E212_mcc_id = hf_E212_mcc_rai;
hf_E212_mnc_id = hf_E212_mnc_rai;
break;
case E212_SAI:
hf_E212_mcc_id = hf_E212_mcc_sai;
hf_E212_mnc_id = hf_E212_mnc_sai;
break;
case E212_CGI:
hf_E212_mcc_id = hf_E212_mcc_cgi;
hf_E212_mnc_id = hf_E212_mnc_cgi;
break;
case E212_ECGI:
hf_E212_mcc_id = hf_E212_mcc_ecgi;
hf_E212_mnc_id = hf_E212_mnc_ecgi;
break;
case E212_TAI:
hf_E212_mcc_id = hf_E212_mcc_tai;
hf_E212_mnc_id = hf_E212_mnc_tai;
break;
default:
hf_E212_mcc_id = hf_E212_mcc;
hf_E212_mnc_id = hf_E212_mnc;
}
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
item = proto_tree_add_uint(tree, hf_E212_mcc_id , tvb, start_offset, 2, mcc );
if (((mcc1 > 9) || (mcc2 > 9) || (mcc3 > 9)) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mcc_non_decimal);
if (long_mnc) {
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc_id , tvb, start_offset + 1, 2, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_3digits_codes_ext, "Unknown"),
mnc);
mcc_mnc_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %u %s, MNC %03u %s",
mcc,
val_to_str_ext_const(mcc,&E212_codes_ext,""),
mnc,
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_3digits_codes_ext, ""));
} else {
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc_id , tvb, start_offset + 1, 2, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext, "Unknown"),
mnc);
mcc_mnc_str = wmem_strdup_printf(wmem_packet_scope(), "MCC %u %s, MNC %02u %s",
mcc,
val_to_str_ext_const(mcc,&E212_codes_ext,""),
mnc,
val_to_str_ext_const(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext, ""));
}
if (((mnc1 > 9) || (mnc2 > 9) || ((mnc3 > 9) && (mnc3 != 0x0f))) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mnc_non_decimal);
return mcc_mnc_str;
}
int
dissect_e212_mcc_mnc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, e212_number_type_t number_type, gboolean little_endian)
{
dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, offset, number_type, little_endian);
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
if (!try_val_to_str_ext(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext)) {
mnc = 10 * mnc + mnc3;
long_mnc = TRUE;
}
item = proto_tree_add_uint(tree, hf_E212_mcc , tvb, start_offset, 2, mcc );
if (((mcc1 > 9) || (mcc2 > 9) || (mcc3 > 9)) & (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mcc_non_decimal);
if (long_mnc)
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_3digits_codes_ext, "Unknown"),
mnc);
else
item = proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 1, 2, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext, "Unknown"),
mnc);
if (((mnc1 > 9) || (mnc2 > 9) || (long_mnc && (mnc3 > 9))) && (mcc_mnc != 0xffffff))
expert_add_info(pinfo, item, &ei_E212_mnc_non_decimal);
if (long_mnc)
return 6;
else
return 5;
}
static int
dissect_e212_mcc_mnc_high_nibble(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 start_offset;
guint8 octet;
guint16 mcc, mnc;
guint8 mcc1, mcc2, mcc3, mnc1, mnc2, mnc3;
gboolean long_mnc;
long_mnc = FALSE;
start_offset = offset;
octet = tvb_get_guint8(tvb,offset);
mcc1 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mcc2 = octet & 0x0f;
mcc3 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mnc1 = octet & 0x0f;
mnc2 = octet >> 4;
offset++;
octet = tvb_get_guint8(tvb,offset);
mnc3 = octet & 0x0f;
mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
mnc = 10 * mnc1 + mnc2;
if (!try_val_to_str_ext(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext)) {
mnc = 10 * mnc + mnc3;
long_mnc = TRUE;
}
proto_tree_add_uint(tree, hf_E212_mcc , tvb, start_offset, 2, mcc );
if (long_mnc)
proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 2, 2, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_3digits_codes_ext, "Unknown"),
mnc);
else
proto_tree_add_uint_format_value(tree, hf_E212_mnc , tvb, start_offset + 2, 1, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext, "Unknown"),
mnc);
if (long_mnc)
return 7;
else
return 5;
}
int
dissect_e212_mcc_mnc_in_utf8_address(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint16 mcc = 0, mnc = 0;
gboolean long_mnc = FALSE;
ws_strtou16(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 3, ENC_UTF_8),
NULL, &mcc);
ws_strtou16(tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 3, 2, ENC_UTF_8),
NULL, &mnc);
if (!try_val_to_str_ext(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext)) {
ws_strtou16(tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 3, 3, ENC_UTF_8),
NULL, &mnc);
long_mnc = TRUE;
}
proto_tree_add_uint(tree, hf_E212_mcc, tvb, offset, 3, mcc );
if (long_mnc)
proto_tree_add_uint_format_value(tree, hf_E212_mnc, tvb, offset + 3, 3, mnc,
"%s (%03u)",
val_to_str_ext_const(mcc * 1000 + mnc, &mcc_mnc_3digits_codes_ext, "Unknown1"),
mnc);
else
proto_tree_add_uint_format_value(tree, hf_E212_mnc, tvb, offset + 3, 2, mnc,
"%s (%02u)",
val_to_str_ext_const(mcc * 100 + mnc, &mcc_mnc_2digits_codes_ext, "Unknown2"),
mnc);
if (long_mnc)
return 6;
else
return 5;
}
const gchar *
dissect_e212_imsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length, gboolean skip_first)
{
proto_item *item;
proto_tree *subtree;
const gchar *imsi_str;
imsi_str = tvb_bcd_dig_to_wmem_packet_str( tvb, offset, length, NULL, skip_first);
item = proto_tree_add_string(tree, hf_E212_imsi, tvb, offset, length, imsi_str);
subtree = proto_item_add_subtree(item, ett_e212_imsi);
if(skip_first) {
dissect_e212_mcc_mnc_high_nibble(tvb, pinfo, subtree, offset);
} else {
dissect_e212_mcc_mnc_in_address(tvb, pinfo, subtree, offset);
}
return imsi_str;
}
const gchar *
dissect_e212_utf8_imsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length)
{
proto_item *item;
proto_tree *subtree;
const gchar *imsi_str;
imsi_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_UTF_8);
item = proto_tree_add_string(tree, hf_E212_imsi, tvb, offset, length, imsi_str);
subtree = proto_item_add_subtree(item, ett_e212_imsi);
dissect_e212_mcc_mnc_in_utf8_address(tvb, pinfo, subtree, offset);
return imsi_str;
}
void
proto_register_e212(void)
{
static hf_register_info hf[] = {
{ &hf_E212_imsi,
{ "IMSI","e212.imsi",
FT_STRING, BASE_NONE, NULL, 0x0,
"International mobile subscriber identity(IMSI)", HFILL }
},
{ &hf_E212_mcc,
{ "Mobile Country Code (MCC)","e212.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_lai,
{ "Mobile Country Code (MCC)","e212.lai.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_rai,
{ "Mobile Country Code (MCC)","e212.rai.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_sai,
{ "Mobile Country Code (MCC)","e212.sai.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_cgi,
{ "Mobile Country Code (MCC)","e212.cgi.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_ecgi,
{ "Mobile Country Code (MCC)","e212.ecgi.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mcc_tai,
{ "Mobile Country Code (MCC)","e212.tai.mcc",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E212_codes_ext, 0x0,
"Mobile Country Code MCC", HFILL }
},
{ &hf_E212_mnc,
{ "Mobile Network Code (MNC)","e212.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_lai,
{ "Mobile Network Code (MNC)","e212.lai.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_rai,
{ "Mobile Network Code (MNC)","e212.rai.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_sai,
{ "Mobile Network Code (MNC)","e212.sai.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_cgi,
{ "Mobile Network Code (MNC)","e212.cgi.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_ecgi,
{ "Mobile Network Code (MNC)","e212.ecgi.mnc",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mobile network code", HFILL }
},
{ &hf_E212_mnc_tai,
{ "Mobile Network Code (MNC)","e212.tai.mnc",
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
static gint *ett_e212_array[] = {
&ett_e212_imsi,
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
proto_register_subtree_array(ett_e212_array, array_length(ett_e212_array));
expert_e212 = expert_register_protocol(proto_e212);
expert_register_field_array(expert_e212, ei, array_length(ei));
}
