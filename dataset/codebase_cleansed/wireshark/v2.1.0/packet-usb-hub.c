static void
dissect_usb_hub_clear_hub_feature(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
const gchar* feature_name;
feature_name = val_to_str(usb_trans_info->setup.wValue,
hub_class_feature_selectors_recipient_hub_vals,
"UNKNOWN (0x%x)");
col_append_fstr(pinfo->cinfo, COL_INFO, " [Hub: %s]", feature_name);
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_hub_feature_selector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_clear_port_feature(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
const gchar* feature_name;
feature_name = val_to_str(usb_trans_info->setup.wValue,
hub_class_feature_selectors_recipient_port_vals,
"UNKNOWN (0x%x)");
col_append_fstr(pinfo->cinfo, COL_INFO, " [Port %u: %s]", usb_trans_info->setup.wIndex, feature_name);
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_port_feature_selector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_port, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hub_port_selector, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_clear_tt_buffer(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_ep_num, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hub_dev_addr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_tt_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_get_hub_descriptor(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_descriptor_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hub_descriptor_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_descriptor_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_get_hub_status(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
col_append_str(pinfo->cinfo, COL_INFO, " [Hub]");
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_get_port_status(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
col_append_fstr(pinfo->cinfo, COL_INFO, " [Port %u]", usb_trans_info->setup.wIndex);
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
static const int *status_fields[] = {
&hf_usb_hub_port_status_connection,
&hf_usb_hub_port_status_enable,
&hf_usb_hub_port_status_suspend,
&hf_usb_hub_port_status_overcurrent,
&hf_usb_hub_port_status_reset,
&hf_usb_hub_port_status_power,
&hf_usb_hub_port_status_low_speed,
&hf_usb_hub_port_status_high_speed,
&hf_usb_hub_port_status_test,
&hf_usb_hub_port_status_indicator,
NULL
};
static const int *change_fields[] = {
&hf_usb_hub_port_change_connection,
&hf_usb_hub_port_change_enable,
&hf_usb_hub_port_change_suspend,
&hf_usb_hub_port_change_overcurrent,
&hf_usb_hub_port_change_reset,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_hub_port_status,
ett_usb_hub_port_status, status_fields, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_hub_port_change,
ett_usb_hub_port_change, change_fields, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_usb_hub_get_tt_state(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_tt_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_tt_port, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_tt_state_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_reset_tt(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_tt_port, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_set_hub_descriptor(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_descriptor_index, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hub_descriptor_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_descriptor_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_stop_tt(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_tt_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_set_hub_feature(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
const gchar* feature_name;
feature_name = val_to_str(usb_trans_info->setup.wValue,
hub_class_feature_selectors_recipient_hub_vals,
"UNKNOWN (0x%x)");
col_append_fstr(pinfo->cinfo, COL_INFO, " [Hub: %s]", feature_name);
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_hub_feature_selector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wIndex);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hub_set_port_feature(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
const gchar* feature_name;
feature_name = val_to_str(usb_trans_info->setup.wValue,
hub_class_feature_selectors_recipient_port_vals,
"UNKNOWN (0x%x)");
col_append_fstr(pinfo->cinfo, COL_INFO, " [Port %u: %s]", usb_trans_info->setup.wIndex,
feature_name);
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hub_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_port_feature_selector, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
item = proto_tree_add_item(tree, hf_usb_hub_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wValue);
proto_tree_add_item(subtree, hf_usb_hub_port, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hub_port_selector, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
item = proto_tree_add_item(tree, hf_usb_hub_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hub_wLength);
proto_tree_add_item(subtree, hf_usb_hub_zero, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static gint
dissect_usb_hub_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gboolean is_request;
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info;
int offset = 0;
usb_setup_dissector dissector;
const usb_setup_dissector_table_t *tmp;
if (data == NULL || ((usb_conv_info_t *)data)->usb_trans_info == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
usb_trans_info = usb_conv_info->usb_trans_info;
is_request = (pinfo->srcport==NO_ENDPOINT);
dissector = NULL;
for (tmp = setup_dissectors; tmp->dissector; tmp++) {
if (tmp->request_type == usb_trans_info->setup.requesttype &&
tmp->request == usb_trans_info->setup.request) {
dissector = tmp->dissector;
break;
}
}
if (!dissector) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBHUB");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(usb_trans_info->setup.request, setup_request_names_vals, "Unknown type %x"),
is_request ? "Request " : "Response");
if (is_request) {
proto_tree_add_item(tree, hf_usb_hub_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
dissector(pinfo, tree, tvb, offset, is_request, usb_trans_info, usb_conv_info);
return tvb_captured_length(tvb);
}
void
proto_register_usb_hub(void)
{
static hf_register_info hf[] = {
{ &hf_usb_hub_request,
{ "bRequest", "usbhub.setup.bRequest", FT_UINT8, BASE_HEX, VALS(setup_request_names_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_hub_value,
{ "wValue", "usbhub.setup.wValue", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_index,
{ "wIndex", "usbhub.setup.wIndex", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_length,
{ "wLength", "usbhub.setup.wLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_hub_feature_selector,
{ "HubFeatureSelector", "usbhub.setup.HubFeatureSelector", FT_UINT16, BASE_DEC,
VALS(hub_class_feature_selectors_recipient_hub_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_hub_port_feature_selector,
{ "PortFeatureSelector", "usbhub.setup.PortFeatureSelector", FT_UINT16, BASE_DEC,
VALS(hub_class_feature_selectors_recipient_port_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_hub_dev_addr,
{ "Dev_Addr", "usbhub.setup.Dev_Addr", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_ep_num,
{ "EP_Num", "usbhub.setup.EP_Num", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_descriptor_type,
{ "DescriptorType", "usbhub.setup.DescriptorType", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_descriptor_index,
{ "DescriptorIndex", "usbhub.setup.DescriptorIndex", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_descriptor_length,
{ "DescriptorLength", "usbhub.setup.DescriptorLength", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_zero,
{ "(zero)", "usbhub.setup.zero", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_tt_flags,
{ "TT_Flags", "usbhub.setup.TT_Flags", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_tt_port,
{ "TT_Port", "usbhub.setup.TT_Port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_tt_state_length,
{ "TT State Length", "usbhub.setup.TT_StateLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_port_selector,
{ "PortSelector", "usbhub.setup.PortSelector", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_port,
{ "Port", "usbhub.setup.Port", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hub_port_status,
{ "Port Status", "usbhub.status.port", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_usb_hub_port_change,
{ "Port Change", "usbhub.change.port", FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_usb_hub_port_status_connection,
{ "PORT_CONNECTION", "usbhub.status.port.connection", FT_BOOLEAN, 16, NULL, (1<<0),
NULL, HFILL }},
{ &hf_usb_hub_port_status_enable,
{ "PORT_ENABLE", "usbhub.status.port.enable", FT_BOOLEAN, 16, NULL, (1<<1),
NULL, HFILL }},
{ &hf_usb_hub_port_status_suspend,
{ "PORT_SUSPEND", "usbhub.status.port.suspend", FT_BOOLEAN, 16, NULL, (1<<2),
NULL, HFILL }},
{ &hf_usb_hub_port_status_overcurrent,
{ "PORT_OVER_CURRENT", "usbhub.status.port.overcurrent", FT_BOOLEAN, 16, NULL, (1<<3),
NULL, HFILL }},
{ &hf_usb_hub_port_status_reset,
{ "PORT_RESET", "usbhub.status.port.reset", FT_BOOLEAN, 16, NULL, (1<<4),
NULL, HFILL }},
{ &hf_usb_hub_port_status_power,
{ "PORT_POWER", "usbhub.status.port.power", FT_BOOLEAN, 16, NULL, (1<<8),
NULL, HFILL }},
{ &hf_usb_hub_port_status_low_speed,
{ "PORT_LOW_SPEED", "usbhub.status.port.low_speed", FT_BOOLEAN, 16, NULL, (1<<9),
NULL, HFILL }},
{ &hf_usb_hub_port_status_high_speed,
{ "PORT_HIGH_SPEED", "usbhub.status.port.high_speed", FT_BOOLEAN, 16, NULL, (1<<10),
NULL, HFILL }},
{ &hf_usb_hub_port_status_test,
{ "PORT_TEST", "usbhub.status.port.test", FT_BOOLEAN, 16, NULL, (1<<11),
NULL, HFILL }},
{ &hf_usb_hub_port_status_indicator,
{ "PORT_INDICATOR", "usbhub.status.port.indicator", FT_BOOLEAN, 16,
TFS(&hub_port_status_indicator_meaning), (1<<12),
NULL, HFILL }},
{ &hf_usb_hub_port_change_connection,
{ "C_PORT_CONNECTION", "usbhub.change.port.connection", FT_BOOLEAN, 16, NULL, (1<<0),
NULL, HFILL }},
{ &hf_usb_hub_port_change_enable,
{ "C_PORT_ENABLE", "usbhub.change.port.enable", FT_BOOLEAN, 16, NULL, (1<<1),
NULL, HFILL }},
{ &hf_usb_hub_port_change_suspend,
{ "C_PORT_SUSPEND", "usbhub.status.port.suspend", FT_BOOLEAN, 16, NULL, (1<<2),
NULL, HFILL }},
{ &hf_usb_hub_port_change_overcurrent,
{ "C_PORT_OVER_CURRENT", "usbhub.status.port.overcurrent", FT_BOOLEAN, 16, NULL, (1<<3),
NULL, HFILL }},
{ &hf_usb_hub_port_change_reset,
{ "C_PORT_RESET", "usbhub.status.port.reset", FT_BOOLEAN, 16, NULL, (1<<4),
NULL, HFILL }}
};
static gint *usb_hub_subtrees[] = {
&ett_usb_hub_wValue,
&ett_usb_hub_wIndex,
&ett_usb_hub_wLength,
&ett_usb_hub_port_status,
&ett_usb_hub_port_change
};
proto_usb_hub = proto_register_protocol("USB HUB", "USBHUB", "usbhub");
proto_register_field_array(proto_usb_hub, hf, array_length(hf));
proto_register_subtree_array(usb_hub_subtrees, array_length(usb_hub_subtrees));
}
void
proto_reg_handoff_usb_hub(void)
{
dissector_handle_t usb_hub_control_handle;
usb_hub_control_handle = create_dissector_handle(dissect_usb_hub_control, proto_usb_hub);
dissector_add_uint("usb.control", IF_CLASS_HUB, usb_hub_control_handle);
dissector_add_uint("usb.control", IF_CLASS_UNKNOWN, usb_hub_control_handle);
}
