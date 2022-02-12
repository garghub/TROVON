void
proto_register_cprpc_server (void)
{
static hf_register_info hf[] = {
{ &hf_cprpc_server_opnum,
{ "Operation", "cprpc_server.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_cprpc_server,
};
proto_cprpc_server = proto_register_protocol ("DNS Control Program Server", "cprpc_server", "cprpc_server");
proto_register_field_array (proto_cprpc_server, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_cprpc_server (void)
{
dcerpc_init_uuid (proto_cprpc_server, ett_cprpc_server, &uuid_cprpc_server, ver_cprpc_server, cprpc_server_dissectors, hf_cprpc_server_opnum);
}
