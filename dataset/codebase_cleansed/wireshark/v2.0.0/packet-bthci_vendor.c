static gint
dissect_bthci_vendor_broadcom(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *main_item;
proto_tree *main_tree;
proto_item *opcode_item;
proto_tree *opcode_tree;
proto_item *sub_item;
bluetooth_data_t *bluetooth_data;
gint offset = 0;
guint16 opcode;
guint16 ocf;
const gchar *description;
guint8 length;
guint8 event_code;
guint8 bd_addr[6];
guint8 status;
guint8 subcode;
guint8 condition;
guint32 interface_id;
guint32 adapter_id;
bluetooth_data = (bluetooth_data_t *) data;
if (bluetooth_data) {
interface_id = bluetooth_data->interface_id;
adapter_id = bluetooth_data->adapter_id;
} else {
interface_id = HCI_INTERFACE_DEFAULT;
adapter_id = HCI_ADAPTER_DEFAULT;
}
main_item = proto_tree_add_item(tree, proto_bthci_vendor_broadcom, tvb, 0, tvb_captured_length(tvb), ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_bthci_vendor_broadcom);
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_CMD_BROADCOM");
col_add_fstr(pinfo->cinfo, COL_INFO, "Sent Broadcom ");
opcode_item = proto_tree_add_item(main_tree, hf_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(opcode_item, ett_opcode);
opcode = tvb_get_letohs(tvb, offset);
proto_tree_add_item(opcode_tree, hf_opcode_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opcode_tree, hf_opcode_ocf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ocf = opcode & 0x03ff;
offset+=2;
description = val_to_str_const(ocf, opcode_ocf_vals, "unknown");
if (g_strcmp0(description, "unknown") != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", description);
else
col_append_fstr(pinfo->cinfo, COL_INFO, "Unknown Command 0x%04X (opcode 0x%04X)", ocf, opcode);
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
if (bluetooth_data) {
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
} else {
tap_hci_summary->interface_id = HCI_INTERFACE_DEFAULT;
tap_hci_summary->adapter_id = HCI_ADAPTER_DEFAULT;
}
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_VENDOR_OPCODE;
tap_hci_summary->ogf = opcode >> 10;
tap_hci_summary->ocf = ocf;
if (try_val_to_str(ocf, opcode_ocf_vals))
tap_hci_summary->name = description;
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
proto_tree_add_item(main_tree, hf_parameter_length, tvb, offset, 1, ENC_NA);
length = tvb_get_guint8(tvb, offset);
offset += 1;
switch(ocf) {
case 0x0001:
offset = dissect_bd_addr(hf_bd_addr, pinfo, main_tree, tvb, offset, TRUE, interface_id, adapter_id, bd_addr);
if (!pinfo->fd->flags.visited && bluetooth_data) {
wmem_tree_key_t key[4];
guint32 frame_number;
localhost_bdaddr_entry_t *localhost_bdaddr_entry;
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &bluetooth_data->interface_id;
key[1].length = 1;
key[1].key = &bluetooth_data->adapter_id;
key[2].length = 1;
key[2].key = &frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_bdaddr_entry = (localhost_bdaddr_entry_t *) wmem_new(wmem_file_scope(), localhost_bdaddr_entry_t);
localhost_bdaddr_entry->interface_id = bluetooth_data->interface_id;
localhost_bdaddr_entry->adapter_id = bluetooth_data->adapter_id;
memcpy(localhost_bdaddr_entry->bd_addr, bd_addr, 6);
wmem_tree_insert32_array(bluetooth_data->localhost_bdaddr, key, localhost_bdaddr_entry);
}
break;
case 0x0018:
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, 1, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += 1;
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, 1, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += 1;
proto_tree_add_item(main_tree, hf_baudrate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case 0x001C:
proto_tree_add_item(main_tree, hf_sco_pcm_routing, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_pcm_interface_clock_rate, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_pcm_interface_frame_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_pcm_interface_sync_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_pcm_interface_clock_mode, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x001E:
proto_tree_add_item(main_tree, hf_pcm_shift_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_pcm_fill_bits, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_pcm_fill_method, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_pcm_fill_number_of_bits, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_pcm_justify_mode, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x0027:
proto_tree_add_item(main_tree, hf_sleep_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_host_stack_idle_threshold, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_host_controller_idle_threshold, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_wake_polarity, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_host_wake_polarity, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_allow_host_sleep_during_sco, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_combine_sleep_mode_and_lpm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_enable_uart_txd_tri_state, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sleep_guard_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_wakeup_guard_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_txd_config, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_pulsed_host_wake, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x0045:
proto_tree_add_item(main_tree, hf_uart_clock, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x004C:
proto_tree_add_item(main_tree, hf_firmware_address, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(main_tree, hf_firmware, tvb, offset, length - 4, ENC_NA);
offset += length - 4;
break;
case 0x004E:
proto_tree_add_item(main_tree, hf_firmware_address, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
break;
case 0x0057:
proto_tree_add_item(main_tree, hf_connection_handle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(main_tree, hf_connection_priority, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x006D:
proto_tree_add_item(main_tree, hf_sco_i2s_pcm_interface_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_i2s_pcm_interface_role, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_i2s_pcm_interface_sample_rate, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_sco_i2s_pcm_interface_clock_rate, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x007E:
proto_tree_add_item(main_tree, hf_codec_state, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
offset += 1;
if (status == 0x01) {
proto_tree_add_item(main_tree, hf_codec, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case 0x0154:
proto_tree_add_item(main_tree, hf_le_multi_advertising_subcode, tvb, offset, 1, ENC_NA);
subcode = tvb_get_guint8(tvb, offset);
offset += 1;
switch (subcode) {
case 0x01:
proto_tree_add_item(main_tree, hf_le_multi_advertising_min_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(main_tree, hf_le_multi_advertising_max_interval, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(main_tree, hf_le_multi_advertising_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_multi_advertising_address_type, tvb, offset, 1, ENC_NA);
offset += 1;
offset = dissect_bd_addr(hf_bd_addr, pinfo, main_tree, tvb, offset, FALSE, interface_id, adapter_id, NULL);
proto_tree_add_item(main_tree, hf_le_multi_advertising_address_type, tvb, offset, 1, ENC_NA);
offset += 1;
offset = dissect_bd_addr(hf_bd_addr, pinfo, main_tree, tvb, offset, FALSE, interface_id, adapter_id, NULL);
proto_tree_add_bitmask(main_tree, tvb, offset, hf_le_multi_advertising_channel_map, ett_channel_map, hfx_le_multi_advertising_channel_map, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_multi_advertising_filter_policy, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_multi_advertising_instance_id, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_multi_advertising_tx_power, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x02:
case 0x03:
call_dissector_with_data(btcommon_ad_handle, tvb_new_subset_length(tvb, offset, 31), pinfo, tree, bluetooth_data);
save_local_device_name_from_eir_ad(tvb, offset, pinfo, 31, bluetooth_data);
offset += 31;
proto_tree_add_item(main_tree, hf_le_multi_advertising_instance_id, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x04:
offset = dissect_bd_addr(hf_bd_addr, pinfo, main_tree, tvb, offset, FALSE, interface_id, adapter_id, NULL);
proto_tree_add_item(main_tree, hf_le_multi_advertising_instance_id, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x05:
proto_tree_add_item(main_tree, hf_le_multi_advertising_enable, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_multi_advertising_instance_id, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
case 0x0156:
proto_tree_add_item(main_tree, hf_le_batch_scan_subcode, tvb, offset, 1, ENC_NA);
subcode = tvb_get_guint8(tvb, offset);
offset += 1;
switch (subcode) {
case 0x01:
proto_tree_add_item(main_tree, hf_le_batch_scan_enable, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x02:
proto_tree_add_item(main_tree, hf_le_batch_scan_full_max, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_batch_scan_truncate_max, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_batch_scan_notify_threshold, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x03:
proto_tree_add_item(main_tree, hf_le_batch_scan_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_batch_scan_window, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(main_tree, hf_le_batch_scan_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(main_tree, hf_le_batch_scan_address_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_batch_scan_discard_rule, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x04:
proto_tree_add_item(main_tree, hf_le_batch_scan_mode, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
case 0x0157:
proto_tree_add_item(main_tree, hf_le_advertising_filter_subcode, tvb, offset, 1, ENC_NA);
subcode = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(main_tree, hf_le_scan_condition, tvb, offset, 1, ENC_NA);
condition = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(main_tree, hf_le_filter_index, tvb, offset, 1, ENC_NA);
offset += 1;
if (condition == 0x00) {
switch (subcode) {
case 0x00:
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
case 0x08:
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length - 3, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += length - 3;
break;
default:
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length - 3, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_unexpected_data);
offset += length - 3;
}
}
break;
case 0x0102:
case 0x0111:
case 0x0112:
case 0x0113:
case 0x0114:
case 0x0158:
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += length;
break;
case 0x002E:
case 0x0153:
case 0x0159:
if (tvb_captured_length_remaining(tvb, offset) > 0) {
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_unexpected_parameter);
}
break;
default:
if (length > 0) {
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += length;
}
}
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_EVT_BROADCOM");
col_add_fstr(pinfo->cinfo, COL_INFO, "Rcvd Broadcom ");
event_code = tvb_get_guint8(tvb, offset);
description = val_to_str_ext_const(event_code, &bthci_evt_evt_code_vals_ext, "Unknown 0x%08x");
col_append_str(pinfo->cinfo, COL_INFO, description);
proto_tree_add_item(main_tree, hf_event_code, tvb, offset, 1, ENC_NA);
offset += 1;
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
if (bluetooth_data) {
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
} else {
tap_hci_summary->interface_id = HCI_INTERFACE_DEFAULT;
tap_hci_summary->adapter_id = HCI_ADAPTER_DEFAULT;
}
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_VENDOR_EVENT;
tap_hci_summary->event = event_code;
if (try_val_to_str_ext(event_code, &bthci_evt_evt_code_vals_ext))
tap_hci_summary->name = description;
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
proto_tree_add_item(main_tree, hf_parameter_length, tvb, offset, 1, ENC_NA);
length = tvb_get_guint8(tvb, offset);
offset += 1;
switch (event_code) {
case 0x0e:
proto_tree_add_item(main_tree, hf_number_of_allowed_command_packets, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
opcode_item = proto_tree_add_item(main_tree, hf_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
opcode_tree = proto_item_add_subtree(opcode_item, ett_opcode);
opcode = tvb_get_letohs(tvb, offset);
proto_tree_add_item(opcode_tree, hf_opcode_ogf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(opcode_tree, hf_opcode_ocf, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ocf = opcode & 0x03ff;
offset += 2;
description = val_to_str_const(ocf, opcode_ocf_vals, "unknown");
if (g_strcmp0(description, "unknown") != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", description);
else
col_append_fstr(pinfo->cinfo, COL_INFO, " (Unknown Command 0x%04X [opcode 0x%04X])", ocf, opcode);
if (have_tap_listener(bluetooth_hci_summary_tap)) {
bluetooth_hci_summary_tap_t *tap_hci_summary;
tap_hci_summary = wmem_new(wmem_packet_scope(), bluetooth_hci_summary_tap_t);
if (bluetooth_data) {
tap_hci_summary->interface_id = bluetooth_data->interface_id;
tap_hci_summary->adapter_id = bluetooth_data->adapter_id;
} else {
tap_hci_summary->interface_id = HCI_INTERFACE_DEFAULT;
tap_hci_summary->adapter_id = HCI_ADAPTER_DEFAULT;
}
tap_hci_summary->type = BLUETOOTH_HCI_SUMMARY_VENDOR_EVENT_OPCODE;
tap_hci_summary->ogf = opcode >> 10;
tap_hci_summary->ocf = ocf;
if (try_val_to_str(ocf, opcode_ocf_vals))
tap_hci_summary->name = description;
else
tap_hci_summary->name = NULL;
tap_queue_packet(bluetooth_hci_summary_tap, pinfo, tap_hci_summary);
}
proto_tree_add_item(main_tree, hf_status, tvb, offset, 1, ENC_NA);
status = tvb_get_guint8(tvb, offset);
offset += 1;
switch (ocf) {
case 0x0153:
if (status != STATUS_SUCCESS)
break;
proto_tree_add_item(main_tree, hf_max_advertising_instance, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_resolvable_private_address_offloading, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_total_scan_results, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(main_tree, hf_max_irk_list, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_filter_support, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_max_filter, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_energy_support, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x0154:
proto_tree_add_item(main_tree, hf_le_multi_advertising_subcode, tvb, offset, 1, ENC_NA);
offset += 1;
break;
case 0x0156:
proto_tree_add_item(main_tree, hf_le_batch_scan_subcode, tvb, offset, 1, ENC_NA);
subcode = tvb_get_guint8(tvb, offset);
offset += 1;
if (subcode == 0x04 && status == STATUS_SUCCESS) {
proto_tree_add_item(main_tree, hf_le_batch_scan_report_format, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_batch_scan_number_of_records, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
case 0x0157:
proto_tree_add_item(main_tree, hf_le_advertising_filter_subcode, tvb, offset, 1, ENC_NA);
offset += 1;
if (status == STATUS_SUCCESS) {
proto_tree_add_item(main_tree, hf_le_scan_condition, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_number_of_available_filters, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
case 0x0159:
if (status == STATUS_SUCCESS) {
proto_tree_add_item(main_tree, hf_le_energy_total_rx_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_energy_total_tx_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_energy_total_idle_time, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(main_tree, hf_le_energy_total_energy_used, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
case 0x0102:
case 0x0111:
case 0x0112:
case 0x0113:
case 0x0114:
case 0x0158:
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += length;
break;
case 0x0001:
case 0x0018:
case 0x001C:
case 0x001E:
case 0x0027:
case 0x002E:
case 0x0045:
case 0x004C:
case 0x004E:
case 0x0057:
case 0x006D:
case 0x007E:
default:
if (tvb_captured_length_remaining(tvb, offset) > 0) {
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_unexpected_parameter);
offset += tvb_captured_length_remaining(tvb, offset);
}
}
break;
default:
if (length > 0) {
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, length, ENC_NA);
expert_add_info(pinfo, sub_item, &ei_undecoded);
offset += length;
}
}
break;
case P2P_DIR_UNKNOWN:
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_BROADCOM");
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection Broadcom ");
if (tvb_captured_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(main_tree, hf_data, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
break;
}
if (tvb_captured_length_remaining(tvb, offset) > 0) {
sub_item = proto_tree_add_item(main_tree, hf_data, tvb, offset, tvb_captured_length_remaining(tvb, offset), ENC_NA);
expert_add_info(pinfo, sub_item, &ei_unexpected_data);
offset += tvb_captured_length_remaining(tvb, offset);
}
return offset;
}
void
proto_register_bthci_vendor_broadcom(void)
{
guint i_opcode = 0;
guint i_array;
guint i_string_array;
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_opcode,
{ "Command Opcode", "bthci_vendor.broadcom.opcode",
FT_UINT16, BASE_HEX, VALS(opcode_vals), 0x0,
"HCI Command Opcode", HFILL }
},
{ &hf_opcode_ogf,
{ "Opcode Group Field", "bthci_vendor.broadcom.opcode.ogf",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_ogf_vals_ext, 0xfc00,
NULL, HFILL }
},
{ &hf_opcode_ocf,
{ "Opcode Command Field", "bthci_vendor.broadcom.opcode.ocf",
FT_UINT16, BASE_HEX, VALS(opcode_ocf_vals), 0x03ff,
NULL, HFILL }
},
{ &hf_parameter_length,
{ "Parameter Total Length", "bthci_vendor.broadcom.parameter_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_event_code,
{ "Event Code", "bthci_vendor.broadcom.event_code",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bthci_evt_evt_code_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_number_of_allowed_command_packets,
{ "Number of Allowed Command Packets", "bthci_vendor.broadcom.number_of_allowed_command_packets",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_advertising_filter_subcode,
{ "Subcode", "bthci_vendor.broadcom.le.advertising_filter.subcode",
FT_UINT8, BASE_HEX, VALS(le_subcode_advertising_filter_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_scan_condition,
{ "Scan Condition", "bthci_vendor.broadcom.le.scan_condition",
FT_UINT8, BASE_HEX, VALS(le_scan_condition_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_filter_index,
{ "Filter Index", "bthci_vendor.broadcom.le.filter_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_number_of_available_filters,
{ "Number of Available Filters", "bthci_vendor.broadcom.le.number_of_available_filters",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_firmware_address,
{ "Address", "bthci_vendor.broadcom.firmware.address",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_firmware,
{ "Firmware", "bthci_vendor.broadcom.firmware.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_baudrate,
{ "Baudrate", "bthci_vendor.broadcom.baudrate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bd_addr,
{ "BD_ADDR", "bthci_vendor.broadcom.bd_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Bluetooth Device Address", HFILL}
},
{ &hf_max_advertising_instance,
{ "Max Advertising Instance", "bthci_vendor.broadcom.max_advertising_instance",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_resolvable_private_address_offloading,
{ "Resolvable Private Address Offloading", "bthci_vendor.broadcom.resolvable_private_address_offloading",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_total_scan_results,
{ "Total Scan Results", "bthci_vendor.broadcom.total_scan_results",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_max_irk_list,
{ "Max IRK List", "bthci_vendor.broadcom.max_irk_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_filter_support,
{ "Filter Support", "bthci_vendor.broadcom.filter_support",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_max_filter,
{ "Max Filter", "bthci_vendor.broadcom.max_filter",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_energy_support,
{ "Energy Support", "bthci_vendor.broadcom.energy_support",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uart_clock,
{ "UART Clock", "bthci_vendor.broadcom.uart_clock",
FT_UINT8, BASE_HEX, VALS(uart_clock_vals), 0x0,
NULL, HFILL }
},
{ &hf_connection_handle,
{ "Connection Handle", "bthci_vendor.broadcom.connection_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_connection_priority,
{ "Connection Priority", "bthci_vendor.broadcom.connection_priority",
FT_UINT8, BASE_HEX, VALS(connection_priority_vals), 0x0,
NULL, HFILL }
},
{ &hf_sleep_mode,
{ "Sleep Mode", "bthci_vendor.broadcom.sleep_mode",
FT_UINT8, BASE_HEX, VALS(sleep_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_host_stack_idle_threshold,
{ "Host Stack Idle Threshold", "bthci_vendor.broadcom.host_stack_idle_threshold",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_host_controller_idle_threshold,
{ "Host Controller Idle Threshold", "bthci_vendor.broadcom.host_controller_idle_threshold",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_wake_polarity,
{ "Wake Polarity", "bthci_vendor.broadcom.wake_polarity",
FT_UINT8, BASE_HEX, VALS(wake_polarity_vals), 0x0,
NULL, HFILL }
},
{ &hf_host_wake_polarity,
{ "Host Wake Polarity", "bthci_vendor.broadcom.host_wake_polarity",
FT_UINT8, BASE_HEX, VALS(wake_polarity_vals), 0x0,
NULL, HFILL }
},
{ &hf_allow_host_sleep_during_sco,
{ "Allow Host Sleep During SCO", "bthci_vendor.broadcom.allow_host_sleep_during_sco",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_combine_sleep_mode_and_lpm,
{ "Combine Sleep Mode and LPM", "bthci_vendor.broadcom.combine_sleep_mode_and_lpm",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_enable_uart_txd_tri_state,
{ "Enable UART TXD Tri-state", "bthci_vendor.broadcom.enable_uart_txd_tri_state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sleep_guard_time,
{ "Sleep Guard Time", "bthci_vendor.broadcom.sleep_guard_time",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_wakeup_guard_time,
{ "Wakeup Guard Time", "bthci_vendor.broadcom.wakeup_guard_time",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_txd_config,
{ "TXD Config", "bthci_vendor.broadcom.txd_config",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pulsed_host_wake,
{ "Pulsed Host Wake", "bthci_vendor.broadcom.pulsed_host_wake",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_codec_state,
{ "Codec State", "bthci_vendor.broadcom.codec_state",
FT_UINT8, BASE_HEX, VALS(codec_state_vals), 0x0,
NULL, HFILL }
},
{ &hf_codec,
{ "Codec", "bthci_vendor.broadcom.codec",
FT_UINT16, BASE_HEX, VALS(codec_vals), 0x0,
NULL, HFILL }
},
{ &hf_status,
{ "Status", "bthci_vendor.broadcom.status",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bthci_cmd_status_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_sco_pcm_routing,
{ "SCO PCM Routing", "bthci_vendor.broadcom.sco.pcm_routing",
FT_UINT8, BASE_HEX, VALS(sco_pcm_routing_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_pcm_interface_clock_rate,
{ "SCO PCM Interface Clock Rate", "bthci_vendor.broadcom.sco.interface.clock_rate",
FT_UINT8, BASE_HEX, VALS(sco_pcm_interface_clock_rate_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_pcm_interface_frame_type,
{ "SCO PCM Interface Frame Type", "bthci_vendor.broadcom.sco.interface.frame_type",
FT_UINT8, BASE_HEX, VALS(sco_pcm_interface_frame_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_pcm_interface_sync_mode,
{ "SCO PCM Interface Sync Mode", "bthci_vendor.broadcom.sco.interface.sync_mode",
FT_UINT8, BASE_HEX, VALS(mode_slave_master_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_pcm_interface_clock_mode,
{ "SCO PCM Interface Clock Mode", "bthci_vendor.broadcom.sco.interface.",
FT_UINT8, BASE_HEX, VALS(mode_slave_master_vals), 0x0,
NULL, HFILL }
},
{ &hf_pcm_shift_mode,
{ "PCM shift_mode", "bthci_vendor.broadcom.pcm.shift_mode",
FT_UINT8, BASE_HEX, VALS(pcm_shift_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_pcm_fill_bits,
{ "PCM Fill Bits", "bthci_vendor.broadcom.pcm.fill_bits",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pcm_fill_method,
{ "PCM Fill Method", "bthci_vendor.broadcom.pcm.fill_method",
FT_UINT8, BASE_HEX, VALS(pcm_fill_method_vals), 0x0,
NULL, HFILL }
},
{ &hf_pcm_fill_number_of_bits,
{ "PCM fill_number_of_bits", "bthci_vendor.broadcom.pcm.fill_number_of_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pcm_justify_mode,
{ "PCM Justify Mode", "bthci_vendor.broadcom.pcm.justify_mode",
FT_UINT8, BASE_HEX, VALS(pcm_justify_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_i2s_pcm_interface_mode,
{ "SCO I2S PCM Interface Mode", "bthci_vendor.broadcom.pcm.i2s_pcm_interface.mode",
FT_UINT8, BASE_HEX, VALS(sco_i2s_pcm_interface_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_i2s_pcm_interface_role,
{ "SCO I2S PCM Interface Role", "bthci_vendor.broadcom.pcm.i2s_pcm_interface.role",
FT_UINT8, BASE_HEX, VALS(mode_slave_master_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_i2s_pcm_interface_sample_rate,
{ "SCO I2S PCM Interface Sample_Rate", "bthci_vendor.broadcom.sco.i2s_pcm_interface.sample_rate",
FT_UINT8, BASE_HEX, VALS(sco_i2s_pcm_interface_sample_rate_vals), 0x0,
NULL, HFILL }
},
{ &hf_sco_i2s_pcm_interface_clock_rate,
{ "SCO I2S PCM Interface Clock Rate", "bthci_vendor.broadcom.pcm.i2s_pcm_interface.clock_rate",
FT_UINT8, BASE_HEX, VALS(sco_i2s_pcm_interface_clock_rate_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_energy_total_rx_time,
{ "Total RX Time", "bthci_vendor.broadcom.le.total_rx_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_energy_total_tx_time,
{ "Total TX Time", "bthci_vendor.broadcom.le.total_tx_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_energy_total_idle_time,
{ "Total Idle Time", "bthci_vendor.broadcom.le.total_idle_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_energy_total_energy_used,
{ "Total Energy Used Time", "bthci_vendor.broadcom.le.total_energy_used",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_subcode,
{ "Subcode", "bthci_vendor.broadcom.le.batch_scan.subcode",
FT_UINT8, BASE_HEX, VALS(le_subcode_batch_scan_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_report_format,
{ "Report Format", "bthci_vendor.broadcom.le.batch_scan.report_format",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_number_of_records,
{ "Number of Records", "bthci_vendor.broadcom.le.batch_scan.number_of_records",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_mode,
{ "Mode", "bthci_vendor.broadcom.le.batch_scan.mode",
FT_UINT8, BASE_HEX, VALS(batch_scan_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_enable,
{ "Enable", "bthci_vendor.broadcom.le.batch_scan.enable",
FT_UINT8, BASE_HEX, VALS(disable_enable_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_full_max,
{ "Full Max", "bthci_vendor.broadcom.le.batch_scan.full_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_truncate_max,
{ "Truncate Max", "bthci_vendor.broadcom.le.batch_scan.truncate_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_notify_threshold,
{ "notify_threshold", "bthci_vendor.broadcom.le.batch_scan.notify_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_window,
{ "Window", "bthci_vendor.broadcom.le.batch_scan.window",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_interval,
{ "Interval", "bthci_vendor.broadcom.le.batch_scan.interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_address_type,
{ "Address Type", "bthci_vendor.broadcom.le.batch_scan.address_type",
FT_UINT8, BASE_HEX, VALS(bluetooth_address_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_batch_scan_discard_rule,
{ "Discard Rule", "bthci_vendor.broadcom.le.batch_scan.discard_rule",
FT_UINT8, BASE_HEX, VALS(batch_scan_discard_rule_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_subcode,
{ "Subcode", "bthci_vendor.broadcom.le.multi_advertising.subcode",
FT_UINT8, BASE_HEX, VALS(le_subcode_multi_advertising_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_enable,
{ "Enable", "bthci_vendor.broadcom.le.multi_advertising.enable",
FT_UINT8, BASE_HEX, VALS(disable_enable_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_instance_id,
{ "Full Max", "bthci_vendor.broadcom.le.multi_advertising.instance_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_min_interval,
{ "Min Interval", "bthci_vendor.broadcom.le.multi_advertising.min_interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_max_interval,
{ "Max Interval", "bthci_vendor.broadcom.le.multi_advertising.max_interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_address_type,
{ "Address Type", "bthci_vendor.broadcom.le.multi_advertising.address_type",
FT_UINT8, BASE_HEX, VALS(bluetooth_address_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_type,
{ "Type", "bthci_vendor.broadcom.le.multi_advertising.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bthci_cmd_eir_data_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_channel_map,
{ "Channel Map", "bthci_vendor.broadcom.le.multi_advertising.channel_map",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_channel_map_reserved,
{ "Reserved", "bthci_vendor.broadcom.le.multi_advertising.channel_map.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF8,
NULL, HFILL }
},
{ &hf_le_multi_advertising_channel_map_39,
{ "Channel 39", "bthci_vendor.broadcom.le.multi_advertising.channel_map.39",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }
},
{ &hf_le_multi_advertising_channel_map_38,
{ "Channel 39", "bthci_vendor.broadcom.le.multi_advertising.channel_map.38",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }
},
{ &hf_le_multi_advertising_channel_map_37,
{ "Channel 39", "bthci_vendor.broadcom.le.multi_advertising.channel_map.37",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }
},
{ &hf_le_multi_advertising_filter_policy,
{ "Filter Policy", "bthci_vendor.broadcom.le.multi_advertising.filter_policy",
FT_UINT8, BASE_HEX, VALS(le_filter_policy_vals), 0x0,
NULL, HFILL }
},
{ &hf_le_multi_advertising_tx_power,
{ "Tx power", "bthci_vendor.broadcom.le.multi_advertising.tx_power",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_data,
{ "Data", "bthci_vendor.broadcom.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bthci_vendor_broadcom,
&ett_opcode,
&ett_channel_map
};
static ei_register_info ei[] = {
{ &ei_undecoded, { "bthci_vendor.broadcom.undecoded", PI_PROTOCOL, PI_UNDECODED, "Undecoded", EXPFILL }},
{ &ei_unexpected_parameter, { "bthci_vendor.broadcom.unexpected_parameter", PI_PROTOCOL, PI_WARN, "Unexpected parameter", EXPFILL }},
{ &ei_unexpected_data, { "bthci_vendor.broadcom.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected data", EXPFILL }},
};
static const struct _opcode_value_string_arrays {
guint ogf;
const value_string *string_array;
guint length;
} opcode_value_string_arrays[] = {
{ 0x3F, opcode_ocf_vals, array_length(opcode_vals) },
};
for (i_array = 0; i_array < array_length(opcode_value_string_arrays); i_array += 1) {
for (i_string_array = 0; i_string_array < opcode_value_string_arrays[i_array].length - 1; i_string_array += 1) {
opcode_vals[i_opcode].value = opcode_value_string_arrays[i_array].string_array[i_string_array].value | (opcode_value_string_arrays[i_array].ogf << 10);
opcode_vals[i_opcode].strptr = opcode_value_string_arrays[i_array].string_array[i_string_array].strptr;
i_opcode += 1;
}
}
opcode_vals[i_opcode].value = 0;
opcode_vals[i_opcode].strptr = NULL;
proto_bthci_vendor_broadcom = proto_register_protocol("Bluetooth Broadcom HCI",
"HCI BROADCOM", "bthci_vendor.broadcom");
bthci_vendor_broadcom_handle = new_register_dissector("bthci_vendor.broadcom", dissect_bthci_vendor_broadcom, proto_bthci_vendor_broadcom);
proto_register_field_array(proto_bthci_vendor_broadcom, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_module = expert_register_protocol(proto_bthci_vendor_broadcom);
expert_register_field_array(expert_module, ei, array_length(ei));
}
void
proto_reg_handoff_bthci_vendor_broadcom(void)
{
btcommon_ad_handle = find_dissector("btcommon.eir_ad.ad");
dissector_add_for_decode_as("bthci_cmd.vendor", bthci_vendor_broadcom_handle);
dissector_add_uint("bluetooth.vendor", 0x000F, bthci_vendor_broadcom_handle);
}
