void
proto_register_rs_prop_acl (void)
{
static hf_register_info hf[] = {
{&hf_rs_prop_acl_opnum,
{"Operation", "rs_prop_acl.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_prop_acl,
};
proto_rs_prop_acl =
proto_register_protocol
("DCE/RPC Registry server propagation interface - ACLs", "rs_prop_acl",
"rs_prop_acl");
proto_register_field_array (proto_rs_prop_acl, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_prop_acl (void)
{
dcerpc_init_uuid (proto_rs_prop_acl, ett_rs_prop_acl, &uuid_rs_prop_acl,
ver_rs_prop_acl, rs_prop_acl_dissectors,
hf_rs_prop_acl_opnum);
}
