static void
dissect_dvb_sdt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0, length = 0;
guint descriptor_len;
guint16 svc_id;
proto_item *ti;
proto_tree *dvb_sdt_tree;
proto_item *si;
proto_tree *dvb_sdt_service_tree;
col_set_str(pinfo->cinfo, COL_INFO, "Service Description Table (SDT)");
ti = proto_tree_add_item(tree, proto_dvb_sdt, tvb, offset, -1, ENC_NA);
dvb_sdt_tree = proto_item_add_subtree(ti, ett_dvb_sdt);
offset += packet_mpeg_sect_header(tvb, offset, dvb_sdt_tree, &length, NULL);
length -= 4;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_transport_stream_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_version_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_current_next_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_original_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_sdt_tree, hf_dvb_sdt_reserved2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (offset >= length)
return;
while (offset < length) {
svc_id = tvb_get_ntohs(tvb, offset);
si = proto_tree_add_text(dvb_sdt_tree, tvb, offset, 5, "Service 0x%04hx", svc_id);
dvb_sdt_service_tree = proto_item_add_subtree(si, ett_dvb_sdt_service);
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_reserved3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_eit_schedule_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_eit_present_following_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_running_status, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_free_ca_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dvb_sdt_service_tree, hf_dvb_sdt_descriptors_loop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
descriptor_len = tvb_get_ntohs(tvb, offset) & DVB_SDT_DESCRIPTORS_LOOP_LENGTH_MASK;
offset += 2;
offset += proto_mpeg_descriptor_loop_dissect(tvb, offset, descriptor_len, dvb_sdt_service_tree);
}
offset += packet_mpeg_sect_crc(tvb, pinfo, dvb_sdt_tree, 0, offset);
proto_item_set_len(ti, offset);
}
void
proto_register_dvb_sdt(void)
{
static hf_register_info hf[] = {
{ &hf_dvb_sdt_transport_stream_id, {
"Transport Stream ID", "dvb_sdt.tsid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_reserved1, {
"Reserved", "dvb_sdt.reserved1",
FT_UINT8, BASE_HEX, NULL, DVB_SDT_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_version_number, {
"Version Number", "dvb_sdt.version",
FT_UINT8, BASE_HEX, NULL, DVB_SDT_VERSION_NUMBER_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_current_next_indicator, {
"Current/Next Indicator", "dvb_sdt.cur_next_ind",
FT_UINT8, BASE_DEC, VALS(dvb_sdt_cur_next_vals), DVB_SDT_CURRENT_NEXT_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_section_number, {
"Section Number", "dvb_sdt.sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_last_section_number, {
"Last Section Number", "dvb_sdt.last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_original_network_id, {
"Original Network ID", "dvb_sdt.original_nid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_reserved2, {
"Reserved", "dvb_sdt.reserved2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_service_id, {
"Service ID", "dvb_sdt.svc.id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dvb_sdt_reserved3, {
"Reserved", "dvb_sdt.svc.reserved",
FT_UINT8, BASE_HEX, NULL, DVB_SDT_RESERVED3_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_eit_schedule_flag, {
"EIT Schedule Flag", "dvb_sdt.svc.eit_schedule_flag",
FT_UINT8, BASE_DEC, NULL, DVB_SDT_EIT_SCHEDULE_FLAG_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_eit_present_following_flag, {
"EIT Present Following Flag", "dvb_sdt.svc.eit_present_following_flag",
FT_UINT8, BASE_DEC, NULL, DVB_SDT_EIT_PRESENT_FOLLOWING_FLAG_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_running_status, {
"Running Status", "dvb_sdt.svc.running_status",
FT_UINT16, BASE_HEX, VALS(dvb_sdt_running_status_vals), DVB_SDT_RUNNING_STATUS_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_free_ca_mode, {
"Free CA Mode", "dvb_sdt.svc.free_ca_mode",
FT_UINT16, BASE_HEX, VALS(dvb_sdt_free_ca_mode_vals), DVB_SDT_FREE_CA_MODE_MASK, NULL, HFILL
} },
{ &hf_dvb_sdt_descriptors_loop_length, {
"Descriptors Loop Length", "dvb_sdt.svc.descr_loop_len",
FT_UINT16, BASE_HEX, NULL, DVB_SDT_DESCRIPTORS_LOOP_LENGTH_MASK, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_dvb_sdt,
&ett_dvb_sdt_service
};
proto_dvb_sdt = proto_register_protocol("DVB Service Description Table", "DVB SDT", "dvb_sdt");
proto_register_field_array(proto_dvb_sdt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dvb_sdt(void)
{
dissector_handle_t dvb_sdt_handle;
dvb_sdt_handle = create_dissector_handle(dissect_dvb_sdt, proto_dvb_sdt);
dissector_add_uint("mpeg_sect.tid", DVB_SDT_TID_ACTUAL, dvb_sdt_handle);
dissector_add_uint("mpeg_sect.tid", DVB_SDT_TID_OTHER, dvb_sdt_handle);
}
