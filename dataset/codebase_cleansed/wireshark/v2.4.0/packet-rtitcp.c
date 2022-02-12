static void rtitcp_util_add_error_attribute(proto_tree *attribute, tvbuff_t* tvb,
gint offset, guint size) {
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_error_code_value, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_error_code_description, tvb, offset + 4,
size - 4, ENC_ASCII|ENC_NA);
}
static void rtitcp_util_add_locator_t(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t * tvb,
gint offset, gboolean little_endian,
proto_item * rtitcp_message, gboolean * first_attribute) {
gint32 kind;
guint16 port;
kind = tvb_get_guint16(tvb, offset+8, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (kind == 0xFFFF) {
kind = LOCATOR_KIND_IPV4;
} else {
kind = LOCATOR_KIND_IPV6;
}
proto_tree_add_uint(tree, hf_rtitcp_locator_kind, tvb, offset+8, 2, kind);
if (kind == LOCATOR_KIND_IPV4) {
proto_tree_add_item(tree, hf_rtitcp_locator_port, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rtitcp_locator_ipv4, tvb, offset+12, 4, ENC_BIG_ENDIAN);
port = tvb_get_guint16(tvb, offset+10, little_endian ? ENC_LITTLE_ENDIAN : ENC_BIG_ENDIAN);
if (*first_attribute) {
proto_item_append_text(rtitcp_message," (");
col_append_str(pinfo->cinfo, COL_INFO, " (");
}
proto_item_append_text(rtitcp_message, "%s%s:%u",
*first_attribute ? "" : ", ", tvb_ip_to_str(tvb, offset + 12), port);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s:%u",
*first_attribute ? "" : ", ", tvb_ip_to_str(tvb, offset + 12), port);
} else {
proto_tree_add_item(tree, hf_rtitcp_locator_ipv6, tvb, offset, 16, ENC_NA);
if (*first_attribute) {
proto_item_append_text(rtitcp_message," (");
col_append_str(pinfo->cinfo, COL_INFO, " (");
}
proto_item_append_text(rtitcp_message, "%s%s",
*first_attribute ? "" : ", ", tvb_ip6_to_str(tvb, offset));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
*first_attribute ? "" : ", ", tvb_ip6_to_str(tvb, offset));
}
}
static guint dissect_attribute(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *attributes_list, guint offset, guint attributes_list_offset,
proto_item * rtitcp_message, gboolean * first_attribute) {
guint16 attribute_length, attribute_type;
guint padding;
proto_item *attribute;
attribute_type = tvb_get_guint16(tvb, attributes_list_offset+offset, ENC_BIG_ENDIAN);
attribute_length = tvb_get_guint16(tvb, attributes_list_offset+offset+2, ENC_BIG_ENDIAN);
attribute = proto_tree_add_subtree_format(attributes_list, tvb,
attributes_list_offset+offset, attribute_length+4,
ett_rtitcp_attribute, NULL, "Unknown Attribute");
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_type, tvb,
attributes_list_offset+offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_length, tvb,
attributes_list_offset+offset+2, 2, ENC_BIG_ENDIAN);
proto_item_set_text(attribute,"%s", val_to_str(attribute_type, attribute_types_vals, "Unknown attribute"));
switch (attribute_type) {
case RTPS_LOCATOR_PORT_ATTRIBUTE_TYPE: {
guint32 port;
port = tvb_get_guint32(tvb, attributes_list_offset+offset+4, ENC_BIG_ENDIAN);
if (*first_attribute) {
proto_item_append_text(rtitcp_message," (");
col_append_str(pinfo->cinfo, COL_INFO, " (");
}
proto_item_append_text(rtitcp_message, "%s%u",
*first_attribute ? "" : ", ", port);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%u",
*first_attribute ? "" : ", ", port);
(*first_attribute) = FALSE;
proto_item_append_text(attribute, " (Port = %u)", port);
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_port, tvb,
attributes_list_offset+offset+4, attribute_length, ENC_BIG_ENDIAN);
break;
}
case RTPS_LOCATOR_ADDRESS_ATTRIBUTE_TYPE: {
rtitcp_util_add_locator_t(attribute, pinfo, tvb, attributes_list_offset+offset+4,
ENC_BIG_ENDIAN, rtitcp_message, first_attribute);
(*first_attribute) = FALSE;
break;
}
case CONNECTION_COOKIE_ATTRIBUTE_TYPE: {
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_connection_cookie,
tvb, attributes_list_offset+offset+4, attribute_length, ENC_NA);
if (*first_attribute) {
proto_item_append_text(rtitcp_message," (");
col_append_str(pinfo->cinfo, COL_INFO, " (");
}
proto_item_append_text(rtitcp_message, "%s%s",
(*first_attribute) ? "" : ", ",
tvb_bytes_to_str(wmem_packet_scope(), tvb, attributes_list_offset+offset+4, 16));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
(*first_attribute) ? "" : ", ",
tvb_bytes_to_str(wmem_packet_scope(), tvb, attributes_list_offset+offset+4, 16));
(*first_attribute) = FALSE;
break;
}
case CONNECTION_TYPE_ATTRIBUTE_TYPE: {
guint8 attribute_connection_type = tvb_get_guint8(tvb, attributes_list_offset+offset+4);
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_connection_type, tvb,
attributes_list_offset+offset+4, attribute_length, ENC_BIG_ENDIAN);
if (*first_attribute) {
proto_item_append_text(rtitcp_message," (");
col_append_str(pinfo->cinfo, COL_INFO, " (");
}
proto_item_append_text(rtitcp_message, "%s%s",
(*first_attribute) ? "" : ", ",
val_to_str(attribute_connection_type, rtitcp_attribute_connection_type_vals, "Unknown attribute"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s",
(*first_attribute) ? "" : ", ",
val_to_str(attribute_connection_type, rtitcp_attribute_connection_type_vals, "Unknown attribute"));
(*first_attribute) = FALSE;
break;
}
case SESSION_ID_ATTRIBUTE_TYPE: {
proto_tree_add_item(attribute, hf_rtitcp_control_attribute_session_id, tvb,
attributes_list_offset+offset+4, attribute_length, ENC_NA);
break;
}
case ERROR_CODE_ATTRIBUTE_TYPE: {
rtitcp_util_add_error_attribute(attribute, tvb, attributes_list_offset+offset+4, attribute_length);
break;
}
default:
break;
}
padding = (4 - attribute_length%4)%4;
return (attribute_length+padding+4);
}
static proto_tree* print_header(proto_tree *tree, proto_tree *rtitcp_message, tvbuff_t *tvb, guint offset,
guint16 msg_length, gboolean printCRC, gboolean is_data) {
proto_item *ti;
if (is_data) {
rtitcp_message = proto_tree_add_subtree_format(tree, tvb, offset, msg_length,
ett_rtitcp_message, NULL, "RTI TCP Data Message");
} else {
rtitcp_message = proto_tree_add_subtree_format(tree, tvb, offset, msg_length,
ett_rtitcp_message, NULL, "RTI TCP Control Message");
}
if (is_data) {
guint32 msg_length32;
proto_tree_add_item(rtitcp_message, hf_rtitcp_header_control_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(rtitcp_message, hf_rtitcp_header_message_length,
tvb, offset+1, 3, ENC_BIG_ENDIAN);
msg_length32 = tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN);
msg_length32 = msg_length32 % NUMBER_2E30;
proto_item_set_text(ti,"RTI TCP Message Length: %d", msg_length32);
} else {
proto_tree_add_item(rtitcp_message, hf_rtitcp_header_control_byte, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rtitcp_message, hf_rtitcp_header_message_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(rtitcp_message, hf_rtitcp_header_magic_number, tvb, offset+4, 4, ENC_BIG_ENDIAN);
if (printCRC) {
proto_tree_add_item(rtitcp_message, hf_rtitcp_crc_magic_cookie, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rtitcp_message, hf_rtitcp_control_crc_value, tvb, offset+12, 4, ENC_BIG_ENDIAN);
}
return rtitcp_message;
}
static guint16 dissect_control_message(proto_tree *rtitcp_tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset) {
proto_tree *attributes_list, *rtitcp_message = NULL;
guint16 msg_length, control_message_kind, attributes_list_length, header_length;
guint attributes_list_offset, attribute_offset, offset_header = offset;
guint attributes_count;
gboolean is_data = FALSE, printCRC = FALSE, first_attribute;
gchar * transaction_id_str;
guint64 seq_num;
conversation_t *conversation;
rtitcp_conv_info_t *rtitcp_info;
rtitcp_transaction_t *rtitcp_trans;
guint64 * conversation_info_key = NULL;
header_length = 8;
msg_length = tvb_get_guint16(tvb, offset+2, ENC_BIG_ENDIAN);
offset += 8;
if (tvb_get_ntohl(tvb, offset) == RTITCP_CRC_MAGIC_NUMBER) {
printCRC = TRUE;
header_length += 8;
offset += 8;
}
rtitcp_message = print_header(rtitcp_tree, rtitcp_message, tvb, offset_header, msg_length + header_length, printCRC, is_data);
control_message_kind = tvb_get_guint16(tvb, offset, ENC_BIG_ENDIAN);
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ",
val_to_str(control_message_kind,ctrl_message_types_vals, "Unknown control message"));
proto_tree_add_uint(rtitcp_message, hf_rtitcp_control_kind, tvb, offset, 2, control_message_kind);
proto_item_set_text(rtitcp_message,"RTI TCP Control Message , Kind: %s",
val_to_str(control_message_kind,ctrl_message_types_vals, "Unknown control message"));
offset += 2;
attributes_list_length = tvb_get_guint16(tvb, offset, ENC_BIG_ENDIAN);
proto_tree_add_item(rtitcp_message, hf_rtitcp_attributes_list_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_get_ntohl(tvb, offset) != RTITCP_CONTROL_MAGIC_COOKIE) {
return msg_length + header_length;
}
proto_tree_add_item(rtitcp_message, hf_rtitcp_control_magic_cookie, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rtitcp_message, hf_rtitcp_control_transaction_id, tvb, offset, 12, ENC_NA);
transaction_id_str = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 12);
seq_num = tvb_get_ntoh64(tvb, offset);
conversation = find_or_create_conversation(pinfo);
rtitcp_info = (rtitcp_conv_info_t *)conversation_get_proto_data(conversation, proto_rtitcp);
if (!rtitcp_info) {
rtitcp_info = wmem_new(wmem_file_scope(), rtitcp_conv_info_t);
rtitcp_info->pdus=wmem_map_new(wmem_file_scope(), g_int64_hash, g_int64_equal);
conversation_add_proto_data(conversation, proto_rtitcp, rtitcp_info);
}
if (!pinfo->fd->flags.visited) {
if (!(control_message_kind & RTITCP_FLAG_NOT_REQUEST)) {
rtitcp_trans=wmem_new(wmem_file_scope(), rtitcp_transaction_t);
rtitcp_trans->req_frame = pinfo->num;
rtitcp_trans->rep_frame = 0;
rtitcp_trans->req_time = pinfo->abs_ts;
conversation_info_key = (guint64*)wmem_alloc0(wmem_file_scope(), sizeof(guint64));
*conversation_info_key = seq_num;
wmem_map_insert(rtitcp_info->pdus, conversation_info_key, (void *)rtitcp_trans);
} else {
conversation_info_key = &seq_num;
rtitcp_trans=(rtitcp_transaction_t *)wmem_map_lookup(rtitcp_info->pdus, conversation_info_key);
if (rtitcp_trans) {
rtitcp_trans->rep_frame = pinfo->num;
}
}
} else {
conversation_info_key = &seq_num;
rtitcp_trans=(rtitcp_transaction_t *)wmem_map_lookup(rtitcp_info->pdus, conversation_info_key);
}
if (!rtitcp_trans) {
rtitcp_trans=wmem_new(wmem_packet_scope(), rtitcp_transaction_t);
rtitcp_trans->req_frame = 0;
rtitcp_trans->rep_frame = 0;
rtitcp_trans->req_time = pinfo->abs_ts;
}
if (!(control_message_kind & RTITCP_FLAG_NOT_REQUEST)) {
if (rtitcp_trans->rep_frame) {
proto_item *it;
it = proto_tree_add_uint(rtitcp_message, hf_rtitcp_response_in,
tvb, 0, 0, rtitcp_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if (rtitcp_trans->req_frame) {
proto_item *it;
nstime_t ns;
it = proto_tree_add_uint(rtitcp_message, hf_rtitcp_response_to,
tvb, 0, 0, rtitcp_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->abs_ts, &rtitcp_trans->req_time);
it = proto_tree_add_time(rtitcp_message, hf_rtitcp_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
offset += 12;
attributes_list_offset = 0;
attributes_list = proto_tree_add_subtree_format(rtitcp_message, tvb,
attributes_list_offset+offset, attributes_list_length,
ett_rtitcp_attributes_list, NULL, "Attributes List");
attributes_count = 0;
first_attribute = TRUE;
while (attributes_list_offset < attributes_list_length) {
++attributes_count;
attribute_offset = dissect_attribute(tvb, pinfo, attributes_list,
offset, attributes_list_offset, rtitcp_message, &first_attribute);
attributes_list_offset += attribute_offset;
}
if (!first_attribute) {
proto_item_append_text(rtitcp_message,")");
col_append_str(pinfo->cinfo, COL_INFO, ")");
}
proto_item_set_text(attributes_list, "Attributes list [%d attribute%s",
attributes_count, attributes_count > 1 ? "s]" : "]");
proto_item_append_text(rtitcp_message,", Transaction ID: %s, Len: %d",
transaction_id_str, msg_length);
return msg_length + header_length;
}
static guint dissect_rtitcp_control_protocol(proto_tree *rtitcp_tree, tvbuff_t *tvb, packet_info *pinfo) {
guint messages_count, offset;
guint16 msg_length;
guint32 tvb_len;
offset = 0;
tvb_len = tvb_reported_length(tvb);
messages_count = 0;
while (offset < tvb_len) {
msg_length = dissect_control_message(rtitcp_tree, tvb, pinfo, offset);
offset += msg_length;
++messages_count;
}
return offset;
}
static gint dissect_rtitcp_common(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_) {
proto_item *ti;
proto_tree *rtitcp_tree, *rtitcp_message = NULL;
guint offset, offset_header;
guint16 rtitcp_msg_length, header_length;
guint32 tvb_len, rtitcp_rtps_msg_length;
gboolean printCRC = FALSE, is_data = FALSE;
tvbuff_t *next_tvb;
heur_dtbl_entry_t *hdtbl_entry;
offset = 0;
tvb_len = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTI-TCP");
rtitcp_msg_length = tvb_get_guint16(tvb, offset+2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(tree, proto_rtitcp, tvb, offset, -1, ENC_NA);
rtitcp_tree = proto_item_add_subtree(ti, ett_rtitcp);
offset_header = 0;
header_length = 8;
offset += 2;
offset += 2;
offset += 4;
if (tvb_get_ntohl(tvb, offset) == RTITCP_CRC_MAGIC_NUMBER) {
printCRC = TRUE;
header_length += 8;
offset += 8;
}
proto_item_set_len(ti, rtitcp_msg_length + header_length);
if (tvb_get_ntohl(tvb, offset) == RTPS_MAGIC_NUMBER) {
if (tvb_len > (guint32)(rtitcp_msg_length + header_length)) {
tvb_set_reported_length(tvb, (rtitcp_msg_length + header_length));
}
rtitcp_rtps_msg_length = tvb_get_guint32(tvb, 0, ENC_BIG_ENDIAN);
rtitcp_rtps_msg_length = rtitcp_rtps_msg_length % NUMBER_2E30;
is_data = TRUE;
rtitcp_message = print_header(rtitcp_tree, rtitcp_message, tvb, offset_header,
rtitcp_rtps_msg_length + header_length, printCRC, is_data);
proto_item_set_text(rtitcp_message,"RTI TCP Data Message, Len: %d",
rtitcp_rtps_msg_length);
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree, &hdtbl_entry, NULL);
return tvb_captured_length(tvb);
} else {
return dissect_rtitcp_control_protocol(rtitcp_tree, tvb, pinfo);
}
}
static guint get_rtitcp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
gint offset, void * data _U_) {
guint16 plen;
guint16 header_length = 8;
plen = tvb_get_guint16(tvb, offset+2, ENC_BIG_ENDIAN);
if (tvb_get_ntohl(tvb, offset+8) == RTITCP_CRC_MAGIC_NUMBER)
header_length += 8;
if (plen >= 0xfff8)
return 1;
return plen + header_length;
}
static gint dissect_rtitcp(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_) {
gboolean desegmentation = TRUE;
if (tvb_captured_length(tvb) < 8)
return 0;
if (tvb_get_ntohl(tvb, 4) != RTITCP_MAGIC_NUMBER)
return 0;
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, desegmentation, RTITCP_MIN_LENGTH,
get_rtitcp_pdu_len, dissect_rtitcp_common, data);
return tvb_captured_length(tvb);
}
void
proto_register_rtitcp(void)
{
static hf_register_info hf[] = {
{ &hf_rtitcp_header_control_byte, {
"Control Byte", "rtitcp.header.control_byte",
FT_UINT8, BASE_HEX, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_header_message_length, {
"Message Length", "rtitcp.header.message_length",
FT_UINT16, BASE_DEC, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_header_magic_number, {
"Magic Cookie", "rtitcp.header.magic_cookie",
FT_UINT32, BASE_HEX, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_crc_magic_cookie, {
"CRC Magic Cookie", "rtitcp.header.crc_magic_cookie",
FT_UINT32, BASE_HEX, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_kind,
{ "Kind", "rtitcp.control.kind",
FT_UINT16, BASE_HEX, VALS(ctrl_message_types_vals), 0,
NULL, HFILL }
},
{ &hf_rtitcp_control_magic_cookie, {
"Control Magic Cookie", "rtitcp.control.magic_cookie",
FT_UINT32, BASE_HEX, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_transaction_id, {
"Transaction ID", "rtitcp.control.transaction_id",
FT_BYTES, BASE_NONE, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_attribute_session_id, {
"Session ID", "rtitcp.control.attribute.session_id",
FT_BYTES, BASE_NONE, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_attribute_type,
{ "Attribute Type", "rtitcp.control.attribute_type",
FT_UINT16, BASE_HEX, VALS(attribute_types_vals), 0,
NULL, HFILL }
},
{ &hf_rtitcp_control_attribute_error_code_value,
{ "Kind", "rtitcp.control.attribute.error_code",
FT_UINT32, BASE_HEX, VALS(error_code_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtitcp_control_attribute_error_code_description, {
"Description", "rtitcp.control.attribute.error_code.description",
FT_STRING, BASE_NONE, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_attribute_connection_cookie, {
"Connection Cookie", "rtitcp.control.attribute.connection_cookie",
FT_BYTES, BASE_NONE, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_attribute_connection_type, {
"Class ID", "rtitcp.control_attribute.connection_type",
FT_UINT8, BASE_HEX, VALS(rtitcp_attribute_connection_type_vals), 0,
0, HFILL }
},
{ &hf_rtitcp_attributes_list_length, {
"Attributes list length", "rtitcp.attributes_list_length",
FT_UINT16, BASE_DEC, NULL, 0,
0,
HFILL }
},
{ &hf_rtitcp_control_attribute_length, {
"Attribute Length", "rtitcp.control.attribute.length",
FT_UINT16, BASE_DEC, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_control_attribute_port, {
"Port", "rtitcp.control.attribute_port",
FT_UINT32, BASE_DEC, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_locator_kind,
{ "Kind", "rtitcp.locator.kind",
FT_UINT16, BASE_DEC, VALS(rtitcp_locator_kind_vals), 0,
NULL, HFILL }
},
{ &hf_rtitcp_locator_ipv4,
{ "Address", "rtitcp.locator.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtitcp_locator_port,
{ "Port", "rtitcp.locator.port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_rtitcp_locator_ipv6,
{ "Address", "rtitcp.locator.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_rtitcp_control_crc_value, {
"CRC", "rtitcp.control.crc",
FT_UINT32, BASE_HEX, NULL, 0,
0, HFILL }
},
{ &hf_rtitcp_response_in, {
"Response In", "rtitcp.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this RTITCP request is in this frame", HFILL }
},
{ &hf_rtitcp_response_to, {
"Request In", "rtitcp.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the RTITCP request in this frame", HFILL }
},
{ &hf_rtitcp_response_time, {
"Response Time", "rtitcp.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Request and the Reply", HFILL }
},
};
static gint *ett[] = {
&ett_rtitcp,
&ett_rtitcp_signalling_protocol,
&ett_rtitcp_message,
&ett_rtitcp_attributes_list,
&ett_rtitcp_attribute
};
proto_rtitcp = proto_register_protocol("RTI TCP Transport Protocol",
"RTITCP", "rtitcp");
hfi_rtitcp = proto_registrar_get_nth(proto_rtitcp);
proto_register_field_array(proto_rtitcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rtitcp", dissect_rtitcp, proto_rtitcp);
heur_subdissector_list = register_heur_dissector_list("rtitcp", proto_rtitcp);
}
void
proto_reg_handoff_rtitcp(void)
{
heur_dissector_add("tcp", dissect_rtitcp, "RTI TCP Layer" , "rtitcp", proto_rtitcp, HEURISTIC_ENABLE);
}
