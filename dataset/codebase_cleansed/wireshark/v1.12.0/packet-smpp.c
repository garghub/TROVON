static void
smpp_stats_tree_init(stats_tree* st)
{
st_smpp_ops = stats_tree_create_node(st, "SMPP Operations", 0, TRUE);
st_smpp_req = stats_tree_create_node(st, "SMPP Requests", st_smpp_ops, TRUE);
st_smpp_res = stats_tree_create_node(st, "SMPP Responses", st_smpp_ops, TRUE);
st_smpp_res_status = stats_tree_create_node(st, "SMPP Response Status", 0, TRUE);
}
static int
smpp_stats_tree_per_packet(stats_tree *st,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *p)
{
const smpp_tap_rec_t* tap_rec = (const smpp_tap_rec_t*)p;
tick_stat_node(st, "SMPP Operations", 0, TRUE);
if ((tap_rec->command_id & 0x80000000) == 0x80000000)
{
tick_stat_node(st, "SMPP Responses", st_smpp_ops, TRUE);
tick_stat_node(st, val_to_str(tap_rec->command_id, vals_command_id, "Unknown 0x%08x"), st_smpp_res, FALSE);
tick_stat_node(st, "SMPP Response Status", 0, TRUE);
tick_stat_node(st, val_to_str(tap_rec->command_status, vals_command_status, "Unknown 0x%08x"), st_smpp_res_status, FALSE);
}
else
{
tick_stat_node(st, "SMPP Requests", st_smpp_ops, TRUE);
tick_stat_node(st, val_to_str(tap_rec->command_id, vals_command_id, "Unknown 0x%08x"), st_smpp_req, FALSE);
}
return 1;
}
static gboolean
smpp_mktime(const char *datestr, time_t *secs, int *nsecs)
{
struct tm r_time;
time_t t_diff;
gboolean relative = (datestr[15] == 'R') ? TRUE : FALSE;
r_time.tm_year = 10 * (datestr[0] - '0') + (datestr[1] - '0');
if (r_time.tm_year < 38)
r_time.tm_year += 100;
r_time.tm_mon = 10 * (datestr[2] - '0') + (datestr[3] - '0');
r_time.tm_mon--;
r_time.tm_mday = 10 * (datestr[4] - '0') + (datestr[5] - '0');
r_time.tm_hour = 10 * (datestr[6] - '0') + (datestr[7] - '0');
r_time.tm_min = 10 * (datestr[8] - '0') + (datestr[9] - '0');
r_time.tm_sec = 10 * (datestr[10] - '0') + (datestr[11] - '0');
r_time.tm_isdst = -1;
if (relative == FALSE) {
struct tm *gm, *local_time;
int gm_hour, gm_min;
time_t current_time;
*secs = mktime(&r_time);
current_time = time(NULL);
gm = gmtime(&current_time);
gm_hour = gm->tm_hour;
gm_min = gm->tm_min;
local_time = localtime(&current_time);
*secs -= 3600*(gm_hour - local_time->tm_hour);
*secs -= 60*(gm_min - local_time->tm_min);
*nsecs = (datestr[12] - '0') * 100000000;
t_diff = (10 * (datestr[13] - '0') + (datestr[14] - '0')) * 900;
if (datestr[15] == '-')
*secs += t_diff;
else if (datestr[15] == '+')
*secs -= t_diff;
} else {
*secs = r_time.tm_sec + 60 *
(r_time.tm_min + 60 *
(r_time.tm_hour + 24 *
r_time.tm_mday));
*nsecs = 0;
}
return relative;
}
static void
smpp_handle_string(proto_tree *tree, tvbuff_t *tvb, int field, int *offset)
{
guint len;
len = tvb_strsize(tvb, *offset);
if (len > 1) {
proto_tree_add_item(tree, field, tvb, *offset, len, ENC_NA);
}
(*offset) += len;
}
static const char *
smpp_handle_string_return(proto_tree *tree, tvbuff_t *tvb, int field, int *offset)
{
gint len;
const char *str;
len = tvb_strsize(tvb, *offset);
if (len > 1) {
str = (char *)tvb_get_stringz(wmem_packet_scope(), tvb, *offset, &len);
proto_tree_add_string(tree, field, tvb, *offset, len, str);
} else {
str = "";
}
(*offset) += len;
return str;
}
static void
smpp_handle_string_z(proto_tree *tree, tvbuff_t *tvb, int field, int *offset,
const char *null_string)
{
gint len;
len = tvb_strsize(tvb, *offset);
if (len > 1) {
proto_tree_add_item(tree, field, tvb, *offset, len, ENC_NA);
} else {
proto_tree_add_string(tree, field, tvb, *offset, len, null_string);
}
(*offset) += len;
}
static void
smpp_handle_int1(proto_tree *tree, tvbuff_t *tvb, int field, int *offset)
{
guint8 val;
val = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, field, tvb, *offset, 1, val);
(*offset)++;
}
static void
smpp_handle_int2(proto_tree *tree, tvbuff_t *tvb, int field, int *offset)
{
guint val;
val = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, field, tvb, *offset, 2, val);
(*offset) += 2;
}
static void
smpp_handle_int4(proto_tree *tree, tvbuff_t *tvb, int field, int *offset)
{
guint val;
val = tvb_get_ntohl(tvb, *offset);
proto_tree_add_uint(tree, field, tvb, *offset, 4, val);
(*offset) += 4;
}
static void
smpp_handle_time(proto_tree *tree, tvbuff_t *tvb,
int field, int field_R, int *offset)
{
char *strval;
gint len;
nstime_t tmptime;
strval = (char *) tvb_get_stringz(wmem_packet_scope(), tvb, *offset, &len);
if (*strval)
{
if (len >= 16)
{
if (smpp_mktime(strval, &tmptime.secs, &tmptime.nsecs))
proto_tree_add_time(tree, field_R, tvb, *offset, len, &tmptime);
else
proto_tree_add_time(tree, field, tvb, *offset, len, &tmptime);
}
else
{
proto_tree_add_text(tree, tvb, *offset, len, "Invalid time: %s", strval);
}
}
*offset += len;
}
static void
smpp_handle_dlist(proto_tree *tree, tvbuff_t *tvb, int *offset)
{
guint8 entries;
int tmpoff = *offset;
proto_tree *sub_tree = NULL;
guint8 dest_flag;
if ((entries = tvb_get_guint8(tvb, tmpoff++))) {
proto_item *pi;
pi = proto_tree_add_item(tree, hf_smpp_dlist, tvb, *offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(pi, ett_dlist);
}
while (entries--)
{
dest_flag = tvb_get_guint8(tvb, tmpoff++);
if (dest_flag == 1)
{
smpp_handle_int1(sub_tree, tvb, hf_smpp_dest_addr_ton, &tmpoff);
smpp_handle_int1(sub_tree, tvb, hf_smpp_dest_addr_npi, &tmpoff);
smpp_handle_string(sub_tree,tvb,hf_smpp_destination_addr,&tmpoff);
}
else
{
smpp_handle_string(sub_tree, tvb, hf_smpp_dl_name, &tmpoff);
}
}
*offset = tmpoff;
}
static void
smpp_handle_dlist_resp(proto_tree *tree, tvbuff_t *tvb, int *offset)
{
guint8 entries;
int tmpoff = *offset;
proto_tree *sub_tree = NULL;
if ((entries = tvb_get_guint8(tvb, tmpoff++))) {
proto_item *pi;
pi = proto_tree_add_item(tree, hf_smpp_dlist_resp,
tvb, *offset, 1, ENC_NA);
sub_tree = proto_item_add_subtree(pi, ett_dlist_resp);
}
while (entries--)
{
smpp_handle_int1(sub_tree, tvb, hf_smpp_dest_addr_ton, &tmpoff);
smpp_handle_int1(sub_tree, tvb, hf_smpp_dest_addr_npi, &tmpoff);
smpp_handle_string(sub_tree,tvb,hf_smpp_destination_addr,&tmpoff);
smpp_handle_int4(sub_tree, tvb, hf_smpp_error_status_code, &tmpoff);
}
*offset = tmpoff;
}
static void
smpp_handle_tlv(proto_tree *tree, tvbuff_t *tvb, int *offset)
{
proto_tree *tlvs_tree = NULL;
proto_item *pi;
if (tvb_reported_length_remaining(tvb, *offset) >= 1) {
pi = proto_tree_add_item(tree, hf_smpp_opt_params,
tvb, *offset, -1, ENC_NA);
tlvs_tree = proto_item_add_subtree(pi, ett_opt_params);
}
while (tvb_reported_length_remaining(tvb, *offset) >= 1)
{
proto_item *sub_tree;
guint16 tag;
guint16 length;
guint8 field;
guint16 field16;
guint8 major, minor;
char *strval=NULL;
tag = tvb_get_ntohs(tvb, *offset);
length = tvb_get_ntohs(tvb, (*offset+2));
pi = proto_tree_add_none_format(tlvs_tree, hf_smpp_opt_param, tvb,
*offset, length+4,
"Optional parameter: %s (0x%04x)",
val_to_str(tag, vals_tlv_tags, "0x%04x"), tag);
sub_tree = proto_item_add_subtree(pi, ett_opt_param);
proto_tree_add_uint(sub_tree,hf_smpp_opt_param_tag,tvb,*offset,2,tag);
proto_tree_add_uint(sub_tree,hf_smpp_opt_param_len,tvb,*offset+2,2,length);
*offset += 4;
switch (tag) {
case 0x0005:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_dest_addr_subunit, offset);
break;
case 0x0006:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_dest_network_type, offset);
break;
case 0x0007:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_dest_bearer_type, offset);
break;
case 0x0008:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_dest_telematics_id, offset);
break;
case 0x000D:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_source_addr_subunit, offset);
break;
case 0x000E:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_source_network_type, offset);
break;
case 0x000F:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_source_bearer_type, offset);
break;
case 0x0010:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_source_telematics_id, offset);
break;
case 0x0017:
smpp_handle_int4(sub_tree, tvb,
hf_smpp_qos_time_to_live, offset);
break;
case 0x0019:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_payload_type, offset);
break;
case 0x001D:
smpp_handle_string(sub_tree, tvb,
hf_smpp_additional_status_info_text, offset);
break;
case 0x001E:
smpp_handle_string(sub_tree, tvb,
hf_smpp_receipted_message_id, offset);
break;
case 0x0030:
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_msg_wait_ind,
tvb, *offset, 1, field);
proto_tree_add_uint(sub_tree, hf_smpp_msg_wait_type,
tvb, *offset, 1, field);
(*offset)++;
break;
case 0x0201:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_privacy_indicator, offset);
break;
case 0x0202:
if (length) {
proto_tree_add_item(sub_tree, hf_smpp_source_subaddress,
tvb, *offset, length, ENC_NA);
(*offset) += length;
}
break;
case 0x0203:
if (length) {
proto_tree_add_item(sub_tree, hf_smpp_dest_subaddress,
tvb, *offset, length, ENC_NA);
(*offset) += length;
}
break;
case 0x0204:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_user_message_reference, offset);
break;
case 0x0205:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_user_response_code, offset);
break;
case 0x020A:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_source_port, offset);
break;
case 0x020B:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_destination_port, offset);
break;
case 0x020C:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_sar_msg_ref_num, offset);
break;
case 0x020D:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_language_indicator, offset);
break;
case 0x020E:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_sar_total_segments, offset);
break;
case 0x020F:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_sar_segment_seqnum, offset);
break;
case 0x0210:
field = tvb_get_guint8(tvb, *offset);
minor = field & 0x0F;
major = (field & 0xF0) >> 4;
strval=wmem_strdup_printf(wmem_packet_scope(), "%u.%u", major, minor);
proto_tree_add_string(sub_tree, hf_smpp_SC_interface_version,
tvb, *offset, 1, strval);
(*offset)++;
break;
case 0x0302:
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_callback_num_pres,
tvb, *offset, 1, field);
proto_tree_add_uint(sub_tree, hf_smpp_callback_num_scrn,
tvb, *offset, 1, field);
(*offset)++;
break;
case 0x0303:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_callback_num_atag,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0304:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_number_of_messages, offset);
break;
case 0x0381:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_callback_num,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0420:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_dpf_result, offset);
break;
case 0x0421:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_set_dpf, offset);
break;
case 0x0422:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_ms_availability_status, offset);
break;
case 0x0423:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_network_error_type, offset);
smpp_handle_int2(sub_tree, tvb,
hf_smpp_network_error_code, offset);
break;
case 0x0424:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_message_payload,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0425:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_delivery_failure_reason, offset);
break;
case 0x0426:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_more_messages_to_send, offset);
break;
case 0x0427:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_message_state, offset);
break;
case 0x0428:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_congestion_state, offset);
break;
case 0x0501:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_ussd_service_op, offset);
break;
case 0x0600:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_broadcast_channel_indicator, offset);
break;
case 0x0601:
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_broadcast_content_type_nw, tvb, *offset, 1, field);
(*offset)++;
field16 = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_broadcast_content_type_type, tvb, *offset, 2, field16);
(*offset) += 2;
break;
case 0x0602:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_broadcast_content_type_info,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0603:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_broadcast_message_class, offset);
break;
case 0x0604:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_broadcast_rep_num, offset);
break;
case 0x0605:
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_broadcast_frequency_interval_unit, tvb, *offset, 1, field);
(*offset)++;
field16 = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_broadcast_frequency_interval_value, tvb, *offset, 2, field16);
(*offset) += 2;
break;
case 0x0606:
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_broadcast_area_identifier_format, tvb, *offset, 1, field);
proto_tree_add_item(sub_tree, hf_smpp_broadcast_area_identifier,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0607:
smpp_handle_int4(sub_tree, tvb,
hf_smpp_broadcast_error_status, offset);
break;
case 0x0608:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_broadcast_area_success, offset);
break;
case 0x0609:
smpp_handle_time(sub_tree, tvb, hf_smpp_broadcast_end_time,
hf_smpp_broadcast_end_time_r, offset);
break;
case 0x060A:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_broadcast_service_group,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x060B:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_billing_identification,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x060D:
smpp_handle_string_z(sub_tree, tvb, hf_smpp_source_network_id,
offset, "Empty!");
break;
case 0x060E:
smpp_handle_string_z(sub_tree, tvb, hf_smpp_dest_network_id,
offset, "Empty!");
break;
case 0x060F:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_source_node_id,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0610:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_dest_node_id,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0611:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_dest_addr_np_resolution, offset);
break;
case 0x0612:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_dest_addr_np_information,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x0613:
if (length)
proto_tree_add_item(sub_tree, hf_smpp_dest_addr_np_country,
tvb, *offset, length, ENC_NA);
(*offset) += length;
break;
case 0x1201:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_display_time, offset);
break;
case 0x1203:
smpp_handle_int2(sub_tree, tvb,
hf_smpp_sms_signal, offset);
break;
case 0x1204:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_ms_validity, offset);
break;
case 0x130C:
if (length == 0) {
proto_tree_add_item(sub_tree,
hf_smpp_alert_on_message_delivery_null,
tvb, *offset, length, ENC_NA);
} else {
smpp_handle_int1(sub_tree, tvb,
hf_smpp_alert_on_message_delivery, offset);
}
break;
case 0x1380:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_its_reply_type, offset);
break;
case 0x1383:
smpp_handle_int1(sub_tree, tvb,
hf_smpp_its_session_number, offset);
field = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_smpp_its_session_sequence,
tvb, *offset, 1, field);
proto_tree_add_uint(sub_tree, hf_smpp_its_session_ind,
tvb, *offset, 1, field);
(*offset)++;
break;
default:
if ((tag >= 0x1400) && (tag <= 0x3FFF)) {
proto_tree_add_item(sub_tree, hf_smpp_vendor_op, tvb,
*offset, length, ENC_NA);
} else {
proto_tree_add_item(sub_tree, hf_smpp_reserved_op, tvb,
*offset, length, ENC_NA);
}
proto_item_append_text(sub_tree,": %s", tvb_bytes_to_ep_str(tvb,*offset,length));
(*offset) += length;
break;
}
}
}
void
smpp_handle_dcs(proto_tree *tree, tvbuff_t *tvb, int *offset)
{
guint8 val;
int off = *offset;
proto_tree *subtree = NULL;
proto_item *pi;
val = tvb_get_guint8(tvb, off);
pi = proto_tree_add_uint(tree, hf_smpp_data_coding, tvb, off, 1, val);
subtree = proto_item_add_subtree(pi, ett_dcs);
proto_tree_add_uint(subtree, hf_smpp_dcs, tvb, off, 1, val);
proto_tree_add_text(subtree, tvb, off, 1,
"GSM SMS Data Coding");
proto_tree_add_uint(subtree,
hf_smpp_dcs_sms_coding_group, tvb, off, 1, val);
if (val>>6 == 2) {
;
} else if (val < 0xF0) {
proto_tree_add_boolean(subtree,
hf_smpp_dcs_text_compression, tvb, off, 1, val);
proto_tree_add_boolean(subtree,
hf_smpp_dcs_class_present, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_charset, tvb, off, 1, val);
if (val & 0x10)
proto_tree_add_uint(subtree,
hf_smpp_dcs_class, tvb, off, 1, val);
} else {
if (val & 0x08)
proto_tree_add_text(subtree, tvb, off, 1,
"SMPP: Bit .... 1... should be 0 (reserved)");
proto_tree_add_uint(subtree,
hf_smpp_dcs_charset, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_class, tvb, off, 1, val);
}
proto_tree_add_text(subtree, tvb, off, 1,
"GSM CBS Data Coding");
proto_tree_add_uint(subtree,
hf_smpp_dcs_cbs_coding_group, tvb, off, 1, val);
if (val < 0x40) {
proto_tree_add_uint(subtree,
hf_smpp_dcs_cbs_language, tvb, off, 1, val);
} else if (val>>6 == 1) {
proto_tree_add_boolean(subtree,
hf_smpp_dcs_text_compression, tvb, off, 1, val);
proto_tree_add_boolean(subtree,
hf_smpp_dcs_class_present, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_charset, tvb, off, 1, val);
if (val & 0x10)
proto_tree_add_uint(subtree,
hf_smpp_dcs_class, tvb, off, 1, val);
} else if (val>>6 == 2) {
proto_tree_add_uint(subtree,
hf_smpp_dcs_charset, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_class, tvb, off, 1, val);
} else if (val>>4 == 14) {
proto_tree_add_uint(subtree,
hf_smpp_dcs_wap_charset, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_wap_class, tvb, off, 1, val);
} else if (val>>4 == 15) {
if (val & 0x08)
proto_tree_add_text(subtree, tvb, off, 1,
"SMPP: Bit .... 1... should be 0 (reserved)");
proto_tree_add_uint(subtree,
hf_smpp_dcs_charset, tvb, off, 1, val);
proto_tree_add_uint(subtree,
hf_smpp_dcs_cbs_class, tvb, off, 1, val);
}
(*offset)++;
}
static void
bind_receiver(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 field;
guint8 major, minor;
char *strval;
smpp_handle_string(tree, tvb, hf_smpp_system_id, &offset);
smpp_handle_string(tree, tvb, hf_smpp_password, &offset);
smpp_handle_string(tree, tvb, hf_smpp_system_type, &offset);
field = tvb_get_guint8(tvb, offset++);
minor = field & 0x0F;
major = (field & 0xF0) >> 4;
strval=wmem_strdup_printf(wmem_packet_scope(), "%u.%u", major, minor);
proto_tree_add_string(tree, hf_smpp_interface_version, tvb,
offset - 1, 1, strval);
smpp_handle_int1(tree, tvb, hf_smpp_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_address_range, &offset);
}
static void
query_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
}
static void
outbind(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_system_id, &offset);
smpp_handle_string(tree, tvb, hf_smpp_password, &offset);
}
static void
submit_sm(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *top_tree)
{
tvbuff_t *tvb_msg;
int offset = 0;
guint8 flag, udhi;
guint8 length;
const char *src_str = NULL;
const char *dst_str = NULL;
address save_src, save_dst;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
src_str = smpp_handle_string_return(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_npi, &offset);
dst_str = smpp_handle_string_return(tree, tvb, hf_smpp_destination_addr, &offset);
flag = tvb_get_guint8(tvb, offset);
udhi = flag & 0x40;
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_mode,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_type,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_features,
tvb, offset, 1, flag);
offset++;
smpp_handle_int1(tree, tvb, hf_smpp_protocol_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_priority_flag, &offset);
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_schedule_delivery_time,
hf_smpp_schedule_delivery_time_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Scheduled delivery time: Immediate delivery");
}
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_validity_period,
hf_smpp_validity_period_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Validity period: SMSC default validity period");
}
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_regdel_receipt, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_acks, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_notif, tvb, offset, 1, flag);
offset++;
smpp_handle_int1(tree, tvb, hf_smpp_replace_if_present_flag, &offset);
smpp_handle_dcs(tree, tvb, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_sm_default_msg_id, &offset);
length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_sm_length, tvb, offset++, 1, length);
if (length)
{
proto_tree_add_item(tree, hf_smpp_short_message,
tvb, offset, length, ENC_NA);
if (udhi)
{
DebugLog(("UDHI present - set addresses\n"));
SET_ADDRESS(&save_src, pinfo->src.type, pinfo->src.len, pinfo->src.data);
SET_ADDRESS(&save_dst, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
SET_ADDRESS(&(pinfo->src), AT_STRINGZ, 1+(int)strlen(src_str), src_str);
SET_ADDRESS(&(pinfo->dst), AT_STRINGZ, 1+(int)strlen(dst_str), dst_str);
tvb_msg = tvb_new_subset (tvb, offset,
MIN(length, tvb_reported_length(tvb) - offset), length);
call_dissector (gsm_sms_handle, tvb_msg, pinfo, top_tree);
SET_ADDRESS(&(pinfo->src), save_src.type, save_src.len, save_src.data );
SET_ADDRESS(&(pinfo->dst), save_dst.type, save_dst.len, save_dst.data);
}
offset += length;
}
smpp_handle_tlv(tree, tvb, &offset);
}
static void
replace_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 flag;
guint8 length;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_schedule_delivery_time,
hf_smpp_schedule_delivery_time_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Scheduled delivery time: Keep initial delivery time setting");
}
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_validity_period,
hf_smpp_validity_period_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Validity period: Keep initial validity period setting");
}
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_regdel_receipt, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_acks, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_notif, tvb, offset, 1, flag);
offset++;
smpp_handle_int1(tree, tvb, hf_smpp_sm_default_msg_id, &offset);
length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_sm_length, tvb, offset++, 1, length);
if (length)
proto_tree_add_item(tree, hf_smpp_short_message,
tvb, offset, length, ENC_NA);
offset += length;
}
static void
cancel_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_destination_addr, &offset);
}
static void
submit_multi(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 flag;
guint8 length;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_dlist(tree, tvb, &offset);
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_mode,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_type,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_features,
tvb, offset, 1, flag);
offset++;
smpp_handle_int1(tree, tvb, hf_smpp_protocol_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_priority_flag, &offset);
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_schedule_delivery_time,
hf_smpp_schedule_delivery_time_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Scheduled delivery time: Immediate delivery");
}
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_validity_period,
hf_smpp_validity_period_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Validity period: SMSC default validity period");
}
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_regdel_receipt, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_acks, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_notif, tvb, offset, 1, flag);
offset++;
smpp_handle_int1(tree, tvb, hf_smpp_replace_if_present_flag, &offset);
smpp_handle_dcs(tree, tvb, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_sm_default_msg_id, &offset);
length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_sm_length, tvb, offset++, 1, length);
if (length)
proto_tree_add_item(tree, hf_smpp_short_message,
tvb, offset, length, ENC_NA);
offset += length;
smpp_handle_tlv(tree, tvb, &offset);
}
static void
alert_notification(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_esme_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_esme_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_esme_addr, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
data_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 flag;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_dest_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_destination_addr, &offset);
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_mode,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_msg_type,
tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_esm_submit_features,
tvb, offset, 1, flag);
offset++;
flag = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_smpp_regdel_receipt, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_acks, tvb, offset, 1, flag);
proto_tree_add_uint(tree, hf_smpp_regdel_notif, tvb, offset, 1, flag);
offset++;
smpp_handle_dcs(tree, tvb, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
broadcast_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_priority_flag, &offset);
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_schedule_delivery_time,
hf_smpp_schedule_delivery_time_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Scheduled delivery time: Immediate delivery");
}
if (tvb_get_guint8(tvb,offset)) {
smpp_handle_time(tree, tvb, hf_smpp_validity_period,
hf_smpp_validity_period_r, &offset);
} else {
proto_tree_add_text(tree, tvb, offset++, 1,
"Validity period: SMSC default validity period");
}
smpp_handle_int1(tree, tvb, hf_smpp_replace_if_present_flag, &offset);
smpp_handle_dcs(tree, tvb, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_sm_default_msg_id, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
query_broadcast_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
cancel_broadcast_sm(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string_z(tree, tvb, hf_smpp_service_type, &offset, "(Default)");
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_ton, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_source_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
bind_receiver_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_system_id, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
query_sm_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_time(tree, tvb, hf_smpp_final_date,
hf_smpp_final_date_r, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_message_state, &offset);
smpp_handle_int1(tree, tvb, hf_smpp_error_code, &offset);
}
static void
submit_sm_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
submit_multi_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_dlist_resp(tree, tvb, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
data_sm_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
query_broadcast_sm_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_string(tree, tvb, hf_smpp_message_id, &offset);
smpp_handle_tlv(tree, tvb, &offset);
}
static void
huawei_auth_acc(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 version = 0;
smpp_handle_int1(tree, tvb, hf_huawei_smpp_version, &offset);
version = tvb_get_guint8(tvb, offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_smsc_addr, &offset);
if ( version == '3' ) {
smpp_handle_int1(tree, tvb, hf_huawei_smpp_msc_addr_noa, &offset);
smpp_handle_int1(tree, tvb, hf_huawei_smpp_msc_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_msc_addr, &offset);
}
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_string(tree, tvb, hf_smpp_destination_addr, &offset);
smpp_handle_int1(tree, tvb, hf_huawei_smpp_mo_mt_flag, &offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_sm_id, &offset);
smpp_handle_int4(tree, tvb, hf_huawei_smpp_length_auth, &offset);
smpp_handle_int4(tree, tvb, hf_huawei_smpp_service_id, &offset);
}
static void
huawei_auth_acc_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_int4(tree, tvb, hf_huawei_smpp_operation_result, &offset);
smpp_handle_int1(tree, tvb, hf_huawei_smpp_notify_mode, &offset);
}
static void
huawei_sm_result_notify(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
guint8 version = 0;
smpp_handle_int1(tree, tvb, hf_huawei_smpp_version, &offset);
version = tvb_get_guint8(tvb, offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_smsc_addr, &offset);
if ( version == '3' ) {
smpp_handle_int1(tree, tvb, hf_huawei_smpp_msc_addr_noa, &offset);
smpp_handle_int1(tree, tvb, hf_huawei_smpp_msc_addr_npi, &offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_msc_addr, &offset);
}
smpp_handle_string(tree, tvb, hf_smpp_source_addr, &offset);
smpp_handle_string(tree, tvb, hf_smpp_destination_addr, &offset);
smpp_handle_int1(tree, tvb, hf_huawei_smpp_mo_mt_flag, &offset);
smpp_handle_string(tree, tvb, hf_huawei_smpp_sm_id, &offset);
smpp_handle_int4(tree, tvb, hf_huawei_smpp_length_auth, &offset);
smpp_handle_int4(tree, tvb, hf_huawei_smpp_delivery_result, &offset);
smpp_handle_int4(tree, tvb, hf_huawei_smpp_service_id, &offset);
}
static void
huawei_sm_result_notify_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
smpp_handle_int4(tree, tvb, hf_huawei_smpp_operation_result, &offset);
}
static gboolean
dissect_smpp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint command_id;
guint command_status;
guint command_length;
if (tvb_reported_length(tvb) < SMPP_MIN_LENGTH)
return FALSE;
command_length = tvb_get_ntohl(tvb, 0);
if (command_length > 64 * 1024 || command_length < SMPP_MIN_LENGTH)
return FALSE;
command_id = tvb_get_ntohl(tvb, 4);
if (try_val_to_str(command_id, vals_command_id) == NULL)
return FALSE;
command_status = tvb_get_ntohl(tvb, 8);
if (try_val_to_str(command_status, vals_command_status) == NULL &&
try_rval_to_str(command_status, reserved_command_status) == NULL)
return FALSE;
dissect_smpp(tvb, pinfo, tree, data);
return TRUE;
}
static guint
get_smpp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset);
}
static int
dissect_smpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
first = TRUE;
if (pinfo->ptype == PT_TCP) {
tcp_dissect_pdus(tvb, pinfo, tree,
reassemble_over_tcp,
16,
get_smpp_pdu_len,
dissect_smpp_pdu, data);
} else {
guint32 offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint16 pdu_len = tvb_get_ntohl(tvb, offset);
gint pdu_real_len = tvb_length_remaining(tvb, offset);
tvbuff_t *pdu_tvb;
if (pdu_len < 1)
THROW(ReportedBoundsError);
if (pdu_real_len <= 0)
return offset;
if (pdu_real_len > pdu_len)
pdu_real_len = pdu_len;
pdu_tvb = tvb_new_subset(tvb, offset, pdu_real_len, pdu_len);
dissect_smpp_pdu(pdu_tvb, pinfo, tree, data);
offset += pdu_len;
first = FALSE;
}
}
return tvb_length(tvb);
}
static int
dissect_smpp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint command_length;
guint command_id;
guint command_status;
guint sequence_number;
smpp_tap_rec_t *tap_rec;
const gchar *command_str;
const gchar *command_status_str = NULL;
proto_item *ti = NULL;
proto_tree *smpp_tree = NULL;
if (tvb_reported_length(tvb) < SMPP_MIN_LENGTH)
return 0;
command_length = tvb_get_ntohl(tvb, offset);
offset += 4;
command_id = tvb_get_ntohl(tvb, offset);
command_str = val_to_str(command_id, vals_command_id,
"(Unknown SMPP Operation 0x%08X)");
offset += 4;
command_status = tvb_get_ntohl(tvb, offset);
if (command_id & 0x80000000) {
command_status_str = try_val_to_str(command_status, vals_command_status);
if (command_status_str == NULL) {
command_status_str = (command_status >= 0x400 && command_status <= 0x4FF ?
wmem_strdup_printf(wmem_packet_scope(), "Vendor-specific Error (0x%08X)", command_status) :
wmem_strdup_printf(wmem_packet_scope(), "(Reserved Error 0x%08X)", command_status));
}
}
offset += 4;
sequence_number = tvb_get_ntohl(tvb, offset);
offset += 4;
if (first == TRUE) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMPP");
}
if (tree) {
ti = proto_tree_add_item (tree, proto_smpp, tvb, 0, tvb_length(tvb), ENC_NA);
smpp_tree = proto_item_add_subtree (ti, ett_smpp);
}
{
tvbuff_t *pdu_tvb;
if (first == TRUE) {
col_add_fstr(pinfo->cinfo, COL_INFO, "SMPP %s", command_str);
first = FALSE;
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", command_str);
}
if (command_id & 0x80000000) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": \"%s\"",
command_status_str);
}
if (tvb_length_remaining(tvb, offset - 16 + command_length) > 0) {
pdu_tvb = tvb_new_subset(tvb, offset - 16,
command_length,
command_length);
} else {
pdu_tvb = tvb_new_subset(tvb, offset - 16,
tvb_length_remaining(tvb, offset - 16),
command_length);
}
if (tree || (command_id == 4))
{
if (tree) {
proto_tree_add_uint(smpp_tree, hf_smpp_command_length,
pdu_tvb, 0, 4, command_length);
proto_tree_add_uint(smpp_tree, hf_smpp_command_id,
pdu_tvb, 4, 4, command_id);
proto_item_append_text(ti, ", Command: %s", command_str);
if (command_id & 0x80000000) {
proto_tree_add_uint(smpp_tree, hf_smpp_command_status,
pdu_tvb, 8, 4, command_status);
proto_item_append_text (ti, ", Status: \"%s\"",
command_status_str);
}
proto_tree_add_uint(smpp_tree, hf_smpp_sequence_number,
pdu_tvb, 12, 4, sequence_number);
proto_item_append_text(ti, ", Seq: %u, Len: %u",
sequence_number, command_length);
}
if (command_length <= tvb_reported_length(pdu_tvb))
{
tvbuff_t *tmp_tvb = tvb_new_subset(pdu_tvb, 16,
-1, command_length - 16);
if (command_id & 0x80000000)
{
switch (command_id & 0x7FFFFFFF) {
case 0:
case 6:
case 7:
case 8:
case 21:
case 275:
break;
case 1:
if (!command_status)
bind_receiver_resp(smpp_tree, tmp_tvb);
break;
case 2:
if (!command_status)
bind_transmitter_resp(smpp_tree, tmp_tvb);
break;
case 3:
if (!command_status)
query_sm_resp(smpp_tree, tmp_tvb);
break;
case 4:
if (!command_status)
submit_sm_resp(smpp_tree, tmp_tvb);
break;
case 5:
if (!command_status)
deliver_sm_resp(smpp_tree, tmp_tvb);
break;
case 9:
if (!command_status)
bind_transceiver_resp(smpp_tree, tmp_tvb);
break;
case 33:
if (!command_status)
submit_multi_resp(smpp_tree, tmp_tvb);
break;
case 259:
if (!command_status)
data_sm_resp(smpp_tree, tmp_tvb);
break;
case 273:
if (!command_status)
broadcast_sm_resp(smpp_tree, tmp_tvb);
break;
case 274:
if (!command_status)
query_broadcast_sm_resp(smpp_tree, tmp_tvb);
break;
case 16777217:
if (!command_status)
huawei_auth_acc_resp(smpp_tree, tmp_tvb);
break;
case 16777218:
if (!command_status)
huawei_sm_result_notify_resp(smpp_tree, tmp_tvb);
break;
default:
break;
}
}
else
{
switch (command_id) {
case 1:
bind_receiver(smpp_tree, tmp_tvb);
break;
case 2:
bind_transmitter(smpp_tree, tmp_tvb);
break;
case 3:
query_sm(smpp_tree, tmp_tvb);
break;
case 4:
submit_sm(smpp_tree, tmp_tvb, pinfo, tree);
break;
case 5:
deliver_sm(smpp_tree, tmp_tvb, pinfo, tree);
break;
case 6:
case 21:
break;
case 7:
replace_sm(smpp_tree, tmp_tvb);
break;
case 8:
cancel_sm(smpp_tree, tmp_tvb);
break;
case 9:
bind_transceiver(smpp_tree, tmp_tvb);
break;
case 11:
outbind(smpp_tree, tmp_tvb);
break;
case 33:
submit_multi(smpp_tree, tmp_tvb);
break;
case 258:
alert_notification(smpp_tree, tmp_tvb);
break;
case 259:
data_sm(smpp_tree, tmp_tvb);
break;
case 273:
broadcast_sm(smpp_tree, tmp_tvb);
break;
case 274:
query_broadcast_sm(smpp_tree, tmp_tvb);
break;
case 275:
cancel_broadcast_sm(smpp_tree, tmp_tvb);
break;
case 16777217:
huawei_auth_acc(smpp_tree, tmp_tvb);
break;
case 16777218:
huawei_sm_result_notify(smpp_tree, tmp_tvb);
break;
default:
break;
}
}
}
}
tap_rec = wmem_new0(wmem_packet_scope(), smpp_tap_rec_t);
tap_rec->command_id = command_id;
tap_rec->command_status = command_status;
tap_queue_packet(smpp_tap, pinfo, tap_rec);
first = FALSE;
}
return tvb_length(tvb);
}
void
proto_register_smpp(void)
{
module_t *smpp_module;
static hf_register_info hf[] = {
{ &hf_smpp_command_length,
{ "Length", "smpp.command_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Total length of the SMPP PDU.",
HFILL
}
},
{ &hf_smpp_command_id,
{ "Operation", "smpp.command_id",
FT_UINT32, BASE_HEX, VALS(vals_command_id), 0x00,
"Defines the SMPP PDU.",
HFILL
}
},
{ &hf_smpp_command_status,
{ "Result", "smpp.command_status",
FT_UINT32, BASE_HEX, VALS(vals_command_status), 0x00,
"Indicates success or failure of the SMPP request.",
HFILL
}
},
{ &hf_smpp_sequence_number,
{ "Sequence #", "smpp.sequence_number",
FT_UINT32, BASE_DEC, NULL, 0x00,
"A number to correlate requests with responses.",
HFILL
}
},
{ &hf_smpp_system_id,
{ "System ID", "smpp.system_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Identifies a system.",
HFILL
}
},
{ &hf_smpp_password,
{ "Password", "smpp.password",
FT_STRING, BASE_NONE, NULL, 0x00,
"Password used for authentication.",
HFILL
}
},
{ &hf_smpp_system_type,
{ "System type", "smpp.system_type",
FT_STRING, BASE_NONE, NULL, 0x00,
"Categorizes the system.",
HFILL
}
},
{ &hf_smpp_interface_version,
{ "Version (if)", "smpp.interface_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"Version of SMPP interface supported.",
HFILL
}
},
{ &hf_smpp_service_type,
{ "Service type", "smpp.service_type",
FT_STRING, BASE_NONE, NULL, 0x00,
"SMS application service associated with the message.",
HFILL
}
},
{ &hf_smpp_addr_ton,
{ "Type of number", "smpp.addr_ton",
FT_UINT8, BASE_HEX, VALS(vals_addr_ton), 0x00,
"Indicates the type of number, given in the address.",
HFILL
}
},
{ &hf_smpp_source_addr_ton,
{ "Type of number (originator)", "smpp.source_addr_ton",
FT_UINT8, BASE_HEX, VALS(vals_addr_ton), 0x00,
"Indicates originator type of number, given in the address.",
HFILL
}
},
{ &hf_smpp_dest_addr_ton,
{ "Type of number (recipient)", "smpp.dest_addr_ton",
FT_UINT8, BASE_HEX, VALS(vals_addr_ton), 0x00,
"Indicates recipient type of number, given in the address.",
HFILL
}
},
{ &hf_smpp_addr_npi,
{ "Numbering plan indicator", "smpp.addr_npi",
FT_UINT8, BASE_HEX, VALS(vals_addr_npi), 0x00,
"Gives the numbering plan this address belongs to.",
HFILL
}
},
{ &hf_smpp_source_addr_npi,
{ "Numbering plan indicator (originator)", "smpp.source_addr_npi",
FT_UINT8, BASE_HEX, VALS(vals_addr_npi), 0x00,
"Gives originator numbering plan this address belongs to.",
HFILL
}
},
{ &hf_smpp_dest_addr_npi,
{ "Numbering plan indicator (recipient)", "smpp.dest_addr_npi",
FT_UINT8, BASE_HEX, VALS(vals_addr_npi), 0x00,
"Gives recipient numbering plan this address belongs to.",
HFILL
}
},
{ &hf_smpp_address_range,
{ "Address", "smpp.address_range",
FT_STRING, BASE_NONE, NULL, 0x00,
"Given address or address range.",
HFILL
}
},
{ &hf_smpp_source_addr,
{ "Originator address", "smpp.source_addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"Address of SME originating this message.",
HFILL
}
},
{ &hf_smpp_destination_addr,
{ "Recipient address", "smpp.destination_addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"Address of SME receiving this message.",
HFILL
}
},
{ &hf_smpp_esm_submit_msg_mode,
{ "Messaging mode", "smpp.esm.submit.msg_mode",
FT_UINT8, BASE_HEX, VALS(vals_esm_submit_msg_mode), 0x03,
"Mode attribute for this message.",
HFILL
}
},
{ &hf_smpp_esm_submit_msg_type,
{ "Message type", "smpp.esm.submit.msg_type",
FT_UINT8, BASE_HEX, VALS(vals_esm_submit_msg_type), 0x3C,
"Type attribute for this message.",
HFILL
}
},
{ &hf_smpp_esm_submit_features,
{ "GSM features", "smpp.esm.submit.features",
FT_UINT8, BASE_HEX, VALS(vals_esm_submit_features), 0xC0,
"GSM network specific features.",
HFILL
}
},
{ &hf_smpp_protocol_id,
{ "Protocol id.", "smpp.protocol_id",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Protocol identifier according GSM 03.40.",
HFILL
}
},
{ &hf_smpp_priority_flag,
{ "Priority level", "smpp.priority_flag",
FT_UINT8, BASE_HEX, VALS(vals_priority_flag), 0x00,
"The priority level of the short message.",
HFILL
}
},
{ &hf_smpp_schedule_delivery_time,
{ "Scheduled delivery time", "smpp.schedule_delivery_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x00,
"Scheduled time for delivery of short message.",
HFILL
}
},
{ &hf_smpp_schedule_delivery_time_r,
{ "Scheduled delivery time", "smpp.schedule_delivery_time_r",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"Scheduled time for delivery of short message.",
HFILL
}
},
{ &hf_smpp_validity_period,
{ "Validity period", "smpp.validity_period",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x00,
"Validity period of this message.",
HFILL
}
},
{ &hf_smpp_validity_period_r,
{ "Validity period", "smpp.validity_period_r",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"Validity period of this message.",
HFILL
}
},
{ &hf_smpp_regdel_receipt,
{ "Delivery receipt", "smpp.regdel.receipt",
FT_UINT8, BASE_HEX, VALS(vals_regdel_receipt), 0x03,
"SMSC delivery receipt request.",
HFILL
}
},
{ &hf_smpp_regdel_acks,
{ "Message type", "smpp.regdel.acks",
FT_UINT8, BASE_HEX, VALS(vals_regdel_acks), 0x0C,
"SME acknowledgement request.",
HFILL
}
},
{ &hf_smpp_regdel_notif,
{ "Intermediate notif", "smpp.regdel.notif",
FT_UINT8, BASE_HEX, VALS(vals_regdel_notif), 0x10,
"Intermediate notification request.",
HFILL
}
},
{ &hf_smpp_replace_if_present_flag,
{ "Replace", "smpp.replace_if_present_flag",
FT_UINT8, BASE_HEX, VALS(vals_replace_if_present_flag), 0x01,
"Replace the short message with this one or not.",
HFILL
}
},
{ &hf_smpp_data_coding,
{ "Data coding", "smpp.data_coding",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Defines the encoding scheme of the message.",
HFILL
}
},
{ &hf_smpp_sm_default_msg_id,
{ "Predefined message", "smpp.sm_default_msg_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Index of a predefined ('canned') short message.",
HFILL
}
},
{ &hf_smpp_sm_length,
{ "Message length", "smpp.sm_length",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Length of the message content.",
HFILL
}
},
{ &hf_smpp_short_message,
{ "Message", "smpp.message",
FT_NONE, BASE_NONE, NULL, 0x00,
"The actual message or data.",
HFILL
}
},
{ &hf_smpp_message_id,
{ "Message id.", "smpp.message_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Identifier of the submitted short message.",
HFILL
}
},
{ &hf_smpp_dlist,
{ "Destination list", "smpp.dlist",
FT_NONE, BASE_NONE, NULL, 0x00,
"The list of destinations for a short message.",
HFILL
}
},
{ &hf_smpp_dlist_resp,
{ "Unsuccessful delivery list", "smpp.dlist_resp",
FT_NONE, BASE_NONE, NULL, 0x00,
"The list of unsuccessful deliveries to destinations.",
HFILL
}
},
{ &hf_smpp_dl_name,
{ "Distr. list name", "smpp.dl_name",
FT_STRING, BASE_NONE, NULL, 0x00,
"The name of the distribution list.",
HFILL
}
},
{ &hf_smpp_final_date,
{ "Final date", "smpp.final_date",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x00,
"Date-time when the queried message reached a final state.",
HFILL
}
},
{ &hf_smpp_final_date_r,
{ "Final date", "smpp.final_date_r",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"Date-time when the queried message reached a final state.",
HFILL
}
},
{ &hf_smpp_message_state,
{ "Message state", "smpp.message_state",
FT_UINT8, BASE_DEC, VALS(vals_message_state), 0x00,
"Specifies the status of the queried short message.",
HFILL
}
},
{ &hf_smpp_error_code,
{ "Error code", "smpp.error_code",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Network specific error code defining reason for failure.",
HFILL
}
},
{ &hf_smpp_error_status_code,
{ "Status", "smpp.error_status_code",
FT_UINT32, BASE_HEX, VALS(vals_command_status), 0x00,
"Indicates success/failure of request for this address.",
HFILL
}
},
{ &hf_smpp_esme_addr_ton,
{ "Type of number (ESME)", "smpp.esme_addr_ton",
FT_UINT8, BASE_HEX, VALS(vals_addr_ton), 0x00,
"Indicates recipient type of number, given in the address.",
HFILL
}
},
{ &hf_smpp_esme_addr_npi,
{ "Numbering plan indicator (ESME)", "smpp.esme_addr_npi",
FT_UINT8, BASE_HEX, VALS(vals_addr_npi), 0x00,
"Gives the numbering plan this address belongs to.",
HFILL
}
},
{ &hf_smpp_esme_addr,
{ "ESME address", "smpp.esme_addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"Address of ESME originating this message.",
HFILL
}
},
{ &hf_smpp_dest_addr_subunit,
{ "Subunit destination", "smpp.dest_addr_subunit",
FT_UINT8, BASE_HEX, VALS(vals_addr_subunit), 0x00,
"Subunit address within mobile to route message to.",
HFILL
}
},
{ &hf_smpp_source_addr_subunit,
{ "Subunit origin", "smpp.source_addr_subunit",
FT_UINT8, BASE_HEX, VALS(vals_addr_subunit), 0x00,
"Subunit address within mobile that generated the message.",
HFILL
}
},
{ &hf_smpp_dest_network_type,
{ "Destination network", "smpp.dest_network_type",
FT_UINT8, BASE_HEX, VALS(vals_network_type), 0x00,
"Network associated with the destination address.",
HFILL
}
},
{ &hf_smpp_source_network_type,
{ "Originator network", "smpp.source_network_type",
FT_UINT8, BASE_HEX, VALS(vals_network_type), 0x00,
"Network associated with the originator address.",
HFILL
}
},
{ &hf_smpp_dest_bearer_type,
{ "Destination bearer", "smpp.dest_bearer_type",
FT_UINT8, BASE_HEX, VALS(vals_bearer_type), 0x00,
"Desired bearer for delivery of message.",
HFILL
}
},
{ &hf_smpp_source_bearer_type,
{ "Originator bearer", "smpp.source_bearer_type",
FT_UINT8, BASE_HEX, VALS(vals_bearer_type), 0x00,
"Bearer over which the message originated.",
HFILL
}
},
{ &hf_smpp_dest_telematics_id,
{ "Telematic interworking (dest)", "smpp.dest_telematics_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Telematic interworking to be used for message delivery.",
HFILL
}
},
{ &hf_smpp_source_telematics_id,
{ "Telematic interworking (orig)", "smpp.source_telematics_id",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Telematic interworking used for message submission.",
HFILL
}
},
{ &hf_smpp_qos_time_to_live,
{ "Validity period", "smpp.qos_time_to_live",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Number of seconds to retain message before expiry.",
HFILL
}
},
{ &hf_smpp_payload_type,
{ "Payload", "smpp.payload_type",
FT_UINT8, BASE_DEC, VALS(vals_payload_type), 0x00,
"PDU type contained in the message payload.",
HFILL
}
},
{ &hf_smpp_additional_status_info_text,
{ "Information", "smpp.additional_status_info_text",
FT_STRING, BASE_NONE, NULL, 0x00,
"Description of the meaning of a response PDU.",
HFILL
}
},
{ &hf_smpp_receipted_message_id,
{ "SMSC identifier", "smpp.receipted_message_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"SMSC handle of the message being received.",
HFILL
}
},
{ &hf_smpp_privacy_indicator,
{ "Privacy indicator", "smpp.privacy_indicator",
FT_UINT8, BASE_DEC, VALS(vals_privacy_indicator), 0x00,
"Indicates the privacy level of the message.",
HFILL
}
},
{ &hf_smpp_source_subaddress,
{ "Source Subaddress", "smpp.source_subaddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_smpp_dest_subaddress,
{ "Destination Subaddress", "smpp.dest_subaddress",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_smpp_user_message_reference,
{ "Message reference", "smpp.user_message_reference",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Reference to the message, assigned by the user.",
HFILL
}
},
{ &hf_smpp_user_response_code,
{ "Application response code", "smpp.user_response_code",
FT_UINT8, BASE_HEX, NULL, 0x00,
"A response code set by the user.",
HFILL
}
},
{ &hf_smpp_language_indicator,
{ "Language", "smpp.language_indicator",
FT_UINT8, BASE_DEC, VALS(vals_language_indicator), 0x00,
"Indicates the language of the short message.",
HFILL
}
},
{ &hf_smpp_source_port,
{ "Source port", "smpp.source_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Application port associated with the source of the message.",
HFILL
}
},
{ &hf_smpp_destination_port,
{ "Destination port", "smpp.destination_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Application port associated with the destination of the message.",
HFILL
}
},
{ &hf_smpp_sar_msg_ref_num,
{ "SAR reference number", "smpp.sar_msg_ref_num",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Reference number for a concatenated short message.",
HFILL
}
},
{ &hf_smpp_sar_total_segments,
{ "SAR size", "smpp.sar_total_segments",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Number of segments of a concatenated short message.",
HFILL
}
},
{ &hf_smpp_sar_segment_seqnum,
{ "SAR sequence number", "smpp.sar_segment_seqnum",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Segment number within a concatenated short message.",
HFILL
}
},
{ &hf_smpp_display_time,
{ "Display time", "smpp.display_time",
FT_UINT8, BASE_DEC, VALS(vals_display_time), 0x00,
"Associates a display time with the message on the handset.",
HFILL
}
},
{ &hf_smpp_sms_signal,
{ "SMS signal", "smpp.sms_signal",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Alert the user according to the information contained within this information element.",
HFILL
}
},
{ &hf_smpp_ms_validity,
{ "Validity info", "smpp.ms_validity",
FT_UINT8, BASE_DEC, VALS(vals_ms_validity), 0x00,
"Associates validity info with the message on the handset.",
HFILL
}
},
{ &hf_smpp_dpf_result,
{ "Delivery pending set?", "smpp.dpf_result",
FT_UINT8, BASE_DEC, VALS(vals_dpf_result), 0x00,
"Indicates whether Delivery Pending Flag was set.",
HFILL
}
},
{ &hf_smpp_set_dpf,
{ "Request DPF set", "smpp.set_dpf",
FT_UINT8, BASE_DEC, VALS(vals_set_dpf), 0x00,
"Request to set the DPF for certain failure scenario's.",
HFILL
}
},
{ &hf_smpp_ms_availability_status,
{ "Availability status", "smpp.ms_availability_status",
FT_UINT8, BASE_DEC, VALS(vals_ms_availability_status), 0x00,
"Indicates the availability state of the handset.",
HFILL
}
},
{ &hf_smpp_delivery_failure_reason,
{ "Delivery failure reason", "smpp.delivery_failure_reason",
FT_UINT8, BASE_DEC, VALS(vals_delivery_failure_reason), 0x00,
"Indicates the reason for a failed delivery attempt.",
HFILL
}
},
{ &hf_smpp_more_messages_to_send,
{ "More messages?", "smpp.more_messages_to_send",
FT_UINT8, BASE_DEC, VALS(vals_more_messages_to_send), 0x00,
"Indicates more messages pending for the same destination.",
HFILL
}
},
{ &hf_smpp_number_of_messages,
{ "Number of messages", "smpp.number_of_messages",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Indicates number of messages stored in a mailbox.",
HFILL
}
},
{ &hf_smpp_its_reply_type,
{ "Reply method", "smpp.its_reply_type",
FT_UINT8, BASE_DEC, VALS(vals_its_reply_type), 0x00,
"Indicates the handset reply method on message receipt.",
HFILL
}
},
{ &hf_smpp_ussd_service_op,
{ "USSD service operation", "smpp.ussd_service_op",
FT_UINT8, BASE_DEC, VALS(vals_ussd_service_op), 0x00,
"Indicates the USSD service operation.",
HFILL
}
},
{ &hf_smpp_vendor_op,
{ "Value", "smpp.vendor_op",
FT_BYTES, BASE_NONE, NULL, 0x00,
"A supplied optional parameter specific to an SMSC-vendor.",
HFILL
}
},
{ &hf_smpp_reserved_op,
{ "Value", "smpp.reserved_op",
FT_BYTES, BASE_NONE, NULL, 0x00,
"An optional parameter that is reserved in this version.",
HFILL
}
},
{ &hf_smpp_msg_wait_ind,
{ "Indication", "smpp.msg_wait.ind",
FT_UINT8, BASE_HEX, VALS(vals_msg_wait_ind), 0x80,
"Indicates to the handset that a message is waiting.",
HFILL
}
},
{ &hf_smpp_msg_wait_type,
{ "Type", "smpp.msg_wait.type",
FT_UINT8, BASE_HEX, VALS(vals_msg_wait_type), 0x03,
"Indicates type of message that is waiting.",
HFILL
}
},
{ &hf_smpp_SC_interface_version,
{ "SMSC-supported version", "smpp.SC_interface_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"Version of SMPP interface supported by the SMSC.",
HFILL
}
},
{ &hf_smpp_callback_num_pres,
{ "Presentation", "smpp.callback_num.pres",
FT_UINT8, BASE_HEX, VALS(vals_callback_num_pres), 0x0C,
"Controls the presentation indication.",
HFILL
}
},
{ &hf_smpp_callback_num_scrn,
{ "Screening", "smpp.callback_num.scrn",
FT_UINT8, BASE_HEX, VALS(vals_callback_num_scrn), 0x03,
"Controls screening of the callback-number.",
HFILL
}
},
{ &hf_smpp_callback_num_atag,
{ "Callback number - alphanumeric display tag",
"smpp.callback_num_atag",
FT_NONE, BASE_NONE, NULL, 0x00,
"Associates an alphanumeric display with call back number.",
HFILL
}
},
{ &hf_smpp_callback_num,
{ "Callback number", "smpp.callback_num",
FT_NONE, BASE_NONE, NULL, 0x00,
"Associates a call back number with the message.",
HFILL
}
},
{ &hf_smpp_network_error_type,
{ "Error type", "smpp.network_error.type",
FT_UINT8, BASE_DEC, VALS(vals_network_error_type), 0x00,
"Indicates the network type.",
HFILL
}
},
{ &hf_smpp_network_error_code,
{ "Error code", "smpp.network_error.code",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Gives the actual network error code.",
HFILL
}
},
{ &hf_smpp_message_payload,
{ "Payload", "smpp.message_payload",
FT_NONE, BASE_NONE, NULL, 0x00,
"Short message user data.",
HFILL
}
},
{ &hf_smpp_alert_on_message_delivery_null,
{ "Alert on delivery", "smpp.alert_on_message_delivery",
FT_NONE, BASE_NONE, NULL, 0x00,
"Instructs the handset to alert user on message delivery.",
HFILL
}
},
{ &hf_smpp_alert_on_message_delivery,
{ "Alert on delivery", "smpp.alert_on_message_delivery",
FT_UINT8, BASE_DEC, VALS(vals_alert_on_message_delivery), 0x00,
"Instructs the handset to alert user on message delivery.",
HFILL
}
},
{ &hf_smpp_its_session_number,
{ "Session number", "smpp.its_session.number",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Session number of interactive teleservice.",
HFILL
}
},
{ &hf_smpp_its_session_sequence,
{ "Sequence number", "smpp.its_session.sequence",
FT_UINT8, BASE_HEX, NULL, 0xFE,
"Sequence number of the dialogue unit.",
HFILL
}
},
{ &hf_smpp_its_session_ind,
{ "Session indicator", "smpp.its_session.ind",
FT_UINT8, BASE_HEX, VALS(vals_its_session_ind), 0x01,
"Indicates whether this message is end of conversation.",
HFILL
}
},
{ &hf_smpp_opt_params,
{ "Optional parameters", "smpp.opt_params",
FT_NONE, BASE_NONE, NULL, 0x00,
"The list of optional parameters in this operation.",
HFILL
}
},
{ &hf_smpp_opt_param,
{ "Optional parameter", "smpp.opt_param",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_smpp_opt_param_tag,
{ "Tag", "smpp.opt_param_tag",
FT_UINT16, BASE_HEX, NULL, 0x00,
"Optional parameter identifier tag",
HFILL
}
},
{ &hf_smpp_opt_param_len,
{ "Length", "smpp.opt_param_len",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Optional parameter length",
HFILL
}
},
{ &hf_smpp_dcs,
{ "SMPP Data Coding Scheme", "smpp.dcs",
FT_UINT8, BASE_HEX, VALS(vals_data_coding), 0x00,
"Data Coding Scheme according to SMPP.",
HFILL
}
},
{ &hf_smpp_dcs_sms_coding_group,
{ "DCS Coding Group for SMS", "smpp.dcs.sms_coding_group",
FT_UINT8, BASE_HEX, VALS(vals_dcs_sms_coding_group), 0xF0,
"Data Coding Scheme coding group for GSM Short Message Service.",
HFILL
}
},
{ &hf_smpp_dcs_text_compression,
{ "DCS Text compression", "smpp.dcs.text_compression",
FT_BOOLEAN, 8, TFS(&tfs_dcs_text_compression), 0x20,
"Indicates if text compression is used.", HFILL
}
},
{ &hf_smpp_dcs_class_present,
{ "DCS Class present", "smpp.dcs.class_present",
FT_BOOLEAN, 8, TFS(&tfs_dcs_class_present), 0x10,
"Indicates if the message class is present (defined).", HFILL
}
},
{ &hf_smpp_dcs_charset,
{ "DCS Character set", "smpp.dcs.charset",
FT_UINT8, BASE_HEX, VALS(vals_dcs_charset), 0x0C,
"Specifies the character set used in the message.", HFILL
}
},
{ &hf_smpp_dcs_class,
{ "DCS Message class", "smpp.dcs.class",
FT_UINT8, BASE_HEX, VALS(vals_dcs_class), 0x03,
"Specifies the message class.", HFILL
}
},
{ &hf_smpp_dcs_cbs_coding_group,
{ "DCS Coding Group for CBS", "smpp.dcs.cbs_coding_group",
FT_UINT8, BASE_HEX, VALS(vals_dcs_cbs_coding_group), 0xF0,
"Data Coding Scheme coding group for GSM Cell Broadcast Service.",
HFILL
}
},
{ &hf_smpp_dcs_cbs_language,
{ "DCS CBS Message language", "smpp.dcs.cbs_language",
FT_UINT8, BASE_HEX, VALS(vals_dcs_cbs_language), 0x3F,
"Language of the GSM Cell Broadcast Service message.", HFILL
}
},
{ &hf_smpp_dcs_cbs_class,
{ "DCS CBS Message class", "smpp.dcs.cbs_class",
FT_UINT8, BASE_HEX, VALS(vals_dcs_cbs_class), 0x03,
"Specifies the message class for GSM Cell Broadcast Service, for the Data coding / message handling code group.", HFILL
}
},
{ &hf_smpp_dcs_wap_charset,
{ "DCS Message coding", "smpp.dcs.wap_coding",
FT_UINT8, BASE_HEX, VALS(vals_dcs_wap_charset), 0x0C,
"Specifies the used message encoding, as specified by the WAP Forum (WAP over GSM USSD).", HFILL
}
},
{ &hf_smpp_dcs_wap_class,
{ "DCS CBS Message class", "smpp.dcs.wap_class",
FT_UINT8, BASE_HEX, VALS(vals_dcs_wap_class), 0x03,
"Specifies the message class for GSM Cell Broadcast Service, as specified by the WAP Forum (WAP over GSM USSD).", HFILL
}
},
{ &hf_smpp_congestion_state,
{ "Congestion State", "smpp.congestion_state",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(vals_congestion_state), 0x00,
"Congestion info between ESME and MC for flow control/cong. control", HFILL
}
},
{ &hf_smpp_billing_identification,
{ "Billing Identification", "smpp.billing_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Billing identification info", HFILL
}
},
{ &hf_smpp_dest_addr_np_country,
{ "Destination Country Code", "smpp.dest_addr_np_country",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Destination Country Code (E.164 Region Code)", HFILL
}
},
{ &hf_smpp_dest_addr_np_information,
{ "Number Portability information", "smpp.dest_addr_np_info",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_smpp_dest_addr_np_resolution,
{ "Number Portability query information", "smpp.dest_addr_np_resolution",
FT_UINT8, BASE_DEC, VALS(vals_dest_addr_np_resolution), 0x00,
"Number Portability query information - method used to resolve number", HFILL
}
},
{ &hf_smpp_source_network_id,
{ "Source Network ID", "smpp.source_network_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Unique ID for a network or ESME operator", HFILL
}
},
{ &hf_smpp_source_node_id,
{ "Source Node ID", "smpp.source_node_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Unique ID for a ESME or MC node", HFILL
}
},
{ &hf_smpp_dest_network_id,
{ "Destination Network ID", "smpp.dest_network_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Unique ID for a network or ESME operator", HFILL
}
},
{ &hf_smpp_dest_node_id,
{ "Destination Node ID", "smpp.dest_node_id",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Unique ID for a ESME or MC node", HFILL
}
},
{ &hf_smpp_broadcast_channel_indicator,
{ "Cell Broadcast channel", "smpp.broadcast_channel_indicator",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(vals_broadcast_channel_indicator), 0x00,
NULL, HFILL
}
},
{ &hf_smpp_broadcast_content_type_nw,
{ "Broadcast Content Type - Network Tag", "smpp.broadcast_content_type.nw",
FT_UINT8, BASE_DEC, VALS(vals_broadcast_content_type_nw), 0x00,
"Cell Broadcast content type", HFILL
}
},
{ &hf_smpp_broadcast_content_type_type,
{ "Broadcast Content Type - Content Type", "smpp.broadcast_content_type.type",
FT_UINT16, BASE_HEX, VALS(vals_broadcast_content_type_type), 0x00,
"Cell Broadcast content type", HFILL
}
},
{ &hf_smpp_broadcast_content_type_info,
{ "Broadcast Content Type Info", "smpp.broadcast_content_type.info",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Cell Broadcast content type Info", HFILL
}
},
{ &hf_smpp_broadcast_message_class,
{ "Broadcast Message Class", "smpp.broadcast_message_class",
FT_UINT8, BASE_HEX, VALS(vals_broadcast_message_class), 0x00,
"Cell Broadcast Message Class", HFILL
}
},
{ &hf_smpp_broadcast_rep_num,
{ "Broadcast Message - Number of repetitions requested", "smpp.broadcast_rep_num",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Cell Broadcast Message - Number of repetitions requested", HFILL
}
},
{ &hf_smpp_broadcast_frequency_interval_unit,
{ "Broadcast Message - frequency interval - Unit", "smpp.broadcast_frequency_interval.unit",
FT_UINT8, BASE_HEX, VALS(vals_broadcast_frequency_interval_unit), 0x00,
"Cell Broadcast Message - frequency interval at which broadcast must be repeated", HFILL
}
},
{ &hf_smpp_broadcast_frequency_interval_value,
{ "Broadcast Message - frequency interval - Unit", "smpp.broadcast_frequency_interval.value",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Cell Broadcast Message - frequency interval at which broadcast must be repeated", HFILL
}
},
{ &hf_smpp_broadcast_area_identifier,
{ "Broadcast Message - Area Identifier", "smpp.broadcast_area_identifier",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Cell Broadcast Message - Area Identifier", HFILL
}
},
{ &hf_smpp_broadcast_area_identifier_format,
{ "Broadcast Message - Area Identifier Format", "smpp.broadcast_area_identifier.format",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING, RVALS(vals_broadcast_area_identifier_format), 0x00,
"Cell Broadcast Message - Area Identifier Format", HFILL
}
},
{ &hf_smpp_broadcast_error_status,
{ "Broadcast Message - Error Status", "smpp.broadcast_error_status",
FT_UINT32, BASE_HEX, VALS(vals_command_status), 0x00,
"Cell Broadcast Message - Error Status", HFILL
}
},
{ &hf_smpp_broadcast_area_success,
{ "Broadcast Message - Area Success", "smpp.broadcast_area_success",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(vals_broadcast_area_success), 0x00,
"Cell Broadcast Message - success rate indicator (ratio) - No. of BTS which accepted Message:Total BTS", HFILL
}
},
{ &hf_smpp_broadcast_end_time,
{ "Broadcast Message - End Time", "smpp.broadcast_end_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x00,
"Cell Broadcast Message - Date and time at which MC set the state of the message to terminated", HFILL
}
},
{ &hf_smpp_broadcast_end_time_r,
{ "Broadcast Message - End Time", "smpp.broadcast_end_time_r",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"Cell Broadcast Message - Date and time at which MC set the state of the message to terminated", HFILL
}
},
{ &hf_smpp_broadcast_service_group,
{ "Broadcast Message - Service Group", "smpp.broadcast_service_group",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Cell Broadcast Message - Service Group", HFILL
}
},
{ &hf_huawei_smpp_version,
{ "Version of SMPP+", "smpp.smppplus_version",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Indicates the SMPP+ version", HFILL
}
},
{ &hf_huawei_smpp_smsc_addr,
{ "SMPP+: GT of SMSC", "smpp.smsc_addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"SMPP+: GT of SMSC", HFILL
}
},
{ &hf_huawei_smpp_msc_addr_noa,
{ "SMPP+: NOA of MSC address", "smpp.msc_addr_noa",
FT_UINT8, BASE_DEC, VALS(vals_msc_addr_noa), 0x00,
"SMPP+: Indicates the TON of MSC address", HFILL
}
},
{ &hf_huawei_smpp_msc_addr_npi,
{ "SMPP+: NPI of MSC address", "smpp.msc_addr_npi",
FT_UINT8, BASE_DEC, VALS(vals_msc_addr_npi), 0x00,
"SMPP+: Indicates the NPI of MSC address", HFILL
}
},
{ &hf_huawei_smpp_msc_addr,
{ "SMPP+: GT of MSC", "smpp.msc_addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"SMPP+: GT of MSC", HFILL
}
},
{ &hf_huawei_smpp_mo_mt_flag,
{ "SMPP+: Charge for MO or MT", "smpp.mo_mt_flag",
FT_UINT8, BASE_DEC, VALS(vals_mo_mt_flag), 0x00,
"SMPP+: Indicates the Charge side of MO or MT", HFILL
}
},
{ &hf_huawei_smpp_sm_id,
{ "SMPP+: Unique SM ID", "smpp.sm_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"SMPP+: Unique SM ID which is generated by SMSC", HFILL
}
},
{ &hf_huawei_smpp_length_auth,
{ "SMPP+: Length of SMS", "smpp.length_auth",
FT_UINT32, BASE_DEC, NULL, 0x00,
"SMPP+: Indicates the Length of SMS", HFILL
}
},
{ &hf_huawei_smpp_service_id,
{ "SMPP+: Service ID of SMSC", "smpp.service_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
"SMPP+: Indicates the Service ID of SMSC", HFILL
}
},
{ &hf_huawei_smpp_operation_result,
{ "SMPP+: Authentication result of SCP", "smpp.operation_result",
FT_UINT32, BASE_DEC, VALS(vals_operation_result), 0x00,
"SMPP+: Indicates the Authentication result of SCP", HFILL
}
},
{ &hf_huawei_smpp_notify_mode,
{ "SMPP+: SMS notify mode", "smpp.notify_mode",
FT_UINT8, BASE_DEC, VALS(vals_notify_mode), 0x00,
"SMPP+: Indicates the SMS notify mode", HFILL
}
},
{ &hf_huawei_smpp_delivery_result,
{ "SMPP+: Delivery result of SMS", "smpp.delivery_result",
FT_UINT32, BASE_DEC, VALS(vals_delivery_result), 0x00,
"SMPP+: Indicates the Delivery result of SMS", HFILL
}
}
};
static gint *ett[] = {
&ett_smpp,
&ett_dlist,
&ett_dlist_resp,
&ett_opt_params,
&ett_opt_param,
&ett_dcs,
};
DebugLog(("Registering SMPP dissector\n"));
proto_smpp = proto_register_protocol("Short Message Peer to Peer",
"SMPP", "smpp");
proto_register_field_array(proto_smpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("smpp", dissect_smpp, proto_smpp);
smpp_tap = register_tap("smpp");
smpp_module = prefs_register_protocol (proto_smpp, NULL);
prefs_register_bool_preference (smpp_module,
"reassemble_smpp_over_tcp",
"Reassemble SMPP over TCP messages spanning multiple TCP segments",
"Whether the SMPP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable "
"\"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&reassemble_over_tcp);
}
void
proto_reg_handoff_smpp(void)
{
dissector_handle_t smpp_handle;
smpp_handle = find_dissector("smpp");
dissector_add_handle("tcp.port", smpp_handle);
heur_dissector_add("tcp", dissect_smpp_heur, proto_smpp);
heur_dissector_add("x.25", dissect_smpp_heur, proto_smpp);
DebugLog(("Finding gsm_sms_ud subdissector\n"));
gsm_sms_handle = find_dissector("gsm_sms_ud");
DISSECTOR_ASSERT(gsm_sms_handle);
stats_tree_register_with_group("smpp","smpp_commands", "SM_PP Operations", 0,
smpp_stats_tree_per_packet, smpp_stats_tree_init,
NULL, REGISTER_STAT_GROUP_TELEPHONY);
}
