static int
dissect_statnotify_mon(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb,tree,hf_statnotify_name,offset,NULL);
offset = dissect_rpc_uint32(tvb,tree,hf_statnotify_state,offset);
proto_tree_add_item(tree,hf_statnotify_priv,tvb,offset,16,ENC_NA);
offset += 16;
return offset;
}
void
proto_register_statnotify(void)
{
static hf_register_info hf[] = {
{ &hf_statnotify_procedure_v1, {
"V1 Procedure", "statnotify.procedure_v1", FT_UINT32, BASE_DEC,
VALS(statnotify1_proc_vals), 0, NULL, HFILL }},
{ &hf_statnotify_name, {
"Name", "statnotify.name", FT_STRING, BASE_NONE,
NULL, 0, "Name of client that changed", HFILL }},
{ &hf_statnotify_state, {
"State", "statnotify.state", FT_UINT32, BASE_DEC,
NULL, 0, "New state of client that changed", HFILL }},
{ &hf_statnotify_priv, {
"Priv", "statnotify.priv", FT_BYTES, BASE_NONE,
NULL, 0, "Client supplied opaque data", HFILL }},
};
static gint *ett[] = {
&ett_statnotify,
};
proto_statnotify = proto_register_protocol("Network Status Monitor CallBack Protocol", "STAT-CB", "statnotify");
proto_register_field_array(proto_statnotify, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_statnotify(void)
{
rpc_init_prog(proto_statnotify, STATNOTIFY_PROGRAM, ett_statnotify);
rpc_init_proc_table(STATNOTIFY_PROGRAM, 1, statnotify1_proc, hf_statnotify_procedure_v1);
}
