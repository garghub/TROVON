static gint dissect_msmms_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (tvb_captured_length(tvb) < 8) {
return 0;
}
if (tvb_get_letohl(tvb, 4) == 0xb00bface)
{
return dissect_msmms_command(tvb, pinfo, tree);
}
else
if ((pinfo->ptype == PT_UDP) && (pinfo->destport == MSMMS_PORT))
{
return dissect_msmms_data_udp_command(tvb, pinfo, tree);
}
else
if (pinfo->destport != MSMMS_PORT)
{
return dissect_msmms_data(tvb, pinfo, tree);
}
return 0;
}
static gint dissect_msmms_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *ti;
proto_tree *msmms_tree;
proto_tree *msmms_common_command_tree;
guint32 sequence_number;
guint16 command_id;
guint16 command_dir;
gint32 length_of_command;
guint32 length_remaining;
if (tvb_reported_length_remaining(tvb, offset) < 12)
{
pinfo->desegment_offset = 0;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
length_of_command = tvb_get_letohl(tvb, offset+8);
if (tvb_reported_length_remaining(tvb, 16) < length_of_command)
{
pinfo->desegment_offset = 0;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSMMS");
col_set_str(pinfo->cinfo, COL_INFO, "Command: ");
ti = proto_tree_add_item(tree, hf_msmms_command, tvb, 0, 0, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
ti = proto_tree_add_item(tree, proto_msmms, tvb, offset, -1, ENC_NA);
msmms_tree = proto_item_add_subtree(ti, ett_msmms_command);
command_id = tvb_get_letohs(tvb, 36);
command_dir = tvb_get_letohs(tvb, 36+2);
ti = proto_tree_add_string_format(msmms_tree, hf_msmms_command_common_header, tvb, offset, -1,
"",
"%s (to %s)",
(command_dir == TO_SERVER) ?
val_to_str_const(command_id, to_server_command_vals, "Unknown") :
val_to_str_const(command_id, to_client_command_vals, "Unknown"),
(command_dir == TO_SERVER) ? "server" : "client");
msmms_common_command_tree = proto_item_add_subtree(ti, ett_msmms_command_common_header);
offset += 4;
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_signature, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (strncmp((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 3, ENC_ASCII), "MMS", 3) != 0)
{
return 0;
}
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_protocol_type, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_length_remaining, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
sequence_number = tvb_get_letohl(tvb, offset);
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_sequence_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_timestamp, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
length_remaining = tvb_get_letohl(tvb, offset);
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_length_remaining2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_common_command_tree,
(command_dir == TO_SERVER) ?
hf_msmms_command_to_server_id :
hf_msmms_command_to_client_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(msmms_common_command_tree, hf_msmms_command_direction, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_item_set_len(msmms_common_command_tree, offset);
col_append_fstr(pinfo->cinfo, COL_INFO,
"seq=%03u: %s %s",
sequence_number,
(command_dir == TO_SERVER) ? "-->" : "<--",
(command_dir == TO_SERVER) ?
val_to_str_const(command_id, to_server_command_vals, "Unknown") :
val_to_str_const(command_id, to_client_command_vals, "Unknown"));
length_remaining = (length_remaining*8) - 8;
if (command_dir == TO_SERVER)
{
switch (command_id)
{
case SERVER_COMMAND_TRANSPORT_INFO:
dissect_client_transport_info(tvb, pinfo, msmms_tree,
offset, length_remaining);
break;
case SERVER_COMMAND_CONNECT_INFO:
dissect_client_player_info(tvb, pinfo, msmms_tree,
offset, length_remaining);
break;
case SERVER_COMMAND_START_SENDING_FROM:
dissect_start_sending_from_info(tvb, msmms_tree, offset);
break;
case SERVER_COMMAND_CANCEL_PROTOCOL:
dissect_cancel_info(tvb, msmms_tree, offset);
break;
case SERVER_COMMAND_TIMING_TEST_DATA_REQUEST:
dissect_timing_test_request(tvb, tree, offset);
break;
case SERVER_COMMAND_REQUEST_SERVER_FILE:
dissect_request_server_file(tvb, pinfo, tree, offset, length_remaining);
break;
case SERVER_COMMAND_NETWORK_TIMER_TEST_RESPONSE:
dissect_network_timer_test_response(tvb, tree, offset);
break;
case SERVER_COMMAND_MEDIA_STREAM_MBR_SELECTOR:
dissect_media_stream_mbr_selector(tvb, tree, offset);
break;
case SERVER_COMMAND_HEADER_REQUEST:
dissect_header_request(tvb, tree, offset);
break;
case SERVER_COMMAND_STOP_BUTTON_PRESSED:
dissect_stop_button_pressed(tvb, tree, offset);
break;
default:
break;
}
}
else
{
switch (command_id)
{
case CLIENT_COMMAND_SERVER_INFO:
dissect_server_info(tvb, pinfo, msmms_tree, offset);
break;
case CLIENT_COMMAND_TIMING_TEST_DATA_RESPONSE:
dissect_timing_test_response(tvb, tree, offset);
break;
case CLIENT_COMMAND_MEDIA_DETAILS:
dissect_media_details(tvb, tree, offset);
break;
case CLIENT_COMMAND_SENDING_HEADER_RESPONSE:
dissect_header_response(tvb, tree, offset);
break;
case CLIENT_COMMAND_TRANSPORT_INFO_ACK:
dissect_transport_info_response(tvb, tree, offset, length_remaining);
break;
default:
break;
}
}
return length_of_command + 12;
}
static gint dissect_msmms_data_udp_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *msmms_tree;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSMMS");
ti = proto_tree_add_item(tree, proto_msmms, tvb, offset, -1, ENC_NA);
msmms_tree = proto_item_add_subtree(ti, ett_msmms_data);
proto_tree_add_item(msmms_tree, hf_msmms_data_header_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_tree, hf_msmms_data_client_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_tree, hf_msmms_data_command_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 4;
col_set_str(pinfo->cinfo, COL_INFO, "Request to resend packet(s):");
while (tvb_reported_length_remaining(tvb, offset) >= 4)
{
guint32 packet_number = tvb_get_letohl(tvb, offset);
proto_tree_add_item(msmms_tree, hf_msmms_data_packet_to_resend, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, " %u", packet_number);
}
return tvb_reported_length_remaining(tvb, 0);
}
static gint dissect_msmms_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *ti;
proto_tree *msmms_tree;
proto_tree *msmms_data_timing_pair = NULL;
guint32 sequence_number;
guint16 packet_length;
guint16 packet_length_found;
guint8 value = 0;
packet_length = tvb_get_letohs(tvb, 6);
packet_length_found = tvb_reported_length_remaining(tvb, 0);
if (packet_length < 8)
{
return 0;
}
if (packet_length_found < packet_length)
{
pinfo->desegment_offset = 0;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return -1;
}
if (pinfo->ptype == PT_TCP)
{
value = tvb_get_guint8(tvb, 5);
if (try_val_to_str(value, tcp_flags_vals) == NULL)
{
return 0;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSMMS");
ti = proto_tree_add_item(tree, hf_msmms_data, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
ti = proto_tree_add_item(tree, proto_msmms, tvb, offset, -1, ENC_NA);
msmms_tree = proto_item_add_subtree(ti, ett_msmms_data);
sequence_number = tvb_get_letohl(tvb, offset);
proto_tree_add_item(msmms_tree, hf_msmms_data_sequence_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(msmms_tree, hf_msmms_data_packet_id_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (pinfo->ptype == PT_UDP)
{
proto_tree_add_item(msmms_tree, hf_msmms_data_udp_sequence, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(msmms_tree, hf_msmms_data_tcp_flags, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
offset++;
packet_length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(msmms_tree, hf_msmms_data_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (value == 0x01)
{
ti = proto_tree_add_string(msmms_tree, hf_msmms_data_timing_pair, tvb, offset, 8, "");
msmms_data_timing_pair = proto_item_add_subtree(ti, ett_msmms_data_timing_packet_pair);
proto_tree_add_item(msmms_data_timing_pair, hf_msmms_data_timing_pair_seqno, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(msmms_data_timing_pair, hf_msmms_data_timing_pair_flags, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(msmms_data_timing_pair, hf_msmms_data_timing_pair_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(msmms_data_timing_pair, hf_msmms_data_timing_pair_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(msmms_data_timing_pair, hf_msmms_data_timing_pair_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
proto_tree_add_item(msmms_tree, hf_msmms_data_unparsed, tvb, offset, packet_length-offset, ENC_NA);
offset = packet_length;
col_add_fstr(pinfo->cinfo, COL_INFO, "Data: seq=%05u, len=%05u",
sequence_number, packet_length);
return offset;
}
static void dissect_client_transport_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint length_remaining)
{
char *transport_info;
guint ipaddr[4];
char protocol[3+1] = "";
guint port;
int fields_matched;
proto_tree_add_item(tree, hf_msmms_command_prefix1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
offset += 4;
transport_info = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length_remaining - 20, ENC_UTF_16|ENC_LITTLE_ENDIAN);
proto_tree_add_string_format(tree, hf_msmms_command_client_transport_info, tvb,
offset, length_remaining-20,
transport_info, "Transport: (%s)", transport_info);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
format_text((guchar*)transport_info, length_remaining - 20));
fields_matched = sscanf(transport_info, "%*c%*c%u.%u.%u.%u%*c%3s%*c%u",
&ipaddr[0], &ipaddr[1], &ipaddr[2], &ipaddr[3],
protocol, &port);
if (fields_matched == 6)
{
port_type pt = PT_NONE;
if (strncmp(protocol, "UDP", 3) == 0)
{
pt = PT_UDP;
}
else
if (strncmp(protocol, "TCP", 3) == 0)
{
pt = PT_TCP;
}
if (pt != PT_NONE)
{
guint8 octets[4];
address addr;
octets[0] = ipaddr[0];
octets[1] = ipaddr[1];
octets[2] = ipaddr[2];
octets[3] = ipaddr[3];
addr.type = AT_IPv4;
addr.len = 4;
addr.data = octets;
msmms_data_add_address(pinfo, &addr, pt, port);
}
}
}
static void dissect_server_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
guint32 server_version_length;
guint32 tool_version_length;
guint32 download_update_player_length;
guint32 password_encryption_type_length;
char *server_version;
proto_tree_add_item(tree, hf_msmms_command_prefix1_error, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
server_version_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_msmms_command_server_version_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
tool_version_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_msmms_command_tool_version_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
download_update_player_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_msmms_command_update_url_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
password_encryption_type_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_msmms_command_password_type_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (server_version_length > 1)
{
server_version = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, server_version_length*2, ENC_UTF_16|ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_msmms_command_server_version, tvb,
offset, server_version_length*2,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (version='%s')",
format_text((guchar*)server_version, strlen(server_version)));
}
offset += (server_version_length*2);
if (tool_version_length > 1)
{
proto_tree_add_item(tree, hf_msmms_command_tool_version, tvb,
offset, tool_version_length*2,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
offset += (tool_version_length*2);
if (download_update_player_length > 1)
{
proto_tree_add_item(tree, hf_msmms_command_update_url, tvb,
offset, download_update_player_length*2,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
offset += (download_update_player_length*2);
if (password_encryption_type_length > 1)
{
proto_tree_add_item(tree, hf_msmms_command_password_type, tvb,
offset, password_encryption_type_length*2,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
}
static void dissect_client_player_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint length_remaining)
{
char *player_info;
proto_tree_add_item(tree, hf_msmms_command_prefix1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
player_info = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length_remaining - 12, ENC_UTF_16|ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_msmms_command_client_player_info, tvb,
offset, length_remaining-12,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
format_text((guchar*)player_info, strlen(player_info)));
}
static void dissect_start_sending_from_info(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_cancel_info(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_timing_test_request(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_timing_test_response(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_error, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_number_of_words, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_client_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_request_server_file(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint length_remaining)
{
char *server_file;
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
server_file = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length_remaining - 16, ENC_UTF_16|ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_msmms_command_server_file, tvb,
offset, length_remaining-16,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
format_text((guchar*)server_file, strlen(server_file)));
}
static void dissect_media_details(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_error, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_result_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_broadcast_indexing, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_msmms_command_broadcast_liveness, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_recorded_media_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset += 4;
offset += 4;
offset += 4;
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_media_packet_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_header_response(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_error, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_network_timer_test_response(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_transport_info_response(tvbuff_t *tvb, proto_tree *tree,
guint offset, guint length_remaining)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_number_of_words, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_strange_string, tvb,
offset, length_remaining-12,
ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
static void dissect_media_stream_mbr_selector(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_stream_structure_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_stream_selection_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_msmms_stream_selection_stream_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_msmms_stream_selection_action, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void dissect_header_request(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
gint n;
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (n=0; n < 8; n++)
{
offset += 4;
}
proto_tree_add_item(tree, hf_msmms_command_header_packet_id_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_stop_button_pressed(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_msmms_command_prefix1_command_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msmms_command_prefix2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void msmms_data_add_address(packet_info *pinfo, address *addr, port_type pt, int port)
{
address null_addr;
conversation_t *p_conv;
if (pinfo->fd->flags.visited)
{
return;
}
clear_address(&null_addr);
p_conv = find_conversation(pinfo->num, addr, &null_addr, pt, port, 0,
NO_ADDR_B | NO_PORT_B);
if (!p_conv)
{
p_conv = conversation_new(pinfo->num, addr, &null_addr, pt,
(guint32)port, 0, NO_ADDR2 | NO_PORT2);
}
conversation_set_dissector(p_conv, msmms_handle);
}
void proto_register_msmms(void)
{
static hf_register_info hf[] =
{
{
&hf_msmms_command,
{
"Command",
"msmms.command",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"MSMMS command hidden filter", HFILL
}
},
{
&hf_msmms_command_common_header,
{
"Command common header",
"msmms.command.common-header",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"MSMMS command common header", HFILL
}
},
#if 0
{
&hf_msmms_command_version,
{
"Version",
"msmms.command.version",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
#endif
{
&hf_msmms_command_signature,
{
"Command signature",
"msmms.command.signature",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_length,
{
"Command length",
"msmms.command.length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_protocol_type,
{
"Protocol type",
"msmms.command.protocol-type",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_length_remaining,
{
"Length until end (8-byte blocks)",
"msmms.command.length-remaining",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_sequence_number,
{
"Sequence number",
"msmms.command.sequence-number",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_timestamp,
{
"Time stamp (s)",
"msmms.command.timestamp",
FT_DOUBLE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_length_remaining2,
{
"Length until end (8-byte blocks)",
"msmms.command.length-remaining2",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_to_server_id,
{
"Command",
"msmms.command.to-server-id",
FT_UINT16,
BASE_HEX,
VALS(to_server_command_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_to_client_id,
{
"Command",
"msmms.command.to-client-id",
FT_UINT16,
BASE_HEX,
VALS(to_client_command_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_direction,
{
"Command direction",
"msmms.command.direction",
FT_UINT16,
BASE_HEX,
VALS(command_direction_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_prefix1,
{
"Prefix 1",
"msmms.command.prefix1",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_prefix1_error,
{
"Prefix 1 ErrorCode",
"msmms.command.prefix1-error-code",
FT_UINT32,
BASE_HEX,
VALS(server_to_client_error_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_prefix1_command_level,
{
"Prefix 1 Command Level",
"msmms.command.prefix1-command-level",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_prefix2,
{
"Prefix 2",
"msmms.command.prefix2",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_client_transport_info,
{
"Client transport info",
"msmms.command.client-transport-info",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_client_player_info,
{
"Player info",
"msmms.command.player-info",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_server_version_length,
{
"Server Version Length",
"msmms.command.server-version-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_tool_version_length,
{
"Tool Version Length",
"msmms.command.tool-version-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_update_url_length,
{
"Download update URL length",
"msmms.command.download-update-player-url-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_password_type_length,
{
"Password encryption type length",
"msmms.command.password-encryption-type-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_server_version,
{
"Server version",
"msmms.command.server-version",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_tool_version,
{
"Tool version",
"msmms.command.tool-version",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_update_url,
{
"Download update player URL",
"msmms.command.download-update-player-url",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_password_type,
{
"Password encryption type",
"msmms.command.password-encryption-type",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_number_of_words,
{
"Number of 4 byte fields in structure",
"msmms.data.words-in-structure",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_client_id,
{
"Client ID",
"msmms.data.client-id",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_server_file,
{
"Server file",
"msmms.command.server-file",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_result_flags,
{
"Result flags",
"msmms.command.result-flags",
FT_UINT32,
BASE_HEX,
VALS(media_result_flags_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_broadcast_indexing,
{
"Broadcast indexing",
"msmms.command.broadcast-indexing",
FT_UINT8,
BASE_HEX,
VALS(broadcast_indexing_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_broadcast_liveness,
{
"Broadcast liveness",
"msmms.command.broadcast-liveness",
FT_UINT8,
BASE_HEX,
VALS(broadcast_liveness_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_recorded_media_length,
{
"Pre-recorded media length (seconds)",
"msmms.data.prerecorded-media-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_media_packet_length,
{
"Media packet length (bytes)",
"msmms.data.media-packet-length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_strange_string,
{
"Strange string",
"msmms.command.strange-string",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_stream_structure_count,
{
"Stream structure count",
"msmms.data.stream-structure-count",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_stream_selection_flags,
{
"Stream selection flags",
"msmms.data.stream-selection-flags",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_stream_selection_stream_id,
{
"Stream id",
"msmms.data.selection-stream-id",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_stream_selection_action,
{
"Action",
"msmms.data.selection-stream-action",
FT_UINT16,
BASE_DEC,
VALS(stream_selection_action_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_command_header_packet_id_type,
{
"Header packet ID type",
"msmms.data.header-packet-id-type",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data,
{
"Data",
"msmms.data",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_sequence_number,
{
"Sequence number",
"msmms.data.sequence",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_packet_id_type,
{
"Packet ID type",
"msmms.data.packet-id-type",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_packet_length,
{
"Packet length",
"msmms.data.packet-length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_header_id,
{
"Header ID",
"msmms.data.header-id",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_client_id,
{
"Client ID",
"msmms.data.client-id",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_command_id,
{
"Command ID",
"msmms.data.command-id",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_packet_to_resend,
{
"Packet to resend",
"msmms.data.packet-to-resend",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_udp_sequence,
{
"UDP Sequence",
"msmms.data.udp-sequence",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_tcp_flags,
{
"TCP flags",
"msmms.data.tcp-flags",
FT_UINT8,
BASE_HEX,
VALS(tcp_flags_vals),
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair,
{
"Data timing pair",
"msmms.data.timing-pair",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair_seqno,
{
"Sequence number",
"msmms.data.timing-pair.sequence-number",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair_flags,
{
"Flags",
"msmms.data.timing-pair.flags",
FT_UINT24,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair_id,
{
"ID",
"msmms.data.timing-pair.id",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair_flag,
{
"Flag",
"msmms.data.timing-pair.flag",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_timing_pair_packet_length,
{
"Packet length",
"msmms.data.timing-pair.packet-length",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_msmms_data_unparsed,
{
"Unparsed data",
"msmms.data.unparsed",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_msmms_command,
&ett_msmms_command_common_header,
&ett_msmms_data,
&ett_msmms_data_timing_packet_pair
};
proto_msmms = proto_register_protocol("Microsoft Media Server", "MSMMS", "msmms");
proto_register_field_array(proto_msmms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("msmms", dissect_msmms_pdu, proto_msmms);
}
void proto_reg_handoff_msmms_command(void)
{
msmms_handle = find_dissector("msmms");
dissector_add_uint("tcp.port", MSMMS_PORT, msmms_handle);
dissector_add_uint("udp.port", MSMMS_PORT, msmms_handle);
}
