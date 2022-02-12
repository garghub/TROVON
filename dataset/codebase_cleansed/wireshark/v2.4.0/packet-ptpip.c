static
int dissect_ptpIP (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item_ptr;
proto_tree *ptp_tree;
guint16 offset = 0;
guint32 pktType;
if ( tvb_captured_length_remaining(tvb, offset) < 8 )
return (0);
col_set_str(pinfo->cinfo,COL_PROTOCOL, "PTP/IP");
col_set_str(
pinfo->cinfo,
COL_INFO,
"Picture Transfer Protocol");
item_ptr = proto_tree_add_protocol_format(tree, proto_ptpIP, tvb, offset,
-1, "Picture Transfer Protocol");
ptp_tree = proto_item_add_subtree(item_ptr, ett_ptpIP);
proto_tree_add_item(ptp_tree, hf_ptpIP_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
pktType = tvb_get_letohl(tvb, offset);
proto_tree_add_item(ptp_tree, hf_ptpIP_pktType, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
switch (pktType) {
case PTPIP_INIT_COMMAND_REQUEST:
dissect_ptpIP_init_command_request(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_INIT_COMMAND_ACK:
dissect_ptpIP_init_command_ack(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_INIT_EVENT_REQUEST:
dissect_ptpIP_init_event_request(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_INIT_EVENT_ACK:
dissect_ptpIP_init_event_ack(pinfo);
break;
case PTPIP_CMD_REQUEST:
dissect_ptpIP_operation_request(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_CMD_RESPONSE:
dissect_ptpIP_operation_response(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_EVENT:
dissect_ptpIP_event(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_START_DATA_PACKET:
dissect_ptpIP_start_data(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_DATA_PACKET:
dissect_ptpIP_data(tvb, pinfo, ptp_tree, &offset);
break;
case PTPIP_END_DATA_PACKET:
dissect_ptpIP_end_data(tvb, pinfo, ptp_tree, &offset);
break;
default:
break;
}
return (offset);
}
void dissect_ptpIP_init_command_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
*offset += 0;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Init Command Request");
dissect_ptpIP_guid(tvb, pinfo, tree, offset);
dissect_ptpIP_unicode_name(tvb, pinfo, tree, offset);
dissect_ptpIP_protocol_version(tvb, tree, offset);
return;
}
void dissect_ptpIP_init_command_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint32 connectionNumber;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Init Command Ack");
connectionNumber = tvb_get_letohl(tvb, *offset);
proto_tree_add_item(tree, hf_ptpIP_connectionNumber, tvb, *offset, 4,ENC_LITTLE_ENDIAN);
col_append_fstr(
pinfo->cinfo,
COL_INFO,
" Connection #:%u",
connectionNumber);
*offset += 4;
dissect_ptpIP_guid(tvb, pinfo, tree, offset);
dissect_ptpIP_unicode_name(tvb,pinfo, tree, offset);
dissect_ptpIP_protocol_version(tvb, tree, offset);
}
void dissect_ptpIP_init_event_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint32 connectionNumber;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Init Event Request");
connectionNumber = tvb_get_letohl(tvb, *offset);
proto_tree_add_item(tree, hf_ptpIP_connectionNumber, tvb, *offset, 4,ENC_LITTLE_ENDIAN);
col_append_fstr(
pinfo->cinfo,
COL_INFO,
" Connection #:%u",
connectionNumber);
*offset += 4;
}
void dissect_ptpIP_init_event_ack(packet_info *pinfo)
{
col_set_str(
pinfo->cinfo,
COL_INFO,
"Init Event Ack");
}
void dissect_ptpIP_operation_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint16 opcode;
guint16 transactionID_offset = *offset;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Operation Request Packet ");
proto_tree_add_item(tree,hf_ptpIP_dataPhaseInfo, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
opcode = tvb_get_letohs(tvb, *offset);
if (opcode & PTP_OC_EXTENSION_MASK)
{
if (pref_vendor == PTP_VENDOR_UNKNOWN)
{
proto_tree_add_item(tree, hf_ptp_vendor_opCode, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
else
{
value_string_ext* vendor_values = NULL;
switch(pref_vendor)
{
case PTP_VENDOR_EASTMAN_KODAK:
vendor_values = &ptp_opcode_ek_names_ext;
break;
case PTP_VENDOR_CANON:
vendor_values = &ptp_opcode_canon_names_ext;
break;
case PTP_VENDOR_NIKON:
vendor_values = &ptp_opcode_nikon_names_ext;
break;
case PTP_VENDOR_CASIO:
vendor_values = &ptp_opcode_casio_names_ext;
break;
case PTP_VENDOR_MTP:
vendor_values = &ptp_opcode_mtp_names_ext;
break;
case PTP_VENDOR_OLYMPUS:
vendor_values = &ptp_opcode_olympus_names_ext;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
proto_tree_add_uint_format_value(tree, hf_ptp_vendor_opCode, tvb, *offset, 2, opcode, "%s (0x%04x)",
val_to_str_ext_const(opcode, vendor_values, "Unknown"), opcode);
}
}
else
{
proto_tree_add_item(tree, hf_ptp_opCode, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
*offset += 2;
transactionID_offset = *offset;
*offset += 4;
switch (opcode)
{
case PTP_OC_GetDeviceInfo:
col_set_str(
pinfo->cinfo,
COL_INFO,
"GetDeviceInfo");
break;
case PTP_OC_OpenSession:
dissect_ptp_opCode_openSession(tvb, pinfo, tree, offset);
break;
case PTP_OC_CloseSession:
col_set_str(
pinfo->cinfo,
COL_INFO,
"CloseSession");
break;
case PTP_OC_GetStorageIDs:
col_set_str(
pinfo->cinfo,
COL_INFO,
"GetStorageIDs");
break;
default:
break;
}
dissect_ptp_transactionID(tvb, pinfo, tree, &transactionID_offset);
}
void dissect_ptpIP_operation_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint16 resp;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Operation Response Packet ");
resp = tvb_get_letohs(tvb, *offset);
if (resp & PTP_OC_EXTENSION_MASK)
{
const value_string* vendor_values = NULL;
switch(pref_vendor)
{
case PTP_VENDOR_EASTMAN_KODAK:
vendor_values = ptp_respcode_ek_names;
break;
case PTP_VENDOR_CANON:
vendor_values = ptp_respcode_canon_names;
break;
case PTP_VENDOR_NIKON:
vendor_values = ptp_respcode_nikon_names;
break;
case PTP_VENDOR_MTP:
vendor_values = ptp_respcode_mtp_names;
break;
case PTP_VENDOR_UNKNOWN:
case PTP_VENDOR_CASIO:
case PTP_VENDOR_OLYMPUS:
default:
vendor_values = ptp_respcode_names;
break;
}
proto_tree_add_uint_format_value(tree, hf_ptp_vendor_opCode, tvb, *offset, 2, resp, "%s (0x%04x)",
val_to_str_const(resp, vendor_values, "Unknown"), resp);
}
else
{
proto_tree_add_item(tree, hf_ptp_respCode, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
}
*offset += 2;
dissect_ptp_transactionID(tvb, pinfo, tree, offset);
}
void dissect_ptpIP_event(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
col_set_str(
pinfo->cinfo,
COL_INFO,
"Event Packet ");
proto_tree_add_item(tree, hf_ptp_eventCode, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
dissect_ptp_transactionID(tvb, pinfo, tree, offset);
}
void dissect_ptpIP_start_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint64 dataLen;
col_set_str(
pinfo->cinfo,
COL_INFO,
"Start Data Packet ");
dissect_ptp_transactionID(tvb, pinfo, tree, offset);
dataLen = tvb_get_letoh64(tvb, *offset);
proto_tree_add_item(tree, hf_ptp_totalDataLength, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
if (dataLen == G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFFFF))
{
col_append_str(
pinfo->cinfo,
COL_INFO,
" Data Length Unknown");
}
}
void dissect_ptpIP_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
col_set_str(
pinfo->cinfo,
COL_INFO,
"Data Packet ");
dissect_ptp_transactionID(tvb, pinfo, tree, offset);
}
void dissect_ptpIP_end_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
col_set_str(
pinfo->cinfo,
COL_INFO,
"End Data Packet ");
dissect_ptp_transactionID(tvb, pinfo, tree, offset);
}
void dissect_ptp_opCode_openSession(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
col_set_str(
pinfo->cinfo,
COL_INFO,
"OpenSession");
proto_tree_add_item(tree, hf_ptp_opCode_param_sessionID, tvb, *offset, 4 , ENC_LITTLE_ENDIAN);
*offset += 4;
}
void dissect_ptp_transactionID(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint32 transactionID;
transactionID = tvb_get_letohl(tvb, *offset);
proto_tree_add_item(tree, hf_ptp_transactionID, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
col_append_fstr(
pinfo->cinfo,
COL_INFO,
" Transaction ID: %d",
transactionID);
}
void dissect_ptpIP_unicode_name(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
const guint8 *name;
gint nameLen;
nameLen = tvb_unicode_strsize(tvb, *offset);
proto_tree_add_item_ret_string(tree, hf_ptpIP_name, tvb, *offset, nameLen, ENC_UTF_16|ENC_LITTLE_ENDIAN, wmem_packet_scope(), &name);
*offset += nameLen;
col_append_fstr(pinfo->cinfo, COL_INFO, " Name: %s", name);
}
void dissect_ptpIP_protocol_version(tvbuff_t *tvb, proto_tree *tree, guint16 *offset)
{
guint8 version[30];
guint32 protoVersion;
guint16 majorVersion, minorVersion;
protoVersion = tvb_get_letohl(tvb, *offset);
minorVersion = protoVersion & 0xFFFF;
majorVersion = (protoVersion & 0xFFFF0000) >>16;
g_snprintf(version, sizeof(version), "%u.%u", majorVersion, minorVersion);
proto_tree_add_string(tree, hf_ptpIP_version, tvb, *offset, 4, version);
*offset += 4;
}
void dissect_ptpIP_guid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 *offset)
{
guint8 *guid;
guid = tvb_bytes_to_str(wmem_packet_scope(), tvb, *offset, PTPIP_GUID_SIZE);
proto_tree_add_item(tree, hf_ptpIP_guid, tvb, *offset, PTPIP_GUID_SIZE, ENC_NA);
*offset += PTPIP_GUID_SIZE;
col_append_fstr(
pinfo->cinfo,
COL_INFO,
" GUID: %s",
guid);
}
void proto_register_ptpip( void )
{
static hf_register_info hf[] = {
{ &hf_ptpIP_len, {
"Length", "ptpip.len", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ptpIP_pktType, {
"Packet Type", "ptpip.pktType", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&ptpip_pktType_names_ext, 0, NULL, HFILL }},
{ &hf_ptpIP_guid, {
"GUID", "ptpip.guid", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ptpIP_name, {
"Host Name", "ptpip.name", FT_STRINGZ, STR_UNICODE,
NULL, 0, NULL, HFILL }},
{ &hf_ptpIP_version, {
"Version", "ptpip.version", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ptpIP_connectionNumber, {
"Connection Number", "ptpip.connection", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ptpIP_dataPhaseInfo, {
"Data Phase Info", "ptpip.phaseinfo", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_opCode, {
"Operation Code", "ptpip.opcode", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&ptp_opcode_names_ext, 0, NULL, HFILL }},
{ &hf_ptp_vendor_opCode, {
"Operation Code", "ptpip.opcode", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_respCode, {
"Response Code", "ptpip.respcode", FT_UINT16, BASE_HEX,
VALS(ptp_respcode_names), 0, NULL, HFILL }},
{ &hf_ptp_vendor_respCode, {
"Response Code", "ptpip.respcode", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_eventCode, {
"Event Code", "ptpip.eventcode", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_transactionID, {
"Transaction ID", "ptpip.transactionID", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_totalDataLength, {
"Total Data Length", "ptpip.datalen", FT_UINT64, BASE_DEC_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ptp_opCode_param_sessionID, {
"Session ID", "ptpip.opcode.param.sessionid", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ptpIP,
&ett_ptpIP_hdr
};
module_t *ptpIP_module;
proto_ptpIP = proto_register_protocol("Picture Transfer Protocol Over IP", "PTP/IP", "ptpip");
proto_register_field_array(proto_ptpIP, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ptpIP_module = prefs_register_protocol(proto_ptpIP, NULL);
prefs_register_enum_preference(ptpIP_module, "vendor",
"Camera vendor",
"Properly translates vendor specific opcodes",
&pref_vendor, pref_hsp_role, FALSE);
}
void proto_reg_handoff_ptpIP( void ) {
dissector_handle_t ptpIP_handle;
ptpIP_handle = create_dissector_handle(dissect_ptpIP, proto_ptpIP);
dissector_add_uint_with_preference("tcp.port", PTPIP_PORT, ptpIP_handle);
}
