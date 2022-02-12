void
proto_register_dcerpc_rs_plcy(void)
{
static hf_register_info hf[] = {
{ &hf_rs_plcy_opnum,
{ "Operation", "rs_plcy.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_rs_plcy
};
proto_dcerpc_rs_plcy = proto_register_protocol(
"RS Interface properties", "RS_PLCY", "rs_plcy");
proto_register_field_array(proto_dcerpc_rs_plcy, hf,
array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_rs_plcy(void)
{
dcerpc_init_uuid(proto_dcerpc_rs_plcy, ett_dcerpc_rs_plcy,
&uuid_dcerpc_rs_plcy, ver_dcerpc_rs_plcy,
dcerpc_rs_plcy_dissectors, hf_rs_plcy_opnum);
}
