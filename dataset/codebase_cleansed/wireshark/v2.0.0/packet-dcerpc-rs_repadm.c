void
proto_register_rs_repadm (void)
{
static hf_register_info hf[] = {
{ &hf_rs_repadm_opnum,
{ "Operation", "rs_repadm.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_rs_repadm,
};
proto_rs_repadm = proto_register_protocol ("Registry server administration operations.", "RS_REPADM", "rs_repadm");
proto_register_field_array (proto_rs_repadm, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_repadm (void)
{
dcerpc_init_uuid (proto_rs_repadm, ett_rs_repadm, &uuid_rs_repadm, ver_rs_repadm, rs_repadm_dissectors, hf_rs_repadm_opnum);
}
