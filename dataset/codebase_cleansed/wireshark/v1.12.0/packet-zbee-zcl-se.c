static int
dissect_zbee_zcl_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *payload_root;
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
proto_tree_add_item(tree, hf_zbee_zcl_msg_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_root = proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
payload_tree = proto_item_add_subtree(payload_root, ett_zbee_zcl_msg);
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MSG_GET_LAST_MSG:
break;
case ZBEE_ZCL_CMD_ID_MSG_MSG_CONFIRM:
dissect_zcl_msg_confirm(tvb, payload_tree, &offset);
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
proto_tree_add_item(tree, hf_zbee_zcl_msg_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_root = proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
payload_tree = proto_item_add_subtree(payload_root, ett_zbee_zcl_msg);
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_MSG_DISPLAY_MSG:
dissect_zcl_msg_display(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_MSG_CANCEL_MSG:
dissect_zcl_msg_cancel(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
return tvb_length(tvb);
}
static void
dissect_zcl_msg_display(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
proto_item *ti;
guint8 control;
guint msg_len;
guint8 *msg_data;
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
control = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Message Control: 0x%02x", control);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_msg_message_control);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_tx, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_importance, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_reserved, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_confirm, tvb, *offset, 1, ENC_NA);
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
}
static void
dissect_zcl_msg_cancel(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree *sub_tree = NULL;
proto_item *ti;
guint8 control;
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
control = tvb_get_guint8(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Message Control: 0x%02x", control);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_msg_message_control);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_tx, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_importance, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_reserved, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(sub_tree, hf_zbee_zcl_msg_ctrl_confirm, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
static void
dissect_zcl_msg_confirm(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
nstime_t confirm_time;
proto_tree_add_item(tree, hf_zbee_zcl_msg_message_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
confirm_time.secs = tvb_get_letohl(tvb, *offset) + ZBEE_ZCL_NSTIME_UTC_OFFSET;
confirm_time.nsecs = 0;
proto_tree_add_time(tree, hf_zbee_zcl_msg_confirm_time, tvb, *offset, 4, &confirm_time);
*offset += 4;
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
value += ZBEE_ZCL_NSTIME_UTC_OFFSET;
g_snprintf(s, ITEM_LABEL_LENGTH, "%s", abs_time_secs_to_ep_str (value, ABSOLUTE_TIME_LOCAL, TRUE));
}
}
static void
dissect_zcl_msg_cmd_id(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint8 cmd_dir)
{
if (cmd_dir == ZBEE_ZCL_FCF_TO_CLIENT)
proto_tree_add_item(tree, hf_zbee_zcl_msg_srv_rx_cmd_id, tvb, *offset, 1, ENC_NA);
else
proto_tree_add_item(tree, hf_zbee_zcl_msg_srv_tx_cmd_id, tvb, *offset, 1, ENC_NA);
}
void
proto_register_zbee_zcl_msg(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_msg_srv_tx_cmd_id,
{ "Command", "zbee_zcl_se.msg.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_srv_tx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_srv_rx_cmd_id,
{ "Command", "zbee_zcl_se.msg.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_srv_rx_cmd_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message_id,
{ "Message ID", "zbee_zcl_se.msg.message.id", FT_UINT32, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_tx,
{ "Transmission", "zbee_zcl_se.msg.message.ctrl.tx", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_ctrl_tx_names),
ZBEE_ZCL_MSG_CTRL_TX_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_importance,
{ "Importance", "zbee_zcl_se.msg.message.ctrl.importance", FT_UINT8, BASE_HEX, VALS(zbee_zcl_msg_ctrl_importance_names),
ZBEE_ZCL_MSG_CTRL_IMPORTANCE_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_reserved,
{ "Reserved", "zbee_zcl_se.msg.message.ctrl.reserved", FT_UINT8, BASE_HEX, NULL,
ZBEE_ZCL_MSG_CTRL_RESERVED_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_ctrl_confirm,
{ "Confirmation", "zbee_zcl_se.msg.message.ctrl.confirm", FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested),
ZBEE_ZCL_MSG_CTRL_CONFIRM_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_msg_start_time,
{ "Start Time", "zbee_zcl_se.msg.message.start_time", FT_UINT32, BASE_CUSTOM, decode_zcl_msg_start_time,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_duration,
{ "Duration", "zbee_zcl_se.msg.message.duration", FT_UINT16, BASE_CUSTOM, decode_zcl_msg_duration,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message_length,
{ "Message Length", "zbee_zcl_se.msg.message.length", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_message,
{ "Message", "zbee_zcl_se.msg.message", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_msg_confirm_time,
{ "Confirmation Time", "zbee_zcl_se.msg.message.confirm_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL,
0x0, NULL, HFILL }}
};
gint *ett[ZBEE_ZCL_MSG_NUM_ETT];
ett[0] = &ett_zbee_zcl_msg;
ett[1] = &ett_zbee_zcl_msg_message_control;
proto_zbee_zcl_msg = proto_register_protocol("ZigBee ZCL Messaging", "ZCL Messaging", ZBEE_PROTOABBREV_ZCL_MSG);
proto_register_field_array(proto_zbee_zcl_msg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(ZBEE_PROTOABBREV_ZCL_MSG, dissect_zbee_zcl_msg, proto_zbee_zcl_msg);
}
void
proto_reg_handoff_zbee_zcl_msg(void)
{
dissector_handle_t msg_handle;
msg_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_MSG);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_MESSAGE, msg_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_msg,
ett_zbee_zcl_msg,
ZBEE_ZCL_CID_MESSAGE,
NULL,
NULL,
(zbee_zcl_fn_cmd_id)dissect_zcl_msg_cmd_id
);
}
