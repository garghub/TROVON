void
proto_register_tkn4int (void)
{
static hf_register_info hf[] = {
{ &hf_tkn4int_opnum,
{ "Operation", "tkn4int.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_tkn4int,
};
proto_tkn4int = proto_register_protocol ("DCE DFS Token Server", "TKN4Int", "tkn4int");
proto_register_field_array (proto_tkn4int, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_tkn4int (void)
{
dcerpc_init_uuid (proto_tkn4int, ett_tkn4int, &uuid_tkn4int, ver_tkn4int, tkn4int_dissectors, hf_tkn4int_opnum);
}
