static int
dissect_text_lines(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *subtree;
proto_item *ti;
gint offset = 0, next_offset;
gint len;
const char *data_name;
int length = tvb_length(tvb);
if(length > 38){
if (tvb_strncaseeql(tvb, 0, "<?xml", 5) == 0){
call_dissector(xml_handle, tvb, pinfo, tree);
return tvb_length(tvb);
}
}
data_name = pinfo->match_string;
if (! (data_name && data_name[0])) {
data_name = (char *)data;
if (! (data_name && data_name[0])) {
data_name = (char *)(pinfo->private_data);
if (! (data_name && data_name[0])) {
data_name = NULL;
}
}
}
if (data_name)
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(%s)",
data_name);
if (tree) {
ti = proto_tree_add_item(tree, proto_text_lines,
tvb, 0, -1, ENC_NA);
if (data_name)
proto_item_append_text(ti, ": %s", data_name);
subtree = proto_item_add_subtree(ti, ett_text_lines);
while (tvb_reported_length_remaining(tvb, offset) != 0) {
len = tvb_find_line_end(tvb, offset,
tvb_ensure_length_remaining(tvb, offset),
&next_offset, FALSE);
if (len == -1)
break;
proto_tree_add_format_text(subtree, tvb, offset, next_offset - offset);
offset = next_offset;
}
}
return tvb_length(tvb);
}
void
proto_register_text_lines(void)
{
static gint *ett[] = {
&ett_text_lines,
};
proto_register_subtree_array(ett, array_length(ett));
proto_text_lines = proto_register_protocol(
"Line-based text data",
"Line-based text data",
"data-text-lines");
new_register_dissector("data-text-lines", dissect_text_lines, proto_text_lines);
}
void
proto_reg_handoff_text_lines(void)
{
dissector_handle_t text_lines_handle;
text_lines_handle = find_dissector("data-text-lines");
dissector_add_string("media_type", "text/plain", text_lines_handle);
dissector_add_string("media_type", "text/richtext", text_lines_handle);
dissector_add_string("media_type", "text/enriched", text_lines_handle);
dissector_add_string("media_type", "text/parameters", text_lines_handle);
dissector_add_string("media_type", "text/html", text_lines_handle);
dissector_add_string("media_type", "text/xml-external-parsed-entity", text_lines_handle);
dissector_add_string("media_type", "text/css", text_lines_handle);
dissector_add_string("media_type", "application/xml-external-parsed-entity", text_lines_handle);
dissector_add_string("media_type", "text/javascript", text_lines_handle);
dissector_add_string("media_type", "application/x-javascript", text_lines_handle);
dissector_add_string("media_type", "application/x-tia-p25-issi", text_lines_handle);
dissector_add_string("media_type", "application/x-tia-p25-sndcp", text_lines_handle);
dissector_add_string("media_type", "application/x-ns-proxy-autoconfig", text_lines_handle);
dissector_add_string("media_type", "text/vnd.sun.j2me.app-descriptor", text_lines_handle);
dissector_add_string("media_type", "application/vnd.poc.refer-to", text_lines_handle);
dissector_add_string("media_type", "application/vnd.drm.message", text_lines_handle);
dissector_add_string("media_type", "application/x-wms-logplaystats", text_lines_handle);
dissector_add_string("media_type", "application/x-rtsp-udp-packetpair", text_lines_handle);
xml_handle = find_dissector("xml");
}
