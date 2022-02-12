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
usb_conv_info->transactions = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_usb, usb_conv_info);
}
return usb_conv_info;
}
static conversation_t *
get_usb_conversation(packet_info *pinfo,
address *src_addr, address *dst_addr,
guint32 src_endpoint, guint32 dst_endpoint)
{
conversation_t *conversation;
conversation = find_conversation(pinfo->fd->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
if (conversation) {
return conversation;
}
conversation = conversation_new(pinfo->fd->num,
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
static int
dissect_usb_setup_clear_feature_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
usb_trans_info_t *usb_trans_info _U_,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
proto_item *nitem = NULL;
int old_offset = offset;
guint32 protocol;
const gchar *description;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "DEVICE QUALIFIER DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
k_frame_number = pinfo->fd->num;
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
usb_trans_info_t *usb_trans_info _U_,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
proto_item *nitem = NULL;
int old_offset = offset;
guint32 protocol;
const gchar *description;
guint16 vendor_id;
guint32 product;
guint16 product_id;
guint8 *field_description;
gint field_description_length;
header_field_info *hfi;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "DEVICE DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
proto_tree_add_item(tree, hf_usb_idVendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
vendor_id = tvb_get_letohs(tvb, offset);
usb_conv_info->deviceVendor = vendor_id;
offset += 2;
nitem = proto_tree_add_item(tree, hf_usb_idProduct, tvb, offset, 2, ENC_LITTLE_ENDIAN);
product_id = tvb_get_letohs(tvb, offset);
usb_conv_info->deviceProduct = product_id;
product = vendor_id << 16 | product_id;
hfi = proto_registrar_get_nth(hf_usb_idProduct);
field_description_length = (gint)strlen(hfi->name) + 14;
field_description = (guint8 *)wmem_alloc(wmem_packet_scope(), field_description_length);
g_strlcpy(field_description, hfi->name, field_description_length);
g_strlcat(field_description, ": %s (0x%04x)", field_description_length);
proto_item_set_text(nitem, field_description,
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
k_frame_number = pinfo->fd->num;
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
usb_trans_info_t *usb_trans_info,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
guint8 len;
proto_item *len_item;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "STRING DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
if (!usb_trans_info->u.get_descriptor.index) {
while(len>(offset-old_offset)) {
proto_tree_add_item(tree, hf_usb_wLANGID, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
}
} else {
proto_tree_add_item(tree, hf_usb_bString, tvb, offset, len-2, ENC_UTF_16 | ENC_LITTLE_ENDIAN);
offset += len-2;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_usb_interface_descriptor(packet_info *pinfo, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_trans_info_t *usb_trans_info,
usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
const char *class_str = NULL;
int old_offset = offset;
guint8 len;
guint8 interface_num;
guint8 alt_setting;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "INTERFACE DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
if (!pinfo->fd->flags.visited && (alt_setting == 0)) {
usb_trans_info->interface_info = get_usb_iface_conv_info(pinfo, interface_num);
usb_trans_info->interface_info->interfaceClass = tvb_get_guint8(tvb, offset);
usb_trans_info->interface_info->interfaceSubclass = tvb_get_guint8(tvb, offset+1);
usb_trans_info->interface_info->interfaceProtocol = tvb_get_guint8(tvb, offset+2);
usb_trans_info->interface_info->deviceVendor = usb_conv_info->deviceVendor;
usb_trans_info->interface_info->deviceProduct = usb_conv_info->deviceProduct;
}
offset += 1;
switch (usb_conv_info->interfaceClass) {
case IF_CLASS_COMMUNICATIONS:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_cdc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case IF_CLASS_HID:
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass_hid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
usb_trans_info_t *usb_trans_info,
usb_conv_info_t *usb_conv_info _U_)
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
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "ENDPOINT DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += 2;
endpoint = tvb_get_guint8(tvb, offset)&0x0f;
dissect_usb_endpoint_address(tree, tvb, offset);
offset += 1;
if ((!pinfo->fd->flags.visited)&&usb_trans_info->interface_info) {
conversation_t *conversation;
if (pinfo->destport == NO_ENDPOINT) {
static address tmp_addr;
static usb_address_t usb_addr;
usb_addr.device = ((const usb_address_t *)(pinfo->src.data))->device;
usb_addr.endpoint = GUINT32_TO_LE(endpoint);
SET_ADDRESS(&tmp_addr, AT_USB, USB_ADDR_LEN, (char *)&usb_addr);
conversation = get_usb_conversation(pinfo, &tmp_addr, &pinfo->dst, usb_addr.endpoint, pinfo->destport);
} else {
static address tmp_addr;
static usb_address_t usb_addr;
usb_addr.device = ((const usb_address_t *)(pinfo->dst.data))->device;
usb_addr.endpoint = GUINT32_TO_LE(endpoint);
SET_ADDRESS(&tmp_addr, AT_USB, USB_ADDR_LEN, (char *)&usb_addr);
conversation = get_usb_conversation(pinfo, &pinfo->src, &tmp_addr, pinfo->srcport, usb_addr.endpoint);
}
conversation_add_proto_data(conversation, proto_usb, usb_trans_info->interface_info);
}
ep_type = ENDPOINT_TYPE(tvb_get_guint8(tvb, offset));
ep_attrib_item = proto_tree_add_item(tree, hf_usb_bmAttributes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
ep_attrib_tree = proto_item_add_subtree(ep_attrib_item, ett_endpoint_bmAttributes);
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeTransfer, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeSynchonisation, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_attrib_tree, hf_usb_bEndpointAttributeBehaviour, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
usb_trans_info_t *usb_trans_info _U_,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "INTERFACE ASSOCIATION DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
usb_trans_info_t *usb_trans_info _U_,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *tree;
guint8 bLength;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "UNKNOWN DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
bLength = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset, NULL);
offset += bLength;
proto_item_set_len(item, bLength);
return offset;
}
static int
dissect_usb_configuration_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset,
usb_trans_info_t *usb_trans_info,
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
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->interfaceProtocol = IF_PROTOCOL_UNKNOWN;
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "CONFIGURATION DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
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
remaining_tvb = tvb_length_remaining(tvb, offset);
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
if (!truncation_expected) {
THROW(ReportedBoundsError);
}
break;
}
next_type = tvb_get_guint8(tvb, offset+1);
switch(next_type) {
case USB_DT_INTERFACE:
offset = dissect_usb_interface_descriptor(pinfo, parent_tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_ENDPOINT:
offset = dissect_usb_endpoint_descriptor(pinfo, parent_tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_INTERFACE_ASSOCIATION:
offset = dissect_usb_interface_assn_descriptor(pinfo, parent_tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
default:
next_tvb = tvb_new_subset(tvb, offset, next_len, next_len);
if (dissector_try_uint_new(usb_descriptor_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent_tree, TRUE, usb_conv_info)) {
offset += next_len;
} else {
offset = dissect_usb_unknown_descriptor(pinfo, parent_tree, tvb, offset, usb_trans_info, usb_conv_info);
}
break;
}
}
proto_item_set_len(item, offset-old_offset);
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->interfaceProtocol = IF_PROTOCOL_UNKNOWN;
return offset;
}
static int
dissect_usb_setup_get_descriptor_request(packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
usb_trans_info_t *usb_trans_info;
usb_trans_info = usb_conv_info->usb_trans_info;
proto_tree_add_item(tree, hf_usb_descriptor_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.index = tvb_get_guint8(tvb, offset);
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
case USB_DT_DEVICE:
offset = dissect_usb_device_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_CONFIG:
offset = dissect_usb_configuration_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_STRING:
offset = dissect_usb_string_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_INTERFACE:
offset = dissect_usb_interface_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_ENDPOINT:
offset = dissect_usb_endpoint_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_DEVICE_QUALIFIER:
offset = dissect_usb_device_qualifier_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
case USB_DT_RPIPE:
if (usb_conv_info->interfaceClass == IF_CLASS_HID ||
usb_conv_info->interfaceClass == IF_CLASS_UNKNOWN) {
offset = dissect_usb_hid_get_report_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
}
default:
proto_tree_add_text(tree, tvb, offset, -1, "GET DESCRIPTOR data (unknown descriptor type %u)", usb_trans_info->u.get_descriptor.type);
offset = tvb_length(tvb);
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
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wFeatureSelector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
dissect_usb_setup_set_interface_request(packet_info *pinfo _U_, proto_tree *tree,
tvbuff_t *tvb, int offset,
usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bAlternateSetting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
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
proto_tree_add_item(tree, hf_usb_wInterface, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
static gint
try_dissect_next_protocol(proto_tree *tree, proto_tree *parent, tvbuff_t *next_tvb, gint offset, packet_info *pinfo,
usb_conv_info_t *usb_conv_info, gint type_2, guint8 urb_type,
device_product_data_t *device_product_data, device_protocol_data_t *device_protocol_data)
{
wmem_tree_key_t key[4];
guint32 k_frame_number;
guint32 k_device_address;
guint32 k_bus_id;
heur_dtbl_entry_t *hdtbl_entry;
if (tvb_length(next_tvb) > 0 &&
!dissector_try_uint_new(device_to_dissector, (guint32) (usb_conv_info->bus_id << 16 | usb_conv_info->device_address), next_tvb, pinfo, parent, FALSE, usb_conv_info)) {
k_frame_number = pinfo->fd->num;
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
if (!device_protocol_data)
device_protocol_data = (device_protocol_data_t *)wmem_tree_lookup32_array_le(device_to_protocol_table, key);
if (device_protocol_data && device_protocol_data->bus_id == usb_conv_info->bus_id &&
device_protocol_data->device_address == usb_conv_info->device_address &&
dissector_try_uint_new(protocol_to_dissector, (guint32) device_protocol_data->protocol, next_tvb, pinfo, parent, FALSE, usb_conv_info)) {
offset += tvb_length(next_tvb);
} else {
if (!device_product_data)
device_product_data = (device_product_data_t *)wmem_tree_lookup32_array_le(device_to_product_table, key);
if (device_product_data && device_product_data->bus_id == usb_conv_info->bus_id &&
device_product_data->device_address == usb_conv_info->device_address &&
dissector_try_uint_new(product_to_dissector, (guint32) (device_product_data->vendor << 16 | device_product_data->product),
next_tvb, pinfo, parent, FALSE, usb_conv_info)) {
offset += tvb_length(next_tvb);
} else {
heur_dissector_list_t heur_subdissector_list;
dissector_table_t usb_dissector_table;
switch(usb_conv_info->transfer_type) {
case URB_BULK:
heur_subdissector_list = heur_bulk_subdissector_list;
usb_dissector_table = usb_bulk_dissector_table;
break;
case URB_INTERRUPT:
heur_subdissector_list = heur_interrupt_subdissector_list;
usb_dissector_table = usb_interrupt_dissector_table;
break;
case URB_CONTROL: {
usb_trans_info_t *usb_trans_info = usb_conv_info->usb_trans_info;
gboolean is_request = usb_conv_info->is_request;
heur_subdissector_list = heur_control_subdissector_list;
usb_dissector_table = usb_control_dissector_table;
if (usb_trans_info && ((is_request && usb_conv_info->is_setup && type_2 == RQT_SETUP_TYPE_CLASS) ||
(!is_request && USB_TYPE(usb_trans_info->setup.requesttype) == RQT_SETUP_TYPE_CLASS))) {
usb_tap_data_t *tap_data;
proto_item *sub_item;
if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_INTERFACE) {
guint8 interface_num = usb_trans_info->setup.wIndex & 0xff;
usb_conv_info = get_usb_iface_conv_info(pinfo, interface_num);
usb_conv_info->usb_trans_info = usb_trans_info;
} else if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_ENDPOINT) {
static address endpoint_addr;
gint endpoint;
static usb_address_t src_addr, dst_addr;
guint32 src_endpoint, dst_endpoint;
conversation_t *conversation;
endpoint = usb_trans_info->setup.wIndex & 0x0f;
if (is_request) {
dst_addr.endpoint = dst_endpoint = GUINT32_TO_LE(endpoint);
SET_ADDRESS(&endpoint_addr, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
conversation = get_usb_conversation(pinfo, &pinfo->src, &endpoint_addr, pinfo->srcport, dst_endpoint);
} else {
src_addr.endpoint = src_endpoint = GUINT32_TO_LE(endpoint);
SET_ADDRESS(&endpoint_addr, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
conversation = get_usb_conversation(pinfo, &endpoint_addr, &pinfo->dst, src_endpoint, pinfo->destport);
}
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
}
tap_data = wmem_new(wmem_packet_scope(), usb_tap_data_t);
tap_data->urb_type = urb_type;
tap_data->transfer_type = (guint8)(usb_conv_info->transfer_type);
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_trans_info;
tap_queue_packet(usb_tap, pinfo, tap_data);
sub_item = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, next_tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(sub_item);
}
}
break;
default:
heur_subdissector_list = NULL;
usb_dissector_table = NULL;
}
if (try_heuristics && dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, parent, &hdtbl_entry, usb_conv_info)) {
offset += tvb_length(next_tvb);
} else if (usb_dissector_table &&
dissector_try_uint_new(usb_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent, TRUE, usb_conv_info)) {
offset += tvb_length(next_tvb);
}
}
}
} else {
offset += tvb_length(next_tvb);
}
return offset;
}
static int
dissect_usb_bmrequesttype(proto_tree *parent_tree, tvbuff_t *tvb, int offset, int *type)
{
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_usb_bmRequestType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_usb_setup_bmrequesttype);
*type = USB_TYPE(tvb_get_guint8(tvb, offset));
proto_tree_add_item(tree, hf_usb_bmRequestType_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_recipient, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return ++offset;
}
static void
dissect_linux_usb_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint *bus_id, guint16 *device_address)
{
guint8 transfer_type;
guint8 endpoint_number;
guint8 transfer_type_and_direction;
guint8 type;
guint8 flag[2];
proto_tree_add_item(tree, hf_usb_urb_id, tvb, 0, 8, ENC_HOST_ENDIAN);
type = tvb_get_guint8(tvb, 8);
proto_tree_add_uint_format_value(tree, hf_usb_urb_type, tvb, 8, 1,
type, "%s ('%c')", val_to_str(type, usb_urb_type_vals, "Unknown %d"),
g_ascii_isprint(type) ? type : '.');
proto_tree_add_item(tree, hf_usb_transfer_type, tvb, 9, 1, ENC_NA);
transfer_type = tvb_get_guint8(tvb, 9);
endpoint_number = tvb_get_guint8(tvb, 10);
transfer_type_and_direction = (transfer_type & 0x7F) | (endpoint_number & 0x80);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(transfer_type_and_direction, usb_transfer_type_and_direction_vals, "Unknown type %x"));
proto_tree_add_bitmask(tree, tvb, 10, hf_usb_endpoint_number, ett_usb_endpoint, usb_endpoint_fields, ENC_NA);
proto_tree_add_item(tree, hf_usb_device_address, tvb, 11, 1, ENC_NA);
*device_address = (guint16)tvb_get_guint8(tvb, 11);
proto_tree_add_item(tree, hf_usb_bus_id, tvb, 12, 2, ENC_HOST_ENDIAN);
tvb_memcpy(tvb, bus_id, 12, 2);
flag[0] = tvb_get_guint8(tvb, 14);
flag[1] = '\0';
if (flag[0] == 0) {
proto_tree_add_string(tree, hf_usb_setup_flag, tvb, 14, 1, "relevant (0)");
} else {
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
static void
dissect_win32_usb_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint *bus_id, guint16 *device_address)
{
guint8 transfer_type;
guint8 endpoint_number;
guint8 transfer_type_and_direction;
proto_tree_add_item(tree, hf_usb_win32_header_len, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_irp_id, tvb, 2, 8, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_usbd_status, tvb, 10, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_function, tvb, 14, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 16, hf_usb_info, ett_usb_usbpcap_info, usb_usbpcap_info_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bus_id, tvb, 17, 2, ENC_LITTLE_ENDIAN);
*bus_id = tvb_get_letohs(tvb, 17);
proto_tree_add_item(tree, hf_usb_win32_device_address, tvb, 19, 2, ENC_LITTLE_ENDIAN);
*device_address = tvb_get_letohs(tvb, 19);
transfer_type = tvb_get_guint8(tvb, 22);
endpoint_number = tvb_get_guint8(tvb, 21);
transfer_type_and_direction = (transfer_type & 0x7F) | (endpoint_number & 0x80);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(transfer_type_and_direction, usb_transfer_type_and_direction_vals, "Unknown type %x"));
proto_tree_add_bitmask(tree, tvb, 21, hf_usb_endpoint_number, ett_usb_endpoint, usb_endpoint_fields, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_transfer_type, tvb, 22, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_win32_data_len, tvb, 23, 4, ENC_LITTLE_ENDIAN);
switch (transfer_type)
{
case URB_ISOCHRONOUS:
break;
case URB_INTERRUPT:
break;
case URB_CONTROL:
proto_tree_add_item(tree, hf_usb_control_stage, tvb, 27, 1, ENC_LITTLE_ENDIAN);
break;
case URB_BULK:
break;
}
}
static void
dissect_usb_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent,
guint8 header_info)
{
gint offset = 0;
gint new_offset;
int type, endpoint, endpoint_with_dir;
gint type_2 = 0;
guint8 urb_type, usbpcap_control_stage = 0;
guint8 setup_flag;
guint16 hdr_len;
guint32 win32_data_len = 0;
proto_tree *tree;
proto_item *item;
static usb_address_t src_addr, dst_addr;
gboolean is_request;
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info = NULL;
conversation_t *conversation;
usb_tap_data_t *tap_data;
guint bus_id = 0;
guint16 device_address;
tvbuff_t *next_tvb = NULL;
tvbuff_t *setup_tvb = NULL;
device_product_data_t *device_product_data = NULL;
device_protocol_data_t *device_protocol_data = NULL;
wmem_tree_key_t key[4];
guint32 k_frame_number;
guint32 k_device_address;
guint32 k_bus_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USB");
if (header_info & USB_HEADER_IS_LINUX) {
proto_item *ti;
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, 0,
(header_info & USB_HEADER_IS_64_BYTES) ? 64 : 48, "USB URB");
tree = proto_item_add_subtree(ti, usb_hdr);
dissect_linux_usb_pseudo_header(tvb, pinfo, tree, &bus_id, &device_address);
urb_type = tvb_get_guint8(tvb, 8);
type = tvb_get_guint8(tvb, 9);
endpoint_with_dir = tvb_get_guint8(tvb, 10);
setup_flag = tvb_get_guint8(tvb, 14);
offset += 40;
} else if (header_info & USB_HEADER_IS_USBPCAP) {
guint8 tmp_val8;
proto_item *ti;
tvb_memcpy(tvb, (guint8 *)&hdr_len, 0, 2);
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, 0, hdr_len, "USB URB");
tree = proto_item_add_subtree(ti, usb_hdr);
dissect_win32_usb_pseudo_header(tvb, pinfo, tree, &bus_id, &device_address);
hdr_len = tvb_get_letohs(tvb, 0);
tmp_val8 = tvb_get_guint8(tvb, 16);
if (tmp_val8 & 0x01) {
urb_type = URB_COMPLETE;
} else {
urb_type = URB_SUBMIT;
}
type = tvb_get_guint8(tvb, 22);
endpoint_with_dir = tvb_get_guint8(tvb, 21);
win32_data_len = tvb_get_letohl(tvb, 23);
usbpcap_control_stage = tvb_get_guint8(tvb, 27);
if (usbpcap_control_stage == USB_CONTROL_STAGE_SETUP) {
setup_flag = 0;
} else {
setup_flag = 0xFF;
}
if (type == URB_ISOCHRONOUS) {
offset += 27;
} else {
offset += hdr_len;
}
} else {
return;
}
endpoint = endpoint_with_dir & (~URB_TRANSFER_IN);
is_request = (urb_type == URB_SUBMIT) ? TRUE : FALSE;
if (is_request) {
src_addr.device = 0xffffffff;
src_addr.endpoint = NO_ENDPOINT;
dst_addr.device = GUINT16_TO_LE(device_address);
dst_addr.endpoint = GUINT32_TO_LE(endpoint);
} else {
src_addr.device = GUINT16_TO_LE(device_address);
src_addr.endpoint = GUINT32_TO_LE(endpoint);
dst_addr.device = 0xffffffff;
dst_addr.endpoint = NO_ENDPOINT;
}
SET_ADDRESS(&pinfo->net_src, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
SET_ADDRESS(&pinfo->src, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
SET_ADDRESS(&pinfo->net_dst, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
SET_ADDRESS(&pinfo->dst, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
pinfo->ptype = PT_USB;
pinfo->srcport = src_addr.endpoint;
pinfo->destport = dst_addr.endpoint;
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, pinfo->srcport, pinfo->destport);
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->bus_id = bus_id;
usb_conv_info->device_address = device_address;
usb_conv_info->endpoint = endpoint;
usb_conv_info->transfer_type = type;
usb_conv_info->is_request = is_request;
usb_conv_info->is_setup = (setup_flag == 0x00);
usb_conv_info->setup_requesttype = 0;
if (endpoint_with_dir & URB_TRANSFER_IN) {
usb_conv_info->direction = P2P_DIR_RECV;
} else {
usb_conv_info->direction = P2P_DIR_SENT;
}
if (is_request) {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32(usb_conv_info->transactions, pinfo->fd->num);
if (!usb_trans_info) {
usb_trans_info = wmem_new0(wmem_file_scope(), usb_trans_info_t);
usb_trans_info->request_in = pinfo->fd->num;
usb_trans_info->req_time = pinfo->fd->abs_ts;
usb_trans_info->header_info = header_info;
wmem_tree_insert32(usb_conv_info->transactions, pinfo->fd->num, usb_trans_info);
}
usb_conv_info->usb_trans_info = usb_trans_info;
if (usb_trans_info->response_in) {
proto_item *ti;
ti = proto_tree_add_uint(tree, hf_usb_response_in, tvb, 0, 0, usb_trans_info->response_in);
PROTO_ITEM_SET_GENERATED(ti);
}
} else {
if (pinfo->fd->flags.visited) {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32(usb_conv_info->transactions, pinfo->fd->num);
} else {
usb_trans_info = (usb_trans_info_t *)wmem_tree_lookup32_le(usb_conv_info->transactions, pinfo->fd->num);
if (usb_trans_info) {
usb_trans_info->response_in = pinfo->fd->num;
wmem_tree_insert32(usb_conv_info->transactions, pinfo->fd->num, usb_trans_info);
}
}
usb_conv_info->usb_trans_info = usb_trans_info;
if (usb_trans_info && usb_trans_info->request_in) {
proto_item *ti;
nstime_t t, deltat;
ti = proto_tree_add_uint(tree, hf_usb_request_in, tvb, 0, 0, usb_trans_info->request_in);
PROTO_ITEM_SET_GENERATED(ti);
t = pinfo->fd->abs_ts;
nstime_delta(&deltat, &t, &usb_trans_info->req_time);
ti = proto_tree_add_time(tree, hf_usb_time, tvb, 0, 0, &deltat);
PROTO_ITEM_SET_GENERATED(ti);
}
}
tap_data = wmem_new(wmem_packet_scope(), usb_tap_data_t);
tap_data->urb_type = urb_type;
tap_data->transfer_type = (guint8)(usb_conv_info->transfer_type);
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_trans_info;
if (usb_conv_info->transfer_type != URB_CONTROL) {
tap_queue_packet(usb_tap, pinfo, tap_data);
}
switch(usb_conv_info->transfer_type) {
case URB_BULK:
case URB_INTERRUPT:
item = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(item);
if (header_info & USB_HEADER_IS_LINUX) {
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
}
if (header_info & USB_HEADER_IS_64_BYTES) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
case URB_CONTROL:
{
const usb_setup_dissector_table_t *tmp;
usb_setup_dissector dissector;
proto_item *ti = NULL;
proto_tree *setup_tree = NULL;
if (is_request) {
if (usb_conv_info->is_setup) {
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, offset, 8, "URB setup");
setup_tree = proto_item_add_subtree(ti, usb_setup_hdr);
usb_trans_info->setup.requesttype = tvb_get_guint8(tvb, offset);
usb_conv_info->setup_requesttype = tvb_get_guint8(tvb, offset);
offset = dissect_usb_bmrequesttype(setup_tree, tvb, offset, &type_2);
usb_trans_info->setup.request = tvb_get_guint8(tvb, offset);
usb_trans_info->setup.wValue = tvb_get_letohs(tvb, offset+1);
usb_trans_info->setup.wIndex = tvb_get_letohs(tvb, offset+3);
usb_trans_info->setup.wLength = tvb_get_letohs(tvb, offset+5);
if (type_2 != RQT_SETUP_TYPE_CLASS) {
tap_queue_packet(usb_tap, pinfo, tap_data);
}
switch (type_2) {
case RQT_SETUP_TYPE_STANDARD:
proto_tree_add_item(setup_tree, hf_usb_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
if (dissector) {
offset = dissector(pinfo, setup_tree, tvb, offset, usb_conv_info);
} else {
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
default:
proto_tree_add_item(setup_tree, hf_usb_request_unknown_class, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (header_info & (USB_HEADER_IS_LINUX | USB_HEADER_IS_64_BYTES)) {
setup_tvb = tvb_new_composite();
next_tvb = tvb_new_subset(tvb, offset - 7, 7, 7);
tvb_composite_append(setup_tvb, next_tvb);
}
}
} else {
if (header_info & USB_HEADER_IS_LINUX) {
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
}
}
if ((header_info & USB_HEADER_IS_LINUX) &&
(header_info & USB_HEADER_IS_64_BYTES)) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
if (type_2 != RQT_SETUP_TYPE_STANDARD) {
if (setup_tvb) {
if (tvb_reported_length_remaining(tvb, offset) != 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
tvb_composite_append(setup_tvb, next_tvb);
tvb_composite_finalize(setup_tvb);
next_tvb = tvb_new_child_real_data(tvb, (const guint8 *) tvb_memdup(pinfo->pool, setup_tvb, 0, tvb_length(setup_tvb)), tvb_length(setup_tvb), tvb_length(setup_tvb));
add_new_data_source(pinfo, next_tvb, "Linux USB Control");
proto_tree_add_item(setup_tree, hf_usb_data_fragment, tvb, offset, -1, ENC_NA);
}
else
tvb_composite_finalize(setup_tvb);
}
else
next_tvb = tvb_new_subset_remaining(tvb, offset - 7);
offset = try_dissect_next_protocol(tree, parent, next_tvb, offset, pinfo, usb_conv_info, type_2, urb_type, NULL, NULL);
}
} else {
if (header_info & USB_HEADER_IS_LINUX) {
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
}
if ((header_info & USB_HEADER_IS_LINUX) &&
(header_info & USB_HEADER_IS_64_BYTES)) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
if (usb_trans_info) {
if ((header_info & USB_HEADER_IS_USBPCAP) &&
(usbpcap_control_stage == USB_CONTROL_STAGE_STATUS)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Status",
val_to_str_ext(usb_conv_info->usb_trans_info->setup.request,
&setup_request_names_vals_ext, "Unknown type %x"));
return;
}
type_2 = USB_TYPE(usb_trans_info->setup.requesttype);
switch (type_2) {
case RQT_SETUP_TYPE_STANDARD:
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
if (dissector) {
offset = dissector(pinfo, parent, tvb, offset, usb_conv_info);
} else {
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_text(parent, tvb, offset, -1, "CONTROL response data");
offset += tvb_length_remaining(tvb, offset);
}
}
break;
default:
if (tvb_reported_length_remaining(tvb, offset) != 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
new_offset = try_dissect_next_protocol(tree, parent, next_tvb, offset, pinfo, usb_conv_info, type_2, urb_type, NULL, NULL);
if (new_offset > offset)
offset = new_offset;
}
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_text(parent, tvb, offset, -1, "CONTROL response data");
offset += tvb_length_remaining(tvb, offset);
}
break;
}
} else {
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_text(parent, tvb, offset, -1, "CONTROL response data");
offset += tvb_length_remaining(tvb, offset);
}
}
}
}
break;
case URB_ISOCHRONOUS:
if (header_info & USB_HEADER_IS_LINUX) {
guint32 iso_numdesc = 0;
proto_item *tii;
tii = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, offset, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(tii);
if (usb_conv_info->is_setup) {
proto_item *ti;
proto_tree *setup_tree;
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, offset, 8, "URB setup");
setup_tree = proto_item_add_subtree(ti, usb_setup_hdr);
offset = dissect_usb_bmrequesttype(setup_tree, tvb, offset, &type_2);
proto_tree_add_item(setup_tree, hf_usb_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
guint32 val32;
tvb_memcpy(tvb, (guint8 *)&val32, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_error_count, tvb, offset, 4, val32);
offset += 4;
tvb_memcpy(tvb, (guint8 *)&iso_numdesc, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_numdesc, tvb, offset, 4, iso_numdesc);
offset += 4;
}
if (header_info & USB_HEADER_IS_64_BYTES)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
if (usb_conv_info->is_setup) {
proto_tree *urb_tree;
guint32 i;
unsigned int data_base;
guint32 iso_status;
guint32 iso_off;
guint32 iso_len;
guint32 iso_pad;
data_base = offset + iso_numdesc * 16;
urb_tree = tree;
for (i = 0; i != iso_numdesc; i++) {
tvb_memcpy(tvb, (guint8 *)&iso_status, offset, 4);
tvb_memcpy(tvb, (guint8 *)&iso_off, offset+4, 4);
tvb_memcpy(tvb, (guint8 *)&iso_len, offset+8, 4);
if (parent) {
proto_item *ti;
if (iso_len > 0) {
ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, offset,
16, "USB isodesc %u [%s] (%u bytes)", i,
val_to_str_ext(iso_status, &usb_urb_status_vals_ext, "Error %d"), iso_len);
} else {
ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, offset,
16, "USB isodesc %u [%s]", i, val_to_str_ext(iso_status, &usb_urb_status_vals_ext, "Error %d"));
}
tree = proto_item_add_subtree(ti, usb_isodesc);
}
proto_tree_add_int(tree, hf_usb_iso_status, tvb, offset, 4, iso_status);
offset += 4;
proto_tree_add_uint(tree, hf_usb_iso_off, tvb, offset, 4, iso_off);
offset += 4;
proto_tree_add_uint(tree, hf_usb_iso_len, tvb, offset, 4, iso_len);
offset += 4;
if (!iso_status && iso_len && data_base + iso_off + iso_len <= tvb_length(tvb))
proto_tree_add_item(tree, hf_usb_iso_data, tvb, data_base + iso_off, iso_len, ENC_NA);
tvb_memcpy(tvb, (guint8 *)&iso_pad, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_pad, tvb, offset, 4, iso_pad);
offset += 4;
}
}
} else if (header_info & USB_HEADER_IS_USBPCAP) {
guint32 num_packets;
guint32 i;
guint32 data_start_offset;
proto_tree *urb_tree;
data_start_offset = offset - 27 + hdr_len;
urb_tree = parent;
proto_tree_add_item(tree, hf_usb_win32_iso_start_frame, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
num_packets = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_usb_win32_iso_num_packets, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_win32_iso_error_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
for (i = 0; i < num_packets; i++)
{
guint32 this_offset;
guint32 next_offset;
guint32 iso_len;
proto_item *ti;
if (parent) {
ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, offset,
12, "USB isochronous packet");
tree = proto_item_add_subtree(ti, usb_win32_iso_packet);
}
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
if (!((is_request && !(endpoint_with_dir & URB_TRANSFER_IN)) ||
(!is_request && (endpoint_with_dir & URB_TRANSFER_IN)))) {
iso_len = 0;
}
proto_tree_add_item(tree, hf_usb_win32_iso_offset, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(tree, hf_usb_win32_iso_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (!(endpoint_with_dir & URB_TRANSFER_IN)) {
proto_item_append_text(ti, " (not used)");
} else {
if (is_request) {
proto_item_append_text(ti, " (irrelevant)");
} else {
proto_item_append_text(ti, " (relevant)");
iso_len = tvb_get_letohl(tvb, offset);
}
}
offset += 4;
ti = proto_tree_add_item(tree, hf_usb_win32_iso_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (urb_type == URB_SUBMIT) {
proto_item_append_text(ti, " (irrelevant)");
} else {
proto_item_append_text(ti, " (relevant)");
}
offset += 4;
if (iso_len && data_start_offset + this_offset + iso_len <= tvb_length(tvb))
proto_tree_add_item(tree, hf_usb_iso_data, tvb, (gint)(data_start_offset + this_offset), (gint)iso_len, ENC_NA);
}
if ((is_request && !(endpoint_with_dir & URB_TRANSFER_IN)) ||
(!is_request && (endpoint_with_dir & URB_TRANSFER_IN))) {
offset += win32_data_len;
}
}
break;
default:
if (usb_conv_info->is_setup) {
proto_item *ti;
proto_tree *setup_tree;
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, offset, 8, "URB setup");
setup_tree = proto_item_add_subtree(ti, usb_setup_hdr);
offset = dissect_usb_bmrequesttype(setup_tree, tvb, offset, &type_2);
proto_tree_add_item(setup_tree, hf_usb_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
if (header_info & USB_HEADER_IS_LINUX) {
proto_tree_add_item(tree, hf_usb_urb_unused_setup_header, tvb, offset, 8, ENC_NA);
offset += 8;
}
}
if ((header_info & USB_HEADER_IS_LINUX) &&
(header_info & USB_HEADER_IS_64_BYTES)) {
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
}
break;
}
k_frame_number = pinfo->fd->num;
k_device_address = device_address;
k_bus_id = bus_id;
key[0].length = 1;
key[0].key = &k_device_address;
key[1].length = 1;
key[1].key = &k_bus_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_product_data = (device_product_data_t *) wmem_tree_lookup32_array_le(device_to_product_table, key);
if (device_product_data && device_product_data->bus_id == bus_id &&
device_product_data->device_address == device_address) {
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_VENDOR_ID, GUINT_TO_POINTER((guint)device_product_data->vendor));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_PRODUCT_ID, GUINT_TO_POINTER((guint)device_product_data->product));
} else {
device_product_data = NULL;
}
device_protocol_data = (device_protocol_data_t *) wmem_tree_lookup32_array_le(device_to_protocol_table, key);
if (device_protocol_data && device_protocol_data->bus_id == bus_id &&
device_protocol_data->device_address == device_address) {
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_CLASS, GUINT_TO_POINTER(device_protocol_data->protocol >> 16));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_SUBCLASS, GUINT_TO_POINTER((device_protocol_data->protocol >> 8) & 0xFF));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_PROTOCOL, GUINT_TO_POINTER(device_protocol_data->protocol & 0xFF));
usb_conv_info->device_protocol = device_protocol_data->protocol;
} else {
device_protocol_data = NULL;
}
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_BUS_ID, GUINT_TO_POINTER(bus_id));
p_add_proto_data(pinfo->pool, pinfo, proto_usb, USB_DEVICE_ADDRESS, GUINT_TO_POINTER((guint)device_address));
if (tvb_length_remaining(tvb, offset) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset = try_dissect_next_protocol(tree, parent, next_tvb, offset, pinfo, usb_conv_info, type_2, urb_type, device_product_data, device_protocol_data);
}
if (tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(parent, hf_usb_capdata, tvb, offset, -1, ENC_NA);
}
}
static void
dissect_linux_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_IS_LINUX);
}
static void
dissect_linux_usb_mmapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_IS_LINUX | USB_HEADER_IS_64_BYTES);
}
static void
dissect_win32_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent)
{
dissect_usb_common(tvb, pinfo, parent, USB_HEADER_IS_USBPCAP);
}
void
proto_register_usb(void)
{
module_t *usb_module;
static hf_register_info hf[] = {
{ &hf_usb_urb_id,
{ "URB id", "usb.urb_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_type,
{ "URB type", "usb.urb_type",
FT_UINT8, BASE_DEC, VALS(usb_urb_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_transfer_type,
{ "URB transfer type", "usb.transfer_type",
FT_UINT8, BASE_HEX, VALS(usb_transfer_type_vals), 0x0,
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
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_length,
{ "wLength", "usb.setup.wLength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wFeatureSelector,
{ "wFeatureSelector", "usb.setup.wFeatureSelector",
FT_UINT16, BASE_DEC, VALS(usb_feature_selector_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_wInterface,
{ "wInterface", "usb.setup.wInterface",
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
{ &hf_usb_bInterfaceSubClass_app,
{ "bInterfaceProtocol", "usb.bInterfaceSubClass",
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
};
static gint *usb_subtrees[] = {
&usb_hdr,
&usb_setup_hdr,
&usb_isodesc,
&usb_win32_iso_packet,
&ett_usb_endpoint,
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
};
expert_module_t* expert_usb;
expert_usb = expert_register_protocol(proto_usb);
expert_register_field_array(expert_usb, ei, array_length(ei));
device_to_product_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
device_to_protocol_table = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
device_to_dissector = register_dissector_table("usb.device", "USB device", FT_UINT32, BASE_HEX);
protocol_to_dissector = register_dissector_table("usb.protocol", "USB protocol", FT_UINT32, BASE_HEX);
product_to_dissector = register_dissector_table("usb.product", "USB product", FT_UINT32, BASE_HEX);
proto_usb = proto_register_protocol("USB", "USB", "usb");
proto_register_field_array(proto_usb, hf, array_length(hf));
proto_register_subtree_array(usb_subtrees, array_length(usb_subtrees));
linux_usb_handle = register_dissector("usb", dissect_linux_usb, proto_usb);
usb_bulk_dissector_table = register_dissector_table("usb.bulk",
"USB bulk endpoint", FT_UINT8, BASE_DEC);
register_heur_dissector_list("usb.bulk", &heur_bulk_subdissector_list);
usb_control_dissector_table = register_dissector_table("usb.control",
"USB control endpoint", FT_UINT8, BASE_DEC);
register_heur_dissector_list("usb.control", &heur_control_subdissector_list);
usb_interrupt_dissector_table = register_dissector_table("usb.interrupt",
"USB interrupt endpoint", FT_UINT8, BASE_DEC);
register_heur_dissector_list("usb.interrupt", &heur_interrupt_subdissector_list);
usb_descriptor_dissector_table = register_dissector_table("usb.descriptor",
"USB descriptor", FT_UINT8, BASE_DEC);
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
}
void
proto_reg_handoff_usb(void)
{
dissector_handle_t linux_usb_mmapped_handle;
dissector_handle_t win32_usb_handle;
linux_usb_mmapped_handle = create_dissector_handle(dissect_linux_usb_mmapped,
proto_usb);
win32_usb_handle = create_dissector_handle(dissect_win32_usb, proto_usb);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX, linux_usb_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX_MMAPPED, linux_usb_mmapped_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USBPCAP, win32_usb_handle);
}
