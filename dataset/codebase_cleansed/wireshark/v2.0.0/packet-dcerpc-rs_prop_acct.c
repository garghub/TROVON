void
proto_register_rs_prop_acct (void)
{
static hf_register_info hf[] = {
{ &hf_rs_prop_acct_opnum,
{ "Operation", "rs_prop_acct.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rs_prop_acct,
};
proto_rs_prop_acct = proto_register_protocol ("DCE/RPC RS_PROP_ACCT", "rs_prop_acct", "rs_prop_acct");
proto_register_field_array (proto_rs_prop_acct, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_prop_acct (void)
{
dcerpc_init_uuid (proto_rs_prop_acct, ett_rs_prop_acct, &uuid_rs_prop_acct, ver_rs_prop_acct, rs_prop_acct_dissectors, hf_rs_prop_acct_opnum);
}
