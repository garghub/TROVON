static guint32 vsip_ValueTypeString(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int hf_string)
{
int soffset = offset;
guint16 length;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_vsipValueTypeString, &ti, "ValueTypeString");
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_vsip_ValueTypeString_Size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (length > 0)
{
proto_tree_add_item(tree, hf_string, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_ValueTypeBinary(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset, int hf_bin)
{
int soffset = offset;
guint32 length;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_vsipValueTypeBinary, &ti, "Binary");
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_vsip_ValueTypeBinary_Size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (length > 0)
{
proto_tree_add_item(tree, hf_bin, tvb, offset, length, ENC_NA);
offset += length;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_PingReq(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 7, ett_vsipPingReq, NULL, "PingReq");
proto_tree_add_item(tree, hf_vsip_PingReq_ReplyAddress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_PingReq_ReplyPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_PingReq_ConnType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset - soffset;
}
static guint32 vsip_PingResp(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 len;
proto_item *ti;
const int *supp_conn_types[] = {
&hf_vsip_PingResp_SuppConnTypes_VOLATILE,
&hf_vsip_PingResp_SuppConnTypes_RTP,
&hf_vsip_PingResp_SuppConnTypes_SSL,
&hf_vsip_PingResp_SuppConnTypes_UDP_BROADCAST,
&hf_vsip_PingResp_SuppConnTypes_TCP_CLIENT,
&hf_vsip_PingResp_SuppConnTypes_TCP_SERVER,
&hf_vsip_PingResp_SuppConnTypes_UDP_MULTICAST,
&hf_vsip_PingResp_SuppConnTypes_UDP_UNICAST,
NULL
};
tree = proto_tree_add_subtree(tree, tvb, offset, 30, ett_vsipPingResp, &ti, "PingResp");
proto_tree_add_item(tree, hf_vsip_PingResp_DeviceIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_PingResp_DevicePort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_vsip_PingResp_SuppConnTypes, ett_vsipPingResp_SuppConnTypes, supp_conn_types, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_vsip_PingResp_DeviceGUID, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_vsip_PingResp_VendorID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_PingResp_ProductType, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_PingResp_Status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_PingResp_SubtypeLen, tvb, offset, 2, len);
offset += 2;
if (len > 0)
{
proto_tree_add_item(tree, hf_vsip_PingResp_Subtype, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_ContentTypeSwitchReq(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 33, ett_vsipContentTypeSwitchReq, NULL, "ContentTypeSwitchReq");
proto_tree_add_item(tree, hf_vsip_ContentTypeSwitchReq_ApplicationGUID, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_vsip_ContentTypeSwitchReq_ContentType, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_vsip_ContentTypeSwitchReq_DeviceGUID, tvb, offset, 16, ENC_NA);
offset += 16;
return offset - soffset;
}
static guint32 vsip_ContentTypeSwitchResp(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 17, ett_vsipContentTypeSwitchResp, NULL, "ContentTypeSwitchResp");
proto_tree_add_item(tree, hf_vsip_ContentTypeSwitchResp_DeviceGUID, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_vsip_ContentTypeSwitchResp_SwitchResult, tvb, offset, 1, ENC_NA);
return offset - soffset;
}
static guint32 vsip_GetCapabilitiesReq(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_vsipGetCapabilitiesReq, NULL, "GetCapabilitiesReq");
proto_tree_add_item(tree, hf_vsip_GetCapabilitiesReq_DisabledCapabilities, tvb, offset, 1, ENC_NA);
offset++;
return offset - soffset;
}
static guint32 vsip_GetCapabilitiesResp_CapabilityArray(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 21, ett_vsipGetCapabilitiesResp_CapabilityArray, NULL, "CapabilityArray");
proto_tree_add_item(tree, hf_vsip_GetCapabilitiesResp_CapabilityArray_EntityType, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_vsip_GetCapabilitiesResp_CapabilityArray_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_GetCapabilitiesResp_CapabilityArray_VendorID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_GetCapabilitiesResp_CapabilityArray_VersionNumber, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset - soffset;
}
static guint32 vsip_GetCapabilitiesResp(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_vsipGetCapabilitiesResp, &ti, "GetCapabilitiesResp");
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_GetCapabilitiesResp_CapabilityCount, tvb, offset, 2, count);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_GetCapabilitiesResp_CapabilityArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_StartDevice(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 25, ett_vsipStartDevice, NULL, "StartDevice");
proto_tree_add_item(tree, hf_vsip_StartDevice_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_StartDevice_TargetAddress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_StartDevice_TargetPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_StartDevice_LocalPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_StartDevice_ConnectionType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset - soffset;
}
static guint32 vsip_StartDeviceEx(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 41, ett_vsipStartDeviceEx, NULL, "StartDeviceEx");
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_TargetAddress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_TargetPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_LocalPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_ConnectionType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_vsip_StartDeviceEx_TargetGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
return offset - soffset;
}
static guint32 vsip_StopDevice(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_vsipStopDevice, NULL, "StopDevice");
proto_tree_add_item(tree, hf_vsip_StopDevice_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
return offset - soffset;
}
static guint32 vsip_StopDeviceEx(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 32, ett_vsipStopDeviceEx, NULL, "StopDeviceEx");
proto_tree_add_item(tree, hf_vsip_StopDeviceEx_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_StopDeviceEx_TargetGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
return offset - soffset;
}
static guint32 vsip_SetConfigReq_ConfigItemArray(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint8 type;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_vsipSetConfigReq_ConfigItemArray, &ti, "ConfigItemArray");
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_ConfigItemID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_ValueType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(type)
{
case 1:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_CharValue, tvb, offset, 1, ENC_NA);
offset++;
break;
case 2:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_ShortValue, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 3:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_IntValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 4:
offset += vsip_ValueTypeString(tree, pinfo, tvb, offset, hf_vsip_SetConfigReq_ConfigItemArray_Value_StringValue);
break;
case 5:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_UintValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 6:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_GuidValue, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
break;
case 7:
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemArray_Value_FloatValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 8:
offset += vsip_ValueTypeBinary(tree, pinfo, tvb, offset, hf_vsip_SetConfigReq_ConfigItemArray_Value_BinaryValue);
break;
default:
break;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_SetConfigReq(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 18, ett_vsipSetConfigReq, &ti, "SetConfigReq");
proto_tree_add_item(tree, hf_vsip_SetConfigReq_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_vsip_SetConfigReq_ConfigItemCount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_SetConfigReq_ConfigItemArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_GetConfigReq_ConfigItemArray(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_vsipGetConfigReq_ConfigItemArray, NULL, "ConfigItemArray");
proto_tree_add_item(tree, hf_vsip_GetConfigReq_ConfigItemArray_ConfigItemID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset - soffset;
}
static guint32 vsip_GetConfigReq(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 18, ett_vsipGetConfigReq, &ti, "GetConfigReq");
proto_tree_add_item(tree, hf_vsip_GetConfigReq_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_vsip_GetConfigReq_ConfigItemCount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_GetConfigReq_ConfigItemArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_GetConfigResp_ConfigItemArray(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint8 type;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_vsipGetConfigResp_ConfigItemArray, &ti, "ConfigItemArray");
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_ConfigItemID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_ValueType, tvb, offset, 1, ENC_NA);
offset++;
switch(type)
{
case 1:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_CharValue, tvb, offset, 1, ENC_NA);
offset++;
break;
case 2:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_ShortValue, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 3:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_IntValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 4:
offset += vsip_ValueTypeString(tree, pinfo, tvb, offset, hf_vsip_GetConfigResp_ConfigItemArray_Value_StringValue);
break;
case 5:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_UintValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 6:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_GuidValue, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
break;
case 7:
proto_tree_add_item(tree, hf_vsip_GetConfigResp_ConfigItemArray_Value_FloatValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 8:
offset += vsip_ValueTypeBinary(tree, pinfo, tvb, offset, hf_vsip_GetConfigResp_ConfigItemArray_Value_BinaryValue);
break;
default:
break;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_GetConfigResp(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 18, ett_vsipGetConfigResp, &ti, "GetConfigResp");
proto_tree_add_item(tree, hf_vsip_GetConfigResp_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_GetConfigResp_ConfigItemCount, tvb, offset, 2, count);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_GetConfigResp_ConfigItemArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_SendCommand(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 25, ett_vsipSendCommand, &ti, "SendCommand");
proto_tree_add_item(tree, hf_vsip_SendCommand_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_SendCommand_CommandCode, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_vsip_SendCommand_Arg1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_SendCommand_Arg2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset - soffset;
}
static guint32 vsip_SendCommandEx_AddArgsArray(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint8 type;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_vsipSendCommandEx_AddArgsArray, &ti, "AddArgsArray");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_ValueType, tvb, offset, 1, ENC_NA);
offset++;
switch(type)
{
case 1:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_CharValue, tvb, offset, 1, ENC_NA);
offset++;
break;
case 2:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_ShortValue, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 3:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_IntValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 4:
offset += vsip_ValueTypeString(tree, pinfo, tvb, offset, hf_vsip_SendCommandEx_AddArgsArray_Value_StringValue);
break;
case 5:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_UintValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 6:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_GuidValue, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
break;
case 7:
proto_tree_add_item(tree, hf_vsip_SendCommandEx_AddArgsArray_Value_FloatValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 8:
offset += vsip_ValueTypeBinary(tree, pinfo, tvb, offset, hf_vsip_SendCommandEx_AddArgsArray_Value_BinaryValue);
break;
default:
break;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_SendCommandEx(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 27, ett_vsipSendCommandEx, &ti, "SendCommandEx");
proto_tree_add_item(tree, hf_vsip_SendCommandEx_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_SendCommandEx_CommandCode, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_vsip_SendCommandEx_Arg1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_SendCommandEx_Arg2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_SendCommandEx_NumAddArgs, tvb, offset, 2, count);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_SendCommandEx_AddArgsArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_EventNotify(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 22, ett_vsipEventNotify, NULL, "EventNotify");
proto_tree_add_item(tree, hf_vsip_EventNotify_CapabilityGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_vsip_EventNotify_EventType, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_EventNotify_EventArgument, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset - soffset;
}
static guint32 vsip_EventSubscribeReq(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 7, ett_vsipEventSubscribeReq, NULL, "EventSubscribeReq");
proto_tree_add_item(tree, hf_vsip_EventSubscribeReq_ReceiverAddress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_EventSubscribeReq_ReceiverPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_EventSubscribeReq_ConnectionType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset - soffset;
}
static guint32 vsip_EventSubscribeExReq(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 23, ett_vsipEventSubscribeExReq, NULL, "EventSubscribeExReq");
proto_tree_add_item(tree, hf_vsip_EventSubscribeExReq_ReceiverAddress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_vsip_EventSubscribeExReq_ReceiverPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_vsip_EventSubscribeExReq_ConnectionType, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_vsip_EventSubscribeExReq_DestinationGUID, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
return offset - soffset;
}
static guint32 vsip_ErrorResponse(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int soffset = offset;
tree = proto_tree_add_subtree(tree, tvb, offset, 5, ett_vsipErrorResponse, NULL, "ErrorResponse");
proto_tree_add_item(tree, hf_vsip_ErrorResponse_RequestMessageType, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_vsip_ErrorResponse_StatusCode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset - soffset;
}
static guint32 vsip_ErrorVAResponse_AddArgsArray(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint8 type;
proto_item* ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_vsipErrorVAResponse_AddArgsArray, &ti, "AddArgsArray");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_ValueType, tvb, offset, 1, ENC_NA);
offset++;
switch(type)
{
case 1:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_CharValue, tvb, offset, 1, ENC_NA);
offset++;
break;
case 2:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_ShortValue, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case 3:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_IntValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 4:
offset += vsip_ValueTypeString(tree, pinfo, tvb, offset, hf_vsip_ErrorVAResponse_AddArgsArray_Value_StringValue);
break;
case 5:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_UintValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 6:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_GuidValue, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
break;
case 7:
proto_tree_add_item(tree, hf_vsip_ErrorVAResponse_AddArgsArray_Value_FloatValue, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 8:
offset += vsip_ValueTypeBinary(tree, pinfo, tvb, offset, hf_vsip_ErrorVAResponse_AddArgsArray_Value_BinaryValue);
break;
default:
break;
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_ErrorVAResponse(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int soffset = offset;
guint16 count;
guint32 i;
proto_item *ti;
tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_vsipErrorVAResponse, &ti, "ErrorVAResponse");
offset += vsip_ErrorResponse(tree, pinfo, tvb, offset);
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_ErrorVAResponse_NumAddArgs, tvb, offset, 2, count);
offset += 2;
for(i = 0; i < count; ++i)
{
offset += vsip_ErrorVAResponse_AddArgsArray(tree, pinfo, tvb, offset);
}
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static guint32 vsip_dissect_pdu(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
int soffset = offset;
guint16 version;
guint8 type;
proto_item *ti;
version = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_vsip_Version, tvb, offset, 2, version);
offset += 2;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_vsip_Type, tvb, offset, 1, type);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(type, &EVsipMessageType_vals_ext, "Unknown") );
offset++;
proto_tree_add_item(tree, hf_vsip_TransacId, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (version == 257)
{
proto_tree_add_item(tree, hf_vsip_PacketSize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if(version == 256)
{
proto_tree_add_item(tree, hf_vsip_PacketSize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
switch(type)
{
case 1:
offset += vsip_PingReq(tree, pinfo, tvb, offset);
break;
case 2:
offset += vsip_PingResp(tree, pinfo, tvb, offset);
break;
case 19:
offset += vsip_ContentTypeSwitchReq(tree, pinfo, tvb, offset);
break;
case 20:
offset += vsip_ContentTypeSwitchResp(tree, pinfo, tvb, offset);
break;
case 3:
offset += vsip_GetCapabilitiesReq(tree, pinfo, tvb, offset);
break;
case 4:
offset += vsip_GetCapabilitiesResp(tree, pinfo, tvb, offset);
break;
case 5:
offset += vsip_StartDevice(tree, pinfo, tvb, offset);
break;
case 21:
offset += vsip_StartDeviceEx(tree, pinfo, tvb, offset);
break;
case 6:
offset += vsip_StopDevice(tree, pinfo, tvb, offset);
break;
case 22:
offset += vsip_StopDeviceEx(tree, pinfo, tvb, offset);
break;
case 7:
offset += vsip_SetConfigReq(tree, pinfo, tvb, offset);
break;
case 8:
offset += vsip_GetConfigReq(tree, pinfo, tvb, offset);
break;
case 9:
offset += vsip_GetConfigResp(tree, pinfo, tvb, offset);
break;
case 10:
offset += vsip_SendCommand(tree, pinfo, tvb, offset);
break;
case 24:
offset += vsip_SendCommandEx(tree, pinfo, tvb, offset);
break;
case 11:
offset += vsip_EventNotify(tree, pinfo, tvb, offset);
break;
case 12:
offset += vsip_EventSubscribeReq(tree, pinfo, tvb, offset);
break;
case 23:
offset += vsip_EventSubscribeExReq(tree, pinfo, tvb, offset);
break;
case 13:
offset += vsip_ErrorResponse(tree, pinfo, tvb, offset);
break;
case 48:
offset += vsip_ErrorVAResponse(tree, pinfo, tvb, offset);
break;
default:
break;
}
ti = proto_tree_get_parent(tree);
proto_item_set_len(ti, offset - soffset);
return offset - soffset;
}
static int dissect_vsip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
guint16 version;
version = tvb_get_ntohs(tvb, 0);
if ((version != 0x0100) && (version != 0x0101))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VSIP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_vsip, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_vsip);
return vsip_dissect_pdu(tvb, 0, pinfo, tree);
}
static void
vsip_fmt_revision( gchar *result, guint32 revision )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d", (guint8)(( revision & 0xFF00 ) >> 8), (guint8)(revision & 0xFF) );
}
void proto_register_vsip(void)
{
static int *ett[] = {
&ett_vsipValueTypeString,
&ett_vsipValueTypeBinary,
&ett_vsipPingReq,
&ett_vsipPingResp_SuppConnTypes,
&ett_vsipPingResp,
&ett_vsipContentTypeSwitchReq,
&ett_vsipContentTypeSwitchResp,
&ett_vsipGetCapabilitiesReq,
&ett_vsipGetCapabilitiesResp_CapabilityArray,
&ett_vsipGetCapabilitiesResp,
&ett_vsipStartDevice,
&ett_vsipStartDeviceEx,
&ett_vsipStopDevice,
&ett_vsipStopDeviceEx,
&ett_vsipSetConfigReq_ConfigItemArray,
&ett_vsipSetConfigReq,
&ett_vsipGetConfigReq_ConfigItemArray,
&ett_vsipGetConfigReq,
&ett_vsipGetConfigResp_ConfigItemArray,
&ett_vsipGetConfigResp,
&ett_vsipSendCommand,
&ett_vsipSendCommandEx_AddArgsArray,
&ett_vsipSendCommandEx,
&ett_vsipEventNotify,
&ett_vsipEventSubscribeReq,
&ett_vsipEventSubscribeExReq,
&ett_vsipErrorResponse,
&ett_vsipErrorVAResponse_AddArgsArray,
&ett_vsipErrorVAResponse,
&ett_vsip
};
static hf_register_info hf[] = {
{ &hf_vsip_ValueTypeBinary_Size,
{ "Size", "vsip.ValueTypeBinary.Size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ValueTypeString_Size,
{ "Size", "vsip.ValueTypeString.Size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingReq_ReplyAddress,
{ "ReplyAddress", "vsip.PingReq.ReplyAddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingReq_ReplyPort,
{ "ReplyPort", "vsip.PingReq.ReplyPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingReq_ConnType,
{ "ConnType", "vsip.PingReq.ConnType", FT_UINT8, BASE_HEX,
VALS(EVsipConnectionType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_DeviceIP,
{ "DeviceIP", "vsip.PingResp.DeviceIP", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_DevicePort,
{ "DevicePort", "vsip.PingResp.DevicePort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_DeviceGUID,
{ "DeviceGUID", "vsip.PingResp.DeviceGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_VendorID,
{ "VendorID", "vsip.PingResp.VendorID", FT_UINT16, BASE_DEC,
VALS(EVsipVendorID_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_ProductType,
{ "ProductType", "vsip.PingResp.ProductType", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_Status,
{ "Status", "vsip.PingResp.Status", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_SubtypeLen,
{ "SubtypeLen", "vsip.PingResp.SubtypeLen", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_Subtype,
{ "Subtype", "vsip.PingResp.Subtype", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes,
{ "SuppConnTypes", "vsip.PingResp.SuppConnTypes", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_VOLATILE,
{ "VOLATILE", "vsip.PingResp_SuppConnTypes.VOLATILE", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_RTP,
{ "RTP", "vsip.PingResp_SuppConnTypes.RTP", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_SSL,
{ "SSL", "vsip.PingResp_SuppConnTypes.SSL", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_UDP_BROADCAST,
{ "UDP_BROADCAST", "vsip.PingResp_SuppConnTypes.UDP_BROADCAST", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x10, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_TCP_CLIENT,
{ "TCP_CLIENT", "vsip.PingResp_SuppConnTypes.TCP_CLIENT", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_TCP_SERVER,
{ "TCP_SERVER", "vsip.PingResp_SuppConnTypes.TCP_SERVER", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_UDP_MULTICAST,
{ "UDP_MULTICAST", "vsip.PingResp_SuppConnTypes.UDP_MULTICAST", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL } },
{ &hf_vsip_PingResp_SuppConnTypes_UDP_UNICAST,
{ "UDP_UNICAST", "vsip.PingResp_SuppConnTypes.UDP_UNICAST", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL } },
{ &hf_vsip_ContentTypeSwitchReq_ApplicationGUID,
{ "ApplicationGUID", "vsip.ContentTypeSwitchReq.ApplicationGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ContentTypeSwitchReq_ContentType,
{ "ContentType", "vsip.ContentTypeSwitchReq.ContentType", FT_UINT8, BASE_DEC,
VALS(EVsipContentType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_ContentTypeSwitchReq_DeviceGUID,
{ "DeviceGUID", "vsip.ContentTypeSwitchReq.DeviceGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ContentTypeSwitchResp_DeviceGUID,
{ "DeviceGUID", "vsip.ContentTypeSwitchResp.DeviceGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ContentTypeSwitchResp_SwitchResult,
{ "SwitchResult", "vsip.ContentTypeSwitchResp.SwitchResult", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesReq_DisabledCapabilities,
{ "DisabledCapabilities", "vsip.GetCapabilitiesReq.DisabledCapabilities", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesResp_CapabilityArray_EntityType,
{ "EntityType", "vsip.GetCapabilitiesResp_CapabilityArray.EntityType", FT_UINT8, BASE_DEC,
VALS(EVsipEntityType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesResp_CapabilityArray_CapabilityGUID,
{ "CapabilityGUID", "vsip.GetCapabilitiesResp_CapabilityArray.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesResp_CapabilityArray_VendorID,
{ "VendorID", "vsip.GetCapabilitiesResp_CapabilityArray.VendorID", FT_UINT16, BASE_DEC,
VALS(EVsipVendorID_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesResp_CapabilityArray_VersionNumber,
{ "VersionNumber", "vsip.GetCapabilitiesResp_CapabilityArray.VersionNumber", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetCapabilitiesResp_CapabilityCount,
{ "CapabilityCount", "vsip.GetCapabilitiesResp.CapabilityCount", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDevice_CapabilityGUID,
{ "CapabilityGUID", "vsip.StartDevice.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDevice_TargetAddress,
{ "TargetAddress", "vsip.StartDevice.TargetAddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDevice_TargetPort,
{ "TargetPort", "vsip.StartDevice.TargetPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDevice_LocalPort,
{ "LocalPort", "vsip.StartDevice.LocalPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDevice_ConnectionType,
{ "ConnectionType", "vsip.StartDevice.ConnectionType", FT_UINT8, BASE_DEC,
VALS(EVsipConnectionType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_CapabilityGUID,
{ "CapabilityGUID", "vsip.StartDeviceEx.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_TargetAddress,
{ "TargetAddress", "vsip.StartDeviceEx.TargetAddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_TargetPort,
{ "TargetPort", "vsip.StartDeviceEx.TargetPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_LocalPort,
{ "LocalPort", "vsip.StartDeviceEx.LocalPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_ConnectionType,
{ "ConnectionType", "vsip.StartDeviceEx.ConnectionType", FT_UINT8, BASE_DEC,
VALS(EVsipConnectionType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_StartDeviceEx_TargetGUID,
{ "TargetGUID", "vsip.StartDeviceEx.TargetGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StopDevice_CapabilityGUID,
{ "CapabilityGUID", "vsip.StopDevice.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StopDeviceEx_CapabilityGUID,
{ "CapabilityGUID", "vsip.StopDeviceEx.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_StopDeviceEx_TargetGUID,
{ "TargetGUID", "vsip.StopDeviceEx.TargetGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_ConfigItemID,
{ "ConfigItemID", "vsip.SetConfigReq_ConfigItemArray.ConfigItemID", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&EVsipConfigItem_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_ValueType,
{ "ValueType", "vsip.SetConfigReq_ConfigItemArray.ValueType", FT_UINT8, BASE_DEC,
VALS(EVsipValueType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_CharValue,
{ "CharValue", "vsip.SetConfigReq_ConfigItemArray.CharValue",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_ShortValue,
{ "ShortValue", "vsip.SetConfigReq_ConfigItemArray.ShortValue",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_IntValue,
{ "IntValue", "vsip.SetConfigReq_ConfigItemArray.IntValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_StringValue,
{ "StringValue", "vsip.SetConfigReq_ConfigItemArray.StringValue", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_UintValue,
{ "UintValue", "vsip.SetConfigReq_ConfigItemArray.UintValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_GuidValue,
{ "GuidValue", "vsip.SetConfigReq_ConfigItemArray.GuidValue", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_FloatValue,
{ "FloatValue", "vsip.SetConfigReq_ConfigItemArray.FloatValue", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemArray_Value_BinaryValue,
{ "BinaryValue", "vsip.SetConfigReq_ConfigItemArray.BinaryValue", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_CapabilityGUID,
{ "CapabilityGUID", "vsip.SetConfigReq.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SetConfigReq_ConfigItemCount,
{ "ConfigItemCount", "vsip.SetConfigReq.ConfigItemCount", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigReq_ConfigItemArray_ConfigItemID,
{ "ConfigItemID", "vsip.GetConfigReq_ConfigItemArray.ConfigItemID", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&EVsipConfigItem_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigReq_CapabilityGUID,
{ "CapabilityGUID", "vsip.GetConfigReq.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigReq_ConfigItemCount,
{ "ConfigItemCount", "vsip.GetConfigReq.ConfigItemCount", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_ConfigItemID,
{ "ConfigItemID", "vsip.GetConfigResp_ConfigItemArray.ConfigItemID", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&EVsipConfigItem_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_ValueType,
{ "ValueType", "vsip.GetConfigResp_ConfigItemArray.ValueType", FT_UINT8, BASE_DEC,
VALS(EVsipValueType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_CharValue,
{ "CharValue", "vsip.GetConfigResp_ConfigItemArray.CharValue", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_ShortValue,
{ "ShortValue", "vsip.GetConfigResp_ConfigItemArray.ShortValue", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_IntValue,
{ "IntValue", "vsip.GetConfigResp_ConfigItemArray.IntValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_StringValue,
{ "StringValue", "vsip.GetConfigResp_ConfigItemArray.StringValue", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_UintValue,
{ "UintValue", "vsip.GetConfigResp_ConfigItemArray.UintValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_GuidValue,
{ "GuidValue", "vsip.GetConfigResp_ConfigItemArray.GuidValue", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_FloatValue,
{ "FloatValue", "vsip.GetConfigResp_ConfigItemArray.FloatValue", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemArray_Value_BinaryValue,
{ "BinaryValue", "vsip.GetConfigResp_ConfigItemArray.BinaryValue", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_CapabilityGUID,
{ "CapabilityGUID", "vsip.GetConfigResp.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_GetConfigResp_ConfigItemCount,
{ "ConfigItemCount", "vsip.GetConfigResp.ConfigItemCount", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommand_CapabilityGUID,
{ "CapabilityGUID", "vsip.SendCommand.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommand_CommandCode,
{ "CommandCode", "vsip.SendCommand.CommandCode", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&EVsipCommand_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommand_Arg1,
{ "Arg1", "vsip.SendCommand.Arg1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommand_Arg2,
{ "Arg2", "vsip.SendCommand.Arg2", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_ValueType,
{ "ValueType", "vsip.SendCommandEx_AddArgsArray.ValueType", FT_UINT8, BASE_DEC,
VALS(EVsipValueType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_CharValue,
{ "CharValue", "vsip.SendCommandEx_AddArgsArray.CharValue", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_ShortValue,
{ "ShortValue", "vsip.SendCommandEx_AddArgsArray.ShortValue", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_IntValue,
{ "IntValue", "vsip.SendCommandEx_AddArgsArray.IntValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_StringValue,
{ "StringValue", "vsip.SendCommandEx_AddArgsArray.StringValue", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_UintValue,
{ "UintValue", "vsip.SendCommandEx_AddArgsArray.UintValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_GuidValue,
{ "GuidValue", "vsip.SendCommandEx_AddArgsArray.GuidValue", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_FloatValue,
{ "FloatValue", "vsip.SendCommandEx_AddArgsArray.FloatValue", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_AddArgsArray_Value_BinaryValue,
{ "BinaryValue", "vsip.SendCommandEx_AddArgsArray.BinaryValue", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_CapabilityGUID,
{ "CapabilityGUID", "vsip.SendCommandEx.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_CommandCode,
{ "CommandCode", "vsip.SendCommandEx.CommandCode", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&EVsipCommand_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_Arg1,
{ "Arg1", "vsip.SendCommandEx.Arg1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_Arg2,
{ "Arg2", "vsip.SendCommandEx.Arg2", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_SendCommandEx_NumAddArgs,
{ "NumAddArgs", "vsip.SendCommandEx.NumAddArgs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventNotify_CapabilityGUID,
{ "CapabilityGUID", "vsip.EventNotify.CapabilityGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventNotify_EventType,
{ "EventType", "vsip.EventNotify.EventType", FT_UINT16, BASE_DEC,
VALS(EVsipEventType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_EventNotify_EventArgument,
{ "EventArgument", "vsip.EventNotify.EventArgument", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeReq_ReceiverAddress,
{ "ReceiverAddress", "vsip.EventSubscribeReq.ReceiverAddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeReq_ReceiverPort,
{ "ReceiverPort", "vsip.EventSubscribeReq.ReceiverPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeReq_ConnectionType,
{ "ConnectionType", "vsip.EventSubscribeReq.ConnectionType", FT_UINT8, BASE_DEC,
VALS(EVsipConnectionType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeExReq_ReceiverAddress,
{ "ReceiverAddress", "vsip.EventSubscribeExReq.ReceiverAddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeExReq_ReceiverPort,
{ "ReceiverPort", "vsip.EventSubscribeExReq.ReceiverPort", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeExReq_ConnectionType,
{ "ConnectionType", "vsip.EventSubscribeExReq.ConnectionType", FT_UINT8, BASE_DEC,
VALS(EVsipConnectionType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_EventSubscribeExReq_DestinationGUID,
{ "DestinationGUID", "vsip.EventSubscribeExReq.DestinationGUID", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorResponse_RequestMessageType,
{ "RequestMessageType", "vsip.ErrorResponse.RequestMessageType", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&EVsipMessageType_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorResponse_StatusCode,
{ "StatusCode", "vsip.ErrorResponse.StatusCode", FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&EVsipErrorCode_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_ValueType,
{ "ValueType", "vsip.ErrorVAResponse_AddArgsArray.ValueType", FT_UINT8, BASE_DEC,
VALS(EVsipValueType_vals), 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_CharValue,
{ "CharValue", "vsip.ErrorVAResponse_AddArgsArray.CharValue", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_ShortValue,
{ "ShortValue", "vsip.ErrorVAResponse_AddArgsArray.ShortValue", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_IntValue,
{ "IntValue", "vsip.ErrorVAResponse_AddArgsArray.IntValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_StringValue,
{ "StringValue", "vsip.ErrorVAResponse_AddArgsArray.StringValue", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_UintValue,
{ "UintValue", "vsip.ErrorVAResponse_AddArgsArray.UintValue", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_GuidValue,
{ "GuidValue", "vsip.ErrorVAResponse_AddArgsArray.GuidValue", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_FloatValue,
{ "FloatValue", "vsip.ErrorVAResponse_AddArgsArray.FloatValue", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_AddArgsArray_Value_BinaryValue,
{ "BinaryValue", "vsip.ErrorVAResponse_AddArgsArray.BinaryValue", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_ErrorVAResponse_NumAddArgs,
{ "NumAddArgs", "vsip.ErrorVAResponse.NumAddArgs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_Version,
{ "Version", "vsip.Version", FT_UINT16, BASE_CUSTOM,
CF_FUNC(vsip_fmt_revision), 0x0, NULL, HFILL } },
{ &hf_vsip_Type,
{ "Type", "vsip.Type", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&EVsipMessageType_vals_ext, 0x0, NULL, HFILL } },
{ &hf_vsip_TransacId,
{ "TransacId", "vsip.TransacId", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_vsip_PacketSize,
{ "PacketSize", "vsip.PacketSize", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
proto_vsip = proto_register_protocol ( "Video Services over IP", "VSIP", "vsip");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_vsip, hf, array_length(hf));
}
void proto_reg_handoff_vsip(void)
{
dissector_handle_t vsip_handle;
vsip_handle = new_create_dissector_handle(dissect_vsip, proto_vsip);
dissector_add_for_decode_as("udp.port", vsip_handle);
dissector_add_for_decode_as("tcp.port", vsip_handle);
}
