static int
dissect_media(tvbuff_t *tvb, packet_info *pinfo , proto_tree *tree, void* data)
{
int bytes;
proto_item *ti;
proto_tree *media_tree = 0;
heur_dtbl_entry_t *hdtbl_entry;
if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, data)) {
return tvb_reported_length(tvb);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", (pinfo->match_string) ? pinfo->match_string : "");
if (tree) {
if ( (bytes = tvb_reported_length(tvb)) > 0 )
{
ti = proto_tree_add_item(tree, proto_media, tvb, 0, -1, ENC_NA);
media_tree = proto_item_add_subtree(ti, ett_media);
if (data) {
proto_tree_add_bytes_format_value(media_tree, hf_media_type, tvb, 0, bytes,
NULL, "%s; %s (%d byte%s)",
pinfo->match_string, (char *)data,
bytes, plurality(bytes, "", "s"));
} else {
proto_tree_add_bytes_format_value(media_tree, hf_media_type, tvb, 0, bytes,
NULL, "%s (%d byte%s)",
pinfo->match_string ? pinfo->match_string : "",
bytes, plurality(bytes, "", "s"));
}
}
}
return tvb_reported_length(tvb);
}
void
proto_register_media(void)
{
static hf_register_info hf[] = {
{ &hf_media_type,
{ "Media type", "media.type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_media
};
proto_media = proto_register_protocol (
"Media Type",
"Media",
"media"
);
new_register_dissector("media", dissect_media, proto_media);
heur_subdissector_list = register_heur_dissector_list("media");
proto_register_field_array(proto_media, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_set_cant_toggle(proto_media);
}
