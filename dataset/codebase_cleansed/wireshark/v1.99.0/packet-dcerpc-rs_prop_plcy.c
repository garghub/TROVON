void
proto_register_rs_prop_plcy (void)
{
static hf_register_info hf[] = {
{&hf_rs_prop_plcy_opnum,
{"Operation", "rs_prop_plcy.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_prop_plcy,
};
proto_rs_prop_plcy =
proto_register_protocol
("DCE/RPC Registry server propagation interface - properties and policies",
"rs_prop_plcy", "rs_prop_plcy");
proto_register_field_array (proto_rs_prop_plcy, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_prop_plcy (void)
{
dcerpc_init_uuid (proto_rs_prop_plcy, ett_rs_prop_plcy, &uuid_rs_prop_plcy,
ver_rs_prop_plcy, rs_prop_plcy_dissectors,
hf_rs_prop_plcy_opnum);
}
