static gboolean
h264_byte_aligned(int bit_offset)
{
if (bit_offset&0x3)
return FALSE;
return TRUE;
}
static guint32
dissect_h264_exp_golomb_code(proto_tree *tree, int hf_index, tvbuff_t *tvb, gint *start_bit_offset, h264_golomb_descriptors descriptor)
{
gint leading_zero_bits, bit_offset, start_offset;
guint32 codenum, mask, value, tmp;
gint32 se_value = 0;
gint b;
char *str;
int bit;
int i;
header_field_info *hf_field = NULL;
start_offset = *start_bit_offset>>3;
if (hf_index > -1)
hf_field = proto_registrar_get_nth(hf_index);
bit_offset = *start_bit_offset;
str = (char *)wmem_alloc(wmem_packet_scope(), 256);
str[0] = '\0';
for (bit=0; bit<((int)(bit_offset&0x07)); bit++) {
if (bit && (!(bit%4))) {
g_strlcat(str, " ", 256);
}
g_strlcat(str,".", 256);
}
leading_zero_bits = -1;
for (b = 0; !b; leading_zero_bits++) {
if (bit && (!(bit%4))) {
g_strlcat(str, " ", 256);
}
if (bit && (!(bit%8))) {
g_strlcat(str, " ", 256);
}
b = tvb_get_bits8(tvb, bit_offset, 1);
if (b != 0) {
g_strlcat(str, "1", 256);
} else {
g_strlcat(str, "0", 256);
}
bit++;
bit_offset++;
}
if (leading_zero_bits == 0) {
codenum = 0;
*start_bit_offset = bit_offset;
for (; bit%8; bit++) {
if (bit && (!(bit%4))) {
g_strlcat(str, " ", 256);
}
g_strlcat(str,".", 256);
}
if (hf_field) {
g_strlcat(str," = ", 256);
g_strlcat(str, hf_field->name, 256);
switch (descriptor) {
case H264_SE_V:
if (hf_field->type == FT_INT32) {
if (hf_field->strings) {
proto_tree_add_int_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %s (%d)",
str,
val_to_str_const(codenum, cVALS(hf_field->strings), "Unknown "),
codenum);
} else {
switch (hf_field->display) {
case BASE_DEC:
proto_tree_add_int_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %d",
str,
codenum);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
}
return codenum;
default:
break;
}
if (hf_field->type == FT_UINT32) {
if (hf_field->strings) {
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %s (%u)",
str,
val_to_str_const(codenum, cVALS(hf_field->strings), "Unknown "),
codenum);
} else {
switch (hf_field->display) {
case BASE_DEC:
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %u",
str,
codenum);
break;
case BASE_HEX:
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: 0x%x",
str,
codenum);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
}
return codenum;
}
codenum = 1;
codenum = codenum << leading_zero_bits;
mask = codenum>>1;
if (leading_zero_bits > 32)
DISSECTOR_ASSERT_NOT_REACHED();
else if (leading_zero_bits > 16)
value = tvb_get_bits32(tvb, bit_offset, leading_zero_bits, ENC_BIG_ENDIAN);
else if (leading_zero_bits > 8)
value = tvb_get_bits16(tvb, bit_offset, leading_zero_bits, ENC_BIG_ENDIAN);
else
value = tvb_get_bits8(tvb, bit_offset, leading_zero_bits);
codenum = (codenum-1) + value;
bit_offset = bit_offset + leading_zero_bits;
for (i=0; i<leading_zero_bits; i++) {
if (bit && (!(bit%4))) {
g_strlcat(str, " ", 256);
}
if (bit && (!(bit%8))) {
g_strlcat(str, " ", 256);
}
bit++;
tmp = value & mask;
if (tmp != 0) {
g_strlcat(str, "1", 256);
} else {
g_strlcat(str, "0", 256);
}
mask = mask>>1;
}
for ( ; bit%8; bit++) {
if (bit && (!(bit%4))) {
g_strlcat(str, " ", 256);
}
g_strlcat(str,".", 256);
}
switch (descriptor) {
case H264_SE_V:
se_value = (codenum + 1) >> 1;
if (!(se_value & 1)) {
se_value = - se_value;
}
break;
default:
break;
}
if (hf_field) {
g_strlcat(str," = ", 256);
g_strlcat(str, hf_field->name, 256);
switch (descriptor) {
case H264_SE_V:
g_strlcat(str,"(se(v))", 256);
break;
default:
break;
}
if ((hf_field->type == FT_UINT32) && (descriptor == H264_UE_V)) {
if (hf_field->strings) {
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %s (%u)",
str,
val_to_str_const(codenum, cVALS(hf_field->strings), "Unknown "),
codenum);
} else {
switch (hf_field->display) {
case BASE_DEC:
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %u",
str,
codenum);
break;
case BASE_HEX:
proto_tree_add_uint_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: 0x%x",
str,
codenum);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
} else if ((hf_field->type == FT_INT32) && (descriptor == H264_SE_V)) {
if (hf_field->strings) {
proto_tree_add_int_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %s (%d)",
str,
val_to_str_const(codenum, cVALS(hf_field->strings), "Unknown "),
se_value);
} else {
switch (hf_field->display) {
case BASE_DEC:
proto_tree_add_int_format(tree, hf_index, tvb, start_offset, 1, codenum,
"%s: %d",
str,
se_value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
*start_bit_offset = bit_offset;
return se_value;
} else {
DISSECTOR_ASSERT_NOT_REACHED();
}
}
*start_bit_offset = bit_offset;
return codenum;
}
static gboolean
more_rbsp_data(proto_tree *tree _U_, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset)
{
int offset;
int remaining_length;
int last_one_bit;
guint8 b = 0;
offset = bit_offset>>3;
remaining_length = tvb_reported_length_remaining(tvb, offset);
if (remaining_length>2) {
return TRUE;
}
last_one_bit = (tvb_reported_length(tvb) << 3);
for (b = 0; !b; ) {
last_one_bit--;
b = tvb_get_bits8(tvb, last_one_bit, 1);
}
if (last_one_bit == bit_offset) {
return FALSE;
}
return TRUE;
}
static int
dissect_h264_rbsp_trailing_bits(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset)
{
gint remaining_bits=0;
proto_tree_add_bits_item(tree, hf_h264_rbsp_stop_bit, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if ((bit_offset&0x7) != 0) {
remaining_bits = 8 - (bit_offset&0x7);
proto_tree_add_bits_item(tree, hf_h264_rbsp_trailing_bits, tvb, bit_offset, remaining_bits, ENC_BIG_ENDIAN);
}
return bit_offset+remaining_bits;
}
static int
dissect_h264_slice_header(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset)
{
dissect_h264_exp_golomb_code(tree, hf_h264_first_mb_in_slice, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_slice_type, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_pic_parameter_set_id, tvb, &bit_offset, H264_UE_V);
return bit_offset;
}
static int
dissect_h264_hrd_parameters(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset)
{
guint8 cpb_cnt_minus1;
int SchedSelIdx;
cpb_cnt_minus1 = dissect_h264_exp_golomb_code(tree, hf_h264_cpb_cnt_minus1, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_bit_rate_scale, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
proto_tree_add_bits_item(tree, hf_h264_cpb_size_scale, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
for (SchedSelIdx = 0; SchedSelIdx <= cpb_cnt_minus1; SchedSelIdx++) {
dissect_h264_exp_golomb_code(tree, hf_h264_bit_rate_value_minus1, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_cpb_size_value_minus1, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_cbr_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
proto_tree_add_bits_item(tree, hf_h264_initial_cpb_removal_delay_length_minus1, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
proto_tree_add_bits_item(tree, hf_h264_cpb_removal_delay_length_minus1, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
proto_tree_add_bits_item(tree, hf_h264_dpb_output_delay_length_minus11, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
proto_tree_add_bits_item(tree, hf_h264_time_offset_length, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
return bit_offset;
}
static int
dissect_h264_vui_parameters(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint bit_offset)
{
guint8 aspect_ratio_info_present_flag, aspect_ratio_idc, overscan_info_present_flag;
guint8 video_signal_type_present_flag, colour_description_present_flag, chroma_loc_info_present_flag;
guint8 timing_info_present_flag, nal_hrd_parameters_present_flag, vcl_hrd_parameters_present_flag;
guint8 bitstream_restriction_flag;
aspect_ratio_info_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_aspect_ratio_info_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (aspect_ratio_info_present_flag) {
aspect_ratio_idc = tvb_get_bits8(tvb, bit_offset, 8);
proto_tree_add_bits_item(tree, hf_h264_aspect_ratio_idc, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 8;
if (aspect_ratio_idc == EXTENDED_SAR) {
proto_tree_add_bits_item(tree, hf_h264_sar_width, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 16;
proto_tree_add_bits_item(tree, hf_h264_sar_height, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 16;
}
}
overscan_info_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_overscan_info_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (overscan_info_present_flag) {
proto_tree_add_bits_item(tree, hf_h264_overscan_appropriate_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
video_signal_type_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_video_signal_type_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (video_signal_type_present_flag) {
proto_tree_add_bits_item(tree, hf_h264_video_format, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 3;
proto_tree_add_bits_item(tree, hf_h264_video_full_range_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
colour_description_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_colour_description_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (colour_description_present_flag) {
proto_tree_add_bits_item(tree, hf_h264_colour_primaries, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 8;
proto_tree_add_bits_item(tree, hf_h264_transfer_characteristics, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 8;
proto_tree_add_bits_item(tree, hf_h264_matrix_coefficients, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 8;
}
}
chroma_loc_info_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_chroma_loc_info_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (chroma_loc_info_present_flag) {
dissect_h264_exp_golomb_code(tree, hf_h264_chroma_sample_loc_type_top_field, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_chroma_sample_loc_type_bottom_field, tvb, &bit_offset, H264_UE_V);
}
timing_info_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_timing_info_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (timing_info_present_flag) {
proto_tree_add_bits_item(tree, hf_h264_num_units_in_tick, tvb, bit_offset, 32, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 32;
proto_tree_add_bits_item(tree, hf_h264_time_scale, tvb, bit_offset, 32, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 32;
proto_tree_add_bits_item(tree, hf_h264_fixed_frame_rate_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
nal_hrd_parameters_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_nal_hrd_parameters_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (nal_hrd_parameters_present_flag) {
bit_offset = dissect_h264_hrd_parameters(tree, tvb, pinfo, bit_offset);
}
vcl_hrd_parameters_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_vcl_hrd_parameters_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (vcl_hrd_parameters_present_flag) {
bit_offset = dissect_h264_hrd_parameters(tree, tvb, pinfo, bit_offset);
}
if (nal_hrd_parameters_present_flag || vcl_hrd_parameters_present_flag) {
proto_tree_add_bits_item(tree, hf_h264_low_delay_hrd_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
proto_tree_add_bits_item(tree, hf_h264_pic_struct_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
bitstream_restriction_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_bitstream_restriction_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (bitstream_restriction_flag) {
proto_tree_add_bits_item(tree, hf_h264_motion_vectors_over_pic_boundaries_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
dissect_h264_exp_golomb_code(tree, hf_h264_max_bytes_per_pic_denom, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_max_bits_per_mb_denom, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_log2_max_mv_length_horizontal, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_log2_max_mv_length_vertical, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_num_reorder_frames, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_max_dec_frame_buffering, tvb, &bit_offset, H264_UE_V);
}
return bit_offset;
}
void
dissect_h264_profile(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item, *level_item;
proto_tree *h264_profile_tree;
gint offset = 0;
guint8 constraint_set3_flag;
guint32 level_idc;
item = proto_tree_add_item(tree, hf_h264_profile, tvb, offset, -1, ENC_NA);
h264_profile_tree = proto_item_add_subtree(item, ett_h264_profile);
proto_tree_add_item(h264_profile_tree, hf_h264_profile_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
constraint_set3_flag = (tvb_get_guint8(tvb, offset)&0x10)>>4;
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set0_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set1_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set2_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set3_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set4_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_constraint_set5_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_profile_tree, hf_h264_reserved_zero_2bits, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
level_idc = tvb_get_guint8(tvb, offset);
level_item = proto_tree_add_item(h264_profile_tree, hf_h264_level_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((level_idc == 11) && (constraint_set3_flag == 1)) {
proto_item_append_text(level_item," [Level 1b (128kb/s)]");
} else {
proto_item_append_text(level_item," [Level %.1f %s]", ((double)level_idc/10), val_to_str_const(level_idc, h264_level_bitrate_values, "Unknown "));
}
}
static tvbuff_t *
dissect_h265_unescap_nal_unit(tvbuff_t *tvb, packet_info *pinfo, int offset)
{
tvbuff_t *tvb_rbsp;
int length = tvb_reported_length_remaining(tvb, offset);
int NumBytesInRBSP = 0;
int i;
gchar *buff;
buff = (gchar *)wmem_alloc(pinfo->pool, length);
for (i = 0; i < length; i++) {
if ((i + 2 < length) && (tvb_get_ntoh24(tvb, offset) == 0x000003)) {
buff[NumBytesInRBSP++] = tvb_get_guint8(tvb, offset);
buff[NumBytesInRBSP++] = tvb_get_guint8(tvb, offset+1);
i += 2;
offset+=3;
} else {
buff[ NumBytesInRBSP++] = tvb_get_guint8(tvb, offset);
offset++;
}
}
tvb_rbsp = tvb_new_child_real_data(tvb, buff, NumBytesInRBSP, NumBytesInRBSP);
add_new_data_source(pinfo, tvb_rbsp, "Unescaped RSP Data");
return tvb_rbsp;
}
static void
dissect_h264_slice_layer_without_partitioning_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
gint bit_offset;
bit_offset = offset <<3;
bit_offset = dissect_h264_slice_header(tree, tvb, pinfo, bit_offset);
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
return;
}
static void
dissect_h264_slice_data_partition_a_layer_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
gint bit_offset;
bit_offset = offset <<3;
bit_offset = dissect_h264_slice_header(tree, tvb, pinfo, bit_offset);
dissect_h264_exp_golomb_code(tree, hf_h264_slice_id, tvb, &bit_offset, H264_UE_V);
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
return;
}
static void
dissect_h264_slice_data_partition_b_layer_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
gint bit_offset;
bit_offset = offset <<3;
dissect_h264_exp_golomb_code(tree, hf_h264_slice_id, tvb, &bit_offset, H264_UE_V);
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
}
static void
dissect_h264_slice_data_partition_c_layer_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
gint bit_offset;
bit_offset = offset <<3;
dissect_h264_exp_golomb_code(tree, hf_h264_slice_id, tvb, &bit_offset, H264_UE_V);
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
}
static int
h264_user_data_unregistered(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset, guint32 payloadSize)
{
guint8 i;
guint8 ld_size;
guint8 p_flag;
guint8 desc =0;
guint8 num_crops;
gint offset = bit_offset >> 3;
proto_item *item;
proto_item *uuid_item;
proto_tree *h264_ms_layer_desc_tree;
proto_tree *h264_ms_crop_data_tree;
e_guid_t guid;
uuid_item = proto_tree_add_item (tree, hf_h264_sei_uuid, tvb, offset, 16, ENC_BIG_ENDIAN);
tvb_get_ntohguid(tvb, offset, &guid);
offset+=16;
if ( memcmp(&guid, &(ms_guids[MS_LAYOUT]), sizeof(e_guid_t)) == 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ":MS_Layout");
proto_item_append_text(uuid_item," - Microsoft Stream Layout SEI Message");
for (i = 0; i < 8 ; i++)
{
item = proto_tree_add_item (tree, hf_h264_sei_ms_lpb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text (item, " PRID %2d - %2d", (i+1)*8-1, i*8);
offset++;
}
p_flag = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, hf_h264_sei_ms_layout_p, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (p_flag == 1)
{
ld_size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, hf_h264_sei_ms_layout_ldsize, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tvb_reported_length_remaining (tvb, offset) != ld_size)
{
item = proto_tree_add_expert(tree, pinfo, &ei_h264_ms_layout_wrong_length, tvb, offset-1, 1);
proto_item_append_text(item," Size of %d, remaining size %d",
ld_size,
tvb_reported_length_remaining (tvb, offset));
}
while (tvb_reported_length_remaining (tvb, offset) >= 16)
{
h264_ms_layer_desc_tree = proto_tree_add_subtree_format(tree, tvb, offset, 16, ett_h264_ms_layer_description, NULL, "MS Layer Description #%d", ++desc);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_coded_width, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_coded_height, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_display_width, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_display_height, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_bitrate, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_frame_rate, tvb, offset + 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_layer_type, tvb, offset + 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_prid, tvb, offset + 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_layer_desc_tree, hf_h264_sei_ms_layer_desc_cb, tvb, offset + 13, 1, ENC_BIG_ENDIAN);
offset += 16;
}
}
}
else if ( memcmp(&guid, &(ms_guids[MS_CROPPING]), sizeof(e_guid_t)) == 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ":MS_Cropping");
proto_item_append_text(uuid_item," - Microsoft Cropping Info SEI Message");
num_crops = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, hf_h264_sei_ms_crop_num_data, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_h264_sei_ms_crop_info_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (num_crops != 0)
{
h264_ms_crop_data_tree = proto_tree_add_subtree_format(tree, tvb, offset, 9, ett_h264_ms_crop_data, NULL, "Crop Data #%d", ++desc);
proto_tree_add_item (h264_ms_crop_data_tree, hf_h264_sei_ms_crop_confidence_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_crop_data_tree, hf_h264_sei_ms_crop_frame_left_offset, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_crop_data_tree, hf_h264_sei_ms_crop_frame_right_offset, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_crop_data_tree, hf_h264_sei_ms_crop_frame_top_offset, tvb, offset+5, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (h264_ms_crop_data_tree, hf_h264_sei_ms_crop_frame_bottom_offset, tvb, offset+7, 2, ENC_BIG_ENDIAN);
num_crops--;
offset += 9;
}
}
else if ( memcmp(&guid, &(ms_guids[MS_BITSTREAM]), sizeof(e_guid_t)) == 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ":MS_Bitstream");
proto_item_append_text(uuid_item," - Microsoft Bitstream Info SEI Message");
proto_tree_add_item (tree, hf_h264_sei_ms_bitstream_ref_frame_cnt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item (tree, hf_h264_sei_ms_bitstream_num_nalus, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else
{
proto_tree_add_item(tree, hf_h264_sei_iso_sec_info, tvb, offset, 16, ENC_NA);
if (payloadSize > 16)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, payloadSize-16);
offset+=(payloadSize-16);
}
}
return offset << 3;
}
static int
h264_sei_payload(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint bit_offset, guint32 payloadType, guint32 payloadSize)
{
if (payloadType == 0) {
bit_offset = bit_offset +(payloadSize<<3);
#if 0
} else if (payloadType == 1) {
} else if (payloadType == 2) {
} else if (payloadType == 3) {
} else if (payloadType == 4) {
#endif
} else if (payloadType == 5) {
bit_offset = h264_user_data_unregistered( tree, tvb, pinfo, bit_offset, payloadSize);
} else if (payloadType == 6) {
bit_offset = bit_offset +(payloadSize<<3);
} else if (payloadType == 7) {
bit_offset = bit_offset +(payloadSize<<3);
}
#if 0
else if (payloadType == 8)
spare_pic( payloadSize ) 5
else if (payloadType == 9)
scene_info( payloadSize ) 5
else if (payloadType == 10)
sub_seq_info( payloadSize ) 5
else if (payloadType == 11)
sub_seq_layer_characteristics( payloadSize ) 5
else if (payloadType == 12)
sub_seq_characteristics( payloadSize ) 5
else if (payloadType == 13)
full_frame_freeze( payloadSize ) 5
else if (payloadType == 14)
full_frame_freeze_release( payloadSize ) 5
else if (payloadType == 15)
full_frame_snapshot( payloadSize ) 5
else if (payloadType == 16)
progressive_refinement_segment_start( payloadSize ) 5
else if (payloadType == 17)
progressive_refinement_segment_end( payloadSize ) 5
else if (payloadType == 18)
motion_constrained_slice_group_set( payloadSize ) 5
else if (payloadType == 19)
film_grain_characteristics( payloadSize ) 5
else if (payloadType == 20)
deblocking_filter_display_preference( payloadSize ) 5
else if (payloadType == 21)
stereo_video_info( payloadSize ) 5
else
reserved_sei_message( payloadSize ) 5
return bit_offset;
#endif
if (!h264_byte_aligned(bit_offset)) {
bit_offset++;
while (!h264_byte_aligned(bit_offset)) {
bit_offset++;
}
}
return bit_offset;
}
static gint
dissect_h264_sei_message(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint bit_offset)
{
guint32 payloadType = 0, payloadSize;
gint start_bit_offset, length;
start_bit_offset = bit_offset;
while (tvb_get_bits8(tvb, bit_offset, 8) == 0xFF) {
payloadType += 255;
bit_offset+=8;
}
payloadType += tvb_get_bits8(tvb, bit_offset, 8);
bit_offset+=8;
length = (bit_offset - start_bit_offset)>>3;
proto_tree_add_uint(tree, hf_h264_payloadtype, tvb, start_bit_offset>>3, length, payloadType);
payloadSize = 0;
start_bit_offset = bit_offset;
while (tvb_get_bits8(tvb, bit_offset, 8) == 0xFF) {
payloadSize += 255;
bit_offset+=8;
}
payloadSize += tvb_get_bits8(tvb, bit_offset, 8);
bit_offset+=8;
length = (bit_offset - start_bit_offset)>>3;
proto_tree_add_uint(tree, hf_h264_payloadsize, tvb, start_bit_offset>>3, length, payloadSize);
bit_offset = h264_sei_payload( tree, tvb, pinfo, bit_offset, payloadType, payloadSize);
return bit_offset;
}
static int
dissect_h264_sei_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
gint bit_offset;
bit_offset = offset <<3;
bit_offset = dissect_h264_sei_message( tree, tvb, pinfo, bit_offset);
if (tvb_reported_length_remaining (tvb, bit_offset >> 3) != 0 || (bit_offset & 0x7) != 0)
{
bit_offset = dissect_h264_rbsp_trailing_bits(tree, tvb, pinfo, bit_offset);
}
return bit_offset;
}
static int
dissect_h264_seq_parameter_set_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
proto_item *level_item;
gint bit_offset;
guint8 constraint_set3_flag;
guint32 level_idc;
gint i;
guint8 profile_idc, chroma_format_idc, frame_mbs_only_flag, frame_cropping_flag;
guint8 pic_order_cnt_type, vui_parameters_present_flag, num_ref_frames_in_pic_order_cnt_cycle;
guint8 seq_scaling_matrix_present_flag;
profile_idc = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_h264_profile_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
constraint_set3_flag = (tvb_get_guint8(tvb, offset)&0x10)>>4;
proto_tree_add_item(tree, hf_h264_constraint_set0_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_constraint_set1_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_constraint_set2_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_constraint_set3_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_constraint_set4_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_constraint_set5_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_reserved_zero_2bits, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
level_idc = tvb_get_guint8(tvb, offset);
level_item = proto_tree_add_item(tree, hf_h264_level_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((level_idc == 11) && (constraint_set3_flag == 1)) {
proto_item_append_text(level_item,"[Level 1b]");
} else {
proto_item_append_text(level_item," [Level %.1f %s]", ((double)level_idc/10), val_to_str_const(level_idc, h264_level_bitrate_values, "Unknown "));
}
offset++;
bit_offset = offset<<3;
dissect_h264_exp_golomb_code(tree, hf_h264_seq_parameter_set_id, tvb, &bit_offset, H264_UE_V);
if ((profile_idc == 100) || (profile_idc == 110) ||
(profile_idc == 122) || (profile_idc == 144) ||
(profile_idc == 44) || (profile_idc == 83) ||
(profile_idc == 86) || (profile_idc == 118) ||
(profile_idc == 128) || (profile_idc == 138))
{
chroma_format_idc = dissect_h264_exp_golomb_code(tree, hf_h264_chroma_format_idc, tvb, &bit_offset, H264_UE_V);
if (chroma_format_idc == 3) {
proto_tree_add_bits_item(tree, hf_h264_residual_colour_transform_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
dissect_h264_exp_golomb_code(tree, hf_h264_bit_depth_luma_minus8, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_bit_depth_chroma_minus8, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_qpprime_y_zero_transform_bypass_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
seq_scaling_matrix_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_seq_scaling_matrix_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (seq_scaling_matrix_present_flag) {
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
return -1;
}
}
dissect_h264_exp_golomb_code(tree, hf_h264_log2_max_frame_num_minus4, tvb, &bit_offset, H264_UE_V);
pic_order_cnt_type = dissect_h264_exp_golomb_code(tree, hf_h264_pic_order_cnt_type, tvb, &bit_offset, H264_UE_V);
if (pic_order_cnt_type == 0) {
dissect_h264_exp_golomb_code(tree, hf_h264_log2_max_pic_order_cnt_lsb_minus4, tvb, &bit_offset, H264_UE_V);
} else if (pic_order_cnt_type == 1) {
proto_tree_add_bits_item(tree, hf_h264_delta_pic_order_always_zero_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
dissect_h264_exp_golomb_code(tree, hf_h264_offset_for_non_ref_pic, tvb, &bit_offset, H264_SE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_offset_for_top_to_bottom_field, tvb, &bit_offset, H264_SE_V);
num_ref_frames_in_pic_order_cnt_cycle = dissect_h264_exp_golomb_code(tree, hf_h264_num_ref_frames_in_pic_order_cnt_cycle, tvb, &bit_offset, H264_UE_V);
for (i = 0; i < num_ref_frames_in_pic_order_cnt_cycle; i++) {
dissect_h264_exp_golomb_code(tree, hf_h264_offset_for_ref_frame, tvb, &bit_offset, H264_SE_V);
}
}
dissect_h264_exp_golomb_code(tree, hf_h264_num_ref_frames, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_gaps_in_frame_num_value_allowed_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
dissect_h264_exp_golomb_code(tree, hf_h264_pic_width_in_mbs_minus1, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_pic_height_in_map_units_minus1, tvb, &bit_offset, H264_UE_V);
frame_mbs_only_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_frame_mbs_only_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (!frame_mbs_only_flag) {
proto_tree_add_bits_item(tree, hf_h264_mb_adaptive_frame_field_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
proto_tree_add_bits_item(tree, hf_h264_direct_8x8_inference_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
frame_cropping_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_frame_cropping_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (frame_cropping_flag) {
dissect_h264_exp_golomb_code(tree, hf_h264_frame_crop_left_offset, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_frame_crop_right_offset, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_frame_crop_top_offset, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_frame_crop_bottom_offset, tvb, &bit_offset, H264_UE_V);
}
vui_parameters_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_vui_parameters_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (vui_parameters_present_flag) {
bit_offset = dissect_h264_vui_parameters(tree, tvb, pinfo, bit_offset);
}
bit_offset = dissect_h264_rbsp_trailing_bits(tree, tvb, pinfo, bit_offset);
offset = bit_offset>>3;
return offset;
}
static void
dissect_h264_pic_parameter_set_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
gint bit_offset;
guint32 num_slice_groups_minus1, pic_scaling_matrix_present_flag;
bit_offset = offset<<3;
dissect_h264_exp_golomb_code(tree, hf_h264_pic_parameter_set_id, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_seq_parameter_set_id, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_entropy_coding_mode_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_h264_pic_order_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
num_slice_groups_minus1 = dissect_h264_exp_golomb_code(tree, hf_h264_num_slice_groups_minus1, tvb, &bit_offset, H264_UE_V);
if (num_slice_groups_minus1 > 0) {
dissect_h264_exp_golomb_code(tree, hf_h264_slice_group_map_type, tvb, &bit_offset, H264_UE_V);
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
return;
}
dissect_h264_exp_golomb_code(tree, hf_h264_num_ref_idx_l0_active_minus1, tvb, &bit_offset, H264_UE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_num_ref_idx_l1_active_minus1, tvb, &bit_offset, H264_UE_V);
proto_tree_add_bits_item(tree, hf_h264_weighted_pred_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_h264_weighted_bipred_idc, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset= bit_offset+2;
dissect_h264_exp_golomb_code(tree, hf_h264_pic_init_qp_minus26, tvb, &bit_offset, H264_SE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_pic_init_qs_minus26, tvb, &bit_offset, H264_SE_V);
dissect_h264_exp_golomb_code(tree, hf_h264_chroma_qp_index_offset, tvb, &bit_offset, H264_SE_V);
proto_tree_add_bits_item(tree, hf_h264_deblocking_filter_control_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_h264_constrained_intra_pred_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_h264_redundant_pic_cnt_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (more_rbsp_data(tree, tvb, pinfo, bit_offset)) {
proto_tree_add_bits_item(tree, hf_h264_transform_8x8_mode_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
pic_scaling_matrix_present_flag = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tree, hf_h264_pic_scaling_matrix_present_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
if (pic_scaling_matrix_present_flag) {
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, bit_offset>>3, -1);
return;
}
dissect_h264_exp_golomb_code(tree, hf_h264_second_chroma_qp_index_offset, tvb, &bit_offset, H264_SE_V);
}
bit_offset = dissect_h264_rbsp_trailing_bits(tree, tvb, pinfo, bit_offset);
}
static void
dissect_h264_access_unit_delimiter_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, -1);
}
static void
dissect_h264_end_of_seq_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, -1);
}
static void
dissect_h264_end_of_stream_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, -1);
}
static void
dissect_h264_filler_data_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, -1);
}
static void
dissect_h264_seq_parameter_set_extension_rbsp(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_expert(tree, pinfo, &ei_h264_undecoded, tvb, offset, -1);
}
static gint
dissect_h264_svc_nal_header_extension(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_svc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_i, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_prid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_n, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_did, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_qid, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_tid, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_u, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_d, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_o, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_hdr_ext_rr, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
return offset + 3;
}
static int dissect_h264_prefix(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
guint8 svc_extension_flag;
svc_extension_flag = tvb_get_bits8(tvb, offset << 3, 1);
if (svc_extension_flag)
{
dissect_h264_svc_nal_header_extension (tree, tvb, pinfo, offset);
}
else
{
offset +=3;
}
return offset;
}
static void
dissect_h264_pacsi(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset)
{
gint8 pacsi_flags;
guint16 nal_unit_size;
tvbuff_t *nalu_tvb;
gboolean error = FALSE;
gboolean contains_sei = FALSE;
offset = dissect_h264_svc_nal_header_extension(tree, tvb, pinfo, offset);
pacsi_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_h264_pacsi_x, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_y, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_t, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_p, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_s, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_pacsi_e, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (pacsi_flags & 0x40)
{
proto_tree_add_item(tree, hf_h264_pacsi_tl0picidx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_h264_pacsi_idrpicid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (pacsi_flags & 0x20)
{
proto_tree_add_item(tree, hf_h264_pacsi_donc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
contains_sei = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, "(");
}
while (tvb_reported_length_remaining(tvb, offset) > 0 && !error)
{
nal_unit_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_h264_nalu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (nal_unit_size == 0 || nal_unit_size > tvb_reported_length_remaining(tvb, offset))
{
proto_tree_add_expert(tree, pinfo, &ei_h264_bad_nal_length, tvb, offset-2, 2);
error = TRUE;
}
else
{
nalu_tvb = tvb_new_subset(tvb, offset, tvb_captured_length_remaining(tvb,offset), nal_unit_size);
dissect_h264(nalu_tvb, pinfo, tree, NULL);
offset += nal_unit_size;
}
}
if (contains_sei == TRUE)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ")");
}
}
static void
dissect_h264_stap(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset, gint8 nal_type)
{
guint16 nal_unit_size;
tvbuff_t *nalu_tvb;
proto_item *item;
if (nal_type == H264_STAP_B)
{
proto_tree_add_item(tree, hf_h264_don, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
proto_tree_add_item(tree, hf_h264_nalu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
nal_unit_size = tvb_get_ntohs(tvb, offset);
offset += 2;
if (nal_unit_size == 0 || tvb_reported_length_remaining(tvb, offset) < nal_unit_size)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " [Bad NAL Length]");
item = proto_tree_add_expert (tree, pinfo, &ei_h264_bad_nal_length, tvb, offset-2, 2);
proto_item_append_text(item, " Size of %d, Remaining %d",
nal_unit_size, tvb_reported_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
}
else
{
nalu_tvb = tvb_new_subset(tvb, offset, tvb_captured_length_remaining(tvb, offset), nal_unit_size);
dissect_h264(nalu_tvb, pinfo, tree, NULL);
offset += nal_unit_size;
}
}
}
static void
dissect_h264_mtap(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset, gint8 nal_type)
{
gint size_offset;
guint16 nal_unit_size;
tvbuff_t *nalu_tvb;
proto_item *item;
proto_tree_add_item(tree, hf_h264_don, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
proto_tree_add_item(tree, hf_h264_nalu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
nal_unit_size = tvb_get_ntohs(tvb, offset);
size_offset = offset;
offset += 2;
proto_tree_add_item(tree, hf_h264_dond, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (nal_type == H264_MTAP16)
{
proto_tree_add_item(tree, hf_h264_ts_offset16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(tree, hf_h264_ts_offset24, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 3;
}
if (nal_unit_size == 0 || tvb_reported_length_remaining(tvb, offset) < nal_unit_size)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " [Bad NAL Length]");
item = proto_tree_add_expert (tree, pinfo, &ei_h264_bad_nal_length, tvb, size_offset, 2);
proto_item_append_text(item, " Size of %d, Remaining %d",
nal_unit_size, tvb_reported_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
}
else
{
nalu_tvb = tvb_new_subset(tvb, offset, tvb_captured_length_remaining(tvb, offset), nal_unit_size);
dissect_h264(nalu_tvb, pinfo, tree, NULL);
offset += nal_unit_size;
}
}
}
static void
dissect_h264_nalu_extension (proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
gint size_offset;
guint16 nal_unit_size;
tvbuff_t *nalu_tvb;
guint8 subtype;
guint8 j_flag;
guint8 bit_offset = offset << 3;
guint8 unit = 1;
proto_item *item;
proto_tree *nimtap_tree;
subtype = tvb_get_bits8(tvb, bit_offset, 5);
j_flag = tvb_get_bits8(tvb, bit_offset+5, 1);
proto_tree_add_item(tree, hf_h264_nal_extension_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_h264_nal_extension_j, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_h264_nal_extension_k, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_h264_nal_extension_l, tvb, offset, 1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(subtype, h264_subtype_summary_values, "Unknown Subtype (%u)"));
offset++;
if (subtype == 2)
{
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
nimtap_tree = proto_tree_add_subtree_format(tree, tvb, offset, 1, ett_h264_ni_mtap, NULL, "NI-MTAP Unit %d", unit++);
proto_tree_add_item(nimtap_tree, hf_h264_nalu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
nal_unit_size = tvb_get_ntohs(tvb, offset);
size_offset = offset;
offset += 2;
proto_tree_add_item(nimtap_tree, hf_h264_ts_offset16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (j_flag)
{
proto_tree_add_item(nimtap_tree, hf_h264_don, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (nal_unit_size == 0 || tvb_reported_length_remaining(tvb, offset) < nal_unit_size)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " [Bad NAL Length]");
item = proto_tree_add_expert (nimtap_tree, pinfo, &ei_h264_bad_nal_length, tvb, size_offset, 2);
proto_item_append_text(item, " Size of %d, Remaining %d",
nal_unit_size, tvb_reported_length_remaining(tvb, offset));
offset += tvb_reported_length_remaining(tvb, offset);
}
else
{
nalu_tvb = tvb_new_subset(tvb, offset, tvb_captured_length_remaining(tvb, offset), nal_unit_size);
dissect_h264(nalu_tvb, pinfo, nimtap_tree, NULL);
offset += nal_unit_size;
}
}
}
}
void
dissect_h264_nal_unit(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *item, *nal_item;
proto_tree *h264_nal_tree;
gint offset = 0;
guint8 nal_unit_type;
guint32 dword;
item = proto_tree_add_item(tree, hf_h264_nal_unit, tvb, offset, -1, ENC_NA);
h264_nal_tree = proto_item_add_subtree(item, ett_h264_nal_unit);
startover:
dword = tvb_get_bits32(tvb, offset<<3, 32, ENC_BIG_ENDIAN);
if (dword == 1) {
offset+=4;
} else if ((dword >> 8) == 1) {
offset+= 3;
}
nal_unit_type = tvb_get_guint8(tvb, offset) & 0x1f;
proto_tree_add_item(h264_nal_tree, hf_h264_forbidden_zero_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_nal_tree, hf_h264_nal_ref_idc, tvb, offset, 1, ENC_BIG_ENDIAN);
nal_item = proto_tree_add_item(h264_nal_tree, hf_h264_nal_unit_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (nal_unit_type) {
case 1:
dissect_h264_slice_layer_without_partitioning_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 2:
dissect_h264_slice_data_partition_a_layer_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 3:
dissect_h264_slice_data_partition_b_layer_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 4:
dissect_h264_slice_data_partition_c_layer_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 5:
dissect_h264_slice_layer_without_partitioning_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 6:
dissect_h264_sei_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case H264_SEQ_PAR_SET:
offset = dissect_h264_seq_parameter_set_rbsp(h264_nal_tree, tvb, pinfo, offset);
if ((offset != -1) && (tvb_reported_length_remaining(tvb, offset) > 0)) {
proto_item_set_len(item, offset);
item = proto_tree_add_item(tree, hf_h264_nal_unit, tvb, offset, -1, ENC_NA);
h264_nal_tree = proto_item_add_subtree(item, ett_h264_nal_unit);
goto startover;
}
break;
case H264_PIC_PAR_SET:
dissect_h264_pic_parameter_set_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 9:
dissect_h264_access_unit_delimiter_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 10:
dissect_h264_end_of_seq_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 11:
dissect_h264_end_of_stream_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 12:
dissect_h264_filler_data_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 13:
dissect_h264_seq_parameter_set_extension_rbsp(h264_nal_tree, tvb, pinfo, offset);
break;
case 14:
case 15:
case 16:
case 17:
case 18:
expert_add_info(pinfo, nal_item, &ei_h264_nal_unit_type_reserved);
break;
case 19:
dissect_h264_slice_layer_without_partitioning_rbsp(tree, tvb, pinfo, offset);
break;
case 28:
dissect_h264_slice_layer_without_partitioning_rbsp(tree, tvb, pinfo, offset);
break;
case 0:
default:
expert_add_info(pinfo, nal_item, &ei_h264_nal_unit_type_unspecified);
break;
}
}
static int
dissect_h264(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item *item;
proto_tree *h264_tree, *h264_nal_tree, *stream_tree, *fua_tree;
guint8 type;
tvbuff_t *rbsp_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H264");
type = tvb_get_guint8(tvb, offset)&0x1f;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(type, h264_type_summary_values, "Unknown Type (%u)"));
{
item = proto_tree_add_item(tree, proto_h264, tvb, 0, -1, ENC_NA);
h264_tree = proto_item_add_subtree(item, ett_h264);
if (type == 28)
h264_nal_tree = proto_tree_add_subtree(h264_tree, tvb, offset, 1, ett_h264_nal, NULL, "FU identifier");
else
h264_nal_tree = proto_tree_add_subtree(h264_tree, tvb, offset, 1, ett_h264_nal, NULL, "NAL unit header or first byte of the payload");
proto_tree_add_item(h264_nal_tree, hf_h264_nal_f_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_nal_tree, hf_h264_nal_nri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(h264_nal_tree, hf_h264_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (type == 28) {
fua_tree = proto_tree_add_subtree(h264_tree, tvb, offset, 1, ett_h264_fua, NULL, "FU Header");
proto_tree_add_item(fua_tree, hf_h264_start_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fua_tree, hf_h264_end_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fua_tree, hf_h264_forbidden_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fua_tree, hf_h264_nal_unit_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset)&0x80) == 0x80) {
type = tvb_get_guint8(tvb, offset)&0x1f;
col_append_fstr(pinfo->cinfo, COL_INFO, " Start:%s",
val_to_str(type, h264_type_summary_values, "Unknown Type (%u)"));
offset++;
}
else
{
if ((tvb_get_guint8(tvb, offset)&0x40) == 0x40) {
col_append_fstr(pinfo->cinfo, COL_INFO, " End");
}
return offset;
}
}
rbsp_tvb = dissect_h265_unescap_nal_unit(tvb, pinfo, offset);
stream_tree = proto_tree_add_subtree(h264_tree, tvb, offset, -1, ett_h264_stream, NULL, "H264 NAL Unit Payload");
switch (type) {
case 1:
dissect_h264_slice_layer_without_partitioning_rbsp(stream_tree, rbsp_tvb, pinfo, 0);
break;
case 3:
dissect_h264_slice_data_partition_b_layer_rbsp(h264_nal_tree, rbsp_tvb, pinfo, 0);
break;
case 4:
dissect_h264_slice_data_partition_c_layer_rbsp(h264_nal_tree, rbsp_tvb, pinfo, 0);
break;
case 5:
dissect_h264_slice_layer_without_partitioning_rbsp(stream_tree, rbsp_tvb, pinfo, 0);
break;
case 6:
dissect_h264_sei_rbsp(stream_tree, tvb, pinfo, offset);
break;
case H264_SEQ_PAR_SET:
dissect_h264_seq_parameter_set_rbsp(stream_tree, rbsp_tvb, pinfo, 0);
break;
case H264_PIC_PAR_SET:
dissect_h264_pic_parameter_set_rbsp(stream_tree, rbsp_tvb, pinfo, 0);
break;
case H264_PREFIX:
dissect_h264_prefix(stream_tree, rbsp_tvb, pinfo, 0);
break;
case 19:
dissect_h264_slice_layer_without_partitioning_rbsp(stream_tree, rbsp_tvb, pinfo, 0);
break;
case H264_STAP_A:
case H264_STAP_B:
dissect_h264_stap(stream_tree, tvb, pinfo, offset, type);
break;
case H264_MTAP16:
case H264_MTAP24:
dissect_h264_mtap(stream_tree, tvb, pinfo, offset, type);
break;
case H264_PACSI:
dissect_h264_pacsi(stream_tree, tvb, pinfo, offset);
break;
case H264_EXTENSION:
dissect_h264_nalu_extension(stream_tree, rbsp_tvb, pinfo, 0);
break;
default:
break;
}
}
return tvb_captured_length(tvb);
}
static int
dissect_h264_par_profile(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_bitmask(tree, tvb, offset,
hf_h264_par_profile, ett_h264_par_profile,
profile_fields, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_h264_par_AdditionalModesSupported(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_bitmask(tree, tvb, offset,
hf_h264_par_AdditionalModesSupported, ett_h264_par_AdditionalModesSupported,
AdditionalModesSupported_fields, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_h264_ProfileIOP(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_bitmask(tree, tvb, offset,
hf_h264_par_ProfileIOP, ett_h264_par_ProfileIOP,
ProfileIOP_fields, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_h264_par_level(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data)
{
int offset = 0;
guint16 lvl;
const gchar *p;
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
lvl = tvb_get_ntohs(tvb, offset);
p = try_val_to_str(lvl, VALS(h264_par_level_values));
if (p) {
proto_item_append_text(actx->created_item, " - Level %s", p);
}
offset += 2;
return offset;
}
static int
dissect_h264_par_DecoderConfigurationInformation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
dissect_h264_nal_unit(tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
static h264_capability_t *find_cap(const gchar *id) {
h264_capability_t *ftr = NULL;
h264_capability_t *f;
for (f=h264_capability_tab; f->id; f++) {
if (!strcmp(id, f->id)) { ftr = f; break; }
}
return ftr;
}
static int
dissect_h264_name(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree, void* data)
{
asn1_ctx_t *actx;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
if (tree) {
h264_capability_t *ftr;
ftr = find_cap(pinfo->match_string);
if (ftr) {
proto_item_append_text(actx->created_item, " - %s", ftr->name);
proto_item_append_text(proto_item_get_parent(proto_tree_get_parent(tree)), ": %s", ftr->name);
} else {
proto_item_append_text(actx->created_item, " - unknown(%s)", pinfo->match_string);
}
}
return tvb_reported_length(tvb);
}
static void range_delete_h264_rtp_pt_callback(guint32 rtp_pt) {
if (rtp_pt >= 96 && rtp_pt <= 127)
dissector_delete_uint("rtp.pt", rtp_pt, h264_handle);
}
static void range_add_h264_rtp_pt_callback(guint32 rtp_pt) {
if (rtp_pt >= 96 && rtp_pt <= 127)
dissector_add_uint("rtp.pt", rtp_pt, h264_handle);
}
void
proto_register_h264(void)
{
module_t *h264_module;
expert_module_t* expert_h264;
static hf_register_info hf[] = {
{ &hf_h264_nal_f_bit,
{ "F bit", "h264.f",
FT_BOOLEAN, 8, TFS(&h264_f_bit_vals), 0x80,
NULL, HFILL }
},
{ &hf_h264_nal_nri,
{ "Nal_ref_idc (NRI)", "h264.nal_nri",
FT_UINT8, BASE_DEC, NULL, 0x60,
NULL, HFILL }
},
{ &hf_h264_type,
{ "Type", "h264.nal_unit_hdr",
FT_UINT8, BASE_DEC, VALS(h264_type_values), 0x1f,
NULL, HFILL }
},
{ &hf_h264_start_bit,
{ "Start bit", "h264.start.bit",
FT_BOOLEAN, 8, TFS(&h264_start_bit_vals), 0x80,
NULL, HFILL }
},
{ &hf_h264_end_bit,
{ "End bit", "h264.end.bit",
FT_BOOLEAN, 8, TFS(&h264_end_bit_vals), 0x40,
NULL, HFILL }
},
{ &hf_h264_forbidden_bit,
{ "Forbidden bit", "h264.forbidden.bit",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_h264_profile,
{ "Profile", "h264.profile",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_profile_idc,
{ "Profile_idc", "h264.profile_idc",
FT_UINT8, BASE_DEC, VALS(h264_profile_idc_values), 0xff,
NULL, HFILL }
},
{ &hf_h264_rbsp_stop_bit,
{ "rbsp_stop_bit", "h264.rbsp_stop_bit",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_rbsp_trailing_bits,
{ "rbsp_trailing_bits", "h264.rbsp_trailing_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_constraint_set0_flag,
{ "Constraint_set0_flag", "h264.constraint_set0_flag",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_h264_constraint_set1_flag,
{ "Constraint_set1_flag", "h264.constraint_set1_flag",
FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL }
},
{ &hf_h264_constraint_set2_flag,
{ "Constraint_set2_flag", "h264.constraint_set2_flag",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_h264_constraint_set3_flag,
{ "Constraint_set3_flag", "h264.constraint_set3_flag",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_h264_constraint_set4_flag,
{ "Constraint_set4_flag", "h264.constraint_set4_flag",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_h264_constraint_set5_flag,
{ "Constraint_set5_flag", "h264.constraint_set5_flag",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_h264_reserved_zero_2bits,
{ "Reserved_zero_2bits", "h264.reserved_zero_2bits",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }
},
{ &hf_h264_level_idc,
{ "Level_id", "h264.level_id",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_h264_nal_unit,
{ "NAL unit", "h264.nal_unit",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_forbidden_zero_bit,
{ "Forbidden_zero_bit", "h264.forbidden_zero_bit",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_h264_nal_ref_idc,
{ "Nal_ref_idc", "h264.nal_ref_idc",
FT_UINT8, BASE_DEC, NULL, 0x60,
NULL, HFILL }
},
{&hf_h264_nal_unit_type,
{ "Nal_unit_type", "h264.nal_unit_type",
FT_UINT8, BASE_DEC, VALS(h264_nal_unit_type_vals), 0x1f,
NULL, HFILL }
},
{ &hf_h264_seq_parameter_set_id,
{ "seq_parameter_set_id", "h264.seq_parameter_set_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_chroma_format_idc,
{ "chroma_format_id", "h264.chroma_format_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_residual_colour_transform_flag,
{ "residual_colour_transform_flag", "h264.residual_colour_transform_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_bit_depth_luma_minus8,
{ "bit_depth_luma_minus8", "h264.bit_depth_luma_minus8",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_bit_depth_chroma_minus8,
{ "bit_depth_chroma_minus8", "h264.bit_depth_chroma_minus8",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_qpprime_y_zero_transform_bypass_flag,
{ "qpprime_y_zero_transform_bypass_flag", "h264.qpprime_y_zero_transform_bypass_flag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_seq_scaling_matrix_present_flag,
{ "seq_scaling_matrix_present_flag", "h264.seq_scaling_matrix_present_flag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_log2_max_frame_num_minus4,
{ "log2_max_frame_num_minus4", "h264.log2_max_frame_num_minus4",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_order_cnt_type,
{ "pic_order_cnt_type", "h264.pic_order_cnt_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_log2_max_pic_order_cnt_lsb_minus4,
{ "log2_max_pic_order_cnt_lsb_minus4", "h264.log2_max_pic_order_cnt_lsb_minus4",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_delta_pic_order_always_zero_flag,
{ "delta_pic_order_always_zero_flag", "h264.delta_pic_order_always_zero_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_offset_for_non_ref_pic,
{ "offset_for_non_ref_pic", "h264.offset_for_non_ref_pic",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_offset_for_top_to_bottom_field,
{ "offset_for_top_to_bottom_field", "h264.offset_for_top_to_bottom_field",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_ref_frames_in_pic_order_cnt_cycle,
{ "num_ref_frames_in_pic_order_cnt_cycle", "h264.num_ref_frames_in_pic_order_cnt_cycle",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_offset_for_ref_frame,
{ "offset_for_ref_frame", "h264.offset_for_ref_frame",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_ref_frames,
{ "num_ref_frames", "h264.num_ref_frames",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_gaps_in_frame_num_value_allowed_flag,
{ "gaps_in_frame_num_value_allowed_flag", "h264.gaps_in_frame_num_value_allowed_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_width_in_mbs_minus1,
{ "pic_width_in_mbs_minus1", "h264.pic_width_in_mbs_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_height_in_map_units_minus1,
{ "pic_height_in_map_units_minus1", "h264.pic_height_in_map_units_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_mbs_only_flag,
{ "frame_mbs_only_flag", "h264.frame_mbs_only_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_mb_adaptive_frame_field_flag,
{ "mb_adaptive_frame_field_flag", "h264.mb_adaptive_frame_field_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_direct_8x8_inference_flag,
{ "direct_8x8_inference_flag", "h264.direct_8x8_inference_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_cropping_flag,
{ "frame_cropping_flag", "h264.frame_cropping_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_crop_left_offset,
{ "frame_crop_left_offset", "h264.frame_crop_left_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_crop_right_offset,
{ "frame_crop_left_offset", "h264.frame_crop_right_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_crop_top_offset,
{ "frame_crop_top_offset", "h264.frame_crop_top_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_frame_crop_bottom_offset,
{ "frame_crop_bottom_offset", "h264.frame_crop_bottom_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_vui_parameters_present_flag,
{ "vui_parameters_present_flag", "h264.vui_parameters_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_parameter_set_id,
{ "pic_parameter_set_id", "h264.pic_parameter_set_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_entropy_coding_mode_flag,
{ "entropy_coding_mode_flag", "h264.entropy_coding_mode_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_order_present_flag,
{ "pic_order_present_flag", "h264.pic_order_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_slice_groups_minus1,
{ "num_slice_groups_minus1", "h264.num_slice_groups_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_slice_group_map_type,
{ "slice_group_map_type", "h264.slice_group_map_type",
FT_UINT32, BASE_DEC, VALS(h264_slice_group_map_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_h264_num_ref_idx_l0_active_minus1,
{ "num_ref_idx_l0_active_minus1", "h264.num_ref_idx_l0_active_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_ref_idx_l1_active_minus1,
{ "num_ref_idx_l1_active_minus1", "h264.num_ref_idx_l1_active_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_weighted_pred_flag,
{ "weighted_pred_flag", "h264.weighted_pred_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_weighted_bipred_idc,
{ "weighted_bipred_idc", "h264.weighted_bipred_idc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_init_qp_minus26,
{ "pic_init_qp_minus26", "h264.pic_init_qp_minus26",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_init_qs_minus26,
{ "pic_init_qs_minus26", "h264.pic_init_qs_minus26",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_chroma_qp_index_offset,
{ "chroma_qp_index_offset", "h264.chroma_qp_index_offset",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_deblocking_filter_control_present_flag,
{ "deblocking_filter_control_present_flag", "h264.deblocking_filter_control_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_constrained_intra_pred_flag,
{ "constrained_intra_pred_flag", "h264.constrained_intra_pred_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_redundant_pic_cnt_present_flag,
{ "redundant_pic_cnt_present_flag", "h264.redundant_pic_cnt_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_transform_8x8_mode_flag,
{ "transform_8x8_mode_flag", "h264.transform_8x8_mode_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_scaling_matrix_present_flag,
{ "pic_scaling_matrix_present_flag", "h264.pic_scaling_matrix_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_second_chroma_qp_index_offset,
{ "second_chroma_qp_index_offset", "h264.second_chroma_qp_index_offset",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_aspect_ratio_info_present_flag,
{ "aspect_ratio_info_present_flag", "h264.aspect_ratio_info_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_aspect_ratio_idc,
{ "aspect_ratio_idc", "h264.aspect_ratio_idc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sar_width,
{ "sar_width", "h264.sar_width",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sar_height,
{ "sar_height", "h264.sar_height",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_overscan_info_present_flag,
{ "overscan_info_present_flag", "h264.overscan_info_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_overscan_appropriate_flag,
{ "overscan_appropriate_flag", "h264.overscan_appropriate_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_video_signal_type_present_flag,
{ "video_signal_type_present_flag", "h264.video_signal_type_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_video_format,
{ "video_format", "h264.video_format",
FT_UINT8, BASE_DEC, VALS(h264_video_format_vals), 0x0,
NULL, HFILL }
},
{ &hf_h264_video_full_range_flag,
{ "video_full_range_flag", "h264.video_full_range_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_colour_description_present_flag,
{ "colour_description_present_flag", "h264.colour_description_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_colour_primaries,
{ "colour_primaries", "h264.colour_primaries",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_transfer_characteristics,
{ "transfer_characteristics", "h264.transfer_characteristics",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_matrix_coefficients,
{ "matrix_coefficients", "h264.matrix_coefficients",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_chroma_loc_info_present_flag,
{ "chroma_loc_info_present_flag", "h264.chroma_loc_info_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_chroma_sample_loc_type_top_field,
{ "chroma_sample_loc_type_top_field", "h264.chroma_sample_loc_type_top_field",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_chroma_sample_loc_type_bottom_field,
{ "chroma_sample_loc_type_bottom_field", "h264.chroma_sample_loc_type_bottom_field",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_timing_info_present_flag,
{ "timing_info_present_flag", "h264.timing_info_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_units_in_tick,
{ "num_units_in_tick", "h264.num_units_in_tick",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_time_scale,
{ "time_scale", "h264.time_scale",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_fixed_frame_rate_flag,
{ "fixed_frame_rate_flag", "h264.fixed_frame_rate_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_nal_hrd_parameters_present_flag,
{ "nal_hrd_parameters_present_flag", "h264.nal_hrd_parameters_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_vcl_hrd_parameters_present_flag,
{ "vcl_hrd_parameters_present_flag", "h264.vcl_hrd_parameters_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_low_delay_hrd_flag,
{ "low_delay_hrd_flag", "h264.low_delay_hrd_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pic_struct_present_flag,
{ "pic_struct_present_flag", "h264.pic_struct_present_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_bitstream_restriction_flag,
{ "bitstream_restriction_flag", "h264.bitstream_restriction_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_motion_vectors_over_pic_boundaries_flag,
{ "motion_vectors_over_pic_boundaries_flag", "h264.motion_vectors_over_pic_boundaries_flag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_max_bytes_per_pic_denom,
{ "max_bytes_per_pic_denom", "h264.max_bytes_per_pic_denom",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_max_bits_per_mb_denom,
{ "max_bits_per_mb_denom", "h264.max_bits_per_mb_denom",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_log2_max_mv_length_horizontal,
{ "max_mv_length_horizontal", "h264.max_mv_length_horizontal",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_log2_max_mv_length_vertical,
{ "log2_max_mv_length_vertical", "h264.log2_max_mv_length_vertical",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_num_reorder_frames,
{ "num_reorder_frames", "h264.num_reorder_frames",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_max_dec_frame_buffering,
{ "max_dec_frame_buffering", "h264.max_dec_frame_buffering",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_cpb_cnt_minus1,
{ "cpb_cnt_minus1", "h264.cpb_cnt_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_bit_rate_scale,
{ "bit_rate_scale", "h264.bit_rate_scale",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_cpb_size_scale,
{ "cpb_size_scale", "h264.cpb_size_scale",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_bit_rate_value_minus1,
{ "bit_rate_value_minus1", "h264.bit_rate_value_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_cpb_size_value_minus1,
{ "cpb_size_value_minus1", "h264.cpb_size_value_minus1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_cbr_flag,
{ "cbr_flag", "h264.cbr_flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_initial_cpb_removal_delay_length_minus1,
{ "initial_cpb_removal_delay_length_minus1", "h264.initial_cpb_removal_delay_length_minus1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_cpb_removal_delay_length_minus1,
{ "cpb_removal_delay_length_minus1", "h264.cpb_removal_delay_length_minus1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_dpb_output_delay_length_minus11,
{ "dpb_output_delay_length_minus11", "h264.dpb_output_delay_length_minus11",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_time_offset_length,
{ "time_offset_length", "h264.time_offset_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_first_mb_in_slice,
{ "first_mb_in_slice", "h264.first_mb_in_slice",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_slice_type,
{ "slice_type", "h264.slice_type",
FT_UINT32, BASE_DEC, VALS(h264_slice_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_h264_slice_id,
{ "slice_id", "h264.slice_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_payloadsize,
{ "PayloadSize", "h264.payloadsize",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_payloadtype,
{ "payloadType", "h264.payloadtype",
FT_UINT32, BASE_DEC, VALS(h264_sei_payload_vals), 0x0,
NULL, HFILL }
},
#if 0
{ &hf_h264_frame_num,
{ "frame_num", "h264.frame_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_h264_par_profile,
{ "Profile", "h264.par_profile",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}},
{ &hf_h264_par_profile_b,
{ "Baseline Profile", "h264.par_profile.base",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_h264_par_profile_m,
{ "Main Profile", "h264.par_profile.main",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}},
{ &hf_h264_par_profile_e,
{ "Extended Profile.", "h264.par_profile.ext",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}},
{ &hf_h264_par_profile_h,
{ "High Profile", "h264.par_profile.high",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL}},
{ &hf_h264_par_profile_h10,
{ "High 10 Profile", "h264.par_profile.high10",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL}},
{ &hf_h264_par_profile_h4_2_2,
{ "High 4:2:2 Profile", "h264.par_profile.high4_2_2",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}},
{ &hf_h264_par_profile_h4_4_4,
{ "High 4:4:4 Profile", "h264.par_profile.high4_4_4",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}},
{ &hf_h264_par_AdditionalModesSupported,
{ "AdditionalModesSupported", "h264.AdditionalModesSupported",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}},
#if 0
{ &hf_h264_par_add_mode_sup,
{ "Additional Modes Supported", "h264.add_mode_sup",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}},
#endif
{ &hf_h264_par_add_mode_sup_rcdo,
{ "Reduced Complexity Decoding Operation (RCDO) support", "h264.add_mode_sup.rcdo",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_h264_par_ProfileIOP,
{ "ProfileIOP", "h264.ProfileIOP",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}},
{ &hf_h264_par_constraint_set0_flag,
{ "constraint_set0_flag", "h264.par.constraint_set0_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}},
{ &hf_h264_par_constraint_set1_flag,
{ "constraint_set1_flag", "h264.par.constraint_set1_flag",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_h264_par_constraint_set2_flag,
{ "constraint_set2_flag", "h264.par.constraint_set2_flag",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}},
{ &hf_h264_nalu_size,
{ "NAL Unit Size", "h264.nalu_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_don,
{ "Decoder Order Number", "h264.don",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_dond,
{ "MTAP Decoder Order Number Delta", "h264.don_delta",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_ts_offset16,
{ "MTAP TS Offset", "h264.ts_offset16",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_ts_offset24,
{ "MTAP TS Offset", "h264.ts_offset24",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_nal_extension_subtype,
{ "Extension Header Subtype", "h264.nal_hdr_extension.subtype",
FT_UINT8, BASE_DEC, VALS(h264_subtype_values), 0xF8,
NULL, HFILL }
},
{ &hf_h264_nal_extension_j,
{ "Extension Header J - DON Present Indicator", "h264.nal_hdr_extension.j",
FT_BOOLEAN, 8, NULL, 0x4,
NULL, HFILL }
},
{ &hf_h264_nal_extension_k,
{ "Extension Header K", "h264.nal_hdr_extension.k",
FT_BOOLEAN, 8, NULL, 0x2,
NULL, HFILL }
},
{ &hf_h264_nal_extension_l,
{ "Extension Header L", "h264.nal_hdr_extension.l",
FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL }
},
{ &hf_h264_sei_uuid,
{ "UUID", "h264.sei.uuid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_lpb,
{ "Layer Presence", "h264.sei.ms.layout.lpb",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layout_p,
{ "Layer Description Present", "h264.sei.ms.layout.p",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layout_ldsize,
{ "Layer Description Size", "h264.sei.ms.layout.desc.ldsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_coded_width,
{ "Coded Width", "h264.sei.ms.layout.desc.coded_width",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_coded_height,
{ "Coded Height", "h264.sei.ms.layout.desc.coded_height",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_display_width,
{ "Display Width", "h264.sei.ms.layout.desc.display_width",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_display_height,
{ "Display Height", "h264.sei.ms.layout.desc.display_height",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_bitrate,
{ "Bitrate", "h264.sei.ms.layout.desc.bitrate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_frame_rate,
{ "Frame Rate Index", "h264.sei.ms.layout.desc.frame_rate",
FT_UINT8, BASE_DEC, VALS(h264_sei_ms_frame_values), 0xF8,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_layer_type,
{ "Layer Type", "h264.sei.ms.layout.desc.layer_type",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_prid,
{ "Priority ID", "h264.sei.ms.layout.desc.prid",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL }
},
{ &hf_h264_sei_ms_layer_desc_cb,
{ "Constrained Baseline", "h264.sei.ms.layout.desc.constrained_baseline",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_h264_sei_ms_bitstream_ref_frame_cnt,
{ "Reference Frame Count", "h264.sei.ms.bitstream_info.ref_frm_cnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_bitstream_num_nalus,
{ "Number of NAL units", "h264.sei.ms.bitstrea3416m_info.num_nalus",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_iso_sec_info,
{ "Unparsed iso_iec information", "h264.sei.iso_sec_info",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_num_data,
{ "Number of Data Entries", "h264.sei.ms.crop.num_data",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_info_type,
{ "Info Type", "h264.sei.ms.crop.info_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_confidence_level,
{ "Confidence Level", "h264.sei.ms.crop.confidence_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_frame_left_offset,
{ "Left Offset", "h264.sei.ms.crop.left_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_frame_right_offset,
{ "Right Offset", "h264.sei.ms.crop.right_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_frame_top_offset,
{ "Top Offset", "h264.sei.ms.crop.top_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_sei_ms_crop_frame_bottom_offset,
{ "Bottom Offset", "h264.sei.ms.crop.bottom_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_svc,
{ "SVC Extension / Reserved", "h264.nal_hdr_ext.r",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_i,
{ "IDR Picture", "h264.nal_hdr_ext.i",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_prid,
{ "Priority ID", "h264.nal_hdr_ext.prid",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_n,
{ "No Inter Layer Prediction", "h264.nal_hdr_ext.n",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_did,
{ "Dependency ID", "h264.nal_hdr_ext.did",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_qid,
{ "Quality ID", "h264.nal_hdr_ext.qid",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_tid,
{ "Temporal ID", "h264.nal_hdr_ext.tid",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_u,
{ "Use Ref Base Picture", "h264.nal_hdr_ext.u",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_d,
{ "Discardable", "h264.nal_hdr_ext.d",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_o,
{ "Output", "h264.nal_hdr_ext.o",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_h264_nal_hdr_ext_rr,
{ "Reserved", "h264.nal_hdr_ext.rr",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }
},
{ &hf_h264_pacsi_x,
{ "X - A,P,C Field Indicator", "h264.pacsi.x",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_h264_pacsi_y,
{ "Y - Pic Fields Indicator", "h264.pacsi.y",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_h264_pacsi_t,
{ "T - DONC Field Indicator", "h264.pacsi.t",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_h264_pacsi_a,
{ "A - Anchor Layer", "h264.pacsi.a",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_h264_pacsi_p,
{ "P - Redundant Slice", "h264.pacsi.p",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_h264_pacsi_c,
{ "C - Intra Slice", "h264.pacsi.c",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_h264_pacsi_s,
{ "S - First Nal Unit of Layer", "h264.pacsi.s",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_h264_pacsi_e,
{ "E - Last Nal Unit of Layer", "h264.pacsi.e",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_h264_pacsi_tl0picidx,
{ "TL0PICIDX", "h264.pacsi.tl0picidx",
FT_UINT8, BASE_DEC, NULL, 0xFF,
NULL, HFILL }
},
{ &hf_h264_pacsi_idrpicid,
{ "IDRPICID - IDR Picture ID", "h264.pacsi.idrpicid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_h264_pacsi_donc,
{ "DONC - Cross Session Decoder Order Number", "h264.pacsi.donc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_h264,
&ett_h264_profile,
&ett_h264_nal,
&ett_h264_fua,
&ett_h264_stream,
&ett_h264_nal_unit,
&ett_h264_par_profile,
&ett_h264_par_AdditionalModesSupported,
&ett_h264_par_ProfileIOP,
&ett_h264_ms_layer_description,
&ett_h264_ms_crop_data,
&ett_h264_ni_mtap
};
static ei_register_info ei[] = {
{ &ei_h264_undecoded, { "h264.undecoded", PI_UNDECODED, PI_WARN, "[Not decoded yet]", EXPFILL }},
{ &ei_h264_ms_layout_wrong_length, { "h264.ms_layout.wrong_length", PI_PROTOCOL, PI_WARN, "[Wrong Layer Description Table Length]", EXPFILL }},
{ &ei_h264_bad_nal_length, { "h264.bad_nalu_length", PI_MALFORMED, PI_ERROR, "[Bad NAL Unit Length]", EXPFILL }},
{ &ei_h264_nal_unit_type_reserved, { "h264.nal_unit_type.reserved", PI_PROTOCOL, PI_WARN, "Reserved NAL unit type", EXPFILL }},
{ &ei_h264_nal_unit_type_unspecified, { "h264.nal_unit_type.unspecified", PI_PROTOCOL, PI_WARN, "Unspecified NAL unit type", EXPFILL }},
};
proto_h264 = proto_register_protocol("H.264","H264", "h264");
proto_register_field_array(proto_h264, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_h264 = expert_register_protocol(proto_h264);
expert_register_field_array(expert_h264, ei, array_length(ei));
h264_module = prefs_register_protocol(proto_h264, proto_reg_handoff_h264);
prefs_register_range_preference(h264_module, "dynamic.payload.type",
"H264 dynamic payload types",
"Dynamic payload types which will be interpreted as H264"
"; Values must be in the range 96 - 127",
&temp_dynamic_payload_type_range, 127);
register_dissector("h264", dissect_h264, proto_h264);
}
void
proto_reg_handoff_h264(void)
{
static range_t *dynamic_payload_type_range = NULL;
static gboolean h264_prefs_initialized = FALSE;
if (!h264_prefs_initialized) {
dissector_handle_t h264_name_handle;
h264_capability_t *ftr;
h264_handle = find_dissector("h264");
dissector_add_string("rtp_dyn_payload_type","H264", h264_handle);
dissector_add_string("rtp_dyn_payload_type","H264-SVC", h264_handle);
dissector_add_string("rtp_dyn_payload_type","X-H264UC", h264_handle);
h264_name_handle = create_dissector_handle(dissect_h264_name, proto_h264);
for (ftr=h264_capability_tab; ftr->id; ftr++) {
if (ftr->name)
dissector_add_string("h245.gef.name", ftr->id, h264_name_handle);
if (ftr->content_pdu)
dissector_add_string("h245.gef.content", ftr->id, create_dissector_handle(ftr->content_pdu, proto_h264));
}
h264_prefs_initialized = TRUE;
} else {
range_foreach(dynamic_payload_type_range, range_delete_h264_rtp_pt_callback);
g_free(dynamic_payload_type_range);
}
dynamic_payload_type_range = range_copy(temp_dynamic_payload_type_range);
range_foreach(dynamic_payload_type_range, range_add_h264_rtp_pt_callback);
}
