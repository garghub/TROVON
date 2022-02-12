static inline ctrl_ref_vals
get_ctrl_ref_vals(guint16 ctrl_val_type)
{
ctrl_ref_vals ret;
switch(ctrl_val_type) {
case AEM_CONTROL_LINEAR_INT8:
case AEM_CONTROL_SELECTOR_INT8:
case AEM_CONTROL_ARRAY_INT8:
ret.hf = hf_aem_ctrl_int8;
ret.size = 1;
break;
case AEM_CONTROL_LINEAR_UINT8:
case AEM_CONTROL_SELECTOR_UINT8:
case AEM_CONTROL_ARRAY_UINT8:
ret.hf = hf_aem_ctrl_uint8;
ret.size = 1;
break;
case AEM_CONTROL_LINEAR_INT16:
case AEM_CONTROL_SELECTOR_INT16:
case AEM_CONTROL_ARRAY_INT16:
ret.hf = hf_aem_ctrl_int16;
ret.size = 2;
break;
case AEM_CONTROL_LINEAR_UINT16:
case AEM_CONTROL_SELECTOR_UINT16:
case AEM_CONTROL_ARRAY_UINT16:
ret.hf = hf_aem_ctrl_uint16;
ret.size = 2;
break;
case AEM_CONTROL_LINEAR_INT32:
case AEM_CONTROL_SELECTOR_INT32:
case AEM_CONTROL_ARRAY_INT32:
ret.hf = hf_aem_ctrl_int32;
ret.size = 4;
break;
case AEM_CONTROL_LINEAR_UINT32:
case AEM_CONTROL_SELECTOR_UINT32:
case AEM_CONTROL_ARRAY_UINT32:
ret.hf = hf_aem_ctrl_uint32;
ret.size = 4;
break;
case AEM_CONTROL_LINEAR_FLOAT:
case AEM_CONTROL_SELECTOR_FLOAT:
case AEM_CONTROL_ARRAY_FLOAT:
ret.hf = hf_aem_ctrl_float;
ret.size = 4;
break;
case AEM_CONTROL_LINEAR_INT64:
case AEM_CONTROL_SELECTOR_INT64:
case AEM_CONTROL_ARRAY_INT64:
ret.hf = hf_aem_ctrl_int64;
ret.size = 8;
break;
case AEM_CONTROL_LINEAR_UINT64:
case AEM_CONTROL_SELECTOR_UINT64:
case AEM_CONTROL_ARRAY_UINT64:
ret.hf = hf_aem_ctrl_uint64;
ret.size = 8;
break;
case AEM_CONTROL_LINEAR_DOUBLE:
case AEM_CONTROL_SELECTOR_DOUBLE:
case AEM_CONTROL_ARRAY_DOUBLE:
ret.hf = hf_aem_ctrl_double;
ret.size = 8;
break;
case AEM_CONTROL_BODE_PLOT:
ret.hf = -1;
ret.size = 12;
break;
default:
ret.size = 0;
ret.hf = -1;
break;
}
return ret;
}
static void
dissect_17221_stream_format(tvbuff_t *tvb, proto_tree *tree)
{
proto_item *stream_tree;
proto_item *stream_ti;
guint8 version;
guint8 subtype;
guint8 sf;
guint8 fmt;
guint8 fdf_evt;
stream_ti = proto_tree_add_item(tree, hf_aem_stream_format, tvb,
0, 8, ENC_NA);
stream_tree = proto_item_add_subtree(stream_ti, ett_aem_stream_format);
version = tvb_get_guint8(tvb, 0) & AEM_MASK_SF_VERSION;
proto_tree_add_item(stream_tree, hf_aem_sf_version, tvb,
AEM_OFFSET_SF_VERSION, 1, ENC_BIG_ENDIAN);
if (version == 0) {
subtype = tvb_get_guint8(tvb, AEM_OFFSET_SF_SUBTYPE) & AEM_MASK_SF_SUBTYPE;
proto_tree_add_item(stream_tree, hf_aem_sf_subtype, tvb,
AEM_OFFSET_SF_SUBTYPE, 1, ENC_BIG_ENDIAN);
switch(subtype) {
case IEC_61883_IIDC_SUBTYPE:
sf = tvb_get_guint8(tvb, 1) & AEM_MASK_SF;
proto_tree_add_item(stream_tree, hf_aem_sf, tvb,
AEM_OFFSET_SF, 1, ENC_BIG_ENDIAN);
if (sf == 0) {
proto_tree_add_item(stream_tree, hf_aem_iidc_format, tvb,
AEM_OFFSET_IIDC_FORMAT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_iidc_mode, tvb,
AEM_OFFSET_IIDC_MODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_iidc_rate, tvb,
AEM_OFFSET_IIDC_RATE, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(stream_tree, hf_aem_fmt, tvb,
AEM_OFFSET_FMT, 1, ENC_BIG_ENDIAN);
fmt = tvb_get_guint8(tvb, AEM_OFFSET_FMT) & 0x7F;
if (fmt == 0x20) {
proto_tree_add_item(stream_tree, hf_aem_fdf_evt, tvb,
AEM_OFFSET_FDF_EVT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_fdf_sfc, tvb,
AEM_OFFSET_FDF_SFC, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_dbs, tvb,
AEM_OFFSET_DBS, 1, ENC_BIG_ENDIAN);
fdf_evt = tvb_get_guint8(tvb, AEM_OFFSET_FDF_EVT) & AEM_MASK_FDF_EVT;
proto_tree_add_item(stream_tree, hf_aem_b_flag, tvb,
AEM_OFFSET_B, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_nb_flag, tvb,
AEM_OFFSET_NB, 1, ENC_BIG_ENDIAN);
if (fdf_evt == 0x00) {
proto_tree_add_item(stream_tree, hf_aem_label_iec_60958_cnt, tvb,
AEM_OFFSET_LABEL_IEC_60958_CNT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_label_mbla_cnt, tvb,
AEM_OFFSET_LABEL_MBLA_CNT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_label_midi_cnt, tvb,
AEM_OFFSET_LABEL_MIDI_CNT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_label_smpte_cnt, tvb,
AEM_OFFSET_LABEL_SMPTE_CNT, 1, ENC_BIG_ENDIAN);
}
} else if (fmt == 0x01) {
proto_tree_add_item(stream_tree, hf_aem_video_mode, tvb,
AEM_OFFSET_VIDEO_MODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_compress_mode, tvb,
AEM_OFFSET_COMPRESS_MODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(stream_tree, hf_aem_color_space, tvb,
AEM_OFFSET_COLOR_SPACE, 1, ENC_BIG_ENDIAN);
}
}
break;
case MMA_SUBTYPE:
break;
case AVTP_AUDIO_SUBTYPE:
break;
case AVTP_VIDEO_SUBTYPE:
break;
case EXPERIMENTAL_SUBTYPE:
break;
default:
break;
}
}
}
static void
dissect_17221_video_format(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_aecp_video_format, tvb,
0, 4, ENC_NA);
}
static void
dissect_17221_video_aspect_ratio(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_aecp_video_format, tvb,
0, 2, ENC_NA);
}
static void
dissect_17221_video_frame_size(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_aecp_video_format, tvb,
0, 4, ENC_NA);
}
static void
dissect_17221_sensor_format(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_aecp_video_format, tvb,
0, 8, ENC_NA);
}
static void
dissect_17221_ctrl_val(tvbuff_t *tvb, proto_tree *tree, guint16 num_ctrl_vals, guint16 ctrl_val_type,
guint16 ctrl_offset)
{
proto_item *ctrl_item;
proto_item *ctrl_subtree;
int i;
guint32 bin_blob_size;
gint string_length;
ctrl_ref_vals ref;
ctrl_item = proto_tree_add_item(tree, hf_aem_ctrl_vals, tvb,
0, 0, ENC_NA);
ctrl_subtree = proto_item_add_subtree(ctrl_item, ett_aem_ctrl_vals);
ref = get_ctrl_ref_vals(ctrl_val_type);
if (ctrl_val_type < 0xa) {
for(i = 0; i < num_ctrl_vals; ++i) {
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += ref.size;
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += ref.size;
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += ref.size;
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += ref.size;
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += ref.size;
proto_tree_add_item(ctrl_subtree, hf_aem_unit, tvb,
ctrl_offset, 2, ENC_BIG_ENDIAN);
ctrl_offset += 2;
proto_tree_add_item(ctrl_subtree, hf_aem_string_ref, tvb,
ctrl_offset, 2, ENC_BIG_ENDIAN);
ctrl_offset += 2;
}
} else if (ctrl_val_type > 0x9 && ctrl_val_type < 0x14) {
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += 2;
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += 2;
for(i = 0; i < num_ctrl_vals; ++i) {
proto_tree_add_item(ctrl_subtree, ref.hf, tvb,
ctrl_offset, ref.size, ENC_BIG_ENDIAN);
ctrl_offset += 2;
}
proto_tree_add_item(ctrl_subtree, hf_aem_unit, tvb,
ctrl_offset, 2, ENC_BIG_ENDIAN);
} else if (ctrl_val_type == 0x14) {
tvb_get_const_stringz(tvb, ctrl_offset, &string_length);
proto_tree_add_item(ctrl_subtree, hf_aem_string, tvb,
ctrl_offset, string_length, ENC_ASCII|ENC_NA);
} else if (ctrl_val_type == 0x15) {
for(i = 0; i < 12 + (num_ctrl_vals * 3); ++i) {
proto_tree_add_item(ctrl_subtree, hf_aem_ctrl_float, tvb,
ctrl_offset, 4, ENC_BIG_ENDIAN);
ctrl_offset += 4;
}
} else if (ctrl_val_type > 0x15 && ctrl_val_type < 0x1f) {
} else if (ctrl_val_type == 0xfffe) {
proto_tree_add_item(ctrl_subtree, hf_aem_guid, tvb,
ctrl_offset, 8, ENC_BIG_ENDIAN);
ctrl_offset += 8;
bin_blob_size = tvb_get_ntohl(tvb, ctrl_offset);
proto_tree_add_item(ctrl_subtree, hf_aem_blob_size, tvb,
ctrl_offset, 4, ENC_BIG_ENDIAN);
ctrl_offset += 4;
proto_tree_add_item(ctrl_subtree, hf_aem_binary_blob, tvb,
ctrl_offset, bin_blob_size, ENC_NA);
}
}
static void
dissect_17221_aem(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 desc_type;
guint16 ctrl_val_type;
guint16 num_ctrl_vals;
tvbuff_t *next_tvb;
int i;
proto_item *mr_subtree;
proto_item *mr_item;
guint32 mr_offset;
guint16 mr_counter;
gfloat frequency;
gint freq_mult;
gint base_freq;
proto_item *aem_tree;
proto_item *desc_ti;
desc_type = tvb_get_ntohs(tvb, 0);
desc_ti = proto_tree_add_item(tree, hf_aecp_descriptor_type, tvb,
AEM_OFFSET_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
aem_tree = proto_item_add_subtree(desc_ti, ett_aem_descriptor);
proto_tree_add_item(aem_tree, hf_aecp_descriptor_index, tvb,
AEM_OFFSET_DESCRIPTOR_ID, 2, ENC_BIG_ENDIAN);
switch(desc_type) {
case AEM_DESCRIPTOR_ENTITY:
proto_tree_add_item(aem_tree, hf_aem_entity_id, tvb,
ENTITY_OFFSET_ENTITY_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_entity_model_id, tvb,
ENTITY_OFFSET_ENTITY_MODEL_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_efu_mode, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_address_access_supported, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_gateway_entity, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_aem_supported, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_legacy_avc, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_assoc_id_support, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_assoc_id_valid, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_vendor_unique, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_class_a_supported, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_class_b_supported, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_gptp_supported, tvb,
ENTITY_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talker_stream_srcs, tvb,
ENTITY_OFFSET_TALKER_STREAM_SOURCES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talker_cap, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_implement, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_other_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_control_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_media_clk_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_smpte_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_midi_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_audio_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_video_src, tvb,
ENTITY_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_listener_stream_sinks, tvb,
ENTITY_OFFSET_LISTENER_STREAM_SINKS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_listener_cap, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_implement, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_other_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_control_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_media_clk_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_smpte_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_midi_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_audio_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_video_sink, tvb,
ENTITY_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_controller_cap, tvb,
ENTITY_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_cont_cap_implement, tvb,
ENTITY_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_cont_cap_layer3_proxy, tvb,
ENTITY_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_avail_index, tvb,
ENTITY_OFFSET_AVAILABLE_INDEX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aecp_association_id, tvb,
ENTITY_OFFSET_ASSOCIATION_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_entity_name, tvb,
ENTITY_OFFSET_ENTITY_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_vendor_name_string, tvb,
ENTITY_OFFSET_VENDOR_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_model_name_string, tvb,
ENTITY_OFFSET_MODEL_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_firmware_version, tvb,
ENTITY_OFFSET_FIRMWARE_VERSION, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_group_name, tvb,
ENTITY_OFFSET_GROUP_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_serial_number, tvb,
ENTITY_OFFSET_SERIAL_NUMBER, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_configurations_count, tvb,
ENTITY_OFFSET_CONFIGURATIONS_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_configuration, tvb,
ENTITY_OFFSET_CURRENT_CONFIGURATION, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CONFIGURATION:
proto_tree_add_item(aem_tree, hf_aem_configuration_name, tvb,
CONFIGURATION_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_configuration_name_string, tvb,
CONFIGURATION_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_descriptor_counts_count, tvb,
CONFIGURATION_OFFSET_DESCRIPTOR_COUNTS_COUNT, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_descriptor_counts_offset, tvb,
CONFIGURATION_OFFSET_DESCRIPTOR_COUNTS_OFFSET, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, CONFIGURATION_OFFSET_DESCRIPTOR_COUNTS_COUNT);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_desc_counts);
mr_offset = CONFIGURATION_OFFSET_DESCRIPTOR_COUNTS;
for(i = 0; i < mr_counter; ++i)
{
proto_tree_add_item(mr_subtree, hf_aecp_descriptor_type, tvb, mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_count, tvb, mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_AUDIO_UNIT:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
AUDIO_UNIT_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
AUDIO_UNIT_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
AUDIO_UNIT_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_input_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_STREAM_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_input_port, tvb,
AUDIO_UNIT_OFFSET_BASE_STREAM_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_output_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_STREAM_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_output_port, tvb,
AUDIO_UNIT_OFFSET_BASE_STREAM_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_input_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_EXTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_input_port, tvb,
AUDIO_UNIT_OFFSET_BASE_EXTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_output_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_EXTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_output_port, tvb,
AUDIO_UNIT_OFFSET_BASE_EXTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_input_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_INTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_input_port, tvb,
AUDIO_UNIT_OFFSET_BASE_INTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_output_ports, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_INTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_output_port, tvb,
AUDIO_UNIT_OFFSET_BASE_INTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
AUDIO_UNIT_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
AUDIO_UNIT_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_signal_selectors, tvb,
AUDIO_UNIT_OFFSET_NUMBER_SIGNAL_SELECTORS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_signal_selector, tvb,
AUDIO_UNIT_OFFSET_BASE_SIGNAL_SELECTOR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_mixers, tvb,
AUDIO_UNIT_OFFSET_NUMBER_MIXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_mixer, tvb,
AUDIO_UNIT_OFFSET_BASE_MIXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_matrices, tvb,
AUDIO_UNIT_OFFSET_NUMBER_MATRICES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_matrix, tvb,
AUDIO_UNIT_OFFSET_BASE_MATRIX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_splitters, tvb,
AUDIO_UNIT_OFFSET_NUMBER_SPLITTERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_splitter, tvb,
AUDIO_UNIT_OFFSET_BASE_SPLITTER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_combiners, tvb,
AUDIO_UNIT_OFFSET_NUMBER_COMBINERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_combiner, tvb,
AUDIO_UNIT_OFFSET_BASE_COMBINER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_demultiplexers, tvb,
AUDIO_UNIT_OFFSET_NUMBER_DEMULTIPLEXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_demultiplexer, tvb,
AUDIO_UNIT_OFFSET_BASE_DEMULTIPLEXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_multiplexers, tvb,
AUDIO_UNIT_OFFSET_NUMBER_MULTIPLEXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_multiplexer, tvb,
AUDIO_UNIT_OFFSET_BASE_MULTIPLEXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_transcoders, tvb,
AUDIO_UNIT_OFFSET_NUMBER_TRANSCODERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_transcoder, tvb,
AUDIO_UNIT_OFFSET_BASE_TRANSCODER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_control_blocks, tvb,
AUDIO_UNIT_OFFSET_NUMBER_CONTROL_BLOCKS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control_block, tvb,
AUDIO_UNIT_OFFSET_BASE_CONTROL_BLOCK, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_sample_rate, tvb,
AUDIO_UNIT_OFFSET_CURRENT_SAMPLE_RATE, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sample_rates_offset, tvb,
AUDIO_UNIT_OFFSET_SAMPLE_RATES_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sample_rates_count, tvb,
AUDIO_UNIT_OFFSET_SAMPLE_RATES_COUNT, 2, ENC_BIG_ENDIAN);
mr_offset = tvb_get_ntohs(tvb, AUDIO_UNIT_OFFSET_SAMPLE_RATES_OFFSET);
mr_counter = tvb_get_ntohs(tvb, AUDIO_UNIT_OFFSET_SAMPLE_RATES_COUNT);
mr_item = proto_tree_add_item(aem_tree, hf_aem_sample_rates, tvb,
mr_offset, mr_counter * 4, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_sample_rates);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_pull_field, tvb,
mr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_base_frequency, tvb,
mr_offset, 4, ENC_BIG_ENDIAN);
base_freq = tvb_get_ntohl(tvb, mr_offset);
freq_mult = base_freq;
freq_mult &= 0xe0000000;
freq_mult = freq_mult >> 29;
base_freq &= 0x1fffffff;
frequency = freq_mult == 0 ? 1 :
freq_mult == 1 ? 1 / (gfloat)1.001 :
freq_mult == 2 ? (gfloat)1.001 :
freq_mult == 3 ? 24 / 25 :
freq_mult == 4 ? 54 / 24 : 0;
frequency *= base_freq;
proto_tree_add_float(mr_subtree, hf_aem_frequency, tvb, mr_offset, 4, frequency);
mr_offset += 4;
}
break;
case AEM_DESCRIPTOR_VIDEO_UNIT:
case AEM_DESCRIPTOR_SENSOR_UNIT:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
VIDEO_UNIT_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
VIDEO_UNIT_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
AUDIO_UNIT_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_input_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_STREAM_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_input_port, tvb,
VIDEO_UNIT_OFFSET_BASE_STREAM_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_output_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_STREAM_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_output_port, tvb,
VIDEO_UNIT_OFFSET_BASE_STREAM_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_input_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_EXTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_input_port, tvb,
VIDEO_UNIT_OFFSET_BASE_EXTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_output_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_EXTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_output_port, tvb,
VIDEO_UNIT_OFFSET_BASE_EXTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_input_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_INTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_input_port, tvb,
VIDEO_UNIT_OFFSET_BASE_INTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_output_ports, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_INTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_output_port, tvb,
VIDEO_UNIT_OFFSET_BASE_INTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
VIDEO_UNIT_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
VIDEO_UNIT_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_signal_selectors, tvb,
VIDEO_UNIT_OFFSET_NUMBER_SIGNAL_SELECTORS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_signal_selector, tvb,
VIDEO_UNIT_OFFSET_BASE_SIGNAL_SELECTOR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_mixers, tvb,
VIDEO_UNIT_OFFSET_NUMBER_MIXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_mixer, tvb,
VIDEO_UNIT_OFFSET_BASE_MIXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_matrices, tvb,
VIDEO_UNIT_OFFSET_NUMBER_MATRICES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_matrix, tvb,
VIDEO_UNIT_OFFSET_BASE_MATRIX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_splitters, tvb,
VIDEO_UNIT_OFFSET_NUMBER_SPLITTERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_splitter, tvb,
VIDEO_UNIT_OFFSET_BASE_SPLITTER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_combiners, tvb,
VIDEO_UNIT_OFFSET_NUMBER_COMBINERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_combiner, tvb,
VIDEO_UNIT_OFFSET_BASE_COMBINER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_demultiplexers, tvb,
VIDEO_UNIT_OFFSET_NUMBER_DEMULTIPLEXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_demultiplexer, tvb,
VIDEO_UNIT_OFFSET_BASE_DEMULTIPLEXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_multiplexers, tvb,
VIDEO_UNIT_OFFSET_NUMBER_MULTIPLEXERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_multiplexer, tvb,
VIDEO_UNIT_OFFSET_BASE_MULTIPLEXER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_transcoders, tvb,
VIDEO_UNIT_OFFSET_NUMBER_TRANSCODERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_transcoder, tvb,
VIDEO_UNIT_OFFSET_BASE_TRANSCODER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_control_blocks, tvb,
VIDEO_UNIT_OFFSET_NUMBER_CONTROL_BLOCKS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control_block, tvb,
VIDEO_UNIT_OFFSET_BASE_CONTROL_BLOCK, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STREAM_INPUT:
case AEM_DESCRIPTOR_STREAM_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_stream_name, tvb,
STREAM_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_stream_name_string, tvb,
STREAM_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
STREAM_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_stream_flags, tvb,
STREAM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_stream_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
STREAM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_class_a, tvb,
STREAM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_class_b, tvb,
STREAM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_length(tvb, STREAM_OFFSET_CURRENT_FORMAT, 8);
dissect_17221_stream_format(next_tvb, aem_tree);
proto_tree_add_item(aem_tree, hf_aem_formats_offset, tvb,
STREAM_OFFSET_FORMATS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_formats, tvb,
STREAM_OFFSET_NUMBER_OF_FORMATS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_0, tvb,
STREAM_OFFSET_BACKUP_TALKER_GUID_0, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_0, tvb,
STREAM_OFFSET_BACKUP_TALKER_UNIQUE_0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_1, tvb,
STREAM_OFFSET_BACKUP_TALKER_GUID_1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_1, tvb,
STREAM_OFFSET_BACKUP_TALKER_UNIQUE_1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_2, tvb,
STREAM_OFFSET_BACKUP_TALKER_GUID_2, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_2, tvb,
STREAM_OFFSET_BACKUP_TALKER_UNIQUE_2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backedup_talker_guid, tvb,
STREAM_OFFSET_BACKEDUP_TALKER_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backedup_talker_unique, tvb,
STREAM_OFFSET_BACKEDUP_TALKER_UNIQUE_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_interface_id, tvb,
STREAM_OFFSET_AVB_INTERFACE_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_buffer_length, tvb,
STREAM_OFFSET_BUFFER_LENGTH, 2, ENC_BIG_ENDIAN);
mr_offset = tvb_get_ntohs(tvb, STREAM_OFFSET_FORMATS_OFFSET);
mr_counter = tvb_get_ntohs(tvb, STREAM_OFFSET_NUMBER_OF_FORMATS);
mr_item = proto_tree_add_item(aem_tree, hf_aem_stream_formats, tvb,
mr_offset, mr_counter * 8, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_stream_formats);
for(i = 0; i < mr_counter; ++i) {
next_tvb = tvb_new_subset_length(tvb, mr_offset, 8);
dissect_17221_stream_format(next_tvb, mr_subtree);
mr_offset += 8;
}
break;
case AEM_DESCRIPTOR_JACK_INPUT:
case AEM_DESCRIPTOR_JACK_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_jack_name, tvb,
JACK_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_jack_name_string, tvb,
JACK_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_jack_flags, tvb,
JACK_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_jack_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_captive, tvb,
JACK_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
JACK_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_jack_type, tvb,
JACK_OFFSET_JACK_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
JACK_OFFSET_JACK_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
JACK_OFFSET_JACK_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STREAM_PORT_INPUT:
case AEM_DESCRIPTOR_STREAM_PORT_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
STREAM_PORT_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
STREAM_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
STREAM_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
STREAM_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
STREAM_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
STREAM_PORT_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
STREAM_PORT_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_clusters, tvb,
STREAM_PORT_OFFSET_NUMBER_OF_CLUSTERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_cluster, tvb,
STREAM_PORT_OFFSET_BASE_CLUSTER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_audio_maps, tvb,
STREAM_PORT_OFFSET_NUMBER_AUDIO_MAPS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_audio_map, tvb,
STREAM_PORT_OFFSET_BASE_AUDIO_MAP, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_EXTERNAL_PORT_INPUT:
case AEM_DESCRIPTOR_EXTERNAL_PORT_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
EXTERNAL_PORT_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
EXTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
EXTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
EXTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
EXTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
EXTERNAL_PORT_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
EXTERNAL_PORT_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
EXTERNAL_PORT_OFFSET_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_index, tvb,
EXTERNAL_PORT_OFFSET_SIGNAL_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_output, tvb,
EXTERNAL_PORT_OFFSET_SIGNAL_OUTPUT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
EXTERNAL_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_jack_id, tvb,
EXTERNAL_PORT_OFFSET_JACK_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_INTERNAL_PORT_INPUT:
case AEM_DESCRIPTOR_INTERNAL_PORT_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_clock_domain_id, tvb,
INTERNAL_PORT_OFFSET_CLOCK_DOMAIN_INDEX, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
INTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
INTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
INTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
INTERNAL_PORT_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
INTERNAL_PORT_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
INTERNAL_PORT_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
INTERNAL_PORT_OFFSET_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_index, tvb,
INTERNAL_PORT_OFFSET_SIGNAL_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_output, tvb,
INTERNAL_PORT_OFFSET_SIGNAL_OUTPUT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
INTERNAL_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_jack_id, tvb,
INTERNAL_PORT_OFFSET_INTERNAL_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_AVB_INTERFACE:
proto_tree_add_item(aem_tree, hf_aem_interface_name, tvb,
AVB_INTERFACE_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_interface_name_string, tvb,
AVB_INTERFACE_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aecp_mac_address, tvb,
AVB_INTERFACE_OFFSET_MAC_ADDRESS, 6, ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_avb_interface_flags, tvb,
AVB_INTERFACE_OFFSET_INTERFACE_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_clock_identity, tvb,
AVB_INTERFACE_OFFSET_CLOCK_IDENTITY, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_priority1, tvb,
AVB_INTERFACE_OFFSET_PRIORITY1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_clock_class, tvb,
AVB_INTERFACE_OFFSET_CLOCK_CLASS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_offset_scaled_log_variance, tvb,
AVB_INTERFACE_OFFSET_OFFSET_SCALED_LOG_VARIANCE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_clock_accuracy, tvb,
AVB_INTERFACE_OFFSET_CLOCK_ACCURACY, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_priority2, tvb,
AVB_INTERFACE_OFFSET_PRIORITY2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_domain_number, tvb,
AVB_INTERFACE_OFFSET_DOMAIN_NUMBER, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_log_sync_interval, tvb,
AVB_INTERFACE_OFFSET_LOG_SYNC_INTERVAL, 1, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CLOCK_SOURCE:
proto_tree_add_item(aem_tree, hf_aem_clock_source_name, tvb,
CLOCK_SOURCE_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_clock_source_name_string, tvb,
CLOCK_SOURCE_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_flags, tvb,
CLOCK_SOURCE_OFFSET_CLOCK_SOURCE_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_type, tvb,
CLOCK_SOURCE_OFFSET_CLOCK_SOURCE_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aecp_clock_source_id, tvb,
CLOCK_SOURCE_OFFSET_CLOCK_SOURCE_IDENTIFIER, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_location_type, tvb,
CLOCK_SOURCE_OFFSET_CLOCK_SOURCE_LOCATION_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_location_id, tvb,
CLOCK_SOURCE_OFFSET_CLOCK_SOURCE_LOCATION_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_AUDIO_MAP:
proto_tree_add_item(aem_tree, hf_aem_mappings_offset, tvb,
AUDIO_MAP_OFFSET_MAPPINGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_mappings, tvb,
AUDIO_MAP_OFFSET_NUMBER_OF_MAPPINGS, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_mappings, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_mappings);
mr_offset = tvb_get_ntohs(tvb, AUDIO_MAP_OFFSET_MAPPINGS_OFFSET);
mr_counter = tvb_get_ntohs(tvb, AUDIO_MAP_OFFSET_NUMBER_OF_MAPPINGS);
proto_item_set_len(mr_item, mr_counter * 8);
for(i = 0; i < mr_counter; i++) {
proto_tree_add_item(mr_subtree, hf_aem_mapping_stream_index, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_mapping_stream_channel, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_mapping_cluster_offset, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_mapping_cluster_channel, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_AUDIO_CLUSTER:
proto_tree_add_item(aem_tree, hf_aem_configuration_name, tvb,
AUDIO_CLUSTER_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_configuration_name_string, tvb,
AUDIO_CLUSTER_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AUDIO_CLUSTER_OFFSET_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_index, tvb,
AUDIO_CLUSTER_OFFSET_SIGNAL_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_output, tvb,
AUDIO_CLUSTER_OFFSET_SIGNAL_OUTPUT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_path_latency, tvb,
AUDIO_CLUSTER_OFFSET_PATH_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
AUDIO_CLUSTER_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_channel_count, tvb,
AUDIO_CLUSTER_OFFSET_CHANNEL_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_am824_label, tvb,
AUDIO_CLUSTER_OFFSET_FORMAT, 1, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CONTROL:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
CONTROL_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
CONTROL_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
CONTROL_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
CONTROL_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
CONTROL_OFFSET_CONTROL_DOMAIN, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_value_type, tvb,
CONTROL_OFFSET_CONTROL_VALUE_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_type, tvb,
CONTROL_OFFSET_CONTROL_TYPE, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_reset_time, tvb,
CONTROL_OFFSET_RESET_TIME, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_values_offset, tvb,
CONTROL_OFFSET_VALUES_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_values, tvb,
CONTROL_OFFSET_NUMBER_OF_VALUES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
CONTROL_OFFSET_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_index, tvb,
CONTROL_OFFSET_SIGNAL_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_output, tvb,
CONTROL_OFFSET_SIGNAL_OUTPUT, 2, ENC_BIG_ENDIAN);
ctrl_val_type = tvb_get_ntohs(tvb, CONTROL_OFFSET_CONTROL_VALUE_TYPE);
num_ctrl_vals = tvb_get_ntohs(tvb, CONTROL_OFFSET_NUMBER_OF_VALUES);
mr_offset = tvb_get_ntohs(tvb, CONTROL_OFFSET_VALUES_OFFSET);
dissect_17221_ctrl_val(tvb, aem_tree, num_ctrl_vals, ctrl_val_type,
mr_offset);
break;
case AEM_DESCRIPTOR_SIGNAL_SELECTOR:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
SIGNAL_SELECTOR_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
SIGNAL_SELECTOR_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
SIGNAL_SELECTOR_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
SIGNAL_SELECTOR_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
SIGNAL_SELECTOR_OFFSET_CONTROL_DOMAIN, 2, ENC_BIG_ENDIAN);
#if 0
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
AEM_OFFSET_CONTROL_NAME_SIGS, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
AEM_OFFSET_CONTROL_NAME_STRING_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sources_offset, tvb,
AEM_OFFSET_SOURCES_OFFSET_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_sources, tvb,
AEM_OFFSET_NUMBER_OF_SOURCES_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_signal_type, tvb,
AEM_OFFSET_CURRENT_SOURCE_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_signal_index, tvb,
AEM_OFFSET_CURRENT_SOURCE_ID_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_default_signal_type, tvb,
AEM_OFFSET_DEFAULT_SOURCE_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_default_signal_index, tvb,
AEM_OFFSET_DEFAULT_SOURCE_ID_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
SIGNAL_SELECTOR_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
SIGNAL_SELECTOR_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_sources, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_sources);
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_SOURCES_SIGS);
mr_offset = SIGNAL_SELECTOR_OFFSET_SOURCES;
proto_item_set_len(mr_item, mr_counter * 4);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_signal_type, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_signal_index, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
#endif
break;
case AEM_DESCRIPTOR_MIXER:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
MIXER_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
MIXER_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
MIXER_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
MIXER_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
MIXER_OFFSET_CONTROL_DOMAIN, 2, ENC_BIG_ENDIAN);
#if 0
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_value_type, tvb,
AEM_OFFSET_CONTROL_VALUE_TYPE_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN_MXR, 2 ,ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
AEM_OFFSET_CONTROL_NAME_MXR, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
AEM_OFFSET_CONTROL_NAME_STRING_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sources_offset, tvb,
AEM_OFFSET_SOURCES_OFFSET_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_sources, tvb,
AEM_OFFSET_NUMBER_OF_SOURCES_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_value_offset, tvb,
AEM_OFFSET_VALUE_OFFSET_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
MIXER_OFFSET_BLOCK_LATENCY, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
MIXER_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_sources, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_sources);
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_SOURCES_MXR);
mr_offset = MIXER_OFFSET_SOURCES;
proto_item_set_len(mr_item, mr_counter * 4);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_signal_type, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_signal_index, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
ctrl_val_type = tvb_get_ntohs(tvb, AEM_OFFSET_CONTROL_VALUE_TYPE_MXR);
num_ctrl_vals = 1;
dissect_17221_ctrl_val(tvb, aem_tree, num_ctrl_vals, ctrl_val_type,
MIXER_OFFSET_SOURCES + (tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_SOURCES_MXR) * 4));
#endif
break;
case AEM_DESCRIPTOR_MATRIX:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
MATRIX_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
MATRIX_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
MATRIX_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
MATRIX_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
MATRIX_OFFSET_CONTROL_DOMAIN, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_LOCALE:
proto_tree_add_item(aem_tree, hf_aem_locale_identifier, tvb,
LOCALE_OFFSET_LOCALE_IDENTIFIER, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_number_of_strings, tvb,
LOCALE_OFFSET_NUMBER_OF_STRINGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_strings, tvb,
LOCALE_OFFSET_BASE_STRINGS, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STRINGS:
mr_offset = STRINGS_OFFSET_STRING0;
for(i = 0; i < 7; ++i) {
proto_tree_add_item(aem_tree, hf_aem_string, tvb,
mr_offset, 64, ENC_ASCII|ENC_NA);
mr_offset += 64;
}
break;
case AEM_DESCRIPTOR_MATRIX_SIGNAL:
proto_tree_add_item(aem_tree, hf_aem_signals_count, tvb,
MATRIX_SIGNAL_OFFSET_SIGNALS_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signals_offset, tvb,
MATRIX_SIGNAL_OFFSET_SIGNALS_OFFSET, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_sources, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_sources);
mr_counter = tvb_get_ntohs(tvb, MATRIX_SIGNAL_OFFSET_SIGNALS_COUNT);
mr_offset = MATRIX_SIGNAL_OFFSET_SIGNALS_OFFSET;
proto_item_set_len(mr_item, mr_counter * 4);
for(i = 0; i < mr_counter; ++i)
{
proto_tree_add_item(mr_subtree, hf_aem_signal_type, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_signal_index, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_MEMORY_OBJECT:
proto_tree_add_item(aem_tree, hf_aem_memory_object_type, tvb,
MEMORY_OBJECT_OFFSET_MEMORY_OBJECT_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_target_descriptor_type, tvb,
MEMORY_OBJECT_OFFSET_TARGET_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_target_descriptor_id, tvb,
MEMORY_OBJECT_OFFSET_TARGET_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
MEMORY_OBJECT_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
MEMORY_OBJECT_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_start_address, tvb,
MEMORY_OBJECT_OFFSET_START_ADDRESS, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_length, tvb,
MEMORY_OBJECT_OFFSET_LENGTH, 8, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CLOCK_DOMAIN:
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
CLOCK_DOMAIN_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_localized_description, tvb,
CLOCK_DOMAIN_OFFSET_LOCALIZED_DESCRIPTION, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_index, tvb,
CLOCK_DOMAIN_OFFSET_CLOCK_SOURCE_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_sources_offset, tvb,
CLOCK_DOMAIN_OFFSET_CLOCK_SOURCES_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_sources_count, tvb,
CLOCK_DOMAIN_OFFSET_CLOCK_SOURCES_COUNT, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, CLOCK_DOMAIN_OFFSET_CLOCK_SOURCES_COUNT);
mr_offset = tvb_get_ntohs(tvb, CLOCK_DOMAIN_OFFSET_CLOCK_SOURCES_OFFSET);
mr_item = proto_tree_add_item(aem_tree, hf_aem_clock_sources_array, tvb,
mr_offset, mr_counter * 2, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_clock_sources);
for(i = 0; i < mr_counter; ++i)
{
proto_tree_add_item(mr_subtree, hf_aem_clock_sources, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
default:
proto_tree_add_item(aem_tree, hf_aem_unknown_descriptor, tvb,
4, tvb_captured_length(tvb) - 4, ENC_NA);
break;
}
}
static void
dissect_17221_aecp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aecp_tree)
{
guint16 c_type;
guint16 mess_status;
guint16 mess_type;
guint16 mr_counter;
guint32 mr_offset;
proto_item *mr_subtree;
proto_item *mr_item;
int i;
tvbuff_t *next_tvb;
proto_tree *flags_tree;
proto_item *flags_ti;
proto_tree_add_item(aecp_tree, hf_aecp_message_type, tvb,
AECP_OFFSET_VERSION, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_status_code, tvb,
AECP_OFFSET_STATUS_CODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_cd_length, tvb,
AECP_OFFSET_CD_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_target_guid, tvb,
AECP_OFFSET_TARGET_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_controller_guid, tvb,
AECP_OFFSET_CONTROLLER_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_sequence_id, tvb,
AECP_OFFSET_SEQUENCE_ID, 2, ENC_BIG_ENDIAN);
mess_type = tvb_get_ntohs(tvb, 0) & AECP_MSG_TYPE_MASK;
if ((mess_type == AECP_AEM_COMMAND_MESSAGE) || (mess_type == AECP_AEM_RESPONSE_MESSAGE))
{
proto_tree_add_item(aecp_tree, hf_aecp_u_flag, tvb,
AECP_OFFSET_U_FLAG, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_command_type, tvb,
AECP_OFFSET_COMMAND_TYPE, 2, ENC_BIG_ENDIAN);
c_type = tvb_get_ntohs(tvb, AECP_OFFSET_COMMAND_TYPE) & AECP_COMMAND_TYPE_MASK;
mess_status = tvb_get_ntohs(tvb, 2) & 0xF800;
switch(c_type) {
case AECP_COMMAND_ACQUIRE_ENTITY:
flags_ti = proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_FLAGS, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_aecp_persistent_flag, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_release_flag, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_owner_guid, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_OWNER_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_LOCK_ENTITY:
proto_tree_add_item(aecp_tree, hf_aecp_unlock_flag, tvb,
AECP_OFFSET_LOCK_ENTITY_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_locked_guid, tvb,
AECP_OFFSET_LOCK_ENTITY_LOCKED_GUID, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_READ_DESCRIPTOR:
proto_tree_add_item(aecp_tree, hf_aecp_configuration, tvb,
AECP_OFFSET_DESCRIPTOR_CONFIGURATION_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_COMMAND_MESSAGE)||(mess_status != 0))
{
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_DESCRIPTOR_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_DESCRIPTOR_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
}
else
{
next_tvb = tvb_new_subset_remaining(tvb, AECP_OFFSET_DESCRIPTOR_DESCRIPTOR);
dissect_17221_aem(next_tvb, pinfo, aecp_tree);
}
break;
case AECP_COMMAND_WRITE_DESCRIPTOR:
proto_tree_add_item(aecp_tree, hf_aecp_configuration, tvb,
AECP_OFFSET_DESCRIPTOR_CONFIGURATION_INDEX, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, AECP_OFFSET_DESCRIPTOR_DESCRIPTOR);
dissect_17221_aem(next_tvb, pinfo, aecp_tree);
break;
case AECP_COMMAND_SET_CONFIGURATION:
case AECP_COMMAND_GET_CONFIGURATION:
proto_tree_add_item(aecp_tree, hf_aecp_configuration,
tvb, AECP_OFFSET_CONFIGURATION_CONFIGURATION_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_STREAM_FORMAT:
case AECP_COMMAND_GET_STREAM_FORMAT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_STREAM_FORMAT_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_STREAM_FORMAT_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type != AECP_AEM_COMMAND_MESSAGE)||(c_type == AECP_COMMAND_SET_STREAM_FORMAT))
{
next_tvb = tvb_new_subset_length(tvb, AECP_OFFSET_STREAM_FORMAT_STREAM_FORMAT, 8);
dissect_17221_stream_format(next_tvb, aecp_tree);
}
break;
case AECP_COMMAND_SET_VIDEO_FORMAT:
case AECP_COMMAND_GET_VIDEO_FORMAT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_VIDEO_FORMAT_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_VIDEO_FORMAT_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type != AECP_AEM_COMMAND_MESSAGE)||(c_type == AECP_COMMAND_SET_VIDEO_FORMAT))
{
next_tvb = tvb_new_subset_length(tvb, AECP_OFFSET_VIDEO_FORMAT_FORMAT_SPECIFIC, 4);
dissect_17221_video_format(next_tvb, aecp_tree);
next_tvb = tvb_new_subset_length(tvb, AECP_OFFSET_VIDEO_FORMAT_ASPECT_RATIO, 2);
dissect_17221_video_aspect_ratio(next_tvb, aecp_tree);
proto_tree_add_item(aecp_tree, hf_aem_color_space, tvb,
AECP_OFFSET_VIDEO_FORMAT_COLOR_SPACE, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_length(tvb, AECP_OFFSET_VIDEO_FORMAT_FRAME_SIZE, 4);
dissect_17221_video_frame_size(next_tvb, aecp_tree);
}
break;
case AECP_COMMAND_SET_SENSOR_FORMAT:
case AECP_COMMAND_GET_SENSOR_FORMAT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_SENSOR_FORMAT_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_SENSOR_FORMAT_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type != AECP_AEM_COMMAND_MESSAGE)||(c_type == AECP_COMMAND_SET_SENSOR_FORMAT))
{
next_tvb = tvb_new_subset_length(tvb, AECP_OFFSET_SENSOR_FORMAT_SENSOR_FORMAT, 8);
dissect_17221_sensor_format(next_tvb, aecp_tree);
}
break;
case AECP_COMMAND_SET_STREAM_INFO:
case AECP_COMMAND_GET_STREAM_INFO:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_STREAM_INFO_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_STREAM_INFO_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_SET_STREAM_INFO)) {
proto_tree_add_item(aecp_tree, hf_acmp_flags_class_b, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_fast_connect, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_saved_state, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_streaming_wait, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_supports_encrypted, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_encrypted_pdu, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_talker_failed, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_vlan_id_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_connected_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_failure_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_dest_mac_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_acc_lat_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_id_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_format_valid_flag, tvb,
AECP_OFFSET_STREAM_INFO_FLAGS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_format, tvb,
AECP_OFFSET_STREAM_INFO_STREAM_FORMAT, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_stream_id, tvb,
AECP_OFFSET_STREAM_INFO_STREAM_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_accumulated_latency, tvb,
AECP_OFFSET_STREAM_INFO_MSRP_ACCUMULATED_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_stream_dest_mac, tvb,
AECP_OFFSET_STREAM_INFO_STREAM_DEST_MAC, 6, ENC_NA);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_failure_code, tvb,
AECP_OFFSET_STREAM_INFO_MSRP_FAILURE_CODE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_failure_bridge_id, tvb,
AECP_OFFSET_STREAM_INFO_MSRP_FAILURE_BRIDGE_ID, 8, ENC_NA);
}
break;
case AECP_COMMAND_SET_NAME:
case AECP_COMMAND_GET_NAME:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_NAME_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_NAME_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_name_index, tvb,
AECP_OFFSET_NAME_NAME_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_configuration_index, tvb,
AECP_OFFSET_NAME_CONFIGURATION_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_SET_NAME)) {
proto_tree_add_item(aecp_tree, hf_aecp_name, tvb,
AECP_OFFSET_NAME_NAME, 64, ENC_ASCII|ENC_NA);
}
break;
case AECP_COMMAND_SET_ASSOCIATION_ID:
case AECP_COMMAND_GET_ASSOCIATION_ID:
proto_tree_add_item(aecp_tree, hf_aecp_association_id, tvb,
AECP_OFFSET_ASSOCIATION_ID_ASSOCIATION_ID, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_SAMPLING_RATE:
case AECP_COMMAND_GET_SAMPLING_RATE:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_SAMPLING_RATE_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_SAMPLING_RATE_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_SET_SAMPLING_RATE)) {
proto_tree_add_item(aecp_tree,hf_aecp_sampling_rate_pull , tvb,
AECP_OFFSET_SAMPLING_RATE_SAMPLING_RATE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_sampling_rate_base_frequency, tvb,
AECP_OFFSET_SAMPLING_RATE_SAMPLING_RATE, 4, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_SET_CLOCK_SOURCE:
case AECP_COMMAND_GET_CLOCK_SOURCE:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_CLOCK_SOURCE_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_CLOCK_SOURCE_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_SET_CLOCK_SOURCE)) {
proto_tree_add_item(aecp_tree, hf_aem_clock_source_id, tvb,
AECP_OFFSET_CLOCK_SOURCE_CLOCK_SOURCE_INDEX, 2, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_SET_CONTROL_VALUE:
case AECP_COMMAND_GET_CONTROL_VALUE:
case AECP_COMMAND_SET_MIXER:
case AECP_COMMAND_GET_MIXER:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_CONTROL_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_CONTROL_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_INCREMENT_CONTROL:
case AECP_COMMAND_DECREMENT_CONTROL:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_INCDEC_CONTROL_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_INCDEC_CONTROL_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_SIGNAL_SELECTOR:
case AECP_COMMAND_GET_SIGNAL_SELECTOR:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_SIGNAL_SELECTOR_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_SIGNAL_SELECTOR_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_SET_SIGNAL_SELECTOR)) {
proto_tree_add_item(aecp_tree, hf_aecp_signal_type, tvb,
AECP_OFFSET_SIGNAL_SELECTOR_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_signal_index, tvb,
AECP_OFFSET_SIGNAL_SELECTOR_SIGNAL_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_signal_output, tvb,
AECP_OFFSET_SIGNAL_SELECTOR_SIGNAL_OUTPUT, 2, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_GET_MATRIX:
case AECP_COMMAND_SET_MATRIX:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_MATRIX_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_MATRIX_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_column, tvb,
AECP_OFFSET_MATRIX_MATRIX_COLUMN, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_row, tvb,
AECP_OFFSET_MATRIX_MATRIX_ROW, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_width, tvb,
AECP_OFFSET_MATRIX_REGION_WIDTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_height, tvb, AECP_OFFSET_MATRIX_REGION_HEIGHT, 2, ENC_BIG_ENDIAN); proto_tree_add_item(aecp_tree, hf_aecp_matrix_rep, tvb,
AECP_OFFSET_MATRIX_REP, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_direction, tvb,
AECP_OFFSET_MATRIX_DIRECTION, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_value_count, tvb,
AECP_OFFSET_MATRIX_VALUE_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_item_offset, tvb,
AECP_OFFSET_MATRIX_ITEM_OFFSET, 2, ENC_BIG_ENDIAN);
if ((mess_type == AECP_AEM_RESPONSE_MESSAGE) || (c_type == AECP_COMMAND_GET_MATRIX)) {
}
break;
case AECP_COMMAND_START_STREAMING:
case AECP_COMMAND_STOP_STREAMING:
case AECP_COMMAND_REBOOT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_STREAMING_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_STREAMING_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_REGISTER_UNSOL_NOTIFICATION:
case AECP_COMMAND_DEREGISTER_UNSOL_NOTIFICATION:
break;
case AECP_COMMAND_IDENTIFY_NOTIFICATION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_IDENTIFY_NOTIFICATION_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_IDENTIFY_NOTIFICATION_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_GET_AVB_INFO:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_AVB_INFO_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_AVB_INFO_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_avb_info_ptp_grandmaster_id, tvb,
AECP_OFFSET_AVB_INFO_AS_GRANDMASTER_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_info_propegation_delay, tvb,
AECP_OFFSET_AVB_INFO_PROPAGATION_DELAY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_info_gptp_domain_number, tvb,
AECP_OFFSET_AVB_INFO_AS_DOMAIN_NUMBER, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_as_capable_flag, tvb,
AECP_OFFSET_AVB_INFO_FLAGS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_gptp_enabled_flag, tvb,
AECP_OFFSET_AVB_INFO_FLAGS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_srp_enabled_flag, tvb,
AECP_OFFSET_AVB_INFO_FLAGS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_info_msrp_mappings_count, tvb,
AECP_OFFSET_AVB_INFO_MSRP_MAPPINGS_COUNT, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aecp_tree, hf_aecp_avb_info_msrp_mappings, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aecp_get_avb_info_msrp_mappings);
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AVB_INFO_MSRP_MAPPINGS_COUNT);
mr_offset = AECP_OFFSET_AVB_INFO_MSRP_MAPPINGS;
for (i = 0; i < mr_counter; i++) {
proto_tree_add_item(mr_subtree, hf_aecp_avb_info_msrp_mapping_traffic_class, tvb,
mr_offset, 1, ENC_BIG_ENDIAN);
mr_offset += 1;
proto_tree_add_item(mr_subtree, hf_aecp_avb_info_msrp_mapping_priority, tvb,
mr_offset, 1, ENC_BIG_ENDIAN);
mr_offset += 1;
proto_tree_add_item(mr_subtree, hf_aecp_get_avb_info_msrp_vlan_id, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
}
break;
case AECP_COMMAND_GET_AS_PATH:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_AS_PATH_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_as_path_count, tvb,
AECP_OFFSET_AS_PATH_COUNT, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aecp_tree, hf_aecp_as_path_sequences, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aecp_get_as_path_sequences);
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AS_PATH_COUNT);
mr_offset = AECP_OFFSET_AS_PATH_PATH_SEQUENCE;
for (i = 0; i < mr_counter; i++) {
proto_tree_add_item(mr_subtree, hf_aecp_get_as_info_clock_id, tvb,
mr_offset, 8, ENC_BIG_ENDIAN);
mr_offset += 8;
}
}
break;
case AECP_COMMAND_GET_COUNTERS:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_COUNTERS_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_COUNTERS_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
switch (tvb_get_ntohs(tvb, AECP_OFFSET_COUNTERS_DESCRIPTOR_TYPE)) {
case AEM_DESCRIPTOR_ENTITY:
break;
case AEM_DESCRIPTOR_AVB_INTERFACE:
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_link_up_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_link_down_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_packets_tx_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_packets_rx_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_rx_crc_error_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_gptp_gm_changed_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CLOCK_DOMAIN:
proto_tree_add_item(aecp_tree, hf_aecp_clock_domain_locked_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_clock_domain_unlocked_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STREAM_INPUT:
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_locked_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_unlocked_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_stream_reset_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_seq_num_mismatch_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_reset_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_uncertain_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_valid_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_not_valid_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_unsupported_format_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_late_timestamp_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_early_timestamp_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_packets_tx_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_packets_rx_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific1_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific2_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific3_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific4_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific5_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific6_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific7_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific8_valid, tvb,
AECP_OFFSET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
switch (tvb_get_ntohs(tvb, AECP_OFFSET_COUNTERS_DESCRIPTOR_TYPE)) {
case AEM_DESCRIPTOR_ENTITY:
break;
case AEM_DESCRIPTOR_AVB_INTERFACE:
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_link_up, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_LINK_UP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_link_down, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_LINK_DOWN, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_packets_tx, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_PACKETS_TX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_packets_rx, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_PACKETS_RX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_rx_crc_error, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_RX_CRC_ERROR, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_avb_interface_gptp_gm_changed, tvb,
AECP_OFFSET_COUNTERS_AVB_INTERFACE_GPTP_GM_CHANGED, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CLOCK_DOMAIN:
proto_tree_add_item(aecp_tree, hf_aecp_clock_domain_locked, tvb,
AECP_OFFSET_COUNTERS_CLOCK_DOMAIN_LOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_clock_domain_unlocked, tvb,
AECP_OFFSET_COUNTERS_CLOCK_DOMAIN_UNLOCKED, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STREAM_INPUT:
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_locked, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_MEDIA_LOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_unlocked, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_MEDIA_UNLOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_stream_reset, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_STREAM_RESET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_seq_num_mismatch, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_SEQ_NUM_MISMATCH, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_media_reset, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_MEDIA_RESET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_uncertain, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_TIMESTAMP_UNCERTAIN, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_valid, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_TIMESTAMP_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_timestamp_not_valid, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_TIMESTAMP_NOT_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_unsupported_format, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_UNSUPPORTED_FORMAT, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_late_timestamp, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_LATE_TIMESTAMP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_early_timestamp, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_EARLY_TIMESTAMP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_packets_tx, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_PACKETS_TX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_input_packets_rx, tvb,
AECP_OFFSET_COUNTERS_STREAM_INPUT_PACKETS_RX, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific1, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific2, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific3, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific4, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific5, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific6, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_6, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific7, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_7, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific8, tvb,
AECP_OFFSET_COUNTERS_ENTITY_SPECIFIC_8, 4, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_GET_AUDIO_MAP:
case AECP_COMMAND_GET_VIDEO_MAP:
case AECP_COMMAND_GET_SENSOR_MAP:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_MAP_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_MAP_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_map_index, tvb,
AECP_OFFSET_MAP_MAP_INDEX, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_number_of_maps, tvb,
AECP_OFFSET_MAP_NUMBER_OF_MAPS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_number_of_maps, tvb,
AECP_OFFSET_MAP_NUMBER_OF_MAPPINGS, 2, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_ADD_AUDIO_MAPPINGS:
case AECP_COMMAND_REMOVE_AUDIO_MAPPINGS:
case AECP_COMMAND_ADD_VIDEO_MAPPINGS:
case AECP_COMMAND_REMOVE_VIDEO_MAPPINGS:
case AECP_COMMAND_ADD_SENSOR_MAPPINGS:
case AECP_COMMAND_REMOVE_SENSOR_MAPPINGS:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_ADDREM_MAP_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_ADDREM_MAP_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_number_of_maps, tvb,
AECP_OFFSET_ADDREM_MAP_NUMBER_OF_MAPPINGS, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_START_OPERATION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_START_OPERATION_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_START_OPERATION_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_id, tvb,
AECP_OFFSET_START_OPERATION_OPERATION_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_type, tvb,
AECP_OFFSET_START_OPERATION_OPERATION_TYPE, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_ABORT_OPERATION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_ABORT_OPERATION_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_ABORT_OPERATION_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_id, tvb,
AECP_OFFSET_ABORT_OPERATION_OPERATION_ID, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_OPERATION_STATUS:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_OPERATION_STATUS_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_OPERATION_STATUS_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_id, tvb,
AECP_OFFSET_OPERATION_STATUS_OPERATION_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_percent_complete, tvb,
AECP_OFFSET_OPERATION_STATUS_PERCENT_COMPLETE, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_AUTH_ADD_KEY:
case AECP_COMMAND_AUTH_DELETE_KEY:
case AECP_COMMAND_AUTH_GET_KEY:
proto_tree_add_item(aecp_tree, hf_aecp_key_eui, tvb,
AECP_OFFSET_AUTH_KEY_KEY_EUI, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_type, tvb,
AECP_OFFSET_AUTH_KEY_KEY_TYPE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_length, tvb,
AECP_OFFSET_AUTH_KEY_KEY_LENGTH, 2, ENC_BIG_ENDIAN);
if (((mess_type == AECP_AEM_RESPONSE_MESSAGE) && (c_type == AECP_COMMAND_AUTH_GET_KEY)) ||
((mess_type == AECP_AEM_COMMAND_MESSAGE) && (c_type == AECP_COMMAND_AUTH_ADD_KEY))) {
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AUTH_KEY_KEY_LENGTH) & AECP_KEY_LENGTH_MASK;
proto_tree_add_item(aecp_tree, hf_aecp_key, tvb,
AECP_OFFSET_AUTH_KEY_KEY, mr_counter, ENC_NA);
}
break;
case AECP_COMMAND_AUTH_GET_KEY_LIST:
proto_tree_add_item(aecp_tree, hf_aecp_keychain_id_small, tvb,
AECP_OFFSET_AUTH_GET_KEY_LIST_KEYCHAIN_ID, 1, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_keychain_id_small, tvb,
AECP_OFFSET_AUTH_GET_KEY_LIST_NUMBER_OF_KEYS, 1, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_AUTH_ADD_KEY_TO_CHAIN:
case AECP_COMMAND_AUTH_DELETE_KEY_FROM_CHAIN:
proto_tree_add_item(aecp_tree, hf_aecp_keychain_id, tvb,
AECP_OFFSET_AUTH_KEYCHAIN_KEYCHAIN_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_eui, tvb,
AECP_OFFSET_AUTH_KEYCHAIN_KEY_EUI, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_AUTH_GET_KEYCHAIN_LIST:
proto_tree_add_item(aecp_tree, hf_aecp_keychain_id, tvb,
AECP_OFFSET_AUTH_GET_KEYCHAIN_LIST_KEYCHAIN_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_keychain_list_index, tvb,
AECP_OFFSET_AUTH_GET_KEYCHAIN_LIST_LIST_INDEX, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_keychain_number_of_lists, tvb,
AECP_OFFSET_AUTH_GET_KEYCHAIN_LIST_NUMBER_OF_LISTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_keychain_number_of_keys, tvb,
AECP_OFFSET_AUTH_GET_KEYCHAIN_LIST_NUMBER_OF_KEYS, 2, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_AUTH_GET_IDENTITY:
proto_tree_add_item(aecp_tree, hf_aecp_key_eui, tvb,
AECP_OFFSET_AUTH_GET_IDENTITY_KEY_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_signature, tvb,
AECP_OFFSET_AUTH_GET_IDENTITY_SIGNATURE, 28, ENC_NA);
break;
case AECP_COMMAND_AUTH_ADD_TOKEN:
if (mess_type == AECP_AEM_COMMAND_MESSAGE) {
guint32 token_length = tvb_get_ntohl(tvb, AECP_OFFSET_AUTH_TOKEN_TOKEN_LENGTH);
proto_tree_add_item(aecp_tree, hf_aecp_key_length, tvb,
AECP_OFFSET_AUTH_TOKEN_TOKEN_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_signature, tvb,
AECP_OFFSET_AUTH_TOKEN_AUTHENTICATION_TOKEN, token_length, ENC_NA);
}
break;
case AECP_COMMAND_AUTH_DELETE_TOKEN:
break;
case AECP_COMMAND_AUTHENTICATE:
case AECP_COMMAND_DEAUTHENTICATE:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_AUTHENTICATE_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_AUTHENTICATE_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_token_length, tvb,
AECP_OFFSET_AUTHENTICATE_TOKEN_LENGTH, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AUTHENTICATE_TOKEN_LENGTH)
& AECP_TOKEN_LENGTH_MASK;
proto_tree_add_item(aecp_tree, hf_aecp_auth_token, tvb,
AECP_OFFSET_AUTHENTICATE_AUTH_TOKEN, mr_counter, ENC_NA);
break;
case AECP_COMMAND_ENABLE_TRANSPORT_SECURITY:
proto_tree_add_item(aecp_tree, hf_aecp_key_eui, tvb,
AECP_OFFSET_TRANSPORT_SECURITY_KEY_EUI, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_DISABLE_TRANSPORT_SECURITY:
break;
case AECP_COMMAND_ENABLE_STREAM_ENCRYPTION:
case AECP_COMMAND_DISABLE_STREAM_ENCRYPTION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_STREAM_ENCRYPTION_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_STREAM_ENCRYPTION_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
if (c_type == AECP_COMMAND_ENABLE_STREAM_ENCRYPTION) {
proto_tree_add_item(aecp_tree, hf_aecp_key_eui, tvb,
AECP_OFFSET_STREAM_ENCRYPTION_KEY_EUI, 8, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_SET_STREAM_BACKUP:
case AECP_COMMAND_GET_STREAM_BACKUP:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_STREAM_BACKUP_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_index, tvb,
AECP_OFFSET_STREAM_BACKUP_DESCRIPTOR_INDEX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_entity_id_0, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_ENTITY_ID_0, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_unique_id_0, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_UNIQUE_ID_0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_entity_id_1, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_ENTITY_ID_1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_unique_id_1, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_UNIQUE_ID_1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_entity_id_2, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_ENTITY_ID_2, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_talker_unique_id_2, tvb,
AECP_OFFSET_STREAM_BACKUP_TALKER_UNIQUE_ID_2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backedup_talker_entity_id, tvb,
AECP_OFFSET_STREAM_BACKEDUP_TALKER_ENTITY_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backedup_talker_unique_id, tvb,
AECP_OFFSET_STREAM_BACKEDUP_TALKER_UNIQUE_ID, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_CONTROLLER_AVAILABLE:
break;
default:
break;
}
}
else if ((mess_type == AECP_ADDRESS_ACCESS_COMMAND_MESSAGE) || (mess_type == AECP_ADDRESS_ACCESS_RESPONSE_MESSAGE))
{
proto_tree_add_item(aecp_tree, hf_aecp_aa_count, tvb,
AECP_AA_OFFSET_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_aa_tlv_mode, tvb,
AECP_AA_OFFSET_TLVS_START, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_aa_tlv_length, tvb,
AECP_AA_OFFSET_TLVS_START, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_aa_tlv_address, tvb,
AECP_AA_OFFSET_TLVS_START+2, 8, ENC_BIG_ENDIAN);
}
}
static void
dissect_17221_adp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *adp_tree)
{
proto_item *ent_cap_ti;
proto_item *talk_cap_ti;
proto_item *list_cap_ti;
proto_item *cont_cap_ti;
proto_tree *ent_cap_flags_tree;
proto_tree *talk_cap_flags_tree;
proto_tree *list_cap_flags_tree;
proto_tree *cont_cap_flags_tree;
proto_tree_add_item(adp_tree, hf_adp_message_type, tvb, ADP_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_valid_time, tvb, ADP_VALID_TIME_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_cd_length, tvb, ADP_CD_LENGTH_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_entity_id, tvb, ADP_ENTITY_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_entity_model_id, tvb, ADP_ENTITY_MODEL_ID_OFFSET, 8, ENC_BIG_ENDIAN);
ent_cap_ti = proto_tree_add_item(adp_tree, hf_adp_entity_cap, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
ent_cap_flags_tree = proto_item_add_subtree(ent_cap_ti, ett_adp_ent_cap);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_efu_mode, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_address_access_supported, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_gateway_entity, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_aem_supported, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_legacy_avc, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_assoc_id_support, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_assoc_id_valid, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_vendor_unique, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_class_a_supported, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_class_b_supported, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_gptp_supported, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_talker_stream_srcs, tvb, ADP_TALKER_STREAM_SRCS_OFFSET, 2, ENC_BIG_ENDIAN);
talk_cap_ti = proto_tree_add_item(adp_tree, hf_adp_talker_cap, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
talk_cap_flags_tree = proto_item_add_subtree(talk_cap_ti, ett_adp_talk_cap);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_implement, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_other_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_control_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_media_clk_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_smpte_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_midi_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_audio_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(talk_cap_flags_tree,
hf_adp_talk_cap_video_src, tvb, ADP_TALKER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_listener_stream_sinks,
tvb, ADP_LISTENER_STREAM_SINKS_OFFSET, 2, ENC_BIG_ENDIAN);
list_cap_ti = proto_tree_add_item(adp_tree, hf_adp_listener_cap, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
list_cap_flags_tree = proto_item_add_subtree(list_cap_ti, ett_adp_list_cap);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_implement, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_other_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_control_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_media_clk_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_smpte_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_midi_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_audio_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(list_cap_flags_tree,
hf_adp_list_cap_video_sink, tvb, ADP_LISTENER_CAP_OFFSET, 2, ENC_BIG_ENDIAN);
cont_cap_ti = proto_tree_add_item(adp_tree, hf_adp_controller_cap, tvb, ADP_CONTROLLER_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
cont_cap_flags_tree = proto_item_add_subtree(cont_cap_ti, ett_adp_cont_cap);
proto_tree_add_item(cont_cap_flags_tree,
hf_adp_cont_cap_implement, tvb, ADP_CONTROLLER_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cont_cap_flags_tree,
hf_adp_cont_cap_layer3_proxy, tvb, ADP_CONTROLLER_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_avail_index, tvb, ADP_AVAIL_INDEX_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_gptp_gm_id, tvb, ADP_AS_GM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_assoc_id, tvb, ADP_ASSOC_ID_OFFSET, 8, ENC_BIG_ENDIAN);
}
static void
dissect_17221_acmp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *acmp_tree)
{
proto_item *flags_ti;
proto_tree *flags_tree;
proto_tree_add_item(acmp_tree, hf_acmp_message_type, tvb, ACMP_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_status_field, tvb, ACMP_STATUS_FIELD_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_cd_length, tvb, ACMP_CD_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_stream_id, tvb, ACMP_STREAM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_controller_guid, tvb, ACMP_CONTROLLER_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_talker_guid, tvb, ACMP_TALKER_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_listener_guid, tvb, ACMP_LISTENER_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_talker_unique_id, tvb, ACMP_TALKER_UNIQUE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_listener_unique_id, tvb, ACMP_LISTENER_UNIQUE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_stream_dest_mac, tvb, ACMP_DEST_MAC_OFFSET, 6, ENC_NA);
proto_tree_add_item(acmp_tree, hf_acmp_connection_count, tvb, ACMP_CONNECTION_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_sequence_id, tvb, ACMP_SEQUENCE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(acmp_tree, hf_acmp_flags, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_acmp_flags_class_b, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_fast_connect, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_saved_state, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_streaming_wait, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_supports_encrypted, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_encrypted_pdu, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_talker_failed, tvb, ACMP_FLAGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(acmp_tree, hf_acmp_vlan_id, tvb, ACMP_VLAN_ID_OFFSET, 2, ENC_BIG_ENDIAN);
}
static int
dissect_17221(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 subtype = 0;
proto_item *ieee17221_item;
proto_tree *ieee17221_tree;
subtype = tvb_get_guint8(tvb, 0);
subtype &= 0x7F;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE1722-1");
ieee17221_item = proto_tree_add_item(tree, proto_17221, tvb, 0, -1, ENC_NA);
ieee17221_tree = proto_item_add_subtree(ieee17221_item, ett_17221);
switch (subtype)
{
case 0x7A:
{
col_set_str(pinfo->cinfo, COL_INFO, "AVDECC Discovery Protocol");
if (tree)
dissect_17221_adp(tvb, pinfo, ieee17221_tree);
break;
}
case 0x7B:
{
col_set_str(pinfo->cinfo, COL_INFO, "AVDECC Enumeration and Control Protocol");
if (tree)
dissect_17221_aecp(tvb, pinfo, ieee17221_tree);
break;
}
case 0x7C:
{
col_set_str(pinfo->cinfo, COL_INFO, "AVDECC Connection Management Protocol");
if (tree)
dissect_17221_acmp(tvb, pinfo, ieee17221_tree);
break;
}
default:
{
col_set_str(pinfo->cinfo, COL_INFO, "1722.1 Unknown");
return 0;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_17221(void)
{
static hf_register_info hf[] = {
{ &hf_adp_message_type,
{ "Message Type", "ieee17221.message_type",
FT_UINT8, BASE_DEC, VALS(adp_message_type_vals), ADP_MSG_TYPE_MASK, NULL, HFILL }
},
{ &hf_adp_valid_time,
{ "Valid Time", "ieee17221.valid_time",
FT_UINT8, BASE_DEC, NULL, ADP_VALID_TIME_MASK, NULL, HFILL }
},
{ &hf_adp_cd_length,
{ "Control Data Length", "ieee17221.control_data_length",
FT_UINT16, BASE_DEC, NULL, ADP_CD_LENGTH_MASK, NULL, HFILL }
},
{ &hf_adp_entity_id,
{ "Entity ID", "ieee17221.entity_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_model_id,
{ "Entity Model ID", "ieee17221.entity_model_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_cap,
{ "Entity Capabilities", "ieee17221.entity_capabilities",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_cap_efu_mode,
{ "EFU_MODE", "ieee17221.entity_capabilities.efu_mode",
FT_BOOLEAN, 32, NULL, ADP_EFU_MODE_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_address_access_supported,
{ "ADDRESS_ACCESS", "ieee17221.entity_capabilities.address_access",
FT_BOOLEAN, 32, NULL, ADP_ADDRESS_ACCESS_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_gateway_entity,
{ "GATEWAY_ENTITY", "ieee17221.entity_capabilities.gateway_entity",
FT_BOOLEAN, 32, NULL, ADP_GATEWAY_ENTITY_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_aem_supported,
{ "AEM", "ieee17221.entity_capabilities.aem_supported",
FT_BOOLEAN, 32, NULL, ADP_AEM_SUPPORTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_legacy_avc,
{ "LEGACY_AVC", "ieee17221.entity_capabilities.legacy_avc",
FT_BOOLEAN, 32, NULL, ADP_LEGACY_AVC_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_assoc_id_support,
{ "ASSOCIATION_ID_SUPPORTED", "ieee17221.entity_capabilities.association_id_supported",
FT_BOOLEAN, 32, NULL, ADP_ASSOC_ID_SUPPORT_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_assoc_id_valid,
{ "ASSOCIATION_ID_VALID", "ieee17221.entity_capabilities.association_id_valid",
FT_BOOLEAN, 32, NULL, ADP_ASSOC_ID_VALID_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_vendor_unique,
{ "VENDOR_UNIQUE", "ieee17221.entity_capabilities.vendor_unique",
FT_BOOLEAN, 32, NULL, ADP_VENDOR_UNIQUE_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_class_a_supported,
{ "CLASS_A", "ieee17221.entity_capabilities.class_a",
FT_BOOLEAN, 32, NULL, ADP_CLASS_A_SUPPORTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_class_b_supported,
{ "CLASS_B", "ieee17221.entity_capabilities.class_b",
FT_BOOLEAN, 32, NULL, ADP_CLASS_B_SUPPORTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_gptp_supported,
{ "gPTP Supported", "ieee17221.entity_capabilities.gptp_supported",
FT_BOOLEAN, 32, NULL, ADP_AS_SUPPORTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_talker_stream_srcs,
{ "Talker Stream Sources", "ieee17221.talker_stream_sources",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_talker_cap,
{ "Talker Capabilities", "ieee17221.talker_capabilities",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_talk_cap_implement,
{ "IMPLEMENTED", "ieee17221.talker_capabilities.implemented",
FT_BOOLEAN, 16, NULL, ADP_TALK_IMPLEMENTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_other_src,
{ "OTHER_SOURCE", "ieee17221.talker_capabilities.other_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_OTHER_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_control_src,
{ "CONTROL_SOURCE", "ieee17221.talker_capabilities.control_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_CONTROL_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_media_clk_src,
{ "MEDIA_CLOCK_SOURCE", "ieee17221.talker_capabilities.media_clock_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_MEDIA_CLK_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_smpte_src,
{ "SMPTE_SOURCE", "ieee17221.talker_capabilities.smpte_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_SMPTE_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_midi_src,
{ "MIDI_SOURCE", "ieee17221.talker_capabilities.midi_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_MIDI_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_audio_src,
{ "AUDIO_SOURCE", "ieee17221.talker_capabilities.audio_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_AUDIO_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_talk_cap_video_src,
{ "VIDEO_SOURCE", "ieee17221.talker_capabilities.video_source",
FT_BOOLEAN, 16, NULL, ADP_TALK_VIDEO_SRC_BITMASK, NULL, HFILL }
},
{ &hf_adp_listener_stream_sinks,
{ "Listener Stream Sinks", "ieee17221.listener_stream_sinks",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_listener_cap,
{ "Listener Capabilities", "ieee17221.listener_capabilities",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_list_cap_implement,
{ "IMPLEMENTED", "ieee17221.listener_capabilities.implemented",
FT_BOOLEAN, 16, NULL, ADP_LIST_IMPLEMENTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_other_sink,
{ "OTHER_SINK", "ieee17221.listener_capabilities.other_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_OTHER_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_control_sink,
{ "CONTROL_SINK", "ieee17221.listener_capabilities.control_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_CONTROL_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_media_clk_sink,
{ "MEDIA_CLOCK_SINK", "ieee17221.listener_capabilities.media_clock_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_MEDIA_CLK_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_smpte_sink,
{ "SMPTE_SINK", "ieee17221.listener_capabilities.smpte_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_SMPTE_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_midi_sink,
{ "MIDI_SINK", "ieee17221.listener_capabilities.midi_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_MIDI_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_audio_sink,
{ "AUDIO_SINK", "ieee17221.listener_capabilities.audio_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_AUDIO_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_list_cap_video_sink,
{ "VIDEO_SINK", "ieee17221.listener_capabilities.video_source",
FT_BOOLEAN, 16, NULL, ADP_LIST_VIDEO_SINK_BITMASK, NULL, HFILL }
},
{ &hf_adp_controller_cap,
{ "Controller Capabilities", "ieee17221.controller_capabilities",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_cont_cap_implement,
{ "IMPLEMENTED", "ieee17221.controller_capabilities.implemented",
FT_BOOLEAN, 16, NULL, ADP_CONT_IMPLEMENTED_BITMASK, NULL, HFILL }
},
{ &hf_adp_cont_cap_layer3_proxy,
{ "LAYER3_PROXY", "ieee17221.controller_capabilities.layer3_proxy",
FT_BOOLEAN, 16, NULL, ADP_CONT_LAYER3_PROXY_BITMASK, NULL, HFILL }
},
{ &hf_adp_avail_index,
{ "Available Index", "ieee17221.available_index",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_gptp_gm_id,
{ "gPTP Grandmaster ID", "ieee17221.gptp_grandmaster_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_adp_def_aud_format,
{ "Default Audio Format", "ieee17221.default_audio_format",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
#if 0
{ &hf_adp_def_aud_sample_rates,
{ "Sample Rates", "ieee17221.default_audio_format.sample_rates",
FT_UINT8, BASE_HEX, NULL, ADP_DEF_AUDIO_SAMPLE_RATES_MASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_44k1,
{ "44.1kHz", "ieee17221.default_audio_format.sample_rates.44k1",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_44K1_BITMASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_48k,
{ "48kHz", "ieee17221.default_audio_format.sample_rates.48k",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_48K_BITMASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_88k2,
{ "88.2kHz", "ieee17221.default_audio_format.sample_rates.88k2",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_88K2_BITMASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_96k,
{ "96kHz", "ieee17221.default_audio_format.sample_rates.96k",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_96K_BITMASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_176k4,
{ "176.4kHz", "ieee17221.default_audio_format.sample_rates.176k4",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_176K4_BITMASK, NULL, HFILL }
},
{ &hf_adp_samp_rate_192k,
{ "192kHz", "ieee17221.default_audio_format.sample_rates.192k",
FT_BOOLEAN, 8, NULL, ADP_SAMP_RATE_192K_BITMASK, NULL, HFILL }
},
{ &hf_adp_def_aud_max_chan,
{ "Max Channels", "ieee17221.default_audio_format.max_channels",
FT_UINT16, BASE_DEC, NULL, ADP_DEF_AUDIO_MAX_CHANS_MASK, NULL, HFILL }
},
{ &hf_adp_def_aud_saf_flag,
{ "saf", "ieee17221.default_audio_format.saf",
FT_BOOLEAN, 16, NULL, ADP_DEF_AUDIO_SAF_MASK, NULL, HFILL }
},
{ &hf_adp_def_aud_float_flag,
{ "float", "ieee17221.default_audio_format.float",
FT_BOOLEAN, 16, NULL, ADP_DEF_AUDIO_FLOAT_MASK, NULL, HFILL }
},
{ &hf_adp_def_aud_chan_formats,
{ "Channel Formats", "ieee17221.default_audio_format.channel_formats",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_chan_format_mono,
{ "MONO", "ieee17221.default_audio_format.channel_formats.mono",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_MONO, NULL, HFILL }
},
{ &hf_adp_chan_format_2ch,
{ "2_CH", "ieee17221.default_audio_format.channel_formats.2_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_2CH, NULL, HFILL }
},
{ &hf_adp_chan_format_3ch,
{ "3_CH", "ieee17221.default_audio_format.channel_formats.3_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_3CH, NULL, HFILL }
},
{ &hf_adp_chan_format_4ch,
{ "4_CH", "ieee17221.default_audio_format.channel_formats.4_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_4CH, NULL, HFILL }
},
{ &hf_adp_chan_format_5ch,
{ "5_CH", "ieee17221.default_audio_format.channel_formats.5_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_5CH, NULL, HFILL }
},
{ &hf_adp_chan_format_6ch,
{ "6_CH", "ieee17221.default_audio_format.channel_formats.6_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_6CH, NULL, HFILL }
},
{ &hf_adp_chan_format_7ch,
{ "7_CH", "ieee17221.default_audio_format.channel_formats.7_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_7CH, NULL, HFILL }
},
{ &hf_adp_chan_format_8ch,
{ "8_CH", "ieee17221.default_audio_format.channel_formats.8_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_8CH, NULL, HFILL }
},
{ &hf_adp_chan_format_10ch,
{ "10_CH", "ieee17221.default_audio_format.channel_formats.10_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_10CH, NULL, HFILL }
},
{ &hf_adp_chan_format_12ch,
{ "12_CH", "ieee17221.default_audio_format.channel_formats.12_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_12CH, NULL, HFILL }
},
{ &hf_adp_chan_format_14ch,
{ "14_CH", "ieee17221.default_audio_format.channel_formats.14_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_14CH, NULL, HFILL }
},
{ &hf_adp_chan_format_16ch,
{ "16_CH", "ieee17221.default_audio_format.channel_formats.16_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_16CH, NULL, HFILL }
},
{ &hf_adp_chan_format_18ch,
{ "18_CH", "ieee17221.default_audio_format.channel_formats.18_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_18CH, NULL, HFILL }
},
{ &hf_adp_chan_format_20ch,
{ "20_CH", "ieee17221.default_audio_format.channel_formats.20_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_20CH, NULL, HFILL }
},
{ &hf_adp_chan_format_22ch,
{ "22_CH", "ieee17221.default_audio_format.channel_formats.22_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_22CH, NULL, HFILL }
},
{ &hf_adp_chan_format_24ch,
{ "24_CH", "ieee17221.default_audio_format.channel_formats.24_ch",
FT_BOOLEAN, 16, NULL, ADP_CHAN_FORMAT_24CH, NULL, HFILL }
},
#endif
#if 0
{ &hf_adp_def_vid_format,
{ "Default Video Format", "ieee17221.default_video_format",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_adp_assoc_id,
{ "Association ID", "ieee17221.association_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_adp_entity_type,
{ "Entity Type", "ieee17221.entity_type",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_acmp_message_type,
{ "Message Type", "ieee17221.message_type",
FT_UINT8, BASE_DEC, VALS(acmp_message_type_vals), ACMP_MSG_TYPE_MASK, NULL, HFILL }
},
{ &hf_acmp_status_field,
{ "Status Field", "ieee17221.status_field",
FT_UINT8, BASE_DEC, VALS(acmp_status_field_vals), ACMP_STATUS_FIELD_MASK, NULL, HFILL }
},
{ &hf_acmp_cd_length,
{ "Control Data Length", "ieee17221.control_data_length",
FT_UINT16, BASE_DEC, NULL, ACMP_CD_LENGTH_MASK, NULL, HFILL }
},
{ &hf_acmp_stream_id,
{ "Stream ID", "ieee17221.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_controller_guid,
{ "Controller GUID", "ieee17221.controller_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_talker_guid,
{ "Talker GUID", "ieee17221.talker_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_listener_guid,
{ "Listener GUID", "ieee17221.listener_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_talker_unique_id,
{ "Talker Unique ID", "ieee17221.talker_unique_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_listener_unique_id,
{ "Listener Unique ID", "ieee17221.listener_unique_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_stream_dest_mac,
{ "Destination MAC address", "ieee17221.dest_mac",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_connection_count,
{ "Connection Count", "ieee17221.connection_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_sequence_id,
{ "Sequence ID", "ieee17221.sequence_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_flags,
{ "Flags", "ieee17221.flags",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_acmp_flags_class_b,
{ "CLASS_B", "ieee17221.flags.class_b",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_CLASS_B_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_fast_connect,
{ "FAST_CONNECT", "ieee17221.flags.fast_connect",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_FAST_CONNECT_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_saved_state,
{ "SAVED_STATE", "ieee17221.flags.saved_state",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_SAVED_STATE_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_streaming_wait,
{ "STREAMING_WAIT", "ieee17221.flags.streaming_wait",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_STREAMING_WAIT_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_supports_encrypted,
{ "SUPPORTS_ENCRYPTED", "ieee17221.flags.supports_encrypted",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_SUPPORTS_ENCRYPTED_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_encrypted_pdu,
{ "ENCRYPTED_PDU", "ieee17221.flags.encrypted_pdu",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_ENCRYPTED_PDU_BITMASK, NULL, HFILL }
},
{ &hf_acmp_flags_talker_failed,
{ "TALKER_FAILED", "ieee17221.flags.talker_failed",
FT_BOOLEAN, 16, NULL, ACMP_FLAG_TALKER_FAILED_BITMASK, NULL, HFILL }
},
{ &hf_acmp_vlan_id,
{ "Stream VLAN Id", "ieee17221.vlan_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_message_type,
{ "Message Type", "ieee17221.message_type",
FT_UINT8, BASE_DEC, VALS(aecp_message_type_vals), AECP_MSG_TYPE_MASK, NULL, HFILL }
},
{ &hf_aecp_cd_length,
{ "Control Data Length", "ieee17221.control_data_length",
FT_UINT16, BASE_DEC, NULL, AECP_CD_LENGTH_MASK, NULL, HFILL }
},
{ &hf_aecp_target_guid,
{ "Target GUID", "ieee17221.target_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_controller_guid,
{ "Controller GUID", "ieee17221.controller_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_sequence_id,
{ "Sequence ID", "ieee17221.sequence_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_u_flag,
{ "U Flag", "ieee17221.u_flag",
FT_BOOLEAN, 8, NULL, AECP_U_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_command_type,
{ "Command Type", "ieee17221.command_type",
FT_UINT16, BASE_HEX, VALS(aecp_command_type_vals), AECP_COMMAND_TYPE_MASK, NULL, HFILL }
},
{ &hf_aecp_aa_count,
{ "Count", "ieee17221.count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_aa_tlv_mode,
{ "Tlv Mode", "ieee17221.tlv_mode",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_aecp_aa_tlv_length,
{ "Tlv Length", "ieee17221.tlv_length",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }
},
{ &hf_aecp_aa_tlv_address,
{ "Tlv Address", "ieee17221.tlv_address",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_aecp_descriptor_type,
{ "Descriptor Type", "ieee17221.descriptor_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aecp_descriptor_index,
{"Descriptor Index", "ieee17221.descriptor_index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_unlock_flag,
{ "UNLOCK Flag", "ieee17221.flags.unlock",
FT_BOOLEAN, 8, NULL, AECP_UNLOCK_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_locked_guid,
{ "Locked GUID", "ieee17221.locked_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_configuration,
{ "Configuration", "ieee17221.configuration",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_persistent_flag,
{ "Persistent Flag", "ieee17221.flags.persistent",
FT_BOOLEAN, 32, NULL, AECP_PERSISTENT_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_release_flag,
{ "Release Flag", "ieee17221.flags.release",
FT_BOOLEAN, 32, NULL, AECP_RELEASE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_owner_guid,
{ "Owner GUID", "ieee17221.owner_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_clock_source_id,
{ "Clock Source ID", "ieee17221.clock_source_id64",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_format,
{"Stream Format", "ieee17221.stream_format64",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_signal_type,
{"Signal Type", "ieee17221.signal_type",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_signal_index,
{"Signal Index", "ieee17221.signal_index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_signal_output,
{"Signal Output", "ieee17221.signal_output",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_matrix_column,
{"Matrix Column", "ieee17221.matrix_column",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_matrix_row,
{"Matrix Row", "ieee17221.matrix_row",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_matrix_region_width,
{"Region Width", "ieee17221.matrix_region_width",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_matrix_region_height,
{"Region Height", "ieee17221.matrix_region_height",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_matrix_rep,
{"Rep", "ieee17221.matrix_rep",
FT_BOOLEAN, 8, NULL, AECP_MATRIX_REP_MASK, NULL, HFILL }
},
{ &hf_aecp_matrix_direction,
{"Direction", "ieee17221.matrix_direction",
FT_UINT8, BASE_DEC, VALS(aecp_direction_type_vals), AECP_MATRIX_DIRECTION_MASK, NULL, HFILL }
},
{ &hf_aecp_matrix_value_count,
{"Value Count", "ieee17221.matrix_value_count",
FT_UINT16, BASE_DEC, NULL, AECP_MATRIX_VALUE_COUNT_MASK, NULL, HFILL }
},
{ &hf_aecp_matrix_item_offset,
{"Item Offset", "ieee17221.matrix_item_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_matrix_affected_item_count,
{"Affected Item Count", "ieee17221.matrix_affected_item_count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_avb_info_ptp_grandmaster_id,
{"gPTP Grandmaster ID", "ieee17221.avb_info_gptp_grandmaster_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_info_propegation_delay,
{"Propagation Delay", "ieee17221.avb_info_propagation_delay",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_info_gptp_domain_number,
{"gPTP Domain Number", "ieee17221.avb_info_gptp_domain_number",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_avb_info_flags,
{"Flags", "ieee17221.avbinfo_flags",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_as_capable_flag,
{ "AS Capable Flag", "ieee17221.as_capable_flag",
FT_BOOLEAN, 8, NULL, AECP_AS_CAPABLE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_gptp_enabled_flag,
{ "gPTP Enabled Flag", "ieee17221.gptp_enabled_flag",
FT_BOOLEAN, 8, NULL, AECP_GPTP_ENABLED_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_srp_enabled_flag,
{ "SRP Enabled Flag", "ieee17221.srp_enabled_flag",
FT_BOOLEAN, 8, NULL, AECP_SRP_ENABLED_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_avb_info_msrp_mappings_count,
{"MSRP Mappings Count", "ieee17221.msrp_mappings_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_info_msrp_mappings,
{"MSRP Mappings", "ieee17221.msrp_mappings",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_info_msrp_mapping_traffic_class,
{"MSRP Mapping Traffic Class", "ieee17221.msrp_mapping_traffic_class",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_info_msrp_mapping_priority,
{"MSRP Mapping Priority", "ieee17221.msrp_mapping_priority",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_get_avb_info_msrp_vlan_id,
{"MSRP VLAN ID", "ieee17221.msrp_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_map_index,
{"Map Index", "ieee17221.map_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_number_of_maps,
{"Number of Maps", "ieee17221.number_of_maps",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_msrp_accumulated_latency,
{"MSRP Accumulated Latency", "ieee17221.msrp_accumulated_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_msrp_failure_code,
{"MSRP Failure Code", "ieee17221.msrp_failure_code",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_msrp_failure_bridge_id,
{"MSRP Failure Bridge ID", "ieee17221.msrp_failure_bridge_id",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_stream_vlan_id,
{"Stream VLAN ID", "ieee17221.stream_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_stream_vlan_id_valid_flag,
{"Stream VLAN ID Valid Flag", "ieee17221.flags.stream_vlan_id_valid",
FT_BOOLEAN, 32, NULL, AECP_STREAM_VLAN_ID_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_connected_flag,
{"Connected Flag", "ieee17221.flags.connected",
FT_BOOLEAN, 32, NULL, AECP_CONNECTED_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_msrp_failure_valid_flag,
{"MSRP Failure Valid Flag", "ieee17221.flags.msrp_failure_valid",
FT_BOOLEAN, 32, NULL, AECP_MSRP_FAILURE_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_dest_mac_valid_flag,
{"Dest MAC Valid Flag", "ieee17221.flags.dest_mac_valid",
FT_BOOLEAN, 32, NULL, AECP_DEST_MAC_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_msrp_acc_lat_valid_flag,
{"MSRP Accumulated Latency Field Valid Flag", "ieee17221.flags.msrp_acc_lat_valid",
FT_BOOLEAN, 32, NULL, AECP_MSRP_ACC_LAT_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_stream_id_valid_flag,
{"Stream ID Valid Flag", "ieee17221.flags.stream_id_valid",
FT_BOOLEAN, 32, NULL, AECP_STREAM_ID_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_stream_format_valid_flag,
{"Stream Format Valid Flag", "ieee17221.flags.stream_format_valid",
FT_BOOLEAN, 32, NULL, AECP_STREAM_FORMAT_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_name_index,
{"Name Index", "ieee17221.name_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_configuration_index,
{"Configuration Index", "ieee17221.configuration_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_name,
{"Name", "ieee17221.name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_association_id,
{"Association ID", "ieee17221.association_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_as_path_count,
{"Count", "ieee17221.as_path_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_as_path_sequences,
{"Path Sequence", "ieee17221.as_path_sequences",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_get_as_info_clock_id,
{ "ClockId", "ieee17221.get_as_info_clock_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_keychain_id,
{"Keychain ID", "ieee17221.keychain_id",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_keychain_id_small,
{"Keychain ID", "ieee17221.keychain_id_small",
FT_UINT8, BASE_HEX, VALS(aecp_keychain_id_type_vals), AECP_KEYCHAIN_ID_MASK, NULL, HFILL }
},
{ &hf_aecp_key_type,
{"Key Type", "ieee17221.key_type",
FT_UINT8, BASE_HEX, VALS(aecp_key_type_type_vals), AECP_KEYTYPE_MASK, NULL, HFILL }
},
{ &hf_aecp_key_signature,
{"Key Signature", "ieee17221.key_signature",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_key_number,
{"Key ID", "ieee17221.key_id",
FT_UINT16, BASE_HEX, NULL, AECP_KEY_NUMBER_MASK, NULL, HFILL }
},
{ &hf_aecp_continued_flag,
{"Continued", "ieee17221.continued",
FT_BOOLEAN, 8, NULL, AECP_CONTINUED_MASK, NULL, HFILL }
},
{ &hf_aecp_key_part,
{"Key Part", "ieee17221.key_part",
FT_UINT8, BASE_DEC, NULL, AECP_KEY_PART_MASK, NULL, HFILL }
},
#endif
{ &hf_aecp_key_length,
{"Key Length", "ieee17221.key_length",
FT_UINT16, BASE_DEC, NULL, AECP_KEY_LENGTH_MASK, NULL, HFILL }
},
#if 0
{ &hf_aecp_private_key_read_flag,
{"Private Key Read Flag", "ieee17221.flags.private_key_read",
FT_BOOLEAN, 32, NULL, AECP_PRIVATE_KEY_READ_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_private_key_write_flag,
{"Private Key Write Flag", "ieee17221.flags.private_key_write",
FT_BOOLEAN, 32, NULL, AECP_PRIVATE_KEY_WRITE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_public_key_write_flag,
{"Public Key Write Flag", "ieee17221.flags.public_key_write",
FT_BOOLEAN, 32, NULL, AECP_PUBLIC_KEY_WRITE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_control_admin_flag,
{"Control Admin Flag", "ieee17221.flags.control_admin",
FT_BOOLEAN, 32, NULL, AECP_CONTROL_ADMIN_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_mem_obj_admin_flag,
{"Memory Object Admin", "ieee17221.mem_obj_admin",
FT_BOOLEAN, 32, NULL, AECP_MEM_OBJ_ADMIN_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_mem_obj_settings_flag,
{"Memory Object Settings", "ieee17221.mem_obj_settings",
FT_BOOLEAN, 32, NULL, AECP_MEM_OBJ_SETTINGS_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_control_user_l1,
{"Control User L1 flag", "ieee17221.flags.control_user_l1",
FT_BOOLEAN, 32, NULL, AECP_CONTROL_USER_L1_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_control_user_l2,
{"Control User L2 flag", "ieee17221.flags.control_user_l2",
FT_BOOLEAN, 32, NULL, AECP_CONTROL_USER_L2_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_control_user_l3,
{"Control User L3 flag", "ieee17221.flags.control_user_l3",
FT_BOOLEAN, 32, NULL, AECP_CONTROL_USER_L3_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_control_user_l4,
{"Control User L4 flag", "ieee17221.flags.control_user_l4",
FT_BOOLEAN, 32, NULL, AECP_CONTROL_USER_L4_FLAG_MASK, NULL, HFILL }
},
#endif
{ &hf_aecp_keychain_list_index,
{"Keychain List Index", "ieee17221.keychain_list_index",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_keychain_number_of_keys,
{"Keychain Number of Keys", "ieee17221.keychain_number_of_keys",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_keychain_number_of_lists,
{"Keychain Number of Lists", "ieee17221.keychain_number_of_lists",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_key_eui,
{"Key EUI", "ieee17221.key_eui",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_token_length,
{"Token Length", "ieee17221.token_length",
FT_UINT16, BASE_DEC, NULL, AECP_TOKEN_LENGTH_MASK, NULL, HFILL }
},
{ &hf_aecp_key,
{"Key", "ieee17221.key",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_auth_token,
{"Auth Token", "ieee17221.auth_token",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_flags_32,
{"Flags", "ieee17221.flags",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_link_up_valid,
{"Link Up Valid", "ieee17221.flags.link_up_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_LINK_UP, NULL, HFILL }
},
{ &hf_aecp_avb_interface_link_down_valid,
{"Link Down Valid", "ieee17221.flags.link_up_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_LINK_DOWN, NULL, HFILL }
},
{ &hf_aecp_avb_interface_packets_tx_valid,
{"Packets TX Valid", "ieee17221.flags.packets_tx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_PACKETS_TX, NULL, HFILL }
},
{ &hf_aecp_avb_interface_packets_rx_valid,
{"Packets RX Valid", "ieee17221.flags.packets_rx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_PACKETS_RX, NULL, HFILL }
},
{ &hf_aecp_avb_interface_rx_crc_error_valid,
{"RX CRC Error Valid", "ieee17221.flags.rx_crc_error_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_RX_CRC_ERROR, NULL, HFILL }
},
{ &hf_aecp_avb_interface_gptp_gm_changed_valid,
{"GPTP GM Changed Valid", "ieee17221.flags.gptp_gm_changed_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_GPTP_GM_CHANGED, NULL, HFILL }
},
{ &hf_aecp_clock_domain_unlocked_valid,
{"Clock Domain Unlocked Valid", "ieee17221.flags.clock_domain_unlocked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_CLOCK_DOMAIN_UNLOCKED, NULL, HFILL }
},
{ &hf_aecp_clock_domain_locked_valid,
{"Clock_Domain Locked Valid", "ieee17221.flags.clock_domain_locked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_CLOCK_DOMAIN_LOCKED, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_unlocked_valid,
{"Media Unlocked Valid", "ieee17221.flags.media_unlocked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_UNLOCKED, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_locked_valid,
{"Media Locked Valid", "ieee17221.flags.media_locked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_LOCKED, NULL, HFILL }
},
{ &hf_aecp_stream_input_stream_reset_valid,
{"Stream Reset Valid", "ieee17221.flags.stream_reset_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_STREAM_RESET, NULL, HFILL }
},
{ &hf_aecp_stream_input_seq_num_mismatch_valid,
{"Seq Num Mismatch Valid", "ieee17221.flags.seq_num_mismatch_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_SEQ_NUM_MISMATCH, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_reset_valid,
{"Media Reset Valid", "ieee17221.flags.media_reset_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_RESET, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_uncertain_valid,
{"Timestamp Uncertain Valid", "ieee17221.flags.timestamp_uncertain_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TIMESTAMP_UNCERTAIN, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_valid_valid,
{"Timestamp Valid Valid", "ieee17221.flags.timestamp_valid_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TIMESTAMP_VALID, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_not_valid_valid,
{"Timestamp Not Valid Valid", "ieee17221.flags.timestamp_not_valid_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TIMESTAMP_NOT_VALID, NULL, HFILL }
},
{ &hf_aecp_stream_input_unsupported_format_valid,
{"Unsupported Format Valid", "ieee17221.flags.unsupported_format_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_UNSUPPORTED_FORMAT, NULL, HFILL }
},
{ &hf_aecp_stream_input_late_timestamp_valid,
{"Late Timestamp Valid", "ieee17221.flags.late_timestamp_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_LATE_TIMESTAMP, NULL, HFILL }
},
{ &hf_aecp_stream_input_early_timestamp_valid,
{"Early Timestamp Valid", "ieee17221.flags.early_timestamp_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_EARLY_TIMESTAMP, NULL, HFILL }
},
{ &hf_aecp_stream_input_packets_tx_valid,
{"Stream Packets TX Valid", "ieee17221.flags.stream_packets_tx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_STREAM_PACKETS_TX, NULL, HFILL }
},
{ &hf_aecp_stream_input_packets_rx_valid,
{"Stream Packets RX Valid", "ieee17221.flags.stream_packets_rx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_STREAM_PACKETS_RX, NULL, HFILL }
},
{ &hf_aecp_entity_specific1_valid,
{"Entity Specific 1", "ieee17221.flags.entity_specific1_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_1, NULL, HFILL }
},
{ &hf_aecp_entity_specific2_valid,
{"Entity Specific 2", "ieee17221.flags.entity_specific2_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_2, NULL, HFILL }
},
{ &hf_aecp_entity_specific3_valid,
{"Entity Specific 3", "ieee17221.flags.entity_specific3_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_3, NULL, HFILL }
},
{ &hf_aecp_entity_specific4_valid,
{"Entity Specific 4", "ieee17221.flags.entity_specific4_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_4, NULL, HFILL }
},
{ &hf_aecp_entity_specific5_valid,
{"Entity Specific 5", "ieee17221.flags.entity_specific5_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_5, NULL, HFILL }
},
{ &hf_aecp_entity_specific6_valid,
{"Entity Specific 6", "ieee17221.flags.entity_specific6_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_6, NULL, HFILL }
},
{ &hf_aecp_entity_specific7_valid,
{"Entity Specific 7", "ieee17221.flags.entity_specific7_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_7, NULL, HFILL }
},
{ &hf_aecp_entity_specific8_valid,
{"Entity Specific 8", "ieee17221.flags.entity_specific8_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_ENTITY_SPECIFIC_8, NULL, HFILL }
},
{ &hf_aecp_avb_interface_link_up,
{"Link Up", "ieee17221.link_up",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_link_down,
{"Link Down", "ieee17221.link_down",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_packets_tx,
{"Frames TX", "ieee17221.frames_tx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_packets_rx,
{"Frames RX", "ieee17221.frames_rx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_rx_crc_error,
{"RX CRC Error", "ieee17221.rx_crc_error",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_avb_interface_gptp_gm_changed,
{"GPTP GM Changed", "ieee17221.gptp_gm_changed",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_clock_domain_unlocked,
{"Clock Domain Unlocked", "ieee17221.clock_domain_unlocked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_clock_domain_locked,
{"Clock_Domain Locked", "ieee17221.clock_domain_locked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_unlocked,
{"Media Unlocked", "ieee17221.media_unlocked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_locked,
{"Media Locked", "ieee17221.media_locked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_stream_reset,
{"Stream Reset", "ieee17221.stream_reset",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_seq_num_mismatch,
{"Seq Num Mismatch", "ieee17221.seq_num_mismatch",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_media_reset,
{"Media Reset", "ieee17221.media_reset",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_uncertain,
{"Timestamp Uncertain", "ieee17221.timestamp_uncertain",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_valid,
{"Timestamp Valid", "ieee17221.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_timestamp_not_valid,
{"Timestamp Not Valid", "ieee17221.timestamp_not",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_unsupported_format,
{"Unsupported Format", "ieee17221.unsupported_format",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_late_timestamp,
{"Late Timestamp", "ieee17221.late_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_early_timestamp,
{"Early Timestamp", "ieee17221.early_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_packets_tx,
{"Stream Packets TX", "ieee17221.stream_packets_tx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_input_packets_rx,
{"Stream Packets RX", "ieee17221.stream_packets_rx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific1,
{"Entity Specific 1", "ieee17221.entity_specific1",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific2,
{"Entity Specific 2", "ieee17221.entity_specific2",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific3,
{"Entity Specific 3", "ieee17221.entity_specific3",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific4,
{"Entity Specific 4", "ieee17221.entity_specific4",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific5,
{"Entity Specific 5", "ieee17221.entity_specific5",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific6,
{"Entity Specific 6", "ieee17221.entity_specific6",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific7,
{"Entity Specific 7", "ieee17221.entity_specific7",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_entity_specific8,
{"Entity Specific 8", "ieee17221.entity_specific8",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_media_format,
{"Media Format", "ieee17221.media_format",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_video_format,
{"Video Format", "ieee17221.video_format",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_sampling_rate_pull,
{ "Sampling Rate Pull Value", "ieee17221.sampling_rate_pull",
FT_UINT32, BASE_HEX, VALS(aecp_sampling_rate_pull_field_vals), AECP_SAMPLING_RATE_PULL_MASK, NULL, HFILL }
},
{ &hf_aecp_sampling_rate_base_frequency,
{"Sampling Rate Base Frequency", "ieee17221.sampling_rate_base_frequency",
FT_UINT32, BASE_DEC, NULL, AECP_SAMPLING_RATE_BASE_FREQ_MASK, NULL, HFILL }
},
#if 0
{ &hf_aecp_address_type,
{"Address Type", "ieee17221.address_type",
FT_UINT16, BASE_HEX, VALS(aecp_address_type_vals), 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_mac_address,
{ "MAC address", "ieee17221.mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_ipv4_address,
{"IPV4 Address", "ieee17221.ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_ipv6_address,
{"IPv6 Address", "ieee17221.ipv6_address",
FT_IPv6, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
#if 0
{ &hf_aecp_query_period,
{"Query Period (ms)", "ieee17221.query_period",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_query_limit,
{"Query Limit", "ieee17221.query_limit",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_query_type,
{"Query Type", "ieee17221.query_type",
FT_UINT16, BASE_HEX, VALS(aecp_command_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aecp_query_id,
{"Query ID", "ieee17221.query_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
#if 0
{ &hf_aecp_count,
{"Count", "ieee17221.count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_descriptors,
{"Descriptors Array", "ieee17221.descriptors",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_values_count,
{"Values Count", "ieee17221.values_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_operation_id,
{"Operation ID", "ieee17221.operation_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_operation_type,
{"Operation Type", "ieee17221.operation_type",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_percent_complete,
{"Percent Complete", "ieee17221.percent_complete",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_entity_id,
{"Entity ID", "ieee17221.entity_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_entity_model_id,
{"Entity Model ID", "ieee17221.entity_model_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_entity_name,
{"Entity Name", "ieee17221.entity_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_vendor_name_string,
{"Vendor Name String (ptr)", "ieee17221.vendor_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_model_name_string,
{"Model Name String (ptr)", "ieee17221.model_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_firmware_version,
{"Firmware Version", "ieee17221.firmware_version",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_group_name,
{"Group Name", "ieee17221.group_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_serial_number,
{"Serial Number", "ieee17221.serial_number",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_configurations_count,
{"Configurations Count", "ieee17221.configurations_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_current_configuration,
{"Current Configuration", "ieee17221.current_configuration",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_configuration_name,
{"Object Name", "ieee17221.configuration_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_configuration_name_string,
{"Localized Description", "ieee17221.configuration_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_descriptor_counts_count,
{"Descriptor Counts Count", "ieee17221.descriptor_counts_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_descriptor_counts_offset,
{"Descriptor Counts Offset", "ieee17221.descriptor_counts_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_count,
{"Count", "ieee17221.count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_stream_input_ports,
{"Number Of Stream Input Ports", "ieee17221.number_of_stream_input_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_stream_input_port,
{"Base Stream Input Port", "ieee17221.base_stream_input_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_stream_output_ports,
{"Number Of Stream Output Ports", "ieee17221.number_of_stream_output_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_stream_output_port,
{"Base Stream Output Port", "ieee17221.base_stream_output_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_external_input_ports,
{"Number Of External Input Ports", "ieee17221.number_of_external_input_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_external_input_port,
{"Base External Input Port", "ieee17221.base_external_input_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_external_output_ports,
{"Number Of External Output Ports", "ieee17221.number_of_external_output_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_external_output_port,
{"Base External Output Port", "ieee17221.base_external_output_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_internal_input_ports,
{"Number Of Internal Input Ports", "ieee17221.number_of_internal_input_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_internal_input_port,
{"Base Internal Input Port", "ieee17221.base_internal_input_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_internal_output_ports,
{"Number Of Internal Output Ports", "ieee17221.number_of_internal_output_ports",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_internal_output_port,
{"Base Internal Output Port", "ieee17221.base_internal_output_port",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_id,
{"Clock Source ID", "ieee17221.clock_source_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_domain_id,
{"Clock Domain ID", "ieee17221.clock_domain_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_sources_offset,
{"Clock Sources Offset", "ieee17221.clock_sources_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_index,
{"Clock Source Index", "ieee17221.clock_source_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_sources_count,
{"Clock Sources Count", "ieee17221.clock_sources_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_sources,
{"Clock Sources", "ieee17221.clock_sources",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_sources_array,
{"Clock Sources Array", "ieee17221.clock_sources_array",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_controls,
{"Number Of Controls", "ieee17221.number_of_controls",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_control,
{"Base Control", "ieee17221.base_control",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_control_blocks,
{"Number Of Control Blocks", "ieee17221.number_of_control_blocks",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_control_block,
{"Base Control Block", "ieee17221.base_control_block",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_object_name,
{"Object Name", "ieee17221.object_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_localized_description,
{"Localized Description", "ieee17221.localized_description",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_current_sample_rate,
{"Current Sample Rate", "ieee17221.current_sample_rate",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_signal_selectors,
{"Number of Signal Selectors", "ieee17221.num_signal_selectors",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_signal_selector,
{"Base Signal Selector", "ieee17221.base_signal_selector",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_mixers,
{"Number of Mixers", "ieee17221.num_mixers",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_mixer,
{"Base Mixer", "ieee17221.base_mixer",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_matrices,
{"Number of Matrices", "ieee17221.num_matrices",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_matrix,
{"Base Matrix", "ieee17221.base_matrix",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_splitters,
{"Number of Splitters", "ieee17221.num_splitters",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_splitter,
{"Base Splitter", "ieee17221.base_splitter",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_combiners,
{"Number of Combiners", "ieee17221.num_combiners",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_combiner,
{"Base Combiner", "ieee17221.base_combiner",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_demultiplexers,
{"Number of Demultiplexers", "ieee17221.num_demultiplexer",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_demultiplexer,
{"Base Demultiplexer", "ieee17221.base_demultiplexer",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_multiplexers,
{"Number of Multiplexers", "ieee17221.num_multiplexers",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_multiplexer,
{"Base Multiplexer", "ieee17221.base_multiplexer",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_transcoders,
{"Number of Transcoders", "ieee17221.num_transcoders",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_transcoder,
{"Base Transcoder", "ieee17221.base_transcoder",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sample_rates_offset,
{"Sample Rates Offset", "ieee17221.sample_rates_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sample_rates_count,
{"Sample Rates Count", "ieee17221.sample_rates_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sample_rates,
{"Sample Rates", "ieee17221.sample_rates",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_frequency,
{"Base Frequency", "ieee17221.base_frequency",
FT_UINT32, BASE_DEC, NULL, AEM_BASE_FREQUENCY_MASK, NULL, HFILL }
},
{ &hf_aem_pull_field,
{"Pull Field (frequency multiplier)", "ieee17221.pull_field",
FT_UINT8, BASE_HEX, VALS(aem_frequency_multiplier_type_vals), AEM_PULL_FIELD_MASK, NULL, HFILL }
},
{ &hf_aem_stream_name,
{"Object Name", "ieee17221.stream_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_stream_name_string,
{"Localized Description", "ieee17221.stream_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_stream_flags,
{"Stream Flags", "ieee17221.stream_flags",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_flags_clock_sync_source,
{"Clock Sync Source Flag", "ieee17221.flags.clock_sync_source",
FT_BOOLEAN, 16, NULL, AEM_CLOCK_SYNC_SOURCE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aem_flags_class_a,
{"Class A Flag", "ieee17221.flags.class_a",
FT_BOOLEAN, 16, NULL, AEM_CLASS_A_FLAG_MASK, NULL, HFILL }
},
{ &hf_aem_flags_class_b,
{"Class B Flag", "ieee17221.flags.class_b",
FT_BOOLEAN, 16, NULL, AEM_CLASS_B_FLAG_MASK, NULL, HFILL }
},
#if 0
{ &hf_aem_stream_channels,
{"Stream Channels", "ieee17221.stream_channels",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_formats_offset,
{"Formats Offset", "ieee17221.formats_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_formats,
{"Number Of Formats", "ieee17221.number_of_formats",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_guid_0,
{"Primary Backup Talker GUID", "ieee17221.backup_talker_guid_0",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_unique_0,
{"Primary Backup Talker Unique ID", "ieee17221.backup_talker_unique_0",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_guid_1,
{"Secondary Backup Talker GUID", "ieee17221.backup_talker_guid_1",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_unique_1,
{"Secondary Backup Talker Unique ID", "ieee17221.backup_talker_unique_1",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_guid_2,
{"Tertiary Backup Talker GUID", "ieee17221.backup_talker_guid_2",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backup_talker_unique_2,
{"Tertiary Backup Talker Unique ID", "ieee17221.backup_talker_unique_2",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backedup_talker_guid,
{"Backedup Talker GUID", "ieee17221.backedup_talker_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_backedup_talker_unique,
{"Backedup Talker Unique ID", "ieee17221.backedup_talker_unique",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_interface_id,
{"AVB Interface ID", "ieee17221.avb_interface_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_buffer_length,
{"Buffer Length", "ieee17221.buffer_length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_stream_formats,
{"Stream Formats Array", "ieee17221.stream_formats",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_name,
{"Object Name", "ieee17221.jack_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_name_string,
{"Localized Description", "ieee17221.jack_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_interface_name,
{"Interface Name", "ieee17221.interface_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_interface_name_string,
{"Interface Name String", "ieee17221.interface_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_flags,
{"Jack Flags", "ieee17221.jack_flags",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_flags_captive,
{"Captive Flag", "ieee17221.flags.captive",
FT_BOOLEAN, 16, NULL, AEM_CAPTIVE_FLAG_MASK, NULL, HFILL }
},
{ &hf_aem_jack_type,
{"Jack Type", "ieee17221.jack_type",
FT_UINT16, BASE_HEX, VALS(aem_jack_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_port_flags,
{"Port Flags", "ieee17221.port_flags",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_flags_async_sample_rate_conv,
{"Asynchronous Sample Rate Converter Flag", "ieee17221.flags.async_sample_rate_conv",
FT_BOOLEAN, 16, NULL, AEM_ASYNC_SAMPLE_RATE_CONV_FLAG_MASK, NULL, HFILL }
},
{ &hf_aem_flags_sync_sample_rate_conv,
{"Synchronous Sample Rate Converter Flag", "ieee17221.flags.sync_sample_rate_conv",
FT_BOOLEAN, 16, NULL, AEM_SYNC_SAMPLE_RATE_CONV_FLAG_MASK, NULL, HFILL }
},
#if 0
{ &hf_aem_audio_channels,
{"Audio Channels", "ieee17221.audio_channels",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_number_of_clusters,
{"Number of Clusters", "ieee17221.number_of_clusters",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_cluster,
{"Base Cluster", "ieee17221.base_cluster",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_audio_map,
{"Base Audio Map", "ieee17221.base_audio_map",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_audio_maps,
{"Number of Audio Maps", "ieee17221.num_audio_maps",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_stream_id,
{"Stream Descriptor ID", "ieee17221.stream_descriptor_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_formats_count,
{"Formats Count", "ieee17221.formats_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_jack_id,
{"Jack ID", "ieee17221.jack_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_internal_id,
{"Internal ID", "ieee17221.internal_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_avb_interface_flags,
{"Interface Flags", "ieee17221.interface_flags",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_clock_identity,
{"Clock Identity", "ieee17221.clock_identity",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_priority1,
{"Priority1", "ieee17221.priority1",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_clock_class,
{"Clock Class", "ieee17221.clock_class",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_offset_scaled_log_variance,
{"Scaled Log Variance", "ieee17221.offset_scaled_log_variance",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_clock_accuracy,
{"Clock Accuracy", "ieee17221.clock_accuracy",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_priority2,
{"Priority2", "ieee17221.priority2",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_domain_number,
{"Domain Number", "ieee17221.domain_number",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_avb_log_sync_interval,
{"Log sync Interval", "ieee17221.log_sync_interval",
FT_INT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_avb_propagation_delay,
{"Propagation Delay", "ieee17221.propagation_delay",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_clock_source_name,
{"Object Name", "ieee17221.clock_source_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_name_string,
{"Localized Description", "ieee17221.clock_source_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_flags,
{"Clock Source Flags", "ieee17221.clock_source_flags",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_type,
{"Clock Source Type", "ieee17221.clock_source_type",
FT_UINT16, BASE_HEX, VALS(aem_clock_source_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_location_type,
{"Clock Source Location Type", "ieee17221.clock_source_location_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_location_id,
{"Clock Source Location ID", "ieee17221.clock_source_location_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mappings_offset,
{"Mappings Offset", "ieee17221.mappings_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_mappings,
{"Number of Mappings", "ieee17221.number_of_mappings",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mappings,
{"Mappings", "ieee17221.mappings",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mapping_stream_index,
{"Mapping Stream Index", "ieee17221.mapping_stream_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mapping_stream_channel,
{"Mapping Stream Channel", "ieee17221.mapping_stream_channel",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mapping_cluster_offset,
{"Mapping Cluster Offset", "ieee17221.mapping_cluster_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mapping_cluster_channel,
{"Mapping Cluster Channel", "ieee17221.mapping_cluster_channel",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_channel_count,
{"Channel Count", "ieee17221.channel_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_path_latency,
{"Path Latency", "ieee17221.path_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_am824_label,
{"AM824 Label", "ieee17221.am824_label",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_cluster_name,
{"Cluster Name", "ieee17221.cluster_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_cluster_name_string,
{"Cluster Name String", "ieee17221.cluster_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_control_type,
{"Control Type", "ieee17221.control_type",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_control_location_type,
{"Control Location Type", "ieee17221.control_location_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_control_location_id,
{"Control Location ID", "ieee17221.control_location_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_control_value_type,
{"Control Value Type", "ieee17221.control_value_type",
FT_UINT16, BASE_HEX, VALS(aem_control_value_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_control_domain,
{"Control Domain", "ieee17221.control_domain",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_values_offset,
{"Values Offset", "ieee17221.values_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_values,
{"Number Of Values", "ieee17221.number_of_values",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_latency,
{"Control Latency", "ieee17221.control_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_sources_offset,
{"Sources Offset", "ieee17221.sources_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_current_signal_type,
{"Current Signal Type", "ieee17221.current_signal_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_current_signal_id,
{"Current Signal ID", "ieee17221.current_signal_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_default_signal_type,
{"Default Signal Type", "ieee17221.default_signal_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_default_signal_id,
{"Default Signal ID", "ieee17221.default_signal_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_block_latency,
{"Block Latency", "ieee17221.block_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_reset_time,
{"Reset Time", "ieee17221.reset_time",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_signal_type,
{"Signal Type", "ieee17221.signal_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_signal_index,
{"Signal Index", "ieee17221.signal_index",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_signal_output,
{"Signal Output", "ieee17221.signal_output",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_number_of_sources,
{"Number of Sources", "ieee17221.number_of_sources",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_value_offset,
{"Value Offset", "ieee17221.value_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_width,
{"Width", "ieee17221.width",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_height,
{"Height", "ieee17221.height",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_source,
{"Base Source", "ieee17221.base_source",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_destinations,
{"Number of Destinations", "ieee17221.num_destinations",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_destination,
{"Base Destination", "ieee17221.base_destination",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_locale_identifier,
{"Locale Identifier", "ieee17221.locale_identifier",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_of_strings,
{"Number of Strings", "ieee17221.number_of_strings",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_strings,
{"Base Strings", "ieee17221.base_strings",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_string,
{"String", "ieee17221.string",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_signals_count,
{"Signals Count", "ieee17221.signals_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_signals_offset,
{"Signals Offset", "ieee17221.signals_offset",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_memory_object_type,
{"Memory Object Type", "ieee17221.memory_object_type",
FT_UINT16, BASE_HEX, VALS(aem_memory_object_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_target_descriptor_type,
{"Target Descriptor Type", "ieee17221.target_descriptor_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_target_descriptor_id,
{"Target Descriptor ID", "ieee17221.target_descriptor_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_start_address,
{"Start Address", "ieee17221.start_address",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_length,
{"Length", "ieee17221.length",
FT_UINT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_int8,
{"Control INT8", "ieee17221.ctrl_int8",
FT_INT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_uint8,
{"Control UINT8", "ieee17221.ctrl_uint8",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_int16,
{"Control INT16", "ieee17221.ctrl_int16",
FT_INT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_uint16,
{"Control UINT16", "ieee17221.ctrl_uint16",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_int32,
{"Control INT32", "ieee17221.ctrl_int32",
FT_INT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_uint32,
{"Control UINT32", "ieee17221.ctrl_uint32",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_int64,
{"Control INT64", "ieee17221.ctrl_int64",
FT_INT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_uint64,
{"Control UINT64", "ieee17221.ctrl_uint64",
FT_UINT64, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_float,
{"Control FLOAT", "ieee17221.ctrl_float",
FT_FLOAT, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_double,
{"Control DOUBLE", "ieee17221.ctrl_double",
FT_DOUBLE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_ctrl_vals,
{"Control Values", "ieee17221.ctrl_vals",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_unit,
{"Control Value Units", "ieee17221.units",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_string_ref,
{"String Reference", "ieee17221.string_ref",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_guid,
{"GUID", "ieee17221.guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_blob_size,
{"Blob Size", "ieee17221.blob_size",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_binary_blob,
{"Binary Blob", "ieee17221.binary_blob",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sources,
{"Sources", "ieee17221.sources",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_unknown_descriptor,
{"Unknown or Malformed Descriptor", "ieee17221.unknown_descriptor",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_frequency,
{"Frequency", "ieee17221.frequency",
FT_FLOAT, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aem_oui24,
{"OUI-24", "ieee17221.oui24",
FT_UINT24, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mfd_type,
{"MFD Type", "ieee17221.mfd_type",
FT_UINT8, BASE_HEX, VALS(aem_mfd_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_div,
{"Div Flag", "ieee17221.div",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_interlace,
{"Interlace Flag", "ieee17221.interlace",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_channels,
{"Video Channel Count", "ieee17221.channels",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_CHANNELS, NULL, HFILL }
},
{ &hf_aem_color_format,
{"Color Format", "ieee17221.color_format",
FT_UINT16, BASE_HEX, VALS(aem_color_format_type_vals), AEM_MASK_COLOR_FORMAT, NULL, HFILL }
},
{ &hf_aem_bpp,
{"Bits Per Pixel", "ieee17221.bpp",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_BPP, NULL, HFILL }
},
{ &hf_aem_aspect_x,
{"Aspect X", "ieee17221.aspect_x",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_aspect_y,
{"Aspect Y", "ieee17221.aspect_y",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_frame_rate,
{"Frame Rate", "ieee17221.frame_rate",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_comp1,
{"Comp 1", "ieee17221.comp1",
FT_UINT16, BASE_DEC, NULL, AEM_MASK_COMP1, NULL, HFILL }
},
{ &hf_aem_comp2,
{"Comp 2", "ieee17221.comp2",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_COMP2, NULL, HFILL }
},
{ &hf_aem_comp3,
{"Comp 3", "ieee17221.comp3",
FT_UINT16, BASE_DEC, NULL, AEM_MASK_COMP3, NULL, HFILL }
},
{ &hf_aem_comp4,
{"Comp 4", "ieee17221.comp4",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_COMP4, NULL, HFILL }
},
{ &hf_aem_mf_width,
{"Width", "ieee17221.width",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_mf_height,
{"Height", "ieee17221.height",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_cs_eui64,
{"CS EUI64", "ieee17221.cs_eui64",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aem_stream_format,
{"Stream Format", "ieee17221.stream_format",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sf_version,
{"Version", "ieee17221.sf_version",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_SF_VERSION, NULL, HFILL }
},
{ &hf_aem_sf_subtype,
{"Subtype", "ieee17221.sf_subtype",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_SF_SUBTYPE, NULL, HFILL }
},
{ &hf_aem_sf,
{"SF", "ieee17221.sf",
FT_BOOLEAN, 8, NULL, AEM_MASK_SF, NULL, HFILL }
},
{ &hf_aem_iidc_format,
{"IIDC Format", "ieee17221.iidc_format",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_iidc_mode,
{"IIDC Mode", "ieee17221.iidc_mode",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_iidc_rate,
{"IIDC Rate", "ieee17221.iidc_rate",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_fmt,
{"FMT", "ieee17221.fmt",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_FMT, NULL, HFILL }
},
{ &hf_aem_fdf_evt,
{"FDF EVT", "ieee17221.fdf_evt",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_FDF_EVT, NULL, HFILL }
},
{ &hf_aem_fdf_sfc,
{"FDF SFC", "ieee17221.fdf_sfc",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_FDF_SFC, NULL, HFILL }
},
{ &hf_aem_dbs,
{"DBS", "ieee17221.dbs",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_b_flag,
{"Blocking Flag", "ieee17221.flags.b",
FT_BOOLEAN, 8, NULL, AEM_MASK_B, NULL, HFILL }
},
{ &hf_aem_nb_flag,
{"NonBlocking Flag", "ieee17221.flags.nb",
FT_BOOLEAN, 8, NULL, AEM_MASK_NB, NULL, HFILL }
},
{ &hf_aem_label_iec_60958_cnt,
{"Label IEC 60958 Count", "ieee17221.label_iec_60958_cnt",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_label_mbla_cnt,
{"Label Multi-Bit Linear Audio Count", "ieee17221.label_mbla_cnt",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_label_midi_cnt,
{"Label Midi Slot Count", "ieee17221.label_midi_cnt",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_LABEL_MIDI_CNT, NULL, HFILL }
},
{ &hf_aem_label_smpte_cnt,
{"Label SMPTE Slot Count", "ieee17221.label_smpte_cnt",
FT_UINT8, BASE_DEC, NULL, AEM_MASK_LABEL_SMPTE_CNT, NULL, HFILL }
},
{ &hf_aem_video_mode,
{"Video Mode", "ieee17221.video_mode",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_compress_mode,
{"Compress Mode", "ieee17221.compress_mode",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_color_space,
{"Color Space", "ieee17221.color_space",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
#if 0
{ &hf_aecp_values,
{"Values", "ieee17221.values",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
#endif
{ &hf_aecp_status_code,
{"Status", "ieee17221.status",
FT_UINT8, BASE_HEX, VALS(aem_status_type_vals), AECP_STATUS_CODE_MASK, NULL, HFILL }
},
{ &hf_aecp_backup_talker_entity_id_0,
{"Backup Talker Entity ID 0", "ieee17221.backup_talker_entity_id_0",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backup_talker_unique_id_0,
{"Backup Talker Unique ID 0", "ieee17221.backup_talker_unique_id_0",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backup_talker_entity_id_1,
{"Backup Talker Entity ID 1", "ieee17221.backup_talker_entity_id_1",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backup_talker_unique_id_1,
{"Backup Talker Unique ID 1", "ieee17221.backup_talker_unique_id_1",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backup_talker_entity_id_2,
{"Backup Talker Entity ID 2", "ieee17221.backup_talker_entity_id_2",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backup_talker_unique_id_2,
{"Backup Talker Unique ID 2", "ieee17221.backup_talker_unique_id_2",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backedup_talker_entity_id,
{"Backed up Talker Entity ID", "ieee17221.backedup_talker_entity_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_backedup_talker_unique_id,
{"Backedup Talker Unique ID", "ieee17221.backedup_talker_unique_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_17221,
&ett_adp_ent_cap,
&ett_adp_talk_cap,
&ett_adp_list_cap,
&ett_adp_cont_cap,
&ett_adp_samp_rates,
&ett_adp_chan_format,
&ett_acmp_flags,
&ett_aem_desc_counts,
&ett_aem_descriptor,
&ett_aem_sample_rates,
&ett_aem_stream_flags,
&ett_aem_clock_sources,
&ett_aem_stream_formats,
&ett_aem_jack_flags,
&ett_aem_port_flags,
&ett_aecp_get_avb_info_msrp_mappings,
&ett_aecp_get_as_path_sequences,
&ett_aem_clock_source_flags,
&ett_aem_mappings,
&ett_aem_ctrl_vals,
&ett_aem_sources,
&ett_aecp_descriptors,
&ett_aecp_flags_32,
&ett_aem_stream_format,
};
proto_17221 = proto_register_protocol("IEEE 1722.1 Protocol", "IEEE1722.1", "ieee17221");
proto_register_field_array(proto_17221, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_17221(void)
{
dissector_handle_t avb17221_handle;
avb17221_handle = create_dissector_handle(dissect_17221, proto_17221);
dissector_add_uint("ieee1722.subtype", 0x7A, avb17221_handle);
dissector_add_uint("ieee1722.subtype", 0x7B, avb17221_handle);
dissector_add_uint("ieee1722.subtype", 0x7C, avb17221_handle);
}
