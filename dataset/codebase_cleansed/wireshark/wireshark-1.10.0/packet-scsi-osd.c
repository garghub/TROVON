static int
dissect_osd_user_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_user_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static void
attribute_1_82(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset=0;
proto_tree_add_item(tree, hf_scsi_osd_user_object_logical_length, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static void
dissect_osd_attributes_list(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 type;
guint16 length, attribute_length;
guint32 page, number;
int start_offset=offset;
proto_item *item;
const attribute_pages_t *ap;
const attribute_page_numbers_t *apn;
tvbuff_t *next_tvb;
type=tvb_get_guint8(tvb, offset)&0x0f;
proto_tree_add_item(tree, hf_scsi_osd_attributes_list_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
length=tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attributes_list_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if(type==1){
length=tvb_length_remaining(tvb, offset);
}
while( (offset-start_offset)<(length+4) ){
switch(type){
case 0x01:
page=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
number=tvb_get_ntohl(tvb, offset);
item=proto_tree_add_item(tree, hf_scsi_osd_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
apn=NULL;
for(ap=attribute_pages;ap->attributes;ap++){
if(ap->page==page){
apn=ap->attributes;
break;
}
}
if(!apn){
proto_tree_add_text(tree, tvb, offset, length, "Unknown attribute page. can not decode attribute value");
break;
}
for(;apn->name;apn++){
if(apn->number==number){
break;
}
}
if(!apn->name){
proto_tree_add_text(tree, tvb, offset, length, "Unknown attribute. can not decode attribute value");
break;
}
proto_item_append_text(item, " (%s)", apn->name);
break;
case 0x0f:
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
case 0x09:
page=tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
number=tvb_get_ntohl(tvb, offset);
item=proto_tree_add_item(tree, hf_scsi_osd_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
attribute_length=tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attribute_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
apn=NULL;
for(ap=attribute_pages;ap->attributes;ap++){
if(ap->page==page){
apn=ap->attributes;
break;
}
}
if(!apn){
proto_tree_add_text(tree, tvb, offset, length, "Unknown attribute page. can not decode attribute value");
offset+=attribute_length;
break;
}
for(;apn->name;apn++){
if(apn->number==number){
break;
}
}
if(!apn->name){
proto_tree_add_text(tree, tvb, offset, length, "Unknown attribute. can not decode attribute value");
offset+=attribute_length;
break;
}
proto_item_append_text(item, " (%s)", apn->name);
if(attribute_length==0){
offset+=attribute_length;
break;
}
next_tvb=tvb_new_subset(tvb, offset, attribute_length, attribute_length);
apn->dissector(next_tvb, pinfo, tree);
offset+=attribute_length;
break;
default:
proto_tree_add_text(tree, tvb, offset, tvb_length_remaining(tvb, offset), "Don't know how to decode this attribute list type:0x%02x",type);
return;
}
}
}
static void
dissect_osd_option(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree=NULL;
proto_item *it=NULL;
guint8 option;
option=tvb_get_guint8(tvb, offset);
if(parent_tree){
it=proto_tree_add_item(parent_tree, hf_scsi_osd_option, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(it, ett_osd_option);
}
proto_tree_add_item(tree, hf_scsi_osd_option_dpo, tvb, offset, 1, ENC_BIG_ENDIAN);
if(option&0x10){
proto_item_append_text(tree, " DPO");
}
proto_tree_add_item(tree, hf_scsi_osd_option_fua, tvb, offset, 1, ENC_BIG_ENDIAN);
if(option&0x08){
proto_item_append_text(tree, " FUA");
}
}
static void
dissect_osd_getsetattrib(tvbuff_t *tvb, int offset, proto_tree *tree, scsi_task_data_t *cdata)
{
if(cdata && cdata->itlq && cdata->itlq->extra_data){
scsi_osd_extra_data_t *extra_data=(scsi_osd_extra_data_t *)cdata->itlq->extra_data;
extra_data->gsatype=(tvb_get_guint8(tvb, offset)>>4)&0x03;
}
proto_tree_add_item(tree, hf_scsi_osd_getsetattrib, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd_timestamps_control(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_timestamps_control, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd_formatted_capacity(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_formatted_capacity, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static int
dissect_osd_attribute_parameters(tvbuff_t *tvb, int offset, proto_tree *parent_tree, scsi_task_data_t *cdata)
{
guint8 gsatype=0;
proto_item *item=NULL;
proto_tree *tree=NULL;
scsi_osd_extra_data_t *extra_data=NULL;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 28,
"Attribute Parameters");
tree = proto_item_add_subtree(item, ett_osd_attribute_parameters);
}
if(cdata && cdata->itlq && cdata->itlq->extra_data){
extra_data=(scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype=extra_data->gsatype;
} else {
return offset;
}
switch(gsatype){
case 2:
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_allocation_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_retrieved_attributes_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case 3:
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_list_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.get_list_length=tvb_get_ntohl(tvb, offset);
offset+=4;
extra_data->u.al.get_list_offset=tvb_get_ntohl(tvb, offset);
extra_data->u.al.get_list_offset=(extra_data->u.al.get_list_offset&0x0fffffff)<<((extra_data->u.al.get_list_offset>>28)&0x0f);
extra_data->u.al.get_list_offset<<=8;
proto_tree_add_uint(tree, hf_scsi_osd_get_attributes_list_offset, tvb, offset, 4, extra_data->u.al.get_list_offset);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_allocation_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.get_list_allocation_length=tvb_get_ntohl(tvb, offset);
offset+=4;
extra_data->u.al.retrieved_list_offset=tvb_get_ntohl(tvb, offset);
extra_data->u.al.retrieved_list_offset=(extra_data->u.al.retrieved_list_offset&0x0fffffff)<<((extra_data->u.al.retrieved_list_offset>>28)&0x0f);
extra_data->u.al.retrieved_list_offset<<=8;
proto_tree_add_uint(tree, hf_scsi_osd_retrieved_attributes_offset, tvb, offset, 4, extra_data->u.al.retrieved_list_offset);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_list_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.set_list_length=tvb_get_ntohl(tvb, offset);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_list_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.set_list_offset=tvb_get_ntohl(tvb, offset);
offset+=4;
offset+=4;
break;
}
return offset;
}
static void
dissect_osd_attribute_data_out(packet_info *pinfo, tvbuff_t *tvb, int offset _U_, proto_tree *tree, scsi_task_data_t *cdata)
{
guint8 gsatype=0;
scsi_osd_extra_data_t *extra_data=NULL;
if(cdata && cdata->itlq && cdata->itlq->extra_data){
extra_data=(scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype=extra_data->gsatype;
} else {
return;
}
switch(gsatype){
case 2:
break;
case 3:
if(extra_data->u.al.get_list_length){
dissect_osd_attributes_list(pinfo, tvb, extra_data->u.al.get_list_offset, tree);
}
if(extra_data->u.al.set_list_length){
proto_tree_add_text(tree, tvb, extra_data->u.al.set_list_offset, extra_data->u.al.set_list_length, "Set Attributes Data");
}
break;
}
}
static void
dissect_osd_attribute_data_in(packet_info *pinfo, tvbuff_t *tvb, int offset _U_, proto_tree *tree, scsi_task_data_t *cdata)
{
guint8 gsatype=0;
scsi_osd_extra_data_t *extra_data=NULL;
if(cdata && cdata->itlq && cdata->itlq->extra_data){
extra_data=(scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype=extra_data->gsatype;
} else {
return;
}
switch(gsatype){
case 2:
break;
case 3:
if(extra_data->u.al.get_list_allocation_length){
dissect_osd_attributes_list(pinfo, tvb, extra_data->u.al.retrieved_list_offset, tree);
}
break;
}
}
static void
dissect_osd_permissions(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree=NULL;
proto_item *it=NULL;
guint16 permissions;
permissions=tvb_get_ntohs(tvb, offset);
if(parent_tree){
it=proto_tree_add_item(parent_tree, hf_scsi_osd_permissions, tvb, offset, 2, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(it, ett_osd_permission_bitmask);
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_read, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x8000){
proto_item_append_text(tree, " READ");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_write, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x4000){
proto_item_append_text(tree, " WRITE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_get_attr, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x2000){
proto_item_append_text(tree, " GET_ATTR");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_set_attr, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x1000){
proto_item_append_text(tree, " SET_ATTR");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_create, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0800){
proto_item_append_text(tree, " CREATE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_remove, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0400){
proto_item_append_text(tree, " REMOVE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_obj_mgmt, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0200){
proto_item_append_text(tree, " OBJ_MGMT");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_append, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0100){
proto_item_append_text(tree, " APPEND");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_dev_mgmt, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0080){
proto_item_append_text(tree, " DEV_MGMT");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_global, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0040){
proto_item_append_text(tree, " GLOBAL");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_pol_sec, tvb, offset, 2, ENC_BIG_ENDIAN);
if(permissions&0x0020){
proto_item_append_text(tree, " POL/SEC");
}
}
static int
dissect_osd_capability(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 80,
"Capability");
tree = proto_item_add_subtree(item, ett_osd_capability);
}
proto_tree_add_item(tree, hf_scsi_osd_capability_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_scsi_osd_key_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_osd_icva, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_scsi_osd_security_method, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset++;
proto_tree_add_item(tree, hf_scsi_osd_capability_expiration_time, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_scsi_osd_audit, tvb, offset, 20, ENC_NA);
offset+=20;
proto_tree_add_item(tree, hf_scsi_osd_capability_discriminator, tvb, offset, 12, ENC_NA);
offset+=12;
proto_tree_add_item(tree, hf_scsi_osd_object_created_time, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(tree, hf_scsi_osd_object_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dissect_osd_permissions(tvb, offset, tree);
offset+=5;
offset++;
proto_tree_add_item(tree, hf_scsi_osd_object_descriptor_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_scsi_osd_object_descriptor, tvb, offset, 24, ENC_NA);
offset+=24;
return offset;
}
static int
dissect_osd_security_parameters(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 40,
"Security Parameters");
tree = proto_item_add_subtree(item, ett_osd_security_parameters);
}
proto_tree_add_item(tree, hf_scsi_osd_ricv, tvb, offset, 20, ENC_NA);
offset+=20;
proto_tree_add_item(tree, hf_scsi_osd_request_nonce, tvb, offset, 12, ENC_NA);
offset+=12;
proto_tree_add_item(tree, hf_scsi_osd_diicvo, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_scsi_osd_doicvo, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static void
dissect_osd_format_osd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info _U_)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=23;
dissect_osd_formatted_capacity(tvb, offset, tree);
offset+=8;
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_partition_id(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree, int hf_index, scsi_osd_lun_info_t *lun_info, gboolean is_created, gboolean is_removed)
{
proto_item *item=NULL;
guint32 partition_id[2];
item=proto_tree_add_item(tree, hf_index, tvb, offset, 8, ENC_BIG_ENDIAN);
partition_id[0]=tvb_get_ntohl(tvb, offset);
partition_id[1]=tvb_get_ntohl(tvb, offset+4);
if(!partition_id[0] && !partition_id[1]){
proto_item_append_text(item, " (ROOT partition)");
} else {
partition_info_t *part_info;
emem_tree_key_t pikey[2];
proto_tree *partition_tree=NULL;
pikey[0].length=2;
pikey[0].key=partition_id;
pikey[1].length=0;
part_info=(partition_info_t *)se_tree_lookup32_array(lun_info->partitions, &pikey[0]);
if(!part_info){
part_info=se_new(partition_info_t);
part_info->created_in=0;
part_info->removed_in=0;
pikey[0].length=2;
pikey[0].key=partition_id;
pikey[1].length=0;
se_tree_insert32_array(lun_info->partitions, &pikey[0], part_info);
}
if(is_created){
part_info->created_in=pinfo->fd->num;
}
if(is_removed){
part_info->removed_in=pinfo->fd->num;
}
if(item){
partition_tree=proto_item_add_subtree(item, ett_osd_partition);
}
if(part_info->created_in){
proto_item *tmp_item;
tmp_item=proto_tree_add_uint(partition_tree, hf_scsi_osd_partition_created_in, tvb, 0, 0, part_info->created_in);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
if(part_info->removed_in){
proto_item *tmp_item;
tmp_item=proto_tree_add_uint(partition_tree, hf_scsi_osd_partition_removed_in, tvb, 0, 0, part_info->removed_in);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
offset+=8;
return offset;
}
static void
dissect_osd_create_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_requested_partition_id, lun_info, TRUE, FALSE);
offset+=8;
offset+=28;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_sortorder(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_sortorder, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_osd_list_identifier(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_list_identifier, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_osd_allocation_length(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_allocation_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_osd_initial_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_initial_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static int
dissect_osd_additional_length(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_additional_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_osd_continuation_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_continuation_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static void
dissect_osd_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_sortorder(tvb, offset, tree);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
offset+=8;
dissect_osd_list_identifier(tvb, offset, tree);
offset+=4;
dissect_osd_allocation_length(tvb, offset, tree);
offset+=8;
dissect_osd_initial_object_id(tvb, offset, tree);
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
guint64 additional_length;
gboolean is_root;
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
additional_length=tvb_get_ntoh64(tvb, offset);
dissect_osd_additional_length(tvb, offset, tree);
offset+=8;
dissect_osd_continuation_object_id(tvb, offset, tree);
offset+=8;
dissect_osd_list_identifier(tvb, offset, tree);
offset+=4;
offset+=3;
proto_tree_add_item(tree, hf_scsi_osd_list_flags_lstchg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_osd_list_flags_root, tvb, offset, 1, ENC_BIG_ENDIAN);
is_root=tvb_get_guint8(tvb, offset)&0x01;
offset++;
while(additional_length > (offset-8)){
if(is_root){
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
} else {
dissect_osd_user_object_id(tvb, offset, tree);
}
offset+=8;
}
}
}
static int
dissect_osd_requested_user_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_requested_user_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static int
dissect_osd_number_of_user_objects(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_number_of_user_objects, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
return offset;
}
static void
dissect_osd_create(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_requested_user_object_id(tvb, offset, tree);
offset+=8;
offset+=4;
dissect_osd_number_of_user_objects(tvb, offset, tree);
offset+=2;
offset+=14;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_remove_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, TRUE);
offset+=8;
offset+=28;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_key_to_set(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_key_to_set, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd_set_key_version(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_set_key_version, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd_key_identifier(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_key_identifier, tvb, offset, 7, ENC_NA);
}
static void
dissect_osd_seed(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_seed, tvb, offset, 20, ENC_NA);
}
static void
dissect_osd_set_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_key_to_set(tvb, offset, tree);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_set_key_version(tvb, offset, tree);
offset++;
dissect_osd_key_identifier(tvb, offset, tree);
offset+=7;
dissect_osd_seed(tvb, offset, tree);
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_remove(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_collection_fcr(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_collection_fcr, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static int
dissect_osd_collection_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_collection_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static void
dissect_osd_remove_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_collection_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_length(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_osd_starting_byte_address(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_starting_byte_address, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static void
dissect_osd_write(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=4;
dissect_osd_length(tvb, offset, tree);
offset+=8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_requested_collection_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_requested_collection_object_id, tvb, offset, 8, ENC_NA);
offset+=8;
return offset;
}
static void
dissect_osd_create_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_requested_collection_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_flush_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_osd_flush(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_flush_scope(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_flush_collection_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_collection_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_osd_flush_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_flush_collection_scope(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_collection_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_append(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=4;
dissect_osd_length(tvb, offset, tree);
offset+=8;
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_create_and_write(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_requested_user_object_id(tvb, offset, tree);
offset+=8;
offset+=4;
dissect_osd_length(tvb, offset, tree);
offset+=8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_flush_osd_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_osd_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_osd_flush_osd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info _U_)
{
if(isreq && iscdb){
dissect_osd_flush_osd_scope(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=39;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static int
dissect_osd_flush_partition_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_partition_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static void
dissect_osd_flush_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_flush_partition_scope(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
offset+=28;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_get_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, TRUE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_list_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_collection_object_id(tvb, offset, tree);
offset+=8;
dissect_osd_list_identifier(tvb, offset, tree);
offset+=4;
dissect_osd_allocation_length(tvb, offset, tree);
offset+=8;
dissect_osd_initial_object_id(tvb, offset, tree);
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_read(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=4;
dissect_osd_length(tvb, offset, tree);
offset+=8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset+=8;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static void
dissect_osd_set_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if(isreq && iscdb){
dissect_osd_option(tvb, offset, tree);
offset++;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset++;
dissect_osd_timestamps_control(tvb, offset, tree);
offset++;
offset+=3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, TRUE);
offset+=8;
dissect_osd_user_object_id(tvb, offset, tree);
offset+=8;
offset+=20;
dissect_osd_attribute_parameters(tvb, offset, tree, cdata);
offset+=28;
dissect_osd_capability(tvb, offset, tree);
offset+=80;
dissect_osd_security_parameters(tvb, offset, tree);
offset+=40;
}
if(isreq && !iscdb){
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata);
}
if(!isreq && !iscdb){
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata);
}
}
static scsi_osd_dissector_t
find_svcaction_dissector(guint16 svcaction)
{
const scsi_osd_svcaction_t *sa=scsi_osd_svcaction;
while(sa&&sa->dissector){
if(sa->svcaction==svcaction){
return sa->dissector;
}
sa++;
}
return NULL;
}
static void
dissect_osd_opcode(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len, scsi_task_data_t *cdata)
{
guint16 svcaction=0;
scsi_osd_dissector_t dissector;
scsi_osd_conv_info_t *conv_info=NULL;
scsi_osd_lun_info_t *lun_info=NULL;
if(!tree) {
return;
}
if(!cdata || !cdata->itl || !cdata->itl->conversation || !cdata->itlq){
return;
}
conv_info=(scsi_osd_conv_info_t *)conversation_get_proto_data(cdata->itl->conversation, proto_scsi_osd);
if(!conv_info){
conv_info=se_new(scsi_osd_conv_info_t);
conv_info->luns=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "SCSI OSD luns tree");
conversation_add_proto_data(cdata->itl->conversation, proto_scsi_osd, conv_info);
}
lun_info=(scsi_osd_lun_info_t *)se_tree_lookup32(conv_info->luns, cdata->itlq->lun);
if(!lun_info){
lun_info=se_new(scsi_osd_lun_info_t);
lun_info->partitions=se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "SCSI OSD partitions tree");
se_tree_insert32(conv_info->luns, cdata->itlq->lun, (void *)lun_info);
}
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_control, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset+=5;
proto_tree_add_item (tree, hf_scsi_osd_add_cdblen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
svcaction=tvb_get_ntohs(tvb, offset);
if(cdata && cdata->itlq){
if((!pinfo->fd->flags.visited) && (!cdata->itlq->extra_data)){
scsi_osd_extra_data_t *extra_data;
extra_data=se_new(scsi_osd_extra_data_t);
extra_data->svcaction=svcaction;
extra_data->gsatype=0;
cdata->itlq->extra_data=extra_data;
}
}
proto_tree_add_item (tree, hf_scsi_osd_svcaction, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if(check_col(pinfo->cinfo, COL_INFO)){
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_const(svcaction, scsi_osd_svcaction_vals, "Unknown OSD Serviceaction"));
}
dissector=find_svcaction_dissector(svcaction);
if(dissector){
(*dissector)(tvb, pinfo, tree, offset, isreq, iscdb, payload_len, cdata, conv_info, lun_info);
}
return;
}
if(cdata && cdata->itlq && cdata->itlq->extra_data){
scsi_osd_extra_data_t *extra_data=(scsi_osd_extra_data_t *)cdata->itlq->extra_data;
svcaction=extra_data->svcaction;
}
if(check_col(pinfo->cinfo, COL_INFO)){
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_const(svcaction, scsi_osd_svcaction_vals, "Unknown OSD Serviceaction"));
}
if(svcaction){
proto_item *it;
it=proto_tree_add_uint_format(tree, hf_scsi_osd_svcaction, tvb, 0, 0, svcaction, "Service Action: 0x%04x", svcaction);
PROTO_ITEM_SET_GENERATED(it);
}
dissector=find_svcaction_dissector(svcaction);
if(dissector){
(*dissector)(tvb, pinfo, tree, offset, isreq, iscdb, payload_len, cdata, conv_info, lun_info);
}
}
void
proto_register_scsi_osd(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_osd_opcode,
{"OSD Opcode", "scsi_osd.opcode", FT_UINT8, BASE_HEX,
VALS (scsi_osd_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_osd_add_cdblen,
{"Additional CDB Length", "scsi_osd.addcdblen", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_svcaction,
{"Service Action", "scsi_osd.svcaction", FT_UINT16, BASE_HEX,
VALS(scsi_osd_svcaction_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_osd_option,
{"Options Byte", "scsi_osd.option", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_option_dpo,
{"DPO", "scsi_osd.option.dpo", FT_BOOLEAN, 8,
TFS(&option_dpo_tfs), 0x10, NULL, HFILL}},
{ &hf_scsi_osd_option_fua,
{"FUA", "scsi_osd.option.fua", FT_BOOLEAN, 8,
TFS(&option_fua_tfs), 0x08, NULL, HFILL}},
{ &hf_scsi_osd_getsetattrib,
{"GET/SET CDBFMT", "scsi_osd.getset", FT_UINT8, BASE_HEX,
VALS(scsi_osd_getsetattrib_vals), 0x30, NULL, HFILL}},
{ &hf_scsi_osd_timestamps_control,
{"Timestamps Control", "scsi_osd.timestamps_control", FT_UINT8, BASE_HEX,
VALS(scsi_osd_timestamps_control_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_osd_formatted_capacity,
{"Formatted Capacity", "scsi_osd.formatted_capacity", FT_UINT64, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_get_attributes_page,
{"Get Attributes Page", "scsi_osd.get_attributes_page", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_get_attributes_list_length,
{"Get Attributes List Length", "scsi_osd.get_attributes_list_length", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_get_attributes_list_offset,
{"Get Attributes List Offset", "scsi_osd.get_attributes_list_offset", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attributes_list_length,
{"Set Attributes List Length", "scsi_osd.set_attributes_list_length", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attributes_list_offset,
{"Set Attributes List Offset", "scsi_osd.set_attributes_list_offset", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_get_attributes_allocation_length,
{"Get Attributes Allocation Length", "scsi_osd.get_attributes_allocation_length", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_retrieved_attributes_offset,
{"Retrieved Attributes Offset", "scsi_osd.retrieved_attributes_offset", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attributes_page,
{"Set Attributes Page", "scsi_osd.set_attributes_page", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attribute_length,
{"Set Attribute Length", "scsi_osd.set_attribute_length", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attribute_number,
{"Set Attribute Number", "scsi_osd.set_attribute_number", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_set_attributes_offset,
{"Set Attributes Offset", "scsi_osd.set_attributes_offset", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_capability_format,
{"Capability Format", "scsi_osd.capability_format", FT_UINT8, BASE_HEX,
VALS(scsi_osd_capability_format_vals), 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_key_version,
{"Key Version", "scsi_osd.key_version", FT_UINT8, BASE_HEX,
NULL, 0xf0, NULL, HFILL}},
{ &hf_scsi_osd_icva,
{"Integrity Check Value Algorithm", "scsi_osd.icva", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_security_method,
{"Security Method", "scsi_osd.security_method", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_capability_expiration_time,
{"Capability Expiration Time", "scsi_osd.capability_expiration_time", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_audit,
{"Audit", "scsi_osd.audit", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_capability_discriminator,
{"Capability Discriminator", "scsi_osd.capability_descriminator", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_object_created_time,
{"Object Created Time", "scsi_osd.object_created_time", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_object_type,
{"Object Type", "scsi_osd.object_type", FT_UINT8, BASE_HEX,
VALS(scsi_osd_object_type_vals), 0, NULL, HFILL}},
{ &hf_scsi_osd_permissions,
{"Permissions", "scsi_osd.permissions", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_permissions_read,
{"READ", "scsi_osd.permissions.read", FT_BOOLEAN, 16,
TFS(&permissions_read_tfs), 0x8000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_write,
{"WRITE", "scsi_osd.permissions.write", FT_BOOLEAN, 16,
TFS(&permissions_write_tfs), 0x4000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_get_attr,
{"GET_ATTR", "scsi_osd.permissions.get_attr", FT_BOOLEAN, 16,
TFS(&permissions_get_attr_tfs), 0x2000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_set_attr,
{"SET_ATTR", "scsi_osd.permissions.set_attr", FT_BOOLEAN, 16,
TFS(&permissions_set_attr_tfs), 0x1000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_create,
{"CREATE", "scsi_osd.permissions.create", FT_BOOLEAN, 16,
TFS(&permissions_create_tfs), 0x0800, NULL, HFILL}},
{ &hf_scsi_osd_permissions_remove,
{"REMOVE", "scsi_osd.permissions.remove", FT_BOOLEAN, 16,
TFS(&permissions_remove_tfs), 0x0400, NULL, HFILL}},
{ &hf_scsi_osd_permissions_obj_mgmt,
{"OBJ_MGMT", "scsi_osd.permissions.obj_mgmt", FT_BOOLEAN, 16,
TFS(&permissions_obj_mgmt_tfs), 0x0200, NULL, HFILL}},
{ &hf_scsi_osd_permissions_append,
{"APPEND", "scsi_osd.permissions.append", FT_BOOLEAN, 16,
TFS(&permissions_append_tfs), 0x0100, NULL, HFILL}},
{ &hf_scsi_osd_permissions_dev_mgmt,
{"DEV_MGMT", "scsi_osd.permissions.dev_mgmt", FT_BOOLEAN, 16,
TFS(&permissions_dev_mgmt_tfs), 0x0080, NULL, HFILL}},
{ &hf_scsi_osd_permissions_global,
{"GLOBAL", "scsi_osd.permissions.global", FT_BOOLEAN, 16,
TFS(&permissions_global_tfs), 0x0040, NULL, HFILL}},
{ &hf_scsi_osd_permissions_pol_sec,
{"POL/SEC", "scsi_osd.permissions.pol_sec", FT_BOOLEAN, 16,
TFS(&permissions_pol_sec_tfs), 0x0020, NULL, HFILL}},
{ &hf_scsi_osd_object_descriptor_type,
{"Object Descriptor Type", "scsi_osd.object_descriptor_type", FT_UINT8, BASE_HEX,
VALS(scsi_osd_object_descriptor_type_vals), 0xf0, NULL, HFILL}},
{ &hf_scsi_osd_object_descriptor,
{"Object Descriptor", "scsi_osd.object_descriptor", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_ricv,
{"Request Integrity Check value", "scsi_osd.ricv", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_request_nonce,
{"Request Nonce", "scsi_osd.request_nonce", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_diicvo,
{"Data-In Integrity Check Value Offset", "scsi_osd.diicvo", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_doicvo,
{"Data-Out Integrity Check Value Offset", "scsi_osd.doicvo", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_requested_partition_id,
{"Requested Partition Id", "scsi_osd.requested_partition_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_sortorder,
{"Sort Order", "scsi_osd.sort_order", FT_UINT8, BASE_DEC,
VALS(scsi_osd_sort_order_vals), 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_partition_id,
{"Partition Id", "scsi_osd.partition_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_list_identifier,
{"List Identifier", "scsi_osd.list_identifier", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_allocation_length,
{"Allocation Length", "scsi_osd.allocation_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_length,
{"Length", "scsi_osd.length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_starting_byte_address,
{"Starting Byte Address", "scsi_osd.starting_byte_address", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_initial_object_id,
{"Initial Object Id", "scsi_osd.initial_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_additional_length,
{"Additional Length", "scsi_osd.additional_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_continuation_object_id,
{"Continuation Object Id", "scsi_osd.continuation_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_user_object_id,
{"User Object Id", "scsi_osd.user_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_list_flags_lstchg,
{"LSTCHG", "scsi_osd.list.lstchg", FT_BOOLEAN, 8,
TFS(&list_lstchg_tfs), 0x02, NULL, HFILL}},
{ &hf_scsi_osd_list_flags_root,
{"ROOT", "scsi_osd.list.root", FT_BOOLEAN, 8,
TFS(&list_root_tfs), 0x01, NULL, HFILL}},
{ &hf_scsi_osd_requested_user_object_id,
{"Requested User Object Id", "scsi_osd.requested_user_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_number_of_user_objects,
{"Number Of User Objects", "scsi_osd.number_of_user_objects", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_key_to_set,
{"Key to Set", "scsi_osd.key_to_set", FT_UINT8, BASE_DEC,
VALS(key_to_set_vals), 0x03, NULL, HFILL}},
{ &hf_scsi_osd_set_key_version,
{"Key Version", "scsi_osd.set_key_version", FT_UINT8, BASE_DEC,
NULL, 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_key_identifier,
{"Key Identifier", "scsi_osd.key_identifier", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_seed,
{"Seed", "scsi_osd.seed", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_collection_fcr,
{"FCR", "scsi_osd.collection.fcr", FT_BOOLEAN, 8,
TFS(&collection_fcr_tfs), 0x01, NULL, HFILL}},
{ &hf_scsi_osd_collection_object_id,
{"Collection Object Id", "scsi_osd.collection_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_requested_collection_object_id,
{"Requested Collection Object Id", "scsi_osd.requested_collection_object_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_partition_created_in,
{ "Created In", "scsi_osd.partition.created_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "The frame this partition was created", HFILL }},
{ &hf_scsi_osd_partition_removed_in,
{ "Removed In", "scsi_osd.partition.removed_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "The frame this partition was removed", HFILL }},
{ &hf_scsi_osd_flush_scope,
{"Flush Scope", "scsi_osd.flush.scope", FT_UINT8, BASE_DEC,
VALS(flush_scope_vals), 0x03, NULL, HFILL}},
{ &hf_scsi_osd_flush_collection_scope,
{"Flush Collection Scope", "scsi_osd.flush_collection.scope", FT_UINT8, BASE_DEC,
VALS(flush_collection_scope_vals), 0x03, NULL, HFILL}},
{ &hf_scsi_osd_flush_partition_scope,
{"Flush Partition Scope", "scsi_osd.flush_partition.scope", FT_UINT8, BASE_DEC,
VALS(flush_partition_scope_vals), 0x03, NULL, HFILL}},
{ &hf_scsi_osd_flush_osd_scope,
{"Flush OSD Scope", "scsi_osd.flush_osd.scope", FT_UINT8, BASE_DEC,
VALS(flush_osd_scope_vals), 0x03, NULL, HFILL}},
{ &hf_scsi_osd_attributes_list_type,
{"Attributes List Type", "scsi_osd.attributes_list.type", FT_UINT8, BASE_HEX,
VALS(attributes_list_type_vals), 0x0f, NULL, HFILL}},
{ &hf_scsi_osd_attributes_list_length,
{"Attributes List Length", "scsi_osd.attributes_list.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attributes_page,
{"Attributes Page", "scsi_osd.attributes.page", FT_UINT32, BASE_HEX,
VALS(attributes_page_vals), 0, NULL, HFILL}},
{ &hf_scsi_osd_attribute_number,
{"Attribute Number", "scsi_osd.attribute.number", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attribute_length,
{"Attribute Length", "scsi_osd.attribute.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_user_object_logical_length,
{"User Object Logical Length", "scsi_osd.user_object.logical_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_osd_option,
&ett_osd_partition,
&ett_osd_attribute_parameters,
&ett_osd_capability,
&ett_osd_permission_bitmask,
&ett_osd_security_parameters,
};
proto_scsi_osd = proto_register_protocol("SCSI_OSD", "SCSI_OSD", "scsi_osd");
proto_register_field_array(proto_scsi_osd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_scsi_osd(void)
{
}
