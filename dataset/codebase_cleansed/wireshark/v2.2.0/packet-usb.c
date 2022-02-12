static int usb_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrp = (const guint8 *)addr->data;
if(pletoh32(&addrp[0])==0xffffffff){
g_strlcpy(buf, "host", buf_len);
} else {
g_snprintf(buf, buf_len, "%d.%d.%d", pletoh16(&addrp[8]),
pletoh32(&addrp[0]), pletoh32(&addrp[4]));
}
return (int)(strlen(buf)+1);
}
static int usb_addr_str_len(const address* addr _U_)
{
return 50;
}
static void
usb_device_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Bus ID %u \nDevice Address %u\nas ",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_BUS_ID)),
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_ADDRESS)));
}
static gpointer
usb_device_value(packet_info *pinfo)
{
guint32 value = GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_BUS_ID)) << 16;
value |= GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_ADDRESS));
return GUINT_TO_POINTER(value);
}
static void
usb_product_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Vendor ID 0x%04x \nProduct ID 0x%04x\nas ",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_VENDOR_ID)),
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_PRODUCT_ID)));
}
static gpointer
usb_product_value(packet_info *pinfo)
{
guint32 value = GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_VENDOR_ID)) << 16;
value |= GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_PRODUCT_ID));
return GUINT_TO_POINTER(value);
}
static void
usb_protocol_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Class ID 0x%04x \nSubclass ID 0x%04x\nProtocol 0x%04x\nas ",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_CLASS)),
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_SUBCLASS)),
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_PROTOCOL)));
}
static gpointer
usb_protocol_value(packet_info *pinfo)
{
guint32 value = GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_CLASS)) << 16;
value |= GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_SUBCLASS)) << 8;
value |= GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_PROTOCOL));
return GUINT_TO_POINTER(value);
}
static usb_conv_info_t *
get_usb_conv_info(conversation_t *conversation)
{
usb_conv_info_t *usb_conv_info;
usb_conv_info = (usb_conv_info_t *)conversation_get_proto_data(conversation, proto_usb);
if (!usb_conv_info) {
usb_conv_info = wmem_new0(wmem_file_scope(), usb_conv_info_t);
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->interfaceProtocol = IF_PROTOCOL_UNKNOWN;
usb_conv_info->deviceVendor = DEV_VENDOR_UNKNOWN;
usb_conv_info->deviceProduct = DEV_PRODUCT_UNKNOWN;
usb_conv_info->alt_settings = wmem_array_new(wmem_file_scope(), sizeof(usb_alt_setting_t));
usb_conv_info->transactions = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_usb, usb_conv_info);
}
return usb_conv_info;
}
static void clear_usb_conv_tmp_data(usb_conv_info_t *usb_conv_info)
{
usb_conv_info->direction = P2P_DIR_UNKNOWN;
usb_conv_info->transfer_type = URB_UNKNOWN;
usb_conv_info->is_request = FALSE;
usb_conv_info->is_setup = FALSE;
usb_conv_info->setup_requesttype = 0;
if (usb_conv_info->endpoint==0) {
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->interfaceProtocol = IF_PROTOCOL_UNKNOWN;
}
}
static conversation_t *
get_usb_conversation(packet_info *pinfo,
address *src_addr, address *dst_addr,
guint32 src_endpoint, guint32 dst_endpoint)
{
conversation_t *conversation;
conversation = find_conversation(pinfo->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
if (conversation) {
return conversation;
}
conversation = conversation_new(pinfo->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
return conversation;
}
usb_conv_info_t *
get_usb_iface_conv_info(packet_info *pinfo, guint8 interface_num)
{
conversation_t *conversation;
guint32 if_port;
if_port = GUINT32_TO_LE(INTERFACE_PORT | interface_num);
if (pinfo->srcport == NO_ENDPOINT) {
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, pinfo->srcport, if_port);
} else {
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, if_port, pinfo->destport);
}
return get_usb_conv_info(conversation);
}
static const char* usb_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == usb_address_type))
return "usb.src";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == usb_address_type))
return "usb.dst";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == usb_address_type))
return "usb.addr";
return CONV_FILTER_INVALID;
}
static int
usb_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip _U_)
{
conv_hash_t *hash = (conv_hash_t*) pct;
add_conversation_table_data(hash, &pinfo->src, &pinfo->dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts, &usb_ct_dissector_info, PT_NONE);
return 1;
}
static const char* usb_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == usb_address_type))
return "usb.addr";
return CONV_FILTER_INVALID;
}
static int
usb_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip _U_)
{
conv_hash_t *hash = (conv_hash_t*) pit;
add_hostlist_table_data(hash, &pinfo->src, 0, TRUE, 1, pinfo->fd->pkt_len, &usb_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &pinfo->dst, 0, FALSE, 1, pinfo->fd->pkt_len, &usb_host_dissector_info, PT_NONE);
return 1;
}
static int
dissect_usb_setup_clear_feature_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
guint8 recip;
if (usb_conv_info) {
recip = USB_RECIPIENT(usb_conv_info->usb_trans_info->setup.requesttype);
switch (recip) {
case RQT_SETUP_RECIPIENT_DEVICE:
proto_tree_add_item(tree, hf_usb_device_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_INTERFACE:
proto_tree_add_item(tree, hf_usb_interface_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_ENDPOINT:
proto_tree_add_item(tree, hf_usb_endpoint_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wEndpoint, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_OTHER:
default:
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
} else {
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_clear_feature_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_get_configuration_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bConfigurationValue, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
proto_item * dissect_usb_descriptor_header(proto_tree *tree,
tvbuff_t *tvb, int offset,
value_string_ext *type_val_str)
{
guint8 desc_type;
proto_item *length_item;
proto_item *type_item;
length_item = proto_tree_add_item(tree, hf_usb_bLength,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
desc_type = tvb_get_guint8(tvb, offset);
type_item = proto_tree_add_item(tree, hf_usb_bDescriptorType,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (!type_val_str)
type_val_str = &std_descriptor_type_vals_ext;
proto_item_append_text(type_item, " (%s)",
val_to_str_ext(desc_type, type_val_str, "unknown"));
return length_item;
}
static int
dissect_usb_device_qualifier_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
proto_item *nitem;
int old_offset = offset;
guint32 protocol;
const gchar *description;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "DEVICE QUALIFIER DESCRIPTOR");
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
proto_tree_add_item(tree, hf_usb_bcdUSB, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
protocol = tvb_get_ntoh24(tvb, offset);
description = val_to_str_ext_const(protocol, &usb_protocols_ext, "");
proto_tree_add_item(tree, hf_usb_bDeviceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
nitem = proto_tree_add_item(tree, hf_usb_bDeviceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (*description)
proto_item_append_text(nitem, " (%s)", description);
offset += 1;
if (!pinfo->fd->flags.visited) {
guint k_bus_id;
guint k_device_address;
guint k_frame_number;
wmem_tree_key_t key[4];
device_protocol_data_t *device_protocol_data;
k_frame_number = pinfo->num;
k_device_address = usb_conv_info->device_address;
k_bus_id = usb_conv_info->bus_id;
key[0].length = 1;
key[0].key = &k_device_address;
key[1].length = 1;
key[1].key = &k_bus_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_protocol_data = wmem_new(wmem_file_scope(), device_protocol_data_t);
device_protocol_data->protocol = protocol;
device_protocol_data->bus_id = usb_conv_info->bus_id;
device_protocol_data->device_address = usb_conv_info->device_address;
wmem_tree_insert32_array(device_to_protocol_table, key, device_protocol_data);
}
proto_tree_add_item(tree, hf_usb_bMaxPacketSize0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumConfigurations, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_usb_device_descriptor(packet_info *pinfo, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
proto_item *nitem;
int old_offset = offset;
guint32 protocol;
const gchar *description;
guint32 vendor_id;
guint32 product;
guint16 product_id;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "DEVICE DESCRIPTOR");
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
proto_tree_add_item(tree, hf_usb_bcdUSB, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
protocol = tvb_get_ntoh24(tvb, offset);
description = val_to_str_ext_const(protocol, &usb_protocols_ext, "");
proto_tree_add_item(tree, hf_usb_bDeviceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
nitem = proto_tree_add_item(tree, hf_usb_bDeviceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (*description)
proto_item_append_text(nitem, " (%s)", description);
offset += 1;
proto_tree_add_item(tree, hf_usb_bMaxPacketSize0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (8 == usb_conv_info->usb_trans_info->setup.wLength) {
proto_item_set_len(item, offset-old_offset);
return offset;
}
proto_tree_add_item_ret_uint(tree, hf_usb_idVendor, tvb, offset, 2, ENC_LITTLE_ENDIAN, &vendor_id);
usb_conv_info->deviceVendor = (guint16)vendor_id;
offset += 2;
product_id = tvb_get_letohs(tvb, offset);
usb_conv_info->deviceProduct = product_id;
product = (guint16)vendor_id << 16 | product_id;
proto_tree_add_uint_format_value(tree, hf_usb_idProduct, tvb, offset, 2, product_id, "%s (0x%04x)",
val_to_str_ext_const(product, &ext_usb_products_vals, "Unknown"),
product_id);
offset += 2;
if (!pinfo->fd->flags.visited) {
guint k_bus_id;
guint k_device_address;
guint k_frame_number;
wmem_tree_key_t key[4];
device_product_data_t *device_product_data;
device_protocol_data_t *device_protocol_data;
k_frame_number = pinfo->num;
k_device_address = usb_conv_info->device_address;
k_bus_id = usb_conv_info->bus_id;
key[0].length = 1;
key[0].key = &k_device_address;
key[1].length = 1;
key[1].key = &k_bus_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_product_data = wmem_new(wmem_file_scope(), device_product_data_t);
device_product_data->vendor = vendor_id;
device_product_data->product = product_id;
device_product_data->bus_id = usb_conv_info->bus_id;
device_product_data->device_address = usb_conv_info->device_address;
wmem_tree_insert32_array(device_to_product_table, key, device_product_data);
device_protocol_data = wmem_new(wmem_file_scope(), device_protocol_data_t);
device_protocol_data->protocol = protocol;
device_protocol_data->bus_id = usb_conv_info->bus_id;
device_protocol_data->device_address = usb_conv_info->device_address;
wmem_tree_insert32_array(device_to_protocol_table, key, device_protocol_data);
}
proto_tree_add_item(tree, hf_usb_bcdDevice, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_iManufacturer, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iProduct, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iSerialNumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumConfigurations, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_usb_string_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
guint8 len;
proto_item *len_item;
usb_trans_info_t *usb_trans_info;
usb_trans_info = usb_conv_info->usb_trans_info;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "STRING DESCRIPTOR");
len = tvb_get_guint8(tvb, offset);
if (len & 0x1) {
len_item = proto_tree_add_item(tree, hf_usb_bLength, tvb, offset, 1, ENC_LITTLE_ENDIAN);
expert_add_info(pinfo, len_item, &ei_usb_bLength_even);
proto_tree_add_item(tree, hf_usb_bDescriptorType, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
}
else
len_item = dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
if (len < 2) {
expert_add_info(pinfo, len_item, &ei_usb_bLength_too_short);
return offset;
}
if (!usb_trans_info->u.get_descriptor.usb_index) {
while (offset >= old_offset && len > (offset - old_offset)) {
proto_tree_add_item(tree, hf_usb_wLANGID, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
}
} else {
guint8 len_str = MIN(len-2, usb_trans_info->setup.wLength -2);
proto_tree_add_item(tree, hf_usb_bString, tvb, offset, len_str, ENC_UTF_16 | ENC_LITTLE_ENDIAN);
offset += len_str;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_usb_interface_descriptor(packet_info *pinfo, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
const char *class_str = NULL;
int old_offset = offset;
guint8 len;
guint8 interface_num;
guint8 alt_setting;
usb_trans_info_t *usb_trans_info;
usb_trans_info = usb_conv_info->usb_trans_info;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "INTERFACE DESCRIPTOR");
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
interface_num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_bInterfaceNumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_conv_info->interfaceNum = interface_num;
offset += 1;
alt_setting = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_bAlternateSetting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumEndpoints, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bInterfaceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_conv_info->interfaceClass = tvb_get_guint8(tvb, offset);
class_str = val_to_str_ext(usb_conv_info->interfaceClass, &usb_class_vals_ext, "unknown (0x%X)");
proto_item_append_text(item, " (%u.%u): class %s", interface_num, alt_setting, class_str);
if (!pinfo->fd->flags.visited) {
usb_alt_setting_t alternate_setting;
usb_trans_info->interface_info = get_usb_iface_conv_info(pinfo, interface_num);
alternate_setting.altSetting = alt_setting;
alternate_setting.interfaceClass = tvb_get_guint8(tvb, offset);
alternate_setting.interfaceSubclass = tvb_get_guint8(tvb, offset+1);
alternate_setting.interfaceProtocol = tvb_get_guint8(tvb, offset+2);
wmem_array_append_one(usb_trans_info->interface_info->alt_settings, alternate_setting);
if (alt_setting == 0) {
usb_trans_info->interface_info->endpoint = NO_ENDPOINT8;
usb_trans_info->interface_info->interfaceClass = alternate_setting.interfaceClass;
usb_trans_info->interface_info->interfaceSubclass = alternate_setting.interfaceSubclass;
usb_trans_info->interface_info->interfaceProtocol = alternate_setting.interfaceProtocol;
usb_trans_info->interface_info->deviceVendor = usb_conv_info->deviceVendor;
usb_trans_info->interface_info->deviceProduct = usb_conv_info->deviceProduct;
}
}
offset += 1;
switch (usb_conv_info->interfaceClass) {
case IF_CLASS_COMMUNICATIONS:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_cdc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_HID:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_hid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_MISCELLANEOUS:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_misc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_APPLICATION_SPECIFIC:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_app, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
usb_conv_info->interfaceSubclass = tvb_get_guint8(tvb, offset);
offset += 1;
switch (usb_conv_info->interfaceClass) {
case IF_CLASS_COMMUNICATIONS:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_cdc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_CDC_DATA:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_cdc_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_APPLICATION_SPECIFIC:
switch (usb_conv_info->interfaceSubclass) {
case 0x01:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_app_dfu, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 0x02:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_app_irda, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 0x03:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_app_usb_test_and_measurement, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
break;
case IF_CLASS_HID:
if (usb_conv_info->interfaceSubclass == 1) {
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol_hid_boot, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
}
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
usb_conv_info->interfaceProtocol = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_usb_iInterface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_set_len(item, len);
if (offset < old_offset+len) {
offset = old_offset + len;
}
return offset;
}
void dissect_usb_endpoint_address(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *endpoint_item;
proto_tree *endpoint_tree;
guint8 endpoint;
endpoint_item = proto_tree_add_item(tree, hf_usb_bEndpointAddress, tvb, offset, 1, ENC_LITTLE_ENDIAN);
endpoint_tree = proto_item_add_subtree(endpoint_item, ett_configuration_bEndpointAddress);
endpoint = tvb_get_guint8(tvb, offset)&0x0f;
proto_tree_add_item(endpoint_tree, hf_usb_bEndpointAddress_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(endpoint_item, " %s", (tvb_get_guint8(tvb, offset)&0x80)?"IN":"OUT");
proto_tree_add_item(endpoint_tree, hf_usb_bEndpointAddress_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(endpoint_item, " Endpoint:%d", endpoint);
}
int
dissect_usb_endpoint_descriptor(packet_info *pinfo, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
proto_item *ep_attrib_item;
proto_tree *ep_attrib_tree;
proto_item *ep_pktsize_item;
proto_tree *ep_pktsize_tree;
int old_offset = offset;
guint8 endpoint;
guint8 ep_type;
guint8 len;
usb_trans_info_t *usb_trans_info = NULL;
if (usb_conv_info)
usb_trans_info = usb_conv_info->usb_trans_info;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "ENDPOINT DESCRIPTOR");
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
endpoint = tvb_get_guint8(tvb, offset)&0x0f;
dissect_usb_endpoint_address(tree, tvb, offset);
offset += 1;
if ((!pinfo->fd->flags.visited) && usb_trans_info && usb_trans_info->interface_info) {
conversation_t *conversation = NULL;
if (pinfo->destport == NO_ENDPOINT) {
address tmp_addr;
usb_address_t *usb_addr = wmem_new0(wmem_packet_scope(), usb_address_t);
usb_addr->bus_id = ((const usb_address_t *)(pinfo->src.data))->bus_id;
usb_addr->device = ((const usb_address_t *)(pinfo->src.data))->device;
usb_addr->endpoint = GUINT32_TO_LE(endpoint);
set_address(&tmp_addr, usb_address_type, USB_ADDR_LEN, (char *)usb_addr);
conversation = get_usb_conversation(pinfo, &tmp_addr, &pinfo->dst, usb_addr->endpoint, pinfo->destport);
}
if (conversation) {
usb_trans_info->interface_info->endpoint = endpoint;
conversation_add_proto_data(conversation, proto_usb, usb_trans_info->interface_info);
}
}
ep_type = ENDPOINT_TYPE(tvb_get_guint8(tvb, offset));
ep_attrib_item = proto_tree_add_item(tree, hf_usb_bmAttributes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
ep_attrib_tree = proto_item_add_subtree(ep_attrib_item, ett_endpoint_bmAttributes);
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeTransfer, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if (ep_type==USB_EP_ISOCHRONOUS) {
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeSynchonisation, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeBehaviour, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset += 1;
ep_pktsize_item = proto_tree_add_item(tree, hf_usb_wMaxPacketSize, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ep_pktsize_tree = proto_item_add_subtree(ep_pktsize_item, ett_endpoint_wMaxPacketSize);
if ((ep_type == ENDPOINT_TYPE_INTERRUPT) || (ep_type == ENDPOINT_TYPE_ISOCHRONOUS)) {
proto_tree_add_item(ep_pktsize_tree, hf_usb_wMaxPacketSize_slots, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(ep_pktsize_tree, hf_usb_wMaxPacketSize_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_bInterval, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_set_len(item, len);
if (offset < old_offset+len) {
offset = old_offset + len;
}
return offset;
}
static int
dissect_usb_interface_assn_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "INTERFACE ASSOCIATION DESCRIPTOR");
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
proto_tree_add_item(tree, hf_usb_bFirstInterface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bInterfaceCount, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bFunctionClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bFunctionSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bFunctionProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iFunction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_item_set_len(item, offset-old_offset);
return offset;
}
int
dissect_usb_unknown_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *tree;
guint8 bLength;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "UNKNOWN DESCRIPTOR");
bLength = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += bLength;
proto_item_set_len(item, bLength);
return offset;
}
static int
dissect_usb_configuration_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
guint16 len;
proto_item *flags_item;
proto_tree *flags_tree;
guint8 flags;
proto_item *power_item;
guint8 power;
gboolean truncation_expected;
usb_trans_info_t *usb_trans_info;
usb_trans_info = usb_conv_info->usb_trans_info;
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->interfaceProtocol = IF_PROTOCOL_UNKNOWN;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_descriptor_device, &item, "CONFIGURATION DESCRIPTOR");
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
proto_tree_add_item(tree, hf_usb_wTotalLength, tvb, offset, 2, ENC_LITTLE_ENDIAN);
len = tvb_get_letohs(tvb, offset);
offset+=2;
proto_tree_add_item(tree, hf_usb_bNumInterfaces, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bConfigurationValue, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iConfiguration, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
flags_item = proto_tree_add_item(tree, hf_usb_configuration_bmAttributes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_configuration_bmAttributes);
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(flags_tree, hf_usb_configuration_legacy10buspowered, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_usb_configuration_selfpowered, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(flags_item, " %sSELF-POWERED", (flags&0x40)?"":"NOT ");
proto_tree_add_item(flags_tree, hf_usb_configuration_remotewakeup, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(flags_item, " %sREMOTE-WAKEUP", (flags&0x20)?"":"NO ");
offset += 1;
power_item = proto_tree_add_item(tree, hf_usb_bMaxPower, tvb, offset, 1, ENC_LITTLE_ENDIAN);
power = tvb_get_guint8(tvb, offset);
proto_item_append_text(power_item, " (%dmA)", power*2);
offset += 1;
usb_trans_info->interface_info = NULL;
truncation_expected = (usb_trans_info->setup.wLength < len);
while(len>(offset-old_offset)) {
guint8 next_type;
guint8 next_len = 0;
gint remaining_tvb, remaining_len;
tvbuff_t *next_tvb = NULL;
remaining_tvb = tvb_reported_length_remaining(tvb, offset);
if (remaining_tvb > 0) {
next_len = tvb_get_guint8(tvb, offset);
remaining_len = len - (offset - old_offset);
if ((next_len < 3) || (next_len > remaining_len)) {
proto_tree_add_expert_format(parent_tree, pinfo, &ei_usb_desc_length_invalid,
tvb, offset, 1, "Invalid descriptor length: %u", next_len);
item = NULL;
break;
}
}
if ((remaining_tvb == 0) || (next_len > remaining_tvb)) {
if (truncation_expected)
break;
}
next_type = tvb_get_guint8(tvb, offset+1);
switch(next_type) {
case USB_DT_INTERFACE:
offset = dissect_usb_interface_descriptor(pinfo, parent_tree, tvb, offset, usb_conv_info);
break;
case USB_DT_ENDPOINT:
offset = dissect_usb_endpoint_descriptor(pinfo, parent_tree, tvb, offset, usb_conv_info);
break;
case USB_DT_INTERFACE_ASSOCIATION:
offset = dissect_usb_interface_assn_descriptor(pinfo, parent_tree, tvb, offset, usb_conv_info);
break;
default:
next_tvb = tvb_new_subset_length(tvb, offset, next_len);
if (dissector_try_uint_new(usb_descriptor_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent_tree, TRUE, usb_conv_info)) {
offset += next_len;
} else {
offset = dissect_usb_unknown_descriptor(pinfo, parent_tree, tvb, offset, usb_conv_info);
}
break;
}
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_usb_setup_get_descriptor_request(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
usb_trans_info_t *usb_trans_info, trans_info;
if (usb_conv_info)
usb_trans_info = usb_conv_info->usb_trans_info;
else
usb_trans_info = &trans_info;
proto_tree_add_item(tree, hf_usb_descriptor_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.usb_index = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDescriptorType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.type = tvb_get_guint8(tvb, offset);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(usb_trans_info->u.get_descriptor.type, &std_descriptor_type_vals_ext, "Unknown type %u"));
proto_tree_add_item(tree, hf_usb_language_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_get_descriptor_response(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
usb_trans_info_t *usb_trans_info;
usb_trans_info = usb_conv_info->usb_trans_info;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(usb_trans_info->u.get_descriptor.type, &std_descriptor_type_vals_ext, "Unknown type %u"));
switch(usb_trans_info->u.get_descriptor.type) {
case USB_DT_INTERFACE:
case USB_DT_ENDPOINT:
break;
case USB_DT_DEVICE:
offset = dissect_usb_device_descriptor(pinfo, tree, tvb, offset, usb_conv_info);
break;
case USB_DT_CONFIG:
offset = dissect_usb_configuration_descriptor(pinfo, tree, tvb, offset, usb_conv_info);
break;
case USB_DT_STRING:
offset = dissect_usb_string_descriptor(pinfo, tree, tvb, offset, usb_conv_info);
break;
case USB_DT_DEVICE_QUALIFIER:
offset = dissect_usb_device_qualifier_descriptor(pinfo, tree, tvb, offset, usb_conv_info);
break;
default:
{
guint len = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_bytes_format(tree, hf_usb_get_descriptor_resp_generic, tvb, offset, len, NULL,
"GET DESCRIPTOR Response data (unknown descriptor type %u): %s",
usb_trans_info->u.get_descriptor.type,
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len));
offset = offset + len;
}
break;
}
return offset;
}
static int
dissect_usb_setup_get_interface_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_get_interface_response(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bAlternateSetting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_usb_setup_get_status_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (usb_conv_info) {
guint8 recip;
recip = USB_RECIPIENT(usb_conv_info->usb_trans_info->setup.requesttype);
switch (recip) {
case RQT_SETUP_RECIPIENT_INTERFACE:
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_ENDPOINT:
proto_tree_add_item(tree, hf_usb_wEndpoint, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_DEVICE:
case RQT_SETUP_RECIPIENT_OTHER:
default:
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
} else {
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_get_status_response(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wStatus, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_set_address_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_device_address, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_set_address_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_configuration_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bConfigurationValue, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_set_configuration_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_feature_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
guint8 recip;
if (usb_conv_info) {
recip = USB_RECIPIENT(usb_conv_info->usb_trans_info->setup.requesttype);
switch (recip) {
case RQT_SETUP_RECIPIENT_DEVICE:
proto_tree_add_item(tree, hf_usb_device_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_INTERFACE:
proto_tree_add_item(tree, hf_usb_interface_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_ENDPOINT:
proto_tree_add_item(tree, hf_usb_endpoint_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wEndpoint, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RQT_SETUP_RECIPIENT_OTHER:
default:
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
} else {
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_set_feature_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_interface_request(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
guint8 alt_setting, interface_num;
alt_setting = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_usb_bAlternateSetting, tvb, offset, 2, alt_setting);
offset += 2;
interface_num = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_usb_wInterface, tvb, offset, 2, interface_num);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (!PINFO_FD_VISITED(pinfo)) {
guint i, count;
usb_conv_info_t *iface_conv_info = get_usb_iface_conv_info(pinfo, interface_num);
count = wmem_array_get_count(iface_conv_info->alt_settings);
for (i = 0; i < count; i++) {
usb_alt_setting_t *alternate_setting = (usb_alt_setting_t *)wmem_array_index(iface_conv_info->alt_settings, i);
if (alternate_setting->altSetting == alt_setting) {
iface_conv_info->interfaceClass = alternate_setting->interfaceClass;
iface_conv_info->interfaceSubclass = alternate_setting->interfaceSubclass;
iface_conv_info->interfaceProtocol = alternate_setting->interfaceProtocol;
break;
}
}
}
return offset;
}
static int
dissect_usb_setup_set_interface_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_synch_frame_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wEndpoint, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_synch_frame_response(packet_info *pinfo _U_, proto_tree *tree _U_,
tvbuff_t *tvb _U_, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wFrameNumber, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_generic(packet_info *pinfo _U_, proto_tree *tree ,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_standard_setup_request(packet_info *pinfo, proto_tree *tree ,
tvbuff_t *tvb, usb_conv_info_t *usb_conv_info,
usb_trans_info_t *usb_trans_info)
{
gint offset = 0;
const usb_setup_dissector_table_t *tmp;
usb_setup_dissector dissector;
proto_tree_add_item(tree, hf_usb_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Request",
val_to_str_ext(usb_trans_info->setup.request, &setup_request_names_vals_ext, "Unknown type %x"));
dissector = NULL;
for(tmp = setup_request_dissectors;tmp->dissector;tmp++) {
if (tmp->request == usb_trans_info->setup.request) {
dissector = tmp->dissector;
break;
}
}
if (!dissector) {
dissector = &dissect_usb_setup_generic;
}
offset = dissector(pinfo, tree, tvb, offset, usb_conv_info);
return offset;
}
static int
dissect_usb_standard_setup_response(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info)
{
const usb_setup_dissector_table_t *tmp;
usb_setup_dissector dissector;
gint length_remaining;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Response",
val_to_str_ext(usb_conv_info->usb_trans_info->setup.request,
&setup_request_names_vals_ext, "Unknown type %x"));
dissector = NULL;
for(tmp = setup_response_dissectors;tmp->dissector;tmp++) {
if (tmp->request == usb_conv_info->usb_trans_info->setup.request) {
dissector = tmp->dissector;
break;
}
}
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (length_remaining <= 0)
return offset;
if (dissector) {
offset = dissector(pinfo, tree, tvb, offset, usb_conv_info);
} else {
proto_tree_add_item(tree, hf_usb_control_response_generic,
tvb, offset, length_remaining, ENC_NA);
offset += length_remaining;
}
return offset;
}
static void
usb_tap_queue_packet(packet_info *pinfo, guint8 urb_type,
usb_conv_info_t *usb_conv_info)
{
usb_tap_data_t *tap_data;
tap_data = wmem_new(wmem_packet_scope(), usb_tap_data_t);
tap_data->urb_type = urb_type;
tap_data->transfer_type = (guint8)(usb_conv_info->transfer_type);
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_conv_info->usb_trans_info;
tap_queue_packet(usb_tap, pinfo, tap_data);
}
static gboolean
is_usb_standard_setup_request(usb_trans_info_t *usb_trans_info)
{
guint8 type, recip;
type = USB_TYPE(usb_trans_info->setup.requesttype);
recip = USB_RECIPIENT(usb_trans_info->setup.requesttype);
if (type != RQT_SETUP_TYPE_STANDARD)
return FALSE;
if (usb_trans_info->setup.request == USB_SETUP_GET_DESCRIPTOR &&
recip != RQT_SETUP_RECIPIENT_DEVICE) {
return FALSE;
}
return TRUE;
}
static gint
try_dissect_next_protocol(proto_tree *tree, tvbuff_t *next_tvb, packet_info *pinfo,
usb_conv_info_t *usb_conv_info, guint8 urb_type, proto_tree *urb_tree)
{
int ret;
wmem_tree_key_t key[4];
guint32 k_frame_number;
guint32 k_device_address;
guint32 k_bus_id;
usb_trans_info_t *usb_trans_info;
heur_dtbl_entry_t *hdtbl_entry;
heur_dissector_list_t heur_subdissector_list = NULL;
dissector_table_t usb_dissector_table = NULL;
proto_item *sub_item;
device_product_data_t *device_product_data;
device_protocol_data_t *device_protocol_data;
guint8 ctrl_recip;
guint32 usb_class;
if (!usb_conv_info) {
if (tvb_reported_length(next_tvb) > 0)
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(next_tvb);
}
ret = dissector_try_uint_new(device_to_dissector,
(guint32)(usb_conv_info->bus_id<<16 | usb_conv_info->device_address),
next_tvb, pinfo, tree, TRUE, usb_conv_info);
if (ret)
return tvb_captured_length(next_tvb);
k_frame_number = pinfo->num;
k_device_address = usb_conv_info->device_address;
k_bus_id = usb_conv_info->bus_id;
key[0].length = 1;
key[0].key = &k_device_address;
key[1].length = 1;
key[1].key = &k_bus_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_protocol_data = (device_protocol_data_t *)wmem_tree_lookup32_array_le(device_to_protocol_table, key);
if (device_protocol_data &&
device_protocol_data->bus_id == usb_conv_info->bus_id &&
device_protocol_data->device_address == usb_conv_info->device_address) {
ret = dissector_try_uint_new(protocol_to_dissector,
(guint32)device_protocol_data->protocol,
next_tvb, pinfo, tree, TRUE, usb_conv_info);
if (ret)
return tvb_captured_length(next_tvb);
}
device_product_data = (device_product_data_t *)wmem_tree_lookup32_array_le(device_to_product_table, key);
if (device_product_data && device_product_data->bus_id == usb_conv_info->bus_id &&
device_product_data->device_address == usb_conv_info->device_address) {
ret = dissector_try_uint_new(product_to_dissector,
(guint32)(device_product_data->vendor<<16 | device_product_data->product),
next_tvb, pinfo, tree, TRUE, usb_conv_info);
if (ret)
return tvb_captured_length(next_tvb);
}
switch(usb_conv_info->transfer_type) {
case URB_BULK:
heur_subdissector_list = heur_bulk_subdissector_list;
usb_dissector_table = usb_bulk_dissector_table;
break;
case URB_INTERRUPT:
heur_subdissector_list = heur_interrupt_subdissector_list;
usb_dissector_table = usb_interrupt_dissector_table;
break;
case URB_CONTROL:
usb_trans_info = usb_conv_info->usb_trans_info;
if (!usb_trans_info)
break;
if (is_usb_standard_setup_request(usb_trans_info))
break;
ctrl_recip = USB_RECIPIENT(usb_trans_info->setup.requesttype);
if (ctrl_recip == RQT_SETUP_RECIPIENT_DEVICE) {
break;
}
else if (ctrl_recip == RQT_SETUP_RECIPIENT_INTERFACE) {
guint8 interface_num = usb_trans_info->setup.wIndex & 0xff;
heur_subdissector_list = heur_control_subdissector_list;
usb_dissector_table = usb_control_dissector_table;
usb_conv_info = get_usb_iface_conv_info(pinfo, interface_num);
usb_conv_info->usb_trans_info = usb_trans_info;
}
else if (ctrl_recip == RQT_SETUP_RECIPIENT_ENDPOINT) {
address endpoint_addr;
gint endpoint;
guint32 src_endpoint, dst_endpoint;
conversation_t *conversation;
heur_subdissector_list = heur_control_subdissector_list;
usb_dissector_table = usb_control_dissector_table;
endpoint = usb_trans_info->setup.wIndex & 0x0f;
if (usb_conv_info->is_request) {
usb_address_t *dst_addr = wmem_new0(wmem_packet_scope(), usb_address_t);
dst_addr->bus_id = usb_conv_info->bus_id;
dst_addr->device = usb_conv_info->device_address;
dst_addr->endpoint = dst_endpoint = GUINT32_TO_LE(endpoint);
set_address(&endpoint_addr, usb_address_type, USB_ADDR_LEN, (char *)dst_addr);
conversation = get_usb_conversation(pinfo, &pinfo->src, &endpoint_addr, pinfo->srcport, dst_endpoint);
}
else {
usb_address_t *src_addr = wmem_new0(wmem_packet_scope(), usb_address_t);
src_addr->bus_id = usb_conv_info->bus_id;
src_addr->device = usb_conv_info->device_address;
src_addr->endpoint = src_endpoint = GUINT32_TO_LE(endpoint);
set_address(&endpoint_addr, usb_address_type, USB_ADDR_LEN, (char *)src_addr);
conversation = get_usb_conversation(pinfo, &endpoint_addr, &pinfo->dst, src_endpoint, pinfo->destport);
}
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
}
else {
heur_subdissector_list = heur_control_subdissector_list;
usb_dissector_table = usb_control_dissector_table;
}
usb_tap_queue_packet(pinfo, urb_type, usb_conv_info);
sub_item = proto_tree_add_uint(urb_tree, hf_usb_bInterfaceClass, next_tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(sub_item);
break;
default:
break;
}
if (try_heuristics && heur_subdissector_list) {
ret = dissector_try_heuristic(heur_subdissector_list,
next_tvb, pinfo, tree, &hdtbl_entry, usb_conv_info);
if (ret)
return tvb_captured_length(next_tvb);
}
if (usb_dissector_table) {
if (usb_conv_info->interfaceClass == IF_CLASS_DEVICE) {
usb_class = (usb_conv_info->device_protocol>>16) & 0xFF;
}
else {
usb_class = usb_conv_info->interfaceClass;
}
ret = dissector_try_uint_new(usb_dissector_table, usb_class,
next_tvb, pinfo, tree, TRUE, usb_conv_info);
if (ret)
return tvb_captured_length(next_tvb);
}
return 0;
}
static int
dissect_usb_setup_response(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
guint8 urb_type, usb_conv_info_t *usb_conv_info)
{
proto_tree *parent;
tvbuff_t *next_tvb = NULL;
gint length_remaining;
parent = proto_tree_get_parent_tree(tree);
if (usb_conv_info) {
if (usb_conv_info->usb_trans_info && is_usb_standard_setup_request(usb_conv_info->usb_trans_info)) {
offset = dissect_usb_standard_setup_response(pinfo, parent, tvb, offset, usb_conv_info);
}
else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += try_dissect_next_protocol(parent, next_tvb, pinfo, usb_conv_info, urb_type, tree);
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (length_remaining > 0) {
proto_tree_add_item(parent, hf_usb_control_response_generic,
tvb, offset, length_remaining, ENC_NA);
offset += length_remaining;
}
}
}
else {
length_remaining = tvb_reported_length_remaining(tvb, offset);
if (length_remaining > 0) {
proto_tree_add_item(parent, hf_usb_control_response_generic, tvb,
offset, length_remaining, ENC_NA);
offset += length_remaining;
}
}
return offset;
}
static int
dissect_usb_bmrequesttype(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_usb_bmRequestType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_usb_setup_bmrequesttype);
proto_tree_add_item(tree, hf_usb_bmRequestType_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_recipient, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return ++offset;
}
static int
dissect_linux_usb_pseudo_header_ext(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_,
proto_tree *tree)
{
proto_tree_add_item(tree, hf_usb_urb_interval, tvb, offset, 4, ENC_HOST_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_urb_start_frame, tvb, offset, 4, ENC_HOST_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_urb_copy_of_transfer_flags, tvb, offset, 4, ENC_HOST_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_iso_numdesc, tvb, offset, 4, ENC_HOST_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_usb_setup_request(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
guint8 urb_type, usb_conv_info_t *usb_conv_info,
usb_header_t header_type)
{
gint setup_offset;
gint req_type;
gint ret;
proto_tree *parent, *setup_tree;
usb_trans_info_t *usb_trans_info, trans_info;
tvbuff_t *next_tvb, *data_tvb = NULL;
if (usb_conv_info)
usb_trans_info = usb_conv_info->usb_trans_info;
else
usb_trans_info = &trans_info;
parent = proto_tree_get_parent_tree(tree);
setup_tree = proto_tree_add_subtree(parent, tvb, offset, 8, ett_usb_setup_hdr, NULL, "URB setup");
req_type = USB_TYPE(tvb_get_guint8(tvb, offset));
usb_trans_info->setup.requesttype = tvb_get_guint8(tvb, offset);
if (usb_conv_info) {
usb_conv_info->setup_requesttype = tvb_get_guint8(tvb, offset);
if (req_type != RQT_SETUP_TYPE_CLASS)
usb_tap_queue_packet(pinfo, urb_type, usb_conv_info);
}
offset = dissect_usb_bmrequesttype(setup_tree, tvb, offset);
setup_offset = offset;
usb_trans_info->setup.request = tvb_get_guint8(tvb, offset);
offset++;
usb_trans_info->setup.wValue = tvb_get_letohs(tvb, offset);
offset += 2;
usb_trans_info->setup.wIndex = tvb_get_letohs(tvb, offset);
offset += 2;
usb_trans_info->setup.wLength = tvb_get_letohs(tvb, offset);
offset += 2;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
if (tvb_captured_length_remaining(tvb, offset) > 0) {
next_tvb = tvb_new_composite();
tvb_composite_append(next_tvb, tvb_new_subset(tvb, setup_offset, 7, 7));
data_tvb = tvb_new_subset_remaining(tvb, offset);
tvb_composite_append(next_tvb, data_tvb);
offset += tvb_captured_length(data_tvb);
tvb_composite_finalize(next_tvb);
next_tvb = tvb_new_child_real_data(tvb,
(const guint8 *) tvb_memdup(pinfo->pool, next_tvb, 0, tvb_captured_length(next_tvb)),
tvb_captured_length(next_tvb),
tvb_captured_length(next_tvb));
add_new_data_source(pinfo, next_tvb, "USB Control");
} else {
next_tvb = tvb_new_subset(tvb, setup_offset, 7, 7);
}
if (is_usb_standard_setup_request(usb_trans_info)) {
dissect_usb_standard_setup_request(pinfo, setup_tree,
next_tvb, usb_conv_info, usb_trans_info);
}
else {
ret = try_dissect_next_protocol(
parent, next_tvb, pinfo, usb_conv_info, urb_type, tree);
if (ret <= 0) {
proto_tree_add_item(setup_tree, hf_usb_request_unknown_class,
next_tvb, 0, 1, ENC_LITTLE_ENDIAN);
dissect_usb_setup_generic(pinfo, setup_tree,
next_tvb, 1, usb_conv_info);
} else if (data_tvb) {
proto_tree_add_item(setup_tree, hf_usb_request_unknown_class,
tvb, setup_offset, 1, ENC_LITTLE_ENDIAN);
dissect_usb_setup_generic(pinfo, setup_tree,
tvb, setup_offset+1, usb_conv_info);
}
}
if (data_tvb)
proto_tree_add_item(setup_tree, hf_usb_data_fragment, data_tvb, 0, -1, ENC_NA);
return offset;
}
static gint
dissect_linux_usb_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
usb_conv_info_t *usb_conv_info, guint64 *urb_id)
{
guint8 transfer_type;
guint8 endpoint_byte;
guint8 transfer_type_and_direction;
guint8 urb_type;
guint8 flag[2];
*urb_id = tvb_get_guint64(tvb, 0, ENC_HOST_ENDIAN);
proto_tree_add_uint64(tree, hf_usb_urb_id, tvb, 0, 8, *urb_id);
urb_type = tvb_get_guint8(tvb, 8);
usb_conv_info->is_request = (urb_type==URB_SUBMIT);
proto_tree_add_uint_format_value(tree, hf_usb_linux_urb_type, tvb, 8, 1,
urb_type, "%s ('%c')", val_to_str(urb_type, usb_linux_urb_type_vals, "Unknown %d"),
g_ascii_isprint(urb_type) ? urb_type : '.');
proto_tree_add_item(tree, hf_usb_linux_transfer_type, tvb, 9, 1, ENC_LITTLE_ENDIAN);
transfer_type = tvb_get_guint8(tvb, 9);
usb_conv_info->transfer_type = transfer_type;
endpoint_byte = tvb_get_guint8(tvb, 10);
usb_conv_info->endpoint = endpoint_byte & 0x7F;
if (endpoint_byte & URB_TRANSFER_IN)
usb_conv_info->direction = P2P_DIR_RECV;
else
usb_conv_info->direction = P2P_DIR_SENT;
transfer_type_and_direction = (transfer_type & 0x7F) | (endpoint_byte & 0x80);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(transfer_type_and_direction, usb_transfer_type_and_direction_vals, "Unknown type %x"));
proto_tree_add_bitmask(tree, tvb, 10, hf_usb_endpoint_number, ett_usb_endpoint, usb_endpoint_fields, ENC_NA);
proto_tree_add_item(tree, hf_usb_device_address, tvb, 11, 1, ENC_LITTLE_ENDIAN);
usb_conv_info->device_address = (guint16)tvb_get_guint8(tvb, 11);
proto_tree_add_item(tree, hf_usb_bus_id, tvb, 12, 2, ENC_HOST_ENDIAN);
tvb_memcpy(tvb, &usb_conv_info->bus_id, 12, 2);
flag[0] = tvb_get_guint8(tvb, 14);
flag[1] = '\0';
if (flag[0] == 0) {
usb_conv_info->is_setup = TRUE;
proto_tree_add_string(tree, hf_usb_setup_flag, tvb, 14, 1, "relevant (0)");
if (usb_conv_info->transfer_type!=URB_CONTROL)
proto_tree_add_expert(tree, pinfo, &ei_usb_invalid_setup, tvb, 14, 1);
} else {
usb_conv_info->is_setup = FALSE;
proto_tree_add_string_format_value(tree, hf_usb_setup_flag, tvb,
14, 1, flag, "not relevant ('%c')", g_ascii_isprint(flag[0]) ? flag[0]: '.');
}
flag[0] = tvb_get_guint8(tvb, 15);
flag[1] = '\0';
if (flag[0] == 0) {
proto_tree_add_string(tree, hf_usb_data_flag, tvb, 15, 1, "present (0)");
} else {
proto_tree_add_string_format_value(tree, hf_usb_data_flag, tvb,
15, 1, flag, "not present ('%c')", g_ascii_isprint(flag[0]) ? flag[0] : '.');
}
proto_tree_add_item(tree, hf_usb_urb_ts_sec, tvb, 16, 8, ENC_HOST_ENDIAN);
proto_tree_add_item(tree, hf_usb_urb_ts_usec, tvb, 24, 4, ENC_HOST_ENDIAN);
proto_tree_add_item(tree, hf_usb_urb_status, tvb, 28, 4, ENC_HOST_ENDIAN);
proto_tree_add_item(tree, hf_usb_urb_len, tvb, 32, 4, ENC_HOST_ENDIAN);
proto_tree_add_item(tree, hf_usb_urb_data_len, tvb, 36, 4, ENC_HOST_ENDIAN);
return 40;
}
static gint
dissect_usbpcap_buffer_packet_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
usb_conv_info_t *usb_conv_info, guint32 *win32_data_len, guint64 *irp_id)
{
guint8 transfer_type;
guint8 endpoint_byte;
guint8 transfer_type_and_direction;
guint8 tmp_val8;
proto_tree_add_item(tree, hf_usb_win32_header_len, tvb, 0, 2, ENC_LITTLE_ENDIAN);
*irp_id = tvb_get_guint64(tvb, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_uint64(tree, hf_usb_irp_id, tvb, 2, 8, *irp_id);
proto_tree_add_item(tree, hf_usb_usbd_status, tvb, 10, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_function, tvb, 14, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 16, hf_usb_info, ett_usb_usbpcap_info, usb_usbpcap_info_fields, ENC_LITTLE_ENDIAN);
tmp_val8 = tvb_get_guint8(tvb, 16);
if (tmp_val8 & 0x01) {
usb_conv_info->is_request = FALSE;
} else {
usb_conv_info->is_request = TRUE;
}
proto_tree_add_item(tree, hf_usb_bus_id, tvb, 17, 2, ENC_LITTLE_ENDIAN);
usb_conv_info->bus_id = tvb_get_letohs(tvb, 17);
proto_tree_add_item(tree, hf_usb_win32_device_address, tvb, 19, 2, ENC_LITTLE_ENDIAN);
usb_conv_info->device_address = tvb_get_letohs(tvb, 19);
endpoint_byte = tvb_get_guint8(tvb, 21);
usb_conv_info->direction = endpoint_byte&URB_TRANSFER_IN ? P2P_DIR_RECV : P2P_DIR_SENT;
usb_conv_info->endpoint = endpoint_byte&0x7F;
proto_tree_add_bitmask(tree, tvb, 21, hf_usb_endpoint_number, ett_usb_endpoint, usb_endpoint_fields, ENC_LITTLE_ENDIAN);
transfer_type = tvb_get_guint8(tvb, 22);
usb_conv_info->transfer_type = transfer_type;
proto_tree_add_item(tree, hf_usb_linux_transfer_type, tvb, 22, 1, ENC_LITTLE_ENDIAN);
transfer_type_and_direction = (transfer_type & 0x7F) | (endpoint_byte & 0x80);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(transfer_type_and_direction, usb_transfer_type_and_direction_vals, "Unknown type %x"));
*win32_data_len = tvb_get_letohl(tvb, 23);
proto_tree_add_item(tree, hf_usb_win32_data_len, tvb, 23, 4, ENC_LITTLE_ENDIAN);
usb_conv_info->is_setup = FALSE;
usb_conv_info->setup_requesttype = 0;
return 27;
}
static void
usb_set_addr(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint16 bus_id, guint16 device_address,
int endpoint, gboolean req)
{
proto_item *sub_item;
usb_address_t *src_addr = wmem_new0(pinfo->pool, usb_address_t),
*dst_addr = wmem_new0(pinfo->pool, usb_address_t);
guint8 *str_src_addr;
guint8 *str_dst_addr;
if (req) {
src_addr->device = 0xffffffff;
src_addr->endpoint = NO_ENDPOINT;
dst_addr->device = GUINT16_TO_LE(device_address);
dst_addr->endpoint = GUINT32_TO_LE(endpoint);
} else {
src_addr->device = GUINT16_TO_LE(device_address);
src_addr->endpoint = GUINT32_TO_LE(endpoint);
dst_addr->device = 0xffffffff;
dst_addr->endpoint = NO_ENDPOINT;
}
src_addr->bus_id = GUINT16_TO_LE(bus_id);
dst_addr->bus_id = GUINT16_TO_LE(bus_id);
set_address(&pinfo->net_src, usb_address_type, USB_ADDR_LEN, (char *)src_addr);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
set_address(&pinfo->net_dst, usb_address_type, USB_ADDR_LEN, (char *)dst_addr);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
pinfo->ptype = PT_USB;
pinfo->srcport = src_addr->endpoint;
pinfo->destport = dst_addr->endpoint;
pinfo->p2p_dir = req ? P2P_DIR_SENT : P2P_DIR_RECV;
str_src_addr = address_to_str(wmem_packet_scope(), &pinfo->src);
str_dst_addr = address_to_str(wmem_packet_scope(), &pinfo->dst);
sub_item = proto_tree_add_string(tree, hf_usb_src, tvb, 0, 0, str_src_addr);
PROTO_ITEM_SET_GENERATED(sub_item);
sub_item = proto_tree_add_string(tree, hf_usb_addr, tvb, 0, 0, str_src_addr);
PROTO_ITEM_SET_HIDDEN(sub_item);
sub_item = proto_tree_add_string(tree, hf_usb_dst, tvb, 0, 0, str_dst_addr);
PROTO_ITEM_SET_GENERATED(sub_item);
sub_item = proto_tree_add_string(tree, hf_usb_addr, tvb, 0, 0, str_dst_addr);
PROTO_ITEM_SET_HIDDEN(sub_item);
}
static usb_trans_info_t
*usb_get_trans_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
usb_header_t header_type, usb_conv_info_t *usb_conv_info, guint64 usb_id)
{
usb_trans_info_t *usb_trans_info;
proto_item *ti;
nstime_t t, deltat;
wmem_tree_key_t key[3];
key[0].length = 2;
key[0].key = (guint32 *)&usb_id;
key[1].length = 1;
key[1].key = &pinfo->num;
key[2].length = 0;
key[2].key = NULL;
if (usb_conv_info->is_request) {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32_array(usb_conv_info->transactions, key);
if (!usb_trans_info) {
usb_trans_info = wmem_new0(wmem_file_scope(), usb_trans_info_t);
usb_trans_info->request_in = pinfo->num;
usb_trans_info->req_time = pinfo->abs_ts;
usb_trans_info->header_type = header_type;
usb_trans_info->usb_id = usb_id;
wmem_tree_insert32_array(usb_conv_info->transactions, key, usb_trans_info);
}
if (usb_trans_info->response_in) {
ti = proto_tree_add_uint(tree, hf_usb_response_in, tvb, 0, 0, usb_trans_info->response_in);
PROTO_ITEM_SET_GENERATED(ti);
}
} else {
if (pinfo->fd->flags.visited) {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32_array(usb_conv_info->transactions, key);
} else {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32_array_le(usb_conv_info->transactions, key);
if (usb_trans_info) {
if (usb_trans_info->usb_id == usb_id) {
if (usb_trans_info->response_in == 0) {
usb_trans_info->response_in = pinfo->num;
}
wmem_tree_insert32_array(usb_conv_info->transactions, key, usb_trans_info);
} else {
usb_trans_info = NULL;
}
}
}
if (usb_trans_info && usb_trans_info->request_in) {
ti = proto_tree_add_uint(tree, hf_usb_request_in, tvb, 0, 0, usb_trans_info->request_in);
PROTO_ITEM_SET_GENERATED(ti);
t = pinfo->abs_ts;
nstime_delta(&deltat, &t, &usb_trans_info->req_time);
ti = proto_tree_add_time(tree, hf_usb_time, tvb, 0, 0, &deltat);
PROTO_ITEM_SET_GENERATED(ti);
}
}
return usb_trans_info;
}
static gint
dissect_usbpcap_iso_packets(packet_info *pinfo _U_, proto_tree *urb_tree, guint8 urb_type,
tvbuff_t *tvb, gint offset, guint32 win32_data_len, usb_conv_info_t *usb_conv_info)
{
guint32 i;
guint32 num_packets;
guint32 data_start_offset;
proto_item *urb_tree_ti;
proto_tree_add_item(urb_tree, hf_usb_win32_iso_start_frame, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
num_packets = tvb_get_letohl(tvb, offset);
proto_tree_add_item(urb_tree, hf_usb_win32_iso_num_packets, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(urb_tree, hf_usb_win32_iso_error_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
data_start_offset = offset + 12 * num_packets;
urb_tree_ti = proto_tree_get_parent(urb_tree);
proto_item_set_len(urb_tree_ti, data_start_offset);
for (i = 0; i < num_packets; i++) {
guint32 this_offset;
guint32 next_offset;
guint32 iso_len;
proto_item *iso_packet_ti, *ti;
proto_tree *iso_packet_tree;
iso_packet_ti = proto_tree_add_protocol_format(
proto_tree_get_root(urb_tree), proto_usb,
tvb, offset, 12, "USB isochronous packet");
iso_packet_tree = proto_item_add_subtree(iso_packet_ti, ett_usb_win32_iso_packet);
this_offset = tvb_get_letohl(tvb, offset);
if (num_packets - i == 1) {
next_offset = win32_data_len;
} else {
next_offset = tvb_get_letohl(tvb, offset + 12);
}
if (next_offset > this_offset) {
iso_len = next_offset - this_offset;
} else {
iso_len = 0;
}
if (!((usb_conv_info->is_request && usb_conv_info->direction==P2P_DIR_SENT) ||
(!usb_conv_info->is_request && usb_conv_info->direction==P2P_DIR_RECV))) {
iso_len = 0;
}
proto_tree_add_item(iso_packet_tree, hf_usb_win32_iso_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(iso_packet_tree, hf_usb_win32_iso_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (usb_conv_info->direction==P2P_DIR_SENT) {
proto_item_append_text(ti, " (not used)");
} else {
if (usb_conv_info->is_request) {
proto_item_append_text(ti, " (irrelevant)");
} else {
proto_item_append_text(ti, " (relevant)");
iso_len = tvb_get_letohl(tvb, offset);
}
}
offset += 4;
ti = proto_tree_add_item(iso_packet_tree, hf_usb_win32_iso_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (urb_type == URB_SUBMIT) {
proto_item_append_text(ti, " (irrelevant)");
} else {
proto_item_append_text(ti, " (relevant)");
}
offset += 4;
if (iso_len && data_start_offset + this_offset + iso_len <= tvb_captured_length(tvb)) {
proto_tree_add_item(iso_packet_tree, hf_usb_iso_data, tvb, (gint)(data_start_offset + this_offset), (gint)iso_len, ENC_NA);
proto_tree_set_appendix(iso_packet_tree, tvb, (gint)(data_start_offset + this_offset), (gint)iso_len);
}
}
if ((usb_conv_info->is_request && usb_conv_info->direction==P2P_DIR_SENT) ||
(!usb_conv_info->is_request && usb_conv_info->direction==P2P_DIR_RECV)) {
offset += win32_data_len;
}
return offset;
}
static gint
dissect_linux_usb_iso_transfer(packet_info *pinfo _U_, proto_tree *urb_tree,
usb_header_t header_type, tvbuff_t *tvb, gint offset,
usb_conv_info_t *usb_conv_info)
{
guint32 iso_numdesc = 0;
proto_item *tii;
guint32 val32;
guint32 i;
guint data_base;
guint32 iso_status;
guint32 iso_off = 0;
guint32 iso_len = 0;
tii = proto_tree_add_uint(urb_tree, hf_usb_bInterfaceClass, tvb, offset, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(tii);
tvb_memcpy(tvb, (guint8 *)&val32, offset, 4);
proto_tree_add_uint(urb_tree, hf_usb_iso_error_count, tvb, offset, 4, val32);
offset += 4;
tvb_memcpy(tvb, (guint8 *)&iso_numdesc, offset, 4);
proto_tree_add_uint(urb_tree, hf_usb_iso_numdesc, tvb, offset, 4, iso_numdesc);
offset += 4;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, urb_tree);
}
data_base = offset + iso_numdesc*16;
for (i = 0; i<iso_numdesc; i++) {
proto_item *iso_desc_ti;
proto_tree *iso_desc_tree;
guint32 iso_pad;
tvb_memcpy(tvb, (guint8 *)&iso_status, offset, 4);
tvb_memcpy(tvb, (guint8 *)&iso_off, offset+4, 4);
tvb_memcpy(tvb, (guint8 *)&iso_len, offset+8, 4);
iso_desc_ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, offset,
16, "USB isodesc %u [%s]", i, val_to_str_ext(iso_status, &usb_urb_status_vals_ext, "Error %d"));
if (iso_len > 0)
proto_item_append_text(iso_desc_ti, " (%u bytes)", iso_len);
iso_desc_tree = proto_item_add_subtree(iso_desc_ti, ett_usb_isodesc);
proto_tree_add_int(iso_desc_tree, hf_usb_iso_status, tvb, offset, 4, iso_status);
offset += 4;
proto_tree_add_uint(iso_desc_tree, hf_usb_iso_off, tvb, offset, 4, iso_off);
offset += 4;
proto_tree_add_uint(iso_desc_tree, hf_usb_iso_len, tvb, offset, 4, iso_len);
offset += 4;
if ((pinfo->p2p_dir==P2P_DIR_SENT || !iso_status) &&
iso_len && data_base + iso_off + iso_len <= tvb_captured_length(tvb)) {
proto_tree_add_item(iso_desc_tree, hf_usb_iso_data, tvb, data_base + iso_off, iso_len, ENC_NA);
proto_tree_set_appendix(iso_desc_tree, tvb, (gint)(data_base+iso_off), (gint)iso_len);
}
tvb_memcpy(tvb, (guint8 *)&iso_pad, offset, 4);
proto_tree_add_uint(iso_desc_tree, hf_usb_iso_pad, tvb, offset, 4, iso_pad);
offset += 4;
}
return data_base+iso_off+iso_len;
}
static gint
dissect_usbip_iso_transfer(packet_info *pinfo _U_, proto_tree *urb_tree,
tvbuff_t *tvb, gint offset, guint32 iso_numdesc, guint32 desc_offset,
usb_conv_info_t *usb_conv_info)
{
proto_item *tii;
guint32 i;
guint data_base;
guint32 iso_off = 0;
guint32 iso_len = 0;
tii = proto_tree_add_uint(urb_tree, hf_usb_bInterfaceClass, tvb, offset, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(tii);
data_base = offset;
for (i = 0; i<iso_numdesc; i++) {
proto_item *iso_desc_ti;
proto_tree *iso_desc_tree;
guint32 iso_status;
iso_status = tvb_get_ntohl(tvb, desc_offset + 12);
iso_desc_ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, desc_offset,
16, "USB isodesc %u [%s]", i, val_to_str_ext(iso_status, &usb_urb_status_vals_ext, "Error %d"));
iso_desc_tree = proto_item_add_subtree(iso_desc_ti, ett_usb_isodesc);
proto_tree_add_item_ret_uint(iso_desc_tree, hf_usb_iso_off, tvb, desc_offset, 4, ENC_BIG_ENDIAN, &iso_off);
desc_offset += 4;
proto_tree_add_item(iso_desc_tree, hf_usb_iso_len, tvb, desc_offset, 4, ENC_BIG_ENDIAN);
desc_offset += 4;
proto_tree_add_item_ret_uint(iso_desc_tree, hf_usb_iso_actual_len, tvb, desc_offset, 4, ENC_BIG_ENDIAN, &iso_len);
desc_offset += 4;
if (iso_len > 0)
proto_item_append_text(iso_desc_ti, " (%u bytes)", iso_len);
proto_tree_add_uint(iso_desc_tree, hf_usb_iso_status, tvb, desc_offset, 4, iso_status);
desc_offset += 4;
if ((pinfo->p2p_dir==P2P_DIR_SENT || !iso_status) &&
iso_len && data_base + iso_off + iso_len <= tvb_reported_length(tvb)) {
proto_tree_add_item(iso_desc_tree, hf_usb_iso_data, tvb, (guint) data_base + iso_off, iso_len, ENC_NA);
proto_tree_set_appendix(iso_desc_tree, tvb, (guint) data_base + iso_off, (gint)iso_len);
}
}
return desc_offset;
}
static gint
dissect_usb_payload(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *parent, proto_tree *tree,
usb_conv_info_t *usb_conv_info, guint8 urb_type,
gint offset, guint16 device_address)
{
wmem_tree_key_t key[4];
guint32 k_frame_number;
guint32 k_device_address;
guint32 k_bus_id;
device_product_data_t *device_product_data = NULL;
device_protocol_data_t *device_protocol_data = NULL;
tvbuff_t *next_tvb = NULL;
k_frame_number = pinfo->num;
k_device_address = device_address;
k_bus_id = usb_conv_info->bus_id;
key[0].length = 1;
key[0].key = &k_device_address;
key[1].length = 1;
key[1].key = &k_bus_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_product_data = (device_product_data_t *) wmem_tree_lookup32_array_le(device_to_product_table, key);
if (device_product_data && device_product_data->bus_id == usb_conv_info->bus_id &&
device_product_data->device_address == device_address) {
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_VENDOR_ID, GUINT_TO_POINTER((guint)device_product_data->vendor));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_PRODUCT_ID, GUINT_TO_POINTER((guint)device_product_data->product));
}
device_protocol_data = (device_protocol_data_t *) wmem_tree_lookup32_array_le(device_to_protocol_table, key);
if (device_protocol_data && device_protocol_data->bus_id == usb_conv_info->bus_id &&
device_protocol_data->device_address == device_address) {
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_CLASS, GUINT_TO_POINTER(device_protocol_data->protocol >> 16));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_SUBCLASS, GUINT_TO_POINTER((device_protocol_data->protocol >> 8) & 0xFF));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_PROTOCOL, GUINT_TO_POINTER(device_protocol_data->protocol & 0xFF));
usb_conv_info->device_protocol = device_protocol_data->protocol;
}
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_BUS_ID, GUINT_TO_POINTER((guint)usb_conv_info->bus_id));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_ADDRESS, GUINT_TO_POINTER((guint)device_address));
if (tvb_captured_length_remaining(tvb, offset) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += try_dissect_next_protocol(parent, next_tvb, pinfo, usb_conv_info, urb_type, tree);
}
if (tvb_captured_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(parent, hf_usb_capdata, tvb, offset, -1, ENC_NA);
}
return offset;
}
static int
dissect_freebsd_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent, void *data _U_)
{
int offset = 0;
proto_item *ti;
proto_tree *tree = NULL, *frame_tree = NULL;
guint32 nframes;
guint32 i;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USB");
if (parent) {
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, 0, 128,
"USB URB");
tree = proto_item_add_subtree(ti, ett_usb_hdr);
}
proto_tree_add_item(tree, hf_usb_totlen, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_busunit, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_address, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_mode, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_freebsd_urb_type, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_freebsd_transfer_type, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 12, hf_usb_xferflags, ett_usb_xferflags,
usb_xferflags_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 16, hf_usb_xferstatus, ett_usb_xferstatus,
usb_xferstatus_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_error, tvb, 20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_interval, tvb, 24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item_ret_uint(tree, hf_usb_nframes, tvb, 28, 4, ENC_LITTLE_ENDIAN, &nframes);
proto_tree_add_item(tree, hf_usb_packet_size, tvb, 32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_packet_count, tvb, 36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_endpoint_number, tvb, 40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_speed, tvb, 44, 1, ENC_LITTLE_ENDIAN);
offset += 128;
for (i = 0; i < nframes; i++) {
guint32 framelen;
guint64 frameflags;
frame_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_usb_frame, &ti,
"Frame %u", i);
proto_tree_add_item_ret_uint(frame_tree, hf_usb_frame_length,
tvb, offset, 4, ENC_LITTLE_ENDIAN,
&framelen);
offset += 4;
proto_tree_add_bitmask_ret_uint64(frame_tree, tvb, offset,
hf_usb_frame_flags,
ett_usb_frame_flags,
usb_frame_flags_fields,
ENC_LITTLE_ENDIAN, &frameflags);
offset += 4;
if (frameflags & FREEBSD_FRAMEFLAG_DATA_FOLLOWS) {
proto_tree_add_item(frame_tree, hf_usb_frame_data, tvb, offset,
framelen, ENC_NA);
offset += (framelen + 3) & ~3;
}
proto_item_set_end(ti, tvb, offset);
}
return tvb_captured_length(tvb);
}
void
dissect_usb_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent,
usb_header_t header_type, void *extra_data)
{
gint offset = 0;
int endpoint;
guint8 urb_type;
guint32 win32_data_len = 0;
guint32 iso_numdesc = 0;
guint32 desc_offset = 0;
proto_item *urb_tree_ti;
proto_tree *tree;
proto_item *item;
usb_conv_info_t *usb_conv_info;
conversation_t *conversation;
guint16 device_address;
guint16 bus_id;
guint8 usbpcap_control_stage = 0;
guint64 usb_id;
struct mausb_header *ma_header = NULL;
struct usbip_header *ip_header = NULL;
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
urb_type = tvb_get_guint8(tvb, 8);
endpoint = tvb_get_guint8(tvb, 10) & 0x7F;
device_address = (guint16)tvb_get_guint8(tvb, 11);
bus_id = tvb_get_letohs(tvb, 12);
break;
case USB_HEADER_USBPCAP:
urb_type = tvb_get_guint8(tvb, 16) & 0x01 ? URB_COMPLETE : URB_SUBMIT;
device_address = tvb_get_letohs(tvb, 19);
endpoint = tvb_get_guint8(tvb, 21) & 0x7F;
bus_id = tvb_get_letohs(tvb, 17);
break;
case USB_HEADER_MAUSB:
ma_header = (struct mausb_header *) extra_data;
urb_type = mausb_is_from_host(ma_header) ? URB_SUBMIT : URB_COMPLETE;
device_address = mausb_ep_handle_dev_addr(ma_header->handle);
endpoint = mausb_ep_handle_ep_num(ma_header->handle);
bus_id = mausb_ep_handle_bus_num(ma_header->handle);
break;
case USB_HEADER_USBIP:
ip_header = (struct usbip_header *) extra_data;
urb_type = tvb_get_ntohl(tvb, 0) == 1 ? URB_SUBMIT : URB_COMPLETE;
device_address = ip_header->devid;
bus_id = ip_header->busid;
endpoint = ip_header->ep;
break;
default:
return;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USB");
urb_tree_ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, 0, -1, "USB URB");
tree = proto_item_add_subtree(urb_tree_ti, ett_usb_hdr);
usb_set_addr(tree, tvb, pinfo, bus_id, device_address, endpoint,
(urb_type == URB_SUBMIT));
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, pinfo->srcport, pinfo->destport);
usb_conv_info = get_usb_conv_info(conversation);
clear_usb_conv_tmp_data(usb_conv_info);
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
proto_item_set_len(urb_tree_ti, (header_type == USB_HEADER_LINUX_64_BYTES) ? 64 : 48);
offset = dissect_linux_usb_pseudo_header(tvb, pinfo, tree, usb_conv_info, &usb_id);
break;
case USB_HEADER_USBPCAP:
offset = dissect_usbpcap_buffer_packet_header(tvb, pinfo, tree, usb_conv_info, &win32_data_len, &usb_id);
proto_item_set_len(urb_tree_ti, offset);
break;
case USB_HEADER_MAUSB:
offset = MAUSB_DPH_LENGTH;
mausb_set_usb_conv_info(usb_conv_info, ma_header);
usb_id = 0;
break;
case USB_HEADER_USBIP:
iso_numdesc = tvb_get_ntohl(tvb, 0x20);
usb_conv_info->transfer_type = endpoint == 0 ? URB_CONTROL : (iso_numdesc > 0 ? URB_ISOCHRONOUS : URB_UNKNOWN);
usb_conv_info->direction = ip_header->dir == USBIP_DIR_OUT ? P2P_DIR_SENT : P2P_DIR_RECV;
usb_conv_info->is_setup = endpoint == 0 ? (tvb_get_ntoh64(tvb, 0x28) != G_GUINT64_CONSTANT(0)) : FALSE;
usb_conv_info->is_request = (urb_type==URB_SUBMIT);
offset = usb_conv_info->is_setup ? USBIP_HEADER_WITH_SETUP_LEN : USBIP_HEADER_LEN;
if ((usb_conv_info->is_request && usb_conv_info->direction == USBIP_DIR_OUT) ||
(!usb_conv_info->is_request && usb_conv_info->direction == USBIP_DIR_IN)) {
desc_offset += tvb_get_ntohl(tvb, 0x18);
}
desc_offset += offset;
usb_id = 0;
break;
default:
usb_id = 0;
break;
}
usb_conv_info->usb_trans_info = usb_get_trans_info(tvb, pinfo, tree, header_type, usb_conv_info, usb_id);
if (usb_conv_info->transfer_type != URB_CONTROL) {
usb_tap_queue_packet(pinfo, urb_type, usb_conv_info);
}
switch(usb_conv_info->transfer_type) {
case URB_BULK:
case URB_INTERRUPT:
item = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(item);
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
case USB_HEADER_USBPCAP:
break;
case USB_HEADER_MAUSB:
break;
case USB_HEADER_USBIP:
break;
}
break;
case URB_CONTROL:
if (header_type == USB_HEADER_USBPCAP) {
proto_tree_add_item(tree, hf_usb_control_stage, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usbpcap_control_stage = tvb_get_guint8(tvb, offset);
if (usbpcap_control_stage == USB_CONTROL_STAGE_SETUP)
usb_conv_info->is_setup = TRUE;
offset++;
proto_item_set_len(urb_tree_ti, offset);
}
if (usb_conv_info->is_request) {
if (usb_conv_info->is_setup) {
offset = dissect_usb_setup_request(pinfo, tree, tvb, offset,
urb_type, usb_conv_info, header_type);
} else {
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
case USB_HEADER_USBPCAP:
break;
case USB_HEADER_MAUSB:
break;
case USB_HEADER_USBIP:
break;
}
}
} else {
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
case USB_HEADER_USBPCAP:
if ((usb_conv_info->usb_trans_info) &&
(usbpcap_control_stage == USB_CONTROL_STAGE_STATUS)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Status",
val_to_str_ext(usb_conv_info->usb_trans_info->setup.request,
&setup_request_names_vals_ext, "Unknown type %x"));
return;
}
break;
case USB_HEADER_MAUSB:
break;
case USB_HEADER_USBIP:
break;
}
offset = dissect_usb_setup_response(pinfo, tree, tvb, offset,
urb_type, usb_conv_info);
}
break;
case URB_ISOCHRONOUS:
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
offset = dissect_linux_usb_iso_transfer(pinfo, tree, header_type,
tvb, offset, usb_conv_info);
break;
case USB_HEADER_USBPCAP:
offset = dissect_usbpcap_iso_packets(pinfo, tree,
urb_type, tvb, offset, win32_data_len, usb_conv_info);
break;
case USB_HEADER_MAUSB:
break;
case USB_HEADER_USBIP:
offset = dissect_usbip_iso_transfer(pinfo, tree,
tvb, offset, iso_numdesc, desc_offset, usb_conv_info);
break;
}
break;
default:
switch (header_type) {
case USB_HEADER_LINUX_48_BYTES:
case USB_HEADER_LINUX_64_BYTES:
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
if (header_type == USB_HEADER_LINUX_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
case USB_HEADER_USBPCAP:
break;
case USB_HEADER_MAUSB:
break;
case USB_HEADER_USBIP:
break;
}
break;
}
dissect_usb_payload(tvb, pinfo, parent, tree, usb_conv_info, urb_type,
offset, device_address);
}
static int
dissect_linux_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent, void* data _U_)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_LINUX_48_BYTES, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_linux_usb_mmapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent, void* data _U_)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_LINUX_64_BYTES, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_win32_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent, void* data _U_)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_USBPCAP, NULL);
return tvb_captured_length(tvb);
}
void
proto_register_usb(void)
{
module_t *usb_module;
static hf_register_info hf[] = {
{ &hf_usb_totlen,
{ "Total length", "usb.totlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_busunit,
{ "Host controller unit number", "usb.busunit",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_address,
{ "USB device index", "usb.address",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_mode,
{ "Mode of transfer", "usb.address",
FT_UINT8, BASE_DEC, VALS(usb_freebsd_transfer_mode_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_freebsd_urb_type,
{ "URB type", "usb.freebsd_type",
FT_UINT8, BASE_DEC, VALS(usb_freebsd_urb_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_freebsd_transfer_type,
{ "URB transfer type", "usb.freebsd_transfer_type",
FT_UINT8, BASE_HEX, VALS(usb_freebsd_transfer_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_xferflags,
{ "Transfer flags", "usb.xferflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_xferflags_force_short_xfer,
{ "Force short transfer", "usb.xferflags.force_short_xfer",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_FORCE_SHORT_XFER,
NULL, HFILL }},
{ &hf_usb_xferflags_short_xfer_ok,
{ "Short transfer OK", "usb.xferflags.short_xfer_ok",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_SHORT_XFER_OK,
NULL, HFILL }},
{ &hf_usb_xferflags_short_frames_ok,
{ "Short frames OK", "usb.xferflags.short_frames_ok",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_SHORT_FRAMES_OK,
NULL, HFILL }},
{ &hf_usb_xferflags_pipe_bof,
{ "Pipe BOF", "usb.xferflags.pipe_bof",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_PIPE_BOF,
NULL, HFILL }},
{ &hf_usb_xferflags_proxy_buffer,
{ "Proxy buffer", "usb.xferflags.proxy_buffer",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_PROXY_BUFFER,
NULL, HFILL }},
{ &hf_usb_xferflags_ext_buffer,
{ "External buffer", "usb.xferflags.ext_buffer",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_EXT_BUFFER,
NULL, HFILL }},
{ &hf_usb_xferflags_manual_status,
{ "Manual status", "usb.xferflags.manual_status",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_MANUAL_STATUS,
NULL, HFILL }},
{ &hf_usb_xferflags_no_pipe_ok,
{ "No pipe OK", "usb.xferflags.no_pipe_ok",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_NO_PIPE_OK,
NULL, HFILL }},
{ &hf_usb_xferflags_stall_pipe,
{ "Stall pipe", "usb.xferflags.stall_pipe",
FT_BOOLEAN, 32, NULL, FREEBSD_FLAG_STALL_PIPE,
NULL, HFILL }},
{ &hf_usb_xferstatus,
{ "Transfer status", "usb.xferstatus",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_xferstatus_open,
{ "Pipe has been opened", "usb.xferstatus.open",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_OPEN,
NULL, HFILL }},
{ &hf_usb_xferstatus_transferring,
{ "Transfer in progress", "usb.xferstatus.transferring",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_TRANSFERRING,
NULL, HFILL }},
{ &hf_usb_xferstatus_did_dma_delay,
{ "Waited for hardware DMA", "usb.xferstatus.did_dma_delay",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_DID_DMA_DELAY,
NULL, HFILL }},
{ &hf_usb_xferstatus_did_close,
{ "Transfer closed", "usb.xferstatus.did_close",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_DID_CLOSE,
NULL, HFILL }},
{ &hf_usb_xferstatus_draining,
{ "Draining transfer", "usb.xferstatus.draining",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_DRAINING,
NULL, HFILL }},
{ &hf_usb_xferstatus_started,
{ "Transfer started", "usb.xferstatus.started",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_STARTED,
"Whether the transfer is started or stopped", HFILL }},
{ &hf_usb_xferstatus_bw_reclaimed,
{ "Bandwidth reclaimed", "usb.xferstatus.bw_reclaimed",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_BW_RECLAIMED,
NULL, HFILL }},
{ &hf_usb_xferstatus_control_xfr,
{ "Control transfer", "usb.xferstatus.control_xfr",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_CONTROL_XFR,
NULL, HFILL }},
{ &hf_usb_xferstatus_control_hdr,
{ "Control header being sent", "usb.xferstatus.control_hdr",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_CONTROL_HDR,
NULL, HFILL }},
{ &hf_usb_xferstatus_control_act,
{ "Control transfer active", "usb.xferstatus.control_act",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_CONTROL_ACT,
NULL, HFILL }},
{ &hf_usb_xferstatus_control_stall,
{ "Control transfer should be stalled", "usb.xferstatus.control_stall",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_CONTROL_STALL,
NULL, HFILL }},
{ &hf_usb_xferstatus_short_frames_ok,
{ "Short frames OK", "usb.xferstatus.short_frames_ok",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_SHORT_FRAMES_OK,
NULL, HFILL }},
{ &hf_usb_xferstatus_short_xfer_ok,
{ "Short transfer OK", "usb.xferstatus.short_xfer_ok",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_SHORT_XFER_OK,
NULL, HFILL }},
{ &hf_usb_xferstatus_bdma_enable,
{ "BUS-DMA enabled", "usb.xferstatus.bdma_enable",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_BDMA_ENABLE,
NULL, HFILL }},
{ &hf_usb_xferstatus_bdma_no_post_sync,
{ "BUS-DMA post sync op not done", "usb.xferstatus.bdma_no_post_sync",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_BDMA_NO_POST_SYNC,
NULL, HFILL }},
{ &hf_usb_xferstatus_bdma_setup,
{ "BUS-DMA set up", "usb.xferstatus.bdma_setup",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_BDMA_SETUP,
NULL, HFILL }},
{ &hf_usb_xferstatus_isochronous_xfr,
{ "Isochronous transfer", "usb.xferstatus.isochronous_xfr",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_ISOCHRONOUS_XFR,
NULL, HFILL }},
{ &hf_usb_xferstatus_curr_dma_set,
{ "Current DMA set", "usb.xferstatus.curr_dma_set",
FT_UINT32, BASE_DEC, NULL, FREEBSD_STATUS_CURR_DMA_SET,
NULL, HFILL }},
{ &hf_usb_xferstatus_can_cancel_immed,
{ "Transfer can be cancelled immediately", "usb.xferstatus.can_cancel_immed",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_CAN_CANCEL_IMMED,
NULL, HFILL }},
{ &hf_usb_xferstatus_doing_callback,
{ "Executing the callback", "usb.xferstatus.doing_callback",
FT_BOOLEAN, 32, NULL, FREEBSD_STATUS_DOING_CALLBACK,
NULL, HFILL }},
{ &hf_usb_error,
{ "Error", "usb.error",
FT_UINT32, BASE_DEC, VALS(usb_freebsd_err_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_interval,
{ "Interval", "usb.interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Interval (ms)", HFILL }},
{ &hf_usb_nframes,
{ "Number of following frames", "usb.nframes",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_packet_size,
{ "Packet size used", "usb.packet_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_packet_count,
{ "Packet count used", "usb.packet_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_speed,
{ "Speed", "usb.speed",
FT_UINT8, BASE_DEC, VALS(usb_freebsd_speed_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_frame_length,
{ "Frame length", "usb.frame.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_frame_flags,
{ "Frame flags", "usb.frame.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_frame_flags_read,
{ "Data direction is read", "usb.frame.read",
FT_BOOLEAN, 32, NULL, FREEBSD_FRAMEFLAG_READ,
NULL, HFILL }},
{ &hf_usb_frame_flags_data_follows,
{ "Frame contains data", "usb.frame.data_follows",
FT_BOOLEAN, 32, NULL, FREEBSD_FRAMEFLAG_DATA_FOLLOWS,
NULL, HFILL }},
{ &hf_usb_frame_data,
{ "Frame data", "usb.frame.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_id,
{ "URB id", "usb.urb_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_linux_urb_type,
{ "URB type", "usb.urb_type",
FT_UINT8, BASE_DEC, VALS(usb_linux_urb_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_linux_transfer_type,
{ "URB transfer type", "usb.transfer_type",
FT_UINT8, BASE_HEX, VALS(usb_linux_transfer_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_endpoint_number,
{ "Endpoint", "usb.endpoint_number",
FT_UINT8, BASE_HEX, NULL, 0x0,
"USB endpoint number", HFILL }},
{ &hf_usb_endpoint_direction,
{ "Direction", "usb.endpoint_number.direction",
FT_UINT8, BASE_DEC, VALS(usb_endpoint_direction_vals), 0x80,
"USB endpoint direction", HFILL }},
{ &hf_usb_endpoint_number_value,
{ "Endpoint value", "usb.endpoint_number.endpoint",
FT_UINT8, BASE_DEC, NULL, 0x7F,
"USB endpoint value", HFILL }},
{ &hf_usb_device_address,
{ "Device", "usb.device_address",
FT_UINT8, BASE_DEC, NULL, 0x0,
"USB device address", HFILL }},
{ &hf_usb_bus_id,
{ "URB bus id", "usb.bus_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_setup_flag,
{ "Device setup request", "usb.setup_flag",
FT_STRING, BASE_NONE, NULL, 0x0,
"USB device setup request is relevant (0) or not", HFILL }},
{ &hf_usb_data_flag,
{ "Data", "usb.data_flag",
FT_STRING, BASE_NONE, NULL, 0x0,
"USB data is present (0) or not", HFILL }},
{ &hf_usb_urb_ts_sec,
{ "URB sec", "usb.urb_ts_sec",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_ts_usec,
{ "URB usec", "usb.urb_ts_usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_status,
{ "URB status", "usb.urb_status",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &usb_urb_status_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_len,
{ "URB length [bytes]", "usb.urb_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"URB length in bytes", HFILL }},
{ &hf_usb_urb_data_len,
{ "Data length [bytes]", "usb.data_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"URB data length in bytes", HFILL }},
{ &hf_usb_urb_unused_setup_header,
{ "Unused Setup Header",
"usb.unused_setup_header", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_urb_interval,
{ "Interval",
"usb.interval", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_urb_start_frame,
{ "Start frame",
"usb.start_frame", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_urb_copy_of_transfer_flags,
{ "Copy of Transfer Flags",
"usb.copy_of_transfer_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_win32_header_len,
{ "USBPcap pseudoheader length", "usb.usbpcap_header_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_irp_id,
{ "IRP ID", "usb.irp_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_usbd_status,
{ "IRP USBD_STATUS", "usb.usbd_status",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &win32_usbd_status_vals_ext, 0x0,
"USB request status value", HFILL }},
{ &hf_usb_function,
{ "URB Function", "usb.function",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &win32_urb_function_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_info,
{ "IRP information", "usb.irp_info",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_usbpcap_info_reserved,
{ "Reserved", "usb.irp_info.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFE,
NULL, HFILL }},
{ &hf_usb_usbpcap_info_direction,
{ "Direction", "usb.irp_info.direction",
FT_UINT8, BASE_HEX, VALS(win32_usb_info_direction_vals), 0x01,
NULL, HFILL }},
{ &hf_usb_win32_device_address,
{ "Device address", "usb.device_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Windows USB device address", HFILL }},
{ &hf_usb_win32_data_len,
{ "Packet Data Length", "usb.data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_control_stage,
{ "Control transfer stage", "usb.control_stage",
FT_UINT8, BASE_DEC, VALS(usb_control_stage_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_start_frame,
{ "Isochronous transfer start frame", "usb.win32.iso_frame",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_num_packets,
{ "Isochronous transfer number of packets", "usb.win32.iso_num_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_error_count,
{ "Isochronous transfer error count", "usb.win32.iso_error_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_offset,
{ "ISO Data offset", "usb.win32.iso_offset",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_length,
{ "ISO Data length", "usb.win32.iso_data_len",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_win32_iso_status,
{ "ISO USBD status", "usb.win32.iso_status",
FT_UINT32, BASE_HEX | BASE_EXT_STRING, &win32_usbd_status_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bmRequestType,
{ "bmRequestType", "usb.bmRequestType",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_control_response_generic,
{ "CONTROL response data", "usb.control.Response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_request,
{ "bRequest", "usb.setup.bRequest",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &setup_request_names_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_request_unknown_class,
{ "bRequest", "usb.setup.bRequest",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_value,
{ "wValue", "usb.setup.wValue",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_index,
{ "wIndex", "usb.setup.wIndex",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_length,
{ "wLength", "usb.setup.wLength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_device_wFeatureSelector,
{ "wFeatureSelector", "usb.setup.wFeatureSelector",
FT_UINT16, BASE_DEC, VALS(usb_device_feature_selector_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_interface_wFeatureSelector,
{ "wFeatureSelector", "usb.setup.wFeatureSelector",
FT_UINT16, BASE_DEC, VALS(usb_interface_feature_selector_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_endpoint_wFeatureSelector,
{ "wFeatureSelector", "usb.setup.wFeatureSelector",
FT_UINT16, BASE_DEC, VALS(usb_endpoint_feature_selector_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_wInterface,
{ "wInterface", "usb.setup.wInterface",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wEndpoint,
{ "wEndpoint", "usb.setup.wEndpoint",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wStatus,
{ "wStatus", "usb.setup.wStatus",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wFrameNumber,
{ "wFrameNumber", "usb.setup.wFrameNumber",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iso_error_count,
{ "ISO error count", "usb.iso.error_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iso_numdesc,
{ "Number of ISO descriptors", "usb.iso.numdesc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iso_status,
{ "Status", "usb.iso.iso_status",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &usb_urb_status_vals_ext, 0x0,
"ISO descriptor status", HFILL }},
{ &hf_usb_iso_off,
{ "Offset [bytes]", "usb.iso.iso_off",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ISO data offset in bytes starting from the end of the last ISO descriptor", HFILL }},
{ &hf_usb_iso_len,
{ "Length [bytes]", "usb.iso.iso_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ISO data length in bytes", HFILL }},
{ &hf_usb_iso_actual_len,
{ "Actual Length [bytes]", "usb.iso.iso_actual_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ISO data actual length in bytes", HFILL }},
{ &hf_usb_iso_pad,
{ "Padding", "usb.iso.pad",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Padding field of ISO descriptor structure", HFILL }},
{ &hf_usb_iso_data,
{"ISO Data", "usb.iso.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_usb_data_len,
{"Application Data Length", "usb.data.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_usb_capdata,
{"Leftover Capture Data", "usb.capdata",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding added by the USB capture system", HFILL }},
{ &hf_usb_bmRequestType_direction,
{ "Direction", "usb.bmRequestType.direction",
FT_BOOLEAN, 8, TFS(&tfs_bmrequesttype_direction), USB_DIR_IN,
NULL, HFILL }},
{ &hf_usb_bmRequestType_type,
{ "Type", "usb.bmRequestType.type",
FT_UINT8, BASE_HEX, VALS(bmrequesttype_type_vals), USB_TYPE_MASK,
NULL, HFILL }},
{ &hf_usb_bmRequestType_recipient,
{ "Recipient", "usb.bmRequestType.recipient",
FT_UINT8, BASE_HEX, VALS(bmrequesttype_recipient_vals), 0x1f,
NULL, HFILL }},
{ &hf_usb_bDescriptorType,
{ "bDescriptorType", "usb.bDescriptorType",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_get_descriptor_resp_generic,
{ "GET DESCRIPTOR Response data", "usb.getDescriptor.Response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_descriptor_index,
{ "Descriptor Index", "usb.DescriptorIndex",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_language_id,
{ "Language Id", "usb.LanguageId",
FT_UINT16, BASE_HEX|BASE_EXT_STRING,&usb_langid_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bLength,
{ "bLength", "usb.bLength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bcdUSB,
{ "bcdUSB", "usb.bcdUSB",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bDeviceClass,
{ "bDeviceClass", "usb.bDeviceClass",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &usb_class_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bDeviceSubClass,
{ "bDeviceSubClass", "usb.bDeviceSubClass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bDeviceProtocol,
{ "bDeviceProtocol", "usb.bDeviceProtocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bMaxPacketSize0,
{ "bMaxPacketSize0", "usb.bMaxPacketSize0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_idVendor,
{ "idVendor", "usb.idVendor",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &ext_usb_vendors_vals, 0x0,
NULL, HFILL }},
{ &hf_usb_idProduct,
{ "idProduct", "usb.idProduct",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bcdDevice,
{ "bcdDevice", "usb.bcdDevice",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iManufacturer,
{ "iManufacturer", "usb.iManufacturer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iProduct,
{ "iProduct", "usb.iProduct",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iSerialNumber,
{ "iSerialNumber", "usb.iSerialNumber",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bNumConfigurations,
{ "bNumConfigurations", "usb.bNumConfigurations",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wLANGID,
{ "wLANGID", "usb.wLANGID",
FT_UINT16, BASE_HEX|BASE_EXT_STRING,&usb_langid_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bString,
{ "bString", "usb.bString",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceNumber,
{ "bInterfaceNumber", "usb.bInterfaceNumber",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bAlternateSetting,
{ "bAlternateSetting", "usb.bAlternateSetting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bNumEndpoints,
{ "bNumEndpoints", "usb.bNumEndpoints",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceClass,
{ "bInterfaceClass", "usb.bInterfaceClass",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &usb_class_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass_cdc,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &ext_usb_com_subclass_vals, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass_hid,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_hid_subclass_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass_misc,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_misc_subclass_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass_app,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_app_subclass_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_cdc,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_cdc_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_cdc_data,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_cdc_data_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_hid_boot,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_hid_boot_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_app_dfu,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_app_dfu_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_app_irda,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_app_irda_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol_app_usb_test_and_measurement,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &usb_app_usb_test_and_measurement_protocol_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_usb_iInterface,
{ "iInterface", "usb.iInterface",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bEndpointAddress,
{ "bEndpointAddress", "usb.bEndpointAddress",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_configuration_bmAttributes,
{ "Configuration bmAttributes", "usb.configuration.bmAttributes",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bmAttributes,
{ "bmAttributes", "usb.bmAttributes",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bEndpointAttributeTransfer,
{ "Transfertype", "usb.bmAttributes.transfer",
FT_UINT8, BASE_HEX, VALS(usb_bmAttributes_transfer_vals), 0x03,
NULL, HFILL }},
{ &hf_usb_bEndpointAttributeSynchonisation,
{ "Synchronisationtype", "usb.bmAttributes.sync",
FT_UINT8, BASE_HEX, VALS(usb_bmAttributes_sync_vals), 0x0c,
NULL, HFILL }},
{ &hf_usb_bEndpointAttributeBehaviour,
{ "Behaviourtype", "usb.bmAttributes.behaviour",
FT_UINT8, BASE_HEX, VALS(usb_bmAttributes_behaviour_vals), 0x30,
NULL, HFILL }},
{ &hf_usb_wMaxPacketSize,
{ "wMaxPacketSize", "usb.wMaxPacketSize",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wMaxPacketSize_size,
{ "Maximum Packet Size", "usb.wMaxPacketSize.size",
FT_UINT16, BASE_DEC, NULL, 0x3FF,
NULL, HFILL }},
{ &hf_usb_wMaxPacketSize_slots,
{ "Transactions per microframe", "usb.wMaxPacketSize.slots",
FT_UINT16, BASE_DEC, VALS(usb_wMaxPacketSize_slots_vals), (3<<11),
NULL, HFILL }},
{ &hf_usb_bInterval,
{ "bInterval", "usb.bInterval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wTotalLength,
{ "wTotalLength", "usb.wTotalLength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bNumInterfaces,
{ "bNumInterfaces", "usb.bNumInterfaces",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bConfigurationValue,
{ "bConfigurationValue", "usb.bConfigurationValue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iConfiguration,
{ "iConfiguration", "usb.iConfiguration",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_bMaxPower,
{ "bMaxPower", "usb.bMaxPower",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_configuration_legacy10buspowered,
{ "Must be 1", "usb.configuration.legacy10buspowered",
FT_BOOLEAN, 8, TFS(&tfs_mustbeone), 0x80,
"Legacy USB 1.0 bus powered", HFILL }},
{ &hf_usb_configuration_selfpowered,
{ "Self-Powered", "usb.configuration.selfpowered",
FT_BOOLEAN, 8, TFS(&tfs_selfpowered), 0x40,
NULL, HFILL }},
{ &hf_usb_configuration_remotewakeup,
{ "Remote Wakeup", "usb.configuration.remotewakeup",
FT_BOOLEAN, 8, TFS(&tfs_remotewakeup), 0x20,
NULL, HFILL }},
{ &hf_usb_bEndpointAddress_number,
{ "Endpoint Number", "usb.bEndpointAddress.number",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }},
{ &hf_usb_bEndpointAddress_direction,
{ "Direction", "usb.bEndpointAddress.direction",
FT_BOOLEAN, 8, TFS(&tfs_endpoint_direction), 0x80,
NULL, HFILL }},
{ &hf_usb_request_in,
{ "Request in", "usb.request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The request to this packet is in this packet", HFILL }},
{ &hf_usb_time,
{ "Time from request", "usb.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0,
"Time between Request and Response for USB cmds", HFILL }},
{ &hf_usb_response_in,
{ "Response in", "usb.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
"The response to this packet is in this packet", HFILL }},
{ &hf_usb_bFirstInterface,
{ "bFirstInterface", "usb.bFirstInterface",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceCount,
{ "bInterfaceCount",
"usb.bInterfaceCount", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionClass,
{ "bFunctionClass", "usb.bFunctionClass",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &usb_class_vals_ext, 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionSubClass,
{ "bFunctionSubClass",
"usb.bFunctionSubClass", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionProtocol,
{ "bFunctionProtocol", "usb.bFunctionProtocol",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iFunction,
{ "iFunction",
"usb.iFunction", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_data_fragment,
{ "Data Fragment",
"usb.data_fragment", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_src,
{ "Source", "usb.src",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_dst,
{ "Destination", "usb.dst",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_usb_addr,
{ "Source or Destination", "usb.addr",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
}
};
static gint *usb_subtrees[] = {
&ett_usb_hdr,
&ett_usb_setup_hdr,
&ett_usb_isodesc,
&ett_usb_win32_iso_packet,
&ett_usb_endpoint,
&ett_usb_xferflags,
&ett_usb_xferstatus,
&ett_usb_frame,
&ett_usb_frame_flags,
&ett_usb_setup_bmrequesttype,
&ett_usb_usbpcap_info,
&ett_descriptor_device,
&ett_configuration_bmAttributes,
&ett_configuration_bEndpointAddress,
&ett_endpoint_bmAttributes,
&ett_endpoint_wMaxPacketSize
};
static ei_register_info ei[] = {
{ &ei_usb_bLength_even, { "usb.bLength.even", PI_PROTOCOL, PI_WARN, "Invalid STRING DESCRIPTOR Length (must be even)", EXPFILL }},
{ &ei_usb_bLength_too_short, { "usb.bLength.too_short", PI_MALFORMED, PI_ERROR, "Invalid STRING DESCRIPTOR Length (must be 2 or larger)", EXPFILL }},
{ &ei_usb_desc_length_invalid, { "usb.desc_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid descriptor length", EXPFILL }},
{ &ei_usb_invalid_setup, { "usb.setup.invalid", PI_MALFORMED, PI_ERROR, "Only control URBs may contain a setup packet", EXPFILL }}
};
expert_module_t* expert_usb;
proto_usb = proto_register_protocol("USB", "USB", "usb");
proto_register_field_array(proto_usb, hf, array_length(hf));
proto_register_subtree_array(usb_subtrees, array_length(usb_subtrees));
expert_usb = expert_register_protocol(proto_usb);
expert_register_field_array(expert_usb, ei, array_length(ei));
device_to_product_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
device_to_protocol_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
device_to_dissector = register_dissector_table("usb.device", "USB device", proto_usb, FT_UINT32, BASE_HEX);
protocol_to_dissector = register_dissector_table("usb.protocol", "USB protocol", proto_usb, FT_UINT32, BASE_HEX);
product_to_dissector = register_dissector_table("usb.product", "USB product", proto_usb, FT_UINT32, BASE_HEX);
usb_bulk_dissector_table = register_dissector_table("usb.bulk",
"USB bulk endpoint", proto_usb, FT_UINT8, BASE_DEC);
heur_bulk_subdissector_list = register_heur_dissector_list("usb.bulk", proto_usb);
usb_control_dissector_table = register_dissector_table("usb.control",
"USB control endpoint", proto_usb, FT_UINT8, BASE_DEC);
heur_control_subdissector_list = register_heur_dissector_list("usb.control", proto_usb);
usb_interrupt_dissector_table = register_dissector_table("usb.interrupt",
"USB interrupt endpoint", proto_usb, FT_UINT8, BASE_DEC);
heur_interrupt_subdissector_list = register_heur_dissector_list("usb.interrupt", proto_usb);
usb_descriptor_dissector_table = register_dissector_table("usb.descriptor",
"USB descriptor", proto_usb, FT_UINT8, BASE_DEC);
usb_module = prefs_register_protocol(proto_usb, NULL);
prefs_register_bool_preference(usb_module, "try_heuristics",
"Try heuristic sub-dissectors",
"Try to decode a packet using a heuristic sub-dissector before "
"attempting to dissect the packet using the \"usb.bulk\", \"usb.interrupt\" or "
"\"usb.control\" dissector tables.", &try_heuristics);
usb_tap = register_tap("usb");
register_decode_as(&usb_protocol_da);
register_decode_as(&usb_product_da);
register_decode_as(&usb_device_da);
usb_address_type = address_type_dissector_register("AT_USB", "USB Address", usb_addr_to_str, usb_addr_str_len, NULL, NULL, NULL, NULL, NULL);
register_conversation_table(proto_usb, TRUE, usb_conversation_packet, usb_hostlist_packet);
}
void
proto_reg_handoff_usb(void)
{
dissector_handle_t linux_usb_handle;
dissector_handle_t linux_usb_mmapped_handle;
dissector_handle_t win32_usb_handle;
dissector_handle_t freebsd_usb_handle;
linux_usb_handle = create_dissector_handle(dissect_linux_usb, proto_usb);
linux_usb_mmapped_handle = create_dissector_handle(dissect_linux_usb_mmapped,
proto_usb);
win32_usb_handle = create_dissector_handle(dissect_win32_usb, proto_usb);
freebsd_usb_handle = create_dissector_handle(dissect_freebsd_usb, proto_usb);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX, linux_usb_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX_MMAPPED, linux_usb_mmapped_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USBPCAP, win32_usb_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_FREEBSD, freebsd_usb_handle);
}
