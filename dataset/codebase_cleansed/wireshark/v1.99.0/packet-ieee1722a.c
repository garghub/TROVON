static void dissect_1722a (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *ieee1722a_tree = NULL;
proto_tree *audio_tree = NULL;
proto_tree *sample_tree = NULL;
proto_tree *timestamp_tree = NULL;
gint offset = 0;
guint16 datalen = 0;
guint16 channels_per_frame = 0;
guint8 subtype = 0;
gint sample_width = 0;
int i, j;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE1722a");
col_set_str(pinfo->cinfo, COL_INFO, "AVB Transportation Protocol");
if (tree)
{
ti = proto_tree_add_item(tree, proto_1722a, tvb, 0, -1, ENC_NA);
ieee1722a_tree = proto_item_add_subtree(ti, ett_1722a);
}
subtype = tvb_get_guint8(tvb, IEEE_1722A_CD_OFFSET);
subtype &= IEEE_1722A_SUBTYPE_MASK;
switch (subtype)
{
case IEEE_1722A_SUBTYPE_AVTP_AUDIO:
if (tree)
{
proto_tree_add_item(ieee1722a_tree, hf_1722a_mrfield, tvb, IEEE_1722A_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_tvfield, tvb, IEEE_1722A_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_seqnum, tvb, IEEE_1722A_SEQ_NUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_tufield, tvb, IEEE_1722A_TU_FIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_stream_id, tvb, IEEE_1722A_STREAM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_avbtp_timestamp, tvb, IEEE_1722A_TIMESTAMP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_format_info, tvb, IEEE_1722A_FORMAT_INFO_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_nominal_sample_rate, tvb, IEEE_1722A_NOM_SAMPLE_RATE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_channels_per_frame, tvb, IEEE_1722A_CHANNELS_PER_FRAME_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_bit_depth, tvb, IEEE_1722A_BIT_DEPTH_OFFSET, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(ieee1722a_tree, hf_1722a_stream_data_length, tvb, IEEE_1722A_STREAM_DATA_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " bytes");
proto_tree_add_item(ieee1722a_tree, hf_1722a_sparse_timestamp, tvb, IEEE_1722A_SPARSE_TIMESTAMP_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_evtfield, tvb, IEEE_1722A_EVT_OFFSET, 1, ENC_BIG_ENDIAN);
}
datalen = tvb_get_ntohs(tvb, IEEE_1722A_STREAM_DATA_LENGTH_OFFSET);
ti = proto_tree_add_item(ieee1722a_tree, hf_1722a_data, tvb, IEEE_1722A_DATA_OFFSET, datalen, ENC_NA);
audio_tree = proto_item_add_subtree(ti, ett_1722a_audio);
offset = IEEE_1722A_DATA_OFFSET;
channels_per_frame = tvb_get_ntohs(tvb, IEEE_1722A_CHANNELS_PER_FRAME_OFFSET);
channels_per_frame &= IEEE_1722A_CHANNEL_PER_FRAME_MASK;
switch (tvb_get_guint8(tvb, IEEE_1722A_FORMAT_INFO_OFFSET))
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
default:
expert_add_info(pinfo, ti, &ei_format_info);
break;
}
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
if (tree)
{
for (j = 0; j < ((datalen * 8) / (channels_per_frame * sample_width)); j++)
{
sample_tree = proto_tree_add_subtree_format(audio_tree, tvb, offset, 1,
ett_1722a_sample, &ti, "Sample Chunk %d", j);
for (i = 0; i < channels_per_frame; i++)
{
ti = proto_tree_add_item(sample_tree, hf_1722a_sample, tvb, offset, sample_width / 8, ENC_NA);
proto_item_prepend_text(ti, "Channel: %d ", i);
offset += (sample_width / 8);
}
}
}
}
}
break;
case IEEE_1722A_SUBTYPE_CRF:
proto_tree_add_item(ieee1722a_tree, hf_1722a_mrfield, tvb, IEEE_1722A_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_tvfield, tvb, IEEE_1722A_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_seqnum, tvb, IEEE_1722A_SEQ_NUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_tufield, tvb, IEEE_1722A_TU_FIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_stream_id, tvb, IEEE_1722A_STREAM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(ieee1722a_tree, hf_1722a_stream_data_length, tvb, IEEE_1722A_STREAM_DATA_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " bytes");
proto_tree_add_item(ieee1722a_tree, hf_1722a_crf_type, tvb, IEEE_1722A_CRF_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
switch (tvb_get_ntohs(tvb, IEEE_1722A_CRF_TYPE_OFFSET))
{
case IEEE_1722A_CRF_AUDIO_SAMPLE_TIMESTAMP:
if (tree)
{
proto_tree_add_item(ieee1722a_tree, hf_1722a_clock_frequency, tvb, IEEE_1722A_CRF_CLOCK_FREQUENCY_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_clock_multiplier, tvb, IEEE_1722A_CRF_CLOCK_MULTIPLIER_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722a_tree, hf_1722a_timestamp_interval, tvb, IEEE_1722A_CRF_TIMESTAMP_INTERVAL_OFFSET, 2, ENC_BIG_ENDIAN);
datalen = tvb_get_ntohs(tvb, IEEE_1722A_STREAM_DATA_LENGTH_OFFSET);
datalen = datalen - 6;
ti = proto_tree_add_item(ieee1722a_tree, hf_1722a_crf_timestamp, tvb, IEEE_1722A_CRF_AUDIO_TIMESTAMP_OFFSET, datalen, ENC_NA);
timestamp_tree = proto_item_add_subtree(ti, ett_1722a_crf_timestamp);
offset = IEEE_1722A_CRF_AUDIO_TIMESTAMP_OFFSET;
for (j = 0; j < (datalen / IEEE_1722A_CRF_TIMESTAMP_SIZE); j++)
{
proto_tree_add_item(timestamp_tree, hf_1722a_crf_timestamp_data, tvb, offset, IEEE_1722A_CRF_TIMESTAMP_SIZE, ENC_BIG_ENDIAN);
offset += IEEE_1722A_CRF_TIMESTAMP_SIZE;
}
}
break;
default:
expert_add_info(pinfo, ti, &ei_clock_reference_type);
break;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
void proto_register_1722a (void)
{
expert_module_t *expert_1722a;
static hf_register_info hf[] =
{
{ &hf_1722a_mrfield,
{ "AVBTP Media Clock Restart", "ieee1722a.mrfield",
FT_BOOLEAN, 8, NULL, IEEE_1722A_MR_MASK, NULL, HFILL }
},
{ &hf_1722a_tvfield,
{ "Source Timestamp Valid", "ieee1722a.tvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722A_TV_MASK, NULL, HFILL }
},
{ &hf_1722a_seqnum,
{ "Sequence Number", "ieee1722a.seqnum",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_tufield,
{ "AVBTP Timestamp Uncertain", "ieee1722a.tufield",
FT_BOOLEAN, 8, NULL, IEEE_1722A_TU_MASK, NULL, HFILL }
},
{ &hf_1722a_stream_id,
{ "Stream ID", "ieee1722a.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_avbtp_timestamp,
{ "AVBTP Timestamp", "ieee1722a.avbtp_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_format_info,
{ "Format Info", "ieee1722a.format_info",
FT_UINT8, BASE_HEX, VALS(format_info_vals), 0x00, NULL, HFILL }
},
{ &hf_1722a_nominal_sample_rate,
{ "Nominal Sample Rate", "ieee1722a.nominal_sample_rate",
FT_UINT8, BASE_HEX, VALS(sample_rate_type_vals), IEEE_1722A_NOM_SAMPLE_RATE_MASK, NULL, HFILL }
},
{ &hf_1722a_bit_depth,
{ "Bit Depth", "ieee1722a.bit_depth",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_stream_data_length,
{ "Stream Data Length", "ieee1722a.stream_data_len",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_sparse_timestamp,
{ "Sparse Timestamp Mode", "ieee1722a.sparse_timestamp",
FT_BOOLEAN, 8, NULL, IEEE_1722A_SP_MASK, NULL, HFILL }
},
{ &hf_1722a_evtfield,
{ "EVT", "ieee1722a.evtfield",
FT_UINT8, BASE_HEX, NULL, IEEE_1722A_EVT_MASK, NULL, HFILL }
},
{ &hf_1722a_channels_per_frame,
{ "Channels per Frame", "ieee1722a.channels_per_frame",
FT_UINT16, BASE_DEC, NULL, IEEE_1722A_CHANNEL_PER_FRAME_MASK, NULL, HFILL }
},
{ &hf_1722a_data,
{ "Audio Data", "ieee1722a.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_sample,
{ "Sample Data", "ieee1722a.data.sample.sampledata",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_crf_type,
{ "Type", "ieee1722a.type",
FT_UINT16, BASE_HEX, VALS(clock_reference_format_type_vals), 0x00, NULL, HFILL }
},
{ &hf_1722a_clock_frequency,
{ "Clock Frequency", "ieee1722a.clock_frequency",
FT_UINT8, BASE_HEX, VALS(clock_frequency_type_vals), 0x00, NULL, HFILL }
},
{ &hf_1722a_clock_multiplier,
{ "Clock Multiplier", "ieee1722a.clock_multiplier",
FT_UINT8, BASE_HEX, VALS(clock_multiplier_type_vals), 0x00, NULL, HFILL }
},
{ &hf_1722a_timestamp_interval,
{ "Timestamp Interval", "ieee1722a.timestamp_interval",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_crf_timestamp,
{ "Timestamps", "ieee1722a.crf_timestamps",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722a_crf_timestamp_data,
{ "Timestamp Data", "ieee1722a.crf_timestamp_data",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_sample_width, { "1722a.expert.sample_width_zero", PI_PROTOCOL, PI_WARN, "Wrong value for Sample Width", EXPFILL }},
{ &ei_channels_per_frame, { "1722a.expert.channels_per_frame_zero", PI_PROTOCOL, PI_WARN, "Wrong value for parameter Channels per Frame", EXPFILL }},
{ &ei_unknown_parameter, { "1722a.expert.unknown_parameter", PI_PROTOCOL, PI_WARN, "Unknown parameter", EXPFILL }},
{ &ei_format_info, { "1722a.expert.format_info", PI_PROTOCOL, PI_WARN, "Format Info Value Reserved", EXPFILL }},
{ &ei_clock_reference_type, { "1722a.expert.clock_reference_format_type", PI_PROTOCOL, PI_WARN, "The CRF type is not supported", EXPFILL }}
};
static gint *ett[] =
{
&ett_1722a,
&ett_1722a_audio,
&ett_1722a_sample,
&ett_1722a_crf_timestamp
};
proto_1722a = proto_register_protocol(
"IEEE 1722a Protocol",
"1722A",
"1722a"
);
proto_register_field_array(proto_1722a, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_1722a = expert_register_protocol(proto_1722a);
expert_register_field_array(expert_1722a, ei, array_length(ei));
}
void proto_reg_handoff_1722a(void)
{
dissector_handle_t avb1722a_handle;
avb1722a_handle = create_dissector_handle(dissect_1722a, proto_1722a);
dissector_add_uint("ieee1722.subtype", IEEE_1722A_SUBTYPE_AVTP_AUDIO, avb1722a_handle);
dissector_add_uint("ieee1722.subtype", IEEE_1722A_SUBTYPE_CRF, avb1722a_handle);
}
