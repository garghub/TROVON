static gboolean check_crc8(tvbuff_t *p, guint8 len, guint8 offset, guint8 received_fcs)
{
int i;
guint8 crc = 0, tmp;
for (i = 0; i < len; i++) {
tmp = tvb_get_guint8(p, offset++);
crc = crc8_table[crc ^ tmp];
}
if (received_fcs == crc)
return TRUE;
else
return FALSE;
}
static int dissect_dvb_s2_gse(tvbuff_t *tvb, int cur_off, proto_tree *tree, packet_info *pinfo)
{
int new_off = 0;
int frag_len;
guint16 gse_hdr, data_len, gse_proto = 0;
proto_item *ti, *tf;
proto_tree *dvb_s2_gse_tree, *dvb_s2_gse_hdr_tree;
tvbuff_t *next_tvb;
col_append_str(pinfo->cinfo, COL_INFO, "GSE");
gse_hdr = tvb_get_ntohs(tvb, cur_off + DVB_S2_GSE_OFFS_HDR);
new_off += 2;
frag_len = (gse_hdr & DVB_S2_GSE_HDR_LENGTH_MASK)+2;
ti = proto_tree_add_item(tree, proto_dvb_s2_gse, tvb, cur_off, frag_len, ENC_NA);
dvb_s2_gse_tree = proto_item_add_subtree(ti, ett_dvb_s2_gse);
tf = proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_hdr, tvb, cur_off + DVB_S2_GSE_OFFS_HDR, 2, gse_hdr);
dvb_s2_gse_hdr_tree = proto_item_add_subtree(tf, ett_dvb_s2_gse_hdr);
proto_tree_add_item(dvb_s2_gse_hdr_tree, hf_dvb_s2_gse_hdr_start, tvb, cur_off + DVB_S2_GSE_OFFS_HDR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_gse_hdr_tree, hf_dvb_s2_gse_hdr_stop, tvb, cur_off + DVB_S2_GSE_OFFS_HDR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_gse_hdr_tree, hf_dvb_s2_gse_hdr_labeltype, tvb,
cur_off + DVB_S2_GSE_OFFS_HDR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_gse_hdr_tree, hf_dvb_s2_gse_hdr_length, tvb, cur_off + DVB_S2_GSE_OFFS_HDR, 2, ENC_BIG_ENDIAN);
if (BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_START_POS) &&
BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_STOP_POS) &&
BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS1) && BIT_IS_CLEAR(gse_hdr, DVB_S2_GSE_HDR_LABELTYPE_POS2)) {
col_append_str(pinfo->cinfo, COL_INFO, " ");
return new_off;
} else {
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
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_label3, tvb, cur_off + new_off, 3, ENC_NA);
new_off += 3;
} else {
if (BIT_IS_SET(gse_hdr, DVB_S2_GSE_HDR_STOP_POS))
col_append_str(pinfo->cinfo, COL_INFO, "0 ");
}
if (gse_proto < 0x0600) {
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
proto_tree_add_item(dvb_s2_gse_tree, hf_dvb_s2_gse_crc32, tvb, cur_off + new_off, DVB_S2_GSE_CRC32_LEN, ENC_NA);
new_off += DVB_S2_GSE_CRC32_LEN;
}
}
return new_off;
}
static gboolean test_dvb_s2_crc(tvbuff_t *tvb, guint offset) {
guint8 input8;
if (tvb_length(tvb) < (offset + DVB_S2_BB_HEADER_LEN))
return FALSE;
input8 = tvb_get_guint8(tvb, offset + DVB_S2_BB_OFFS_CRC);
if (!check_crc8(tvb, DVB_S2_BB_HEADER_LEN - 1, offset, input8))
return FALSE;
else
return TRUE;
}
static int dissect_dvb_s2_bb(tvbuff_t *tvb, int cur_off, proto_tree *tree, packet_info *pinfo)
{
proto_item *ti, *tf;
proto_tree *dvb_s2_bb_tree, *dvb_s2_bb_matype1_tree;
guint8 input8;
guint16 input16, bb_data_len = 0;
int sub_dissected = 0, flag_is_ms = 0, new_off = 0;
col_append_str(pinfo->cinfo, COL_PROTOCOL, "BB ");
col_append_str(pinfo->cinfo, COL_INFO, "Baseband ");
ti = proto_tree_add_item(tree, proto_dvb_s2_bb, tvb, cur_off, DVB_S2_BB_HEADER_LEN, ENC_NA);
dvb_s2_bb_tree = proto_item_add_subtree(ti, ett_dvb_s2_bb);
input8 = tvb_get_guint8(tvb, cur_off + DVB_S2_BB_OFFS_MATYPE1);
new_off += 1;
if (BIT_IS_CLEAR(input8, DVB_S2_BB_MIS_POS))
flag_is_ms = 1;
tf = proto_tree_add_item(dvb_s2_bb_tree, hf_dvb_s2_bb_matype1, tvb, cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, input8);
dvb_s2_bb_matype1_tree = proto_item_add_subtree(tf, ett_dvb_s2_bb_matype1);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_gs, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_mis, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_acm, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_issyi, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_npd, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_bb_matype1_tree, hf_dvb_s2_bb_matype1_ro, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE1, 1, ENC_BIG_ENDIAN);
input8 = tvb_get_guint8(tvb, cur_off + DVB_S2_BB_OFFS_MATYPE2);
new_off += 1;
if (flag_is_ms) {
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_matype2, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE2, 1, input8, "MATYPE2: Input Stream Identifier (ISI): %d",
input8);
} else {
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_matype2, tvb,
cur_off + DVB_S2_BB_OFFS_MATYPE2, 1, input8, "MATYPE2: reserved");
}
input16 = tvb_get_ntohs(tvb, cur_off + DVB_S2_BB_OFFS_UPL);
new_off += 2;
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_upl, tvb,
cur_off + DVB_S2_BB_OFFS_UPL, 2, input16, "User Packet Length: %d bits (%d bytes)",
(guint16) input16, (guint16) input16 / 8);
bb_data_len = input16 = tvb_get_ntohs(tvb, cur_off + DVB_S2_BB_OFFS_DFL);
bb_data_len /= 8;
new_off += 2;
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_dfl, tvb,
cur_off + DVB_S2_BB_OFFS_DFL, 2, input16, "DFL: %d bits (%d bytes)", input16, input16 / 8);
new_off += 1;
proto_tree_add_item(dvb_s2_bb_tree, hf_dvb_s2_bb_sync, tvb, cur_off + DVB_S2_BB_OFFS_SYNC, 1, ENC_BIG_ENDIAN);
new_off += 2;
proto_tree_add_item(dvb_s2_bb_tree, hf_dvb_s2_bb_syncd, tvb, cur_off + DVB_S2_BB_OFFS_SYNCD, 2, ENC_BIG_ENDIAN);
input8 = tvb_get_guint8(tvb, cur_off + DVB_S2_BB_OFFS_CRC);
new_off += 1;
if (check_crc8(tvb, DVB_S2_BB_HEADER_LEN - 1, cur_off, input8)) {
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_crc, tvb,
cur_off + DVB_S2_BB_OFFS_CRC, 1, 1, "Checksum: correct (0x%2.2x)", input8);
} else {
proto_tree_add_uint_format(dvb_s2_bb_tree, hf_dvb_s2_bb_crc, tvb,
cur_off + DVB_S2_BB_OFFS_CRC, 1, -1, "Checksum: incorrect! (0x%2.2x)", input8);
}
while (bb_data_len) {
sub_dissected = dissect_dvb_s2_gse(tvb, cur_off + new_off, tree, pinfo);
new_off += sub_dissected;
if ((sub_dissected <= bb_data_len) && (sub_dissected >= DVB_S2_GSE_MINSIZE)) {
bb_data_len -= sub_dissected;
if (bb_data_len < DVB_S2_GSE_MINSIZE)
bb_data_len = 0;
} else
bb_data_len = 0;
}
return new_off;
}
static int dissect_dvb_s2_modeadapt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int cur_off = 0, dvb_s2_modeadapt_len = -1;
proto_item *ti, *tf;
proto_tree *dvb_s2_modeadapt_tree;
proto_tree *dvb_s2_modeadapt_acm_tree;
guint8 byte;
if (tvb_length(tvb) < 1)
return 0;
byte = tvb_get_guint8(tvb, DVB_S2_MODEADAPT_OFFS_SYNCBYTE);
cur_off++;
if (byte != DVB_S2_MODEADAPT_SYNCBYTE)
return 0;
if (test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_INSIZE)) {
dvb_s2_modeadapt_len = 2;
} else if (test_dvb_s2_crc(tvb, DVB_S2_MODEADAPT_OUTSIZE)) {
dvb_s2_modeadapt_len = 4;
} else {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DVB-S2 ");
col_set_str(pinfo->cinfo, COL_INFO, "DVB-S2 ");
ti = proto_tree_add_item(tree, proto_dvb_s2_modeadapt, tvb, 0, dvb_s2_modeadapt_len, ENC_NA);
dvb_s2_modeadapt_tree = proto_item_add_subtree(ti, ett_dvb_s2_modeadapt);
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_sync, tvb, DVB_S2_MODEADAPT_OFFS_SYNCBYTE, 1, ENC_BIG_ENDIAN);
cur_off++;
tf = proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_acm, tvb,
DVB_S2_MODEADAPT_OFFS_ACMBYTE, 1, ENC_BIG_ENDIAN);
dvb_s2_modeadapt_acm_tree = proto_item_add_subtree(tf, ett_dvb_s2_modeadapt_acm);
proto_tree_add_item(dvb_s2_modeadapt_acm_tree, hf_dvb_s2_modeadapt_acm_fecframe, tvb,
DVB_S2_MODEADAPT_OFFS_ACMBYTE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_modeadapt_acm_tree, hf_dvb_s2_modeadapt_acm_pilot, tvb,
DVB_S2_MODEADAPT_OFFS_ACMBYTE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_s2_modeadapt_acm_tree, hf_dvb_s2_modeadapt_acm_modcod, tvb,
DVB_S2_MODEADAPT_OFFS_ACMBYTE, 1, ENC_BIG_ENDIAN);
if (dvb_s2_modeadapt_len > 2) {
cur_off++;
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_cni, tvb, DVB_S2_MODEADAPT_OFFS_CNI, 1, ENC_BIG_ENDIAN);
cur_off++;
proto_tree_add_item(dvb_s2_modeadapt_tree, hf_dvb_s2_modeadapt_frameno, tvb, DVB_S2_MODEADAPT_OFFS_FNO, 1, ENC_BIG_ENDIAN);
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
"Stream Input", "dvb-s2_bb.matype1.gs",
FT_UINT8, BASE_DEC, VALS(bb_gs), DVB_S2_BB_GS_MASK,
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
"CRC", "dvb-s2_bb.crc",
FT_UINT8, BASE_HEX, NULL, 0x0,
"CRC-8", HFILL}
}
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
{&hf_dvb_s2_gse_proto, {
"Protocol", "dvb-s2_gse.proto",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(gse_proto_str), 0x0,
"Protocol Type", HFILL}
},
{&hf_dvb_s2_gse_label6, {
"Label", "dvb-s2_gse.label",
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
proto_dvb_s2_modeadapt = proto_register_protocol("DVB-S2 Modeadaption Header", "DVB-S2", "dvb-s2_modeadapt");
proto_dvb_s2_bb = proto_register_protocol("DVB-S2 Baseband Frame", "DVB-S2-BB", "dvb-s2_bb");
proto_dvb_s2_gse = proto_register_protocol("DVB-S2 GSE Packet", "DVB-S2-GSE", "dvb-s2_gse");
proto_register_field_array(proto_dvb_s2_modeadapt, hf_modeadapt, array_length(hf_modeadapt));
proto_register_subtree_array(ett_modeadapt, array_length(ett_modeadapt));
proto_register_field_array(proto_dvb_s2_bb, hf_bb, array_length(hf_bb));
proto_register_subtree_array(ett_bb, array_length(ett_bb));
proto_register_field_array(proto_dvb_s2_gse, hf_gse, array_length(hf_gse));
proto_register_subtree_array(ett_gse, array_length(ett_gse));
dvb_s2_modeadapt_module = prefs_register_protocol(proto_dvb_s2_modeadapt, proto_reg_handoff_dvb_s2_modeadapt);
prefs_register_bool_preference(dvb_s2_modeadapt_module, "enable", "Enable dissector",
"Enable DVB-S2 dissector", &dvb_s2_enable);
prefs_register_bool_preference(dvb_s2_modeadapt_module, "full_decode",
"Enable dissection of GSE data",
"Check this to enable full protocol dissection of data above GSE Layer",
&dvb_s2_full_dissection);
}
void proto_reg_handoff_dvb_s2_modeadapt(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
heur_dissector_add("udp", dissect_dvb_s2_modeadapt, proto_dvb_s2_modeadapt);
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
prefs_initialized = TRUE;
}
proto_set_decoding(proto_dvb_s2_modeadapt, dvb_s2_enable);
}
