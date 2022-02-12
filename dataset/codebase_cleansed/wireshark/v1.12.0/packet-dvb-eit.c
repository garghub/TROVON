static void
dissect_dvb_eit(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0, length = 0;
guint descriptor_len;
guint16 evt_id;
proto_item *ti;
proto_tree *dvb_eit_tree;
proto_item *ei;
proto_tree *dvb_eit_event_tree;
proto_item *duration_item;
nstime_t start_time;
col_set_str(pinfo->cinfo, COL_INFO, "Event Information Table (EIT)");
ti = proto_tree_add_item(tree, proto_dvb_eit, tvb, offset, -1, ENC_NA);
dvb_eit_tree = proto_item_add_subtree(ti, ett_dvb_eit);
offset += packet_mpeg_sect_header(tvb, offset, dvb_eit_tree, &length, NULL);
length -= 4;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_version_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_current_next_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_transport_stream_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_original_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_segment_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_eit_tree, hf_dvb_eit_last_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (offset >= length) {
packet_mpeg_sect_crc(tvb, pinfo, dvb_eit_tree, 0, offset);
return;
}
while (offset < length) {
evt_id = tvb_get_ntohs(tvb, offset);
ei = proto_tree_add_text(dvb_eit_tree, tvb, offset, 12, "Event 0x%04hx", evt_id);
dvb_eit_event_tree = proto_item_add_subtree(ei, ett_dvb_eit_event);
proto_tree_add_item(dvb_eit_event_tree, hf_dvb_eit_event_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_memeql(tvb, offset, "\xFF\xFF\xFF\xFF\xFF", 5)) {
if (packet_mpeg_sect_mjd_to_utc_time(tvb, offset, &start_time) < 0) {
proto_tree_add_text(tree, tvb, offset, 5, "Unparseable time");
} else {
proto_tree_add_time(dvb_eit_event_tree, hf_dvb_eit_start_time, tvb, offset,
5, &start_time);
}
} else {
proto_tree_add_text(tree, tvb, offset, 5, "Start Time: Undefined (0xFFFFFFFFFF)");
}
offset += 5;
duration_item = proto_tree_add_item(dvb_eit_event_tree, hf_dvb_eit_duration, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(duration_item, " (%02u:%02u:%02u)",
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)),
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset + 1)),
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset + 2)));
offset += 3;
proto_tree_add_item(dvb_eit_event_tree, hf_dvb_eit_running_status, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_eit_event_tree, hf_dvb_eit_free_ca_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_eit_event_tree, hf_dvb_eit_descriptors_loop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
descriptor_len = tvb_get_ntohs(tvb, offset) & DVB_EIT_DESCRIPTORS_LOOP_LENGTH_MASK;
offset += 2;
offset += proto_mpeg_descriptor_loop_dissect(tvb, offset, descriptor_len, dvb_eit_event_tree);
}
offset += packet_mpeg_sect_crc(tvb, pinfo, dvb_eit_tree, 0, offset);
proto_item_set_len(ti, offset);
}
void
proto_register_dvb_eit(void)
{
static hf_register_info hf[] = {
{ &hf_dvb_eit_service_id, {
"Service ID", "dvb_eit.sid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_reserved, {
"Reserved", "dvb_eit.reserved",
FT_UINT8, BASE_HEX, NULL, DVB_EIT_RESERVED_MASK, NULL, HFILL
} },
{ &hf_dvb_eit_version_number, {
"Version Number", "dvb_eit.version",
FT_UINT8, BASE_HEX, NULL, DVB_EIT_VERSION_NUMBER_MASK, NULL, HFILL
} },
{ &hf_dvb_eit_current_next_indicator, {
"Current/Next Indicator", "dvb_eit.cur_next_ind",
FT_UINT8, BASE_DEC, VALS(dvb_eit_cur_next_vals), DVB_EIT_CURRENT_NEXT_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_dvb_eit_section_number, {
"Section Number", "dvb_eit.sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_last_section_number, {
"Last Section Number", "dvb_eit.last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_transport_stream_id, {
"Transport Stream ID", "dvb_eit.tsid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_original_network_id, {
"Original Network ID", "dvb_eit.original_nid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_segment_last_section_number, {
"Segment Last Section Number", "dvb_eit.segment_last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_last_table_id, {
"Last Table ID", "dvb_eit.last_tid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_event_id, {
"Event ID", "dvb_eit.evt.id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_start_time, {
"UTC Start Time", "dvb_eit.evt.start_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_duration, {
"Duration", "dvb_eit.evt.duration",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_eit_running_status, {
"Running Status", "dvb_eit.evt.running_status",
FT_UINT16, BASE_HEX, VALS(dvb_eit_running_status_vals), DVB_EIT_RUNNING_STATUS_MASK, NULL, HFILL
} },
{ &hf_dvb_eit_free_ca_mode, {
"Free CA Mode", "dvb_eit.evt.free_ca_mode",
FT_UINT16, BASE_HEX, VALS(dvb_eit_free_ca_mode_vals), DVB_EIT_FREE_CA_MODE_MASK, NULL, HFILL
} },
{ &hf_dvb_eit_descriptors_loop_length, {
"Descriptors Loop Length", "dvb_eit.evt.descr_loop_len",
FT_UINT16, BASE_HEX, NULL, DVB_EIT_DESCRIPTORS_LOOP_LENGTH_MASK, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_dvb_eit,
&ett_dvb_eit_event
};
proto_dvb_eit = proto_register_protocol("DVB Event Information Table", "DVB EIT", "dvb_eit");
proto_register_field_array(proto_dvb_eit, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dvb_eit(void)
{
int tid;
dissector_handle_t dvb_eit_handle;
dvb_eit_handle = create_dissector_handle(dissect_dvb_eit, proto_dvb_eit);
for (tid = DVB_EIT_TID_MIN; tid <= DVB_EIT_TID_MAX; tid++)
dissector_add_uint("mpeg_sect.tid", tid, dvb_eit_handle);
}
