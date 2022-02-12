static const gchar *
match_strextval_idx(guint32 val, const ext_value_string *vs, gint *idx) {
gint i = 0;
if(vs) {
while (vs[i].strptr) {
if (vs[i].value == val) {
if (idx)
*idx = i;
return(vs[i].strptr);
}
i++;
}
}
if (idx)
*idx = -1;
return NULL;
}
static const gchar*
extval_to_str_idx(guint32 val, const ext_value_string *vs, gint *idx, const char *fmt) {
const gchar *ret;
if (!fmt)
fmt="Unknown";
ret = match_strextval_idx(val, vs, idx);
if (ret != NULL)
return ret;
return wmem_strdup_printf(wmem_packet_scope(), fmt, val);
}
static int
dissect_snmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *wassp_tree,
volatile guint32 offset, guint32 length, const ext_value_string *value_array _U_)
{
tvbuff_t *snmp_tvb;
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
snmp_tvb = tvb_new_subset_length(tvb, offset, length);
TRY {
call_dissector(snmp_handle, snmp_tvb, pinfo, wassp_tree);
} CATCH_NONFATAL_ERRORS {
show_exception(snmp_tvb, pinfo, wassp_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
col_set_writable(pinfo->cinfo, COL_INFO, TRUE);
offset += length;
return offset;
}
static int
dissect_ieee80211(tvbuff_t *tvb, packet_info *pinfo, proto_tree *wassp_tree,
volatile guint32 offset, guint32 length, const ext_value_string *value_array _U_)
{
tvbuff_t *ieee80211_tvb;
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
ieee80211_tvb = tvb_new_subset_length(tvb, offset, length);
TRY {
call_dissector(ieee80211_handle, ieee80211_tvb, pinfo, wassp_tree);
} CATCH_NONFATAL_ERRORS {
show_exception(ieee80211_tvb, pinfo, wassp_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
col_set_writable(pinfo->cinfo, COL_INFO, TRUE);
offset += length;
return offset;
}
static int
dissect_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *wassp_tree,
guint32 offset, guint32 length _U_, const ext_value_string *value_array)
{
guint32 tlv_type;
guint32 tlv_length;
proto_item *tlv_tree;
proto_item *type_item;
int type_index;
guint32 tlv_end;
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
DISSECTOR_ASSERT(tlv_length >= 4);
tlv_tree = proto_tree_add_subtree_format(wassp_tree, tvb,
offset, tlv_length, ett_wassp_tlv_header, NULL,
"T %d, L %d: %s",
tlv_type,
tlv_length,
extval_to_str_idx(tlv_type, value_array, NULL, "Unknown"));
type_item = proto_tree_add_item(tlv_tree, hf_wassp_tlv_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(type_item, " = %s",
extval_to_str_idx(tlv_type, value_array,
&type_index, "Unknown"));
offset += 2;
proto_tree_add_item(tlv_tree, hf_wassp_tlv_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tlv_length -= 4;
if (tlv_length == 0)
return offset;
tlv_end = offset + tlv_length;
if ( type_index != -1 && value_array[type_index].hf_element) {
proto_tree_add_item(tlv_tree,
*(value_array[type_index].hf_element),
tvb, offset, tlv_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_wassp_tlv_data,
tvb, offset, tlv_length, ENC_NA);
}
if ( type_index != -1 && value_array[type_index].specialfunction ) {
guint32 newoffset;
while (offset < tlv_end) {
newoffset = value_array[type_index].specialfunction (
tvb, pinfo, tlv_tree, offset, tlv_length,
value_array[type_index].evs);
DISSECTOR_ASSERT(newoffset > offset);
offset = newoffset;
}
}
return tlv_end;
}
static int
dissect_wassp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *wassp_tree = NULL;
guint32 offset = 0;
guint32 packet_length;
guint8 packet_type;
guint32 subtype;
packet_type = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type,
wassp_tunnel_pdu_type, "Type 0x%02x"));
if (tree) {
ti = proto_tree_add_item(tree, proto_wassp, tvb, offset, -1,
ENC_NA);
wassp_tree = proto_item_add_subtree(ti, ett_wassp);
proto_tree_add_item(wassp_tree, hf_wassp_version, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(wassp_tree, hf_wassp_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
switch (packet_type) {
case 1:
proto_tree_add_item(wassp_tree, hf_wassp_discover1, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(wassp_tree, hf_wassp_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(wassp_tree, hf_wassp_discover2, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
subtype = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(wassp_tree, hf_wassp_subtype, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
switch (subtype) {
case 1:
proto_tree_add_item(wassp_tree, hf_wassp_ether, tvb, offset, 6,
ENC_NA);
offset += 6;
break;
case 2:
proto_tree_add_item(wassp_tree, hf_wassp_discover3, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
break;
}
break;
default:
proto_tree_add_item(wassp_tree, hf_wassp_seqno, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(wassp_tree, hf_wassp_flags, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(wassp_tree, hf_wassp_sessionid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
packet_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(wassp_tree, hf_wassp_length, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
break;
}
switch (packet_type) {
case 15:
offset = dissect_ieee80211(tvb, pinfo, wassp_tree,
offset, packet_length - offset, NULL);
break;
default:
while (offset < packet_length)
offset = dissect_tlv(tvb, pinfo, wassp_tree,
offset, 0, wassp_tunnel_tlv_vals);
break;
}
}
return offset;
}
static gboolean
test_wassp(tvbuff_t *tvb)
{
if ( tvb_captured_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
return TRUE;
}
static gboolean
dissect_wassp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_wassp(tvb) ) {
return FALSE;
}
dissect_wassp(tvb, pinfo, tree);
return TRUE;
}
static int
dissect_wassp_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_wassp(tvb) ) {
return 0;
}
return dissect_wassp(tvb, pinfo, tree);
}
void
proto_register_wassp(void)
{
static hf_register_info hf[] = {
{ &hf_wassp_tlv_type,
{ "TlvType", "wassp.tlv.type", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_tlv_length,
{ "TlvLength", "wassp.tlv.length", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_tlv_data,
{ "TlvData", "wassp.tlv.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_version,
{ "Protocol Version", "wassp.version", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_type,
{ "PDU Type", "wassp.type", FT_UINT8, BASE_DEC, VALS(wassp_tunnel_pdu_type),
0x0, NULL, HFILL }},
{ &hf_wassp_seqno,
{ "Sequence No", "wassp.seqno", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_flags,
{ "Flags", "wassp.flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_sessionid,
{ "Session ID", "wassp.sessionid", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_length,
{ "PDU Length", "wassp.length", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
#if 0
{ &hf_data,
{ "DATA", "wassp.data", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
#endif
{ &hf_status,
{ "STATUS", "wassp.status", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_soft_version,
{ "RU-SOFT-VERSION", "wassp.ru.soft.version", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_serial_number,
{ "RU-SERIAL-NUMBER", "wassp.ru.serial.number", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_challenge,
{ "RU-CHALLENGE", "wassp.ru.challenge", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_response,
{ "RU-RESPONSE", "wassp.ru.response", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ac_ipaddr,
{ "AC-IPADDR", "wassp.ac.ipaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_vns_id,
{ "RU-VNS-ID", "wassp.ru.vns.id", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_tftp_server,
{ "TFTP-SERVER", "wassp.tftp.server", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_image_path,
{ "IMAGE-PATH", "wassp.image.path", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_config,
{ "RU-CONFIG", "wassp.ru.config", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_state,
{ "RU-STATE", "wassp.ru.state", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_session_key,
{ "RU-SESSION-KEY", "wassp.ru.session.key", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_message_type,
{ "MESSAGE-TYPE", "wassp.message.type", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_random_number,
{ "RANDOM-NUMBER", "wassp.random.number", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_standby_timeout,
{ "STANDBY-TIMEOUT", "wassp.standby.timeout", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_challenge_id,
{ "RU-CHALLENGE-ID", "wassp.ru.challenge.id", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_model,
{ "RU-MODEL", "wassp.ru.model", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_mode,
{ "RU-SCAN-MODE", "wassp.ru.scan.mode", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_type,
{ "RU-SCAN-TYPE", "wassp.ru.scan.type", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_interval,
{ "RU-SCAN-INTERVAL", "wassp.ru.scan.interval", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_radio_type,
{ "RU-RADIO-TYPE", "wassp.ru.radio.type", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_channel_dwell_time,
{ "RU-CHANNEL-DWELL-TIME", "wassp.ru.channel.dwell.time", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_channel_list,
{ "RU-CHANNEL-LIST", "wassp.ru.channel.list", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_trap,
{ "RU-TRAP", "wassp.ru.trap", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_times,
{ "RU-SCAN-TIMES", "wassp.ru.scan.times", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_delay,
{ "RU-SCAN-DELAY", "wassp.ru.scan.delay", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_scan_req_id,
{ "RU-SCAN-REQ-ID", "wassp.ru.scan.req.id", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_static_config,
{ "STATIC-CONFIG", "wassp.static.config", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_local_bridging,
{ "LOCAL-BRIDGING", "wassp.local.bridging", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_static_bp_ipaddr,
{ "STATIC-BP-IPADDR", "wassp.static.bp.ipaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_static_bp_netmask,
{ "STATIC-BP-NETMASK", "wassp.static.bp.netmask", FT_IPv4, BASE_NETMASK, NULL,
0x0, NULL, HFILL }},
{ &hf_static_bp_gateway,
{ "STATIC-BP-GATEWAY", "wassp.static.bp.gateway", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_static_bm_ipaddr,
{ "STATIC-BM-IPADDR", "wassp.static.bm.ipaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ru_alarm,
{ "RU-ALARM", "wassp.ru.alarm", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_bp_request_id,
{ "BP-REQUEST-ID", "wassp.bp.request.id", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_snmp_error_status,
{ "SNMP-ERROR-STATUS", "wassp.snmp.error.status", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_snmp_error_index,
{ "SNMP-ERROR-INDEX", "wassp.snmp.error.index", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_img_to_ram,
{ "AP-IMG-TO-RAM", "wassp.ap.img.to.ram", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_img_role,
{ "AP-IMG-ROLE", "wassp.ap.img.role", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_stats_block,
{ "AP Stats Block", "wassp.ap_stats_block", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_block_config,
{ "Config", "wassp.tlv_config", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_vlan_tag,
{ "WASSP-VLAN-TAG", "wassp.vlan.tag", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_tunnel_type,
{ "WASSP-TUNNEL-TYPE", "wassp.tunnel.type", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_dhcp_mode,
{ "AP-DHCP-MODE", "wassp.ap.dhcp.mode", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_ipaddr,
{ "AP-IPADDR", "wassp.ap.ipaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_netmask,
{ "AP-NETMASK", "wassp.ap.netmask", FT_IPv4, BASE_NETMASK, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_gateway,
{ "AP-GATEWAY", "wassp.ap.gateway", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_preauth_resp,
{ "PREAUTH_RESP", "wassp.preauth.resp", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_bp_pmk,
{ "BP_PMK", "wassp.bp.pmk", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ac_reg_challenge,
{ "AC_REG_CHALLENGE", "wassp.ac.reg.challenge", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ac_reg_response,
{ "AC_REG_RESPONSE", "wassp.ac.reg.response", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats,
{ "STATS", "wassp.stats", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_certificate,
{ "CERTIFICATE", "wassp.certificate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_radio_id,
{ "RADIO_ID", "wassp.radio.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_network_id,
{ "NETWORK_ID", "wassp.network.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_mac,
{ "MU_MAC", "wassp.mu.mac", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_time,
{ "TIME", "wassp.time", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_num_radios,
{ "NUM_RADIOS", "wassp.num.radios", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_radio_info,
{ "RADIO_INFO", "wassp.radio.info", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_network_info,
{ "NETWORK_INFO", "wassp.network.info", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vendor_id,
{ "VENDOR_ID", "wassp.vendor.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_product_id,
{ "PRODUCT_ID", "wassp.product.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_radio_info_ack,
{ "RADIO_INFO_ACK", "wassp.radio.info.ack", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_rf_stats_block,
{ "MU_RF_STATS_BLOCK", "wassp.mu.rf.stats.block", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_request_type,
{ "STATS_REQUEST_TYPE", "wassp.stats.request.type", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_last,
{ "STATS_LAST", "wassp.stats.last", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_pmkid_list,
{ "MU_PMKID_LIST", "wassp.mu.pmkid.list", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_pmk_bp,
{ "MU_PMK_BP", "wassp.mu.pmk.bp", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_pmkid_bp,
{ "MU_PMKID_BP", "wassp.mu.pmkid.bp", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_countdown_time,
{ "COUNTDOWN_TIME", "wassp.countdown.time", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_stats_block_ether,
{ "Ether Stats", "wassp.ap_stats_block.ether", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_stats_block_radio_a,
{ "Radio-A Stats", "wassp.ap_stats_block.radioa", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_ap_stats_block_radio_b_g,
{ "Radio-B/G Stats", "wassp.ap_stats_block.radiobg", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_stats_block,
{ "Mobile User Stats", "wassp.mustats", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_mu_stats_block_65,
{ "MU Stats Unknown 65", "wassp.mustats.65", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_dot1x_stats_block,
{ "DOT1x_STATS_BLOCK", "wassp.ap_stats_block.dot1x", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_ackfailurecount,
{ "DOT11_ACKFailureCount", "wassp.stats.dot11.ackfailurecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_fcserrorcount,
{ "DOT11_FCSErrorCount", "wassp.stats.dot11.fcserrorcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_failedcount,
{ "DOT11_FailedCount", "wassp.stats.dot11.failedcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_frameduplicatecount,
{ "DOT11_FrameDuplicateCount", "wassp.stats.dot11.frameduplicatecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_multicastreceivedframecount,
{ "DOT11_MulticastReceivedFrameCount", "wassp.stats.dot11.multicastreceivedframecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_multicasttransmittedframecount,
{ "DOT11_MulticastTransmittedFrameCount", "wassp.stats.dot11.multicasttransmittedframecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_multipleretrycount,
{ "DOT11_MultipleRetryCount", "wassp.stats.dot11.multipleretrycount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_rtsfailurecount,
{ "DOT11_RTSFailureCount", "wassp.stats.dot11.rtsfailurecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_rtssuccesscount,
{ "DOT11_RTSSuccessCount", "wassp.stats.dot11.rtssuccesscount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_receivedfragementcount,
{ "DOT11_ReceivedFragementCount", "wassp.stats.dot11.receivedfragementcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_retrycount,
{ "DOT11_RetryCount", "wassp.stats.dot11.retrycount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_transmittedfragmentcount,
{ "DOT11_TransmittedFragmentCount", "wassp.stats.dot11.transmittedfragmentcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_transmittedframecount,
{ "DOT11_TransmittedFrameCount", "wassp.stats.dot11.transmittedframecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_webundecryptablecount,
{ "DOT11_WEBUndecryptableCount", "wassp.stats.dot11.webundecryptablecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_wepexcludedcount,
{ "DOT11_WEPExcludedCount", "wassp.stats.dot11.wepexcludedcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_dot11_wepicverrorcount,
{ "DOT11_WEPICVErrorCount", "wassp.stats.dot11.wepicverrorcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_allocfailures,
{ "DRM_AllocFailures", "wassp.stats.drm.allocfailures", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_currentchannel,
{ "DRM_CurrentChannel", "wassp.stats.drm.currentchannel", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_currentpower,
{ "DRM_CurrentPower", "wassp.stats.drm.currentpower", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_datatxfailures,
{ "DRM_DataTxFailures", "wassp.stats.drm.datatxfailures", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_devicetype,
{ "DRM_DeviceType", "wassp.stats.drm.devicetype", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_indatapackets,
{ "DRM_InDataPackets", "wassp.stats.drm.indatapackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_inmgmtpackets,
{ "DRM_InMgmtPackets", "wassp.stats.drm.inmgmtpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_loadfactor,
{ "DRM_LoadFactor", "wassp.stats.drm.loadfactor", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_mgmttxfailures,
{ "DRM_MgmtTxFailures", "wassp.stats.drm.mgmttxfailures", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_msgqfailures,
{ "DRM_MsgQFailures", "wassp.stats.drm.msgqfailures", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_nodrmcurrentchannel,
{ "DRM_NoDRMCurrentChannel", "wassp.stats.drm.nodrmcurrentchannel", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_outdatapackets,
{ "DRM_OutDataPackets", "wassp.stats.drm.outdatapackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_drm_outmgmtpackets,
{ "DRM_OutMgmtPackets", "wassp.stats.drm.outmgmtpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_inbcastpackets,
{ "IF_InBcastPackets", "wassp.stats.if.inbcastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_indiscards,
{ "IF_InDiscards", "wassp.stats.if.indiscards", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_inerrors,
{ "IF_InErrors", "wassp.stats.if.inerrors", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_inmcastpackets,
{ "IF_InMcastPackets", "wassp.stats.if.inmcastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_inoctets,
{ "IF_InOctets", "wassp.stats.if.inoctets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_inucastpackets,
{ "IF_InUcastPackets", "wassp.stats.if.inucastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_mtu,
{ "IF_MTU", "wassp.stats.if.mtu", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outbcastpackets,
{ "IF_OutBcastPackets", "wassp.stats.if.outbcastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outdiscards,
{ "IF_OutDiscards", "wassp.stats.if.outdiscards", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outerrors,
{ "IF_OutErrors", "wassp.stats.if.outerrors", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outoctets,
{ "IF_OutOctets", "wassp.stats.if.outoctets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outucastpackets,
{ "IF_OutUcastPackets", "wassp.stats.if.outucastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_if_outmcastpackets,
{ "IF_OutMCastPackets", "wassp.stats.if.outmcastpackets", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_address,
{ "MU_Address", "wassp.stats.mu.address", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_associationcount,
{ "MU_AssociationCount", "wassp.stats.mu.associationcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_authenticationcount,
{ "MU_AuthenticationCount", "wassp.stats.mu.authenticationcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_deassociationcount,
{ "MU_DeAssociationCount", "wassp.stats.mu.deassociationcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_deauthenticationcount,
{ "MU_DeAuthenticationCount", "wassp.stats.mu.deauthenticationcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_ifindex,
{ "MU_IfIndex", "wassp.stats.mu.ifindex", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_reassociationcount,
{ "MU_ReAssociationCount", "wassp.stats.mu.reassociationcount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_receivedbytes,
{ "MU_ReceivedBytes", "wassp.stats.mu.receivedbytes", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_receivederrors,
{ "MU_ReceivedErrors", "wassp.stats.mu.receivederrors", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_receivedframecount,
{ "MU_ReceivedFrameCount", "wassp.stats.mu.receivedframecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_receivedrssi,
{ "MU_ReceivedRSSI", "wassp.stats.mu.receivedrssi", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_receivedrate,
{ "MU_ReceivedRate", "wassp.stats.mu.receivedrate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_transmittedbytes,
{ "MU_TransmittedBytes", "wassp.stats.mu.transmittedbytes", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_transmittederrors,
{ "MU_TransmittedErrors", "wassp.stats.mu.transmittederrors", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_transmittedframecount,
{ "MU_TransmittedFrameCount", "wassp.stats.mu.transmittedframecount", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_transmittedrssi,
{ "MU_TransmittedRSSI", "wassp.stats.mu.transmittedrssi", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_transmittedrate,
{ "MU_TransmittedRate", "wassp.stats.mu.transmittedrate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_mu_rf_stats_end,
{ "MU_RF_STATS_END", "wassp.stats.mu.rf.stats.end", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_rfc_1213_sysuptime,
{ "RFC_1213_SYSUPTIME", "wassp.stats.rfc.1213.sysuptime", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_dot1x_stats_credent,
{ "DOT1x_CREDENT", "wassp.stats.dot1x.credent", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_dot1x_stats_end_date,
{ "DOT1x_END_DATE", "wassp.stats.dot1x.enddate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_stats_tlv_max,
{ "TLV_MAX", "wassp.stats.tlvmax", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio,
{ "Config Radio", "wassp.tlv_config.radio", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns,
{ "Config VNS", "wassp.tlv_config.vns", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_trace_status_debug,
{ "TRACE_STATUS_DEBUG", "wassp.config.trace.status.debug", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_trace_status_config,
{ "TRACE_STATUS_CONFIG", "wassp.config.trace.status.config", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_use_bcast_for_disassc,
{ "USE_BCAST_FOR_DISASSC", "wassp.config.use.bcast.for.disassc", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_voice_assc,
{ "BANDWIDTH_VOICE_ASSC", "wassp.config.bandwidth.voice.assc", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_voice_reassc,
{ "BANDWIDTH_VOICE_REASSC", "wassp.config.bandwidth.voice.reassc", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_video_assc,
{ "BANDWIDTH_VIDEO_ASSC", "wassp.config.bandwidth.video.assc", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_video_reassc,
{ "BANDWIDTH_VIDEO_REASSC", "wassp.config.bandwidth.video.reassc", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_video_reserve,
{ "BANDWIDTH_VIDEO_RESERVE", "wassp.config.bandwidth.video.reserve", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_bandwidth_adm_ctrl_reserve,
{ "BANDWIDTH_ADM_CTRL_RESERVE", "wassp.config.bandwidth.adm.ctrl.reserve", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vlan_tag,
{ "VLAN_TAG", "wassp.config.vlan.tag", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_country_code,
{ "COUNTRY_CODE", "wassp.config.country.code", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_poll_duration,
{ "POLL_DURATION", "wassp.config.poll.duration", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_poll_interval,
{ "POLL_INTERVAL", "wassp.config.poll.interval", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_poll_maintain_client_session,
{ "POLL_MAINTAIN_CLIENT_SESSION", "wassp.config.poll.maintain.client.session", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_telnet_enable,
{ "TELNET_ENABLE", "wassp.config.telnet.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_telnet_password,
{ "TELNET_PASSWORD", "wassp.config.telnet.password", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_telnet_password_entry_mode,
{ "TELNET_PASSWORD_ENTRY_MODE", "wassp.config.telnet.password.entry.mode", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_outdoor_enable_environment,
{ "OUTDOOR_ENABLE_ENVIRONMENT", "wassp.config.outdoor.enable.environment", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_slp_retry_count,
{ "SLP_RETRY_COUNT", "wassp.config.slp.retry.count", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_slp_retry_delay,
{ "SLP_RETRY_DELAY", "wassp.config.slp.retry.delay", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_dns_retry_count,
{ "DNS_RETRY_COUNT", "wassp.config.dns.retry.count", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_dns_retry_delay,
{ "DNS_RETRY_DELAY", "wassp.config.dns.retry.delay", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_mcast_slp_retry_count,
{ "MCAST_SLP_RETRY_COUNT", "wassp.config.mcast.slp.retry.count", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_mcast_slp_retry_delay,
{ "MCAST_SLP_RETRY_DELAY", "wassp.config.mcast.slp.retry.delay", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_disc_retry_count,
{ "DISC_RETRY_COUNT", "wassp.config.disc.retry.count", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_disc_retry_delay,
{ "DISC_RETRY_DELAY", "wassp.config.disc.retry.delay", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_logging_alarm_sev,
{ "LOGGING_ALARM_SEV", "wassp.config.logging.alarm.sev", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_blacklist_blacklist_add,
{ "BLACKLIST_BLACKLIST_ADD", "wassp.config.blacklist.blacklist.add", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_failover_ac_ip_addr,
{ "FAILOVER_AC_IP_ADDR", "wassp.config.failover.ac.ip.addr", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_static_ac_ip_addr,
{ "STATIC_AC_IP_ADDR", "wassp.config.static.ac.ip.addr", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_dhcp_assignment,
{ "DHCP_ASSIGNMENT", "wassp.config.dhcp.assignment", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_static_ap_ip_addr,
{ "STATIC_AP_IP_ADDR", "wassp.config.static.ap.ip.addr", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_static_ap_ip_netmask,
{ "STATIC_AP_IP_NETMASK", "wassp.config.static.ap.ip.netmask", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_static_ap_default_gw,
{ "STATIC_AP_DEFAULT_GW", "wassp.config.static.ap.default.gw", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_blacklist_del,
{ "BLACKLIST_DEL", "wassp.config.blacklist.del", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_macaddr_req,
{ "MACADDR_REQ", "wassp.config.macaddr.req", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_availability_mode,
{ "AVAILABILITY_MODE", "wassp.config.availability.mode", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_radio_id,
{ "V_RADIO_ID", "wassp.config.vns.radio.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_vns_id,
{ "V_VNS_ID", "wassp.config.vns.vns.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_turbo_voice,
{ "V_TURBO_VOICE", "wassp.config.vns.turbo.voice", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_prop_ie,
{ "V_PROP_IE", "wassp.config.vns.prop.ie", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_enable_802_11_h,
{ "V_ENABLE_802_11_H", "wassp.config.vns.enable.802.11.h", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_power_backoff,
{ "V_POWER_BACKOFF", "wassp.config.vns.power.backoff", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_bridge_mode,
{ "V_BRIDGE_MODE", "wassp.config.vns.bridge.mode", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_vlan_tag,
{ "V_VLAN_TAG", "wassp.config.vns.vlan.tag", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_process_ie_req,
{ "V_PROCESS_IE_REQ", "wassp.config.vns.process.ie.req", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_enable_u_apsd,
{ "V_ENABLE_U_APSD", "wassp.config.vns.enable.u.apsd", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_adm_ctrl_voice,
{ "V_ADM_CTRL_VOICE", "wassp.config.vns.adm.ctrl.voice", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_adm_ctrl_video,
{ "V_ADM_CTRL_VIDEO", "wassp.config.vns.adm.ctrl.video", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_qos_up_value,
{ "V_QOS_UP_VALUE", "wassp.config.vns.qos.up.value", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_priority_override,
{ "V_PRIORITY_OVERRIDE", "wassp.config.vns.priority.override", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_dscp_override_value,
{ "V_DSCP_OVERRIDE_VALUE", "wassp.config.vns.dscp.override.value", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_enable_802_11_e,
{ "V_ENABLE_802_11_E", "wassp.config.vns.enable.802.11.e", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_enable_wmm,
{ "V_ENABLE_WMM", "wassp.config.vns.enable.wmm", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_legacy_client_priority,
{ "V_LEGACY_CLIENT_PRIORITY", "wassp.config.vns.legacy.client.priority", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_ssid_id,
{ "V_SSID_ID", "wassp.config.vns.ssid.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_ssid_bcast_string,
{ "V_SSID_BCAST_STRING", "wassp.config.vns.ssid.bcast.string", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_ssid_suppress,
{ "V_SSID_SUPPRESS", "wassp.config.vns.ssid.suppress", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_802_1_x_enable,
{ "V_802_1_X_ENABLE", "wassp.config.vns.802.1.x.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_802_1_x_dyn_rekey,
{ "V_802_1_X_DYN_REKEY", "wassp.config.vns.802.1.x.dyn.rekey", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wpa_enable,
{ "V_WPA_ENABLE", "wassp.config.vns.wpa.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wpa_v2_enable,
{ "V_WPA_V2_ENABLE", "wassp.config.vns.wpa.v2.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wpa_passphrase,
{ "V_WPA_PASSPHRASE", "wassp.config.vns.wpa.passphrase", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wpa_cipher_type,
{ "V_WPA_CIPHER_TYPE", "wassp.config.vns.wpa.cipher.type", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wpa_v2_cipher_type,
{ "V_WPA_V2_CIPHER_TYPE", "wassp.config.vns.wpa.v2.cipher.type", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wep_key_index,
{ "V_WEP_KEY_INDEX", "wassp.config.vns.wep.key.index", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wep_default_key_value,
{ "V_WEP_DEFAULT_KEY_VALUE", "wassp.config.vns.wep.default.key.value", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_channel_report,
{ "V_CHANNEL_REPORT", "wassp.config.vns.channel.report", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_service,
{ "V_WDS_SERVICE", "wassp.config.vns.wds.service", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_pref_parent,
{ "V_WDS_PREF_PARENT", "wassp.config.vns.wds.pref.parent", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_bridge,
{ "V_WDS_BRIDGE", "wassp.config.vns.wds.bridge", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_okc_enabled,
{ "V_OKC_ENABLED", "wassp.config.vns.okc.enabled", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_mu_assoc_retries,
{ "V_MU_ASSOC_RETRIES", "wassp.config.vns.mu.assoc.retries", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_mu_assoc_timeout,
{ "V_MU_ASSOC_TIMEOUT", "wassp.config.vns.mu.assoc.timeout", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_parent,
{ "V_WDS_PARENT", "wassp.config.vns.wds.parent", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_back_parent,
{ "V_WDS_BACK_PARENT", "wassp.config.vns.wds.back.parent", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_vns_wds_name,
{ "V_WDS_NAME", "wassp.config.vns.wds.name", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_radio_id,
{ "R_RADIO_ID", "wassp.config.radio.radio.id", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_enable_radio,
{ "R_ENABLE_RADIO", "wassp.config.radio.enable.radio", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_channel,
{ "R_CHANNEL", "wassp.config.radio.channel", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_op_rate_set,
{ "R_OP_RATE_SET", "wassp.config.radio.op.rate.set", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_op_rate_max,
{ "R_OP_RATE_MAX", "wassp.config.radio.op.rate.max", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_beacon_period,
{ "R_BEACON_PERIOD", "wassp.config.radio.beacon.period", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_dtim_period,
{ "R_DTIM_PERIOD", "wassp.config.radio.dtim.period", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_rts_threshold,
{ "R_RTS_THRESHOLD", "wassp.config.radio.rts.threshold", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_fragment_threshold,
{ "R_FRAGMENT_THRESHOLD", "wassp.config.radio.fragment.threshold", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_power_level,
{ "R_POWER_LEVEL", "wassp.config.radio.power.level", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_diversity_rx,
{ "R_DIVERSITY_RX", "wassp.config.radio.diversity.rx", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_diversity_tx,
{ "R_DIVERSITY_TX", "wassp.config.radio.diversity.tx", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_short_preamble,
{ "R_SHORT_PREAMBLE", "wassp.config.radio.short.preamble", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_basic_rate_max,
{ "R_BASIC_RATE_MAX", "wassp.config.radio.basic.rate.max", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_basic_rate_min,
{ "R_BASIC_RATE_MIN", "wassp.config.radio.basic.rate.min", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_hw_retries,
{ "R_HW_RETRIES", "wassp.config.radio.hw.retries", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_tx_power_min,
{ "R_TX_POWER_MIN", "wassp.config.radio.tx.power.min", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_tx_power_max,
{ "R_TX_POWER_MAX", "wassp.config.radio.tx.power.max", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_domain_id,
{ "R_DOMAIN_ID", "wassp.config.radio.domain.id", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_b_enable,
{ "R_B_ENABLE", "wassp.config.radio.b.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_b_basic_rates,
{ "R_B_BASIC_RATES", "wassp.config.radio.b.basic.rates", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_g_enable,
{ "R_G_ENABLE", "wassp.config.radio.g.enable", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_g_protect_mode,
{ "R_G_PROTECT_MODE", "wassp.config.radio.g.protect.mode", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_g_protect_type,
{ "R_G_PROTECT_TYPE", "wassp.config.radio.g.protect.type", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_g_protect_rate,
{ "R_G_PROTECT_RATE", "wassp.config.radio.g.protect.rate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_g_basic_rate,
{ "R_G_BASIC_RATE", "wassp.config.radio.g.basic.rate", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_a_support_802_11_j,
{ "R_A_SUPPORT_802_11_J", "wassp.config.radio.a.support.802.11.j", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_atpc_en_interval,
{ "R_ATPC_EN_INTERVAL", "wassp.config.radio.atpc.en.interval", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_acs_ch_list,
{ "R_ACS_CH_LIST", "wassp.config.radio.acs.ch.list", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_config_radio_tx_power_adj,
{ "R_TX_POWER_ADJ", "wassp.config.radio.tx.power.adj", FT_INT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_discover1,
{ "Discover Header1", "wassp.discover1", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_discover2,
{ "Discover Header2", "wassp.discover2", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_subtype,
{ "Discover Subtype", "wassp.subtype", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_ether,
{ "Discover Ether", "wassp.ether", FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wassp_discover3,
{ "Discover Header3", "wassp.discover3", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_wassp,
&ett_wassp_tlv_header,
};
proto_wassp = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "wassp");
proto_register_field_array(proto_wassp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wassp(void)
{
dissector_handle_t wassp_handle;
wassp_handle = create_dissector_handle(dissect_wassp_static, proto_wassp);
dissector_add_uint("udp.port", PORT_WASSP_DISCOVER, wassp_handle);
dissector_add_uint("udp.port", PORT_WASSP_TUNNEL, wassp_handle);
heur_dissector_add("udp", dissect_wassp_heur, "WASSP over UDP", "wassp_udp", proto_wassp, HEURISTIC_DISABLE);
snmp_handle = find_dissector_add_dependency("snmp", proto_wassp);
ieee80211_handle = find_dissector_add_dependency("wlan_withoutfcs", proto_wassp);
}
