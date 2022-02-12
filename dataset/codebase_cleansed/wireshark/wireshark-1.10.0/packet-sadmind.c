void
proto_register_sadmind(void)
{
static hf_register_info hf[] = {
{ &hf_sadmind_procedure_v1, {
"V1 Procedure", "sadmind.procedure_v1", FT_UINT32, BASE_DEC,
VALS(sadmind1_proc_vals), 0, NULL, HFILL }},
{ &hf_sadmind_procedure_v2, {
"V2 Procedure", "sadmind.procedure_v2", FT_UINT32, BASE_DEC,
VALS(sadmind2_proc_vals), 0, NULL, HFILL }},
{ &hf_sadmind_procedure_v3, {
"V3 Procedure", "sadmind.procedure_v3", FT_UINT32, BASE_DEC,
VALS(sadmind3_proc_vals), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_sadmind,
};
proto_sadmind = proto_register_protocol("SADMIND", "SADMIND", "sadmind");
proto_register_field_array(proto_sadmind, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_sadmind(void)
{
rpc_init_prog(proto_sadmind, SADMIND_PROGRAM, ett_sadmind);
rpc_init_proc_table(SADMIND_PROGRAM, 1, sadmind1_proc, hf_sadmind_procedure_v1);
rpc_init_proc_table(SADMIND_PROGRAM, 2, sadmind2_proc, hf_sadmind_procedure_v2);
rpc_init_proc_table(SADMIND_PROGRAM, 3, sadmind3_proc, hf_sadmind_procedure_v3);
}
