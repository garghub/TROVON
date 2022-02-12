static void
process_marker_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bytes_format_value(subtree, hf_remain_seg_data, tvb, 4, -1, NULL, "%u bytes", len - 2);
}
static void
process_sof_header(proto_tree *tree, tvbuff_t *tvb, guint32 len _U_,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
guint8 count;
guint32 offset;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_sof_header,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_precision, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_lines, tvb, 5, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_samples_per_line, tvb, 7, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_nf, tvb, 9, 1, ENC_BIG_ENDIAN);
count = tvb_get_guint8(tvb, 9);
offset = 10;
while (count > 0) {
proto_tree_add_item(subtree, hf_sof_c_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_h_i, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_v_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_tq_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
count--;
}
}
static void
process_sos_header(proto_tree *tree, tvbuff_t *tvb, guint32 len _U_,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
guint8 count;
guint32 offset;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_sos_header,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ns, tvb, 4, 1, ENC_BIG_ENDIAN);
count = tvb_get_guint8(tvb, 4);
offset = 5;
while (count > 0) {
proto_tree_add_item(subtree, hf_sos_cs_j, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_td_j, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ta_j, tvb, offset++, 1, ENC_BIG_ENDIAN);
count--;
}
proto_tree_add_item(subtree, hf_sos_ss, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_se, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ah, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_al, tvb, offset, 1, ENC_BIG_ENDIAN);
;
}
static void
process_comment_header(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_comment_header,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_comment, tvb, 4, len-2, ENC_ASCII|ENC_NA);
}
static int
process_app0_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
proto_tree *subtree_details = NULL;
guint32 offset;
char *str;
gint str_size;
guint16 x, y;
if (!tree)
return 0;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
str = tvb_get_stringz_enc(wmem_packet_scope(), tvb, 4, &str_size, ENC_ASCII);
ti = proto_tree_add_item(subtree, hf_identifier, tvb, 4, str_size, ENC_ASCII|ENC_NA);
if (strcmp(str, "JFIF") == 0) {
ti = proto_tree_add_none_format(subtree, hf_version,
tvb, 9, 2, "Version: %u.%u",
tvb_get_guint8(tvb, 9),
tvb_get_guint8(tvb, 10));
subtree_details = proto_item_add_subtree(ti, ett_details);
proto_tree_add_item(subtree_details, hf_version_major,
tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree_details, hf_version_minor,
tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_units,
tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_xdensity,
tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ydensity,
tvb, 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_xthumbnail,
tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ythumbnail,
tvb, 17, 1, ENC_BIG_ENDIAN);
x = tvb_get_guint8(tvb, 16);
y = tvb_get_guint8(tvb, 17);
if (x || y) {
proto_tree_add_item(subtree, hf_rgb,
tvb, 18, 3 * (x * y), ENC_NA);
offset = 18 + (3 * (x * y));
} else {
offset = 18;
}
}
else if (strcmp(str, "JFXX") == 0) {
proto_tree_add_item(subtree, hf_extension_code,
tvb, 9, 1, ENC_BIG_ENDIAN);
offset = 10;
}
else {
proto_item_append_text(ti, " (unknown identifier)");
offset = 4 + str_size;
proto_tree_add_bytes_format_value(subtree, hf_remain_seg_data, tvb, offset, -1, NULL, "%u bytes", len - 2 - str_size);
}
return offset;
}
static int
process_app1_segment(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 len,
guint16 marker, const char *marker_name, gboolean show_first_identifier_not_jfif)
{
proto_item *ti;
proto_tree *subtree;
char *str;
gint str_size;
int offset = 0;
int tiff_start;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
str = tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &str_size, ENC_ASCII);
ti = proto_tree_add_item(subtree, hf_identifier, tvb, offset, str_size, ENC_ASCII|ENC_NA);
offset += str_size;
if (show_first_identifier_not_jfif && strcmp(str, "JFIF") != 0) {
expert_add_info(pinfo, ti, &ei_file_jpeg_first_identifier_not_jfif);
}
if (strcmp(str, "Exif") == 0) {
int encoding;
guint16 val_16;
guint32 val_32, num_fields;
proto_item* tiff_item;
offset++;
tiff_start = offset;
val_16 = tvb_get_ntohs(tvb, offset);
if (val_16 == 0x4949) {
encoding = ENC_LITTLE_ENDIAN;
proto_tree_add_uint_format_value(subtree, hf_endianness, tvb, offset, 2, val_16, "little endian");
} else if (val_16 == 0x4D4D) {
encoding = ENC_BIG_ENDIAN;
proto_tree_add_uint_format_value(subtree, hf_endianness, tvb, offset, 2, val_16, "big endian");
} else {
proto_tree_add_uint_format_value(subtree, hf_endianness, tvb, offset, 2, val_16,
"Incorrect encoding 0x%04x- skipping the remainder of this application marker", val_16);
return offset;
}
offset += 2;
offset += 2;
tiff_item = proto_tree_add_item_ret_uint(subtree, hf_start_ifd_offset, tvb, offset, 4, encoding, &val_32);
offset += 4;
if (val_32 + tiff_start < (guint32)offset) {
expert_add_info_format(pinfo, tiff_item, &ei_start_ifd_offset, " (bogus, should be >= %u)",
offset- tiff_start);
return offset;
}
if (val_32 + tiff_start > (guint32)offset) {
proto_tree_add_bytes_format_value(subtree, hf_skipped_tiff_data, tvb, offset, val_32 + tiff_start - offset, NULL, "%u bytes",
val_32 + tiff_start - offset);
}
for (;;) {
offset = val_32 + tiff_start;
proto_tree_add_item_ret_uint(subtree, hf_ifd_num_fields, tvb, offset, 2, encoding, &num_fields);
offset += 2;
while (num_fields-- > 0) {
proto_tree_add_item(subtree, hf_idf_tag, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(subtree, hf_idf_type, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(subtree, hf_idf_count, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(subtree, hf_idf_offset, tvb, offset, 4, encoding);
offset += 4;
}
tiff_item = proto_tree_add_item_ret_uint(subtree, hf_next_ifd_offset, tvb, offset, 4, encoding, &val_32);
offset += 4;
if (val_32 != 0 &&
val_32 + tiff_start < (guint32)offset) {
expert_add_info_format(pinfo, tiff_item, &ei_next_ifd_offset, " (bogus, should be >= %u)", offset + tiff_start);
return offset;
}
if (val_32 == 0)
break;
}
} else {
proto_tree_add_bytes_format_value(subtree, hf_remain_seg_data, tvb, offset, -1, NULL, "%u bytes", len - 2 - str_size);
proto_item_append_text(ti, " (Unknown identifier)");
}
return offset;
}
static void
process_app2_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti;
proto_tree *subtree;
char *str;
gint str_size;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
str = tvb_get_stringz_enc(wmem_packet_scope(), tvb, 4, &str_size, ENC_ASCII);
ti = proto_tree_add_item(subtree, hf_identifier, tvb, 4, str_size, ENC_ASCII|ENC_NA);
if (strcmp(str, "FPXR") == 0) {
proto_tree_add_item(tree, hf_exif_flashpix_marker, tvb, 0, -1, ENC_NA);
} else {
proto_tree_add_bytes_format_value(subtree, hf_remain_seg_data, tvb, 4 + str_size, -1, NULL, "%u bytes", len - 2 - str_size);
proto_item_append_text(ti, " (Unknown identifier)");
}
}
static gint
dissect_jfif(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *subtree;
proto_item *ti;
gint tvb_len = tvb_reported_length(tvb);
gint32 start_entropy = 0;
gint32 start_fill, start_marker;
gboolean show_first_identifier_not_jfif = FALSE;
if (tvb_len < 20)
return 0;
if (tvb_get_ntohs(tvb, 0) != MARKER_SOI)
return 0;
if (tvb_memeql(tvb, 6, "Exif", 5) == 0) {
show_first_identifier_not_jfif = TRUE;
}
else if (tvb_memeql(tvb, 6, "JFIF", 5)) {
return 0;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "(JPEG JFIF image)");
ti = proto_tree_add_item(tree, proto_jfif,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_jfif);
for (; ; ) {
const char *str;
guint16 marker;
start_fill = start_entropy;
for (; ; ) {
start_fill = tvb_find_guint8(tvb, start_fill, -1, 0xFF);
if (start_fill == -1 || tvb_len - start_fill == 1
|| tvb_get_guint8(tvb, start_fill + 1) != 0)
break;
start_fill += 2;
}
if (start_fill == -1) start_fill = tvb_len;
if (start_fill != start_entropy)
proto_tree_add_item(subtree, hf_entropy_coded_segment, tvb, start_entropy, start_fill - start_entropy, ENC_NA);
if (start_fill == tvb_len) break;
start_marker = start_fill;
while (tvb_get_guint8(tvb, start_marker + 1) == 0xFF)
++start_marker;
if (start_marker != start_fill)
proto_tree_add_item(subtree, hf_fill_bytes, tvb, start_fill, start_marker - start_fill, ENC_NA);
marker = tvb_get_ntohs(tvb, start_marker);
str = try_val_to_str(marker, vals_marker);
if (str) {
if (marker_has_length(marker)) {
const guint16 len = tvb_get_ntohs(tvb, start_marker + 2);
tvbuff_t *tmp_tvb = tvb_new_subset_length(tvb, start_marker, 2 + len);
switch (marker) {
case MARKER_APP0:
process_app0_segment(subtree, tmp_tvb, len, marker, str);
break;
case MARKER_APP1:
process_app1_segment(subtree, tmp_tvb, pinfo, len, marker, str, show_first_identifier_not_jfif);
show_first_identifier_not_jfif = FALSE;
break;
case MARKER_APP2:
process_app2_segment(subtree, tmp_tvb, len, marker, str);
break;
case MARKER_SOF0:
case MARKER_SOF1:
case MARKER_SOF2:
case MARKER_SOF3:
case MARKER_SOF5:
case MARKER_SOF6:
case MARKER_SOF7:
case MARKER_SOF8:
case MARKER_SOF9:
case MARKER_SOF10:
case MARKER_SOF11:
case MARKER_SOF13:
case MARKER_SOF14:
case MARKER_SOF15:
process_sof_header(subtree, tmp_tvb, len, marker, str);
break;
case MARKER_SOS:
process_sos_header(subtree, tmp_tvb, len, marker, str);
break;
case MARKER_COM:
process_comment_header(subtree, tmp_tvb, len, marker, str);
break;
default:
process_marker_segment(subtree, tmp_tvb, len, marker, str);
break;
}
start_entropy = start_marker + 2 + len;
} else {
proto_tree_add_item(subtree, hf_marker,
tvb, start_marker, 2, ENC_BIG_ENDIAN);
start_entropy = start_marker + 2;
}
} else {
ti = proto_tree_add_item(subtree, hf_marker,
tvb, start_marker, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (Reserved)");
return tvb_len;
}
}
return tvb_len;
}
static gboolean
dissect_jfif_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_jfif(tvb, pinfo, tree, NULL) > 0;
}
void
proto_register_jfif(void)
{
static hf_register_info hf[] = {
{ &hf_marker,
{ "Marker",
"image-jfif.marker",
FT_UINT8, BASE_HEX, VALS(vals_marker), 0x00,
"JFIF Marker",
HFILL
}
},
{ &hf_marker_segment,
{ "Marker segment",
"image-jfif.marker_segment",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_len,
{ "Length",
"image-jfif.length",
FT_UINT16, BASE_DEC, 0, 0x00,
"Length of segment (including length field)",
HFILL
}
},
{ &hf_identifier,
{ "Identifier",
"image-jfif.identifier",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Identifier of the segment",
HFILL
}
},
{ &hf_version,
{ "Version",
"image-jfif.version",
FT_NONE, BASE_NONE, NULL, 0x00,
"JFIF Version",
HFILL
}
},
{ &hf_version_major,
{ "Major Version",
"image-jfif.version.major",
FT_UINT8, BASE_DEC, NULL, 0x00,
"JFIF Major Version",
HFILL
}
},
{ &hf_version_minor,
{ "Minor Version",
"image-jfif.version.minor",
FT_UINT8, BASE_DEC, NULL, 0x00,
"JFIF Minor Version",
HFILL
}
},
{ &hf_units,
{ "Units",
"image-jfif.units",
FT_UINT8, BASE_DEC, VALS(vals_units), 0x00,
"Units used in this segment",
HFILL
}
},
{ &hf_xdensity,
{ "Xdensity",
"image-jfif.Xdensity",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Horizontal pixel density",
HFILL
}
},
{ &hf_ydensity,
{ "Ydensity",
"image-jfif.Ydensity",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Vertical pixel density",
HFILL
}
},
{ &hf_xthumbnail,
{ "Xthumbnail",
"image-jfif.Xthumbnail",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Thumbnail horizontal pixel count",
HFILL
}
},
{ &hf_ythumbnail,
{ "Ythumbnail",
"image-jfif.Ythumbnail",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Thumbnail vertical pixel count",
HFILL
}
},
{ &hf_rgb,
{ "RGB values of thumbnail pixels",
"image-jfif.RGB",
FT_BYTES, BASE_NONE, NULL, 0x00,
"RGB values of the thumbnail pixels (24 bit per pixel, Xthumbnail x Ythumbnail pixels)",
HFILL
}
},
{ &hf_extension_code,
{ "Extension code",
"image-jfif.extension.code",
FT_UINT8, BASE_HEX, VALS(vals_extension_code), 0x00,
"JFXX extension code for thumbnail encoding",
HFILL
}
},
{ &hf_sof_header,
{ "Start of Frame header",
"image-jfif.sof",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_sof_precision,
{ "Sample Precision (bits)",
"image-jfif.sof.precision",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the precision in bits for the samples of the components in the frame.",
HFILL
}
},
{ &hf_sof_lines,
{ "Lines",
"image-jfif.sof.lines",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Specifies the maximum number of lines in the source image.",
HFILL
}
},
{ &hf_sof_samples_per_line,
{ "Samples per line",
"image-jfif.sof.samples_per_line",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Specifies the maximum number of samples per line in the source image.",
HFILL
}
},
{ &hf_sof_nf,
{ "Number of image components in frame",
"image-jfif.sof.nf",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the number of source image components in the frame.",
HFILL
}
},
{ &hf_sof_c_i,
{ "Component identifier",
"image-jfif.sof.c_i",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Assigns a unique label to the ith component in the sequence of frame component specification parameters.",
HFILL
}
},
{ &hf_sof_h_i,
{ "Horizontal sampling factor",
"image-jfif.sof.h_i",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Specifies the relationship between the component horizontal dimension and maximum image dimension X.",
HFILL
}
},
{ &hf_sof_v_i,
{ "Vertical sampling factor",
"image-jfif.sof.v_i",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"Specifies the relationship between the component vertical dimension and maximum image dimension Y.",
HFILL
}
},
{ &hf_sof_tq_i,
{ "Quantization table destination selector",
"image-jfif.sof.tq_i",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies one of four possible quantization table destinations from which the quantization table to"
" use for dequantization of DCT coefficients of component Ci is retrieved.",
HFILL
}
},
{ &hf_sos_header,
{ "Start of Segment header",
"image-jfif.header.sos",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_sos_ns,
{ "Number of image components in scan",
"image-jfif.sos.ns",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the number of source image components in the scan.",
HFILL
}
},
{ &hf_sos_cs_j,
{ "Scan component selector",
"image-jfif.sos.component_selector",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Selects which of the Nf image components specified in the frame parameters shall be the jth"
" component in the scan.",
HFILL
}
},
{ &hf_sos_td_j,
{ "DC entropy coding table destination selector",
"image-jfif.sos.dc_entropy_selector",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Specifies one of four possible DC entropy coding table destinations from which the entropy"
" table needed for decoding of the DC coefficients of component Csj is retrieved.",
HFILL
}
},
{ &hf_sos_ta_j,
{ "AC entropy coding table destination selector",
"image-jfif.sos.ac_entropy_selector",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"Specifies one of four possible AC entropy coding table destinations from which the entropy"
" table needed for decoding of the AC coefficients of component Csj is retrieved.",
HFILL
}
},
{ &hf_sos_ss,
{ "Start of spectral or predictor selection",
"image-jfif.sos.ss",
FT_UINT8, BASE_DEC, NULL, 0x00,
"In the DCT modes of operation, this parameter specifies the first DCT coefficient in"
" each block in zig-zag order which shall be coded in the scan. This parameter shall"
" be set to zero for the sequential DCT processes. In the lossless mode of operations"
" this parameter is used to select the predictor.",
HFILL
}
},
{ &hf_sos_se,
{ "End of spectral selection",
"image-jfif.sos.se",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the last DCT coefficient in each block in zig-zag order which shall be coded"
" in the scan. This parameter shall be set to 63 for the sequential DCT processes. In the"
" lossless mode of operations this parameter has no meaning. It shall be set to zero.",
HFILL
}
},
{ &hf_sos_ah,
{ "Successive approximation bit position high",
"image-jfif.sos.ah",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"This parameter specifies the point transform used in the preceding scan (i.e. successive"
" approximation bit position low in the preceding scan) for the band of coefficients"
" specified by Ss and Se. This parameter shall be set to zero for the first scan of each"
" band of coefficients. In the lossless mode of operations this parameter has no meaning."
" It shall be set to zero.",
HFILL
}
},
{ &hf_sos_al,
{ "Successive approximation bit position low or point transform",
"image-jfif.sos.al",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"In the DCT modes of operation this parameter specifies the point transform, i.e. bit"
" position low, used before coding the band of coefficients specified by Ss and Se."
" This parameter shall be set to zero for the sequential DCT processes. In the lossless"
" mode of operations, this parameter specifies the point transform, Pt.",
HFILL
}
},
{ &hf_comment_header,
{ "Comment header",
"image-jfif.header.comment",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_comment,
{ "Comment",
"image-jfif.comment",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL,
HFILL
}
},
{ &hf_remain_seg_data,
{ "Remaining segment data",
"image-jfif.remain_seg_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_endianness,
{ "Endianness",
"image-jfif.endianness",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL,
HFILL
}
},
{ &hf_start_ifd_offset,
{ "Start offset of IFD starting from the TIFF header start",
"image-jfif.start_ifd_offset",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
NULL,
HFILL
}
},
{ &hf_next_ifd_offset,
{ "Offset to next IFD from start of TIFF header",
"image-jfif.next_ifd_offset",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
NULL,
HFILL
}
},
{ &hf_exif_flashpix_marker,
{ "Exif FlashPix APP2 application marker",
"image-jfif.exif_flashpix_marker",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_entropy_coded_segment,
{ "Entropy-coded segment (dissection is not yet implemented)",
"image-jfif.entropy_coded_segment",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_fill_bytes,
{ "Fill bytes",
"image-jfif.fill_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_skipped_tiff_data,
{ "Skipped data between end of TIFF header and start of IFD",
"image-jfif.skipped_tiff_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_ifd_num_fields,
{ "Number of fields in this IFD",
"image-jfif.ifd.num_fields",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{ &hf_idf_tag,
{ "Exif Tag",
"image-jfif.ifd.tag",
FT_UINT16, BASE_DEC, VALS(vals_exif_tags), 0x0,
NULL,
HFILL
}
},
{ &hf_idf_type,
{ "Type",
"image-jfif.ifd.type",
FT_UINT16, BASE_DEC, VALS(vals_exif_types), 0x0,
NULL,
HFILL
}
},
{ &hf_idf_count,
{ "Count",
"image-jfif.ifd.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{ &hf_idf_offset,
{ "Value offset from start of TIFF header",
"image-jfif.ifd.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
};
static gint *ett[] = {
&ett_jfif,
&ett_marker_segment,
&ett_details,
};
static ei_register_info ei[] = {
{ &ei_file_jpeg_first_identifier_not_jfif,
{ "image-jfif.app0-identifier-not-jfif", PI_MALFORMED, PI_WARN,
"Initial App0 segment with \"JFIF\" Identifier not found", EXPFILL }},
{ &ei_start_ifd_offset,
{ "image-jfif.start_ifd_offset.invalid", PI_PROTOCOL, PI_WARN,
"Invalid value", EXPFILL }},
{ &ei_next_ifd_offset,
{ "image-jfif.next_ifd_offset.invalid", PI_PROTOCOL, PI_WARN,
"Invalid value", EXPFILL }},
};
expert_module_t* expert_jfif;
proto_jfif = proto_register_protocol(
"JPEG File Interchange Format",
"JFIF (JPEG) image",
"image-jfif"
);
proto_register_field_array(proto_jfif, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_jfif = expert_register_protocol(proto_jfif);
expert_register_field_array(expert_jfif, ei, array_length(ei));
register_dissector("image-jfif", dissect_jfif, proto_jfif);
}
void
proto_reg_handoff_jfif(void)
{
dissector_handle_t jfif_handle = find_dissector("image-jfif");
dissector_add_string("media_type", "image/jfif", jfif_handle);
dissector_add_string("media_type", "image/jpg", jfif_handle);
dissector_add_string("media_type", "image/jpeg", jfif_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JPEG_JFIF, jfif_handle);
heur_dissector_add("http", dissect_jfif_heur, "JPEG file in HTTP", "jfif_http", proto_jfif, HEURISTIC_ENABLE);
heur_dissector_add("wtap_file", dissect_jfif_heur, "JPEG file", "jfif_wtap", proto_jfif, HEURISTIC_ENABLE);
}
