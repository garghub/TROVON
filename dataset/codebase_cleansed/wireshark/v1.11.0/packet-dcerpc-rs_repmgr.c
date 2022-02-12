void
proto_register_rs_repmgr (void)
{
static hf_register_info hf[] = {
{&hf_rs_repmgr_opnum,
{"Operation", "rs_repmgr.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_repmgr,
};
proto_rs_repmgr =
proto_register_protocol
("DCE/RPC Operations between registry server replicas", "rs_repmgr",
"rs_repmgr");
proto_register_field_array (proto_rs_repmgr, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_repmgr (void)
{
dcerpc_init_uuid (proto_rs_repmgr, ett_rs_repmgr, &uuid_rs_repmgr,
ver_rs_repmgr, rs_repmgr_dissectors, hf_rs_repmgr_opnum);
}
