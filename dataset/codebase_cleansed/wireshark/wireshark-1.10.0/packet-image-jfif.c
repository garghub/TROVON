static void
process_marker_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
if (! tree)
return;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(subtree, tvb, 4, -1,
"Remaining segment data (%u bytes)", len - 2);
}
static void
process_sof_header(proto_tree *tree, tvbuff_t *tvb, guint32 len _U_,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
if (! tree)
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
{
guint8 count = tvb_get_guint8(tvb, 9);
guint32 offset = 10;
while (count > 0) {
proto_tree_add_item(subtree, hf_sof_c_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_h_i, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_v_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sof_tq_i, tvb, offset++, 1, ENC_BIG_ENDIAN);
count--;
}
}
}
static void
process_sos_header(proto_tree *tree, tvbuff_t *tvb, guint32 len _U_,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
guint32 offset;
if (! tree)
return;
ti = proto_tree_add_item(tree, hf_sos_header,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ns, tvb, 4, 1, ENC_BIG_ENDIAN);
{
guint8 count = tvb_get_guint8(tvb, 4);
offset = 5;
while (count > 0) {
proto_tree_add_item(subtree, hf_sos_cs_j, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_td_j, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ta_j, tvb, offset++, 1, ENC_BIG_ENDIAN);
count--;
}
}
proto_tree_add_item(subtree, hf_sos_ss, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_se, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_ah, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_sos_al, tvb, offset, 1, ENC_BIG_ENDIAN);
;
}
static int
process_app0_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
proto_tree *subtree_details = NULL;
guint32 offset;
char *str;
gint str_size;
if (!tree)
return 0 ;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_len, tvb, 2, 2, ENC_BIG_ENDIAN);
str = tvb_get_ephemeral_stringz(tvb, 4, &str_size);
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
{
guint16 x = tvb_get_guint8(tvb, 16);
guint16 y = tvb_get_guint8(tvb, 17);
if (x || y) {
proto_tree_add_item(subtree, hf_rgb,
tvb, 18, 3 * (x * y), ENC_NA);
offset = 18 + (3 * (x * y));
} else {
offset = 18;
}
}
} else if (strcmp(str, "JFXX") == 0) {
proto_tree_add_item(subtree, hf_extension_code,
tvb, 9, 1, ENC_BIG_ENDIAN);
{
guint8 code = tvb_get_guint8(tvb, 9);
switch (code) {
case 0x10:
break;
case 0x11:
break;
case 0x13:
break;
default:
break;
}
}
offset = 10;
} else {
proto_item_append_text(ti, " (unknown identifier)");
offset = 4 + str_size;
proto_tree_add_text(subtree, tvb, offset, -1,
"Remaining segment data (%u bytes)", len - 2 - str_size);
}
return offset;
}
static int
process_app1_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
char *str;
gint str_size;
int offset = 0;
int tiff_start;
if (!tree)
return 0;
ti = proto_tree_add_item(tree, hf_marker_segment,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_marker_segment);
proto_item_append_text(ti, ": %s (0x%04X)", marker_name, marker);
proto_tree_add_item(subtree, hf_marker, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
str = tvb_get_ephemeral_stringz(tvb, offset, &str_size);
ti = proto_tree_add_item(subtree, hf_identifier, tvb, offset, str_size, ENC_ASCII|ENC_NA);
offset += str_size;
if (strcmp(str, "Exif") == 0) {
gboolean is_little_endian;
guint16 val_16;
guint32 val_32;
guint16 num_fields;
offset++;
tiff_start = offset;
val_16 = tvb_get_ntohs(tvb, offset);
if (val_16 == 0x4949) {
is_little_endian = TRUE;
proto_tree_add_text(subtree, tvb, offset, 2, "Endianness: little endian");
} else if (val_16 == 0x4D4D) {
is_little_endian = FALSE;
proto_tree_add_text(subtree, tvb, offset, 2, "Endianness: big endian");
} else {
proto_tree_add_text(subtree, tvb, offset, 2,
"Incorrect endianness encoding - skipping the remainder of this application marker");
return offset;
}
offset += 2;
offset += 2;
if (is_little_endian) {
val_32 = tvb_get_letohl(tvb, offset);
} else {
val_32 = tvb_get_ntohl(tvb, offset);
}
if (val_32 + tiff_start < (guint32)offset + 4) {
proto_tree_add_text(subtree, tvb, offset, 4,
"Start offset of IFD starting from the TIFF header start: %u bytes (bogus, should be >= %u",
val_32, offset + 4 - tiff_start);
return offset;
}
proto_tree_add_text(subtree, tvb, offset, 4,
"Start offset of IFD starting from the TIFF header start: %u bytes",
val_32);
offset += 4;
if (val_32 + tiff_start > (guint32)offset) {
proto_tree_add_text(subtree, tvb, offset, val_32 + tiff_start - offset,
"Skipped data between end of TIFF header and start of IFD (%u bytes)",
val_32 + tiff_start - offset);
}
for (;;) {
offset = val_32 + tiff_start;
if (is_little_endian) {
num_fields = tvb_get_letohs(tvb, offset);
} else {
num_fields = tvb_get_ntohs(tvb, offset);
}
proto_tree_add_text(subtree, tvb, offset, 2, "Number of fields in this IFD: %u", num_fields);
offset += 2;
while (num_fields-- > 0) {
guint16 tag, type;
guint32 count, off;
if (is_little_endian) {
tag = tvb_get_letohs(tvb, offset);
type = tvb_get_letohs(tvb, offset + 2);
count = tvb_get_letohl(tvb, offset + 4);
off = tvb_get_letohl(tvb, offset + 8);
} else {
tag = tvb_get_ntohs(tvb, offset);
type = tvb_get_ntohs(tvb, offset + 2);
count = tvb_get_ntohl(tvb, offset + 4);
off = tvb_get_ntohl(tvb, offset + 8);
}
proto_tree_add_text(subtree, tvb, offset, 2,
"Exif Tag: 0x%04X (%s), Type: %u (%s), Count: %u, "
"Value offset from start of TIFF header: %u",
tag, val_to_str_const(tag, vals_exif_tags, "Unknown Exif tag"),
type, val_to_str_const(type, vals_exif_types, "Unknown Exif type"),
count, off);
offset += 12;
}
if (is_little_endian) {
val_32 = tvb_get_letohl(tvb, offset);
} else {
val_32 = tvb_get_ntohl(tvb, offset);
}
if (val_32 != 0 &&
val_32 + tiff_start < (guint32)offset + 4) {
proto_tree_add_text(subtree, tvb, offset, 4,
"Offset to next IFD from start of TIFF header: %u bytes (bogus, should be >= %u)",
val_32, offset + 4 - tiff_start);
return offset;
}
proto_tree_add_text(subtree, tvb, offset, 4,
"Offset to next IFD from start of TIFF header: %u bytes",
val_32);
offset += 4;
if (val_32 == 0)
break;
}
} else {
proto_tree_add_text(subtree, tvb, offset, -1,
"Remaining segment data (%u bytes)", len - 2 - str_size);
proto_item_append_text(ti, " (Unknown identifier)");
}
return offset;
}
static void
process_app2_segment(proto_tree *tree, tvbuff_t *tvb, guint32 len,
guint16 marker, const char *marker_name)
{
proto_item *ti = NULL;
proto_tree *subtree = NULL;
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
str = tvb_get_ephemeral_stringz(tvb, 4, &str_size);
ti = proto_tree_add_item(subtree, hf_identifier, tvb, 4, str_size, ENC_ASCII|ENC_NA);
if (strcmp(str, "FPXR") == 0) {
proto_tree_add_text(tree, tvb, 0, -1, "Exif FlashPix APP2 application marker");
} else {
proto_tree_add_text(subtree, tvb, 4 + str_size, -1,
"Remaining segment data (%u bytes)", len - 2 - str_size);
proto_item_append_text(ti, " (Unknown identifier)");
}
}
static gint
dissect_jfif(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *subtree = NULL;
proto_item *ti = NULL;
gint tvb_len = tvb_reported_length(tvb);
gint32 start_entropy = 0;
gint32 start_fill, start_marker;
if (tvb_len < 20)
return 0;
if (tvb_get_ntohs(tvb, 0) != MARKER_SOI)
return 0;
if (tvb_memeql(tvb, 6, "JFIF", 5))
return 0;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(JPEG JFIF image)");
if (tree) {
ti = proto_tree_add_item(tree, proto_jfif,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_jfif);
}
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
proto_tree_add_text(subtree, tvb, start_entropy, start_fill - start_entropy,
"Entropy-coded segment (dissection is not yet implemented)");
if (start_fill == tvb_len) break;
start_marker = start_fill;
while (tvb_get_guint8(tvb, start_marker + 1) == 0xFF)
++start_marker;
if (start_marker != start_fill)
proto_tree_add_text(subtree, tvb, start_fill, start_marker - start_fill,
"Fill bytes");
marker = tvb_get_ntohs(tvb, start_marker);
str = try_val_to_str(marker, vals_marker);
if (str) {
if (marker_has_length(marker)) {
const guint16 len = tvb_get_ntohs(tvb, start_marker + 2);
tvbuff_t *tmp_tvb = tvb_new_subset(tvb, start_marker, 2 + len, 2 + len);
switch (marker) {
case MARKER_APP0:
process_app0_segment(subtree, tmp_tvb, len, marker, str);
break;
case MARKER_APP1:
process_app1_segment(subtree, tmp_tvb, len, marker, str);
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
IMG_JFIF ".marker",
FT_UINT8, BASE_HEX, VALS(vals_marker), 0x00,
"JFIF Marker",
HFILL
}
},
{ &hf_marker_segment,
{ "Marker segment",
IMG_JFIF ".marker_segment",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_len,
{ "Length",
IMG_JFIF ".length",
FT_UINT16, BASE_DEC, 0, 0x00,
"Length of segment (including length field)",
HFILL
}
},
{ &hf_identifier,
{ "Identifier",
IMG_JFIF ".identifier",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
"Identifier of the segment",
HFILL
}
},
{ &hf_version,
{ "Version",
IMG_JFIF ".version",
FT_NONE, BASE_NONE, NULL, 0x00,
"JFIF Version",
HFILL
}
},
{ &hf_version_major,
{ "Major Version",
IMG_JFIF ".version.major",
FT_UINT8, BASE_DEC, NULL, 0x00,
"JFIF Major Version",
HFILL
}
},
{ &hf_version_minor,
{ "Minor Version",
IMG_JFIF ".version.minor",
FT_UINT8, BASE_DEC, NULL, 0x00,
"JFIF Minor Version",
HFILL
}
},
{ &hf_units,
{ "Units",
IMG_JFIF ".units",
FT_UINT8, BASE_DEC, VALS(vals_units), 0x00,
"Units used in this segment",
HFILL
}
},
{ &hf_xdensity,
{ "Xdensity",
IMG_JFIF ".Xdensity",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Horizontal pixel density",
HFILL
}
},
{ &hf_ydensity,
{ "Ydensity",
IMG_JFIF ".Ydensity",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Vertical pixel density",
HFILL
}
},
{ &hf_xthumbnail,
{ "Xthumbnail",
IMG_JFIF ".Xthumbnail",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Thumbnail horizontal pixel count",
HFILL
}
},
{ &hf_ythumbnail,
{ "Ythumbnail",
IMG_JFIF ".Ythumbnail",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Thumbnail vertical pixel count",
HFILL
}
},
{ &hf_rgb,
{ "RGB values of thumbnail pixels",
IMG_JFIF ".RGB",
FT_BYTES, BASE_NONE, NULL, 0x00,
"RGB values of the thumbnail pixels (24 bit per pixel, Xthumbnail x Ythumbnail pixels)",
HFILL
}
},
{ &hf_extension_code,
{ "Extension code",
IMG_JFIF ".extension.code",
FT_UINT8, BASE_HEX, VALS(vals_extension_code), 0x00,
"JFXX extension code for thumbnail encoding",
HFILL
}
},
{ &hf_sof_header,
{ "Start of Frame header",
IMG_JFIF ".sof",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_sof_precision,
{ "Sample Precision (bits)",
IMG_JFIF ".sof.precision",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the precision in bits for the samples of the components in the frame.",
HFILL
}
},
{ &hf_sof_lines,
{ "Lines",
IMG_JFIF ".sof.lines",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Specifies the maximum number of lines in the source image.",
HFILL
}
},
{ &hf_sof_samples_per_line,
{ "Samples per line",
IMG_JFIF ".sof.samples_per_line",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Specifies the maximum number of samples per line in the source image.",
HFILL
}
},
{ &hf_sof_nf,
{ "Number of image components in frame",
IMG_JFIF ".sof.nf",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the number of source image components in the frame.",
HFILL
}
},
{ &hf_sof_c_i,
{ "Component identifier",
IMG_JFIF ".sof.c_i",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Assigns a unique label to the ith component in the sequence of frame component specification parameters.",
HFILL
}
},
{ &hf_sof_h_i,
{ "Horizontal sampling factor",
IMG_JFIF ".sof.h_i",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Specifies the relationship between the component horizontal dimension and maximum image dimension X.",
HFILL
}
},
{ &hf_sof_v_i,
{ "Vertical sampling factor",
IMG_JFIF ".sof.v_i",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"Specifies the relationship between the component vertical dimension and maximum image dimension Y.",
HFILL
}
},
{ &hf_sof_tq_i,
{ "Quantization table destination selector",
IMG_JFIF ".sof.tq_i",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies one of four possible quantization table destinations from which the quantization table to"
" use for dequantization of DCT coefficients of component Ci is retrieved.",
HFILL
}
},
{ &hf_sos_header,
{ "Start of Segment header",
IMG_JFIF ".header.sos",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_sos_ns,
{ "Number of image components in scan",
IMG_JFIF ".sos.ns",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the number of source image components in the scan.",
HFILL
}
},
{ &hf_sos_cs_j,
{ "Scan component selector",
IMG_JFIF ".sos.component_selector",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Selects which of the Nf image components specified in the frame parameters shall be the jth"
" component in the scan.",
HFILL
}
},
{ &hf_sos_td_j,
{ "DC entropy coding table destination selector",
IMG_JFIF ".sos.dc_entropy_selector",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Specifies one of four possible DC entropy coding table destinations from which the entropy"
" table needed for decoding of the DC coefficients of component Csj is retrieved.",
HFILL
}
},
{ &hf_sos_ta_j,
{ "AC entropy coding table destination selector",
IMG_JFIF ".sos.ac_entropy_selector",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"Specifies one of four possible AC entropy coding table destinations from which the entropy"
" table needed for decoding of the AC coefficients of component Csj is retrieved.",
HFILL
}
},
{ &hf_sos_ss,
{ "Start of spectral or predictor selection",
IMG_JFIF ".sos.ss",
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
IMG_JFIF ".sos.se",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Specifies the last DCT coefficient in each block in zig-zag order which shall be coded"
" in the scan. This parameter shall be set to 63 for the sequential DCT processes. In the"
" lossless mode of operations this parameter has no meaning. It shall be set to zero.",
HFILL
}
},
{ &hf_sos_ah,
{ "Successive approximation bit position high",
IMG_JFIF ".sos.ah",
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
IMG_JFIF ".sos.al",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"In the DCT modes of operation this parameter specifies the point transform, i.e. bit"
" position low, used before coding the band of coefficients specified by Ss and Se."
" This parameter shall be set to zero for the sequential DCT processes. In the lossless"
" mode of operations, this parameter specifies the point transform, Pt.",
HFILL
}
},
};
static gint *ett[] = {
&ett_jfif,
&ett_marker_segment,
&ett_details,
};
proto_jfif = proto_register_protocol(
"JPEG File Interchange Format",
"JFIF (JPEG) image",
IMG_JFIF
);
proto_register_field_array(proto_jfif, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(IMG_JFIF, dissect_jfif, proto_jfif);
}
void
proto_reg_handoff_jfif(void)
{
dissector_handle_t jfif_handle = find_dissector(IMG_JFIF);
dissector_add_string("media_type", "image/jfif", jfif_handle);
dissector_add_string("media_type", "image/jpg", jfif_handle);
dissector_add_string("media_type", "image/jpeg", jfif_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_JPEG_JFIF, jfif_handle);
heur_dissector_add("http", dissect_jfif_heur, proto_jfif);
heur_dissector_add("wtap_file", dissect_jfif_heur, proto_jfif);
}
