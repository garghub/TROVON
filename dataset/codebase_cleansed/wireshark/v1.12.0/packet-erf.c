static void
erf_atm_guess_lane_type(const guint8 *pd, guint len,
union wtap_pseudo_header *pseudo_header)
{
if (len >= 2) {
if (pd[0] == 0xff && pd[1] == 0x00) {
pseudo_header->atm.subtype = TRAF_ST_LANE_LE_CTRL;
} else {
pseudo_header->atm.subtype = TRAF_ST_LANE_802_3;
}
}
}
static void
erf_atm_guess_traffic_type(const guint8 *pd, guint len,
union wtap_pseudo_header *pseudo_header)
{
pseudo_header->atm.aal = AAL_5;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
if (pseudo_header->atm.vpi == 0) {
switch (pseudo_header->atm.vci) {
case 5:
pseudo_header->atm.aal = AAL_SIGNALLING;
return;
case 16:
pseudo_header->atm.type = TRAF_ILMI;
return;
}
}
if (len >= 3) {
if (pd[0] == 0xaa && pd[1] == 0xaa && pd[2] == 0x03) {
pseudo_header->atm.type = TRAF_LLCMX;
} else if ((pseudo_header->atm.aal5t_len &&
pseudo_header->atm.aal5t_len < 16) || len<16) {
pseudo_header->atm.aal = AAL_SIGNALLING;
} else if (pd[0] == 0x83 || pd[0] == 0x81) {
pseudo_header->atm.aal = AAL_SIGNALLING;
} else {
pseudo_header->atm.type = TRAF_LANE;
erf_atm_guess_lane_type(pd, len, pseudo_header);
}
} else {
pseudo_header->atm.aal = AAL_SIGNALLING;
}
}
static void
dissect_classification_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
proto_item *flags_item;
proto_tree *flags_tree;
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
guint32 value = ((guint32)(hdr >> 32)) & EHDR_CLASS_FLAGS_MASK;
flags_item = proto_tree_add_uint(tree, hf_erf_ehdr_class_flags, tvb, 0, 0, value);
flags_tree = proto_item_add_subtree(flags_item, ett_erf_flags);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_sh, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_shm, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_res1, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_user, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_res2, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_drop, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_str, tvb, 0, 0, value);
proto_tree_add_uint(tree, hf_erf_ehdr_class_seqnum, tvb, 0, 0, (guint32)hdr);
}
}
static void
dissect_intercept_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_int_res1, tvb, 0, 0, (guint8)((hdr >> 48) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_int_id, tvb, 0, 0, (guint16)((hdr >> 32 ) & 0xFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_int_res2, tvb, 0, 0, (guint32)hdr);
}
}
static void
dissect_raw_link_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_res , tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_seqnum , tvb, 0, 0, (guint32)((hdr >> 16) & 0xffff));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_rate, tvb, 0, 0, (guint32)((hdr >> 8) & 0x00ff));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_type, tvb, 0, 0, (guint32)(hdr & 0x00ff));
}
}
static void
dissect_bfs_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_hash, tvb, 0, 0, (guint32)((hdr >> 48) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_color, tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_raw_hash, tvb, 0, 0, (guint32)(hdr & 0xFFFFFFFF));
}
}
static int
channelised_fill_sdh_g707_format(sdh_g707_format_t* in_fmt, guint16 bit_flds, guint8 vc_size, guint8 rate)
{
int i = 0;
if ( (0 == vc_size) || (vc_size > DECHAN_MAX_VC_SIZE) || (rate > DECHAN_MAX_LINE_RATE) )
{
in_fmt->m_vc_size = 0;
in_fmt->m_sdh_line_rate = 0;
memset(&(in_fmt->m_vc_index_array[0]), 0x00, DECHAN_MAX_AUG_INDEX);
return -1;
}
in_fmt->m_vc_size = vc_size;
in_fmt->m_sdh_line_rate = rate;
memset(&(in_fmt->m_vc_index_array[0]), 0xff, DECHAN_MAX_AUG_INDEX);
for (i = (rate - 2); i >= 0; i--)
{
guint8 aug_n_index = 0;
if ( i >= (vc_size - 1))
{
aug_n_index = ((bit_flds >> (2 *i))& 0x3) +1;
}
else
{
aug_n_index = 0;
}
in_fmt->m_vc_index_array[i] = aug_n_index;
}
return 0;
}
static void
channelised_fill_vc_id_string(wmem_strbuf_t* out_string, sdh_g707_format_t* in_fmt)
{
int i;
gboolean is_printed = FALSE;
static const char* g_vc_size_strings[] = {
"unknown",
"VC3",
"VC4",
"VC4-4c",
"VC4-16c",
"VC4-64c", };
wmem_strbuf_truncate(out_string, 0);
if ( (in_fmt->m_vc_size > DECHAN_MAX_VC_SIZE) || (in_fmt->m_sdh_line_rate > DECHAN_MAX_LINE_RATE) )
{
wmem_strbuf_append_printf(out_string, "Malformed");
return;
}
wmem_strbuf_append_printf(out_string, "%s(",
(in_fmt->m_vc_size < array_length(g_vc_size_strings)) ?
g_vc_size_strings[in_fmt->m_vc_size] : g_vc_size_strings[0] );
if (in_fmt->m_sdh_line_rate <= 0 )
{
for (i = (DECHAN_MAX_AUG_INDEX -1); i >= 0; i--)
{
if ((in_fmt->m_vc_index_array[i] > 0) || (is_printed) )
{
wmem_strbuf_append_printf(out_string, "%s%d",
((is_printed)?", ":""),
in_fmt->m_vc_index_array[i]);
is_printed = TRUE;
}
}
}
else
{
for (i = in_fmt->m_sdh_line_rate - 2; i >= 0; i--)
{
wmem_strbuf_append_printf(out_string, "%s%d",
((is_printed)?", ":""),
in_fmt->m_vc_index_array[i]);
is_printed = TRUE;
}
}
if ( ! is_printed )
{
for ( i =0; i < in_fmt->m_vc_size - 2; i++)
{
wmem_strbuf_append_printf(out_string, "%s0",
((is_printed)?", ":""));
is_printed = TRUE;
}
}
wmem_strbuf_append_c(out_string, ')');
return;
}
static void
dissect_channelised_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
guint8 vc_id = (guint8)((hdr >> 24) & 0xFF);
guint8 vc_size = (guint8)((hdr >> 16) & 0xFF);
guint8 line_rate = (guint8)((hdr >> 8) & 0xFF);
sdh_g707_format_t g707_format;
wmem_strbuf_t *vc_id_string = wmem_strbuf_new_label(wmem_packet_scope());
channelised_fill_sdh_g707_format(&g707_format, vc_id, vc_size, line_rate);
channelised_fill_vc_id_string(vc_id_string, &g707_format);
if (tree) {
proto_tree_add_boolean(tree, hf_erf_ehdr_chan_morebits, tvb, 0, 0, (guint8)((hdr >> 63) & 0x1));
proto_tree_add_boolean(tree, hf_erf_ehdr_chan_morefrag, tvb, 0, 0, (guint8)((hdr >> 55) & 0x1));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_seqnum, tvb, 0, 0, (guint16)((hdr >> 40) & 0x7FFF));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_res, tvb, 0, 0, (guint8)((hdr >> 32) & 0xFF));
proto_tree_add_uint_format_value(tree, hf_erf_ehdr_chan_virt_container_id, tvb, 0, 0, vc_id,
"0x%.2x (g.707: %s)", vc_id, wmem_strbuf_get_str(vc_id_string));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_assoc_virt_container_size, tvb, 0, 0, vc_size);
proto_tree_add_uint(tree, hf_erf_ehdr_chan_rate, tvb, 0, 0, line_rate);
proto_tree_add_uint(tree, hf_erf_ehdr_chan_type, tvb, 0, 0, (guint8)((hdr >> 0) & 0xFF));
}
}
static void
dissect_signature_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if(tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_signature_payload_hash, tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_signature_color, tvb, 0, 0, (guint8)((hdr >> 24) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_signature_flow_hash, tvb, 0, 0, (guint32)(hdr & 0xFFFFFF));
}
}
static void
dissect_unknown_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint64(tree, hf_erf_ehdr_unk, tvb, 0, 0, hdr);
}
}
static void
dissect_mc_hdlc_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_hdlc_item;
proto_tree *mc_hdlc_tree;
struct erf_mc_hdlc_hdrx *mc_hdlc;
proto_item *pi;
mc_hdlc_item = proto_tree_add_uint(tree, hf_erf_mc_hdlc, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_hdlc_tree = proto_item_add_subtree(mc_hdlc_item, ett_erf_mc_hdlc);
mc_hdlc = (struct erf_mc_hdlc_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_cn, tvb, 0, 0, mc_hdlc->byte01);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res1, tvb, 0, 0, mc_hdlc->byte01);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res2, tvb, 0, 0, mc_hdlc->byte2);
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_fcse, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_FCSE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC FCS Error");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_sre, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_SRE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Short Record Error, <5 bytes");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_lre, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_LRE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Long Record Error, >2047 bytes");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_afe, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_AFE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Aborted Frame Error");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_oe, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_OE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Octet Error, the closing flag was not octet aligned after bit unstuffing");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_lbe, tvb, 0, 0, mc_hdlc->byte3);
if (mc_hdlc->byte3 & MC_HDLC_LBE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Lost Byte Error");
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_first, tvb, 0, 0, mc_hdlc->byte3);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res3, tvb, 0, 0, mc_hdlc->byte3);
}
}
static void
dissect_mc_raw_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_raw_item;
proto_tree *mc_raw_tree;
struct erf_mc_raw_hdrx *mc_raw;
mc_raw_item = proto_tree_add_uint(tree, hf_erf_mc_raw, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_raw_tree = proto_item_add_subtree(mc_raw_item, ett_erf_mc_raw);
mc_raw = (struct erf_mc_raw_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_int, tvb, 0, 0, mc_raw->byte0);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res1, tvb, 0, 0, mc_raw->byte0);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res2, tvb, 0, 0, mc_raw->byte12);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res3, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_sre, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_lre, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res4, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_lbe, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_first, tvb, 0, 0, mc_raw->byte3);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res5, tvb, 0, 0, mc_raw->byte3);
}
}
static void
dissect_mc_atm_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_atm_item;
proto_tree *mc_atm_tree;
struct erf_mc_atm_hdrx *mc_atm;
mc_atm_item = proto_tree_add_uint(tree, hf_erf_mc_atm, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_atm_tree = proto_item_add_subtree(mc_atm_item, ett_erf_mc_atm);
mc_atm = (struct erf_mc_atm_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_cn, tvb, 0, 0, mc_atm->byte01);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res1, tvb, 0, 0, mc_atm->byte01);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_mul, tvb, 0, 0, mc_atm->byte01);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_port, tvb, 0, 0, mc_atm->byte2);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res2, tvb, 0, 0, mc_atm->byte2);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_lbe, tvb, 0, 0, mc_atm->byte3);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_hec, tvb, 0, 0, mc_atm->byte3);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_crc10, tvb, 0, 0, mc_atm->byte3);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_oamcell, tvb, 0, 0, mc_atm->byte3);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_first, tvb, 0, 0, mc_atm->byte3);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res3, tvb, 0, 0, mc_atm->byte3);
}
}
static void
dissect_mc_rawlink_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_rawl_item;
proto_tree *mc_rawl_tree;
struct erf_mc_rawl_hdrx *mc_rawl;
mc_rawl_item = proto_tree_add_uint(tree, hf_erf_mc_rawl, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_rawl_tree = proto_item_add_subtree(mc_rawl_item, ett_erf_mc_rawlink);
mc_rawl = (struct erf_mc_rawl_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_cn, tvb, 0, 0, mc_rawl->byte01);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_res2, tvb, 0, 0, mc_rawl->byte3);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_lbe, tvb, 0, 0, mc_rawl->byte3);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_first, tvb, 0, 0, mc_rawl->byte3);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_res3, tvb, 0, 0, mc_rawl->byte3);
}
}
static void
dissect_mc_aal5_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_aal5_item;
proto_tree *mc_aal5_tree;
struct erf_mc_aal5_hdrx *mc_aal5;
mc_aal5_item = proto_tree_add_uint(tree, hf_erf_mc_aal5, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_aal5_tree = proto_item_add_subtree(mc_aal5_item, ett_erf_mc_aal5);
mc_aal5 = (struct erf_mc_aal5_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_cn, tvb, 0, 0, mc_aal5->byte01);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res1, tvb, 0, 0, mc_aal5->byte01);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_port, tvb, 0, 0, mc_aal5->byte2);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_crcck, tvb, 0, 0, mc_aal5->byte2);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_crce, tvb, 0, 0, mc_aal5->byte2);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_lenck, tvb, 0, 0, mc_aal5->byte2);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_lene, tvb, 0, 0, mc_aal5->byte2);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res2, tvb, 0, 0, mc_aal5->byte3);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_first, tvb, 0, 0, mc_aal5->byte3);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res3, tvb, 0, 0, mc_aal5->byte3);
}
}
static void
dissect_mc_aal2_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_aal2_item;
proto_tree *mc_aal2_tree;
struct erf_mc_aal2_hdrx *mc_aal2;
mc_aal2_item = proto_tree_add_uint(tree, hf_erf_mc_aal2, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_aal2_tree = proto_item_add_subtree(mc_aal2_item, ett_erf_mc_aal2);
mc_aal2 = (struct erf_mc_aal2_hdrx *) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_cn, tvb, 0, 0, mc_aal2->byte01);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res1, tvb, 0, 0, mc_aal2->byte01);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res2, tvb, 0, 0, mc_aal2->byte01);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_port, tvb, 0, 0, mc_aal2->byte2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res3, tvb, 0, 0, mc_aal2->byte2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_first, tvb, 0, 0, mc_aal2->byte2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_maale, tvb, 0, 0, mc_aal2->byte2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_lene, tvb, 0, 0, mc_aal2->byte2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_cid, tvb, 0, 0, mc_aal2->byte3);
}
}
static void
dissect_aal2_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *aal2_item;
proto_tree *aal2_tree;
struct erf_aal2_hdrx *aal2;
aal2_item = proto_tree_add_uint(tree, hf_erf_aal2, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
aal2_tree = proto_item_add_subtree(aal2_item, ett_erf_aal2);
aal2 = (struct erf_aal2_hdrx*) (&pinfo->pseudo_header->erf.subhdr.mc_hdr);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_cid, tvb, 0, 0, aal2->byte0);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_maale, tvb, 0, 0, aal2->byte1);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_maalei, tvb, 0, 0, aal2->byte23);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_first, tvb, 0, 0, aal2->byte23);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_res1, tvb, 0, 0, aal2->byte23);
}
}
static void
dissect_eth_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *eth_item;
proto_tree *eth_tree;
struct erf_eth_hdrx *eth_hdr;
eth_item = proto_tree_add_item(tree, hf_erf_eth, tvb, 0, 0, ENC_NA);
eth_tree = proto_item_add_subtree(eth_item, ett_erf_eth);
eth_hdr = (struct erf_eth_hdrx *) (&pinfo->pseudo_header->erf.subhdr.eth_hdr);
proto_tree_add_uint(eth_tree, hf_erf_eth_off, tvb, 0, 0, eth_hdr->byte0);
proto_tree_add_uint(eth_tree, hf_erf_eth_res1, tvb, 0, 0, eth_hdr->byte1);
}
}
static void
dissect_erf_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
proto_item *flags_item, *rectype_item;
proto_tree *flags_tree, *rectype_tree;
proto_tree_add_uint64(tree, hf_erf_ts, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.ts);
rectype_item = proto_tree_add_uint_format_value(tree, hf_erf_rectype, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type,
"0x%02x (Type %d: %s)",
pinfo->pseudo_header->erf.phdr.type,
pinfo->pseudo_header->erf.phdr.type & ERF_HDR_TYPE_MASK,
val_to_str_const(pinfo->pseudo_header->erf.phdr.type & ERF_HDR_TYPE_MASK,
erf_type_vals,
"Unknown Type"));
rectype_tree = proto_item_add_subtree(rectype_item, ett_erf_rectype);
proto_tree_add_uint(rectype_tree, hf_erf_type, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type);
proto_tree_add_uint(rectype_tree, hf_erf_ehdr, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type);
flags_item=proto_tree_add_uint(tree, hf_erf_flags, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
flags_tree = proto_item_add_subtree(flags_item, ett_erf_flags);
proto_tree_add_uint(flags_tree, hf_erf_flags_cap, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
proto_item_append_text(flags_item, " (Capture Interface: %d", pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_CAP_MASK);
proto_tree_add_uint(flags_tree, hf_erf_flags_vlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_trunc, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_TRUNC_MASK) {
proto_item_append_text(flags_item, "; ERF Truncation Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF Truncation Error");
}
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_rxe, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_RXE_MASK) {
proto_item_append_text(flags_item, "; ERF Rx Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF Rx Error");
}
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_dse, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_DSE_MASK) {
proto_item_append_text(flags_item, "; ERF DS Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF DS Error");
}
proto_item_append_text(flags_item, ")");
proto_tree_add_uint(flags_tree, hf_erf_flags_res, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
proto_tree_add_uint(tree, hf_erf_rlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.rlen);
pi=proto_tree_add_uint(tree, hf_erf_lctr, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.lctr);
if (pinfo->pseudo_header->erf.phdr.lctr > 0)
expert_add_info(pinfo, pi, &ei_erf_packet_loss);
proto_tree_add_uint(tree, hf_erf_wlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.wlen);
}
static void
dissect_erf_pseudo_extension_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
proto_item *ehdr_tree;
guint8 type;
guint8 has_more = pinfo->pseudo_header->erf.phdr.type & 0x80;
int i = 0;
int max = sizeof(pinfo->pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
while(has_more && (i < max)) {
type = (guint8) (pinfo->pseudo_header->erf.ehdr_list[i].ehdr >> 56);
pi = proto_tree_add_uint(tree, hf_erf_ehdr_t, tvb, 0, 0, (type & 0x7f));
ehdr_tree = proto_item_add_subtree(pi, ett_erf_pseudo_hdr);
switch (type & 0x7f) {
case EXT_HDR_TYPE_CLASSIFICATION:
dissect_classification_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case EXT_HDR_TYPE_INTERCEPTID:
dissect_intercept_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case EXT_HDR_TYPE_RAW_LINK:
dissect_raw_link_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case EXT_HDR_TYPE_BFS:
dissect_bfs_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case EXT_HDR_TYPE_CHANNELISED:
dissect_channelised_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case EXT_HDR_TYPE_SIGNATURE:
dissect_signature_ex_header(tvb, pinfo, ehdr_tree, i);
break;
default:
dissect_unknown_ex_header(tvb, pinfo, ehdr_tree, i);
break;
}
has_more = type & 0x80;
i += 1;
}
if (has_more) {
proto_tree_add_expert(tree, pinfo, &ei_erf_extension_headers_not_shown, tvb, 0, 0);
}
}
guint64* erf_get_ehdr(packet_info *pinfo, guint8 hdrtype, gint* afterindex) {
guint8 type;
guint8 has_more;
int max;
int i = afterindex ? *afterindex + 1 : 0;
if (!pinfo)
return NULL;
has_more = pinfo->pseudo_header->erf.phdr.type & 0x80;
max = sizeof(pinfo->pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
while(has_more && (i < max)) {
type = (guint8) (pinfo->pseudo_header->erf.ehdr_list[i].ehdr >> 56);
if ((type & 0x7f) == (hdrtype & 0x7f)) {
if (afterindex)
*afterindex = i;
return &pinfo->pseudo_header->erf.ehdr_list[i].ehdr;
}
has_more = type & 0x80;
i += 1;
}
return NULL;
}
static void
dissect_erf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 flags;
guint8 erf_type;
guint32 atm_hdr = 0;
proto_tree *erf_tree = NULL;
guint atm_pdu_caplen;
const guint8 *atm_pdu;
erf_hdlc_type_vals hdlc_type;
guint8 first_byte;
tvbuff_t *new_tvb;
guint8 aal2_cid;
erf_type=pinfo->pseudo_header->erf.phdr.type & 0x7F;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ERF");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(erf_type, erf_type_vals, "Unknown type %u"));
if (tree) {
proto_item *erf_item;
erf_item = proto_tree_add_item(tree, proto_erf, tvb, 0, -1, ENC_NA);
erf_tree = proto_item_add_subtree(erf_item, ett_erf);
dissect_erf_pseudo_header(tvb, pinfo, erf_tree);
if (pinfo->pseudo_header->erf.phdr.type & 0x80) {
dissect_erf_pseudo_extension_header(tvb, pinfo, erf_tree);
}
}
flags = pinfo->pseudo_header->erf.phdr.flags;
pinfo->p2p_dir = ( (flags & 0x01) ? P2P_DIR_RECV : P2P_DIR_SENT);
switch (erf_type) {
case ERF_TYPE_RAW_LINK:
if(sdh_handle){
call_dissector(sdh_handle, tvb, pinfo, tree);
}
else{
call_dissector(data_handle, tvb, pinfo, tree);
}
break;
case ERF_TYPE_IPV4:
if (ipv4_handle)
call_dissector(ipv4_handle, tvb, pinfo, tree);
else
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_IPV6:
if (ipv6_handle)
call_dissector(ipv6_handle, tvb, pinfo, tree);
else
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_INFINIBAND:
if (infiniband_handle)
call_dissector(infiniband_handle, tvb, pinfo, tree);
else
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_INFINIBAND_LINK:
if (infiniband_link_handle)
call_dissector(infiniband_link_handle, tvb, pinfo, tree);
else
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_LEGACY:
case ERF_TYPE_IP_COUNTER:
case ERF_TYPE_TCP_FLOW_COUNTER:
break;
case ERF_TYPE_PAD:
break;
case ERF_TYPE_MC_RAW:
dissect_mc_raw_header(tvb, pinfo, erf_tree);
if (data_handle)
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_MC_RAW_CHANNEL:
dissect_mc_rawlink_header(tvb, pinfo, erf_tree);
if (data_handle)
call_dissector(data_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_MC_ATM:
dissect_mc_atm_header(tvb, pinfo, erf_tree);
case ERF_TYPE_ATM:
memset(&pinfo->pseudo_header->atm, 0, sizeof(pinfo->pseudo_header->atm));
atm_hdr = tvb_get_ntohl(tvb, 0);
pinfo->pseudo_header->atm.vpi = ((atm_hdr & 0x0ff00000) >> 20);
pinfo->pseudo_header->atm.vci = ((atm_hdr & 0x000ffff0) >> 4);
pinfo->pseudo_header->atm.channel = (flags & 0x03);
if (erf_rawcell_first) {
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
pinfo->pseudo_header->atm.aal = AAL_5;
switch (erf_aal5_type) {
case ERF_AAL5_GUESS:
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
atm_pdu_caplen = tvb_length(new_tvb);
atm_pdu = tvb_get_ptr(new_tvb, 0, atm_pdu_caplen);
erf_atm_guess_traffic_type(atm_pdu, atm_pdu_caplen, pinfo->pseudo_header);
break;
case ERF_AAL5_LLC:
pinfo->pseudo_header->atm.type = TRAF_LLCMX;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ERF_AAL5_UNSPEC:
pinfo->pseudo_header->atm.aal = AAL_5;
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
call_dissector(atm_untruncated_handle, new_tvb, pinfo, tree);
} else {
pinfo->pseudo_header->atm.flags |= ATM_RAW_CELL;
pinfo->pseudo_header->atm.flags |= ATM_NO_HEC;
pinfo->pseudo_header->atm.aal = AAL_UNKNOWN;
call_dissector(atm_untruncated_handle, tvb, pinfo, tree);
}
break;
case ERF_TYPE_MC_AAL5:
dissect_mc_aal5_header(tvb, pinfo, erf_tree);
case ERF_TYPE_AAL5:
atm_hdr = tvb_get_ntohl(tvb, 0);
memset(&pinfo->pseudo_header->atm, 0, sizeof(pinfo->pseudo_header->atm));
pinfo->pseudo_header->atm.vpi = ((atm_hdr & 0x0ff00000) >> 20);
pinfo->pseudo_header->atm.vci = ((atm_hdr & 0x000ffff0) >> 4);
pinfo->pseudo_header->atm.channel = (flags & 0x03);
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
pinfo->pseudo_header->atm.aal = AAL_5;
switch (erf_aal5_type) {
case ERF_AAL5_GUESS:
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
atm_pdu_caplen = tvb_length(new_tvb);
atm_pdu = tvb_get_ptr(new_tvb, 0, atm_pdu_caplen);
erf_atm_guess_traffic_type(atm_pdu, atm_pdu_caplen, pinfo->pseudo_header);
break;
case ERF_AAL5_LLC:
pinfo->pseudo_header->atm.type = TRAF_LLCMX;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ERF_AAL5_UNSPEC:
pinfo->pseudo_header->atm.aal = AAL_5;
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
call_dissector(atm_untruncated_handle, new_tvb, pinfo, tree);
break;
case ERF_TYPE_MC_AAL2:
dissect_mc_aal2_header(tvb, pinfo, erf_tree);
atm_hdr = tvb_get_ntohl(tvb, 0);
aal2_cid = ((struct erf_mc_aal2_hdrx *)(&pinfo->pseudo_header->erf.subhdr.mc_hdr))->byte3;
memset(&pinfo->pseudo_header->atm, 0, sizeof(pinfo->pseudo_header->atm));
pinfo->pseudo_header->atm.aal = AAL_2;
pinfo->pseudo_header->atm.flags |= ATM_AAL2_NOPHDR;
pinfo->pseudo_header->atm.vpi = ((atm_hdr & 0x0ff00000) >> 20);
pinfo->pseudo_header->atm.vci = ((atm_hdr & 0x000ffff0) >> 4);
pinfo->pseudo_header->atm.channel = (flags & 0x03);
pinfo->pseudo_header->atm.aal2_cid = aal2_cid;
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
call_dissector(atm_untruncated_handle, new_tvb, pinfo, tree);
break;
case ERF_TYPE_AAL2:
dissect_aal2_header(tvb, pinfo, erf_tree);
atm_hdr = tvb_get_ntohl(tvb, 0);
memset(&pinfo->pseudo_header->atm, 0, sizeof(pinfo->pseudo_header->atm));
pinfo->pseudo_header->atm.aal = AAL_2;
pinfo->pseudo_header->atm.flags |= ATM_AAL2_NOPHDR;
pinfo->pseudo_header->atm.vpi = ((atm_hdr & 0x0ff00000) >> 20);
pinfo->pseudo_header->atm.vci = ((atm_hdr & 0x000ffff0) >> 4);
pinfo->pseudo_header->atm.channel = (flags & 0x03);
pinfo->pseudo_header->atm.type = TRAF_UNKNOWN;
pinfo->pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
call_dissector(atm_untruncated_handle, new_tvb, pinfo, tree);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
dissect_eth_header(tvb, pinfo, erf_tree);
if (erf_ethfcs)
call_dissector(ethwithfcs_handle, tvb, pinfo, tree);
else
call_dissector(ethwithoutfcs_handle, tvb, pinfo, tree);
break;
case ERF_TYPE_MC_HDLC:
dissect_mc_hdlc_header(tvb, pinfo, erf_tree);
case ERF_TYPE_HDLC_POS:
case ERF_TYPE_COLOR_HDLC_POS:
case ERF_TYPE_DSM_COLOR_HDLC_POS:
case ERF_TYPE_COLOR_MC_HDLC_POS:
hdlc_type = (erf_hdlc_type_vals)erf_hdlc_type;
if (hdlc_type == ERF_HDLC_GUESS) {
first_byte = tvb_get_guint8(tvb, 0);
if (first_byte == 0x0f || first_byte == 0x8f)
hdlc_type = ERF_HDLC_CHDLC;
else {
hdlc_type = ERF_HDLC_PPP;
}
}
switch (hdlc_type) {
case ERF_HDLC_CHDLC:
call_dissector(chdlc_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_PPP:
call_dissector(ppp_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_FRELAY:
memset(&pinfo->pseudo_header->x25, 0, sizeof(pinfo->pseudo_header->x25));
call_dissector(frelay_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_MTP2:
memset(&pinfo->pseudo_header->mtp2, 0, sizeof(pinfo->pseudo_header->mtp2));
call_dissector(mtp2_handle, tvb, pinfo, tree);
break;
default:
break;
}
break;
default:
break;
}
}
void
proto_register_erf(void)
{
static hf_register_info hf[] = {
{ &hf_erf_ts,
{ "Timestamp", "erf.ts",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_rectype,
{ "Record type", "erf.types",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_type,
{ "Type", "erf.types.type",
FT_UINT8, BASE_DEC, VALS(erf_type_vals), ERF_HDR_TYPE_MASK, NULL, HFILL } },
{ &hf_erf_ehdr,
{ "Extension header present", "erf.types.ext_header",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_EHDR_MASK, NULL, HFILL } },
{ &hf_erf_flags,
{ "Flags", "erf.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_flags_cap,
{ "Capture interface", "erf.flags.cap",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_CAP_MASK, NULL, HFILL } },
{ &hf_erf_flags_vlen,
{ "Varying record length", "erf.flags.vlen",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_VLEN_MASK, NULL, HFILL } },
{ &hf_erf_flags_trunc,
{ "Truncated", "erf.flags.trunc",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_TRUNC_MASK, NULL, HFILL } },
{ &hf_erf_flags_rxe,
{ "RX error", "erf.flags.rxe",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_RXE_MASK, NULL, HFILL } },
{ &hf_erf_flags_dse,
{ "DS error", "erf.flags.dse",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_DSE_MASK, NULL, HFILL } },
{ &hf_erf_flags_res,
{ "Reserved", "erf.flags.res",
FT_UINT8, BASE_HEX, NULL, ERF_HDR_RES_MASK, NULL, HFILL } },
{ &hf_erf_rlen,
{ "Record length", "erf.rlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_lctr,
{ "Loss counter", "erf.lctr",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_wlen,
{ "Wire length", "erf.wlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_t,
{ "Extension Header", "erf.ehdr.types",
FT_UINT8, BASE_DEC, VALS(ehdr_type_vals), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_res1,
{ "Reserved", "erf.ehdr.int.res1",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_id,
{ "Intercept ID", "erf.ehdr.int.intid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_res2,
{ "Reserved", "erf.ehdr.int.res2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_res,
{ "Reserved", "erf.ehdr.raw.res",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_seqnum,
{ "Sequence number", "erf.ehdr.raw.seqnum",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_rate,
{ "Rate", "erf.ehdr.raw.rate",
FT_UINT8, BASE_DEC, VALS(raw_link_rates), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_type,
{ "Link Type", "erf.ehdr.raw.link_type",
FT_UINT8, BASE_DEC, VALS(raw_link_types), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags,
{ "Flags", "erf.ehdr.class.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_sh,
{ "Search hit", "erf.ehdr.class.flags.sh",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_SH_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_shm,
{ "Multiple search hits", "erf.ehdr.class.flags.shm",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_SHM_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_res1,
{ "Reserved", "erf.ehdr.class.flags.res1",
FT_UINT32, BASE_HEX, NULL, EHDR_CLASS_RES1_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_user,
{ "User classification", "erf.ehdr.class.flags.user",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_USER_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_res2,
{ "Reserved", "erf.ehdr.class.flags.res2",
FT_UINT32, BASE_HEX, NULL, EHDR_CLASS_RES2_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_drop,
{ "Drop Steering Bit", "erf.ehdr.class.flags.drop",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_DROP_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_str,
{ "Stream Steering Bits", "erf.ehdr.class.flags.str",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_STER_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_seqnum,
{ "Sequence number", "erf.ehdr.class.seqnum",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_hash,
{ "Hash", "erf.ehdr.bfs.hash",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_color,
{ "Filter Color", "erf.ehdr.bfs.color",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_raw_hash,
{ "Raw Hash", "erf.ehdr.bfs.rawhash",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_morebits,
{ "More Bits", "erf.ehdr.chan.morebits",
FT_BOOLEAN, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_morefrag,
{ "More Fragments", "erf.ehdr.chan.morefrag",
FT_BOOLEAN, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_seqnum,
{ "Sequence Number", "erf.ehdr.chan.seqnum",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_res,
{ "Reserved", "erf.ehdr.chan.res",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_virt_container_id,
{ "Virtual Container ID", "erf.ehdr.chan.vcid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_assoc_virt_container_size,
{ "Associated Virtual Container Size", "erf.ehdr.chan.vcsize",
FT_UINT8, BASE_HEX, VALS(channelised_assoc_virt_container_size), 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_rate,
{ "Origin Line Type/Rate", "erf.ehdr.chan.rate",
FT_UINT8, BASE_HEX, VALS(channelised_rate), 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_type,
{ "Frame Part Type", "erf.ehdr.chan.type",
FT_UINT8, BASE_HEX, VALS(channelised_type), 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_payload_hash,
{ "Payload Hash", "erf.ehdr.signature.payloadhash",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_color,
{ "Filter Color", "erf.ehdr.signature.color",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_flow_hash,
{ "Flow Hash", "erf.ehdr.signature.flowhash",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_unk,
{ "Data", "erf.ehdr.unknown.data",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_hdlc,
{ "Multi Channel HDLC Header", "erf.mchdlc",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_hdlc_cn,
{ "Connection number", "erf.mchdlc.cn",
FT_UINT16, BASE_DEC, NULL, MC_HDLC_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res1,
{ "Reserved", "erf.mchdlc.res1",
FT_UINT16, BASE_HEX, NULL, MC_HDLC_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res2,
{ "Reserved", "erf.mchdlc.res2",
FT_UINT8, BASE_HEX, NULL, MC_HDLC_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_fcse,
{ "FCS error", "erf.mchdlc.fcse",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_FCSE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_sre,
{ "Short record error", "erf.mchdlc.sre",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_SRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_lre,
{ "Long record error", "erf.mchdlc.lre",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_LRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_afe,
{ "Aborted frame error", "erf.mchdlc.afe",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_AFE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_oe,
{ "Octet error", "erf.mchdlc.oe",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_OE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_lbe,
{ "Lost byte error", "erf.mchdlc.lbe",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_first,
{ "First record", "erf.mchdlc.first",
FT_UINT8, BASE_DEC, NULL, MC_HDLC_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res3,
{ "Reserved", "erf.mchdlc.res3",
FT_UINT8, BASE_HEX, NULL, MC_HDLC_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw,
{ "Multi Channel RAW Header", "erf.mcraw",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_raw_int,
{ "Physical interface", "erf.mcraw.int",
FT_UINT8, BASE_DEC, NULL, MC_RAW_INT_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res1,
{ "Reserved", "erf.mcraw.res1",
FT_UINT8, BASE_HEX, NULL, MC_RAW_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res2,
{ "Reserved", "erf.mcraw.res2",
FT_UINT16, BASE_HEX, NULL, MC_RAW_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res3,
{ "Reserved", "erf.mcraw.res3",
FT_UINT8, BASE_HEX, NULL, MC_RAW_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_sre,
{ "Short record error", "erf.mcraw.sre",
FT_UINT8, BASE_DEC, NULL, MC_RAW_SRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_lre,
{ "Long record error", "erf.mcraw.lre",
FT_UINT8, BASE_DEC, NULL, MC_RAW_LRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res4,
{ "Reserved", "erf.mcraw.res4",
FT_UINT8, BASE_HEX, NULL, MC_RAW_RES4_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_lbe,
{ "Lost byte error", "erf.mcraw.lbe",
FT_UINT8, BASE_DEC, NULL, MC_RAW_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_first,
{ "First record", "erf.mcraw.first",
FT_UINT8, BASE_DEC, NULL, MC_RAW_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res5,
{ "Reserved", "erf.mcraw.res5",
FT_UINT8, BASE_HEX, NULL, MC_RAW_RES5_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm,
{ "Multi Channel ATM Header", "erf.mcatm",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_erf_mc_atm_cn,
{ "Connection number", "erf.mcatm.cn",
FT_UINT16, BASE_DEC, NULL, MC_ATM_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res1,
{ "Reserved", "erf.mcatm.res1",
FT_UINT16, BASE_HEX, NULL, MC_ATM_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_mul,
{ "Multiplexed", "erf.mcatm.mul",
FT_UINT16, BASE_DEC, NULL, MC_ATM_MUL_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_port,
{ "Physical port", "erf.mcatm.port",
FT_UINT8, BASE_DEC, NULL, MC_ATM_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res2,
{ "Reserved", "erf.mcatm.res2",
FT_UINT8, BASE_HEX, NULL, MC_ATM_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_lbe,
{ "Lost Byte Error", "erf.mcatm.lbe",
FT_UINT8, BASE_DEC, NULL, MC_ATM_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_hec,
{ "HEC corrected", "erf.mcatm.hec",
FT_UINT8, BASE_DEC, NULL, MC_ATM_HEC_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_crc10,
{ "OAM Cell CRC10 Error (not implemented)", "erf.mcatm.crc10",
FT_UINT8, BASE_DEC, NULL, MC_ATM_CRC10_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_oamcell,
{ "OAM Cell", "erf.mcatm.oamcell",
FT_UINT8, BASE_DEC, NULL, MC_ATM_OAMCELL_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_first,
{ "First record", "erf.mcatm.first",
FT_UINT8, BASE_DEC, NULL, MC_ATM_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res3,
{ "Reserved", "erf.mcatm.res3",
FT_UINT8, BASE_HEX, NULL, MC_ATM_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl,
{ "Multi Channel RAW Link Header", "erf.mcrawl",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_rawl_cn,
{ "Connection number", "erf.mcrawl.cn",
FT_UINT8, BASE_DEC, NULL, MC_RAWL_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_res2,
{ "Reserved", "erf.mcrawl.res2",
FT_UINT8, BASE_HEX, NULL, MC_RAWL_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_lbe,
{ "Lost byte error", "erf.mcrawl.lbe",
FT_UINT8, BASE_DEC, NULL, MC_RAWL_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_first,
{ "First record", "erf.mcrawl.first",
FT_UINT8, BASE_DEC, NULL, MC_RAWL_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_res3,
{ "Reserved", "erf.mcrawl.res5",
FT_UINT8, BASE_HEX, NULL, MC_RAWL_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5,
{ "Multi Channel AAL5 Header", "erf.mcaal5",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_aal5_cn,
{ "Connection number", "erf.mcaal5.cn",
FT_UINT16, BASE_DEC, NULL, MC_AAL5_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res1,
{ "Reserved", "erf.mcaal5.res1",
FT_UINT16, BASE_HEX, NULL, MC_AAL5_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_port,
{ "Physical port", "erf.mcaal5.port",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_crcck,
{ "CRC checked", "erf.mcaal5.crcck",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_CRCCK_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_crce,
{ "CRC error", "erf.mcaal5.crce",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_CRCE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_lenck,
{ "Length checked", "erf.mcaal5.lenck",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_LENCK_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_lene,
{ "Length error", "erf.mcaal5.lene",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_LENE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res2,
{ "Reserved", "erf.mcaal5.res2",
FT_UINT8, BASE_HEX, NULL, MC_AAL5_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_first,
{ "First record", "erf.mcaal5.first",
FT_UINT8, BASE_DEC, NULL, MC_AAL5_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res3,
{ "Reserved", "erf.mcaal5.res3",
FT_UINT8, BASE_HEX, NULL, MC_AAL5_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2,
{ "Multi Channel AAL2 Header", "erf.mcaal2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_aal2_cn,
{ "Connection number", "erf.mcaal2.cn",
FT_UINT16, BASE_DEC, NULL, MC_AAL2_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res1,
{ "Reserved for extra connection", "erf.mcaal2.res1",
FT_UINT16, BASE_HEX, NULL, MC_AAL2_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res2,
{ "Reserved for type", "erf.mcaal2.mul",
FT_UINT16, BASE_HEX, NULL, MC_AAL2_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_port,
{ "Physical port", "erf.mcaal2.port",
FT_UINT8, BASE_DEC, NULL, MC_AAL2_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res3,
{ "Reserved", "erf.mcaal2.res2",
FT_UINT8, BASE_HEX, NULL, MC_AAL2_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_first,
{ "First cell received", "erf.mcaal2.lbe",
FT_UINT8, BASE_DEC, NULL, MC_AAL2_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_maale,
{ "MAAL error", "erf.mcaal2.hec",
FT_UINT8, BASE_DEC, NULL, MC_AAL2_MAALE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_lene,
{ "Length error", "erf.mcaal2.crc10",
FT_UINT8, BASE_DEC, NULL, MC_AAL2_LENE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_cid,
{ "Channel Identification Number", "erf.mcaal2.cid",
FT_UINT8, BASE_DEC, NULL, MC_AAL2_CID_MASK, NULL, HFILL } },
{ &hf_erf_aal2,
{ "AAL2 Header", "erf.aal2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_aal2_cid,
{ "Channel Identification Number", "erf.aal2.cid",
FT_UINT8, BASE_DEC, NULL, AAL2_CID_MASK, NULL, HFILL } },
{ &hf_erf_aal2_maale,
{ "MAAL error number", "erf.aal2.maale",
FT_UINT8, BASE_DEC, NULL, AAL2_MAALE_MASK, NULL, HFILL } },
{ &hf_erf_aal2_maalei,
{ "MAAL error", "erf.aal2.hec",
FT_UINT16, BASE_DEC, NULL, AAL2_MAALEI_MASK, NULL, HFILL } },
{ &hf_erf_aal2_first,
{ "First cell received", "erf.aal2.lbe",
FT_UINT16, BASE_DEC, NULL, AAL2_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_aal2_res1,
{ "Reserved", "erf.aal2.res1",
FT_UINT16, BASE_HEX, NULL, AAL2_RES1_MASK, NULL, HFILL } },
{ &hf_erf_eth,
{ "Ethernet pad", "erf.eth",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_eth_off,
{ "Offset", "erf.eth.off",
FT_UINT8, BASE_DEC, NULL, ETH_OFF_MASK, NULL, HFILL } },
{ &hf_erf_eth_res1,
{ "Reserved", "erf.eth.res1",
FT_UINT8, BASE_HEX, NULL, ETH_RES1_MASK, NULL, HFILL } },
};
static gint *ett[] = {
&ett_erf,
&ett_erf_pseudo_hdr,
&ett_erf_rectype,
&ett_erf_flags,
&ett_erf_mc_hdlc,
&ett_erf_mc_raw,
&ett_erf_mc_atm,
&ett_erf_mc_rawlink,
&ett_erf_mc_aal5,
&ett_erf_mc_aal2,
&ett_erf_aal2,
&ett_erf_eth
};
static const enum_val_t erf_hdlc_options[] = {
{ "chdlc", "Cisco HDLC", ERF_HDLC_CHDLC },
{ "ppp", "PPP serial", ERF_HDLC_PPP },
{ "frelay", "Frame Relay", ERF_HDLC_FRELAY },
{ "mtp2", "SS7 MTP2", ERF_HDLC_MTP2 },
{ "guess", "Attempt to guess", ERF_HDLC_GUESS },
{ NULL, NULL, 0 }
};
static const enum_val_t erf_aal5_options[] = {
{ "guess", "Attempt to guess", ERF_AAL5_GUESS },
{ "llc", "LLC multiplexed", ERF_AAL5_LLC },
{ "unspec", "Unspecified", ERF_AAL5_UNSPEC },
{ NULL, NULL, 0 }
};
static ei_register_info ei[] = {
{ &ei_erf_checksum_error, { "erf.checksum.error", PI_CHECKSUM, PI_ERROR, "ERF MC FCS Error", EXPFILL }},
{ &ei_erf_packet_loss, { "erf.packet_loss", PI_SEQUENCE, PI_WARN, "Packet loss occurred between previous and current packet", EXPFILL }},
{ &ei_erf_extension_headers_not_shown, { "erf.ehdr.more_not_shown", PI_SEQUENCE, PI_WARN, "More extension headers were present, not shown", EXPFILL }},
};
module_t *erf_module;
expert_module_t* expert_erf;
proto_erf = proto_register_protocol("Extensible Record Format", "ERF", "erf");
erf_handle = register_dissector("erf", dissect_erf, proto_erf);
proto_register_field_array(proto_erf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_erf = expert_register_protocol(proto_erf);
expert_register_field_array(expert_erf, ei, array_length(ei));
erf_module = prefs_register_protocol(proto_erf, NULL);
prefs_register_enum_preference(erf_module, "hdlc_type", "ERF_HDLC Layer 2",
"Protocol encapsulated in HDLC records",
&erf_hdlc_type, erf_hdlc_options, FALSE);
prefs_register_bool_preference(erf_module, "rawcell_first",
"Raw ATM cells are first cell of AAL5 PDU",
"Whether raw ATM cells should be treated as "
"the first cell of an AAL5 PDU",
&erf_rawcell_first);
prefs_register_enum_preference(erf_module, "aal5_type",
"ATM AAL5 packet type",
"Protocol encapsulated in ATM AAL5 packets",
&erf_aal5_type, erf_aal5_options, FALSE);
prefs_register_bool_preference(erf_module, "ethfcs",
"Ethernet packets have FCS",
"Whether the FCS is present in Ethernet packets",
&erf_ethfcs);
}
void
proto_reg_handoff_erf(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_ERF, erf_handle);
data_handle = find_dissector("data");
ipv4_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
infiniband_handle = find_dissector("infiniband");
infiniband_link_handle = find_dissector("infiniband_link");
chdlc_handle = find_dissector("chdlc");
ppp_handle = find_dissector("ppp_hdlc");
frelay_handle = find_dissector("fr");
mtp2_handle = find_dissector("mtp2");
atm_untruncated_handle = find_dissector("atm_untruncated");
ethwithfcs_handle = find_dissector("eth_withfcs");
ethwithoutfcs_handle = find_dissector("eth_withoutfcs");
sdh_handle = find_dissector("sdh");
}
