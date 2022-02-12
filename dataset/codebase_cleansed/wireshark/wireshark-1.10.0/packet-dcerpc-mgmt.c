static int
mgmtrpc_dissect_inq_princ_name_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep,
sizeof(guint8), hf_mgmt_princ_name, TRUE, NULL);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_mgmt_rc, NULL);
return offset;
}
static int
mgmtrpc_dissect_inq_princ_name_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_mgmt_proto, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_mgmt_princ_size, NULL);
return offset;
}
void
proto_register_mgmt (void)
{
static hf_register_info hf[] = {
{ &hf_mgmt_opnum,
{ "Operation", "mgmt.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_mgmt_proto,
{"Authn Proto", "mgmt.proto", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_mgmt_princ_name,
{"Principal name", "mgmt.princ_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mgmt_princ_size,
{"Principal size", "mgmt.princ_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of principal", HFILL }},
{ &hf_mgmt_rc,
{"Status", "mgmt.rc", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_mgmt
};
proto_mgmt = proto_register_protocol ("DCE/RPC Remote Management", "MGMT", "mgmt");
proto_register_field_array (proto_mgmt, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_mgmt (void)
{
dcerpc_init_uuid (proto_mgmt, ett_mgmt, &uuid_mgmt, ver_mgmt, mgmt_dissectors, hf_mgmt_opnum);
}
