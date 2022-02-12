void
proto_register_dcerpc_trksvr(void)
{
static hf_register_info hf[] = {
{ &hf_trksvr_opnum, {
"Operation", "trksvr.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_trksvr_rc, {
"Return code", "trksvr.rc", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0x0, "TRKSVR return code", HFILL }},
#endif
};
static gint *ett[] = {
&ett_dcerpc_trksvr
};
proto_dcerpc_trksvr = proto_register_protocol(
"Microsoft Distributed Link Tracking Server Service", "TRKSVR", "trksvr");
proto_register_field_array(proto_dcerpc_trksvr, hf,
array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_trksvr(void)
{
dcerpc_init_uuid(proto_dcerpc_trksvr, ett_dcerpc_trksvr,
&uuid_dcerpc_trksvr, ver_dcerpc_trksvr,
dcerpc_trksvr_dissectors, hf_trksvr_opnum);
}
