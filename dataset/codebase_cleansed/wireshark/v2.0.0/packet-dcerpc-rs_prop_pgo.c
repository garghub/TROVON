void
proto_register_rs_prop_pgo (void)
{
static hf_register_info hf[] = {
{&hf_rs_prop_pgo_opnum,
{"Operation", "rs_prop_pgo.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_prop_pgo,
};
proto_rs_prop_pgo =
proto_register_protocol
("DCE/RPC Registry server propagation interface - PGO items",
"rs_prop_pgo", "rs_prop_pgo");
proto_register_field_array (proto_rs_prop_pgo, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_prop_pgo (void)
{
dcerpc_init_uuid (proto_rs_prop_pgo, ett_rs_prop_pgo, &uuid_rs_prop_pgo,
ver_rs_prop_pgo, rs_prop_pgo_dissectors,
hf_rs_prop_pgo_opnum);
}
