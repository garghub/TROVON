static int
dissect_ICBABrowse_get_Count_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Count;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_count, &u32Count);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
if (u32HResult) {
col_append_fstr(pinfo->cinfo, COL_INFO, "-> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " Cnt=%u -> S_OK", u32Count);
}
return offset;
}
static int
dissect_ICBABrowse_BrowseItems_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Offset;
guint32 u32MaxReturn;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_offset, &u32Offset);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_max_return, &u32MaxReturn);
col_append_fstr(pinfo->cinfo, COL_INFO, " Offset=%u MaxReturn=%u",
u32Offset, u32MaxReturn);
return offset;
}
static int
dissect_ICBABrowse_BrowseItems_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Pointer;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_item);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_data_type);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_access_right);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBABrowse2_get_Count2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Selector;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_selector, &u32Selector);
col_append_fstr(pinfo->cinfo, COL_INFO, " Selector=%u",
u32Selector);
return offset;
}
static int
dissect_ICBABrowse2_BrowseItems2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Selector;
guint32 u32Offset;
guint32 u32MaxReturn;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_selector, &u32Selector);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_offset, &u32Offset);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_browse_max_return, &u32MaxReturn);
col_append_fstr(pinfo->cinfo, COL_INFO, " Sel=%u Offset=%u MaxReturn=%u",
u32Selector, u32Offset, u32MaxReturn);
return offset;
}
static int
dissect_ICBABrowse2_BrowseItems2_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Pointer;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_item);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_info1);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_browse_info2);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBAPersist2_Save2_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Pointer;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_save_ldev_name);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep, hf_cba_save_result);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_get_BSTR_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, int hfindex)
{
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
guint32 u32Pointer;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hfindex, szStr, u32MaxStr);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": \"%s\" -> %s", szStr,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_get_ProductionDate_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
gdouble r8Date;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DATE(tvb, offset, pinfo, tree, drep,
hf_cba_production_date, &r8Date);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Date: %g -> %s",
r8Date,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_get_SerialNo_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
guint32 u32Pointer;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_VARIANT(tvb, offset, pinfo, tree, drep,
hf_cba_serial_no);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBATime_get_Time_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
gdouble r8Date;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DATE(tvb, offset, pinfo, tree, drep,
hf_cba_time, &r8Date);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Time: %g -> %s",
r8Date,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBATime_put_Time_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
gdouble r8Date;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DATE(tvb, offset, pinfo, tree, drep,
hf_cba_time, &r8Date);
return offset;
}
static int
dissect_get_Producer_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return dissect_get_BSTR_resp(tvb, offset, pinfo, tree, drep, hf_cba_producer);
}
static int
dissect_get_Product_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return dissect_get_BSTR_resp(tvb, offset, pinfo, tree, drep, hf_cba_product);
}
static int
dissect_ICBAPhysicalDevice_get_LogicalDevice_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Pointer;
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
dcerpc_info *info = (dcerpc_info *) pinfo->private_data;
gchar *call;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hf_cba_name, szStr, u32MaxStr);
}
if (strlen(szStr) > 0) {
call = wmem_strdup(wmem_file_scope(), szStr);
info->call_data->private_data = call;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ": \"%s\"", szStr);
return offset;
}
static int
dissect_ICBAPhysicalDevice_get_LogicalDevice_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
dcerpc_info *info = (dcerpc_info *) pinfo->private_data;
gchar *ldev_name = (gchar *)info->call_data->private_data;
dcom_interface_t *pdev_interf;
dcom_interface_t *ldev_interf;
cba_pdev_t *pdev;
cba_ldev_t *ldev;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep, 0, &ldev_interf);
if (ldev_name != NULL && ldev_interf != NULL) {
pdev_interf = dcom_interface_new(pinfo, (const guint8 *)pinfo->net_dst.data, &uuid_ICBAPhysicalDevice, 0, 0, &info->call_data->object_uuid);
if (pdev_interf != NULL) {
pdev = cba_pdev_add(pinfo, (const guint8 *)pinfo->net_dst.data);
cba_pdev_link(pinfo, pdev, pdev_interf);
ldev = cba_ldev_add(pinfo, pdev, ldev_name);
cba_ldev_link(pinfo, ldev, ldev_interf);
}
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBAPhysicalDevice2_Type_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16MultiApp;
guint16 u16PROFInetDCOMStack;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_VARIANT_BOOL(tvb, offset, pinfo, tree, drep,
hf_cba_multi_app, &u16MultiApp);
offset = dissect_dcom_VARIANT_BOOL(tvb, offset, pinfo, tree, drep,
hf_cba_profinet_dcom_stack, &u16PROFInetDCOMStack);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " App=%s Stack=%s -> %s",
(u16MultiApp) ? "Multi" : "Single",
(u16PROFInetDCOMStack) ? "PN-DCOM" : "MS-DCOM",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_PROFInetRevision_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Major;
guint16 u16Minor;
guint16 u16ServicePack;
guint16 u16Build;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_major, &u16Major);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_minor, &u16Minor);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_service_pack, &u16ServicePack);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_build, &u16Build);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " Revision=%u.%u.%u.%u -> %s",
u16Major, u16Minor, u16ServicePack, u16Build,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBAPhysicalDevice2_get_PDevStamp_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32PDevStamp;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_pdev_stamp, &u32PDevStamp);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " PDevStamp=0x%x -> %s",
u32PDevStamp,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_Revision_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16Major;
guint16 u16Minor;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_major, &u16Major);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_revision_minor, &u16Minor);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u.%u -> %s",
u16Major, u16Minor,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBALogicalDevice_get_Name_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
guint32 u32Pointer;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hf_cba_name, szStr, u32MaxStr);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": \"%s\" -> %s", szStr,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_RTAuto_get_Name_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return dissect_get_BSTR_resp(tvb, offset, pinfo, tree, drep, hf_cba_name);
}
static int
dissect_ICBALogicalDevice_get_ACCO_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
dcom_interface_t *acco_interf;
dcerpc_info *info = (dcerpc_info *) pinfo->private_data;
cba_ldev_t *ldev;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep, 0, &acco_interf);
if (acco_interf == NULL) {
expert_add_info(pinfo, NULL, &ei_cba_acco_interface_pointer_unresolved);
}
ldev = cba_ldev_find(pinfo, pinfo->net_src.data, &info->call_data->object_uuid);
if (ldev != NULL && acco_interf != NULL) {
cba_ldev_link_acco(pinfo, ldev, acco_interf);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep, &u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBALogicalDevice_get_RTAuto_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep, 0, NULL);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep, &u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBALogicalDevice_Get_RTAuto_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
guint32 u32Pointer;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hf_cba_name, szStr, u32MaxStr);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ": \"%s\"", szStr);
return offset;
}
static int
dissect_ComponentInfo_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
gchar szStr[1000];
guint32 u32MaxStr = sizeof(szStr);
gchar szStr2[1000];
guint32 u32MaxStr2 = sizeof(szStr2);
guint32 u32HResult;
guint32 u32Pointer;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hf_cba_component_id, szStr, u32MaxStr);
}
offset = dissect_dcom_dcerpc_pointer(tvb, offset, pinfo, tree, drep,
&u32Pointer);
if (u32Pointer) {
offset = dissect_dcom_BSTR(tvb, offset, pinfo, tree, drep,
hf_cba_component_version, szStr2, u32MaxStr2);
}
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep, &u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": ID=\"%s\" Version=\"%s\" -> %s",
szStr, szStr2,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static void
dissect_PBAddressInfo(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep,
guint32 u32VarType _U_, guint32 u32ArraySize)
{
guint8 u8ID;
guint8 u8Addr;
proto_item *sub_item;
proto_tree *sub_tree;
while (u32ArraySize != 0) {
sub_item = proto_tree_add_item(tree, hf_cba_pbaddress, tvb, offset, 2, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_PBAddress);
offset = dissect_dcom_BYTE(tvb, offset, pinfo, sub_tree, drep,
hf_cba_pbaddress_system_id, &u8ID);
offset = dissect_dcom_BYTE(tvb, offset, pinfo, sub_tree, drep,
hf_cba_pbaddress_address, &u8Addr);
u32ArraySize-=2;
proto_item_append_text(sub_item, ": ID=0x%x Addr=%u", u8ID, u8Addr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", ID=0x%x Addr=%u",
u8ID, u8Addr);
}
}
static int
dissect_PBAddressInfo_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_SAFEARRAY(tvb, offset, pinfo, tree, drep, 0 , dissect_PBAddressInfo);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep, &u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> %s",
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_Advise_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep, 0, NULL);
return offset;
}
static int
dissect_Advise_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Cookie;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_cookie, &u32Cookie);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Cookie=0x%x -> %s",
u32Cookie,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_Unadvise_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Cookie;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_cookie, &u32Cookie);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Cookie=0x%x",
u32Cookie);
return offset;
}
static int
dissect_ICBAState_get_State_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16State;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_state, &u16State);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": State=%s -> %s",
val_to_str(u16State, cba_state_vals, "Unknown (0x%08x)"),
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBAStateEvent_OnStateChanged_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16NewState;
guint16 u16OldState;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_new_state, &u16NewState);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_old_state, &u16OldState);
col_append_fstr(pinfo->cinfo, COL_INFO, ": NewState=%s OldState=%s",
val_to_str(u16NewState, cba_state_vals, "Unknown (0x%04x)"),
val_to_str(u16OldState, cba_state_vals, "Unknown (0x%04x)") );
return offset;
}
static int
dissect_ICBAGroupError_OnGroupErrorChanged_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16NewGroupError;
guint16 u16OldGroupError;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_new_grouperror, &u16NewGroupError);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_old_grouperror, &u16OldGroupError);
col_append_fstr(pinfo->cinfo, COL_INFO, ": NewGE=%s OldGE=%s",
val_to_str(u16NewGroupError, cba_grouperror_vals, "Unknown (0x%04x)"),
val_to_str(u16OldGroupError, cba_grouperror_vals, "Unknown (0x%04x)") );
return offset;
}
static int
dissect_ICBAPhysicalDevicePCEvent_OnLogicalDeviceAdded_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 u32Cookie;
guint32 u32HResult;
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_cookie, &u32Cookie);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep, 0, NULL);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": Cookie=0x%x %s",
u32Cookie,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static int
dissect_ICBAGroupError_GroupError_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint16 u16GroupError;
guint32 u32Cookie;
guint32 u32HResult;
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_WORD(tvb, offset, pinfo, tree, drep,
hf_cba_grouperror, &u16GroupError);
offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
hf_cba_cookie, &u32Cookie);
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
&u32HResult);
col_append_fstr(pinfo->cinfo, COL_INFO, ": GroupError=%s Cookie=0x%x -> %s",
val_to_str(u16GroupError, cba_grouperror_vals, "Unknown (0x%08x)"),
u32Cookie,
val_to_str(u32HResult, dcom_hresult_vals, "Unknown (0x%08x)") );
return offset;
}
static void cba_reinit( void) {
cba_pdevs = NULL;
}
void
proto_register_dcom_cba (void)
{
static hf_register_info hf_cba_browse_array[] = {
{ &hf_cba_browse_count,
{ "Count", "cba.browse.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_offset,
{ "Offset", "cba.browse.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_max_return,
{ "MaxReturn", "cba.browse.max_return",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_item,
{ "ItemNames", "cba.browse.item",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_data_type,
{ "DataTypes", "cba.browse.data_type",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_access_right,
{ "AccessRights", "cba.browse.access_right",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_selector,
{ "Selector", "cba.browse.selector",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_info1,
{ "Info1", "cba.browse.info1",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_browse_info2,
{ "Info2", "cba.browse.info2",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_cba_pdev_array[] = {
{ &hf_cba_revision_major,
{ "Major", "cba.revision_major",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_revision_minor,
{ "Minor", "cba.revision_minor",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_revision_service_pack,
{ "ServicePack", "cba.revision_service_pack",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_revision_build,
{ "Build", "cba_revision_build",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_producer,
{ "Producer", "cba.producer",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_product,
{ "Product", "cba.product",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_multi_app,
{ "MultiApp", "cba.multi_app",
FT_UINT16, BASE_HEX, VALS(dcom_boolean_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_profinet_dcom_stack,
{ "PROFInetDCOMStack", "cba.profinet_dcom_stack",
FT_UINT16, BASE_HEX, VALS(dcom_boolean_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_pdev_stamp,
{ "PDevStamp", "cba.pdev_stamp",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_save_ldev_name,
{ "LDevName", "cba.save_ldev_name",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_save_result,
{ "PartialResult", "cba.save_result",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_cba_ldev_array[] = {
{ &hf_cba_name,
{ "Name", "cba.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_component_id,
{ "ComponentID", "cba.component_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_component_version,
{ "Version", "cba.component_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_pbaddress,
{ "PROFIBUS Address", "cba.pbaddress",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_pbaddress_system_id,
{ "SystemID", "cba.pbaddress.system_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_pbaddress_address,
{ "Address", "cba.pbaddress.address",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_cba_array[] = {
{ &hf_cba_opnum,
{ "Operation", "cba.opnum",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_production_date,
{ "ProductionDate", "cba.production_date",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_time,
{ "Time", "cba.time",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_serial_no,
{ "SerialNo", "cba.serial_no",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_state,
{ "State", "cba.state",
FT_UINT16, BASE_HEX, VALS(cba_state_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_new_state,
{ "NewState", "cba.state_new",
FT_UINT16, BASE_HEX, VALS(cba_state_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_old_state,
{ "OldState", "cba.state_old",
FT_UINT16, BASE_HEX, VALS(cba_state_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_cookie,
{ "Cookie", "cba.cookie",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_cba_grouperror,
{ "GroupError", "cba.grouperror",
FT_UINT16, BASE_HEX, VALS(cba_grouperror_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_new_grouperror,
{ "NewGroupError", "cba.grouperror_new",
FT_UINT16, BASE_HEX, VALS(cba_grouperror_vals), 0x0,
NULL, HFILL }},
{ &hf_cba_old_grouperror,
{ "OldGroupError", "cba.grouperror_old",
FT_UINT16, BASE_HEX, VALS(cba_grouperror_vals), 0x0,
NULL, HFILL }},
};
static gint *ett_cba[] = {
&ett_ICBAPhysicalDevice,
&ett_ICBABrowse,
&ett_ICBAPhysicalDevicePC,
&ett_ICBAPhysicalDevicePCEvent,
&ett_ICBAPersist,
&ett_ICBALogicalDevice,
&ett_ICBAState,
&ett_ICBAStateEvent,
&ett_ICBATime,
&ett_ICBAGroupError,
&ett_ICBAGroupErrorEvent,
&ett_ICBARTAuto,
&ett_ICBASystemProperties,
&ett_PBAddress
};
static ei_register_info ei[] = {
{ &ei_cba_acco_interface_pointer_unresolved, { "cba.acco.interface_pointer_unresolved", PI_UNDECODED, PI_WARN, "LDev_get_ACCO: can't resolve ACCO interface pointer", EXPFILL }},
};
expert_module_t* expert_cba_acco;
proto_register_subtree_array (ett_cba, array_length (ett_cba));
proto_ICBAPhysicalDevice = proto_register_protocol ("ICBAPhysicalDevice", "ICBAPDev", "cba_pdev");
proto_register_field_array(proto_ICBAPhysicalDevice, hf_cba_pdev_array, array_length(hf_cba_pdev_array));
expert_cba_acco = expert_register_protocol(proto_ICBAPhysicalDevice);
expert_register_field_array(expert_cba_acco, ei, array_length(ei));
proto_ICBAPhysicalDevice2 = proto_register_protocol ("ICBAPhysicalDevice2", "ICBAPDev2", "cba_pdev2");
proto_ICBABrowse = proto_register_protocol ("ICBABrowse", "ICBABrowse", "cba_browse");
proto_register_field_array(proto_ICBABrowse, hf_cba_array, array_length(hf_cba_array));
proto_register_field_array(proto_ICBABrowse, hf_cba_browse_array, array_length(hf_cba_browse_array));
proto_ICBABrowse2 = proto_register_protocol ("ICBABrowse2", "ICBABrowse2", "cba_browse2");
proto_ICBAPhysicalDevicePC = proto_register_protocol ("ICBAPhysicalDevicePC", "ICBAPDevPC", "cba_pdev_pc");
proto_ICBAPhysicalDevicePCEvent = proto_register_protocol ("ICBAPhysicalDevicePCEvent", "ICBAPDevPCEvent", "cba_pdev_pc_event");
proto_ICBAPersist = proto_register_protocol ("ICBAPersist", "ICBAPersist", "cba_persist");
proto_ICBAPersist2 = proto_register_protocol ("ICBAPersist2", "ICBAPersist2", "cba_persist2");
proto_ICBALogicalDevice = proto_register_protocol ("ICBALogicalDevice", "ICBALDev", "cba_ldev");
proto_register_field_array(proto_ICBAPhysicalDevice, hf_cba_ldev_array, array_length(hf_cba_ldev_array));
proto_ICBALogicalDevice2 = proto_register_protocol ("ICBALogicalDevice2", "ICBALDev2", "cba_ldev2");
proto_ICBAState = proto_register_protocol ("ICBAState", "ICBAState", "cba_state");
proto_ICBAStateEvent = proto_register_protocol ("ICBAStateEvent", "ICBAStateEvent", "cba_state_event");
proto_ICBATime = proto_register_protocol ("ICBATime", "ICBATime", "cba_time");
proto_ICBAGroupError = proto_register_protocol ("ICBAGroupError", "ICBAGErr", "cba_grouperror");
proto_ICBAGroupErrorEvent = proto_register_protocol ("ICBAGroupErrorEvent", "ICBAGErrEvent", "cba_grouperror_event");
proto_ICBARTAuto = proto_register_protocol ("ICBARTAuto", "ICBARTAuto", "cba_rtauto");
proto_ICBARTAuto2 = proto_register_protocol ("ICBARTAuto2", "ICBARTAuto2", "cba_rtauto2");
proto_ICBASystemProperties = proto_register_protocol ("ICBASystemProperties", "ICBASysProp", "cba_sysprop");
register_init_routine(cba_reinit);
}
void
proto_reg_handoff_dcom_cba (void)
{
guids_add_uuid(&uuid_coclass_CBAPhysicalDevice, "CBA");
dcerpc_init_uuid(proto_ICBAPhysicalDevice, ett_ICBAPhysicalDevice,
&uuid_ICBAPhysicalDevice, ver_ICBAPhysicalDevice,
ICBAPhysicalDevice_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAPhysicalDevice2, ett_ICBAPhysicalDevice,
&uuid_ICBAPhysicalDevice2, ver_ICBAPhysicalDevice2,
ICBAPhysicalDevice_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBABrowse, ett_ICBABrowse,
&uuid_ICBABrowse, ver_ICBABrowse,
ICBABrowse_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBABrowse2, ett_ICBABrowse,
&uuid_ICBABrowse2, ver_ICBABrowse2,
ICBABrowse_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAPhysicalDevicePC, ett_ICBAPhysicalDevicePC,
&uuid_ICBAPhysicalDevicePC, ver_ICBAPhysicalDevicePC,
ICBAPhysicalDevicePC_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAPhysicalDevicePCEvent, ett_ICBAPhysicalDevicePCEvent,
&uuid_ICBAPhysicalDevicePCEvent, ver_ICBAPhysicalDevicePCEvent,
ICBAPhysicalDevicePCEvent_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAPersist, ett_ICBAPersist,
&uuid_ICBAPersist, ver_ICBAPersist,
ICBAPersist_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAPersist2, ett_ICBAPersist,
&uuid_ICBAPersist2, ver_ICBAPersist2,
ICBAPersist_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBALogicalDevice, ett_ICBALogicalDevice,
&uuid_ICBALogicalDevice, ver_ICBALogicalDevice,
ICBALogicalDevice_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBALogicalDevice2, ett_ICBALogicalDevice,
&uuid_ICBALogicalDevice2, ver_ICBALogicalDevice2,
ICBALogicalDevice_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAState, ett_ICBAState,
&uuid_ICBAState, ver_ICBAState,
ICBAState_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAStateEvent, ett_ICBAStateEvent,
&uuid_ICBAStateEvent, ver_ICBAStateEvent,
ICBAStateEvent_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBATime, ett_ICBATime,
&uuid_ICBATime, ver_ICBATime,
ICBATime_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAGroupError, ett_ICBAGroupError,
&uuid_ICBAGroupError, ver_ICBAGroupError,
ICBAGroupError_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBAGroupErrorEvent, ett_ICBAGroupErrorEvent,
&uuid_ICBAGroupErrorEvent, ver_ICBAGroupErrorEvent,
ICBAGroupErrorEvent_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBARTAuto, ett_ICBARTAuto,
&uuid_ICBARTAuto, ver_ICBARTAuto,
ICBARTAuto_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBARTAuto2, ett_ICBARTAuto,
&uuid_ICBARTAuto2, ver_ICBARTAuto2,
ICBARTAuto_dissectors, hf_cba_opnum);
dcerpc_init_uuid(proto_ICBASystemProperties, ett_ICBASystemProperties,
&uuid_ICBASystemProperties, ver_ICBASystemProperties,
ICBASystemProperties_dissectors, hf_cba_opnum);
}
