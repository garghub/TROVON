static guint8
reverse_byte(guint8 val)
{
return ( ((val & 0x80)>>7) | ((val & 0x40)>>5) |
((val & 0x20)>>3) | ((val & 0x10)>>1) |
((val & 0x08)<<1) | ((val & 0x04)<<3) |
((val & 0x02)<<5) | ((val & 0x01)<<7) );
}
static gchar *
t30_get_string_numbers(tvbuff_t *tvb, int offset, int len)
{
gchar *buf;
int i;
if (len != LENGTH_T30_NUM)
return NULL;
buf=(gchar *)ep_alloc(LENGTH_T30_NUM+1);
for (i=0; i<LENGTH_T30_NUM; i++)
buf[LENGTH_T30_NUM-i-1] = reverse_byte(tvb_get_guint8(tvb, offset+i));
buf[LENGTH_T30_NUM] = '\0';
return g_strstrip(buf);
}
static void
dissect_t30_numbers(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree)
{
gchar *str_num=NULL;
str_num = t30_get_string_numbers(tvb, offset, len);
if (str_num) {
proto_tree_add_string_format(tree, hf_t30_fif_number, tvb, offset, LENGTH_T30_NUM, str_num,
"Number: %s", str_num);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " - Number:%s", str_num );
if (pinfo->private_data)
g_snprintf(((t38_packet_info*)pinfo->private_data)->desc, MAX_T38_DESC, "Num: %s", str_num);
}
else {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: number of digits must be 20]");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET: number of digits must be 20]" );
}
}
static void
dissect_t30_facsimile_coded_data(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree)
{
guint8 octet;
guint8 *t4_data;
if (len < 2) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: FCD length must be at least 2 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 FCD length must be at least 2 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET]");
return;
}
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_t30_t4_frame_num, tvb, offset, 1, reverse_byte(octet));
offset++;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " - Frame num:%d", reverse_byte(octet));
if (pinfo->private_data)
g_snprintf(((t38_packet_info*)pinfo->private_data)->desc, MAX_T38_DESC, "Frm num: %d", reverse_byte(octet));
t4_data = (guint8 *)ep_alloc(len-1);
tvb_memcpy(tvb, t4_data, offset, len-1);
proto_tree_add_bytes(tree, hf_t30_t4_data, tvb, offset, len-1, t4_data);
}
static void
dissect_t30_non_standard_cap(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree)
{
guint8 octet;
guint8 *non_standard_bytes;
if (len < 2) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: NSC length must be at least 2 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 NSC length must be at least 2 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET]");
return;
}
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_t30_fif_country_code, tvb, offset, 1, octet);
offset++;
non_standard_bytes = (guint8 *)ep_alloc(len-1);
tvb_memcpy(tvb, non_standard_bytes, offset, len-1);
proto_tree_add_bytes(tree, hf_t30_fif_non_stand_bytes, tvb, offset, len-1, non_standard_bytes);
}
static void
dissect_t30_partial_page_signal(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree)
{
guint8 octet, page_count, block_count, frame_count;
if (len != 4) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: PPS length must be 4 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 PPS length must be 4 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET]");
return;
}
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_t30_partial_page_fcf2, tvb, offset, 1, octet);
offset += 1;
octet = tvb_get_guint8(tvb, offset);
page_count = reverse_byte(octet);
proto_tree_add_uint(tree, hf_t30_partial_page_i1, tvb, offset, 1, page_count);
offset++;
octet = tvb_get_guint8(tvb, offset);
block_count = reverse_byte(octet);
proto_tree_add_uint(tree, hf_t30_partial_page_i2, tvb, offset, 1, block_count);
offset++;
octet = tvb_get_guint8(tvb, offset);
frame_count = reverse_byte(octet);
proto_tree_add_uint(tree, hf_t30_partial_page_i3, tvb, offset, 1, frame_count);
offset++;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " - PC:%d BC:%d FC:%d", page_count, block_count, frame_count);
if (pinfo->private_data)
g_snprintf(((t38_packet_info*)pinfo->private_data)->desc, MAX_T38_DESC,
"PC:%d BC:%d FC:%d", page_count, block_count, frame_count);
}
static void
dissect_t30_partial_page_request(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree)
{
int frame_count = 0;
int frame;
#define BUF_SIZE (10*1 + 90*2 + 156*3 + 256*2 + 1)
gchar *buf = (gchar *)ep_alloc(BUF_SIZE);
gchar *buf_top = buf;
if (len != 32) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: PPR length must be 32 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 PPR length must be 32 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET]");
return;
}
for (frame=0; frame < 255; ) {
guint8 octet = tvb_get_guint8(tvb, offset);
guint8 bit = 1<<7;
for (;bit;) {
if (octet & bit) {
++frame_count;
DISSECTOR_ASSERT((buf_top-buf) < BUF_SIZE);
buf_top += g_snprintf(buf_top, BUF_SIZE - (gulong)(buf_top - buf), "%u, ", frame);
}
bit >>= 1;
++frame;
}
++offset;
}
proto_tree_add_uint(tree, hf_t30_partial_page_request_frame_count, tvb, offset, 1, frame_count);
if (buf_top > buf+1) {
buf_top[-2] = '\0';
proto_tree_add_string_format(tree, hf_t30_partial_page_request_frames, tvb, offset, (gint)(buf_top-buf),
buf, "Frames: %s", buf);
}
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " - %d frames", frame_count);
}
static void
dissect_t30_dis_dtc(tvbuff_t *tvb, int offset, packet_info *pinfo, int len, proto_tree *tree, gboolean dis_dtc)
{
guint8 octet;
if (len < 3) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: DIS length must be at least 4 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 DIS length must be at least 4 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " [MALFORMED OR SHORT PACKET]");
return;
}
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_sm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_rtif, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_3gmn, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_boolean(tree, hf_t30_fif_v8c, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_op, tvb, offset, 1, octet);
}
offset += 1;
octet = tvb_get_guint8(tvb, offset);
if (dis_dtc)
proto_tree_add_boolean(tree, hf_t30_fif_rtfc, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_rfo, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_uint(tree, hf_t30_fif_dsr, tvb, offset, 1, octet);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
" - DSR:%s",
val_to_str_const((octet&0x3C) >> 2, t30_data_signalling_rate_vals, "<unknown>"));
if (pinfo->private_data)
g_snprintf(((t38_packet_info*)pinfo->private_data)->desc, MAX_T38_DESC,
"DSR:%s",
val_to_str_const((octet&0x3C) >> 2, t30_data_signalling_rate_vals, "<unknown>"));
}
else {
proto_tree_add_uint(tree, hf_t30_fif_dsr_dcs, tvb, offset, 1, octet);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
" - DSR:%s",
val_to_str_const((octet&0x3C) >> 2, t30_data_signalling_rate_dcs_vals, "<unknown>"));
if (pinfo->private_data)
g_snprintf(((t38_packet_info*)pinfo->private_data)->desc, MAX_T38_DESC,
"DSR:%s",
val_to_str_const((octet&0x3C) >> 2, t30_data_signalling_rate_dcs_vals, "<unknown>"));
}
proto_tree_add_boolean(tree, hf_t30_fif_res, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_tdcc, tvb, offset, 1, octet);
offset += 1;
octet = tvb_get_guint8(tvb, offset);
if (dis_dtc) {
proto_tree_add_uint(tree, hf_t30_fif_rwc, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_t30_fif_rlc, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_t30_fif_msltcr, tvb, offset, 1, octet);
} else {
proto_tree_add_uint(tree, hf_t30_fif_rw_dcs, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_t30_fif_rl_dcs, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_t30_fif_mslt_dcs, tvb, offset, 1, octet);
}
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 4) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_cm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ecm, tvb, offset, 1, octet);
if (!dis_dtc)
proto_tree_add_boolean(tree, hf_t30_fif_fs_dcs, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_t6, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 5) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_fvc, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_boolean(tree, hf_t30_fif_mspc, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ps, tvb, offset, 1, octet);
}
proto_tree_add_boolean(tree, hf_t30_fif_t43, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_pi, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_vc32k, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 6) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_r8x15, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_300x300, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_r16x15, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_boolean(tree, hf_t30_fif_ibrp, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_mbrp, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_msltchr, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_sp, tvb, offset, 1, octet);
} else {
proto_tree_add_boolean(tree, hf_t30_fif_rts, tvb, offset, 1, octet);
}
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 7) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_sc, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_boolean(tree, hf_t30_fif_passw, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_rttd, tvb, offset, 1, octet);
} else {
proto_tree_add_boolean(tree, hf_t30_fif_sit, tvb, offset, 1, octet);
}
proto_tree_add_boolean(tree, hf_t30_fif_bft, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_dtm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_edi, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 8) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_btm, tvb, offset, 1, octet);
if (dis_dtc)
proto_tree_add_boolean(tree, hf_t30_fif_rttcmmd, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_chrm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_mm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 9) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_pm26, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_dnc, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_do, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_jpeg, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_fcm, tvb, offset, 1, octet);
if (!dis_dtc)
proto_tree_add_boolean(tree, hf_t30_fif_pht, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_12c, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 10) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_ns, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ci, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_cgr, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_nalet, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_naleg, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_spscb, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_spsco, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 11) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_hkm, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_rsa, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_oc, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_hfx40, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_acn2c, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_acn3c, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_hfx40i, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 12) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_ahsn2, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ahsn3, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_t441, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_t442, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_t443, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_plmss, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 13) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_cg300, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_100x100cg, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_spcbft, tvb, offset, 1, octet);
if (dis_dtc) {
proto_tree_add_boolean(tree, hf_t30_fif_ebft, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_isp, tvb, offset, 1, octet);
}
proto_tree_add_boolean(tree, hf_t30_fif_ira, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 14) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_600x600, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_1200x1200, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_300x600, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_400x800, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_600x1200, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_cg600x600, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_cg1200x1200, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) || (len < 15) )
return;
offset += 1;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_t30_fif_dspcam, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_dspccm, tvb, offset, 1, octet);
if (dis_dtc)
proto_tree_add_boolean(tree, hf_t30_fif_bwmrcp, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_t45, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_t30_fif_sdmc, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_t30_fif_ext, tvb, offset, 1, octet);
if ( !(octet & 0x01) )
return;
}
static int
dissect_t30_hdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_item *it;
proto_tree *tr;
proto_tree *tr_fif;
proto_item *it_fcf;
guint8 octet;
guint32 frag_len;
proto_item *item;
if (tvb_reported_length_remaining(tvb, offset) < 3) {
proto_tree_add_text(tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"[MALFORMED OR SHORT PACKET: hdlc T30 length must be at least 4 bytes]");
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR, "T30 length must be at least 4 bytes");
col_append_str(pinfo->cinfo, COL_INFO, " (HDLC Reassembled: [MALFORMED OR SHORT PACKET])");
return offset;
}
col_append_str(pinfo->cinfo, COL_INFO, " (HDLC Reassembled:");
it=proto_tree_add_protocol_format(tree, proto_t30, tvb, offset, -1,
"ITU-T Recommendation T.30");
tr=proto_item_add_subtree(it, ett_t30);
octet = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint(tr, hf_t30_Address, tvb, offset, 1, octet);
if (octet != 0xFF)
expert_add_info_format(pinfo, item, PI_REASSEMBLE, PI_WARN, "T30 Address must be 0xFF");
offset += 1;
octet = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint(tr, hf_t30_Control, tvb, offset, 1, octet);
if ((octet != 0xC0) && (octet != 0xC8))
expert_add_info_format(pinfo, item, PI_REASSEMBLE, PI_WARN, "T30 Control Field must be 0xC0 or 0xC8");
offset += 1;
octet = tvb_get_guint8(tvb, offset);
it_fcf = proto_tree_add_uint(tr, hf_t30_Facsimile_Control, tvb, offset, 1, octet & 0x7F);
offset += 1;
tr_fif = proto_item_add_subtree(it_fcf, ett_t30_fif);
frag_len = tvb_length_remaining(tvb, offset);
if (pinfo->private_data)
((t38_packet_info*)pinfo->private_data)->t30_Facsimile_Control = octet;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
" %s - %s",
val_to_str_const(octet & 0x7F, t30_facsimile_control_field_vals_short, "<unknown>"),
val_to_str_const(octet & 0x7F, t30_facsimile_control_field_vals, "<unknown>") );
switch (octet & 0x7F) {
case T30_FC_DIS:
case T30_FC_DTC:
dissect_t30_dis_dtc(tvb, offset, pinfo, frag_len, tr_fif, TRUE);
break;
case T30_FC_DCS:
dissect_t30_dis_dtc(tvb, offset, pinfo, frag_len, tr_fif, FALSE);
break;
case T30_FC_CSI:
case T30_FC_CIG:
case T30_FC_TSI:
case T30_FC_PWD:
case T30_FC_SEP:
case T30_FC_SUB:
case T30_FC_SID:
case T30_FC_PSA:
dissect_t30_numbers(tvb, offset, pinfo, frag_len, tr_fif);
break;
case T30_FC_NSF:
case T30_FC_NSC:
case T30_FC_NSS:
dissect_t30_non_standard_cap(tvb, offset, pinfo, frag_len, tr_fif);
break;
case T30_FC_FCD:
dissect_t30_facsimile_coded_data(tvb, offset, pinfo, frag_len, tr_fif);
break;
case T30_FC_PPS:
dissect_t30_partial_page_signal(tvb, offset, pinfo, frag_len, tr_fif);
break;
case T30_FC_PPR:
dissect_t30_partial_page_request(tvb, offset, pinfo, frag_len, tr_fif);
break;
}
col_append_str(pinfo->cinfo, COL_INFO, ")");
return offset;
}
void
proto_register_t30(void)
{
static hf_register_info hf_t30[] =
{
{ &hf_t30_Address,
{ "Address", "t30.Address", FT_UINT8, BASE_HEX,
NULL, 0, "Address Field", HFILL }},
{ &hf_t30_Control,
{ "Control", "t30.Control", FT_UINT8, BASE_HEX,
VALS(t30_control_vals), 0, "Control Field", HFILL }},
{ &hf_t30_Facsimile_Control,
{ "Facsimile Control", "t30.FacsimileControl", FT_UINT8, BASE_DEC,
VALS(t30_facsimile_control_field_vals), 0, NULL, HFILL }},
{ &hf_t30_fif_sm,
{ "Store and forward Internet fax- Simple mode (ITU-T T.37)", "t30.fif.sm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_rtif,
{ "Real-time Internet fax (ITU T T.38)", "t30.fif.rtif", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_3gmn,
{ "3rd Generation Mobile Network", "t30.fif.3gmn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_v8c,
{ "V.8 capabilities", "t30.fif.v8c", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_op,
{ "Octets preferred", "t30.fif.op", FT_BOOLEAN, 8,
TFS(&t30_octets_preferred_value), 0x02, NULL, HFILL }},
{ &hf_t30_fif_rtfc,
{ "Ready to transmit a facsimile document (polling)", "t30.fif.rtfc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_rfo,
{ "Receiver fax operation", "t30.fif.rfo", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_dsr,
{ "Data signalling rate", "t30.fif.dsr", FT_UINT8, BASE_HEX,
VALS(t30_data_signalling_rate_vals), 0x3C, NULL, HFILL }},
{ &hf_t30_fif_dsr_dcs,
{ "Data signalling rate", "t30.fif.dsr_dcs", FT_UINT8, BASE_HEX,
VALS(t30_data_signalling_rate_dcs_vals), 0x3C, NULL, HFILL }},
{ &hf_t30_fif_res,
{ "R8x7.7 lines/mm and/or 200x200 pels/25.4 mm", "t30.fif.res", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_tdcc,
{ "Two dimensional coding capability", "t30.fif.tdcc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x01, NULL, HFILL }},
{ &hf_t30_fif_rwc,
{ "Recording width capabilities", "t30.fif.rwc", FT_UINT8, BASE_HEX,
VALS(t30_recording_width_capabilities_vals), 0xC0, NULL, HFILL }},
{ &hf_t30_fif_rw_dcs,
{ "Recording width", "t30.fif.rw_dcs", FT_UINT8, BASE_HEX,
VALS(t30_recording_width_dcs_vals), 0xC0, NULL, HFILL }},
{ &hf_t30_fif_rlc,
{ "Recording length capability", "t30.fif.rlc", FT_UINT8, BASE_HEX,
VALS(t30_recording_length_capability_vals), 0x30, NULL, HFILL }},
{ &hf_t30_fif_rl_dcs,
{ "Recording length capability", "t30.fif.rl_dcs", FT_UINT8, BASE_HEX,
VALS(t30_recording_length_dcs_vals), 0x30, NULL, HFILL }},
{ &hf_t30_fif_msltcr,
{ "Minimum scan line time capability at the receiver", "t30.fif.msltcr", FT_UINT8, BASE_HEX,
VALS(t30_minimum_scan_line_time_rec_vals), 0x0E, NULL, HFILL }},
{ &hf_t30_fif_mslt_dcs,
{ "Minimum scan line time", "t30.fif.mslt_dcs", FT_UINT8, BASE_HEX,
VALS(t30_minimum_scan_line_time_dcs_vals), 0x0E, NULL, HFILL }},
{ &hf_t30_fif_ext,
{ "Extension indicator", "t30.fif.ext", FT_BOOLEAN, 8,
TFS(&t30_extension_ind_value), 0x01, NULL, HFILL }},
{ &hf_t30_fif_cm,
{ "Compress/Uncompress mode", "t30.fif.cm", FT_BOOLEAN, 8,
TFS(&t30_compress_value), 0x40, NULL, HFILL }},
{ &hf_t30_fif_ecm,
{ "Error correction mode", "t30.fif.ecm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_fs_dcs,
{ "Frame size", "t30.fif.fs_dcm", FT_BOOLEAN, 8,
TFS(&t30_frame_size_dcs_value), 0x10, NULL, HFILL }},
{ &hf_t30_fif_t6,
{ "T.6 coding capability", "t30.fif.t6", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_fvc,
{ "Field valid capability", "t30.fif.fvc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_mspc,
{ "Multiple selective polling capability", "t30.fif.mspc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_ps,
{ "Polled Subaddress", "t30.fif.ps", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_t43,
{ "T.43 coding", "t30.fif.t43", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_pi,
{ "Plane interleave", "t30.fif.pi", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_vc32k,
{ "Voice coding with 32k ADPCM (ITU T G.726)", "t30.fif.vc32k", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_r8x15,
{ "R8x15.4 lines/mm", "t30.fif.r8x15", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_300x300,
{ "300x300 pels/25.4 mm", "t30.fif.300x300", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_r16x15,
{ "R16x15.4 lines/mm and/or 400x400 pels/25.4 mm", "t30.fif.r16x15", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_ibrp,
{ "Inch based resolution preferred", "t30.fif.ibrp", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_mbrp,
{ "Metric based resolution preferred", "t30.fif.mbrp", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_msltchr,
{ "Minimum scan line time capability for higher resolutions", "t30.fif.msltchr", FT_BOOLEAN, 8,
TFS(&t30_minimum_scan_value), 0x04, NULL, HFILL }},
{ &hf_t30_fif_rts,
{ "Resolution type selection", "t30.fif.rts", FT_BOOLEAN, 8,
TFS(&t30_res_type_sel_value), 0x10, NULL, HFILL }},
{ &hf_t30_fif_sp,
{ "Selective polling", "t30.fif.sp", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_sc,
{ "Subaddressing capability", "t30.fif.sc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_passw,
{ "Password", "t30.fif.passw", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_sit,
{ "Sender Identification transmission", "t30.fif.sit", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_rttd,
{ "Ready to transmit a data file (polling)", "t30.fif.rttd", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_bft,
{ "Binary File Transfer (BFT)", "t30.fif.bft", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_dtm,
{ "Document Transfer Mode (DTM)", "t30.fif.dtm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_edi,
{ "Electronic Data Interchange (EDI)", "t30.fif.edi", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_btm,
{ "Basic Transfer Mode (BTM)", "t30.fif.btm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_rttcmmd,
{ "Ready to transmit a character or mixed mode document (polling)", "t30.fif.rttcmmd", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_chrm,
{ "Character mode", "t30.fif.chrm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_mm,
{ "Mixed mode (Annex E/T.4)", "t30.fif.mm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_pm26,
{ "Processable mode 26 (ITU T T.505)", "t30.fif.pm26", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_dnc,
{ "Digital network capability", "t30.fif.dnc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_do,
{ "Duplex operation", "t30.fif.do", FT_BOOLEAN, 8,
TFS(&t30_duplex_operation_value), 0x20, NULL, HFILL }},
{ &hf_t30_fif_jpeg,
{ "JPEG coding", "t30.fif.jpeg", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_fcm,
{ "Full colour mode", "t30.fif.fcm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_pht,
{ "Preferred Huffman tables", "t30.fif.pht", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_12c,
{ "12 bits/pel component", "t30.fif.12c", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_ns,
{ "No subsampling (1:1:1)", "t30.fif.ns", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_ci,
{ "Custom illuminant", "t30.fif.ci", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_cgr,
{ "Custom gamut range", "t30.fif.cgr", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_nalet,
{ "North American Letter (215.9 x 279.4 mm) capability", "t30.fif.nalet", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_naleg,
{ "North American Legal (215.9 x 355.6 mm) capability", "t30.fif.naleg", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_spscb,
{ "Single-progression sequential coding (ITU-T T.85) basic capability", "t30.fif.spscb", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_spsco,
{ "Single-progression sequential coding (ITU-T T.85) optional L0 capability", "t30.fif.spsco", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_hkm,
{ "HKM key management capability", "t30.fif.hkm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_rsa,
{ "RSA key management capability", "t30.fif.rsa", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_oc,
{ "Override capability", "t30.fif.oc", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_hfx40,
{ "HFX40 cipher capability", "t30.fif.hfx40", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_acn2c,
{ "Alternative cipher number 2 capability", "t30.fif.acn2c", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_acn3c,
{ "Alternative cipher number 3 capability", "t30.fif.acn3c", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_hfx40i,
{ "HFX40-I hashing capability", "t30.fif.hfx40i", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_ahsn2,
{ "Alternative hashing system number 2 capability", "t30.fif.ahsn2", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_ahsn3,
{ "Alternative hashing system number 3 capability", "t30.fif.ahsn3", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_t441,
{ "T.44 (Mixed Raster Content)", "t30.fif.t441", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_t442,
{ "T.44 (Mixed Raster Content)", "t30.fif.t442", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_t443,
{ "T.44 (Mixed Raster Content)", "t30.fif.t443", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_plmss,
{ "Page length maximum strip size for T.44 (Mixed Raster Content)", "t30.fif.plmss", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_cg300,
{ "Colour/gray-scale 300 pels/25.4 mm x 300 lines/25.4 mm or 400 pels/25.4 mm x 400 lines/25.4 mm resolution", "t30.fif.cg300", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_100x100cg,
{ "100 pels/25.4 mm x 100 lines/25.4 mm for colour/gray scale", "t30.fif.100x100cg", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_spcbft,
{ "Simple Phase C BFT Negotiations capability", "t30.fif.spcbft", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_ebft,
{ "Extended BFT Negotiations capability", "t30.fif.ebft", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_isp,
{ "Internet Selective Polling Address (ISP)", "t30.fif.isp", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_ira,
{ "Internet Routing Address (IRA)", "t30.fif.ira", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_600x600,
{ "600 pels/25.4 mm x 600 lines/25.4 mm", "t30.fif.600x600", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_1200x1200,
{ "1200 pels/25.4 mm x 1200 lines/25.4 mm", "t30.fif.1200x1200", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_300x600,
{ "300 pels/25.4 mm x 600 lines/25.4 mm", "t30.fif.300x600", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_400x800,
{ "400 pels/25.4 mm x 800 lines/25.4 mm", "t30.fif.400x800", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_600x1200,
{ "600 pels/25.4 mm x 1200 lines/25.4 mm", "t30.fif.600x1200", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_t30_fif_cg600x600,
{ "Colour/gray scale 600 pels/25.4 mm x 600 lines/25.4 mm resolution", "t30.fif.cg600x600", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_t30_fif_cg1200x1200,
{ "Colour/gray scale 1200 pels/25.4 mm x 1200 lines/25.4 mm resolution", "t30.fif.cg1200x1200", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }},
{ &hf_t30_fif_dspcam,
{ "Double sided printing capability (alternate mode)", "t30.fif.dspcam", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_t30_fif_dspccm,
{ "Double sided printing capability (continuous mode)", "t30.fif.dspccm", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_t30_fif_bwmrcp,
{ "Black and white mixed raster content profile (MRCbw)", "t30.fif.bwmrcp", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_t30_fif_t45,
{ "T.45 (run length colour encoding)", "t30.fif.t45", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_t30_fif_sdmc,
{ "SharedDataMemory capacity", "t30.fif.sdmc", FT_UINT8, BASE_HEX,
VALS(t30_SharedDataMemory_capacity_vals), 0x0C, NULL, HFILL }},
{ &hf_t30_fif_number,
{ "Number", "t30.fif.number", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_t30_fif_country_code,
{ "ITU-T Country code", "t30.fif.country_code", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_fif_non_stand_bytes,
{ "Non-standard capabilities", "t30.fif.non_standard_cap", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_t30_t4_frame_num,
{ "T.4 Frame number", "t30.t4.frame_num", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_t4_data,
{ "T.4 Facsimile data field", "t30.t4.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_t30_partial_page_fcf2,
{ "Post-message command", "t30.pps.fcf2", FT_UINT8, BASE_DEC,
VALS(t30_partial_page_fcf2_vals), 0, NULL, HFILL }},
{ &hf_t30_partial_page_i1,
{ "Page counter", "t30.t4.page_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_partial_page_i2,
{ "Block counter", "t30.t4.block_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_partial_page_i3,
{ "Frame counter", "t30.t4.frame_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_partial_page_request_frame_count,
{ "Frame counter", "t30.ppr.frame_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_t30_partial_page_request_frames,
{ "Frames", "t30.ppr.frames", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *t30_ett[] =
{
&ett_t30,
&ett_t30_fif,
};
proto_t30 = proto_register_protocol("T.30", "T.30", "t30");
proto_register_field_array(proto_t30, hf_t30, array_length(hf_t30));
proto_register_subtree_array(t30_ett, array_length(t30_ett));
new_register_dissector("t30.hdlc", dissect_t30_hdlc, proto_t30);
}
