void
proto_register_dcerpc_pnp(void)
{
static hf_register_info hf[] = {
{ &hf_pnp_opnum,
{ "Operation", "pnp.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_pnp,
};
proto_dcerpc_pnp = proto_register_protocol(
"Microsoft Plug and Play service", "PNP", "pnp");
proto_register_field_array(proto_dcerpc_pnp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_pnp(void)
{
dcerpc_init_uuid(
proto_dcerpc_pnp, ett_dcerpc_pnp, &uuid_dcerpc_pnp,
ver_dcerpc_pnp, dcerpc_pnp_dissectors, hf_pnp_opnum);
}
