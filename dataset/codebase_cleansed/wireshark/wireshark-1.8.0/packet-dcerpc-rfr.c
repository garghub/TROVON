int
rfr_dissect_enum_MAPISTATUS(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if(param){
parameter=(guint32)*param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ulFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_rfr_RfrGetNewDSA_ulFlags, 0);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_pUserDN(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetNewDSA_pUserDN_, NDR_POINTER_REF, "Pointer to Puserdn (uint8)",hf_rfr_RfrGetNewDSA_pUserDN);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_pUserDN_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_rfr_RfrGetNewDSA_pUserDN, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszUnused(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetNewDSA_ppszUnused_, NDR_POINTER_UNIQUE, "Pointer to Ppszunused (uint8)",hf_rfr_RfrGetNewDSA_ppszUnused);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszUnused_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetNewDSA_ppszUnused__, NDR_POINTER_UNIQUE, "Pointer to Ppszunused (uint8)",hf_rfr_RfrGetNewDSA_ppszUnused);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszUnused__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_rfr_RfrGetNewDSA_ppszUnused, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszServer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetNewDSA_ppszServer_, NDR_POINTER_UNIQUE, "Pointer to Ppszserver (uint8)",hf_rfr_RfrGetNewDSA_ppszServer);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszServer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetNewDSA_ppszServer__, NDR_POINTER_UNIQUE, "Pointer to Ppszserver (uint8)",hf_rfr_RfrGetNewDSA_ppszServer);
return offset;
}
static int
rfr_dissect_element_RfrGetNewDSA_ppszServer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_rfr_RfrGetNewDSA_ppszServer, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
rfr_dissect_RfrGetNewDSA_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="RfrGetNewDSA";
offset = rfr_dissect_element_RfrGetNewDSA_ppszUnused(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetNewDSA_ppszServer(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_rfr_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, rfr_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
rfr_dissect_RfrGetNewDSA_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="RfrGetNewDSA";
offset = rfr_dissect_element_RfrGetNewDSA_ulFlags(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetNewDSA_pUserDN(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetNewDSA_ppszUnused(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetNewDSA_ppszServer(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_ulFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_rfr_RfrGetFQDNFromLegacyDN_ulFlags, 0);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_cbMailboxServerDN(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_rfr_RfrGetFQDNFromLegacyDN_cbMailboxServerDN, 0);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_szMailboxServerDN(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetFQDNFromLegacyDN_szMailboxServerDN_, NDR_POINTER_REF, "Pointer to Szmailboxserverdn (uint8)",hf_rfr_RfrGetFQDNFromLegacyDN_szMailboxServerDN);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_szMailboxServerDN_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_rfr_RfrGetFQDNFromLegacyDN_szMailboxServerDN, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN_, NDR_POINTER_REF, "Pointer to Ppszserverfqdn (uint8)",hf_rfr_RfrGetFQDNFromLegacyDN_ppszServerFQDN);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN__, NDR_POINTER_REF, "Pointer to Ppszserverfqdn (uint8)",hf_rfr_RfrGetFQDNFromLegacyDN_ppszServerFQDN);
return offset;
}
static int
rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_rfr_RfrGetFQDNFromLegacyDN_ppszServerFQDN, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
rfr_dissect_RfrGetFQDNFromLegacyDN_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="RfrGetFQDNFromLegacyDN";
offset = rfr_dissect_element_RfrGetFQDNFromLegacyDN_ppszServerFQDN(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_rfr_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, rfr_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
rfr_dissect_RfrGetFQDNFromLegacyDN_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="RfrGetFQDNFromLegacyDN";
offset = rfr_dissect_element_RfrGetFQDNFromLegacyDN_ulFlags(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetFQDNFromLegacyDN_cbMailboxServerDN(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = rfr_dissect_element_RfrGetFQDNFromLegacyDN_szMailboxServerDN(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
void proto_register_dcerpc_rfr(void)
{
static hf_register_info hf[] = {
{ &hf_rfr_MAPISTATUS_status,
{ "MAPISTATUS", "rfr.MAPISTATUS_status", FT_UINT32, BASE_HEX, VALS(rfr_MAPISTATUS_vals), 0, NULL, HFILL }},
{ &hf_rfr_RfrGetFQDNFromLegacyDN_ulFlags,
{ "Ulflags", "rfr.RfrGetFQDNFromLegacyDN.ulFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetFQDNFromLegacyDN_szMailboxServerDN,
{ "Szmailboxserverdn", "rfr.RfrGetFQDNFromLegacyDN.szMailboxServerDN", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rfr_opnum,
{ "Operation", "rfr.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetNewDSA_ulFlags,
{ "Ulflags", "rfr.RfrGetNewDSA.ulFlags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetFQDNFromLegacyDN_cbMailboxServerDN,
{ "Cbmailboxserverdn", "rfr.RfrGetFQDNFromLegacyDN.cbMailboxServerDN", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetNewDSA_pUserDN,
{ "Puserdn", "rfr.RfrGetNewDSA.pUserDN", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetNewDSA_ppszUnused,
{ "Ppszunused", "rfr.RfrGetNewDSA.ppszUnused", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetNewDSA_ppszServer,
{ "Ppszserver", "rfr.RfrGetNewDSA.ppszServer", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_rfr_RfrGetFQDNFromLegacyDN_ppszServerFQDN,
{ "Ppszserverfqdn", "rfr.RfrGetFQDNFromLegacyDN.ppszServerFQDN", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_rfr,
};
proto_dcerpc_rfr = proto_register_protocol("Exchange 2003 Directory Request For Response", "RFR", "rfr");
proto_register_field_array(proto_dcerpc_rfr, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_rfr(void)
{
dcerpc_init_uuid(proto_dcerpc_rfr, ett_dcerpc_rfr,
&uuid_dcerpc_rfr, ver_dcerpc_rfr,
rfr_dissectors, hf_rfr_opnum);
}
