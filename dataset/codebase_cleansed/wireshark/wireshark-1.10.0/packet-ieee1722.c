static void
dissect_1722(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *ieee1722_tree = NULL;
proto_tree *audio_tree;
proto_tree *sample_tree;
gint offset;
guint16 datalen;
guint8 dbs;
guint8 subtype;
int i, j;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE1722");
col_set_str(pinfo->cinfo, COL_INFO, "AVB Transportation Protocol");
if (tree) {
ti = proto_tree_add_item(tree, proto_1722, tvb, 0, -1, ENC_NA);
ieee1722_tree = proto_item_add_subtree(ti, ett_1722);
proto_tree_add_item(ieee1722_tree, hf_1722_cdfield, tvb, IEEE_1722_CD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_subtype, tvb, IEEE_1722_CD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_svfield, tvb, IEEE_1722_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_verfield, tvb, IEEE_1722_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
}
subtype = tvb_get_guint8(tvb, IEEE_1722_CD_OFFSET);
subtype &= 0x7F;
if (dissector_try_uint(avb_dissector_table, subtype, tvb, pinfo, tree)) return;
if (tree) {
proto_tree_add_item(ieee1722_tree, hf_1722_mrfield, tvb, IEEE_1722_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_gvfield, tvb, IEEE_1722_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_tvfield, tvb, IEEE_1722_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_seqnum, tvb,
IEEE_1722_SEQ_NUM_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_tufield, tvb,
IEEE_1722_TU_FIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_stream_id, tvb,
IEEE_1722_STREAM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_avbtp_timestamp, tvb,
IEEE_1722_TIMESTAMP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_gateway_info, tvb,
IEEE_1722_GW_INFO_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_packet_data_length, tvb,
IEEE_1722_PKT_DATA_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_tag, tvb,
IEEE_1722_TAG_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_channel, tvb,
IEEE_1722_TAG_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_tcode, tvb,
IEEE_1722_TCODE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_sy, tvb,
IEEE_1722_TCODE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_sid, tvb,
IEEE_1722_SID_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_dbs, tvb,
IEEE_1722_DBS_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_fn, tvb,
IEEE_1722_FN_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_qpc, tvb,
IEEE_1722_FN_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_sph, tvb,
IEEE_1722_FN_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_dbc, tvb,
IEEE_1722_DBC_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_fmt, tvb,
IEEE_1722_FMT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_fdf, tvb,
IEEE_1722_FDF_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ieee1722_tree, hf_1722_syt, tvb,
IEEE_1722_SYT_OFFSET, 2, ENC_BIG_ENDIAN);
datalen = tvb_get_ntohs(tvb, IEEE_1722_PKT_DATA_LENGTH_OFFSET);
datalen -= IEEE_1722_CIP_HEADER_SIZE;
ti = proto_tree_add_item(ieee1722_tree, hf_1722_data, tvb,
IEEE_1722_DATA_OFFSET, datalen, ENC_NA);
audio_tree = proto_item_add_subtree(ti, ett_1722_audio);
offset = IEEE_1722_DATA_OFFSET;
dbs = tvb_get_guint8(tvb, IEEE_1722_DBS_OFFSET);
if(dbs == 0)
proto_tree_add_text(ieee1722_tree, tvb, IEEE_1722_DATA_OFFSET, datalen, "Incorrect DBS");
else {
for (j = 0; j < (datalen / (dbs*4)); j++) {
ti = proto_tree_add_text(audio_tree, tvb, offset, 1, "Sample %d", j+1);
sample_tree = proto_item_add_subtree(ti, ett_1722_sample);
for (i = 0; i < dbs; i++) {
proto_tree_add_item(sample_tree, hf_1722_label, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sample_tree, hf_1722_sample, tvb, offset, 3, ENC_NA);
offset += 3;
}
}
}
}
}
void proto_register_1722(void)
{
static hf_register_info hf[] = {
{ &hf_1722_cdfield,
{ "Control/Data Indicator", "ieee1722.cdfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_CD_MASK, NULL, HFILL }
},
{ &hf_1722_subtype,
{ "AVBTP Subtype", "ieee1722.subtype",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_SUBTYPE_MASK, NULL, HFILL }
},
{ &hf_1722_svfield,
{ "AVBTP Stream ID Valid", "ieee1722.svfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_SV_MASK, NULL, HFILL }
},
{ &hf_1722_verfield,
{ "AVBTP Version", "ieee1722.verfield",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_VER_MASK, NULL, HFILL }
},
{ &hf_1722_mrfield,
{ "AVBTP Media Reset", "ieee1722.mrfield",
FT_UINT8, BASE_DEC, NULL, IEEE_1722_MR_MASK, NULL, HFILL }
},
{ &hf_1722_gvfield,
{ "AVBTP Gateway Info Valid", "ieee1722.gvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_GV_MASK, NULL, HFILL }
},
{ &hf_1722_tvfield,
{ "Source Timestamp Valid", "ieee1722.tvfield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TV_MASK, NULL, HFILL }
},
{ &hf_1722_seqnum,
{ "Sequence Number", "ieee1722.seqnum",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_tufield,
{ "AVBTP Timestamp Uncertain", "ieee1722.tufield",
FT_BOOLEAN, 8, NULL, IEEE_1722_TU_MASK, NULL, HFILL }
},
{ &hf_1722_stream_id,
{ "Stream ID", "ieee1722.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_avbtp_timestamp,
{ "AVBTP Timestamp", "ieee1722.avbtp_timestamp",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_gateway_info,
{ "Gateway Info", "ieee1722.gateway_info",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_packet_data_length,
{ "1394 Packet Data Length", "ieee1722.packet_data_len",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_tag,
{ "1394 Packet Format Tag", "ieee1722.tag",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_TAG_MASK, NULL, HFILL }
},
{ &hf_1722_channel,
{ "1394 Packet Channel", "ieee1722.channel",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_CHANNEL_MASK, NULL, HFILL }
},
{ &hf_1722_tcode,
{ "1394 Packet Tcode", "ieee1722.tcode",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_TCODE_MASK, NULL, HFILL }
},
{ &hf_1722_sy,
{ "1394 App-specific Control", "ieee1722.sy",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_SY_MASK, NULL, HFILL }
},
{ &hf_1722_sid,
{ "Source ID", "ieee1722.sid",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_SID_MASK, NULL, HFILL }
},
{ &hf_1722_dbs,
{ "Data Block Size", "ieee1722.dbs",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_fn,
{ "Fraction Number", "ieee1722.fn",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_FN_MASK, NULL, HFILL }
},
{ &hf_1722_qpc,
{ "Quadlet Padding Count", "ieee1722.qpc",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_QPC_MASK, NULL, HFILL }
},
{ &hf_1722_sph,
{ "Source Packet Header", "ieee1722.sph",
FT_BOOLEAN, 8, NULL, IEEE_1722_SPH_MASK, NULL, HFILL }
},
{ &hf_1722_dbc,
{ "Data Block Continuity", "ieee1722.dbc",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_fmt,
{ "Format ID", "ieee1722.fmt",
FT_UINT8, BASE_HEX, NULL, IEEE_1722_FMT_MASK, NULL, HFILL }
},
{ &hf_1722_fdf,
{ "Format Dependent Field", "ieee1722.fdf",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_syt,
{ "SYT", "ieee1722.syt",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_data,
{ "Audio Data", "ieee1722.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_label,
{ "Label", "ieee1722.data.sample.label",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_1722_sample,
{ "Sample", "ieee1722.data.sample.sampledata",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_1722,
&ett_1722_audio,
&ett_1722_sample
};
proto_1722 = proto_register_protocol("IEEE 1722 Protocol", "IEEE1722", "ieee1722");
proto_register_field_array(proto_1722, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
avb_dissector_table = register_dissector_table("ieee1722.subtype",
"AVBTP Subtype", FT_UINT8, BASE_HEX);
}
void proto_reg_handoff_1722(void)
{
dissector_handle_t avbtp_handle;
avbtp_handle = create_dissector_handle(dissect_1722, proto_1722);
dissector_add_uint("ethertype", ETHERTYPE_AVBTP, avbtp_handle);
}
