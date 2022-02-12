static int dissect_1722_crf (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ieee1722_crf_tree;
proto_tree *timestamp_tree;
gint offset = 1;
guint32 datalen;
guint j;
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
ieee1722_crf_tree = proto_item_add_subtree(ti, ett_1722_crf);
proto_tree_add_bitmask_list(ieee1722_crf_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ieee1722_crf_tree, hf_1722_crf_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_crf_tree, hf_1722_crf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_crf_tree, hf_1722_crf_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_bitmask_list(ieee1722_crf_tree, tvb, offset, 4, pull_frequency, ENC_NA);
offset += 4;
ti = proto_tree_add_item_ret_uint(ieee1722_crf_tree, hf_1722_crf_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
proto_item_append_text(ti, " bytes");
offset += 2;
proto_tree_add_item(ieee1722_crf_tree, hf_1722_crf_timestamp_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(ieee1722_crf_tree, hf_1722_crf_timestamp_data, tvb, offset, datalen, ENC_NA);
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
static int dissect_1722_aaf (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ieee1722_aaf_tree;
proto_tree *audio_tree;
proto_tree *sample_tree;
gint offset = 1;
guint32 datalen;
guint16 channels_per_frame = 0;
gint sample_width = 0;
guint32 format_offset;
guint i, j;
const gint *fields[] = {
&hf_1722_aaf_mrfield,
&hf_1722_aaf_tvfield,
NULL
};
const gint *fields2[] = {
&hf_1722_aaf_nominal_sample_rate,
&hf_1722_aaf_channels_per_frame,
NULL
};
const gint *fields3[] = {
&hf_1722_aaf_sparse_timestamp,
&hf_1722_aaf_evtfield,
NULL
};
ti = proto_tree_add_item(tree, proto_1722_aaf, tvb, 0, -1, ENC_NA);
ieee1722_aaf_tree = proto_item_add_subtree(ti, ett_1722_aaf);
proto_tree_add_bitmask_list(ieee1722_aaf_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_tufield, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_avtp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti = proto_tree_add_item_ret_uint(ieee1722_aaf_tree, hf_1722_aaf_format, tvb, offset, 1, ENC_BIG_ENDIAN, &format_offset);
offset += 1;
switch (format_offset)
{
case 0:
break;
case 1:
sample_width = 32;
break;
case 2:
sample_width = 32;
break;
case 3:
sample_width = 24;
break;
case 4:
sample_width = 16;
break;
case 5:
sample_width = 32;
break;
default:
expert_add_info(pinfo, ti, &ei_format_reserved);
break;
}
proto_tree_add_bitmask_list(ieee1722_aaf_tree, tvb, offset, 2, fields2, ENC_BIG_ENDIAN);
channels_per_frame = tvb_get_ntohs(tvb, offset) & IEEE_1722_CHANNEL_PER_FRAME_MASK;
offset += 2;
proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_bit_depth, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item_ret_uint(ieee1722_aaf_tree, hf_1722_aaf_stream_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
proto_item_append_text(ti, " bytes");
offset += 2;
proto_tree_add_bitmask_list(ieee1722_aaf_tree, tvb, offset, 1, fields3, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(ieee1722_aaf_tree, hf_1722_aaf_data, tvb, offset, datalen, ENC_NA);
audio_tree = proto_item_add_subtree(ti, ett_1722_aaf_audio);
if (sample_width == 0)
{
expert_add_info(pinfo, ti, &ei_sample_width);
}
else
{
if (channels_per_frame == 0)
{
expert_add_info(pinfo, ti, &ei_channels_per_frame);
}
else
{
if (audio_tree)
{
for (j = 0; j < ((datalen * 8) / (channels_per_frame * sample_width)); j++)
{
sample_tree = proto_tree_add_subtree_format(audio_tree, tvb, offset, 1,
ett_1722_aaf_sample, NULL, "Sample Chunk %d", j);
for (i = 0; i < channels_per_frame; i++)
{
ti = proto_tree_add_item(sample_tree, hf_1722_aaf_sample, tvb, offset, sample_width / 8, ENC_NA);
proto_item_prepend_text(ti, "Channel: %d ", i);
offset += (sample_width / 8);
}
}
}
}
}
return tvb_captured_length(tvb);
}
static int dissect_1722_61883(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ieee1722_61883_tree;
proto_tree *audio_tree;
proto_tree *sample_tree;
proto_tree *video_tree;
gint offset = 1;
guint8 dbs, tag, channel, tcode, cip_qi1, cip_sid, cip_qpc, cip_qi2, cip_fmt;
guint32 datalen;
guint db_size, numSourcePackets;
guint i, j;
const gint *fields[] = {
&hf_1722_61883_mrfield,
&hf_1722_61883_gvfield,
&hf_1722_61883_tvfield,
NULL
};
ti = proto_tree_add_item(tree, proto_1722_61883, tvb, 0, -1, ENC_NA);
ieee1722_61883_tree = proto_item_add_subtree(ti, ett_1722_61883);
proto_tree_add_bitmask_list(ieee1722_61883_tree, tvb, offset, 1, fields, ENC_NA);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_tufield, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_stream_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_avtp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_gateway_info, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti = proto_tree_add_item_ret_uint(ieee1722_61883_tree, hf_1722_61883_stream_data_length, tvb, offset, 2, ENC_BIG_ENDIAN, &datalen);
proto_item_append_text(ti, " bytes");
offset += 2;
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, offset) & IEEE_1722_TAG_MASK;
if (tag > 0x40)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_tag);
}
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
channel = tvb_get_guint8(tvb, offset) & IEEE_1722_CHANNEL_MASK;
if (channel != IEEE_1722_61883_CHANNEL_AVTP)
{
proto_item_append_text(ti, ": Originating Source ID from an IEEE 1394 serial bus");
}
else
{
proto_item_append_text(ti, ": Originating source is on AVTP network (native AVTP)");
}
offset += 1;
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_tcode, tvb, offset, 1, ENC_BIG_ENDIAN);
tcode = tvb_get_guint8(tvb, offset) & IEEE_1722_TCODE_MASK;
if (tcode != 0xa0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_tcode);
}
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_sy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag) {
case IEEE_1722_61883_TAG_NO_CIP:
proto_item_prepend_text(ti, "IIDC 1394 video payload:");
break;
case IEEE_1722_61883_TAG_CIP:
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_qi1, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qi1 = tvb_get_guint8(tvb, offset) & IEEE_1722_QI1_MASK;
if (cip_qi1 != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qi1);
}
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_sid, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_sid = tvb_get_guint8(tvb, offset) & IEEE_1722_SID_MASK;
if (cip_sid != IEEE_1722_61883_SID_AVTP)
{
proto_item_append_text(ti, ": Originating Source ID from an IEEE 1394 serial bus");
}
else
{
proto_item_append_text(ti, ": Originating source is on AVTP network");
}
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_dbs, tvb, offset, 1, ENC_BIG_ENDIAN);
dbs = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_fn, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_qpc, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qpc = tvb_get_guint8(tvb, offset) & IEEE_1722_QPC_MASK;
if (cip_qpc != 0)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qpc);
}
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_sph, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_dbc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_qi2, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_qi2 = tvb_get_guint8(tvb, offset) & IEEE_1722_QI2_MASK;
if (cip_qi2 != 0x80)
{
expert_add_info(pinfo, ti, &ei_1722_61883_incorrect_qi2);
}
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_fmt, tvb, offset, 1, ENC_BIG_ENDIAN);
cip_fmt = tvb_get_guint8(tvb, offset) & IEEE_1722_FMT_MASK;
if ((cip_fmt != IEEE_1722_61883_6) && (cip_fmt != IEEE_1722_61883_4))
{
expert_add_info(pinfo, ti, &ei_1722_61883_unknown_format);
}
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_fdf, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_cip_syt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (cip_fmt) {
case IEEE_1722_61883_6:
datalen -= IEEE_1722_CIP_HEADER_SIZE;
if (dbs == 0) {
db_size = 256;
}
else {
db_size = dbs;
}
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_audio_data, tvb, offset, datalen, ENC_NA);
audio_tree = proto_item_add_subtree(ti, ett_1722_61883_audio);
if (audio_tree) {
for (j = 0; j < (datalen / (db_size*4)); j++) {
sample_tree = proto_tree_add_subtree_format(audio_tree, tvb, offset, 1, ett_1722_61883_sample, NULL, "Sample %d", j+1);
for (i = 0; i < db_size; i++) {
proto_tree_add_item(sample_tree, hf_1722_61883_label, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sample_tree, hf_1722_61883_sample, tvb, offset, 3, ENC_NA);
offset += 3;
}
}
}
break;
case IEEE_1722_61883_4:
ti = proto_tree_add_item(ieee1722_61883_tree, hf_1722_61883_video_data, tvb, offset, datalen, ENC_NA);
video_tree = proto_item_add_subtree(ti, ett_1722_61883_audio);
if (video_tree) {
numSourcePackets = datalen / IEEE_1722_61883_4_LEN_SOURCE_PACKET;
for (j = 0; j < numSourcePackets; j++) {
proto_tree_add_item(video_tree, hf_1722_61883_source_packet_header_timestamp, tvb, offset, IEEE_1722_61883_4_LEN_SP_TIMESTAMP, ENC_BIG_ENDIAN);
offset += IEEE_1722_61883_4_LEN_SP_TIMESTAMP;
proto_tree_add_item(video_tree, hf_1722_61883_video_data, tvb, offset, (IEEE_1722_61883_4_LEN_SOURCE_PACKET - IEEE_1722_61883_4_LEN_SP_TIMESTAMP), ENC_NA);
offset += (IEEE_1722_61883_4_LEN_SOURCE_PACKET - IEEE_1722_61883_4_LEN_SP_TIMESTAMP);
}
}
break;
default:
break;
}
break;
default:
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_1722(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *ieee1722_tree;
guint32 subtype;
int offset = 0;
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
FT_UINT8, BASE_HEX, VALS(type_vals), 0x00, NULL, HFILL }
},
{ &hf_1722_crf_stream_id,
{ "Stream ID", "crf.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_crf_pull,
{ "Pull", "crf.pull",
FT_UINT32, BASE_HEX, VALS(pull_vals), IEEE_1722_PULL_MASK, NULL, HFILL }
},
{ &hf_1722_crf_base_frequency,
{ "Base Frequency", "crf.base_frequency",
FT_UINT32, BASE_DEC, NULL, IEEE_1722_BASE_FREQUENCY_MASK, NULL, HFILL }
},
{ &hf_1722_crf_data_length,
{ "Data Length", "crf.data_len",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
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
{ &ei_clock_reference_type, { "crf.expert.clock_reference_format_type", PI_PROTOCOL, PI_WARN, "The CRF type is not supported", EXPFILL }},
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
FT_UINT8, BASE_HEX, VALS(format_info_vals), IEEE_1722_FORMAT_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_nominal_sample_rate,
{ "Nominal Sample Rate", "aaf.nominal_sample_rate",
FT_UINT16, BASE_HEX, VALS(sample_rate_type_vals), IEEE_1722_NOM_SAMPLE_RATE_MASK, NULL, HFILL }
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
FT_UINT16, BASE_DEC, NULL, IEEE_1722_STREAM_DATA_LENGTH_MASK, NULL, HFILL }
},
{ &hf_1722_aaf_sparse_timestamp,
{ "Sparse Timestamp Mode", "aaf.sparse_timestamp",
FT_UINT8, BASE_DEC, VALS(sparse_mode_vals), IEEE_1722_SP_MASK, NULL, HFILL }
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
{ &ei_sample_width, { "aaf.expert.sample_width_zero", PI_PROTOCOL, PI_WARN, "Wrong value for sample width", EXPFILL }},
{ &ei_channels_per_frame, { "aaf.expert.channels_per_frame_zero", PI_PROTOCOL, PI_WARN, "Wrong value for parameter channels per Frame", EXPFILL }},
{ &ei_format_reserved, { "aaf.expert.format_reserved", PI_PROTOCOL, PI_WARN, "Reserved value", EXPFILL }}
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
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
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
FT_UINT8, BASE_HEX, NULL, IEEE_1722_FN_MASK, NULL, HFILL }
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
FT_UINT8, BASE_HEX, VALS(format_vals), IEEE_1722_FMT_MASK, NULL, HFILL }
},
{ &hf_1722_61883_cip_fdf,
{ "CIP Format Dependent Field", "61883.fdf",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_61883_cip_syt,
{ "CIP SYT", "61883.syt",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
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
&ett_1722_61883_sample
};
static ei_register_info ei[] = {
{ &ei_1722_61883_incorrect_tag, { "61883.incorrect_tag", PI_PROTOCOL, PI_WARN, "Incorrect tag field, only 0x00 and 0x01 supported for AVTP", EXPFILL }},
{ &ei_1722_61883_incorrect_tcode, { "61883.incorrect_tcode", PI_PROTOCOL, PI_WARN, "Incorrect tcode, talker shall set this field to 0x0A", EXPFILL }},
{ &ei_1722_61883_incorrect_qi1, { "61883.incorrect_qi1", PI_PROTOCOL, PI_WARN, "Incorrect quadlet indicator 1 field, talker shall set this field to 0x00", EXPFILL }},
{ &ei_1722_61883_incorrect_qpc, { "61883.incorrect_qpc", PI_PROTOCOL, PI_WARN, "Incorrect quadlet padding count field, shall be set to 0", EXPFILL }},
{ &ei_1722_61883_incorrect_qi2, { "61883.incorrect_qi2", PI_PROTOCOL, PI_WARN, "Incorrect quadlet indicator 2 field, talker shall set this field to 0x02", EXPFILL }},
{ &ei_1722_61883_unknown_format, { "61883.unknown_format", PI_PROTOCOL, PI_NOTE, "IEC 61883 format not dissected yet", EXPFILL }}
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
void proto_register_1722(void)
{
static hf_register_info hf[] = {
{ &hf_1722_subtype,
{ "AVBTP Subtype", "ieee1722.subtype",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(ieee1722_subtype_range_vals), IEEE_1722_SUBTYPE_MASK, NULL, HFILL }
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
