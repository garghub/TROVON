static void
dissect_png_ihdr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, &hfi_png_ihdr_width, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_height, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_bitdepth, tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_colour_type, tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_compression_method, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_filter_method, tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_ihdr_interlace_method, tvb, 12, 1, ENC_BIG_ENDIAN);
}
static void
dissect_png_srgb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, &hfi_png_srgb_intent,
tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
dissect_png_text(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
gint offset=0, nul_offset;
nul_offset = tvb_find_guint8(tvb, offset, tvb_length_remaining(tvb, offset), 0);
if (nul_offset<=0) {
return;
}
proto_tree_add_item(tree, &hfi_png_text_keyword, tvb, offset, nul_offset, ENC_ISO_8859_1|ENC_NA);
offset = nul_offset+1;
proto_tree_add_item(tree, &hfi_png_text_string, tvb, offset, tvb_length_remaining(tvb, offset), ENC_ISO_8859_1|ENC_NA);
}
static void
dissect_png_time(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, &hfi_png_time_year, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_time_month, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_time_day, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_time_hour, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_time_minute, tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_time_second, tvb, 6, 1, ENC_BIG_ENDIAN);
}
static void
dissect_png_phys(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, &hfi_png_phys_horiz, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_phys_vert, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_phys_unit, tvb, 8, 1, ENC_BIG_ENDIAN);
}
static void
dissect_png_bkgd(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
switch(tvb_reported_length(tvb)){
case 1:
proto_tree_add_item(tree, &hfi_png_bkgd_palette_index, tvb, 0, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, &hfi_png_bkgd_greyscale, tvb, 0, 2, ENC_BIG_ENDIAN);
break;
case 6:
proto_tree_add_item(tree, &hfi_png_bkgd_red, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_bkgd_green, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_png_bkgd_blue, tvb, 4, 2, ENC_BIG_ENDIAN);
break;
}
}
static void
dissect_png_chrm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
float wx, wy, rx, ry, gx, gy, bx, by;
gint offset = 0;
wx = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_white_x,
tvb, offset, 4, wx, "%f", wx);
offset += 4;
wy = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_white_y,
tvb, offset, 4, wy, "%f", wy);
offset += 4;
rx = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_red_x,
tvb, offset, 4, rx, "%f", rx);
offset += 4;
ry = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_red_y,
tvb, offset, 4, ry, "%f", ry);
offset += 4;
gx = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_green_x,
tvb, offset, 4, gx, "%f", gx);
offset += 4;
gy = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_green_y,
tvb, offset, 4, gy, "%f", gy);
offset += 4;
bx = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_blue_x,
tvb, offset, 4, bx, "%f", bx);
offset += 4;
by = tvb_get_ntohl(tvb, offset) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_chrm_blue_y,
tvb, offset, 4, by, "%f", by);
}
static void
dissect_png_gama(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
float gamma;
gamma = tvb_get_ntohl(tvb, 0) / 100000.0f;
proto_tree_add_float_format_value(tree, &hfi_png_gama_gamma,
tvb, 0, 4, gamma, "%f", gamma);
}
static gint
dissect_png(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_tree *tree;
proto_item *ti;
gint offset=0;
static const guint8 magic[8] = { 137, 80, 78, 71, 13, 10, 26, 10 };
if (tvb_length(tvb) < 20)
return 0;
if (tvb_memeql(tvb, 0, magic, sizeof(magic)) != 0)
return 0;
col_append_str(pinfo->cinfo, COL_INFO, " (PNG)");
ti=proto_tree_add_item(parent_tree, hfi_png, tvb, offset, -1, ENC_NA);
tree=proto_item_add_subtree(ti, ett_png);
proto_tree_add_item(tree, &hfi_png_signature, tvb, offset, 8, ENC_NA);
offset+=8;
while(tvb_reported_length_remaining(tvb, offset) > 0){
guint32 len_field;
proto_item *chunk_it, *len_it;
proto_tree *chunk_tree;
guint32 type;
guint8 *type_str;
tvbuff_t *chunk_tvb;
len_field = tvb_get_ntohl(tvb, offset);
type = tvb_get_ntohl(tvb, offset+4);
type_str = tvb_get_string_enc(wmem_packet_scope(),
tvb, offset+4, 4, ENC_ASCII|ENC_NA);
chunk_it = proto_tree_add_text(tree, tvb, offset, 4+4+len_field+4, "%s (%s)",
val_to_str_const(type, chunk_types, "unknown"), type_str);
chunk_tree = proto_item_add_subtree(chunk_it, ett_png_chunk);
len_it = proto_tree_add_item(chunk_tree, &hfi_png_chunk_len,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (len_field > G_MAXINT) {
expert_add_info(pinfo, len_it, &ei_png_chunk_too_large);
return offset;
}
proto_tree_add_item(chunk_tree, &hfi_png_chunk_type_str,
tvb, offset, 4, ENC_ASCII|ENC_NA);
proto_tree_add_item(chunk_tree, &hfi_png_chunk_flag_anc, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(chunk_tree, &hfi_png_chunk_flag_priv, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(chunk_tree, &hfi_png_chunk_flag_stc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
chunk_tvb=tvb_new_subset(tvb, offset, len_field, len_field);
switch (type) {
case CHUNK_TYPE_IHDR:
dissect_png_ihdr(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_bKGD:
dissect_png_bkgd(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_cHRM:
dissect_png_chrm(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_gAMA:
dissect_png_gama(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_pHYs:
dissect_png_phys(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_sRGB:
dissect_png_srgb(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_tEXt:
dissect_png_text(chunk_tvb, pinfo, chunk_tree);
break;
case CHUNK_TYPE_tIME:
dissect_png_time(chunk_tvb, pinfo, chunk_tree);
break;
default:
if (len_field>0) {
proto_tree_add_item(chunk_tree, &hfi_png_chunk_data,
tvb, offset, len_field, ENC_NA);
}
break;
}
offset += len_field;
proto_tree_add_item(chunk_tree, &hfi_png_chunk_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
return offset;
}
void
proto_register_png(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] =
{
&hfi_png_signature,
&hfi_png_chunk_type_str,
&hfi_png_chunk_data,
&hfi_png_chunk_len,
&hfi_png_chunk_crc,
&hfi_png_chunk_flag_anc,
&hfi_png_chunk_flag_priv,
&hfi_png_chunk_flag_stc,
&hfi_png_ihdr_width,
&hfi_png_ihdr_height,
&hfi_png_ihdr_bitdepth,
&hfi_png_ihdr_colour_type,
&hfi_png_ihdr_compression_method,
&hfi_png_ihdr_filter_method,
&hfi_png_ihdr_interlace_method,
&hfi_png_srgb_intent,
&hfi_png_text_keyword,
&hfi_png_text_string,
&hfi_png_time_year,
&hfi_png_time_month,
&hfi_png_time_day,
&hfi_png_time_hour,
&hfi_png_time_minute,
&hfi_png_time_second,
&hfi_png_phys_horiz,
&hfi_png_phys_vert,
&hfi_png_phys_unit,
&hfi_png_bkgd_palette_index,
&hfi_png_bkgd_greyscale,
&hfi_png_bkgd_red,
&hfi_png_bkgd_green,
&hfi_png_bkgd_blue,
&hfi_png_chrm_white_x,
&hfi_png_chrm_white_y,
&hfi_png_chrm_red_x,
&hfi_png_chrm_red_y,
&hfi_png_chrm_green_x,
&hfi_png_chrm_green_y,
&hfi_png_chrm_blue_x,
&hfi_png_chrm_blue_y,
&hfi_png_gama_gamma
};
#endif
static gint *ett[] =
{
&ett_png,
&ett_png_chunk,
};
static ei_register_info ei[] = {
{ &ei_png_chunk_too_large,
{ "png.chunk_too_large", PI_PROTOCOL, PI_WARN,
"chunk size too large, dissection of this chunk is not supported", EXPFILL }}
};
expert_module_t *expert_png;
int proto_png;
proto_png = proto_register_protocol("Portable Network Graphics","PNG","png");
hfi_png = proto_registrar_get_nth(proto_png);
proto_register_fields(proto_png, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
expert_png = expert_register_protocol(proto_png);
expert_register_field_array(expert_png, ei, array_length(ei));
png_handle = new_register_dissector("png", dissect_png, proto_png);
}
static gboolean dissect_png_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_png(tvb, pinfo, tree, NULL) > 0;
}
void
proto_reg_handoff_png(void)
{
dissector_add_string("media_type", "image/png", png_handle);
heur_dissector_add("http", dissect_png_heur, hfi_png->id);
heur_dissector_add("wtap_file", dissect_png_heur, hfi_png->id);
}
