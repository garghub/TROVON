void
proto_register_kadm5(void)
{
static hf_register_info hf[] = {
{ &hf_kadm5_procedure_v2, {
"V2 Procedure", "kadm5.procedure_v2", FT_UINT32, BASE_DEC,
VALS(kadm5_v2_proc_vals), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_kadm5,
};
proto_kadm5 = proto_register_protocol("Kerberos Administration",
"KADM5", "kadm5");
proto_register_field_array(proto_kadm5, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_kadm5(void)
{
rpc_init_prog(proto_kadm5, KADM5_PROGRAM, ett_kadm5,
G_N_ELEMENTS(kadm5_vers_info), kadm5_vers_info);
}
