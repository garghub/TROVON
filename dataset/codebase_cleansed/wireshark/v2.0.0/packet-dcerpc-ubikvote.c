void
proto_register_ubikvote (void)
{
static hf_register_info hf[] = {
{ &hf_ubikvote_opnum,
{ "Operation", "ubikvote.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ubikvote,
};
proto_ubikvote = proto_register_protocol ("DCE DFS FLDB UBIKVOTE", "UBIKVOTE", "ubikvote");
proto_register_field_array (proto_ubikvote, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_ubikvote (void)
{
dcerpc_init_uuid (proto_ubikvote, ett_ubikvote, &uuid_ubikvote, ver_ubikvote, ubikvote_dissectors, hf_ubikvote_opnum);
}
