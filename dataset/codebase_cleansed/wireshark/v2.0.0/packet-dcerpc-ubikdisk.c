void
proto_register_ubikdisk (void)
{
static hf_register_info hf[] = {
{ &hf_ubikdisk_opnum,
{ "Operation", "ubikdisk.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ubikdisk,
};
proto_ubikdisk = proto_register_protocol ("DCE DFS FLDB UBIK TRANSFER", "UBIKDISK", "ubikdisk");
proto_register_field_array (proto_ubikdisk, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_ubikdisk (void)
{
dcerpc_init_uuid (proto_ubikdisk, ett_ubikdisk, &uuid_ubikdisk, ver_ubikdisk, ubikdisk_dissectors, hf_ubikdisk_opnum);
}
