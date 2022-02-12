void
proto_register_ypxfr(void)
{
static hf_register_info hf[] = {
{ &hf_ypxfr_procedure_v1, {
"V1 Procedure", "ypxfr.procedure_v1", FT_UINT32, BASE_DEC,
VALS(ypxfr1_proc_vals), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ypxfr
};
proto_ypxfr = proto_register_protocol("Yellow Pages Transfer",
"YPXFR", "ypxfr");
proto_register_field_array(proto_ypxfr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ypxfr(void)
{
rpc_init_prog(proto_ypxfr, YPXFR_PROGRAM, ett_ypxfr);
rpc_init_proc_table(YPXFR_PROGRAM, 1, ypxfr1_proc, hf_ypxfr_procedure_v1);
}
