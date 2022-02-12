void
proto_register_dcerpc_rras(void)
{
static hf_register_info hf[] = {
{ &hf_rras_opnum,
{ "Operation", "rras.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_rras,
};
proto_dcerpc_rras = proto_register_protocol(
"Microsoft Routing and Remote Access Service", "RRAS", "rras");
proto_register_field_array(proto_dcerpc_rras, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_rras(void)
{
dcerpc_init_uuid(
proto_dcerpc_rras, ett_dcerpc_rras, &uuid_dcerpc_rras,
ver_dcerpc_rras, dcerpc_rras_dissectors, hf_rras_opnum);
}
