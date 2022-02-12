void
capture_clip( const guchar *pd, int len, packet_counts *ld ) {
capture_ip(pd, 0, len, ld);
}
static void
dissect_clip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
proto_item *ti;
pinfo->current_proto = "CLIP";
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CLIP");
col_set_str(pinfo->cinfo, COL_INFO, "Classical IP frame");
if(tree) {
ti = proto_tree_add_text(tree, tvb, 0, 0, "Classical IP frame" );
fh_tree = proto_item_add_subtree(ti, ett_clip);
proto_tree_add_text(fh_tree, tvb, 0, 0, "No link information available");
}
call_dissector(ip_handle, tvb, pinfo, tree);
}
void
proto_register_clip(void)
{
static gint *ett[] = {
&ett_clip,
};
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_clip(void)
{
dissector_handle_t clip_handle;
ip_handle = find_dissector("ip");
clip_handle = create_dissector_handle(dissect_clip, -1);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LINUX_ATM_CLIP, clip_handle);
}
