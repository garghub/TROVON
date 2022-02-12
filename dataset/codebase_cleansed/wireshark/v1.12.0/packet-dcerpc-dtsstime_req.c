void
proto_register_dtsstime_req (void)
{
static hf_register_info hf[] = {
{ &hf_dtsstime_req_opnum,
{ "Operation", "dtsstime_req.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_dtsstime_req,
};
proto_dtsstime_req = proto_register_protocol ("DCE Distributed Time Service Local Server", "DTSSTIME_REQ", "dtsstime_req");
proto_register_field_array (proto_dtsstime_req, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_dtsstime_req (void)
{
dcerpc_init_uuid (proto_dtsstime_req, ett_dtsstime_req, &uuid_dtsstime_req, ver_dtsstime_req, dtsstime_req_dissectors, hf_dtsstime_req_opnum);
}
