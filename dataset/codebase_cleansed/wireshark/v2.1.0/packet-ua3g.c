static void
version_number_computer( gchar *result, guint32 hexa_version )
{
int release, vers, fix;
release = (int)(hexa_version / 10000);
vers = (int)((hexa_version % 10000) / 100);
fix = (hexa_version % 10000) % 100;
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%02d.%02d", release, vers, fix);
}
static void
decode_with_one_parameter(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length,
int hf_opcode)
{
if (length == 0)
return;
proto_tree_add_item(tree, hf_opcode, tvb, offset, 1, ENC_NA);
}
static void
decode_subdevice_escape(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
proto_tree_add_item(tree, hf_ua3g_subdevice_address, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_subdevice_opcode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (length > 2) {
proto_tree_add_item(tree, hf_ua3g_subdevice_parameter_bytes, tvb, offset+2, length-2, ENC_NA);
}
}
static void
decode_software_reset(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
if (length == 0)
return;
proto_tree_add_item(tree, hf_ua3g_software_reset, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
decode_ip_phone_warmstart(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
if (length == 0)
return;
proto_tree_add_item(tree, hf_ua3g_ip_phone_warmstart, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
decode_super_msg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length, guint8 opcode)
{
proto_tree *ua3g_body_tree = tree;
int j = 0, parameter_length;
if (!ua3g_body_tree)
return;
while (length > 0) {
if (opcode == 0x17) {
parameter_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_super_msg_length, tvb, offset, 2,
parameter_length, "Length %d: %d", j++, parameter_length);
offset += 2;
length -= 2;
} else {
parameter_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_super_msg_length, tvb, offset, 1,
parameter_length, "Length %d: %d", j++, parameter_length);
offset++;
length--;
}
if (parameter_length > 0) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_super_msg_data, tvb, offset, parameter_length, ENC_NA);
offset += parameter_length;
length -= parameter_length;
}
}
}
static void
decode_segment_msg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
guint8 val;
if (!tree)
return;
val = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ua3g_segment_msg_segment, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ua3g_segment_msg_num_remaining, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (val & 0x80) {
proto_tree_add_item(tree, hf_ua3g_segment_msg_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
}
if (length > 0) {
proto_tree_add_item(tree, hf_ua3g_segment_message_data, tvb, offset, length, ENC_NA);
}
}
static void
decode_ip_device_routing(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command;
proto_tree *ua3g_body_tree = tree, *ua3g_param_tree, *ua3g_param_subtree;
proto_item *ua3g_param_item;
int parameter_length, parameter_id;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_ip_device_routing, "Unknown"));
if (!ua3g_body_tree)
return;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (command) {
case 0x00:
{
if (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_const(parameter_id, ip_device_routing_cmd_reset_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
guint8 param;
switch (parameter_id) {
case 0x00:
param = tvb_get_guint8(tvb, offset);
if ((param & 0x80) == 0x00) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_noe_update, tvb, offset, 1, ENC_BIG_ENDIAN);
ua3g_param_subtree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param_sub);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_bootloader, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_data, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_customization, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_localization, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_code, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_subtree, hf_ua3g_ip_device_routing_reset_parameter_noe_update_sip, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x01:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_bad_sec_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_cust_name, tvb, offset, parameter_length, ENC_NA|ENC_ASCII);
break;
case 0x03:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_l10n_name, tvb, offset, parameter_length, ENC_NA|ENC_ASCII);
break;
default:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_reset_parameter_value, tvb, offset, parameter_length, ENC_NA);
break;
}
}
}
break;
}
case 0x01:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_start_rtp_direction, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_start_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_ext_const(parameter_id, &ip_device_routing_cmd_start_rtp_vals_ext, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x01:
case 0x11:
case 0x13:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x04:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_compressor, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x06:
case 0x07:
case 0x0A:
case 0x0B:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_enabler, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x0D:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_send_qos, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x0E:
case 0x0F:
break;
case 0x15:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_dtmf_sending, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x18:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_rfc2198, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
case 0x31:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_srtp_encryption, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
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
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x02:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_const(parameter_id, ip_device_routing_cmd_stop_rtp_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter_value_num, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_stop_rtp_parameter_value_bytes, tvb, offset, parameter_length, ENC_NA);
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x03:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_redirect_parameter,
tvb, offset, parameter_length + 2, parameter_id,
"%s", val_to_str_const(parameter_id, ip_device_routing_cmd_redirect_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_redirect_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_redirect_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_redirect_parameter_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x01:
default:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_redirect_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_redirect_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x04:
{
int i, tone_nb_entries;
guint16 frequency_1, frequency_2;
signed char level_1, level_2;
tone_nb_entries = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_def_tones_num_entries, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
while (length > 0 && tone_nb_entries) {
for (i = 1; i <= tone_nb_entries; i++) {
frequency_1 = tvb_get_ntohs(tvb, offset);
level_1 = (signed char)(tvb_get_guint8(tvb, offset + 2)) / 2;
frequency_2 = tvb_get_ntohs(tvb, offset + 3);
level_2 = (signed char)(tvb_get_guint8(tvb, offset + 5)) / 2;
ua3g_param_tree = proto_tree_add_subtree_format(ua3g_body_tree, tvb, offset, 6,
ett_ua3g_param, NULL, "Tone Pair %d: %d Hz at %d dB / %d Hz at %d dB",
i, frequency_1, level_1, frequency_2, level_2);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_def_tones_frequency_1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_int(ua3g_param_tree, hf_ua3g_ip_device_routing_def_tones_level_1, tvb, offset, 1, level_1);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_def_tones_frequency_2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_int(ua3g_param_tree, hf_ua3g_ip_device_routing_def_tones_level_2, tvb, offset, 1, level_2);
offset++;
length--;
}
}
break;
}
case 0x05:
{
guint8 ii, tone_nb_entries, tone_id;
#if 0
guint8 tone_direction, tone_id, tone_duration tone_silence;
#endif
int tone_duration;
tone_nb_entries = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_start_tone_direction, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_start_tone_num_entries, tvb, offset, 1, ENC_BIG_ENDIAN);
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
ua3g_param_tree = proto_tree_add_subtree_format(ua3g_body_tree, tvb, offset, 6,
#if 0
ett_ua3g_param, NULL, "Tone Pair %d: Id: %d, Duration: %d ms, Silence: %d ms",
ii+1, tone_id, tone_duration, tone_silence);
#endif
ett_ua3g_param, NULL, "Tone Pair %d: Id: %d, Duration: %d ms",
ii+1, tone_id, tone_duration);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_tone_identification, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_tone_duration, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
#if 0
proto_tree_add_uint(ua3g_param_tree, hf_ua3g_feedback_duration, tvb, offset, 1, tone_duration);
offset++;
length--;
proto_tree_add_uint(ua3g_param_tree, hf_ua3g_silence, tvb, offset, 1, tone_silence);
offset++;
length--;
#endif
}
}
break;
}
case 0x07:
case 0x08:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_const(parameter_id, ip_device_routing_cmd_listen_rtp_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
case 0x03:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter_ip, tvb, offset, 1, ENC_NA);
break;
case 0x01:
case 0x02:
case 0x04:
default:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter_port, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_listen_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x09:
while (length > 0) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_get_param_req_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
break;
case 0x0A:
{
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_set_param_req_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_ext_const(parameter_id, &ip_device_routing_cmd_set_param_req_vals_ext, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x06:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_compressor, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x07:
case 0x08:
case 0x09:
case 0x0A:
case 0x0B:
case 0x0C:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_err_string, tvb, offset, parameter_length, ENC_NA|ENC_ASCII);
break;
case 0x0F:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_tftp_backup_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x11:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_set_pc_port_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x12:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_record_rtp_auth, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x13:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_security_flag_filter, tvb, offset, 1, ENC_NA);
break;
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
if ((parameter_length > 0) && (parameter_length <= 8)) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else if (parameter_length > 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_set_param_req_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
case 0x0B:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_device_routing_digit_value, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x0C:
case 0x0D:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_pause_restart_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_const(parameter_id, ip_device_routing_cmd_pause_restart_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_pause_restart_rtp_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x0E:
case 0x0F:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter, tvb, offset,
parameter_length + 2, parameter_id, "%s",
val_to_str_const(parameter_id, ip_device_routing_cmd_record_rtp_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x01:
case 0x04:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_remote_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
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
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x06:
default:
{
break;
}
}
}
static void
decode_debug_in_line(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
proto_tree_add_item(tree, hf_ua3g_debug_in_line, tvb, offset, length, ENC_NA|ENC_ASCII);
}
static void
decode_led_command(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset)
{
int command;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_led, "Unknown"));
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_command_led, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((command >= 0) && (command < 7)) {
proto_tree_add_item(tree, hf_ua3g_command_led_number, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
}
static void
decode_lcd_line_cmd(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command, column_n;
const gchar* command_str;
proto_tree *ua3g_body_tree = tree, *ua3g_param_tree, *ua3g_option_tree;
proto_item *ua3g_option_item;
wmem_strbuf_t *strbuf;
command = tvb_get_guint8(tvb, offset) & 0x03;
column_n = tvb_get_guint8(tvb, offset + 1);
command_str = val_to_str_const(command, str_command_lcd_line, "Unknown");
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s %d", command_str, column_n);
if (!ua3g_body_tree)
return;
strbuf = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_append_printf(strbuf, "\"%s\"", tvb_format_text(tvb, offset + 2, length - 2));
ua3g_param_tree = proto_tree_add_subtree_format(ua3g_body_tree, tvb, offset,
length, ett_ua3g_param, NULL, "%s %d: %s",
command_str, column_n, wmem_strbuf_get_str(strbuf));
proto_tree_add_item(ua3g_body_tree, hf_ua3g_command_lcd_line, tvb, offset, 1, ENC_BIG_ENDIAN);
ua3g_option_item = proto_tree_add_item(ua3g_param_tree, hf_ua3g_lcd_line_cmd_lcd_options, tvb, offset, 1, ENC_BIG_ENDIAN);
ua3g_option_tree = proto_item_add_subtree(ua3g_option_item, ett_ua3g_option);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_call_timer, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_blink, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_call_timer_control, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_call_timer_display, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_time_of_day_display, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_option_tree, hf_ua3g_lcd_line_cmd_lcd_options_suspend_display_refresh, tvb, offset, 1, ENC_NA);
offset++;
length--;
if (command != 3)
proto_tree_add_item(ua3g_param_tree, hf_ua3g_lcd_line_cmd_starting_column, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(ua3g_param_tree, hf_ua3g_lcd_line_cmd_unused, tvb, offset, 1, ENC_NA);
offset++;
length--;
proto_tree_add_string(ua3g_param_tree, hf_ua3g_lcd_line_cmd_ascii_char, tvb, offset, length, wmem_strbuf_get_str(strbuf));
}
static void
decode_main_voice_mode(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 mode;
proto_tree *ua3g_body_tree = tree;
mode = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(mode, str_main_voice_mode, "Unknown"));
if (!ua3g_body_tree)
return;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_main_voice_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (mode) {
case 0x06:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_main_voice_mode_tune, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_main_voice_mode_cadence, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
case 0x02:
case 0x03:
case 0x04:
case 0x05:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_main_voice_mode_speaker_volume, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (length > 0) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_main_voice_mode_microphone_volume, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
}
case 0x11:
{
signed char level;
level = (signed char)(tvb_get_guint8(tvb, offset)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_handset_level, tvb, offset, 1, level);
level = (signed char)(tvb_get_guint8(tvb, offset+1)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_sending_level, tvb, offset+1, 1, level);
break;
}
case 0x12:
{
signed char level;
level = (signed char)(tvb_get_guint8(tvb, offset)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_headset_level, tvb, offset, 1, level);
level = (signed char)(tvb_get_guint8(tvb, offset+1)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_sending_level, tvb, offset+1, 1, level);
break;
}
case 0x13:
{
signed char level;
level = (signed char)(tvb_get_guint8(tvb, offset)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_handsfree_level, tvb, offset, 1, level);
level = (signed char)(tvb_get_guint8(tvb, offset+1)) / 2;
proto_tree_add_int(ua3g_body_tree, hf_ua3g_main_voice_mode_sending_level, tvb, offset+1, 1, level);
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
decode_subdevice_metastate(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset)
{
proto_tree_add_item(tree, hf_ua3g_subdevice_metastate_subchannel_address, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_subdevice_metastate_new_metastate, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
static void
decode_dwl_dtmf_clck_format(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length)
{
proto_tree_add_item(tree, hf_ua3g_dwl_dtmf_clck_format_minimum_on_time, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_dwl_dtmf_clck_format_inter_digit_pause_time, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_dwl_dtmf_clck_format_clock_time_format, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if (length > 2)
proto_tree_add_item(tree, hf_ua3g_dwl_dtmf_clck_format_dtmf_country_adaptation, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
static void
decode_set_clck(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command;
int hour, minute, second, call_timer;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_set_clck, "Unknown"));
proto_tree_add_item(tree, hf_ua3g_command_set_clck, tvb, offset, 1, ENC_BIG_ENDIAN);
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
while (length > 0) {
hour = tvb_get_guint8(tvb, offset);
minute = tvb_get_guint8(tvb, offset + 1);
second = tvb_get_guint8(tvb, offset + 2);
proto_tree_add_uint_format_value(tree, (call_timer == 1) ? hf_ua3g_call_timer : hf_ua3g_current_time, tvb, offset, 3,
tvb_get_ntoh24(tvb, offset), "%d:%d:%d", hour, minute, second);
offset += 3;
length -= 3;
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
decode_voice_channel(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
if (length == 1) {
proto_tree_add_item(tree, hf_ua3g_voice_channel_channel_mode, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ua3g_voice_channel_codec, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ua3g_voice_channel_voice_channel, tvb, offset, 1, ENC_NA);
} else if (length == 2) {
proto_tree_add_item(tree, hf_ua3g_voice_channel_main_voice, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_voice_channel_announce, tvb, offset+1, 1, ENC_BIG_ENDIAN);
} else if (length == 4) {
proto_tree_add_item(tree, hf_ua3g_voice_channel_b_general, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_voice_channel_b_loud_speaker, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_voice_channel_b_ear_piece, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_voice_channel_b_microphones, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
}
static void
decode_external_ringing(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset)
{
guint8 command;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_ext_ring_cmd, "Unknown"));
proto_tree_add_item(tree, hf_ua3g_external_ringing_command, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
decode_lcd_cursor(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo, guint offset)
{
const gchar* str_on_off_val = STR_ON_OFF(tvb_get_guint8(tvb, offset + 1) & 0x02);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", str_on_off_val);
proto_tree_add_item(tree, hf_ua3g_lcd_cursor_line_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_lcd_cursor, tvb, offset+1, 1, ENC_NA);
}
static void
decode_dwl_special_char(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length)
{
int i;
while (length > 0) {
proto_tree_add_item(tree, hf_ua3g_dwl_special_char_character_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
for (i = 1; i <= 8; i++) {
proto_tree_add_item(tree, hf_ua3g_dwl_special_char_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
}
}
static void
decode_set_clck_timer_pos(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset)
{
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_set_clck_timer_pos_clock_line_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_set_clck_timer_pos_clock_column_number, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_set_clck_timer_pos_call_timer_line_number, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_set_clck_timer_pos_call_timer_column_number, tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
static void
decode_set_lcd_contrast(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset)
{
proto_tree_add_item(tree, hf_ua3g_set_lcd_contrast_driver_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_set_lcd_contrast_contrast_value, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
static void
decode_beep(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
if (length > 0) {
guint8 command;
proto_tree *ua3g_body_tree = tree;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_beep, "Unknown"));
proto_tree_add_item(ua3g_body_tree, hf_ua3g_command_beep, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (command) {
case 0x01:
case 0x02:
{
int i = 0;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_destination, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
while (length > 0) {
guint8 val;
i++;
val = (tvb_get_guint8(tvb, offset) & 0x7F) * 10;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_on_off, tvb, offset, 1, ENC_NA);
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_beep_cadence, tvb, offset, 1, val,
"Cadence T%d: %d ms", i, val);
offset++;
length--;
}
break;
}
case 0x04:
{
static const int *destinations[] = {
&hf_ua3g_beep_beep_destination_handset,
&hf_ua3g_beep_beep_destination_headset,
&hf_ua3g_beep_beep_destination_loudspeaker,
&hf_ua3g_beep_beep_destination_announce_loudspeaker,
&hf_ua3g_beep_beep_destination_handsfree,
NULL
};
proto_tree_add_bitmask(ua3g_body_tree, tvb, offset, hf_ua3g_beep_beep_destination,
ett_ua3g_beep_beep_destination, destinations, ENC_NA);
offset++;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_beep_number, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case 0x05:
{
int i, nb_of_notes, beep_number;
proto_tree* note_tree;
beep_number = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_beep_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (beep_number <= 0x44)
beep_number = 0x00;
else
beep_number = 0xFF;
nb_of_notes = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_number_of_notes, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
while (length > 0) {
for (i = 1; i <= nb_of_notes; i++) {
note_tree = proto_tree_add_subtree_format(ua3g_body_tree, tvb, offset, 3,
ett_ua3g_note, NULL, "Note %d", i);
proto_tree_add_uint_format(note_tree, hf_ua3g_beep_freq_sample, tvb, offset, 1, tvb_get_guint8(tvb, offset),
"%s: %d", val_to_str_const(beep_number, str_beep_freq_sample_nb, "Unknown"),
tvb_get_guint8(tvb, offset));
offset++;
length--;
proto_tree_add_item(note_tree, hf_ua3g_beep_level, tvb, offset, 1, ENC_NA);
offset++;
length--;
proto_tree_add_uint_format(note_tree, hf_ua3g_beep_duration, tvb, offset, 1, tvb_get_guint8(tvb, offset),
"%s: %x", val_to_str_const(beep_number, str_beep_duration, "Unknown"),
tvb_get_guint8(tvb, offset));
offset++;
length--;
}
proto_tree_add_item(ua3g_body_tree, hf_ua3g_beep_terminator, tvb, offset, 1, ENC_BIG_ENDIAN);
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
col_append_str(pinfo->cinfo, COL_INFO, ": Classical Beep");
}
}
static void
decode_sidetone(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint offset)
{
guint8 command;
const gchar* command_str;
command = tvb_get_guint8(tvb, offset);
command_str = STR_ON_OFF(command);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", command_str);
proto_tree_add_item(tree, hf_ua3g_command_sidetone, tvb, offset, 1, ENC_NA);
if (command == 0x01) {
proto_tree_add_int(tree, hf_ua3g_sidetone_level, tvb, offset+1, 1,
(signed char)(tvb_get_guint8(tvb, offset+1) / 2));
}
}
static void
decode_ringing_cadence(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length)
{
int i = 0;
guint16 cadence_length;
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_ringing_cadence_cadence, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
while (length > 0) {
i++;
proto_tree_add_item(tree, hf_ua3g_ringing_cadence_on_off, tvb, offset, 1, ENC_NA);
cadence_length = ((tvb_get_guint8(tvb, offset) & 0x7F) * 10);
proto_tree_add_uint_format(tree, hf_ua3g_ringing_cadence_length, tvb, offset, 1, cadence_length,
"Length %d : %d ms", i, cadence_length);
offset++;
length--;
}
}
static void
decode_mute(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint offset)
{
guint8 command;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_mute, "Unknown"));
proto_tree_add_item(tree, hf_ua3g_command_mute, tvb, offset, 1, ENC_NA);
}
static void
decode_feedback(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command;
const gchar* command_str;
command = tvb_get_guint8(tvb, offset);
command_str = STR_ON_OFF(command);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", command_str);
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_command_feedback, tvb, offset, 1, ENC_NA);
offset++;
length--;
if (command == 0x01) {
proto_tree_add_int(tree, hf_ua3g_feedback_level, tvb, offset, 1,
(signed char)(tvb_get_guint8(tvb, offset) / 2));
offset++;
length--;
if (length > 0) {
proto_tree_add_uint_format_value(tree, hf_ua3g_feedback_duration, tvb, offset, 1,
tvb_get_guint8(tvb, offset) * 10, "%d ms", tvb_get_guint8(tvb, offset) * 10);
}
}
}
static void
decode_r_w_peripheral(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset, guint length)
{
proto_tree_add_item(tree, hf_ua3g_r_w_peripheral_address, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length > 2) {
proto_tree_add_item(tree, hf_ua3g_r_w_peripheral_content, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
}
static void
decode_icon_cmd(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint offset)
{
guint8 byte0, byte1, bytex;
int i;
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_icon_cmd_icon_number, tvb, offset, 1, ENC_BIG_ENDIAN);
byte0 = tvb_get_guint8(tvb, offset+1);
byte1 = tvb_get_guint8(tvb, offset+2);
for (i = 0; i < 8; i++) {
bytex =
((byte0 >> i) & 0x01) * 2 +
((byte1 >> i) & 0x01);
proto_tree_add_uint_format(tree, hf_ua3g_icon_cmd_segment, tvb, offset+1, 2, bytex,
"Segment %d: %s (%d)", i, val_to_str_const(bytex, str_icon_cmd_state, "Unknown"), bytex);
}
}
static void
decode_audio_config(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command;
proto_tree *ua3g_body_tree = tree;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_audio_config, "Unknown"));
if (!ua3g_body_tree)
return;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_command_audio_config, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (command) {
case 0x00:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_ignored, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_law, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
case 0x01:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_dpi_chan_ua_tx1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_dpi_chan_ua_tx2, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_dpi_chan_gci_tx1, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_dpi_chan_gci_tx2, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_dpi_chan_cod_tx, tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
case 0x02:
{
int i;
for (i = 1; i < 8; i++) {
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_audio_config_volume_level, tvb, offset,
1, tvb_get_guint8(tvb, offset), "Volume Level %d: %d",
i, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
break;
}
case 0x03:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_dth, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_dtr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_dtf, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_str, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_ahp1, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_ahp2, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_ath, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_atr, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_atf, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_audio_circuit_alm, tvb, offset+9, 1, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_handsfree_return, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_handsfree_handsfree, tvb, offset, 1, ENC_NA);
break;
case 0x05:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_group_listen, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_attenuation, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_stay_in_send, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_shift_right_mtx, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_shift_right_mrc, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_idle_trans_threshold, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_low_trans_threshold, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_idle_recv_threshold, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_low_recv_threshold, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_med_recv_threshold, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_high_recv_threshold, tvb, offset+10, 1, ENC_BIG_ENDIAN);
break;
case 0x06:
{
static const gchar *str_device_values[] = {
" Internal",
" Rj9 Plug",
" Jack Plug",
" Bluetooth Link",
" USB Link"
};
wmem_strbuf_t *strbuf;
guint8 device_values;
int j;
int device_index = 0;
strbuf = wmem_strbuf_new_label(wmem_packet_scope());
while (length > 0) {
device_values = tvb_get_guint8(tvb, offset);
wmem_strbuf_truncate(strbuf, 0);
if (device_values != 0) {
for (j = 0; j < 5; j++) {
if (device_values & (0x01 << j)) {
wmem_strbuf_append(strbuf, str_device_values[j]);
}
}
} else {
wmem_strbuf_append(strbuf, " None");
}
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_device_configuration, tvb, offset, 1,
device_values, "%s:%s",
val_to_str_const(device_index, str_device_configuration, "Unknown"),
wmem_strbuf_get_str(strbuf));
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
decode_audio_padded_path(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset)
{
proto_tree_add_item(tree, hf_ua3g_audio_padded_path_emission_padded_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_audio_padded_path_reception_padded_level, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
static void
decode_on_off_level(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, int hf_opcode)
{
guint8 command;
const gchar* command_str;
command = tvb_get_guint8(tvb, offset);
command_str = STR_ON_OFF(command);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", command_str);
proto_tree_add_item(tree, hf_opcode, tvb, offset, 1, ENC_NA);
if (length > 1) {
if (command == 0x01) {
proto_tree_add_item(tree, hf_ua3g_on_off_level_level_on_loudspeaker, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
}
}
static void
decode_ring(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint offset)
{
guint8 command;
const gchar* command_str;
command = tvb_get_guint8(tvb, offset);
command_str = STR_ON_OFF(command);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", command_str);
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_command_ring, tvb, offset, 1, ENC_NA);
if (command == 0x01) {
proto_tree_add_item(tree, hf_ua3g_ring_melody, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_ring_cadence, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_ring_speaker_level, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_ring_beep_number, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_ring_silent, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(tree, hf_ua3g_ring_progressive, tvb, offset+5, 1, ENC_BIG_ENDIAN);
}
}
static void
decode_ua_dwl_protocol(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length)
{
guint8 command;
proto_tree *ua3g_body_tree = tree, *ua3g_param_tree;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_ua_dwl_protocol, "Unknown"));
proto_tree_add_item(ua3g_body_tree, hf_ua3g_command_ua_dwl_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (command) {
case 0x00:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_item_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_item_version_nc, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_cause, tvb, offset+3, 1, ENC_BIG_ENDIAN);
break;
case 0x01:
{
if (length > 7) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_force_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_item_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_item_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (length > 2) {
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Files Included");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_files_inc_boot_binary,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_files_inc_loader_binary,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_files_inc_appli_binary,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_files_inc_data_binary,
tvb, offset, 1, ENC_NA);
offset++;
length--;
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Model Selection");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_model_selection_a,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_model_selection_b,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_model_selection_c,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_model_selection_country_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Hardware Selection");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_hardware_selection_ivanoe1,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_hardware_selection_ivanoe2,
tvb, offset, 1, ENC_NA);
offset++;
length--;
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Memory Sizes Required");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_memory_sizes_flash,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_ua_dwl_protocol_memory_sizes_ext_ram,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
} else {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_binary_info, tvb, offset, 1, ENC_NA);
offset++;
length--;
}
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_binary_length, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
}
case 0x02:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_packet_number, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_download_ack_status, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
case 0x03:
{
int i = 1;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_packet_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
while (length > 0) {
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_packet_number, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "Packet Number %3d: %d", i, tvb_get_guint8(tvb, offset));
offset++;
length--;
i++;
}
break;
}
case 0x05:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_packet_download_end_ack_ok_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x06:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_checksum, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ua_dwl_protocol_acknowledge, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x04:
default:
break;
}
}
static void
decode_digit_dialed(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint offset)
{
proto_tree_add_item(tree, hf_ua3g_digit_dialed_digit_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
decode_subdevice_msg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint length)
{
if (!tree)
return;
proto_tree_add_item(tree, hf_ua3g_subdevice_msg_subdev_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_subdevice_msg_subdev_address, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ua3g_subdevice_msg_subdevice_opcode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (length > 2) {
proto_tree_add_item(tree, hf_ua3g_subdevice_msg_parameter_bytes, tvb, offset+2, length-2, ENC_NA);
}
}
static void
decode_cs_ip_device_routing(proto_tree *tree _U_, tvbuff_t *tvb,
packet_info *pinfo, guint offset, guint length)
{
guint8 command;
proto_tree *ua3g_body_tree = tree, *ua3g_param_tree;
proto_item *ua3g_param_item;
int i, parameter_id, parameter_length;
command = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_cs_ip_device_routing, "Unknown"));
if (!ua3g_body_tree)
return;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_ip_cs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (command) {
case 0x00:
proto_tree_add_item(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_cmd00_vta_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_cmd00_characteristic_number, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
case 0x01:
{
int j = 0;
if (length == 1) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_cmd01_incident_0, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
while (length >0) {
j++;
proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_param_identifier, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "Parameter %d Identifier: %d",
j, tvb_get_guint8(tvb, offset));
offset++;
length--;
}
}
break;
}
case 0x02:
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter, tvb, offset,
parameter_id, parameter_length + 2,
"%s", val_to_str_const(parameter_id, ip_device_routing_cmd_get_param_req_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x00:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_firmware_version, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x08:
{
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_default_codec_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_default_codec_bytes, tvb, offset, parameter_length, ENC_NA);
}
break;
}
case 0x09:
{
if (parameter_length == 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_speed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_duplex, tvb, offset+1, 1, ENC_BIG_ENDIAN);
} else if (parameter_length == 4) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_speed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_duplex, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_pc_speed, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_pc_duplex, tvb, offset+3, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
case 0x0A:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_mac_address, tvb, offset, 6, ENC_NA);
break;
default:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd02_parameter_value, tvb, offset, parameter_length, ENC_NA);
}
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
case 0x03:
{
int framing_rtp = 0;
while (length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_ntohs(tvb, offset + 1);
ua3g_param_item = proto_tree_add_uint_format(ua3g_body_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter, tvb, offset,
parameter_length+3, parameter_id, "%s",
val_to_str_const(parameter_id, cs_ip_device_routing_03_parameter_id_tab_vals, "Unknown"));
ua3g_param_tree = proto_item_add_subtree(ua3g_param_item, ett_ua3g_param);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (parameter_length > 0) {
switch (parameter_id) {
case 0x06:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_type_of_equip1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_type_of_equip2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x08:
case 0x09:
case 0x26:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x0A:
case 0x0B:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_string, tvb, offset, parameter_length, ENC_NA|ENC_ASCII);
break;
case 0x0F:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_default_codec, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_default_codec, tvb, offset, 8, ENC_BIG_ENDIAN);
}
break;
case 0x10:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_vad, tvb, offset, 1, ENC_NA);
break;
case 0x11:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_ece, tvb, offset, 1, ENC_NA);
break;
case 0x12:
if (parameter_length <= 8) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_voice_mode, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_voice_mode, tvb, offset, 8, ENC_BIG_ENDIAN);
}
break;
case 0x1B:
for (i = 0; i < parameter_length; i += 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_delay_distribution, tvb, offset+i, 2, ENC_BIG_ENDIAN);
}
break;
case 0x1E:
for (i = 0; i < parameter_length; i += 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_consecutive_bfi, tvb, offset+i, 2, ENC_BIG_ENDIAN);
}
break;
case 0x1F:
for (i = 0; i < parameter_length; i += 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_bfi_distribution, tvb, offset+i, 2, ENC_BIG_ENDIAN);
}
break;
case 0x20:
for (i = 0; i < parameter_length / 4; i+=4) {
proto_tree_add_uint_format_value(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_jitter_depth_distribution,
tvb, offset+i, 4, tvb_get_ntohl(tvb, offset+i), "+/- %3d ms: %d",
((2 * i/4) + 1) * framing_rtp / 2, tvb_get_ntohl(tvb, offset+i));
}
break;
case 0x2E:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_8021Q_used, tvb, offset, 1, ENC_NA);
break;
case 0x2F:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_8021P_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x30:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x31:
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_diffserv, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x3D:
for (i = 0; i < parameter_length; i += 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_bfi_distribution_200ms, tvb, offset+i, 2, ENC_BIG_ENDIAN);
}
break;
case 0x3E:
for (i = 0; i < parameter_length; i += 2) {
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_consecutive_rtp_lost, tvb, offset+i, 2, ENC_BIG_ENDIAN);
}
break;
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
proto_tree_add_item(ua3g_param_tree, hf_ua3g_cs_ip_device_routing_cmd03_parameter_uint, tvb, offset, parameter_length, ENC_BIG_ENDIAN);
break;
}
offset += parameter_length;
length -= parameter_length;
}
}
break;
}
default:
break;
}
}
static void
decode_unsolicited_msg(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
guint offset, guint length, guint8 opcode)
{
guint8 command;
proto_tree *ua3g_body_tree = tree, *ua3g_param_tree;
command = tvb_get_guint8(tvb, offset);
if (opcode != 0x21) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(command, str_command_unsolicited_msg, "Unknown"));
proto_tree_add_item(ua3g_body_tree, hf_ua3g_command_unsolicited_msg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
} else {
command = 0xFF;
}
switch (command)
{
case 0x00:
case 0x01:
case 0xFF:
{
int link, vta_type;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_device_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_firmware_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
if (opcode != 0x21) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_self_test_result, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
vta_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_vta_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
switch (vta_type)
{
case 0x03:
case 0x04:
case 0x05:
{
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Characteristic Number");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_char_num_vta_subtype,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_char_num_generation,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_char_num_design,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_other_information, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Hardware Configuration");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_vta_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_design,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_subtype,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (opcode != 0x21) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_hook_status, tvb, offset, 1, ENC_NA);
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
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_other_information_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
if (link == 0x00) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_hardware_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
ua3g_param_tree = proto_tree_add_subtree(ua3g_body_tree, tvb, offset, 1, ett_ua3g_param, NULL, "Hardware Configuration");
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_hard_config_chip,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_hard_config_flash,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_param_tree, hf_ua3g_unsolicited_msg_hardware_config_config_ram,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
} else {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_other_information_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_hardware_config_hard_config_ip,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
}
if (opcode != 0x21) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_hook_status,
tvb, offset, 1, ENC_NA);
offset++;
length--;
if (length > 0) {
if (link == 0x00) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_firmware_datas_patch_version,
tvb, offset, 2, ENC_BIG_ENDIAN);
if (length > 2) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_firmware_version_loader, tvb,
offset+2, 2, ENC_BIG_ENDIAN);
}
} else {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_datas_version, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length > 2) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_firmware_version_bootloader,
tvb, offset+2, 2, ENC_BIG_ENDIAN);
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
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_opcode_of_bad_command, tvb, offset, 1, ENC_BIG_ENDIAN);
if (length > 1) {
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_next_byte_of_bad_command, tvb, offset+1, length-1, ENC_NA);
}
break;
}
case 0x05:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_subdevice_address, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case 0x06:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_segment_failure_t, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_segment_failure_num, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_segment_failure_s, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_segment_failure_l, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_opcode_bad_segment, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_next_byte_of_bad_segment, tvb, offset+2, 1, ENC_BIG_ENDIAN);
break;
}
case 0x07:
{
proto_tree_add_item(ua3g_body_tree, hf_ua3g_unsolicited_msg_device_event, tvb, offset, 1, ENC_BIG_ENDIAN);
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
guint offset, guint length)
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
proto_tree_add_uint_format_value(tree, hf_ua3g_key_number, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "Row %d, Column %d",
(tvb_get_guint8(tvb, offset) & 0xF0), (tvb_get_guint8(tvb, offset) & 0x0F));
}
}
static void
decode_i_m_here(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, guint offset)
{
proto_tree_add_item(tree, hf_ua3g_i_m_here_id_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
decode_special_key(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_,
guint offset, guint8 opcode)
{
static const int * special_keys[] = {
&hf_ua3g_special_key_shift,
&hf_ua3g_special_key_ctrl,
&hf_ua3g_special_key_alt,
&hf_ua3g_special_key_cmd,
&hf_ua3g_special_key_shift_prime,
&hf_ua3g_special_key_ctrl_prime,
&hf_ua3g_special_key_alt_prime,
&hf_ua3g_special_key_cmd_prime,
NULL
};
if (opcode == 0x23) {
proto_tree_add_item(tree, hf_ua3g_special_key_param_dtmf, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ua3g_special_key_hookswitch_status, tvb, offset, 1, ENC_NA);
offset++;
}
proto_tree_add_bitmask_list(tree, tvb, offset, 1, special_keys, ENC_NA);
}
static void
decode_subdevice_state(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo _U_, guint offset)
{
guint8 info;
int i;
for (i = 0; i <= 7; i++) {
info = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ua3g_subdevice_state, tvb, offset, 1,
info & 0x0F, "Subdevice %d State: %d",
i, info & 0x0F);
i++;
proto_tree_add_uint_format(tree, hf_ua3g_subdevice_state, tvb, offset, 1,
(info & 0xF0) >> 4, "Subdevice %d State: %d",
i, (info & 0xF0) >> 4);
offset++;
}
}
static int
dissect_ua3g(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
proto_item *ua3g_item;
proto_tree *ua3g_tree, *ua3g_body_tree;
gint length;
guint8 opcode;
const gchar* opcode_str;
e_ua_direction *message_direction;
if (data == NULL)
return 0;
message_direction = (e_ua_direction *)data;
ua3g_item = proto_tree_add_item(tree, proto_ua3g, tvb, 0, -1, ENC_NA);
ua3g_tree = proto_item_add_subtree(ua3g_item, ett_ua3g);
length = tvb_get_letohs(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, " - UA3G Message:");
proto_tree_add_uint(ua3g_tree, hf_ua3g_length, tvb, offset, 2, length);
offset += 2;
opcode = tvb_get_guint8(tvb, offset);
if (opcode != 0x9f)
opcode = (opcode & 0x7f);
if (*message_direction == SYS_TO_TERM) {
proto_tree_add_uint(ua3g_tree, hf_ua3g_opcode_sys, tvb, offset, 1, opcode);
opcode_str = val_to_str_ext_const(opcode, &opcodes_vals_sys_ext, "Unknown");
} else {
proto_tree_add_uint(ua3g_tree, hf_ua3g_opcode_term, tvb, offset, 1, opcode);
opcode_str = val_to_str_ext_const(opcode, &opcodes_vals_term_ext, "Unknown");
}
offset++;
length--;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", opcode_str);
proto_item_append_text(ua3g_item, ", %s", opcode_str);
ua3g_body_tree = proto_tree_add_subtree(ua3g_tree, tvb, offset, length, ett_ua3g_body, NULL, "UA3G Body");
if (*message_direction == SYS_TO_TERM) {
switch (opcode) {
case SC_PRODUCTION_TEST:
{
decode_with_one_parameter(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_opcode_production_test);
break;
}
case SC_SUBDEVICE_RESET:
{
decode_with_one_parameter(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_opcode_subservice_reset);
break;
}
case SC_ARE_YOU_THERE:
{
decode_with_one_parameter(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_opcode_are_you_there);
break;
}
case SC_SET_SPEAKER_VOL:
{
decode_with_one_parameter(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_opcode_set_speaker_vol);
break;
}
case SC_TRACE_ON:
{
decode_with_one_parameter(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_opcode_trace_on);
break;
}
case SC_SUBDEVICE_ESCAPE:
{
decode_subdevice_escape(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SOFT_RESET:
{
decode_software_reset(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_IP_PHONE_WARMSTART:
{
decode_ip_phone_warmstart(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SUPER_MSG:
case SC_SUPER_MSG_2:
{
decode_super_msg(ua3g_body_tree, tvb, pinfo, offset, length, opcode);
break;
}
case SC_SEGMENT_MSG:
{
decode_segment_msg(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_IP_DEVICE_ROUTING:
{
decode_ip_device_routing(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_DEBUG_IN_LINE:
{
decode_debug_in_line(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_LED_COMMAND:
{
decode_led_command(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_LCD_LINE_1_CMD:
case SC_LCD_LINE_2_CMD:
{
decode_lcd_line_cmd(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_MAIN_VOICE_MODE:
{
decode_main_voice_mode(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SUBDEVICE_METASTATE:
{
decode_subdevice_metastate(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_DWL_DTMF_CLCK_FORMAT:
{
decode_dwl_dtmf_clck_format(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SET_CLCK:
{
decode_set_clck(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_VOICE_CHANNEL:
{
decode_voice_channel(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_EXTERNAL_RINGING:
{
decode_external_ringing(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_LCD_CURSOR:
{
decode_lcd_cursor(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_DWL_SPECIAL_CHAR:
{
decode_dwl_special_char(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SET_CLCK_TIMER_POS:
{
decode_set_clck_timer_pos(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_SET_LCD_CONTRAST:
{
decode_set_lcd_contrast(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_BEEP:
{
decode_beep(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_SIDETONE:
{
decode_sidetone(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_RINGING_CADENCE:
{
decode_ringing_cadence(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_MUTE:
{
decode_mute(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_FEEDBACK:
{
decode_feedback(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_READ_PERIPHERAL:
case SC_WRITE_PERIPHERAL:
{
decode_r_w_peripheral(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_ICON_CMD:
{
decode_icon_cmd(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_AUDIO_CONFIG:
{
decode_audio_config(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case SC_AUDIO_PADDED_PATH:
{
decode_audio_padded_path(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_KEY_RELEASE:
{
decode_on_off_level(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_command_key_release);
break;
}
case SC_AMPLIFIED_HANDSET:
{
decode_on_off_level(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_command_amplified_handset);
break;
}
case SC_LOUDSPEAKER:
{
decode_on_off_level(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_command_loudspeaker);
break;
}
case SC_ANNOUNCE:
{
decode_on_off_level(ua3g_body_tree, tvb, pinfo, offset, length, hf_ua3g_command_announce);
break;
}
case SC_RING:
{
decode_ring(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case SC_UA_DWL_PROTOCOL:
{
decode_ua_dwl_protocol(ua3g_body_tree, tvb, pinfo, offset, length);
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
if (*message_direction == TERM_TO_SYS) {
switch (opcode) {
case CS_DIGIT_DIALED:
{
decode_digit_dialed(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case CS_SUBDEVICE_MSG:
{
decode_subdevice_msg(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_SUPER_MSG:
case CS_SUPER_MSG_2:
{
decode_super_msg(ua3g_body_tree, tvb, pinfo, offset, length, opcode);
break;
}
case CS_SEGMENT_MSG:
{
decode_segment_msg(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_IP_DEVICE_ROUTING:
{
decode_cs_ip_device_routing(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_DEBUG_IN_LINE:
{
decode_debug_in_line(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_NON_DIGIT_KEY_PUSHED:
case CS_DIGIT_KEY_RELEASED:
case CS_KEY_RELEASED:
case CS_TM_KEY_PUSHED:
{
decode_key_number(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_UNSOLICITED_MSG:
case CS_VERSION_RESPONSE:
{
decode_unsolicited_msg(ua3g_body_tree, tvb, pinfo, offset, length, opcode);
break;
}
case CS_I_M_HERE:
{
decode_i_m_here(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case CS_RSP_STATUS_INQUIRY:
case CS_SPECIAL_KEY_STATUS:
{
decode_special_key(ua3g_body_tree, tvb, pinfo, offset, opcode);
break;
}
case CS_SUBDEVICE_STATE:
{
decode_subdevice_state(ua3g_body_tree, tvb, pinfo, offset);
break;
}
case CS_PERIPHERAL_CONTENT:
{
decode_r_w_peripheral(ua3g_body_tree, tvb, pinfo, offset, length);
break;
}
case CS_UA_DWL_PROTOCOL:
{
decode_ua_dwl_protocol(ua3g_body_tree, tvb, pinfo, offset, length);
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
return tvb_captured_length(tvb);
}
void
proto_register_ua3g(void)
{
static hf_register_info hf[] =
{
{ &hf_ua3g_length,
{ "Length", "ua3g.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_sys,
{ "Opcode", "ua3g.opcode",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &opcodes_vals_sys_ext, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_term,
{ "Opcode", "ua3g.opcode",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &opcodes_vals_term_ext, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_production_test,
{ "Production Test Command", "ua3g.production_test",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_subservice_reset,
{ "Reserved For Compatibility", "ua3g.subservice_reset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_are_you_there,
{ "Temporization", "ua3g.are_you_there",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_set_speaker_vol,
{ "Volume", "ua3g.set_speaker_vol",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_opcode_trace_on,
{ "Subdevice Address", "ua3g.trace_on",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip,
{ "IP Device Routing", "ua3g.ip",
FT_UINT8, BASE_HEX, VALS(str_command_ip_device_routing), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip_cs,
{ "IP Device Routing", "ua3g.ip.cs",
FT_UINT8, BASE_HEX, VALS(str_command_cs_ip_device_routing), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_led,
{ "Led Command", "ua3g.command.led",
FT_UINT8, BASE_HEX, VALS(str_command_led), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_lcd_line,
{ "LCD Line Command", "ua3g.command.lcd_line",
FT_UINT8, BASE_HEX, VALS(str_command_lcd_line), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_main_voice_mode,
{ "Voice Mode", "ua3g.command.main_voice_mode",
FT_UINT8, BASE_HEX, VALS(str_main_voice_mode), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_set_clck,
{ "Set Clock", "ua3g.command.set_clck",
FT_UINT8, BASE_HEX, VALS(str_command_set_clck), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_external_ringing_command,
{ "External Ringing Command", "ua3g.command.external_ringing",
FT_UINT8, BASE_HEX, VALS(str_ext_ring_cmd), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_lcd_cursor,
{ "Cursor", "ua3g.lcd_cursor",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x02,
NULL, HFILL }
},
{ &hf_ua3g_command_beep,
{ "Beep", "ua3g.command.beep",
FT_UINT8, BASE_HEX, VALS(str_command_beep), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_sidetone,
{ "Sidetone", "ua3g.command.sidetone",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_mute,
{ "Microphone", "ua3g.command.mute",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL }
},
{ &hf_ua3g_command_feedback,
{ "Feedback", "ua3g.command.feedback",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_audio_config,
{ "Audio Config", "ua3g.command.audio_config",
FT_UINT8, BASE_HEX, VALS(str_command_audio_config), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_key_release,
{ "Key Release", "ua3g.command.key_release",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_amplified_handset,
{ "Amplified Handset (Boost)", "ua3g.command.amplified_handset",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_loudspeaker,
{ "Loudspeaker", "ua3g.command.loudspeaker",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_announce,
{ "Announce", "ua3g.command.announce",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_ring,
{ "Ring", "ua3g.command.ring",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_ua_dwl_protocol,
{ "UA Download Protocol", "ua3g.command.ua_dwl_protocol",
FT_UINT8, BASE_HEX, VALS(str_command_ua_dwl_protocol), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_command_unsolicited_msg,
{ "Unsolicited Message", "ua3g.command.unsolicited_msg",
FT_UINT8, BASE_HEX, VALS(str_command_unsolicited_msg), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip_device_routing_stop_rtp_parameter,
{ "Parameter", "ua3g.ip.stop_rtp.parameter",
FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_stop_rtp_vals), 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip_device_routing_stop_rtp_parameter_length,
{ "Length", "ua3g.ip.stop_rtp.parameter.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip_device_routing_stop_rtp_parameter_value_num,
{ "Value", "ua3g.ip.stop_rtp.parameter.value.num",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_ip_device_routing_stop_rtp_parameter_value_bytes,
{ "Value", "ua3g.ip.stop_rtp.parameter.value.bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ua3g_subdevice_address, { "Subdevice Address", "ua3g.subdevice.address", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_ua3g_subdevice_opcode, { "Subdevice Opcode", "ua3g.subdevice.opcode", FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL }},
{ &hf_ua3g_subdevice_parameter_bytes, { "Parameter Bytes", "ua3g.subdevice.parameter_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_software_reset, { "Software Reset", "ua3g.software_reset", FT_UINT8, BASE_DEC, VALS(software_reset_verswitch_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_phone_warmstart, { "IP Phone Warmstart", "ua3g.ip_phone_warmstart", FT_UINT8, BASE_DEC, VALS(str_command_ip_phone_warmstart), 0x0, NULL, HFILL }},
{ &hf_ua3g_super_msg_length, { "Length", "ua3g.super_msg.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_super_msg_data, { "Data", "ua3g.super_msg.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_segment_msg_num_remaining, { "Number Of Remaining Segments", "ua3g.segment_msg.num_remaining", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_ua3g_segment_msg_length, { "Length", "ua3g.segment_msg.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_segment_message_data, { "Segment Message Data", "ua3g.segment_message.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter, { "Parameter", "ua3g.ip.reset.parameter", FT_UINT8, BASE_DEC, VALS(ip_device_routing_cmd_reset_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_length, { "Length", "ua3g.ip.reset.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_direction, { "Direction", "ua3g.ip.start_rtp.direction", FT_UINT8, BASE_DEC, VALS(start_rtp_str_direction), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter, { "Parameter", "ua3g.ip.start_rtp.parameter", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ip_device_routing_cmd_start_rtp_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_length, { "Length", "ua3g.ip.start_rtp.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_redirect_parameter, { "Parameter", "ua3g.ip.redirect.parameter", FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_redirect_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_redirect_parameter_length, { "Length", "ua3g.ip.redirect.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_def_tones_num_entries, { "Number Of Entries", "ua3g.ip.def_tones.num_entries", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_def_tones_frequency_1, { "Frequency 1 (Hz)", "ua3g.ip.def_tones.frequency_1", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_def_tones_level_1, { "Level 1 (dB)", "ua3g.ip.def_tones.level_1", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_def_tones_frequency_2, { "Frequency 2 (Hz)", "ua3g.ip.def_tones.frequency_2", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_def_tones_level_2, { "Level 2 (dB)", "ua3g.ip.def_tones.level_2", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_tone_direction, { "Direction", "ua3g.ip.start_tone.direction", FT_UINT8, BASE_DEC, VALS(ip_device_routing_tone_direction_vals), 0xC0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_tone_num_entries, { "Number of entries", "ua3g.ip.start_tone.num_entries", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_tone_identification, { "Identification", "ua3g.ip.start_tone.identification", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_tone_duration, { "Duration (ms)", "ua3g.ip.start_tone.duration", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_listen_rtp_parameter, { "Parameter", "ua3g.ip.listen_rtp.parameter", FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_listen_rtp_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_listen_rtp_parameter_length, { "Length", "ua3g.ip.listen_rtp.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_get_param_req_parameter, { "Parameter", "ua3g.ip.get_param_req.parameter", FT_UINT8, BASE_DEC, VALS(ip_device_routing_cmd_get_param_req_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter, { "Parameter", "ua3g.ip.set_param_req.parameter", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ip_device_routing_cmd_set_param_req_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_length, { "Length", "ua3g.ip.set_param_req.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_digit_value, { "Digit Value", "ua3g.ip.digit_value", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &str_digit_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_pause_restart_rtp_parameter, { "Parameter", "ua3g.ip.pause_restart_rtp.parameter", FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_pause_restart_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_length, { "Length", "ua3g.ip.pause_restart_rtp.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_value, { "Value", "ua3g.ip.pause_restart_rtp.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter, { "Parameter", "ua3g.ip.start_stop_record_rtp.parameter", FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_record_rtp_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_length, { "Length", "ua3g.ip.start_stop_record_rtp.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_debug_in_line, { "Text String With Debug", "ua3g.debug_in_line", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_command_led_number, { "Led Number", "ua3g.command.led.number", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options, { "LCD Options", "ua3g.command.lcd_line.lcd_options", FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_starting_column, { "Starting Column", "ua3g.command.lcd_line.starting_column", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_tune, { "Tune", "ua3g.main_voice_mode.tune", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_cadence, { "Cadence", "ua3g.main_voice_mode.cadence", FT_UINT8, BASE_DEC, VALS(str_cadence), 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_speaker_volume, { "Speaker Volume", "ua3g.main_voice_mode.speaker_volume", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_microphone_volume, { "Microphone Volume", "ua3g.main_voice_mode.microphone_volume", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_sending_level, { "Sending Level (dB)", "ua3g.main_voice_mode.sending_level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_handset_level, { "Receiving Level (dB)", "ua3g.main_voice_mode.handset_level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_headset_level, { "Receiving Level (dB)", "ua3g.main_voice_mode.headset_level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_main_voice_mode_handsfree_level, { "Sending Level (dB)", "ua3g.main_voice_mode.handsfree_level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_metastate_subchannel_address, { "Subchannel Address", "ua3g.subdevice_metastate.subchannel_address", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_metastate_new_metastate, { "New Metastate", "ua3g.subdevice_metastate.new_metastate", FT_UINT8, BASE_DEC, VALS(str_new_metastate), 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_dtmf_clck_format_minimum_on_time, { "Minimum 'ON' Time (ms)", "ua3g.dwl_dtmf_clck_format.minimum_on_time", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_dtmf_clck_format_inter_digit_pause_time, { "Inter-Digit Pause Time (ms)", "ua3g.dwl_dtmf_clck_format.inter_digit_pause_time", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_dtmf_clck_format_clock_time_format, { "Clock Time Format", "ua3g.dwl_dtmf_clck_format.clock_time_format", FT_UINT8, BASE_DEC, VALS(str_clock_format), 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_dtmf_clck_format_dtmf_country_adaptation, { "DTMF Country Adaptation", "ua3g.dwl_dtmf_clck_format.dtmf_country_adaptation", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_channel_mode, { "Channel Mode", "ua3g.voice_channel.channel_mode", FT_BOOLEAN, 8, TFS(&tfs_voice_channel_channel_mode), 0x01, NULL, HFILL }},
{ &hf_ua3g_voice_channel_codec, { "Codec", "ua3g.voice_channel.codec", FT_BOOLEAN, 8, TFS(&tfs_voice_channel_codec), 0x02, NULL, HFILL }},
{ &hf_ua3g_voice_channel_voice_channel, { "Voice Channel", "ua3g.voice_channel.voice_channel", FT_BOOLEAN, 8, TFS(&tfs_voice_channel_voice_channel), 0x04, NULL, HFILL }},
{ &hf_ua3g_voice_channel_main_voice, { "Main Voice", "ua3g.voice_channel.main_voice", FT_UINT8, BASE_DEC, VALS(str_voice_channel), 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_announce, { "Announce", "ua3g.voice_channel.announce", FT_UINT8, BASE_DEC, VALS(str_voice_channel), 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_b_general, { "B General", "ua3g.voice_channel.b_general", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_b_loud_speaker, { "B Loud Speaker", "ua3g.voice_channel.b_loud_speaker", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_b_ear_piece, { "B Ear Piece", "ua3g.voice_channel.b_ear_piece", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_voice_channel_b_microphones, { "B Microphones", "ua3g.voice_channel.b_microphones", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_lcd_cursor_line_number, { "Line Number", "ua3g.lcd_cursor.line_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_special_char_character_number, { "Character Number", "ua3g.dwl_special_char.character_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_dwl_special_char_byte, { "Byte", "ua3g.dwl_special_char.byte", FT_UINT8, BASE_DEC, NULL, 0xFF, NULL, HFILL }},
{ &hf_ua3g_set_clck_timer_pos_clock_line_number, { "Clock Line Number", "ua3g.set_clck_timer_pos.clock_line_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_set_clck_timer_pos_clock_column_number, { "Clock Column Number", "ua3g.set_clck_timer_pos.clock_column_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_set_clck_timer_pos_call_timer_line_number, { "Call Timer Line Number", "ua3g.set_clck_timer_pos.call_timer_line_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_set_clck_timer_pos_call_timer_column_number, { "Call Timer Column Number", "ua3g.set_clck_timer_pos.call_timer_column_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_set_lcd_contrast_driver_number, { "Driver Number", "ua3g.set_lcd_contrast.driver_number", FT_UINT8, BASE_DEC, VALS(str_driver_number), 0x0, NULL, HFILL }},
{ &hf_ua3g_set_lcd_contrast_contrast_value, { "Contrast Value", "ua3g.set_lcd_contrast.contrast_value", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_destination, { "Destination", "ua3g.command.beep.destination", FT_UINT8, BASE_DEC, VALS(str_beep_start_destination), 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_on_off, { "On / Off", "ua3g.command.beep.on_off", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80, NULL, HFILL }},
{ &hf_ua3g_beep_cadence, { "Cadence", "ua3g.command.beep.cadence", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_beep_number, { "Beep Number", "ua3g.command.beep.beep_number", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_number_of_notes, { "Number Of Notes", "ua3g.command.beep.number_of_notes", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_terminator, { "Terminator", "ua3g.command.beep.terminator", FT_UINT8, BASE_DEC, VALS(str_beep_terminator), 0x0, NULL, HFILL }},
{ &hf_ua3g_sidetone_level, { "Level", "ua3g.command.sidetone.level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ringing_cadence_cadence, { "Cadence", "ua3g.ringing_cadence.cadence", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ringing_cadence_on_off, { "On / Off", "ua3g.ringing_cadence.on_off", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80, NULL, HFILL }},
{ &hf_ua3g_ringing_cadence_length, { "Length (ms)", "ua3g.ringing_cadence.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_feedback_level, { "Level (dB)", "ua3g.command.feedback.level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_feedback_duration, { "Duration (ms)", "ua3g.command.feedback.duration", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_r_w_peripheral_address, { "Address", "ua3g.r_w_peripheral.address", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_r_w_peripheral_content, { "Content", "ua3g.r_w_peripheral.content", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_icon_cmd_icon_number, { "Icon Number", "ua3g.icon_cmd.icon_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_icon_cmd_segment, { "Segment", "ua3g.icon_cmd.segment", FT_UINT16, BASE_DEC, VALS(str_icon_cmd_state), 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_ignored, { "Ignored", "ua3g.command.audio_config.ignored", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_law, { "Law", "ua3g.command.audio_config.law", FT_UINT8, BASE_DEC, VALS(str_audio_coding_law), 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_volume_level, { "Volume Level", "ua3g.command.audio_config.volume_level", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_handsfree_return, { "Return", "ua3g.command.audio_config.handsfree_return", FT_BOOLEAN, 8, TFS(&tfs_audio_config_handsfree_return), 0x01, NULL, HFILL }},
{ &hf_ua3g_audio_config_handsfree_handsfree, { "Handsfree", "ua3g.command.audio_config.handsfree", FT_BOOLEAN, 8, TFS(&tfs_audio_config_handsfree_handsfree), 0x02, NULL, HFILL }},
{ &hf_ua3g_audio_padded_path_emission_padded_level, { "Emission Padded Level", "ua3g.audio_padded_path.emission_padded_level", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_padded_path_reception_padded_level, { "Reception Padded Level", "ua3g.audio_padded_path.reception_padded_level", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_on_off_level_level_on_loudspeaker, { "Level on Loudspeaker (dB)", "ua3g.on_off_level.level_on_loudspeaker", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ring_melody, { "Melody", "ua3g.command.ring.melody", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ring_cadence, { "Cadence", "ua3g.command.ring.cadence", FT_UINT8, BASE_DEC, VALS(str_cadence), 0x0, NULL, HFILL }},
{ &hf_ua3g_ring_speaker_level, { "Speaker level (dB)", "ua3g.command.ring.speaker_level", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ring_beep_number, { "Beep number", "ua3g.command.ring.beep_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ring_silent, { "Silent", "ua3g.command.ring.silent", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80, NULL, HFILL }},
{ &hf_ua3g_ring_progressive, { "Progressive", "ua3g.command.ring.progressive", FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_item_identifier, { "Item Identifier", "ua3g.ua_dwl_protocol.item_identifier", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_cause, { "Cause", "ua3g.ua_dwl_protocol.cause", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_force_mode, { "Force Mode", "ua3g.ua_dwl_protocol.force_mode", FT_UINT8, BASE_DEC, VALS(str_download_req_force_mode), 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_item_version, { "Item Version", "ua3g.ua_dwl_protocol.item_version", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_item_version_nc, { "Item Version", "ua3g.ua_dwl_protocol.item_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_binary_length, { "Binary Length", "ua3g.ua_dwl_protocol.binary_length", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_packet_number, { "Packet Number", "ua3g.ua_dwl_protocol.packet_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_download_ack_status, { "Status", "ua3g.ua_dwl_protocol.download_ack_status", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &str_download_ack_status_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_packet_download_end_ack_ok_status, { "Status", "ua3g.ua_dwl_protocol_packet.download_end_ack_ok_status", FT_UINT8, BASE_DEC, VALS(str_download_end_ack_ok), 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_checksum, { "Checksum", "ua3g.ua_dwl_protocol.checksum", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_acknowledge, { "Acknowledge", "ua3g.ua_dwl_protocol.acknowledge", FT_UINT8, BASE_DEC, VALS(str_iso_checksum_ack_status), 0x0, NULL, HFILL }},
{ &hf_ua3g_digit_dialed_digit_value, { "Digit Value", "ua3g.digit_dialed.digit_value", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &str_digit_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_msg_subdev_type, { "Subdev Type", "ua3g.subdevice_msg.subdev_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_msg_subdev_address, { "Subdev Address", "ua3g.subdevice_msg.subdev_address", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_msg_subdevice_opcode, { "Subdevice Opcode", "ua3g.subdevice_msg.subdevice_opcode", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_msg_parameter_bytes, { "Parameter Bytes", "ua3g.subdevice_msg.parameter_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd00_vta_type, { "VTA Type", "ua3g.ip.cs.cmd00.vta_type", FT_UINT8, BASE_DEC, VALS(str_cs_ip_device_routing_vta_type), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd00_characteristic_number, { "Characteristic Number", "ua3g.ip.cs.cmd00.characteristic_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd01_incident_0, { "Incident 0", "ua3g.ip.cs.cmd01.incident_0", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter, { "Parameter", "ua3g.ip.cs.cmd02.parameter", FT_UINT8, BASE_HEX, VALS(ip_device_routing_cmd_get_param_req_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_length, { "Length", "ua3g.ip.cs.cmd02.parameter.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter, { "Parameter", "ua3g.ip.cs.cmd03.parameter", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &cs_ip_device_routing_03_parameter_id_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_length, { "Length", "ua3g.ip.cs.cmd03.parameter.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_device_type, { "Device Type", "ua3g.unsolicited_msg.device_type", FT_UINT8, BASE_DEC, VALS(str_device_type), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_self_test_result, { "Self-Test Result", "ua3g.unsolicited_msg.self_test_result", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_vta_type, { "VTA Type", "ua3g.unsolicited_msg.vta_type", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_vta_type), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_other_information, { "Other Information", "ua3g.unsolicited_msg.other_information", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_other_info_2), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_other_information_1, { "Other Information 1", "ua3g.unsolicited_msg.other_information_1", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_other_info_1), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_version, { "Hardware Version", "ua3g.unsolicited_msg.hardware_version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_other_information_2, { "Other Information 2", "ua3g.unsolicited_msg.other_information_2", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_other_info_2), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_firmware_datas_patch_version, { "Firmware Datas Patch Version", "ua3g.unsolicited_msg.firmware_datas_patch_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_firmware_version_loader, { "Firmware Version (Loader)", "ua3g.unsolicited_msg.firmware_version_loader", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_firmware_version, { "Firmware Version", "ua3g.unsolicited_msg.firmware_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_datas_version, { "Datas Version", "ua3g.unsolicited_msg.datas_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_firmware_version_bootloader, { "Firmware Version (Bootloader)", "ua3g.unsolicited_msg.firmware_version_bootloader", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_opcode_of_bad_command, { "Opcode Of Bad Command", "ua3g.unsolicited_msg.opcode_of_bad_command", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_next_byte_of_bad_command, { "Next Byte Of Bad Command", "ua3g.unsolicited_msg.next_byte_of_bad_command", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_subdevice_address, { "Subdevice Address", "ua3g.unsolicited_msg.subdevice_address", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_segment_failure_t, { "T", "ua3g.unsolicited_msg.segment_failure.t", FT_BOOLEAN, 8, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_segment_failure_num, { "Num", "ua3g.unsolicited_msg.segment_failurenum", FT_BOOLEAN, 8, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_segment_failure_s, { "/S", "ua3g.unsolicited_msg.segment_failure.s", FT_BOOLEAN, 8, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_segment_failure_l, { "L", "ua3g.unsolicited_msg.segment_failure.l", FT_BOOLEAN, 8, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_opcode_bad_segment, { "Opcode Bad Segment", "ua3g.unsolicited_msg.opcode_bad_segment", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_next_byte_of_bad_segment, { "Next Byte Of Bad Segment", "ua3g.unsolicited_msg.next_byte_of_bad_segment", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_device_event, { "Device Event", "ua3g.unsolicited_msg.device_event", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_i_m_here_id_code, { "Id Code", "ua3g.i_m_here.id_code", FT_UINT8, BASE_DEC, VALS(str_device_type), 0x0, NULL, HFILL }},
{ &hf_ua3g_segment_msg_segment, { "F/S", "ua3g.segment_msg.segment", FT_BOOLEAN, 8, TFS(&tfs_segment_msg_segment), 0x80, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update, { "NOE Update Mode", "ua3g.ip.reset.parameter.noe_update", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_bootloader, { "Bootloader", "ua3g.ip.reset.parameter.noe_update.bootloader", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_data, { "Data", "ua3g.ip.reset.parameter.noe_update.data", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_customization, { "Customization", "ua3g.ip.reset.parameter.noe_update.customization", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_localization, { "Localization", "ua3g.ip.reset.parameter.noe_update.localization", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_code, { "Code", "ua3g.ip.reset.parameter.noe_update.code", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_noe_update_sip, { "SIP", "ua3g.ip.reset.parameter.noe_update.sip", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_bad_sec_mode, { "Bad Sec Mode", "ua3g.ip.reset.parameter.bad_sec_mode", FT_UINT8, BASE_DEC, VALS(reset_param_bad_sec_mode), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_value, { "Value", "ua3g.ip.reset.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_cust_name, { "Cust_Name", "ua3g.ip.reset.parameter.cust_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_reset_parameter_l10n_name, { "L10N_Name", "ua3g.ip.reset.parameter.l10n_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_value, { "Value", "ua3g.ip.start_rtp.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_ip, { "IP", "ua3g.ip.start_rtp.parameter.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_compressor, { "Compressor", "ua3g.ip.start_rtp.parameter.compressor", FT_UINT64, BASE_DEC|BASE_VAL64_STRING, VALS64(str_start_rtp_compressor), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_enabler, { "Enabler", "ua3g.ip.start_rtp.parameter.enabler", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_send_qos, { "Must Send QOS Tickets", "ua3g.ip.start_rtp.parameter.enabler", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_uint, { "Value", "ua3g.ip.start_rtp.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_dtmf_sending, { "Send DTMF", "ua3g.ip.start_rtp.parameter.dtmf_sending", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_rfc2198, { "Enable RFC 2198", "ua3g.ip.start_rtp.parameter.rfc2198", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_rtp_parameter_srtp_encryption, { "Enable SRTP Encryption", "ua3g.ip.start_rtp.parameter.srtp_encryption", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_redirect_parameter_value, { "Value", "ua3g.ip.redirect.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_redirect_parameter_ip, { "IP", "ua3g.ip.redirect.parameter.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_redirect_parameter_uint, { "Value", "ua3g.ip.redirect.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_listen_rtp_parameter_value, { "Value", "ua3g.ip.listen_rtp.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_listen_rtp_parameter_ip, { "IP", "ua3g.ip.listen_rtp.parameter.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_listen_rtp_parameter_port, { "Port", "ua3g.ip.listen_rtp.parameter.port", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_value, { "Value", "ua3g.ip.set_param_req.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_tftp_backup_ip, { "TFTP Backup IP", "ua3g.ip.set_param_req.parameter.tftp_backup_ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_uint, { "Value", "ua3g.ip.set_param_req.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_err_string, { "Value", "ua3g.ip.set_param_req.parameter.err_string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_compressor, { "Compressor", "ua3g.ip.set_param_req.parameter.compressor", FT_UINT8, BASE_DEC, VALS(str_set_param_req_compressor), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_set_pc_port_status, { "Set PC Port status", "ua3g.ip.set_param_req.parameter.set_pc_port_status", FT_UINT8, BASE_DEC, VALS(str_set_pc_port_status), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_record_rtp_auth, { "Record RTP Authorization", "ua3g.ip.set_param_req.parameter.record_rtp_auth", FT_UINT8, BASE_DEC, VALS(str_enable_feature), 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_set_param_req_parameter_security_flag_filter, { "Filtering", "ua3g.ip.set_param_req.parameter.security_flag.filter", FT_BOOLEAN, 8, TFS(&tfs_active_inactive), 0x01, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_pause_restart_rtp_parameter_uint, { "Value", "ua3g.ip.pause_restart_rtp.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_value, { "Value", "ua3g.ip.start_stop_record_rtp.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_remote_ip, { "Remote IP", "ua3g.ip.start_stop_record_rtp.parameter.remote_ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ip_device_routing_start_stop_record_rtp_parameter_uint, { "Value", "ua3g.ip.start_stop_record_rtp.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_dpi_chan_ua_tx1, { "UA Channel UA-TX1", "ua3g.command.audio_config.dpi_chan.ua_tx1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_dpi_chan_ua_tx2, { "UA Channel UA-TX2", "ua3g.command.audio_config.dpi_chan.ua_tx2", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_dpi_chan_gci_tx1, { "GCI Channel GCI-TX1", "ua3g.command.audio_config.dpi_chan.gci_tx1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_dpi_chan_gci_tx2, { "GCI Channel GCI-TX2", "ua3g.command.audio_config.dpi_chan.gci_tx2", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_dpi_chan_cod_tx, { "Codec Channel COD-TX", "ua3g.command.audio_config.dpi_chan.cod_tx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_dth, { "Anti-Distortion Coeff 1(DTH)", "ua3g.command.audio_config.audio_circuit.dth", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_dtr, { "Anti-Distortion Coeff 2(DTR)", "ua3g.command.audio_config.audio_circuit.dtr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_dtf, { "Anti-Distortion Coeff 3(DTF)", "ua3g.command.audio_config.audio_circuit.dtf", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_str, { "Sidetone Attenuation (STR)", "ua3g.command.audio_config.audio_circuit.str", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_ahp1, { "Anti-Larsen Coeff 1 (AHP1)", "ua3g.command.audio_config.audio_circuit.ahp1", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_ahp2, { "Anti-Larsen Coeff 2 (AHP2)", "ua3g.command.audio_config.audio_circuit.ahp2", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_ath, { "Anti-Larsen Coeff 3 (ATH)", "ua3g.command.audio_config.audio_circuit.ath", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_atr, { "Anti-Larsen Coeff 4 (ATR)", "ua3g.command.audio_config.audio_circuit.atr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_atf, { "Anti-Larsen Coeff 5 (ATF)", "ua3g.command.audio_config.audio_circuit.atf", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_audio_circuit_alm, { "Anti-Larsen Coeff 6 (ALM)", "ua3g.command.audio_config.audio_circuit.alm", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_group_listen, { "Group Listening Attenuation Constant", "ua3g.command.audio_config.loudspeaker_aco_param.group_listen", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_attenuation, { "Handsfree Attenuation Constant", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_attenuation", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_stay_in_send, { "Handsfree Number Of ms To Stay In Send State Before Going To Another State", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_stay_in_send", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_shift_right_mtx, { "Handsfree Number Of Positions To Shift Right MTx", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_shift_right_mtx", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_shift_right_mrc, { "Handsfree Number Of Positions To Shift Right MRc", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_shift_right_mrc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_idle_trans_threshold, { "Handsfree Idle Transmission Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_idle_trans_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_low_trans_threshold, { "Handsfree Low Transmission Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_low_trans_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_idle_recv_threshold, { "Handsfree Idle Reception Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_idle_recv_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_low_recv_threshold, { "Handsfree Low Reception Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_low_recv_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_med_recv_threshold, { "Handsfree Medium Reception Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_med_recv_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_audio_config_loudspeaker_aco_param_handsfree_high_recv_threshold, { "Handsfree High Reception Threshold", "ua3g.command.audio_config.loudspeaker_aco_param.handsfree_high_recv_threshold", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_files_inc_boot_binary, { "Boot Binary Included", "ua3g.ua_dwl_protocol.files_inc.boot_binary", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_files_inc_loader_binary, { "Loader Binary Included", "ua3g.ua_dwl_protocol.files_inc.loader_binary", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_files_inc_appli_binary, { "Appli Binary Included", "ua3g.ua_dwl_protocol.files_inc.appli_binary", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_files_inc_data_binary, { "Datas Binary Included", "ua3g.ua_dwl_protocol.files_inc.data_binary", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_model_selection_a, { "For A Model", "ua3g.ua_dwl_protocol.model_selection.a", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_model_selection_b, { "For B Model", "ua3g.ua_dwl_protocol.model_selection.b", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_model_selection_c, { "For C Model", "ua3g.ua_dwl_protocol.model_selection.c", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_model_selection_country_ver, { "Country Version", "ua3g.ua_dwl_protocol.model_selection.country_ver", FT_UINT8, BASE_DEC, VALS(str_download_req_mode_selection_country), 0xE0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_hardware_selection_ivanoe1, { "For Ivanoe 1", "ua3g.ua_dwl_protocol.hardware_selection.ivanoe1", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_hardware_selection_ivanoe2, { "For Ivanoe 2", "ua3g.ua_dwl_protocol.hardware_selection.ivanoe2", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_memory_sizes_flash, { "Flash Min Size", "ua3g.ua_dwl_protocol.memory_sizes.flash", FT_UINT8, BASE_DEC, VALS(str_mem_size), 0x07, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_memory_sizes_ext_ram, { "External Ram Min Size", "ua3g.ua_dwl_protocol.memory_sizes.ext_ram", FT_UINT8, BASE_DEC, VALS(str_mem_size), 0x38, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_char_num_vta_subtype, { "VTA SubType", "ua3g.unsolicited_msg.char_num.vta_subtype", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_subtype), 0xC0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_char_num_generation, { "Generation", "ua3g.unsolicited_msg.char_num.generation", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_generation), 0x38, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_char_num_design, { "Design", "ua3g.unsolicited_msg.char_num.design", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_design), 0x07, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_vta_type, { "VTA Type", "ua3g.unsolicited_msg.hardware_config.vta_type", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_vta_type), 0xE0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_design, { "Design", "ua3g.unsolicited_msg.hardware_config.design", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_design), 0x1C, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_subtype, { "VTA SubType", "ua3g.unsolicited_msg.hardware_config.subtype", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_subtype), 0x03, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_hard_config_chip, { "Chip Id", "ua3g.unsolicited_msg.hardware_config.hard_config_chip", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_config_chip), 0x03, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_hard_config_flash, { "Flash Size", "ua3g.unsolicited_msg.hardware_config.hard_config_flash", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_config_flash), 0x1C, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_config_ram, { "External RAM Size", "ua3g.unsolicited_msg.hardware_config.config_ram", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_config_ram), 0xE0, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hardware_config_hard_config_ip, { "Hardware Configuration", "ua3g.unsolicited_msg.hardware_config.ip", FT_UINT8, BASE_DEC, VALS(str_unsolicited_msg_hard_config_ip), 0x01, NULL, HFILL }},
{ &hf_ua3g_unsolicited_msg_hook_status, { "Hook Status", "ua3g.unsolicited_msg.hook_status", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x00, NULL, HFILL }},
{ &hf_ua3g_special_key_shift, { "Shift", "ua3g.special_key.shift", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x01, NULL, HFILL }},
{ &hf_ua3g_special_key_ctrl, { "Ctrl", "ua3g.special_key.ctrl", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x02, NULL, HFILL }},
{ &hf_ua3g_special_key_alt, { "Alt", "ua3g.special_key.alt", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x04, NULL, HFILL }},
{ &hf_ua3g_special_key_cmd, { "Cmd", "ua3g.special_key.cmd", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x08, NULL, HFILL }},
{ &hf_ua3g_special_key_shift_prime, { "Shift'", "ua3g.special_key.shift_prime", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x10, NULL, HFILL }},
{ &hf_ua3g_special_key_ctrl_prime, { "Ctrl'", "ua3g.special_key.ctrl_prime", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x20, NULL, HFILL }},
{ &hf_ua3g_special_key_alt_prime, { "Alt'", "ua3g.special_key.alt_prime", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x40, NULL, HFILL }},
{ &hf_ua3g_special_key_cmd_prime, { "Cmd'", "ua3g.special_key.cmd_prime", FT_BOOLEAN, 8, TFS(&tfs_released_pressed), 0x80, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_call_timer, { "Call Timer", "ua3g.lcd_line_cmd.lcd_options.call_timer", FT_UINT8, BASE_DEC, VALS(str_call_timer_ctrl), 0x03, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_blink, { "Blink", "ua3g.lcd_line_cmd.lcd_options.blink", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_call_timer_control, { "Call Timer Control", "ua3g.lcd_line_cmd.lcd_options.call_timer_control", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x10, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_call_timer_display, { "Call Timer Display", "ua3g.lcd_line_cmd.lcd_options.call_timer_display", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_time_of_day_display, { "Time Of Day Display", "ua3g.lcd_line_cmd.lcd_options.time_of_day_display", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x40, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_lcd_options_suspend_display_refresh, { "Suspend Display Refresh", "ua3g.lcd_line_cmd.lcd_options.suspend_display_refresh", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x80, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_value, { "Value", "ua3g.ip.cs.cmd02.parameter.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_ip, { "IP", "ua3g.ip.cs.cmd02.parameter.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_mac_address, { "MAC Address", "ua3g.ip.cs.cmd02.parameter.mac_address", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_uint, { "Value", "ua3g.ip.cs.cmd02.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_default_codec_bytes, { "Default Codec", "ua3g.ip.cs.cmd02.parameter.default_codec.bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_default_codec_uint, { "Default Codec", "ua3g.ip.cs.cmd02.parameter.default_codec.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_firmware_version, { "Firmware Version", "ua3g.ip.cs.cmd02.parameter.firmware_version", FT_UINT16, BASE_CUSTOM, CF_FUNC(version_number_computer), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_speed, { "Port Lan Speed", "ua3g.ip.cs.cmd02.parameter.eth_driver_config.port_lan_speed", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_lan_duplex, { "Port Lan Duplex", "ua3g.ip.cs.cmd02.parameter.eth_driver_config.port_lan_duplex", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_pc_speed, { "Port PC Speed", "ua3g.ip.cs.cmd02.parameter.eth_driver_config.port_pc_speed", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd02_parameter_eth_driver_config_port_pc_duplex, { "Port PC Duplex", "ua3g.ip.cs.cmd02.parameter.eth_driver_config.port_pc_duplex", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_ip, { "IP", "ua3g.ip.cs.cmd03.parameter.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_string, { "IP", "ua3g.ip.cs.cmd03.parameter.string", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_type_of_equip1, { "Type Of Equipment (first byte)", "ua3g.ip.cs.cmd03.parameter.type_of_equip1", FT_UINT8, BASE_DEC, VALS(cs_ip_device_routing_cmd03_first_byte_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_type_of_equip2, { "Type Of Equipment (second byte)", "ua3g.ip.cs.cmd03.parameter.type_of_equip2", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_cmd03_second_byte_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_default_codec, { "Default Codec", "ua3g.ip.cs.cmd03.parameter.default_codec", FT_UINT64, BASE_DEC|BASE_VAL64_STRING, VALS64(str_cs_ip_device_routing_0F_compressor), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_vad, { "VAD", "ua3g.ip.cs.cmd03.parameter.vad", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_ece, { "ECE", "ua3g.ip.cs.cmd03.parameter.ece", FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_voice_mode, { "Voice Mode", "ua3g.ip.cs.cmd03.parameter.voice_mode", FT_UINT64, BASE_DEC|BASE_VAL64_STRING, VALS64(cs_ip_device_routing_cmd03_voice_mode_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_delay_distribution, { "Delay Distribution", "ua3g.ip.cs.cmd03.parameter.delay_distribution", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_delay_distribution_range_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_consecutive_bfi, { "Consecutive BFI", "ua3g.ip.cs.cmd03.parameter.consecutive_bfi", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_consecutive_bfi_range_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_bfi_distribution, { "BFI Distribution", "ua3g.ip.cs.cmd03.parameter.bfi_distribution", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_bfi_distribution_range_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_8021Q_used, { "802.1 Q Used", "ua3g.ip.cs.cmd03.parameter.8021Q_used", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_8021P_priority, { "802.1p Priority", "ua3g.ip.cs.cmd03.parameter.8021P_priority", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_vlan_id, { "VLAN Id", "ua3g.ip.cs.cmd03.parameter.vlan_id", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_diffserv, { "DiffServ", "ua3g.ip.cs.cmd03.parameter.diffserv", FT_UINT8, BASE_DEC, NULL, 0xFC, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_bfi_distribution_200ms, { "200 ms BFI Distribution", "ua3g.ip.cs.cmd03.parameter.bfi_distribution_200ms", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_200ms_bfi_distribution_range_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_uint, { "Value", "ua3g.ip.cs.cmd03.parameter.uint", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_consecutive_rtp_lost, { "Consecutive RTP Lost", "ua3g.ip.cs.cmd03.parameter.consecutive_rtp_lost", FT_UINT16, BASE_DEC, VALS(cs_ip_device_routing_consecutive_rtp_lost_range_vals), 0x0, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_cmd03_parameter_jitter_depth_distribution, { "Jitter Depth Distribution", "ua3g.ip.cs.cmd03.parameter.jitter_depth_distribution", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_subdevice_state, { "Subdevice State", "ua3g.subdevice_state", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_special_key_param_dtmf, { "Parameters Received for DTMF", "ua3g.special_key.param_dtmf", FT_BOOLEAN, 8, TFS(&tfs_special_key_parameters), 0x02, NULL, HFILL }},
{ &hf_ua3g_special_key_hookswitch_status, { "Hookswitch Status", "ua3g.special_key.hookswitch_status", FT_BOOLEAN, 8, TFS(&tfs_hookswitch_status), 0x01, NULL, HFILL }},
{ &hf_ua3g_cs_ip_device_routing_param_identifier, { "Parameter Identifier", "ua3g.ip.cs.param_identifier", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_key_number, { "Key Number", "ua3g.key_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_ua_dwl_protocol_binary_info, { "Binary information", "ua3g.ua_dwl_protocol.binary_info", FT_BOOLEAN, 8, TFS(&tfs_bin_info), 0x01, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_unused, { "Unused", "ua3g.command.lcd_line.unused", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_lcd_line_cmd_ascii_char, { "ASCII Char", "ua3g.command.lcd_line.ascii_char", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_call_timer, { "Call Timer", "ua3g.command.call_timer", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_current_time, { "Current Timer", "ua3g.command.current_time", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination, { "Destination", "ua3g.command.beep.destination", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination_handset, { "Handset", "ua3g.command.beep.destination.handset", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination_headset, { "Headset", "ua3g.command.beep.destination.headset", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination_loudspeaker, { "Loudspeeker", "ua3g.command.beep.destination.loudspeaker", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination_announce_loudspeaker, { "Announce Loudspeeker", "ua3g.command.beep.destination.announce_loudspeaker", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ua3g_beep_beep_destination_handsfree, { "Handsfree", "ua3g.command.beep.destination.handsfree", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ua3g_beep_freq_sample, { "Freq sample", "ua3g.command.beep.note.freq_sample", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_level, { "Level", "ua3g.command.beep.note.level", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_beep_duration, { "Duration", "ua3g.command.beep.note.duration", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ua3g_device_configuration, { "Device Configuration", "ua3g.device_configuration", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] =
{
&ett_ua3g,
&ett_ua3g_body,
&ett_ua3g_param,
&ett_ua3g_param_sub,
&ett_ua3g_option,
&ett_ua3g_beep_beep_destination,
&ett_ua3g_note,
};
proto_ua3g = proto_register_protocol("UA3G Message", "UA3G", "ua3g");
proto_register_field_array(proto_ua3g, hf, array_length(hf));
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
