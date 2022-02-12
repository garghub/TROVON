void
proto_register_dce_update (void)
{
static hf_register_info hf[] = {
{&hf_dce_update_opnum,
{"Operation", "dce_update.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}}
};
static gint *ett[] = {
&ett_dce_update,
};
proto_dce_update =
proto_register_protocol ("DCE/RPC UpServer", "dce_update", "dce_update");
proto_register_field_array (proto_dce_update, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_dce_update (void)
{
dcerpc_init_uuid (proto_dce_update, ett_dce_update, &uuid_dce_update,
ver_dce_update, dce_update_dissectors,
hf_dce_update_opnum);
}
