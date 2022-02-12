static void
dissect_mpeg_pmt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0, length = 0, descriptor_end = 0;
guint16 prog_info_len = 0, es_info_len = 0, pid = 0;
proto_item *ti = NULL;
proto_tree *mpeg_pmt_tree = NULL;
proto_item *si = NULL;
proto_tree *mpeg_pmt_stream_tree = NULL;
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_INFO, "Program Map Table (PMT)");
if (!tree)
return;
ti = proto_tree_add_item(tree, proto_mpeg_pmt, tvb, offset, -1, ENC_NA);
mpeg_pmt_tree = proto_item_add_subtree(ti, ett_mpeg_pmt);
offset += packet_mpeg_sect_header(tvb, offset, mpeg_pmt_tree, &length, NULL);
length -= 4;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_program_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_version_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_current_next_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_pcr_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
prog_info_len = tvb_get_ntohs(tvb, offset) & MPEG_PMT_PROGRAM_INFO_LENGTH_MASK;
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_reserved3, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_tree, hf_mpeg_pmt_program_info_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
descriptor_end = offset + prog_info_len;
while (offset < descriptor_end)
offset += proto_mpeg_descriptor_dissect(tvb, offset, mpeg_pmt_tree);
while (offset < length) {
pid = tvb_get_ntohs(tvb, offset + 1) & MPEG_PMT_STREAM_ELEMENTARY_PID_MASK;
es_info_len = tvb_get_ntohs(tvb, offset + 3) & MPEG_PMT_STREAM_ES_INFO_LENGTH_MASK;
si = proto_tree_add_text(mpeg_pmt_tree, tvb, offset, 5 + es_info_len, "Stream PID=0x%04hx", pid);
mpeg_pmt_stream_tree = proto_item_add_subtree(si, ett_mpeg_pmt_stream);
proto_tree_add_item(mpeg_pmt_stream_tree, hf_mpeg_pmt_stream_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(mpeg_pmt_stream_tree, hf_mpeg_pmt_stream_reserved1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_stream_tree, hf_mpeg_pmt_stream_elementary_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mpeg_pmt_stream_tree, hf_mpeg_pmt_stream_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpeg_pmt_stream_tree, hf_mpeg_pmt_stream_es_info_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
descriptor_end = offset + es_info_len;
while (offset < descriptor_end)
offset += proto_mpeg_descriptor_dissect(tvb, offset, mpeg_pmt_stream_tree);
}
packet_mpeg_sect_crc(tvb, pinfo, mpeg_pmt_tree, 0, offset);
}
void
proto_register_mpeg_pmt(void)
{
static hf_register_info hf[] = {
{ &hf_mpeg_pmt_program_number, {
"Program Number", "mpeg_pmt.pg_num",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_pmt_reserved1, {
"Reserved", "mpeg_pmt.reserved1",
FT_UINT8, BASE_HEX, NULL, MPEG_PMT_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_version_number, {
"Version Number", "mpeg_pmt.version",
FT_UINT8, BASE_HEX, NULL, MPEG_PMT_VERSION_NUMBER_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_current_next_indicator, {
"Current/Next Indicator", "mpeg_pmt.cur_next_ind",
FT_UINT8, BASE_HEX, VALS(mpeg_pmt_cur_next_vals), MPEG_PMT_CURRENT_NEXT_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_section_number, {
"Section Number", "mpeg_pmt.sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_pmt_last_section_number, {
"Last Section Number", "mpeg_pmt.last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_pmt_reserved2, {
"Reserved", "mpeg_pmt.reserved2",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_pcr_pid, {
"PCR PID", "mpeg_pmt.pcr_pid",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_PCR_PID_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_reserved3, {
"Reserved", "mpeg_pmt.reserved3",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_RESERVED3_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_program_info_length, {
"Program Info Length", "mpeg_pmt.prog_info_len",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_PROGRAM_INFO_LENGTH_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_stream_type, {
"Stream type", "mpeg_pmt.stream.type",
FT_UINT8, BASE_HEX, VALS(mpeg_pmt_stream_type_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_pmt_stream_reserved1, {
"Reserved", "mpeg_pmt.stream.reserved1",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_STREAM_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_stream_elementary_pid, {
"Elementary PID", "mpeg_pmt.stream.elementary_pid",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_STREAM_ELEMENTARY_PID_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_stream_reserved2, {
"Reserved", "mpeg_pmt.stream.reserved2",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_STREAM_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_mpeg_pmt_stream_es_info_length, {
"ES Info Length", "mpeg_pmt.stream.es_info_len",
FT_UINT16, BASE_HEX, NULL, MPEG_PMT_STREAM_ES_INFO_LENGTH_MASK, NULL, HFILL
} },
};
static gint *ett[] = {
&ett_mpeg_pmt,
&ett_mpeg_pmt_stream,
};
proto_mpeg_pmt = proto_register_protocol("MPEG2 Program Map Table", "MPEG PMT", "mpeg_pmt");
proto_register_field_array(proto_mpeg_pmt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mpeg_pmt(void)
{
dissector_handle_t mpeg_pmt_handle;
mpeg_pmt_handle = create_dissector_handle(dissect_mpeg_pmt, proto_mpeg_pmt);
dissector_add_uint("mpeg_sect.tid", MPEG_PMT_TID, mpeg_pmt_handle);
}
