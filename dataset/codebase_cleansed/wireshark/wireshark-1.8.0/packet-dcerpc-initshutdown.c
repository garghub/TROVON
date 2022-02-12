static int
initshutdown_dissect_element_String_sub_name_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_String_sub_name_size, 0);
return offset;
}
static int
initshutdown_dissect_element_String_sub_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
return offset;
}
int
initshutdown_dissect_struct_String_sub(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_initshutdown_initshutdown_String_sub);
}
offset = initshutdown_dissect_element_String_sub_name_size(tvb, offset, pinfo, tree, drep);
offset = initshutdown_dissect_element_String_sub_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
initshutdown_dissect_element_String_name_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_String_name_len, 0);
return offset;
}
static int
initshutdown_dissect_element_String_name_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_String_name_size, 0);
return offset;
}
static int
initshutdown_dissect_element_String_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_String_name_, NDR_POINTER_UNIQUE, "Pointer to Name (initshutdown_String_sub)",hf_initshutdown_initshutdown_String_name);
return offset;
}
static int
initshutdown_dissect_element_String_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = initshutdown_dissect_struct_String_sub(tvb,offset,pinfo,tree,drep,hf_initshutdown_initshutdown_String_name,0);
return offset;
}
int
initshutdown_dissect_struct_String(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_initshutdown_initshutdown_String);
}
offset = initshutdown_dissect_element_String_name_len(tvb, offset, pinfo, tree, drep);
offset = initshutdown_dissect_element_String_name_size(tvb, offset, pinfo, tree, drep);
offset = initshutdown_dissect_element_String_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
initshutdown_dissect_element_Init_hostname(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_Init_hostname_, NDR_POINTER_UNIQUE, "Pointer to Hostname (uint16)",hf_initshutdown_initshutdown_Init_hostname);
return offset;
}
static int
initshutdown_dissect_element_Init_hostname_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_Init_hostname, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_message(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_Init_message_, NDR_POINTER_UNIQUE, "Pointer to Message (initshutdown_String)",hf_initshutdown_initshutdown_Init_message);
return offset;
}
static int
initshutdown_dissect_element_Init_message_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = initshutdown_dissect_struct_String(tvb,offset,pinfo,tree,drep,hf_initshutdown_initshutdown_Init_message,0);
return offset;
}
static int
initshutdown_dissect_element_Init_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_Init_timeout, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_force_apps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_Init_force_apps, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_reboot(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_Init_reboot, 0);
return offset;
}
static int
initshutdown_dissect_Init_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Init";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_werror, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_Init_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Init";
offset = initshutdown_dissect_element_Init_hostname(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_Init_message(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_Init_timeout(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_Init_force_apps(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_Init_reboot(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
initshutdown_dissect_element_Abort_server(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_Abort_server_, NDR_POINTER_UNIQUE, "Pointer to Server (uint16)",hf_initshutdown_initshutdown_Abort_server);
return offset;
}
static int
initshutdown_dissect_element_Abort_server_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_Abort_server, 0);
return offset;
}
static int
initshutdown_dissect_Abort_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Abort";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_werror, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_Abort_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Abort";
offset = initshutdown_dissect_element_Abort_server(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
initshutdown_dissect_element_InitEx_hostname(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_InitEx_hostname_, NDR_POINTER_UNIQUE, "Pointer to Hostname (uint16)",hf_initshutdown_initshutdown_InitEx_hostname);
return offset;
}
static int
initshutdown_dissect_element_InitEx_hostname_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_InitEx_hostname, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_message(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, initshutdown_dissect_element_InitEx_message_, NDR_POINTER_UNIQUE, "Pointer to Message (initshutdown_String)",hf_initshutdown_initshutdown_InitEx_message);
return offset;
}
static int
initshutdown_dissect_element_InitEx_message_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = initshutdown_dissect_struct_String(tvb,offset,pinfo,tree,drep,hf_initshutdown_initshutdown_InitEx_message,0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_InitEx_timeout, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_force_apps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_InitEx_force_apps, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_reboot(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_InitEx_reboot, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_reason(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_initshutdown_InitEx_reason, 0);
return offset;
}
static int
initshutdown_dissect_InitEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="InitEx";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_initshutdown_werror, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_InitEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="InitEx";
offset = initshutdown_dissect_element_InitEx_hostname(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_InitEx_message(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_InitEx_timeout(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_InitEx_force_apps(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_InitEx_reboot(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = initshutdown_dissect_element_InitEx_reason(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
void proto_register_dcerpc_initshutdown(void)
{
static hf_register_info hf[] = {
{ &hf_initshutdown_initshutdown_String_name_len,
{ "Name Len", "initshutdown.initshutdown_String.name_len", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Abort_server,
{ "Server", "initshutdown.initshutdown_Abort.server", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_message,
{ "Message", "initshutdown.initshutdown_Init.message", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_hostname,
{ "Hostname", "initshutdown.initshutdown_Init.hostname", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_reboot,
{ "Reboot", "initshutdown.initshutdown_InitEx.reboot", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_reason,
{ "Reason", "initshutdown.initshutdown_InitEx.reason", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_String_name_size,
{ "Name Size", "initshutdown.initshutdown_String.name_size", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_timeout,
{ "Timeout", "initshutdown.initshutdown_Init.timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_hostname,
{ "Hostname", "initshutdown.initshutdown_InitEx.hostname", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_message,
{ "Message", "initshutdown.initshutdown_InitEx.message", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_String_name,
{ "Name", "initshutdown.initshutdown_String.name", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_reboot,
{ "Reboot", "initshutdown.initshutdown_Init.reboot", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_opnum,
{ "Operation", "initshutdown.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_force_apps,
{ "Force Apps", "initshutdown.initshutdown_Init.force_apps", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_String_sub_name,
{ "Name", "initshutdown.initshutdown_String_sub.name", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_werror,
{ "Windows Error", "initshutdown.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_String_sub_name_size,
{ "Name Size", "initshutdown.initshutdown_String_sub.name_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_force_apps,
{ "Force Apps", "initshutdown.initshutdown_InitEx.force_apps", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_timeout,
{ "Timeout", "initshutdown.initshutdown_InitEx.timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_initshutdown,
&ett_initshutdown_initshutdown_String_sub,
&ett_initshutdown_initshutdown_String,
};
proto_dcerpc_initshutdown = proto_register_protocol("Init shutdown service", "INITSHUTDOWN", "initshutdown");
proto_register_field_array(proto_dcerpc_initshutdown, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_initshutdown(void)
{
dcerpc_init_uuid(proto_dcerpc_initshutdown, ett_dcerpc_initshutdown,
&uuid_dcerpc_initshutdown, ver_dcerpc_initshutdown,
initshutdown_dissectors, hf_initshutdown_opnum);
}
