static guint
nr_of_padding_bytes (guint length)
{
guint remainder;
remainder = length % 4;
if (remainder == 0)
return 0;
else
return 4 - remainder;
}
static void
dissect_m2tp_common_header(tvbuff_t *common_header_tvb, packet_info *pinfo, proto_tree *m2tp_tree)
{
guint8 version, reserved, message_class, message_type;
guint32 message_length;
version = tvb_get_guint8(common_header_tvb, VERSION_OFFSET);
reserved = tvb_get_guint8(common_header_tvb, RESERVED_OFFSET);
message_class = tvb_get_guint8(common_header_tvb, MESSAGE_CLASS_OFFSET);
message_type = tvb_get_guint8(common_header_tvb, MESSAGE_TYPE_OFFSET);
message_length = tvb_get_ntohl (common_header_tvb, MESSAGE_LENGTH_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_class * 256 + message_type, m2tp_message_class_type_acro_values, "reserved"));
if (m2tp_tree) {
proto_tree_add_uint(m2tp_tree, hf_m2tp_version, common_header_tvb, VERSION_OFFSET, VERSION_LENGTH, version);
proto_tree_add_uint(m2tp_tree, hf_m2tp_reserved, common_header_tvb, RESERVED_OFFSET, RESERVED_LENGTH, reserved);
proto_tree_add_uint(m2tp_tree, hf_m2tp_message_class, common_header_tvb, MESSAGE_CLASS_OFFSET, MESSAGE_CLASS_LENGTH, message_class);
proto_tree_add_uint_format_value(m2tp_tree, hf_m2tp_message_type,
common_header_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH,
message_type, "%u (%s)",
message_type, val_to_str_const(message_class * 256 + message_type, m2tp_message_class_type_values, "reserved"));
proto_tree_add_uint(m2tp_tree, hf_m2tp_message_length, common_header_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, message_length);
};
}
static void
dissect_m2tp_interface_identifier_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 parameter_value;
if (parameter_tree) {
parameter_value = tvb_get_ntohl(parameter_tvb, PARAMETER_VALUE_OFFSET);
proto_tree_add_uint(parameter_tree, hf_m2tp_interface_identifier, parameter_tvb, INTERFACE_IDENTIFIER_OFFSET, INTERFACE_IDENTIFIER_LENGTH, parameter_value);
proto_item_set_text(parameter_item, "Interface Identifier (%u)", parameter_value);
}
}
static void
dissect_m2tp_master_slave_parameter (tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 parameter_value;
if (parameter_tree) {
parameter_value = tvb_get_ntohl(parameter_tvb, PARAMETER_VALUE_OFFSET);
proto_tree_add_uint(parameter_tree, hf_m2tp_master_slave, parameter_tvb, MASTER_SLAVE_OFFSET, MASTER_SLAVE_LENGTH, parameter_value);
proto_item_set_text(parameter_item, "Master Slave Indicator (%s)", val_to_str_const(parameter_value, m2tp_mode_values, "unknown"));
}
}
static void
dissect_m2tp_user_identifier_parameter (tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 parameter_value;
if (parameter_tree) {
parameter_value = tvb_get_ntohl(parameter_tvb, PARAMETER_VALUE_OFFSET);
proto_tree_add_uint(parameter_tree, hf_m2tp_user, parameter_tvb, M2TP_USER_OFFSET, M2TP_USER_LENGTH, parameter_value);
proto_item_set_text(parameter_item, "M2TP User Identifier (%u)", parameter_value);
}
}
static void
dissect_m2tp_info_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, info_string_length;
const guint8 *info_string;
if (parameter_tree) {
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
info_string_length = length - PARAMETER_HEADER_LENGTH;
proto_tree_add_item_ret_string(parameter_tree, hf_m2tp_info_string, parameter_tvb, INFO_STRING_OFFSET, info_string_length, ENC_ASCII, wmem_packet_scope(), &info_string);
proto_item_set_text(parameter_item, "Info String (%.*s)", info_string_length, info_string);
}
}
static void
dissect_m2tp_diagnostic_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, diagnostic_info_length;
if (parameter_tree) {
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
diagnostic_info_length = length - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_m2tp_diagnostic_info, parameter_tvb, PARAMETER_VALUE_OFFSET, diagnostic_info_length, ENC_NA);
proto_item_set_text(parameter_item, "Diagnostic information (%u byte%s)", diagnostic_info_length, plurality(diagnostic_info_length, "", "s"));
}
}
static void
dissect_m2tp_heartbeat_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 length, heartbeat_data_length;
if (parameter_tree) {
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
heartbeat_data_length = length - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_m2tp_heartbeat_data, parameter_tvb, PARAMETER_VALUE_OFFSET, heartbeat_data_length, ENC_NA);
proto_item_set_text(parameter_item, "Heartbeat data (%u byte%s)", heartbeat_data_length, plurality(heartbeat_data_length, "", "s"));
}
}
static void
dissect_m2tp_reason_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 reason;
if (parameter_tree) {
reason = tvb_get_ntohl(parameter_tvb, REASON_OFFSET);
proto_tree_add_uint(parameter_tree, hf_m2tp_reason, parameter_tvb, REASON_OFFSET, REASON_LENGTH, reason);
proto_item_set_text(parameter_item, "Reason parameter (%s)", val_to_str_const(reason, m2tp_reason_code_values, "unknown"));
}
}
static void
dissect_m2tp_error_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 error_code;
if (parameter_tree) {
error_code = tvb_get_ntohl(parameter_tvb, ERROR_CODE_OFFSET);
proto_tree_add_uint(parameter_tree, hf_m2tp_error_code, parameter_tvb, ERROR_CODE_OFFSET, ERROR_CODE_LENGTH, error_code);
proto_item_set_text(parameter_item, "Error code parameter (%s)", val_to_str_const(error_code, m2tp_error_code_values, "unknown"));
}
}
static void
dissect_m2tp_protocol_data_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, packet_info *pinfo, proto_item *m2tp_item, proto_tree *tree)
{
guint16 length, protocol_data_length, padding_length;
tvbuff_t *mtp2_tvb;
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = nr_of_padding_bytes(length);
protocol_data_length = length - PARAMETER_HEADER_LENGTH;
mtp2_tvb = tvb_new_subset_length(parameter_tvb, PARAMETER_VALUE_OFFSET, protocol_data_length);
call_dissector(mtp2_handle, mtp2_tvb, pinfo, tree);
if (parameter_tree) {
proto_item_set_text(parameter_item, "Protocol data (SS7 message)");
proto_item_set_len(parameter_item, proto_item_get_len(parameter_item) - protocol_data_length - padding_length);
proto_item_set_len(m2tp_item, proto_item_get_len(m2tp_item) - protocol_data_length - padding_length);
}
}
static void
dissect_m2tp_unknown_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 tag, length, parameter_value_length;
if (parameter_tree) {
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
parameter_value_length = length - PARAMETER_HEADER_LENGTH;
proto_tree_add_item(parameter_tree, hf_m2tp_parameter_value, parameter_tvb, PARAMETER_VALUE_OFFSET, parameter_value_length, ENC_NA);
proto_item_set_text(parameter_item, "Parameter with tag %u and %u byte%s value", tag, parameter_value_length, plurality(parameter_value_length, "", "s"));
}
}
static void
dissect_m2tp_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *m2tp_tree, proto_item *m2tp_item, proto_tree *tree)
{
guint16 tag, length, padding_length, total_length;
proto_item *parameter_item = NULL;
proto_tree *parameter_tree = NULL;
tag = tvb_get_ntohs(parameter_tvb, PARAMETER_TAG_OFFSET);
length = tvb_get_ntohs(parameter_tvb, PARAMETER_LENGTH_OFFSET);
padding_length = nr_of_padding_bytes(length);
total_length = length + padding_length;
if (tree) {
parameter_tree = proto_tree_add_subtree(m2tp_tree, parameter_tvb, PARAMETER_HEADER_OFFSET, total_length,
ett_m2tp_parameter, &parameter_item, "Incomplete parameter");
proto_tree_add_uint(parameter_tree, hf_m2tp_parameter_tag, parameter_tvb, PARAMETER_TAG_OFFSET, PARAMETER_TAG_LENGTH, tag);
proto_tree_add_uint(parameter_tree, hf_m2tp_parameter_length, parameter_tvb, PARAMETER_LENGTH_OFFSET, PARAMETER_LENGTH_LENGTH, length);
}
switch(tag) {
case INTERFACE_IDENTIFIER_PARAMETER_TAG:
dissect_m2tp_interface_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case MASTER_SLAVE_INDICATOR_PARAMETER_TAG:
dissect_m2tp_master_slave_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case M2TP_USER_IDENTIFIER_PARAMETER_TAG:
dissect_m2tp_user_identifier_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case INFO_PARAMETER_TAG:
dissect_m2tp_info_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case DIAGNOSTIC_INFORMATION_PARAMETER_TAG:
dissect_m2tp_diagnostic_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case HEARTBEAT_DATA_PARAMETER_TAG:
dissect_m2tp_heartbeat_data_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case REASON_PARAMETER_TAG:
dissect_m2tp_reason_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ERROR_CODE_PARAMETER_TAG:
dissect_m2tp_error_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PROTOCOL_DATA_PARAMETER_TAG:
dissect_m2tp_protocol_data_parameter(parameter_tvb, parameter_tree, parameter_item, pinfo, m2tp_item, tree);
break;
default:
dissect_m2tp_unknown_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
};
if ((parameter_tree) && (padding_length > 0))
proto_tree_add_item(parameter_tree, hf_m2tp_parameter_padding, parameter_tvb, PARAMETER_HEADER_OFFSET + length, padding_length, ENC_NA);
}
static void
dissect_m2tp_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_item *m2tp_item, proto_tree *m2tp_tree, proto_tree *tree)
{
gint offset, length, padding_length, total_length;
tvbuff_t *common_header_tvb, *parameter_tvb;
offset = 0;
common_header_tvb = tvb_new_subset_length(message_tvb, offset, COMMON_HEADER_LENGTH);
dissect_m2tp_common_header(common_header_tvb, pinfo, m2tp_tree);
offset += COMMON_HEADER_LENGTH;
while(tvb_reported_length_remaining(message_tvb, offset) > 0) {
length = tvb_get_ntohs(message_tvb, offset + PARAMETER_LENGTH_OFFSET);
padding_length = nr_of_padding_bytes(length);
total_length = length + padding_length;
parameter_tvb = tvb_new_subset_length(message_tvb, offset, total_length);
dissect_m2tp_parameter(parameter_tvb, pinfo, m2tp_tree, m2tp_item, tree);
offset += total_length;
}
}
static int
dissect_m2tp(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *m2tp_item;
proto_tree *m2tp_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "M2TP");
m2tp_item = proto_tree_add_item(tree, proto_m2tp, message_tvb, 0, -1, ENC_NA);
m2tp_tree = proto_item_add_subtree(m2tp_item, ett_m2tp);
dissect_m2tp_message(message_tvb, pinfo, m2tp_item, m2tp_tree, tree);
return tvb_captured_length(message_tvb);
}
void
proto_register_m2tp(void)
{
static hf_register_info hf[] = {
{ &hf_m2tp_version,
{ "Version", "m2tp.version",
FT_UINT8, BASE_DEC, VALS(m2tp_protocol_version_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_reserved,
{ "Reserved", "m2tp.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_message_class,
{ "Message class", "m2tp.message_class",
FT_UINT8, BASE_DEC, VALS(m2tp_message_class_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_message_type,
{ "Message Type", "m2tp.message_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_message_length,
{ "Message length", "m2tp.message_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_parameter_tag,
{ "Parameter Tag", "m2tp.parameter_tag",
FT_UINT16, BASE_DEC, VALS(m2tp_parameter_tag_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_parameter_length,
{ "Parameter length", "m2tp.parameter_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_parameter_value,
{ "Parameter Value", "m2tp.parameter_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_m2tp_parameter_padding,
{ "Padding", "m2tp.parameter_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_m2tp_interface_identifier,
{ "Interface Identifier", "m2tp.interface_identifier",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_user,
{ "M2tp User Identifier", "m2tp.user_identifier",
FT_UINT32, BASE_DEC, VALS(m2tp_user_identifier_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_master_slave,
{ "Master Slave Indicator", "m2tp.master_slave",
FT_UINT32, BASE_DEC, VALS(m2tp_mode_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_info_string,
{ "Info string", "m2tp.info_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_m2tp_diagnostic_info,
{ "Diagnostic information", "m2tp.diagnostic_info",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_m2tp_heartbeat_data,
{ "Heartbeat data", "m2tp.heartbeat_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_m2tp_error_code,
{ "Error code", "m2tp.error_code",
FT_UINT32, BASE_DEC, VALS(m2tp_error_code_values), 0x0,
NULL, HFILL}
},
{ &hf_m2tp_reason,
{ "Reason", "m2tp.reason",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_m2tp,
&ett_m2tp_parameter,
};
proto_m2tp = proto_register_protocol("MTP 2 Transparent Proxy", "M2TP", "m2tp");
proto_register_field_array(proto_m2tp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_m2tp(void)
{
dissector_handle_t m2tp_handle;
mtp2_handle = find_dissector_add_dependency("mtp2", proto_m2tp);
m2tp_handle = create_dissector_handle(dissect_m2tp, proto_m2tp);
dissector_add_uint("sctp.ppi", M2TP_PAYLOAD_PROTOCOL_ID, m2tp_handle);
dissector_add_uint("sctp.port", SCTP_PORT_M2TP, m2tp_handle);
}
