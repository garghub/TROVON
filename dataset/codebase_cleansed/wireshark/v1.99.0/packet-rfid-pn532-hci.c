static gint
dissect_pn532_hci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *main_item;
proto_tree *main_tree;
gint offset = 0;
tvbuff_t *next_tvb;
guint16 packet_code;
guint16 length;
guint8 checksum;
usb_conv_info_t *usb_conv_info;
if (data == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
length = tvb_length_remaining(tvb, offset);
if (length < 6) return offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN532_HCI");
col_clear(pinfo->cinfo, COL_INFO);
main_item = proto_tree_add_item(tree, proto_pn532_hci, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_pn532_hci);
length = 0;
while (tvb_length_remaining(tvb, length) >= 2 && tvb_get_ntohs(tvb, length) != 0x00FF) {
length += 1;
}
if (length) {
proto_tree_add_item(main_tree, hf_preamble, tvb, offset, length, ENC_NA);
offset += length;
}
proto_tree_add_item(main_tree, hf_start_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
packet_code = tvb_get_ntohs(tvb, offset);
if (packet_code == 0x00FF) {
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet_code, packet_code_vals, "Unknown frame"));
proto_tree_add_item(main_tree, hf_packet_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (packet_code == 0xFF00) {
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet_code, packet_code_vals, "Unknown frame"));
proto_tree_add_item(main_tree, hf_packet_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (packet_code == 0x01FF) {
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet_code, packet_code_vals, "Unknown frame"));
proto_tree_add_item(main_tree, hf_packet_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(main_tree, hf_specific_application_level_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
} else if (packet_code == 0xFFFF) {
col_set_str(pinfo->cinfo, COL_INFO, "Extended Information Frame");
proto_tree_add_item(main_tree, hf_extended_length, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(main_tree, hf_length_checksum, tvb, offset, 1, ENC_NA);
checksum = (length >> 8) + (length & 0xFF) + tvb_get_guint8(tvb, offset);
if (checksum != 0) {
proto_tree_add_expert(main_tree, pinfo, &ei_invalid_length_checksum, tvb, offset, 1);
}
offset += 1;
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector_with_data(pn532_handle, next_tvb, pinfo, tree, usb_conv_info);
offset += length;
proto_tree_add_item(main_tree, hf_data_checksum, tvb, offset, 1, ENC_NA);
checksum = tvb_get_guint8(tvb, offset);
while (length) {
checksum += tvb_get_guint8(tvb, offset - length);
length -= 1;
}
if (checksum != 0) {
proto_tree_add_expert(main_tree, pinfo, &ei_invalid_data_checksum, tvb, offset, 1);
}
offset += 1;
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Normal Information Frame");
proto_tree_add_item(main_tree, hf_length, tvb, offset, 1, ENC_NA);
length = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(main_tree, hf_length_checksum, tvb, offset, 1, ENC_NA);
checksum = length + tvb_get_guint8(tvb, offset);
if (checksum != 0)
proto_tree_add_expert(main_tree, pinfo, &ei_invalid_length_checksum, tvb, offset, 1);
offset += 1;
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector_with_data(pn532_handle, next_tvb, pinfo, tree, usb_conv_info);
offset += length;
proto_tree_add_item(main_tree, hf_data_checksum, tvb, offset, 1, ENC_NA);
checksum = tvb_get_guint8(tvb, offset);
while (length) {
checksum += tvb_get_guint8(tvb, offset - length);
length -= 1;
}
if (checksum != 0) {
proto_tree_add_expert(main_tree, pinfo, &ei_invalid_data_checksum, tvb, offset, 1);
}
offset += 1;
}
length = 0;
if (tvb_length_remaining(tvb, offset) == 1) {
length = 1;
} else while (tvb_length_remaining(tvb, offset + length) >= 2 && tvb_get_ntohs(tvb, offset + length) != 0x00FF) {
length += 1;
}
if (length) {
proto_tree_add_item(main_tree, hf_postable, tvb, offset, length, ENC_NA);
offset += length;
}
if (tvb_length_remaining(tvb, offset)) {
proto_tree_add_item(main_tree, hf_ignored, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
offset += tvb_length_remaining(tvb, offset);
}
return offset;
}
void
proto_register_pn532_hci(void)
{
module_t *module;
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_preamble,
{ "Preamble", "pn532_hci.preamble",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_start_code,
{ "Start Code", "pn532_hci.start_code",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_packet_code,
{ "Packet Code", "pn532_hci.packet_code",
FT_UINT16, BASE_HEX, VALS(packet_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_length,
{ "Length", "pn532_hci.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_extended_length,
{ "Extended Length", "pn532_hci.extended_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_length_checksum,
{ "Length Checksum", "pn532_hci.length_checksum",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_data_checksum,
{ "Data Checksum", "pn532_hci.data_checksum",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_specific_application_level_error_code,
{ "Specific Application Level Error Code","pn532_hci.specific_application_level_error_code",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_postable,
{ "Postamble", "pn532_hci.postamble",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ignored,
{ "Ignored", "pn532_hci.ignored",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_pn532_hci
};
static ei_register_info ei[] = {
{ &ei_invalid_length_checksum, { "pn532_hci.expert.invalid_length_checksum", PI_PROTOCOL, PI_WARN, "Invalid Length Checksum", EXPFILL }},
{ &ei_invalid_data_checksum, { "pn532_hci.expert.invalid_data_checksum", PI_PROTOCOL, PI_WARN, "Invalid Data Checksum", EXPFILL }},
};
proto_pn532_hci = proto_register_protocol("NXP PN532 HCI", "PN532_HCI", "pn532_hci");
pn532_hci_handle = new_register_dissector("pn532_hci", dissect_pn532_hci, proto_pn532_hci);
proto_register_field_array(proto_pn532_hci, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_module = expert_register_protocol(proto_pn532_hci);
expert_register_field_array(expert_module, ei, array_length(ei));
module = prefs_register_protocol(proto_pn532_hci, NULL);
prefs_register_static_text_preference(module, "version",
"PN532 HCI protocol version is based on: \"UM0701-02; PN532 User Manual\"",
"Version of protocol supported by this dissector.");
}
void
proto_reg_handoff_pn532_hci(void)
{
pn532_handle = find_dissector("pn532");
dissector_add_uint("usb.product", (0x04e6 << 16) | 0x5591, pn532_hci_handle);
dissector_add_for_decode_as("usb.device", pn532_hci_handle);
dissector_add_for_decode_as("usb.protocol", pn532_hci_handle);
}
