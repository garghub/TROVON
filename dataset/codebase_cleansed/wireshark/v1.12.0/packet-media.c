static int
dissect_media(tvbuff_t *tvb, packet_info *pinfo , proto_tree *tree, void* data)
{
int bytes;
proto_item *ti;
proto_tree *media_tree = 0;
heur_dtbl_entry_t *hdtbl_entry;
if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, data)) {
return tvb_length(tvb);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", (pinfo->match_string) ? pinfo->match_string : "");
if (tree) {
if ( (bytes = tvb_length(tvb)) > 0 )
{
ti = proto_tree_add_item(tree, proto_media, tvb, 0, -1, ENC_NA);
media_tree = proto_item_add_subtree(ti, ett_media);
if (pinfo->private_data) {
proto_tree_add_text(media_tree, tvb, 0, bytes,
"Media Type: %s; %s (%d byte%s)",
pinfo->match_string, (char *)pinfo->private_data,
bytes, plurality(bytes, "", "s"));
} else {
proto_tree_add_text(media_tree, tvb, 0, bytes,
"Media Type: %s (%d byte%s)",
pinfo->match_string ? pinfo->match_string : "",
bytes, plurality(bytes, "", "s"));
}
}
}
return tvb_length(tvb);
}
void
proto_register_media(void)
{
static gint *ett[] = {
&ett_media
};
proto_media = proto_register_protocol (
"Media Type",
"Media",
"media"
);
new_register_dissector("media", dissect_media, proto_media);
register_heur_dissector_list("media", &heur_subdissector_list);
proto_register_subtree_array(ett, array_length(ett));
proto_set_cant_toggle(proto_media);
}
