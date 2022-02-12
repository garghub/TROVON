static proto_item*
dissect_osd_user_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_item *item;
item = proto_tree_add_item(tree, hf_scsi_osd_user_object_id, tvb, offset, 8, ENC_NA);
return item;
}
static void
generic_attribute_dissector(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
scsi_osd_lun_info_t *lun_info _U_, const attribute_page_numbers_t *att)
{
proto_tree_add_item(tree, *att->hf_index, tvb, 0, att->expected_length, ENC_BIG_ENDIAN);
}
static void
partition_id_attribute_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
scsi_osd_lun_info_t *lun_info, const attribute_page_numbers_t *att)
{
dissect_osd_partition_id(pinfo, tvb, 0, tree, *att->hf_index, lun_info, FALSE, FALSE);
}
static void
dissect_osd2_isolation(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd2_isolation, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd2_list_attr(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd2_list_attr, tvb, offset, 1, ENC_BIG_ENDIAN);
}
const attribute_page_numbers_t *
osd_lookup_attribute(guint32 page, guint32 number)
{
const attribute_pages_t *ap;
const attribute_page_numbers_t *apn;
apn = NULL;
for (ap=attribute_pages;ap->attributes;ap++) {
if (ap->page == page) {
apn = ap->attributes;
break;
}
}
if (!apn) return NULL;
for (;apn->name;apn++) {
if (apn->number == number) {
break;
}
}
if (!apn->name) return NULL;
return apn;
}
static guint32
dissect_osd_attribute_list_entry(packet_info *pinfo, tvbuff_t *tvb,
proto_tree *tree, proto_item *item,
guint32 offset, scsi_osd_lun_info_t *lun_info,
gboolean osd2)
{
guint16 attribute_length;
guint32 page, number;
const attribute_page_numbers_t *apn;
page = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
number = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (osd2) {
offset += 6;
}
attribute_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attribute_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_append_text(item, " 0x%08x (%s)", page, val_to_str_ext_const(page, &attributes_page_vals_ext, "Unknown"));
proto_item_append_text(item, " 0x%08x", number);
apn= osd_lookup_attribute(page, number);
if (!apn) {
expert_add_info(pinfo, item, &ei_osd_attr_unknown);
proto_item_append_text(item, " (Unknown)");
} else {
proto_item_append_text(item, " (%s)", apn->name);
if (attribute_length) {
if (attribute_length != apn->expected_length) {
proto_tree_add_expert_format(tree, pinfo, &ei_osd_attr_length_invalid,
tvb, 0, attribute_length, "%s", apn->name);
} else {
tvbuff_t *next_tvb = tvb_new_subset_length(tvb, offset, attribute_length);
apn->dissector(next_tvb, pinfo, tree, lun_info, apn);
}
}
}
offset += attribute_length;
if (osd2 && (attribute_length&7)) {
offset += 8-(attribute_length&7);
}
return offset;
}
static void
dissect_osd_attributes_list(packet_info *pinfo, tvbuff_t *tvb, int offset,
proto_tree *tree, scsi_osd_lun_info_t *lun_info,
gboolean osd2)
{
guint8 type;
guint32 length;
guint32 page, number;
int start_offset = offset;
proto_item *item, *list_type_item;
const attribute_page_numbers_t *apn;
type = tvb_get_guint8(tvb, offset)&0x0f;
list_type_item = proto_tree_add_item(tree, hf_scsi_osd_attributes_list_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += (osd2?3:1);
if (osd2) {
length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd2_attributes_list_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd_attributes_list_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (!osd2 && type == 1) {
length = tvb_reported_length_remaining(tvb, offset);
}
length += (osd2?8:4);
while ( (guint32)(offset-start_offset)<length ) {
proto_item *ti;
proto_tree *tt;
guint32 attribute_entry_length;
switch (type) {
case 0x01:
attribute_entry_length = 8;
break;
case 0x0f:
attribute_entry_length = 18+tvb_get_ntohs(tvb, offset+16);
break;
case 0x09:
if (osd2) {
attribute_entry_length = 16+tvb_get_ntohs(tvb, offset+14);
} else {
attribute_entry_length = 10+tvb_get_ntohs(tvb, offset+8);
}
break;
default:
expert_add_info(pinfo, list_type_item, &ei_osd_unknown_attributes_list_type);
return;
}
if ((guint32)(offset-start_offset)+attribute_entry_length>length) break;
tt = proto_tree_add_subtree(tree, tvb, offset, attribute_entry_length, ett_osd_attribute, &ti, "Attribute:");
switch (type) {
case 0x01:
page = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tt, hf_scsi_osd_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
number = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(tt, hf_scsi_osd_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_append_text(ti, " 0x%08x (%s)", page, val_to_str_ext_const(page, &attributes_page_vals_ext, "Unknown"));
proto_item_append_text(ti, " 0x%08x", number);
apn = osd_lookup_attribute(page, number);
if (!apn) {
proto_item_append_text(ti, " (Unknown)");
proto_item_append_text(item, " (Unknown)");
} else {
proto_item_append_text(ti, " (%s)", apn->name);
proto_item_append_text(item, " (%s)", apn->name);
}
break;
case 0x0f:
dissect_osd_user_object_id(tvb, offset, tt);
offset += 8;
case 0x09:
offset = dissect_osd_attribute_list_entry(pinfo, tvb, tt, ti, offset, lun_info, osd2);
break;
}
}
}
static void
dissect_osd_option(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree;
proto_item *it;
guint8 option;
option = tvb_get_guint8(tvb, offset);
it = proto_tree_add_item(parent_tree, hf_scsi_osd_option, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(it, ett_osd_option);
proto_tree_add_item(tree, hf_scsi_osd_option_dpo, tvb, offset, 1, ENC_BIG_ENDIAN);
if (option&0x10) {
proto_item_append_text(tree, " DPO");
}
proto_tree_add_item(tree, hf_scsi_osd_option_fua, tvb, offset, 1, ENC_BIG_ENDIAN);
if (option&0x08) {
proto_item_append_text(tree, " FUA");
}
}
static void
dissect_osd_getsetattrib(tvbuff_t *tvb, int offset, proto_tree *tree, scsi_task_data_t *cdata)
{
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
scsi_osd_extra_data_t *extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
extra_data->gsatype = (tvb_get_guint8(tvb, offset)>>4)&0x03;
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
static void
dissect_osd_offset(packet_info *pinfo, tvbuff_t *tvb, int offset,
proto_tree *tree, int field, guint32 *raw_value_ptr,
gboolean osd2)
{
guint32 value = *raw_value_ptr;
if (value != 0xFFFFFFFF) {
if (!osd2) {
value = (value & 0x0fffffff) << ((value>>28) & 0x0f);
value <<= 8;
} else {
int exponent = (value>>28);
guint32 mantissa = (value&0x0FFFFFFF);
if (exponent&0x8) {
exponent = -(((~exponent)&7)+1);
if (exponent <=- 6 && mantissa != 0xFFFFFFF) {
proto_item *item;
item = proto_tree_add_item(tree, field, tvb, offset, 4, value);
expert_add_info(pinfo, item, &ei_osd2_invalid_offset);
*raw_value_ptr = 0xFFFFFFFF;
return;
}
}
value = mantissa << (exponent+8);
}
}
proto_tree_add_uint(tree, field, tvb, offset, 4, value);
*raw_value_ptr = value;
}
static int
dissect_osd_attribute_parameters(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *parent_tree, scsi_task_data_t *cdata)
{
guint8 gsatype = 0;
proto_tree *tree;
scsi_osd_extra_data_t *extra_data = NULL;
gboolean osd2;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 28,
ett_osd_attribute_parameters, NULL, "Attribute Parameters");
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype = extra_data->gsatype;
osd2 = extra_data->osd2;
} else {
return offset;
}
switch (gsatype) {
case 1:
if (osd2) {
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd2_set_attribute_value, tvb, offset, 18, ENC_NA);
offset += 18;
}
break;
case 2:
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_allocation_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_retrieved_attributes_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attribute_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 3:
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_list_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.get_list_length = tvb_get_ntohl(tvb, offset);
offset += 4;
extra_data->u.al.get_list_offset = tvb_get_ntohl(tvb, offset);
dissect_osd_offset(pinfo, tvb, offset, tree, hf_scsi_osd_get_attributes_list_offset,
&extra_data->u.al.get_list_offset, osd2);
if (extra_data->u.al.get_list_offset == 0xFFFFFFFF) {
extra_data->u.al.get_list_length = 0;
}
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_get_attributes_allocation_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.get_list_allocation_length = tvb_get_ntohl(tvb, offset);
offset += 4;
extra_data->u.al.retrieved_list_offset = tvb_get_ntohl(tvb, offset);
dissect_osd_offset(pinfo, tvb, offset, tree, hf_scsi_osd_retrieved_attributes_offset,
&extra_data->u.al.retrieved_list_offset, osd2);
if (extra_data->u.al.retrieved_list_offset == 0xFFFFFFFF) {
extra_data->u.al.get_list_allocation_length = 0;
}
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_set_attributes_list_length, tvb, offset, 4, ENC_BIG_ENDIAN);
extra_data->u.al.set_list_length = tvb_get_ntohl(tvb, offset);
offset += 4;
extra_data->u.al.set_list_offset = tvb_get_ntohl(tvb, offset);
dissect_osd_offset(pinfo, tvb, offset, tree, hf_scsi_osd_set_attributes_list_offset,
&extra_data->u.al.set_list_offset, osd2);
if (extra_data->u.al.set_list_offset == 0xFFFFFFFF) {
extra_data->u.al.set_list_length = 0;
}
offset += 4;
offset += 4;
break;
}
return offset;
}
static void
dissect_osd_attribute_data_out(packet_info *pinfo, tvbuff_t *tvb, int offset _U_,
proto_tree *tree, scsi_task_data_t *cdata,
scsi_osd_lun_info_t *lun_info)
{
guint8 gsatype = 0;
proto_tree *subtree;
scsi_osd_extra_data_t *extra_data = NULL;
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype = extra_data->gsatype;
} else {
return;
}
switch (gsatype) {
case 2:
break;
case 3:
if (extra_data->u.al.get_list_length) {
subtree = proto_tree_add_subtree(tree, tvb, extra_data->u.al.get_list_offset, extra_data->u.al.get_list_length,
ett_osd_get_attributes, NULL, "Get Attributes Segment");
dissect_osd_attributes_list(pinfo, tvb, extra_data->u.al.get_list_offset, subtree, lun_info, extra_data->osd2);
}
if (extra_data->u.al.set_list_length) {
subtree = proto_tree_add_subtree(tree, tvb, extra_data->u.al.set_list_offset, extra_data->u.al.set_list_length,
ett_osd_get_attributes, NULL, "Set Attributes Segment");
dissect_osd_attributes_list(pinfo, tvb, extra_data->u.al.set_list_offset, subtree, lun_info, extra_data->osd2);
}
break;
}
}
static void
dissect_osd_attribute_data_in(packet_info *pinfo, tvbuff_t *tvb, int offset _U_, proto_tree *tree, scsi_task_data_t *cdata, scsi_osd_lun_info_t *lun_info)
{
guint8 gsatype = 0;
scsi_osd_extra_data_t *extra_data = NULL;
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
gsatype = extra_data->gsatype;
} else {
return;
}
switch (gsatype) {
case 2:
break;
case 3:
if (extra_data->u.al.get_list_allocation_length) {
dissect_osd_attributes_list(pinfo, tvb, extra_data->u.al.retrieved_list_offset, tree, lun_info, extra_data->osd2);
}
break;
}
}
static void
dissect_osd2_cdb_continuation_length(packet_info *pinfo, tvbuff_t *tvb,
guint32 offset, proto_tree *tree,
scsi_task_data_t *cdata)
{
scsi_osd_extra_data_t *extra_data;
guint32 continuation_length;
proto_item *item;
continuation_length = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(tree, hf_scsi_osd2_cdb_continuation_length, tvb, offset, 4, ENC_BIG_ENDIAN);
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
extra_data->continuation_length = continuation_length;
}
if (continuation_length>0 && continuation_length<40) {
expert_add_info(pinfo, item, &ei_osd2_cdb_continuation_length_invalid);
}
}
static void dissect_osd2_query_list_descriptor(packet_info *pinfo, tvbuff_t *tvb, guint32 offset, proto_tree *tree, guint32 length) {
guint32 end = offset+length;
proto_tree_add_item(tree, hf_scsi_osd2_query_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 3;
while (offset<end) {
guint32 page, number;
guint32 min_value_length, max_value_length;
guint32 min_value_offset, max_value_offset;
proto_item *item;
const attribute_page_numbers_t *apn;
offset += 2;
proto_tree_add_item(tree, hf_scsi_osd2_query_entry_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
page = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_scsi_osd2_query_attributes_page, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
number = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(tree, hf_scsi_osd2_query_attribute_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
apn = osd_lookup_attribute(page, number);
if (!apn) {
expert_add_info(pinfo, item, &ei_osd_attr_unknown);
proto_item_append_text(item, " (Unknown)");
} else {
proto_item_append_text(item, " (%s)", apn->name);
}
proto_tree_add_item(tree, hf_scsi_osd2_query_minimum_attribute_value_length, tvb, offset, 2, ENC_BIG_ENDIAN);
min_value_length = tvb_get_ntohs(tvb, offset);
offset += 2;
max_value_offset = offset;
offset += min_value_length;
item = proto_tree_add_item(tree, hf_scsi_osd2_query_maximum_attribute_value_length, tvb, offset, 2, ENC_BIG_ENDIAN);
max_value_length = tvb_get_ntohs(tvb, offset);
offset += 2;
min_value_offset = offset;
offset += max_value_length;
if (max_value_length == min_value_length) {
unsigned int i;
for (i=0; i<max_value_length; i++) {
if (tvb_get_guint8(tvb, max_value_offset+i) != tvb_get_guint8(tvb, min_value_offset+i)) return;
}
expert_add_info(pinfo, item, &ei_osd2_query_values_equal);
}
}
}
static void
dissect_osd2_cdb_continuation(packet_info *pinfo, tvbuff_t *tvb, guint32 offset,
proto_tree *tree, scsi_task_data_t *cdata)
{
scsi_osd_extra_data_t *extra_data = NULL;
proto_item *item;
guint8 format;
guint16 sa;
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
}
if (!extra_data || extra_data->continuation_length<40) return;
item = proto_tree_add_item(tree, hf_scsi_osd2_cdb_continuation_format, tvb, offset, 1, ENC_BIG_ENDIAN);
format = tvb_get_guint8(tvb, offset);
if (format != 0x01) {
expert_add_info(pinfo, item, &ei_osd2_cdb_continuation_format_unknown);
return;
}
offset += 1;
offset += 1;
item = proto_tree_add_item(tree, hf_scsi_osd2_continued_service_action, tvb, offset, 2, ENC_BIG_ENDIAN);
sa = tvb_get_ntohs(tvb, offset);
if (sa != extra_data->svcaction) {
expert_add_info(pinfo, item, &ei_osd2_continued_service_action_mismatch);
}
offset += 2;
offset += 36;
while (offset<extra_data->continuation_length) {
guint16 type;
guint32 length, padlen;
proto_item *item_type, *item_length;
item_type= proto_tree_add_item(tree, hf_scsi_osd2_cdb_continuation_descriptor_type, tvb, offset, 2, ENC_BIG_ENDIAN);
type = tvb_get_ntohs(tvb, offset);
offset += 2;
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd2_cdb_continuation_descriptor_pad_length, tvb, offset, 1, ENC_BIG_ENDIAN);
padlen = tvb_get_guint8(tvb, offset)&7;
offset += 1;
item_length = proto_tree_add_item(tree, hf_scsi_osd2_cdb_continuation_descriptor_length, tvb, offset, 4, ENC_BIG_ENDIAN);
length = tvb_get_ntohl(tvb, offset);
offset += 4;
switch (type) {
case 0x0000: break;
case 0x0001: break;
case 0x0002: dissect_osd2_query_list_descriptor(pinfo, tvb, offset, tree, length);
case 0x0100: break;
case 0x0101: break;
case 0xFFEE: break;
default: expert_add_info(pinfo, item_type, &ei_osd2_cdb_continuation_descriptor_type_unknown);
}
if ((length+padlen)%8) {
expert_add_info(pinfo, item_length, &ei_osd2_cdb_continuation_descriptor_length_invalid);
return;
}
if (offset + length + padlen > offset) {
offset += length+padlen;
}
}
}
static void
dissect_osd_permissions(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree = NULL;
proto_item *it = NULL;
guint16 permissions;
permissions = tvb_get_ntohs(tvb, offset);
if (parent_tree) {
it = proto_tree_add_item(parent_tree, hf_scsi_osd_permissions, tvb, offset, 2, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(it, ett_osd_permission_bitmask);
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_read, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x8000) {
proto_item_append_text(tree, " READ");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_write, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x4000) {
proto_item_append_text(tree, " WRITE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_get_attr, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x2000) {
proto_item_append_text(tree, " GET_ATTR");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_set_attr, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x1000) {
proto_item_append_text(tree, " SET_ATTR");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_create, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0800) {
proto_item_append_text(tree, " CREATE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_remove, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0400) {
proto_item_append_text(tree, " REMOVE");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_obj_mgmt, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0200) {
proto_item_append_text(tree, " OBJ_MGMT");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_append, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0100) {
proto_item_append_text(tree, " APPEND");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_dev_mgmt, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0080) {
proto_item_append_text(tree, " DEV_MGMT");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_global, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0040) {
proto_item_append_text(tree, " GLOBAL");
}
proto_tree_add_item(tree, hf_scsi_osd_permissions_pol_sec, tvb, offset, 2, ENC_BIG_ENDIAN);
if (permissions&0x0020) {
proto_item_append_text(tree, " POL/SEC");
}
}
static void
dissect_osd_capability(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree;
guint8 format;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 80,
ett_osd_capability, NULL, "Capability");
proto_tree_add_item(tree, hf_scsi_osd_capability_format, tvb, offset, 1, ENC_BIG_ENDIAN);
format = tvb_get_guint8(tvb, offset)&0x0F;
offset += 1;
if (format != 1) return;
proto_tree_add_item(tree, hf_scsi_osd_key_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_osd_icva, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd_security_method, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd_capability_expiration_time, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_scsi_osd_audit, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_scsi_osd_capability_discriminator, tvb, offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(tree, hf_scsi_osd_object_created_time, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_scsi_osd_object_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
dissect_osd_permissions(tvb, offset, tree);
offset += 5;
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd_object_descriptor_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd_object_descriptor, tvb, offset, 24, ENC_NA);
return;
}
static int
dissect_osd_security_parameters(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_tree *tree;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 40,
ett_osd_security_parameters, NULL, "Security Parameters");
proto_tree_add_item(tree, hf_scsi_osd_ricv, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_scsi_osd_request_nonce, tvb, offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(tree, hf_scsi_osd_diicvo, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_scsi_osd_doicvo, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static void
dissect_osd_format_osd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info _U_)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 23;
dissect_osd_formatted_capacity(tvb, offset, tree);
offset += 8;
offset += 8;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static proto_item*
dissect_osd_partition_id(packet_info *pinfo, tvbuff_t *tvb, int offset,
proto_tree *tree, int hf_index,
scsi_osd_lun_info_t *lun_info, gboolean is_created,
gboolean is_removed)
{
proto_item *item = NULL;
guint32 partition_id[2];
item = proto_tree_add_item(tree, hf_index, tvb, offset, 8, ENC_BIG_ENDIAN);
partition_id[0] = tvb_get_ntohl(tvb, offset);
partition_id[1] = tvb_get_ntohl(tvb, offset+4);
if (!partition_id[0] && !partition_id[1]) {
proto_item_append_text(item, " (ROOT partition)");
} else {
partition_info_t *part_info;
wmem_tree_key_t pikey[2];
proto_tree *partition_tree = NULL;
pikey[0].length = 2;
pikey[0].key = partition_id;
pikey[1].length = 0;
part_info = (partition_info_t *)wmem_tree_lookup32_array(lun_info->partitions, &pikey[0]);
if (!part_info) {
part_info = wmem_new(wmem_file_scope(), partition_info_t);
part_info->created_in = 0;
part_info->removed_in = 0;
pikey[0].length = 2;
pikey[0].key = partition_id;
pikey[1].length = 0;
wmem_tree_insert32_array(lun_info->partitions, &pikey[0], part_info);
}
if (is_created) {
part_info->created_in = pinfo->num;
}
if (is_removed) {
part_info->removed_in = pinfo->num;
}
if (item) {
partition_tree = proto_item_add_subtree(item, ett_osd_partition);
}
if (part_info->created_in) {
proto_item *tmp_item;
tmp_item = proto_tree_add_uint(partition_tree, hf_scsi_osd_partition_created_in, tvb, 0, 0, part_info->created_in);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
if (part_info->removed_in) {
proto_item *tmp_item;
tmp_item = proto_tree_add_uint(partition_tree, hf_scsi_osd_partition_removed_in, tvb, 0, 0, part_info->removed_in);
PROTO_ITEM_SET_GENERATED(tmp_item);
}
}
return item;
}
static void
dissect_osd_create_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
gboolean osd2 = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
if (osd2) dissect_osd2_isolation(tvb, offset, tree);
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_requested_partition_id, lun_info, TRUE, FALSE);
offset += 8;
offset += 24;
if (osd2) {
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
} else {
}
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd2_cdb_continuation(pinfo, tvb, offset, tree, cdata);
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_sortorder(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_sortorder, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_osd_list_identifier(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_list_identifier, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static void
dissect_osd_allocation_length(tvbuff_t *tvb, int offset, proto_tree *tree, scsi_task_data_t *cdata)
{
proto_tree_add_item(tree, hf_scsi_osd_allocation_length, tvb, offset, 8, ENC_BIG_ENDIAN);
if (cdata) {
guint64 alloc_len = tvb_get_ntoh64(tvb, offset);
if (alloc_len>G_GINT64_CONSTANT(0xFFFFFFFF)) {
alloc_len = G_GINT64_CONSTANT(0xFFFFFFFF);
}
cdata->itlq->alloc_len = (guint32)alloc_len;
}
}
static int
dissect_osd_initial_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_initial_object_id, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int
dissect_osd_additional_length(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_additional_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_osd_continuation_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_continuation_object_id, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static proto_item*
dissect_osd_collection_object_id(tvbuff_t *tvb, int offset, proto_tree *tree, const int hfindex)
{
proto_item *item;
item = proto_tree_add_item(tree, hfindex, tvb, offset, 8, ENC_NA);
return item;
}
static void
dissect_osd_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
guint svcaction = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction;
gboolean list_collection = (svcaction == 0x8817) || (svcaction == 0x8897);
gboolean osd2 = svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
if (osd2) dissect_osd2_isolation(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
if (!list_collection) dissect_osd_sortorder(tvb, offset, tree);
if (osd2) dissect_osd2_list_attr(tvb, offset, tree);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
if (list_collection) {
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_collection_object_id);
} else {
}
offset += 8;
if (osd2) {
dissect_osd_allocation_length(tvb, offset, tree, cdata);
offset += 8;
dissect_osd_initial_object_id(tvb, offset, tree);
offset += 8;
dissect_osd_list_identifier(tvb, offset, tree);
offset += 4;
} else {
dissect_osd_list_identifier(tvb, offset, tree);
offset += 4;
dissect_osd_allocation_length(tvb, offset, tree, cdata);
offset += 8;
dissect_osd_initial_object_id(tvb, offset, tree);
offset += 8;
}
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
guint64 additional_length;
guint64 allocation_length;
guint64 remaining_length;
gboolean is_root_or_coltn;
guint8 format = 0;
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
allocation_length = cdata->itlq->alloc_len;
remaining_length = tvb_captured_length_remaining(tvb, offset);
if (remaining_length<allocation_length) allocation_length = remaining_length;
if (allocation_length<24) return;
additional_length = tvb_get_ntoh64(tvb, offset);
if (allocation_length<additional_length) additional_length = allocation_length;
dissect_osd_additional_length(tvb, offset, tree);
offset += 8;
dissect_osd_continuation_object_id(tvb, offset, tree);
offset += 8;
dissect_osd_list_identifier(tvb, offset, tree);
offset += 4;
offset += 3;
proto_tree_add_item(tree, hf_scsi_osd_list_flags_lstchg, tvb, offset, 1, ENC_BIG_ENDIAN);
if (osd2) {
proto_item *item;
item = proto_tree_add_item(tree, hf_scsi_osd2_object_descriptor_format, tvb, offset, 1, ENC_BIG_ENDIAN);
format = tvb_get_guint8(tvb, offset)>>2;
if (format == 0x01 || format == 0x02) {
is_root_or_coltn = TRUE;
if (list_collection) format = 0;
} else if (format == 0x11 || format == 0x12) {
is_root_or_coltn = TRUE;
if (!list_collection) format = 0;
} else if (format == 0x21 || format == 0x22) {
is_root_or_coltn = FALSE;
} else format = 0;
if (!format) {
expert_add_info(pinfo, item, &ei_osd2_invalid_object_descriptor_format);
return;
}
} else {
if (list_collection) {
proto_tree_add_item(tree, hf_scsi_osd_list_collection_flags_coltn, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_scsi_osd_list_flags_root, tvb, offset, 1, ENC_BIG_ENDIAN);
}
is_root_or_coltn = tvb_get_guint8(tvb, offset)&0x01;
}
offset += 1;
while (additional_length > (offset-8)) {
proto_item *ti;
if (is_root_or_coltn) {
if (list_collection) {
ti = dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_collection_object_id);
} else {
ti = dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
}
} else {
ti = dissect_osd_user_object_id(tvb, offset, tree);
}
offset += 8;
if (osd2 && (format&0x02)) {
guint32 attr_list_end;
proto_tree *subtree;
if (offset+8>additional_length) break;
subtree = proto_item_add_subtree(ti, ett_osd_multi_object);
proto_tree_add_item(subtree, hf_scsi_osd_object_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 5;
attr_list_end = offset+2+tvb_get_ntohs(tvb, offset);
offset += 2;
if (attr_list_end>additional_length+8) break;
while (offset+16<attr_list_end) {
guint32 attribute_length = tvb_get_ntohs(tvb, offset+14);
proto_item *att_item;
proto_tree *att_tree = proto_tree_add_subtree(subtree, tvb, offset, 16+attribute_length, ett_osd_attribute, &att_item, "Attribute:");
offset = dissect_osd_attribute_list_entry(pinfo, tvb, att_tree, att_item, offset, lun_info, TRUE);
}
offset = attr_list_end;
}
}
}
}
static int
dissect_osd_requested_user_object_id(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_requested_user_object_id, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int
dissect_osd_number_of_user_objects(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_number_of_user_objects, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static void
dissect_osd_create(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_requested_user_object_id(tvb, offset, tree);
offset += 8;
offset += 4;
dissect_osd_number_of_user_objects(tvb, offset, tree);
offset += 2;
offset += 14;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_remove_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
gboolean osd2 = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
if (osd2) dissect_osd2_isolation(tvb, offset, tree);
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
if (osd2) proto_tree_add_item(tree, hf_scsi_osd2_remove_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, TRUE);
offset += 8;
offset += 24;
if (osd2) {
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
} else {
}
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd2_cdb_continuation(pinfo, tvb, offset, tree, cdata);
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
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
if (isreq && iscdb) {
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_key_to_set(tvb, offset, tree);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_set_key_version(tvb, offset, tree);
offset += 1;
dissect_osd_key_identifier(tvb, offset, tree);
offset += 7;
dissect_osd_seed(tvb, offset, tree);
offset += 20;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_remove(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 20;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_collection_fcr(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_collection_fcr, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_osd_remove_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
gboolean osd2 = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_collection_object_id);
offset += 8;
offset += 16;
if (osd2) {
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
} else {
}
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd2_cdb_continuation(pinfo, tvb, offset, tree, cdata);
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_length(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_length, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_osd_starting_byte_address(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_starting_byte_address, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static void
dissect_osd_write(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 4;
dissect_osd_length(tvb, offset, tree);
offset += 8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset += 8;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_create_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_requested_collection_object_id);
offset += 8;
offset += 20;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_flush_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
dissect_osd_flush(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_flush_scope(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 20;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_flush_collection_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_collection_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
dissect_osd_flush_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_flush_collection_scope(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
dissect_osd_collection_fcr(tvb, offset, tree);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_collection_object_id);
offset += 8;
offset += 20;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_append(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 4;
dissect_osd_length(tvb, offset, tree);
offset += 8;
offset += 8;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_create_and_write(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_requested_user_object_id(tvb, offset, tree);
offset += 8;
offset += 4;
dissect_osd_length(tvb, offset, tree);
offset += 8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset += 8;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_flush_osd_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_osd_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
dissect_osd_flush_osd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info _U_)
{
if (isreq && iscdb) {
dissect_osd_flush_osd_scope(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 39;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static int
dissect_osd_flush_partition_scope(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_scsi_osd_flush_partition_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
dissect_osd_flush_partition(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_flush_partition_scope(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
offset += 28;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_get_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
gboolean osd2 = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 16;
if (osd2) {
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
} else {
}
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_read(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 4;
dissect_osd_length(tvb, offset, tree);
offset += 8;
dissect_osd_starting_byte_address(tvb, offset, tree);
offset += 8;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd_set_attributes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
gboolean osd2 = ((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->svcaction&0x80;
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = osd2;
if (isreq && iscdb) {
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
offset += 16;
if (osd2) {
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
} else {
}
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += osd2?104:80;
dissect_osd_security_parameters(tvb, offset, tree);
offset += osd2?52:40;
}
if (isreq && !iscdb) {
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd2_create_user_tracking_collection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = TRUE;
if (isreq && iscdb) {
dissect_osd2_isolation(tvb, offset, tree);
dissect_osd_option(tvb, offset, tree);
offset += 1;
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_requested_collection_object_id);
offset += 8;
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd2_source_collection_object_id);
offset += 8;
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 104;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 52;
}
if (isreq && !iscdb) {
dissect_osd2_cdb_continuation(pinfo, tvb, offset, tree, cdata);
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
}
}
static void
dissect_osd2_query(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_,
scsi_osd_conv_info_t *conv_info _U_,
scsi_osd_lun_info_t *lun_info)
{
((scsi_osd_extra_data_t *)cdata->itlq->extra_data)->osd2 = TRUE;
if (isreq && iscdb) {
dissect_osd2_isolation(tvb, offset, tree);
offset += 1;
proto_tree_add_item(tree, hf_scsi_osd2_immed_tr, tvb, offset, 1, ENC_BIG_ENDIAN);
dissect_osd_getsetattrib(tvb, offset, tree, cdata);
offset += 1;
dissect_osd_timestamps_control(tvb, offset, tree);
offset += 1;
offset += 3;
dissect_osd_partition_id(pinfo, tvb, offset, tree, hf_scsi_osd_partition_id, lun_info, FALSE, FALSE);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd_collection_object_id);
offset += 8;
dissect_osd_allocation_length(tvb, offset, tree, cdata);
offset += 8;
dissect_osd_collection_object_id(tvb, offset, tree, hf_scsi_osd2_matches_collection_object_id);
offset += 8;
dissect_osd2_cdb_continuation_length(pinfo, tvb, offset, tree, cdata);
offset += 4;
dissect_osd_attribute_parameters(pinfo, tvb, offset, tree, cdata);
offset += 28;
dissect_osd_capability(tvb, offset, tree);
offset += 104;
dissect_osd_security_parameters(tvb, offset, tree);
offset += 52;
}
if (isreq && !iscdb) {
dissect_osd2_cdb_continuation(pinfo, tvb, offset, tree, cdata);
dissect_osd_attribute_data_out(pinfo, tvb, offset, tree, cdata, lun_info);
}
if (!isreq && !iscdb) {
guint64 additional_length;
guint64 allocation_length;
guint64 remaining_length;
guint8 format;
proto_item *item;
dissect_osd_attribute_data_in(pinfo, tvb, offset, tree, cdata, lun_info);
allocation_length = cdata->itlq->alloc_len;
remaining_length = tvb_captured_length_remaining(tvb, offset);
if (remaining_length<allocation_length) allocation_length = remaining_length;
if (allocation_length<12) return;
additional_length = tvb_get_ntoh64(tvb, offset);
if ((guint32)(allocation_length-8)<additional_length) additional_length = (guint32)(allocation_length-8);
dissect_osd_additional_length(tvb, offset, tree);
offset += 8;
offset += 3;
item = proto_tree_add_item(tree, hf_scsi_osd2_object_descriptor_format, tvb, offset, 1, ENC_BIG_ENDIAN);
format = tvb_get_guint8(tvb, offset)>>2;
offset += 1;
if (format != 0x21) {
expert_add_info(pinfo, item, &ei_osd2_invalid_object_descriptor_format);
return;
}
while (additional_length > (offset-4)) {
dissect_osd_user_object_id(tvb, offset, tree);
offset += 8;
}
}
}
static scsi_osd_dissector_t
find_svcaction_dissector(guint16 svcaction)
{
const scsi_osd_svcaction_t *sa = scsi_osd_svcaction;
while (sa && sa->dissector) {
if (sa->svcaction == svcaction) {
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
guint16 svcaction = 0;
scsi_osd_dissector_t dissector;
scsi_osd_conv_info_t *conv_info;
scsi_osd_lun_info_t *lun_info;
if (!tree) {
return;
}
if (!cdata || !cdata->itl || !cdata->itl->conversation || !cdata->itlq) {
return;
}
conv_info = (scsi_osd_conv_info_t *)conversation_get_proto_data(cdata->itl->conversation, proto_scsi_osd);
if (!conv_info) {
conv_info = wmem_new(wmem_file_scope(), scsi_osd_conv_info_t);
conv_info->luns = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(cdata->itl->conversation, proto_scsi_osd, conv_info);
}
lun_info = (scsi_osd_lun_info_t *)wmem_tree_lookup32(conv_info->luns, cdata->itlq->lun);
if (!lun_info) {
lun_info = wmem_new(wmem_file_scope(), scsi_osd_lun_info_t);
lun_info->partitions = wmem_tree_new(wmem_file_scope());
wmem_tree_insert32(conv_info->luns, cdata->itlq->lun, (void *)lun_info);
}
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_control, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 5;
proto_tree_add_item (tree, hf_scsi_osd_add_cdblen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
svcaction = tvb_get_ntohs(tvb, offset);
if (cdata && cdata->itlq) {
if ((!pinfo->fd->flags.visited) || (!cdata->itlq->extra_data)) {
scsi_osd_extra_data_t *extra_data;
extra_data = wmem_new0(wmem_file_scope(), scsi_osd_extra_data_t);
extra_data->svcaction = svcaction;
cdata->itlq->extra_data = extra_data;
}
}
proto_tree_add_item (tree, hf_scsi_osd_svcaction, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(svcaction, &scsi_osd_svcaction_vals_ext, "Unknown OSD Service Action"));
dissector = find_svcaction_dissector(svcaction);
if (dissector) {
(*dissector)(tvb, pinfo, tree, offset, isreq, iscdb, payload_len, cdata, conv_info, lun_info);
}
return;
}
if (cdata && cdata->itlq && cdata->itlq->extra_data) {
scsi_osd_extra_data_t *extra_data = (scsi_osd_extra_data_t *)cdata->itlq->extra_data;
svcaction = extra_data->svcaction;
}
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext_const(svcaction, &scsi_osd_svcaction_vals_ext, "Unknown OSD Service Action"));
if (svcaction) {
proto_item *it;
it = proto_tree_add_uint_format_value(tree, hf_scsi_osd_svcaction, tvb, 0, 0, svcaction, "0x%04x", svcaction);
PROTO_ITEM_SET_GENERATED(it);
}
dissector = find_svcaction_dissector(svcaction);
if (dissector) {
(*dissector)(tvb, pinfo, tree, offset, isreq, iscdb, payload_len, cdata, conv_info, lun_info);
}
}
void
proto_register_scsi_osd(void)
{
expert_module_t *expert_scsi_osd;
static hf_register_info hf[] = {
{ &hf_scsi_osd_opcode,
{"OSD Opcode", "scsi_osd.opcode", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&scsi_osd_vals_ext, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_add_cdblen,
{"Additional CDB Length", "scsi_osd.addcdblen", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_svcaction,
{"Service Action", "scsi_osd.svcaction", FT_UINT16, BASE_HEX | BASE_EXT_STRING,
&scsi_osd_svcaction_vals_ext, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_option,
{"Options Byte", "scsi_osd.option", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_osd_option_dpo,
{"DPO", "scsi_osd.option.dpo", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL}},
{ &hf_scsi_osd_option_fua,
{"FUA", "scsi_osd.option.fua", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL}},
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
TFS(&tfs_set_notset), 0x8000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_write,
{"WRITE", "scsi_osd.permissions.write", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x4000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_get_attr,
{"GET_ATTR", "scsi_osd.permissions.get_attr", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x2000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_set_attr,
{"SET_ATTR", "scsi_osd.permissions.set_attr", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x1000, NULL, HFILL}},
{ &hf_scsi_osd_permissions_create,
{"CREATE", "scsi_osd.permissions.create", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0800, NULL, HFILL}},
{ &hf_scsi_osd_permissions_remove,
{"REMOVE", "scsi_osd.permissions.remove", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0400, NULL, HFILL}},
{ &hf_scsi_osd_permissions_obj_mgmt,
{"OBJ_MGMT", "scsi_osd.permissions.obj_mgmt", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0200, NULL, HFILL}},
{ &hf_scsi_osd_permissions_append,
{"APPEND", "scsi_osd.permissions.append", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0100, NULL, HFILL}},
{ &hf_scsi_osd_permissions_dev_mgmt,
{"DEV_MGMT", "scsi_osd.permissions.dev_mgmt", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0080, NULL, HFILL}},
{ &hf_scsi_osd_permissions_global,
{"GLOBAL", "scsi_osd.permissions.global", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0040, NULL, HFILL}},
{ &hf_scsi_osd_permissions_pol_sec,
{"POL/SEC", "scsi_osd.permissions.pol_sec", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0020, NULL, HFILL}},
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
{ &hf_scsi_osd_list_collection_flags_coltn,
{"COLTN", "scsi_osd.list_collection.coltn", FT_BOOLEAN, 8,
TFS(&list_coltn_tfs), 0x01, NULL, HFILL}},
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
TFS(&tfs_set_notset), 0x01, NULL, HFILL}},
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
{"Attributes Page", "scsi_osd.attributes.page", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&attributes_page_vals_ext, 0, NULL, HFILL}},
{ &hf_scsi_osd_attribute_number,
{"Attribute Number", "scsi_osd.attribute.number", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attribute_length,
{"Attribute Length", "scsi_osd.attribute.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_attributes_list_length,
{"Attributes List Length", "scsi_osd2.attributes_list.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attrval_user_object_logical_length,
{"User Object Logical Length", "scsi_osd.user_object.logical_length", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attrval_object_type,
{"Object Type", "scsi_osd.attr.object_type", FT_UINT8, BASE_HEX, VALS(scsi_osd_object_type_vals), 0, NULL, HFILL}},
{ &hf_scsi_osd_attrval_partition_id,
{"Partition ID", "scsi_osd.attr.partition_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd_attrval_object_id,
{"Object ID", "scsi_osd.attr.object_id", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_set_attribute_value,
{"Set Attributes Value", "scsi_osd.set_attribute_value", FT_BYTES, BASE_NONE, 0, 0, NULL, HFILL}},
{ &hf_scsi_osd2_isolation,
{"Isolation", "scsi_osd2.isolation", FT_UINT8, BASE_HEX, VALS(scsi_osd2_isolation_val), 0x0F, NULL, HFILL}},
{ &hf_scsi_osd2_list_attr,
{"LIST ATTR flag", "scsi_osd2.list_attr", FT_BOOLEAN, 8, 0, 0x40, NULL, HFILL}},
{ &hf_scsi_osd2_object_descriptor_format,
{"Object Descriptor Format", "scsi_osd2.object_descriptor_format", FT_UINT8, BASE_HEX, VALS(scsi_osd2_object_descriptor_format_val), 0xFC, NULL, HFILL}},
{ &hf_scsi_osd2_immed_tr,
{"Immed TR", "scsi_osd2.immed_tr", FT_UINT8, BASE_DEC, 0, 0x80, NULL, HFILL}},
{ &hf_scsi_osd2_remove_scope,
{"Remove scope", "scsi_osd2.remove_scope", FT_UINT8, BASE_HEX, VALS(scsi_osd2_remove_scope), 0x07, NULL, HFILL}},
{ &hf_scsi_osd2_source_collection_object_id,
{"Source Collection Object ID", "scsi_osd2.source_collection_object_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_matches_collection_object_id,
{"Matches Collection Object ID", "scsi_osd2.matches_collection_object_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_cdb_continuation_length,
{"CDB Continuation Length", "scsi_osd2.cdb_continuation.length", FT_UINT32, BASE_DEC, 0, 0, NULL, HFILL}},
{ &hf_scsi_osd2_cdb_continuation_format,
{"CDB Continuation Format", "scsi_osd2.cdb_continuation.format", FT_UINT8, BASE_HEX, VALS(scsi_osd2_cdb_continuation_format_val), 0, NULL, HFILL}},
{ &hf_scsi_osd2_continued_service_action,
{"Continued Service Action", "scsi_osd2.cdb_continuation.sa", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_cdb_continuation_descriptor_type,
{"Descriptor Type", "scsi_osd2.cdb_continuation.desc.type", FT_UINT16, BASE_HEX, VALS(scsi_osd2_cdb_continuation_descriptor_type_val), 0, NULL, HFILL}},
{ &hf_scsi_osd2_cdb_continuation_descriptor_pad_length,
{"Descriptor Pad Length", "scsi_osd2.cdb_continuation.desc.padlen", FT_UINT8, BASE_DEC, NULL, 0x7, NULL, HFILL}},
{ &hf_scsi_osd2_cdb_continuation_descriptor_length,
{"Descriptor Length", "scsi_osd2.cdb_continuation.desc.length", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_query_type,
{"Query Type", "scsi_osd2.query.type", FT_UINT8, BASE_HEX, VALS(scsi_osd2_query_type_vals), 0x0f, NULL, HFILL}},
{ &hf_scsi_osd2_query_entry_length,
{"Entry Length", "scsi_osd2.query.entry.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_query_attributes_page,
{"Attributes Page", "scsi_osd2.query.entry.page", FT_UINT32, BASE_HEX | BASE_EXT_STRING, &attributes_page_vals_ext, 0, NULL, HFILL}},
{ &hf_scsi_osd2_query_attribute_number,
{"Attribute Number", "scsi_osd2.query.entry.number", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_query_minimum_attribute_value_length,
{"Minimum Attribute Value Length", "scsi_osd2.query.entry.min_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_scsi_osd2_query_maximum_attribute_value_length,
{"Maximum Attribute Value Length", "scsi_osd2.query.entry.max_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_osd_option,
&ett_osd_partition,
&ett_osd_attribute_parameters,
&ett_osd_capability,
&ett_osd_permission_bitmask,
&ett_osd_security_parameters,
&ett_osd_get_attributes,
&ett_osd_set_attributes,
&ett_osd_multi_object,
&ett_osd_attribute,
&ett_osd2_query_criteria_entry,
};
static ei_register_info ei[] = {
{ &ei_osd_attr_unknown, { "scsi_osd.attr_unknown", PI_UNDECODED, PI_NOTE, "Unknown attribute, cannot decode attribute value", EXPFILL }},
{ &ei_osd2_invalid_offset, { "scsi_osd2.invalid_offset", PI_UNDECODED, PI_ERROR, "Invalid offset exponent", EXPFILL }},
{ &ei_osd2_invalid_object_descriptor_format, { "scsi_osd2.object_descriptor_format.invalid", PI_UNDECODED, PI_ERROR, "Invalid list format", EXPFILL }},
{ &ei_osd_unknown_attributes_list_type, { "scsi_osd.attributes_list.type.invalid", PI_UNDECODED, PI_ERROR, "Unknown attribute list type", EXPFILL }},
{ &ei_osd2_cdb_continuation_format_unknown, { "scsi_osd2.cdb_continuation.format.unknown", PI_UNDECODED, PI_ERROR, "Unknown CDB Continuation Format", EXPFILL }},
{ &ei_osd2_continued_service_action_mismatch, { "scsi_osd2.cdb_continuation.sa.mismatch", PI_PROTOCOL, PI_WARN, "CONTINUED SERVICE ACTION and SERVICE ACTION do not match", EXPFILL }},
{ &ei_osd2_cdb_continuation_descriptor_type_unknown, { "scsi_osd2.cdb_continuation.desc.type.unknown", PI_UNDECODED, PI_WARN, "Unknown descriptor type", EXPFILL }},
{ &ei_osd2_cdb_continuation_descriptor_length_invalid, { "scsi_osd2.cdb_continuation.desc.length.invalid", PI_PROTOCOL, PI_ERROR, "Invalid descriptor length (not a multiple of 8)", EXPFILL }},
{ &ei_osd2_cdb_continuation_length_invalid, { "scsi_osd2.cdb_continuation.length.invalid", PI_PROTOCOL, PI_ERROR, "Invalid CDB continuation length", EXPFILL }},
{ &ei_osd_attr_length_invalid, { "scsi_osd.attribute_length.invalid", PI_PROTOCOL, PI_ERROR, "Invalid Attribute Length", EXPFILL }},
{ &ei_osd2_query_values_equal, { "scsi_osd2.query.entry.equal", PI_PROTOCOL, PI_NOTE, "The minimum and maximum values are equal", EXPFILL }},
};
proto_scsi_osd = proto_register_protocol("SCSI_OSD", "SCSI_OSD", "scsi_osd");
proto_register_field_array(proto_scsi_osd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_scsi_osd = expert_register_protocol(proto_scsi_osd);
expert_register_field_array(expert_scsi_osd, ei, array_length(ei));
}
