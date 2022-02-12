static gchar*
tipc_addr_value_to_buf(guint tipc_address, gchar *buf, int buf_len)
{
guint8 zone;
guint16 subnetwork;
guint16 processor;
processor = tipc_address & 0x0fff;
tipc_address = tipc_address >> 12;
subnetwork = tipc_address & 0x0fff;
tipc_address = tipc_address >> 12;
zone = tipc_address & 0xff;
g_snprintf(buf, buf_len, "%u.%u.%u", zone, subnetwork, processor);
return buf;
}
static gchar *
tipc_addr_to_str(guint tipc_address)
{
gchar *buf;
buf = (gchar *)wmem_alloc(wmem_packet_scope(), MAX_TIPC_ADDRESS_STR_LEN);
return tipc_addr_value_to_buf(tipc_address, buf, MAX_TIPC_ADDRESS_STR_LEN);
}
static int
tipc_addr_to_str_buf(const address* addr, gchar *buf, int buf_len)
{
const guint8 *data = (const guint8 *)addr->data;
guint32 tipc_address;
tipc_address = data[0];
tipc_address = (tipc_address << 8) ^ data[1];
tipc_address = (tipc_address << 8) ^ data[2];
tipc_address = (tipc_address << 8) ^ data[3];
tipc_addr_value_to_buf(tipc_address, buf, buf_len);
return (int)(strlen(buf)+1);
}
static int
tipc_addr_str_len(const address* addr _U_)
{
return MAX_TIPC_ADDRESS_STR_LEN;
}
static void
dissect_tipc_name_dist_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 item_size)
{
int offset = 0;
guint32 dword;
gchar *addr_str_ptr;
if ((handle_v2_as & V2_AS_1_6) || ((handle_v2_as & (V2_AS_ALL) && item_size == 0))) {
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_tipc_name_dist_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_lower, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_upper, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
}
} else {
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, hf_tipc_name_dist_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_lower, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_upper, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
proto_tree_add_item(tree, hf_tipc_name_dist_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset+4;
dword = tvb_get_ntohl(tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tree, hf_tipcv2_name_dist_port_id_node, tvb, offset, 4, addr_str_ptr);
offset = offset+4;
proto_tree_add_item(tree, hf_tipcv2_dist_dist, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_tipcv2_dist_scope, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (item_size == 7) continue;
proto_tree_add_expert(tree, pinfo, &ei_tipc_field_not_specified, tvb, offset, ((item_size-7)*4));
offset += (item_size-7)*4;
}
}
}
static void
tipc_v2_set_info_col(tvbuff_t *tvb, packet_info *pinfo, guint8 user, guint8 msg_type, guint8 hdr_size)
{
guint32 portNameInst, dword;
guint32 portNameType, portNameInstLow, portNameInstHigh;
guint8 error;
switch (user) {
case TIPCv2_DATA_LOW:
case TIPCv2_DATA_NORMAL:
case TIPCv2_DATA_HIGH:
case TIPCv2_DATA_NON_REJECTABLE:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_data_msg_type_defines, "unknown"));
dword = tvb_get_ntohl(tvb, 4);
error = (dword>>25) & 0xf;
if (error > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(error, tipcv2_error_code_short_strings, "unknown"));
if (hdr_size > 8) {
portNameType = tvb_get_ntohl(tvb, 32);
col_append_fstr(pinfo->cinfo, COL_INFO, " type:%d", portNameType);
if (hdr_size > 9) {
portNameInst = tvb_get_ntohl(tvb, 36);
col_append_fstr(pinfo->cinfo, COL_INFO, " inst:%d", portNameInst);
if (hdr_size > 10) {
portNameInst = tvb_get_ntohl(tvb, 40);
col_append_fstr(pinfo->cinfo, COL_INFO, "-%d", portNameInst);
}
}
}
break;
case TIPCv2_BCAST_PROTOCOL:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_bcast_mtype_strings, "unknown"));
break;
case TIPCv2_MSG_BUNDLER:
break;
case TIPCv2_LINK_PROTOCOL:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_link_mtype_strings, "unknown"));
break;
case TIPCv2_CONN_MANAGER:
dword = tvb_get_ntohl(tvb, 4);
error = (dword>>25) & 0xf;
if (error > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(error, tipcv2_error_code_short_strings, "unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_connmgr_mtype_strings, "unknown"));
break;
case TIPCv2_ROUTE_DISTRIBUTOR:
if ((handle_v2_as & V2_AS_1_6) || ((handle_v2_as & V2_AS_ALL) == 0)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_route_mtype_strings_1_6, "unknown"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_route_mtype_strings_1_7, "unknown"));
}
break;
case TIPCv2_CHANGEOVER_PROTOCOL:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_changeover_mtype_strings, "unknown"));
break;
case TIPCv2_NAME_DISTRIBUTOR:
portNameType = tvb_get_ntohl(tvb, 40);
portNameInstLow = tvb_get_ntohl(tvb, 44);
portNameInstHigh = tvb_get_ntohl(tvb, 48);
if (portNameInstLow == portNameInstHigh) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s type:%d inst:%d",
val_to_str_const(msg_type, tipcv2_naming_mtype_strings, "unknown"), portNameType, portNameInstLow);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s type:%d seq:%d-%d",
val_to_str_const(msg_type, tipcv2_naming_mtype_strings, "unknown"), portNameType, portNameInstLow, portNameInstHigh);
}
break;
case TIPCv2_MSG_FRAGMENTER:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_fragmenter_mtype_strings, "unknown"));
break;
case TIPCv2_NEIGHBOUR_DISCOVERY:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", val_to_str_const(msg_type, tipcv2_neighbour_mtype_strings, "unknown"));
break;
default:
break;
}
}
static gboolean
tipc_v1_set_col_msgtype(packet_info *pinfo, guint8 user, guint8 msg_type)
{
gboolean datatype_hdr = FALSE;
switch (user) {
case TIPC_DATA_PRIO_0:
case TIPC_DATA_PRIO_1:
case TIPC_DATA_PRIO_2:
case TIPC_DATA_NON_REJECTABLE:
datatype_hdr = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_data_msg_type_values, "unknown"), msg_type);
break;
case TIPC_NAME_DISTRIBUTOR:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_name_dist_msg_type_values, "unknown"), msg_type);
break;
case TIPC_CONNECTION_MANAGER:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_cm_msg_type_values, "unknown"), msg_type);
break;
case TIPC_ROUTING_MANAGER:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_routing_mgr_msg_type_values, "unknown"), msg_type);
break;
case TIPC_LINK_PROTOCOL:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_link_prot_msg_type_values, "unknown"), msg_type);
break;
case TIPC_CHANGEOVER_PROTOCOL:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_cng_prot_msg_type_values, "unknown"), msg_type);
break;
case TIPC_SEGMENTATION_MANAGER:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", val_to_str_const(msg_type, tipc_sm_msg_type_values, "unknown"), msg_type);
break;
case TIPC_MSG_BUNDLER:
break;
default:
break;
}
return datatype_hdr;
}
static int
dissect_tipc_v2_internal_msg(tvbuff_t *tipc_tvb, proto_tree *tipc_tree, packet_info *pinfo, int offset, guint8 user, guint32 msg_size, guint8 orig_hdr_size)
{
guint32 dword;
gchar *addr_str_ptr;
tvbuff_t *data_tvb;
guint8 message_type;
guint8 item_size = 0;
guint16 message_count;
guint msg_no = 0;
guint32 msg_in_bundle_size;
guint8 msg_in_bundle_user;
gint b_inst_strlen, padlen;
gint len, reported_len;
gboolean save_fragmented;
guint32 frag_no, frag_msg_no;
tvbuff_t* new_tvb = NULL;
fragment_head *frag_msg = NULL;
proto_item *ti;
message_type = (tvb_get_guint8(tipc_tvb, offset) >>5) & 0x7;
switch (user) {
case TIPCv2_BCAST_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipcv2_bcast_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
} else {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_network_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
}
proto_tree_add_item(tipc_tree, hf_tipcv2_bcast_tag, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
break;
case TIPCv2_MSG_BUNDLER:
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 1 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 2 unused for this user");
offset = offset + 4;
} else {
proto_tree_add_item(tipc_tree, hf_tipcv2_bundler_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
} else {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
}
proto_tree_add_item(tipc_tree, hf_tipcv2_msg_count, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
message_count = tvb_get_ntohs(tipc_tvb, offset);
offset = offset + 4;
while ((guint32)offset < msg_size) {
msg_no++;
dword = tvb_get_ntohl(tipc_tvb, offset);
msg_in_bundle_size = dword & 0x1ffff;
msg_in_bundle_user = (dword >> 25) & 0xf;
ti = proto_tree_add_uint_format(top_tree, hf_tipc_msg_no_bundle, tipc_tvb, offset, 1, msg_no, "Message %u of %u in Bundle (%s)",
msg_no, message_count, val_to_str_const(msg_in_bundle_user, tipcv2_user_short_str_vals, "unknown"));
proto_item_set_len(ti, msg_in_bundle_size);
data_tvb = tvb_new_subset_length(tipc_tvb, offset, msg_in_bundle_size);
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_tipc(data_tvb, pinfo, top_tree, NULL);
offset += msg_in_bundle_size + ((msg_in_bundle_size%4)?(4-(msg_in_bundle_size%4)):0);
}
break;
case TIPCv2_LINK_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipcv2_link_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_sequence_gap, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_next_sent_broadcast, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_next_sent_packet, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_session_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_redundant_link, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_bearer_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_prio, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_network_plane, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_probe, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
} else {
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_timestamp, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
proto_tree_add_item(tipc_tree, hf_tipcv2_max_packet, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_tolerance, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if ((message_type == TIPCv2_RESET_MSG)
|| ((message_type == TIPCv2_STATE_MSG) && ((msg_size-(orig_hdr_size*4)) != 0))){
proto_tree_add_item(tipc_tree, hf_tipcv2_bearer_instance, tipc_tvb, offset, -1, ENC_ASCII|ENC_NA);
b_inst_strlen = tvb_strsize(tipc_tvb, offset);
offset += b_inst_strlen;
if ((padlen = (4-b_inst_strlen%4)) > 0) {
proto_tree_add_bytes_format_value(tipc_tree, hf_tipcv2_padding, tipc_tvb, offset, padlen, NULL, "%d byte%c", padlen, (padlen!=1?'s':0));
offset += padlen;
}
if ((offset-msg_size) > 0) {
proto_tree_add_bytes_format_value(tipc_tree, hf_tipcv2_filler_mtu_discovery, tipc_tvb, offset, -1, NULL,
"%d byte%c", tvb_reported_length_remaining(tipc_tvb, offset), (padlen!=1?'s':0));
}
}
break;
case TIPCv2_CONN_MANAGER:
proto_tree_add_item(tipc_tree, hf_tipcv2_connmgr_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_errorcode, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_rer_cnt, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_lookup_scope, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no , tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no , tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no , tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_org_port , tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_dst_port , tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
if (message_type == TIPCv2_CONMGR_MSG_ACK || (handle_v2_as & (V2_AS_ALL + V2_AS_1_7)))
{
proto_tree_add_item(tipc_tree, hf_tipcv2_conn_mgr_msg_ack, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case TIPCv2_ROUTE_DISTRIBUTOR:
dword = tvb_get_ntohl(tipc_tvb, offset+28);
item_size = (dword >> 24) & 0xff;
if ((handle_v2_as & V2_AS_1_6) || ((handle_v2_as & V2_AS_ALL) == 0)) {
proto_tree_add_item(tipc_tree, hf_tipcv2_route_mtype_1_6, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tipc_tree, hf_tipcv2_route_mtype_1_7, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (handle_v2_as & V2_AS_1_6) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 9 unused for this user");
offset = offset + 4;
} else {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_dst_port, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
item_size = (dword >> 24) & 0xff;
proto_tree_add_item(tipc_tree, hf_tipcv2_item_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
if ((handle_v2_as & V2_AS_1_6) || ((handle_v2_as & V2_AS_ALL) && (item_size == 0))) {
switch (message_type) {
case TIPCv2_EXT_ROUTING_TABLE:
case TIPCv2_LOCAL_ROUTING_TABLE:
case TIPCv2_SEC_ROUTING_TABLE:
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_cluster_address, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_bitmap, tipc_tvb, offset, -1, ENC_NA);
break;
case TIPCv2_ROUTE_ADDITION:
case TIPCv2_ROUTE_REMOVAL:
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_node_address, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
default:
break;
}
} else {
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_network_region, tipc_tvb, offset, 4, addr_str_ptr);
offset += 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_local_router, tipc_tvb, offset, 4, addr_str_ptr);
offset += 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_remote_router, tipc_tvb, offset, 4, addr_str_ptr);
offset += 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_dist_dist, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_dist_scope, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
break;
case TIPCv2_CHANGEOVER_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipcv2_changeover_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_item(tipc_tree, hf_tipcv2_redundant_link, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tipc_tree, hf_tipcv2_bearer_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
} else {
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
}
switch (message_type)
{
case 0:
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 9 unused for this user");
break;
case 1:
proto_tree_add_item(tipc_tree, hf_tipcv2_msg_count, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset = offset + 4;
break;
case TIPCv2_NAME_DISTRIBUTOR:
proto_tree_add_item(tipc_tree, hf_tipcv2_naming_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 4 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6 + V2_AS_ALL)) {
proto_tree_add_item(tipc_tree, hf_tipcv2_transport_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
} else {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
}
if (handle_v2_as & V2_AS_1_6) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 9 unused for this user");
offset = offset + 4;
} else {
dword = tvb_get_ntohl(tipc_tvb, offset);
item_size = (dword >> 24) & 0xff;
proto_tree_add_item(tipc_tree, hf_tipcv2_item_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
data_tvb = tvb_new_subset_remaining(tipc_tvb, offset);
dissect_tipc_name_dist_data(data_tvb, pinfo, tipc_tree, item_size);
break;
case TIPCv2_MSG_FRAGMENTER:
proto_tree_add_item(tipc_tree, hf_tipcv2_fragmenter_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
proto_tree_add_item(tipc_tree, hf_tipcv2_fragment_number, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
frag_no = (dword >> 16) & 0x0000ffff;
proto_tree_add_item(tipc_tree, hf_tipcv2_fragment_msg_number, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
frag_msg_no = dword & 0x0000ffff;
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 7 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 9 unused for this user");
offset = offset + 4;
} else {
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 5 unused for this user");
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 8 unused for this user");
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tipc_tvb, offset, 4, "word 9 unused for this user");
offset = offset + 4;
}
len = (msg_size - (orig_hdr_size<<2));
reported_len = tvb_reported_length_remaining(tipc_tvb, offset);
if (tipc_defragment) {
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&tipc_msg_reassembly_table,
tipc_tvb, offset,
pinfo,
frag_msg_no,
NULL,
(frag_no-1),
len,
(message_type != TIPCv2_USER_LAST_FRAGMENT));
new_tvb = process_reassembled_data(tipc_tvb, offset, pinfo,
"Reassembled TIPC", frag_msg, &tipc_msg_frag_items,
NULL, tipc_tree);
if (frag_msg) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Message Reassembled)");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Message fragment %u)", frag_no);
}
if (new_tvb) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_tipc(new_tvb, pinfo, top_tree, NULL);
} else {
data_tvb = tvb_new_subset_length_caplen(tipc_tvb, offset, len, reported_len);
call_data_dissector(data_tvb, pinfo, top_tree);
}
pinfo->fragmented = save_fragmented;
} else {
data_tvb = tvb_new_subset_length_caplen(tipc_tvb, offset, len, reported_len);
call_data_dissector(data_tvb, pinfo, top_tree);
}
break;
case TIPCv2_NEIGHBOUR_DISCOVERY:
proto_tree_add_item(tipc_tree, hf_tipcv2_neighbour_mtype, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_minor_pv, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_node_sig, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_destination_domain, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_network_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (handle_v2_as & (V2_AS_1_6)) {
proto_tree_add_item(tipc_tree, hf_tipcv2_bearer_level_orig_addr, tipc_tvb, offset, 20, ENC_NA);
offset = offset + 20;
} else {
proto_tree_add_item(tipc_tree, hf_tipcv2_media_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_bearer_level_orig_addr, tipc_tvb, offset, 16, ENC_NA);
offset = offset + 16;
}
if (msg_size-(orig_hdr_size*4) != 0) {
proto_tree_add_item(tipc_tree, hf_tipcv2_vendor_specific_data, tipc_tvb, offset, -1, ENC_NA);
}
break;
default:
break;
}
return offset;
}
static void
call_tipc_v2_data_subdissectors(tvbuff_t *data_tvb, packet_info *pinfo, guint32 *name_type_p, guint8 user)
{
if (dissect_tipc_data) {
heur_dtbl_entry_t *hdtbl_entry;
if (try_heuristic_first) {
if (dissector_try_heuristic(tipc_heur_subdissector_list, data_tvb, pinfo, top_tree, &hdtbl_entry, NULL))
return;
}
if (dissector_try_uint(tipc_user_dissector, user, data_tvb, pinfo, top_tree))
return;
if (name_type_p)
if (dissector_try_uint(tipc_type_dissector, *name_type_p, data_tvb, pinfo, top_tree))
return;
if (!try_heuristic_first) {
if (dissector_try_heuristic(tipc_heur_subdissector_list, data_tvb, pinfo, top_tree, &hdtbl_entry, NULL))
return;
}
}
call_data_dissector(data_tvb, pinfo, top_tree);
}
static void
dissect_tipc_v2(tvbuff_t *tipc_tvb, proto_tree *tipc_tree, packet_info *pinfo, int offset, guint8 user, guint32 msg_size, guint8 hdr_size, gboolean datatype_hdr)
{
guint32 dword;
gchar *addr_str_ptr;
guint8 opt_p = 0;
proto_item *item;
guint8 orig_hdr_size;
guint32 name_type = 0;
guint32 *name_type_p = NULL;
tvbuff_t *data_tvb;
gint len, reported_len;
orig_hdr_size = hdr_size;
proto_tree_add_item(tipc_tree, hf_tipc_ver, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_usr, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tipc_tree, hf_tipc_hdr_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " = %u bytes", (hdr_size * 4));
proto_tree_add_item(tipc_tree, hf_tipc_nonsequenced, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
if (datatype_hdr) {
proto_tree_add_item(tipc_tree, hf_tipc_destdrop, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_srcdrop, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_syn, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tipc_tree, hf_tipc_msg_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (!datatype_hdr) {
dissect_tipc_v2_internal_msg(tipc_tvb, tipc_tree, pinfo, offset, user, msg_size, orig_hdr_size);
return;
}
proto_tree_add_item(tipc_tree, hf_tipcv2_data_msg_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_errorcode, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_rer_cnt, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_lookup_scope, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
if (handle_v2_as & (V2_AS_ALL + V2_AS_1_6)) {
opt_p = tvb_get_guint8(tipc_tvb, offset+1) & 0x7;
proto_tree_add_item(tipc_tree, hf_tipcv2_opt_p, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
if (opt_p != 0) {
hdr_size = hdr_size - (opt_p << 2);
}
}
proto_tree_add_item(tipc_tree, hf_tipcv2_broadcast_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_ack_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_link_level_seq_no, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_prev_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_org_port, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_dst_port, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (hdr_size > 6) {
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_orig_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipcv2_dest_node, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (hdr_size > 8) {
proto_tree_add_item(tipc_tree, hf_tipcv2_port_name_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
name_type = tvb_get_ntohl(tipc_tvb, offset);
name_type_p = &name_type;
offset = offset + 4;
if (hdr_size > 9) {
if (hdr_size < 11)
proto_tree_add_item(tipc_tree, hf_tipcv2_port_name_instance, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tipc_tree, hf_tipcv2_multicast_lower, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (hdr_size > 10) {
proto_tree_add_item(tipc_tree, hf_tipcv2_multicast_upper, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
}
}
}
if (handle_v2_as & (V2_AS_ALL + V2_AS_1_6)) {
if (opt_p != 0) {
proto_tree_add_bytes_format(tipc_tree, hf_tipcv2_options, tipc_tvb, offset, (opt_p >> 2), NULL, "Options");
offset = offset + (opt_p << 2);
}
}
len = (msg_size - (orig_hdr_size<<2));
reported_len = tvb_reported_length_remaining(tipc_tvb, offset);
data_tvb = tvb_new_subset_length_caplen(tipc_tvb, offset, len, reported_len);
call_tipc_v2_data_subdissectors(data_tvb, pinfo, name_type_p, user);
}
static void
dissect_tipc_int_prot_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tipc_tree, int offset, guint8 user, guint32 msg_size)
{
guint8 msg_type;
tvbuff_t *data_tvb;
guint32 msg_in_bundle_size;
guint32 dword;
guint msg_no = 0;
guint8 link_sel;
guint16 link_lev_seq_no;
guint32 reassembled_msg_length = 0;
guint32 no_of_segments = 0;
gboolean save_fragmented;
tvbuff_t* new_tvb = NULL;
tvbuff_t* next_tvb = NULL;
fragment_head *frag_msg = NULL;
proto_item *item;
link_lev_seq_no = tvb_get_ntohl(tvb, 4) & 0xffff;
msg_type = tvb_get_guint8(tvb, 20)>>4;
dword = tvb_get_ntohl(tvb, offset);
link_sel = dword & 0x7;
proto_tree_add_item(tipc_tree, hf_tipc_unused2, tvb, offset, 4, ENC_BIG_ENDIAN);
if (user == TIPC_SEGMENTATION_MANAGER)
proto_tree_add_item(tipc_tree, hf_tipc_importance, tvb, offset, 4, ENC_BIG_ENDIAN);
if (user == TIPC_SEGMENTATION_MANAGER || user == TIPC_NAME_DISTRIBUTOR || user == TIPC_CHANGEOVER_PROTOCOL)
proto_tree_add_item(tipc_tree, hf_tipc_link_selector, tvb, offset, 4, ENC_BIG_ENDIAN);
if (user == TIPC_MSG_BUNDLER || user == TIPC_CHANGEOVER_PROTOCOL) {
proto_tree_add_item(tipc_tree, hf_tipc_msg_cnt, tvb, offset, 4, ENC_BIG_ENDIAN);
}
if (user == TIPC_LINK_PROTOCOL)
proto_tree_add_item(tipc_tree, hf_tipc_probe, tvb, offset, 4, ENC_BIG_ENDIAN);
if (user == TIPC_LINK_PROTOCOL || user == TIPC_CHANGEOVER_PROTOCOL)
proto_tree_add_item(tipc_tree, hf_tipc_bearer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
if (user == TIPC_SEGMENTATION_MANAGER || user == TIPC_NAME_DISTRIBUTOR || user == TIPC_CHANGEOVER_PROTOCOL)
proto_tree_add_item(tipc_tree, hf_tipc_link_selector2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (user == TIPC_ROUTING_MANAGER)
proto_tree_add_item(tipc_tree, hf_tipc_remote_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
switch (user) {
case TIPC_ROUTING_MANAGER:
proto_tree_add_item(tipc_tree, hf_tipc_rm_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case TIPC_NAME_DISTRIBUTOR:
proto_tree_add_item(tipc_tree, hf_tipc_nd_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case TIPC_CONNECTION_MANAGER:
break;
case TIPC_LINK_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipc_lp_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case TIPC_CHANGEOVER_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipc_cng_prot_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case TIPC_SEGMENTATION_MANAGER:
proto_tree_add_item(tipc_tree, hf_tipc_sm_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tipc_tree, hf_tipc_unknown_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
if (user == TIPC_LINK_PROTOCOL && msg_type == TIPC_LINK_PROTOCO_STATE_MSG)
proto_tree_add_item(tipc_tree, hf_tipc_seq_gap, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_nxt_snt_pkg, tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_none_format(tipc_tree, hf_tipc_unused_word, tvb, offset, 4, "word 6 unused for this user");
offset = offset + 4;
if (msg_size == 28)
return;
switch (user) {
case TIPC_LINK_PROTOCOL:
proto_tree_add_item(tipc_tree, hf_tipc_bearer_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
break;
case TIPC_CHANGEOVER_PROTOCOL:
switch (msg_type) {
case 0:
case 1:
item = proto_tree_add_uint_format(tipc_tree, hf_tipc_changeover_protocol, tvb, offset, 1,
msg_type, "TIPC_CHANGEOVER_PROTOCOL %s (%u)",
val_to_str_const(msg_type, tipc_cng_prot_msg_type_values, "unknown"), msg_type);
proto_item_set_len(item, tvb_reported_length_remaining(tvb, offset));
data_tvb = tvb_new_subset_remaining(tvb, offset);
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_tipc(data_tvb, pinfo, tipc_tree, NULL);
break;
default:
item = proto_tree_add_uint_format(tipc_tree, hf_tipc_changeover_protocol, tvb, offset, 1, msg_type,
"TIPC_CHANGEOVER_PROTOCOL Protocol/dissection Error");
proto_item_set_len(item, tvb_reported_length_remaining(tvb, offset));
break;
}
break;
case TIPC_SEGMENTATION_MANAGER:
save_fragmented = pinfo->fragmented;
if (tipc_defragment) {
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(&tipc_msg_reassembly_table,
tvb, offset,
pinfo,
link_sel,
NULL,
tvb_captured_length_remaining(tvb, offset),
TRUE);
if (msg_type == TIPC_FIRST_SEGMENT) {
reassembled_msg_length = tvb_get_ntohl(tvb, offset) & 0x1ffff;
no_of_segments = reassembled_msg_length/(msg_size - 28);
if (reassembled_msg_length > (no_of_segments * (msg_size - 28)))
no_of_segments++;
fragment_set_tot_len(&tipc_msg_reassembly_table,
pinfo, link_sel, NULL,
no_of_segments-1);
item = proto_tree_add_bytes_format(tipc_tree, hf_tipc_data_fragment, tvb, offset, -1, NULL, "Segmented message size %u bytes -> No segments = %i",
reassembled_msg_length, no_of_segments);
PROTO_ITEM_SET_GENERATED(item);
}
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled TIPC", frag_msg, &tipc_msg_frag_items,
NULL, tipc_tree);
if (frag_msg) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Message Reassembled)");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Message fragment %u)", link_lev_seq_no);
}
}
if (new_tvb) {
next_tvb = new_tvb;
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
pinfo->fragmented = save_fragmented;
if (new_tvb) {
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_tipc(next_tvb, pinfo, tipc_tree, NULL);
return;
}
proto_tree_add_bytes_format(tipc_tree, hf_tipc_data_fragment, next_tvb, 0, -1, NULL, "%u bytes Data Fragment", (msg_size - 28));
break;
case TIPC_MSG_BUNDLER:
proto_tree_add_item(tipc_tree, hf_tipc_message_bundle, tvb, offset, -1, ENC_NA);
while ((guint32)offset < msg_size) {
msg_no++;
msg_in_bundle_size = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_uint_format(tipc_tree, hf_tipc_msg_no_bundle, tvb, offset, 1, msg_no, "%u Message in Bundle", msg_no);
proto_item_set_len(item, msg_in_bundle_size);
data_tvb = tvb_new_subset_length(tvb, offset, msg_in_bundle_size);
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_tipc(data_tvb, pinfo, tipc_tree, NULL);
offset = offset + msg_in_bundle_size;
}
break;
default:
proto_tree_add_item(tipc_tree, hf_tipc_data, tvb, offset, -1, ENC_NA);
break;
}
}
static guint
get_tipc_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset) & 0x0001FFFF;
}
static int
dissect_tipc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, parent_tree, tipc_tcp_desegment, 4, get_tipc_pdu_len,
dissect_tipc, data);
return tvb_captured_length(tvb);
}
static int
dissect_tipc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti, *item;
proto_tree *tipc_tree, *tipc_data_tree;
int offset = 0;
guint32 dword;
guint8 version;
guint32 msg_size;
guint8 hdr_size;
guint8 user;
gchar *addr_str_ptr;
tvbuff_t *data_tvb, *tipc_tvb;
gboolean datatype_hdr = FALSE;
guint8 msg_type = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TIPC");
col_clear(pinfo->cinfo, COL_INFO);
top_tree = tree;
dword = tvb_get_ntohl(tvb, offset);
version = (dword >>29) & 0xf;
hdr_size = (dword >>21) & 0xf;
user = (dword>>25) & 0xf;
msg_size = dword & 0x1ffff;
if ((guint32)tvb_reported_length_remaining(tvb, offset) < msg_size) {
tipc_tvb = tvb;
} else {
tipc_tvb = tvb_new_subset_length(tvb, offset, msg_size);
}
if (user == TIPCv2_LINK_PROTOCOL) version = TIPCv2;
switch (version) {
case 0:
case TIPCv1:
msg_type = tvb_get_guint8(tipc_tvb, offset + 20)>>4;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s(%u) ", val_to_str_const(user, tipc_user_values, "unknown"), user);
datatype_hdr = tipc_v1_set_col_msgtype(pinfo, user, msg_type);
if (datatype_hdr) {
if (hdr_size > 5 && user <4) {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 24);
set_address_tvb(&pinfo->dst, tipc_address_type, 4, tipc_tvb, offset + 28);
} else {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 8);
}
} else {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 8);
}
break;
case TIPCv2:
msg_type = tvb_get_guint8(tipc_tvb, offset + 4)>>5;
col_append_fstr(pinfo->cinfo, COL_INFO, "%-12s", val_to_str_const(user, tipcv2_user_short_str_vals, "unknown"));
tipc_v2_set_info_col(tvb, pinfo, user, msg_type, hdr_size);
switch (user) {
case TIPCv2_DATA_LOW:
case TIPCv2_DATA_NORMAL:
case TIPCv2_DATA_HIGH:
case TIPCv2_DATA_NON_REJECTABLE:
datatype_hdr = TRUE;
break;
default:
datatype_hdr = FALSE;
break;
}
if (datatype_hdr) {
if (hdr_size > 6) {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 24);
set_address_tvb(&pinfo->dst, tipc_address_type, 4, tipc_tvb, offset + 28);
} else {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 12);
}
} else {
if (user != TIPCv2_NEIGHBOUR_DISCOVERY) {
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 24);
set_address_tvb(&pinfo->dst, tipc_address_type, 4, tipc_tvb, offset + 28);
} else {
set_address_tvb(&pinfo->dst, tipc_address_type, 4, tipc_tvb, offset + 8);
set_address_tvb(&pinfo->src, tipc_address_type, 4, tipc_tvb, offset + 12);
}
}
break;
default:
break;
}
ti = proto_tree_add_item(tree, proto_tipc, tipc_tvb, offset, -1, ENC_NA);
tipc_tree = proto_item_add_subtree(ti, ett_tipc);
if (version == TIPCv2) {
dissect_tipc_v2(tipc_tvb, tipc_tree, pinfo, offset, user, msg_size, hdr_size, datatype_hdr);
return tvb_captured_length(tvb);
}
proto_tree_add_item(tipc_tree, hf_tipc_ver, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_usr, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tipc_tree, hf_tipc_hdr_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " = %u bytes", (hdr_size * 4));
proto_tree_add_item(tipc_tree, hf_tipc_nonsequenced, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_unused, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
if (datatype_hdr) {
proto_tree_add_item(tipc_tree, hf_tipc_destdrop, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipcv2_srcdrop, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tipc_tree, hf_tipc_msg_size, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_ack_link_lev_seq, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_link_lev_seq, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipc_prev_proc, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
switch (user) {
case TIPC_ROUTING_MANAGER:
case TIPC_LINK_PROTOCOL:
case TIPC_CHANGEOVER_PROTOCOL:
case TIPC_SEGMENTATION_MANAGER:
case TIPC_MSG_BUNDLER:
dissect_tipc_int_prot_msg(tipc_tvb, pinfo, tipc_tree, offset, user, msg_size);
return tvb_captured_length(tvb);
default:
break;
}
dword = tvb_get_ntohl(tipc_tvb, offset);
pinfo->ptype = PT_TIPC;
pinfo->srcport = dword;
proto_tree_add_item(tipc_tree, hf_tipc_org_port, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
if (user != TIPC_NAME_DISTRIBUTOR) {
dword = tvb_get_ntohl(tipc_tvb, offset);
pinfo->destport = dword;
proto_tree_add_item(tipc_tree, hf_tipc_dst_port, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset = offset + 4;
if (hdr_size <= 6) {
proto_tree_add_item(tipc_tree, hf_tipc_data, tipc_tvb, offset, -1, ENC_NA);
} else {
switch (user) {
case TIPC_NAME_DISTRIBUTOR:
proto_tree_add_item(tipc_tree, hf_tipc_nd_msg_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case TIPC_CONNECTION_MANAGER:
proto_tree_add_item(tipc_tree, hf_tipc_cm_msg_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tipc_tree, hf_tipc_data_msg_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(tipc_tree, hf_tipc_err_code, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_reroute_cnt, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tipc_tree, hf_tipc_act_id, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipc_org_proc, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
dword = tvb_get_ntohl(tipc_tvb, offset);
addr_str_ptr = tipc_addr_to_str(dword);
proto_tree_add_string(tipc_tree, hf_tipc_dst_proc, tipc_tvb, offset, 4, addr_str_ptr);
offset = offset + 4;
if (hdr_size > 8) {
if (user == TIPC_NAME_DISTRIBUTOR) {
offset = offset + 8;
tipc_data_tree = proto_tree_add_subtree_format(tipc_tree, tvb, offset, -1, ett_tipc_data, NULL,
"TIPC_NAME_DISTRIBUTOR %u bytes User Data", (msg_size - hdr_size*4));
data_tvb = tvb_new_subset_remaining(tipc_tvb, offset);
dissect_tipc_name_dist_data(data_tvb, pinfo, tipc_data_tree, 0);
return tvb_captured_length(tvb);
} else {
proto_tree_add_item(tipc_tree, hf_tipc_port_name_type, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
proto_tree_add_item(tipc_tree, hf_tipc_port_name_instance, tipc_tvb, offset, 4, ENC_BIG_ENDIAN);
offset = offset + 4;
}
}
if (user < 4 && dissect_tipc_data) {
tvbuff_t *next_tvb;
guint32 msg_type32 = msg_type;
guint32 *name_type_p = &msg_type32;
switch (msg_type) {
case TIPC_CONNECTED_MSG:
proto_tree_add_item(tipc_tree, hf_tipc_data, tipc_tvb, offset, -1, ENC_NA);
break;
case TIPC_NAMED_MSG:
proto_tree_add_item(tipc_tree, hf_tipc_named_msg_hdr, tipc_tvb, offset, 14, ENC_NA);
proto_tree_add_item(tipc_tree, hf_tipc_data, tipc_tvb, offset+14, -1, ENC_NA);
break;
case TIPC_DIRECT_MSG:
proto_tree_add_item(tipc_tree, hf_tipc_data, tipc_tvb, offset, -1, ENC_NA);
break;
default:
proto_tree_add_item(tipc_tree, hf_tipc_data, tipc_tvb, offset, -1, ENC_NA);
break;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_tipc_v2_data_subdissectors(next_tvb, pinfo, name_type_p, user);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_tipc(void)
{
static hf_register_info hf[] = {
{ &hf_tipc_msg_fragments,
{ "Message fragments", "tipc.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_msg_fragment,
{ "Message fragment", "tipc.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_overlap,
{ "Message fragment overlap", "tipc.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "tipc.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments", "tipc.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_too_long_fragment,
{ "Message fragment too long", "tipc.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_error,
{ "Message defragmentation error", "tipc.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_msg_fragment_count,
{ "Message fragment count", "tipc.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_msg_reassembled_in,
{ "Reassembled in", "tipc.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_msg_reassembled_length,
{ "Reassembled TIPC length", "tipc.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_tipc_ver,
{ "Version", "tipc.ver",
FT_UINT32, BASE_DEC, NULL, 0xe0000000,
"TIPC protocol version", HFILL }
},
{ &hf_tipc_usr,
{ "User", "tipc.usr",
FT_UINT32, BASE_DEC, VALS(tipc_user_values), 0x1e000000,
"TIPC User", HFILL }
},
{ &hf_tipcv2_usr,
{ "User", "tipc.usr",
FT_UINT32, BASE_DEC, VALS(tipcv2_user_values), 0x1e000000,
"TIPC User", HFILL }
},
{ &hf_tipc_hdr_size,
{ "Header size", "tipc.hdr_size",
FT_UINT32, BASE_DEC, NULL, 0x01e00000,
"TIPC Header size", HFILL }
},
{ &hf_tipc_nonsequenced,
{ "Non-sequenced", "tipc.non_sequenced",
FT_UINT32, BASE_DEC, NULL, 0x00100000,
"Non-sequenced Bit", HFILL }
},
{ &hf_tipc_destdrop,
{ "Destination Droppable", "tipc.destdrop",
FT_UINT32, BASE_DEC, NULL, 0x00080000,
"Destination Droppable Bit", HFILL }
},
{ &hf_tipc_unused,
{ "Unused", "tipc.hdr_unused",
FT_UINT32, BASE_DEC, NULL, 0x000e0000,
"TIPC Unused", HFILL }
},
{ &hf_tipc_msg_size,
{ "Message size", "tipc.msg_size",
FT_UINT32, BASE_DEC, NULL, 0x0001ffff,
"TIPC Message size", HFILL }
},
{ &hf_tipc_ack_link_lev_seq,
{ "Acknowledged link level sequence number", "tipc.ack_link_lev_seq",
FT_UINT32, BASE_DEC, NULL, 0xffff0000,
"TIPC Acknowledged link level sequence number", HFILL }
},
{ &hf_tipc_link_lev_seq,
{ "Link level sequence number", "tipc.link_lev_seq",
FT_UINT32, BASE_DEC, NULL, 0x0000ffff,
"TIPC Link level sequence number", HFILL }
},
{ &hf_tipc_prev_proc,
{ "Previous processor", "tipc.prev_proc",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Previous processor", HFILL }
},
{ &hf_tipc_org_port,
{ "Originating port", "tipc.org_port",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Originating port", HFILL }
},
{ &hf_tipc_dst_port,
{ "Destination port", "tipc.dst_port",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Destination port", HFILL }
},
{ &hf_tipc_data_msg_type,
{ "Message type", "tipc.msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_data_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_err_code,
{ "Error code", "tipc.err_code",
FT_UINT32, BASE_DEC, VALS(tipc_error_code_values), 0x0f000000,
"TIPC Error code", HFILL }
},
{ &hf_tipc_reroute_cnt,
{ "Reroute counter", "tipc.route_cnt",
FT_UINT32, BASE_DEC, NULL, 0x00f00000,
"TIPC Reroute counter", HFILL }
},
{ &hf_tipc_act_id,
{ "Activity identity", "tipc.act_id",
FT_UINT32, BASE_DEC, NULL, 0x000fffff,
"TIPC Activity identity", HFILL }
},
{ &hf_tipc_org_proc,
{ "Originating processor", "tipc.org_proc",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Originating processor", HFILL }
},
{ &hf_tipc_dst_proc,
{ "Destination processor", "tipc.dst_proc",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Destination processor", HFILL }
},
{ &hf_tipc_unused2,
{ "Unused", "tipc.unused2",
FT_UINT32, BASE_DEC, NULL, 0xe0000000,
"TIPC Unused", HFILL }
},
{ &hf_tipc_importance,
{ "Importance", "tipc.importance",
FT_UINT32, BASE_DEC, NULL, 0x18000000,
"TIPC Importance", HFILL }
},
{ &hf_tipc_link_selector,
{ "Link selector", "tipc.link_selector",
FT_UINT32, BASE_DEC, NULL, 0x07000000,
"TIPC Link selector", HFILL }
},
{ &hf_tipc_msg_cnt,
{ "Message count", "tipc.imsg_cnt",
FT_UINT32, BASE_DEC, NULL, 0x00ffff00,
"TIPC Message count", HFILL }
},
{ &hf_tipc_probe,
{ "Probe", "tipc.probe",
FT_UINT32, BASE_DEC, NULL, 0x00000040,
"TIPC Probe", HFILL }
},
{ &hf_tipc_bearer_id,
{ "Bearer identity", "tipc.bearer_id",
FT_UINT32, BASE_DEC, NULL, 0x00000038,
"TIPC Bearer identity", HFILL }
},
{ &hf_tipc_link_selector2,
{ "Link selector", "tipc.link_selector",
FT_UINT32, BASE_DEC, NULL, 0x00000007,
"TIPC Link selector", HFILL }
},
{ &hf_tipc_remote_addr,
{ "Remote address", "tipc.remote_addr",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Remote address", HFILL }
},
{ &hf_tipc_rm_msg_type,
{ "Message type", "tipc.rm_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_routing_mgr_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_nd_msg_type,
{ "Message type", "tipc.nd_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_name_dist_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_cm_msg_type,
{ "Message type", "tipc.nd_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_cm_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_lp_msg_type,
{ "Message type", "tipc.lp_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_link_prot_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_cng_prot_msg_type,
{ "Message type", "tipc.cng_prot_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_cng_prot_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_sm_msg_type,
{ "Message type", "tipc.sm_msg_type",
FT_UINT32, BASE_DEC, VALS(tipc_sm_msg_type_values), 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_unknown_msg_type,
{ "Message type", "tipc.unknown_msg_type",
FT_UINT32, BASE_DEC, NULL, 0xf0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipc_seq_gap,
{ "Sequence gap", "tipc.seq_gap",
FT_UINT32, BASE_DEC, NULL, 0x1fff0000,
"TIPC Sequence gap", HFILL }
},
{ &hf_tipc_nxt_snt_pkg,
{ "Next sent packet", "tipc.nxt_snt_pkg",
FT_UINT32, BASE_DEC, NULL, 0x0000ffff,
"TIPC Next sent packet", HFILL }
},
{ &hf_tipc_unused_word,
{ "Word Unused", "tipc.unused_word",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_bearer_name,
{ "Bearer name", "tipc.bearer_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"TIPC Bearer name", HFILL }
},
{ &hf_tipc_data,
{ "Data", "tipc.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_msg_no_bundle,
{ "Message no. in bundle", "tipc.msg_no_bundle",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_changeover_protocol,
{ "TIPC_CHANGEOVER_PROTOCOL", "tipc.changeover_protocol",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_name_dist_type,
{ "Published port name type", "tipc.name_dist_type",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Published port name type", HFILL }
},
{ &hf_tipc_name_dist_lower,
{ "Lower bound of published sequence", "tipc.name_dist_lower",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Lower bound of published sequence", HFILL }
},
{ &hf_tipc_name_dist_upper,
{ "Upper bound of published sequence", "tipc.name_dist_upper",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Upper bound of published sequence", HFILL }
},
{ &hf_tipc_name_dist_port,
{ "Random number part of port identity", "tipc.dist_port",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC Random number part of port identity", HFILL }
},
{ &hf_tipc_name_dist_key,
{ "Key (Use for verification at withdrawal)", "tipc.dist_key",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"TIPC key", HFILL }
},
{ &hf_tipcv2_srcdrop,
{ "Source Droppable", "tipc.srcdrop",
FT_UINT32, BASE_DEC, NULL, 0x00040000,
"Destination Droppable Bit", HFILL }
},
{ &hf_tipcv2_syn,
{ "Connection request (SYN)", "tipc.syn",
FT_UINT32, BASE_DEC, NULL, 0x00020000,
"Destination Droppable Bit", HFILL }
},
{ &hf_tipcv2_data_msg_type,
{ "Message type", "tipc.data_type",
FT_UINT32, BASE_DEC, VALS(tipc_data_msg_type_values), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_bcast_mtype,
{ "Message type", "tipcv2.bcast_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_bcast_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_bundler_mtype,
{ "Message type", "tipcv2.bundler_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_bundler_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_link_mtype,
{ "Message type", "tipcv2.link_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_link_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_connmgr_mtype,
{ "Message type", "tipcv2.connmgr_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_connmgr_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_route_mtype_1_6,
{ "Message type", "tipcv2.route_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_route_mtype_strings_1_6), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_route_mtype_1_7,
{ "Message type", "tipcv2.route_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_route_mtype_strings_1_7), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_changeover_mtype,
{ "Message type", "tipcv2.changeover_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_changeover_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_naming_mtype,
{ "Message type", "tipcv2.naming_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_naming_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_fragmenter_mtype,
{ "Message type", "tipcv2.fragmenter_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_fragmenter_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_neighbour_mtype,
{ "Message type", "tipcv2.data_msg_type",
FT_UINT32, BASE_DEC, VALS(tipcv2_neighbour_mtype_strings), 0xe0000000,
"TIPC Message type", HFILL }
},
{ &hf_tipcv2_errorcode,
{ "Error code", "tipcv2.errorcode",
FT_UINT32, BASE_DEC, VALS(tipcv2_error_code_strings), 0x1e000000,
NULL, HFILL }
},
{ &hf_tipcv2_rer_cnt,
{ "Reroute Counter", "tipcv2.rer_cnt",
FT_UINT32, BASE_DEC, NULL, 0x01e00000,
NULL, HFILL }
},
{ &hf_tipcv2_lookup_scope,
{ "Lookup Scope", "tipcv2.lookup_scope",
FT_UINT32, BASE_DEC, VALS(tipcv2_lookup_scope_strings), 0x00180000,
NULL, HFILL }
},
{ &hf_tipcv2_opt_p,
{ "Options Position", "tipcv2.opt_p",
FT_UINT32, BASE_DEC, NULL, 0x00070000,
NULL, HFILL }
},
{ &hf_tipcv2_broadcast_ack_no,
{ "Broadcast Acknowledge Number", "tipcv2.broadcast_ack_no",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
{ &hf_tipcv2_link_level_ack_no,
{ "Link Level Acknowledge Number", "tipcv2.link_level_ack_no",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_link_level_seq_no,
{ "Link Level Sequence Number", "tipcv2.link_level_seq_no",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
#if 0
{ &hf_tipcv2_bcast_seq_no,
{ "Broadcast Sequence Number", "tipcv2.bcast_seq_no",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
#endif
{ &hf_tipcv2_prev_node,
{ "Previous Node", "tipcv2.prev_node",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Previous Node", HFILL }
},
{ &hf_tipcv2_orig_node,
{ "Originating Node", "tipcv2.orig_node",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Originating Node", HFILL }
},
{ &hf_tipcv2_dest_node,
{ "Destination Node", "tipcv2.dest_node",
FT_STRING, BASE_NONE, NULL, 0x0,
"TIPC Destination Node", HFILL }
},
{ &hf_tipcv2_port_name_type,
{ "Port name type", "tipcv2.port_name_type",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
NULL, HFILL }
},
{ &hf_tipcv2_port_name_instance,
{ "Port name instance", "tipcv2.port_name_instance",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
NULL, HFILL }
},
{ &hf_tipcv2_multicast_lower,
{ "Multicast lower bound", "tipcv2.multicast_lower",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"Multicast port name instance lower bound", HFILL }
},
{ &hf_tipcv2_multicast_upper,
{ "Multicast upper bound", "tipcv2.multicast_upper",
FT_UINT32, BASE_DEC, NULL, 0xffffffff,
"Multicast port name instance upper bound", HFILL }
},
{ &hf_tipcv2_sequence_gap,
{ "Sequence Gap", "tipcv2.seq_gap",
FT_UINT32, BASE_DEC, NULL, 0x1FFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_next_sent_broadcast,
{ "Next Sent Broadcast", "tipcv2.next_sent_broadcast",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_fragment_number,
{ "Fragment Number", "tipcv2.fragment_number",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_fragment_msg_number,
{ "Fragment Message Number", "tipcv2.fragment_msg_number",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
{ &hf_tipcv2_next_sent_packet,
{ "Next Sent Packet", "tipcv2.next_sent_packet",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
{ &hf_tipcv2_session_no,
{ "Session Number", "tipcv2.session_no",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_link_prio,
{ "Link Priority", "tipcv2.link_prio",
FT_UINT32, BASE_DEC, NULL, 0x000001F0,
NULL, HFILL }
},
{ &hf_tipcv2_network_plane,
{ "Network Plane", "tipcv2.network_plane",
FT_UINT32, BASE_DEC, VALS(tipcv2_networkplane_strings), 0x0000000E,
NULL, HFILL }
},
{ &hf_tipcv2_probe,
{ "Probe", "tipcv2.probe",
FT_UINT32, BASE_DEC, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_tipcv2_link_tolerance,
{ "Link Tolerance (ms)", "tipcv2.link_tolerance",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
"Link Tolerance in ms", HFILL }
},
{ &hf_tipcv2_bearer_instance,
{ "Bearer Instance", "tipcv2.bearer_instance",
FT_STRINGZ, BASE_NONE, NULL, 0,
"Bearer instance used by the sender node for this link", HFILL }
},
{ &hf_tipcv2_padding,
{ "Padding", "tipcv2.padding",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipcv2_bearer_level_orig_addr,
{ "Bearer Level Originating Address", "tipcv2.bearer_level_orig_addr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipcv2_cluster_address,
{ "Cluster Address", "tipcv2.cluster_address",
FT_STRING, BASE_NONE, NULL, 0x0,
"The remote cluster concerned by the table", HFILL }
},
{ &hf_tipcv2_bitmap,
{ "Bitmap", "tipcv2.bitmap",
FT_BYTES, BASE_NONE, NULL, 0,
"Bitmap, indicating to which nodes within that cluster the sending node has direct links", HFILL }
},
{ &hf_tipcv2_node_address,
{ "Node Address", "tipcv2.node_address",
FT_STRING, BASE_NONE, NULL, 0x0,
"Which node the route addition/loss concern", HFILL }
},
{ &hf_tipcv2_destination_domain,
{ "Destination Domain", "tipcv2.destination_domain",
FT_STRING, BASE_NONE, NULL, 0x0,
"The domain to which the link request is directed", HFILL }
},
{ &hf_tipcv2_network_id,
{ "Network Identity", "tipcv2.network_id",
FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF,
"The sender node's network identity", HFILL }
},
{ &hf_tipcv2_bcast_tag,
{ "Broadcast Tag", "tipcv2.bcast_tag",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_msg_count,
{ "Message Count", "tipcv2.msg_count",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_max_packet,
{ "Max Packet", "tipcv2.max_packet",
FT_UINT32, BASE_DEC, NULL, 0xFFFF0000,
NULL, HFILL }
},
{ &hf_tipcv2_transport_seq_no,
{ "Transport Sequence No", "tipcv2.tseq_no",
FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF,
"Transport Level Sequence Number", HFILL }
},
{ &hf_tipcv2_redundant_link,
{ "Redundant Link", "tipcv2.redundant_link",
FT_UINT32, BASE_DEC, NULL, 0x00001000,
NULL, HFILL }
},
{ &hf_tipcv2_bearer_id,
{ "Bearer identity", "tipcv2.bearer_id",
FT_UINT32, BASE_DEC, NULL, 0x00000e00,
NULL, HFILL }
},
{ &hf_tipcv2_conn_mgr_msg_ack,
{ "Number of Messages Acknowledged", "tipcv2.conn_mgr_msg_ack",
FT_UINT32, BASE_DEC, NULL, 0xffff0000,
NULL, HFILL }
},
{ &hf_tipcv2_minor_pv,
{ "Minor protocol version", "tipcv2.minor_pv",
FT_UINT32, BASE_DEC, NULL, 0x00ff0000,
NULL, HFILL }
},
{ &hf_tipcv2_node_sig,
{ "Node signature", "tipcv2.node_sig",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL }
},
{ &hf_tipcv2_filler_mtu_discovery,
{ "Filler for MTU discovery", "tipcv2.filler_mtu_discovery",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipcv2_vendor_specific_data,
{ "Vendor specific data", "tipcv2.vendor_specific_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipcv2_options,
{ "Options", "tipcv2.options",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipc_named_msg_hdr,
{ "TIPC_NAMED_MSG Hdr", "tipc.named_msg_hdr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipc_port_name_type,
{ "Port name type / Connection level sequence number", "tipc.port_name_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_port_name_instance,
{ "Port name instance", "tipc.port_name_instance",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipc_data_fragment,
{ "Data fragment", "tipc.data_fragment",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipc_message_bundle,
{ "Message Bundle", "tipc.message_bundle",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tipcv2_timestamp,
{ "Timestamp", "tipcv2.timestamp",
FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF,
"OS-dependent Timestamp", HFILL }
},
{ &hf_tipcv2_item_size,
{ "Item Size", "tipcv2.item_size",
FT_UINT32, BASE_DEC, NULL, 0xFF000000,
NULL, HFILL }
},
{ &hf_tipcv2_network_region,
{ "Network Region", "tipcv2.network_region",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipcv2_local_router,
{ "Local Router", "tipcv2.local_router",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipcv2_remote_router,
{ "Remote Router", "tipcv2.remote_router",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipcv2_dist_dist,
{ "Route Distributor Dist", "tipcv2.dist_dist",
FT_UINT32, BASE_DEC, VALS(tipcv2_dist_dist_strings), 0x000000f0,
NULL, HFILL }
},
{ &hf_tipcv2_dist_scope,
{ "Route Distributor Scope", "tipcv2.dist_scope",
FT_UINT32, BASE_DEC, VALS(tipcv2_dist_scope_strings), 0x0000000f,
NULL, HFILL }
},
{ &hf_tipcv2_name_dist_port_id_node,
{ "Port Id Node", "tipcv2.port_id_node",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tipcv2_media_id,
{ "Media Id", "tipcv2.media_id",
FT_UINT32, BASE_DEC, NULL, 0x000000ff,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_tipc,
&ett_tipc_data,
&ett_tipc_msg_fragment,
&ett_tipc_msg_fragments
};
static ei_register_info ei[] = {
{ &ei_tipc_field_not_specified, { "tipc.field_not_specified", PI_PROTOCOL, PI_WARN, "This field is not specified in TIPC v7", EXPFILL }},
};
module_t *tipc_module;
expert_module_t* expert_tipc;
static const enum_val_t handle_v2_as_options[] = {
{ "all", "ALL", V2_AS_ALL },
{ "tipc l.5/1.6", "TIPC 1.5/1.6", V2_AS_1_6 },
{ "tipc 1.7", "TIPC 1.7", V2_AS_1_7 },
{ NULL, NULL, 0 }
};
proto_tipc = proto_register_protocol("Transparent Inter Process Communication(TIPC)", "TIPC", "tipc");
proto_register_field_array(proto_tipc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_tipc = expert_register_protocol(proto_tipc);
expert_register_field_array(expert_tipc, ei, array_length(ei));
tipc_user_dissector = register_dissector_table("tipc.usr",
"TIPC user", proto_tipc, FT_UINT8, BASE_DEC);
tipc_type_dissector = register_dissector_table("tipcv2.port_name_type",
"TIPC port name type", proto_tipc, FT_UINT32, BASE_DEC);
tipc_heur_subdissector_list = register_heur_dissector_list("tipc", proto_tipc);
tipc_handle = register_dissector("tipc", dissect_tipc, proto_tipc);
reassembly_table_register(&tipc_msg_reassembly_table,
&addresses_reassembly_table_functions);
tipc_module = prefs_register_protocol(proto_tipc, NULL);
tipc_address_type = address_type_dissector_register("AT_TIPC", "TIPC Address Zone,Subnetwork,Processor",
tipc_addr_to_str_buf, tipc_addr_str_len, NULL, NULL, NULL, NULL, NULL);
prefs_register_bool_preference(tipc_module, "defragment",
"Reassemble TIPCv1 SEGMENTATION_MANAGER datagrams",
"Whether TIPCv1 SEGMENTATION_MANAGER datagrams should be reassembled",
&tipc_defragment);
prefs_register_bool_preference(tipc_module, "dissect_tipc_data",
"Dissect TIPC data",
"Whether to try to dissect TIPC data or not",
&dissect_tipc_data);
prefs_register_bool_preference(tipc_module, "try_heuristic_first",
"Try heuristic sub-dissectors first",
"Try to decode a TIPCv2 packet using an heuristic sub-dissector before using a registered sub-dissector",
&try_heuristic_first);
prefs_register_enum_preference(tipc_module, "handle_v2_as",
"Handle version 2 as",
"TIPC 1.7 removes/adds fields (not) available in TIPC 1.5/1.6 while keeping the version number 2 in the packages. \"ALL\" shows all fields that were ever used in both versions.",
&handle_v2_as,
handle_v2_as_options,
TRUE);
prefs_register_bool_preference(tipc_module, "desegment",
"Reassemble TIPC-over-TCP messages spanning multiple TCP segments",
"Whether the TIPC-over-TCP dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&tipc_tcp_desegment);
}
void
proto_reg_handoff_tipc(void)
{
dissector_handle_t tipc_tcp_handle;
tipc_tcp_handle = create_dissector_handle(dissect_tipc_tcp, proto_tipc);
ip_handle = find_dissector("ip");
dissector_add_uint("ethertype", ETHERTYPE_TIPC, tipc_handle);
dissector_add_for_decode_as_with_preference("tcp.port", tipc_tcp_handle);
dissector_add_uint_range_with_preference("udp.port", DEFAULT_TIPC_PORT_RANGE, tipc_handle);
}
