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
guint16 subtype;
guint8 sf;
guint8 fmt;
guint8 fdf_evt;
stream_ti = proto_tree_add_item(tree, hf_aem_stream_format, tvb,
0, 8, ENC_NA);
stream_tree = proto_item_add_subtree(stream_ti, ett_aem_stream_format);
version = tvb_get_guint8(tvb, 0) & 0xC0;
proto_tree_add_item(stream_tree, hf_aem_sf_version, tvb,
AEM_OFFSET_SF_VERSION, 1, ENC_BIG_ENDIAN);
if (version == 0) {
subtype = tvb_get_ntohs(tvb, 0) & AEM_MASK_SF_SUBTYPE;
proto_tree_add_item(stream_tree, hf_aem_sf, tvb,
AEM_OFFSET_SF_SUBTYPE, 2, ENC_BIG_ENDIAN);
switch(subtype) {
case SF61883_IIDC_SUBTYPE:
sf = tvb_get_guint8(tvb, 1) & 0x40;
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
fmt = tvb_get_guint8(tvb, AEM_OFFSET_FMT) & 0x3F;
if (fmt == 0x40) {
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
case EXPERIMENTAL_SUBTYPE:
break;
default:
break;
}
}
}
static void
dissect_17221_media_format(tvbuff_t *tvb, proto_tree *tree)
{
proto_item *media_tree;
proto_item *media_ti;
guint32 oui24;
guint8 mfd_type;
oui24 = tvb_get_ntoh24(tvb, 0);
mfd_type = tvb_get_guint8(tvb, 3);
media_ti = proto_tree_add_item(tree, hf_aecp_media_format, tvb,
0, 16, ENC_NA);
media_tree = proto_item_add_subtree(media_ti, ett_aem_media_format);
if (oui24 == OUI24_STANDARD_MEDIA_FORMAT) {
proto_tree_add_item(media_tree, hf_aem_oui24, tvb,
0, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_mfd_type, tvb,
AEM_OFFSET_MFD_TYPE, 1, ENC_BIG_ENDIAN);
switch(mfd_type) {
case MFD_TYPE_VIDEO:
proto_tree_add_item(media_tree, hf_aem_div, tvb,
AEM_OFFSET_DIV, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_interlace, tvb,
AEM_OFFSET_INTERLACE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_channels, tvb,
AEM_OFFSET_CHANNELS, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_color_format, tvb,
AEM_OFFSET_COLOR_FORMAT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_bpp, tvb,
AEM_OFFSET_BPP, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_aspect_x, tvb,
AEM_OFFSET_ASPECT_X, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_aspect_y, tvb,
AEM_OFFSET_ASPECT_Y, 1 ,ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_frame_rate, tvb,
AEM_OFFSET_FRAME_RATE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_comp1, tvb,
AEM_OFFSET_COMP1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_comp2, tvb,
AEM_OFFSET_COMP2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_comp3, tvb,
AEM_OFFSET_COMP3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_comp4, tvb,
AEM_OFFSET_COMP4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_mf_width, tvb,
AEM_OFFSET_SVMF_WIDTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_tree, hf_aem_mf_height, tvb,
AEM_OFFSET_SVMF_HEIGHT, 2, ENC_BIG_ENDIAN);
break;
case MFD_TYPE_TRANSPORT_STRM:
break;
case MFD_TYPE_MIDI:
break;
case MFD_TYPE_TIME_CODE:
break;
case MFD_TYPE_CONTROL_PROTO:
proto_tree_add_item(media_tree, hf_aem_cs_eui64, tvb,
AEM_OFFSET_CS_EUI64, 8, ENC_BIG_ENDIAN);
break;
default:
break;
}
} else {
}
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
proto_tree_add_item(aem_tree, hf_aecp_descriptor_id, tvb,
AEM_OFFSET_DESCRIPTOR_ID, 2, ENC_BIG_ENDIAN);
switch(desc_type) {
case AEM_DESCRIPTOR_ENTITY:
proto_tree_add_item(aem_tree, hf_aem_entity_guid, tvb,
AEM_OFFSET_ENTITY_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_vendor_id, tvb,
AEM_OFFSET_VENDOR_ID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_entity_model_id, tvb,
AEM_OFFSET_ENTITY_MODEL_ID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_avdecc_ip, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_zero_conf, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_gateway_entity, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_avdecc_control, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_legacy_avc, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_assoc_id_support, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_cap_assoc_id_valid, tvb,
AEM_OFFSET_ENTITY_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talker_stream_srcs, tvb,
AEM_OFFSET_TALKER_STREAM_SOURCES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talker_cap, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_implement, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_other_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_control_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_media_clk_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_smpte_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_midi_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_audio_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_talk_cap_video_src, tvb,
AEM_OFFSET_TALKER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_listener_stream_sinks, tvb,
AEM_OFFSET_LISTENER_STREAM_SINKS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_listener_cap, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_implement, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_other_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_control_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_media_clk_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_smpte_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_midi_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_audio_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_list_cap_video_sink, tvb,
AEM_OFFSET_LISTENER_CAPABILITIES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_controller_cap, tvb,
AEM_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_cont_cap_implement, tvb,
AEM_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_cont_cap_layer3_proxy, tvb,
AEM_OFFSET_CONTROLLER_CAPABILITIES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_avail_index, tvb,
AEM_OFFSET_AVAILABLE_INDEX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_as_gm_id, tvb,
AEM_OFFSET_AS_GRANDMASTER_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aecp_association_id, tvb,
AEM_OFFSET_ASSOCIATION_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_adp_entity_type, tvb,
AEM_OFFSET_ENTITY_TYPE, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_entity_name, tvb,
AEM_OFFSET_ENTITY_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_vendor_name_string, tvb,
AEM_OFFSET_VENDOR_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_model_name_string, tvb,
AEM_OFFSET_MODEL_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_firmware_version, tvb,
AEM_OFFSET_FIRMWARE_VERSION, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_group_name, tvb,
AEM_OFFSET_GROUP_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_serial_number, tvb,
AEM_OFFSET_SERIAL_NUMBER, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_configurations_count, tvb,
AEM_OFFSET_CONFIGURATIONS_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_configuration, tvb,
AEM_OFFSET_CURRENT_CONFIGURATION, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CONFIGURATION:
proto_tree_add_item(aem_tree, hf_aem_configuration_name, tvb,
AEM_OFFSET_CONFIGURATION_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_configuration_name_string, tvb,
AEM_OFFSET_CONFIGURATION_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_descriptor_counts_count, tvb,
AEM_OFFSET_DESCRIPTOR_COUNTS_COUNT, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_descriptor_counts_offset, tvb,
AEM_OFFSET_DESCRIPTOR_COUNTS_OFFSET, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_DESCRIPTOR_COUNTS_COUNT);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_desc_counts);
mr_offset = AEM_OFFSET_DESCRIPTOR_COUNTS;
for(i = 0; i < mr_counter; ++i)
{
proto_tree_add_item(mr_subtree, hf_aecp_descriptor_type, tvb, mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_count, tvb, mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_AUDIO:
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_STREAM_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_input_port, tvb,
AEM_OFFSET_BASE_STREAM_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_STREAM_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_output_port, tvb,
AEM_OFFSET_BASE_STREAM_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_EXTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_input_port, tvb,
AEM_OFFSET_BASE_EXTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_EXTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_output_port, tvb,
AEM_OFFSET_BASE_EXTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_INTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_input_port, tvb,
AEM_OFFSET_BASE_INTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_INTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_output_port, tvb,
AEM_OFFSET_BASE_INTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_id, tvb,
AEM_OFFSET_CLOCK_SOURCE_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
AEM_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
AEM_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_unit_name, tvb,
AEM_OFFSET_UNIT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_unit_name_string, tvb,
AEM_OFFSET_UNIT_NAME_STRING, 2, ENC_BIG_ENDIAN);
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
proto_tree_add_item(aem_tree, hf_aem_current_sample_rate, tvb,
AUDIO_UNIT_OFFSET_CURRENT_SAMPLE_RATE, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sample_rates_offset, tvb,
AUDIO_UNIT_OFFSET_SAMPLE_RATES_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sample_rates_count, tvb,
AUDIO_UNIT_OFFSET_SAMPLE_RATES_COUNT, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_sample_rates, tvb,
0, 0, ENC_NA);
mr_counter = tvb_get_ntohs(tvb, AUDIO_UNIT_OFFSET_SAMPLE_RATES_COUNT);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_sample_rates);
mr_offset = AUDIO_UNIT_OFFSET_SAMPLE_RATES;
proto_item_set_len(mr_item, 4 * mr_counter);
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
case AEM_DESCRIPTOR_VIDEO:
case AEM_DESCRIPTOR_SENSOR:
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_STREAM_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_input_port, tvb,
AEM_OFFSET_BASE_STREAM_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_stream_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_STREAM_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_stream_output_port, tvb,
AEM_OFFSET_BASE_STREAM_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_EXTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_input_port, tvb,
AEM_OFFSET_BASE_EXTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_external_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_EXTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_external_output_port, tvb,
AEM_OFFSET_BASE_EXTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_input_ports, tvb,
AEM_OFFSET_NUMBER_OF_INTERNAL_INPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_input_port, tvb,
AEM_OFFSET_BASE_INTERNAL_INPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_internal_output_ports, tvb,
AEM_OFFSET_NUMBER_OF_INTERNAL_OUTPUT_PORTS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_internal_output_port, tvb,
AEM_OFFSET_BASE_INTERNAL_OUTPUT_PORT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_id, tvb,
AEM_OFFSET_CLOCK_SOURCE_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_controls, tvb,
AEM_OFFSET_NUMBER_OF_CONTROLS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_control, tvb,
AEM_OFFSET_BASE_CONTROL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_unit_name, tvb,
AEM_OFFSET_UNIT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_unit_name_string, tvb,
AEM_OFFSET_UNIT_NAME_STRING, 2, ENC_BIG_ENDIAN);
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
break;
case AEM_DESCRIPTOR_STREAM_INPUT:
case AEM_DESCRIPTOR_STREAM_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_stream_name, tvb,
AEM_OFFSET_STREAM_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_stream_name_string, tvb,
AEM_OFFSET_STREAM_NAME_STRING, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_stream_flags, tvb,
AEM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_stream_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_class_a, tvb,
AEM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_class_b, tvb,
AEM_OFFSET_STREAM_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_stream_channels, tvb,
AEM_OFFSET_STREAM_CHANNELS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_clock_source_id, tvb,
AEM_OFFSET_CLOCK_SOURCE_ID_STREAM, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, AEM_OFFSET_CURRENT_FORMAT, 8, 8);
dissect_17221_stream_format(next_tvb, aem_tree);
proto_tree_add_item(aem_tree, hf_aem_formats_offset, tvb,
AEM_OFFSET_FORMATS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_formats, tvb,
AEM_OFFSET_NUMBER_OF_FORMATS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_0, tvb,
AEM_OFFSET_BACKUP_TALKER_GUID_0, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_0, tvb,
AEM_OFFSET_BACKUP_TALKER_UNIQUE_0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_1, tvb,
AEM_OFFSET_BACKUP_TALKER_GUID_1, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_1, tvb,
AEM_OFFSET_BACKUP_TALKER_UNIQUE_1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_guid_2, tvb,
AEM_OFFSET_BACKUP_TALKER_GUID_2, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backup_talker_unique_2, tvb,
AEM_OFFSET_BACKUP_TALKER_UNIQUE_2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backedup_talker_guid, tvb,
AEM_OFFSET_BACKEDUP_TALKER_GUID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_backedup_talker_unique, tvb,
AEM_OFFSET_BACKEDUP_TALKER_UNIQUE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_avb_interface_id, tvb,
AEM_OFFSET_AVB_INTERFACE_ID, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_stream_formats, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_stream_formats);
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_FORMATS);
mr_offset = AEM_OFFSET_FORMATS;
proto_item_set_len(mr_item, mr_counter * 8);
for(i = 0; i < mr_counter; ++i) {
next_tvb = tvb_new_subset(tvb, mr_offset, 8, 8);
dissect_17221_stream_format(next_tvb, mr_subtree);
mr_offset += 8;
}
break;
case AEM_DESCRIPTOR_EXTERNAL_JACK_INPUT:
case AEM_DESCRIPTOR_EXTERNAL_JACK_OUTPUT:
proto_tree_add_item(aem_tree, hf_aem_jack_name, tvb,
AEM_OFFSET_JACK_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_jack_name_string, tvb,
AEM_OFFSET_JACK_NAME_STRING, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_jack_flags, tvb,
AEM_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_jack_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_captive, tvb,
AEM_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_JACK_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_jack_type, tvb,
AEM_OFFSET_JACK_TYPE, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_AUDIO_PORT_INPUT:
case AEM_DESCRIPTOR_AUDIO_PORT_OUTPUT:
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_audio_channels, tvb,
AEM_OFFSET_AUDIO_CHANNELS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_clusters, tvb,
AEM_OFFSET_NUMBER_OF_CLUSTERS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_cluster, tvb,
AEM_OFFSET_BASE_CLUSTER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_audio_map, tvb,
AUDIO_PORT_OFFSET_BASE_AUDIO_MAP, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_audio_maps, tvb,
AUDIO_PORT_OFFSET_NUMBER_AUDIO_MAPS, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_VIDEO_PORT_INPUT:
case AEM_DESCRIPTOR_VIDEO_PORT_OUTPUT:
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, 6, 16, 16);
dissect_17221_media_format(next_tvb, aem_tree);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AEM_OFFSET_SOURCE_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AEM_OFFSET_SOURCE_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_stream_id, tvb,
AEM_OFFSET_STREAM_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_formats_offset, tvb,
AEM_OFFSET_FORMATS_OFFSET_VID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_formats_count, tvb,
AEM_OFFSET_FORMATS_COUNT_VID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
VIDEO_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_FORMATS_COUNT_VID);
mr_offset = VIDEO_PORT_OFFSET_FORMATS;
for(i = 0; i < mr_counter; ++i) {
next_tvb = tvb_new_subset(tvb, mr_offset, 16, 16);
dissect_17221_media_format(next_tvb, aem_tree);
mr_offset += 16;
}
break;
case AEM_DESCRIPTOR_EXTERNAL_PORT_INPUT:
case AEM_DESCRIPTOR_EXTERNAL_PORT_OUTPUT:
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AEM_OFFSET_SOURCE_TYPE_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AEM_OFFSET_SOURCE_ID_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_jack_id, tvb,
EXTERNAL_PORT_OFFSET_JACK_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
EXTERNAL_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_SENSOR_PORT_INPUT:
case AEM_DESCRIPTOR_SENSOR_PORT_OUTPUT:
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AEM_OFFSET_SOURCE_TYPE_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AEM_OFFSET_SOURCE_ID_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_stream_id, tvb,
AEM_OFFSET_STREAM_ID_SEN, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
SENSOR_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_INTERNAL_PORT_INPUT:
case AEM_DESCRIPTOR_INTERNAL_PORT_OUTPUT:
mr_item = proto_tree_add_item(aem_tree, hf_aem_port_flags, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_port_flags);
proto_tree_add_item(mr_subtree, hf_aem_flags_clock_sync_source, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_async_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_flags_sync_sample_rate_conv, tvb,
AEM_OFFSET_PORT_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AEM_OFFSET_SOURCE_TYPE_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AEM_OFFSET_SOURCE_ID_EXT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_internal_id, tvb,
AEM_OFFSET_INTERNAL_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
INTERNAL_PORT_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_AVB_INTERFACE:
proto_tree_add_item(aem_tree, hf_aecp_mac_address, tvb,
AEM_OFFSET_MAC_ADDRESS, 6, ENC_NA);
proto_tree_add_item(aem_tree, hf_adp_as_gm_id, tvb,
AEM_OFFSET_AS_GRANDMASTER_ID_AVB, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_msrp_mappings_offset, tvb,
AEM_OFFSET_MSRP_MAPPINGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_msrp_mappings_count, tvb,
AEM_OFFSET_MSRP_MAPPINGS_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_interface_name, tvb,
AVB_INTERFACE_OFFSET_INTERFACE_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_interface_name_string, tvb,
AVB_INTERFACE_OFFSET_INTERFACE_NAME_STRING, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_msrp_mappings, tvb,
AVB_INTERFACE_MSRP_MAPPINGS, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_msrp_mappings);
mr_offset = AVB_INTERFACE_MSRP_MAPPINGS;
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_MSRP_MAPPINGS_COUNT);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_msrp_mapping_traffic_class, tvb,
mr_offset, 1, ENC_BIG_ENDIAN);
++mr_offset;
proto_tree_add_item(mr_subtree, hf_aem_msrp_mapping_priority, tvb,
mr_offset, 1, ENC_BIG_ENDIAN);
++mr_offset;
proto_tree_add_item(mr_subtree, hf_aem_msrp_vlan_id, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_CLOCK_SOURCE:
proto_tree_add_item(aem_tree, hf_aem_clock_source_name, tvb,
AEM_OFFSET_CLOCK_SOURCE_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_clock_source_name_string, tvb,
AEM_OFFSET_CLOCK_SOURCE_NAME_STRING, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_clock_source_flags, tvb,
AEM_OFFSET_CLOCK_SOURCE_FLAGS, 2, ENC_BIG_ENDIAN);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_clock_source_flags);
proto_tree_add_item(mr_subtree, hf_aem_clock_source_type, tvb,
AEM_OFFSET_CLOCK_SOURCE_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aecp_clock_source_id, tvb,
AEM_OFFSET_CLOCK_SOURCE_ID_CLK, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_clock_source_location_type, tvb,
AEM_OFFSET_CLOCK_SOURCE_LOCATION_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_subtree, hf_aem_clock_source_location_id, tvb,
AEM_OFFSET_CLOCK_SOURCE_LOCATION_ID, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_AUDIO_MAP:
proto_tree_add_item(aem_tree, hf_aem_mappings_offset, tvb,
AEM_OFFSET_MAPPINGS_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_mappings, tvb,
AEM_OFFSET_NUMBER_OF_MAPPINGS, 2, ENC_BIG_ENDIAN);
mr_item = proto_tree_add_item(aem_tree, hf_aem_mappings, tvb,
0, 0, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aem_mappings);
mr_offset = AEM_OFFSET_MAPPINGS;
mr_counter = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_MAPPINGS);
proto_item_set_len(mr_item, mr_counter * 6);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_mapping_stream_index, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_mapping_stream_channel, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_mapping_audio_channel, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_AUDIO_CLUSTER:
proto_tree_add_item(aem_tree, hf_aem_channel_count, tvb,
AUDIO_CLUSTER_OFFSET_CHANNEL_COUNT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_path_latency, tvb,
AUDIO_CLUSTER_OFFSET_PATH_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_am824_label, tvb,
AUDIO_CLUSTER_OFFSET_AM824_LABEL, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_cluster_name, tvb,
AUDIO_CLUSTER_OFFSET_CLUSTER_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_cluster_name_string, tvb,
AUDIO_CLUSTER_OFFSET_CLUSTER_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AUDIO_CLUSTER_OFFSET_SIGNAL_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AUDIO_CLUSTER_OFFSET_SIGNAL_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
AUDIO_CLUSTER_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_CONTROL:
proto_tree_add_item(aem_tree, hf_aem_control_type, tvb,
AEM_OFFSET_CONTROL_TYPE, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_value_type, tvb,
AEM_OFFSET_CONTROL_VALUE_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_name, tvb,
AEM_OFFSET_CONTROL_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_control_name_string, tvb,
AEM_OFFSET_CONTROL_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_values_offset, tvb,
AEM_OFFSET_VALUES_OFFSET_CTRL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_values, tvb,
AEM_OFFSET_NUMBER_OF_VALUES_CTRL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_type, tvb,
AEM_OFFSET_SOURCE_TYPE_CTRL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_signal_id, tvb,
AEM_OFFSET_SOURCE_ID_CTRL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
CONTROL_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
CONTROL_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
ctrl_val_type = tvb_get_ntohs(tvb, AEM_OFFSET_CONTROL_VALUE_TYPE);
num_ctrl_vals = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_VALUES_CTRL);
dissect_17221_ctrl_val(tvb, aem_tree, num_ctrl_vals, ctrl_val_type,
CONTROL_OFFSET_VALUE_DETAILS);
break;
case AEM_DESCRIPTOR_SIGNAL_SELECTOR:
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_name, tvb,
AEM_OFFSET_CONTROL_NAME_SIGS, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_control_name_string, tvb,
AEM_OFFSET_CONTROL_NAME_STRING_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_sources_offset, tvb,
AEM_OFFSET_SOURCES_OFFSET_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_sources, tvb,
AEM_OFFSET_NUMBER_OF_SOURCES_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_signal_type, tvb,
AEM_OFFSET_CURRENT_SOURCE_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_current_signal_id, tvb,
AEM_OFFSET_CURRENT_SOURCE_ID_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_default_signal_type, tvb,
AEM_OFFSET_DEFAULT_SOURCE_TYPE_SIGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_default_signal_id, tvb,
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
proto_tree_add_item(mr_subtree, hf_aem_signal_id, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AEM_DESCRIPTOR_MIXER:
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_value_type, tvb,
AEM_OFFSET_CONTROL_VALUE_TYPE_MXR, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN_MXR, 2 ,ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_name, tvb,
AEM_OFFSET_CONTROL_NAME_MXR, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_control_name_string, tvb,
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
proto_tree_add_item(mr_subtree, hf_aem_signal_id, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
ctrl_val_type = tvb_get_ntohs(tvb, AEM_OFFSET_CONTROL_VALUE_TYPE_MXR);
num_ctrl_vals = 1;
dissect_17221_ctrl_val(tvb, aem_tree, num_ctrl_vals, ctrl_val_type,
MIXER_OFFSET_SOURCES + (tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_SOURCES_MXR) * 4));
break;
case AEM_DESCRIPTOR_MATRIX:
proto_tree_add_item(aem_tree, hf_aem_control_type, tvb,
AEM_OFFSET_CONTROL_TYPE_MTRX, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_type, tvb,
AEM_OFFSET_CONTROL_LOCATION_TYPE_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_location_id, tvb,
AEM_OFFSET_CONTROL_LOCATION_ID_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_value_type, tvb,
AEM_OFFSET_CONTROL_VALUE_TYPE_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_domain, tvb,
AEM_OFFSET_CONTROL_DOMAIN_MTRX, 2 ,ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_name, tvb,
AEM_OFFSET_CONTROL_NAME_MTRX, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_control_name_string, tvb,
AEM_OFFSET_CONTROL_NAME_STRING_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_width, tvb,
AEM_OFFSET_WIDTH_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_height, tvb,
AEM_OFFSET_HEIGHT_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_values_offset, tvb,
AEM_OFFSET_VALUES_OFFSET_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_values, tvb,
AEM_OFFSET_NUMBER_OF_VALUES_MTRX, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_block_latency, tvb,
MATRIX_OFFSET_BLOCK_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_control_latency, tvb,
MATRIX_OFFSET_CONTROL_LATENCY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_of_sources, tvb,
MATRIX_OFFSET_NUMBER_SOURCES, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_source, tvb,
MATRIX_OFFSET_BASE_SOURCE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_number_destinations, tvb,
MATRIX_OFFSET_NUMBER_DESTINATIONS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_destination, tvb,
MATRIX_OFFSET_BASE_DESTINATION, 2, ENC_BIG_ENDIAN);
ctrl_val_type = tvb_get_ntohs(tvb, AEM_OFFSET_CONTROL_VALUE_TYPE_MTRX);
num_ctrl_vals = tvb_get_ntohs(tvb, AEM_OFFSET_NUMBER_OF_VALUES_MTRX);
dissect_17221_ctrl_val(tvb, aem_tree, num_ctrl_vals, ctrl_val_type,
MATRIX_OFFSET_VALUE_DETAILS);
break;
case AEM_DESCRIPTOR_LOCALE:
proto_tree_add_item(aem_tree, hf_aem_locale_identifier, tvb,
AEM_OFFSET_LOCALE_IDENTIFIER, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_number_of_strings, tvb,
AEM_OFFSET_NUMBER_OF_STRINGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_base_strings, tvb,
AEM_OFFSET_BASE_STRINGS, 2, ENC_BIG_ENDIAN);
break;
case AEM_DESCRIPTOR_STRINGS:
mr_offset = AEM_OFFSET_STRING0;
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
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aem_signal_type, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aem_signal_id, tvb,
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
MEMORY_OBJECT_OFFSET_TARGET_DESCRIPTOR_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_object_name, tvb,
MEMORY_OBJECT_OFFSET_OBJECT_NAME, 64, ENC_ASCII|ENC_NA);
proto_tree_add_item(aem_tree, hf_aem_object_name_string, tvb,
MEMORY_OBJECT_OFFSET_OBJECT_NAME_STRING, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_start_address, tvb,
MEMORY_OBJECT_OFFSET_START_ADDRESS, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aem_tree, hf_aem_length, tvb,
MEMORY_OBJECT_OFFSET_LENGTH, 8, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(aem_tree, hf_aem_unknown_descriptor, tvb,
4, tvb_length(tvb) - 4, ENC_NA);
break;
}
}
static void
dissect_17221_aecp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *aecp_tree)
{
guint16 c_type;
guint16 addr_type;
#if 0
guint16 ctrl_data_len;
guint16 mess_status;
#endif
guint16 mess_type;
guint32 mr_offset;
guint16 mr_counter;
proto_item *mr_subtree;
proto_item *mr_item;
int i;
tvbuff_t *next_tvb;
proto_tree *flags_tree;
proto_item *flags_ti;
proto_tree_add_item(aecp_tree, hf_aecp_message_type, tvb,
AECP_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_status_code, tvb,
AECP_STATUS_CODE_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_cd_length, tvb,
AECP_CD_LENGTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_target_guid, tvb,
AECP_TARGET_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_controller_guid, tvb,
AECP_CONTROLLER_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_sequence_id, tvb,
AECP_SEQUENCE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_u_flag, tvb,
AECP_U_FLAG_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_command_type, tvb,
AECP_COMMAND_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
c_type = tvb_get_ntohs(tvb, AECP_COMMAND_TYPE_OFFSET) & AECP_COMMAND_TYPE_MASK;
#if 0
ctrl_data_len = tvb_get_ntohs(tvb, AECP_CD_LENGTH_OFFSET) & AECP_CD_LENGTH_MASK;
#endif
mess_type = tvb_get_ntohs(tvb, 0) & ACMP_MSG_TYPE_MASK;
#if 0
mess_status = tvb_get_ntohs(tvb, 2) & 0xF800;
#endif
switch(c_type) {
case AECP_COMMAND_LOCK_ENTITY:
proto_tree_add_item(aecp_tree, hf_aecp_unlock_flag, tvb,
AECP_FLAGS_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_locked_guid, tvb,
AECP_LOCKED_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_READ_DESCRIPTOR:
proto_tree_add_item(aecp_tree, hf_aecp_configuration, tvb,
AECP_CONFIGURATION_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_COMMAND_MESSAGE)
{
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET_28, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET_30, 2, ENC_BIG_ENDIAN);
}
else
{
next_tvb = tvb_new_subset_remaining(tvb, 28);
dissect_17221_aem(next_tvb, pinfo, aecp_tree);
}
break;
case AECP_COMMAND_WRITE_DESCRIPTOR:
proto_tree_add_item(aecp_tree, hf_aecp_configuration, tvb,
AECP_CONFIGURATION_OFFSET, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 28);
dissect_17221_aem(next_tvb, pinfo, aecp_tree);
break;
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
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_OFFSET_ACQUIRE_ENTITY_DESCRIPTOR_ID, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_CLOCK_SOURCE:
case AECP_COMMAND_GET_CLOCK_SOURCE:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_OFFSET_CLOCK_SOURCE_DESCRIPTOR_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_OFFSET_CLOCK_SOURCE_DESCRIPTOR_ID, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aem_clock_source_id, tvb,
AECP_OFFSET_CLOCK_SOURCE_CLOCK_SOURCE_ID, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_STREAM_FORMAT:
case AECP_COMMAND_GET_STREAM_FORMAT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, AECP_STREAM_FORMAT_OFFSET, 8, 8);
dissect_17221_stream_format(next_tvb, aecp_tree);
break;
case AECP_COMMAND_SET_CONFIGURATION:
case AECP_COMMAND_GET_CONFIGURATION:
proto_tree_add_item(aecp_tree, hf_aecp_configuration,
tvb, AECP_CONFIGURATION_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_CONTROL_VALUE:
case AECP_COMMAND_GET_CONTROL_VALUE:
case AECP_COMMAND_SET_MIXER:
case AECP_COMMAND_GET_MIXER:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_SIGNAL_SELECTOR:
case AECP_COMMAND_GET_SIGNAL_SELECTOR:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_signal_type, tvb,
AECP_SOURCE_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_signal_id, tvb,
AECP_SOURCE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_MATRIX:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_column, tvb,
AECP_MATRIX_COLUMN_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_row, tvb,
AECP_MATRIX_ROW_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_width, tvb,
AECP_MATRIX_REGION_WIDTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_height, tvb,
AECP_MATRIX_REGION_HEIGHT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_rep, tvb,
AECP_MATRIX_REP_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_direction, tvb,
AECP_MATRIX_DIRECTION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_value_count, tvb,
AECP_MATRIX_VALUE_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_item_offset, tvb,
AECP_MATRIX_ITEM_OFFSET_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_matrix_affected_item_count, tvb,
AECP_MATRIX_AFFECTED_ITEM_COUNT_OFFSET, 4, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_GET_MATRIX:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_column, tvb,
AECP_MATRIX_COLUMN_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_row, tvb,
AECP_MATRIX_ROW_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_width, tvb,
AECP_MATRIX_REGION_WIDTH_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_region_height, tvb,
AECP_MATRIX_REGION_HEIGHT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_direction, tvb,
AECP_MATRIX_DIRECTION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_value_count, tvb,
AECP_MATRIX_VALUE_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_matrix_item_offset, tvb,
AECP_MATRIX_ITEM_OFFSET_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_START_STREAMING:
case AECP_COMMAND_STOP_STREAMING:
case AECP_COMMAND_REBOOT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_STREAM_INFO:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_acmp_flags_class_b, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_fast_connect, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_saved_state, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_acmp_flags_streaming_wait, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_msrp_acc_lat_valid_flag, tvb,
AECP_FLAGS_32_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_accumulated_latency, tvb,
AECP_SET_MSRP_ACC_LAT_OFFSET, 4, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_GET_STREAM_INFO:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_acmp_flags_class_b, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_fast_connect, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_saved_state, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_flags_streaming_wait, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_connected_flag, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_id_valid_flag, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_acc_lat_valid_flag, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_dest_mac_valid_flag, tvb,
AECP_FLAGS28_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_format, tvb,
AECP_OFFSET_GET_STREAM_INFO_STREAM_FORMAT, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_stream_id, tvb,
AECP_OFFSET_GET_STREAM_INFO_STREAM_ID, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_msrp_accumulated_latency, tvb,
AECP_MSRP_ACC_LAT_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_acmp_stream_dest_mac, tvb,
AECP_DEST_MAC_OFFSET, 6, ENC_NA);
proto_tree_add_item(aecp_tree, hf_aem_clock_source_id, tvb,
AECP_STREAM_CLOCK_SOURCE_ID_OFFSET, 2, ENC_BIG_ENDIAN);
}
break;
case AECP_COMMAND_SET_NAME:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_name_index, tvb,
AECP_NAME_INDEX_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_name, tvb,
AECP_NAME_OFFSET, 64, ENC_ASCII|ENC_NA);
break;
case AECP_COMMAND_GET_NAME:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_name_index, tvb,
AECP_NAME_INDEX_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_name, tvb,
AECP_NAME_OFFSET, 64, ENC_ASCII|ENC_NA);
}
break;
case AECP_COMMAND_SET_ASSOCIATION_ID:
case AECP_COMMAND_GET_ASSOCIATION_ID:
proto_tree_add_item(aecp_tree, hf_aecp_association_id, tvb,
AECP_ASSOCIATION_ID_OFFSET, 8, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_AUTH_ADD_KEY:
case AECP_COMMAND_AUTH_GET_KEY:
case AECP_COMMAND_AUTH_GET_KEY_COUNT:
case AECP_COMMAND_AUTH_REVOKE_KEY:
proto_tree_add_item(aecp_tree, hf_aecp_keychain_id, tvb,
AECP_KEYCHAIN_ID_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_keytype, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEYTYPE, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_number, tvb,
AECP_KEY_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_continued_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_CONTINUED, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_part, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PART, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_length, tvb,
AECP_OFFSET_AUTH_ADD_KEY_LENGTH, 2, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_aecp_private_key_read_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_private_key_write_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_public_key_write_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_connection_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_admin_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_mem_obj_admin_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_mem_obj_settings_flag, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l4, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l3, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l2, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l1, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_guid, tvb,
AECP_OFFSET_AUTH_ADD_KEY_KEY_GUID, 8, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AUTH_ADD_KEY_LENGTH) & AECP_KEY_LENGTH_MASK;
mr_offset = AECP_OFFSET_AUTH_ADD_KEY_KEY;
proto_tree_add_item(aecp_tree, hf_aecp_key, tvb,
mr_offset, mr_counter, ENC_NA);
break;
case AECP_COMMAND_AUTHENTICATE:
case AECP_COMMAND_DEAUTHENTICATE:
proto_tree_add_item(aecp_tree, hf_aecp_token_length, tvb,
AECP_OFFSET_AUTHENTICATE_TOKEN_LENGTH, 2, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_aecp_private_key_read_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_private_key_write_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_public_key_write_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_connection_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_admin_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_mem_obj_admin_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_mem_obj_settings_flag, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l4, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l3, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l2, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_control_user_l1, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_PERMISSIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_key_guid, tvb,
AECP_OFFSET_AUTHENTICATE_KEY_GUID, 8, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AECP_OFFSET_AUTHENTICATE_TOKEN_LENGTH)
& AECP_TOKEN_LENGTH_MASK;
mr_offset = AECP_OFFSET_AUTHENTICATE_AUTH_TOKEN;
proto_tree_add_item(aecp_tree, hf_aecp_auth_token, tvb,
mr_offset, mr_counter, ENC_NA);
break;
case AECP_COMMAND_GET_COUNTERS:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
flags_ti = proto_tree_add_item(aecp_tree, hf_aecp_flags_32, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_ti, ett_acmp_flags);
proto_tree_add_item(flags_tree, hf_aecp_gptp_unlocked_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_gtpt_locked_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_media_unlocked_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_media_locked_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_stream_reset_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_srp_refused_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_backup_stream_switch_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_missed_avdecc_response_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_refused_avdecc_command_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_seq_num_mismatch_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_media_clock_toggles_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_timestamp_uncertains_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_timestamp_valids_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_unsupported_formats_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_bad_presentation_times_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_srp_latency_violations_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_packets_tx_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_packets_rx_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_packets_interest_rx_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_talker_bw_reserved_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_reserved1_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_reserved2_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific1_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific2_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific3_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific4_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific5_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific6_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific7_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_aecp_entity_specific8_valid, tvb,
AECP_OFFSET_GET_COUNTERS_VALID, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_gptp_gm_changed, tvb,
AECP_OFFSET_COUNTERS_VALID_GPTP_GM_CHANGED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_gptp_unlocked, tvb,
AECP_OFFSET_COUNTERS_VALID_GPTP_UNLOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_gptp_locked, tvb,
AECP_OFFSET_COUNTERS_VALID_GPTP_LOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_media_unlocked, tvb,
AECP_OFFSET_COUNTERS_VALID_MEDIA_UNLOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_media_locked, tvb,
AECP_OFFSET_COUNTERS_VALID_MEDIA_LOCKED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_media_seq_error, tvb,
AECP_OFFSET_COUNTERS_VALID_MEDIA_SEQ_ERROR, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_stream_reset, tvb,
AECP_OFFSET_COUNTERS_VALID_STREAM_RESET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_srp_refused, tvb,
AECP_OFFSET_COUNTERS_VALID_SRP_REFUSED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_backup_stream_switch, tvb,
AECP_OFFSET_COUNTERS_VALID_BACKUP_STREAM_SWITCH, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_missed_avdecc_response, tvb,
AECP_OFFSET_COUNTERS_VALID_MISSED_AVDECC_RESPONSE, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_refused_avdecc_command, tvb,
AECP_OFFSET_COUNTERS_VALID_REFUSED_AVDECC_COMMAND, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_seq_num_mismatch, tvb,
AECP_OFFSET_COUNTERS_VALID_SEQ_NUM_MISMATCH, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_media_clock_toggles, tvb,
AECP_OFFSET_COUNTERS_VALID_MEDIA_CLOCK_TOGGLES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_timestamp_uncertains, tvb,
AECP_OFFSET_COUNTERS_VALID_TIMESTAMP_UNCERTAINS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_timestamp_valids, tvb,
AECP_OFFSET_COUNTERS_VALID_TIMESTAMP_VALIDS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_unsupported_formats, tvb,
AECP_OFFSET_COUNTERS_VALID_UNSUPPORTED_FORMATS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_bad_presentation_times, tvb,
AECP_OFFSET_COUNTERS_VALID_BAD_PRESENTATION_TIMES, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_srp_latency_violations, tvb,
AECP_OFFSET_COUNTERS_VALID_SRP_LATENCY_VIOLATIONS, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_packets_tx, tvb,
AECP_OFFSET_COUNTERS_VALID_PACKETS_TX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_packets_rx, tvb,
AECP_OFFSET_COUNTERS_VALID_PACKETS_RX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_packets_interest_rx, tvb,
AECP_OFFSET_COUNTERS_VALID_PACKETS_OF_INTEREST_RX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_talker_bw_reserved, tvb,
AECP_OFFSET_COUNTERS_VALID_TALKER_BW_RESERVED, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_reserved_counter, tvb,
AECP_OFFSET_COUNTERS_VALID_RESERVED1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_reserved_counter, tvb,
AECP_OFFSET_COUNTERS_VALID_RESERVED2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific1, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific2, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific3, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific4, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific5, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific6, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_6, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific7, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_7, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_entity_specific8, tvb,
AECP_OFFSET_COUNTERS_VALID_ENTITY_SPECIFIC_8, 4, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_SET_MEDIA_FORMAT:
case AECP_COMMAND_GET_MEDIA_FORMAT:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_media_format, tvb,
AECP_MEDIA_FORMAT_OFFSET, 16, ENC_NA);
next_tvb = tvb_new_subset(tvb, AECP_OFFSET_SETMF_MEDIA_FMT, 16, 16);
dissect_17221_media_format(next_tvb, aecp_tree);
break;
case AECP_COMMAND_REGISTER_STATE_NOTIFICATION:
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_address_type, tvb,
AECP_ADDRESS_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
addr_type = tvb_get_ntohs(tvb, AECP_ADDRESS_TYPE_OFFSET);
if (addr_type == AECP_ADDRESS_MAC) {
proto_tree_add_item(aecp_tree, hf_aecp_mac_address, tvb,
AECP_ADDRESS_OFFSET, 6, ENC_NA);
} else if (addr_type == AECP_ADDRESS_IPV4) {
proto_tree_add_item(aecp_tree, hf_aecp_ipv4_address, tvb,
AECP_ADDRESS_OFFSET, 4, ENC_BIG_ENDIAN);
} else if (addr_type == AECP_ADDRESS_IPV6) {
proto_tree_add_item(aecp_tree, hf_aecp_ipv6_address, tvb,
AECP_ADDRESS_OFFSET, 8, ENC_NA);
}
}
break;
case AECP_COMMAND_REGISTER_QUERY_NOTIFICATION:
proto_tree_add_item(aecp_tree, hf_aecp_query_period, tvb,
AECP_QUERY_PERIOD_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_query_limit, tvb,
AECP_QUERY_LIMIT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_query_type, tvb,
AECP_QUERY_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_query_id, tvb,
AECP_QUERY_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_QUERY_DESC_T_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_QUERY_DESC_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_DEREGISTER_QUERY_NOTIFICATION:
proto_tree_add_item(aecp_tree, hf_aecp_query_id, tvb,
AECP_DEREG_QUERY_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_IDENTIFY_NOTIFICATION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_STATE_CHANGE_NOTIFICATION:
proto_tree_add_item(aecp_tree, hf_aecp_count, tvb,
AECP_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AECP_COUNT_OFFSET);
mr_offset = AECP_DESCRIPTORS_OFFSET_DQN;
mr_item = proto_tree_add_item(aecp_tree, hf_aecp_descriptors, tvb,
mr_offset, mr_counter * 4, ENC_NA);
mr_subtree = proto_item_add_subtree(mr_item, ett_aecp_descriptors);
for(i = 0; i < mr_counter; ++i) {
proto_tree_add_item(mr_subtree, hf_aecp_descriptor_type, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
proto_tree_add_item(mr_subtree, hf_aecp_descriptor_id, tvb,
mr_offset, 2, ENC_BIG_ENDIAN);
mr_offset += 2;
}
break;
case AECP_COMMAND_INCREMENT_CONTROL_VALUE:
case AECP_COMMAND_DECREMENT_CONTROL_VALUE:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_COMMAND_MESSAGE) {
proto_tree_add_item(aecp_tree, hf_aecp_values_count, tvb,
AECP_VALUES_COUNT_OFFSET, 2, ENC_BIG_ENDIAN);
mr_counter = tvb_get_ntohs(tvb, AECP_VALUES_COUNT_OFFSET);
proto_tree_add_item(aecp_tree, hf_aecp_values, tvb,
AECP_VALUES_OFFSET, mr_counter, ENC_NA);
}
break;
case AECP_COMMAND_START_OPERATION:
case AECP_COMMAND_ABORT_OPERATION:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_id, tvb,
AECP_OPERATION_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_type, tvb,
AECP_OPERATION_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_OPERATION_STATUS:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_operation_id, tvb,
AECP_OPERATION_ID_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_percent_complete, tvb,
AECP_PERCENT_COMPLETE_OFFSET, 2, ENC_BIG_ENDIAN);
break;
case AECP_COMMAND_GET_AS_PATH:
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_type, tvb,
AECP_DESCRIPTOR_TYPE_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aecp_tree, hf_aecp_descriptor_id, tvb,
AECP_DESCRIPTOR_ID_OFFSET, 2, ENC_BIG_ENDIAN);
if (mess_type == AECP_AEM_RESPONSE_MESSAGE) {
}
break;
case AECP_COMMAND_CONTROLLER_AVAILABLE:
case AECP_COMMAND_DEREGISTER_STATE_NOTIFICATION:
break;
default:
break;
}
}
static void
dissect_17221_adp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *adp_tree)
{
proto_item *ent_cap_ti;
proto_item *talk_cap_ti;
proto_item *list_cap_ti;
proto_item *cont_cap_ti;
proto_item *aud_format_ti;
proto_item *samp_rates_ti;
proto_item *chan_format_ti;
proto_tree *ent_cap_flags_tree;
proto_tree *talk_cap_flags_tree;
proto_tree *list_cap_flags_tree;
proto_tree *cont_cap_flags_tree;
proto_tree *aud_format_tree;
proto_tree *samp_rates_tree;
proto_tree *chan_format_tree;
proto_tree_add_item(adp_tree, hf_adp_message_type, tvb, ADP_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_valid_time, tvb, ADP_VALID_TIME_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_cd_length, tvb, ADP_CD_LENGTH_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_entity_guid, tvb, ADP_ENTITY_GUID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_vendor_id, tvb, ADP_VENDOR_ID_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_model_id, tvb, ADP_MODEL_ID_OFFSET, 4, ENC_BIG_ENDIAN);
ent_cap_ti = proto_tree_add_item(adp_tree, hf_adp_entity_cap, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
ent_cap_flags_tree = proto_item_add_subtree(ent_cap_ti, ett_adp_ent_cap);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_avdecc_ip, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_zero_conf, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_gateway_entity, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_avdecc_control, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_legacy_avc, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_assoc_id_support, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ent_cap_flags_tree,
hf_adp_entity_cap_assoc_id_valid, tvb, ADP_ENTITY_CAP_OFFSET, 4, ENC_BIG_ENDIAN);
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
proto_tree_add_item(adp_tree, hf_adp_as_gm_id, tvb, ADP_AS_GM_ID_OFFSET, 8, ENC_BIG_ENDIAN);
aud_format_ti = proto_tree_add_item(adp_tree, hf_adp_def_aud_format, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 4, ENC_BIG_ENDIAN);
aud_format_tree = proto_item_add_subtree(aud_format_ti, ett_adp_aud_format);
samp_rates_ti = proto_tree_add_item(aud_format_tree,
hf_adp_def_aud_sample_rates, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
samp_rates_tree = proto_item_add_subtree(samp_rates_ti, ett_adp_samp_rates);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_44k1, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_48k, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_88k2, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_96k, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_176k4, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(samp_rates_tree,
hf_adp_samp_rate_192k, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aud_format_tree,
hf_adp_def_aud_max_chan, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aud_format_tree,
hf_adp_def_aud_saf_flag, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aud_format_tree,
hf_adp_def_aud_float_flag, tvb, ADP_DEF_AUDIO_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
chan_format_ti = proto_tree_add_item(aud_format_tree,
hf_adp_def_aud_chan_formats, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
chan_format_tree = proto_item_add_subtree(chan_format_ti, ett_adp_chan_format);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_mono, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_2ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_3ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_4ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_5ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_6ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_7ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_8ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_10ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_12ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_14ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_16ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_18ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_20ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_22ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(chan_format_tree,
hf_adp_chan_format_24ch, tvb, ADP_CHAN_FORMAT_OFFSET, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_def_vid_format, tvb, ADP_DEF_VIDEO_FORMAT_OFFSET, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_assoc_id, tvb, ADP_ASSOC_ID_OFFSET, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(adp_tree, hf_adp_entity_type, tvb, ADP_ENTITY_TYPE_OFFSET, 4, ENC_BIG_ENDIAN);
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
proto_tree_add_item(acmp_tree, hf_acmp_default_format, tvb, ACMP_DEFAULT_FORMAT_OFFSET, 4, ENC_BIG_ENDIAN);
}
static void
dissect_17221(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
return;
}
}
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
{ &hf_adp_entity_guid,
{ "Entity GUID", "ieee17221.entity_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_vendor_id,
{ "Vendor ID", "ieee17221.vendor_id",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_model_id,
{ "Model ID", "ieee17221.model_id",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_cap,
{ "Entity Capabilities", "ieee17221.entity_capabilities",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_cap_avdecc_ip,
{ "AVDECC_IP", "ieee17221.entity_capabilities.avdecc_ip",
FT_BOOLEAN, 32, NULL, ADP_AVDECC_IP_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_zero_conf,
{ "ZERO_CONF", "ieee17221.entity_capabilities.zero_conf",
FT_BOOLEAN, 32, NULL, ADP_ZERO_CONF_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_gateway_entity,
{ "GATEWAY_ENTITY", "ieee17221.entity_capabilities.gateway_entity",
FT_BOOLEAN, 32, NULL, ADP_GATEWAY_ENTITY_BITMASK, NULL, HFILL }
},
{ &hf_adp_entity_cap_avdecc_control,
{ "AVDECC_CONTROL", "ieee17221.entity_capabilities.avdecc_control",
FT_BOOLEAN, 32, NULL, ADP_AVDECC_CONTROL_BITMASK, NULL, HFILL }
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
{ &hf_adp_as_gm_id,
{ "AS Grandmaster ID", "ieee17221.as_grandmaster_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_def_aud_format,
{ "Default Audio Format", "ieee17221.default_audio_format",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
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
{ &hf_adp_def_vid_format,
{ "Default Video Format", "ieee17221.default_video_format",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_assoc_id,
{ "Assocation ID", "ieee17221.assocation_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_adp_entity_type,
{ "Entity Type", "ieee17221.entity_type",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
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
{ &hf_acmp_default_format,
{ "Default Format", "ieee17221.default_format",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL }
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
{ &hf_aecp_descriptor_type,
{ "Descriptor Type", "ieee17221.descriptor_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aecp_descriptor_id,
{"Descriptor ID", "ieee17221._descriptor_id",
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
{ "Configuration", "ieee17221._configuration",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_persistent_flag,
{ "Peristent Flag", "ieee17221.flags.persistent",
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
{ "Clock Source ID", "ieee17221.clock_source_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_stream_format,
{"Stream Format", "ieee17221.stream_format",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_signal_type,
{"Signal Type", "ieee17221.signal_type",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_signal_id,
{"Signal ID", "ieee17221.signal_id",
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
{ &hf_aecp_matrix_affected_item_count,
{"Affected Item Count", "ieee17221.matrix_affected_item_count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_msrp_accumulated_latency,
{"MSRP Accumulated Latency", "ieee17221.msrp_accumulated_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_connected_flag,
{"Connected Flag", "ieee17221.flags.connected",
FT_BOOLEAN, 32, NULL, AECP_CONNECTED_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_stream_id_valid_flag,
{"Stream ID Valid Flag", "ieee17221.flags.stream_id_valid",
FT_BOOLEAN, 32, NULL, AECP_STREAM_ID_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_msrp_acc_lat_valid_flag,
{"MSRP Accumulated Latency Field Valid Flag", "ieee17221.flags.msrp_acc_lat_valid",
FT_BOOLEAN, 32, NULL, AECP_MSRP_ACC_LAT_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_dest_mac_valid_flag,
{"Dest MAC Valid Flag", "ieee17221.flags.dest_mac_valid",
FT_BOOLEAN, 32, NULL, AECP_DEST_MAC_VALID_FLAG_MASK, NULL, HFILL }
},
{ &hf_aecp_name_index,
{"Name Index", "ieee17221.name_index",
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
{ &hf_aecp_keychain_id,
{"Keychain ID", "ieee17221.keychain_id",
FT_UINT8, BASE_HEX, VALS(aecp_keychain_id_type_vals), AECP_KEYCHAIN_ID_MASK, NULL, HFILL }
},
{ &hf_aecp_keytype,
{"Key Type", "ieee17221.keytype",
FT_UINT8, BASE_HEX, VALS(aecp_keytype_type_vals), AECP_KEYTYPE_MASK, NULL, HFILL }
},
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
{ &hf_aecp_key_length,
{"Key Length", "ieee17221.key_length",
FT_UINT16, BASE_DEC, NULL, AECP_KEY_LENGTH_MASK, NULL, HFILL }
},
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
{ &hf_aecp_connection_flag,
{"Connection Flag", "ieee17221.flags.connection",
FT_BOOLEAN, 32, NULL, AECP_CONNECTION_FLAG_MASK, NULL, HFILL }
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
{ &hf_aecp_gptp_gm_changed,
{"GPTP GM Changed", "ieee17221.gtptp_gm_changed",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_gptp_unlocked,
{"GPTP Unlocked", "ieee17221.gptp_unlocked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_gptp_locked,
{"GPTP Locked", "ieee17221.gptp_locked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_media_unlocked,
{"Media Unlocked", "ieee17221.media_unlocked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_media_locked,
{"Media Locked", "ieee17221.media_locked",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_media_seq_error,
{"Media Seq Error", "ieee17221.media_seq_error",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_stream_reset,
{"stream_reset", "ieee17221.stream_reset",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_srp_refused,
{"SRP Refused", "ieee17221.srp_refused",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_backup_stream_switch,
{"Backup Stream Switch", "ieee17221.backup_stream_switch",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_missed_avdecc_response,
{"Missed Avdecc Response", "ieee17221.missed_avdecc_response",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_refused_avdecc_command,
{"Refused Avdecc Command", "ieee17221.refused_avdecc_command",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_seq_num_mismatch,
{"Seq Num Mismatch", "ieee17221.seq_num_mismatch",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_media_clock_toggles,
{"Media Clock Toggles", "ieee17221.media_clock_toggles",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_timestamp_uncertains,
{"Timestamp Uncertains", "ieee17221.timestamp_uncertains",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_timestamp_valids,
{"Timestamp Valids", "ieee17221.timestamp_valids",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_unsupported_formats,
{"Unsupported Formats", "ieee17221.unsupported_formats",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_bad_presentation_times,
{"Bad Presentation Times", "ieee17221.bad_presentation_times",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_srp_latency_violations,
{"SRP Latency Violations", "ieee17221.srp_latency_violations",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_packets_tx,
{"Packets TX", "ieee17221.packets_tx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_packets_rx,
{"Packets RX", "ieee17221.packets_rx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_packets_interest_rx,
{"Packets of Interest RX", "ieee17221.packets_interest_rx",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_talker_bw_reserved,
{"Talker BW Reserved", "ieee17221.talker_bw_reserved",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_reserved_counter,
{"RESERVED", "ieee17221.reserved",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific1,
{"Entity Specific #1", "ieee17221.entity_specific_1",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific2,
{"Entity Specific #2", "ieee17221.entity_specific_2",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific3,
{"Entity Specific #3", "ieee17221.entity_specific_3",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific4,
{"Entity Specific #4", "ieee17221.entity_specific_4",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific5,
{"Entity Specific #5", "ieee17221.entity_specific_5",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific6,
{"Entity Specific #6", "ieee17221.entity_specific_6",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific7,
{"Entity Specific #7", "ieee17221.entity_specific_7",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_entity_specific8,
{"Entity Specific #8", "ieee17221.entity_specific_8",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{ &hf_aecp_key_guid,
{"Key GUID", "ieee17221.key_guid",
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
{ &hf_aecp_gptp_unlocked_valid,
{"GPTP Unlocked Valid", "ieee17221.flags.gptp_unlocked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_GPTP_UNLOCKED, NULL, HFILL }
},
{ &hf_aecp_gtpt_locked_valid,
{"GPTP Locked Valid", "ieee17221.flags.gptp_locked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_GPTP_LOCKED, NULL, HFILL }
},
{ &hf_aecp_media_unlocked_valid,
{"Media Unlocked Valid", "ieee17221.flags.media_unlocked_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_UNLOCKED, NULL, HFILL }
},
{ &hf_aecp_media_locked_valid,
{"Media Locked Valid", "ieee17221.flags._valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_LOCKED, NULL, HFILL }
},
{ &hf_aecp_stream_reset_valid,
{"Stream Reset Valid", "ieee17221.flags.stream_reset_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_STREAM_RESET, NULL, HFILL }
},
{ &hf_aecp_srp_refused_valid,
{"SRP Refused Valid", "ieee17221.flags.srt_refused_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_SRP_REFUSED, NULL, HFILL }
},
{ &hf_aecp_backup_stream_switch_valid,
{"Backup Stream Switch Valid", "ieee17221.flags.backup_stream_switch_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_BACKUP_STREAM_SWITCH, NULL, HFILL }
},
{ &hf_aecp_missed_avdecc_response_valid,
{"Missed Avdecc Response Valid", "ieee17221.flags.missed_avdecc_response_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MISSED_AVDECC_RESPONSE, NULL, HFILL }
},
{ &hf_aecp_refused_avdecc_command_valid,
{"Refused Avdecc Command Valid", "ieee17221.flags.refused_avdecc_command_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_REFUSED_AVDECC_COMMAND, NULL, HFILL }
},
{ &hf_aecp_seq_num_mismatch_valid,
{"Seq Num Mismatch Valid", "ieee17221.flags.seq_num_mismatch_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_SEQ_NUM_MISMATCH, NULL, HFILL }
},
{ &hf_aecp_media_clock_toggles_valid,
{"Media Clock Toggles Valid", "ieee17221.flags.media_clock_toggles_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_MEDIA_CLOCK_TOGGLES, NULL, HFILL }
},
{ &hf_aecp_timestamp_uncertains_valid,
{"Timestamp Uncertains Valid", "ieee17221.flags.timestamp_uncertains_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TIMESTAMP_UNCERTAINS, NULL, HFILL }
},
{ &hf_aecp_timestamp_valids_valid,
{"Timestamp Valids Valid", "ieee17221.flags.timestamp_valids_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TIMESTAMP_VALIDS, NULL, HFILL }
},
{ &hf_aecp_unsupported_formats_valid,
{"Unsupported Formats Valid", "ieee17221.flags.unsupported_formats_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_UNSUPPORTED_FORMATS, NULL, HFILL }
},
{ &hf_aecp_bad_presentation_times_valid,
{"Bad Presentation Times Valid", "ieee17221.flags.bad_presentation_times_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_BAD_PRESENTATION_TIMES, NULL, HFILL }
},
{ &hf_aecp_srp_latency_violations_valid,
{"SRP Latency Violations Valid", "ieee17221.flags.srp_latency_violations_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_SRP_LATENCY_VIOLATIONS, NULL, HFILL }
},
{ &hf_aecp_packets_tx_valid,
{"Packets TX Valid", "ieee17221.flags.packets_tx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_PACKETS_TX, NULL, HFILL }
},
{ &hf_aecp_packets_rx_valid,
{"Packets RX Valid", "ieee17221.flags.packets_rx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_PACKETS_RX, NULL, HFILL }
},
{ &hf_aecp_packets_interest_rx_valid,
{"Packets of Interest RX Valid", "ieee17221.flags.packets_interest_rx_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_PACKETS_OF_INTEREST_RX, NULL, HFILL }
},
{ &hf_aecp_talker_bw_reserved_valid,
{"Talker BW Reserved Valid", "ieee17221.flags.talker_bw_reserved_valid",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_TALKER_BW_RESERVED, NULL, HFILL }
},
{ &hf_aecp_reserved1_valid,
{"RESERVED", "ieee17221.flags.reserved",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_RESERVED1, NULL, HFILL }
},
{ &hf_aecp_reserved2_valid,
{"RESERVED", "ieee17221.flags.reserved",
FT_BOOLEAN, 32, NULL, AECP_COUNTERS_VALID_RESERVED2, NULL, HFILL }
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
{ &hf_aecp_media_format,
{"Media Format", "ieee17221.media_format",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_address_type,
{"Address Type", "ieee17221.address_type",
FT_UINT16, BASE_HEX, VALS(aecp_address_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aecp_mac_address,
{ "MAC address", "ieee17221.mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_ipv4_address,
{"IPV4 Address", "ieee17221.ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_ipv6_address,
{"IPv6 Address", "ieee17221.ipv6_address",
FT_IPv6, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
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
{ &hf_aem_entity_guid,
{"Entity GUID", "ieee17221.entity_guid",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_vendor_id,
{"Vendor ID", "ieee17221.vendor_id",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_entity_model_id,
{"Entity Model ID", "ieee17221.entity_model_id",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
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
{"Configuration Name", "ieee17221.configuration_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_configuration_name_string,
{"Configuration Name String", "ieee17221.configuration_name_string",
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
{ &hf_aem_number_of_controls,
{"Number Of Controls", "ieee17221.number_of_controls",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_control,
{"Base Control", "ieee17221.base_control",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_unit_name,
{"Unit Name", "ieee17221.unit_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_unit_name_string,
{"Unit Name String", "ieee17221.unit_name_string",
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
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_mixers,
{"Number of Mixers", "ieee17221.num_mixers",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_mixer,
{"Base Mixer", "ieee17221.base_mixer",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_matrices,
{"Number of Matrices", "ieee17221.num_matrices",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_base_matrix,
{"Base Matrix", "ieee17221.base_matrix",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
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
{"Stream Name", "ieee17221.stream_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_stream_name_string,
{"Stream Name String", "ieee17221.stream_name_string",
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
{ &hf_aem_stream_channels,
{"Stream Channels", "ieee17221.stream_channels",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
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
{ &hf_aem_stream_formats,
{"Stream Formats Array", "ieee17221.stream_formats",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_name,
{"Jack Name", "ieee17221.jack_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_name_string,
{"Jack Name String", "ieee17221.jack_name_string",
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
{ &hf_aem_audio_channels,
{"Audio Channels", "ieee17221.audio_channels",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
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
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_number_audio_maps,
{"Number of Audio Maps", "ieee17221.num_audio_maps",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ & hf_aem_stream_id,
{"Stream Descriptor ID", "ieee17221.stream_descriptor_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_formats_count,
{"Formats Count", "ieee17221.formats_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_jack_id,
{"Jack ID", "ieee17221.jack_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_internal_id,
{"Internal ID", "ieee17221.internal_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_mappings_offset,
{"MSRP Mappings Offset", "ieee17221.msrp_mappings_offset",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_mappings_count,
{"MSRP Mappings Count", "ieee17221.msrp_mappings_count",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_mappings,
{"MSRP Mappings", "ieee17221.msrp_mappings",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_mapping_traffic_class,
{"MSRP Mapping Traffic Class", "ieee17221.msrp_mapping_traffic_class",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_mapping_priority,
{"MSRP Mapping Priority", "ieee17221.msrp_mapping_priority",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_msrp_vlan_id,
{"MSRP VLAN ID", "ieee17221.msrp_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_name,
{"Clock Source Name", "ieee17221.clock_source_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_clock_source_name_string,
{"Clock Source Name String", "ieee17221.clock_source_name_string",
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
{ &hf_aem_mapping_audio_channel,
{"Mapping Audio Channel", "ieee17221.mapping_audio_channel",
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
{ &hf_aem_cluster_name,
{"Cluster Name", "ieee17221.cluster_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_cluster_name_string,
{"Cluster Name String", "ieee17221.cluster_name_string",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_type,
{"Control Type", "ieee17221.control_type",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_location_type,
{"Control Location Type", "ieee17221.control_location_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_control_location_id,
{"Control Location ID", "ieee17221.control_location_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_value_type,
{"Control Value Type", "ieee17221.control_value_type",
FT_UINT16, BASE_HEX, VALS(aem_control_value_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_control_domain,
{"Control Domain", "ieee17221.control_domain",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_name,
{"Control Name", "ieee17221.control_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_control_name_string,
{"Control Name String", "ieee17221.control_name_string",
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
{ &hf_aem_block_latency,
{"Block Latency", "ieee17221.block_latency",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_signal_type,
{"Signal Type", "ieee17221.signal_type",
FT_UINT16, BASE_HEX, VALS(aem_descriptor_type_vals), 0x00, NULL, HFILL }
},
{ &hf_aem_signal_id,
{"Signal ID", "ieee17221.signal_id",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
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
{ &hf_aem_object_name,
{"Object Name", "ieee17221.object_name",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_object_name_string,
{"Object Name String", "ieee17221.object_name_string",
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
{ &hf_aem_stream_format,
{"Stream Format", "ieee17221.stream_format",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aem_sf_version,
{"Version", "ieee17221.sf_version",
FT_UINT8, BASE_HEX, NULL, AEM_MASK_SF_VERSION, NULL, HFILL }
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
{"Color Space", "ieee17221.color_sapce",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_values,
{"Values", "ieee17221.values",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_aecp_status_code,
{"Status", "ieee17221.status",
FT_UINT8, BASE_HEX, VALS(aem_status_type_vals), AECP_STATUS_CODE_MASK, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_17221,
&ett_adp_ent_cap,
&ett_adp_talk_cap,
&ett_adp_list_cap,
&ett_adp_cont_cap,
&ett_adp_aud_format,
&ett_adp_samp_rates,
&ett_adp_chan_format,
&ett_acmp_flags,
&ett_aem_desc_counts,
&ett_aem_descriptor,
&ett_aem_sample_rates,
&ett_aem_stream_flags,
&ett_aem_stream_formats,
&ett_aem_jack_flags,
&ett_aem_port_flags,
&ett_aem_msrp_mappings,
&ett_aem_clock_source_flags,
&ett_aem_mappings,
&ett_aem_ctrl_vals,
&ett_aem_sources,
&ett_aem_media_format,
&ett_aecp_descriptors,
&ett_aecp_flags_32,
&ett_aem_stream_format
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
