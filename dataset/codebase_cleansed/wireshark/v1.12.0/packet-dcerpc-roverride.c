void
proto_register_roverride (void)
{
static hf_register_info hf[] = {
{ &hf_roverride_opnum,
{ "Operation", "roverride.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_roverride,
};
proto_roverride = proto_register_protocol ("Remote Override interface", "roverride", "roverride");
proto_register_field_array (proto_roverride, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_roverride (void)
{
dcerpc_init_uuid (proto_roverride, ett_roverride, &uuid_roverride, ver_roverride, roverride_dissectors, hf_roverride_opnum);
}
