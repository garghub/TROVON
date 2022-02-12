static void
dissect_jpeg( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti = NULL;
proto_tree *jpeg_tree = NULL;
proto_tree *main_hdr_tree = NULL;
proto_tree *restart_hdr_tree = NULL;
proto_tree *qtable_hdr_tree = NULL;
guint32 fragment_offset = 0;
guint16 len = 0;
guint8 type = 0;
guint8 q = 0;
gint h = 0;
gint w = 0;
unsigned int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "JPEG");
col_set_str(pinfo->cinfo, COL_INFO, "JPEG message");
if ( tree ) {
ti = proto_tree_add_item( tree, hfi_jpeg, tvb, offset, -1, ENC_NA );
jpeg_tree = proto_item_add_subtree( ti, ett_jpeg );
ti = proto_tree_add_item(jpeg_tree, &hfi_rtp_jpeg_main_hdr, tvb, offset, 8, ENC_NA);
main_hdr_tree = proto_item_add_subtree(ti, ett_jpeg);
proto_tree_add_item(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_ts, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_offs, tvb, offset, 3, ENC_BIG_ENDIAN);
fragment_offset = tvb_get_ntoh24(tvb, offset);
offset += 3;
proto_tree_add_item(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_q, tvb, offset, 1, ENC_BIG_ENDIAN);
q = tvb_get_guint8(tvb, offset);
offset += 1;
w = tvb_get_guint8(tvb, offset) * 8;
proto_tree_add_uint(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_width, tvb, offset, 1, w);
offset += 1;
h = tvb_get_guint8(tvb, offset) * 8;
proto_tree_add_uint(main_hdr_tree, &hfi_rtp_jpeg_main_hdr_height, tvb, offset, 1, h);
offset += 1;
if (type >= 64 && type <= 127) {
ti = proto_tree_add_item(jpeg_tree, &hfi_rtp_jpeg_restart_hdr, tvb, offset, 4, ENC_NA);
restart_hdr_tree = proto_item_add_subtree(ti, ett_jpeg);
proto_tree_add_item(restart_hdr_tree, &hfi_rtp_jpeg_restart_hdr_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(restart_hdr_tree, &hfi_rtp_jpeg_restart_hdr_f, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(restart_hdr_tree, &hfi_rtp_jpeg_restart_hdr_l, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(restart_hdr_tree, &hfi_rtp_jpeg_restart_hdr_count, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (q >= 128 && fragment_offset == 0) {
ti = proto_tree_add_item(jpeg_tree, &hfi_rtp_jpeg_qtable_hdr, tvb, offset, -1, ENC_NA);
qtable_hdr_tree = proto_item_add_subtree(ti, ett_jpeg);
proto_tree_add_item(qtable_hdr_tree, &hfi_rtp_jpeg_qtable_hdr_mbz, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(qtable_hdr_tree, &hfi_rtp_jpeg_qtable_hdr_prec, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(qtable_hdr_tree, &hfi_rtp_jpeg_qtable_hdr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
len = tvb_get_ntohs(tvb, offset);
offset += 2;
if (len > 0) {
proto_tree_add_item(qtable_hdr_tree, &hfi_rtp_jpeg_qtable_hdr_data, tvb, offset, len, ENC_NA);
offset += len;
}
proto_item_set_len(ti, len + 4);
}
proto_tree_add_item( jpeg_tree, &hfi_rtp_jpeg_payload, tvb, offset, -1, ENC_NA );
}
}
void
proto_register_jpeg(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] =
{
&hfi_rtp_jpeg_main_hdr,
&hfi_rtp_jpeg_main_hdr_ts,
&hfi_rtp_jpeg_main_hdr_offs,
&hfi_rtp_jpeg_main_hdr_type,
&hfi_rtp_jpeg_main_hdr_q,
&hfi_rtp_jpeg_main_hdr_width,
&hfi_rtp_jpeg_main_hdr_height,
&hfi_rtp_jpeg_restart_hdr,
&hfi_rtp_jpeg_restart_hdr_interval,
&hfi_rtp_jpeg_restart_hdr_f,
&hfi_rtp_jpeg_restart_hdr_l,
&hfi_rtp_jpeg_restart_hdr_count,
&hfi_rtp_jpeg_qtable_hdr,
&hfi_rtp_jpeg_qtable_hdr_mbz,
&hfi_rtp_jpeg_qtable_hdr_prec,
&hfi_rtp_jpeg_qtable_hdr_length,
&hfi_rtp_jpeg_qtable_hdr_data,
&hfi_rtp_jpeg_payload,
};
#endif
static gint *ett[] =
{
&ett_jpeg,
};
int proto_jpeg;
proto_jpeg = proto_register_protocol("RFC 2435 JPEG","JPEG","jpeg");
hfi_jpeg = proto_registrar_get_nth(proto_jpeg);
proto_register_fields(proto_jpeg, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
jpeg_handle = create_dissector_handle(dissect_jpeg, proto_jpeg);
register_ber_oid_dissector_handle("0.9.2342.19200300.100.1.60", jpeg_handle, proto_jpeg, "jpegPhoto");
}
void
proto_reg_handoff_jpeg(void)
{
dissector_add_uint("rtp.pt", PT_JPEG, jpeg_handle);
}
