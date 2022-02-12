static void
dissect_open_request_message(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *rtcdc_tree, proto_item *rtcdc_item _U_)
{
if (rtcdc_tree) {
proto_tree *flags_tree;
proto_item *flags_item;
proto_tree_add_item(rtcdc_tree, hf_channel_type, tvb, CHANNEL_TYPE_OFFSET, CHANNEL_TYPE_LENGTH, ENC_BIG_ENDIAN);
flags_item = proto_tree_add_item(rtcdc_tree, hf_flags, tvb, FLAGS_OFFSET, FLAGS_LENGTH, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_flags);
proto_tree_add_item(flags_tree, hf_flags_reserved, tvb, FLAGS_OFFSET, FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_unordered_allowed, tvb, FLAGS_OFFSET, FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_reliability, tvb, RELIABILITY_OFFSET, RELIABILITY_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_priority, tvb, PRIORITY_OFFSET, PRIORITY_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_label, tvb, LABEL_OFFSET, -1, ENC_ASCII|ENC_NA);
}
return;
}
static void
dissect_open_response_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtcdc_tree, proto_item *rtcdc_item)
{
if (tvb_reported_length(tvb) > DATA_CHANNEL_RESPONSE_LENGTH) {
expert_add_info(pinfo, rtcdc_item, &ei_rtcdc_message_too_long);
}
if (rtcdc_tree) {
proto_tree_add_item(rtcdc_tree, hf_error, tvb, ERROR_OFFSET, ERROR_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_flags, tvb, FLAGS_OFFSET, FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_sid, tvb, SID_OFFSET, SID_LENGTH, ENC_BIG_ENDIAN);
}
return;
}
static void
dissect_open_ack_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtcdc_tree _U_, proto_item *rtcdc_item)
{
if (tvb_reported_length(tvb) > DATA_CHANNEL_ACK_LENGTH) {
expert_add_info(pinfo, rtcdc_item, &ei_rtcdc_message_too_long);
}
return;
}
static void
dissect_new_open_request_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtcdc_tree, proto_item *rtcdc_item)
{
guint8 channel_type;
guint32 reliability;
guint16 label_length;
guint16 protocol_length;
channel_type = tvb_get_guint8(tvb, NEW_CHANNEL_TYPE_OFFSET);
if ((channel_type & 0x7f) > 0x02) {
expert_add_info(pinfo, rtcdc_item, &ei_rtcdc_new_channel_type);
}
reliability = tvb_get_ntohl(tvb, NEW_RELIABILITY_OFFSET);
if ((reliability > 0) && ((channel_type & 0x7f) == 0x00)) {
expert_add_info(pinfo, rtcdc_item, &ei_rtcdc_new_reliability_non_zero);
}
label_length = tvb_get_ntohs(tvb, NEW_LABEL_LENGTH_OFFSET);
protocol_length = tvb_get_ntohs(tvb, NEW_PROTOCOL_LENGTH_OFFSET);
if (NEW_OPEN_REQUEST_HEADER_LENGTH + (guint)label_length + (guint)protocol_length != tvb_reported_length(tvb)) {
expert_add_info(pinfo, rtcdc_item, &ei_rtcdc_inconsistent_label_and_parameter_length);
}
if (rtcdc_tree) {
proto_tree_add_item(rtcdc_tree, hf_new_channel_type, tvb, NEW_CHANNEL_TYPE_OFFSET, NEW_CHANNEL_TYPE_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_new_priority, tvb, NEW_PRIORITY_OFFSET, NEW_PRIORITY_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_new_reliability, tvb, NEW_RELIABILITY_OFFSET, NEW_RELIABILITY_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_new_label_length, tvb, NEW_LABEL_LENGTH_OFFSET, NEW_LABEL_LENGTH_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_new_protocol_length, tvb, NEW_PROTOCOL_LENGTH_OFFSET, NEW_PROTOCOL_LENGTH_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(rtcdc_tree, hf_new_label, tvb, NEW_LABEL_OFFSET, label_length, ENC_ASCII|ENC_NA);
proto_tree_add_item(rtcdc_tree, hf_new_protocol, tvb, NEW_LABEL_OFFSET + label_length, protocol_length, ENC_ASCII|ENC_NA);
}
return;
}
static int
dissect_rtcdc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *rtcdc_item, *msg_item;
proto_tree *rtcdc_tree;
guint8 message_type;
message_type = tvb_get_guint8(tvb, MESSAGE_TYPE_OFFSET);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTCDC");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_type, message_type_values, "reserved"));
rtcdc_item = proto_tree_add_item(tree, proto_rtcdc, tvb, 0, -1, ENC_NA);
rtcdc_tree = proto_item_add_subtree(rtcdc_item, ett_rtcdc);
msg_item = proto_tree_add_item(rtcdc_tree, hf_message_type, tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, ENC_BIG_ENDIAN);
switch (message_type) {
case DATA_CHANNEL_OPEN_REQUEST:
dissect_open_request_message(tvb, pinfo, rtcdc_tree, rtcdc_item);
break;
case DATA_CHANNEL_OPEN_RESPONSE:
dissect_open_response_message(tvb, pinfo, rtcdc_tree, rtcdc_item);
break;
case DATA_CHANNEL_ACK:
dissect_open_ack_message(tvb, pinfo, rtcdc_tree, rtcdc_item);
break;
case DATA_CHANNEL_NEW_OPEN_REQUEST:
dissect_new_open_request_message(tvb, pinfo, rtcdc_tree, rtcdc_item);
break;
default:
expert_add_info(pinfo, msg_item, &ei_rtcdc_message_type_unknown);
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_rtcdc(void)
{
module_t *rtcdc_module;
expert_module_t *expert_rtcdc;
static hf_register_info hf[] = {
{ &hf_message_type,
{ "Message type", "rtcdc.message_type",
FT_UINT8, BASE_DEC, VALS(message_type_values), 0x0,
NULL, HFILL }
},
{ &hf_channel_type,
{ "Channel type", "rtcdc.channel_type",
FT_UINT8, BASE_DEC, VALS(channel_type_values), 0x0,
NULL, HFILL }
},
{ &hf_flags,
{ "Flags", "rtcdc.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_flags_reserved,
{ "Reserved", "rtcdc.flags_reserved",
FT_UINT16, BASE_HEX, NULL, DATA_CHANNEL_FLAG_RESERVED_MASK,
NULL, HFILL }
},
{ &hf_unordered_allowed,
{ "Unordered allowed", "rtcdc.flags_unordered_allowed",
FT_BOOLEAN, 16, NULL, DATA_CHANNEL_FLAG_OUT_OF_ORDER_ALLOWED_MASK,
NULL, HFILL }
},
{ &hf_reliability,
{ "Reliability parameter", "rtcdc.reliability_parameter",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_priority,
{ "Priority", "rtcdc.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_label,
{ "Label", "rtcdc.label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_error,
{ "Error", "rtcdc.error",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sid,
{ "Reverse stream identifier", "rtcdc.reverse_stream_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_channel_type,
{ "Channel type", "rtcdc.channel_type",
FT_UINT8, BASE_DEC, VALS(new_channel_type_values), 0x0,
NULL, HFILL }
},
{ &hf_new_reliability,
{ "Reliability parameter", "rtcdc.reliability_parameter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_priority,
{ "Priority", "rtcdc.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_label_length,
{ "Label length", "rtcdc.label_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_protocol_length,
{ "Protocol length", "rtcdc.protocol_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_label,
{ "Label", "rtcdc.label",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_new_protocol,
{ "Protocol", "rtcdc.protocol",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_rtcdc,
&ett_flags
};
static ei_register_info ei[] = {
{ &ei_rtcdc_message_too_long, { "rtcdc.message_too_long", PI_MALFORMED, PI_ERROR, "Message too long", EXPFILL }},
{ &ei_rtcdc_new_channel_type, { "rtcdc.channel_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown channel type", EXPFILL }},
{ &ei_rtcdc_new_reliability_non_zero, { "rtcdc.reliability_parameter.non_zero", PI_PROTOCOL, PI_WARN, "Reliability parameter non zero for reliable channel", EXPFILL }},
{ &ei_rtcdc_inconsistent_label_and_parameter_length, { "rtcdc.inconsistent_label_and_parameter_length", PI_MALFORMED, PI_ERROR, "Inconsistent label and parameter length", EXPFILL }},
{ &ei_rtcdc_message_type_unknown, { "rtcdc.message_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown message type", EXPFILL }},
};
proto_rtcdc = proto_register_protocol("WebRTC Datachannel Protocol", "RTCDC", "rtcdc");
proto_register_field_array(proto_rtcdc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rtcdc = expert_register_protocol(proto_rtcdc);
expert_register_field_array(expert_rtcdc, ei, array_length(ei));
rtcdc_module = prefs_register_protocol(proto_rtcdc, proto_reg_handoff_rtcdc);
prefs_register_uint_preference(rtcdc_module, "sctp.ppi", "RTCDC SCTP PPID", "RTCDC SCTP PPID if other than the default", 10, &rtcdc_ppid);
}
void
proto_reg_handoff_rtcdc(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t rtcdc_handle;
static guint32 current_ppid;
if (!initialized) {
rtcdc_handle = create_dissector_handle(dissect_rtcdc, proto_rtcdc);
initialized = TRUE;
} else {
dissector_delete_uint("sctp.ppi", current_ppid, rtcdc_handle);
}
current_ppid = rtcdc_ppid;
dissector_add_uint("sctp.ppi", current_ppid, rtcdc_handle);
}
