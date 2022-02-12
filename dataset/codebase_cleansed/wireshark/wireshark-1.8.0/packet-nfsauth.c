void
proto_register_nfsauth(void)
{
static hf_register_info hf[] = {
{ &hf_nfsauth_procedure_v1, {
"V1 Procedure", "nfsauth.procedure_v1", FT_UINT32, BASE_DEC,
VALS(nfsauth1_proc_vals), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_nfsauth,
};
proto_nfsauth = proto_register_protocol("NFSAUTH", "NFSAUTH", "nfsauth");
proto_register_field_array(proto_nfsauth, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nfsauth(void)
{
rpc_init_prog(proto_nfsauth, NFSAUTH_PROGRAM, ett_nfsauth);
rpc_init_proc_table(NFSAUTH_PROGRAM, 1, nfsauth1_proc, hf_nfsauth_procedure_v1);
}
