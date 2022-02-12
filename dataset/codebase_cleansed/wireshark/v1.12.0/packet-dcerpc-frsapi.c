void
proto_register_dcerpc_frsapi(void)
{
static hf_register_info hf[] = {
{ &hf_frsapi_opnum,
{ "Operation", "frsapi.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_frsapi,
};
proto_dcerpc_frsapi = proto_register_protocol(
"Microsoft File Replication Service API", "FRSAPI", "frsapi");
proto_register_field_array(proto_dcerpc_frsapi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_frsapi(void)
{
dcerpc_init_uuid(
proto_dcerpc_frsapi, ett_dcerpc_frsapi, &uuid_dcerpc_frsapi,
ver_dcerpc_frsapi, dcerpc_frsapi_dissectors, hf_frsapi_opnum);
}
