static gboolean uat_devicenet_record_update_cb(void* r, char** err) {
uat_devicenet_record_t* rec = (uat_devicenet_record_t *)r;
if (rec->mac_id > 63) {
*err = g_strdup("MAC ID must be between 0-63");
return FALSE;
}
return TRUE;
}
static gint body_type_8_over_8_dissection(guint8 data_length, proto_tree *devicenet_tree,
tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
guint16 class_id, instance, attribute;
attribute_info_t* att_info;
gint start_offset = offset, length;
proto_item* ti;
devicenet_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, -1, ett_devicenet_8_8, NULL, "DeviceNet 8/8");
proto_tree_add_item(devicenet_tree, hf_devicenet_class8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
class_id = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_instance8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
instance = tvb_get_guint8(tvb, offset);
offset++;
if (data_length > 3)
{
attribute = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(devicenet_tree, hf_devicenet_attribute, tvb, offset, 1, ENC_LITTLE_ENDIAN);
att_info = cip_get_attribute(class_id, instance, attribute);
if (att_info != NULL)
proto_item_append_text(ti, " (%s)", att_info->text);
offset++;
}
if (data_length > 4)
{
length = offset-start_offset;
proto_tree_add_item(devicenet_tree, hf_devicenet_data, tvb, offset, length, ENC_NA);
offset += length;
}
return offset;
}
static gint body_type_8_over_16_dissection(guint8 data_length, proto_tree *devicenet_tree,
tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
guint16 class_id, instance, attribute;
attribute_info_t* att_info;
proto_item* ti;
devicenet_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, -1, ett_devicenet_8_16, NULL, "DeviceNet 8/16");
proto_tree_add_item(devicenet_tree, hf_devicenet_class8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
class_id = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_instance16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
instance = tvb_get_letohs(tvb, offset);
if (data_length > 4)
{
attribute = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(devicenet_tree, hf_devicenet_attribute, tvb, offset, 1, ENC_LITTLE_ENDIAN);
att_info = cip_get_attribute(class_id, instance, attribute);
if (att_info != NULL)
proto_item_append_text(ti, " (%s)", att_info->text);
offset++;
}
return offset;
}
static gint body_type_16_over_8_dissection(guint8 data_length, proto_tree *devicenet_tree, tvbuff_t *tvb,
packet_info *pinfo _U_, gint offset)
{
guint16 class_id, instance, attribute;
attribute_info_t* att_info;
proto_item* ti;
devicenet_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, -1, ett_devicenet_16_8, NULL, "DeviceNet 16/8");
proto_tree_add_item(devicenet_tree, hf_devicenet_class16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
class_id = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(devicenet_tree, hf_devicenet_instance8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
instance = tvb_get_guint8(tvb, offset);
offset++;
if (data_length > 4)
{
attribute = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(devicenet_tree, hf_devicenet_attribute, tvb, offset, 1, ENC_LITTLE_ENDIAN);
att_info = cip_get_attribute(class_id, instance, attribute);
if (att_info != NULL)
proto_item_append_text(ti, " (%s)", att_info->text);
offset++;
}
return offset;
}
static gint body_type_16_over_16_dissection(guint8 data_length, proto_tree *devicenet_tree, tvbuff_t *tvb,
packet_info *pinfo _U_, gint offset)
{
guint16 class_id, instance, attribute;
attribute_info_t* att_info;
proto_item* ti;
devicenet_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, 4, ett_devicenet_16_16, NULL, "DeviceNet 16/16");
proto_tree_add_item(devicenet_tree, hf_devicenet_class16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
class_id = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(devicenet_tree, hf_devicenet_instance16, tvb, offset, 2, ENC_LITTLE_ENDIAN);
instance = tvb_get_letohs(tvb, offset);
offset+=2;
if (data_length > 5)
{
attribute = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(devicenet_tree, hf_devicenet_attribute, tvb, offset, 1, ENC_LITTLE_ENDIAN);
att_info = cip_get_attribute(class_id, instance, attribute);
if (att_info != NULL)
proto_item_append_text(ti, " (%s)", att_info->text);
offset++;
}
return offset;
}
static int dissect_devicenet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti, *can_id_item,
*msg_id_item, *service_item;
proto_tree *devicenet_tree, *can_tree, *content_tree;
gint offset = 0;
guint16 message_id;
guint32 data_length = tvb_reported_length(tvb);
guint8 source_mac;
struct can_identifier can_id;
guint8 service_rr;
guint8 *src_address, *dest_address;
DISSECTOR_ASSERT(data);
can_id = *((struct can_identifier*)data);
can_id.id = GUINT32_SWAP_LE_BE(can_id.id);
if (can_id.id & (~DEVICENET_CANID_MASK))
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DeviceNet");
ti = proto_tree_add_item(tree, proto_devicenet, tvb, offset, -1, ENC_NA);
devicenet_tree = proto_item_add_subtree(ti, ett_devicenet);
can_tree = proto_tree_add_subtree_format(devicenet_tree, tvb, 0, 0, ett_devicenet_can, NULL, "CAN Identifier: 0x%04x", can_id.id);
can_id_item = proto_tree_add_uint(can_tree, hf_devicenet_can_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(can_id_item);
if ( can_id.id <= MESSAGE_GROUP_1_ID )
{
ti = proto_tree_add_uint(can_tree, hf_devicenet_grp_msg1_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_devicenet_src_mac_id, tvb, 0, 0, can_id.id & MESSAGE_GROUP_1_MAC_ID_MASK);
PROTO_ITEM_SET_GENERATED(ti);
src_address = (guint8*)wmem_alloc(pinfo->pool, 1);
*src_address = (guint8)(can_id.id & MESSAGE_GROUP_1_MAC_ID_MASK);
set_address(&pinfo->src, devicenet_address_type, 1, (const void*)src_address);
message_id = can_id.id & MESSAGE_GROUP_1_MSG_MASK;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_id, devicenet_grp_msg1_vals, "Other Group 1 Message"));
proto_tree_add_item(devicenet_tree, hf_devicenet_data, tvb, offset, data_length, ENC_NA);
}
else if (can_id.id <= MESSAGE_GROUP_2_ID )
{
ti = proto_tree_add_uint(can_tree, hf_devicenet_grp_msg2_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
message_id = can_id.id & MESSAGE_GROUP_2_MSG_MASK;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_id, devicenet_grp_msg2_vals, "Unknown"));
ti = proto_tree_add_uint(can_tree, hf_devicenet_src_mac_id, tvb, 0, 0, (can_id.id & MESSAGE_GROUP_2_MAC_ID_MASK) >> 3);
PROTO_ITEM_SET_GENERATED(ti);
src_address = (guint8*)wmem_alloc(pinfo->pool, 1);
*src_address = (guint8)((can_id.id & MESSAGE_GROUP_2_MAC_ID_MASK) >> 3);
set_address(&pinfo->src, devicenet_address_type, 1, (const void*)src_address);
content_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, -1, ett_devicenet_contents, NULL, "Contents");
switch (message_id)
{
case 0x0:
case 0x1:
case 0x2:
case 0x3:
case 0x4:
case 0x5:
proto_tree_add_item(content_tree, hf_devicenet_data, tvb, offset, data_length, ENC_NA);
break;
case 0x6:
proto_tree_add_item(content_tree, hf_devicenet_data, tvb, offset, data_length, ENC_NA);
break;
case 0x7:
proto_tree_add_item(content_tree, hf_devicenet_dup_mac_id_rr_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_dup_mac_id_physical_port_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset ++;
proto_tree_add_item(content_tree, hf_devicenet_dup_mac_id_vendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(content_tree, hf_devicenet_dup_mac_id_serial_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
}
}
else if (can_id.id <= MESSAGE_GROUP_3_ID )
{
guint8 byte1;
msg_id_item = proto_tree_add_uint(can_tree, hf_devicenet_grp_msg3_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(msg_id_item);
ti = proto_tree_add_uint(can_tree, hf_devicenet_src_mac_id, tvb, 0, 0, can_id.id & MESSAGE_GROUP_3_MAC_ID_MASK);
PROTO_ITEM_SET_GENERATED(ti);
src_address = (guint8*)wmem_alloc(pinfo->pool, 1);
*src_address = (guint8)(can_id.id & MESSAGE_GROUP_3_MAC_ID_MASK);
set_address(&pinfo->src, devicenet_address_type, 1, (const void*)src_address);
message_id = can_id.id & MESSAGE_GROUP_3_MSG_MASK;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_id, devicenet_grp_msg3_vals, "Unknown"));
proto_tree_add_item(devicenet_tree, hf_devicenet_grp_msg3_frag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(devicenet_tree, hf_devicenet_grp_msg3_xid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(devicenet_tree, hf_devicenet_grp_msg3_dest_mac_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
byte1 = tvb_get_guint8(tvb, offset);
source_mac = byte1 & MESSAGE_GROUP_3_MAC_ID_MASK;
dest_address = (guint8*)wmem_alloc(pinfo->pool, 1);
*dest_address = (guint8)source_mac;
set_address(&pinfo->dst, devicenet_address_type, 1, (const void*)dest_address);
offset++;
if (byte1 & MESSAGE_GROUP_3_FRAG_MASK)
{
col_set_str(pinfo->cinfo, COL_INFO, "Group 3 Message Fragment");
content_tree = proto_tree_add_subtree(devicenet_tree, tvb, offset, -1, ett_devicenet_contents, NULL, "Fragmentation");
proto_tree_add_item(content_tree, hf_devicenet_fragment_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_fragment_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_expert(content_tree, pinfo, &ei_devicenet_frag_not_supported, tvb, offset, -1);
col_set_str(pinfo->cinfo, COL_INFO, try_val_to_str((tvb_get_guint8(tvb, offset) & 0xC0) >> 6, devicenet_fragmented_message_type_vals));
}
else
{
service_rr = tvb_get_guint8(tvb, offset);
content_tree = proto_tree_add_subtree_format(devicenet_tree, tvb, offset, -1, ett_devicenet_contents, NULL,
"Service: %s (%s)", val_to_str_const(service_rr & CIP_SC_MASK, devicenet_service_code_vals, "Unknown"),
service_rr & CIP_SC_RESPONSE_MASK ? "Response" : "Request");
proto_tree_add_item(content_tree, hf_devicenet_rr_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
service_item = proto_tree_add_item(content_tree, hf_devicenet_service_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(service_rr & CIP_SC_MASK, devicenet_service_code_vals, "Unknown Service Code"));
if (service_rr & CIP_SC_RESPONSE_MASK)
{
col_append_str(pinfo->cinfo, COL_INFO, " - Response");
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " - Request");
}
switch(message_id)
{
case 0x140:
switch(service_rr & CIP_SC_MASK)
{
case SC_OPEN_EXPLICIT_MESSAGE:
case SC_CLOSE_EXPLICIT_MESSAGE:
case SC_DEVICE_HEARTBEAT_MESSAGE:
case SC_DEVICE_SHUTOWN_MESSAGE:
break;
default:
expert_add_info_format(pinfo, service_item, &ei_devicenet_invalid_service,
"Invalid service code (0x%x) for Group 3 Message ID 5", service_rr & CIP_SC_MASK);
break;
}
break;
case 0x180:
switch(service_rr & CIP_SC_MASK)
{
case SC_OPEN_EXPLICIT_MESSAGE:
case SC_CLOSE_EXPLICIT_MESSAGE:
break;
default:
expert_add_info_format(pinfo, service_item, &ei_devicenet_invalid_service,
"Invalid service code (0x%x) for Group 3 Message ID 6", service_rr & CIP_SC_MASK);
break;
}
break;
case 0x1C0:
expert_add_info_format(pinfo, msg_id_item, &ei_devicenet_invalid_msg_id,
"Invalid Group 3 Message ID (%d)", message_id);
break;
}
switch(service_rr & CIP_SC_MASK)
{
case SC_OPEN_EXPLICIT_MESSAGE:
if (service_rr & CIP_SC_RESPONSE_MASK)
{
proto_tree_add_item(content_tree, hf_devicenet_open_exp_msg_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_open_exp_msg_actual_body_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_devicenet_open_exp_dest_message_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_open_exp_src_message_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_devicenet_connection_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_item(content_tree, hf_devicenet_open_exp_msg_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_open_exp_msg_req_body_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_devicenet_open_exp_group_select, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(content_tree, hf_devicenet_open_exp_src_message_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
break;
case SC_CLOSE_EXPLICIT_MESSAGE:
if ((service_rr & CIP_SC_RESPONSE_MASK) == 0)
{
proto_tree_add_item(content_tree, hf_devicenet_connection_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
break;
default:
if(service_rr & CIP_SC_MASK)
{
proto_tree_add_item(devicenet_tree, hf_devicenet_data, tvb, offset, data_length - 2, ENC_NA);
}
else
{
guint channel;
for (channel = 0; channel < num_devicenet_records_uat; channel++)
{
if (uat_devicenet_records[channel].mac_id == source_mac)
{
switch(uat_devicenet_records[channel].behavior)
{
case 0:
body_type_8_over_8_dissection(data_length, content_tree, tvb, pinfo, offset);
break;
case 1:
body_type_8_over_16_dissection(data_length, content_tree, tvb, pinfo, offset);
break;
case 2:
body_type_16_over_8_dissection(data_length, content_tree, tvb, pinfo, offset);
break;
case 3:
body_type_16_over_16_dissection(data_length, content_tree, tvb, pinfo, offset);
break;
default:
proto_tree_add_item(content_tree, hf_devicenet_data, tvb, offset, data_length, ENC_NA);
break;
}
}
}
if (channel >= num_devicenet_records_uat)
{
body_type_8_over_8_dissection(data_length, content_tree, tvb, pinfo, offset);
}
}
break;
}
}
}
else if (can_id.id <= MESSAGE_GROUP_4_ID )
{
ti = proto_tree_add_uint(can_tree, hf_devicenet_grp_msg4_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
message_id = can_id.id & MESSAGE_GROUP_4_MSG_MASK;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_id, devicenet_grp_msg4_vals, "Reserved Group 4 Message"));
switch(message_id)
{
case GRP4_COMM_FAULT_RESPONSE:
case GRP4_COMM_FAULT_REQUEST:
if(data_length == 2)
{
proto_tree_add_item(devicenet_tree, hf_devicenet_comm_fault_rsv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(devicenet_tree, hf_devicenet_comm_fault_match, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(devicenet_tree, hf_devicenet_comm_fault_value, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_rr_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(devicenet_tree, hf_devicenet_service_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if( tvb_get_guint8(tvb, offset) & CIP_SC_RESPONSE_MASK)
{
col_append_str(pinfo->cinfo, COL_INFO, " - Response");
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " - Request");
}
}
else if(data_length == 8)
{
proto_tree_add_item(devicenet_tree, hf_devicenet_comm_fault_rsv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_rr_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(devicenet_tree, hf_devicenet_service_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if( tvb_get_guint8(tvb, offset) & CIP_SC_RESPONSE_MASK)
{
col_append_str(pinfo->cinfo, COL_INFO, " - Response");
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " - Request");
}
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_vendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(devicenet_tree, hf_devicenet_serial_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case GRP4_OFFLINE_OWNER_REQUEST:
case GRP4_OFFLINE_OWNER_RESPONSE:
proto_tree_add_item(devicenet_tree, hf_devicenet_offline_ownership_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(devicenet_tree, hf_devicenet_offline_ownership_client_mac_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_rr_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if( tvb_get_guint8(tvb, offset) & CIP_SC_RESPONSE_MASK)
{
col_append_str(pinfo->cinfo, COL_INFO, " - Response");
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, " - Request");
}
proto_tree_add_item(devicenet_tree, hf_devicenet_offline_ownership_allocate, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(devicenet_tree, hf_devicenet_vendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(devicenet_tree, hf_devicenet_serial_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
}
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Invalid CAN Message 0x%06X", can_id.id);
expert_add_info_format(pinfo, can_id_item, &ei_devicenet_invalid_can_id,
"Invalid CAN Message 0x%04X", can_id.id);
}
return tvb_captured_length(tvb);
}
static int devicenet_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrdata = (const guint8 *)addr->data;
guint32_to_str_buf(*addrdata, buf, buf_len);
return (int)strlen(buf);
}
static int devicenet_addr_str_len(const address* addr _U_)
{
return 11;
}
static int devicenet_addr_len(void)
{
return 1;
}
void proto_register_devicenet(void)
{
module_t *devicenet_module;
expert_module_t*expert_devicenet;
static hf_register_info hf[] = {
{ &hf_devicenet_can_id,
{"CAN Identifier", "devicenet.can_id",
FT_UINT16, BASE_HEX, NULL, DEVICENET_CANID_MASK,
NULL, HFILL }
},
{ &hf_devicenet_src_mac_id,
{ "Source MAC ID", "devicenet.src_mac_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_devicenet_connection_id,
{ "Connection ID", "devicenet.connection_id",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_devicenet_data,
{ "Data", "devicenet.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg1_id,
{ "Group 1 message ID", "devicenet.grp_msg1.id",
FT_UINT16, BASE_DEC, NULL, MESSAGE_GROUP_1_MSG_MASK,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg2_id,
{ "Group 2 message ID", "devicenet.grp_msg2.id",
FT_UINT16, BASE_DEC, NULL, MESSAGE_GROUP_2_MSG_MASK,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg3_id,
{ "Group 3 message ID", "devicenet.grp_msg3.id",
FT_UINT16, BASE_DEC, NULL, MESSAGE_GROUP_3_MSG_MASK,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg3_dest_mac_id,
{ "Destination MAC ID", "devicenet.dest_mac_id",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg3_frag,
{ "Frag", "devicenet.grp_msg3.frag",
FT_BOOLEAN, 8, NULL, MESSAGE_GROUP_3_FRAG_MASK,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg3_xid,
{ "XID", "devicenet.grp_msg3.xid",
FT_BOOLEAN, 8, NULL, MESSAGE_GROUP_3_XID_MASK,
NULL, HFILL }
},
{ &hf_devicenet_grp_msg4_id,
{ "Group 4 message ID", "devicenet.grp_msg4.id",
FT_UINT16, BASE_DEC, NULL, MESSAGE_GROUP_4_MSG_MASK,
NULL, HFILL }
},
{ &hf_devicenet_rr_bit,
{ "Request/Response", "devicenet.rr",
FT_UINT8, BASE_DEC, VALS(cip_sc_rr), CIP_SC_RESPONSE_MASK,
"Request or Response message", HFILL }
},
{ &hf_devicenet_service_code,
{ "Service Code", "devicenet.service",
FT_UINT8, BASE_DEC, VALS(devicenet_service_code_vals), CIP_SC_MASK,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_src_message_id,
{ "Source Message ID", "devicenet.open_message.src_message_id",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_dest_message_id,
{ "Destination Message ID", "devicenet.open_message.dest_message_id",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_msg_reserved,
{ "Reserved", "devicenet.open_message.reserved",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_msg_req_body_format,
{ "Requested Message Body Format", "devicenet.open_message.req_body_format",
FT_UINT8, BASE_DEC, VALS(devicenet_message_body_format_vals), 0x0F,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_msg_actual_body_format,
{ "Actual Message Body Format", "devicenet.open_message.actual_body_format",
FT_UINT8, BASE_DEC, VALS(devicenet_message_body_format_vals), 0x0F,
NULL, HFILL }
},
{ &hf_devicenet_open_exp_group_select,
{ "Group Select", "devicenet.open_message.group_select",
FT_UINT8, BASE_DEC, VALS(devicenet_group_select_vals), 0xF0,
NULL, HFILL }
},
{ &hf_devicenet_dup_mac_id_rr_bit,
{ "Request/Response", "devicenet.dup_mac_id.rr",
FT_UINT8, BASE_DEC, VALS(cip_sc_rr), CIP_SC_RESPONSE_MASK,
"Duplicate MAC ID Request or Response message", HFILL }
},
{ &hf_devicenet_dup_mac_id_physical_port_number,
{ "Physical port number", "devicenet.dup_mac_id.physical_port_number",
FT_UINT8, BASE_DEC, NULL, 0x7F,
"Duplicate MAC ID check message physical port number", HFILL }
},
{ &hf_devicenet_dup_mac_id_vendor,
{ "Vendor ID", "devicenet.dup_mac_id.vendor",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0,
NULL, HFILL }
},
{ &hf_devicenet_dup_mac_id_serial_number,
{ "Serial Number", "devicenet.dup_mac_id.serial_number",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_devicenet_vendor,
{ "Vendor ID", "devicenet.vendor",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_vendor_vals_ext, 0,
NULL, HFILL }
},
{ &hf_devicenet_serial_number,
{ "Serial Number", "devicenet.serial_number",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_devicenet_instance8,
{ "Instance", "devicenet.instance",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_devicenet_instance16,
{ "Instance", "devicenet.instance",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_devicenet_attribute,
{ "Attribute", "devicenet.attribute",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_devicenet_fragment_type,
{ "Fragment Type", "devicenet.fragment_type",
FT_UINT8, BASE_HEX, VALS(devicenet_fragmented_message_type_vals), 0xC0,
NULL, HFILL }
},
{ &hf_devicenet_fragment_count,
{ "Fragment Count", "devicenet.fragment_count",
FT_UINT8, BASE_HEX_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_devicenet_class8,
{ "Class", "devicenet.class",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0,
NULL, HFILL }
},
{ &hf_devicenet_class16,
{ "Class", "devicenet.class",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &cip_class_names_vals_ext, 0,
NULL, HFILL }
},
{ &hf_devicenet_comm_fault_rsv,
{ "Reserved", "devicenet.comm_fault.reserved",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_devicenet_comm_fault_match,
{ "Match", "devicenet.comm_fault.match",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }
},
{&hf_devicenet_comm_fault_value,
{ "Value", "devicenet.comm_fault.value",
FT_UINT8, BASE_HEX, NULL, 0x3F,
"Comm Fault Value", HFILL }
},
{&hf_devicenet_offline_ownership_reserved,
{ "Reserved", "devicenet.offline_ownership.reserved",
FT_UINT8, BASE_HEX, NULL, 0xC0,
"Offline ownership Response Message Reserved", HFILL }
},
{&hf_devicenet_offline_ownership_client_mac_id,
{ "Client MAC ID", "devicenet.offline_ownership.client_mac_id",
FT_UINT8, BASE_HEX, NULL, MESSAGE_GROUP_4_MSG_MASK,
"Offline ownership message client MAC ID", HFILL }
},
{&hf_devicenet_offline_ownership_allocate,
{ "Allocate", "devicenet.offline_ownership.allocate",
FT_UINT8, BASE_HEX, NULL, CIP_SC_MASK,
"Offline ownership response message allocate", HFILL }
},
};
static gint *ett[] = {
&ett_devicenet,
&ett_devicenet_can,
&ett_devicenet_contents,
&ett_devicenet_8_8,
&ett_devicenet_8_16,
&ett_devicenet_16_8,
&ett_devicenet_16_16
};
static ei_register_info ei[] = {
{ &ei_devicenet_invalid_service, { "devicenet.invalid_service", PI_PROTOCOL, PI_WARN, "Invalid service", EXPFILL }},
{ &ei_devicenet_invalid_can_id, { "devicenet.invalid_can_id", PI_PROTOCOL, PI_WARN, "Invalid CAN ID", EXPFILL }},
{ &ei_devicenet_invalid_msg_id, { "devicenet.invalid_msg_id", PI_PROTOCOL, PI_WARN, "Invalid Message ID", EXPFILL }},
{ &ei_devicenet_frag_not_supported, { "devicenet.frag_not_supported", PI_UNDECODED, PI_WARN, "Fragmentation not currently supported", EXPFILL }},
};
static uat_field_t devicenet_uat_flds[] = {
UAT_FLD_DEC(uat_devicenet_records, mac_id, "Option number", "Custom Option Number"),
UAT_FLD_VS(uat_devicenet_records, behavior, "Option type", devicenet_message_body_format_vals, "Option datatype"),
UAT_END_FIELDS
};
proto_devicenet = proto_register_protocol("DeviceNet Protocol", "DeviceNet", "devicenet");
proto_register_field_array(proto_devicenet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_devicenet = expert_register_protocol(proto_devicenet);
expert_register_field_array(expert_devicenet, ei, array_length(ei));
devicenet_address_type = address_type_dissector_register("AT_DEVICENET", "DeviceNet Address", devicenet_addr_to_str, devicenet_addr_str_len, NULL, NULL, devicenet_addr_len, NULL, NULL);
devicenet_module = prefs_register_protocol(proto_devicenet, NULL);
devicenet_uat = uat_new("Node bodytypes",
sizeof(uat_devicenet_record_t),
"devicenet_bodytypes",
TRUE,
&uat_devicenet_records,
&num_devicenet_records_uat,
UAT_AFFECTS_DISSECTION,
NULL,
NULL,
uat_devicenet_record_update_cb,
NULL,
NULL,
NULL,
devicenet_uat_flds);
prefs_register_uat_preference(devicenet_module,
"bodytype_table",
"Node bodytypes",
"Node bodytypes",
devicenet_uat);
}
void
proto_reg_handoff_devicenet(void)
{
dissector_handle_t devicenet_handle;
devicenet_handle = create_dissector_handle( dissect_devicenet, proto_devicenet );
dissector_add_for_decode_as("can.subdissector", devicenet_handle );
}
