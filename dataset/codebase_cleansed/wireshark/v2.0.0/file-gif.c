static gint
dissect_gif(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *gif_tree;
proto_tree *subtree;
guint offset = 0, len = 0;
guint8 peek;
gboolean color_map_present;
guint8 color_resolution;
guint8 image_bpp;
guint tvb_len = tvb_reported_length(tvb);
char *str;
guint8 version = 0;
if (tvb_len < 20)
return 0;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, 6, ENC_ASCII|ENC_NA);
if (strcmp(str, "GIF87a") == 0) {
version = GIF_87a;
} else if (strcmp(str, "GIF89a") == 0) {
version = GIF_89a;
} else {
return 0;
}
DISSECTOR_ASSERT(version);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", str);
if (tree) {
ti = proto_tree_add_item(tree, hfi_gif, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Version: %s", str);
gif_tree = proto_item_add_subtree(ti, ett_gif);
proto_tree_add_item(gif_tree, &hfi_version, tvb, 0, 6, ENC_ASCII|ENC_NA);
proto_tree_add_item(gif_tree, &hfi_screen_width, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gif_tree, &hfi_screen_height, tvb, 8, 2, ENC_LITTLE_ENDIAN);
peek = tvb_get_guint8(tvb, 10);
color_map_present = peek & 0x80;
color_resolution = 1 + ((peek & 0x60) >> 4);
image_bpp = 1 + (peek & 0x07);
subtree = proto_tree_add_subtree(gif_tree, tvb, 10, 1, ett_global_flags, &ti,
"Global settings:");
if (color_map_present)
proto_item_append_text(ti, " (Global color table present)");
proto_item_append_text(ti,
" (%u bit%s per color) (%u bit%s per pixel)",
color_resolution, plurality(color_resolution, "", "s"),
image_bpp, plurality(image_bpp, "", "s"));
proto_tree_add_item(subtree, &hfi_global_color_map_present,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, &hfi_global_color_resolution,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
proto_tree_add_item(subtree, &hfi_global_color_map_ordered,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(subtree, &hfi_global_image_bpp,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gif_tree, &hfi_background_color,
tvb, 11, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
peek = tvb_get_guint8(tvb, 12);
if (peek) {
proto_tree_add_uint_format(gif_tree, hfi_pixel_aspect_ratio.id,
tvb, 12, 1, peek,
"%u, yields an aspect ratio of (15 + %u) / 64 = %.2f",
peek, peek, (float)(15 + peek) / 64.0);
}
}
if (color_map_present) {
len = 3 * (1 << image_bpp);
proto_tree_add_item(gif_tree, &hfi_global_color_map,
tvb, 13, len, ENC_NA);
} else {
len = 0;
}
offset = 13 + len;
while (offset < tvb_len) {
peek = tvb_get_guint8(tvb, offset);
if (peek == 0x21) {
guint32 item_len = 2;
ti = proto_tree_add_item(gif_tree, &hfi_extension,
tvb, offset, 1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_extension);
offset++;
proto_tree_add_item(subtree, &hfi_extension_label,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
peek = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s",
val_to_str(peek, vals_extensions,
"<Warning: Unknown extension 0x%02X>"));
offset++;
do {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_bytes_format(subtree, hfi_data_block.id, tvb,
offset+1, len, NULL,
"Data block (length = %u)", len);
offset += (1 + len);
item_len += (1 + len);
} while (len > 0);
proto_item_set_len(ti, item_len);
} else if (peek == 0x2C) {
proto_tree *subtree2;
proto_item *ti2;
guint32 item_len = 11;
ti = proto_tree_add_item(gif_tree, &hfi_image,
tvb, offset, 1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_image);
offset++;
proto_tree_add_item(subtree, &hfi_image_left,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, &hfi_image_top,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, &hfi_image_width,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, &hfi_image_height,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
peek = tvb_get_guint8(tvb, offset);
color_map_present = peek & 0x80;
color_resolution = 1 + ((peek & 0x60) >> 4);
image_bpp = 1 + (peek & 0x07);
subtree2 = proto_tree_add_subtree(subtree, tvb, offset, 1, ett_local_flags, &ti2,
"Local settings:");
if (color_map_present)
proto_item_append_text(ti2, " (Local color table present)");
proto_item_append_text(ti2,
" (%u bit%s per color) (%u bit%s per pixel)",
color_resolution, plurality(color_resolution, "", "s"),
image_bpp, plurality(image_bpp, "", "s"));
proto_tree_add_item(subtree2, &hfi_local_color_map_present,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, &hfi_local_color_resolution,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
proto_tree_add_item(subtree2, &hfi_local_color_map_ordered,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(subtree2, &hfi_global_image_bpp,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (color_map_present) {
len = 3 * (1 << image_bpp);
proto_tree_add_item(subtree, &hfi_local_color_map,
tvb, offset, len, ENC_NA);
} else {
len = 0;
}
offset += len;
item_len += len;
proto_tree_add_item(subtree, &hfi_image_code_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
do {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_bytes_format(subtree, hfi_data_block.id, tvb,
offset + 1, len, NULL,
"Data block (length = %u)", len);
offset += 1 + len;
item_len += (1 + len);
} while (len > 0);
proto_item_set_len(ti, item_len);
} else {
proto_tree_add_item(gif_tree, &hfi_trailer,
tvb, offset, 1, ENC_NA);
break;
}
}
}
return offset;
}
static gboolean
dissect_gif_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_gif(tvb, pinfo, tree, NULL) > 0;
}
void
proto_register_gif(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_version,
&hfi_screen_width,
&hfi_screen_height,
&hfi_global_color_map_present,
&hfi_global_color_resolution,
&hfi_global_color_map_ordered,
&hfi_global_image_bpp,
&hfi_background_color,
&hfi_pixel_aspect_ratio,
&hfi_global_color_map,
&hfi_local_color_map_present,
&hfi_local_color_resolution,
&hfi_local_color_map_ordered,
&hfi_local_color_map,
&hfi_extension,
&hfi_extension_label,
&hfi_image,
&hfi_image_left,
&hfi_image_top,
&hfi_image_width,
&hfi_image_height,
&hfi_image_code_size,
&hfi_trailer,
&hfi_data_block
};
#endif
static gint *ett[] = {
&ett_gif,
&ett_global_flags,
&ett_local_flags,
&ett_extension,
&ett_image,
};
int proto_gif;
proto_gif = proto_register_protocol(
"Compuserve GIF",
"GIF image",
IMG_GIF
);
hfi_gif = proto_registrar_get_nth(proto_gif);
proto_register_fields(proto_gif, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
gif_handle = new_register_dissector(IMG_GIF, dissect_gif, proto_gif);
}
void
proto_reg_handoff_gif(void)
{
dissector_add_string("media_type", "image/gif", gif_handle);
heur_dissector_add("http", dissect_gif_heur, "GIF file in HTTP", "gif_http", hfi_gif->id, HEURISTIC_ENABLE);
heur_dissector_add("wtap_file", dissect_gif_heur, "GIF file", "gif_wtap", hfi_gif->id, HEURISTIC_ENABLE);
}
