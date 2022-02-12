static void
mime_encap_init(void)
{
if (whole_file) {
g_string_free(whole_file, TRUE);
whole_file = NULL;
}
}
static void
dissect_mime_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item* item;
guint len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MIME_FILE");
item = proto_tree_add_item(tree, proto_mime_encap, tvb, 0, -1, ENC_NA);
if (pinfo->fd->abs_ts.nsecs >= 1000000000) {
proto_item_append_text(item, " (Error)");
}
if (!whole_file)
whole_file = g_string_new("");
if (!(len = tvb_length(tvb))) {
tvbuff_t *comp_tvb;
proto_item_append_text(item, " (Final)");
comp_tvb = tvb_new_child_real_data(tvb, whole_file->str, (guint) whole_file->len, (gint) whole_file->len);
add_new_data_source(pinfo, comp_tvb, "Whole file");
if (!dissector_try_heuristic(heur_subdissector_list, comp_tvb, pinfo, tree, NULL)) {
proto_item_append_text(item, " (Unhandled)");
call_dissector(data_handle, comp_tvb, pinfo, tree);
}
} else {
if (!pinfo->fd->flags.visited) {
g_string_set_size(whole_file, (gsize) pinfo->fd->file_off + len);
tvb_memcpy(tvb, whole_file->str + pinfo->fd->file_off, 0, len);
}
}
}
void
proto_register_mime_encap(void)
{
proto_mime_encap = proto_register_protocol("MIME file", "MIME_FILE", "mime_dlt");
register_dissector("mime_dlt", dissect_mime_encap, proto_mime_encap);
register_init_routine(mime_encap_init);
register_heur_dissector_list("wtap_file", &heur_subdissector_list);
}
void
proto_reg_handoff_mime_encap(void)
{
dissector_handle_t mime_encap_handle;
data_handle = find_dissector("data");
mime_encap_handle = find_dissector("mime_dlt");
dissector_add_uint("wtap_encap", WTAP_ENCAP_MIME, mime_encap_handle);
}
