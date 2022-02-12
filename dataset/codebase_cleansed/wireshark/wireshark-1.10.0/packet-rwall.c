static int
dissect_rwall_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_string(tvb, tree, hf_rwall_message, offset, NULL);
return offset;
}
void
proto_register_rwall(void)
{
static hf_register_info hf[] = {
{ &hf_rwall_procedure_v1, {
"V1 Procedure", "rwall.procedure_v1", FT_UINT32, BASE_DEC,
VALS(rwall1_proc_vals), 0, NULL, HFILL }},
{ &hf_rwall_message, {
"Message", "rwall.message", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rwall,
};
proto_rwall = proto_register_protocol("Remote Wall protocol",
"RWALL", "rwall");
proto_register_field_array(proto_rwall, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rwall(void)
{
rpc_init_prog(proto_rwall, RWALL_PROGRAM, ett_rwall);
rpc_init_proc_table(RWALL_PROGRAM, 1, rwall1_proc, hf_rwall_procedure_v1);
}
