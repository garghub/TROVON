static char *
version_number_computer(int hexa_version)
{
int release, vers, fix;
release = (int)(hexa_version / 10000);
vers = (int)((hexa_version % 10000) / 100);
fix = (hexa_version % 10000) % 100;
return ep_strdup_printf("%d.%02d.%02d", release, vers, fix);
}
static void
decode_with_one_parameter(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_first_parameter[] = {
{0x01, "Production Test Command"},
{0x06, "Reserved For Compatibility"},
{0x2B, "Temporization"},
{0x3B, "Volume"},
{0x42, "Subdevice Address"},
{0, NULL}
};
if (!ua3g_body_item || (length == 0))
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, length, "%s: %d",
val_to_str_const(opcode, str_first_parameter, "Unknown"), tvb_get_guint8(tvb, offset));
}
static void
decode_subdevice_escape(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int j;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice Address: %d", (tvb_get_guint8(tvb, offset) & 0x0F));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice Opcode: 0x%02x", (tvb_get_guint8(tvb, offset) & 0x7F));
offset++;
length--;
j = 0;
while (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Parameter Byte %2d: %d", j++,
tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
static void
decode_software_reset(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_verswitch[] = {
{0x00, "Reset Without Version Switch"},
{0x01, "Reset With Version Switch"},
{0, NULL}
};
if (!ua3g_body_item || (length == 0))
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_verswitch, "Unknown"));
}
static void
decode_ip_phone_warmstart(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_command[] = {
{0x00, "Run In UA2G Emulation Mode"},
{0x01, "Run In Full UA3G Mode"},
{0, NULL}
};
if (!ua3g_body_item || (length == 0))
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree,
tvb,
offset,
1,
"Command: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_command, "Unknown"));
}
static void
decode_super_msg(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int i, parameter_length;
int j;
if (!ua3g_body_item || (length == 0))
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
j = 0;
while (length > 0) {
if (opcode == 0x17) {
parameter_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Length %d: %d", j++, parameter_length);
offset += 2;
length -= 2;
} else {
parameter_length = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Length %d: %d", j++, parameter_length);
offset++;
length--;
}
for (i = 1; i <= parameter_length; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"L%d Byte %2d: %d",
j, i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
}
static void
decode_segment_msg(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
guint8 val;
int j;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "F/S: %s (%d)",
(val & 0x80) ? "First Segment" : "Subsequent Segment",
val & 0x80);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Number Of Remaining Segments: %d",
(val & 0x7F));
offset++;
length--;
if (val & 0x80) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2, "Length: %d",
tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
}
j = 0;
while (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Segment Message byte %d: %d",
j++, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
static void
decode_ip_device_routing(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
proto_item *ua3g_param_item;
proto_tree *ua3g_param_tree;
static const value_string str_command[] = {
{0x00, "Reset"},
{0x01, "Start RTP"},
{0x02, "Stop RTP"},
{0x03, "Redirect"},
{0x04, "Tone Definition"},
{0x05, "Start Tone"},
{0x06, "Stop Tone"},
{0x07, "Start Listen RTP"},
{0x08, "Stop Listen RTP"},
{0x09, "Get Parameters Value"},
{0x0A, "Set Parameters Value"},
{0x0B, "Send Digit"},
{0x0C, "Pause RTP"},
{0x0D, "Restart RTP"},
{0x0E, "Start Record RTP"},
{0x0F, "Stop Record RTP"},
{0, NULL}
};
static value_string_ext str_command_ext = VALUE_STRING_EXT_INIT(str_command);
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip, tvb, offset, 1,
command, "Command: %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
offset++;
length--;
switch (command) {
case 0x00:
{
int i, parameter_id, parameter_length;
static const value_string str_parameter_id[] = {
{0x00, "Update Mode"},
{0x01, "Bad Sec Mode"},
{0x02, "Customization Name"},
{0x03, "Localization Name"},
{0, NULL}
};
if (length > 0) {
emem_strbuf_t *strbuf;
strbuf = ep_strbuf_new_label(NULL);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
guint8 param;
switch (parameter_id) {
case 0x00:
{
static const char *str_update_mode[] = {
"Bootloader",
"Data",
"Customization",
"Localization",
"Code",
"SIP"
};
param = tvb_get_guint8(tvb, offset + 2);
if ((param & 0x80) == 0x00) {
ep_strbuf_append(strbuf, "NOE Update Mode: ");
for (i = 0; i < 6; i++) {
ep_strbuf_append_printf(strbuf, "%s: %s, ",
str_update_mode[i],
((param >> i) & 0x01) ? "Enable" : "Disable");
}
} else {
ep_strbuf_append(strbuf, "Unknown");
}
break;
}
case 0x01:
{
static const value_string str_bad_sec_mode[] = {
{0x01, "Binary is full, CS is secured, but terminal running in clear mode"},
{0, NULL}
};
ep_strbuf_append(strbuf,
val_to_str_const(tvb_get_guint8(tvb, offset + 2), str_bad_sec_mode, "Unknown"));
break;
}
case 0x02:
{
ep_strbuf_append(strbuf, "\"");
for (i = 1; i <= parameter_length; i++) {
if (isprint(tvb_get_guint8(tvb, offset + 1 + i)))
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
else
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
}
ep_strbuf_append(strbuf, "\"");
break;
}
case 0x03:
{
ep_strbuf_append(strbuf, "\"");
for (i = 1; i <= parameter_length; i++) {
if (isprint(tvb_get_guint8(tvb, offset + 1 + i)))
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
else
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
}
ep_strbuf_append(strbuf, "\"");
break;
}
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s", val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
}
}
break;
}
case 0x01:
{
emem_strbuf_t *strbuf;
int i, parameter_length, parameter_id;
static const value_string str_direction[] = {
{0x00, "Terminal Input"},
{0x01, "Terminal Output"},
{0x02, "Terminal Input/Output (Both Directions)"},
{0, NULL}
};
static const value_string str_parameter_id[] = {
{0x00, "Local UDP Port"},
{0x01, "Remote IP Address"},
{0x02, "Remote UDP Port"},
{0x03, "Type Of Service"},
{0x04, "Compressor"},
{0x05, "Payload Concatenation (ms)"},
{0x06, "Echo Cancellation Enabler"},
{0x07, "Silence Suppression Enabler"},
{0x08, "802.1 Q User Priority"},
{0x09, "Reserved"},
{0x0a, "Post Filtering Enabler"},
{0x0b, "High Pass Filtering Enabler"},
{0x0c, "Remote SSRC"},
{0x0d, "Must Send QOS Tickets"},
{0x0e, "Local Identifier"},
{0x0f, "Distant Identifier"},
{0x10, "Destination For RTCP Sender Reports - Port Number"},
{0x11, "Destination For RTCP Sender Reports - IP Address"},
{0x12, "Destination For RTCP Receiver Reports - Port Number"},
{0x13, "Destination For RTCP Receiver Reports - IP Address"},
{0x14, "Channel Number"},
{0x15, "DTMF Sending"},
{0x16, "Payload Type Of Redundancy"},
{0x17, "Payload Type Of DTMF Events"},
{0x18, "Enable / Disable RFC 2198"},
{0x31, "SRTP Encryption Enable For This Communication"},
{0x32, "Master Key For SRTP Session"},
{0x33, "Master Salt Key For SRTP Session"},
{0x34, "Master key for output stream of SRTP session"},
{0x35, "Master salt key for output stream of SRTP session"},
{0x36, "Integrity checking enabled for this communication"},
{0x37, "MKI value for SRTP packets in input stream"},
{0x38, "MKI value for SRTP packets in output stream"},
{0x50, "MD5 Authentication"},
{0, NULL}
};
static value_string_ext str_parameter_id_ext = VALUE_STRING_EXT_INIT(str_parameter_id);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Direction: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_direction, "Unknown"));
offset++;
length--;
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x01:
case 0x11:
case 0x13:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 1; i < parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+2+i));
}
break;
}
case 0x04:
{
static const value_string str_compressor[] = {
{0x00, "G.711 A-law"},
{0x01, "G.711 mu-law"},
{0x0F, "G.723.1 5.3kbps"},
{0x10, "G.723.1 6.3kbps"},
{0x11, "G.729A 8 kbps"},
{0, NULL}
};
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, val_to_str_const((guint8)(param_value), str_compressor, "Default Codec"));
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x06:
case 0x07:
case 0x0A:
case 0x0B:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, STR_ON_OFF((guint8)(param_value)));
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x0D:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, ((guint8)param_value == 0x01) ? "Yes": "No");
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x0E:
case 0x0F:
{
break;
}
case 0x15:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, ((guint8)param_value) ? "Send DTMF" : "Don't Send DTMF");
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x18:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, (((guint8)param_value) == 0x00) ? "Enable" : "Disable");
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x31:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf, (((guint8)param_value) == 0x10) ? "Enable" : "Disable");
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x00:
case 0x02:
case 0x03:
case 0x05:
case 0x08:
case 0x09:
case 0x0C:
case 0x10:
case 0x12:
case 0x14:
case 0x16:
case 0x17:
case 0x32:
case 0x33:
case 0x34:
case 0x35:
case 0x36:
case 0x37:
case 0x38:
case 0x50:
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x02:
{
emem_strbuf_t *strbuf;
int i, parameter_id, parameter_length;
static const value_string str_parameter_id[] = {
{0x0E, "Local Identifier"},
{0x0F, "Distant Identifier"},
{0x14, "Canal Identifier"},
{0, NULL}
};
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x0E:
case 0x0F:
{
break;
}
case 0x14:
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x03:
{
emem_strbuf_t *strbuf;
int i, parameter_length, parameter_id;
static const value_string str_parameter_id[] = {
{0x00, "Remote MainCPU Server IP Address"},
{0x01, "Remote MainCPU Server Port"},
{0, NULL}
};
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+1+i));
}
break;
}
case 0x01:
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
}
break;
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset, parameter_length + 2,
"%s: %s", val_to_str_const(parameter_id, str_parameter_id, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset, parameter_length + 2,
"%s", val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x04:
{
int i, tone_nb_entries;
guint16 frequency_1, frequency_2;
signed char level_1, level_2;
tone_nb_entries = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Number Of Entries: %d", tone_nb_entries);
offset++;
length--;
while (length > 0 && tone_nb_entries) {
for (i = 1; i <= tone_nb_entries; i++) {
frequency_1 = tvb_get_ntohs(tvb, offset);
level_1 = (signed char)(tvb_get_guint8(tvb, offset + 2)) / 2;
frequency_2 = tvb_get_ntohs(tvb, offset + 3);
level_2 = (signed char)(tvb_get_guint8(tvb, offset + 5)) / 2;
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset, 6,
"Tone Pair %d: %d Hz at %d dB / %d Hz at %d dB",
i, frequency_1, level_1, frequency_2, level_2);
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 2,
"Frequency 1: %d Hz", frequency_1);
offset += 2;
length -= 2;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Level: %d dB", level_1);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 2, "Frequency 2: %d Hz", frequency_2);
offset += 2;
length -= 2;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Level: %d dB", level_2);
offset++;
length--;
}
}
break;
}
case 0x05:
{
guint8 ii, tone_nb_entries;
guint8 tone_direction, tone_id;
#if 0
guint8 tone_direction, tone_id, tone_duration tone_silence; */
#endif
int tone_duration;
static const value_string str_tone_direction[] = {
{0x00, "On The Phone"},
{0x40, "To The Network"},
{0x80, "On The Phone and To The Network"},
{0, NULL}
};
tone_direction = tvb_get_guint8(tvb, offset) & 0xC0;
tone_nb_entries = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Direction: %s - Number Of Entries: %d",
val_to_str_const(tone_direction, str_tone_direction, "Unknown"), tone_nb_entries);
offset++;
length--;
while (length > 0 && tone_nb_entries) {
for (ii = 0; ii < tone_nb_entries; ii++) {
tone_id = tvb_get_guint8(tvb, offset);
tone_duration = tvb_get_ntohs(tvb, offset + 1);
#if 0
tone_duration = tvb_get_guint8(tvb, offset + 1);
tone_silence = tvb_get_guint8(tvb, offset + 2);
#endif
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset, 6,
#if 0
"Tone Pair %d: Id: %d, Duration: %d ms, Silence: %d ms",
ii+1, tone_id, tone_duration, tone_silence);
#endif
"Tone Pair %d: Id: %d, Duration: %d ms",
ii+1, tone_id, tone_duration);
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Identification: %d", tone_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 2,
"Duration: %d ms", tone_duration);
offset += 2;
length -= 2;
#if 0
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Duration: %d ms", tone_duration);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Silence: %d ms", tone_silence);
offset++;
length--;
#endif
}
}
break;
}
case 0x07:
case 0x08:
{
emem_strbuf_t *strbuf;
int i, parameter_length, parameter_id;
static const value_string str_parameter_id[] = {
{0x00, "Remote IP Address "},
{0x01, "Remote UDP Port In "},
{0x02, "Remote UDP Port Out "},
{0x03, "Remote IP Address Out"},
{0x04, "Canal Number"},
{0, NULL}
};
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
case 0x03:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+1+i));
}
break;
}
case 0x01:
case 0x02:
case 0x04:
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
}
break;
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x09:
{
guint8 parameter;
static const value_string str_parameter[] = {
{0x00 , "Firmware Version"},
{0x01 , "Firmware Version"},
{0x02 , "DHCP IP Address"},
{0x03 , "Local IP Address"},
{0x04 , "Subnetwork Mask"},
{0x05 , "Router IP Address"},
{0x06 , "TFTP IP Address"},
{0x07 , "MainCPU IP Address"},
{0x08 , "Default Codec"},
{0x09 , "Ethernet Drivers Config"},
{0x0A , "MAC Address"},
{0, NULL}
};
static value_string_ext str_parameter_ext = VALUE_STRING_EXT_INIT(str_parameter);
while (length > 0) {
parameter = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
val_to_str_ext_const(parameter, &str_parameter_ext, "Unknown"));
offset++;
length--;
}
break;
}
case 0x0A:
{
emem_strbuf_t *strbuf;
int i, parameter_id, parameter_length;
static const value_string str_parameter_id[] = {
{0x00 , "QOS IP TOS"},
{0x01 , "QOS 8021 VLID"},
{0x02 , "QOS 8021 PRI"},
{0x03 , "SNMP MIB2 SysContact"},
{0x04 , "SNMP MIB2 SysName"},
{0x05 , "SNMP MIB2 SysLocation"},
{0x06 , "Default Compressor"},
{0x07 , "Error String Net Down"},
{0x08 , "Error String Cable PB"},
{0x09 , "Error String Try Connect"},
{0x0A , "Error String Connected"},
{0x0B , "Error String Reset"},
{0x0C , "Error String Duplicate IP Address"},
{0x0D , "SNMP MIB Community"},
{0x0E , "TFTP Backup Sec Mode"},
{0x0F , "TFTP Backup IP Address"},
{0x10 , "Set MMI Password"},
{0x11 , "Set PC Port Status"},
{0x12 , "Record RTP Authorization"},
{0x13 , "Security Flags"},
{0x14 , "ARP Spoofing"},
{0x15 , "Session Param"},
{0x30 , "MD5 Authentication"},
{0, NULL}
};
static value_string_ext str_parameter_id_ext = VALUE_STRING_EXT_INIT(str_parameter_id);
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
guint64 param_value = 0;
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x06:
{
static const value_string str_compressor[] = {
{0x00, "G.711 A-law"},
{0x01, "G.711 mu-law"},
{0x0F, "G.723.1 5.3kbps"},
{0x10, "G.723.1 6.3kbps"},
{0x11, "G.729A 8 kbps"},
{0, NULL}
};
ep_strbuf_append(strbuf, val_to_str_const(tvb_get_guint8(tvb, offset + 2),
str_compressor, "Default Codec"));
break;
}
case 0x07:
case 0x08:
case 0x09:
case 0x0A:
case 0x0B:
case 0x0C:
{
ep_strbuf_append(strbuf, "\"");
for (i = 1; i <= parameter_length; i++) {
if (isprint(tvb_get_guint8(tvb, offset + 1 + i)))
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
else
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
}
ep_strbuf_append(strbuf, "\"");
break;
}
case 0x0F:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+1+i));
}
break;
}
case 0x11:
{
static const value_string str_set_pc_port_status[] = {
{0x00, "No PC Port Security"},
{0x01, "Block PC Port"},
{0x02, "Filter VLAN"},
{0, NULL}
};
ep_strbuf_append(strbuf, val_to_str_const(tvb_get_guint8(tvb, offset + 2),
str_set_pc_port_status, "Unknown"));
break;
}
case 0x12:
{
static const value_string str_enable_feature[] = {
{0x00, "Disable Feature"},
{0x01, "Enable Feature"},
{0, NULL}
};
ep_strbuf_append(strbuf, val_to_str_const(tvb_get_guint8(tvb, offset + 2),
str_enable_feature, "Unknown"));
break;
}
case 0x13:
{
ep_strbuf_append(strbuf,
(tvb_get_guint8(tvb, offset + 2) & 0x01) ?
"Filtering Activated" : "Filtering Not Active");
break;
}
case 0x00:
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x0D:
case 0x0E:
case 0x10:
case 0x14:
case 0x15:
case 0x30:
default:
{
if ((parameter_length > 0) && (parameter_length <= 8)) {
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else if (parameter_length > 8) {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x0B:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Digit Value: %s",
val_to_str_ext_const(tvb_get_guint8(tvb, offset), &str_digit_ext, "Unknown"));
break;
}
case 0x0C:
case 0x0D:
{
emem_strbuf_t *strbuf;
int i, parameter_length, parameter_id;
static const value_string str_parameter_id[] = {
{0x14, "Canal Identifier"},
{0, NULL}
};
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_const(parameter_id, str_parameter_id, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x0E:
case 0x0F:
{
emem_strbuf_t *strbuf;
int i, parameter_length, parameter_id;
static const value_string str_parameter_id[] = {
{0x00 , "Recorder Index"},
{0x01 , "Remote IP Address"},
{0x02 , "Remote UDP Port In"},
{0x03 , "Remote UDP Port Out"},
{0x04 , "Remote IP Address Out"},
{0x05 , "Local UDP Port In"},
{0x06 , "Local UDP Port Out"},
{0x07 , "Type Of Service"},
{0x08 , "Master Key For SRTP Session"},
{0x09 , "Master Salt Key For SRTP Session"},
{0x30 , "MD5 Authentication"},
{0, NULL}
};
static value_string_ext str_parameter_id_ext = VALUE_STRING_EXT_INIT(str_parameter_id);
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x01:
case 0x04:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+1+i));
}
break;
}
case 0x00:
case 0x02:
case 0x03:
case 0x05:
case 0x06:
case 0x07:
case 0x08:
case 0x09:
case 0x30:
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
}
break;
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x06:
default:
{
break;
}
}
}
static void
decode_debug_in_line(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int i, parameter_length;
emem_strbuf_t *strbuf;
if (!ua3g_body_item)
return;
parameter_length = length;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
strbuf = ep_strbuf_new_label(NULL);
ep_strbuf_append(strbuf, "\"");
for (i = 0; i < parameter_length; i++) {
if (isprint(tvb_get_guint8(tvb, offset + i)))
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+i, NULL));
else
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+i, NULL));
}
ep_strbuf_append(strbuf, "\"");
proto_tree_add_text(ua3g_body_tree, tvb, offset, length,
"Text String With Debug: %s", strbuf->str);
}
static void
decode_led_command(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int command;
static const value_string str_command[] = {
{0x00, "Led Off"},
{0x01, "Led On"},
{0x02, "Red Led Fast Flash"},
{0x03, "Red Led Slow Flash"},
{0x04, "Green Led On"},
{0x05, "Green Led Fast Flash"},
{0x06, "Green Led Slow Flash"},
{0x07, "All Led Off"},
{0, NULL}
};
static value_string_ext str_command_ext = VALUE_STRING_EXT_INIT(str_command);
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, "s - %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
offset++;
length--;
if ((command >= 0) && (command < 7)) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Led Number: %d", tvb_get_guint8(tvb, offset));
}
}
static void
decode_lcd_line_cmd(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 lcd_options, command, column_n;
guint i;
proto_tree *ua3g_body_tree;
proto_item *ua3g_param_item;
proto_tree *ua3g_param_tree;
proto_item *ua3g_option_item;
proto_tree *ua3g_option_tree;
emem_strbuf_t *strbuf;
static const value_string str_command[] = {
{0, "Clear Line & Write From Column"},
{1, "Write From Column"},
{2, "Append To Current Line"},
{0, NULL}
};
static const value_string str_lcd_option[] = {
{7, "Suspend Display Refresh"},
{6, "Time Of Day Display "},
{5, "Call Timer Display "},
{4, "Call Timer Control "},
{2, "Blink "},
{0, NULL}
};
static const value_string str_call_timer_ctrl[] = {
{0x00, "Call Timer Status Not Changed"},
{0x01, "Stop Call Timer"},
{0x02, "Start Call Timer From Current Value"},
{0x03, "Initialize And Call Timer"},
{0, NULL}
};
lcd_options = tvb_get_guint8(tvb, offset) & 0xFC;
command = tvb_get_guint8(tvb, offset) & 0x03;
column_n = tvb_get_guint8(tvb, offset + 1);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s %d",
val_to_str_const(command, str_command, "Unknown"),
column_n);
if (!ua3g_body_item)
return;
strbuf = ep_strbuf_new_label(NULL);
proto_item_append_text(ua3g_item, ", %s %d",
val_to_str_const(command, str_command, "Unknown"),
column_n);
proto_item_append_text(ua3g_body_item, " %s %d",
val_to_str_const(command, str_command, "Unknown"),
column_n);
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
ep_strbuf_append(strbuf, "\"");
for (i = 0; i < length - 2; i++) {
if (isprint(tvb_get_guint8(tvb, offset + 2 + i)))
ep_strbuf_append_printf(strbuf, "%c", tvb_get_guint8(tvb, offset + 2 + i));
else
ep_strbuf_append_printf(strbuf, "'0x%02x'", tvb_get_guint8(tvb, offset + 2 + i));
}
ep_strbuf_append(strbuf, "\"");
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
length, "%s %d: %s",
val_to_str_const(command, str_command, "Unknown"), column_n, strbuf->str);
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
val_to_str_const(command, str_command, "Unknown"));
ua3g_option_item = proto_tree_add_text(ua3g_param_tree, tvb, offset,
1, "LCD Options: 0x%x", lcd_options);
ua3g_option_tree = proto_item_add_subtree(ua3g_option_item, ett_ua3g_option);
for (i = 2; i <= 7; i++) {
if (i != 3) {
proto_tree_add_text(ua3g_option_tree, tvb, offset, 1, "%s: %s",
val_to_str_const(i, str_lcd_option, "Unknown"),
(lcd_options & (1 << i)) ? "Enable" : "Disable");
} else {
i++;
proto_tree_add_text(ua3g_option_tree, tvb, offset, 1, "%s: %s",
val_to_str_const(i, str_lcd_option, "Unknown"),
val_to_str_const((lcd_options >> 3) & 0x03, str_call_timer_ctrl, "Unknown"));
}
}
offset++;
length--;
if (command != 3)
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Starting Column: %d", column_n);
else
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Unused");
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, length, "ASCII Char: %s", strbuf->str);
}
static void
decode_main_voice_mode(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 mode;
proto_tree *ua3g_body_tree;
static const value_string str_voice_mode[] = {
{0x00, "Idle"},
{0x01, "Handset"},
{0x02, "Group Listening"},
{0x03, "On Hook Dial"},
{0x04, "Handsfree"},
{0x05, "Announce Loudspeaker"},
{0x06, "Ringing"},
{0x10, "Idle"},
{0x11, "Handset"},
{0x12, "Headset"},
{0x13, "Handsfree"},
{0, NULL}
};
static value_string_ext str_voice_mode_ext = VALUE_STRING_EXT_INIT(str_voice_mode);
mode = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(mode, &str_voice_mode_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(mode, &str_voice_mode_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_ext_const(mode, &str_voice_mode_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, mode, "Voice Mode: %s",
val_to_str_ext_const(mode, &str_voice_mode_ext, "Unknown"));
offset++;
length--;
switch (mode) {
case 0x06:
{
static const value_string str_cadence[] = {
{0x00, "Standard Ringing"},
{0x01, "Double Burst"},
{0x02, "Triple Burst"},
{0x03, "Continuous Ringing"},
{0x04, "Priority Attendant Ringing"},
{0x05, "Regular Attendant Ringing"},
{0x06, "Programmable Cadence"},
{0x07, "Programmable Cadence"},
{0, NULL}
};
static value_string_ext str_cadence_ext = VALUE_STRING_EXT_INIT(str_cadence);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Tune: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Cadence: %s (%d)",
val_to_str_ext_const(tvb_get_guint8(tvb, offset), &str_cadence_ext, "Unknown"),
tvb_get_guint8(tvb, offset));
offset++;
length--;
}
case 0x02:
case 0x03:
case 0x04:
case 0x05:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Speaker Volume: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
if (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "Microphone Volume: %d",
tvb_get_guint8(tvb, offset));
}
break;
}
case 0x11:
case 0x12:
case 0x13:
{
signed char level;
static const value_string str_receiving_level[] = {
{0x11, "Receiving Level "},
{0x12, "Receiving Level "},
{0x13, "Speaker Level "},
{0, NULL}
};
level = (signed char)(tvb_get_guint8(tvb, offset)) / 2;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"%s: %d dB",
val_to_str_const(mode, str_receiving_level, "Unknown"), level);
offset++;
length--;
level = (signed char)(tvb_get_guint8(tvb, offset)) / 2;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Sending Level: %d dB", level);
break;
}
case 0x00:
case 0x01:
case 0x10:
default:
{
break;
}
}
}
static void
decode_subdevice_metastate(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_new_metastate[] = {
{0x00, "Disable"},
{0x01, "Active"},
{0x02, "Wake Up"},
{0, NULL}
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subchannel Address: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "New Metastate: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_new_metastate, "Unknown"));
}
static void
decode_dwl_dtmf_clck_format(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_clock_format[] = {
{0, "Europe"},
{1, "US"},
{0, NULL}
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Minimum 'ON' Time: %d ms", (tvb_get_guint8(tvb, offset) * 10));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Inter-Digit Pause Time: %d ms",
(tvb_get_guint8(tvb, offset) * 10));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Clock Time Format: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_clock_format, "Unknown"));
offset++;
length--;
if (length > 0)
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"DTMF Country Adaptation: %d", tvb_get_guint8(tvb, offset));
}
static void
decode_set_clck(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
proto_item *ua3g_param_item;
proto_tree *ua3g_param_tree;
int hour, minute, second, call_timer;
static const value_string str_command[] = {
{0x00, "Set Current Time/Call Timer"},
{0x01, "Set Current Time"},
{0x02, "Set Call Timer"},
{0, NULL}
};
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(command, str_command, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_const(command, str_command, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_const(command, str_command, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
val_to_str_const(command, str_command, "Unknown"));
offset++;
length--;
call_timer = 0;
switch (command) {
case 0x02:
{
call_timer = 1;
}
case 0x00:
case 0x01:
{
static const value_string str_call_timer[] = {
{1, "Call Timer "},
{0, NULL}
};
while (length > 0) {
hour = tvb_get_guint8(tvb, offset);
minute = tvb_get_guint8(tvb, offset + 1);
second = tvb_get_guint8(tvb, offset + 2);
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset, 3,
"%s: %d:%d:%d",
val_to_str_const(call_timer, str_call_timer, "Current Time"), hour, minute, second);
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "%sHour: %d",
val_to_str_const(call_timer, str_call_timer, ""), hour);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "%sMinute: %d",
val_to_str_const(call_timer, str_call_timer, ""), minute);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "%sSecond: %d",
val_to_str_const(call_timer, str_call_timer, ""), second);
offset++;
length--;
call_timer = 1;
}
}
default:
{
break;
}
}
}
static void
decode_voice_channel(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_voice_channel[] = {
{0x00, "No"},
{0x01, "B1"},
{0x02, "B2"},
{0x03, "B3"},
{0, NULL}
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
if (length == 1) {
guint8 val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
(val & 0x01) ? "Write 00 to Voice Channel" : "Normal Voice Channel Mode");
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
(val & 0x02) ? "Write Quiet To Codec" : "Normal Codec Operation");
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
(val & 0x04) ? "Use B3 As Voice Channel" : "Use B1 As Voice Channel");
offset++;
length--;
} else if (length == 2) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Main Voice: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_voice_channel, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Announce: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_voice_channel, "Unknown"));
offset++;
length--;
} else if (length == 4) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "B General: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "B Loud Speaker: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "B Ear Piece: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "B Microphones: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
static void
decode_external_ringing(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length _U_, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
guint8 command;
static const value_string str_ext_ring_cmd[] = {
{0x00, "Turn Off"},
{0x01, "Turn On"},
{0x02, "Follow The Normal Ringing"},
{0, NULL}
};
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(command, str_ext_ring_cmd, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_const(command, str_ext_ring_cmd, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_const(command, str_ext_ring_cmd, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "External Ringing Command: %s",
val_to_str_const(command, str_ext_ring_cmd, "Unknown"));
}
static void
decode_lcd_cursor(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
guint8 str_on_off_val;
str_on_off_val = tvb_get_guint8(tvb, offset + 1) & 0x02;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
STR_ON_OFF(str_on_off_val));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
STR_ON_OFF(str_on_off_val));
proto_item_append_text(ua3g_body_item, " - %s",
STR_ON_OFF(str_on_off_val));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Line Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "Cursor %s",
STR_ON_OFF(tvb_get_guint8(tvb, offset) & 0x02));
}
static void
decode_dwl_special_char(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int i, j;
emem_strbuf_t *strbuf;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Character Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
for (i = 1; i <= 8; i++) {
int byte = tvb_get_guint8(tvb, offset);
ep_strbuf_truncate(strbuf, 0);
for (j = 7; j >= 0; j--) {
if (((byte >> j) & 0x01) == 0)
ep_strbuf_append_printf(strbuf, " ");
else
ep_strbuf_append_printf(strbuf, "o ");
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Byte %d: 0x%02x %s", i, byte, strbuf->str);
offset++;
length--;
}
}
}
static void
decode_set_clck_timer_pos(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Clock Line Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Clock Column Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Call Timer Line Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Call Timer Column Number: %d", tvb_get_guint8(tvb, offset));
}
static void
decode_set_lcd_contrast(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
static const value_string str_driver_number[] = {
{0x00, "Display"},
{0x01, "Icon"},
{0, NULL}
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Driver Number: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_driver_number, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Contrast Value: %d", tvb_get_guint8(tvb, offset));
}
static void
decode_beep(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
if (length > 0) {
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_command[] = {
{0x01, "Beep Once"},
{0x02, "Beep Start"},
{0x03, "Stop Beep"},
{0x04, "Start Beep"},
{0x05, "Define Beep"},
{0, NULL}
};
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(command, str_command, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_const(command, str_command, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_const(command, str_command, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb,
offset, 1, command, "Beep: %s",
val_to_str_const(command, str_command, "Unknown"));
offset++;
length--;
switch (command) {
case 0x01:
case 0x02:
{
int i = 0;
static const value_string str_destination[] = {
{0x01, "Ear-Piece"},
{0x02, "Loudspeaker"},
{0x03, "Ear-Piece and Loudspeaker"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Destination: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_destination, "Unknown"));
offset++;
length--;
while (length > 0) {
guint8 val;
i++;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "On / Off: %s",
STR_ON_OFF(val & 0x80));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Cadence T%d: %d ms",
i, ((val & 0x7F) * 10));
offset++;
length--;
}
break;
}
case 0x04:
{
guint8 beep_dest;
emem_strbuf_t *strbuf;
int i;
static const value_string str_destination[] = {
{0x01, "Handset"},
{0x02, "Headset"},
{0x04, "Loudspeaker"},
{0x08, "Announce Loudspeaker"},
{0x10, "Handsfree"},
{0, NULL}
};
beep_dest = tvb_get_guint8(tvb, offset);
strbuf = ep_strbuf_new_label(NULL);
for (i = 0; i < 5; i++) {
ep_strbuf_append(strbuf,
val_to_str_const(beep_dest & (0x01 << i), str_destination, ""));
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Destination: %s", strbuf->str);
offset++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Beep Number: %x", tvb_get_guint8(tvb, offset));
break;
}
case 0x05:
{
int i, nb_of_notes, beep_number;
static const value_string str_freq_sample_nb[] = {
{0x00, "Frequency"},
{0xFF, "Audio Sample Number"},
{0, NULL}
};
static const value_string str_duration[] = {
{0x00, "Duration "},
{0xFF, "Duration (Ignored)"},
{0, NULL}
};
static const value_string str_terminator[] = {
{0xFD, "Stop"},
{0xFE, "Loop"},
{0xFF, "Infinite"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Beep Number: %x", beep_number = tvb_get_guint8(tvb, offset));
offset++;
length--;
if (beep_number <= 0x44)
beep_number = 0x00;
else
beep_number = 0xFF;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Number Of Notes: %x", nb_of_notes = tvb_get_guint8(tvb, offset));
offset++;
length--;
while (length > 0) {
for (i = 1; i <= nb_of_notes; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s %d: %d",
val_to_str_const(beep_number, str_freq_sample_nb, "Unknown"),
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Level %d: %d",
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s %d: %x",
val_to_str_const(beep_number, str_duration, "Unknown"),
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Terminator: %d (%s)",
tvb_get_guint8(tvb, offset),
val_to_str_const(tvb_get_guint8(tvb, offset), str_terminator, "Unknown"));
offset++;
length--;
}
break;
}
case 0x03:
default:
{
break;
}
}
} else {
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": Classical Beep");
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", Classical Beep");
proto_item_append_text(ua3g_body_item, " - Classical Beep");
}
}
static void
decode_sidetone(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length _U_, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
STR_ON_OFF(command));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
STR_ON_OFF(command));
proto_item_append_text(ua3g_body_item, " - %s",
STR_ON_OFF(command));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
STR_ON_OFF(command));
offset++;
if (command == 0x01) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Level: %d dB",
(signed char)(tvb_get_guint8(tvb, offset) / 2));
}
}
static void
decode_ringing_cadence(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int i = 0;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Cadence: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
while (length > 0) {
i++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "On / Off : %s",
STR_ON_OFF(tvb_get_guint8(tvb, offset) & 0x80));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Length %d : %d ms",
i, ((tvb_get_guint8(tvb, offset) & 0x7F) * 10));
offset++;
length--;
}
}
static void
decode_mute(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length _U_, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_mute[] = {
{0x00, "Microphone Disable"},
{0x01, "Microphone Enable"},
{0, NULL}
};
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(command, str_mute, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_const(command, str_mute, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_const(command, str_mute, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "%s",
val_to_str_const(command, str_mute, "Unknown"));
}
static void
decode_feedback(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
STR_ON_OFF(command));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
STR_ON_OFF(command));
proto_item_append_text(ua3g_body_item, " - %s",
STR_ON_OFF(command));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
STR_ON_OFF(command));
offset++;
length--;
if (command == 0x01) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Level: %d dB",
(signed char)(tvb_get_guint8(tvb, offset) / 2));
offset++;
length--;
if (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Duration: %d ms",
(tvb_get_guint8(tvb, offset) * 10));
}
}
}
static void
decode_r_w_peripheral(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2, "Address: %d",
tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
if (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Content: %d", tvb_get_guint8(tvb, offset));
}
}
static void
decode_icon_cmd(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
guint8 byte0, byte1, bytex;
int i;
static const value_string str_state[] = {
{0x00, "Off"},
{0x01, "Slow Flash"},
{0x02, "Not Used"},
{0x03, "Steady On"},
{0, NULL}
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Icon Number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
byte0 = tvb_get_guint8(tvb, offset);
byte1 = tvb_get_guint8(tvb, offset+1);
for (i = 0; i < 8; i++) {
bytex =
((byte0 >> i) & 0x01) * 2 +
((byte1 >> i) & 0x01);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Segment %d: %s (%d)", i,
val_to_str_const(bytex, str_state, "Unknown"),
bytex
);
}
}
static void
decode_audio_config(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_command[] = {
{0x00, "Audio Coding"},
{0x01, "DPI Channel Allocations"},
{0x02, "Loudspeaker Volume Adjust"},
{0x03, "Audio Circuit Configuration"},
{0x04, "Handsfree Parameters"},
{0x05, "Loudspeaker Acoustic Parameters"},
{0x06, "Device Configuration"},
{0, NULL}
};
static value_string_ext str_command_ext = VALUE_STRING_EXT_INIT(str_command);
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb,
offset, 1, command, "Command: %s (%d)",
val_to_str_ext_const(command, &str_command_ext, "Unknown"), command);
offset++;
length--;
switch (command) {
case 0x00:
{
static const value_string str_law[] = {
{0x00, "A Law"},
{0x01, "m Law"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "Ignored: %d",
tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "Law: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_law, "Unknown"));
break;
}
case 0x01:
{
int i;
static const gchar *str_body[] = {
"UA Channel UA-TX1 ",
"UA Channel UA-TX2 ",
"GCI Channel GCI-TX1 ",
"GCI Channel GCI-TX2 ",
"Codec Channel COD-TX"
};
for (i = 0; i < 5; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "%s: %d",
str_body[i], tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x02:
{
int i;
for (i = 1; i < 8; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "Volume Level %d: %d",
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x03:
{
int i;
static const gchar *str_body[] = {
"Anti-Distortion Coeff 1(DTH)",
"Anti-Distortion Coeff 2(DTR)",
"Anti-Distortion Coeff 3(DTF)",
"Sidetone Attenuation (STR) ",
"Anti-Larsen Coeff 1 (AHP1) ",
"Anti-Larsen Coeff 2 (AHP2) ",
"Anti-Larsen Coeff 3 (ATH) ",
"Anti-Larsen Coeff 4 (ATR) ",
"Anti-Larsen Coeff 5 (ATF) ",
"Anti-Larsen Coeff 6 (ALM) "
};
for (i = 0; i < 10; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "%s: %d",
str_body[i], tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x04:
{
guint8 val;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
(val & 0x01) ? "Return Loss Active" : "Return Loss Normal");
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s",
(val & 0x02) ? "More Full Duplex" : "Handsfree Normal");
break;
}
case 0x05:
{
int i;
static const gchar *str_body[] = {
"Group Listening Attenuation Constant ",
"Handsfree Attenuation Constant ",
"Handsfree Number Of ms To Stay In Send State Before Going To Another State",
"Handsfree Number Of Positions To Shift Right MTx ",
"Handsfree Number Of Positions To Shift Right MRc ",
"Handsfree Idle Transmission Threshold ",
"Handsfree Low Transmission Threshold ",
"Handsfree Idle Reception Threshold ",
"Handsfree Low Reception Threshold ",
"Handsfree Medium Reception Threshold ",
"Handsfree High Reception Threshold "
};
for (i = 0; i < 11; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s: %d",
str_body[i], tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x06:
{
static const value_string str_device[] = {
{ 0, "Handset Device "},
{ 1, "Headset Device "},
{ 2, "Loudspeaker Device "},
{ 3, "Announce Loudspeaker Device"},
{ 4, "Handsfree Device "},
{ 0, NULL }
};
static value_string_ext str_device_ext = VALUE_STRING_EXT_INIT(str_device);
static const gchar *str_device_values[] = {
" Internal",
" Rj9 Plug",
" Jack Plug",
" Bluetooth Link",
" USB Link"
};
emem_strbuf_t *strbuf;
guint8 device_values;
int j;
int device_index = 0;
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
device_values = tvb_get_guint8(tvb, offset);
ep_strbuf_truncate(strbuf, 0);
if (device_values != 0) {
for (j = 0; j < 5; j++) {
if (device_values & (0x01 << j)) {
ep_strbuf_append(strbuf, str_device_values[j]);
}
}
} else {
ep_strbuf_append(strbuf, " None");
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"%s:%s",
val_to_str_ext_const(device_index, &str_device_ext, "Unknown"),
strbuf->str);
offset++;
length--;
device_index++;
}
break;
}
default:
{
break;
}
}
}
static void
decode_audio_padded_path(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Emission Padded Level: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Reception Padded Level: %d", tvb_get_guint8(tvb, offset));
}
static void
decode_on_off_level(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
STR_ON_OFF(command));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
STR_ON_OFF(command));
proto_item_append_text(ua3g_body_item, " - %s",
STR_ON_OFF(command));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
STR_ON_OFF(command));
offset++;
length--;
if (length > 0) {
if (command == 0x01) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Level on Loudspeaker: %d dB",
(signed char)(tvb_get_guint8(tvb, offset)));
}
}
}
static void
decode_ring(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_cadence[] = {
{0x00, "Standard Ringing"},
{0x01, "Double Burst"},
{0x02, "Triple Burst"},
{0x03, "Continuous"},
{0x04, "Priority Attendant Ringing"},
{0x05, "Regular Attendant Ringing"},
{0x06, "Programmable Cadence"},
{0, NULL}
};
static value_string_ext str_cadence_ext = VALUE_STRING_EXT_INIT(str_cadence);
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
STR_ON_OFF(command));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
STR_ON_OFF(command));
proto_item_append_text(ua3g_body_item, " - %s",
STR_ON_OFF(command));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb, offset,
1, command, "Command: %s",
STR_ON_OFF(command));
offset++;
length--;
if (command == 0x01) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Melody: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Cadence: %s",
val_to_str_ext_const(tvb_get_guint8(tvb, offset), &str_cadence_ext, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Speaker level: %d dB",
(signed char)(tvb_get_guint8(tvb, offset)));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Beep number: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Silent: %s",
STR_ON_OFF(tvb_get_guint8(tvb, offset) & 0x80));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Progressive: %d",
(tvb_get_guint8(tvb, offset) & 0x03));
}
}
static void
decode_ua_dwl_protocol(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_command[] = {
{0x00, "Downloading Suggest"},
{0x01, "Downloading Request"},
{0x02, "Downloading Acknowledge"},
{0x03, "Downloading Data"},
{0x04, "Downloading End"},
{0x05, "Downloading End Acknowledge"},
{0x06, "Downloading ISO Checksum"},
{0x07, "Downloading ISO Checksum Acknowledge"},
{0, NULL}
};
static value_string_ext str_command_ext = VALUE_STRING_EXT_INIT(str_command);
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb,
offset, 1, command, "Command: %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
offset++;
length--;
switch (command) {
case 0x00:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Item Identifier: %d", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Item Version: %s",
version_number_computer(tvb_get_letohs(tvb, offset)));
offset += 2;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Cause: %d", tvb_get_guint8(tvb, offset));
break;
}
case 0x01:
{
static const value_string str_force_mode[] = {
{0x00, "System Accept All Refusals"},
{0x01, "Force Software Lock"},
{0, NULL}
};
static const value_string str_item_id[] = {
{0x00, "Patches File"},
{0x01, "Application Binary"},
{0x02, "Datas Binary"},
{0, NULL}
};
static const value_string str_mode_selection_country[] = {
{0x00, "No Check"},
{0x01, "For All Countries Except Chinese"},
{0x02, "For Chinese"},
{0, NULL}
};
static const gchar *str_mem_size[] = {
"No Check",
"128 Kbytes",
"256 Kbytes",
"512 Kbytes",
"1 Mbytes",
"2 Mbytes",
"4 Mbytes",
"8 Mbytes"
};
static const gchar *str_bin_info[] = {
"Uncompressed Binary",
"LZO Compressed Binary"
};
if (length > 7) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Force Mode: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_force_mode, "Unknown"));
offset++;
length--;
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Item Identifier: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_item_id, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Item Version: %d", tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
if (length > 2) {
guint8 val;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Files Included: %sBoot Binary Included, %sLoader Binary Included,"
" %sAppli Binary Included, %sDatas Binary Included",
(val & 0x01) ? "" : "No ",
(val & 0x02) ? "" : "No ",
(val & 0x04) ? "" : "No ",
(val & 0x08) ? "" : "No ");
offset++;
length--;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Model Selection: For A Model: %s, For B Model: %s, For C Model %s, Country Version: %s",
STR_YES_NO(val & 0x01),
STR_YES_NO(val & 0x02),
STR_YES_NO(val & 0x04),
val_to_str_const(((tvb_get_guint8(tvb, offset) & 0xE0) >> 5), str_mode_selection_country, "Unknown"));
offset++;
length--;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hardware Selection: For Ivanoe 1: %s, For Ivanoe 2: %s",
STR_YES_NO(val & 0x01),
STR_YES_NO(val & 0x02));
offset++;
length--;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Memory Sizes Required: Flash Min Size: %s, External Ram Min Size: %s",
str_mem_size[(val & 0x07)],
str_mem_size[(val & 0x38) >> 3]);
offset++;
length--;
} else {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Binary Information: %s, Country/Operator/CLient Identifier ?",
str_bin_info[tvb_get_guint8(tvb, offset) & 0x01]);
offset++;
length--;
}
proto_tree_add_text(ua3g_body_tree, tvb, offset, 3,
"Binary Length: %d", tvb_get_ntoh24(tvb, offset));
break;
}
case 0x02:
{
static const value_string str_status[] = {
{0x00, "Ok (Binary Item Downloading In \"Normal\" Progress)"},
{0x01, "Hardware Failure: Flash Failure"},
{0x02, "Not Enough Place To Store The Downloaded Binary"},
{0x03, "Wrong Seq Number On Latest Received Download_Data Message"},
{0x04, "Wrong Packet Number On Latest Received Download_Data Message"},
{0x05, "Download Refusal Terminal (Validation Purpose)"},
{0x06, "Download Refusal Terminal (Development Purpose)"},
{0x10, "Download Refusal: Hardware Cause (Unknown Flash Device, Incompatible Hardware)"},
{0x11, "Download Refusal: No Loader Available Into The Terminal"},
{0x12, "Download Refusal: Software Lock"},
{0x13, "Download Refusal: Wrong Parameter Into Download Request"},
{0x20, "Wrong Packet Number On Latest Received Downloading_Data Message"},
{0x21, "Compress Header Invalid"},
{0x22, "Decompress Error"},
{0x23, "Binary Header Invalid"},
{0x24, "Binary Check Error: Flash Write Error Or Binary Is Invalid"},
{0x25, "Error Already Signaled - No More Data Accepted"},
{0x26, "No Downloading In Progress"},
{0x27, "Too Many Bytes Received (More Than Size Given Into The Download_Req Message)"},
{0xFF, "Undefined Error"},
{0, NULL}
};
static value_string_ext str_status_ext = VALUE_STRING_EXT_INIT(str_status);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Packet Number: %d", tvb_get_ntohs(tvb, offset));
offset += 2;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Status: %s",
val_to_str_ext_const(tvb_get_guint8(tvb, offset), &str_status_ext, "Unknown"));
break;
}
case 0x03:
{
int i = 1;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Packet Number: %d", tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
while (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Packet Number %3d: %d", i, tvb_get_guint8(tvb, offset));
offset++;
length--;
i++;
}
break;
}
case 0x05:
{
static const value_string str_ok[] = {
{0x00, "Ok"},
{0x01, "Hardware Failure: Flash Problems"},
{0x02, "Not Enough Place To Store The Downloaded Binary"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Status: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_ok, "Not Ok"));
break;
}
case 0x06:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 4,
"Checksum: %d", tvb_get_ntohl(tvb, offset));
break;
}
case 0x07:
{
static const value_string str_ack_status[] = {
{0x00, "The Checksum Matches"},
{0x25, "Error Detected And Already Signaled"},
{0x30, "Checksum Error (All Bytes Received)"},
{0x31, "Checksum Error (Bytes Missing)"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Acknowledge: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_ack_status, "Unknown"));
break;
}
case 0x04:
default:
{
break;
}
}
}
static void
decode_digit_dialed(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length _U_, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Digit Value: %s",
val_to_str_ext_const(tvb_get_guint8(tvb, offset), &str_digit_ext, "Unknown"));
}
static void
decode_subdevice_msg(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
int i = 0;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdev Type: %d", (tvb_get_guint8(tvb, offset) & 0xF0));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdev Address: %d", (tvb_get_guint8(tvb, offset) & 0x0F));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice Opcode: %d", (tvb_get_guint8(tvb, offset) & 0x7F));
offset++;
length--;
while (length > 0) {
i++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Parameter Byte %2d: %d", i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
static void
decode_cs_ip_device_routing(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo, guint offset, guint length,
guint8 opcode _U_, proto_item *ua3g_item,
proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
proto_item *ua3g_param_item;
proto_tree *ua3g_param_tree;
static const value_string str_command[] = {
{0x00, "Init"},
{0x01, "Incident"},
{0x02, "Get Parameters Value Response"},
{0x03, "QOS Ticket RSP"},
{0, NULL}
};
command = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(command, str_command, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_const(command, str_command, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_const(command, str_command, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip, tvb, offset,
1, command, "Command: %s",
val_to_str_const(command, str_command, "Unknown"));
offset++;
length--;
switch (command) {
case 0x00:
{
static const value_string str_vta_type[] = {
{0x20, "NOE A"},
{0x21, "NOE B"},
{0x22, "NOE C"},
{0x23, "NOE D"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "VTA Type: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_vta_type, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset,
1, "Characteristic Number: %d", tvb_get_guint8(tvb, offset));
break;
}
case 0x01:
{
int i = 0;
if (length == 1) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Incident 0: %d", tvb_get_guint8(tvb, offset));
} else {
while (length >0) {
i++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Parameter %d Identifier: %d",
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
break;
}
case 0x02:
{
emem_strbuf_t *strbuf;
int i, parameter_id, parameter_length;
static const value_string str_parameter_id[] = {
{0x00, "Firmware Version"},
{0x01, "Firmware Version"},
{0x02, "DHCP IP Address"},
{0x03, "Local IP Address"},
{0x04, "Subnetwork Mask"},
{0x05, "Router IP Address"},
{0x06, "TFTP IP Address"},
{0x07, "Main CPU Address"},
{0x08, "Default Codec"},
{0x09, "Ethernet Drivers Config"},
{0x0A, "MAC Address"},
{0, NULL}
};
static value_string_ext str_parameter_id_ext = VALUE_STRING_EXT_INIT(str_parameter_id);
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
{
ep_strbuf_append_printf(strbuf, "%s",
version_number_computer(tvb_get_ntohs(tvb, offset + 2)));
break;
}
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+1+i));
}
break;
}
case 0x08:
{
static const value_string str_compressor[] = {
{0x00, "G.711 A-law"},
{0x01, "G.711 mu-law"},
{0x0F, "G.723.1 5.3kbps"},
{0x10, "G.723.1 6.3kbps"},
{0x11, "G.729A 8 kbps"},
{0, NULL}
};
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf,
val_to_str_const((guint8)(param_value), str_compressor, "Default Codec"));
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x09:
{
if (parameter_length == 2) {
ep_strbuf_append_printf(strbuf,
"Port Lan Speed: %d - Port Lan Duplex: %d",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3));
} else if (parameter_length == 4) {
ep_strbuf_append_printf(strbuf,
"Port Lan Speed: %d - Port Lan Duplex: %d - Port PC Speed: %d - Port PC Duplex: %d",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 4),
tvb_get_guint8(tvb, offset + 5));
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
break;
}
case 0x0A:
{
ep_strbuf_append_printf(strbuf, "%02x", tvb_get_guint8(tvb, offset + 2));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ":");
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+1+i, NULL));
}
break;
}
default:
{
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 1 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
} else {
ep_strbuf_append_printf(strbuf, "0x%02x 0x%02x ... 0x%02x 0x%02x",
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + parameter_length),
tvb_get_guint8(tvb, offset + 1 + parameter_length));
}
}
break;
}
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s: %s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 2, "%s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Length: %d", parameter_length);
offset++;
length--;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x03:
{
emem_strbuf_t *strbuf;
int i, parameter_id, parameter_length;
int element_length = 1;
int framing_rtp = 0;
#define PVT_ROWS 15
#define PVT_COLS 50
char parameter_value_tab[PVT_ROWS][PVT_COLS];
static const value_string str_parameter_id[] = {
{0x01, "Date Of End Of Communication"},
{0x02, "Node Number"},
{0x03, "Ticket Protocol Version"},
{0x06, "Equipment Type"},
{0x08, "Local IP Address"},
{0x09, "Distant IP Address"},
{0x0A, "Local ID"},
{0x0B, "Distant ID"},
{0x0C, "Call Duration (second)"},
{0x0D, "Local SSRC"},
{0x0E, "Distant SSRC"},
{0x0F, "Codec"},
{0x10, "VAD"},
{0x11, "ECE"},
{0x12, "Voice Mode"},
{0x13, "Transmitted Framing (ms)"},
{0x14, "Received Framing (ms)"},
{0x15, "Framing Changes"},
{0x16, "Number Of RTP Packets Received"},
{0x17, "Number Of RTP Packets Sent"},
{0x18, "Number Of RTP Packets Lost"},
{0x19, "Total Silence Detected (second)"},
{0x1A, "Number Of SID Received"},
{0x1B, "Delay Distribution"},
{0x1C, "Maximum Delay (ms)"},
{0x1D, "Number Of DTMF Received"},
{0x1E, "Consecutive BFI"},
{0x1F, "BFI Distribution"},
{0x20, "Jitter Depth Distribution"},
{0x21, "Number Of ICMP Host Unreachable"},
{0x26, "Firmware Version"},
{0x29, "DSP Framing (ms)"},
{0x2A, "Transmitter SID"},
{0x2D, "Minimum Delay (ms)"},
{0x2E, "802.1 Q Used"},
{0x2F, "802.1p Priority"},
{0x30, "VLAN Id"},
{0x31, "DiffServ"},
{0x3D, "200 ms BFI Distribution"},
{0x3E, "Consecutive RTP Lost"},
{0, NULL}
};
static value_string_ext str_parameter_id_ext = VALUE_STRING_EXT_INIT(str_parameter_id);
static const value_string str_parameter_id_tab[] = {
{0x1B, "Range: Value"},
{0x1F, "Range: Value"},
{0x20, "Jitter: Value"},
{0x3D, "Contents: Value"},
{0x3E, "Contents: Value"},
{0, NULL}
};
strbuf = ep_strbuf_new_label(NULL);
while (length > 0) {
ep_strbuf_truncate(strbuf, 0);
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_ntohs(tvb, offset + 1);
if (parameter_length > 0) {
switch (parameter_id) {
case 0x06:
{
static const value_string str_first_byte[] = {
{0x01, "IP-Phone"},
{0x02, "Appli-PC"},
{0x03, "Coupler OmniPCX Enterprise"},
{0x04, "Coupler OmniPCX Office"},
{0, NULL}
};
static const value_string str_second_byte[] = {
{0x0101, "IP-Phone V2"},
{0x0102, "NOE-IP"},
{0x0200, "4980 Softphone (PCMM2)"},
{0x0201, "WebSoftphoneIP"},
{0x0300, "INTIP"},
{0x0301, "GD"},
{0x0302, "eVA"},
{0, NULL}
};
ep_strbuf_append_printf(strbuf, "%s, %s",
val_to_str_const(tvb_get_guint8(tvb, offset + 3), str_first_byte, "Unknown"),
val_to_str_const(tvb_get_ntohs(tvb, offset + 3), str_second_byte, "Unknown"));
break;
}
case 0x08:
case 0x09:
case 0x26:
{
ep_strbuf_append_printf(strbuf, "%d", tvb_get_guint8(tvb, offset + 3));
for (i = 2; i <= parameter_length; i++) {
ep_strbuf_append(strbuf, ".");
ep_strbuf_append_printf(strbuf, "%u", tvb_get_guint8(tvb, offset+2+i));
}
break;
}
case 0x0A:
case 0x0B:
{
ep_strbuf_append(strbuf, "\"");
for (i = 1; i <= parameter_length; i++) {
if (isprint(tvb_get_guint8(tvb, offset + 2 + i)))
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+2+i, NULL));
else
ep_strbuf_append(strbuf, tvb_get_const_stringz(tvb, offset+2+i, NULL));
}
ep_strbuf_append(strbuf, "\"");
break;
}
case 0x0F:
{
static const value_string str_compressor[] = {
{0x00, "G.711 A-law"},
{0x01, "G.711 mu-law"},
{0x02, "G.723.1 6.3kbps"},
{0x03, "G.729"},
{0x04, "G.723.1 5.3kbps"},
{0, NULL}
};
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 2 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf,
val_to_str_const((guint8)(param_value), str_compressor, "Default Codec"));
} else {
ep_strbuf_append(strbuf, "Parameter Value Too Long (more than 64 bits)");
}
break;
}
case 0x10:
case 0x11:
{
ep_strbuf_append_printf(strbuf, "%s",
STR_ON_OFF(tvb_get_guint8(tvb, offset + 3)));
break;
}
case 0x12:
{
static const value_string str_voice_mode[] = {
{0x50, "Idle"},
{0x51, "Handset"},
{0x52, "Group Listening"},
{0x53, "On Hook Dial"},
{0x54, "Handsfree"},
{0x55, "Headset"},
{0, NULL}
};
if (parameter_length <= 8) {
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 2 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append(strbuf,
val_to_str_const((guint8)(param_value), str_voice_mode, "Unknown"));
} else {
ep_strbuf_append(strbuf, "Parameter Value Too Long (more than 64 bits)");
}
break;
}
case 0x1B:
{
static const value_string str_range[] = {
{0, "0-40 "},
{1, "40-80 "},
{2, "80-150 "},
{3, "150-250 "},
{4, "250 and +"},
{0, NULL}
};
element_length = 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "%s: %d",
val_to_str_const(i, str_range, "Unknown"),
tvb_get_ntohs(tvb, offset + 3 + element_length * i));
}
break;
}
case 0x1E:
{
static const value_string str_range[] = {
{0, "0"},
{1, "1"},
{2, "2"},
{3, "3"},
{4, "4"},
{5, "5"},
{6, "5"},
{7, "7"},
{8, "8"},
{9, "9"},
{0, NULL}
};
static value_string_ext str_range_ext = VALUE_STRING_EXT_INIT(str_range);
element_length = 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "%s: %d",
val_to_str_ext_const(i, &str_range_ext, "Unknown"),
tvb_get_ntohs(tvb, offset + 3 + element_length * i));
}
break;
}
case 0x1F:
{
static const value_string str_range[] = {
{0, "0 "},
{1, "0-1 "},
{2, "1-2 "},
{3, "2-3 "},
{4, "3 and +"},
{0, NULL}
};
static value_string_ext str_range_ext = VALUE_STRING_EXT_INIT(str_range);
element_length = 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "%s: %d",
val_to_str_ext_const(i, &str_range_ext, "Unknown"),
tvb_get_ntohs(tvb, offset + 3 + element_length * i));
}
break;
}
case 0x20:
{
element_length = 4;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "+/- %3d ms: %d",
((2 * i) + 1) * framing_rtp / 2,
tvb_get_ntohl(tvb, offset + 3 + 4 * i));
}
break;
}
case 0x2E:
{
ep_strbuf_append(strbuf,
tvb_get_guint8(tvb, offset + 3) ? "True" : "False");
break;
}
case 0x2F:
{
ep_strbuf_append_printf(strbuf, "%d", (tvb_get_guint8(tvb, offset + 3) & 0x07));
break;
}
case 0x30:
{
ep_strbuf_append_printf(strbuf, "%d", (tvb_get_ntohs(tvb, offset + 3) & 0x0FFF));
break;
}
case 0x31:
{
ep_strbuf_append_printf(strbuf, "%d (%d)", tvb_get_guint8(tvb, offset + 3),
tvb_get_guint8(tvb, offset + 3)>>2);
break;
}
case 0x3D:
{
static const value_string str_range[] = {
{0, "< 10 % "},
{1, "< 20 % "},
{2, "< 40 % "},
{3, "< 60 % "},
{4, ">= 60 % "},
{0, NULL}
};
static value_string_ext str_range_ext = VALUE_STRING_EXT_INIT(str_range);
element_length = 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "%s: %d",
val_to_str_ext_const(i, &str_range_ext, "Unknown"),
tvb_get_ntohs(tvb, offset + 3 + element_length * i));
}
break;
}
case 0x3E:
{
static const value_string str_range[] = {
{0, "1 "},
{1, "2 "},
{2, "3 "},
{3, "4 "},
{4, "5 and more"},
{0, NULL}
};
static value_string_ext str_range_ext = VALUE_STRING_EXT_INIT(str_range);
element_length = 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
g_snprintf(parameter_value_tab[i], PVT_COLS, "%s: %d",
val_to_str_ext_const(i, &str_range_ext, "Unknown"),
tvb_get_ntohs(tvb, offset + 3 + element_length * i));
}
break;
}
case 0x14:
{
framing_rtp = tvb_get_guint8(tvb, offset + 3);
}
case 0x01:
case 0x02:
case 0x03:
case 0x0C:
case 0x0D:
case 0x0E:
case 0x13:
case 0x15:
case 0x16:
case 0x17:
case 0x18:
case 0x19:
case 0x1A:
case 0x1C:
case 0x1D:
case 0x21:
case 0x29:
case 0x2A:
case 0x2D:
default:
{
guint64 param_value = 0;
for (i = parameter_length; i > 0; i--) {
param_value += ((guint64)tvb_get_guint8(tvb, offset + 2 + i) << (8 * (parameter_length - i)));
}
ep_strbuf_append_printf(strbuf, "%" G_GINT64_MODIFIER "u", param_value);
break;
}
}
}
switch (parameter_id)
{
case 0x1B:
case 0x1E:
case 0x1F:
case 0x20:
case 0x3D:
case 0x3E:
{
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 3, "%s:",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
proto_tree_add_text(ua3g_body_tree, tvb, offset + 3,
parameter_length, " %s",
val_to_str_const(parameter_id, str_parameter_id_tab, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1,
"Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 2,
"Length: %d", parameter_length);
offset += 2;
length -= 2;
for (i = 0; (i < (parameter_length / element_length)) && (i < PVT_ROWS); i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset,
element_length, " %s", parameter_value_tab[i]);
offset += element_length;
length -= element_length;
}
if (i >= PVT_ROWS) {
gint length_remaining = parameter_length - PVT_ROWS*element_length;
proto_tree_add_text(ua3g_body_tree,
tvb, offset, length_remaining,
"Unknown Parameter Data");
offset += length_remaining;
length -= length_remaining;
}
break;
}
default:
{
if (parameter_length > 0) {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 3, "%s: %s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), strbuf->str);
} else {
ua3g_param_item = proto_tree_add_text(ua3g_body_tree, tvb, offset,
parameter_length + 3, "%s",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"));
}
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_text(ua3g_param_tree, tvb, offset, 1, "Parameter: %s (0x%02x)",
val_to_str_ext_const(parameter_id, &str_parameter_id_ext, "Unknown"), parameter_id);
offset++;
length--;
proto_tree_add_text(ua3g_param_tree, tvb, offset, 2, "Length: %d", parameter_length);
offset += 2;
length -= 2;
if (parameter_length > 0) {
proto_tree_add_text(ua3g_param_tree, tvb, offset, parameter_length,
"Value: %s", strbuf->str);
offset += parameter_length;
length -= parameter_length;
}
break;
}
}
}
break;
}
default:
{
break;
}
}
}
static void
decode_unsolicited_msg(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode,
proto_item *ua3g_item, proto_item *ua3g_body_item)
{
guint8 command;
proto_tree *ua3g_body_tree;
static const value_string str_command[] = {
{0x00, "Hardware Reset Acknowledge"},
{0x01, "Software Reset Acknowledge"},
{0x02, "Illegal Command Received"},
{0x05, "Subdevice Down"},
{0x06, "Segment Failure"},
{0x07, "UA Device Event"},
{0, NULL}
};
static value_string_ext str_command_ext = VALUE_STRING_EXT_INIT(str_command);
command = tvb_get_guint8(tvb, offset);
if (opcode != 0x21) {
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
if (!ua3g_body_item)
return;
proto_item_append_text(ua3g_item, ", %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
proto_item_append_text(ua3g_body_item, " - %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_command, tvb,
offset, 1, command, "Command: %s",
val_to_str_ext_const(command, &str_command_ext, "Unknown"));
offset++;
length--;
} else {
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
command = 0xFF;
}
switch (command)
{
case 0x00:
case 0x01:
case 0xFF:
{
int link, vta_type;
static const value_string str_vta_type[] = {
{0x03, "4035"},
{0x04, "4020"},
{0x05, "4010"},
{0x20, "NOE A"},
{0x21, "NOE B"},
{0x22, "NOE C"},
{0x23, "NOE D"},
{0, NULL}
};
static const value_string str_other_info_1[] = {
{0x00, "Link Is TDM"},
{0x01, "Link Is IP"},
{0, NULL}
};
static const value_string str_other_info_2[] = {
{0x00, "Download Allowed"},
{0x01, "Download Refused"},
{0, NULL}
};
static const value_string str_hard_config_ip[] = {
{0x00, "Export Binary (No Thales)"},
{0x01, "Full Binary (Thales)"},
{0, NULL}
};
static const value_string str_hard_config_chip[] = {
{0x00, "Chip Id: Unknown"},
{0x01, "Chip Id: Ivanoe 1"},
{0x02, "Chip Id: Ivanoe 2"},
{0x03, "Chip Id: Reserved"},
{0, NULL}
};
static const value_string str_hard_config_flash[] = {
{0x00, "Flash Size: No Flash"},
{0x01, "Flash Size: 128 Kbytes"},
{0x02, "Flash Size: 256 Kbytes"},
{0x03, "Flash Size: 512 Kbytes"},
{0x04, "Flash Size: 1 Mbytes"},
{0x05, "Flash Size: 2 Mbytes"},
{0x06, "Flash Size: 4 Mbytes"},
{0x07, "Flash Size: 8 Mbytes"},
{0, NULL}
};
static const value_string str_hard_config_ram[] = {
{0x00, "External RAM Size: No External RAM"},
{0x01, "External RAM Size: 128 Kbytes"},
{0x02, "External RAM Size: 256 Kbytes"},
{0x03, "External RAM Size: 512 Kbytes"},
{0x04, "External RAM Size: 1 Mbytes"},
{0x05, "External RAM Size: 2 Mbytes"},
{0x06, "External RAM Size: 4 Mbytes"},
{0x07, "External RAM Size: 8 Mbytes"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Device Type: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_device_type, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2, "Firmware Version: %s",
version_number_computer(tvb_get_ntohs(tvb, offset)));
offset += 2;
length -= 2;
if (opcode != 0x21) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Self-Test Result: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
}
vta_type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "VTA Type: %s",
val_to_str_const(vta_type, str_vta_type, "Unknown"));
offset++;
length--;
switch (vta_type)
{
case 0x03:
case 0x04:
case 0x05:
{
static const value_string str_subtype[] = {
{0x03, "2x40"},
{0x04, "1x20"},
{0x05, "1x20"},
{0, NULL}
};
static const value_string str_generation[] = {
{0x02, "3"},
{0, NULL}
};
static const value_string str_design[] = {
{0x00, "Alpha"},
{0, NULL}
};
static const value_string str_hard_vta_type[] = {
{0x03, "MR2 (4035)"},
{0x05, "VLE (4010)"},
{0x07, "LE (4020)"},
{0, NULL}
};
static const value_string str_hard_design[] = {
{0x06, "Alpha"},
{0, NULL}
};
static const value_string str_hard_subtype[] = {
{0x06, "2x40"},
{0x07, "1x20"},
{0x08, "1x20"},
{0, NULL}
};
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Characteristic Number: VTA SubType: %s, Generation: %s, Design: %s",
val_to_str_const((((tvb_get_guint8(tvb, offset) & 0xC0) >> 6) + vta_type), str_subtype, "Unknown"),
val_to_str_const(((tvb_get_guint8(tvb, offset) & 0x38) >> 3), str_generation, "Unknown"),
val_to_str_const((tvb_get_guint8(tvb, offset) & 0x07), str_design, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Other Information: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_other_info_2, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hardware Configuration: VTA Type: %s, Design: %s, VTA SubType: %s",
val_to_str_const((((tvb_get_guint8(tvb, offset) & 0xE0) >> 5) + vta_type), str_hard_vta_type, "Unknown"),
val_to_str_const(((tvb_get_guint8(tvb, offset) & 0x1C) >> 2), str_hard_design, "Unknown"),
val_to_str_const((tvb_get_guint8(tvb, offset) & 0x03), str_hard_subtype, "Unknown"));
offset++;
length--;
if (opcode != 0x21) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hook Status/BCM Version: %s Hook",
STR_ON_OFF(tvb_get_guint8(tvb, offset)));
offset++;
length--;
}
break;
}
case 0x20:
case 0x21:
case 0x22:
case 0x23:
default:
{
link = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Other Information 1: %s",
val_to_str_const(link, str_other_info_1, "Unknown"));
offset++;
length--;
if (link == 0x00) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hardware Version: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hardware Configuration: %s, %s, %s",
val_to_str_const((tvb_get_guint8(tvb, offset) & 0x03), str_hard_config_chip, "Unknown"),
val_to_str_const(((tvb_get_guint8(tvb, offset) & 0x1C) >> 2), str_hard_config_flash, "Unknown"),
val_to_str_const(((tvb_get_guint8(tvb, offset) & 0xE0) >> 5), str_hard_config_ram, "Unknown"));
offset++;
length--;
} else {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Other Information 2: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_other_info_2, "Unknown"));
offset++;
length--;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Hardware Configuration: %s",
val_to_str_const((tvb_get_guint8(tvb, offset) & 0x01), str_hard_config_ip, "Unknown"));
offset++;
length--;
}
if (opcode != 0x21) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Hook Status: %s Hook",
STR_ON_OFF(tvb_get_guint8(tvb, offset)));
offset++;
length--;
if (length > 0) {
if (link == 0x00) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Firmware Datas Patch Version: %s",
version_number_computer(tvb_get_ntohs(tvb, offset)));
offset += 2;
length -= 2;
if (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Firmware Version (Loader): %s",
version_number_computer(tvb_get_ntohs(tvb, offset)));
}
} else {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Datas Version: %s",
version_number_computer(tvb_get_ntohs(tvb, offset)));
offset += 2;
length -= 2;
if (length > 0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 2,
"Firmware Version (Bootloader): %s",
version_number_computer(tvb_get_ntohs(tvb, offset)));
}
}
}
}
break;
}
}
break;
}
case 0x02:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Opcode Of Bad Command: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
while (length >0) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Next Byte Of Bad Command: %d", tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x05:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice Address: %d", tvb_get_guint8(tvb, offset));
break;
}
case 0x06:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "T: %d",
(tvb_get_guint8(tvb, offset) & 0x01));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Num: %d",
(tvb_get_guint8(tvb, offset) & 0x02));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "/S: %d",
(tvb_get_guint8(tvb, offset) & 0x04));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "L: %d",
(tvb_get_guint8(tvb, offset) & 0x08));
offset++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Opcode Bad Segment: %d", tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Next Byte Of Bad Segment: %d",
tvb_get_guint8(tvb, offset));
break;
}
case 0x07:
{
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Device Event: %d", tvb_get_guint8(tvb, offset));
break;
}
default:
{
break;
}
}
}
static void
decode_key_number(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode _U_,
proto_item *ua3g_body_item _U_)
{
#if 0
proto_tree *ua3g_body_tree;
static const value_string str_first_parameter[] = {
{0x01, "Production Test Command"},
{0x06, "Reserved For Compatibility"},
{0x3B, "Volume"},
{0x42, "Subdevice Address"},
{0, NULL}
};
#endif
if (!tree)
return;
if (length > 0) {
#if 0
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
#endif
proto_tree_add_text(tree, tvb, offset, length,
"Key Number: Row %d, Column %d",
(tvb_get_guint8(tvb, offset) & 0xF0), (tvb_get_guint8(tvb, offset) & 0x0F));
}
}
static void
decode_i_m_here(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length _U_, guint8 opcode _U_,
proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "Id Code: %s",
val_to_str_const(tvb_get_guint8(tvb, offset), str_device_type, "Unknown"));
}
static void
decode_special_key(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode,
proto_item *ua3g_body_item)
{
guint8 special_key_status;
proto_tree *ua3g_body_tree;
int i;
static const value_string str_parameters[] = {
{0x00, "Not Received Default In Effect"},
{0x02, "Downloaded Values In Effect"},
{0, NULL}
};
static const value_string str_special_key_status[] = {
{0x00, "Released"},
{0, NULL}
};
static const char *const str_special_key_name[] = {
"Shift ",
"Ctrl ",
"Alt ",
"Cmd ",
"Shift'",
"Ctrl' ",
"Alt' ",
"Cmd' "
};
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
if (opcode == 0x23) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Parameters Received for DTMF: %s",
val_to_str_const((tvb_get_guint8(tvb, offset) & 0x02), str_parameters, "Unknown"));
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Hookswitch Status: %shook",
STR_ON_OFF(tvb_get_guint8(tvb, offset) & 0x01));
offset++;
length--;
}
special_key_status = tvb_get_guint8(tvb, offset);
for (i = 0; i < 8; i++) {
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1, "%s: %s",
str_special_key_name[i],
val_to_str_const(special_key_status & (0x01 << i), str_special_key_status, "Pressed"));
}
}
static void
decode_subdevice_state(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length _U_,
guint8 opcode _U_, proto_item *ua3g_body_item)
{
proto_tree *ua3g_body_tree;
guint8 info;
int i;
if (!ua3g_body_item)
return;
ua3g_body_tree = proto_item_add_subtree(ua3g_body_item, ett_ua3g_body);
for (i = 0; i <= 7; i++) {
info = tvb_get_guint8(tvb, offset);
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice %d State: %d",
i, info & 0x0F);
i++;
proto_tree_add_text(ua3g_body_tree, tvb, offset, 1,
"Subdevice %d State: %d",
i, (info & 0xF0) >> 4);
offset++;
}
}
static void
dissect_ua3g(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
proto_item *ua3g_item;
proto_tree *ua3g_tree;
proto_item *ua3g_body_item = NULL;
gint length;
guint8 opcode;
value_string_ext *opcodes_vals_ext_p;
ua3g_item = proto_tree_add_item(tree, proto_ua3g, tvb, 0, -1, ENC_NA);
ua3g_tree = proto_item_add_subtree(ua3g_item, ett_ua3g);
if (message_direction == SYS_TO_TERM) {
opcodes_vals_ext_p = &opcodes_vals_sys_ext;
} else
opcodes_vals_ext_p = &opcodes_vals_term_ext;
length = tvb_get_letohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " - UA3G Message:");
proto_tree_add_uint(ua3g_tree, hf_ua3g_length, tvb, offset, 2, length);
offset += 2;
opcode = tvb_get_guint8(tvb, offset);
if (opcode != 0x9f)
opcode = (opcode & 0x7f);
proto_tree_add_uint_format(ua3g_tree, hf_ua3g_opcode, tvb, offset,
1, opcode, "Opcode: %s (0x%02x)",
val_to_str_ext_const(opcode, opcodes_vals_ext_p, "Unknown"), opcode);
offset++;
length--;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext_const(opcode, opcodes_vals_ext_p, "Unknown"));
proto_item_append_text(ua3g_item, ", %s", val_to_str_ext_const(opcode, opcodes_vals_ext_p, "Unknown"));
if (length > 0)
ua3g_body_item = proto_tree_add_text(ua3g_tree, tvb, offset,
length, "UA3G Body - %s",
val_to_str_ext_const(opcode, opcodes_vals_ext_p, "Unknown"));
if (message_direction == SYS_TO_TERM) {
switch (opcode) {
case SC_PRODUCTION_TEST:
case SC_SUBDEVICE_RESET:
case SC_ARE_YOU_THERE:
case SC_SET_SPEAKER_VOL:
case SC_TRACE_ON:
{
decode_with_one_parameter(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SUBDEVICE_ESCAPE:
{
decode_subdevice_escape(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SOFT_RESET:
{
decode_software_reset(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_IP_PHONE_WARMSTART:
{
decode_ip_phone_warmstart(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SUPER_MSG:
case SC_SUPER_MSG_2:
{
decode_super_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SEGMENT_MSG:
{
decode_segment_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_IP_DEVICE_ROUTING:
{
decode_ip_device_routing(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_DEBUG_IN_LINE:
{
decode_debug_in_line(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_LED_COMMAND:
{
decode_led_command(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_LCD_LINE_1_CMD:
case SC_LCD_LINE_2_CMD:
{
decode_lcd_line_cmd(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_MAIN_VOICE_MODE:
{
decode_main_voice_mode(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_SUBDEVICE_METASTATE:
{
decode_subdevice_metastate(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_DWL_DTMF_CLCK_FORMAT:
{
decode_dwl_dtmf_clck_format(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SET_CLCK:
{
decode_set_clck(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_VOICE_CHANNEL:
{
decode_voice_channel(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_EXTERNAL_RINGING:
{
decode_external_ringing(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_LCD_CURSOR:
{
decode_lcd_cursor(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_DWL_SPECIAL_CHAR:
{
decode_dwl_special_char(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SET_CLCK_TIMER_POS:
{
decode_set_clck_timer_pos(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_SET_LCD_CONTRAST:
{
decode_set_lcd_contrast(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_BEEP:
{
decode_beep(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_SIDETONE:
{
decode_sidetone(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_RINGING_CADENCE:
{
decode_ringing_cadence(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_MUTE:
{
decode_mute(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_FEEDBACK:
{
decode_feedback(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_READ_PERIPHERAL:
case SC_WRITE_PERIPHERAL:
{
decode_r_w_peripheral(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_ICON_CMD:
{
decode_icon_cmd(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_AUDIO_CONFIG:
{
decode_audio_config(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_AUDIO_PADDED_PATH:
{
decode_audio_padded_path(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case SC_KEY_RELEASE:
case SC_AMPLIFIED_HANDSET:
case SC_LOUDSPEAKER:
case SC_ANNOUNCE:
{
decode_on_off_level(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_RING:
{
decode_ring(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_UA_DWL_PROTOCOL:
{
decode_ua_dwl_protocol(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case SC_NOP:
case SC_HE_ROUTING:
case SC_LOOPBACK_ON:
case SC_LOOPBACK_OFF:
case SC_VIDEO_ROUTING:
case SC_REMOTE_UA_ROUTING:
case SC_VERY_REMOTE_UA_ROUTING:
case SC_OSI_ROUTING:
case SC_ABC_A_ROUTING:
case SC_IBS_ROUTING:
case SC_M_REFLEX_HUB_ROUTING:
case SC_START_BUZZER:
case SC_STOP_BUZZER:
case SC_ENABLE_DTMF:
case SC_DISABLE_DTMF:
case SC_CLEAR_LCD_DISP:
case SC_VERSION_INQUIRY:
case SC_VTA_STATUS_INQUIRY:
case SC_SUBDEVICE_STATE:
case SC_AUDIO_IDLE:
case SC_TRACE_OFF:
case SC_ALL_ICONS_OFF:
case SC_RELEASE_RADIO_LINK:
case SC_DECT_HANDOVER:
default:
{
break;
}
}
}
if (message_direction == TERM_TO_SYS) {
switch (opcode) {
case CS_DIGIT_DIALED:
{
decode_digit_dialed(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_SUBDEVICE_MSG:
{
decode_subdevice_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_SUPER_MSG:
case CS_SUPER_MSG_2:
{
decode_super_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_SEGMENT_MSG:
{
decode_segment_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_IP_DEVICE_ROUTING:
{
decode_cs_ip_device_routing(ua3g_tree, tvb, pinfo, offset, length, opcode,ua3g_item, ua3g_body_item);
break;
}
case CS_DEBUG_IN_LINE:
{
decode_debug_in_line(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_NON_DIGIT_KEY_PUSHED:
case CS_DIGIT_KEY_RELEASED:
case CS_KEY_RELEASED:
case CS_TM_KEY_PUSHED:
{
decode_key_number(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_UNSOLICITED_MSG:
case CS_VERSION_RESPONSE:
{
decode_unsolicited_msg(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case CS_I_M_HERE:
{
decode_i_m_here(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_RSP_STATUS_INQUIRY:
case CS_SPECIAL_KEY_STATUS:
{
decode_special_key(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_SUBDEVICE_STATE:
{
decode_subdevice_state(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_PERIPHERAL_CONTENT:
{
decode_r_w_peripheral(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_body_item);
break;
}
case CS_UA_DWL_PROTOCOL:
{
decode_ua_dwl_protocol(ua3g_tree, tvb, pinfo, offset, length, opcode, ua3g_item, ua3g_body_item);
break;
}
case CS_NOP_ACK:
case CS_HANDSET_OFFHOOK:
case CS_HANDSET_ONHOOK:
case CS_HE_ROUTING:
case CS_LOOPBACK_ON:
case CS_LOOPBACK_OFF:
case CS_VIDEO_ROUTING:
case CS_WARMSTART_ACK:
case CS_REMOTE_UA_ROUTING:
case CS_VERY_REMOTE_UA_R:
case CS_OSI_ROUTING:
case CS_ABC_A_ROUTING:
case CS_IBS_ROUTING:
case CS_TRACE_ON_ACK:
case CS_TRACE_OFF_ACK:
default:
{
break;
}
}
}
}
void
proto_register_ua3g(void)
{
static hf_register_info hf_ua3g[] =
{
{ &hf_ua3g_length,
{ "Length", "ua3g.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Decimal Value", HFILL }
},
{ &hf_ua3g_opcode,
{ "Opcode", "ua3g.opcode",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Hexa Value", HFILL }
},
{ &hf_ua3g_ip,
{ "IP Device Routing", "ua3g.ip",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Hexa Value - 2nd Command For IP Device Routing Opcode", HFILL }
},
{ &hf_ua3g_command,
{ "Command", "ua3g.command",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Hexa Value - 2nd Command (Excepted IP Device Routing Opcode)", HFILL }
},
};
static gint *ett[] =
{
&ett_ua3g,
&ett_ua3g_body,
&ett_ua3g_param,
&ett_ua3g_option,
};
proto_ua3g = proto_register_protocol("UA3G Message", "UA3G", "ua3g");
proto_register_field_array(proto_ua3g, hf_ua3g, array_length(hf_ua3g));
register_dissector("ua3g", dissect_ua3g, proto_ua3g);
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ua3g(void)
{
#if 0
dissector_handle_t handle_ua3g = find_dissector("ua3g");
dissector_add_uint("ua.opcode", 0x15, handle_ua3g);
#endif
}
