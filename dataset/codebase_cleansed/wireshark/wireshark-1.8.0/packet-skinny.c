static guint
get_skinny_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 hdr_data_length;
hdr_data_length = tvb_get_letohl(tvb, offset);
return hdr_data_length + 8;
}
static void
dissect_skinny_xml(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, const gint start, gint length)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
tvbuff_t *next_tvb;
dissector_handle_t handle;
item = proto_tree_add_item(tree, hf_skinny_xmlData, tvb, start, length, ENC_ASCII|ENC_NA);
subtree = proto_item_add_subtree(item, 0);
next_tvb = tvb_new_subset(tvb, start, length, -1);
handle = dissector_get_string_handle(media_type_dissector_table, "text/xml");
if (handle != NULL) {
call_dissector(handle, next_tvb, pinfo, subtree);
}
}
static void
dissect_skinny_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
gboolean is_video = FALSE;
guint32 hdr_data_length;
guint32 hdr_version;
guint32 data_messageid;
guint i = 0;
guint t = 0;
int j = 0;
guint count;
int val;
guint32 ipversion;
guint32 capCount;
guint32 softKeyCount;
guint32 softKeySetCount;
guint16 validKeyMask;
proto_item *ti;
proto_tree *skinny_tree = NULL;
proto_item *ti_sub;
proto_tree *skinny_sub_tree;
proto_tree *skinny_sub_tree_sav;
proto_tree *skinny_sub_tree_sav_sav;
proto_item *skm = NULL;
proto_item *skm_tree = NULL;
hdr_data_length = tvb_get_letohl(tvb, offset);
hdr_version = tvb_get_letohl(tvb, offset+4);
data_messageid = tvb_get_letohl(tvb, offset+8);
pi_current++;
if (pi_current == MAX_SKINNY_MESSAGES_IN_PACKET)
{
pi_current = 0;
}
si = &pi_arr[pi_current];
si->messId = data_messageid;
si->messageName = val_to_str_ext(data_messageid, &message_id_ext, "0x%08X (Unknown)");
si->callId = 0;
si->lineId = 0;
si->passThruId = 0;
si->callState = 0;
g_free(si->callingParty);
si->callingParty = NULL;
g_free(si->calledParty);
si->calledParty = NULL;
if (tree) {
ti = proto_tree_add_item(tree, proto_skinny, tvb, offset, hdr_data_length+8, ENC_NA);
skinny_tree = proto_item_add_subtree(ti, ett_skinny);
proto_tree_add_uint(skinny_tree, hf_skinny_data_length, tvb, offset, 4, hdr_data_length);
proto_tree_add_uint(skinny_tree, hf_skinny_hdr_version, tvb, offset+4, 4, hdr_version);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,"%s ", si->messageName);
col_set_fence(pinfo->cinfo, COL_INFO);
}
if (tree) {
proto_tree_add_uint(skinny_tree, hf_skinny_messageid, tvb,offset+8, 4, data_messageid );
}
{
switch(data_messageid) {
case 0x0000:
break;
case 0x0001:
proto_tree_add_item(skinny_tree, hf_skinny_deviceName, tvb, offset+12, StationMaxDeviceNameSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_stationUserId, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_stationInstance, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+36, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_deviceType, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxStreams, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0002:
proto_tree_add_item(skinny_tree, hf_skinny_stationIpPort, tvb, offset+12, 2, ENC_BIG_ENDIAN);
break;
case 0x0003:
proto_tree_add_item(skinny_tree, hf_skinny_stationKeypadButton, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 8) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
}
break;
case 0x0004:
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, offset+12, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
break;
case 0x0005:
proto_tree_add_item(skinny_tree, hf_skinny_stimulus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_stimulusInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 12) {
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, offset+20);
}
break;
case 0x0006:
if (hdr_data_length > 4) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
}
break;
case 0x0007:
if (hdr_data_length > 4) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
}
break;
case 0x0008:
break;
case 0x0009:
proto_tree_add_item(skinny_tree, hf_skinny_lineNumber, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x000a:
proto_tree_add_item(skinny_tree, hf_skinny_speedDialNumber, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x000b:
proto_tree_add_item(skinny_tree, hf_skinny_lineNumber, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x000c:
break;
case 0x000d:
break;
case 0x000e:
break;
case 0x000f:
break;
case 0x0010:
capCount = tvb_get_letohl(tvb, offset+12);
proto_tree_add_uint(skinny_tree, hf_skinny_capCount, tvb, offset+12, 4, capCount);
for (i = 0; i < capCount; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+(i*16)+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxFramesPerPacket, tvb, offset+(i*16)+20, 2, ENC_LITTLE_ENDIAN);
}
break;
case 0x0011:
break;
case 0x0012:
break;
case 0x0020:
proto_tree_add_item(skinny_tree, hf_skinny_alarmSeverity, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayMessage, tvb, offset+16, StationMaxAlarmMessageSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_alarmParam1, tvb, offset+96, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_alarmParam2, tvb, offset+100, 4, ENC_BIG_ENDIAN);
break;
case 0x0021:
proto_tree_add_item(skinny_tree, hf_skinny_receptionStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0022:
if (hdr_version == BASIC_MSG_TYPE) {
proto_tree_add_item(skinny_tree, hf_skinny_ORCStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_portNumber, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
if (rtp_handle) {
address src_addr;
guint32 ipv4_address;
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (guint8 *)&ipv4_address;
ipv4_address = tvb_get_ipv4(tvb, offset+16);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset+20), 0, "Skinny", pinfo->fd->num, is_video, NULL);
}
si->passThruId = tvb_get_letohl(tvb, offset+24);
} else if (hdr_version == CM7_MSG_TYPE_A || hdr_version == CM7_MSG_TYPE_B || hdr_version == CM7_MSG_TYPE_C) {
proto_tree_add_item(skinny_tree, hf_skinny_ORCStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
ipversion = tvb_get_ntohl(tvb, offset+16);
proto_tree_add_item(skinny_tree, hf_skinny_IPVersion, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
if (ipversion == 0) {
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+20, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(skinny_tree, hf_skinny_ipV6Address, tvb, offset+20, 16, ENC_NA);
}
proto_tree_add_item(skinny_tree, hf_skinny_portNumber, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
if (rtp_handle) {
address src_addr;
guint32 ipv4_address;
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (guint8 *)&ipv4_address;
ipv4_address = tvb_get_ipv4(tvb, offset+20);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset+36), 0, "Skinny", pinfo->fd->num, is_video, NULL);
}
si->passThruId = tvb_get_letohl(tvb, offset+40);
}
break;
case 0x0023:
proto_tree_add_item(skinny_tree, hf_skinny_directoryNumber, tvb, offset+12, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_statsProcessingType, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_packetsSent, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_octetsSent, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_packetsRecv, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_octetsRecv, tvb, offset+56, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_packetsLost, tvb, offset+60, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_jitter, tvb, offset+64, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_latency, tvb, offset+68, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, offset+36);
break;
case 0x0024:
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, offset+12,StationMaxDirnumSize, ENC_ASCII|ENC_NA);
break;
case 0x0025:
break;
case 0x0026:
proto_tree_add_item(skinny_tree, hf_skinny_softKeyEvent, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0027:
break;
case 0x0028:
break;
case 0x0029:
proto_tree_add_item(skinny_tree, hf_skinny_deviceName, tvb, offset+12, 4, ENC_ASCII|ENC_NA);
i = offset+12+StationMaxDeviceNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_stationUserId, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_stationInstance, tvb, i+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, i+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_deviceType, tvb, i+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x002A:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_portNumber, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+28);
break;
case 0x002B:
proto_tree_add_item(skinny_tree, hf_skinny_headsetMode, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x002C:
proto_tree_add_item(skinny_tree, hf_skinny_deviceType, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfInServiceStreams, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxStreamsPerConf, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfOutOfServiceStreams, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
break;
case 0x002D:
proto_tree_add_item(skinny_tree, hf_skinny_numberLines, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x002E:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+30, count);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x002F:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+30, count);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0030:
proto_tree_add_item(skinny_tree, hf_skinny_audioCapCount, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_videoCapCount, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dataCapCount, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_RTPPayloadFormat, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_customPictureFormatCount, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = offset+32;
for ( i = 0; i < MAX_CUSTOM_PICTURES; i++ ) {
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 20, "customPictureFormat[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureWidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureHeight, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_pixelAspectRatio, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_clockConversionCode, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_clockDivisor, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "confResources");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_activeStreamsOnRegistration, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxBW, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_serviceResourceCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
skinny_sub_tree_sav = skinny_sub_tree;
for ( i = 0; i < MAX_SERVICE_TYPE; i++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 20, "serviceResource[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_layoutCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
skinny_sub_tree_sav_sav = skinny_sub_tree_sav;
for ( t = 0; t < MAX_LAYOUT_WITH_SAME_SERVICE; t++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 20, "layouts[%d]", t);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_layout, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
skinny_sub_tree = skinny_sub_tree_sav_sav;
proto_tree_add_item(skinny_sub_tree, hf_skinny_serviceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxStreams, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxConferences, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_activeConferenceOnRegistration, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
for ( i = 0; i < StationMaxCapabilities; i++ ) {
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 20, "audiocaps[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_payloadCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxFramesPerPacket, tvb, count, 2, ENC_LITTLE_ENDIAN);
count+= 4;
count+= 8;
}
for ( i = 0; i < StationMaxVideoCapabilities; i++ ) {
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 20, "vidCaps[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_payloadCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_transmitOrReceive, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_levelPreferenceCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
skinny_sub_tree_sav = skinny_sub_tree;
for ( t = 0; t < MAX_LEVEL_PREFERENCE; t++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 20, "levelPreference[%d]", t);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_transmitPreference, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_minBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_serviceNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
val = count;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h261VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_stillImageTransmission, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h263VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_annexNandWFutureUse, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "vieoVideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
for ( i = 0; i < StationMaxDataCapabilities; i++ ) {
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 20, "dataCaps[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_payloadCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_transmitOrReceive, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_protocolDependentData, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
break;
case 0x0031:
proto_tree_add_item(skinny_tree, hf_skinny_ORCStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_portNumber, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+24);
si->callId = tvb_get_letohl(tvb, offset+28);
break;
case 0x0032:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_serviceNum, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0033:
proto_tree_add_item(skinny_tree, hf_skinny_serviceURLIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0034:
proto_tree_add_item(skinny_tree, hf_skinny_featureIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0035:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_createConfResults, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+20);
proto_tree_add_uint(skinny_tree, hf_skinny_passThruData, tvb, offset+24, 1, count);
break;
case 0x0036:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_deleteConfResults, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0037:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_modifyConfResults, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+20);
proto_tree_add_uint(skinny_tree, hf_skinny_passThruData, tvb, offset+24, 1, count);
break;
case 0x0038:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_addParticipantResults, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0039:
proto_tree_add_item(skinny_tree, hf_skinny_last, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfEntries, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
count = offset+20;
for ( i = 0; i < StationMaxConference; i++ ) {
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_resourceTypes, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_numberOfReservedParticipants, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_numberOfActiveParticipants, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_appID, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_uint(skinny_tree, hf_skinny_appConfID, tvb, count, 1, AppConferenceIDSize);
count += AppConferenceIDSize;
proto_tree_add_uint(skinny_tree, hf_skinny_appData, tvb, count, 1, AppDataSize);
count += AppDataSize;
}
break;
case 0x0040:
proto_tree_add_item(skinny_tree, hf_skinny_auditParticipantResults, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_last, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfEntries, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+24);
for ( i = 0; i < count; i++ ) {
proto_tree_add_item(skinny_tree, hf_skinny_participantEntry, tvb, offset+28+(i*4), 4, ENC_LITTLE_ENDIAN);
}
break;
case 0x0041:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
proto_tree_add_item(skinny_tree, hf_skinny_sequenceFlag, tvb, offset+30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayPriority, tvb, offset+34, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+38, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_appInstanceID, tvb, offset+42, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_routingID, tvb, offset+46, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+50, count);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0042:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
proto_tree_add_item(skinny_tree, hf_skinny_sequenceFlag, tvb, offset+30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayPriority, tvb, offset+34, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+38, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_appInstanceID, tvb, offset+42, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_routingID, tvb, offset+46, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+50, count);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0048:
proto_tree_add_item(skinny_tree, hf_skinny_directoryIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_unknown, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_directoryPhoneNumber, tvb, offset+24, 256, ENC_ASCII|ENC_NA);
break;
case 0x0081:
proto_tree_add_item(skinny_tree, hf_skinny_keepAliveInterval, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateTemplate, tvb, offset+16, StationDateTemplateSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_secondaryKeepAliveInterval, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0082:
proto_tree_add_item(skinny_tree, hf_skinny_deviceTone, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 12) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+20);
si->callId = tvb_get_letohl(tvb, offset+24);
}
break;
case 0x0083:
if (hdr_data_length > 4) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
}
break;
case 0x0085:
proto_tree_add_item(skinny_tree, hf_skinny_ringType, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ringMode, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 12) {
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+20);
si->callId = tvb_get_letohl(tvb, offset+24);
}
break;
case 0x0086:
proto_tree_add_item(skinny_tree, hf_skinny_stimulus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_stimulusInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lampMode, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0087:
proto_tree_add_item(skinny_tree, hf_skinny_hookFlashDetectMode, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_detectInterval, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0088:
proto_tree_add_item(skinny_tree, hf_skinny_speakerMode, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0089:
proto_tree_add_item(skinny_tree, hf_skinny_microphoneMode, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x008a:
if (hdr_version == BASIC_MSG_TYPE) {
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_remoteIpAddr, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_remotePortNumber, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_precedenceValue, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_silenceSuppression, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxFramesPerPacket, tvb, offset+44, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_g723BitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
if (rtp_handle) {
address src_addr;
guint32 ipv4_address;
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (char *)&ipv4_address;
ipv4_address = tvb_get_ipv4(tvb, offset+20);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset+24), 0, "Skinny", pinfo->fd->num, is_video, NULL);
}
si->passThruId = tvb_get_letohl(tvb, offset+16);
}
else if (hdr_version == CM7_MSG_TYPE_A || hdr_version == CM7_MSG_TYPE_B || hdr_version == CM7_MSG_TYPE_C)
{
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
ipversion = tvb_get_ntohl(tvb, offset+20);
proto_tree_add_item(skinny_tree, hf_skinny_IPVersion, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
if (ipversion ==0) {
proto_tree_add_item(skinny_tree, hf_skinny_remoteIpAddr, tvb, offset+24, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(skinny_tree, hf_skinny_ipV6Address, tvb, offset+24, 16, ENC_NA);
}
proto_tree_add_item(skinny_tree, hf_skinny_remotePortNumber, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
if (rtp_handle) {
address src_addr;
guint32 ipv4_address;
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (char *)&ipv4_address;
ipv4_address = tvb_get_ipv4(tvb, offset+24);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset+40), 0, "Skinny", pinfo->fd->num, is_video, NULL);
}
si->passThruId = tvb_get_letohl(tvb, offset+16);
}
break;
case 0x008b:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x008c:
break;
case 0x008d:
break;
case 0x008f:
i = offset+12;
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyNumber, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
si->callingParty = g_strdup(tvb_format_stringzpad(tvb, i, StationMaxDirnumSize));
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
si->calledParty = g_strdup(tvb_format_stringzpad(tvb, i, StationMaxDirnumSize));
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, i, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, i);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, i, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, i);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_callType, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_originalCdpnRedirectReason, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingReason, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_cast_cgpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_cdpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_originalCdpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_cast_callInstance, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_cast_callSecurityStatus, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
val = tvb_get_letohl( tvb, i);
ti_sub = proto_tree_add_text(skinny_tree, tvb, i, 8, "partyPIRestrictionBits");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x01, 4*8, "Does RestrictCallingPartyName", "Doesn't RestrictCallingPartyName"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x02, 4*8, "Does RestrictCallingPartyNumber", "Doesn't RestrictCallingPartyNumber"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x04, 4*8, "Does RestrictCalledPartyName", "Doesn't RestrictCalledPartyName"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x08, 4*8, "Does RestrictCalledPartyNumber", "Doesn't RestrictCalledPartyNumber"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x10, 4*8, "Does RestrictOriginalCalledPartyName", "Doesn't RestrictOriginalCalledPartyName"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x20, 4*8, "Does RestrictOriginalCalledPartyNumber", "Doesn't RestrictOriginalCalledPartyNumber"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x40, 4*8, "Does RestrictLastRedirectPartyName", "Doesn't RestrictLastRedirectPartyName"));
proto_tree_add_text(skinny_sub_tree, tvb, i, 4, "%s",
decode_boolean_bitfield( val, 0x80, 4*8, "Does RestrictLastRedirectPartyNumber", "Doesn't RestrictLastRedirectPartyNumber"));
break;
case 0x0090:
proto_tree_add_item(skinny_tree, hf_skinny_activeForward, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineNumber, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_forwardAllActive, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_forwardNumber, tvb, offset+24, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i = offset+24+StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_forwardBusyActive, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_forwardNumber, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_forwardNoAnswerActive, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_forwardNumber, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
break;
case 0x0091:
proto_tree_add_item(skinny_tree, hf_skinny_speedDialNumber, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_speedDialDirNumber, tvb, offset+16, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_speedDialDisplayName, tvb, offset+40, StationMaxNameSize, ENC_ASCII|ENC_NA);
break;
case 0x0092:
proto_tree_add_item(skinny_tree, hf_skinny_lineNumber, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineDirNumber, tvb, offset+16, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_lineFullyQualifiedDisplayName, tvb, offset+16+StationMaxDirnumSize, StationMaxNameSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_lineDisplayName, tvb, offset+16+StationMaxDirnumSize+StationMaxNameSize, StationMaxDisplayNameSize, ENC_ASCII|ENC_NA);
break;
case 0x0093:
proto_tree_add_item(skinny_tree, hf_skinny_deviceName, tvb, offset+12, StationMaxDeviceNameSize, ENC_ASCII|ENC_NA);
i = offset+12+StationMaxDeviceNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_stationUserId, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_stationInstance, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(skinny_tree, hf_skinny_userName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_serverName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(skinny_tree, hf_skinny_numberLines, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberSpeedDials, tvb, i+4, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0094:
proto_tree_add_item(skinny_tree, hf_skinny_dateYear, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateMonth, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dayOfWeek, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateDay, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateHour, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateMinute, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateSeconds,tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_dateMilliseconds,tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_timeStamp, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0095:
proto_tree_add_item(skinny_tree, hf_skinny_remoteIpAddr, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_sessionType, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0096:
proto_tree_add_item(skinny_tree, hf_skinny_remoteIpAddr, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_sessionType, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0097:
proto_tree_add_item(skinny_tree, hf_skinny_buttonOffset, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_buttonCount, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_totalButtonCount, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
for (i = 0; i < StationMaxButtonTemplateSize; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_buttonInstanceNumber, tvb, offset+(i*2)+24, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_buttonDefinition, tvb, offset+(i*2)+25, 1, ENC_LITTLE_ENDIAN);
}
break;
case 0x0098:
proto_tree_add_item(skinny_tree, hf_skinny_version, tvb, offset+12, StationMaxVersionSize, ENC_ASCII|ENC_NA);
break;
case 0x0099:
proto_tree_add_item(skinny_tree, hf_skinny_displayMessage, tvb, offset+12, StationMaxDisplayTextSize, ENC_ASCII|ENC_NA);
break;
case 0x009a:
break;
case 0x009b:
break;
case 0x009c:
proto_tree_add_item(skinny_tree, hf_skinny_mediaEnunciationType, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
for (i = 0; i < StationMaxDirnumSize; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_unknown, tvb, offset+16+(i*4), 4, ENC_LITTLE_ENDIAN);
}
i = offset+16+StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_mediaEnunciationType, tvb, i, 4, ENC_LITTLE_ENDIAN);
break;
case 0x009d:
proto_tree_add_item(skinny_tree, hf_skinny_displayMessage, tvb, offset+12, StationMaxDisplayTextSize, ENC_ASCII|ENC_NA);
break;
case 0x009e:
for (i = 0; i < StationMaxServers; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_serverIdentifier,
tvb, offset+12+(i*StationMaxServers), StationMaxServerNameSize, ENC_ASCII|ENC_NA);
}
j = offset+12+(i*StationMaxServers);
for (i = 0; i < StationMaxServers; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_serverListenPort, tvb, j+(i*4), 4, ENC_LITTLE_ENDIAN);
}
j = j+(i*4);
for (i = 0; i < StationMaxServers; i++) {
proto_tree_add_item(skinny_tree, hf_skinny_serverIpAddress, tvb, j+(i*4), 4, ENC_BIG_ENDIAN);
}
break;
case 0x009f:
proto_tree_add_item(skinny_tree, hf_skinny_deviceResetType, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0100:
break;
case 0x0101:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_multicastIpAddress, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_multicastPort, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_echoCancelType, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_g723BitRate, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0102:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_multicastIpAddress, tvb, offset+20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_multicastPort, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_precedenceValue, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_silenceSuppression, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxFramesPerPacket, tvb, offset+44, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_g723BitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0103:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0104:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x105:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_echoCancelType, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_g723BitRate, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0106:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0107:
i = 12;
proto_tree_add_item(skinny_tree, hf_skinny_directoryNumber, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i = 12 + StationMaxDirnumSize;
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, i, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, i);
i = i+4;
proto_tree_add_item(skinny_tree, hf_skinny_statsProcessingType, tvb, i, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0108:
proto_tree_add_item(skinny_tree, hf_skinny_softKeyOffset, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
softKeyCount = tvb_get_letohl(tvb, offset+16);
proto_tree_add_uint(skinny_tree, hf_skinny_softKeyCount, tvb, offset+16, 4, softKeyCount);
proto_tree_add_item(skinny_tree, hf_skinny_totalSoftKeyCount, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
for (i = 0; ((i < StationMaxSoftKeyDefinition) && (i < softKeyCount)); i++){
proto_tree_add_item(skinny_tree, hf_skinny_softKeyLabel,
tvb, offset+(i*20)+24, StationMaxSoftKeyLabelSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_softKeyEvent, tvb, offset+(i*20)+40, 4, ENC_LITTLE_ENDIAN);
}
break;
case 0x0109:
proto_tree_add_item(skinny_tree, hf_skinny_softKeySetOffset, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
softKeySetCount = tvb_get_letohl(tvb, offset+16);
proto_tree_add_uint(skinny_tree, hf_skinny_softKeySetCount, tvb, offset+16, 4, softKeySetCount);
proto_tree_add_item(skinny_tree, hf_skinny_totalSoftKeySetCount, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
for (i = 0; ((i < StationMaxSoftKeySetDefinition) && (i < softKeySetCount)); i++) {
proto_tree_add_uint(skinny_tree, hf_skinny_softKeySetDescription, tvb, offset+24+(i*48) , 1, i);
for (j = 0; j < StationMaxSoftKeyIndex; j++) {
proto_tree_add_item(skinny_tree, hf_skinny_softKeyTemplateIndex, tvb, offset+24+(i*48)+j, 1, ENC_LITTLE_ENDIAN);
}
for (j = 0; j < StationMaxSoftKeyIndex; j++) {
proto_tree_add_item(skinny_tree, hf_skinny_softKeyInfoIndex,
tvb, offset+24+(i*48)+StationMaxSoftKeyIndex+(j*2), 2, ENC_LITTLE_ENDIAN);
}
}
break;
case 0x0110:
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_softKeySetDescription, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
validKeyMask = tvb_get_letohs(tvb, offset + 24);
skm = proto_tree_add_uint(skinny_tree, hf_skinny_softKeyMap, tvb, offset + 24, 4, validKeyMask);
skm_tree = proto_item_add_subtree(skm, ett_skinny_softKeyMap);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey0, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey1, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey2, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey3, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey4, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey5, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey6, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey7, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey8, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey9, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey10, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey11, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey12, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey13, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey14, tvb, offset + 24, 4, validKeyMask);
proto_tree_add_boolean(skm_tree, hf_skinny_softKey15, tvb, offset + 24, 4, validKeyMask);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0111:
proto_tree_add_item(skinny_tree, hf_skinny_callState, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
si->callState = tvb_get_letohl(tvb, offset+12);
break;
case 0x0112:
proto_tree_add_item(skinny_tree, hf_skinny_messageTimeOutValue, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayMessage, tvb, offset+16, StationMaxDisplayPromptStatusSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+48);
si->callId = tvb_get_letohl(tvb, offset+52);
break;
case 0x0113:
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance , tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x0114:
proto_tree_add_item(skinny_tree, hf_skinny_messageTimeOutValue, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayMessage, tvb, offset+16, StationMaxDisplayNotifySize , ENC_ASCII|ENC_NA);
break;
case 0x0115:
break;
case 0x0116:
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
break;
case 0x0117:
break;
case 0x0118:
proto_tree_add_item(skinny_tree, hf_skinny_deviceUnregisterStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0119:
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x011a:
break;
case 0x011B:
proto_tree_add_item(skinny_tree, hf_skinny_tokenRejWaitTime, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x011C:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_millisecondPacketSize, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_echoCancelType, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_g723BitRate, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+34, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+34);
break;
case 0x011D:
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, offset+12, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12+StationMaxDirnumSize, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+12+StationMaxDirnumSize+4, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12+StationMaxDirnumSize);
si->callId = tvb_get_letohl(tvb, offset+16+StationMaxDirnumSize);
break;
case 0x011E:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+30, count);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x011F:
proto_tree_add_item(skinny_tree, hf_skinny_featureIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_featureID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_featureTextLabel, tvb, offset+20, StationMaxNameSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_featureStatus, tvb, offset+20+StationMaxNameSize, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0120:
proto_tree_add_item(skinny_tree, hf_skinny_messageTimeOutValue, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_priority, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_notify, tvb, offset+16, StationMaxDisplayNotifySize, ENC_ASCII|ENC_NA);
break;
case 0x0121:
proto_tree_add_item(skinny_tree, hf_skinny_priority, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0122:
count = offset+12;
for ( i = 0; i < MaxAnnouncementList; i++ ) {
proto_tree_add_item(skinny_tree, hf_skinny_locale, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_country, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_deviceTone, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
proto_tree_add_item(skinny_tree, hf_skinny_endOfAnnAck, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
for ( i = 0; i < StationMaxMonitorParties; i++ ) {
proto_tree_add_item(skinny_tree, hf_skinny_matrixConfPartyID, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
proto_tree_add_item(skinny_tree, hf_skinny_hearingConfPartyMask, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_tree, hf_skinny_annPlayMode, tvb, count, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0123:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0124:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_annPlayStatus, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0127:
proto_tree_add_item(skinny_tree, hf_skinny_deviceTone, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0128:
proto_tree_add_item(skinny_tree, hf_skinny_deviceTone, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0129:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012A:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012B:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012C:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012D:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012E:
proto_tree_add_item(skinny_tree, hf_skinny_payloadDtmf, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+20);
break;
case 0x012F:
proto_tree_add_item(skinny_tree, hf_skinny_serviceURLIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_serviceURL, tvb, offset+16, StationMaxServiceURLSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(skinny_tree, hf_skinny_serviceURLDisplayName, tvb, offset+16+StationMaxServiceURLSize, StationMaxNameSize, ENC_ASCII|ENC_NA);
break;
case 0x0130:
proto_tree_add_item(skinny_tree, hf_skinny_callSelectStat, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0131:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payload_rfc_number, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadType, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_isConferenceCreator, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->lineId = tvb_get_letohl(tvb, offset+24);
si->callId = tvb_get_letohl(tvb, offset+28);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 12, "audioParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_millisecondPacketSize, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_echoCancelType, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_g723BitRate, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 30, "vidParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_bitRate, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureFormatCount, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
skinny_sub_tree_sav = skinny_sub_tree;
count = offset+52;
for ( i = 0; i < MAX_PICTURE_FORMAT; i++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8 * MAX_PICTURE_FORMAT, "pictureFormat[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
skinny_sub_tree = skinny_sub_tree_sav;
proto_tree_add_item(skinny_sub_tree, hf_skinny_confServiceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
val = count;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h261VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_stillImageTransmission, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h263VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_annexNandWFutureUse, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "vieoVideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "dataParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_protocolDependentData, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxBitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0132:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadCapability, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_ipAddress, tvb, offset+24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_portNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payload_rfc_number, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_payloadType, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_DSCPValue, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+32);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 12, "audioParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_millisecondPacketSize, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_echoCancelType, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_g723BitRate, tvb, offset+56, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 30, "vidParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_bitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureFormatCount, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
skinny_sub_tree_sav = skinny_sub_tree;
count = offset+56;
for ( i = 0; i < MAX_PICTURE_FORMAT; i++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8 * MAX_PICTURE_FORMAT, "pictureFormat[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
skinny_sub_tree = skinny_sub_tree_sav;
proto_tree_add_item(skinny_sub_tree, hf_skinny_confServiceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
val = count;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h261VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_stillImageTransmission, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "h263VideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_annexNandWFutureUse, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "vieoVideoCapability");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(skinny_sub_tree, hf_skinny_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "dataParameters");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_protocolDependentData, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_maxBitRate, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0133:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0134:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_miscCommandType, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "videoFastUpdateGOB");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_firstGOB, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_numberOfGOBs, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "videoFastUpdateGOB");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_firstGOB, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_firstMB, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_numberOfMBs, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "lostPicture");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_longTermPictureIndex, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "lostPartialPicture");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_longTermPictureIndex, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_firstMB, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_numberOfMBs, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 8, "recoveryReferencePicture");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_recoveryReferencePictureCount, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
skinny_sub_tree_sav = skinny_sub_tree;
for ( i = 0; i < MAX_REFERENCE_PICTURE; i++ ) {
ti_sub = proto_tree_add_text(skinny_sub_tree_sav, tvb, offset, 8, "recoveryReferencePicture[%d]", i);
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_pictureNumber, tvb, offset+32+(i*8), 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_sub_tree, hf_skinny_longTermPictureIndex, tvb, offset+36+(i*8), 4, ENC_LITTLE_ENDIAN);
}
ti_sub = proto_tree_add_text(skinny_tree, tvb, offset, 4, "temporalSpatialTradeOff");
skinny_sub_tree = proto_item_add_subtree(ti_sub, ett_skinny_tree);
proto_tree_add_item(skinny_sub_tree, hf_skinny_temporalSpatialTradeOff, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0135:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_maxBitRate, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0136:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->passThruId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x0137:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfReservedParticipants, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_resourceTypes, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_appID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
count = offset+24;
proto_tree_add_uint(skinny_tree, hf_skinny_appConfID, tvb, count, 1, AppConferenceIDSize);
count += AppConferenceIDSize;
proto_tree_add_uint(skinny_tree, hf_skinny_appData, tvb, count, 1, AppDataSize);
count += AppDataSize;
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, count, 4, ENC_LITTLE_ENDIAN);
val = tvb_get_letohl( tvb, count);
count += 4;
proto_tree_add_uint(skinny_tree, hf_skinny_passThruData, tvb, count, 1, val);
break;
case 0x0138:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x0139:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_numberOfReservedParticipants, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_appID, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
count = offset+24;
proto_tree_add_uint(skinny_tree, hf_skinny_appConfID, tvb, count, 1, AppConferenceIDSize);
count += AppConferenceIDSize;
proto_tree_add_uint(skinny_tree, hf_skinny_appData, tvb, count, 1, AppDataSize);
count += AppDataSize;
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, count, 4, ENC_LITTLE_ENDIAN);
val = tvb_get_letohl( tvb, count);
count += 4;
proto_tree_add_uint(skinny_tree, hf_skinny_passThruData, tvb, count, 1, val);
break;
case 0x013A:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x013B:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(tvb, offset+16);
break;
case 0x013C:
break;
case 0x013D:
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x013F:
proto_tree_add_item(skinny_tree, hf_skinny_applicationID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_transactionID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_data_length, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
count = tvb_get_letohl( tvb, offset+28);
proto_tree_add_item(skinny_tree, hf_skinny_sequenceFlag, tvb, offset+30, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_displayPriority, tvb, offset+34, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_conferenceID, tvb, offset+38, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_appInstanceID, tvb, offset+42, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_routingID, tvb, offset+46, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+50, count);
si->lineId = tvb_get_letohl(tvb, offset+16);
si->callId = tvb_get_letohl(tvb, offset+20);
break;
case 0x014A:
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_callType, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(tvb, offset+12);
{
i = offset+44;
if(hdr_version == BASIC_MSG_TYPE)
{
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyNumber, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledParty, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingParty, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_cgpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_cdpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_originalCdpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
}
else if(hdr_version == CM7_MSG_TYPE_B || hdr_version == CM7_MSG_TYPE_A)
{
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyNumber, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_cgpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyNumber, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledParty, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingParty, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_cdpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_originalCdpnVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingVoiceMailbox, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_callingPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_calledPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_skinny_originalCalledPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
i += count;
count = tvb_strnlen(tvb, i, -1)+1;
proto_tree_add_item(skinny_tree, hf_cast_lastRedirectingPartyName, tvb, i, count, ENC_ASCII|ENC_NA);
}
}
break;
case 0x0152:
proto_tree_add_item(skinny_tree, hf_skinny_directoryIndex, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_unknown, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(skinny_tree, hf_skinny_unknown, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
break;
case 0x015A:
dissect_skinny_xml(skinny_tree, tvb, pinfo, offset+12, hdr_data_length-4);
break;
default:
proto_tree_add_item(skinny_tree, hf_skinny_rawData, tvb, offset+12, hdr_data_length-4, ENC_NA);
break;
}
}
tap_queue_packet(skinny_tap, pinfo, si);
}
static gboolean
dissect_skinny(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 hdr_data_length;
guint32 hdr_version;
if (tvb_length_remaining(tvb, 0) < 8)
{
return FALSE;
}
hdr_data_length = tvb_get_letohl(tvb, 0);
hdr_version = tvb_get_letohl(tvb, 4);
if ((hdr_data_length < 4) ||
((hdr_version != BASIC_MSG_TYPE) &&
(hdr_version != CM7_MSG_TYPE_A) &&
(hdr_version != CM7_MSG_TYPE_B) &&
(hdr_version != CM7_MSG_TYPE_C))
)
{
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SKINNY");
col_set_str(pinfo->cinfo, COL_INFO, "Skinny Client Control Protocol");
tcp_dissect_pdus(tvb, pinfo, tree, skinny_desegment, 4,
get_skinny_pdu_len, dissect_skinny_pdu);
return TRUE;
}
void
proto_register_skinny(void)
{
static hf_register_info hf[] = {
{ &hf_skinny_data_length,
{ "Data length", "skinny.data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of bytes in the data portion.",
HFILL }
},
{ &hf_skinny_hdr_version,
{ "Header version", "skinny.hdr_version",
FT_UINT32, BASE_HEX, VALS(header_version), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_messageid,
{ "Message ID", "skinny.messageid",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &message_id_ext, 0x0,
"The function requested/done with this message.",
HFILL }
},
{ &hf_skinny_deviceName,
{ "Device name", "skinny.deviceName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The device name of the phone.",
HFILL }
},
{ &hf_skinny_stationUserId,
{ "Station user ID", "skinny.stationUserId",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_stationInstance,
{ "Station instance", "skinny.stationInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_deviceType,
{ "Device type", "skinny.deviceType",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &deviceTypes_ext, 0x0,
"DeviceType of the station.",
HFILL }
},
{ &hf_skinny_maxStreams,
{ "Max streams", "skinny.maxStreams",
FT_UINT32, BASE_DEC, NULL, 0x0,
"32 bit unsigned integer indicating the maximum number of simultansous RTP duplex streams that the client can handle.",
HFILL }
},
{ &hf_skinny_stationIpPort,
{ "Station ip port", "skinny.stationIpPort",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_stationKeypadButton,
{ "Keypad button", "skinny.stationKeypadButton",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &keypadButtons_ext, 0x0,
"The button pressed on the phone.",
HFILL }
},
{ &hf_skinny_calledPartyNumber,
{ "Called party number", "skinny.calledParty",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number called.",
HFILL }
},
{ &hf_skinny_stimulus,
{ "Stimulus", "skinny.stimulus",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &deviceStimuli_ext, 0x0,
"Reason for the device stimulus message.",
HFILL }
},
{ &hf_skinny_stimulusInstance,
{ "Stimulus instance", "skinny.stimulusInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_lineNumber,
{ "Line number", "skinny.lineNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_speedDialNumber,
{ "Speed-dial number", "skinny.speedDialNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Which speed dial number",
HFILL }
},
{ &hf_skinny_capCount,
{ "Capabilities count", "skinny.capCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"How many capabilities",
HFILL }
},
{ &hf_skinny_payloadCapability,
{ "Payload capability", "skinny.payloadCapability",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &mediaPayloads_ext, 0x0,
"The payload capability for this media capability structure.",
HFILL }
},
{ &hf_skinny_maxFramesPerPacket,
{ "Max frames per packet", "skinny.maxFramesPerPacket",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_alarmSeverity,
{ "Alarm severity", "skinny.alarmSeverity",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &alarmSeverities_ext, 0x0,
"The severity of the reported alarm.",
HFILL }
},
{ &hf_skinny_alarmParam1,
{ "Alarm param 1", "skinny.alarmParam1",
FT_UINT32, BASE_HEX, NULL, 0x0,
"An as yet undecoded param1 value from the alarm message",
HFILL }
},
{ &hf_skinny_alarmParam2,
{ "Alarm param 2", "skinny.alarmParam2",
FT_IPv4, BASE_NONE, NULL, 0x0,
"This is the second alarm parameter i think it's an ip address",
HFILL }
},
{ &hf_skinny_receptionStatus,
{ "Reception status", "skinny.receptionStatus",
FT_UINT32, BASE_DEC, VALS(multicastMediaReceptionStatus), 0x0,
"The current status of the multicast media.",
HFILL }
},
{ &hf_skinny_passThruPartyID,
{ "Pass-thru party ID", "skinny.passThruPartyID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_ORCStatus,
{ "Opened receive-channel status", "skinny.openReceiveChannelStatus",
FT_UINT32, BASE_DEC, VALS(openReceiveChanStatus), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_IPVersion,
{ "IP Version", "skinny.ipversion",
FT_UINT32, BASE_DEC, VALS(ipVersion), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_ipAddress,
{ "IP address", "skinny.ipAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_ipV6Address,
{ "IPv6 address", "skinny.ipv6Address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_portNumber,
{ "Port number", "skinny.portNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_statsProcessingType,
{ "Stats processing type", "skinny.statsProcessingType",
FT_UINT32, BASE_DEC, VALS(statsProcessingTypes), 0x0,
"What do do after you send the stats.",
HFILL }
},
{ &hf_skinny_callIdentifier,
{ "Call identifier", "skinny.callIdentifier",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_packetsSent,
{ "Packets sent", "skinny.packetsSent",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_octetsSent,
{ "Octets sent", "skinny.octetsSent",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_packetsRecv,
{ "Packets Received", "skinny.packetsRecv",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_octetsRecv,
{ "Octets received", "skinny.octetsRecv",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_packetsLost,
{ "Packets lost", "skinny.packetsLost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_latency,
{ "Latency(ms)", "skinny.latency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Average packet latency during the call.",
HFILL }
},
{ &hf_skinny_jitter,
{ "Jitter", "skinny.jitter",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Average jitter during the call.",
HFILL }
},
{ &hf_skinny_directoryNumber,
{ "Directory number", "skinny.directoryNumber",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number we are reporting statistics for.",
HFILL }
},
{ &hf_skinny_lineInstance,
{ "Line instance", "skinny.lineInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The display call plane associated with this call.",
HFILL }
},
{ &hf_skinny_softKeyEvent,
{ "Soft-key event", "skinny.softKeyEvent",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &softKeyEvents_ext, 0x0,
"Which softkey event is being reported.",
HFILL }
},
{ &hf_skinny_keepAliveInterval,
{ "Keep-alive interval", "skinny.keepAliveInterval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"How often are keep alives exchanges between the client and the call manager.",
HFILL }
},
{ &hf_skinny_secondaryKeepAliveInterval,
{ "Secondary keep-alive interval", "skinny.secondaryKeepAliveInterval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"How often are keep alives exchanges between the client and the secondary call manager.",
HFILL }
},
{ &hf_skinny_dateTemplate,
{ "Date template", "skinny.dateTemplate",
FT_STRING, BASE_NONE, NULL, 0x0,
"The display format for the date/time on the phone.",
HFILL }
},
{ &hf_skinny_buttonOffset,
{ "Button offset", "skinny.buttonOffset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Offset is the number of the first button referenced by this message.",
HFILL }
},
{ &hf_skinny_buttonCount,
{ "Buttons count", "skinny.buttonCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of (VALID) button definitions in this message.",
HFILL }
},
{ &hf_skinny_totalButtonCount,
{ "Total buttons count", "skinny.totalButtonCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total number of buttons defined for this phone.",
HFILL }
},
{ &hf_skinny_buttonInstanceNumber,
{ "Instance number", "skinny.buttonInstanceNumber",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keypadButtons_ext, 0x0,
"The button instance number for a button or the StationKeyPad value, repeats allowed.",
HFILL }
},
{ &hf_skinny_buttonDefinition,
{ "Button definition", "skinny.buttonDefinition",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &buttonDefinitions_ext, 0x0,
"The button type for this instance (ie line, speed dial, ....",
HFILL }
},
{ &hf_skinny_softKeyOffset,
{ "Soft-Key offset", "skinny.softKeyOffset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The offset for the first soft key in this message.",
HFILL }
},
{ &hf_skinny_softKeyCount,
{ "Soft-keys count", "skinny.softKeyCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of valid softkeys in this message.",
HFILL }
},
{ &hf_skinny_totalSoftKeyCount,
{ "Total soft-keys count", "skinny.totalSoftKeyCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total number of softkeys for this device.",
HFILL }
},
{ &hf_skinny_softKeyLabel,
{ "Soft-key label", "skinny.softKeyLabel",
FT_STRING, BASE_NONE, NULL, 0x0,
"The text label for this soft key.",
HFILL }
},
{ &hf_skinny_softKeySetOffset,
{ "Soft-key-set offset", "skinny.softKeySetOffset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The offset for the first soft key set in this message.",
HFILL }
},
{ &hf_skinny_softKeySetCount,
{ "Soft-key-sets count", "skinny.softKeySetCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of valid softkey sets in this message.",
HFILL }
},
{ &hf_skinny_totalSoftKeySetCount,
{ "Total soft-key-sets count", "skinny.totalSoftKeySetCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total number of softkey sets for this device.",
HFILL }
},
{ &hf_skinny_softKeyTemplateIndex,
{ "Soft-key template index", "skinny.softKeyTemplateIndex",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &softKeyEvents_ext, 0x0,
"Array of size 16 8-bit unsigned ints containing an index into the softKeyTemplate.",
HFILL }
},
{ &hf_skinny_softKeyInfoIndex,
{ "Soft-key info index", "skinny.softKeyInfoIndex",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &softKeyIndexes_ext, 0x0,
"Array of size 16 16-bit unsigned integers containing an index into the soft key description information.",
HFILL }
},
{ &hf_skinny_softKeySetDescription,
{ "Soft-key set description", "skinny.softKeySetDescription",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &keySetNames_ext, 0x0,
"A text description of what this softkey when this softkey set is displayed",
HFILL }
},
{ &hf_skinny_softKeyMap,
{ "Soft-key map","skinny.softKeyMap",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_softKey0,
{ "SoftKey0", "skinny.softKeyMap.0",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY0,
NULL,
HFILL }
},
{ &hf_skinny_softKey1,
{ "SoftKey1", "skinny.softKeyMap.1",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY1,
NULL,
HFILL }
},
{ &hf_skinny_softKey2,
{ "SoftKey2", "skinny.softKeyMap.2",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY2,
NULL,
HFILL }
},
{ &hf_skinny_softKey3,
{ "SoftKey3", "skinny.softKeyMap.3",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY3,
NULL,
HFILL }
},
{ &hf_skinny_softKey4,
{ "SoftKey4", "skinny.softKeyMap.4",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY4,
NULL,
HFILL }
},
{ &hf_skinny_softKey5,
{ "SoftKey5", "skinny.softKeyMap.5",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY5,
NULL,
HFILL }
},
{ &hf_skinny_softKey6,
{ "SoftKey6", "skinny.softKeyMap.6",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY6,
NULL,
HFILL }
},
{ &hf_skinny_softKey7,
{ "SoftKey7", "skinny.softKeyMap.7",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY7,
NULL,
HFILL }
},
{ &hf_skinny_softKey8,
{ "SoftKey8", "skinny.softKeyMap.8",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY8,
NULL,
HFILL }
},
{ &hf_skinny_softKey9,
{ "SoftKey9", "skinny.softKeyMap.9",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY9,
NULL,
HFILL }
},
{ &hf_skinny_softKey10,
{ "SoftKey10", "skinny.softKeyMap.10",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY10,
NULL,
HFILL }
},
{ &hf_skinny_softKey11,
{ "SoftKey11", "skinny.softKeyMap.11",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY11,
NULL,
HFILL }
},
{ &hf_skinny_softKey12,
{ "SoftKey12", "skinny.softKeyMap.12",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY12,
NULL,
HFILL }
},
{ &hf_skinny_softKey13,
{ "SoftKey13", "skinny.softKeyMap.13",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY13,
NULL,
HFILL }
},
{ &hf_skinny_softKey14,
{ "SoftKey14", "skinny.softKeyMap.14",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY14,
NULL,
HFILL }
},
{ &hf_skinny_softKey15,
{ "SoftKey15", "skinny.softKeyMap.15",
FT_BOOLEAN, 16, TFS(&softKeyMapValues), SKINNY_SOFTKEY15,
NULL,
HFILL }
},
{ &hf_skinny_lampMode,
{ "Lamp mode", "skinny.lampMode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &stationLampModes_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_messageTimeOutValue,
{ "Message time-out", "skinny.messageTimeOutValue",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The timeout in seconds for this message",
HFILL }
},
{ &hf_skinny_displayMessage,
{ "Display message", "skinny.displayMessage",
FT_STRING, BASE_NONE, NULL, 0x0,
"The message displayed on the phone.",
HFILL }
},
{ &hf_skinny_lineDirNumber,
{ "Line directory number", "skinny.lineDirNumber",
FT_STRING, BASE_NONE, NULL, 0x0,
"The directory number for this line.",
HFILL }
},
{ &hf_skinny_lineFullyQualifiedDisplayName,
{ "Fully qualified display name", "skinny.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
"The full display name for this line.",
HFILL }
},
{ &hf_skinny_lineDisplayName,
{ "Display name", "skinny.displayName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The display name for this line.",
HFILL }
},
{ &hf_skinny_speedDialDirNumber,
{ "Speed-dial number", "skinny.speedDialDirNum",
FT_STRING, BASE_NONE, NULL, 0x0,
"the number to dial for this speed dial.",
HFILL }
},
{ &hf_skinny_speedDialDisplayName,
{ "Speed-dial display", "skinny.speedDialDisplay",
FT_STRING, BASE_NONE, NULL, 0x0,
"The text to display for this speed dial.",
HFILL }
},
{ &hf_skinny_dateYear,
{ "Year", "skinny.year",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The current year",
HFILL }
},
{ &hf_skinny_dateMonth,
{ "Month", "skinny.month",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The current month",
HFILL }
},
{ &hf_skinny_dayOfWeek,
{ "Day of week", "skinny.dayOfWeek",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The day of the week",
HFILL }
},
{ &hf_skinny_dateDay,
{ "Day", "skinny.day",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The day of the current month",
HFILL }
},
{ &hf_skinny_dateHour,
{ "Hour", "skinny.hour",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Hour of the day",
HFILL }
},
{ &hf_skinny_dateMinute,
{ "Minute", "skinny.minute",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_dateSeconds,
{ "Seconds", "skinny.dateSeconds",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_dateMilliseconds,
{ "Milliseconds", "skinny.dateMilliseconds",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_timeStamp,
{ "Timestamp", "skinny.timeStamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time stamp for the call reference",
HFILL }
},
{ &hf_skinny_callState,
{ "Call state", "skinny.callState",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_stationCallStates_ext, 0x0,
"The D channel call state of the call",
HFILL }
},
{ &hf_skinny_deviceTone,
{ "Tone", "skinny.deviceTone",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &skinny_deviceTones_ext, 0x0,
"Which tone to play",
HFILL }
},
{ &hf_skinny_callingPartyName,
{ "Calling party name", "skinny.callingPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The passed name of the calling party.",
HFILL }
},
{ &hf_skinny_callingPartyNumber,
{ "Calling party number", "skinny.callingParty",
FT_STRING, BASE_NONE, NULL, 0x0,
"The passed number of the calling party.",
HFILL }
},
{ &hf_skinny_calledPartyName,
{ "Called party name", "skinny.calledPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The name of the party we are calling.",
HFILL }
},
{ &hf_skinny_callType,
{ "Call type", "skinny.callType",
FT_UINT32, BASE_DEC, VALS(skinny_callTypes), 0x0,
"What type of call, in/out/etc",
HFILL }
},
{ &hf_skinny_originalCalledPartyName,
{ "Original called party name", "skinny.originalCalledPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_originalCalledParty,
{ "Original called party number", "skinny.originalCalledParty",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_ringType,
{ "Ring type", "skinny.ringType",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &skinny_ringTypes_ext, 0x0,
"What type of ring to play",
HFILL }
},
{ &hf_skinny_ringMode,
{ "Ring mode", "skinny.ringMode",
FT_UINT32, BASE_HEX, VALS(skinny_ringModes), 0x0,
"What mode of ring to play",
HFILL }
},
{ &hf_skinny_speakerMode,
{ "Speaker", "skinny.speakerMode",
FT_UINT32, BASE_HEX, VALS(skinny_speakerModes), 0x0,
"This message sets the speaker mode on/off",
HFILL }
},
{ &hf_skinny_remoteIpAddr,
{ "Remote IP address", "skinny.remoteIpAddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The remote end ip address for this stream",
HFILL }
},
{ &hf_skinny_remotePortNumber,
{ "Remote port", "skinny.remotePortNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The remote port number listening for this stream",
HFILL }
},
{ &hf_skinny_millisecondPacketSize,
{ "MS/packet", "skinny.millisecondPacketSize",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of milliseconds of conversation in each packet",
HFILL }
},
{ &hf_skinny_precedenceValue,
{ "Precedence", "skinny.precedenceValue",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_silenceSuppression,
{ "Silence suppression", "skinny.silenceSuppression",
FT_UINT32, BASE_HEX, VALS(skinny_silenceSuppressionModes), 0x0,
"Mode for silence suppression",
HFILL }
},
{ &hf_skinny_g723BitRate,
{ "G723 bitrate", "skinny.g723BitRate",
FT_UINT32, BASE_DEC, VALS(skinny_g723BitRates), 0x0,
"The G723 bit rate for this stream/JUNK if not g723 stream",
HFILL }
},
{ &hf_skinny_conferenceID,
{ "Conference ID", "skinny.conferenceID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_deviceResetType,
{ "Reset type", "skinny.deviceResetType",
FT_UINT32, BASE_DEC, VALS(skinny_deviceResetTypes), 0x0,
"How the devices it to be reset (reset/restart)",
HFILL }
},
{ &hf_skinny_echoCancelType,
{ "Echo-cancel type", "skinny.echoCancelType",
FT_UINT32, BASE_DEC, VALS(skinny_echoCancelTypes), 0x0,
"Is echo cancelling enabled or not",
HFILL }
},
{ &hf_skinny_deviceUnregisterStatus,
{ "Unregister status", "skinny.deviceUnregisterStatus",
FT_UINT32, BASE_DEC, VALS(skinny_deviceUnregisterStatusTypes), 0x0,
"The status of the device unregister request (*CAN* be refused)",
HFILL }
},
{ &hf_skinny_hookFlashDetectMode,
{ "Hook flash mode", "skinny.hookFlashDetectMode",
FT_UINT32, BASE_DEC, VALS(skinny_hookFlashDetectModes), 0x0,
"Which method to use to detect that a hook flash has occured",
HFILL }
},
{ &hf_skinny_detectInterval,
{ "HF Detect Interval", "skinny.detectInterval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of milliseconds that determines a hook flash has occured",
HFILL }
},
{ &hf_skinny_headsetMode,
{ "Headset mode", "skinny.headsetMode",
FT_UINT32, BASE_DEC, VALS(skinny_headsetModes), 0x0,
"Turns on and off the headset on the set",
HFILL }
},
{ &hf_skinny_microphoneMode,
{ "Microphone mode", "skinny.microphoneMode",
FT_UINT32, BASE_DEC, VALS(skinny_microphoneModes), 0x0,
"Turns on and off the microphone on the set",
HFILL }
},
{ &hf_skinny_activeForward,
{ "Active forward", "skinny.activeForward",
FT_UINT32, BASE_DEC, NULL, 0x0,
"This is non zero to indicate that a forward is active on the line",
HFILL }
},
{ &hf_skinny_forwardAllActive,
{ "Forward all", "skinny.forwardAllActive",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Forward all calls",
HFILL }
},
{ &hf_skinny_forwardBusyActive,
{ "Forward busy", "skinny.forwardBusyActive",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Forward calls when busy",
HFILL }
},
{ &hf_skinny_forwardNoAnswerActive,
{ "Forward no answer", "skinny.forwardNoAnswerActive",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Forward only when no answer",
HFILL }
},
{ &hf_skinny_forwardNumber,
{ "Forward number", "skinny.forwardNumber",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number to forward calls to.",
HFILL }
},
{ &hf_skinny_userName,
{ "Username", "skinny.userName",
FT_STRING, BASE_NONE, NULL, 0x0,
"Username for this device.",
HFILL }
},
{ &hf_skinny_serverName,
{ "Server name", "skinny.serverName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The server name for this device.",
HFILL }
},
{ &hf_skinny_numberLines,
{ "Number of lines", "skinny.numberLines",
FT_UINT32, BASE_DEC, NULL, 0x0,
"How many lines this device has",
HFILL }
},
{ &hf_skinny_numberSpeedDials,
{ "Number of speed-dials", "skinny.numberSpeedDials",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of speed dials this device has",
HFILL }
},
{ &hf_skinny_sessionType,
{ "Session type", "skinny.sessionType",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_sessionTypes_ext, 0x0,
"The type of this session.",
HFILL }
},
{ &hf_skinny_version,
{ "Version", "skinny.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_mediaEnunciationType,
{ "Enunciation type", "skinny.mediaEnunciationType",
FT_UINT32, BASE_DEC, VALS(skinny_mediaEnunciationTypes), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serverIdentifier,
{ "Server identifier", "skinny.serverIdentifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serverListenPort,
{ "Server port", "skinny.serverListenPort",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serverIpAddress,
{ "Server IP address", "skinny.serverIpAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_multicastPort,
{ "Multicast port", "skinny.multicastPort",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_multicastIpAddress,
{ "Multicast IP address", "skinny.multicastIpAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_tokenRejWaitTime,
{ "Retry wait time", "skinny.tokenRejWaitTime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_unknown,
{ "Unknown data", "skinny.unknown",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Place holder for unknown data.",
HFILL }
},
{ &hf_skinny_rawData,
{ "Unknown raw data", "skinny.rawData",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Place holder for unknown raw data.",
HFILL }
},
{ &hf_skinny_xmlData,
{ "XML data", "skinny.xmlData",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfInServiceStreams,
{ "Number of in-service streams", "skinny.numberOfInServiceStreams",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_maxStreamsPerConf,
{ "Max streams per conf", "skinny.maxStreamsPerConf",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfOutOfServiceStreams,
{ "Number of out-of-service streams", "skinny.numberOfOutOfServiceStreams",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_applicationID,
{ "Application ID", "skinny.applicationID",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Application ID.",
HFILL }
},
{ &hf_skinny_transactionID,
{ "Transaction ID", "skinny.transactionID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serviceNum,
{ "Service number", "skinny.serviceNum",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serviceURLIndex,
{ "Service URL index", "skinny.serviceURLIndex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_featureIndex,
{ "Feature index", "skinny.featureIndex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_createConfResults,
{ "Create conf results", "skinny.createConfResults",
FT_UINT32, BASE_DEC, VALS(skinny_createConfResults), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_modifyConfResults,
{ "Modify conf results", "skinny.modifyConfResults",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_modifyConfResults_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_deleteConfResults,
{ "Delete conf results", "skinny.deleteConfResults",
FT_UINT32, BASE_DEC, VALS(skinny_deleteConfResults), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_addParticipantResults,
{ "Add participant results", "skinny.addParticipantResults",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_addParticipantResults_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_passThruData,
{ "Pass-thru data", "skinny.passThruData",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_auditParticipantResults,
{ "Audit participant results", "skinny.auditParticipantResults",
FT_UINT32, BASE_DEC, VALS(skinny_auditParticipantResults), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_last,
{ "Last", "skinny.last",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfEntries,
{ "Number of entries", "skinny.numberOfEntries",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_participantEntry,
{ "Participant entry", "skinny.participantEntry",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_resourceTypes,
{ "ResourceType", "skinny.resourceTypes",
FT_UINT32, BASE_DEC, VALS(skinny_resourceTypes), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfReservedParticipants,
{ "Number of reserved participants", "skinny.numberOfReservedParticipants",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfActiveParticipants,
{ "Number of active participants", "skinny.numberOfActiveParticipants",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_appID,
{ "Application ID", "skinny.appID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_appData,
{ "Application data", "skinny.appData",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_appConfID,
{ "Application conf ID", "skinny.appConfID",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_sequenceFlag,
{ "Sequence flag", "skinny.sequenceFlag",
FT_UINT32, BASE_DEC, VALS(skinny_sequenceFlags), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_displayPriority,
{ "Display priority", "skinny.displayPriority",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_appInstanceID,
{ "Application instance ID", "skinny.appInstanceID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_routingID,
{ "Routing ID", "skinny.routingID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_audioCapCount,
{ "Audio cap count", "skinny.audioCapCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_videoCapCount,
{ "Video cap count", "skinny.videoCapCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_dataCapCount,
{ "Data cap count", "skinny.dataCapCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_RTPPayloadFormat,
{ "RTP payload format", "skinny.RTPPayloadFormat",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_customPictureFormatCount,
{ "Custom picture format count", "skinny.customPictureFormatCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_pictureWidth,
{ "Picture width", "skinny.pictureWidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_pictureHeight,
{ "Picture height", "skinny.pictureHeight",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_pixelAspectRatio,
{ "Pixel aspect ratio", "skinny.pixelAspectRatio",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_clockConversionCode,
{ "Clock conversion code", "skinny.clockConversionCode",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_clockDivisor,
{ "Clock divisor", "skinny.clockDivisor",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_activeStreamsOnRegistration,
{ "Active streams on registration", "skinny.activeStreamsOnRegistration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_maxBW,
{ "Max BW", "skinny.maxBW",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serviceResourceCount,
{ "Service resource count", "skinny.serviceResourceCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_layoutCount,
{ "Layout count", "skinny.layoutCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_layout,
{ "Layout", "skinny.layout",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_Layouts_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_maxConferences,
{ "Max conferences", "skinny.maxConferences",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_activeConferenceOnRegistration,
{ "Active conference on registration", "skinny.activeConferenceOnRegistration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_transmitOrReceive,
{ "Transmit or receive", "skinny.transmitOrReceive",
FT_UINT32, BASE_DEC, VALS(skinny_transmitOrReceive), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_levelPreferenceCount,
{ "Level preference count", "skinny.levelPreferenceCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_transmitPreference,
{ "Transmit preference", "skinny.transmitPreference",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_format,
{ "Format", "skinny.format",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_formatTypes_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_maxBitRate,
{ "Max bitrate", "skinny.maxBitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_minBitRate,
{ "Min bitrate", "skinny.minBitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_MPI,
{ "MPI", "skinny.MPI",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serviceNumber,
{ "Service number", "skinny.serviceNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_temporalSpatialTradeOffCapability,
{ "Temporal spatial trade off capability", "skinny.temporalSpatialTradeOffCapability",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_stillImageTransmission,
{ "Still image transmission", "skinny.stillImageTransmission",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_h263_capability_bitfield,
{ "H263 capability bitfield", "skinny.h263_capability_bitfield",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_annexNandWFutureUse,
{ "Annex N and W future use", "skinny.annexNandWFutureUse",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_modelNumber,
{ "Model number", "skinny.modelNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_bandwidth,
{ "Bandwidth", "skinny.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_protocolDependentData,
{ "Protocol dependent data", "skinny.protocolDependentData",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_priority,
{ "Priority", "skinny.priority",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_payloadDtmf,
{ "Payload DTMF", "skinny.payloadDtmf",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RTP payload type.",
HFILL }
},
{ &hf_skinny_featureID,
{ "Feature ID", "skinny.featureID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_featureTextLabel,
{ "Feature text label", "skinny.featureTextLabel",
FT_STRING, BASE_NONE, NULL, 0x0,
"The feature label text that is displayed on the phone.",
HFILL }
},
{ &hf_skinny_featureStatus,
{ "Feature status", "skinny.featureStatus",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_notify,
{ "Notify", "skinny.notify",
FT_STRING, BASE_NONE, NULL, 0x0,
"The message notify text that is displayed on the phone.",
HFILL }
},
{ &hf_skinny_endOfAnnAck,
{ "End of ann. ack", "skinny.endOfAnnAck",
FT_UINT32, BASE_DEC, VALS(skinny_endOfAnnAck), 0x0,
"End of announcement ack.",
HFILL }
},
{ &hf_skinny_annPlayMode,
{ "Ann. play mode", "skinny.annPlayMode",
FT_UINT32, BASE_DEC, VALS(skinny_annPlayMode), 0x0,
"Announcement play mode.",
HFILL }
},
{ &hf_skinny_annPlayStatus,
{ "Ann. play status", "skinny.annPlayStatus",
FT_UINT32, BASE_DEC, VALS(skinny_annPlayStatus), 0x0,
"Announcement play status.",
HFILL }
},
{ &hf_skinny_locale,
{ "Locale", "skinny.locale",
FT_UINT32, BASE_DEC, NULL, 0x0,
"User locale ID.",
HFILL }
},
{ &hf_skinny_country,
{ "Country", "skinny.country",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Country ID (Network locale).",
HFILL }
},
{ &hf_skinny_matrixConfPartyID,
{ "Matrix conf party ID", "skinny.matrixConfPartyID",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Existing conference parties.",
HFILL }
},
{ &hf_skinny_hearingConfPartyMask,
{ "Hearing conf party mask", "skinny.hearingConfPartyMask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Bit mask of conference parties to hear media received on this stream. Bit0 = matrixConfPartyID[0], Bit1 = matrixConfPartiID[1].",
HFILL }
},
{ &hf_skinny_serviceURL,
{ "Service URL value", "skinny.serviceURL",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_serviceURLDisplayName,
{ "Service URL display name", "skinny.serviceURLDisplayName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_callSelectStat,
{ "Call select stat", "skinny.callSelectStat",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_isConferenceCreator,
{ "Is conference creator", "skinny.isConferenceCreator",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_payload_rfc_number,
{ "Payload RFC number", "skinny.payload_rfc_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_payloadType,
{ "Payload type", "skinny.payloadType",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_bitRate,
{ "Bitrate", "skinny.bitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_pictureFormatCount,
{ "Picture format count", "skinny.pictureFormatCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_confServiceNum,
{ "Conf service number", "skinny.confServiceNum",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Conference service number.",
HFILL }
},
{ &hf_skinny_DSCPValue,
{ "DSCP value", "skinny.DSCPValue",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_miscCommandType,
{ "Misc command type", "skinny.miscCommandType",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &skinny_miscCommandType_ext, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_temporalSpatialTradeOff,
{ "Temporal spatial trade-off", "skinny.temporalSpatialTradeOff",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_firstGOB,
{ "First GOB", "skinny.firstGOB",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfGOBs,
{ "Number of GOBs", "skinny.numberOfGOBs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_firstMB,
{ "First MB", "skinny.firstMB",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_numberOfMBs,
{ "Number of MBs", "skinny.numberOfMBs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_pictureNumber,
{ "Picture number", "skinny.pictureNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_longTermPictureIndex,
{ "Long-term picture index", "skinny.longTermPictureIndex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_recoveryReferencePictureCount,
{ "Recovery-reference picture count", "skinny.recoveryReferencePictureCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_lastRedirectingPartyName,
{ "Last redirecting party name", "cast.lastRedirectingPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_lastRedirectingParty,
{ "Last redirecting party", "cast.lastRedirectingParty",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_cgpnVoiceMailbox,
{ "Calling party voice mailbox", "cast.cgpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_cdpnVoiceMailbox,
{ "Called party voice mailbox", "cast.cdpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_originalCdpnVoiceMailbox,
{ "Original called party voice mailbox", "cast.originalCdpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_lastRedirectingVoiceMailbox,
{ "Last redirecting voice mailbox", "cast.lastRedirectingVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_originalCdpnRedirectReason,
{ "Original called party redirect reason", "cast.originalCdpnRedirectReason",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_lastRedirectingReason,
{ "Last redirecting reason", "cast.lastRedirectingReason",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_callInstance,
{ "Call instance", "cast.callInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_cast_callSecurityStatus,
{ "Call security status", "cast.callSecurityStatus",
FT_UINT32, BASE_DEC, VALS(cast_callSecurityStatusTypes), 0x0,
NULL,
HFILL }
},
{ &hf_skinny_directoryIndex,
{ "Directory index", "skinny.directoryIndex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL }
},
{ &hf_skinny_directoryPhoneNumber,
{ "Directory phone number", "skinny.directoryPhoneNumber",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
},
};
static gint *ett[] = {
&ett_skinny,
&ett_skinny_tree,
&ett_skinny_softKeyMap,
};
module_t *skinny_module;
proto_skinny = proto_register_protocol("Skinny Client Control Protocol",
"SKINNY", "skinny");
proto_register_field_array(proto_skinny, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
skinny_module = prefs_register_protocol(proto_skinny, NULL);
prefs_register_bool_preference(skinny_module, "desegment",
"Reassemble SCCP messages spanning multiple TCP segments",
"Whether the SCCP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&skinny_desegment);
skinny_tap = register_tap("skinny");
}
void
proto_reg_handoff_skinny(void)
{
static gboolean skinny_prefs_initialized = FALSE;
dissector_handle_t skinny_handle;
if (!skinny_prefs_initialized) {
rtp_handle = find_dissector("rtp");
media_type_dissector_table = find_dissector_table("media_type");
skinny_handle = new_create_dissector_handle(dissect_skinny, proto_skinny);
dissector_add_uint("tcp.port", TCP_PORT_SKINNY, skinny_handle);
ssl_dissector_add(SSL_PORT_SKINNY, "skinny", TRUE);
skinny_prefs_initialized = TRUE;
}
}
