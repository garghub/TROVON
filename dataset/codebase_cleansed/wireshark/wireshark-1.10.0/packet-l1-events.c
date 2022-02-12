static void
dissect_l1_events(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *subtree;
proto_item *ti;
gint offset = 0, next_offset;
gint len;
const char *data_name;
data_name = pinfo->match_string;
if (! (data_name && data_name[0])) {
data_name = (char *)(pinfo->private_data);
if (! (data_name && data_name[0])) {
data_name = NULL;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Layer1");
if (check_col(pinfo->cinfo, COL_DEF_SRC))
col_set_str(pinfo->cinfo, COL_DEF_SRC,
pinfo->pseudo_header->l1event.uton? "TE" : "NT");
if (check_col(pinfo->cinfo, COL_INFO)) {
len = tvb_find_line_end(tvb, 0,
tvb_ensure_length_remaining(tvb, 0),
&next_offset, FALSE);
if(len>0)
col_add_str(pinfo->cinfo, COL_INFO,
tvb_format_text(tvb, 0, len));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_l1_events,
tvb, 0, -1, ENC_NA);
if (data_name)
proto_item_append_text(ti, ": %s", data_name);
subtree = proto_item_add_subtree(ti, ett_l1_events);
while (tvb_reported_length_remaining(tvb, offset) != 0) {
len = tvb_find_line_end(tvb, offset,
tvb_ensure_length_remaining(tvb, offset),
&next_offset, FALSE);
if (len == -1)
break;
proto_tree_add_text(subtree, tvb, offset, next_offset - offset,
"%s", tvb_format_text(tvb, offset,
next_offset - offset));
offset = next_offset;
}
}
}
void
proto_register_l1_events(void)
{
static gint *ett[] = {
&ett_l1_events,
};
proto_register_subtree_array(ett, array_length(ett));
proto_l1_events = proto_register_protocol(
"Layer 1 Event Messages",
"Layer 1 Events",
"data-l1-events");
register_dissector("data-l1-events", dissect_l1_events, proto_l1_events);
}
void
proto_reg_handoff_l1_events(void)
{
dissector_handle_t l1_events_handle;
l1_events_handle = find_dissector("data-l1-events");
dissector_add_uint("wtap_encap", WTAP_ENCAP_LAYER1_EVENT, l1_events_handle);
}
