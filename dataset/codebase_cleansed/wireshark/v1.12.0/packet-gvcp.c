static const gchar* get_register_name_from_address(guint32 addr, gboolean* is_custom_register)
{
const gchar* address_string = NULL;
if (is_custom_register != NULL)
{
*is_custom_register = FALSE;
}
address_string = try_val_to_str(addr, bootstrapregisternames);
if (!address_string)
{
address_string = wmem_strdup_printf(wmem_packet_scope(),"[Addr:0x%08X]", addr);
if (is_custom_register != NULL)
{
*is_custom_register = TRUE;
}
}
return address_string;
}
static int dissect_register(guint32 addr, proto_tree *branch, tvbuff_t *tvb, gint offset, gint length)
{
switch (addr)
{
case GVCP_VERSION:
proto_tree_add_item(branch, hf_gvcp_spec_version_major, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_spec_version_minor, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_DEVICE_MODE:
proto_tree_add_item(branch, hf_gvcp_devicemode_endianess, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_devicemode_deviceclass, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_devicemode_characterset, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_DEVICE_MAC_HIGH_0:
case GVCP_DEVICE_MAC_HIGH_1:
case GVCP_DEVICE_MAC_HIGH_2:
case GVCP_DEVICE_MAC_HIGH_3:
proto_tree_add_item(branch, hf_gvcp_machigh, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_DEVICE_MAC_LOW_0:
case GVCP_DEVICE_MAC_LOW_1:
case GVCP_DEVICE_MAC_LOW_2:
case GVCP_DEVICE_MAC_LOW_3:
proto_tree_add_item(branch, hf_gvcp_maclow, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SUPPORTED_IP_CONFIGURATION_0:
case GVCP_SUPPORTED_IP_CONFIGURATION_1:
case GVCP_SUPPORTED_IP_CONFIGURATION_2:
case GVCP_SUPPORTED_IP_CONFIGURATION_3:
proto_tree_add_item(branch, hf_gvcp_ip_config_can_handle_pause_frames_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_can_generate_pause_frames_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_lla, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_dhcp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_persistent_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CURIPCFG_0:
case GVCP_CURIPCFG_1:
case GVCP_CURIPCFG_2:
case GVCP_CURIPCFG_3:
proto_tree_add_item(branch, hf_gvcp_ip_config_can_handle_pause_frames_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_can_generate_pause_frames_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_lla, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_dhcp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_ip_config_persistent_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CURRENT_IP_ADDRESS_0:
case GVCP_CURRENT_IP_ADDRESS_1:
case GVCP_CURRENT_IP_ADDRESS_2:
case GVCP_CURRENT_IP_ADDRESS_3:
proto_tree_add_item(branch, hf_gvcp_current_IP, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CURRENT_SUBNET_MASK_0:
case GVCP_CURRENT_SUBNET_MASK_1:
case GVCP_CURRENT_SUBNET_MASK_2:
case GVCP_CURRENT_SUBNET_MASK_3:
proto_tree_add_item(branch, hf_gvcp_current_subnet_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CURRENT_DEFAULT_GATEWAY_0:
case GVCP_CURRENT_DEFAULT_GATEWAY_1:
case GVCP_CURRENT_DEFAULT_GATEWAY_2:
case GVCP_CURRENT_DEFAULT_GATEWAY_3:
proto_tree_add_item(branch, hf_gvcp_current_default_gateway, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MANUFACTURER_NAME:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_MODEL_NAME:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_DEVICE_VERSION:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_MANUFACTURER_INFO:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_SERIAL_NUMBER:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_USER_DEFINED_NAME:
proto_tree_add_item(branch, hf_gvcp_user_defined_name, tvb, offset, 4, ENC_ASCII|ENC_NA);
break;
case GVCP_FIRST_URL:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_SECOND_URL:
proto_tree_add_text(branch, tvb, 0, length, "Reserved Bit");
break;
case GVCP_NUMBER_OF_NETWORK_INTERFACES:
proto_tree_add_item(branch, hf_gvcp_number_interfaces, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PERSISTENT_IP_ADDRESS_0:
case GVCP_PERSISTENT_IP_ADDRESS_1:
case GVCP_PERSISTENT_IP_ADDRESS_2:
case GVCP_PERSISTENT_IP_ADDRESS_3:
proto_tree_add_item(branch, hf_gvcp_persistent_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PERSISTENT_SUBNET_MASK_0:
case GVCP_PERSISTENT_SUBNET_MASK_1:
case GVCP_PERSISTENT_SUBNET_MASK_2:
case GVCP_PERSISTENT_SUBNET_MASK_3:
proto_tree_add_item(branch, hf_gvcp_persistent_subnet, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PERSISTENT_DEFAULT_GATEWAY_0:
case GVCP_PERSISTENT_DEFAULT_GATEWAY_1:
case GVCP_PERSISTENT_DEFAULT_GATEWAY_2:
case GVCP_PERSISTENT_DEFAULT_GATEWAY_3:
proto_tree_add_item(branch, hf_gvcp_persistent_gateway, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_LINK_SPEED_0:
case GVCP_LINK_SPEED_1:
case GVCP_LINK_SPEED_2:
case GVCP_LINK_SPEED_3:
proto_tree_add_item(branch, hf_gvcp_link_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_NUMBER_OF_MESSAGE_CHANNELS:
proto_tree_add_item(branch, hf_gvcp_number_message_channels, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_NUMBER_OF_STREAM_CHANNELS:
proto_tree_add_item(branch, hf_gvcp_number_stream_channels, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_NUMBER_OF_ACTION_SIGNALS:
proto_tree_add_item(branch, hf_gvcp_number_action_signals, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_ACTION_DEVICE_KEY:
proto_tree_add_item(branch, hf_gvcp_writeregcmd_data, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_NUMBER_OF_ACTIVE_LINKS:
proto_tree_add_item(branch, hf_gvcp_number_of_active_links_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_CAPS:
proto_tree_add_item(branch, hf_gvcp_sccaps_scspx_register_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sccaps_legacy_16bit_blockid_supported_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MESSAGE_CHANNEL_CAPS:
proto_tree_add_item(branch, hf_gvcp_mcsp_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CAPABILITY:
proto_tree_add_item(branch, hf_gvcp_capability_user_defined, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_serial_number, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_heartbeat_disable, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_link_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_ccp_application_portip, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_manifest_table, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_test_data, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_discovery_ACK_delay, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_writable_discovery_ACK_delay, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_extended_status_code_v1_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_primary_application_switchover, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_unconditional_action_command, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_1588_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_extended_status_code_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_scheduled_action_command_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_action_command, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_pending, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_evendata, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_event, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_packetresend, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_writemem, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_capability_concatenation, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_HEARTBEAT_TIMEOUT:
proto_tree_add_item(branch, hf_gvcp_heartbeat, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_TIMESTAMP_TICK_FREQUENCY_HIGH:
proto_tree_add_item(branch, hf_gvcp_high_timestamp_frequency, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_TIMESTAMP_TICK_FREQUENCY_LOW:
proto_tree_add_item(branch, hf_gvcp_low_timestamp_frequency, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_TIMESTAMP_CONTROL:
proto_tree_add_item(branch, hf_gvcp_timestamp_control_latch, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_timestamp_control_reset, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_TIMESTAMP_VALUE_HIGH:
proto_tree_add_item(branch, hf_gvcp_high_timestamp_value, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_TIMESTAMP_VALUE_LOW:
proto_tree_add_item(branch, hf_gvcp_low_timestamp_value, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_DISCOVERY_ACK_DELAY:
proto_tree_add_item(branch, hf_gvcp_discovery_ACK_delay, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CONFIGURATION:
proto_tree_add_item(branch, hf_gvcp_configuration_1588_enable_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_configuration_extended_status_codes_enable_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_configuration_unconditional_action_command_enable_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_configuration_extended_status_codes_enable_v1_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_configuration_pending_ack_enable, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_configuration_heartbeat_disable, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PENDING_TIMEOUT:
proto_tree_add_item(branch, hf_gvcp_pending_timeout_max_execution, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CONTROL_SWITCHOVER_KEY:
proto_tree_add_item(branch, hf_gvcp_control_switchover_key_register, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_GVSCP_CONFIGURATION:
proto_tree_add_item(branch, hf_gvcp_gvsp_configuration_64bit_blockid_enable_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PHYSICAL_LINK_CAPABILITY:
proto_tree_add_item(branch, hf_gvcp_link_dlag_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_slag_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_ml_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_sl_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PHYSICAL_LINK_CONFIGURATION:
proto_tree_add_item(branch, hf_gvcp_link_dlag_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_slag_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_ml_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_link_sl_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_IEEE_1588_STATUS:
proto_tree_add_item(branch, hf_gvcp_ieee1588_clock_status_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SCHEDULED_ACTION_COMMAND_QUEUE_SIZE:
proto_tree_add_item(branch, hf_gvcp_scheduled_action_command_queue_size_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_CCP:
proto_tree_add_item(branch, hf_gvcp_control_switchover_key, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_control_switchover_en, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_control_access, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_exclusive_access, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PRIMARY_APPLICATION_PORT:
proto_tree_add_item(branch, hf_gvcp_primary_application_host_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_PRIMARY_APPLICATION_IP_ADDRESS:
proto_tree_add_item(branch, hf_gvcp_primary_application_ip_address, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MC_DESTINATION_PORT:
proto_tree_add_item(branch, hf_gvcp_network_interface_index, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_host_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MC_DESTINATION_ADDRESS:
proto_tree_add_item(branch, hf_gvcp_channel_destination_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MC_TIMEOUT:
proto_tree_add_item(branch, hf_gvcp_message_channel_transmission_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MC_RETRY_COUNT:
proto_tree_add_item(branch, hf_gvcp_message_channel_retry_count, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MC_SOURCE_PORT:
proto_tree_add_item(branch, hf_gvcp_message_channel_source_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_DESTINATION_PORT(0):
case GVCP_SC_DESTINATION_PORT(1):
case GVCP_SC_DESTINATION_PORT(2):
case GVCP_SC_DESTINATION_PORT(3):
proto_tree_add_item(branch, hf_gvcp_sc_direction, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_ni_index, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_host_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_PACKET_SIZE(0):
case GVCP_SC_PACKET_SIZE(1):
case GVCP_SC_PACKET_SIZE(2):
case GVCP_SC_PACKET_SIZE(3):
proto_tree_add_item(branch, hf_gvcp_sc_fire_test_packet, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_do_not_fragment, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_pixel_endianness, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_packet_size, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case GVCP_SC_PACKET_DELAY(0):
case GVCP_SC_PACKET_DELAY(1):
case GVCP_SC_PACKET_DELAY(2):
case GVCP_SC_PACKET_DELAY(3):
proto_tree_add_item(branch, hf_gvcp_sc_packet_delay, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_DESTINATION_ADDRESS(0):
case GVCP_SC_DESTINATION_ADDRESS(1):
case GVCP_SC_DESTINATION_ADDRESS(2):
case GVCP_SC_DESTINATION_ADDRESS(3):
{
guint32 value = 0;
value = tvb_get_letohl(tvb, offset);
proto_tree_add_ipv4(branch, hf_gvcp_sc_destination_ip, tvb, offset, 4, value);
}
break;
case GVCP_SC_SOURCE_PORT(0):
case GVCP_SC_SOURCE_PORT(1):
case GVCP_SC_SOURCE_PORT(2):
case GVCP_SC_SOURCE_PORT(3):
proto_tree_add_item(branch, hf_gvcp_sc_source_port, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_CAPABILITY(0):
case GVCP_SC_CAPABILITY(1):
case GVCP_SC_CAPABILITY(2):
case GVCP_SC_CAPABILITY(3):
proto_tree_add_item(branch, hf_gvcp_sc_big_little_endian_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_ip_reassembly_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_multizone_supported_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_packet_resend_destination_option_supported_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_packet_resend_all_in_transmission_supported_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_unconditional_streaming_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_extended_chunk_data_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_CONFIGURATION(0):
case GVCP_SC_CONFIGURATION(1):
case GVCP_SC_CONFIGURATION(2):
case GVCP_SC_CONFIGURATION(3):
proto_tree_add_item(branch, hf_gvcp_sc_packet_resend_destination_option_enabled_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_packet_resend_all_in_transmission_enabled_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_unconditional_streaming_enabled, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_extended_chunk_data_enabled, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_ZONE(0):
case GVCP_SC_ZONE(1):
case GVCP_SC_ZONE(2):
case GVCP_SC_ZONE(3):
proto_tree_add_item(branch, hf_gvcp_sc_additional_zones_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_SC_ZONE_DIRECTION(0):
case GVCP_SC_ZONE_DIRECTION(1):
case GVCP_SC_ZONE_DIRECTION(2):
case GVCP_SC_ZONE_DIRECTION(3):
proto_tree_add_item(branch, hf_gvcp_sc_zone0_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone1_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone2_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone3_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone4_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone5_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone6_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone7_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone8_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone9_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone10_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone11_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone12_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone13_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone14_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone15_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone16_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone17_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone18_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone19_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone20_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone21_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone22_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone23_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone24_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone25_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone26_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone27_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone28_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone29_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone30_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(branch, hf_gvcp_sc_zone31_direction_v2_0, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_MANIFEST_TABLE:
proto_tree_add_text(branch, tvb, 0, length, "Manifest Table");
break;
case GVCP_ACTION_GROUP_KEY(0):
case GVCP_ACTION_GROUP_KEY(1):
case GVCP_ACTION_GROUP_KEY(2):
case GVCP_ACTION_GROUP_KEY(3):
case GVCP_ACTION_GROUP_KEY(4):
case GVCP_ACTION_GROUP_KEY(5):
case GVCP_ACTION_GROUP_KEY(6):
case GVCP_ACTION_GROUP_KEY(7):
case GVCP_ACTION_GROUP_KEY(8):
case GVCP_ACTION_GROUP_KEY(9):
proto_tree_add_item(branch, hf_gvcp_action_group_key, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case GVCP_ACTION_GROUP_MASK(0):
case GVCP_ACTION_GROUP_MASK(1):
case GVCP_ACTION_GROUP_MASK(2):
case GVCP_ACTION_GROUP_MASK(3):
case GVCP_ACTION_GROUP_MASK(4):
case GVCP_ACTION_GROUP_MASK(5):
case GVCP_ACTION_GROUP_MASK(6):
case GVCP_ACTION_GROUP_MASK(7):
case GVCP_ACTION_GROUP_MASK(8):
case GVCP_ACTION_GROUP_MASK(9):
proto_tree_add_item(branch, hf_gvcp_action_group_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
return 0;
}
return 1;
}
static int dissect_register_data(guint32 addr, proto_tree *branch, tvbuff_t *tvb, gint offset, gint length)
{
switch (addr)
{
case GVCP_MANUFACTURER_NAME:
if (length == 32)
{
proto_tree_add_item(branch, hf_gvcp_manufacturer_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_MODEL_NAME:
if (length == 32)
{
proto_tree_add_item(branch, hf_gvcp_model_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_DEVICE_VERSION:
if (length == 32)
{
proto_tree_add_item(branch, hf_gvcp_device_version, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_MANUFACTURER_INFO:
if (length == 48)
{
proto_tree_add_item(branch, hf_gvcp_manufacturer_specific_info, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_SERIAL_NUMBER:
if (length == 16)
{
proto_tree_add_item(branch, hf_gvcp_serial_number, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_USER_DEFINED_NAME:
if (length == 16)
{
proto_tree_add_item(branch, hf_gvcp_user_defined_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_FIRST_URL:
if (length == 512)
{
proto_tree_add_item(branch, hf_gvcp_first_xml_device_description_file, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case GVCP_SECOND_URL:
if (length == 512)
{
proto_tree_add_item(branch, hf_gvcp_second_xml_device_description_file, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
default:
return 0;
}
return 1;
}
static void dissect_forceip_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint startoffset, gint length)
{
const gint mac_offset = startoffset + 2;
const gint ip_offset = startoffset + 20;
const gint mask_offset = startoffset + 36;
const gint gateway_offset = startoffset + 52;
proto_item *item = NULL;
if (gvcp_telegram_tree != NULL)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "FORCEIP_CMD Options");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_forceip_mac_address, tvb, mac_offset, 6, ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_forceip_static_IP, tvb, ip_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_forceip_static_subnet_mask, tvb, mask_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_forceip_static_default_gateway, tvb, gateway_offset, 4, ENC_BIG_ENDIAN);
}
}
static void dissect_packetresend_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, int extendedblockid)
{
guint64 block_id = 0;
guint32 first_packet = 0;
guint32 last_packet = 0;
proto_item *item = NULL;
gint offset;
offset = startoffset;
if (extendedblockid == 0)
{
block_id = tvb_get_ntohs(tvb, offset + 2);
}
else
{
guint64 highid;
guint64 lowid;
highid = tvb_get_ntoh64(tvb, offset + 12);
lowid = tvb_get_ntoh64(tvb, offset + 16);
block_id = lowid | (highid << 32);
}
if (extendedblockid == 0)
{
first_packet = tvb_get_ntohl(tvb, offset + 4) & 0x00FFFFFF;
last_packet = tvb_get_ntohl(tvb, offset + 8) & 0x00FFFFFF;
}
else
{
first_packet = tvb_get_ntohl(tvb, offset + 4);
last_packet = tvb_get_ntohl(tvb, offset + 8);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "Block %" G_GINT64_MODIFIER "u, Packets %d->%d", (gint64)block_id, first_packet, last_packet);
if (gvcp_telegram_tree != NULL)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "PACKETRESEND_CMD Values");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_stream_channel_index, tvb, offset, 2, ENC_BIG_ENDIAN);
if (extendedblockid == 0)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_block_id, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_first_packet_id, tvb, offset + 5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_last_packet_id, tvb, offset + 9, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_extended_block_id_v2_0, tvb, offset + 12, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_extended_first_packet_id_v2_0, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_resendcmd_extended_last_packet_id_v2_0, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
}
}
}
static void dissect_readreg_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gvcp_transaction_t* gvcp_trans)
{
proto_item *item = NULL;
guint32 addr = 0;
const gchar* address_string = NULL;
gboolean is_custom_register = FALSE;
gint offset;
gint i;
gint num_registers;
offset = startoffset;
num_registers = length / 4;
addr = tvb_get_ntohl(tvb, offset);
address_string = get_register_name_from_address(addr, &is_custom_register);
if (num_registers > 1)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[Multiple Register Read Command]");
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", address_string);
}
if (!pinfo->fd->flags.visited)
{
gvcp_trans->addr_list = wmem_array_new(wmem_file_scope(), sizeof(guint32));
}
if (gvcp_telegram_tree != NULL)
{
if (num_registers > 1)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "READREG_CMD Address List");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
}
}
for (i = 0; i < num_registers; i++)
{
addr = tvb_get_ntohl(tvb, offset);
if (gvcp_trans && (!pinfo->fd->flags.visited))
{
wmem_array_append_one(gvcp_trans->addr_list, addr);
}
if (gvcp_telegram_tree != NULL)
{
if (try_val_to_str(addr, bootstrapregisternames) != NULL)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_readregcmd_bootstrap_register, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else
{
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_custom_register_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " ");
proto_item_append_text(item, "[Unknown Register]");
}
}
offset +=4;
}
}
static void dissect_writereg_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gvcp_transaction_t* gvcp_trans)
{
gint offset;
gint i;
proto_item *item = NULL;
guint32 addr = 0;
guint32 value = 0;
const gchar *address_string = NULL;
gboolean is_custom_register = FALSE;
gint num_registers;
proto_tree *subtree = NULL;
offset = startoffset;
num_registers = length / 8;
if (gvcp_trans)
{
gvcp_trans->addr_count = num_registers;
}
addr = tvb_get_ntohl(tvb, offset);
value = tvb_get_ntohl(tvb, offset+4);
address_string = get_register_name_from_address(addr, &is_custom_register);
if ((addr == GVCP_SC_DESTINATION_PORT(0)) ||
(addr == GVCP_SC_DESTINATION_PORT(1)) ||
(addr == GVCP_SC_DESTINATION_PORT(2)) ||
(addr == GVCP_SC_DESTINATION_PORT(3)))
{
dissector_handle_t gvsp_handle;
gvsp_handle = find_dissector("gvsp");
if (gvsp_handle != NULL)
{
dissector_add_uint("udp.port", value, gvsp_handle);
}
}
if (addr == GVCP_MC_DESTINATION_PORT)
{
dissector_handle_t gvcp_handle;
gvcp_handle = find_dissector("gvcp");
if (gvcp_handle != NULL)
{
dissector_add_uint("udp.port", value, gvcp_handle);
}
}
if (num_registers > 1)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[Multiple Register Write Command]");
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s Value=0x%08X", address_string, value);
}
if (gvcp_telegram_tree != NULL)
{
if (num_registers > 1)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "WRITEREG_CMD Address List");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
}
for (i = 0; i < num_registers; i++)
{
addr = tvb_get_ntohl(tvb, offset);
if (try_val_to_str(addr, bootstrapregisternames) != NULL)
{
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_writeregcmd_bootstrap_register, tvb, offset, 4, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gvcp_payload_cmd_subtree);
offset += 4;
dissect_register(addr, subtree, tvb, offset, 4);
}
else
{
proto_tree* temp_tree = NULL;
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_custom_register_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
temp_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd_subtree);
proto_tree_add_text(temp_tree,tvb, offset, 4, "Value=0x%08X", value);
}
offset += 4;
}
}
}
static void dissect_readmem_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset)
{
guint32 addr = 0;
guint16 count = 0;
gint offset;
offset = startoffset;
addr = tvb_get_ntohl(tvb, offset);
count = tvb_get_ntohs(tvb, offset + 6);
col_append_fstr(pinfo->cinfo, COL_INFO, " (0x%08X (%d) bytes)", addr, count);
if (gvcp_telegram_tree != NULL)
{
proto_item *item = NULL;
if (try_val_to_str(addr, bootstrapregisternames) != NULL)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_readmemcmd_bootstrap_register, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else
{
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_custom_memory_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " ");
proto_item_append_text(item, "[Unknown Register]");
}
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_readmemcmd_count, tvb, (offset + 6), 2, ENC_BIG_ENDIAN);
}
}
static void dissect_writemem_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gvcp_transaction_t* gvcp_trans)
{
const gchar* address_string = NULL;
gboolean is_custom_register = FALSE;
guint32 addr = 0;
addr = tvb_get_ntohl(tvb, startoffset);
address_string = get_register_name_from_address(addr, &is_custom_register);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s: %d bytes", address_string, (length - 4));
if (gvcp_trans && (!pinfo->fd->flags.visited))
{
gvcp_trans->addr_list = wmem_array_new(wmem_file_scope(), sizeof(guint32));
wmem_array_append_one(gvcp_trans->addr_list, addr);
}
if (gvcp_telegram_tree != NULL)
{
guint offset;
guint byte_count;
offset = startoffset + 4;
byte_count = (length - 4);
if (gvcp_trans && (gvcp_trans->rep_frame))
{
proto_item *item = NULL;
item = proto_tree_add_uint(gvcp_telegram_tree, hf_gvcp_response_in, tvb, 0, 0, gvcp_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(item);
}
if (try_val_to_str(addr, bootstrapregisternames) != NULL)
{
dissect_register_data(addr, gvcp_telegram_tree, tvb, offset, byte_count);
}
else
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_writememcmd_data, tvb, offset, byte_count, ENC_NA);
}
}
}
static void dissect_event_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gint extendedblockids)
{
gint32 eventid;
gint offset;
offset = startoffset;
eventid = tvb_get_ntohs(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "[ID: 0x%04X]", eventid);
if (gvcp_telegram_tree != NULL)
{
gint i;
gint event_count = 0;
proto_item *item = NULL;
if (extendedblockids == 0)
{
event_count = length / 16;
}
else
{
event_count = length / 24;
}
if (event_count > 1)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, offset, length, "EVENT_CMD Event List");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
}
for (i = 0; i < event_count; i++)
{
offset += 2;
eventid = tvb_get_ntohs(tvb, offset);
if ((eventid >= 0x0000) && (eventid <= 0x8000))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if ((eventid >= 0x8001) && (eventid <= 0x8FFF))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_error_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if ((eventid >= 0x9000) && (eventid <= 0xFFFF))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_device_specific_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_stream_channel_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (extendedblockids == 0)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_block_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
offset += 2;
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_block_id_64bit_v2_0, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_timestamp, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
}
}
static void dissect_eventdata_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint extendedblockids)
{
gint32 eventid;
gint offset;
offset = startoffset;
eventid = tvb_get_ntohs(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "[ID: 0x%04X]", eventid);
if (gvcp_telegram_tree != NULL)
{
offset += 2;
if ((eventid >= 0x0000) && (eventid <= 0x8000))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if ((eventid >= 0x8001) && (eventid <= 0x8FFF))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_error_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if ((eventid >= 0x9000) && (eventid <= 0xFFFF))
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_device_specific_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_stream_channel_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (extendedblockids == 0)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_block_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_block_id_64bit_v2_0, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_timestamp, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_eventcmd_data, tvb, offset, -1, ENC_NA);
}
}
static void dissect_action_cmd(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint startoffset, gint scheduledactioncommand)
{
if (gvcp_telegram_tree != NULL)
{
gint offset;
offset = startoffset;
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_actioncmd_device_key, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_actioncmd_group_key, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_actioncmd_group_mask, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
if (scheduledactioncommand != 0)
{
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_actioncmd_time_v2_0, tvb, offset + 12, 8, ENC_BIG_ENDIAN);
}
}
}
static void dissect_discovery_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length)
{
proto_item *item = NULL;
gint offset;
const guint8* string_manufacturer_name = NULL;
const guint8* string_serial_number = NULL;
gint string_length = 0;
proto_tree *tree = NULL;
offset = startoffset;
string_manufacturer_name = tvb_get_const_stringz(tvb, 80, &string_length);
string_serial_number = tvb_get_const_stringz(tvb, 224, &string_length);
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s, %s)",string_manufacturer_name, string_serial_number);
if (gvcp_telegram_tree != NULL)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, offset, length, "DISCOVERY_ACK Payload");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_spec_version, tvb, offset, 4, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_gvcp_bootstrap_fields);
dissect_register(GVCP_VERSION, tree, tvb, offset, 4 );
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_devicemodediscovery, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_gvcp_bootstrap_fields);
dissect_register(GVCP_DEVICE_MODE, tree, tvb, offset + 4, 4 );
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_device_mac_address, tvb, offset + 10, 6, ENC_NA);
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_supportedipconfig, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_gvcp_bootstrap_fields);
dissect_register(GVCP_SUPPORTED_IP_CONFIGURATION_0, tree, tvb, offset + 16, 4);
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_currentipconfig, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_gvcp_bootstrap_fields);
dissect_register(GVCP_CURIPCFG_0, tree, tvb, offset + 20, 4);
dissect_register(GVCP_CURRENT_IP_ADDRESS_0, gvcp_telegram_tree, tvb, offset + 36, 4);
dissect_register(GVCP_CURRENT_SUBNET_MASK_0, gvcp_telegram_tree, tvb, offset + 52, 4);
dissect_register(GVCP_CURRENT_DEFAULT_GATEWAY_0, gvcp_telegram_tree, tvb, offset + 68, 4);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_manufacturer_name, tvb, offset + 72, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_model_name, tvb, offset + 104, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_device_version, tvb, offset + 136, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_manufacturer_specific_info, tvb, offset + 168, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_serial_number, tvb, offset + 216, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_user_defined_name, tvb, offset + 232, -1, ENC_ASCII|ENC_NA);
}
}
static void dissect_readreg_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gvcp_transaction_t *gvcp_trans)
{
guint i;
proto_item *item = NULL;
gboolean is_custom_register = FALSE;
const gchar* address_string = NULL;
guint num_registers;
gint offset;
gboolean valid_trans = FALSE;
guint addr_list_size = 0;
offset = startoffset;
num_registers = length / 4;
if (gvcp_trans && gvcp_trans->addr_list)
{
valid_trans = TRUE;
addr_list_size = wmem_array_get_count(gvcp_trans->addr_list);
}
if (num_registers > 1)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[Multiple ReadReg Ack]");
}
else
{
if (valid_trans)
{
if (addr_list_size > 0)
{
address_string = get_register_name_from_address(*((guint32*)wmem_array_index(gvcp_trans->addr_list, 0)), &is_custom_register);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s Value=0x%08X", address_string, tvb_get_ntohl(tvb, offset));
}
}
if (gvcp_telegram_tree != NULL)
{
if (num_registers > 1)
{
item = proto_tree_add_text(gvcp_telegram_tree, tvb, offset, length, "Register Value List");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_ack);
}
for (i = 0; i < num_registers; i++)
{
guint32 curr_register = 0;
if (valid_trans && i < addr_list_size)
{
curr_register = *((guint32*)wmem_array_index(gvcp_trans->addr_list, i));
address_string = get_register_name_from_address(curr_register, &is_custom_register);
if (!is_custom_register)
{
proto_tree_add_uint(gvcp_telegram_tree, hf_gvcp_readregcmd_bootstrap_register, tvb, 0, 4, curr_register);
dissect_register(curr_register, gvcp_telegram_tree, tvb, offset, length);
}
else
{
proto_tree_add_text(gvcp_telegram_tree, tvb, offset, 4, "Custom Register Address: %s (0x%08X)", address_string, curr_register);
proto_tree_add_text(gvcp_telegram_tree, tvb, offset, 4, "Custom Register Value: 0x%08X", tvb_get_ntohl(tvb, offset));
}
}
else
{
proto_tree_add_text(gvcp_telegram_tree,tvb, offset, 4, "Value=0x%08X", tvb_get_ntohl(tvb, offset));
}
offset += 4;
}
}
}
static void dissect_writereg_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gvcp_transaction_t* gvcp_trans)
{
proto_item *item = NULL;
guint16 ack_index = 0;
if (gvcp_telegram_tree != NULL)
{
item = proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_writeregcmd_data_index, tvb, (startoffset + 2), 2, ENC_BIG_ENDIAN);
}
ack_index = tvb_get_ntohs(tvb, 10);
if (gvcp_trans)
{
gint num_registers = 0;
num_registers = gvcp_trans->addr_count;
if (num_registers > 1)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[Multiple WriteReg Ack] (%d/%d) %s ", ack_index, num_registers, (ack_index == num_registers ? "(Success)" : "(Failed)"));
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", (ack_index == num_registers ? "(Success)" : "(Failed)"));
}
if (gvcp_telegram_tree != NULL)
{
proto_item_append_text(item, " %s",(ack_index == num_registers ? "(Success)" : "(Failed)"));
}
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "[Cannot find requesting packet]");
}
}
static void dissect_readmem_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length)
{
guint32 addr = 0;
const gchar *address_string = NULL;
gboolean is_custom_register = FALSE;
addr = tvb_get_ntohl(tvb, startoffset);
address_string = get_register_name_from_address(addr, &is_custom_register);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", address_string);
if (gvcp_telegram_tree != NULL)
{
guint offset;
guint byte_count;
offset = startoffset + 4;
byte_count = (length - 4);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_readmemcmd_address, tvb, startoffset, 4, ENC_BIG_ENDIAN);
if (try_val_to_str(addr, bootstrapregisternames) != NULL)
{
dissect_register_data(addr, gvcp_telegram_tree, tvb, offset, byte_count);
}
else
{
proto_tree_add_text(gvcp_telegram_tree, tvb, offset, byte_count, "%d bytes of data read.", byte_count);
}
}
}
static void dissect_writemem_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo, gint startoffset, gint length, gvcp_transaction_t* gvcp_trans)
{
if (gvcp_trans && gvcp_trans->addr_list)
{
if (wmem_array_get_count(gvcp_trans->addr_list) > 0)
{
const gchar *address_string = NULL;
address_string = get_register_name_from_address((*((guint32*)wmem_array_index(gvcp_trans->addr_list, 0))), NULL);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", address_string);
}
}
if (gvcp_telegram_tree != NULL)
{
proto_item *item = NULL;
if (gvcp_trans && gvcp_trans->req_frame)
{
item = proto_tree_add_uint(gvcp_telegram_tree, hf_gvcp_response_to, tvb, 0, 0, gvcp_trans->req_frame);
PROTO_ITEM_SET_GENERATED(item);
}
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "Payload Data: WRITEMEM_ACK");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_writememcmd_data_index, tvb, (startoffset +2), 2, ENC_BIG_ENDIAN);
}
}
static void dissect_pending_ack(proto_tree *gvcp_telegram_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint startoffset, gint length)
{
if (gvcp_telegram_tree != NULL)
{
proto_item *item = NULL;
item = proto_tree_add_text(gvcp_telegram_tree, tvb, startoffset, length, "Payload Data: PENDING_ACK");
gvcp_telegram_tree = proto_item_add_subtree(item, ett_gvcp_payload_cmd);
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_time_to_completion, tvb, (startoffset + 2), 2, ENC_BIG_ENDIAN);
}
}
static int dissect_gvcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
proto_tree *gvcp_tree = NULL;
proto_tree *gvcp_tree_flag = NULL;
proto_tree *gvcp_telegram_tree = NULL;
gint data_length = 0;
gint command = -1;
const gchar* command_string = NULL;
gint status = 0;
gint flags = -1;
gint extendedblockids = -1;
gint scheduledactioncommand = -1;
gint ack_code = -1;
const gchar* ack_string = NULL;
gint request_id = 0;
gchar key_code = 0;
proto_item *ti = NULL;
proto_item *item = NULL;
conversation_t *conversation = 0;
gvcp_conv_info_t *gvcp_info = 0;
gvcp_transaction_t *gvcp_trans = 0;
if (tvb_captured_length(tvb) < GVCP_MIN_PACKET_SIZE)
{
return 0;
}
key_code = (gchar) tvb_get_guint8(tvb, offset);
ack_code = tvb_get_ntohs(tvb, offset+2);
ack_string = try_val_to_str(ack_code, acknowledgenames);
if ((key_code != 0x42) && !ack_string)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GVCP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_gvcp, tvb, offset, -1, ENC_NA);
gvcp_tree = proto_item_add_subtree(ti, ett_gvcp);
if (key_code == 0x42)
{
command = tvb_get_ntohs(tvb, offset+2);
command_string = val_to_str(command, commandnames,"Unknown Command (0x%x)");
col_append_fstr(pinfo->cinfo, COL_INFO, "> %s ", command_string);
item = proto_tree_add_text(gvcp_tree, tvb, offset, 8, "Command Header: %s", command_string);
gvcp_tree = proto_item_add_subtree(item, ett_gvcp_cmd);
proto_tree_add_item(gvcp_tree, hf_gvcp_message_key_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
flags = (gchar) tvb_get_guint8(tvb, offset + 1);
item = proto_tree_add_item(gvcp_tree, hf_gvcp_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
gvcp_tree_flag = proto_item_add_subtree(item, ett_gvcp_flags);
if (command == GVCP_ACTION_CMD)
{
proto_tree_add_item(gvcp_tree_flag, hf_gvcp_scheduledactioncommand_flag_v2_0, tvb, offset, 1, ENC_BIG_ENDIAN);
scheduledactioncommand = (flags & 0x80);
}
if ((command == GVCP_EVENTDATA_CMD) ||
(command == GVCP_EVENT_CMD) ||
(command == GVCP_PACKETRESEND_CMD))
{
proto_tree_add_item(gvcp_tree_flag, hf_gvcp_64bitid_flag_v2_0, tvb, offset, 1, ENC_BIG_ENDIAN);
extendedblockids = (flags & 0x10);
}
if ((command == GVCP_DISCOVERY_CMD) ||
(command == GVCP_FORCEIP_CMD))
{
proto_tree_add_item(gvcp_tree_flag, hf_gvcp_allow_broadcast_acknowledge_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(gvcp_tree_flag, hf_gvcp_acknowledge_required_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(gvcp_tree, hf_gvcp_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
status = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "< %s %s",
ack_string, val_to_str(status, statusnames_short, "Unknown status (0x%04X)"));
item = proto_tree_add_text(gvcp_tree, tvb, offset+2, tvb_captured_length(tvb)-2, "Acknowledge Header: %s", ack_string);
gvcp_tree = proto_item_add_subtree(item, ett_gvcp_ack);
proto_tree_add_item(gvcp_tree, hf_gvcp_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(gvcp_tree, hf_gvcp_acknowledge, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_tree_add_item(gvcp_tree, hf_gvcp_length, tvb, offset, 2, ENC_BIG_ENDIAN);
data_length = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(gvcp_tree, hf_gvcp_request_id, tvb, offset, 2, ENC_BIG_ENDIAN);
request_id = tvb_get_ntohs(tvb, offset);
offset += 2;
conversation = find_or_create_conversation(pinfo);
gvcp_info = (gvcp_conv_info_t*)conversation_get_proto_data(conversation, proto_gvcp);
if (!gvcp_info)
{
gvcp_info = (gvcp_conv_info_t*)wmem_alloc(wmem_file_scope(), sizeof(gvcp_conv_info_t));
gvcp_info->pdus = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_gvcp, gvcp_info);
}
if (!pinfo->fd->flags.visited)
{
if (key_code == 0x42)
{
gvcp_trans = (gvcp_transaction_t*)wmem_alloc(wmem_packet_scope(), sizeof(gvcp_transaction_t));
gvcp_trans->req_frame = pinfo->fd->num;
gvcp_trans->rep_frame = 0;
gvcp_trans->addr_list = 0;
gvcp_trans->addr_count = 0;
}
else
{
if (ack_string)
{
gvcp_trans_array = (wmem_array_t*)wmem_map_lookup(gvcp_info->pdus, GUINT_TO_POINTER(request_id));
if (gvcp_trans_array)
{
gint i;
guint array_size = wmem_array_get_count(gvcp_trans_array);
for (i = array_size-1; i >= 0; i--)
{
gvcp_trans = (gvcp_transaction_t*)wmem_array_index(gvcp_trans_array, i);
if (gvcp_trans && (gvcp_trans->req_frame < pinfo->fd->num))
{
if (gvcp_trans->rep_frame != 0)
{
gvcp_trans = 0;
}
else
{
gvcp_trans->rep_frame = pinfo->fd->num;
}
break;
}
gvcp_trans = 0;
}
}
}
}
}
else
{
gvcp_trans = 0;
gvcp_trans_array = (wmem_array_t*)wmem_map_lookup(gvcp_info->pdus, GUINT_TO_POINTER(request_id));
if (gvcp_trans_array)
{
guint i;
guint array_size = wmem_array_get_count(gvcp_trans_array);
for (i = 0; i < array_size; ++i)
{
gvcp_trans = (gvcp_transaction_t*)wmem_array_index(gvcp_trans_array, i);
if (gvcp_trans && (pinfo->fd->num == gvcp_trans->req_frame || pinfo->fd->num == gvcp_trans->rep_frame))
{
break;
}
gvcp_trans = 0;
}
}
}
if (!gvcp_trans)
{
gvcp_trans = wmem_new0(wmem_packet_scope(), gvcp_transaction_t);
}
gvcp_telegram_tree = proto_item_add_subtree(gvcp_tree, ett_gvcp);
if (key_code == 0x42)
{
if (gvcp_telegram_tree != NULL)
{
if (gvcp_trans->rep_frame)
{
item = proto_tree_add_uint(gvcp_telegram_tree, hf_gvcp_response_in, tvb, 0, 0, gvcp_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(item);
}
}
switch (command)
{
case GVCP_FORCEIP_CMD:
dissect_forceip_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length);
break;
case GVCP_PACKETRESEND_CMD:
dissect_packetresend_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length, extendedblockids);
break;
case GVCP_READREG_CMD:
dissect_readreg_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length, gvcp_trans);
break;
case GVCP_WRITEREG_CMD:
dissect_writereg_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length, gvcp_trans);
break;
case GVCP_READMEM_CMD:
dissect_readmem_cmd(gvcp_telegram_tree, tvb, pinfo, offset);
break;
case GVCP_WRITEMEM_CMD:
dissect_writemem_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length, gvcp_trans);
break;
case GVCP_EVENT_CMD:
dissect_event_cmd(gvcp_telegram_tree, tvb, pinfo, offset, data_length, extendedblockids);
break;
case GVCP_EVENTDATA_CMD:
dissect_eventdata_cmd(gvcp_telegram_tree, tvb, pinfo, offset, extendedblockids);
break;
case GVCP_ACTION_CMD:
dissect_action_cmd(gvcp_telegram_tree, tvb, pinfo, offset, scheduledactioncommand);
break;
case GVCP_DISCOVERY_CMD:
default:
break;
}
if (!pinfo->fd->flags.visited)
{
if (key_code == 0x42)
{
gvcp_trans_array = (wmem_array_t*)wmem_map_lookup(gvcp_info->pdus, GUINT_TO_POINTER(request_id));
if(gvcp_trans_array)
{
wmem_array_append(gvcp_trans_array, gvcp_trans, 1);
}
else
{
gvcp_trans_array = wmem_array_new(wmem_file_scope(), sizeof(gvcp_transaction_t));
wmem_array_append(gvcp_trans_array, gvcp_trans, 1);
wmem_map_insert(gvcp_info->pdus, GUINT_TO_POINTER(request_id), (void *)gvcp_trans_array);
}
}
}
}
else
{
if (gvcp_telegram_tree != NULL)
{
if (gvcp_trans->req_frame)
{
item = proto_tree_add_uint(gvcp_telegram_tree, hf_gvcp_response_to, tvb, 0, 0, gvcp_trans->req_frame);
PROTO_ITEM_SET_GENERATED(item);
}
}
switch (ack_code)
{
case GVCP_DISCOVERY_ACK:
dissect_discovery_ack(gvcp_telegram_tree, tvb, pinfo, offset, data_length);
break;
case GVCP_READREG_ACK:
dissect_readreg_ack(gvcp_telegram_tree, tvb, pinfo, offset, data_length, gvcp_trans);
break;
case GVCP_WRITEREG_ACK:
dissect_writereg_ack(gvcp_telegram_tree, tvb, pinfo, offset, gvcp_trans);
break;
case GVCP_READMEM_ACK:
dissect_readmem_ack(gvcp_telegram_tree, tvb, pinfo, offset, data_length);
break;
case GVCP_WRITEMEM_ACK:
dissect_writemem_ack(gvcp_telegram_tree, tvb, pinfo, offset, data_length, gvcp_trans);
break;
case GVCP_PENDING_ACK:
dissect_pending_ack(gvcp_telegram_tree, tvb, pinfo, offset, data_length);
break;
case GVCP_FORCEIP_ACK:
break;
case GVCP_PACKETRESEND_ACK:
case GVCP_EVENT_ACK:
case GVCP_EVENTDATA_ACK:
case GVCP_ACTION_ACK:
default:
proto_tree_add_item(gvcp_telegram_tree, hf_gvcp_payloaddata, tvb, offset, data_length, ENC_NA);
break;
}
}
return tvb_captured_length(tvb);
}
void proto_register_gvcp(void)
{
static hf_register_info hf[] =
{
{ &hf_gvcp_message_key_code,
{ "Message Key Code", "gvcp.message_key_code",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_flag,
{ "Flags", "gvcp.cmd.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_acknowledge_required_flag,
{ "Acknowledge Required", "gvcp.cmd.flag.acq_required",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gvcp_scheduledactioncommand_flag_v2_0,
{ "Scheduled Action Command", "gvcp.cmd.flag.scheduledactioncommand",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gvcp_64bitid_flag_v2_0,
{ "64 bit ID", "gvcp.cmd.flag.64bitid",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gvcp_allow_broadcast_acknowledge_flag,
{ "Allow Broadcast Acknowledge", "gvcp.cmd.flag.allowbroadcastacq",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gvcp_command,
{ "Command", "gvcp.cmd.command",
FT_UINT16, BASE_HEX, VALS(commandnames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_length,
{ "Payload Length", "gvcp.cmd.payloadlength",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_request_id,
{ "Request ID", "gvcp.cmd.req_id",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_payloaddata,
{ "Payload Data", "gvcp.cmd.payloaddata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_status,
{ "Status", "gvcp.cmd.status",
FT_UINT16, BASE_HEX, VALS(statusnames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_acknowledge,
{ "Acknowledge", "gvcp.ack",
FT_UINT16, BASE_HEX, VALS(acknowledgenames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_devicemodediscovery,
{ "Device Mode", "gvcp.ack.discovery.devicemode",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_forceip_mac_address,
{ "MAC Address", "gvcp.cmd.forceip.macaddress",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_forceip_static_IP,
{ "IP address", "gvcp.cmd.forceip.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_forceip_static_subnet_mask,
{ "Subnet Mask", "gvcp.cmd.forceip.subnetmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_forceip_static_default_gateway,
{ "Default Gateway", "gvcp.cmd.forceip.defaultgateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_device_mac_address,
{ "Device MAC Address", "gvcp.cmd.discovery.devicemacaddress",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_readregcmd_bootstrap_register,
{ "Bootstrap Register", "gvcp.cmd.readreg.bootstrapregister",
FT_UINT32, BASE_HEX_DEC, VALS(bootstrapregisternames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_writeregcmd_data,
{ "DataX", "gvcp.cmd.writereg.data",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_writeregcmd_bootstrap_register,
{ "Bootstrap Register", "gvcp.cmd.writereg.bootstrapregister",
FT_UINT32, BASE_HEX_DEC, VALS(bootstrapregisternames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_writeregcmd_data_index,
{ "Data Index", "gvcp.cmd.writereg.dataindex",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_readmemcmd_address,
{ "Register Address", "gvcp.cmd.readmem.address",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_readmemcmd_bootstrap_register,
{ "Memory Bootstrap Register", "gvcp.cmd.readmem.bootstrapregister",
FT_UINT32, BASE_HEX_DEC, VALS(bootstrapregisternames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_readmemcmd_count,
{ "Count", "gvcp.cmd.readmem.count",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_writememcmd_data,
{ "DataY", "gvcp.cmd.writemem.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_writememcmd_data_index,
{ "Data Index", "gvcp.cmd.writemem.dataindex",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_stream_channel_index,
{ "Resend Stream Channel Index", "gvcp.cmd.resend.streamchannelindex",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_block_id,
{ "Resend Block ID 16 bits", "gvcp.cmd.resend.blockid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_first_packet_id,
{ "Resend First Packet ID 24 bits", "gvcp.cmd.resend.firstpacketid",
FT_UINT24, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_last_packet_id,
{ "Resend Last Packet ID 24 bits", "gvcp.cmd.resend.lastpacketid",
FT_UINT24, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_extended_block_id_v2_0,
{ "Resend Block ID 64 bits", "gvcp.cmd.resend.extendedblockid",
FT_UINT64, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_extended_first_packet_id_v2_0,
{ "Resend First Packet ID 32 bits", "gvcp.cmd.resend.firstpacketid",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_resendcmd_extended_last_packet_id_v2_0,
{ "Resend Last Packet ID 32 bits", "gvcp.cmd.resend.lastpacketid",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_id,
{ "ID", "gvcp.cmd.event.id",
FT_UINT16, BASE_HEX_DEC, VALS(eventidnames), 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_error_id,
{ "Error ID", "gvcp.cmd.event.errorid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_device_specific_id,
{ "Device Specific ID", "gvcp.cmd.event.devicespecificid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_stream_channel_index,
{ "Stream Channel Index", "gvcp.cmd.event.streamchannelindex",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_block_id,
{ "Block ID (16 bit)", "gvcp.cmd.event.blockid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_timestamp,
{ "Timestamp", "gvcp.cmd.event.timestamp",
FT_UINT64, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_block_id_64bit_v2_0,
{ "Block ID 64 bit", "gvcp.event_timestamp",
FT_UINT64, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_eventcmd_data,
{ "Event Data", "gvcp.cmd.eventdata.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_actioncmd_device_key,
{ "Action Device Key", "gvcp.cmd.action.devicekey",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_actioncmd_group_key,
{ "Action Group Key", "gvcp.cmd.action.groupkey",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_actioncmd_group_mask,
{ "Action Group Mask", "gvcp.cmd.action.groupmask",
FT_UINT32, BASE_HEX_DEC, NULL, 0xFFFFFFFF,
NULL, HFILL }},
{ &hf_gvcp_actioncmd_time_v2_0,
{ "Action Scheduled Time", "gvcp.cmd.action.time",
FT_UINT64, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_time_to_completion,
{ "Time to completion", "gvcp.ack.pendingack.timetocompletion",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_spec_version_major,
{ "Version Major", "gvcp.bootstrap.specversion.major",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL }},
{ &hf_gvcp_spec_version_minor,
{ "Version Minor", "gvcp.bootstrap.specversion.minor",
FT_UINT32, BASE_HEX, NULL, 0x0000FFFF,
NULL, HFILL }},
{ &hf_gvcp_spec_version,
{ "Spec Version", "gvcp.bootstrap.specversion",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_gvcp_devicemode_endianess,
{ "Endianess", "gvcp.bootstrap.devicemode.endianess",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{ &hf_gvcp_devicemode_deviceclass,
{ "Device Class", "gvcp.bootstrap.devicemode.deviceclass",
FT_UINT32, BASE_HEX, VALS(devicemodenames_class), 0x70000000,
NULL, HFILL
}},
{& hf_gvcp_devicemode_characterset,
{ "Character Set", "gvcp.bootstrap.devicemode.characterset",
FT_UINT32, BASE_HEX, VALS(devicemodenames_characterset), 0x0000000F,
NULL, HFILL
}},
{ &hf_gvcp_machigh,
{ "MAC High", "gvcp.bootstrap.machigh",
FT_UINT32, BASE_HEX, NULL, 0x0000FFFF,
NULL, HFILL
}},
{ &hf_gvcp_maclow,
{ "MAC Low", "gvcp.bootstrap.maclow",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{ &hf_gvcp_ip_config_can_handle_pause_frames_v2_0,
{ "IP Config Can Handle Pause Frames", "gvcp.bootstrap.ipconfig.canhandlepauseframes",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL }},
{ &hf_gvcp_ip_config_can_generate_pause_frames_v2_0,
{ "Can Generate Pause Frames", "gvcp.bootstrap.ipconfig.cangeneratepauseframes",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL }},
{ &hf_gvcp_ip_config_lla,
{ "LLA", "gvcp.bootstrap.ipconfig.lla",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL }},
{ &hf_gvcp_ip_config_dhcp,
{ "DHCP", "gvcp.bootstrap.ipconfig.dhcp",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL }},
{ &hf_gvcp_ip_config_persistent_ip,
{ "Persistent IP", "gvcp.bootstrap.ipconfig.persistentip",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }},
{ &hf_gvcp_supportedipconfig,
{ "Supported IP Configuration", "gvcp.bootstrap.supportedipconfig",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{ &hf_gvcp_currentipconfig,
{ "Current IP Configuration", "gvcp.bootstrap.currentipconfig",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{ &hf_gvcp_current_IP,
{ "Current IP", "gvcp.bootstrap.currentip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_current_subnet_mask,
{ "Subnet Mask", "gvcp.bootstrap.currentsubnetmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_current_default_gateway,
{ "Default Gateway", "gvcp.bootstrap.currentdefaultgateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_manufacturer_name,
{ "Manufacturer Name", "gvcp.bootstrap.manufacturername",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_model_name,
{ "Model Name", "gvcp.bootstrap.modelname",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_device_version,
{ "Device Version", "gvcp.bootstrap.deviceversion",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_manufacturer_specific_info,
{ "Manufacturer Specific Info", "gvcp.bootstrap.manufacturerspecificinfo",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_serial_number,
{ "Serial Number", "gvcp.bootstrap.serialnumber",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_user_defined_name,
{ "User-defined Name", "gvcp.bootstrap.userdefinedname",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_first_xml_device_description_file,
{ "First URL", "gvcp.bootstrap.firsturl",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gvcp_second_xml_device_description_file,
{ "Second URL", "gvcp.bootstrap.secondurl",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{& hf_gvcp_number_interfaces,
{ "Number of Network Interfaces", "gvcp.bootstrap.numberofnetworminterfaces",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_persistent_ip,
{ "Persistent IP", "gvcp.bootstrap.persistentip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_persistent_subnet,
{ "Persistent Subnet Mask", "gvcp.bootstrap.persistentsubnetmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_persistent_gateway,
{ "Persistent GateWay", "gvcp.bootstrap.persistentgateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_link_speed,
{ "Link Speed (in Mbs)", "gvcp.bootstrap.linkspeed",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_number_message_channels,
{ "Number of Message Channels", "gvcp.bootstrap.numberofmessagechannels",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_number_stream_channels,
{ "Number of Stream Channels", "gvcp.bootstrap.numberofstreamchannels",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_number_action_signals,
{ "Number of Action Signals", "gvcp.bootstrap.numberofactionsignals",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_number_of_active_links_v2_0,
{ "Number of Active Links", "gvcp.bootstrap.numberofactivelinks",
FT_UINT32, BASE_DEC, NULL, 0x0000000F,
NULL, HFILL
}},
{& hf_gvcp_sccaps_scspx_register_supported,
{ "SCSPx Register Supporteed", "gvcp.bootstrap.sccaps.scspxregistersupported",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_sccaps_legacy_16bit_blockid_supported_v2_0,
{ "16 bit Block ID Supported", "gvcp.bootstrap.sccaps.16bitblockidsupported",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_mcsp_supported,
{ "MCSP Supported", "gvcp.bootstrap.mccaps.mcspsupported",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_capability_user_defined,
{ "User Defined Name Supported", "gvcp.bootstrap.capability.userdefined",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_capability_serial_number,
{ "Serial Number Supported", "gvcp.bootstrap.capability.serialnumber",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_capability_heartbeat_disable,
{ "Heartbeat Disable Supported", "gvcp.bootstrap.capability.heartbeatdisabled",
FT_BOOLEAN, 32, NULL, 0x20000000,
NULL, HFILL
}},
{& hf_gvcp_capability_link_speed,
{ "Link Speed Supported", "gvcp.bootstrap.capability.linkspeed",
FT_BOOLEAN, 32, NULL, 0x10000000,
NULL, HFILL
}},
{& hf_gvcp_capability_ccp_application_portip,
{ "CCP Application Port/IP Supported", "gvcp.bootstrap.capability.ccpapplicationportip",
FT_BOOLEAN, 32, NULL, 0x08000000,
NULL, HFILL
}},
{& hf_gvcp_capability_manifest_table,
{ "Manifest Table Supported", "gvcp.bootstrap.capability.manifesttable",
FT_BOOLEAN, 32, NULL, 0x04000000,
NULL, HFILL
}},
{& hf_gvcp_capability_test_data,
{ "Test Data Supported", "gvcp.bootstrap.capability.testdata",
FT_BOOLEAN, 32, NULL, 0x02000000,
NULL, HFILL
}},
{& hf_gvcp_capability_discovery_ACK_delay,
{ "Discovery ACK Delay Supported", "gvcp.bootstrap.capability.discoveryackdelay",
FT_BOOLEAN, 32, NULL, 0x01000000,
NULL, HFILL
}},
{& hf_gvcp_capability_writable_discovery_ACK_delay,
{ "Writable Discovery ACK Delay Supported", "gvcp.bootstrap.capability.writablediscoveryackdelay",
FT_BOOLEAN, 32, NULL, 0x00800000,
NULL, HFILL
}},
{& hf_gvcp_capability_extended_status_code_v1_1,
{ "Extended Status Code Supported (v1.1)", "gvcp.bootstrap.capability.extendedstatuscodesupportedv1_1",
FT_BOOLEAN, 32, NULL, 0x00400000,
NULL, HFILL
}},
{& hf_gvcp_capability_primary_application_switchover,
{ "Primary Application Switchover Supported", "gvcp.bootstrap.capability.primaryapplicationswitchover",
FT_BOOLEAN, 32, NULL, 0x00200000,
NULL, HFILL
}},
{& hf_gvcp_capability_unconditional_action_command,
{ "Unconditional Action Command Supported", "gvcp.bootstrap.capability.unconditionalactioncommand",
FT_BOOLEAN, 32, NULL, 0x00100000,
NULL, HFILL
}},
{& hf_gvcp_capability_1588_v2_0,
{ "Capability 1588", "gvcp.bootstrap.capability.ieee1588",
FT_BOOLEAN, 32, NULL, 0x00080000,
NULL, HFILL
}},
{& hf_gvcp_capability_extended_status_code_v2_0,
{ "Status Code", "gvcp.bootstrap.capability.pendingextendedstatuscodev2_0",
FT_BOOLEAN, 32, NULL, 0x00040000,
NULL, HFILL
}},
{& hf_gvcp_capability_scheduled_action_command_v2_0,
{ "Scheduled Action Command", "gvcp.bootstrap.capability.scheduledactioncommand",
FT_BOOLEAN, 32, NULL, 0x00020000,
NULL, HFILL
}},
{& hf_gvcp_capability_action_command,
{ "Action Command", "gvcp.bootstrap.capability.actioncommand",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL
}},
{& hf_gvcp_capability_pending,
{ "Pending ACK Supported", "gvcp.bootstrap.capability.pendingack",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL
}},
{& hf_gvcp_capability_evendata,
{ "Eventdata Supported", "gvcp.bootstrap.capability.eventdata",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL
}},
{& hf_gvcp_capability_event,
{ "Event Signal Supported", "gvcp.bootstrap.capability.eventsignal",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL
}},
{& hf_gvcp_capability_packetresend,
{ "Packet Resend CMD Supported", "gvcp.bootstrap.capability.packetresendcmd",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL
}},
{& hf_gvcp_capability_writemem,
{ "WRITEMEM Supported", "gvcp.bootstrap.capability.writemem",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_capability_concatenation,
{ "Concatenation Supported", "gvcp.bootstrap.capability.concatenation",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_heartbeat,
{ "Heartbeat Timeout (in ms)", "gvcp.bootstrap.heartbeattimeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_high_timestamp_frequency,
{ "Timestamp Tick High Frequency (in Hz)", "gvcp.bootstrap.timestamptickfrequencyhigh",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_low_timestamp_frequency,
{ "Timestamp Tick Low Frequency (in Hz)", "gvcp.bootstrap.timestamptickfrequencylow",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_timestamp_control_latch,
{ "Timestamp Control Latch", "gvcp.bootstrap.timestampcontrol.latch",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_timestamp_control_reset,
{ "Timestamp Control Reset", "gvcp.bootstrap.timestampcontrol.reset",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_high_timestamp_value,
{ "Timestamp Value High", "gvcp.bootstrap.timestampvaluehigh",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_low_timestamp_value,
{ "Timestamp Value Low", "gvcp.bootstrap.timestampvaluelow",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_discovery_ACK_delay,
{ "Discovery ACK Delay (in ms)", "gvcp.bootstrap.discoveryackdelay",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_configuration_1588_enable_v2_0,
{ "IEEE 1588 Enable", "gvcp.bootstrap.config.ieee1588enable",
FT_BOOLEAN, 32, NULL, 0x00080000,
NULL, HFILL
}},
{& hf_gvcp_configuration_extended_status_codes_enable_v2_0,
{ "Status Codes v2.0 Enable", "gvcp.bootstrap.config.statuscodesv2_0enable",
FT_BOOLEAN, 32, NULL, 0x00040000,
NULL, HFILL
}},
{& hf_gvcp_configuration_unconditional_action_command_enable_v2_0,
{ "Unconditional Action Command Enable", "gvcp.bootstrap.config.unconditionalactioncommandenable",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL
}},
{& hf_gvcp_configuration_extended_status_codes_enable_v1_1,
{ "Status Codes v1.1 Enable", "gvcp.bootstrap.config.statuscodesv1_1enable",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL
}},
{& hf_gvcp_configuration_pending_ack_enable,
{ "Pending_ACK Enable", "gvcp.bootstrap.config.pendingackenable",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_configuration_heartbeat_disable,
{ "Heartbeat Disable", "gvcp.bootstrap.config.heartbeatdisable",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_pending_timeout_max_execution,
{ "Pending Timeout (in ms)", "gvcp.bootstrap.pending.timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_control_switchover_key_register,
{ "Control Switchover Key", "gvcp.bootstrap.controlswitchoverkey",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_gvsp_configuration_64bit_blockid_enable_v2_0,
{ "GVSP Configuration 64 bit Block ID", "gvcp.bootstrap.gvcspconfig.64bitblockidenable",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_link_dlag_v2_0,
{ "Link dLAG", "gvcp.bootstrap.link.dlag",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL
}},
{& hf_gvcp_link_slag_v2_0,
{ "Link sLAG", "gvcp.bootstrap.link.slag",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL
}},
{& hf_gvcp_link_ml_v2_0,
{ "Link ML", "gvcp.bootstrap.link.ml",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_link_sl_v2_0,
{ "Link SL", "gvcp.bootstrap.link.sl",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_ieee1588_clock_status_v2_0,
{ "IEEE 1588 Clock Status", "gvcp.bootstrap.ieee1588.clockstatus",
FT_UINT32, BASE_HEX, NULL, 0x0000000F,
NULL, HFILL
}},
{& hf_gvcp_scheduled_action_command_queue_size_v2_0,
{ "Scheduled Action Command Queue Size", "gvcp.bootstrap.scheduledactioncommandqueuesize",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL
}},
{& hf_gvcp_control_switchover_key,
{ "Control Switchover Key", "gvcp.bootstrap.control.switchoverkey",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL
}},
{& hf_gvcp_control_switchover_en,
{ "Control Switchover Enable", "gvcp.bootstrap.control.switchoverenable",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL
}},
{& hf_gvcp_control_access,
{ "Control Access", "gvcp.bootstrap.control.controlaccess",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_exclusive_access,
{ "Exclusive Access", "gvcp.bootstrap.control.exclusiveaccess",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_primary_application_host_port,
{ "Primary Application Port", "gvcp.bootstrap.primaryapplicationport",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_primary_application_ip_address,
{ "Primary Application IP Address", "gvcp.bootstrap.primaryapplicationipaddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_network_interface_index,
{ "Network Interface Index", "gvcp.bootstrap.mcp.networkinterfaceindex",
FT_UINT32, BASE_DEC, NULL, 0x000F0000,
NULL, HFILL
}},
{& hf_gvcp_host_port,
{ "Host Port", "gvcp.bootstrap.mcp.hostport",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_channel_destination_ip,
{ "Destination IP Address", "gvcp.bootstrap.mcda",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_message_channel_transmission_timeout,
{ "Transmission Timeout (in ms)", "gvcp.bootstrap.mctt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_message_channel_retry_count,
{ "Retry Count", "gvcp.bootstrap.mcrc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_message_channel_source_port,
{ "Source Port", "gvcp.bootstrap.mcsp",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_sc_direction,
{ "Direction", "gvcp.bootstrap.scpx.direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_sc_ni_index,
{ "Network Interface Index", "gvcp.bootstrap.scpx.networkinterfaceindex",
FT_UINT32, BASE_DEC, NULL, 0x000F0000,
NULL, HFILL
}},
{& hf_gvcp_sc_host_port,
{ "Host Port", "gvcp.bootstrap.scpx.hostport",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_sc_fire_test_packet,
{ "Fire Test Packet", "gvcp.bootstrap.scpsx.firetestpacket",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_sc_do_not_fragment,
{ "Do Not Fragment", "gvcp.bootstrap.scpsx.donotfragment",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_sc_pixel_endianness,
{ "Pixel Endianness", "gvcp.bootstrap.scpsx.pixelendianness",
FT_BOOLEAN, 32, NULL, 0x20000000,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_size,
{ "Packet Size", "gvcp.bootstrap.scpsx.packetsize",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_delay,
{ "Packet Delay", "gvcp.bootstrap.scpdx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_sc_destination_ip,
{ "Destination Address", "gvcp.bootstrap.scdax",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_sc_source_port,
{ "Source Port", "gvcp.bootstrap.scspx",
FT_UINT32, BASE_DEC, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvcp_sc_big_little_endian_supported,
{ "Big/Little Endian Supported", "gvcp.bootstrap.sccx.biglittleendiansupported",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_sc_ip_reassembly_supported,
{ "IP Reassembly Supported", "gvcp.bootstrap.sccx.ipreassemblysupported",
FT_BOOLEAN, 32, NULL, 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_sc_multizone_supported_v2_0,
{ "Multizone Supported", "gvcp.bootstrap.sccx.multizonesupported",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_resend_destination_option_supported_v2_0,
{ "Resend Destination Option Supported", "gvcp.bootstrap.sccx.resenddestinationoptionsupported",
FT_BOOLEAN, 32, NULL, 0x8,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_resend_all_in_transmission_supported_v2_0,
{ "All In Transmission Supported", "gvcp.bootstrap.sccx.allintransmissionsupported",
FT_BOOLEAN, 32, NULL, 0x4,
NULL, HFILL
}},
{& hf_gvcp_sc_unconditional_streaming_supported,
{ "Unconditional Streaming Supported", "gvcp.bootstrap.sccx.unconditionalstreamingsupported",
FT_BOOLEAN, 32, NULL, 0x2,
NULL, HFILL
}},
{& hf_gvcp_sc_extended_chunk_data_supported,
{ "Extended Chunk Data Supported", "gvcp.bootstrap.sccx.extendedchunkdatasupported",
FT_BOOLEAN, 32, NULL, 0x1,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_resend_destination_option_enabled_v2_0,
{ "Resend Destination Option Enabled", "gvcp.bootstrap.sccfgx.resenddestinationoptionenabled",
FT_BOOLEAN, 32, NULL, 0x8,
NULL, HFILL
}},
{& hf_gvcp_sc_packet_resend_all_in_transmission_enabled_v2_0,
{ "All In Transmission Enabled", "gvcp.bootstrap.sccfgx.allintransmissionenabled",
FT_BOOLEAN, 32, NULL, 0x4,
NULL, HFILL
}},
{& hf_gvcp_sc_unconditional_streaming_enabled,
{ "Unconditional Streaming Enabled", "gvcp.bootstrap.sccfgx.unconditionalstreamingenabled",
FT_BOOLEAN, 32, NULL, 0x2,
NULL, HFILL
}},
{& hf_gvcp_sc_extended_chunk_data_enabled,
{ "Extended Chunk Data Enabled", "gvcp.bootstrap.sccfgx.extendedchunkdataenabled",
FT_BOOLEAN, 32, NULL, 0x1,
NULL, HFILL
}},
{& hf_gvcp_sc_additional_zones_v2_0,
{ "Additional Zones", "gvcp.bootstrap.sczx.additionalzones",
FT_UINT32, BASE_DEC, NULL, 0x0000000F,
NULL, HFILL
}},
{& hf_gvcp_sc_zone0_direction_v2_0,
{ "Zone 0 Direction", "gvcp.bootstrap.sczdx.zone0direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x80000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone1_direction_v2_0,
{ "Zone 1 Direction", "gvcp.bootstrap.sczdx.zone1direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x40000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone2_direction_v2_0,
{ "Zone 2 Direction", "gvcp.bootstrap.sczdx.zone2direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x20000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone3_direction_v2_0,
{ "Zone 3 Direction", "gvcp.bootstrap.sczdx.zone3direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x10000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone4_direction_v2_0,
{ "Zone 4 Direction", "gvcp.bootstrap.sczdx.zone4direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x08000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone5_direction_v2_0,
{ "Zone 5 Direction", "gvcp.bootstrap.sczdx.zone5direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x04000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone6_direction_v2_0,
{ "Zone 6 Direction", "gvcp.bootstrap.sczdx.zone6direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x02000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone7_direction_v2_0,
{ "Zone 7 Direction", "gvcp.bootstrap.sczdx.zone7direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x01000000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone8_direction_v2_0,
{ "Zone 8 Direction", "gvcp.bootstrap.sczdx.zone8direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00800000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone9_direction_v2_0,
{ "Zone 9 Direction", "gvcp.bootstrap.sczdx.zone9direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00400000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone10_direction_v2_0,
{ "Zone 10 Direction", "gvcp.bootstrap.sczdx.zone10direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00200000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone11_direction_v2_0,
{ "Zone 11 Direction", "gvcp.bootstrap.sczdx.zone1direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00100000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone12_direction_v2_0,
{ "Zone 12 Direction", "gvcp.bootstrap.sczdx.zone12direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00080000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone13_direction_v2_0,
{ "Zone 13 Direction", "gvcp.bootstrap.sczdx.zone13direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00040000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone14_direction_v2_0,
{ "Zone 14 Direction", "gvcp.bootstrap.sczdx.zone14direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00020000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone15_direction_v2_0,
{ "Zone 15 Direction", "gvcp.bootstrap.sczdx.zone15direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00010000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone16_direction_v2_0,
{ "Zone 16 Direction", "gvcp.bootstrap.sczdx.zone16direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00008000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone17_direction_v2_0,
{ "Zone 17 Direction", "gvcp.bootstrap.sczdx.zone17direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00004000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone18_direction_v2_0,
{ "Zone 18 Direction", "gvcp.bootstrap.sczdx.zone18direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00002000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone19_direction_v2_0,
{ "Zone 19 Direction", "gvcp.bootstrap.sczdx.zone19direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00001000,
NULL, HFILL
}},
{& hf_gvcp_sc_zone20_direction_v2_0,
{ "Zone 20 Direction", "gvcp.bootstrap.sczdx.zone20direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000800,
NULL, HFILL
}},
{& hf_gvcp_sc_zone21_direction_v2_0,
{ "Zone 21 Direction", "gvcp.bootstrap.sczdx.zone21direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000400,
NULL, HFILL
}},
{& hf_gvcp_sc_zone22_direction_v2_0,
{ "Zone 22 Direction", "gvcp.bootstrap.sczdx.zone22direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000200,
NULL, HFILL
}},
{& hf_gvcp_sc_zone23_direction_v2_0,
{ "Zone 23 Direction", "gvcp.bootstrap.sczdx.zone23direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000100,
NULL, HFILL
}},
{& hf_gvcp_sc_zone24_direction_v2_0,
{ "Zone 24 Direction", "gvcp.bootstrap.sczdx.zone24direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000080,
NULL, HFILL
}},
{& hf_gvcp_sc_zone25_direction_v2_0,
{ "Zone 25 Direction", "gvcp.bootstrap.sczdx.zone25direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000040,
NULL, HFILL
}},
{& hf_gvcp_sc_zone26_direction_v2_0,
{ "Zone 26 Direction", "gvcp.bootstrap.sczdx.zone26direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000020,
NULL, HFILL
}},
{& hf_gvcp_sc_zone27_direction_v2_0,
{ "Zone 27 Direction", "gvcp.bootstrap.sczdx.zone27direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000010,
NULL, HFILL
}},
{& hf_gvcp_sc_zone28_direction_v2_0,
{ "Zone 28 Direction", "gvcp.bootstrap.sczdx.zone28direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000008,
NULL, HFILL
}},
{& hf_gvcp_sc_zone29_direction_v2_0,
{ "Zone 29 Direction", "gvcp.bootstrap.sczdx.zone29direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000004,
NULL, HFILL
}},
{& hf_gvcp_sc_zone30_direction_v2_0,
{ "Zone 30 Direction", "gvcp.bootstrap.sczdx.zone30direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000002,
NULL, HFILL
}},
{& hf_gvcp_sc_zone31_direction_v2_0,
{ "Zone 31 Direction", "gvcp.bootstrap.sczdx.zone31direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000001,
NULL, HFILL
}},
{& hf_gvcp_action_group_key,
{ "Action Group Key", "gvcp.bootstrap.actiongroupkey",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_action_group_mask,
{ "Action Group Mask", "gvcp.bootstrap.actiongroupmask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_custom_register_addr,
{ "Custom Register Address", "gvcp.bootstrap.custom.register.write",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_custom_memory_addr,
{ "Custom Memory Address", "gvcp.bootstrap.custom.register.write",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvcp_response_in,
{ "Response In", "gvcp.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this GVCP request is in this frame", HFILL
}},
{& hf_gvcp_response_to,
{ "Request In", "gvcp.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the GVCP request in this frame", HFILL
}}
};
static gint *ett[] = {
&ett_gvcp,
&ett_gvcp_cmd,
&ett_gvcp_flags,
&ett_gvcp_ack,
&ett_gvcp_payload_cmd,
&ett_gvcp_payload_ack,
&ett_gvcp_payload_ack_subtree,
&ett_gvcp_payload_cmd_subtree,
&ett_gvcp_bootstrap_fields
};
proto_gvcp = proto_register_protocol("GigE Vision Control Protocol", "GVCP", "gvcp");
new_register_dissector("gvcp", dissect_gvcp, proto_gvcp);
proto_register_field_array(proto_gvcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_gvcp(void)
{
static dissector_handle_t gvcp_handle;
gvcp_handle = new_create_dissector_handle((new_dissector_t)dissect_gvcp, proto_gvcp);
dissector_add_uint("udp.port", global_gvcp_port, gvcp_handle);
}
