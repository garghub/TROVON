static void
dissect_ascend(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *fh_tree;
proto_item *ti, *hidden_item;
union wtap_pseudo_header *pseudo_header = pinfo->pseudo_header;
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "N/A");
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "N/A");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "N/A");
col_set_str(pinfo->cinfo, COL_INFO, "Lucent/Ascend packet trace");
switch (pseudo_header->ascend.type) {
case ASCEND_PFX_WDS_X:
pinfo->p2p_dir = P2P_DIR_SENT;
break;
case ASCEND_PFX_WDS_R:
pinfo->p2p_dir = P2P_DIR_RECV;
break;
}
if(tree) {
ti = proto_tree_add_protocol_format(tree, proto_ascend, tvb, 0, 0,
"Lucent/Ascend packet trace");
fh_tree = proto_item_add_subtree(ti, ett_raw);
proto_tree_add_uint(fh_tree, hf_link_type, tvb, 0, 0,
pseudo_header->ascend.type);
if (pseudo_header->ascend.type == ASCEND_PFX_WDD) {
proto_tree_add_string(fh_tree, hf_called_number, tvb, 0, 0,
pseudo_header->ascend.call_num);
proto_tree_add_uint(fh_tree, hf_chunk, tvb, 0, 0,
pseudo_header->ascend.chunk);
hidden_item = proto_tree_add_uint(fh_tree, hf_session_id, tvb, 0, 0, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
proto_tree_add_string(fh_tree, hf_user_name, tvb, 0, 0,
pseudo_header->ascend.user);
proto_tree_add_uint(fh_tree, hf_session_id, tvb, 0, 0,
pseudo_header->ascend.sess);
hidden_item = proto_tree_add_uint(fh_tree, hf_chunk, tvb, 0, 0, 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
proto_tree_add_uint(fh_tree, hf_task, tvb, 0, 0, pseudo_header->ascend.task);
}
switch (pseudo_header->ascend.type) {
case ASCEND_PFX_WDS_X:
case ASCEND_PFX_WDS_R:
call_dissector(ppp_hdlc_handle, tvb, pinfo, tree);
break;
case ASCEND_PFX_WDD:
call_dissector(eth_withoutfcs_handle, tvb, pinfo, tree);
break;
default:
break;
}
}
void
proto_register_ascend(void)
{
static hf_register_info hf[] = {
{ &hf_link_type,
{ "Link type", "ascend.type", FT_UINT32, BASE_DEC, VALS(encaps_vals), 0x0,
NULL, HFILL }},
{ &hf_session_id,
{ "Session ID", "ascend.sess", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_called_number,
{ "Called number", "ascend.number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_chunk,
{ "WDD Chunk", "ascend.chunk", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_task,
{ "Task", "ascend.task", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_user_name,
{ "User name", "ascend.user", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_raw,
};
proto_ascend = proto_register_protocol("Lucent/Ascend debug output",
"Lucent/Ascend", "ascend");
proto_register_field_array(proto_ascend, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ascend(void)
{
dissector_handle_t ascend_handle;
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
ppp_hdlc_handle = find_dissector("ppp_hdlc");
ascend_handle = create_dissector_handle(dissect_ascend, proto_ascend);
dissector_add_uint("wtap_encap", WTAP_ENCAP_ASCEND, ascend_handle);
}
