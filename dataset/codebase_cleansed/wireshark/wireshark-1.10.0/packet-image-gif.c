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
str = tvb_get_ephemeral_string(tvb, 0, 6);
if (strcmp(str, "GIF87a") == 0) {
version = GIF_87a;
} else if (strcmp(str, "GIF89a") == 0) {
version = GIF_89a;
} else {
return 0;
}
DISSECTOR_ASSERT(version);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", str);
if (tree) {
ti = proto_tree_add_item(tree, proto_gif, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Version: %s", str);
gif_tree = proto_item_add_subtree(ti, ett_gif);
proto_tree_add_item(gif_tree, hf_version, tvb, 0, 6, ENC_ASCII|ENC_NA);
proto_tree_add_item(gif_tree, hf_screen_width, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gif_tree, hf_screen_height, tvb, 8, 2, ENC_LITTLE_ENDIAN);
peek = tvb_get_guint8(tvb, 10);
color_map_present = peek & 0x80;
color_resolution = 1 + ((peek & 0x60) >> 4);
image_bpp = 1 + (peek & 0x07);
ti = proto_tree_add_text(gif_tree, tvb, 10, 1,
"Global settings:");
if (color_map_present)
proto_item_append_text(ti, " (Global color table present)");
proto_item_append_text(ti,
" (%u bit%s per color) (%u bit%s per pixel)",
color_resolution, plurality(color_resolution, "", "s"),
image_bpp, plurality(image_bpp, "", "s"));
subtree = proto_item_add_subtree(ti, ett_global_flags);
proto_tree_add_item(subtree, hf_global_color_map_present,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_global_color_resolution,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
proto_tree_add_item(subtree, hf_global_color_map_ordered,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(subtree, hf_global_image_bpp,
tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gif_tree, hf_background_color,
tvb, 11, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
peek = tvb_get_guint8(tvb, 12);
if (peek) {
proto_tree_add_uint_format(gif_tree, hf_pixel_aspect_ratio,
tvb, 12, 1, peek,
"%u, yields an aspect ratio of (15 + %u) / 64 = %.2f",
peek, peek, (float)(15 + peek) / 64.0);
}
}
if (color_map_present) {
len = 3 * (1 << image_bpp);
proto_tree_add_item(gif_tree, hf_global_color_map,
tvb, 13, len, ENC_NA);
} else {
len = 0;
}
offset = 13 + len;
while (offset < tvb_len) {
peek = tvb_get_guint8(tvb, offset);
if (peek == 0x21) {
guint32 item_len = 2;
ti = proto_tree_add_item(gif_tree, hf_extension,
tvb, offset, 1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_extension);
offset++;
proto_tree_add_item(subtree, hf_extension_label,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
peek = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s",
val_to_str(peek, vals_extensions,
"<Warning: Unknown extension 0x%02X>"));
offset++;
do {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(subtree, tvb,
offset, 1 + len,
"Data block (length = %u)", len);
offset += (1 + len);
item_len += (1 + len);
} while (len > 0);
proto_item_set_len(ti, item_len);
} else if (peek == 0x2C) {
proto_tree *subtree2;
proto_item *ti2;
guint32 item_len = 11;
ti = proto_tree_add_item(gif_tree, hf_image,
tvb, offset, 1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_image);
offset++;
proto_tree_add_item(subtree, hf_image_left,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, hf_image_top,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, hf_image_width,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(subtree, hf_image_height,
tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
peek = tvb_get_guint8(tvb, offset);
color_map_present = peek & 0x80;
color_resolution = 1 + ((peek & 0x60) >> 4);
image_bpp = 1 + (peek & 0x07);
ti2 = proto_tree_add_text(subtree, tvb, offset, 1,
"Local settings:");
if (color_map_present)
proto_item_append_text(ti2, " (Local color table present)");
proto_item_append_text(ti2,
" (%u bit%s per color) (%u bit%s per pixel)",
color_resolution, plurality(color_resolution, "", "s"),
image_bpp, plurality(image_bpp, "", "s"));
subtree2 = proto_item_add_subtree(ti2, ett_local_flags);
proto_tree_add_item(subtree2, hf_local_color_map_present,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree2, hf_local_color_resolution,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (version == GIF_89a) {
proto_tree_add_item(subtree2, hf_local_color_map_ordered,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(subtree2, hf_global_image_bpp,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if (color_map_present) {
len = 3 * (1 << image_bpp);
proto_tree_add_item(subtree, hf_local_color_map,
tvb, offset, len, ENC_NA);
} else {
len = 0;
}
offset += len;
item_len += len;
proto_tree_add_item(subtree, hf_image_code_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
do {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(subtree, tvb,
offset, 1 + len,
"Data block (length = %u)", len);
offset += 1 + len;
item_len += (1 + len);
} while (len > 0);
proto_item_set_len(ti, item_len);
} else {
proto_tree_add_item(gif_tree, hf_trailer,
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
static hf_register_info hf[] = {
{ &hf_version,
{ "Version",
IMG_GIF ".version",
FT_STRING, BASE_NONE, NULL, 0x00,
"GIF Version",
HFILL
}
},
{ &hf_screen_width,
{ "Screen width",
IMG_GIF ".screen.width",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_screen_height,
{ "Screen height",
IMG_GIF ".screen.height",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_global_color_map_present,
{ "Global color map is present",
IMG_GIF ".global.color_map.present",
FT_UINT8, BASE_DEC, VALS(vals_true_false), 0x80,
"Indicates if the global color map is present",
HFILL
}
},
{ &hf_global_color_resolution,
{ "Bits per color minus 1",
IMG_GIF ".global.color_bpp",
FT_UINT8, BASE_DEC, NULL, 0x70,
"The number of bits per color is one plus the field value.",
HFILL
}
},
{ &hf_global_color_map_ordered,
{ "Global color map is ordered",
IMG_GIF ".global.color_map.ordered",
FT_UINT8, BASE_DEC, VALS(vals_true_false), 0x08,
"Indicates whether the global color map is ordered.",
HFILL
}
},
{ &hf_global_image_bpp,
{ "Image bits per pixel minus 1",
IMG_GIF ".global.bpp",
FT_UINT8, BASE_DEC, NULL, 0x07,
"The number of bits per pixel is one plus the field value.",
HFILL
}
},
{ &hf_background_color,
{ "Background color index",
IMG_GIF ".image_background_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Index of the background color in the color map.",
HFILL
}
},
{ &hf_pixel_aspect_ratio,
{ "Global pixel aspect ratio",
IMG_GIF ".global.pixel_aspect_ratio",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Gives an approximate value of the aspect ratio of the pixels.",
HFILL
}
},
{ &hf_global_color_map,
{ "Global color map",
IMG_GIF ".global.color_map",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Global color map.",
HFILL
}
},
{ &hf_local_color_map_present,
{ "Local color map is present",
IMG_GIF ".local.color_map.present",
FT_UINT8, BASE_DEC, VALS(vals_true_false), 0x80,
"Indicates if the local color map is present",
HFILL
}
},
{ &hf_local_color_resolution,
{ "Bits per color minus 1",
IMG_GIF ".local.color_bpp",
FT_UINT8, BASE_DEC, NULL, 0x70,
"The number of bits per color is one plus the field value.",
HFILL
}
},
{ &hf_local_color_map_ordered,
{ "Local color map is ordered",
IMG_GIF ".local.color_map.ordered",
FT_UINT8, BASE_DEC, VALS(vals_true_false), 0x08,
"Indicates whether the local color map is ordered.",
HFILL
}
},
#if 0
{ &hf_local_image_bpp,
{ "Image bits per pixel minus 1",
IMG_GIF ".local.bpp",
FT_UINT8, BASE_DEC, NULL, 0x07,
"The number of bits per pixel is one plus the field value.",
HFILL
}
},
#endif
{ &hf_local_color_map,
{ "Local color map",
IMG_GIF ".local.color_map",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Local color map.",
HFILL
}
},
{ &hf_extension,
{ "Extension",
IMG_GIF ".extension",
FT_NONE, BASE_NONE, NULL, 0x00,
"Extension.",
HFILL
}
},
{ &hf_extension_label,
{ "Extension label",
IMG_GIF ".extension.label",
FT_UINT8, BASE_HEX, VALS(vals_extensions), 0x00,
"Extension label.",
HFILL
}
},
{ &hf_image,
{ "Image",
IMG_GIF ".image",
FT_NONE, BASE_NONE, NULL, 0x00,
"Image.",
HFILL
}
},
{ &hf_image_left,
{ "Image left position",
IMG_GIF ".image.left",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Offset between left of Screen and left of Image.",
HFILL
}
},
{ &hf_image_top,
{ "Image top position",
IMG_GIF ".image.top",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Offset between top of Screen and top of Image.",
HFILL
}
},
{ &hf_image_width,
{ "Image width",
IMG_GIF ".image.width",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Image width.",
HFILL
}
},
{ &hf_image_height,
{ "Image height",
IMG_GIF ".image.height",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Image height.",
HFILL
}
},
{ &hf_image_code_size,
{ "LZW minimum code size",
IMG_GIF ".image.code_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Minimum code size for the LZW compression.",
HFILL
}
},
{ &hf_trailer,
{ "Trailer (End of the GIF stream)",
IMG_GIF ".end",
FT_NONE, BASE_NONE, NULL, 0x00,
"This byte tells the decoder that the data stream is finished.",
HFILL
}
},
};
static gint *ett[] = {
&ett_gif,
&ett_global_flags,
&ett_local_flags,
&ett_extension,
&ett_image,
};
proto_gif = proto_register_protocol(
"Compuserve GIF",
"GIF image",
IMG_GIF
);
proto_register_field_array(proto_gif, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(IMG_GIF, dissect_gif, proto_gif);
}
void
proto_reg_handoff_gif(void)
{
dissector_handle_t gif_handle = find_dissector(IMG_GIF);
dissector_add_string("media_type", "image/gif", gif_handle);
heur_dissector_add("http", dissect_gif_heur, proto_gif);
heur_dissector_add("wtap_file", dissect_gif_heur, proto_gif);
}
