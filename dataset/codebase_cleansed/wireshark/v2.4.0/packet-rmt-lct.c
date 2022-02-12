static void lct_timestamp_parse(guint32 t, nstime_t* s)
{
s->secs = t / 1000;
s->nsecs = (t % 1000) * 1000000;
}
double rmt_decode_send_rate(guint16 send_rate )
{
double value;
value = (send_rate >> 4) * 10.0 / 4096.0 * pow(10.0, (send_rate & 0xf));
return value;
}
int lct_ext_decode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint offset, guint offset_max, lct_data_exchange_t *data_exchange,
int hfext, int ettext)
{
guint8 het;
guint i, count = 0;
guint length,
tmp_offset = offset,
start_offset = offset;
proto_item *ti;
proto_tree *hec_tree, *ext_tree;
double cc_loss;
while (tmp_offset < offset_max)
{
het = tvb_get_guint8(tvb, tmp_offset);
if (het <= 127)
{
length = tvb_get_guint8(tvb, tmp_offset+1)*4;
}
else
{
length = 4;
}
if (length == 0)
break;
tmp_offset += length;
count++;
}
if (count == 0)
return 0;
ti = proto_tree_add_uint(tree, hfext, tvb, offset, tmp_offset - offset, count);
hec_tree = proto_item_add_subtree(ti, ettext);
for (i = 0; i < count; i++)
{
het = tvb_get_guint8(tvb, offset);
if (het <= 127)
{
length = tvb_get_guint8(tvb, offset+1)*4;
}
else
{
length = 4;
}
ti = proto_tree_add_item(hec_tree, hf_hec_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ext_tree = proto_item_add_subtree(ti, ett_ext_ext);
proto_item_set_len(ti, length);
if (het <= 127)
{
proto_tree_add_item(ext_tree, hf_hec_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
switch (het)
{
case 0:
case 1:
default:
proto_tree_add_item(ext_tree, hf_hec_data, tvb, offset+2, length-2, ENC_NA);
break;
case 3:
proto_tree_add_item(ext_tree, hf_cc_sequence, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_cc_flags, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_cc_rtt, tvb, offset+5, 1, ENC_BIG_ENDIAN);
cc_loss = tvb_get_ntohs(tvb, offset+6)/65535.0;
proto_tree_add_double(ext_tree, hf_cc_loss, tvb, offset+6, 2, cc_loss);
proto_tree_add_item(ext_tree, hf_cc_rate, tvb, offset+8, 2, ENC_BIG_ENDIAN);
break;
case 64:
fec_decode_ext_fti(tvb, pinfo, ext_tree, offset,
(data_exchange == NULL) ? 0 : data_exchange->codepoint);
break;
case 128:
proto_tree_add_double(ext_tree, hf_send_rate, tvb, offset+2, 2,
rmt_decode_send_rate(tvb_get_ntohs(tvb, offset+2)));
break;
case 192:
if ((data_exchange != NULL) && (data_exchange->ext_192 == LCT_PREFS_EXT_192_FLUTE))
{
proto_tree_add_item(ext_tree, hf_flute_version, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ext_tree, hf_fdt_instance_id, tvb, offset, 4, ENC_BIG_ENDIAN);
data_exchange->is_flute = TRUE;
}
break;
case 193:
if ((data_exchange != NULL) && (data_exchange->ext_193 == LCT_PREFS_EXT_193_FLUTE))
{
proto_tree_add_item(ext_tree, hf_cenc, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
break;
}
offset += length;
}
return offset-start_offset;
}
static int
dissect_lct(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
int offset = 0;
guint16 buffer16;
guint8 cci_size;
guint8 tsi_size;
guint8 toi_size;
guint64 tsi;
guint64 toi = 0;
guint16 hlen;
nstime_t tmp_time;
proto_item *ti;
proto_tree *lct_tree = tree, *lct_fsize_tree, *lct_flags_tree;
lct_data_exchange_t *data_exchange = (lct_data_exchange_t *)data;
buffer16 = tvb_get_ntohs(tvb, offset);
cci_size = ((buffer16 & 0x0C00) >> 10) * 4 + 4;
tsi_size = ((buffer16 & 0x0080) >> 7) * 4 + ((buffer16 & 0x0010) >> 4) * 2;
toi_size = ((buffer16 & 0x0060) >> 5) * 4 + ((buffer16 & 0x0010) >> 4) * 2;
hlen = tvb_get_guint8(tvb, offset+2) * 4;
if (data_exchange != NULL)
{
data_exchange->codepoint = tvb_get_guint8(tvb, offset+3);
data_exchange->is_flute = FALSE;
}
if (tree)
{
ti = proto_tree_add_item(tree, proto_rmt_lct, tvb, offset, hlen, ENC_NA);
lct_tree = proto_item_add_subtree(ti, ett_main);
proto_tree_add_item(lct_tree, hf_version, tvb, offset, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(lct_tree, hf_fsize_header, tvb, offset, 2, ENC_BIG_ENDIAN);
lct_fsize_tree = proto_item_add_subtree(ti, ett_fsize);
proto_tree_add_uint(lct_fsize_tree, hf_fsize_cci, tvb, offset, 2, cci_size);
proto_tree_add_uint(lct_fsize_tree, hf_fsize_tsi, tvb, offset, 2, tsi_size);
proto_tree_add_uint(lct_fsize_tree, hf_fsize_toi, tvb, offset, 2, toi_size);
ti = proto_tree_add_item(lct_tree, hf_flags_header, tvb, offset, 2, ENC_BIG_ENDIAN);
lct_flags_tree = proto_item_add_subtree(ti, ett_flags);
proto_tree_add_item(lct_flags_tree, hf_flags_sct_present, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_flags_tree, hf_flags_ert_present, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_flags_tree, hf_flags_close_session, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_flags_tree, hf_flags_close_object, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(lct_tree, hf_hlen, tvb, offset+2, 1, hlen);
proto_tree_add_item(lct_tree, hf_codepoint, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
offset += 4;
if (cci_size > 0) {
proto_tree_add_item(lct_tree, hf_cci, tvb, offset, cci_size, ENC_NA);
offset += cci_size;
}
if (tsi_size > 0) {
switch (tsi_size)
{
case 2:
proto_tree_add_item(lct_tree, hf_tsi16, tvb, offset, tsi_size, ENC_BIG_ENDIAN);
tsi = tvb_get_ntohs(tvb, offset);
break;
case 4:
proto_tree_add_item(lct_tree, hf_tsi32, tvb, offset, tsi_size, ENC_BIG_ENDIAN);
tsi = tvb_get_ntohl(tvb, offset);
break;
case 6:
proto_tree_add_item(lct_tree, hf_tsi48, tvb, offset, tsi_size, ENC_BIG_ENDIAN);
tsi = tvb_get_ntoh48(tvb, offset);
break;
default:
tsi = 0;
break;
}
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "TSI: %" G_GINT64_MODIFIER "u", tsi);
offset += tsi_size;
}
if (toi_size > 0) {
switch (toi_size)
{
case 2:
proto_tree_add_item(lct_tree, hf_toi16, tvb, offset, toi_size, ENC_BIG_ENDIAN);
toi = tvb_get_ntohs(tvb, offset);
break;
case 4:
proto_tree_add_item(lct_tree, hf_toi32, tvb, offset, toi_size, ENC_BIG_ENDIAN);
toi = tvb_get_ntohl(tvb, offset);
break;
case 6:
proto_tree_add_item(lct_tree, hf_toi48, tvb, offset, toi_size, ENC_BIG_ENDIAN);
toi = tvb_get_ntoh48(tvb, offset);
break;
case 8:
proto_tree_add_item(lct_tree, hf_toi64, tvb, offset, toi_size, ENC_BIG_ENDIAN);
toi = tvb_get_ntoh64(tvb, offset);
break;
case 10:
proto_tree_add_item(lct_tree, hf_toi64, tvb, offset+2, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_tree, hf_toi_extended, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 12:
proto_tree_add_item(lct_tree, hf_toi64, tvb, offset+4, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_tree, hf_toi_extended, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 14:
proto_tree_add_item(lct_tree, hf_toi64, tvb, offset+6, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(lct_tree, hf_toi_extended, tvb, offset, 6, ENC_BIG_ENDIAN);
break;
default:
break;
}
if (toi_size <= 8)
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "TOI: %" G_GINT64_MODIFIER "u", toi);
else
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "TOI: 0x%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, toi_size));
offset += toi_size;
}
if (buffer16 & LCT_CLOSE_SESSION_FLAG)
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Close session");
if (buffer16 & LCT_CLOSE_OBJECT_FLAG)
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "Close object");
if (buffer16 & LCT_SCT_FLAG) {
lct_timestamp_parse(tvb_get_ntohl(tvb, offset), &tmp_time);
proto_tree_add_time(lct_tree, hf_sct, tvb, offset, 4, &tmp_time);
offset += 4;
}
if (buffer16 & LCT_ERT_FLAG) {
lct_timestamp_parse(tvb_get_ntohl(tvb, offset), &tmp_time);
proto_tree_add_time(lct_tree, hf_ert, tvb, offset, 4, &tmp_time);
offset += 4;
}
lct_ext_decode(lct_tree, tvb, pinfo, offset, hlen, data_exchange, hf_ext, ett_ext);
return hlen;
}
void
proto_register_rmt_lct(void)
{
static hf_register_info hf[] = {
{ &hf_version,
{ "Version", "rmt-lct.version",
FT_UINT16, BASE_DEC, NULL, 0xF000,
NULL, HFILL }
},
{ &hf_fsize_header,
{ "Field size flags", "rmt-lct.fsize",
FT_UINT16, BASE_HEX, NULL, 0x0FD0,
NULL, HFILL }
},
{ &hf_fsize_cci,
{ "Congestion Control Information field size", "rmt-lct.fsize.cci",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fsize_tsi,
{ "Transport Session Identifier field size", "rmt-lct.fsize.tsi",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fsize_toi,
{ "Transport Object Identifier field size", "rmt-lct.fsize.toi",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_flags_header,
{ "Flags", "rmt-lct.flags",
FT_UINT16, BASE_HEX, NULL, 0x001F,
NULL, HFILL }
},
{ &hf_flags_sct_present,
{ "Sender Current Time present flag", "rmt-lct.flags.sct_present",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), LCT_SCT_FLAG,
NULL, HFILL }
},
{ &hf_flags_ert_present,
{ "Expected Residual Time present flag", "rmt-lct.flags.ert_present",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), LCT_ERT_FLAG,
NULL, HFILL }
},
{ &hf_flags_close_session,
{ "Close Session flag", "rmt-lct.flags.close_session",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), LCT_CLOSE_SESSION_FLAG,
NULL, HFILL }
},
{ &hf_flags_close_object,
{ "Close Object flag", "rmt-lct.flags.close_object",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), LCT_CLOSE_OBJECT_FLAG,
NULL, HFILL }
},
{ &hf_hlen,
{ "Header length", "rmt-lct.hlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_codepoint,
{ "Codepoint", "rmt-lct.codepoint",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cci,
{ "Congestion Control Information", "rmt-lct.cci",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tsi16,
{ "Transport Session Identifier", "rmt-lct.tsi",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tsi32,
{ "Transport Session Identifier", "rmt-lct.tsi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tsi48,
{ "Transport Session Identifier", "rmt-lct.tsi64",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_toi16,
{ "Transport Object Identifier", "rmt-lct.toi",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_toi32,
{ "Transport Object Identifier", "rmt-lct.toi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_toi48,
{ "Transport Object Identifier", "rmt-lct.toi64",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_toi64,
{ "Transport Object Identifier (up to 64 bits)", "rmt-lct.toi64",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_toi_extended,
{ "Transport Object Identifier (bits 64-112)", "rmt-lct.toi_extended",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sct,
{ "Sender Current Time", "rmt-lct.sct",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ert,
{ "Expected Residual Time", "rmt-lct.ert",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ext,
{ "Extension count", "rmt-lct.ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hec_type,
{ "Header Extension Type (HET)", "rmt-lct.hec.type",
FT_UINT8, BASE_DEC, VALS(hec_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_hec_len,
{ "Header Extension Length (HEL)", "rmt-lct.hec.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hec_data,
{ "Header Extension Data", "rmt-lct.hec.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_send_rate,
{ "Send Rate", "rmt-lct.send_rate",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cenc,
{ "Content Encoding Algorithm (CENC)", "rmt-lct.cenc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_flute_version,
{ "FLUTE version (V)", "rmt-lct.flute_version",
FT_UINT32, BASE_DEC, NULL, 0x00F00000,
NULL, HFILL }
},
{ &hf_fdt_instance_id,
{ "FDT Instance ID", "rmt-lct.fdt_instance_id",
FT_UINT32, BASE_DEC, NULL, 0x000FFFFF,
NULL, HFILL }
},
{ &hf_cc_sequence,
{ "CC Sequence", "rmt-lct.cc_sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cc_flags,
{ "CC Flags", "rmt-lct.cc_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cc_rtt,
{ "CC RTT", "rmt-lct.cc_rtt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cc_loss,
{ "CC Loss", "rmt-lct.cc_loss",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cc_rate,
{ "CC Rate", "rmt-lct.cc_rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_main,
&ett_fsize,
&ett_flags,
&ett_ext,
&ett_ext_ext
};
proto_rmt_lct = proto_register_protocol("Layered Coding Transport", "RMT-LCT", "rmt-lct");
register_dissector("rmt-lct", dissect_lct, proto_rmt_lct);
proto_register_field_array(proto_rmt_lct, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
