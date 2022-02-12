static int
dissect_usb_com_descriptor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 offset = 0, type, subtype;
proto_tree *subtree;
proto_item *ti;
ti = proto_tree_add_text(tree, tvb, offset, -1, "COMMUNICATIONS DESCRIPTOR");
subtree = proto_item_add_subtree(ti, ett_usb_com);
dissect_usb_descriptor_header(subtree, tvb, 0, &usb_com_descriptor_type_vals_ext);
type = tvb_get_guint8(tvb, 1);
switch (type) {
case CS_INTERFACE:
subtype = tvb_get_guint8(tvb, 2);
proto_tree_add_uint(subtree, hf_usb_com_descriptor_subtype, tvb, 2, 1, subtype);
switch (subtype) {
case 0x00:
proto_tree_add_item(subtree, hf_usb_com_descriptor_cdc, tvb, 3, 2, ENC_LITTLE_ENDIAN);
offset = 5;
break;
case 0x1b:
case 0x1c:
offset = call_dissector_only(mbim_descriptor_handle, tvb, pinfo, subtree, NULL);
break;
default:
break;
}
break;
case CS_ENDPOINT:
default:
break;
}
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_item(subtree, hf_usb_com_descriptor_payload, tvb, offset, -1, ENC_NA);
}
return tvb_length(tvb);
}
static int
dissect_usb_com_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
usb_conv_info_t *usb_conv_info;
proto_tree *subtree;
proto_item *ti;
gint offset = 0;
usb_conv_info = (usb_conv_info_t *)pinfo->usb_conv_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBCOM");
ti = proto_tree_add_item(tree, proto_usb_com, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_usb_com);
if (usb_conv_info) {
ti = proto_tree_add_uint(subtree, hf_usb_com_control_subclass, tvb, 0, 0,
usb_conv_info->interfaceSubclass);
PROTO_ITEM_SET_GENERATED(ti);
switch (usb_conv_info->interfaceSubclass)
{
case COM_SUBCLASS_MBIM:
offset = call_dissector_only(mbim_control_handle, tvb, pinfo, tree, NULL);
break;
default:
break;
}
}
if (tvb_reported_length_remaining(tvb, offset) != 0) {
proto_tree_add_item(subtree, hf_usb_com_control_payload, tvb, offset, -1, ENC_NA);
}
return tvb_length(tvb);
}
static int
dissect_usb_com_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
usb_conv_info_t *usb_conv_info;
usb_conv_info = (usb_conv_info_t *)pinfo->usb_conv_info;
if (usb_conv_info) {
switch (usb_conv_info->interfaceProtocol)
{
case 0x01:
case 0x02:
return call_dissector_only(mbim_bulk_handle, tvb, pinfo, tree, NULL);
break;
default:
break;
}
}
return call_dissector_only(eth_withoutfcs_handle, tvb, pinfo, tree, NULL);
}
void
proto_register_usb_com(void)
{
static hf_register_info hf[] = {
{ &hf_usb_com_descriptor_subtype,
{ "bDescriptorSubtype", "usbcom.descriptor.subtype", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&usb_com_descriptor_subtype_vals_ext, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_cdc,
{ "bcdCDC", "usbcom.descriptor.cdc", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_descriptor_payload,
{ "Payload", "usbcom.descriptor.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_com_control_subclass,
{ "Subclass", "usbcom.control.subclass", FT_UINT8, BASE_HEX,
VALS(usb_com_subclass_vals), 0, NULL, HFILL }},
{ &hf_usb_com_control_payload,
{ "Payload", "usbcom.control.payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }}
};
static gint *usb_com_subtrees[] = {
&ett_usb_com
};
proto_usb_com = proto_register_protocol("USB Communications and CDC Control", "USBCOM", "usbcom");
proto_register_field_array(proto_usb_com, hf, array_length(hf));
proto_register_subtree_array(usb_com_subtrees, array_length(usb_com_subtrees));
}
void
proto_reg_handoff_usb_com(void)
{
dissector_handle_t usb_com_descriptor_handle, usb_com_control_handle, usb_com_bulk_handle;
usb_com_descriptor_handle = new_create_dissector_handle(dissect_usb_com_descriptor, proto_usb_com);
dissector_add_uint("usb.descriptor", IF_CLASS_COMMUNICATIONS, usb_com_descriptor_handle);
usb_com_control_handle = new_create_dissector_handle(dissect_usb_com_control, proto_usb_com);
dissector_add_uint("usb.control", IF_CLASS_COMMUNICATIONS, usb_com_control_handle);
usb_com_bulk_handle = new_create_dissector_handle(dissect_usb_com_bulk, proto_usb_com);
dissector_add_uint("usb.bulk", IF_CLASS_CDC_DATA, usb_com_bulk_handle);
mbim_control_handle = find_dissector("mbim.control");
mbim_descriptor_handle = find_dissector("mbim.descriptor");
mbim_bulk_handle = find_dissector("mbim.bulk");
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
}
