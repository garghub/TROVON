static int
dissect_mime_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item* item;
heur_dtbl_entry_t *hdtbl_entry;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MIME_FILE");
item = proto_tree_add_item(tree, proto_mime_encap, tvb, 0, -1, ENC_NA);
if (!dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, NULL)) {
proto_item_append_text(item, " (Unhandled)");
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_mime_encap(void)
{
proto_mime_encap = proto_register_protocol("MIME file", "MIME_FILE", "mime_dlt");
register_dissector("mime_dlt", dissect_mime_encap, proto_mime_encap);
heur_subdissector_list = register_heur_dissector_list("wtap_file", proto_mime_encap);
}
void
proto_reg_handoff_mime_encap(void)
{
dissector_handle_t mime_encap_handle;
mime_encap_handle = find_dissector("mime_dlt");
dissector_add_uint("wtap_encap", WTAP_ENCAP_MIME, mime_encap_handle);
}
