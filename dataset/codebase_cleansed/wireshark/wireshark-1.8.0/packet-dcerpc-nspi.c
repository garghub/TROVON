int
nspi_dissect_enum_MAPITAGS(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index, guint32 *param)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, param);
return offset;
}
int
nspi_dissect_enum_MAPISTATUS(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index, guint32 *param)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, param);
return offset;
}
static int
nspi_dissect_element_MAPIUID_ab(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
int i;
for (i = 0; i < 16; i++)
offset = nspi_dissect_element_MAPIUID_ab_(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
nspi_dissect_element_MAPIUID_ab_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_nspi_MAPIUID_ab, 0);
return offset;
}
int
nspi_dissect_struct_MAPIUID(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_MAPIUID);
}
offset = nspi_dissect_element_MAPIUID_ab(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_input_locale_language(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_input_locale_language, 0);
return offset;
}
static int
nspi_dissect_element_input_locale_method(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_input_locale_method, 0);
return offset;
}
int
nspi_dissect_struct_input_locale(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_input_locale);
}
offset = nspi_dissect_element_input_locale_language(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_input_locale_method(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_MAPI_SETTINGS_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPI_SETTINGS_handle, 0);
return offset;
}
static int
nspi_dissect_element_MAPI_SETTINGS_flag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPI_SETTINGS_flag, 0);
return offset;
}
static int
nspi_dissect_element_MAPI_SETTINGS_service_provider(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPIUID(tvb,offset,pinfo,tree,drep,hf_nspi_MAPI_SETTINGS_service_provider,0);
return offset;
}
static int
nspi_dissect_element_MAPI_SETTINGS_codepage(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPI_SETTINGS_codepage, 0);
return offset;
}
static int
nspi_dissect_element_MAPI_SETTINGS_input_locale(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_input_locale(tvb,offset,pinfo,tree,drep,hf_nspi_MAPI_SETTINGS_input_locale,0);
return offset;
}
int
nspi_dissect_struct_MAPI_SETTINGS(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_MAPI_SETTINGS);
}
offset = nspi_dissect_element_MAPI_SETTINGS_handle(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPI_SETTINGS_flag(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPI_SETTINGS_service_provider(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPI_SETTINGS_codepage(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPI_SETTINGS_input_locale(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SPropTagArray_aulPropTag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropTagArray_aulPropTag_, NDR_POINTER_UNIQUE, "Pointer to Aulproptag (MAPITAGS)",hf_nspi_SPropTagArray_aulPropTag);
return offset;
}
static int
nspi_dissect_element_SPropTagArray_aulPropTag_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropTagArray_aulPropTag__);
return offset;
}
static int
nspi_dissect_element_SPropTagArray_aulPropTag__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_enum_MAPITAGS(tvb, offset, pinfo, tree, drep, hf_nspi_SPropTagArray_aulPropTag, 0);
return offset;
}
static int
nspi_dissect_element_SPropTagArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropTagArray_cValues, 0);
return offset;
}
int
nspi_dissect_struct_SPropTagArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SPropTagArray);
}
offset = nspi_dissect_element_SPropTagArray_aulPropTag(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SPropTagArray_cValues(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_instance_key_value(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_instance_key_value_, NDR_POINTER_UNIQUE, "Pointer to Value (uint32)",hf_nspi_instance_key_value);
return offset;
}
static int
nspi_dissect_element_instance_key_value_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucvarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_instance_key_value__);
return offset;
}
static int
nspi_dissect_element_instance_key_value__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_instance_key_value, 0);
return offset;
}
static int
nspi_dissect_element_instance_key_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_instance_key_cValues, 0);
return offset;
}
int
nspi_dissect_struct_instance_key(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_instance_key);
}
offset = nspi_dissect_element_instance_key_value(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_instance_key_cValues(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_MAPINAMEID_lpguid(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_MAPINAMEID_lpguid_, NDR_POINTER_UNIQUE, "Pointer to Lpguid (MAPIUID)",hf_nspi_MAPINAMEID_lpguid);
return offset;
}
static int
nspi_dissect_element_MAPINAMEID_lpguid_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPIUID(tvb,offset,pinfo,tree,drep,hf_nspi_MAPINAMEID_lpguid,0);
return offset;
}
static int
nspi_dissect_element_MAPINAMEID_ulKind(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPINAMEID_ulKind, 0);
return offset;
}
static int
nspi_dissect_element_MAPINAMEID_lID(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPINAMEID_lID, 0);
return offset;
}
int
nspi_dissect_struct_MAPINAMEID(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_MAPINAMEID);
}
offset = nspi_dissect_element_MAPINAMEID_lpguid(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPINAMEID_ulKind(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MAPINAMEID_lID(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
nspi_dissect_enum_RestrictionType(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index, guint32 *param)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, param);
return offset;
}
static int
nspi_dissect_element_SPropertyRestriction_relop(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropertyRestriction_relop, 0);
return offset;
}
static int
nspi_dissect_element_SPropertyRestriction_ulPropTag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_enum_MAPITAGS(tvb, offset, pinfo, tree, drep, hf_nspi_SPropertyRestriction_ulPropTag, 0);
return offset;
}
static int
nspi_dissect_element_SPropertyRestriction_lpProp(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropertyRestriction_lpProp_, NDR_POINTER_UNIQUE, "Pointer to Lpprop (SPropValue)",hf_nspi_SPropertyRestriction_lpProp);
return offset;
}
static int
nspi_dissect_element_SPropertyRestriction_lpProp_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropValue(tvb,offset,pinfo,tree,drep,hf_nspi_SPropertyRestriction_lpProp,0);
return offset;
}
int
nspi_dissect_struct_SPropertyRestriction(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SPropertyRestriction);
}
offset = nspi_dissect_element_SPropertyRestriction_relop(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SPropertyRestriction_ulPropTag(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SPropertyRestriction_lpProp(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SAndRestriction_cRes(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SAndRestriction_cRes, 0);
return offset;
}
static int
nspi_dissect_element_SAndRestriction_lpRes(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SAndRestriction_lpRes_, NDR_POINTER_UNIQUE, "Pointer to Lpres (SRestriction)",hf_nspi_SAndRestriction_lpRes);
return offset;
}
static int
nspi_dissect_element_SAndRestriction_lpRes_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SAndRestriction_lpRes__);
return offset;
}
static int
nspi_dissect_element_SAndRestriction_lpRes__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRestriction(tvb,offset,pinfo,tree,drep,hf_nspi_SAndRestriction_lpRes,0);
return offset;
}
int
nspi_dissect_struct_SAndRestriction(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SAndRestriction);
}
offset = nspi_dissect_element_SAndRestriction_cRes(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SAndRestriction_lpRes(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SRestriction_CTR_resAnd(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SAndRestriction(tvb,offset,pinfo,tree,drep,hf_nspi_SRestriction_CTR_resAnd,0);
return offset;
}
static int
nspi_dissect_element_SRestriction_CTR_resProperty(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropertyRestriction(tvb,offset,pinfo,tree,drep,hf_nspi_SRestriction_CTR_resProperty,0);
return offset;
}
static int
nspi_dissect_SRestriction_CTR(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "SRestriction_CTR");
tree = proto_item_add_subtree(item, ett_nspi_SRestriction_CTR);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, &level);
switch(level) {
case RES_AND:
offset = nspi_dissect_element_SRestriction_CTR_resAnd(tvb, offset, pinfo, tree, drep);
break;
case RES_PROPERTY:
offset = nspi_dissect_element_SRestriction_CTR_resProperty(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SRestriction_rt(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_enum_RestrictionType(tvb, offset, pinfo, tree, drep, hf_nspi_SRestriction_PTTYPE, 0);
return offset;
}
static int
nspi_dissect_element_SRestriction_res(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_SRestriction_CTR(tvb, offset, pinfo, tree, drep, hf_nspi_SRestriction_PTTYPE, 0);
return offset;
}
int
nspi_dissect_struct_SRestriction(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SRestriction);
}
offset = nspi_dissect_element_SRestriction_rt(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SRestriction_res(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SSortOrder_ulPropTag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SSortOrder_ulPropTag, 0);
return offset;
}
static int
nspi_dissect_element_SSortOrder_ulOrder(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SSortOrder_ulOrder, 0);
return offset;
}
int
nspi_dissect_struct_SSortOrder(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SSortOrder);
}
offset = nspi_dissect_element_SSortOrder_ulPropTag(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SSortOrder_ulOrder(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_cSorts(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SSortOrderSet_cSorts, 0);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_cCategories(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SSortOrderSet_cCategories, 0);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_cExpanded(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SSortOrderSet_cExpanded, 0);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_aSort(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SSortOrderSet_aSort_, NDR_POINTER_UNIQUE, "Pointer to Asort (SSortOrder)",hf_nspi_SSortOrderSet_aSort);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_aSort_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SSortOrderSet_aSort__);
return offset;
}
static int
nspi_dissect_element_SSortOrderSet_aSort__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SSortOrder(tvb,offset,pinfo,tree,drep,hf_nspi_SSortOrderSet_aSort,0);
return offset;
}
int
nspi_dissect_struct_SSortOrderSet(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SSortOrderSet);
}
offset = nspi_dissect_element_SSortOrderSet_cSorts(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SSortOrderSet_cCategories(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SSortOrderSet_cExpanded(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SSortOrderSet_aSort(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_NAME_STRING_str(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NAME_STRING_str_, NDR_POINTER_UNIQUE, "Pointer to Str (uint8)",hf_nspi_NAME_STRING_str);
return offset;
}
static int
nspi_dissect_element_NAME_STRING_str_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_nspi_NAME_STRING_str, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
nspi_dissect_struct_NAME_STRING(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_NAME_STRING);
}
offset = nspi_dissect_element_NAME_STRING_str(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
nspi_dissect_enum_property_types(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, int hf_index, guint32 *param)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, param);
return offset;
}
static int
nspi_dissect_element_SBinary_cb(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SBinary_cb, 0);
return offset;
}
static int
nspi_dissect_element_SBinary_lpb(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SBinary_lpb_, NDR_POINTER_UNIQUE, "Pointer to Lpb (uint8)",hf_nspi_SBinary_lpb);
return offset;
}
static int
nspi_dissect_element_SBinary_lpb_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SBinary_lpb__);
return offset;
}
static int
nspi_dissect_element_SBinary_lpb__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint8(tvb, offset, pinfo, tree, drep, hf_nspi_SBinary_lpb, 0);
return offset;
}
int
nspi_dissect_struct_SBinary(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SBinary);
}
offset = nspi_dissect_element_SBinary_cb(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SBinary_lpb(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_FILETIME_dwLowDateTime(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_FILETIME_dwLowDateTime, 0);
return offset;
}
static int
nspi_dissect_element_FILETIME_dwHighDateTime(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_FILETIME_dwHighDateTime, 0);
return offset;
}
int
nspi_dissect_struct_FILETIME(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_FILETIME);
}
offset = nspi_dissect_element_FILETIME_dwLowDateTime(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_FILETIME_dwHighDateTime(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SShortArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SShortArray_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SShortArray_lpi(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SShortArray_lpi_, NDR_POINTER_UNIQUE, "Pointer to Lpi (uint16)",hf_nspi_SShortArray_lpi);
return offset;
}
static int
nspi_dissect_element_SShortArray_lpi_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SShortArray_lpi__);
return offset;
}
static int
nspi_dissect_element_SShortArray_lpi__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_nspi_SShortArray_lpi, 0);
return offset;
}
int
nspi_dissect_struct_SShortArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SShortArray);
}
offset = nspi_dissect_element_SShortArray_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SShortArray_lpi(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_MV_LONG_STRUCT_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MV_LONG_STRUCT_cValues, 0);
return offset;
}
static int
nspi_dissect_element_MV_LONG_STRUCT_lpl(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_MV_LONG_STRUCT_lpl_, NDR_POINTER_UNIQUE, "Pointer to Lpl (uint32)",hf_nspi_MV_LONG_STRUCT_lpl);
return offset;
}
static int
nspi_dissect_element_MV_LONG_STRUCT_lpl_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_MV_LONG_STRUCT_lpl__);
return offset;
}
static int
nspi_dissect_element_MV_LONG_STRUCT_lpl__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MV_LONG_STRUCT_lpl, 0);
return offset;
}
int
nspi_dissect_struct_MV_LONG_STRUCT(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_MV_LONG_STRUCT);
}
offset = nspi_dissect_element_MV_LONG_STRUCT_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MV_LONG_STRUCT_lpl(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_LPSTR_lppszA(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, 1, hf_nspi_LPSTR_lppszA, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
int
nspi_dissect_struct_LPSTR(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_LPSTR);
}
offset = nspi_dissect_element_LPSTR_lppszA(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SLPSTRArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SLPSTRArray_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SLPSTRArray_strings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SLPSTRArray_strings_, NDR_POINTER_UNIQUE, "Pointer to Strings (LPSTR)",hf_nspi_SLPSTRArray_strings);
return offset;
}
static int
nspi_dissect_element_SLPSTRArray_strings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SLPSTRArray_strings__);
return offset;
}
static int
nspi_dissect_element_SLPSTRArray_strings__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SLPSTRArray_strings___, NDR_POINTER_UNIQUE, "Pointer to Strings (LPSTR)",hf_nspi_SLPSTRArray_strings);
return offset;
}
static int
nspi_dissect_element_SLPSTRArray_strings___(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_LPSTR(tvb,offset,pinfo,tree,drep,hf_nspi_SLPSTRArray_strings,0);
return offset;
}
int
nspi_dissect_struct_SLPSTRArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SLPSTRArray);
}
offset = nspi_dissect_element_SLPSTRArray_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SLPSTRArray_strings(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SBinaryArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SBinaryArray_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SBinaryArray_lpbin(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SBinaryArray_lpbin_, NDR_POINTER_UNIQUE, "Pointer to Lpbin (SBinary)",hf_nspi_SBinaryArray_lpbin);
return offset;
}
static int
nspi_dissect_element_SBinaryArray_lpbin_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SBinaryArray_lpbin__);
return offset;
}
static int
nspi_dissect_element_SBinaryArray_lpbin__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SBinary(tvb,offset,pinfo,tree,drep,hf_nspi_SBinaryArray_lpbin,0);
return offset;
}
int
nspi_dissect_struct_SBinaryArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SBinaryArray);
}
offset = nspi_dissect_element_SBinaryArray_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SBinaryArray_lpbin(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SGuidArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SGuidArray_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SGuidArray_lpguid(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SGuidArray_lpguid_, NDR_POINTER_UNIQUE, "Pointer to Lpguid (uint32)",hf_nspi_SGuidArray_lpguid);
return offset;
}
static int
nspi_dissect_element_SGuidArray_lpguid_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SGuidArray_lpguid__);
return offset;
}
static int
nspi_dissect_element_SGuidArray_lpguid__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SGuidArray_lpguid, 0);
return offset;
}
int
nspi_dissect_struct_SGuidArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SGuidArray);
}
offset = nspi_dissect_element_SGuidArray_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SGuidArray_lpguid(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_MV_UNICODE_STRUCT_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MV_UNICODE_STRUCT_cValues, 0);
return offset;
}
static int
nspi_dissect_element_MV_UNICODE_STRUCT_lpi(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_MV_UNICODE_STRUCT_lpi_, NDR_POINTER_UNIQUE, "Pointer to Lpi (uint32)",hf_nspi_MV_UNICODE_STRUCT_lpi);
return offset;
}
static int
nspi_dissect_element_MV_UNICODE_STRUCT_lpi_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_MV_UNICODE_STRUCT_lpi__);
return offset;
}
static int
nspi_dissect_element_MV_UNICODE_STRUCT_lpi__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MV_UNICODE_STRUCT_lpi, 0);
return offset;
}
int
nspi_dissect_struct_MV_UNICODE_STRUCT(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_MV_UNICODE_STRUCT);
}
offset = nspi_dissect_element_MV_UNICODE_STRUCT_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_MV_UNICODE_STRUCT_lpi(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SDateTimeArray_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SDateTimeArray_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SDateTimeArray_lpft(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SDateTimeArray_lpft_, NDR_POINTER_UNIQUE, "Pointer to Lpft (FILETIME)",hf_nspi_SDateTimeArray_lpft);
return offset;
}
static int
nspi_dissect_element_SDateTimeArray_lpft_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SDateTimeArray_lpft__);
return offset;
}
static int
nspi_dissect_element_SDateTimeArray_lpft__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_FILETIME(tvb,offset,pinfo,tree,drep,hf_nspi_SDateTimeArray_lpft,0);
return offset;
}
int
nspi_dissect_struct_SDateTimeArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SDateTimeArray);
}
offset = nspi_dissect_element_SDateTimeArray_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SDateTimeArray_lpft(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_i(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_i, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_l(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_l, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_b(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint16(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_b, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpszA(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropValue_CTR_lpszA_, NDR_POINTER_UNIQUE, "Pointer to Lpsza (uint8)",hf_nspi_SPropValue_CTR_lpszA);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpszA_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint8), hf_nspi_SPropValue_CTR_lpszA, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_bin(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SBinary(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_bin,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpszW(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropValue_CTR_lpszW_, NDR_POINTER_UNIQUE, "Pointer to Lpszw (uint16)",hf_nspi_SPropValue_CTR_lpszW);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpszW_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
char *data;
offset = dissect_ndr_cvstring(tvb, offset, pinfo, tree, drep, sizeof(guint16), hf_nspi_SPropValue_CTR_lpszW, FALSE, &data);
proto_item_append_text(tree, ": %s", data);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpguid(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SPropValue_CTR_lpguid_, NDR_POINTER_UNIQUE, "Pointer to Lpguid (MAPIUID)",hf_nspi_SPropValue_CTR_lpguid);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_lpguid_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPIUID(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_lpguid,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_ft(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_FILETIME(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_ft,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_err(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_enum_MAPISTATUS(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_err, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVi(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SShortArray(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVi,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVl(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MV_LONG_STRUCT(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVl,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVszA(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SLPSTRArray(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVszA,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVbin(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SBinaryArray(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVbin,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVguid(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SGuidArray(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVguid,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVszW(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MV_UNICODE_STRUCT(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVszW,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_MVft(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SDateTimeArray(tvb,offset,pinfo,tree,drep,hf_nspi_SPropValue_CTR_MVft,0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_null(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_null, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_CTR_object(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_CTR_object, 0);
return offset;
}
static int
nspi_dissect_SPropValue_CTR(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
guint32 level;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "SPropValue_CTR");
tree = proto_item_add_subtree(item, ett_nspi_SPropValue_CTR);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_index, &level);
switch(level) {
case PT_I2:
offset = nspi_dissect_element_SPropValue_CTR_i(tvb, offset, pinfo, tree, drep);
break;
case PT_LONG:
offset = nspi_dissect_element_SPropValue_CTR_l(tvb, offset, pinfo, tree, drep);
break;
case PT_BOOLEAN:
offset = nspi_dissect_element_SPropValue_CTR_b(tvb, offset, pinfo, tree, drep);
break;
case PT_STRING8:
offset = nspi_dissect_element_SPropValue_CTR_lpszA(tvb, offset, pinfo, tree, drep);
break;
case PT_BINARY:
offset = nspi_dissect_element_SPropValue_CTR_bin(tvb, offset, pinfo, tree, drep);
break;
case PT_UNICODE:
offset = nspi_dissect_element_SPropValue_CTR_lpszW(tvb, offset, pinfo, tree, drep);
break;
case PT_CLSID:
offset = nspi_dissect_element_SPropValue_CTR_lpguid(tvb, offset, pinfo, tree, drep);
break;
case PT_SYSTIME:
offset = nspi_dissect_element_SPropValue_CTR_ft(tvb, offset, pinfo, tree, drep);
break;
case PT_ERROR:
offset = nspi_dissect_element_SPropValue_CTR_err(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_I2:
offset = nspi_dissect_element_SPropValue_CTR_MVi(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_LONG:
offset = nspi_dissect_element_SPropValue_CTR_MVl(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_STRING8:
offset = nspi_dissect_element_SPropValue_CTR_MVszA(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_BINARY:
offset = nspi_dissect_element_SPropValue_CTR_MVbin(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_CLSID:
offset = nspi_dissect_element_SPropValue_CTR_MVguid(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_UNICODE:
offset = nspi_dissect_element_SPropValue_CTR_MVszW(tvb, offset, pinfo, tree, drep);
break;
case PT_MV_SYSTIME:
offset = nspi_dissect_element_SPropValue_CTR_MVft(tvb, offset, pinfo, tree, drep);
break;
case PT_NULL:
offset = nspi_dissect_element_SPropValue_CTR_null(tvb, offset, pinfo, tree, drep);
break;
case PT_OBJECT:
offset = nspi_dissect_element_SPropValue_CTR_object(tvb, offset, pinfo, tree, drep);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SPropValue_ulPropTag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_enum_MAPITAGS(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_ulPropTag, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_dwAlignPad(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SPropValue_dwAlignPad, 0);
return offset;
}
static int
nspi_dissect_element_SPropValue_value(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_SPropValue_CTR(tvb, offset, pinfo, tree, drep, hf_nspi_property_type, 0);
return offset;
}
int
nspi_dissect_struct_SPropValue(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SPropValue);
}
offset = nspi_dissect_element_SPropValue_ulPropTag(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SPropValue_dwAlignPad(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SPropValue_value(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SRow_ulAdrEntryPad(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SRow_ulAdrEntryPad, 0);
return offset;
}
static int
nspi_dissect_element_SRow_cValues(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SRow_cValues, 0);
return offset;
}
static int
nspi_dissect_element_SRow_lpProps(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SRow_lpProps_, NDR_POINTER_UNIQUE, "Pointer to Lpprops (SPropValue)",hf_nspi_SRow_lpProps);
return offset;
}
static int
nspi_dissect_element_SRow_lpProps_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SRow_lpProps__);
return offset;
}
static int
nspi_dissect_element_SRow_lpProps__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropValue(tvb,offset,pinfo,tree,drep,hf_nspi_SRow_lpProps,0);
return offset;
}
int
nspi_dissect_struct_SRow(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SRow);
}
offset = nspi_dissect_element_SRow_ulAdrEntryPad(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SRow_cValues(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SRow_lpProps(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_SRowSet_cRows(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_SRowSet_cRows, 0);
return offset;
}
static int
nspi_dissect_element_SRowSet_aRow(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_SRowSet_aRow_);
return offset;
}
static int
nspi_dissect_element_SRowSet_aRow_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRow(tvb,offset,pinfo,tree,drep,hf_nspi_SRowSet_aRow,0);
return offset;
}
int
nspi_dissect_struct_SRowSet(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *parent_tree, guint8 *drep, int hf_index, guint32 param _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset;
ALIGN_TO_4_BYTES;
old_offset = offset;
if (parent_tree) {
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, -1, TRUE);
tree = proto_item_add_subtree(item, ett_nspi_SRowSet);
}
offset = nspi_dissect_element_SRowSet_cRows(tvb, offset, pinfo, tree, drep);
offset = nspi_dissect_element_SRowSet_aRow(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
nspi_dissect_element_NspiBind_unknown(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiBind_unknown, 0);
return offset;
}
static int
nspi_dissect_element_NspiBind_settings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiBind_settings_, NDR_POINTER_REF, "Pointer to Settings (MAPI_SETTINGS)",hf_nspi_NspiBind_settings);
return offset;
}
static int
nspi_dissect_element_NspiBind_settings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPI_SETTINGS(tvb,offset,pinfo,tree,drep,hf_nspi_NspiBind_settings,0);
return offset;
}
static int
nspi_dissect_element_NspiBind_mapiuid(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiBind_mapiuid_, NDR_POINTER_UNIQUE, "Pointer to Mapiuid (GUID)",hf_nspi_NspiBind_mapiuid);
return offset;
}
static int
nspi_dissect_element_NspiBind_mapiuid_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, drep, hf_nspi_NspiBind_mapiuid, NULL);
return offset;
}
static int
nspi_dissect_element_NspiBind_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiBind_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiBind_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0x0001);
return offset;
}
static int
nspi_dissect_NspiBind_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiBind";
offset = nspi_dissect_element_NspiBind_mapiuid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiBind_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiBind_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiBind";
offset = nspi_dissect_element_NspiBind_unknown(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiBind_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiBind_mapiuid(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_element_NspiUnbind_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiUnbind_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiUnbind_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0x0002);
return offset;
}
static int
nspi_dissect_element_NspiUnbind_status(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiUnbind_status, 0);
return offset;
}
static int
nspi_dissect_NspiUnbind_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiUnbind";
offset = nspi_dissect_element_NspiUnbind_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiUnbind_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiUnbind";
offset = nspi_dissect_element_NspiUnbind_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiUnbind_status(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiUpdateStat_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiUpdateStat";
return offset;
}
static int
nspi_dissect_NspiUpdateStat_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiUpdateStat";
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_flag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiQueryRows_flag, 0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_settings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_settings_, NDR_POINTER_REF, "Pointer to Settings (MAPI_SETTINGS)",hf_nspi_NspiQueryRows_settings);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_settings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPI_SETTINGS(tvb,offset,pinfo,tree,drep,hf_nspi_NspiQueryRows_settings,0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_lRows(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiQueryRows_lRows, 0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_instance_key(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_instance_key_, NDR_POINTER_UNIQUE, "Pointer to Instance Key (uint32)",hf_nspi_NspiQueryRows_instance_key);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_instance_key_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_instance_key__);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_instance_key__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiQueryRows_instance_key, 0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_unknown(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiQueryRows_unknown, 0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_REQ_properties(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_REQ_properties_, NDR_POINTER_REF, "Pointer to Req Properties (SPropTagArray)",hf_nspi_NspiQueryRows_REQ_properties);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_REQ_properties_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropTagArray(tvb,offset,pinfo,tree,drep,hf_nspi_NspiQueryRows_REQ_properties,0);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_RowSet(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_RowSet_, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiQueryRows_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_RowSet_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiQueryRows_RowSet__, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiQueryRows_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiQueryRows_RowSet__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRowSet(tvb,offset,pinfo,tree,drep,hf_nspi_NspiQueryRows_RowSet,0);
return offset;
}
static int
nspi_dissect_NspiQueryRows_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiQueryRows";
offset = nspi_dissect_element_NspiQueryRows_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_RowSet(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiQueryRows_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiQueryRows";
offset = nspi_dissect_element_NspiQueryRows_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_flag(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_lRows(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_instance_key(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_unknown(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiQueryRows_REQ_properties(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiSeekEntries_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiSeekEntries";
return offset;
}
static int
nspi_dissect_NspiSeekEntries_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiSeekEntries";
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_unknown1(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetMatches_unknown1, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_settings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_settings_, NDR_POINTER_REF, "Pointer to Settings (MAPI_SETTINGS)",hf_nspi_NspiGetMatches_settings);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_settings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPI_SETTINGS(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_settings,0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_PropTagArray(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_PropTagArray_, NDR_POINTER_UNIQUE, "Pointer to Proptagarray (SPropTagArray)",hf_nspi_NspiGetMatches_PropTagArray);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_PropTagArray_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropTagArray(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_PropTagArray,0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_unknown2(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetMatches_unknown2, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_restrictions(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_restrictions_, NDR_POINTER_UNIQUE, "Pointer to Restrictions (SRestriction)",hf_nspi_NspiGetMatches_restrictions);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_restrictions_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRestriction(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_restrictions,0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_unknown3(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetMatches_unknown3, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_instance_key(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_instance_key_, NDR_POINTER_REF, "Pointer to Instance Key (instance_key)",hf_nspi_NspiGetMatches_instance_key);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_instance_key_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_instance_key(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_instance_key,0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_REQ_properties(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_REQ_properties_, NDR_POINTER_UNIQUE, "Pointer to Req Properties (SPropTagArray)",hf_nspi_NspiGetMatches_REQ_properties);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_REQ_properties_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropTagArray(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_REQ_properties,0);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_RowSet(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_RowSet_, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiGetMatches_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_RowSet_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetMatches_RowSet__, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiGetMatches_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiGetMatches_RowSet__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRowSet(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetMatches_RowSet,0);
return offset;
}
static int
nspi_dissect_NspiGetMatches_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiGetMatches";
offset = nspi_dissect_element_NspiGetMatches_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_instance_key(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_RowSet(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiGetMatches_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetMatches";
offset = nspi_dissect_element_NspiGetMatches_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_unknown1(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_PropTagArray(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_unknown2(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_restrictions(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_unknown3(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetMatches_REQ_properties(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiResortRestriction_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResortRestriction";
return offset;
}
static int
nspi_dissect_NspiResortRestriction_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResortRestriction";
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiDNToEph_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_flag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiDNToEph_flag, 0);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_size(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiDNToEph_size, 0);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_server_dn(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiDNToEph_server_dn_, NDR_POINTER_REF, "Pointer to Server Dn (NAME_STRING)",hf_nspi_NspiDNToEph_server_dn);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_server_dn_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiDNToEph_server_dn__);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_server_dn__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_NAME_STRING(tvb,offset,pinfo,tree,drep,hf_nspi_NspiDNToEph_server_dn,0);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_instance_key(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiDNToEph_instance_key_, NDR_POINTER_REF, "Pointer to Instance Key (instance_key)",hf_nspi_NspiDNToEph_instance_key);
return offset;
}
static int
nspi_dissect_element_NspiDNToEph_instance_key_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_instance_key(tvb,offset,pinfo,tree,drep,hf_nspi_NspiDNToEph_instance_key,0);
return offset;
}
static int
nspi_dissect_NspiDNToEph_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiDNToEph";
offset = nspi_dissect_element_NspiDNToEph_instance_key(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiDNToEph_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiDNToEph";
offset = nspi_dissect_element_NspiDNToEph_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiDNToEph_flag(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiDNToEph_size(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiDNToEph_server_dn(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiGetPropList_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetPropList";
return offset;
}
static int
nspi_dissect_NspiGetPropList_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetPropList";
return offset;
}
static int
nspi_dissect_element_NspiGetProps_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetProps_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_flag(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetProps_flag, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_settings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetProps_settings_, NDR_POINTER_REF, "Pointer to Settings (MAPI_SETTINGS)",hf_nspi_NspiGetProps_settings);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_settings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPI_SETTINGS(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetProps_settings,0);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_REQ_properties(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetProps_REQ_properties_, NDR_POINTER_REF, "Pointer to Req Properties (SPropTagArray)",hf_nspi_NspiGetProps_REQ_properties);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_REQ_properties_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SPropTagArray(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetProps_REQ_properties,0);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_REPL_values(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetProps_REPL_values_, NDR_POINTER_REF, "Pointer to Repl Values (SRow)",hf_nspi_NspiGetProps_REPL_values);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_REPL_values_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetProps_REPL_values__, NDR_POINTER_REF, "Pointer to Repl Values (SRow)",hf_nspi_NspiGetProps_REPL_values);
return offset;
}
static int
nspi_dissect_element_NspiGetProps_REPL_values__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRow(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetProps_REPL_values,0);
return offset;
}
static int
nspi_dissect_NspiGetProps_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiGetProps";
offset = nspi_dissect_element_NspiGetProps_REPL_values(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiGetProps_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetProps";
offset = nspi_dissect_element_NspiGetProps_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetProps_flag(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetProps_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetProps_REQ_properties(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiCompareDNTs_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiCompareDNTs";
return offset;
}
static int
nspi_dissect_NspiCompareDNTs_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiCompareDNTs";
return offset;
}
static int
nspi_dissect_NspiModProps_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiModProps";
return offset;
}
static int
nspi_dissect_NspiModProps_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiModProps";
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_handle(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetHierarchyInfo_handle_, NDR_POINTER_REF, "Pointer to Handle (policy_handle)",hf_nspi_handle);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_handle_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_policy_hnd(tvb, offset, pinfo, tree, drep, hf_nspi_handle, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_unknown1(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetHierarchyInfo_unknown1, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_settings(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetHierarchyInfo_settings_, NDR_POINTER_REF, "Pointer to Settings (MAPI_SETTINGS)",hf_nspi_NspiGetHierarchyInfo_settings);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_settings_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_MAPI_SETTINGS(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetHierarchyInfo_settings,0);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_unknown2(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetHierarchyInfo_unknown2_, NDR_POINTER_REF, "Pointer to Unknown2 (uint32)",hf_nspi_NspiGetHierarchyInfo_unknown2);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_unknown2_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = PIDL_dissect_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_NspiGetHierarchyInfo_unknown2, 0);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_RowSet(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_toplevel_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetHierarchyInfo_RowSet_, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiGetHierarchyInfo_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_RowSet_(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, nspi_dissect_element_NspiGetHierarchyInfo_RowSet__, NDR_POINTER_REF, "Pointer to Rowset (SRowSet)",hf_nspi_NspiGetHierarchyInfo_RowSet);
return offset;
}
static int
nspi_dissect_element_NspiGetHierarchyInfo_RowSet__(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = nspi_dissect_struct_SRowSet(tvb,offset,pinfo,tree,drep,hf_nspi_NspiGetHierarchyInfo_RowSet,0);
return offset;
}
static int
nspi_dissect_NspiGetHierarchyInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
guint32 status;
pinfo->dcerpc_procedure_name="NspiGetHierarchyInfo";
offset = nspi_dissect_element_NspiGetHierarchyInfo_unknown2(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetHierarchyInfo_RowSet(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_nspi_MAPISTATUS_status, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Status: %s", val_to_str(status, nspi_MAPISTATUS_vals, "Unknown MAPISTATUS error 0x%08x"));
return offset;
}
static int
nspi_dissect_NspiGetHierarchyInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetHierarchyInfo";
offset = nspi_dissect_element_NspiGetHierarchyInfo_handle(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetHierarchyInfo_unknown1(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetHierarchyInfo_settings(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
offset = nspi_dissect_element_NspiGetHierarchyInfo_unknown2(tvb, offset, pinfo, tree, drep);
offset = dissect_deferred_pointers(pinfo, tvb, offset, drep);
return offset;
}
static int
nspi_dissect_NspiGetTemplateInfo_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetTemplateInfo";
return offset;
}
static int
nspi_dissect_NspiGetTemplateInfo_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetTemplateInfo";
return offset;
}
static int
nspi_dissect_NspiModLInkAtt_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiModLInkAtt";
return offset;
}
static int
nspi_dissect_NspiModLInkAtt_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiModLInkAtt";
return offset;
}
static int
nspi_dissect_NspiDeleteEntries_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiDeleteEntries";
return offset;
}
static int
nspi_dissect_NspiDeleteEntries_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiDeleteEntries";
return offset;
}
static int
nspi_dissect_NspiQueryColumns_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiQueryColumns";
return offset;
}
static int
nspi_dissect_NspiQueryColumns_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiQueryColumns";
return offset;
}
static int
nspi_dissect_NspiGetNamesFromIDs_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetNamesFromIDs";
return offset;
}
static int
nspi_dissect_NspiGetNamesFromIDs_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetNamesFromIDs";
return offset;
}
static int
nspi_dissect_NspiGetIDsFromNames_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetIDsFromNames";
return offset;
}
static int
nspi_dissect_NspiGetIDsFromNames_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiGetIDsFromNames";
return offset;
}
static int
nspi_dissect_NspiResolveNames_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResolveNames";
return offset;
}
static int
nspi_dissect_NspiResolveNames_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResolveNames";
return offset;
}
static int
nspi_dissect_NspiResolveNamesW_response(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResolveNamesW";
return offset;
}
static int
nspi_dissect_NspiResolveNamesW_request(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo, proto_tree *tree _U_, guint8 *drep _U_)
{
pinfo->dcerpc_procedure_name="NspiResolveNamesW";
return offset;
}
void proto_register_dcerpc_nspi(void)
{
static hf_register_info hf[] = {
{ &hf_nspi_NspiGetHierarchyInfo_unknown1,
{ "Unknown1", "nspi.NspiGetHierarchyInfo.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_ft,
{ "Ft", "nspi.SPropValue_CTR.ft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_object,
{ "Object", "nspi.SPropValue_CTR.object", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_input_locale_language,
{ "Language", "nspi.input_locale.language", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVft,
{ "Mvft", "nspi.SPropValue_CTR.MVft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SDateTimeArray_lpft,
{ "Lpft", "nspi.SDateTimeArray.lpft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrderSet_aSort,
{ "Asort", "nspi.SSortOrderSet.aSort", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SGuidArray_lpguid,
{ "Lpguid", "nspi.SGuidArray.lpguid", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_dwAlignPad,
{ "Dwalignpad", "nspi.SPropValue.dwAlignPad", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_instance_key,
{ "Instance Key", "nspi.NspiQueryRows.instance_key", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrderSet_cCategories,
{ "Ccategories", "nspi.SSortOrderSet.cCategories", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPINAMEID_ulKind,
{ "Ulkind", "nspi.MAPINAMEID.ulKind", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiDNToEph_server_dn,
{ "Server Dn", "nspi.NspiDNToEph.server_dn", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPIUID_ab,
{ "Ab", "nspi.MAPIUID.ab", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_b,
{ "B", "nspi.SPropValue_CTR.b", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRow_ulAdrEntryPad,
{ "Uladrentrypad", "nspi.SRow.ulAdrEntryPad", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_null,
{ "Null", "nspi.SPropValue_CTR.null", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SBinary_cb,
{ "Cb", "nspi.SBinary.cb", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SBinaryArray_lpbin,
{ "Lpbin", "nspi.SBinaryArray.lpbin", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SShortArray_cValues,
{ "Cvalues", "nspi.SShortArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRowSet_aRow,
{ "Arow", "nspi.SRowSet.aRow", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiBind_mapiuid,
{ "Mapiuid", "nspi.NspiBind.mapiuid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SGuidArray_cValues,
{ "Cvalues", "nspi.SGuidArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_instance_key_cValues,
{ "Cvalues", "nspi.instance_key.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRestriction_CTR_resProperty,
{ "Resproperty", "nspi.SRestriction_CTR.resProperty", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_lRows,
{ "Lrows", "nspi.NspiQueryRows.lRows", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MV_UNICODE_STRUCT_cValues,
{ "Cvalues", "nspi.MV_UNICODE_STRUCT.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrder_ulOrder,
{ "Ulorder", "nspi.SSortOrder.ulOrder", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetHierarchyInfo_RowSet,
{ "Rowset", "nspi.NspiGetHierarchyInfo.RowSet", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPINAMEID_lID,
{ "Lid", "nspi.MAPINAMEID.lID", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_settings,
{ "Settings", "nspi.NspiQueryRows.settings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SBinaryArray_cValues,
{ "Cvalues", "nspi.SBinaryArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_unknown2,
{ "Unknown2", "nspi.NspiGetMatches.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SLPSTRArray_strings,
{ "Strings", "nspi.SLPSTRArray.strings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_FILETIME_dwHighDateTime,
{ "Dwhighdatetime", "nspi.FILETIME.dwHighDateTime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetProps_REPL_values,
{ "Repl Values", "nspi.NspiGetProps.REPL_values", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRow_cValues,
{ "Cvalues", "nspi.SRow.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_ulPropTag,
{ "Ulproptag", "nspi.SPropValue.ulPropTag", FT_UINT32, BASE_DEC, VALS(nspi_MAPITAGS_vals), 0, NULL, HFILL }},
{ &hf_nspi_NspiGetProps_settings,
{ "Settings", "nspi.NspiGetProps.settings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiDNToEph_instance_key,
{ "Instance Key", "nspi.NspiDNToEph.instance_key", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRestriction_CTR_resAnd,
{ "Resand", "nspi.SRestriction_CTR.resAnd", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_RowSet,
{ "Rowset", "nspi.NspiGetMatches.RowSet", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MV_UNICODE_STRUCT_lpi,
{ "Lpi", "nspi.MV_UNICODE_STRUCT.lpi", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrderSet_cSorts,
{ "Csorts", "nspi.SSortOrderSet.cSorts", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrder_ulPropTag,
{ "Ulproptag", "nspi.SSortOrder.ulPropTag", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVbin,
{ "Mvbin", "nspi.SPropValue_CTR.MVbin", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_opnum,
{ "Operation", "nspi.opnum", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiUnbind_status,
{ "Status", "nspi.NspiUnbind.status", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SAndRestriction_lpRes,
{ "Lpres", "nspi.SAndRestriction.lpRes", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiDNToEph_size,
{ "Size", "nspi.NspiDNToEph.size", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVi,
{ "Mvi", "nspi.SPropValue_CTR.MVi", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropertyRestriction_lpProp,
{ "Lpprop", "nspi.SPropertyRestriction.lpProp", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_unknown3,
{ "Unknown3", "nspi.NspiGetMatches.unknown3", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPI_SETTINGS_flag,
{ "Flag", "nspi.MAPI_SETTINGS.flag", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_instance_key_value,
{ "Value", "nspi.instance_key.value", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_settings,
{ "Settings", "nspi.NspiGetMatches.settings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MV_LONG_STRUCT_cValues,
{ "Cvalues", "nspi.MV_LONG_STRUCT.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRowSet_cRows,
{ "Crows", "nspi.SRowSet.cRows", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPI_SETTINGS_service_provider,
{ "Service Provider", "nspi.MAPI_SETTINGS.service_provider", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_l,
{ "L", "nspi.SPropValue_CTR.l", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SAndRestriction_cRes,
{ "Cres", "nspi.SAndRestriction.cRes", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_flag,
{ "Flag", "nspi.NspiQueryRows.flag", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_REQ_properties,
{ "Req Properties", "nspi.NspiQueryRows.REQ_properties", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVl,
{ "Mvl", "nspi.SPropValue_CTR.MVl", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetProps_flag,
{ "Flag", "nspi.NspiGetProps.flag", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPISTATUS_status,
{ "MAPISTATUS", "nspi.MAPISTATUS_status", FT_UINT32, BASE_HEX, VALS(nspi_MAPISTATUS_vals), 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVszW,
{ "Mvszw", "nspi.SPropValue_CTR.MVszW", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_LPSTR_lppszA,
{ "Lppsza", "nspi.LPSTR.lppszA", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVszA,
{ "Mvsza", "nspi.SPropValue_CTR.MVszA", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_property_type,
{ "Value", "nspi.SPropValue.value", FT_UINT32, BASE_HEX, VALS(nspi_property_types_vals), 0, NULL, HFILL }},
{ &hf_nspi_handle,
{ "Handle", "nspi.handle", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_restrictions,
{ "Restrictions", "nspi.NspiGetMatches.restrictions", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_RowSet,
{ "Rowset", "nspi.NspiQueryRows.RowSet", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SRow_lpProps,
{ "Lpprops", "nspi.SRow.lpProps", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPI_SETTINGS_input_locale,
{ "Input Locale", "nspi.MAPI_SETTINGS.input_locale", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropertyRestriction_ulPropTag,
{ "Ulproptag", "nspi.SPropertyRestriction.ulPropTag", FT_UINT32, BASE_DEC, VALS(nspi_MAPITAGS_vals), 0, NULL, HFILL }},
{ &hf_nspi_SPropTagArray_aulPropTag,
{ "Aulproptag", "nspi.SPropTagArray.aulPropTag", FT_UINT32, BASE_DEC, VALS(nspi_MAPITAGS_vals), 0, NULL, HFILL }},
{ &hf_nspi_NspiGetHierarchyInfo_unknown2,
{ "Unknown2", "nspi.NspiGetHierarchyInfo.unknown2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SBinary_lpb,
{ "Lpb", "nspi.SBinary.lpb", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetHierarchyInfo_settings,
{ "Settings", "nspi.NspiGetHierarchyInfo.settings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SSortOrderSet_cExpanded,
{ "Cexpanded", "nspi.SSortOrderSet.cExpanded", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiQueryRows_unknown,
{ "Unknown", "nspi.NspiQueryRows.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_input_locale_method,
{ "Method", "nspi.input_locale.method", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_instance_key,
{ "Instance Key", "nspi.NspiGetMatches.instance_key", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_lpszA,
{ "Lpsza", "nspi.SPropValue_CTR.lpszA", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_bin,
{ "Bin", "nspi.SPropValue_CTR.bin", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SShortArray_lpi,
{ "Lpi", "nspi.SShortArray.lpi", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_lpszW,
{ "Lpszw", "nspi.SPropValue_CTR.lpszW", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_PropTagArray,
{ "Proptagarray", "nspi.NspiGetMatches.PropTagArray", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SLPSTRArray_cValues,
{ "Cvalues", "nspi.SLPSTRArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_err,
{ "Err", "nspi.SPropValue_CTR.err", FT_UINT32, BASE_DEC, VALS(nspi_MAPISTATUS_vals), 0, NULL, HFILL }},
{ &hf_nspi_SRestriction_PTTYPE,
{ "Restriction Type", "nspi.property_type", FT_UINT32, BASE_HEX, VALS(nspi_nspi_RestrictionType_vals), 0, NULL, HFILL }},
{ &hf_nspi_NAME_STRING_str,
{ "Str", "nspi.NAME_STRING.str", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropertyRestriction_relop,
{ "Relop", "nspi.SPropertyRestriction.relop", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_MVguid,
{ "Mvguid", "nspi.SPropValue_CTR.MVguid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPINAMEID_lpguid,
{ "Lpguid", "nspi.MAPINAMEID.lpguid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_FILETIME_dwLowDateTime,
{ "Dwlowdatetime", "nspi.FILETIME.dwLowDateTime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_REQ_properties,
{ "Req Properties", "nspi.NspiGetMatches.REQ_properties", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropTagArray_cValues,
{ "Cvalues", "nspi.SPropTagArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_lpguid,
{ "Lpguid", "nspi.SPropValue_CTR.lpguid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SPropValue_CTR_i,
{ "I", "nspi.SPropValue_CTR.i", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPI_SETTINGS_codepage,
{ "Codepage", "nspi.MAPI_SETTINGS.codepage", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiDNToEph_flag,
{ "Flag", "nspi.NspiDNToEph.flag", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiBind_unknown,
{ "Unknown", "nspi.NspiBind.unknown", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MAPI_SETTINGS_handle,
{ "Handle", "nspi.MAPI_SETTINGS.handle", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetProps_REQ_properties,
{ "Req Properties", "nspi.NspiGetProps.REQ_properties", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_nspi_MV_LONG_STRUCT_lpl,
{ "Lpl", "nspi.MV_LONG_STRUCT.lpl", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiGetMatches_unknown1,
{ "Unknown1", "nspi.NspiGetMatches.unknown1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_SDateTimeArray_cValues,
{ "Cvalues", "nspi.SDateTimeArray.cValues", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_nspi_NspiBind_settings,
{ "Settings", "nspi.NspiBind.settings", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_nspi,
&ett_nspi_MAPIUID,
&ett_nspi_input_locale,
&ett_nspi_MAPI_SETTINGS,
&ett_nspi_SPropTagArray,
&ett_nspi_instance_key,
&ett_nspi_MAPINAMEID,
&ett_nspi_SPropertyRestriction,
&ett_nspi_SAndRestriction,
&ett_nspi_SRestriction_CTR,
&ett_nspi_SRestriction,
&ett_nspi_SSortOrder,
&ett_nspi_SSortOrderSet,
&ett_nspi_NAME_STRING,
&ett_nspi_SBinary,
&ett_nspi_FILETIME,
&ett_nspi_SShortArray,
&ett_nspi_MV_LONG_STRUCT,
&ett_nspi_LPSTR,
&ett_nspi_SLPSTRArray,
&ett_nspi_SBinaryArray,
&ett_nspi_SGuidArray,
&ett_nspi_MV_UNICODE_STRUCT,
&ett_nspi_SDateTimeArray,
&ett_nspi_SPropValue_CTR,
&ett_nspi_SPropValue,
&ett_nspi_SRow,
&ett_nspi_SRowSet,
};
proto_dcerpc_nspi = proto_register_protocol("Exchange 5.5 Name Service Provider", "NSPI", "nspi");
proto_register_field_array(proto_dcerpc_nspi, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_dcerpc_nspi(void)
{
dcerpc_init_uuid(proto_dcerpc_nspi, ett_dcerpc_nspi,
&uuid_dcerpc_nspi, ver_dcerpc_nspi,
nspi_dissectors, hf_nspi_opnum);
}
