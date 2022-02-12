static void
proto_mpeg_descriptor_dissect_video_stream(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 mpeg1_only_flag;
mpeg1_only_flag = tvb_get_guint8(tvb, offset) & MPEG_DESCR_VIDEO_STREAM_MPEG1_ONLY_FLAG_MASK;
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_multiple_frame_rate_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_frame_rate_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_mpeg1_only_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_constrained_parameter_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_still_picture_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (mpeg1_only_flag == 0) {
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_profile_and_level_indication, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_chroma_format, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_frame_rate_extension_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_video_stream_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
proto_mpeg_descriptor_dissect_audio_stream(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_audio_stream_free_format_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_audio_stream_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_audio_stream_layer, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_audio_stream_variable_rate_audio_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_audio_stream_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_registration(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_mpeg_descr_reg_form_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while (offset-offset_start<len) {
proto_tree_add_item(tree, hf_mpeg_descr_reg_add_id_inf, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
static void
proto_mpeg_descriptor_dissect_data_stream_alignment(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_data_stream_alignment, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_ca(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_ca_system_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_ca_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ca_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len > 4)
proto_tree_add_item(tree, hf_mpeg_descr_ca_private, tvb, offset, len - 4, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_iso639(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
if (len > 1)
proto_tree_add_item(tree, hf_mpeg_descr_iso639_lang, tvb, offset, len - 1, ENC_ASCII|ENC_NA);
offset += len - 1;
proto_tree_add_item(tree, hf_mpeg_descr_iso639_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_system_clock(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_system_clock_external_clock_reference_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_system_clock_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_system_clock_accuracy_integer, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_system_clock_accuracy_exponent, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_system_clock_reserved2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_max_bitrate(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *rate_item;
guint32 rate;
proto_tree_add_item(tree, hf_mpeg_descr_max_bitrate_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
rate = tvb_get_ntoh24(tvb, offset) & MPEG_DESCR_MAX_BITRATE_MASK;
rate_item = proto_tree_add_item(tree, hf_mpeg_descr_max_bitrate, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(rate_item, " (%u bytes/sec)", rate * 50);
}
static void
proto_mpeg_descriptor_dissect_smoothing_buffer(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *leak_rate_item;
guint32 leak_rate;
proto_tree_add_item(tree, hf_mpeg_descr_smoothing_buffer_reserved1, tvb, offset, 3, ENC_BIG_ENDIAN);
leak_rate = tvb_get_ntoh24(tvb, offset) & MPEG_DESCR_SMOOTHING_BUFFER_LEAK_RATE_MASK;
leak_rate_item = proto_tree_add_item(tree, hf_mpeg_descr_smoothing_buffer_leak_rate, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(leak_rate_item, " (%u bytes/sec)", leak_rate * 400 / 8);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_smoothing_buffer_reserved2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_smoothing_buffer_size, tvb, offset, 3, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_std(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_std_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_std_leak_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_carousel_identifier(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint key_len;
guint8 format_id;
guint private_len = 0;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
format_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_format_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (format_id == 0x01) {
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_module_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_module_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_block_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_module_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_compression_method, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_original_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
key_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_object_key_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_object_key_data, tvb, offset, key_len, ENC_NA);
offset += key_len;
if (len > (key_len + 20))
private_len = len - 20 - key_len;
} else {
if (len > 5)
private_len = len - 5;
}
if (private_len)
proto_tree_add_item(tree, hf_mpeg_descr_carousel_identifier_private, tvb, offset, private_len, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_association_tag(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint16 use;
guint8 selector_len;
proto_tree_add_item(tree, hf_mpeg_descr_association_tag, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
use = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_use, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
selector_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_selector_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
if (use == 0x00) {
if (selector_len != 8)
return;
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_selector_bytes, tvb, offset, selector_len, ENC_NA);
offset += selector_len;
}
if (offset < end)
proto_tree_add_item(tree, hf_mpeg_descr_association_tag_private_bytes, tvb, offset, end - offset, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_avc_vid(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_profile_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_constraint_set0_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_constraint_set1_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_constraint_set2_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_compatible_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_level_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_still_present, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_24h_picture_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_avc_vid_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_network_name(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_network_name_descriptor, tvb, offset, len, ENC_ASCII|ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_service_list(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint16 svc_id;
proto_tree *svc_tree;
while (offset < end) {
svc_id = tvb_get_ntohs(tvb, offset);
svc_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3,
ett_mpeg_descriptor_service_list, NULL, "Service 0x%02x", svc_id);
proto_tree_add_item(svc_tree, hf_mpeg_descr_service_list_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(svc_tree, hf_mpeg_descr_service_list_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
proto_mpeg_descriptor_stuffing(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_stuffing, tvb, offset, len, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_satellite_delivery(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
double frequency, symbol_rate;
float orbital_position;
guint8 modulation_system;
frequency = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)) * 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1)) / 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+2)) / 1000.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+3)) / 100000.0;
proto_tree_add_double(tree, hf_mpeg_descr_satellite_delivery_frequency,
tvb, offset, 4, frequency);
offset += 4;
orbital_position = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)) * 10.0f +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1)) / 10.0f;
proto_tree_add_float(tree, hf_mpeg_descr_satellite_delivery_orbital_position,
tvb, offset, 2, orbital_position);
offset += 2;
modulation_system = tvb_get_guint8(tvb, offset) & MPEG_DESCR_SATELLITE_DELIVERY_MODULATION_SYSTEM_MASK;
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_west_east_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_polarization, tvb, offset, 1, ENC_BIG_ENDIAN);
if (modulation_system)
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_roll_off, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_zero, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_modulation_system, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_modulation_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
symbol_rate = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)) * 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1)) / 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+2)) / 1000.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+3)>>4) / 10000.0;
proto_tree_add_double_format_value(tree, hf_mpeg_descr_satellite_delivery_symbol_rate,
tvb, offset, 4, symbol_rate, "%3.4f MSym/s", symbol_rate);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_satellite_delivery_fec_inner, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_cable_delivery(tvbuff_t *tvb, guint offset, proto_tree *tree) {
double frequency, symbol_rate;
frequency = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)) * 100.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1)) +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+2)) / 100.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+3)) / 10000.0;
proto_tree_add_double_format_value(tree, hf_mpeg_descr_cable_delivery_frequency,
tvb, offset, 4, frequency, "%4.4f MHz", frequency);
offset += 4;
proto_tree_add_item(tree, hf_mpeg_descr_cable_delivery_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_cable_delivery_fec_outer, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_cable_delivery_modulation, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
symbol_rate = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset)) * 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1)) / 10.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+2)) / 1000.0 +
MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+3)>>4) / 10000.0;
proto_tree_add_double_format_value(tree, hf_mpeg_descr_cable_delivery_symbol_rate,
tvb, offset, 4, symbol_rate, "%3.4f MSymbol/s", symbol_rate);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_cable_delivery_fec_inner, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_vbi_data(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint8 svc_id, svc_len;
guint end = offset + len, svc_end;
proto_tree *svc_tree;
while (offset < end) {
svc_id = tvb_get_guint8(tvb, offset);
svc_len = tvb_get_guint8(tvb, offset + 1);
svc_tree = proto_tree_add_subtree_format(tree, tvb, offset, svc_len + 2,
ett_mpeg_descriptor_vbi_data_service, NULL, "Service 0x%02x", svc_id);
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_service_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_descr_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (svc_id) {
case 0x01:
case 0x02:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
svc_end = offset + svc_len;
while (offset < svc_end) {
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_field_parity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_line_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
default:
proto_tree_add_item(svc_tree, hf_mpeg_descr_vbi_data_reserved2, tvb, offset, svc_len, ENC_NA);
offset += svc_len;
break;
}
}
}
static void
proto_mpeg_descriptor_dissect_bouquet_name(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_bouquet_name, tvb, offset, len, ENC_ASCII|ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_service(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 prov_len, name_len;
guint enc_len;
dvb_encoding_e encoding;
proto_tree_add_item(tree, hf_mpeg_descr_service_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
prov_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_service_provider_name_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (prov_len>0) {
enc_len = dvb_analyze_string_charset(tvb, offset, prov_len, &encoding);
dvb_add_chartbl(tree, hf_mpeg_descr_service_provider_name_encoding, tvb, offset, enc_len, encoding);
proto_tree_add_item(tree, hf_mpeg_descr_service_provider,
tvb, offset+enc_len, prov_len-enc_len, dvb_enc_to_item_enc(encoding));
}
offset += prov_len;
name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_service_name_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (name_len>0) {
enc_len = dvb_analyze_string_charset(tvb, offset, name_len, &encoding);
dvb_add_chartbl(tree, hf_mpeg_descr_service_name_encoding, tvb, offset, enc_len, encoding);
proto_tree_add_item(tree, hf_mpeg_descr_service_name,
tvb, offset+enc_len, name_len-enc_len, dvb_enc_to_item_enc(encoding));
}
}
static void
proto_mpeg_descriptor_dissect_linkage(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint8 linkage_type, hand_over_type, origin_type;
guint end = offset + len;
guint population_id_loop_count;
guint16 population_id_base, population_id_mask;
proto_item *pi;
proto_tree *population_tree;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_transport_stream_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_original_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_linkage_type, tvb, offset, 1, ENC_BIG_ENDIAN);
linkage_type = tvb_get_guint8(tvb, offset);
offset += 1;
if (linkage_type == 0x08) {
proto_tree_add_item(tree, hf_mpeg_descr_linkage_hand_over_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_linkage_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_linkage_origin_type, tvb, offset, 1, ENC_BIG_ENDIAN);
hand_over_type = (tvb_get_guint8(tvb, offset) & MPEG_DESCR_LINKAGE_HAND_OVER_TYPE_MASK) >> MPEG_DESCR_LINKAGE_HAND_OVER_TYPE_SHIFT;
origin_type = tvb_get_guint8(tvb, offset) & MPEG_DESCR_LINKAGE_ORIGIN_TYPE_MASK;
offset += 1;
if ((hand_over_type == 1) || (hand_over_type == 2) || (hand_over_type == 3)) {
proto_tree_add_item(tree, hf_mpeg_descr_linkage_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (origin_type) {
proto_tree_add_item(tree, hf_mpeg_descr_linkage_initial_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
} else if (linkage_type == 0x0D) {
proto_tree_add_item(tree, hf_mpeg_descr_linkage_target_event_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_target_listed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_linkage_event_simulcast, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_linkage_reserved2, tvb, offset, 1, ENC_BIG_ENDIAN);
} else if (linkage_type == 0x81) {
if (offset+7>end)
return;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_interactive_network_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
population_id_loop_count = tvb_get_guint8(tvb, offset) + 1;
proto_tree_add_item(tree, hf_mpeg_descr_linkage_population_id_loop_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
while (population_id_loop_count--) {
population_id_base = tvb_get_ntohs(tvb, offset);
population_id_mask = tvb_get_ntohs(tvb, offset + 2);
pi = proto_tree_add_uint_format_value(tree, hf_mpeg_descr_linkage_population_id, tvb, offset, 4,
population_id_base<<16|population_id_mask,
"0x%04x / 0x%04x", population_id_base, population_id_mask);
population_tree = proto_item_add_subtree(pi, ett_mpeg_descriptor_linkage_population_id);
proto_tree_add_item(population_tree, hf_mpeg_descr_linkage_population_id_base, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(population_tree, hf_mpeg_descr_linkage_population_id_mask, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
if (end - offset > 0)
proto_tree_add_item(tree, hf_mpeg_descr_linkage_private_data_byte, tvb, offset, end - offset, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_short_event(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 name_len, text_len;
guint enc_len;
dvb_encoding_e encoding;
proto_tree_add_item(tree, hf_mpeg_descr_short_event_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
name_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_short_event_name_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (name_len>0) {
enc_len = dvb_analyze_string_charset(tvb, offset, name_len, &encoding);
dvb_add_chartbl(tree, hf_mpeg_descr_short_event_name_encoding, tvb, offset, enc_len, encoding);
proto_tree_add_item(tree, hf_mpeg_descr_short_event_name,
tvb, offset+enc_len, name_len-enc_len, dvb_enc_to_item_enc(encoding));
}
offset += name_len;
text_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_short_event_text_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (text_len>0) {
enc_len = dvb_analyze_string_charset(tvb, offset, text_len, &encoding);
dvb_add_chartbl(tree, hf_mpeg_descr_short_event_text_encoding, tvb, offset, enc_len, encoding);
proto_tree_add_item(tree, hf_mpeg_descr_short_event_text,
tvb, offset+enc_len, text_len-enc_len, dvb_enc_to_item_enc(encoding));
}
}
static void
proto_mpeg_descriptor_dissect_extended_event(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 items_len, item_descr_len, item_len, text_len;
guint items_end;
proto_tree *item_tree;
guint enc_len;
dvb_encoding_e encoding;
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_descriptor_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_last_descriptor_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
items_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_length_of_items, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
items_end = offset + items_len;
while (offset < items_end) {
item_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_mpeg_descriptor_extended_event_item, NULL, "Item");
item_descr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(item_tree, hf_mpeg_descr_extended_event_item_description_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_mpeg_descr_extended_event_item_description_char, tvb, offset, item_descr_len, ENC_ASCII|ENC_NA);
offset += item_descr_len;
item_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(item_tree, hf_mpeg_descr_extended_event_item_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_mpeg_descr_extended_event_item_char, tvb, offset, item_len, ENC_ASCII|ENC_NA);
offset += item_len;
}
text_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_text_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (text_len>0) {
enc_len = dvb_analyze_string_charset(tvb, offset, text_len, &encoding);
dvb_add_chartbl(tree, hf_mpeg_descr_extended_event_text_encoding, tvb, offset, enc_len, encoding);
proto_tree_add_item(tree, hf_mpeg_descr_extended_event_text,
tvb, offset+enc_len, text_len-enc_len, dvb_enc_to_item_enc(encoding));
}
}
static void
proto_mpeg_descriptor_dissect_component(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_item *cti;
proto_tree *content_type_tree;
proto_tree_add_item(tree, hf_mpeg_descr_component_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
cti = proto_tree_add_item(tree, hf_mpeg_descr_component_content_type, tvb, offset, 2, ENC_BIG_ENDIAN);
content_type_tree = proto_item_add_subtree(cti, ett_mpeg_descriptor_component_content_type);
proto_tree_add_item(content_type_tree, hf_mpeg_descr_component_stream_content, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(content_type_tree, hf_mpeg_descr_component_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_component_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_component_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
if (offset < len)
proto_tree_add_item(tree, hf_mpeg_descr_component_text, tvb, offset, len - offset, ENC_ASCII|ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_stream_identifier(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_stream_identifier_component_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_ca_identifier(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
while (offset < end) {
proto_tree_add_item(tree, hf_mpeg_descr_ca_identifier_system_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
static void
proto_mpeg_descriptor_dissect_content(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_item *ni;
proto_tree *nibble_tree;
guint end = offset + len;
while (offset < end) {
ni = proto_tree_add_item(tree, hf_mpeg_descr_content_nibble, tvb, offset, 1, ENC_BIG_ENDIAN);
nibble_tree = proto_item_add_subtree(ni, ett_mpeg_descriptor_content_nibble);
proto_tree_add_item(nibble_tree, hf_mpeg_descr_content_nibble_level_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nibble_tree, hf_mpeg_descr_content_nibble_level_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_content_user_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
proto_mpeg_descriptor_dissect_parental_rating(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_parental_rating_country_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_parental_rating_rating, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_teletext(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
while (offset < end) {
proto_tree_add_item(tree, hf_mpeg_descr_teletext_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_teletext_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_teletext_magazine_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_teletext_page_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
proto_mpeg_descriptor_dissect_local_time_offset(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint8 hour, min;
nstime_t local_time_offset, time_of_change, next_time_offset;
while (offset < end) {
proto_tree_add_item(tree, hf_mpeg_descr_local_time_offset_country_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_local_time_offset_region_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_local_time_offset_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_local_time_offset_polarity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
hour = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset));
min = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1));
nstime_set_zero(&local_time_offset);
local_time_offset.secs = hour*60*60 + min*60;
proto_tree_add_time_format_value(tree, hf_mpeg_descr_local_time_offset_offset,
tvb, offset, 2, &local_time_offset, "%02d:%02d", hour, min);
offset += 2;
if (packet_mpeg_sect_mjd_to_utc_time(tvb, offset, &time_of_change) < 0) {
proto_tree_add_time_format_value(tree, hf_mpeg_descr_local_time_offset_time_of_change, tvb, offset, 5, &time_of_change, "Unparseable time");
} else {
proto_tree_add_time(tree, hf_mpeg_descr_local_time_offset_time_of_change, tvb, offset, 5, &time_of_change);
}
offset += 5;
hour = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset));
min = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, offset+1));
nstime_set_zero(&next_time_offset);
next_time_offset.secs = hour*60*60 + min*60;
proto_tree_add_time_format_value(tree, hf_mpeg_descr_local_time_offset_next_time_offset,
tvb, offset, 2, &next_time_offset, "%02d:%02d", hour, min);
offset += 2;
}
}
static void
proto_mpeg_descriptor_dissect_subtitling(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
while (offset < end) {
proto_tree_add_item(tree, hf_mpeg_descr_subtitling_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_subtitling_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_subtitling_composition_page_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_subtitling_ancillary_page_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
static void
proto_mpeg_descriptor_dissect_terrestrial_delivery(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint64 centre_freq;
centre_freq = tvb_get_ntohl(tvb, offset) * 10;
proto_tree_add_uint64_format_value(tree, hf_mpeg_descr_terrestrial_delivery_centre_frequency, tvb, offset, 4,
centre_freq, "%d.%06d MHz", (guint)centre_freq/(1000*1000), (guint)centre_freq%(1000*1000));
offset += 4;
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_bandwidth, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_time_slicing_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_mpe_fec_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_constellation, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_hierarchy_information, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_code_rate_hp_stream, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_code_rate_lp_stream, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_guard_interval, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_transmission_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_other_frequency_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_terrestrial_delivery_reserved2, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_private_data_specifier(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_private_data_specifier_id, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
proto_mpeg_descriptor_dissect_data_bcast(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 selector_len, text_len;
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_bcast_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_component_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
selector_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_selector_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (selector_len > 0) {
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_selector_bytes, tvb, offset, selector_len, ENC_NA);
offset += selector_len;
}
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
text_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_text_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (text_len > 0)
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_text, tvb, offset, text_len, ENC_ASCII|ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_data_bcast_id(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_id_bcast_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len > 2)
proto_tree_add_item(tree, hf_mpeg_descr_data_bcast_id_id_selector_bytes, tvb, offset, len - 2, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_ac3(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint8 flags, component_type;
proto_tree *component_type_tree;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_component_type_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_bsid_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_mainid_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_asvc_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (flags & MPEG_DESCR_AC3_COMPONENT_TYPE_FLAG_MASK) {
component_type = tvb_get_guint8(tvb, offset);
component_type_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3,
ett_mpeg_descriptor_ac3_component_type, NULL, "Component Type 0x%02x", component_type);
proto_tree_add_item(component_type_tree, hf_mpeg_descr_ac3_component_type_reserved_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(component_type_tree, hf_mpeg_descr_ac3_component_type_full_service_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(component_type_tree, hf_mpeg_descr_ac3_component_type_service_type_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(component_type_tree, hf_mpeg_descr_ac3_component_type_number_of_channels_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (flags & MPEG_DESCR_AC3_BSID_FLAG_MASK) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_bsid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (flags & MPEG_DESCR_AC3_MAINID_FLAG_MASK) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_mainid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (flags & MPEG_DESCR_AC3_ASVC_FLAG_MASK) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_asvc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (offset < end)
proto_tree_add_item(tree, hf_mpeg_descr_ac3_additional_info, tvb, offset, end - offset, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_app_sig(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint offset_start;
offset_start = offset;
while ((offset - offset_start) < len) {
proto_tree_add_item(tree, hf_mpeg_descr_app_sig_app_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_app_sig_ait_ver, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
proto_mpeg_descriptor_dissect_default_authority(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
proto_tree_add_item(tree, hf_mpeg_descr_default_authority_name, tvb, offset, len, ENC_ASCII|ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_content_identifier(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len, crid_len;
guint8 crid, crid_location, crid_type;
proto_tree *crid_tree;
while (offset < end) {
crid = tvb_get_guint8(tvb, offset);
crid_type = (crid & MPEG_DESCR_CONTENT_IDENTIFIER_CRID_TYPE_MASK) >> 2;
crid_location = crid & MPEG_DESCR_CONTENT_IDENTIFIER_CRID_LOCATION_MASK;
if (crid_location == 0) {
crid_len = 2 + tvb_get_guint8(tvb, offset + 1);
} else if (crid_location == 1) {
crid_len = 3;
} else {
crid_len = 1;
}
crid_tree = proto_tree_add_subtree_format(tree, tvb, offset, crid_len,
ett_mpeg_descriptor_content_identifier_crid, NULL, "CRID type=0%02x", crid_type);
proto_tree_add_item(crid_tree, hf_mpeg_descr_content_identifier_crid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(crid_tree, hf_mpeg_descr_content_identifier_crid_location, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (crid_location == 0x00) {
crid_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(crid_tree, hf_mpeg_descr_content_identifier_crid_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(crid_tree, hf_mpeg_descr_content_identifier_crid_bytes, tvb, offset, crid_len, ENC_NA);
offset += crid_len;
} else if (crid_location == 0x01) {
proto_tree_add_item(crid_tree, hf_mpeg_descr_content_identifier_cird_ref, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
}
static void
proto_mpeg_descriptor_dissect_extension(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint offset_start;
guint8 tag_ext;
gboolean lang_code_present;
guint already_dissected;
offset_start = offset;
tag_ext = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_extension_tag_extension, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag_ext) {
case EXT_TAG_SUPP_AUDIO:
proto_tree_add_item(tree, hf_mpeg_descr_extension_supp_audio_mix_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_extension_supp_audio_ed_cla, tvb, offset, 1, ENC_BIG_ENDIAN);
lang_code_present = ((tvb_get_guint8(tvb, offset) & 0x01) == 0x01);
proto_tree_add_item(tree, hf_mpeg_descr_extension_supp_audio_lang_code_present, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (lang_code_present) {
proto_tree_add_item(tree, hf_mpeg_descr_extension_supp_audio_lang_code, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
}
already_dissected = offset-offset_start;
if (already_dissected<len)
proto_tree_add_item(tree, hf_mpeg_descr_private_data, tvb, offset, len-already_dissected, ENC_NA);
break;
default:
already_dissected = offset-offset_start;
if (already_dissected<len)
proto_tree_add_item(tree, hf_mpeg_descr_extension_data, tvb, offset, len-already_dissected, ENC_NA);
break;
}
}
static void
proto_mpeg_descriptor_dissect_ac3_system_a(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint8 bsmod_chans_fullsvc, bsmod, num_channels, textlen, lang;
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_srate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_bsid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_bitrate_limit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_bitrate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_surround, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
bsmod_chans_fullsvc = tvb_get_guint8(tvb, offset);
bsmod = (bsmod_chans_fullsvc & 0xe0) >> 5;
num_channels = (bsmod_chans_fullsvc & 0x1e) >> 1;
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_bsmod, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_num_channels, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_full_svc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_langcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (num_channels == 0) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_langcode2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (bsmod < 2) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_mainid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_asvcflags, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
textlen = tvb_get_guint8(tvb, offset) >> 1;
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_textlen, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_textcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += textlen;
lang = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_lang1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_lang2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (lang & 0x80) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_lang1_bytes, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
}
if (lang & 0x40) {
proto_tree_add_item(tree, hf_mpeg_descr_ac3_sysa_lang2_bytes, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
}
if (offset < end)
proto_tree_add_item(tree, hf_mpeg_descr_ac3_additional_info, tvb, offset, end - offset, ENC_NA);
}
static void
proto_mpeg_descriptor_dissect_logon_initialize(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
guint8 flags;
guint16 flags2;
if (len >= 1)
{
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_group_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (len >= 3)
{
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_logon_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (len >= 4)
{
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_continuous_carrier_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_continuous_carrier, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_security_handshake_required, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_prefix_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_data_unit_labelling_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_mini_slot_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_contention_based_mini_slot_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (len >= 5)
{
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_capacity_type_flag_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_capacity_type_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_traffic_burst_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (flags & MPEG_DESCR_LOGON_INITIALIZE_TRAFFIC_BURST_TYPE_MASK) {
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_connectivity, tvb, offset, 2, ENC_BIG_ENDIAN);
flags2 = tvb_get_ntohs(tvb, offset);
if (flags2 & MPEG_DESCR_LOGON_INITIALIZE_CONNECTIVITY_MASK) {
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_signalling_vpi_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_signalling_vpi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_signalling_vci, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_forward_signalling_vpi_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_forward_signalling_vpi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_forward_signalling_vci, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_vpi_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_vpi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_vci, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
} else {
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_trf_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_ctrl_mngm_pid_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_return_ctrl_mngm_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if ((offset < end) && (flags & MPEG_DESCR_LOGON_INITIALIZE_CAPACITY_TYPE_FLAG_MASK)) {
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_cra_level, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_vbdc_max_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_vbdc_max, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_rbdc_max, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_logon_initialize_rbdc_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
}
static void
proto_mpeg_descriptor_dissect_rcs_content(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree)
{
guint end = offset + len;
while (offset < end) {
proto_tree_add_item(tree, hf_mpeg_descr_rcs_content_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static guint
proto_mpeg_descriptor_dissect_private_ciplus(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint offset_start;
guint8 tag, len;
const gchar *tag_str;
proto_item *di;
proto_tree *descriptor_tree;
offset_start=offset;
tag = tvb_get_guint8(tvb, offset);
tag_str = try_val_to_str(tag, mpeg_descriptor_ciplus_tag_vals);
if (!tag_str)
return 0;
descriptor_tree = proto_tree_add_subtree_format(tree, tvb, offset_start, -1,
ett_mpeg_descriptor, &di, "CI+ private descriptor Tag=0x%02x", tag);
proto_tree_add_uint_format(descriptor_tree, hf_mpeg_descriptor_tag,
tvb, offset, 1, tag, "Descriptor Tag: %s (0x%02x)", tag_str, tag);
offset += 1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(descriptor_tree, hf_mpeg_descriptor_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (tag==CIPLUS_DESC_TAG_CNT_LBL) {
proto_tree_add_item(tree, hf_mpeg_descr_ciplus_cl_cb_min, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_ciplus_cl_cb_max, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mpeg_descr_ciplus_cl_lang, tvb, offset, 3, ENC_ASCII|ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_mpeg_descr_ciplus_cl_label, tvb, offset, len-offset, ENC_ASCII|ENC_NA);
offset += len-offset;
}
else if (tag==CIPLUS_DESC_TAG_SVC) {
guint8 str_len_byte;
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_visible, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_selectable, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_lcn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
str_len_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_prov_name, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset += 1+str_len_byte;
str_len_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_svc_name, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset += 1+str_len_byte;
}
else if (tag==CIPLUS_DESC_TAG_PROT) {
gboolean match_brand_flag;
guint8 num_brands, i;
guint remaining;
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_prot_free_ci_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
match_brand_flag = ((tvb_get_guint8(tvb, offset) & 0x40) == 0x40);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_prot_match_brand_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (match_brand_flag) {
num_brands = tvb_get_guint8(tvb, offset);
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_prot_num_entries, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i<num_brands; i++) {
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_ciplus_prot_brand_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
remaining = offset_start+2+len - offset;
if (remaining > 0) {
proto_tree_add_item(descriptor_tree, hf_mpeg_descr_private_data, tvb, offset, remaining, ENC_NA);
offset += remaining;
}
}
proto_item_set_len(di, offset-offset_start);
return offset-offset_start;
}
guint
proto_mpeg_descriptor_dissect(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint tag, len;
proto_tree *descriptor_tree;
tag = tvb_get_guint8(tvb, offset);
len = tvb_get_guint8(tvb, offset + 1);
descriptor_tree = proto_tree_add_subtree_format(tree, tvb, offset, len + 2,
ett_mpeg_descriptor, NULL, "Descriptor Tag=0x%02x", tag);
proto_tree_add_item(descriptor_tree, hf_mpeg_descriptor_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(descriptor_tree, hf_mpeg_descriptor_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (len == 0)
return 2;
switch (tag) {
case 0x02:
proto_mpeg_descriptor_dissect_video_stream(tvb, offset, descriptor_tree);
break;
case 0x03:
proto_mpeg_descriptor_dissect_audio_stream(tvb, offset, descriptor_tree);
break;
case 0x05:
proto_mpeg_descriptor_dissect_registration(tvb, offset, len, descriptor_tree);
break;
case 0x06:
proto_mpeg_descriptor_dissect_data_stream_alignment(tvb, offset, descriptor_tree);
break;
case 0x09:
proto_mpeg_descriptor_dissect_ca(tvb, offset, len, descriptor_tree);
break;
case 0x0A:
proto_mpeg_descriptor_dissect_iso639(tvb, offset, len, descriptor_tree);
break;
case 0x0B:
proto_mpeg_descriptor_dissect_system_clock(tvb, offset, descriptor_tree);
break;
case 0x0E:
proto_mpeg_descriptor_dissect_max_bitrate(tvb, offset, descriptor_tree);
break;
case 0x10:
proto_mpeg_descriptor_dissect_smoothing_buffer(tvb, offset, descriptor_tree);
break;
case 0x11:
proto_mpeg_descriptor_dissect_std(tvb, offset, descriptor_tree);
break;
case 0x13:
proto_mpeg_descriptor_dissect_carousel_identifier(tvb, offset, len, descriptor_tree);
break;
case 0x14:
proto_mpeg_descriptor_dissect_association_tag(tvb, offset, len, descriptor_tree);
break;
case 0x28:
proto_mpeg_descriptor_dissect_avc_vid(tvb, offset, descriptor_tree);
break;
case 0x40:
proto_mpeg_descriptor_dissect_network_name(tvb, offset, len, descriptor_tree);
break;
case 0x41:
proto_mpeg_descriptor_dissect_service_list(tvb, offset, len, descriptor_tree);
break;
case 0x42:
proto_mpeg_descriptor_stuffing(tvb, offset, len, descriptor_tree);
break;
case 0x43:
proto_mpeg_descriptor_dissect_satellite_delivery(tvb, offset, descriptor_tree);
break;
case 0x44:
proto_mpeg_descriptor_dissect_cable_delivery(tvb, offset, descriptor_tree);
break;
case 0x45:
proto_mpeg_descriptor_dissect_vbi_data(tvb, offset, len, descriptor_tree);
break;
case 0x47:
proto_mpeg_descriptor_dissect_bouquet_name(tvb, offset, len, descriptor_tree);
break;
case 0x48:
proto_mpeg_descriptor_dissect_service(tvb, offset, descriptor_tree);
break;
case 0x4A:
proto_mpeg_descriptor_dissect_linkage(tvb, offset, len, descriptor_tree);
break;
case 0x4D:
proto_mpeg_descriptor_dissect_short_event(tvb, offset, descriptor_tree);
break;
case 0x4E:
proto_mpeg_descriptor_dissect_extended_event(tvb, offset, descriptor_tree);
break;
case 0x50:
proto_mpeg_descriptor_dissect_component(tvb, offset, len, descriptor_tree);
break;
case 0x52:
proto_mpeg_descriptor_dissect_stream_identifier(tvb, offset, descriptor_tree);
break;
case 0x53:
proto_mpeg_descriptor_dissect_ca_identifier(tvb, offset, len, descriptor_tree);
break;
case 0x54:
proto_mpeg_descriptor_dissect_content(tvb, offset, len, descriptor_tree);
break;
case 0x55:
proto_mpeg_descriptor_dissect_parental_rating(tvb, offset, descriptor_tree);
break;
case 0x56:
proto_mpeg_descriptor_dissect_teletext(tvb, offset, len, descriptor_tree);
break;
case 0x58:
proto_mpeg_descriptor_dissect_local_time_offset(tvb, offset, len, descriptor_tree);
break;
case 0x59:
proto_mpeg_descriptor_dissect_subtitling(tvb, offset, len, descriptor_tree);
break;
case 0x5A:
proto_mpeg_descriptor_dissect_terrestrial_delivery(tvb, offset, descriptor_tree);
break;
case 0x5F:
proto_mpeg_descriptor_dissect_private_data_specifier(tvb, offset, descriptor_tree);
break;
case 0x64:
proto_mpeg_descriptor_dissect_data_bcast(tvb, offset, descriptor_tree);
break;
case 0x66:
proto_mpeg_descriptor_dissect_data_bcast_id(tvb, offset, len, descriptor_tree);
break;
case 0x6A:
proto_mpeg_descriptor_dissect_ac3(tvb, offset, len, descriptor_tree);
break;
case 0x6F:
proto_mpeg_descriptor_dissect_app_sig(tvb, offset, len, descriptor_tree);
break;
case 0x73:
proto_mpeg_descriptor_dissect_default_authority(tvb, offset, len, descriptor_tree);
break;
case 0x76:
proto_mpeg_descriptor_dissect_content_identifier(tvb, offset, len, descriptor_tree);
break;
case 0x7F:
proto_mpeg_descriptor_dissect_extension(tvb, offset, len, descriptor_tree);
break;
case 0x81:
proto_mpeg_descriptor_dissect_ac3_system_a(tvb, offset, len, descriptor_tree);
break;
case 0xA2:
proto_mpeg_descriptor_dissect_logon_initialize(tvb, offset, len, descriptor_tree);
break;
case 0xA7:
proto_mpeg_descriptor_dissect_rcs_content(tvb, offset, len, descriptor_tree);
break;
default:
proto_tree_add_item(descriptor_tree, hf_mpeg_descriptor_data, tvb, offset, len, ENC_NA);
break;
}
return len + 2;
}
guint
proto_mpeg_descriptor_loop_dissect(tvbuff_t *tvb, guint offset, guint loop_len, proto_tree *tree)
{
guint32 private_data_specifier = PRIVATE_DATA_SPECIFIER_RESERVED;
guint offset_start;
guint desc_len;
guint8 tag;
offset_start = offset;
while ((offset - offset_start) < loop_len) {
tag = tvb_get_guint8(tvb, offset);
if (tag == 0x5F) {
private_data_specifier = tvb_get_ntohl(tvb, offset+2);
}
if (try_val_to_str(tag, mpeg_descriptor_tag_vals)) {
desc_len = proto_mpeg_descriptor_dissect(tvb, offset, tree);
}
else {
switch (private_data_specifier) {
case PRIVATE_DATA_SPECIFIER_CIPLUS_LLP:
desc_len = proto_mpeg_descriptor_dissect_private_ciplus(tvb, offset, tree);
break;
default:
desc_len = 0;
break;
}
if (desc_len == 0) {
desc_len = proto_mpeg_descriptor_dissect(tvb, offset, tree);
}
}
offset += desc_len;
}
return offset-offset_start;
}
void
proto_register_mpeg_descriptor(void)
{
static hf_register_info hf[] = {
{ &hf_mpeg_descriptor_tag, {
"Descriptor Tag", "mpeg_descr.tag",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descriptor_tag_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descriptor_length, {
"Descriptor Length", "mpeg_descr.len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descriptor_data, {
"Descriptor Data", "mpeg_descr.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_multiple_frame_rate_flag, {
"Multiple Frame Rate Flag", "mpeg_descr.video_stream.multiple_frame_rate_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_video_stream_multiple_frame_rate_flag_vals),
MPEG_DESCR_VIDEO_STREAM_MULTIPLE_FRAME_RATE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_frame_rate_code, {
"Frame Rate Code", "mpeg_descr.video_stream.frame_rate_code",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_VIDEO_STREAM_FRAME_RATE_CODE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_mpeg1_only_flag, {
"MPEG1 Only Flag", "mpeg_descr.video_stream.mpeg1_only_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_VIDEO_STREAM_MPEG1_ONLY_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_constrained_parameter_flag, {
"Constrained Parameter Flag", "mpeg_descr.video_stream.constrained_parameter_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_VIDEO_STREAM_CONSTRAINED_PARAMETER_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_still_picture_flag, {
"Still Picture Flag", "mpeg_descr.video_stream.still_picture_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_VIDEO_STREAM_STILL_PICTURE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_profile_and_level_indication, {
"Profile and Level Indication", "mpeg_descr.video_stream.profile_level_ind",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_chroma_format, {
"Chroma Format", "mpeg_descr.video_stream.chroma_format",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_frame_rate_extension_flag, {
"Frame Rate Extension Flag", "mpeg_descr.video_stream.frame_rate_extension_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_VIDEO_STREAM_FRAME_RATE_EXTENSION_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_video_stream_reserved, {
"Reserved", "mpeg_descr.video_stream.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_VIDEO_STREAM_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_audio_stream_free_format_flag, {
"Free Format Flag", "mpeg_descr.audio_stream.free_format_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_audio_stream_free_format_flag_vals), MPEG_DESCR_AUDIO_STREAM_FREE_FORMAT_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_audio_stream_id, {
"ID", "mpeg_descr.audio_stream.id",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_audio_stream_id_vals), MPEG_DESCR_AUDIO_STREAM_ID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_audio_stream_layer, {
"Layer", "mpeg_descr.audio_stream.layer",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AUDIO_STREAM_LAYER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_audio_stream_variable_rate_audio_indicator, {
"Variable Rate Audio Indicator", "mpeg_descr.audio_stream.vbr_indicator",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_audio_stream_variable_rate_audio_indicator_vals),
MPEG_DESCR_AUDIO_STREAM_VARIABLE_RATE_AUDIO_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_audio_stream_reserved, {
"Reserved", "mpeg_descr.audio_stream.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AUDIO_STREAM_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_reg_form_id, {
"Format identifier", "mpeg_descr.registration.format_identifier",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_reg_add_id_inf, {
"Additional identification info", "mpeg_descr.registration.add_id_info",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_stream_alignment, {
"Data Stream Alignment", "mpeg_descr.data_stream_alignment.alignment",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_data_stream_alignment_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ca_system_id, {
"System ID", "mpeg_descr.ca.sys_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ca_reserved, {
"Reserved", "mpeg_descr.ca.reserved",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_CA_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ca_pid, {
"CA PID", "mpeg_descr.ca.pid",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_CA_PID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ca_private, {
"Private bytes", "mpeg_descr.ca.private",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_iso639_lang, {
"ISO 639 Language Code", "mpeg_descr.lang.code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_iso639_type, {
"ISO 639 Language Type", "mpeg_descr.lang.type",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_iso639_type_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_system_clock_external_clock_reference_indicator, {
"External Clock Reference Indicator", "mpeg_descr.sys_clk.external_clk_ref_ind",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_SYSTEM_CLOCK_EXTERNAL_CLOCK_REFERENCE_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_system_clock_reserved1, {
"Reserved", "mpeg_descr.sys_clk.reserved1",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_SYSTEM_CLOCK_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_system_clock_accuracy_integer, {
"Accuracy Integer", "mpeg_descr.sys_clk.accuracy_integer",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_SYSTEM_CLOCK_ACCURACY_INTEGER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_system_clock_accuracy_exponent, {
"Accuracy Exponent", "mpeg_descr.sys_clk.accuracy_exponent",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_SYSTEM_CLOCK_ACCURACY_EXPONENT_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_system_clock_reserved2, {
"Reserved", "mpeg_descr.sys_clk.reserved2",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_SYSTEM_CLOCK_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_max_bitrate_reserved, {
"Maximum Bitrate Reserved", "mpeg_descr.max_bitrate.reserved",
FT_UINT24, BASE_HEX, NULL, MPEG_DESCR_MAX_BITRATE_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_max_bitrate, {
"Maximum Bitrate", "mpeg_descr.max_bitrate.rate",
FT_UINT24, BASE_DEC, NULL, MPEG_DESCR_MAX_BITRATE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_smoothing_buffer_reserved1, {
"Reserved", "mpeg_descr.smoothing_buf.reserved1",
FT_UINT24, BASE_HEX, NULL, MPEG_DESCR_SMOOTHING_BUFFER_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_smoothing_buffer_leak_rate, {
"Leak Rate", "mpeg_descr.smoothing_buf.leak_rate",
FT_UINT24, BASE_DEC, NULL, MPEG_DESCR_SMOOTHING_BUFFER_LEAK_RATE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_smoothing_buffer_reserved2, {
"Reserved", "mpeg_descr.smoothing_buf.reserved2",
FT_UINT24, BASE_HEX, NULL, MPEG_DESCR_SMOOTHING_BUFFER_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_smoothing_buffer_size, {
"Buffer Size", "mpeg_descr.smoothing_buf.size",
FT_UINT24, BASE_DEC, NULL, MPEG_DESCR_SMOOTHING_BUFFER_SIZE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_std_reserved, {
"Reserved", "mpeg_descr.std.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_STD_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_std_leak_valid, {
"Leak Valid", "mpeg_descr.std.leak_valid",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_STD_LEAK_VALID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_id, {
"Carousel ID", "mpeg_descr.carousel_identifier.id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_format_id, {
"Format ID", "mpeg_descr.carousel_identifier.format_id",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_carousel_identifier_format_id_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_module_version, {
"Module Version", "mpeg_descr.carousel_identifier.module_version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_module_id, {
"Module ID", "mpeg_descr.carousel_identifier.module_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_block_size, {
"Block Size", "mpeg_descr.carousel_identifier.block_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_module_size, {
"Module Size", "mpeg_descr.carousel_identifier.module_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_compression_method, {
"Compression Method", "mpeg_descr.carousel_identifier.comp_method",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_original_size, {
"Original Size", "mpeg_descr.carousel_identifier.orig_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_timeout, {
"Timeout", "mpeg_descr.carousel_identifier.timeout",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_object_key_len, {
"Object Key Length", "mpeg_descr.carousel_identifier.key_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_object_key_data, {
"Object Key Data", "mpeg_descr.carousel_identifier.key_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_carousel_identifier_private, {
"Private Bytes", "mpeg_descr.carousel_identifier.private",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag, {
"Association Tag", "mpeg_descr.assoc_tag.tag",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_use, {
"Use", "mpeg_descr.assoc_tag.use",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_selector_len, {
"Selector Length", "mpeg_descr.assoc_tag.selector_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_transaction_id, {
"Transaction ID", "mpeg_descr.assoc_tag.transaction_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_timeout, {
"Timeout", "mpeg_descr.assoc_tag.timeout",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_selector_bytes, {
"Selector Bytes", "mpeg_descr.assoc_tag.selector_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_association_tag_private_bytes, {
"Private Bytes", "mpeg_descr.assoc_tag.private_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_profile_idc, {
"Profile IDC", "mpeg_descr.avc_vid.profile_idc",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_constraint_set0_flag, {
"Constraint Set0 Flag", "mpeg_descr.avc_vid.contraint_set0",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AVC_VID_CONSTRAINT_SET0_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_constraint_set1_flag, {
"Constraint Set1 Flag", "mpeg_descr.avc_vid.contraint_set1",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AVC_VID_CONSTRAINT_SET1_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_constraint_set2_flag, {
"Constraint Set2 Flag", "mpeg_descr.avc_vid.contraint_set2",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AVC_VID_CONSTRAINT_SET2_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_compatible_flags, {
"Constraint Compatible Flags", "mpeg_descr.avc_vid.compatible_flags",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AVC_VID_COMPATIBLE_FLAGS_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_level_idc, {
"Level IDC", "mpeg_descr.avc_vid.level_idc",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_still_present, {
"AVC Still Present", "mpeg_descr.avc_vid.still_present",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AVC_VID_STILL_PRESENT_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_24h_picture_flag, {
"AVC 24 Hour Picture Flag", "mpeg_descr.avc_vid.24h_picture_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_AVC_VID_24H_PICTURE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_avc_vid_reserved, {
"Reserved", "mpeg_descr.avc_vid.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AVC_VID_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_network_name_descriptor, {
"Network Name", "mpeg_descr.net_name.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_list_id, {
"Service ID", "mpeg_descr.svc_list.id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_list_type, {
"Service Type", "mpeg_descr.svc_list.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_service_type_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_stuffing, {
"Stuffing", "mpeg_descr.stuffing",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_frequency, {
"Frequency", "mpeg_descr.sat_delivery.freq",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_ghz, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_orbital_position, {
"Orbital Position", "mpeg_descr.sat_delivery.orbital_pos",
FT_FLOAT, BASE_NONE|BASE_UNIT_STRING, &units_degree_degrees, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_west_east_flag, {
"West East Flag", "mpeg_descr.sat_delivery.west_east_flag",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_satellite_delivery_west_east_flag_vals),
MPEG_DESCR_SATELLITE_DELIVERY_WEST_EAST_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_polarization, {
"Polarization", "mpeg_descr.sat_delivery.polarization",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_satellite_delivery_polarization_vals),
MPEG_DESCR_SATELLITE_DELIVERY_POLARIZATION_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_roll_off, {
"Roll Off", "mpeg_descr.sat_delivery.roll_off",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_satellite_delivery_roll_off_vals),
MPEG_DESCR_SATELLITE_DELIVERY_ROLL_OFF_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_zero, {
"Zero", "mpeg_descr.sat_delivery.zero",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_SATELLITE_DELIVERY_ZERO_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_modulation_system, {
"Modulation System", "mpeg_descr.sat_delivery.modulation_system",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_satellite_delivery_modulation_system_vals),
MPEG_DESCR_SATELLITE_DELIVERY_MODULATION_SYSTEM_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_modulation_type, {
"Modulation Type", "mpeg_descr.sat_delivery.modulation_type",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_satellite_delivery_modulation_type_vals),
MPEG_DESCR_SATELLITE_DELIVERY_MODULATION_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_symbol_rate, {
"Symbol Rate", "mpeg_descr.sat_delivery.symbol_rate",
FT_DOUBLE, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_satellite_delivery_fec_inner, {
"FEC Inner", "mpeg_descr.sat_delivery.fec_inner",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_satellite_delivery_fec_inner_vals_ext,
MPEG_DESCR_SATELLITE_DELIVERY_FEC_INNER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_frequency, {
"Frequency", "mpeg_descr.cable_delivery.freq",
FT_DOUBLE, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_reserved, {
"Reserved", "mpeg_descr.cable_delivery.reserved",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_CABLE_DELIVERY_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_fec_outer, {
"FEC Outer", "mpeg_descr.cable_delivery.fec_outer",
FT_UINT16, BASE_HEX, VALS(mpeg_descr_cable_delivery_fec_outer_vals),
MPEG_DESCR_CABLE_DELIVERY_FEC_OUTER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_modulation, {
"Modulation", "mpeg_descr.cable_delivery.modulation",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_cable_delivery_modulation_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_symbol_rate, {
"Symbol Rate", "mpeg_descr.cable_delivery.sym_rate",
FT_DOUBLE, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_cable_delivery_fec_inner, {
"FEC Inner", "mpeg_descr.cable_delivery.fec_inner",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_cable_delivery_fec_inner_vals_ext,
MPEG_DESCR_CABLE_DELIVERY_FEC_INNER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_service_id, {
"Data Service ID", "mpeg_descr.vbi_data.svc_id",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_vbi_data_service_id_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_descr_len, {
"Data Descriptor Length", "mpeg_descr.vbi_data.decr_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_reserved1, {
"Reserved", "mpeg_descr.vbi_data.reserved1",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_VBI_DATA_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_field_parity, {
"Field Parity", "mpeg_descr.vbi_data.field_parity",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_vbi_data_field_parity_vals),
MPEG_DESCR_VBI_DATA_FIELD_PARITY_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_line_offset, {
"Line offset", "mpeg_descr.vbi_data.line_offset",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_vbi_data_reserved2, {
"Reserved", "mpeg_descr.vbi_data.reserved2",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_bouquet_name, {
"Bouquet Name Descriptor", "mpeg_descr.bouquet_name.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_type, {
"Service Type", "mpeg_descr.svc.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_service_type_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_provider_name_length, {
"Provider Name Length", "mpeg_descr.svc.provider_name_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_provider_name_encoding, {
"Provider Name Encoding", "mpeg_descr.svc.provider_name_enc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_provider, {
"Service Provider Name", "mpeg_descr.svc.provider_name",
FT_STRING, STR_UNICODE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_name_length, {
"Service Name Length", "mpeg_descr.svc.svc_name_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_name_encoding, {
"Service Name Encoding", "mpeg_descr.svc.svn_name_enc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_service_name, {
"Service Name", "mpeg_descr.svc.svc_name",
FT_STRING, STR_UNICODE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_transport_stream_id, {
"Transport Stream ID", "mpeg_descr.linkage.tsid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_original_network_id, {
"Original Network ID", "mpeg_descr.linkage.original_nid",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_service_id, {
"Service ID", "mpeg_descr.linkage.svc_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_linkage_type, {
"Linkage Type", "mpeg_descr.linkage.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_linkage_linkage_type_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_hand_over_type, {
"Hand-Over Type", "mpeg_descr.linkage.hand_over_type",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LINKAGE_HAND_OVER_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_reserved1, {
"Reserved", "mpeg_descr.linkage.reserved1",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LINKAGE_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_origin_type, {
"Origin Type", "mpeg_descr.linkage.origin_type",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_linkage_origin_type_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_network_id, {
"Network ID", "mpeg_descr.linkage.network_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_initial_service_id, {
"Initial Service ID", "mpeg_descr.linkage.initial_svc_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_target_event_id, {
"Target Event ID", "mpeg_descr.linkage.target_evt_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_target_listed, {
"Target Listed", "mpeg_descr.linkage.target_listed",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_linkage_target_listed_vals),
MPEG_DESCR_LINKAGE_TARGET_LISTED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_event_simulcast, {
"Event Simulcast", "mpeg_descr.linkage.evt_simulcast",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_linkage_event_simulcast_vals),
MPEG_DESCR_LINKAGE_EVENT_SIMULCAST_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_reserved2, {
"Reserved", "mpeg_descr.linkage.reserved2",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LINKAGE_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_private_data_byte, {
"Private Data", "mpeg_descr.linkage.private_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_interactive_network_id, {
"Interactive Network ID", "mpeg_descr.interactive_network_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_population_id_loop_count, {
"Population ID loop count", "mpeg_descr.population_id_loop_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_population_id, {
"Population ID", "mpeg_descr.population_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_population_id_base, {
"Population ID Base", "mpeg_descr.population_id_base",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_linkage_population_id_mask, {
"Population ID Mask", "mpeg_descr.population_id_mask",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_lang_code, {
"Language Code", "mpeg_descr.short_evt.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_name_length, {
"Event Name Length", "mpeg_descr.short_evt.name_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_name_encoding, {
"Event Name Encoding", "mpeg_descr.short_evt.name_enc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_name, {
"Event Name", "mpeg_descr.short_evt.name",
FT_STRING, STR_UNICODE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_text_length, {
"Event Text Length", "mpeg_descr.short_evt.txt_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_text_encoding, {
"Event Text Encoding", "mpeg_descr.short_evt.txt_enc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_short_event_text, {
"Event Text", "mpeg_descr.short_evt.txt",
FT_STRING, STR_UNICODE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_descriptor_number, {
"Descriptor Number", "mpeg_descr.ext_evt.descr_num",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_EXTENDED_EVENT_DESCRIPTOR_NUMBER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_last_descriptor_number, {
"Last Descriptor Number", "mpeg_descr.ext_evt.last_descr_num",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_EXTENDED_EVENT_LAST_DESCRIPTOR_NUMBER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_lang_code, {
"Language Code", "mpeg_descr.ext_evt.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_length_of_items, {
"Length of items", "mpeg_descr.ext_evt.items_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_item_description_length, {
"Item Description Length", "mpeg_descr.ext_evt.item_descr_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_item_description_char, {
"Item Description", "mpeg_descr.ext_evt.item_descr",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_item_length, {
"Item Length", "mpeg_descr.ext_evt.item_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_item_char, {
"Item", "mpeg_descr.ext_evt.item",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_text_length, {
"Text Length", "mpeg_descr.ext_evt.txt_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_text_encoding, {
"Text Encoding", "mpeg_descr.ext_evt.txt_enc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extended_event_text, {
"Text", "mpeg_descr.ext_evt.txt",
FT_STRING, STR_UNICODE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_component_reserved, {
"Reserved", "mpeg_descr.component.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_COMPONENT_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_component_stream_content, {
"Stream Content", "mpeg_descr.component.stream_content",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_component_stream_content_vals),
MPEG_DESCR_COMPONENT_STREAM_CONTENT_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_component_type, {
"Component Type", "mpeg_descr.component.type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_component_content_type, {
"Stream Content and Component Type", "mpeg_descr.component.content_type",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_component_content_type_vals_ext,
MPEG_DESCR_COMPONENT_CONTENT_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_component_tag, {
"Component Tag", "mpeg_descr.component.tag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_component_lang_code, {
"Language Code", "mpeg_descr.component.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_component_text, {
"Text", "mpeg_descr.component.text",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_stream_identifier_component_tag, {
"Component Tag", "mpeg_descr.stream_id.component_tag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ca_identifier_system_id, {
"CA System ID", "mpeg_descr.ca_id.sys_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_content_nibble, {
"Nibble Level 1 and 2", "mpeg_descr.content.nibble_1_2",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_content_nibble_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_content_nibble_level_1, {
"Nibble Level 1", "mpeg_descr.content.nibble_lvl_1",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_content_nibble_level_1_vals_ext,
MPEG_DESCR_CONTENT_NIBBLE_LEVEL_1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_content_nibble_level_2, {
"Nibble Level 2", "mpeg_descr.content.nibble_lvl_2",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_CONTENT_NIBBLE_LEVEL_2_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_content_user_byte, {
"User Byte", "mpeg_descr.content.user",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_teletext_lang_code, {
"Language Code", "mpeg_descr.teletext.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_teletext_type, {
"Teletext Type", "mpeg_descr.teletext.type",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_teletext_type_vals),
MPEG_DESCR_TELETEXT_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_teletext_magazine_number, {
"Magazine Number", "mpeg_descr.teletext.magazine_num",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_TELETEXT_MAGAZINE_NUMBER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_teletext_page_number, {
"Page Number", "mpeg_descr.teletext.page_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_parental_rating_country_code, {
"Country Code", "mpeg_descr.parental_rating.country_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_parental_rating_rating, {
"Rating", "mpeg_descr.parental_rating.rating",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_parental_rating_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_country_code, {
"Country Code", "mpeg_descr.local_time_offset.country_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_region_id, {
"Region ID", "mpeg_descr.local_time_offset.region_id",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOCAL_TIME_OFFSET_COUNTRY_REGION_ID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_reserved, {
"Reserved", "mpeg_descr.local_time_offset.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOCAL_TIME_OFFSET_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_polarity, {
"Time Offset Polarity", "mpeg_descr.local_time_offset.polarity",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_local_time_offset_polarity_vals),
MPEG_DESCR_LOCAL_TIME_OFFSET_POLARITY, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_offset, {
"Local Time Offset", "mpeg_descr.local_time_offset.offset",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_time_of_change, {
"Time of Change", "mpeg_descr.local_time_offset.time_of_change",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_local_time_offset_next_time_offset, {
"Next Time Offset", "mpeg_descr.local_time_offset.next_time_offset",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_subtitling_lang_code, {
"Language Code", "mpeg_descr.subtitling.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_subtitling_type, {
"Subtitling Type", "mpeg_descr.subtitling.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_subtitling_type_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_subtitling_composition_page_id, {
"Composition Page ID", "mpeg_descr.subtitling.composition_page_id",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_subtitling_ancillary_page_id, {
"Ancillary Page ID", "mpeg_descr.subtitling.ancillary_page_id",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_centre_frequency, {
"Centre Frequency", "mpeg_descr.terr_delivery.centre_freq",
FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_bandwidth, {
"Bandwidth", "mpeg_descr.terr_delivery.bandwidth",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_bandwidth_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_BANDWIDTH_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_priority, {
"Priority", "mpeg_descr.terr_delivery.priority",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_priority_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_PRIORITY_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_time_slicing_indicator, {
"Time Slicing Indicator", "mpeg_descr.terr_delivery.time_slicing_ind",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_time_slicing_indicator_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_TIME_SLICING_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_mpe_fec_indicator, {
"MPE-FEC Indicator", "mpeg_descr.terr_delivery.mpe_fec_ind",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_mpe_fec_indicator_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_MPE_FEC_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_reserved1, {
"Reserved", "mpeg_descr.terr_delivery.reserved1",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_TERRESTRIAL_DELIVERY_RESERVED1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_constellation, {
"Constellation", "mpeg_descr.terr_delivery.constellation",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_constellation_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_CONSTELLATION_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_hierarchy_information, {
"Hierarchy Information", "mpeg_descr.terr_delivery.hierarchy_information",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_hierarchy_information_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_HIERARCHY_INFORMATION_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_code_rate_hp_stream, {
"Code Rate High Priority Stream", "mpeg_descr.terr_delivery.code_rate_hp_stream",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_code_rate_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_CODE_RATE_HP_STREAM_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_code_rate_lp_stream, {
"Code Rate Low Priority Stream", "mpeg_descr.terr_delivery.code_rate_lp_stream",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_code_rate_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_CODE_RATE_LP_STREAM_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_guard_interval, {
"Guard Interval", "mpeg_descr.terr_delivery.guard_interval",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_guard_interval_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_GUARD_INTERVAL_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_transmission_mode, {
"Transmission Mode", "mpeg_descr.terr_delivery.transmission_mode",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_transmission_mode_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_TRANSMISSION_MODE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_other_frequency_flag, {
"Other Frequency Flag", "mpeg_descr.terr_delivery.other_freq_flag",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_terrestrial_delivery_other_frequency_flag_vals),
MPEG_DESCR_TERRESTRIAL_DELIVERY_OTHER_FREQUENCY_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_terrestrial_delivery_reserved2, {
"Reserved", "mpeg_descr.terr_delivery.reserved2",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_private_data_specifier_id, {
"Private Data Specifier", "mpeg_descr.private_data_specifier.id",
FT_UINT32, BASE_HEX, VALS(mpeg_descr_data_specifier_id_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_bcast_id, {
"Data Broadcast ID", "mpeg_descr.data_bcast.id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_data_bcast_id_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_component_tag, {
"Component Tag", "mpeg_descr.data_bcast.component_tag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_selector_len, {
"Selector Length", "mpeg_descr.data_bcast.selector_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_selector_bytes, {
"Selector Bytes", "mpeg_descr.data_bcast.selector_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_lang_code, {
"Language Code", "mpeg_descr.data_bcast.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_text_len, {
"Text Length", "mpeg_descr.data_bcast.text_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_text, {
"Text", "mpeg_descr.data_bcast.text",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_id_bcast_id, {
"Data Broadcast ID", "mpeg_descr.data_bcast_id.id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_data_bcast_id_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_data_bcast_id_id_selector_bytes, {
"ID Selector Bytes", "mpeg_descr.data_bcast_id.id_selector_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_component_type_flag, {
"Component Type Flag", "mpeg_descr.ac3.component_type_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_ac3_component_type_flag_vals),
MPEG_DESCR_AC3_COMPONENT_TYPE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_bsid_flag, {
"BSID Flag", "mpeg_descr.ac3.bsid_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_ac3_bsid_flag_vals),
MPEG_DESCR_AC3_BSID_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_mainid_flag, {
"Main ID Flag", "mpeg_descr.ac3_main_id_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_ac3_mainid_flag_vals),
MPEG_DESCR_AC3_MAINID_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_asvc_flag, {
"ASVC Flag", "mpeg_descr.ac3.asvc_flag",
FT_UINT8, BASE_DEC, VALS(mpeg_descr_ac3_asvc_flag_vals),
MPEG_DESCR_AC3_ASVC_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_reserved, {
"Reserved", "mpeg_descr.ac3.reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_component_type_reserved_flag, {
"Type Reserved Flag", "mpeg_descr.ac3.component_type.reserved_flag",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_COMPONENT_TYPE_RESERVED_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_component_type_full_service_flag, {
"Full Service Flag", "mpeg_descr.ac3.component_type.full_service_flag",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_component_type_full_service_flag_vals),
MPEG_DESCR_AC3_COMPONENT_TYPE_FULL_SERVICE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_component_type_service_type_flags, {
"Service Type Flags", "mpeg_descr.ac3.component_type.service_type_flags",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_component_type_service_type_flags_vals),
MPEG_DESCR_AC3_COMPONENT_TYPE_SERVICE_TYPE_FLAGS_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_component_type_number_of_channels_flags, {
"Number of Channels Flags", "mpeg_descr.ac3.component_type.number_chan_flags",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_component_type_number_of_channels_flags_vals),
MPEG_DESCR_AC3_COMPONENT_TYPE_NUMBER_OF_CHANNELS_FLAGS, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_bsid, {
"BSID", "mpeg_descr.ac3.bsid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_mainid, {
"Main ID", "mpeg_descr.ac3.mainid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_asvc, {
"ASVC", "mpeg_descr.ac3.asvc",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_additional_info, {
"Additional Info", "mpeg_descr.ac3.additional_info",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_app_sig_app_type, {
"Application type", "mpeg_descr.app_sig.app_type",
FT_UINT16, BASE_HEX, NULL, 0x7FFF, NULL, HFILL
} },
{ &hf_mpeg_descr_app_sig_ait_ver, {
"AIT version", "mpeg_descr.app_sig.ait_ver",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL
} },
{ &hf_mpeg_descr_default_authority_name, {
"Default Authority Name", "mpeg_descr.default_authority.name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_content_identifier_crid_type, {
"CRID Type", "mpeg_descr.content_identifier.crid_type",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_content_identifier_crid_type_vals),
MPEG_DESCR_CONTENT_IDENTIFIER_CRID_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_content_identifier_crid_location, {
"CRID Location", "mpeg_descr.content_identifier.crid_location",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_content_identifier_crid_location_vals),
MPEG_DESCR_CONTENT_IDENTIFIER_CRID_LOCATION_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_content_identifier_crid_length, {
"CRID Length", "mpeg_descr.content_identifier.crid_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_content_identifier_crid_bytes, {
"CRID Bytes", "mpeg_descr.content_identifier.crid_bytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_content_identifier_cird_ref, {
"CRID Reference", "mpeg_descr.content_identifier.crid_ref",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_tag_extension, {
"Descriptor Tag Extension", "mpeg_descr.ext.tag",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_extension_tag_extension_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_data, {
"Descriptor Extension Data", "mpeg_descr.ext.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_supp_audio_mix_type, {
"Mix type", "mpeg_descr.ext.supp_audio.mix_type",
FT_UINT8, BASE_HEX, VALS(supp_audio_mix_type_vals), 0x80, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_supp_audio_ed_cla, {
"Editorial classification", "mpeg_descr.ext.supp_audio.ed_cla",
FT_UINT8, BASE_HEX, VALS(supp_audio_ed_cla), 0x7C, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_supp_audio_lang_code_present, {
"Language code present", "mpeg_descr.ext.supp_audio.lang_code_present",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL
} },
{ &hf_mpeg_descr_extension_supp_audio_lang_code, {
"ISO 639 language code", "mpeg_descr.ext.supp_audio.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_private_data, {
"Private data", "mpeg_descr.private_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_srate, {
"Sample Rate", "mpeg_descr.ac3.sysa_sample_rate",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_srate_flag_vals),
MPEG_DESCR_AC3_SYSA_SRATE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_bsid, {
"bsid", "mpeg_descr.ac3.sysa_bsid",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_BSID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_bitrate_limit, {
"Bitrate Code limit type", "mpeg_descr.ac3.sysa_bitrate_code_limit",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_bitrate_code_limit_vals),
MPEG_DESCR_AC3_SYSA_BITRATE_CODE_LIMIT_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_bitrate, {
"Bitrate Code", "mpeg_descr.ac3.sysa_bitrate_code",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_bitrate_code_vals),
MPEG_DESCR_AC3_SYSA_BITRATE_CODE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_surround, {
"Surround Mode", "mpeg_descr.ac3.sysa_surround_mode",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_surround_mode_vals),
MPEG_DESCR_AC3_SYSA_SURROUND_MODE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_bsmod, {
"Bsmod", "mpeg_descr.ac3.sysa_bsmod",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_BSMOD_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_num_channels, {
"Number of Channels", "mpeg_descr.ac3.sysa_num_channels",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_num_channels_vals),
MPEG_DESCR_AC3_SYSA_NUM_CHANNELS_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_full_svc, {
"Full Service", "mpeg_descr.ac3.sysa_full_svc",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_FULL_SVC_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_langcode, {
"Language Code (Deprecated)", "mpeg_descr.ac3.sysa_langcode",
FT_UINT8, BASE_HEX, NULL, 0xff, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_langcode2, {
"Language Code 2 (Deprecated)", "mpeg_descr.ac3.sysa_langcode2",
FT_UINT8, BASE_HEX, NULL, 0xff, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_mainid, {
"Main ID", "mpeg_descr.ac3.sysa_mainid",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_MAINID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_priority, {
"Priority", "mpeg_descr.ac3.sysa_priority",
FT_UINT8, BASE_HEX, VALS(mpeg_descr_ac3_sysa_priority_vals),
MPEG_DESCR_AC3_SYSA_PRIORITY_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_reserved, {
"Reserved", "mpeg_descr.ac3.sysa_reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_asvcflags, {
"Associated Service Flags", "mpeg_descr.ac3.sysa_asvcflags",
FT_UINT8, BASE_HEX, NULL, 0xff, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_textlen, {
"Text length", "mpeg_descr.ac3.sysa_textlen",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_TEXTLEN_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_textcode, {
"Text Code", "mpeg_descr.ac3.sysa_textcode",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_TEXTCODE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_lang1, {
"Language 1 Present", "mpeg_descr.ac3.sysa_lang1",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_LANG1_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_lang2, {
"Language 2 Present", "mpeg_descr.ac3.sysa_lang2",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_AC3_SYSA_LANG2_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_lang1_bytes, {
"Language 1 ISO 639 language code", "mpeg_descr.ac3.sysa_lang1_bytes",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ac3_sysa_lang2_bytes, {
"Language 2 ISO 639 language code", "mpeg_descr.ac3.sysa_lang2_bytes",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_group_id, {
"Group ID", "mpeg_descr.logon_init.group_id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_logon_id, {
"Logon ID", "mpeg_descr.logon_init.logon_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_continuous_carrier_reserved, {
"Continuous Carrier Reserved", "mpeg_descr.logon_init.continuous_carrier_reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_CONTINUOUS_CARRIER_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_continuous_carrier, {
"Continuous Carrier", "mpeg_descr.logon_init.continuous_carrier",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_CONTINUOUS_CARRIER_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_security_handshake_required, {
"Security Handshake Required", "mpeg_descr.logon_init.security_handshake_required",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_SECURITY_HANDSHAKE_REQUIRED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_prefix_flag, {
"Prefix Flag", "mpeg_descr.logon_init.prefix_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_PREFIX_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_data_unit_labelling_flag, {
"Unit Labelling Flag", "mpeg_descr.logon_init.data_unit_labelling_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_DATA_UNIT_LABELLING_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_mini_slot_flag, {
"Mini Slot Flag", "mpeg_descr.logon_init.mini_slot_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_MINI_SLOT_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_contention_based_mini_slot_flag, {
"Contention Based Mini Slot Flag", "mpeg_descr.logon_init.contention_based_mini_slot_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_CONTENTION_BASED_MINI_SLOT_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_capacity_type_flag_reserved, {
"Capacity Type Flag Reserved", "mpeg_descr.logon_init.capactity_type_flag_reserved",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_CAPACITY_TYPE_FLAG_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_capacity_type_flag, {
"Capacity Type Flag", "mpeg_descr.logon_init.capactity_type_flag",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_CAPACITY_TYPE_FLAG_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_traffic_burst_type, {
"Traffic Burst Type", "mpeg_descr.logon_init.traffic_burst_type",
FT_UINT8, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_TRAFFIC_BURST_TYPE_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_trf_pid, {
"Return TRF PID", "mpeg_descr.logon_init.return_trf_pid",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_TRF_PID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_ctrl_mngm_pid_reserved, {
"Return CTRL MNGM PID Reserved", "mpeg_descr.logon_init.return_mngm_pid_reserved",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_CTRL_MNGM_PID_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_ctrl_mngm_pid, {
"Return CTRL MNGM PID", "mpeg_descr.logon_init.return_mngm_pid",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_CTRL_MNGM_PID_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_connectivity, {
"Connectivity", "mpeg_descr.logon_init.connectivity",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_CONNECTIVITY_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_vpi_reserved, {
"Return VPI Reserved", "mpeg_descr.logon_init.return_vpi_reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_VPI_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_vpi, {
"Return VPI", "mpeg_descr.logon_init.return_vpi",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_VPI_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_vci, {
"Return VCI", "mpeg_descr.logon_init.return_vci",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_signalling_vpi_reserved, {
"Return Signalling VPI Reserved", "mpeg_descr.logon_init.return_signalling_vpi_reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_SIGNALLING_VPI_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_signalling_vpi, {
"Return Signalling VPI", "mpeg_descr.logon_init.return_signalling_vpi",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_SIGNALLING_VPI_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_return_signalling_vci, {
"Return Signalling VCI", "mpeg_descr.logon_init.return_signalling_vci",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_forward_signalling_vpi_reserved, {
"Forward Signalling VPI Reserved", "mpeg_descr.logon_init.forward_signalling_vpi_reserved",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_SIGNALLING_VPI_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_forward_signalling_vpi, {
"Forward Signalling VPI", "mpeg_descr.logon_init.forward_signalling_vpi",
FT_UINT8, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_RETURN_SIGNALLING_VPI_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_forward_signalling_vci, {
"Forward Signalling VCI", "mpeg_descr.logon_init.forward_signalling_vci",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_cra_level, {
"CRA Level", "mpeg_descr.logon_init.cra_level",
FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_vbdc_max_reserved, {
"VDBC Max Reserved", "mpeg_descr.logon_init.vdbc_max_reserved",
FT_UINT16, BASE_HEX, NULL, MPEG_DESCR_LOGON_INITIALIZE_VDBC_MAX_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_vbdc_max, {
"VDBC Max", "mpeg_descr.logon_init.vdbc_max",
FT_UINT16, BASE_DEC, NULL, MPEG_DESCR_LOGON_INITIALIZE_VDBC_MAX_MASK, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_rbdc_max, {
"RDBC Max", "mpeg_descr.logon_init.rdbc_max",
FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_logon_initialize_rbdc_timeout, {
"RDBC Timeout", "mpeg_descr.logon_init.rdbc_timeout",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_rcs_content_table_id, {
"Table ID", "mpeg_descr.rcs_content.tid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_cl_cb_min, {
"Content byte minimum value", "mpeg_descr.ciplus_content_label.content_byte_min",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_cl_cb_max, {
"Content byte maximum value", "mpeg_descr.ciplus_content_label.content_byte_max",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_cl_lang, {
"ISO 639 language code", "mpeg_descr.ciplus_content_label.lang_code",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_cl_label, {
"Content label", "mpeg_descr.ciplus_content_label.label",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_id, {
"Service ID", "mpeg_descr.ciplus_svc.id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_type, {
"Service type", "mpeg_descr.ciplus_svc.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mpeg_descr_service_type_vals_ext, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_visible, {
"Visible Service Flag", "mpeg_descr.ciplus_svc.visible",
FT_UINT16, BASE_HEX, NULL, 0x8000, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_selectable, {
"Selectable Service Flag", "mpeg_descr.ciplus_svc.selectable",
FT_UINT16, BASE_HEX, NULL, 0x4000, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_lcn, {
"Logical Channel Number", "mpeg_descr.ciplus_svc.lcn",
FT_UINT16, BASE_DEC, NULL, 0x3FFF, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_prov_name, {
"Service Provider Name", "mpeg_descr.ciplus_svc.provider_name",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_svc_name, {
"Service Name", "mpeg_descr.ciplus_svc.name",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_prot_free_ci_mode, {
"Free CI mode", "mpeg_descr.ciplus_prot.free_ci_mode",
FT_BOOLEAN, 8, TFS(&tfs_prot_noprot), 0x80, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_prot_match_brand_flag, {
"Match brand flag", "mpeg_descr.ciplus_prot.match_brand_flag",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x40, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_prot_num_entries, {
"Number of entries", "mpeg_descr.ciplus_prot.num_entries",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_mpeg_descr_ciplus_prot_brand_id, {
"CICAM brand identifier", "mpeg_descr.ciplus_prot.brand_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_mpeg_descriptor,
&ett_mpeg_descriptor_extended_event_item,
&ett_mpeg_descriptor_component_content_type,
&ett_mpeg_descriptor_content_nibble,
&ett_mpeg_descriptor_vbi_data_service,
&ett_mpeg_descriptor_content_identifier_crid,
&ett_mpeg_descriptor_service_list,
&ett_mpeg_descriptor_ac3_component_type,
&ett_mpeg_descriptor_linkage_population_id
};
proto_mpeg_descriptor = proto_register_protocol("MPEG2 Descriptors", "MPEG Descriptor", "mpeg_descr");
proto_register_field_array(proto_mpeg_descriptor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
