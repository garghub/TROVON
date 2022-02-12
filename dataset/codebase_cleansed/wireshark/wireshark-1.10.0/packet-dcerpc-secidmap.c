void
proto_register_secidmap (void)
{
static hf_register_info hf[] = {
{ &hf_secidmap_opnum,
{ "Operation", "secidmap.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_secidmap,
};
proto_secidmap = proto_register_protocol ("DCE Security ID Mapper", "SECIDMAP", "secidmap");
proto_register_field_array (proto_secidmap, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_secidmap (void)
{
dcerpc_init_uuid (proto_secidmap, ett_secidmap, &uuid_secidmap, ver_secidmap, secidmap_dissectors, hf_secidmap_opnum);
}
