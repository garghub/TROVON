static int
mdssvc_dissect_element_blob_spotlight_blob(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info* di, guint8 *drep _U_)
{
tvbuff_t *spotlight_tvb;
dissector_handle_t spotlight_handle;
if (di->conformant_run) {
return offset;
}
spotlight_handle = find_dissector("afp_spotlight");
if (spotlight_handle)
{
spotlight_tvb = tvb_new_subset_remaining(tvb, offset + 16);
return (offset + 16 + call_dissector(spotlight_handle, spotlight_tvb, pinfo, tree));
}
return offset;
}
static int
mdssvc_dissect_element_blob_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_blob_length, 0);
return offset;
}
static int
mdssvc_dissect_element_blob_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_blob_size, 0);
return offset;
}
int
mdssvc_dissect_struct_blob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mdssvc_mdssvc_blob);
}
offset = mdssvc_dissect_element_blob_length(tvb, offset, pinfo, tree, di, drep);
offset = mdssvc_dissect_element_blob_size(tvb, offset, pinfo, tree, di, drep);
offset = mdssvc_dissect_element_blob_spotlight_blob(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
mdssvc_dissect_element_open_device_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_open_device_id_, NDR_POINTER_REF, "Pointer to Device Id (uint32)",hf_mdssvc_mdssvc_open_device_id);
return offset;
}
static int
mdssvc_dissect_element_open_device_id_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_open_device_id, 0);
return offset;
}
static int
mdssvc_dissect_element_open_unkn2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_open_unkn2_, NDR_POINTER_REF, "Pointer to Unkn2 (uint32)",hf_mdssvc_mdssvc_open_unkn2);
return offset;
}
static int
mdssvc_dissect_element_open_unkn2_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_open_unkn2, 0);
return offset;
}
static int
mdssvc_dissect_element_open_unkn3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_open_unkn3_, NDR_POINTER_REF, "Pointer to Unkn3 (uint32)",hf_mdssvc_mdssvc_open_unkn3);
return offset;
}
static int
mdssvc_dissect_element_open_unkn3_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_open_unkn3, 0);
return offset;
}
static int
mdssvc_dissect_element_open_share_mount_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mdssvc_mdssvc_open_share_mount_path, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mdssvc_dissect_element_open_share_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mdssvc_mdssvc_open_share_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mdssvc_dissect_element_open_share_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint8), hf_mdssvc_mdssvc_open_share_path, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
mdssvc_dissect_element_open_share_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_open_share_handle_, NDR_POINTER_REF, "Pointer to Share Handle (policy_handle)",hf_mdssvc_mdssvc_open_share_handle);
return offset;
}
static int
mdssvc_dissect_element_open_share_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_open_share_handle, 0);
return offset;
}
static int
mdssvc_dissect_open_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="open";
offset = mdssvc_dissect_element_open_device_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_unkn2(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_unkn3(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_share_path(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_share_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mdssvc_dissect_open_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="open";
offset = mdssvc_dissect_element_open_device_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_unkn2(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_unkn3(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_share_mount_path(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_open_share_name(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mdssvc_dissect_element_unknown1_share_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_share_handle, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn1, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_device_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_device_id, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn3, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn4, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn5, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn6, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_unknown1_status_, NDR_POINTER_REF, "Pointer to Status (uint32)",hf_mdssvc_mdssvc_unknown1_status);
return offset;
}
static int
mdssvc_dissect_element_unknown1_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_status, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_unknown1_flags_, NDR_POINTER_REF, "Pointer to Flags (uint32)",hf_mdssvc_mdssvc_unknown1_flags);
return offset;
}
static int
mdssvc_dissect_element_unknown1_flags_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_flags, 0);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_unknown1_unkn7_, NDR_POINTER_REF, "Pointer to Unkn7 (uint32)",hf_mdssvc_mdssvc_unknown1_unkn7);
return offset;
}
static int
mdssvc_dissect_element_unknown1_unkn7_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_unknown1_unkn7, 0);
return offset;
}
static int
mdssvc_dissect_unknown1_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="unknown1";
offset = mdssvc_dissect_element_unknown1_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_flags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn7(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mdssvc_dissect_unknown1_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="unknown1";
offset = mdssvc_dissect_element_unknown1_share_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn1(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_device_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn3(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn4(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn5(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_unknown1_unkn6(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mdssvc_dissect_element_cmd_share_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_share_handle, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn1, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_device_id(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_device_id, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn3, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn4, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_flags, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_request_blob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mdssvc_dissect_struct_blob(tvb,offset,pinfo,tree,di,drep,hf_mdssvc_mdssvc_cmd_request_blob,0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn5, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_max_fragment_size1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_max_fragment_size1, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn6, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_max_fragment_size2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_max_fragment_size2, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn7, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn8(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn8, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_cmd_status_, NDR_POINTER_REF, "Pointer to Status (uint32)",hf_mdssvc_mdssvc_cmd_status);
return offset;
}
static int
mdssvc_dissect_element_cmd_status_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_status, 0);
return offset;
}
static int
mdssvc_dissect_element_cmd_response_blob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_cmd_response_blob_, NDR_POINTER_REF, "Pointer to Response Blob (mdssvc_blob)",hf_mdssvc_mdssvc_cmd_response_blob);
return offset;
}
static int
mdssvc_dissect_element_cmd_response_blob_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = mdssvc_dissect_struct_blob(tvb,offset,pinfo,tree,di,drep,hf_mdssvc_mdssvc_cmd_response_blob,0);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn9(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, mdssvc_dissect_element_cmd_unkn9_, NDR_POINTER_REF, "Pointer to Unkn9 (uint32)",hf_mdssvc_mdssvc_cmd_unkn9);
return offset;
}
static int
mdssvc_dissect_element_cmd_unkn9_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, di, drep, hf_mdssvc_mdssvc_cmd_unkn9, 0);
return offset;
}
static int
mdssvc_dissect_cmd_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="cmd";
offset = mdssvc_dissect_element_cmd_status(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_response_blob(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn9(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
mdssvc_dissect_cmd_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="cmd";
offset = mdssvc_dissect_element_cmd_share_handle(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn1(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_device_id(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn3(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn4(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_flags(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_request_blob(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn5(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_max_fragment_size1(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn6(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_max_fragment_size2(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn7(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = mdssvc_dissect_element_cmd_unkn8(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
void proto_register_dcerpc_mdssvc(void)
{
static hf_register_info hf[] = {
{ &hf_mdssvc_mdssvc_blob_length,
{ "Length", "mdssvc.mdssvc_blob.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_blob_size,
{ "Size", "mdssvc.mdssvc_blob.size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_blob_spotlight_blob,
{ "Spotlight Blob", "mdssvc.mdssvc_blob.spotlight_blob", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_device_id,
{ "Device Id", "mdssvc.mdssvc_cmd.device_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_flags,
{ "Flags", "mdssvc.mdssvc_cmd.flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_max_fragment_size1,
{ "Max Fragment Size1", "mdssvc.mdssvc_cmd.max_fragment_size1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_max_fragment_size2,
{ "Max Fragment Size2", "mdssvc.mdssvc_cmd.max_fragment_size2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_request_blob,
{ "Request Blob", "mdssvc.mdssvc_cmd.request_blob", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_response_blob,
{ "Response Blob", "mdssvc.mdssvc_cmd.response_blob", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_share_handle,
{ "Share Handle", "mdssvc.mdssvc_cmd.share_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_status,
{ "Status", "mdssvc.mdssvc_cmd.status", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn1,
{ "Unkn1", "mdssvc.mdssvc_cmd.unkn1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn3,
{ "Unkn3", "mdssvc.mdssvc_cmd.unkn3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn4,
{ "Unkn4", "mdssvc.mdssvc_cmd.unkn4", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn5,
{ "Unkn5", "mdssvc.mdssvc_cmd.unkn5", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn6,
{ "Unkn6", "mdssvc.mdssvc_cmd.unkn6", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn7,
{ "Unkn7", "mdssvc.mdssvc_cmd.unkn7", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn8,
{ "Unkn8", "mdssvc.mdssvc_cmd.unkn8", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_cmd_unkn9,
{ "Unkn9", "mdssvc.mdssvc_cmd.unkn9", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_device_id,
{ "Device Id", "mdssvc.mdssvc_open.device_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_share_handle,
{ "Share Handle", "mdssvc.mdssvc_open.share_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_share_mount_path,
{ "Share Mount Path", "mdssvc.mdssvc_open.share_mount_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_share_name,
{ "Share Name", "mdssvc.mdssvc_open.share_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_share_path,
{ "Share Path", "mdssvc.mdssvc_open.share_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_unkn2,
{ "Unkn2", "mdssvc.mdssvc_open.unkn2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_open_unkn3,
{ "Unkn3", "mdssvc.mdssvc_open.unkn3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_device_id,
{ "Device Id", "mdssvc.mdssvc_unknown1.device_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_flags,
{ "Flags", "mdssvc.mdssvc_unknown1.flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_share_handle,
{ "Share Handle", "mdssvc.mdssvc_unknown1.share_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_status,
{ "Status", "mdssvc.mdssvc_unknown1.status", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn1,
{ "Unkn1", "mdssvc.mdssvc_unknown1.unkn1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn3,
{ "Unkn3", "mdssvc.mdssvc_unknown1.unkn3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn4,
{ "Unkn4", "mdssvc.mdssvc_unknown1.unkn4", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn5,
{ "Unkn5", "mdssvc.mdssvc_unknown1.unkn5", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn6,
{ "Unkn6", "mdssvc.mdssvc_unknown1.unkn6", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_mdssvc_unknown1_unkn7,
{ "Unkn7", "mdssvc.mdssvc_unknown1.unkn7", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mdssvc_opnum,
{ "Operation", "mdssvc.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_mdssvc,
&ett_mdssvc_mdssvc_blob,
};
proto_dcerpc_mdssvc = proto_register_protocol("Spotlight metadata search service", "MDSSVC", "mdssvc");
proto_register_field_array(proto_dcerpc_mdssvc, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_mdssvc(void)
{
dcerpc_init_uuid(proto_dcerpc_mdssvc, ett_dcerpc_mdssvc,
&uuid_dcerpc_mdssvc, ver_dcerpc_mdssvc,
mdssvc_dissectors, hf_mdssvc_opnum);
}
