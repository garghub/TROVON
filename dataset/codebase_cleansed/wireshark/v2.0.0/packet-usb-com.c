static int
dissect_usb_com_descriptor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 offset = 0, type, subtype;
proto_tree *subtree;
proto_tree *subtree_capabilities;
proto_item *subitem_capabilities;
subtree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_usb_com, NULL, "COMMUNICATIONS DESCRIPTOR");
dissect_usb_descriptor_header(subtree, tvb, offset, &usb_com_descriptor_type_vals_ext);
offset += 2;
type = tvb_get_guint8(tvb, 1);
switch (type) {
case CS_INTERFACE:
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_usb_com_descriptor_subtype, tvb, offset, 1, subtype);
offset++;
switch (subtype) {
case 0x00:
proto_tree_add_item(subtree, hf_usb_com_descriptor_cdc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 0x01:
subitem_capabilities = proto_tree_add_item(subtree, hf_usb_com_capabilities, tvb, 3, 1, ENC_LITTLE_ENDIAN);
subtree_capabilities = proto_item_add_subtree(subitem_capabilities, ett_usb_com_capabilities);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_cm_capabilities_reserved, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_cm_capabilities_call_management_over_data_class_interface, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_cm_capabilities_call_management, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_usb_com_descriptor_cm_data_interface, tvb, 4, 1, ENC_LITTLE_ENDIAN);
offset = 5;
break;
case 0x02:
subitem_capabilities = proto_tree_add_item(subtree, hf_usb_com_capabilities, tvb, 3, 1, ENC_LITTLE_ENDIAN);
subtree_capabilities = proto_item_add_subtree(subitem_capabilities, ett_usb_com_capabilities);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_acm_capabilities_reserved, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_acm_capabilities_network_connection, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_acm_capabilities_send_break, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_acm_capabilities_line_and_state, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree_capabilities, hf_usb_com_descriptor_acm_capabilities_comm_features, tvb, 3, 1, ENC_LITTLE_ENDIAN);
offset = 4;
break;
case 0x06:
offset = 3;
proto_tree_add_item(subtree, hf_usb_com_descriptor_control_interface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
while (tvb_reported_length_remaining(tvb,offset) > 0) {
proto_tree_add_item(subtree, hf_usb_com_descriptor_subordinate_interface, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
break;
case 0x0f:
proto_tree_add_item(subtree, hf_usb_com_descriptor_ecm_mac_address, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_bitmask_with_flags(subtree, tvb, offset, hf_usb_com_descriptor_ecm_eth_stats,
ett_usb_com_descriptor_ecm_eth_stats, ecm_eth_stats,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
offset += 4;
proto_tree_add_item(subtree, hf_usb_com_descriptor_ecm_max_segment_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask_with_flags(subtree, tvb, offset, hf_usb_com_descriptor_ecm_nb_mc_filters,
ett_usb_com_descriptor_ecm_nb_mc_filters, ecm_nb_mc_filters,
ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_descriptor_ecm_nb_power_filters, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case 0x1b:
case 0x1c:
offset = call_dissector_only(mbim_descriptor_handle, tvb, pinfo, subtree, data);
break;
default:
break;
}
break;
case CS_ENDPOINT:
default:
break;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(subtree, hf_usb_com_descriptor_payload, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_usb_com_get_ntb_params(tvbuff_t *tvb, proto_tree *tree, gint base_offset)
{
gint offset = base_offset;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_usb_com_get_ntb_params_ntb_formats_supported, ett_usb_com_bitmap,
usb_com_get_ntb_params_ntb_formats_supported_fields, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ntb_in_max_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_in_divisor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_in_payload_remainder, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_in_alignment, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ntb_out_max_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_out_divisor, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_out_payload_remainder, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ndp_out_alignment, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_com_get_ntb_params_ntb_out_max_datagrams, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_usb_com_ntb_input_size(tvbuff_t *tvb, proto_tree *tree, gint base_offset, gboolean is_set)
{
gint offset = base_offset;
proto_tree_add_item(tree, is_set ? hf_usb_com_set_ntb_input_size_ntb_in_max_size :
hf_usb_com_get_ntb_input_size_ntb_in_max_size, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(tree, is_set ? hf_usb_com_set_ntb_input_size_ntb_in_max_datagrams :
hf_usb_com_get_ntb_input_size_ntb_in_max_datagrams, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, is_set ? hf_usb_com_set_ntb_input_size_reserved :
hf_usb_com_get_ntb_input_size_reserved, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static int
dissect_usb_com_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info = (usb_conv_info_t *)data;
usb_trans_info_t *usb_trans_info;
proto_tree *subtree;
proto_item *ti;
gint offset = 0;
gboolean is_request;
if (tvb_reported_length(tvb) == 0) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBCOM");
ti = proto_tree_add_item(tree, proto_usb_com, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_usb_com);
if (usb_conv_info) {
usb_trans_info = usb_conv_info->usb_trans_info;
ti = proto_tree_add_uint(subtree, hf_usb_com_control_subclass, tvb, 0, 0,
usb_conv_info->interfaceSubclass);
PROTO_ITEM_SET_GENERATED(ti);
is_request = (pinfo->srcport==NO_ENDPOINT);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str_ext(usb_trans_info->setup.request, &usb_com_setup_request_vals_ext, "Unknown type %x"),
is_request ? "Request" : "Response");
if (is_request) {
proto_tree_add_item(subtree, hf_usb_com_control_request_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(subtree, hf_usb_com_control_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_control_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_control_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
ti = proto_tree_add_uint(subtree, hf_usb_com_control_response_code, tvb, 0, 0,
usb_trans_info->setup.request);
PROTO_ITEM_SET_GENERATED(ti);
}
switch (usb_trans_info->setup.request)
{
case SEND_ENCAPSULATED_COMMAND:
if ((usb_conv_info->interfaceSubclass == COM_SUBCLASS_MBIM) &&
(USB_HEADER_IS_LINUX(usb_trans_info->header_type))) {
offset = call_dissector_only(mbim_control_handle, tvb, pinfo, tree, usb_conv_info);
break;
}
case GET_ENCAPSULATED_RESPONSE:
if ((usb_conv_info->interfaceSubclass == COM_SUBCLASS_MBIM) && !is_request) {
offset = call_dissector_only(mbim_control_handle, tvb, pinfo, tree, usb_conv_info);
}
break;
case GET_NTB_PARAMETERS:
if (!is_request) {
offset = dissect_usb_com_get_ntb_params(tvb, subtree, offset);
}
break;
case GET_NET_ADDRESS:
if (!is_request) {
proto_tree_add_item(subtree, hf_usb_com_get_net_address_eui48, tvb, offset, 6, ENC_NA);
offset += 6;
}
break;
case SET_NET_ADDRESS:
if (is_request) {
proto_tree_add_item(subtree, hf_usb_com_set_net_address_eui48, tvb, offset, 6, ENC_NA);
offset += 6;
}
break;
case GET_NTB_FORMAT:
if (!is_request) {
proto_tree_add_item(subtree, hf_usb_com_get_ntb_format_ntb_format, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case SET_NTB_FORMAT:
if (is_request) {
proto_tree_add_item(subtree, hf_usb_com_set_ntb_format_ntb_format, tvb, offset-6, 2, ENC_LITTLE_ENDIAN);
}
break;
case GET_NTB_INPUT_SIZE:
if (!is_request) {
offset = dissect_usb_com_ntb_input_size(tvb, subtree, offset, FALSE);
}
break;
case SET_NTB_INPUT_SIZE:
if (!is_request) {
offset = dissect_usb_com_ntb_input_size(tvb, subtree, offset, TRUE);
}
break;
case GET_MAX_DATAGRAM_SIZE:
if (!is_request) {
proto_tree_add_item(subtree, hf_usb_com_get_max_datagram_size_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case SET_MAX_DATAGRAM_SIZE:
if (is_request) {
proto_tree_add_item(subtree, hf_usb_com_set_max_datagram_size_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case GET_CRC_MODE:
if (!is_request) {
proto_tree_add_item(subtree, hf_usb_com_get_crc_mode_crc_mode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
break;
case SET_CRC_MODE:
if (is_request) {
proto_tree_add_item(subtree, hf_usb_com_set_crc_mode_crc_mode, tvb, offset-6, 2, ENC_LITTLE_ENDIAN);
}
break;
default:
break;
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(subtree, hf_usb_com_control_payload, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_usb_com_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info = (usb_conv_info_t *)data;
if (usb_conv_info) {
switch (usb_conv_info->interfaceProtocol)
{
case 0x01:
case 0x02:
return call_dissector_only(mbim_bulk_handle, tvb, pinfo, tree, NULL);
default:
break;
}
}
return call_dissector_only(eth_withoutfcs_handle, tvb, pinfo, tree, NULL);
}
static int
dissect_usb_com_interrupt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *subtree;
proto_item *it;
guint32 notif_code;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBCOM");
it = proto_tree_add_item(tree, proto_usb_com, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(it, ett_usb_com);
proto_tree_add_item(subtree, hf_usb_com_interrupt_request_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item_ret_uint(subtree, hf_usb_com_interrupt_notif_code, tvb, offset, 1, ENC_LITTLE_ENDIAN, &notif_code);
offset++;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(notif_code, usb_com_interrupt_notif_code_vals, "Unknown type %x"));
switch (notif_code) {
case NETWORK_CONNECTION:
proto_tree_add_item(subtree, hf_usb_com_interrupt_value_nw_conn, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case RESPONSE_AVAILABLE:
proto_tree_add_item(subtree, hf_usb_com_interrupt_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case CONNECTION_SPEED_CHANGE:
proto_tree_add_item(subtree, hf_usb_com_interrupt_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_usb_com_interrupt_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
it = proto_tree_add_item(subtree, hf_usb_com_interrupt_dl_bitrate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(it, " b/s");
offset += 4;
it = proto_tree_add_item(subtree, hf_usb_com_interrupt_ul_bitrate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(it, " b/s");
offset += 4;
break;
default:
break;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(subtree, hf_usb_com_interrupt_payload, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
void
proto_register_usb_com(void)
{
static hf_register_info hf[] = {
{ &hf_usb_com_descriptor_subtype,
{ "Descriptor Subtype", "usbcom.descriptor.subtype", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&usb_com_descriptor_subtype_vals_ext, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_cdc,
{ "CDC", "usbcom.descriptor.cdc", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_payload,
{ "Payload", "usbcom.descriptor.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_control_subclass,
{ "Subclass", "usbcom.control.subclass", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&ext_usb_com_subclass_vals, 0, NULL, HFILL }},
{ &hf_usb_com_control_request_code,
{ "Request Code", "usbcom.control.request_code", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&usb_com_setup_request_vals_ext, 0, NULL, HFILL }},
{ &hf_usb_com_control_value,
{ "Value", "usbcom.control.value", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_control_index,
{ "Index", "usbcom.control.index", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_control_length,
{ "Length", "usbcom.control.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_control_response_code,
{ "Response Code", "usbcom.control.response_code", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&usb_com_setup_request_vals_ext, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_length,
{ "Length", "usbcom.control.get_ntb_params.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_formats_supported,
{ "NTB Formats Supported", "usbcom.control.get_ntb_params.ntb_formats_supported", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_formats_supported_16bit,
{ "16-bit NTB", "usbcom.control.get_ntb_params.ntb_formats_supported.16bit", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0001, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_formats_supported_32bit,
{ "32-bit NTB", "usbcom.control.get_ntb_params.ntb_formats_supported.32bit", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0002, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_in_max_size,
{ "NTB IN Max Size", "usbcom.control.get_ntb_params.ntb_in_max_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_in_divisor,
{ "NDP IN Divisor", "usbcom.control.get_ntb_params.ndp_in_divisor", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_in_payload_remainder,
{ "NDP IN Payload Remainder", "usbcom.control.get_ntb_params.ndp_in_payload_remainder", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_in_alignment,
{ "NDP IN Alignment", "usbcom.control.get_ntb_params.ndp_in_alignment", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_reserved,
{ "Reserved", "usbcom.control.get_ntb_params.reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_out_max_size,
{ "NTB OUT Max Size", "usbcom.control.get_ntb_params.ntb_out_max_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_out_divisor,
{ "NDP OUT Divisor", "usbcom.control.get_ntb_params.ndp_out_divisor", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_out_payload_remainder,
{ "NDP OUT Payload Remainder", "usbcom.control.get_ntb_params.ndp_out_payload_remainder", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ndp_out_alignment,
{ "NDP OUT Alignment", "usbcom.control.get_ntb_params.ndp_out_alignment", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_params_ntb_out_max_datagrams,
{ "NTB OUT Max Datagrams", "usbcom.control.get_ntb_params.ntb_out_max_datagrams", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_net_address_eui48,
{ "EUI-48", "usbcom.control.get_net_address.eui48", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_set_net_address_eui48,
{ "EUI-48", "usbcom.control.set_net_address.eui48", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_format_ntb_format,
{ "NTB Format", "usbcom.control.get_net_address.ntb_format", FT_UINT16, BASE_HEX,
VALS(usb_com_ntb_format_vals), 0, NULL, HFILL }},
{ &hf_usb_com_set_ntb_format_ntb_format,
{ "NTB Format", "usbcom.control.set_net_address.ntb_format", FT_UINT16, BASE_HEX,
VALS(usb_com_ntb_format_vals), 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_input_size_ntb_in_max_size,
{ "NTB IN Max Size", "usbcom.control.get_ntb_input_size.ntb_in_max_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_input_size_ntb_in_max_datagrams,
{ "NTB IN Max Datagrams", "usbcom.control.get_ntb_input_size.ntb_in_max_datagrams", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_ntb_input_size_reserved,
{ "Reserved", "usbcom.control.get_ntb_input_size.reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_set_ntb_input_size_ntb_in_max_size,
{ "NTB IN Max Size", "usbcom.control.set_ntb_input_size.ntb_in_max_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_set_ntb_input_size_ntb_in_max_datagrams,
{ "NTB IN Max Datagrams", "usbcom.control.set_ntb_input_size.ntb_in_max_datagrams", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_set_ntb_input_size_reserved,
{ "Reserved", "usbcom.control.set_ntb_input_size.reserved", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_max_datagram_size_size,
{ "Max Datagram Size", "usbcom.control.get_max_datagram_size.size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_set_max_datagram_size_size,
{ "Max Datagram Size", "usbcom.control.set_max_datagram_size.size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_get_crc_mode_crc_mode,
{ "CRC Mode", "usbcom.control.get_crc_mode.crc_mode", FT_UINT16, BASE_HEX,
VALS(usb_com_crc_mode_vals), 0, NULL, HFILL }},
{ &hf_usb_com_set_crc_mode_crc_mode,
{ "CRC Mode", "usbcom.control.set_crc_mode.crc_mode", FT_UINT16, BASE_HEX,
VALS(usb_com_crc_mode_vals), 0, NULL, HFILL }},
{ &hf_usb_com_control_payload,
{ "Payload", "usbcom.control.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_capabilities,
{ "bmCapabilities", "usbcom.descriptor.capabilities", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_acm_capabilities_reserved,
{ "Reserved", "usbcom.descriptor.acm.capabilities.reserved", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL }},
{ &hf_usb_com_descriptor_acm_capabilities_network_connection,
{ "Network_Connection", "usbcom.descriptor.acm.capabilities.network_connection", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x08, NULL, HFILL }},
{ &hf_usb_com_descriptor_acm_capabilities_send_break,
{ "Send_Break", "usbcom.descriptor.acm.capabilities.network_connection", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x04, NULL, HFILL }},
{ &hf_usb_com_descriptor_acm_capabilities_line_and_state,
{ "Line Requests and State Notification", "usbcom.descriptor.acm.capabilities.line_and_state", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{ &hf_usb_com_descriptor_acm_capabilities_comm_features,
{ "Comm Features Combinations", "usbcom.descriptor.acm.capabilities.comm_features", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{ &hf_usb_com_descriptor_control_interface,
{ "Control Interface", "usbcom.descriptor.control_interface", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_subordinate_interface,
{ "Subordinate Interface", "usbcom.descriptor.subordinate_interface", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_cm_capabilities_reserved,
{ "Reserved", "usbcom.descriptor.cm.capabilities.reserved", FT_UINT8, BASE_HEX,
NULL, 0xFC, NULL, HFILL }},
{ &hf_usb_com_descriptor_cm_capabilities_call_management_over_data_class_interface,
{ "Call Management over Data Class Interface", "usbcom.descriptor.cm.capabilities.call_management_over_data_class_interface", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{ &hf_usb_com_descriptor_cm_capabilities_call_management,
{ "Call Management", "usbcom.descriptor.cm.capabilities.call_management", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{ &hf_usb_com_descriptor_cm_data_interface,
{ "Data Interface", "usbcom.descriptor.cm.data_interface", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_mac_address,
{ "MAC Address", "usbcom.descriptor.ecm.mac_address", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats,
{ "Ethernet Statistics", "usbcom.descriptor.ecm.eth_stats", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_reserved,
{ "Reserved", "usbcom.descriptor.ecm.eth_stats.reserved", FT_UINT32, BASE_HEX,
NULL, 0xe0000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_late_collisions,
{ "XMIT Late Collisions", "usbcom.descriptor.ecm.eth_stats.xmit_late_collisions", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x10000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_times_crs_lost,
{ "XMIT TImes CRS Lost", "usbcom.descriptor.ecm.eth_stats.xmit_times_crs_lost", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x08000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_heartbeat_failure,
{ "XMIT Heartbeat Failure", "usbcom.descriptor.ecm.eth_stats.xmit_heartbeat_failure", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x04000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_underrun,
{ "XMIT Underrun", "usbcom.descriptor.ecm.eth_stats.xmit_underrun", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x02000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rcv_overrun,
{ "RCV Overrun", "usbcom.descriptor.ecm.eth_stats.rcv_overrun", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x01000000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_max_collisions,
{ "XMIT Max Collisions", "usbcom.descriptor.ecm.eth_stats.xmit_max_collisions", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00800000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_deferred,
{ "XMIT Deferred", "usbcom.descriptor.ecm.eth_stats.xmit_deferred", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00400000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_more_collisions,
{ "XMIT More Collisions", "usbcom.descriptor.ecm.eth_stats.xmit_more_collisions", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00200000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_one_collision,
{ "XMIT One Collision", "usbcom.descriptor.ecm.eth_stats.xmit_one_collision", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00100000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rcv_error_alignment,
{ "RCV Error Alignment", "usbcom.descriptor.ecm.eth_stats.rcv_error_alignment", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00080000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_transmit_queue_length,
{ "Transmit Queue Length", "usbcom.descriptor.ecm.eth_stats.transmit_queue_length", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00040000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rcv_crc_error,
{ "RCV CRC Error", "usbcom.descriptor.ecm.eth_stats.rcv_crc_error", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00020000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_broadcast_frames_rcv,
{ "Broadcast Frames RCV", "usbcom.descriptor.ecm.eth_stats.broadcast_frames_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00010000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_broadcast_bytes_rcv,
{ "Broadcast Bytes RCV", "usbcom.descriptor.ecm.eth_stats.broadcast_bytes_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00008000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_multicast_frames_rcv,
{ "Multicast Frames RCV", "usbcom.descriptor.ecm.eth_stats.multicast_frames_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00004000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_multicast_bytes_rcv,
{ "Multicast Bytes RCV", "usbcom.descriptor.ecm.eth_stats.multicast_bytes_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00002000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_directed_frames_rcv,
{ "Directed Frames RCV", "usbcom.descriptor.ecm.eth_stats.directed_frames_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00001000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_directed_bytes_rcv,
{ "Directed Bytes RCV", "usbcom.descriptor.ecm.eth_stats.directed_bytes_rcv", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000800, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_broadcast_frames_xmit,
{ "Broadcast Frames XMIT", "usbcom.descriptor.ecm.eth_stats.broadcast_frames_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000400, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_broadcast_bytes_xmit,
{ "Broadcast Bytes XMIT", "usbcom.descriptor.ecm.eth_stats.broadcast_bytes_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000200, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_multicast_frames_xmit,
{ "Multicast Frames XMIT", "usbcom.descriptor.ecm.eth_stats.multicast_frames_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000100, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_multicast_bytes_xmit,
{ "Multicast Bytes XMIT", "usbcom.descriptor.ecm.eth_stats.multicast_bytes_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000080, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_directed_frames_xmit,
{ "Directed Frames XMIT", "usbcom.descriptor.ecm.eth_stats.directed_frames_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000040, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_directed_bytes_xmit,
{ "Directed Bytes XMIT", "usbcom.descriptor.ecm.eth_stats.directed_bytes_xmit", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000020, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rcv_no_buffer,
{ "RCV No Buffer", "usbcom.descriptor.ecm.eth_stats.rcv_no_buffer", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000010, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rcv_error,
{ "RCV Error", "usbcom.descriptor.ecm.eth_stats.rcv_error", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000008, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_error,
{ "XMIT Error", "usbcom.descriptor.ecm.eth_stats.xmit_error", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000004, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_rvc_ok,
{ "RCV OK", "usbcom.descriptor.ecm.eth_stats.rvc_ok", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000002, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_eth_stats_xmit_ok,
{ "XMIT OK", "usbcom.descriptor.ecm.eth_stats.xmit_ok", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x00000001, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_max_segment_size,
{ "Max Segment Size", "usbcom.descriptor.ecm.max_segment_size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_nb_mc_filters,
{ "Number MC Filters", "usbcom.descriptor.ecm.nb_mc_filters", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_nb_mc_filters_mc_address_filtering,
{ "Multicast Address Filtering", "usbcom.descriptor.ecm.nb_mc_filters.mc_address_filtering", FT_BOOLEAN, 16,
TFS(&usb_com_ecm_mc_address_filtering), 0x8000, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_nb_mc_filters_nb_filters_supported,
{ "Number of Multicast Address Filters Supported", "usbcom.descriptor.ecm.nb_mc_filters.nb_filters_supported", FT_UINT16, BASE_DEC,
NULL, 0x7fff, NULL, HFILL }},
{ &hf_usb_com_descriptor_ecm_nb_power_filters,
{ "Number Power Filters", "usbcom.descriptor.ecm.nb_power_filters", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_request_type,
{ "Request Type", "usbcom.interrupt.request_type", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_notif_code,
{ "Notification Code", "usbcom.interrupt.notification_code", FT_UINT8, BASE_HEX,
VALS(usb_com_interrupt_notif_code_vals), 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_value,
{ "Value", "usbcom.interrupt.value", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_value_nw_conn,
{ "Value", "usbcom.interrupt.value", FT_UINT16, BASE_HEX,
VALS(usb_com_interrupt_value_nw_conn_vals), 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_index,
{ "Index", "usbcom.interrupt.index", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_length,
{ "Length", "usbcom.interrupt.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_dl_bitrate,
{ "DL Bitrate", "usbcom.interrupt.conn_speed_change.dl_bitrate", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_ul_bitrate,
{ "UL Bitrate", "usbcom.interrupt.conn_speed_change.ul_bitrate", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_interrupt_payload,
{ "Payload", "usbcom.interrupt.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }}
};
static gint *usb_com_subtrees[] = {
&ett_usb_com,
&ett_usb_com_capabilities,
&ett_usb_com_bitmap,
&ett_usb_com_descriptor_ecm_eth_stats,
&ett_usb_com_descriptor_ecm_nb_mc_filters
};
proto_usb_com = proto_register_protocol("USB Communications and CDC Control", "USBCOM", "usbcom");
proto_register_field_array(proto_usb_com, hf, array_length(hf));
proto_register_subtree_array(usb_com_subtrees, array_length(usb_com_subtrees));
}
void
proto_reg_handoff_usb_com(void)
{
dissector_handle_t usb_com_descriptor_handle, usb_com_control_handle,
usb_com_bulk_handle, usb_com_interrupt_handle;
usb_com_descriptor_handle = new_create_dissector_handle(dissect_usb_com_descriptor, proto_usb_com);
dissector_add_uint("usb.descriptor", IF_CLASS_COMMUNICATIONS, usb_com_descriptor_handle);
usb_com_control_handle = new_create_dissector_handle(dissect_usb_com_control, proto_usb_com);
dissector_add_uint("usb.control", IF_CLASS_COMMUNICATIONS, usb_com_control_handle);
usb_com_bulk_handle = new_create_dissector_handle(dissect_usb_com_bulk, proto_usb_com);
dissector_add_uint("usb.bulk", IF_CLASS_CDC_DATA, usb_com_bulk_handle);
usb_com_interrupt_handle = new_create_dissector_handle(dissect_usb_com_interrupt, proto_usb_com);
dissector_add_uint("usb.interrupt", IF_CLASS_COMMUNICATIONS, usb_com_interrupt_handle);
mbim_control_handle = find_dissector("mbim.control");
mbim_descriptor_handle = find_dissector("mbim.descriptor");
mbim_bulk_handle = find_dissector("mbim.bulk");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
}
