static int dissect_1722(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ieee1722_tree;
guint subtype = 0;
gint offset = 0;
const gint *fields[] = {
&hf_1722_svfield,
&hf_1722_verfield,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE1722");
col_set_str(pinfo->cinfo, COL_INFO, "AVB Transportation Protocol");
ti = proto_tree_add_item(tree, proto_1722, tvb, 0, -1, ENC_NA);
ieee1722_tree = proto_item_add_subtree(ti, ett_1722);
proto_tree_add_item_ret_uint(ieee1722_tree, hf_1722_subtype, tvb, offset, 1, ENC_BIG_ENDIAN, &subtype);
offset += 1;
proto_tree_add_bitmask_list(ieee1722_tree, tvb, offset, 1, fields, ENC_NA);
if (dissector_try_uint(avb_dissector_table, subtype, tvb, pinfo, tree))
return tvb_captured_length(tvb);
return tvb_captured_length(tvb);
}
void proto_register_1722(void)
{
static hf_register_info hf[] = {
{ &hf_1722_subtype,
{ "AVBTP Subtype", "ieee1722.subtype",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(subtype_range_rvals), 0x00, NULL, HFILL }
},
{ &hf_1722_svfield,
{ "AVTP Stream ID Valid", "ieee1722.svfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_SV_MASK, NULL, HFILL }
},
{ &hf_1722_verfield,
{ "AVTP Version", "ieee1722.verfield",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_VER_MASK, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_1722
};
proto_1722 = proto_register_protocol("IEEE 1722 Protocol", "IEEE1722", "ieee1722");
proto_register_field_array(proto_1722, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
avb_dissector_table = register_dissector_table("ieee1722.subtype",
"IEEE1722 AVBTP Subtype", proto_1722, FT_UINT8, BASE_HEX);
}
void proto_reg_handoff_1722(void)
{
dissector_handle_t avbtp_handle;
avbtp_handle = create_dissector_handle(dissect_1722, proto_1722);
dissector_add_uint("ethertype", ETHERTYPE_AVBTP, avbtp_handle);
}
static int dissect_1722_61883(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ti_61883_tree;
proto_tree *ti_channel;
proto_tree *ti_datalen;
proto_tree *ti_cip_fn;
proto_tree *ti_cip_dbs;
proto_tree *ti_cip_sph;
proto_tree *ti_cip_fmt;
proto_tree *ti_cip_fdf;
proto_tree *ti_audio_tree;
proto_tree *ti_sample_tree;
proto_tree *ti_video_tree;
gint offset = 1;
guint8 cip_dbs = 0;
guint8 tag = 0;
guint8 channel = 0;
guint8 tcode = 0;
guint8 cip_qi1 = 0;
guint8 cip_sid = 0;
guint8 cip_qpc = 0;
guint8 cip_qi2 = 0;
guint8 cip_fmt = 0;
guint8 cip_sph = 0;
guint8 cip_fn = 0;
guint datalen = 0;
guint db_size = 0;
guint numSourcePackets = 0;
guint i = 0;
guint j = 0;
const gint *fields[] = {
&hf_1722_61883_mrfield,
&hf_1722_61883_gvfield,
&hf_1722_61883_tvfield,
NULL
};
ti = proto_tree_add_item(tree, proto_1722_61883, tvb, 0, -1, ENC_NA);
ti_61883_tree = proto_item_add_subtree(ti, ett_1722_61883);
proto_tree_add_bitmask_list(ti_61883_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_tufield, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_avtp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_gateway_info, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti_datalen = proto_tree_add_item_ret_uint(ti_61883_tree, hf_1722_61883_stream_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
offset += 2;
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, offset) & IEEE_1722_TAG_MASK;
if (tag > 0x40)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_tag);
}
ti_channel = proto_tree_add_item(ti_61883_tree, hf_1722_61883_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
channel = tvb_get_guint8(tvb, offset) & IEEE_1722_CHANNEL_MASK;
if (channel != IEEE_1722_61883_CHANNEL_AVTP)
{
proto_item_append_text(ti_channel, ": Originating Source ID from an IEEE 1394 serial bus");
}
else
{
proto_item_append_text(ti_channel, ": Originating source is on AVTP network (native AVTP)");
}
offset += 1;
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_tcode, tvb, offset, 1, ENC_BIG_ENDIAN);
tcode = tvb_get_guint8(tvb, offset) & IEEE_1722_TCODE_MASK;
if (tcode != 0xa0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_tcode);
}
proto_tree_add_item(ti_61883_tree, hf_1722_61883_sy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag) {
case IEEE_1722_61883_TAG_NO_CIP:
proto_item_prepend_text(ti, "IIDC 1394 video payload:");
break;
case IEEE_1722_61883_TAG_CIP:
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_qi1, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qi1 = tvb_get_guint8(tvb, offset) & IEEE_1722_QI1_MASK;
if (cip_qi1 != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qi1);
}
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_sid, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_sid = tvb_get_guint8(tvb, offset) & IEEE_1722_SID_MASK;
if (cip_sid != IEEE_1722_61883_SID_AVTP)
{
proto_item_append_text(ti, ": Originating Source ID from an IEEE 1394 serial bus");
if (channel == IEEE_1722_61883_CHANNEL_AVTP)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_channel_sid);
expert_add_info(pinfo, ti_channel, &ei_1722_61883_incorrect_channel_sid);
}
}
else
{
proto_item_append_text(ti, ": Originating source is on AVTP network");
if (channel != IEEE_1722_61883_CHANNEL_AVTP)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_channel_sid);
expert_add_info(pinfo, ti_channel, &ei_1722_61883_incorrect_channel_sid);
}
}
offset += 1;
ti_cip_dbs = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_dbs, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_dbs = tvb_get_guint8(tvb, offset);
offset += 1;
ti_cip_fn = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_fn, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (tvb_get_guint8(tvb, offset) & IEEE_1722_FN_MASK) {
case 0:
cip_fn = 0;
break;
case 0x40:
cip_fn = 2;
break;
case 0x80:
cip_fn = 4;
break;
case 0xc0:
cip_fn = 8;
break;
default:
break;
}
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_qpc, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qpc = tvb_get_guint8(tvb, offset) & IEEE_1722_QPC_MASK;
if (cip_qpc != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qpc);
}
ti_cip_sph = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_sph, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_sph = tvb_get_guint8(tvb, offset) & IEEE_1722_SPH_MASK;
offset += 1;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_dbc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_qi2, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qi2 = tvb_get_guint8(tvb, offset) & IEEE_1722_QI2_MASK;
if (cip_qi2 != 0x80)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qi2);
}
ti_cip_fmt = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_fmt, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_fmt = tvb_get_guint8(tvb, offset) & IEEE_1722_FMT_MASK;
offset += 1;
if ((cip_fmt & 0x20) == 0)
{
proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_fdf, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_syt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
ti_cip_fdf = proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_fdf_no_syt, tvb, offset, 3, ENC_BIG_ENDIAN);
if (((tvb_get_guint8(tvb, offset) & 0x007fffff) != 0))
{
expert_add_info(pinfo, ti_cip_fdf, &ei_1722_61883_incorrect_cip_fdf);
}
proto_tree_add_item(ti_61883_tree, hf_1722_61883_cip_fdf_tsf, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
datalen -= IEEE_1722_CIP_HEADER_SIZE;
if (cip_dbs == 0) {
db_size = 256;
}
else
{
db_size = cip_dbs;
}
switch (cip_fmt) {
case IEEE_1722_61883_6:
if (cip_fn != 0)
{
expert_add_info(pinfo, ti_cip_fn, &ei_1722_61883_6_incorrect_cip_fn);
}
if (cip_sph != 0)
{
expert_add_info(pinfo, ti_cip_sph, &ei_1722_61883_6_incorrect_cip_sph);
}
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_audio_data, tvb, offset, datalen, ENC_NA);
ti_audio_tree = proto_item_add_subtree(ti, ett_1722_61883_audio);
if ((datalen % (db_size*4)) != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_datalen);
expert_add_info(pinfo, ti_datalen, &ei_1722_61883_incorrect_datalen);
}
numSourcePackets = datalen / (db_size*4);
if (ti_audio_tree) {
for (j = 0; j < numSourcePackets; j++) {
ti_sample_tree = proto_tree_add_subtree_format(ti_audio_tree, tvb, offset, 1, ett_1722_61883_sample, NULL, "Sample %d", j+1);
for (i = 0; i < db_size; i++) {
proto_tree_add_item(ti_sample_tree, hf_1722_61883_label, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_sample_tree, hf_1722_61883_sample, tvb, offset, 3, ENC_NA);
offset += 3;
}
}
}
break;
case IEEE_1722_61883_4:
if (db_size != 6)
{
expert_add_info(pinfo, ti_cip_dbs, &ei_1722_61883_4_incorrect_cip_dbs);
}
if (cip_fn != 8)
{
expert_add_info(pinfo, ti_cip_fn, &ei_1722_61883_4_incorrect_cip_fn);
}
if (cip_sph != 4)
{
expert_add_info(pinfo, ti_cip_sph, &ei_1722_61883_4_incorrect_cip_sph);
}
ti = proto_tree_add_item(ti_61883_tree, hf_1722_61883_video_data, tvb, offset, datalen, ENC_NA);
ti_video_tree = proto_item_add_subtree(ti, ett_1722_61883_video);
if ((datalen % IEEE_1722_61883_4_LEN_SOURCE_PACKET) != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_datalen);
expert_add_info(pinfo, ti_datalen, &ei_1722_61883_incorrect_datalen);
}
numSourcePackets = datalen / IEEE_1722_61883_4_LEN_SOURCE_PACKET;
if (ti_video_tree) {
for (j = 0; j < numSourcePackets; j++) {
proto_tree_add_item(ti_video_tree, hf_1722_61883_source_packet_header_timestamp, tvb, offset, IEEE_1722_61883_4_LEN_SP_TIMESTAMP, ENC_BIG_ENDIAN);
offset += IEEE_1722_61883_4_LEN_SP_TIMESTAMP;
proto_tree_add_item(ti_video_tree, hf_1722_61883_video_data, tvb, offset, (IEEE_1722_61883_4_LEN_SOURCE_PACKET - IEEE_1722_61883_4_LEN_SP_TIMESTAMP), ENC_NA);
offset += (IEEE_1722_61883_4_LEN_SOURCE_PACKET - IEEE_1722_61883_4_LEN_SP_TIMESTAMP);
}
}
break;
default:
expert_add_info(pinfo, ti_cip_fmt, &ei_1722_61883_unknown_format);
break;
}
break;
default:
break;
}
return tvb_captured_length(tvb);
}
void proto_register_1722_61883(void)
{
static hf_register_info hf[] = {
{ &hf_1722_61883_mrfield,
{ "Media Clock Restart", "61883.mrfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_MR_MASK, NULL, HFILL }
},
{ &hf_1722_61883_gvfield,
{ "Gateway Info Valid", "61883.gvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_GV_MASK, NULL, HFILL }
},
{ &hf_1722_61883_tvfield,
{ "Timestamp Valid", "61883.tvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TV_MASK, NULL, HFILL }
},
{ &hf_1722_61883_seqnum,
{ "Sequence Number", "61883.seqnum",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_tufield,
{ "Timestamp Uncertain", "61883.tufield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TU_MASK, NULL, HFILL }
},
{ &hf_1722_61883_stream_id,
{ "Stream ID", "61883.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_avtp_timestamp,
{ "AVTP Timestamp", "61883.avtp_timestamp",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_gateway_info,
{ "Gateway Info", "61883.gateway_info",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_stream_data_length,
{ "1394 Stream Data Length", "61883.stream_data_len",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_tag,
{ "1394 Packet Format Tag", "61883.tag",
FT_UINT8, BASE_HEX, VALS(tag_vals), IEEE_1722_TAG_MASK, NULL, HFILL }
},
{ &hf_1722_61883_channel,
{ "1394 Packet Channel", "61883.channel",
FT_UINT8, BASE_DEC, NULL, IEEE_1722_CHANNEL_MASK, NULL, HFILL }
},
{ &hf_1722_61883_tcode,
{ "1394 Packet Tcode", "61883.tcode",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_TCODE_MASK, NULL, HFILL }
},
{ &hf_1722_61883_sy,
{ "1394 App-specific Control", "61883.sy",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_SY_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_qi1,
{ "CIP Quadlet Indicator 1", "61883.qi1",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_QI1_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_sid,
{ "CIP Source ID", "61883.sid",
FT_UINT8, BASE_DEC, NULL, IEEE_1722_SID_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_dbs,
{ "CIP Data Block Size", "61883.dbs",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_cip_fn,
{ "CIP Fraction Number", "61883.fn",
FT_UINT8, BASE_HEX, VALS(fraction_number_vals), IEEE_1722_FN_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_qpc,
{ "CIP Quadlet Padding Count", "61883.qpc",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_QPC_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_sph,
{ "CIP Source Packet Header", "61883.sph",
FT_BOOLEAN, 8, NULL, IEEE_1722_SPH_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_dbc,
{ "CIP Data Block Continuity", "61883.dbc",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_cip_qi2,
{ "CIP Quadlet Indicator 2", "61883.qi2",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_QI2_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_fmt,
{ "CIP Format ID", "61883.fmt",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(format_rvals), IEEE_1722_FMT_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_fdf_no_syt,
{ "CIP Format Dependent Field", "61883.fdf_no_syt",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_cip_fdf_tsf,
{ "Time shift flag", "61883.fdf_tsf",
FT_BOOLEAN, 8, NULL, IEEE_1722_FDF_TSF_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_fdf,
{ "CIP Format Dependent Field", "61883.fdf",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(fdf_rvals), IEEE_1722_FDF_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_syt,
{ "CIP SYT", "61883.syt",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(syt_rvals), 0x00, NULL, HFILL }
},
{ &hf_1722_61883_audio_data,
{ "Audio Data", "61883.audiodata",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_label,
{ "Label", "61883.audiodata.sample.label",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_sample,
{ "Sample", "61883.audiodata.sample.sampledata",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_video_data,
{ "Video Data", "61883.videodata",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_source_packet_header_timestamp,
{ "Source Packet Header Timestamp", "61883.spht",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_1722_61883,
&ett_1722_61883_audio,
&ett_1722_61883_sample,
&ett_1722_61883_video
};
static ei_register_info ei[] = {
{ &ei_1722_61883_incorrect_tag, { "61883.incorrect_tag", PI_PROTOCOL, PI_WARN,
"Incorrect tag field, only 0x00 and 0x01 supported for AVTP", EXPFILL }},
{ &ei_1722_61883_incorrect_tcode, { "61883.incorrect_tcode", PI_PROTOCOL, PI_WARN,
"Incorrect tcode, talker shall set this field to 0x0A", EXPFILL }},
{ &ei_1722_61883_incorrect_qi1, { "61883.incorrect_qi1", PI_PROTOCOL, PI_WARN,
"Incorrect quadlet indicator 1 field, talker shall set this field to 0x00", EXPFILL }},
{ &ei_1722_61883_incorrect_qpc, { "61883.incorrect_qpc", PI_PROTOCOL, PI_WARN,
"Incorrect quadlet padding count field, shall be set to 0", EXPFILL }},
{ &ei_1722_61883_incorrect_qi2, { "61883.incorrect_qi2", PI_PROTOCOL, PI_WARN,
"Incorrect quadlet indicator 2 field, talker shall set this field to 0x02", EXPFILL }},
{ &ei_1722_61883_unknown_format, { "61883.unknown_format", PI_PROTOCOL, PI_NOTE,
"IEC 61883 format not dissected yet", EXPFILL }},
{ &ei_1722_61883_incorrect_channel_sid, { "61883.incorrect_channel_sid", PI_PROTOCOL, PI_WARN,
"1394 Packet Channel and Source ID don`t match", EXPFILL }},
{ &ei_1722_61883_incorrect_datalen, { "61883.incorrect_datalen", PI_PROTOCOL, PI_WARN,
"Incorrect stream data length field, must be multiple of 192 plus 8 bytes CIP header", EXPFILL }},
{ &ei_1722_61883_4_incorrect_cip_fn, { "61883.4_incorrect_cip_fn", PI_PROTOCOL, PI_WARN,
"Incorrect fraction number, shall be 8 for IEC 61883-4", EXPFILL }},
{ &ei_1722_61883_4_incorrect_cip_dbs, { "61883.4_incorrect_cip_dbs", PI_PROTOCOL, PI_WARN,
"Incorrect data block size, shall be 6 for IEC 61883-4", EXPFILL }},
{ &ei_1722_61883_4_incorrect_cip_sph, { "61883.4_incorrect_cip_sph", PI_PROTOCOL, PI_WARN,
"Incorrect source packet header value, shall be 1 for IEC 61883-4", EXPFILL }},
{ &ei_1722_61883_6_incorrect_cip_fn, { "61883.6_incorrect_cip_fn", PI_PROTOCOL, PI_WARN,
"Incorrect fraction number, shall be 0 for IEC 61883-6", EXPFILL }},
{ &ei_1722_61883_6_incorrect_cip_sph, { "61883.6_incorrect_cip_sph", PI_PROTOCOL, PI_WARN,
"Incorrect source packet header value, shall be 0 for IEC 61883-6", EXPFILL }},
{ &ei_1722_61883_incorrect_cip_fdf, { "61883.6_incorrect_cip_fdf", PI_PROTOCOL, PI_WARN,
"Incorrect frame dependent field value, shall be 0", EXPFILL }}
};
expert_module_t* expert_1722_61883;
proto_1722_61883 = proto_register_protocol(
"IEC 61883 Protocol",
"IEC 61883",
"61883");
proto_register_field_array(proto_1722_61883, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_1722_61883 = expert_register_protocol(proto_1722_61883);
expert_register_field_array(expert_1722_61883, ei, array_length(ei));
}
void proto_reg_handoff_1722_61883(void)
{
dissector_handle_t avb1722_61883_handle;
avb1722_61883_handle = create_dissector_handle(dissect_1722_61883, proto_1722_61883);
dissector_add_uint("ieee1722.subtype", IEEE_1722_SUBTYPE_61883, avb1722_61883_handle);
}
static int dissect_1722_aaf (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ti_aaf_tree;
proto_tree *ti_channels_per_frame;
proto_tree *ti_format;
proto_tree *ti_audio_tree;
proto_tree *ti_sample_tree;
gint offset = 1;
guint datalen = 0;
guint channels_per_frame = 0;
guint bit_depth = 0;
guint sample_width = 0;
guint format = 0;
guint i = 0;
guint j = 0;
const gint *fields[] = {
&hf_1722_aaf_mrfield,
&hf_1722_aaf_tvfield,
NULL
};
const gint *fields_pcm[] = {
&hf_1722_aaf_sparse_timestamp,
&hf_1722_aaf_evtfield,
NULL
};
ti = proto_tree_add_item(tree, proto_1722_aaf, tvb, 0, -1, ENC_NA);
ti_aaf_tree = proto_item_add_subtree(ti, ett_1722_aaf);
proto_tree_add_bitmask_list(ti_aaf_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_tufield, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_avtp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti_format = proto_tree_add_item_ret_uint(ti_aaf_tree, hf_1722_aaf_format, tvb, offset, 1, ENC_BIG_ENDIAN, &format);
offset += 1;
switch (format)
{
case IEEE_1722_AAF_FORMAT_USER:
break;
case IEEE_1722_AAF_FORMAT_FLOAT_32_BIT:
sample_width = 32;
break;
case IEEE_1722_AAF_FORMAT_INT_32_BIT:
sample_width = 32;
break;
case IEEE_1722_AAF_FORMAT_INT_24_BIT:
sample_width = 24;
break;
case IEEE_1722_AAF_FORMAT_INT_16_BIT:
sample_width = 16;
break;
case IEEE_1722_AAF_FORMAT_AES3_32_BIT:
sample_width = 32;
break;
default:
break;
}
if (format < IEEE_1722_AAF_FORMAT_AES3_32_BIT)
{
proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_nominal_sample_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
ti_channels_per_frame = proto_tree_add_item_ret_uint(ti_aaf_tree, hf_1722_aaf_channels_per_frame, tvb, offset, 2, ENC_BIG_ENDIAN, &channels_per_frame);
if (channels_per_frame == 0)
{
expert_add_info(pinfo, ti_channels_per_frame, &ei_aaf_channels_per_frame);
}
else
{
offset += 2;
ti = proto_tree_add_item_ret_uint(ti_aaf_tree, hf_1722_aaf_bit_depth, tvb, offset, 1, ENC_BIG_ENDIAN, &bit_depth);
if ((bit_depth == 0) || (bit_depth > sample_width))
{
expert_add_info(pinfo, ti, &ei_aaf_incorrect_bit_depth);
}
offset += 1;
proto_tree_add_item_ret_uint(ti_aaf_tree, hf_1722_aaf_stream_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
offset += 2;
proto_tree_add_bitmask_list(ti_aaf_tree, tvb, offset, 1, fields_pcm, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(ti_aaf_tree, hf_1722_aaf_data, tvb, offset, datalen, ENC_NA);
ti_audio_tree = proto_item_add_subtree(ti, ett_1722_aaf_audio);
if (sample_width == 0)
{
expert_add_info(pinfo, ti, &ei_aaf_sample_width);
}
else
{
for (j = 0; j < ((datalen * 8) / (channels_per_frame * sample_width)); j++)
{
ti_sample_tree = proto_tree_add_subtree_format(ti_audio_tree, tvb, offset, 1,
ett_1722_aaf_sample, NULL, "Sample Chunk %d", j);
for (i = 0; i < channels_per_frame; i++)
{
ti = proto_tree_add_item(ti_sample_tree, hf_1722_aaf_sample, tvb, offset, sample_width / 8, ENC_NA);
proto_item_prepend_text(ti, "Channel: %d ", i);
offset += (sample_width / 8);
}
}
}
}
}
else if (format == IEEE_1722_AAF_FORMAT_AES3_32_BIT)
{
expert_add_info(pinfo, ti_format, &ei_aaf_aes3_format);
}
else
{
expert_add_info(pinfo, ti_format, &ei_aaf_reserved_format);
}
return tvb_captured_length(tvb);
}
void proto_register_1722_aaf (void)
{
static hf_register_info hf[] =
{
{ &hf_1722_aaf_mrfield,
{ "Media Clock Restart", "aaf.mrfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_MR_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_tvfield,
{ "Source Timestamp Valid", "aaf.tvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TV_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_seqnum,
{ "Sequence Number", "aaf.seqnum",
FT_UINT8, BASE_DEC, NULL, IEEE_1722_SEQ_NUM_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_tufield,
{ "Timestamp Uncertain", "aaf.tufield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TU_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_stream_id,
{ "Stream ID", "aaf.stream_id",
FT_UINT64, BASE_HEX, NULL, IEEE_1722_STREAM_ID_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_avtp_timestamp,
{ "AVTP Timestamp", "aaf.avtp_timestamp",
FT_UINT32, BASE_DEC, NULL, IEEE_1722_TIMESTAMP_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_format,
{ "Format", "aaf.format_info",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(aaf_format_range_rvals), IEEE_1722_FORMAT_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_nominal_sample_rate,
{ "Nominal Sample Rate", "aaf.nominal_sample_rate",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(aaf_nominal_sample_rate_range_rvals), IEEE_1722_NOM_SAMPLE_RATE_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_channels_per_frame,
{ "Channels per Frame", "aaf.channels_per_frame",
FT_UINT16, BASE_DEC, NULL, IEEE_1722_CHANNEL_PER_FRAME_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_bit_depth,
{ "Bit Depth", "aaf.bit_depth",
FT_UINT8, BASE_DEC, NULL, IEEE_1722_BIT_DEPTH_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_stream_data_length,
{ "Stream Data Length", "aaf.stream_data_len",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, IEEE_1722_STREAM_DATA_LENGTH_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_sparse_timestamp,
{ "Sparse Timestamp Mode", "aaf.sparse_timestamp",
FT_UINT8, BASE_DEC, VALS(aaf_sparse_timestamp_vals), IEEE_1722_SP_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_evtfield,
{ "EVT", "aaf.evtfield",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_EVT_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_data,
{ "Audio Data", "aaf.data",
FT_BYTES, BASE_NONE, NULL, IEEE_1722_DATA_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_sample,
{ "Sample Data", "aaf.data.sample",
FT_BYTES, BASE_NONE, NULL, IEEE_1722_SAMPLE_MASK, NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_aaf_sample_width, { "aaf.expert.sample_width_zero", PI_PROTOCOL, PI_WARN, "Sample_width of 0 can`t be dissected", EXPFILL }},
{ &ei_aaf_reserved_format, { "aaf.expert.reserved_format", PI_PROTOCOL, PI_WARN, "Incorrect format, can`t be dissected", EXPFILL }},
{ &ei_aaf_aes3_format, { "aaf.expert.aes3_format", PI_PROTOCOL, PI_WARN, "AES3 format is currently not supported", EXPFILL }},
{ &ei_aaf_channels_per_frame, { "aaf.expert.channels_per_frame_zero", PI_PROTOCOL, PI_WARN, "Channels_per_frame value shall not be 0", EXPFILL }},
{ &ei_aaf_incorrect_bit_depth, { "aaf.expert.incorrect_bit_depth", PI_PROTOCOL, PI_WARN, "Incorrect bit_depth value", EXPFILL }}
};
static gint *ett[] =
{
&ett_1722_aaf,
&ett_1722_aaf_audio,
&ett_1722_aaf_sample,
};
expert_module_t *expert_1722_aaf;
proto_1722_aaf = proto_register_protocol("AVTP Audio Format", "AAF", "aaf");
proto_register_field_array(proto_1722_aaf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_1722_aaf = expert_register_protocol(proto_1722_aaf);
expert_register_field_array(expert_1722_aaf, ei, array_length(ei));
}
void proto_reg_handoff_1722_aaf(void)
{
dissector_handle_t avb1722_aaf_handle;
avb1722_aaf_handle = create_dissector_handle(dissect_1722_aaf, proto_1722_aaf);
dissector_add_uint("ieee1722.subtype", IEEE_1722_SUBTYPE_AAF, avb1722_aaf_handle);
}
static int dissect_1722_crf (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ti_crf_tree;
proto_tree *timestamp_tree;
gint offset = 1;
guint datalen = 0;
guint j = 0;
const gint *fields[] = {
&hf_1722_crf_mrfield,
&hf_1722_crf_fsfield,
&hf_1722_crf_tufield,
NULL
};
const gint *pull_frequency[] = {
&hf_1722_crf_pull,
&hf_1722_crf_base_frequency,
NULL
};
ti = proto_tree_add_item(tree, proto_1722_crf, tvb, 0, -1, ENC_NA);
ti_crf_tree = proto_item_add_subtree(ti, ett_1722_crf);
proto_tree_add_bitmask_list(ti_crf_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ti_crf_tree, hf_1722_crf_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_crf_tree, hf_1722_crf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti_crf_tree, hf_1722_crf_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_bitmask_list(ti_crf_tree, tvb, offset, 4, pull_frequency, ENC_NA);
offset += 4;
proto_tree_add_item_ret_uint(ti_crf_tree, hf_1722_crf_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
offset += 2;
proto_tree_add_item(ti_crf_tree, hf_1722_crf_timestamp_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(ti_crf_tree, hf_1722_crf_timestamp_data, tvb, offset, datalen, ENC_NA);
timestamp_tree = proto_item_add_subtree(ti, ett_1722_crf_timestamp);
if (datalen%8)
{
expert_add_info(pinfo, ti, &ei_crf_datalen);
}
else
{
for (j = 0; j < (datalen / IEEE_1722_CRF_TIMESTAMP_SIZE); j++)
{
ti = proto_tree_add_item(timestamp_tree, hf_1722_crf_timestamp, tvb, offset, IEEE_1722_CRF_TIMESTAMP_SIZE, ENC_BIG_ENDIAN);
proto_item_prepend_text(ti, "Timestamp %d ", j);
offset += IEEE_1722_CRF_TIMESTAMP_SIZE;
}
}
return tvb_captured_length(tvb);
}
void proto_register_1722_crf(void)
{
static hf_register_info hf[] =
{
{ &hf_1722_crf_mrfield,
{ "Media Clock Restart", "crf.mrfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_MR_MASK, NULL, HFILL }
},
{ &hf_1722_crf_fsfield,
{ "Frame Sync", "crf.fsfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_FS_MASK, NULL, HFILL }
},
{ &hf_1722_crf_tufield,
{ "Timestamp Uncertain", "crf.tufield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TU_MASK, NULL, HFILL }
},
{ &hf_1722_crf_seqnum,
{ "Sequence Number", "crf.seqnum",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_type,
{ "Type", "crf.type",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(crf_type_range_rvals), 0x00, NULL, HFILL }
},
{ &hf_1722_crf_stream_id,
{ "Stream ID", "crf.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_pull,
{ "Pull", "crf.pull",
FT_UINT32, BASE_HEX | BASE_RANGE_STRING, RVALS(crf_pull_range_rvals), IEEE_1722_PULL_MASK, NULL, HFILL }
},
{ &hf_1722_crf_base_frequency,
{ "Base Frequency", "crf.base_frequency",
FT_UINT32, BASE_DEC, NULL, IEEE_1722_BASE_FREQUENCY_MASK, NULL, HFILL }
},
{ &hf_1722_crf_data_length,
{ "Data Length", "crf.data_len",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_timestamp_interval,
{ "Timestamp Interval", "crf.timestamp_interval",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_timestamp_data,
{ "Timestamp Data", "crf.timestamp_data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_timestamp,
{ "Data", "crf.timestamp",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_crf_datalen, { "crf.expert.crf_datalen", PI_PROTOCOL, PI_WARN, "The CRF data length must be multiple of 8", EXPFILL }}
};
static gint *ett[] =
{
&ett_1722_crf,
&ett_1722_crf_timestamp
};
expert_module_t *expert_1722_crf;
proto_1722_crf = proto_register_protocol("Clock Reference Format", "CRF", "crf");
proto_register_field_array(proto_1722_crf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_1722_crf = expert_register_protocol(proto_1722_crf);
expert_register_field_array(expert_1722_crf, ei, array_length(ei));
}
void proto_reg_handoff_1722_crf(void)
{
dissector_handle_t avb1722_crf_handle;
avb1722_crf_handle = create_dissector_handle(dissect_1722_crf, proto_1722_crf);
dissector_add_uint("ieee1722.subtype", IEEE_1722_SUBTYPE_CRF, avb1722_crf_handle);
}
