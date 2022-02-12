static int
dissect_oxid_simple_ping_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_setid, NULL);
return offset;
}
static int
dissect_oxid_simple_ping_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 u32HResult;
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, di, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_oxid_server_alive_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 u32HResult;
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, di, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_oxid_complex_ping_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint16 u16SeqNum;
guint16 u16AddToSet;
guint16 u16DelFromSet;
guint32 u32Pointer;
guint32 u32ArraySize;
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_setid, NULL);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_seqnum, &u16SeqNum);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_addtoset, &u16AddToSet);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_delfromset, &u16DelFromSet);
col_append_fstr(pinfo->cinfo, COL_INFO, " AddToSet=%u DelFromSet=%u",
u16AddToSet, u16DelFromSet);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, tree, di, drep,
&u32ArraySize);
while (u16AddToSet--) {
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_oid, NULL);
}
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, tree, di, drep,
&u32ArraySize);
while (u16DelFromSet--) {
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_oid, NULL);
}
}
return offset;
}
static int
dissect_oxid_complex_ping_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint16 u16PingBackoffFactor;
guint32 u32HResult;
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_setid, NULL);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_ping_backoff_factor, &u16PingBackoffFactor);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, di, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_oxid_resolve_oxid2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint16 u16ProtSeqs;
guint32 u32ArraySize;
guint32 u32ItemIdx;
offset = dissect_dcom_ID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_oxid, NULL);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_requested_protseqs, &u16ProtSeqs);
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, tree, di, drep,
&u32ArraySize);
u32ItemIdx = 1;
while (u32ArraySize--) {
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_protseqs, &u16ProtSeqs);
u32ItemIdx++;
}
return offset;
}
static int
dissect_oxid_resolve_oxid2_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
guint32 u32Pointer;
guint32 u32ArraySize;
e_guid_t ipid;
guint32 u32AuthnHint;
guint16 u16VersionMajor;
guint16 u16VersionMinor;
guint32 u32HResult;
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, di, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_dcerpc_array_size(tvb, offset, pinfo, tree, di, drep,
&u32ArraySize);
offset = dissect_dcom_DUALSTRINGARRAY(tvb, offset, pinfo, tree, di, drep,
hf_oxid_bindings, NULL);
offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, di, drep,
hf_oxid_ipid, &ipid);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, di, drep,
hf_oxid_authn_hint, &u32AuthnHint);
offset = dissect_dcom_COMVERSION(tvb, offset, pinfo, tree, di, drep,
&u16VersionMajor, &u16VersionMinor);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, di, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_oxid_server_alive2_resp(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep) {
guint16 u16VersionMajor;
guint16 u16VersionMinor;
offset = dissect_dcom_COMVERSION(tvb, offset, pinfo, tree, di, drep, &u16VersionMajor, &u16VersionMinor);
dissect_dcerpc_uint64(tvb, offset, pinfo, tree, di, drep, hf_oxid_Unknown1, NULL);
offset += 8;
offset = dissect_dcom_DUALSTRINGARRAY(tvb, offset, pinfo, tree, di, drep, hf_oxid_ds_array, NULL);
dissect_dcerpc_uint64(tvb, offset, pinfo, tree, di, drep, hf_oxid_Unknown2, NULL);
offset += 8;
return offset;
}
void
proto_register_oxid (void)
{
static hf_register_info hf[] = {
{ &hf_oxid_opnum,
{ "Operation", "oxid.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_setid,
{ "SetId", "oxid.setid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_seqnum,
{ "SeqNum", "oxid.seqnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_addtoset,
{ "AddToSet", "oxid.addtoset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_delfromset,
{ "DelFromSet", "oxid.delfromset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_oid,
{ "OID", "oxid.oid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_ping_backoff_factor,
{ "PingBackoffFactor", "oxid.ping_backoff_factor", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_oxid,
{ "OXID", "oxid.oxid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_requested_protseqs,
{ "RequestedProtSeq", "oxid.requested_protseqs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_protseqs,
{ "ProtSeq", "oxid.protseqs", FT_UINT16, BASE_DEC, VALS(dcom_protseq_vals), 0x0, NULL, HFILL }},
{ &hf_oxid_bindings,
{ "OxidBindings", "oxid.bindings", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_ipid,
{ "IPID", "oxid.ipid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_authn_hint,
{ "AuthnHint", "oxid.authn_hint", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_ds_array,
{ "Address", "dcom.oxid.address", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_Unknown1,
{ "unknown 8 bytes 1", "oxid.unknown1", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_oxid_Unknown2,
{ "unknown 8 bytes 2", "oxid.unknown2", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_oxid
};
proto_oxid = proto_register_protocol ("DCOM OXID Resolver", "IOXIDResolver", "oxid");
proto_register_field_array (proto_oxid, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_oxid (void)
{
dcerpc_init_uuid (proto_oxid, ett_oxid, &uuid_oxid, ver_oxid, oxid_dissectors, hf_oxid_opnum);
}
