static void
dissect_msnms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *msnms_tree;
proto_item *ti;
gint offset = 0;
const guchar *line;
gint next_offset;
int linelen;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSNMS");
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
col_add_str(pinfo->cinfo, COL_INFO,
format_text(line, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_msnms, tvb, offset, -1,
ENC_NA);
msnms_tree = proto_item_add_subtree(ti, ett_msnms);
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1,
&next_offset, FALSE);
proto_tree_add_format_text(msnms_tree, tvb, offset, next_offset - offset);
offset = next_offset;
}
}
}
void
proto_register_msnms(void)
{
static gint *ett[] = {
&ett_msnms,
};
proto_msnms = proto_register_protocol("MSN Messenger Service", "MSNMS", "msnms");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_msnms(void)
{
dissector_handle_t msnms_handle;
msnms_handle = create_dissector_handle(dissect_msnms, proto_msnms);
dissector_add_uint("tcp.port", TCP_PORT_MSNMS, msnms_handle);
dissector_add_string("media_type", "application/x-msn-messenger", msnms_handle);
}
