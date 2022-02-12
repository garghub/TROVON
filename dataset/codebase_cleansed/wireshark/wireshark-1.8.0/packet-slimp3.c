static int
dissect_slimp3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const char *opcode_str;
proto_tree *slimp3_tree = NULL;
proto_item *ti = NULL, *hidden_item;
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
opcode_str = match_strval(opcode, slimp3_opcode_vals);
if (opcode_str == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SliMP3");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO, opcode_str);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_slimp3, tvb, offset, -1, ENC_NA);
slimp3_tree = proto_item_add_subtree(ti, ett_slimp3);
proto_tree_add_uint(slimp3_tree, hf_slimp3_opcode, tvb,
offset, 1, opcode);
}
if ((pinfo->destport == UDP_PORT_SLIMP3_V2) && (pinfo->srcport == UDP_PORT_SLIMP3_V2)) {
SET_ADDRESS(&tmp_addr, AT_ETHER, 6, tvb_get_ptr(tvb, offset+12, 6));
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
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_ir, tvb, offset+8, 4, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
i1 = tvb_get_ntohl(tvb, offset+2);
proto_tree_add_text(slimp3_tree, tvb, offset+2, 4, "Uptime: %u sec (%u ticks)",
i1/625000, i1);
i1 = tvb_get_guint8(tvb, offset+6);
proto_tree_add_text(slimp3_tree, tvb, offset+6, 1, "Code identifier: 0x%0x: %s",
i1, val_to_str(i1, slimp3_ir_types, "Unknown"));
proto_tree_add_text(slimp3_tree, tvb, offset+7, 1, "Code bits: %d",
tvb_get_guint8(tvb, offset+7));
i1 = tvb_get_ntohl(tvb, offset+8);
if (tvb_get_guint8(tvb, offset+6) == 0x02 &&
tvb_get_guint8(tvb, offset+7) == 32) {
proto_tree_add_text(slimp3_tree, tvb, offset+8, 4,
"Infrared Code: %s: 0x%0x",
val_to_str(i1, slimp3_ir_codes_slimp3, "Unknown"), i1);
}
else if (tvb_get_guint8(tvb, offset+6) == 0xff &&
tvb_get_guint8(tvb, offset+7) == 16) {
proto_tree_add_text(slimp3_tree, tvb, offset+8, 4,
"Infrared Code: %s: 0x%0x",
val_to_str(i1, slimp3_ir_codes_jvc, "Unknown"), i1);
} else {
proto_tree_add_text(slimp3_tree, tvb, offset+8, 4, "Infrared Code: 0x%0x", i1);
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
i1 = tvb_get_ntohl(tvb, offset+8);
if (tvb_get_guint8(tvb, offset+6) == 0x02 &&
tvb_get_guint8(tvb, offset+7) == 32) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", SLIMP3: %s",
val_to_str(i1, slimp3_ir_codes_slimp3, "Unknown (0x%0x)"));
}
else if (tvb_get_guint8(tvb, offset+6) == 0xff &&
tvb_get_guint8(tvb, offset+7) == 16) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", JVC: %s",
val_to_str(i1, slimp3_ir_codes_jvc, "Unknown (0x%0x)"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", 0x%0x", i1);
}
}
break;
case SLIMP3_DISPLAY:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_display,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
i1 = 18;
in_str = FALSE;
lcd_strlen = 0;
while (i1 < tvb_reported_length_remaining(tvb, offset)) {
switch(tvb_get_guint8(tvb, offset + i1)) {
case 0:
in_str = FALSE;
lcd_strlen = 0;
proto_tree_add_text(slimp3_tree, tvb, offset + i1, 2,
"Delay (%d ms)", tvb_get_guint8(tvb, offset + i1 + 1));
i1 += 2;
break;
case 3:
lcd_char = tvb_get_guint8(tvb, offset + i1 + 1);
if (!isprint(lcd_char)) lcd_char = '.';
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
if (check_col(pinfo->cinfo, COL_INFO)) {
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
if (lcd_strlen < 1 ||
lcd_str[lcd_strlen-1] != ' ' ||
tvb_get_guint8(tvb, offset + i1 + 1) != ' ') {
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
}
break;
case SLIMP3_CONTROL:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_control,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(slimp3_tree, tvb, offset+1, 1, "Command: %s",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_stream_control, "Unknown (0x%0x)"));
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_stream_control, "Unknown (0x%0x)"));
}
break;
case SLIMP3_HELLO:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_hello,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (to_server) {
guint8 fw_ver = 0;
proto_tree_add_text(slimp3_tree, tvb, offset, 1, "Hello Response (Client --> Server)");
proto_tree_add_text(slimp3_tree, tvb, offset+1, 1, "Device ID: %d",
tvb_get_guint8(tvb, offset+1));
fw_ver = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(slimp3_tree, tvb, offset+2, 1, "Firmware Revision: %d.%d (0x%0x)",
fw_ver>>4, fw_ver & 0xf, fw_ver);
} else {
proto_tree_add_text(slimp3_tree, tvb, offset, 1, "Hello Request (Server --> Client)");
}
}
break;
case SLIMP3_I2C:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_i2c,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (to_server) {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"I2C Response (Client --> Server)");
} else {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"I2C Request (Server --> Client)");
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
if (to_server) {
col_append_str(pinfo->cinfo, COL_INFO, ", Response");
} else {
col_append_str(pinfo->cinfo, COL_INFO, ", Request");
}
}
break;
case SLIMP3_DATA_REQ:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_data_request,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(slimp3_tree, tvb, offset+2, 2,
"Requested offset: %d bytes.",
tvb_get_ntohs(tvb, offset+2)*2);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Offset: %d bytes",
tvb_get_ntohs(tvb, offset+2)*2);
}
break;
case SLIMP3_DATA:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_data,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (old_protocol) {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Length: %d bytes",
tvb_reported_length_remaining(tvb, offset+18));
proto_tree_add_text(slimp3_tree, tvb, offset+2, 2,
"Buffer offset: %d bytes.",
tvb_get_ntohs(tvb, offset+2) * 2);
}
else {
proto_tree_add_text(slimp3_tree, tvb, offset+1, 1, "Command: %s",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_mpg_control, "Unknown (0x%0x)"));
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Length: %d bytes",
tvb_reported_length_remaining(tvb, offset+18));
proto_tree_add_text(slimp3_tree, tvb, offset+6, 2,
"Write Pointer: %d",
tvb_get_ntohs(tvb, offset+6) * 2);
proto_tree_add_text(slimp3_tree, tvb, offset+10, 2,
"Sequence: %d",
tvb_get_ntohs(tvb, offset+10));
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
if (old_protocol) {
col_append_fstr(pinfo->cinfo, COL_INFO,
", Length: %d bytes, Offset: %d bytes.",
tvb_reported_length_remaining(tvb, offset+18),
tvb_get_ntohs(tvb, offset+2) * 2);
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO,
", %s, %d bytes at %d, Sequence: %d",
val_to_str(tvb_get_guint8(tvb, offset+1),
slimp3_mpg_control, "Unknown (0x%0x)"),
tvb_reported_length_remaining(tvb, offset+18),
tvb_get_ntohs(tvb, offset+6) * 2,
tvb_get_ntohs(tvb, offset+10));
}
}
break;
case SLIMP3_DISC_REQ:
if (tree) {
guint8 fw_ver;
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_discover_request,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(slimp3_tree, tvb, offset+1, 1,
"Device ID: %d.", tvb_get_guint8(tvb, offset+1));
fw_ver = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(slimp3_tree, tvb, offset+2, 1, "Firmware Revision: %d.%d (0x%0x)",
fw_ver>>4, fw_ver & 0xf, fw_ver);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
guint8 fw_ver = tvb_get_guint8(tvb, offset+2);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Device ID: %d. Firmware: %d.%d",
tvb_get_guint8(tvb, offset+1), fw_ver>>4, fw_ver & 0xf);
}
break;
case SLIMP3_DISC_RSP:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_discover_response,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(slimp3_tree, tvb, offset+2, 4,
"Server Address: %s.",
tvb_ip_to_str(tvb, offset+2));
proto_tree_add_text(slimp3_tree, tvb, offset+6, 2,
"Server Port: %d", tvb_get_ntohs(tvb, offset + 6));
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Server Address: %s. Server Port: %d",
tvb_ip_to_str(tvb, offset+2),
tvb_get_ntohs(tvb, offset + 6));
}
break;
case SLIMP3_DATA_ACK:
if (tree) {
hidden_item = proto_tree_add_item(slimp3_tree, hf_slimp3_data_ack,
tvb, offset, 1, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(slimp3_tree, tvb, offset+6, 2,
"Write Pointer: %d",
tvb_get_ntohs(tvb, offset+6) * 2);
proto_tree_add_text(slimp3_tree, tvb, offset+8, 2,
"Read Pointer: %d",
tvb_get_ntohs(tvb, offset+8) * 2);
proto_tree_add_text(slimp3_tree, tvb, offset+10, 2,
"Sequence: %d",
tvb_get_ntohs(tvb, offset+10));
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Sequence: %d",
tvb_get_ntohs(tvb, offset+10));
}
break;
default:
if (tree) {
proto_tree_add_text(slimp3_tree, tvb, offset, -1,
"Data (%d bytes)", tvb_reported_length_remaining(tvb, offset));
}
break;
}
return tvb_length(tvb);
}
void
proto_register_slimp3(void)
{
static hf_register_info hf[] = {
{ &hf_slimp3_opcode,
{ "Opcode", "slimp3.opcode",
FT_UINT8, BASE_DEC, VALS(slimp3_opcode_vals), 0x0,
"SLIMP3 message type", HFILL }},
{ &hf_slimp3_ir,
{ "Infrared", "slimp3.ir",
FT_UINT32, BASE_HEX, NULL, 0x0,
"SLIMP3 Infrared command", HFILL }},
{ &hf_slimp3_control,
{ "Control Packet", "slimp3.control",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 control", HFILL }},
{ &hf_slimp3_display,
{ "Display", "slimp3.display",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 display", HFILL }},
{ &hf_slimp3_hello,
{ "Hello", "slimp3.hello",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 hello", HFILL }},
{ &hf_slimp3_i2c,
{ "I2C", "slimp3.i2c",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 I2C", HFILL }},
{ &hf_slimp3_data,
{ "Data", "slimp3.data",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 Data", HFILL }},
{ &hf_slimp3_data_request,
{ "Data Request", "slimp3.data_req",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 Data Request", HFILL }},
{ &hf_slimp3_discover_request,
{ "Discovery Request", "slimp3.discovery_req",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 Discovery Request", HFILL }},
{ &hf_slimp3_discover_response,
{ "Discovery Response", "slimp3.discovery_response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 Discovery Response", HFILL }},
{ &hf_slimp3_data_ack,
{ "Data Ack", "slimp3.data_ack",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"SLIMP3 Data Ack", HFILL }},
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
