void
proto_register_rs_replist (void)
{
static hf_register_info hf[] = {
{ &hf_rs_replist_opnum,
{ "Operation", "rs_replist.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_rs_replist,
};
proto_rs_replist = proto_register_protocol ("DCE/RPC Repserver Calls", "RS_REPLIST", "rs_replist");
proto_register_field_array (proto_rs_replist, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_replist (void)
{
dcerpc_init_uuid (proto_rs_replist, ett_rs_replist, &uuid_rs_replist, ver_rs_replist, rs_replist_dissectors, hf_rs_replist_opnum);
}
