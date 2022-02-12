void
proto_register_rs_attr_schema (void)
{
static hf_register_info hf[] = {
{&hf_rs_attr_schema_opnum,
{"Operation", "rs_attr_schema.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rs_attr_schema,
};
proto_rs_attr_schema =
proto_register_protocol ("DCE/RPC Registry Server Attributes Schema",
"rs_attr_schema", "rs_attr_schema");
proto_register_field_array (proto_rs_attr_schema, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_attr_schema (void)
{
dcerpc_init_uuid (proto_rs_attr_schema, ett_rs_attr_schema,
&uuid_rs_attr_schema, ver_rs_attr_schema,
rs_attr_schema_dissectors, hf_rs_attr_schema_opnum);
}
