static void
OperationalStatus_funk(tvbuff_t* tvb, packet_info *pinfo, proto_tree* tree, gint* offset)
{
guint32 value;
proto_item* ti;
value = tvb_get_ntohl(tvb, *offset);
ti = proto_tree_add_item(tree, hf_ged125_OperationalStatus, tvb, *offset, 4, ENC_BIG_ENDIAN);
if (value == 0)
expert_add_info(pinfo, ti, &ei_ged125_OperationalStatus_normal);
else if (value <= 31 && value >0)
expert_add_info(pinfo, ti, &ei_ged125_OperationalStatus_loss_redundant_component);
else if (value <= 63 && value >= 32 )
expert_add_info(pinfo, ti, &ei_ged125_OperationalStatus_degraded_call_processing);
else if (value <= 127 && value >= 64 )
expert_add_info(pinfo, ti, &ei_ged125_OperationalStatus_conditions_prevent_call);
else if (value > 127)
expert_add_info(pinfo, ti, &ei_ged125_OperationalStatus_invalid_message);
*offset += 4;
}
static void
StatusVariable_funk(tvbuff_t* tvb, proto_tree* tree, gint* offset, const gint size)
{
while(*offset+4 <= size)
{
proto_tree_add_item(tree, hf_ged125_StatusVariable, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
}
static void
trunk_funk_without_status(tvbuff_t* tvb, proto_tree* z_tree, gint* offset, const gint size)
{
gint count = 0;
while(*offset+2 <= size && count < 1024)
{
proto_tree_add_item(z_tree, hf_ged125_TrunkNumber, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
count++;
}
}
static void
trunk_funk(tvbuff_t* tvb, proto_tree* tree, gint* offset, const gint size)
{
guint16 count = 0;
while(*offset+4 <= size && count < 1024) {
proto_tree_add_item(tree, hf_ged125_TrunkNumber, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(tree, hf_ged125_TrunkStatus, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
count++;
}
}
static void
Media_Specifier_dissect(tvbuff_t* tvb, proto_tree* tree, gint* offset, guint32 length)
{
guint8 media_protocol;
media_protocol = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_ged125_floating_media_protocol, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
switch (media_protocol)
{
case 'H':
case 'S':
case 'O':
case 'F':
proto_tree_add_item(tree, hf_ged125_floating_library_designator, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(tree, hf_ged125_floating_payload_strg, tvb, *offset, length - 2, ENC_NA|ENC_ASCII);
break;
case 'T':
proto_tree_add_item(tree, hf_ged125_floating_payload_strg, tvb, *offset, length - 1, ENC_NA|ENC_ASCII);
break;
case 'D':
proto_tree_add_item(tree, hf_ged125_Data_Playback_Type, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_ged125_Data_Playback_Formats, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_ged125_floating_payload_strg, tvb, *offset, length - 9, ENC_NA|ENC_ASCII);
break;
}
*offset += length;
}
static void
floating_fields(tvbuff_t* tvb, packet_info *pinfo, proto_tree* tree, gint offset, const gint size)
{
gint32 length = 4;
guint32 floating_type;
proto_tree *ged125_tree, *float_tree;
proto_item *ti;
if (size - offset > 0)
length = size - offset;
ged125_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_ged125_floating, NULL, "Float Message");
while (offset < size-2)
{
floating_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint_format(ged125_tree, hf_ged125_floating, tvb, offset, 1,
floating_type, "%s", val_to_str(floating_type,
vals_floating_point_types, "Unknown %d"));
float_tree = proto_item_add_subtree(ti, ett_ged125_float_field);
offset += 1;
length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(float_tree, hf_ged125_length, tvb, offset, 1, length);
offset += 1;
if ((offset + length > size) && (length > 0))
{
expert_add_info(pinfo, ti, &ei_ged125_length_bad);
break;
}
switch (floating_type)
{
case 42:
case 43:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_ECC_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (length-4 > 0)
{
proto_tree_add_item(float_tree, hf_ged125_floating_payload_strg, tvb, offset, length-4, ENC_NA|ENC_ASCII);
offset += (length-4);
}
break;
case 44:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_ECC_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(float_tree, hf_ged125_floating_uchar_array_index, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length-5 > 0)
{
proto_tree_add_item(float_tree, hf_ged125_floating_payload_strg, tvb, offset, length-4, ENC_NA|ENC_ASCII);
offset += (length-5);
}
break;
case 47:
case 48:
case 49:
case 50:
Media_Specifier_dissect(tvb, float_tree, &offset, length);
break;
case 19:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_unspec, tvb, offset, length, ENC_NA);
offset += length;
break;
case 1:
case 18:
case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
case 28: case 29: case 30: case 31: case 32: case 33: case 34:
case 37: case 38: case 39: case 40:
case 51: case 52: case 53: case 54: case 55: case 56: case 57: case 58:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_strg, tvb, offset, length, ENC_NA|ENC_ASCII);
offset += length;
break;
case 35:
case 36:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_uint, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += length;
break;
case 41:
proto_tree_add_item(float_tree, hf_ged125_floating_cause_code, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += length;
break;
case 45:
case 46:
proto_tree_add_item(float_tree, hf_ged125_floating_payload_bool, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += length;
break;
}
}
}
static void
service_control_dissect(tvbuff_t* tvb,proto_tree* msg_tree, proto_tree* ged125_tree, packet_info* pinfo,
gint* offset, const gint size)
{
proto_item *ti;
proto_tree *service_tree, *data_tree;
guint32 mess_type, DialogueID, SendSeqNo;
service_tree = proto_tree_add_subtree(msg_tree, tvb, *offset, 12,
ett_ged125_service_control_header, NULL, "Service-Control Header");
mess_type = tvb_get_ntohl(tvb, *offset);
*offset += 4;
DialogueID = tvb_get_ntohl(tvb, *offset);
proto_tree_add_item(service_tree, hf_ged125_DialogueID_num, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
col_add_fstr(pinfo->cinfo, COL_INFO, "Service_Control->%s DIALOGUE_ID=%u LEN=%u",
val_to_str(mess_type, vals_service_control_message_subvalues, "Unknown %d"), DialogueID, size);
SendSeqNo = tvb_get_ntohl(tvb, *offset);
ti = proto_tree_add_item(service_tree, hf_ged125_SendSeqNo_num, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
if ((DialogueID != SendSeqNo) &&
((DialogueID == 0xFFFFFFFF) || (SendSeqNo == 0xFFFFFFFF)))
expert_add_info(pinfo, ti, &ei_ged125_sendseqno_and_dialogueid);
ti = proto_tree_add_uint(service_tree, hf_ged125_service_control_value,
tvb, *offset-12, 4, mess_type);
data_tree = proto_item_add_subtree(ti, ett_ged125_service_control_data);
switch (mess_type)
{
case GED125_INIT_SERVICE_CTRL_REQ_VALUE:
case GED125_INIT_SERVICE_CTRL_CONF_VALUE:
case GED125_INIT_SERVICE_CTRL_END_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_INIT_SERVICE_CTRL_DATA_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ServiceFeatures, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_NEW_CALL_VALUE:
case GED125_REQUEST_INSTRUCTION_VALUE:
proto_tree_add_item(data_tree, hf_ged125_TrunkGroupID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TrunkNumber, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ServiceID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_RUN_SCRIPT_REQ_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_RUN_SCRIPT_RESULT_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ResultCode, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_CONNECT_VALUE:
proto_tree_add_item(data_tree, hf_ged125_LabelType, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_EVENT_REPORT_VALUE:
proto_tree_add_item(data_tree, hf_ged125_EventID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_DIALOGUE_FAILURE_CONF_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ErrorCode, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_DIALOGUE_FAILURE_EVENT_VALUE:
proto_tree_add_item(data_tree, hf_ged125_ErrorCode, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_INIT_SERVICE_CTRL_TRKGRP_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TrunkGroupID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TrunkCount, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
trunk_funk(tvb, data_tree, offset, size);
break;
case GED125_INIT_SERVICE_CTRL_SERVICE_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ServiceID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_AvailableNow, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_CallsInNow, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_CallsOutNow, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_INIT_SERVICE_CTRL_VRU_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_CurrentTime_num, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TimeZoneDelta, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
OperationalStatus_funk(tvb, pinfo, data_tree, offset);
StatusVariable_funk(tvb, data_tree, offset, size);
break;
case GED125_TRKGRP_STATUS_VALUE:
proto_tree_add_item(data_tree, hf_ged125_TrunkGroupID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TrunkCount, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
trunk_funk(tvb, data_tree, offset, size);
break;
case GED125_SERVICE_STATUS_VALUE:
proto_tree_add_item(data_tree, hf_ged125_ServiceID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ServiceAvailable, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_VRU_STATUS_VALUE:
proto_tree_add_item(data_tree, hf_ged125_CurrentTime_num, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_TimeZoneDelta, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
OperationalStatus_funk(tvb, pinfo, data_tree, offset);
StatusVariable_funk(tvb, data_tree, offset, size);
break;
case GED125_CANCEL_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_RequestID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_RELEASE_VALUE:
proto_tree_add_item(data_tree, hf_ged125_Cause_just_for_release_message, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case GED125_NEW_DIALOGUE_VALUE:
proto_tree_add_item(data_tree, hf_ged125_CallID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ServiceID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_CONNECT_TO_RESOURCE_VALUE:
case GED125_MICROAPP_CONTEXT_VALUE:
case GED125_TEMPORARY_CONNECT_VALUE:
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_RESOURCE_CONNECTED_VALUE:
break;
case GED125_MICROAPP_PLAY_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ToBeContinued, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Barge_In_Allowed, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_MICROAPP_PLAY_CONTINUE_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ToBeContinued, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_MICROAPP_COLLECT_DATA_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_DTMF_Termination_Key, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_No_Entry_Timeout, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Interdigit_Timeout, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Number_of_No_Entry_Tries, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Number_of_Invalid_Entry_Tries, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Min_Length, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Max_Length, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Barge_In_Allowed, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ASR_Allowed, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_MICROAPP_MENU_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_No_Entry_Timeout, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Number_of_No_Entry_Tries, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Number_of_Invalid_Entry_Tries, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_DTMF_Menu_Keys, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Barge_In_Allowed, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_ASR_Allowed, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
case GED125_MICROAPP_RESULT_VALUE:
proto_tree_add_item(data_tree, hf_ged125_InvokeID, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(data_tree, hf_ged125_Microapp_Error_Code, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
floating_fields(tvb, pinfo, ged125_tree, *offset, size);
break;
default:
expert_add_info(pinfo, ti, &ei_ged125_service_control_value_unknown);
}
}
static guint
get_ged125_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset _U_, void *data _U_)
{
return tvb_get_ntohl(tvb, 0) + 8;
}
static int
dissect_ged125_base_messages(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_)
{
gint size = tvb_reported_length(tvb);
proto_item *ti, *message_item;
proto_tree *ged125_tree, *ged125_header_tree, *ged125_message_tree;
gint offset = 8;
guint32 value,
message_type = tvb_get_ntohl(tvb, 4);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GED125");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %u bytes",
val_to_str(message_type, base_message_values, "Unknown %d"), size);
ti = proto_tree_add_item(tree, proto_ged125, tvb, 0, -1, ENC_NA);
ged125_tree = proto_item_add_subtree( ti, ett_ged125);
ged125_header_tree = proto_tree_add_subtree(ged125_tree, tvb, 0, 8, ett_ged125_header, NULL, "GED125 Header");
proto_tree_add_item(ged125_header_tree, hf_ged125_length, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ged125_header_tree, hf_ged125_value, tvb, 4, 4, ENC_BIG_ENDIAN);
ged125_message_tree = proto_tree_add_subtree(ged125_tree, tvb, offset, -1, ett_ged125_message, &message_item, "GED125 Message");
switch (message_type)
{
case GED125_FAILURE_CONF_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_Status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_FAILURE_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_Status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_OPEN_REQ_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_VersionNumber, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_IdleTimeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_OPEN_CONF_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_UseEventFeed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_UsePolledFeed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_UseCallRouting, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_UseTimeSynch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_UseServiceControl, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_HEARTBEAT_REQ_VALUE:
case GED125_HEARTBEAT_CONF_VALUE:
case GED125_CLOSE_CONF_VALUE:
case GED125_INIT_DATA_REQ_VALUE:
case GED125_INIT_DATA_CONF_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_CLOSE_REQ_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_Status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
case GED125_INIT_TRKGRP_DATA_EVENT_VALUE:
value = tvb_get_ntohl(tvb, offset);
ti = proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (value > 65535)
expert_add_info(pinfo, ti, &ei_ged125_trunk_group_id);
value = tvb_get_ntohl(tvb, offset);
ti = proto_tree_add_item(ged125_message_tree, hf_ged125_TrunkCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (value > 1023)
expert_add_info(pinfo, ti, &ei_ged125_TrunkCount_invalid);
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsInToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsOutToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_InServiceTimeToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_InUseInboundTimeToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_InUseOutboundTimeToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_AllTrunksInUseTimeToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
trunk_funk(tvb, ged125_message_tree, &offset, size);
break;
case GED125_INIT_SERVICE_DATA_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_AvailableNow, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsInNow, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsOutNow, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsInToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsOutToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallsHandledToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_HandleTimeToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_DivertedInToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_DivertedOutToday, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_INIT_VRU_DATA_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_TimeZoneDelta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
OperationalStatus_funk(tvb, pinfo, ged125_message_tree, &offset);
StatusVariable_funk(tvb, ged125_message_tree, &offset, size);
break;
case GED125_INIT_DATA_END_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_InitDataTime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_StartOfDay, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_DELIVERED_EVENT_VALUE:
case GED125_ORIGINATED_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_TrunkGroupID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_TrunkNumber, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
case GED125_CALL_CLEARED_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_floating_CauseCode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
case GED125_CONFERENCED_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_ConferenceCallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_PrimaryCallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_SecondaryCallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_DIVERTED_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_NewServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_NEW_TRANSACTION_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_NewCallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_SET_CALL_VARIABLES_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
case GED125_VRU_STATUS_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CurrentTime_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_TimeZoneDelta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
OperationalStatus_funk(tvb, pinfo, ged125_message_tree, &offset);
StatusVariable_funk(tvb, ged125_message_tree, &offset, size);
break;
case GED125_TRKGRP_STATUS_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_TrunkGroupID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
value = tvb_get_ntohl(tvb, offset);
ti = proto_tree_add_item(ged125_message_tree, hf_ged125_TrunkCount, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (value > 1023)
expert_add_info(pinfo, ti, &ei_ged125_TrunkCount_invalid);
proto_tree_add_item(ged125_message_tree, hf_ged125_InService, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
trunk_funk_without_status(tvb, ged125_message_tree, &offset, size);
break;
case GED125_SERVICE_STATUS_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_ServiceAvailable, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_ROUTE_REQUEST_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CrossRefID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_CallID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
return tvb_captured_length(tvb);
case GED125_ROUTE_SELECT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CrossRefID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_LabelType, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
case GED125_ROUTE_END_EVENT_VALUE:
case GED125_ROUTE_END_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CrossRefID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_Status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_TIME_SYNCH_REQ_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ged125_message_tree, hf_ged125_VRUTimeLag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_TIME_SYNCH_CONF_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_InvokeID, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case GED125_SERVICE_CONTROL_VALUE:
service_control_dissect(tvb, ged125_message_tree, ged125_tree, pinfo, &offset, size);
break;
case GED125_SIMULATOR_RESET_EVENT_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_simulator_reset_event, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GED125_REGISTER_VARIABLES_VALUE:
proto_tree_add_item(ged125_message_tree, hf_ged125_CallVarsMask, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
floating_fields(tvb, pinfo, ged125_tree, offset, size);
break;
}
proto_item_set_len(message_item, offset-8);
return tvb_captured_length(tvb);
}
static int
dissect_ged125(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint size;
guint32 message_type;
size = tvb_captured_length(tvb);
if (size < 12)
return 0;
message_type = tvb_get_ntohl(tvb, 4);
if (try_val_to_str(message_type, base_message_values) == NULL)
return 0;
tcp_dissect_pdus(tvb, pinfo, tree, ged125_desegment_body, 4,
get_ged125_pdu_len, dissect_ged125_base_messages, data);
return size;
}
void
proto_register_ged125 (void)
{
module_t* ged125_module;
static hf_register_info hf[] = {
{ &hf_ged125_length,
{ "Package Length", "ged125.len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_value,
{ "Message value", "ged125.value",
FT_UINT32, BASE_DEC, VALS(base_message_values), 0x0, NULL, HFILL }},
{ &hf_ged125_service_control_value,
{ "Sub-Service Control Message value", "ged125.service_control",
FT_UINT32, BASE_DEC, VALS(vals_service_control_message_subvalues),
0x0, NULL, HFILL }},
{ &hf_ged125_DialogueID_num,
{ "Dialogue Id", "ged125.dialogue_id",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_SendSeqNo_num,
{ "SendSeqNo", "ged125.send_seq_no",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Send sequence for the sent message", HFILL }},
{ &hf_ged125_CurrentTime_num,
{ "Current Time", "ged125.current_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The current UTC time (VRU clock)", HFILL }},
{ &hf_ged125_TimeZoneDelta,
{ "Time Zone Delta", "ged125.time_zone_delta",
FT_INT32, BASE_DEC,NULL, 0x0,
"The current local time zone delta, expressed in seconds."
"This value is added to a UTC time to form a time in the local time zone",
HFILL }},
{ &hf_ged125_OperationalStatus,
{ "Operational Status", "ged125.operational_status",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Operational Status of the VRU", HFILL }},
{ &hf_ged125_StatusVariable,
{ "Status Variable", "ged125.status_variable",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_InvokeID,
{ "Invoke ID", "ged125.invoke_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Same as the corresponding req. mess", HFILL }},
{ &hf_ged125_Status,
{ "Status", "ged125.status",
FT_UINT32, BASE_DEC, VALS(error_codes), 0x0,
"Status: Indicates cause of failure", HFILL }},
{ &hf_ged125_VersionNumber,
{ "Version Number", "ged125.version_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interface number requested by the Peripheral Gateway,"
"defines the version of all messages in the message set", HFILL }},
{ &hf_ged125_IdleTimeout,
{ "Idle Timeout (ms)", "ged125.idle_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_floating_CauseCode,
{ "Cause code", "ged125.cause_code",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_UseEventFeed,
{ "Use Event Feed", "ged125.use_event_feed",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates if the VRU supports the Event Data Feed", HFILL }},
{ &hf_ged125_UsePolledFeed,
{ "Use Polled Feed", "ged125.use_polled_feed",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates if the VRU supports the Polled Data Feed.", HFILL }},
{ &hf_ged125_UseCallRouting,
{ "Use Call Routing", "ged125.use_call_routing",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates if the VRU supports the Call Routing Interface", HFILL }},
{ &hf_ged125_UseTimeSynch,
{ "Use Time Synch", "ged125.use_time_synch",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates if the VRU supports the Time Synchronization Interface", HFILL }},
{ &hf_ged125_UseServiceControl,
{ "Use Service Control", "ged125.use_service_control",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates if the VRU supports the Service Control Interface", HFILL }},
{ &hf_ged125_TrunkGroupID,
{ "Trunk Group ID", "ged125.trunk_group_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"An ID assigned by the VRU to this trunk group, in the range 0 to 65535", HFILL }},
{ &hf_ged125_TrunkCount,
{ "Trunk Count", "ged125.trunk_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of trunks configured in this message. TrunkCount may not exceed 1024", HFILL }},
{ &hf_ged125_CallsInToday,
{ "Calls In Today", "ged125.calls_in_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative number of inbound calls that have arrived on the trunk group this day", HFILL }},
{ &hf_ged125_CallsOutToday,
{ "Calls Out Today", "ged125.call_out_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative number of outbound calls that have been placed on the trunk group this day", HFILL }},
{ &hf_ged125_InServiceTimeToday,
{ "In Service Time Today", "ged125.in_service_time_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative amount of time (sec) that trunks in the trunk group "
"have been in service this day", HFILL }},
{ &hf_ged125_InUseInboundTimeToday,
{ "In Use Inbound Time Today", "ged125.in_use_inbound_time_today",
FT_UINT32, BASE_DEC,NULL, 0x0,
"The cumulative amount of time (sec) that trunks in the trunk group "
"have been in use on incoming calls this day", HFILL }},
{ &hf_ged125_InUseOutboundTimeToday,
{ "In Use Outbound Time Today", "ged125.in_use_outbound_time_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative amount of time (sec) that trunks in the trunk group "
"have been in use on outgoing calls this day", HFILL }},
{ &hf_ged125_AllTrunksInUseTimeToday,
{ "All Trunks In Use Time Today", "ged125.all_trunks_in_use_time_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative amount of time (sec) that all trunks in the trunk group "
"were simultaneously busy this day", HFILL }},
{ &hf_ged125_TrunkNumber,
{ "Trunk Number", "ged125.trunk_number",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_TrunkStatus,
{ "Trunk Status", "ged125.trunk_status",
FT_UINT16, BASE_DEC, VALS(status_code_trunk_status), 0x0, NULL, HFILL }},
{ &hf_ged125_ServiceID,
{ "Service ID", "ged125.service_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"An ID assigned by the VRU to this service", HFILL }},
{ &hf_ged125_AvailableNow,
{ "Available Now", "ged125.available_now",
FT_BOOLEAN, 32, NULL, 0x01,
"Current availability of the service", HFILL }},
{ &hf_ged125_CallsInNow,
{ "Call In Now", "ged125.call_in_now",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of inbound calls currently in progress on the service.", HFILL }},
{ &hf_ged125_CallsOutNow,
{ "Call Out Now", "ged125.call_out_now",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of outbound calls currently in progress on the service", HFILL }},
{ &hf_ged125_CallsHandledToday,
{ "Calls Handled Today", "ged125.call_handled_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative number of calls handled on the service this day", HFILL }},
{ &hf_ged125_HandleTimeToday,
{ "Handle Time Today", "ged125.handle_time_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative amount of time (secs) spent handling calls on the service this day", HFILL }},
{ &hf_ged125_DivertedInToday,
{ "Diverted In Today", "ged125.diverted_in_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative number of calls diverted from another service to this service this day", HFILL }},
{ &hf_ged125_DivertedOutToday,
{ "Diverted Out Today", "ged125.diverted_out_today",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The cumulative number of calls diverted from this service to another service this day", HFILL }},
{ &hf_ged125_InitDataTime,
{ "Init Data Time", "ged125.init_data_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The UTC time at which the initial snapshot was taken", HFILL }},
{ &hf_ged125_StartOfDay,
{ "Start Of Day", "ged125.start_of_day",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Corresponds to midnight local time at the VRU (UTC). However, this may refer "
"to a different time if the VRU has restarted", HFILL }},
{ &hf_ged125_CallID,
{ "Call ID", "ged125.call_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"An ID assigned to the call by the VRU", HFILL }},
{ &hf_ged125_floating,
{ "Field", "ged125.floating_field",
FT_UINT32, BASE_DEC, VALS(vals_floating_point_types), 0x0,
"Shows the type of floating field", HFILL }},
{ &hf_ged125_ServiceFeatures,
{ "Service Features", "ged125.service_features",
FT_UINT32, BASE_HEX, NULL, 0x0,
"A bit mask that is a logical OR of the Service Control features supported by the VRU", HFILL }},
{ &hf_ged125_floating_payload_strg,
{ "Floating Payload", "ged125.floating_payload.strg",
FT_STRING, FT_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_floating_payload_uint,
{ "Floating Payload", "ged125.floating_payload.uint",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_floating_payload_bool,
{ "Floating Payload", "ged125.floating_payload.bool",
FT_BOOLEAN, 32, NULL, 0x01, NULL, HFILL }},
{ &hf_ged125_floating_payload_ECC_tag,
{ "ECC VAR Tag", "ged125.ecc_var_tag",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_ResultCode,
{ "Errors running script", "ged125.result_code",
FT_BOOLEAN, 32, TFS(&tfs_true_false), 0x01, NULL, HFILL }},
{ &hf_ged125_LabelType,
{ "Label Type", "ged125.label_type",
FT_UINT32, BASE_DEC, VALS(status_code_Label_values),0x0,
"The type of the label returned in the following field", HFILL }},
{ &hf_ged125_EventID,
{ "Event ID", "ged125.event_id",
FT_UINT32, BASE_DEC, VALS(status_code_event_reportcodes), 0x0,
"A code that identifies the event detected by the VRU", HFILL }},
{ &hf_ged125_ErrorCode,
{ "Error Code", "ged125.error_code",
FT_UINT32, BASE_DEC, VALS(error_codes), 0x0,
"A status code indicating the cause of the failure", HFILL }},
{ &hf_ged125_Cause_just_for_release_message,
{ "Cause of Release", "ged125.call_release",
FT_UINT32, BASE_DEC, VALS(Cause_just_for_release_message_vals), 0x0,
"The reason the call was released", HFILL }},
{ &hf_ged125_InService,
{ "In Service", "ged125.in_service",
FT_BOOLEAN, 32, NULL, 0x01,
"A flag indicating that the affected trunks have been placed into "
"service (True) or removed from service (False)", HFILL }},
{ &hf_ged125_ServiceAvailable,
{ "Service Available", "ged125.service_available",
FT_BOOLEAN, 32, NULL, 0x01,
NULL, HFILL }},
{ &hf_ged125_RequestID,
{ "Request ID", "ged125.request_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The InvokeID of the previously issued request to be cancelled", HFILL }},
{ &hf_ged125_ToBeContinued,
{ "To Be Continued", "ged125.to_be_continued",
FT_BOOLEAN, 32, NULL, 0x01,
"A flag which indicates whether additional MICROAPP_PLAY_CONTINUE messages will follow", HFILL }},
{ &hf_ged125_Barge_In_Allowed,
{ "Barge In Allowed", "ged125.barge_in_allowed",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates whether caller is allowed to interrupt playing", HFILL }},
{ &hf_ged125_floating_cause_code,
{ "Call Cleared Code", "ged125.call_cleared_code",
FT_UINT32, BASE_DEC,VALS(vals_status_code_call_cleared), 0x0,
"Termination Call Details", HFILL }},
{ &hf_ged125_DTMF_Termination_Key,
{ "DTMF Termination Key", "ged125.dtmf_termination_key",
FT_UINT32,BASE_DEC, NULL,0x0,
"Terminates a variable length string of DTMF digits "
"(typically # key). The value is a bit map", HFILL }},
{ &hf_ged125_No_Entry_Timeout,
{ "No Entry Timeout", "ged125.no_entry_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Determines how many seconds a caller is allowed to start entering data", HFILL }},
{ &hf_ged125_Interdigit_Timeout,
{ "Interdigit Timeout", "ged125.interdigit_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Determines how many seconds the caller is allowed between digits, "
"before the system assumes the caller is finished", HFILL }},
{ &hf_ged125_Number_of_No_Entry_Tries,
{ "Number of No Entry Tries", "ged125.number_of_no_entry_tries",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of times VRU should repeat the 'Get data' cycle when the caller "
"doesn't enter any data", HFILL }},
{ &hf_ged125_Number_of_Invalid_Entry_Tries,
{ "Number of Invalid Entry Tries", "ged125.number_of_invalid_entry_tries",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of times VRU should repeat the 'Get data' cycle when the "
"caller enters invalid data", HFILL }},
{ &hf_ged125_Min_Length,
{ "Min Length of Digits", "ged125.min_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Minimum number of digits expected from the caller", HFILL }},
{ &hf_ged125_Max_Length,
{ "Max Length of Digits", "ged125.max_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Maximum number of digits expected from the caller", HFILL }},
{ &hf_ged125_ASR_Allowed,
{ "ASR Allowed", "ged125.asr_allowed",
FT_BOOLEAN, 32, NULL, 0x01,
"Indicates whether Automatic Speech Recognition should be enabled for this request", HFILL }},
{ &hf_ged125_DTMF_Menu_Keys,
{ "DTMF Menu Keys", "ged125.dtmf_menu_keys",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates which keypad keys represent valid menu choices", HFILL }},
{ &hf_ged125_Microapp_Error_Code,
{ "Microapp Error Code", "ged125.microapp_error_code",
FT_UINT32, BASE_DEC,
VALS(status_code_microcapp_error_codes), 0x0, NULL, HFILL }},
{ &hf_ged125_ConferenceCallID,
{ "Conference Call ID", "ged125.conference_call_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"An ID assigned to the resultant conference call by the VRU", HFILL }},
{ &hf_ged125_PrimaryCallID,
{ "Primary Call ID", "ged125.primary_call_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The ID of the primary (inbound) call being conferenced", HFILL }},
{ &hf_ged125_SecondaryCallID,
{ "Secondary Call ID", "ged125.secondary_call_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The ID of the secondary (outbound) call being conferenced", HFILL }},
{ &hf_ged125_NewServiceID,
{ "New Service ID", "ged125.new_service_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The ID of the new service to which the call was diverted", HFILL }},
{ &hf_ged125_NewCallID,
{ "New Call ID", "ged125.new_call_id",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_simulator_reset_event,
{ "Simulator Reset Event", "ged125.simulator_reset_event",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ged125_CrossRefID,
{ "Cross Reference ID", "ged125.cross_ref_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"A cross-reference identifier assigned by the VRU to this call routing dialogue", HFILL }},
{ &hf_ged125_VRUTimeLag,
{ "VRU Time Lag", "ged125.vru_time_lag",
FT_INT32, BASE_DEC, NULL, 0x0,
"Number of seconds that the VRU clock lags the ICM clock", HFILL }},
{ &hf_ged125_CallVarsMask,
{ "Call Vars Mask", "ged125.call_vars_mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
"A bit map, with the least significant bit referring to Call Variable1", HFILL }},
{ &hf_ged125_floating_payload_unspec,
{ "Unspec floating data-type", "ged125.floating_unspec",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown data type", HFILL }},
{ &hf_ged125_floating_media_protocol,
{ "Media Protocol", "ged125.media_protocol",
FT_UINT8, BASE_DEC, VALS(floating_media_protocol_vals), 0x0,
"Type of media", HFILL }},
{ &hf_ged125_floating_library_designator,
{ "Library Designator", "ged125.library_designator",
FT_UINT8, BASE_DEC, VALS(floating_media_library_designator_vals), 0x0,
"System or Application", HFILL }},
{ &hf_ged125_Data_Playback_Type,
{ "Data Playback Type", "ged125.data_playback_type",
FT_UINT32, BASE_DEC, VALS(Data_Playback_Type), 0x0, NULL, HFILL }},
{ &hf_ged125_Data_Playback_Formats,
{ "Data Playback Format", "ged125.data_playback_format",
FT_UINT32, BASE_DEC, VALS(Data_Playback_Formats),0x0,
"Only relevant if Data Playback Type is one of the time formats. "
"It should contain PLAYBACK_FORMAT_OTHER in all other cases", HFILL }},
{ &hf_ged125_floating_uchar_array_index,
{ "Uchar-Array Index", "ged125.uchar_array_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Array index of an ECC field", HFILL }}
};
static gint *ett[] = {
&ett_ged125,
&ett_ged125_header,
&ett_ged125_message,
&ett_ged125_floating,
&ett_ged125_float_field,
&ett_ged125_service_control_header,
&ett_ged125_service_control_data
};
static ei_register_info ei[] = {
{ &ei_ged125_OperationalStatus_normal, { "ged125.operational_status.normal", PI_PROTOCOL, PI_NOTE, "Normal Operation", EXPFILL }},
{ &ei_ged125_OperationalStatus_loss_redundant_component, { "ged125.operational_status.loss_redundant_component", PI_PROTOCOL, PI_NOTE,
"Loss of redundant component or other transparent failure; still fully functional for call processing", EXPFILL }},
{ &ei_ged125_OperationalStatus_degraded_call_processing, { "ged125.operational_status.degraded_call_processing", PI_PROTOCOL, PI_NOTE, "Degraded call processing", EXPFILL }},
{ &ei_ged125_OperationalStatus_conditions_prevent_call, { "ged125.operational_status.conditions_prevent_call", PI_PROTOCOL, PI_NOTE, "Conditions prevent call processing", EXPFILL }},
{ &ei_ged125_OperationalStatus_invalid_message, { "ged125.operational_status.invalid_message", PI_PROTOCOL, PI_WARN, "Error: Invalid message", EXPFILL }},
{ &ei_ged125_length_bad, { "ged125.length.bad", PI_MALFORMED, PI_ERROR, "Incorrect size given in the packet (corrupted)", EXPFILL }},
{ &ei_ged125_sendseqno_and_dialogueid, { "ged125.sendseqno_and_dialogueid", PI_PROTOCOL, PI_WARN, "Both SendSeqNo & DialogueID must be NULL because at least one is NULL", EXPFILL }},
{ &ei_ged125_service_control_value_unknown, { "ged125.service_control_value.unknown", PI_PROTOCOL, PI_WARN, "Unknown Service-Control Message Sub-type, aborting dissection", EXPFILL }},
{ &ei_ged125_trunk_group_id, { "ged125.trunk_group_id.bad_range", PI_PROTOCOL, PI_WARN, "TrunkGroupID must be between 0-65535", EXPFILL }},
{ &ei_ged125_TrunkCount_invalid, { "ged125.trunk_count.invalid", PI_PROTOCOL, PI_WARN, "Invalid number of trunks (max is 1023)", EXPFILL }},
};
expert_module_t* expert_ged125;
proto_ged125 = proto_register_protocol ("Cisco GED-125 Protocol", "GED125", "ged125");
proto_register_field_array (proto_ged125, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_ged125 = expert_register_protocol(proto_ged125);
expert_register_field_array(expert_ged125, ei, array_length(ei));
ged125_handle = new_register_dissector("ged125", dissect_ged125, proto_ged125);
ged125_module = prefs_register_protocol(proto_ged125, NULL);
prefs_register_uint_preference(ged125_module, "tcp_port","GED125 TCP Port",
"Set up the TCP port for GED125",
10, &global_tcp_port_ged125);
prefs_register_bool_preference(ged125_module, "desegment_body",
"Reassemble GED125 bodies spanning multiple TCP segments",
"Whether the GED125 dissector should desegment all messages spanning multiple TCP segments",
&ged125_desegment_body);
}
void
proto_reg_handoff_ged125(void)
{
static guint old_ged125_tcp_port = 0;
if (old_ged125_tcp_port != 0 && old_ged125_tcp_port != global_tcp_port_ged125)
dissector_delete_uint("tcp.port", old_ged125_tcp_port, ged125_handle);
if (global_tcp_port_ged125 != 0 && old_ged125_tcp_port != global_tcp_port_ged125)
dissector_add_uint("tcp.port", global_tcp_port_ged125, ged125_handle);
old_ged125_tcp_port = global_tcp_port_ged125;
}
