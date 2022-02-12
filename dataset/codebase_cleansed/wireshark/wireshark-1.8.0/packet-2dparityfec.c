static void dissect_2dparityfec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 OffsetField;
guint8 NAField;
guint32 SNBase;
guint8 D;
SNBase = (guint32)tvb_get_guint8(tvb, 0)<<8;
SNBase |= (guint32)tvb_get_guint8(tvb, 1);
SNBase |= (guint32)tvb_get_guint8(tvb, 15)<<16;
D = (tvb_get_guint8(tvb, 12)>>6) & 0x1;
OffsetField = tvb_get_guint8(tvb, 13);
NAField = tvb_get_guint8(tvb, 14);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "2dFEC");
if(D)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Row FEC - SNBase=%u, Offset=%u, NA=%u",
SNBase, OffsetField, NAField);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Column FEC - SNBase=%u, Offset=%u, NA=%u",
SNBase, OffsetField, NAField);
}
if(tree)
{
proto_item *ti = NULL;
proto_tree *tree_2dparityfec = NULL;
gint offset = 0;
ti = proto_tree_add_item(tree, proto_2dparityfec, tvb, 0, -1, ENC_NA);
tree_2dparityfec = proto_item_add_subtree(ti, ett_2dparityfec);
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_snbase_low, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_length_recovery, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_rfc2733_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_pt_recovery, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_mask, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_ts_recovery, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_ts_pro_mpeg_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_row_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_index, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_offset, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_na, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_snbase_ext, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, hf_2dparityfec_payload, tvb, offset, -1, ENC_NA);
}
}
void proto_register_2dparityfec(void)
{
module_t *module_2dparityfec;
static hf_register_info hf[] = {
{&hf_2dparityfec_snbase_low,
{ "SNBase low",
"2dparityfec.snbase_low",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_length_recovery,
{ "Length recovery",
"2dparityfec.lr",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_rfc2733_ext,
{ "RFC2733 Extension (E)",
"2dparityfec.e",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL,
HFILL} },
{&hf_2dparityfec_pt_recovery,
{ "Payload Type recovery",
"2dparityfec.ptr",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL,
HFILL} },
{&hf_2dparityfec_mask,
{ "Mask",
"2dparityfec.mask",
FT_UINT24,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_ts_recovery,
{ "Timestamp recovery",
"2dparityfec.tsr",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_ts_pro_mpeg_ext,
{ "Pro-MPEG Extension (X)",
"2dparityfec.x",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL,
HFILL} },
{&hf_2dparityfec_row_flag,
{ "Row FEC (D)",
"2dparityfec.d",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL,
HFILL} },
{&hf_2dparityfec_type,
{ "Type",
"2dparityfec.type",
FT_UINT8,
BASE_DEC,
VALS(fec_type_names),
0x38,
NULL,
HFILL} },
{&hf_2dparityfec_index,
{ "Index",
"2dparityfec.index",
FT_UINT8,
BASE_DEC,
NULL,
0x07,
NULL,
HFILL} },
{&hf_2dparityfec_offset,
{ "Offset",
"2dparityfec.offset",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_na,
{ "NA",
"2dparityfec.na",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_snbase_ext,
{ "SNBase ext",
"2dparityfec.snbase_ext",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL} },
{&hf_2dparityfec_payload,
{ "FEC Payload",
"2dparityfec.payload",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL} }
};
static gint *ett[] = {
&ett_2dparityfec,
};
proto_2dparityfec = proto_register_protocol(
"Pro-MPEG Code of Practice #3 release 2 FEC Protocol",
"2dparityfec",
"2dparityfec");
proto_register_field_array(proto_2dparityfec, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
module_2dparityfec = prefs_register_protocol(proto_2dparityfec,
proto_reg_handoff_2dparityfec);
prefs_register_bool_preference(module_2dparityfec, "enable",
"Decode Pro-MPEG FEC on RTP dynamic payload type 96",
"Enable this option to recognise all traffic on RTP dynamic payload type 96 (0x60) "
"as FEC data corresponding to Pro-MPEG Code of Practice #3 release 2",
&dissect_fec);
}
void proto_reg_handoff_2dparityfec(void)
{
static dissector_handle_t handle_2dparityfec = NULL;
if (!handle_2dparityfec) {
handle_2dparityfec = create_dissector_handle(dissect_2dparityfec,
proto_2dparityfec);
}
if (dissect_fec) {
dissector_add_uint("rtp.pt", fec_rtp_payload_type, handle_2dparityfec);
} else {
dissector_delete_uint("rtp.pt", fec_rtp_payload_type, handle_2dparityfec);
}
}
