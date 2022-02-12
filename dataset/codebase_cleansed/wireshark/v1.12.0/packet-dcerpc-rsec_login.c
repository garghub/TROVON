void
proto_register_rsec_login (void)
{
static hf_register_info hf[] = {
{ &hf_rsec_login_opnum,
{ "Operation", "rsec_login.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rsec_login,
};
proto_rsec_login = proto_register_protocol ("Remote sec_login preauth interface.", "rsec_login", "rsec_login");
proto_register_field_array (proto_rsec_login, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rsec_login (void)
{
dcerpc_init_uuid (proto_rsec_login, ett_rsec_login, &uuid_rsec_login, ver_rsec_login, rsec_login_dissectors, hf_rsec_login_opnum);
}
