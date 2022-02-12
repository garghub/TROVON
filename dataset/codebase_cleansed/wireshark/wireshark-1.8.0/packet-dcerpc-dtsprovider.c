void
proto_register_dtsprovider (void)
{
static hf_register_info hf[] = {
{ &hf_dtsprovider_opnum,
{ "Operation", "dtsprovider.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_dtsprovider_status,
{ "Status", "dtsprovider.status", FT_UINT32, BASE_DEC|BASE_EXT_STRING,
&dce_error_vals_ext, 0x0, "Return code, status of executed command", HFILL }}
};
static gint *ett[] = {
&ett_dtsprovider,
};
proto_dtsprovider = proto_register_protocol ("DCE Distributed Time Service Provider", "DTSPROVIDER", "dtsprovider");
proto_register_field_array (proto_dtsprovider, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_dtsprovider (void)
{
dcerpc_init_uuid (proto_dtsprovider, ett_dtsprovider, &uuid_dtsprovider, ver_dtsprovider, dtsprovider_dissectors, hf_dtsprovider_opnum);
}
