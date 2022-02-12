void
proto_register_rs_pwd_mgmt (void)
{
static hf_register_info hf[] = {
{&hf_rs_pwd_mgmt_opnum,
{"Operation", "rs_pwd_mgmt.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_pwd_mgmt,
};
proto_rs_pwd_mgmt =
proto_register_protocol ("DCE/RPC Registry Password Management",
"rs_pwd_mgmt", "rs_pwd_mgmt");
proto_register_field_array (proto_rs_pwd_mgmt, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_pwd_mgmt (void)
{
dcerpc_init_uuid (proto_rs_pwd_mgmt, ett_rs_pwd_mgmt, &uuid_rs_pwd_mgmt,
ver_rs_pwd_mgmt, rs_pwd_mgmt_dissectors,
hf_rs_pwd_mgmt_opnum);
}
