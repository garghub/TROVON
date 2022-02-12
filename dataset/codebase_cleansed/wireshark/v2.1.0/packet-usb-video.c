static int
dissect_bmControl(proto_tree *tree, tvbuff_t *tvb, int offset,
gint ett_subtree, const int** bm_items)
{
guint8 bm_size = 0;
bm_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_bControlSize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (bm_size > 0)
{
proto_tree_add_bitmask_len(tree, tvb, offset, bm_size, hf_usb_vid_bmControl,
ett_subtree, bm_items, &ei_usb_vid_bitmask_len, ENC_LITTLE_ENDIAN);
offset += bm_size;
}
return offset;
}
static int
dissect_usb_video_camera_terminal(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *control_bits[] = {
&hf_usb_vid_cam_control_D[0],
&hf_usb_vid_cam_control_D[1],
&hf_usb_vid_cam_control_D[2],
&hf_usb_vid_cam_control_D[3],
&hf_usb_vid_cam_control_D[4],
&hf_usb_vid_cam_control_D[5],
&hf_usb_vid_cam_control_D[6],
&hf_usb_vid_cam_control_D[7],
&hf_usb_vid_cam_control_D[8],
&hf_usb_vid_cam_control_D[9],
&hf_usb_vid_cam_control_D[10],
&hf_usb_vid_cam_control_D[11],
&hf_usb_vid_cam_control_D[12],
&hf_usb_vid_cam_control_D[13],
&hf_usb_vid_cam_control_D[14],
&hf_usb_vid_cam_control_D[15],
&hf_usb_vid_cam_control_D[16],
&hf_usb_vid_cam_control_D[17],
&hf_usb_vid_cam_control_D[18],
&hf_usb_vid_cam_control_D[19],
&hf_usb_vid_cam_control_D[20],
&hf_usb_vid_cam_control_D[21],
NULL
};
DISSECTOR_ASSERT(array_length(control_bits) == (1+array_length(hf_usb_vid_cam_control_D)));
proto_tree_add_item(tree, hf_usb_vid_cam_objective_focal_len_min, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_vid_cam_objective_focal_len_max, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_vid_cam_ocular_focal_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = dissect_bmControl(tree, tvb, offset, ett_camera_controls, control_bits);
return offset;
}
static int
dissect_usb_video_processing_unit(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *control_bits[] = {
&hf_usb_vid_proc_control_D[0],
&hf_usb_vid_proc_control_D[1],
&hf_usb_vid_proc_control_D[2],
&hf_usb_vid_proc_control_D[3],
&hf_usb_vid_proc_control_D[4],
&hf_usb_vid_proc_control_D[5],
&hf_usb_vid_proc_control_D[6],
&hf_usb_vid_proc_control_D[7],
&hf_usb_vid_proc_control_D[8],
&hf_usb_vid_proc_control_D[9],
&hf_usb_vid_proc_control_D[10],
&hf_usb_vid_proc_control_D[11],
&hf_usb_vid_proc_control_D[12],
&hf_usb_vid_proc_control_D[13],
&hf_usb_vid_proc_control_D[14],
&hf_usb_vid_proc_control_D[15],
&hf_usb_vid_proc_control_D[16],
&hf_usb_vid_proc_control_D[17],
&hf_usb_vid_proc_control_D[18],
NULL
};
DISSECTOR_ASSERT(array_length(control_bits) == (1+array_length(hf_usb_vid_proc_control_D)));
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_src_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_max_multiplier, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
offset += 3;
offset = dissect_bmControl(tree, tvb, offset, ett_processing_controls, control_bits);
proto_tree_add_item(tree, hf_usb_vid_iProcessing, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
static const int *standard_bits[] = {
&hf_usb_vid_proc_standards_D[0],
&hf_usb_vid_proc_standards_D[1],
&hf_usb_vid_proc_standards_D[2],
&hf_usb_vid_proc_standards_D[3],
&hf_usb_vid_proc_standards_D[4],
&hf_usb_vid_proc_standards_D[5],
NULL
};
DISSECTOR_ASSERT(array_length(standard_bits) == (1+array_length(hf_usb_vid_proc_standards_D)));
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_proc_standards,
ett_video_standards, standard_bits, ENC_NA);
++offset;
}
return offset;
}
static int
dissect_usb_video_selector_unit(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 num_inputs;
num_inputs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_num_inputs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (num_inputs > 0)
{
proto_tree_add_item(tree, hf_usb_vid_sources, tvb, offset, num_inputs, ENC_NA);
offset += num_inputs;
}
proto_tree_add_item(tree, hf_usb_vid_iSelector, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
return offset;
}
static int
dissect_usb_video_extension_unit(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 num_inputs;
guint8 control_size;
proto_tree_add_item(tree, hf_usb_vid_exten_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_exten_num_controls, tvb, offset+16, 1, ENC_LITTLE_ENDIAN);
offset += 17;
num_inputs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_num_inputs, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (num_inputs > 0)
{
proto_tree_add_item(tree, hf_usb_vid_sources, tvb, offset, num_inputs, ENC_NA);
offset += num_inputs;
}
control_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_bControlSize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (control_size > 0)
{
if (control_size <= proto_registrar_get_length(hf_usb_vid_bmControl))
{
proto_tree_add_item(tree, hf_usb_vid_bmControl, tvb, offset, control_size,
ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_bytes_format(tree, hf_usb_vid_bmControl_bytes, tvb, offset, control_size, NULL, "bmControl");
}
offset += control_size;
}
proto_tree_add_item(tree, hf_usb_vid_iExtension, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
return offset;
}
static int
dissect_usb_video_control_interface_descriptor(proto_tree *parent_tree, tvbuff_t *tvb,
guint8 descriptor_len, packet_info *pinfo, usb_conv_info_t *usb_conv_info)
{
video_conv_info_t *video_conv_info = NULL;
video_entity_t *entity = NULL;
proto_item *item = NULL;
proto_item *subtype_item = NULL;
proto_tree *tree = NULL;
guint8 entity_id = 0;
guint16 terminal_type = 0;
int offset = 0;
guint8 subtype;
subtype = tvb_get_guint8(tvb, offset+2);
if (parent_tree)
{
const gchar *subtype_str;
subtype_str = val_to_str_ext(subtype, &vc_if_descriptor_subtypes_ext, "Unknown (0x%x)");
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, descriptor_len,
ett_descriptor_video_control, &item, "VIDEO CONTROL INTERFACE DESCRIPTOR [%s]",
subtype_str);
}
dissect_usb_descriptor_header(tree, tvb, offset, &vid_descriptor_type_vals_ext);
subtype_item = proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_subtype, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
if (subtype == VC_HEADER)
{
guint8 num_vs_interfaces;
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_bcdUVC, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_ifdesc_wTotalLength, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_dwClockFrequency, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
num_vs_interfaces = tvb_get_guint8(tvb, offset+8);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_bInCollection, tvb, offset+8, 1, ENC_LITTLE_ENDIAN);
if (num_vs_interfaces > 0)
{
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_baInterfaceNr, tvb, offset+9, num_vs_interfaces, ENC_NA);
}
offset += 9 + num_vs_interfaces;
}
else if ((subtype == VC_INPUT_TERMINAL) || (subtype == VC_OUTPUT_TERMINAL))
{
entity_id = tvb_get_guint8(tvb, offset);
terminal_type = tvb_get_letohs(tvb, offset+1);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_terminal_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_terminal_type, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_assoc_terminal, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
offset += 4;
if (subtype == VC_OUTPUT_TERMINAL)
{
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_src_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
}
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_iTerminal, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (subtype == VC_INPUT_TERMINAL)
{
if (terminal_type == ITT_CAMERA)
{
offset = dissect_usb_video_camera_terminal(tree, tvb, offset);
}
else if (terminal_type == ITT_MEDIA_TRANSPORT_INPUT)
{
}
}
if (subtype == VC_OUTPUT_TERMINAL)
{
if (terminal_type == OTT_MEDIA_TRANSPORT_OUTPUT)
{
}
}
}
else
{
entity_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_control_ifdesc_unit_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (subtype == VC_PROCESSING_UNIT)
{
offset = dissect_usb_video_processing_unit(tree, tvb, offset);
}
else if (subtype == VC_SELECTOR_UNIT)
{
offset = dissect_usb_video_selector_unit(tree, tvb, offset);
}
else if (subtype == VC_EXTENSION_UNIT)
{
offset = dissect_usb_video_extension_unit(tree, tvb, offset);
}
else if (subtype == VC_ENCODING_UNIT)
{
}
else
{
expert_add_info_format(pinfo, subtype_item, &ei_usb_vid_subtype_unknown,
"Unknown VC subtype %u", subtype);
}
}
if (offset < descriptor_len)
{
proto_tree_add_item(tree, hf_usb_vid_descriptor_data, tvb, offset, descriptor_len-offset, ENC_NA);
}
if (entity_id != 0)
proto_item_append_text(item, " (Entity %d)", entity_id);
if (subtype != VC_HEADER && usb_conv_info)
{
usb_conv_info = get_usb_iface_conv_info(pinfo, usb_conv_info->interfaceNum);
video_conv_info = (video_conv_info_t *)usb_conv_info->class_data;
if (!video_conv_info)
{
video_conv_info = wmem_new(wmem_file_scope(), video_conv_info_t);
video_conv_info->entities = wmem_tree_new(wmem_file_scope());
usb_conv_info->class_data = video_conv_info;
usb_conv_info->class_data_type = USB_CONV_VIDEO;
} else if (usb_conv_info->class_data_type != USB_CONV_VIDEO) {
return descriptor_len;
}
entity = (video_entity_t*) wmem_tree_lookup32(video_conv_info->entities, entity_id);
if (!entity)
{
entity = wmem_new(wmem_file_scope(), video_entity_t);
entity->entityID = entity_id;
entity->subtype = subtype;
entity->terminalType = terminal_type;
wmem_tree_insert32(video_conv_info->entities, entity_id, entity);
}
}
return descriptor_len;
}
static int
dissect_usb_video_streaming_input_header(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 num_formats;
guint8 bm_size;
static const int *info_bits[] = {
&hf_usb_vid_streaming_info_D[0],
NULL
};
static const int *control_bits[] = {
&hf_usb_vid_streaming_control_D[0],
&hf_usb_vid_streaming_control_D[1],
&hf_usb_vid_streaming_control_D[2],
&hf_usb_vid_streaming_control_D[3],
&hf_usb_vid_streaming_control_D[4],
&hf_usb_vid_streaming_control_D[5],
NULL
};
DISSECTOR_ASSERT(array_length(control_bits) == (1+array_length(hf_usb_vid_streaming_control_D)));
num_formats = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_streaming_ifdesc_bNumFormats, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_ifdesc_wTotalLength, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
offset += 3;
dissect_usb_endpoint_address(tree, tvb, offset);
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_streaming_bmInfo,
ett_streaming_info, info_bits, ENC_NA);
proto_tree_add_item(tree, hf_usb_vid_streaming_terminal_link, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_streaming_still_capture_method, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_usb_vid_streaming_trigger_support, tvb, offset, 1, ENC_NA);
if (tvb_get_guint8(tvb, offset) > 0)
{
proto_tree_add_item(tree, hf_usb_vid_streaming_trigger_usage, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_uint_format_value(tree, hf_usb_vid_streaming_trigger_usage, tvb, offset+1, 1, 0, "Not applicable");
}
offset += 2;
bm_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_bControlSize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if (bm_size > 0)
{
guint8 i;
for (i=0; i<num_formats; ++i)
{
proto_tree_add_bitmask_len(tree, tvb, offset, bm_size, hf_usb_vid_bmControl,
ett_streaming_controls, control_bits, &ei_usb_vid_bitmask_len,
ENC_LITTLE_ENDIAN);
offset += bm_size;
}
}
return offset;
}
static int
dissect_usb_video_format(proto_tree *tree, tvbuff_t *tvb, int offset,
guint8 subtype)
{
static const int *interlace_bits[] = {
&hf_usb_vid_is_interlaced,
&hf_usb_vid_interlaced_fields,
&hf_usb_vid_field_1_first,
&hf_usb_vid_field_pattern,
NULL
};
proto_item *desc_item;
guint8 format_index;
format_index = tvb_get_guint8(tvb, offset);
desc_item = proto_tree_get_parent(tree);
proto_item_append_text(desc_item, " (Format %u)", format_index);
proto_tree_add_item(tree, hf_usb_vid_format_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_format_num_frame_descriptors, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
if ((subtype == VS_FORMAT_UNCOMPRESSED) || (subtype == VS_FORMAT_FRAME_BASED))
{
char fourcc[5];
tvb_memcpy(tvb, (guint8 *)fourcc, offset, 4);
fourcc[4] = '\0';
proto_item_append_text(desc_item, ": %s", fourcc);
proto_tree_add_item(tree, hf_usb_vid_format_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_format_bits_per_pixel, tvb, offset+16, 1, ENC_LITTLE_ENDIAN);
offset += 17;
}
else if (subtype == VS_FORMAT_MJPEG)
{
static const int * flags[] = {
&hf_usb_vid_mjpeg_fixed_samples,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_mjpeg_flags, ett_mjpeg_flags, flags, ENC_NA);
offset++;
}
else
{
DISSECTOR_ASSERT_NOT_REACHED();
}
proto_tree_add_item(tree, hf_usb_vid_default_frame_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_aspect_ratio_x, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_aspect_ratio_y, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
#if 0
if (something)
proto_tree_add_uint_format_value(tree, hf_usb_vid_interlace_flags, tvb, offset, 1, tvb_get_guint8(tvb, offset), "Not applicable");
#endif
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_interlace_flags,
ett_interlace_flags, interlace_bits, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_usb_vid_copy_protect, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (subtype == VS_FORMAT_FRAME_BASED)
{
proto_tree_add_item(tree, hf_usb_vid_variable_size, tvb, offset, 1, ENC_NA);
offset++;
}
return offset;
}
static int
dissect_usb_video_frame(proto_tree *tree, tvbuff_t *tvb, int offset,
guint8 subtype)
{
static const int *capability_bits[] = {
&hf_usb_vid_frame_stills_supported,
&hf_usb_vid_frame_fixed_frame_rate,
NULL
};
proto_item *desc_item;
guint8 bFrameIntervalType;
guint8 frame_index;
guint16 frame_width;
guint16 frame_height;
frame_index = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_frame_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_frame_capabilities,
ett_frame_capability_flags, capability_bits, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_usb_vid_frame_width, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_height, tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
frame_width = tvb_get_letohs(tvb, offset);
frame_height = tvb_get_letohs(tvb, offset+2);
desc_item = proto_tree_get_parent(tree);
proto_item_append_text(desc_item, " (Index %2u): %4u x %4u", frame_index, frame_width, frame_height);
proto_tree_add_item(tree, hf_usb_vid_frame_min_bit_rate, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_max_bit_rate, tvb, offset+8, 4, ENC_LITTLE_ENDIAN);
offset += 12;
if (subtype != VS_FRAME_FRAME_BASED)
{
proto_tree_add_item(tree, hf_usb_vid_frame_max_frame_sz, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_usb_vid_frame_default_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
bFrameIntervalType = tvb_get_guint8(tvb, offset);
if (bFrameIntervalType == 0)
{
proto_tree_add_uint_format_value(tree, hf_usb_vid_frame_interval_type, tvb, offset, 1,
bFrameIntervalType, "Continuous (0)");
offset++;
if (subtype == VS_FRAME_FRAME_BASED)
{
proto_tree_add_item(tree, hf_usb_vid_frame_bytes_per_line, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_usb_vid_frame_min_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_max_interval, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_step_interval, tvb, offset+8, 4, ENC_LITTLE_ENDIAN);
offset += 12;
}
else
{
guint8 i;
proto_tree_add_uint_format_value(tree, hf_usb_vid_frame_interval_type, tvb, offset, 1,
bFrameIntervalType, "Discrete (%u choice%s)",
bFrameIntervalType, (bFrameIntervalType > 1) ? "s" : "");
offset++;
if (subtype == VS_FRAME_FRAME_BASED)
{
proto_tree_add_item(tree, hf_usb_vid_frame_bytes_per_line, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
for (i=0; i<bFrameIntervalType; ++i)
{
proto_tree_add_item(tree, hf_usb_vid_frame_interval, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
return offset;
}
static int
dissect_usb_video_colorformat(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_usb_vid_color_primaries, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_transfer_characteristics, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_matrix_coefficients, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset +=3;
return offset;
}
static int
dissect_usb_video_streaming_interface_descriptor(proto_tree *parent_tree, tvbuff_t *tvb,
guint8 descriptor_len)
{
proto_tree *tree;
int offset = 0;
const gchar *subtype_str;
guint8 subtype;
subtype = tvb_get_guint8(tvb, offset+2);
subtype_str = val_to_str_ext(subtype, &vs_if_descriptor_subtypes_ext, "Unknown (0x%x)");
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, descriptor_len,
ett_descriptor_video_streaming, NULL, "VIDEO STREAMING INTERFACE DESCRIPTOR [%s]",
subtype_str);
dissect_usb_descriptor_header(tree, tvb, offset, &vid_descriptor_type_vals_ext);
proto_tree_add_item(tree, hf_usb_vid_streaming_ifdesc_subtype, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
switch (subtype)
{
case VS_INPUT_HEADER:
offset = dissect_usb_video_streaming_input_header(tree, tvb, offset);
break;
case VS_FORMAT_UNCOMPRESSED:
case VS_FORMAT_MJPEG:
case VS_FORMAT_FRAME_BASED:
offset = dissect_usb_video_format(tree, tvb, offset, subtype);
break;
case VS_FRAME_UNCOMPRESSED:
case VS_FRAME_MJPEG:
case VS_FRAME_FRAME_BASED:
offset = dissect_usb_video_frame(tree, tvb, offset, subtype);
break;
case VS_COLORFORMAT:
offset = dissect_usb_video_colorformat(tree, tvb, offset);
break;
default:
break;
}
if (offset < descriptor_len)
proto_tree_add_item(tree, hf_usb_vid_descriptor_data, tvb, offset, descriptor_len-offset, ENC_NA);
return descriptor_len;
}
static int
dissect_usb_video_endpoint_descriptor(proto_tree *parent_tree, tvbuff_t *tvb,
guint8 descriptor_len)
{
proto_tree *tree = NULL;
int offset = 0;
guint8 subtype;
subtype = tvb_get_guint8(tvb, offset+2);
if (parent_tree)
{
const gchar* subtype_str;
subtype_str = val_to_str(subtype, vc_ep_descriptor_subtypes, "Unknown (0x%x)");
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, descriptor_len,
ett_descriptor_video_endpoint, NULL, "VIDEO CONTROL ENDPOINT DESCRIPTOR [%s]",
subtype_str);
}
dissect_usb_descriptor_header(tree, tvb, offset, &vid_descriptor_type_vals_ext);
proto_tree_add_item(tree, hf_usb_vid_epdesc_subtype, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
if (subtype == EP_INTERRUPT)
{
proto_tree_add_item(tree, hf_usb_vid_epdesc_max_transfer_sz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (offset < descriptor_len)
proto_tree_add_item(tree, hf_usb_vid_descriptor_data, tvb, offset, descriptor_len-offset, ENC_NA);
return descriptor_len;
}
static int
dissect_usb_vid_descriptor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
int offset = 0;
guint8 descriptor_len;
guint8 descriptor_type;
gint bytes_available;
usb_conv_info_t *usb_conv_info = (usb_conv_info_t *)data;
tvbuff_t *desc_tvb;
descriptor_len = tvb_get_guint8(tvb, offset);
descriptor_type = tvb_get_guint8(tvb, offset+1);
bytes_available = tvb_captured_length_remaining(tvb, offset);
desc_tvb = tvb_new_subset(tvb, 0, bytes_available, descriptor_len);
if (descriptor_type == CS_ENDPOINT)
{
offset = dissect_usb_video_endpoint_descriptor(tree, desc_tvb,
descriptor_len);
}
else if (descriptor_type == CS_INTERFACE)
{
if (usb_conv_info && usb_conv_info->interfaceSubclass == SC_VIDEOCONTROL)
{
offset = dissect_usb_video_control_interface_descriptor(tree, desc_tvb,
descriptor_len,
pinfo, usb_conv_info);
}
else if (usb_conv_info && usb_conv_info->interfaceSubclass == SC_VIDEOSTREAMING)
{
offset = dissect_usb_video_streaming_interface_descriptor(tree, desc_tvb,
descriptor_len);
}
}
return offset;
}
static int
dissect_usb_vid_probe(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_tree *tree;
static const int *hint_bits[] = {
&hf_usb_vid_probe_hint_D[0],
&hf_usb_vid_probe_hint_D[1],
&hf_usb_vid_probe_hint_D[2],
&hf_usb_vid_probe_hint_D[3],
&hf_usb_vid_probe_hint_D[4],
NULL
};
DISSECTOR_ASSERT(array_length(hint_bits) == (1+array_length(hf_usb_vid_probe_hint_D)));
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_video_probe, NULL, "Probe/Commit Info");
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_probe_hint,
ett_probe_hint, hint_bits, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_format_index, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_index, tvb, offset+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_frame_interval, tvb, offset+4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_key_frame_rate, tvb, offset+8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_p_frame_rate, tvb, offset+10, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_comp_quality, tvb, offset+12, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_comp_window, tvb, offset+14, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_delay, tvb, offset+16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_max_frame_sz, tvb, offset+18, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_max_payload_sz, tvb, offset+22, 4, ENC_LITTLE_ENDIAN);
offset += 26;
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
static const int *framing_bits[] = {
&hf_usb_vid_probe_framing_D[0],
&hf_usb_vid_probe_framing_D[1],
NULL
};
DISSECTOR_ASSERT(array_length(framing_bits) == (1+array_length(hf_usb_vid_probe_framing_D)));
proto_tree_add_item(tree, hf_usb_vid_probe_clock_freq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_probe_framing,
ett_probe_framing, framing_bits, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_usb_vid_probe_preferred_ver, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_min_ver, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_vid_probe_max_ver, tvb, offset+2, 1, ENC_LITTLE_ENDIAN);
offset += 3;
}
return offset;
}
static value_string_ext*
get_control_selector_values(guint8 entity_id, usb_conv_info_t *usb_conv_info)
{
video_conv_info_t *video_conv_info;
video_entity_t *entity = NULL;
value_string_ext *selectors = NULL;
if (usb_conv_info == NULL)
return NULL;
video_conv_info = (video_conv_info_t *)usb_conv_info->class_data;
if (video_conv_info)
entity = (video_entity_t*) wmem_tree_lookup32(video_conv_info->entities, entity_id);
if (entity_id == 0)
{
switch (usb_conv_info->interfaceSubclass)
{
case SC_VIDEOCONTROL:
selectors = &cs_control_interface_ext;
break;
case SC_VIDEOSTREAMING:
selectors = &cs_streaming_interface_ext;
break;
default:
break;
}
}
else if (entity)
{
switch (entity->subtype)
{
case VC_INPUT_TERMINAL:
if (entity->terminalType == ITT_CAMERA)
{
selectors = &cs_camera_terminal_ext;
}
break;
case VC_PROCESSING_UNIT:
selectors = &cs_processing_unit_ext;
break;
case VC_SELECTOR_UNIT:
selectors = &cs_selector_unit_ext;
break;
default:
break;
}
}
return selectors;
}
static const gchar*
get_control_selector_name(guint8 entity_id, guint8 control_sel, usb_conv_info_t *usb_conv_info)
{
const gchar *control_name = NULL;
value_string_ext *selectors = NULL;
selectors = get_control_selector_values(entity_id, usb_conv_info);
if (selectors)
control_name = try_val_to_str_ext(control_sel, selectors);
return control_name;
}
static int
dissect_usb_vid_control_info(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *capability_bits[] = {
&hf_usb_vid_control_info_D[0],
&hf_usb_vid_control_info_D[1],
&hf_usb_vid_control_info_D[2],
&hf_usb_vid_control_info_D[3],
&hf_usb_vid_control_info_D[4],
&hf_usb_vid_control_info_D[5],
&hf_usb_vid_control_info_D[6],
NULL
};
DISSECTOR_ASSERT(array_length(capability_bits) == (1+array_length(hf_usb_vid_control_info_D)));
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_vid_control_info,
ett_control_capabilities, capability_bits, ENC_NA);
return offset+1;
}
static void
dissect_usb_vid_control_value(proto_tree *tree, tvbuff_t *tvb, int offset, guint8 request)
{
gint value_size;
const char *fallback_name;
int hf;
switch (request)
{
case USB_SETUP_GET_DEF:
hf = hf_usb_vid_control_default;
fallback_name = "Default Value";
break;
case USB_SETUP_GET_MIN:
case CONTROL_CHANGE_MIN:
hf = hf_usb_vid_control_min;
fallback_name = "Min Value";
break;
case USB_SETUP_GET_MAX:
case CONTROL_CHANGE_MAX:
hf = hf_usb_vid_control_max;
fallback_name = "Max Value";
break;
case USB_SETUP_GET_RES:
hf = hf_usb_vid_control_res;
fallback_name = "Resolution";
break;
case USB_SETUP_GET_CUR:
case USB_SETUP_SET_CUR:
case CONTROL_CHANGE_VALUE:
hf = hf_usb_vid_control_cur;
fallback_name = "Current Value";
break;
default:
hf = -1;
fallback_name = "Value";
break;
}
value_size = tvb_reported_length_remaining(tvb, offset);
if (hf != -1)
{
header_field_info *hfinfo;
hfinfo = proto_registrar_get_nth(hf);
DISSECTOR_ASSERT(IS_FT_INT(hfinfo->type) || IS_FT_UINT(hfinfo->type));
}
if ((hf != -1) && (value_size <= 4))
{
proto_tree_add_item(tree, hf, tvb, offset, value_size, ENC_LITTLE_ENDIAN);
}
else
{
proto_tree_add_bytes_format(tree, hf_usb_vid_control_value, tvb, offset, value_size, NULL, "%s", fallback_name);
}
}
static int
dissect_usb_vid_get_set(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb,
int offset, gboolean is_request,
usb_trans_info_t *usb_trans_info,
usb_conv_info_t *usb_conv_info)
{
const gchar *short_name = NULL;
guint8 control_sel;
guint8 entity_id;
entity_id = usb_trans_info->setup.wIndex >> 8;
control_sel = usb_trans_info->setup.wValue >> 8;
col_append_str(pinfo->cinfo, COL_INFO, " [");
short_name = get_control_selector_name(entity_id, control_sel, usb_conv_info);
if (short_name)
col_append_str(pinfo->cinfo, COL_INFO, short_name);
else
{
short_name = "Unknown";
if (entity_id == 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "Interface %u control 0x%x",
usb_conv_info->interfaceNum, control_sel);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "Unit %u control 0x%x",
entity_id, control_sel);
}
}
col_append_str(pinfo->cinfo, COL_INFO, "]");
col_set_fence(pinfo->cinfo, COL_INFO);
if (is_request)
{
offset++;
proto_tree_add_uint_format_value(tree, hf_usb_vid_control_selector, tvb,
offset, 1, control_sel, "%s (0x%02x)", short_name, control_sel);
offset++;
proto_tree_add_item(tree, hf_usb_vid_control_interface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_vid_control_entity, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_vid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
else
{
proto_item *ti;
ti = proto_tree_add_uint(tree, hf_usb_vid_control_interface, tvb, 0, 0,
usb_trans_info->setup.wIndex & 0xFF);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(tree, hf_usb_vid_control_entity, tvb, 0, 0, entity_id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint_format_value(tree, hf_usb_vid_control_selector, tvb,
0, 0, control_sel, "%s (0x%02x)", short_name, control_sel);
PROTO_ITEM_SET_GENERATED(ti);
}
if (!is_request || (usb_trans_info->setup.request == USB_SETUP_SET_CUR))
{
gint value_size = tvb_reported_length_remaining(tvb, offset);
if (value_size != 0)
{
if ((entity_id == 0) && (usb_conv_info->interfaceSubclass == SC_VIDEOSTREAMING))
{
if ((control_sel == VS_PROBE_CONTROL) || (control_sel == VS_COMMIT_CONTROL))
{
int old_offset = offset;
offset = dissect_usb_vid_probe(tree, tvb, offset);
value_size -= (offset - old_offset);
}
}
else
{
if (usb_trans_info->setup.request == USB_SETUP_GET_INFO)
{
dissect_usb_vid_control_info(tree, tvb, offset);
offset++;
value_size--;
}
else if (usb_trans_info->setup.request == USB_SETUP_GET_LEN)
{
proto_tree_add_item(tree, hf_usb_vid_control_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
value_size -= 2;
}
else if ( (usb_trans_info->setup.request == USB_SETUP_GET_CUR)
&& (entity_id == 0)
&& (usb_conv_info->interfaceSubclass == SC_VIDEOCONTROL)
&& (control_sel == VC_REQUEST_ERROR_CODE_CONTROL))
{
proto_tree_add_item(tree, hf_usb_vid_request_error, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
value_size--;
}
else
{
dissect_usb_vid_control_value(tree, tvb, offset, usb_trans_info->setup.request);
offset += value_size;
value_size = 0;
}
}
if (value_size > 0)
{
proto_tree_add_item(tree, hf_usb_vid_control_data, tvb, offset, -1, ENC_NA);
offset += value_size;
}
}
}
return offset;
}
static int
dissect_usb_vid_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gboolean is_request = (pinfo->srcport == NO_ENDPOINT);
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info;
int offset = 0;
usb_setup_dissector dissector = NULL;
const usb_setup_dissector_table_t *tmp;
if (data == NULL || ((usb_conv_info_t *)data)->usb_trans_info == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
usb_trans_info = usb_conv_info->usb_trans_info;
for (tmp=setup_dissectors; tmp->dissector; tmp++)
{
if (tmp->request == usb_trans_info->setup.request)
{
dissector = tmp->dissector;
break;
}
}
if (!dissector)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBVIDEO");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(usb_trans_info->setup.request, setup_request_names_vals, "Unknown type %x"),
is_request?"Request ":"Response");
if (is_request)
{
proto_tree_add_item(tree, hf_usb_vid_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
offset = dissector(pinfo, tree, tvb, offset, is_request, usb_trans_info, usb_conv_info);
return offset;
}
static int
dissect_usb_vid_interrupt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info;
gint bytes_available;
int offset = 0;
usb_conv_info = (usb_conv_info_t *)data;
bytes_available = tvb_reported_length_remaining(tvb, offset);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBVIDEO");
if (bytes_available > 0)
{
guint8 originating_interface;
guint8 originating_entity;
originating_interface = tvb_get_guint8(tvb, offset) & INT_ORIGINATOR_MASK;
proto_tree_add_item(tree, hf_usb_vid_interrupt_bStatusType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
originating_entity = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_interrupt_bOriginator, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (originating_interface == INT_VIDEOCONTROL)
{
guint8 control_sel;
guint8 attribute;
const gchar *control_name;
proto_tree_add_item(tree, hf_usb_vid_control_interrupt_bEvent, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
control_sel = tvb_get_guint8(tvb, offset);
control_name = get_control_selector_name(originating_entity, control_sel, usb_conv_info);
if (!control_name)
control_name = "Unknown";
proto_tree_add_uint_format_value(tree, hf_usb_vid_control_selector, tvb,
offset, 1, control_sel, "%s (0x%02x)",
control_name, control_sel);
offset++;
attribute = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_vid_interrupt_bAttribute, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
switch (attribute)
{
case CONTROL_CHANGE_FAILURE:
proto_tree_add_item(tree, hf_usb_vid_request_error, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
break;
case CONTROL_CHANGE_INFO:
offset = dissect_usb_vid_control_info(tree, tvb, offset);
break;
case CONTROL_CHANGE_VALUE:
case CONTROL_CHANGE_MIN:
case CONTROL_CHANGE_MAX:
dissect_usb_vid_control_value(tree, tvb, offset, attribute);
offset += tvb_reported_length_remaining(tvb, offset);
break;
default:
proto_tree_add_item(tree, hf_usb_vid_value_data, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
break;
}
}
else if (originating_interface == INT_VIDEOSTREAMING)
{
}
}
else
offset = -2;
return offset;
}
void
proto_register_usb_vid(void)
{
static hf_register_info hf[] = {
{ &hf_usb_vid_request,
{ "bRequest", "usbvideo.setup.bRequest", FT_UINT8, BASE_HEX, VALS(setup_request_names_vals), 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_length,
{ "wLength", "usbvideo.setup.wLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_request_error,
{ "bRequestErrorCode", "usbvideo.reqerror.code",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&request_error_codes_ext, 0,
"Request Error Code", HFILL }
},
{ &hf_usb_vid_control_selector,
{ "Control Selector", "usbvideo.control.selector", FT_UINT8, BASE_HEX, NULL, 0x0,
"ID of the control within its entity", HFILL }
},
{ &hf_usb_vid_control_entity,
{ "Entity", "usbvideo.control.entity", FT_UINT8, BASE_HEX, NULL, 0x0,
"Unit or terminal to which the control belongs", HFILL }
},
{ &hf_usb_vid_control_interface,
{ "Interface", "usbvideo.control.interface", FT_UINT8, BASE_HEX, NULL, 0x0,
"Interface to which the control belongs", HFILL }
},
{ &hf_usb_vid_control_info,
{ "Info (Capabilities/State)", "usbvideo.control.info",
FT_UINT8, BASE_HEX, NULL, 0,
"Control capabilities and current state", HFILL }
},
{ &hf_usb_vid_control_info_D[0],
{ "Supports GET", "usbvideo.control.info.D0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[1],
{ "Supports SET", "usbvideo.control.info.D1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[2],
{ "Disabled due to automatic mode", "usbvideo.control.info.D2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<2),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[3],
{ "Autoupdate", "usbvideo.control.info.D3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<3),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[4],
{ "Asynchronous", "usbvideo.control.info.D4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<4),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[5],
{ "Disabled due to incompatibility with Commit state", "usbvideo.control.info.D5",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<5),
NULL, HFILL }
},
{ &hf_usb_vid_control_info_D[6],
{ "Reserved", "usbvideo.control.info.D6",
FT_UINT8, BASE_HEX, NULL, (3<<6),
NULL, HFILL }
},
{ &hf_usb_vid_control_length,
{ "Control Length", "usbvideo.control.len",
FT_UINT16, BASE_DEC, NULL, 0,
"Control size in bytes", HFILL }
},
{ &hf_usb_vid_control_default,
{ "Default value", "usbvideo.control.value.default",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_min,
{ "Minimum value", "usbvideo.control.value.min",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_max,
{ "Maximum value", "usbvideo.control.value.max",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_res,
{ "Resolution", "usbvideo.control.value.res",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_cur,
{ "Current value", "usbvideo.control.value.cur",
FT_UINT32, BASE_DEC_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_ifdesc_iTerminal,
{ "iTerminal", "usbvideo.terminal.name", FT_UINT8, BASE_DEC, NULL, 0x0,
"String Descriptor describing this terminal", HFILL }
},
{ &hf_usb_vid_control_ifdesc_terminal_id,
{ "bTerminalID", "usbvideo.terminal.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_control_ifdesc_terminal_type,
{ "wTerminalType", "usbvideo.terminal.type",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &vc_terminal_types_ext, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_ifdesc_assoc_terminal,
{ "bAssocTerminal", "usbvideo.terminal.assocTerminal", FT_UINT8, BASE_DEC, NULL, 0x0,
"Associated Terminal", HFILL }
},
{ &hf_usb_vid_cam_objective_focal_len_min,
{ "wObjectiveFocalLengthMin", "usbvideo.camera.objectiveFocalLengthMin",
FT_UINT16, BASE_DEC, NULL, 0,
"Minimum Focal Length for Optical Zoom", HFILL }
},
{ &hf_usb_vid_cam_objective_focal_len_max,
{ "wObjectiveFocalLengthMax", "usbvideo.camera.objectiveFocalLengthMax",
FT_UINT16, BASE_DEC, NULL, 0,
"Minimum Focal Length for Optical Zoom", HFILL }
},
{ &hf_usb_vid_cam_ocular_focal_len,
{ "wOcularFocalLength", "usbvideo.camera.ocularFocalLength",
FT_UINT16, BASE_DEC, NULL, 0,
"Ocular Focal Length for Optical Zoom", HFILL }
},
{ &hf_usb_vid_cam_control_D[0],
{ "Scanning Mode", "usbvideo.camera.control.D0",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[1],
{ "Auto Exposure Mode", "usbvideo.camera.control.D1",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[2],
{ "Auto Exposure Priority", "usbvideo.camera.control.D2",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<2),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[3],
{ "Exposure Time (Absolute)", "usbvideo.camera.control.D3",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<3),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[4],
{ "Exposure Time (Relative)", "usbvideo.camera.control.D4",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<4),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[5],
{ "Focus (Absolute)", "usbvideo.camera.control.D5",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<5),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[6],
{ "Focus (Relative)", "usbvideo.camera.control.D6",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<6),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[7],
{ "Iris (Absolute)", "usbvideo.camera.control.D7",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<7),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[8],
{ "Iris (Relative)", "usbvideo.camera.control.D8",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<8),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[9],
{ "Zoom (Absolute)", "usbvideo.camera.control.D9",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<9),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[10],
{ "Zoom (Relative)", "usbvideo.camera.control.D10",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<10),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[11],
{ "PanTilt (Absolute)", "usbvideo.camera.control.D11",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<11),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[12],
{ "PanTilt (Relative)", "usbvideo.camera.control.D12",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<12),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[13],
{ "Roll (Absolute)", "usbvideo.camera.control.D13",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<13),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[14],
{ "Roll (Relative)", "usbvideo.camera.control.D14",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<14),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[15],
{ "D15", "usbvideo.camera.control.D15",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<15),
"Reserved", HFILL }
},
{ &hf_usb_vid_cam_control_D[16],
{ "D16", "usbvideo.camera.control.D16",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<16),
"Reserved", HFILL }
},
{ &hf_usb_vid_cam_control_D[17],
{ "Auto Focus", "usbvideo.camera.control.D17",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<17),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[18],
{ "Privacy", "usbvideo.camera.control.D18",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<18),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[19],
{ "Focus (Simple)", "usbvideo.camera.control.D19",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<19),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[20],
{ "Window", "usbvideo.camera.control.D20",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<20),
NULL, HFILL }
},
{ &hf_usb_vid_cam_control_D[21],
{ "Region of Interest", "usbvideo.camera.control.D21",
FT_BOOLEAN,
array_length(hf_usb_vid_cam_control_D),
TFS(&tfs_yes_no), (1<<21),
NULL, HFILL }
},
{ &hf_usb_vid_control_ifdesc_unit_id,
{ "bUnitID", "usbvideo.unit.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_num_inputs,
{ "bNrInPins", "usbvideo.unit.numInputs",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of input pins", HFILL }
},
{ &hf_usb_vid_sources,
{ "baSourceID", "usbvideo.unit.sources",
FT_BYTES, BASE_NONE, NULL, 0,
"Input entity IDs", HFILL }
},
{ &hf_usb_vid_iProcessing,
{ "iProcessing", "usbvideo.processor.name", FT_UINT8, BASE_DEC, NULL, 0x0,
"String Descriptor describing this terminal", HFILL }
},
{ &hf_usb_vid_proc_control_D[0],
{ "Brightness", "usbvideo.processor.control.D0",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[1],
{ "Contrast", "usbvideo.processor.control.D1",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[2],
{ "Hue", "usbvideo.processor.control.D2",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<2),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[3],
{ "Saturation", "usbvideo.processor.control.D3",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<3),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[4],
{ "Sharpness", "usbvideo.processor.control.D4",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<4),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[5],
{ "Gamma", "usbvideo.processor.control.D5",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<5),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[6],
{ "White Balance Temperature", "usbvideo.processor.control.D6",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<6),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[7],
{ "White Balance Component", "usbvideo.processor.control.D7",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<7),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[8],
{ "Backlight Compensation", "usbvideo.processor.control.D8",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<8),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[9],
{ "Gain", "usbvideo.processor.control.D9",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<9),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[10],
{ "Power Line Frequency", "usbvideo.processor.control.D10",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<10),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[11],
{ "Hue, Auto", "usbvideo.processor.control.D11",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<11),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[12],
{ "White Balance Temperature, Auto", "usbvideo.processor.control.D12",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<12),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[13],
{ "White Balance Component, Auto", "usbvideo.processor.control.D13",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<13),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[14],
{ "Digital Multiplier", "usbvideo.processor.control.D14",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<14),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[15],
{ "Digital Multiplier Limit", "usbvideo.processor.control.D15",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<15),
"Reserved", HFILL }
},
{ &hf_usb_vid_proc_control_D[16],
{ "Analog Video Standard", "usbvideo.processor.control.D16",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<16),
"Reserved", HFILL }
},
{ &hf_usb_vid_proc_control_D[17],
{ "Analog Video Lock Status", "usbvideo.processor.control.D17",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<17),
NULL, HFILL }
},
{ &hf_usb_vid_proc_control_D[18],
{ "Contrast, Auto", "usbvideo.processor.control.D18",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), (1<<18),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards,
{ "bmVideoStandards", "usbvideo.processor.standards",
FT_UINT8, BASE_HEX, NULL, 0,
"Supported analog video standards", HFILL }
},
{ &hf_usb_vid_proc_standards_D[0],
{ "None", "usbvideo.processor.standards.D0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards_D[1],
{ "NTSC - 525/60", "usbvideo.processor.standards.D1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards_D[2],
{ "PAL - 625/50", "usbvideo.processor.standards.D2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<2),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards_D[3],
{ "SECAM - 625/50", "usbvideo.processor.standards.D3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<3),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards_D[4],
{ "NTSC - 625/50", "usbvideo.processor.standards.D4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<4),
NULL, HFILL }
},
{ &hf_usb_vid_proc_standards_D[5],
{ "PAL - 525/60", "usbvideo.processor.standards.D5",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<5),
NULL, HFILL }
},
{ &hf_usb_vid_max_multiplier,
{ "wMaxMultiplier", "usbvideo.processor.maxMultiplier",
FT_UINT16, BASE_DEC, NULL, 0,
"100 x max digital multiplication", HFILL }
},
{ &hf_usb_vid_iSelector,
{ "iSelector", "usbvideo.selector.name", FT_UINT8, BASE_DEC, NULL, 0x0,
"String Descriptor describing this terminal", HFILL }
},
{ &hf_usb_vid_iExtension,
{ "iExtension", "usbvideo.extension.name", FT_UINT8, BASE_DEC, NULL, 0x0,
"String Descriptor describing this terminal", HFILL }
},
{ &hf_usb_vid_exten_guid,
{ "guid", "usbvideo.extension.guid",
FT_GUID, BASE_NONE, NULL, 0,
"Identifier", HFILL }
},
{ &hf_usb_vid_exten_num_controls,
{ "bNumControls", "usbvideo.extension.numControls",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of controls", HFILL }
},
{ &hf_usb_vid_probe_hint,
{ "bmHint", "usbvideo.probe.hint",
FT_UINT16, BASE_HEX, NULL, 0,
"Fields to hold constant during negotiation", HFILL }
},
{ &hf_usb_vid_probe_hint_D[0],
{ "dwFrameInterval", "usbvideo.probe.hint.D0",
FT_BOOLEAN, 5, TFS(&probe_hint_meaning), (1<<0),
"Frame Rate", HFILL }
},
{ &hf_usb_vid_probe_hint_D[1],
{ "wKeyFrameRate", "usbvideo.probe.hint.D1",
FT_BOOLEAN, 5, TFS(&probe_hint_meaning), (1<<1),
"Key Frame Rate", HFILL }
},
{ &hf_usb_vid_probe_hint_D[2],
{ "wPFrameRate", "usbvideo.probe.hint.D2",
FT_BOOLEAN, 5, TFS(&probe_hint_meaning), (1<<2),
"P-Frame Rate", HFILL }
},
{ &hf_usb_vid_probe_hint_D[3],
{ "wCompQuality", "usbvideo.probe.hint.D3",
FT_BOOLEAN, 5, TFS(&probe_hint_meaning), (1<<3),
"Compression Quality", HFILL }
},
{ &hf_usb_vid_probe_hint_D[4],
{ "wCompWindowSize", "usbvideo.probe.hint.D4",
FT_BOOLEAN, 5, TFS(&probe_hint_meaning), (1<<4),
"Compression Window Size", HFILL }
},
{ &hf_usb_vid_probe_key_frame_rate,
{ "wKeyFrameRate", "usbvideo.probe.keyFrameRate",
FT_UINT16, BASE_DEC, NULL, 0,
"Key frame rate", HFILL }
},
{ &hf_usb_vid_probe_p_frame_rate,
{ "wPFrameRate", "usbvideo.probe.pFrameRate",
FT_UINT16, BASE_DEC, NULL, 0,
"P frame rate", HFILL }
},
{ &hf_usb_vid_probe_comp_quality,
{ "wCompQuality", "usbvideo.probe.compQuality",
FT_UINT16, BASE_DEC, NULL, 0,
"Compression quality [0-10000]", HFILL }
},
{ &hf_usb_vid_probe_comp_window,
{ "wCompWindow", "usbvideo.probe.compWindow",
FT_UINT16, BASE_DEC, NULL, 0,
"Window size for average bit rate control", HFILL }
},
{ &hf_usb_vid_probe_delay,
{ "wDelay", "usbvideo.probe.delay",
FT_UINT16, BASE_DEC, NULL, 0,
"Latency in ms from capture to USB", HFILL }
},
{ &hf_usb_vid_probe_max_frame_sz,
{ "dwMaxVideoFrameSize", "usbvideo.probe.maxVideoFrameSize",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_probe_max_payload_sz,
{ "dwMaxPayloadTransferSize", "usbvideo.probe.maxPayloadTransferSize",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_probe_clock_freq,
{ "dwClockFrequency", "usbvideo.probe.clockFrequency",
FT_UINT32, BASE_DEC, NULL, 0,
"Device clock frequency in Hz", HFILL }
},
{ &hf_usb_vid_probe_framing,
{ "bmFramingInfo", "usbvideo.probe.framing",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_probe_framing_D[0],
{ "Frame ID required", "usbvideo.probe.framing.D0",
FT_BOOLEAN, 2, TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_probe_framing_D[1],
{ "EOF utilized", "usbvideo.probe.framing.D1",
FT_BOOLEAN, 2, TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_probe_preferred_ver,
{ "bPreferredVersion", "usbvideo.probe.preferredVersion",
FT_UINT8, BASE_DEC, NULL, 0,
"Preferred payload format version", HFILL }
},
{ &hf_usb_vid_probe_min_ver,
{ "bMinVersion", "usbvideo.probe.minVersion",
FT_UINT8, BASE_DEC, NULL, 0,
"Min supported payload format version", HFILL }
},
{ &hf_usb_vid_probe_max_ver,
{ "bPreferredVersion", "usbvideo.probe.maxVer",
FT_UINT8, BASE_DEC, NULL, 0,
"Max supported payload format version", HFILL }
},
{ &hf_usb_vid_control_ifdesc_dwClockFrequency,
{ "dwClockFrequency", "usbvideo.probe.clockFrequency",
FT_UINT32, BASE_DEC, NULL, 0,
"Device clock frequency (Hz) for selected format", HFILL }
},
{ &hf_usb_vid_format_index,
{ "bFormatIndex", "usbvideo.format.index",
FT_UINT8, BASE_DEC, NULL, 0,
"Index of this format descriptor", HFILL }
},
{ &hf_usb_vid_format_num_frame_descriptors,
{ "bNumFrameDescriptors", "usbvideo.format.numFrameDescriptors",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of frame descriptors for this format", HFILL }
},
{ &hf_usb_vid_format_guid,
{ "guidFormat", "usbvideo.format.guid",
FT_GUID, BASE_NONE, NULL, 0,
"Stream encoding format", HFILL }
},
{ &hf_usb_vid_format_bits_per_pixel,
{ "bBitsPerPixel", "usbvideo.format.bitsPerPixel",
FT_UINT8, BASE_DEC, NULL, 0,
"Bits per pixel", HFILL }
},
{ &hf_usb_vid_default_frame_index,
{ "bDefaultFrameIndex", "usbvideo.format.defaultFrameIndex",
FT_UINT8, BASE_DEC, NULL, 0,
"Optimum frame index for this stream", HFILL }
},
{ &hf_usb_vid_aspect_ratio_x,
{ "bAspectRatioX", "usbvideo.format.aspectRatioX",
FT_UINT8, BASE_DEC, NULL, 0,
"X dimension of picture aspect ratio", HFILL }
},
{ &hf_usb_vid_aspect_ratio_y,
{ "bAspectRatioY", "usbvideo.format.aspectRatioY",
FT_UINT8, BASE_DEC, NULL, 0,
"Y dimension of picture aspect ratio", HFILL }
},
{ &hf_usb_vid_interlace_flags,
{ "bmInterlaceFlags", "usbvideo.format.interlace",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_is_interlaced,
{ "Interlaced stream", "usbvideo.format.interlace.D0",
FT_BOOLEAN, 8, TFS(&is_interlaced_meaning), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_interlaced_fields,
{ "Fields per frame", "usbvideo.format.interlace.D1",
FT_BOOLEAN, 8, TFS(&interlaced_fields_meaning), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_field_1_first,
{ "Field 1 first", "usbvideo.format.interlace.D2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<2),
NULL, HFILL }
},
{ &hf_usb_vid_field_pattern,
{ "Field pattern", "usbvideo.format.interlace.pattern",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&field_pattern_meaning_ext, (3<<4),
NULL, HFILL }
},
{ &hf_usb_vid_copy_protect,
{ "bCopyProtect", "usbvideo.format.copyProtect",
FT_UINT8, BASE_DEC, VALS(copy_protect_meaning), 0,
NULL, HFILL }
},
{ &hf_usb_vid_variable_size,
{ "Variable size", "usbvideo.format.variableSize",
FT_BOOLEAN, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_usb_vid_mjpeg_flags,
{ "bmFlags", "usbvideo.mjpeg.flags",
FT_UINT8, BASE_HEX, NULL, 0,
"Characteristics", HFILL }
},
{ &hf_usb_vid_mjpeg_fixed_samples,
{ "Fixed size samples", "usbvideo.mjpeg.fixed_size",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_frame_index,
{ "bFrameIndex", "usbvideo.frame.index",
FT_UINT8, BASE_DEC, NULL, 0,
"Index of this frame descriptor", HFILL }
},
{ &hf_usb_vid_frame_capabilities,
{ "bmCapabilities", "usbvideo.frame.capabilities",
FT_UINT8, BASE_HEX, NULL, 0,
"Capabilities", HFILL }
},
{ &hf_usb_vid_frame_stills_supported,
{ "Still image", "usbvideo.frame.stills",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), (1<<0),
NULL, HFILL }
},
{ &hf_usb_vid_frame_interval,
{ "dwFrameInterval", "usbvideo.frame.interval",
FT_UINT32, BASE_DEC, NULL, 0,
"Frame interval multiple of 100 ns", HFILL }
},
{ &hf_usb_vid_frame_fixed_frame_rate,
{ "Fixed frame rate", "usbvideo.frame.fixedRate",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<1),
NULL, HFILL }
},
{ &hf_usb_vid_frame_width,
{ "wWidth", "usbvideo.frame.width",
FT_UINT16, BASE_DEC, NULL, 0,
"Width of frame in pixels", HFILL }
},
{ &hf_usb_vid_frame_height,
{ "wHeight", "usbvideo.frame.height",
FT_UINT16, BASE_DEC, NULL, 0,
"Height of frame in pixels", HFILL }
},
{ &hf_usb_vid_frame_min_bit_rate,
{ "dwMinBitRate", "usbvideo.frame.minBitRate",
FT_UINT32, BASE_DEC, NULL, 0,
"Minimum bit rate in bps", HFILL }
},
{ &hf_usb_vid_frame_max_bit_rate,
{ "dwMaxBitRate", "usbvideo.frame.maxBitRate",
FT_UINT32, BASE_DEC, NULL, 0,
"Maximum bit rate in bps", HFILL }
},
{ &hf_usb_vid_frame_max_frame_sz,
{ "dwMaxVideoFrameBufferSize", "usbvideo.frame.maxBuffer",
FT_UINT32, BASE_DEC, NULL, 0,
"Maximum bytes per frame", HFILL }
},
{ &hf_usb_vid_frame_default_interval,
{ "dwDefaultFrameInterval", "usbvideo.frame.interval.default",
FT_UINT32, BASE_DEC, NULL, 0,
"Suggested default", HFILL }
},
{ &hf_usb_vid_frame_interval_type,
{ "bFrameIntervalType", "usbvideo.frame.interval.type",
FT_UINT8, BASE_DEC, NULL, 0,
"Frame rate control (continuous/discrete)", HFILL }
},
{ &hf_usb_vid_frame_min_interval,
{ "dwMinFrameInterval", "usbvideo.frame.interval.min",
FT_UINT32, BASE_DEC, NULL, 0,
"Shortest frame interval (* 100 ns)", HFILL }
},
{ &hf_usb_vid_frame_max_interval,
{ "dwMaxFrameInterval", "usbvideo.frame.interval.max",
FT_UINT32, BASE_DEC, NULL, 0,
"Longest frame interval (* 100 ns)", HFILL }
},
{ &hf_usb_vid_frame_step_interval,
{ "dwMinFrameInterval", "usbvideo.frame.interval.step",
FT_UINT32, BASE_DEC, NULL, 0,
"Granularity of frame interval (* 100 ns)", HFILL }
},
{ &hf_usb_vid_frame_bytes_per_line,
{ "dwBytesPerLine", "usbvideo.frame.bytesPerLine",
FT_UINT32, BASE_DEC, NULL, 0,
"Fixed number of bytes per video line", HFILL }
},
{ &hf_usb_vid_color_primaries,
{ "bColorPrimaries", "usbvideo.color.primaries",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&color_primaries_meaning_ext, 0,
NULL, HFILL }
},
{ &hf_usb_vid_transfer_characteristics,
{ "bTransferCharacteristics", "usbvideo.color.transferCharacteristics",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&color_transfer_characteristics_ext, 0,
NULL, HFILL }
},
{ &hf_usb_vid_matrix_coefficients,
{ "bMatrixCoefficients", "usbvideo.color.matrixCoefficients",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&matrix_coefficients_meaning_ext, 0,
NULL, HFILL }
},
{ &hf_usb_vid_control_ifdesc_bcdUVC,
{ "bcdUVC", "usbvideo.bcdUVC",
FT_UINT16, BASE_HEX, NULL, 0,
"Video Device Class Specification release number", HFILL }
},
{ &hf_usb_vid_control_ifdesc_bInCollection,
{ "bInCollection", "usbvideo.numStreamingInterfaces",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of VideoStreaming interfaces", HFILL }
},
{ &hf_usb_vid_control_ifdesc_baInterfaceNr,
{ "baInterfaceNr", "usbvideo.streamingInterfaceNumbers",
FT_BYTES, BASE_NONE, NULL, 0,
"Interface numbers of VideoStreaming interfaces", HFILL }},
{ &hf_usb_vid_streaming_ifdesc_bNumFormats,
{ "bNumFormats", "usbvideo.streaming.numFormats",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of video payload format descriptors", HFILL }
},
{ &hf_usb_vid_streaming_bmInfo,
{ "bmInfo", "usbvideo.streaming.info",
FT_UINT8, BASE_HEX, NULL, 0,
"Capabilities", HFILL }
},
{ &hf_usb_vid_streaming_info_D[0],
{ "Dynamic Format Change", "usbvideo.streaming.info.D0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), (1<<0),
"Dynamic Format Change", HFILL }
},
{ &hf_usb_vid_streaming_control_D[0],
{ "wKeyFrameRate", "usbvideo.streaming.control.D0",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<0),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_control_D[1],
{ "wPFrameRate", "usbvideo.streaming.control.D1",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<1),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_control_D[2],
{ "wCompQuality", "usbvideo.streaming.control.D2",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<2),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_control_D[3],
{ "wCompWindowSize", "usbvideo.streaming.control.D3",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<3),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_control_D[4],
{ "Generate Key Frame", "usbvideo.streaming.control.D4",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<4),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_control_D[5],
{ "Update Frame Segment", "usbvideo.streaming.control.D5",
FT_BOOLEAN, 6, TFS(&tfs_yes_no), (1<<5),
"Probe and Commit support", HFILL }
},
{ &hf_usb_vid_streaming_terminal_link,
{ "bTerminalLink", "usbvideo.streaming.terminalLink", FT_UINT8, BASE_DEC, NULL, 0x0,
"Output terminal ID", HFILL }
},
{ &hf_usb_vid_streaming_still_capture_method,
{ "bStillCaptureMethod", "usbvideo.streaming.stillCaptureMethod",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&vs_still_capture_methods_ext, 0,
"Method of Still Image Capture", HFILL }
},
{ &hf_usb_vid_streaming_trigger_support,
{ "HW Triggering", "usbvideo.streaming.triggerSupport",
FT_BOOLEAN, BASE_DEC, TFS(&tfs_supported_not_supported), 0,
"Is HW triggering supported", HFILL }
},
{ &hf_usb_vid_streaming_trigger_usage,
{ "bTriggerUsage", "usbvideo.streaming.triggerUsage",
FT_UINT8, BASE_DEC, VALS(vs_trigger_usage), 0,
"How host SW should respond to trigger", HFILL }
},
{ &hf_usb_vid_interrupt_bStatusType,
{ "Status Type", "usbvideo.interrupt.statusType",
FT_UINT8, BASE_HEX, VALS(interrupt_status_types), 0xF,
NULL, HFILL }
},
{ &hf_usb_vid_interrupt_bAttribute,
{ "Change Type", "usbvideo.interrupt.attribute",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&control_change_types_ext, 0,
"Type of control change", HFILL }
},
{ &hf_usb_vid_interrupt_bOriginator,
{ "Originator", "usbvideo.interrupt.originator",
FT_UINT8, BASE_DEC, NULL, 0,
"ID of the entity that reports this interrupt", HFILL }
},
{ &hf_usb_vid_control_interrupt_bEvent,
{ "Event", "usbvideo.interrupt.controlEvent",
FT_UINT8, BASE_HEX, VALS(control_interrupt_events), 0,
"Type of event", HFILL }
},
{ &hf_usb_vid_epdesc_subtype,
{ "Subtype", "usbvideo.ep.descriptorSubType",
FT_UINT8, BASE_DEC, VALS(vc_ep_descriptor_subtypes), 0,
"Descriptor Subtype", HFILL }
},
{ &hf_usb_vid_epdesc_max_transfer_sz,
{ "wMaxTransferSize", "usbvideo.ep.maxInterruptSize", FT_UINT16,
BASE_DEC, NULL, 0x0, "Max interrupt structure size", HFILL }
},
{ &hf_usb_vid_ifdesc_wTotalLength,
{ "wTotalLength", "usbvideo.totalLength",
FT_UINT16, BASE_DEC, NULL, 0,
"Video interface descriptor size", HFILL }
},
{ &hf_usb_vid_bControlSize,
{ "bControlSize", "usbvideo.bmcontrolSize",
FT_UINT8, BASE_DEC, NULL, 0,
"Size of bmControls field", HFILL }
},
{ &hf_usb_vid_bmControl,
{ "bmControl", "usbvideo.availableControls",
FT_UINT32, BASE_HEX, NULL, 0,
"Available controls", HFILL }
},
{ &hf_usb_vid_bmControl_bytes,
{ "bmControl", "usbvideo.availableControls.bytes",
FT_BYTES, BASE_NONE, NULL, 0,
"Available controls", HFILL }
},
{ &hf_usb_vid_control_ifdesc_src_id,
{ "bSourceID", "usbvideo.sourceID", FT_UINT8, BASE_DEC, NULL, 0x0,
"Entity to which this terminal/unit is connected", HFILL }
},
{ &hf_usb_vid_control_ifdesc_subtype,
{ "Subtype", "usbvideo.control.descriptorSubType",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&vc_if_descriptor_subtypes_ext, 0,
"Descriptor Subtype", HFILL }
},
{ &hf_usb_vid_streaming_ifdesc_subtype,
{ "Subtype", "usbvideo.streaming.descriptorSubType",
FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&vs_if_descriptor_subtypes_ext, 0,
"Descriptor Subtype", HFILL }
},
{ &hf_usb_vid_descriptor_data,
{ "Descriptor data", "usbvideo.descriptor_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_control_data,
{ "Control data", "usbvideo.control_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_control_value,
{ "Control value", "usbvideo.control_value", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_vid_value_data,
{ "Value data", "usbvideo.value_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *usb_vid_subtrees[] = {
&ett_usb_vid,
&ett_descriptor_video_endpoint,
&ett_descriptor_video_control,
&ett_descriptor_video_streaming,
&ett_camera_controls,
&ett_processing_controls,
&ett_streaming_controls,
&ett_streaming_info,
&ett_interlace_flags,
&ett_frame_capability_flags,
&ett_mjpeg_flags,
&ett_video_probe,
&ett_probe_hint,
&ett_probe_framing,
&ett_video_standards,
&ett_control_capabilities
};
static ei_register_info ei[] = {
{ &ei_usb_vid_subtype_unknown, { "usbvideo.subtype.unknown", PI_UNDECODED, PI_WARN, "Unknown VC subtype", EXPFILL }},
{ &ei_usb_vid_bitmask_len, { "usbvideo.bitmask_len_error", PI_UNDECODED, PI_WARN, "Only least-significant bytes decoded", EXPFILL }},
};
expert_module_t* expert_usb_vid;
proto_usb_vid = proto_register_protocol("USB Video", "USBVIDEO", "usbvideo");
proto_register_field_array(proto_usb_vid, hf, array_length(hf));
proto_register_subtree_array(usb_vid_subtrees, array_length(usb_vid_subtrees));
expert_usb_vid = expert_register_protocol(proto_usb_vid);
expert_register_field_array(expert_usb_vid, ei, array_length(ei));
}
void
proto_reg_handoff_usb_vid(void)
{
dissector_handle_t usb_vid_control_handle;
dissector_handle_t usb_vid_descriptor_handle;
dissector_handle_t usb_vid_interrupt_handle;
usb_vid_control_handle = create_dissector_handle(dissect_usb_vid_control, proto_usb_vid);
dissector_add_uint("usb.control", IF_CLASS_VIDEO, usb_vid_control_handle);
usb_vid_descriptor_handle = create_dissector_handle(dissect_usb_vid_descriptor, proto_usb_vid);
dissector_add_uint("usb.descriptor", IF_CLASS_VIDEO, usb_vid_descriptor_handle);
usb_vid_interrupt_handle = create_dissector_handle(dissect_usb_vid_interrupt, proto_usb_vid);
dissector_add_uint("usb.interrupt", IF_CLASS_VIDEO, usb_vid_interrupt_handle);
}
