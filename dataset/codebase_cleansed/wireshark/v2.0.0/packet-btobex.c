static void
save_path(packet_info *pinfo, const gchar *current_path, const gchar *name,
gboolean go_up, obex_proto_data_t *obex_proto_data)
{
if (!pinfo->fd->flags.visited) {
obex_path_data_t *obex_path_data;
wmem_tree_key_t key[6];
guint32 frame_number;
const gchar *path = path_unknown;
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &obex_proto_data->interface_id;
key[1].length = 1;
key[1].key = &obex_proto_data->adapter_id;
key[2].length = 1;
key[2].key = &obex_proto_data->chandle;
key[3].length = 1;
key[3].key = &obex_proto_data->channel;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
obex_path_data = wmem_new(wmem_file_scope(), obex_path_data_t);
obex_path_data->interface_id = obex_proto_data->interface_id;
obex_path_data->adapter_id = obex_proto_data->adapter_id;
obex_path_data->chandle = obex_proto_data->chandle;
obex_path_data->channel = obex_proto_data->channel;
if (go_up == TRUE) {
if (current_path != path_unknown && current_path != path_root) {
gchar *i_path;
i_path = g_strrstr(current_path, "/");
if (!i_path) {
current_path = path_unknown;
} else {
if (i_path == current_path)
path = current_path = path_root;
else
path = current_path = wmem_strndup(wmem_epan_scope(), current_path, i_path - current_path - 1);
}
}
}
if (name && *name == '\0')
path = path_root;
else if (name && current_path == path_root)
path = wmem_strdup_printf(wmem_file_scope(), "/%s", name);
else if (name)
path = wmem_strdup_printf(wmem_file_scope(), "%s/%s", current_path, name);
obex_path_data->path = path;
wmem_tree_insert32_array(obex_path, key, obex_path_data);
}
}
static void media_type_prompt(packet_info *pinfo, gchar* result)
{
gchar *value_data;
value_data = (gchar *) p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE);
if (value_data)
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Media Type %s as", (gchar *) value_data);
else
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Unknown Media Type");
}
static gpointer media_type_value(packet_info *pinfo)
{
gchar *value_data;
value_data = (gchar *) p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE);
if (value_data)
return (gpointer) value_data;
return NULL;
}
static void btobex_profile_prompt(packet_info *pinfo _U_, gchar* result)
{
guint8 *value_data;
value_data = (guint8 *) p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_BTOBEX_PROFILE);
if (value_data)
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "OBEX Profile 0x%04x as", (guint) *value_data);
else
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Unknown OBEX Profile");
}
static gpointer btobex_profile_value(packet_info *pinfo _U_)
{
guint8 *value_data;
value_data = (guint8 *) p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_BTOBEX_PROFILE);
if (value_data)
return GUINT_TO_POINTER((gulong)*value_data);
return NULL;
}
static void
defragment_init(void)
{
reassembly_table_init(&btobex_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
defragment_cleanup(void)
{
reassembly_table_destroy(&btobex_reassembly_table);
}
static int
is_ascii_str(const guint8 *str, int length)
{
int i;
if ((length < 1) || (str[length-1] != '\0'))
return 0;
for(i=0; i<length-1; i++) {
if ((str[i] < 0x20) && (str[i] != 0x0a))
break;
}
if (i < (length-1))
return 0;
return 1;
}
static gint
dissect_btobex_application_parameter_raw(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset,
tvb_captured_length_remaining(tvb, offset), "Parameter: 0x%02x", parameter_id);
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_application_parameter_id, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset,
1, ENC_BIG_ENDIAN);
parameter_length = tvb_get_guint8(tvb, offset);
proto_item_set_len(parameter_item, parameter_length + 2);
offset += 1;
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset,
parameter_length, ENC_NA);
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_bpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
bpp_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_bpp_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_length != 4) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be 4, but there is %i", parameter_length);
} else switch (parameter_id) {
case 0x01:
proto_tree_add_item(parameter_tree, hf_bpp_application_parameter_data_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_bpp_application_parameter_data_count, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x03:
proto_tree_add_item(parameter_tree, hf_bpp_application_parameter_data_job_id, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(parameter_tree, hf_bpp_application_parameter_data_file_size, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_bip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
static gint required_length_map[] = {0, 2, 2, 1, 4, 4, 4, 1, 1, 16, 1};
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
bip_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_id < (sizeof(required_length_map)/sizeof(gint)) &&
required_length_map[parameter_id] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map[parameter_id], parameter_length);
} else switch (parameter_id) {
case 0x01:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_number_of_returned_handles, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_list_start_offset, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x03:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_latest_captured_images, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_partial_file_length, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x05:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_partial_file_start_offset, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x06:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_total_file_size, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_end_flag, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x08:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_remote_display, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x09:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_service_id, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0A:
proto_tree_add_item(parameter_tree, hf_bip_application_parameter_data_store_flag, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_pbap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
static gint required_length_map[] = {0, 1, -1, 1, 2, 2, 8, 1, 2, 1, 16, 16, 8, 16, 1, 1};
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
pbap_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_id < (sizeof(required_length_map)/sizeof(gint)) &&
required_length_map[parameter_id] != -1 &&
required_length_map[parameter_id] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map[parameter_id], parameter_length);
} else switch (parameter_id) {
case 0x01:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_order, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_search_value, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
case 0x03:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_search_attribute, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_max_list_count, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x05:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_list_start_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x06:
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_pbap_application_parameter_data_filter, ett_btobex_filter, hfx_pbap_application_parameter_data_filter_1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_pbap_application_parameter_data_filter, ett_btobex_filter, hfx_pbap_application_parameter_data_filter_0, ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_format, tvb, offset, 1, ENC_NA);
break;
case 0x08:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_phonebook_size, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x09:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_new_missed_calls, tvb, offset, 1, ENC_NA);
break;
case 0x0A:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_primary_version_counter, tvb, offset, 16, ENC_NA);
break;
case 0x0B:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_secondary_version_counter, tvb, offset, 16, ENC_NA);
break;
case 0x0C:
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_pbap_application_parameter_vcard_selector, ett_btobex_filter, hfx_pbap_application_parameter_data_filter_1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_pbap_application_parameter_vcard_selector, ett_btobex_filter, hfx_pbap_application_parameter_data_filter_0, ENC_BIG_ENDIAN);
break;
case 0x0D:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_database_identifier, tvb, offset, 16, ENC_NA);
break;
case 0x0E:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_vcard_selector_operator, tvb, offset, 1, ENC_NA);
break;
case 0x0F:
proto_tree_add_item(parameter_tree, hf_pbap_application_parameter_data_reset_new_missed_calls, tvb, offset, 1, ENC_NA);
break;
case 0x10:
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_pbap_application_parameter_data_supported_features, ett_btobex_parameter, hfx_pbap_application_parameter_data_supported_features, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
static gint required_length_map[] = {0, 2, 2, 1, -1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 2, 1, 1, 1, 1, 1, 1, -1};
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
map_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_id < (sizeof(required_length_map)/sizeof(gint)) &&
required_length_map[parameter_id] != -1 &&
required_length_map[parameter_id] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map[parameter_id], parameter_length);
} else switch (parameter_id) {
case 0x01:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_max_list_count, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_start_offset, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x03:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_message_type_reserved, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_message_type_mms, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_message_type_email, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_message_type_sms_cdma, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_message_type_sms_gsm, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_period_begin, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
case 0x05:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_period_end, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
case 0x06:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_read_status_reserved_6, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_read_status_get_read, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_read_status_get_unread, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_recipient, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
case 0x08:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_originator, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
case 0x09:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_priority_reserved_6, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_priority_get_high, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_filter_priority_non_high, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0A:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_attachment, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0B:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_transparent, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0C:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_retry, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0D:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_new_message, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0E:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_notification_status, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x0F:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_mas_instance_id, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x10:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_reserved, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_reply_to_addressing, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_protected, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_sent, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_read, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_priority, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_attachment_size, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_text, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_reception_status, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_size, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_type, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_recipient_addressing, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_recipient_name, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_sender_addressing, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_sender_name, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_datetime, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_parameter_mask_subject, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x11:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_folder_listing_size, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x12:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_messages_listing_size, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x13:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_subject_length, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x14:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_charset, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x15:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_fraction_request, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x16:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_fraction_deliver, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x17:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_status_indicator, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x18:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_reserved_7, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_status_value, tvb, offset, required_length_map[parameter_id], ENC_BIG_ENDIAN);
break;
case 0x19:
proto_tree_add_item(parameter_tree, hf_map_application_parameter_data_mse_time, tvb, offset, parameter_length, ENC_ASCII | ENC_NA);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_gpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
static gint required_length_map[] = {2, 2, 1, 1, 0, 2};
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
gpp_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_id >= 0x41 && (guint8)(parameter_id - 0x41) < (sizeof(required_length_map)/sizeof(gint)) &&
required_length_map[parameter_id - 0x41] != -1 &&
required_length_map[parameter_id - 0x41] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map[parameter_id - 0x41], parameter_length);
} else switch (parameter_id) {
case 0x41:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_max_list_count, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x42:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_list_start_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x43:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_reserved_7, tvb, offset, 1, ENC_NA);
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_notification_status, tvb, offset, 1, ENC_NA);
break;
case 0x44:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_instance_id, tvb, offset, 1, ENC_NA);
break;
case 0x46:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_listing_size, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static gint
dissect_btobex_application_parameter_ctn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *item;
proto_item *parameter_item;
proto_tree *parameter_tree;
guint8 parameter_id;
gint offset = 0;
gint parameters_length;
gint parameter_length;
static gint required_length_map[] = {0, 1, 1, 1, -1, -1, 4, 1, 1, 4, -1, -1, 1, 1, -1};
static gint required_length_map_gpp[] = {2, 2, 1, 1, -1, 2};
parameters_length = tvb_reported_length(tvb);
while (parameters_length > 0) {
parameter_id = tvb_get_guint8(tvb, offset);
parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(tree, hf_application_parameter, tvb, offset, parameter_length + 2,
"Parameter: %s", val_to_str_const(parameter_id,
ctn_application_parameters_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_application_parameters);
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
item = proto_tree_add_item(parameter_tree, hf_application_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (parameter_id < 0x41 && parameter_id < (sizeof(required_length_map)/sizeof(gint)) &&
required_length_map[parameter_id] != -1 &&
required_length_map[parameter_id] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map[parameter_id], parameter_length);
} else if (parameter_id >= 0x41 && (guint8)(parameter_id - 0x41) < (sizeof(required_length_map_gpp)/sizeof(gint)) &&
required_length_map[parameter_id - 0x41] != -1 &&
required_length_map[parameter_id - 0x41] != parameter_length) {
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
expert_add_info_format(pinfo, item, &ei_application_parameter_length_bad,
"According to the specification this parameter length should be %i, but there is %i",
required_length_map_gpp[parameter_id - 0x41], parameter_length);
} else switch (parameter_id) {
case 0x41:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_max_list_count, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x42:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_list_start_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x43:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_reserved_7, tvb, offset, 1, ENC_NA);
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_notification_status, tvb, offset, 1, ENC_NA);
break;
case 0x44:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_instance_id, tvb, offset, 1, ENC_NA);
break;
case 0x46:
proto_tree_add_item(parameter_tree, hf_gpp_application_parameter_data_listing_size, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x01:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_acoustic_alarm_status, tvb, offset, 1, ENC_NA);
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_attachment, tvb, offset, 1, ENC_NA);
break;
case 0x03:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_send, tvb, offset, 1, ENC_NA);
break;
case 0x04:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_filter_period_begin, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 0x05:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_filter_period_end, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 0x06:
proto_tree_add_bitmask(parameter_tree, tvb, offset, hf_ctn_application_parameter_data_parameter_mask, ett_btobex_filter, hfx_ctn_application_parameter_data_parameter_mask, ENC_BIG_ENDIAN);
break;
case 0x07:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_status_indicator, tvb, offset, 1, ENC_NA);
break;
case 0x08:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_status_value, tvb, offset, 1, ENC_NA);
break;
case 0x09:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_postpone_val, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x0A:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_email_uri, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 0x0B:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_cse_time, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 0x0C:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_recurrent, tvb, offset, 1, ENC_NA);
break;
case 0x0D:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_attach_id, tvb, offset, 1, ENC_NA);
break;
case 0x0E:
proto_tree_add_item(parameter_tree, hf_ctn_application_parameter_data_last_update, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
default:
proto_tree_add_item(parameter_tree, hf_application_parameter_data, tvb, offset, parameter_length, ENC_NA);
}
parameters_length -= 2 + parameter_length;
offset += parameter_length;
}
return offset;
}
static int
dissect_headers(proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo,
gint profile, obex_last_opcode_data_t *obex_last_opcode_data,
obex_proto_data_t *obex_proto_data)
{
proto_tree *hdrs_tree = NULL;
proto_tree *hdr_tree = NULL;
proto_item *hdr = NULL;
proto_item *handle_item;
tvbuff_t *next_tvb;
gint new_offset;
gint item_length = 0;
gint value_length = 0;
guint8 hdr_id, i;
guint32 value;
guint32 frame_number;
guint8 tag;
gchar *str = NULL;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_item *hdrs;
hdrs = proto_tree_add_item(tree, hf_headers, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
hdrs_tree = proto_item_add_subtree(hdrs, ett_btobex_hdrs);
}
else {
return offset;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
hdr_id = tvb_get_guint8(tvb, offset);
switch(0xC0 & hdr_id)
{
case 0x00:
item_length = tvb_get_ntohs(tvb, offset + 1);
value_length = item_length - 3;
break;
case 0x40:
item_length = tvb_get_ntohs(tvb, offset + 1);
value_length = item_length - 3;
break;
case 0x80:
item_length = 1 + 1;
value_length = 1;
break;
case 0xc0:
item_length = 1 + 4;
value_length = 4;
break;
}
hdr = proto_tree_add_none_format(hdrs_tree, hf_header, tvb, offset, item_length, "%s",
val_to_str_ext_const(hdr_id, &header_id_vals_ext, "Unknown"));
hdr_tree = proto_item_add_subtree(hdr, ett_btobex_hdr);
proto_tree_add_bitmask_with_flags(hdr_tree, tvb, offset, hf_hdr_id, ett_btobex_hdr_id, hfx_hdr_id, ENC_NA, BMT_NO_APPEND);
offset++;
switch(0xC0 & hdr_id)
{
case 0x00:
proto_tree_add_item(hdr_tree, hf_hdr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (hdr_id) {
case 0x01:
proto_tree_add_item(hdr_tree, hf_name, tvb, offset, value_length, ENC_UCS_2 | ENC_BIG_ENDIAN);
if (!pinfo->fd->flags.visited && obex_last_opcode_data) {
if (obex_last_opcode_data->code == BTOBEX_CODE_VALS_SET_PATH)
obex_last_opcode_data->data.set_data.name = tvb_get_string_enc(wmem_file_scope(), tvb, offset, value_length, ENC_UCS_2 | ENC_BIG_ENDIAN);
else if (obex_last_opcode_data->code == BTOBEX_CODE_VALS_GET || obex_last_opcode_data->code == BTOBEX_CODE_VALS_PUT)
obex_last_opcode_data->data.get_put.name = tvb_get_string_enc(wmem_file_scope(), tvb, offset, value_length, ENC_UCS_2 | ENC_BIG_ENDIAN);
}
break;
default:
proto_tree_add_item(hdr_tree, hf_hdr_val_unicode, tvb, offset, value_length, ENC_UCS_2 | ENC_BIG_ENDIAN);
}
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_UCS_2 | ENC_BIG_ENDIAN);
proto_item_append_text(hdr_tree, ": \"%s\"", str);
col_append_fstr(pinfo->cinfo, COL_INFO, " \"%s\"", str);
offset += value_length;
break;
case 0x40:
proto_tree_add_item(hdr_tree, hf_hdr_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (hdr_id) {
case 0x4c:
next_tvb = tvb_new_subset_length(tvb, offset, value_length);
if (!(new_offset = dissector_try_uint_new(btobex_profile, profile, next_tvb, pinfo, hdr_tree, TRUE, NULL))) {
new_offset = call_dissector(raw_application_parameters_handle, next_tvb, pinfo, hdr_tree);
}
offset += new_offset;
break;
case 0x4d:
while (value_length) {
guint8 parameter_id;
guint8 sub_parameter_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
parameter_id = tvb_get_guint8(tvb, offset);
sub_parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(hdr_tree, hf_authentication_parameter, tvb, offset,
2 + sub_parameter_length, "Tag: %s", val_to_str_const(parameter_id,
authentication_challenge_tag_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_authentication_parameters);
proto_tree_add_item(parameter_tree, hf_authentication_challenge_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(parameter_tree, hf_authentication_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag) {
case 0x00:
proto_tree_add_item(parameter_tree, hf_authentication_key, tvb, offset, 16, ENC_NA);
offset += 16;
break;
case 0x01:
proto_tree_add_item(parameter_tree, hf_authentication_option_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_authentication_option_read_only, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_authentication_option_user_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_authentication_info_charset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_authentication_info, tvb, offset, sub_parameter_length - 1, ENC_ASCII|ENC_NA);
offset += sub_parameter_length - 1;
break;
default:
proto_tree_add_item(parameter_tree, hf_authentication_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
value_length -= 2 + sub_parameter_length;
}
break;
case 0x4e:
while (value_length) {
guint8 parameter_id;
guint8 sub_parameter_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
parameter_id = tvb_get_guint8(tvb, offset);
sub_parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(hdr_tree, hf_authentication_parameter, tvb, offset,
2 + sub_parameter_length, "Tag: %s", val_to_str_const(parameter_id,
authentication_response_tag_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_authentication_parameters);
proto_tree_add_item(parameter_tree, hf_authentication_response_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(parameter_tree, hf_authentication_length, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_parameter_length = tvb_get_guint8(tvb, offset);
offset += 1;
switch (tag) {
case 0x00:
proto_tree_add_item(parameter_tree, hf_authentication_result_key, tvb, offset, 16, ENC_NA);
offset += 16;
break;
case 0x01:
proto_tree_add_item(parameter_tree, hf_authentication_user_id, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
break;
case 0x02:
proto_tree_add_item(parameter_tree, hf_authentication_key, tvb, offset, 16, ENC_NA);
offset += 16;
break;
default:
proto_tree_add_item(parameter_tree, hf_authentication_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
break;
}
value_length -= 2 + sub_parameter_length;
}
break;
case 0x42:
proto_tree_add_item(hdr_tree, hf_type, tvb, offset, value_length, ENC_ASCII | ENC_NA);
proto_item_append_text(hdr_tree, ": \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_ASCII));
if (!pinfo->fd->flags.visited && obex_last_opcode_data && (obex_last_opcode_data->code == BTOBEX_CODE_VALS_GET || obex_last_opcode_data->code == BTOBEX_CODE_VALS_PUT)) {
obex_last_opcode_data->data.get_put.type = tvb_get_string_enc(wmem_file_scope(), tvb, offset, value_length, ENC_ASCII | ENC_NA);
}
if (p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE) == NULL) {
guint8 *value_data;
value_data = tvb_get_string_enc(wmem_file_scope(), tvb, offset, value_length, ENC_ASCII | ENC_NA);
p_add_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE, value_data);
}
offset += value_length;
break;
case 0x44:
proto_tree_add_item(hdr_tree, hf_time_iso8601, tvb, offset, value_length, ENC_ASCII | ENC_NA);
proto_item_append_text(hdr_tree, ": \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_ASCII));
offset += value_length;
break;
case 0x48:
case 0x49:
proto_tree_add_item(hdr_tree, hf_hdr_val_byte_seq, tvb, offset, value_length, ENC_NA);
next_tvb = tvb_new_subset_length(tvb, offset, value_length);
if (value_length > 0 && obex_last_opcode_data &&
(obex_last_opcode_data->code == BTOBEX_CODE_VALS_GET || obex_last_opcode_data->code == BTOBEX_CODE_VALS_PUT) &&
p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE) == NULL) {
guint8 *value_data;
value_data = obex_last_opcode_data->data.get_put.type;
p_add_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_MEDIA_TYPE, value_data);
}
if (value_length > 0 && obex_last_opcode_data &&
(obex_last_opcode_data->code == BTOBEX_CODE_VALS_GET || obex_last_opcode_data->code == BTOBEX_CODE_VALS_PUT) &&
obex_last_opcode_data->data.get_put.type &&
dissector_try_string(media_type_dissector_table, obex_last_opcode_data->data.get_put.type, next_tvb, pinfo, tree, NULL) > 0) {
offset += value_length;
} else {
if (!tvb_strneql(tvb, offset, "<?xml", 5))
{
call_dissector(xml_handle, next_tvb, pinfo, tree);
} else if (is_ascii_str(tvb_get_ptr(tvb, offset, value_length), value_length)) {
proto_item_append_text(hdr_tree, ": \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_ASCII));
col_append_fstr(pinfo->cinfo, COL_INFO, " \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_ASCII));
}
offset += value_length;
}
break;
case 0x46:
case 0x4a:
handle_item = proto_tree_add_item(hdr_tree, hf_hdr_val_byte_seq, tvb, offset, value_length, ENC_NA);
if (value_length == 16) for (i = 0; target_vals[i].strptr != NULL; i++) {
if (tvb_memeql(tvb, offset, target_vals[i].value, target_vals[i].length) == 0) {
proto_item_append_text(handle_item, ": %s", target_vals[i].strptr);
proto_item_append_text(hdr_tree, ": %s", target_vals[i].strptr);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", target_vals[i].strptr);
if (!pinfo->fd->flags.visited) {
obex_profile_data_t *obex_profile_data;
wmem_tree_key_t key[6];
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &obex_proto_data->interface_id;
key[1].length = 1;
key[1].key = &obex_proto_data->adapter_id;
key[2].length = 1;
key[2].key = &obex_proto_data->chandle;
key[3].length = 1;
key[3].key = &obex_proto_data->channel;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
obex_profile_data = wmem_new(wmem_file_scope(), obex_profile_data_t);
obex_profile_data->interface_id = obex_proto_data->interface_id;
obex_profile_data->adapter_id = obex_proto_data->adapter_id;
obex_profile_data->chandle = obex_proto_data->chandle;
obex_profile_data->channel = obex_proto_data->channel;
obex_profile_data->profile = target_to_profile[i];
wmem_tree_insert32_array(obex_profile, key, obex_profile_data);
}
}
}
offset += value_length;
break;
case 0x47: {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(http_handle, next_tvb, pinfo, hdr_tree);
}
break;
case 0x50:
if (value_length == 2) {
proto_tree_add_item(hdr_tree, hf_wan_uuid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
proto_tree_add_item(hdr_tree, hf_hdr_val_byte_seq, tvb, offset, value_length, ENC_NA);
offset += value_length;
}
break;
case 0x51:
proto_tree_add_item(hdr_tree, hf_object_class, tvb, offset, value_length, ENC_ASCII | ENC_NA);
proto_item_append_text(hdr_tree, ": \"%s\"", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, value_length, ENC_ASCII));
offset += value_length;
break;
case 0x52:
while (value_length) {
guint8 parameter_id;
guint8 sub_parameter_length;
proto_item *parameter_item;
proto_tree *parameter_tree;
parameter_id = tvb_get_guint8(tvb, offset);
sub_parameter_length = tvb_get_guint8(tvb, offset + 1);
parameter_item = proto_tree_add_none_format(hdr_tree, hf_session_parameter, tvb, offset,
2 + sub_parameter_length, "Tag: %s", val_to_str_const(parameter_id,
session_tag_vals, "Unknown"));
parameter_tree = proto_item_add_subtree(parameter_item, ett_btobex_session_parameters);
proto_tree_add_item(parameter_tree, hf_session_parameter_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
tag = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(parameter_tree, hf_session_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_parameter_length = tvb_get_guint8(tvb, offset);
offset += 1;
switch (tag) {
case 0x00:
if (sub_parameter_length == 6) {
offset = dissect_bd_addr(hf_sender_bd_addr, pinfo, parameter_tree, tvb, offset, FALSE, obex_proto_data->interface_id, obex_proto_data->adapter_id, NULL);
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
case 0x01:
if (sub_parameter_length >= 4 && sub_parameter_length <= 16) {
proto_tree_add_item(parameter_tree, hf_session_parameter_nonce, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
case 0x02:
if (sub_parameter_length == 16) {
proto_tree_add_item(parameter_tree, hf_session_parameter_session_id, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
case 0x03:
if (sub_parameter_length == 1) {
proto_tree_add_item(parameter_tree, hf_session_parameter_next_sequence_number, tvb, offset, 1, ENC_NA);
offset += 1;
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
case 0x04:
if (sub_parameter_length == 4) {
proto_tree_add_item(parameter_tree, hf_session_parameter_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
case 0x05:
if (sub_parameter_length == 1) {
proto_tree_add_item(parameter_tree, hf_session_parameter_opcode, tvb, offset, 1, ENC_NA);
offset += 1;
} else {
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
}
break;
default:
proto_tree_add_item(parameter_tree, hf_session_parameter_data, tvb, offset, sub_parameter_length, ENC_NA);
offset += sub_parameter_length;
break;
}
value_length -= 2 + sub_parameter_length;
}
break;
default:
proto_tree_add_item(hdr_tree, hf_hdr_val_byte_seq, tvb, offset, value_length, ENC_NA);
offset += value_length;
}
break;
case 0x80:
value = tvb_get_guint8(tvb, offset);
switch (hdr_id) {
case 0x94:
proto_tree_add_item(hdr_tree, hf_hdr_val_action, tvb, offset, 1, ENC_NA);
proto_item_append_text(hdr_tree, ": %s", val_to_str_const(value, action_vals, "Unknown"));
break;
case 0x97:
proto_tree_add_item(hdr_tree, hf_hdr_val_single_response_mode, tvb, offset, 1, ENC_NA);
proto_item_append_text(hdr_tree, ": %s", val_to_str_const(value, single_response_mode_vals, "Unknown"));
break;
case 0x98:
proto_tree_add_item(hdr_tree, hf_hdr_val_single_response_mode_parameter, tvb, offset, 1, ENC_NA);
proto_item_append_text(hdr_tree, ": %s", val_to_str_const(value, single_response_mode_parameter_vals, "Unknown"));
break;
case 0x93:
default:
proto_tree_add_item(hdr_tree, hf_hdr_val_byte, tvb, offset, 1, ENC_NA);
proto_item_append_text(hdr_tree, ": %i", value);
}
offset += 1;
break;
case 0xC0:
switch (hdr_id) {
case 0xC0:
proto_item_append_text(hdr_tree, ": %i", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_count, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0xC3:
proto_item_append_text(hdr_tree, ": %i", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_data_length, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0xCB:
proto_item_append_text(hdr_tree, ": %i", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_connection_id, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0xC4:
case 0xCF:
case 0xD6:
default:
proto_item_append_text(hdr_tree, ": %i", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(hdr_tree, hf_hdr_val_long, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
break;
default:
break;
}
}
return offset;
}
static gint
dissect_btobex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *main_item;
proto_tree *main_tree;
proto_item *sub_item;
fragment_head *frag_msg = NULL;
gboolean save_fragmented;
gboolean complete;
tvbuff_t* new_tvb = NULL;
tvbuff_t* next_tvb = NULL;
gint offset = 0;
gint profile = PROFILE_UNKNOWN;
const gchar *path = path_unknown;
obex_profile_data_t *obex_profile_data;
wmem_tree_key_t key[6];
guint32 frame_number;
obex_last_opcode_data_t *obex_last_opcode_data;
obex_path_data_t *obex_path_data;
guint32 length;
guint8 *profile_data;
dissector_handle_t current_handle;
dissector_handle_t default_handle;
gint previous_proto;
obex_proto_data_t obex_proto_data;
previous_proto = (GPOINTER_TO_INT(wmem_list_frame_data(wmem_list_frame_prev(wmem_list_tail(pinfo->layers)))));
if (previous_proto == proto_btl2cap) {
btl2cap_data_t *l2cap_data;
l2cap_data = (btl2cap_data_t *) data;
obex_proto_data.interface_id = l2cap_data->interface_id;
obex_proto_data.adapter_id = l2cap_data->adapter_id;
obex_proto_data.chandle = l2cap_data->chandle;
obex_proto_data.channel = l2cap_data->cid;
} else if (previous_proto == proto_btrfcomm) {
btrfcomm_data_t *rfcomm_data;
rfcomm_data = (btrfcomm_data_t *) data;
obex_proto_data.interface_id = rfcomm_data->interface_id;
obex_proto_data.adapter_id = rfcomm_data->adapter_id;
obex_proto_data.chandle = rfcomm_data->chandle;
obex_proto_data.channel = rfcomm_data->dlci >> 1;
} else {
obex_proto_data.interface_id = HCI_INTERFACE_DEFAULT;
obex_proto_data.adapter_id = HCI_ADAPTER_DEFAULT;
obex_proto_data.chandle = 0;
obex_proto_data.channel = 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OBEX");
main_item = proto_tree_add_item(tree, proto_btobex, tvb, 0, tvb_captured_length(tvb), ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_btobex);
save_fragmented = pinfo->fragmented;
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &obex_proto_data.interface_id;
key[1].length = 1;
key[1].key = &obex_proto_data.adapter_id;
key[2].length = 1;
key[2].key = &obex_proto_data.chandle;
key[3].length = 1;
key[3].key = &obex_proto_data.channel;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
profile_data = (guint8 *) p_get_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_BTOBEX_PROFILE);
if (profile_data == NULL) {
obex_profile_data = (obex_profile_data_t *)wmem_tree_lookup32_array_le(obex_profile, key);
if (obex_profile_data && obex_profile_data->interface_id == obex_proto_data.interface_id &&
obex_profile_data->adapter_id == obex_proto_data.adapter_id &&
obex_profile_data->chandle == obex_proto_data.chandle &&
obex_profile_data->channel == obex_proto_data.channel) {
profile = obex_profile_data->profile;
}
profile_data = wmem_new(wmem_file_scope(), guint8);
*profile_data = profile;
p_add_proto_data(pinfo->pool, pinfo, proto_btobex, PROTO_DATA_BTOBEX_PROFILE, profile_data);
}
obex_path_data = (obex_path_data_t *)wmem_tree_lookup32_array_le(obex_path, key);
if (obex_path_data && obex_path_data->interface_id == obex_proto_data.interface_id &&
obex_path_data->adapter_id == obex_proto_data.adapter_id &&
obex_path_data->chandle == obex_proto_data.chandle &&
obex_path_data->channel == obex_proto_data.channel) {
path = obex_path_data->path;
}
sub_item = proto_tree_add_uint(main_tree, hf_profile, tvb, 0, 0, profile);
PROTO_ITEM_SET_GENERATED(sub_item);
if (path) {
sub_item = proto_tree_add_string(main_tree, hf_current_path, tvb, 0, 0, path);
PROTO_ITEM_SET_GENERATED(sub_item);
}
current_handle = dissector_get_uint_handle(btobex_profile, profile);
default_handle = dissector_get_default_uint_handle("btobex.profile", profile);
if (current_handle != default_handle) {
expert_add_info_format(pinfo, main_item, &ei_decoded_as_profile, "Decoded As %s", dissector_handle_get_long_name(current_handle));
}
complete = FALSE;
if (tvb_captured_length(tvb) == tvb_reported_length(tvb)) {
frag_msg = fragment_get_reassembled_id(&btobex_reassembly_table, pinfo, pinfo->p2p_dir);
if (frag_msg && pinfo->fd->num != frag_msg->reassembled_in) {
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, main_tree);
} else if (frag_msg && pinfo->fd->num == frag_msg->reassembled_in) {
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, main_tree);
} else {
frag_msg = fragment_get(&btobex_reassembly_table, pinfo, pinfo->p2p_dir, NULL);
if (frag_msg) {
while (frag_msg->next) {
frag_msg = frag_msg->next;
}
frag_msg = fragment_add_check(&btobex_reassembly_table,
tvb, 0, pinfo, pinfo->p2p_dir, NULL,
frag_msg->offset + frag_msg->len, tvb_reported_length(tvb),
((frag_msg->offset + frag_msg->len + tvb_reported_length(tvb)) <
fragment_get_tot_len(&btobex_reassembly_table, pinfo, pinfo->p2p_dir, NULL)) ? TRUE : FALSE);
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, main_tree);
pinfo->fragmented = TRUE;
} else {
if (tvb_reported_length(tvb) < 3) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s OBEX packet too short",
(pinfo->p2p_dir==P2P_DIR_SENT) ? "Sent" : "Rcvd");
call_dissector(data_handle, tvb, pinfo, main_tree);
return tvb_reported_length(tvb);
} else if (tvb_reported_length(tvb) >= 3 && tvb_reported_length(tvb) < tvb_get_ntohs(tvb, offset+1)) {
frag_msg = fragment_add_check(&btobex_reassembly_table,
tvb, 0, pinfo, pinfo->p2p_dir, NULL,
0, tvb_reported_length(tvb), TRUE);
fragment_set_tot_len(&btobex_reassembly_table,
pinfo, pinfo->p2p_dir, NULL,
tvb_get_ntohs(tvb, offset + 1));
new_tvb = process_reassembled_data(tvb, 0, pinfo,
"Reassembled Obex packet", frag_msg, &btobex_frag_items, NULL, main_tree);
pinfo->fragmented = TRUE;
} else if (tvb_reported_length(tvb) == tvb_get_ntohs(tvb, offset+1)) {
complete = TRUE;
pinfo->fragmented = FALSE;
}
}
}
}
if (new_tvb) {
next_tvb = new_tvb;
complete = TRUE;
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (complete) {
guint8 code;
guint8 final_flag;
code = tvb_get_guint8(next_tvb, offset) & BTOBEX_CODE_VALS_MASK;
final_flag = tvb_get_guint8(next_tvb, offset) & 0x80;
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
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(code, &code_vals_ext, "Unknown"));
if (code < BTOBEX_CODE_VALS_CONTINUE || code == BTOBEX_CODE_VALS_ABORT) {
proto_tree_add_item(main_tree, hf_opcode, next_tvb, offset, 1, ENC_BIG_ENDIAN);
if (!pinfo->fd->flags.visited &&
(pinfo->p2p_dir == P2P_DIR_SENT ||
pinfo->p2p_dir == P2P_DIR_RECV)) {
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &obex_proto_data.interface_id;
key[1].length = 1;
key[1].key = &obex_proto_data.adapter_id;
key[2].length = 1;
key[2].key = &obex_proto_data.chandle;
key[3].length = 1;
key[3].key = &obex_proto_data.channel;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
obex_last_opcode_data = wmem_new0(wmem_file_scope(), obex_last_opcode_data_t);
obex_last_opcode_data->interface_id = obex_proto_data.interface_id;
obex_last_opcode_data->adapter_id = obex_proto_data.adapter_id;
obex_last_opcode_data->chandle = obex_proto_data.chandle;
obex_last_opcode_data->channel = obex_proto_data.channel;
obex_last_opcode_data->code = code;
obex_last_opcode_data->final_flag = final_flag;
obex_last_opcode_data->request_in_frame = frame_number;
obex_last_opcode_data->response_in_frame = 0;
wmem_tree_insert32_array(obex_last_opcode, key, obex_last_opcode_data);
}
} else {
proto_tree_add_item(main_tree, hf_response_code, next_tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(main_tree, hf_final_flag, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(main_tree, hf_length, next_tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb, offset) - 3;
offset += 2;
frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &obex_proto_data.interface_id;
key[1].length = 1;
key[1].key = &obex_proto_data.adapter_id;
key[2].length = 1;
key[2].key = &obex_proto_data.chandle;
key[3].length = 1;
key[3].key = &obex_proto_data.channel;
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
obex_last_opcode_data = (obex_last_opcode_data_t *)wmem_tree_lookup32_array_le(obex_last_opcode, key);
if (obex_last_opcode_data && obex_last_opcode_data->interface_id == obex_proto_data.interface_id &&
obex_last_opcode_data->adapter_id == obex_proto_data.adapter_id &&
obex_last_opcode_data->chandle == obex_proto_data.chandle &&
obex_last_opcode_data->channel == obex_proto_data.channel) {
if (obex_last_opcode_data->request_in_frame > 0 && obex_last_opcode_data->request_in_frame != pinfo->fd->num) {
sub_item = proto_tree_add_uint(main_tree, hf_request_in_frame, next_tvb, 0, 0, obex_last_opcode_data->request_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
if (!pinfo->fd->flags.visited && obex_last_opcode_data->response_in_frame == 0 && obex_last_opcode_data->request_in_frame < pinfo->fd->num) {
obex_last_opcode_data->response_in_frame = pinfo->fd->num;
}
if (obex_last_opcode_data->response_in_frame > 0 && obex_last_opcode_data->response_in_frame != pinfo->fd->num) {
sub_item = proto_tree_add_uint(main_tree, hf_response_in_frame, next_tvb, 0, 0, obex_last_opcode_data->response_in_frame);
PROTO_ITEM_SET_GENERATED(sub_item);
}
}
switch(code)
{
case BTOBEX_CODE_VALS_CONNECT:
proto_tree_add_item(main_tree, hf_version, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(main_tree, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(main_tree, hf_max_pkt_len, next_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case BTOBEX_CODE_VALS_PUT:
case BTOBEX_CODE_VALS_GET:
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", (final_flag == 0x80) ? "final" : "continue");
break;
case BTOBEX_CODE_VALS_SET_PATH:
proto_tree_add_item(main_tree, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(main_tree, hf_set_path_flags_0, next_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(main_tree, hf_set_path_flags_1, next_tvb, offset, 1, ENC_BIG_ENDIAN);
if (!pinfo->fd->flags.visited && obex_last_opcode_data) {
obex_last_opcode_data->data.set_data.go_up = tvb_get_guint8(tvb, offset) & 0x01;
obex_last_opcode_data->data.set_data.name = NULL;
}
offset++;
proto_tree_add_item(main_tree, hf_constants, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case BTOBEX_CODE_VALS_DISCONNECT:
case BTOBEX_CODE_VALS_ABORT:
break;
default:
if (length == 0 && tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_expert(main_tree, pinfo, &ei_unexpected_data, tvb, offset, tvb_reported_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
break;
} else if (length == 0) break;
if (obex_last_opcode_data && obex_last_opcode_data->code == BTOBEX_CODE_VALS_CONNECT) {
proto_tree_add_item(main_tree, hf_version, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(main_tree, hf_flags, next_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(main_tree, hf_max_pkt_len, next_tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (!pinfo->fd->flags.visited)
save_path(pinfo, path, "", FALSE, &obex_proto_data);
}
break;
}
dissect_headers(main_tree, next_tvb, offset, pinfo, profile, obex_last_opcode_data, &obex_proto_data);
if (!pinfo->fd->flags.visited &&
obex_last_opcode_data &&
obex_last_opcode_data->data.set_data.name &&
obex_last_opcode_data->code == BTOBEX_CODE_VALS_SET_PATH &&
code == BTOBEX_CODE_VALS_SUCCESS) {
save_path(pinfo, path, obex_last_opcode_data->data.set_data.name, obex_last_opcode_data->data.set_data.go_up, &obex_proto_data);
}
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s OBEX fragment",
(pinfo->p2p_dir==P2P_DIR_SENT) ? "Sent" : "Rcvd");
call_dissector(data_handle, next_tvb, pinfo, main_tree);
offset = tvb_reported_length(tvb);
}
pinfo->fragmented = save_fragmented;
return offset;
}
void
proto_register_btobex(void)
{
module_t *module;
expert_module_t *expert_btobex;
int proto_raw;
int proto_bpp;
int proto_bip;
int proto_map;
int proto_gpp;
int proto_ctn;
int proto_pbap;
static hf_register_info hf[] = {
{ &hf_opcode,
{ "Opcode", "btobex.opcode",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &code_vals_ext, BTOBEX_CODE_VALS_MASK,
"Request Opcode", HFILL}
},
{ &hf_response_code,
{ "Response Code", "btobex.resp_code",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &code_vals_ext, BTOBEX_CODE_VALS_MASK,
NULL, HFILL}
},
{ &hf_final_flag,
{ "Final Flag", "btobex.final_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}
},
{ &hf_length,
{ "Packet Length", "btobex.pkt_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_version,
{ "Version", "btobex.version",
FT_UINT8, BASE_HEX, VALS(version_vals), 0x00,
"Obex Protocol Version", HFILL}
},
{ &hf_flags,
{ "Flags", "btobex.flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_constants,
{ "Constants", "btobex.constants",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_max_pkt_len,
{ "Max. Packet Length", "btobex.max_pkt_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_set_path_flags_0,
{ "Go back one folder (../) first", "btobex.set_path_flags_0",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_set_path_flags_1,
{ "Do not create folder, if not existing", "btobex.set_path_flags_1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_headers,
{ "Headers", "btobex.headers",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_header,
{ "Header", "btobex.header",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_hdr_id,
{ "Header Id", "btobex.header.id",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &header_id_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_hdr_id_encoding,
{ "Encoding", "btobex.header.id.encoding",
FT_UINT8, BASE_HEX, VALS(header_id_encoding_vals), 0xC0,
NULL, HFILL}
},
{ &hf_hdr_id_meaning,
{ "Meaning", "btobex.header.id.meaning",
FT_UINT8, BASE_HEX, VALS(header_id_meaning_vals), 0x3F,
NULL, HFILL}
},
{ &hf_hdr_length,
{ "Length", "btobex.header.length",
FT_UINT16, BASE_DEC, NULL, 0,
"Header Length", HFILL}
},
{ &hf_hdr_val_unicode,
{ "Value", "btobex.header.value.unicode",
FT_STRING, BASE_NONE, NULL, 0,
"Unicode Value", HFILL }
},
{ &hf_hdr_val_byte_seq,
{ "Value", "btobex.header.value.byte_sequence",
FT_BYTES, BASE_NONE, NULL, 0,
"Byte Sequence Value", HFILL}
},
{ &hf_hdr_val_byte,
{ "Value", "btobex.header.value.byte",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
"Byte Value", HFILL}
},
{ &hf_hdr_val_long,
{ "Value", "btobex.header.value.long",
FT_UINT32, BASE_DEC, NULL, 0,
"4-byte Value", HFILL}
},
{ &hf_count,
{ "Count", "btobex.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_data_length,
{ "Length", "btobex.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_connection_id,
{ "Connection ID", "btobex.connection_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter,
{ "Session Parameter", "btobex.session",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_session_parameter_data,
{ "Parameter Value", "btobex.session.value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_tag,
{ "Tag", "btobex.session.tag",
FT_UINT8, BASE_HEX, VALS(session_tag_vals), 0x00,
NULL, HFILL}
},
{ &hf_session_parameter_length,
{ "Length", "btobex.session.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_nonce,
{ "Nonce", "btobex.session.nonce",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_session_id,
{ "Session ID", "btobex.session.session_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_next_sequence_number,
{ "Next Sequence Number", "btobex.session.next_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_timeout,
{ "Timeout", "btobex.session.timeout",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_session_parameter_opcode,
{ "Opcode", "btobex.session.opcode",
FT_UINT8, BASE_HEX, VALS(session_opcode_vals), 0,
NULL, HFILL}
},
{ &hf_authentication_parameter,
{ "Autentication Parameter", "btobex.authentication",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_authentication_parameter_data,
{ "Parameter Value", "btobex.authentication.value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_authentication_challenge_tag,
{ "Tag", "btobex.authentication.challenge_tag",
FT_UINT8, BASE_HEX, VALS(authentication_challenge_tag_vals), 0x00,
NULL, HFILL}
},
{ &hf_authentication_response_tag,
{ "Tag", "btobex.authentication.response_tag",
FT_UINT8, BASE_HEX, VALS(authentication_response_tag_vals), 0x00,
NULL, HFILL}
},
{ &hf_authentication_length,
{ "Length", "btobex.authentication.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_authentication_key,
{ "Key", "btobex.authentication.key",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_authentication_result_key,
{ "Result Key", "btobex.authentication.result_key",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_authentication_user_id,
{ "User Id", "btobex.authentication.user_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_authentication_option_reserved,
{ "Reserved", "btobex.authentication.option.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL}
},
{ &hf_authentication_option_read_only,
{ "Read Only", "btobex.authentication.option.read_only",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_authentication_option_user_id,
{ "User ID", "btobex.authentication.option.user_id",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_authentication_info_charset,
{ "Charset", "btobex.authentication.info.charset",
FT_UINT8, BASE_HEX, VALS(info_charset_vals), 0,
NULL, HFILL}
},
{ &hf_authentication_info,
{ "Info", "btobex.authentication.info",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_application_parameter,
{ "Parameter", "btobex.parameter",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_application_parameter_id,
{ "Parameter Id", "btobex.parameter.id",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_application_parameter_length,
{ "Parameter Length", "btobex.parameter.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_application_parameter_data,
{ "Parameter Value", "btobex.parameter.value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_bpp_application_parameter_id,
{ "Parameter Id", "btobex.parameter.id",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bpp_application_parameters_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_bpp_application_parameter_data_offset,
{ "Offset", "btobex.parameter.value.offset",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
"The byte offset into the image or file.", HFILL}
},
{ &hf_bpp_application_parameter_data_count,
{ "Count", "btobex.parameter.value.count",
FT_INT32, BASE_DEC, NULL, 0,
"The number of bytes of the image or file to be sent.", HFILL}
},
{ &hf_bpp_application_parameter_data_job_id,
{ "Job ID", "btobex.parameter.value.job_id",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
"The job identifier of the print job.", HFILL}
},
{ &hf_bpp_application_parameter_data_file_size,
{ "File Size", "btobex.parameter.value.file_size",
FT_INT32, BASE_DEC, NULL, 0,
"The size (in bytes) of object or file.", HFILL}
},
{ &hf_bip_application_parameter_id,
{ "Parameter Id", "btobex.parameter.id",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bip_application_parameters_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_bip_application_parameter_data_number_of_returned_handles,
{ "Number of Returned Handles", "btobex.parameter.value.number_of_returned_handles",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_list_start_offset,
{ "List Start Offset", "btobex.parameter.value.list_start_offset",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_latest_captured_images,
{ "Latest Captured Images", "btobex.parameter.value.latest_captured_images",
FT_BOOLEAN, 8, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_partial_file_length,
{ "Partial File Length", "btobex.parameter.value.partial_file_length",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_partial_file_start_offset,
{ "Partial File Start Offset", "btobex.parameter.value.partial_file_start_offset",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_total_file_size,
{ "Total File Size", "btobex.parameter.value.total_file_size",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_end_flag,
{ "End Flag", "btobex.parameter.value.end_flag",
FT_BOOLEAN, 8, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_remote_display,
{ "Remote Display", "btobex.parameter.value.remote_display",
FT_UINT8, BASE_HEX, VALS(bip_remote_display_vals), 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_service_id,
{ "Service ID", "btobex.parameter.value.service_id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &bluetooth_uuid_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bip_application_parameter_data_store_flag,
{ "Store Flag", "btobex.parameter.value.store_flag",
FT_BOOLEAN, 8, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_id,
{ "Parameter Id", "btobex.parameter.id",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &pbap_application_parameters_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_order,
{ "Max List Count", "btobex.parameter.value.order",
FT_UINT8, BASE_HEX, VALS(pbap_order_vals), 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_search_value,
{ "Search Value", "btobex.parameter.value.search_value",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_search_attribute,
{ "Search Attribute", "btobex.parameter.value.search_attribute",
FT_UINT8, BASE_HEX, VALS(pbap_search_attribute_vals), 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_max_list_count,
{ "Max List Count", "btobex.parameter.value.max_list_count",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_list_start_offset,
{ "List Start Offset", "btobex.parameter.value.list_start_offset",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter,
{ "Filter", "btobex.parameter.value.filter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_vcard_selector,
{ "vCard Selector", "btobex.parameter.value.filter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_version,
{ "vCard Version", "btobex.parameter.value.filter.version",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_fn,
{ "Formatted Name", "btobex.parameter.value.filter.fn",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_n,
{ "Structured Presentation of Name", "btobex.parameter.value.filter.n",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_photo,
{ "Associated Image or Photo", "btobex.parameter.value.filter.photo",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_birthday,
{ "Birthday", "btobex.parameter.value.filter.birthday",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_adr,
{ "Delivery Address", "btobex.parameter.value.filter.adr",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_label,
{ "Delivery", "btobex.parameter.value.filter.label",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_tel,
{ "Telephone Number", "btobex.parameter.value.filter.tel",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_email,
{ "Electronic Mail Address", "btobex.parameter.value.filter.email",
FT_BOOLEAN, 32, NULL, 0x00000100,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_mailer,
{ "Electronic Mail", "btobex.parameter.value.filter.mailer",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_time_zone,
{ "Time Zone", "btobex.parameter.value.filter.time_zone",
FT_BOOLEAN, 32, NULL, 0x00000400,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_geographic_position,
{ "Geographic Position", "btobex.parameter.value.filter.geographic_position",
FT_BOOLEAN, 32, NULL, 0x00000800,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_title,
{ "Job", "btobex.parameter.value.filter.title",
FT_BOOLEAN, 32, NULL, 0x00001000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_role,
{ "Role within the Organization", "btobex.parameter.value.filter.role",
FT_BOOLEAN, 32, NULL, 0x00002000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_logo,
{ "Organization Logo", "btobex.parameter.value.filter.logo",
FT_BOOLEAN, 32, NULL, 0x00004000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_agent,
{ "vCard of Person Representing", "btobex.parameter.value.filter.agent",
FT_BOOLEAN, 32, NULL, 0x00008000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_name_of_organization,
{ "Name of Organization", "btobex.parameter.value.filter.name_of_organization",
FT_BOOLEAN, 32, NULL, 0x00010000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_comments,
{ "Comments", "btobex.parameter.value.filter.comments",
FT_BOOLEAN, 32, NULL, 0x00020000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_revision,
{ "Revision", "btobex.parameter.value.filter.revision",
FT_BOOLEAN, 32, NULL, 0x00040000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_pronunciation_of_name,
{ "Pronunciation of Name", "btobex.parameter.value.filter.pronunciation_of_name",
FT_BOOLEAN, 32, NULL, 0x00080000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_url,
{ "Uniform Resource Locator", "btobex.parameter.value.filter.url",
FT_BOOLEAN, 32, NULL, 0x00100000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_uid,
{ "Unique ID", "btobex.parameter.value.filter.uid",
FT_BOOLEAN, 32, NULL, 0x00200000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_key,
{ "Public Encryption Key", "btobex.parameter.value.filter.key",
FT_BOOLEAN, 32, NULL, 0x00400000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_nickname,
{ "Nickname", "btobex.parameter.value.filter.nickname",
FT_BOOLEAN, 32, NULL, 0x00800000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_categories,
{ "Categories", "btobex.parameter.value.filter.categories",
FT_BOOLEAN, 32, NULL, 0x01000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_product_id,
{ "Product ID", "btobex.parameter.value.filter.product_id",
FT_BOOLEAN, 32, NULL, 0x02000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_class,
{ "Class Information", "btobex.parameter.value.filter.class",
FT_BOOLEAN, 32, NULL, 0x04000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_sort_string,
{ "String Used For Sorting Operations", "btobex.parameter.value.filter.sort_string",
FT_BOOLEAN, 32, NULL, 0x08000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_timestamp,
{ "Timestamp", "btobex.parameter.value.filter.timestamp",
FT_BOOLEAN, 32, NULL, 0x10000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_reserved_29_31,
{ "Reserved", "btobex.parameter.value.filter.reserved_29_31",
FT_UINT32, BASE_HEX, NULL, 0xE0000000,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_reserved_32_38,
{ "Reserved", "btobex.parameter.value.filter.reserved_32_38",
FT_UINT32, BASE_HEX, NULL, 0x0000007F,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_proprietary_filter,
{ "Proprietary Filter", "btobex.parameter.value.filter.proprietary_filter",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_filter_reserved_for_proprietary_filter_usage,
{ "Reserved for Proprietary Filter Usage", "btobex.parameter.value.filter.reserved_for_proprietary_filter_usage",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFF00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_format,
{ "Format", "btobex.parameter.value.format",
FT_UINT8, BASE_HEX, VALS(pbap_format_vals), 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_phonebook_size,
{ "Phonebook Size", "btobex.parameter.value.phonebook_size",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_new_missed_calls,
{ "New Missed Calls", "btobex.parameter.value.new_missed_calls",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_primary_version_counter,
{ "Primary Version Counter", "btobex.parameter.value.primary_version_counter",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_secondary_version_counter,
{ "Secondary Version Counter", "btobex.parameter.value.secondary_version_counter",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_database_identifier,
{ "Database Identifier", "btobex.parameter.value.database_identifier",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_vcard_selector_operator,
{ "vCard Selector Operator", "btobex.parameter.value.vcard_selector_operator",
FT_UINT8, BASE_HEX, VALS(pbap_application_parameter_data_vcard_selector_operator_vals), 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_reset_new_missed_calls,
{ "vCard Selector Operator", "btobex.parameter.value.reset_new_missed_calls",
FT_UINT8, BASE_HEX, VALS(pbap_application_parameter_data_reset_new_missed_calls_vals), 0x00,
NULL, HFILL}
},
{ &hf_pbap_application_parameter_data_supported_features,
{ "Supported Features", "btobex.parameter.supported_features",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_reserved,
{ "Reserved", "btobex.parameter.supported_features.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFC00,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_default_contact_image_format,
{ "Default Contact Image Format", "btobex.parameter.supported_features.default_contact_image_format",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_contact_referencing,
{ "Contact Referencing", "btobex.parameter.supported_features.contact_referencing",
FT_BOOLEAN, 32, NULL, 0x00000100,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_x_bt_uid_vcard_property,
{ "X-BT-UID vCard Property", "btobex.parameter.supported_features.x_bt_uid_vcard_property",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_x_bt_uci_vcard_property,
{ "X-BT-UCI vCard Property", "btobex.parameter.supported_features.x_bt_uci_vcard_property",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_enhanced_missed_calls,
{ "Enhanced Missed Calls", "btobex.parameter.supported_features.enhanced_missed_calls",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_vcard_selecting,
{ "vCard Selecting", "btobex.parameter.supported_features.vcard_selecting",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_folder_version_counters,
{ "Folder Version Counters", "btobex.parameter.supported_features.folder_version_counters",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_database_identifier,
{ "Database Identifier", "btobex.parameter.supported_features.database_identifier",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_browsing,
{ "Browsing", "btobex.parameter.supported_features.browsing",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL }
},
{ &hf_pbap_application_parameter_data_supported_features_download,
{ "Download", "btobex.parameter.supported_features.download",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_map_application_parameter_id,
{ "Parameter Id", "btobex.parameter.id",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &map_application_parameters_vals_ext, 0x00,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_max_list_count,
{ "Max List Count", "btobex.parameter.value.max_list_count",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_start_offset,
{ "Start Offset", "btobex.parameter.value.start_offset",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_message_type_reserved,
{ "Reserved", "btobex.parameter.value.filter_message_type.reserved",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_message_type_mms,
{ "MMS", "btobex.parameter.value.filter_message_type.mms",
FT_BOOLEAN, 8, NULL, 0x08,
"True to filter out, False to listing this type", HFILL}
},
{ &hf_map_application_parameter_data_filter_message_type_email,
{ "EMAIL", "btobex.parameter.value.filter_message_type.sms_email",
FT_BOOLEAN, 8, NULL, 0x04,
"True to filter out, False to listing this type", HFILL}
},
{ &hf_map_application_parameter_data_filter_message_type_sms_cdma,
{ "SMS_CDMA", "btobex.parameter.value.filter_message_type.sms_cdma",
FT_BOOLEAN, 8, NULL, 0x02,
"True to filter out, False to listing this type", HFILL}
},
{ &hf_map_application_parameter_data_filter_message_type_sms_gsm,
{ "SMS_GSM", "btobex.parameter.value.filter_message_type.sms_gsm",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_period_begin,
{ "Filter Period Begin", "btobex.parameter.value.filter_period_begin",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_period_end,
{ "Filter Period End", "btobex.parameter.value.filter_period_end",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_read_status_reserved_6,
{ "Filter Read Status: Reserved", "btobex.parameter.value.filter_read_status.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_read_status_get_read,
{ "Filter Read Status: Get Read", "btobex.parameter.value.filter_read_status.get_read",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_read_status_get_unread,
{ "Filter Read Status: Get Unread", "btobex.parameter.value.filter_read_status.get_unread",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_recipient,
{ "Filter Recipient", "btobex.parameter.value.filter_recipient",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_originator,
{ "Filter Originator", "btobex.parameter.value.filter_originator",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_priority_reserved_6,
{ "Filter Priority: Reserved", "btobex.parameter.value.filter_priority.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_priority_get_high,
{ "Filter Priority: Get Read", "btobex.parameter.value.filter_priority.get_high",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_filter_priority_non_high,
{ "Filter Priority: Get Non High", "btobex.parameter.value.filter_priority.non_high",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_reserved_7,
{ "Reserved", "btobex.parameter.value.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFE,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_attachment,
{ "Attachment", "btobex.parameter.value.attachment",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_transparent,
{ "Transparent", "btobex.parameter.value.transparent",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_retry,
{ "Retry", "btobex.parameter.value.retry",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_new_message,
{ "New Message", "btobex.parameter.value.new_message",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_notification_status,
{ "Notification Status", "btobex.parameter.value.notification_status",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_mas_instance_id,
{ "MAS Instance ID", "btobex.parameter.value.mas_instance_id",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_reserved,
{ "Parameter Mask: Reserved", "btobex.parameter.value.parameter_mask.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_reply_to_addressing,
{ "Parameter Mask: Reply to Addressing", "btobex.parameter.value.parameter_mask.reply_to_addressing",
FT_BOOLEAN, 32, NULL, 0x8000,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_protected,
{ "Parameter Mask: Protected", "btobex.parameter.value.parameter_mask.protected",
FT_BOOLEAN, 32, NULL, 0x4000,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_sent,
{ "Parameter Mask: Sent", "btobex.parameter.value.parameter_mask.sent",
FT_BOOLEAN, 32, NULL, 0x2000,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_read,
{ "Parameter Mask: Read", "btobex.parameter.value.parameter_mask.read",
FT_BOOLEAN, 32, NULL, 0x1000,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_priority,
{ "Parameter Mask: Priority", "btobex.parameter.value.parameter_mask.priority",
FT_BOOLEAN, 32, NULL, 0x0800,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_attachment_size,
{ "Parameter Mask: Attachment Size", "btobex.parameter.value.parameter_mask.attachment_size",
FT_BOOLEAN, 32, NULL, 0x0400,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_text,
{ "Parameter Mask: Text", "btobex.parameter.value.parameter_mask.text",
FT_BOOLEAN, 32, NULL, 0x0200,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_reception_status,
{ "Parameter Mask: Reception Status", "btobex.parameter.value.parameter_mask.reception_status",
FT_BOOLEAN, 32, NULL, 0x0100,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_size,
{ "Parameter Mask: Size", "btobex.parameter.value.parameter_mask.size",
FT_BOOLEAN, 32, NULL, 0x0080,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_type,
{ "Parameter Mask: Type", "btobex.parameter.value.parameter_mask.type",
FT_BOOLEAN, 32, NULL, 0x0040,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_recipient_addressing,
{ "Parameter Mask: Recipient Addressing", "btobex.parameter.value.parameter_mask.recipient_addressing",
FT_BOOLEAN, 32, NULL, 0x0020,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_recipient_name,
{ "Parameter Mask: Recipient Name", "btobex.parameter.value.parameter_mask.recipient_name",
FT_BOOLEAN, 32, NULL, 0x0010,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_sender_addressing,
{ "Parameter Mask: Sender Addressing", "btobex.parameter.value.parameter_mask.sender_addressing",
FT_BOOLEAN, 32, NULL, 0x0008,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_sender_name,
{ "Parameter Mask: Sender Name", "btobex.parameter.value.parameter_mask.sender_name",
FT_BOOLEAN, 32, NULL, 0x0004,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_datetime,
{ "Parameter Mask: Datetime", "btobex.parameter.value.parameter_mask.datetime",
FT_BOOLEAN, 32, NULL, 0x0002,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_parameter_mask_subject,
{ "Parameter Mask: Subject", "btobex.parameter.value.parameter_mask.subject",
FT_BOOLEAN, 32, NULL, 0x0001,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_folder_listing_size,
{ "Folder Listing Size", "btobex.parameter.value.folder_listing_size",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_messages_listing_size,
{ "Messages Listing Size", "btobex.parameter.value.messages_listing_size",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_subject_length,
{ "Subject Length", "btobex.parameter.value.subject_length",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_charset,
{ "Charset", "btobex.parameter.value.charset",
FT_UINT8, BASE_HEX, VALS(map_charset_vals), 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_fraction_request,
{ "Fraction Request", "btobex.parameter.value.fraction_request",
FT_UINT8, BASE_HEX, VALS(map_fraction_request_vals), 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_fraction_deliver,
{ "Fraction Deliver", "btobex.parameter.value.fraction_deliver",
FT_UINT8, BASE_HEX, VALS(map_fraction_deliver_vals), 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_status_indicator,
{ "Status Indicator", "btobex.parameter.value.status_indicator",
FT_UINT8, BASE_HEX, VALS(map_status_indicator_vals), 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_status_value,
{ "Status Value", "btobex.parameter.value.status_value",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_map_application_parameter_data_mse_time,
{ "MSE Time", "btobex.parameter.value.mse_time",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_id,
{ "Parameter Id", "btobex.parameter.gpp.id",
FT_UINT8, BASE_HEX, VALS(gpp_application_parameters_vals), 0x00,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_max_list_count,
{ "Max List Count", "btobex.parameter.gpp.value.max_list_count",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_list_start_offset,
{ "List Start Offset", "btobex.parameter.gpp.value.list_start_offset",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_reserved_7,
{ "Reserved", "btobex.parameter.gpp.value.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFE,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_notification_status,
{ "Notification Status", "btobex.parameter.gpp.value.notification_status",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_instance_id,
{ "Instance ID", "btobex.parameter.gpp.value.instance_id",
FT_UINT8, BASE_DEC_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_gpp_application_parameter_data_listing_size,
{ "Listing Size", "btobex.parameter.gpp.value.listing_size",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_id,
{ "Parameter Id", "btobex.parameter.ctn.id",
FT_UINT8, BASE_HEX, VALS(ctn_application_parameters_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_acoustic_alarm_status,
{ "Acoustic Alarm Status", "btobex.parameter.ctn.acoustic_alarm_status",
FT_UINT8, BASE_HEX, VALS(off_on_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_attachment,
{ "Attachment", "btobex.parameter.ctn.attachment",
FT_UINT8, BASE_HEX, VALS(ctn_application_parameter_data_attachment_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_send,
{ "Attachment", "btobex.parameter.ctn.attachment",
FT_UINT8, BASE_HEX, VALS(no_yes_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_filter_period_begin,
{ "Filter Period Begin", "btobex.parameter.ctn.filter_period_begin",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_filter_period_end,
{ "Filter Period End", "btobex.parameter.ctn.filter_period_end",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask,
{ "Parameter Mask", "btobex.parameter.ctn.parameter_mask",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_reserved,
{ "Reserved", "btobex.parameter.ctn.parameter_mask.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFC00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_recurrent,
{ "Recurrent", "btobex.parameter.ctn.parameter_mask.recurrent",
FT_UINT32, BASE_HEX, NULL, 0x00000200,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_send_status,
{ "Send Status", "btobex.parameter.ctn.parameter_mask.send_status",
FT_UINT32, BASE_HEX, NULL, 0x00000100,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_alarm_status,
{ "Alarm Status", "btobex.parameter.ctn.parameter_mask.",
FT_UINT32, BASE_HEX, NULL, 0x00000080,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_pstatus,
{ "pStatus", "btobex.parameter.ctn.parameter_mask.pstatus",
FT_UINT32, BASE_HEX, NULL, 0x00000040,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_priority,
{ "Priority", "btobex.parameter.ctn.parameter_mask.priority",
FT_UINT32, BASE_HEX, NULL, 0x00000020,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_originator_address,
{ "Originator Address", "btobex.parameter.ctn.parameter_mask.originator_address",
FT_UINT32, BASE_HEX, NULL, 0x00000010,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_originator_name,
{ "Originator Name", "btobex.parameter.ctn.parameter_mask.originator_name",
FT_UINT32, BASE_HEX, NULL, 0x00000008,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_end_time,
{ "End Time", "btobex.parameter.ctn.parameter_mask.end_time",
FT_UINT32, BASE_HEX, NULL, 0x00000004,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_summary,
{ "Summary", "btobex.parameter.ctn.parameter_mask.summary",
FT_UINT32, BASE_HEX, NULL, 0x00000002,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_parameter_mask_attachment,
{ "Attachment", "btobex.parameter.ctn.parameter_mask.attachment",
FT_UINT32, BASE_HEX, NULL, 0x00000001,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_status_indicator,
{ "Status Indicator", "btobex.parameter.ctn.status_indicator",
FT_UINT8, BASE_HEX, VALS(ctn_application_parameter_data_status_indicator_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_status_value,
{ "Status Value", "btobex.parameter.ctn.status_value",
FT_UINT8, BASE_HEX, VALS(ctn_application_parameter_data_status_value_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_postpone_val,
{ "Postpone Val", "btobex.parameter.ctn.postpone_val",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_email_uri,
{ "Email URI", "btobex.parameter.ctn.email_uri",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_cse_time,
{ "CSE Time", "btobex.parameter.ctn.cse_time",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_recurrent,
{ "Recurrent", "btobex.parameter.ctn.recurrent",
FT_UINT8, BASE_HEX, VALS(no_yes_vals), 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_attach_id,
{ "Attach ID", "btobex.parameter.ctn.attach_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{ &hf_ctn_application_parameter_data_last_update,
{ "Last Update", "btobex.parameter.ctn.last_update",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL}
},
{ &hf_btobex_fragment_overlap,
{ "Fragment overlap", "btobex.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }
},
{ &hf_btobex_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "btobex.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{ &hf_btobex_fragment_multiple_tails,
{ "Multiple tail fragments found", "btobex.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{ &hf_btobex_fragment_too_long_fragment,
{ "Fragment too long", "btobex.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }
},
{ &hf_btobex_fragment_error,
{ "Defragmentation error", "btobex.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{ &hf_btobex_fragment_count,
{ "Fragment count", "btobex.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btobex_fragment,
{ "OBEX Fragment", "btobex.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"btobex Fragment", HFILL }
},
{ &hf_btobex_fragments,
{ "OBEX Fragments", "btobex.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
"btobex Fragments", HFILL }
},
{ &hf_btobex_reassembled_in,
{ "Reassembled OBEX in frame", "btobex.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This OBEX frame is reassembled in this frame", HFILL }
},
{ &hf_btobex_reassembled_length,
{ "Reassembled OBEX length", "btobex.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
},
{ &hf_profile,
{ "Profile", "btobex.profile", FT_UINT32, BASE_DEC | BASE_EXT_STRING, &profile_vals_ext, 0x0,
"Blutooth Profile used in this OBEX session", HFILL }
},
{ &hf_type,
{ "Type", "btobex.type", FT_STRINGZ, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_object_class,
{ "Object Class", "btobex.object_class", FT_STRINGZ, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_time_iso8601,
{ "Time", "btobex.time", FT_STRINGZ, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdr_val_action,
{ "Action", "btobex.action", FT_UINT8, BASE_DEC, VALS(action_vals), 0x0,
NULL, HFILL }
},
{ &hf_hdr_val_single_response_mode,
{ "Single Response Mode", "btobex.single_response_mode", FT_UINT8, BASE_DEC, VALS(single_response_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_hdr_val_single_response_mode_parameter,
{ "Single Response Mode Parameter", "btobex.single_response_mode_parameter", FT_UINT8, BASE_DEC, VALS(single_response_mode_parameter_vals), 0x0,
NULL, HFILL }
},
{ &hf_wan_uuid,
{ "WAN UUID", "btobex.wan_uuid",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_sender_bd_addr,
{ "Sender Address", "btobex.sender_bd_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_name,
{ "Name", "btobex.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_current_path,
{ "Current Path", "btobex.current_path",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_request_in_frame,
{ "Request in Frame", "btobex.request_in_frame", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0,
NULL, HFILL}
},
{ &hf_response_in_frame,
{ "Response in Frame", "btobex.response_in_frame", FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0x0,
NULL, HFILL}
}
};
static gint *ett[] = {
&ett_btobex,
&ett_btobex_hdrs,
&ett_btobex_hdr,
&ett_btobex_hdr_id,
&ett_btobex_filter,
&ett_btobex_parameter,
&ett_btobex_fragment,
&ett_btobex_fragments,
&ett_btobex_session_parameters,
&ett_btobex_application_parameters,
&ett_btobex_authentication_parameters
};
static ei_register_info ei[] = {
{ &ei_application_parameter_length_bad, { "btobex.parameter.length.bad", PI_PROTOCOL, PI_WARN, "Parameter length bad", EXPFILL }},
{ &ei_unexpected_data, { "btobex.expert.unexpected_data", PI_PROTOCOL, PI_WARN, "Unexpected data", EXPFILL }},
{ &ei_decoded_as_profile, { "btobex.expert.decoded_as.profile", PI_PROTOCOL, PI_NOTE, "Decoded As", EXPFILL }},
};
static build_valid_func btobex_profile_da_build_value[1] = {btobex_profile_value};
static decode_as_value_t btobex_profile_da_values = {btobex_profile_prompt, 1, btobex_profile_da_build_value};
static decode_as_t btobex_profile_da = {"btobex", "OBEX Profile", "btobex.profile", 1, 0, &btobex_profile_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
static build_valid_func media_type_da_build_value[1] = {media_type_value};
static decode_as_value_t media_type_da_values = {media_type_prompt, 1, media_type_da_build_value};
static decode_as_t media_type_da = {"btobex", "Media Type", "media_type",
1, 0, &media_type_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
obex_path = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
obex_profile = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
obex_last_opcode = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
proto_btobex = proto_register_protocol("Bluetooth OBEX Protocol", "BT OBEX", "btobex");
btobex_handle = new_register_dissector("btobex", dissect_btobex, proto_btobex);
btobex_profile = register_dissector_table("btobex.profile", "BTOBEX Profile", FT_UINT8, BASE_DEC);
proto_register_field_array(proto_btobex, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_btobex = expert_register_protocol(proto_btobex);
expert_register_field_array(expert_btobex, ei, array_length(ei));
register_init_routine(&defragment_init);
register_cleanup_routine(&defragment_cleanup);
register_decode_as(&btobex_profile_da);
proto_raw = proto_register_protocol("BT OBEX Raw Application Parameters", "Raw Application Parameters", "btobex.parameter.raw");
raw_application_parameters_handle = new_register_dissector("btobex.parameter.raw", dissect_btobex_application_parameter_raw, proto_raw);
proto_bpp = proto_register_protocol("BT OBEX BPP Application Parameters", "BPP Application Parameters", "btobex.parameter.bpp");
bpp_application_parameters_handle = new_register_dissector("btobex.parameter.bpp", dissect_btobex_application_parameter_bpp, proto_bpp);
proto_bip = proto_register_protocol("BT OBEX BIP Application Parameters", "BIP Application Parameters", "btobex.parameter.bip");
bip_application_parameters_handle = new_register_dissector("btobex.parameter.bip", dissect_btobex_application_parameter_bip, proto_bip);
proto_map = proto_register_protocol("BT OBEX MAP Application Parameters", "MAP Application Parameters", "btobex.parameter.map");
map_application_parameters_handle = new_register_dissector("btobex.parameter.map", dissect_btobex_application_parameter_map, proto_map);
proto_gpp = proto_register_protocol("BT OBEX GPP Application Parameters", "GPP Application Parameters", "btobex.parameter.gpp");
gpp_application_parameters_handle = new_register_dissector("btobex.parameter.gpp", dissect_btobex_application_parameter_gpp, proto_gpp);
proto_ctn = proto_register_protocol("BT OBEX CTN Application Parameters", "CTN Application Parameters", "btobex.parameter.ctn");
ctn_application_parameters_handle = new_register_dissector("btobex.parameter.ctn", dissect_btobex_application_parameter_ctn, proto_ctn);
proto_pbap = proto_register_protocol("BT OBEX PBAP Application Parameters", "PBAP Application Parameters", "btobex.parameter.pbap");
pbap_application_parameters_handle = new_register_dissector("btobex.parameter.pbap", dissect_btobex_application_parameter_pbap, proto_pbap);
register_decode_as(&media_type_da);
module = prefs_register_protocol(proto_btobex, NULL);
prefs_register_static_text_preference(module, "obex.version",
"Bluetooth Protocol OBEX support profiles: BIP 1.2, BPP 1.2, CTN 1.0, FTP 1.3, GOEP 1.3, GPP 1.0, MAP 1.2, OPP 1.2, PBAP 1.2, SYNCH 1.2",
"Version of profiles supported by this dissector.");
}
void
proto_reg_handoff_btobex(void)
{
dissector_add_string("bluetooth.uuid", "1104", btobex_handle);
dissector_add_string("bluetooth.uuid", "1105", btobex_handle);
dissector_add_string("bluetooth.uuid", "1106", btobex_handle);
dissector_add_string("bluetooth.uuid", "1107", btobex_handle);
dissector_add_string("bluetooth.uuid", "1118", btobex_handle);
dissector_add_string("bluetooth.uuid", "1119", btobex_handle);
dissector_add_string("bluetooth.uuid", "111a", btobex_handle);
dissector_add_string("bluetooth.uuid", "111b", btobex_handle);
dissector_add_string("bluetooth.uuid", "111c", btobex_handle);
dissector_add_string("bluetooth.uuid", "111d", btobex_handle);
dissector_add_string("bluetooth.uuid", "1120", btobex_handle);
dissector_add_string("bluetooth.uuid", "1121", btobex_handle);
dissector_add_string("bluetooth.uuid", "1122", btobex_handle);
dissector_add_string("bluetooth.uuid", "1123", btobex_handle);
dissector_add_string("bluetooth.uuid", "112e", btobex_handle);
dissector_add_string("bluetooth.uuid", "112f", btobex_handle);
dissector_add_string("bluetooth.uuid", "1130", btobex_handle);
dissector_add_string("bluetooth.uuid", "1132", btobex_handle);
dissector_add_string("bluetooth.uuid", "1133", btobex_handle);
dissector_add_string("bluetooth.uuid", "1134", btobex_handle);
http_handle = find_dissector("http");
xml_handle = find_dissector("xml");
data_handle = find_dissector("data");
data_text_lines_handle = find_dissector("data-text-lines");
dissector_add_uint("btobex.profile", PROFILE_UNKNOWN, raw_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_BPP, bpp_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_BIP, bip_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_CTN, ctn_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_GPP, gpp_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_MAP, map_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_PBAP, pbap_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_OPP, raw_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_FTP, raw_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_SYNCML, raw_application_parameters_handle);
dissector_add_uint("btobex.profile", PROFILE_SYNC, raw_application_parameters_handle);
dissector_add_for_decode_as("btrfcomm.dlci", btobex_handle);
dissector_add_for_decode_as("btl2cap.psm", btobex_handle);
dissector_add_for_decode_as("btl2cap.cid", btobex_handle);
dissector_add_string("media_type", "x-bt/phonebook", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/vcard", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/vcard-listing", xml_handle);
dissector_add_string("media_type", "x-bt/message", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/messageStatus", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/MAP-messageUpdate", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/MAP-NotificationRegistration", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/MASInstanceInformation", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/MAP-msg-listing", xml_handle);
dissector_add_string("media_type", "x-bt/MAP-event-report", xml_handle);
dissector_add_string("media_type", "x-obex/folder-listing", xml_handle);
dissector_add_string("media_type", "x-bt/CTN-EventReport", xml_handle);
dissector_add_string("media_type", "x-bt/CTN-Listing", xml_handle);
dissector_add_string("media_type", "x-bt/CTN-NotificationRegistration", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/Calendar", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/CalendarStatus", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/CTN-forward", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/InstanceDescription", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/Update", data_text_lines_handle);
dissector_add_string("media_type", "text/x-ref-simple", data_text_lines_handle);
dissector_add_string("media_type", "text/x-ref-list", data_text_lines_handle);
dissector_add_string("media_type", "x-obex/RUI", data_text_lines_handle);
dissector_add_string("media_type", "x-obex/bt-SOAP", xml_handle);
dissector_add_string("media_type", "x-bt/img-listing", xml_handle);
dissector_add_string("media_type", "x-bt/img-properties", xml_handle);
dissector_add_string("media_type", "x-bt/img-capabilities", xml_handle);
dissector_add_string("media_type", "x-bt/img-print", data_text_lines_handle);
dissector_add_string("media_type", "x-bt/img-img", data_handle);
dissector_add_string("media_type", "x-bt/img-thm", data_handle);
dissector_add_string("media_type", "x-bt/img-attachment", data_handle);
dissector_add_string("media_type", "x-bt/img-display", data_handle);
dissector_add_string("media_type", "x-bt/img-partial", data_handle);
dissector_add_string("media_type", "x-bt/img-archive", data_handle);
dissector_add_string("media_type", "x-bt/img-status", data_handle);
dissector_add_string("media_type", "x-bt/img-monitoring", data_handle);
media_type_dissector_table = find_dissector_table("media_type");
}
