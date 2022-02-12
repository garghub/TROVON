static void bthci_evt_vendor_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Vendor as");
}
static gpointer bthci_evt_vendor_value(packet_info *pinfo _U_)
{
return NULL;
}
static void add_opcode(wmem_list_t *opcode_list, guint16 opcode, enum command_status command_status) {
opcode_list_data_t *opcode_list_data;
opcode_list_data = wmem_new(wmem_packet_scope(), opcode_list_data_t);
if (opcode_list_data) {
opcode_list_data->opcode = opcode;
opcode_list_data->command_status = command_status;
wmem_list_append(opcode_list, opcode_list_data);
}
}
static void
save_remote_device_name(tvbuff_t *tvb, gint offset, packet_info *pinfo,
guint8 size, guint8 *bd_addr, bluetooth_data_t *bluetooth_data)
{
gint i = 0;
guint8 length;
wmem_tree_key_t key[6];
guint32 interface_id;
guint32 adapter_id;
guint32 bd_addr_oui;
guint32 bd_addr_id;
guint32 frame_number;
gchar *name;
device_name_t *device_name;
if (!(!pinfo->fd->flags.visited && bd_addr)) return;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
while (i < size) {
length = tvb_get_guint8(tvb, offset + i);
if (length == 0) break;
switch(tvb_get_guint8(tvb, offset + i + 1)) {
case 0x08:
case 0x09:
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + i + 2, length - 1, ENC_UTF_8);
frame_number = pinfo->num;
bd_addr_oui = bd_addr[0] << 16 | bd_addr[1] << 8 | bd_addr[2];
bd_addr_id = bd_addr[3] << 16 | bd_addr[4] << 8 | bd_addr[5];
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &bd_addr_id;
key[3].length = 1;
key[3].key = &bd_addr_oui;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
device_name = (device_name_t *) wmem_new(wmem_file_scope(), device_name_t);
device_name->bd_addr_oui = bd_addr[0] << 16 | bd_addr[1] << 8 | bd_addr[2];
device_name->bd_addr_id = bd_addr[3] << 16 | bd_addr[4] << 8 | bd_addr[5];
device_name->name = wmem_strdup(wmem_file_scope(), name);
wmem_tree_insert32_array(bluetooth_data->bdaddr_to_name, key, device_name);
break;
}
i += length + 1;
}
}
static void send_hci_summary_status_tap(guint8 status, packet_info *pinfo, bluetooth_data_t *bluetooth_data)
{
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_STATUS;
tap_hci_summary->status = status;
if (try_val_to_str_ext(status, &bthci_cmd_status_vals_ext))
tap_hci_summary->name = val_to_str_ext(status, &bthci_cmd_status_vals_ext, "Unknown 0x%02x");
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
}
static void send_hci_summary_pending_tap(packet_info *pinfo, bluetooth_data_t *bluetooth_data)
{
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_STATUS_PENDING;
tap_hci_summary->status = 0;
tap_hci_summary->name = "Pending";
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
}
static void send_hci_summary_reason_tap(guint8 reason, packet_info *pinfo, bluetooth_data_t *bluetooth_data)
{
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_REASON;
tap_hci_summary->reason = reason;
if (try_val_to_str_ext(reason, &bthci_cmd_status_vals_ext))
tap_hci_summary->name = val_to_str_ext(reason, &bthci_cmd_status_vals_ext, "Unknown 0x%02x");
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
}
static int
dissect_bthci_evt_inquire_complete(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_connect_complete(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint32 connection_handle;
guint8 bd_addr[6];
guint8 status;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
connection_handle = tvb_get_letohs(tvb, offset) & 0x0FFF;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
wmem_tree_key_t key[5];
guint32 k_interface_id;
guint32 k_adapter_id;
guint32 k_connection_handle;
guint32 k_frame_number;
remote_bdaddr_t *remote_bdaddr;
chandle_session_t *chandle_session;
connection_mode_t *connection_mode;
k_interface_id = bluetooth_data->interface_id;
k_adapter_id = bluetooth_data->adapter_id;
k_connection_handle = connection_handle;
k_frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_connection_handle;
key[3].length = 1;
key[3].key = &k_frame_number;
key[4].length = 0;
key[4].key = NULL;
remote_bdaddr = (remote_bdaddr_t *) wmem_new(wmem_file_scope(), remote_bdaddr_t);
remote_bdaddr->interface_id = bluetooth_data->interface_id;
remote_bdaddr->adapter_id = bluetooth_data->adapter_id;
remote_bdaddr->chandle = connection_handle;
memcpy(remote_bdaddr->bd_addr, bd_addr, 6);
wmem_tree_insert32_array(bluetooth_data->chandle_to_bdaddr, key, remote_bdaddr);
chandle_session = (chandle_session_t *) wmem_new(wmem_file_scope(), chandle_session_t);
chandle_session->connect_in_frame = k_frame_number;
chandle_session->disconnect_in_frame = max_disconnect_in_frame;
wmem_tree_insert32_array(bluetooth_data->chandle_sessions, key, chandle_session);
connection_mode = (connection_mode_t *) wmem_new(wmem_file_scope(), connection_mode_t);
connection_mode->mode = 0;
connection_mode->change_in_frame = k_frame_number;
wmem_tree_insert32_array(bluetooth_data->chandle_to_mode, key, connection_mode);
}
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_encryption_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_connect_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
call_dissector(btcommon_cod_handle, tvb_new_subset_length(tvb, offset, 3), pinfo, tree);
offset += 3;
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_disconnect_complete(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint32 connection_handle;
guint8 status;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
connection_handle = tvb_get_letohs(tvb, offset) & 0x0FFF;
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_reason_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
wmem_tree_key_t key[4];
guint32 interface_id;
guint32 adapter_id;
chandle_session_t *chandle_session;
wmem_tree_t *subtree;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &connection_handle;
key[3].length = 0;
key[3].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(bluetooth_data->chandle_sessions, key);
chandle_session = (subtree) ? (chandle_session_t *) wmem_tree_lookup32_le(subtree, pinfo->num) : NULL;
if (chandle_session && chandle_session->connect_in_frame < pinfo->num)
chandle_session->disconnect_in_frame = pinfo->num;
}
return offset;
}
static int
dissect_bthci_evt_auth_complete(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_lmp_features(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint8 page_numer)
{
guint8 fc_lag;
proto_item *fl_lag_item;
proto_tree *lmp_tree = NULL;
if (tree) {
proto_item *lmp_item;
lmp_item = proto_tree_add_item(tree, hf_lmp_features, tvb, offset, 8, ENC_NA);
lmp_tree = proto_item_add_subtree(lmp_item, ett_lmp_subtree);
}
switch (page_numer) {
case 0:
proto_tree_add_item(lmp_tree, hf_lmp_feature_3slot_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_5slot_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_encryption, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_slot_offset, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_timing_accuracy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_role_switch, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_hold_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_sniff_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_park_state, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_power_control_requests, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_channel_quality_driven_data_rate, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_sco_link, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_hv2_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_hv3_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_u_law_log_synchronous_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_a_law_log_synchronous_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_cvsd_synchronous_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_paging_parameter_negotiation, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_power_control, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_transparent_synchronous_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
fl_lag_item = proto_tree_add_item(lmp_tree,hf_lmp_feature_flow_control_lag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
fc_lag = (tvb_get_guint8(tvb, offset) & 0x70) >> 4;
proto_item_append_text(fl_lag_item, " (%i bytes)", 256 * fc_lag);
proto_tree_add_item(lmp_tree,hf_lmp_feature_broadcast_encryption, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_24, tvb, offset, 1, ENC_NA);
proto_tree_add_item(lmp_tree, hf_lmp_feature_edr_acl_2mbps_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_edr_acl_3mbps_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_enhanced_inquiry_scan, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_interlaced_inquiry_scan, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_interlaced_page_scan, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_rssi_with_inquiry_results, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_ev3_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_ev4_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_ev5_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_34, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_afh_capable_slave, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_afh_classification_slave, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_br_edr_not_supported, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_le_supported_controller, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_3slot_edr_acl_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_5slot_edr_acl_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_sniff_subrating, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_pause_encryption, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_afh_capable_master, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_afh_classification_master, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_edr_esco_2mbps_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_edr_esco_3mbps_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_3slot_edr_esco_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_extended_inquiry_response, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_simultaneous_le_and_br_edr_controller, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_50, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_secure_simple_pairing, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_encapsulated_pdu, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_erroneous_data_reporting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_non_flushable_packet_boundary_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_55, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_link_supervision_timeout_changed_event, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_inquiry_tx_power_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_enhanced_power_control, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_59_62, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_extended_features, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 1:
proto_tree_add_item(lmp_tree, hf_lmp_feature_secure_simple_pairing_host, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_le_supported_host, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_simultaneous_le_and_br_edr_host, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved_67_71, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved, tvb, offset, 7, ENC_NA);
offset += 7;
break;
default:
proto_tree_add_item(lmp_tree, hf_lmp_feature_reserved, tvb, offset, 8, ENC_NA);
offset += 8;
}
return offset;
}
static int
dissect_bthci_evt_pin_code_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_link_key_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_link_key_notification(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_link_key, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_bthci_evt_key_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_return_link_keys(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint8 evt_num_keys;
evt_num_keys = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_keys, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (evt_num_keys--) {
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_link_key, tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int
dissect_bthci_evt_read_remote_support_features_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree, 0);
return offset;
}
static int
dissect_bthci_evt_remote_name_req_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint8 bd_addr[6];
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
proto_tree_add_item(tree, hf_bthci_evt_remote_name, tvb, offset, 248, ENC_UTF_8|ENC_NA);
if (!pinfo->fd->flags.visited) {
wmem_tree_key_t key[6];
guint32 interface_id;
guint32 adapter_id;
guint32 bd_addr_oui;
guint32 bd_addr_id;
guint32 frame_number;
gchar *name;
device_name_t *device_name;
name = tvb_get_string_enc(wmem_file_scope(), tvb, offset, 248, ENC_UTF_8);
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
bd_addr_oui = bd_addr[0] << 16 | bd_addr[1] << 8 | bd_addr[2];
bd_addr_id = bd_addr[3] << 16 | bd_addr[4] << 8 | bd_addr[5];
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &bd_addr_id;
key[3].length = 1;
key[3].key = &bd_addr_oui;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
device_name = (device_name_t *) wmem_new(wmem_file_scope(), device_name_t);
device_name->bd_addr_oui = bd_addr[0] << 16 | bd_addr[1] << 8 | bd_addr[2];
device_name->bd_addr_id = bd_addr[3] << 16 | bd_addr[4] << 8 | bd_addr[5];
device_name->name = name;
wmem_tree_insert32_array(bluetooth_data->bdaddr_to_name, key, device_name);
}
if (have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
tap_device->interface_id = bluetooth_data->interface_id;
tap_device->adapter_id = bluetooth_data->adapter_id;
memcpy(tap_device->bd_addr, bd_addr, 6);
tap_device->has_bd_addr = TRUE;
tap_device->is_local = FALSE;
tap_device->type = BLUETOOTH_DEVICE_NAME;
tap_device->data.name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 248, ENC_UTF_8);
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
offset += 248;
return offset;
}
static int
dissect_bthci_evt_read_remote_version_information_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, bluetooth_data_t *bluetooth_data, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_vers_nr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_comp_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_sub_vers_nr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (have_tap_listener(bluetooth_device_tap)) {
wmem_tree_t *subtree;
wmem_tree_key_t key[4];
guint32 interface_id;
guint32 adapter_id;
guint32 connection_handle;
remote_bdaddr_t *remote_bdaddr;
bluetooth_device_tap_t *tap_device;
guint8 lmp_version;
guint16 lmp_subversion;
guint16 manufacturer;
lmp_version = tvb_get_guint8(tvb, offset - 5);
manufacturer = tvb_get_letohs(tvb, offset - 4);
lmp_subversion = tvb_get_letohs(tvb, offset - 2);
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
connection_handle = tvb_get_guint16(tvb, offset - 7, ENC_LITTLE_ENDIAN) & 0x0fff;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &connection_handle;
key[3].length = 0;
key[3].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(bluetooth_data->chandle_to_bdaddr, key);
remote_bdaddr = (subtree) ? (remote_bdaddr_t *) wmem_tree_lookup32_le(subtree, pinfo->num) : NULL;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
tap_device->type = BLUETOOTH_DEVICE_REMOTE_VERSION;
tap_device->interface_id = bluetooth_data->interface_id;
tap_device->adapter_id = bluetooth_data->adapter_id;
if (remote_bdaddr) {
tap_device->has_bd_addr = TRUE;
memcpy(tap_device->bd_addr, remote_bdaddr->bd_addr, 6);
} else {
tap_device->has_bd_addr = FALSE;
}
tap_device->is_local = FALSE;
tap_device->data.remote_version.lmp_version = lmp_version;
tap_device->data.remote_version.lmp_subversion = lmp_subversion;
tap_device->data.remote_version.manufacturer = manufacturer;
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
return offset;
}
static int
dissect_bthci_evt_flush_occured(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_number_of_completed_packets(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 evt_num_handles;
evt_num_handles = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_handles, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (evt_num_handles--) {
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_compl_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static int
dissect_bthci_evt_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_item *handle_item;
guint32 connection_handle;
guint8 mode;
guint8 status;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
connection_handle = tvb_get_letohs(tvb, offset) & 0x0FFF;
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_curr_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
mode = tvb_get_guint8(tvb, offset);
offset += 1;
handle_item = proto_tree_add_item(tree, hf_bthci_evt_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(handle_item, " Baseband slots (%f msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
wmem_tree_key_t key[5];
guint32 interface_id;
guint32 adapter_id;
guint32 frame_number;
connection_mode_t *connection_mode;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &connection_handle;
key[3].length = 1;
key[3].key = &frame_number;
key[4].length = 0;
key[4].key = NULL;
connection_mode = (connection_mode_t *) wmem_new(wmem_file_scope(), connection_mode_t);
connection_mode->mode = mode;
connection_mode->change_in_frame = frame_number;
wmem_tree_insert32_array(bluetooth_data->chandle_to_mode, key, connection_mode);
}
return offset;
}
static int
dissect_bthci_evt_role_change(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint8 bd_addr[6];
guint8 role;
guint8 status;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
proto_tree_add_item(tree, hf_bthci_evt_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
role = tvb_get_guint8(tvb, offset);
offset += 1;
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
guint32 interface_id;
guint32 adapter_id;
guint32 bd_addr_oui;
guint32 bd_addr_id;
guint32 frame_number;
wmem_tree_key_t key[6];
device_role_t *device_role;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
bd_addr_oui = bd_addr[0] << 16 | bd_addr[1] << 8 | bd_addr[2];
bd_addr_id = bd_addr[3] << 16 | bd_addr[4] << 8 | bd_addr[5];
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &bd_addr_id;
key[3].length = 1;
key[3].key = &bd_addr_oui;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
device_role = (device_role_t *) wmem_new(wmem_file_scope(), device_role_t);
device_role->change_in_frame = frame_number;
if (role == 0)
device_role->role = ROLE_SLAVE;
else if (role == 1)
device_role->role = ROLE_MASTER;
else
device_role->role = ROLE_UNKNOWN;
wmem_tree_insert32_array(bluetooth_data->bdaddr_to_role, key, device_role);
}
return offset;
}
static int
dissect_bthci_evt_hardware_error(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_hardware_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_HARDWARE_ERROR;
tap_hci_summary->hardware_error = tvb_get_guint8(tvb, offset - 1);
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
return offset;
}
static int
dissect_bthci_evt_loopback_command(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(bthci_cmd_handle, next_tvb, pinfo, tree, bluetooth_data);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_bthci_evt_data_buffer_overflow(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_read_clock_offset_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_item *handle_item;
gint16 clk;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
handle_item = proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
clk = tvb_get_letohs(tvb, offset) & 0x7FFF;
proto_item_append_text(handle_item, " (%g ms)", 1.25*clk);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_max_slots_change(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_max_slots, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_qos_violation(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_conn_packet_type_changed(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint16 packet_types;
proto_tree *handle_tree;
proto_item *ti_ptype_subtree;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
handle_tree = proto_tree_add_item(tree, hf_usable_packet_types, tvb, offset, 2, ENC_NA);
packet_types = tvb_get_letohs(tvb, offset);
ti_ptype_subtree = proto_item_add_subtree(handle_tree, ett_ptype_subtree);
proto_item_append_text(handle_tree, ": ");
if (packet_types & 0x0008)
proto_item_append_text(handle_tree, "DM1 ");
if (packet_types & 0x0010)
proto_item_append_text(handle_tree, "DH1 ");
if (packet_types & 0x0400)
proto_item_append_text(handle_tree, "DM3 ");
if (packet_types & 0x0800)
proto_item_append_text(handle_tree, "DH3 ");
if (packet_types & 0x4000)
proto_item_append_text(handle_tree, "DM5 ");
if (packet_types & 0x8000)
proto_item_append_text(handle_tree, "DH5 ");
if (packet_types & 0x0020)
proto_item_append_text(handle_tree, "HV1 ");
if (packet_types & 0x0040)
proto_item_append_text(handle_tree, "HV2 ");
if (packet_types & 0x0080)
proto_item_append_text(handle_tree, "HV3 ");
if (packet_types & 0x0002)
proto_item_append_text(handle_tree, "2-DH1 ");
if (packet_types & 0x0004)
proto_item_append_text(handle_tree, "3-DH1 ");
if (packet_types & 0x0100)
proto_item_append_text(handle_tree, "2-DH3 ");
if (packet_types & 0x0200)
proto_item_append_text(handle_tree, "3-DH3 ");
if (packet_types & 0x1000)
proto_item_append_text(handle_tree, "2-DH5 ");
if (packet_types & 0x2000)
proto_item_append_text(handle_tree, "3-DH5 ");
if (packet_types == 0)
proto_item_append_text(handle_tree, "does not support any packets");
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_2dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_3dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dm5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_dh5, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_ptype_subtree, hf_bthci_evt_link_type_hv3, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_command_status(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *main_tree, proto_tree *tree, wmem_list_t *opcode_list,
bluetooth_data_t *bluetooth_data)
{
proto_item *ti_opcode;
proto_tree *opcode_tree;
guint8 status_code;
guint16 opcode;
guint8 ogf;
gint hfx;
status_code = tvb_get_guint8(tvb, offset);
if (status_code != 0) {
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
}
else {
proto_tree_add_item(tree, hf_bthci_evt_status_pending, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_pending_tap(pinfo, bluetooth_data);
}
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_command_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
opcode = tvb_get_letohs(tvb, offset);
ogf = opcode >> 10;
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_EVENT_OPCODE;
tap_hci_summary->ogf = ogf;
tap_hci_summary->ocf = opcode & 0x03ff;
tap_hci_summary->event = 0x0f;
if (try_val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext))
tap_hci_summary->name = val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x");
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
if (status_code != 0)
add_opcode(opcode_list, opcode, COMMAND_STATUS_RESULT);
else
add_opcode(opcode_list, opcode, COMMAND_STATUS_PENDING);
ti_opcode = proto_tree_add_item(tree, hf_bthci_evt_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(ti_opcode, ett_opcode);
proto_tree_add_item(opcode_tree, hf_bthci_evt_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (ogf == HCI_OGF_LINK_CONTROL)
hfx = hf_bthci_evt_ocf_link_control;
else if (ogf == HCI_OGF_LINK_POLICY)
hfx = hf_bthci_evt_ocf_link_policy;
else if (ogf == HCI_OGF_HOST_CONTROLLER)
hfx = hf_bthci_evt_ocf_host_controller_and_baseband;
else if (ogf == HCI_OGF_INFORMATIONAL)
hfx = hf_bthci_evt_ocf_informational;
else if (ogf == HCI_OGF_STATUS)
hfx = hf_bthci_evt_ocf_status;
else if (ogf == HCI_OGF_TESTING)
hfx = hf_bthci_evt_ocf_testing;
else if (ogf == HCI_OGF_LOW_ENERGY)
hfx = hf_bthci_evt_ocf_low_energy;
else if (ogf == HCI_OGF_LOGO_TESTING)
hfx = hf_bthci_evt_ocf_logo_testing;
else
hfx = hf_bthci_evt_ocf;
proto_tree_add_item(opcode_tree, hfx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (ogf == HCI_OGF_VENDOR_SPECIFIC) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (Vendor Command 0x%04X [(opcode 0x%04X])", opcode & 0x03ff, opcode);
if (!dissector_try_uint_new(vendor_dissector_table, HCI_VENDOR_DEFAULT, tvb, pinfo, main_tree, TRUE, bluetooth_data)) {
if (bluetooth_data) {
hci_vendor_data_t *hci_vendor_data;
wmem_tree_key_t key[3];
guint32 interface_id;
guint32 adapter_id;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 0;
key[2].key = NULL;
hci_vendor_data = (hci_vendor_data_t *) wmem_tree_lookup32_array(bluetooth_data->hci_vendors, key);
if (hci_vendor_data) {
gint sub_offset;
sub_offset = dissector_try_uint_new(hci_vendor_table, hci_vendor_data->manufacturer, tvb, pinfo, main_tree, TRUE, bluetooth_data);
if (sub_offset > 0 && sub_offset < tvb_captured_length_remaining(tvb, offset))
proto_tree_add_expert(tree, pinfo, &ei_parameter_unexpected, tvb, offset + sub_offset, tvb_captured_length_remaining(tvb, sub_offset + offset));
}
}
}
return tvb_captured_length(tvb);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x"));
}
return offset;
}
static int
dissect_bthci_evt_page_scan_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_page_scan_repetition_mode_change(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_inquire_result_with_rssi(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data, guint8 *bd_addr)
{
guint8 num, evt_num_responses;
evt_num_responses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (num = 0; num < evt_num_responses; num++) {
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, (num == 0) ? bd_addr : NULL);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
call_dissector(btcommon_cod_handle, tvb_new_subset_length(tvb, offset, 3), pinfo, tree);
offset += 3;
proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_rssi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
return offset;
}
static int
dissect_bthci_evt_io_capability_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_io_capability_response(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_io_capability, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_oob_data_present, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_auth_requirements, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_user_confirmation_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_numeric_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_bthci_evt_user_passkey_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_remote_oob_data_request(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_simple_pairing_complete(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
return offset;
}
static int
dissect_bthci_evt_user_passkey_notification(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_passkey, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_bthci_evt_keypress_notification(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_notification_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_remote_host_sup_feat_notification(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
offset = dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree, 0);
return offset;
}
static int
dissect_bthci_evt_le_meta(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, wmem_list_t *opcode_list, bluetooth_data_t *bluetooth_data)
{
proto_item *item;
guint8 subevent_code;
guint16 connection_handle;
guint8 bd_addr[6];
guint8 status;
subevent_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_le_meta_subevent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str(subevent_code, evt_le_meta_subevent, "Unknown 0x%02x"));
offset += 1;
switch(subevent_code) {
case 0x01:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
connection_handle = tvb_get_letohs(tvb, offset) & 0x0FFF;
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_le_peer_address_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
item = proto_tree_add_item(tree, hf_bthci_evt_le_con_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (%g msec)", tvb_get_letohs(tvb, offset)*1.25);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_le_con_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (number events)");
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_le_supervision_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (%g sec)", tvb_get_letohs(tvb, offset)*0.01);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_le_master_clock_accuracy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
wmem_tree_key_t key[5];
guint32 k_interface_id;
guint32 k_adapter_id;
guint32 k_connection_handle;
guint32 k_frame_number;
remote_bdaddr_t *remote_bdaddr;
chandle_session_t *chandle_session;
k_interface_id = bluetooth_data->interface_id;
k_adapter_id = bluetooth_data->adapter_id;
k_connection_handle = connection_handle;
k_frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_connection_handle;
key[3].length = 1;
key[3].key = &k_frame_number;
key[4].length = 0;
key[4].key = NULL;
remote_bdaddr = (remote_bdaddr_t *) wmem_new(wmem_file_scope(), remote_bdaddr_t);
remote_bdaddr->interface_id = bluetooth_data->interface_id;
remote_bdaddr->adapter_id = bluetooth_data->adapter_id;
remote_bdaddr->chandle = connection_handle;
memcpy(remote_bdaddr->bd_addr, bd_addr, 6);
wmem_tree_insert32_array(bluetooth_data->chandle_to_bdaddr, key, remote_bdaddr);
chandle_session = (chandle_session_t *) wmem_new(wmem_file_scope(), chandle_session_t);
chandle_session->connect_in_frame = k_frame_number;
chandle_session->disconnect_in_frame = max_disconnect_in_frame;
wmem_tree_insert32_array(bluetooth_data->chandle_sessions, key, chandle_session);
}
add_opcode(opcode_list, 0x200D, COMMAND_STATUS_NORMAL);
break;
case 0x02:
{
guint8 i, num_reports, length;
num_reports = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_reports, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (i = 0; i < num_reports; i++) {
proto_tree_add_item(tree, hf_bthci_evt_advts_event_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_le_peer_address_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_data_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (length > 0) {
bluetooth_eir_ad_data_t *ad_data;
ad_data = wmem_new0(wmem_packet_scope(), bluetooth_eir_ad_data_t);
ad_data->interface_id = bluetooth_data->interface_id;
ad_data->adapter_id = bluetooth_data->adapter_id;
ad_data->bd_addr = bd_addr;
call_dissector_with_data(btcommon_ad_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree, ad_data);
save_remote_device_name(tvb, offset, pinfo, length, bd_addr, bluetooth_data);
offset += length;
}
proto_tree_add_item(tree, hf_bthci_evt_rssi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
}
break;
case 0x03:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_le_con_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (%g msec)", tvb_get_letohs(tvb, offset)*1.25);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_le_con_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (number events)");
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_le_supervision_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (%g sec)", tvb_get_letohs(tvb, offset)*0.01);
offset += 2;
add_opcode(opcode_list, 0x2013, COMMAND_STATUS_NORMAL);
break;
case 0x04:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_le_feature_00, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 8;
add_opcode(opcode_list, 0x2016, COMMAND_STATUS_NORMAL);
break;
case 0x05:
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_random_number, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_bthci_evt_encrypted_diversifier, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x06:
case 0x07:
case 0x08:
case 0x09:
case 0x0A:
case 0x0B:
default:
break;
}
return offset;
}
static int
dissect_bthci_evt_physical_link_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_channel_select_physical_link_recovery(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_disconnect_physical_link_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_reason_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_physical_link_loss_early_warning(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_link_loss_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_logical_link_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_logical_link_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_flow_spec_identifier, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_disconnect_logical_link_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_logical_link_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_reason_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_flow_spec_modify_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_number_of_completed_data_blocks(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 evt_num_handles;
proto_tree_add_item(tree, hf_bthci_evt_total_num_data_blocks, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
evt_num_handles = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_handles, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (evt_num_handles--) {
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_compl_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_compl_blocks, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static int
dissect_bthci_evt_amp_start_stop_test(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_test_scenario, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_amp_receiver_test(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_amp_controller_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_report_reason, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_report_event_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_frames, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_error_frames, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_bits, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_num_error_bits, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_bthci_evt_short_range_mode_change_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_short_range_mode_state, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_amp_status_change(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_amp_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_command_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *main_tree, proto_tree *tree,
wmem_list_t *opcode_list, bluetooth_data_t *bluetooth_data, guint32 *out_opcode)
{
proto_item *ti_opcode;
proto_tree *opcode_tree;
proto_item *item;
gint16 timeout;
guint8 num8;
guint i;
guint8 ogf;
guint32 accuracy;
guint8 bd_addr[6];
gboolean local_addr = FALSE;
gint hfx;
guint8 status;
wmem_tree_key_t key[4];
guint32 interface_id;
guint32 adapter_id;
guint32 frame_number;
guint32 opcode;
proto_tree_add_item(tree, hf_bthci_evt_num_command_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
opcode = tvb_get_letohs(tvb, offset);
ogf = opcode >> 10;
if (out_opcode)
*out_opcode = opcode;
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_EVENT_OPCODE;
tap_hci_summary->ogf = ogf;
tap_hci_summary->ocf = opcode & 0x03ff;
tap_hci_summary->event = 0x0e;
if (try_val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext))
tap_hci_summary->name = val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x");
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
ti_opcode = proto_tree_add_item(tree, hf_bthci_evt_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(ti_opcode, ett_opcode);
proto_tree_add_item(opcode_tree, hf_bthci_evt_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (ogf == HCI_OGF_LINK_CONTROL)
hfx = hf_bthci_evt_ocf_link_control;
else if (ogf == HCI_OGF_LINK_POLICY)
hfx = hf_bthci_evt_ocf_link_policy;
else if (ogf == HCI_OGF_HOST_CONTROLLER)
hfx = hf_bthci_evt_ocf_host_controller_and_baseband;
else if (ogf == HCI_OGF_INFORMATIONAL)
hfx = hf_bthci_evt_ocf_informational;
else if (ogf == HCI_OGF_STATUS)
hfx = hf_bthci_evt_ocf_status;
else if (ogf == HCI_OGF_TESTING)
hfx = hf_bthci_evt_ocf_testing;
else if (ogf == HCI_OGF_LOW_ENERGY)
hfx = hf_bthci_evt_ocf_low_energy;
else if (ogf == HCI_OGF_LOGO_TESTING)
hfx = hf_bthci_evt_ocf_logo_testing;
else
hfx = hf_bthci_evt_ocf;
proto_tree_add_item(opcode_tree, hfx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (ogf == HCI_OGF_VENDOR_SPECIFIC) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (Vendor Command 0x%04X [opcode 0x%04X])", opcode & 0x03ff, opcode);
if (!dissector_try_uint_new(vendor_dissector_table, HCI_VENDOR_DEFAULT, tvb, pinfo, main_tree, TRUE, bluetooth_data)) {
if (bluetooth_data) {
hci_vendor_data_t *hci_vendor_data;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 0;
key[2].key = NULL;
hci_vendor_data = (hci_vendor_data_t *) wmem_tree_lookup32_array(bluetooth_data->hci_vendors, key);
if (hci_vendor_data) {
gint sub_offset;
sub_offset = dissector_try_uint_new(hci_vendor_table, hci_vendor_data->manufacturer, tvb, pinfo, main_tree, TRUE, bluetooth_data);
if (sub_offset > 0 && sub_offset < tvb_captured_length_remaining(tvb, offset))
proto_tree_add_expert(tree, pinfo, &ei_parameter_unexpected, tvb, offset + sub_offset, tvb_captured_length_remaining(tvb, sub_offset + offset));
}
}
}
proto_tree_add_item(tree, hf_bthci_evt_ret_params, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset = tvb_captured_length(tvb);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
val_to_str_ext(opcode, &bthci_cmd_opcode_vals_ext, "Unknown 0x%04x"));
}
if (ogf != HCI_OGF_VENDOR_SPECIFIC) switch(opcode) {
case 0x0402:
case 0x0403:
case 0x0404:
case 0x080f:
case 0x0c01:
case 0x0c03:
case 0x0c05:
case 0x0c0a:
case 0x0c0b:
case 0x0c13:
case 0x0c16:
case 0x0c18:
case 0x0c1a:
case 0x0c1c:
case 0x0c1e:
case 0x0c20:
case 0x0c22:
case 0x0c24:
case 0x0c26:
case 0x0c2a:
case 0x0c2c:
case 0x0c2f:
case 0x0c31:
case 0x0c33:
case 0x0c3a:
case 0x0c3c:
case 0x0c3e:
case 0x0c3f:
case 0x0c43:
case 0x0c45:
case 0x0c47:
case 0x0c49:
case 0x0c52:
case 0x0c53:
case 0x0c56:
case 0x0c59:
case 0x0c5b:
case 0x0c62:
case 0x0c63:
case 0x0c65:
case 0x0c67:
case 0x0c6a:
case 0x0c6b:
case 0x0c6d:
case 0x1802:
case 0x1803:
case 0x1804:
case 0x1807:
case 0x1808:
case 0x1809:
case 0x2001:
case 0x2005:
case 0x2006:
case 0x2008:
case 0x2009:
case 0x200a:
case 0x200b:
case 0x200c:
case 0x200e:
case 0x2010:
case 0x2011:
case 0x2012:
case 0x2014:
case 0x201d:
case 0x201e:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
break;
case 0x1009:
local_addr = TRUE;
case 0x0408:
case 0x040b:
case 0x040c:
case 0x040d:
case 0x040e:
case 0x041a:
case 0x042b:
case 0x0434:
case 0x042c:
case 0x042d:
case 0x042e:
case 0x042f:
case 0x0430:
case 0x0433:
case 0x0c60:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, local_addr, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
if (!pinfo->fd->flags.visited && local_addr) {
localhost_bdaddr_entry_t *localhost_bdaddr_entry;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_bdaddr_entry = (localhost_bdaddr_entry_t *) wmem_new(wmem_file_scope(), localhost_bdaddr_entry_t);
localhost_bdaddr_entry->interface_id = interface_id;
localhost_bdaddr_entry->adapter_id = adapter_id;
memcpy(localhost_bdaddr_entry->bd_addr, bd_addr, 6);
wmem_tree_insert32_array(bluetooth_data->localhost_bdaddr, key, localhost_bdaddr_entry);
}
if (local_addr && have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
if (bluetooth_data) {
tap_device->interface_id = bluetooth_data->interface_id;
tap_device->adapter_id = bluetooth_data->adapter_id;
} else {
tap_device->interface_id = HCI_INTERFACE_DEFAULT;
tap_device->adapter_id = HCI_ADAPTER_DEFAULT;
}
memcpy(tap_device->bd_addr, bd_addr, 6);
tap_device->has_bd_addr = TRUE;
tap_device->is_local = TRUE;
tap_device->type = BLUETOOTH_DEVICE_LOCAL_ADAPTER;
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
break;
case 0x080d:
case 0x0811:
case 0x0c08:
case 0x0c28:
case 0x0c37:
case 0x0c5f:
case 0x1402:
case 0x201a:
case 0x201b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0c15:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
timeout = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset += 2;
break;
case 0x0c17:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
timeout = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset += 2;
break;
case 0x0c27:
case 0x0c36:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
timeout = tvb_get_letohs(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", timeout*0.625);
offset += 2;
break;
case 0x0c1b:
case 0x0c1d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_window, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0420:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_lmp_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 4;
break;
case 0x043b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_flow_spec_identifier, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0809:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_curr_role, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x080c:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_switch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_hold , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_sniff , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_park , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x080e:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_switch, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_hold , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_sniff , tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_link_policy_setting_park , tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0c09:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_pin_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c0d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_max_num_keys, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_read, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0c11:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_written, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c12:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_keys_deleted, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0c14:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_device_name, tvb, offset, 248, ENC_UTF_8|ENC_NA);
if (status == STATUS_SUCCESS && !pinfo->fd->flags.visited) {
gchar *name;
localhost_name_entry_t *localhost_name_entry;
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 248, ENC_UTF_8);
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_name_entry = (localhost_name_entry_t *) wmem_new(wmem_file_scope(), localhost_name_entry_t);
localhost_name_entry->interface_id = interface_id;
localhost_name_entry->adapter_id = adapter_id;
localhost_name_entry->name = wmem_strdup(wmem_file_scope(), name);
wmem_tree_insert32_array(bluetooth_data->localhost_name, key, localhost_name_entry);
}
if (status == STATUS_SUCCESS && have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
if (bluetooth_data) {
tap_device->interface_id = bluetooth_data->interface_id;
tap_device->adapter_id = bluetooth_data->adapter_id;
} else {
tap_device->interface_id = HCI_INTERFACE_DEFAULT;
tap_device->adapter_id = HCI_ADAPTER_DEFAULT;
}
tap_device->has_bd_addr = FALSE;
tap_device->is_local = TRUE;
tap_device->type = BLUETOOTH_DEVICE_NAME;
tap_device->data.name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 248, ENC_UTF_8);
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
offset += 248;
break;
case 0x0c19:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_scan_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c1f:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_authentication_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c21:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_encryption_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c23:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
call_dissector(btcommon_cod_handle, tvb_new_subset_length(tvb, offset, 3), pinfo, tree);
offset += 3;
break;
case 0x0c25:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_input_unused, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_input_coding, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_input_data_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_input_sample_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_linear_pcm_bit_pos, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_air_coding_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x0c29:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_broadcast_retransm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c2b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_page, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_inquiry, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_bthci_evt_hold_mode_act_periodic, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c2d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c2e:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_sco_flow_cont_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c38:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_num_supp_iac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c39:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
num8 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_curr_iac, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (i = 0; i < num8; i++) {
proto_tree_add_item(tree, hf_bthci_evt_iac_lap, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
}
break;
case 0x0c3b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_period_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c3d:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c42:
case 0x0c46:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_scan_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c44:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_inq_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c48:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_afh_ch_assessment_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c51:
{
bluetooth_eir_ad_data_t *eir_data;
eir_data = wmem_new0(wmem_packet_scope(), bluetooth_eir_ad_data_t);
eir_data->interface_id = bluetooth_data->interface_id;
eir_data->adapter_id = bluetooth_data->adapter_id;
eir_data->bd_addr = NULL;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_fec_required, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
call_dissector_with_data(btcommon_eir_handle, tvb_new_subset_length(tvb, offset, 240), pinfo, tree, eir_data);
offset += 240;
}
break;
case 0x0c55:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_simple_pairing_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c57:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_hash_c, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_bthci_evt_randomizer_r, tvb, offset, 16, ENC_NA);
offset += 16;
break;
case 0x0c58:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_power_level_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c5a:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_err_data_reporting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c61:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
item = proto_tree_add_item(tree, hf_bthci_evt_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
break;
case 0x0c64:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_location_domain_aware, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_location_domain, tvb, offset, 2, ENC_ASCII | ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_location_domain_options, tvb, offset, 1, ENC_ASCII | ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_location_options, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c66:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_flow_control_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c68:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level_gfsk, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level_dqpsk, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level_8dpsk, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x0c69:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_flush_to_us, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case 0x0c6c:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_le_supported_host, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_le_simultaneous_host, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1001: {
proto_item *hci_revision_item;
proto_item *manufacturer_item;
proto_item *lmp_subversion_item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_bthci_evt_hci_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
hci_revision_item = proto_tree_add_item(tree, hf_bthci_evt_hci_revision, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_vers_nr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
manufacturer_item = proto_tree_add_item(tree, hf_bthci_evt_comp_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
lmp_subversion_item = proto_tree_add_item(tree, hf_bthci_evt_sub_vers_nr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (status == STATUS_SUCCESS) {
hci_vendor_data_t *hci_vendor_data;
guint16 hci_revision;
guint16 manufacturer;
guint16 lmp_subversion;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 0;
key[2].key = NULL;
hci_vendor_data = (hci_vendor_data_t *) wmem_tree_lookup32_array(bluetooth_data->hci_vendors, key);
hci_revision = tvb_get_letohs(tvb, offset - 7);
manufacturer = tvb_get_letohs(tvb, offset - 4);
lmp_subversion = tvb_get_letohs(tvb, offset - 2);
if (have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
guint8 hci_version;
guint8 lmp_version;
hci_version = tvb_get_guint8(tvb, offset - 8);
lmp_version = tvb_get_guint8(tvb, offset - 5);
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
tap_device->type = BLUETOOTH_DEVICE_LOCAL_VERSION;
tap_device->interface_id = interface_id;
tap_device->adapter_id = adapter_id;
tap_device->has_bd_addr = FALSE;
tap_device->is_local = TRUE;
tap_device->data.local_version.hci_version = hci_version;
tap_device->data.local_version.hci_revision = hci_revision;
tap_device->data.local_version.lmp_version = lmp_version;
tap_device->data.local_version.lmp_subversion = lmp_subversion;
tap_device->data.local_version.manufacturer = manufacturer;
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
if (hci_vendor_data) {
proto_tree *sub_tree;
proto_item *sub_item;
if (manufacturer != hci_vendor_data->manufacturer) {
expert_add_info(pinfo, manufacturer_item, &ei_manufacturer_data_changed);
sub_tree = proto_item_add_subtree(manufacturer_item, ett_expert);
sub_item = proto_tree_add_uint(sub_tree, hf_changed_in_frame, tvb, 0, 0, hci_vendor_data->change_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
if (hci_revision != hci_vendor_data->hci_revision) {
expert_add_info(pinfo, hci_revision_item, &ei_manufacturer_data_changed);
sub_tree = proto_item_add_subtree(hci_revision_item, ett_expert);
sub_item = proto_tree_add_uint(sub_tree, hf_changed_in_frame, tvb, 0, 0, hci_vendor_data->change_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
if (lmp_subversion != hci_vendor_data->lmp_subversion) {
expert_add_info(pinfo, lmp_subversion_item, &ei_manufacturer_data_changed);
sub_tree = proto_item_add_subtree(lmp_subversion_item, ett_expert);
sub_item = proto_tree_add_uint(sub_tree, hf_changed_in_frame, tvb, 0, 0, hci_vendor_data->change_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
}
if (!pinfo->fd->flags.visited) {
hci_vendor_data_t *new_hci_vendor_data;
new_hci_vendor_data = wmem_new(wmem_file_scope(), hci_vendor_data_t);
new_hci_vendor_data->hci_revision = hci_revision;
new_hci_vendor_data->manufacturer = manufacturer;
new_hci_vendor_data->lmp_subversion = lmp_subversion;
new_hci_vendor_data->change_in_frame = pinfo->num;
if (hci_vendor_data && hci_vendor_data->change_in_frame < pinfo->num)
new_hci_vendor_data->previous = hci_vendor_data;
else
new_hci_vendor_data->previous = NULL;
wmem_tree_insert32_array(bluetooth_data->hci_vendors, key, new_hci_vendor_data);
}
}}
break;
case 0x1002:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_local_supported_cmds, tvb, offset, 64, ENC_NA);
offset += 64;
break;
case 0x1003:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
offset = dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree, 0);
break;
case 0x1004:
{
guint8 page_number;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
page_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_max_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree, page_number);
}
break;
case 0x1005:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_host_data_packet_length_acl, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_host_data_packet_length_sco, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_host_total_num_acl_data_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_host_total_num_sco_data_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x100a:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_max_acl_data_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_data_block_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_total_num_data_blocks, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x100b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_expert(tree, pinfo, &ei_event_undecoded, tvb, offset, tvb_captured_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
break;
case 0x1007:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_country_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1401:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_failed_contact_counter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x1403:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_link_quality, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1405:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_rssi, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1406:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_afh_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_afh_channel_map, tvb, offset, 10, ENC_NA);
offset += 10;
break;
case 0x1407:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_clock, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
accuracy = tvb_get_letohl(tvb, offset);
item = proto_tree_add_item(tree, hf_bthci_evt_clock_accuracy, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " %g msec", accuracy*0.3125);
offset += 2;
break;
case 0x1408:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_enc_key_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1409:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_amp_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_total_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_max_guaranteed_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_min_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_max_pdu_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_amp_controller_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_pal_capabilities_00, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_max_amp_assoc_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_max_flush_to_us, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_best_effort_flush_to_us, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case 0x140a:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_amp_remaining_assoc_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_amp_assoc_fragment, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
break;
case 0x140b:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_physical_link_handle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1801:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_loopback_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x2002:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
item = proto_tree_add_item(tree, hf_bthci_evt_le_acl_data_pkt_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if ( (tvb_get_letohs(tvb, offset) == 0) && (tvb_get_guint8(tvb, offset+2) == 0) )
proto_item_append_text(item, " (buffers shared between BR/EDR and LE) ");
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_total_num_le_acl_data_pkts, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x2003:
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
if (tree) {
proto_item *ti_le_features;
proto_item *ti_le_subtree;
ti_le_features = proto_tree_add_item(tree, hf_bthci_evt_le_features, tvb, offset, 8, ENC_NA);
ti_le_subtree = proto_item_add_subtree(ti_le_features, ett_lmp_subtree);
proto_tree_add_item(ti_le_subtree,hf_bthci_evt_le_feature_00, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 8;
}
break;
case 0x2007:
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_transmit_power_level, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
}
case 0x200f:
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_white_list_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
}
case 0x2015:
{
proto_tree *sub_tree;
proto_item *sub_item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
sub_item = proto_tree_add_item(tree, hf_bthci_evt_le_channel_map, tvb, offset, 5, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_le_channel_map);
call_dissector(btcommon_le_channel_map_handle, tvb_new_subset_length(tvb, offset, 5), pinfo, sub_tree);
offset += 5;
break;
}
case 0x2017:
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_encrypted_data, tvb, offset, 16, ENC_NA);
offset += 16;
break;
}
case 0x2018:
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_random_number, tvb, offset, 8, ENC_NA);
offset += 8;
break;
}
case 0x201c:
{
proto_item *ti_le_states;
proto_item *ti_le_states_subtree;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
ti_le_states = proto_tree_add_item(tree, hf_bthci_evt_le_states, tvb, offset, 8, ENC_NA);
ti_le_states_subtree = proto_item_add_subtree(ti_le_states, ett_le_state_subtree);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_00, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_01, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_02, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_03, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_04, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_05, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_06, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_07, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_10, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_11, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_12, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_13, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_14, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_15, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_16, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_17, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_20, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_21, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_22, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_23, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_24, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_25, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_26, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_27, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_30, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_31, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_32, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_33, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ti_le_states_subtree,hf_bthci_evt_le_states_34, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 5;
break;
}
case 0x201f:
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_le_num_packets, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
default:
proto_tree_add_expert(tree, pinfo, &ei_event_unknown_command, tvb, offset, tvb_captured_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
break;
}
add_opcode(opcode_list, opcode, COMMAND_STATUS_NORMAL);
return offset;
}
static int
dissect_bthci_evt_qos_setup_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_delay_variation, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_bthci_evt_change_conn_link_key_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_master_link_key_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_key_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_encryption_change(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_encryption_enable, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_bthci_evt_read_remote_ext_features_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint8 page_number;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
page_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_max_page_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset = dissect_bthci_evt_lmp_features(tvb, offset, pinfo, tree, page_number);
return offset;
}
static int
dissect_bthci_evt_sync_connection_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_item *item;
guint32 connection_handle;
guint8 bd_addr[6];
guint8 status;
wmem_tree_key_t key[5];
guint32 interface_id;
guint32 adapter_id;
guint32 frame_number;
wmem_tree_t *subtree;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status = tvb_get_guint8(tvb, offset);
send_hci_summary_status_tap(status, pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
connection_handle = tvb_get_letohs(tvb, offset) & 0x0FFF;
offset += 2;
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, bd_addr);
proto_tree_add_item(tree, hf_bthci_evt_sync_link_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_tx_interval, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset += 1;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_rtx_window, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_sync_rx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_sync_tx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_air_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
if (!pinfo->fd->flags.visited && status == STATUS_SUCCESS) {
remote_bdaddr_t *remote_bdaddr;
chandle_session_t *chandle_session;
bthci_sco_stream_number_t *sco_stream_number;
guint32 stream_number;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &connection_handle;
key[3].length = 1;
key[3].key = &frame_number;
key[4].length = 0;
key[4].key = NULL;
remote_bdaddr = (remote_bdaddr_t *) wmem_new(wmem_file_scope(), remote_bdaddr_t);
remote_bdaddr->interface_id = bluetooth_data->interface_id;
remote_bdaddr->adapter_id = bluetooth_data->adapter_id;
remote_bdaddr->chandle = connection_handle;
memcpy(remote_bdaddr->bd_addr, bd_addr, 6);
wmem_tree_insert32_array(bluetooth_data->chandle_to_bdaddr, key, remote_bdaddr);
chandle_session = (chandle_session_t *) wmem_new(wmem_file_scope(), chandle_session_t);
chandle_session->connect_in_frame = frame_number;
chandle_session->disconnect_in_frame = max_disconnect_in_frame;
wmem_tree_insert32_array(bluetooth_data->chandle_sessions, key, chandle_session);
key[2].length = 0;
key[2].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(bthci_sco_stream_numbers, key);
sco_stream_number = (subtree) ? (bthci_sco_stream_number_t *) wmem_tree_lookup32_le(subtree, pinfo->num) : NULL;
if (!sco_stream_number) {
stream_number = 1;
} else {
stream_number = sco_stream_number->stream_number + 1;
}
key[2].length = 1;
key[2].key = &frame_number;
key[3].length = 0;
key[3].key = NULL;
sco_stream_number = (bthci_sco_stream_number_t *) wmem_new(wmem_file_scope(), bthci_sco_stream_number_t);
sco_stream_number->stream_number = stream_number;
wmem_tree_insert32_array(bthci_sco_stream_numbers, key, sco_stream_number);
}
return offset;
}
static int
dissect_bthci_evt_sync_connection_changed(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_tx_interval, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset += 1;
item = proto_tree_add_item(tree, hf_bthci_evt_sync_rtx_window, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_guint8(tvb, offset)*0.625);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_sync_rx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_sync_tx_packet_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_sniff_subrating(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_max_tx_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_max_rx_latency, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_min_remote_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_min_local_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_flow_specification_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bthci_evt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_flow_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_service_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_token_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_token_bucket_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_peak_bandwidth, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_bthci_evt_latency, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_bthci_evt_enhanced_flush_complete(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_encryption_key_refresh_complete(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
proto_tree_add_item(tree, hf_bthci_evt_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_hci_summary_status_tap(tvb_get_guint8(tvb, offset), pinfo, bluetooth_data);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_link_supervision_timeout_changed(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item;
proto_tree_add_item(tree, hf_bthci_evt_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_bthci_evt_link_supervision_timeout, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " slots (%g msec)", tvb_get_letohs(tvb, offset)*0.625);
offset += 2;
return offset;
}
static int
dissect_bthci_evt_inquire_result(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, bluetooth_data_t *bluetooth_data)
{
guint8 num, evt_num_responses;
evt_num_responses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bthci_evt_num_responses, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
for (num = 0; num < evt_num_responses; num++) {
offset = dissect_bd_addr(hf_bthci_evt_bd_addr, pinfo, tree, tvb, offset, FALSE, bluetooth_data->interface_id, bluetooth_data->adapter_id, NULL);
proto_tree_add_item(tree, hf_bthci_evt_page_scan_repetition_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_period_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bthci_evt_page_scan_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
call_dissector(btcommon_cod_handle, tvb_new_subset_length(tvb, offset, 3), pinfo, tree);
offset += 3;
proto_tree_add_item(tree, hf_bthci_evt_clock_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static gint
dissect_bthci_evt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *bthci_evt_tree;
guint8 param_length, evt_code;
guint8 bd_addr[6];
gint offset = 0;
gint previous_offset = 0;
bluetooth_data_t *bluetooth_data;
wmem_list_t *opcode_list;
wmem_list_frame_t *opcode_list_frame;
bthci_cmd_data_t *lastest_bthci_cmd_data = NULL;
opcode_list_data_t *opcode_list_data = NULL;
guint32 opcode = G_MAXUINT32;
if (data == NULL)
return 0;
bluetooth_data = (bluetooth_data_t *) data;
opcode_list = wmem_list_new(wmem_packet_scope());
ti = proto_tree_add_item(tree, proto_bthci_evt, tvb, offset, -1, ENC_NA);
bthci_evt_tree = proto_item_add_subtree(ti, ett_bthci_evt);
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection ");
break;
}
set_address(&pinfo->src, AT_STRINGZ, 11, "controller");
set_address(&pinfo->dst, AT_STRINGZ, 5, "host");
set_address(&pinfo->net_src, AT_STRINGZ, 11, "controller");
set_address(&pinfo->net_dst, AT_STRINGZ, 5, "host");
set_address(&pinfo->dl_src, AT_STRINGZ, 11, "controller");
set_address(&pinfo->dl_dst, AT_STRINGZ, 5, "host");
if (!pinfo->fd->flags.visited) {
address *addr;
addr = (address *) wmem_memdup(wmem_file_scope(), &pinfo->dl_src, sizeof(address));
addr->data = wmem_memdup(wmem_file_scope(), pinfo->dl_src.data, pinfo->dl_src.len);
p_add_proto_data(wmem_file_scope(), pinfo, proto_bluetooth, BLUETOOTH_DATA_SRC, addr);
addr = (address *) wmem_memdup(wmem_file_scope(), &pinfo->dl_dst, sizeof(address));
addr->data = wmem_memdup(wmem_file_scope(), pinfo->dl_dst.data, pinfo->dl_dst.len);
p_add_proto_data(wmem_file_scope(), pinfo, proto_bluetooth, BLUETOOTH_DATA_DST, addr);
}
evt_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bthci_evt_tree, hf_bthci_evt_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(bthci_evt_tree, " - %s", val_to_str_ext_const(evt_code, &bthci_evt_evt_code_vals_ext, "Unknown 0x%08x"));
offset += 1;
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_EVENT;
tap_hci_summary->event = evt_code;
if (try_val_to_str_ext(evt_code, &bthci_evt_evt_code_vals_ext))
tap_hci_summary->name = val_to_str_ext(evt_code, &bthci_evt_evt_code_vals_ext, "Unknown 0x%04x");
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
param_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bthci_evt_tree, hf_bthci_evt_param_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_EVT");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(evt_code, &bthci_evt_evt_code_vals_ext, "Unknown 0x%08x"));
if (param_length > 0) {
switch(evt_code) {
case 0x01:
offset = dissect_bthci_evt_inquire_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0401, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x0403, COMMAND_STATUS_NORMAL);
break;
case 0x02:
offset = dissect_bthci_evt_inquire_result(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x03:
offset = dissect_bthci_evt_connect_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0405, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x0409, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x040A, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x043E, COMMAND_STATUS_NORMAL);
break;
case 0x04:
offset = dissect_bthci_evt_connect_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x05:
offset = dissect_bthci_evt_disconnect_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0406, COMMAND_STATUS_NORMAL);
break;
case 0x06:
offset = dissect_bthci_evt_auth_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0411, COMMAND_STATUS_NORMAL);
break;
case 0x07:
offset = dissect_bthci_evt_remote_name_req_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0419, COMMAND_STATUS_NORMAL);
break;
case 0x08:
offset = dissect_bthci_evt_encryption_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0413, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x2019, COMMAND_STATUS_NORMAL);
break;
case 0x09:
offset = dissect_bthci_evt_change_conn_link_key_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x0a:
offset = dissect_bthci_evt_master_link_key_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x0b:
offset = dissect_bthci_evt_read_remote_support_features_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x41B, COMMAND_STATUS_NORMAL);
break;
case 0x0c:
offset = dissect_bthci_evt_read_remote_version_information_complete(tvb, offset, pinfo, bluetooth_data, bthci_evt_tree);
add_opcode(opcode_list, 0x41D, COMMAND_STATUS_NORMAL);
break;
case 0x0d:
offset = dissect_bthci_evt_qos_setup_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x0e:
offset = dissect_bthci_evt_command_complete(tvb, offset, pinfo, tree, bthci_evt_tree, opcode_list, bluetooth_data, &opcode);
add_opcode(opcode_list, 0x0429, COMMAND_STATUS_NORMAL);
break;
case 0x0f:
offset = dissect_bthci_evt_command_status(tvb, offset, pinfo, tree, bthci_evt_tree, opcode_list, bluetooth_data);
break;
case 0x10:
offset = dissect_bthci_evt_hardware_error(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x11:
offset = dissect_bthci_evt_flush_occured(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x12:
offset = dissect_bthci_evt_role_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x080B, COMMAND_STATUS_NORMAL);
break;
case 0x13:
offset = dissect_bthci_evt_number_of_completed_packets(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x14:
offset = dissect_bthci_evt_mode_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0803, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x0804, COMMAND_STATUS_NORMAL);
break;
case 0x15:
offset = dissect_bthci_evt_return_link_keys(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x16:
offset = dissect_bthci_evt_pin_code_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x17:
offset = dissect_bthci_evt_link_key_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x18:
offset = dissect_bthci_evt_link_key_notification(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x19:
offset = dissect_bthci_evt_loopback_command(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x1a:
offset = dissect_bthci_evt_data_buffer_overflow(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1b:
offset = dissect_bthci_evt_max_slots_change(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1c:
offset = dissect_bthci_evt_read_clock_offset_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x1d:
offset = dissect_bthci_evt_conn_packet_type_changed(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x040F, COMMAND_STATUS_NORMAL);
break;
case 0x1e:
offset = dissect_bthci_evt_qos_violation(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x1f:
offset = dissect_bthci_evt_page_scan_mode_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x20:
offset = dissect_bthci_evt_page_scan_repetition_mode_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x21:
offset = dissect_bthci_evt_flow_specification_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x22:
offset = dissect_bthci_evt_inquire_result_with_rssi(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data, NULL);
break;
case 0x23:
offset = dissect_bthci_evt_read_remote_ext_features_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x41C, COMMAND_STATUS_NORMAL);
break;
case 0x2c:
offset = dissect_bthci_evt_sync_connection_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x0429, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x0428, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x043D, COMMAND_STATUS_NORMAL);
add_opcode(opcode_list, 0x043E, COMMAND_STATUS_NORMAL);
break;
case 0x2d:
offset = dissect_bthci_evt_sync_connection_changed(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x043D, COMMAND_STATUS_NORMAL);
break;
case 0x2e:
offset = dissect_bthci_evt_sniff_subrating(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x2f:
{
bluetooth_eir_ad_data_t *eir_data;
previous_offset = offset;
offset = dissect_bthci_evt_inquire_result_with_rssi(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data, bd_addr);
eir_data = wmem_new0(wmem_packet_scope(), bluetooth_eir_ad_data_t);
eir_data->interface_id = bluetooth_data->interface_id;
eir_data->adapter_id = bluetooth_data->adapter_id;
eir_data->bd_addr = bd_addr;
call_dissector_with_data(btcommon_eir_handle, tvb_new_subset_length(tvb, offset, 240), pinfo, bthci_evt_tree, eir_data);
save_remote_device_name(tvb, offset, pinfo, 240, (offset - previous_offset <= 1) ? NULL : bd_addr, bluetooth_data);
offset += 240;
}
break;
case 0x30:
offset = dissect_bthci_evt_encryption_key_refresh_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x2019, COMMAND_STATUS_NORMAL);
break;
case 0x31:
offset = dissect_bthci_evt_io_capability_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x32:
offset = dissect_bthci_evt_io_capability_response(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x33:
offset = dissect_bthci_evt_user_confirmation_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x34:
offset = dissect_bthci_evt_user_passkey_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x35:
offset = dissect_bthci_evt_remote_oob_data_request(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x36:
offset = dissect_bthci_evt_simple_pairing_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x38:
offset = dissect_bthci_evt_link_supervision_timeout_changed(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x39:
offset = dissect_bthci_evt_enhanced_flush_complete(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x3b:
offset = dissect_bthci_evt_user_passkey_notification(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x3c:
offset = dissect_bthci_evt_keypress_notification(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x3d:
offset = dissect_bthci_evt_remote_host_sup_feat_notification(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x3e:
offset = dissect_bthci_evt_le_meta(tvb, offset, pinfo, bthci_evt_tree, opcode_list, bluetooth_data);
break;
case 0x40:
offset = dissect_bthci_evt_physical_link_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x41:
case 0x44:
offset = dissect_bthci_evt_channel_select_physical_link_recovery(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x42:
offset = dissect_bthci_evt_disconnect_physical_link_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x43:
offset = dissect_bthci_evt_physical_link_loss_early_warning(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x45:
offset = dissect_bthci_evt_logical_link_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x46:
offset = dissect_bthci_evt_disconnect_logical_link_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x47:
offset = dissect_bthci_evt_flow_spec_modify_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x48:
offset = dissect_bthci_evt_number_of_completed_data_blocks(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x49:
offset = dissect_bthci_evt_amp_start_stop_test(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x1809, COMMAND_STATUS_NORMAL);
break;
case 0x4a:
offset = dissect_bthci_evt_amp_start_stop_test(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
add_opcode(opcode_list, 0x1808, COMMAND_STATUS_NORMAL);
break;
case 0x4b:
offset = dissect_bthci_evt_amp_receiver_test(tvb, offset, pinfo, bthci_evt_tree);
break;
case 0x4c:
offset = dissect_bthci_evt_short_range_mode_change_complete(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x4d:
offset = dissect_bthci_evt_amp_status_change(tvb, offset, pinfo, bthci_evt_tree, bluetooth_data);
break;
case 0x4e:
case 0x4f:
case 0x50:
case 0x51:
case 0x52:
case 0x53:
case 0x54:
case 0x55:
case 0x56:
case 0xfe:
proto_tree_add_expert(bthci_evt_tree, pinfo, &ei_event_undecoded, tvb, offset, tvb_captured_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
break;
case 0xff:
if (!dissector_try_uint_new(vendor_dissector_table, HCI_VENDOR_DEFAULT, tvb, pinfo, tree, TRUE, bluetooth_data)) {
if (bluetooth_data) {
hci_vendor_data_t *hci_vendor_data;
wmem_tree_key_t key[3];
guint32 interface_id;
guint32 adapter_id;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 0;
key[2].key = NULL;
hci_vendor_data = (hci_vendor_data_t *) wmem_tree_lookup32_array(bluetooth_data->hci_vendors, key);
if (hci_vendor_data) {
gint sub_offset;
sub_offset = dissector_try_uint_new(hci_vendor_table, hci_vendor_data->manufacturer, tvb, pinfo, tree, TRUE, bluetooth_data);
if (sub_offset > 0 && sub_offset < tvb_captured_length_remaining(tvb, offset))
proto_tree_add_expert(bthci_evt_tree, pinfo, &ei_parameter_unexpected, tvb, offset + sub_offset, tvb_captured_length_remaining(tvb, sub_offset + offset));
}
}
}
proto_tree_add_expert(bthci_evt_tree, pinfo, &ei_event_undecoded, tvb, offset, tvb_captured_length_remaining(tvb, offset));
return tvb_captured_length(tvb);
default:
proto_tree_add_expert(bthci_evt_tree, pinfo, &ei_event_unknown_event, tvb, offset, tvb_captured_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
break;
}
}
opcode_list_frame = wmem_list_head(opcode_list);
while (opcode_list_frame) {
wmem_tree_key_t key[4];
guint32 interface_id;
guint32 adapter_id;
guint32 frame_number;
bthci_cmd_data_t *bthci_cmd_data;
wmem_tree_t *subtree;
gint i_frame_number;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
frame_number = pinfo->num;
opcode_list_data = (opcode_list_data_t *) wmem_list_frame_data(opcode_list_frame);
opcode = opcode_list_data->opcode;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &opcode;
key[3].length = 0;
key[3].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(bthci_cmds, key);
i_frame_number = frame_number;
do {
bthci_cmd_data = (subtree) ? (bthci_cmd_data_t *) wmem_tree_lookup32_le(subtree, i_frame_number) : NULL;
if (bthci_cmd_data && bthci_cmd_data->command_in_frame < frame_number && (
(opcode_list_data->command_status == COMMAND_STATUS_NORMAL &&
(bthci_cmd_data->response_in_frame == frame_number ||
bthci_cmd_data->response_in_frame == max_disconnect_in_frame)) ||
(opcode_list_data->command_status == COMMAND_STATUS_PENDING &&
(bthci_cmd_data->pending_in_frame == frame_number ||
((bthci_cmd_data->response_in_frame == max_disconnect_in_frame ||
bthci_cmd_data->response_in_frame > frame_number) &&
bthci_cmd_data->pending_in_frame == max_disconnect_in_frame))) ||
(opcode_list_data->command_status == COMMAND_STATUS_RESULT &&
(bthci_cmd_data->response_in_frame == frame_number ||
((bthci_cmd_data->response_in_frame == max_disconnect_in_frame &&
bthci_cmd_data->pending_in_frame == max_disconnect_in_frame))))
)) {
lastest_bthci_cmd_data = bthci_cmd_data;
if (((opcode_list_data->command_status == COMMAND_STATUS_RESULT ||
opcode_list_data->command_status == COMMAND_STATUS_NORMAL) &&
bthci_cmd_data->response_in_frame == frame_number) ||
(opcode_list_data->command_status == COMMAND_STATUS_PENDING &&
bthci_cmd_data->pending_in_frame == frame_number)) {
opcode_list_frame = NULL;
break;
}
}
if (bthci_cmd_data && bthci_cmd_data->command_in_frame < frame_number) {
i_frame_number = bthci_cmd_data->command_in_frame - 1;
if (i_frame_number < 1)
bthci_cmd_data = NULL;
} else {
bthci_cmd_data = NULL;
}
} while (bthci_cmd_data);
if (opcode_list_frame)
opcode_list_frame = wmem_list_frame_next(opcode_list_frame);
}
if (lastest_bthci_cmd_data) {
proto_item *sub_item;
guint32 frame_number;
nstime_t delta;
frame_number = pinfo->num;
if (opcode != G_MAXUINT32 && opcode >> 10 != HCI_OGF_VENDOR_SPECIFIC) {
guint8 status;
switch(opcode) {
case 0x0c13:
status = tvb_get_guint8(tvb, 5);
if (status == STATUS_SUCCESS && have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
tap_device->interface_id = bluetooth_data->interface_id;
tap_device->adapter_id = bluetooth_data->adapter_id;
tap_device->has_bd_addr = FALSE;
tap_device->is_local = TRUE;
tap_device->type = BLUETOOTH_DEVICE_NAME;
tap_device->data.name = lastest_bthci_cmd_data->data.name;
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
if (status == STATUS_SUCCESS && !pinfo->fd->flags.visited) {
localhost_name_entry_t *localhost_name_entry;
wmem_tree_key_t key[4];
guint32 interface_id;
guint32 adapter_id;
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_name_entry = (localhost_name_entry_t *) wmem_new(wmem_file_scope(), localhost_name_entry_t);
localhost_name_entry->interface_id = interface_id;
localhost_name_entry->adapter_id = adapter_id;
localhost_name_entry->name = lastest_bthci_cmd_data->data.name;
wmem_tree_insert32_array(bluetooth_data->localhost_name, key, localhost_name_entry);
}
break;
}
}
if (!pinfo->fd->flags.visited && opcode_list_data->command_status == COMMAND_STATUS_PENDING &&
lastest_bthci_cmd_data->pending_in_frame == max_disconnect_in_frame) {
lastest_bthci_cmd_data->pending_in_frame = frame_number;
lastest_bthci_cmd_data->pending_abs_ts = pinfo->abs_ts;
}
if (!pinfo->fd->flags.visited && opcode_list_data->command_status == COMMAND_STATUS_NORMAL &&
lastest_bthci_cmd_data->response_in_frame == max_disconnect_in_frame) {
lastest_bthci_cmd_data->response_in_frame = frame_number;
lastest_bthci_cmd_data->response_abs_ts = pinfo->abs_ts;
}
if (!pinfo->fd->flags.visited && opcode_list_data->command_status == COMMAND_STATUS_RESULT &&
lastest_bthci_cmd_data->response_in_frame == max_disconnect_in_frame &&
lastest_bthci_cmd_data->pending_in_frame == max_disconnect_in_frame) {
lastest_bthci_cmd_data->response_in_frame = frame_number;
lastest_bthci_cmd_data->response_abs_ts = pinfo->abs_ts;
}
if (lastest_bthci_cmd_data->pending_in_frame == frame_number) {
sub_item = proto_tree_add_uint(bthci_evt_tree, hf_command_in_frame, tvb, 0, 0, lastest_bthci_cmd_data->command_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
if (lastest_bthci_cmd_data->response_in_frame < max_disconnect_in_frame) {
sub_item = proto_tree_add_uint(bthci_evt_tree, hf_response_in_frame, tvb, 0, 0, lastest_bthci_cmd_data->response_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
nstime_delta(&delta, &lastest_bthci_cmd_data->pending_abs_ts, &lastest_bthci_cmd_data->command_abs_ts);
sub_item = proto_tree_add_double(bthci_evt_tree, hf_command_pending_time_delta, tvb, 0, 0, nstime_to_msec(&delta));
proto_item_append_text(sub_item, " ms");
PROTO_ITEM_SET_GENERATED(sub_item);
if (lastest_bthci_cmd_data->response_in_frame < max_disconnect_in_frame) {
nstime_delta(&delta, &lastest_bthci_cmd_data->response_abs_ts, &lastest_bthci_cmd_data->pending_abs_ts);
sub_item = proto_tree_add_double(bthci_evt_tree, hf_pending_response_time_delta, tvb, 0, 0, nstime_to_msec(&delta));
proto_item_append_text(sub_item, " ms");
PROTO_ITEM_SET_GENERATED(sub_item);
}
}
if (lastest_bthci_cmd_data->response_in_frame == frame_number) {
sub_item = proto_tree_add_uint(bthci_evt_tree, hf_command_in_frame, tvb, 0, 0, lastest_bthci_cmd_data->command_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
if (lastest_bthci_cmd_data->pending_in_frame < max_disconnect_in_frame) {
sub_item = proto_tree_add_uint(bthci_evt_tree, hf_pending_in_frame, tvb, 0, 0, lastest_bthci_cmd_data->pending_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
nstime_delta(&delta, &lastest_bthci_cmd_data->response_abs_ts, &lastest_bthci_cmd_data->pending_abs_ts);
sub_item = proto_tree_add_double(bthci_evt_tree, hf_pending_response_time_delta, tvb, 0, 0, nstime_to_msec(&delta));
proto_item_append_text(sub_item, " ms");
PROTO_ITEM_SET_GENERATED(sub_item);
}
nstime_delta(&delta, &lastest_bthci_cmd_data->response_abs_ts, &lastest_bthci_cmd_data->command_abs_ts);
sub_item = proto_tree_add_double(bthci_evt_tree, hf_command_response_time_delta, tvb, 0, 0, nstime_to_msec(&delta));
proto_item_append_text(sub_item, " ms");
PROTO_ITEM_SET_GENERATED(sub_item);
}
}
return offset;
}
void
proto_register_bthci_evt(void)
{
module_t *module;
expert_module_t *expert_bthci_evt;
static hf_register_info hf[] = {
{ &hf_bthci_evt_code,
{ "Event Code", "bthci_evt.code",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bthci_evt_evt_code_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_param_length,
{ "Parameter Total Length", "bthci_evt.param_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_command_packets,
{ "Number of Allowed Command Packets", "bthci_evt.num_command_packets",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_handles,
{ "Number of Connection Handles", "bthci_evt.num_handles",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Connection Handles and Num_HCI_Data_Packets parameter pairs", HFILL }
},
{ &hf_bthci_evt_connection_handle,
{ "Connection Handle", "bthci_evt.connection_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_compl_packets,
{ "Number of Completed Packets", "bthci_evt.num_compl_packets",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The number of HCI Data Packets that have been completed", HFILL }
},
{ &hf_bthci_evt_opcode,
{ "Command Opcode", "bthci_evt.opcode",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_opcode_vals_ext, 0x0,
"HCI Command Opcode", HFILL }
},
{ &hf_bthci_evt_ogf,
{ "Opcode Group Field", "bthci_evt.opcode.ogf",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_ogf_vals_ext, 0xfc00,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_link_control,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_link_control_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_link_policy,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_link_policy_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_host_controller_and_baseband,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_host_controller_and_baseband_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_informational,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_informational_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_status,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_status_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_testing,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_testing_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_low_energy,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_ocf_low_energy_vals_ext, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf_logo_testing,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX, NULL, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ocf,
{ "Opcode Command Field", "bthci_evt.opcode.ocf",
FT_UINT16, BASE_HEX, NULL, 0x03ff,
NULL, HFILL }
},
{ &hf_bthci_evt_ret_params,
{ "Return Parameter", "bthci_evt.ret_params",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_status,
{ "Status", "bthci_evt.status",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_status_pending,
{ "Status", "bthci_evt.status",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_status_pending_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_bd_addr,
{ "BD_ADDR", "bthci_evt.bd_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Bluetooth Device Address", HFILL}
},
{ &hf_bthci_evt_link_type,
{ "Link Type", "bthci_evt.link_type",
FT_UINT8, BASE_HEX, VALS(evt_link_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_encryption_mode,
{ "Encryption Mode", "bthci_evt.encryption_mode",
FT_UINT8, BASE_HEX, VALS(evt_encryption_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_reason,
{ "Reason", "bthci_evt.reason",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_remote_name,
{ "Remote Name", "bthci_evt.remote_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Userfriendly descriptive name for the remote device", HFILL }
},
{ &hf_bthci_evt_encryption_enable,
{ "Encryption Enable", "bthci_evt.encryption_enable",
FT_UINT8, BASE_HEX, VALS(evt_encryption_enable), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_key_flag,
{ "Key Flag", "bthci_evt.key_flag",
FT_UINT8, BASE_HEX, VALS(evt_key_flag), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_vers_nr,
{ "LMP Version", "bthci_evt.lmp_vers_nr",
FT_UINT8, BASE_HEX, VALS(bthci_evt_lmp_version), 0x0,
"Version of the Current LMP", HFILL }
},
{ &hf_bthci_bthci_evt_hci_version,
{ "HCI Version", "bthci_evt.hci_vers_nr",
FT_UINT8, BASE_HEX, VALS(bthci_evt_hci_version), 0x0,
"Version of the Current HCI", HFILL }
},
{ &hf_bthci_evt_hci_revision,
{ "HCI Revision", "bthci_evt.hci_vers_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Revision of the Current HCI", HFILL }
},
{ &hf_bthci_evt_comp_id,
{ "Manufacturer Name", "bthci_evt.comp_id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bluetooth_company_id_vals_ext, 0x0,
"Manufacturer Name of Bluetooth Hardware", HFILL }
},
{ &hf_bthci_evt_sub_vers_nr,
{ "LMP Subversion", "bthci_evt.lmp_sub_vers_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Subversion of the Current LMP", HFILL }
},
{ &hf_bthci_evt_flags,
{ "Flags", "bthci_evt.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_service_type,
{ "Service Type", "bthci_evt.service_type",
FT_UINT8, BASE_HEX, VALS(evt_service_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_token_rate,
{ "Available Token Rate", "bthci_evt.token_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Token Rate, in bytes per second", HFILL }
},
{ &hf_bthci_evt_peak_bandwidth,
{ "Available Peak Bandwidth", "bthci_evt.peak_bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Peak Bandwidth, in bytes per second", HFILL }
},
{ &hf_bthci_evt_latency,
{ "Available Latency", "bthci_evt.latency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Latency, in microseconds", HFILL }
},
{ &hf_bthci_evt_delay_variation,
{ "Available Delay Variation", "bthci_evt.delay_variation",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Available Delay Variation, in microseconds", HFILL }
},
{ &hf_bthci_evt_hardware_code,
{ "Hardware Code", "bthci_evt.hardware_code",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Hardware Code (implementation specific)", HFILL }
},
{ &hf_bthci_evt_role,
{ "Role", "bthci_evt.role",
FT_UINT8, BASE_HEX, VALS(evt_role_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_curr_mode,
{ "Current Mode", "bthci_evt.current_mode",
FT_UINT8, BASE_HEX, VALS(evt_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_interval,
{ "Interval", "bthci_evt.interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Interval - Number of Baseband slots", HFILL }
},
{ &hf_bthci_evt_link_key,
{ "Link Key", "bthci_evt.link_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Link Key for the associated BD_ADDR", HFILL }
},
{ &hf_bthci_evt_key_type,
{ "Key Type", "bthci_evt.key_type",
FT_UINT8, BASE_HEX, VALS(evt_key_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_slots,
{ "Maximum Number of Slots", "bthci_evt.max_slots",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Maximum Number of slots allowed for baseband packets", HFILL }
},
{ &hf_bthci_evt_clock_offset,
{ "Clock Offset", "bthci_evt.clock_offset",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
"Bit 2-16 of the Clock Offset between CLKmaster-CLKslave", HFILL }
},
{ &hf_bthci_evt_page_scan_mode,
{ "Page Scan Mode", "bthci_evt.page_scan_mode",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_page_scan_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_page_scan_repetition_mode,
{ "Page Scan Repetition Mode", "bthci_evt.page_scan_repetition_mode",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_page_scan_repetition_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_reserved,
{ "Reserved", "bthci_evt.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_page_scan_period_mode,
{ "Page Scan Period Mode", "bthci_evt.page_scan_period_mode",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_page_scan_period_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh1,
{ "ACL Link Type 2-DH1", "bthci_evt.link_type_2dh1",
FT_BOOLEAN, 16, NULL, 0x0002,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh1,
{ "ACL Link Type 3-DH1", "bthci_evt.link_type_3dh1",
FT_BOOLEAN, 16, NULL, 0x0004,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm1,
{ "ACL Link Type DM1", "bthci_evt.link_type_dm1",
FT_BOOLEAN, 16, NULL, 0x0008,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh1,
{ "ACL Link Type DH1", "bthci_evt.link_type_dh1",
FT_BOOLEAN, 16, NULL, 0x0010,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh3,
{ "ACL Link Type 2-DH3", "bthci_evt.link_type_2dh3",
FT_BOOLEAN, 16, NULL, 0x0100,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh3,
{ "ACL Link Type 3-DH3", "bthci_evt.link_type_3dh3",
FT_BOOLEAN, 16, NULL, 0x0200,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm3,
{ "ACL Link Type DM3", "bthci_evt.link_type_dm3",
FT_BOOLEAN, 16, NULL, 0x0400,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh3,
{ "ACL Link Type DH3", "bthci_evt.link_type_dh3",
FT_BOOLEAN, 16, NULL, 0x0800,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_2dh5,
{ "ACL Link Type 2-DH5", "bthci_evt.link_type_2dh5",
FT_BOOLEAN, 16, NULL, 0x1000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_3dh5,
{ "ACL Link Type 3-DH5", "bthci_evt.link_type_3dh5",
FT_BOOLEAN, 16, NULL, 0x2000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dm5,
{ "ACL Link Type DM5", "bthci_evt.link_type_dm5",
FT_BOOLEAN, 16, NULL, 0x4000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_dh5,
{ "ACL Link Type DH5", "bthci_evt.link_type_dh5",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv1,
{ "SCO Link Type HV1", "bthci_evt.link_type_hv1",
FT_BOOLEAN, 16, NULL, 0x0020,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv2,
{ "SCO Link Type HV2", "bthci_evt.link_type_hv2",
FT_BOOLEAN, 16, NULL, 0x0040,
NULL, HFILL }
},
{ &hf_bthci_evt_link_type_hv3,
{ "SCO Link Type HV3", "bthci_evt.link_type_hv3",
FT_BOOLEAN, 16, NULL, 0x0080,
NULL, HFILL }
},
{ &hf_lmp_features,
{ "LMP Features", "bthci_evt.lmp_features",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_lmp_feature_3slot_packets,
{ "3-slot packets", "bthci_evt.lmp_features.3slot_packets",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_5slot_packets,
{ "5-slot packets", "bthci_evt.lmp_features.5slot_packets",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_encryption,
{ "Encryption", "bthci_evt.lmp_features.encryption",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_slot_offset,
{ "Slot Offset", "bthci_evt.lmp_features.slot_offset",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_timing_accuracy,
{ "Timing Accuracy", "bthci_evt.lmp_features.timing_accuracy",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_role_switch,
{ "Role Switch", "bthci_evt.lmp_features.role_switch",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_hold_mode,
{ "Hold Mode", "bthci_evt.lmp_features.hold_mode",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_sniff_mode,
{ "Sniff Mode", "bthci_evt.lmp_features.sniff_mode",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_park_state,
{ "Park Mode", "bthci_evt.lmp_features.park_state",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_power_control_requests,
{ "Power Control Requests", "bthci_evt.lmp_features.power_control_requests",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_channel_quality_driven_data_rate,
{ "Channel Quality Driven Data Rate", "bthci_evt.lmp_features.channel_quality_driven_data_rate",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_sco_link,
{ "SCO Link", "bthci_evt.lmp_features.sco_link",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_hv2_packets,
{ "HV2 packets", "bthci_evt.lmp_features.hv2_packets",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_hv3_packets,
{ "HV3 packets", "bthci_evt.lmp_features.hv3_packets",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_u_law_log_synchronous_data,
{ "u-law Log Synchronous Data", "bthci_evt.lmp_features.u_law_log_synchronous_data",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_a_law_log_synchronous_data,
{ "A-law Log Synchronous Data", "bthci_evt.lmp_features.a_law_log_synchronous_data",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_cvsd_synchronous_data,
{ "CVSD Synchronous Data", "bthci_evt.lmp_features.cvsd_synchronous_data",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_paging_parameter_negotiation,
{ "Paging Parameter Negotiation", "bthci_evt.lmp_features.paging_parameter_negotiation",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_power_control,
{ "Power Control", "bthci_evt.lmp_features.power_control",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_transparent_synchronous_data,
{ "Transparent Synchronous Data", "bthci_evt.lmp_features.transparent_synchronous_data",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_flow_control_lag,
{ "Flow Control Lag", "bthci_evt.lmp_features.flow_control_lag",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_lmp_feature_broadcast_encryption,
{ "Broadband Encryption", "bthci_evt.lmp_features.broadcast_encryption",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_reserved_24,
{ "Reserved", "bthci_evt.lmp_features.reserved.24",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_edr_acl_2mbps_mode,
{ "EDR ACL 2 Mbps Mode", "bthci_evt.lmp_features.edr_acl_2mbps_mode",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_edr_acl_3mbps_mode,
{ "EDR ACL 3 Mbps Mode", "bthci_evt.lmp_features.edr_acl_3mbps_mode",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_enhanced_inquiry_scan,
{ "Enhanced Inquiry Scan", "bthci_evt.lmp_features.enhanced_inquiry_scan",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_interlaced_inquiry_scan,
{ "Interlaced Inquiry Scan", "bthci_evt.lmp_features.interlaced_inquiry_scan",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_interlaced_page_scan,
{ "Interlaced Page Scan", "bthci_evt.lmp_features.interlaced_page_scan",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_rssi_with_inquiry_results,
{ "RSSI with Inquiry Results", "bthci_evt.lmp_features.rssi_with_inquiry_results",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_ev3_packets,
{ "EV3 Packets", "bthci_evt.lmp_features.ev3_packets",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_ev4_packets,
{ "EV4 Packets", "bthci_evt.lmp_features.ev4_packets",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_ev5_packets,
{ "EV5 Packets", "bthci_evt.lmp_features.ev5_packets",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_reserved_34,
{ "Reserved", "bthci_evt.lmp_features.reserved.34",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_afh_capable_slave,
{ "AFH Capable Slave", "bthci_evt.lmp_features.afh_capable_slave",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_afh_classification_slave,
{ "AFH Classification Slave", "bthci_evt.lmp_features.afh_classification_slave",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_br_edr_not_supported,
{ "BR/EDR Not Supported", "bthci_evt.lmp_features.br_edr_not_supported",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_le_supported_controller,
{ "LE Supported Controller", "bthci_evt.lmp_features.le_supported_controller",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_3slot_edr_acl_packets,
{ "3-slot EDR ACL packets", "bthci_evt.lmp_features.3slot_edr_acl_packets",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_5slot_edr_acl_packets,
{ "5-slot EDR ACL packets", "bthci_evt.lmp_features.5slot_edr_acl_packets",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_sniff_subrating,
{ "Sniff Subrating", "bthci_evt.lmp_features.sniff_subrating",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_pause_encryption,
{ "Pause Encryption", "bthci_evt.lmp_features.pause_encryption",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_afh_capable_master,
{ "AFH Capable Master", "bthci_evt.lmp_features.afh_capable_master",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_afh_classification_master,
{ "AFH Classification Master", "bthci_evt.lmp_features.afh_classification_master",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_edr_esco_2mbps_mode,
{ "EDR eSCO 2 Mbps Mode", "bthci_evt.lmp_features.edr_esco_2mbps_mode",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_edr_esco_3mbps_mode,
{ "EDR eSCO 3 Mbps Mode", "bthci_evt.lmp_features.edr_esco_3mbps_mode",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_3slot_edr_esco_packets,
{ "3-slot EDR eSCO Packets", "bthci_evt.lmp_features.3slot_edr_esco_packets",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_extended_inquiry_response,
{ "Extended Inquiry Response", "bthci_evt.lmp_features.extended_inquiry_response",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_simultaneous_le_and_br_edr_controller,
{"Simultaneous LE and BR/EDR to Same Device Capable Controller", "bthci_evt.lmp_features.simultaneous_le_and_br_edr.controller",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_lmp_feature_reserved_50,
{ "Reserved", "bthci_evt.lmp_features.reserved.50",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_secure_simple_pairing,
{ "Secure Simple Pairing", "bthci_evt.lmp_features.secure_simple_pairing",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_lmp_feature_encapsulated_pdu,
{ "Encapsulated PDU", "bthci_evt.lmp_features.encapsulated_pdu",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_lmp_feature_erroneous_data_reporting,
{ "Erroneous Data Reporting", "bthci_evt.lmp_features.erroneous_data_reporting",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_lmp_feature_non_flushable_packet_boundary_flag,
{ "Non-flushable Packet Boundary Flag", "bthci_evt.lmp_features.non_flushable_packet_boundary_flag",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_lmp_feature_reserved_55,
{ "Reserved", "bthci_evt.lmp_features.reserved.55",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_link_supervision_timeout_changed_event,
{ "Link Supervision Timeout Changed Event", "bthci_evt.lmp_features.supervision_timeout_changed_event",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_lmp_feature_inquiry_tx_power_level,
{ "Inquiry TX Power Level", "bthci_evt.lmp_features.inquiry_tx_power_level",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_lmp_feature_enhanced_power_control,
{ "Enhanced Power Control", "bthci_evt.lmp_features.enhanced_power_control",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_lmp_feature_reserved_59_62,
{ "Reserved", "bthci_evt.lmp_features.reserved.59_62",
FT_BOOLEAN, 8, NULL, 0x78,
NULL, HFILL }
},
{ &hf_lmp_feature_extended_features,
{ "Extended Features", "bthci_evt.lmp_features.extended_features",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_lmp_feature_secure_simple_pairing_host,
{"Secure Simple Pairing Host", "bthci_evt.lmp_features.secure_simple_pairing_host",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_lmp_feature_le_supported_host,
{"LE Supported Host", "bthci_evt.lmp_features.le_supported.host",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_lmp_feature_simultaneous_le_and_br_edr_host,
{"Simultaneous LE and BR/EDR to Same Device Capable Host", "bthci_evt.lmp_features.simultaneous_le_and_br_edr.host",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL}
},
{ &hf_lmp_feature_reserved_67_71,
{"Reserved", "bthci_evt.lmp_features.reserved.67_71",
FT_UINT8, BASE_HEX, NULL, 0xF8,
NULL, HFILL}
},
{ &hf_lmp_feature_reserved,
{"Reserved", "bthci_evt.lmp_features.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_num_keys,
{ "Number of Link Keys", "bthci_evt.num_keys",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Link Keys contained", HFILL }
},
{ &hf_bthci_evt_num_keys_read,
{ "Number of Link Keys Read", "bthci_evt.num_keys_read",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_keys_deleted,
{ "Number of Link Keys Deleted", "bthci_evt.num_keys_deleted",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_keys_written,
{ "Number of Link Keys Written", "bthci_evt.num_keys_written",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_num_keys,
{ "Max Num Keys", "bthci_evt.max_num_keys",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of Link Keys that the Host Controller can store", HFILL }
},
{ &hf_bthci_evt_num_responses,
{ "Number of responses", "bthci_evt.num_responses",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Responses from Inquiry", HFILL }
},
{ &hf_bthci_evt_link_policy_setting_switch,
{ "Enable Master Slave Switch", "bthci_evt.link_policy_switch",
FT_BOOLEAN, 16, NULL, 0x0001,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_hold,
{ "Enable Hold Mode", "bthci_evt.link_policy_hold",
FT_BOOLEAN, 16, NULL, 0x0002,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_sniff,
{ "Enable Sniff Mode", "bthci_evt.link_policy_sniff",
FT_BOOLEAN, 16, NULL, 0x0004,
NULL, HFILL }
},
{ &hf_bthci_evt_link_policy_setting_park,
{ "Enable Park Mode", "bthci_evt.link_policy_park",
FT_BOOLEAN, 16, NULL, 0x0008,
NULL, HFILL }
},
{ &hf_bthci_evt_curr_role,
{ "Current Role", "bthci_evt.curr_role",
FT_UINT8, BASE_HEX, VALS(evt_role_vals_handle), 0x0,
"Current role for this connection handle", HFILL }
},
{ &hf_bthci_evt_pin_type,
{ "PIN Type", "bthci_evt.pin_type",
FT_UINT8, BASE_HEX, VALS(evt_pin_types), 0x0,
"PIN Types", HFILL }
},
{ &hf_bthci_evt_device_name,
{ "Device Name", "bthci_evt.device_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Userfriendly descriptive name for the device", HFILL }
},
{ &hf_bthci_evt_timeout,
{ "Timeout", "bthci_evt.timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Baseband slots for timeout.", HFILL }
},
{ &hf_bthci_evt_scan_enable,
{ "Scan", "bthci_evt.scan_enable",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_scan_enable_values), 0x0,
"Scan Enable", HFILL }
},
{ &hf_bthci_evt_authentication_enable,
{ "Authentication", "bthci_evt.auth_enable",
FT_UINT8, BASE_HEX, VALS(evt_auth_enable_values), 0x0,
"Authentication Enable", HFILL }
},
{ &hf_bthci_evt_sco_flow_cont_enable,
{ "SCO Flow Control", "bthci_evt.sco_flow_cont_enable",
FT_UINT8, BASE_HEX, VALS(evt_enable_values), 0x0,
"SCO Flow Control Enable", HFILL }
},
{ &hf_bthci_evt_window,
{ "Window", "bthci_evt.window",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_input_unused,
{ "Unused bits", "bthci_evt.voice.unused",
FT_UINT16, BASE_HEX, NULL, 0xfc00,
NULL, HFILL }
},
{ &hf_bthci_evt_input_coding,
{ "Input Coding", "bthci_evt.voice.input_coding",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &bthci_cmd_input_coding_vals_ext, 0x0300,
NULL, HFILL }
},
{ &hf_bthci_evt_input_data_format,
{ "Input Data Format", "bthci_evt.voice.input_data_format",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &bthci_cmd_input_data_format_vals_ext, 0x00c0,
NULL, HFILL }
},
{ &hf_bthci_evt_input_sample_size,
{ "Input Sample Size", "bthci_evt.voice.input_sample_size",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &bthci_cmd_input_sample_size_vals_ext, 0x0020,
NULL, HFILL }
},
{ &hf_bthci_evt_linear_pcm_bit_pos,
{ "Linear PCM Bit Position", "bthci_evt.voice.linear_pcm_bit_pos",
FT_UINT16, BASE_DEC, NULL, 0x001c,
"# bit pos. that MSB of sample is away from starting at MSB", HFILL }
},
{ &hf_bthci_evt_air_coding_format,
{ "Air Coding Format", "bthci_evt.voice.air_coding_format",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &bthci_cmd_air_coding_format_vals_ext, 0x0003,
NULL, HFILL }
},
{ &hf_bthci_evt_num_broadcast_retransm,
{ "Num Broadcast Retran", "bthci_evt.num_broad_retran",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Broadcast Retransmissions", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_page,
{ "Suspend Page Scan", "bthci_evt.hold_mode_page",
FT_BOOLEAN, 8, NULL, 0x1,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_inquiry,
{ "Suspend Inquiry Scan", "bthci_evt.hold_mode_inquiry",
FT_BOOLEAN, 8, NULL, 0x2,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_hold_mode_act_periodic,
{ "Suspend Periodic Inquiries", "bthci_evt.hold_mode_periodic",
FT_BOOLEAN, 8, NULL, 0x4,
"Device can enter low power state", HFILL }
},
{ &hf_bthci_evt_transmit_power_level,
{ "Transmit Power Level (dBm)", "bthci_evt.transmit_power_level",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_supp_iac,
{"Num Support IAC", "bthci_evt.num_supp_iac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Num of supported IAC the device can simultaneously listen", HFILL }
},
{ &hf_bthci_evt_num_curr_iac,
{"Num Current IAC", "bthci_evt.num_curr_iac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Num of IACs currently in use to simultaneously listen", HFILL }
},
{ &hf_bthci_evt_iac_lap,
{ "IAC LAP", "bthci_evt.num_curr_iac",
FT_UINT24, BASE_HEX, NULL, 0x0,
"LAP(s)used to create IAC", HFILL }
},
{ &hf_bthci_evt_loopback_mode,
{"Loopback Mode", "bthci_evt.loopback_mode",
FT_UINT8, BASE_HEX, VALS(evt_loopback_modes), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_country_code,
{"Country Code", "bthci_evt.country_code",
FT_UINT8, BASE_HEX, VALS(evt_country_code_values), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_failed_contact_counter,
{"Failed Contact Counter", "bthci_evt.failed_contact_counter",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_quality,
{"Link Quality", "bthci_evt.link_quality",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Link Quality (0x00 - 0xFF Higher Value = Better Link)", HFILL }
},
{ &hf_bthci_evt_rssi,
{ "RSSI (dB)", "bthci_evt.rssi",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_host_data_packet_length_acl,
{"Host ACL Data Packet Length (bytes)", "bthci_evt.max_data_length_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Max Host ACL Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_evt_host_data_packet_length_sco,
{"Host SCO Data Packet Length (bytes)", "bthci_evt.max_data_length_sco",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max Host SCO Data Packet length of data portion host is able to accept", HFILL }
},
{ &hf_bthci_evt_host_total_num_acl_data_packets,
{"Host Total Num ACL Data Packets", "bthci_evt.max_data_num_acl",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI ACL Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_evt_host_total_num_sco_data_packets,
{"Host Total Num SCO Data Packets", "bthci_evt.max_data_num_sco",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total Number of HCI SCO Data Packets that can be stored in the data buffers of the Host", HFILL }
},
{ &hf_bthci_evt_page_number,
{"Page Number", "bthci_evt.page_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_page_number,
{"Max. Page Number", "bthci_evt.max_page_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_local_supported_cmds,
{ "Local Supported Commands", "bthci_evt.local_supported_cmds",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_fec_required,
{"FEC Required", "bthci_evt.fec_required",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_err_data_reporting,
{"Erroneous Data Reporting", "bthci_evt.err_data_reporting",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_scan_type,
{"Scan Type", "bthci_evt.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(evt_scan_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_inq_mode,
{"Inquiry Mode", "bthci_evt.inq_scan_type",
FT_UINT8, BASE_DEC, VALS(evt_inq_modes), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_power_level_type,
{"Type", "bthci_evt.power_level_type",
FT_UINT8, BASE_HEX, VALS(evt_power_level_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_link_type,
{"Link Type", "bthci_evt.sync_link_type",
FT_UINT8, BASE_HEX, VALS(evt_sync_link_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_tx_interval,
{"Transmit Interval", "bthci_evt.sync_tx_interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_rtx_window,
{"Retransmit Window", "bthci_evt.sync_rtx_window",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_rx_packet_length,
{"Rx Packet Length", "bthci_evt.sync_rx_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_sync_tx_packet_length,
{"Tx Packet Length", "bthci_evt.sync_tx_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_air_mode,
{"Air Mode", "bthci_evt.air_mode",
FT_UINT8, BASE_DEC, VALS(evt_air_mode_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_tx_latency,
{"Max. Tx Latency", "bthci_evt.max_tx_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_rx_latency,
{"Max. Rx Latency", "bthci_evt.max_rx_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_min_remote_timeout,
{"Min. Remote Timeout", "bthci_evt.min_remote_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_min_local_timeout,
{"Min. Local Timeout", "bthci_evt.min_local_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_link_supervision_timeout,
{"Link Supervision Timeout", "bthci_evt.link_supervision_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_token_bucket_size,
{ "Token Bucket Size", "bthci_evt.token_bucket_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Token Bucket Size (bytes)", HFILL }
},
{ &hf_bthci_evt_flow_direction,
{"Flow Direction", "bthci_evt.flow_direction",
FT_UINT8, BASE_DEC, VALS(evt_flow_direction_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_afh_ch_assessment_mode,
{"AFH Channel Assessment Mode", "bthci_evt.afh_ch_assessment_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_lmp_handle,
{ "LMP Handle", "bthci_evt.lmp_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_clock,
{ "Clock", "bthci_evt.clock",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_clock_accuracy,
{ "Clock", "bthci_evt.clock_accuracy",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_afh_mode,
{"AFH Mode", "bthci_evt.afh_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_afh_channel_map,
{"AFH Channel Map", "bthci_evt.afh_channel_map",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_simple_pairing_mode,
{"Simple Pairing Mode", "bthci_evt.simple_pairing_mode",
FT_UINT8, BASE_DEC, VALS(evt_enable_values), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_hash_c,
{"Hash C", "bthci_evt.hash_c",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_randomizer_r,
{"Randomizer R", "bthci_evt.randomizer_r",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_io_capability,
{"IO Capability", "bthci_evt.io_capability",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_io_capability_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_oob_data_present,
{"OOB Data Present", "bthci_evt.oob_data_present",
FT_UINT8, BASE_DEC, VALS(bthci_cmd_oob_data_present_vals), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_auth_requirements,
{"Authentication Requirements", "bthci_evt.auth_requirements",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &bthci_cmd_auth_req_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_numeric_value,
{"Numeric Value", "bthci_evt.numeric_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_passkey,
{"Passkey", "bthci_evt.passkey",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_notification_type,
{"Notification Type", "bthci_evt.notification_type",
FT_UINT8, BASE_DEC, VALS(bthci_cmd_notification_types), 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_data_length,
{ "Data Length", "bthci_evt.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_location_domain_aware,
{ "Location Domain Aware", "bthci_evt.location_domain_aware",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_location_domain,
{ "Location Domain", "bthci_evt.location_domain",
FT_STRING, BASE_NONE, NULL, 0x0,
"ISO 3166-1 Country Code", HFILL }
},
{ &hf_bthci_evt_location_domain_options,
{ "Location Domain Options", "bthci_evt.location_domain_options",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_location_options,
{ "Location Options", "bthci_evt.location_options",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_flow_control_mode,
{ "Flow Control Mode", "bthci_evt.flow_control_mode",
FT_UINT8, BASE_HEX, VALS(evt_flow_ctrl_mode), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_physical_link_handle,
{ "Physical Link Handle", "bthci_evt.physical_link_handle",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_flow_spec_identifier,
{ "Flow Spec Identifier", "bthci_evt.flow_spec_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_logical_link_handle,
{ "Logical Link Handle", "bthci_evt.logical_link_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_max_acl_data_packet_length,
{ "Max. ACL Data Packet Length", "bthci_evt.max_acl_data_packet_length",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_data_block_length,
{ "Max. Data Block Length", "bthci_evt.data_block_length",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_total_num_data_blocks,
{ "Total Number of Data Blocks", "bthci_evt.total_num_data_blocks",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_bthci_evt_enc_key_size,
{ "Encryption Key Size", "bthci_evt.enc_key_size",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_amp_remaining_assoc_length,
{ "AMP Remaining Assoc Length", "bthci_evt.amp_remaining_assoc_length",
FT_UINT16, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_amp_assoc_fragment,
{ "AMP Assoc Fragment", "bthci_evt.amp_assoc_fragment",
FT_BYTES, BASE_NONE, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_amp_status,
{ "AMP Status", "bthci_evt.amp_status",
FT_UINT8, BASE_HEX, VALS(evt_amp_status), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_total_bandwidth,
{ "Total Bandwidth (kbps)", "bthci_evt.total_bandwidth",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_guaranteed_bandwidth,
{ "Max Guaranteed Bandwidth (kbps)", "bthci_evt.max_guaranteed_bandwidth",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_min_latency,
{ "Min Latency (us)", "bthci_evt.min_latency",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_pdu_size,
{ "Max PDU Size", "bthci_evt.max_pdu_size",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_amp_controller_type,
{ "Controller Type", "bthci_evt.controller_type",
FT_UINT8, BASE_HEX, VALS(evt_controller_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_pal_capabilities_00,
{ "Guaranteed Service", "bthci_evt.pal_capabilities",
FT_BOOLEAN, 16, NULL, 0x0001,
NULL, HFILL }
},
{ &hf_bthci_evt_max_amp_assoc_length,
{ "Max AMP Assoc Length", "bthci_evt.max_amp_assoc_length",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_max_flush_to_us,
{ "Max Flush Timeout (us)", "bthci_evt.max_flush_to",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_best_effort_flush_to_us,
{ "Best Effort Flush Timeout (us)", "bthci_evt.best_effort_flush_to",
FT_UINT32, BASE_DEC, 0x0, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_link_loss_reason,
{ "Reason", "bthci_evt.link_loss_reason",
FT_UINT8, BASE_HEX, VALS(evt_link_loss_reasons), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_compl_blocks,
{ "Number Of Completed Blocks", "bthci_evt.num_compl_blocks",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_test_scenario,
{ "Test Scenario", "bthci_evt.test_scenario",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_report_reason,
{ "Reason", "bthci_evt.report_reason",
FT_UINT8, BASE_HEX, VALS(evt_report_reasons), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_report_event_type,
{ "Report Event Type", "bthci_evt.report_event_type",
FT_UINT8, BASE_HEX, VALS(evt_report_event_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_frames,
{ "Number Of Frames", "bthci_evt.num_frames",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_error_frames,
{ "Number Of Error Frames", "bthci_evt.num_error_frames",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_bits,
{ "Number Of Bits", "bthci_evt.num_bits",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_error_bits,
{ "Number Of Error Bits", "bthci_evt.num_error_bits",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_short_range_mode_state,
{ "Short Range Mode State", "bthci_evt.short_range_mode_state",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_transmit_power_level_gfsk,
{ "Transmit Power Level GFSK (dBm)", "bthci_evt.transmit_power_level_gfsk",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_transmit_power_level_dqpsk,
{ "Transmit Power Level DQPSK (dBm)", "bthci_evt.transmit_power_level_dqpsk",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_transmit_power_level_8dpsk,
{ "Transmit Power Level 8DPSK (dBm)", "bthci_evt.transmit_power_level_8dpsk",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_flush_to_us,
{ "Flush Timeout (us)", "bthci_evt.flushto",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_supported_host,
{ "LE Supported Host", "bthci_evt.le_supported_host",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_simultaneous_host,
{ "Simultaneous LE Host", "bthci_evt.le_simlutaneous_host",
FT_BOOLEAN, 8, NULL, 0x0,
"Support for both LE and BR/EDR to same device", HFILL }
},
{ &hf_bthci_evt_le_acl_data_pkt_len,
{ "LE ACL Data Packet Length", "bthci_evt.le_acl_data_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_total_num_le_acl_data_pkts,
{ "Total Number LE ACL Data Packets", "bthci_evt.le_total_num_acl_data_pkts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_features,
{ "Supported LE Features", "bthci_evt.le_features",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthci_evt_le_feature_00,
{ "LE Encryption", "bthci_evt.le_features.encryption",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_white_list_size,
{ "White List Size", "bthci_evt.le_white_list_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max. total whitelist entries storable in controller", HFILL }
},
{ &hf_bthci_evt_le_channel_map,
{ "Channel Map", "bthci_evt.le_channel_map",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_encrypted_data,
{ "Plaintext", "bthci_evt.le_encrypted_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_random_number,
{ "Random Number", "bthci_evt.le_random_number",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_num_packets,
{ "Number of Packets", "bthci_evt.le_num_packets",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_meta_subevent,
{ "Sub Event", "bthci_evt.le_meta_subevent",
FT_UINT8, BASE_HEX, VALS(evt_le_meta_subevent), 0x00,
NULL, HFILL }
},
{ &hf_bthci_evt_le_peer_address_type,
{ "Peer Address Type", "bthci_evt.le_peer_address_type",
FT_UINT8, BASE_HEX, VALS(bthci_cmd_address_types_vals), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_con_interval,
{ "Connection Interval", "bthci_evt.le_con_interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_con_latency,
{ "Connection Latency", "bthci_evt.le_con_latency",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_supervision_timeout,
{ "Supervision Timeout", "bthci_evt.le_supv_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_encrypted_diversifier,
{ "Encrypted Diversifier", "bthci_evt.le_encrypted_diversifier",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_master_clock_accuracy,
{ "Master Clock Accuracy", "bthci_evt.le_master_clock_accuracy",
FT_UINT8, BASE_HEX, VALS(evt_master_clock_accuray), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_num_reports,
{ "Num Reports", "bthci_evt.le_num_reports",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_advts_event_type,
{ "Event Type", "bthci_evt.le_advts_event_type",
FT_UINT8, BASE_HEX, VALS(evt_le_advertising_evt_types), 0x0,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states,
{ "Supported LE States", "bthci_evt.le_states",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_00,
{ "Non-connectable Advertising State", "bthci_evt.le_states_00",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_01,
{ "Scannable Advertising State", "bthci_evt.le_states_01",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_02,
{ "Connectable Advertising State", "bthci_evt.le_states_02",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_03,
{ "Directed Advertising State", "bthci_evt.le_states_03",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_04,
{ "Passive Scanning State", "bthci_evt.le_states_04",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_05,
{ "Active Scanning State", "bthci_evt.le_states_05",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_06,
{ "Initiating State. Connection State in Master Role", "bthci_evt.le_states_06",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_07,
{ "Connection State in Slave Role", "bthci_evt.le_states_07",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_10,
{ "Non-connectable Advertising State and Passive Scanning State combination", "bthci_evt.le_states_10",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_11,
{ "Scannable Advertising State and Passive Scanning State combination", "bthci_evt.le_states_11",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_12,
{ "Connectable Advertising State and Passive Scanning State combination", "bthci_evt.le_states_12",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_13,
{ "Directed Advertising State and Passive Scanning State combination", "bthci_evt.le_states_13",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_14,
{ "Non-connectable Advertising State and Active Scanning State combination", "bthci_evt.le_states_14",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_15,
{ "Scannable Advertising State and Active Scanning State combination", "bthci_evt.le_states_15",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_16,
{ "Connectable Advertising State and Active Scanning State combination", "bthci_evt.le_states_16",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_17,
{ "Directed Advertising State and Active Scanning State combination", "bthci_evt.le_states_17",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_20,
{ "Non-connectable Advertising State and Initiating State combination", "bthci_evt.le_states_20",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_21,
{ "Scannable Advertising State and Initiating State combination", "bthci_evt.le_states_21",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_22,
{ "Non-connectable Advertising State and Master Role combination", "bthci_evt.le_states_22",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_23,
{ "Scannable Advertising State and Master Role combination", "bthci_evt.le_states_23",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_24,
{ "Non-connectable Advertising State and Slave Role combination", "bthci_evt.le_states_24",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_25,
{ "Scannable Advertising State and Slave Role combination", "bthci_evt.le_states_25",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_26,
{ "Passive Scanning State and Initiating State combination", "bthci_evt.le_states_26",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_27,
{ "Active Scanning State and Initiating State combination", "bthci_evt.le_states_27",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_30,
{ "Passive Scanning State and Master Role combination", "bthci_evt.le_states_30",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_31,
{ "Active Scanning State and Master Role combination", "bthci_evt.le_states_31",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_32,
{ "Passive Scanning state and Slave Role combination", "bthci_evt.le_states_32",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_33,
{ "Active Scanning state and Slave Role combination", "bthci_evt.le_states_33",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_bthci_evt_le_states_34,
{ "Initiating State and Master Role combination. Master Role and Master Role combination", "bthci_evt.le_states_34",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_usable_packet_types,
{ "Usable Packet Types", "bthci_evt.usable_packet_types",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_changed_in_frame,
{ "Change in Frame", "bthci_evt.change_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_command_in_frame,
{ "Command in frame", "bthci_evt.command_in_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0x0,
NULL, HFILL }
},
{ &hf_pending_in_frame,
{ "Pending in frame", "bthci_evt.pending_in_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0,
NULL, HFILL }
},
{ &hf_response_in_frame,
{ "Response in frame", "bthci_evt.response_in_frame",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0,
NULL, HFILL }
},
{ &hf_command_response_time_delta,
{ "Command-Response Delta", "bthci_evt.command_response_delta",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_command_pending_time_delta,
{ "Command-Pending Delta", "bthci_evt.command_pending_delta",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pending_response_time_delta,
{ "Pending-Response Delta", "bthci_evt.pending_response_delta",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_event_undecoded, { "bthci_evt.expert.event.undecoded", PI_UNDECODED, PI_NOTE, "Event undecoded", EXPFILL }},
{ &ei_event_unknown_event, { "bthci_evt.expert.event.unknown_event", PI_PROTOCOL, PI_WARN, "Unknown event", EXPFILL }},
{ &ei_event_unknown_command, { "bthci_evt.expert.event.unknown_command", PI_PROTOCOL, PI_WARN, "Unknown command", EXPFILL }},
{ &ei_parameter_unexpected, { "bthci_evt.expert.parameter.unexpected", PI_PROTOCOL, PI_WARN, "Unexpected command parameter", EXPFILL }},
{ &ei_manufacturer_data_changed, { "bthci_evt.expert.event.manufacturer_data_changed", PI_PROTOCOL, PI_WARN, "Manufacturer data changed", EXPFILL }}
};
static gint *ett[] = {
&ett_bthci_evt,
&ett_opcode,
&ett_lmp_subtree,
&ett_ptype_subtree,
&ett_le_state_subtree,
&ett_le_channel_map,
&ett_expert
};
static build_valid_func bthci_evt_vendor_da_build_value[1] = {bthci_evt_vendor_value};
static decode_as_value_t bthci_evt_vendor_da_values = {bthci_evt_vendor_prompt, 1, bthci_evt_vendor_da_build_value};
static decode_as_t bthci_evt_vendor_da = {"bthci_cmd", "Vendor", "bthci_cmd.vendor", 1, 0, &bthci_evt_vendor_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_bthci_evt = proto_register_protocol("Bluetooth HCI Event",
"HCI_EVT", "bthci_evt");
bthci_evt_handle = register_dissector("bthci_evt", dissect_bthci_evt, proto_bthci_evt);
proto_register_field_array(proto_bthci_evt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bthci_evt = expert_register_protocol(proto_bthci_evt);
expert_register_field_array(expert_bthci_evt, ei, array_length(ei));
module = prefs_register_protocol(proto_bthci_evt, NULL);
prefs_register_static_text_preference(module, "hci_evt.version",
"Bluetooth HCI version: 4.0 (Core)",
"Version of protocol supported by this dissector.");
register_decode_as(&bthci_evt_vendor_da);
}
void
proto_reg_handoff_bthci_evt(void)
{
vendor_dissector_table = find_dissector_table("bthci_cmd.vendor");
hci_vendor_table = find_dissector_table("bluetooth.vendor");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_EVT, bthci_evt_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_EVENT, bthci_evt_handle);
bthci_cmd_handle = find_dissector_add_dependency("bthci_cmd", proto_bthci_evt);
btcommon_cod_handle = find_dissector_add_dependency("btcommon.cod", proto_bthci_evt);
btcommon_eir_handle = find_dissector_add_dependency("btcommon.eir_ad.eir", proto_bthci_evt);
btcommon_ad_handle = find_dissector_add_dependency("btcommon.eir_ad.ad", proto_bthci_evt);
btcommon_le_channel_map_handle = find_dissector_add_dependency("btcommon.le_channel_map", proto_bthci_evt);
}
