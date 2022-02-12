static int
dissect_slimp3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
const char *opcode_str;
proto_tree *slimp3_tree;
proto_item *ti;
gint i1;
gint offset = 0;
guint16 opcode;
guchar lcd_char;
char lcd_str[MAX_LCD_STR_LEN + 1];
int to_server = FALSE;
int old_protocol = FALSE;
address tmp_addr;
gboolean in_str;
int lcd_strlen;
if (!tvb_bytes_exist(tvb, offset, 1))
return 0;
opcode = tvb_get_guint8(tvb, offset);
opcode_str = try_val_to_str(opcode, slimp3_opcode_vals);
if (opcode_str == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SliMP3");
col_add_str(pinfo->cinfo, COL_INFO, opcode_str);
ti = proto_tree_add_item(tree, proto_slimp3, tvb, offset, -1, ENC_NA);
slimp3_tree = proto_item_add_subtree(ti, ett_slimp3);
proto_tree_add_uint(slimp3_tree, hf_slimp3_opcode, tvb,
offset, 1, opcode);
if ((pinfo->destport == UDP_PORT_SLIMP3_V2) && (pinfo->srcport == UDP_PORT_SLIMP3_V2)) {
TVB_SET_ADDRESS(&tmp_addr, AT_ETHER, tvb, offset+12, 6);
to_server = ADDRESSES_EQUAL(&tmp_addr, &pinfo->dl_src);
}
else if (pinfo->destport == UDP_PORT_SLIMP3_V2) {
to_server = TRUE;
}
else if (pinfo->srcport == UDP_PORT_SLIMP3_V2) {
to_server = FALSE;
}
if (pinfo->destport == UDP_PORT_SLIMP3_V1) {
to_server = TRUE;
old_protocol = TRUE;
}
else if (pinfo->srcport == UDP_PORT_SLIMP3_V1) {
to_server = FALSE;
old_protocol = TRUE;
}
switch (opcode) {
case SLIMP3_IR:
if (tree) {
i1 = tvb_get_ntohl(tvb, offset+2);
proto_tree_add_uint_format_value(slimp3_tree, hf_slimp3_uptime, tvb, offset+2, 4, i1,
"%u sec (%u ticks)", i1/625000, i1);
proto_tree_add_item(slimp3_tree, hf_slimp3_code_id, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(slimp3_tree, hf_slimp3_code_bits, tvb, offset+7, 1, ENC_BIG_ENDIAN);
i1 = tvb_get_ntohl(tvb, offset+8);
if (tvb_get_guint8(tvb, offset+6) == 0x02 &&
tvb_get_guint8(tvb, offset+7) == 32) {
proto_tree_add_item(slimp3_tree, hf_slimp3_infrared_slimp3, tvb, offset+8, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", SLIMP3: %s",
val_to_str(i1, slimp3_ir_codes_slimp3, "Unknown (0x%0x)"));
}
else if (tvb_get_guint8(tvb, offset+6) == 0xff &&
tvb_get_guint8(tvb, offset+7) == 16) {
proto_tree_add_item(slimp3_tree, hf_slimp3_infrared_jvc, tvb, offset+8, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", JVC: %s",
val_to_str(i1, slimp3_ir_codes_jvc, "Unknown (0x%0x)"));
} else {
proto_tree_add_item(slimp3_tree, hf_slimp3_infrared, tvb, offset+8, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", 0x%0x", i1);
}
}
break;
case SLIMP3_DISPLAY:
if (tree) {
i1 = 18;
in_str = FALSE;
lcd_strlen = 0;
while (i1 < tvb_reported_length_remaining(tvb, offset)) {
switch(tvb_get_guint8(tvb, offset + i1)) {
case 0:
in_str = FALSE;
lcd_strlen = 0;
proto_tree_add_text(slimp3_tree, tvb, offset + i1, 2,
"Delay (%u ms)", tvb_get_guint8(tvb, offset + i1 + 1));
i1 += 2;
break;
case 3:
lcd_char = tvb_get_guint8(tvb, offset + i1 + 1);
if (!isprint(lcd_char))
lcd_char = '.';
if (ti && in_str) {
lcd_strlen += 2;
proto_item_append_text(ti, "%c", lcd_char);
proto_item_set_len(ti, lcd_strlen);
} else {
ti = proto_tree_add_text(slimp3_tree, tvb, offset + i1, 2,
"String: %c", lcd_char);
in_str = TRUE;
lcd_strlen = 2;
}
i1 += 2;
break;
case 2:
in_str = FALSE;
lcd_strlen = 0;
ti = proto_tree_add_text(slimp3_tree, tvb, offset + i1, 2,
"Command: %s",
val_to_str(tvb_get_guint8(tvb, offset + i1 + 1),
slimp3_display_commands,
"Unknown (0x%0x)"));
if ((tvb_get_guint8(tvb, offset + i1 + 1) & 0xf0) == 0x30) {
proto_item_append_text(ti, ": %s",
val_to_str(tvb_get_guint8(tvb, offset + i1 + 2),
slimp3_display_fset8,
"Unknown (0x%0x)"));
i1 += 2;
}
i1 += 2;
break;
default:
proto_tree_add_text(slimp3_tree, tvb, offset + i1, 2,
"Unknown 0x%0x, 0x%0x",
tvb_get_guint8(tvb, offset + i1),
tvb_get_guint8(tvb, offset + i1 + 1));
i1 += 2;
break;
}
}
}
i1 = 18;
lcd_strlen = 0;
while (tvb_offset_exists(tvb, offset + i1) &&
lcd_strlen < MAX_LCD_STR_LEN) {
switch (tvb_get_guint8(tvb, offset + i1)) {
case 0:
lcd_str[lcd_strlen++] = '.';
break;
case 2:
lcd_str[lcd_strlen++] = '|';
if (tvb_offset_exists(tvb, offset + i1 + 1) &&
(tvb_get_guint8(tvb, offset + i1 + 1) & 0xf0) == 0x30)
i1 += 2;
break;
case 3:
if (tvb_offset_exists(tvb, offset + i1 + 1)) {
if ((lcd_strlen < 1) ||
(lcd_str[lcd_strlen-1] != ' ') ||
(tvb_get_guint8(tvb, offset + i1 + 1) != ' ')) {
lcd_char = tvb_get_guint8(tvb, offset + i1 + 1);
lcd_str[lcd_strlen++] = isprint(lcd_char) ? lcd_char : '.';
}
}
}
i1 += 2;
}
lcd_str[lcd_strlen] = '\0';
if (lcd_strlen > 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", lcd_str);
break;
case SLIMP3_CONTROL:
proto_tree_add_item(slimp3_tree, hf_slimp3_control, tvb, offset+1, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_stream_control, "Unknown (0x%0x)"));
break;
case SLIMP3_HELLO:
if (tree) {
if (to_server) {
guint8 fw_ver;
proto_tree_add_text(slimp3_tree, tvb, offset, 1, "Hello Response (Client --> Server)");
proto_tree_add_item(slimp3_tree, hf_slimp3_device_id, tvb, offset+1, 1, ENC_BIG_ENDIAN);
fw_ver = tvb_get_guint8(tvb, offset+2);
proto_tree_add_uint_format_value(slimp3_tree, hf_slimp3_fw_rev, tvb, offset+2, 1, fw_ver,
"%u.%u (0x%0x)", fw_ver>>4, fw_ver & 0xf, fw_ver);
} else {
proto_tree_add_text(slimp3_tree, tvb, offset, 1, "Hello Request (Server --> Client)");
}
}
break;
case SLIMP3_I2C:
if (to_server) {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"I2C Response (Client --> Server)");
col_append_str(pinfo->cinfo, COL_INFO, ", Response");
} else {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"I2C Request (Server --> Client)");
col_append_str(pinfo->cinfo, COL_INFO, ", Request");
}
break;
case SLIMP3_DATA_REQ:
proto_tree_add_item(slimp3_tree, hf_slimp3_data_req_offset, tvb, offset+2, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Offset: %u bytes",
tvb_get_ntohs(tvb, offset+2)*2);
break;
case SLIMP3_DATA:
if (old_protocol) {
guint offset_buffer;
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Length: %d bytes",
tvb_reported_length_remaining(tvb, offset+18));
offset_buffer = tvb_get_ntohs(tvb, offset+2) * 2;
proto_tree_add_uint(slimp3_tree, hf_slimp3_data_offset, tvb, offset+2, 2, offset_buffer);
col_append_fstr(pinfo->cinfo, COL_INFO,
", Length: %d bytes, Offset: %u bytes.",
tvb_reported_length_remaining(tvb, offset+18),
offset_buffer);
}
else {
guint write_pointer;
proto_tree_add_item(slimp3_tree, hf_slimp3_data_command, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Length: %d bytes",
tvb_reported_length_remaining(tvb, offset+18));
write_pointer = tvb_get_ntohs(tvb, offset+6) * 2;
proto_tree_add_uint(slimp3_tree, hf_slimp3_data_write_pointer, tvb, offset+6, 2, write_pointer);
proto_tree_add_item(slimp3_tree, hf_slimp3_data_sequence, tvb, offset+10, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO,
", %s, %d bytes at %u, Sequence: %u",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_mpg_control, "Unknown (0x%0x)"),
tvb_reported_length_remaining(tvb, offset+18),
write_pointer,
tvb_get_ntohs(tvb, offset+10));
}
break;
case SLIMP3_DISC_REQ:
{
guint8 fw_ver;
proto_tree_add_item(slimp3_tree, hf_slimp3_device_id, tvb, offset+1, 1, ENC_BIG_ENDIAN);
fw_ver = tvb_get_guint8(tvb, offset+2);
proto_tree_add_uint_format_value(slimp3_tree, hf_slimp3_fw_rev, tvb, offset+2, 1, fw_ver,
"%u.%u (0x%0x)", fw_ver>>4, fw_ver & 0xf, fw_ver);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Device ID: %u. Firmware: %u.%u",
tvb_get_guint8(tvb, offset+1), fw_ver>>4, fw_ver & 0xf);
}
break;
case SLIMP3_DISC_RSP:
if (tree) {
proto_tree_add_item(slimp3_tree, hf_slimp3_disc_rsp_server_ip, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(slimp3_tree, hf_slimp3_disc_rsp_server_port, tvb, offset+6, 2, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Server Address: %s. Server Port: %u",
tvb_ip_to_str(tvb, offset+2),
tvb_get_ntohs(tvb, offset + 6));
break;
case SLIMP3_DATA_ACK:
if (tree) {
guint pointer;
pointer = tvb_get_ntohs(tvb, offset+6) * 2;
proto_tree_add_uint(slimp3_tree, hf_slimp3_data_ack_write_pointer, tvb, offset+6, 2, pointer);
pointer = tvb_get_ntohs(tvb, offset+8) * 2;
proto_tree_add_uint(slimp3_tree, hf_slimp3_data_ack_read_pointer, tvb, offset+8, 2, pointer);
proto_tree_add_item(slimp3_tree, hf_slimp3_data_ack_sequence, tvb, offset+10, 2, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Sequence: %u",
tvb_get_ntohs(tvb, offset+10));
break;
default:
if (tree) {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Data (%d bytes)", tvb_reported_length_remaining(tvb, offset));
}
break;
}
return tvb_reported_length(tvb);
}
void
proto_register_slimp3(void)
{
static hf_register_info hf[] = {
{ &hf_slimp3_opcode,
{ "Opcode", "slimp3.opcode",
FT_UINT8, BASE_DEC, VALS(slimp3_opcode_vals), 0x0,
"SLIMP3 message type", HFILL }},
{ &hf_slimp3_control,
{ "Control Packet", "slimp3.control",
FT_UINT8, BASE_DEC, VALS(slimp3_stream_control), 0x0,
"SLIMP3 control", HFILL }},
{ &hf_slimp3_uptime,
{ "Uptime", "slimp3.uptime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_code_id,
{ "Code identifier", "slimp3.code_id",
FT_UINT8, BASE_DEC, VALS(slimp3_ir_types), 0x0,
NULL, HFILL }},
{ &hf_slimp3_code_bits,
{ "Code bits", "slimp3.code_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_infrared_slimp3,
{ "Infrared Code", "slimp3.infrared",
FT_UINT32, BASE_HEX, VALS(slimp3_ir_codes_slimp3), 0x0,
NULL, HFILL }},
{ &hf_slimp3_infrared_jvc,
{ "Infrared Code", "slimp3.infrared",
FT_UINT32, BASE_HEX, VALS(slimp3_ir_codes_jvc), 0x0,
NULL, HFILL }},
{ &hf_slimp3_infrared,
{ "Infrared Code", "slimp3.infrared",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_device_id,
{ "Device ID", "slimp3.device_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_fw_rev,
{ "Firmware Revision", "slimp3.fw_rev",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_offset,
{ "Buffer offset", "slimp3.data.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_command,
{ "Command", "slimp3.data.command",
FT_UINT8, BASE_HEX, VALS(slimp3_mpg_control), 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_write_pointer,
{ "Write Pointer", "slimp3.data.write_pointer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_sequence,
{ "Sequence", "slimp3.data.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_disc_rsp_server_ip,
{ "Server Address", "slimp3.disc_rsp.server_ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_disc_rsp_server_port,
{ "Server Port", "slimp3.disc_rsp.server_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_ack_write_pointer,
{ "Write Pointer", "slimp3.data_ack.write_pointer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_ack_read_pointer,
{ "Read Pointer", "slimp3.data_ack.read_pointer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_ack_sequence,
{ "Sequence", "slimp3.data_ack.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_slimp3_data_req_offset,
{ "Requested offset", "slimp3.data_req.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_slimp3,
};
proto_slimp3 = proto_register_protocol("SliMP3 Communication Protocol",
"SliMP3", "slimp3");
proto_register_field_array(proto_slimp3, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_slimp3(void)
{
dissector_handle_t slimp3_handle;
slimp3_handle = new_create_dissector_handle(dissect_slimp3, proto_slimp3);
dissector_add_uint("udp.port", UDP_PORT_SLIMP3_V1, slimp3_handle);
dissector_add_uint("udp.port", UDP_PORT_SLIMP3_V2, slimp3_handle);
}
