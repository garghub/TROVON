static int
align_4(tvbuff_t *tvb, int aoffset)
{
if(tvb_captured_length_remaining(tvb, aoffset) > 4 )
{
return (aoffset%4);
}
return 0;
}
static int
ndps_string(tvbuff_t* tvb, int hfinfo, proto_tree *ndps_tree, int offset, char **stringval)
{
int foffset = offset;
guint32 str_length;
char *string;
str_length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if(str_length == 0)
{
proto_tree_add_string(ndps_tree, hfinfo, tvb, offset, 4, "<Not Specified>");
if (stringval != NULL)
*stringval = wmem_strdup(wmem_packet_scope(), "");
return foffset;
}
if (str_length <= 2 || (str_length & 0x01) || tvb_get_guint8(tvb, foffset + 1) != 0) {
string = tvb_get_string_enc(wmem_packet_scope(), tvb, foffset, str_length, ENC_ASCII|ENC_NA); ;
} else {
string = tvb_get_string_enc(wmem_packet_scope(), tvb, foffset, str_length, ENC_UTF_16|ENC_LITTLE_ENDIAN);
}
foffset += str_length;
proto_tree_add_string(ndps_tree, hfinfo, tvb, offset, str_length + 4, string);
foffset += align_4(tvb, foffset);
if (stringval != NULL)
*stringval = string;
return foffset;
}
static int
objectidentifier(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 length;
const char *label=NULL;
guint32 label_value=0;
proto_tree *atree;
proto_item *aitem;
gboolean found=TRUE;
length = tvb_get_ntohl(tvb, foffset);
if (length==0)
{
return foffset;
}
if (ndps_show_oids)
{
proto_tree_add_uint(ndps_tree, hf_oid_struct_size, tvb, foffset, 4, length);
}
foffset += 4;
switch (length)
{
case 9:
label_value = tvb_get_ntohl(tvb, foffset+5);
label = try_val_to_str(label_value, object_ids_7);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_7, tvb, foffset, length, label_value, "%s", label);
break;
case 10:
label_value = tvb_get_ntohl(tvb, foffset+6);
label = try_val_to_str(label_value, object_ids_8);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_8, tvb, foffset, length, label_value, "%s", label);
break;
case 11:
label_value = tvb_get_ntohl(tvb, foffset+7);
label = try_val_to_str(label_value, object_ids_9);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_9, tvb, foffset, length, label_value, "%s", label);
break;
case 12:
label_value = tvb_get_ntohl(tvb, foffset+8);
label = try_val_to_str(label_value, object_ids_10);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_10, tvb, foffset, length, label_value, "%s", label);
break;
case 13:
label_value = tvb_get_ntohl(tvb, foffset+9);
label = try_val_to_str(label_value, object_ids_11);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_11, tvb, foffset, length, label_value, "%s", label);
break;
case 14:
label_value = tvb_get_ntohl(tvb, foffset+10);
label = try_val_to_str(label_value, object_ids_12);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_12, tvb, foffset, length, label_value, "%s", label);
break;
case 15:
label_value = tvb_get_ntohl(tvb, foffset+11);
label = try_val_to_str(label_value, object_ids_13);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_13, tvb, foffset, length, label_value, "%s", label);
break;
case 16:
label_value = tvb_get_ntohl(tvb, foffset+12);
label = try_val_to_str(label_value, object_ids_14);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_14, tvb, foffset, length, label_value, "%s", label);
break;
case 17:
label_value = tvb_get_ntohl(tvb, foffset+13);
label = try_val_to_str(label_value, object_ids_15);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_15, tvb, foffset, length, label_value, "%s", label);
break;
case 18:
label_value = tvb_get_ntohl(tvb, foffset+14);
label = try_val_to_str(label_value, object_ids_16);
if (label==NULL)
{
label = wmem_strdup(wmem_packet_scope(), "Unknown ID");
found=FALSE;
}
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_16, tvb, foffset, length, label_value, "%s", label);
break;
default:
aitem = proto_tree_add_uint_format(ndps_tree, hf_ndps_object_ids_7, tvb, foffset, length, 1, "Unknown ID");
found=FALSE;
break;
}
if (!found)
{
label_value = 1;
label = try_val_to_str(label_value, object_ids_7);
}
if (ndps_show_oids)
{
atree = proto_item_add_subtree(aitem, ett_ndps);
proto_tree_add_item(atree, hf_oid_asn1_type, tvb, foffset, 1, ENC_BIG_ENDIAN);
foffset += 1;
length = tvb_get_guint8(tvb, foffset);
foffset += 1;
proto_tree_add_item(atree, hf_ndps_oid, tvb, foffset, length, ENC_NA);
foffset += length;
}
else
{
if (!found)
{
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
}
else
{
foffset += 1;
length = tvb_get_guint8(tvb, foffset);
foffset += 1;
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
}
}
global_attribute_name = label;
if ((int) (foffset+(length%2)) < 0) {
THROW(ReportedBoundsError);
}
return foffset+(length%2);
}
static int
name_or_id(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 name_or_id_val;
name_or_id_val = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_nameorid, tvb, foffset, 4, name_or_id_val);
foffset += 4;
switch (name_or_id_val)
{
case 1:
foffset = objectidentifier(tvb, ndps_tree, foffset);
break;
case 2:
foffset = ndps_string(tvb, hf_ndps_local_object_name, ndps_tree, foffset, NULL);
break;
}
foffset += align_4(tvb, foffset);
return foffset;
}
static int
qualifiedname(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 qualified_name_type=0;
qualified_name_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_qualified_name, tvb, foffset, 4, qualified_name_type);
foffset += 4;
if (qualified_name_type != 0) {
if (qualified_name_type == 1) {
foffset = ndps_string(tvb, hf_ndps_printer_name, ndps_tree, foffset, NULL);
}
else
{
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
}
}
return foffset;
}
static int
objectidentification(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 object_type=0;
proto_tree *atree;
proto_item *aitem;
object_type = tvb_get_ntohl(tvb, foffset);
aitem = proto_tree_add_item(ndps_tree, hf_obj_id_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
atree = proto_item_add_subtree(aitem, ett_ndps);
foffset += 4;
switch(object_type)
{
case 0:
foffset = ndps_string(tvb, hf_ndps_printer_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_object, tvb, foffset,
4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 1:
foffset = ndps_string(tvb, hf_ndps_printer_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_document_number, tvb, foffset,
4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 2:
foffset = objectidentifier(tvb, atree, foffset);
break;
case 3:
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
if (foffset > tvb_captured_length_remaining(tvb, foffset)) {
return foffset;
}
foffset = name_or_id(tvb, atree, foffset);
break;
case 4:
foffset = name_or_id(tvb, atree, foffset);
break;
case 5:
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
break;
case 6:
foffset = ndps_string(tvb, hf_ndps_printer_name, atree, foffset, NULL);
break;
case 7:
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 8:
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
foffset = objectidentifier(tvb, atree, foffset);
proto_tree_add_item(atree, hf_ndps_event_type, tvb, foffset,
4, ENC_BIG_ENDIAN);
foffset += 4;
default:
break;
}
return foffset;
}
static int
print_address(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 addr_type=0;
guint32 addr_len=0;
addr_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_address, tvb, foffset, 4, addr_type);
foffset += 4;
addr_len = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(ndps_tree, hf_address_len, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
switch(addr_type)
{
case 0x00000000:
proto_tree_add_item(ndps_tree, hf_ndps_net, tvb, foffset, 4, ENC_NA);
proto_tree_add_item(ndps_tree, hf_ndps_node, tvb, foffset+4, 6, ENC_NA);
proto_tree_add_item(ndps_tree, hf_ndps_socket, tvb, foffset+10, 2, ENC_BIG_ENDIAN);
break;
case 0x00000001:
proto_tree_add_item(ndps_tree, hf_ndps_port, tvb, foffset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ndps_tree, hf_ndps_ip, tvb, foffset+2, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
tvb_ensure_bytes_exist(tvb, foffset, addr_len);
foffset += addr_len;
return foffset+(addr_len%4);
}
static int
address_item(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 addr_type=0;
addr_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_address_type, tvb, foffset, 4, addr_type);
foffset += 4;
switch(addr_type)
{
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 8:
case 9:
case 10:
case 11:
case 12:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
break;
case 13:
proto_tree_add_item(ndps_tree, hf_ndps_attrib_boolean, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 14:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 15:
foffset = print_address(tvb, ndps_tree, foffset);
break;
case 16:
case 17:
default:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
break;
}
return foffset;
}
static int
credentials(tvbuff_t* tvb, packet_info *pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 cred_type=0;
guint32 length=0;
guint32 number_of_items;
guint32 ii;
proto_tree *atree;
proto_item *aitem, *expert_item;
cred_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_cred_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
switch (cred_type)
{
case 0:
foffset = ndps_string(tvb, hf_ndps_user_name, ndps_tree, foffset, NULL);
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_passwords, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Password %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(atree, hf_ndps_password, tvb, foffset, length, ENC_NA);
}
proto_item_set_end(aitem, tvb, foffset);
foffset += length;
}
break;
case 1:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_certified, tvb, foffset, length, ENC_NA);
}
foffset += length;
break;
case 2:
foffset = ndps_string(tvb, hf_ndps_server_name, ndps_tree, foffset, NULL);
foffset += 2;
proto_tree_add_item(ndps_tree, hf_ndps_connection, tvb, foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
break;
case 3:
length=tvb_get_ntohl(tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_server_name, ndps_tree, foffset, NULL);
if (length == 0)
{
foffset += 2;
}
if (tvb_get_ntohs(tvb, foffset)==0)
{
foffset+=2;
if (tvb_get_ntohs(tvb, foffset)==0)
{
foffset += 2;
}
}
proto_tree_add_item(ndps_tree, hf_ndps_connection, tvb, foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
foffset = ndps_string(tvb, hf_ndps_user_name, ndps_tree, foffset, NULL);
break;
case 4:
foffset = ndps_string(tvb, hf_ndps_server_name, ndps_tree, foffset, NULL);
foffset += 2;
proto_tree_add_item(ndps_tree, hf_ndps_connection, tvb, foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
foffset = ndps_string(tvb, hf_ndps_user_name, ndps_tree, foffset, NULL);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
break;
default:
break;
}
return foffset;
}
static int
event_object_set(tvbuff_t* tvb, packet_info *pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 number_of_items;
guint32 number_of_items2;
guint32 ii;
guint32 jj;
guint32 object_identifier;
proto_tree *atree, *btree, *ctree;
proto_item *aitem, *bitem, *citem, *expert_item;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_events, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &bitem, "Event %u", ii+1);
proto_tree_add_item(btree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = objectidentifier(tvb, btree, foffset);
foffset += align_4(tvb, foffset);
foffset = objectidentification(tvb, btree, foffset);
foffset += align_4(tvb, foffset);
proto_tree_add_item(btree, hf_ndps_object_op, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
object_identifier = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(btree, hf_ndps_event_object_identifier, tvb, foffset, 4, object_identifier);
foffset += 4;
switch (object_identifier)
{
case 1:
foffset = objectidentifier(tvb, btree, foffset);
foffset += align_4(tvb, foffset);
break;
case 2:
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_item_count, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Item %u", jj+1);
foffset = objectidentifier(tvb, ctree, foffset);
foffset += align_4(tvb, foffset);
proto_item_set_end(citem, tvb, foffset);
}
break;
}
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
return foffset;
}
static int
cardinal_seq(tvbuff_t* tvb, packet_info* pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 number_of_items;
guint32 length;
guint32 ii;
proto_tree *atree;
proto_item *aitem, *expert_item;
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Cardinal %u", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
proto_item_set_end(aitem, tvb, foffset);
}
return foffset;
}
static int
server_entry(tvbuff_t* tvb, packet_info* pinfo, proto_tree *ndps_tree, int foffset)
{
char *server_name;
guint32 number_of_items;
guint32 ii;
guint32 data_type;
proto_tree *atree, *btree;
proto_item *aitem, *bitem, *expert_item;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Server Info");
foffset = ndps_string(tvb, hf_ndps_server_name, ndps_tree, foffset, &server_name);
proto_item_append_text(aitem, ": %s", format_text(server_name, strlen(server_name)));
proto_tree_add_item(atree, hf_ndps_server_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = print_address(tvb, atree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_servers, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Info %u", ii+1);
data_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(btree, hf_ndps_data_item_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
switch (data_type)
{
case 0:
proto_tree_add_item(btree, hf_info_int, tvb, foffset, 1, ENC_BIG_ENDIAN);
foffset++;
break;
case 1:
proto_tree_add_item(btree, hf_info_int16, tvb, foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
break;
case 2:
proto_tree_add_item(btree, hf_info_int32, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 3:
proto_tree_add_item(btree, hf_info_boolean, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 4:
case 5:
foffset = ndps_string(tvb, hf_info_string, btree, foffset, NULL);
break;
default:
break;
}
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
return foffset;
}
static int
attribute_value(tvbuff_t* tvb, packet_info* pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 ii;
guint32 jj;
guint32 number_of_items;
guint32 number_of_items2;
guint32 attribute_type;
guint32 integer_or_oid;
guint32 event_object_type;
guint32 ignored_type;
guint32 resource_type;
guint32 identifier_type;
guint32 criterion_type;
guint32 card_enum_time;
guint32 media_type;
guint32 doc_content;
guint32 page_size;
guint32 medium_size;
guint32 numbers_up;
guint32 colorant_set;
guint32 length;
guint32 dimension;
guint32 location;
guint32 cardinal;
const char *label;
guint32 label_value;
proto_tree *atree, *btree;
proto_item *aitem, *bitem, *expert_item;
if (global_attribute_name==NULL)
{
label_value = 1;
label = try_val_to_str(label_value, object_ids_7);
global_attribute_name = label;
}
attribute_type = tvb_get_ntohl(tvb, foffset);
if (ndps_show_oids)
{
proto_tree_add_item(ndps_tree, hf_ndps_obj_attribute_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
}
foffset += 4;
switch(attribute_type)
{
case 0:
proto_tree_add_item(ndps_tree, hf_ndps_data, tvb, foffset+4, tvb_get_ntohl(tvb, foffset), ENC_NA);
break;
case 1:
case 2:
case 3:
case 6:
case 40:
case 50:
case 58:
case 102:
case 103:
case 108:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
break;
case 4:
case 5:
case 38:
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 39:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 7:
case 79:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 8:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Name %u", ii+1);
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 9:
case 10:
case 11:
case 13:
case 15:
case 18:
case 19:
case 35:
case 57:
case 72:
case 95:
if (global_attribute_name != NULL &&
strcmp(global_attribute_name,"(Novell) Attribute PRINTER SECURITY LEVEL")==0)
{
proto_tree_add_item(ndps_tree, hf_print_security, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
case 12:
case 14:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_info_int32, tvb, foffset, length, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
break;
case 16:
case 17:
proto_tree_add_item(ndps_tree, hf_ndps_lower_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 20:
case 22:
case 24:
case 31:
case 29:
proto_tree_add_item(ndps_tree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 21:
case 23:
case 30:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %u", ii+1);
proto_tree_add_item(atree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 25:
case 26:
case 32:
case 33:
proto_tree_add_item(ndps_tree, hf_ndps_lower_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 27:
proto_tree_add_item(ndps_tree, hf_ndps_lower_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 28:
proto_tree_add_item(ndps_tree, hf_ndps_upper_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 34:
proto_tree_add_item(ndps_tree, hf_ndps_attrib_boolean, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 36:
foffset = objectidentifier(tvb, ndps_tree, foffset);
break;
case 37:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object %d", ii+1);
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 41:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_names, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Name %u", ii+1);
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 42:
proto_tree_add_item(ndps_tree, hf_ndps_realization, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 43:
proto_tree_add_item(ndps_tree, hf_ndps_xdimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 44:
dimension = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_dim_value, tvb, foffset, 4, dimension);
foffset += 4;
if (dimension == 0) {
proto_tree_add_item(ndps_tree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
else
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
proto_tree_add_item(ndps_tree, hf_ndps_dim_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 45:
dimension = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_xydim_value, tvb, foffset, 4, dimension);
foffset += 4;
if (dimension == 1) {
foffset = name_or_id(tvb, ndps_tree, foffset);
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_xdimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
proto_tree_add_item(ndps_tree, hf_ndps_dim_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 46:
location = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_location_value, tvb, foffset, 4, location);
foffset += 4;
if (location == 0) {
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_locations, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Location %u", ii+1);
proto_tree_add_item(atree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_item_set_end(aitem, tvb, foffset);
}
}
else
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
proto_tree_add_item(ndps_tree, hf_ndps_dim_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 47:
proto_tree_add_item(ndps_tree, hf_ndps_xmin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_xmax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
case 48:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_areas, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Area %u", ii+1);
proto_tree_add_item(atree, hf_ndps_xmin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(atree, hf_ndps_xmax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(atree, hf_ndps_ymin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(atree, hf_ndps_ymax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 49:
proto_tree_add_item(ndps_tree, hf_ndps_edge_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 51:
cardinal = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_cardinal_or_oid, tvb, foffset, 4, cardinal);
foffset += 4;
if (cardinal==0) {
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
foffset = objectidentifier(tvb, ndps_tree, foffset);
}
break;
case 52:
foffset = objectidentifier(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 53:
cardinal = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_cardinal_name_or_oid, tvb, foffset, 4, cardinal);
foffset += 4;
if (cardinal==0) {
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
break;
case 54:
integer_or_oid = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_or_oid, tvb, foffset, 4, integer_or_oid);
foffset += 4;
if (integer_or_oid==0) {
foffset = objectidentifier(tvb, ndps_tree, foffset);
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
case 55:
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = qualifiedname(tvb, ndps_tree, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = name_or_id(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_address_items, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Address Item %u", ii+1);
foffset = address_item(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_events, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event %u", ii+1);
proto_tree_add_item(atree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = objectidentifier(tvb, atree, foffset);
foffset += align_4(tvb, foffset);
foffset = objectidentification(tvb, atree, foffset);
proto_tree_add_item(atree, hf_ndps_object_op, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
event_object_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_event_object_identifier, tvb, foffset, 4, event_object_type);
foffset += 4;
switch (event_object_type)
{
case 2:
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
foffset = objectidentifier(tvb, atree, foffset);
}
foffset += 4;
break;
case 1:
foffset = objectidentifier(tvb, atree, foffset);
break;
case 0:
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object %u", jj+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
break;
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 56:
case 63:
case 66:
length = tvb_get_ntohl(tvb, foffset);
ndps_string(tvb, hf_info_string, ndps_tree, foffset, NULL);
foffset += length+2;
foffset += align_4(tvb, foffset);
break;
case 59:
proto_tree_add_item(ndps_tree, hf_ndps_delivery_add_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
event_object_type = tvb_get_ntohl(tvb, foffset);
foffset += 4;
switch(event_object_type)
{
case 0:
case 1:
case 2:
case 3:
foffset = ndps_string(tvb, hf_info_string, ndps_tree, foffset, NULL);
break;
case 4:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 5:
case 6:
foffset = objectidentifier(tvb, ndps_tree, foffset);
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
default:
break;
}
break;
case 60:
foffset = objectidentification(tvb, ndps_tree, foffset);
break;
case 61:
foffset = objectidentifier(tvb, ndps_tree, foffset);
foffset = name_or_id(tvb, ndps_tree, foffset);
foffset = address_item(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 62:
foffset = objectidentifier(tvb, ndps_tree, foffset);
criterion_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_criterion_type, tvb, foffset, 4, criterion_type);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 64:
foffset = objectidentifier(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 65:
foffset = objectidentifier(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_job_categories, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job %u", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 67:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = objectidentifier(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_ignored_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Ignored Attribute %u", ii+1);
ignored_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_ignored_type, tvb, foffset, 4, ignored_type);
foffset += 4;
if (ignored_type == 38)
{
foffset = name_or_id(tvb, atree, foffset);
}
else
{
foffset = objectidentifier(tvb, atree, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 68:
resource_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_resource_type, tvb, foffset, 4, resource_type);
foffset += 4;
if (resource_type == 0)
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
else
{
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
}
break;
case 69:
foffset = name_or_id(tvb, ndps_tree, foffset);
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 70:
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
break;
case 71:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_resources, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resource %u", ii+1);
resource_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_resource_type, tvb, foffset, 4, resource_type);
foffset += 4;
if (resource_type == 0)
{
foffset = name_or_id(tvb, atree, foffset);
}
else
{
foffset = ndps_string(tvb, hf_ndps_tree, atree, foffset, NULL);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 73:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_page_selects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Page Select %u", ii+1);
proto_tree_add_item(atree, hf_ndps_page_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
identifier_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_identifier_type, tvb, foffset, 4, identifier_type);
foffset += 4;
if (identifier_type == 0)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
if (identifier_type == 1)
{
foffset = ndps_string(tvb, hf_ndps_tree, atree, foffset, NULL);
}
if (identifier_type == 2)
{
foffset = name_or_id(tvb, atree, foffset);
}
proto_tree_add_item(atree, hf_ndps_page_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
identifier_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_identifier_type, tvb, foffset, 4, identifier_type);
foffset += 4;
if (identifier_type == 0)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
if (identifier_type == 1)
{
foffset = ndps_string(tvb, hf_ndps_tree, atree, foffset, NULL);
}
if (identifier_type == 2)
{
foffset = name_or_id(tvb, atree, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 74:
media_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_media_type, tvb, foffset, 4, media_type);
foffset += 4;
if (media_type == 0)
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
else
{
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %u", ii+1);
proto_tree_add_item(atree, hf_ndps_page_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
identifier_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_identifier_type, tvb, foffset, 4, identifier_type);
foffset += 4;
if (identifier_type == 0)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
if (identifier_type == 1)
{
foffset = ndps_string(tvb, hf_ndps_tree, atree, foffset, NULL);
}
if (identifier_type == 2)
{
foffset = name_or_id(tvb, atree, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
}
}
break;
case 75:
doc_content = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_doc_content, tvb, foffset, 4, doc_content);
foffset += 4;
if (doc_content == 0)
{
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
}
else
{
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
foffset = name_or_id(tvb, ndps_tree, foffset);
}
break;
case 76:
page_size = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_page_size, tvb, foffset, 4, page_size);
foffset += 4;
if (page_size == 0)
{
foffset = objectidentifier(tvb, ndps_tree, foffset);
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_xdimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
break;
case 77:
proto_tree_add_item(ndps_tree, hf_ndps_direction, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 78:
proto_tree_add_item(ndps_tree, hf_ndps_page_order, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 80:
foffset = name_or_id(tvb, ndps_tree, foffset);
medium_size = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_medium_size, tvb, foffset, 4, medium_size);
foffset += 4;
if (medium_size == 0)
{
page_size = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_page_size, tvb, foffset, 4, page_size);
foffset += 4;
if (page_size == 0)
{
foffset = objectidentifier(tvb, ndps_tree, foffset);
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_xdimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
proto_tree_add_item(ndps_tree, hf_ndps_long_edge_feeds, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_xmin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_xmax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
else
{
proto_tree_add_item(ndps_tree, hf_ndps_lower_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_inc_across_feed, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_lower_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_size_inc_in_feed, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_long_edge_feeds, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_xmin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_xmax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymin_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ymax_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
break;
case 81:
foffset = name_or_id(tvb, ndps_tree, foffset);
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 82:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_page_informations, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Page Information %u", ii+1);
proto_tree_add_item(atree, hf_ndps_page_order, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ndps_page_orientation, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 83:
proto_tree_add_item(ndps_tree, hf_ndps_identifier_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 84:
foffset = objectidentifier(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_lower_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 85:
foffset = objectidentifier(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_categories, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Category %u", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
}
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_values, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Value %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 86:
numbers_up=tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_numbers_up, tvb, foffset, 4, numbers_up);
foffset += 4;
switch(numbers_up)
{
case 0:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 1:
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 2:
proto_tree_add_item(ndps_tree, hf_ndps_lower_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_upper_range, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 87:
case 88:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 89:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 90:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_level, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_interval, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 91:
proto_tree_add_item(ndps_tree, hf_ndps_address, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_add_bytes, tvb, foffset, 4, ENC_NA);
}
foffset += length;
break;
case 92:
dimension = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_xydim_value, tvb, foffset, 4, dimension);
foffset += 4;
switch (dimension)
{
case 1:
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 0:
proto_tree_add_item(ndps_tree, hf_ndps_xdimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension_n64, tvb, foffset, 8, ENC_NA);
foffset += 8;
break;
default:
proto_tree_add_item(ndps_tree, hf_ndps_xdimension, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
}
break;
case 93:
foffset = name_or_id(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_xdimension, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_ydimension, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 94:
foffset += 4;
foffset = name_or_id(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_state_severity, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_training, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = objectidentifier(tvb, ndps_tree, foffset);
foffset += align_4(tvb, foffset);
foffset = objectidentification(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items = tvb_get_ntohl(tvb, foffset);
foffset += 4*number_of_items;
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 96:
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 97:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_names, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Name %u", ii+1);
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 98:
colorant_set = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_colorant_set, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (colorant_set==0)
{
foffset = name_or_id(tvb, ndps_tree, foffset);
}
else
{
foffset = objectidentifier(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_colorants, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Colorant %u", ii+1);
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
}
break;
case 99:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_printer_def_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Printer %u", ii+1);
foffset = ndps_string(tvb, hf_ndps_printer_type, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_printer_manuf, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 100:
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
foffset = objectidentifier(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 101:
foffset = qualifiedname(tvb, ndps_tree, foffset);
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 104:
card_enum_time = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_card_enum_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
switch (card_enum_time)
{
case 0:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 1:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
}
break;
case 105:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object %u", ii+1);
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 106:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
break;
case 107:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 109:
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = qualifiedname(tvb, ndps_tree, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = name_or_id(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_delivery_add_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
event_object_type = tvb_get_ntohl(tvb, foffset);
foffset += 4;
switch(event_object_type)
{
case 0:
case 1:
case 2:
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
break;
case 3:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_octet_string, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
break;
case 4:
foffset = ndps_string(tvb, hf_object_name, ndps_tree, foffset, NULL);
foffset = name_or_id(tvb, ndps_tree, foffset);
break;
case 5:
case 6:
foffset = objectidentifier(tvb, ndps_tree, foffset);
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
default:
break;
}
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_events, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event %u", ii+1);
foffset = ndps_string(tvb, hf_object_name, atree, foffset, NULL);
foffset = objectidentifier(tvb, atree, foffset);
proto_tree_add_item(atree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentifier(tvb, ndps_tree, foffset);
foffset = qualifiedname(tvb, ndps_tree, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object %u", ii+1);
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
break;
default:
break;
}
return foffset;
}
static int
commonarguments(tvbuff_t* tvb, packet_info* pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 number_of_items;
guint32 ii;
proto_tree *atree, *btree;
proto_item *aitem, *bitem, *expert_item;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Common Arguments");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_args, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Argument %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
return foffset;
}
static int
res_add_input_data(tvbuff_t* tvb, proto_tree *ndps_tree, int foffset)
{
guint32 resource_type=0;
resource_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_res_type, tvb, foffset, 4, resource_type);
foffset += 4;
switch (resource_type)
{
case 0:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 1:
foffset = ndps_string(tvb, hf_ndps_vendor_dir, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 2:
foffset = ndps_string(tvb, hf_ndps_banner_name, ndps_tree, foffset, NULL);
break;
case 3:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_font_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 4:
case 5:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_archive_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
return foffset;
}
static gint
ndps_equal(gconstpointer v, gconstpointer v2)
{
const ndps_req_hash_key *val1 = (const ndps_req_hash_key*)v;
const ndps_req_hash_key *val2 = (const ndps_req_hash_key*)v2;
if (val1->conversation == val2->conversation &&
val1->ndps_xport == val2->ndps_xport ) {
return 1;
}
return 0;
}
static guint
ndps_hash(gconstpointer v)
{
const ndps_req_hash_key *ndps_key = (const ndps_req_hash_key*)v;
return GPOINTER_TO_UINT(ndps_key->conversation) + ndps_key->ndps_xport;
}
static void
ndps_init_protocol(void)
{
reassembly_table_init(&ndps_reassembly_table,
&addresses_reassembly_table_functions);
ndps_req_hash = g_hash_table_new(ndps_hash, ndps_equal);
}
static void
ndps_cleanup_protocol(void)
{
reassembly_table_destroy(&ndps_reassembly_table);
}
static void
ndps_postseq_cleanup(void)
{
if (ndps_req_hash) {
g_hash_table_destroy(ndps_req_hash);
ndps_req_hash = NULL;
}
}
static ndps_req_hash_value*
ndps_hash_insert(conversation_t *conversation, guint32 ndps_xport)
{
ndps_req_hash_key *request_key;
ndps_req_hash_value *request_value;
request_key = wmem_new(wmem_file_scope(), ndps_req_hash_key);
request_key->conversation = conversation;
request_key->ndps_xport = ndps_xport;
request_value = wmem_new(wmem_file_scope(), ndps_req_hash_value);
request_value->ndps_prog = 0;
request_value->ndps_func = 0;
request_value->ndps_frame_num = 0;
request_value->ndps_frag = FALSE;
request_value->ndps_end_frag = 0;
g_hash_table_insert(ndps_req_hash, request_key, request_value);
return request_value;
}
static ndps_req_hash_value*
ndps_hash_lookup(conversation_t *conversation, guint32 ndps_xport)
{
ndps_req_hash_key request_key;
request_key.conversation = conversation;
request_key.ndps_xport = ndps_xport;
return (ndps_req_hash_value *)g_hash_table_lookup(ndps_req_hash, &request_key);
}
static void
dissect_ndps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ndps_tree)
{
guint32 ndps_xid;
guint32 ndps_prog;
guint32 ndps_packet_type;
int foffset;
guint32 ndps_hfname;
guint32 ndps_func;
const char *ndps_program_string;
const char *ndps_func_string;
ndps_packet_type = tvb_get_ntohl(tvb, 8);
if (ndps_packet_type != 0 && ndps_packet_type != 1) {
col_set_str(pinfo->cinfo, COL_INFO, "(Continuation Data)");
proto_tree_add_bytes_format(ndps_tree, hf_ndps_data, tvb, 0, -1, NULL, "Data - (%d Bytes)", tvb_reported_length(tvb));
return;
}
foffset = 0;
proto_tree_add_item(ndps_tree, hf_ndps_record_mark, tvb,
foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
proto_tree_add_item(ndps_tree, hf_ndps_length, tvb,
foffset, 2, ENC_BIG_ENDIAN);
foffset += 2;
ndps_xid = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_xid, tvb, foffset, 4, ndps_xid);
foffset += 4;
ndps_packet_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_packet_type, tvb, foffset, 4, ndps_packet_type);
foffset += 4;
if(ndps_packet_type == 0x00000001)
{
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS ");
proto_tree_add_item(ndps_tree, hf_ndps_rpc_accept, tvb, foffset, 4, ENC_BIG_ENDIAN);
if (tvb_get_ntohl(tvb, foffset)==0) {
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_auth_null, tvb, foffset, 8, ENC_NA);
foffset += 8;
}
else
{
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_rpc_rej_stat, tvb, foffset+4, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
dissect_ndps_reply(tvb, pinfo, ndps_tree, foffset);
}
else
{
col_set_str(pinfo->cinfo, COL_INFO, "C NDPS ");
proto_tree_add_item(ndps_tree, hf_ndps_rpc_version, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
ndps_prog = tvb_get_ntohl(tvb, foffset);
ndps_program_string = try_val_to_str(ndps_prog, spx_ndps_program_vals);
if( ndps_program_string != NULL)
{
proto_tree_add_item(ndps_tree, hf_spx_ndps_program, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
col_append_str(pinfo->cinfo, COL_INFO, (const gchar*) ndps_program_string);
col_append_str(pinfo->cinfo, COL_INFO, ", ");
proto_tree_add_item(ndps_tree, hf_spx_ndps_version, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
ndps_func = tvb_get_ntohl(tvb, foffset);
switch(ndps_prog)
{
case 0x060976:
ndps_hfname = hf_spx_ndps_func_print;
ndps_func_string = try_val_to_str_ext(ndps_func, &spx_ndps_print_func_vals_ext);
break;
case 0x060977:
ndps_hfname = hf_spx_ndps_func_broker;
ndps_func_string = try_val_to_str_ext(ndps_func, &spx_ndps_broker_func_vals_ext);
break;
case 0x060978:
ndps_hfname = hf_spx_ndps_func_registry;
ndps_func_string = try_val_to_str_ext(ndps_func, &spx_ndps_registry_func_vals_ext);
break;
case 0x060979:
ndps_hfname = hf_spx_ndps_func_notify;
ndps_func_string = try_val_to_str_ext(ndps_func, &spx_ndps_notify_func_vals_ext);
break;
case 0x06097a:
ndps_hfname = hf_spx_ndps_func_resman;
ndps_func_string = try_val_to_str_ext(ndps_func, &spx_ndps_resman_func_vals_ext);
break;
case 0x06097b:
ndps_hfname = hf_spx_ndps_func_delivery;
ndps_func_string = try_val_to_str(ndps_func, spx_ndps_deliver_func_vals);
break;
default:
ndps_hfname = 0;
ndps_func_string = NULL;
break;
}
if(ndps_hfname != 0)
{
proto_tree_add_item(ndps_tree, ndps_hfname, tvb, foffset, 4, ENC_BIG_ENDIAN);
if (ndps_func_string != NULL)
{
col_append_str(pinfo->cinfo, COL_INFO, (const gchar*) ndps_func_string);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_auth_null, tvb, foffset, 16, ENC_NA);
foffset+=16;
dissect_ndps_request(tvb, pinfo, ndps_tree, ndps_prog, ndps_func, foffset);
}
}
}
}
}
static guint
get_ndps_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohs(tvb, offset +2) + 4;
}
static int
dissect_ndps_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ndps_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NDPS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ndps, tvb, 0, -1, ENC_NA);
ndps_tree = proto_item_add_subtree(ti, ett_ndps);
dissect_ndps(tvb, pinfo, ndps_tree);
return tvb_captured_length(tvb);
}
static void
ndps_defrag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, spx_info *spx_info_p)
{
guint len=0;
tvbuff_t *next_tvb = NULL;
fragment_head *fd_head;
ndps_req_hash_value *request_value = NULL;
conversation_t *conversation;
if (!ndps_defragment) {
dissect_ndps(tvb, pinfo, tree);
return;
}
if (!pinfo->fd->flags.visited)
{
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->srcport, 0);
if (conversation == NULL)
{
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->srcport, 0);
}
request_value = ndps_hash_lookup(conversation, (guint32) pinfo->srcport);
if (request_value == NULL)
{
request_value = ndps_hash_insert(conversation, (guint32) pinfo->srcport);
}
p_add_proto_data(wmem_file_scope(), pinfo, proto_ndps, 0, (void*) request_value);
}
else
{
request_value = (ndps_req_hash_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ndps, 0);
}
if (!request_value)
{
dissect_ndps(tvb, pinfo, tree);
return;
}
if (!spx_info_p->eom) {
request_value->ndps_frag = TRUE;
}
if (request_value->ndps_frag || (request_value->ndps_end_frag == pinfo->fd->num))
{
tid = (pinfo->srcport+pinfo->destport);
len = tvb_reported_length(tvb);
if (tvb_captured_length(tvb) >= len)
{
fd_head = fragment_add_seq_next(&ndps_reassembly_table, tvb, 0, pinfo, tid, NULL, len, !spx_info_p->eom);
if (fd_head != NULL)
{
if (fd_head->next != NULL && spx_info_p->eom)
{
proto_item *frag_tree_item;
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo,
next_tvb,
"Reassembled NDPS");
if (tree)
{
show_fragment_seq_tree(fd_head,
&ndps_frag_items,
tree, pinfo,
next_tvb, &frag_tree_item);
tid++;
}
request_value->ndps_end_frag = pinfo->fd->num;
}
else
{
next_tvb = tvb_new_subset_remaining(tvb, 0);
if (!spx_info_p->eom)
{
col_append_str(pinfo->cinfo, COL_INFO, "[NDPS Fragment]");
}
}
}
else
{
if (!spx_info_p->eom)
{
col_append_str(pinfo->cinfo, COL_INFO, "[NDPS Fragment]");
}
next_tvb = NULL;
}
}
else
{
next_tvb = tvb_new_subset_remaining(tvb, 0);
}
if (next_tvb == NULL)
{
next_tvb = tvb_new_subset_remaining (tvb, 0);
call_dissector(ndps_data_handle, next_tvb, pinfo, tree);
}
else
{
if (spx_info_p->eom) {
request_value->ndps_frag = FALSE;
dissect_ndps(next_tvb, pinfo, tree);
}
}
}
else
{
request_value->ndps_frag = FALSE;
dissect_ndps(tvb, pinfo, tree);
}
}
static int
dissect_ndps_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, ndps_desegment, 4, get_ndps_pdu_len, dissect_ndps_pdu, data);
return tvb_captured_length(tvb);
}
static int
dissect_ndps_ipx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *ndps_tree;
proto_item *ti;
if (data == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NDPS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ndps, tvb, 0, -1, ENC_NA);
ndps_tree = proto_item_add_subtree(ti, ett_ndps);
ndps_defrag(tvb, pinfo, ndps_tree, (spx_info*)data);
return tvb_captured_length(tvb);
}
static int
dissect_ndps_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ndps_tree, guint32 ndps_prog, guint32 ndps_func, int foffset)
{
ndps_req_hash_value *request_value = NULL;
conversation_t *conversation;
guint32 ii;
guint32 jj;
guint32 field_len;
guint32 cred_type;
guint32 resource_type;
guint32 filter_type;
guint32 print_type;
guint32 length;
guint32 number_of_items;
guint32 number_of_items2;
guint32 doc_content;
guint32 list_attr_op;
guint32 scope;
guint32 job_type;
gboolean supplier_flag;
gboolean language_flag;
gboolean method_flag;
gboolean delivery_address_flag;
guint32 profiles_type;
guint32 profiles_choice_type;
guint32 integer_type_flag;
guint32 local_servers_type;
gint length_remaining;
proto_tree *atree, *btree, *ctree, *dtree;
proto_item *aitem, *bitem, *citem, *ditem, *expert_item;
if (!pinfo->fd->flags.visited)
{
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->srcport, 0);
if (conversation == NULL)
{
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->srcport, 0);
}
request_value = ndps_hash_insert(conversation, (guint32) pinfo->srcport);
request_value->ndps_prog = ndps_prog;
request_value->ndps_func = ndps_func;
request_value->ndps_frame_num = pinfo->fd->num;
}
switch(ndps_prog)
{
case 0x060976:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000002:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_retrieve_restrictions, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_bind_security_option_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Security %u", ii+1);
length = tvb_get_ntohl(tvb, foffset);
if (length==4)
{
proto_tree_add_uint(atree, hf_bind_security, tvb, foffset, 4, length);
}
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 0x00000003:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset,
4, ENC_BIG_ENDIAN);
break;
case 0x00000004:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
print_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_print_arg, tvb, foffset, 4, print_type);
foffset += 4;
switch (print_type)
{
case 0:
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_sub_complete, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Transfer Method");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Value %u", jj+1);
foffset = attribute_value(tvb, pinfo, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_tree_add_item(btree, hf_ndps_qualifier, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Content");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Type %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
foffset += align_4(tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
doc_content = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_doc_content, tvb, foffset, 4, doc_content);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Value %u", ii+1);
if (doc_content==0)
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(btree, hf_ndps_included_doc_len, tvb, foffset, 4, length);
foffset += 4;
length_remaining = tvb_reported_length_remaining(tvb, foffset);
if (length_remaining == -1 || length > (guint32) length_remaining)
{
proto_tree_add_item(btree, hf_ndps_data, tvb, foffset, -1, ENC_NA);
return foffset;
}
if (length==4)
{
proto_tree_add_item(btree, hf_ndps_included_doc, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
if ((int) foffset <= 0)
THROW(ReportedBoundsError);
}
else
{
foffset = ndps_string(tvb, hf_ndps_ref_name, btree, foffset, NULL);
foffset = name_or_id(tvb, btree, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset += 4;
if (align_4(tvb, foffset)>0) {
foffset += align_4(tvb, foffset);
}
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Type");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Value %u", jj+1);
foffset = attribute_value(tvb, pinfo, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_tree_add_item(btree, hf_ndps_qualifier, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Attributes");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
break;
case 1:
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_sub_complete, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Transfer Method");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_transfer_methods, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Method %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_tree_add_item(ndps_tree, hf_doc_content, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Type");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_doc_types, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Type %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
foffset += align_4(tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Attributes");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
break;
case 2:
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_document_number, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job Modifications");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Modification %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Document Modifications");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Modification %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000006:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_document_number, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Cancel Message");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Retention Period");
proto_tree_add_item(atree, hf_ndps_status_flags, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
list_attr_op = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_attrs_arg, tvb, foffset, 4, list_attr_op);
foffset += 4;
if (list_attr_op==0)
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Attribute %u", ii+1);
foffset = attribute_value(tvb, pinfo, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset += 4;
foffset += align_4(tvb, foffset);
scope = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_scope, tvb, foffset, 4, scope);
foffset += 4;
if (scope!=0)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Selector Option");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_options, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Option %u", ii+1);
foffset = objectidentification(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset += align_4(tvb, foffset);
filter_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_filter, tvb, foffset, 4, filter_type);
foffset += 4;
#if 0
if (filter_type == 0 || filter_type == 3 )
{
foffset = filteritem(tvb, ndps_tree, foffset);
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Filter Items");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
foffset = filteritem(tvb, ndps_tree, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
}
#endif
proto_tree_add_item(ndps_tree, hf_ndps_time_limit, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_count_limit, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Requested Attributes");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if (number_of_items == 0)
{
break;
}
proto_tree_add_item(ndps_tree, hf_ndps_operator, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000008:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000009:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
job_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_interrupt_job_type, tvb, foffset, 4, job_type);
foffset += 4;
if (job_type==0)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
else
{
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
}
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Interrupt Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Interrupting Job");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000a:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
job_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_pause_job_type, tvb, foffset, 4, job_type);
foffset += 4;
if (job_type==0)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
else
{
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
}
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Pause Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000b:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resume Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000c:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Clean Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000d:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object ID");
foffset = objectidentification(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_force, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Reference Object Option");
foffset = objectidentification(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Attribute");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000e:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object ID");
foffset = objectidentification(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000f:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Disable PA Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000010:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Enable PA Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000011:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = qualifiedname(tvb, ndps_tree, foffset);
foffset = address_item(tvb, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_resubmit_op_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resubmit Job");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, btree, foffset, NULL);
proto_tree_add_item(btree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
proto_tree_add_item(atree, hf_ndps_document_number, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Job Attributes");
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Attribute %u", jj+1);
foffset = attribute_value(tvb, pinfo, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Document Attributes");
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Attribute %u", jj+1);
foffset = attribute_value(tvb, pinfo, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resubmit Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000012:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object ID");
foffset = objectidentification(tvb, atree, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Attribute Modifications");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Modification `%d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000013:
case 0x0000001e:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_shutdown_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Shutdown Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000014:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Startup Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000015:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job Identification");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Reference Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000016:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Pause Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000017:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resume Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000018:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_get_status_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_data, tvb, foffset+4, tvb_get_ntohl(tvb, foffset), ENC_NA);
break;
case 0x00000019:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Operation ID");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000001a:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = qualifiedname(tvb, ndps_tree, foffset);
foffset = ndps_string(tvb, hf_ndps_supplier_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
foffset += align_4(tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Address");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %u", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
foffset = qualifiedname(tvb, ndps_tree, foffset);
break;
case 0x0000001b:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x0000001c:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_supplier_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &supplier_flag);
foffset += 4;
if (supplier_flag)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier ID");
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_language_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &language_flag);
foffset += 4;
if (language_flag)
{
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_method_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &method_flag);
foffset += 4;
if (method_flag)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_delivery_address_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &delivery_address_flag);
foffset += 4;
if (delivery_address_flag)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Address");
foffset = print_address(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000001d:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
profiles_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_profiles_type, tvb, foffset, 4, profiles_type);
foffset += 4;
if (profiles_type==0)
{
foffset = qualifiedname(tvb, ndps_tree, foffset);
profiles_choice_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_profiles_choice_type, tvb, foffset, 4, profiles_choice_type);
foffset += 4;
if (profiles_choice_type==0)
{
foffset = cardinal_seq(tvb, pinfo, ndps_tree, foffset);
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_tree_add_item(atree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item(ndps_tree, hf_ndps_list_profiles_result_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
integer_type_flag = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_type_flag, tvb, foffset, 4, integer_type_flag);
foffset += 4;
if (integer_type_flag!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_integer_type_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
}
else
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
case 0x0000001f:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Cancel Shutdown Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000020:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_ds_info_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_printer_name, ndps_tree, foffset, NULL);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "DS Object Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000021:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Clean Message Option");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = commonarguments(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000022:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_guid, tvb, foffset, length, ENC_NA);
}
foffset += length;
break;
case 0x00000023:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_supplier_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
foffset += align_4(tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Address");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %u", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Account");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Notify Attributes");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %u", ii+1);
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
proto_tree_add_item(ndps_tree, hf_notify_time_interval, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_notify_sequence_number, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_notify_lease_exp_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_notify_printer_uri, ndps_tree, foffset, NULL);
break;
case 0x00000024:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
profiles_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_profiles_type, tvb, foffset, 4, profiles_type);
foffset += 4;
if (profiles_type==0)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier Alias");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
profiles_choice_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_profiles_choice_type, tvb, foffset, 4, profiles_choice_type);
foffset += 4;
if (profiles_choice_type==0)
{
foffset = cardinal_seq(tvb, pinfo, ndps_tree, foffset);
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
proto_tree_add_item(ndps_tree, hf_ndps_list_profiles_result_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
integer_type_flag = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_type_flag, tvb, foffset, 4, integer_type_flag);
foffset += 4;
if (integer_type_flag!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_integer_type_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
}
else
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
default:
break;
}
break;
case 0x060977:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_retrieve_restrictions, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_bind_security_option_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Security %u", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_bind_security, tvb, foffset, length, ENC_BIG_ENDIAN);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
break;
case 0x00000003:
proto_tree_add_item(ndps_tree, hf_ndps_list_services_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x00000004:
proto_tree_add_item(ndps_tree, hf_ndps_service_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Parameters");
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(atree, hf_ndps_item_bytes, tvb, foffset, length, ENC_NA);
}
foffset += length;
}
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_list_services_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x00000006:
case 0x00000007:
case 0x00000008:
default:
break;
}
break;
case 0x060978:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_retrieve_restrictions, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_bind_security_option_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Security %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_bind_security, tvb, foffset, length, ENC_BIG_ENDIAN);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
break;
case 0x00000003:
foffset = server_entry(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000004:
case 0x00000006:
case 0x0000000b:
case 0x0000000c:
break;
case 0x00000005:
foffset = ndps_string(tvb, hf_ndps_registry_name, ndps_tree, foffset, NULL);
foffset = print_address(tvb, ndps_tree, foffset);
break;
case 0x00000007:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Add");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Entry %u", ii+1);
foffset = server_entry(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Remove");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Entry %u", ii+1);
foffset = server_entry(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000008:
case 0x00000009:
case 0x0000000a:
local_servers_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_local_servers_type, tvb, foffset, 4, local_servers_type);
foffset += 4;
if (local_servers_type==0)
{
integer_type_flag = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_type_flag, tvb, foffset, 4, integer_type_flag);
foffset += 4;
if (integer_type_flag!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_integer_type_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
}
else
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
default:
break;
}
break;
case 0x060979:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_retrieve_restrictions, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Security %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_bind_security, tvb, foffset, length, ENC_BIG_ENDIAN);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
case 0x0000000a:
case 0x00000010:
case 0x00000011:
break;
case 0x00000003:
foffset = ndps_string(tvb, hf_ndps_supplier_name, ndps_tree, foffset, NULL);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier Alias %u", ii+1);
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000004:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier Alias");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Addresses");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %d", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000006:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_supplier_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &supplier_flag);
foffset += 4;
if (supplier_flag)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier ID");
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, foffset, length);
foffset += length;
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_language_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &language_flag);
foffset += 4;
if (language_flag)
{
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_method_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &method_flag);
foffset += 4;
if (method_flag)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item_ret_uint(ndps_tree, hf_ndps_delivery_address_flag, tvb, foffset, 4, ENC_BIG_ENDIAN, &delivery_address_flag);
foffset += 4;
if (delivery_address_flag)
{
foffset = print_address(tvb, ndps_tree, foffset);
}
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000008:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
profiles_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_list_profiles_type, tvb, foffset, 4, profiles_type);
foffset += 4;
if (profiles_type==0)
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Supplier Alias");
foffset = qualifiedname(tvb, atree, foffset);
profiles_choice_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_list_profiles_choice_type, tvb, foffset, 4, profiles_choice_type);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
if (profiles_choice_type==0)
{
foffset = cardinal_seq(tvb, pinfo, ndps_tree, foffset);
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_tree_add_item(atree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
proto_tree_add_item(ndps_tree, hf_ndps_list_profiles_result_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
integer_type_flag = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_type_flag, tvb, foffset, 4, integer_type_flag);
foffset += 4;
if (integer_type_flag!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_integer_type_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
}
else
{
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
break;
case 0x00000009:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event Items");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Item %d", ii+1);
proto_tree_add_item(btree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Containing Class");
foffset = objectidentifier(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Containing Object");
foffset = objectidentification(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Filter Class");
foffset = objectidentifier(tvb, ctree, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Object Class");
foffset = objectidentifier(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Object ID");
foffset = objectidentification(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Event Object ID");
foffset = objectidentifier(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Attribute Modifications");
for (jj = 0; jj < number_of_items; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, citem, &ei_ndps_truncated);
break;
}
dtree = proto_tree_add_subtree_format(ctree, tvb, foffset, -1, ett_ndps, &ditem, "Modification %d", jj+1);
foffset = attribute_value(tvb, pinfo, dtree, foffset);
proto_item_set_end(ditem, tvb, foffset);
}
proto_item_set_end(citem, tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_message, btree, foffset, NULL);
proto_tree_add_item(btree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x0000000b:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_destinations, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Destination %d", ii+1);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Method ID");
foffset = name_or_id(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
proto_tree_add_item(atree, hf_address_len, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = print_address(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = ndps_string(tvb, hf_ndps_supplier_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Containing Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Containing Object");
foffset = objectidentification(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Filter Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Class");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object ID");
foffset = objectidentification(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event Object ID");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Attributes");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_message, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Account");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x0000000c:
foffset = ndps_string(tvb, hf_ndps_file_name, ndps_tree, foffset, NULL);
break;
case 0x0000000d:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x0000000e:
cred_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(ndps_tree, hf_delivery_method_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
switch (cred_type)
{
case 0:
integer_type_flag = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_integer_type_flag, tvb, foffset, 4, integer_type_flag);
foffset += 4;
if (integer_type_flag!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_integer_type_value, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 1:
length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_context_len, tvb, foffset, 4, length);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_context, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset += (length%2);
proto_tree_add_item(ndps_tree, hf_ndps_abort_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x0000000f:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x06097a:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_retrieve_restrictions, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_bind_security_option_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Security %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(atree, hf_bind_security, tvb, foffset, length, ENC_BIG_ENDIAN);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
case 0x00000008:
case 0x00000009:
break;
case 0x00000003:
proto_tree_add_item(ndps_tree, hf_packet_count, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_last_packet_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_file_timestamp, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = res_add_input_data(tvb, ndps_tree, foffset);
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
length=tvb_get_ntohl(tvb, foffset);
length_remaining = tvb_reported_length_remaining(tvb, foffset);
if(length_remaining == -1 || (guint32) length_remaining < length)
{
return foffset;
}
proto_tree_add_item(atree, hf_ndps_item_ptr, tvb, foffset, length, ENC_NA);
foffset += length;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000004:
foffset = res_add_input_data(tvb, ndps_tree, foffset);
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_max_items, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_status_flags, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_resource_list_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
resource_type = tvb_get_ntohl(tvb, foffset);
foffset += 4;
switch (resource_type)
{
case 0:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 1:
case 2:
foffset = ndps_string(tvb, hf_ndps_vendor_dir, ndps_tree, foffset, NULL);
break;
case 3:
proto_tree_add_item(ndps_tree, hf_banner_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 4:
proto_tree_add_item(ndps_tree, hf_font_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 5:
case 12:
case 9:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_printer_type, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_printer_manuf, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, ndps_tree, foffset, NULL);
field_len = tvb_get_ntohl(tvb, foffset);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_printer_id, tvb, foffset, field_len, ENC_NA);
break;
case 6:
case 10:
foffset = ndps_string(tvb, hf_ndps_vendor_dir, ndps_tree, foffset, NULL);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_printer_type, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_printer_manuf, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, ndps_tree, foffset, NULL);
field_len = tvb_get_ntohl(tvb, foffset);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_printer_id, tvb, foffset, field_len, ENC_NA);
break;
case 7:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_font_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_font_name, ndps_tree, foffset, NULL);
break;
case 8:
case 11:
case 13:
foffset = ndps_string(tvb, hf_ndps_printer_manuf, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_printer_type, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, ndps_tree, foffset, NULL);
break;
case 14:
break;
default:
break;
}
break;
case 0x00000006:
proto_tree_add_item(ndps_tree, hf_get_status_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_res_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
resource_type = tvb_get_ntohl(tvb, foffset);
foffset += 4;
switch (resource_type)
{
case 0:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 1:
foffset = ndps_string(tvb, hf_ndps_vendor_dir, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 2:
foffset = ndps_string(tvb, hf_ndps_banner_name, ndps_tree, foffset, NULL);
break;
case 3:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_font_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_file_name, ndps_tree, foffset, NULL);
break;
case 4:
case 5:
proto_tree_add_item(ndps_tree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_archive_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_ndps_status_flags, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = res_add_input_data(tvb, ndps_tree, foffset);
break;
case 0x0000000a:
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x06097b:
switch(ndps_func)
{
case 0x00000001:
foffset = credentials(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000002:
break;
case 0x00000003:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
proto_tree_add_item(atree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Supplier ID");
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(btree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(btree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Containing Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Containing Object");
foffset = objectidentification(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Filter Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object ID");
foffset = objectidentification(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Event Object ID");
foffset = objectidentifier(tvb, btree, foffset);
foffset = attribute_value(tvb, pinfo, atree, foffset);
foffset = ndps_string(tvb, hf_ndps_message, atree, foffset, NULL);
proto_tree_add_item(atree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Account");
foffset = qualifiedname(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000004:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object %d", ii+1);
proto_tree_add_item(atree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Supplier ID");
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(btree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(atree, hf_ndps_event_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Containing Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Containing Object");
foffset = objectidentification(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Filter Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object Class");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object ID");
foffset = objectidentification(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Event Object ID");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute");
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, bitem, &ei_ndps_truncated);
break;
}
foffset = attribute_value(tvb, pinfo, btree, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_message, atree, foffset, NULL);
proto_tree_add_item(atree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Account");
foffset = qualifiedname(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
default:
break;
}
break;
default:
break;
}
return foffset;
}
static int
ndps_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 number_of_items;
guint32 ndps_problem_type;
guint32 problem_type;
guint32 ii;
proto_tree *atree;
proto_item *aitem;
proto_tree *btree;
proto_item *bitem;
proto_item *expert_item;
ndps_problem_type = tvb_get_ntohl(tvb, foffset);
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_problem_type, tvb, foffset, 4, ndps_problem_type);
expert_add_info_format(pinfo, expert_item, &ei_ndps_problem_type, "Fault: %s", val_to_str(ndps_problem_type, error_type_enum, "Unknown NDPS Error (0x%08x)"));
foffset += 4;
switch(ndps_problem_type)
{
case 0:
problem_type = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_problem_type, tvb, foffset, 4, problem_type);
foffset += 4;
if (problem_type==0)
{
proto_tree_add_item(ndps_tree, hf_security_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Message");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
break;
case 1:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_service_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
foffset = attribute_value(tvb, pinfo, ndps_tree, foffset);
proto_tree_add_item(ndps_tree, hf_ndps_lib_error, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_other_error, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_other_error_2, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_reported_length_remaining(tvb, foffset) >= 4) {
foffset = ndps_string(tvb, hf_ndps_other_error_string, ndps_tree, foffset, NULL);
}
break;
case 2:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_access_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
break;
case 3:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_printer_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
break;
case 4:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_selection_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
foffset = attribute_value(tvb, pinfo, ndps_tree, foffset);
break;
case 5:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_doc_access_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset = objectidentifier(tvb, ndps_tree, foffset);
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
break;
case 6:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
proto_tree_add_item(atree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(atree, hf_attribute_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Extended Error");
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
foffset = attribute_value(tvb, pinfo, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 7:
proto_tree_add_item(ndps_tree, hf_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4)==0)
{
proto_tree_add_item(ndps_tree, hf_update_problem_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
else
{
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Extended Error");
foffset = objectidentifier(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
foffset = objectidentification(tvb, ndps_tree, foffset);
break;
default:
break;
}
return foffset;
}
static int
return_code(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ndps_tree, int foffset)
{
guint32 expert_status;
proto_item *expert_item;
expert_status = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
if (expert_status != 0) {
expert_add_info_format(pinfo, expert_item, &ei_ndps_return_code, "Fault: %s",
val_to_str_ext(expert_status, &ndps_error_types_ext, "Unknown NDPS Error (0x%08x)"));
}
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) == 0)
{
return foffset;
}
proto_tree_add_item(ndps_tree, hf_ndps_ext_error, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
return foffset;
}
static int
dissect_ndps_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ndps_tree, int foffset)
{
conversation_t *conversation = NULL;
ndps_req_hash_value *request_value = NULL;
proto_tree *atree;
proto_item *aitem;
proto_tree *btree;
proto_item *bitem;
proto_tree *ctree;
proto_item *citem;
proto_tree *dtree;
proto_item *ditem;
guint32 ii;
guint32 jj;
guint32 kk;
guint32 number_of_items=0;
guint32 number_of_items2=0;
guint32 number_of_items3=0;
guint32 length=0;
guint32 ndps_func=0;
guint32 ndps_prog=0;
guint32 error_val=0;
guint32 resource_type=0;
gint length_remaining;
proto_item *expert_item;
guint32 expert_status;
if (!pinfo->fd->flags.visited) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->destport, (guint32) pinfo->destport, 0);
if (conversation != NULL) {
request_value = ndps_hash_lookup(conversation, (guint32) pinfo->destport);
p_add_proto_data(wmem_file_scope(), pinfo, proto_ndps, 0, (void*) request_value);
}
}
else {
request_value = (ndps_req_hash_value *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ndps, 0);
}
if (request_value) {
ndps_prog = request_value->ndps_prog;
ndps_func = request_value->ndps_func;
proto_tree_add_uint_format(ndps_tree, hf_ndps_reqframe, tvb, 0,
0, request_value->ndps_frame_num,
"Response to Request in Frame Number: %u",
request_value->ndps_frame_num);
}
if (tvb_reported_length_remaining(tvb, foffset) < 12 && tvb_get_ntohl(tvb, foffset) == 0)
{
proto_tree_add_uint(ndps_tree, hf_ndps_error_val, tvb, foffset, 4, error_val);
col_append_str(pinfo->cinfo, COL_INFO, "- Ok");
return foffset;
}
if(ndps_func == 1 || ndps_func == 2)
{
expert_item = proto_tree_add_item(ndps_tree, hf_ndps_rpc_acc_stat, tvb, foffset, 4, ENC_BIG_ENDIAN);
expert_status = tvb_get_ntohl(tvb, foffset);
if (expert_status != 0) {
expert_add_info_format(pinfo, expert_item, &ei_ndps_rpc_acc_stat, "Fault: %s", val_to_str(expert_status, accept_stat, "Unknown NDPS Error (0x%08x)"));
}
foffset += 4;
if (tvb_reported_length_remaining(tvb,foffset) < 4 ) {
col_append_str(pinfo->cinfo, COL_INFO, "- Error");
return foffset;
}
proto_tree_add_item(ndps_tree, hf_ndps_rpc_acc_results, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_reported_length_remaining(tvb,foffset) < 4) {
col_append_str(pinfo->cinfo, COL_INFO, "- Error");
return foffset;
}
}
error_val = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_error_val, tvb, foffset, 4, error_val);
foffset += 4;
if (try_val_to_str_ext(tvb_get_ntohl(tvb, foffset), &ndps_error_types_ext) && tvb_reported_length_remaining(tvb,foffset) < 8 && (tvb_get_ntohl(tvb, foffset)!=0))
{
expert_status = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, expert_item, &ei_ndps_return_code, "Fault: %s", val_to_str_ext(expert_status, &ndps_error_types_ext, "Unknown NDPS Error (0x%08x)"));
col_append_str(pinfo->cinfo, COL_INFO, "- Error");
return foffset;
}
col_append_str(pinfo->cinfo, COL_INFO, "- Ok");
switch(ndps_prog)
{
case 0x060976:
switch(ndps_func)
{
case 0x00000001:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
if(tvb_reported_length_remaining(tvb, foffset) < 4)
{
break;
}
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "PSM Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
break;
case 0x00000002:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
if(tvb_reported_length_remaining(tvb, foffset) < 4)
{
break;
}
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
}
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
break;
case 0x00000003:
break;
case 0x00000004:
foffset = ndps_string(tvb, hf_ndps_pa_name, ndps_tree, foffset, NULL);
proto_tree_add_item(ndps_tree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000005:
case 0x00000006:
case 0x00000008:
case 0x0000000b:
case 0x0000000d:
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Attribute Set");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_answer_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Continuation Option");
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_options, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Option %d", ii+1);
length=tvb_get_ntohl(tvb, foffset);
length_remaining = tvb_reported_length_remaining(tvb, foffset);
if(length_remaining == -1 || (guint32) length_remaining < length)
{
return foffset;
}
proto_tree_add_item(btree, hf_ndps_item_ptr, tvb, foffset, length, ENC_NA);
foffset += length;
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Limit Encountered Option");
proto_tree_add_item(atree, hf_ndps_len, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ndps_limit_enc, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Results Set");
number_of_items=tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_results, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Results: (%d)", ii+1);
if (ii>0) {
foffset += 2;
}
foffset = objectidentification(tvb, btree, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_objects, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Object: (%d)", jj+1);
foffset = objectidentifier(tvb, ctree, foffset);
foffset += align_4(tvb, foffset);
number_of_items3 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ctree, hf_ndps_num_values, tvb, foffset, 4, number_of_items3);
foffset += 4;
for (kk = 0; kk < number_of_items3; kk++ )
{
if (kk >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
dtree = proto_tree_add_subtree_format(ctree, tvb, foffset, -1, ett_ndps, &ditem, "Value: (%d)", kk+1);
foffset = attribute_value(tvb, pinfo, dtree, foffset);
proto_item_set_end(ditem, tvb, foffset);
}
proto_tree_add_item(ctree, hf_ndps_qualifier, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset += align_4(tvb, foffset);
proto_item_set_end(citem, tvb, foffset);
}
foffset = objectidentifier(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000009:
case 0x0000000a:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job ID");
foffset = ndps_string(tvb, hf_ndps_pa_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Object Attribute Set");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Attribute %d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x0000000c:
case 0x0000000e:
case 0x0000000f:
case 0x00000010:
case 0x00000012:
case 0x00000013:
case 0x00000014:
case 0x00000018:
case 0x00000019:
case 0x0000001b:
case 0x0000001c:
case 0x0000001e:
case 0x0000001f:
case 0x00000020:
case 0x00000021:
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000011:
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_num_jobs, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Resubmit Job");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Job %d", ii+1);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Old Job");
foffset = ndps_string(tvb, hf_ndps_pa_name, ctree, foffset, NULL);
proto_tree_add_item(ctree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(citem, tvb, foffset);
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "New Job");
foffset = ndps_string(tvb, hf_ndps_pa_name, ctree, foffset, NULL);
proto_tree_add_item(ctree, hf_local_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(citem, tvb, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ctree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
ctree = proto_tree_add_subtree(btree, tvb, foffset, -1, ett_ndps, &citem, "Job Status");
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, citem, &ei_ndps_truncated);
break;
}
dtree = proto_tree_add_subtree_format(ctree, tvb, foffset, -1, ett_ndps, &ditem, "Object %d", jj+1);
foffset = attribute_value(tvb, pinfo, dtree, foffset);
proto_item_set_end(ditem, tvb, foffset);
}
proto_item_set_end(citem, tvb, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000015:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Job Status");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object %d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000016:
case 0x00000017:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Printer Status");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Object %d", ii+1);
foffset = attribute_value(tvb, pinfo, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x0000001a:
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x0000001d:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer Name");
foffset = qualifiedname(tvb, atree, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Addresses");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %d", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_continuation_option, tvb, foffset, length, ENC_NA);
}
foffset += length;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000022:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "NDS Printer Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000023:
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_notify_lease_exp_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
break;
case 0x00000024:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_events, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Event %d", ii+1);
proto_tree_add_item(atree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Consumer Name");
foffset = qualifiedname(tvb, btree, foffset);
foffset = ndps_string(tvb, hf_ndps_supplier_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Method ID");
foffset = name_or_id(tvb, btree, foffset);
foffset += align_4(tvb, foffset);
proto_item_set_end(bitem, tvb, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items2);
foffset += 4;
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Delivery Addresses");
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, bitem, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Address %d", ii+1);
foffset = address_item(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, atree, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Account");
foffset = qualifiedname(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
btree = proto_tree_add_subtree(atree, tvb, foffset, -1, ett_ndps, &bitem, "Notify Attributes");
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(btree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
ctree = proto_tree_add_subtree_format(btree, tvb, foffset, -1, ett_ndps, &citem, "Attribute %d", ii+1);
foffset = objectidentifier(tvb, ctree, foffset);
proto_item_set_end(citem, tvb, foffset);
}
proto_item_set_end(bitem, tvb, foffset);
proto_tree_add_item(atree, hf_notify_time_interval, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_notify_sequence_number, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_notify_lease_exp_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_notify_printer_uri, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_continuation_option, tvb, foffset, length, ENC_NA);
}
foffset += length;
if(error_val != 0)
{
foffset = ndps_error(tvb, pinfo, ndps_tree, foffset);
}
}
break;
default:
break;
}
break;
case 0x060977:
switch(ndps_func)
{
case 0x00000001:
case 0x00000002:
case 0x00000004:
case 0x00000005:
case 0x00000006:
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000003:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_services, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Service %d", ii+1);
proto_tree_add_item(atree, hf_ndps_service_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ndps_service_enabled, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_ndps_item_count, tvb, foffset,
4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_broker_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000008:
default:
break;
}
break;
case 0x060978:
switch(ndps_func)
{
case 0x00000001:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Attribute %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(atree, hf_ndps_attribute_set, tvb, foffset, length, ENC_NA);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
break;
case 0x00000003:
case 0x00000004:
case 0x00000005:
case 0x00000006:
case 0x00000007:
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000008:
case 0x00000009:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
foffset = server_entry(tvb, pinfo, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_continuation_option, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000a:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_item(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
aitem = proto_tree_add_item(ndps_tree, hf_ndps_client_server_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
atree = proto_item_add_subtree(aitem, ett_ndps);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_registry_name, atree, foffset, NULL);
foffset = print_address(tvb, atree, foffset);
}
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_continuation_option, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000b:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "NDS Printer Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000c:
proto_tree_add_item(ndps_tree, hf_ndps_session_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
default:
break;
}
break;
case 0x060979:
switch(ndps_func)
{
case 0x00000001:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_num_attributes, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Attribute %d", ii+1);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(atree, hf_ndps_attribute_set, tvb, foffset, length, ENC_NA);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 0x00000002:
break;
case 0x00000003:
proto_tree_add_item(ndps_tree, hf_ndps_session, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000004:
case 0x0000000b:
case 0x0000000d:
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000006:
case 0x00000007:
case 0x00000009:
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000008:
proto_tree_add_item(ndps_tree, hf_ndps_len, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_profile_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_persistence, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Consumer Name");
foffset = qualifiedname(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_value, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Addresses");
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %d", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = event_object_set(tvb, pinfo, ndps_tree, foffset);
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_continuation_option, tvb, foffset, length, ENC_NA);
}
foffset += length;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000a:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length==4)
{
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, length, ENC_BIG_ENDIAN);
}
foffset += length;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000c:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
proto_item_set_end(aitem, tvb, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000e:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_delivery_method_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method %d", ii+1);
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Method ID");
foffset = name_or_id(tvb, btree, foffset);
foffset += align_4(tvb, foffset);
proto_item_set_end(bitem, tvb, foffset);
foffset = ndps_string(tvb, hf_ndps_method_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_method_ver, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_file_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_admin_submit, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000f:
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Method ID");
foffset = name_or_id(tvb, atree, foffset);
foffset = ndps_string(tvb, hf_ndps_method_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_method_ver, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_file_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_ndps_admin_submit, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
number_of_items = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_delivery_add_count, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Delivery Addresses");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Address %d", ii+1);
foffset = address_item(tvb, btree, foffset);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000010:
proto_tree_add_item(ndps_tree, hf_ndps_item_count, tvb, foffset,
4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_broker_name, ndps_tree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_tree, ndps_tree, foffset, NULL);
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000011:
proto_tree_add_item(ndps_tree, hf_ndps_get_session_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
default:
break;
}
break;
case 0x06097a:
switch(ndps_func)
{
case 0x00000001:
length = tvb_get_ntohl(tvb, foffset);
foffset += 4;
if (length!=0)
{
proto_tree_add_item(ndps_tree, hf_ndps_attribute_set, tvb, foffset, length, ENC_NA);
}
break;
case 0x00000002:
break;
case 0x00000003:
case 0x00000004:
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x00000005:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) != 0)
{
break;
}
proto_tree_add_item(ndps_tree, hf_ndps_status_flags, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_resource_list_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
resource_type = tvb_get_ntohl(tvb, foffset);
foffset += 4;
switch (resource_type)
{
case 0:
case 1:
case 2:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_printer_def_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Definition %d", ii+1);
if (tvb_get_ntohl(tvb, foffset)==0) {
foffset += 2;
}
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_printer_manuf, atree, foffset, NULL);
if (tvb_get_ntohl(tvb, foffset)==0) {
foffset += 2;
}
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_printer_type, atree, foffset, NULL);
if (tvb_get_ntohl(tvb, foffset)==0) {
foffset += 2;
}
foffset += 4;
foffset = ndps_string(tvb, hf_ndps_inf_file_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 3:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Banner %d", ii+1);
foffset = ndps_string(tvb, hf_ndps_banner_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 4:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_font_type_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Font %d", ii+1);
foffset = ndps_string(tvb, hf_font_type_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 7:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_font_file_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Font File %d", ii+1);
foffset = ndps_string(tvb, hf_font_file_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 5:
case 12:
case 9:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_printer_def_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "File %d", ii+1);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 6:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_printer_def_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Definition %d", ii+1);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_inf_file_name, atree, foffset, NULL);
proto_item_set_end(aitem, tvb, foffset);
}
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Item %d", ii+1);
foffset = ndps_string(tvb, hf_ndps_def_file_name, atree, foffset, NULL);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_num_win31_keys, tvb, foffset, 4, number_of_items2);
btree = proto_tree_add_subtree(atree, tvb, foffset, 4, ett_ndps, &bitem, "Windows 3.1 Keys");
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, bitem, &ei_ndps_truncated);
break;
}
foffset = ndps_string(tvb, hf_ndps_windows_key, btree, foffset, NULL);
}
proto_item_set_end(bitem, tvb, foffset);
number_of_items2 = tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(atree, hf_ndps_num_win95_keys, tvb, foffset, 4, number_of_items2);
btree = proto_tree_add_subtree(atree, tvb, foffset, 4, ett_ndps, &bitem, "Windows 95 Keys");
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, bitem, &ei_ndps_truncated);
break;
}
foffset = ndps_string(tvb, hf_ndps_windows_key, btree, foffset, NULL);
}
proto_item_set_end(bitem, tvb, foffset);
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 10:
foffset = ndps_string(tvb, hf_ndps_def_file_name, ndps_tree, foffset, NULL);
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_os_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "OS %d", ii+1);
proto_tree_add_item(atree, hf_os_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
number_of_items2 = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(atree, hf_ndps_num_windows_keys, tvb, foffset, 4, number_of_items2);
foffset += 4;
for (jj = 0; jj < number_of_items2; jj++ )
{
if (jj >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Key %d", jj+1);
foffset = ndps_string(tvb, hf_ndps_windows_key, btree, foffset, NULL);
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 8:
case 11:
case 13:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_printer_type_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Type %d", ii+1);
foffset = ndps_string(tvb, hf_ndps_printer_manuf, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_printer_type, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_file_name, atree, foffset, NULL);
foffset = ndps_string(tvb, hf_ndps_prn_dir_name, atree, foffset, NULL);
proto_tree_add_item(atree, hf_archive_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_archive_file_size, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
break;
case 14:
number_of_items = tvb_get_ntohl(tvb, foffset);
expert_item = proto_tree_add_uint(ndps_tree, hf_ndps_language_count, tvb, foffset, 4, number_of_items);
foffset += 4;
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, expert_item, &ei_ndps_truncated);
break;
}
atree = proto_tree_add_subtree_format(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Language %d", ii+1);
proto_tree_add_item(atree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_item_set_end(aitem, tvb, foffset);
}
break;
default:
break;
}
break;
case 0x00000006:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) != 0)
{
break;
}
proto_tree_add_item(ndps_tree, hf_get_status_flag, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_file_timestamp, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_ndps_data, tvb, foffset, -1, ENC_NA);
break;
case 0x00000007:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) != 0)
{
break;
}
proto_tree_add_item(ndps_tree, hf_file_timestamp, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 0x00000008:
foffset = qualifiedname(tvb, ndps_tree, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_error_val, tvb, foffset, 4, error_val);
foffset += 4;
break;
case 0x00000009:
proto_tree_add_item(ndps_tree, hf_ndps_get_resman_session_type, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(ndps_tree, hf_time, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset = return_code(tvb, pinfo, ndps_tree, foffset);
break;
case 0x0000000a:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) != 0)
{
break;
}
proto_tree_add_item(ndps_tree, hf_ndps_language_id, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
default:
break;
}
break;
case 0x06097b:
switch(ndps_func)
{
case 0x00000001:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
break;
case 0x00000002:
break;
case 0x00000003:
case 0x00000004:
proto_tree_add_item(ndps_tree, hf_ndps_return_code, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
if (tvb_get_ntohl(tvb, foffset-4) != 0)
col_set_str(pinfo->cinfo, COL_INFO, "R NDPS - Error");
if (tvb_get_ntohl(tvb, foffset-4) != 0)
{
break;
}
number_of_items=tvb_get_ntohl(tvb, foffset);
proto_tree_add_uint(ndps_tree, hf_ndps_item_count, tvb, foffset, 4, number_of_items);
foffset += 4;
atree = proto_tree_add_subtree(ndps_tree, tvb, foffset, -1, ett_ndps, &aitem, "Failed Items");
for (ii = 0; ii < number_of_items; ii++ )
{
if (ii >= NDPS_MAX_ITEMS) {
expert_add_info(pinfo, aitem, &ei_ndps_truncated);
break;
}
btree = proto_tree_add_subtree_format(atree, tvb, foffset, -1, ett_ndps, &bitem, "Item %d", ii+1);
length=tvb_get_ntohl(tvb, foffset);
length_remaining = tvb_reported_length_remaining(tvb, foffset);
if(length_remaining == -1 || (guint32) length_remaining < length)
{
return foffset;
}
proto_tree_add_item(btree, hf_ndps_item_ptr, tvb, foffset, length, ENC_NA);
foffset += length;
proto_item_set_end(bitem, tvb, foffset);
}
proto_item_set_end(aitem, tvb, foffset);
break;
default:
break;
}
break;
default:
break;
}
return foffset;
}
void
proto_register_ndps(void)
{
static hf_register_info hf_ndps[] = {
{ &hf_ndps_record_mark,
{ "Record Mark", "ndps.record_mark", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_packet_type,
{ "Packet Type", "ndps.packet_type",
FT_UINT32, BASE_HEX, VALS(ndps_packet_types), 0x0,
NULL, HFILL }},
{ &hf_ndps_length,
{ "Record Length", "ndps.record_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_xid,
{ "Exchange ID", "ndps.xid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_rpc_version,
{ "RPC Version", "ndps.rpc_version",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_program,
{ "NDPS Program Number", "spx.ndps_program",
FT_UINT32, BASE_HEX, VALS(spx_ndps_program_vals), 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_version,
{ "Program Version", "spx.ndps_version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_error,
{ "NDPS Error", "spx.ndps_error",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_other_error_string,
{ "Extended Error String", "ndps.ext_err_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_print,
{ "Print Program", "spx.ndps_func_print",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &spx_ndps_print_func_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_notify,
{ "Notify Program", "spx.ndps_func_notify",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &spx_ndps_notify_func_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_delivery,
{ "Delivery Program", "spx.ndps_func_delivery",
FT_UINT32, BASE_HEX, VALS(spx_ndps_deliver_func_vals), 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_registry,
{ "Registry Program", "spx.ndps_func_registry",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &spx_ndps_registry_func_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_resman,
{ "ResMan Program", "spx.ndps_func_resman",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &spx_ndps_resman_func_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_spx_ndps_func_broker,
{ "Broker Program", "spx.ndps_func_broker",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &spx_ndps_broker_func_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_objects,
{ "Number of Objects", "ndps.num_objects",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_attributes,
{ "Number of Attributes", "ndps.num_attributes",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_sbuffer,
{ "Server", "ndps.sbuffer",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_ndps_rbuffer,
{ "Connection", "ndps.rbuffer",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_user_name,
{ "Trustee Name", "ndps.user_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_broker_name,
{ "Broker Name", "ndps.broker_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_results,
{ "Number of Results", "ndps.num_results",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_options,
{ "Number of Options", "ndps.num_options",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_jobs,
{ "Number of Jobs", "ndps.num_jobs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_pa_name,
{ "Printer Name", "ndps.pa_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_tree,
{ "Tree", "ndps.tree",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_reqframe,
{ "Request Frame", "ndps.reqframe",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_error_val,
{ "Return Status", "ndps.error_val",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_error_types_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_object,
{ "Object ID", "ndps.object",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_cred_type,
{ "Credential Type", "ndps.cred_type",
FT_UINT32, BASE_HEX, VALS(ndps_credential_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_server_name,
{ "Server Name", "ndps.server_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_connection,
{ "Connection", "ndps.connection",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ext_error,
{ "Extended Error Code", "ndps.ext_error",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_auth_null,
{ "Auth Null", "ndps.auth_null",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_rpc_accept,
{ "RPC Accept or Deny", "ndps.rpc_acc",
FT_UINT32, BASE_HEX, VALS(true_false), 0x0,
NULL, HFILL }},
{ &hf_ndps_rpc_acc_stat,
{ "RPC Accept Status", "ndps.rpc_acc_stat",
FT_UINT32, BASE_HEX, VALS(accept_stat), 0x0,
NULL, HFILL }},
{ &hf_ndps_rpc_rej_stat,
{ "RPC Reject Status", "ndps.rpc_rej_stat",
FT_UINT32, BASE_HEX, VALS(reject_stat), 0x0,
NULL, HFILL }},
{ &hf_ndps_rpc_acc_results,
{ "RPC Accept Results", "ndps.rpc_acc_res",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_problem_type,
{ "Problem Type", "ndps.rpc_prob_type",
FT_UINT32, BASE_HEX, VALS(error_type_enum), 0x0,
NULL, HFILL }},
{ &hf_security_problem_type,
{ "Security Problem", "ndps.rpc_sec_prob",
FT_UINT32, BASE_HEX, VALS(security_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_service_problem_type,
{ "Service Problem", "ndps.rpc_serv_prob",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &service_problem_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_access_problem_type,
{ "Access Problem", "ndps.rpc_acc_prob",
FT_UINT32, BASE_HEX, VALS(access_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_printer_problem_type,
{ "Printer Problem", "ndps.rpc_print_prob",
FT_UINT32, BASE_HEX, VALS(printer_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_selection_problem_type,
{ "Selection Problem", "ndps.rpc_sel_prob",
FT_UINT32, BASE_HEX, VALS(selection_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_doc_access_problem_type,
{ "Document Access Problem", "ndps.rpc_doc_acc_prob",
FT_UINT32, BASE_HEX, VALS(doc_access_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_attribute_problem_type,
{ "Attribute Problem", "ndps.rpc_attr_prob",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &attribute_problem_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_update_problem_type,
{ "Update Problem", "ndps.rpc_update_prob",
FT_UINT32, BASE_HEX, VALS(update_problem_enum), 0x0,
NULL, HFILL }},
{ &hf_obj_id_type,
{ "Object ID Type", "ndps.rpc_obj_id_type",
FT_UINT32, BASE_HEX, VALS(obj_identification_enum), 0x0,
NULL, HFILL }},
{ &hf_oid_struct_size,
{ "OID Struct Size", "ndps.rpc_oid_struct_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_object_name,
{ "Object Name", "ndps.object_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_document_number,
{ "Document Number", "ndps.doc_num",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_doc_content,
{ "Document Content", "ndps.doc_content",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_nameorid,
{ "Name or ID Type", "ndps.nameorid",
FT_UINT32, BASE_HEX, VALS(nameorid_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_local_object_name,
{ "Local Object Name", "ndps.loc_object_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_printer_name,
{ "Printer Name", "ndps.printer_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_qualified_name,
{ "Qualified Name Type", "ndps.qual_name_type",
FT_UINT32, BASE_HEX, VALS(qualified_name_enum), 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_qualified_name2,
{ "Qualified Name Type", "ndps.qual_name_type2",
FT_UINT32, BASE_HEX, VALS(qualified_name_enum2), 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_item_count,
{ "Number of Items", "ndps.item_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_passwords,
{ "Number of Passwords", "ndps.num_passwords",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_servers,
{ "Number of Servers", "ndps.num_servers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_locations,
{ "Number of Locations", "ndps.num_locations",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_areas,
{ "Number of Areas", "ndps.num_areas",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_address_items,
{ "Number of Address Items", "ndps.num_address_items",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_job_categories,
{ "Number of Job Categories", "ndps.num_job_categories",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_page_selects,
{ "Number of Page Select Items", "ndps.num_page_selects",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_page_informations,
{ "Number of Page Information Items", "ndps.num_page_informations",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_names,
{ "Number of Names", "ndps.num_names",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_categories,
{ "Number of Categories", "ndps.num_categories",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_colorants,
{ "Number of Colorants", "ndps.num_colorants",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_events,
{ "Number of Events", "ndps.num_events",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_args,
{ "Number of Arguments", "ndps.num_argss",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_transfer_methods,
{ "Number of Transfer Methods", "ndps.num_transfer_methods",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_doc_types,
{ "Number of Document Types", "ndps.num_doc_types",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_destinations,
{ "Number of Destinations", "ndps.num_destinations",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_qualifier,
{ "Qualifier", "ndps.qual",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_lib_error,
{ "Library Error", "ndps.lib_error",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_error_types_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_other_error,
{ "Other Error", "ndps.other_error",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_error_types_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_other_error_2,
{ "Other Error 2", "ndps.other_error_2",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_error_types_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_session,
{ "Session Handle", "ndps.session",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_abort_flag,
{ "Abort?", "ndps.abort",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_obj_attribute_type,
{ "Value Syntax", "ndps.attrib_type",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_attribute_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_attribute_value,
{ "Value", "ndps.attribue_value",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_lower_range,
{ "Lower Range", "ndps.lower_range",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_upper_range,
{ "Upper Range", "ndps.upper_range",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_n64,
{ "Value", "ndps.n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_lower_range_n64,
{ "Lower Range", "ndps.lower_range_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_upper_range_n64,
{ "Upper Range", "ndps.upper_range_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_attrib_boolean,
{ "Value?", "ndps.attrib_boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_realization,
{ "Realization Type", "ndps.realization",
FT_UINT32, BASE_HEX, VALS(ndps_realization_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_xdimension_n64,
{ "X Dimension", "ndps.xdimension_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ydimension_n64,
{ "Y Dimension", "ndps.ydimension_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_dim_value,
{ "Dimension Value Type", "ndps.dim_value",
FT_UINT32, BASE_HEX, VALS(ndps_dim_value_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_dim_flag,
{ "Dimension Flag", "ndps.dim_falg",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_xydim_value,
{ "XY Dimension Value Type", "ndps.xydim_value",
FT_UINT32, BASE_HEX, VALS(ndps_xydim_value_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_location_value,
{ "Location Value Type", "ndps.location_value",
FT_UINT32, BASE_HEX, VALS(ndps_location_value_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_xmin_n64,
{ "Minimum X Dimension", "ndps.xmin_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_xmax_n64,
{ "Maximum X Dimension", "ndps.xmax_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ymin_n64,
{ "Minimum Y Dimension", "ndps.ymin_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ymax_n64,
{ "Maximum Y Dimension", "ndps.ymax_n64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_edge_value,
{ "Edge Value", "ndps.edge_value",
FT_UINT32, BASE_HEX, VALS(ndps_edge_value_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_cardinal_or_oid,
{ "Cardinal or OID", "ndps.car_or_oid",
FT_UINT32, BASE_HEX, VALS(ndps_card_or_oid_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_cardinal_name_or_oid,
{ "Cardinal Name or OID", "ndps.car_name_or_oid",
FT_UINT32, BASE_HEX, VALS(ndps_card_name_or_oid_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_integer_or_oid,
{ "Integer or OID", "ndps.integer_or_oid",
FT_UINT32, BASE_HEX, VALS(ndps_integer_or_oid_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_profile_id,
{ "Profile ID", "ndps.profile_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_persistence,
{ "Persistence", "ndps.persistence",
FT_UINT32, BASE_HEX, VALS(ndps_persistence_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_language_count,
{ "Number of Languages", "ndps.language_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_language_id,
{ "Language ID", "ndps.lang_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_address_type,
{ "Address Type", "ndps.address_type",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_address_type_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_address,
{ "Address", "ndps.address",
FT_UINT32, BASE_HEX, VALS(ndps_address_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_add_bytes,
{ "Address Bytes", "ndps.add_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_event_type,
{ "Event Type", "ndps.event_type",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_event_object_identifier,
{ "Event Object Type", "ndps.event_object_identifier",
FT_UINT32, BASE_HEX, VALS(ndps_event_object_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_octet_string,
{ "Octet String", "ndps.octet_string",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_scope,
{ "Scope", "ndps.scope",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_address_len,
{ "Address Length", "ndps.addr_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_net,
{ "IPX Network", "ndps.net",
FT_IPXNET, BASE_NONE, NULL, 0x0,
"Scope", HFILL }},
{ &hf_ndps_node,
{ "Node", "ndps.node",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_socket,
{ "IPX Socket", "ndps.socket",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_port,
{ "IP Port", "ndps.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ip,
{ "IP Address", "ndps.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_server_type,
{ "NDPS Server Type", "ndps.server_type",
FT_UINT32, BASE_HEX, VALS(ndps_server_type_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_num_services,
{ "Number of Services", "ndps.num_services",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_service_type,
{ "NDPS Service Type", "ndps.service_type",
FT_UINT32, BASE_HEX, VALS(ndps_service_type_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_service_enabled,
{ "Service Enabled?", "ndps.service_enabled",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_method_name,
{ "Method Name", "ndps.method_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_method_ver,
{ "Method Version", "ndps.method_ver",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_file_name,
{ "File Name", "ndps.file_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_admin_submit,
{ "Admin Submit Flag?", "ndps.admin_submit_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_oid,
{ "Object ID", "ndps.oid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_object_op,
{ "Operation", "ndps.object_op",
FT_UINT32, BASE_HEX, VALS(ndps_object_op_enum), 0x0,
NULL, HFILL }},
{ &hf_answer_time,
{ "Answer Time", "ndps.answer_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_oid_asn1_type,
{ "ASN.1 Type", "ndps.asn1_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_item_ptr,
{ "Item Pointer", "ndps.item_ptr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_len,
{ "Length", "ndps.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_limit_enc,
{ "Limit Encountered", "ndps.limit_enc",
FT_UINT32, BASE_HEX, VALS(ndps_limit_enc_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_delivery_add_count,
{ "Number of Delivery Addresses", "ndps.delivery_add_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_delivery_add_type,
{ "Delivery Address Type", "ndps.delivery_add_type",
FT_UINT32, BASE_HEX, VALS(ndps_delivery_add_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_criterion_type,
{ "Criterion Type", "ndps.criterion_type",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_attribute_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_ignored_attributes,
{ "Number of Ignored Attributes", "ndps.num_ignored_attributes",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ignored_type,
{ "Ignored Type", "ndps.ignored_type",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_attribute_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_resources,
{ "Number of Resources", "ndps.num_resources",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_resource_type,
{ "Resource Type", "ndps.resource_type",
FT_UINT32, BASE_HEX, VALS(ndps_resource_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_identifier_type,
{ "Identifier Type", "ndps.identifier_type",
FT_UINT32, BASE_HEX, VALS(ndps_identifier_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_page_flag,
{ "Page Flag", "ndps.page_flag",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_media_type,
{ "Media Type", "ndps.media_type",
FT_UINT32, BASE_HEX, VALS(ndps_media_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_page_size,
{ "Page Size", "ndps.page_size",
FT_UINT32, BASE_HEX, VALS(ndps_page_size_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_direction,
{ "Direction", "ndps.direction",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_pres_direction_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_page_order,
{ "Page Order", "ndps.page_order",
FT_UINT32, BASE_HEX, VALS(ndps_page_order_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_medium_size,
{ "Medium Size", "ndps.medium_size",
FT_UINT32, BASE_HEX, VALS(ndps_medium_size_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_long_edge_feeds,
{ "Long Edge Feeds?", "ndps.long_edge_feeds",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_inc_across_feed,
{ "Increment Across Feed", "ndps.inc_across_feed",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_size_inc_in_feed,
{ "Size Increment in Feed", "ndps.size_inc_in_feed",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_page_orientation,
{ "Page Orientation", "ndps.page_orientation",
FT_UINT32, BASE_HEX, VALS(ndps_page_orientation_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_numbers_up,
{ "Numbers Up", "ndps.numbers_up",
FT_UINT32, BASE_HEX, VALS(ndps_numbers_up_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_xdimension,
{ "X Dimension", "ndps.xdimension",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ydimension,
{ "Y Dimension", "ndps.ydimension",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_state_severity,
{ "State Severity", "ndps.state_severity",
FT_UINT32, BASE_HEX, VALS(ndps_state_severity_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_training,
{ "Training", "ndps.training",
FT_UINT32, BASE_HEX, VALS(ndps_training_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_colorant_set,
{ "Colorant Set", "ndps.colorant_set",
FT_UINT32, BASE_HEX, VALS(ndps_colorant_set_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_card_enum_time,
{ "Cardinal, Enum, or Time", "ndps.card_enum_time",
FT_UINT32, BASE_HEX, VALS(ndps_card_enum_time_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_attrs_arg,
{ "List Attribute Operation", "ndps.attrs_arg",
FT_UINT32, BASE_HEX, VALS(ndps_attrs_arg_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_context_len,
{ "Context Length", "ndps.context_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_context,
{ "Context", "ndps.context",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_filter,
{ "Filter Type", "ndps.filter",
FT_UINT32, BASE_HEX, VALS(ndps_filter_enum), 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_item_filter,
{ "Filter Item Operation", "ndps.filter_item",
FT_UINT32, BASE_HEX, VALS(ndps_filter_item_enum), 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_ndps_substring_match,
{ "Substring Match", "ndps.substring_match",
FT_UINT32, BASE_HEX, VALS(ndps_match_criteria_enum), 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_time_limit,
{ "Time Limit", "ndps.time_limit",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_count_limit,
{ "Count Limit", "ndps.count_limit",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_operator,
{ "Operator Type", "ndps.operator",
FT_UINT32, BASE_DEC, VALS(ndps_operator_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_password,
{ "Password", "ndps.password",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_retrieve_restrictions,
{ "Retrieve Restrictions", "ndps.ret_restrict",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_bind_security_option_count,
{ "Number of Bind Security Options", "ndps.bind_security_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bind_security,
{ "Bind Security Options", "ndps.bind_security",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_max_items,
{ "Maximum Items in List", "ndps.max_items",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_status_flags,
{ "Status Flag", "ndps.status_flags",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_resource_list_type,
{ "Resource Type", "ndps.resource_type",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &ndps_resource_type_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_os_count,
{ "Number of OSes", "ndps.os_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_os_type,
{ "OS Type", "ndps.os_type",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &ndps_os_type_enum_ext, 0x0,
NULL, HFILL }},
{ &hf_ndps_printer_type_count,
{ "Number of Printer Types", "ndps.printer_type_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_printer_type,
{ "Printer Type", "ndps.prn_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_printer_manuf,
{ "Printer Manufacturer", "ndps.prn_manuf",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_inf_file_name,
{ "INF File Name", "ndps.inf_file_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_vendor_dir,
{ "Vendor Directory", "ndps.vendor_dir",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_banner_type,
{ "Banner Type", "ndps.banner_type",
FT_UINT32, BASE_DEC, VALS(ndps_banner_type_enum), 0x0,
NULL, HFILL }},
{ &hf_font_type,
{ "Font Type", "ndps.font_type",
FT_UINT32, BASE_DEC, VALS(ndps_font_type_enum), 0x0,
NULL, HFILL }},
{ &hf_printer_id,
{ "Printer ID", "ndps.printer_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_font_name,
{ "Font Name", "ndps.font_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_return_code,
{ "Return Code", "ndps.ret_code",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &ndps_error_types_ext, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_banner_count,
{ "Number of Banners", "ndps.banner_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_banner_name,
{ "Banner Name", "ndps.banner_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_font_type_count,
{ "Number of Font Types", "ndps.font_type_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_font_type_name,
{ "Font Type Name", "ndps.font_type_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_font_file_count,
{ "Number of Font Files", "ndps.font_file_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_font_file_name,
{ "Font File Name", "ndps.font_file_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_printer_def_count,
{ "Number of Printer Definitions", "ndps.printer_def_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_prn_file_name,
{ "Printer File Name", "ndps.print_file_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_prn_dir_name,
{ "Printer Directory Name", "ndps.print_dir_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_def_file_name,
{ "Printer Definition Name", "ndps.print_def_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_win31_keys,
{ "Number of Windows 3.1 Keys", "ndps.num_win31_keys",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_win95_keys,
{ "Number of Windows 95 Keys", "ndps.num_win95_keys",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_num_windows_keys,
{ "Number of Windows Keys", "ndps.num_windows_keys",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_windows_key,
{ "Windows Key", "ndps.windows_key",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_archive_type,
{ "Archive Type", "ndps.archive_type",
FT_UINT32, BASE_DEC, VALS(ndps_archive_enum), 0x0,
NULL, HFILL }},
{ &hf_archive_file_size,
{ "Archive File Size", "ndps.archive_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_segment_overlap,
{ "Segment overlap", "ndps.segment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Segment overlaps with other segments", HFILL }},
{ &hf_ndps_segment_overlap_conflict,
{ "Conflicting data in segment overlap", "ndps.segment.overlap.conflict",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Overlapping segments contained conflicting data", HFILL }},
{ &hf_ndps_segment_multiple_tails,
{ "Multiple tail segments found", "ndps.segment.multipletails",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Several tails were found when desegmenting the packet", HFILL }},
{ &hf_ndps_segment_too_long_segment,
{ "Segment too long", "ndps.segment.toolongsegment", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Segment contained data past end of packet", HFILL }},
{ &hf_ndps_segment_error,
{"Desegmentation error", "ndps.segment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Desegmentation error due to illegal segments", HFILL }},
{ &hf_ndps_segment_count,
{"Segment count", "ndps.segment.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ndps_reassembled_length,
{"Reassembled NDPS length", "ndps.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x0, "The total length of the reassembled payload", HFILL }},
{ &hf_ndps_segment,
{ "NDPS Fragment", "ndps.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ndps_segments,
{ "NDPS Fragments", "ndps.fragments", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ndps_data,
{ "Data", "ndps.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_get_status_flag,
{ "Get Status Flag", "ndps.get_status_flags",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_res_type,
{ "Resource Type", "ndps.res_type",
FT_UINT32, BASE_DEC, VALS(ndps_res_type_enum), 0x0,
NULL, HFILL }},
{ &hf_file_timestamp,
{ "File Time Stamp", "ndps.file_time_stamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_print_arg,
{ "Print Type", "ndps.print_arg",
FT_UINT32, BASE_DEC, VALS(ndps_print_arg_enum), 0x0,
NULL, HFILL }},
{ &hf_sub_complete,
{ "Submission Complete?", "ndps.sub_complete", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_doc_content,
{ "Document Content", "ndps.doc_content",
FT_UINT32, BASE_DEC, VALS(ndps_doc_content_enum), 0x0,
NULL, HFILL }},
#if 0
{ &hf_ndps_doc_name,
{ "Document Name", "ndps.doc_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_local_id,
{ "Local ID", "ndps.local_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_included_doc_len,
{ "Included Document Length", "ndps.included_doc_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_included_doc,
{ "Included Document", "ndps.included_doc",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ref_name,
{ "Referenced Document Name", "ndps.ref_doc_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_interrupt_job_type,
{ "Interrupt Job Identifier", "ndps.interrupt_job_type",
FT_UINT32, BASE_DEC, VALS(ndps_interrupt_job_enum), 0x0,
NULL, HFILL }},
{ &hf_pause_job_type,
{ "Pause Job Identifier", "ndps.pause_job_type",
FT_UINT32, BASE_DEC, VALS(ndps_pause_job_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_force,
{ "Force?", "ndps.force",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_resubmit_op_type,
{ "Resubmit Operation Type", "ndps.resubmit_op_type",
FT_UINT32, BASE_DEC, VALS(ndps_resubmit_op_enum), 0x0,
NULL, HFILL }},
{ &hf_shutdown_type,
{ "Shutdown Type", "ndps.shutdown_type",
FT_UINT32, BASE_DEC, VALS(ndps_shutdown_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_supplier_flag,
{ "Supplier Data?", "ndps.supplier_flag",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_language_flag,
{ "Language Data?", "ndps.language_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_method_flag,
{ "Method Data?", "ndps.method_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_delivery_address_flag,
{ "Delivery Address Data?", "ndps.delivery_flag",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_list_profiles_type,
{ "List Profiles Type", "ndps.list_profiles_type",
FT_UINT32, BASE_HEX, VALS(ndps_attrs_arg_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_list_profiles_choice_type,
{ "List Profiles Choice Type", "ndps.list_profiles_choice_type",
FT_UINT32, BASE_HEX, VALS(ndps_list_profiles_choice_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_list_profiles_result_type,
{ "List Profiles Result Type", "ndps.list_profiles_result_type",
FT_UINT32, BASE_HEX, VALS(ndps_list_profiles_result_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_integer_type_flag,
{ "Integer Type Flag", "ndps.integer_type_flag",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_integer_type_value,
{ "Integer Type Value", "ndps.integer_type_value",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_continuation_option,
{ "Continuation Option", "ndps.continuation_option",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_ds_info_type,
{ "DS Info Type", "ndps.ds_info_type",
FT_UINT32, BASE_HEX, VALS(ndps_ds_info_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_guid,
{ "GUID", "ndps.guid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_list_services_type,
{ "Services Type", "ndps.list_services_type",
FT_UINT32, BASE_HEX, VALS(ndps_list_services_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_item_bytes,
{ "Item Ptr", "ndps.item_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_certified,
{ "Certified", "ndps.certified",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_attribute_set,
{ "Attribute Set", "ndps.attribute_set",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_data_item_type,
{ "Item Type", "ndps.data_item_type",
FT_UINT32, BASE_HEX, VALS(ndps_data_item_enum), 0x0,
NULL, HFILL }},
{ &hf_info_int,
{ "Integer Value", "ndps.info_int",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_info_int16,
{ "16 Bit Integer Value", "ndps.info_int16",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_info_int32,
{ "32 Bit Integer Value", "ndps.info_int32",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_info_boolean,
{ "Boolean Value", "ndps.info_boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_info_string,
{ "String Value", "ndps.info_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_info_bytes,
{ "Byte Value", "ndps.info_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ndps_list_local_servers_type,
{ "Server Type", "ndps.list_local_server_type",
FT_UINT32, BASE_HEX, VALS(ndps_list_local_servers_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_registry_name,
{ "Registry Name", "ndps.registry_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_client_server_type,
{ "Client/Server Type", "ndps.client_server_type",
FT_UINT32, BASE_HEX, VALS(ndps_client_server_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_session_type,
{ "Session Type", "ndps.session_type",
FT_UINT32, BASE_HEX, VALS(ndps_session_type_enum), 0x0,
NULL, HFILL }},
{ &hf_time,
{ "Time", "ndps.time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_supplier_name,
{ "Supplier Name", "ndps.supplier_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_message,
{ "Message", "ndps.message",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_delivery_method_count,
{ "Number of Delivery Methods", "ndps.delivery_method_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_delivery_method_type,
{ "Delivery Method Type", "ndps.delivery_method_type",
FT_UINT32, BASE_HEX, VALS(ndps_delivery_method_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_get_session_type,
{ "Session Type", "ndps.get_session_type",
FT_UINT32, BASE_HEX, VALS(ndps_get_session_type_enum), 0x0,
NULL, HFILL }},
{ &hf_packet_count,
{ "Packet Count", "ndps.packet_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_last_packet_flag,
{ "Last Packet Flag", "ndps.last_packet_flag",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_get_resman_session_type,
{ "Session Type", "ndps.get_resman_session_type",
FT_UINT32, BASE_HEX, VALS(ndps_get_resman_session_type_enum), 0x0,
NULL, HFILL }},
{ &hf_problem_type,
{ "Problem Type", "ndps.problem_type",
FT_UINT32, BASE_HEX, VALS(problem_type_enum), 0x0,
NULL, HFILL }},
{ &hf_ndps_num_values,
{ "Number of Values", "ndps.num_values",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ndps_object_ids_7,
{ "Object ID Definition", "ndps.objectid_def7",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_8,
{ "Object ID Definition", "ndps.objectid_def8",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_9,
{ "Object ID Definition", "ndps.objectid_def9",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_10,
{ "Object ID Definition", "ndps.objectid_def10",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_11,
{ "Object ID Definition", "ndps.objectid_def11",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_12,
{ "Object ID Definition", "ndps.objectid_def12",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_13,
{ "Object ID Definition", "ndps.objectid_def13",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_14,
{ "Object ID Definition", "ndps.objectid_def14",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_15,
{ "Object ID Definition", "ndps.objectid_def15",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ndps_object_ids_16,
{ "Object ID Definition", "ndps.objectid_def16",
FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
#if 0
{ &hf_ndps_attribute_time,
{ "Time", "ndps.attribute_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_print_security,
{ "Printer Security", "ndps.print_security",
FT_UINT32, BASE_HEX, VALS(ndps_print_security), 0x0,
NULL, HFILL }},
{ &hf_notify_time_interval,
{ "Notify Time Interval", "ndps.notify_time_interval",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_notify_sequence_number,
{ "Notify Sequence Number", "ndps.notify_seq_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_notify_lease_exp_time,
{ "Notify Lease Expiration Time", "ndps.notify_lease_exp_time",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_notify_printer_uri,
{ "Notify Printer URI", "ndps.notify_printer_uri",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_level,
{ "Level", "ndps.level",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_interval,
{ "Interval", "ndps.interval",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_ndps,
&ett_ndps_segments,
&ett_ndps_segment,
};
static ei_register_info ei[] = {
{ &ei_ndps_problem_type, { "ndps.problem_type.expert", PI_RESPONSE_CODE, PI_NOTE, "Fault", EXPFILL }},
{ &ei_ndps_return_code, { "ndps.return_code.expert", PI_RESPONSE_CODE, PI_NOTE, "Fault", EXPFILL }},
{ &ei_ndps_rpc_acc_stat, { "ndps.rpc_acc_stat.expert", PI_RESPONSE_CODE, PI_NOTE, "Fault", EXPFILL }},
{ &ei_ndps_truncated, { "ndps.truncated", PI_PROTOCOL, PI_WARN, "Truncated", EXPFILL }},
};
module_t *ndps_module;
expert_module_t* expert_ndps;
proto_ndps = proto_register_protocol("Novell Distributed Print System", "NDPS", "ndps");
proto_register_field_array(proto_ndps, hf_ndps, array_length(hf_ndps));
proto_register_subtree_array(ett, array_length(ett));
expert_ndps = expert_register_protocol(proto_ndps);
expert_register_field_array(expert_ndps, ei, array_length(ei));
ndps_module = prefs_register_protocol(proto_ndps, NULL);
prefs_register_bool_preference(ndps_module, "desegment_tcp",
"Reassemble NDPS messages spanning multiple TCP segments",
"Whether the NDPS dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ndps_desegment);
prefs_register_bool_preference(ndps_module, "desegment_spx",
"Reassemble fragmented NDPS messages spanning multiple SPX packets",
"Whether the NDPS dissector should reassemble fragmented NDPS messages spanning multiple SPX packets",
&ndps_defragment);
prefs_register_bool_preference(ndps_module, "show_oid",
"Display NDPS Details",
"Whether or not the NDPS dissector should show object id's and other details",
&ndps_show_oids);
register_init_routine(&ndps_init_protocol);
register_cleanup_routine(&ndps_cleanup_protocol);
register_postseq_cleanup_routine(&ndps_postseq_cleanup);
}
void
proto_reg_handoff_ndps(void)
{
dissector_handle_t ndps_handle, ndps_tcp_handle;
ndps_handle = new_create_dissector_handle(dissect_ndps_ipx, proto_ndps);
ndps_tcp_handle = new_create_dissector_handle(dissect_ndps_tcp, proto_ndps);
dissector_add_uint("spx.socket", SPX_SOCKET_PA, ndps_handle);
dissector_add_uint("spx.socket", SPX_SOCKET_BROKER, ndps_handle);
dissector_add_uint("spx.socket", SPX_SOCKET_SRS, ndps_handle);
dissector_add_uint("spx.socket", SPX_SOCKET_ENS, ndps_handle);
dissector_add_uint("spx.socket", SPX_SOCKET_RMS, ndps_handle);
dissector_add_uint("spx.socket", SPX_SOCKET_NOTIFY_LISTENER, ndps_handle);
dissector_add_uint("tcp.port", TCP_PORT_PA, ndps_tcp_handle);
dissector_add_uint("tcp.port", TCP_PORT_BROKER, ndps_tcp_handle);
dissector_add_uint("tcp.port", TCP_PORT_SRS, ndps_tcp_handle);
dissector_add_uint("tcp.port", TCP_PORT_ENS, ndps_tcp_handle);
dissector_add_uint("tcp.port", TCP_PORT_RMS, ndps_tcp_handle);
dissector_add_uint("tcp.port", TCP_PORT_NOTIFY_LISTENER, ndps_tcp_handle);
ndps_data_handle = find_dissector("data");
}
