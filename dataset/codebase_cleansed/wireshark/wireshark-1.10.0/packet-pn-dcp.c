static int
dissect_PNDCP_Option(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, int hfindex, gboolean append_col)
{
guint8 option;
guint8 suboption;
const value_string *val_str;
offset = dissect_pn_uint8 (tvb, offset, pinfo, tree, hfindex, &option);
switch (option) {
case PNDCP_OPTION_IP:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_ip, &suboption);
val_str = pn_dcp_suboption_ip;
break;
case PNDCP_OPTION_DEVICE:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device, &suboption);
val_str = pn_dcp_suboption_device;
break;
case PNDCP_OPTION_DHCP:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_dhcp, &suboption);
val_str = pn_dcp_suboption_dhcp;
break;
case PNDCP_OPTION_CONTROL:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_control, &suboption);
val_str = pn_dcp_suboption_control;
break;
case PNDCP_OPTION_DEVICEINITIATIVE:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_deviceinitiative, &suboption);
val_str = pn_dcp_suboption_deviceinitiative;
break;
case PNDCP_OPTION_ALLSELECTOR:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_all, &suboption);
val_str = pn_dcp_suboption_all;
break;
default:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_manuf, &suboption);
val_str = pn_dcp_suboption_manuf;
}
proto_item_append_text(block_item, ", Status from %s - %s",
val_to_str(option, pn_dcp_option, "Unknown"), val_to_str(suboption, val_str, "Unknown"));
if (append_col) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str(suboption, val_str, "Unknown"));
}
return offset;
}
static int
dissect_PNDCP_Suboption_IP(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id, gboolean is_response)
{
guint8 suboption;
guint16 block_length;
guint16 block_info;
guint16 block_qualifier;
guint32 ip;
proto_item *item = NULL;
offset = dissect_pn_uint8 (tvb, offset, pinfo, tree, hf_pn_dcp_suboption_ip, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
switch (suboption) {
case PNDCP_SUBOPTION_IP_MAC:
pn_append_info(pinfo, dcp_item, ", MAC");
proto_item_append_text(block_item, "IP/MAC");
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
break;
case PNDCP_SUBOPTION_IP_IP:
pn_append_info(pinfo, dcp_item, ", IP");
proto_item_append_text(block_item, "IP/IP");
if ( ((service_id == PNDCP_SERVICE_ID_IDENTIFY) && is_response) ||
((service_id == PNDCP_SERVICE_ID_HELLO) && !is_response) ||
((service_id == PNDCP_SERVICE_ID_GET) && is_response)) {
block_info = tvb_get_ntohs (tvb, offset);
if (tree) {
item = proto_tree_add_uint(tree, hf_pn_dcp_suboption_ip_block_info, tvb, offset, 2, block_info);
}
offset += 2;
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_suboption_ip_block_info, "Undecoded"));
block_length -= 2;
if (block_info & 0x80) {
expert_add_info_format(pinfo, item, PI_RESPONSE_CODE, PI_NOTE, "IP address conflict detected!");
}
}
if ( (service_id == PNDCP_SERVICE_ID_SET) && !is_response) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
block_length -= 2;
}
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_ip_ip, &ip);
proto_item_append_text(block_item, ", IP: %s", ip_to_str((guint8*)&ip));
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_ip_subnetmask, &ip);
proto_item_append_text(block_item, ", Subnet: %s", ip_to_str((guint8*)&ip));
offset = dissect_pn_ipv4(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_ip_standard_gateway, &ip);
proto_item_append_text(block_item, ", Gateway: %s", ip_to_str((guint8*)&ip));
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Suboption_Device(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id, gboolean is_response)
{
guint8 suboption;
guint16 block_length;
gchar *info_str;
guint8 device_role;
guint16 vendor_id;
guint16 device_id;
char *typeofstation;
char *nameofstation;
char *aliasname;
guint16 block_info;
guint16 block_qualifier;
gboolean have_block_info = FALSE;
gboolean have_block_qualifier = FALSE;
guint8 device_instance_high;
guint8 device_instance_low;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
if ( ((service_id == PNDCP_SERVICE_ID_IDENTIFY) && is_response) ||
((service_id == PNDCP_SERVICE_ID_HELLO) && !is_response) ||
((service_id == PNDCP_SERVICE_ID_GET) && is_response)) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_info, &block_info);
have_block_info = TRUE;
block_length -= 2;
}
if ( (service_id == PNDCP_SERVICE_ID_SET) && !is_response) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
have_block_qualifier = TRUE;
block_length -= 2;
}
switch (suboption) {
case PNDCP_SUBOPTION_DEVICE_MANUF:
typeofstation = (char *)ep_alloc(block_length+1);
tvb_memcpy(tvb, (guint8 *) typeofstation, offset, block_length);
typeofstation[block_length] = '\0';
proto_tree_add_string (tree, hf_pn_dcp_suboption_device_typeofstation, tvb, offset, block_length, typeofstation);
pn_append_info(pinfo, dcp_item, ", DeviceVendorValue");
proto_item_append_text(block_item, "Device/Manufacturer specific");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info){
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", DeviceVendorValue: \"%s\"", typeofstation);
offset += block_length;
break;
case PNDCP_SUBOPTION_DEVICE_NAMEOFSTATION:
nameofstation = (char *)ep_alloc(block_length+1);
tvb_memcpy(tvb, (guint8 *) nameofstation, offset, block_length);
nameofstation[block_length] = '\0';
proto_tree_add_string (tree, hf_pn_dcp_suboption_device_nameofstation, tvb, offset, block_length, nameofstation);
pn_append_info(pinfo, dcp_item, ep_strdup_printf(", NameOfStation:\"%s\"", nameofstation));
proto_item_append_text(block_item, "Device/NameOfStation");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", \"%s\"", nameofstation);
offset += block_length;
break;
case PNDCP_SUBOPTION_DEVICE_DEV_ID:
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_vendor_id, &vendor_id);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device_id, &device_id);
pn_append_info(pinfo, dcp_item, ", Dev-ID");
proto_item_append_text(block_item, "Device/Device ID");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", VendorID: 0x%04x / DeviceID: 0x%04x", vendor_id, device_id);
break;
case PNDCP_SUBOPTION_DEVICE_DEV_ROLE:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device_role, &device_role);
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_reserved8, NULL);
pn_append_info(pinfo, dcp_item, ", Dev-Role");
proto_item_append_text(block_item, "Device/Device Role");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info)
proto_item_append_text(block_item, ", BlockInfo: %s", val_to_str(block_info, pn_dcp_block_info, "Unknown"));
if (device_role & 0x01)
proto_item_append_text(block_item, ", IO-Device");
if (device_role & 0x02)
proto_item_append_text(block_item, ", IO-Controller");
if (device_role & 0x04)
proto_item_append_text(block_item, ", IO-Multidevice");
if (device_role & 0x08)
proto_item_append_text(block_item, ", PN-Supervisor");
break;
case PNDCP_SUBOPTION_DEVICE_DEV_OPTIONS:
info_str = ep_strdup_printf(", Dev-Options(%u)", block_length/2);
pn_append_info(pinfo, dcp_item, info_str);
proto_item_append_text(block_item, "Device/Device Options");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", %u options", block_length/2);
for( ; block_length != 0; block_length -= 2) {
offset = dissect_PNDCP_Option(tvb, offset, pinfo, tree, NULL , hf_pn_dcp_option,
FALSE );
}
break;
case PNDCP_SUBOPTION_DEVICE_ALIAS_NAME:
aliasname = (char *)ep_alloc(block_length+1);
tvb_memcpy(tvb, (guint8 *) aliasname, offset, block_length);
aliasname[block_length] = '\0';
proto_tree_add_string (tree, hf_pn_dcp_suboption_device_aliasname, tvb, offset, block_length, aliasname);
pn_append_info(pinfo, dcp_item, ep_strdup_printf(", AliasName:\"%s\"", aliasname));
proto_item_append_text(block_item, "Device/AliasName");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", \"%s\"", aliasname);
offset += block_length;
break;
case PNDCP_SUBOPTION_DEVICE_DEV_INSTANCE:
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device_instance_high, &device_instance_high);
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_device_instance_low, &device_instance_low);
pn_append_info(pinfo, dcp_item, ", Dev-Instance");
proto_item_append_text(block_item, "Device/Device Instance");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_item_append_text(block_item, ", InstanceHigh: %d, Instance Low: %d",
device_instance_high, device_instance_low);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Suboption_DHCP(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id _U_, gboolean is_response _U_)
{
guint8 suboption;
guint16 block_length;
guint16 block_info;
guint16 block_qualifier;
gboolean have_block_info = FALSE;
gboolean have_block_qualifier = FALSE;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_dhcp, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
if ( ((service_id == PNDCP_SERVICE_ID_IDENTIFY) && is_response) ||
((service_id == PNDCP_SERVICE_ID_HELLO) && !is_response) ||
((service_id == PNDCP_SERVICE_ID_GET) && is_response)) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_info, &block_info);
have_block_info=TRUE;
block_length -= 2;
}
if ( (service_id == PNDCP_SERVICE_ID_SET) && !is_response) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
have_block_qualifier=TRUE;
block_length -= 2;
}
switch (suboption) {
case PNDCP_SUBOPTION_DHCP_CLIENT_ID:
pn_append_info(pinfo, dcp_item, ", DHCP client identifier");
proto_item_append_text(block_item, "DHCP/Client-ID");
if (have_block_qualifier) {
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
}
if (have_block_info) {
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
}
proto_tree_add_item(tree, hf_pn_dcp_suboption_dhcp_device_id, tvb, offset, block_length, ENC_NA);
offset += block_length;
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Suboption_Control(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id _U_, gboolean is_response _U_)
{
guint8 suboption;
guint16 block_length;
guint16 block_qualifier;
gchar *info_str;
guint8 block_error;
proto_item *item = NULL;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_control, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
switch (suboption) {
case PNDCP_SUBOPTION_CONTROL_START_TRANS:
pn_append_info(pinfo, dcp_item, ", Start-Trans");
proto_item_append_text(block_item, "Control/Start-Transaction");
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
break;
case PNDCP_SUBOPTION_CONTROL_END_TRANS:
pn_append_info(pinfo, dcp_item, ", End-Trans");
proto_item_append_text(block_item, "Control/End-Transaction");
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
break;
case PNDCP_SUBOPTION_CONTROL_SIGNAL:
pn_append_info(pinfo, dcp_item, ", Signal");
proto_item_append_text(block_item, "Control/Signal");
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
block_length -= 2;
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
break;
case PNDCP_SUBOPTION_CONTROL_RESPONSE:
proto_item_append_text(block_item, "Control/Response");
offset = dissect_PNDCP_Option(tvb, offset, pinfo, tree, block_item, hf_pn_dcp_suboption_control_response,
FALSE );
block_error = tvb_get_guint8 (tvb, offset);
if (tree) {
item = proto_tree_add_uint(tree, hf_pn_dcp_block_error, tvb, offset, 1, block_error);
}
offset += 1;
if (block_error != 0) {
expert_add_info_format(pinfo, item, PI_RESPONSE_CODE, PI_CHAT, "%s",
val_to_str(block_error, pn_dcp_block_error, "Unknown"));
}
info_str = ep_strdup_printf(", Response(%s)",
val_to_str(block_error, pn_dcp_block_error, "Unknown"));
pn_append_info(pinfo, dcp_item, info_str);
proto_item_append_text(block_item, ", BlockError: %s",
val_to_str(block_error, pn_dcp_block_error, "Unknown"));
break;
case PNDCP_SUBOPTION_CONTROL_FACT_RESET:
pn_append_info(pinfo, dcp_item, ", Reset FactorySettings");
proto_item_append_text(block_item, "Control/Reset FactorySettings");
offset += 2;
block_length -= 2;
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Suboption_DeviceInitiative(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id, gboolean is_response)
{
guint8 suboption;
guint16 block_length;
guint16 block_info;
guint16 block_qualifier;
guint16 value;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_deviceinitiative, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
pn_append_info(pinfo, dcp_item, ", DeviceInitiative");
proto_item_append_text(block_item, "DeviceInitiative/DeviceInitiative");
if ( ((service_id == PNDCP_SERVICE_ID_IDENTIFY) && is_response) ||
((service_id == PNDCP_SERVICE_ID_HELLO) && !is_response) ||
((service_id == PNDCP_SERVICE_ID_GET) && is_response)) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_info, &block_info);
proto_item_append_text(block_item, ", BlockInfo: %s",
val_to_str(block_info, pn_dcp_block_info, "Unknown"));
block_length -= 2;
}
if ( (service_id == PNDCP_SERVICE_ID_SET) && !is_response) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_qualifier, &block_qualifier);
proto_item_append_text(block_item, ", BlockQualifier: %s",
val_to_str(block_qualifier, pn_dcp_block_qualifier, "Unknown"));
block_length -= 2;
}
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_deviceinitiative_value, &value);
return offset;
}
static int
dissect_PNDCP_Suboption_All(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id _U_, gboolean is_response _U_)
{
guint8 suboption;
guint16 block_length;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_dcp_suboption_all, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
switch (suboption) {
case 255:
pn_append_info(pinfo, dcp_item, ", All");
proto_item_append_text(block_item, "All/All");
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Suboption_Manuf(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *block_item, proto_item *dcp_item,
guint8 service_id _U_, gboolean is_response _U_)
{
guint8 suboption;
guint16 block_length;
offset = dissect_pn_uint8( tvb, offset, pinfo, tree, hf_pn_dcp_suboption_manuf, &suboption);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_block_length, &block_length);
switch (suboption) {
default:
pn_append_info(pinfo, dcp_item, ", Manufacturer Specific");
proto_item_append_text(block_item, "Manufacturer Specific");
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, block_length);
}
return offset;
}
static int
dissect_PNDCP_Block(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *dcp_item,
guint8 service_id, gboolean is_response)
{
guint8 option;
proto_item *block_item;
proto_tree *block_tree;
int ori_offset = offset;
block_item = proto_tree_add_none_format(tree, hf_pn_dcp_block,
tvb, offset, 0, "Block: ");
block_tree = proto_item_add_subtree(block_item, ett_pn_dcp_block);
offset = dissect_pn_uint8(tvb, offset, pinfo, block_tree, hf_pn_dcp_option, &option);
switch (option) {
case PNDCP_OPTION_IP:
offset = dissect_PNDCP_Suboption_IP(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_DEVICE:
offset = dissect_PNDCP_Suboption_Device(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_DHCP:
offset = dissect_PNDCP_Suboption_DHCP(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_CONTROL:
offset = dissect_PNDCP_Suboption_Control(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_DEVICEINITIATIVE:
offset = dissect_PNDCP_Suboption_DeviceInitiative(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_ALLSELECTOR:
offset = dissect_PNDCP_Suboption_All(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
break;
case PNDCP_OPTION_MANUF_X80:
case PNDCP_OPTION_MANUF_X81:
default:
offset = dissect_PNDCP_Suboption_Manuf(tvb, offset, pinfo, block_tree, block_item, dcp_item, service_id, is_response);
}
proto_item_set_len(block_item, offset-ori_offset);
if ((offset-ori_offset) & 1) {
offset = dissect_pn_padding(tvb, offset, pinfo, tree, 1);
}
return offset;
}
static void
dissect_PNDCP_PDU(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, proto_item *dcp_item)
{
guint8 service_id;
guint8 service_type;
guint32 xid;
guint16 response_delay;
guint16 data_length;
int offset = 0;
gchar *xid_str;
gboolean is_response = FALSE;
offset = dissect_pn_uint8 (tvb, offset, pinfo, tree, hf_pn_dcp_service_id, &service_id);
offset = dissect_pn_uint8 (tvb, offset, pinfo, tree, hf_pn_dcp_service_type, &service_type);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_dcp_xid, &xid);
if (service_id == PNDCP_SERVICE_ID_IDENTIFY && service_type == PNDCP_SERVICE_TYPE_REQUEST) {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_response_delay, &response_delay);
} else {
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_reserved16, NULL);
}
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_dcp_data_length, &data_length);
switch (service_id) {
case PNDCP_SERVICE_ID_GET:
pn_append_info(pinfo, dcp_item, "Get");
break;
case PNDCP_SERVICE_ID_SET:
pn_append_info(pinfo, dcp_item, "Set");
break;
case PNDCP_SERVICE_ID_IDENTIFY:
pn_append_info(pinfo, dcp_item, "Ident");
break;
case PNDCP_SERVICE_ID_HELLO:
pn_append_info(pinfo, dcp_item, "Hello");
break;
default:
dissect_pn_undecoded(tvb, offset, pinfo, tree, tvb_length_remaining(tvb, offset));
return;
}
switch (service_type) {
case PNDCP_SERVICE_TYPE_REQUEST:
pn_append_info(pinfo, dcp_item, " Req");
break;
case PNDCP_SERVICE_TYPE_RESPONSE_SUCCESS:
pn_append_info(pinfo, dcp_item, " Ok ");
is_response = TRUE;
break;
case PNDCP_SERVICE_TYPE_RESPONSE_UNSUPPORTED:
pn_append_info(pinfo, dcp_item, " unsupported");
is_response = TRUE;
break;
default:
dissect_pn_undecoded(tvb, offset, pinfo, tree, tvb_length_remaining(tvb, offset));
return;
}
xid_str = ep_strdup_printf(", Xid:0x%x", xid);
pn_append_info(pinfo, dcp_item, xid_str);
while(data_length) {
int ori_offset = offset;
if (service_id == PNDCP_SERVICE_ID_GET && service_type == PNDCP_SERVICE_TYPE_REQUEST) {
offset = dissect_PNDCP_Option(tvb, offset, pinfo,
tree, dcp_item, hf_pn_dcp_option, TRUE );
} else {
offset = dissect_PNDCP_Block(tvb, offset, pinfo, tree, dcp_item, service_id, is_response);
}
if (offset <= ori_offset || data_length < (offset - ori_offset)) {
THROW(ReportedBoundsError);
}
data_length -= (offset - ori_offset);
}
}
static gboolean
dissect_PNDCP_Data_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
guint16 u16FrameID;
proto_item *item;
proto_tree *dcp_tree;
u16FrameID = GPOINTER_TO_UINT(pinfo->private_data);
if (u16FrameID < FRAME_ID_DCP_HELLO || u16FrameID > FRAME_ID_DCP_IDENT_RES) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN-DCP");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_protocol_format(tree, proto_pn_dcp, tvb, 0, tvb_get_ntohs(tvb, 8) + 10,
"PROFINET DCP, ");
dcp_tree = proto_item_add_subtree(item, ett_pn_dcp);
dissect_PNDCP_PDU(tvb, pinfo, dcp_tree, item);
return TRUE;
}
void
proto_register_pn_dcp (void)
{
static hf_register_info hf[] = {
{ &hf_pn_dcp_service_id,
{ "ServiceID", "pn_dcp.service_id",
FT_UINT8, BASE_DEC, VALS(pn_dcp_service_id), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_service_type,
{ "ServiceType", "pn_dcp.service_type",
FT_UINT8, BASE_DEC, VALS(pn_dcp_service_type), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_xid,
{ "Xid", "pn_dcp.xid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_reserved8,
{ "Reserved", "pn_dcp.reserved8",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_reserved16,
{ "Reserved", "pn_dcp.reserved16",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_response_delay,
{ "ResponseDelay", "pn_dcp.response_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_data_length,
{ "DCPDataLength", "pn_dcp.data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_block_length,
{ "DCPBlockLength", "pn_dcp.block_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_option,
{ "Option", "pn_dcp.option",
FT_UINT8, BASE_DEC, VALS(pn_dcp_option), 0x0,
NULL, HFILL }},
#if 0
{ &hf_pn_dcp_suboption,
{ "Suboption", "pn_dcp.suboption",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_pn_dcp_block_error,
{ "BlockError", "pn_dcp.block_error",
FT_UINT8, BASE_DEC, VALS(pn_dcp_block_error), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_block,
{ "Block", "pn_dcp.block",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_block_info,
{ "BlockInfo", "pn_dcp.block_info",
FT_UINT16, BASE_DEC, VALS(pn_dcp_block_info), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_block_qualifier,
{ "BlockQualifier", "pn_dcp.block_qualifier",
FT_UINT16, BASE_DEC, VALS(pn_dcp_block_qualifier), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_ip,
{ "Suboption", "pn_dcp.suboption_ip",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_ip), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_ip_block_info,
{ "BlockInfo", "pn_dcp.suboption_ip_block_info",
FT_UINT16, BASE_DEC, VALS(pn_dcp_suboption_ip_block_info), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_ip_ip,
{ "IPaddress", "pn_dcp.subobtion_ip_ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_ip_subnetmask,
{ "Subnetmask", "pn_dcp.subobtion_ip_subnetmask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_ip_standard_gateway,
{ "StandardGateway", "pn_dcp.suboption_ip_standard_gateway",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device,
{ "Suboption", "pn_dcp.suboption_device",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_device), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_typeofstation,
{ "DeviceVendorValue", "pn_dcp.suboption_device_devicevendorvalue",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_nameofstation,
{ "NameOfStation", "pn_dcp.suboption_device_nameofstation",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_vendor_id,
{ "VendorID", "pn_dcp.suboption_vendor_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_id,
{ "DeviceID", "pn_dcp.suboption_device_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_role,
{ "DeviceRoleDetails", "pn_dcp.suboption_device_role",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_aliasname,
{ "AliasName", "pn_dcp.suboption_device_aliasname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_instance_high,
{ "DeviceInstanceHigh", "pn_dcp.suboption_device_instance",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_device_instance_low,
{ "DeviceInstanceLow", "pn_dcp.suboption_device_instance",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_dhcp,
{ "Suboption", "pn_dcp.suboption_dhcp",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_dhcp), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_dhcp_device_id,
{ "Device ID", "pn_dcp.suboption_dhcp_device_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_control,
{ "Suboption", "pn_dcp.suboption_control",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_control), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_control_response,
{ "Response", "pn_dcp.suboption_control_response",
FT_UINT8, BASE_DEC, VALS(pn_dcp_option), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_deviceinitiative,
{ "Suboption", "pn_dcp.suboption_deviceinitiative",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_deviceinitiative), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_deviceinitiative_value,
{ "DeviceInitiativeValue", "pn_dcp.deviceinitiative_value",
FT_UINT16, BASE_DEC, VALS(pn_dcp_deviceinitiative_value), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_all,
{ "Suboption", "pn_dcp.suboption_all",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_all), 0x0,
NULL, HFILL }},
{ &hf_pn_dcp_suboption_manuf,
{ "Suboption", "pn_dcp.suboption_manuf",
FT_UINT8, BASE_DEC, VALS(pn_dcp_suboption_manuf), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_pn_dcp,
&ett_pn_dcp_block
};
proto_pn_dcp = proto_register_protocol ("PROFINET DCP", "PN-DCP", "pn_dcp");
proto_register_field_array (proto_pn_dcp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_pn_dcp (void)
{
heur_dissector_add("pn_rt", dissect_PNDCP_Data_heur, proto_pn_dcp);
}
