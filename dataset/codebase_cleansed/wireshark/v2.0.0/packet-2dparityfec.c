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
proto_item *ti;
proto_tree *tree_2dparityfec;
gint offset = 0;
ti = proto_tree_add_item(tree, hfi_2dparityfec, tvb, 0, -1, ENC_NA);
tree_2dparityfec = proto_item_add_subtree(ti, ett_2dparityfec);
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_snbase_low, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_length_recovery, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_rfc2733_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_pt_recovery, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_mask, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_ts_recovery, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_ts_pro_mpeg_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_row_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_index, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_offset, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_na, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_snbase_ext, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(tree_2dparityfec, &hfi_2dparityfec_payload, tvb, offset, -1, ENC_NA);
}
}
void proto_register_2dparityfec(void)
{
module_t *module_2dparityfec;
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_2dparityfec_snbase_low,
&hfi_2dparityfec_length_recovery,
&hfi_2dparityfec_rfc2733_ext,
&hfi_2dparityfec_pt_recovery,
&hfi_2dparityfec_mask,
&hfi_2dparityfec_ts_recovery,
&hfi_2dparityfec_ts_pro_mpeg_ext,
&hfi_2dparityfec_row_flag,
&hfi_2dparityfec_type,
&hfi_2dparityfec_index,
&hfi_2dparityfec_offset,
&hfi_2dparityfec_na,
&hfi_2dparityfec_snbase_ext,
&hfi_2dparityfec_payload,
};
#endif
static gint *ett[] = {
&ett_2dparityfec,
};
int proto_2dparityfec;
proto_2dparityfec = proto_register_protocol(
"Pro-MPEG Code of Practice #3 release 2 FEC Protocol",
"2dparityfec",
"2dparityfec");
hfi_2dparityfec = proto_registrar_get_nth(proto_2dparityfec);
proto_register_fields(proto_2dparityfec, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
module_2dparityfec = prefs_register_protocol(proto_2dparityfec,
proto_reg_handoff_2dparityfec);
prefs_register_bool_preference(module_2dparityfec, "enable",
"Decode Pro-MPEG FEC on RTP dynamic payload type 96",
"Enable this option to recognise all traffic on RTP dynamic payload type 96 (0x60) "
"as FEC data corresponding to Pro-MPEG Code of Practice #3 release 2",
&dissect_fec);
handle_2dparityfec = create_dissector_handle(dissect_2dparityfec,
proto_2dparityfec);
}
void proto_reg_handoff_2dparityfec(void)
{
if (dissect_fec) {
dissector_add_uint("rtp.pt", fec_rtp_payload_type, handle_2dparityfec);
} else {
dissector_delete_uint("rtp.pt", fec_rtp_payload_type, handle_2dparityfec);
}
}
