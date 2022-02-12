void
proto_register_rs_unix (void)
{
static hf_register_info hf[] = {
{ &hf_rs_unix_opnum,
{ "Operation", "rs_unix.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rs_unix,
};
proto_rs_unix = proto_register_protocol ("DCE/RPC RS_UNIX", "RS_UNIX", "rs_unix");
proto_register_field_array (proto_rs_unix, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_unix (void)
{
dcerpc_init_uuid (proto_rs_unix, ett_rs_unix, &uuid_rs_unix, ver_rs_unix, rs_unix_dissectors, hf_rs_unix_opnum);
}
