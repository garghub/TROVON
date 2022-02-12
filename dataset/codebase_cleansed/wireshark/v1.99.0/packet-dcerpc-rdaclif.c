void
proto_register_rdaclif (void)
{
static hf_register_info hf[] = {
{&hf_rdaclif_opnum,
{"Operation", "rdaclif.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_rdaclif,
};
proto_rdaclif =
proto_register_protocol ("DCE/RPC Directory Acl Interface", "rdaclif",
"rdaclif");
proto_register_field_array (proto_rdaclif, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rdaclif (void)
{
dcerpc_init_uuid (proto_rdaclif, ett_rdaclif, &uuid_rdaclif, ver_rdaclif,
rdaclif_dissectors, hf_rdaclif_opnum);
}
