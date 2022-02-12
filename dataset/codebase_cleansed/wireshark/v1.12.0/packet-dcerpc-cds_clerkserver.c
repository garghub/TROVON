void
proto_register_cds_clerkserver (void)
{
static hf_register_info hf[] = {
{ &hf_cds_clerkserver_opnum,
{ "Operation", "cds_clerkserver.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_cds_clerkserver,
};
proto_cds_clerkserver = proto_register_protocol ("CDS Clerk Server Calls", "CDS_CLERK", "cds_clerkserver");
proto_register_field_array (proto_cds_clerkserver, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_cds_clerkserver (void)
{
dcerpc_init_uuid (proto_cds_clerkserver, ett_cds_clerkserver, &uuid_cds_clerkserver, ver_cds_clerkserver, cds_clerkserver_dissectors, hf_cds_clerkserver_opnum);
}
