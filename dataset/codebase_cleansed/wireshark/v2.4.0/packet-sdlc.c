static int
dissect_sdlc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *sdlc_tree;
proto_item *sdlc_ti;
guint8 addr;
guint16 control;
int sdlc_header_len;
gboolean is_response;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SDLC");
col_clear(pinfo->cinfo, COL_INFO);
addr = tvb_get_guint8(tvb, 0);
sdlc_header_len = 1;
if (pinfo->p2p_dir == P2P_DIR_SENT) {
is_response = FALSE;
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DCE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DTE");
}
else {
is_response = TRUE;
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DTE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DCE");
}
sdlc_ti = proto_tree_add_item(tree, proto_sdlc, tvb, 0, -1,
ENC_NA);
sdlc_tree = proto_item_add_subtree(sdlc_ti, ett_sdlc);
proto_tree_add_uint(sdlc_tree, hf_sdlc_address, tvb, 0, 1,
addr);
control = dissect_xdlc_control(tvb, 1, pinfo, sdlc_tree, hf_sdlc_control,
ett_sdlc_control, &sdlc_cf_items, NULL, NULL, NULL,
is_response, FALSE, FALSE);
sdlc_header_len += XDLC_CONTROL_LEN(control, FALSE);
proto_item_set_len(sdlc_ti, sdlc_header_len);
next_tvb = tvb_new_subset_remaining(tvb, sdlc_header_len);
if (XDLC_IS_INFORMATION(control)) {
call_dissector(sna_handle, next_tvb, pinfo, tree);
} else
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_sdlc(void)
{
static hf_register_info hf[] = {
{ &hf_sdlc_address,
{ "Address Field", "sdlc.address", FT_UINT8, BASE_HEX,
NULL, 0x0, "Address", HFILL }},
{ &hf_sdlc_control,
{ "Control Field", "sdlc.control", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sdlc_n_r,
{ "N(R)", "sdlc.control.n_r", FT_UINT8, BASE_DEC,
NULL, XDLC_N_R_MASK, NULL, HFILL }},
{ &hf_sdlc_n_s,
{ "N(S)", "sdlc.control.n_s", FT_UINT8, BASE_DEC,
NULL, XDLC_N_S_MASK, NULL, HFILL }},
{ &hf_sdlc_p,
{ "Poll", "sdlc.control.p", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_sdlc_f,
{ "Final", "sdlc.control.f", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_sdlc_s_ftype,
{ "Supervisory frame type", "sdlc.control.s_ftype", FT_UINT8, BASE_HEX,
VALS(stype_vals), XDLC_S_FTYPE_MASK, NULL, HFILL }},
{ &hf_sdlc_u_modifier_cmd,
{ "Command", "sdlc.control.u_modifier_cmd", FT_UINT8, BASE_HEX,
VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_sdlc_u_modifier_resp,
{ "Response", "sdlc.control.u_modifier_resp", FT_UINT8, BASE_HEX,
VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_sdlc_ftype_i,
{ "Frame type", "sdlc.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_I_MASK, NULL, HFILL }},
{ &hf_sdlc_ftype_s_u,
{ "Frame type", "sdlc.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
};
static gint *ett[] = {
&ett_sdlc,
&ett_sdlc_control,
};
proto_sdlc = proto_register_protocol(
"Synchronous Data Link Control (SDLC)", "SDLC", "sdlc");
proto_register_field_array(proto_sdlc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sdlc(void)
{
dissector_handle_t sdlc_handle;
sna_handle = find_dissector_add_dependency("sna", proto_sdlc);
sdlc_handle = create_dissector_handle(dissect_sdlc, proto_sdlc);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SDLC, sdlc_handle);
}
