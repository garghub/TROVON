void
proto_register_clearcase(void)
{
static hf_register_info hf[] = {
{ &hf_clearcase_procedure_v3, {
"V3 Procedure", "clearcase.procedure_v3", FT_UINT32, BASE_DEC,
VALS(clearcase3_proc_vals), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_clearcase
};
proto_clearcase = proto_register_protocol("Clearcase NFS",
"CLEARCASE", "clearcase");
proto_register_field_array(proto_clearcase, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_clearcase(void)
{
rpc_init_prog(proto_clearcase, CLEARCASE_PROGRAM, ett_clearcase,
G_N_ELEMENTS(clearcase_vers_info), clearcase_vers_info);
}
