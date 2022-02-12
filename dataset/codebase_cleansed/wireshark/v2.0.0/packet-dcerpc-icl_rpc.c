void
proto_register_icl_rpc (void)
{
static hf_register_info hf[] = {
{ &hf_icl_rpc_opnum,
{ "Operation", "icl_rpc.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_icl_rpc,
};
proto_icl_rpc = proto_register_protocol ("DCE DFS ICL RPC", "ICL_RPC", "icl_rpc");
proto_register_field_array (proto_icl_rpc, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_icl_rpc (void)
{
dcerpc_init_uuid (proto_icl_rpc, ett_icl_rpc, &uuid_icl_rpc, ver_icl_rpc, icl_rpc_dissectors, hf_icl_rpc_opnum);
}
