void
proto_register_rs_attr (void)
{
static hf_register_info hf[] = {
{ &hf_rs_attr_opnum,
{ "Operation", "rs_attr.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rs_attr,
};
proto_rs_attr = proto_register_protocol ("Registry Server Attributes Manipulation Interface", "RS_ATTR", "rs_attr");
proto_register_field_array (proto_rs_attr, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_attr (void)
{
dcerpc_init_uuid (proto_rs_attr, ett_rs_attr, &uuid_rs_attr, ver_rs_attr, rs_attr_dissectors, hf_rs_attr_opnum);
}
