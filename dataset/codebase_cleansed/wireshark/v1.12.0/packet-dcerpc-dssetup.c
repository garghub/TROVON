int
dssetup_dissect_enum_DsRole(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
int
dssetup_dissect_bitmap_DsRoleFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, DREP_ENC_INTEGER(drep));
tree = proto_item_add_subtree(item,ett_dssetup_dssetup_DsRoleFlags);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, di, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_RUNNING, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "DS_ROLE_PRIMARY_DS_RUNNING");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_MIXED_MODE, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "DS_ROLE_PRIMARY_DS_MIXED_MODE");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_UPGRADE_IN_PROGRESS, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "DS_ROLE_UPGRADE_IN_PROGRESS");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT, tvb, offset-4, 4, flags);
if (flags&( 0x01000000 )){
proto_item_append_text(item, "DS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT");
if (flags & (~( 0x01000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_role(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_enum_DsRole(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_role, 0);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_bitmap_DsRoleFlags(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_flags, 0);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain_, NDR_POINTER_UNIQUE, "Pointer to Domain (uint16)",hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_domain);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_domain, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_dns_domain(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dssetup_dissect_element_DsRolePrimaryDomInfoBasic_dns_domain_, NDR_POINTER_UNIQUE, "Pointer to Dns Domain (uint16)",hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_dns_domain);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_dns_domain_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_dns_domain, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_forest(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, di, drep, dssetup_dissect_element_DsRolePrimaryDomInfoBasic_forest_, NDR_POINTER_UNIQUE, "Pointer to Forest (uint16)",hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_forest);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_forest_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, di, drep, sizeof(guint16), hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_forest, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_domain_guid, NULL);
return offset;
}
int
dssetup_dissect_struct_DsRolePrimaryDomInfoBasic(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dssetup_dssetup_DsRolePrimaryDomInfoBasic);
}
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_role(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_flags(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_dns_domain(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_forest(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRolePrimaryDomInfoBasic_domain_guid(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
dssetup_dissect_enum_DsUpgrade(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint32 parameter=0;
if(param){
parameter=(guint32)*param;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
int
dssetup_dissect_enum_DsPrevious(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
dssetup_dissect_element_DsRoleUpgradeStatus_upgrading(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_enum_DsUpgrade(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRoleUpgradeStatus_upgrading, 0);
return offset;
}
static int
dssetup_dissect_element_DsRoleUpgradeStatus_previous_role(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_enum_DsPrevious(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRoleUpgradeStatus_previous_role, 0);
return offset;
}
int
dssetup_dissect_struct_DsRoleUpgradeStatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dssetup_dssetup_DsRoleUpgradeStatus);
}
offset = dssetup_dissect_element_DsRoleUpgradeStatus_upgrading(tvb, offset, pinfo, tree, di, drep);
offset = dssetup_dissect_element_DsRoleUpgradeStatus_previous_role(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
dssetup_dissect_enum_DsRoleOp(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
dssetup_dissect_element_DsRoleOpStatus_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_enum_DsRoleOp(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRoleOpStatus_status, 0);
return offset;
}
int
dssetup_dissect_struct_DsRoleOpStatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_3_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dssetup_dssetup_DsRoleOpStatus);
}
offset = dssetup_dissect_element_DsRoleOpStatus_status(tvb, offset, pinfo, tree, di, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_3_BYTES;
}
return offset;
}
int
dssetup_dissect_enum_DsRoleInfoLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
dssetup_dissect_element_DsRoleInfo_basic(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_struct_DsRolePrimaryDomInfoBasic(tvb,offset,pinfo,tree,di,drep,hf_dssetup_dssetup_DsRoleInfo_basic,0);
return offset;
}
static int
dssetup_dissect_element_DsRoleInfo_upgrade(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_struct_DsRoleUpgradeStatus(tvb,offset,pinfo,tree,di,drep,hf_dssetup_dssetup_DsRoleInfo_upgrade,0);
return offset;
}
static int
dssetup_dissect_element_DsRoleInfo_opstatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_struct_DsRoleOpStatus(tvb,offset,pinfo,tree,di,drep,hf_dssetup_dssetup_DsRoleInfo_opstatus,0);
return offset;
}
static int
dssetup_dissect_DsRoleInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, dcerpc_info* di _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint1632 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "dssetup_DsRoleInfo");
tree = proto_item_add_subtree(item, ett_dssetup_dssetup_DsRoleInfo);
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, di, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case DS_ROLE_BASIC_INFORMATION:
offset = dssetup_dissect_element_DsRoleInfo_basic(tvb, offset, pinfo, tree, di, drep);
break;
case DS_ROLE_UPGRADE_STATUS:
offset = dssetup_dissect_element_DsRoleInfo_upgrade(tvb, offset, pinfo, tree, di, drep);
break;
case DS_ROLE_OP_STATUS:
offset = dssetup_dissect_element_DsRoleInfo_opstatus(tvb, offset, pinfo, tree, di, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_enum_DsRoleInfoLevel(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRoleGetPrimaryDomainInformation_level, 0);
return offset;
}
static int
dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, di, drep, dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_info_, NDR_POINTER_UNIQUE, "Pointer to Info (dssetup_DsRoleInfo)",hf_dssetup_dssetup_DsRoleGetPrimaryDomainInformation_info);
return offset;
}
static int
dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
offset = dssetup_dissect_DsRoleInfo(tvb, offset, pinfo, tree, di, drep, hf_dssetup_dssetup_DsRoleGetPrimaryDomainInformation_info, 0);
return offset;
}
static int
dssetup_dissect_DsRoleGetPrimaryDomainInformation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleGetPrimaryDomainInformation";
offset = dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_info(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleGetPrimaryDomainInformation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleGetPrimaryDomainInformation";
offset = dssetup_dissect_element_DsRoleGetPrimaryDomainInformation_level(tvb, offset, pinfo, tree, di, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, di, drep);
return offset;
}
static int
dssetup_dissect_DsRoleDnsNameToFlatName_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleDnsNameToFlatName";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleDnsNameToFlatName_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleDnsNameToFlatName";
return offset;
}
static int
dssetup_dissect_DsRoleDcAsDc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleDcAsDc";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleDcAsDc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleDcAsDc";
return offset;
}
static int
dssetup_dissect_DsRoleDcAsReplica_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleDcAsReplica";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleDcAsReplica_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleDcAsReplica";
return offset;
}
static int
dssetup_dissect_DsRoleDemoteDc_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleDemoteDc";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleDemoteDc_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleDemoteDc";
return offset;
}
static int
dssetup_dissect_DsRoleGetDcOperationProgress_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleGetDcOperationProgress";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleGetDcOperationProgress_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleGetDcOperationProgress";
return offset;
}
static int
dssetup_dissect_DsRoleGetDcOperationResults_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleGetDcOperationResults";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleGetDcOperationResults_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleGetDcOperationResults";
return offset;
}
static int
dssetup_dissect_DsRoleCancel_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleCancel";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleCancel_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleCancel";
return offset;
}
static int
dssetup_dissect_DsRoleServerSaveStateForUpgrade_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleServerSaveStateForUpgrade";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleServerSaveStateForUpgrade_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleServerSaveStateForUpgrade";
return offset;
}
static int
dssetup_dissect_DsRoleUpgradeDownlevelServer_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleUpgradeDownlevelServer";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleUpgradeDownlevelServer_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleUpgradeDownlevelServer";
return offset;
}
static int
dssetup_dissect_DsRoleAbortDownlevelServerUpgrade_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
guint32 status;
di->dcerpc_procedure_name="DsRoleAbortDownlevelServerUpgrade";
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_dssetup_werror, &status);
if (status != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown DOS error 0x%08x"));
return offset;
}
static int
dssetup_dissect_DsRoleAbortDownlevelServerUpgrade_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, dcerpc_info* di _U_, guint8 *drep _U_)
{
di->dcerpc_procedure_name="DsRoleAbortDownlevelServerUpgrade";
return offset;
}
void proto_register_dcerpc_dssetup(void)
{
static hf_register_info hf[] = {
{ &hf_dssetup_dssetup_DsRoleGetPrimaryDomainInformation_level,
{ "Level", "dssetup.dssetup_DsRoleGetPrimaryDomainInformation.level", FT_UINT1632, BASE_DEC, VALS(dssetup_dssetup_DsRoleInfoLevel_vals), 0, NULL, HFILL }},
{ &hf_dssetup_opnum,
{ "Operation", "dssetup.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_flags,
{ "Flags", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleUpgradeStatus_previous_role,
{ "Previous Role", "dssetup.dssetup_DsRoleUpgradeStatus.previous_role", FT_UINT1632, BASE_DEC, VALS(dssetup_dssetup_DsPrevious_vals), 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleInfo_opstatus,
{ "Opstatus", "dssetup.dssetup_DsRoleInfo.opstatus", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_domain_guid,
{ "Domain Guid", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.domain_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleOpStatus_status,
{ "Status", "dssetup.dssetup_DsRoleOpStatus.status", FT_UINT1632, BASE_DEC, VALS(dssetup_dssetup_DsRoleOp_vals), 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleInfo_upgrade,
{ "Upgrade", "dssetup.dssetup_DsRoleInfo.upgrade", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleGetPrimaryDomainInformation_info,
{ "Info", "dssetup.dssetup_DsRoleGetPrimaryDomainInformation.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_UPGRADE_IN_PROGRESS,
{ "Ds Role Upgrade In Progress", "dssetup.dssetup_DsRoleFlags.DS_ROLE_UPGRADE_IN_PROGRESS", FT_BOOLEAN, 32, TFS(&dssetup_DsRoleFlags_DS_ROLE_UPGRADE_IN_PROGRESS_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT,
{ "Ds Role Primary Domain Guid Present", "dssetup.dssetup_DsRoleFlags.DS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT", FT_BOOLEAN, 32, TFS(&dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DOMAIN_GUID_PRESENT_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleInfo_basic,
{ "Basic", "dssetup.dssetup_DsRoleInfo.basic", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_role,
{ "Role", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.role", FT_UINT1632, BASE_DEC, VALS(dssetup_dssetup_DsRole_vals), 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_RUNNING,
{ "Ds Role Primary Ds Running", "dssetup.dssetup_DsRoleFlags.DS_ROLE_PRIMARY_DS_RUNNING", FT_BOOLEAN, 32, TFS(&dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_RUNNING_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_dns_domain,
{ "Dns Domain", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.dns_domain", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleUpgradeStatus_upgrading,
{ "Upgrading", "dssetup.dssetup_DsRoleUpgradeStatus.upgrading", FT_UINT32, BASE_DEC, VALS(dssetup_dssetup_DsUpgrade_vals), 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_domain,
{ "Domain", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.domain", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_dssetup_werror,
{ "Windows Error", "dssetup.werror", FT_UINT32, BASE_HEX, VALS(WERR_errors), 0, NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_MIXED_MODE,
{ "Ds Role Primary Ds Mixed Mode", "dssetup.dssetup_DsRoleFlags.DS_ROLE_PRIMARY_DS_MIXED_MODE", FT_BOOLEAN, 32, TFS(&dssetup_DsRoleFlags_DS_ROLE_PRIMARY_DS_MIXED_MODE_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_dssetup_dssetup_DsRolePrimaryDomInfoBasic_forest,
{ "Forest", "dssetup.dssetup_DsRolePrimaryDomInfoBasic.forest", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_dssetup,
&ett_dssetup_dssetup_DsRoleFlags,
&ett_dssetup_dssetup_DsRolePrimaryDomInfoBasic,
&ett_dssetup_dssetup_DsRoleUpgradeStatus,
&ett_dssetup_dssetup_DsRoleOpStatus,
&ett_dssetup_dssetup_DsRoleInfo,
};
proto_dcerpc_dssetup = proto_register_protocol("Active Directory Setup", "DSSETUP", "dssetup");
proto_register_field_array(proto_dcerpc_dssetup, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_dssetup(void)
{
dcerpc_init_uuid(proto_dcerpc_dssetup, ett_dcerpc_dssetup,
&uuid_dcerpc_dssetup, ver_dcerpc_dssetup,
dssetup_dissectors, hf_dssetup_opnum);
}
