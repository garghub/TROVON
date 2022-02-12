static guint8 compute_crc8(tvbuff_t *p, guint8 len, guint8 offset)
{
int i;
guint8 crc = 0, tmp;
for (i = 0; i < len; i++) {
tmp = tvb_get_guint8(p, offset++);
crc = crc8_table[crc ^ tmp];
}
return crc;
}
static int dissect_dvb_s2_gse(tvbuff_t *tvb, int cur_off, proto_tree *tree, packet_info *pinfo, int bytes_available)
{
int new_off = 0;
int frag_len;
guint16 gse_hdr, data_len, padding_len, gse_proto = 0;
proto_item *ti;
proto_tree *dvb_s2_gse_tree;
tvbuff_t *next_tvb;
static const int * gse_header_bitfields[] = {
&hf_dvb_s2_gse_hdr_start,
&hf_dvb_s2_gse_hdr_stop,
&hf_dvb_s2_gse_hdr_labeltype,
&hf_dvb_s2_gse_hdr_length,
NULL
};
col_append_str(pinfo->cinfo, COL_INFO, " GSE");
gse_hdr = tvb_get_ntohs(tvb, cur_off + DVB_S2_GSE_OFFS_HDR);
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) &&
BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_STOP_POS) &&
BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS1) && BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS2)) {
padding_len = bytes_available;
proto_tree_add_uint_format(tree, hf_dvb_s2_gse_padding, tvb, cur_off + new_off, padding_len, padding_len,
"DVB-S2 GSE Padding, Length: %d", padding_len);
col_append_str(pinfo->cinfo, COL_INFO, " pad");
new_off += padding_len;
return new_off;
} else {
new_off += 2;
frag_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK)+2;
ti = proto_tree_add_item(tree, proto_dvb_s2_gse, tvb, cur_off, frag_len, ENC_NA);
dvb_s2_gse_tree = proto_item_add_subtree(ti, ett_dvb_s2_gse);
proto_tree_add_bitmask_with_flags(dvb_s2_gse_tree, tvb, cur_off + DVB_S2_GSE_OFFS_HDR, hf_dvb_s2_gse_hdr,
ett_dvb_s2_gse_hdr, gse_header_bitfields, ENC_BIG_ENDIAN, BMT_NO_TFS);
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) || BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_STOP_POS)) {
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_fragid, tvb, cur_off + new_off, 1, ENC_BIG_ENDIAN);
new_off += 1;
}
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_START_POS) && BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_STOP_POS)) {
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_totlength, tvb, cur_off + new_off, 2, ENC_BIG_ENDIAN);
col_append_str(pinfo->cinfo, COL_INFO, "(frag) ");
new_off += 2;
}
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_START_POS)) {
gse_proto = tvb_get_ntohs(tvb, cur_off + new_off);
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_proto, tvb, cur_off + new_off, 2, ENC_BIG_ENDIAN);
new_off += 2;
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS1) && BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS2)) {
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS))
col_append_str(pinfo->cinfo, COL_INFO, "6 ");
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_label6, tvb, cur_off + new_off, 6, ENC_NA);
new_off += 6;
} else if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS1) &&
BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS2)) {
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS))
col_append_str(pinfo->cinfo, COL_INFO, "3 ");
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_label3, tvb, cur_off + new_off, 3, ENC_BIG_ENDIAN);
new_off += 3;
} else {
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS))
col_append_str(pinfo->cinfo, COL_INFO, "0 ");
}
if (gse_proto < 0x0600 && gse_proto >= 0x100) {
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_exthdr, tvb, cur_off + new_off, 1, ENC_BIG_ENDIAN);
new_off += 1;
}
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "(frag) ");
}
next_tvb = tvb_new_subset_remaining(tvb, cur_off + new_off);
if (dvb_s2_full_dissection)
{
switch (gse_proto) {
case ETHERTYPE_IP:
new_off += call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case ETHERTYPE_IPv6:
new_off += call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
default:
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) && BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS)) {
data_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK) - (new_off - DVB_S2_GSE_MINSIZE) - DVB_S2_GSE_CRC32_LEN;
} else
data_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK) - (new_off - DVB_S2_GSE_MINSIZE);
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_data, tvb, cur_off + new_off, data_len, ENC_NA);
new_off += data_len;
break;
}
}
else
{
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) && BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS)) {
data_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK) - (new_off - DVB_S2_GSE_MINSIZE) - DVB_S2_GSE_CRC32_LEN;
} else
data_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK) - (new_off - DVB_S2_GSE_MINSIZE);
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_data, tvb, cur_off + new_off, data_len, ENC_NA);
new_off += data_len;
}
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) && BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS)) {
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_crc32, tvb, cur_off + new_off, DVB_S2_GSE_CRC32_LEN, ENC_BIG_ENDIAN);
new_off += DVB_S2_GSE_CRC32_LEN;
}
}
return new_off;
}
static gboolean test_dvb_s2_crc(tvbuff_t *tvb, guint offset) {
guint8 input8;
if (tvb_captured_length(tvb) < (offset + DVB_S2_BB_HEADER_LEN))
return FALSE;
input8 = tvb_get_guint8(tvb, offset + DVB_S2_BB_OFFS_CRC);
if (compute_crc8(tvb, DVB_S2_BB_HEADER_LEN - 1, offset) != input8)
return FALSE;
else
return TRUE;
}
static int dissect_dvb_s2_bb(tvbuff_t *tvb, int cur_off, proto_tree *tree, packet_info *pinfo)
{
proto_item *ti;
proto_tree *dvb_s2_bb_tree;
guint8 input8, matype1;
guint16 input16, bb_data_len = 0, user_packet_length;
int sub_dissected = 0, flag_is_ms = 0, new_off = 0;
static const int * bb_header_bitfields[] = {
&hf_dvb_s2_bb_matype1_gs,
&hf_dvb_s2_bb_matype1_mis,
&hf_dvb_s2_bb_matype1_acm,
&hf_dvb_s2_bb_matype1_issyi,
&hf_dvb_s2_bb_matype1_npd,
&hf_dvb_s2_bb_matype1_ro,
NULL
};
col_append_str(pinfo->cinfo, COL_PROTOCOL, "BB ");
col_append_str(pinfo->cinfo, COL_INFO, "Baseband ");
ti = proto_tree_add_item(tree, proto_dvb_s2_bb, tvb, cur_off, DVB_S2_BB_HEADER_LEN, ENC_NA);
dvb_s2_bb_tree = proto_item_add_subtree(ti, ett_dvb_s2_bb);
matype1 = tvb_get_guint8(tvb, cur_off + DVB_S2_BB_OFFS_MATYPE1);
new_off += 1;
if (BIT_IS_CLEAR(matype1, DVB_S2_BB_MIS_POS))
flag_is_ms = 1;
proto_tree_add_bitmask_with_flags(dvb_s2_bb_tree, tvb, cur_off + DVB_S2_BB_OFFS_MATYPE1, hf_dvb_s2_bb_matype1,
ett_dvb_s2_bb_matype1, bb_header_bitfields, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
input8 = tvb_get_guint8(tvb, cur_off + DVB_S2_BB_OFFS_MATYPE2);
new_off += 1;
if (flag_is_ms) {
proto_tree_add_uint_format_value(dvb_s2_bb_tree, hf_dvb_s2_bb_matype2, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE2, 1, input8, "Input Stream Identifier (ISI): %d",
input8);
} else {
proto_tree_add_uint_format_value(dvb_s2_bb_tree, hf_dvb_s2_bb_matype2, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE2, 1, input8, "reserved");
}
user_packet_length = input16 = tvb_get_ntohs(tvb, cur_off + DVB_S2_BB_OFFS_UPL);
new_off += 2;
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_upl, tvb,
cur_off + DVB_S2_BB_OFFS_UPL, 2, input16, "User Packet Length: %d bits (%d bytes)",
(guint16) input16, (guint16) input16 / 8);
bb_data_len = input16 = tvb_get_ntohs(tvb, cur_off + DVB_S2_BB_OFFS_DFL);
bb_data_len /= 8;
new_off += 2;
proto_tree_add_uint_format_value(dvb_s2_bb_tree, hf_dvb_s2_bb_dfl, tvb,
cur_off + DVB_S2_BB_OFFS_DFL, 2, input16, "%d bits (%d bytes)", input16, input16 / 8);
new_off += 1;
proto_tree_add_item(dvb_s2_bb_tree, hf_dvb_s2_bb_sync, tvb, cur_off + DVB_S2_BB_OFFS_SYNC, 1, ENC_BIG_ENDIAN);
new_off += 2;
proto_tree_add_item(dvb_s2_bb_tree, hf_dvb_s2_bb_syncd, tvb, cur_off + DVB_S2_BB_OFFS_SYNCD, 2, ENC_BIG_ENDIAN);
new_off += 1;
proto_tree_add_checksum(dvb_s2_bb_tree, tvb, cur_off + DVB_S2_BB_OFFS_CRC, hf_dvb_s2_bb_crc, hf_dvb_s2_bb_crc_status, &ei_dvb_s2_bb_crc, pinfo,
compute_crc8(tvb, DVB_S2_BB_HEADER_LEN - 1, cur_off), ENC_NA, PROTO_CHECKSUM_VERIFY);
switch (matype1 & DVB_S2_BB_TSGS_MASK) {
case DVB_S2_BB_TSGS_GENERIC_CONTINUOUS:
if (BIT_IS_SET(matype1, DVB_S2_BB_ISSYI_POS)) {
expert_add_info(pinfo, ti, &ei_dvb_s2_bb_issy_invalid);
}
if (BIT_IS_SET(matype1, DVB_S2_BB_NPD_POS)) {
expert_add_info(pinfo, ti, &ei_dvb_s2_bb_npd_invalid);
}
if (user_packet_length != 0x0000) {
expert_add_info_format(pinfo, ti, &ei_dvb_s2_bb_upl_invalid,
"UPL is 0x%04x. It must be 0x0000 for GSE packets.", user_packet_length);
}
while (bb_data_len) {
sub_dissected = dissect_dvb_s2_gse(tvb, cur_off + new_off, tree, pinfo, bb_data_len);
new_off += sub_dissected;
if ((sub_dissected <= bb_data_len) && (sub_dissected >= DVB_S2_GSE_MINSIZE)) {
bb_data_len -= sub_dissected;
if (bb_data_len < DVB_S2_GSE_MINSIZE)
bb_data_len = 0;
} else {
bb_data_len = 0;
}
}
break;
case DVB_S2_BB_TSGS_GENERIC_PACKETIZED:
proto_tree_add_item(tree, hf_dvb_s2_bb_packetized, tvb, cur_off + new_off, bb_data_len, ENC_NA);
new_off += bb_data_len;
break;
case DVB_S2_BB_TSGS_TRANSPORT_STREAM:
proto_tree_add_item(tree, hf_dvb_s2_bb_transport, tvb, cur_off + new_off, bb_data_len, ENC_NA);
new_off += bb_data_len;
break;
default:
proto_tree_add_item(tree, hf_dvb_s2_bb_reserved, tvb, cur_off + new_off,bb_data_len, ENC_NA);
new_off += bb_data_len;
expert_add_info(pinfo, ti, &ei_dvb_s2_bb_reserved);
break;
}
return new_off;
}
static int dissect_dvb_s2_modeadapt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int cur_off = 0, modeadapt_len, modeadapt_type, matched_headers = 0;
proto_item *ti;
proto_tree *dvb_s2_modeadapt_tree;
static const int * modeadapt_acm_bitfields[] = {
&hf_dvb_s2_modeadapt_acm_fecframe,
&hf_dvb_s2_modeadapt_acm_pilot,
&hf_dvb_s2_modeadapt_acm_modcod,
NULL
};
if (tvb_captured_length(tvb) < DVB_S2_MODEADAPT_MINSIZE)
return 0;
if (test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_L1SIZE)) {
matched_headers++;
modeadapt_type = DVB_S2_MODEADAPT_TYPE_L1;
modeadapt_len = DVB_S2_MODEADAPT_L1SIZE;
}
if ((tvb_get_guint8(tvb, DVB_S2_MODEADAPT_OFFS_SYNCBYTE) == DVB_S2_MODEADAPT_SYNCBYTE) &&
test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_L2SIZE)) {
matched_headers++;
modeadapt_type = DVB_S2_MODEADAPT_TYPE_L2;
modeadapt_len = DVB_S2_MODEADAPT_L2SIZE;
}
if ((tvb_get_guint8(tvb, DVB_S2_MODEADAPT_OFFS_SYNCBYTE) == DVB_S2_MODEADAPT_SYNCBYTE) &&
test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_L3SIZE)) {
matched_headers++;
modeadapt_type = DVB_S2_MODEADAPT_TYPE_L3;
modeadapt_len = DVB_S2_MODEADAPT_L3SIZE;
}
if (test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_L4SIZE)) {
matched_headers++;
modeadapt_type = DVB_S2_MODEADAPT_TYPE_L4;
modeadapt_len = DVB_S2_MODEADAPT_L4SIZE;
}
if (matched_headers == 0) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DVB-S2 ");
col_set_str(pinfo->cinfo, COL_INFO, "DVB-S2 ");
if (modeadapt_len > 0) {
ti = proto_tree_add_protocol_format(tree, proto_dvb_s2_modeadapt, tvb, 0, modeadapt_len,
"DVB-S2 Mode Adaptation Header L.%d", modeadapt_type);
dvb_s2_modeadapt_tree = proto_item_add_subtree(ti, ett_dvb_s2_modeadapt);
if (matched_headers > 1) {
expert_add_info_format(pinfo, ti, &ei_dvb_s2_bb_header_ambiguous,
"Mode adaptation header format is ambiguous. Assuming L.%d", modeadapt_type);
}
if (modeadapt_type == DVB_S2_MODEADAPT_TYPE_L2 ||
modeadapt_type == DVB_S2_MODEADAPT_TYPE_L3) {
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_sync, tvb, cur_off, 1, ENC_BIG_ENDIAN);
cur_off++;
}
if (modeadapt_type == DVB_S2_MODEADAPT_TYPE_L2 ||
modeadapt_type == DVB_S2_MODEADAPT_TYPE_L3 ||
modeadapt_type == DVB_S2_MODEADAPT_TYPE_L4) {
proto_tree_add_bitmask_with_flags(dvb_s2_modeadapt_tree, tvb, DVB_S2_MODEADAPT_OFFS_ACMBYTE, hf_dvb_s2_modeadapt_acm,
ett_dvb_s2_modeadapt_acm, modeadapt_acm_bitfields, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
cur_off++;
}
if (modeadapt_type == DVB_S2_MODEADAPT_TYPE_L3 ||
modeadapt_type == DVB_S2_MODEADAPT_TYPE_L4) {
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_cni, tvb, cur_off, 1, ENC_BIG_ENDIAN);
cur_off++;
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_frameno, tvb, cur_off, 1, ENC_BIG_ENDIAN);
cur_off++;
}
}
cur_off = dissect_dvb_s2_bb(tvb, cur_off, tree, pinfo);
return cur_off;
}
void proto_register_dvb_s2_modeadapt(void)
{
module_t *dvb_s2_modeadapt_module;
static hf_register_info hf_modeadapt[] = {
{&hf_dvb_s2_modeadapt_sync, {
"Sync Byte", "dvb-s2_modeadapt.sync",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Das Sync Byte", HFILL}
},
{&hf_dvb_s2_modeadapt_acm, {
"ACM command", "dvb-s2_modeadapt.acmcmd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_dvb_s2_modeadapt_acm_fecframe, {
"FEC frame size", "dvb-s2_modeadapt.acmcmd.fecframe",
FT_BOOLEAN, 8, TFS(&tfs_modeadapt_fecframe), DVB_S2_MODEADAPT_FECFRAME_MASK,
"FEC", HFILL}
},
{&hf_dvb_s2_modeadapt_acm_pilot, {
"Pilots configuration", "dvb-s2_modeadapt.acmcmd.pilots",
FT_BOOLEAN, 8, TFS(&tfs_modeadapt_pilots), DVB_S2_MODEADAPT_PILOTS_MASK,
"Pilots", HFILL}
},
{&hf_dvb_s2_modeadapt_acm_modcod, {
"Modcod indicator", "dvb-s2_modeadapt.acmcmd.modcod",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &modeadapt_modcods_ext, DVB_S2_MODEADAPT_MODCODS_MASK,
"Modcod", HFILL}
},
{&hf_dvb_s2_modeadapt_cni, {
"Carrier to Noise [dB]", "dvb-s2_modeadapt.cni",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &modeadapt_esno_ext, 0x0,
"CNI", HFILL}
},
{&hf_dvb_s2_modeadapt_frameno, {
"Frame number", "dvb-s2_modeadapt.frameno",
FT_UINT8, BASE_DEC, NULL, 0x0,
"fno", HFILL}
}
};
static gint *ett_modeadapt[] = {
&ett_dvb_s2_modeadapt,
&ett_dvb_s2_modeadapt_acm
};
static hf_register_info hf_bb[] = {
{&hf_dvb_s2_bb_matype1, {
"MATYPE1", "dvb-s2_bb.matype1",
FT_UINT8, BASE_HEX, NULL, 0x0,
"MATYPE1 Header Field", HFILL}
},
{&hf_dvb_s2_bb_matype1_gs, {
"TS/GS Stream Input", "dvb-s2_bb.matype1.tsgs",
FT_UINT8, BASE_DEC, VALS(bb_tsgs), DVB_S2_BB_TSGS_MASK,
"Transport Stream Input or Generic Stream Input", HFILL}
},
{&hf_dvb_s2_bb_matype1_mis, {
"Input Stream", "dvb-s2_bb.matype1.mis",
FT_BOOLEAN, 8, TFS(&tfs_bb_mis), DVB_S2_BB_MIS_MASK,
"Single Input Stream or Multiple Input Stream", HFILL}
},
{&hf_dvb_s2_bb_matype1_acm, {
"Coding and Modulation", "dvb-s2_bb.matype1.acm",
FT_BOOLEAN, 8, TFS(&tfs_bb_acm), DVB_S2_BB_ACM_MASK,
"Constant Coding and Modulation or Adaptive Coding and Modulation", HFILL}
},
{&hf_dvb_s2_bb_matype1_issyi, {
"ISSYI", "dvb-s2_bb.matype1.issyi",
FT_BOOLEAN, 8, TFS(&tfs_bb_issyi), DVB_S2_BB_ISSYI_MASK,
"Input Stream Synchronization Indicator", HFILL}
},
{&hf_dvb_s2_bb_matype1_npd, {
"NPD", "dvb-s2_bb.matype1.npd",
FT_BOOLEAN, 8, TFS(&tfs_bb_npd), DVB_S2_BB_NPD_MASK,
"Null-packet deletion enabled", HFILL}
},
{&hf_dvb_s2_bb_matype1_ro, {
"RO", "dvb-s2_bb.matype1.ro",
FT_UINT8, BASE_DEC, VALS(bb_ro), DVB_S2_BB_RO_MASK,
"Transmission Roll-off factor", HFILL}
},
{&hf_dvb_s2_bb_matype2, {
"MATYPE2", "dvb-s2_bb.matype2",
FT_UINT8, BASE_HEX, NULL, 0x0,
"MATYPE2 Header Field", HFILL}
},
{&hf_dvb_s2_bb_upl, {
"UPL", "dvb-s2_bb.upl",
FT_UINT16, BASE_HEX, NULL, 0x0,
"User Packet Length", HFILL}
},
{&hf_dvb_s2_bb_dfl, {
"DFL", "dvb-s2_bb.dfl",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Data Field Length", HFILL}
},
{&hf_dvb_s2_bb_sync, {
"SYNC", "dvb-s2_bb.sync",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Copy of the User Packet Sync-byte", HFILL}
},
{&hf_dvb_s2_bb_syncd, {
"SYNCD", "dvb-s2_bb.syncd",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Distance to first user packet", HFILL}
},
{&hf_dvb_s2_bb_crc, {
"Checksum", "dvb-s2_bb.crc",
FT_UINT8, BASE_HEX, NULL, 0x0,
"CRC-8", HFILL}
},
{&hf_dvb_s2_bb_crc_status, {
"Checksum Status", "dvb-s2_bb.crc.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0x0,
NULL, HFILL}
},
{&hf_dvb_s2_bb_packetized, {
"Packetized Generic Stream Data", "dvb-s2_bb.packetized",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Packetized Generic Stream (non-TS) Data", HFILL}
},
{&hf_dvb_s2_bb_transport, {
"Transport Stream Data", "dvb-s2_bb.transport",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Transport Stream (TS) Data", HFILL}
},
{&hf_dvb_s2_bb_reserved, {
"Reserved Stream Type Data", "dvb-s2_bb.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Stream of an unknown reserved type", HFILL}
},
};
static gint *ett_bb[] = {
&ett_dvb_s2_bb,
&ett_dvb_s2_bb_matype1
};
static hf_register_info hf_gse[] = {
{&hf_dvb_s2_gse_hdr, {
"GSE header", "dvb-s2_gse.hdr",
FT_UINT16, BASE_HEX, NULL, 0x0,
"GSE Header (start/stop/length)", HFILL}
},
{&hf_dvb_s2_gse_hdr_start, {
"Start", "dvb-s2_gse.hdr.start",
FT_BOOLEAN, 16, TFS(&tfs_gse_ss), DVB_S2_GSE_HDR_START_MASK,
"Start Indicator", HFILL}
},
{&hf_dvb_s2_gse_hdr_stop, {
"Stop", "dvb-s2_gse.hdr.stop",
FT_BOOLEAN, 16, TFS(&tfs_gse_ss), DVB_S2_GSE_HDR_STOP_MASK,
"Stop Indicator", HFILL}
},
{&hf_dvb_s2_gse_hdr_labeltype, {
"Label Type", "dvb-s2_gse.hdr.labeltype",
FT_UINT16, BASE_HEX, VALS(gse_labeltype), DVB_S2_GSE_HDR_LABELTYPE_MASK,
"Label Type Indicator", HFILL}
},
{&hf_dvb_s2_gse_hdr_length, {
"Length", "dvb-s2_gse.hdr.length",
FT_UINT16, BASE_DEC, NULL, DVB_S2_GSE_HDR_LENGTH_MASK,
"GSE Length", HFILL}
},
{&hf_dvb_s2_gse_padding, {
"GSE Padding", "dvb-s2_gse.padding",
FT_UINT16, BASE_DEC, NULL, 0x0,
"GSE Padding Bytes", HFILL}
},
{&hf_dvb_s2_gse_proto, {
"Protocol", "dvb-s2_gse.proto",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(gse_proto_str), 0x0,
"Protocol Type", HFILL}
},
{&hf_dvb_s2_gse_label6, {
"Label", "dvb-s2_gse.label_ether",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Label Field", HFILL}
},
{&hf_dvb_s2_gse_label3, {
"Label", "dvb-s2_gse.label",
FT_UINT24, BASE_HEX, NULL, 0x0,
"Label Field", HFILL}
},
{&hf_dvb_s2_gse_fragid, {
"Frag ID", "dvb-s2_gse.fragid",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Fragment ID", HFILL}
},
{&hf_dvb_s2_gse_totlength, {
"Total Length", "dvb-s2_gse.totlength",
FT_UINT16, BASE_DEC, NULL, 0x0,
"GSE Total Frame Length", HFILL}
},
{&hf_dvb_s2_gse_exthdr, {
"Extension Header", "dvb-s2_gse.exthdr",
FT_UINT8, BASE_HEX, NULL, 0x0,
"optional Extension Header", HFILL}
},
{&hf_dvb_s2_gse_data, {
"PDU Data", "dvb-s2_gse.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"GSE Frame User Data", HFILL}
},
{&hf_dvb_s2_gse_crc32, {
"CRC", "dvb-s2_gse.crc",
FT_UINT32, BASE_HEX, NULL, 0x0,
"CRC-32", HFILL}
}
};
static gint *ett_gse[] = {
&ett_dvb_s2_gse,
&ett_dvb_s2_gse_hdr
};
static ei_register_info ei[] = {
{ &ei_dvb_s2_bb_crc, { "dvb-s2_bb.bad_checksum", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_dvb_s2_bb_issy_invalid, {"dvb-s2_bb.issy_invalid", PI_PROTOCOL, PI_WARN, "ISSY is active, which is not allowed for GSE packets", EXPFILL }},
{ &ei_dvb_s2_bb_npd_invalid, {"dvb-s2_bb.npd_invalid", PI_PROTOCOL, PI_WARN, "NPD is active, which is not allowed for GSE packets", EXPFILL }},
{ &ei_dvb_s2_bb_upl_invalid, {"dvb-s2_bb.upl_invalid", PI_PROTOCOL, PI_WARN, "User Packet Length non-zero, which is not allowed for GSE packets", EXPFILL }},
{ &ei_dvb_s2_bb_reserved, {"dvb-s2_bb.reserved_frame_format", PI_PROTOCOL, PI_WARN, "Reserved frame format in TS/GS is not defined", EXPFILL }},
{ &ei_dvb_s2_bb_header_ambiguous, { "dvb-s2_bb.header_ambiguous", PI_ASSUMPTION, PI_WARN, "Mode Adaptation header ambiguous", EXPFILL }},
};
expert_module_t* expert_dvb_s2_bb;
proto_dvb_s2_modeadapt = proto_register_protocol("DVB-S2 Mode Adaptation Header", "DVB-S2", "dvb-s2_modeadapt");
proto_dvb_s2_bb = proto_register_protocol("DVB-S2 Baseband Frame", "DVB-S2-BB", "dvb-s2_bb");
proto_dvb_s2_gse = proto_register_protocol("DVB-S2 GSE Packet", "DVB-S2-GSE", "dvb-s2_gse");
proto_register_field_array(proto_dvb_s2_modeadapt, hf_modeadapt, array_length(hf_modeadapt));
proto_register_subtree_array(ett_modeadapt, array_length(ett_modeadapt));
proto_register_field_array(proto_dvb_s2_bb, hf_bb, array_length(hf_bb));
proto_register_subtree_array(ett_bb, array_length(ett_bb));
expert_dvb_s2_bb = expert_register_protocol(proto_dvb_s2_bb);
expert_register_field_array(expert_dvb_s2_bb, ei, array_length(ei));
proto_register_field_array(proto_dvb_s2_gse, hf_gse, array_length(hf_gse));
proto_register_subtree_array(ett_gse, array_length(ett_gse));
dvb_s2_modeadapt_module = prefs_register_protocol(proto_dvb_s2_modeadapt, proto_reg_handoff_dvb_s2_modeadapt);
prefs_register_obsolete_preference(dvb_s2_modeadapt_module, "enable");
prefs_register_bool_preference(dvb_s2_modeadapt_module, "full_decode",
"Enable dissection of GSE data",
"Check this to enable full protocol dissection of data above GSE Layer",
&dvb_s2_full_dissection);
}
void proto_reg_handoff_dvb_s2_modeadapt(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
heur_dissector_add("udp", dissect_dvb_s2_modeadapt, "DVB-S2 over UDP", "dvb_s2_udp", proto_dvb_s2_modeadapt, HEURISTIC_DISABLE);
ip_handle = find_dissector_add_dependency("ip", proto_dvb_s2_bb);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_dvb_s2_bb);
prefs_initialized = TRUE;
}
}
