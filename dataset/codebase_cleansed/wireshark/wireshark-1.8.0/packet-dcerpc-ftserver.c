void
proto_register_ftserver (void)
{
static hf_register_info hf[] = {
{ &hf_ftserver_opnum,
{ "Operation", "ftserver.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ftserver,
};
proto_ftserver = proto_register_protocol ("FTServer Operations", "FTSERVER", "ftserver");
proto_register_field_array (proto_ftserver, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_ftserver (void)
{
dcerpc_init_uuid (proto_ftserver, ett_ftserver, &uuid_ftserver, ver_ftserver, ftserver_dissectors, hf_ftserver_opnum);
}
