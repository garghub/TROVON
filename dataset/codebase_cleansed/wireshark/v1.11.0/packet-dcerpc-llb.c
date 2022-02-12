void
proto_register_llb (void)
{
static hf_register_info hf[] = {
{&hf_llb_opnum,
{"Operation", "llb.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
};
static gint *ett[] = {
&ett_llb,
};
proto_llb =
proto_register_protocol ("DCE/RPC NCS 1.5.1 Local Location Broker", "llb",
"llb");
proto_register_field_array (proto_llb, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_llb (void)
{
dcerpc_init_uuid (proto_llb, ett_llb, &uuid_llb, ver_llb, llb_dissectors,
hf_llb_opnum);
}
