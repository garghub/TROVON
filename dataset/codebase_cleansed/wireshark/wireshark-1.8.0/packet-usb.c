static usb_conv_info_t *
get_usb_conv_info(conversation_t *conversation)
{
usb_conv_info_t *usb_conv_info;
usb_conv_info = conversation_get_proto_data(conversation, proto_usb);
if(!usb_conv_info){
usb_conv_info = se_alloc0(sizeof(usb_conv_info_t));
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
usb_conv_info->transactions = se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "usb transactions");
conversation_add_proto_data(conversation, proto_usb, usb_conv_info);
}
return usb_conv_info;
}
static conversation_t *
get_usb_conversation(packet_info *pinfo, address *src_addr, address *dst_addr, guint32 src_endpoint, guint32 dst_endpoint)
{
conversation_t *conversation;
conversation = find_conversation(pinfo->fd->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
if(conversation){
return conversation;
}
conversation = conversation_new(pinfo->fd->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
return conversation;
}
static int
dissect_usb_setup_clear_feature_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_clear_feature_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_get_configuration_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bConfigurationValue, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
void dissect_usb_descriptor_header(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_usb_bLength, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bDescriptorType, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
}
static int
dissect_usb_device_qualifier_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "DEVICE QUALIFIER DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
dissect_usb_descriptor_header(tree, tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_usb_bcdUSB, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_bDeviceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bMaxPacketSize0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumConfigurations, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += 1;
if(item){
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static int
dissect_usb_device_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "DEVICE DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
dissect_usb_descriptor_header(tree, tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_usb_bcdUSB, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_bDeviceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDeviceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bMaxPacketSize0, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_idVendor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_idProduct, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_bcdDevice, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_iManufacturer, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iProduct, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iSerialNumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumConfigurations, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(item){
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static int
dissect_usb_string_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint8 len;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "STRING DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset);
offset += 2;
if(!usb_trans_info->u.get_descriptor.index){
while(len>(offset-old_offset)){
proto_tree_add_item(tree, hf_usb_wLANGID, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
}
} else {
char *str;
str = tvb_get_ephemeral_unicode_string(tvb, offset, len-2, ENC_LITTLE_ENDIAN);
proto_tree_add_string(tree, hf_usb_bString, tvb, offset, len-2, str);
offset += len-2;
}
if(item){
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static int
dissect_usb_interface_descriptor(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint8 len;
guint8 interface_num;
guint8 alt_setting;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "INTERFACE DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset);
offset += 2;
interface_num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_bInterfaceNumber, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
alt_setting = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_usb_bAlternateSetting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bNumEndpoints, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_bInterfaceClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_conv_info->interfaceClass = tvb_get_guint8(tvb, offset);
if (!pinfo->fd->flags.visited && (alt_setting == 0)) {
conversation_t *conversation;
guint32 if_port;
usb_trans_info->interface_info = se_alloc0(sizeof(usb_conv_info_t));
usb_trans_info->interface_info->interfaceClass = tvb_get_guint8(tvb, offset);
usb_trans_info->interface_info->interfaceSubclass = tvb_get_guint8(tvb, offset+1);
usb_trans_info->interface_info->transactions = se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "usb transactions");
if_port = htolel(INTERFACE_PORT | interface_num);
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, if_port, pinfo->destport);
conversation_add_proto_data(conversation, proto_usb, usb_trans_info->interface_info);
}
offset += 1;
proto_tree_add_item(tree, hf_usb_bInterfaceSubClass, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_conv_info->interfaceSubclass = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_usb_bInterfaceProtocol, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usb_iInterface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if(item){
proto_item_set_len(item, len);
}
if (offset != old_offset + len) {
}
offset = old_offset + len;
return offset;
}
void dissect_usb_endpoint_address(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *endpoint_item = NULL;
proto_tree *endpoint_tree = NULL;
guint8 endpoint;
if(tree){
endpoint_item = proto_tree_add_item(tree, hf_usb_bEndpointAddress, tvb, offset, 1, ENC_LITTLE_ENDIAN);
endpoint_tree = proto_item_add_subtree(endpoint_item, ett_configuration_bEndpointAddress);
}
endpoint = tvb_get_guint8(tvb, offset)&0x0f;
proto_tree_add_item(endpoint_tree, hf_usb_bEndpointAddress_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(endpoint_item, " %s", (tvb_get_guint8(tvb, offset)&0x80)?"IN":"OUT");
proto_tree_add_item(endpoint_tree, hf_usb_bEndpointAddress_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(endpoint_item, " Endpoint:%d", endpoint);
}
static int
dissect_usb_endpoint_descriptor(packet_info *pinfo, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
proto_item *ep_attrib_item = NULL;
proto_tree *ep_attrib_tree = NULL;
proto_item *ep_pktsize_item;
proto_tree *ep_pktsize_tree;
int old_offset = offset;
guint8 endpoint;
guint8 ep_type;
guint8 len;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "ENDPOINT DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
len = tvb_get_guint8(tvb, offset);
dissect_usb_descriptor_header(tree, tvb, offset);
offset += 2;
endpoint = tvb_get_guint8(tvb, offset)&0x0f;
dissect_usb_endpoint_address(tree, tvb, offset);
offset += 1;
if((!pinfo->fd->flags.visited)&&usb_trans_info->interface_info){
conversation_t *conversation;
if(pinfo->destport==NO_ENDPOINT){
static address tmp_addr;
static usb_address_t usb_addr;
usb_addr.device = ((usb_address_t *)(pinfo->src.data))->device;
usb_addr.endpoint = htolel(endpoint);
SET_ADDRESS(&tmp_addr, AT_USB, USB_ADDR_LEN, (char *)&usb_addr);
conversation = get_usb_conversation(pinfo, &tmp_addr, &pinfo->dst, usb_addr.endpoint, pinfo->destport);
} else {
static address tmp_addr;
static usb_address_t usb_addr;
usb_addr.device = ((usb_address_t *)(pinfo->dst.data))->device;
usb_addr.endpoint = htolel(endpoint);
SET_ADDRESS(&tmp_addr, AT_USB, USB_ADDR_LEN, (char *)&usb_addr);
conversation = get_usb_conversation(pinfo, &pinfo->src, &tmp_addr, pinfo->srcport, usb_addr.endpoint);
}
conversation_add_proto_data(conversation, proto_usb, usb_trans_info->interface_info);
}
ep_type = ENDPOINT_TYPE(tvb_get_guint8(tvb, offset));
if (tree) {
ep_attrib_item = proto_tree_add_item(tree, hf_usb_bmAttributes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
ep_attrib_tree = proto_item_add_subtree(ep_attrib_item, ett_endpoint_bmAttributes);
}
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
if(item){
proto_item_set_len(item, len);
}
if (offset != old_offset + len) {
}
offset = old_offset + len;
return offset;
}
static int
dissect_usb_interface_assn_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree,
tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_,
usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "INTERFACE ASSOCIATION DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
dissect_usb_descriptor_header(tree, tvb, offset);
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
if(item){
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static int
dissect_usb_unknown_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint8 bLength;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "UNKNOWN DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
proto_tree_add_item(tree, hf_usb_bLength, tvb, offset, 1, ENC_LITTLE_ENDIAN);
bLength = tvb_get_guint8(tvb, offset);
offset += 1;
if (bLength < 3) {
if(item){
proto_item_set_len(item, offset-old_offset);
}
item = proto_tree_add_text(parent_tree, tvb, offset - 1, 1,
"Invalid bLength: %u", bLength);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Invalid bLength: %u", bLength);
return offset;
}
proto_tree_add_item(tree, hf_usb_bDescriptorType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
offset += bLength - 2;
if(item){
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static int
dissect_usb_configuration_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint16 len;
proto_item *flags_item = NULL;
proto_tree *flags_tree = NULL;
guint8 flags;
proto_item *power_item;
guint8 power;
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, -1, "CONFIGURATION DESCRIPTOR");
tree = proto_item_add_subtree(item, ett_descriptor_device);
}
dissect_usb_descriptor_header(tree, tvb, offset);
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
if(tree){
flags_item = proto_tree_add_item(tree, hf_usb_configuration_bmAttributes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_configuration_bmAttributes);
}
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
while(len>(old_offset-offset)){
guint8 next_type;
tvbuff_t *next_tvb = NULL;
if(tvb_length_remaining(tvb, offset)<2){
break;
}
next_type = tvb_get_guint8(tvb, offset+1);
switch(next_type){
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
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (dissector_try_uint(usb_descriptor_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent_tree)){
offset += tvb_get_guint8(next_tvb, 0);
} else {
offset = dissect_usb_unknown_descriptor(pinfo, parent_tree, tvb, offset, usb_trans_info, usb_conv_info);
}
break;
}
}
if(item){
proto_item_set_len(item, offset-old_offset);
}
usb_conv_info->interfaceClass = IF_CLASS_UNKNOWN;
usb_conv_info->interfaceSubclass = IF_SUBCLASS_UNKNOWN;
return offset;
}
static int
dissect_usb_setup_get_descriptor_request(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_descriptor_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.index = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_usb_bDescriptorType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.type = tvb_get_guint8(tvb, offset);
offset += 1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(usb_trans_info->u.get_descriptor.type, descriptor_type_vals, "Unknown type %u"));
}
proto_tree_add_item(tree, hf_usb_language_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_get_descriptor_response(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info)
{
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(usb_trans_info->u.get_descriptor.type, descriptor_type_vals, "Unknown type %u"));
}
switch(usb_trans_info->u.get_descriptor.type){
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
if (usb_conv_info->interfaceClass == IF_CLASS_HID) {
offset = dissect_usb_hid_get_report_descriptor(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info);
break;
}
default:
proto_tree_add_text(tree, tvb, offset, -1, "GET DESCRIPTOR data (unknown descriptor type %u)",usb_trans_info->u.get_descriptor.type);
offset = tvb_length(tvb);
break;
}
return offset;
}
static int
dissect_usb_setup_get_interface_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_get_interface_response(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_bAlternateSetting, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_usb_setup_get_status_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_get_status_response(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wStatus, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_setup_set_address_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_set_address_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_configuration_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_set_configuration_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_feature_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_set_feature_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_set_interface_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_set_interface_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
return offset;
}
static int
dissect_usb_setup_synch_frame_request(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
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
dissect_usb_setup_synch_frame_response(packet_info *pinfo _U_, proto_tree *tree _U_, tvbuff_t *tvb _U_, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_tree_add_item(tree, hf_usb_wFrameNumber, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_bmrequesttype(proto_tree *parent_tree, tvbuff_t *tvb, int offset,
int *type)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
if(parent_tree){
item = proto_tree_add_item(parent_tree, hf_usb_bmRequestType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tree = proto_item_add_subtree(item, ett_usb_setup_bmrequesttype);
}
*type = USB_TYPE(tvb_get_guint8(tvb, offset));
proto_tree_add_item(tree, hf_usb_bmRequestType_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_bmRequestType_recipient, tvb, offset, 1, ENC_LITTLE_ENDIAN);
return ++offset;
}
static void
dissect_linux_usb_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 transfer_type;
guint8 endpoint_number;
guint8 transfer_type_and_direction;
guint8 type, flag;
guint16 val16;
guint32 val32;
guint64 val64;
tvb_memcpy(tvb, (guint8 *)&val64, 0, 8);
proto_tree_add_uint64(tree, hf_usb_urb_id, tvb, 0, 8, val64);
type = tvb_get_guint8(tvb, 8);
proto_tree_add_uint_format_value(tree, hf_usb_urb_type, tvb, 8, 1,
type, "%s ('%c')", val_to_str(type, usb_urb_type_vals, "Unknown %d"),
isprint(type) ? type : '.');
proto_tree_add_item(tree, hf_usb_transfer_type, tvb, 9, 1, ENC_BIG_ENDIAN);
if (check_col(pinfo->cinfo, COL_INFO)) {
transfer_type = tvb_get_guint8(tvb, 9);
endpoint_number = tvb_get_guint8(tvb, 10);
transfer_type_and_direction = (transfer_type & 0x7F) | (endpoint_number & 0x80);
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(transfer_type_and_direction, usb_transfer_type_and_direction_vals, "Unknown type %x"));
}
proto_tree_add_bitmask(tree, tvb, 10, hf_usb_endpoint_number, ett_usb_endpoint, usb_endpoint_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usb_device_address, tvb, 11, 1, ENC_BIG_ENDIAN);
tvb_memcpy(tvb, (guint8 *)&val16, 12, 2);
proto_tree_add_uint(tree, hf_usb_bus_id, tvb, 12, 2, val16);
flag = tvb_get_guint8(tvb, 14);
if (flag == 0) {
proto_tree_add_string(tree, hf_usb_setup_flag, tvb, 14, 1, "relevant (0)");
} else {
proto_tree_add_string_format_value(tree, hf_usb_setup_flag, tvb,
14, 1, &flag, "not relevant ('%c')", isprint(flag) ? flag: '.');
}
flag = tvb_get_guint8(tvb, 15);
if (flag == 0) {
proto_tree_add_string(tree, hf_usb_data_flag, tvb, 15, 1, "present (0)");
} else {
proto_tree_add_string_format_value(tree, hf_usb_data_flag, tvb,
15, 1, &flag, "not present ('%c')", isprint(flag) ? flag : '.');
}
tvb_memcpy(tvb, (guint8 *)&val64, 16, 8);
proto_tree_add_uint64(tree, hf_usb_urb_ts_sec, tvb, 16, 8, val64);
tvb_memcpy(tvb, (guint8 *)&val32, 24, 4);
proto_tree_add_uint(tree, hf_usb_urb_ts_usec, tvb, 24, 4, val32);
tvb_memcpy(tvb, (guint8 *)&val32, 28, 4);
proto_tree_add_int(tree, hf_usb_urb_status, tvb, 28, 4, val32);
tvb_memcpy(tvb, (guint8 *)&val32, 32, 4);
proto_tree_add_uint(tree, hf_usb_urb_len, tvb, 32, 4, val32);
tvb_memcpy(tvb, (guint8 *)&val32, 36, 4);
proto_tree_add_uint(tree, hf_usb_urb_data_len, tvb, 36, 4, val32);
}
static int
dissect_linux_usb_pseudo_header_ext(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_,
proto_tree *tree _U_)
{
guint32 ndesc;
offset += 4;
offset += 4;
offset += 4;
tvb_memcpy(tvb, (guint8 *)&ndesc, offset, 4);
offset += 4;
offset += ndesc*16;
return offset;
}
static void
dissect_linux_usb_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent,
gboolean header_len_64_bytes)
{
unsigned int offset = 0;
int type, endpoint;
guint8 setup_flag;
proto_tree *tree = NULL;
guint32 tmp_addr;
static usb_address_t src_addr, dst_addr;
guint32 src_endpoint, dst_endpoint;
gboolean is_request = FALSE;
usb_conv_info_t *usb_conv_info = NULL;
usb_trans_info_t *usb_trans_info = NULL;
conversation_t *conversation;
usb_tap_data_t *tap_data = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USB");
if (parent) {
proto_item *ti = NULL;
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, 0,
header_len_64_bytes ? 64 : 48, "USB URB");
tree = proto_item_add_subtree(ti, usb_hdr);
}
dissect_linux_usb_pseudo_header(tvb, pinfo, tree);
is_request = (tvb_get_guint8(tvb, 8) == URB_SUBMIT) ? TRUE : FALSE;
type = tvb_get_guint8(tvb, 9);
endpoint = tvb_get_guint8(tvb, 10) & (~URB_TRANSFER_IN);
tmp_addr = tvb_get_guint8(tvb, 11);
setup_flag = tvb_get_guint8(tvb, 14);
offset += 40;
if (is_request) {
src_addr.device = 0xffffffff;
src_addr.endpoint = src_endpoint = NO_ENDPOINT;
dst_addr.device = htolel(tmp_addr);
dst_addr.endpoint = dst_endpoint = htolel(endpoint);
} else {
src_addr.device = htolel(tmp_addr);
src_addr.endpoint = src_endpoint = htolel(endpoint);
dst_addr.device = 0xffffffff;
dst_addr.endpoint = dst_endpoint = NO_ENDPOINT;
}
SET_ADDRESS(&pinfo->net_src, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
SET_ADDRESS(&pinfo->src, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
SET_ADDRESS(&pinfo->net_dst, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
SET_ADDRESS(&pinfo->dst, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
pinfo->ptype = PT_USB;
pinfo->srcport = src_endpoint;
pinfo->destport = dst_endpoint;
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, pinfo->srcport, pinfo->destport);
usb_conv_info = get_usb_conv_info(conversation);
pinfo->usb_conv_info = usb_conv_info;
if(is_request){
usb_trans_info = se_tree_lookup32(usb_conv_info->transactions, pinfo->fd->num);
if(!usb_trans_info){
usb_trans_info = se_alloc0(sizeof(usb_trans_info_t));
usb_trans_info->request_in = pinfo->fd->num;
usb_trans_info->req_time = pinfo->fd->abs_ts;
usb_trans_info->header_len_64 = header_len_64_bytes;
se_tree_insert32(usb_conv_info->transactions, pinfo->fd->num, usb_trans_info);
}
usb_conv_info->usb_trans_info = usb_trans_info;
if(usb_trans_info->response_in){
proto_item *ti;
ti = proto_tree_add_uint(tree, hf_usb_response_in, tvb, 0, 0, usb_trans_info->response_in);
PROTO_ITEM_SET_GENERATED(ti);
}
} else {
if(pinfo->fd->flags.visited){
usb_trans_info = se_tree_lookup32(usb_conv_info->transactions, pinfo->fd->num);
} else {
usb_trans_info = se_tree_lookup32_le(usb_conv_info->transactions, pinfo->fd->num);
if(usb_trans_info){
usb_trans_info->response_in = pinfo->fd->num;
se_tree_insert32(usb_conv_info->transactions, pinfo->fd->num, usb_trans_info);
}
}
usb_conv_info->usb_trans_info = usb_trans_info;
if(usb_trans_info && usb_trans_info->request_in){
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
tap_data = ep_alloc(sizeof(usb_tap_data_t));
tap_data->urb_type = tvb_get_guint8(tvb, 8);
tap_data->transfer_type = (guint8)type;
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_trans_info;
if (type != URB_CONTROL) {
tap_queue_packet(usb_tap, pinfo, tap_data);
}
switch(type){
case URB_BULK:
{
proto_item *item;
item = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(item);
offset += 8;
if (header_len_64_bytes)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
if(tvb_reported_length_remaining(tvb, offset)){
tvbuff_t *next_tvb;
pinfo->usb_conv_info = usb_conv_info;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_heuristics && dissector_try_heuristic(heur_bulk_subdissector_list, next_tvb, pinfo, parent)) {
return;
}
else if(dissector_try_uint(usb_bulk_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent)){
return;
}
}
}
break;
case URB_INTERRUPT:
{
proto_item *item;
item = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(item);
offset += 8;
if (header_len_64_bytes)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
if(tvb_reported_length_remaining(tvb, offset)){
tvbuff_t *next_tvb;
pinfo->usb_conv_info = usb_conv_info;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_heuristics && dissector_try_heuristic(heur_interrupt_subdissector_list, next_tvb, pinfo, parent)) {
return;
}
else if(dissector_try_uint(usb_interrupt_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent)){
return;
}
}
}
break;
case URB_CONTROL:
{
const usb_setup_dissector_table_t *tmp;
usb_setup_dissector dissector;
proto_item *ti = NULL;
proto_tree *setup_tree = NULL;
int type_2;
if(is_request){
if (setup_flag == 0) {
tvbuff_t *next_tvb;
ti = proto_tree_add_protocol_format(parent, proto_usb, tvb, offset, 8, "URB setup");
setup_tree = proto_item_add_subtree(ti, usb_setup_hdr);
usb_trans_info->setup.requesttype = tvb_get_guint8(tvb, offset);
offset = dissect_usb_bmrequesttype(setup_tree, tvb, offset, &type_2);
usb_trans_info->setup.request = tvb_get_guint8(tvb, offset);
usb_trans_info->setup.wValue = tvb_get_letohs(tvb, offset+1);
usb_trans_info->setup.wIndex = tvb_get_letohs(tvb, offset+3);
if (type_2 != RQT_SETUP_TYPE_CLASS) {
tap_queue_packet(usb_tap, pinfo, tap_data);
}
switch (type_2) {
case RQT_SETUP_TYPE_STANDARD:
proto_tree_add_item(setup_tree, hf_usb_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Request",
val_to_str(usb_trans_info->setup.request, setup_request_names_vals, "Unknown type %x"));
}
dissector = NULL;
for(tmp = setup_request_dissectors;tmp->dissector;tmp++){
if (tmp->request == usb_trans_info->setup.request){
dissector = tmp->dissector;
break;
}
}
if(dissector){
offset = dissector(pinfo, setup_tree, tvb, offset, usb_trans_info, usb_conv_info);
} else {
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case RQT_SETUP_TYPE_CLASS:
if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_INTERFACE) {
guint16 interface_num = usb_trans_info->setup.wIndex & 0xff;
guint32 if_port = htolel(INTERFACE_PORT | interface_num);
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, pinfo->srcport, if_port);
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
pinfo->usb_conv_info = usb_conv_info;
} else if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_ENDPOINT) {
static address endpoint_addr;
endpoint = usb_trans_info->setup.wIndex & 0x0f;
dst_addr.endpoint = dst_endpoint = htolel(endpoint);
SET_ADDRESS(&endpoint_addr, AT_USB, USB_ADDR_LEN, (char *)&dst_addr);
conversation = get_usb_conversation(pinfo, &pinfo->src, &endpoint_addr, pinfo->srcport, dst_endpoint);
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
pinfo->usb_conv_info = usb_conv_info;
}
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_trans_info;
tap_queue_packet(usb_tap, pinfo, tap_data);
ti = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(ti);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_heuristics && dissector_try_heuristic(heur_control_subdissector_list, next_tvb, pinfo, setup_tree)) {
return;
}
if(dissector_try_uint(usb_control_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, setup_tree)){
return;
}
proto_tree_add_item(setup_tree, hf_usb_request_unknown_class, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(setup_tree, hf_usb_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(setup_tree, hf_usb_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
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
}
} else {
offset += 8;
}
if (header_len_64_bytes)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
if (tvb_reported_length_remaining(tvb, offset) != 0) {
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_heuristics && dissector_try_heuristic(heur_control_subdissector_list, next_tvb, pinfo, parent)) {
return;
}
if(dissector_try_uint(usb_control_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent)){
return;
}
}
} else {
tvbuff_t *next_tvb;
offset += 8;
if (usb_trans_info) {
if (USB_TYPE(usb_trans_info->setup.requesttype) == RQT_SETUP_TYPE_CLASS) {
if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_INTERFACE) {
guint32 if_port = htolel(INTERFACE_PORT | (usb_trans_info->setup.wIndex & 0xff));
conversation = get_usb_conversation(pinfo, &pinfo->src, &pinfo->dst, if_port, pinfo->destport);
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
pinfo->usb_conv_info = usb_conv_info;
} else if (USB_RECIPIENT(usb_trans_info->setup.requesttype) == RQT_SETUP_RECIPIENT_ENDPOINT) {
static address endpoint_addr;
endpoint = usb_trans_info->setup.wIndex & 0x0f;
src_addr.endpoint = src_endpoint = htolel(endpoint);
SET_ADDRESS(&endpoint_addr, AT_USB, USB_ADDR_LEN, (char *)&src_addr);
conversation = get_usb_conversation(pinfo, &endpoint_addr, &pinfo->dst, src_endpoint, pinfo->destport);
usb_conv_info = get_usb_conv_info(conversation);
usb_conv_info->usb_trans_info = usb_trans_info;
pinfo->usb_conv_info = usb_conv_info;
}
}
}
tap_data->conv_info = usb_conv_info;
tap_data->trans_info = usb_trans_info;
tap_queue_packet(usb_tap, pinfo, tap_data);
ti = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, 0, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(ti);
if (header_len_64_bytes)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
if(usb_trans_info){
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_heuristics && dissector_try_heuristic(heur_control_subdissector_list, next_tvb, pinfo, parent)) {
return;
}
if(dissector_try_uint(usb_control_dissector_table, usb_conv_info->interfaceClass, next_tvb, pinfo, parent)){
return;
}
type_2 = USB_TYPE(usb_trans_info->setup.requesttype);
switch (type_2) {
case RQT_SETUP_TYPE_STANDARD:
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Response",
val_to_str(usb_conv_info->usb_trans_info->setup.request,
setup_request_names_vals, "Unknown type %x"));
}
dissector = NULL;
for(tmp = setup_response_dissectors;tmp->dissector;tmp++){
if (tmp->request == usb_conv_info->usb_trans_info->setup.request){
dissector = tmp->dissector;
break;
}
}
if(dissector){
offset = dissector(pinfo, parent, tvb, offset, usb_conv_info->usb_trans_info, usb_conv_info);
} else {
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_text(parent, tvb, offset, -1, "CONTROL response data");
offset += tvb_length_remaining(tvb, offset);
}
}
break;
default:
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
{
guint32 iso_numdesc = 0;
proto_item *ti = NULL;
ti = proto_tree_add_uint(tree, hf_usb_bInterfaceClass, tvb, offset, 0, usb_conv_info->interfaceClass);
PROTO_ITEM_SET_GENERATED(ti);
if (setup_flag == 0) {
proto_tree *setup_tree = NULL;
int type_2;
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
if (header_len_64_bytes) {
guint32 ndesc;
offset += 4;
offset += 4;
offset += 4;
tvb_memcpy(tvb, (guint8 *)&ndesc, offset, 4);
offset += 4;
}
if (setup_flag != 0) {
proto_tree *urb_tree = NULL;
guint32 i;
unsigned int data_base;
guint32 iso_status;
guint32 iso_off;
guint32 iso_len;
guint32 iso_pad;
data_base = offset + iso_numdesc * 16;
urb_tree = tree;
for (i = 0; i != iso_numdesc; i++) {
if (parent) {
proto_item *ti = NULL;
ti = proto_tree_add_protocol_format(urb_tree, proto_usb, tvb, offset,
16, "USB isodesc %u", i);
tree = proto_item_add_subtree(ti, usb_isodesc);
}
tvb_memcpy(tvb, (guint8 *)&iso_status, offset, 4);
proto_tree_add_int(tree, hf_usb_iso_status, tvb, offset, 4, iso_status);
offset += 4;
tvb_memcpy(tvb, (guint8 *)&iso_off, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_off, tvb, offset, 4, iso_off);
offset += 4;
tvb_memcpy(tvb, (guint8 *)&iso_len, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_len, tvb, offset, 4, iso_len);
offset += 4;
if (!iso_status && iso_len && data_base + iso_off + iso_len <= tvb_length(tvb))
proto_tree_add_item(tree, hf_usb_iso_data, tvb, data_base + iso_off, iso_len, ENC_NA);
tvb_memcpy(tvb, (guint8 *)&iso_pad, offset, 4);
proto_tree_add_uint(tree, hf_usb_iso_pad, tvb, offset, 4, iso_pad);
offset += 4;
}
}
}
break;
default:
if (setup_flag == 0) {
proto_item *ti;
proto_tree *setup_tree;
int type_2;
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
offset += 8;
}
if (header_len_64_bytes)
offset = dissect_linux_usb_pseudo_header_ext(tvb, offset, pinfo, tree);
break;
}
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_item(parent, hf_usb_capdata, tvb, offset, -1, ENC_NA);
}
}
static void
dissect_linux_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent)
{
dissect_linux_usb_common(tvb, pinfo, parent, FALSE);
}
static void
dissect_linux_usb_mmapped(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent)
{
dissect_linux_usb_common(tvb, pinfo, parent, TRUE);
}
void
proto_register_usb(void)
{
module_t *usb_module;
static hf_register_info hf[] = {
{ &hf_usb_urb_id,
{ "URB id", "usb.urb_id", FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_type,
{ "URB type", "usb.urb_type", FT_UINT8, BASE_DEC,
VALS(usb_urb_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_transfer_type,
{ "URB transfer type", "usb.transfer_type", FT_UINT8, BASE_HEX,
VALS(usb_transfer_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_endpoint_number,
{ "Endpoint", "usb.endpoint_number", FT_UINT8, BASE_HEX, NULL, 0x0,
"USB endpoint number", HFILL }},
{ &hf_usb_endpoint_direction,
{ "Direction", "usb.endpoint_number.direction", FT_UINT8, BASE_DEC,
VALS(usb_endpoint_direction_vals), 0x80,
"USB endpoint direction", HFILL }},
{ &hf_usb_endpoint_number_value,
{ "Endpoint value", "usb.endpoint_number.endpoint", FT_UINT8, BASE_DEC,
NULL, 0x7F,
"USB endpoint value", HFILL }},
{ &hf_usb_device_address,
{ "Device", "usb.device_address", FT_UINT8, BASE_DEC, NULL, 0x0,
"USB device address", HFILL }},
{ &hf_usb_bus_id,
{ "URB bus id", "usb.bus_id", FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_setup_flag,
{ "Device setup request", "usb.setup_flag", FT_STRING, BASE_NONE,
NULL, 0x0,
"USB device setup request is relevant (0) or not", HFILL }},
{ &hf_usb_data_flag,
{ "Data", "usb.data_flag", FT_STRING, BASE_NONE,
NULL, 0x0,
"USB data is present (0) or not", HFILL }},
{ &hf_usb_urb_ts_sec,
{ "URB sec", "usb.urb_ts_sec", FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_ts_usec,
{ "URB usec", "usb.urb_ts_usec", FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_urb_status,
{ "URB status", "usb.urb_status", FT_INT32, BASE_DEC,
VALS(usb_urb_status_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_urb_len,
{ "URB length [bytes]", "usb.urb_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"URB length in bytes", HFILL }},
{ &hf_usb_urb_data_len,
{ "Data length [bytes]", "usb.data_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"URB data length in bytes", HFILL }},
{ &hf_usb_bmRequestType,
{ "bmRequestType", "usb.bmRequestType", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_request,
{ "bRequest", "usb.setup.bRequest", FT_UINT8, BASE_DEC, VALS(setup_request_names_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_request_unknown_class,
{ "bRequest", "usb.setup.bRequest", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_value,
{ "wValue", "usb.setup.wValue", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_index,
{ "wIndex", "usb.setup.wIndex", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_length,
{ "wLength", "usb.setup.wLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_wFeatureSelector,
{ "wFeatureSelector", "usb.setup.wFeatureSelector", FT_UINT16, BASE_DEC,
VALS(usb_feature_selector_vals), 0x0, NULL, HFILL }},
{ &hf_usb_wInterface,
{ "wInterface", "usb.setup.wInterface", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_wStatus,
{ "wStatus", "usb.setup.wStatus", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_wFrameNumber,
{ "wFrameNumber", "usb.setup.wFrameNumber", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iso_error_count,
{ "ISO error count", "usb.iso.error_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iso_numdesc,
{ "Number of ISO descriptors", "usb.iso.numdesc", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_iso_status,
{ "Status", "usb.iso.iso_status", FT_INT32, BASE_DEC,
VALS(usb_urb_status_vals), 0x0,
"ISO descriptor status", HFILL }},
{ &hf_usb_iso_off,
{ "Offset [bytes]", "usb.iso.iso_off", FT_UINT32, BASE_DEC, NULL, 0x0,
"ISO data offset in bytes starting from the end of the last ISO descriptor", HFILL }},
{ &hf_usb_iso_len,
{ "Length [bytes]", "usb.iso.iso_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"ISO data length in bytes", HFILL }},
{ &hf_usb_iso_pad,
{ "Padding", "usb.iso._pad", FT_UINT32, BASE_HEX, NULL, 0x0,
"Padding field of ISO descriptor structure", HFILL }},
{ &hf_usb_iso_data,
{"ISO Data", "usb.iso.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_data_len,
{"Application Data Length", "usb.data.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_capdata,
{"Leftover Capture Data", "usb.capdata",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Padding added by the USB capture system", HFILL }},
{ &hf_usb_bmRequestType_direction,
{ "Direction", "usb.bmRequestType.direction", FT_BOOLEAN, 8,
TFS(&tfs_bmrequesttype_direction), USB_DIR_IN, NULL, HFILL }},
{ &hf_usb_bmRequestType_type,
{ "Type", "usb.bmRequestType.type", FT_UINT8, BASE_HEX,
VALS(bmrequesttype_type_vals), USB_TYPE_MASK, NULL, HFILL }},
{ &hf_usb_bmRequestType_recipient,
{ "Recipient", "usb.bmRequestType.recipient", FT_UINT8, BASE_HEX,
VALS(bmrequesttype_recipient_vals), 0x1f, NULL, HFILL }},
{ &hf_usb_bDescriptorType,
{ "bDescriptorType", "usb.bDescriptorType", FT_UINT8, BASE_DEC,
VALS(descriptor_type_vals), 0x0, NULL, HFILL }},
{ &hf_usb_descriptor_index,
{ "Descriptor Index", "usb.DescriptorIndex", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_language_id,
{ "Language Id", "usb.LanguageId", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&usb_langid_vals_ext, 0x0, NULL, HFILL }},
{ &hf_usb_bLength,
{ "bLength", "usb.bLength", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bcdUSB,
{ "bcdUSB", "usb.bcdUSB", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bDeviceClass,
{ "bDeviceClass", "usb.bDeviceClass", FT_UINT8, BASE_HEX,
VALS(usb_class_vals), 0x0, NULL, HFILL }},
{ &hf_usb_bDeviceSubClass,
{ "bDeviceSubClass", "usb.bDeviceSubClass", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bDeviceProtocol,
{ "bDeviceProtocol", "usb.bDeviceProtocol", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bMaxPacketSize0,
{ "bMaxPacketSize0", "usb.bMaxPacketSize0", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_idVendor,
{ "idVendor", "usb.idVendor", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_idProduct,
{ "idProduct", "usb.idProduct", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bcdDevice,
{ "bcdDevice", "usb.bcdDevice", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iManufacturer,
{ "iManufacturer", "usb.iManufacturer", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iProduct,
{ "iProduct", "usb.iProduct", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iSerialNumber,
{ "iSerialNumber", "usb.iSerialNumber", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bNumConfigurations,
{ "bNumConfigurations", "usb.bNumConfigurations", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_wLANGID,
{ "wLANGID", "usb.wLANGID", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&usb_langid_vals_ext, 0x0, NULL, HFILL }},
{ &hf_usb_bString,
{ "bString", "usb.bString", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceNumber,
{ "bInterfaceNumber", "usb.bInterfaceNumber", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bAlternateSetting,
{ "bAlternateSetting","usb.bAlternateSetting", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bNumEndpoints,
{ "bNumEndpoints","usb.bNumEndpoints", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceClass,
{ "bInterfaceClass", "usb.bInterfaceClass", FT_UINT8, BASE_HEX,
VALS(usb_class_vals), 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceSubClass,
{ "bInterfaceSubClass", "usb.bInterfaceSubClass", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceProtocol,
{ "bInterfaceProtocol", "usb.bInterfaceProtocol", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iInterface,
{ "iInterface", "usb.iInterface", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bEndpointAddress,
{ "bEndpointAddress", "usb.bEndpointAddress", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_configuration_bmAttributes,
{ "Configuration bmAttributes", "usb.configuration.bmAttributes", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bmAttributes,
{ "bmAttributes", "usb.bmAttributes", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bEndpointAttributeTransfer,
{ "Transfertype", "usb.bmAttributes.transfer", FT_UINT8, BASE_HEX,
VALS(usb_bmAttributes_transfer_vals), 0x03, NULL, HFILL }},
{ &hf_usb_bEndpointAttributeSynchonisation,
{ "Synchronisationtype", "usb.bmAttributes.sync", FT_UINT8, BASE_HEX,
VALS(usb_bmAttributes_sync_vals), 0x0c, NULL, HFILL }},
{ &hf_usb_bEndpointAttributeBehaviour,
{ "Behaviourtype", "usb.bmAttributes.behaviour", FT_UINT8, BASE_HEX,
VALS(usb_bmAttributes_behaviour_vals), 0x30, NULL, HFILL }},
{ &hf_usb_wMaxPacketSize,
{ "wMaxPacketSize", "usb.wMaxPacketSize", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_wMaxPacketSize_size,
{ "Maximum Packet Size", "usb.wMaxPacketSize.size", FT_UINT16, BASE_DEC,
NULL, 0x3FF, NULL, HFILL }},
{ &hf_usb_wMaxPacketSize_slots,
{ "Transactions per microframe", "usb.wMaxPacketSize.slots", FT_UINT16, BASE_DEC,
VALS(usb_wMaxPacketSize_slots_vals), (3<<11), NULL, HFILL }},
{ &hf_usb_bInterval,
{ "bInterval", "usb.bInterval", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_wTotalLength,
{ "wTotalLength", "usb.wTotalLength", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bNumInterfaces,
{ "bNumInterfaces", "usb.bNumInterfaces", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bConfigurationValue,
{ "bConfigurationValue", "usb.bConfigurationValue", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iConfiguration,
{ "iConfiguration", "usb.iConfiguration", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bMaxPower,
{ "bMaxPower", "usb.bMaxPower", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_configuration_legacy10buspowered,
{ "Must be 1", "usb.configuration.legacy10buspowered", FT_BOOLEAN, 8,
TFS(&tfs_mustbeone), 0x80, "Legacy USB 1.0 bus powered", HFILL }},
{ &hf_usb_configuration_selfpowered,
{ "Self-Powered", "usb.configuration.selfpowered", FT_BOOLEAN, 8,
TFS(&tfs_selfpowered), 0x40, NULL, HFILL }},
{ &hf_usb_configuration_remotewakeup,
{ "Remote Wakeup", "usb.configuration.remotewakeup", FT_BOOLEAN, 8,
TFS(&tfs_remotewakeup), 0x20, NULL, HFILL }},
{ &hf_usb_bEndpointAddress_number,
{ "Endpoint Number", "usb.bEndpointAddress.number", FT_UINT8, BASE_HEX,
NULL, 0x0f, NULL, HFILL }},
{ &hf_usb_bEndpointAddress_direction,
{ "Direction", "usb.bEndpointAddress.direction", FT_BOOLEAN, 8,
TFS(&tfs_endpoint_direction), 0x80, NULL, HFILL }},
{ &hf_usb_request_in,
{ "Request in", "usb.request_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The request to this packet is in this packet", HFILL }},
{ &hf_usb_time,
{ "Time from request", "usb.time", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time between Request and Response for USB cmds", HFILL }},
{ &hf_usb_response_in,
{ "Response in", "usb.response_in", FT_FRAMENUM, BASE_NONE,
NULL, 0, "The response to this packet is in this packet", HFILL }},
{ &hf_usb_bFirstInterface,
{ "bFirstInterface", "usb.bFirstInterface", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bInterfaceCount,
{ "bInterfaceCount", "usb.bInterfaceCount", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionClass,
{ "bFunctionClass", "usb.bFunctionClass", FT_UINT8, BASE_HEX,
VALS(usb_class_vals), 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionSubClass,
{ "bFunctionSubClass", "usb.bFunctionSubClass", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_bFunctionProtocol,
{ "bFunctionProtocol", "usb.bFunctionProtocol", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_usb_iFunction,
{ "iFunction", "usb.iFunction", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
};
static gint *usb_subtrees[] = {
&usb_hdr,
&usb_setup_hdr,
&usb_isodesc,
&ett_usb_endpoint,
&ett_usb_setup_bmrequesttype,
&ett_descriptor_device,
&ett_configuration_bmAttributes,
&ett_configuration_bEndpointAddress,
&ett_endpoint_bmAttributes,
&ett_endpoint_wMaxPacketSize
};
proto_usb = proto_register_protocol("USB", "USB", "usb");
proto_register_field_array(proto_usb, hf, array_length(hf));
proto_register_subtree_array(usb_subtrees, array_length(usb_subtrees));
register_dissector("usb", dissect_linux_usb, proto_usb);
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
}
void
proto_reg_handoff_usb(void)
{
dissector_handle_t linux_usb_handle, linux_usb_mmapped_handle;
linux_usb_handle = create_dissector_handle(dissect_linux_usb, proto_usb);
linux_usb_mmapped_handle = create_dissector_handle(dissect_linux_usb_mmapped,
proto_usb);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX, linux_usb_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_USB_LINUX_MMAPPED, linux_usb_mmapped_handle);
}
