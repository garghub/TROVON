static void capwap_reassemble_init(void)
{
reassembly_table_init(&capwap_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
dissect_capwap_data_message_bindings_ieee80211(tvbuff_t *tvb, proto_tree *data_message_binding_tree, guint offset, packet_info *pinfo)
{
proto_item *data_message_binding_item, *ti;
proto_tree *sub_data_message_binding_tree;
if (global_capwap_data_udp_port == pinfo->destport)
{
guint16 data_rate;
data_message_binding_item = proto_tree_add_item(data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_fi, tvb, offset, 4, ENC_NA);
sub_data_message_binding_tree = proto_item_add_subtree(data_message_binding_item, ett_capwap);
proto_tree_add_item(sub_data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_fi_rssi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_fi_snr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(sub_data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_fi_data_rate, tvb, offset+2, 2, ENC_BIG_ENDIAN);
data_rate = tvb_get_ntohs(tvb, offset+2);
proto_item_append_text(ti, " (%.1f Mb/s)", ((float)data_rate / 10));
}
else
{
data_message_binding_item = proto_tree_add_item(data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_dest_wlan,tvb, offset, 4, ENC_NA);
sub_data_message_binding_tree = proto_item_add_subtree(data_message_binding_item, ett_capwap);
proto_tree_add_item(sub_data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_dw_wlan_id_bitmap, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_data_message_binding_tree, hf_capwap_header_wireless_data_ieee80211_dw_reserved, tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_capwap_encryption_capabilities(tvbuff_t *tvb, proto_tree *encryption_capabilities_tree, guint offset)
{
proto_item *encryption_capabilities_item;
proto_tree *sub_encryption_capabilities_tree;
encryption_capabilities_item = proto_tree_add_item(encryption_capabilities_tree, hf_capwap_msg_element_type_wtp_descriptor_encrypt, tvb, offset, 3, ENC_NA);
sub_encryption_capabilities_tree = proto_item_add_subtree(encryption_capabilities_item, ett_capwap);
proto_tree_add_item(sub_encryption_capabilities_tree, hf_capwap_msg_element_type_wtp_descriptor_encrypt_reserved, tvb, offset, 1, ENC_NA);
proto_tree_add_item (sub_encryption_capabilities_tree, hf_capwap_msg_element_type_wtp_descriptor_encrypt_wbid, tvb, offset, 1, ENC_NA);
proto_item_append_text(encryption_capabilities_item, ": (WBID %d)",tvb_get_guint8(tvb, offset) & 0x1F);
proto_tree_add_item(sub_encryption_capabilities_tree, hf_capwap_msg_element_type_wtp_descriptor_encrypt_capabilities, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_item_append_text(encryption_capabilities_item, " %d",tvb_get_ntohs(tvb, offset+1));
}
static int
dissect_capwap_ac_information(tvbuff_t *tvb, proto_tree *ac_information_type_tree, guint offset)
{
guint optlen,ac_information_type = 0;
proto_item *ac_information_type_item;
proto_tree *sub_ac_information_type_tree;
ac_information_type = tvb_get_ntohs(tvb, offset+4);
optlen = tvb_get_ntohs(tvb, offset+6);
ac_information_type_item = proto_tree_add_item(ac_information_type_tree, hf_capwap_msg_element_type_ac_information, tvb, offset, 4+2+2+optlen, ENC_NA );
proto_item_append_text(ac_information_type_item,": (t=%d,l=%d) %s", ac_information_type, optlen, val_to_str(ac_information_type,ac_information_type_vals,"Unknown AC Information Type (%02d)") );
sub_ac_information_type_tree = proto_item_add_subtree(ac_information_type_item, ett_capwap);
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_vendor, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_type, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_length, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_value, tvb, offset+8, optlen, ENC_NA);
switch (ac_information_type) {
case AC_INFORMATION_HARDWARE_VERSION:
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_hardware_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
case AC_INFORMATION_SOFTWARE_VERSION:
proto_tree_add_item(sub_ac_information_type_tree, hf_capwap_msg_element_type_ac_information_software_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
default:
break;
}
return 4+2+2+optlen;
}
static int
dissect_capwap_wtp_descriptor(tvbuff_t *tvb, proto_tree *wtp_descriptor_type_tree, guint offset)
{
guint optlen,wtp_descriptor_type = 0;
proto_item *wtp_descriptor_type_item;
proto_tree *sub_wtp_descriptor_type_tree;
wtp_descriptor_type = tvb_get_ntohs(tvb, offset+4);
optlen = tvb_get_ntohs(tvb, offset+6);
wtp_descriptor_type_item = proto_tree_add_item(wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor, tvb, offset, 4+2+2+optlen, ENC_NA);
proto_item_append_text(wtp_descriptor_type_item, ": (t=%d,l=%d) %s", wtp_descriptor_type, optlen, val_to_str(wtp_descriptor_type,wtp_descriptor_type_vals,"Unknown WTP Descriptor Type (%02d)") );
sub_wtp_descriptor_type_tree = proto_item_add_subtree(wtp_descriptor_type_item, ett_capwap);
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_vendor, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_type, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_length, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_value, tvb, offset+8, optlen, ENC_NA);
switch (wtp_descriptor_type) {
case WTP_DESCRIPTOR_HARDWARE_VERSION:
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_hardware_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
case WTP_DESCRIPTOR_ACTIVE_SOFTWARE_VERSION:
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_active_software_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
case WTP_DESCRIPTOR_BOOT_VERSION:
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_boot_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
case WTP_DESCRIPTOR_OTHER_SOFTWARE_VERSION:
proto_tree_add_item(sub_wtp_descriptor_type_tree, hf_capwap_msg_element_type_wtp_descriptor_other_software_version, tvb, offset+8, optlen, ENC_ASCII|ENC_NA);
break;
default:
break;
}
return 4+2+2+optlen;
}
static int
dissect_capwap_board_data(tvbuff_t *tvb, proto_tree *board_data_type_tree, guint offset)
{
guint optlen,board_data_type = 0;
proto_item *board_data_type_item;
proto_tree *sub_board_data_type_tree;
board_data_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
board_data_type_item = proto_tree_add_item(board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data, tvb, offset, 2+2+optlen, ENC_NA );
proto_item_append_text(board_data_type_item, ": (t=%d,l=%d) %s", board_data_type, optlen, val_to_str(board_data_type,board_data_type_vals,"Unknown Board Data Type (%02d)") );
sub_board_data_type_tree = proto_item_add_subtree(board_data_type_item, ett_capwap);
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_value, tvb, offset+4, optlen, ENC_NA);
switch (board_data_type) {
case BOARD_DATA_WTP_MODEL_NUMBER:
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_wtp_model_number, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case BOARD_DATA_WTP_SERIAL_NUMBER:
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_wtp_serial_number, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case BOARD_DATA_BOARD_ID:
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_wtp_board_id, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case BOARD_DATA_BOARD_REVISION:
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_wtp_board_revision, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case BOARD_DATA_BASE_MAC_ADDRESS:
proto_tree_add_item(sub_board_data_type_tree, hf_capwap_msg_element_type_wtp_board_data_base_mac_address, tvb, offset+4, 6, ENC_NA);
break;
default:
break;
}
return 2+2+optlen;
}
static int
dissect_capwap_message_element_type(tvbuff_t *tvb, proto_tree *msg_element_type_tree, guint offset)
{
guint optlen, offset_end, number_encrypt, i, msg_element_type = 0;
proto_item *msg_element_type_item, *msg_element_type_item_flag;
proto_tree *sub_msg_element_type_tree, *sub_msg_element_type_flag_tree;
msg_element_type = tvb_get_ntohs(tvb, offset);
optlen = tvb_get_ntohs(tvb, offset+2);
msg_element_type_item = proto_tree_add_item(msg_element_type_tree, hf_capwap_msg_element, tvb, offset, 2+2+optlen, ENC_NA );
proto_item_append_text(msg_element_type_item, ": (t=%d,l=%d) %s", msg_element_type, optlen, val_to_str(msg_element_type,message_element_type_vals,"Unknown Message Element Type (%02d)") );
sub_msg_element_type_tree = proto_item_add_subtree(msg_element_type_item, ett_capwap);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_value, tvb, offset+4, optlen, ENC_NA);
switch (msg_element_type) {
case TYPE_AC_DESCRIPTOR:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_stations, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_limit, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_active_wtp, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_max_wtp, tvb, offset+10, 2, ENC_BIG_ENDIAN);
msg_element_type_item_flag = proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_security, tvb, offset+12, 1, ENC_NA);
sub_msg_element_type_flag_tree = proto_item_add_subtree(msg_element_type_item_flag, ett_capwap);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_security_r, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_security_s, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_security_x, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_rmac_field, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_reserved, tvb, offset+14, 1, ENC_BIG_ENDIAN);
msg_element_type_item_flag = proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_descriptor_dtls_policy, tvb, offset+15, 1, ENC_NA);
sub_msg_element_type_flag_tree = proto_item_add_subtree(msg_element_type_item_flag, ett_capwap);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_dtls_policy_r, tvb, offset+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_dtls_policy_d, tvb, offset+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ac_descriptor_dtls_policy_c, tvb, offset+15, 1, ENC_BIG_ENDIAN);
offset_end = offset + optlen -4;
offset += 4 + 12;
while (offset < offset_end) {
offset += dissect_capwap_ac_information(tvb, sub_msg_element_type_tree, offset);
}
break;
case TYPE_AC_IPV4_LIST:
offset_end = offset + 4 + optlen;
offset += 4;
if (optlen%4 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_ipv4_list, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
break;
case TYPE_AC_IPV6_LIST:
offset_end = offset + 4 + optlen;
offset += 4;
if (optlen%16 == 0)
{
while (offset_end-offset > 0)
{
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_ipv6_list, tvb, offset, 16, ENC_NA);
offset += 16;
}
}
break;
case TYPE_AC_NAME:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_name, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case TYPE_AC_NAME_W_PRIORITY:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_name_with_priority, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ac_name, tvb, offset+5, optlen-1, ENC_ASCII|ENC_NA);
break;
case TYPE_CAPWAP_CONTROL_IPV4_ADDRESS:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_control_ipv4, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_control_wtp_count, tvb, offset+8, 2, ENC_BIG_ENDIAN);
break;
case TYPE_CAPWAP_CONTROL_IPV6_ADDRESS:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_control_ipv6, tvb, offset+4, 16, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_control_wtp_count, tvb, offset+20, 2, ENC_BIG_ENDIAN);
break;
case TYPE_CAPWAP_TIMERS:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_timers_discovery, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_capwap_timers_echo_request, tvb, offset+5, 1, ENC_BIG_ENDIAN);
break;
case TYPE_DECRYPTION_ERROR_REPORT_PERIOD:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_decryption_error_report_period_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree,hf_capwap_msg_element_type_decryption_error_report_period_interval, tvb, offset+5, 2, ENC_BIG_ENDIAN);
break;
case TYPE_DISCOVERY_TYPE:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_discovery_type, tvb, offset+4, optlen, ENC_BIG_ENDIAN);
break;
case TYPE_IDLE_TIMEOUT:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_idle_timeout, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case TYPE_LOCATION_DATA:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_location_data, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case TYPE_MAXIMUM_MESSAGE_LENGTH:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_maximum_message_length, tvb, offset+4, 2, ENC_BIG_ENDIAN);
break;
case TYPE_RADIO_ADMINISTRATIVE_STATE:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_radio_admin_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_radio_admin_state, tvb, offset+5, 1, ENC_BIG_ENDIAN);
break;
case TYPE_RADIO_OPERATIONAL_STATE:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_radio_op_state_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_radio_op_state_radio_state, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_radio_op_state_radio_cause, tvb, offset+6, 1, ENC_BIG_ENDIAN);
break;
case TYPE_RESULT_CODE:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_result_code, tvb, offset+4, optlen, ENC_BIG_ENDIAN);
break;
case TYPE_SESSION_ID:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_session_id, tvb, offset+4, optlen, ENC_NA);
break;
case TYPE_STATISTICS_TIMER:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_statistics_timer, tvb, offset+4, 2, ENC_BIG_ENDIAN);
break;
case TYPE_VENDOR_SPECIFIC_PAYLOAD:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_vsp_vendor_identifier, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_vsp_vendor_element_id, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_vsp_vendor_data, tvb, offset+10, optlen-6, ENC_NA);
break;
case TYPE_WTP_BOARD_DATA:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_board_data_vendor, tvb, offset+4, 4, ENC_BIG_ENDIAN);
offset += 8;
offset_end = offset + optlen -4;
while (offset < offset_end) {
offset += dissect_capwap_board_data(tvb, sub_msg_element_type_tree, offset);
}
break;
case TYPE_WTP_DESCRIPTOR:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_descriptor_max_radios, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_descriptor_radio_in_use, tvb, offset+5, 1, ENC_BIG_ENDIAN);
if (global_capwap_draft_8_cisco == 0)
{
number_encrypt = tvb_get_guint8(tvb,offset+6);
msg_element_type_item_flag = proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_descriptor_number_encrypt, tvb, offset+6, 1, ENC_BIG_ENDIAN);
sub_msg_element_type_flag_tree = proto_item_add_subtree(msg_element_type_item_flag, ett_capwap);
for (i=0; i < number_encrypt; i++) {
dissect_capwap_encryption_capabilities(tvb, sub_msg_element_type_flag_tree, offset+4+3+i*3);
}
offset_end = offset + optlen -4;
offset += 4 + 3 + number_encrypt * 3;
}
else
{
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_descriptor_encrypt_capabilities, tvb, offset+6, 2, ENC_BIG_ENDIAN);
offset_end = offset + optlen -4;
offset += 6 + 2;
}
while (offset < offset_end) {
offset += dissect_capwap_wtp_descriptor(tvb, sub_msg_element_type_tree, offset);
}
break;
case TYPE_WTP_FALLBACK:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_fallback, tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
case TYPE_WTP_FRAME_TUNNEL_MODE:
msg_element_type_item_flag = proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_frame_tunnel_mode, tvb, offset+4, 1, ENC_NA);
sub_msg_element_type_flag_tree = proto_item_add_subtree(msg_element_type_item_flag, ett_capwap);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_wtp_frame_tunnel_mode_n, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_wtp_frame_tunnel_mode_e, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_wtp_frame_tunnel_mode_l, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_wtp_frame_tunnel_mode_r, tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
case TYPE_WTP_MAC_TYPE:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_mac_type, tvb, offset+4, optlen, ENC_BIG_ENDIAN);
break;
case TYPE_WTP_NAME:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_name, tvb, offset+4, optlen, ENC_ASCII|ENC_NA);
break;
case TYPE_WTP_REBOOT_STATISTICS:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_reboot_count, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_ac_initiated_count, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_link_failure_count, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_sw_failure_count, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_hw_failure_count, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_other_failure_count, tvb, offset+14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_unknown_failure_count, tvb, offset+16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_wtp_reboot_statistics_last_failure_type, tvb, offset+18, 1, ENC_BIG_ENDIAN);
break;
case IEEE80211_ADD_WLAN:{
guint16 key_length;
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_wlan_id, tvb, offset+5, 1, ENC_BIG_ENDIAN);
msg_element_type_item_flag = proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability, tvb, offset+6, 2, ENC_BIG_ENDIAN);
sub_msg_element_type_flag_tree = proto_item_add_subtree(msg_element_type_item_flag, ett_capwap_element_ieee80211_add_wlan_capability);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_e, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_i, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_c, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_f, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_p, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_s, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_b, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_a, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_m, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_q, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_t, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_d, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_v, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_o, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_k, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_flag_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_capability_l, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_key_index, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_key_status, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_key_length, tvb, offset+10, 2, ENC_BIG_ENDIAN);
key_length = tvb_get_ntohs(tvb, offset+10);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_key, tvb, offset+12, key_length, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_group_tsc, tvb, offset+key_length+12, 6, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_qos, tvb, offset+key_length+18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_auth_type, tvb, offset+key_length+19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_mac_mode, tvb, offset+key_length+20, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_tunnel_mode, tvb, offset+key_length+21, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_suppress_ssid, tvb, offset+key_length+22, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_add_wlan_ssid, tvb, offset+key_length+23, optlen-(key_length+23-4), ENC_ASCII|ENC_NA);
}
break;
case IEEE80211_ASSIGNED_WTP_BSSID:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_wlan_id, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_bssid, tvb, offset+6, 6, ENC_NA);
break;
case IEEE80211_DELETE_WLAN:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_delete_wlan_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_delete_wlan_wlan_id, tvb, offset+5, 1, ENC_BIG_ENDIAN);
break;
case IEEE80211_RATE_SET:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_rate_set_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_rate_set_rate_set, tvb, offset+5, optlen-1, ENC_NA);
break;
case IEEE80211_STATION_SESSION_KEY:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_mac, tvb, offset+4, 6, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_flags, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_flags_a, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_flags_c, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_pairwire_tsc, tvb, offset+12, 6, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_pairwire_rsc, tvb, offset+18, 6, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_station_session_key_key, tvb, offset+24, optlen-24, ENC_NA);
break;
case IEEE80211_WTP_RADIO_INFORMATION:
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_id, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_reserved, tvb, offset+5, 3, ENC_NA);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_n, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_g, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_a, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_msg_element_type_tree, hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_b, tvb, offset+8, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
return 2+2+optlen;
}
static int
dissect_capwap_message_element(tvbuff_t *tvb, proto_tree *capwap_control_tree, guint offset)
{
guint plen = 0, offset_end;
proto_item *ti;
proto_tree *capwap_message_element_tree;
ti = proto_tree_add_item(capwap_control_tree, hf_capwap_message_element, tvb, offset, tvb_reported_length(tvb) - offset, ENC_NA);
capwap_message_element_tree = proto_item_add_subtree(ti, ett_capwap);
offset_end = tvb_reported_length(tvb);
while (offset+plen < offset_end) {
plen += dissect_capwap_message_element_type(tvb, capwap_message_element_tree, offset+plen);
}
return plen;
}
static int
dissect_capwap_data_keep_alive(tvbuff_t *tvb, packet_info *pinfo, proto_tree *capwap_data_tree, guint offset)
{
guint16 len;
guint plen = 0, offset_end;
proto_item *ti;
proto_tree *capwap_data_keep_alive_tree;
ti = proto_tree_add_item(capwap_data_tree, hf_capwap_data_keep_alive, tvb, offset, tvb_reported_length(tvb), ENC_NA);
capwap_data_keep_alive_tree = proto_item_add_subtree(ti, ett_capwap);
ti = proto_tree_add_item(capwap_data_keep_alive_tree, hf_capwap_data_keep_alive_length, tvb, offset, 2, ENC_BIG_ENDIAN);
len = tvb_get_ntohs(tvb, offset);
if (len != tvb_reported_length(tvb))
expert_add_info(pinfo, ti, &ei_capwap_data_keep_alive_length);
plen += 2;
offset_end = tvb_reported_length(tvb);
while (offset+plen < offset_end) {
plen += dissect_capwap_message_element_type(tvb, capwap_data_keep_alive_tree, offset+plen);
}
return plen;
}
static int
dissect_capwap_control_header(tvbuff_t *tvb, proto_tree *capwap_control_tree, guint offset, packet_info *pinfo)
{
guint plen = 0;
proto_item *ti, *ti_flag;
proto_tree *capwap_control_header_tree;
proto_tree *capwap_control_msg_type_tree;
ti = proto_tree_add_item(capwap_control_tree, hf_capwap_control_header, tvb, offset, 8, ENC_NA);
capwap_control_header_tree = proto_item_add_subtree(ti, ett_capwap);
ti_flag = proto_tree_add_item(capwap_control_header_tree, hf_capwap_control_header_msg_type, tvb, offset, 4, ENC_BIG_ENDIAN);
capwap_control_msg_type_tree = proto_item_add_subtree(ti_flag, ett_capwap);
proto_tree_add_item(capwap_control_msg_type_tree, hf_capwap_control_header_msg_type_enterprise_nbr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_control_msg_type_tree, hf_capwap_control_header_msg_type_enterprise_specific, tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s",val_to_str(tvb_get_ntohl(tvb, offset),message_type,"Unknown Message Type (0x%x)"));
plen += 4;
proto_tree_add_item(capwap_control_header_tree, hf_capwap_control_header_seq_number, tvb, offset+plen, 1, ENC_BIG_ENDIAN);
plen += 1;
proto_tree_add_item(capwap_control_header_tree, hf_capwap_control_header_msg_element_length, tvb, offset+plen, 2, ENC_BIG_ENDIAN);
plen += 2;
proto_tree_add_item(capwap_control_header_tree, hf_capwap_control_header_flags, tvb, offset+plen, 1, ENC_BIG_ENDIAN);
plen += 1;
return plen;
}
static int
dissect_capwap_header(tvbuff_t *tvb, proto_tree *capwap_control_tree, guint offset, packet_info *pinfo, guint8 *payload_type, guint8 *payload_wbid, gboolean *fragment_is, gboolean *fragment_more, guint32 *fragment_id, guint32 *fragment_offset)
{
guint plen = 0, hlen = 0;
proto_item *ti, *ti_flag, *ti_len;
proto_tree *capwap_header_tree;
proto_tree *capwap_header_flags_tree;
guint flags = 0;
guint8 maclength, wirelesslength;
guint align = 0;
hlen = tvb_get_bits8(tvb, (offset+plen)*8, 5)*4-1;
ti = proto_tree_add_item(capwap_control_tree, hf_capwap_header, tvb, offset+plen, hlen, ENC_NA);
capwap_header_tree = proto_item_add_subtree(ti, ett_capwap);
ti_len = proto_tree_add_item(capwap_header_tree, hf_capwap_header_hlen, tvb, offset+plen, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_len, " (%d)",hlen+1);
proto_tree_add_item(capwap_header_tree, hf_capwap_header_rid, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_tree, hf_capwap_header_wbid, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
*payload_wbid = tvb_get_bits8(tvb, (offset+plen)*8+10, 5);
flags = tvb_get_bits16(tvb, (offset+plen)*8+15, 9, ENC_BIG_ENDIAN);
ti_flag = proto_tree_add_item(capwap_header_tree, hf_capwap_header_flags, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
capwap_header_flags_tree = proto_item_add_subtree(ti_flag, ett_capwap);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_t, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_f, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_l, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_w, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_m, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_k, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_flags_tree, hf_capwap_header_flags_r, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
*fragment_is = ((flags & 0x80) == 0x80) ? TRUE : FALSE;
*fragment_more = ((flags &0x40) == 0x40) ? FALSE : TRUE;
if (flags &0x08 ) {
col_append_str(pinfo->cinfo, COL_INFO, " Keep-Alive");
*payload_type = 0xff;
} else
*payload_type = tvb_get_bits8(tvb, (offset+plen)*8+15,1);
plen += 3;
proto_tree_add_item(capwap_header_tree, hf_capwap_header_fragment_id, tvb, offset+plen, 2, ENC_BIG_ENDIAN);
*fragment_id = (guint32)tvb_get_ntohs(tvb, offset+plen);
plen += 2;
proto_tree_add_item(capwap_header_tree, hf_capwap_header_fragment_offset, tvb, offset+plen, 2, ENC_BIG_ENDIAN);
*fragment_offset = 8 * (guint32)tvb_get_bits16(tvb, (offset+plen)*8, 13, ENC_BIG_ENDIAN);
proto_tree_add_item(capwap_header_tree, hf_capwap_header_reserved, tvb, offset+plen+1, 1, ENC_BIG_ENDIAN);
plen += 2;
if (flags & 0x10 ) {
maclength=tvb_get_guint8(tvb, offset+plen);
proto_tree_add_item(capwap_header_tree, hf_capwap_header_mac_length, tvb, offset+plen, 1, ENC_BIG_ENDIAN);
plen += 1;
if (maclength == 6) {
proto_tree_add_item(capwap_header_tree, hf_capwap_header_mac_eui48, tvb, offset+plen, maclength, ENC_NA);
} else if (maclength == 8) {
proto_tree_add_item(capwap_header_tree, hf_capwap_header_mac_eui64, tvb, offset+plen, maclength, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(capwap_header_tree, hf_capwap_header_mac_data, tvb, offset+plen, maclength, ENC_NA);
}
plen += maclength;
align = 4-((offset+plen)%4);
if (align != 4)
{
proto_tree_add_item(capwap_header_tree, hf_capwap_header_padding, tvb, offset+plen, align, ENC_NA);
plen += align;
}
}
if (flags & 0x20 ) {
wirelesslength=tvb_get_guint8(tvb, offset+plen);
if (global_capwap_draft_8_cisco == 1)
{
plen += 1;
wirelesslength = 4;
}
proto_tree_add_item(capwap_header_tree, hf_capwap_header_wireless_length, tvb, offset+plen, 1, ENC_BIG_ENDIAN);
plen += 1;
proto_tree_add_item(capwap_header_tree, hf_capwap_header_wireless_data, tvb, offset+plen, wirelesslength, ENC_NA);
if (*payload_wbid == 1)
{
dissect_capwap_data_message_bindings_ieee80211(tvb, capwap_header_tree, offset+plen, pinfo);
}
plen += wirelesslength;
align = 4-((offset+plen)%4);
if (align != 4)
{
proto_tree_add_item(capwap_header_tree, hf_capwap_header_padding, tvb, offset+plen, align, ENC_NA);
plen += align;
}
}
if ((plen != hlen) && global_capwap_draft_8_cisco == 0)
{
expert_add_info_format(pinfo, ti_len, &ei_capwap_header_length_bad, "Wrong calculate length (%d) =! header length (%d) ! (May be try to use Cisco Wireless Controller Support Preference ?)", plen, hlen);
}
return hlen;
}
static int
dissect_capwap_preamble(tvbuff_t *tvb, proto_tree *capwap_control_tree, guint offset, guint8 *type_header)
{
guint plen = 0;
proto_item *ti;
proto_tree *capwap_preamble_tree;
ti = proto_tree_add_item(capwap_control_tree, hf_capwap_preamble, tvb, offset+plen, -1, ENC_NA);
capwap_preamble_tree = proto_item_add_subtree(ti, ett_capwap);
proto_tree_add_item(capwap_preamble_tree, hf_capwap_preamble_version, tvb, offset+plen, 1, ENC_NA);
proto_tree_add_item(capwap_preamble_tree, hf_capwap_preamble_type, tvb, offset+plen, 1, ENC_NA);
*type_header = tvb_get_guint8(tvb, offset+plen) & 0x0F;
plen++;
if (*type_header == 1) {
proto_tree_add_item(capwap_preamble_tree, hf_capwap_preamble_reserved, tvb, offset+plen, 3, ENC_BIG_ENDIAN);
plen +=3;
}
proto_item_set_len(ti, plen);
return plen;
}
static int
dissect_capwap_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *capwap_control_tree;
guint offset = 0;
tvbuff_t *next_tvb = NULL;
guint8 type_header;
guint8 payload_type;
guint8 payload_wbid;
gboolean fragment_is;
gboolean fragment_more;
guint32 fragment_id;
guint32 fragment_offset;
fragment_head *frag_msg = NULL;
gboolean save_fragmented;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CAPWAP");
col_set_str(pinfo->cinfo, COL_INFO, "CAPWAP-Control");
ti = proto_tree_add_item(tree, proto_capwap, tvb, 0, -1, ENC_NA);
capwap_control_tree = proto_item_add_subtree(ti, ett_capwap);
offset += dissect_capwap_preamble(tvb, capwap_control_tree, offset, &type_header);
if (type_header == 1) {
next_tvb = tvb_new_subset_remaining (tvb, offset);
call_dissector(dtls_handle, next_tvb, pinfo, tree);
return offset;
}
offset += dissect_capwap_header(tvb, capwap_control_tree, offset, pinfo, &payload_type, &payload_wbid, &fragment_is, &fragment_more, &fragment_id, &fragment_offset );
save_fragmented = pinfo->fragmented;
if (global_capwap_reassemble && fragment_is)
{
const int len_rem = tvb_reported_length_remaining(tvb, offset);
if (len_rem <= 0)
return offset;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_check(&capwap_reassembly_table,
tvb, offset, pinfo, fragment_id, NULL,
fragment_offset,
len_rem,
fragment_more);
next_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled CAPWAP", frag_msg,
&capwap_frag_items, NULL, tree);
if (next_tvb == NULL)
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Fragment ID: %u, Fragment Offset: %u)", fragment_id, fragment_offset);
}
else
{
offset = dissect_capwap_control_header(next_tvb, capwap_control_tree, 0, pinfo);
offset += dissect_capwap_message_element(next_tvb, capwap_control_tree, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Reassembled, Fragment ID: %u)", fragment_id);
}
}
else
{
offset += dissect_capwap_control_header(tvb, capwap_control_tree, offset, pinfo);
offset += dissect_capwap_message_element(tvb, capwap_control_tree, offset);
}
pinfo->fragmented = save_fragmented;
return offset;
}
static void
dissect_capwap_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *capwap_data_tree;
guint offset = 0;
tvbuff_t *next_tvb;
guint8 type_header;
guint8 payload_type;
guint8 payload_wbid;
gboolean fragment_is;
gboolean fragment_more;
guint32 fragment_id;
guint32 fragment_offset;
fragment_head *frag_msg = NULL;
gboolean save_fragmented;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CAPWAP");
col_set_str(pinfo->cinfo, COL_INFO, "CAPWAP-Data");
ti = proto_tree_add_item(tree, proto_capwap, tvb, 0, -1, ENC_NA);
capwap_data_tree = proto_item_add_subtree(ti, ett_capwap);
offset += dissect_capwap_preamble(tvb, capwap_data_tree, offset, &type_header);
if (type_header == 1) {
next_tvb = tvb_new_subset_remaining (tvb, offset);
call_dissector(dtls_handle, next_tvb, pinfo, tree);
return;
}
offset += dissect_capwap_header(tvb, capwap_data_tree, offset, pinfo, &payload_type, &payload_wbid, &fragment_is, &fragment_more, &fragment_id, &fragment_offset);
save_fragmented = pinfo->fragmented;
if (global_capwap_reassemble && fragment_is)
{
gint len_rem = tvb_reported_length_remaining(tvb, offset);
if (len_rem <= 0)
return;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_check(&capwap_reassembly_table,
tvb, offset, pinfo, fragment_id, NULL,
fragment_offset,
len_rem,
fragment_more);
next_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled CAPWAP", frag_msg,
&capwap_frag_items, NULL, tree);
if (next_tvb == NULL)
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle,next_tvb, pinfo, tree);
col_append_fstr(pinfo->cinfo, COL_INFO, " (Fragment ID: %u, Fragment Offset: %u)", fragment_id, fragment_offset);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (Reassembled, Fragment ID: %u)", fragment_id);
}
}
else
{
next_tvb = tvb_new_subset_remaining (tvb, offset);
}
if (payload_type == 0) {
call_dissector(ieee8023_handle, next_tvb, pinfo, tree);
}
else if (payload_type == 0xff) {
dissect_capwap_data_keep_alive(next_tvb, pinfo, capwap_data_tree, 0);
}
else
{
switch (payload_wbid) {
case 0:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
case 1:
call_dissector(global_capwap_swap_frame_control ? ieee80211_bsfc_handle : ieee80211_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
pinfo->fragmented = save_fragmented;
}
void
proto_register_capwap_control(void)
{
module_t *capwap_module;
static hf_register_info hf[] = {
{ &hf_capwap_preamble,
{ "Preamble", "capwap.preamble",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_preamble_version,
{ "Version", "capwap.preamble.version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Version of CAPWAP", HFILL }},
{ &hf_capwap_preamble_type,
{ "Type", "capwap.preamble.type",
FT_UINT8, BASE_DEC, VALS(type_header_vals), 0x0F,
"Type of Payload", HFILL }},
{ &hf_capwap_preamble_reserved,
{ "Reserved", "capwap.preamble.reserved",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_header,
{ "Header", "capwap.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_header_hlen,
{ "Header Length", "capwap.header.length",
FT_UINT24, BASE_DEC, NULL, 0xF80000,
"Length of the CAPWAP transport header in 4-byte words (similar to IP header length)", HFILL }},
{ &hf_capwap_header_rid,
{ "Radio ID", "capwap.header.rid",
FT_UINT24, BASE_DEC, NULL, 0x07C000,
NULL, HFILL }},
{ &hf_capwap_header_wbid,
{ "Wireless Binding ID", "capwap.header.wbid",
FT_UINT24, BASE_DEC, VALS(type_wbid), 0x003E00,
NULL, HFILL }},
{ &hf_capwap_header_flags,
{ "Header Flags", "capwap.header.flags",
FT_UINT24, BASE_HEX, NULL, 0x0001FF,
NULL, HFILL }},
{ &hf_capwap_header_flags_t,
{ "Payload Type", "capwap.header.flags.t",
FT_BOOLEAN, 24, TFS(&flag_type_t), 0x0000100,
NULL, HFILL }},
{ &hf_capwap_header_flags_f,
{ "Fragment", "capwap.header.flags.f",
FT_BOOLEAN, 24, TFS(&flag_type_f), 0x000080,
NULL, HFILL }},
{ &hf_capwap_header_flags_l,
{ "Last Fragment", "capwap.header.flags.l",
FT_BOOLEAN, 24, TFS(&flag_type_l), 0x000040,
NULL, HFILL }},
{ &hf_capwap_header_flags_w,
{ "Wireless header", "capwap.header.flags.w",
FT_BOOLEAN, 24, TFS(&flag_type_w), 0x000020,
NULL, HFILL }},
{ &hf_capwap_header_flags_m,
{ "Radio MAC header", "capwap.header.flags.m",
FT_BOOLEAN, 24, TFS(&flag_type_m), 0x000010,
NULL, HFILL }},
{ &hf_capwap_header_flags_k,
{ "Keep-Alive", "capwap.header.flags.k",
FT_BOOLEAN, 24, TFS(&flag_type_k), 0x000008,
NULL, HFILL }},
{ &hf_capwap_header_flags_r,
{ "Reserved", "capwap.header.flags.r",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), 0x000007,
NULL, HFILL }},
{ &hf_capwap_header_fragment_id,
{ "Fragment ID", "capwap.header.fragment.id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_fragment_offset,
{ "Fragment Offset", "capwap.header.fragment.offset",
FT_UINT16, BASE_DEC, NULL, 0xFFF8,
NULL, HFILL }},
{ &hf_capwap_header_reserved,
{ "Reserved", "capwap.header.fragment.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0007,
NULL, HFILL }},
{ &hf_capwap_header_mac_length,
{ "MAC length", "capwap.header.mac.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_mac_eui48,
{ "MAC address", "capwap.header.mac.eui48",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_mac_eui64,
{ "MAC address", "capwap.header.mac.eui64",
FT_EUI64, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_mac_data,
{ "MAC address", "capwap.header.mac.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_length,
{ "Wireless length", "capwap.header.wireless.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data,
{ "Wireless data", "capwap.header.wireless.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_fi,
{ "Wireless data ieee80211 Frame Info", "capwap.header.wireless.data.ieee80211.fi",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_fi_rssi,
{ "Wireless data ieee80211 RSSI (dBm)", "capwap.header.wireless.data.ieee80211.fi.rssi",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_fi_snr,
{ "Wireless data ieee80211 SNR (dB)", "capwap.header.wireless.data.ieee80211.fi.snr",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_fi_data_rate,
{ "Wireless data ieee80211 Data Rate (Mbps)", "capwap.header.wireless.data.ieee80211.fi.data_rate",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_dest_wlan,
{ "Wireless data ieee80211 Destination WLANs", "capwap.header.wireless.data.ieee80211.dw",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_dw_wlan_id_bitmap,
{ "Wireless data ieee80211 Destination Wlan Id bitmap",
"capwap.header.wireless.data.ieee80211.dw.wlan_id_bitmap",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_wireless_data_ieee80211_dw_reserved,
{ "Wireless data ieee80211 Destination Wlan reserved", "capwap.header.wireless.data.ieee80211.dw.reserved",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_header_padding,
{ "Padding for 4 Byte Alignement", "capwap.header.padding",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header,
{ "Control Header", "capwap.control.header",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_msg_type,
{ "Message Type", "capwap.control.header.message_type",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_msg_type_enterprise_nbr,
{ "Message Type (Enterprise Number)", "capwap.control.header.message_type.enterprise_number",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_msg_type_enterprise_specific,
{ "Message Type (Enterprise Specific)", "capwap.control.header.message_type.enterprise_specific",
FT_UINT32, BASE_DEC, VALS(message_type), 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_seq_number,
{ "Sequence Number", "capwap.control.header.sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_msg_element_length,
{ "Message Element Length", "capwap.control.header.message_element_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_control_header_flags,
{ "Flags", "capwap.control.header.flags",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_message_element,
{ "Message Element", "capwap.message_element",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element,
{ "Type", "capwap.message_element",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type,
{ "Type", "capwap.message_element.type",
FT_UINT16, BASE_DEC, VALS(message_element_type_vals), 0x00,
"CAPWAP Message Element type", HFILL }},
{ &hf_capwap_msg_element_length,
{ "Length", "capwap.message_element.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"CAPWAP Message Element length", HFILL }},
{ &hf_capwap_msg_element_value,
{ "Value", "capwap.message_element.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
"CAPWAP Message Element value", HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_stations,
{ "Stations", "capwap.control.message_element.ac_descriptor.stations",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_limit,
{ "Limit Stations", "capwap.control.message_element.ac_descriptor.limit",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_active_wtp,
{ "Active WTPs", "capwap.control.message_element.ac_descriptor.active_wtp",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_max_wtp,
{ "Max WTPs", "capwap.control.message_element.ac_descriptor.max_wtp",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_security,
{ "Security Flags", "capwap.control.message_element.ac_descriptor.security",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_security_s,
{ "AC supports the pre-shared", "capwap.control.message_element.ac_descriptor.security.s",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x04,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_security_x,
{ "AC supports X.509 Certificate", "capwap.control.message_element.ac_descriptor.security.x",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_security_r,
{ "Reserved", "capwap.control.message_element.ac_descriptor.security.r",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0xF9,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_rmac_field,
{ "R-MAC Field", "capwap.control.message_element.ac_descriptor.rmac_field",
FT_UINT8, BASE_DEC, VALS(rmac_field_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_reserved,
{ "Reserved", "capwap.control.message_element.ac_descriptor.reserved",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_dtls_policy,
{ "DTLS Policy Flags", "capwap.control.message_element.ac_descriptor.dtls_policy",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_dtls_policy_d,
{ "DTLS-Enabled Data Channel Supported", "capwap.control.message_element.ac_descriptor.dtls_policy.d",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x04,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_dtls_policy_c,
{ "Clear Text Data Channel Supported", "capwap.control.message_element.ac_descriptor.dtls_policy.c",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_descriptor_dtls_policy_r,
{ "Reserved", "capwap.control.message_element.ac_descriptor.dtls_policy.r",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0xF9,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information,
{ "AC Information", "capwap.control.message_element.ac_information",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_vendor,
{ "AC Information Vendor", "capwap.control.message_element.ac_information.vendor",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_type,
{ "AC Information Type", "capwap.control.message_element.ac_information.type",
FT_UINT16, BASE_DEC, VALS(ac_information_type_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_length,
{ "AC Information Length", "capwap.control.message_element.ac_information.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_value,
{ "AC Information Value", "capwap.control.message_element.ac_information.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_hardware_version,
{ "AC Hardware Version", "capwap.control.message_element.ac_information.hardware_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_information_software_version,
{ "AC Software Version", "capwap.control.message_element.ac_information.software_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_ipv4_list,
{ "AC IPv4 List", "capwap.control.message_element.message_element.ac_ipv4_list",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_ipv6_list,
{ "AC IPv6 List", "capwap.control.message_element.message_element.ac_ipv6_list",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_capwap_control_ipv4,
{ "CAPWAP Control IP Address", "capwap.control.message_element.message_element.capwap_control_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_capwap_control_ipv6,
{ "CAPWAP Control IP Address", "capwap.control.message_element.message_element.capwap_control_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_capwap_control_wtp_count,
{ "CAPWAP Control WTP Count", "capwap.control.message_element.capwap_control_wtp_count",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_capwap_timers_discovery,
{ "CAPWAP Timers Discovery (Sec)", "capwap.control.message_element.capwap_timers_discovery",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_capwap_timers_echo_request,
{ "CAPWAP Timers Echo Request (Sec)", "capwap.control.message_element.capwap_timers_echo_request",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_decryption_error_report_period_radio_id,
{ "Decryption Error Report Period Radio ID", "capwap.control.message_element.decryption_error_report_period.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_decryption_error_report_period_interval,
{ "Decryption Error Report Report Interval (Sec)", "capwap.control.message_element.decryption_error_report_period.interval",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_name,
{ "AC Name", "capwap.control.message_element.ac_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ac_name_with_priority,
{ "AC Name Priority", "capwap.control.message_element.ac_name_with_priority",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_discovery_type,
{ "Discovery Type", "capwap.control.message_element.discovery_type",
FT_UINT8, BASE_DEC, VALS(discovery_type_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_idle_timeout,
{ "Idle Timeout (Sec)", "capwap.control.message_element.idle_timeout",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_location_data,
{ "Location Data", "capwap.control.message_element.location_data",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_maximum_message_length,
{ "Maximum Message Length", "capwap.control.message_element.maximum_message_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_radio_admin_id,
{ "Radio Administrative ID", "capwap.control.message_element.radio_admin.id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_radio_admin_state,
{ "Radio Administrative State", "capwap.control.message_element.radio_admin.state",
FT_UINT8, BASE_DEC, VALS(radio_admin_state_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_radio_op_state_radio_id,
{ "Radio Operational ID", "capwap.control.message_element.radio_op_state.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_radio_op_state_radio_state,
{ "Radio Operational State", "capwap.control.message_element.radio_op_state.radio_state",
FT_UINT8, BASE_DEC, VALS(radio_op_state_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_radio_op_state_radio_cause,
{ "Radio Operational Cause", "capwap.control.message_element.radio_op_state.radio_cause",
FT_UINT8, BASE_DEC, VALS(radio_op_cause_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_result_code,
{ "Result Code", "capwap.control.message_element.result_code",
FT_UINT32, BASE_DEC, VALS(result_code_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_session_id,
{ "Session ID", "capwap.control.message_element.session_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_statistics_timer,
{ "Statistics Timer (Sec)", "capwap.control.message_element.statistics_timer",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_vsp_vendor_identifier,
{ "Vendor Identifier", "capwap.control.message_element.vsp.vendor_identifier",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_vsp_vendor_element_id,
{ "Vendor Element ID", "capwap.control.message_element.vsp.vendor_element_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_vsp_vendor_data,
{ "Vendor Data", "capwap.control.message_element.vsp.vendor_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data,
{ "WTP Board Data", "capwap.control.message_element.wtp_board_data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_vendor,
{ "WTP Board Data Vendor", "capwap.control.message_element.wtp_board_data.vendor",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_type,
{ "Board Data Type", "capwap.control.message_element.wtp_board_data.type",
FT_UINT16, BASE_DEC, VALS(board_data_type_vals), 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_length,
{ "Board Data Length", "capwap.control.message_element.wtp_board_data.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_value,
{ "Board Data Value", "capwap.control.message_element.wtp_board_data.value",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_wtp_model_number,
{ "WTP Model Number", "capwap.control.message_element.wtp_board_data.wtp_model_number",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_wtp_serial_number,
{ "WTP Serial Number", "capwap.control.message_element.wtp_board_data.wtp_serial_number",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_wtp_board_id,
{ "WTP Board ID", "capwap.control.message_element.wtp_board_data.wtp_board_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_wtp_board_revision,
{ "WTP Board Revision", "capwap.control.message_element.wtp_board_data.wtp_board_revision",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_board_data_base_mac_address,
{ "Base Mac Address", "capwap.control.message_element.wtp_board_data.base_mac_address",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_max_radios,
{ "Max Radios", "capwap.control.message_element.wtp_descriptor.max_radios",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_radio_in_use,
{ "Radio in use", "capwap.control.message_element.wtp_descriptor.radio_in_use",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_number_encrypt,
{ "Encryption Capabilities (Number)", "capwap.control.message_element.wtp_descriptor.number_encrypt",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_encrypt,
{ "Encryption Capabilities", "capwap.control.message_element.wtp_descriptor.encrypt",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_encrypt_reserved,
{ "Reserved (Encrypt)", "capwap.control.message_element.wtp_descriptor.encrypt_reserved",
FT_UINT8, BASE_DEC, NULL, 0xE0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_encrypt_wbid,
{ "Encrypt WBID", "capwap.control.message_element.wtp_descriptor.encrypt_wbid",
FT_UINT8, BASE_DEC, VALS(type_wbid), 0x1F,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_encrypt_capabilities,
{ "Encryption Capabilities", "capwap.control.message_element.wtp_descriptor.encrypt_capabilities",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor,
{ "WTP Descriptor", "capwap.control.message_element.wtp_descriptor",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_vendor,
{ "WTP Descriptor Vendor", "capwap.control.message_element.wtp_descriptor.vendor",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x00,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_type,
{ "Descriptor Type", "capwap.control.message_element.wtp_descriptor.type",
FT_UINT16, BASE_DEC, VALS(wtp_descriptor_type_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_length,
{ "Descriptor Length", "capwap.control.message_element.wtp_descriptor.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_value,
{ "Descriptor Value", "capwap.control.message_element.wtp_descriptor.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_hardware_version,
{ "WTP Hardware Version", "capwap.control.message_element.wtp_descriptor.hardware_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_active_software_version,
{ "WTP Active Software Version", "capwap.control.message_element.wtp_descriptor.active_software_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_boot_version,
{ "WTP Boot Version", "capwap.control.message_element.wtp_descriptor.boot_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_descriptor_other_software_version,
{ "WTP Other Software Version", "capwap.control.message_element.wtp_descriptor.other_software_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_fallback,
{ "WTP Fallback", "capwap.control.message_element.wtp_fallback",
FT_UINT8, BASE_DEC, VALS(wtp_fallback_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_frame_tunnel_mode,
{ "WTP Frame Tunnel Mode", "capwap.control.message_element.wtp_frame_tunnel_mode",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_frame_tunnel_mode_n,
{ "Native Frame Tunnel Mode", "capwap.control.message_element.wtp_frame_tunnel_mode.n",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x08,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_frame_tunnel_mode_e,
{ "802.3 Frame Tunnel Mode", "capwap.control.message_element.wtp_frame_tunnel_mode.e",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x04,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_frame_tunnel_mode_l,
{ "Local Bridging", "capwap.control.message_element.wtp_frame_tunnel_mode.l",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_frame_tunnel_mode_r,
{ "Reserved", "capwap.control.message_element.wtp_frame_tunnel_mode.r",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0xF1,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_mac_type,
{ "WTP MAC Type", "capwap.control.message_element.wtp_mac_type",
FT_UINT8, BASE_DEC, VALS(wtp_mac_vals), 0x0,
"The MAC mode of operation supported by the WTP", HFILL }},
{ &hf_capwap_msg_element_type_wtp_name,
{ "WTP Name", "capwap.control.message_element.wtp_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_reboot_count,
{ "Reboot Count", "capwap.control.message_element.wtp_reboot_statistics.reboot_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of reboots that have occurred due to a WTP crash", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_ac_initiated_count,
{ "AC Initiated Count", "capwap.control.message_element.wtp_reboot_statistics.ac_initiated_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of reboots that have occurred at the request of a CAPWAP protocol message", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_link_failure_count,
{ "Link Failure Count", "capwap.control.message_element.wtp_reboot_statistics.link_failure_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of times that a CAPWAP protocol connection with an AC has failed due to link failure", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_sw_failure_count,
{ "SW Failure Count", "capwap.control.message_element.wtp_reboot_statistics.sw_failure_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of times that a CAPWAP protocol connection with an AC has failed due to software-related reasons", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_hw_failure_count,
{ "HW Failure Count", "capwap.control.message_element.wtp_reboot_statistics.hw_failure_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of times that a CAPWAP protocol connection with an AC has failed due to hardware-related reasons", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_other_failure_count,
{ "Other Failure Count", "capwap.control.message_element.wtp_reboot_statistics.other_failure_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of times that a CAPWAP protocol connection with an AC has failed due to known reasons, other than AC initiated, link, SW or HW failure", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_unknown_failure_count,
{ "Unknown Failure Count", "capwap.control.message_element.wtp_reboot_statistics.unknown_failure_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of times that a CAPWAP protocol connection with an AC has failed for unknown reasons", HFILL }},
{ &hf_capwap_msg_element_type_wtp_reboot_statistics_last_failure_type,
{ "Last Failure Type", "capwap.control.message_element.wtp_reboot_statistics.last_failure_type",
FT_UINT8, BASE_DEC, VALS(last_failure_type_vals), 0x0,
"The failure type of the most recent WTP failure", HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_radio_id,
{ "Radio ID", "capwap.control.message_element.ieee80211_add_wlan.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_wlan_id,
{ "WLAN ID", "capwap.control.message_element.ieee80211_add_wlan.wlan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability,
{ "Capability", "capwap.control.message_element.ieee80211_add_wlan.capability",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_e,
{ "ESS", "capwap.control.message_element.ieee80211_add_wlan.capability.e",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_i,
{ "IBSS", "capwap.control.message_element.ieee80211_add_wlan.capability.i",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x4000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_c,
{ "CF-Pollable", "capwap.control.message_element.ieee80211_add_wlan.capability.c",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x2000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_f,
{ "CF-Poll Request", "capwap.control.message_element.ieee80211_add_wlan.capability.f",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x1000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_p,
{ "Privacy", "capwap.control.message_element.ieee80211_add_wlan.capability.p",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0800,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_s,
{ "Short Preamble", "capwap.control.message_element.ieee80211_add_wlan.capability.s",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_b,
{ "PBCC", "capwap.control.message_element.ieee80211_add_wlan.capability.b",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_a,
{ "Channek Agility", "capwap.control.message_element.ieee80211_add_wlan.capability.a",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_m,
{ "Spectrum Management", "capwap.control.message_element.ieee80211_add_wlan.capability.m",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_q,
{ "QoS", "capwap.control.message_element.ieee80211_add_wlan.capability.q",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0040,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_t,
{ "Short Slot Time", "capwap.control.message_element.ieee80211_add_wlan.capability.t",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0020,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_d,
{ "APSD", "capwap.control.message_element.ieee80211_add_wlan.capability.d",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0010,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_v,
{ "Reserved", "capwap.control.message_element.ieee80211_add_wlan.capability.v",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_o,
{ "DSSS-OFDM", "capwap.control.message_element.ieee80211_add_wlan.capability.o",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_k,
{ "Delayed Block ACK", "capwap.control.message_element.ieee80211_add_wlan.capability.k",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_capability_l,
{ "Immediate Block ACK", "capwap.control.message_element.ieee80211_add_wlan.capability.l",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x00001,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_key_index,
{ "Key-Index", "capwap.control.message_element.ieee80211_add_wlan.key_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_key_status,
{ "Key Status", "capwap.control.message_element.ieee80211_add_wlan.key_status",
FT_UINT8, BASE_DEC, VALS(ieee80211_add_wlan_key_status_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_key_length,
{ "Key Length", "capwap.control.message_element.ieee80211_add_wlan.key_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_key,
{ "Key", "capwap.control.message_element.ieee80211_add_wlan.key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_group_tsc,
{ "Group TSC", "capwap.control.message_element.ieee80211_add_wlan.group_tsc",
FT_UINT64, BASE_DEC, NULL, 0x00FFFFFF,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_qos,
{ "QoS", "capwap.control.message_element.ieee80211_add_wlan.qos",
FT_UINT8, BASE_DEC, VALS(ieee80211_add_wlan_qos_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_auth_type,
{ "Auth Type", "capwap.control.message_element.ieee80211_add_wlan.auth_type",
FT_UINT8, BASE_DEC, VALS(ieee80211_add_wlan_auth_type_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_mac_mode,
{ "MAC Mode", "capwap.control.message_element.ieee80211_add_wlan.mac_mode",
FT_UINT8, BASE_DEC, VALS(ieee80211_add_wlan_mac_mode_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_tunnel_mode,
{ "Tunnel Mode", "capwap.control.message_element.ieee80211_add_wlan.tunnel_mode",
FT_UINT8, BASE_DEC, VALS(ieee80211_add_wlan_tunnel_mode_vals), 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_suppress_ssid,
{ "Suppress SSID", "capwap.control.message_element.ieee80211_add_wlan.supress_ssid",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_add_wlan_ssid,
{ "SSID", "capwap.control.message_element.ieee80211_add_wlan.ssid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_radio_id,
{ "Radio ID", "capwap.control.message_element.ieee80211_assigned_wtp_bssid.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_wlan_id,
{ "WLAN ID", "capwap.control.message_element.ieee80211_assigned_wtp_bssid.wlan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_assigned_wtp_bssid_bssid,
{ "BSSID", "capwap.control.message_element.ieee80211_assigned_wtp_bssid.bssid",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_delete_wlan_radio_id,
{ "Radio ID", "capwap.control.message_element.ieee80211_delete_wlan.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_delete_wlan_wlan_id,
{ "WLAN ID", "capwap.control.message_element.ieee80211_delete_wlan.wlan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_rate_set_radio_id,
{ "Radio ID", "capwap.control.message_element.ieee80211_rate_set.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_rate_set_rate_set,
{ "Rate Set", "capwap.control.message_element.ieee80211_rate_set.rate_set",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_mac,
{ "Mac Address", "capwap.control.message_element.ieee80211_station_session_key.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
"The station's MAC Address", HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_flags,
{ "Flags", "capwap.control.message_element.ieee80211_station_session_key.flags",
FT_UINT16, BASE_DEC, NULL, 0x3FFF,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_flags_a,
{ "Flag A", "capwap.control.message_element.ieee80211_station_session_key.flags_a",
FT_BOOLEAN, 1, NULL, 0x2000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_flags_c,
{ "Flag C", "capwap.control.message_element.ieee80211_station_session_key.flags_c",
FT_BOOLEAN, 1, NULL, 0x1000,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_pairwire_tsc,
{ "Pairwise TSC", "capwap.control.message_element.ieee80211_station_session_key.pairwire_tsc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Transmit Sequence Counter (TSC)", HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_pairwire_rsc,
{ "Pairwise RSC", "capwap.control.message_element.ieee80211_station_session_key.pairwire_rsc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Receive Sequence Counter (TSC)", HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_station_session_key_key,
{ "Key", "capwap.control.message_element.ieee80211_station_session_key.key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_id,
{ "Radio ID", "capwap.control.message_element.ieee80211__wtp_radio_info.radio_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_reserved,
{ "Radio Type Reserved", "capwap.control.message_element.ieee80211_wtp_info_radio.radio_type_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_n,
{ "Radio Type 802.11n", "capwap.control.message_element.ieee80211_wtp_info_radio.radio_type_n",
FT_BOOLEAN, 4, TFS(&tfs_true_false), 0x0008,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_g,
{ "Radio Type 802.11g", "capwap.control.message_element.ieee80211_wtp_info_radio.radio_type_g",
FT_BOOLEAN, 4, TFS(&tfs_true_false), 0x0004,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_a,
{ "Radio Type 802.11a", "capwap.control.message_element.ieee80211_wtp_info_radio.radio_type_a",
FT_BOOLEAN, 4, TFS(&tfs_true_false), 0x0002,
NULL, HFILL }},
{ &hf_capwap_msg_element_type_ieee80211_wtp_radio_info_radio_type_b,
{ "Radio Type 802.11b", "capwap.control.message_element.ieee80211_wtp_info_radio.radio_type_b",
FT_BOOLEAN, 4, TFS(&tfs_true_false), 0x0001,
NULL, HFILL }},
{ & hf_capwap_data_keep_alive,
{ "Keep-Alive", "capwap.keep_alive", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ & hf_capwap_data_keep_alive_length,
{ "Message Element Length", "capwap.keep_alive.length", FT_UINT16, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragments,
{ "Message fragments", "capwap.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment,
{ "Message fragment", "capwap.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment_overlap,
{ "Message fragment overlap", "capwap.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"capwap.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL,
0x00, NULL, HFILL } },
{ &hf_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments",
"capwap.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment_too_long_fragment,
{ "Message fragment too long", "capwap.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment_error,
{ "Message defragmentation error", "capwap.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_msg_fragment_count,
{ "Message fragment count", "capwap.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_reassembled_in,
{ "Reassembled in", "capwap.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_msg_reassembled_length,
{ "Reassembled CAPWAP length", "capwap.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } }
};
static gint *ett[] = {
&ett_capwap,
&ett_capwap_element_ieee80211_add_wlan_capability,
&ett_msg_fragment,
&ett_msg_fragments
};
static ei_register_info ei[] = {
{ &ei_capwap_header_length_bad, { "capwap.header.length.bad", PI_MALFORMED, PI_WARN, "Wrong calculate length =! header length", EXPFILL }},
{ &ei_capwap_data_keep_alive_length, { "capwap.keep_alive.length.bad", PI_MALFORMED, PI_WARN, "Invalid Keep Alive length", EXPFILL }},
};
expert_module_t* expert_capwap;
proto_capwap = proto_register_protocol("Control And Provisioning of Wireless Access Points", "CAPWAP", "capwap");
proto_register_field_array(proto_capwap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_capwap = expert_register_protocol(proto_capwap);
expert_register_field_array(expert_capwap, ei, array_length(ei));
register_init_routine(&capwap_reassemble_init);
capwap_module = prefs_register_protocol(proto_capwap, proto_reg_handoff_capwap);
prefs_register_uint_preference(capwap_module, "udp.port.control", "CAPWAP Control UDP Port",
"Set the port for CAPWAP Control messages (if other than the default of 5246)",
10, &global_capwap_control_udp_port);
prefs_register_uint_preference(capwap_module, "udp.port.data", "CAPWAP Data UDP Port",
"Set the port for CAPWAP Data messages (if other than the default of 5247)",
10, &global_capwap_data_udp_port);
prefs_register_bool_preference(capwap_module, "draft_8_cisco", "Cisco Wireless Controller Support",
"Enable support of Cisco Wireless Controller (based on old 8 draft revision).",
&global_capwap_draft_8_cisco);
prefs_register_bool_preference(capwap_module, "reassemble", "Reassemble fragmented CAPWAP packets",
"Reassemble fragmented CAPWAP packets.",
&global_capwap_reassemble);
prefs_register_bool_preference(capwap_module, "swap_fc", "Swap Frame Control",
"Swap frame control bytes (needed for some APs).",
&global_capwap_swap_frame_control);
}
void
proto_reg_handoff_capwap(void)
{
static gboolean inited = FALSE;
static dissector_handle_t capwap_control_handle, capwap_data_handle;
static guint capwap_control_udp_port, capwap_data_udp_port;
if (!inited) {
capwap_control_handle = new_create_dissector_handle(dissect_capwap_control, proto_capwap);
capwap_data_handle = create_dissector_handle(dissect_capwap_data, proto_capwap);
dtls_handle = find_dissector("dtls");
ieee8023_handle = find_dissector("eth_withoutfcs");
ieee80211_handle = find_dissector("wlan_withoutfcs");
ieee80211_bsfc_handle = find_dissector("wlan_bsfc");
data_handle = find_dissector("data");
inited = TRUE;
} else {
dissector_delete_uint("udp.port", capwap_control_udp_port, capwap_control_handle);
dissector_delete_uint("udp.port", capwap_data_udp_port, capwap_data_handle);
}
dissector_add_uint("udp.port", global_capwap_control_udp_port, capwap_control_handle);
dissector_add_uint("udp.port", global_capwap_data_udp_port, capwap_data_handle);
capwap_control_udp_port = global_capwap_control_udp_port;
capwap_data_udp_port = global_capwap_data_udp_port;
}
