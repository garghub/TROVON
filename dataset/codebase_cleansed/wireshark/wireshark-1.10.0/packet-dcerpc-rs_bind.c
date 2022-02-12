void
proto_register_rs_bind (void)
{
static hf_register_info hf[] = {
{ &hf_rs_bind_opnum,
{ "Operation", "rs_bind.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rs_bind,
};
proto_rs_bind =
proto_register_protocol ("DCE/RPC RS_BIND", "RS_BIND", "rs_bind");
proto_register_field_array (proto_rs_bind, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_bind (void)
{
dcerpc_init_uuid (proto_rs_bind, ett_rs_bind, &uuid_rs_bind, ver_rs_bind,
rs_bind_dissectors, hf_rs_bind_opnum);
}
