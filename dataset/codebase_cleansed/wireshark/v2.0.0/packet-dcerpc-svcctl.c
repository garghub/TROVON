static int
svcctl_dissect_dwServiceType_flags(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep, int opnum)
{
guint32 value, len = 4;
proto_item *item = NULL;
proto_tree *tree = NULL;
(void) dissect_dcerpc_uint32 (tvb, offset, pinfo, NULL, drep, 0, &value);
if(parent_tree) {
item = proto_tree_add_uint(parent_tree, hf_svcctl_service_type, tvb, offset, len, value);
tree = proto_item_add_subtree(item, ett_dcerpc_svcctl_service_type_bits);
}
switch(opnum) {
case SVC_CREATE_SERVICE_W:
proto_tree_add_boolean(tree, hf_svcctl_service_type_interactive_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_INTERACTIVE_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_share_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_SHARE_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_own_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_OWN_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_fs_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_FILE_SYSTEM_DRIVER);
proto_tree_add_boolean(tree, hf_svcctl_service_type_kernel_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_KERNEL_DRIVER);
break;
case SVC_ENUM_SERVICES_STATUS_W:
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_share_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_SHARE_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_own_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_OWN_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_fs_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_FILE_SYSTEM_DRIVER);
proto_tree_add_boolean(tree, hf_svcctl_service_type_kernel_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_KERNEL_DRIVER);
break;
case SVC_QUERY_SERVICE_CONFIG_W:
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_share_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_SHARE_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_win32_own_process,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_WIN32_OWN_PROCESS);
proto_tree_add_boolean(tree, hf_svcctl_service_type_fs_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_FILE_SYSTEM_DRIVER);
proto_tree_add_boolean(tree, hf_svcctl_service_type_kernel_driver,
tvb, offset, len, value & SVCCTL_SERVICE_TYPE_KERNEL_DRIVER);
break;
}
offset += len;
return offset;
}
static int
svcctl_dissect_pointer_long(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
di->hf_index, NULL);
return offset;
}
static void
svcctl_scm_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree,
guint32 access)
{
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_modify_boot_config, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_query_lock_status, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_lock, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_enumerate_service, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_create_service, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_svcctl_scm_rights_connect, tvb, offset, 4, access);
}
static int
svcctl_dissect_OpenSCManager_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
const char *mn, *dn;
dcv->private_data=NULL;
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"MachineName", hf_svcctl_machinename, cb_str_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | CB_STR_SAVE | 1));
mn=(const char *)dcv->private_data;
if(!mn)
mn="";
dcv->private_data=NULL;
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"Database", hf_svcctl_database, cb_str_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | 1));
dn=(const char *)dcv->private_data;
if(!dn)
dn="";
if(!pinfo->fd->flags.visited){
if(!dcv->se_data){
dcv->se_data=wmem_strdup_printf(wmem_file_scope(), "%s\\%s",mn,dn);
}
}
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_access_mask,
&svcctl_scm_access_mask_info, NULL);
return offset;
}
static int
svcctl_dissect_OpenSCManager_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
e_ctx_hnd policy_hnd;
proto_item *hnd_item;
guint32 status;
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, &policy_hnd,
&hnd_item, TRUE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, &status);
if( status == 0 ){
const char *pol_name;
if (dcv->se_data){
pol_name = wmem_strdup_printf(wmem_packet_scope(),
"OpenSCManagerW(%s)", (char *)dcv->se_data);
} else {
pol_name = "Unknown OpenSCManagerW() handle";
}
if(!pinfo->fd->flags.visited){
dcerpc_store_polhnd_name(&policy_hnd, pinfo, pol_name);
}
if(hnd_item)
proto_item_append_text(hnd_item, ": %s", pol_name);
}
return offset;
}
static int
svcctl_dissect_OpenSCManagerW_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
const char *mn, *dn;
dcv->private_data=NULL;
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"MachineName", hf_svcctl_machinename, cb_wstr_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | CB_STR_SAVE | 1));
mn=(const char *)dcv->private_data;
if(!mn)
mn="";
dcv->private_data=NULL;
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Database", hf_svcctl_database, cb_wstr_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | 1));
dn=(const char *)dcv->private_data;
if(!dn)
dn="";
if(!pinfo->fd->flags.visited){
if(!dcv->se_data){
dcv->se_data=wmem_strdup_printf(wmem_file_scope(), "%s\\%s",mn,dn);
}
}
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_access_mask,
&svcctl_scm_access_mask_info, NULL);
return offset;
}
static int
svcctl_dissect_OpenSCManagerW_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
e_ctx_hnd policy_hnd;
proto_item *hnd_item;
guint32 status;
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, &policy_hnd,
&hnd_item, TRUE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, &status);
if( status == 0 ){
const char *pol_name;
if (dcv->se_data){
pol_name = wmem_strdup_printf(wmem_packet_scope(),
"OpenSCManagerW(%s)", (char *)dcv->se_data);
} else {
pol_name = "Unknown OpenSCManagerW() handle";
}
if(!pinfo->fd->flags.visited){
dcerpc_store_polhnd_name(&policy_hnd, pinfo, pol_name);
}
if(hnd_item)
proto_item_append_text(hnd_item, ": %s", pol_name);
}
return offset;
}
static int
svcctl_dissect_CreateServiceW_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint16), hf_svcctl_service_name, TRUE, NULL);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Display Name", hf_svcctl_display_name, cb_wstr_postprocess,
GINT_TO_POINTER(1));
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_access_mask,
&svcctl_scm_access_mask_info, NULL);
offset = svcctl_dissect_dwServiceType_flags(tvb, offset, pinfo, tree, drep, SVC_CREATE_SERVICE_W);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_service_start_type, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_service_error_control, NULL);
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint16), hf_svcctl_binarypathname, TRUE, NULL);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Load Order Group", hf_svcctl_loadordergroup, cb_wstr_postprocess,
GINT_TO_POINTER(1));
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_tagid, NULL);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Dependencies", hf_svcctl_dependencies, cb_wstr_postprocess,
GINT_TO_POINTER(1));
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_depend_size, NULL);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Service Start Name", hf_svcctl_service_start_name, cb_wstr_postprocess,
GINT_TO_POINTER(1));
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE,
"Password", hf_svcctl_password, cb_wstr_postprocess,
GINT_TO_POINTER(1));
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_password_size, NULL);
return offset;
}
static int
svcctl_dissect_CreateServiceW_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_tagid, NULL);
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_CloseServiceHandle_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
e_ctx_hnd policy_hnd;
char *pol_name;
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, &policy_hnd,
NULL, FALSE, TRUE);
dcerpc_fetch_polhnd_data(&policy_hnd, &pol_name, NULL, NULL, NULL,
pinfo->fd->num);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
pol_name);
return offset;
}
static int
svcctl_dissect_CloseServiceHandle_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, NULL,
NULL, FALSE, TRUE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_LockServiceDatabase_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, NULL,
NULL, FALSE, TRUE);
return offset;
}
static int
svcctl_dissect_LockServiceDatabase_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_lock, NULL,
NULL, TRUE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_UnlockServiceDatabase_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_lock, NULL,
NULL, FALSE, TRUE);
return offset;
}
static int
svcctl_dissect_UnlockServiceDatabase_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_lock, NULL,
NULL, TRUE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_QUERY_SERVICE_LOCK_STATUS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_is_locked, NULL);
offset = dissect_ndr_pointer(
tvb, offset, pinfo, tree, di, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"Owner", hf_svcctl_lock_owner);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_lock_duration, NULL);
return offset;
}
static int
svcctl_dissect_QueryServiceLockStatus_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_hnd, NULL,
NULL, FALSE, TRUE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_size, NULL);
return offset;
}
static int
svcctl_dissect_QueryServiceLockStatus_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
dcerpc_info *di, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
svcctl_dissect_QUERY_SERVICE_LOCK_STATUS, NDR_POINTER_REF,
"LOCK_STATUS", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_required_size, NULL);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_EnumServicesStatus_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = svcctl_dissect_dwServiceType_flags(tvb, offset, pinfo, tree, drep, SVC_ENUM_SERVICES_STATUS_W);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_service_state, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_size, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
svcctl_dissect_pointer_long, NDR_POINTER_UNIQUE,
"Resume Handle", hf_svcctl_resume);
return offset;
}
static int
svcctl_dissect_OpenServiceW_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep,
sizeof(guint16), hf_svcctl_service_name, TRUE, NULL);
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_access_mask,
&svcctl_scm_access_mask_info, NULL);
return offset;
}
static int
svcctl_dissect_OpenServiceW_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = dissect_doserror(
tvb, offset, pinfo, tree, di, drep, hf_svcctl_rc, NULL);
return offset;
}
static int
svcctl_dissect_QueryServiceConfigW_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep)
{
offset = dissect_nt_policy_hnd(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_hnd, NULL, NULL, FALSE, FALSE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_svcctl_buffer, NULL);
return offset;
}
void
proto_register_dcerpc_svcctl(void)
{
static hf_register_info hf[] = {
{ &hf_svcctl_opnum,
{ "Operation", "svcctl.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_svcctl_machinename,
{ "MachineName", "svcctl.machinename", FT_STRING, BASE_NONE,
NULL, 0x0, "Name of the host we want to open the database on", HFILL }},
{ &hf_svcctl_database,
{ "Database", "svcctl.database", FT_STRING, BASE_NONE,
NULL, 0x0, "Name of the database to open", HFILL }},
{ &hf_svcctl_access_mask,
{ "Access Mask", "svcctl.access_mask", FT_UINT32, BASE_HEX,
NULL, 0x0, "SVCCTL Access Mask", HFILL }},
{ &hf_svcctl_scm_rights_connect,
{ "Connect", "svcctl.scm_rights_connect", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000001, "SVCCTL Rights to connect to SCM", HFILL }},
{ &hf_svcctl_scm_rights_create_service,
{ "Create Service", "svcctl.scm_rights_create_service", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000002, "SVCCTL Rights to create services", HFILL }},
{ &hf_svcctl_scm_rights_enumerate_service,
{ "Enumerate Service", "svcctl.scm_rights_enumerate_service", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000004, "SVCCTL Rights to enumerate services", HFILL }},
{ &hf_svcctl_scm_rights_lock,
{ "Lock", "svcctl.scm_rights_lock", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000008, "SVCCTL Rights to lock database", HFILL }},
{ &hf_svcctl_scm_rights_query_lock_status,
{ "Query Lock Status", "svcctl.scm_rights_query_lock_status", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000010, "SVCCTL Rights to query database lock status", HFILL }},
{ &hf_svcctl_scm_rights_modify_boot_config,
{ "Modify Boot Config", "svcctl.scm_rights_modify_boot_config", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), 0x00000020, "SVCCTL Rights to modify boot config", HFILL }},
{ &hf_svcctl_hnd,
{ "Context Handle", "svcctl.hnd", FT_BYTES, BASE_NONE,
NULL, 0x0, "SVCCTL Context handle", HFILL }},
{ &hf_svcctl_lock,
{ "Lock", "svcctl.lock", FT_BYTES, BASE_NONE,
NULL, 0x0, "SVCCTL Database Lock", HFILL }},
{ &hf_svcctl_rc,
{ "Return code", "svcctl.rc", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&DOS_errors_ext, 0x0, "SVCCTL return code", HFILL }},
{ &hf_svcctl_size,
{ "Size", "svcctl.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL size of buffer", HFILL }},
{ &hf_svcctl_required_size,
{ "Required Size", "svcctl.required_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL required size of buffer for data to fit", HFILL }},
{ &hf_svcctl_is_locked,
{ "IsLocked", "svcctl.is_locked", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL whether the database is locked or not", HFILL }},
{ &hf_svcctl_lock_duration,
{ "Duration", "svcctl.lock_duration", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL number of seconds the database has been locked", HFILL }},
{ &hf_svcctl_lock_owner,
{ "Owner", "svcctl.lock_owner", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL the user that holds the database lock", HFILL }},
{ &hf_svcctl_service_type,
{ "Service Type", "svcctl.service_type", FT_UINT32, BASE_HEX,
NULL, 0x0, "SVCCTL type of service", HFILL }},
{ &hf_svcctl_service_type_kernel_driver,
{ "Kernel Driver Service", "svcctl.service_type.kernel", FT_BOOLEAN, 32,
TFS(&tfs_svcctl_service_type_kernel_driver), SVCCTL_SERVICE_TYPE_KERNEL_DRIVER, "Request includes kernel driver services?", HFILL }},
{ &hf_svcctl_service_type_fs_driver,
{ "File System Driver Service", "svcctl.service_type.fs", FT_BOOLEAN, 32,
TFS(&tfs_svcctl_service_type_fs_driver), SVCCTL_SERVICE_TYPE_FILE_SYSTEM_DRIVER, "Request includes file system driver services?", HFILL }},
{ &hf_svcctl_service_type_win32_own_process,
{ "Self Process Service", "svcctl.service_type.win32_own", FT_BOOLEAN, 32,
TFS(&tfs_svcctl_service_type_win32_own_process), SVCCTL_SERVICE_TYPE_WIN32_OWN_PROCESS, "Request includes services that run their own process?", HFILL }},
{ &hf_svcctl_service_type_win32_share_process,
{ "Shared Process Service", "svcctl.service_type.win32_shared", FT_BOOLEAN, 32,
TFS(&tfs_svcctl_service_type_win32_share_process), SVCCTL_SERVICE_TYPE_WIN32_SHARE_PROCESS, "Request includes services that share their process?", HFILL }},
{ &hf_svcctl_service_type_interactive_process,
{ "Interactive Process Service", "svcctl.service_type.interactive", FT_BOOLEAN, 32,
TFS(&tfs_svcctl_service_type_interactive_process), SVCCTL_SERVICE_TYPE_INTERACTIVE_PROCESS, "Request includes services that can interact with the desktop?", HFILL }},
{ &hf_svcctl_service_state,
{ "Service State", "svcctl.service_state", FT_UINT32, BASE_DEC,
VALS(svcctl_service_status_vals), 0x0, "SVCCTL service state", HFILL }},
{ &hf_svcctl_buffer,
{ "Buffer", "svcctl.buffer", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL buffer", HFILL }},
#if 0
{ &hf_svcctl_bytes_needed,
{ "Bytes Needed", "svcctl.bytes_needed", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL bytes needed", HFILL }},
{ &hf_svcctl_services_returned,
{ "Services Returned", "svcctl.services_returned", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL services returned", HFILL }},
#endif
{ &hf_svcctl_service_name,
{ "Service Name", "svcctl.servicename", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL name of service", HFILL }},
{ &hf_svcctl_display_name,
{ "Display Name", "svcctl.displayname", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL display name", HFILL }},
{ &hf_svcctl_service_start_type,
{ "Service Start Type", "svcctl.service_start_type", FT_UINT32, BASE_DEC,
VALS(svcctl_service_start_type_vals), 0x0, "SVCCTL service start type", HFILL }},
{ &hf_svcctl_service_error_control,
{ "Service Error Control", "svcctl.service_error_control", FT_UINT32, BASE_DEC,
VALS(svcctl_service_error_control_vals), 0x0, "SVCCTL service error control", HFILL }},
{ &hf_svcctl_binarypathname,
{ "Binary Path Name", "svcctl.binarypathname", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL binary path name", HFILL }},
{ &hf_svcctl_loadordergroup,
{ "Load Order Group", "svcctl.loadordergroup", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL load order group", HFILL }},
{ &hf_svcctl_tagid,
{ "Tag Id", "svcctl.tagid", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL tag id", HFILL }},
{ &hf_svcctl_dependencies,
{ "Dependencies", "svcctl.dependencies", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL dependencies", HFILL }},
{ &hf_svcctl_depend_size,
{ "Depend Size", "svcctl.depend_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL depend size", HFILL }},
{ &hf_svcctl_service_start_name,
{ "Service Start Name", "svcctl.service_start_name", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL service start name", HFILL }},
{ &hf_svcctl_password,
{ "Password", "svcctl.password", FT_STRING, BASE_NONE,
NULL, 0x0, "SVCCTL password", HFILL }},
{ &hf_svcctl_password_size,
{ "Password Size", "svcctl.password_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL password size", HFILL }},
{ &hf_svcctl_resume,
{ "Resume Handle", "svcctl.resume", FT_UINT32, BASE_DEC,
NULL, 0x0, "SVCCTL resume handle", HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_svcctl,
&ett_dcerpc_svcctl_service_type_bits,
};
proto_dcerpc_svcctl = proto_register_protocol(
"Microsoft Service Control", "SVCCTL", "svcctl");
proto_register_field_array(proto_dcerpc_svcctl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_svcctl(void)
{
dcerpc_init_uuid(proto_dcerpc_svcctl, ett_dcerpc_svcctl,
&uuid_dcerpc_svcctl, ver_dcerpc_svcctl,
dcerpc_svcctl_dissectors, hf_svcctl_opnum);
}
