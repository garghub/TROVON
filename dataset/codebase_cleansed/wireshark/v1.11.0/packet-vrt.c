static void dissect_vrt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 type;
guint8 sidflag;
guint8 cidflag;
guint8 tflag;
guint8 tsiflag;
guint8 tsfflag;
guint16 len;
gint16 nsamps;
proto_tree *vrt_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VITA 49");
col_clear(pinfo->cinfo,COL_INFO);
if (tvb_get_guint8(tvb, 0) == 0) offset += 4;
type = tvb_get_guint8(tvb, offset) >> 4;
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(type, packet_types, "Reserved packet type (0x%02x)"));
sidflag = (type & 1) || (type == 4);
cidflag = (tvb_get_guint8(tvb, offset) >> 3) & 0x01;
tflag = (tvb_get_guint8(tvb, offset) >> 2) & 0x01;
if(type == 4) tflag = 0;
tsiflag = (tvb_get_guint8(tvb, offset+1) >> 6) & 0x03;
tsfflag = (tvb_get_guint8(tvb, offset+1) >> 4) & 0x03;
len = tvb_get_ntohs(tvb, offset+2);
nsamps = len - 1 - sidflag - cidflag*2 - tsiflag - tsfflag*2 - tflag;
if (tree) {
ti = proto_tree_add_item(tree, proto_vrt, tvb, offset, -1, ENC_NA);
vrt_tree = proto_item_add_subtree(ti, ett_vrt);
dissect_header(tvb, vrt_tree, type, offset);
offset += 4;
if(sidflag) {
proto_tree_add_item(vrt_tree, hf_vrt_sid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if(cidflag) {
dissect_cid(tvb, vrt_tree, offset);
offset += 8;
}
if(tsiflag != 0) {
proto_tree_add_item(vrt_tree, hf_vrt_ts_int, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if(tsfflag != 0) {
if(tsfflag == 1 || tsfflag == 3) {
proto_tree_add_item(vrt_tree, hf_vrt_ts_frac_sample, tvb, offset, 8, ENC_BIG_ENDIAN);
} else if(tsfflag == 2) {
proto_tree_add_item(vrt_tree, hf_vrt_ts_frac_picosecond, tvb, offset, 8, ENC_BIG_ENDIAN);
}
offset += 8;
}
if(nsamps > 0)
{
proto_tree_add_item(vrt_tree, hf_vrt_data, tvb, offset, nsamps*4, ENC_NA);
}
offset += nsamps*4;
if(tflag) {
dissect_trailer(tvb, vrt_tree, offset);
}
} else {
}
}
void dissect_header(tvbuff_t *tvb, proto_tree *tree, int type, int _offset)
{
int offset;
proto_item *hdr_item;
proto_tree *hdr_tree;
offset = _offset;
hdr_item = proto_tree_add_item(tree, hf_vrt_header, tvb, offset, 4, ENC_BIG_ENDIAN);
hdr_tree = proto_item_add_subtree(hdr_item, ett_header);
proto_tree_add_item(hdr_tree, hf_vrt_type, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(hdr_tree, hf_vrt_cidflag, tvb, (offset * 8) + 5, 1, ENC_NA);
if(type == 4) {
proto_tree_add_item(hdr_tree, hf_vrt_tsmflag, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_bits_item(hdr_tree, hf_vrt_tflag, tvb, (offset * 8) + 6, 1, ENC_NA);
}
offset += 1;
proto_tree_add_item(hdr_tree, hf_vrt_tsi, tvb, offset, 1, ENC_NA);
proto_tree_add_item(hdr_tree, hf_vrt_tsf, tvb, offset, 1, ENC_NA);
proto_tree_add_item(hdr_tree, hf_vrt_seq, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(hdr_tree, hf_vrt_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
void dissect_trailer(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *enable_item, *ind_item, *trailer_item;
proto_tree *enable_tree;
proto_tree *ind_tree;
proto_tree *trailer_tree;
guint16 en_bits;
gint16 i;
trailer_item = proto_tree_add_item(tree, hf_vrt_trailer, tvb, offset, 4, ENC_BIG_ENDIAN);
trailer_tree = proto_item_add_subtree(trailer_item, ett_trailer);
enable_item = proto_tree_add_item(trailer_tree, hf_vrt_trailer_enables, tvb, offset, 2, ENC_NA);
ind_item = proto_tree_add_item(trailer_tree, hf_vrt_trailer_ind, tvb, offset + 1, 2, ENC_NA);
en_bits = (tvb_get_ntohs(tvb, offset) & 0xFFF0) >> 4;
if(en_bits) {
enable_tree = proto_item_add_subtree(enable_item, ett_ind_enables);
ind_tree = proto_item_add_subtree(ind_item, ett_indicators);
for(i = 11; i >= 0; i--) {
if(en_bits & (1<<i)) {
proto_tree_add_bits_item(enable_tree, *enable_hfs[i], tvb, (offset+(i<3)) * 8 + (i+1), 1, ENC_NA);
proto_tree_add_bits_item(ind_tree, *ind_hfs[i], tvb, (offset+(i<8)+1) * 8 + (i+5), 1, ENC_NA);
}
}
}
offset += 3;
proto_tree_add_bits_item(trailer_tree, hf_vrt_trailer_e, tvb, offset * 8, 1, ENC_NA);
proto_tree_add_item(trailer_tree, hf_vrt_trailer_acpc, tvb, offset, 1, ENC_NA);
}
void dissect_cid(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *cid_item;
proto_tree *cid_tree;
cid_item = proto_tree_add_item(tree, hf_vrt_cid, tvb, offset, 8, ENC_BIG_ENDIAN);
cid_tree = proto_item_add_subtree(cid_item, ett_cid);
offset += 1;
proto_tree_add_item(cid_tree, hf_vrt_cid_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(cid_tree, hf_vrt_cid_icc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cid_tree, hf_vrt_cid_pcc, tvb, offset, 2, ENC_BIG_ENDIAN);
}
void
proto_register_vrt(void)
{
static hf_register_info hf[] = {
{ &hf_vrt_header,
{ "VRT header", "vrt.hdr",
FT_UINT32, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_type,
{ "Packet type", "vrt.type",
FT_UINT8, 4,
VALS(packet_types), 0xF0,
NULL, HFILL }
},
{ &hf_vrt_cidflag,
{ "Class ID included", "vrt.cidflag",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_tflag,
{ "Trailer included", "vrt.tflag",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_tsmflag,
{ "Timestamp mode", "vrt.tsmflag",
FT_UINT8, 1,
VALS(tsm_types), 0x01,
NULL, HFILL }
},
{ &hf_vrt_tsi,
{ "Integer timestamp type", "vrt.tsi",
FT_UINT8, 2,
VALS(tsi_types), 0xC0,
NULL, HFILL }
},
{ &hf_vrt_tsf,
{ "Fractional timestamp type", "vrt.tsf",
FT_UINT8, 2,
VALS(tsf_types), 0x30,
NULL, HFILL }
},
{ &hf_vrt_seq,
{ "Sequence number", "vrt.seq",
FT_UINT8, 4,
NULL, 0x0F,
NULL, HFILL }
},
{ &hf_vrt_len,
{ "Length", "vrt.len",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_ts_int,
{ "Integer timestamp", "vrt.ts_int",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_ts_frac_sample,
{ "Fractional timestamp (samples)", "vrt.ts_frac_sample",
FT_UINT64, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_ts_frac_picosecond,
{ "Fractional timestamp (picoseconds)", "vrt.ts_frac_picosecond",
FT_DOUBLE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_sid,
{ "Stream ID", "vrt.sid",
FT_UINT32, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_cid,
{ "Class ID", "vrt.cid",
FT_UINT64, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_data,
{ "Data", "vrt.data",
FT_BYTES, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer,
{ "Trailer", "vrt.trailer",
FT_UINT32, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_enables,
{ "Indicator enable bits", "vrt.enables",
FT_UINT16, BASE_HEX,
NULL, 0xFFF0,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind,
{ "Indicator bits", "vrt.indicators",
FT_UINT16, BASE_HEX,
NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_vrt_trailer_e,
{ "Associated context packet count enabled", "vrt.e",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_acpc,
{ "Associated context packet count", "vrt.acpc",
FT_UINT8, BASE_DEC,
NULL, 0x7F,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_caltime,
{ "Calibrated time indicator", "vrt.caltime",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_valid,
{ "Valid signal indicator", "vrt.valid",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_reflock,
{ "Reference lock indicator", "vrt.reflock",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_agc,
{ "AGC/MGC indicator", "vrt.agc",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_sig,
{ "Signal detected indicator", "vrt.sig",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_inv,
{ "Spectral inversion indicator", "vrt.inv",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_overrng,
{ "Overrange indicator", "vrt.overrng",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_sampleloss,
{ "Lost sample indicator", "vrt.sampleloss",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_user0,
{ "User indicator 0", "vrt.user0",
FT_BOOLEAN, BASE_NONE,
NULL, 0x000,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_user1,
{ "User indicator 1", "vrt.user1",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_user2,
{ "User indicator 2", "vrt.user2",
FT_BOOLEAN, BASE_NONE,
NULL, 0x000,
NULL, HFILL }
},
{ &hf_vrt_trailer_ind_user3,
{ "User indicator 3", "vrt.user3",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_caltime,
{ "Calibrated time indicator enable", "vrt.caltime_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_valid,
{ "Valid signal indicator enable", "vrt.valid_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_reflock,
{ "Reference lock indicator enable", "vrt.reflock_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_agc,
{ "AGC/MGC indicator enable", "vrt.agc_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_sig,
{ "Signal detected indicator enable", "vrt.sig_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_inv,
{ "Spectral inversion indicator enable", "vrt.inv_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_overrng,
{ "Overrange indicator enable", "vrt.overrng_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_sampleloss,
{ "Lost sample indicator enable", "vrt.sampleloss_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_user0,
{ "User indicator 0 enable", "vrt.user0_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_user1,
{ "User indicator 1 enable", "vrt.user1_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_user2,
{ "User indicator 2 enable", "vrt.user2_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_trailer_en_user3,
{ "User indicator 3 enable", "vrt.user3_en",
FT_BOOLEAN, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_cid_oui,
{ "Class ID Organizationally Unique ID", "vrt.oui",
FT_UINT24, BASE_HEX,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_cid_icc,
{ "Class ID Information Class Code", "vrt.icc",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_vrt_cid_pcc,
{ "Class ID Packet Class Code", "vrt.pcc",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_vrt,
&ett_header,
&ett_trailer,
&ett_indicators,
&ett_ind_enables,
&ett_cid
};
module_t *vrt_module;
proto_vrt = proto_register_protocol (
"VITA 49 radio transport protocol",
"VITA 49",
"vrt"
);
proto_register_field_array(proto_vrt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
vrt_module = prefs_register_protocol(proto_vrt, proto_reg_handoff_vrt);
prefs_register_uint_preference(vrt_module,
"dissector_port",
"Dissector UDP port",
"The UDP port used by this dissector",
10, &dissector_port_pref);
}
void
proto_reg_handoff_vrt(void)
{
static gboolean vrt_prefs_initialized = FALSE;
static dissector_handle_t vrt_handle;
static gint dissector_port;
if (!vrt_prefs_initialized) {
vrt_handle = create_dissector_handle(dissect_vrt, proto_vrt);
vrt_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", dissector_port, vrt_handle);
}
dissector_port = dissector_port_pref;
dissector_add_uint("udp.port", dissector_port, vrt_handle);
}
