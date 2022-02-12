void
proto_register_cds_solicit (void)
{
static hf_register_info hf[] = {
{ &hf_cds_solicit_opnum,
{ "Operation", "cds_solicit.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_cds_solicit,
};
proto_cds_solicit = proto_register_protocol ("DCE/RPC CDS Solicitation", "cds_solicit", "cds_solicit");
proto_register_field_array (proto_cds_solicit, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_cds_solicit (void)
{
dcerpc_init_uuid (proto_cds_solicit, ett_cds_solicit, &uuid_cds_solicit, ver_cds_solicit, cds_solicit_dissectors, hf_cds_solicit_opnum);
}
