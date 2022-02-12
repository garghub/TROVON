static int
dissect_rwall_call(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_string(tvb, tree, hfi_rwall_message.id, 0, NULL);
}
void
proto_register_rwall(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_rwall_procedure_v1,
&hfi_rwall_message,
};
#endif
static gint *ett[] = {
&ett_rwall,
};
int proto_rwall;
proto_rwall = proto_register_protocol("Remote Wall protocol", "RWALL", "rwall");
hfi_rwall = proto_registrar_get_nth(proto_rwall);
proto_register_fields(proto_rwall, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rwall(void)
{
rpc_init_prog(hfi_rwall->id, RWALL_PROGRAM, ett_rwall,
G_N_ELEMENTS(rwall_vers_info), rwall_vers_info);
}
