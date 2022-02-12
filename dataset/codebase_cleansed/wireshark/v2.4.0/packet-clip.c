static int
dissect_clip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *fh_item;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CLIP");
col_set_str(pinfo->cinfo, COL_INFO, "Classical IP frame");
fh_item = proto_tree_add_item(tree, proto_clip, tvb, 0, 0, ENC_NA);
expert_add_info(pinfo, fh_item, &ei_no_link_info);
call_dissector(ip_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_clip(void)
{
static gint *ett[] = {
&ett_clip,
};
static ei_register_info ei[] = {
{ &ei_no_link_info, { "clip.no_link_info", PI_PROTOCOL, PI_NOTE, "No link information available", EXPFILL }},
};
expert_module_t* expert_clip;
proto_clip = proto_register_protocol("Classical IP frame", "CLIP", "clip");
proto_register_subtree_array(ett, array_length(ett));
expert_clip = expert_register_protocol(proto_clip);
expert_register_field_array(expert_clip, ei, array_length(ei));
}
void
proto_reg_handoff_clip(void)
{
dissector_handle_t clip_handle;
ip_handle = find_dissector_add_dependency("ip", proto_clip);
clip_handle = create_dissector_handle(dissect_clip, proto_clip);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LINUX_ATM_CLIP, clip_handle);
}
