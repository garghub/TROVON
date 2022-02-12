static gint dissect_options(proto_tree *tree, packet_info *pinfo,
guint32 block_type, tvbuff_t *tvb, guint encoding, void *user_data)
{
proto_tree *options_tree;
proto_item *options_item;
proto_tree *option_tree;
proto_item *option_item;
proto_item *p_item;
gint offset = 0;
guint16 option_code;
gint option_length;
gint hfj_pcapng_option_code;
const gchar *str = NULL;
address addr;
address addr_mask;
const value_string *vals = NULL;
union value {
guint32 u32;
guint64 u64;
guint8 u8;
} value;
if (tvb_reported_length(tvb) <= 0)
return 0;
options_item = proto_tree_add_item(tree, hf_pcapng_options, tvb, offset, -1, ENC_NA);
options_tree = proto_item_add_subtree(options_item, ett_pcapng_options);
while (tvb_captured_length_remaining(tvb, offset)) {
str = NULL;
option_code = tvb_get_guint16(tvb, offset, encoding);
option_length = tvb_get_guint16(tvb, offset + 2, encoding);
option_item = proto_tree_add_item(options_tree, hf_pcapng_option, tvb, offset, option_length + 2 * 2, ENC_NA);
option_tree = proto_item_add_subtree(option_item, ett_pcapng_option);
switch (block_type) {
case BLOCK_SECTION_HEADER:
hfj_pcapng_option_code = hf_pcapng_option_code_section_header;
vals = option_code_section_header_vals;
break;
case BLOCK_INTERFACE_DESCRIPTION:
hfj_pcapng_option_code = hf_pcapng_option_code_interface_description;
vals = option_code_interface_description_vals;
break;
case BLOCK_ENHANCED_PACKET:
hfj_pcapng_option_code = hf_pcapng_option_code_enhanced_packet;
vals = option_code_enhanced_packet_vals;
break;
case BLOCK_PACKET:
hfj_pcapng_option_code = hf_pcapng_option_code_packet;
vals = option_code_packet_vals;
break;
case BLOCK_NAME_RESOLUTION:
hfj_pcapng_option_code = hf_pcapng_option_code_name_resolution;
vals = option_code_name_resolution_vals;
break;
case BLOCK_INTERFACE_STATISTICS:
hfj_pcapng_option_code = hf_pcapng_option_code_interface_statistics;
vals = option_code_interface_statistics_vals;
break;
default:
hfj_pcapng_option_code = hf_pcapng_option_code;
}
if (vals)
proto_item_append_text(option_item, ": %s", val_to_str_const(option_code, vals, "Unknown"));
proto_tree_add_item(option_tree, hfj_pcapng_option_code, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(option_tree, hf_pcapng_option_length, tvb, offset, 2, encoding);
offset += 2;
if (option_code == 0 && option_length == 0) {
break;
} else if (option_code == 1) {
proto_tree_add_item(option_tree, hf_pcapng_option_data_comment, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
} else switch (block_type) {
case BLOCK_SECTION_HEADER:
switch (option_code) {
case 0x0002:
proto_tree_add_item(option_tree, hf_pcapng_option_data_section_header_hardware, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x0003:
proto_tree_add_item(option_tree, hf_pcapng_option_data_section_header_os, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x0004:
proto_tree_add_item(option_tree, hf_pcapng_option_data_section_header_user_application, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
break;
case BLOCK_INTERFACE_DESCRIPTION: {
struct interface_description *interface_description = (struct interface_description *) user_data;
switch (option_code) {
case 0x0002:
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_description_name, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x0003:
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_description_description, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x0004:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&addr, AT_IPv4, tvb, offset, 4);
offset += 4;
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv4_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&addr_mask, AT_IPv4, tvb, offset, 4);
offset += 4;
str = wmem_strdup_printf(wmem_packet_scope(), "%s/%s",
address_to_display(wmem_packet_scope(), &addr),
address_to_display(wmem_packet_scope(), &addr_mask));
break;
case 0x0005:
if (option_length != 17) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv6, tvb, offset, 16, ENC_NA);
TVB_SET_ADDRESS(&addr, AT_IPv6, tvb, offset, 16);
offset += 16;
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv6_mask, tvb, offset, 1, ENC_NA);
offset += 1;
str = wmem_strdup_printf(wmem_packet_scope(), "%s/%u",
address_to_display(wmem_packet_scope(), &addr), (unsigned int) tvb_get_guint8(tvb, offset - 1));
break;;
case 0x0006:
if (option_length != 6) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_mac_address, tvb, offset, 6, encoding);
str = tvb_get_ether_name(tvb, offset);
offset += 6;
break;
case 0x0007:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_eui_address, tvb, offset, 8, encoding);
TVB_SET_ADDRESS(&addr, AT_EUI64, tvb, offset, 8);
offset += 8;
str = address_to_display(wmem_packet_scope(), &addr);
break;
case 0x0008:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
p_item = proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_speed, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
if (value.u64 == 10000000) {
str = "10 Mbps";
proto_item_append_text(p_item, "%s", str);
} else if (value.u64 == 100000000) {
str = "100 Mbps";
proto_item_append_text(p_item, "%s", str);
} else if (value.u64 == 1000000000) {
str = "1 Gbps";
proto_item_append_text(p_item, "%s", str);
} else {
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
}
offset += 8;
break;
case 0x0009:
if (option_length != 1) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_interface_timestamp_resolution, ett_pcapng_option, hfx_pcapng_option_data_interface_timestamp_resolution, ENC_NA);
value.u8 = tvb_get_guint8(tvb, offset);
offset += 1;
if (interface_description) {
interface_description->timestamp_resolution = value.u8;
}
str = wmem_strdup_printf(wmem_packet_scope(), "%s^-%u%s",
(value.u8 & 0x80) ? "2" : "10",
(guint32) (value.u8 & 0x7F),
(!(value.u8 & 0x80) && value.u8 == 6) ? " (microseconds)" : ((!(value.u8 & 0x80) && value.u8 == 9) ? " (nanoseconds)" : ""));
break;
case 0x000A:
if (option_length != 4) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_timezone, tvb, offset, 4, encoding);
value.u32 = tvb_get_guint32(tvb, offset, encoding);
offset += 4;
str = wmem_strdup_printf(wmem_packet_scope(), "%u", value.u32);
break;
case 0x000B:
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_filter, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x000C:
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_os, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x000D:
if (option_length != 1) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_fcs_length, tvb, offset, 1, ENC_NA);
value.u8 = tvb_get_guint8(tvb, offset);
str = wmem_strdup_printf(wmem_packet_scope(), "%u", (guint32) value.u8);
offset += 1;
break;
case 0x000E:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_timestamp_offset, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
if (interface_description) {
interface_description->timestamp_offset = value.u64;
}
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
}
break;
case BLOCK_PACKET:
switch (option_code) {
case 0x0002:
if (option_length != 4) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
if (encoding == ENC_LITTLE_ENDIAN) {
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags, ett_pcapng_option, hfx_pcapng_option_data_packet_flags, encoding);
offset += 2;
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags_link_layer_errors, ett_pcapng_option, hfx_pcapng_option_data_packet_flags_link_layer_errors, encoding);
offset += 2;
} else {
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags_link_layer_errors, ett_pcapng_option, hfx_pcapng_option_data_packet_flags_link_layer_errors, encoding);
offset += 2;
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags, ett_pcapng_option, hfx_pcapng_option_data_packet_flags, encoding);
offset += 2;
}
break;
case 0x0003:
proto_tree_add_item(option_tree, hf_pcapng_option_data_packet_hash_algorithm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(option_tree, hf_pcapng_option_data_packet_hash_data, tvb, offset, option_length - 1, ENC_NA);
offset += option_length - 1;
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
break;
case BLOCK_NAME_RESOLUTION:
switch (option_code) {
case 0x0002:
proto_tree_add_item(option_tree, hf_pcapng_option_data_dns_name, tvb, offset, option_length, ENC_NA | ENC_UTF_8);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, option_length, ENC_UTF_8);
offset += option_length;
break;
case 0x0003:
if (option_length != 4) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&addr, AT_IPv4, tvb, offset, 4);
offset += 4;
str = wmem_strdup_printf(wmem_packet_scope(), "%s",
address_to_display(wmem_packet_scope(), &addr));
break;
case 0x0004:
if (option_length != 16) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_ipv6, tvb, offset, 16, ENC_NA);
TVB_SET_ADDRESS(&addr, AT_IPv6, tvb, offset, 16);
offset += 16;
str = wmem_strdup_printf(wmem_packet_scope(), "%s",
address_to_display(wmem_packet_scope(), &addr));
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
break;
case BLOCK_INTERFACE_STATISTICS:
switch (option_code) {
case 0x0002:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_start_time, tvb, offset, 8, encoding);
offset += 8;
break;
case 0x0003:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_end_time, tvb, offset, 8, encoding);
offset += 8;
break;
case 0x0004:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_received, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
case 0x0005:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_dropped, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
case 0x0006:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_accepted_by_filter, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
case 0x0007:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_dropped_by_os, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
case 0x0008:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_interface_delivered_to_user, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
break;
case BLOCK_ENHANCED_PACKET:
switch (option_code) {
case 0x0002:
if (option_length != 4) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
if (encoding == ENC_LITTLE_ENDIAN) {
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags, ett_pcapng_option, hfx_pcapng_option_data_packet_flags, encoding);
offset += 2;
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags_link_layer_errors, ett_pcapng_option, hfx_pcapng_option_data_packet_flags_link_layer_errors, encoding);
offset += 2;
} else {
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags_link_layer_errors, ett_pcapng_option, hfx_pcapng_option_data_packet_flags_link_layer_errors, encoding);
offset += 2;
proto_tree_add_bitmask(option_tree, tvb, offset, hf_pcapng_option_data_packet_flags, ett_pcapng_option, hfx_pcapng_option_data_packet_flags, encoding);
offset += 2;
}
break;
case 0x0003:
proto_tree_add_item(option_tree, hf_pcapng_option_data_packet_hash_algorithm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(option_tree, hf_pcapng_option_data_packet_hash_data, tvb, offset, option_length - 1, ENC_NA);
offset += option_length - 1;
break;
case 0x0004:
if (option_length != 8) {
proto_tree_add_expert(option_tree, pinfo, &ei_invalid_option_length, tvb, offset, option_length);
offset += option_length;
break;
}
proto_tree_add_item(option_tree, hf_pcapng_option_data_packet_drop_count, tvb, offset, 8, encoding);
value.u64 = tvb_get_guint64(tvb, offset, encoding);
str = wmem_strdup_printf(wmem_packet_scope(), "%"G_GUINT64_FORMAT, value.u64);
offset += 8;
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
break;
default:
proto_tree_add_item(option_tree, hf_pcapng_option_data, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
if (option_length % 4) {
proto_item_set_len(option_item, option_length + 2 * 2 + (4 - option_length % 4));
option_length = 4 - option_length % 4;
proto_tree_add_item(option_tree, hf_pcapng_option_padding, tvb, offset, option_length, ENC_NA);
offset += option_length;
}
if (str)
proto_item_append_text(option_item, " = %s", str);
}
return offset;
}
static void
pcapng_add_timestamp(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
int offset, guint encoding, guint32 interface_id, struct info *info)
{
proto_tree_add_item(tree, hf_pcapng_timestamp_high, tvb, offset, 4, encoding);
proto_tree_add_item(tree, hf_pcapng_timestamp_low, tvb, offset + 4, 4, encoding);
if (interface_id < wmem_array_get_count(info->interfaces)) {
struct interface_description *interface_description;
nstime_t timestamp;
guint64 ts;
guint32 base;
guint32 i_resolution;
guint64 resolution = 1;
proto_item *ti;
interface_description = (struct interface_description *) wmem_array_index(info->interfaces, interface_id);
ts = ((guint64)(tvb_get_guint32(tvb, offset, encoding))) << 32 |
tvb_get_guint32(tvb, offset + 4, encoding);
ts += interface_description->timestamp_offset;
if (interface_description->timestamp_resolution == 0)
interface_description->timestamp_resolution = 6;
if (interface_description->timestamp_resolution & 0x80) {
base = 2;
} else {
base = 10;
}
for (i_resolution = 0; i_resolution < (guint32)(interface_description->timestamp_resolution & 0x7F); i_resolution += 1)
resolution *= base;
timestamp.secs = (time_t)(ts / resolution);
timestamp.nsecs = (int)(ts - (ts / resolution) * resolution);
ti = proto_tree_add_time(tree, hf_pcapng_timestamp, tvb, offset, 8, &timestamp);
PROTO_ITEM_SET_GENERATED(ti);
pinfo->fd->abs_ts = timestamp;
}
}
static gint dissect_block(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
guint encoding, struct info *info)
{
proto_tree *block_tree;
proto_item *block_item;
proto_tree *block_data_tree;
proto_item *block_data_item;
proto_item *packet_data_item;
gint offset = 0;
guint32 length;
guint32 captured_length;
guint32 reported_length;
guint32 block_type;
guint32 block_data_length;
guint32 interface_id;
tvbuff_t *next_tvb;
block_type = tvb_get_guint32(tvb, offset + 0, encoding);
length = tvb_get_guint32(tvb, offset + 4, encoding);
block_item = proto_tree_add_item(tree, hf_pcapng_block, tvb, offset, length, ENC_NA);
block_tree = proto_item_add_subtree(block_item, ett_pcapng_section_header_block);
proto_item_append_text(block_item, ": %s", val_to_str_const(block_type, block_type_vals, "Unknown"));
proto_tree_add_bitmask_with_flags(block_tree, tvb, offset, hf_pcapng_block_type, ett_pcapng_option, hfx_pcapng_block_type, encoding, BMT_NO_APPEND);
offset += 4;
proto_tree_add_item(block_tree, hf_pcapng_block_length, tvb, offset, 4, encoding);
block_data_length = tvb_get_guint32(tvb, offset, encoding) - 3 * 4;
offset += 4;
block_data_item = proto_tree_add_item(block_tree, hf_pcapng_block_data, tvb, offset, block_data_length, ENC_NA);
block_data_tree = proto_item_add_subtree(block_data_item, ett_pcapng_block_data);
switch (block_type) {
case BLOCK_SECTION_HEADER:
proto_item_append_text(block_item, " %u", info->file_number);
info->file_number += 1;
info->interface_number = 0;
info->frame_number = 1;
proto_tree_add_item(block_data_tree, hf_pcapng_section_header_byte_order_magic, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(block_data_tree, hf_pcapng_section_header_major_version, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(block_data_tree, hf_pcapng_section_header_minor_version, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(block_data_tree, hf_pcapng_section_header_section_length, tvb, offset, 8, encoding);
offset += 8;
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - 4 - 2 - 2 - 8);
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, NULL);
break;
case BLOCK_INTERFACE_DESCRIPTION: {
struct interface_description interface_description;
memset(&interface_description, 0, sizeof(struct interface_description));
proto_item_append_text(block_item, " %u", info->interface_number);
info->interface_number += 1;
proto_tree_add_item(block_data_tree, hf_pcapng_interface_description_link_type, tvb, offset, 2, encoding);
interface_description.link_type = tvb_get_guint16(tvb, offset, encoding);
offset += 2;
proto_tree_add_item(block_data_tree, hf_pcapng_interface_description_reserved, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(block_data_tree, hf_pcapng_interface_description_snap_length, tvb, offset, 4, encoding);
offset += 4;
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - 2 - 2 - 4);
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, &interface_description);
wmem_array_append_one(info->interfaces, interface_description);
}
break;
case BLOCK_PACKET:
proto_item_append_text(block_item, " %u", info->frame_number);
proto_tree_add_item(block_data_tree, hf_pcapng_packet_block_interface_id, tvb, offset, 2, encoding);
interface_id = tvb_get_guint16(tvb, offset, encoding);
offset += 2;
proto_tree_add_item(block_data_tree, hf_pcapng_packet_block_drops_count, tvb, offset, 2, encoding);
offset += 2;
pcapng_add_timestamp(block_data_tree, pinfo, tvb, offset, encoding, interface_id, info);
offset += 8;
proto_tree_add_item_ret_uint(block_data_tree, hf_pcapng_captured_length, tvb, offset, 4, encoding, &captured_length);
offset += 4;
proto_tree_add_item_ret_uint(block_data_tree, hf_pcapng_packet_length, tvb, offset, 4, encoding, &reported_length);
offset += 4;
packet_data_item = proto_tree_add_item(block_data_tree, hf_pcapng_packet_data, tvb, offset, captured_length, encoding);
if (pref_dissect_next_layer && interface_id < wmem_array_get_count(info->interfaces)) {
struct interface_description *interface_description;
proto_tree *packet_data_tree = proto_item_add_subtree(packet_data_item, ett_pcapng_packet_data);
pinfo->fd->num = info->frame_number;
interface_description = (struct interface_description *) wmem_array_index(info->interfaces, interface_id);
TRY {
call_dissector_with_data(pcap_pseudoheader_handle, tvb_new_subset(tvb, offset, captured_length, reported_length),
pinfo, packet_data_tree, &interface_description->link_type);
}
CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, packet_data_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
info->frame_number += 1;
offset += captured_length;
if (captured_length % 4) {
proto_tree_add_item(block_data_tree, hf_pcapng_packet_padding, tvb, offset, captured_length % 4?(4 - captured_length % 4):0, ENC_NA);
offset += captured_length % 4?(4 - captured_length % 4):0;
}
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - 2 - 2 - 8 - 4 - 4 - captured_length - (captured_length % 4?(4 - captured_length % 4):0));
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, NULL);
break;
case BLOCK_SIMPLE_PACKET:
proto_item_append_text(block_item, " %u", info->frame_number);
proto_tree_add_item_ret_uint(block_data_tree, hf_pcapng_packet_length, tvb, offset, 4, encoding, &captured_length);
offset += 4;
interface_id = 0;
packet_data_item = proto_tree_add_item(block_data_tree, hf_pcapng_packet_data, tvb, offset, captured_length, encoding);
if (pref_dissect_next_layer && interface_id < wmem_array_get_count(info->interfaces)) {
struct interface_description *interface_description;
proto_tree *packet_data_tree = proto_item_add_subtree(packet_data_item, ett_pcapng_packet_data);
pinfo->fd->num = info->frame_number;
interface_description = (struct interface_description *) wmem_array_index(info->interfaces, interface_id);
TRY {
call_dissector_with_data(pcap_pseudoheader_handle, tvb_new_subset_length(tvb, offset, captured_length),
pinfo, packet_data_tree, &interface_description->link_type);
}
CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, packet_data_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
info->frame_number += 1;
offset += captured_length;
if (captured_length % 4) {
proto_tree_add_item(block_data_tree, hf_pcapng_packet_padding, tvb, offset, captured_length % 4?(4 - captured_length % 4):0, ENC_NA);
offset += captured_length % 4?(4 - captured_length % 4):0;
}
break;
case BLOCK_NAME_RESOLUTION:
{
proto_tree *records_tree;
proto_item *records_item;
proto_tree *record_tree;
proto_item *record_item;
gint offset_record_start;
gint offset_string_start;
guint16 record_code;
gint record_length;
gint string_length;
gchar *str = NULL;
address addr;
records_item = proto_tree_add_item(block_data_tree, hf_pcapng_records, tvb, offset, block_data_length, ENC_NA);
records_tree = proto_item_add_subtree(records_item, ett_pcapng_records);
offset_record_start = offset;
while (block_data_length - (offset_record_start - offset) > 0) {
record_code = tvb_get_guint16(tvb, offset, encoding);
record_length = tvb_get_guint16(tvb, offset + 2, encoding);
record_item = proto_tree_add_item(records_tree, hf_pcapng_record, tvb, offset, record_length + 2 * 2, ENC_NA);
record_tree = proto_item_add_subtree(record_item, ett_pcapng_record);
proto_item_append_text(record_item, ": %s", val_to_str_const(record_code, record_code_vals, "Unknown"));
proto_tree_add_item(record_tree, hf_pcapng_record_code, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(record_tree, hf_pcapng_record_length, tvb, offset, 2, encoding);
offset += 2;
if (record_code == 0 && record_length == 0) {
break;
} else switch (record_code) {
case 0x0001:
if (record_length < 5) {
proto_tree_add_expert(record_tree, pinfo, &ei_invalid_record_length, tvb, offset, record_length);
offset += record_length;
break;
}
proto_tree_add_item(record_tree, hf_pcapng_record_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS(&addr, AT_IPv4, tvb, offset, 4);
offset += 4;
offset_string_start = offset;
while (offset - offset_string_start < record_length - 4) {
string_length = tvb_strnlen(tvb, offset, (offset - offset_string_start) + record_length - 4);
if (string_length >= 0) {
proto_tree_add_item(record_tree, hf_pcapng_record_name, tvb, offset, string_length + 1, encoding);
offset += string_length + 1;
} else {
proto_tree_add_item(record_tree, hf_pcapng_record_data, tvb, offset, (record_length - 4) - (offset - offset_string_start), encoding);
offset += (record_length - 4) - (offset - offset_string_start);
}
}
str = wmem_strdup_printf(wmem_packet_scope(), "%s",
address_to_display(wmem_packet_scope(), &addr));
break;
case 0x0002:
if (record_length < 17) {
proto_tree_add_expert(record_tree, pinfo, &ei_invalid_option_length, tvb, offset, record_length);
offset += record_length;
break;
}
proto_tree_add_item(record_tree, hf_pcapng_record_ipv6, tvb, offset, 16, ENC_NA);
TVB_SET_ADDRESS(&addr, AT_IPv6, tvb, offset, 16);
offset += 16;
offset_string_start = offset;
while (offset - offset_string_start < record_length - 16) {
string_length = tvb_strnlen(tvb, offset, (offset - offset_string_start) + record_length - 16);
if (string_length >= 0) {
proto_tree_add_item(record_tree, hf_pcapng_record_name, tvb, offset, string_length + 1, encoding);
offset += string_length + 1;
} else {
proto_tree_add_item(record_tree, hf_pcapng_record_data, tvb, offset, (record_length - 16) - (offset - offset_string_start), encoding);
offset += (record_length - 16) - (offset - offset_string_start);
}
}
str = wmem_strdup_printf(wmem_packet_scope(), "%s",
address_to_display(wmem_packet_scope(), &addr));
break;
default:
proto_tree_add_item(record_tree, hf_pcapng_record_data, tvb, offset, record_length, ENC_NA);
offset += record_length;
}
if (record_code != 0 && record_length % 4) {
proto_item_set_len(record_item, record_length + 2 * 2 + (4 - record_length % 4));
record_length = 4 - record_length % 4;
proto_tree_add_item(record_tree, hf_pcapng_record_padding, tvb, offset, record_length, ENC_NA);
offset += record_length;
}
if (str)
proto_item_append_text(record_item, " = %s", str);
}
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - (offset - offset_record_start));
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, NULL);
}
break;
case BLOCK_INTERFACE_STATISTICS:
proto_tree_add_item(block_data_tree, hf_pcapng_interface_id, tvb, offset, 4, encoding);
interface_id = tvb_get_guint32(tvb, offset, encoding);
offset += 4;
pcapng_add_timestamp(block_data_tree, pinfo, tvb, offset, encoding, interface_id, info);
offset += 8;
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - 4 - 8);
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, NULL);
break;
case BLOCK_ENHANCED_PACKET:
proto_item_append_text(block_item, " %u", info->frame_number);
proto_tree_add_item(block_data_tree, hf_pcapng_interface_id, tvb, offset, 4, encoding);
interface_id = tvb_get_guint32(tvb, offset, encoding);
offset += 4;
pcapng_add_timestamp(block_data_tree, pinfo, tvb, offset, encoding, interface_id, info);
offset += 8;
proto_tree_add_item_ret_uint(block_data_tree, hf_pcapng_captured_length, tvb, offset, 4, encoding, &captured_length);
offset += 4;
proto_tree_add_item_ret_uint(block_data_tree, hf_pcapng_packet_length, tvb, offset, 4, encoding, &reported_length);
offset += 4;
packet_data_item = proto_tree_add_item(block_data_tree, hf_pcapng_packet_data, tvb, offset, captured_length, encoding);
if (pref_dissect_next_layer && interface_id < wmem_array_get_count(info->interfaces)) {
struct interface_description *interface_description;
proto_tree *packet_data_tree = proto_item_add_subtree(packet_data_item, ett_pcapng_packet_data);
pinfo->fd->num = info->frame_number;
interface_description = (struct interface_description *) wmem_array_index(info->interfaces, interface_id);
TRY {
call_dissector_with_data(pcap_pseudoheader_handle, tvb_new_subset(tvb, offset, captured_length, reported_length),
pinfo, packet_data_tree, &interface_description->link_type);
}
CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, packet_data_tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
info->frame_number += 1;
offset += captured_length;
if (captured_length % 4) {
proto_tree_add_item(block_data_tree, hf_pcapng_packet_padding, tvb, offset, captured_length % 4?(4 - captured_length % 4):0, ENC_NA);
offset += captured_length % 4?(4 - captured_length % 4):0;
}
next_tvb = tvb_new_subset_length(tvb, offset, block_data_length - 4 - 8 - 4 - 4 - captured_length - (captured_length % 4?(4 - captured_length % 4):0));
offset += dissect_options(block_data_tree, pinfo, block_type, next_tvb, encoding, NULL);
break;
case BLOCK_IRIG_TIMESTAMP:
case BLOCK_ARINC_429:
default:
offset += block_data_length;
}
proto_tree_add_item(block_tree, hf_pcapng_block_length, tvb, offset, 4, encoding);
offset += 4;
return offset;
}
static int
dissect_pcapng(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
static const guint8 pcapng_premagic[] = { 0x0A, 0x0D, 0x0D, 0x0A };
static const guint8 pcapng_magic[] = { 0x1A, 0x2B, 0x3C, 0x4D };
static const guint8 pcapng_swapped_magic[] = { 0x4D, 0x3C, 0x2B, 0x1A };
gint offset = 0;
guint32 length;
guint32 encoding;
proto_tree *main_tree;
proto_item *main_item;
struct info info;
if (tvb_memeql(tvb, 0, pcapng_premagic, sizeof(pcapng_premagic)) != 0)
return 0;
if (tvb_memeql(tvb, 8, pcapng_magic, sizeof(pcapng_magic)) != 0) {
if (tvb_memeql(tvb, 8, pcapng_swapped_magic, sizeof(pcapng_swapped_magic)) != 0) {
return 0;
}
}
info.file_number = 1;
info.interface_number = 0;
info.frame_number = 1;
info.interfaces = wmem_array_new(wmem_packet_scope(), sizeof(struct interface_description));
main_item = proto_tree_add_item(tree, proto_pcapng, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_pcapng);
encoding = tvb_get_guint32(tvb, offset + 8, ENC_HOST_ENDIAN);
if (encoding == 0x1A2B3C4D) {
encoding = ENC_LITTLE_ENDIAN;
} else if (encoding == 0x4D3C2B1A) {
encoding = ENC_BIG_ENDIAN;
} else {
expert_add_info(pinfo, main_item, &ei_unknown_encoding);
return offset;
}
while (tvb_captured_length_remaining(tvb, offset)) {
tvbuff_t *next_tvb;
length = tvb_get_guint32(tvb, offset + 4, encoding);
next_tvb = tvb_new_subset_length(tvb, offset, length);
offset += dissect_block(main_tree, pinfo, next_tvb, encoding, &info);
}
return offset;
}
static gboolean
dissect_pcapng_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_pcapng(tvb, pinfo, tree, NULL) > 0;
}
void
proto_register_pcapng(void)
{
module_t *module;
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_pcapng_block,
{ "Block", "pcapng.block",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_block_type,
{ "Block Type", "pcapng.block.type",
FT_UINT32, BASE_HEX, VALS(block_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_block_type_vendor,
{ "Block Type Vendor", "pcapng.block.type.vendor",
FT_BOOLEAN, 32, NULL, 0x80000000,
NULL, HFILL }
},
{ &hf_pcapng_block_type_value,
{ "Block Type Value", "pcapng.block.type.value",
FT_UINT32, BASE_HEX, VALS(block_type_vals), 0x7FFFFFFF,
NULL, HFILL }
},
{ &hf_pcapng_block_length,
{ "Block Length", "pcapng.block.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_block_data,
{ "Block Data", "pcapng.block.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_options,
{ "Options", "pcapng.options",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option,
{ "Option", "pcapng.options.option",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_interface_description,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_interface_description_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_enhanced_packet,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_enhanced_packet_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_packet,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_packet_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_name_resolution,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_name_resolution_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_interface_statistics,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_interface_statistics_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_length,
{ "Length", "pcapng.options.option.length",
FT_INT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data,
{ "Option Data", "pcapng.options.option.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_padding,
{ "Option Padding", "pcapng.options.option.padding",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_comment,
{ "Comment", "pcapng.options.option.data.comment",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_section_header_byte_order_magic,
{ "Byte Order Magic", "pcapng.section_header.byte_order_magic",
FT_UINT32, BASE_HEX, VALS(byte_order_magic_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_section_header_major_version,
{ "Major Version", "pcapng.section_header.version.major",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_section_header_minor_version,
{ "Minor Version", "pcapng.section_header.version.minor",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_section_header_section_length,
{ "Section Length", "pcapng.section_header.section_length",
FT_INT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_code_section_header,
{ "Code", "pcapng.options.option.code",
FT_UINT16, BASE_DEC, VALS(option_code_section_header_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_section_header_hardware,
{ "Hardware", "pcapng.options.option.data.hardware",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_section_header_os,
{ "OS", "pcapng.options.option.data.os",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_section_header_user_application,
{ "User Application", "pcapng.options.option.data.user_application",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_description_name,
{ "Name", "pcapng.options.option.data.interface.name",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_description_description,
{ "Description", "pcapng.options.option.data.interface.description",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_ipv4,
{ "IPv4", "pcapng.options.option.data.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_ipv4_mask,
{ "IPv4 Mask", "pcapng.options.option.data.ipv4_mask",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_ipv6,
{ "IPv6", "pcapng.options.option.data.ipv4",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_ipv6_mask,
{ "IPv6 Mask", "pcapng.options.option.data.ipv6_mask",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_mac_address,
{ "MAC Address", "pcapng.options.option.data.mac",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_eui_address,
{ "EUI Address", "pcapng.options.option.data.eui",
FT_EUI64, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_speed,
{ "Speed", "pcapng.options.option.data.interface.speed",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_timestamp_resolution,
{ "Timestamp Resolution", "pcapng.options.option.data.interface.timestamp_resolution",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_timestamp_resolution_base,
{ "Base", "pcapng.options.option.data.interface.timestamp_resolution.base",
FT_UINT8, BASE_HEX, VALS(timestamp_resolution_base_vals), 0x80,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_timestamp_resolution_value,
{ "Value", "pcapng.options.option.data.interface.timestamp_resolution.value",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_timezone,
{ "Timezone", "pcapng.options.option.data.interface.timezone",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_filter,
{ "Filter", "pcapng.options.option.data.interface.filter",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_os,
{ "OS", "pcapng.options.option.data.interface.os",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_fcs_length,
{ "FCS Length", "pcapng.options.option.data.interface.fcs_length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_timestamp_offset,
{ "Timestamp Offset", "pcapng.options.option.data.interface.timestamp_offset",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_drop_count,
{ "Drop Count", "pcapng.options.option.data.packet.drop_count",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_hash_algorithm,
{ "Hash Algorithm", "pcapng.options.option.data.packet.hash.algorithm",
FT_UINT8, BASE_HEX, VALS(packet_hash_algorithm_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_hash_data,
{ "Hash Data", "pcapng.options.option.data.packet.hash.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors,
{ "Link Layer Errors", "pcapng.options.option.data.packet.flags.link_layer_errors",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_symbol,
{ "Symbol Error", "pcapng.options.option.data.packet.flags.link_layer_errors.symbol",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_preamble,
{ "Preamble Error", "pcapng.options.option.data.packet.flags.link_layer_errors.preamble",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_start_frame_delimiter,
{ "Preamble Error", "pcapng.options.option.data.packet.flags.link_layer_errors.preamble",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_unaligned_frame,
{ "Preamble Error", "pcapng.options.option.data.packet.flags.link_layer_errors.preamble",
FT_BOOLEAN, 16, NULL, 0x4000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_wrong_inter_frame_gap,
{ "Wrong Inter Frame Gap", "pcapng.options.option.data.packet.flags.link_layer_errors.wrong_inter_frame_gap",
FT_BOOLEAN, 16, NULL, 0x2000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_packet_too_short,
{ "Packet Too Short", "pcapng.options.option.data.packet.flags.link_layer_errors.packet_too_short",
FT_BOOLEAN, 16, NULL, 0x1000,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_packet_too_long,
{ "Packet Too Long", "pcapng.options.option.data.packet.flags.link_layer_errors.packet_too_long",
FT_BOOLEAN, 16, NULL, 0x0800,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_crc_error,
{ "CRC Error", "pcapng.options.option.data.packet.flags.link_layer_errors.crc",
FT_BOOLEAN, 16, NULL, 0x0400,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_link_layer_errors_reserved,
{ "Reserved", "pcapng.options.option.data.packet.flags.link_layer_errors.reserved",
FT_UINT16, BASE_HEX, NULL, 0x03FF,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags,
{ "Flags", "pcapng.options.option.data.packet.flags",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_reserved,
{ "Reserved", "pcapng.options.option.data.packet.flags.reserved",
FT_UINT16, BASE_HEX, NULL, 0xFE00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_fcs_length,
{ "FCS Length", "pcapng.options.option.data.packet.flags.fcs_length",
FT_UINT16, BASE_DEC, NULL, 0x01E0,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_reception_type,
{ "Reception Type", "pcapng.options.option.data.packet.flags.reception_type",
FT_UINT16, BASE_HEX, VALS(flags_reception_type_vals), 0x001C,
NULL, HFILL }
},
{ &hf_pcapng_option_data_packet_flags_direction,
{ "Direction", "pcapng.options.option.data.packet.flags.direction",
FT_UINT16, BASE_HEX, VALS(packet_flags_direction_vals), 0x0003,
NULL, HFILL }
},
{ &hf_pcapng_option_data_dns_name,
{ "DNS Name", "pcapng.options.option.data.dns_name",
FT_STRING, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_start_time,
{ "Start Time", "pcapng.options.option.data.start_time",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_end_time,
{ "End Time", "pcapng.options.option.data.end_time",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_received,
{ "Number of Received Packets", "pcapng.options.option.data.interface.received",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_dropped,
{ "Number of Dropped Packets", "pcapng.options.option.data.interface.dropped",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_accepted_by_filter,
{ "Number of Accepted by Filter Packets", "pcapng.options.option.data.interface.accepted_by_filter",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_dropped_by_os,
{ "Number of Dropped Packets by OS", "pcapng.options.option.data.interface.dropped_by_os",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_option_data_interface_delivered_to_user,
{ "Number of Delivered to the User Packets", "pcapng.options.option.data.interface.delivered_to_user",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_interface_description_link_type,
{ "Link Type", "pcapng.interface_description.link_type",
FT_UINT16, BASE_DEC_HEX, VALS(link_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_interface_description_reserved,
{ "Reserved", "pcapng.interface_description.reserved",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_interface_description_snap_length,
{ "Snap Length", "pcapng.interface_description.snap_length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_packet_block_interface_id,
{ "Interface", "pcapng.packet.interface_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_packet_block_drops_count,
{ "Drops Count", "pcapng.packet.drops_count",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_captured_length,
{ "Captured Length", "pcapng.packet.captured_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_packet_length,
{ "Packet Length", "pcapng.packet.packet_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_packet_data,
{ "Packet Data", "pcapng.packet.packet_data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_packet_padding,
{ "Packet Padding", "pcapng.packet.padding",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_interface_id,
{ "Interface", "pcapng.interface_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_timestamp_high,
{ "Timestamp (High)", "pcapng.timestamp_high",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_timestamp_low,
{ "Timestamp (Low)", "pcapng.timestamp_low",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_timestamp,
{ "Timestamp", "pcapng.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_records,
{ "Records", "pcapng.records",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record,
{ "Record", "pcapng.records.record",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_code,
{ "Code", "pcapng.records.record.code",
FT_UINT16, BASE_DEC, VALS(record_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_length,
{ "Length", "pcapng.records.record.length",
FT_INT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_data,
{ "Record Data", "pcapng.records.record.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_padding,
{ "Record Padding", "pcapng.records.record.padding",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_ipv4,
{ "IPv4", "pcapng.records.record.data.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_ipv6,
{ "IPv6", "pcapng.records.record.data.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcapng_record_name,
{ "Name", "pcapng.records.record.data.name",
FT_STRINGZ, STR_ASCII, NULL, 0x00,
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_invalid_option_length, { "pcapng.invalid_option_length", PI_PROTOCOL, PI_ERROR, "Invalid Option Length", EXPFILL }},
{ &ei_invalid_record_length, { "pcapng.invalid_record_length", PI_PROTOCOL, PI_ERROR, "Invalid Record Length", EXPFILL }},
{ &ei_unknown_encoding, { "pcapng.unknown_encoding", PI_PROTOCOL, PI_ERROR, "Unknown Encoding", EXPFILL }}
};
static gint *ett[] = {
&ett_pcapng,
&ett_pcapng_section_header_block,
&ett_pcapng_block_data,
&ett_pcapng_options,
&ett_pcapng_option,
&ett_pcapng_records,
&ett_pcapng_record,
&ett_pcapng_packet_data
};
proto_pcapng = proto_register_protocol("PCAPNG File Format", "File-PCAPNG", "file-pcapng");
proto_register_field_array(proto_pcapng, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pcapng_handle = new_register_dissector("file-pcapng", dissect_pcapng, proto_pcapng);
module = prefs_register_protocol(proto_pcapng, NULL);
prefs_register_static_text_preference(module, "version",
"PCAPNG version: 1.0",
"Version of file-format supported by this dissector.");
prefs_register_bool_preference(module, "dissect_next_layer",
"Dissect next layer",
"Dissect next layer",
&pref_dissect_next_layer);
expert_module = expert_register_protocol(proto_pcapng);
expert_register_field_array(expert_module, ei, array_length(ei));
}
void
proto_reg_handoff_pcapng(void)
{
heur_dissector_add("wtap_file", dissect_pcapng_heur, "PCAPNG File", "pcapng_wtap", proto_pcapng, HEURISTIC_ENABLE);
}
