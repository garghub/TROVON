static void
dissect_zcl_met_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_SE_ATTR_REPORT_STATUS_MET:
proto_tree_add_item(tree, hf_zbee_zcl_met_attr_reporting_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_met(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_met_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_met_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_met, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MET_REQUEST_MIRROR_RSP:
break;
case ZBEE_ZCL_CMD_ID_MET_GET_SNAPSHOT:
break;
case ZBEE_ZCL_CMD_ID_MET_GET_SAMPLED_DATA:
break;
case ZBEE_ZCL_CMD_ID_MET_LOCAL_CHANGE_SUPPLY:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_met_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_met_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_met, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MET_REQUEST_MIRROR:
break;
case ZBEE_ZCL_CMD_ID_MET_PUBLISH_SNAPSHOT:
break;
case ZBEE_ZCL_CMD_ID_MET_GET_SAMPLED_DATA_RSP:
break;
case ZBEE_ZCL_CMD_ID_MET_CONFIGURE_MIRROR:
break;
case ZBEE_ZCL_CMD_ID_MET_GET_NOTIFIED_MESSAGE:
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_met(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_met_attr_id,
{ "Attribute", "zbee_zcl_se.met.attr_id", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &zbee_zcl_met_attr_names_ext,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_met_attr_reporting_status,
{ "Attribute Reporting Status", "zbee_zcl_se.met.attr.attr_reporting_status",
FT_UINT8, BASE_HEX, VALS(zbee_zcl_se_reporting_status_names), 0x00, NULL, HFILL } },
{ &hf_zbee_zcl_met_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.met.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_met_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_met_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.met.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_met_srv_rx_cmd_names),
0x00, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_met,
};
proto_zbee_zcl_met = proto_register_protocol("ZigBee ZCL Metering", "ZCL Metering", ZBEE_PROTOABBREV_ZCL_MET);
proto_register_field_array(proto_zbee_zcl_met, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
met_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_MET, dissect_zbee_zcl_met, proto_zbee_zcl_met);
}
void
proto_reg_handoff_zbee_zcl_met(void)
{
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_SIMPLE_METERING, met_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_met,
ett_zbee_zcl_met,
ZBEE_ZCL_CID_SIMPLE_METERING,
hf_zbee_zcl_met_attr_id,
hf_zbee_zcl_met_srv_rx_cmd_id,
hf_zbee_zcl_met_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_met_attr_data
);
}
static void
dissect_zcl_msg_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_SE_ATTR_REPORT_STATUS_MSG:
proto_tree_add_item(tree, hf_zbee_zcl_msg_attr_reporting_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_msg_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_msg_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_msg, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MSG_GET_LAST_MSG:
break;
case ZBEE_ZCL_CMD_ID_MSG_MSG_CONFIRM:
dissect_zcl_msg_confirm(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_MSG_GET_MESSAGE_CANCEL:
dissect_zcl_msg_get_cancel(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_msg_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_msg_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_msg, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MSG_DISPLAY_MSG:
dissect_zcl_msg_display(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_MSG_CANCEL_MSG:
dissect_zcl_msg_cancel(tvb, pinfo, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_MSG_DISPLAY_PROTECTED_MSG:
dissect_zcl_msg_display(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_MSG_CANCEL_ALL_MSG:
dissect_zcl_msg_cancel_all(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
static void
dissect_zcl_msg_display(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint msg_len;
guint8 *msg_data;
static const int * message_ctrl_flags[] = {
&hf_zbee_zcl_msg_ctrl_tx,
&hf_zbee_zcl_msg_ctrl_importance,
&hf_zbee_zcl_msg_ctrl_enh_confirm,
&hf_zbee_zcl_msg_ctrl_reserved,
&hf_zbee_zcl_msg_ctrl_confirm,
NULL
};
static const int * message_ext_ctrl_flags[] = {
&hf_zbee_zcl_msg_ext_ctrl_status,
NULL
};
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_msg_ctrl, ett_zbee_zcl_msg_message_control, message_ctrl_flags, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_msg_start_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_msg_duration, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
msg_len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_length, tvb, *offset, 1, ENC_NA);
*offset += 1;
msg_data = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, msg_len, ENC_LITTLE_ENDIAN);
proto_tree_add_string(tree, hf_zbee_zcl_msg_message, tvb, *offset, msg_len, msg_data);
*offset += msg_len;
if (tvb_reported_length_remaining(tvb, *offset) > 0) {
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_msg_ext_ctrl, ett_zbee_zcl_msg_ext_message_control, message_ext_ctrl_flags, ENC_NA);
*offset += 1;
}
}
static void
dissect_zcl_msg_cancel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint *offset)
{
gint8 msg_ctrl;
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
msg_ctrl = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_msg_ctrl, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (msg_ctrl != 0x00) {
expert_add_info(pinfo, tree, &ei_zbee_zcl_msg_msg_ctrl_depreciated);
}
}
static void
dissect_zcl_msg_cancel_all(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
nstime_t impl_time;
impl_time.secs = tvb_get_letohl(tvb, *offset) + ZBEE_ZCL_NSTIME_UTC_OFFSET;
impl_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_msg_implementation_time, tvb, *offset, 4, &impl_time);
*offset += 4;
}
static void
dissect_zcl_msg_get_cancel(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
nstime_t impl_time;
impl_time.secs = tvb_get_letohl(tvb, *offset) + ZBEE_ZCL_NSTIME_UTC_OFFSET;
impl_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_msg_earliest_time, tvb, *offset, 4, &impl_time);
*offset += 4;
}
static void
dissect_zcl_msg_confirm(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint msg_len;
guint8 *msg_data;
nstime_t confirm_time;
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
confirm_time.secs = tvb_get_letohl(tvb, *offset) + ZBEE_ZCL_NSTIME_UTC_OFFSET;
confirm_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_msg_confirm_time, tvb, *offset, 4, &confirm_time);
*offset += 4;
if ( tvb_reported_length_remaining(tvb, *offset) <= 0 ) return;
proto_tree_add_item(tree, hf_zbee_zcl_msg_confirm_ctrl, tvb, *offset, 1, ENC_NA);
*offset += 1;
if ( tvb_reported_length_remaining(tvb, *offset) <= 0 ) return;
msg_len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_msg_confirm_response_length, tvb, *offset, 1, ENC_NA);
*offset += 1;
if (msg_len > 0) {
msg_data = tvb_get_string_enc(wmem_packet_scope(), tvb, *offset, msg_len, ENC_LITTLE_ENDIAN);
proto_tree_add_string(tree, hf_zbee_zcl_msg_confirm_response, tvb, *offset, msg_len, msg_data);
*offset += msg_len;
}
}
static void
decode_zcl_msg_duration(gchar *s, guint16 value)
{
if (value == 0xffff)
g_snprintf(s, ITEM_LABEL_LENGTH, "Until changed");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes", value);
return;
}
static void
decode_zcl_msg_start_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_MSG_START_TIME_NOW)
g_snprintf(s, ITEM_LABEL_LENGTH, "Now");
else {
gchar *start_time;
value += ZBEE_ZCL_NSTIME_UTC_OFFSET;
start_time = abs_time_secs_to_str (NULL, value, ABSOLUTE_TIME_LOCAL, TRUE);
g_snprintf(s, ITEM_LABEL_LENGTH, "%s", start_time);
wmem_free(NULL, start_time);
}
}
void
proto_register_zbee_zcl_msg(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_msg_attr_id,
{ "Attribute", "zbee_zcl_se.msg.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_msg_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_msg_attr_reporting_status,
{ "Attribute Reporting Status", "zbee_zcl_se.msg.attr.attr_reporting_status",
FT_UINT8, BASE_HEX, VALS(zbee_zcl_se_reporting_status_names), 0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.msg.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.msg.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message_id,
{ "Message ID", "zbee_zcl_se.msg.message.id", FT_UINT32, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl,
{ "Message Control", "zbee_zcl_se.msg.message.ctrl", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_tx,
{ "Transmission", "zbee_zcl_se.msg.message.ctrl.tx", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_ctrl_tx_names),
ZBEE_ZCL_MSG_CTRL_TX_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_importance,
{ "Importance", "zbee_zcl_se.msg.message.ctrl.importance", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_ctrl_importance_names),
ZBEE_ZCL_MSG_CTRL_IMPORTANCE_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_enh_confirm,
{ "Confirmation", "zbee_zcl_se.msg.message.ctrl.enhconfirm", FT_BOOLEAN, 8, TFS(&tfs_required_not_required),
ZBEE_ZCL_MSG_CTRL_ENHANCED_CONFIRM_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_reserved,
{ "Reserved", "zbee_zcl_se.msg.message.ctrl.reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_MSG_CTRL_RESERVED_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_confirm,
{ "Confirmation", "zbee_zcl_se.msg.message.ctrl.confirm", FT_BOOLEAN, 8, TFS(&tfs_required_not_required),
ZBEE_ZCL_MSG_CTRL_CONFIRM_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ext_ctrl,
{ "Extended Message Control", "zbee_zcl_se.msg.message.ext.ctrl", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ext_ctrl_status,
{ "Message Confirmation Status", "zbee_zcl_se.msg.message.ext.ctrl.status", FT_BOOLEAN, 8, TFS(&tfs_confirmed_unconfirmed),
ZBEE_ZCL_MSG_EXT_CTRL_STATUS_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_start_time,
{ "Start Time", "zbee_zcl_se.msg.message.start_time", FT_UINT32, BASE_CUSTOM, CF_FUNC(decode_zcl_msg_start_time),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_duration,
{ "Duration", "zbee_zcl_se.msg.message.duration", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_zcl_msg_duration),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message_length,
{ "Message Length", "zbee_zcl_se.msg.message.length", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message,
{ "Message", "zbee_zcl_se.msg.message", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_confirm_time,
{ "Confirmation Time", "zbee_zcl_se.msg.message.confirm_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_msg_confirm_ctrl,
{ "Confirmation Control", "zbee_zcl_se.msg.message.confirm.ctrl", FT_BOOLEAN, 8, TFS(&tfs_no_yes),
ZBEE_ZCL_MSG_CONFIRM_CTRL_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_confirm_response_length,
{ "Response Length", "zbee_zcl_se.msg.message.length", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_confirm_response,
{ "Response", "zbee_zcl_se.msg.message", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_implementation_time,
{ "Implementation Time", "zbee_zcl_se.msg.impl_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_msg_earliest_time,
{ "Earliest Implementation Time", "zbee_zcl_se.msg.earliest_impl_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL,
0, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_msg,
&ett_zbee_zcl_msg_message_control,
&ett_zbee_zcl_msg_ext_message_control,
};
expert_module_t* expert_zbee_zcl_msg;
static ei_register_info ei[] = {
{ &ei_zbee_zcl_msg_msg_ctrl_depreciated, { "zbee_zcl_se.msg.msg_ctrl.depreciated", PI_PROTOCOL, PI_WARN, "Message Control depreciated in this message, should be 0x00", EXPFILL }},
};
proto_zbee_zcl_msg = proto_register_protocol("ZigBee ZCL Messaging", "ZCL Messaging", ZBEE_PROTOABBREV_ZCL_MSG);
proto_register_field_array(proto_zbee_zcl_msg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_zbee_zcl_msg = expert_register_protocol(proto_zbee_zcl_msg);
expert_register_field_array(expert_zbee_zcl_msg, ei, array_length(ei));
msg_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_MSG, dissect_zbee_zcl_msg, proto_zbee_zcl_msg);
}
void
proto_reg_handoff_zbee_zcl_msg(void)
{
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_MESSAGE, msg_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_msg,
ett_zbee_zcl_msg,
ZBEE_ZCL_CID_MESSAGE,
hf_zbee_zcl_msg_attr_id,
hf_zbee_zcl_msg_srv_rx_cmd_id,
hf_zbee_zcl_msg_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_msg_attr_data
);
}
static void
dissect_zcl_tun_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_TUN_CLOSE_TIMEOUT:
proto_tree_add_item(tree, hf_zbee_zcl_tun_attr_close_timeout, tvb, *offset, 2, ENC_NA);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_SE_ATTR_REPORT_STATUS_TUN:
proto_tree_add_item(tree, hf_zbee_zcl_tun_attr_reporting_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
dissect_zcl_tun_request_tunnel(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_protocol_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_tun_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_flow_control_support, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_tun_max_in_size, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_close_tunnel(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_transfer_data(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
gint length;
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
length = tvb_reported_length_remaining(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_tun_transfer_data, tvb, *offset, length, ENC_NA);
*offset += length;
}
static void
dissect_zcl_tun_transfer_data_error(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_transfer_data_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_tun_ack_transfer_data(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_num_octets_left, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_ready_data(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_num_octets_left, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_get_supported(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_protocol_offset, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_request_tunnel_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_transfer_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_tun_max_in_size, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static void
dissect_zcl_tun_get_supported_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint16 mfg_code;
proto_tree_add_item(tree, hf_zbee_zcl_tun_protocol_list_complete, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_tun_protocol_count, tvb, *offset, 1, ENC_NA);
*offset += 1;
while (tvb_reported_length_remaining(tvb, *offset) > 0) {
mfg_code = tvb_get_letohs(tvb, *offset);
if (mfg_code == 0xFFFF) {
proto_tree_add_string(tree, hf_zbee_zcl_tun_manufacturer_code, tvb, *offset, 2, "Standard Protocol (Mfg Code 0xFFFF)");
}
else {
proto_tree_add_item(tree, hf_zbee_zcl_tun_manufacturer_code, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_tun_protocol_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
}
static void
dissect_zcl_tun_closure_notify(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_tun_tunnel_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static int
dissect_zbee_zcl_tun(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *payload_tree;
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_tun_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_tun_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_tun, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_TUN_REQUEST_TUNNEL:
dissect_zcl_tun_request_tunnel(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_CLOSE_TUNNEL:
dissect_zcl_tun_close_tunnel(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_TRANSFER_DATA:
dissect_zcl_tun_transfer_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_TRANSFER_DATA_ERROR:
dissect_zcl_tun_transfer_data_error(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_ACK_TRANSFER_DATA:
dissect_zcl_tun_ack_transfer_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_READY_DATA:
dissect_zcl_tun_ready_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_GET_SUPPORTED_PROTOCOLS:
dissect_zcl_tun_get_supported(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_tun_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_tun_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_tree = proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_tun, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_TUN_REQUEST_TUNNEL_RSP:
dissect_zcl_tun_request_tunnel_rsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_TRANSFER_DATA_TX:
dissect_zcl_tun_transfer_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_TRANSFER_DATA_ERROR_TX:
dissect_zcl_tun_transfer_data_error(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_ACK_TRANSFER_DATA_TX:
dissect_zcl_tun_ack_transfer_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_READY_DATA_TX:
dissect_zcl_tun_ready_data(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_GET_SUPPORTED_PROTOCOLS_RSP:
dissect_zcl_tun_get_supported_rsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_TUN_CLOSURE_NOTIFY:
dissect_zcl_tun_closure_notify(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_tun(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_tun_attr_id,
{ "Attribute", "zbee_zcl_se.tun.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_tun_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_tun_attr_reporting_status,
{ "Attribute Reporting Status", "zbee_zcl_se.tun.attr.attr_reporting_status",
FT_UINT8, BASE_HEX, VALS(zbee_zcl_se_reporting_status_names), 0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_attr_close_timeout,
{ "Close Tunnel Timeout", "zbee_zcl_se.tun.attr.close_tunnel", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_tun_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.tun.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_tun_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.tun.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_tun_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_protocol_id,
{ "Protocol ID", "zbee_zcl_se.tun.protocol_id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_tun_protocol_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_manufacturer_code,
{ "Manufacturer Code", "zbee_zcl_se.tun.manufacturer_code", FT_UINT16, BASE_HEX, VALS(zbee_mfr_code_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_flow_control_support,
{ "Flow Control Supported", "zbee_zcl_se.tun.flow_control_supported", FT_BOOLEAN, 8, TFS(&tfs_true_false),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_max_in_size,
{ "Max Incoming Transfer Size", "zbee_zcl_se.tun.max_in_transfer_size", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_tunnel_id,
{ "Tunnel Id", "zbee_zcl_se.tun.tunnel_id", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_num_octets_left,
{ "Num Octets Left", "zbee_zcl_se.tun.octets_left", FT_UINT16, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_protocol_offset,
{ "Protocol Offset", "zbee_zcl_se.tun.protocol_offset", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_transfer_status,
{ "Transfer Status", "zbee_zcl_se.tun.transfer_status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_tun_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_transfer_data,
{ "Transfer Data", "zbee_zcl_se.tun.transfer_data", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_tun_transfer_data_status,
{ "Transfer Data Status", "zbee_zcl_se.tun.transfer_data_status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_tun_trans_data_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_protocol_count,
{ "Protocol Count", "zbee_zcl_se.tun.protocol_count", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_tun_protocol_list_complete,
{ "List Complete", "zbee_zcl_se.tun.protocol_list_complete", FT_BOOLEAN, 8, TFS(&tfs_true_false),
0x00, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_tun,
};
proto_zbee_zcl_tun = proto_register_protocol("ZigBee ZCL Tunneling", "ZCL Tunneling", ZBEE_PROTOABBREV_ZCL_TUN);
proto_register_field_array(proto_zbee_zcl_tun, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tun_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_TUN, dissect_zbee_zcl_tun, proto_zbee_zcl_tun);
}
void
proto_reg_handoff_zbee_zcl_tun(void)
{
ipv4_handle = find_dissector("ipv4");
ipv6_handle = find_dissector("ipv6");
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_TUNNELING, tun_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_tun,
ett_zbee_zcl_tun,
ZBEE_ZCL_CID_TUNNELING,
hf_zbee_zcl_tun_attr_id,
hf_zbee_zcl_tun_srv_rx_cmd_id,
hf_zbee_zcl_tun_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_tun_attr_data
);
}
static void
dissect_zcl_pp_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_SE_ATTR_REPORT_STATUS_PP:
proto_tree_add_item(tree, hf_zbee_zcl_pp_attr_reporting_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_pp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_pp_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_pp_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_pp, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PP_SELECT_AVAILABLE_EMERGENCY_CREDIT:
break;
case ZBEE_ZCL_CMD_ID_PP_CONSUMER_TOP_UP:
break;
case ZBEE_ZCL_CMD_ID_PP_GET_PREPAY_SNAPTSHOT:
break;
case ZBEE_ZCL_CMD_ID_PP_GET_TOP_UP_LOG:
break;
case ZBEE_ZCL_CMD_ID_PP_GET_DEBT_REPAYMENT_LOG:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_pp_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_pp_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_pp, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_PP_PUBLISH_PREPAY_SNAPSHOT:
break;
case ZBEE_ZCL_CMD_ID_PP_CONSUMER_TOP_UP_RESPONSE:
break;
case ZBEE_ZCL_CMD_ID_PP_PUBLISH_TOP_UP_LOG:
break;
case ZBEE_ZCL_CMD_ID_PP_PUBLISH_DEBT_LOG:
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_pp(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_pp_attr_id,
{ "Attribute", "zbee_zcl_se.pp.attr_id", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &zbee_zcl_pp_attr_names_ext,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_pp_attr_reporting_status,
{ "Attribute Reporting Status", "zbee_zcl_se.pp.attr.attr_reporting_status",
FT_UINT8, BASE_HEX, VALS(zbee_zcl_se_reporting_status_names), 0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pp_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.pp.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_pp_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_pp_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.pp.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_pp_srv_rx_cmd_names),
0x00, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_pp,
};
proto_zbee_zcl_pp = proto_register_protocol("ZigBee ZCL Prepayment", "ZCL Prepayment", ZBEE_PROTOABBREV_ZCL_PRE_PAYMENT);
proto_register_field_array(proto_zbee_zcl_pp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pp_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_PRE_PAYMENT, dissect_zbee_zcl_pp, proto_zbee_zcl_pp);
}
void
proto_reg_handoff_zbee_zcl_pp(void)
{
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_PRE_PAYMENT, pp_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_pp,
ett_zbee_zcl_pp,
ZBEE_ZCL_CID_PRE_PAYMENT,
hf_zbee_zcl_pp_attr_id,
hf_zbee_zcl_pp_srv_rx_cmd_id,
hf_zbee_zcl_pp_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_pp_attr_data
);
}
static void
dissect_zcl_events_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch (attr_id) {
case ZBEE_ZCL_ATTR_ID_SE_ATTR_REPORT_STATUS_EVENTS:
proto_tree_add_item(tree, hf_zbee_zcl_events_attr_reporting_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static int
dissect_zbee_zcl_events(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_events_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_events_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_events, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_EVENTS_GET_EVENT_LOG:
break;
case ZBEE_ZCL_CMD_ID_EVENTS_CLEAR_EVENT_LOG_REQUEST:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_events_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_events_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_subtree(tree, tvb, offset, rem_len, ett_zbee_zcl_events, NULL, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_EVENTS_PUBLISH_EVENT:
break;
case ZBEE_ZCL_CMD_ID_EVENTS_PUBLISH_EVENT_LOG:
break;
case ZBEE_ZCL_CMD_ID_EVENTS_CLEAR_EVENT_LOG_RESPONSE:
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_events(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_events_attr_id,
{ "Attribute", "zbee_zcl_se.events.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_events_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_events_attr_reporting_status,
{ "Attribute Reporting Status", "zbee_zcl_se.events.attr.attr_reporting_status",
FT_UINT8, BASE_HEX, VALS(zbee_zcl_se_reporting_status_names), 0x00, NULL, HFILL } },
{ &hf_zbee_zcl_events_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.events.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_events_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_events_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.events.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_events_srv_rx_cmd_names),
0x00, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_events,
};
proto_zbee_zcl_events = proto_register_protocol("ZigBee ZCL Events", "ZCL Events", ZBEE_PROTOABBREV_ZCL_EVENTS);
proto_register_field_array(proto_zbee_zcl_events, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
events_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_EVENTS, dissect_zbee_zcl_events, proto_zbee_zcl_events);
}
void
proto_reg_handoff_zbee_zcl_events(void)
{
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_EVENTS, events_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_events,
ett_zbee_zcl_events,
ZBEE_ZCL_CID_EVENTS,
hf_zbee_zcl_events_attr_id,
hf_zbee_zcl_events_srv_rx_cmd_id,
hf_zbee_zcl_events_srv_tx_cmd_id,
(zbee_zcl_fn_attr_data)dissect_zcl_events_attr_data
);
}
static void
dissect_zcl_ke_suite1_certificate(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_reconstr, tvb, *offset, 22, ENC_NA);
*offset += 22;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_subject, tvb, *offset, 8, ENC_NA);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_issuer, tvb, *offset, 8, ENC_NA);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_profile_attr, tvb, *offset, 10, ENC_NA);
*offset += 10;
}
static void
dissect_zcl_ke_suite2_certificate(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
nstime_t valid_from_time;
nstime_t valid_to_time;
guint32 valid_to;
guint8 key_usage;
proto_tree *usage_tree;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_type, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_serialno, tvb, *offset, 8, ENC_NA);
*offset += 8;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_curve, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_hash, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_issuer, tvb, *offset, 8, ENC_NA);
*offset += 8;
valid_from_time.secs = (time_t)tvb_get_ntoh40(tvb, *offset);
valid_from_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_ke_cert_valid_from, tvb, *offset, 5, &valid_from_time);
*offset += 5;
valid_to = tvb_get_ntohl(tvb, *offset);
if (valid_to == 0xFFFFFFFF) {
proto_tree_add_time_format(tree, hf_zbee_zcl_ke_cert_valid_to, tvb, *offset, 4, &valid_to_time, "Valid To: does not expire (0xFFFFFFFF)");
}
else {
valid_to_time.secs = valid_from_time.secs + valid_to;
valid_to_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_ke_cert_valid_to, tvb, *offset, 4, &valid_to_time);
}
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_subject, tvb, *offset, 8, ENC_NA);
*offset += 8;
key_usage = tvb_get_guint8(tvb, *offset);
usage_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 1, ett_zbee_zcl_ke_key_usage, NULL, "Key Usage (0x%02x)", key_usage);
proto_tree_add_item(usage_tree, hf_zbee_zcl_ke_cert_key_usage_agreement, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(usage_tree, hf_zbee_zcl_ke_cert_key_usage_signature, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_cert_reconstr, tvb, *offset, 37, ENC_NA);
*offset += 37;
}
static void
dissect_zcl_ke_initiate(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
gint rem_len;
proto_tree *subtree;
guint16 suite;
suite = tvb_get_letohs(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ke_suite, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_zbee_zcl_ke_ephemeral_time, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_confirm_time, tvb, *offset, 1, ENC_NA);
*offset += 1;
rem_len = tvb_reported_length_remaining(tvb, *offset);
subtree = proto_tree_add_subtree(tree, tvb, *offset, rem_len, ett_zbee_zcl_ke_cert, NULL, "Implicit Certificate");
switch (suite) {
case ZBEE_ZCL_KE_SUITE_1:
dissect_zcl_ke_suite1_certificate(tvb, subtree, offset);
break;
case ZBEE_ZCL_KE_SUITE_2:
dissect_zcl_ke_suite2_certificate(tvb, subtree, offset);
break;
default:
break;
}
}
static int
dissect_zcl_ke_ephemeral_qeu(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
gint length;
length = tvb_reported_length_remaining(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ke_ephemeral_qeu, tvb, *offset, length, ENC_NA);
*offset += length;
return tvb_captured_length(tvb);
}
static int
dissect_zcl_ke_ephemeral_qev(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
gint length;
length = tvb_reported_length_remaining(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_ke_ephemeral_qev, tvb, *offset, length, ENC_NA);
*offset += length;
return tvb_captured_length(tvb);
}
static int
dissect_zcl_ke_confirm_macu(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ke_macu, tvb, *offset, ZBEE_SEC_CONST_BLOCKSIZE, ENC_NA);
*offset += ZBEE_SEC_CONST_BLOCKSIZE;
return tvb_captured_length(tvb);
}
static int
dissect_zcl_ke_confirm_macv(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ke_macv, tvb, *offset, ZBEE_SEC_CONST_BLOCKSIZE, ENC_NA);
*offset += ZBEE_SEC_CONST_BLOCKSIZE;
return tvb_captured_length(tvb);
}
static void
dissect_zcl_ke_terminate(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_ke_status, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_wait_time, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_ke_suite, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static int
dissect_zbee_zcl_ke(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
zbee_zcl_packet *zcl;
guint offset = 0;
guint8 cmd_id;
gint rem_len;
if (data == NULL)
return 0;
zcl = (zbee_zcl_packet *)data;
cmd_id = zcl->cmd_id;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ke_srv_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_ke_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, offset);
offset += 1;
if (rem_len > 0) {
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_KE_INITIATE:
dissect_zcl_ke_initiate(tvb, tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_KE_EPHEMERAL:
return dissect_zcl_ke_ephemeral_qeu(tvb, tree, &offset);
case ZBEE_ZCL_CMD_ID_KE_CONFIRM:
return dissect_zcl_ke_confirm_macu(tvb, tree, &offset);
case ZBEE_ZCL_CMD_ID_KE_TERMINATE:
dissect_zcl_ke_terminate(tvb, tree, &offset);
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_ke_srv_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_uint(tree, hf_zbee_zcl_ke_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_KE_INITIATE:
dissect_zcl_ke_initiate(tvb, tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_KE_EPHEMERAL:
return dissect_zcl_ke_ephemeral_qev(tvb, tree, &offset);
case ZBEE_ZCL_CMD_ID_KE_CONFIRM:
return dissect_zcl_ke_confirm_macv(tvb, tree, &offset);
case ZBEE_ZCL_CMD_ID_KE_TERMINATE:
dissect_zcl_ke_terminate(tvb, tree, &offset);
break;
default:
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_zbee_zcl_ke(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_ke_attr_id,
{ "Attribute", "zbee_zcl_se.ke.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ke_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ke_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.ke.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_srv_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ke_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.ke.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_srv_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ke_suite,
{ "Key Establishment Suite", "zbee_zcl_se.ke.attr.suite", FT_UINT16, BASE_HEX, VALS(zbee_zcl_ke_suite_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ke_ephemeral_time,
{ "Ephemeral Data Generate Time", "zbee_zcl_se.ke.init.ephemeral.time", FT_UINT8, BASE_DEC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_confirm_time,
{ "Confirm Key Generate Time", "zbee_zcl_se.ke.init.confirm.time", FT_UINT8, BASE_DEC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_status,
{ "Status", "zbee_zcl_se.ke.terminate.status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_ke_wait_time,
{ "Wait Time", "zbee_zcl_se.ke.terminate.wait.time", FT_UINT8, BASE_DEC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_reconstr,
{ "Public Key", "zbee_zcl_se.ke.cert.reconst", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_subject,
{ "Subject", "zbee_zcl_se.ke.cert.subject", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_issuer,
{ "Issuer", "zbee_zcl_se.ke.cert.issuer", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_profile_attr,
{ "Profile Attribute Data", "zbee_zcl_se.ke.cert.profile", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_type,
{ "Type", "zbee_zcl_se.ke.cert.type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_type_names),
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_serialno,
{ "Serial No", "zbee_zcl_se.ke.cert.serialno", FT_UINT64, BASE_HEX, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_curve,
{ "Curve", "zbee_zcl_se.ke.cert.curve", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_curve_names),
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_hash,
{ "Hash", "zbee_zcl_se.ke.cert.hash", FT_UINT8, BASE_HEX, VALS(zbee_zcl_ke_hash_names),
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_valid_from,
{ "Valid From", "zbee_zcl_se.ke.cert.valid.from", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_valid_to,
{ "Valid To", "zbee_zcl_se.ke.cert.valid.to", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_cert_key_usage_agreement,
{ "Key Agreement", "zbee_zcl_se.ke.cert.key.usage.agreement", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled),
ZBEE_ZCL_KE_USAGE_KEY_AGREEMENT, NULL, HFILL }},
{ &hf_zbee_zcl_ke_cert_key_usage_signature,
{ "Digital Signature", "zbee_zcl_se.ke.cert.key.usage.signature", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled),
ZBEE_ZCL_KE_USAGE_DIGITAL_SIGNATURE, NULL, HFILL }},
{ &hf_zbee_zcl_ke_ephemeral_qeu,
{ "Ephemeral Data (QEU)", "zbee_zcl_se.ke.qeu", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_ephemeral_qev,
{ "Ephemeral Data (QEV)", "zbee_zcl_se.ke.qev", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_macu,
{ "Message Authentication Code (MACU)", "zbee_zcl_se.ke.macu", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
{ &hf_zbee_zcl_ke_macv,
{ "Message Authentication Code (MACV)", "zbee_zcl_se.ke.macv", FT_BYTES, BASE_NONE, NULL,
0, NULL, HFILL } },
};
gint *ett[] = {
&ett_zbee_zcl_ke,
&ett_zbee_zcl_ke_cert,
&ett_zbee_zcl_ke_key_usage,
};
proto_zbee_zcl_ke = proto_register_protocol("ZigBee ZCL Key Establishment", "ZCL Key Establishment", ZBEE_PROTOABBREV_ZCL_KE);
proto_register_field_array(proto_zbee_zcl_ke, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ke_handle = register_dissector(ZBEE_PROTOABBREV_ZCL_KE, dissect_zbee_zcl_ke, proto_zbee_zcl_ke);
}
void
proto_reg_handoff_zbee_zcl_ke(void)
{
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_KE, ke_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_ke,
ett_zbee_zcl_ke,
ZBEE_ZCL_CID_KE,
hf_zbee_zcl_ke_attr_id,
hf_zbee_zcl_ke_srv_rx_cmd_id,
hf_zbee_zcl_ke_srv_tx_cmd_id,
NULL
);
}
