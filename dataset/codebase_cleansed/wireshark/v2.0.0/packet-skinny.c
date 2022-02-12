static guint
get_skinny_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint32 hdr_data_length;
hdr_data_length = tvb_get_letohl(tvb, offset);
return hdr_data_length + 8;
}
static void
dissect_skinny_xml(ptvcursor_t *cursor, int hfindex, packet_info *pinfo, guint32 length, guint32 maxlength)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
dissector_handle_t handle = NULL;
proto_tree *tree = ptvcursor_tree(cursor);
guint32 offset = ptvcursor_current_offset(cursor);
tvbuff_t *tvb = ptvcursor_tvbuff(cursor);
tvbuff_t *next_tvb;
if (length == 0) {
length = tvb_strnlen(tvb, offset, -1);
}
if (length >= maxlength) {
length = maxlength;
}
ptvcursor_add_no_advance(cursor, hfindex, length, ENC_ASCII|ENC_NA);
item = proto_tree_add_item(tree, hf_skinny_xmlData, tvb, offset, length, ENC_ASCII|ENC_NA);
subtree = proto_item_add_subtree(item, 0);
next_tvb = tvb_new_subset(tvb, offset, length, -1);
handle = dissector_get_string_handle(media_type_dissector_table, "text/xml");
if (handle != NULL) {
call_dissector(handle, next_tvb, pinfo, subtree);
}
ptvcursor_advance(cursor, maxlength);
}
static void
dissect_skinny_ipv4or6(ptvcursor_t *cursor, int hfindex_ipv4, int hfindex_ipv6, packet_info *pinfo)
{
address src_addr;
guint32 ipversion = 0;
guint32 offset = ptvcursor_current_offset(cursor);
tvbuff_t *tvb = ptvcursor_tvbuff(cursor);
guint32 hdr_version = tvb_get_letohl(tvb, 4);
gboolean is_video = FALSE;
if (hdr_version >= V17_MSG_TYPE) {
ipversion = tvb_get_letohl(tvb, offset);
ptvcursor_add(cursor, hf_skinny_ipv4or6, 4, ENC_LITTLE_ENDIAN);
}
if (ipversion == IPADDRTYPE_IPV4) {
guint32 ip_address;
src_addr.type = AT_IPv4;
src_addr.len = 4;
src_addr.data = (guint8 *)&ip_address;
ip_address = tvb_get_ipv4(tvb, offset);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset), 0, "Skinny", pinfo->fd->num, is_video, NULL);
ptvcursor_add(cursor, hfindex_ipv4, 4, ENC_BIG_ENDIAN);
if (hdr_version >= V17_MSG_TYPE) {
ptvcursor_advance(cursor, 12);
}
} else if (ipversion == IPADDRTYPE_IPV6 || ipversion == IPADDRTYPE_IPV4_V6) {
struct e_in6_addr IPv6;
src_addr.type = AT_IPv6;
src_addr.len = 16;
src_addr.data = (guint8 *)&IPv6;
tvb_get_ipv6(tvb, offset, &IPv6);
rtp_add_address(pinfo, &src_addr, tvb_get_letohl(tvb, offset), 0, "Skinny", pinfo->fd->num, is_video, NULL);
ptvcursor_add(cursor, hfindex_ipv6, 16, ENC_NA);
} else {
ptvcursor_advance(cursor, 16);
}
}
static void
dissect_skinny_displayLabel(ptvcursor_t *cursor, int hfindex, gint length)
{
proto_item *item = NULL;
proto_tree *tree = ptvcursor_tree(cursor);
guint32 offset = ptvcursor_current_offset(cursor);
tvbuff_t *tvb = ptvcursor_tvbuff(cursor);
wmem_strbuf_t *wmem_new = NULL;
gchar *disp_string = NULL;
const gchar *replacestr = NULL;
gboolean show_replaced_str = FALSE;
gint x = 0;
if (length == 0) {
length = tvb_strnlen(tvb, offset, -1);
if (length == -1) {
length = tvb_captured_length_remaining(tvb, offset);
}
}
item = proto_tree_add_item(tree, hfindex, tvb, offset, length, ENC_ASCII | ENC_NA);
wmem_new = wmem_strbuf_sized_new(wmem_packet_scope(), length + 1, 0);
disp_string = (gchar*) wmem_alloc(wmem_packet_scope(), length + 1);
disp_string[length] = '\0';
tvb_memcpy(tvb, (void*)disp_string, offset, length);
for (x = 0; x < length && disp_string[x] != '\0'; x++) {
replacestr = NULL;
if (x + 1 < length) {
if (disp_string[x] == '\36') {
replacestr = try_val_to_str_ext(disp_string[x + 1], &DisplayLabels_36_ext);
} else if (disp_string[x] == '\200') {
replacestr = try_val_to_str_ext(disp_string[x + 1], &DisplayLabels_200_ext);
}
}
if (replacestr) {
x++;
wmem_strbuf_append(wmem_new, replacestr);
show_replaced_str = TRUE;
} else {
wmem_strbuf_append_c(wmem_new, disp_string[x]);
}
}
if (show_replaced_str) {
proto_item_append_text(item, " => \"%s\"" , wmem_strbuf_get_str(wmem_new));
}
ptvcursor_advance(cursor, length);
}
static void
handle_RegisterMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sid");
ptvcursor_add(cursor, hf_skinny_DeviceName, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_reserved_for_future_use, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_instance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_stationIpAddr, 4, ENC_BIG_ENDIAN);
ptvcursor_add(cursor, hf_skinny_deviceType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreams, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 52) {
ptvcursor_add(cursor, hf_skinny_activeStreams, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_protocolVer, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_unknown, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "PhoneFeatures");
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit1, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit2, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit3, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit4, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_UTF8, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit6, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit7, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_DynamicMessages, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit9, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_RFC2833, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit11, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit12, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit13, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit14, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit15, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Abbreviated_Dial, 2, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 2);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_maxConferences, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_data_length > 100) {
ptvcursor_add(cursor, hf_skinny_activeConferences, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_macAddress, 6, ENC_NA);
ptvcursor_advance(cursor, 12 - 6);
ptvcursor_add(cursor, hf_skinny_ipV4AddressScope, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxNumberOfLines, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stationIpV6Addr, 16, ENC_NA);
ptvcursor_add(cursor, hf_skinny_ipV6AddressScope, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_firmwareLoadName, 32, ENC_ASCII|ENC_NA);
}
if (hdr_data_length > 190) {
ptvcursor_add(cursor, hf_skinny_configVersionStamp, 48, ENC_ASCII|ENC_NA);
}
}
static void
handle_IpPortMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_rtpMediaPort, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_KeypadButtonMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
ptvcursor_add(cursor, hf_skinny_kpButton, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 8) {
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_EnblocCallMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
si->calledParty = g_strdup(tvb_format_stringzpad(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), VariableDirnumSize));
ptvcursor_add(cursor, hf_skinny_calledParty, VariableDirnumSize, ENC_ASCII|ENC_NA);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StimulusMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_stimulus, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stimulusStatus, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_OffHookMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
if (hdr_data_length > 4) {
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_OnHookMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
if (hdr_data_length > 4) {
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_HookFlashMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ForwardStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_lineNumber, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SpeedDialStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_speedDialNumber, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_LineStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_lineNumber, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CapabilitiesRes(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 capCount = 0;
guint32 payloadCapability = 0;
capCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_capCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "caps [ref: capCount = %d, max:18]", capCount);
for (counter_1 = 0; counter_1 < 18; counter_1++) {
if (counter_1 < capCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "caps [%d / %d]", counter_1 + 1, capCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 4, ENC_LITTLE_ENDIAN);
if (payloadCapability == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_MODEMRELAY) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_ModemRelay");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SPRT) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SPRT");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SSE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SSE");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any payloadCapability");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
}
} else {
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_AlarmMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_alarmSeverity, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_text, 80, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_parm1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_parm2, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_MulticastMediaReceptionAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_receptionStatus, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_OpenReceiveChannelAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
si->openreceiveStatus = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_openReceiveChannelStatus, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_ipAddr_ipv4, hf_skinny_ipAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_portNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 20) {
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_ConnectionStatisticsResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
guint32 dataSize = 0;
ptvcursor_add(cursor, hf_skinny_directoryNum, VariableDirnumSize, ENC_ASCII|ENC_NA);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_statsProcessingMode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberPacketsSent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOctetsSent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberPacketsReceived, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOctetsReceived, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberPacketsLost, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_jitter, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_latency, 4, ENC_LITTLE_ENDIAN);
if (hdr_data_length > 64) {
dataSize = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataSize, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_data, dataSize, ENC_ASCII|ENC_NA);
}
}
static void
handle_OffHookWithCgpnMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
ptvcursor_add(cursor, hf_skinny_callingPartyNumber, VariableDirnumSize, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_cgpnVoiceMailbox, VariableDirnumSize, ENC_ASCII|ENC_NA);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SoftKeyEventMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_softKeyEvent, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UnregisterMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_unRegReasonCode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_RegisterTokenReq(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sid");
ptvcursor_add(cursor, hf_skinny_DeviceName, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_reserved_for_future_use, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_instance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_stationIpAddr, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_deviceType, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_stationIpV6Addr_ipv4, hf_skinny_stationIpV6Addr_ipv6, pinfo);
}
static void
handle_MediaTransmissionFailureMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_HeadsetStatusMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_headsetStatus, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_MediaResourceNotificationMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_deviceType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfInServiceStreams, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreamsPerConf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfOutOfServiceStreams, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_RegisterAvailableLinesMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_maxNumOfAvailLines, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_DeviceToUserDataMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "deviceToUserData");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_DeviceToUserDataResponseMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "deviceToUserData");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_UpdateCapabilitiesMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 audioCapCount = 0;
guint32 videoCapCount = 0;
guint32 dataCapCount = 0;
guint32 customPictureFormatCount = 0;
guint32 serviceResourceCount = 0;
guint32 layoutCount = 0;
guint32 payloadCapability = 0;
guint32 levelPreferenceCount = 0;
audioCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_audioCapCount, 4, ENC_LITTLE_ENDIAN);
videoCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_videoCapCount, 4, ENC_LITTLE_ENDIAN);
dataCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataCapCount, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RTPPayloadFormat, 4, ENC_LITTLE_ENDIAN);
customPictureFormatCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_customPictureFormatCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [ref: customPictureFormatCount = %d, max:6]", customPictureFormatCount);
for (counter_1 = 0; counter_1 < 6; counter_1++) {
if (counter_1 < customPictureFormatCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [%d / %d]", counter_1 + 1, customPictureFormatCount);
ptvcursor_add(cursor, hf_skinny_pictureWidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pictureHeight, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pixelAspectRatio, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockConversionCode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockDivisor, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 20);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "confResources");
ptvcursor_add(cursor, hf_skinny_activeStreamsOnRegistration, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBW, 4, ENC_LITTLE_ENDIAN);
serviceResourceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_serviceResourceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [ref: serviceResourceCount = %d, max:4]", serviceResourceCount);
for (counter_2 = 0; counter_2 < 4; counter_2++) {
if (counter_2 < serviceResourceCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [%d / %d]", counter_2 + 1, serviceResourceCount);
layoutCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_layoutCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_5 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "layouts [ref: layoutCount = %d, max:5]", layoutCount);
for (counter_5 = 0; counter_5 < 5; counter_5++) {
if (counter_5 < layoutCount) {
ptvcursor_add(cursor, hf_skinny_layouts, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 4);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_serviceNum, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreams, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxConferences, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_activeConferenceOnRegistration, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 24);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [ref: audioCapCount = %d, max:18]", audioCapCount);
for (counter_1 = 0; counter_1 < 18; counter_1++) {
if (counter_1 < audioCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [%d / %d]", counter_1 + 1, audioCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 4, ENC_LITTLE_ENDIAN);
if (payloadCapability == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_MODEMRELAY) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_ModemRelay");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SPRT) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SPRT");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SSE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SSE");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any payloadCapability");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
}
} else {
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [ref: videoCapCount = %d, max:10]", videoCapCount);
for (counter_1 = 0; counter_1 < 10; counter_1++) {
if (counter_1 < videoCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [%d / %d]", counter_1 + 1, videoCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_videoCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
levelPreferenceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_levelPreferenceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_4 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [ref: levelPreferenceCount = %d, max:4]", levelPreferenceCount);
for (counter_4 = 0; counter_4 < 4; counter_4++) {
if (counter_4 < levelPreferenceCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [%d / %d]", counter_4 + 1, levelPreferenceCount);
ptvcursor_add(cursor, hf_skinny_transmitPreference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_format, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_minBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_MPI, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_serviceNumber, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 24);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
if (payloadCapability == MEDIA_PAYLOAD_H261) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H261");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h261VideoCapability");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOffCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stillImageTransmission, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_H263) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H263");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263VideoCapability");
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263_capability_bitfield");
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit17, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit18, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit19, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit20, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit21, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit22, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit23, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit24, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit25, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit26, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit27, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit28, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit29, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit30, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit31, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit32, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_annexNandWFutureUse, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_VIEO) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_Vieo");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vieoVideoCapability");
ptvcursor_add(cursor, hf_skinny_modelNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bandwidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
} else {
ptvcursor_advance(cursor, 44);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [ref: dataCapCount = %d, max:5]", dataCapCount);
for (counter_1 = 0; counter_1 < 5; counter_1++) {
if (counter_1 < dataCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [%d / %d]", counter_1 + 1, dataCapCount);
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dataCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_protocolDependentData, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_OpenMultiMediaReceiveChannelAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_multimediaOpenReceiveChannelStatus, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_ipAddr_ipv4, hf_skinny_ipAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_portNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ClearConferenceMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_serviceNum, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ServiceURLStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_serviceURLIndex, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_FeatureStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_featureIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureCapabilities, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CreateConferenceResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_result, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruData, dataLength, ENC_ASCII|ENC_NA);
}
static void
handle_DeleteConferenceResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_delete_conf_result, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ModifyConferenceResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modify_conf_result, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruData, dataLength, ENC_ASCII|ENC_NA);
}
static void
handle_AddParticipantResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_add_participant_result, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bridgeParticipantId, 257, ENC_ASCII|ENC_NA);
}
static void
handle_AuditConferenceResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 numberOfEntries = 0;
ptvcursor_add(cursor, hf_skinny_last, 4, ENC_LITTLE_ENDIAN);
numberOfEntries = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_numberOfEntries, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "conferenceEntry [ref: numberOfEntries = %d, max:32]", numberOfEntries);
for (counter_1 = 0; counter_1 < 32; counter_1++) {
if (counter_1 < numberOfEntries) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "conferenceEntry [%d / %d]", counter_1 + 1, numberOfEntries);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_resourceType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfReservedParticipants, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfActiveParticipants, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appConfID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appData, 24, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 76);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_AuditParticipantResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 numberOfEntries = 0;
ptvcursor_add(cursor, hf_skinny_audit_participant_result, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_last, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
numberOfEntries = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_numberOfEntries, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "participantEntry [ref: numberOfEntries = %d, max:256]", numberOfEntries);
for (counter_1 = 0; counter_1 < 256; counter_1++) {
if (counter_1 < numberOfEntries) {
ptvcursor_add(cursor, hf_skinny_participantEntry, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 4);
}
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_DeviceToUserDataMessageVersion1(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "deviceToUserDataVersion1");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_sequenceFlag, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_displayPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appInstanceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_routingID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_DeviceToUserDataResponseMessageVersion1(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "deviceToUserDataVersion1");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_sequenceFlag, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_displayPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appInstanceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_routingID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_UpdateCapabilitiesV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 audioCapCount = 0;
guint32 videoCapCount = 0;
guint32 dataCapCount = 0;
guint32 customPictureFormatCount = 0;
guint32 serviceResourceCount = 0;
guint32 layoutCount = 0;
guint32 payloadCapability = 0;
guint32 levelPreferenceCount = 0;
audioCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_audioCapCount, 4, ENC_LITTLE_ENDIAN);
videoCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_videoCapCount, 4, ENC_LITTLE_ENDIAN);
dataCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataCapCount, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RTPPayloadFormat, 4, ENC_LITTLE_ENDIAN);
customPictureFormatCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_customPictureFormatCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [ref: customPictureFormatCount = %d, max:6]", customPictureFormatCount);
for (counter_1 = 0; counter_1 < 6; counter_1++) {
if (counter_1 < customPictureFormatCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [%d / %d]", counter_1 + 1, customPictureFormatCount);
ptvcursor_add(cursor, hf_skinny_pictureWidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pictureHeight, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pixelAspectRatio, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockConversionCode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockDivisor, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 20);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "confResources");
ptvcursor_add(cursor, hf_skinny_activeStreamsOnRegistration, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBW, 4, ENC_LITTLE_ENDIAN);
serviceResourceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_serviceResourceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [ref: serviceResourceCount = %d, max:4]", serviceResourceCount);
for (counter_2 = 0; counter_2 < 4; counter_2++) {
if (counter_2 < serviceResourceCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [%d / %d]", counter_2 + 1, serviceResourceCount);
layoutCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_layoutCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_5 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "layouts [ref: layoutCount = %d, max:5]", layoutCount);
for (counter_5 = 0; counter_5 < 5; counter_5++) {
if (counter_5 < layoutCount) {
ptvcursor_add(cursor, hf_skinny_layouts, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 4);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_serviceNum, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreams, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxConferences, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_activeConferenceOnRegistration, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 24);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [ref: audioCapCount = %d, max:18]", audioCapCount);
for (counter_1 = 0; counter_1 < 18; counter_1++) {
if (counter_1 < audioCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [%d / %d]", counter_1 + 1, audioCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 4, ENC_LITTLE_ENDIAN);
if (payloadCapability == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_MODEMRELAY) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_ModemRelay");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SPRT) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SPRT");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SSE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SSE");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any payloadCapability");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
}
} else {
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [ref: videoCapCount = %d, max:10]", videoCapCount);
for (counter_1 = 0; counter_1 < 10; counter_1++) {
if (counter_1 < videoCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [%d / %d]", counter_1 + 1, videoCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_videoCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
levelPreferenceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_levelPreferenceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_4 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [ref: levelPreferenceCount = %d, max:4]", levelPreferenceCount);
for (counter_4 = 0; counter_4 < 4; counter_4++) {
if (counter_4 < levelPreferenceCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [%d / %d]", counter_4 + 1, levelPreferenceCount);
ptvcursor_add(cursor, hf_skinny_transmitPreference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_format, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_minBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_MPI, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_serviceNumber, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 24);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
if (payloadCapability == MEDIA_PAYLOAD_H261) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H261");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h261VideoCapability");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOffCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stillImageTransmission, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadCapability == MEDIA_PAYLOAD_H263) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H263");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263VideoCapability");
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263_capability_bitfield");
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit17, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit18, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit19, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit20, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit21, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit22, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit23, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit24, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit25, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit26, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit27, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit28, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit29, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit30, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit31, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit32, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_annexNandWFutureUse, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadCapability == MEDIA_PAYLOAD_H264) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H264");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h264VideoCapability");
ptvcursor_add(cursor, hf_skinny_profile, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_level, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxMBPS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxFS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxDPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxBRandCPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_VIEO) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_Vieo");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vieoVideoCapability");
ptvcursor_add(cursor, hf_skinny_modelNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bandwidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
}
} else {
ptvcursor_advance(cursor, 60);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [ref: dataCapCount = %d, max:5]", dataCapCount);
for (counter_1 = 0; counter_1 < 5; counter_1++) {
if (counter_1 < dataCapCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [%d / %d]", counter_1 + 1, dataCapCount);
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dataCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_protocolDependentData, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_UpdateCapabilitiesV3Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 audioCapCount = 0;
guint32 videoCapCount = 0;
guint32 dataCapCount = 0;
guint32 customPictureFormatCount = 0;
guint32 serviceResourceCount = 0;
guint32 layoutCount = 0;
guint32 payloadCapability = 0;
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 levelPreferenceCount = 0;
audioCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_audioCapCount, 4, ENC_LITTLE_ENDIAN);
videoCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_videoCapCount, 4, ENC_LITTLE_ENDIAN);
dataCapCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataCapCount, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RTPPayloadFormat, 4, ENC_LITTLE_ENDIAN);
customPictureFormatCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_customPictureFormatCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [ref: customPictureFormatCount = %d, max:customPictureFormatCount]", customPictureFormatCount);
for (counter_1 = 0; counter_1 < customPictureFormatCount; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "customPictureFormat [%d / %d]", counter_1 + 1, customPictureFormatCount);
ptvcursor_add(cursor, hf_skinny_pictureWidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pictureHeight, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_pixelAspectRatio, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockConversionCode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_clockDivisor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "confResources");
ptvcursor_add(cursor, hf_skinny_activeStreamsOnRegistration, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBW, 4, ENC_LITTLE_ENDIAN);
serviceResourceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_serviceResourceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [ref: serviceResourceCount = %d, max:serviceResourceCount]", serviceResourceCount);
for (counter_2 = 0; counter_2 < serviceResourceCount; counter_2++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serviceResource [%d / %d]", counter_2 + 1, serviceResourceCount);
layoutCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_layoutCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_4 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "layouts [ref: layoutCount = %d, max:layoutCount]", layoutCount);
for (counter_4 = 0; counter_4 < layoutCount; counter_4++) {
ptvcursor_add(cursor, hf_skinny_layouts, 4, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_serviceNum, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreams, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxConferences, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_activeConferenceOnRegistration, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [ref: audioCapCount = %d, max:audioCapCount]", audioCapCount);
for (counter_1 = 0; counter_1 < audioCapCount; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audiocaps [%d / %d]", counter_1 + 1, audioCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 4, ENC_LITTLE_ENDIAN);
if (payloadCapability == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_MODEMRELAY) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_ModemRelay");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SPRT) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SPRT");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_V150_LC_SSE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_v150_LC_SSE");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any payloadCapability");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [ref: videoCapCount = %d, max:videoCapCount]", videoCapCount);
for (counter_1 = 0; counter_1 < videoCapCount; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidCaps [%d / %d]", counter_1 + 1, videoCapCount);
payloadCapability = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_videoCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
levelPreferenceCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_levelPreferenceCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_3 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [ref: levelPreferenceCount = %d, max:levelPreferenceCount]", levelPreferenceCount);
for (counter_3 = 0; counter_3 < levelPreferenceCount; counter_3++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "levelPreference [%d / %d]", counter_3 + 1, levelPreferenceCount);
ptvcursor_add(cursor, hf_skinny_transmitPreference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_format, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_minBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_MPI, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_serviceNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_encryptionCapability, 4, ENC_LITTLE_ENDIAN);
if (payloadCapability == MEDIA_PAYLOAD_H261) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H261");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h261VideoCapability");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOffCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stillImageTransmission, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadCapability == MEDIA_PAYLOAD_H263) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H263");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263VideoCapability");
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263_capability_bitfield");
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit17, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit18, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit19, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit20, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit21, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit22, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit23, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit24, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit25, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit26, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit27, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit28, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit29, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit30, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit31, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit32, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_annexNandWFutureUse, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadCapability == MEDIA_PAYLOAD_H264) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_H264");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h264VideoCapability");
ptvcursor_add(cursor, hf_skinny_profile, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_level, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxMBPS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxFS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxDPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxBRandCPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadCapability == MEDIA_PAYLOAD_VIEO) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadCapability is Media_Payload_Vieo");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vieoVideoCapability");
ptvcursor_add(cursor, hf_skinny_modelNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bandwidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
}
ptvcursor_add(cursor, hf_skinny_ipAddressingMode, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V16_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_ipAddressingMode, 4, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [ref: dataCapCount = %d, max:dataCapCount]", dataCapCount);
for (counter_1 = 0; counter_1 < dataCapCount; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataCaps [%d / %d]", counter_1 + 1, dataCapCount);
ptvcursor_add(cursor, hf_skinny_payloadCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dataCapabilityDirection, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_protocolDependentData, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_encryptionCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_PortResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_ipAddr_ipv4, hf_skinny_ipAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_portNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RTCPPortNumber, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V19_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_mediaType, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_QoSResvNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_direction, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_QoSErrorNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_direction, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_errorCode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_failureNodeIpAddr, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_rsvpErrorCode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_rsvpErrorSubCodeVal, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_rsvpErrorFlag, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SubscriptionStatReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_timer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_subscriptionID, 256, ENC_ASCII|ENC_NA);
}
static void
handle_MediaPathEventMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_mediaPathID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mediaPathEvent, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_MediaPathCapabilityMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_mediaPathID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mediaPathCapabilities, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_MwiNotificationMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_mwiTargetNumber, 25, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_mwiControlNumber, 25, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_areMessagesWaiting, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "totalVmCounts");
ptvcursor_add(cursor, hf_skinny_numNewMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numOldMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "priorityVmCounts");
ptvcursor_add(cursor, hf_skinny_numNewMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numOldMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "totalFaxCounts");
ptvcursor_add(cursor, hf_skinny_numNewMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numOldMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "priorityFaxCounts");
ptvcursor_add(cursor, hf_skinny_numNewMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numOldMsgs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_RegisterAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_keepAliveInterval, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dateTemplate, 6, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_alignmentPadding, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_secondaryKeepAliveInterval, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxProtocolVer, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_unknown, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "PhoneFeatures");
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit1, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit2, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit3, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit4, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_UTF8, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit6, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit7, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_DynamicMessages, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit9, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_RFC2833, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit11, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit12, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit13, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit14, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Bit15, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_PhoneFeatures_Abbreviated_Dial, 2, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 2);
ptvcursor_pop_subtree(cursor);
}
static void
handle_StartToneMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_tone, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_tone_output_direction, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopToneMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V11_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_tone, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_SetRingerMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_ringMode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_ringDuration, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SetLampMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_stimulus, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stimulusInstance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_lampMode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SetSpeakerModeMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_speakerMode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SetMicroModeMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_micMode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 compressionType = 0;
guint16 keylen = 0;
guint16 saltlen = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierOut");
ptvcursor_add(cursor, hf_skinny_precedenceValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_ssValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_padding, 2, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "mTxMediaEncryptionKeyInfo");
ptvcursor_add(cursor, hf_skinny_algorithmID, 4, ENC_LITTLE_ENDIAN);
keylen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_keylen, 2, ENC_LITTLE_ENDIAN);
saltlen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_saltlen, 2, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "key [ref: keylen = %d, max:16]", keylen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < keylen) {
ptvcursor_add(cursor, hf_skinny_key, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "salt [ref: saltlen = %d, max:16]", saltlen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < saltlen) {
ptvcursor_add(cursor, hf_skinny_salt, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_isMKIPresent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_keyDerivationRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_streamPassThroughID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_associatedStreamID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RFC2833PayloadType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dtmfType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mixingMode, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V15_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_partyDirection, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V20_MSG_TYPE) {
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "latentCapsInfo");
ptvcursor_add(cursor, hf_skinny_active, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadParam");
ptvcursor_add(cursor, hf_skinny_nse, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_rfc2833, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_sse, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_v150sprt, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_noaudio, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse3, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
}
static void
handle_StopMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_portHandlingFlag, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CallInfoMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_callingPartyName, 40, ENC_ASCII|ENC_NA);
si->callingParty = g_strdup(tvb_format_stringzpad(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), 24));
ptvcursor_add(cursor, hf_skinny_callingParty, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_calledPartyName, 40, ENC_ASCII|ENC_NA);
si->calledParty = g_strdup(tvb_format_stringzpad(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), 24));
ptvcursor_add(cursor, hf_skinny_calledParty, 24, ENC_ASCII|ENC_NA);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_callType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_originalCalledPartyName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_originalCalledParty, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lastRedirectingPartyName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lastRedirectingParty, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_originalCdpnRedirectReason, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_lastRedirectingReason, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_cgpnVoiceMailbox, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_cdpnVoiceMailbox, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_originalCdpnVoiceMailbox, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lastRedirectingVoiceMailbox, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_callInstance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_callSecurityStatus, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "partyPIRestrictionBits");
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_BitsReserved, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
}
static void
handle_ForwardStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
ptvcursor_add(cursor, hf_skinny_activeForward, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_lineNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_forwardAllActive, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_forwardAllDirnum, VariableDirnumSize, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_forwardBusyActive, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_forwardBusyDirnum, VariableDirnumSize, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_forwardNoAnswerActive, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_forwardNoAnswerlDirnum, VariableDirnumSize, ENC_ASCII|ENC_NA);
}
static void
handle_SpeedDialStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_speedDialNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_speedDialDirNumber, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_speedDialDisplayName, 40, ENC_ASCII|ENC_NA);
}
static void
handle_LineStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_lineNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_lineDirNumber, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lineFullyQualifiedDisplayName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lineTextLabel, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_lineDisplayOptions, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ConfigStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sid");
ptvcursor_add(cursor, hf_skinny_DeviceName, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_reserved_for_future_use, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_instance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_userName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_serverName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_numberOfLines, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfSpeedDials, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_DefineTimeDate(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "timeDataInfo");
ptvcursor_add(cursor, hf_skinny_wYear, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wMonth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wDayOfWeek, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wDay, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wHour, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wMinute, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wSecond, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_wMilliseconds, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_systemTime, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartSessionTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_sessionType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopSessionTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_sessionType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ButtonTemplateMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 totalButtonCount = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "buttonTemplate");
ptvcursor_add(cursor, hf_skinny_buttonOffset, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_buttonCount, 4, ENC_LITTLE_ENDIAN);
totalButtonCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_totalButtonCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [ref: totalButtonCount = %d, max:42]", totalButtonCount);
for (counter_2 = 0; counter_2 < 42; counter_2++) {
if (counter_2 < totalButtonCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [%d / %d]", counter_2 + 1, totalButtonCount);
ptvcursor_add(cursor, hf_skinny_instanceNumber, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_buttonDefinition, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 2);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_VersionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_version, 16, ENC_ASCII|ENC_NA);
}
static void
handle_DisplayTextMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_text, 32, ENC_ASCII|ENC_NA);
}
static void
handle_RegisterRejectMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_text, 32, ENC_ASCII|ENC_NA);
}
static void
handle_ServerResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_data_length = tvb_get_letohl(ptvcursor_tvbuff(cursor), 0);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "server [max:5]");
for (counter_1 = 0; counter_1 < 5; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "server [%d / %d]", counter_1 + 1, 5);
ptvcursor_add(cursor, hf_skinny_ServerName, 48, ENC_ASCII|ENC_NA);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serverTcpListenPort [max:5]");
for (counter_1 = 0; counter_1 < 5; counter_1++) {
ptvcursor_add(cursor, hf_skinny_serverTcpListenPort, 4, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
if (hdr_data_length < 293) {
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serverIpAddr [max:5]");
for (counter_2 = 0; counter_2 < 5; counter_2++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serverIpAddr [%d / %d]", counter_2 + 1, 5);
ptvcursor_add(cursor, hf_skinny_stationIpAddr, 4, ENC_BIG_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
if (hdr_data_length > 292) {
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serverIpAddr [max:5]");
for (counter_2 = 0; counter_2 < 5; counter_2++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "serverIpAddr [%d / %d]", counter_2 + 1, 5);
dissect_skinny_ipv4or6(cursor, hf_skinny_stationIpAddr_ipv4, hf_skinny_stationIpAddr_ipv6, pinfo);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
}
static void
handle_Reset(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_resetType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartMulticastMediaReceptionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 compressionType = 0;
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_multicastIpAddr_ipv4, hf_skinny_multicastIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_multicastPortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierIn");
ptvcursor_add(cursor, hf_skinny_ecValue, 4, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartMulticastMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 compressionType = 0;
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_multicastIpAddr_ipv4, hf_skinny_multicastIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_multicastPortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierOut");
ptvcursor_add(cursor, hf_skinny_precedenceValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_ssValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxFramesPerPacket, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_padding, 2, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopMulticastMediaReceptionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopMulticastMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_OpenReceiveChannelMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 compressionType = 0;
guint16 keylen = 0;
guint16 saltlen = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierIn");
ptvcursor_add(cursor, hf_skinny_ecValue, 4, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "mRxMediaEncryptionKeyInfo");
ptvcursor_add(cursor, hf_skinny_algorithmID, 4, ENC_LITTLE_ENDIAN);
keylen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_keylen, 2, ENC_LITTLE_ENDIAN);
saltlen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_saltlen, 2, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "key [ref: keylen = %d, max:16]", keylen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < keylen) {
ptvcursor_add(cursor, hf_skinny_key, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "salt [ref: saltlen = %d, max:16]", saltlen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < saltlen) {
ptvcursor_add(cursor, hf_skinny_salt, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_isMKIPresent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_keyDerivationRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_streamPassThroughID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_associatedStreamID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_RFC2833PayloadType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dtmfType, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V11_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_mixingMode, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_partyDirection, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_sourceIpAddr_ipv4, hf_skinny_sourceIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_sourcePortNumber, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V16_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_requestedIpAddrType, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V17_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_audioLevelAdjustment, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V20_MSG_TYPE) {
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "latentCapsInfo");
ptvcursor_add(cursor, hf_skinny_active, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "modemRelay");
ptvcursor_add(cursor, hf_skinny_capAndVer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_modAnd2833, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sprtPayload");
ptvcursor_add(cursor, hf_skinny_chan0MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan3MaxPayload, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_chan2MaxWindow, 2, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sse");
ptvcursor_add(cursor, hf_skinny_standard, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_vendor, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadParam");
ptvcursor_add(cursor, hf_skinny_nse, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_rfc2833, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_sse, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_v150sprt, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_noaudio, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_FutureUse3, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
}
static void
handle_CloseReceiveChannelMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_portHandlingFlag, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ConnectionStatisticsReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
ptvcursor_add(cursor, hf_skinny_directoryNum, VariableDirnumSize, ENC_ASCII|ENC_NA);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_statsProcessingMode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SoftKeyTemplateResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 totalSoftKeyCount = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "softKeyTemplate");
ptvcursor_add(cursor, hf_skinny_softKeyOffset, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_softKeyCount, 4, ENC_LITTLE_ENDIAN);
totalSoftKeyCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_totalSoftKeyCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [ref: totalSoftKeyCount = %d, max:32]", totalSoftKeyCount);
for (counter_2 = 0; counter_2 < 32; counter_2++) {
if (counter_2 < totalSoftKeyCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [%d / %d]", counter_2 + 1, totalSoftKeyCount);
dissect_skinny_displayLabel(cursor, hf_skinny_softKeyLabel, 16);
ptvcursor_add(cursor, hf_skinny_softKeyEvent, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 20);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_SoftKeySetResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 totalSoftKeySetCount = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "softKeySets");
ptvcursor_add(cursor, hf_skinny_softKeySetOffset, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_softKeySetCount, 4, ENC_LITTLE_ENDIAN);
totalSoftKeySetCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_totalSoftKeySetCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [ref: totalSoftKeySetCount = %d, max:16]", totalSoftKeySetCount);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < totalSoftKeySetCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "definition [%d / %d]", counter_2 + 1, totalSoftKeySetCount);
{
guint32 counter_5 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "softKeyTemplateIndex [max:16]");
for (counter_5 = 0; counter_5 < 16; counter_5++) {
ptvcursor_add(cursor, hf_skinny_softKeyTemplateIndex, 1, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_5 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "softKeyInfoIndex [max:16]");
for (counter_5 = 0; counter_5 < 16; counter_5++) {
ptvcursor_add(cursor, hf_skinny_softKeyInfoIndex, 2, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
} else {
ptvcursor_advance(cursor, 3);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_SelectSoftKeysMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_softKeySetIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "validKeyMask");
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_SoftKeyMask_SoftKey16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
}
static void
handle_CallStateMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->callState = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callState, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_privacy, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "precedence");
ptvcursor_add(cursor, hf_skinny_precedenceLevel, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_precedenceDomain, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_DisplayPromptStatusMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_promptStatus, 32);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ClearPromptStatusMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_DisplayNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_notify, 32);
}
static void
handle_ActivateCallPlaneMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UnregisterAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_status, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_BackSpaceReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_RegisterTokenReject(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_waitTimeBeforeNextReq, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartMediaFailureDetectionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 compressionType = 0;
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierIn");
ptvcursor_add(cursor, hf_skinny_ecValue, 4, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_DialedNumberMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 VariableDirnumSize = (hdr_version >= V18_MSG_TYPE) ? 25 : 24;
ptvcursor_add(cursor, hf_skinny_dialedNumber, VariableDirnumSize, ENC_ASCII|ENC_NA);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UserToDeviceDataMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "userToDeviceData");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_FeatureStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_featureIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureTextLabel, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_featureStatus, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_DisplayPriNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_priority, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_notify, 32);
}
static void
handle_ClearPriNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_priority, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartAnnouncementMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "AnnList [max:32]");
for (counter_1 = 0; counter_1 < 32; counter_1++) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "AnnList [%d / %d]", counter_1 + 1, 32);
ptvcursor_add(cursor, hf_skinny_locale, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_country, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_toneAnnouncement, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_annAckReq, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "matrixConfPartyID [max:16]");
for (counter_1 = 0; counter_1 < 16; counter_1++) {
ptvcursor_add(cursor, hf_skinny_matrixConfPartyID, 4, ENC_LITTLE_ENDIAN);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_hearingConfPartyMask, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_annPlayMode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopAnnouncementMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_AnnouncementFinishMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_annStatus, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_NotifyDtmfToneMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_tone, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SendDtmfToneMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_tone, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SubscribeDtmfPayloadReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dtmfType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SubscribeDtmfPayloadResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SubscribeDtmfPayloadErrMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UnSubscribeDtmfPayloadReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dtmfType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UnSubscribeDtmfPayloadResMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UnSubscribeDtmfPayloadErrMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_payloadDtmf, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ServiceURLStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_serviceURLIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_serviceURL, 256, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_serviceURLDisplayName, 40, ENC_ASCII|ENC_NA);
}
static void
handle_CallSelectStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_callSelectStat, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_OpenMultiMediaReceiveChannelMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 compressionType = 0;
guint32 payloadType = 0;
guint32 pictureFormatCount = 0;
guint16 keylen = 0;
guint16 saltlen = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType");
ptvcursor_add(cursor, hf_skinny_payload_rfc_number, 4, ENC_LITTLE_ENDIAN);
payloadType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_isConferenceCreator, 4, ENC_LITTLE_ENDIAN);
if (payloadType <= MEDIA_PAYLOAD_AMR_WB) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType <= Media_Payload_AMR_WB");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audioParameters");
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierIn");
ptvcursor_add(cursor, hf_skinny_ecValue, 4, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 28);
} else if (payloadType >= MEDIA_PAYLOAD_H261 && payloadType <= MEDIA_PAYLOAD_H264_FEC) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "Media_Payload_H261 <= payloadType <= Media_Payload_H264_FEC");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidParameters");
ptvcursor_add(cursor, hf_skinny_bitRate, 4, ENC_LITTLE_ENDIAN);
pictureFormatCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_pictureFormatCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_3 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "pictureFormat [ref: pictureFormatCount = %d, max:5]", pictureFormatCount);
for (counter_3 = 0; counter_3 < 5; counter_3++) {
if (counter_3 < pictureFormatCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "pictureFormat [%d / %d]", counter_3 + 1, pictureFormatCount);
ptvcursor_add(cursor, hf_skinny_format, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_MPI, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 8);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_confServiceNum, 4, ENC_LITTLE_ENDIAN);
if (payloadType == MEDIA_PAYLOAD_H261) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H261");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h261VideoCapability");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOffCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stillImageTransmission, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadType == MEDIA_PAYLOAD_H263) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H263");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263VideoCapability");
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263_capability_bitfield");
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit17, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit18, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit19, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit20, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit21, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit22, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit23, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit24, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit25, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit26, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit27, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit28, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit29, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit30, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit31, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit32, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_annexNandWFutureUse, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadType == MEDIA_PAYLOAD_H264) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H264");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h264VideoCapability");
ptvcursor_add(cursor, hf_skinny_profile, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_level, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxMBPS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxFS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxDPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxBRandCPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadType == MEDIA_PAYLOAD_VIEO) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_Vieo");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vieoVideoCapability");
ptvcursor_add(cursor, hf_skinny_modelNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bandwidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadType >= MEDIA_PAYLOAD_CLEAR_CHAN) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType >= Media_Payload_Clear_Chan");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataParameters");
ptvcursor_add(cursor, hf_skinny_protocolDependentData, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 36);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "mRxMediaEncryptionKeyInfo");
ptvcursor_add(cursor, hf_skinny_algorithmID, 4, ENC_LITTLE_ENDIAN);
keylen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_keylen, 2, ENC_LITTLE_ENDIAN);
saltlen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_saltlen, 2, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "key [ref: keylen = %d, max:16]", keylen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < keylen) {
ptvcursor_add(cursor, hf_skinny_key, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "salt [ref: saltlen = %d, max:16]", saltlen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < saltlen) {
ptvcursor_add(cursor, hf_skinny_salt, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_isMKIPresent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_keyDerivationRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_streamPassThroughID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_associatedStreamID, 4, ENC_LITTLE_ENDIAN);
if (hdr_version >= V11_MSG_TYPE) {
dissect_skinny_ipv4or6(cursor, hf_skinny_sourceIpAddr_ipv4, hf_skinny_sourceIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_sourcePortNumber, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V16_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_requestedIpAddrType, 4, ENC_LITTLE_ENDIAN);
}
}
static void
handle_StartMultiMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 compressionType = 0;
guint32 payloadType = 0;
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 pictureFormatCount = 0;
guint16 keylen = 0;
guint16 saltlen = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
compressionType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType");
ptvcursor_add(cursor, hf_skinny_payload_rfc_number, 4, ENC_LITTLE_ENDIAN);
payloadType = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_payloadType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_DSCPValue, 4, ENC_LITTLE_ENDIAN);
if (payloadType <= MEDIA_PAYLOAD_AMR_WB) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType <= Media_Payload_AMR_WB");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "audioParameters");
ptvcursor_add(cursor, hf_skinny_millisecondPacketSize, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "qualifierIn");
ptvcursor_add(cursor, hf_skinny_ecValue, 4, ENC_LITTLE_ENDIAN);
if (hdr_version <= V10_MSG_TYPE) {
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
}
if (hdr_version >= V11_MSG_TYPE) {
if (compressionType == MEDIA_PAYLOAD_G7231) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "compressionType is Media_Payload_G7231");
ptvcursor_add(cursor, hf_skinny_g723BitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any compressionType");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "codecParams");
ptvcursor_add(cursor, hf_skinny_codecMode, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_dynamicPayload, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam1, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_codecParam2, 1, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 28);
} else if (payloadType >= MEDIA_PAYLOAD_H261 && payloadType <= MEDIA_PAYLOAD_H264_FEC) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "Media_Payload_H261 <= payloadType <= Media_Payload_H264_FEC");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vidParameters");
ptvcursor_add(cursor, hf_skinny_bitRate, 4, ENC_LITTLE_ENDIAN);
pictureFormatCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_pictureFormatCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_3 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "pictureFormat [ref: pictureFormatCount = %d, max:5]", pictureFormatCount);
for (counter_3 = 0; counter_3 < 5; counter_3++) {
if (counter_3 < pictureFormatCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "pictureFormat [%d / %d]", counter_3 + 1, pictureFormatCount);
ptvcursor_add(cursor, hf_skinny_format, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_MPI, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 8);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_confServiceNum, 4, ENC_LITTLE_ENDIAN);
if (payloadType == MEDIA_PAYLOAD_H261) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H261");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h261VideoCapability");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOffCapability, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_stillImageTransmission, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadType == MEDIA_PAYLOAD_H263) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H263");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263VideoCapability");
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h263_capability_bitfield");
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit1, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit2, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit3, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit4, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit5, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit6, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit7, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit8, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit9, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit10, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit11, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit12, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit13, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit14, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit15, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit16, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit17, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit18, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit19, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit20, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit21, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit22, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit23, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit24, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit25, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit26, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit27, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit28, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit29, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit30, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit31, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_Generic_Bitfield_Bit32, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_annexNandWFutureUse, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
} else if (payloadType == MEDIA_PAYLOAD_H264) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_H264");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "h264VideoCapability");
ptvcursor_add(cursor, hf_skinny_profile, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_level, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxMBPS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxFS, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxDPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_customMaxBRandCPB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadType == MEDIA_PAYLOAD_VIEO) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType is Media_Payload_Vieo");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "vieoVideoCapability");
ptvcursor_add(cursor, hf_skinny_modelNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_bandwidth, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 16);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (payloadType >= MEDIA_PAYLOAD_CLEAR_CHAN) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "payloadType >= Media_Payload_Clear_Chan");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "dataParameters");
ptvcursor_add(cursor, hf_skinny_protocolDependentData, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 36);
}
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "mTxMediaEncryptionKeyInfo");
ptvcursor_add(cursor, hf_skinny_algorithmID, 4, ENC_LITTLE_ENDIAN);
keylen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_keylen, 2, ENC_LITTLE_ENDIAN);
saltlen = tvb_get_letohs(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_saltlen, 2, ENC_LITTLE_ENDIAN);
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "key [ref: keylen = %d, max:16]", keylen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < keylen) {
ptvcursor_add(cursor, hf_skinny_key, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
{
guint32 counter_2 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "salt [ref: saltlen = %d, max:16]", saltlen);
for (counter_2 = 0; counter_2 < 16; counter_2++) {
if (counter_2 < saltlen) {
ptvcursor_add(cursor, hf_skinny_salt, 1, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 1);
}
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_isMKIPresent, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_keyDerivationRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_streamPassThroughID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_associatedStreamID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StopMultiMediaTransmissionMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_portHandlingFlag, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_MiscellaneousCommandMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 command = 0;
guint32 recoveryReferencePictureCount = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
command = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_command, 4, ENC_LITTLE_ENDIAN);
if (command == MISCCOMMANDTYPE_VIDEOFASTUPDATEPICTURE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_videoFastUpdatePicture");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "videoFastUpdatePicture");
ptvcursor_add(cursor, hf_skinny_firstGOB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfGOBs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 8);
} else if (command == MISCCOMMANDTYPE_VIDEOFASTUPDATEGOB) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_videoFastUpdateGOB");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "videoFastUpdateGOB");
ptvcursor_add(cursor, hf_skinny_firstGOB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfGOBs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 8);
} else if (command == MISCCOMMANDTYPE_VIDEOFASTUPDATEMB) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_videoFastUpdateMB");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "videoFastUpdateMB");
ptvcursor_add(cursor, hf_skinny_firstGOB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_firstMB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfMBs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (command == MISCCOMMANDTYPE_LOSTPICTURE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_lostPicture");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "lostPicture");
ptvcursor_add(cursor, hf_skinny_pictureNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_longTermPictureIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 8);
} else if (command == MISCCOMMANDTYPE_LOSTPARTIALPICTURE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_lostPartialPicture");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "lostPartialPicture");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "pictureReference");
ptvcursor_add(cursor, hf_skinny_pictureNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_longTermPictureIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_firstMB, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfMBs, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
} else if (command == MISCCOMMANDTYPE_RECOVERYREFERENCEPICTURE) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_recoveryReferencePicture");
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "recoveryReferencePictureValue");
recoveryReferencePictureCount = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_recoveryReferencePictureCount, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_3 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "recoveryReferencePicture [ref: recoveryReferencePictureCount = %d, max:4]", recoveryReferencePictureCount);
for (counter_3 = 0; counter_3 < 4; counter_3++) {
if (counter_3 < recoveryReferencePictureCount) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "recoveryReferencePicture [%d / %d]", counter_3 + 1, recoveryReferencePictureCount);
ptvcursor_add(cursor, hf_skinny_pictureNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_longTermPictureIndex, 4, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 8);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 4);
} else if (command == MISCCOMMANDTYPE_TEMPORALSPATIALTRADEOFF) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "command is MiscCommandType_temporalSpatialTradeOff");
ptvcursor_add(cursor, hf_skinny_temporalSpatialTradeOff, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 12);
} else {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "any command");
ptvcursor_add(cursor, hf_skinny_none, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
ptvcursor_advance(cursor, 12);
}
}
static void
handle_FlowControlCommandMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maximumBitRate, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CloseMultiMediaReceiveChannelMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_portHandlingFlag, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CreateConferenceReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfReservedParticipants, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_resourceType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appConfID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appData, 24, ENC_ASCII|ENC_NA);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruData, dataLength, ENC_ASCII|ENC_NA);
}
static void
handle_DeleteConferenceReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ModifyConferenceReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfReservedParticipants, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appConfID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appData, 24, ENC_ASCII|ENC_NA);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruData, dataLength, ENC_ASCII|ENC_NA);
}
static void
handle_AddParticipantReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "partyPIRestrictionBits");
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_BitsReserved, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_participantName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_participantNumber, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_conferenceName, 32, ENC_ASCII|ENC_NA);
}
static void
handle_DropParticipantReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_AuditParticipantReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ChangeParticipantReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "partyPIRestrictionBits");
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_BitsReserved, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
ptvcursor_add(cursor, hf_skinny_participantName, 40, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_participantNumber, 24, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_conferenceName, 32, ENC_ASCII|ENC_NA);
}
static void
handle_UserToDeviceDataMessageVersion1(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 dataLength = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "userToDeviceDataVersion1");
ptvcursor_add(cursor, hf_skinny_applicationID, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
dataLength = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_dataLength, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_sequenceFlag, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_displayPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_appInstanceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_routingID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_xml(cursor, hf_skinny_xmldata, pinfo, dataLength, 2000);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_VideoDisplayCommandMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_layoutID, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_FlowControlNotifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passthruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maximumBitRate, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_ConfigStatV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 DeviceName_len = 0;
guint32 userName_len = 0;
guint32 serverName_len = 0;
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sid");
DeviceName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (DeviceName_len > 1) {
ptvcursor_add(cursor, hf_skinny_DeviceName, DeviceName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
ptvcursor_add(cursor, hf_skinny_reserved_for_future_use, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_instance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_numberOfLines, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_numberOfSpeedDials, 4, ENC_LITTLE_ENDIAN);
userName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (userName_len > 1) {
ptvcursor_add(cursor, hf_skinny_userName, userName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
serverName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (serverName_len > 1) {
ptvcursor_add(cursor, hf_skinny_serverName, serverName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
}
static void
handle_DisplayNotifyV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_notify, 0);
}
static void
handle_DisplayPriNotifyV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_priority, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_notify, 0);
}
static void
handle_DisplayPromptStatusV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_timeOutValue, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_displayLabel(cursor, hf_skinny_promptStatus, 0);
}
static void
handle_FeatureStatV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 featureTextLabel_len = 0;
ptvcursor_add(cursor, hf_skinny_featureIndex, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureStatus, 4, ENC_LITTLE_ENDIAN);
featureTextLabel_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (featureTextLabel_len > 1) {
ptvcursor_add(cursor, hf_skinny_featureTextLabel, featureTextLabel_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
}
static void
handle_LineStatV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 lineDirNumber_len = 0;
guint32 lineFullyQualifiedDisplayName_len = 0;
guint32 lineTextLabel_len = 0;
ptvcursor_add(cursor, hf_skinny_lineNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "lineType");
ptvcursor_add_no_advance(cursor, hf_skinny_OrigDialed, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RedirDialed, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_CallingPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_CallingPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
lineDirNumber_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lineDirNumber_len > 1) {
ptvcursor_add(cursor, hf_skinny_lineDirNumber, lineDirNumber_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
lineFullyQualifiedDisplayName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lineFullyQualifiedDisplayName_len > 1) {
ptvcursor_add(cursor, hf_skinny_lineFullyQualifiedDisplayName, lineFullyQualifiedDisplayName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
lineTextLabel_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lineTextLabel_len > 1) {
ptvcursor_add(cursor, hf_skinny_lineTextLabel, lineTextLabel_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
}
static void
handle_ServiceURLStatV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_serviceURLIndex, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SpeedDialStatV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 speedDialDirNumber_len = 0;
guint32 speedDialDisplayName_len = 0;
ptvcursor_add(cursor, hf_skinny_speedDialNumber, 4, ENC_LITTLE_ENDIAN);
speedDialDirNumber_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (speedDialDirNumber_len > 1) {
ptvcursor_add(cursor, hf_skinny_speedDialDirNumber, speedDialDirNumber_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
speedDialDisplayName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (speedDialDisplayName_len > 1) {
ptvcursor_add(cursor, hf_skinny_speedDialDisplayName, speedDialDisplayName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
}
static void
handle_CallInfoV2Message(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 hdr_version = tvb_get_letohl(ptvcursor_tvbuff(cursor), 4);
guint32 callingParty_len = 0;
guint32 AlternateCallingParty_len = 0;
guint32 calledParty_len = 0;
guint32 originalCalledParty_len = 0;
guint32 lastRedirectingParty_len = 0;
guint32 cgpnVoiceMailbox_len = 0;
guint32 cdpnVoiceMailbox_len = 0;
guint32 originalCdpnVoiceMailbox_len = 0;
guint32 lastRedirectingVoiceMailbox_len = 0;
guint32 callingPartyName_len = 0;
guint32 calledPartyName_len = 0;
guint32 originalCalledPartyName_len = 0;
guint32 lastRedirectingPartyName_len = 0;
guint32 HuntPilotNumber_len = 0;
guint32 HuntPilotName_len = 0;
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_callType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_originalCdpnRedirectReason, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_lastRedirectingReason, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_callInstance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_callSecurityStatus, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "partyPIRestrictionBits");
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CallingParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_CalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_OriginalCalledParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyName, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectPartyNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_LastRedirectParty, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor, hf_skinny_RestrictInformationType_BitsReserved, 4, ENC_LITTLE_ENDIAN);
ptvcursor_advance(cursor, 4);
ptvcursor_pop_subtree(cursor);
callingParty_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (callingParty_len > 1) {
si->callingParty = g_strdup(tvb_format_stringzpad(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), callingParty_len));
ptvcursor_add(cursor, hf_skinny_callingParty, callingParty_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
AlternateCallingParty_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (AlternateCallingParty_len > 1) {
ptvcursor_add(cursor, hf_skinny_AlternateCallingParty, AlternateCallingParty_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
calledParty_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (calledParty_len > 1) {
si->calledParty = g_strdup(tvb_format_stringzpad(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), calledParty_len));
ptvcursor_add(cursor, hf_skinny_calledParty, calledParty_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
originalCalledParty_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (originalCalledParty_len > 1) {
ptvcursor_add(cursor, hf_skinny_originalCalledParty, originalCalledParty_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
lastRedirectingParty_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lastRedirectingParty_len > 1) {
ptvcursor_add(cursor, hf_skinny_lastRedirectingParty, lastRedirectingParty_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
cgpnVoiceMailbox_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (cgpnVoiceMailbox_len > 1) {
ptvcursor_add(cursor, hf_skinny_cgpnVoiceMailbox, cgpnVoiceMailbox_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
cdpnVoiceMailbox_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (cdpnVoiceMailbox_len > 1) {
ptvcursor_add(cursor, hf_skinny_cdpnVoiceMailbox, cdpnVoiceMailbox_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
originalCdpnVoiceMailbox_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (originalCdpnVoiceMailbox_len > 1) {
ptvcursor_add(cursor, hf_skinny_originalCdpnVoiceMailbox, originalCdpnVoiceMailbox_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
lastRedirectingVoiceMailbox_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lastRedirectingVoiceMailbox_len > 1) {
ptvcursor_add(cursor, hf_skinny_lastRedirectingVoiceMailbox, lastRedirectingVoiceMailbox_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
callingPartyName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (callingPartyName_len > 1) {
ptvcursor_add(cursor, hf_skinny_callingPartyName, callingPartyName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
calledPartyName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (calledPartyName_len > 1) {
ptvcursor_add(cursor, hf_skinny_calledPartyName, calledPartyName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
originalCalledPartyName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (originalCalledPartyName_len > 1) {
ptvcursor_add(cursor, hf_skinny_originalCalledPartyName, originalCalledPartyName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
lastRedirectingPartyName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (lastRedirectingPartyName_len > 1) {
ptvcursor_add(cursor, hf_skinny_lastRedirectingPartyName, lastRedirectingPartyName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
if (hdr_version >= V17_MSG_TYPE) {
HuntPilotNumber_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (HuntPilotNumber_len > 1) {
ptvcursor_add(cursor, hf_skinny_HuntPilotNumber, HuntPilotNumber_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
HuntPilotName_len = tvb_strnlen(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor), -1)+1;
if (HuntPilotName_len > 1) {
ptvcursor_add(cursor, hf_skinny_HuntPilotName, HuntPilotName_len, ENC_ASCII|ENC_NA);
} else {
ptvcursor_advance(cursor, 1);
}
}
}
static void
handle_PortReqMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mediaTransportType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_ipAddressType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mediaType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_PortCloseMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_mediaType, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_QoSListenMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_resvStyle, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxRetryNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_retryTimer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_confirmRequired, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_preemptionPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_defendingPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_averageBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_burstSize, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_peakRate, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "appID");
ptvcursor_add(cursor, hf_skinny_vendorID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_version, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appName, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_subAppID, 32, ENC_ASCII|ENC_NA);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_QoSPathMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_resvStyle, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxRetryNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_retryTimer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_preemptionPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_defendingPriority, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_averageBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_burstSize, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_peakRate, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "appID");
ptvcursor_add(cursor, hf_skinny_vendorID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_version, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appName, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_subAppID, 32, ENC_ASCII|ENC_NA);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_QoSTeardownMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_direction, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_UpdateDSCPMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_DSCPValue, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_QoSModifyMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_remoteIpAddr_ipv4, hf_skinny_remoteIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_remotePortNumber, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_direction, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_compressionType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_averageBitRate, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_burstSize, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_peakRate, 4, ENC_LITTLE_ENDIAN);
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "appID");
ptvcursor_add(cursor, hf_skinny_vendorID, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_version, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_appName, 32, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_subAppID, 32, ENC_ASCII|ENC_NA);
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_SubscriptionStatMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_timer, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_cause, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_NotificationMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_transactionID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_featureID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_status, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_text, 97, ENC_ASCII|ENC_NA);
}
static void
handle_StartMediaTransmissionAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_transmitIpAddr_ipv4, hf_skinny_transmitIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_transmitPort, 4, ENC_LITTLE_ENDIAN);
si->startmediatransmisionStatus = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_startMediaTransmissionStatus, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_StartMultiMediaTransmissionAckMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_conferenceID, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_passThruPartyID, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
dissect_skinny_ipv4or6(cursor, hf_skinny_transmitIpAddr_ipv4, hf_skinny_transmitIpAddr_ipv6, pinfo);
ptvcursor_add(cursor, hf_skinny_transmitPort, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_resultCode, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_CallHistoryInfoMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_callHistoryDisposition, 4, ENC_LITTLE_ENDIAN);
si->lineId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineInstance, 4, ENC_LITTLE_ENDIAN);
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_LocationInfoMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_locationInfo, 2401, ENC_ASCII|ENC_NA);
}
static void
handle_MwiResponseMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_mwiTargetNumber, 25, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_mwi_notification_result, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_EnhancedAlarmMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
dissect_skinny_xml(cursor, hf_skinny_alarmInfo, pinfo, 0, 2048);
}
static void
handle_CallCountRespMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
guint32 lineDataEntries = 0;
ptvcursor_add(cursor, hf_skinny_totalNumOfConfiguredLines, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_startingLineInstance, 4, ENC_LITTLE_ENDIAN);
lineDataEntries = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_lineDataEntries, 4, ENC_LITTLE_ENDIAN);
{
guint32 counter_1 = 0;
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "lineData [ref: lineDataEntries = %d, max:42]", lineDataEntries);
for (counter_1 = 0; counter_1 < 42; counter_1++) {
if (counter_1 < lineDataEntries) {
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "lineData [%d / %d]", counter_1 + 1, lineDataEntries);
ptvcursor_add(cursor, hf_skinny_maxNumCalls, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_busyTrigger, 2, ENC_LITTLE_ENDIAN);
} else {
ptvcursor_advance(cursor, 4);
}
ptvcursor_pop_subtree(cursor);
}
ptvcursor_pop_subtree(cursor);
}
}
static void
handle_RecordingStatusMessage(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
si->callId = tvb_get_letohl(ptvcursor_tvbuff(cursor), ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_skinny_callReference, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_recording_status, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SPCPRegisterTokenReq(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
{
ptvcursor_add_text_with_subtree(cursor, SUBTREE_UNDEFINED_LENGTH, ett_skinny_tree, "sid");
ptvcursor_add(cursor, hf_skinny_DeviceName, 16, ENC_ASCII|ENC_NA);
ptvcursor_add(cursor, hf_skinny_reserved_for_future_use, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_instance, 4, ENC_LITTLE_ENDIAN);
ptvcursor_pop_subtree(cursor);
}
ptvcursor_add(cursor, hf_skinny_stationIpAddr, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_deviceType, 4, ENC_LITTLE_ENDIAN);
ptvcursor_add(cursor, hf_skinny_maxStreams, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SPCPRegisterTokenAck(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_features, 4, ENC_LITTLE_ENDIAN);
}
static void
handle_SPCPRegisterTokenReject(ptvcursor_t *cursor, packet_info * pinfo _U_)
{
ptvcursor_add(cursor, hf_skinny_waitTimeBeforeNextReq, 4, ENC_LITTLE_ENDIAN);
}
static int dissect_skinny_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
ptvcursor_t* cursor;
guint32 hdr_data_length;
guint32 hdr_version;
guint32 data_messageid;
guint16 i;
proto_tree *skinny_tree = NULL;
proto_item *ti = NULL;
hdr_data_length = tvb_get_letohl(tvb, 0);
hdr_version = tvb_get_letohl(tvb, 4);
data_messageid = tvb_get_letohl(tvb, 8);
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
si->openreceiveStatus = 0;
si->startmediatransmisionStatus = 0;
if (tree) {
ti = proto_tree_add_item(tree, proto_skinny, tvb, offset, hdr_data_length+8, ENC_NA);
skinny_tree = proto_item_add_subtree(ti, ett_skinny);
proto_tree_add_uint(skinny_tree, hf_skinny_data_length, tvb, offset, 4, hdr_data_length);
proto_tree_add_uint(skinny_tree, hf_skinny_hdr_version, tvb, offset+4, 4, hdr_version);
}
col_add_fstr(pinfo->cinfo, COL_INFO,"%s ", si->messageName);
col_set_fence(pinfo->cinfo, COL_INFO);
proto_tree_add_uint(skinny_tree, hf_skinny_messageId, tvb,offset+8, 4, data_messageid );
offset += 12;
cursor = ptvcursor_new(skinny_tree, tvb, offset);
for (i = 0; i < sizeof(skinny_opcode2handler)/sizeof(struct opcode2handler) ; i++) {
if (skinny_opcode2handler[i].opcode == data_messageid && skinny_opcode2handler[i].handler) {
skinny_opcode2handler[i].handler(cursor, pinfo);
}
}
ptvcursor_free(cursor);
tap_queue_packet(skinny_tap, pinfo, si);
return tvb_captured_length(tvb);
}
static int
dissect_skinny(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint32 hdr_data_length;
guint32 hdr_version;
if (tvb_captured_length(tvb) < 8)
{
return 0;
}
hdr_data_length = tvb_get_letohl(tvb, 0);
hdr_version = tvb_get_letohl(tvb, 4);
if (
(hdr_data_length < 4) ||
((hdr_version != BASIC_MSG_TYPE) &&
(hdr_version != V10_MSG_TYPE) &&
(hdr_version != V11_MSG_TYPE) &&
(hdr_version != V15_MSG_TYPE) &&
(hdr_version != V16_MSG_TYPE) &&
(hdr_version != V17_MSG_TYPE) &&
(hdr_version != V18_MSG_TYPE) &&
(hdr_version != V19_MSG_TYPE) &&
(hdr_version != V20_MSG_TYPE) &&
(hdr_version != V21_MSG_TYPE) &&
(hdr_version != V22_MSG_TYPE))
)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SKINNY");
col_set_str(pinfo->cinfo, COL_INFO, "Skinny Client Control Protocol");
tcp_dissect_pdus(tvb, pinfo, tree, skinny_desegment, 4, get_skinny_pdu_len, dissect_skinny_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_skinny(void)
{
static hf_register_info hf[] = {
{ &hf_skinny_data_length,
{
"Data length", "skinny.data_length", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of bytes in the data portion.", HFILL }},
{ &hf_skinny_hdr_version,
{
"Header version", "skinny.hdr_version", FT_UINT32, BASE_HEX, VALS(header_version), 0x0,
NULL, HFILL }},
{ &hf_skinny_messageId,
{
"Message ID", "skinny.messageId", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &message_id_ext, 0x0,
NULL, HFILL }},
{ &hf_skinny_xmlData,
{
"XML data", "skinny.xmlData", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_ipv4or6,
{
"IPv4or6", "skinny.ipv4or6", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &IpAddrType_ext, 0x0,
NULL, HFILL }},
{ &hf_skinny_CallingPartyName,
{
"CallingName", "skinny.CallingPartyName", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }},
{ &hf_skinny_CallingPartyNumber,
{
"CallingNum", "skinny.CallingPartyNumber", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }},
{ &hf_skinny_DSCPValue,
{
"DSCPValue", "skinny.DSCPValue", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_FutureUse1,
{
"FutureUse1", "skinny.FutureUse1", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_FutureUse2,
{
"FutureUse2", "skinny.FutureUse2", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_FutureUse3,
{
"FutureUse3", "skinny.FutureUse3", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit1,
{
"Bit1", "skinny.Generic.Bitfield.Bit1", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit10,
{
"Bit10", "skinny.Generic.Bitfield.Bit10", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0200,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit11,
{
"Bit11", "skinny.Generic.Bitfield.Bit11", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0400,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit12,
{
"Bit12", "skinny.Generic.Bitfield.Bit12", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0800,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit13,
{
"Bit13", "skinny.Generic.Bitfield.Bit13", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x1000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit14,
{
"Bit14", "skinny.Generic.Bitfield.Bit14", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x2000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit15,
{
"Bit14", "skinny.Generic.Bitfield.Bit15", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x4000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit16,
{
"Bit15", "skinny.Generic.Bitfield.Bit16", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x8000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit17,
{
"Bit17", "skinny.Generic.Bitfield.Bit17", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x10000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit18,
{
"Bit18", "skinny.Generic.Bitfield.Bit18", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x20000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit19,
{
"Bit19", "skinny.Generic.Bitfield.Bit19", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x40000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit2,
{
"Bit2", "skinny.Generic.Bitfield.Bit2", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit20,
{
"Bit20", "skinny.Generic.Bitfield.Bit20", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x80000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit21,
{
"Bit21", "skinny.Generic.Bitfield.Bit21", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x100000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit22,
{
"Bit22", "skinny.Generic.Bitfield.Bit22", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x200000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit23,
{
"Bit23", "skinny.Generic.Bitfield.Bit23", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x400000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit24,
{
"Bit24", "skinny.Generic.Bitfield.Bit24", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x800000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit25,
{
"Bit25", "skinny.Generic.Bitfield.Bit25", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x1000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit26,
{
"Bit26", "skinny.Generic.Bitfield.Bit26", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x2000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit27,
{
"Bit27", "skinny.Generic.Bitfield.Bit27", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x4000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit28,
{
"Bit28", "skinny.Generic.Bitfield.Bit28", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x8000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit29,
{
"Bit29", "skinny.Generic.Bitfield.Bit29", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x10000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit3,
{
"Bit3", "skinny.Generic.Bitfield.Bit3", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit30,
{
"Bit30", "skinny.Generic.Bitfield.Bit30", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x20000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit31,
{
"Bit31", "skinny.Generic.Bitfield.Bit31", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x40000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit32,
{
"Bit32", "skinny.Generic.Bitfield.Bit32", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x80000000,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit4,
{
"Bit4", "skinny.Generic.Bitfield.Bit4", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit5,
{
"Bit5", "skinny.Generic.Bitfield.Bit5", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0010,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit6,
{
"Bit6", "skinny.Generic.Bitfield.Bit6", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0020,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit7,
{
"Bit7", "skinny.Generic.Bitfield.Bit7", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0040,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit8,
{
"Bit8", "skinny.Generic.Bitfield.Bit8", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0080,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_Generic_Bitfield_Bit9,
{
"Bit9", "skinny.Generic.Bitfield.Bit9", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0100,
"H263 Capability BitField", HFILL }},
{ &hf_skinny_MPI,
{
"MPI", "skinny.MPI", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_OrigDialed,
{
"Originaly Dialed", "skinny.OrigDialed", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }},
{ &hf_skinny_PhoneFeatures_Abbreviated_Dial,
{
"AbbrevDial", "skinny.PhoneFeatures.Abbreviated.Dial", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit1,
{
"Bit1", "skinny.PhoneFeatures.Bit1", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0001,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit11,
{
"Bit11", "skinny.PhoneFeatures.Bit11", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0400,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit12,
{
"Bit12", "skinny.PhoneFeatures.Bit12", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0800,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit13,
{
"Bit13", "skinny.PhoneFeatures.Bit13", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x1000,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit14,
{
"Bit14", "skinny.PhoneFeatures.Bit14", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x2000,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit15,
{
"Bit15", "skinny.PhoneFeatures.Bit15", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x4000,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit2,
{
"Bit2", "skinny.PhoneFeatures.Bit2", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0002,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit3,
{
"Bit3", "skinny.PhoneFeatures.Bit3", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0004,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit4,
{
"Bit4", "skinny.PhoneFeatures.Bit4", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0008,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit6,
{
"Bit6", "skinny.PhoneFeatures.Bit6", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0020,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit7,
{
"Bit7", "skinny.PhoneFeatures.Bit7", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0040,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_Bit9,
{
"Bit9", "skinny.PhoneFeatures.Bit9", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_DynamicMessages,
{
"DynamicMessages", "skinny.PhoneFeatures.DynamicMessages", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_RFC2833,
{
"RFC2833", "skinny.PhoneFeatures.RFC2833", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
"Features this device supports", HFILL }},
{ &hf_skinny_PhoneFeatures_UTF8,
{
"UTF8Bit5", "skinny.PhoneFeatures.UTF8", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0010,
"Features this device supports", HFILL }},
{ &hf_skinny_RFC2833PayloadType,
{
"RFC2833PayloadType", "skinny.RFC2833PayloadType", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_RTCPPortNumber,
{
"RTCPPortNumber", "skinny.RTCPPortNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_RTPPayloadFormat,
{
"RTPPayloadFormat", "skinny.RTPPayloadFormat", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_RedirDialed,
{
"Redirected Dialed", "skinny.RedirDialed", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_BitsReserved,
{
"BitsReserved", "skinny.RestrictInformationType.BitsReserved", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0xffffff00,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CalledParty,
{
"CalledParty", "skinny.RestrictInformationType.CalledParty", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x000c,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CalledPartyName,
{
"CalledPartyName", "skinny.RestrictInformationType.CalledPartyName", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CalledPartyNumber,
{
"CalledPartyNumber", "skinny.RestrictInformationType.CalledPartyNumber", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CallingParty,
{
"CallingParty", "skinny.RestrictInformationType.CallingParty", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0003,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CallingPartyName,
{
"CallingPartyName", "skinny.RestrictInformationType.CallingPartyName", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_CallingPartyNumber,
{
"CallingPartyNumber", "skinny.RestrictInformationType.CallingPartyNumber", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_LastRedirectParty,
{
"LastRedirectParty", "skinny.RestrictInformationType.LastRedirectParty", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00c0,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_LastRedirectPartyName,
{
"LastRedirectPartyName", "skinny.RestrictInformationType.LastRedirectPartyName", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_LastRedirectPartyNumber,
{
"LastRedirectPartyNumber", "skinny.RestrictInformationType.LastRedirectPartyNumber", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_OriginalCalledParty,
{
"OriginalCalledParty", "skinny.RestrictInformationType.OriginalCalledParty", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0030,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_OriginalCalledPartyName,
{
"OriginalCalledPartyName", "skinny.RestrictInformationType.OriginalCalledPartyName", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0010,
NULL, HFILL }},
{ &hf_skinny_RestrictInformationType_OriginalCalledPartyNumber,
{
"OriginalCalledPartyNumber", "skinny.RestrictInformationType.OriginalCalledPartyNumber", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0020,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey1,
{
"SoftKey1", "skinny.SoftKeyMask.SoftKey1", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey10,
{
"SoftKey10", "skinny.SoftKeyMask.SoftKey10", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey11,
{
"SoftKey11", "skinny.SoftKeyMask.SoftKey11", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey12,
{
"SoftKey12", "skinny.SoftKeyMask.SoftKey12", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0800,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey13,
{
"SoftKey13", "skinny.SoftKeyMask.SoftKey13", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x1000,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey14,
{
"SoftKey14", "skinny.SoftKeyMask.SoftKey14", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x2000,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey15,
{
"SoftKey15", "skinny.SoftKeyMask.SoftKey15", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x4000,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey16,
{
"SoftKey16", "skinny.SoftKeyMask.SoftKey16", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey2,
{
"SoftKey2", "skinny.SoftKeyMask.SoftKey2", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey3,
{
"SoftKey3", "skinny.SoftKeyMask.SoftKey3", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey4,
{
"SoftKey4", "skinny.SoftKeyMask.SoftKey4", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey5,
{
"SoftKey5", "skinny.SoftKeyMask.SoftKey5", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0010,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey6,
{
"SoftKey6", "skinny.SoftKeyMask.SoftKey6", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0020,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey7,
{
"SoftKey7", "skinny.SoftKeyMask.SoftKey7", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey8,
{
"SoftKey8", "skinny.SoftKeyMask.SoftKey8", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_skinny_SoftKeyMask_SoftKey9,
{
"SoftKey9", "skinny.SoftKeyMask.SoftKey9", FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_skinny_active,
{
"active", "skinny.active", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_activeConferenceOnRegistration,
{
"Active Conference", "skinny.activeConferenceOnRegistration", FT_UINT32, BASE_DEC, NULL, 0x0,
"Active conference at Registration", HFILL }},
{ &hf_skinny_activeConferences,
{
"Active Conferences", "skinny.activeConferences", FT_UINT32, BASE_DEC, NULL, 0x0,
"Active Conferences at Registration", HFILL }},
{ &hf_skinny_activeForward,
{
"activeForward", "skinny.activeForward", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_activeStreams,
{
"Active RTP Streams", "skinny.activeStreams", FT_UINT32, BASE_DEC, NULL, 0x0,
"Active RTP Streams at Registration", HFILL }},
{ &hf_skinny_activeStreamsOnRegistration,
{
"activeStreamsOnRegistration", "skinny.activeStreamsOnRegistration", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_alarmInfo,
{
"alarmInfo", "skinny.alarmInfo", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_alignmentPadding,
{
"alignmentPadding", "skinny.alignmentPadding", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_annexNandWFutureUse,
{
"annexNandWFutureUse", "skinny.annexNandWFutureUse", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_appID,
{
"appID", "skinny.appID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_appInstanceID,
{
"appInstanceID", "skinny.appInstanceID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_applicationID,
{
"applicationID", "skinny.applicationID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_areMessagesWaiting,
{
"areMessagesWaiting", "skinny.areMessagesWaiting", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_associatedStreamID,
{
"associatedStreamID", "skinny.associatedStreamID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_audioCapCount,
{
"audioCapCount", "skinny.audioCapCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_audioLevelAdjustment,
{
"audioLevelAdjustment", "skinny.audioLevelAdjustment", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_averageBitRate,
{
"averageBitRate", "skinny.averageBitRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_bandwidth,
{
"bandwidth", "skinny.bandwidth", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_bitRate,
{
"bitRate", "skinny.bitRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_burstSize,
{
"burstSize", "skinny.burstSize", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_busyTrigger,
{
"busyTrigger", "skinny.busyTrigger", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_buttonCount,
{
"buttonCount", "skinny.buttonCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_buttonOffset,
{
"buttonOffset", "skinny.buttonOffset", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_callInstance,
{
"callInstance", "skinny.callInstance", FT_UINT32, BASE_DEC, NULL, 0x0,
"CallId", HFILL }},
{ &hf_skinny_callReference,
{
"callReference", "skinny.callReference", FT_UINT32, BASE_DEC, NULL, 0x0,
"CallId", HFILL }},
{ &hf_skinny_callSelectStat,
{
"callSelectStat", "skinny.callSelectStat", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_capAndVer,
{
"capAndVer", "skinny.capAndVer", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_capCount,
{
"capCount", "skinny.capCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_chan0MaxPayload,
{
"chan0MaxPayload", "skinny.chan0MaxPayload", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_chan2MaxPayload,
{
"chan2MaxPayload", "skinny.chan2MaxPayload", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_chan2MaxWindow,
{
"chan2MaxWindow", "skinny.chan2MaxWindow", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_chan3MaxPayload,
{
"chan3MaxPayload", "skinny.chan3MaxPayload", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_clockConversionCode,
{
"clockConversionCode", "skinny.clockConversionCode", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_clockDivisor,
{
"clockDivisor", "skinny.clockDivisor", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_codecMode,
{
"codecMode", "skinny.codecMode", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_codecParam1,
{
"codecParam1", "skinny.codecParam1", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_codecParam2,
{
"codecParam2", "skinny.codecParam2", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_confServiceNum,
{
"confServiceNum", "skinny.confServiceNum", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_conferenceID,
{
"conferenceID", "skinny.conferenceID", FT_UINT32, BASE_DEC, NULL, 0x0,
"Conference ID", HFILL }},
{ &hf_skinny_confirmRequired,
{
"confirmRequired", "skinny.confirmRequired", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_country,
{
"country", "skinny.country", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_customMaxBRandCPB,
{
"customMaxBRandCPB", "skinny.customMaxBRandCPB", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_customMaxDPB,
{
"customMaxDPB", "skinny.customMaxDPB", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_customMaxFS,
{
"customMaxFS", "skinny.customMaxFS", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_customMaxMBPS,
{
"customMaxMBPS", "skinny.customMaxMBPS", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_customPictureFormatCount,
{
"customPictureFormatCount", "skinny.customPictureFormatCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_dataCapCount,
{
"dataCapCount", "skinny.dataCapCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_dataLength,
{
"dataLength", "skinny.dataLength", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_dataSize,
{
"dataSize", "skinny.dataSize", FT_UINT32, BASE_DEC, NULL, 0x0,
"Data Size", HFILL }},
{ &hf_skinny_defendingPriority,
{
"defendingPriority", "skinny.defendingPriority", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_displayPriority,
{
"displayPriority", "skinny.displayPriority", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_dtmfType,
{
"dtmfType", "skinny.dtmfType", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_dynamicPayload,
{
"dynamicPayload", "skinny.dynamicPayload", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_failureNodeIpAddr,
{
"failureNodeIpAddr", "skinny.failureNodeIpAddr", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_featureCapabilities,
{
"featureCapabilities", "skinny.featureCapabilities", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_featureIndex,
{
"featureIndex", "skinny.featureIndex", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_featureStatus,
{
"featureStatus", "skinny.featureStatus", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_features,
{
"features", "skinny.features", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_firstGOB,
{
"firstGOB", "skinny.firstGOB", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_firstMB,
{
"firstMB", "skinny.firstMB", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_format,
{
"format", "skinny.format", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_forwardAllActive,
{
"forwardAllActive", "skinny.forwardAllActive", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_forwardBusyActive,
{
"forwardBusyActive", "skinny.forwardBusyActive", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_forwardNoAnswerActive,
{
"forwardNoAnswerActive", "skinny.forwardNoAnswerActive", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_hearingConfPartyMask,
{
"hearingConfPartyMask", "skinny.hearingConfPartyMask", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_instance,
{
"instance", "skinny.instance", FT_UINT32, BASE_DEC, NULL, 0x0,
"Device Instance", HFILL }},
{ &hf_skinny_instanceNumber,
{
"instanceNumber", "skinny.instanceNumber", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_ipAddr_ipv4,
{
"ipAddr IPv4 Address", "skinny.ipAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_ipAddr_ipv6,
{
"ipAddr IPv6 Address", "skinny.ipAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_ipV4AddressScope,
{
"ipV4AddressScope", "skinny.ipV4AddressScope", FT_UINT32, BASE_DEC, NULL, 0x0,
"IPv4 Address Scope", HFILL }},
{ &hf_skinny_ipV6AddressScope,
{
"ipV6AddressScope", "skinny.ipV6AddressScope", FT_UINT32, BASE_DEC, NULL, 0x0,
"IPv6 Address Scope", HFILL }},
{ &hf_skinny_isConferenceCreator,
{
"isConferenceCreator", "skinny.isConferenceCreator", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_isMKIPresent,
{
"isMKIPresent", "skinny.isMKIPresent", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_jitter,
{
"jitter", "skinny.jitter", FT_UINT32, BASE_DEC, NULL, 0x0,
"Amount of Jitter", HFILL }},
{ &hf_skinny_keepAliveInterval,
{
"keepAliveInterval", "skinny.keepAliveInterval", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_key,
{
"key", "skinny.key", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_keyDerivationRate,
{
"keyDerivationRate", "skinny.keyDerivationRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_keylen,
{
"keylen", "skinny.keylen", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_last,
{
"last", "skinny.last", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_lastRedirectingReason,
{
"lastRedirectingReason", "skinny.lastRedirectingReason", FT_UINT32, BASE_DEC, NULL, 0x0,
"Last Redirecting Reason", HFILL }},
{ &hf_skinny_latency,
{
"latency", "skinny.latency", FT_UINT32, BASE_DEC, NULL, 0x0,
"Amount of Latency", HFILL }},
{ &hf_skinny_layoutCount,
{
"layoutCount", "skinny.layoutCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_layoutID,
{
"layoutID", "skinny.layoutID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_level,
{
"level", "skinny.level", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_levelPreferenceCount,
{
"levelPreferenceCount", "skinny.levelPreferenceCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_lineDataEntries,
{
"lineDataEntries", "skinny.lineDataEntries", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Line Data Entries", HFILL }},
{ &hf_skinny_lineDisplayOptions,
{
"lineDisplayOptions", "skinny.lineDisplayOptions", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_lineInstance,
{
"lineInstance", "skinny.lineInstance", FT_UINT32, BASE_DEC, NULL, 0x0,
"LineId", HFILL }},
{ &hf_skinny_lineNumber,
{
"lineNumber", "skinny.lineNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_locale,
{
"locale", "skinny.locale", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_longTermPictureIndex,
{
"longTermPictureIndex", "skinny.longTermPictureIndex", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_macAddress,
{
"Mac Address", "skinny.macAddress", FT_ETHER, BASE_NONE, NULL, 0x0,
"Ethernet/Mac Address", HFILL }},
{ &hf_skinny_matrixConfPartyID,
{
"matrixConfPartyID", "skinny.matrixConfPartyID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxBW,
{
"maxBW", "skinny.maxBW", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxBitRate,
{
"maxBitRate", "skinny.maxBitRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxConferences,
{
"Maximum Number of Concurrent Conferences", "skinny.maxConferences", FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the maximum number of simultansous Conferences, which this client/appliance can handle", HFILL }},
{ &hf_skinny_maxFramesPerPacket,
{
"maxFramesPerPacket", "skinny.maxFramesPerPacket", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxNumCalls,
{
"maxNumCalls", "skinny.maxNumCalls", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxNumOfAvailLines,
{
"maxNumOfAvailLines", "skinny.maxNumOfAvailLines", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxNumberOfLines,
{
"maxNumberOfLines", "skinny.maxNumberOfLines", FT_UINT32, BASE_DEC, NULL, 0x0,
"Maximum number of lines", HFILL }},
{ &hf_skinny_maxProtocolVer,
{
"maxProtocolVer", "skinny.maxProtocolVer", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxRetryNumber,
{
"maxRetryNumber", "skinny.maxRetryNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maxStreams,
{
"Maximum Number of Concurrent RTP Streams", "skinny.maxStreams", FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the maximum number of simultansous RTP duplex streams, which this client/appliance can handle.", HFILL }},
{ &hf_skinny_maxStreamsPerConf,
{
"maxStreamsPerConf", "skinny.maxStreamsPerConf", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_maximumBitRate,
{
"maximumBitRate", "skinny.maximumBitRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_millisecondPacketSize,
{
"millisecondPacketSize", "skinny.millisecondPacketSize", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_minBitRate,
{
"minBitRate", "skinny.minBitRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_mixingMode,
{
"mixingMode", "skinny.mixingMode", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_modAnd2833,
{
"modAnd2833", "skinny.modAnd2833", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_modelNumber,
{
"modelNumber", "skinny.modelNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_multicastIpAddr_ipv4,
{
"multicastIpAddr IPv4 Address", "skinny.multicastIpAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_multicastIpAddr_ipv6,
{
"multicastIpAddr IPv6 Address", "skinny.multicastIpAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_multicastPortNumber,
{
"multicastPortNumber", "skinny.multicastPortNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_noaudio,
{
"noaudio", "skinny.noaudio", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_none,
{
"none", "skinny.none", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_nse,
{
"nse", "skinny.nse", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numNewMsgs,
{
"numNewMsgs", "skinny.numNewMsgs", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numOldMsgs,
{
"numOldMsgs", "skinny.numOldMsgs", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOctetsReceived,
{
"numberOctetsReceived", "skinny.numberOctetsReceived", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Octets Received", HFILL }},
{ &hf_skinny_numberOctetsSent,
{
"numberOctetsSent", "skinny.numberOctetsSent", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Octets Sent", HFILL }},
{ &hf_skinny_numberOfActiveParticipants,
{
"numberOfActiveParticipants", "skinny.numberOfActiveParticipants", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfEntries,
{
"numberOfEntries", "skinny.numberOfEntries", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfGOBs,
{
"numberOfGOBs", "skinny.numberOfGOBs", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfInServiceStreams,
{
"numberOfInServiceStreams", "skinny.numberOfInServiceStreams", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfLines,
{
"numberOfLines", "skinny.numberOfLines", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfMBs,
{
"numberOfMBs", "skinny.numberOfMBs", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfOutOfServiceStreams,
{
"numberOfOutOfServiceStreams", "skinny.numberOfOutOfServiceStreams", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfReservedParticipants,
{
"numberOfReservedParticipants", "skinny.numberOfReservedParticipants", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberOfSpeedDials,
{
"numberOfSpeedDials", "skinny.numberOfSpeedDials", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_numberPacketsLost,
{
"numberPacketsLost", "skinny.numberPacketsLost", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Packets Lost", HFILL }},
{ &hf_skinny_numberPacketsReceived,
{
"numberPacketsReceived", "skinny.numberPacketsReceived", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Packets Received", HFILL }},
{ &hf_skinny_numberPacketsSent,
{
"numberPacketsSent", "skinny.numberPacketsSent", FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of Packets Sent", HFILL }},
{ &hf_skinny_originalCdpnRedirectReason,
{
"originalCdpnRedirectReason", "skinny.originalCdpnRedirectReason", FT_UINT32, BASE_DEC, NULL, 0x0,
"Original Called Party Redirect Reason", HFILL }},
{ &hf_skinny_padding,
{
"padding", "skinny.padding", FT_UINT16, BASE_DEC, NULL, 0x0,
"Unused/Padding", HFILL }},
{ &hf_skinny_parm1,
{
"parm1", "skinny.parm1", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_parm2,
{
"parm2", "skinny.parm2", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_participantEntry,
{
"participantEntry", "skinny.participantEntry", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_partyDirection,
{
"partyDirection", "skinny.partyDirection", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_passThruPartyID,
{
"passThruPartyID", "skinny.passThruPartyID", FT_UINT32, BASE_DEC, NULL, 0x0,
"PassThrough PartyId", HFILL }},
{ &hf_skinny_passthruPartyID,
{
"passthruPartyID", "skinny.passthruPartyID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_payloadDtmf,
{
"payloadDtmf", "skinny.payloadDtmf", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_payloadType,
{
"payloadType", "skinny.payloadType", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_payload_rfc_number,
{
"payload_rfc_number", "skinny.payload.rfc.number", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_peakRate,
{
"peakRate", "skinny.peakRate", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_pictureFormatCount,
{
"pictureFormatCount", "skinny.pictureFormatCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_pictureHeight,
{
"pictureHeight", "skinny.pictureHeight", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_pictureNumber,
{
"pictureNumber", "skinny.pictureNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_pictureWidth,
{
"pictureWidth", "skinny.pictureWidth", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_pixelAspectRatio,
{
"pixelAspectRatio", "skinny.pixelAspectRatio", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_portNumber,
{
"portNumber", "skinny.portNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_precedenceDomain,
{
"precedenceDomain", "skinny.precedenceDomain", FT_UINT32, BASE_DEC, NULL, 0x0,
"Precendence Domain", HFILL }},
{ &hf_skinny_precedenceLevel,
{
"precedenceLevel", "skinny.precedenceLevel", FT_UINT32, BASE_DEC, NULL, 0x0,
"Precendence Level, MLPP priorities", HFILL }},
{ &hf_skinny_precedenceValue,
{
"precedenceValue", "skinny.precedenceValue", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_preemptionPriority,
{
"preemptionPriority", "skinny.preemptionPriority", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_priority,
{
"priority", "skinny.priority", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_profile,
{
"profile", "skinny.profile", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_protocolDependentData,
{
"protocolDependentData", "skinny.protocolDependentData", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_protocolVer,
{
"Protocol Version", "skinny.protocolVer", FT_UINT8, BASE_DEC, NULL, 0x0,
"Maximum Supported Protocol Version", HFILL }},
{ &hf_skinny_recoveryReferencePictureCount,
{
"recoveryReferencePictureCount", "skinny.recoveryReferencePictureCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_remoteIpAddr_ipv4,
{
"remoteIpAddr IPv4 Address", "skinny.remoteIpAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_remoteIpAddr_ipv6,
{
"remoteIpAddr IPv6 Address", "skinny.remoteIpAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_remotePortNumber,
{
"remotePortNumber", "skinny.remotePortNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_reserved_for_future_use,
{
"reserved_for_future_use", "skinny.reserved.for.future.use", FT_UINT32, BASE_DEC, NULL, 0x0,
"User Id", HFILL }},
{ &hf_skinny_retryTimer,
{
"retryTimer", "skinny.retryTimer", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_rfc2833,
{
"rfc2833", "skinny.rfc2833", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_routingID,
{
"routingID", "skinny.routingID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_rsvpErrorFlag,
{
"rsvpErrorFlag", "skinny.rsvpErrorFlag", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_rsvpErrorSubCodeVal,
{
"rsvpErrorSubCodeVal", "skinny.rsvpErrorSubCodeVal", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_rtpMediaPort,
{
"rtpMediaPort", "skinny.rtpMediaPort", FT_UINT32, BASE_DEC, NULL, 0x0,
"RTP Media Port", HFILL }},
{ &hf_skinny_salt,
{
"salt", "skinny.salt", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_saltlen,
{
"saltlen", "skinny.saltlen", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_secondaryKeepAliveInterval,
{
"secondaryKeepAliveInterval", "skinny.secondaryKeepAliveInterval", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_serverTcpListenPort,
{
"serverTcpListenPort", "skinny.serverTcpListenPort", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_serviceNum,
{
"serviceNum", "skinny.serviceNum", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_serviceNumber,
{
"serviceNumber", "skinny.serviceNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_serviceResourceCount,
{
"serviceResourceCount", "skinny.serviceResourceCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_serviceURLIndex,
{
"serviceURLIndex", "skinny.serviceURLIndex", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_softKeyCount,
{
"softKeyCount", "skinny.softKeyCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_softKeyOffset,
{
"softKeyOffset", "skinny.softKeyOffset", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_softKeySetCount,
{
"softKeySetCount", "skinny.softKeySetCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_softKeySetOffset,
{
"softKeySetOffset", "skinny.softKeySetOffset", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_sourceIpAddr_ipv4,
{
"sourceIpAddr IPv4 Address", "skinny.sourceIpAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_sourceIpAddr_ipv6,
{
"sourceIpAddr IPv6 Address", "skinny.sourceIpAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_sourcePortNumber,
{
"sourcePortNumber", "skinny.sourcePortNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_speedDialNumber,
{
"speedDialNumber", "skinny.speedDialNumber", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_sse,
{
"sse", "skinny.sse", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_standard,
{
"standard", "skinny.standard", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_startingLineInstance,
{
"startingLineInstance", "skinny.startingLineInstance", FT_UINT32, BASE_DEC, NULL, 0x0,
"Starting Line Instance", HFILL }},
{ &hf_skinny_stationIpAddr,
{
"stationIpAddr", "skinny.stationIpAddr", FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv4 Address", HFILL }},
{ &hf_skinny_stationIpAddr_ipv4,
{
"stationIpAddr IPv4 Address", "skinny.stationIpAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_stationIpAddr_ipv6,
{
"stationIpAddr IPv6 Address", "skinny.stationIpAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_stationIpV6Addr,
{
"stationIpV6Addr", "skinny.stationIpV6Addr", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 Address", HFILL }},
{ &hf_skinny_stationIpV6Addr_ipv4,
{
"stationIpV6Addr IPv4 Address", "skinny.stationIpV6Addr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_stationIpV6Addr_ipv6,
{
"stationIpV6Addr IPv6 Address", "skinny.stationIpV6Addr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_stillImageTransmission,
{
"stillImageTransmission", "skinny.stillImageTransmission", FT_UINT32, BASE_DEC, NULL, 0x0,
"Still Image Transmission", HFILL }},
{ &hf_skinny_stimulusInstance,
{
"stimulusInstance", "skinny.stimulusInstance", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_stimulusStatus,
{
"stimulusStatus", "skinny.stimulusStatus", FT_UINT32, BASE_DEC, NULL, 0x0,
"Stimulus Status", HFILL }},
{ &hf_skinny_streamPassThroughID,
{
"streamPassThroughID", "skinny.streamPassThroughID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_systemTime,
{
"systemTime", "skinny.systemTime", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_temporalSpatialTradeOff,
{
"temporalSpatialTradeOff", "skinny.temporalSpatialTradeOff", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_temporalSpatialTradeOffCapability,
{
"temporalSpatialTradeOffCapability", "skinny.temporalSpatialTradeOffCapability", FT_UINT32, BASE_DEC, NULL, 0x0,
"Temporal spatial trade off capability", HFILL }},
{ &hf_skinny_timeOutValue,
{
"timeOutValue", "skinny.timeOutValue", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_timer,
{
"timer", "skinny.timer", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_totalButtonCount,
{
"totalButtonCount", "skinny.totalButtonCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_totalNumOfConfiguredLines,
{
"totalNumOfConfiguredLines", "skinny.totalNumOfConfiguredLines", FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Number of Configured Lines", HFILL }},
{ &hf_skinny_totalSoftKeyCount,
{
"totalSoftKeyCount", "skinny.totalSoftKeyCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_totalSoftKeySetCount,
{
"totalSoftKeySetCount", "skinny.totalSoftKeySetCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_transactionID,
{
"transactionID", "skinny.transactionID", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_transmitIpAddr_ipv4,
{
"transmitIpAddr IPv4 Address", "skinny.transmitIpAddr.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_transmitIpAddr_ipv6,
{
"transmitIpAddr IPv6 Address", "skinny.transmitIpAddr.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"ipaddress in big endian", HFILL }},
{ &hf_skinny_transmitPort,
{
"transmitPort", "skinny.transmitPort", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_transmitPreference,
{
"transmitPreference", "skinny.transmitPreference", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_unknown,
{
"unknown", "skinny.unknown", FT_UINT8, BASE_DEC, NULL, 0x0,
"unknown (Part of ProtocolVer)", HFILL }},
{ &hf_skinny_v150sprt,
{
"v150sprt", "skinny.v150sprt", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_vendor,
{
"vendor", "skinny.vendor", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_videoCapCount,
{
"videoCapCount", "skinny.videoCapCount", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wDay,
{
"wDay", "skinny.wDay", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wDayOfWeek,
{
"wDayOfWeek", "skinny.wDayOfWeek", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wHour,
{
"wHour", "skinny.wHour", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wMilliseconds,
{
"wMilliseconds", "skinny.wMilliseconds", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wMinute,
{
"wMinute", "skinny.wMinute", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wMonth,
{
"wMonth", "skinny.wMonth", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wSecond,
{
"wSecond", "skinny.wSecond", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_wYear,
{
"wYear", "skinny.wYear", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_waitTimeBeforeNextReq,
{
"waitTimeBeforeNextReq", "skinny.waitTimeBeforeNextReq", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_skinny_xmldata,
{
"xmldata", "skinny.xmldata", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_AlternateCallingParty,
{
"AlternateCallingParty", "skinny.AlternateCallingParty", FT_STRING, BASE_NONE, NULL, 0x0,
"Alternate Calling Party Number", HFILL }},
{&hf_skinny_DeviceName,
{
"DeviceName", "skinny.DeviceName", FT_STRING, BASE_NONE, NULL, 0x0,
"Device Name", HFILL }},
{&hf_skinny_HuntPilotName,
{
"HuntPilotName", "skinny.HuntPilotName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_HuntPilotNumber,
{
"HuntPilotNumber", "skinny.HuntPilotNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_ServerName,
{
"ServerName", "skinny.ServerName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_add_participant_result,
{
"add_participant_result", "skinny.add.participant.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &AddParticipantResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_alarmSeverity,
{
"alarmSeverity", "skinny.alarmSeverity", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceAlarmSeverity_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_algorithmID,
{
"algorithmID", "skinny.algorithmID", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaEncryptionAlgorithmType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_annAckReq,
{
"annAckReq", "skinny.annAckReq", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &EndOfAnnAck_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_annPlayMode,
{
"annPlayMode", "skinny.annPlayMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &AnnPlayMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_annStatus,
{
"annStatus", "skinny.annStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &PlayAnnStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_appConfID,
{
"appConfID", "skinny.appConfID", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_appData,
{
"appData", "skinny.appData", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_appName,
{
"appName", "skinny.appName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_audit_participant_result,
{
"audit_participant_result", "skinny.audit.participant.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &AuditParticipantResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_bridgeParticipantId,
{
"bridgeParticipantId", "skinny.bridgeParticipantId", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_buttonDefinition,
{
"buttonDefinition", "skinny.buttonDefinition", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ButtonType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_callHistoryDisposition,
{
"callHistoryDisposition", "skinny.callHistoryDisposition", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &CallHistoryDisposition_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_callSecurityStatus,
{
"callSecurityStatus", "skinny.callSecurityStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &CallSecurityStatusType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_callState,
{
"callState", "skinny.callState", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DCallState_ext, 0x0,
"CallState", HFILL }},
{&hf_skinny_callType,
{
"callType", "skinny.callType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &CallType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_calledParty,
{
"calledParty", "skinny.calledParty", FT_STRING, BASE_NONE, NULL, 0x0,
"CalledPartyNumber", HFILL }},
{&hf_skinny_calledPartyName,
{
"calledPartyName", "skinny.calledPartyName", FT_STRING, BASE_NONE, NULL, 0x0,
"Called Party Name", HFILL }},
{&hf_skinny_callingParty,
{
"callingParty", "skinny.callingParty", FT_STRING, BASE_NONE, NULL, 0x0,
"Calling Party Number", HFILL }},
{&hf_skinny_callingPartyName,
{
"callingPartyName", "skinny.callingPartyName", FT_STRING, BASE_NONE, NULL, 0x0,
"Calling Party Name", HFILL }},
{&hf_skinny_callingPartyNumber,
{
"callingPartyNumber", "skinny.callingPartyNumber", FT_STRING, BASE_NONE, NULL, 0x0,
"Calling Party Number", HFILL }},
{&hf_skinny_cause,
{
"cause", "skinny.cause", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SubscribeCause_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_cdpnVoiceMailbox,
{
"cdpnVoiceMailbox", "skinny.cdpnVoiceMailbox", FT_STRING, BASE_NONE, NULL, 0x0,
"Called Party Voicemail Box Number", HFILL }},
{&hf_skinny_cgpnVoiceMailbox,
{
"cgpnVoiceMailbox", "skinny.cgpnVoiceMailbox", FT_STRING, BASE_NONE, NULL, 0x0,
"Calling Party Voicemail Box Number", HFILL }},
{&hf_skinny_command,
{
"command", "skinny.command", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MiscCommandType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_compressionType,
{
"compressionType", "skinny.compressionType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_PayloadType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_conferenceName,
{
"conferenceName", "skinny.conferenceName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_configVersionStamp,
{
"configVersionStamp", "skinny.configVersionStamp", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_data,
{
"Statistics", "skinny.data", FT_STRING, BASE_NONE, NULL, 0x0,
"variable field size (max: 600]", HFILL }},
{&hf_skinny_dataCapabilityDirection,
{
"dataCapabilityDirection", "skinny.dataCapabilityDirection", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &TransmitOrReceive_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_dateTemplate,
{
"dateTemplate", "skinny.dateTemplate", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_delete_conf_result,
{
"delete_conf_result", "skinny.delete.conf.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeleteConfResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_deviceType,
{
"Device Type", "skinny.deviceType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceType_ext, 0x0,
"Device Type of this phone / appliance", HFILL }},
{&hf_skinny_dialedNumber,
{
"dialedNumber", "skinny.dialedNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_direction,
{
"direction", "skinny.direction", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &RSVPDirection_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_directoryNum,
{
"directoryNum", "skinny.directoryNum", FT_STRING, BASE_NONE, NULL, 0x0,
"Directory Number", HFILL }},
{&hf_skinny_ecValue,
{
"ecValue", "skinny.ecValue", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_EchoCancellation_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_encryptionCapability,
{
"encryptionCapability", "skinny.encryptionCapability", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_Encryption_Capability_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_errorCode,
{
"errorCode", "skinny.errorCode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &QoSErrorCode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_featureID,
{
"featureID", "skinny.featureID", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SubscriptionFeatureID_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_featureTextLabel,
{
"featureTextLabel", "skinny.featureTextLabel", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_firmwareLoadName,
{
"firmwareLoadName", "skinny.firmwareLoadName", FT_STRING, BASE_NONE, NULL, 0x0,
"Firmware Load Name", HFILL }},
{&hf_skinny_forwardAllDirnum,
{
"forwardAllDirnum", "skinny.forwardAllDirnum", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_forwardBusyDirnum,
{
"forwardBusyDirnum", "skinny.forwardBusyDirnum", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_forwardNoAnswerlDirnum,
{
"forwardNoAnswerlDirnum", "skinny.forwardNoAnswerlDirnum", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_g723BitRate,
{
"g723BitRate", "skinny.g723BitRate", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_G723BitRate_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_headsetStatus,
{
"headsetStatus", "skinny.headsetStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &HeadsetMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_ipAddressType,
{
"ipAddressType", "skinny.ipAddressType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &IpAddrType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_ipAddressingMode,
{
"ipAddressingMode", "skinny.ipAddressingMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &IpAddrMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_kpButton,
{
"kpButton", "skinny.kpButton", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &KeyPadButton_ext, 0x0,
"KeyPad Button which was Pressed", HFILL }},
{&hf_skinny_lampMode,
{
"lampMode", "skinny.lampMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &LampMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_lastRedirectingParty,
{
"lastRedirectingParty", "skinny.lastRedirectingParty", FT_STRING, BASE_NONE, NULL, 0x0,
"Last Redirecting Party Number", HFILL }},
{&hf_skinny_lastRedirectingPartyName,
{
"lastRedirectingPartyName", "skinny.lastRedirectingPartyName", FT_STRING, BASE_NONE, NULL, 0x0,
"Last Redirecting Party Name", HFILL }},
{&hf_skinny_lastRedirectingVoiceMailbox,
{
"lastRedirectingVoiceMailbox", "skinny.lastRedirectingVoiceMailbox", FT_STRING, BASE_NONE, NULL, 0x0,
"Last Redirecting Parties Voicemail Box Number", HFILL }},
{&hf_skinny_layouts,
{
"layouts", "skinny.layouts", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Layout_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_lineDirNumber,
{
"lineDirNumber", "skinny.lineDirNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_lineFullyQualifiedDisplayName,
{
"lineFullyQualifiedDisplayName", "skinny.lineFullyQualifiedDisplayName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_lineTextLabel,
{
"lineTextLabel", "skinny.lineTextLabel", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_locationInfo,
{
"locationInfo", "skinny.locationInfo", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_mediaPathCapabilities,
{
"mediaPathCapabilities", "skinny.mediaPathCapabilities", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaPathCapabilities_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_mediaPathEvent,
{
"mediaPathEvent", "skinny.mediaPathEvent", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaPathEvent_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_mediaPathID,
{
"mediaPathID", "skinny.mediaPathID", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaPathID_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_mediaTransportType,
{
"mediaTransportType", "skinny.mediaTransportType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaTransportType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_mediaType,
{
"mediaType", "skinny.mediaType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_micMode,
{
"micMode", "skinny.micMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MicrophoneMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_modify_conf_result,
{
"modify_conf_result", "skinny.modify.conf.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ModifyConfResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_multimediaOpenReceiveChannelStatus,
{
"multimediaOpenReceiveChannelStatus", "skinny.multimediaOpenReceiveChannelStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &OpenReceiveChanStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_mwiControlNumber,
{
"mwiControlNumber", "skinny.mwiControlNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_mwiTargetNumber,
{
"mwiTargetNumber", "skinny.mwiTargetNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_mwi_notification_result,
{
"mwi_notification_result", "skinny.mwi.notification.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MwiNotificationResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_notify,
{
"notify", "skinny.notify", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_openReceiveChannelStatus,
{
"openReceiveChannelStatus", "skinny.openReceiveChannelStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_originalCalledParty,
{
"originalCalledParty", "skinny.originalCalledParty", FT_STRING, BASE_NONE, NULL, 0x0,
"Original Called Party Number", HFILL }},
{&hf_skinny_originalCalledPartyName,
{
"originalCalledPartyName", "skinny.originalCalledPartyName", FT_STRING, BASE_NONE, NULL, 0x0,
"Original Called Party Name", HFILL }},
{&hf_skinny_originalCdpnVoiceMailbox,
{
"originalCdpnVoiceMailbox", "skinny.originalCdpnVoiceMailbox", FT_STRING, BASE_NONE, NULL, 0x0,
"Original Called Party Voicemail Box Number", HFILL }},
{&hf_skinny_participantName,
{
"participantName", "skinny.participantName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_participantNumber,
{
"participantNumber", "skinny.participantNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_passThruData,
{
"passThruData", "skinny.passThruData", FT_STRING, BASE_NONE, NULL, 0x0,
"variable field size (max: 2000]", HFILL }},
{&hf_skinny_payloadCapability,
{
"payloadCapability", "skinny.payloadCapability", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_PayloadType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_portHandlingFlag,
{
"portHandlingFlag", "skinny.portHandlingFlag", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &PortHandling_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_privacy,
{
"privacy", "skinny.privacy", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &CallPrivacy_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_promptStatus,
{
"promptStatus", "skinny.promptStatus", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_receptionStatus,
{
"receptionStatus", "skinny.receptionStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MulticastMediaReceptionStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_recording_status,
{
"recording_status", "skinny.recording.status", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &RecordingStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_requestedIpAddrType,
{
"requestedIpAddrType", "skinny.requestedIpAddrType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &IpAddrType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_resetType,
{
"resetType", "skinny.resetType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceResetType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_resourceType,
{
"resourceType", "skinny.resourceType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ResourceType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_result,
{
"result", "skinny.result", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &CreateConfResult_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_resultCode,
{
"resultCode", "skinny.resultCode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_resvStyle,
{
"resvStyle", "skinny.resvStyle", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ResvStyle_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_ringDuration,
{
"ringDuration", "skinny.ringDuration", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &RingDuration_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_ringMode,
{
"ringMode", "skinny.ringMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &RingMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_rsvpErrorCode,
{
"rsvpErrorCode", "skinny.rsvpErrorCode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &RSVPErrorCode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_sequenceFlag,
{
"sequenceFlag", "skinny.sequenceFlag", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SequenceFlag_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_serverName,
{
"serverName", "skinny.serverName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_serviceURL,
{
"serviceURL", "skinny.serviceURL", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_serviceURLDisplayName,
{
"serviceURLDisplayName", "skinny.serviceURLDisplayName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_sessionType,
{
"sessionType", "skinny.sessionType", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SessionType_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_softKeyEvent,
{
"softKeyEvent", "skinny.softKeyEvent", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SoftKeyEvent_ext, 0x0,
"SoftKey Event", HFILL }},
{&hf_skinny_softKeyInfoIndex,
{
"softKeyInfoIndex", "skinny.softKeyInfoIndex", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &SoftKeyInfoIndex_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_softKeyLabel,
{
"softKeyLabel", "skinny.softKeyLabel", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_softKeySetIndex,
{
"softKeySetIndex", "skinny.softKeySetIndex", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SoftKeySet_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_softKeyTemplateIndex,
{
"softKeyTemplateIndex", "skinny.softKeyTemplateIndex", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &SoftKeyTemplateIndex_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_speakerMode,
{
"speakerMode", "skinny.speakerMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &SpeakerMode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_speedDialDirNumber,
{
"speedDialDirNumber", "skinny.speedDialDirNumber", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_speedDialDisplayName,
{
"speedDialDisplayName", "skinny.speedDialDisplayName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_ssValue,
{
"ssValue", "skinny.ssValue", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &Media_SilenceSuppression_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_startMediaTransmissionStatus,
{
"startMediaTransmissionStatus", "skinny.startMediaTransmissionStatus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &MediaStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_statsProcessingMode,
{
"Stats Processing Mode", "skinny.statsProcessingMode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &StatsProcessingType_ext, 0x0,
"What do do after you send the stats", HFILL }},
{&hf_skinny_status,
{
"status", "skinny.status", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceUnregisterStatus_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_stimulus,
{
"stimulus", "skinny.stimulus", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceStimulus_ext, 0x0,
"Device Stimulus", HFILL }},
{&hf_skinny_subAppID,
{
"subAppID", "skinny.subAppID", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_subscriptionID,
{
"subscriptionID", "skinny.subscriptionID", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_text,
{
"text", "skinny.text", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_tone,
{
"tone", "skinny.tone", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceTone_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_toneAnnouncement,
{
"toneAnnouncement", "skinny.toneAnnouncement", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &DeviceTone_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_tone_output_direction,
{
"tone_output_direction", "skinny.tone.output.direction", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ToneOutputDirection_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_unRegReasonCode,
{
"unRegReasonCode", "skinny.unRegReasonCode", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &UnRegReasonCode_ext, 0x0,
NULL, HFILL }},
{&hf_skinny_userName,
{
"userName", "skinny.userName", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_vendorID,
{
"vendorID", "skinny.vendorID", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_version,
{
"version", "skinny.version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&hf_skinny_videoCapabilityDirection,
{
"videoCapabilityDirection", "skinny.videoCapabilityDirection", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &TransmitOrReceive_ext, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_skinny,
&ett_skinny_tree,
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
skinny_handle = new_register_dissector("skinny", dissect_skinny, proto_skinny);
skinny_tap = register_tap("skinny");
}
void
proto_reg_handoff_skinny(void)
{
media_type_dissector_table = find_dissector_table("media_type");
dissector_add_uint("tcp.port", TCP_PORT_SKINNY, skinny_handle);
ssl_dissector_add(SSL_PORT_SKINNY, "skinny", TRUE);
}
