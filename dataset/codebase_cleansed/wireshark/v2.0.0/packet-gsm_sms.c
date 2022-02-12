static void
gsm_sms_defragment_init (void)
{
reassembly_table_init(&g_sm_reassembly_table,
&addresses_reassembly_table_functions);
g_sm_fragment_params_table = g_hash_table_new(g_direct_hash, g_direct_equal);
}
static void
gsm_sms_defragment_cleanup (void)
{
reassembly_table_destroy(&g_sm_reassembly_table);
g_hash_table_destroy(g_sm_fragment_params_table);
}
static void
dis_field_addr(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 *offset_p, const gchar *title)
{
static gchar digit_table[] = {"0123456789*#abc\0"};
proto_item *item;
proto_tree *subtree;
guint8 oct;
guint32 offset;
guint32 numdigocts;
guint32 length, addrlength;
guint32 i, j;
gchar *addrstr;
offset = *offset_p;
addrlength = tvb_get_guint8(tvb, offset);
numdigocts = (addrlength + 1) / 2;
length = tvb_reported_length_remaining(tvb, offset);
if (length <= numdigocts)
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length, "%s: Short Data (?)", title);
*offset_p += length;
return;
}
subtree = proto_tree_add_subtree(tree, tvb,
offset, numdigocts + 2, ett_addr, &item, title);
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_dis_field_addr_length,
tvb, offset, 1,
addrlength, "%d address digits", addrlength);
offset++;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_addr_extension, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_addr_num_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_addr_num_plan, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
j = 0;
switch ((oct & 0x70) >> 4)
{
case 0x05:
addrlength = (addrlength << 2) / 7;
addrstr = tvb_get_ts_23_038_7bits_string(wmem_packet_scope(), tvb, offset << 3,
(addrlength > MAX_ADDR_SIZE) ? MAX_ADDR_SIZE : addrlength);
break;
default:
addrstr = (gchar *)wmem_alloc(wmem_packet_scope(), numdigocts*2 + 1);
for (i = 0; i < numdigocts; i++)
{
oct = tvb_get_guint8(tvb, offset + i);
addrstr[j++] = digit_table[oct & 0x0f];
addrstr[j++] = digit_table[(oct & 0xf0) >> 4];
}
addrstr[j++] = '\0';
break;
}
if (g_ascii_strncasecmp(title, "TP-O", 4) == 0) {
proto_tree_add_string(subtree, hf_gsm_sms_tp_oa, tvb,
offset, numdigocts, addrstr);
} else if (g_ascii_strncasecmp(title, "TP-D", 4) == 0) {
proto_tree_add_string(subtree, hf_gsm_sms_tp_da, tvb,
offset, numdigocts, addrstr);
} else if (g_ascii_strncasecmp(title, "TP-R", 4) == 0) {
proto_tree_add_string(subtree, hf_gsm_sms_tp_ra, tvb,
offset, numdigocts, addrstr);
} else {
proto_tree_add_string(subtree, hf_gsm_sms_tp_digits, tvb,
offset, numdigocts, addrstr);
}
proto_item_append_text(item, " - (%s)", addrstr);
*offset_p = offset + numdigocts;
}
static void
dis_field_pid(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint8 oct)
{
proto_item *item;
proto_tree *subtree;
item = proto_tree_add_item(tree, hf_gsm_sms_tp_pid, tvb, offset, 1, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_pid);
switch ((oct & 0xc0) >> 6)
{
case 0:
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_format_subsequent_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_telematic_interworking, tvb, offset, 1, ENC_NA);
if (oct & 0x20)
{
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_device_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_sm_al_proto, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case 1:
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_format_subsequent_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_undefined, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_sc_specific_use, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_tp_pid_sc_specific, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
}
static void
dis_field_dcs(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint8 oct,
gboolean *seven_bit, gboolean *eight_bit, gboolean *ucs2, gboolean *compressed)
{
proto_item *item;
proto_tree *subtree;
gboolean default_5_bits;
gboolean default_3_bits;
gboolean default_data;
*seven_bit = FALSE;
*eight_bit = FALSE;
*ucs2 = FALSE;
*compressed = FALSE;
item = proto_tree_add_item(tree, hf_gsm_sms_tp_dcs, tvb, offset, 1, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_dcs);
if (oct&0x80) {
proto_tree_add_item(subtree, hf_gsm_sms_coding_group_bits4, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(subtree, hf_gsm_sms_coding_group_bits2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if (oct == 0x00)
{
proto_tree_add_item(subtree, hf_gsm_sms_gsm_7_bit_default_alphabet, tvb, offset, 1, ENC_NA);
*seven_bit = TRUE;
return;
}
default_5_bits = FALSE;
default_3_bits = FALSE;
default_data = FALSE;
switch ((oct & 0xc0) >> 6)
{
case 0:
default_5_bits = TRUE;
break;
case 1:
default_5_bits = TRUE;
break;
case 2:
return;
case 3:
switch ((oct & 0x30) >> 4)
{
case 0x00:
default_3_bits = TRUE;
*seven_bit = TRUE;
break;
case 0x01:
default_3_bits = TRUE;
*seven_bit = TRUE;
break;
case 0x02:
default_3_bits = TRUE;
break;
case 0x03:
default_data = TRUE;
break;
}
break;
}
if (default_5_bits)
{
*compressed = (oct & 0x20) >> 5;
proto_tree_add_item(subtree, hf_gsm_sms_dcs_text_compressed, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_message_class_defined, tvb, offset, 1, ENC_NA);
switch ((oct & 0x0c) >> 2)
{
case 0x00:
*seven_bit = TRUE;
break;
case 0x01:
*eight_bit = TRUE;
break;
case 0x02:
*ucs2 = TRUE;
break;
case 0x03:
break;
}
proto_tree_add_item(subtree, hf_gsm_sms_dcs_character_set, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_message_class, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else if (default_3_bits)
{
proto_tree_add_item(subtree, hf_gsm_sms_dcs_indication_sense, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_reserved04, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_message_waiting, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else if (default_data)
{
*seven_bit = !(*eight_bit = (oct & 0x04) ? TRUE : FALSE);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_reserved08, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_message_coding, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_dcs_message_class, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
dis_field_scts_aux(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
guint8 oct;
guint16 value;
char sign;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_year, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_month, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_day, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_hour, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_minutes, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(tree, hf_gsm_sms_scts_seconds, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
sign = (oct & 0x08)?'-':'+';
oct = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_uint_format_value(tree, hf_gsm_sms_scts_timezone, tvb, offset, 1,
oct, "GMT %c %d hours %d minutes",
sign, oct / 4, oct % 4 * 15);
}
static void
dis_field_scts(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 *offset_p)
{
proto_tree *subtree;
guint32 offset;
guint32 length;
offset = *offset_p;
length = tvb_reported_length_remaining(tvb, offset);
if (length < 7)
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length,
"TP-Service-Centre-Time-Stamp: Short Data (?)");
*offset_p += length;
return;
}
subtree = proto_tree_add_subtree(tree, tvb,
offset, 7, ett_scts, NULL,
"TP-Service-Centre-Time-Stamp");
dis_field_scts_aux(tvb, subtree, *offset_p);
*offset_p += 7;
}
static void
dis_field_vp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 *offset_p, guint8 vp_form)
{
proto_tree *subtree;
guint32 offset;
guint32 length;
guint8 oct;
guint8 loc_form;
guint16 value;
guint32 mins, hours;
gboolean done;
if (vp_form == 0x00) return;
offset = *offset_p;
subtree = tree;
done = FALSE;
do
{
switch (vp_form)
{
case 1:
length = tvb_reported_length_remaining(tvb, offset);
if (length < 7)
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length,
"TP-Validity-Period: Short Data (?)");
*offset_p += length;
return;
}
subtree = proto_tree_add_subtree(tree, tvb, offset, 7, ett_vp, NULL, "TP-Validity-Period");
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_gsm_sms_vp_extension, tvb, offset, 1, ENC_NA);
if (oct & 0x80)
{
proto_tree_add_item(subtree, hf_gsm_sms_vp_extension_ignored, tvb, offset + 1, 6, ENC_NA);
*offset_p += 7;
return;
}
proto_tree_add_item(subtree, hf_gsm_sms_vp_single_shot_sm, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_vp_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_vp_validity_period_format, tvb, offset, 1, ENC_BIG_ENDIAN);
loc_form = oct & 0x7;
switch (loc_form)
{
case 0x00:
done = TRUE;
break;
case 0x01:
offset++;
vp_form = 2;
break;
case 0x02:
offset++;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d seconds", oct);
done = TRUE;
break;
case 0x03:
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(subtree, hf_gsm_sms_vp_validity_period_hour, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(subtree, hf_gsm_sms_vp_validity_period_minutes, tvb, offset, 1, value);
offset++;
oct = tvb_get_guint8(tvb, offset);
value = (oct & 0x0f)*10 + ((oct & 0xf0) >> 4),
proto_tree_add_uint(subtree, hf_gsm_sms_vp_validity_period_seconds, tvb, offset, 1, value);
offset++;
done = TRUE;
break;
default:
done = TRUE;
break;
}
break;
case 2:
oct = tvb_get_guint8(tvb, offset);
if (oct <= 143)
{
mins = (oct + 1) * 5;
if (mins >= 60)
{
hours = mins / 60;
mins %= 60;
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d hours %d minutes", hours, mins);
}
else
{
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d minutes", mins);
}
}
else if ((oct >= 144) &&
(oct <= 167))
{
mins = (oct - 143) * 30;
hours = 12 + (mins / 60);
mins %= 60;
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d hours %d minutes", hours, mins);
}
else if ((oct >= 168) &&
(oct <= 196))
{
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d day(s)", oct - 166);
}
else if (oct >= 197)
{
proto_tree_add_uint_format_value(subtree, hf_gsm_sms_vp_validity_period, tvb, offset, 1,
oct, "%d week(s)", oct - 192);
}
done = TRUE;
break;
case 3:
length = tvb_reported_length_remaining(tvb, offset);
if (length < 7)
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length,
"TP-Validity-Period: Short Data (?)");
*offset_p += length;
return;
}
subtree = proto_tree_add_subtree(tree, tvb,
offset, 7, ett_vp, NULL,
"TP-Validity-Period: absolute");
dis_field_scts_aux(tvb, subtree, *offset_p);
done = TRUE;
break;
}
}
while (!done);
if (vp_form == 2)
{
(*offset_p)++;
}
else
{
*offset_p += 7;
}
}
static void
dis_field_dt(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 *offset_p)
{
proto_tree *subtree;
guint32 offset;
guint32 length;
offset = *offset_p;
length = tvb_reported_length_remaining(tvb, offset);
if (length < 7)
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length,
"TP-Discharge-Time: Short Data (?)");
*offset_p += length;
return;
}
subtree = proto_tree_add_subtree(tree, tvb,
offset, 7, ett_dt, NULL,
"TP-Discharge-Time");
dis_field_scts_aux(tvb, subtree, *offset_p);
*offset_p += 7;
}
static void
dis_field_st(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb,
offset, 1, ett_st, NULL, "TP-Status");
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_definition, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_st_error, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_st_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_field_fcs(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint8 oct _U_)
{
proto_tree_add_item(tree, hf_gsm_sms_tp_fail_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_iei_csm8(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields)
{
guint8 oct;
EXACT_DATA_CHECK(length, 3);
oct = tvb_get_guint8(tvb, offset);
p_udh_fields->sm_id = oct;
proto_tree_add_uint (tree, hf_gsm_sms_ud_multiple_messages_msg_id,
tvb, offset, 1, oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
p_udh_fields->frags = oct;
proto_tree_add_uint (tree, hf_gsm_sms_ud_multiple_messages_msg_parts,
tvb, offset, 1, oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
p_udh_fields->frag = oct;
proto_tree_add_uint (tree,
hf_gsm_sms_ud_multiple_messages_msg_part,
tvb, offset, 1, oct);
}
static void
dis_iei_apa_8bit(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields)
{
EXACT_DATA_CHECK(length, 2);
p_udh_fields->port_dst = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gsm_sms_destination_port8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
p_udh_fields->port_src = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gsm_sms_originator_port8, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_iei_apa_16bit(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields)
{
EXACT_DATA_CHECK(length, 4);
p_udh_fields->port_dst = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_gsm_sms_destination_port16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
p_udh_fields->port_src = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_gsm_sms_originator_port16, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dis_iei_scp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
static const int * status_flags[] = {
&hf_gsm_sms_status_report_short_msg,
&hf_gsm_sms_status_report_permanent_error,
&hf_gsm_sms_status_report_temp_error_no_attempt,
&hf_gsm_sms_status_report_temp_error_transfer,
&hf_gsm_sms_status_report_active,
&hf_gsm_sms_status_report_original_udh,
NULL
};
EXACT_DATA_CHECK(length, 1);
proto_tree_add_bitmask(tree, tvb, offset, hf_gsm_sms_status_report, ett_st, status_flags, ENC_NA);
}
static void
dis_iei_udh_si(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
EXACT_DATA_CHECK(length, 1);
proto_tree_add_item(tree, hf_gsm_sms_udh_created, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_iei_csm16(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields)
{
guint8 oct;
guint16 oct_ref;
EXACT_DATA_CHECK(length, 4);
oct_ref = tvb_get_ntohs(tvb, offset);
p_udh_fields->sm_id = oct_ref;
proto_tree_add_uint (tree,
hf_gsm_sms_ud_multiple_messages_msg_id,
tvb, offset, 2, oct_ref);
offset+=2;
oct = tvb_get_guint8(tvb, offset);
p_udh_fields->frags = oct;
proto_tree_add_uint (tree,
hf_gsm_sms_ud_multiple_messages_msg_parts,
tvb , offset , 1, oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
p_udh_fields->frag = oct;
proto_tree_add_uint (tree,
hf_gsm_sms_ud_multiple_messages_msg_part,
tvb, offset, 1, oct);
}
static void
dis_iei_tf(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
proto_tree* subtree_colour;
static const int * format_flags[] = {
&hf_gsm_sms_formatting_mode_alignment,
&hf_gsm_sms_formatting_mode_font_size,
&hf_gsm_sms_formatting_mode_style_bold,
&hf_gsm_sms_formatting_mode_style_italic,
&hf_gsm_sms_formatting_mode_style_underlined,
&hf_gsm_sms_formatting_mode_style_strikethrough,
NULL
};
SHORT_DATA_CHECK(length, 3);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_tf_start_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_tf_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_gsm_sms_formatting_mode, ett_udh_tfm, format_flags, ENC_NA);
offset++;
if (length > 3)
{
subtree_colour = proto_tree_add_subtree(tree, tvb, offset, 1, ett_udh_tfc, NULL, "Text Colour");
proto_tree_add_item(subtree_colour, hf_gsm_sms_dis_iei_tf_foreground_colour, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree_colour, hf_gsm_sms_dis_iei_tf_background_colour, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
dis_iei_ps(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
EXACT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_ps_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_ps_sound_number, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_iei_uds(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_uds_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_uds_user_defined_sound, tvb, offset, length - 1, ENC_NA);
}
static void
dis_iei_pa(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
EXACT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_pa_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_pa_animation_number, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dis_iei_la(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_la_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_la_large_animation, tvb, offset, length - 1, ENC_NA);
}
static void
dis_iei_sa(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_sa_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_sa_small_animation, tvb, offset, length - 1, ENC_NA);
}
static void
dis_iei_lp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_lp_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_lp_large_picture, tvb, offset, length - 1, ENC_NA);
}
static void
dis_iei_sp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 2);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_sp_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_sp_small_picture, tvb, offset, length - 1, ENC_NA);
}
static void
dis_iei_vp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
SHORT_DATA_CHECK(length, 4);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_vp_position, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_vp_horizontal_dimension, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_vp_vertical_dimension, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_vp_variable_picture, tvb, offset, length - 3, ENC_NA);
}
static void
dis_iei_upi(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields _U_)
{
EXACT_DATA_CHECK(length, 1);
proto_tree_add_item(tree, hf_gsm_sms_dis_iei_upi_num_corresponding_objects, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
static void
dis_field_ud_iei(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields)
{
void (*iei_fcn)(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 offset, guint8 length, gsm_sms_udh_fields_t *p_udh_fields);
guint8 oct;
proto_tree *subtree;
guint8 iei_len;
while (length >= 2)
{
iei_fcn = NULL;
oct = tvb_get_guint8(tvb, offset);
switch (oct)
{
case 0x00:
iei_fcn = dis_iei_csm8;
break;
case 0x04:
iei_fcn = dis_iei_apa_8bit;
break;
case 0x05:
iei_fcn = dis_iei_apa_16bit;
break;
case 0x06:
iei_fcn = dis_iei_scp;
break;
case 0x07:
iei_fcn = dis_iei_udh_si;
break;
case 0x08:
iei_fcn = dis_iei_csm16;
break;
case 0x0A:
iei_fcn = dis_iei_tf;
break;
case 0x0B:
iei_fcn = dis_iei_ps;
break;
case 0x0C:
iei_fcn = dis_iei_uds;
break;
case 0x0D:
iei_fcn = dis_iei_pa;
break;
case 0x0E:
iei_fcn = dis_iei_la;
break;
case 0x0F:
iei_fcn = dis_iei_sa;
break;
case 0x10:
iei_fcn = dis_iei_lp;
break;
case 0x11:
iei_fcn = dis_iei_sp;
break;
case 0x12:
iei_fcn = dis_iei_vp;
break;
case 0x13:
iei_fcn = dis_iei_upi;
break;
}
iei_len = tvb_get_guint8(tvb, offset + 1);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, iei_len + 2,
ett_udh_ieis[oct], NULL, "IE: %s",
rval_to_str_const(oct, gsm_sms_tp_ud_ie_id_rvals, "Reserved"));
proto_tree_add_item(subtree, hf_gsm_sms_ie_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_gsm_sms_dis_field_ud_iei_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (iei_len > 0)
{
if (iei_fcn == NULL)
{
proto_tree_add_item(subtree, hf_gsm_sms_ie_data, tvb, offset, iei_len, ENC_NA);
}
else
{
iei_fcn(tvb, pinfo, subtree, offset, iei_len, p_udh_fields);
}
}
length -= 2 + iei_len;
offset += iei_len;
}
}
void
dis_field_udh(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint32 *offset, guint32 *length,
guint8 *udl, enum character_set cset, guint8 *fill_bits, gsm_sms_udh_fields_t *p_udh_fields)
{
guint8 oct;
proto_tree *udh_subtree;
static const gint* fill_bits_mask_gsm[7] = { &hf_gsm_sms_dis_field_udh_gsm_mask00, &hf_gsm_sms_dis_field_udh_gsm_mask01, &hf_gsm_sms_dis_field_udh_gsm_mask03,
&hf_gsm_sms_dis_field_udh_gsm_mask07, &hf_gsm_sms_dis_field_udh_gsm_mask0f, &hf_gsm_sms_dis_field_udh_gsm_mask1f,
&hf_gsm_sms_dis_field_udh_gsm_mask3f };
static const gint* fill_bits_mask_ascii[7] = {&hf_gsm_sms_dis_field_udh_ascii_mask00, &hf_gsm_sms_dis_field_udh_ascii_mask80, &hf_gsm_sms_dis_field_udh_ascii_maskc0,
&hf_gsm_sms_dis_field_udh_ascii_maske0, &hf_gsm_sms_dis_field_udh_ascii_maskf0, &hf_gsm_sms_dis_field_udh_ascii_maskf8,
&hf_gsm_sms_dis_field_udh_ascii_maskfc };
oct = tvb_get_guint8(tvb, *offset);
udh_subtree =
proto_tree_add_subtree(tree, tvb,
*offset, oct + 1,
ett_udh, NULL, "User-Data Header");
proto_tree_add_item(udh_subtree, hf_gsm_sms_dis_field_udh_user_data_header_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
(*offset)++;
(*length)--;
dis_field_ud_iei(tvb, pinfo, udh_subtree, *offset, oct, p_udh_fields);
*offset += oct;
*length -= oct;
if (cset != OTHER)
{
*fill_bits = 6 - ((oct * 8) % 7);
*udl -= (((oct + 1)*8) + *fill_bits) / 7;
if (*fill_bits)
{
if (cset == GSM_7BITS)
{
proto_tree_add_item(udh_subtree, *fill_bits_mask_gsm[*fill_bits], tvb, *offset, 1, ENC_NA);
}
else
{
proto_tree_add_item(udh_subtree, *fill_bits_mask_ascii[*fill_bits], tvb, *offset, 1, ENC_NA);
}
}
}
else
{
*udl -= oct + 1;
}
}
static void
dis_field_ud(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset,
guint32 length, gboolean udhi, guint8 udl, gboolean seven_bit,
gboolean eight_bit, gboolean ucs2, gboolean compressed, gsm_sms_data_t *data)
{
proto_tree *subtree;
tvbuff_t *sm_tvb = NULL;
fragment_head *fd_sm = NULL;
guint8 fill_bits;
guint32 total_sms_len, len_sms, length_ucs2, i;
gchar *utf8_text = NULL;
gchar save_byte = 0, save_byte2 = 0;
gboolean reassembled = FALSE;
guint32 reassembled_in = 0;
gboolean is_fragmented = FALSE;
gboolean save_fragmented = FALSE, try_gsm_sms_ud_reassemble = FALSE;
guint32 num_labels;
sm_fragment_params *p_frag_params;
gsm_sms_udh_fields_t udh_fields;
memset(&udh_fields, 0, sizeof(udh_fields));
fill_bits = 0;
subtree =
proto_tree_add_subtree(tree, tvb,
offset, length,
ett_ud, NULL, "TP-User-Data");
if (udhi)
{
enum character_set cset;
if (data && data->stk_packing_required)
{
cset = OTHER;
}
else
{
cset = (seven_bit && !compressed) ? GSM_7BITS : OTHER;
}
dis_field_udh(tvb, pinfo, subtree, &offset, &length, &udl, cset, &fill_bits, &udh_fields);
}
if (udh_fields.frags > 1)
is_fragmented = TRUE;
if ( is_fragmented && reassemble_sms)
{
try_gsm_sms_ud_reassemble = TRUE;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
fd_sm = fragment_add_seq_check (&g_sm_reassembly_table, tvb, offset,
pinfo,
udh_fields.sm_id,
NULL,
udh_fields.frag-1,
length,
(udh_fields.frag != udh_fields.frags));
if (fd_sm)
{
reassembled = TRUE;
reassembled_in = fd_sm->reassembled_in;
}
sm_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled Short Message", fd_sm, &sm_frag_items,
NULL, tree);
if(reassembled && pinfo->fd->num == reassembled_in)
{
col_append_str (pinfo->cinfo, COL_INFO,
" (Short Message Reassembled)");
}
else
{
col_append_fstr (pinfo->cinfo, COL_INFO,
" (Short Message fragment %u of %u)", udh_fields.frag, udh_fields.frags);
}
p_frag_params = wmem_new0(wmem_file_scope(), sm_fragment_params);
p_frag_params->udl = udl;
p_frag_params->fill_bits = fill_bits;
p_frag_params->length = length;
g_hash_table_insert(g_sm_fragment_params_table,
GUINT_TO_POINTER((guint)((udh_fields.sm_id<<16)|(udh_fields.frag-1))),
p_frag_params);
}
if (! sm_tvb)
sm_tvb = tvb_new_subset_remaining (tvb, offset);
if (compressed)
{
proto_tree_add_item(subtree, hf_gsm_sms_compressed_data, tvb, offset, length, ENC_NA);
}
else
{
if (data && data->stk_packing_required)
{
if(!(reassembled && pinfo->fd->num == reassembled_in))
{
proto_tree_add_item(subtree, hf_gsm_sms_text, tvb, offset, length, ENC_ASCII|ENC_NA);
}
else
{
total_sms_len = 0;
for(i = 0 ; i < udh_fields.frags; i++)
{
p_frag_params = (sm_fragment_params*)g_hash_table_lookup(g_sm_fragment_params_table,
GUINT_TO_POINTER((guint)((udh_fields.sm_id<<16)|i)));
if (p_frag_params) {
proto_tree_add_item(subtree, hf_gsm_sms_text, sm_tvb, total_sms_len,
p_frag_params->length, ENC_ASCII|ENC_NA);
total_sms_len += p_frag_params->length;
}
}
}
}
else if (seven_bit)
{
if(!(reassembled && pinfo->fd->num == reassembled_in))
{
proto_tree_add_ts_23_038_7bits_item(subtree, hf_gsm_sms_text, tvb, (offset<<3)+fill_bits,
(udl > SMS_MAX_MESSAGE_SIZE ? SMS_MAX_MESSAGE_SIZE : udl));
}
else
{
total_sms_len = 0;
for(i = 0 ; i < udh_fields.frags; i++)
{
p_frag_params = (sm_fragment_params*)g_hash_table_lookup(g_sm_fragment_params_table,
GUINT_TO_POINTER((guint)((udh_fields.sm_id<<16)|i)));
if (p_frag_params) {
proto_tree_add_ts_23_038_7bits_item(subtree, hf_gsm_sms_text, sm_tvb,
(total_sms_len<<3)+p_frag_params->fill_bits,
(p_frag_params->udl > SMS_MAX_MESSAGE_SIZE ? SMS_MAX_MESSAGE_SIZE : p_frag_params->udl));
total_sms_len += p_frag_params->length;
}
}
}
}
else if (eight_bit)
{
if (!is_fragmented || (reassembled && pinfo->fd->num == reassembled_in)) {
if (! dissector_try_uint(gsm_sms_dissector_tbl, udh_fields.port_src, sm_tvb, pinfo, subtree))
{
if (! dissector_try_uint(gsm_sms_dissector_tbl, udh_fields.port_dst,sm_tvb, pinfo, subtree))
{
proto_tree_add_item(subtree, hf_gsm_sms_body, tvb, offset, length, ENC_NA);
}
}
} else {
proto_tree_add_item(subtree, hf_gsm_sms_body, tvb, offset, length, ENC_NA);
}
}
else if (ucs2)
{
{
guint rep_len = tvb_reported_length(sm_tvb);
if (!(reassembled && pinfo->fd->num == reassembled_in))
{
proto_tree_add_item(subtree, hf_gsm_sms_text, sm_tvb,
0, rep_len, ENC_UCS_2|ENC_BIG_ENDIAN);
} else {
utf8_text = tvb_get_string_enc(wmem_packet_scope(), sm_tvb, 0, rep_len, ENC_UCS_2|ENC_BIG_ENDIAN);
len_sms = (int)strlen(utf8_text);
num_labels = len_sms / MAX_SMS_FRAG_LEN;
num_labels += (len_sms % MAX_SMS_FRAG_LEN) ? 1 : 0;
for(i = 0; i < num_labels;i++) {
if(i * MAX_SMS_FRAG_LEN < len_sms) {
save_byte = utf8_text[i * MAX_SMS_FRAG_LEN];
save_byte2 = utf8_text[i * MAX_SMS_FRAG_LEN + 1];
if(i > 0)
{
utf8_text[i * MAX_SMS_FRAG_LEN] = '\0';
utf8_text[i * MAX_SMS_FRAG_LEN + 1] = '\0';
}
length_ucs2 = MAX_SMS_FRAG_LEN;
} else
length_ucs2 = len_sms % MAX_SMS_FRAG_LEN;
proto_tree_add_string(subtree, hf_gsm_sms_text, sm_tvb,
i * MAX_SMS_FRAG_LEN, length_ucs2,
&utf8_text[i * MAX_SMS_FRAG_LEN]);
if(i * MAX_SMS_FRAG_LEN < len_sms) {
utf8_text[i * MAX_SMS_FRAG_LEN] = save_byte;
utf8_text[i * MAX_SMS_FRAG_LEN + 1] = save_byte2;
}
}
}
}
}
}
if (try_gsm_sms_ud_reassemble)
pinfo->fragmented = save_fragmented;
}
static void
dis_field_pi(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
static const int * pi_flags[] = {
&hf_gsm_sms_tp_extension,
&hf_gsm_sms_tp_reserved,
&hf_gsm_sms_tp_udl_present,
&hf_gsm_sms_tp_dcs_present,
&hf_gsm_sms_tp_pid_present,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_gsm_sms_tp_parameter_indicator, ett_pi, pi_flags, ENC_NA);
}
static void
dis_msg_deliver(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, gsm_sms_data_t *data)
{
guint32 saved_offset;
guint32 length;
guint8 oct;
guint8 udl;
gboolean seven_bit;
gboolean eight_bit;
gboolean ucs2;
gboolean compressed;
gboolean udhi;
saved_offset = offset;
length = tvb_reported_length_remaining(tvb, offset);
oct = tvb_get_guint8(tvb, offset);
udhi = oct & 0x40;
proto_tree_add_item(tree, hf_gsm_sms_tp_rp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_sri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_lp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mms, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_down, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dis_field_addr(tvb, pinfo, tree, &offset, "TP-Originating-Address");
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_dcs(tvb, tree, offset, oct, &seven_bit, &eight_bit, &ucs2, &compressed);
offset++;
dis_field_scts(tvb, pinfo, tree, &offset);
oct = tvb_get_guint8(tvb, offset);
udl = oct;
DIS_FIELD_UDL(tree, offset);
if (udl > 0)
{
offset++;
dis_field_ud(tvb, pinfo, tree, offset, length - (offset - saved_offset), udhi, udl,
seven_bit, eight_bit, ucs2, compressed, data);
}
}
static void
dis_msg_deliver_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, gsm_sms_data_t *data)
{
guint32 saved_offset;
guint32 length;
guint8 oct;
guint8 pi;
guint8 udl;
gboolean seven_bit = FALSE;
gboolean eight_bit = FALSE;
gboolean ucs2 = FALSE;
gboolean compressed = FALSE;
gboolean udhi;
udl = 0;
saved_offset = offset;
length = tvb_reported_length_remaining(tvb, offset);
oct = tvb_get_guint8(tvb, offset);
udhi = oct & 0x40;
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_up, tvb, offset, 1, ENC_BIG_ENDIAN);
if (length < 2)
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, length);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
if (oct & 0x80)
{
dis_field_fcs(tvb, tree, offset, oct);
offset++;
}
pi = tvb_get_guint8(tvb, offset);
dis_field_pi(tvb, tree, offset);
if (pi & 0x01)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
}
if (pi & 0x02)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_dcs(tvb, tree, offset, oct, &seven_bit, &eight_bit, &ucs2, &compressed);
}
if (pi & 0x04)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
udl = oct;
DIS_FIELD_UDL(tree, offset);
}
if (udl > 0)
{
offset++;
dis_field_ud(tvb, pinfo, tree, offset, length - (offset - saved_offset), udhi, udl,
seven_bit, eight_bit, ucs2, compressed, data);
}
}
static void
dis_msg_submit(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, gsm_sms_data_t *data)
{
guint32 saved_offset;
guint32 length;
guint8 oct;
guint8 vp_form;
guint8 udl;
gboolean seven_bit;
gboolean eight_bit;
gboolean ucs2;
gboolean compressed;
gboolean udhi;
saved_offset = offset;
length = tvb_reported_length_remaining(tvb, offset);
oct = tvb_get_guint8(tvb, offset);
udhi = oct & 0x40;
vp_form = ((oct & 0x18) >> 3);
proto_tree_add_item(tree, hf_gsm_sms_tp_rp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_srr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_vpf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_rd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_tp_mr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dis_field_addr(tvb, pinfo, tree, &offset, "TP-Destination-Address");
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_dcs(tvb, tree, offset, oct, &seven_bit, &eight_bit, &ucs2, &compressed);
offset++;
dis_field_vp(tvb, pinfo, tree, &offset, vp_form);
oct = tvb_get_guint8(tvb, offset);
udl = oct;
DIS_FIELD_UDL(tree, offset);
if (udl > 0)
{
offset++;
dis_field_ud(tvb, pinfo, tree, offset, length - (offset - saved_offset), udhi, udl,
seven_bit, eight_bit, ucs2, compressed, data);
}
}
static void
dis_msg_submit_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, gsm_sms_data_t *data)
{
guint32 saved_offset;
guint32 length;
guint8 oct;
guint8 pi;
guint8 udl;
gboolean seven_bit = FALSE;
gboolean eight_bit = FALSE;
gboolean ucs2 = FALSE;
gboolean compressed = FALSE;
gboolean udhi;
udl = 0;
saved_offset = offset;
length = tvb_reported_length_remaining(tvb, offset);
oct = tvb_get_guint8(tvb, offset);
udhi = oct & 0x40;
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_down, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oct = tvb_get_guint8(tvb, offset);
if (oct & 0x80)
{
dis_field_fcs(tvb, tree, offset, oct);
offset++;
}
pi = tvb_get_guint8(tvb, offset);
dis_field_pi(tvb, tree, offset);
offset++;
dis_field_scts(tvb, pinfo, tree, &offset);
if (pi & 0x01) {
if (length <= (offset - saved_offset)) {
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
offset++;
}
if (pi & 0x02)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
oct = tvb_get_guint8(tvb, offset);
dis_field_dcs(tvb, tree, offset, oct, &seven_bit, &eight_bit, &ucs2, &compressed);
offset++;
}
if (pi & 0x04)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
oct = tvb_get_guint8(tvb, offset);
udl = oct;
DIS_FIELD_UDL(tree, offset);
offset++;
}
if (udl > 0)
{
dis_field_ud(tvb, pinfo, tree, offset, length - (offset - saved_offset), udhi, udl,
seven_bit, eight_bit, ucs2, compressed, data);
}
}
static void
dis_msg_status_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, gsm_sms_data_t *data)
{
guint32 saved_offset;
guint32 length;
guint8 oct;
guint8 pi;
guint8 udl;
gboolean seven_bit = FALSE;
gboolean eight_bit = FALSE;
gboolean ucs2 = FALSE;
gboolean compressed = FALSE;
gboolean udhi;
udl = 0;
saved_offset = offset;
length = tvb_reported_length_remaining(tvb, offset);
oct = tvb_get_guint8(tvb, offset);
udhi = oct & 0x40;
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_srq, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_lp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mms, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_down, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_tp_mr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dis_field_addr(tvb, pinfo, tree, &offset, "TP-Recipient-Address");
dis_field_scts(tvb, pinfo, tree, &offset);
dis_field_dt(tvb, pinfo, tree, &offset);
dis_field_st(tvb, tree, offset);
offset++;
if (length <= (offset - saved_offset))
{
return;
}
pi = tvb_get_guint8(tvb, offset);
dis_field_pi(tvb, tree, offset);
if (pi & 0x01)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
}
if (pi & 0x02)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_dcs(tvb, tree, offset, oct, &seven_bit, &eight_bit, &ucs2, &compressed);
}
if (pi & 0x04)
{
if (length <= (offset - saved_offset))
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_sms_short_data,
tvb, offset, -1);
return;
}
offset++;
oct = tvb_get_guint8(tvb, offset);
udl = oct;
DIS_FIELD_UDL(tree, offset);
}
if (udl > 0)
{
offset++;
dis_field_ud(tvb, pinfo, tree, offset, length - (offset - saved_offset), udhi, udl,
seven_bit, eight_bit, ucs2, compressed, data);
}
}
static void
dis_msg_command(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, gsm_sms_data_t *data _U_)
{
guint8 oct;
guint8 cdl;
proto_tree_add_item(tree, hf_gsm_sms_tp_udhi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_srr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_sms_tp_mti_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_sms_tp_mr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oct = tvb_get_guint8(tvb, offset);
dis_field_pid(tvb, tree, offset, oct);
offset++;
DIS_FIELD_CT(tree, offset);
offset++;
DIS_FIELD_MN(tree, offset);
offset++;
dis_field_addr(tvb, pinfo, tree, &offset, "TP-Destination-Address");
oct = tvb_get_guint8(tvb, offset);
cdl = oct;
DIS_FIELD_CDL(tree, offset);
if (cdl > 0)
{
offset++;
proto_tree_add_item(tree, hf_gsm_sms_tp_command_data, tvb, offset, cdl, ENC_NA);
}
}
static int
dissect_gsm_sms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
void (*msg_fcn)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, gsm_sms_data_t *gsm_data) = NULL;
guint32 offset;
guint8 msg_type;
guint8 oct;
gint idx;
const gchar *str = NULL;
gsm_sms_data_t *gsm_data = (gsm_sms_data_t*) data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, gsm_sms_proto_name_short);
if (tree || reassemble_sms)
{
proto_item *gsm_sms_item;
proto_tree *gsm_sms_tree;
g_tree = tree;
offset = 0;
oct = tvb_get_guint8(tvb, offset);
oct &= 0x03;
msg_type = oct;
msg_type |= ((pinfo->p2p_dir == P2P_DIR_RECV) ? 0x04 : 0x00);
str = try_val_to_str_idx(msg_type, msg_type_strings, &idx);
gsm_sms_item =
proto_tree_add_protocol_format(tree, proto_gsm_sms, tvb, 0, -1,
"%s %s",
gsm_sms_proto_name,
(str == NULL) ? "Unknown message identifier" : str);
gsm_sms_tree =
proto_item_add_subtree(gsm_sms_item, ett_gsm_sms);
if ((str == NULL) ||
(msg_type == 0x03) ||
(msg_type == 0x07))
{
return tvb_captured_length(tvb);
}
else
{
msg_fcn = gsm_sms_msg_fcn[idx];
}
if (msg_fcn == NULL)
{
proto_tree_add_expert(gsm_sms_tree, pinfo, &ei_gsm_sms_message_dissector_not_implemented,
tvb, offset, -1);
}
else
{
(*msg_fcn)(tvb, pinfo, gsm_sms_tree, offset, gsm_data);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_gsm_sms(void)
{
guint i;
guint last_offset;
module_t *gsm_sms_module;
expert_module_t* expert_gsm_sms;
static hf_register_info hf[] =
{
{ &hf_gsm_sms_coding_group_bits2,
{ "Coding Group Bits", "gsm_sms.coding_group_bits2",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &gsm_sms_coding_group_bits_vals_ext, 0xc0,
NULL, HFILL }
},
{ &hf_gsm_sms_coding_group_bits4,
{ "Coding Group Bits", "gsm_sms.coding_group_bits4",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &gsm_sms_coding_group_bits_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_gsm_sms_ud_fragments,
{ "Short Message fragments", "gsm_sms.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
"GSM Short Message fragments", HFILL }
},
{ &hf_gsm_sms_ud_fragment,
{ "Short Message fragment", "gsm_sms.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message fragment", HFILL }
},
{ &hf_gsm_sms_ud_fragment_overlap,
{ "Short Message fragment overlap", "gsm_sms.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment overlaps with other fragment(s)", HFILL }
},
{ &hf_gsm_sms_ud_fragment_overlap_conflicts,
{ "Short Message fragment overlapping with conflicting data", "gsm_sms.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment overlaps with conflicting data", HFILL }
},
{ &hf_gsm_sms_ud_fragment_multiple_tails,
{ "Short Message has multiple tail fragments", "gsm_sms.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment has multiple tail fragments", HFILL }
},
{ &hf_gsm_sms_ud_fragment_too_long_fragment,
{ "Short Message fragment too long", "gsm_sms.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment data goes beyond the packet end", HFILL }
},
{ &hf_gsm_sms_ud_fragment_error,
{ "Short Message defragmentation error", "gsm_sms.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message defragmentation error due to illegal fragments", HFILL }
},
{ &hf_gsm_sms_ud_fragment_count,
{ "Short Message fragment count", "gsm_sms.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_sms_ud_reassembled_in,
{ "Reassembled in", "gsm_sms.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message has been reassembled in this packet.", HFILL }
},
{ &hf_gsm_sms_ud_reassembled_length,
{ "Reassembled Short Message length", "gsm_sms.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"The total length of the reassembled payload", HFILL }
},
{ &hf_gsm_sms_ud_multiple_messages_msg_id,
{ "Message identifier", "gsm_sms.udh.mm.msg_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Identification of the message", HFILL }
},
{ &hf_gsm_sms_ud_multiple_messages_msg_parts,
{ "Message parts", "gsm_sms.udh.mm.msg_parts",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Total number of message parts (fragments)", HFILL }
},
{ &hf_gsm_sms_ud_multiple_messages_msg_part,
{ "Message part number", "gsm_sms.udh.mm.msg_part",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Message part (fragment) sequence number", HFILL }
},
{ &hf_gsm_sms_tp_mti_up,
{ "TP-MTI", "gsm_sms.tp-mti",
FT_UINT8, BASE_DEC, VALS(msg_type_strings_ms_to_sc), 0x03,
"TP-Message-Type-Indicator (in the direction MS to SC)", HFILL }
},
{ &hf_gsm_sms_tp_mti_down,
{ "TP-MTI", "gsm_sms.tp-mti",
FT_UINT8, BASE_DEC, VALS(msg_type_strings_sc_to_ms), 0x03,
"TP-Message-Type-Indicator (in the direction SC to MS)", HFILL }
},
{ &hf_gsm_sms_tp_oa,
{ "TP-OA Digits", "gsm_sms.tp-oa",
FT_STRING, BASE_NONE, NULL, 0x00,
"TP-Originating-Address Digits", HFILL }
},
{ &hf_gsm_sms_tp_da,
{ "TP-DA Digits", "gsm_sms.tp-da",
FT_STRING, BASE_NONE, NULL, 0x00,
"TP-Destination-Address Digits", HFILL }
},
{ &hf_gsm_sms_tp_ra,
{ "TP-RA Digits", "gsm_sms.tp-ra",
FT_STRING, BASE_NONE, NULL, 0x00,
"TP-Recipient-Address Digits", HFILL }
},
{ &hf_gsm_sms_tp_digits,
{ "Digits", "gsm_sms.tp-digits",
FT_STRING, BASE_NONE, NULL, 0x00,
"TP (Unknown) Digits", HFILL }
},
{ &hf_gsm_sms_tp_pid,
{ "TP-PID", "gsm_sms.tp-pid",
FT_UINT8, BASE_DEC, NULL, 0x00,
"TP-Protocol-Identifier", HFILL }
},
{ &hf_gsm_sms_tp_dcs,
{ "TP-DCS", "gsm_sms.tp-dcs",
FT_UINT8, BASE_DEC, NULL, 0x00,
"TP-Data-Coding-Scheme", HFILL }
},
{ &hf_gsm_sms_tp_mr,
{ "TP-MR", "gsm_sms.tp-mr",
FT_UINT8, BASE_DEC, NULL, 0x00,
"TP-Message-Reference", HFILL }
},
{ &hf_gsm_sms_tp_mms,
{ "TP-MMS", "gsm_sms.tp-mms",
FT_BOOLEAN, 8, TFS(&mms_bool_strings), 0x04,
"TP-More-Messages-to-Send", HFILL }
},
{ &hf_gsm_sms_tp_lp,
{ "TP-LP", "gsm_sms.tp-lp",
FT_BOOLEAN, 8, TFS(&lp_bool_strings), 0x08,
"TP-Loop-Prevention", HFILL }
},
{ &hf_gsm_sms_tp_sri,
{ "TP-SRI", "gsm_sms.tp-sri",
FT_BOOLEAN, 8, TFS(&sri_bool_strings), 0x20,
"TP-Status-Report-Indication", HFILL }
},
{ &hf_gsm_sms_tp_srr,
{ "TP-SRR", "gsm_sms.tp-srr",
FT_BOOLEAN, 8, TFS(&srr_bool_strings), 0x20,
"TP-Status-Report-Request", HFILL }
},
{ &hf_gsm_sms_tp_udhi,
{ "TP-UDHI", "gsm_sms.tp-udhi",
FT_BOOLEAN, 8, TFS(&udhi_bool_strings), 0x40,
"TP-User-Data-Header-Indicator", HFILL }
},
{ &hf_gsm_sms_tp_rp,
{ "TP-RP", "gsm_sms.tp-rp",
FT_BOOLEAN, 8, TFS(&rp_bool_strings), 0x80,
"TP-Reply-Path", HFILL }
},
{ &hf_gsm_sms_tp_vpf,
{ "TP-VPF", "gsm_sms.tp-vpf",
FT_UINT8, BASE_DEC, VALS(vp_type_strings), 0x18,
"TP-Validity-Period-Format", HFILL }
},
{ &hf_gsm_sms_tp_rd,
{ "TP-RD", "gsm_sms.tp-rd",
FT_BOOLEAN, 8, TFS(&rd_bool_strings), 0x04,
"TP-Reject-Duplicates", HFILL }
},
{ &hf_gsm_sms_tp_srq,
{ "TP-SRQ", "gsm_sms.tp-srq",
FT_BOOLEAN, 8, TFS(&srq_bool_strings), 0x20,
"TP-Status-Report-Qualifier", HFILL }
},
{ &hf_gsm_sms_text,
{ "SMS text", "gsm_sms.sms_text",
FT_STRING, STR_UNICODE, NULL, 0x00,
"The text of the SMS", HFILL }
},
{ &hf_gsm_sms_body,
{ "SMS body", "gsm_sms.sms_body",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_fail_cause,
{ "TP-Failure-Cause (TP-FCS)", "gsm_sms.tp-fcs",
FT_UINT8, BASE_HEX_DEC|BASE_RANGE_STRING, RVALS(gsm_sms_tp_failure_cause_values), 0x0,
"TP-Validity-Period-Format", HFILL }
},
{ &hf_gsm_sms_dis_field_addr_extension,
{ "Extension", "gsm_sms.dis_field_addr.extension",
FT_BOOLEAN, 8, TFS(&tfs_no_extension_extended), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_addr_num_type,
{ "Type of number", "gsm_sms.dis_field_addr.num_type",
FT_UINT8, BASE_DEC, VALS(dis_field_addr_num_types_vals), 0x70,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_addr_num_plan,
{ "Numbering plan", "gsm_sms.dis_field_addr.num_plan",
FT_UINT8, BASE_DEC, VALS(dis_field_addr_numbering_plan_vals), 0x0F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_parameter_indicator,
{ "TP-Parameter-Indicator", "gsm_sms.tp.parameter_indicator",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_extension,
{ "Extension", "gsm_sms.tp.extension",
FT_BOOLEAN, 8, TFS(&tfs_extended_no_extension), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_reserved,
{ "Reserved", "gsm_sms.tp.reserved",
FT_UINT8, BASE_DEC, NULL, 0x78,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_udl_present,
{ "TP-UDL", "gsm_sms.tp.udl.present",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x04,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_dcs_present,
{ "TP-DCS", "gsm_sms.tp.dcs.present",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x02,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_present,
{ "TP-PID", "gsm_sms.tp.pid.present",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x01,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_format_subsequent_bits,
{ "Defines formatting for subsequent bits", "gsm_sms.tp.pid.format_subsequent_bits",
FT_UINT8, BASE_HEX, NULL, 0xC0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_telematic_interworking,
{ "Telematic interworking", "gsm_sms.tp.pid.telematic_interworking",
FT_BOOLEAN, 8, TFS(&tfs_telematic_interworking), 0x20,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_device_type,
{ "Device type", "gsm_sms.tp.pid.device_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(tp_pid_device_type_rvals), 0x1F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_sm_al_proto,
{ "The SM-AL protocol being used between the SME and the MS", "gsm_sms.tp.pid.sm_al_proto",
FT_UINT8, BASE_DEC, NULL, 0x1F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_message_type,
{ "Message type", "gsm_sms.tp.pid.message_type",
FT_UINT8, BASE_DEC, VALS(pid_message_type_vals), 0x3F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_reserved,
{ "Reserved", "gsm_sms.tp.pid.reserved",
FT_UINT8, BASE_HEX, NULL, 0xC0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_undefined,
{ "Undefined", "gsm_sms.tp.pid.undefined",
FT_UINT8, BASE_HEX, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_sc_specific_use,
{ "Bits 0-5 for SC specific use", "gsm_sms.tp.pid.sc_specific_use",
FT_UINT8, BASE_HEX, NULL, 0xC0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_pid_sc_specific,
{ "SC specific", "gsm_sms.tp.pid.sc_specific",
FT_UINT8, BASE_HEX, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_text_compressed,
{ "Text", "gsm_sms.dcs.text_compressed",
FT_BOOLEAN, 8, TFS(&tfs_compressed_not_compressed), 0x20,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_message_class_defined,
{ "Message Class", "gsm_sms.dcs.message_class_defined",
FT_BOOLEAN, 8, TFS(&tfs_message_class_defined), 0x10,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_character_set,
{ "Character Set", "gsm_sms.dcs.character_set",
FT_UINT8, BASE_HEX, VALS(dcs_character_set_vals), 0x0C,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_message_class,
{ "Message Class", "gsm_sms.dcs.message_class",
FT_UINT8, BASE_HEX, VALS(dcs_message_class_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_indication_sense,
{ "Indication Sense", "gsm_sms.dcs.indication_sense",
FT_BOOLEAN, 8, TFS(&tfs_indication_sense), 0x08,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_reserved04,
{ "Reserved", "gsm_sms.dcs.reserved",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_reserved08,
{ "Reserved", "gsm_sms.dcs.reserved",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_message_waiting,
{ "Message Waiting", "gsm_sms.dcs.message_waiting",
FT_UINT8, BASE_HEX, VALS(dcs_message_waiting_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_sms_dcs_message_coding,
{ "Message coding", "gsm_sms.dcs.message_coding",
FT_BOOLEAN, 8, TFS(&tfs_message_coding), 0x04,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_extension,
{ "Extension", "gsm_sms.vp.extension",
FT_BOOLEAN, 8, TFS(&tfs_extended_no_extension), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_extension_ignored,
{ "Extension not implemented, ignored", "gsm_sms.vp.extension_ignored",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_single_shot_sm,
{ "Single shot SM", "gsm_sms.vp.single_shot_sm",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_reserved,
{ "Reserved", "gsm_sms.vp.reserved",
FT_UINT8, BASE_HEX, NULL, 0x38,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_validity_period_format,
{ "Validity Period Format", "gsm_sms.vp.validity_period_format",
FT_UINT8, BASE_DEC, VALS(vp_validity_period_format_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_validity_period,
{ "TP-Validity-Period", "gsm_sms.vp.validity_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_definition,
{ "Definition of bits 0-6", "gsm_sms.dis_field.definition",
FT_BOOLEAN, 8, TFS(&tfs_dis_field_definition), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_st_error,
{ "Error", "gsm_sms.dis_field.st_error",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(dis_field_st_error_rvals), 0x7F,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_st_reason,
{ "Reason", "gsm_sms.dis.field_st_reason",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(dis_field_st_reason_rvals), 0x7F,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_user_data_length,
{ "TP-User-Data-Length", "gsm_sms.tp.user_data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_message_number,
{ "TP-Message-Number", "gsm_sms.tp.message_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_command_type,
{ "TP-Command-Type", "gsm_sms.tp.command_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(tp_command_type_rvals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_command_data,
{ "TP-Command-Data", "gsm_sms.tp.command_data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_tp_command_data_length,
{ "TP-Command-Data-Length", "gsm_sms.tp.command_data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_destination_port8,
{ "Destination port", "gsm_sms.destination_port",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_sms_8bit_port_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_originator_port8,
{ "Originator port", "gsm_sms.originator_port",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_sms_8bit_port_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_destination_port16,
{ "Destination port", "gsm_sms.destination_port",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_sms_16bit_port_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_originator_port16,
{ "Originator port", "gsm_sms.originator_port",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_sms_16bit_port_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report,
{ "Status Report", "gsm_sms.status_report",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_short_msg,
{ "Status Report for short message transaction completed", "gsm_sms.status_report.short_msg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_permanent_error,
{ "Status Report for permanent error when SC is not making any more transfer attempts", "gsm_sms.status_report.permanent_error",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_temp_error_no_attempt,
{ "Status Report for temporary error when SC is not making any more transfer attempts", "gsm_sms.status_report.temp_error_no_attempt",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_temp_error_transfer,
{ "Status Report for temporary error when SC is still trying to transfer SM", "gsm_sms.status_report.temp_error_transfer",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_active,
{ "Single shot SM", "gsm_sms.status_report.active",
FT_BOOLEAN, 8, TFS(&tfs_status_report_active), 0x40,
NULL, HFILL }
},
{ &hf_gsm_sms_status_report_original_udh,
{ "Include original UDH into the Status Report", "gsm_sms.status_report.original_udh",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_udh_created,
{ "The following part of the UDH is created by", "gsm_sms.udh_created",
FT_UINT8, BASE_DEC, VALS(udh_created_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode,
{ "Formatting mode", "gsm_sms.formatting_mode",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_alignment,
{ "Alignment", "gsm_sms.udh_created",
FT_UINT8, BASE_DEC, VALS(alignment_values), 0x03,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_font_size,
{ "Font Size", "gsm_sms.udh_created",
FT_UINT8, BASE_DEC, VALS(font_size_values), 0x0C,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_style_bold,
{ "Style bold", "gsm_sms.formatting_mode.style_bold",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x10,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_style_italic,
{ "Style Italic", "gsm_sms.formatting_mode.style_italic",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x20,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_style_underlined,
{ "Style Underlined", "gsm_sms.formatting_mode.style_underlined",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x40,
NULL, HFILL }
},
{ &hf_gsm_sms_formatting_mode_style_strikethrough,
{ "Style Strikethrough", "gsm_sms.formatting_mode.style_strikethrough",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80,
NULL, HFILL }
},
{ &hf_gsm_sms_ie_identifier,
{ "Information Element Identifier", "gsm_sms.ie_identifier",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_year,
{ "Year", "gsm_sms.scts.year",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_month,
{ "Month", "gsm_sms.scts.month",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_day,
{ "Day", "gsm_sms.scts.day",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_hour,
{ "Hour", "gsm_sms.scts.hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_minutes,
{ "Minutes", "gsm_sms.scts.minutes",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_seconds,
{ "Seconds", "gsm_sms.scts.seconds",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_scts_timezone,
{ "Timezone", "gsm_sms.scts.timezone",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_validity_period_hour,
{ "Hour", "gsm_sms.vp.validity_period.hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_validity_period_minutes,
{ "Minutes", "gsm_sms.vp.validity_period.minutes",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_vp_validity_period_seconds,
{ "Seconds", "gsm_sms.vp.validity_period.seconds",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_sms_dis_field_addr_length, { "Length", "gsm_sms.dis_field_addr.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_gsm_7_bit_default_alphabet, { "Special case, GSM 7 bit default alphabet", "gsm_sms.gsm_7_bit_default_alphabet", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_tf_start_position, { "Start position of the text formatting", "gsm_sms.dis_iei_tf.start_position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_tf_length, { "Text formatting length", "gsm_sms.dis_iei_tf.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_tf_foreground_colour, { "Foreground Colour", "gsm_sms.dis_iei_tf.foreground_colour", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &text_color_values_ext, 0x0F, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_tf_background_colour, { "Background Colour", "gsm_sms.dis_iei_tf.background_colour", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &text_color_values_ext, 0xF0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_ps_position, { "Position", "gsm_sms.dis_iei_ps.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_ps_sound_number, { "Sound number", "gsm_sms.dis_iei_ps.sound_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_uds_position, { "Position", "gsm_sms.dis_iei_uds.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_uds_user_defined_sound, { "User Defined Sound", "gsm_sms.dis_iei_uds.user_defined_sound", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_pa_position, { "Position", "gsm_sms.dis_iei_pa.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_pa_animation_number, { "Animation number", "gsm_sms.dis_iei_pa.animation_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_la_position, { "Position", "gsm_sms.dis_iei_la.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_la_large_animation, { "Large Animation", "gsm_sms.dis_iei_la.large_animation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_sa_position, { "Position", "gsm_sms.dis_iei_sa.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_sa_small_animation, { "Small Animation", "gsm_sms.dis_iei_sa.small_animation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_lp_position, { "Position", "gsm_sms.dis_iei_lp.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_lp_large_picture, { "Large Picture", "gsm_sms.dis_iei_lp.large_picture", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_sp_position, { "Position", "gsm_sms.dis_iei_sp.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_sp_small_picture, { "Small Picture", "gsm_sms.dis_iei_sp.small_picture", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_vp_position, { "position", "gsm_sms.dis_iei_vp.position", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_vp_horizontal_dimension, { "Horizontal dimension", "gsm_sms.dis_iei_vp.horizontal_dimension", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_vp_vertical_dimension, { "Vertical dimension", "gsm_sms.dis_iei_vp.vertical_dimension", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_vp_variable_picture, { "Variable Picture", "gsm_sms.dis_iei_vp.variable_picture", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_iei_upi_num_corresponding_objects, { "Number of corresponding objects", "gsm_sms.dis_iei_upi.num_corresponding_objects", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_ud_iei_length, { "Length", "gsm_sms.dis_field_ud_iei.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_ie_data, { "IE Data", "gsm_sms.ie_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_user_data_header_length, { "User Data Header Length", "gsm_sms.dis_field_udh.user_data_header_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_compressed_data, { "Compressed data", "gsm_sms.compressed_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask00, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask01, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask03, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask07, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x07, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask0f, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask1f, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_gsm_mask3f, { "Fill bits", "gsm_sms.dis_field_udh.gsm.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_mask00, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_mask80, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_maskc0, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_maske0, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_maskf0, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_maskf8, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL }},
{ &hf_gsm_sms_dis_field_udh_ascii_maskfc, { "Fill bits", "gsm_sms.dis_field_udh.ascii.fill_bits", FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_gsm_sms_short_data, { "gsm_sms.short_data", PI_MALFORMED, PI_ERROR, "Short Data (?)", EXPFILL }},
{ &ei_gsm_sms_unexpected_data_length, { "gsm_sms.unexpected_data_length", PI_MALFORMED, PI_ERROR, "Unexpected Data Length", EXPFILL }},
{ &ei_gsm_sms_message_dissector_not_implemented, { "gsm_sms.message_dissector_not_implemented", PI_UNDECODED, PI_WARN, "Message dissector not implemented", EXPFILL }},
};
#define NUM_INDIVIDUAL_PARMS 14
gint *ett[NUM_INDIVIDUAL_PARMS+NUM_UDH_IEIS+2];
ett[0] = &ett_gsm_sms;
ett[1] = &ett_pid;
ett[2] = &ett_pi;
ett[3] = &ett_fcs;
ett[4] = &ett_vp;
ett[5] = &ett_scts;
ett[6] = &ett_dt;
ett[7] = &ett_st;
ett[8] = &ett_addr;
ett[9] = &ett_dcs;
ett[10] = &ett_ud;
ett[11] = &ett_udh;
ett[12] = &ett_udh_tfm;
ett[13] = &ett_udh_tfc;
last_offset = NUM_INDIVIDUAL_PARMS;
#if 0
for (i=0; i < NUM_MSGS; i++, last_offset++)
{
ett_msgs[i] = -1;
ett[last_offset] = &ett_msgs[i];
}
#endif
for (i=0; i < NUM_UDH_IEIS; i++, last_offset++)
{
ett_udh_ieis[i] = -1;
ett[last_offset] = &ett_udh_ieis[i];
}
ett[last_offset++] = &ett_gsm_sms_ud_fragment;
ett[last_offset] = &ett_gsm_sms_ud_fragments;
proto_gsm_sms = proto_register_protocol(gsm_sms_proto_name, gsm_sms_proto_name_short, "gsm_sms");
proto_register_field_array(proto_gsm_sms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_sms = expert_register_protocol(proto_gsm_sms);
expert_register_field_array(expert_gsm_sms, ei, array_length(ei));
gsm_sms_dissector_tbl = register_dissector_table("gsm_sms.udh.port",
"GSM SMS port IE in UDH", FT_UINT16, BASE_DEC);
gsm_sms_module = prefs_register_protocol (proto_gsm_sms, NULL);
prefs_register_obsolete_preference(gsm_sms_module,
"try_dissect_message_fragment");
prefs_register_bool_preference (gsm_sms_module, "reassemble",
"Reassemble fragmented SMS",
"Whether the dissector should reassemble SMS spanning multiple packets",
&reassemble_sms);
new_register_dissector("gsm_sms", dissect_gsm_sms, proto_gsm_sms);
register_init_routine (gsm_sms_defragment_init);
register_cleanup_routine (gsm_sms_defragment_cleanup);
}
