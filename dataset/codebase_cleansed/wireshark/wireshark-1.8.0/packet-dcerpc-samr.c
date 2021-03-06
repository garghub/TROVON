static void
samr_connect_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_LOOKUP_DOMAIN, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_ENUM_DOMAINS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_CREATE_DOMAIN, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_INITIALIZE_SERVER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_SHUTDOWN_SERVER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_CONNECT_TO_SERVER, tvb, offset, 4, access);
}
int
samr_dissect_bitmap_ConnectAccessMask(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask,
&samr_connect_access_mask_info, NULL);
return offset;
}
static void
samr_alias_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_ADD_MEMBER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_REMOVE_MEMBER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_GET_MEMBERS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_LOOKUP_INFO, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_SET_INFO, tvb, offset, 4, access);
}
int
samr_dissect_bitmap_AliasAccessMask(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, drep, hf_samr_alias_access_mask,
&samr_alias_access_mask_info, NULL);
return offset;
}
static void
samr_group_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_GET_MEMBERS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_REMOVE_MEMBER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_ADD_MEMBER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_SET_INFO, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_LOOKUP_INFO, tvb, offset, 4, access);
}
int
samr_dissect_bitmap_GroupAccessMask(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, drep, hf_samr_group_access_mask,
&samr_group_access_mask_info, NULL);
return offset;
}
static void
samr_domain_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_1, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_1, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_2, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_2, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_USER, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_GROUP, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_ALIAS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_ALIAS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_ENUM_ACCOUNTS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_OPEN_ACCOUNT, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_3, tvb, offset, 4, access);
}
int
samr_dissect_bitmap_DomainAccessMask(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, drep, hf_samr_domain_access_mask,
&samr_domain_access_mask_info, NULL);
return offset;
}
static void
samr_user_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_GROUP_MEMBERSHIP, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUP_MEMBERSHIP, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUPS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_PASSWORD, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_PASSWORD, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_ATTRIBUTES, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_ATTRIBUTES, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOGONINFO, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_LOC_COM, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOCALE, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_NAME_ETC, tvb, offset, 4, access);
}
int
samr_dissect_bitmap_UserAccessMask(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, drep, hf_samr_user_access_mask,
&samr_user_access_mask_info, NULL);
return offset;
}
static int
cnf_dissect_lsa_AsciiString(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, guint32 param _U_, int hfindex)
{
offset = dissect_ndr_counted_ascii_string(tvb, offset, pinfo, tree, drep,
hfindex, 0);
return offset;
}
static int
cnf_dissect_hyper(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, guint32 param _U_, int hfindex)
{
offset = dissect_ndr_uint64(tvb, offset, pinfo, tree, drep, hfindex, NULL);
return offset;
}
static int
cnf_dissect_sec_desc_buf_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint64 len;
dcerpc_info *di = NULL;
e_ctx_hnd *polhnd = NULL;
dcerpc_call_value *dcv = NULL;
guint32 type=0;
struct access_mask_info *ami=NULL;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint3264 (tvb, offset, pinfo, tree, drep,
hf_samr_sec_desc_buf_len, &len);
dcv = (dcerpc_call_value *)di->call_data;
if(dcv){
polhnd = dcv->pol;
}
if(polhnd){
dcerpc_fetch_polhnd_data(polhnd, NULL, &type, NULL, NULL,
pinfo->fd->num);
}
switch(type){
case PIDL_POLHND_TYPE_SAMR_USER:
ami=&samr_user_access_mask_info;
break;
case PIDL_POLHND_TYPE_SAMR_CONNECT:
ami=&samr_connect_access_mask_info;
break;
case PIDL_POLHND_TYPE_SAMR_DOMAIN:
ami=&samr_domain_access_mask_info;
break;
case PIDL_POLHND_TYPE_SAMR_GROUP:
ami=&samr_group_access_mask_info;
break;
case PIDL_POLHND_TYPE_SAMR_ALIAS:
ami=&samr_alias_access_mask_info;
break;
}
dissect_nt_sec_desc(tvb, offset, pinfo, tree, drep, TRUE, (int)len, ami);
offset += (int)len;
return offset;
}
static int
cnf_dissect_sec_desc_buf(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint64 len;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint3264 (tvb, offset, pinfo, tree, drep,
hf_samr_sec_desc_buf_len, &len);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
cnf_dissect_sec_desc_buf_, NDR_POINTER_UNIQUE,
"SAM SECURITY DESCRIPTOR data:", -1);
return offset;
}
static int
cnf_dissect_dom_sid2(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_nt_SID(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
cnf_dissect_lsa_SidArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_nt_PSID_ARRAY(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
cnf_dissect_samr_security_secinfo(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, guint8 *drep _U_)
{
offset = dissect_nt_security_information(tvb, offset, tree);
return offset;
}
static int
samr_dissect_element_lsa_Strings_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_lsa_Strings_count, 0);
return offset;
}
static int
samr_dissect_element_lsa_Strings_names(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_lsa_Strings_names_, NDR_POINTER_UNIQUE, "Pointer to Names (lsa_String)",hf_samr_lsa_Strings_names);
return offset;
}
static int
samr_dissect_element_lsa_Strings_names_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_lsa_Strings_names__);
return offset;
}
static int
samr_dissect_element_lsa_Strings_names__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_lsa_Strings_names);
return offset;
}
int
samr_dissect_struct_lsa_Strings(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_lsa_Strings);
}
offset = samr_dissect_element_lsa_Strings_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_lsa_Strings_names(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_enum_lsa_SidType(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
int
samr_dissect_enum_RejectReason(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
int
samr_dissect_bitmap_AcctFlags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_samr_samr_AcctFlags);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_DISABLED, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "ACB_DISABLED");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_HOMDIRREQ, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "ACB_HOMDIRREQ");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_PWNOTREQ, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "ACB_PWNOTREQ");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_TEMPDUP, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "ACB_TEMPDUP");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_NORMAL, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "ACB_NORMAL");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_MNS, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "ACB_MNS");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_DOMTRUST, tvb, offset-4, 4, flags);
if (flags&( 0x00000040 )){
proto_item_append_text(item, "ACB_DOMTRUST");
if (flags & (~( 0x00000040 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000040 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_WSTRUST, tvb, offset-4, 4, flags);
if (flags&( 0x00000080 )){
proto_item_append_text(item, "ACB_WSTRUST");
if (flags & (~( 0x00000080 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000080 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_SVRTRUST, tvb, offset-4, 4, flags);
if (flags&( 0x00000100 )){
proto_item_append_text(item, "ACB_SVRTRUST");
if (flags & (~( 0x00000100 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000100 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_PWNOEXP, tvb, offset-4, 4, flags);
if (flags&( 0x00000200 )){
proto_item_append_text(item, "ACB_PWNOEXP");
if (flags & (~( 0x00000200 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000200 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_AUTOLOCK, tvb, offset-4, 4, flags);
if (flags&( 0x00000400 )){
proto_item_append_text(item, "ACB_AUTOLOCK");
if (flags & (~( 0x00000400 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000400 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_ENC_TXT_PWD_ALLOWED, tvb, offset-4, 4, flags);
if (flags&( 0x00000800 )){
proto_item_append_text(item, "ACB_ENC_TXT_PWD_ALLOWED");
if (flags & (~( 0x00000800 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000800 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_SMARTCARD_REQUIRED, tvb, offset-4, 4, flags);
if (flags&( 0x00001000 )){
proto_item_append_text(item, "ACB_SMARTCARD_REQUIRED");
if (flags & (~( 0x00001000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00001000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_TRUSTED_FOR_DELEGATION, tvb, offset-4, 4, flags);
if (flags&( 0x00002000 )){
proto_item_append_text(item, "ACB_TRUSTED_FOR_DELEGATION");
if (flags & (~( 0x00002000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00002000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_NOT_DELEGATED, tvb, offset-4, 4, flags);
if (flags&( 0x00004000 )){
proto_item_append_text(item, "ACB_NOT_DELEGATED");
if (flags & (~( 0x00004000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00004000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_USE_DES_KEY_ONLY, tvb, offset-4, 4, flags);
if (flags&( 0x00008000 )){
proto_item_append_text(item, "ACB_USE_DES_KEY_ONLY");
if (flags & (~( 0x00008000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00008000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_DONT_REQUIRE_PREAUTH, tvb, offset-4, 4, flags);
if (flags&( 0x00010000 )){
proto_item_append_text(item, "ACB_DONT_REQUIRE_PREAUTH");
if (flags & (~( 0x00010000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00010000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_PW_EXPIRED, tvb, offset-4, 4, flags);
if (flags&( 0x00020000 )){
proto_item_append_text(item, "ACB_PW_EXPIRED");
if (flags & (~( 0x00020000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00020000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_TRUST_AUTH_DELEGAT, tvb, offset-4, 4, flags);
if (flags&( 0x00040000 )){
proto_item_append_text(item, "ACB_TRUST_AUTH_DELEGAT");
if (flags & (~( 0x00040000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00040000 ));
proto_tree_add_boolean(tree, hf_samr_samr_AcctFlags_ACB_NO_AUTH_DATA_REQD, tvb, offset-4, 4, flags);
if (flags&( 0x00080000 )){
proto_item_append_text(item, "ACB_NO_AUTH_DATA_REQD");
if (flags & (~( 0x00080000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00080000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
samr_dissect_element_SamEntry_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SamEntry_idx, 0);
return offset;
}
static int
samr_dissect_element_SamEntry_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_SamEntry_name);
return offset;
}
int
samr_dissect_struct_SamEntry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_SamEntry);
}
offset = samr_dissect_element_SamEntry_idx(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_SamEntry_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_SamArray_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SamArray_count, 0);
return offset;
}
static int
samr_dissect_element_SamArray_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SamArray_entries_, NDR_POINTER_UNIQUE, "Pointer to Entries (samr_SamEntry)",hf_samr_samr_SamArray_entries);
return offset;
}
static int
samr_dissect_element_SamArray_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_SamArray_entries__);
return offset;
}
static int
samr_dissect_element_SamArray_entries__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_SamEntry(tvb,offset,pinfo,tree,drep,hf_samr_samr_SamArray_entries,3|PIDL_SET_COL_INFO);
return offset;
}
int
samr_dissect_struct_SamArray(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_SamArray);
}
offset = samr_dissect_element_SamArray_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_SamArray_entries(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_enum_DomainInfoClass(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
int
samr_dissect_enum_Role(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
int
samr_dissect_bitmap_PasswordProperties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_samr_samr_PasswordProperties);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_COMPLEX, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "DOMAIN_PASSWORD_COMPLEX");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_NO_ANON_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "DOMAIN_PASSWORD_NO_ANON_CHANGE");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_NO_CLEAR_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "DOMAIN_PASSWORD_NO_CLEAR_CHANGE");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_LOCKOUT_ADMINS, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "DOMAIN_PASSWORD_LOCKOUT_ADMINS");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_STORE_CLEARTEXT, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "DOMAIN_PASSWORD_STORE_CLEARTEXT");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_samr_samr_PasswordProperties_DOMAIN_REFUSE_PASSWORD_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "DOMAIN_REFUSE_PASSWORD_CHANGE");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
samr_dissect_enum_DomainServerState(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
samr_dissect_element_DomInfo1_min_password_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo1_min_password_length, 0);
return offset;
}
static int
samr_dissect_element_DomInfo1_password_history_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo1_password_history_length, 0);
return offset;
}
static int
samr_dissect_element_DomInfo1_password_properties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_PasswordProperties(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo1_password_properties, 0);
return offset;
}
static int
samr_dissect_element_DomInfo1_max_password_age(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo1_max_password_age, NULL);
return offset;
}
static int
samr_dissect_element_DomInfo1_min_password_age(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo1_min_password_age, NULL);
return offset;
}
int
samr_dissect_struct_DomInfo1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo1);
}
offset = samr_dissect_element_DomInfo1_min_password_length(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo1_password_history_length(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo1_password_properties(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo1_max_password_age(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo1_min_password_age(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_force_logoff_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_force_logoff_time);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_oem_information(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomGeneralInformation_oem_information);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_domain_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomGeneralInformation_domain_name);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_primary(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomGeneralInformation_primary);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_sequence_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_sequence_num, NULL);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_domain_server_state(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainServerState(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_domain_server_state, 0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_role(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_Role(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_role, 0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_unknown3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_unknown3, 0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_num_users(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_num_users, 0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_num_groups(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_num_groups, 0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation_num_aliases(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation_num_aliases, 0);
return offset;
}
int
samr_dissect_struct_DomGeneralInformation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomGeneralInformation);
}
offset = samr_dissect_element_DomGeneralInformation_force_logoff_time(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_oem_information(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_domain_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_primary(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_sequence_num(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_domain_server_state(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_role(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_unknown3(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_num_users(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_num_groups(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation_num_aliases(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo3_force_logoff_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo3_force_logoff_time);
return offset;
}
int
samr_dissect_struct_DomInfo3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo3);
}
offset = samr_dissect_element_DomInfo3_force_logoff_time(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomOEMInformation_oem_information(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomOEMInformation_oem_information);
return offset;
}
int
samr_dissect_struct_DomOEMInformation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomOEMInformation);
}
offset = samr_dissect_element_DomOEMInformation_oem_information(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo5_domain_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo5_domain_name);
return offset;
}
int
samr_dissect_struct_DomInfo5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo5);
}
offset = samr_dissect_element_DomInfo5_domain_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo6_primary(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo6_primary);
return offset;
}
int
samr_dissect_struct_DomInfo6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo6);
}
offset = samr_dissect_element_DomInfo6_primary(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo7_role(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_Role(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo7_role, 0);
return offset;
}
int
samr_dissect_struct_DomInfo7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo7);
}
offset = samr_dissect_element_DomInfo7_role(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo8_sequence_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo8_sequence_num);
return offset;
}
static int
samr_dissect_element_DomInfo8_domain_create_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo8_domain_create_time);
return offset;
}
int
samr_dissect_struct_DomInfo8(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo8);
}
offset = samr_dissect_element_DomInfo8_sequence_num(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo8_domain_create_time(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo9_domain_server_state(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainServerState(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo9_domain_server_state, 0);
return offset;
}
int
samr_dissect_struct_DomInfo9(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo9);
}
offset = samr_dissect_element_DomInfo9_domain_server_state(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomGeneralInformation2_general(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomGeneralInformation(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomGeneralInformation2_general,0);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation2_lockout_duration(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomGeneralInformation2_lockout_duration);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation2_lockout_window(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomGeneralInformation2_lockout_window);
return offset;
}
static int
samr_dissect_element_DomGeneralInformation2_lockout_threshold(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomGeneralInformation2_lockout_threshold, 0);
return offset;
}
int
samr_dissect_struct_DomGeneralInformation2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomGeneralInformation2);
}
offset = samr_dissect_element_DomGeneralInformation2_general(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation2_lockout_duration(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation2_lockout_window(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomGeneralInformation2_lockout_threshold(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo12_lockout_duration(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo12_lockout_duration);
return offset;
}
static int
samr_dissect_element_DomInfo12_lockout_window(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo12_lockout_window);
return offset;
}
static int
samr_dissect_element_DomInfo12_lockout_threshold(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo12_lockout_threshold, 0);
return offset;
}
int
samr_dissect_struct_DomInfo12(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo12);
}
offset = samr_dissect_element_DomInfo12_lockout_duration(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo12_lockout_window(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo12_lockout_threshold(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomInfo13_sequence_num(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo13_sequence_num);
return offset;
}
static int
samr_dissect_element_DomInfo13_domain_create_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_DomInfo13_domain_create_time);
return offset;
}
static int
samr_dissect_element_DomInfo13_modified_count_at_last_promotion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_hyper(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DomInfo13_modified_count_at_last_promotion);
return offset;
}
int
samr_dissect_struct_DomInfo13(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DomInfo13);
}
offset = samr_dissect_element_DomInfo13_sequence_num(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo13_domain_create_time(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DomInfo13_modified_count_at_last_promotion(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_DomainInfo_info1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo1(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info1,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_general(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomGeneralInformation(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_general,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo3(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info3,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_oem(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomOEMInformation(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_oem,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo5(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info5,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo6(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info6,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo7(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info7,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info8(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo8(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info8,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info9(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo9(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info9,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_general2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomGeneralInformation2(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_general2,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info12(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo12(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info12,0);
return offset;
}
static int
samr_dissect_element_DomainInfo_info13(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo13(tvb,offset,pinfo,tree,drep,hf_samr_samr_DomainInfo_info13,0);
return offset;
}
static int
samr_dissect_DomainInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_DomainInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_DomainInfo);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_8_BYTES;
switch(level) {
case 1:
offset = samr_dissect_element_DomainInfo_info1(tvb, offset, pinfo, tree, drep);
break;
case 2:
offset = samr_dissect_element_DomainInfo_general(tvb, offset, pinfo, tree, drep);
break;
case 3:
offset = samr_dissect_element_DomainInfo_info3(tvb, offset, pinfo, tree, drep);
break;
case 4:
offset = samr_dissect_element_DomainInfo_oem(tvb, offset, pinfo, tree, drep);
break;
case 5:
offset = samr_dissect_element_DomainInfo_info5(tvb, offset, pinfo, tree, drep);
break;
case 6:
offset = samr_dissect_element_DomainInfo_info6(tvb, offset, pinfo, tree, drep);
break;
case 7:
offset = samr_dissect_element_DomainInfo_info7(tvb, offset, pinfo, tree, drep);
break;
case 8:
offset = samr_dissect_element_DomainInfo_info8(tvb, offset, pinfo, tree, drep);
break;
case 9:
offset = samr_dissect_element_DomainInfo_info9(tvb, offset, pinfo, tree, drep);
break;
case 11:
offset = samr_dissect_element_DomainInfo_general2(tvb, offset, pinfo, tree, drep);
break;
case 12:
offset = samr_dissect_element_DomainInfo_info12(tvb, offset, pinfo, tree, drep);
break;
case 13:
offset = samr_dissect_element_DomainInfo_info13(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_Ids_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_Ids_count, 0);
return offset;
}
static int
samr_dissect_element_Ids_ids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Ids_ids_, NDR_POINTER_UNIQUE, "Pointer to Ids (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_Ids_ids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_Ids_ids__);
return offset;
}
static int
samr_dissect_element_Ids_ids__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
int
samr_dissect_struct_Ids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_Ids);
}
offset = samr_dissect_element_Ids_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_Ids_ids(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_bitmap_GroupAttrs(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_samr_samr_GroupAttrs);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_MANDATORY, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "SE_GROUP_MANDATORY");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_ENABLED_BY_DEFAULT, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "SE_GROUP_ENABLED_BY_DEFAULT");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_ENABLED, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "SE_GROUP_ENABLED");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_OWNER, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "SE_GROUP_OWNER");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_USE_FOR_DENY_ONLY, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "SE_GROUP_USE_FOR_DENY_ONLY");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_RESOURCE, tvb, offset-4, 4, flags);
if (flags&( 0x20000000 )){
proto_item_append_text(item, "SE_GROUP_RESOURCE");
if (flags & (~( 0x20000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x20000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_GroupAttrs_SE_GROUP_LOGON_ID, tvb, offset-4, 4, flags);
if (flags&( 0xC0000000 )){
proto_item_append_text(item, "SE_GROUP_LOGON_ID");
if (flags & (~( 0xC0000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0xC0000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
samr_dissect_element_GroupInfoAll_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GroupInfoAll_name);
return offset;
}
static int
samr_dissect_element_GroupInfoAll_attributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAttrs(tvb, offset, pinfo, tree, drep, hf_samr_samr_GroupInfoAll_attributes, 0);
return offset;
}
static int
samr_dissect_element_GroupInfoAll_num_members(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_GroupInfoAll_num_members, 0);
return offset;
}
static int
samr_dissect_element_GroupInfoAll_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GroupInfoAll_description);
return offset;
}
int
samr_dissect_struct_GroupInfoAll(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_GroupInfoAll);
}
offset = samr_dissect_element_GroupInfoAll_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_GroupInfoAll_attributes(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_GroupInfoAll_num_members(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_GroupInfoAll_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_GroupInfoAttributes_attributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAttrs(tvb, offset, pinfo, tree, drep, hf_samr_samr_GroupInfoAttributes_attributes, 0);
return offset;
}
int
samr_dissect_struct_GroupInfoAttributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_GroupInfoAttributes);
}
offset = samr_dissect_element_GroupInfoAttributes_attributes(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_GroupInfoDescription_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GroupInfoDescription_description);
return offset;
}
int
samr_dissect_struct_GroupInfoDescription(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_GroupInfoDescription);
}
offset = samr_dissect_element_GroupInfoDescription_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_enum_GroupInfoEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
samr_dissect_element_GroupInfo_all(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_GroupInfoAll(tvb,offset,pinfo,tree,drep,hf_samr_samr_GroupInfo_all,0);
return offset;
}
static int
samr_dissect_element_GroupInfo_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GroupInfo_name);
return offset;
}
static int
samr_dissect_element_GroupInfo_attributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_GroupInfoAttributes(tvb,offset,pinfo,tree,drep,hf_samr_samr_GroupInfo_attributes,0);
return offset;
}
static int
samr_dissect_element_GroupInfo_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GroupInfo_description);
return offset;
}
static int
samr_dissect_element_GroupInfo_all2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_GroupInfoAll(tvb,offset,pinfo,tree,drep,hf_samr_samr_GroupInfo_all2,0);
return offset;
}
static int
samr_dissect_GroupInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint1632 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_GroupInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_GroupInfo);
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case GROUPINFOALL:
offset = samr_dissect_element_GroupInfo_all(tvb, offset, pinfo, tree, drep);
break;
case GROUPINFONAME:
offset = samr_dissect_element_GroupInfo_name(tvb, offset, pinfo, tree, drep);
break;
case GROUPINFOATTRIBUTES:
offset = samr_dissect_element_GroupInfo_attributes(tvb, offset, pinfo, tree, drep);
break;
case GROUPINFODESCRIPTION:
offset = samr_dissect_element_GroupInfo_description(tvb, offset, pinfo, tree, drep);
break;
case GROUPINFOALL2:
offset = samr_dissect_element_GroupInfo_all2(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_RidTypeArray_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_RidTypeArray_count, 0);
return offset;
}
static int
samr_dissect_element_RidTypeArray_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidTypeArray_rids_, NDR_POINTER_UNIQUE, "Pointer to Rids (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_RidTypeArray_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidTypeArray_rids__);
return offset;
}
static int
samr_dissect_element_RidTypeArray_rids__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_RidTypeArray_types(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidTypeArray_types_, NDR_POINTER_UNIQUE, "Pointer to Types (uint32)",hf_samr_samr_RidTypeArray_types);
return offset;
}
static int
samr_dissect_element_RidTypeArray_types_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidTypeArray_types__);
return offset;
}
static int
samr_dissect_element_RidTypeArray_types__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_RidTypeArray_types, 0);
return offset;
}
int
samr_dissect_struct_RidTypeArray(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_RidTypeArray);
}
offset = samr_dissect_element_RidTypeArray_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_RidTypeArray_rids(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_RidTypeArray_types(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_AliasInfoAll_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_AliasInfoAll_name);
return offset;
}
static int
samr_dissect_element_AliasInfoAll_num_members(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_AliasInfoAll_num_members, 0);
return offset;
}
static int
samr_dissect_element_AliasInfoAll_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_AliasInfoAll_description);
return offset;
}
int
samr_dissect_struct_AliasInfoAll(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_AliasInfoAll);
}
offset = samr_dissect_element_AliasInfoAll_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_AliasInfoAll_num_members(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_AliasInfoAll_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_enum_AliasInfoEnum(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
samr_dissect_element_AliasInfo_all(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_AliasInfoAll(tvb,offset,pinfo,tree,drep,hf_samr_samr_AliasInfo_all,0);
return offset;
}
static int
samr_dissect_element_AliasInfo_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_AliasInfo_name);
return offset;
}
static int
samr_dissect_element_AliasInfo_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_AliasInfo_description);
return offset;
}
static int
samr_dissect_AliasInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint1632 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_AliasInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_AliasInfo);
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case ALIASINFOALL:
offset = samr_dissect_element_AliasInfo_all(tvb, offset, pinfo, tree, drep);
break;
case ALIASINFONAME:
offset = samr_dissect_element_AliasInfo_name(tvb, offset, pinfo, tree, drep);
break;
case ALIASINFODESCRIPTION:
offset = samr_dissect_element_AliasInfo_description(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
samr_dissect_enum_UserInfoLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
samr_dissect_element_UserInfo1_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo1_account_name);
return offset;
}
static int
samr_dissect_element_UserInfo1_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo1_full_name);
return offset;
}
static int
samr_dissect_element_UserInfo1_primary_gid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo1_primary_gid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo1_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo1_description);
return offset;
}
static int
samr_dissect_element_UserInfo1_comment(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo1_comment);
return offset;
}
int
samr_dissect_struct_UserInfo1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo1);
}
offset = samr_dissect_element_UserInfo1_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo1_full_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo1_primary_gid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo1_description(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo1_comment(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo2_comment(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo2_comment);
return offset;
}
static int
samr_dissect_element_UserInfo2_unknown(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo2_unknown);
return offset;
}
static int
samr_dissect_element_UserInfo2_country_code(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo2_country_code, 0);
return offset;
}
static int
samr_dissect_element_UserInfo2_code_page(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo2_code_page, 0);
return offset;
}
int
samr_dissect_struct_UserInfo2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo2);
}
offset = samr_dissect_element_UserInfo2_comment(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo2_unknown(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo2_country_code(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo2_code_page(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_LogonHours_units_per_week(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_LogonHours_units_per_week, 0);
return offset;
}
static int
samr_dissect_element_LogonHours_bits(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LogonHours_bits_, NDR_POINTER_UNIQUE, "Pointer to Bits (uint8)",hf_samr_samr_LogonHours_bits);
return offset;
}
static int
samr_dissect_element_LogonHours_bits_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_LogonHours_bits__);
return offset;
}
static int
samr_dissect_element_LogonHours_bits__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_LogonHours_bits, 0);
return offset;
}
int
samr_dissect_struct_LogonHours(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_LogonHours);
}
offset = samr_dissect_element_LogonHours_units_per_week(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_LogonHours_bits(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo3_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_account_name);
return offset;
}
static int
samr_dissect_element_UserInfo3_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_full_name);
return offset;
}
static int
samr_dissect_element_UserInfo3_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo3_primary_gid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_primary_gid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo3_home_directory(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_home_directory);
return offset;
}
static int
samr_dissect_element_UserInfo3_home_drive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_home_drive);
return offset;
}
static int
samr_dissect_element_UserInfo3_logon_script(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_logon_script);
return offset;
}
static int
samr_dissect_element_UserInfo3_profile_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_profile_path);
return offset;
}
static int
samr_dissect_element_UserInfo3_workstations(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo3_workstations);
return offset;
}
static int
samr_dissect_element_UserInfo3_last_logon(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_last_logon);
return offset;
}
static int
samr_dissect_element_UserInfo3_last_logoff(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_last_logoff);
return offset;
}
static int
samr_dissect_element_UserInfo3_last_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_last_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo3_allow_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_allow_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo3_force_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_force_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo3_logon_hours(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_LogonHours(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo3_logon_hours,0);
return offset;
}
static int
samr_dissect_element_UserInfo3_bad_password_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_bad_password_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo3_logon_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_logon_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo3_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo3_acct_flags, 0);
return offset;
}
int
samr_dissect_struct_UserInfo3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo3);
}
offset = samr_dissect_element_UserInfo3_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_full_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_primary_gid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_home_directory(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_home_drive(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_logon_script(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_profile_path(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_workstations(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_last_logon(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_last_logoff(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_last_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_allow_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_force_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_logon_hours(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_bad_password_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_logon_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo3_acct_flags(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo4_logon_hours(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_LogonHours(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo4_logon_hours,0);
return offset;
}
int
samr_dissect_struct_UserInfo4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo4);
}
offset = samr_dissect_element_UserInfo4_logon_hours(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo5_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_account_name);
return offset;
}
static int
samr_dissect_element_UserInfo5_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_full_name);
return offset;
}
static int
samr_dissect_element_UserInfo5_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo5_primary_gid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_primary_gid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo5_home_directory(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_home_directory);
return offset;
}
static int
samr_dissect_element_UserInfo5_home_drive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_home_drive);
return offset;
}
static int
samr_dissect_element_UserInfo5_logon_script(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_logon_script);
return offset;
}
static int
samr_dissect_element_UserInfo5_profile_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_profile_path);
return offset;
}
static int
samr_dissect_element_UserInfo5_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_description);
return offset;
}
static int
samr_dissect_element_UserInfo5_workstations(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo5_workstations);
return offset;
}
static int
samr_dissect_element_UserInfo5_last_logon(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_last_logon);
return offset;
}
static int
samr_dissect_element_UserInfo5_last_logoff(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_last_logoff);
return offset;
}
static int
samr_dissect_element_UserInfo5_logon_hours(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_LogonHours(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo5_logon_hours,0);
return offset;
}
static int
samr_dissect_element_UserInfo5_bad_password_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_bad_password_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo5_logon_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_logon_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo5_last_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_last_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo5_acct_expiry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_acct_expiry);
return offset;
}
static int
samr_dissect_element_UserInfo5_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo5_acct_flags, 0);
return offset;
}
int
samr_dissect_struct_UserInfo5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo5);
}
offset = samr_dissect_element_UserInfo5_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_full_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_primary_gid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_home_directory(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_home_drive(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_logon_script(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_profile_path(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_description(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_workstations(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_last_logon(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_last_logoff(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_logon_hours(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_bad_password_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_logon_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_last_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_acct_expiry(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo5_acct_flags(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo6_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo6_account_name);
return offset;
}
static int
samr_dissect_element_UserInfo6_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo6_full_name);
return offset;
}
int
samr_dissect_struct_UserInfo6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo6);
}
offset = samr_dissect_element_UserInfo6_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo6_full_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo7_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo7_account_name);
return offset;
}
int
samr_dissect_struct_UserInfo7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo7);
}
offset = samr_dissect_element_UserInfo7_account_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo8_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo8_full_name);
return offset;
}
int
samr_dissect_struct_UserInfo8(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo8);
}
offset = samr_dissect_element_UserInfo8_full_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo9_primary_gid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo9_primary_gid, 0);
return offset;
}
int
samr_dissect_struct_UserInfo9(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo9);
}
offset = samr_dissect_element_UserInfo9_primary_gid(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo10_home_directory(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo10_home_directory);
return offset;
}
static int
samr_dissect_element_UserInfo10_home_drive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo10_home_drive);
return offset;
}
int
samr_dissect_struct_UserInfo10(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo10);
}
offset = samr_dissect_element_UserInfo10_home_directory(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo10_home_drive(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo11_logon_script(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo11_logon_script);
return offset;
}
int
samr_dissect_struct_UserInfo11(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo11);
}
offset = samr_dissect_element_UserInfo11_logon_script(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo12_profile_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo12_profile_path);
return offset;
}
int
samr_dissect_struct_UserInfo12(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo12);
}
offset = samr_dissect_element_UserInfo12_profile_path(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo13_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo13_description);
return offset;
}
int
samr_dissect_struct_UserInfo13(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo13);
}
offset = samr_dissect_element_UserInfo13_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo14_workstations(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo14_workstations);
return offset;
}
int
samr_dissect_struct_UserInfo14(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo14);
}
offset = samr_dissect_element_UserInfo14_workstations(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo16_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo16_acct_flags, 0);
return offset;
}
int
samr_dissect_struct_UserInfo16(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo16);
}
offset = samr_dissect_element_UserInfo16_acct_flags(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo17_acct_expiry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo17_acct_expiry);
return offset;
}
int
samr_dissect_struct_UserInfo17(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo17);
}
offset = samr_dissect_element_UserInfo17_acct_expiry(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_Password_hash(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 16; i++)
offset = samr_dissect_element_Password_hash_(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_Password_hash_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_Password_hash, 0);
return offset;
}
int
samr_dissect_struct_Password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_Password);
}
offset = samr_dissect_element_Password_hash(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_UserInfo18_nt_pwd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo18_nt_pwd,0);
return offset;
}
static int
samr_dissect_element_UserInfo18_lm_pwd(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo18_lm_pwd,0);
return offset;
}
static int
samr_dissect_element_UserInfo18_nt_pwd_active(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo18_nt_pwd_active, 0);
return offset;
}
static int
samr_dissect_element_UserInfo18_lm_pwd_active(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo18_lm_pwd_active, 0);
return offset;
}
static int
samr_dissect_element_UserInfo18_password_expired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo18_password_expired, 0);
return offset;
}
int
samr_dissect_struct_UserInfo18(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo18);
}
offset = samr_dissect_element_UserInfo18_nt_pwd(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo18_lm_pwd(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo18_nt_pwd_active(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo18_lm_pwd_active(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo18_password_expired(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_UserInfo20_parameters(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo20_parameters);
return offset;
}
int
samr_dissect_struct_UserInfo20(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo20);
}
offset = samr_dissect_element_UserInfo20_parameters(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_bitmap_FieldsPresent(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_samr_samr_FieldsPresent);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCOUNT_NAME, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "SAMR_FIELD_ACCOUNT_NAME");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_FULL_NAME, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "SAMR_FIELD_FULL_NAME");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_RID, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "SAMR_FIELD_RID");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_PRIMARY_GID, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "SAMR_FIELD_PRIMARY_GID");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_DESCRIPTION, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "SAMR_FIELD_DESCRIPTION");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_COMMENT, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "SAMR_FIELD_COMMENT");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_HOME_DIRECTORY, tvb, offset-4, 4, flags);
if (flags&( 0x00000040 )){
proto_item_append_text(item, "SAMR_FIELD_HOME_DIRECTORY");
if (flags & (~( 0x00000040 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000040 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_HOME_DRIVE, tvb, offset-4, 4, flags);
if (flags&( 0x00000080 )){
proto_item_append_text(item, "SAMR_FIELD_HOME_DRIVE");
if (flags & (~( 0x00000080 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000080 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LOGON_SCRIPT, tvb, offset-4, 4, flags);
if (flags&( 0x00000100 )){
proto_item_append_text(item, "SAMR_FIELD_LOGON_SCRIPT");
if (flags & (~( 0x00000100 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000100 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_PROFILE_PATH, tvb, offset-4, 4, flags);
if (flags&( 0x00000200 )){
proto_item_append_text(item, "SAMR_FIELD_PROFILE_PATH");
if (flags & (~( 0x00000200 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000200 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_WORKSTATIONS, tvb, offset-4, 4, flags);
if (flags&( 0x00000400 )){
proto_item_append_text(item, "SAMR_FIELD_WORKSTATIONS");
if (flags & (~( 0x00000400 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000400 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_LOGON, tvb, offset-4, 4, flags);
if (flags&( 0x00000800 )){
proto_item_append_text(item, "SAMR_FIELD_LAST_LOGON");
if (flags & (~( 0x00000800 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000800 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_LOGOFF, tvb, offset-4, 4, flags);
if (flags&( 0x00001000 )){
proto_item_append_text(item, "SAMR_FIELD_LAST_LOGOFF");
if (flags & (~( 0x00001000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00001000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LOGON_HOURS, tvb, offset-4, 4, flags);
if (flags&( 0x00002000 )){
proto_item_append_text(item, "SAMR_FIELD_LOGON_HOURS");
if (flags & (~( 0x00002000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00002000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_BAD_PWD_COUNT, tvb, offset-4, 4, flags);
if (flags&( 0x00004000 )){
proto_item_append_text(item, "SAMR_FIELD_BAD_PWD_COUNT");
if (flags & (~( 0x00004000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00004000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_NUM_LOGONS, tvb, offset-4, 4, flags);
if (flags&( 0x00008000 )){
proto_item_append_text(item, "SAMR_FIELD_NUM_LOGONS");
if (flags & (~( 0x00008000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00008000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_ALLOW_PWD_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00010000 )){
proto_item_append_text(item, "SAMR_FIELD_ALLOW_PWD_CHANGE");
if (flags & (~( 0x00010000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00010000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_FORCE_PWD_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00020000 )){
proto_item_append_text(item, "SAMR_FIELD_FORCE_PWD_CHANGE");
if (flags & (~( 0x00020000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00020000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_PWD_CHANGE, tvb, offset-4, 4, flags);
if (flags&( 0x00040000 )){
proto_item_append_text(item, "SAMR_FIELD_LAST_PWD_CHANGE");
if (flags & (~( 0x00040000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00040000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCT_EXPIRY, tvb, offset-4, 4, flags);
if (flags&( 0x00080000 )){
proto_item_append_text(item, "SAMR_FIELD_ACCT_EXPIRY");
if (flags & (~( 0x00080000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00080000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCT_FLAGS, tvb, offset-4, 4, flags);
if (flags&( 0x00100000 )){
proto_item_append_text(item, "SAMR_FIELD_ACCT_FLAGS");
if (flags & (~( 0x00100000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00100000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_PARAMETERS, tvb, offset-4, 4, flags);
if (flags&( 0x00200000 )){
proto_item_append_text(item, "SAMR_FIELD_PARAMETERS");
if (flags & (~( 0x00200000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00200000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_COUNTRY_CODE, tvb, offset-4, 4, flags);
if (flags&( 0x00400000 )){
proto_item_append_text(item, "SAMR_FIELD_COUNTRY_CODE");
if (flags & (~( 0x00400000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00400000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_CODE_PAGE, tvb, offset-4, 4, flags);
if (flags&( 0x00800000 )){
proto_item_append_text(item, "SAMR_FIELD_CODE_PAGE");
if (flags & (~( 0x00800000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00800000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_NT_PASSWORD_PRESENT, tvb, offset-4, 4, flags);
if (flags&( 0x01000000 )){
proto_item_append_text(item, "SAMR_FIELD_NT_PASSWORD_PRESENT");
if (flags & (~( 0x01000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x01000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_LM_PASSWORD_PRESENT, tvb, offset-4, 4, flags);
if (flags&( 0x02000000 )){
proto_item_append_text(item, "SAMR_FIELD_LM_PASSWORD_PRESENT");
if (flags & (~( 0x02000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x02000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_PRIVATE_DATA, tvb, offset-4, 4, flags);
if (flags&( 0x04000000 )){
proto_item_append_text(item, "SAMR_FIELD_PRIVATE_DATA");
if (flags & (~( 0x04000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x04000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_EXPIRED_FLAG, tvb, offset-4, 4, flags);
if (flags&( 0x08000000 )){
proto_item_append_text(item, "SAMR_FIELD_EXPIRED_FLAG");
if (flags & (~( 0x08000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x08000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_SEC_DESC, tvb, offset-4, 4, flags);
if (flags&( 0x10000000 )){
proto_item_append_text(item, "SAMR_FIELD_SEC_DESC");
if (flags & (~( 0x10000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x10000000 ));
proto_tree_add_boolean(tree, hf_samr_samr_FieldsPresent_SAMR_FIELD_OWF_PWD, tvb, offset-4, 4, flags);
if (flags&( 0x20000000 )){
proto_item_append_text(item, "SAMR_FIELD_OWF_PWD");
if (flags & (~( 0x20000000 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x20000000 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
static int
samr_dissect_element_UserInfo21_last_logon(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_last_logon);
return offset;
}
static int
samr_dissect_element_UserInfo21_last_logoff(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_last_logoff);
return offset;
}
static int
samr_dissect_element_UserInfo21_last_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_last_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo21_acct_expiry(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_acct_expiry);
return offset;
}
static int
samr_dissect_element_UserInfo21_allow_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_allow_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo21_force_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_force_password_change);
return offset;
}
static int
samr_dissect_element_UserInfo21_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_account_name);
return offset;
}
static int
samr_dissect_element_UserInfo21_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_full_name);
return offset;
}
static int
samr_dissect_element_UserInfo21_home_directory(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_home_directory);
return offset;
}
static int
samr_dissect_element_UserInfo21_home_drive(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_home_drive);
return offset;
}
static int
samr_dissect_element_UserInfo21_logon_script(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_logon_script);
return offset;
}
static int
samr_dissect_element_UserInfo21_profile_path(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_profile_path);
return offset;
}
static int
samr_dissect_element_UserInfo21_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_description);
return offset;
}
static int
samr_dissect_element_UserInfo21_workstations(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_workstations);
return offset;
}
static int
samr_dissect_element_UserInfo21_comment(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_comment);
return offset;
}
static int
samr_dissect_element_UserInfo21_parameters(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_parameters);
return offset;
}
static int
samr_dissect_element_UserInfo21_lm_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_lm_password);
return offset;
}
static int
samr_dissect_element_UserInfo21_nt_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_nt_password);
return offset;
}
static int
samr_dissect_element_UserInfo21_private(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_UserInfo21_private);
return offset;
}
static int
samr_dissect_element_UserInfo21_buf_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_buf_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_buffer(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_UserInfo21_buffer_, NDR_POINTER_UNIQUE, "Pointer to Buffer (uint8)",hf_samr_samr_UserInfo21_buffer);
return offset;
}
static int
samr_dissect_element_UserInfo21_buffer_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_UserInfo21_buffer__);
return offset;
}
static int
samr_dissect_element_UserInfo21_buffer__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_buffer, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_primary_gid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_primary_gid, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_fields_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_FieldsPresent(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_fields_present, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_logon_hours(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_LogonHours(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo21_logon_hours,0);
return offset;
}
static int
samr_dissect_element_UserInfo21_bad_password_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_bad_password_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_logon_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_logon_count, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_country_code(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_country_code, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_code_page(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_code_page, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_lm_password_set(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_lm_password_set, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_nt_password_set(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_nt_password_set, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_password_expired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_password_expired, 0);
return offset;
}
static int
samr_dissect_element_UserInfo21_unknown4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo21_unknown4, 0);
return offset;
}
int
samr_dissect_struct_UserInfo21(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo21);
}
offset = samr_dissect_element_UserInfo21_last_logon(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_last_logoff(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_last_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_acct_expiry(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_allow_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_force_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_full_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_home_directory(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_home_drive(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_logon_script(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_profile_path(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_description(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_workstations(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_comment(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_parameters(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_lm_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_nt_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_private(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_buf_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_buffer(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_primary_gid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_acct_flags(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_fields_present(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_logon_hours(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_bad_password_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_logon_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_country_code(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_code_page(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_lm_password_set(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_nt_password_set(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_password_expired(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo21_unknown4(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_CryptPassword_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 516; i++)
offset = samr_dissect_element_CryptPassword_data_(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_CryptPassword_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_CryptPassword_data, 0);
return offset;
}
int
samr_dissect_struct_CryptPassword(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_CryptPassword);
}
offset = samr_dissect_element_CryptPassword_data(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_UserInfo23_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo21(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo23_info,0);
return offset;
}
static int
samr_dissect_element_UserInfo23_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo23_password,0);
return offset;
}
int
samr_dissect_struct_UserInfo23(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo23);
}
offset = samr_dissect_element_UserInfo23_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo23_password(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo24_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo24_password,0);
return offset;
}
static int
samr_dissect_element_UserInfo24_password_expired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo24_password_expired, 0);
return offset;
}
int
samr_dissect_struct_UserInfo24(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo24);
}
offset = samr_dissect_element_UserInfo24_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo24_password_expired(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_CryptPasswordEx_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
int i;
for (i = 0; i < 532; i++)
offset = samr_dissect_element_CryptPasswordEx_data_(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_CryptPasswordEx_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_CryptPasswordEx_data, 0);
return offset;
}
int
samr_dissect_struct_CryptPasswordEx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_CryptPasswordEx);
}
offset = samr_dissect_element_CryptPasswordEx_data(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_UserInfo25_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo21(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo25_info,0);
return offset;
}
static int
samr_dissect_element_UserInfo25_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPasswordEx(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo25_password,0);
return offset;
}
int
samr_dissect_struct_UserInfo25(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo25);
}
offset = samr_dissect_element_UserInfo25_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo25_password(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_UserInfo26_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPasswordEx(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo26_password,0);
return offset;
}
static int
samr_dissect_element_UserInfo26_password_expired(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_UserInfo26_password_expired, 0);
return offset;
}
int
samr_dissect_struct_UserInfo26(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo26);
}
offset = samr_dissect_element_UserInfo26_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_UserInfo26_password_expired(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_UserInfo_info1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo1(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info1,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo2(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info2,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo3(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info3,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo4(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info4,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo5(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info5,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info6(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo6(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info6,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info7(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo7(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info7,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info8(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo8(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info8,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info9(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo9(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info9,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info10(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo10(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info10,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info11(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo11(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info11,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info12(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo12(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info12,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info13(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo13(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info13,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info14(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo14(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info14,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info16(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo16(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info16,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info17(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo17(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info17,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info18(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo18(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info18,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info20(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo20(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info20,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info21(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo21(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info21,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info23(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo23(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info23,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info24(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo24(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info24,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info25(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo25(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info25,0);
return offset;
}
static int
samr_dissect_element_UserInfo_info26(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_UserInfo26(tvb,offset,pinfo,tree,drep,hf_samr_samr_UserInfo_info26,0);
return offset;
}
static int
samr_dissect_UserInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_UserInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_UserInfo);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case 1:
offset = samr_dissect_element_UserInfo_info1(tvb, offset, pinfo, tree, drep);
break;
case 2:
offset = samr_dissect_element_UserInfo_info2(tvb, offset, pinfo, tree, drep);
break;
case 3:
offset = samr_dissect_element_UserInfo_info3(tvb, offset, pinfo, tree, drep);
break;
case 4:
offset = samr_dissect_element_UserInfo_info4(tvb, offset, pinfo, tree, drep);
break;
case 5:
offset = samr_dissect_element_UserInfo_info5(tvb, offset, pinfo, tree, drep);
break;
case 6:
offset = samr_dissect_element_UserInfo_info6(tvb, offset, pinfo, tree, drep);
break;
case 7:
offset = samr_dissect_element_UserInfo_info7(tvb, offset, pinfo, tree, drep);
break;
case 8:
offset = samr_dissect_element_UserInfo_info8(tvb, offset, pinfo, tree, drep);
break;
case 9:
offset = samr_dissect_element_UserInfo_info9(tvb, offset, pinfo, tree, drep);
break;
case 10:
offset = samr_dissect_element_UserInfo_info10(tvb, offset, pinfo, tree, drep);
break;
case 11:
offset = samr_dissect_element_UserInfo_info11(tvb, offset, pinfo, tree, drep);
break;
case 12:
offset = samr_dissect_element_UserInfo_info12(tvb, offset, pinfo, tree, drep);
break;
case 13:
offset = samr_dissect_element_UserInfo_info13(tvb, offset, pinfo, tree, drep);
break;
case 14:
offset = samr_dissect_element_UserInfo_info14(tvb, offset, pinfo, tree, drep);
break;
case 16:
offset = samr_dissect_element_UserInfo_info16(tvb, offset, pinfo, tree, drep);
break;
case 17:
offset = samr_dissect_element_UserInfo_info17(tvb, offset, pinfo, tree, drep);
break;
case 18:
offset = samr_dissect_element_UserInfo_info18(tvb, offset, pinfo, tree, drep);
break;
case 20:
offset = samr_dissect_element_UserInfo_info20(tvb, offset, pinfo, tree, drep);
break;
case 21:
offset = samr_dissect_element_UserInfo_info21(tvb, offset, pinfo, tree, drep);
break;
case 23:
offset = samr_dissect_element_UserInfo_info23(tvb, offset, pinfo, tree, drep);
break;
case 24:
offset = samr_dissect_element_UserInfo_info24(tvb, offset, pinfo, tree, drep);
break;
case 25:
offset = samr_dissect_element_UserInfo_info25(tvb, offset, pinfo, tree, drep);
break;
case 26:
offset = samr_dissect_element_UserInfo_info26(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_RidWithAttribute_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_RidWithAttribute_attributes(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAttrs(tvb, offset, pinfo, tree, drep, hf_samr_samr_RidWithAttribute_attributes, 0);
return offset;
}
int
samr_dissect_struct_RidWithAttribute(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_RidWithAttribute);
}
offset = samr_dissect_element_RidWithAttribute_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_RidWithAttribute_attributes(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_RidWithAttributeArray_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_RidWithAttributeArray_count, 0);
return offset;
}
static int
samr_dissect_element_RidWithAttributeArray_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidWithAttributeArray_rids_, NDR_POINTER_UNIQUE, "Pointer to Rids (samr_RidWithAttribute)",hf_samr_samr_RidWithAttributeArray_rids);
return offset;
}
static int
samr_dissect_element_RidWithAttributeArray_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidWithAttributeArray_rids__);
return offset;
}
static int
samr_dissect_element_RidWithAttributeArray_rids__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_RidWithAttribute(tvb,offset,pinfo,tree,drep,hf_samr_samr_RidWithAttributeArray_rids,0);
return offset;
}
int
samr_dissect_struct_RidWithAttributeArray(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_RidWithAttributeArray);
}
offset = samr_dissect_element_RidWithAttributeArray_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_RidWithAttributeArray_rids(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryGeneral_idx, 0);
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryGeneral_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryGeneral_account_name);
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryGeneral_description);
return offset;
}
static int
samr_dissect_element_DispEntryGeneral_full_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryGeneral_full_name);
return offset;
}
int
samr_dissect_struct_DispEntryGeneral(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispEntryGeneral);
}
offset = samr_dissect_element_DispEntryGeneral_idx(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryGeneral_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryGeneral_acct_flags(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryGeneral_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryGeneral_description(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryGeneral_full_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispInfoGeneral_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispInfoGeneral_count, 0);
return offset;
}
static int
samr_dissect_element_DispInfoGeneral_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoGeneral_entries_, NDR_POINTER_UNIQUE, "Pointer to Entries (samr_DispEntryGeneral)",hf_samr_samr_DispInfoGeneral_entries);
return offset;
}
static int
samr_dissect_element_DispInfoGeneral_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoGeneral_entries__);
return offset;
}
static int
samr_dissect_element_DispInfoGeneral_entries__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispEntryGeneral(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfoGeneral_entries,0);
return offset;
}
int
samr_dissect_struct_DispInfoGeneral(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispInfoGeneral);
}
offset = samr_dissect_element_DispInfoGeneral_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispInfoGeneral_entries(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispEntryFull_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryFull_idx, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFull_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFull_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryFull_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFull_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryFull_account_name);
return offset;
}
static int
samr_dissect_element_DispEntryFull_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryFull_description);
return offset;
}
int
samr_dissect_struct_DispEntryFull(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispEntryFull);
}
offset = samr_dissect_element_DispEntryFull_idx(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFull_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFull_acct_flags(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFull_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFull_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispInfoFull_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispInfoFull_count, 0);
return offset;
}
static int
samr_dissect_element_DispInfoFull_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoFull_entries_, NDR_POINTER_UNIQUE, "Pointer to Entries (samr_DispEntryFull)",hf_samr_samr_DispInfoFull_entries);
return offset;
}
static int
samr_dissect_element_DispInfoFull_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoFull_entries__);
return offset;
}
static int
samr_dissect_element_DispInfoFull_entries__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispEntryFull(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfoFull_entries,0);
return offset;
}
int
samr_dissect_struct_DispInfoFull(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispInfoFull);
}
offset = samr_dissect_element_DispInfoFull_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispInfoFull_entries(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispEntryFullGroup_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryFullGroup_idx, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFullGroup_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFullGroup_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAttrs(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryFullGroup_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_DispEntryFullGroup_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryFullGroup_account_name);
return offset;
}
static int
samr_dissect_element_DispEntryFullGroup_description(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryFullGroup_description);
return offset;
}
int
samr_dissect_struct_DispEntryFullGroup(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispEntryFullGroup);
}
offset = samr_dissect_element_DispEntryFullGroup_idx(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFullGroup_rid(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFullGroup_acct_flags(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFullGroup_account_name(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryFullGroup_description(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispInfoFullGroups_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispInfoFullGroups_count, 0);
return offset;
}
static int
samr_dissect_element_DispInfoFullGroups_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoFullGroups_entries_, NDR_POINTER_UNIQUE, "Pointer to Entries (samr_DispEntryFullGroup)",hf_samr_samr_DispInfoFullGroups_entries);
return offset;
}
static int
samr_dissect_element_DispInfoFullGroups_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoFullGroups_entries__);
return offset;
}
static int
samr_dissect_element_DispInfoFullGroups_entries__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispEntryFullGroup(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfoFullGroups_entries,0);
return offset;
}
int
samr_dissect_struct_DispInfoFullGroups(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispInfoFullGroups);
}
offset = samr_dissect_element_DispInfoFullGroups_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispInfoFullGroups_entries(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispEntryAscii_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispEntryAscii_idx, 0);
return offset;
}
static int
samr_dissect_element_DispEntryAscii_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_AsciiString(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_DispEntryAscii_account_name);
return offset;
}
int
samr_dissect_struct_DispEntryAscii(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispEntryAscii);
}
offset = samr_dissect_element_DispEntryAscii_idx(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispEntryAscii_account_name(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_DispInfoAscii_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_DispInfoAscii_count, 0);
return offset;
}
static int
samr_dissect_element_DispInfoAscii_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoAscii_entries_, NDR_POINTER_UNIQUE, "Pointer to Entries (samr_DispEntryAscii)",hf_samr_samr_DispInfoAscii_entries);
return offset;
}
static int
samr_dissect_element_DispInfoAscii_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_DispInfoAscii_entries__);
return offset;
}
static int
samr_dissect_element_DispInfoAscii_entries__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispEntryAscii(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfoAscii_entries,0);
return offset;
}
int
samr_dissect_struct_DispInfoAscii(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_DispInfoAscii);
}
offset = samr_dissect_element_DispInfoAscii_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_DispInfoAscii_entries(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
int
samr_dissect_enum_DomainDisplayInformation(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
samr_dissect_element_DispInfo_info1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispInfoGeneral(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfo_info1,0);
return offset;
}
static int
samr_dissect_element_DispInfo_info2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispInfoFull(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfo_info2,0);
return offset;
}
static int
samr_dissect_element_DispInfo_info3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispInfoFullGroups(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfo_info3,0);
return offset;
}
static int
samr_dissect_element_DispInfo_info4(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispInfoAscii(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfo_info4,0);
return offset;
}
static int
samr_dissect_element_DispInfo_info5(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DispInfoAscii(tvb,offset,pinfo,tree,drep,hf_samr_samr_DispInfo_info5,0);
return offset;
}
static int
samr_dissect_DispInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_DispInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_DispInfo);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_5_BYTES;
switch(level) {
case SAMR_DOMAIN_DISPLAY_USER:
offset = samr_dissect_element_DispInfo_info1(tvb, offset, pinfo, tree, drep);
break;
case SAMR_DOMAIN_DISPLAY_MACHINE:
offset = samr_dissect_element_DispInfo_info2(tvb, offset, pinfo, tree, drep);
break;
case SAMR_DOMAIN_DISPLAY_GROUP:
offset = samr_dissect_element_DispInfo_info3(tvb, offset, pinfo, tree, drep);
break;
case SAMR_DOMAIN_DISPLAY_OEM_USER:
offset = samr_dissect_element_DispInfo_info4(tvb, offset, pinfo, tree, drep);
break;
case SAMR_DOMAIN_DISPLAY_OEM_GROUP:
offset = samr_dissect_element_DispInfo_info5(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_PwInfo_min_password_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_PwInfo_min_password_length, 0);
return offset;
}
static int
samr_dissect_element_PwInfo_password_properties(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_PasswordProperties(tvb, offset, pinfo, tree, drep, hf_samr_samr_PwInfo_password_properties, 0);
return offset;
}
int
samr_dissect_struct_PwInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_PwInfo);
}
offset = samr_dissect_element_PwInfo_min_password_length(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_PwInfo_password_properties(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
int
samr_dissect_enum_ConnectVersion(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
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
samr_dissect_element_ChangeReject_reason(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_RejectReason(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangeReject_reason, 0);
return offset;
}
static int
samr_dissect_element_ChangeReject_unknown1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangeReject_unknown1, 0);
return offset;
}
static int
samr_dissect_element_ChangeReject_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangeReject_unknown2, 0);
return offset;
}
int
samr_dissect_struct_ChangeReject(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ChangeReject);
}
offset = samr_dissect_element_ChangeReject_reason(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ChangeReject_unknown1(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ChangeReject_unknown2(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_ConnectInfo1_client_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_ConnectVersion(tvb, offset, pinfo, tree, drep, hf_samr_samr_ConnectInfo1_client_version, 0);
return offset;
}
static int
samr_dissect_element_ConnectInfo1_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ConnectInfo1_unknown2, 0);
return offset;
}
int
samr_dissect_struct_ConnectInfo1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ConnectInfo1);
}
offset = samr_dissect_element_ConnectInfo1_client_version(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ConnectInfo1_unknown2(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_4_BYTES;
}
return offset;
}
static int
samr_dissect_element_ConnectInfo_info1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ConnectInfo1(tvb,offset,pinfo,tree,drep,hf_samr_samr_ConnectInfo_info1,0);
return offset;
}
static int
samr_dissect_ConnectInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_ConnectInfo");
tree = proto_item_add_subtree(item, ett_samr_samr_ConnectInfo);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_4_BYTES;
switch(level) {
case 1:
offset = samr_dissect_element_ConnectInfo_info1(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
samr_dissect_bitmap_ValidateFieldsPresent(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 flags;
ALIGN_TO_4_BYTES;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 4, TRUE);
tree = proto_item_add_subtree(item,ett_samr_samr_ValidateFieldsPresent);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep, -1, &flags);
proto_item_append_text(item, ": ");
if (!flags)
proto_item_append_text(item, "(No values set)");
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_LAST_SET, tvb, offset-4, 4, flags);
if (flags&( 0x00000001 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_PASSWORD_LAST_SET");
if (flags & (~( 0x00000001 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000001 ));
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_TIME, tvb, offset-4, 4, flags);
if (flags&( 0x00000002 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_BAD_PASSWORD_TIME");
if (flags & (~( 0x00000002 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000002 ));
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_LOCKOUT_TIME, tvb, offset-4, 4, flags);
if (flags&( 0x00000004 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_LOCKOUT_TIME");
if (flags & (~( 0x00000004 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000004 ));
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_COUNT, tvb, offset-4, 4, flags);
if (flags&( 0x00000008 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_BAD_PASSWORD_COUNT");
if (flags & (~( 0x00000008 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000008 ));
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_LENGTH, tvb, offset-4, 4, flags);
if (flags&( 0x00000010 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_LENGTH");
if (flags & (~( 0x00000010 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000010 ));
proto_tree_add_boolean(tree, hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY, tvb, offset-4, 4, flags);
if (flags&( 0x00000020 )){
proto_item_append_text(item, "SAMR_VALIDATE_FIELD_PASSWORD_HISTORY");
if (flags & (~( 0x00000020 )))
proto_item_append_text(item, ", ");
}
flags&=(~( 0x00000020 ));
if (flags) {
proto_item_append_text(item, "Unknown bitmap value 0x%x", flags);
}
return offset;
}
int
samr_dissect_enum_ValidatePasswordLevel(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
int
samr_dissect_enum_ValidationStatus(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 *param _U_)
{
guint1632 parameter=0;
if(param){
parameter=(guint1632)*param;
}
offset = dissect_ndr_uint1632(tvb, offset, pinfo, tree, drep, hf_index, &parameter);
if(param){
*param=(guint32)parameter;
}
return offset;
}
static int
samr_dissect_element_ValidationBlob_length(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidationBlob_length, 0);
return offset;
}
static int
samr_dissect_element_ValidationBlob_data(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidationBlob_data_, NDR_POINTER_UNIQUE, "Pointer to Data (uint8)",hf_samr_samr_ValidationBlob_data);
return offset;
}
static int
samr_dissect_element_ValidationBlob_data_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidationBlob_data__);
return offset;
}
static int
samr_dissect_element_ValidationBlob_data__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidationBlob_data, 0);
return offset;
}
int
samr_dissect_struct_ValidationBlob(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_5_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidationBlob);
}
offset = samr_dissect_element_ValidationBlob_length(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidationBlob_data(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_5_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_fields_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ValidateFieldsPresent(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_fields_present, 0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_last_password_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_last_password_change);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_bad_password_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_bad_password_time);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_lockout_time(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_lockout_time);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_bad_pwd_count(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_bad_pwd_count, 0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_pwd_history_len(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordInfo_pwd_history_len, 0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_pwd_history(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidatePasswordInfo_pwd_history_, NDR_POINTER_UNIQUE, "Pointer to Pwd History (samr_ValidationBlob)",hf_samr_samr_ValidatePasswordInfo_pwd_history);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_pwd_history_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidatePasswordInfo_pwd_history__);
return offset;
}
static int
samr_dissect_element_ValidatePasswordInfo_pwd_history__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidationBlob(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordInfo_pwd_history,0);
return offset;
}
int
samr_dissect_struct_ValidatePasswordInfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordInfo);
}
offset = samr_dissect_element_ValidatePasswordInfo_fields_present(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_last_password_change(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_bad_password_time(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_lockout_time(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_bad_pwd_count(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_pwd_history_len(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordInfo_pwd_history(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordRepCtr_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordRepCtr_info,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordRepCtr_status(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_ValidationStatus(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordRepCtr_status, 0);
return offset;
}
int
samr_dissect_struct_ValidatePasswordRepCtr(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordRepCtr);
}
offset = samr_dissect_element_ValidatePasswordRepCtr_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordRepCtr_status(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordRep_ctr1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordRepCtr(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordRep_ctr1,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordRep_ctr2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordRepCtr(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordRep_ctr2,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordRep_ctr3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordRepCtr(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordRep_ctr3,0);
return offset;
}
static int
samr_dissect_ValidatePasswordRep(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_ValidatePasswordRep");
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordRep);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_8_BYTES;
switch(level) {
case 1:
offset = samr_dissect_element_ValidatePasswordRep_ctr1(tvb, offset, pinfo, tree, drep);
break;
case 2:
offset = samr_dissect_element_ValidatePasswordRep_ctr2(tvb, offset, pinfo, tree, drep);
break;
case 3:
offset = samr_dissect_element_ValidatePasswordRep_ctr3(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq3_info,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ValidatePasswordReq3_password);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ValidatePasswordReq3_account);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_hash(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidationBlob(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq3_hash,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_pwd_must_change_at_next_logon(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordReq3_pwd_must_change_at_next_logon, 0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq3_clear_lockout(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordReq3_clear_lockout, 0);
return offset;
}
int
samr_dissect_struct_ValidatePasswordReq3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordReq3);
}
offset = samr_dissect_element_ValidatePasswordReq3_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq3_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq3_account(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq3_hash(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq3_pwd_must_change_at_next_logon(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq3_clear_lockout(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq2_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq2_info,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq2_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ValidatePasswordReq2_password);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq2_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ValidatePasswordReq2_account);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq2_hash(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidationBlob(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq2_hash,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq2_password_matched(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordReq2_password_matched, 0);
return offset;
}
int
samr_dissect_struct_ValidatePasswordReq2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordReq2);
}
offset = samr_dissect_element_ValidatePasswordReq2_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq2_password(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq2_account(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq2_hash(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq2_password_matched(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq1_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq1_info,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq1_password_matched(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePasswordReq1_password_matched, 0);
return offset;
}
int
samr_dissect_struct_ValidatePasswordReq1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di = pinfo->private_data;
int old_offset;
ALIGN_TO_8_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordReq1);
}
offset = samr_dissect_element_ValidatePasswordReq1_info(tvb, offset, pinfo, tree, drep);
offset = samr_dissect_element_ValidatePasswordReq1_password_matched(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
if (di->call_data->flags & DCERPC_IS_NDR64) {
ALIGN_TO_8_BYTES;
}
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq_req1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordReq1(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq_req1,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq_req2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordReq2(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq_req2,0);
return offset;
}
static int
samr_dissect_element_ValidatePasswordReq_req3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ValidatePasswordReq3(tvb,offset,pinfo,tree,drep,hf_samr_samr_ValidatePasswordReq_req3,0);
return offset;
}
static int
samr_dissect_ValidatePasswordReq(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *parent_tree _U_, guint8 *drep _U_, int hf_index _U_, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint16 level;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "samr_ValidatePasswordReq");
tree = proto_item_add_subtree(item, ett_samr_samr_ValidatePasswordReq);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep, hf_index, &level);
ALIGN_TO_8_BYTES;
switch(level) {
case 1:
offset = samr_dissect_element_ValidatePasswordReq_req1(tvb, offset, pinfo, tree, drep);
break;
case 2:
offset = samr_dissect_element_ValidatePasswordReq_req2(tvb, offset, pinfo, tree, drep);
break;
case 3:
offset = samr_dissect_element_ValidatePasswordReq_req3(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
samr_dissect_element_Connect_system_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect_system_name_, NDR_POINTER_UNIQUE, "Pointer to System Name (uint16)",hf_samr_samr_Connect_system_name);
return offset;
}
static int
samr_dissect_element_Connect_system_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect_system_name, 0);
return offset;
}
static int
samr_dissect_element_Connect_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ConnectAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask, 0);
return offset;
}
static int
samr_dissect_element_Connect_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_Connect_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_CONNECT);
return offset;
}
static int
samr_dissect_Connect_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Connect";
offset = samr_dissect_element_Connect_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Connect_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Connect";
offset = samr_dissect_element_Connect_system_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Close_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Close_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_samr_handle);
return offset;
}
static int
samr_dissect_element_Close_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_handle, PIDL_POLHND_CLOSE);
return offset;
}
static int
samr_dissect_Close_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Close";
offset = samr_dissect_element_Close_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Close_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Close";
offset = samr_dissect_element_Close_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetSecurity_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetSecurity_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_samr_handle);
return offset;
}
static int
samr_dissect_element_SetSecurity_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_handle, 0);
return offset;
}
static int
samr_dissect_element_SetSecurity_sec_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_samr_security_secinfo(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_SetSecurity_sdbuf(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetSecurity_sdbuf_, NDR_POINTER_REF, "Pointer to Sdbuf (sec_desc_buf)",hf_samr_samr_SetSecurity_sdbuf);
return offset;
}
static int
samr_dissect_element_SetSecurity_sdbuf_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_SetSecurity_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetSecurity";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetSecurity_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetSecurity";
offset = samr_dissect_element_SetSecurity_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetSecurity_sec_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetSecurity_sdbuf(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QuerySecurity_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QuerySecurity_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_samr_handle);
return offset;
}
static int
samr_dissect_element_QuerySecurity_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_handle, 0);
return offset;
}
static int
samr_dissect_element_QuerySecurity_sec_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_samr_security_secinfo(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_QuerySecurity_sdbuf(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QuerySecurity_sdbuf_, NDR_POINTER_REF, "Pointer to Sdbuf (sec_desc_buf)",hf_samr_samr_QuerySecurity_sdbuf);
return offset;
}
static int
samr_dissect_element_QuerySecurity_sdbuf_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QuerySecurity_sdbuf__, NDR_POINTER_UNIQUE, "Pointer to Sdbuf (sec_desc_buf)",hf_samr_samr_QuerySecurity_sdbuf);
return offset;
}
static int
samr_dissect_element_QuerySecurity_sdbuf__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_QuerySecurity_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QuerySecurity";
offset = samr_dissect_element_QuerySecurity_sdbuf(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QuerySecurity_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QuerySecurity";
offset = samr_dissect_element_QuerySecurity_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QuerySecurity_sec_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Shutdown_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Shutdown_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_samr_Shutdown_connect_handle);
return offset;
}
static int
samr_dissect_element_Shutdown_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_samr_Shutdown_connect_handle, PIDL_POLHND_CLOSE);
return offset;
}
static int
samr_dissect_Shutdown_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Shutdown";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Shutdown_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Shutdown";
offset = samr_dissect_element_Shutdown_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_LookupDomain_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupDomain_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_LookupDomain_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, 0);
return offset;
}
static int
samr_dissect_element_LookupDomain_domain_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupDomain_domain_name_, NDR_POINTER_REF, "Pointer to Domain Name (lsa_String)",hf_samr_samr_LookupDomain_domain_name);
return offset;
}
static int
samr_dissect_element_LookupDomain_domain_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 3|PIDL_SET_COL_INFO, hf_samr_samr_LookupDomain_domain_name);
return offset;
}
static int
samr_dissect_element_LookupDomain_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupDomain_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_LookupDomain_sid);
return offset;
}
static int
samr_dissect_element_LookupDomain_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupDomain_sid__, NDR_POINTER_UNIQUE, "Pointer to Sid (dom_sid2)",hf_samr_samr_LookupDomain_sid);
return offset;
}
static int
samr_dissect_element_LookupDomain_sid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_LookupDomain_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="LookupDomain";
offset = samr_dissect_element_LookupDomain_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_LookupDomain_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="LookupDomain";
offset = samr_dissect_element_LookupDomain_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupDomain_domain_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_EnumDomains_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomains_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_samr_EnumDomains_connect_handle);
return offset;
}
static int
samr_dissect_element_EnumDomains_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomains_connect_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomains_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomains_resume_handle_, NDR_POINTER_REF, "Pointer to Resume Handle (uint32)",hf_samr_samr_EnumDomains_resume_handle);
return offset;
}
static int
samr_dissect_element_EnumDomains_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomains_resume_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomains_sam(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomains_sam_, NDR_POINTER_REF, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomains_sam);
return offset;
}
static int
samr_dissect_element_EnumDomains_sam_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomains_sam__, NDR_POINTER_UNIQUE, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomains_sam);
return offset;
}
static int
samr_dissect_element_EnumDomains_sam__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_SamArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_EnumDomains_sam,0);
return offset;
}
static int
samr_dissect_element_EnumDomains_buf_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomains_buf_size, 0);
return offset;
}
static int
samr_dissect_element_EnumDomains_num_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomains_num_entries_, NDR_POINTER_REF, "Pointer to Num Entries (uint32)",hf_samr_samr_EnumDomains_num_entries);
return offset;
}
static int
samr_dissect_element_EnumDomains_num_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomains_num_entries, 0);
return offset;
}
static int
samr_dissect_EnumDomains_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="EnumDomains";
offset = samr_dissect_element_EnumDomains_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomains_sam(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomains_num_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_EnumDomains_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="EnumDomains";
offset = samr_dissect_element_EnumDomains_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomains_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomains_buf_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_OpenDomain_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenDomain_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_OpenDomain_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, 0);
return offset;
}
static int
samr_dissect_element_OpenDomain_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_DomainAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_domain_access_mask, 0);
return offset;
}
static int
samr_dissect_element_OpenDomain_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenDomain_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_OpenDomain_sid);
return offset;
}
static int
samr_dissect_element_OpenDomain_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_OpenDomain_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenDomain_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_OpenDomain_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_DOMAIN);
return offset;
}
static int
samr_dissect_OpenDomain_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="OpenDomain";
offset = samr_dissect_element_OpenDomain_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_OpenDomain_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="OpenDomain";
offset = samr_dissect_element_OpenDomain_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenDomain_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenDomain_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainInfoClass(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDomainInfo_level, 0);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_DomainInfo)",hf_samr_samr_QueryDomainInfo_info);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_DomainInfo)",hf_samr_samr_QueryDomainInfo_info);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DomainInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDomainInfo_info, 0);
return offset;
}
static int
samr_dissect_QueryDomainInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryDomainInfo";
offset = samr_dissect_element_QueryDomainInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryDomainInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryDomainInfo";
offset = samr_dissect_element_QueryDomainInfo_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDomainInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetDomainInfo_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetDomainInfo_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_SetDomainInfo_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_SetDomainInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainInfoClass(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetDomainInfo_level, 0);
return offset;
}
static int
samr_dissect_element_SetDomainInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetDomainInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_DomainInfo)",hf_samr_samr_SetDomainInfo_info);
return offset;
}
static int
samr_dissect_element_SetDomainInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DomainInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetDomainInfo_info, 0);
return offset;
}
static int
samr_dissect_SetDomainInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetDomainInfo";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetDomainInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetDomainInfo";
offset = samr_dissect_element_SetDomainInfo_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetDomainInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetDomainInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomainGroup_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomainGroup_name_, NDR_POINTER_REF, "Pointer to Name (lsa_String)",hf_samr_samr_CreateDomainGroup_name);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_CreateDomainGroup_name);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_group_access_mask, 0);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomainGroup_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_GROUP);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomainGroup_rid_, NDR_POINTER_REF, "Pointer to Rid (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_CreateDomainGroup_rid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_CreateDomainGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="CreateDomainGroup";
offset = samr_dissect_element_CreateDomainGroup_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomainGroup_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_CreateDomainGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="CreateDomainGroup";
offset = samr_dissect_element_CreateDomainGroup_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomainGroup_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomainGroup_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainGroups_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainGroups_resume_handle_, NDR_POINTER_REF, "Pointer to Resume Handle (uint32)",hf_samr_samr_EnumDomainGroups_resume_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainGroups_resume_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_sam(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainGroups_sam_, NDR_POINTER_REF, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainGroups_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_sam_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainGroups_sam__, NDR_POINTER_UNIQUE, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainGroups_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_sam__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_SamArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_EnumDomainGroups_sam,0);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_max_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainGroups_max_size, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_num_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainGroups_num_entries_, NDR_POINTER_REF, "Pointer to Num Entries (uint32)",hf_samr_samr_EnumDomainGroups_num_entries);
return offset;
}
static int
samr_dissect_element_EnumDomainGroups_num_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainGroups_num_entries, 0);
return offset;
}
static int
samr_dissect_EnumDomainGroups_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="EnumDomainGroups";
offset = samr_dissect_element_EnumDomainGroups_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainGroups_sam(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainGroups_num_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_EnumDomainGroups_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="EnumDomainGroups";
offset = samr_dissect_element_EnumDomainGroups_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainGroups_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainGroups_max_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_CreateUser_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_CreateUser_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_CreateUser_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser_account_name_, NDR_POINTER_REF, "Pointer to Account Name (lsa_String)",hf_samr_samr_CreateUser_account_name);
return offset;
}
static int
samr_dissect_element_CreateUser_account_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 3|PIDL_SET_COL_INFO|PIDL_STR_SAVE, hf_samr_samr_CreateUser_account_name);
return offset;
}
static int
samr_dissect_element_CreateUser_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_UserAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_user_access_mask, 0);
return offset;
}
static int
samr_dissect_element_CreateUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_CreateUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_USER);
return offset;
}
static int
samr_dissect_element_CreateUser_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser_rid_, NDR_POINTER_REF, "Pointer to Rid (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_CreateUser_rid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_CreateUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="CreateUser";
offset = samr_dissect_element_CreateUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_CreateUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="CreateUser";
offset = samr_dissect_element_CreateUser_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser_account_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainUsers_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainUsers_resume_handle_, NDR_POINTER_REF, "Pointer to Resume Handle (uint32)",hf_samr_samr_EnumDomainUsers_resume_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainUsers_resume_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainUsers_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_sam(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainUsers_sam_, NDR_POINTER_REF, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainUsers_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_sam_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainUsers_sam__, NDR_POINTER_UNIQUE, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainUsers_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_sam__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_SamArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_EnumDomainUsers_sam,0);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_max_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainUsers_max_size, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_num_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainUsers_num_entries_, NDR_POINTER_REF, "Pointer to Num Entries (uint32)",hf_samr_samr_EnumDomainUsers_num_entries);
return offset;
}
static int
samr_dissect_element_EnumDomainUsers_num_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainUsers_num_entries, 0);
return offset;
}
static int
samr_dissect_EnumDomainUsers_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="EnumDomainUsers";
offset = samr_dissect_element_EnumDomainUsers_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainUsers_sam(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainUsers_num_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_EnumDomainUsers_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="EnumDomainUsers";
offset = samr_dissect_element_EnumDomainUsers_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainUsers_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainUsers_acct_flags(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainUsers_max_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomAlias_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_alias_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomAlias_alias_name_, NDR_POINTER_REF, "Pointer to Alias Name (lsa_String)",hf_samr_samr_CreateDomAlias_alias_name);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_alias_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_CreateDomAlias_alias_name);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AliasAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_alias_access_mask, 0);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_ALIAS);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateDomAlias_rid_, NDR_POINTER_REF, "Pointer to Rid (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_CreateDomAlias_rid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_CreateDomAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="CreateDomAlias";
offset = samr_dissect_element_CreateDomAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomAlias_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_CreateDomAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="CreateDomAlias";
offset = samr_dissect_element_CreateDomAlias_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomAlias_alias_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateDomAlias_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainAliases_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_resume_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainAliases_resume_handle_, NDR_POINTER_REF, "Pointer to Resume Handle (uint32)",hf_samr_samr_EnumDomainAliases_resume_handle);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_resume_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainAliases_resume_handle, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_sam(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainAliases_sam_, NDR_POINTER_REF, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainAliases_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_sam_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainAliases_sam__, NDR_POINTER_UNIQUE, "Pointer to Sam (samr_SamArray)",hf_samr_samr_EnumDomainAliases_sam);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_sam__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_SamArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_EnumDomainAliases_sam,0);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_max_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainAliases_max_size, 0);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_num_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_EnumDomainAliases_num_entries_, NDR_POINTER_REF, "Pointer to Num Entries (uint32)",hf_samr_samr_EnumDomainAliases_num_entries);
return offset;
}
static int
samr_dissect_element_EnumDomainAliases_num_entries_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_EnumDomainAliases_num_entries, 0);
return offset;
}
static int
samr_dissect_EnumDomainAliases_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="EnumDomainAliases";
offset = samr_dissect_element_EnumDomainAliases_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainAliases_sam(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainAliases_num_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_EnumDomainAliases_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="EnumDomainAliases";
offset = samr_dissect_element_EnumDomainAliases_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainAliases_resume_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_EnumDomainAliases_max_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetAliasMembership_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_sids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetAliasMembership_sids_, NDR_POINTER_REF, "Pointer to Sids (lsa_SidArray)",hf_samr_samr_GetAliasMembership_sids);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_sids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_SidArray(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetAliasMembership_rids_, NDR_POINTER_REF, "Pointer to Rids (samr_Ids)",hf_samr_samr_GetAliasMembership_rids);
return offset;
}
static int
samr_dissect_element_GetAliasMembership_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Ids(tvb,offset,pinfo,tree,drep,hf_samr_samr_GetAliasMembership_rids,0);
return offset;
}
static int
samr_dissect_GetAliasMembership_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetAliasMembership";
offset = samr_dissect_element_GetAliasMembership_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetAliasMembership_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetAliasMembership";
offset = samr_dissect_element_GetAliasMembership_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_GetAliasMembership_sids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_LookupNames_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupNames_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_LookupNames_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_LookupNames_num_names(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_LookupNames_num_names, 0);
return offset;
}
static int
samr_dissect_element_LookupNames_names(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupNames_names_, NDR_POINTER_REF, "Pointer to Names (lsa_String)",hf_samr_samr_LookupNames_names);
return offset;
}
static int
samr_dissect_element_LookupNames_names_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupNames_names__);
return offset;
}
static int
samr_dissect_element_LookupNames_names__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_LookupNames_names);
return offset;
}
static int
samr_dissect_element_LookupNames_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupNames_rids_, NDR_POINTER_REF, "Pointer to Rids (samr_Ids)",hf_samr_samr_LookupNames_rids);
return offset;
}
static int
samr_dissect_element_LookupNames_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Ids(tvb,offset,pinfo,tree,drep,hf_samr_samr_LookupNames_rids,0);
return offset;
}
static int
samr_dissect_element_LookupNames_types(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupNames_types_, NDR_POINTER_REF, "Pointer to Types (samr_Ids)",hf_samr_samr_LookupNames_types);
return offset;
}
static int
samr_dissect_element_LookupNames_types_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Ids(tvb,offset,pinfo,tree,drep,hf_samr_samr_LookupNames_types,0);
return offset;
}
static int
samr_dissect_LookupNames_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="LookupNames";
offset = samr_dissect_element_LookupNames_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupNames_types(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_LookupNames_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="LookupNames";
offset = samr_dissect_element_LookupNames_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupNames_num_names(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupNames_names(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_LookupRids_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupRids_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_LookupRids_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_LookupRids_num_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_LookupRids_num_rids, 0);
return offset;
}
static int
samr_dissect_element_LookupRids_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupRids_rids_);
return offset;
}
static int
samr_dissect_element_LookupRids_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_LookupRids_names(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupRids_names_, NDR_POINTER_REF, "Pointer to Names (lsa_Strings)",hf_samr_samr_LookupRids_names);
return offset;
}
static int
samr_dissect_element_LookupRids_names_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_lsa_Strings(tvb,offset,pinfo,tree,drep,hf_samr_samr_LookupRids_names,0);
return offset;
}
static int
samr_dissect_element_LookupRids_types(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_LookupRids_types_, NDR_POINTER_REF, "Pointer to Types (samr_Ids)",hf_samr_samr_LookupRids_types);
return offset;
}
static int
samr_dissect_element_LookupRids_types_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Ids(tvb,offset,pinfo,tree,drep,hf_samr_samr_LookupRids_types,0);
return offset;
}
static int
samr_dissect_LookupRids_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="LookupRids";
offset = samr_dissect_element_LookupRids_names(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupRids_types(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_LookupRids_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="LookupRids";
offset = samr_dissect_element_LookupRids_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupRids_num_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_LookupRids_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_OpenGroup_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenGroup_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_OpenGroup_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_OpenGroup_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_GroupAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_group_access_mask, 0);
return offset;
}
static int
samr_dissect_element_OpenGroup_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_OpenGroup_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenGroup_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_OpenGroup_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_GROUP);
return offset;
}
static int
samr_dissect_OpenGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="OpenGroup";
offset = samr_dissect_element_OpenGroup_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_OpenGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="OpenGroup";
offset = samr_dissect_element_OpenGroup_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenGroup_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenGroup_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupInfo_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_GroupInfoEnum(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryGroupInfo_level, 0);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_GroupInfo)",hf_samr_samr_QueryGroupInfo_info);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupInfo_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_GroupInfo)",hf_samr_samr_QueryGroupInfo_info);
return offset;
}
static int
samr_dissect_element_QueryGroupInfo_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_GroupInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryGroupInfo_info, 0);
return offset;
}
static int
samr_dissect_QueryGroupInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryGroupInfo";
offset = samr_dissect_element_QueryGroupInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryGroupInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryGroupInfo";
offset = samr_dissect_element_QueryGroupInfo_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryGroupInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetGroupInfo_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetGroupInfo_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_SetGroupInfo_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_SetGroupInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_GroupInfoEnum(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetGroupInfo_level, 0);
return offset;
}
static int
samr_dissect_element_SetGroupInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetGroupInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_GroupInfo)",hf_samr_samr_SetGroupInfo_info);
return offset;
}
static int
samr_dissect_element_SetGroupInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_GroupInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetGroupInfo_info, 0);
return offset;
}
static int
samr_dissect_SetGroupInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetGroupInfo";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetGroupInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetGroupInfo";
offset = samr_dissect_element_SetGroupInfo_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetGroupInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetGroupInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_AddGroupMember_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_AddGroupMember_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_AddGroupMember_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_AddGroupMember_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_AddGroupMember_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_AddGroupMember_flags, 0);
return offset;
}
static int
samr_dissect_AddGroupMember_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="AddGroupMember";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_AddGroupMember_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="AddGroupMember";
offset = samr_dissect_element_AddGroupMember_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_AddGroupMember_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_AddGroupMember_flags(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_DeleteDomainGroup_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteDomainGroup_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_DeleteDomainGroup_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, PIDL_POLHND_CLOSE);
return offset;
}
static int
samr_dissect_DeleteDomainGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="DeleteDomainGroup";
offset = samr_dissect_element_DeleteDomainGroup_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_DeleteDomainGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="DeleteDomainGroup";
offset = samr_dissect_element_DeleteDomainGroup_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_DeleteGroupMember_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteGroupMember_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_DeleteGroupMember_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_DeleteGroupMember_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_DeleteGroupMember_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="DeleteGroupMember";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_DeleteGroupMember_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="DeleteGroupMember";
offset = samr_dissect_element_DeleteGroupMember_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_DeleteGroupMember_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryGroupMember_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupMember_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_QueryGroupMember_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryGroupMember_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupMember_rids_, NDR_POINTER_REF, "Pointer to Rids (samr_RidTypeArray)",hf_samr_samr_QueryGroupMember_rids);
return offset;
}
static int
samr_dissect_element_QueryGroupMember_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryGroupMember_rids__, NDR_POINTER_UNIQUE, "Pointer to Rids (samr_RidTypeArray)",hf_samr_samr_QueryGroupMember_rids);
return offset;
}
static int
samr_dissect_element_QueryGroupMember_rids__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_RidTypeArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_QueryGroupMember_rids,0);
return offset;
}
static int
samr_dissect_QueryGroupMember_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryGroupMember";
offset = samr_dissect_element_QueryGroupMember_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryGroupMember_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryGroupMember";
offset = samr_dissect_element_QueryGroupMember_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetMemberAttributesOfGroup_group_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetMemberAttributesOfGroup_group_handle_, NDR_POINTER_REF, "Pointer to Group Handle (policy_handle)",hf_samr_group_handle);
return offset;
}
static int
samr_dissect_element_SetMemberAttributesOfGroup_group_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_group_handle, 0);
return offset;
}
static int
samr_dissect_element_SetMemberAttributesOfGroup_unknown1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetMemberAttributesOfGroup_unknown1, 0);
return offset;
}
static int
samr_dissect_element_SetMemberAttributesOfGroup_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetMemberAttributesOfGroup_unknown2, 0);
return offset;
}
static int
samr_dissect_SetMemberAttributesOfGroup_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetMemberAttributesOfGroup";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetMemberAttributesOfGroup_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetMemberAttributesOfGroup";
offset = samr_dissect_element_SetMemberAttributesOfGroup_group_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetMemberAttributesOfGroup_unknown1(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetMemberAttributesOfGroup_unknown2(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_OpenAlias_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenAlias_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_OpenAlias_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_OpenAlias_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AliasAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_alias_access_mask, 0);
return offset;
}
static int
samr_dissect_element_OpenAlias_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_OpenAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_OpenAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_ALIAS);
return offset;
}
static int
samr_dissect_OpenAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="OpenAlias";
offset = samr_dissect_element_OpenAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_OpenAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="OpenAlias";
offset = samr_dissect_element_OpenAlias_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenAlias_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenAlias_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryAliasInfo_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_AliasInfoEnum(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryAliasInfo_level, 0);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryAliasInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_AliasInfo)",hf_samr_samr_QueryAliasInfo_info);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryAliasInfo_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_AliasInfo)",hf_samr_samr_QueryAliasInfo_info);
return offset;
}
static int
samr_dissect_element_QueryAliasInfo_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_AliasInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryAliasInfo_info, 0);
return offset;
}
static int
samr_dissect_QueryAliasInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryAliasInfo";
offset = samr_dissect_element_QueryAliasInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryAliasInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryAliasInfo";
offset = samr_dissect_element_QueryAliasInfo_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryAliasInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetAliasInfo_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetAliasInfo_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_SetAliasInfo_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_SetAliasInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_AliasInfoEnum(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetAliasInfo_level, 0);
return offset;
}
static int
samr_dissect_element_SetAliasInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetAliasInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_AliasInfo)",hf_samr_samr_SetAliasInfo_info);
return offset;
}
static int
samr_dissect_element_SetAliasInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_AliasInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetAliasInfo_info, 0);
return offset;
}
static int
samr_dissect_SetAliasInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetAliasInfo";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetAliasInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetAliasInfo";
offset = samr_dissect_element_SetAliasInfo_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetAliasInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetAliasInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_DeleteDomAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteDomAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_DeleteDomAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, PIDL_POLHND_CLOSE);
return offset;
}
static int
samr_dissect_DeleteDomAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="DeleteDomAlias";
offset = samr_dissect_element_DeleteDomAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_DeleteDomAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="DeleteDomAlias";
offset = samr_dissect_element_DeleteDomAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_AddAliasMember_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_AddAliasMember_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_AddAliasMember_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_AddAliasMember_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_AddAliasMember_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_AddAliasMember_sid);
return offset;
}
static int
samr_dissect_element_AddAliasMember_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_AddAliasMember_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="AddAliasMember";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_AddAliasMember_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="AddAliasMember";
offset = samr_dissect_element_AddAliasMember_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_AddAliasMember_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_DeleteAliasMember_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteAliasMember_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_DeleteAliasMember_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_DeleteAliasMember_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteAliasMember_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_DeleteAliasMember_sid);
return offset;
}
static int
samr_dissect_element_DeleteAliasMember_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_DeleteAliasMember_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="DeleteAliasMember";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_DeleteAliasMember_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="DeleteAliasMember";
offset = samr_dissect_element_DeleteAliasMember_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_DeleteAliasMember_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetMembersInAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetMembersInAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_GetMembersInAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_GetMembersInAlias_sids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetMembersInAlias_sids_, NDR_POINTER_REF, "Pointer to Sids (lsa_SidArray)",hf_samr_samr_GetMembersInAlias_sids);
return offset;
}
static int
samr_dissect_element_GetMembersInAlias_sids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_SidArray(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_GetMembersInAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetMembersInAlias";
offset = samr_dissect_element_GetMembersInAlias_sids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetMembersInAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetMembersInAlias";
offset = samr_dissect_element_GetMembersInAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_OpenUser_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenUser_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_OpenUser_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_OpenUser_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_UserAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_user_access_mask, 0);
return offset;
}
static int
samr_dissect_element_OpenUser_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_OpenUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OpenUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_OpenUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_USER);
return offset;
}
static int
samr_dissect_OpenUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="OpenUser";
offset = samr_dissect_element_OpenUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_OpenUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="OpenUser";
offset = samr_dissect_element_OpenUser_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenUser_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OpenUser_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_DeleteUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_DeleteUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_DeleteUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, PIDL_POLHND_CLOSE);
return offset;
}
static int
samr_dissect_DeleteUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="DeleteUser";
offset = samr_dissect_element_DeleteUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_DeleteUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="DeleteUser";
offset = samr_dissect_element_DeleteUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_UserInfoLevel(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryUserInfo_level, 0);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_UserInfo)",hf_samr_samr_QueryUserInfo_info);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_UserInfo)",hf_samr_samr_QueryUserInfo_info);
return offset;
}
static int
samr_dissect_element_QueryUserInfo_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_UserInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryUserInfo_info, 0);
return offset;
}
static int
samr_dissect_QueryUserInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryUserInfo";
offset = samr_dissect_element_QueryUserInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryUserInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryUserInfo";
offset = samr_dissect_element_QueryUserInfo_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryUserInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetUserInfo_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetUserInfo_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_SetUserInfo_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_SetUserInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_UserInfoLevel(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetUserInfo_level, 0);
return offset;
}
static int
samr_dissect_element_SetUserInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetUserInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_UserInfo)",hf_samr_samr_SetUserInfo_info);
return offset;
}
static int
samr_dissect_element_SetUserInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_UserInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetUserInfo_info, 0);
return offset;
}
static int
samr_dissect_SetUserInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetUserInfo";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetUserInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetUserInfo";
offset = samr_dissect_element_SetUserInfo_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetUserInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetUserInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_lm_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser_lm_present, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_old_lm_crypted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_old_lm_crypted_, NDR_POINTER_UNIQUE, "Pointer to Old Lm Crypted (samr_Password)",hf_samr_samr_ChangePasswordUser_old_lm_crypted);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_old_lm_crypted_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_old_lm_crypted,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_new_lm_crypted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_new_lm_crypted_, NDR_POINTER_UNIQUE, "Pointer to New Lm Crypted (samr_Password)",hf_samr_samr_ChangePasswordUser_new_lm_crypted);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_new_lm_crypted_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_new_lm_crypted,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_nt_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser_nt_present, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_old_nt_crypted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_old_nt_crypted_, NDR_POINTER_UNIQUE, "Pointer to Old Nt Crypted (samr_Password)",hf_samr_samr_ChangePasswordUser_old_nt_crypted);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_old_nt_crypted_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_old_nt_crypted,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_new_nt_crypted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_new_nt_crypted_, NDR_POINTER_UNIQUE, "Pointer to New Nt Crypted (samr_Password)",hf_samr_samr_ChangePasswordUser_new_nt_crypted);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_new_nt_crypted_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_new_nt_crypted,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_cross1_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser_cross1_present, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_nt_cross(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_nt_cross_, NDR_POINTER_UNIQUE, "Pointer to Nt Cross (samr_Password)",hf_samr_samr_ChangePasswordUser_nt_cross);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_nt_cross_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_nt_cross,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_cross2_present(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser_cross2_present, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_lm_cross(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser_lm_cross_, NDR_POINTER_UNIQUE, "Pointer to Lm Cross (samr_Password)",hf_samr_samr_ChangePasswordUser_lm_cross);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser_lm_cross_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser_lm_cross,0);
return offset;
}
static int
samr_dissect_ChangePasswordUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="ChangePasswordUser";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_ChangePasswordUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="ChangePasswordUser";
offset = samr_dissect_element_ChangePasswordUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_lm_present(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_old_lm_crypted(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_new_lm_crypted(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_nt_present(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_old_nt_crypted(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_new_nt_crypted(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_cross1_present(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_nt_cross(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_cross2_present(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser_lm_cross(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetGroupsForUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetGroupsForUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_GetGroupsForUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_GetGroupsForUser_rids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetGroupsForUser_rids_, NDR_POINTER_REF, "Pointer to Rids (samr_RidWithAttributeArray)",hf_samr_samr_GetGroupsForUser_rids);
return offset;
}
static int
samr_dissect_element_GetGroupsForUser_rids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetGroupsForUser_rids__, NDR_POINTER_UNIQUE, "Pointer to Rids (samr_RidWithAttributeArray)",hf_samr_samr_GetGroupsForUser_rids);
return offset;
}
static int
samr_dissect_element_GetGroupsForUser_rids__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_RidWithAttributeArray(tvb,offset,pinfo,tree,drep,hf_samr_samr_GetGroupsForUser_rids,0);
return offset;
}
static int
samr_dissect_GetGroupsForUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetGroupsForUser";
offset = samr_dissect_element_GetGroupsForUser_rids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetGroupsForUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetGroupsForUser";
offset = samr_dissect_element_GetGroupsForUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainDisplayInformation(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_level, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_start_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_start_idx, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_max_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_max_entries, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_buf_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_buf_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_total_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo_total_size_, NDR_POINTER_REF, "Pointer to Total Size (uint32)",hf_samr_samr_QueryDisplayInfo_total_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_total_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_total_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_returned_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo_returned_size_, NDR_POINTER_REF, "Pointer to Returned Size (uint32)",hf_samr_samr_QueryDisplayInfo_returned_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_returned_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_returned_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_DispInfo)",hf_samr_samr_QueryDisplayInfo_info);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DispInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo_info, 0);
return offset;
}
static int
samr_dissect_QueryDisplayInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryDisplayInfo";
offset = samr_dissect_element_QueryDisplayInfo_total_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_returned_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryDisplayInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryDisplayInfo";
offset = samr_dissect_element_QueryDisplayInfo_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_start_idx(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_max_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo_buf_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetDisplayEnumerationIndex_level, 0);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex_name_, NDR_POINTER_REF, "Pointer to Name (lsa_String)",hf_samr_samr_GetDisplayEnumerationIndex_name);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GetDisplayEnumerationIndex_name);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex_idx_, NDR_POINTER_REF, "Pointer to Idx (uint32)",hf_samr_samr_GetDisplayEnumerationIndex_idx);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex_idx_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetDisplayEnumerationIndex_idx, 0);
return offset;
}
static int
samr_dissect_GetDisplayEnumerationIndex_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetDisplayEnumerationIndex";
offset = samr_dissect_element_GetDisplayEnumerationIndex_idx(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetDisplayEnumerationIndex_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetDisplayEnumerationIndex";
offset = samr_dissect_element_GetDisplayEnumerationIndex_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_GetDisplayEnumerationIndex_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_GetDisplayEnumerationIndex_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_TestPrivateFunctionsDomain_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_TestPrivateFunctionsDomain_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_TestPrivateFunctionsDomain_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_TestPrivateFunctionsDomain_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="TestPrivateFunctionsDomain";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_TestPrivateFunctionsDomain_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="TestPrivateFunctionsDomain";
offset = samr_dissect_element_TestPrivateFunctionsDomain_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_TestPrivateFunctionsUser_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_TestPrivateFunctionsUser_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_TestPrivateFunctionsUser_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_TestPrivateFunctionsUser_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="TestPrivateFunctionsUser";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_TestPrivateFunctionsUser_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="TestPrivateFunctionsUser";
offset = samr_dissect_element_TestPrivateFunctionsUser_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetUserPwInfo_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetUserPwInfo_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_GetUserPwInfo_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_GetUserPwInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetUserPwInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_PwInfo)",hf_samr_samr_GetUserPwInfo_info);
return offset;
}
static int
samr_dissect_element_GetUserPwInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_PwInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_GetUserPwInfo_info,0);
return offset;
}
static int
samr_dissect_GetUserPwInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetUserPwInfo";
offset = samr_dissect_element_GetUserPwInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetUserPwInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetUserPwInfo";
offset = samr_dissect_element_GetUserPwInfo_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_RemoveMemberFromForeignDomain_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RemoveMemberFromForeignDomain_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_RemoveMemberFromForeignDomain_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_RemoveMemberFromForeignDomain_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RemoveMemberFromForeignDomain_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_RemoveMemberFromForeignDomain_sid);
return offset;
}
static int
samr_dissect_element_RemoveMemberFromForeignDomain_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_RemoveMemberFromForeignDomain_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="RemoveMemberFromForeignDomain";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_RemoveMemberFromForeignDomain_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="RemoveMemberFromForeignDomain";
offset = samr_dissect_element_RemoveMemberFromForeignDomain_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_RemoveMemberFromForeignDomain_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo2_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainInfoClass(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDomainInfo2_level, 0);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo2_info_, NDR_POINTER_REF, "Pointer to Info (samr_DomainInfo)",hf_samr_samr_QueryDomainInfo2_info);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDomainInfo2_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_DomainInfo)",hf_samr_samr_QueryDomainInfo2_info);
return offset;
}
static int
samr_dissect_element_QueryDomainInfo2_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DomainInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDomainInfo2_info, 0);
return offset;
}
static int
samr_dissect_QueryDomainInfo2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryDomainInfo2";
offset = samr_dissect_element_QueryDomainInfo2_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryDomainInfo2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryDomainInfo2";
offset = samr_dissect_element_QueryDomainInfo2_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDomainInfo2_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo2_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_UserInfoLevel(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryUserInfo2_level, 0);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo2_info_, NDR_POINTER_REF, "Pointer to Info (samr_UserInfo)",hf_samr_samr_QueryUserInfo2_info);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryUserInfo2_info__, NDR_POINTER_UNIQUE, "Pointer to Info (samr_UserInfo)",hf_samr_samr_QueryUserInfo2_info);
return offset;
}
static int
samr_dissect_element_QueryUserInfo2_info__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_UserInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryUserInfo2_info, 0);
return offset;
}
static int
samr_dissect_QueryUserInfo2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryUserInfo2";
offset = samr_dissect_element_QueryUserInfo2_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryUserInfo2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryUserInfo2";
offset = samr_dissect_element_QueryUserInfo2_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryUserInfo2_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo2_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainDisplayInformation(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_level, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_start_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_start_idx, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_max_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_max_entries, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_buf_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_buf_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_total_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo2_total_size_, NDR_POINTER_REF, "Pointer to Total Size (uint32)",hf_samr_samr_QueryDisplayInfo2_total_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_total_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_total_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_returned_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo2_returned_size_, NDR_POINTER_REF, "Pointer to Returned Size (uint32)",hf_samr_samr_QueryDisplayInfo2_returned_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_returned_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_returned_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo2_info_, NDR_POINTER_REF, "Pointer to Info (samr_DispInfo)",hf_samr_samr_QueryDisplayInfo2_info);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo2_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DispInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo2_info, 0);
return offset;
}
static int
samr_dissect_QueryDisplayInfo2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryDisplayInfo2";
offset = samr_dissect_element_QueryDisplayInfo2_total_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_returned_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryDisplayInfo2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryDisplayInfo2";
offset = samr_dissect_element_QueryDisplayInfo2_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_start_idx(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_max_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo2_buf_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex2_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainDisplayInformation(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetDisplayEnumerationIndex2_level, 0);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex2_name_, NDR_POINTER_REF, "Pointer to Name (lsa_String)",hf_samr_samr_GetDisplayEnumerationIndex2_name);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_GetDisplayEnumerationIndex2_name);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDisplayEnumerationIndex2_idx_, NDR_POINTER_REF, "Pointer to Idx (uint32)",hf_samr_samr_GetDisplayEnumerationIndex2_idx);
return offset;
}
static int
samr_dissect_element_GetDisplayEnumerationIndex2_idx_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetDisplayEnumerationIndex2_idx, 0);
return offset;
}
static int
samr_dissect_GetDisplayEnumerationIndex2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetDisplayEnumerationIndex2";
offset = samr_dissect_element_GetDisplayEnumerationIndex2_idx(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetDisplayEnumerationIndex2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetDisplayEnumerationIndex2";
offset = samr_dissect_element_GetDisplayEnumerationIndex2_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_GetDisplayEnumerationIndex2_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_GetDisplayEnumerationIndex2_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_CreateUser2_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser2_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_CreateUser2_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_CreateUser2_account_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser2_account_name_, NDR_POINTER_REF, "Pointer to Account Name (lsa_String)",hf_samr_samr_CreateUser2_account_name);
return offset;
}
static int
samr_dissect_element_CreateUser2_account_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 3|PIDL_SET_COL_INFO|PIDL_STR_SAVE, hf_samr_samr_CreateUser2_account_name);
return offset;
}
static int
samr_dissect_element_CreateUser2_acct_flags(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_AcctFlags(tvb, offset, pinfo, tree, drep, hf_samr_samr_CreateUser2_acct_flags, 0);
return offset;
}
static int
samr_dissect_element_CreateUser2_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_UserAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_user_access_mask, 0);
return offset;
}
static int
samr_dissect_element_CreateUser2_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser2_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_CreateUser2_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_USER);
return offset;
}
static int
samr_dissect_element_CreateUser2_access_granted(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser2_access_granted_, NDR_POINTER_REF, "Pointer to Access Granted (uint32)",hf_samr_samr_CreateUser2_access_granted);
return offset;
}
static int
samr_dissect_element_CreateUser2_access_granted_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_CreateUser2_access_granted, 0);
return offset;
}
static int
samr_dissect_element_CreateUser2_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_CreateUser2_rid_, NDR_POINTER_REF, "Pointer to Rid (uint32)",hf_samr_rid);
return offset;
}
static int
samr_dissect_element_CreateUser2_rid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_CreateUser2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="CreateUser2";
offset = samr_dissect_element_CreateUser2_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser2_access_granted(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser2_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_CreateUser2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="CreateUser2";
offset = samr_dissect_element_CreateUser2_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser2_account_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser2_acct_flags(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_CreateUser2_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo3_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_DomainDisplayInformation(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_level, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_start_idx(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_start_idx, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_max_entries(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_max_entries, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_buf_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_buf_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_total_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo3_total_size_, NDR_POINTER_REF, "Pointer to Total Size (uint32)",hf_samr_samr_QueryDisplayInfo3_total_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_total_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_total_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_returned_size(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo3_returned_size_, NDR_POINTER_REF, "Pointer to Returned Size (uint32)",hf_samr_samr_QueryDisplayInfo3_returned_size);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_returned_size_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_returned_size, 0);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_QueryDisplayInfo3_info_, NDR_POINTER_REF, "Pointer to Info (samr_DispInfo)",hf_samr_samr_QueryDisplayInfo3_info);
return offset;
}
static int
samr_dissect_element_QueryDisplayInfo3_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_DispInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_QueryDisplayInfo3_info, 0);
return offset;
}
static int
samr_dissect_QueryDisplayInfo3_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="QueryDisplayInfo3";
offset = samr_dissect_element_QueryDisplayInfo3_total_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_returned_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_QueryDisplayInfo3_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="QueryDisplayInfo3";
offset = samr_dissect_element_QueryDisplayInfo3_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_start_idx(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_max_entries(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_QueryDisplayInfo3_buf_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_AddMultipleMembersToAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_AddMultipleMembersToAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_AddMultipleMembersToAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_AddMultipleMembersToAlias_sids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_AddMultipleMembersToAlias_sids_, NDR_POINTER_REF, "Pointer to Sids (lsa_SidArray)",hf_samr_samr_AddMultipleMembersToAlias_sids);
return offset;
}
static int
samr_dissect_element_AddMultipleMembersToAlias_sids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_SidArray(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_AddMultipleMembersToAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="AddMultipleMembersToAlias";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_AddMultipleMembersToAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="AddMultipleMembersToAlias";
offset = samr_dissect_element_AddMultipleMembersToAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_AddMultipleMembersToAlias_sids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_RemoveMultipleMembersFromAlias_alias_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RemoveMultipleMembersFromAlias_alias_handle_, NDR_POINTER_REF, "Pointer to Alias Handle (policy_handle)",hf_samr_alias_handle);
return offset;
}
static int
samr_dissect_element_RemoveMultipleMembersFromAlias_alias_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_alias_handle, 0);
return offset;
}
static int
samr_dissect_element_RemoveMultipleMembersFromAlias_sids(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RemoveMultipleMembersFromAlias_sids_, NDR_POINTER_REF, "Pointer to Sids (lsa_SidArray)",hf_samr_samr_RemoveMultipleMembersFromAlias_sids);
return offset;
}
static int
samr_dissect_element_RemoveMultipleMembersFromAlias_sids_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_SidArray(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_RemoveMultipleMembersFromAlias_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="RemoveMultipleMembersFromAlias";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_RemoveMultipleMembersFromAlias_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="RemoveMultipleMembersFromAlias";
offset = samr_dissect_element_RemoveMultipleMembersFromAlias_alias_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_RemoveMultipleMembersFromAlias_sids(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_server(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OemChangePasswordUser2_server_, NDR_POINTER_UNIQUE, "Pointer to Server (lsa_AsciiString)",hf_samr_samr_OemChangePasswordUser2_server);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_server_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_AsciiString(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_OemChangePasswordUser2_server);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OemChangePasswordUser2_account_, NDR_POINTER_REF, "Pointer to Account (lsa_AsciiString)",hf_samr_samr_OemChangePasswordUser2_account);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_account_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_lsa_AsciiString(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_OemChangePasswordUser2_account);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OemChangePasswordUser2_password_, NDR_POINTER_UNIQUE, "Pointer to Password (samr_CryptPassword)",hf_samr_samr_OemChangePasswordUser2_password);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_OemChangePasswordUser2_password,0);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_hash(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_OemChangePasswordUser2_hash_, NDR_POINTER_UNIQUE, "Pointer to Hash (samr_Password)",hf_samr_samr_OemChangePasswordUser2_hash);
return offset;
}
static int
samr_dissect_element_OemChangePasswordUser2_hash_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_OemChangePasswordUser2_hash,0);
return offset;
}
static int
samr_dissect_OemChangePasswordUser2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="OemChangePasswordUser2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_OemChangePasswordUser2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="OemChangePasswordUser2";
offset = samr_dissect_element_OemChangePasswordUser2_server(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OemChangePasswordUser2_account(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OemChangePasswordUser2_password(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_OemChangePasswordUser2_hash(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_server(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_server_, NDR_POINTER_UNIQUE, "Pointer to Server (lsa_String)",hf_samr_samr_ChangePasswordUser2_server);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_server_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ChangePasswordUser2_server);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_account_, NDR_POINTER_REF, "Pointer to Account (lsa_String)",hf_samr_samr_ChangePasswordUser2_account);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_account_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ChangePasswordUser2_account);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_nt_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_nt_password_, NDR_POINTER_UNIQUE, "Pointer to Nt Password (samr_CryptPassword)",hf_samr_samr_ChangePasswordUser2_nt_password);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_nt_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser2_nt_password,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_nt_verifier(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_nt_verifier_, NDR_POINTER_UNIQUE, "Pointer to Nt Verifier (samr_Password)",hf_samr_samr_ChangePasswordUser2_nt_verifier);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_nt_verifier_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser2_nt_verifier,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_lm_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser2_lm_change, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_lm_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_lm_password_, NDR_POINTER_UNIQUE, "Pointer to Lm Password (samr_CryptPassword)",hf_samr_samr_ChangePasswordUser2_lm_password);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_lm_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser2_lm_password,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_lm_verifier(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser2_lm_verifier_, NDR_POINTER_UNIQUE, "Pointer to Lm Verifier (samr_Password)",hf_samr_samr_ChangePasswordUser2_lm_verifier);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser2_lm_verifier_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser2_lm_verifier,0);
return offset;
}
static int
samr_dissect_ChangePasswordUser2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="ChangePasswordUser2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_ChangePasswordUser2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="ChangePasswordUser2";
offset = samr_dissect_element_ChangePasswordUser2_server(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_account(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_nt_password(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_nt_verifier(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_lm_change(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_lm_password(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser2_lm_verifier(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetDomPwInfo_domain_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDomPwInfo_domain_name_, NDR_POINTER_UNIQUE, "Pointer to Domain Name (lsa_String)",hf_samr_samr_GetDomPwInfo_domain_name);
return offset;
}
static int
samr_dissect_element_GetDomPwInfo_domain_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 3|PIDL_SET_COL_INFO, hf_samr_samr_GetDomPwInfo_domain_name);
return offset;
}
static int
samr_dissect_element_GetDomPwInfo_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetDomPwInfo_info_, NDR_POINTER_REF, "Pointer to Info (samr_PwInfo)",hf_samr_samr_GetDomPwInfo_info);
return offset;
}
static int
samr_dissect_element_GetDomPwInfo_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_PwInfo(tvb,offset,pinfo,tree,drep,hf_samr_samr_GetDomPwInfo_info,0);
return offset;
}
static int
samr_dissect_GetDomPwInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetDomPwInfo";
offset = samr_dissect_element_GetDomPwInfo_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetDomPwInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetDomPwInfo";
offset = samr_dissect_element_GetDomPwInfo_domain_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Connect2_system_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect2_system_name_, NDR_POINTER_UNIQUE, "Pointer to System Name (uint16)",hf_samr_samr_Connect2_system_name);
return offset;
}
static int
samr_dissect_element_Connect2_system_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_samr_samr_Connect2_system_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
samr_dissect_element_Connect2_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ConnectAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask, 0);
return offset;
}
static int
samr_dissect_element_Connect2_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect2_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_Connect2_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_CONNECT);
return offset;
}
static int
samr_dissect_Connect2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Connect2";
offset = samr_dissect_element_Connect2_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Connect2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Connect2";
offset = samr_dissect_element_Connect2_system_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect2_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetUserInfo2_user_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetUserInfo2_user_handle_, NDR_POINTER_REF, "Pointer to User Handle (policy_handle)",hf_samr_user_handle);
return offset;
}
static int
samr_dissect_element_SetUserInfo2_user_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_user_handle, 0);
return offset;
}
static int
samr_dissect_element_SetUserInfo2_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_UserInfoLevel(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetUserInfo2_level, 0);
return offset;
}
static int
samr_dissect_element_SetUserInfo2_info(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetUserInfo2_info_, NDR_POINTER_REF, "Pointer to Info (samr_UserInfo)",hf_samr_samr_SetUserInfo2_info);
return offset;
}
static int
samr_dissect_element_SetUserInfo2_info_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_UserInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetUserInfo2_info, 0);
return offset;
}
static int
samr_dissect_SetUserInfo2_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetUserInfo2";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetUserInfo2_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetUserInfo2";
offset = samr_dissect_element_SetUserInfo2_user_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetUserInfo2_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetUserInfo2_info(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetBootKeyInformation_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetBootKeyInformation_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_SetBootKeyInformation_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, 0);
return offset;
}
static int
samr_dissect_element_SetBootKeyInformation_unknown1(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetBootKeyInformation_unknown1, 0);
return offset;
}
static int
samr_dissect_element_SetBootKeyInformation_unknown2(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetBootKeyInformation_unknown2, 0);
return offset;
}
static int
samr_dissect_element_SetBootKeyInformation_unknown3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetBootKeyInformation_unknown3, 0);
return offset;
}
static int
samr_dissect_SetBootKeyInformation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetBootKeyInformation";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetBootKeyInformation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetBootKeyInformation";
offset = samr_dissect_element_SetBootKeyInformation_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetBootKeyInformation_unknown1(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetBootKeyInformation_unknown2(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetBootKeyInformation_unknown3(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_GetBootKeyInformation_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetBootKeyInformation_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_samr_GetBootKeyInformation_domain_handle);
return offset;
}
static int
samr_dissect_element_GetBootKeyInformation_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetBootKeyInformation_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_GetBootKeyInformation_unknown(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_GetBootKeyInformation_unknown_, NDR_POINTER_REF, "Pointer to Unknown (uint32)",hf_samr_samr_GetBootKeyInformation_unknown);
return offset;
}
static int
samr_dissect_element_GetBootKeyInformation_unknown_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_GetBootKeyInformation_unknown, 0);
return offset;
}
static int
samr_dissect_GetBootKeyInformation_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="GetBootKeyInformation";
offset = samr_dissect_element_GetBootKeyInformation_unknown(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_GetBootKeyInformation_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="GetBootKeyInformation";
offset = samr_dissect_element_GetBootKeyInformation_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Connect3_system_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect3_system_name_, NDR_POINTER_UNIQUE, "Pointer to System Name (uint16)",hf_samr_samr_Connect3_system_name);
return offset;
}
static int
samr_dissect_element_Connect3_system_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_samr_samr_Connect3_system_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
samr_dissect_element_Connect3_unknown(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect3_unknown, 0);
return offset;
}
static int
samr_dissect_element_Connect3_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ConnectAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask, 0);
return offset;
}
static int
samr_dissect_element_Connect3_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect3_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_Connect3_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_CONNECT);
return offset;
}
static int
samr_dissect_Connect3_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Connect3";
offset = samr_dissect_element_Connect3_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Connect3_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Connect3";
offset = samr_dissect_element_Connect3_system_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect3_unknown(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect3_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Connect4_system_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect4_system_name_, NDR_POINTER_UNIQUE, "Pointer to System Name (uint16)",hf_samr_samr_Connect4_system_name);
return offset;
}
static int
samr_dissect_element_Connect4_system_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_samr_samr_Connect4_system_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
samr_dissect_element_Connect4_client_version(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_ConnectVersion(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect4_client_version, 0);
return offset;
}
static int
samr_dissect_element_Connect4_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ConnectAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask, 0);
return offset;
}
static int
samr_dissect_element_Connect4_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect4_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_Connect4_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_CONNECT);
return offset;
}
static int
samr_dissect_Connect4_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Connect4";
offset = samr_dissect_element_Connect4_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Connect4_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Connect4";
offset = samr_dissect_element_Connect4_system_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect4_client_version(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect4_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_server(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_server_, NDR_POINTER_UNIQUE, "Pointer to Server (lsa_String)",hf_samr_samr_ChangePasswordUser3_server);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_server_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ChangePasswordUser3_server);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_account(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_account_, NDR_POINTER_REF, "Pointer to Account (lsa_String)",hf_samr_samr_ChangePasswordUser3_account);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_account_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_ChangePasswordUser3_account);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_nt_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_nt_password_, NDR_POINTER_UNIQUE, "Pointer to Nt Password (samr_CryptPassword)",hf_samr_samr_ChangePasswordUser3_nt_password);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_nt_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_nt_password,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_nt_verifier(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_nt_verifier_, NDR_POINTER_UNIQUE, "Pointer to Nt Verifier (samr_Password)",hf_samr_samr_ChangePasswordUser3_nt_verifier);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_nt_verifier_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_nt_verifier,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_lm_change(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_samr_samr_ChangePasswordUser3_lm_change, 0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_lm_password(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_lm_password_, NDR_POINTER_UNIQUE, "Pointer to Lm Password (samr_CryptPassword)",hf_samr_samr_ChangePasswordUser3_lm_password);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_lm_password_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_lm_password,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_lm_verifier(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_lm_verifier_, NDR_POINTER_UNIQUE, "Pointer to Lm Verifier (samr_Password)",hf_samr_samr_ChangePasswordUser3_lm_verifier);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_lm_verifier_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_lm_verifier,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_password3(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_password3_, NDR_POINTER_UNIQUE, "Pointer to Password3 (samr_CryptPassword)",hf_samr_samr_ChangePasswordUser3_password3);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_password3_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_CryptPassword(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_password3,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_dominfo(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_dominfo_, NDR_POINTER_REF, "Pointer to Dominfo (samr_DomInfo1)",hf_samr_samr_ChangePasswordUser3_dominfo);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_dominfo_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_dominfo__, NDR_POINTER_UNIQUE, "Pointer to Dominfo (samr_DomInfo1)",hf_samr_samr_ChangePasswordUser3_dominfo);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_dominfo__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_DomInfo1(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_dominfo,0);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_reject(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_reject_, NDR_POINTER_REF, "Pointer to Reject (samr_ChangeReject)",hf_samr_samr_ChangePasswordUser3_reject);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_reject_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ChangePasswordUser3_reject__, NDR_POINTER_UNIQUE, "Pointer to Reject (samr_ChangeReject)",hf_samr_samr_ChangePasswordUser3_reject);
return offset;
}
static int
samr_dissect_element_ChangePasswordUser3_reject__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_ChangeReject(tvb,offset,pinfo,tree,drep,hf_samr_samr_ChangePasswordUser3_reject,0);
return offset;
}
static int
samr_dissect_ChangePasswordUser3_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="ChangePasswordUser3";
offset = samr_dissect_element_ChangePasswordUser3_dominfo(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_reject(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_ChangePasswordUser3_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="ChangePasswordUser3";
offset = samr_dissect_element_ChangePasswordUser3_server(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_account(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_nt_password(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_nt_verifier(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_lm_change(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_lm_password(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_lm_verifier(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ChangePasswordUser3_password3(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_Connect5_system_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect5_system_name_, NDR_POINTER_UNIQUE, "Pointer to System Name (uint16)",hf_samr_samr_Connect5_system_name);
return offset;
}
static int
samr_dissect_element_Connect5_system_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_samr_samr_Connect5_system_name, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
samr_dissect_element_Connect5_access_mask(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_bitmap_ConnectAccessMask(tvb, offset, pinfo, tree, drep, hf_samr_connect_access_mask, 0);
return offset;
}
static int
samr_dissect_element_Connect5_level_in(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect5_level_in, 0);
return offset;
}
static int
samr_dissect_element_Connect5_info_in(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect5_info_in_, NDR_POINTER_REF, "Pointer to Info In (samr_ConnectInfo)",hf_samr_samr_Connect5_info_in);
return offset;
}
static int
samr_dissect_element_Connect5_info_in_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_ConnectInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect5_info_in, 0);
return offset;
}
static int
samr_dissect_element_Connect5_level_out(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect5_level_out_, NDR_POINTER_REF, "Pointer to Level Out (uint32)",hf_samr_samr_Connect5_level_out);
return offset;
}
static int
samr_dissect_element_Connect5_level_out_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect5_level_out, 0);
return offset;
}
static int
samr_dissect_element_Connect5_info_out(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect5_info_out_, NDR_POINTER_REF, "Pointer to Info Out (samr_ConnectInfo)",hf_samr_samr_Connect5_info_out);
return offset;
}
static int
samr_dissect_element_Connect5_info_out_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_ConnectInfo(tvb, offset, pinfo, tree, drep, hf_samr_samr_Connect5_info_out, 0);
return offset;
}
static int
samr_dissect_element_Connect5_connect_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_Connect5_connect_handle_, NDR_POINTER_REF, "Pointer to Connect Handle (policy_handle)",hf_samr_connect_handle);
return offset;
}
static int
samr_dissect_element_Connect5_connect_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_connect_handle, PIDL_POLHND_OPEN|PIDL_POLHND_TYPE_SAMR_CONNECT);
return offset;
}
static int
samr_dissect_Connect5_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="Connect5";
offset = samr_dissect_element_Connect5_level_out(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect5_info_out(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect5_connect_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_Connect5_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="Connect5";
offset = samr_dissect_element_Connect5_system_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect5_access_mask(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect5_level_in(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_Connect5_info_in(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_RidToSid_domain_handle(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidToSid_domain_handle_, NDR_POINTER_REF, "Pointer to Domain Handle (policy_handle)",hf_samr_domain_handle);
return offset;
}
static int
samr_dissect_element_RidToSid_domain_handle_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_samr_domain_handle, 0);
return offset;
}
static int
samr_dissect_element_RidToSid_rid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_rid, 0);
return offset;
}
static int
samr_dissect_element_RidToSid_sid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidToSid_sid_, NDR_POINTER_REF, "Pointer to Sid (dom_sid2)",hf_samr_samr_RidToSid_sid);
return offset;
}
static int
samr_dissect_element_RidToSid_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_RidToSid_sid__, NDR_POINTER_UNIQUE, "Pointer to Sid (dom_sid2)",hf_samr_samr_RidToSid_sid);
return offset;
}
static int
samr_dissect_element_RidToSid_sid__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=cnf_dissect_dom_sid2(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
samr_dissect_RidToSid_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="RidToSid";
offset = samr_dissect_element_RidToSid_sid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_RidToSid_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="RidToSid";
offset = samr_dissect_element_RidToSid_domain_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_RidToSid_rid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_SetDsrmPassword_name(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetDsrmPassword_name_, NDR_POINTER_UNIQUE, "Pointer to Name (lsa_String)",hf_samr_samr_SetDsrmPassword_name);
return offset;
}
static int
samr_dissect_element_SetDsrmPassword_name_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset=dissect_ndr_lsa_String(tvb, offset, pinfo, tree, drep, 0, hf_samr_samr_SetDsrmPassword_name);
return offset;
}
static int
samr_dissect_element_SetDsrmPassword_unknown(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_samr_samr_SetDsrmPassword_unknown, 0);
return offset;
}
static int
samr_dissect_element_SetDsrmPassword_hash(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_SetDsrmPassword_hash_, NDR_POINTER_UNIQUE, "Pointer to Hash (samr_Password)",hf_samr_samr_SetDsrmPassword_hash);
return offset;
}
static int
samr_dissect_element_SetDsrmPassword_hash_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_struct_Password(tvb,offset,pinfo,tree,drep,hf_samr_samr_SetDsrmPassword_hash,0);
return offset;
}
static int
samr_dissect_SetDsrmPassword_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="SetDsrmPassword";
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_SetDsrmPassword_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="SetDsrmPassword";
offset = samr_dissect_element_SetDsrmPassword_name(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetDsrmPassword_unknown(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_SetDsrmPassword_hash(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
samr_dissect_element_ValidatePassword_level(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_enum_ValidatePasswordLevel(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePassword_level, 0);
return offset;
}
static int
samr_dissect_element_ValidatePassword_req(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidatePassword_req_, NDR_POINTER_REF, "Pointer to Req (samr_ValidatePasswordReq)",hf_samr_samr_ValidatePassword_req);
return offset;
}
static int
samr_dissect_element_ValidatePassword_req_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_ValidatePasswordReq(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePassword_req, 0);
return offset;
}
static int
samr_dissect_element_ValidatePassword_rep(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidatePassword_rep_, NDR_POINTER_REF, "Pointer to Rep (samr_ValidatePasswordRep)",hf_samr_samr_ValidatePassword_rep);
return offset;
}
static int
samr_dissect_element_ValidatePassword_rep_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, samr_dissect_element_ValidatePassword_rep__, NDR_POINTER_UNIQUE, "Pointer to Rep (samr_ValidatePasswordRep)",hf_samr_samr_ValidatePassword_rep);
return offset;
}
static int
samr_dissect_element_ValidatePassword_rep__(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = samr_dissect_ValidatePasswordRep(tvb, offset, pinfo, tree, drep, hf_samr_samr_ValidatePassword_rep, 0);
return offset;
}
static int
samr_dissect_ValidatePassword_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="ValidatePassword";
offset = samr_dissect_element_ValidatePassword_rep(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep, hf_samr_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, NT_errors, "Unknown NT status 0x%08x"));
return offset;
}
static int
samr_dissect_ValidatePassword_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="ValidatePassword";
offset = samr_dissect_element_ValidatePassword_level(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = samr_dissect_element_ValidatePassword_req(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
void proto_register_dcerpc_samr(void)
{
static hf_register_info hf[] = {
{ &hf_samr_samr_QueryDisplayInfo2_level,
{ "Level", "samr.samr_QueryDisplayInfo2.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainDisplayInformation_vals), 0, NULL, HFILL }},
{ &hf_samr_rid,
{ "RID", "samr.rid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect2_system_name,
{ "System Name", "samr.samr_Connect2.system_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_DONT_REQUIRE_PREAUTH,
{ "Acb Dont Require Preauth", "samr.samr_AcctFlags.ACB_DONT_REQUIRE_PREAUTH", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_DONT_REQUIRE_PREAUTH_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_samr_group_access_mask,
{ "Access Mask", "samr.group.access_mask", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_oem,
{ "Oem", "samr.samr_DomainInfo.oem", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfoAscii_entries,
{ "Entries", "samr.samr_DispInfoAscii.entries", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryAliasInfo_level,
{ "Level", "samr.samr_QueryAliasInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_AliasInfoEnum_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryFullGroup_idx,
{ "Idx", "samr.samr_DispEntryFullGroup.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryGroupInfo_info,
{ "Info", "samr.samr_QueryGroupInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LOGON_SCRIPT,
{ "Samr Field Logon Script", "samr.samr_FieldsPresent.SAMR_FIELD_LOGON_SCRIPT", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LOGON_SCRIPT_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_primary_gid,
{ "Primary Gid", "samr.samr_UserInfo21.primary_gid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation2_lockout_duration,
{ "Lockout Duration", "samr.samr_DomGeneralInformation2.lockout_duration", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCT_EXPIRY,
{ "Samr Field Acct Expiry", "samr.samr_FieldsPresent.SAMR_FIELD_ACCT_EXPIRY", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_ACCT_EXPIRY_tfs), ( 0x00080000 ), NULL, HFILL }},
{ &hf_samr_samr_DispInfoGeneral_count,
{ "Count", "samr.samr_DispInfoGeneral.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_total_size,
{ "Total Size", "samr.samr_QueryDisplayInfo3.total_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetDomPwInfo_info,
{ "Info", "samr.samr_GetDomPwInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QuerySecurity_sdbuf,
{ "Sdbuf", "samr.samr_QuerySecurity.sdbuf", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_workstations,
{ "Workstations", "samr.samr_UserInfo3.workstations", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryUserInfo2_info,
{ "Info", "samr.samr_QueryUserInfo2.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_start_idx,
{ "Start Idx", "samr.samr_QueryDisplayInfo3.start_idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_PARAMETERS,
{ "Samr Field Parameters", "samr.samr_FieldsPresent.SAMR_FIELD_PARAMETERS", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_PARAMETERS_tfs), ( 0x00200000 ), NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_num_users,
{ "Num Users", "samr.samr_DomGeneralInformation.num_users", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_ALIAS,
{ "Samr Domain Access Lookup Alias", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_LOOKUP_ALIAS", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_ALIAS_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_acct_flags,
{ "Acct Flags", "samr.samr_UserInfo21.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_profile_path,
{ "Profile Path", "samr.samr_UserInfo5.profile_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_PW_EXPIRED,
{ "Acb Pw Expired", "samr.samr_AcctFlags.ACB_PW_EXPIRED", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_PW_EXPIRED_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_hash,
{ "Hash", "samr.samr_ValidatePasswordReq3.hash", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDomainInfo_info,
{ "Info", "samr.samr_QueryDomainInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info16,
{ "Info16", "samr.samr_UserInfo.info16", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetBootKeyInformation_unknown1,
{ "Unknown1", "samr.samr_SetBootKeyInformation.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfo_attributes,
{ "Attributes", "samr.samr_GroupInfo.attributes", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo3_force_logoff_time,
{ "Force Logoff Time", "samr.samr_DomInfo3.force_logoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_new_nt_crypted,
{ "New Nt Crypted", "samr.samr_ChangePasswordUser.new_nt_crypted", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_reject,
{ "Reject", "samr.samr_ChangePasswordUser3.reject", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDomainInfo2_info,
{ "Info", "samr.samr_QueryDomainInfo2.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo1_description,
{ "Description", "samr.samr_UserInfo1.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetAliasInfo_info,
{ "Info", "samr.samr_SetAliasInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_cross1_present,
{ "Cross1 Present", "samr.samr_ChangePasswordUser.cross1_present", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_primary_gid,
{ "Primary Gid", "samr.samr_UserInfo5.primary_gid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_NO_CLEAR_CHANGE,
{ "Domain Password No Clear Change", "samr.samr_PasswordProperties.DOMAIN_PASSWORD_NO_CLEAR_CHANGE", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_PASSWORD_NO_CLEAR_CHANGE_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_OPEN_ACCOUNT,
{ "Samr Domain Access Open Account", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_OPEN_ACCOUNT", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_OPEN_ACCOUNT_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_samr_samr_Connect4_system_name,
{ "System Name", "samr.samr_Connect4.system_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_buf_size,
{ "Buf Size", "samr.samr_QueryDisplayInfo3.buf_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_NUM_LOGONS,
{ "Samr Field Num Logons", "samr.samr_FieldsPresent.SAMR_FIELD_NUM_LOGONS", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_NUM_LOGONS_tfs), ( 0x00008000 ), NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_COUNT,
{ "Samr Validate Field Bad Password Count", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_BAD_PASSWORD_COUNT", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_COUNT_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_PWD_CHANGE,
{ "Samr Field Last Pwd Change", "samr.samr_FieldsPresent.SAMR_FIELD_LAST_PWD_CHANGE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LAST_PWD_CHANGE_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo20_parameters,
{ "Parameters", "samr.samr_UserInfo20.parameters", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo18_lm_pwd,
{ "Lm Pwd", "samr.samr_UserInfo18.lm_pwd", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo1_account_name,
{ "Account Name", "samr.samr_UserInfo1.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_lm_change,
{ "Lm Change", "samr.samr_ChangePasswordUser2.lm_change", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_description,
{ "Description", "samr.samr_UserInfo21.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_profile_path,
{ "Profile Path", "samr.samr_UserInfo21.profile_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePassword_req,
{ "Req", "samr.samr_ValidatePassword.req", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_DISABLED,
{ "Acb Disabled", "samr.samr_AcctFlags.ACB_DISABLED", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_DISABLED_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_nt_cross,
{ "Nt Cross", "samr.samr_ChangePasswordUser.nt_cross", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangeReject_unknown2,
{ "Unknown2", "samr.samr_ChangeReject.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCOUNT_NAME,
{ "Samr Field Account Name", "samr.samr_FieldsPresent.SAMR_FIELD_ACCOUNT_NAME", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_ACCOUNT_NAME_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo2_unknown,
{ "Unknown", "samr.samr_UserInfo2.unknown", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_password,
{ "Password", "samr.samr_ValidatePasswordReq3.password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_logon_script,
{ "Logon Script", "samr.samr_UserInfo5.logon_script", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_RidWithAttributeArray_count,
{ "Count", "samr.samr_RidWithAttributeArray.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_pwd_history_len,
{ "Pwd History Len", "samr.samr_ValidatePasswordInfo.pwd_history_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfoFullGroups_entries,
{ "Entries", "samr.samr_DispInfoFullGroups.entries", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_bad_password_count,
{ "Bad Password Count", "samr.samr_UserInfo5.bad_password_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info5,
{ "Info5", "samr.samr_DomainInfo.info5", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_ADD_MEMBER,
{ "Samr Alias Access Add Member", "samr.samr_AliasAccessMask.SAMR_ALIAS_ACCESS_ADD_MEMBER", FT_BOOLEAN, 32, TFS(&samr_AliasAccessMask_SAMR_ALIAS_ACCESS_ADD_MEMBER_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info6,
{ "Info6", "samr.samr_UserInfo.info6", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect5_info_out,
{ "Info Out", "samr.samr_Connect5.info_out", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_logon_script,
{ "Logon Script", "samr.samr_UserInfo3.logon_script", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetUserInfo_level,
{ "Level", "samr.samr_SetUserInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_UserInfoLevel_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_last_logon,
{ "Last Logon", "samr.samr_UserInfo21.last_logon", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetBootKeyInformation_domain_handle,
{ "Domain Handle", "samr.samr_GetBootKeyInformation.domain_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_lm_password,
{ "Lm Password", "samr.samr_UserInfo21.lm_password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_returned_size,
{ "Returned Size", "samr.samr_QueryDisplayInfo3.returned_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_account,
{ "Account", "samr.samr_ValidatePasswordReq3.account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo7_account_name,
{ "Account Name", "samr.samr_UserInfo7.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo23_info,
{ "Info", "samr.samr_UserInfo23.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_1,
{ "Samr Domain Access Set Info 1", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_SET_INFO_1", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_1_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_last_logon,
{ "Last Logon", "samr.samr_UserInfo3.last_logon", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info10,
{ "Info10", "samr.samr_UserInfo.info10", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainGroups_max_size,
{ "Max Size", "samr.samr_EnumDomainGroups.max_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_NO_ANON_CHANGE,
{ "Domain Password No Anon Change", "samr.samr_PasswordProperties.DOMAIN_PASSWORD_NO_ANON_CHANGE", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_PASSWORD_NO_ANON_CHANGE_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_full_name,
{ "Full Name", "samr.samr_UserInfo3.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryAscii_account_name,
{ "Account Name", "samr.samr_DispEntryAscii.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo11_logon_script,
{ "Logon Script", "samr.samr_UserInfo11.logon_script", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_TRUST_AUTH_DELEGAT,
{ "Acb Trust Auth Delegat", "samr.samr_AcctFlags.ACB_TRUST_AUTH_DELEGAT", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_TRUST_AUTH_DELEGAT_tfs), ( 0x00040000 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_lm_present,
{ "Lm Present", "samr.samr_ChangePasswordUser.lm_present", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AddMultipleMembersToAlias_sids,
{ "Sids", "samr.samr_AddMultipleMembersToAlias.sids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo13_sequence_num,
{ "Sequence Num", "samr.samr_DomInfo13.sequence_num", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info21,
{ "Info21", "samr.samr_UserInfo.info21", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq_req1,
{ "Req1", "samr.samr_ValidatePasswordReq.req1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_MNS,
{ "Acb Mns", "samr.samr_AcctFlags.ACB_MNS", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_MNS_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_DispEntryFullGroup_description,
{ "Description", "samr.samr_DispEntryFullGroup.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetSecurity_sdbuf,
{ "Sdbuf", "samr.samr_SetSecurity.sdbuf", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq2_account,
{ "Account", "samr.samr_ValidatePasswordReq2.account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupNames_names,
{ "Names", "samr.samr_LookupNames.names", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_REFUSE_PASSWORD_CHANGE,
{ "Domain Refuse Password Change", "samr.samr_PasswordProperties.DOMAIN_REFUSE_PASSWORD_CHANGE", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_REFUSE_PASSWORD_CHANGE_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_GROUP_MEMBERSHIP,
{ "Samr User Access Change Group Membership", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_CHANGE_GROUP_MEMBERSHIP", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_GROUP_MEMBERSHIP_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_samr_samr_PwInfo_password_properties,
{ "Password Properties", "samr.samr_PwInfo.password_properties", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq_req2,
{ "Req2", "samr.samr_ValidatePasswordReq.req2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation2_lockout_window,
{ "Lockout Window", "samr.samr_DomGeneralInformation2.lockout_window", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_returned_size,
{ "Returned Size", "samr.samr_QueryDisplayInfo2.returned_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetBootKeyInformation_unknown2,
{ "Unknown2", "samr.samr_SetBootKeyInformation.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_LOGON,
{ "Samr Field Last Logon", "samr.samr_FieldsPresent.SAMR_FIELD_LAST_LOGON", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LAST_LOGON_tfs), ( 0x00000800 ), NULL, HFILL }},
{ &hf_samr_samr_Ids_count,
{ "Count", "samr.samr_Ids.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_LOC_COM,
{ "Samr User Access Set Loc Com", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_SET_LOC_COM", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_SET_LOC_COM_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_SMARTCARD_REQUIRED,
{ "Acb Smartcard Required", "samr.samr_AcctFlags.ACB_SMARTCARD_REQUIRED", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_SMARTCARD_REQUIRED_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_nt_verifier,
{ "Nt Verifier", "samr.samr_ChangePasswordUser3.nt_verifier", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info17,
{ "Info17", "samr.samr_UserInfo.info17", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupRids_types,
{ "Types", "samr.samr_LookupRids.types", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_PROFILE_PATH,
{ "Samr Field Profile Path", "samr.samr_FieldsPresent.SAMR_FIELD_PROFILE_PATH", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_PROFILE_PATH_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_lm_change,
{ "Lm Change", "samr.samr_ChangePasswordUser3.lm_change", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo1_primary_gid,
{ "Primary Gid", "samr.samr_UserInfo1.primary_gid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq1_info,
{ "Info", "samr.samr_ValidatePasswordReq1.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_home_drive,
{ "Home Drive", "samr.samr_UserInfo21.home_drive", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_PWNOEXP,
{ "Acb Pwnoexp", "samr.samr_AcctFlags.ACB_PWNOEXP", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_PWNOEXP_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_samr_samr_DomOEMInformation_oem_information,
{ "Oem Information", "samr.samr_DomOEMInformation.oem_information", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_group_handle,
{ "Group Handle", "samr.group_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainAliases_num_entries,
{ "Num Entries", "samr.samr_EnumDomainAliases.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_SVRTRUST,
{ "Acb Svrtrust", "samr.samr_AcctFlags.ACB_SVRTRUST", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_SVRTRUST_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_oem_information,
{ "Oem Information", "samr.samr_DomGeneralInformation.oem_information", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info8,
{ "Info8", "samr.samr_UserInfo.info8", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo25_info,
{ "Info", "samr.samr_UserInfo25.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUP_MEMBERSHIP,
{ "Samr User Access Get Group Membership", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_GROUP_MEMBERSHIP", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUP_MEMBERSHIP_tfs), ( 0x00000200 ), NULL, HFILL }},
{ &hf_samr_samr_CreateDomainGroup_name,
{ "Name", "samr.samr_CreateDomainGroup.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_num_groups,
{ "Num Groups", "samr.samr_DomGeneralInformation.num_groups", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetGroupInfo_info,
{ "Info", "samr.samr_SetGroupInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_lsa_Strings_names,
{ "Names", "samr.lsa_Strings.names", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainAliases_resume_handle,
{ "Resume Handle", "samr.samr_EnumDomainAliases.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_num_aliases,
{ "Num Aliases", "samr.samr_DomGeneralInformation.num_aliases", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainAliases_max_size,
{ "Max Size", "samr.samr_EnumDomainAliases.max_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_full_name,
{ "Full Name", "samr.samr_UserInfo21.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetDomPwInfo_domain_name,
{ "Domain Name", "samr.samr_GetDomPwInfo.domain_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_primary_gid,
{ "Primary Gid", "samr.samr_UserInfo3.primary_gid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_LOOKUP_INFO,
{ "Samr Alias Access Lookup Info", "samr.samr_AliasAccessMask.SAMR_ALIAS_ACCESS_LOOKUP_INFO", FT_BOOLEAN, 32, TFS(&samr_AliasAccessMask_SAMR_ALIAS_ACCESS_LOOKUP_INFO_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info5,
{ "Info5", "samr.samr_UserInfo.info5", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_home_directory,
{ "Home Directory", "samr.samr_UserInfo3.home_directory", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_cross2_present,
{ "Cross2 Present", "samr.samr_ChangePasswordUser.cross2_present", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DeleteAliasMember_sid,
{ "Sid", "samr.samr_DeleteAliasMember.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePassword_rep,
{ "Rep", "samr.samr_ValidatePassword.rep", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_fields_present,
{ "Fields Present", "samr.samr_ValidatePasswordInfo.fields_present", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_REMOVE_MEMBER,
{ "Samr Group Access Remove Member", "samr.samr_GroupAccessMask.SAMR_GROUP_ACCESS_REMOVE_MEMBER", FT_BOOLEAN, 32, TFS(&samr_GroupAccessMask_SAMR_GROUP_ACCESS_REMOVE_MEMBER_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_SetMemberAttributesOfGroup_unknown1,
{ "Unknown1", "samr.samr_SetMemberAttributesOfGroup.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex2_level,
{ "Level", "samr.samr_GetDisplayEnumerationIndex2.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainDisplayInformation_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_ENC_TXT_PWD_ALLOWED,
{ "Acb Enc Txt Pwd Allowed", "samr.samr_AcctFlags.ACB_ENC_TXT_PWD_ALLOWED", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_ENC_TXT_PWD_ALLOWED_tfs), ( 0x00000800 ), NULL, HFILL }},
{ &hf_samr_samr_AliasInfo_description,
{ "Description", "samr.samr_AliasInfo.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_info,
{ "Info", "samr.samr_QueryDisplayInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfoAll_num_members,
{ "Num Members", "samr.samr_GroupInfoAll.num_members", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_status,
{ "NT Error", "samr.status", FT_UINT32, BASE_HEX, VALS(NT_errors), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo12_profile_path,
{ "Profile Path", "samr.samr_UserInfo12.profile_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_comment,
{ "Comment", "samr.samr_UserInfo21.comment", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_2,
{ "Samr Domain Access Set Info 2", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_SET_INFO_2", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_2_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info14,
{ "Info14", "samr.samr_UserInfo.info14", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_CreateUser2_access_granted,
{ "Access Granted", "samr.samr_CreateUser2.access_granted", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectInfo1_client_version,
{ "Client Version", "samr.samr_ConnectInfo1.client_version", FT_UINT32, BASE_DEC, VALS(samr_samr_ConnectVersion_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_acct_flags,
{ "Acct Flags", "samr.samr_UserInfo5.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo24_password_expired,
{ "Password Expired", "samr.samr_UserInfo24.password_expired", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_NOT_DELEGATED,
{ "Acb Not Delegated", "samr.samr_AcctFlags.ACB_NOT_DELEGATED", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_NOT_DELEGATED_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_samr_samr_SetDsrmPassword_name,
{ "Name", "samr.samr_SetDsrmPassword.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect_system_name,
{ "System Name", "samr.samr_Connect.system_name", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo1_min_password_age,
{ "Min Password Age", "samr.samr_DomInfo1.min_password_age", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupRids_num_rids,
{ "Num Rids", "samr.samr_LookupRids.num_rids", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfoDescription_description,
{ "Description", "samr.samr_GroupInfoDescription.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryUserInfo_level,
{ "Level", "samr.samr_QueryUserInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_UserInfoLevel_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_LOGON_ID,
{ "Se Group Logon Id", "samr.samr_GroupAttrs.SE_GROUP_LOGON_ID", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_LOGON_ID_tfs), ( 0xC0000000 ), NULL, HFILL }},
{ &hf_samr_samr_DispEntryGeneral_account_name,
{ "Account Name", "samr.samr_DispEntryGeneral.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_HOMDIRREQ,
{ "Acb Homdirreq", "samr.samr_AcctFlags.ACB_HOMDIRREQ", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_HOMDIRREQ_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_CryptPasswordEx_data,
{ "Data", "samr.samr_CryptPasswordEx.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_bad_password_time,
{ "Bad Password Time", "samr.samr_ValidatePasswordInfo.bad_password_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_USE_DES_KEY_ONLY,
{ "Acb Use Des Key Only", "samr.samr_AcctFlags.ACB_USE_DES_KEY_ONLY", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_USE_DES_KEY_ONLY_tfs), ( 0x00008000 ), NULL, HFILL }},
{ &hf_samr_samr_DispInfo_info1,
{ "Info1", "samr.samr_DispInfo.info1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetDomainInfo_level,
{ "Level", "samr.samr_SetDomainInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainInfoClass_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfo_info4,
{ "Info4", "samr.samr_DispInfo.info4", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo8_domain_create_time,
{ "Domain Create Time", "samr.samr_DomInfo8.domain_create_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_private,
{ "Private", "samr.samr_UserInfo21.private", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_old_nt_crypted,
{ "Old Nt Crypted", "samr.samr_ChangePasswordUser.old_nt_crypted", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_force_logoff_time,
{ "Force Logoff Time", "samr.samr_DomGeneralInformation.force_logoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo12_lockout_threshold,
{ "Lockout Threshold", "samr.samr_DomInfo12.lockout_threshold", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfoAttributes_attributes,
{ "Attributes", "samr.samr_GroupInfoAttributes.attributes", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SamArray_entries,
{ "Entries", "samr.samr_SamArray.entries", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info9,
{ "Info9", "samr.samr_UserInfo.info9", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_lm_password,
{ "Lm Password", "samr.samr_ChangePasswordUser2.lm_password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryGeneral_full_name,
{ "Full Name", "samr.samr_DispEntryGeneral.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_domain_handle,
{ "Domain Handle", "samr.domain_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation2_general,
{ "General", "samr.samr_DomGeneralInformation2.general", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasInfoAll_num_members,
{ "Num Members", "samr.samr_AliasInfoAll.num_members", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_SET_INFO,
{ "Samr Group Access Set Info", "samr.samr_GroupAccessMask.SAMR_GROUP_ACCESS_SET_INFO", FT_BOOLEAN, 32, TFS(&samr_GroupAccessMask_SAMR_GROUP_ACCESS_SET_INFO_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_DispEntryFull_description,
{ "Description", "samr.samr_DispEntryFull.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupDomain_domain_name,
{ "Domain Name", "samr.samr_LookupDomain.domain_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordRep_ctr3,
{ "Ctr3", "samr.samr_ValidatePasswordRep.ctr3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_user_handle,
{ "User Handle", "samr.user_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_max_entries,
{ "Max Entries", "samr.samr_QueryDisplayInfo3.max_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo6_primary,
{ "Primary", "samr.samr_DomInfo6.primary", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_COMPLEX,
{ "Domain Password Complex", "samr.samr_PasswordProperties.DOMAIN_PASSWORD_COMPLEX", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_PASSWORD_COMPLEX_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_domain_access_mask,
{ "Access Mask", "samr.domain.access_mask", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect5_system_name,
{ "System Name", "samr.samr_Connect5.system_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_bad_password_count,
{ "Bad Password Count", "samr.samr_UserInfo21.bad_password_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_acct_expiry,
{ "Acct Expiry", "samr.samr_UserInfo21.acct_expiry", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainUsers_max_size,
{ "Max Size", "samr.samr_EnumDomainUsers.max_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_ALLOW_PWD_CHANGE,
{ "Samr Field Allow Pwd Change", "samr.samr_FieldsPresent.SAMR_FIELD_ALLOW_PWD_CHANGE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_ALLOW_PWD_CHANGE_tfs), ( 0x00010000 ), NULL, HFILL }},
{ &hf_samr_samr_LookupNames_rids,
{ "Rids", "samr.samr_LookupNames.rids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo1_min_password_length,
{ "Min Password Length", "samr.samr_DomInfo1.min_password_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_pwd_must_change_at_next_logon,
{ "Pwd Must Change At Next Logon", "samr.samr_ValidatePasswordReq3.pwd_must_change_at_next_logon", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_WORKSTATIONS,
{ "Samr Field Workstations", "samr.samr_FieldsPresent.SAMR_FIELD_WORKSTATIONS", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_WORKSTATIONS_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex_idx,
{ "Idx", "samr.samr_GetDisplayEnumerationIndex.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo9_domain_server_state,
{ "Domain Server State", "samr.samr_DomInfo9.domain_server_state", FT_UINT32, BASE_DEC, VALS(samr_samr_DomainServerState_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_Connect5_level_out,
{ "Level Out", "samr.samr_Connect5.level_out", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_last_logon,
{ "Last Logon", "samr.samr_UserInfo5.last_logon", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_server,
{ "Server", "samr.samr_ChangePasswordUser2.server", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetDomainInfo_info,
{ "Info", "samr.samr_SetDomainInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SamArray_count,
{ "Count", "samr.samr_SamArray.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo24_password,
{ "Password", "samr.samr_UserInfo24.password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryFull_idx,
{ "Idx", "samr.samr_DispEntryFull.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_INITIALIZE_SERVER,
{ "Samr Access Initialize Server", "samr.samr_ConnectAccessMask.SAMR_ACCESS_INITIALIZE_SERVER", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_INITIALIZE_SERVER_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_DispEntryFull_acct_flags,
{ "Acct Flags", "samr.samr_DispEntryFull.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo13_modified_count_at_last_promotion,
{ "Modified Count At Last Promotion", "samr.samr_DomInfo13.modified_count_at_last_promotion", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetAliasMembership_sids,
{ "Sids", "samr.samr_GetAliasMembership.sids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info1,
{ "Info1", "samr.samr_UserInfo.info1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_RESOURCE,
{ "Se Group Resource", "samr.samr_GroupAttrs.SE_GROUP_RESOURCE", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_RESOURCE_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_DESCRIPTION,
{ "Samr Field Description", "samr.samr_FieldsPresent.SAMR_FIELD_DESCRIPTION", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_DESCRIPTION_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo18_nt_pwd,
{ "Nt Pwd", "samr.samr_UserInfo18.nt_pwd", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo23_password,
{ "Password", "samr.samr_UserInfo23.password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_last_logoff,
{ "Last Logoff", "samr.samr_UserInfo21.last_logoff", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfo_info2,
{ "Info2", "samr.samr_DispInfo.info2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainUsers_resume_handle,
{ "Resume Handle", "samr.samr_EnumDomainUsers.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordRepCtr_status,
{ "Status", "samr.samr_ValidatePasswordRepCtr.status", FT_UINT1632, BASE_DEC, VALS(samr_samr_ValidationStatus_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_SetMemberAttributesOfGroup_unknown2,
{ "Unknown2", "samr.samr_SetMemberAttributesOfGroup.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_general2,
{ "General2", "samr.samr_DomainInfo.general2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfoFull_count,
{ "Count", "samr.samr_DispInfoFull.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_GET_MEMBERS,
{ "Samr Group Access Get Members", "samr.samr_GroupAccessMask.SAMR_GROUP_ACCESS_GET_MEMBERS", FT_BOOLEAN, 32, TFS(&samr_GroupAccessMask_SAMR_GROUP_ACCESS_GET_MEMBERS_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_COUNTRY_CODE,
{ "Samr Field Country Code", "samr.samr_FieldsPresent.SAMR_FIELD_COUNTRY_CODE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_COUNTRY_CODE_tfs), ( 0x00400000 ), NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq2_password,
{ "Password", "samr.samr_ValidatePasswordReq2.password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_logon_hours,
{ "Logon Hours", "samr.samr_UserInfo5.logon_hours", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_HOME_DIRECTORY,
{ "Samr Field Home Directory", "samr.samr_FieldsPresent.SAMR_FIELD_HOME_DIRECTORY", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_HOME_DIRECTORY_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_NO_AUTH_DATA_REQD,
{ "Acb No Auth Data Reqd", "samr.samr_AcctFlags.ACB_NO_AUTH_DATA_REQD", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_NO_AUTH_DATA_REQD_tfs), ( 0x00080000 ), NULL, HFILL }},
{ &hf_samr_samr_QueryDomainInfo_level,
{ "Level", "samr.samr_QueryDomainInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainInfoClass_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo26_password,
{ "Password", "samr.samr_UserInfo26.password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq1_password_matched,
{ "Password Matched", "samr.samr_ValidatePasswordReq1.password_matched", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_account_name,
{ "Account Name", "samr.samr_UserInfo21.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_ATTRIBUTES,
{ "Samr User Access Get Attributes", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_ATTRIBUTES", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_ATTRIBUTES_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_SET_INFO,
{ "Samr Alias Access Set Info", "samr.samr_AliasAccessMask.SAMR_ALIAS_ACCESS_SET_INFO", FT_BOOLEAN, 32, TFS(&samr_AliasAccessMask_SAMR_ALIAS_ACCESS_SET_INFO_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo2_comment,
{ "Comment", "samr.samr_UserInfo2.comment", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_RID,
{ "Samr Field Rid", "samr.samr_FieldsPresent.SAMR_FIELD_RID", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_RID_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info23,
{ "Info23", "samr.samr_UserInfo.info23", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo18_password_expired,
{ "Password Expired", "samr.samr_UserInfo18.password_expired", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_total_size,
{ "Total Size", "samr.samr_QueryDisplayInfo2.total_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo25_password,
{ "Password", "samr.samr_UserInfo25.password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_lm_verifier,
{ "Lm Verifier", "samr.samr_ChangePasswordUser2.lm_verifier", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo4_logon_hours,
{ "Logon Hours", "samr.samr_UserInfo4.logon_hours", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_home_directory,
{ "Home Directory", "samr.samr_UserInfo5.home_directory", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo12_lockout_duration,
{ "Lockout Duration", "samr.samr_DomInfo12.lockout_duration", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_CreateUser_account_name,
{ "Account Name", "samr.samr_CreateUser.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo9_primary_gid,
{ "Primary Gid", "samr.samr_UserInfo9.primary_gid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOGONINFO,
{ "Samr User Access Get Logoninfo", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_LOGONINFO", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOGONINFO_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_LAST_SET,
{ "Samr Validate Field Password Last Set", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_PASSWORD_LAST_SET", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_LAST_SET_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_domain_name,
{ "Domain Name", "samr.samr_DomGeneralInformation.domain_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_CreateUser2_account_name,
{ "Account Name", "samr.samr_CreateUser2.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_CREATE_DOMAIN,
{ "Samr Access Create Domain", "samr.samr_ConnectAccessMask.SAMR_ACCESS_CREATE_DOMAIN", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_CREATE_DOMAIN_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_LookupDomain_sid,
{ "Sid", "samr.samr_LookupDomain.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AddAliasMember_sid,
{ "Sid", "samr.samr_AddAliasMember.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryAliasInfo_info,
{ "Info", "samr.samr_QueryAliasInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq2_hash,
{ "Hash", "samr.samr_ValidatePasswordReq2.hash", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_fields_present,
{ "Fields Present", "samr.samr_UserInfo21.fields_present", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_EXPIRED_FLAG,
{ "Samr Field Expired Flag", "samr.samr_FieldsPresent.SAMR_FIELD_EXPIRED_FLAG", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_EXPIRED_FLAG_tfs), ( 0x08000000 ), NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq2_password_matched,
{ "Password Matched", "samr.samr_ValidatePasswordReq2.password_matched", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QuerySecurity_sec_info,
{ "Sec Info", "samr.samr_QuerySecurity.sec_info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info12,
{ "Info12", "samr.samr_DomainInfo.info12", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_max_entries,
{ "Max Entries", "samr.samr_QueryDisplayInfo.max_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomains_resume_handle,
{ "Resume Handle", "samr.samr_EnumDomains.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info7,
{ "Info7", "samr.samr_UserInfo.info7", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfo_all2,
{ "All2", "samr.samr_GroupInfo.all2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo1_full_name,
{ "Full Name", "samr.samr_UserInfo1.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainGroups_resume_handle,
{ "Resume Handle", "samr.samr_EnumDomainGroups.resume_handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetUserInfo2_info,
{ "Info", "samr.samr_SetUserInfo2.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_nt_password,
{ "Nt Password", "samr.samr_ChangePasswordUser3.nt_password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_buf_count,
{ "Buf Count", "samr.samr_UserInfo21.buf_count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PwInfo_min_password_length,
{ "Min Password Length", "samr.samr_PwInfo.min_password_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_user_access_mask,
{ "Access Mask", "samr.user.access_mask", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_sequence_num,
{ "Sequence Num", "samr.samr_DomGeneralInformation.sequence_num", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo26_password_expired,
{ "Password Expired", "samr.samr_UserInfo26.password_expired", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_old_lm_crypted,
{ "Old Lm Crypted", "samr.samr_ChangePasswordUser.old_lm_crypted", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_GET_MEMBERS,
{ "Samr Alias Access Get Members", "samr.samr_AliasAccessMask.SAMR_ALIAS_ACCESS_GET_MEMBERS", FT_BOOLEAN, 32, TFS(&samr_AliasAccessMask_SAMR_ALIAS_ACCESS_GET_MEMBERS_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_NORMAL,
{ "Acb Normal", "samr.samr_AcctFlags.ACB_NORMAL", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_NORMAL_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_GroupInfo_all,
{ "All", "samr.samr_GroupInfo.all", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo16_acct_flags,
{ "Acct Flags", "samr.samr_UserInfo16.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo2_country_code,
{ "Country Code", "samr.samr_UserInfo2.country_code", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AddGroupMember_flags,
{ "Flags", "samr.samr_AddGroupMember.flags", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo10_home_directory,
{ "Home Directory", "samr.samr_UserInfo10.home_directory", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_OemChangePasswordUser2_server,
{ "Server", "samr.samr_OemChangePasswordUser2.server", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_PASSWORD,
{ "Samr User Access Change Password", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_CHANGE_PASSWORD", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_CHANGE_PASSWORD_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_samr_samr_AliasInfo_all,
{ "All", "samr.samr_AliasInfo.all", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_TIME,
{ "Samr Validate Field Bad Password Time", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_BAD_PASSWORD_TIME", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_BAD_PASSWORD_TIME_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_ChangeReject_reason,
{ "Reason", "samr.samr_ChangeReject.reason", FT_UINT32, BASE_DEC, VALS(samr_samr_RejectReason_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_NAME_ETC,
{ "Samr User Access Get Name Etc", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_NAME_ETC", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_NAME_ETC_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_password3,
{ "Password3", "samr.samr_ChangePasswordUser3.password3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo13_description,
{ "Description", "samr.samr_UserInfo13.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_lm_password_set,
{ "Lm Password Set", "samr.samr_UserInfo21.lm_password_set", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info2,
{ "Info2", "samr.samr_UserInfo.info2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LogonHours_bits,
{ "Bits", "samr.samr_LogonHours.bits", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_handle,
{ "Handle", "samr.handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_ENABLED_BY_DEFAULT,
{ "Se Group Enabled By Default", "samr.samr_GroupAttrs.SE_GROUP_ENABLED_BY_DEFAULT", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_ENABLED_BY_DEFAULT_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_EnumDomainGroups_sam,
{ "Sam", "samr.samr_EnumDomainGroups.sam", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfoAll_name,
{ "Name", "samr.samr_GroupInfoAll.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordRep_ctr2,
{ "Ctr2", "samr.samr_ValidatePasswordRep.ctr2", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info24,
{ "Info24", "samr.samr_UserInfo.info24", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info3,
{ "Info3", "samr.samr_DomainInfo.info3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainGroups_num_entries,
{ "Num Entries", "samr.samr_EnumDomainGroups.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_PWNOTREQ,
{ "Acb Pwnotreq", "samr.samr_AcctFlags.ACB_PWNOTREQ", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_PWNOTREQ_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_bad_password_count,
{ "Bad Password Count", "samr.samr_UserInfo3.bad_password_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_CODE_PAGE,
{ "Samr Field Code Page", "samr.samr_FieldsPresent.SAMR_FIELD_CODE_PAGE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_CODE_PAGE_tfs), ( 0x00800000 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_new_lm_crypted,
{ "New Lm Crypted", "samr.samr_ChangePasswordUser.new_lm_crypted", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupNames_types,
{ "Types", "samr.samr_LookupNames.types", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SamEntry_idx,
{ "Idx", "samr.samr_SamEntry.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_logon_hours,
{ "Logon Hours", "samr.samr_UserInfo3.logon_hours", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangeReject_unknown1,
{ "Unknown1", "samr.samr_ChangeReject.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_account,
{ "Account", "samr.samr_ChangePasswordUser3.account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo8_sequence_num,
{ "Sequence Num", "samr.samr_DomInfo8.sequence_num", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_pwd_history,
{ "Pwd History", "samr.samr_ValidatePasswordInfo.pwd_history", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect3_unknown,
{ "Unknown", "samr.samr_Connect3.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_LOOKUP_DOMAIN,
{ "Samr Access Lookup Domain", "samr.samr_ConnectAccessMask.SAMR_ACCESS_LOOKUP_DOMAIN", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_LOOKUP_DOMAIN_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex2_idx,
{ "Idx", "samr.samr_GetDisplayEnumerationIndex2.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectInfo1_unknown2,
{ "Unknown2", "samr.samr_ConnectInfo1.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasInfoAll_name,
{ "Name", "samr.samr_AliasInfoAll.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfo_description,
{ "Description", "samr.samr_GroupInfo.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_OWNER,
{ "Se Group Owner", "samr.samr_GroupAttrs.SE_GROUP_OWNER", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_OWNER_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_EnumDomainAliases_sam,
{ "Sam", "samr.samr_EnumDomainAliases.sam", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LogonHours_units_per_week,
{ "Units Per Week", "samr.samr_LogonHours.units_per_week", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_role,
{ "Role", "samr.samr_DomGeneralInformation.role", FT_UINT32, BASE_DEC, VALS(samr_samr_Role_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info13,
{ "Info13", "samr.samr_DomainInfo.info13", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetSecurity_sec_info,
{ "Sec Info", "samr.samr_SetSecurity.sec_info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_buf_size,
{ "Buf Size", "samr.samr_QueryDisplayInfo2.buf_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_STORE_CLEARTEXT,
{ "Domain Password Store Cleartext", "samr.samr_PasswordProperties.DOMAIN_PASSWORD_STORE_CLEARTEXT", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_PASSWORD_STORE_CLEARTEXT_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation2_lockout_threshold,
{ "Lockout Threshold", "samr.samr_DomGeneralInformation2.lockout_threshold", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_last_password_change,
{ "Last Password Change", "samr.samr_UserInfo21.last_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_account,
{ "Account", "samr.samr_ChangePasswordUser2.account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_lm_password,
{ "Lm Password", "samr.samr_ChangePasswordUser3.lm_password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_account_name,
{ "Account Name", "samr.samr_UserInfo3.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect3_system_name,
{ "System Name", "samr.samr_Connect3.system_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info11,
{ "Info11", "samr.samr_UserInfo.info11", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info9,
{ "Info9", "samr.samr_DomainInfo.info9", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SamEntry_name,
{ "Name", "samr.samr_SamEntry.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_lsa_Strings_count,
{ "Count", "samr.lsa_Strings.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_acct_flags,
{ "Acct Flags", "samr.samr_UserInfo3.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_allow_password_change,
{ "Allow Password Change", "samr.samr_UserInfo3.allow_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDomainInfo2_level,
{ "Level", "samr.samr_QueryDomainInfo2.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainInfoClass_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex_name,
{ "Name", "samr.samr_GetDisplayEnumerationIndex.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_info,
{ "Info", "samr.samr_ValidatePasswordReq3.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_lockout_time,
{ "Lockout Time", "samr.samr_ValidatePasswordInfo.lockout_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo17_acct_expiry,
{ "Acct Expiry", "samr.samr_UserInfo17.acct_expiry", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo1_password_history_length,
{ "Password History Length", "samr.samr_DomInfo1.password_history_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryUserInfo_info,
{ "Info", "samr.samr_QueryUserInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_primary,
{ "Primary", "samr.samr_DomGeneralInformation.primary", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_SHUTDOWN_SERVER,
{ "Samr Access Shutdown Server", "samr.samr_ConnectAccessMask.SAMR_ACCESS_SHUTDOWN_SERVER", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_SHUTDOWN_SERVER_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LM_PASSWORD_PRESENT,
{ "Samr Field Lm Password Present", "samr.samr_FieldsPresent.SAMR_FIELD_LM_PASSWORD_PRESENT", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LM_PASSWORD_PRESENT_tfs), ( 0x02000000 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_home_drive,
{ "Home Drive", "samr.samr_UserInfo5.home_drive", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_RemoveMemberFromForeignDomain_sid,
{ "Sid", "samr.samr_RemoveMemberFromForeignDomain.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_FORCE_PWD_CHANGE,
{ "Samr Field Force Pwd Change", "samr.samr_FieldsPresent.SAMR_FIELD_FORCE_PWD_CHANGE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_FORCE_PWD_CHANGE_tfs), ( 0x00020000 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LAST_LOGOFF,
{ "Samr Field Last Logoff", "samr.samr_FieldsPresent.SAMR_FIELD_LAST_LOGOFF", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LAST_LOGOFF_tfs), ( 0x00001000 ), NULL, HFILL }},
{ &hf_samr_samr_RidWithAttributeArray_rids,
{ "Rids", "samr.samr_RidWithAttributeArray.rids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Password_hash,
{ "Hash", "samr.samr_Password.hash", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_OWF_PWD,
{ "Samr Field Owf Pwd", "samr.samr_FieldsPresent.SAMR_FIELD_OWF_PWD", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_OWF_PWD_tfs), ( 0x20000000 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info25,
{ "Info25", "samr.samr_UserInfo.info25", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_home_drive,
{ "Home Drive", "samr.samr_UserInfo3.home_drive", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_start_idx,
{ "Start Idx", "samr.samr_QueryDisplayInfo.start_idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info13,
{ "Info13", "samr.samr_UserInfo.info13", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_nt_password,
{ "Nt Password", "samr.samr_ChangePasswordUser2.nt_password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_bad_pwd_count,
{ "Bad Pwd Count", "samr.samr_ValidatePasswordInfo.bad_pwd_count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryGroupMember_rids,
{ "Rids", "samr.samr_QueryGroupMember.rids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_password_expired,
{ "Password Expired", "samr.samr_UserInfo21.password_expired", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomains_buf_size,
{ "Buf Size", "samr.samr_EnumDomains.buf_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo1_max_password_age,
{ "Max Password Age", "samr.samr_DomInfo1.max_password_age", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_ADD_MEMBER,
{ "Samr Group Access Add Member", "samr.samr_GroupAccessMask.SAMR_GROUP_ACCESS_ADD_MEMBER", FT_BOOLEAN, 32, TFS(&samr_GroupAccessMask_SAMR_GROUP_ACCESS_ADD_MEMBER_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_GroupInfoAll_description,
{ "Description", "samr.samr_GroupInfoAll.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_logon_count,
{ "Logon Count", "samr.samr_UserInfo3.logon_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY,
{ "Samr Validate Field Password History", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_PASSWORD_HISTORY", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_GroupInfo_name,
{ "Name", "samr.samr_GroupInfo.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_force_password_change,
{ "Force Password Change", "samr.samr_UserInfo3.force_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_nt_present,
{ "Nt Present", "samr.samr_ChangePasswordUser.nt_present", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_home_directory,
{ "Home Directory", "samr.samr_UserInfo21.home_directory", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info12,
{ "Info12", "samr.samr_UserInfo.info12", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_OemChangePasswordUser2_password,
{ "Password", "samr.samr_OemChangePasswordUser2.password", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_RidTypeArray_types,
{ "Types", "samr.samr_RidTypeArray.types", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_ALIAS,
{ "Samr Domain Access Create Alias", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_CREATE_ALIAS", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_ALIAS_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_samr_opnum,
{ "Operation", "samr.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_server,
{ "Server", "samr.samr_ChangePasswordUser3.server", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex2_name,
{ "Name", "samr.samr_GetDisplayEnumerationIndex2.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAccessMask_SAMR_GROUP_ACCESS_LOOKUP_INFO,
{ "Samr Group Access Lookup Info", "samr.samr_GroupAccessMask.SAMR_GROUP_ACCESS_LOOKUP_INFO", FT_BOOLEAN, 32, TFS(&samr_GroupAccessMask_SAMR_GROUP_ACCESS_LOOKUP_INFO_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo14_workstations,
{ "Workstations", "samr.samr_UserInfo14.workstations", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfo_info3,
{ "Info3", "samr.samr_DispInfo.info3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info8,
{ "Info8", "samr.samr_DomainInfo.info8", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfoGeneral_entries,
{ "Entries", "samr.samr_DispInfoGeneral.entries", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo8_full_name,
{ "Full Name", "samr.samr_UserInfo8.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_logon_count,
{ "Logon Count", "samr.samr_UserInfo21.logon_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_code_page,
{ "Code Page", "samr.samr_UserInfo21.code_page", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryFullGroup_acct_flags,
{ "Acct Flags", "samr.samr_DispEntryFullGroup.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetUserInfo_info,
{ "Info", "samr.samr_SetUserInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_OpenDomain_sid,
{ "Sid", "samr.samr_OpenDomain.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryFull_account_name,
{ "Account Name", "samr.samr_DispEntryFull.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_LENGTH,
{ "Samr Validate Field Password History Length", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_LENGTH", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_PASSWORD_HISTORY_LENGTH_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_CreateUser2_acct_flags,
{ "Acct Flags", "samr.samr_CreateUser2.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_HOME_DRIVE,
{ "Samr Field Home Drive", "samr.samr_FieldsPresent.SAMR_FIELD_HOME_DRIVE", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_HOME_DRIVE_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info1,
{ "Info1", "samr.samr_DomainInfo.info1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordRep_ctr1,
{ "Ctr1", "samr.samr_ValidatePasswordRep.ctr1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo18_nt_pwd_active,
{ "Nt Pwd Active", "samr.samr_UserInfo18.nt_pwd_active", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_DOMTRUST,
{ "Acb Domtrust", "samr.samr_AcctFlags.ACB_DOMTRUST", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_DOMTRUST_tfs), ( 0x00000040 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser_lm_cross,
{ "Lm Cross", "samr.samr_ChangePasswordUser.lm_cross", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_profile_path,
{ "Profile Path", "samr.samr_UserInfo3.profile_path", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_unknown4,
{ "Unknown4", "samr.samr_UserInfo21.unknown4", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo13_domain_create_time,
{ "Domain Create Time", "samr.samr_DomInfo13.domain_create_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_WSTRUST,
{ "Acb Wstrust", "samr.samr_AcctFlags.ACB_WSTRUST", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_WSTRUST_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_samr_samr_DispEntryAscii_idx,
{ "Idx", "samr.samr_DispEntryAscii.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo5_domain_name,
{ "Domain Name", "samr.samr_DomInfo5.domain_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_logon_count,
{ "Logon Count", "samr.samr_UserInfo5.logon_count", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_last_logoff,
{ "Last Logoff", "samr.samr_UserInfo5.last_logoff", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePassword_level,
{ "Level", "samr.samr_ValidatePassword.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_ValidatePasswordLevel_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo6_full_name,
{ "Full Name", "samr.samr_UserInfo6.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupRids_names,
{ "Names", "samr.samr_LookupRids.names", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo10_home_drive,
{ "Home Drive", "samr.samr_UserInfo10.home_drive", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_ACCT_FLAGS,
{ "Samr Field Acct Flags", "samr.samr_FieldsPresent.SAMR_FIELD_ACCT_FLAGS", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_ACCT_FLAGS_tfs), ( 0x00100000 ), NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUPS,
{ "Samr User Access Get Groups", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_GROUPS", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_GROUPS_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_samr_samr_RemoveMultipleMembersFromAlias_sids,
{ "Sids", "samr.samr_RemoveMultipleMembersFromAlias.sids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_OemChangePasswordUser2_account,
{ "Account", "samr.samr_OemChangePasswordUser2.account", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_ENUM_DOMAINS,
{ "Samr Access Enum Domains", "samr.samr_ConnectAccessMask.SAMR_ACCESS_ENUM_DOMAINS", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_ENUM_DOMAINS_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info4,
{ "Info4", "samr.samr_UserInfo.info4", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_info,
{ "Info", "samr.samr_QueryDisplayInfo2.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo1_password_properties,
{ "Password Properties", "samr.samr_DomInfo1.password_properties", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_logon_script,
{ "Logon Script", "samr.samr_UserInfo21.logon_script", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_AUTOLOCK,
{ "Acb Autolock", "samr.samr_AcctFlags.ACB_AUTOLOCK", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_AUTOLOCK_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_samr_samr_GetBootKeyInformation_unknown,
{ "Unknown", "samr.samr_GetBootKeyInformation.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_RidWithAttribute_attributes,
{ "Attributes", "samr.samr_RidWithAttribute.attributes", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_CryptPassword_data,
{ "Data", "samr.samr_CryptPassword.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasInfo_name,
{ "Name", "samr.samr_AliasInfo.name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_USER,
{ "Samr Domain Access Create User", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_CREATE_USER", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_USER_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_COMMENT,
{ "Samr Field Comment", "samr.samr_FieldsPresent.SAMR_FIELD_COMMENT", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_COMMENT_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_last_password_change,
{ "Last Password Change", "samr.samr_UserInfo3.last_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Shutdown_connect_handle,
{ "Connect Handle", "samr.samr_Shutdown.connect_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_sec_desc_buf_len,
{ "Sec Desc Buf Len", "samr.sec_desc_buf_len", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_ENABLED,
{ "Se Group Enabled", "samr.samr_GroupAttrs.SE_GROUP_ENABLED", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_ENABLED_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_2,
{ "Samr Domain Access Lookup Info 2", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_LOOKUP_INFO_2", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_2_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_ValidationBlob_length,
{ "Length", "samr.samr_ValidationBlob.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryGeneral_idx,
{ "Idx", "samr.samr_DispEntryGeneral.idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_start_idx,
{ "Start Idx", "samr.samr_QueryDisplayInfo2.start_idx", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_logon_hours,
{ "Logon Hours", "samr.samr_UserInfo21.logon_hours", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_country_code,
{ "Country Code", "samr.samr_UserInfo21.country_code", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetDsrmPassword_hash,
{ "Hash", "samr.samr_SetDsrmPassword.hash", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_general,
{ "General", "samr.samr_DomainInfo.general", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_MANDATORY,
{ "Se Group Mandatory", "samr.samr_GroupAttrs.SE_GROUP_MANDATORY", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_MANDATORY_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_description,
{ "Description", "samr.samr_UserInfo5.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo7_role,
{ "Role", "samr.samr_DomInfo7.role", FT_UINT32, BASE_DEC, VALS(samr_samr_Role_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_workstations,
{ "Workstations", "samr.samr_UserInfo21.workstations", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryGeneral_description,
{ "Description", "samr.samr_DispEntryGeneral.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_PRIVATE_DATA,
{ "Samr Field Private Data", "samr.samr_FieldsPresent.SAMR_FIELD_PRIVATE_DATA", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_PRIVATE_DATA_tfs), ( 0x04000000 ), NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_ENUM_ACCOUNTS,
{ "Samr Domain Access Enum Accounts", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_ENUM_ACCOUNTS", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_ENUM_ACCOUNTS_tfs), ( 0x00000100 ), NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq_req3,
{ "Req3", "samr.samr_ValidatePasswordReq.req3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_alias_access_mask,
{ "Access Mask", "samr.alias.access_mask", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser2_nt_verifier,
{ "Nt Verifier", "samr.samr_ChangePasswordUser2.nt_verifier", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_TRUSTED_FOR_DELEGATION,
{ "Acb Trusted For Delegation", "samr.samr_AcctFlags.ACB_TRUSTED_FOR_DELEGATION", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_TRUSTED_FOR_DELEGATION_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_samr_samr_EnumDomains_connect_handle,
{ "Connect Handle", "samr.samr_EnumDomains.connect_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info18,
{ "Info18", "samr.samr_UserInfo.info18", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_force_password_change,
{ "Force Password Change", "samr.samr_UserInfo21.force_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_nt_password,
{ "Nt Password", "samr.samr_UserInfo21.nt_password", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_domain_server_state,
{ "Domain Server State", "samr.samr_DomGeneralInformation.domain_server_state", FT_UINT32, BASE_DEC, VALS(samr_samr_DomainServerState_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_SetBootKeyInformation_unknown3,
{ "Unknown3", "samr.samr_SetBootKeyInformation.unknown3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainUsers_num_entries,
{ "Num Entries", "samr.samr_EnumDomainUsers.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq2_info,
{ "Info", "samr.samr_ValidatePasswordReq2.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_LookupNames_num_names,
{ "Num Names", "samr.samr_LookupNames.num_names", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_level,
{ "Level", "samr.samr_QueryDisplayInfo3.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainDisplayInformation_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_RidTypeArray_count,
{ "Count", "samr.samr_RidTypeArray.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo2_max_entries,
{ "Max Entries", "samr.samr_QueryDisplayInfo2.max_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordInfo_last_password_change,
{ "Last Password Change", "samr.samr_ValidatePasswordInfo.last_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOCALE,
{ "Samr User Access Get Locale", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_GET_LOCALE", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_GET_LOCALE_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_LOGON_HOURS,
{ "Samr Field Logon Hours", "samr.samr_FieldsPresent.SAMR_FIELD_LOGON_HOURS", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_LOGON_HOURS_tfs), ( 0x00002000 ), NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_dominfo,
{ "Dominfo", "samr.samr_ChangePasswordUser3.dominfo", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidationBlob_data,
{ "Data", "samr.samr_ValidationBlob.data", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo18_lm_pwd_active,
{ "Lm Pwd Active", "samr.samr_UserInfo18.lm_pwd_active", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info26,
{ "Info26", "samr.samr_UserInfo.info26", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GroupInfoAll_attributes,
{ "Attributes", "samr.samr_GroupInfoAll.attributes", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info7,
{ "Info7", "samr.samr_DomainInfo.info7", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectAccessMask_SAMR_ACCESS_CONNECT_TO_SERVER,
{ "Samr Access Connect To Server", "samr.samr_ConnectAccessMask.SAMR_ACCESS_CONNECT_TO_SERVER", FT_BOOLEAN, 32, TFS(&samr_ConnectAccessMask_SAMR_ACCESS_CONNECT_TO_SERVER_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_EnumDomains_num_entries,
{ "Num Entries", "samr.samr_EnumDomains.num_entries", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_parameters,
{ "Parameters", "samr.samr_UserInfo21.parameters", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryGeneral_acct_flags,
{ "Acct Flags", "samr.samr_DispEntryGeneral.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_connect_handle,
{ "Connect Handle", "samr.connect_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AcctFlags_ACB_TEMPDUP,
{ "Acb Tempdup", "samr.samr_AcctFlags.ACB_TEMPDUP", FT_BOOLEAN, 32, TFS(&samr_AcctFlags_ACB_TEMPDUP_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_DispInfoFullGroups_count,
{ "Count", "samr.samr_DispInfoFullGroups.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_1,
{ "Samr Domain Access Lookup Info 1", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_LOOKUP_INFO_1", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_LOOKUP_INFO_1_tfs), ( 0x00000001 ), NULL, HFILL }},
{ &hf_samr_samr_GetAliasMembership_rids,
{ "Rids", "samr.samr_GetAliasMembership.rids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo6_account_name,
{ "Account Name", "samr.samr_UserInfo6.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_connect_access_mask,
{ "Access Mask", "samr.connect.access_mask", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info3,
{ "Info3", "samr.samr_UserInfo.info3", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect5_level_in,
{ "Level In", "samr.samr_Connect5.level_in", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomInfo12_lockout_window,
{ "Lockout Window", "samr.samr_DomInfo12.lockout_window", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_RidToSid_sid,
{ "Sid", "samr.samr_RidToSid.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_SEC_DESC,
{ "Samr Field Sec Desc", "samr.samr_FieldsPresent.SAMR_FIELD_SEC_DESC", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_SEC_DESC_tfs), ( 0x10000000 ), NULL, HFILL }},
{ &hf_samr_samr_GetUserPwInfo_info,
{ "Info", "samr.samr_GetUserPwInfo.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainUsers_acct_flags,
{ "Acct Flags", "samr.samr_EnumDomainUsers.acct_flags", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainInfo_info6,
{ "Info6", "samr.samr_DomainInfo.info6", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_CreateDomAlias_alias_name,
{ "Alias Name", "samr.samr_CreateDomAlias.alias_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomainUsers_sam,
{ "Sam", "samr.samr_EnumDomainUsers.sam", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfo_info5,
{ "Info5", "samr.samr_DispInfo.info5", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetGroupsForUser_rids,
{ "Rids", "samr.samr_GetGroupsForUser.rids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo3_last_logoff,
{ "Last Logoff", "samr.samr_UserInfo3.last_logoff", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordRepCtr_info,
{ "Info", "samr.samr_ValidatePasswordRepCtr.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_SetGroupInfo_level,
{ "Level", "samr.samr_SetGroupInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_GroupInfoEnum_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_NT_PASSWORD_PRESENT,
{ "Samr Field Nt Password Present", "samr.samr_FieldsPresent.SAMR_FIELD_NT_PASSWORD_PRESENT", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_NT_PASSWORD_PRESENT_tfs), ( 0x01000000 ), NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_PASSWORD,
{ "Samr User Access Set Password", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_SET_PASSWORD", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_SET_PASSWORD_tfs), ( 0x00000080 ), NULL, HFILL }},
{ &hf_samr_samr_SetUserInfo2_level,
{ "Level", "samr.samr_SetUserInfo2.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_UserInfoLevel_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_acct_expiry,
{ "Acct Expiry", "samr.samr_UserInfo5.acct_expiry", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect5_info_in,
{ "Info In", "samr.samr_Connect5.info_in", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_nt_password_set,
{ "Nt Password Set", "samr.samr_UserInfo21.nt_password_set", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo_info20,
{ "Info20", "samr.samr_UserInfo.info20", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_alias_handle,
{ "Alias Handle", "samr.alias_handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_account_name,
{ "Account Name", "samr.samr_UserInfo5.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispInfoFull_entries,
{ "Entries", "samr.samr_DispInfoFull.entries", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_full_name,
{ "Full Name", "samr.samr_UserInfo5.full_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ChangePasswordUser3_lm_verifier,
{ "Lm Verifier", "samr.samr_ChangePasswordUser3.lm_verifier", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_PRIMARY_GID,
{ "Samr Field Primary Gid", "samr.samr_FieldsPresent.SAMR_FIELD_PRIMARY_GID", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_PRIMARY_GID_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_3,
{ "Samr Domain Access Set Info 3", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_SET_INFO_3", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_SET_INFO_3_tfs), ( 0x00000400 ), NULL, HFILL }},
{ &hf_samr_samr_GroupAttrs_SE_GROUP_USE_FOR_DENY_ONLY,
{ "Se Group Use For Deny Only", "samr.samr_GroupAttrs.SE_GROUP_USE_FOR_DENY_ONLY", FT_BOOLEAN, 32, TFS(&samr_GroupAttrs_SE_GROUP_USE_FOR_DENY_ONLY_tfs), ( 0x00000010 ), NULL, HFILL }},
{ &hf_samr_samr_DispInfoAscii_count,
{ "Count", "samr.samr_DispInfoAscii.count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_GetMembersInAlias_sids,
{ "Sids", "samr.samr_GetMembersInAlias.sids", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo3_info,
{ "Info", "samr.samr_QueryDisplayInfo3.info", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_OemChangePasswordUser2_hash,
{ "Hash", "samr.samr_OemChangePasswordUser2.hash", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryUserInfo2_level,
{ "Level", "samr.samr_QueryUserInfo2.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_UserInfoLevel_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_BAD_PWD_COUNT,
{ "Samr Field Bad Pwd Count", "samr.samr_FieldsPresent.SAMR_FIELD_BAD_PWD_COUNT", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_BAD_PWD_COUNT_tfs), ( 0x00004000 ), NULL, HFILL }},
{ &hf_samr_samr_ValidatePasswordReq3_clear_lockout,
{ "Clear Lockout", "samr.samr_ValidatePasswordReq3.clear_lockout", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_Connect4_client_version,
{ "Client Version", "samr.samr_Connect4.client_version", FT_UINT32, BASE_DEC, VALS(samr_samr_ConnectVersion_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_GetDisplayEnumerationIndex_level,
{ "Level", "samr.samr_GetDisplayEnumerationIndex.level", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_workstations,
{ "Workstations", "samr.samr_UserInfo5.workstations", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DispEntryFullGroup_account_name,
{ "Account Name", "samr.samr_DispEntryFullGroup.account_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_LOCKOUT_TIME,
{ "Samr Validate Field Lockout Time", "samr.samr_ValidateFieldsPresent.SAMR_VALIDATE_FIELD_LOCKOUT_TIME", FT_BOOLEAN, 32, TFS(&samr_ValidateFieldsPresent_SAMR_VALIDATE_FIELD_LOCKOUT_TIME_tfs), ( 0x00000004 ), NULL, HFILL }},
{ &hf_samr_samr_UserInfo1_comment,
{ "Comment", "samr.samr_UserInfo1.comment", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_total_size,
{ "Total Size", "samr.samr_QueryDisplayInfo.total_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_EnumDomains_sam,
{ "Sam", "samr.samr_EnumDomains.sam", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo2_code_page,
{ "Code Page", "samr.samr_UserInfo2.code_page", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_PasswordProperties_DOMAIN_PASSWORD_LOCKOUT_ADMINS,
{ "Domain Password Lockout Admins", "samr.samr_PasswordProperties.DOMAIN_PASSWORD_LOCKOUT_ADMINS", FT_BOOLEAN, 32, TFS(&samr_PasswordProperties_DOMAIN_PASSWORD_LOCKOUT_ADMINS_tfs), ( 0x00000008 ), NULL, HFILL }},
{ &hf_samr_samr_DomGeneralInformation_unknown3,
{ "Unknown3", "samr.samr_DomGeneralInformation.unknown3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserAccessMask_SAMR_USER_ACCESS_SET_ATTRIBUTES,
{ "Samr User Access Set Attributes", "samr.samr_UserAccessMask.SAMR_USER_ACCESS_SET_ATTRIBUTES", FT_BOOLEAN, 32, TFS(&samr_UserAccessMask_SAMR_USER_ACCESS_SET_ATTRIBUTES_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_buf_size,
{ "Buf Size", "samr.samr_QueryDisplayInfo.buf_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_AliasAccessMask_SAMR_ALIAS_ACCESS_REMOVE_MEMBER,
{ "Samr Alias Access Remove Member", "samr.samr_AliasAccessMask.SAMR_ALIAS_ACCESS_REMOVE_MEMBER", FT_BOOLEAN, 32, TFS(&samr_AliasAccessMask_SAMR_ALIAS_ACCESS_REMOVE_MEMBER_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_QueryGroupInfo_level,
{ "Level", "samr.samr_QueryGroupInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_GroupInfoEnum_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_SetAliasInfo_level,
{ "Level", "samr.samr_SetAliasInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_AliasInfoEnum_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_buffer,
{ "Buffer", "samr.samr_UserInfo21.buffer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_level,
{ "Level", "samr.samr_QueryDisplayInfo.level", FT_UINT1632, BASE_DEC, VALS(samr_samr_DomainDisplayInformation_vals), 0, NULL, HFILL }},
{ &hf_samr_samr_SetDsrmPassword_unknown,
{ "Unknown", "samr.samr_SetDsrmPassword.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo5_last_password_change,
{ "Last Password Change", "samr.samr_UserInfo5.last_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_GROUP,
{ "Samr Domain Access Create Group", "samr.samr_DomainAccessMask.SAMR_DOMAIN_ACCESS_CREATE_GROUP", FT_BOOLEAN, 32, TFS(&samr_DomainAccessMask_SAMR_DOMAIN_ACCESS_CREATE_GROUP_tfs), ( 0x00000020 ), NULL, HFILL }},
{ &hf_samr_samr_QueryDisplayInfo_returned_size,
{ "Returned Size", "samr.samr_QueryDisplayInfo.returned_size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_UserInfo21_allow_password_change,
{ "Allow Password Change", "samr.samr_UserInfo21.allow_password_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_ConnectInfo_info1,
{ "Info1", "samr.samr_ConnectInfo.info1", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_samr_samr_FieldsPresent_SAMR_FIELD_FULL_NAME,
{ "Samr Field Full Name", "samr.samr_FieldsPresent.SAMR_FIELD_FULL_NAME", FT_BOOLEAN, 32, TFS(&samr_FieldsPresent_SAMR_FIELD_FULL_NAME_tfs), ( 0x00000002 ), NULL, HFILL }},
{ &hf_samr_samr_AliasInfoAll_description,
{ "Description", "samr.samr_AliasInfoAll.description", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_samr,
&ett_samr_lsa_Strings,
&ett_samr_samr_AcctFlags,
&ett_samr_samr_ConnectAccessMask,
&ett_samr_samr_UserAccessMask,
&ett_samr_samr_DomainAccessMask,
&ett_samr_samr_GroupAccessMask,
&ett_samr_samr_AliasAccessMask,
&ett_samr_samr_SamEntry,
&ett_samr_samr_SamArray,
&ett_samr_samr_PasswordProperties,
&ett_samr_samr_DomInfo1,
&ett_samr_samr_DomGeneralInformation,
&ett_samr_samr_DomInfo3,
&ett_samr_samr_DomOEMInformation,
&ett_samr_samr_DomInfo5,
&ett_samr_samr_DomInfo6,
&ett_samr_samr_DomInfo7,
&ett_samr_samr_DomInfo8,
&ett_samr_samr_DomInfo9,
&ett_samr_samr_DomGeneralInformation2,
&ett_samr_samr_DomInfo12,
&ett_samr_samr_DomInfo13,
&ett_samr_samr_DomainInfo,
&ett_samr_samr_Ids,
&ett_samr_samr_GroupAttrs,
&ett_samr_samr_GroupInfoAll,
&ett_samr_samr_GroupInfoAttributes,
&ett_samr_samr_GroupInfoDescription,
&ett_samr_samr_GroupInfo,
&ett_samr_samr_RidTypeArray,
&ett_samr_samr_AliasInfoAll,
&ett_samr_samr_AliasInfo,
&ett_samr_samr_UserInfo1,
&ett_samr_samr_UserInfo2,
&ett_samr_samr_LogonHours,
&ett_samr_samr_UserInfo3,
&ett_samr_samr_UserInfo4,
&ett_samr_samr_UserInfo5,
&ett_samr_samr_UserInfo6,
&ett_samr_samr_UserInfo7,
&ett_samr_samr_UserInfo8,
&ett_samr_samr_UserInfo9,
&ett_samr_samr_UserInfo10,
&ett_samr_samr_UserInfo11,
&ett_samr_samr_UserInfo12,
&ett_samr_samr_UserInfo13,
&ett_samr_samr_UserInfo14,
&ett_samr_samr_UserInfo16,
&ett_samr_samr_UserInfo17,
&ett_samr_samr_Password,
&ett_samr_samr_UserInfo18,
&ett_samr_samr_UserInfo20,
&ett_samr_samr_FieldsPresent,
&ett_samr_samr_UserInfo21,
&ett_samr_samr_CryptPassword,
&ett_samr_samr_UserInfo23,
&ett_samr_samr_UserInfo24,
&ett_samr_samr_CryptPasswordEx,
&ett_samr_samr_UserInfo25,
&ett_samr_samr_UserInfo26,
&ett_samr_samr_UserInfo,
&ett_samr_samr_RidWithAttribute,
&ett_samr_samr_RidWithAttributeArray,
&ett_samr_samr_DispEntryGeneral,
&ett_samr_samr_DispInfoGeneral,
&ett_samr_samr_DispEntryFull,
&ett_samr_samr_DispInfoFull,
&ett_samr_samr_DispEntryFullGroup,
&ett_samr_samr_DispInfoFullGroups,
&ett_samr_samr_DispEntryAscii,
&ett_samr_samr_DispInfoAscii,
&ett_samr_samr_DispInfo,
&ett_samr_samr_PwInfo,
&ett_samr_samr_ChangeReject,
&ett_samr_samr_ConnectInfo1,
&ett_samr_samr_ConnectInfo,
&ett_samr_samr_ValidateFieldsPresent,
&ett_samr_samr_ValidationBlob,
&ett_samr_samr_ValidatePasswordInfo,
&ett_samr_samr_ValidatePasswordRepCtr,
&ett_samr_samr_ValidatePasswordRep,
&ett_samr_samr_ValidatePasswordReq3,
&ett_samr_samr_ValidatePasswordReq2,
&ett_samr_samr_ValidatePasswordReq1,
&ett_samr_samr_ValidatePasswordReq,
};
proto_dcerpc_samr = proto_register_protocol("SAMR (pidl)", "SAMR", "samr");
proto_register_field_array(proto_dcerpc_samr, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_samr(void)
{
dcerpc_init_uuid(proto_dcerpc_samr, ett_dcerpc_samr,
&uuid_dcerpc_samr, ver_dcerpc_samr,
samr_dissectors, hf_samr_opnum);
}
