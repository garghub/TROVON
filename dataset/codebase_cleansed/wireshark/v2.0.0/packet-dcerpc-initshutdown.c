int
initshutdown_dissect_enum_ReasonMajor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
initshutdown_dissect_enum_ReasonMinor(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if (param) {
parameter = *param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if (param) {
*param = parameter;
}
return offset;
}
int
initshutdown_dissect_bitmap_ReasonFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, DREP_ENC_INTEGER(drep));
tree = proto_item_add_subtree(item,ett_initshutdown_initshutdown_ReasonFlags);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_initshutdown_initshutdown_ReasonFlags_SHTDN_REASON_FLAG_USER_DEFINED, tvb, offset-4, 4, flags);
if (flags&( 0x40000000 )){
proto_item_append_text(item, "SHTDN_REASON_FLAG_USER_DEFINED");
if (flags & (~( 0x40000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x40000000 ));
proto_tree_add_boolean(tree, hf_initshutdown_initshutdown_ReasonFlags_SHTDN_REASON_FLAG_PLANNED, tvb, offset-4, 4, flags);
if (flags&( 0x80000000 )){
proto_item_append_text(item, "SHTDN_REASON_FLAG_PLANNED");
if (flags & (~( 0x80000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x80000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
initshutdown_dissect_element_Init_hostname(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, initshutdown_dissect_element_Init_hostname_, NDR_POINTER_UNIQUE, "Pointer to Hostname (uint16)",hf_initshutdown_initshutdown_Init_hostname);
return offset;
}
static int
initshutdown_dissect_element_Init_hostname_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Init_hostname, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_message(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, initshutdown_dissect_element_Init_message_, NDR_POINTER_UNIQUE, "Pointer to Message (lsa_StringLarge)",hf_initshutdown_initshutdown_Init_message);
return offset;
}
static int
initshutdown_dissect_element_Init_message_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=lsarpc_dissect_struct_lsa_StringLarge(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Init_message, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Init_timeout, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_force_apps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Init_force_apps, 0);
return offset;
}
static int
initshutdown_dissect_element_Init_do_reboot(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Init_do_reboot, 0);
return offset;
}
static int
initshutdown_dissect_Init_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="Init";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_Init_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="Init";
offset = initshutdown_dissect_element_Init_hostname(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_Init_message(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_Init_timeout(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_Init_force_apps(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_Init_do_reboot(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
initshutdown_dissect_element_Abort_server(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, initshutdown_dissect_element_Abort_server_, NDR_POINTER_UNIQUE, "Pointer to Server (uint16)",hf_initshutdown_initshutdown_Abort_server);
return offset;
}
static int
initshutdown_dissect_element_Abort_server_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_Abort_server, 0);
return offset;
}
static int
initshutdown_dissect_Abort_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="Abort";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_Abort_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="Abort";
offset = initshutdown_dissect_element_Abort_server(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
initshutdown_dissect_element_InitEx_hostname(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, initshutdown_dissect_element_InitEx_hostname_, NDR_POINTER_UNIQUE, "Pointer to Hostname (uint16)",hf_initshutdown_initshutdown_InitEx_hostname);
return offset;
}
static int
initshutdown_dissect_element_InitEx_hostname_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_hostname, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_message(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, initshutdown_dissect_element_InitEx_message_, NDR_POINTER_UNIQUE, "Pointer to Message (lsa_StringLarge)",hf_initshutdown_initshutdown_InitEx_message);
return offset;
}
static int
initshutdown_dissect_element_InitEx_message_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset=lsarpc_dissect_struct_lsa_StringLarge(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_message, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_timeout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_timeout, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_force_apps(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_force_apps, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_do_reboot(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_do_reboot, 0);
return offset;
}
static int
initshutdown_dissect_element_InitEx_reason(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_initshutdown_InitEx_reason, 0);
return offset;
}
static int
initshutdown_dissect_InitEx_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="InitEx";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_initshutdown_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
initshutdown_dissect_InitEx_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="InitEx";
offset = initshutdown_dissect_element_InitEx_hostname(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_InitEx_message(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_InitEx_timeout(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_InitEx_force_apps(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_InitEx_do_reboot(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = initshutdown_dissect_element_InitEx_reason(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
void proto_register_dcerpc_initshutdown(void)
{
static hf_register_info hf[] = {
{ &hf_initshutdown_initshutdown_Abort_server,
{ "Server", "initshutdown.initshutdown_Abort.server", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_do_reboot,
{ "Do Reboot", "initshutdown.initshutdown_InitEx.do_reboot", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_force_apps,
{ "Force Apps", "initshutdown.initshutdown_InitEx.force_apps", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_hostname,
{ "Hostname", "initshutdown.initshutdown_InitEx.hostname", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_message,
{ "Message", "initshutdown.initshutdown_InitEx.message", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_reason,
{ "Reason", "initshutdown.initshutdown_InitEx.reason", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_InitEx_timeout,
{ "Timeout", "initshutdown.initshutdown_InitEx.timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_do_reboot,
{ "Do Reboot", "initshutdown.initshutdown_Init.do_reboot", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_force_apps,
{ "Force Apps", "initshutdown.initshutdown_Init.force_apps", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_hostname,
{ "Hostname", "initshutdown.initshutdown_Init.hostname", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_message,
{ "Message", "initshutdown.initshutdown_Init.message", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_Init_timeout,
{ "Timeout", "initshutdown.initshutdown_Init.timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_initshutdown_ReasonFlags_SHTDN_REASON_FLAG_PLANNED,
{ "Shtdn Reason Flag Planned", "initshutdown.initshutdown_ReasonFlags.SHTDN_REASON_FLAG_PLANNED", FT_BOOLEAN, 32, TFS(&initshutdown_ReasonFlags_SHTDN_REASON_FLAG_PLANNED_tfs), ( 0x80000000 ), NULL, HFILL }},
{ &hf_initshutdown_initshutdown_ReasonFlags_SHTDN_REASON_FLAG_USER_DEFINED,
{ "Shtdn Reason Flag User Defined", "initshutdown.initshutdown_ReasonFlags.SHTDN_REASON_FLAG_USER_DEFINED", FT_BOOLEAN, 32, TFS(&initshutdown_ReasonFlags_SHTDN_REASON_FLAG_USER_DEFINED_tfs), ( 0x40000000 ), NULL, HFILL }},
{ &hf_initshutdown_opnum,
{ "Operation", "initshutdown.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_initshutdown_werror,
{ "Windows Error", "initshutdown.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_initshutdown,
&ett_initshutdown_initshutdown_ReasonFlags,
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
