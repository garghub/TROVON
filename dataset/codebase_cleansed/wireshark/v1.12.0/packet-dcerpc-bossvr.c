void
proto_register_dcerpc_bossvr (void)
{
static hf_register_info hf[] = {
{ &hf_bossvr_opnum,
{ "Operation", "bossvr.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_bossvr,
};
proto_bossvr = proto_register_protocol ("DCE DFS Basic Overseer Server", "BOSSVR", "bossvr");
proto_register_field_array (proto_bossvr, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_dcerpc_bossvr (void)
{
dcerpc_init_uuid (proto_bossvr, ett_bossvr, &uuid_bossvr, ver_bossvr, bossvr_dissectors, hf_bossvr_opnum);
}
