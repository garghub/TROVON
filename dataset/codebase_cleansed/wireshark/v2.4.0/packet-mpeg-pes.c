static int
dissect_mpeg_pes_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_mpeg_pes_T_stream(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_PES(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_PES, PES_sequence);
return offset;
}
static int
dissect_mpeg_pes_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_mpeg_pes_T_scrambling_control(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_Stream(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_Stream, Stream_sequence);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
12, 12, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_T_aspect_ratio(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_T_frame_rate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, FALSE, 0, T_frame_rate_value_map);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
18, 18, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_Sequence_header(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_Sequence_header, Sequence_header_sequence);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_Sequence_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_Sequence_extension, Sequence_extension_sequence);
return offset;
}
static int
dissect_mpeg_pes_INTEGER_0_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_INTEGER_0_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_5(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
5, 5, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_Group_of_pictures(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_Group_of_pictures, Group_of_pictures_sequence);
return offset;
}
static int
dissect_mpeg_pes_T_frame_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_pes_BIT_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_pes_Picture(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_pes_Picture, Picture_sequence);
return offset;
}
static guint64 decode_time_stamp(tvbuff_t *tvb, gint offset, nstime_t *nst)
{
guint64 bytes = tvb_get_ntoh40(tvb, offset);
guint64 ts =
(bytes >> 33 & 0x0007) << 30 |
(bytes >> 17 & 0x7fff) << 15 |
(bytes >> 1 & 0x7fff) << 0;
unsigned int rem = (unsigned int)(ts % TSHZ);
nst->secs = (time_t)(ts / TSHZ);
nst->nsecs = (int)(G_GINT64_CONSTANT(1000000000) * rem / TSHZ);
return ts;
}
static guint64 decode_clock_reference(tvbuff_t *tvb, gint offset,
nstime_t *nst)
{
guint64 bytes = tvb_get_ntoh48(tvb, offset);
guint64 ts =
(bytes >> 43 & 0x0007) << 30 |
(bytes >> 27 & 0x7fff) << 15 |
(bytes >> 11 & 0x7fff) << 0;
unsigned int ext = (unsigned int)((bytes >> 1) & 0x1ff);
guint64 cr = 300 * ts + ext;
unsigned int rem = (unsigned int)(cr % SCRHZ);
nst->secs = (time_t)(cr / SCRHZ);
nst->nsecs = (int)(G_GINT64_CONSTANT(1000000000) * rem / SCRHZ);
return cr;
}
static int
dissect_mpeg_pes_header_data(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *root, unsigned int flags)
{
proto_item *item = proto_tree_add_item(root, hf_mpeg_pes_header_data, tvb,
0, -1, ENC_NA);
proto_tree *tree = proto_item_add_subtree(item, ett_mpeg_pes_header_data);
gint offset = 0;
if (flags & PTS_FLAG) {
nstime_t nst;
decode_time_stamp(tvb, offset, &nst);
proto_tree_add_time(tree, hf_mpeg_pes_pts, tvb,
offset, 5, &nst);
offset += 5;
}
if (flags & DTS_FLAG) {
nstime_t nst;
decode_time_stamp(tvb, offset, &nst);
proto_tree_add_time(tree, hf_mpeg_pes_dts, tvb,
offset, 5, &nst);
offset += 5;
}
if (flags & ESCR_FLAG) {
nstime_t nst;
decode_clock_reference(tvb, offset, &nst);
proto_tree_add_time(tree, hf_mpeg_pes_escr, tvb,
offset, 6, &nst);
offset += 6;
}
if (flags & ES_RATE_FLAG) {
unsigned int es_rate = (tvb_get_ntohs(tvb, offset) >> 1 & 0x3fff) * 50;
proto_tree_add_uint(tree, hf_mpeg_pes_es_rate, tvb,
offset, 3, es_rate);
offset += 3;
}
if (flags & DSM_TRICK_MODE_FLAG)
{
guint8 value = tvb_get_guint8(tvb, offset);
guint8 control;
proto_tree *trick_tree;
proto_item *trick_item;
trick_item = proto_tree_add_item(item,
hf_mpeg_pes_dsm_trick_mode, tvb,
offset, 1, ENC_NA);
trick_tree = proto_item_add_subtree(trick_item,
ett_mpeg_pes_trick_mode);
control = (value >> 5);
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_control, tvb,
offset, 1,
control);
if (control == FAST_FORWARD_CONTROL
|| control == FAST_REVERSE_CONTROL)
{
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_field_id, tvb,
offset, 1,
(value & 0x18) >> 3);
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_intra_slice_refresh, tvb,
offset, 1,
(value & 0x04) >> 2);
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_frequency_truncation, tvb,
offset, 1,
(value & 0x03));
}
else if (control == SLOW_MOTION_CONTROL
|| control == SLOW_REVERSE_CONTROL)
{
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_rep_cntrl, tvb,
offset, 1,
(value & 0x1F));
}
else if (control == FREEZE_FRAME_CONTROL)
{
proto_tree_add_uint(trick_tree,
hf_mpeg_pes_dsm_trick_mode_field_id, tvb,
offset, 1,
(value & 0x18) >> 3);
}
offset += 1;
}
if (flags & COPY_INFO_FLAG) {
proto_tree_add_item(tree, hf_mpeg_pes_copy_info, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (flags & CRC_FLAG) {
proto_tree_add_item(tree, hf_mpeg_pes_crc, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (flags & EXTENSION_FLAG) {
int flags2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mpeg_pes_extension_flags, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
if (flags2 & PRIVATE_DATA_FLAG) {
proto_tree_add_item(tree, hf_mpeg_pes_private_data, tvb,
offset, 16, ENC_NA);
offset += 16;
}
if (flags2 & PACK_LENGTH_FLAG) {
proto_tree_add_item(tree, hf_mpeg_pes_pack_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (flags2 & SEQUENCE_FLAG) {
proto_tree_add_item(tree, hf_mpeg_pes_sequence, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (flags2 & PSTD_BUFFER_FLAG) {
unsigned int pstd = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_mpeg_pes_pstd_buffer, tvb,
offset, 2, (pstd & 0x2000 ? 1024 : 128) * (pstd & 0x1ff));
offset += 2;
}
if (flags2 & EXTENSION_FLAG2) {
proto_tree_add_item(tree, hf_mpeg_pes_extension2, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
return offset;
}
static gint
dissect_mpeg_pes_pack_header(tvbuff_t *tvb, gint offset,
packet_info *pinfo _U_, proto_tree *root)
{
unsigned int program_mux_rate, stuffing_length;
proto_item *item = proto_tree_add_item(root, hf_mpeg_pes_pack_header, tvb,
offset / 8, 10, ENC_NA);
proto_tree *tree = proto_item_add_subtree(item, ett_mpeg_pes_pack_header);
nstime_t nst;
decode_clock_reference(tvb, offset / 8, &nst);
proto_tree_add_time(tree, hf_mpeg_pes_scr, tvb, offset / 8, 6, &nst);
offset += 6 * 8;
program_mux_rate = (tvb_get_ntoh24(tvb, offset / 8) >> 2) * 50;
proto_tree_add_uint(tree, hf_mpeg_pes_program_mux_rate, tvb, offset / 8, 3,
program_mux_rate);
offset += 3 * 8;
stuffing_length = tvb_get_guint8(tvb, offset / 8) & 0x07;
proto_tree_add_item(tree, hf_mpeg_pes_stuffing_length, tvb,
offset / 8, 1, ENC_BIG_ENDIAN);
offset += 1 * 8;
if (stuffing_length > 0) {
proto_tree_add_item(tree, hf_mpeg_pes_stuffing, tvb,
offset / 8, stuffing_length, ENC_NA);
offset += stuffing_length * 8;
}
return offset;
}
static gboolean
dissect_mpeg_pes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int prefix;
int stream;
asn1_ctx_t asn1_ctx;
gint offset = 0;
if (!tvb_bytes_exist(tvb, 0, 3))
return FALSE;
prefix = tvb_get_ntoh24(tvb, 0);
if (prefix != PES_PREFIX)
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPEG PES");
col_clear(pinfo->cinfo, COL_INFO);
stream = tvb_get_guint8(tvb, 3);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(stream, mpeg_pes_T_stream_vals, "Unknown stream: %d"));
#if 0
if (tree == NULL)
return TRUE;
#endif
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_mpeg_pes_PES(tvb, offset, &asn1_ctx,
tree, proto_mpeg_pes);
if (stream == STREAM_PICTURE) {
int frame_type;
frame_type = tvb_get_guint8(tvb, 5) >> 3 & 0x07;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(frame_type, mpeg_pes_T_frame_type_vals, "Unknown frame type: %d"));
offset = dissect_mpeg_pes_Picture(tvb, offset, &asn1_ctx,
tree, hf_mpeg_video_picture);
proto_tree_add_item(tree, hf_mpeg_video_data, tvb,
offset / 8, -1, ENC_NA);
} else if (stream == STREAM_SEQUENCE) {
tvbuff_t *es;
offset = dissect_mpeg_pes_Sequence_header(tvb, offset, &asn1_ctx,
tree, hf_mpeg_video_sequence_header);
proto_tree_add_item(tree, hf_mpeg_video_quantization_matrix, tvb,
offset / 8, 64, ENC_NA);
offset += 64 * 8;
es = tvb_new_subset_remaining(tvb, offset / 8);
dissect_mpeg_pes(es, pinfo, tree, NULL);
} else if (stream == STREAM_SEQUENCE_EXTENSION) {
tvbuff_t *es;
offset = dissect_mpeg_pes_Sequence_extension(tvb, offset, &asn1_ctx,
tree, hf_mpeg_video_sequence_extension);
es = tvb_new_subset_remaining(tvb, offset / 8);
dissect_mpeg_pes(es, pinfo, tree, NULL);
} else if (stream == STREAM_GOP) {
tvbuff_t *es;
offset = dissect_mpeg_pes_Group_of_pictures(tvb, offset, &asn1_ctx,
tree, hf_mpeg_video_group_of_pictures);
es = tvb_new_subset_remaining(tvb, offset / 8);
dissect_mpeg_pes(es, pinfo, tree, NULL);
} else if (stream == STREAM_PACK) {
if (tvb_get_guint8(tvb, offset / 8) >> 6 == 1) {
dissect_mpeg_pes_pack_header(tvb, offset, pinfo, tree);
} else {
proto_tree_add_item(tree, hf_mpeg_pes_data, tvb,
offset / 8, 8, ENC_NA);
}
} else if (stream == STREAM_SYSTEM || stream == STREAM_PRIVATE2) {
unsigned int data_length = tvb_get_ntohs(tvb, offset / 8);
proto_tree_add_item(tree, hf_mpeg_pes_length, tvb,
offset / 8, 2, ENC_BIG_ENDIAN);
offset += 2 * 8;
proto_tree_add_item(tree, hf_mpeg_pes_data, tvb,
offset / 8, data_length, ENC_NA);
} else if (stream == STREAM_PADDING) {
unsigned int padding_length = tvb_get_ntohs(tvb, offset / 8);
proto_tree_add_item(tree, hf_mpeg_pes_length, tvb,
offset / 8, 2, ENC_BIG_ENDIAN);
offset += 2 * 8;
proto_tree_add_item(tree, hf_mpeg_pes_padding, tvb,
offset / 8, padding_length, ENC_NA);
} else if (stream == STREAM_PRIVATE1
|| stream >= STREAM_AUDIO) {
int length = tvb_get_ntohs(tvb, 4);
if ((tvb_get_guint8(tvb, 6) & 0xc0) == 0x80) {
int header_length;
tvbuff_t *es;
offset = dissect_mpeg_pes_Stream(tvb, offset, &asn1_ctx,
tree, hf_mpeg_pes_extension);
if(length !=0 && stream != STREAM_VIDEO){
length -= 5;
}
header_length = tvb_get_guint8(tvb, 8);
if (header_length > 0) {
int flags = tvb_get_guint8(tvb, 7);
tvbuff_t *header_data = tvb_new_subset_length(tvb, offset / 8,
header_length);
dissect_mpeg_pes_header_data(header_data, pinfo, tree, flags);
offset += header_length * 8;
if(length !=0 && stream != STREAM_VIDEO){
length -= header_length;
}
}
if(length==0){
proto_tree_add_item(tree, hf_mpeg_pes_data, tvb, (offset>>3),-1, ENC_NA);
return TRUE;
}
es = tvb_new_subset_length_caplen(tvb, offset / 8, -1, length);
if (tvb_get_ntoh24(es, 0) == PES_PREFIX)
dissect_mpeg_pes(es, pinfo, tree, NULL);
else if (tvb_get_guint8(es, 0) == 0xff)
dissect_mpeg(es, pinfo, tree, data);
else
proto_tree_add_item(tree, hf_mpeg_pes_data, es,
0, -1, ENC_NA);
} else {
unsigned int data_length = tvb_get_ntohs(tvb, offset / 8);
proto_tree_add_item(tree, hf_mpeg_pes_length, tvb,
offset / 8, 2, ENC_BIG_ENDIAN);
offset += 2 * 8;
proto_tree_add_item(tree, hf_mpeg_pes_data, tvb,
offset / 8, data_length, ENC_NA);
}
} else {
proto_tree_add_item(tree, hf_mpeg_pes_data, tvb,
offset / 8, -1, ENC_NA);
}
return TRUE;
}
static int
dissect_mpeg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
heur_dtbl_entry_t *hdtbl_entry;
if (!dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, NULL)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPEG");
col_clear(pinfo->cinfo, COL_INFO);
proto_tree_add_item(tree, proto_mpeg, tvb, 0, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
void
proto_register_mpeg_pes(void)
{
static hf_register_info hf[] = {
#line 1 "./asn1/mpeg-pes/packet-mpeg-pes-hfarr.c"
{ &hf_mpeg_pes_prefix,
{ "prefix", "mpeg-pes.prefix",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_mpeg_pes_stream,
{ "stream", "mpeg-pes.stream",
FT_UINT8, BASE_HEX, VALS(mpeg_pes_T_stream_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_pes_length,
{ "length", "mpeg-pes.length",
FT_UINT16, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_mpeg_pes_must_be_one,
{ "must-be-one", "mpeg-pes.must_be_one",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_must_be_zero,
{ "must-be-zero", "mpeg-pes.must_be_zero",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_scrambling_control,
{ "scrambling-control", "mpeg-pes.scrambling_control",
FT_UINT32, BASE_DEC, VALS(mpeg_pes_T_scrambling_control_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_pes_priority,
{ "priority", "mpeg-pes.priority",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_data_alignment,
{ "data-alignment", "mpeg-pes.data_alignment",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_copyright,
{ "copyright", "mpeg-pes.copyright",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_original,
{ "original", "mpeg-pes.original",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_pts_flag,
{ "pts-flag", "mpeg-pes.pts_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_dts_flag,
{ "dts-flag", "mpeg-pes.dts_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_escr_flag,
{ "escr-flag", "mpeg-pes.escr_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_es_rate_flag,
{ "es-rate-flag", "mpeg-pes.es_rate_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_flag,
{ "dsm-trick-mode-flag", "mpeg-pes.dsm_trick_mode_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_additional_copy_info_flag,
{ "additional-copy-info-flag", "mpeg-pes.additional_copy_info_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_crc_flag,
{ "crc-flag", "mpeg-pes.crc_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_extension_flag,
{ "extension-flag", "mpeg-pes.extension_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_header_data_length,
{ "header-data-length", "mpeg-pes.header_data_length",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_mpeg_pes_horizontal_size,
{ "horizontal-size", "mpeg-pes.horizontal_size",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_12", HFILL }},
{ &hf_mpeg_pes_vertical_size,
{ "vertical-size", "mpeg-pes.vertical_size",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_12", HFILL }},
{ &hf_mpeg_pes_aspect_ratio,
{ "aspect-ratio", "mpeg-pes.aspect_ratio",
FT_UINT32, BASE_DEC, VALS(mpeg_pes_T_aspect_ratio_vals), 0,
"T_aspect_ratio", HFILL }},
{ &hf_mpeg_pes_frame_rate,
{ "frame-rate", "mpeg-pes.frame_rate",
FT_UINT32, BASE_DEC, VALS(mpeg_pes_T_frame_rate_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_pes_bit_rate,
{ "bit-rate", "mpeg-pes.bit_rate",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_18", HFILL }},
{ &hf_mpeg_pes_vbv_buffer_size,
{ "vbv-buffer-size", "mpeg-pes.vbv_buffer_size",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_10", HFILL }},
{ &hf_mpeg_pes_constrained_parameters_flag,
{ "constrained-parameters-flag", "mpeg-pes.constrained_parameters_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_load_intra_quantiser_matrix,
{ "load-intra-quantiser-matrix", "mpeg-pes.load_intra_quantiser_matrix",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_load_non_intra_quantiser_matrix,
{ "load-non-intra-quantiser-matrix", "mpeg-pes.load_non_intra_quantiser_matrix",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_must_be_0001,
{ "must-be-0001", "mpeg-pes.must_be_0001",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_mpeg_pes_profile_and_level,
{ "profile-and-level", "mpeg-pes.profile_and_level",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_mpeg_pes_progressive_sequence,
{ "progressive-sequence", "mpeg-pes.progressive_sequence",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_chroma_format,
{ "chroma-format", "mpeg-pes.chroma_format",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_pes_horizontal_size_extension,
{ "horizontal-size-extension", "mpeg-pes.horizontal_size_extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_pes_vertical_size_extension,
{ "vertical-size-extension", "mpeg-pes.vertical_size_extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_pes_bit_rate_extension,
{ "bit-rate-extension", "mpeg-pes.bit_rate_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_12", HFILL }},
{ &hf_mpeg_pes_vbv_buffer_size_extension,
{ "vbv-buffer-size-extension", "mpeg-pes.vbv_buffer_size_extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_mpeg_pes_low_delay,
{ "low-delay", "mpeg-pes.low_delay",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_frame_rate_extension_n,
{ "frame-rate-extension-n", "mpeg-pes.frame_rate_extension_n",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_pes_frame_rate_extension_d,
{ "frame-rate-extension-d", "mpeg-pes.frame_rate_extension_d",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_pes_drop_frame_flag,
{ "drop-frame-flag", "mpeg-pes.drop_frame_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_hour,
{ "hour", "mpeg-pes.hour",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32", HFILL }},
{ &hf_mpeg_pes_minute,
{ "minute", "mpeg-pes.minute",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_64", HFILL }},
{ &hf_mpeg_pes_second,
{ "second", "mpeg-pes.second",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_64", HFILL }},
{ &hf_mpeg_pes_frame,
{ "frame", "mpeg-pes.frame",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_64", HFILL }},
{ &hf_mpeg_pes_closed_gop,
{ "closed-gop", "mpeg-pes.closed_gop",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_broken_gop,
{ "broken-gop", "mpeg-pes.broken_gop",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_pes_must_be_zero_01,
{ "must-be-zero", "mpeg-pes.must_be_zero",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_5", HFILL }},
{ &hf_mpeg_pes_temporal_sequence_number,
{ "temporal-sequence-number", "mpeg-pes.temporal_sequence_number",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_10", HFILL }},
{ &hf_mpeg_pes_frame_type,
{ "frame-type", "mpeg-pes.frame_type",
FT_UINT32, BASE_DEC, VALS(mpeg_pes_T_frame_type_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_pes_vbv_delay,
{ "vbv-delay", "mpeg-pes.vbv_delay",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
#line 544 "./asn1/mpeg-pes/packet-mpeg-pes-template.c"
{ &hf_mpeg_pes_pack_header,
{ "Pack header", "mpeg-pes.pack",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_scr,
{ "system clock reference (SCR)", "mpeg-pes.scr",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_program_mux_rate,
{ "PES program mux rate", "mpeg-pes.program-mux-rate",
FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_stuffing_length,
{ "PES stuffing length", "mpeg-pes.stuffing-length",
FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }},
{ &hf_mpeg_pes_stuffing,
{ "PES stuffing bytes", "mpeg-pes.stuffing",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_extension,
{ "PES extension", "mpeg-pes.extension",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_header_data,
{ "PES header data", "mpeg-pes.header-data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_pts,
{ "presentation time stamp (PTS)", "mpeg-pes.pts",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_dts,
{ "decode time stamp (DTS)", "mpeg-pes.dts",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_escr,
{ "elementary stream clock reference (ESCR)", "mpeg-pes.escr",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_es_rate,
{ "elementary stream rate", "mpeg-pes.es-rate",
FT_UINT24, BASE_DEC, NULL, 0x7ffe, NULL, HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode,
{ "Trick mode", "mpeg-pes.trick-mode",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_control,
{ "control", "mpeg-pes.trick-mode-control",
FT_UINT8, BASE_HEX, VALS(mpeg_pes_TrickModeControl_vals), 0,
"mpeg_pes trick mode control", HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_field_id,
{ "field id", "mpeg-pes.trick-mode-field-id",
FT_UINT8, BASE_HEX, VALS(mpeg_pes_TrickModeFieldId_vals), 0,
"mpeg_pes trick mode field id", HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_intra_slice_refresh,
{ "intra slice refresh", "mpeg-pes.trick-mode-intra-slice-refresh",
FT_UINT8, BASE_HEX, VALS(mpeg_pes_TrickModeIntraSliceRefresh_vals), 0,
"mpeg_pes trick mode intra slice refresh", HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_frequency_truncation,
{ "frequency truncation", "mpeg-pes.trick-mode-frequency-truncation",
FT_UINT8, BASE_HEX, VALS(mpeg_pes_TrickModeFrequencyTruncation_vals), 0,
"mpeg_pes trick mode frequency truncation", HFILL }},
{ &hf_mpeg_pes_dsm_trick_mode_rep_cntrl,
{ "rep cntrl", "mpeg-pes.trick-mode-rep-cntrl",
FT_UINT8, BASE_HEX, NULL, 0, "mpeg_pes trick mode rep cntrl", HFILL }},
{ &hf_mpeg_pes_copy_info,
{ "copy info", "mpeg-pes.copy-info",
FT_UINT8, BASE_DEC, NULL, 0x7f, NULL, HFILL }},
{ &hf_mpeg_pes_crc,
{ "CRC", "mpeg-pes.crc",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_extension_flags,
{ "extension flags", "mpeg-pes.extension-flags",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_private_data,
{ "private data", "mpeg-pes.private-data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_pack_length,
{ "pack length", "mpeg-pes.pack-length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_sequence,
{ "sequence", "mpeg-pes.sequence",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_pstd_buffer,
{ "P-STD buffer size", "mpeg-pes.pstd-buffer",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_extension2,
{ "extension2", "mpeg-pes.extension2",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_padding,
{ "PES padding", "mpeg-pes.padding",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_pes_data,
{ "PES data", "mpeg-pes.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_sequence_header,
{ "MPEG sequence header", "mpeg-video.sequence",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_sequence_extension,
{ "MPEG sequence extension", "mpeg-video.sequence-ext",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_group_of_pictures,
{ "MPEG group of pictures", "mpeg-video.gop",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_picture,
{ "MPEG picture", "mpeg-video.picture",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_quantization_matrix,
{ "MPEG quantization matrix", "mpeg-video.quant",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_video_data,
{ "MPEG picture data", "mpeg-video.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
#line 1 "./asn1/mpeg-pes/packet-mpeg-pes-ettarr.c"
&ett_mpeg_pes_PES,
&ett_mpeg_pes_Stream,
&ett_mpeg_pes_Sequence_header,
&ett_mpeg_pes_Sequence_extension,
&ett_mpeg_pes_Group_of_pictures,
&ett_mpeg_pes_Picture,
#line 651 "./asn1/mpeg-pes/packet-mpeg-pes-template.c"
&ett_mpeg_pes_pack_header,
&ett_mpeg_pes_header_data,
&ett_mpeg_pes_trick_mode
};
proto_mpeg = proto_register_protocol(
"Moving Picture Experts Group", "MPEG", "mpeg");
mpeg_handle = register_dissector("mpeg", dissect_mpeg, proto_mpeg);
heur_subdissector_list = register_heur_dissector_list("mpeg", proto_mpeg);
proto_mpeg_pes = proto_register_protocol(
"Packetized Elementary Stream", "MPEG PES", "mpeg-pes");
proto_register_field_array(proto_mpeg_pes, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mpeg-pes", dissect_mpeg_pes, proto_mpeg_pes);
}
void
proto_reg_handoff_mpeg_pes(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_MPEG, mpeg_handle);
heur_dissector_add("mpeg", dissect_mpeg_pes, "MPEG PES", "mpeg_pes", proto_mpeg_pes, HEURISTIC_ENABLE);
}
