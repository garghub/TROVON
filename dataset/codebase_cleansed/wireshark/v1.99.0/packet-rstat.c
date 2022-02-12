void
proto_register_rstat(void)
{
static hf_register_info hf[] = {
{ &hf_rstat_procedure_v1, {
"V1 Procedure", "rstat.procedure_v1", FT_UINT32, BASE_DEC,
VALS(rstat1_proc_vals), 0, NULL, HFILL }},
{ &hf_rstat_procedure_v2, {
"V2 Procedure", "rstat.procedure_v2", FT_UINT32, BASE_DEC,
VALS(rstat2_proc_vals), 0, NULL, HFILL }},
{ &hf_rstat_procedure_v3, {
"V3 Procedure", "rstat.procedure_v3", FT_UINT32, BASE_DEC,
VALS(rstat3_proc_vals), 0, NULL, HFILL }},
{ &hf_rstat_procedure_v4, {
"V4 Procedure", "rstat.procedure_v4", FT_UINT32, BASE_DEC,
VALS(rstat4_proc_vals), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rstat,
};
proto_rstat = proto_register_protocol("RSTAT", "RSTAT", "rstat");
proto_register_field_array(proto_rstat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rstat(void)
{
rpc_init_prog(proto_rstat, RSTAT_PROGRAM, ett_rstat);
rpc_init_proc_table(RSTAT_PROGRAM, 1, rstat1_proc, hf_rstat_procedure_v1);
rpc_init_proc_table(RSTAT_PROGRAM, 2, rstat2_proc, hf_rstat_procedure_v2);
rpc_init_proc_table(RSTAT_PROGRAM, 3, rstat3_proc, hf_rstat_procedure_v3);
rpc_init_proc_table(RSTAT_PROGRAM, 4, rstat4_proc, hf_rstat_procedure_v4);
}
