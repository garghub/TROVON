static void
lapdm_defragment_init (void)
{
fragment_table_init (&lapdm_fragment_table);
reassembled_table_init(&lapdm_reassembled_table);
}
static void
dissect_lapdm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *lapdm_tree, *addr_tree, *length_tree;
proto_item *lapdm_ti, *addr_ti, *length_ti;
guint8 addr, length, cr, sapi, len;
int control;
gboolean m;
tvbuff_t *payload;
int available_length;
gboolean is_response = FALSE;
if (tvb_length(tvb) < LAPDM_HEADER_LEN)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LAPDm");
addr = tvb_get_guint8(tvb, 0);
length = tvb_get_guint8(tvb, 2);
cr = addr & LAPDM_CR;
if (pinfo->p2p_dir == P2P_DIR_RECV) {
is_response = cr ? FALSE : TRUE;
}
else if (pinfo->p2p_dir == P2P_DIR_SENT) {
is_response = cr ? TRUE : FALSE;
}
if (tree) {
lapdm_ti = proto_tree_add_item(tree, proto_lapdm, tvb, 0, LAPDM_HEADER_LEN, ENC_NA);
lapdm_tree = proto_item_add_subtree(lapdm_ti, ett_lapdm);
addr_ti = proto_tree_add_uint(lapdm_tree, hf_lapdm_address, tvb, 0, 1, addr);
addr_tree = proto_item_add_subtree(addr_ti, ett_lapdm_address);
proto_tree_add_uint(addr_tree, hf_lapdm_lpd, tvb, 0, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapdm_sapi, tvb, 0, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapdm_cr, tvb, 0, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapdm_ea, tvb, 0, 1, addr);
}
else {
lapdm_ti = NULL;
lapdm_tree = NULL;
}
control = dissect_xdlc_control(tvb, 1, pinfo, lapdm_tree, hf_lapdm_control,
ett_lapdm_control, &lapdm_cf_items, NULL , NULL, NULL,
is_response, FALSE, FALSE);
if (tree) {
length_ti = proto_tree_add_uint(lapdm_tree, hf_lapdm_length, tvb,
2, 1, length);
length_tree = proto_item_add_subtree(length_ti, ett_lapdm_length);
proto_tree_add_uint(length_tree, hf_lapdm_len, tvb, 2, 1, length);
proto_tree_add_uint(length_tree, hf_lapdm_m, tvb, 2, 1, length);
proto_tree_add_uint(length_tree, hf_lapdm_el, tvb, 2, 1, length);
}
sapi = (addr & LAPDM_SAPI) >> LAPDM_SAPI_SHIFT;
len = (length & LAPDM_LEN) >> LAPDM_LEN_SHIFT;
m = (length & LAPDM_M) >> LAPDM_M_SHIFT;
available_length = tvb_length(tvb) - LAPDM_HEADER_LEN;
if( !MIN(len, available_length) )
return;
payload = tvb_new_subset(tvb, LAPDM_HEADER_LEN, MIN(len,available_length), -1);
if( (control & XDLC_I_MASK) == XDLC_I && reassemble_lapdm )
{
fragment_data *fd_m = NULL;
tvbuff_t *reassembled = NULL;
guint32 fragment_id;
gboolean save_fragmented = pinfo->fragmented;
pinfo->fragmented = m;
fragment_id = (pinfo->circuit_id << 4) | (sapi << 1) | pinfo->p2p_dir;
fd_m = fragment_add_seq_next (payload, 0, pinfo,
fragment_id,
lapdm_fragment_table,
lapdm_reassembled_table,
len,
m);
reassembled = process_reassembled_data(payload, 0, pinfo,
"Reassembled LAPDm", fd_m, &lapdm_frag_items,
NULL, lapdm_tree);
if (fd_m && pinfo->fd->num == fd_m->reassembled_in) {
if (!dissector_try_uint(lapdm_sapi_dissector_table, sapi,
reassembled, pinfo, tree))
call_dissector(data_handle, reassembled, pinfo, tree);
}
else {
col_append_str(pinfo->cinfo, COL_INFO, " (Fragment)");
if (tree) {
proto_tree_add_text(lapdm_tree, payload, 0, -1, "Fragment Data");
}
}
pinfo->fragmented = save_fragmented;
}
else
{
if (!dissector_try_uint(lapdm_sapi_dissector_table, sapi,
payload, pinfo, tree))
call_dissector(data_handle,payload, pinfo, tree);
}
}
void
proto_register_lapdm(void)
{
static hf_register_info hf[] = {
{ &hf_lapdm_address,
{ "Address Field", "lapdm.address_field", FT_UINT8, BASE_HEX, NULL, 0x0,
"Address", HFILL }},
{ &hf_lapdm_ea,
{ "EA", "lapdm.ea", FT_UINT8, BASE_DEC, VALS(lapdm_ea_vals), LAPDM_EA,
"Address field extension bit", HFILL }},
{ &hf_lapdm_cr,
{ "C/R", "lapdm.cr", FT_UINT8, BASE_DEC, NULL, LAPDM_CR,
"Command/response field bit", HFILL }},
{ &hf_lapdm_lpd,
{ "LPD", "lapdm.lpd", FT_UINT8, BASE_DEC, VALS(lapdm_lpd_vals), LAPDM_LPD,
"Link Protocol Discriminator", HFILL }},
{ &hf_lapdm_sapi,
{ "SAPI", "lapdm.sapi", FT_UINT8, BASE_DEC, VALS(lapdm_sapi_vals), LAPDM_SAPI,
"Service access point identifier", HFILL }},
{ &hf_lapdm_control,
{ "Control Field", "lapdm.control_field", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_lapdm_n_r,
{ "N(R)", "lapdm.control.n_r", FT_UINT8, BASE_DEC,
NULL, XDLC_N_R_MASK, NULL, HFILL }},
{ &hf_lapdm_n_s,
{ "N(S)", "lapdm.control.n_s", FT_UINT8, BASE_DEC,
NULL, XDLC_N_S_MASK, NULL, HFILL }},
{ &hf_lapdm_p,
{ "Poll", "lapdm.control.p", FT_BOOLEAN, 8,
TFS(&tfs_true_false), XDLC_P_F, NULL, HFILL }},
{ &hf_lapdm_f,
{ "Final", "lapdm.control.f", FT_BOOLEAN, 8,
TFS(&tfs_true_false), XDLC_P_F, NULL, HFILL }},
{ &hf_lapdm_s_ftype,
{ "Supervisory frame type", "lapdm.control.s_ftype", FT_UINT8, BASE_HEX,
VALS(stype_vals), XDLC_S_FTYPE_MASK, NULL, HFILL }},
{ &hf_lapdm_u_modifier_cmd,
{ "Command", "lapdm.control.u_modifier_cmd", FT_UINT8, BASE_HEX,
VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_lapdm_u_modifier_resp,
{ "Response", "lapdm.control.u_modifier_resp", FT_UINT8, BASE_HEX,
VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_lapdm_ftype_i,
{ "Frame type", "lapdm.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_I_MASK, NULL, HFILL }},
{ &hf_lapdm_ftype_s_u,
{ "Frame type", "lapdm.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
{ &hf_lapdm_length,
{ "Length Field", "lapdm.length_field", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_lapdm_el,
{ "EL", "lapdm.el", FT_UINT8, BASE_DEC,
VALS(lapdm_el_vals), LAPDM_EL, "Length indicator field extension bit", HFILL }},
{ &hf_lapdm_m,
{ "M", "lapdm.m", FT_UINT8, BASE_DEC,
VALS(lapdm_m_vals), LAPDM_M, "More data bit", HFILL }},
{ &hf_lapdm_len,
{ "Length", "lapdm.length", FT_UINT8, BASE_DEC,
NULL, LAPDM_LEN, "Length indicator", HFILL }},
{ &hf_lapdm_fragments,
{ "Message fragments", "lapdm.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, "LAPDm Message fragments", HFILL }},
{ &hf_lapdm_fragment,
{ "Message fragment", "lapdm.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "LAPDm Message fragment", HFILL }},
{ &hf_lapdm_fragment_overlap,
{ "Message fragment overlap", "lapdm.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "LAPDm Message fragment overlaps with other fragment(s)", HFILL }},
{ &hf_lapdm_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "lapdm.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "LAPDm Message fragment overlaps with conflicting data", HFILL }},
{ &hf_lapdm_fragment_multiple_tails,
{ "Message has multiple tail fragments", "lapdm.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "LAPDm Message fragment has multiple tail fragments", HFILL }},
{ &hf_lapdm_fragment_too_long_fragment,
{ "Message fragment too long", "lapdm.fragment.too_long_fragment", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "LAPDm Message fragment data goes beyond the packet end", HFILL }},
{ &hf_lapdm_fragment_error,
{ "Message defragmentation error", "lapdm.fragment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "LAPDm Message defragmentation error due to illegal fragments", HFILL }},
{ &hf_lapdm_fragment_count,
{ "Message fragment count", "lapdm.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL }},
{ &hf_lapdm_reassembled_in,
{ "Reassembled in", "lapdm.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "LAPDm Message has been reassembled in this packet.", HFILL }},
{ &hf_lapdm_reassembled_length,
{ "Reassembled LAPDm length", "lapdm.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, "The total length of the reassembled payload", HFILL }}
};
static gint *ett[] = {
&ett_lapdm,
&ett_lapdm_address,
&ett_lapdm_control,
&ett_lapdm_length,
&ett_lapdm_fragment,
&ett_lapdm_fragments
};
module_t *lapdm_module;
proto_lapdm = proto_register_protocol("Link Access Procedure, Channel Dm (LAPDm)", "LAPDm", "lapdm");
proto_register_field_array (proto_lapdm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("lapdm", dissect_lapdm, proto_lapdm);
lapdm_sapi_dissector_table = register_dissector_table("lapdm.sapi", "LAPDm SAPI", FT_UINT8, BASE_DEC);
lapdm_module = prefs_register_protocol(proto_lapdm, NULL);
prefs_register_bool_preference(lapdm_module, "reassemble",
"Reassemble fragmented LAPDm packets",
"Whether the dissector should defragment LAPDm messages spanning multiple packets.",
&reassemble_lapdm);
register_init_routine (lapdm_defragment_init);
}
void
proto_reg_handoff_lapdm(void)
{
data_handle = find_dissector("data");
}
