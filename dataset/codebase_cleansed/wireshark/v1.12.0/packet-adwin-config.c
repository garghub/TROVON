static void
dissect_UDPStatus(tvbuff_t *tvb, proto_tree *adwin_tree)
{
proto_tree *status_tree;
proto_tree *debug_tree;
proto_item *st, *dt;
if (! adwin_tree)
return;
dt = proto_tree_add_item(adwin_tree, proto_adwin_config, tvb, 0, -1, ENC_NA);
debug_tree = proto_item_add_subtree(dt, ett_adwin_config_debug);
proto_item_set_text(dt, "ADwin Debug information");
proto_tree_add_item(adwin_tree, hf_adwin_config_pattern, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_version, tvb, 4, 4, ENC_BIG_ENDIAN);
st = proto_tree_add_item(adwin_tree, hf_adwin_config_status, tvb, 8, 4, ENC_BIG_ENDIAN);
status_tree = proto_item_add_subtree(st, ett_adwin_config_status);
proto_tree_add_item(status_tree, hf_adwin_config_status_bootloader, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_reprogrammable, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_configurable, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_bootloader_boots, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_bootloader_reprogrammable, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_bootloader_receive, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_bootloader_reprogramming_done, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(status_tree, hf_adwin_config_status_eeprom_support, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_server_version_beta, tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_server_version, tvb, 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_xilinx_version, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 20, 6, ENC_NA);
proto_tree_add_item(debug_tree, hf_adwin_config_unused, tvb, 26, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_port16, tvb, 28, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_dhcp, tvb, 30, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_netmask_count, tvb, 31, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_gateway, tvb, 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(debug_tree, hf_adwin_config_unused, tvb, 36, 11, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_reply_broadcast, tvb, 47, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_scan_id, tvb, 48, 4, ENC_LITTLE_ENDIAN);
}
static void
dissect_UDPExtStatus(tvbuff_t *tvb, proto_tree *adwin_tree)
{
const gchar *processor_type, *system_type;
if (! adwin_tree)
return;
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 0, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 6, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_pattern, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_version, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_description, tvb, 16, 16, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_timerresets, tvb, 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_socketshutdowns, tvb, 36, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_disk_free, tvb, 40, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_disk_size, tvb, 44, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_date, tvb, 48, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_revision, tvb, 56, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_processor_type, tvb, 64, 2, ENC_ASCII|ENC_NA);
processor_type = tvb_get_string_enc(wmem_packet_scope(), tvb, 64, 2, ENC_ASCII|ENC_NA);
processor_type = str_to_str(processor_type, processor_type_mapping, "Unknown (%s)");
proto_tree_add_text(adwin_tree, tvb, 64, 2, "Processor Type: %s", processor_type);
proto_tree_add_item(adwin_tree, hf_adwin_config_system_type, tvb, 66, 2, ENC_ASCII|ENC_NA);
system_type = tvb_get_string_enc(wmem_packet_scope(), tvb, 66, 2, ENC_ASCII|ENC_NA);
system_type = str_to_str(system_type, system_type_mapping, "Unknown (%s)");
proto_tree_add_text(adwin_tree, tvb, 66, 2, "System Type: %s", system_type);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 68, 364, ENC_NA);
}
static void
dissect_UDPMessage(tvbuff_t *tvb, proto_tree *adwin_tree)
{
const gchar *processor_type, *system_type;
if (! adwin_tree)
return;
proto_tree_add_item(adwin_tree, hf_adwin_config_command, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_version, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 8, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 14, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_server_ip, tvb, 16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 20, 4, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_netmask, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 28, 4, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_gateway, tvb, 32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 36, 4, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_dhcp, tvb, 40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_port32, tvb, 44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_password, tvb, 48, 10, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_bootloader, tvb, 58, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 59, 5, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_description, tvb, 64, 16, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_date, tvb, 80, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_revision, tvb, 88, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_processor_type, tvb, 96, 2, ENC_ASCII|ENC_NA);
processor_type = tvb_get_string_enc(wmem_packet_scope(), tvb, 96, 2, ENC_ASCII|ENC_NA);
processor_type = str_to_str(processor_type, processor_type_mapping, "Unknown");
proto_tree_add_text(adwin_tree, tvb, 96, 2, "Processor Type: %s", processor_type);
proto_tree_add_item(adwin_tree, hf_adwin_config_system_type, tvb, 98, 2, ENC_ASCII|ENC_NA);
system_type = tvb_get_string_enc(wmem_packet_scope(), tvb, 98, 2, ENC_ASCII|ENC_NA);
system_type = str_to_str(system_type, system_type_mapping, "Unknown");
proto_tree_add_text(adwin_tree, tvb, 98, 2, "System Type: %s", system_type);
}
static void
dissect_UDPInitAck(tvbuff_t *tvb, proto_tree *adwin_tree)
{
if (! adwin_tree)
return;
proto_tree_add_item(adwin_tree, hf_adwin_config_pattern, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_reboot, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 8, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 14, 2, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 16, 80, ENC_NA);
}
static void
dissect_UDPIXP425FlashUpdate(tvbuff_t *tvb, proto_tree *adwin_tree)
{
if (! adwin_tree)
return;
proto_tree_add_item(adwin_tree, hf_adwin_config_pattern, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_version, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_scan_id, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_status, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_timeout, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_filename, tvb, 20, 24, ENC_ASCII|ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 44, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, 50, 42, ENC_NA);
}
static void
dissect_UDPOut(tvbuff_t *tvb, proto_tree *adwin_tree)
{
if (! adwin_tree)
return;
proto_tree_add_item(adwin_tree, hf_adwin_config_status, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_mac, tvb, 4, 6, ENC_NA);
proto_tree_add_item(adwin_tree, hf_adwin_config_netmask, tvb, 10, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_gateway, tvb, 14, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_dhcp, tvb, 18, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(adwin_tree, hf_adwin_config_port16, tvb, 20, 2, ENC_BIG_ENDIAN);
}
static guint
get_adwin_TCPUpdate_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset);
}
static int
dissect_TCPFlashUpdate(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_tree *adwin_tree;
proto_item *ti;
gint length, offset;
guint8 *filename;
nstime_t tmp_time;
tmp_time.nsecs = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ADwin Config");
col_set_str(pinfo->cinfo, COL_INFO, "TCPFlashUpdate");
ti = proto_tree_add_item(tree, proto_adwin_config, tvb, 0, -1, ENC_NA);
adwin_tree = proto_item_add_subtree(ti, ett_adwin_config);
proto_tree_add_item(adwin_tree, hf_adwin_config_stream_length, tvb, 0, 4, ENC_BIG_ENDIAN);
offset = 4;
length = tvb_strnlen(tvb, offset, -1) + 1;
filename = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII|ENC_NA);
if (strncmp(filename, "eeprom_on", length) == 0) {
proto_tree_add_text(adwin_tree, tvb, offset, length,
"Enable EEPROM Support");
return offset+length;
}
if (strncmp(filename, "eeprom_off", length) == 0) {
proto_tree_add_text(adwin_tree, tvb, offset, length,
"Disable EEPROM Support");
return offset+length;
}
proto_tree_add_item(adwin_tree, hf_adwin_config_filename, tvb, 4, length, ENC_ASCII|ENC_NA);
offset += length;
length = tvb_strnlen(tvb, 4 + length, -1) + 1;
proto_tree_add_item(adwin_tree, hf_adwin_config_path, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
proto_tree_add_item(adwin_tree, hf_adwin_config_filesize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
tmp_time.secs = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(adwin_tree, tvb, offset, 4,
"File time: %s", abs_time_to_ep_str(&tmp_time, ABSOLUTE_TIME_LOCAL, TRUE));
offset += 4;
tmp_time.secs = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(adwin_tree, tvb, offset, 4,
"Update time: %s", abs_time_to_ep_str(&tmp_time, ABSOLUTE_TIME_LOCAL, TRUE));
offset += 4;
proto_tree_add_item(adwin_tree, hf_adwin_config_unused, tvb, offset, 128, ENC_NA);
offset += 128;
length = tvb_length(tvb) - offset;
proto_tree_add_item(adwin_tree, hf_adwin_config_data, tvb, offset, length, ENC_NA);
return tvb_length(tvb);
}
static gboolean
is_adwin_mac_or_broadcast(address mac)
{
if (mac.type != AT_ETHER)
return FALSE;
if (mac.len != 6)
return FALSE;
if ((memcmp(mac.data, mac_iab_start, mac.len) >= 0) &&
(memcmp(mac.data, mac_iab_end , mac.len) <= 0))
return TRUE;
if ((memcmp(mac.data, mac_oui_start, mac.len) >= 0) &&
(memcmp(mac.data, mac_oui_end, mac.len) <= 0))
return TRUE;
if (memcmp(mac.data, mac_broadcast, mac.len) == 0)
return TRUE;
return FALSE;
}
static int
dissect_adwin_config_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *adwin_config_tree;
guint32 length;
length = tvb_reported_length(tvb);
if (!(length == UDPStatusLENGTH
|| length == UDPExtStatusLENGTH
|| length == UDPMessageLENGTH
|| length == UDPMessageLENGTH_wrong
|| length == UDPInitAckLENGTH
|| length == UDPIXP425FlashUpdateLENGTH
|| length == UDPOutLENGTH))
return 0;
if (! (is_adwin_mac_or_broadcast(pinfo->dl_src) || is_adwin_mac_or_broadcast(pinfo->dl_dst)))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ADwin Config");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_adwin_config, tvb, 0, -1, ENC_NA);
adwin_config_tree = proto_item_add_subtree(ti, ett_adwin_config);
switch (length) {
case UDPStatusLENGTH:
dissect_UDPStatus(tvb, adwin_config_tree);
break;
case UDPExtStatusLENGTH:
dissect_UDPExtStatus(tvb, adwin_config_tree);
break;
case UDPMessageLENGTH:
dissect_UDPMessage(tvb, adwin_config_tree);
break;
case UDPMessageLENGTH_wrong:
dissect_UDPMessage(tvb, adwin_config_tree);
break;
case UDPInitAckLENGTH:
dissect_UDPInitAck(tvb, adwin_config_tree);
break;
case UDPIXP425FlashUpdateLENGTH:
dissect_UDPIXP425FlashUpdate(tvb, adwin_config_tree);
break;
case UDPOutLENGTH:
dissect_UDPOut(tvb, adwin_config_tree);
break;
default:
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(length, length_mapping,
"Unknown ADwin Configuration packet, length: %d"));
}
return (tvb_reported_length(tvb));
}
static int
dissect_adwin_config_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if(!(pinfo->srcport == ADWIN_CONFIGURATION_PORT
|| pinfo->destport == ADWIN_CONFIGURATION_PORT))
return 0;
if (! (is_adwin_mac_or_broadcast(pinfo->dl_src) || is_adwin_mac_or_broadcast(pinfo->dl_dst)))
return 0;
tcp_dissect_pdus(tvb, pinfo, tree, 1, 4, get_adwin_TCPUpdate_len, dissect_TCPFlashUpdate, NULL);
return (tvb_reported_length(tvb));
}
void
proto_register_adwin_config(void)
{
static hf_register_info hf[] = {
{ &hf_adwin_config_bootloader,
{ "Enable Bootloader", "adwin_config.bootloader",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_command,
{ "Command", "adwin_config.command",
FT_UINT32, BASE_DEC, config_command_mapping, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_data,
{ "Data", "adwin_config.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_date,
{ "Date", "adwin_config.date",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_description,
{ "Description", "adwin_config.description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_dhcp,
{ "DHCP enabled", "adwin_config.dhcp",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_filename,
{ "File name", "adwin_config.filename",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_filesize,
{ "File size", "adwin_config.filesize",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_gateway,
{ "Gateway IP", "adwin_config.gateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_mac,
{ "MAC address", "adwin_config.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_netmask,
{ "Netmask", "adwin_config.netmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_netmask_count,
{ "Netmask count", "adwin_config.netmask_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of binary ones in the netmask.", HFILL }
},
{ &hf_adwin_config_password,
{ "Password", "adwin_config.password",
FT_STRING, BASE_NONE, NULL, 0x0,
"Password to set for ADwin system.", HFILL }
},
{ &hf_adwin_config_pattern,
{ "Pattern", "adwin_config.pattern",
FT_UINT32, BASE_HEX, pattern_mapping, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_path,
{ "Path", "adwin_config.path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_port16,
{ "Port (16bit)", "adwin_config.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The server port on which the ADwin system is listening on (16bit).", HFILL }
},
{ &hf_adwin_config_port32,
{ "Port (32bit)", "adwin_config.port",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The server port on which the ADwin system is listening on (32bit).", HFILL }
},
{ &hf_adwin_config_reboot,
{ "Reboot", "adwin_config.reboot",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Number of system reboots.", HFILL }
},
{ &hf_adwin_config_scan_id,
{ "Scan ID", "adwin_config.scan_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_reply_broadcast,
{ "Reply with broadcast", "adwin_config.reply_broadcast",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"If this bit is set, the scanned system should reply with a broadcast.", HFILL }
},
{ &hf_adwin_config_revision,
{ "Revision", "adwin_config.revision",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_processor_type,
{ "Processor Type (Raw value)", "adwin_config.processor_type",
FT_STRING, BASE_NONE, NULL, 0x0,
"The DSP processor type of the ADwin system, e.g. T9, T10 or T11.", HFILL }
},
{ &hf_adwin_config_system_type,
{ "System Type (Raw value)", "adwin_config.system_type",
FT_STRING, BASE_NONE, NULL, 0x0,
"The system type of the ADwin system, e.g. Gold, Pro or Light.", HFILL }
},
{ &hf_adwin_config_server_ip,
{ "Server IP", "adwin_config.server_ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
"In scan replies, this is the current IP address of the ADwin system. In configuration packets, this is the new IP to be used by the ADwin system.", HFILL }
},
{ &hf_adwin_config_server_version,
{ "Server version", "adwin_config.server_version",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The version number of the server program. This number represents the complete firmware version, e.g. 2.74.", HFILL }
},
{ &hf_adwin_config_server_version_beta,
{ "server version (beta part)", "adwin_config.server_version_beta",
FT_UINT32, BASE_DEC, NULL, 0x0,
"A non-zero value of this field indicates a beta firmware version, where this number represents the current revision.", HFILL }
},
{ &hf_adwin_config_socketshutdowns,
{ "Socket shutdowns", "adwin_config.socketshutdowns",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of socket errors that lead to a recreation of the socket (ethernet interface version 1 only).", HFILL }
},
{ &hf_adwin_config_status,
{ "Status", "adwin_config.status",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_status_bootloader,
{ "Status Bootloader", "adwin_config.status_bootloader",
FT_BOOLEAN, 32, NULL, STATUS_WITH_BOOTLOADER,
"Indicates if the ADwin system has bootloader capabilities.", HFILL }
},
{ &hf_adwin_config_status_reprogrammable,
{ "Status Reprogrammable",
"adwin_config.status_reprogrammable",
FT_BOOLEAN, 32, NULL, STATUS_REPROGRAMMABLE,
NULL, HFILL }
},
{ &hf_adwin_config_status_configurable,
{ "Status Configurable", "adwin_config.status_configurable",
FT_BOOLEAN, 32, NULL, STATUS_CONFIGURABLE,
NULL, HFILL }
},
{ &hf_adwin_config_status_bootloader_boots,
{ "Status Bootloader boots",
"adwin_config.status_bootloader_boots",
FT_BOOLEAN, 32, NULL, STATUS_BOOTLOADER_BOOTS,
NULL, HFILL }
},
{ &hf_adwin_config_status_bootloader_reprogrammable,
{ "Status Bootloader reprogrammable",
"adwin_config.status_bootloader_reprogrammable",
FT_BOOLEAN, 32, NULL, STATUS_BOOTLOADER_REPROGRAMMABLE,
NULL, HFILL }
},
{ &hf_adwin_config_status_bootloader_receive,
{ "Status Bootloader receive",
"adwin_config.status_bootloader_receive",
FT_BOOLEAN, 32, NULL, STATUS_BOOTLOADER_RECEIVES_DATA,
NULL, HFILL }
},
{ &hf_adwin_config_status_bootloader_reprogramming_done,
{ "Status Bootloader reprogramming done",
"adwin_config.status_bootloader_reprogramming_done",
FT_BOOLEAN, 32, NULL, STATUS_BOOTLOADER_REPROGRAMMING_DONE,
NULL, HFILL }
},
{ &hf_adwin_config_status_eeprom_support,
{ "Status EEPROM Support",
"adwin_config.status_eeprom_support",
FT_BOOLEAN, 32, NULL, STATUS_WITH_EEPROM_SUPPORT,
NULL, HFILL }
},
{ &hf_adwin_config_stream_length,
{ "Stream length", "adwin_config.stream_length",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_timeout,
{ "Timeout", "adwin_config.timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_timerresets,
{ "Timer resets", "adwin_config.timerresets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Counter for resets of the timer (ethernet interface version 1 only).", HFILL }
},
{ &hf_adwin_config_disk_free,
{ "Free disk space (kb)", "adwin_config.disk_free",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Free disk space in kb on flash (ethernet interface version 2 only).", HFILL }
},
{ &hf_adwin_config_disk_size,
{ "Disk size (kb)", "adwin_config.disk_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flash disk size in kb (ethernet interface version 2 only).", HFILL }
},
{ &hf_adwin_config_unused,
{ "Unused", "adwin_config.unused",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_version,
{ "Version", "adwin_config.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_adwin_config_xilinx_version,
{ "XILINX Version", "adwin_config.xilinx_version",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Version of XILINX program", HFILL }
},
};
static gint *ett[] = {
&ett_adwin_config,
&ett_adwin_config_status,
&ett_adwin_config_debug,
};
proto_adwin_config =
proto_register_protocol("ADwin configuration protocol",
"ADwin-Config", "adwin_config");
proto_register_field_array(proto_adwin_config, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_adwin_config(void)
{
heur_dissector_add("udp", dissect_adwin_config_udp, proto_adwin_config);
heur_dissector_add("tcp", dissect_adwin_config_tcp, proto_adwin_config);
}
