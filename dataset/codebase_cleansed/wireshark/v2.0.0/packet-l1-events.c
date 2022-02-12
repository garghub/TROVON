static int
dissect_l1_events(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *subtree;
proto_item *ti;
gint offset = 0, next_offset;
gint len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Layer1");
col_set_str(pinfo->cinfo, COL_DEF_SRC,
pinfo->pseudo_header->l1event.uton? "TE" : "NT");
len = tvb_find_line_end(tvb, 0, -1, &next_offset, FALSE);
if(len>0)
col_add_str(pinfo->cinfo, COL_INFO, tvb_format_text(tvb, 0, len));
if (tree) {
ti = proto_tree_add_item(tree, proto_l1_events,
tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_l1_events);
while (tvb_offset_exists(tvb, offset)) {
len = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
if (len == -1)
break;
proto_tree_add_format_text(subtree, tvb, offset, next_offset - offset);
offset = next_offset;
}
}
return tvb_captured_length(tvb);
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
}
void
proto_reg_handoff_l1_events(void)
{
dissector_handle_t l1_events_handle = new_create_dissector_handle(dissect_l1_events, proto_l1_events);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LAYER1_EVENT, l1_events_handle);
}
