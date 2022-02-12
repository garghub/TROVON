static void
mbim_rssi_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-113 or less dBm (0)");
} else if (val < 31) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d dBm (%u)", -113 + 2*val, val);
} else if (val == 31) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-51 or greater dBm (31)");
} else if (val == 99) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (99)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_degrees_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f Celcius Degrees (%u)", (float)v/10.0, v);
}
static void
mbim_rscp_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-120 or less dBm (0)");
} else if (val < 96) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d dBm (%u)", -120 + val, val);
} else if (val == 96) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-24 or greater dBm (96)");
} else if (val == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_ecno_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-24 or less dBm (0)");
} else if (val < 49) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f dBm (%u)", -24 + ((float)val/2), val);
} else if (val == 49) {
g_snprintf(s, ITEM_LABEL_LENGTH, "0.5 or greater dBm (49)");
} else if (val == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_rsrq_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-19.5 or less dBm (0)");
} else if (val < 34) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f dBm (%u)", -19.5 + ((float)val/2), val);
} else if (val == 34) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-2.5 or greater dBm (34)");
} else if (val == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_rsrp_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-140 or less dBm (0)");
} else if (val < 97) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d dBm (%u)", -140 + val, val);
} else if (val == 97) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-43 or greater dBm (97)");
} else if (val == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_rssnr_fmt(gchar *s, guint32 val)
{
if (val == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-5 or less dB (0)");
} else if (val < 35) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d dB (%u)", -5 + val, val);
} else if (val == 35) {
g_snprintf(s, ITEM_LABEL_LENGTH, "30 or greater dB (35)");
} else if (val == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Unknown or undetectable (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value (%u)", val);
}
}
static void
mbim_projection_table_coeff_fmt(gchar *s, guint32 val)
{
gint32 coeff = (gint32)val;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.3f (%d)", ((float)coeff)/1000, coeff);
}
static guint8
mbim_dissect_service_id_uuid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint hf,
gint *offset, struct mbim_uuid_ext **uuid_ext_info)
{
e_guid_t uuid;
guint i;
guint32 uuid_ext[4];
tvb_get_ntohguid(tvb, *offset, &uuid);
for (i = 0; i < UUID_MAX; i++) {
if (memcmp(&uuid, &(mbim_uuid_service_id_vals[i].uuid), sizeof(e_guid_t)) == 0) {
break;
}
}
if ((i == UUID_MAX) && mbim_uuid_ext_hash && uuid_ext_info) {
uuid_ext[0] = tvb_get_ntohl(tvb, *offset);
uuid_ext[1] = tvb_get_ntohl(tvb, *offset + 4);
uuid_ext[2] = tvb_get_ntohl(tvb, *offset + 8);
uuid_ext[3] = tvb_get_ntohl(tvb, *offset + 12);
*uuid_ext_info = (struct mbim_uuid_ext *)wmem_map_lookup(mbim_uuid_ext_hash, uuid_ext);
if (*uuid_ext_info) {
proto_tree_add_guid_format_value(tree, hf, tvb, *offset, 16, &uuid, "%s (%s)",
(*uuid_ext_info)->uuid_name, guid_to_str(wmem_packet_scope(), &uuid));
*offset += 16;
return UUID_EXT_IDX;
}
}
proto_tree_add_guid_format_value(tree, hf, tvb, *offset, 16, &uuid, "%s (%s)",
val_to_str_ext_const(i, &mbim_service_id_vals_ext, "Unknown"),
guid_to_str(wmem_packet_scope(), &uuid));
*offset += 16;
return i;
}
static guint32
mbim_dissect_cid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset, guint8 uuid_idx,
struct mbim_uuid_ext *uuid_ext_info)
{
guint32 cid;
cid = tvb_get_letohl(tvb, *offset);
if (uuid_idx < UUID_MAX) {
proto_tree_add_uint(tree, *mbim_uuid_info[uuid_idx].hf_entry, tvb, *offset, 4, cid);
if (mbim_uuid_info[uuid_idx].cid_list_ext) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_ext_const(cid, mbim_uuid_info[uuid_idx].cid_list_ext, "Unknown"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", val_to_str_const(cid, mbim_uuid_info[uuid_idx].cid_list, "Unknown"));
}
} else if (uuid_idx == UUID_EXT_IDX) {
const gchar* cid_string = val_to_str_const(cid, uuid_ext_info->uuid_cid_list, "Unknown");
proto_tree_add_uint_format_value(tree, hf_mbim_cid, tvb, *offset, 4, cid, "%s (%u)", cid_string , cid);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s", cid_string);
} else {
proto_tree_add_uint(tree, hf_mbim_cid, tvb, *offset, 4, cid);
col_append_str(pinfo->cinfo, COL_INFO, ": Unknown");
}
*offset += 4;
return cid;
}
static void
mbim_dissect_device_caps_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
gint base_offset;
guint32 custom_class_offset, custom_class_size, device_id_offset, device_id_size,
fw_info_offset, fw_info_size, hw_info_offset, hw_info_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_device_caps_info_device_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_cellular_class, tvb, offset, 4,
ENC_LITTLE_ENDIAN, &mbim_conv->cellular_class);
offset += 4;
proto_tree_add_item(tree, hf_mbim_device_caps_info_voice_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_device_caps_info_sim_class, ett_mbim_bitmap,
mbim_device_caps_info_sim_class_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_device_caps_info_data_class, ett_mbim_bitmap,
mbim_data_class_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_device_caps_info_sms_caps, ett_mbim_bitmap,
mbim_device_caps_info_sms_caps_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_device_caps_info_control_caps, ett_mbim_bitmap,
mbim_device_caps_info_control_caps_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_device_caps_info_max_sessions, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_custom_data_class_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &custom_class_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_custom_data_class_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &custom_class_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_device_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &device_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_device_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &device_id_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_fw_info_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &fw_info_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_fw_info_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &fw_info_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_hw_info_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &hw_info_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_caps_info_hw_info_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &hw_info_size);
if (custom_class_offset && custom_class_size) {
it = proto_tree_add_item(tree, hf_mbim_device_caps_info_custom_data_class, tvb, base_offset + custom_class_offset,
custom_class_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (custom_class_size > 22) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (device_id_offset && device_id_size) {
it = proto_tree_add_item(tree, hf_mbim_device_caps_info_device_id, tvb, base_offset + device_id_offset,
device_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if ((mbim_conv->cellular_class == MBIM_CELLULAR_CLASS_GSM) && (device_id_size > 30)) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
} else if (device_id_size > 36) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (fw_info_offset && fw_info_size) {
it = proto_tree_add_item(tree, hf_mbim_device_caps_info_fw_info, tvb, base_offset + fw_info_offset,
fw_info_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (fw_info_size > 60) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (hw_info_offset && hw_info_size) {
it = proto_tree_add_item(tree, hf_mbim_device_caps_info_hw_info, tvb, base_offset + hw_info_offset,
hw_info_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (hw_info_size > 60) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_subscriber_ready_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
proto_tree *subtree;
gint base_offset;
guint32 i, subscriber_id_offset, subscriber_id_size, sim_icc_id_offset, sim_icc_id_size, elem_count;
proto_item *it;
wmem_array_t *pair_list = NULL;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_subscr_ready_status_ready_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_subscr_ready_status_susbcr_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &subscriber_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_subscr_ready_status_susbcr_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &subscriber_id_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_subscr_ready_status_sim_icc_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sim_icc_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_subscr_ready_status_sim_icc_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sim_icc_id_size);
offset += 4;
proto_tree_add_item(tree, hf_mbim_subscr_ready_status_ready_info, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_subscr_ready_status_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Telephone Numbers Ref List");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_subscr_ready_status_tel_nb_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_subscr_ready_status_tel_nb_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
}
if (subscriber_id_offset && subscriber_id_size) {
it = proto_tree_add_item(tree, hf_mbim_subscr_ready_status_susbcr_id, tvb, base_offset + subscriber_id_offset,
subscriber_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if ((mbim_conv->cellular_class == MBIM_CELLULAR_CLASS_CDMA) && (subscriber_id_size > 20)) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
} else if (subscriber_id_size > 30) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (sim_icc_id_offset && sim_icc_id_size) {
it = proto_tree_add_item(tree, hf_mbim_subscr_ready_status_sim_icc_id, tvb, base_offset + sim_icc_id_offset,
sim_icc_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (sim_icc_id_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
it = proto_tree_add_item(tree, hf_mbim_subscr_ready_status_tel_nb, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (p_pair_list_item->size > 44) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
}
static void
mbim_dissect_set_pin(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 pin_offset, pin_size, new_pin_offset, new_pin_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_set_pin_pin_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_pin_pin_pin_operation, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_pin_pin_pin_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pin_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_pin_pin_pin_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pin_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_pin_new_pin_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &new_pin_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_pin_new_pin_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &new_pin_size);
if (pin_offset && pin_size) {
it = proto_tree_add_item(tree, hf_mbim_set_pin_pin, tvb, base_offset + pin_offset,
pin_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (pin_size > 32) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (new_pin_offset && new_pin_size) {
it = proto_tree_add_item(tree, hf_mbim_set_pin_new_pin, tvb, base_offset + new_pin_offset,
new_pin_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (new_pin_size > 32) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_pin_list_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
const char *pin_list[10] = { "PIN 1", "PIN 2", "Device SIM PIN", "Device First SIM PIN", "Network PIN",
"Network Subset PIN", "Service Provider PIN", "Corporate PIN", "Subsidy Lock",
"Custom"};
guint i;
guint32 length;
proto_tree *subtree;
for (i = 0; i < 10; i++) {
subtree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_mbim_pin, NULL, pin_list[i]);
proto_tree_add_item(subtree, hf_mbim_pin_list_pin_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_pin_list_pin_format, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
length = tvb_get_letohl(tvb, offset);
if (length == 0xffffffff) {
proto_tree_add_uint_format_value(subtree, hf_mbim_pin_list_pin_length_min, tvb, offset, 4,
length, "Not available (0xffffffff)");
} else {
proto_tree_add_uint(subtree, hf_mbim_pin_list_pin_length_min, tvb, offset, 4, length);
}
offset += 4;
length = tvb_get_letohl(tvb, offset);
if (length == 0xffffffff) {
proto_tree_add_uint_format_value(subtree, hf_mbim_pin_list_pin_length_max, tvb, offset, 4,
length, "Not available (0xffffffff)");
} else {
proto_tree_add_uint(subtree, hf_mbim_pin_list_pin_length_max, tvb, offset, 4, length);
}
offset += 4;
}
}
static void
mbim_dissect_provider(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 provider_id_offset, provider_id_size, provider_name_offset, provider_name_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_provider_provider_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_provider_provider_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_size);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_provider_state, ett_mbim_bitmap,
mbim_provider_state_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_provider_provider_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_provider_provider_name_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_size);
offset += 4;
proto_tree_add_item (tree, hf_mbim_provider_cellular_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_mbim_provider_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_mbim_provider_error_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (provider_id_offset && provider_id_size) {
it = proto_tree_add_item(tree, hf_mbim_provider_provider_id, tvb, base_offset + provider_id_offset,
provider_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_id_size > 12) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (provider_name_offset && provider_name_size) {
it = proto_tree_add_item(tree, hf_mbim_provider_provider_name, tvb, base_offset + provider_name_offset,
provider_name_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_name_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_providers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, elem_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_providers_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Providers Ref List");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_providers_provider_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_providers_provider_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset, p_pair_list_item->size,
ett_mbim_pair_list, NULL, "Provider #%u", i+1);
mbim_dissect_provider(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_set_register_state(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 provider_id_offset, provider_id_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_register_state_provider_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_register_state_provider_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_size);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_register_state_register_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_register_state_data_class, ett_mbim_bitmap,
mbim_data_class_fields, ENC_LITTLE_ENDIAN);
if (provider_id_offset && provider_id_size) {
it = proto_tree_add_item(tree, hf_mbim_set_register_state_provider_id, tvb, base_offset + provider_id_offset,
provider_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_id_size > 12) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_registration_state_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 provider_id_offset, provider_id_size, provider_name_offset, provider_name_size,
roaming_text_offset, roaming_text_size, nw_error;
proto_item *it;
base_offset = offset;
nw_error = tvb_get_letohl(tvb, offset);
if (nw_error == 0) {
proto_tree_add_uint_format_value(tree, hf_mbim_registration_state_info_nw_error, tvb, offset, 4, nw_error, "Success (0)");
} else {
proto_tree_add_uint(tree, hf_mbim_registration_state_info_nw_error, tvb, offset, 4, nw_error);
}
offset += 4;
proto_tree_add_item(tree, hf_mbim_registration_state_info_register_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_registration_state_info_register_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_registration_state_info_available_data_classes, ett_mbim_bitmap,
mbim_data_class_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_registration_state_info_current_cellular_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_provider_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_provider_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_provider_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_provider_name_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_roaming_text_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &roaming_text_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_registration_state_info_roaming_text_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &roaming_text_size);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_registration_state_info_registration_flags, ett_mbim_bitmap,
mbim_registration_state_info_registration_flags_fields, ENC_LITTLE_ENDIAN);
if (provider_id_offset && provider_id_size) {
it = proto_tree_add_item(tree, hf_mbim_registration_state_info_provider_id, tvb, base_offset + provider_id_offset,
provider_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_id_size > 12) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (provider_name_offset && provider_name_size) {
it = proto_tree_add_item(tree, hf_mbim_registration_state_info_provider_name, tvb, base_offset + provider_name_offset,
provider_name_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_name_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (roaming_text_offset && roaming_text_size) {
it = proto_tree_add_item(tree, hf_mbim_registration_state_info_roaming_text, tvb, base_offset + roaming_text_offset,
roaming_text_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (roaming_text_size > 126) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_packet_service_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint32 nw_error;
nw_error = tvb_get_letohl(tvb, offset);
if (nw_error == 0) {
proto_tree_add_uint_format_value(tree, hf_mbim_packet_service_info_nw_error, tvb, offset, 4, nw_error, "Success (0)");
} else {
proto_tree_add_uint(tree, hf_mbim_packet_service_info_nw_error, tvb, offset, 4, nw_error);
}
offset += 4;
proto_tree_add_item(tree, hf_mbim_packet_service_info_packet_service_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_packet_service_info_highest_available_data_class, ett_mbim_bitmap,
mbim_data_class_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_packet_service_info_uplink_speed, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_packet_service_info_downlink_speed, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_set_signal_state(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint32 error_rate_threshold;
proto_tree_add_item(tree, hf_mbim_set_signal_state_signal_strength_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_signal_state_rssi_threshold, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
error_rate_threshold = tvb_get_letohl(tvb, offset);
if (error_rate_threshold == 0xffffffff) {
proto_tree_add_uint_format_value(tree, hf_mbim_set_signal_state_error_rate_threshold, tvb, offset, 4,
error_rate_threshold, "No report (0xffffffff)");
} else {
proto_tree_add_item(tree, hf_mbim_set_signal_state_error_rate_threshold, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
static void
mbim_dissect_signal_state_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint32 error_rate_threshold;
proto_tree_add_item(tree, hf_mbim_signal_state_info_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_signal_state_info_error_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_signal_state_info_signal_strength_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_signal_state_info_rssi_threshold, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
error_rate_threshold = tvb_get_letohl(tvb, offset);
if (error_rate_threshold == 0xffffffff) {
proto_tree_add_uint_format_value(tree, hf_mbim_signal_state_info_error_rate_threshold, tvb, offset, 4,
error_rate_threshold, "No report (0xffffffff)");
} else {
proto_tree_add_item(tree, hf_mbim_signal_state_info_error_rate_threshold, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
static guint8
mbim_dissect_context_type_uuid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint *offset)
{
e_guid_t uuid;
guint i;
tvb_get_ntohguid(tvb, *offset, &uuid);
for (i = 0; i < array_length(mbim_uuid_context_type_vals); i++) {
if (memcmp(&uuid, &(mbim_uuid_context_type_vals[i].uuid), sizeof(e_guid_t)) == 0) {
break;
}
}
proto_tree_add_guid_format_value(tree, hf_mbim_context_type, tvb, *offset, 16, &uuid, "%s (%s)",
val_to_str_const(i, mbim_context_type_vals, "Unknown"), guid_to_str(wmem_packet_scope(), &uuid));
*offset += 16;
return i;
}
static void
mbim_dissect_set_connect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 access_string_offset, access_string_size, user_name_offset, user_name_size,
password_offset, password_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_set_connect_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_connect_activation_command, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_access_string_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &access_string_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_access_string_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &access_string_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_user_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &user_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_user_name_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &user_name_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_password_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &password_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_connect_password_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &password_size);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_connect_compression, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_connect_auth_protocol, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_connect_ip_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
mbim_dissect_context_type_uuid(tvb, pinfo, tree, &offset);
if (access_string_offset && access_string_size) {
it = proto_tree_add_item(tree, hf_mbim_set_connect_access_string, tvb, base_offset + access_string_offset,
access_string_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (access_string_size > 200) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (user_name_offset && user_name_size) {
it = proto_tree_add_item(tree, hf_mbim_set_connect_user_name, tvb, base_offset + user_name_offset,
user_name_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (user_name_size > 510) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (password_offset && password_size) {
it = proto_tree_add_item(tree, hf_mbim_set_connect_password, tvb, base_offset + password_offset,
password_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (password_size > 510) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_connect_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint32 nw_error;
proto_tree_add_item(tree, hf_mbim_connect_info_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_connect_info_activation_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_connect_info_voice_call_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_connect_info_ip_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
mbim_dissect_context_type_uuid(tvb, pinfo, tree, &offset);
nw_error = tvb_get_letohl(tvb, offset);
if (nw_error == 0) {
proto_tree_add_uint_format_value(tree, hf_mbim_connect_info_nw_error, tvb, offset, 4, nw_error, "Success (0)");
} else {
proto_tree_add_uint(tree, hf_mbim_connect_info_nw_error, tvb, offset, 4, nw_error);
}
}
static void
mbim_dissect_context(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gboolean is_set)
{
gint base_offset;
guint32 access_string_offset, access_string_size, user_name_offset, user_name_size,
password_offset, password_size, provider_id_offset = 0, provider_id_size = 0;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_context_context_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
mbim_dissect_context_type_uuid(tvb, pinfo, tree, &offset);
proto_tree_add_item_ret_uint(tree, hf_mbim_context_access_string_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &access_string_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_access_string_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &access_string_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_user_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &user_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_user_name_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &user_name_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_password_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &password_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_password_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &password_size);
offset += 4;
proto_tree_add_item(tree, hf_mbim_context_compression, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_context_auth_protocol, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (is_set) {
proto_tree_add_item_ret_uint(tree, hf_mbim_context_provider_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_context_provider_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_size);
offset += 4;
}
if (access_string_offset && access_string_size) {
it = proto_tree_add_item(tree, hf_mbim_context_access_string, tvb, base_offset + access_string_offset,
access_string_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (access_string_size > 200) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (user_name_offset && user_name_size) {
it = proto_tree_add_item(tree, hf_mbim_context_user_name, tvb, base_offset + user_name_offset,
user_name_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (user_name_size > 510) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (password_offset && password_size) {
it = proto_tree_add_item(tree, hf_mbim_context_password, tvb, base_offset + password_offset,
password_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (password_size > 510) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (provider_id_offset && provider_id_size) {
it = proto_tree_add_item(tree, hf_mbim_context_provider_id, tvb, base_offset + provider_id_offset,
provider_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_id_size > 12) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_provisioned_contexts_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, elem_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_provisioned_contexts_info_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Provisioned Context Ref List");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_provisioned_contexts_info_provisioned_context_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_provisioned_contexts_info_provisioned_context_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "Provisioned Context #%u", i+1);
mbim_dissect_context(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset, FALSE);
}
}
}
}
static void
mbim_dissect_ipv4_element(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset)
{
guint32 on_link_prefix_length;
proto_item *ti;
ti = proto_tree_add_item_ret_uint(tree, hf_mbim_ipv4_element_on_link_prefix_length,
tvb, *offset, 4, ENC_LITTLE_ENDIAN, &on_link_prefix_length);
*offset += 4;
if (on_link_prefix_length > 32) {
expert_add_info_format(pinfo, ti, &ei_mbim_illegal_on_link_prefix_length,
"Illegal On Link Prefix Length %u (max is 32)", on_link_prefix_length);
}
proto_tree_add_item(tree, hf_mbim_ipv4_element_ipv4_address, tvb, *offset, 4, ENC_NA);
*offset += 4;
}
static void
mbim_dissect_ipv6_element(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint *offset)
{
guint32 on_link_prefix_length;
proto_item *ti;
ti = proto_tree_add_item_ret_uint(tree, hf_mbim_ipv6_element_on_link_prefix_length, tvb,
*offset, 4, ENC_LITTLE_ENDIAN, &on_link_prefix_length);
*offset += 4;
if (on_link_prefix_length > 128) {
expert_add_info_format(pinfo, ti, &ei_mbim_illegal_on_link_prefix_length,
"Illegal On Link Prefix Length %u (max is 128)", on_link_prefix_length);
}
proto_tree_add_item(tree, hf_mbim_ipv6_element_ipv6_address, tvb, *offset, 16, ENC_NA);
*offset += 16;
}
static void
mbim_dissect_ip_configuration_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 i, ipv4_address_count, ipv4_address_offset, ipv6_address_count, ipv6_address_offset,
ipv4_gateway_offset, ipv6_gateway_offset, ipv4_dns_count, ipv4_dns_offset,
ipv6_dns_count, ipv6_dns_offset;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_ip_configuration_info_ipv4_configuration_available,
ett_mbim_bitmap, mbim_ip_configuration_info_ipv4_configuration_available_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_ip_configuration_info_ipv6_configuration_available,
ett_mbim_bitmap, mbim_ip_configuration_info_ipv6_configuration_available_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv4_address_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv4_address_count);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv4_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv4_address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv6_address_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv6_address_count);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv6_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv6_address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv4_gateway_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv4_gateway_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv6_gateway_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv6_gateway_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv4_dns_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv4_dns_count);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv4_dns_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv4_dns_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv6_dns_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv6_dns_count);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ip_configuration_info_ipv6_dns_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ipv6_dns_offset);
offset += 4;
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv4_mtu, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv6_mtu, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (ipv4_address_count && ipv4_address_offset) {
offset = base_offset + ipv4_address_offset;
for (i = 0; i < ipv4_address_count; i++) {
mbim_dissect_ipv4_element(tvb, pinfo, tree, &offset);
}
}
if (ipv6_address_count && ipv6_address_offset) {
offset = base_offset + ipv6_address_offset;
for (i = 0; i < ipv6_address_count; i++) {
mbim_dissect_ipv6_element(tvb, pinfo, tree, &offset);
}
}
if (ipv4_gateway_offset) {
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv4_gateway,
tvb, base_offset + ipv4_gateway_offset, 4, ENC_NA);
}
if (ipv6_gateway_offset) {
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv6_gateway,
tvb, base_offset + ipv6_gateway_offset, 16, ENC_NA);
}
if (ipv4_dns_count && ipv4_dns_offset) {
offset = base_offset + ipv4_dns_offset;
for (i = 0; i < ipv4_dns_count; i++) {
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv4_dns,
tvb, offset, 4, ENC_NA);
offset += 4;
}
}
if (ipv6_dns_count && ipv6_dns_offset) {
offset = base_offset + ipv6_dns_offset;
for (i = 0; i < ipv6_dns_count; i++) {
proto_tree_add_item(tree, hf_mbim_ip_configuration_info_ipv6_dns,
tvb, offset, 16, ENC_NA);
offset += 16;
}
}
}
static void
mbim_dissect_device_service_element(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint8 uuid_idx;
guint32 i, cid_count, cid;
struct mbim_uuid_ext *uuid_ext_info = NULL;
uuid_idx = mbim_dissect_service_id_uuid(tvb, pinfo, tree, hf_mbim_device_service_element_device_service_id, &offset, &uuid_ext_info);
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_device_service_element_dss_payload,
ett_mbim_bitmap, mbim_device_service_element_dss_payload_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_device_service_element_max_dss_instances, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_service_element_cid_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &cid_count);
offset += 4;
for (i = 0; i < cid_count; i++) {
cid = tvb_get_letohl(tvb, offset);
if (uuid_idx < UUID_MAX) {
if (mbim_uuid_info[uuid_idx].cid_list_ext) {
proto_tree_add_uint_format_value(tree, hf_mbim_device_service_element_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_ext_const(cid, mbim_uuid_info[uuid_idx].cid_list_ext, "Unknown"), cid);
} else {
proto_tree_add_uint_format_value(tree, hf_mbim_device_service_element_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_const(cid, mbim_uuid_info[uuid_idx].cid_list, "Unknown"), cid);
}
} else if (uuid_idx == UUID_EXT_IDX) {
proto_tree_add_uint_format_value(tree, hf_mbim_device_service_element_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_const(cid, uuid_ext_info->uuid_cid_list, "Unknown"), cid);
} else {
proto_tree_add_uint(tree, hf_mbim_device_service_element_cid, tvb, offset, 4, cid);
}
offset += 4;
}
}
static void
mbim_dissect_device_services_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, device_services_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_services_info_device_services_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &device_services_count);
offset += 4;
proto_tree_add_item(tree, hf_mbim_device_services_info_max_dss_sessions, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (device_services_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), device_services_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*device_services_count, ett_mbim_pair_list, NULL, "Device Services Ref List");
for (i = 0; i < device_services_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_device_services_info_device_services_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_device_services_info_device_services_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < device_services_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "Device Service Element #%u", i+1);
mbim_dissect_device_service_element(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_event_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint8 uuid_idx;
guint32 i, cid_count, cid;
struct mbim_uuid_ext *uuid_ext_info = NULL;
uuid_idx = mbim_dissect_service_id_uuid(tvb, pinfo, tree, hf_mbim_event_entry_device_service_id, &offset, &uuid_ext_info);
proto_tree_add_item_ret_uint(tree, hf_mbim_event_entry_cid_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &cid_count);
offset += 4;
for (i = 0; i < cid_count; i++) {
cid = tvb_get_letohl(tvb, offset);
if (uuid_idx < UUID_MAX) {
if (mbim_uuid_info[uuid_idx].cid_list_ext) {
proto_tree_add_uint_format_value(tree, hf_mbim_event_entry_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_ext_const(cid, mbim_uuid_info[uuid_idx].cid_list_ext, "Unknown"), cid);
} else {
proto_tree_add_uint_format_value(tree, hf_mbim_event_entry_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_const(cid, mbim_uuid_info[uuid_idx].cid_list, "Unknown"), cid);
}
} else if (uuid_idx == UUID_EXT_IDX) {
proto_tree_add_uint_format_value(tree, hf_mbim_device_service_element_cid, tvb, offset, 4, cid, "%s (%u)",
val_to_str_const(cid, uuid_ext_info->uuid_cid_list, "Unknown"), cid);
} else {
proto_tree_add_uint(tree, hf_mbim_event_entry_cid, tvb, offset, 4, cid);
}
offset += 4;
}
}
static void
mbim_dissect_device_service_subscribe_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, element_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_device_service_subscribe_element_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &element_count);
offset += 4;
if (element_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), element_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*element_count, ett_mbim_pair_list, NULL, "Device Service Subscribe Ref List");
for (i = 0; i < element_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_device_service_subscribe_device_service_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_device_service_subscribe_device_service_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < element_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "Device Service Element #%u", i+1);
mbim_dissect_event_entry(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_packet_statistics_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_in_discards, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_in_errors, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_in_octets, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_in_packets, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_out_octets, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_out_packets, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_out_errors, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_packet_statistics_info_out_discards, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_single_packet_filter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 filter_size, packet_filter_offset, packet_mask_offset;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_single_packet_filter_filter_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &filter_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_single_packet_filter_packet_filter_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &packet_filter_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_single_packet_filter_packet_mask_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &packet_mask_offset);
if (filter_size) {
if (packet_filter_offset) {
proto_tree_add_item(tree, hf_mbim_single_packet_filter_packet_filter, tvb, base_offset + packet_filter_offset,
filter_size, ENC_NA);
}
if (packet_mask_offset) {
proto_tree_add_item(tree, hf_mbim_single_packet_filter_packet_mask, tvb, base_offset + packet_mask_offset,
filter_size, ENC_NA);
}
}
}
static void
mbim_dissect_packet_filters(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, packet_filters_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_packet_filters_session_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_packet_filters_packet_filters_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &packet_filters_count);
offset += 4;
if (packet_filters_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), packet_filters_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*packet_filters_count, ett_mbim_pair_list, NULL, "Packet Filter Ref List");
for (i = 0; i < packet_filters_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_packet_filters_packet_filters_packet_filter_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_packet_filters_packet_filters_packet_filter_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < packet_filters_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "Packet Filter Element #%u", i+1);
mbim_dissect_single_packet_filter(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_set_sms_configuration(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 sc_address_offset, sc_address_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_set_sms_configuration_format, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_sms_configuration_sc_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sc_address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_sms_configuration_sc_address_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sc_address_size);
if (sc_address_offset && sc_address_size) {
it = proto_tree_add_item(tree, hf_mbim_set_sms_configuration_sc_address, tvb, base_offset + sc_address_offset,
sc_address_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (sc_address_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_sms_configuration_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 sc_address_offset, sc_address_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_sms_configuration_info_sms_storage_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_configuration_info_format, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_configuration_info_max_messages, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_configuration_info_cdma_short_message_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_configuration_info_sc_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sc_address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_configuration_info_sc_address_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &sc_address_size);
if (sc_address_offset && sc_address_size) {
it = proto_tree_add_item(tree, hf_mbim_sms_configuration_info_sc_address, tvb, base_offset + sc_address_offset,
sc_address_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (sc_address_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_sms_pdu_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
gint base_offset;
guint32 message_status, pdu_data_offset, pdu_data_size;
tvbuff_t *sms_tvb;
proto_item *ti;
proto_tree *subtree, *sc_tree;
guint8 sc_address_size;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_sms_pdu_record_message_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_pdu_record_message_status, tvb, offset, 4, ENC_LITTLE_ENDIAN, &message_status);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_pdu_record_pdu_data_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pdu_data_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_pdu_record_pdu_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pdu_data_size);
if (pdu_data_offset && pdu_data_size) {
if ((((mbim_sms_pdu_format == SMS_PDU_AUTOMATIC) && (mbim_conv->cellular_class & MBIM_CELLULAR_CLASS_GSM)) ||
(mbim_sms_pdu_format == SMS_PDU_3GPP)) && gsm_sms_handle) {
ti = proto_tree_add_item(tree, hf_mbim_sms_pdu_record_pdu_data, tvb, base_offset + pdu_data_offset,
pdu_data_size, ENC_NA);
if (pdu_data_size > 183) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
sc_address_size = tvb_get_guint8(tvb, base_offset + pdu_data_offset);
sc_tree = proto_tree_add_subtree(subtree, tvb, base_offset + pdu_data_offset, 1 + sc_address_size,
ett_mbim_sc_address, NULL, "Service Center Address");
proto_tree_add_uint(sc_tree, hf_mbim_sms_pdu_record_pdu_data_sc_address_size, tvb,
base_offset + pdu_data_offset, 1, sc_address_size);
if (sc_address_size) {
de_cld_party_bcd_num(tvb, sc_tree, pinfo, base_offset + pdu_data_offset + 1,
sc_address_size, NULL, 0);
}
if (pdu_data_size > (guint32)(sc_address_size + 1)) {
pdu_data_size -= sc_address_size + 1;
sms_tvb = tvb_new_subset_length(tvb, base_offset + pdu_data_offset + 1 + sc_address_size,
pdu_data_size);
pinfo->p2p_dir = (message_status < 2) ? P2P_DIR_SENT : P2P_DIR_RECV;
call_dissector(gsm_sms_handle, sms_tvb, pinfo, subtree);
}
} else {
ti = proto_tree_add_item(tree, hf_mbim_sms_pdu_record_pdu_data, tvb, base_offset + pdu_data_offset,
pdu_data_size, ENC_NA);
if (pdu_data_size > 255) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
if ((((mbim_sms_pdu_format == SMS_PDU_AUTOMATIC) && (mbim_conv->cellular_class & MBIM_CELLULAR_CLASS_CDMA)) ||
(mbim_sms_pdu_format == SMS_PDU_3GPP2)) && cdma_sms_handle) {
sms_tvb = tvb_new_subset_length(tvb, base_offset + pdu_data_offset, pdu_data_size);
call_dissector(cdma_sms_handle, sms_tvb, pinfo, subtree);
}
}
}
}
static void mbim_decode_sms_cdma_text(tvbuff_t *tvb, proto_tree *tree, const int hfindex, gint offset,
guint32 encoding_id, guint32 size_in_bytes, guint32 size_in_chars)
{
unsigned char *src, *dest;
switch (encoding_id) {
case MBIM_ENCODING_7BIT_ASCII:
proto_tree_add_ascii_7bits_item(tree, hfindex, tvb, (offset << 3), size_in_chars);
break;
case MBIM_ENCODING_IA5:
src = tvb_get_ascii_7bits_string(wmem_packet_scope(), tvb, (offset << 3), size_in_chars);
dest = (unsigned char*)wmem_alloc(wmem_packet_scope(), size_in_chars+1);
IA5_7BIT_decode(dest, src, size_in_chars);
proto_tree_add_string(tree, hfindex, tvb, offset, size_in_bytes, dest);
break;
case MBIM_ENCODING_UNICODE:
proto_tree_add_item(tree, hfindex, tvb, offset, size_in_bytes, ENC_UCS_2|ENC_BIG_ENDIAN);
break;
case MBIM_ENCODING_LATIN_HEBREW:
proto_tree_add_item(tree, hfindex, tvb, offset, size_in_bytes, ENC_ISO_8859_8|ENC_NA);
break;
case MBIM_ENCODING_LATIN:
proto_tree_add_item(tree, hfindex, tvb, offset, size_in_bytes, ENC_ISO_8859_1|ENC_NA);
break;
case MBIM_ENCODING_GSM_7BIT:
proto_tree_add_ts_23_038_7bits_item(tree, hfindex, tvb, (offset << 3), size_in_chars);
break;
default:
break;
}
}
static void
mbim_dissect_sms_cdma_record(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 address_offset, address_size, timestamp_offset, timestamp_size, encoding_id,
encoded_message_offset, size_in_bytes, size_in_chars;
proto_item *ti;
proto_tree *subtree;
proto_item *it;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_sms_cdma_record_message_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_cdma_record_message_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_address_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &address_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_timestamp_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &timestamp_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_timestamp_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &timestamp_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_encoding_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &encoding_id);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_cdma_record_language_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_encoded_message_offset, tvb, offset, 4,
ENC_LITTLE_ENDIAN, &encoded_message_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_size_in_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN, &size_in_bytes);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_cdma_record_size_in_characters, tvb, offset, 4, ENC_LITTLE_ENDIAN, &size_in_chars);
if (address_offset && address_size) {
it = proto_tree_add_item(tree, hf_mbim_sms_cdma_record_address, tvb, base_offset + address_offset,
address_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (address_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (timestamp_offset && timestamp_size) {
it = proto_tree_add_item(tree, hf_mbim_sms_cdma_record_timestamp, tvb, base_offset + timestamp_offset,
timestamp_size, ENC_NA|ENC_ASCII);
if (timestamp_size > 21) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (encoded_message_offset && size_in_bytes) {
ti = proto_tree_add_item(tree, hf_mbim_sms_cdma_record_encoded_message, tvb, base_offset + encoded_message_offset,
size_in_bytes, ENC_NA);
if (size_in_bytes > 160) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
mbim_decode_sms_cdma_text(tvb, subtree, hf_mbim_sms_cdma_record_encoded_message_text,
(base_offset + encoded_message_offset), encoding_id, size_in_bytes, size_in_chars);
}
}
static void
mbim_dissect_sms_read_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_sms_read_req_format, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_read_req_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_read_req_message_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_sms_read_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
proto_tree *subtree;
gint base_offset;
guint32 i, format, element_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_read_info_format, tvb, offset, 4, ENC_LITTLE_ENDIAN, &format);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_read_info_element_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &element_count);
offset += 4;
if (element_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), element_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*element_count, ett_mbim_pair_list, NULL, "SMS Ref List");
for (i = 0; i < element_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_sms_read_info_sms_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_sms_read_info_sms_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < element_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "SMS Element #%u", i+1);
if (format == MBIM_SMS_FORMAT_PDU) {
mbim_dissect_sms_pdu_record(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset, mbim_conv);
} else if (format == MBIM_SMS_FORMAT_CDMA) {
mbim_dissect_sms_cdma_record(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unknown_sms_format, tvb,
base_offset + p_pair_list_item->offset, p_pair_list_item->size);
}
}
}
}
}
static void
mbim_dissect_sms_send_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
gint base_offset;
guint32 pdu_data_offset, pdu_data_size;
tvbuff_t *sms_tvb;
proto_item *ti;
proto_tree *subtree, *sc_tree;
guint8 sc_address_size;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_pdu_pdu_data_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pdu_data_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_pdu_pdu_data_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pdu_data_size);
if (pdu_data_offset && pdu_data_size) {
if ((((mbim_sms_pdu_format == SMS_PDU_AUTOMATIC) && (mbim_conv->cellular_class & MBIM_CELLULAR_CLASS_GSM)) ||
(mbim_sms_pdu_format == SMS_PDU_3GPP)) && gsm_sms_handle) {
ti = proto_tree_add_item(tree, hf_mbim_sms_send_pdu_pdu_data, tvb, base_offset + pdu_data_offset,
pdu_data_size, ENC_NA);
if (pdu_data_size > 183) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
sc_address_size = tvb_get_guint8(tvb, base_offset + pdu_data_offset);
sc_tree = proto_tree_add_subtree(subtree, tvb, base_offset + pdu_data_offset, 1 + sc_address_size,
ett_mbim_sc_address, NULL, "Service Center Address");
proto_tree_add_uint(sc_tree, hf_mbim_sms_send_pdu_pdu_data_sc_address_size, tvb,
base_offset + pdu_data_offset, 1, sc_address_size);
if (sc_address_size) {
de_cld_party_bcd_num(tvb, sc_tree, pinfo, base_offset + pdu_data_offset + 1,
sc_address_size, NULL, 0);
}
if (pdu_data_size > (guint32)(sc_address_size + 1)) {
pdu_data_size -= sc_address_size + 1;
sms_tvb = tvb_new_subset_length(tvb, base_offset + pdu_data_offset + 1 + sc_address_size,
pdu_data_size);
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector(gsm_sms_handle, sms_tvb, pinfo, subtree);
}
} else {
ti = proto_tree_add_item(tree, hf_mbim_sms_send_pdu_pdu_data, tvb, base_offset + pdu_data_offset,
pdu_data_size, ENC_NA);
if (pdu_data_size > 255) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
if ((((mbim_sms_pdu_format == SMS_PDU_AUTOMATIC) && (mbim_conv->cellular_class & MBIM_CELLULAR_CLASS_CDMA)) ||
(mbim_sms_pdu_format == SMS_PDU_3GPP2)) && cdma_sms_handle) {
sms_tvb = tvb_new_subset_length(tvb, base_offset + pdu_data_offset, pdu_data_size);
call_dissector(cdma_sms_handle, sms_tvb, pinfo, subtree);
}
}
}
}
static void
mbim_dissect_sms_send_cdma(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 encoding_id, address_offset, address_size, encoded_message_offset,
size_in_bytes, size_in_chars;
proto_item *ti;
proto_tree *subtree;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_encoding_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &encoding_id);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sms_send_cdma_language_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_address_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &address_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_address_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &address_size);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_encoded_message_offset, tvb, offset, 4,
ENC_LITTLE_ENDIAN, &encoded_message_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_size_in_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN, &size_in_bytes);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_sms_send_cdma_size_in_characters, tvb, offset, 4, ENC_LITTLE_ENDIAN, &size_in_chars);
if (address_offset && address_size) {
ti = proto_tree_add_item(tree, hf_mbim_sms_send_cdma_address, tvb, base_offset + address_offset,
address_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (address_size > 40) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_string);
}
}
if (encoded_message_offset && size_in_bytes) {
ti = proto_tree_add_item(tree, hf_mbim_sms_send_cdma_encoded_message, tvb, base_offset + encoded_message_offset,
size_in_bytes, ENC_NA);
if (size_in_bytes > 160) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
mbim_decode_sms_cdma_text(tvb, subtree, hf_mbim_sms_send_cdma_encoded_message_text,
(base_offset + encoded_message_offset), encoding_id, size_in_bytes, size_in_chars);
}
}
static void
mbim_dissect_set_sms_send(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
struct mbim_conv_info *mbim_conv)
{
guint32 format;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_sms_send_format, tvb, offset, 4, ENC_LITTLE_ENDIAN, &format);
offset += 4;
if (format == MBIM_SMS_FORMAT_PDU) {
mbim_dissect_sms_send_pdu(tvb, pinfo, tree, offset, mbim_conv);
} else if (format == MBIM_SMS_FORMAT_CDMA) {
mbim_dissect_sms_send_cdma(tvb, pinfo, tree, offset);
} else {
proto_tree_add_expert(tree, pinfo, &ei_mbim_unknown_sms_format, tvb, offset, -1);
}
}
static void
mbim_dissect_set_ussd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_item *ti;
proto_tree *subtree;
gint base_offset;
guint32 ussd_payload_offset, ussd_payload_length;
guint8 encoding;
tvbuff_t *ussd_tvb;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_set_ussd_ussd_action, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(tree, hf_mbim_set_ussd_ussd_data_coding_scheme, tvb, offset, 4, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
encoding = dissect_cbs_data_coding_scheme(tvb, pinfo, subtree, offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_ussd_ussd_payload_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ussd_payload_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_ussd_ussd_payload_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ussd_payload_length);
if (ussd_payload_offset && ussd_payload_length) {
ti = proto_tree_add_item(tree, hf_mbim_set_ussd_ussd_payload, tvb, base_offset + ussd_payload_offset,
ussd_payload_length, ENC_NA);
if (ussd_payload_length > 160) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
ussd_tvb = tvb_new_subset_length(tvb, base_offset + ussd_payload_offset, ussd_payload_length);
switch (encoding) {
case SMS_ENCODING_7BIT:
case SMS_ENCODING_7BIT_LANG:
proto_tree_add_item(subtree, hf_mbim_set_ussd_ussd_payload_text,
ussd_tvb, 0, ussd_payload_length, ENC_3GPP_TS_23_038_7BITS|ENC_NA);
break;
case SMS_ENCODING_8BIT:
proto_tree_add_item(subtree, hf_mbim_set_ussd_ussd_payload_text,
ussd_tvb , 0, ussd_payload_length, ENC_ASCII|ENC_NA);
break;
case SMS_ENCODING_UCS2:
case SMS_ENCODING_UCS2_LANG:
proto_tree_add_item(subtree, hf_mbim_set_ussd_ussd_payload_text,
ussd_tvb , 0, ussd_payload_length, ENC_UCS_2|ENC_BIG_ENDIAN);
break;
default:
break;
}
}
}
static void
mbim_dissect_ussd_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_item *ti;
proto_tree *subtree;
gint base_offset;
guint32 ussd_payload_offset, ussd_payload_length;
guint8 encoding;
tvbuff_t *ussd_tvb;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_ussd_info_ussd_response, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_ussd_info_ussd_session_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(tree, hf_mbim_ussd_info_ussd_data_coding_scheme, tvb, offset, 4, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
encoding = dissect_cbs_data_coding_scheme(tvb, pinfo, subtree, offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ussd_info_ussd_payload_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ussd_payload_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_ussd_info_ussd_payload_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &ussd_payload_length);
if (ussd_payload_offset && ussd_payload_length) {
ti = proto_tree_add_item(tree, hf_mbim_ussd_info_ussd_payload, tvb, base_offset + ussd_payload_offset,
ussd_payload_length, ENC_NA);
if (ussd_payload_length > 160) {
expert_add_info(pinfo, ti, &ei_mbim_oversized_pdu);
}
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
ussd_tvb = tvb_new_subset_length(tvb, base_offset + ussd_payload_offset, ussd_payload_length);
switch (encoding) {
case SMS_ENCODING_7BIT:
case SMS_ENCODING_7BIT_LANG:
proto_tree_add_item(subtree, hf_mbim_ussd_info_ussd_payload_text,
ussd_tvb, 0, ussd_payload_length, ENC_3GPP_TS_23_038_7BITS|ENC_NA);
break;
case SMS_ENCODING_8BIT:
proto_tree_add_item(subtree, hf_mbim_ussd_info_ussd_payload_text,
ussd_tvb , 0, ussd_payload_length, ENC_ASCII|ENC_NA);
break;
case SMS_ENCODING_UCS2:
case SMS_ENCODING_UCS2_LANG:
proto_tree_add_item(subtree, hf_mbim_ussd_info_ussd_payload_text,
ussd_tvb , 0, ussd_payload_length, ENC_UCS_2|ENC_BIG_ENDIAN);
break;
default:
break;
}
}
}
static void
mbim_dissect_phonebook_configuration_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_phonebook_configuration_info_phonebook_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_phonebook_configuration_info_total_nb_of_entries, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_phonebook_configuration_info_used_entries, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_phonebook_configuration_info_max_number_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_phonebook_configuration_info_max_name_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_phonebook_entry(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 number_offset, number_length, name_offset, name_length;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_phonebook_entry_entry_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_phonebook_entry_number_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &number_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_phonebook_entry_number_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &number_length);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_phonebook_entry_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_phonebook_entry_name_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &name_length);
if (number_offset && number_length) {
proto_tree_add_item(tree, hf_mbim_phonebook_entry_number, tvb, base_offset + number_offset,
number_length, ENC_LITTLE_ENDIAN|ENC_UTF_16);
}
if (name_offset && name_length) {
proto_tree_add_item(tree, hf_mbim_phonebook_entry_name, tvb, base_offset + name_offset,
name_length, ENC_LITTLE_ENDIAN|ENC_UTF_16);
}
}
static void
mbim_dissect_phonebook_read_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, element_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_phonebook_read_info_element_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &element_count);
offset += 4;
if (element_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), element_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*element_count, ett_mbim_pair_list, NULL, "Phonebook Ref List");
for (i = 0; i < element_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_phonebook_read_info_phonebook_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_phonebook_read_info_phonebook_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < element_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset,
p_pair_list_item->size, ett_mbim_pair_list, NULL, "Phonebook Element #%u", i+1);
mbim_dissect_phonebook_entry(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_set_phonebook_write(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 number_offset, number_length, name_offset, name_length;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_set_phonebook_write_save_flag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_phonebook_write_save_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_phonebook_write_number_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &number_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_phonebook_write_number_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &number_length);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_phonebook_write_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_phonebook_write_name_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &name_length);
if (number_offset && number_length) {
proto_tree_add_item(tree, hf_mbim_set_phonebook_write_number, tvb, base_offset + number_offset,
number_length, ENC_LITTLE_ENDIAN|ENC_UTF_16);
}
if (name_offset && name_length) {
proto_tree_add_item(tree, hf_mbim_set_phonebook_write_name, tvb, base_offset + name_offset,
name_length, ENC_LITTLE_ENDIAN|ENC_UTF_16);
}
}
static void
mbim_dissect_set_stk_pac(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_mbim_set_stk_pac_pac_host_control, tvb, offset, 32, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_mbim_pac);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_refresh, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_more_time, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_poll_interval, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_polling_off, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_set_up_evt_list, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_set_up_call, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_send_ss, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_send_ussd, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_send_short_msg, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_send_dtmf, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_launch_browser, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_geo_loc_req, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_play_tone, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_display_text, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_inkey, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_input, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_select_item, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_set_up_menu, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_prov_local_info, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_timer_management, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_set_up_idle_mode_text, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_perform_card_apdu, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_power_on_card, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_power_off_card, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_reader_status, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_run_at_cmd, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_lang_notif, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_open_channel, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_close_channel, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_receive_data, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_send_data, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_channel_status, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_service_search, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_service_info, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_declare_service, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_set_frames, tvb, offset+6, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_get_frames_status, tvb, offset+6, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_retrieve_multimedia_msg, tvb, offset+7, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_submit_multimedia_msg, tvb, offset+7, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_display_multimedia_msg, tvb, offset+7, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_activate, tvb, offset+8, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_contactless_state_changed, tvb, offset+8, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_cmd_container, tvb, offset+9, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_encapsulated_session_ctrl, tvb, offset+9, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_set_stk_pac_pac_host_control_end_proact_session, tvb, offset+10, 1, ENC_NA);
}
static void
mbim_dissect_stk_pac_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_mbim_stk_pac_info_pac_support, tvb, offset, 256, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_mbim_pac);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_refresh, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_more_time, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_poll_interval, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_polling_off, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_set_up_evt_list, tvb, offset+5, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_set_up_call, tvb, offset+10, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_send_ss, tvb, offset+11, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_send_ussd, tvb, offset+12, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_send_short_msg, tvb, offset+13, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_send_dtmf, tvb, offset+14, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_launch_browser, tvb, offset+15, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_geo_loc_req, tvb, offset+16, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_play_tone, tvb, offset+20, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_display_text, tvb, offset+21, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_inkey, tvb, offset+22, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_input, tvb, offset+23, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_select_item, tvb, offset+24, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_set_up_menu, tvb, offset+25, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_prov_local_info, tvb, offset+26, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_timer_management, tvb, offset+27, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_set_up_idle_mode_text, tvb, offset+28, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_perform_card_apdu, tvb, offset+30, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_power_on_card, tvb, offset+31, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_power_off_card, tvb, offset+32, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_reader_status, tvb, offset+33, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_run_at_cmd, tvb, offset+34, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_lang_notif, tvb, offset+35, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_open_channel, tvb, offset+40, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_close_channel, tvb, offset+41, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_receive_data, tvb, offset+42, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_send_data, tvb, offset+43, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_channel_status, tvb, offset+44, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_service_search, tvb, offset+45, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_service_info, tvb, offset+46, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_declare_service, tvb, offset+47, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_set_frames, tvb, offset+50, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_get_frames_status, tvb, offset+51, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_retrieve_multimedia_msg, tvb, offset+60, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_submit_multimedia_msg, tvb, offset+61, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_display_multimedia_msg, tvb, offset+62, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_activate, tvb, offset+70, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_contactless_state_changed, tvb, offset+71, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_cmd_container, tvb, offset+72, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_encapsulated_session_ctrl, tvb, offset+73, 1, ENC_NA);
proto_tree_add_item(subtree, hf_mbim_stk_pac_info_pac_support_end_proact_session, tvb, offset+81, 1, ENC_NA);
}
static void
mbim_dissect_set_stk_terminal_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
tvbuff_t *pac_tvb;
guint32 response_length;
proto_item *ti;
proto_tree *subtree;
proto_tree_add_item_ret_uint(tree, hf_mbim_set_stk_terminal_response_response_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &response_length);
offset += 4;
ti = proto_tree_add_item(tree, hf_mbim_set_stk_terminal_response_data_buffer, tvb, offset, response_length, ENC_NA);
if (etsi_cat_handle) {
subtree = proto_item_add_subtree(ti, ett_mbim_buffer);
pac_tvb = tvb_new_subset_length(tvb, offset, response_length);
call_dissector(etsi_cat_handle, pac_tvb, pinfo, subtree);
}
}
static void
mbim_dissect_stk_terminal_response_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 result_data_string_offset, result_data_string_length;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_stk_terminal_response_info_result_data_string_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &result_data_string_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_stk_terminal_response_info_result_data_string_length,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &result_data_string_length);
offset += 4;
proto_tree_add_item(tree, hf_mbim_stk_terminal_response_info_status_word, tvb, offset,
4, ENC_LITTLE_ENDIAN);
if (result_data_string_offset && result_data_string_length) {
proto_tree_add_item(tree, hf_mbim_stk_terminal_response_info_result_data_string, tvb,
base_offset + result_data_string_offset, result_data_string_length, ENC_NA);
}
}
static void
mbim_dissect_aka_auth_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_aka_auth_req_rand, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_aka_auth_req_autn, tvb, offset, 16, ENC_NA);
}
static void
mbim_dissect_aka_auth_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_aka_auth_info_res, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_aka_auth_info_res_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_aka_auth_info_ik, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_aka_auth_info_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_aka_auth_info_auts, tvb, offset, 14, ENC_NA);
}
static void
mbim_dissect_akap_auth_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 network_name_offset, network_name_length;
base_offset = offset;
proto_tree_add_item(tree, hf_mbim_akap_auth_req_rand, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_akap_auth_req_autn, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item_ret_uint(tree, hf_mbim_akap_auth_req_network_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &network_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_akap_auth_req_network_name_length, tvb, offset, 4, ENC_LITTLE_ENDIAN, &network_name_length);
if (network_name_offset && network_name_length) {
proto_tree_add_item(tree, hf_mbim_akap_auth_req_network_name, tvb, base_offset + network_name_offset,
network_name_length, ENC_LITTLE_ENDIAN|ENC_UTF_16);
}
}
static void
mbim_dissect_akap_auth_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_akap_auth_info_res, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_akap_auth_info_res_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_akap_auth_info_ik, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_akap_auth_info_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_akap_auth_info_auts, tvb, offset, 14, ENC_NA);
}
static void
mbim_dissect_sim_auth_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_sim_auth_req_rand1, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_sim_auth_req_rand2, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_sim_auth_req_rand3, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_mbim_sim_auth_req_n, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_sim_auth_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_sim_auth_info_sres1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_kc1, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_sres2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_kc2, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_sres3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_kc3, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_mbim_sim_auth_info_n, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_set_dss_connect(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint32 dss_session_id;
struct mbim_uuid_ext *uuid_ext_info = NULL;
mbim_dissect_service_id_uuid(tvb, pinfo, tree, hf_mbim_set_dss_connect_device_service_id, &offset, &uuid_ext_info);
dss_session_id = tvb_get_letohl(tvb, offset);
dissector_delete_uint("mbim.dss_session_id", dss_session_id, NULL);
if ((dss_session_id <= 255) && uuid_ext_info && uuid_ext_info->dss_handle) {
dissector_add_uint("mbim.dss_session_id", dss_session_id, uuid_ext_info->dss_handle);
}
proto_tree_add_uint(tree, hf_mbim_set_dss_connect_dss_session_id, tvb, offset, 4, dss_session_id);
offset += 4;
proto_tree_add_item(tree, hf_mbim_set_dss_connect_dss_link_state, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_muticarrier_current_cid_list_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint8 service_idx;
service_idx = mbim_dissect_service_id_uuid(tvb, pinfo, tree, hf_mbim_multicarrier_current_cid_list_req_uuid, &offset, NULL);
if (service_idx != UUID_MULTICARRIER) {
expert_add_info_format(pinfo, NULL, &ei_mbim_unexpected_uuid_value,
"Unexpected UUID value, should be UUID_MULTICARRIER");
}
}
static void
mbim_dissect_muticarrier_current_cid_list_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
guint32 i, cid_count;
proto_tree_add_item_ret_uint(tree, hf_mbim_multicarrier_current_cid_list_info_cid_count,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &cid_count);
offset += 4;
for (i = 0; i < cid_count; i++) {
proto_tree_add_item(tree, hf_mbim_multicarrier_current_cid_list_info_cid,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
static void
mbim_dissect_thermal_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
int i;
proto_tree *subtree;
for (i = 0; i < 4; i++) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 24, ett_mbim_thermal_threshold_setting, NULL, "Threshold %u", i);
proto_tree_add_item(subtree, hf_mbim_thermal_config_enable, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_thermal_config_temp_sensor_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_thermal_config_alarm_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_thermal_config_threshold_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_thermal_config_hyst_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_thermal_config_sampling_period, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
static void
mbim_dissect_thermal_state_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_thermal_state_info_current_temp_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_enable, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_temp_sensor_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_alarm_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_threshold_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_hyst_value, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_thermal_state_info_sampling_period, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_sar_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset, guint32 buffer_len)
{
proto_tree_add_item(tree, hf_mbim_sar_config_sar_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (buffer_len > 4) {
proto_tree_add_item(tree, hf_mbim_sar_config_level, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
static void
mbim_dissect_adpclk_freq_value(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset, guint32 buffer_len)
{
proto_tree_add_item(tree, hf_mbim_adpclk_freq_info_adpclk_freq_value_center_freq, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_adpclk_freq_info_adpclk_freq_value_freq_spread, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (buffer_len > 8) {
proto_tree_add_item(tree, hf_mbim_adpclk_freq_info_adpclk_freq_value_noise_power, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (buffer_len > 12) {
proto_tree_add_item(tree, hf_mbim_adpclk_freq_info_adpclk_freq_value_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (buffer_len > 16) {
proto_tree_add_item(tree, hf_mbim_adpclk_freq_info_adpclk_freq_value_connect_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
}
}
static void
mbim_dissect_adpclk_freq_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, elem_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_adpclk_freq_info_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Element Offset Length Pair");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_adpclk_freq_info_adpclk_freq_value_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_adpclk_freq_info_adpclk_freq_value_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset, p_pair_list_item->size,
ett_mbim_pair_list, NULL, "ADPCLK Freq Value #%u", i+1);
mbim_dissect_adpclk_freq_value(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset, p_pair_list_item->size);
}
}
}
}
static void
mbim_dissect_nrtcws_config(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset, guint32 buffer_len)
{
proto_tree_add_item(tree, hf_mbim_nrtcws_config_mode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (buffer_len > 2) {
proto_tree_add_item(tree, hf_mbim_nrtcws_config_wlan_active, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_config_wlan_safe_rx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_config_wlan_bandwidth, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_config_bt_active, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_config_bt_safe_rx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
static void
mbim_dissect_nrtcws_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_nrtcws_info_lte_active, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_wlan_safe_rx_min, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_wlan_safe_rx_max, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_bt_safe_rx_min, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_bt_safe_rx_max, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_lte_sps_period, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_lte_sps_duration, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mbim_nrtcws_info_lte_sps_initial_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_atds_signal_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_atds_signal_info_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_ber, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_rscp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_ecno, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_rsrq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_rsrp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_signal_info_rssnr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_atds_operator(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
gint base_offset;
guint32 provider_id_offset, provider_id_size, provider_name_offset, provider_name_size;
proto_item *it;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_operator_provider_id_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_operator_provider_id_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_id_size);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mbim_atds_operator_provider_state, ett_mbim_bitmap,
mbim_provider_state_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_operator_provider_name_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_offset);
offset += 4;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_operator_provider_name_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &provider_name_size);
offset += 4;
proto_tree_add_item (tree, hf_mbim_atds_operator_plmn_mode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_mbim_atds_operator_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (tree, hf_mbim_atds_operator_error_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (provider_id_offset && provider_id_size) {
it = proto_tree_add_item(tree, hf_mbim_atds_operator_provider_id, tvb, base_offset + provider_id_offset,
provider_id_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_id_size > 12) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
if (provider_name_offset && provider_name_size) {
it = proto_tree_add_item(tree, hf_mbim_atds_operator_provider_name, tvb, base_offset + provider_name_offset,
provider_name_size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
if (provider_name_size > 40) {
expert_add_info(pinfo, it, &ei_mbim_oversized_string);
}
}
}
static void
mbim_dissect_atds_operators(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, elem_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_operators_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Operators List");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_atds_operators_operator_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_atds_operators_operator_size, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset, p_pair_list_item->size,
ett_mbim_pair_list, NULL, "Operator #%u", i+1);
mbim_dissect_atds_operator(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static void
mbim_dissect_atds_projection_table(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_mbim_atds_projection_table_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar5min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a5, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b5, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar4min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a4, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b4, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar3min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar2min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b2, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar1min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_bar0min, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_a0, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mbim_atds_projection_table_b0, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
static void
mbim_dissect_atds_projection_tables(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
proto_tree *subtree;
gint base_offset;
guint32 i, elem_count;
wmem_array_t *pair_list;
struct mbim_pair_list pair_list_item, *p_pair_list_item;
base_offset = offset;
proto_tree_add_item_ret_uint(tree, hf_mbim_atds_projection_tables_elem_count, tvb, offset, 4, ENC_LITTLE_ENDIAN, &elem_count);
offset += 4;
if (elem_count) {
pair_list = wmem_array_sized_new(wmem_packet_scope(), sizeof(struct mbim_pair_list), elem_count);
subtree = proto_tree_add_subtree(tree, tvb, offset, 8*elem_count, ett_mbim_pair_list, NULL, "Projection Tables List");
for (i = 0; i < elem_count; i++) {
proto_tree_add_item_ret_uint(subtree, hf_mbim_atds_projection_tables_projection_table_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.offset);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_atds_projection_tables_projection_table_size,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &pair_list_item.size);
offset += 4;
wmem_array_append_one(pair_list, pair_list_item);
}
for (i = 0; i < elem_count; i++) {
p_pair_list_item = (struct mbim_pair_list*)wmem_array_index(pair_list, i);
if (p_pair_list_item->offset && p_pair_list_item->size) {
subtree = proto_tree_add_subtree_format(tree, tvb, base_offset + p_pair_list_item->offset, p_pair_list_item->size,
ett_mbim_pair_list, NULL, "Projection Table #%u", i+1);
mbim_dissect_atds_projection_table(tvb, pinfo, subtree, base_offset + p_pair_list_item->offset);
}
}
}
}
static int
dissect_mbim_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *mbim_tree, *header_tree, *subtree;
gint offset = 0;
guint32 msg_type, trans_id, open_count;
guint64 trans_id_key, *p_trans_id_key;
conversation_t *conversation;
struct mbim_conv_info *mbim_conv;
struct mbim_info *mbim_info = NULL;
if (data) {
usb_trans_info_t *usb_trans_info = ((usb_conv_info_t *)data)->usb_trans_info;
if (usb_trans_info && (usb_trans_info->setup.request == 0x00) && (USB_HEADER_IS_LINUX(usb_trans_info->header_type))) {
offset += 7;
tree = proto_tree_get_parent_tree(tree);
}
}
if (mbim_control_decode_unknown_itf && (tvb_reported_length_remaining(tvb, offset) < 12)) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MBIM");
col_clear(pinfo->cinfo, COL_INFO);
conversation = find_or_create_conversation(pinfo);
mbim_conv = (struct mbim_conv_info *)conversation_get_proto_data(conversation, proto_mbim);
if (!mbim_conv) {
mbim_conv = wmem_new(wmem_file_scope(), struct mbim_conv_info);
mbim_conv->trans = wmem_map_new(wmem_file_scope(), wmem_int64_hash, g_int64_equal);
mbim_conv->open = wmem_tree_new(wmem_file_scope());
mbim_conv->cellular_class = 0;
mbim_conv->open_count = 0;
wmem_tree_insert32(mbim_conv->open, pinfo->num, GUINT_TO_POINTER(mbim_conv->open_count));
conversation_add_proto_data(conversation, proto_mbim, mbim_conv);
}
ti = proto_tree_add_item(tree, proto_mbim, tvb, offset, -1, ENC_NA);
mbim_tree = proto_item_add_subtree(ti, ett_mbim);
ti = proto_tree_add_item(mbim_tree, hf_mbim_control, tvb, offset, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
header_tree = proto_tree_add_subtree(mbim_tree, tvb, offset, 12, ett_mbim_msg_header, NULL, "Message Header");
proto_tree_add_item_ret_uint(header_tree, hf_mbim_header_message_type, tvb, offset, 4, ENC_LITTLE_ENDIAN, &msg_type);
col_add_fstr(pinfo->cinfo, COL_INFO, "%-19s", val_to_str_const(msg_type, mbim_msg_type_vals, "Unknown"));
offset += 4;
proto_tree_add_item(header_tree, hf_mbim_header_message_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(header_tree, hf_mbim_header_transaction_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &trans_id);
offset += 4;
switch (msg_type) {
case MBIM_OPEN_MSG:
{
guint32 max_ctrl_transfer;
if (!PINFO_FD_VISITED(pinfo)) {
mbim_conv->open_count++;
wmem_tree_insert32(mbim_conv->open, pinfo->num, GUINT_TO_POINTER(mbim_conv->open_count));
}
max_ctrl_transfer = tvb_get_letohl(tvb, offset);
if (max_ctrl_transfer == 8) {
proto_tree_add_uint_format_value(mbim_tree, hf_mbim_max_ctrl_transfer, tvb, offset, 4, max_ctrl_transfer, "MBIM_ERROR_MAX_TRANSFER (%d)", max_ctrl_transfer);
} else {
ti = proto_tree_add_uint(mbim_tree, hf_mbim_max_ctrl_transfer, tvb, offset, 4, max_ctrl_transfer);
if (max_ctrl_transfer < 64) {
expert_add_info(pinfo, ti, &ei_mbim_max_ctrl_transfer);
}
}
}
break;
case MBIM_CLOSE_MSG:
break;
case MBIM_COMMAND_MSG:
{
guint32 info_buff_len, current_frag, total_frag, cid, cmd_type;
guint8 uuid_idx;
fragment_head *frag_data;
tvbuff_t *frag_tvb;
struct mbim_uuid_ext *uuid_ext_info = NULL;
subtree = proto_tree_add_subtree(mbim_tree, tvb, offset, 8, ett_mbim_frag_header, NULL, "Fragment Header");
proto_tree_add_item_ret_uint(subtree, hf_mbim_fragment_total, tvb, offset, 4, ENC_LITTLE_ENDIAN, &total_frag);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_fragment_current, tvb, offset, 4, ENC_LITTLE_ENDIAN, &current_frag);
offset += 4;
if (total_frag > 1) {
frag_data = fragment_add_seq_check(&mbim_reassembly_table, tvb, offset, pinfo,
trans_id, NULL, current_frag,
tvb_reported_length_remaining(tvb, offset),
(current_frag != (total_frag-1)));
frag_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled MBIM control message",
frag_data, &mbim_frag_items, NULL, subtree);
if (!frag_tvb) {
proto_tree_add_item(mbim_tree, hf_mbim_fragmented_payload, tvb, offset, -1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ": [Fragment #%u out of %u]", current_frag+1, total_frag);
break;
}
offset = 0;
} else {
frag_tvb = tvb;
}
open_count = GPOINTER_TO_UINT(wmem_tree_lookup32_le(mbim_conv->open, pinfo->num));
trans_id_key = ((guint64)open_count << 32) | trans_id;
if (!PINFO_FD_VISITED(pinfo)) {
p_trans_id_key = wmem_new(wmem_file_scope(), guint64);
*p_trans_id_key = trans_id_key;
mbim_info = wmem_new(wmem_file_scope(), struct mbim_info);
mbim_info->req_frame = pinfo->num;
mbim_info->resp_frame = 0;
wmem_map_insert(mbim_conv->trans, p_trans_id_key, mbim_info);
} else {
mbim_info = (struct mbim_info *)wmem_map_lookup(mbim_conv->trans, &trans_id_key);
if (mbim_info && mbim_info->resp_frame) {
proto_item *resp_it;
resp_it = proto_tree_add_uint(header_tree, hf_mbim_response_in, tvb, 0, 0, mbim_info->resp_frame);
PROTO_ITEM_SET_GENERATED(resp_it);
}
}
uuid_idx = mbim_dissect_service_id_uuid(frag_tvb, pinfo, mbim_tree, hf_mbim_device_service_id, &offset, &uuid_ext_info);
cid = mbim_dissect_cid(frag_tvb, pinfo, mbim_tree, &offset, uuid_idx, uuid_ext_info);
proto_tree_add_item_ret_uint(mbim_tree, hf_mbim_command_type, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &cmd_type);
if (mbim_info) {
mbim_info->cmd_type = cmd_type;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str_const(cmd_type, mbim_command_type_vals, "Unknown"));
offset += 4;
proto_tree_add_item_ret_uint(mbim_tree, hf_mbim_info_buffer_len, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &info_buff_len);
offset += 4;
subtree = mbim_tree;
if (info_buff_len) {
subtree = proto_tree_add_subtree(mbim_tree, frag_tvb, offset, info_buff_len, ett_mbim_info_buffer, NULL, "Information Buffer");
}
switch (uuid_idx) {
case UUID_BASIC_CONNECT:
switch (cid) {
case MBIM_CID_DEVICE_CAPS:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_SUBSCRIBER_READY_STATUS:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_RADIO_STATE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_radio_state_set, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_PIN:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_pin(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_PIN_LIST:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_HOME_PROVIDER:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_provider(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_PREFERRED_PROVIDERS:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_providers(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_VISIBLE_PROVIDERS:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
proto_tree_add_item(subtree, hf_mbim_visible_providers_req_action, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case MBIM_CID_REGISTER_STATE:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_register_state(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_PACKET_SERVICE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_set_packet_service_action,
frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_SIGNAL_STATE:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_signal_state(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_CONNECT:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_connect(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_item(subtree, hf_mbim_connect_info_session_id, frag_tvb,
offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case MBIM_CID_PROVISIONED_CONTEXTS:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_context(frag_tvb, pinfo, subtree, offset, TRUE);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_SERVICE_ACTIVATION:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_set_service_activation_data_buffer,
frag_tvb, offset, info_buff_len, ENC_NA);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_IP_CONFIGURATION:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
proto_tree_add_item(subtree, hf_mbim_ip_configuration_info_session_id, frag_tvb,
offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case MBIM_CID_DEVICE_SERVICES:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_DEVICE_SERVICE_SUBSCRIBE_LIST:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_device_service_subscribe_list(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PACKET_STATISTICS:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_NETWORK_IDLE_HINT:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_network_idle_hint_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_EMERGENCY_MODE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_IP_PACKET_FILTERS:
mbim_dissect_packet_filters(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_MULTICARRIER_PROVIDERS:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_providers(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_SMS:
switch (cid) {
case MBIM_CID_SMS_CONFIGURATION:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_sms_configuration(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_SMS_READ:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_sms_read_req(frag_tvb, pinfo, subtree, offset);
}
break;
case MBIM_CID_SMS_SEND:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_sms_send(frag_tvb, pinfo, subtree, offset, mbim_conv);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SMS_DELETE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_set_sms_delete_flag,
frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_set_sms_delete_message_index,
frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SMS_MESSAGE_STORE_STATUS:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_USSD:
switch (cid) {
case MBIM_CID_USSD:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_ussd(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_PHONEBOOK:
switch (cid) {
case MBIM_CID_PHONEBOOK_CONFIGURATION:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_PHONEBOOK_READ:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
proto_tree_add_item(subtree, hf_mbim_phonebook_read_req_filter_flag, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_phonebook_read_req_filter_message_index, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
case MBIM_CID_PHONEBOOK_DELETE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_set_phonebook_delete_filter_flag, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_set_phonebook_delete_filter_message_index, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PHONEBOOK_WRITE:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_phonebook_write(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_STK:
switch (cid) {
case MBIM_CID_STK_PAC:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_stk_pac(frag_tvb, pinfo, subtree, offset);
} else {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
}
break;
case MBIM_CID_STK_TERMINAL_RESPONSE:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_stk_terminal_response(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_STK_ENVELOPE:
if (cmd_type == MBIM_COMMAND_SET) {
tvbuff_t *env_tvb;
proto_tree *env_tree;
ti = proto_tree_add_item(subtree, hf_mbim_set_stk_envelope_data_buffer,
frag_tvb, offset, info_buff_len, ENC_NA);
if (bertlv_handle) {
env_tree = proto_item_add_subtree(ti, ett_mbim_buffer);
env_tvb = tvb_new_subset_length(frag_tvb, offset, info_buff_len);
call_dissector(bertlv_handle, env_tvb, pinfo, env_tree);
}
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_AUTH:
switch (cid) {
case MBIM_CID_AKA_AUTH:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_aka_auth_req(frag_tvb, pinfo, subtree, offset);
}
break;
case MBIM_CID_AKAP_AUTH:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_akap_auth_req(frag_tvb, pinfo, subtree, offset);
}
break;
case MBIM_CID_SIM_AUTH:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_sim_auth_req(frag_tvb, pinfo, subtree, offset);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_DSS:
switch (cid) {
case MBIM_CID_DSS_CONNECT:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_set_dss_connect(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MULTICARRIER:
switch (cid) {
case MBIM_CID_MULTICARRIER_CAPABILITIES:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_LOCATION_INFO:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_location_info_country, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_MULTICARRIER_CURRENT_CID_LIST:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, info_buff_len);
} else {
mbim_dissect_muticarrier_current_cid_list_req(frag_tvb, pinfo, subtree, offset);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MS_HOSTSHUTDOWN:
switch (cid) {
case MBIM_CID_MS_HOSTSHUTDOWN:
if (cmd_type == MBIM_COMMAND_SET) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MSFWID:
switch (cid) {
case MBIM_CID_MSFWID_FIRMWAREID:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_QMI:
switch (cid) {
case MBIM_CID_QMI_QMI:
if (info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_qmi_buffer, frag_tvb, offset, info_buff_len, ENC_NA);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_FWUSVC:
switch (cid) {
case MBIM_CID_INTC_MODEM_REBOOT:
if (cmd_type == MBIM_COMMAND_SET) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_DPTF:
switch (cid) {
case MBIM_CID_INTC_THERMAL_STATE:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_thermal_config(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_item(subtree, hf_mbim_query_thermal_state_temp_sensor_id, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_SAR:
switch (cid) {
case MBIM_CID_INTC_SAR_CONFIG:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_sar_config(frag_tvb, pinfo, subtree, offset, info_buff_len);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_ACT:
switch (cid) {
case MBIM_CID_INTC_ADPCLK_MODE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_adpclk_activate_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_TRCSVC:
switch (cid) {
case MBIM_CID_INTC_TRACE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_trace_config_config, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_INTC_TRACE_DATA:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_trace_config_config, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_NRTC:
switch (cid) {
case MBIM_CID_INTC_NRTAPP:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_nrtc_app_info_period, frag_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_mbim_nrtc_app_info_duration, frag_tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_INTC_NRTCWS:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_nrtcws_config(frag_tvb, pinfo, subtree, offset, info_buff_len);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_USB_PROFILE:
switch (cid) {
case MBIM_CID_INTC_USBPROFILE:
if (cmd_type == MBIM_COMMAND_SET) {
guint32 at_len;
proto_tree_add_item_ret_uint(subtree, hf_mbim_usbprofile_cmd_length, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &at_len);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_usbprofile_cmd_buffer, frag_tvb, offset, at_len, ENC_LITTLE_ENDIAN|ENC_UTF_16);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_CIQ:
switch (cid) {
case MBIM_CID_INTC_CIQ:
if (cmd_type == MBIM_COMMAND_SET) {
guint32 size;
proto_tree_add_item(subtree, hf_mbim_ciq_set_mode, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_ciq_set_debug_info_size, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &size);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_ciq_set_debug_info, frag_tvb, offset, size, ENC_LITTLE_ENDIAN|ENC_UTF_16);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_ATDS:
switch (cid) {
case MBIM_CID_ATDS_SIGNAL:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_ATDS_LOCATION:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_ATDS_OPERATORS:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_atds_operators(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_ATDS_RAT:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_item(subtree, hf_mbim_atds_rat_info_mode, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_ATDS_REGISTER_STATE:
if (cmd_type == MBIM_COMMAND_SET) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_ATDS_SET_PROJECTION_TABLES:
if (cmd_type == MBIM_COMMAND_SET) {
mbim_dissect_atds_projection_tables(frag_tvb, pinfo, subtree, offset);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_EXT_IDX:
{
gint cid_idx;
mbim_dissect_fct dissect_cid;
try_val_to_str_idx(cid, uuid_ext_info->uuid_cid_list, &cid_idx);
if (cid_idx != -1) {
dissect_cid = (cmd_type == MBIM_COMMAND_SET) ? uuid_ext_info->uuid_fct_list[cid_idx].cmd_set :
uuid_ext_info->uuid_fct_list[cid_idx].cmd_query;
if (dissect_cid) {
dissect_cid(frag_tvb, pinfo, subtree, offset, mbim_info);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
}
break;
default:
if (info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_info_buffer, frag_tvb, offset, info_buff_len, ENC_NA);
}
break;
}
}
break;
case MBIM_FUNCTION_ERROR_MSG:
open_count = GPOINTER_TO_UINT(wmem_tree_lookup32_le(mbim_conv->open, pinfo->num));
trans_id_key = ((guint64)open_count << 32) | trans_id;
mbim_info = (struct mbim_info *)wmem_map_lookup(mbim_conv->trans, &trans_id_key);
if (!PINFO_FD_VISITED(pinfo)) {
if (mbim_info) {
mbim_info->resp_frame = pinfo->num;
}
} else {
if (mbim_info && mbim_info->req_frame) {
proto_item *req_it;
req_it = proto_tree_add_uint(header_tree, hf_mbim_request_in, tvb, 0, 0, mbim_info->req_frame);
PROTO_ITEM_SET_GENERATED(req_it);
}
}
case MBIM_HOST_ERROR_MSG:
proto_tree_add_item(mbim_tree, hf_mbim_error_status_code, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case MBIM_OPEN_DONE:
case MBIM_CLOSE_DONE:
proto_tree_add_item(mbim_tree, hf_mbim_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case MBIM_COMMAND_DONE:
case MBIM_INDICATE_STATUS_MSG:
{
guint32 info_buff_len, current_frag, total_frag, cid;
guint8 uuid_idx;
fragment_head *frag_data;
tvbuff_t *frag_tvb;
struct mbim_uuid_ext *uuid_ext_info = NULL;
subtree = proto_tree_add_subtree(mbim_tree, tvb, offset, 8, ett_mbim_frag_header, NULL, "Fragment Header");
proto_tree_add_item_ret_uint(subtree, hf_mbim_fragment_total, tvb, offset, 4, ENC_LITTLE_ENDIAN, &total_frag);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_fragment_current, tvb, offset, 4, ENC_LITTLE_ENDIAN, &current_frag);
offset += 4;
if (total_frag > 1) {
frag_data = fragment_add_seq_check(&mbim_reassembly_table, tvb, offset, pinfo,
trans_id, NULL, current_frag,
tvb_reported_length_remaining(tvb, offset),
(current_frag != (total_frag-1)));
frag_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled MBIM control message",
frag_data, &mbim_frag_items, NULL, subtree);
if (!frag_tvb) {
proto_tree_add_item(mbim_tree, hf_mbim_fragmented_payload, tvb, offset, -1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ": [Fragment #%u out of %u]", current_frag+1, total_frag);
break;
}
offset = 0;
} else {
frag_tvb = tvb;
}
if (msg_type == MBIM_COMMAND_DONE) {
open_count = GPOINTER_TO_UINT(wmem_tree_lookup32_le(mbim_conv->open, pinfo->num));
trans_id_key = ((guint64)open_count << 32) | trans_id;
mbim_info = (struct mbim_info *)wmem_map_lookup(mbim_conv->trans, &trans_id_key);
if (!PINFO_FD_VISITED(pinfo)) {
if (mbim_info) {
mbim_info->resp_frame = pinfo->num;
}
} else {
if (mbim_info && mbim_info->req_frame) {
proto_item *req_it;
req_it = proto_tree_add_uint(header_tree, hf_mbim_request_in, tvb, 0, 0, mbim_info->req_frame);
PROTO_ITEM_SET_GENERATED(req_it);
}
}
}
uuid_idx = mbim_dissect_service_id_uuid(frag_tvb, pinfo, mbim_tree, hf_mbim_device_service_id, &offset, &uuid_ext_info);
cid = mbim_dissect_cid(frag_tvb, pinfo, mbim_tree, &offset, uuid_idx, uuid_ext_info);
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(mbim_tree, hf_mbim_status, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
proto_tree_add_item_ret_uint(mbim_tree, hf_mbim_info_buffer_len, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &info_buff_len);
offset += 4;
if (info_buff_len == 0) {
break;
}
subtree = proto_tree_add_subtree(mbim_tree, frag_tvb, offset, info_buff_len, ett_mbim_info_buffer, NULL, "Information Buffer");
switch (uuid_idx) {
case UUID_BASIC_CONNECT:
switch (cid) {
case MBIM_CID_DEVICE_CAPS:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_device_caps_info(frag_tvb, pinfo, subtree, offset, mbim_conv);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SUBSCRIBER_READY_STATUS:
mbim_dissect_subscriber_ready_status(frag_tvb, pinfo, subtree, offset, mbim_conv);
break;
case MBIM_CID_RADIO_STATE:
proto_tree_add_item(subtree, hf_mbim_radio_state_hw_radio_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_radio_state_sw_radio_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case MBIM_CID_PIN:
if (msg_type == MBIM_COMMAND_DONE) {
guint32 attempts;
proto_tree_add_item(subtree, hf_mbim_pin_info_pin_type, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_pin_info_pin_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
attempts = tvb_get_letohl(frag_tvb, offset);
if (attempts == 0xffffffff) {
proto_tree_add_uint_format(subtree, hf_mbim_pin_info_remaining_attempts, frag_tvb, offset, 4,
attempts, "Not supported (0xffffffff)");
} else {
proto_tree_add_uint(subtree, hf_mbim_pin_info_remaining_attempts, frag_tvb, offset, 4, attempts);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PIN_LIST:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_pin_list_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_HOME_PROVIDER:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_provider(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PREFERRED_PROVIDERS:
mbim_dissect_providers(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_VISIBLE_PROVIDERS:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_providers(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_REGISTER_STATE:
mbim_dissect_registration_state_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_PACKET_SERVICE:
mbim_dissect_packet_service_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_SIGNAL_STATE:
mbim_dissect_signal_state_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_CONNECT:
mbim_dissect_connect_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_PROVISIONED_CONTEXTS:
mbim_dissect_provisioned_contexts_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_SERVICE_ACTIVATION:
if (msg_type == MBIM_COMMAND_DONE) {
guint32 nw_error;
nw_error = tvb_get_letohl(frag_tvb, offset);
if (nw_error == 0) {
proto_tree_add_uint_format_value(subtree, hf_mbim_service_activation_info_nw_error,
frag_tvb, offset, 4, nw_error, "Success (0)");
} else {
proto_tree_add_uint(subtree, hf_mbim_service_activation_info_nw_error,
frag_tvb, offset, 4, nw_error);
}
proto_tree_add_item(subtree, hf_mbim_service_activation_info_data_buffer, frag_tvb, offset, info_buff_len, ENC_NA);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_IP_CONFIGURATION:
mbim_dissect_ip_configuration_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_DEVICE_SERVICES:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_device_services_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_DEVICE_SERVICE_SUBSCRIBE_LIST:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_device_service_subscribe_list(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PACKET_STATISTICS:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_packet_statistics_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_NETWORK_IDLE_HINT:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_network_idle_hint_state, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_EMERGENCY_MODE:
proto_tree_add_item(subtree, hf_mbim_emergency_mode_info_emergency_mode, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case MBIM_CID_IP_PACKET_FILTERS:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_packet_filters(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_MULTICARRIER_PROVIDERS:
mbim_dissect_providers(frag_tvb, pinfo, subtree, offset);
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_SMS:
switch (cid) {
case MBIM_CID_SMS_CONFIGURATION:
mbim_dissect_sms_configuration_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_SMS_READ:
mbim_dissect_sms_read_info(frag_tvb, pinfo, subtree, offset, mbim_conv);
break;
case MBIM_CID_SMS_SEND:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_sms_send_info_message_reference, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SMS_DELETE:
if (msg_type == MBIM_COMMAND_DONE) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SMS_MESSAGE_STORE_STATUS:
proto_tree_add_bitmask(subtree, frag_tvb, offset, hf_mbim_sms_status_info_flags, ett_mbim_bitmap,
mbim_sms_status_info_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_sms_status_info_message_index, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_USSD:
switch (cid) {
case MBIM_CID_USSD:
mbim_dissect_ussd_info(frag_tvb, pinfo, subtree, offset);
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_PHONEBOOK:
switch (cid) {
case MBIM_CID_PHONEBOOK_CONFIGURATION:
mbim_dissect_phonebook_configuration_info(frag_tvb, pinfo, subtree, offset);
break;
case MBIM_CID_PHONEBOOK_READ:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_phonebook_read_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_PHONEBOOK_DELETE:
case MBIM_CID_PHONEBOOK_WRITE:
if (msg_type == MBIM_COMMAND_DONE) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_STK:
switch (cid) {
case MBIM_CID_STK_PAC:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_stk_pac_info(frag_tvb, pinfo, subtree, offset);
} else {
tvbuff_t *pac_tvb;
gint pac_length;
proto_tree *pac_tree;
proto_tree_add_item(subtree, hf_mbim_stk_pac_pac_type, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
pac_length = info_buff_len - 4;
ti = proto_tree_add_item(subtree, hf_mbim_stk_pac_pac, frag_tvb, offset, pac_length, ENC_NA);
if (bertlv_handle) {
pac_tree = proto_item_add_subtree(ti, ett_mbim_buffer);
pac_tvb = tvb_new_subset_length(frag_tvb, offset, pac_length);
call_dissector(bertlv_handle, pac_tvb, pinfo, pac_tree);
}
}
break;
case MBIM_CID_STK_TERMINAL_RESPONSE:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_stk_terminal_response_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_STK_ENVELOPE:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_stk_envelope_info_envelope_support,
frag_tvb, offset, 32, ENC_NA);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_AUTH:
switch (cid) {
case MBIM_CID_AKA_AUTH:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_aka_auth_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_AKAP_AUTH:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_akap_auth_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_SIM_AUTH:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_sim_auth_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_DSS:
switch (cid) {
case MBIM_CID_DSS_CONNECT:
if (msg_type == MBIM_COMMAND_DONE) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MULTICARRIER:
switch (cid) {
case MBIM_CID_MULTICARRIER_CAPABILITIES:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_bitmask(subtree, frag_tvb, offset, hf_mbim_multicarrier_capabilities_info_capabilities,
ett_mbim_bitmap, mbim_multicarrier_capabilities_fields, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_LOCATION_INFO:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_location_info_country, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
case MBIM_CID_MULTICARRIER_CURRENT_CID_LIST:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_muticarrier_current_cid_list_info(frag_tvb, pinfo, subtree, offset);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MS_HOSTSHUTDOWN:
switch (cid) {
case MBIM_CID_MS_HOSTSHUTDOWN:
if (msg_type == MBIM_COMMAND_DONE) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_MSFWID:
switch (cid) {
case MBIM_CID_MSFWID_FIRMWAREID:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_msfwid_firmwareid_info_firmware_id, frag_tvb, offset, 16, ENC_NA);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_QMI:
switch (cid) {
case MBIM_CID_QMI_QMI:
if (info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_qmi_buffer, frag_tvb, offset, info_buff_len, ENC_NA);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_FWUSVC:
switch (cid) {
case MBIM_CID_INTC_MODEM_REBOOT:
if (msg_type == MBIM_COMMAND_DONE) {
if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_DPTF:
switch (cid) {
case MBIM_CID_INTC_THERMAL_STATE:
if ((msg_type == MBIM_COMMAND_DONE) && mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) {
mbim_dissect_thermal_config(frag_tvb, pinfo, subtree, offset);
} else {
mbim_dissect_thermal_state_info(frag_tvb, pinfo, subtree, offset);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_SAR:
switch (cid) {
case MBIM_CID_INTC_SAR_CONFIG:
if (msg_type == MBIM_COMMAND_DONE) {
mbim_dissect_sar_config(frag_tvb, pinfo, subtree, offset, info_buff_len);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_ACT:
switch (cid) {
case MBIM_CID_INTC_ADPCLK_MODE:
if ((msg_type == MBIM_COMMAND_DONE) && info_buff_len &&
mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else {
mbim_dissect_adpclk_freq_info(frag_tvb, pinfo, subtree, offset);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_TRCSVC:
switch (cid) {
case MBIM_CID_INTC_TRACE:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_trace_config_config, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_INTC_TRACE_DATA:
if (msg_type == MBIM_COMMAND_DONE) {
proto_tree_add_item(subtree, hf_mbim_trace_config_config, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_NRTC:
switch (cid) {
case MBIM_CID_INTC_NRTAPP:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_nrtc_app_info_period, frag_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_mbim_nrtc_app_info_duration, frag_tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_INTC_NRTCWS:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
mbim_dissect_nrtcws_config(frag_tvb, pinfo, subtree, offset, info_buff_len);
}
} else {
mbim_dissect_nrtcws_info(frag_tvb, pinfo, subtree, offset);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_USB_PROFILE:
switch (cid) {
case MBIM_CID_INTC_USBPROFILE:
if ((msg_type == MBIM_COMMAND_DONE) && ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) || info_buff_len)) {
guint32 at_len;
proto_tree_add_item_ret_uint(subtree, hf_mbim_usbprofile_rsp_length, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN, &at_len);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_usbprofile_rsp_buffer, frag_tvb, offset, at_len, ENC_LITTLE_ENDIAN|ENC_UTF_16);
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_INTEL_CIQ:
switch (cid) {
case MBIM_CID_INTC_CIQ:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_ciq_info_mode, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_ATDS:
switch (cid) {
case MBIM_CID_ATDS_SIGNAL:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_atds_signal_info(frag_tvb, pinfo, subtree, offset);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_ATDS_LOCATION:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
proto_tree_add_item(subtree, hf_mbim_atds_location_info_lac, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_atds_location_info_tac, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_atds_location_info_cellid, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_ATDS_OPERATORS:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
mbim_dissect_atds_operators(frag_tvb, pinfo, subtree, offset);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_ATDS_RAT:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
proto_tree_add_item(subtree, hf_mbim_atds_rat_info_mode, frag_tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_ATDS_REGISTER_STATE:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET)) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
} else {
mbim_dissect_registration_state_info(frag_tvb, pinfo, subtree, offset);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
case MBIM_CID_ATDS_SET_PROJECTION_TABLES:
if (msg_type == MBIM_COMMAND_DONE) {
if (mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_SET) && info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
} else if ((mbim_info && (mbim_info->cmd_type == MBIM_COMMAND_QUERY)) || info_buff_len) {
mbim_dissect_atds_projection_tables(frag_tvb, pinfo, subtree, offset);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
break;
}
break;
case UUID_EXT_IDX:
{
gint cid_idx;
mbim_dissect_fct dissect_cid;
try_val_to_str_idx(cid, uuid_ext_info->uuid_cid_list, &cid_idx);
if (cid_idx != -1) {
dissect_cid = (msg_type == MBIM_COMMAND_DONE) ? uuid_ext_info->uuid_fct_list[cid_idx].cmd_done :
uuid_ext_info->uuid_fct_list[cid_idx].ind_status;
if (dissect_cid) {
dissect_cid(frag_tvb, pinfo, subtree, offset, mbim_info);
} else if (info_buff_len) {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_info_buffer, frag_tvb, offset, info_buff_len);
}
} else {
proto_tree_add_expert(subtree, pinfo, &ei_mbim_unexpected_msg, frag_tvb, offset, -1);
}
}
break;
default:
proto_tree_add_item(subtree, hf_mbim_info_buffer, frag_tvb, offset, info_buff_len, ENC_NA);
break;
}
}
break;
default:
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_mbim_descriptor(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *ti;
guint8 length, type, subtype;
length = tvb_get_guint8(tvb, 0);
type = tvb_get_guint8(tvb, 1);
subtype = tvb_get_guint8(tvb, 2);
if ((type != 0x24) ||
!(((subtype == 0x1b) && (length == 12)) || ((subtype == 0x1c) && (length == 8)))){
return 0;
}
ti = proto_tree_add_item(tree, hf_mbim_descriptor, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
if (subtype == 0x1b) {
proto_tree_add_item(tree, hf_mbim_descriptor_version, tvb, 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mbim_descriptor_max_control_message, tvb, 5, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mbim_descriptor_number_filters, tvb, 7, 1, ENC_NA);
proto_tree_add_item(tree, hf_mbim_descriptor_max_filter_size, tvb, 8, 1, ENC_NA);
proto_tree_add_item(tree, hf_mbim_descriptor_max_segment_size, tvb, 9, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 11, hf_mbim_descriptor_network_capabilities, ett_mbim_bitmap,
mbim_descriptor_network_capabilities_fields, ENC_NA);
} else {
proto_tree_add_item(tree, hf_mbim_descriptor_extended_version, tvb, 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mbim_descriptor_max_outstanding_command_messages, tvb, 5, 1, ENC_NA);
proto_tree_add_item(tree, hf_mbim_descriptor_mtu, tvb, 6, 2, ENC_LITTLE_ENDIAN);
}
return length;
}
static int
dissect_mbim_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *sig_ti, *pi;
proto_tree *mbim_tree, *subtree, *sig_tree;
gboolean is_32bits;
guint32 nth_sig, length, next_index, base_offset, offset, datagram_index, datagram_length,
nb, total = 0, ndp = 0, block_len, dss_session_id;
guint8 *signature;
dissector_handle_t dissector;
tvbuff_t *datagram_tvb;
const guint32 NTH16 = 0x484D434E;
const guint32 NTH32 = 0x686D636E;
guint reported_length;
if (tvb_captured_length(tvb) < 12) {
return 0;
}
nth_sig = tvb_get_letohl(tvb, 0);
if (nth_sig == NTH16) {
is_32bits = FALSE;
} else if (nth_sig == NTH32) {
is_32bits = TRUE;
} else {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MBIM");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_mbim, tvb, 0, -1, ENC_NA);
mbim_tree = proto_item_add_subtree(ti, ett_mbim);
ti =proto_tree_add_item(mbim_tree, hf_mbim_bulk, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti);
subtree = proto_tree_add_subtree(mbim_tree, tvb, 0, 0, ett_mbim_msg_header, NULL, "NCM Transfer Header");
proto_tree_add_item(subtree, hf_mbim_bulk_nth_signature, tvb, 0, 4, ENC_ASCII|ENC_NA);
proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_nth_header_length, tvb, 4, 2, ENC_LITTLE_ENDIAN, &length);
proto_item_set_len(ti, length);
proto_tree_add_item(subtree, hf_mbim_bulk_nth_sequence_number, tvb, 6, 2, ENC_LITTLE_ENDIAN);
if (!is_32bits) {
ti = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_nth_block_length, tvb, 8, 2, ENC_LITTLE_ENDIAN, &block_len);
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_nth_ndp_index, tvb, 10, 2, ENC_LITTLE_ENDIAN, &next_index);
} else {
ti = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_nth_block_length_32, tvb, 8, 4, ENC_LITTLE_ENDIAN, &block_len);
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_nth_ndp_index_32, tvb, 12, 4, ENC_LITTLE_ENDIAN, &next_index);
}
reported_length = tvb_reported_length(tvb);
if (block_len != reported_length) {
expert_add_info(pinfo, ti, &ei_mbim_invalid_block_len);
}
if (next_index % 4) {
expert_add_info_format(pinfo, pi, &ei_mbim_alignment_error,
"NDP Index is not a multiple of 4 bytes");
return tvb_captured_length(tvb);
}
if (next_index > reported_length) {
expert_add_info(pinfo, pi, &ei_mbim_out_of_bounds_index);
return tvb_captured_length(tvb);
}
while (next_index) {
base_offset = offset = next_index;
nb = 0;
subtree = proto_tree_add_subtree(mbim_tree, tvb, offset, 0, ett_mbim_msg_header, NULL, "NCM Datagram Pointer");
signature = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII);
if ((!is_32bits && !strncmp(signature, "IPS", 3)) ||
(is_32bits && !strncmp(signature, "ips", 3))) {
sig_ti = proto_tree_add_uint_format_value(subtree, hf_mbim_bulk_ndp_signature, tvb, offset,
4, tvb_get_letohl(tvb, offset), "%c%c%c%u", signature[0],
signature[1], signature[2], signature[3]);
sig_tree = proto_item_add_subtree(sig_ti, ett_mbim_msg_header);
proto_tree_add_item(sig_tree, hf_mbim_bulk_ndp_signature_ips_session_id, tvb, offset+3, 1, ENC_NA);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%c%c%c%u", signature[0], signature[1],
signature[2], signature[3]);
dissector = ip_handle;
} else if ((!is_32bits && !strncmp(signature, "DSS", 3)) ||
(is_32bits && !strncmp(signature, "dss", 3))) {
sig_ti = proto_tree_add_uint_format_value(subtree, hf_mbim_bulk_ndp_signature, tvb, offset,
4, tvb_get_letohl(tvb, offset), "%c%c%c%u", signature[0],
signature[1], signature[2], signature[3]);
sig_tree = proto_item_add_subtree(sig_ti, ett_mbim_msg_header);
proto_tree_add_item_ret_uint(sig_tree, hf_mbim_bulk_ndp_signature_dss_session_id,
tvb, offset+3, 1, ENC_LITTLE_ENDIAN, &dss_session_id);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%c%c%c%u", signature[0], signature[1],
signature[2], signature[3]);
dissector = dissector_get_uint_handle(dss_dissector_table, dss_session_id);
if (dissector == NULL) {
dissector = data_handle;
}
} else if ((!is_32bits && !strcmp(signature, "NCM0")) ||
(is_32bits && !strcmp(signature, "ncm0"))) {
proto_tree_add_uint_format_value(subtree, hf_mbim_bulk_ndp_signature, tvb, offset, 4,
tvb_get_letohl(tvb, offset), "%s", signature);
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, signature);
dissector = eth_handle;
} else if ((!is_32bits && !strcmp(signature, "NCM1")) ||
(is_32bits && !strcmp(signature, "ncm1"))) {
proto_tree_add_uint_format_value(subtree, hf_mbim_bulk_ndp_signature, tvb, offset, 4,
tvb_get_letohl(tvb, offset), "%s", signature);
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, signature);
dissector = eth_fcs_handle;
} else {
proto_tree_add_item(subtree, hf_mbim_bulk_ndp_signature, tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "0x%08X", tvb_get_ntohl(tvb, offset));
dissector = data_handle;
}
offset += 4;
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_length, tvb, offset, 2, ENC_LITTLE_ENDIAN, &length);
if (length % (is_32bits ? 8 : 4)) {
expert_add_info_format(pinfo, pi, &ei_mbim_alignment_error, "Length is not a multiple of %u bytes",
is_32bits ? 8 : 4);
return tvb_captured_length(tvb);
}
proto_item_set_len(ti, length);
offset += 2;
if (!is_32bits) {
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_next_ndp_index, tvb,
offset, 2, ENC_LITTLE_ENDIAN, &next_index);
offset += 2;
} else {
proto_tree_add_item(subtree, hf_mbim_bulk_ndp_reserved, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_next_ndp_index_32,
tvb, offset, 4, ENC_LITTLE_ENDIAN, &next_index);
offset += 4;
proto_tree_add_item(subtree, hf_mbim_bulk_ndp_reserved2, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
if (next_index % 4) {
expert_add_info_format(pinfo, pi, &ei_mbim_alignment_error,
"NDP Index is not a multiple of 4 bytes");
return tvb_captured_length(tvb);
}
if (next_index > reported_length) {
expert_add_info(pinfo, pi, &ei_mbim_out_of_bounds_index);
return tvb_captured_length(tvb);
}
while ((offset - base_offset) < length) {
if (!is_32bits) {
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_datagram_index, tvb,
offset, 2, ENC_LITTLE_ENDIAN, &datagram_index);
offset += 2;
proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_datagram_length, tvb,
offset, 2, ENC_LITTLE_ENDIAN, &datagram_length);
offset += 2;
} else {
pi = proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_datagram_index_32, tvb,
offset, 4, ENC_LITTLE_ENDIAN, &datagram_index);
offset += 4;
proto_tree_add_item_ret_uint(subtree, hf_mbim_bulk_ndp_datagram_length_32, tvb,
offset, 4, ENC_LITTLE_ENDIAN, &datagram_length);
offset += 4;
}
if (next_index > reported_length) {
expert_add_info(pinfo, pi, &ei_mbim_out_of_bounds_index);
return tvb_captured_length(tvb);
}
if (datagram_index && datagram_length) {
proto_tree_add_item(subtree, hf_mbim_bulk_ndp_datagram, tvb,
datagram_index, datagram_length, ENC_NA);
datagram_tvb = tvb_new_subset_length(tvb, datagram_index, datagram_length);
if (dissector) {
if (total) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "|");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_str(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
}
call_dissector(dissector, datagram_tvb, pinfo, tree);
}
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
col_set_fence(pinfo->cinfo, COL_INFO);
nb++;
if (++total > MBIM_MAX_ITEMS) {
expert_add_info_format(pinfo, NULL, &ei_mbim_too_many_items,
"More than %u datagrams, dissection seems suspicious",
MBIM_MAX_ITEMS);
return tvb_captured_length(tvb);
}
}
}
ti = proto_tree_add_uint(subtree, hf_mbim_bulk_ndp_nb_datagrams, tvb, 0, 0, nb);
PROTO_ITEM_SET_GENERATED(ti);
if (++ndp > MBIM_MAX_ITEMS) {
expert_add_info_format(pinfo, NULL, &ei_mbim_too_many_items,
"More than %u NCM Datagram Pointers, dissection seems suspicious",
MBIM_MAX_ITEMS);
return tvb_captured_length(tvb);
}
}
ti = proto_tree_add_uint(mbim_tree, hf_mbim_bulk_total_nb_datagrams, tvb, 0, 0, total);
PROTO_ITEM_SET_GENERATED(ti);
return tvb_captured_length(tvb);
}
static gboolean
dissect_mbim_bulk_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info = (usb_conv_info_t *)data;
if ((usb_conv_info == NULL) ||
((usb_conv_info->interfaceClass != IF_CLASS_CDC_DATA) &&
(usb_conv_info->interfaceClass != IF_CLASS_UNKNOWN))) {
return FALSE;
}
if (dissect_mbim_bulk(tvb, pinfo, tree, usb_conv_info)) {
return TRUE;
}
return FALSE;
}
static int
dissect_mbim_decode_as(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info;
if (!data || (tvb_reported_length(tvb) == 0)) {
return 0;
}
usb_conv_info = (usb_conv_info_t *)data;
usb_trans_info = usb_conv_info->usb_trans_info;
switch (usb_conv_info->transfer_type) {
case URB_CONTROL:
if (!usb_trans_info) {
return dissect_mbim_control(tvb, pinfo, tree, usb_conv_info);
}
if (((usb_trans_info->setup.request == 0x00) &&
(USB_HEADER_IS_LINUX(usb_trans_info->header_type) || (pinfo->srcport != NO_ENDPOINT))) ||
((usb_trans_info->setup.request == 0x01) && (pinfo->srcport != NO_ENDPOINT))) {
return dissect_mbim_control(tvb, pinfo, tree, usb_conv_info);
}
break;
case URB_BULK:
return dissect_mbim_bulk(tvb, pinfo, tree, usb_conv_info);
default:
break;
}
return 0;
}
static guint
mbim_uuid_hash(gconstpointer key)
{
return wmem_strong_hash((const guint8 *)key, 4*sizeof(guint32));
}
static gboolean
mbim_uuid_equal(gconstpointer v1, gconstpointer v2)
{
const guint32 *uuid1 = (const guint32*)v1;
const guint32 *uuid2 = (const guint32*)v2;
return ((uuid1[0] == uuid2[0]) &&
(uuid1[1] == uuid2[1]) &&
(uuid1[2] == uuid2[2]) &&
(uuid1[3] == uuid2[3]));
}
void mbim_register_uuid_ext(struct mbim_uuid_ext *uuid_ext)
{
guint32 *uuid_key;
if (!mbim_uuid_ext_hash) {
mbim_uuid_ext_hash = wmem_map_new(wmem_epan_scope(), mbim_uuid_hash, mbim_uuid_equal);
}
uuid_key = (guint32 *)wmem_alloc(wmem_epan_scope(), 4*sizeof(guint32));
memcpy(uuid_key, uuid_ext->uuid, 4*sizeof(guint32));
wmem_map_insert(mbim_uuid_ext_hash, uuid_key, uuid_ext);
}
void
proto_register_mbim(void)
{
module_t *mbim_module;
expert_module_t* expert_mbim;
static hf_register_info hf[] = {
{ &hf_mbim_control,
{ "Control", "mbim.control",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_header_message_type,
{ "Message Type", "mbim.control.header.message_type",
FT_UINT32, BASE_HEX, VALS(mbim_msg_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_header_message_length,
{ "Message Length", "mbim.control.header.message_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_header_transaction_id,
{ "Transaction Id", "mbim.control.header.transaction_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_total,
{ "Total Fragments", "mbim.control.fragment.total",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_current,
{ "Current Fragment", "mbim.control.fragment.current",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_max_ctrl_transfer,
{ "Max Control Transfer", "mbim.control.max_control_transfer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_id,
{ "Device Service Id", "mbim.control.device_service_id",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_basic_connect_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &mbim_uuid_basic_connect_cid_vals_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_sms_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_sms_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_ussd_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_ussd_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_phonebook_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_phonebook_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_stk_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_stk_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_auth_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_auth_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_dss_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_dss_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_multicarrier_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_multicarrier_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_ms_hostshutdown_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_ms_hostshutdown_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_msfwid_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_msfwid_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_qmi_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_qmi_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_fwusvc_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_fwusvc_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_dptf_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_dptf_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_sar_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_sar_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_act_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_act_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_trcsvc_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_trcsvc_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_nrtc_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_nrtc_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_usb_profile_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_usb_profile_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_intel_ciq_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_intel_ciq_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_uuid_atds_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_atds_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_cid,
{ "CID", "mbim.control.cid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_command_type,
{ "Command Type", "mbim.control.command_type",
FT_UINT32, BASE_DEC, VALS(mbim_command_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_info_buffer_len,
{ "Information Buffer Length", "mbim.control.info_buffer_len",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_info_buffer,
{ "Information Buffer", "mbim.control.info_buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_error_status_code,
{ "Error Status Code", "mbim.control.error_status_code",
FT_UINT32, BASE_DEC, VALS(mbim_error_status_code_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_status,
{ "Status", "mbim.control.status",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &mbim_status_code_vals_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_device_type,
{ "Device Type", "mbim.control.device_caps_info.device_type",
FT_UINT32, BASE_DEC, VALS(mbim_device_caps_info_device_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_cellular_class,
{ "Cellular Class", "mbim.control.device_caps_info.cellular_class",
FT_UINT32, BASE_DEC, VALS(mbim_cellular_class_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_voice_class,
{ "Voice Class", "mbim.control.device_caps_info.voice_class",
FT_UINT32, BASE_DEC, VALS(mbim_device_caps_info_voice_class_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sim_class,
{ "SIM Class", "mbim.control.device_caps_info.sim_class",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sim_class_logical,
{ "Logical", "mbim.control.device_caps_info.sim_class.logical",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sim_class_removable,
{ "Removable", "mbim.control.device_caps_info.sim_class.removable",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_data_class,
{ "Data Class", "mbim.control.device_caps_info.data_class",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_data_class_gprs,
{ "GPRS", "mbim.control.data_class.gprs",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_data_class_edge,
{ "EDGE", "mbim.control.data_class.edge",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_data_class_umts,
{ "UMTS", "mbim.control.data_class.umts",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_data_class_hsdpa,
{ "HSDPA", "mbim.control.data_class.hsdpa",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_data_class_hsupa,
{ "HSUPA", "mbim.control.data_class.hsupa",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_mbim_data_class_lte,
{ "LTE", "mbim.control.data_class.lte",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000020,
NULL, HFILL }
},
{ &hf_mbim_data_class_reserved_gsm,
{ "Reserved for future GSM classes", "mbim.control.data_class.reserved_gsm",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x0000ffc0,
NULL, HFILL }
},
{ &hf_mbim_data_class_1xrtt,
{ "1xRTT", "mbim.control.data_class.1xrtt",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00010000,
NULL, HFILL }
},
{ &hf_mbim_data_class_1xevdo,
{ "1xEV-DO", "mbim.control.data_class.1xevdo",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00020000,
NULL, HFILL }
},
{ &hf_mbim_data_class_1xevdoreva,
{ "1xEV-DO RevA", "mbim.control.data_class.1xevdoreva",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00040000,
NULL, HFILL }
},
{ &hf_mbim_data_class_1xevdv,
{ "1xEVDV", "mbim.control.data_class.1xevdv",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00080000,
NULL, HFILL }
},
{ &hf_mbim_data_class_3xrtt,
{ "3xRTT", "mbim.control.data_class.3xrtt",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00100000,
NULL, HFILL }
},
{ &hf_mbim_data_class_1xevdorevb,
{ "1xEV-DO RevB", "mbim.control.data_class.1xevdorevb",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00200000,
NULL, HFILL }
},
{ &hf_mbim_data_class_umb,
{ "UMB", "mbim.control.data_class.umb",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00400000,
NULL, HFILL }
},
{ &hf_mbim_data_class_reserved_cdma,
{ "Reserved for future CDMA classes", "mbim.control.data_class.reserved_cdma",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x7f800000,
NULL, HFILL }
},
{ &hf_mbim_data_class_custom,
{ "Custom", "mbim.control.data_class.custom",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x80000000,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sms_caps,
{ "SMS Caps", "mbim.control.device_caps_info.sms_caps",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sms_caps_pdu_receive,
{ "PDU Receive", "mbim.control.device_caps_info.sms_caps.pdu_receive",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sms_caps_pdu_send,
{ "PDU Send", "mbim.control.device_caps_info.sms_caps.pdu_send",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sms_caps_text_receive,
{ "Text Receive", "mbim.control.device_caps_info.sms_caps.text_receive",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_sms_caps_text_send,
{ "Text Send", "mbim.control.device_caps_info.sms_caps.text_send",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps,
{ "Control Caps", "mbim.control.device_caps_info.control_caps",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps_reg_manual,
{ "Reg Manual", "mbim.control.device_caps_info.control_caps.reg_manual",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps_hw_radio_switch,
{ "HW Radio Switch", "mbim.control.device_caps_info.control_caps.hw_radio_switch",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps_cdma_mobile_ip,
{ "CDMA Mobile IP", "mbim.control.device_caps_info.control_caps.cdma_mobile_ip",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps_cdma_simple_ip,
{ "CDMA Simple IP", "mbim.control.device_caps_info.control_caps.cdma_simple_ip",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_control_caps_multi_carrier,
{ "Multi Carrier", "mbim.control.device_caps_info.control_caps.multi_carrier",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000010,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_max_sessions,
{ "Max Sessions", "mbim.control.device_caps_info.max_sessions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_custom_data_class_offset,
{ "Custom Data Class Offset", "mbim.control.device_caps_info.custom_data_class.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_custom_data_class_size,
{ "Custom Data Class Size", "mbim.control.device_caps_info.custom_data_class.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_device_id_offset,
{ "Device Id Offset", "mbim.control.device_caps_info.device_id.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_device_id_size,
{ "Device Id Size", "mbim.control.device_caps_info.device_id.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_fw_info_offset,
{ "FW Info Offset", "mbim.control.device_caps_info.fw_info.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_fw_info_size,
{ "FW Info Size", "mbim.control.device_caps_info.fw_info.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_hw_info_offset,
{ "HW Info Offset", "mbim.control.device_caps_info.hw_info.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_hw_info_size,
{ "HW Info Size", "mbim.control.device_caps_info.hw_info.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_custom_data_class,
{ "Custom Data Class", "mbim.control.device_caps_info.custom_data_class",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_device_id,
{ "Device Id", "mbim.control.device_caps_info.device_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_fw_info,
{ "FW Info", "mbim.control.device_caps_info.fw_info",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_caps_info_hw_info,
{ "HW Info", "mbim.control.device_caps_info.hw_info",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_ready_state,
{ "Ready State", "mbim.control.subscriber_ready_status.ready_state",
FT_UINT32, BASE_DEC, VALS(mbim_subscr_ready_status_ready_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_susbcr_id_offset,
{ "Subscriber Id Offset", "mbim.control.subscriber_ready_status.susbcriber_id.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_susbcr_id_size,
{ "Subscriber Id Size", "mbim.control.subscriber_ready_status.susbcriber_id.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_sim_icc_id_offset,
{ "SIM ICC Id Offset", "mbim.control.subscriber_ready_status.sim_icc_id.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_sim_icc_id_size,
{ "SIM ICC Id Size", "mbim.control.subscriber_ready_status.sim_icc_id.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_ready_info,
{ "Ready Info", "mbim.control.subscriber_ready_status.ready_info",
FT_UINT32, BASE_DEC, VALS(mbim_subscr_ready_status_ready_info_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_elem_count,
{ "Element Count", "mbim.control.subscriber_ready_status.element_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_tel_nb_offset,
{ "Telephone Number Offset", "mbim.control.subscriber_ready_status.tel_nb.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_tel_nb_size,
{ "Telephone Number Size", "mbim.control.subscriber_ready_status.tel_nb.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_susbcr_id,
{ "Subscriber Id", "mbim.control.device_caps_info.subscriber_ready_status.susbcriber_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_sim_icc_id,
{ "SIM ICC Id", "mbim.control.device_caps_info.subscriber_ready_status.sim_icc_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_subscr_ready_status_tel_nb,
{ "Telephone Number", "mbim.control.device_caps_info.subscriber_ready_status.tel_nb",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_radio_state_set,
{ "Radio Set", "mbim.control.radio_state.set",
FT_UINT32, BASE_DEC, VALS(mbim_radio_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_radio_state_hw_radio_state,
{ "HW Radio State", "mbim.control.radio_state.hw_radio_state",
FT_UINT32, BASE_DEC, VALS(mbim_radio_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_radio_state_sw_radio_state,
{ "SW Radio State", "mbim.control.radio_state.sw_radio_stat",
FT_UINT32, BASE_DEC, VALS(mbim_radio_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_pin_type,
{ "PIN Type", "mbim.control.set_pin.pin_type",
FT_UINT32, BASE_DEC, VALS(mbim_pin_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_pin_pin_operation,
{ "PIN Operation", "mbim.control.set_pin.pin_operation",
FT_UINT32, BASE_DEC, VALS(mbim_pin_operation_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_pin_pin_offset,
{ "PIN Offset", "mbim.control.set_pin.pin.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_pin_pin_size,
{ "PIN Size", "mbim.control.set_pin.pin.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_new_pin_offset,
{ "New PIN Offset", "mbim.control.set_pin.new_pin.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_new_pin_size,
{ "New PIN Size", "mbim.control.set_pin.new_pin.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_pin,
{ "PIN", "mbim.control.set_pin.pin",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_pin_new_pin,
{ "New PIN", "mbim.control.set_pin.new_pin",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_pin_info_pin_type,
{ "PIN Type", "mbim.control.pin_info.pin_type",
FT_UINT32, BASE_DEC, VALS(mbim_pin_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_pin_info_pin_state,
{ "PIN State", "mbim.control.pin_info.pin_state",
FT_UINT32, BASE_DEC, VALS(mbim_pin_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_pin_info_remaining_attempts,
{ "Remaining Attempts", "mbim.control.pin_info.remaining_attempts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_pin_list_pin_mode,
{ "PIN Mode", "mbim.control.pin_list.pin_mode",
FT_UINT32, BASE_DEC, VALS(mbim_pin_mode_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_pin_list_pin_format,
{ "PIN Format", "mbim.control.pin_list.pin_format",
FT_UINT32, BASE_DEC, VALS(mbim_pin_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_pin_list_pin_length_min,
{ "PIN Length Min", "mbim.control.pin_list.pin_length_min",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_pin_list_pin_length_max,
{ "PIN Length Max", "mbim.control.pin_list.pin_length_max",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_state,
{ "Provider State", "mbim.control.provider_state",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_state_home,
{ "Home", "mbim.control.provider_state.home",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_provider_state_forbidden,
{ "Forbidden", "mbim.control.provider_state.forbidden",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_provider_state_preferred,
{ "Preferred", "mbim.control.provider_state.preferred",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_provider_state_visible,
{ "Visible", "mbim.control.provider_state.visible",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_provider_state_registered,
{ "Registered", "mbim.control.provider_state.registered",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000010,
NULL, HFILL }
},
{ &hf_mbim_provider_state_preferred_multicarrier,
{ "Preferred Multicarrier", "mbim.control.provider_state.preferred_multicarrier",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000020,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_id_offset,
{ "Provider Id Offset", "mbim.control.provider.provider_id_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_id_size,
{ "Provider Id Size", "mbim.control.provider.provider_id_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_name_offset,
{ "Provider Name Offset", "mbim.control.provider.provider_name_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_name_size,
{ "Provider Name Size", "mbim.control.provider.provider_name_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_cellular_class,
{ "Cellular Class", "mbim.control.provider.cellular_class",
FT_UINT32, BASE_DEC, VALS(mbim_cellular_class_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_provider_rssi,
{ "RSSI", "mbim.control.provider.rssi",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rssi_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_provider_error_rate,
{ "Error Rate", "mbim.control.provider.error_rate",
FT_UINT32, BASE_DEC, VALS(mbim_error_rate_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_id,
{ "Provider Id", "mbim.control.provider.provider_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provider_provider_name,
{ "Provider Name", "mbim.control.provider.provider_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_providers_elem_count,
{ "Element Count", "mbim.control.providers.elem_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_providers_provider_offset,
{ "Provider Offset", "mbim.control.providers.provider_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_providers_provider_size,
{ "Provider Size", "mbim.control.providers.provider_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_visible_providers_req_action,
{ "Action", "mbim.control.visible_providers_req.action",
FT_UINT32, BASE_DEC, VALS(mbim_visible_providers_action_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_register_state_provider_id_offset,
{ "Provider Id Offset", "mbim.control.set_register_state.provider_id.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_register_state_provider_id_size,
{ "Provider Id Size", "mbim.control.set_register_state.provider_id.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_register_state_register_action,
{ "Register Action", "mbim.control.set_register_state.register_action",
FT_UINT32, BASE_DEC, VALS(mbim_register_action_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_register_state_data_class,
{ "Data Class", "mbim.control.set_register_state.data_class",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_register_state_provider_id,
{ "Provider Id", "mbim.control.set_register_state.provider_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_nw_error,
{ "Network Error", "mbim.control.registration_state_info.nw_error",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &nas_eps_emm_cause_values_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_register_state,
{ "Register State", "mbim.control.registration_state_info.register_state",
FT_UINT32, BASE_DEC, VALS(mbim_register_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_register_mode,
{ "Register Mode", "mbim.control.registration_state_info.register_mode",
FT_UINT32, BASE_DEC, VALS(mbim_register_mode_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_available_data_classes,
{ "Available Data Classes", "mbim.control.registration_state_info.available_data_classes",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_current_cellular_class,
{ "Current Cellular Class", "mbim.control.registration_state_info.current_cellular_class",
FT_UINT32, BASE_DEC, VALS(mbim_cellular_class_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_id_offset,
{ "Provider Id Offset", "mbim.control.registration_state_info.provider_id.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_id_size,
{ "Provider Id Size", "mbim.control.registration_state_info.provider_id.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_name_offset,
{ "Provider Name Offset", "mbim.control.registration_state_info.provider_name.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_name_size,
{ "Provider Name Size", "mbim.control.registration_state_info.provider_name.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_roaming_text_offset,
{ "Roaming Text Offset", "mbim.control.registration_state_info.roaming_text.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_roaming_text_size,
{ "Roaming Text Size", "mbim.control.registration_state_info.roaming_text.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_registration_flags,
{ "Registration Flags", "mbim.control.registration_state_info.registration_flags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_registration_flags_manual_selection_not_available,
{ "Manual Selection Not Available", "mbim.control.registration_state_info.registration_flags.manual_selection_not_available",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_registration_flags_packet_service_auto_attach,
{ "Packet Service Auto Attach", "mbim.control.registration_state_info.registration_flags.packet_service_auto_attach",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_id,
{ "Provider Id", "mbim.control.registration_state_info.provider_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_provider_name,
{ "Provider Name", "mbim.control.registration_state_info.provider_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_registration_state_info_roaming_text,
{ "Roaming Text", "mbim.control.registration_state_info.roaming_text",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_packet_service_action,
{ "Action", "mbim.control.set_packet_service.action",
FT_UINT32, BASE_DEC, VALS(mbim_packet_service_action_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_packet_service_info_nw_error,
{ "Network Error", "mbim.control.packet_service_info.nw_error",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &nas_eps_emm_cause_values_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_service_info_packet_service_state,
{ "Packet Service State", "mbim.control.packet_service_info.packet_service_state",
FT_UINT32, BASE_DEC, VALS(mbim_packet_service_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_packet_service_info_highest_available_data_class,
{ "Highest Available Data Class", "mbim.control.packet_service_info.highest_available_data_class",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_service_info_uplink_speed,
{ "Uplink Speed", "mbim.control.packet_service_info.uplink_speed",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_service_info_downlink_speed,
{ "Downlink Speed", "mbim.control.packet_service_info.downlink_speed",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_bit_sec, 0,
NULL, HFILL }
},
{ &hf_mbim_set_signal_state_signal_strength_interval,
{ "Signal Strength Interval", "mbim.control.set_signal_state.signal_strength_interval",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }
},
{ &hf_mbim_set_signal_state_rssi_threshold,
{ "RSSI Threshold", "mbim.control.set_signal_state.rssi_threshold",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_signal_state_error_rate_threshold,
{ "Error Rate Threshold", "mbim.control.set_signal_state.error_rate_threshold",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_signal_state_info_rssi,
{ "RSSI", "mbim.control.signal_state_info.rssi",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rssi_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_signal_state_info_error_rate,
{ "Error Rate", "mbim.control.signal_state_info.error_rate",
FT_UINT32, BASE_DEC, VALS(mbim_error_rate_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_signal_state_info_signal_strength_interval,
{ "Signal Strength Interval", "mbim.control.signal_state_info.signal_strength_interval",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }
},
{ &hf_mbim_signal_state_info_rssi_threshold,
{ "RSSI Threshold", "mbim.control.signal_state_info.rssi_threshold",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_signal_state_info_error_rate_threshold,
{ "Error Rate Threshold", "mbim.control.signal_state_info.error_rate_threshold",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_type,
{ "Context Type", "mbim.control.context_type",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_session_id,
{ "Session Id", "mbim.control.set_connect.session_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_activation_command,
{ "Activation Command", "mbim.control.set_connect.activation_command",
FT_UINT32, BASE_DEC, VALS(mbim_activation_command_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_access_string_offset,
{ "Access String Offset", "mbim.control.set_connect.access_string_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_access_string_size,
{ "Access String Size", "mbim.control.set_connect.access_string_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_user_name_offset,
{ "User Name Offset", "mbim.control.set_connect.user_name_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_user_name_size,
{ "User Name Size", "mbim.control.set_connect.user_name_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_password_offset,
{ "Password Offset", "mbim.control.set_connect.password_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_password_size,
{ "Password Size", "mbim.control.set_connect.password_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_compression,
{ "Compression", "mbim.control.set_connect.compression",
FT_UINT32, BASE_DEC, VALS(mbim_compression_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_auth_protocol,
{ "Authentication Protocol", "mbim.control.set_connect.auth_protocol",
FT_UINT32, BASE_DEC, VALS(mbim_auth_protocol_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_ip_type,
{ "IP Type", "mbim.control.set_connect.ip_type",
FT_UINT32, BASE_DEC, VALS(mbim_context_ip_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_access_string,
{ "Access String", "mbim.control.set_connect.access_string",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_user_name,
{ "User Name", "mbim.control.set_connect.user_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_connect_password,
{ "Password", "mbim.control.set_connect.password",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_connect_info_session_id,
{ "Session Id", "mbim.control.connect_info.session_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_connect_info_activation_state,
{ "Activation State", "mbim.control.connect_info.activation_state",
FT_UINT32, BASE_DEC, VALS(mbim_activation_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_connect_info_voice_call_state,
{ "Voice Call State", "mbim.control.connect_info.voice_call_state",
FT_UINT32, BASE_DEC, VALS(mbim_voice_call_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_connect_info_ip_type,
{ "IP Type", "mbim.control.connect_info.ip_type",
FT_UINT32, BASE_DEC, VALS(mbim_context_ip_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_connect_info_nw_error,
{ "Network Error", "mbim.control.connect_info.nw_error",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &nas_eps_emm_cause_values_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_context_context_id,
{ "Context Id", "mbim.control.context.context_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_access_string_offset,
{ "Access String Offset", "mbim.control.context.access_string_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_access_string_size,
{ "Access String Size", "mbim.control.context.access_string_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_user_name_offset,
{ "User Name Offset", "mbim.control.context.user_name_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_user_name_size,
{ "User Name Size", "mbim.control.context.user_name_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_password_offset,
{ "Password Offset", "mbim.control.context.password_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_password_size,
{ "Password Size", "mbim.control.context.password_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_compression,
{ "Compression", "mbim.control.context.compression",
FT_UINT32, BASE_DEC, VALS(mbim_compression_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_context_auth_protocol,
{ "Authentication Protocol", "mbim.control.context.auth_protocol",
FT_UINT32, BASE_DEC, VALS(mbim_auth_protocol_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_context_provider_id_offset,
{ "Provider Id Offset", "mbim.control.context.provider_id_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_provider_id_size,
{ "Provider Id Size", "mbim.control.context.provider_id_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_access_string,
{ "Access String", "mbim.control.context.access_string",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_user_name,
{ "User Name", "mbim.control.context.user_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_password,
{ "Password", "mbim.control.context.password",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_context_provider_id,
{ "Provider Id", "mbim.control.context.provider_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provisioned_contexts_info_elem_count,
{ "Element Count", "mbim.control.context.provisioned_contexts_info.elem_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provisioned_contexts_info_provisioned_context_offset,
{ "Provisioned Context Offset", "mbim.control.context.provisioned_contexts_info.provisioned_context_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_provisioned_contexts_info_provisioned_context_size,
{ "Provisioned Context Size", "mbim.control.context.provisioned_contexts_info.provisioned_context_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_service_activation_data_buffer,
{ "Data Buffer", "mbim.control.set_service_activation.data_buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_service_activation_info_nw_error,
{ "Network Error", "mbim.control.service_activation_info.nw_error",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &nas_eps_emm_cause_values_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_service_activation_info_data_buffer,
{ "Data Buffer", "mbim.control.service_activation_info.data_buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ipv4_element_on_link_prefix_length,
{ "On Link Prefix Length", "mbim.control.ipv4_element.on_link_prefix_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ipv4_element_ipv4_address,
{ "IPv4 Address", "mbim.control.ipv4_element.ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ipv6_element_on_link_prefix_length,
{ "On Link Prefix Length", "mbim.control.ipv6_element.on_link_prefix_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ipv6_element_ipv6_address,
{ "IPv6 Address", "mbim.control.ipv6_element.ipv6_address",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_session_id,
{ "Session Id", "mbim.control.ip_configuration_info.session_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_configuration_available,
{ "IPv4 Configuration Available", "mbim.control.ip_configuration_info.ipv4_configuration_available",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_configuration_available_address,
{ "Address", "mbim.control.ip_configuration_info.control_caps.ipv4_configuration_available.address",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_configuration_available_gateway,
{ "Gateway", "mbim.control.ip_configuration_info.control_caps.ipv4_configuration_available.gateway",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_configuration_available_dns,
{ "DNS Server", "mbim.control.ip_configuration_info.control_caps.ipv4_configuration_available.dns",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_configuration_available_mtu,
{ "MTU", "mbim.control.ip_configuration_info.control_caps.ipv4_configuration_available.mtu",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_configuration_available,
{ "IPv6 Configuration Available", "mbim.control.ip_configuration_info.ipv6_configuration_available",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_configuration_available_address,
{ "Address", "mbim.control.ip_configuration_info.control_caps.ipv6_configuration_available.address",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_configuration_available_gateway,
{ "Gateway", "mbim.control.ip_configuration_info.control_caps.ipv6_configuration_available.gateway",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_configuration_available_dns,
{ "DNS Server", "mbim.control.ip_configuration_info.control_caps.ipv6_configuration_available.dns",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000004,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_configuration_available_mtu,
{ "MTU", "mbim.control.ip_configuration_info.control_caps.ipv6_configuration_available.mtu",
FT_BOOLEAN, 32, TFS(&tfs_available_not_available), 0x00000008,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_address_count,
{ "IPv4 Address Count", "mbim.control.ip_configuration_info.ipv4_address.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_address_offset,
{ "IPv4 Address Offset", "mbim.control.ip_configuration_info.ipv4_address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_address_count,
{ "IPv6 Address Count", "mbim.control.ip_configuration_info.ipv6_address.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_address_offset,
{ "IPv6 Address Offset", "mbim.control.ip_configuration_info.ipv6_address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_gateway_offset,
{ "IPv4 Gateway Offset", "mbim.control.ip_configuration_info.ipv4_gateway.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_gateway_offset,
{ "IPv6 Gateway Offset", "mbim.control.ip_configuration_info.ipv6_gateway.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_dns_count,
{ "IPv4 DNS Server Count", "mbim.control.ip_configuration_info.ipv4_dns.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_dns_offset,
{ "IPv4 DNS Server Offset", "mbim.control.ip_configuration_info.ipv4_dns.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_dns_count,
{ "IPv6 DNS Server Count", "mbim.control.ip_configuration_info.ipv6_dns.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_dns_offset,
{ "IPv6 DNS Server Offset", "mbim.control.ip_configuration_info.ipv6_dns.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_mtu,
{ "IPv4 MTU", "mbim.control.ip_configuration_info.ipv4_mtu",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_mtu,
{ "IPv6 MTU", "mbim.control.ip_configuration_info.ipv6_mtu",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_gateway,
{ "IPv4 Gateway", "mbim.control.ip_configuration_info.ipv4_gateway",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_gateway,
{ "IPv6 Gateway", "mbim.control.ip_configuration_info.ipv6_gateway",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv4_dns,
{ "IPv4 DNS Server", "mbim.control.ip_configuration_info.ipv4_dns",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ip_configuration_info_ipv6_dns,
{ "IPv6 DNS Server", "mbim.control.ip_configuration_info.ipv6_dns",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_device_service_id,
{ "Device Service Id", "mbim.control.device_service_element.device_service_id",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_dss_payload,
{ "DSS Payload", "mbim.control.device_service_element.dss_payload",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_dss_payload_host_device,
{ "Host To Device", "mbim.control.device_service_element.dss_payload.host_device",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_dss_payload_device_host,
{ "Device To Host", "mbim.control.device_service_element.dss_payload.device_host",
FT_BOOLEAN, 32, TFS(&tfs_supported_not_supported), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_max_dss_instances,
{ "Max DSS Instances", "mbim.control.device_service_element.max_dss_instances",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_cid_count,
{ "CID Count", "mbim.control.device_service_element.cid.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_element_cid,
{ "CID", "mbim.control.device_service_element.cid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_services_info_device_services_count,
{ "Device Services Count", "mbim.control.device_services_info.device_services_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_services_info_max_dss_sessions,
{ "Max DSS Sessions", "mbim.control.device_services_info.max_dss_sessions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_services_info_device_services_offset,
{ "Device Services Offset", "mbim.control.device_services_info.device_services.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_services_info_device_services_size,
{ "Device Services Size", "mbim.control.device_services_info.device_services.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_event_entry_device_service_id,
{ "Device Service Id", "mbim.control.event_entry.device_service_id",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_event_entry_cid_count,
{ "CID Count", "mbim.control.event_entry.cid.count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_event_entry_cid,
{ "CID", "mbim.control.event_entry.cid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_subscribe_element_count,
{ "Element Count", "mbim.control.device_service_subscribe.element_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_subscribe_device_service_offset,
{ "Device Service Offset", "mbim.control.device_service_subscribe.device_service.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_device_service_subscribe_device_service_size,
{ "Device Service Size", "mbim.control.device_service_subscribe.device_service.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_in_discards,
{ "In Discards", "mbim.control.packet_statistics_info.in_discards",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_in_errors,
{ "In Errors", "mbim.control.packet_statistics_info.in_errors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_in_octets,
{ "In Octets", "mbim.control.packet_statistics_info.in_octets",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_in_packets,
{ "In Packets", "mbim.control.packet_statistics_info.in_packets",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_out_octets,
{ "Out Octets", "mbim.control.packet_statistics_info.out_octets",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_out_packets,
{ "Out Packets", "mbim.control.packet_statistics_info.out_packets",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_out_errors,
{ "Out Errors", "mbim.control.packet_statistics_info.out_errors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_statistics_info_out_discards,
{ "Out Discards", "mbim.control.packet_statistics_info.out_discards",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_network_idle_hint_state,
{ "Network Idle Hint State", "mbim.control.network_idle_hint.state",
FT_UINT32, BASE_DEC, VALS(mbim_network_idle_hint_states_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_emergency_mode_info_emergency_mode,
{ "Emergency Mode", "mbim.control.emergency_mode_info.mode",
FT_UINT32, BASE_DEC, VALS(mbim_emergency_mode_states_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_single_packet_filter_filter_size,
{ "Filter Size", "mbim.control.single_packet_filter.filter_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_single_packet_filter_packet_filter_offset,
{ "Packet Filter Offset", "mbim.control.single_packet_filter.packet_filter.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_single_packet_filter_packet_mask_offset,
{ "Packet Mask Offset", "mbim.control.single_packet_filter.packet_mask.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_single_packet_filter_packet_filter,
{ "Packet Filter", "mbim.control.single_packet_filter.packet_filter",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_single_packet_filter_packet_mask,
{ "Packet Mask", "mbim.control.single_packet_filter.packet_mask",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_filters_session_id,
{ "Session Id", "mbim.control.packet_filters.session_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_filters_packet_filters_count,
{ "Packet Filters Count", "mbim.control.packet_filters.packet_filters_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_filters_packet_filters_packet_filter_offset,
{ "Packet Filter Offset", "mbim.control.packet_filters.packet_filter.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_packet_filters_packet_filters_packet_filter_size,
{ "Packet Filters Size", "mbim.control.packet_filters.packet_filter.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_configuration_format,
{ "Format", "mbim.control.set_sms_configuration.format",
FT_UINT32, BASE_DEC, VALS(mbim_sms_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_configuration_sc_address_offset,
{ "Service Center Address Offset", "mbim.control.set_sms_configuration.sc_address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_configuration_sc_address_size,
{ "Service Center Address Size", "mbim.control.set_sms_configuration.sc_address.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_configuration_sc_address,
{ "Service Center Address", "mbim.control.set_sms_configuration.sc_address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_sms_storage_state,
{ "SMS Storage State", "mbim.control.sms_configuration_info.sms_storage_state",
FT_UINT32, BASE_DEC, VALS(mbim_sms_storage_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_format,
{ "Format", "mbim.control.sms_configuration_info.format",
FT_UINT32, BASE_DEC, VALS(mbim_sms_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_max_messages,
{ "Max Messages", "mbim.control.sms_configuration_info.max_messages",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_cdma_short_message_size,
{ "CDMA Short Message Size", "mbim.control.sms_configuration_info.cdma_short_message_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_sc_address_offset,
{ "Service Center Address Offset", "mbim.control.sms_configuration_info.sc_address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_sc_address_size,
{ "Service Center Address Size", "mbim.control.sms_configuration_info.sc_address.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_configuration_info_sc_address,
{ "Service Center Address Size", "mbim.control.sms_configuration_info.sc_address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_message_index,
{ "Message Index", "mbim.control.sms_pdu_record.message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_message_status,
{ "Message Status", "mbim.control.sms_pdu_record.message_status",
FT_UINT32, BASE_DEC, VALS(mbim_sms_message_status_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_pdu_data_offset,
{ "PDU Data Offset", "mbim.control.sms_pdu_record.pdu_data.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_pdu_data_size,
{ "PDU Data Size", "mbim.control.sms_pdu_record.pdu_data.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_pdu_data,
{ "PDU Data", "mbim.control.sms_pdu_record.pdu_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_pdu_record_pdu_data_sc_address_size,
{ "Size", "mbim.control.sms_pdu_record.pdu_data.sc_address_size",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_message_index,
{ "Message Index", "mbim.control.sms_cdma_record.message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_message_status,
{ "Message Status", "mbim.control.sms_cdma_record.message_status",
FT_UINT32, BASE_DEC, VALS(mbim_sms_message_status_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_address_offset,
{ "Address Offset", "mbim.control.sms_cdma_record.address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_address_size,
{ "Address Size", "mbim.control.sms_cdma_record.address.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_timestamp_offset,
{ "Timestamp Offset", "mbim.control.sms_cdma_record.timestamp.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_timestamp_size,
{ "Timestamp Size", "mbim.control.sms_cdma_record.timestamp.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_encoding_id,
{ "Encoding Id", "mbim.control.sms_cdma_record.encoding_id",
FT_UINT32, BASE_DEC, VALS(mbim_sms_cdma_encoding_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_language_id,
{ "Language Id", "mbim.control.sms_cdma_record.language_id",
FT_UINT32, BASE_DEC, VALS(mbim_sms_cdma_lang_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_encoded_message_offset,
{ "Encoded Message Offset", "mbim.control.sms_cdma_record.encoded_message.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_size_in_bytes,
{ "Size In Bytes", "mbim.control.sms_cdma_record.size_in_bytes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_size_in_characters,
{ "Size In Characters", "mbim.control.sms_cdma_record.size_in_characters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_address,
{ "Address", "mbim.control.sms_cdma_record.address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_timestamp,
{ "Timestamp", "mbim.control.sms_cdma_record.timestamp",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_encoded_message,
{ "Encoded Message", "mbim.control.sms_cdma_record.encoded_message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_cdma_record_encoded_message_text,
{ "Text", "mbim.control.sms_cdma_record.encoded_message.text",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_req_format,
{ "Format", "mbim.control.sms_read_req.format",
FT_UINT32, BASE_DEC, VALS(mbim_sms_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_req_flag,
{ "Flag", "mbim.control.sms_read_req.flag",
FT_UINT32, BASE_DEC, VALS(mbim_sms_flag_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_req_message_index,
{ "Message Index", "mbim.control.sms_read_req.message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_info_format,
{ "Format", "mbim.control.sms_read_info.format",
FT_UINT32, BASE_DEC, VALS(mbim_sms_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_info_element_count,
{ "Element Count", "mbim.control.sms_read_info.element_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_info_sms_offset,
{ "SMS Offset", "mbim.control.sms_read_info.sms.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_read_info_sms_size,
{ "SMS Size", "mbim.control.sms_read_info.sms.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_pdu_pdu_data_offset,
{ "PDU Data Offset", "mbim.control.sms_send_pdu.pdu_data.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_pdu_pdu_data_size,
{ "PDU Data Size", "mbim.control.sms_send_pdu.pdu_data.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_pdu_pdu_data,
{ "PDU Data", "mbim.control.sms_send_pdu.pdu_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_pdu_pdu_data_sc_address_size,
{ "Size", "mbim.control.sms_send_pdu.pdu_data.sc_address_size",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_encoding_id,
{ "Encoding Id", "mbim.control.sms_send_cdma.encoding_id",
FT_UINT32, BASE_DEC, VALS(mbim_sms_cdma_encoding_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_language_id,
{ "Language Id", "mbim.control.sms_send_cdma.language_id",
FT_UINT32, BASE_DEC, VALS(mbim_sms_cdma_lang_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_address_offset,
{ "Address Offset", "mbim.control.sms_send_cdma.address.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_address_size,
{ "Address Size", "mbim.control.sms_send_cdma.address.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_encoded_message_offset,
{ "Encoded Message Offset", "mbim.control.sms_send_cdma.encoded_message.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_size_in_bytes,
{ "Size In Bytes", "mbim.control.sms_send_cdma.size_in_bytes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_size_in_characters,
{ "Size In Characters", "mbim.control.sms_send_cdma.size_in_characters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_address,
{ "Address", "mbim.control.sms_send_cdma.address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_encoded_message,
{ "Encoded Message", "mbim.control.sms_send_cdma.encoded_message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_cdma_encoded_message_text,
{ "Text", "mbim.control.sms_send_cdma.encoded_message.text",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_send_format,
{ "Format", "mbim.control.set_sms_send.format",
FT_UINT32, BASE_DEC, VALS(mbim_sms_format_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sms_send_info_message_reference,
{ "Message Reference", "mbim.control.sms_send_info.message_reference",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_delete_flag,
{ "Flag", "mbim.control.set_sms_delete.flag",
FT_UINT32, BASE_DEC, VALS(mbim_sms_flag_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_sms_delete_message_index,
{ "Message Index", "mbim.control.set_sms_delete.message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_status_info_flags,
{ "Flags", "mbim.control.sms_status_info.flags",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sms_status_info_flags_message_store_full,
{ "Message Store Full", "mbim.control.sms_status_info.flags.message_store_full",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_sms_status_info_flags_new_message,
{ "New Message", "mbim.control.sms_status_info.flags.new_message",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_sms_status_info_message_index,
{ "Message Index", "mbim.control.sms_status_info.message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_action,
{ "USSD Action", "mbim.control.set_ussd.ussd_action",
FT_UINT32, BASE_DEC, VALS(mbim_ussd_action_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_data_coding_scheme,
{ "USSD Data Coding Scheme", "mbim.control.set_ussd.ussd_data_coding_scheme",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_payload_offset,
{ "USSD Payload Offset", "mbim.control.set_ussd.ussd_payload.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_payload_length,
{ "USSD Payload Length", "mbim.control.set_ussd.ussd_payload.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_payload,
{ "USSD Payload", "mbim.control.set_ussd.ussd_payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_ussd_ussd_payload_text,
{ "USSD Payload Text", "mbim.control.set_ussd.ussd_payload.text",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_response,
{ "USSD Response", "mbim.control.info_ussd.ussd_response",
FT_UINT32, BASE_DEC, VALS(mbim_ussd_response_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_session_state,
{ "USSD Session State", "mbim.control.info_ussd.ussd_session_state",
FT_UINT32, BASE_DEC, VALS(mbim_ussd_session_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_data_coding_scheme,
{ "USSD Data Coding Scheme", "mbim.control.ussd_info.ussd_data_coding_scheme",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_payload_offset,
{ "USSD Payload Offset", "mbim.control.ussd_info.ussd_payload.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_payload_length,
{ "USSD Payload Length", "mbim.control.ussd_info.ussd_payload.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_payload,
{ "USSD Payload", "mbim.control.ussd_info.ussd_payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ussd_info_ussd_payload_text,
{ "USSD Payload Text", "mbim.control.ussd_info.ussd_payload.text",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_configuration_info_phonebook_state,
{ "Phonebook State", "mbim.control.phonebook_configuration_info.phonebook_state",
FT_UINT32, BASE_DEC, VALS(mbim_phonebook_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_configuration_info_total_nb_of_entries,
{ "Total Number Of Entries", "mbim.control.phonebook_configuration_info.total_nb_of_entries",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_configuration_info_used_entries,
{ "Used Entries", "mbim.control.phonebook_configuration_info.used_entries",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_configuration_info_max_number_length,
{ "Max Number Length", "mbim.control.phonebook_configuration_info.max_number_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_configuration_info_max_name_length,
{ "Max Name Length", "mbim.control.phonebook_configuration_info.max_name_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_entry_index,
{ "Entry Index", "mbim.control.phonebook_entry.entry_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_number_offset,
{ "Number Offset", "mbim.control.phonebook_entry.number.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_number_length,
{ "Number Length", "mbim.control.phonebook_entry.number.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_name_offset,
{ "Name Offset", "mbim.control.phonebook_entry.name.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_name_length,
{ "Name Length", "mbim.control.phonebook_entry.name.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_number,
{ "Number", "mbim.control.phonebook_entry.number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_entry_name,
{ "Name", "mbim.control.phonebook_entry.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_read_req_filter_flag,
{ "Filter Flag", "mbim.control.phonebook_read_req.filter_flag",
FT_UINT32, BASE_DEC, VALS(mbim_phonebook_flag_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_read_req_filter_message_index,
{ "Filter Message Index", "mbim.control.phonebook_read_req.filter_message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_read_info_element_count,
{ "Element Count", "mbim.control.phonebook_read_info.element_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_read_info_phonebook_offset,
{ "Phonebook Offset", "mbim.control.phonebook_read_info.phonebook.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_phonebook_read_info_phonebook_size,
{ "Phonebook Size", "mbim.control.phonebook_read_info.phonebook.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_delete_filter_flag,
{ "Filter Flag", "mbim.control.set_phonebook_delete.filter_flag",
FT_UINT32, BASE_DEC, VALS(mbim_phonebook_flag_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_delete_filter_message_index,
{ "Filter Message Index", "mbim.control.set_phonebook_delete.filter_message_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_save_flag,
{ "Save Flag", "mbim.control.set_phonebook_write.save_flag",
FT_UINT32, BASE_DEC, VALS(mbim_phonebook_write_flag_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_save_index,
{ "Save Index", "mbim.control.set_phonebook_write.save_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_number_offset,
{ "Number Offset", "mbim.control.set_phonebook_write.number.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_number_length,
{ "Number Length", "mbim.control.set_phonebook_write.number.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_name_offset,
{ "Name Offset", "mbim.control.set_phonebook_write.name.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_name_length,
{ "Name Length", "mbim.control.set_phonebook_write.name.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_number,
{ "Number", "mbim.control.set_phonebook_write.number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_phonebook_write_name,
{ "Name", "mbim.control.set_phonebook_write.name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control,
{ "PAC Host Control", "mbim.control.set_stk_pac.pac_host_control",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_refresh,
{ "Refresh", "mbim.control.set_stk_pac.pac_host_control.refresh",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_more_time,
{ "More Time", "mbim.control.set_stk_pac.pac_host_control.more_time",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_poll_interval,
{ "Poll Interval", "mbim.control.set_stk_pac.pac_host_control.poll_interval",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_polling_off,
{ "Polling Off", "mbim.control.set_stk_pac.pac_host_control.polling_off",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_set_up_evt_list,
{ "Set Up Event List", "mbim.control.set_stk_pac.pac_host_control.set_up_evt_list",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x20,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_set_up_call,
{ "Set Up Call", "mbim.control.set_stk_pac.pac_host_control.set_up_call",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_send_ss,
{ "Send SS", "mbim.control.set_stk_pac.pac_host_control.send_ss",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_send_ussd,
{ "Send USSD", "mbim.control.set_stk_pac.pac_host_control.send_ussd",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_send_short_msg,
{ "Send Short Message", "mbim.control.set_stk_pac.pac_host_control.send_short_msg",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x20,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_send_dtmf,
{ "Send DTMF", "mbim.control.set_stk_pac.pac_host_control.send_dtmf",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_launch_browser,
{ "Launch Browser", "mbim.control.set_stk_pac.pac_host_control.launch_browser",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x80,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_geo_loc_req,
{ "Geographical Location Request", "mbim.control.set_stk_pac.pac_host_control.geo_loc_req",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x01,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_play_tone,
{ "Play Tone", "mbim.control.set_stk_pac.pac_host_control.play_tone",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_display_text,
{ "Display Text", "mbim.control.set_stk_pac.pac_host_control.display_text",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x20,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_inkey,
{ "Get Inkey", "mbim.control.set_stk_pac.pac_host_control.get_inkey",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_input,
{ "Get Input", "mbim.control.set_stk_pac.pac_host_control.get_input",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x80,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_select_item,
{ "Select Item", "mbim.control.set_stk_pac.pac_host_control.select_item",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x01,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_set_up_menu,
{ "Set Up Menu", "mbim.control.set_stk_pac.pac_host_control.set_up_menu",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_prov_local_info,
{ "Provide Local Information", "mbim.control.set_stk_pac.pac_host_control.prov_local_info",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_timer_management,
{ "Timer Management", "mbim.control.set_stk_pac.pac_host_control.timer_management",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_set_up_idle_mode_text,
{ "Set Up Idle Mode Text", "mbim.control.set_stk_pac.pac_host_control.set_up_idle_mode_text",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_perform_card_apdu,
{ "Perform Card APDU", "mbim.control.set_stk_pac.pac_host_control.perform_card_apdu",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_power_on_card,
{ "Power On Card", "mbim.control.set_stk_pac.pac_host_control.power_on_card",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x80,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_power_off_card,
{ "Power Off Card", "mbim.control.set_stk_pac.pac_host_control.power_off_card",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x01,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_reader_status,
{ "Get Reader Status", "mbim.control.set_stk_pac.pac_host_control.get_reader_status",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_run_at_cmd,
{ "Run AT Command", "mbim.control.set_stk_pac.pac_host_control.run_at_cmd",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_lang_notif,
{ "Language Notification", "mbim.control.set_stk_pac.pac_host_control.lang_notif",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_open_channel,
{ "Open Channel", "mbim.control.set_stk_pac.pac_host_control.open_channel",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x01,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_close_channel,
{ "Close Channel", "mbim.control.set_stk_pac.pac_host_control.close_channel",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_receive_data,
{ "Receive Data", "mbim.control.set_stk_pac.pac_host_control.receive_data",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_send_data,
{ "Send Data", "mbim.control.set_stk_pac.pac_host_control.send_data",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_channel_status,
{ "Get Channel Status", "mbim.control.set_stk_pac.pac_host_control.get_channel_status",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_service_search,
{ "Service Search", "mbim.control.set_stk_pac.pac_host_control.service_search",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x20,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_service_info,
{ "Get Service Information", "mbim.control.set_stk_pac.pac_host_control.get_service_info",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_declare_service,
{ "Declare Service", "mbim.control.set_stk_pac.pac_host_control.declare_service",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x80,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_set_frames,
{ "Set Frames", "mbim.control.set_stk_pac.pac_host_control.set_frames",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x04,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_get_frames_status,
{ "Get Frames Status", "mbim.control.set_stk_pac.pac_host_control.get_frames_status",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x08,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_retrieve_multimedia_msg,
{ "Retrieve Multimedia Message", "mbim.control.set_stk_pac.pac_host_control.retrieve_multimedia_msg",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x10,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_submit_multimedia_msg,
{ "Submit Multimedia Message", "mbim.control.set_stk_pac.pac_host_control.submit_multimedia_msg",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x20,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_display_multimedia_msg,
{ "Display Multimedia Message", "mbim.control.set_stk_pac.pac_host_control.display_multimedia_msg",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_activate,
{ "Activate", "mbim.control.set_stk_pac.pac_host_control.activate",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x40,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_contactless_state_changed,
{ "Contactless State Changed", "mbim.control.set_stk_pac.pac_host_control.contactless_state_changed",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x80,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_cmd_container,
{ "Command Container", "mbim.control.set_stk_pac.pac_host_control.cmd_container",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x01,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_encapsulated_session_ctrl,
{ "Encapsulated Session Control", "mbim.control.set_stk_pac.pac_host_control.encapsulated_session_ctrl",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_set_stk_pac_pac_host_control_end_proact_session,
{ "End Proactive Session", "mbim.control.set_stk_pac.pac_host_control.end_proact_session",
FT_BOOLEAN, 8, TFS(&mbim_pac_host_control_val), 0x02,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support,
{ "PAC Host Control", "mbim.control.stk_pac_info.pac_support",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_refresh,
{ "Refresh", "mbim.control.stk_pac_info.pac_support.refresh",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_more_time,
{ "More Time", "mbim.control.stk_pac_info.pac_support.more_time",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_poll_interval,
{ "Poll Interval", "mbim.control.stk_pac_info.pac_support.poll_interval",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_polling_off,
{ "Polling Off", "mbim.control.stk_pac_info.pac_support.polling_off",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_set_up_evt_list,
{ "Set Up Event List", "mbim.control.stk_pac_info.pac_support.set_up_evt_list",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_set_up_call,
{ "Set Up Call", "mbim.control.stk_pac_info.pac_support.set_up_call",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_send_ss,
{ "Send SS", "mbim.control.stk_pac_info.pac_support.send_ss",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_send_ussd,
{ "Send USSD", "mbim.control.stk_pac_info.pac_support.send_ussd",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_send_short_msg,
{ "Send Short Message", "mbim.control.stk_pac_info.pac_support.send_short_msg",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_send_dtmf,
{ "Send DTMF", "mbim.control.stk_pac_info.pac_support.send_dtmf",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_launch_browser,
{ "Launch Browser", "mbim.control.stk_pac_info.pac_support.launch_browser",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_geo_loc_req,
{ "Geographical Location Request", "mbim.control.stk_pac_info.pac_support.geo_loc_req",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_play_tone,
{ "Play Tone", "mbim.control.stk_pac_info.pac_support.play_tone",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_display_text,
{ "Display Text", "mbim.control.stk_pac_info.pac_support.display_text",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_inkey,
{ "Get Inkey", "mbim.control.stk_pac_info.pac_support.get_inkey",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_input,
{ "Get Input", "mbim.control.stk_pac_info.pac_support.get_input",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_select_item,
{ "Select Item", "mbim.control.stk_pac_info.pac_support.select_item",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_set_up_menu,
{ "Set Up Menu", "mbim.control.stk_pac_info.pac_support.set_up_menu",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_prov_local_info,
{ "Provide Local Information", "mbim.control.stk_pac_info.pac_support.prov_local_info",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_timer_management,
{ "Timer Management", "mbim.control.stk_pac_info.pac_support.timer_management",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_set_up_idle_mode_text,
{ "Set Up Idle Mode Text", "mbim.control.stk_pac_info.pac_support.set_up_idle_mode_text",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_perform_card_apdu,
{ "Perform Card APDU", "mbim.control.stk_pac_info.pac_support.perform_card_apdu",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_power_on_card,
{ "Power On Card", "mbim.control.stk_pac_info.pac_support.power_on_card",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_power_off_card,
{ "Power Off Card", "mbim.control.stk_pac_info.pac_support.power_off_card",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_reader_status,
{ "Get Reader Status", "mbim.control.stk_pac_info.pac_support.get_reader_status",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_run_at_cmd,
{ "Run AT Command", "mbim.control.stk_pac_info.pac_support.run_at_cmd",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_lang_notif,
{ "Language Notification", "mbim.control.stk_pac_info.pac_support.lang_notif",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_open_channel,
{ "Open Channel", "mbim.control.stk_pac_info.pac_support.open_channel",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_close_channel,
{ "Close Channel", "mbim.control.stk_pac_info.pac_support.close_channel",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_receive_data,
{ "Receive Data", "mbim.control.stk_pac_info.pac_support.receive_data",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_send_data,
{ "Send Data", "mbim.control.stk_pac_info.pac_support.send_data",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_channel_status,
{ "Get Channel Status", "mbim.control.stk_pac_info.pac_support.get_channel_status",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_service_search,
{ "Service Search", "mbim.control.stk_pac_info.pac_support.service_search",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_service_info,
{ "Get Service Information", "mbim.control.stk_pac_info.pac_support.get_service_info",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_declare_service,
{ "Declare Service", "mbim.control.stk_pac_info.pac_support.declare_service",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_set_frames,
{ "Set Frames", "mbim.control.stk_pac_info.pac_support.set_frames",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_get_frames_status,
{ "Get Frames Status", "mbim.control.stk_pac_info.pac_support.get_frames_status",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_retrieve_multimedia_msg,
{ "Retrieve Multimedia Message", "mbim.control.stk_pac_info.pac_support.retrieve_multimedia_msg",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_submit_multimedia_msg,
{ "Submit Multimedia Message", "mbim.control.stk_pac_info.pac_support.submit_multimedia_msg",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_display_multimedia_msg,
{ "Display Multimedia Message", "mbim.control.stk_pac_info.pac_support.display_multimedia_msg",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_activate,
{ "Activate", "mbim.control.stk_pac_info.pac_support.activate",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_contactless_state_changed,
{ "Contactless State Changed", "mbim.control.stk_pac_info.pac_support.contactless_state_changed",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_cmd_container,
{ "Command Container", "mbim.control.stk_pac_info.pac_support.cmd_container",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_encapsulated_session_ctrl,
{ "Encapsulated Session Control", "mbim.control.stk_pac_info.pac_support.encapsulated_session_ctrl",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_info_pac_support_end_proact_session,
{ "End Proactive Session", "mbim.control.stk_pac_info.pac_support.end_proact_session",
FT_UINT8, BASE_DEC, VALS(mbim_stk_pac_profile_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_pac_type,
{ "PAC Type", "mbim.control.stk_pac.pac_type",
FT_UINT32, BASE_DEC, VALS(mbim_stk_pac_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_stk_pac_pac,
{ "PAC", "mbim.control.stk_pac.pac",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_stk_terminal_response_response_length,
{ "Response Length", "mbim.control.set_stk_terminal_response.response_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_stk_terminal_response_data_buffer,
{ "Data Buffer", "mbim.control.set_stk_terminal_response.data_buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_terminal_response_info_result_data_string_offset,
{ "Result Data String Offset", "mbim.control.stk_terminal_response_info.result_data_string.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_terminal_response_info_result_data_string_length,
{ "Result Data String Length", "mbim.control.stk_terminal_response_info.result_data_string.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_terminal_response_info_status_word,
{ "Status Word", "mbim.control.stk_terminal_response_info.status_word",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_terminal_response_info_result_data_string,
{ "Result Data String", "mbim.control.stk_terminal_response_info.result_data_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_stk_envelope_data_buffer,
{ "Data Buffer", "mbim.control.set_stk_envelope.data_buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_stk_envelope_info_envelope_support,
{ "Envelope Support", "mbim.control.stk_envelope_info.envelope_support",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_req_rand,
{ "RAND", "mbim.control.aka_auth_req.rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_req_autn,
{ "AUTN", "mbim.control.aka_auth_req.autn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_info_res,
{ "RES", "mbim.control.aka_auth_info.res",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_info_res_length,
{ "RES Length", "mbim.control.aka_auth_info.res_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_info_ik,
{ "IK", "mbim.control.aka_auth_info.ik",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_info_ck,
{ "CK", "mbim.control.aka_auth_info.ck",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_aka_auth_info_auts,
{ "AUTS", "mbim.control.aka_auth_info.auts",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_req_rand,
{ "RAND", "mbim.control.akap_auth_req.rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_req_autn,
{ "AUTN", "mbim.control.akap_auth_req.autn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_req_network_name_offset,
{ "Network Name Offset", "mbim.control.akap_auth_req.network_name.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_req_network_name_length,
{ "Network Name Length", "mbim.control.akap_auth_req.network_name.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_req_network_name,
{ "Network Name", "mbim.control.akap_auth_req.network_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_info_res,
{ "RES", "mbim.control.akap_auth_info.res",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_info_res_length,
{ "RES Length", "mbim.control.akap_auth_info.res_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_info_ik,
{ "IK", "mbim.control.akap_auth_info.ik",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_info_ck,
{ "CK", "mbim.control.akap_auth_info.ck",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_akap_auth_info_auts,
{ "AUTS", "mbim.control.akap_auth_info.auts",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_req_rand1,
{ "RAND1", "mbim.control.sim_auth_req.rand1",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_req_rand2,
{ "RAND2", "mbim.control.sim_auth_req.rand2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_req_rand3,
{ "RAND3", "mbim.control.sim_auth_req.rand3",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_req_n,
{ "n", "mbim.control.sim_auth_req.n",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_sres1,
{ "SRES1", "mbim.control.sim_auth_info.sres1",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_kc1,
{ "KC1", "mbim.control.sim_auth_info.kc1",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_sres2,
{ "SRES2", "mbim.control.sim_auth_info.sres2",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_kc2,
{ "KC2", "mbim.control.sim_auth_info.kc2",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_sres3,
{ "SRES3", "mbim.control.sim_auth_info.sres3",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_kc3,
{ "KC3", "mbim.control.sim_auth_info.kc3",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sim_auth_info_n,
{ "n", "mbim.control.sim_auth_info.n",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_dss_connect_device_service_id,
{ "Device Service Id", "mbim.control.set_dss_connect.device_service_id",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_dss_connect_dss_session_id,
{ "DSS Session Id", "mbim.control.set_dss_connect.dss_session_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_set_dss_connect_dss_link_state,
{ "DSS Link State", "mbim.control.set_dss_connect.dss_link_state",
FT_UINT32, BASE_DEC, VALS(mbim_dss_link_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_capabilities_info_capabilities,
{ "Capabilities", "mbim.control.multicarrier_capabilities_info.capabilities",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_capabilities_info_capabilities_static_scan,
{ "Static Scan", "mbim.control.multicarrier_capabilities_info.capabilities.static_scan",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000001,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_capabilities_info_capabilities_fw_requires_reboot,
{ "FW Requires Reboot", "mbim.control.multicarrier_capabilities_info.capabilities.fw_requires_reboot",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x00000002,
NULL, HFILL }
},
{ &hf_mbim_location_info_country,
{ "Country", "mbim.control.location_info.country",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &mbim_geoid_vals_ext, 0,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_current_cid_list_req_uuid,
{ "UUID", "mbim.control.multicarrier_current_cid_list_req.uuid",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_current_cid_list_info_cid_count,
{ "CID Count", "mbim.control.multicarrier_current_cid_list_info.cid_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_multicarrier_current_cid_list_info_cid,
{ "CID", "mbim.control.multicarrier_current_cid_list_info.cid",
FT_UINT32, BASE_DEC, VALS(mbim_uuid_multicarrier_cid_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_msfwid_firmwareid_info_firmware_id,
{ "Firmware Id", "mbim.control.msfwid_firmwareid_info.firmware_id",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_qmi_buffer,
{ "Buffer", "mbim.control.qmi.buffer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_enable,
{ "Enable", "mbim.control.thermal_config.enable",
FT_UINT32, BASE_DEC, VALS(mbim_thermal_config_enable_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_temp_sensor_id,
{ "Temperature Sensor ID", "mbim.control.thermal_config.temp_sensor_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_alarm_id,
{ "Alarm ID", "mbim.control.thermal_config.alarm_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_threshold_value,
{ "Threshold Value", "mbim.control.thermal_config.threshold_value",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_degrees_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_hyst_value,
{ "Hysteresis Value", "mbim.control.thermal_config.hyst_value",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_degrees_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_config_sampling_period,
{ "Sampling Period", "mbim.control.thermal_config.sampling_period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_query_thermal_state_temp_sensor_id,
{ "Temperature Sensor ID", "mbim.control.query_thermal_state.temp_sensor_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_current_temp_value,
{ "Current Temperature Value", "mbim.control.thermal_state_info.current_temp_value",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_degrees_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_enable,
{ "Enable", "mbim.control.thermal_state_info.enable",
FT_UINT32, BASE_DEC, VALS(mbim_thermal_config_enable_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_temp_sensor_id,
{ "Temperature Sensor ID", "mbim.control.thermal_state_info.temp_sensor_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_alarm_id,
{ "Alarm ID", "mbim.control.thermal_state_info.alarm_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_threshold_value,
{ "Threshold Value", "mbim.control.thermal_state_info.threshold_value",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_degrees_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_hyst_value,
{ "Hysteresis Value", "mbim.control.thermal_state_info.hyst_value",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_degrees_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_thermal_state_info_sampling_period,
{ "Sampling Period", "mbim.control.thermal_state_info.sampling_period",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_sar_config_sar_status,
{ "SAR Status", "mbim.control.sar_config.sar_status",
FT_UINT32, BASE_DEC, VALS(mbim_sar_status_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_sar_config_level,
{ "Level", "mbim.control.sar_config.level",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_activate_state,
{ "State", "mbim.control.adpclk_activate.state",
FT_UINT32, BASE_DEC, VALS(mbim_adpclk_activate_state_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_elem_count,
{ "Element Count", "mbim.control.adpclk_freq_info.elem_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_offset,
{ "ADPCLK Freq Value Offset", "mbim.control.adpclk_freq_info.adpclk_freq_value.offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_size,
{ "ADPCLK Freq Value Size", "mbim.control.adpclk_freq_info.adpclk_freq_value.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_center_freq,
{ "Center Frequency", "mbim.control.adpclk_freq_info.adpclk_freq_value.center_freq",
FT_UINT64, BASE_DEC|BASE_UNIT_STRING, &units_hz, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_freq_spread,
{ "Frequency Spread", "mbim.control.adpclk_freq_info.adpclk_freq_value.freq_spread",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_hz, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_noise_power,
{ "Noise Power", "mbim.control.adpclk_freq_info.adpclk_freq_value.noise_power",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_rssi,
{ "Relative Signal Strength Indication", "mbim.control.adpclk_freq_info.adpclk_freq_value.rssi",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_adpclk_freq_info_adpclk_freq_value_connect_status,
{ "Connect Status", "mbim.control.adpclk_freq_info.adpclk_freq_value.connect_status",
FT_UINT32, BASE_DEC, VALS(mbim_connect_status_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_trace_config_config,
{ "Configuration", "mbim.control.trace_config.config",
FT_UINT32, BASE_DEC, VALS(mbim_trace_config_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_nrtc_app_info_period,
{ "Period", "mbim.control.nrtc_app_info.period",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtc_app_info_duration,
{ "Duration", "mbim.control.nrtc_app_info.duration",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_mode,
{ "Mode", "mbim.control.nrtcws_config.mode",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_wlan_active,
{ "WLAN Active", "mbim.control.nrtcws_config.wlan_active",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_wlan_safe_rx,
{ "WLAN Safe Rx", "mbim.control.nrtcws_config.wlan_safe_rx",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_wlan_bandwidth,
{ "WLAN Bandwidth", "mbim.control.nrtcws_config.wlan_bandwidth",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_bt_active,
{ "BT Active", "mbim.control.nrtcws_config.bt_active",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_config_bt_safe_rx,
{ "BT Safe Rx", "mbim.control.nrtcws_config.bt_safe_rx",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_lte_active,
{ "LTE Active", "mbim.control.nrtcws_info.lte_active",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_wlan_safe_rx_min,
{ "WLAN Safe Rx Min", "mbim.control.nrtcws_info.wlan_safe_rx_min",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_mhz, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_wlan_safe_rx_max,
{ "WLAN Safe Rx Max", "mbim.control.nrtcws_info.wlan_safe_rx_max",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_mhz, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_bt_safe_rx_min,
{ "BT Safe Rx Min", "mbim.control.nrtcws_info.bt_safe_rx_min",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_mhz, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_bt_safe_rx_max,
{ "BT Safe Rx Max", "mbim.control.nrtcws_info.bt_safe_rx_max",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_mhz, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_lte_sps_period,
{ "LTE SPS Periodicity", "mbim.control.nrtcws_info.lte_sps_period",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_lte_sps_duration,
{ "LTE SPS Duration", "mbim.control.nrtcws_info.lte_sps_duration",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_nrtcws_info_lte_sps_initial_offset,
{ "LTE SPS Initial Offset", "mbim.control.nrtcws_info.lte_sps_initial_offset",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_usbprofile_cmd_length,
{ "Length", "mbim.control.usbprofile_cmd.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_usbprofile_cmd_buffer,
{ "Buffer", "mbim.control.usbprofile_cmd.buffer",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_usbprofile_rsp_length,
{ "Length", "mbim.control.usbprofile_rsp.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_usbprofile_rsp_buffer,
{ "Buffer", "mbim.control.usbprofile_rsp.buffer",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ciq_set_mode,
{ "Mode", "mbim.control.ciq_set.mode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ciq_set_debug_info_size,
{ "Debug Info Size", "mbim.control.ciq_set.debug_info.size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ciq_set_debug_info,
{ "Debug Info", "mbim.control.ciq_set.debug_info",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_ciq_info_mode,
{ "Mode", "mbim.control.ciq_info.mode",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_rssi,
{ "RSSI", "mbim.control.atds_signal_info.rssi",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rssi_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_ber,
{ "BER", "mbim.control.atds_signal_info.ber",
FT_UINT32, BASE_DEC, VALS(mbim_ber_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_rscp,
{ "RSCP", "mbim.control.atds_signal_info.rscp",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rscp_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_ecno,
{ "Ec/No", "mbim.control.atds_signal_info.ecno",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_ecno_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_rsrq,
{ "RSRQ", "mbim.control.atds_signal_info.rsrq",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rsrq_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_rsrp,
{ "RSRP", "mbim.control.atds_signal_info.rsrp",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rsrp_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_signal_info_rssnr,
{ "RS SNR", "mbim.control.atds_signal_info.rssnr",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rssnr_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_location_info_lac,
{ "Location Area Code", "mbim.control.atds_location_info.lac",
FT_UINT32, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_location_info_tac,
{ "Tracking Area Code", "mbim.control.atds_location_info.tac",
FT_UINT32, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_location_info_cellid,
{ "Cell Identity", "mbim.control.atds_location_info.cellid",
FT_UINT32, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_id_offset,
{ "Provider Id Offset", "mbim.control.atds_operator.provider_id_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_id_size,
{ "Provider Id Size", "mbim.control.atds_operator.provider_id_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_state,
{ "Provider State", "mbim.control.atds_operator.provider_state",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_name_offset,
{ "Provider Name Offset", "mbim.control.atds_operator.provider_name_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_name_size,
{ "Provider Name Size", "mbim.control.atds_operator.provider_name_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_plmn_mode,
{ "PLMN Mode", "mbim.control.atds_operator.plmn_mode",
FT_UINT32, BASE_DEC, VALS(mbim_atds_operator_plmn_mode_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_rssi,
{ "RSSI", "mbim.control.atds_operator.rssi",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_rssi_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_error_rate,
{ "Error Rate", "mbim.control.atds_operator.error_rate",
FT_UINT32, BASE_DEC, VALS(mbim_error_rate_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_id,
{ "Provider Id", "mbim.control.atds_operator.provider_id",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operator_provider_name,
{ "Provider Name", "mbim.control.atds_operator.provider_name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operators_elem_count,
{ "Element Count", "mbim.control.atds_operators.elem_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operators_operator_offset,
{ "Provider Offset", "mbim.control.atds_operators.provider_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_operators_operator_size,
{ "Provider Size", "mbim.control.atds_operators.provider_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_rat_info_mode,
{ "Mode", "mbim.control.atds_rat_info.mode",
FT_UINT32, BASE_DEC, VALS(mbim_adts_rat_info_mode_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_type,
{ "Type", "mbim.control.atds_projection_table.type",
FT_UINT32, BASE_DEC, VALS(mbim_adts_projection_table_type_vals), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar5min,
{ "Bar5 Min", "mbim.control.atds_projection_table.bar5min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a5,
{ "A5", "mbim.control.atds_projection_table.a5",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b5,
{ "B5", "mbim.control.atds_projection_table.b5",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar4min,
{ "Bar4 Min", "mbim.control.atds_projection_table.bar4min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a4,
{ "A4", "mbim.control.atds_projection_table.a4",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b4,
{ "B4", "mbim.control.atds_projection_table.b4",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar3min,
{ "Bar3 Min", "mbim.control.atds_projection_table.bar3min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a3,
{ "A3", "mbim.control.atds_projection_table.a3",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b3,
{ "B3", "mbim.control.atds_projection_table.b3",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar2min,
{ "Bar2 Min", "mbim.control.atds_projection_table.bar2min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a2,
{ "A2", "mbim.control.atds_projection_table.a2",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b2,
{ "B2", "mbim.control.atds_projection_table.b2",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar1min,
{ "Bar1 Min", "mbim.control.atds_projection_table.bar1min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a1,
{ "A1", "mbim.control.atds_projection_table.a1",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b1,
{ "B1", "mbim.control.atds_projection_table.b1",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_bar0min,
{ "Bar0 Min", "mbim.control.atds_projection_table.bar0min",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_a0,
{ "A0", "mbim.control.atds_projection_table.a0",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_table_b0,
{ "B0", "mbim.control.atds_projection_table.b0",
FT_UINT32, BASE_CUSTOM, CF_FUNC(mbim_projection_table_coeff_fmt), 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_tables_elem_count,
{ "Element Count", "mbim.control.atds_projection_tables.elem_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_tables_projection_table_offset,
{ "Projection Table Offset", "mbim.control.atds_projection_tables.projection_table_offset",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_atds_projection_tables_projection_table_size,
{ "Projection Table Size", "mbim.control.atds_projection_tables.projection_table_size",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragmented_payload,
{ "Fragmented Payload", "mbim.control.fragmented_payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_request_in,
{ "Request In", "mbim.control.request_in",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0,
NULL, HFILL }
},
{ &hf_mbim_response_in,
{ "Response In", "mbim.control.response_in",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0,
NULL, HFILL }
},
{ &hf_mbim_descriptor,
{ "Descriptor", "mbim.descriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_descriptor_version,
{ "bcdMBIMVersion", "mbim.descriptor.version",
FT_UINT16, BASE_HEX, NULL, 0,
"MBIM Version", HFILL }
},
{ &hf_mbim_descriptor_max_control_message,
{ "wMaxControlMessage", "mbim.descriptor.max_control_message",
FT_UINT16, BASE_DEC, NULL, 0,
"Max Control Message", HFILL }
},
{ &hf_mbim_descriptor_number_filters,
{ "bNumberFilters", "mbim.descriptor.number_filters",
FT_UINT8, BASE_DEC, NULL, 0,
"Number Of Packet Filters", HFILL }
},
{ &hf_mbim_descriptor_max_filter_size,
{ "bMaxFilterSize", "mbim.descriptor.max_filter_size",
FT_UINT8, BASE_DEC, NULL, 0,
"Max Packet Filter Size", HFILL }
},
{ &hf_mbim_descriptor_max_segment_size,
{ "wMaxSegmentSize", "mbim.descriptor.max_segment_size",
FT_UINT16, BASE_DEC, NULL, 0,
"Max Segment Size", HFILL }
},
{ &hf_mbim_descriptor_network_capabilities,
{ "bmNetworkCapabilities", "mbim.descriptor.network_capabilities",
FT_UINT8, BASE_HEX, NULL, 0,
"Network Capabilities", HFILL }
},
{ &hf_mbim_descriptor_network_capabilities_max_datagram_size,
{ "SetMaxDatagramSize/GetMaxDatagramSize", "mbim.descriptor.network_capabilities.max_datagram_size",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x08,
NULL, HFILL }
},
{ &hf_mbim_descriptor_network_capabilities_ntb_input_size,
{ "8-byte GetNtbInputSize/SetNtbInputSize", "mbim.descriptor.network_capabilities.ntb_input_size",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_mbim_descriptor_extended_version,
{ "bcdMBIMExtendedVersion", "mbim.descriptor.extended_version",
FT_UINT16, BASE_HEX, NULL, 0,
"MBIM Extended Version", HFILL }
},
{ &hf_mbim_descriptor_max_outstanding_command_messages,
{ "bMaxOutstandingCommandMessages", "mbim.descriptor.max_outstanding_command_messages",
FT_UINT8, BASE_DEC, NULL, 0,
"Max Outstanding Messages", HFILL }
},
{ &hf_mbim_descriptor_mtu,
{ "wMTU", "mbim.descriptor.mtu",
FT_UINT16, BASE_DEC, NULL, 0,
"MTU", HFILL }
},
{ &hf_mbim_bulk,
{ "Bulk", "mbim.bulk",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_signature,
{ "Signature", "mbim.bulk.nth.signature",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_header_length,
{ "Header Length", "mbim.bulk.nth.header_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_sequence_number,
{ "Sequence Number", "mbim.bulk.nth.sequence_number",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_block_length,
{ "Block Length", "mbim.bulk.nth.block_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_block_length_32,
{ "Block Length", "mbim.bulk.nth.block_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_ndp_index,
{ "NDP Index", "mbim.bulk.nth.ndp_index",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_nth_ndp_index_32,
{ "NDP Index", "mbim.bulk.nth.ndp_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_signature,
{ "Signature", "mbim.bulk.ndp.signature",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_signature_ips_session_id,
{ "IPS Session Id", "mbim.bulk.ndp.signature.ips_session_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_signature_dss_session_id,
{ "DSS Session Id", "mbim.bulk.ndp.signature.dss_session_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_length,
{ "Length", "mbim.bulk.ndp.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_next_ndp_index,
{ "Next NDP Index", "mbim.bulk.ndp.next_ndp_index",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_next_ndp_index_32,
{ "Next NDP Index", "mbim.bulk.ndp.next_ndp_index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_reserved,
{ "Reserved", "mbim.bulk.ndp.reserved",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_reserved2,
{ "Reserved", "mbim.bulk.ndp.reserved",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_datagram_index,
{ "Datagram Index", "mbim.bulk.ndp.datagram.index",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_datagram_index_32,
{ "Datagram Index", "mbim.bulk.ndp.datagram.index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_datagram_length,
{ "Datagram Length", "mbim.bulk.ndp.datagram.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_datagram_length_32,
{ "Datagram Length", "mbim.bulk.ndp.datagram.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_datagram,
{ "Datagram", "mbim.bulk.ndp.datagram",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_ndp_nb_datagrams,
{ "Number Of Datagrams", "mbim.bulk.ndp.nb_datagrams",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_bulk_total_nb_datagrams,
{ "Total Number Of Datagrams", "mbim.bulk.total_nb_datagrams",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragments,
{ "Fragments", "mbim.control.fragments",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment,
{ "Fragment", "mbim.control.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_overlap,
{ "Fragment Overlap", "mbim.control.fragment_overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_overlap_conflict,
{ "Fragment Overlap Conflict", "mbim.control.fragment_overlap_conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_multiple_tails,
{ "Fragment Multiple Tails", "mbim.control.fragment_multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_too_long_fragment,
{ "Too Long Fragment", "mbim.control.fragment_too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_error,
{ "Fragment Error", "mbim.control.fragment_error",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_fragment_count,
{ "Fragment Count", "mbim.control.fragment_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_reassembled_in,
{ "Reassembled In", "mbim.control.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_reassembled_length,
{ "Reassembled Length", "mbim.control.reassembled_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_mbim_reassembled_data,
{ "Reassembled Data", "mbim.control.reassembled_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_mbim,
&ett_mbim_msg_header,
&ett_mbim_frag_header,
&ett_mbim_info_buffer,
&ett_mbim_bitmap,
&ett_mbim_pair_list,
&ett_mbim_pin,
&ett_mbim_buffer,
&ett_mbim_sc_address,
&ett_mbim_pac,
&ett_mbim_thermal_threshold_setting,
&ett_mbim_fragment,
&ett_mbim_fragments
};
static ei_register_info ei[] = {
{ &ei_mbim_max_ctrl_transfer,
{ "mbim.max_control_transfer_too_small", PI_MALFORMED, PI_ERROR,
"Max Control Transfer is less than 64 bytes", EXPFILL }},
{ &ei_mbim_unexpected_msg,
{ "mbim.unexpected_msg", PI_MALFORMED, PI_ERROR,
"Unexpected message", EXPFILL }},
{ &ei_mbim_unexpected_info_buffer,
{ "mbim.unexpected_info_buffer", PI_MALFORMED, PI_WARN,
"Unexpected Information Buffer", EXPFILL }},
{ &ei_mbim_illegal_on_link_prefix_length,
{ "mbim.illegal_on_link_prefix_length", PI_MALFORMED, PI_WARN,
"Illegal On Link Prefix Length", EXPFILL }},
{ &ei_mbim_unknown_sms_format,
{ "mbim.unknown_sms_format", PI_PROTOCOL, PI_WARN,
"Unknown SMS format", EXPFILL }},
{ &ei_mbim_unexpected_uuid_value,
{ "mbim.unexpected_uuid_value", PI_PROTOCOL, PI_WARN,
"Unexpected UUID value", EXPFILL }},
{ &ei_mbim_too_many_items,
{ "mbim.too_many_items", PI_PROTOCOL, PI_WARN,
"Too many items", EXPFILL }},
{ &ei_mbim_alignment_error,
{ "mbim.alignment_error", PI_MALFORMED, PI_ERROR,
"Alignment error", EXPFILL }},
{ &ei_mbim_invalid_block_len,
{ "mbim.invalid_block_len", PI_PROTOCOL, PI_WARN,
"NTH Block Length does not match packet length", EXPFILL }},
{ &ei_mbim_out_of_bounds_index,
{ "mbim.out_of_bounds_index", PI_MALFORMED, PI_ERROR,
"Index is out of bounds", EXPFILL }},
{ &ei_mbim_oversized_string,
{ "mbim.oversized_string", PI_PROTOCOL, PI_WARN,
"String exceeds maximum size allowed", EXPFILL }},
{ &ei_mbim_oversized_pdu,
{ "mbim.oversized_pdu", PI_PROTOCOL, PI_WARN,
"PDU exceeds maximum size allowed", EXPFILL }}
};
proto_mbim = proto_register_protocol("Mobile Broadband Interface Model",
"MBIM", "mbim");
proto_register_field_array(proto_mbim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mbim = expert_register_protocol(proto_mbim);
expert_register_field_array(expert_mbim, ei, array_length(ei));
reassembly_table_register(&mbim_reassembly_table,
&addresses_reassembly_table_functions);
mbim_control_handle = register_dissector("mbim.control", dissect_mbim_control, proto_mbim);
register_dissector("mbim.descriptor", dissect_mbim_descriptor, proto_mbim);
register_dissector("mbim.bulk", dissect_mbim_bulk, proto_mbim);
dss_dissector_table = register_dissector_table("mbim.dss_session_id",
"MBIM DSS Session Id", proto_mbim, FT_UINT8, BASE_DEC);
mbim_module = prefs_register_protocol(proto_mbim, proto_reg_handoff_mbim);
prefs_register_obsolete_preference(mbim_module, "bulk_heuristic");
prefs_register_bool_preference(mbim_module, "control_decode_unknown_itf",
"Force decoding of unknown USB control data as MBIM",
"Decode control data received on \"usb.control\" with an "
"unknown interface class as MBIM",
&mbim_control_decode_unknown_itf);
prefs_register_enum_preference(mbim_module, "sms_pdu_format",
"SMS PDU format",
"Format used for SMS PDU decoding",
&mbim_sms_pdu_format, mbim_sms_pdu_format_vals, FALSE);
}
void
proto_reg_handoff_mbim(void)
{
static gboolean initialized = FALSE, mbim_control_decode_unknown_itf_prev = FALSE;
if (!initialized) {
dissector_handle_t mbim_decode_as_handle = create_dissector_handle(dissect_mbim_decode_as, proto_mbim);
bertlv_handle = find_dissector_add_dependency("gsm_sim.bertlv", proto_mbim);
etsi_cat_handle = find_dissector_add_dependency("etsi_cat", proto_mbim);
gsm_sms_handle = find_dissector_add_dependency("gsm_sms", proto_mbim);
cdma_sms_handle = find_dissector_add_dependency("ansi_637_trans", proto_mbim);
eth_handle = find_dissector_add_dependency("eth_withoutfcs", proto_mbim);
eth_fcs_handle = find_dissector_add_dependency("eth_withfcs", proto_mbim);
ip_handle = find_dissector_add_dependency("ip", proto_mbim);
data_handle = find_dissector("data");
heur_dissector_add("usb.bulk", dissect_mbim_bulk_heur, "MBIM USB bulk endpoint", "mbim_usb_bulk", proto_mbim, HEURISTIC_ENABLE);
dissector_add_for_decode_as("usb.device", mbim_decode_as_handle);
dissector_add_for_decode_as("usb.product", mbim_decode_as_handle);
dissector_add_for_decode_as("usb.protocol", mbim_decode_as_handle);
initialized = TRUE;
}
if (mbim_control_decode_unknown_itf != mbim_control_decode_unknown_itf_prev) {
if (mbim_control_decode_unknown_itf) {
dissector_add_uint("usb.control", IF_CLASS_UNKNOWN, mbim_control_handle);
} else {
dissector_delete_uint("usb.control", IF_CLASS_UNKNOWN, mbim_control_handle);
}
mbim_control_decode_unknown_itf_prev = mbim_control_decode_unknown_itf;
}
}
