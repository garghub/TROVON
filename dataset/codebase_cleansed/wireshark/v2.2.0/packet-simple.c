static void dissect_simple_link16(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint subtype, stn, word_count, i;
Link16State state;
tvbuff_t *newtvb;
proto_tree_add_item(tree, hf_simple_link16_subtype, tvb, offset, 1, ENC_NA);
subtype = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_simple_link16_rc, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_link16_network, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_link16_ssc2, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_link16_npg, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_simple_link16_ssc1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_simple_link16_stn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
stn = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_simple_link16_word_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
word_count = tvb_get_guint8(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_simple_link16_loopback_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", STN: %05o, Words:", stn);
switch(subtype) {
case SIMPLE_LINK16_FIXED_FORMAT:
memset(&state, 0, sizeof(state));
for (i = 0; i < word_count; i += 5) {
newtvb = tvb_new_subset(tvb, offset, 10, -1);
add_new_data_source(pinfo, newtvb, "Link 16 Word");
call_dissector_with_data(link16_handle, newtvb, pinfo, tree, &state);
offset += 10;
}
break;
}
}
static void dissect_simple_status(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
char *name;
int link16_status, pu;
proto_tree_add_item(tree, hf_simple_status_subtype, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_word_count, tvb, offset, 1, ENC_NA);
offset++;
name = tvb_get_stringzpad(wmem_packet_scope(), tvb, offset, SIMPLE_STATUS_NAME_LEN, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Name: %s", name);
proto_tree_add_item(tree, hf_simple_status_name, tvb, offset, SIMPLE_STATUS_NAME_LEN, ENC_ASCII|ENC_NA);
offset += SIMPLE_STATUS_NAME_LEN;
proto_tree_add_item(tree, hf_simple_status_time_hours, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_node_id, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_time_seconds, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_time_minutes, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_security_level, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_node_entry_flag, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_relay_hop, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_bitmask_text(tree, tvb, offset, 2, "Data Extraction Flags", NULL, ett_simple_status_dx_flag, simple_status_dx_flag_fields, ENC_LITTLE_ENDIAN, 0);
offset += 2;
proto_tree_add_item(tree, hf_simple_status_dx_file_id, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_simple_status_spare_1, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_simple_status_link16_terminal_type, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_link16_role, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_link16_sync_status, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_link16_terminal_host_status, tvb, offset, 1, ENC_NA);
link16_status = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_simple_status_link16_stn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (link16_status)
col_append_fstr(pinfo->cinfo, COL_INFO, ", STN: %05o", tvb_get_letohs(tvb, offset));
offset += 2;
proto_tree_add_item(tree, hf_simple_status_spare_2, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_simple_status_link11_dts_type, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_link11_role, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_simple_status_link11_pu, tvb, offset, 1, ENC_NA);
pu = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_simple_status_link11_dts_host_status, tvb, offset, 1, ENC_NA);
if (tvb_get_guint8(tvb, offset))
col_append_fstr(pinfo->cinfo, COL_INFO, ", PU: %03o", pu);
offset++;
proto_tree_add_item(tree, hf_simple_status_spare_3, tvb, offset, 4, ENC_NA);
}
static void dissect_checksum(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
const guint8 * v = tvb_get_ptr(tvb, 0, offset);
guint16 expected_checksum = 0;
gint i;
for (i = 0; i < offset; i++)
expected_checksum += v[i];
proto_tree_add_checksum(tree, tvb, offset, hf_simple_checksum, hf_simple_checksum_status, &ei_simple_checksum_bad, pinfo, expected_checksum,
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
static int dissect_simple(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *simple_item = NULL, *item;
proto_tree *simple_tree = NULL, *packet_tree = NULL;
guint offset = 0, length, packet_size, packet_type;
const gchar *packet_type_string;
guint8 sync_bytes_bad = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SIMPLE");
if (tree) {
simple_item = proto_tree_add_item(tree, proto_simple, tvb, 0, -1, ENC_NA);
simple_tree = proto_item_add_subtree(simple_item, ett_simple);
}
proto_tree_add_item(simple_tree, hf_simple_sync_byte_1, tvb, offset, 1, ENC_NA);
sync_bytes_bad |= tvb_get_guint8(tvb, offset) ^ 0x49;
offset++;
proto_tree_add_item(simple_tree, hf_simple_sync_byte_2, tvb, offset, 1, ENC_NA);
sync_bytes_bad |= tvb_get_guint8(tvb, offset) ^ 0x36;
offset++;
if (sync_bytes_bad)
expert_add_info(pinfo, simple_item, &ei_simple_sync_bytes_bad);
item = proto_tree_add_item(simple_tree, hf_simple_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
length = tvb_get_letohs(tvb, offset);
offset += 2;
if (length < 16 || length >= 518 || length > tvb_reported_length(tvb))
expert_add_info(pinfo, item, &ei_simple_length_bad);
proto_tree_add_item(simple_tree, hf_simple_sequence_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(simple_tree, hf_simple_src_node, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(simple_tree, hf_simple_src_subnode, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(simple_tree, hf_simple_dst_node, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(simple_tree, hf_simple_dst_subnode, tvb, offset, 1, ENC_NA);
offset++;
item = proto_tree_add_item(simple_tree, hf_simple_packet_size, tvb, offset, 1, ENC_NA);
packet_size = tvb_get_guint8(tvb, offset) * 2;
if (packet_size < 8 || packet_size - 8 > tvb_reported_length(tvb))
expert_add_info(pinfo, item, &ei_simple_packet_size_bad);
packet_size -= 8;
offset++;
proto_tree_add_item(simple_tree, hf_simple_packet_type, tvb, offset, 1, ENC_NA);
packet_type = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(simple_tree, hf_simple_transit_time, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
packet_type_string = val_to_str(packet_type, PacketType_Strings, "Unknown");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", packet_type_string);
packet_tree = proto_tree_add_subtree_format(simple_tree, tvb, offset, packet_size, ett_packet, NULL, "%s Packet", packet_type_string);
switch(packet_type) {
case SIMPLE_LINK16:
dissect_simple_link16(tvb, pinfo, packet_tree, offset);
break;
case SIMPLE_STATUS:
dissect_simple_status(tvb, pinfo, packet_tree, offset);
break;
}
dissect_checksum(tvb, pinfo, simple_tree, length - 2);
return tvb_captured_length(tvb);
}
void proto_register_simple(void)
{
static hf_register_info hf[] = {
{ &hf_simple_sync_byte_1,
{ "Sync Byte 1", "simple.sync_byte_1", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_sync_byte_2,
{ "Sync Byte 2", "simple.sync_byte_2", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_length,
{ "Length", "simple.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_sequence_number,
{ "Sequence Number", "simple.sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_src_node,
{ "Source Node", "simple.src_node", FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(Node_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_src_subnode,
{ "Source Subnode", "simple.src_subnode", FT_UINT8, BASE_DEC, VALS(Subnode_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_dst_node,
{ "Destination Node", "simple.dst_node", FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(Node_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_dst_subnode,
{ "Destination Subnode", "simple.dst_subnode", FT_UINT8, BASE_DEC, VALS(Subnode_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_packet_size,
{ "Packet Size", "simple.packet_size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_packet_type,
{ "Packet Type", "simple.packet_type", FT_UINT8, BASE_DEC, VALS(PacketType_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_transit_time,
{ "Transit Time", "simple.transit_time", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_subtype,
{ "Subtype", "simple.link16.subtype", FT_UINT8, BASE_DEC, VALS(Link16_Subtype_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_link16_rc,
{ "R/C Flag", "simple.link16.rc", FT_UINT8, BASE_DEC, VALS(Link16_RC_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_link16_network,
{ "Network", "simple.link16.network", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_ssc2,
{ "Sequential Slot Count 2", "simple.link16.ssc2", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_npg,
{ "NPG Number", "simple.link16.npg", FT_UINT16, BASE_DEC, VALS(Link16_NPG_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_link16_ssc1,
{ "Sequential Slot Count 1", "simple.link16.ssc1", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_stn,
{ "Source Track Number", "simple.link16.stn", FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_word_count,
{ "Word Count", "simple.link16.word_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_link16_loopback_id,
{ "Loopback ID", "simple.link16.loopback_id", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_subtype,
{ "Subtype", "simple.status.subtype", FT_UINT8, BASE_HEX, VALS(Status_Subtype_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_status_word_count,
{ "Word Count", "simple.status.word_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_name,
{ "Name", "simple.status.name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_time_hours,
{ "Time (Hours)", "simple.status.time_hours", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_node_id,
{ "Node Id", "simple.status.node_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_time_seconds,
{ "Time (Seconds)", "simple.status.time_seconds", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_time_minutes,
{ "Time (Minutes)", "simple.status.time_minutes", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_security_level,
{ "Security Level", "simple.status.security_level", FT_UINT8, BASE_DEC, VALS(Security_Level_Strings), 0x0,
NULL, HFILL }},
{ &hf_simple_status_node_entry_flag,
{ "Node Entry Flag", "simple.status.node_entry_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_relay_hop,
{ "Relay Hop", "simple.status.relay_hop", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_system_messages,
{ "DX System Messages", "simple.status.dx_flag.system_messages", FT_BOOLEAN, 16, NULL, 0x1,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_common_tims_bims,
{ "DX Common TIMS/BIMS", "simple.status.dx_flag.common_tims_bims", FT_BOOLEAN, 16, NULL, 0x2,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_common_toms_boms,
{ "DX Common TOMS/BOMS", "simple.status.dx_flag.common_toms_boms", FT_BOOLEAN, 16, NULL, 0x4,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_simple_receive,
{ "DX SIMPLE Recieve", "simple.status.dx_flag.simple_receive", FT_BOOLEAN, 16, NULL, 0x8,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_simple_transmit,
{ "DX SIMPLE Transmit", "simple.status.dx_flag.simple_transmit", FT_BOOLEAN, 16, NULL, 0x10,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_all_tims_bims,
{ "DX All TIMS/BIMS", "simple.status.dx_flag.all_tims_bims", FT_BOOLEAN, 16, NULL, 0x20,
NULL, HFILL }},
{ &hf_simple_status_dx_flag_all_toms_boms,
{ "DX All TOMS/BOMS", "simple.status.dx_flag.all_toms_boms", FT_BOOLEAN, 16, NULL, 0x40,
NULL, HFILL }},
{ &hf_simple_status_dx_file_id,
{ "DX File Id", "simple.status.dx_file_id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_spare_1,
{ "Spare1", "simple.status.spare_1", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_link16_terminal_type,
{ "Link 16 Type", "simple.status.link16.terminal_type", FT_UINT8, BASE_DEC, VALS(Link16_Terminal_Type), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link16_role,
{ "Link 16 Role", "simple.status.link16.role", FT_UINT8, BASE_DEC, VALS(Link16_Role), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link16_sync_status,
{ "Link 16 Sync Status", "simple.status.link16.sync_status", FT_UINT8, BASE_DEC, VALS(Link16_Sync_Status), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link16_terminal_host_status,
{ "Link 16 Terminal/Host Status", "simple.status.link16.terminal_host_status", FT_UINT8, BASE_DEC, VALS(Link_Terminal_Host_Status), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link16_stn,
{ "Link 16 STN", "simple.status.link16.stn", FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_spare_2,
{ "Spare2", "simple.status.spare_2", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_link11_dts_type,
{ "Link 11 DTS Type", "simple.status.link11.dts_type", FT_UINT8, BASE_DEC, VALS(Link11_DTS_Type), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link11_role,
{ "Link 11 Role", "simple.status.link11.role", FT_UINT8, BASE_DEC, VALS(Link11_Role), 0x0,
NULL, HFILL }},
{ &hf_simple_status_link11_pu,
{ "Link 11 PU", "simple.status.link11.pu", FT_UINT8, BASE_OCT, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_status_link11_dts_host_status,
{ "Link 11 DTS/Host Status", "simple.status.link11.dts_host_status", FT_UINT8, BASE_DEC, VALS(Link_Terminal_Host_Status), 0x0,
NULL, HFILL }},
{ &hf_simple_status_spare_3,
{ "Spare3", "simple.status.spare_3", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_checksum,
{ "Checksum", "simple.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_simple_checksum_status,
{ "Checksum Status", "simple.checksum.status", FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_simple,
&ett_packet,
&ett_simple_status_dx_flag,
};
static ei_register_info ei[] = {
{ &ei_simple_sync_bytes_bad, { "simple.sync_bytes.bad", PI_MALFORMED, PI_ERROR, "Bad sync bytes", EXPFILL }},
{ &ei_simple_length_bad, { "simple.length.bad", PI_MALFORMED, PI_ERROR, "Bad length", EXPFILL }},
{ &ei_simple_packet_size_bad, { "simple.packet_size.bad", PI_MALFORMED, PI_ERROR, "Bad packet length", EXPFILL }},
{ &ei_simple_checksum_bad, { "simple.checksum.bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_simple;
proto_simple = proto_register_protocol("Standard Interface for Multiple Platform Link Evaluation", "SIMPLE", "simple");
proto_register_field_array(proto_simple, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_simple = expert_register_protocol(proto_simple);
expert_register_field_array(expert_simple, ei, array_length(ei));
register_dissector("simple", dissect_simple, proto_simple);
}
void proto_reg_handoff_simple(void)
{
dissector_handle_t simple_dissector_handle;
simple_dissector_handle = create_dissector_handle(dissect_simple, proto_simple);
dissector_add_for_decode_as("udp.port", simple_dissector_handle);
link16_handle = find_dissector_add_dependency("link16", proto_simple);
}
