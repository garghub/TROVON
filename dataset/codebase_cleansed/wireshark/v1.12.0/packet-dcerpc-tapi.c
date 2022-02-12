static int
dissect_tapi_client_attach_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_tapi_unknown_long, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_REF, "unknown string",
hf_tapi_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_REF, "unknown string",
hf_tapi_unknown_string, 0);
return offset;
}
static int
dissect_tapi_client_attach_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd(tvb, offset, pinfo, tree, di, drep,
hf_tapi_hnd, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_tapi_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_tapi_rc, NULL);
return offset;
}
static int
dissect_tapi_TYPE_1(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
if(di->conformant_run){
offset =dissect_ndr_ucvarray(tvb, offset, pinfo, tree, di, drep, NULL);
return offset;
}
proto_tree_add_item(tree, hf_tapi_unknown_bytes, tvb, offset,
di->array_actual_count, ENC_NA);
offset += di->array_actual_count;
return offset;
}
static int
dissect_tapi_client_request_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_ctx_hnd(tvb, offset, pinfo, tree, di, drep,
hf_tapi_hnd, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_tapi_TYPE_1, NDR_POINTER_REF,
"unknown array", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_tapi_unknown_long, NULL);
return offset;
}
static int
dissect_tapi_client_request_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_tapi_rc, NULL);
return offset;
}
static int
dissect_tapi_client_detach_rqst(tvbuff_t *tvb _U_, int offset _U_,
packet_info *pinfo _U_, proto_tree *tree _U_,
dcerpc_info *di _U_, guint8 *drep _U_)
{
return offset;
}
static int
dissect_tapi_client_detach_reply(tvbuff_t *tvb _U_, int offset _U_,
packet_info *pinfo _U_, proto_tree *tree _U_,
dcerpc_info *di _U_, guint8 *drep _U_)
{
return offset;
}
void
proto_register_dcerpc_tapi(void)
{
static hf_register_info hf[] = {
{ &hf_tapi_opnum, {
"Operation", "tapi.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_tapi_rc, {
"Return code", "tapi.rc", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&NT_errors_ext, 0x0, "TAPI return code", HFILL }},
{ &hf_tapi_hnd, {
"Context Handle", "tapi.hnd", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_tapi_unknown_long, {
"Unknown long", "tapi.unknown.long", FT_UINT32, BASE_HEX,
NULL, 0x0, "Unknown long. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_tapi_unknown_string, {
"Unknown string", "tapi.unknown.string", FT_STRING, BASE_NONE,
NULL, 0x0, "Unknown string. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_tapi_unknown_bytes, {
"Unknown bytes", "tapi.unknown.bytes", FT_BYTES, BASE_NONE,
NULL, 0x0, "Unknown bytes. If you know what this is, contact wireshark developers.", HFILL }}
};
static gint *ett[] = {
&ett_dcerpc_tapi
};
proto_dcerpc_tapi = proto_register_protocol(
"Microsoft Telephony API Service", "TAPI", "tapi");
proto_register_field_array(proto_dcerpc_tapi, hf,
array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_tapi(void)
{
dcerpc_init_uuid(proto_dcerpc_tapi, ett_dcerpc_tapi,
&uuid_dcerpc_tapi, ver_dcerpc_tapi,
dcerpc_tapi_dissectors, hf_tapi_opnum);
}
