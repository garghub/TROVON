static void
dissect_hpsw_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length,
proto_tree *tree, proto_item *ti, guint8 type)
{
switch (type) {
case HPFOO_DEVICE_NAME:
if (length > 0) {
proto_tree_add_item(tree, hf_hpsw_device_name, tvb, offset, length, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Device Name: Bad length %u", length);
}
break;
case HPFOO_DEVICE_VERSION:
if (length > 0) {
proto_tree_add_item(tree, hf_hpsw_device_version, tvb, offset, length, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Version: Bad length %u", length);
}
break;
case HPFOO_CONFIG_NAME:
if (length > 0) {
proto_tree_add_item(tree, hf_hpsw_config_name, tvb, offset, length, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Config Name: Bad length %u", length);
}
break;
case HPFOO_ROOT_MAC_ADDR:
if (length == 6) {
proto_tree_add_item(tree, hf_hpsw_root_mac_addr, tvb, offset, length, ENC_NA);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Root MAC Addr: Bad length %u", length);
}
break;
case HPFOO_IP_ADDR:
if (length == 4) {
proto_tree_add_item(tree, hf_hpsw_ip_addr, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "IP Addr: Bad length %u", length);
}
break;
case HPFOO_FIELD_6:
if (length == 2) {
proto_tree_add_item(tree, hf_hpsw_field_6, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Field 6: Bad length %u", length);
}
break;
case HPFOO_DOMAIN:
if (length > 0) {
proto_tree_add_item(tree, hf_hpsw_domain, tvb, offset, length, ENC_NA|ENC_ASCII);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Domain: Bad length %u", length);
}
break;
case HPFOO_FIELD_8:
if (length == 2) {
proto_tree_add_item(tree, hf_hpsw_field_8, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Field 8: Bad length %u", length);
}
break;
case HPFOO_FIELD_9:
if (length == 2) {
proto_tree_add_item(tree, hf_hpsw_field_9, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Field 9: Bad length %u", length);
}
break;
case HPFOO_FIELD_10:
if (length == 4) {
proto_tree_add_item(tree, hf_hpsw_field_10, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Field 10: Bad length %u", length);
}
break;
case HPFOO_NEIGHBORS:
if (!(length % 6))
{ int i = length/6;
proto_item_set_text(proto_tree_get_parent(tree), "Number of neighbor MAC Addresses: %u", i);
for ( ; i; i--)
{
proto_tree_add_item(tree, hf_hpsw_neighbor_mac_addr, tvb, offset, 6, ENC_NA);
offset += 6;
}
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Neighbors: Bad length %u", length);
}
break;
case HPFOO_FIELD_12:
if (length == 1) {
proto_tree_add_item(tree, hf_hpsw_field_12, tvb, offset, length, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Field 12: Bad length %u", length);
}
break;
case HPFOO_DEVICE_ID:
if (length > 6) {
proto_tree_add_item(tree, hf_hpsw_device_id, tvb, offset, 6, ENC_NA);
proto_tree_add_item(tree, hf_hpsw_device_id_data, tvb, offset+6, length-6, ENC_NA);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Device ID: Bad length %u", length);
}
break;
case HPFOO_OWN_MAC_ADDR:
if (length == 6) {
proto_tree_add_item(tree, hf_hpsw_own_mac_addr, tvb, offset, length, ENC_NA);
} else {
expert_add_info_format(pinfo, ti, &ei_hpsw_tlvlength_bad, "Own MAC Addr: Bad length %u", length);
}
break;
default:
proto_tree_add_item(tree, hf_hpsw_data, tvb, offset, length, ENC_NA);
break;
}
}
static int
dissect_hpsw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *hp_tree;
proto_tree *tlv_tree;
proto_item *ti;
guint8 version;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HP");
col_set_str(pinfo->cinfo, COL_INFO, "HP Switch Protocol");
version = tvb_get_guint8(tvb, 0);
ti = proto_tree_add_item(tree, proto_hpsw, tvb, 0, -1, ENC_NA);
hp_tree = proto_item_add_subtree(ti, ett_hpsw);
proto_tree_add_uint(hp_tree, hf_hpsw_version, tvb, 0, 1, version);
offset += 1;
proto_tree_add_item(hp_tree, hf_hpsw_type, tvb, 1, 1, ENC_BIG_ENDIAN);
offset += 1;
while ( tvb_reported_length_remaining(tvb, offset) > 0 )
{
guint8 type, length;
type = tvb_get_guint8(tvb, offset);
length = tvb_get_guint8(tvb, offset+1);
if (( length < 1 ) || ( length > tvb_reported_length_remaining(tvb, offset+2)))
break;
tlv_tree = proto_tree_add_subtree(hp_tree, tvb, offset, length+2, ett_hpsw_tlv, NULL,
val_to_str(type, hpsw_tlv_type_vals, "Unknown TLV type: 0x%02x"));
proto_tree_add_uint(tlv_tree, hf_hpsw_tlvtype, tvb, offset, 1, type);
offset += 1;
ti = proto_tree_add_uint(tlv_tree, hf_hpsw_tlvlength, tvb, offset, 1, length);
offset += 1;
dissect_hpsw_tlv(tvb, pinfo, offset, length, tlv_tree, ti, type);
offset += length;
}
return tvb_captured_length(tvb);
}
void
proto_register_hpsw(void)
{
static hf_register_info hf[] = {
{ &hf_hpsw_version,
{ "Version", "hpsw.version", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_type,
{ "Type", "hpsw.type", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_tlvtype,
{ "Type", "hpsw.tlv_type", FT_UINT8, BASE_HEX,
VALS(hpsw_tlv_type_vals), 0x0, NULL, HFILL }},
{ &hf_hpsw_tlvlength,
{ "Length", "hpsw.tlv_len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_device_name,
{ "Device Name", "hpsw.device_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_device_version,
{ "Version", "hpsw.device_version", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_config_name,
{ "Config Name", "hpsw.config_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_root_mac_addr,
{ "Root MAC Addr", "hpsw.root_mac_addr", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_ip_addr,
{ "IP Addr", "hpsw.ip_addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_field_6,
{ "Field 6", "hpsw.field_6", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_domain,
{ "Domain", "hpsw.domain", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_field_8,
{ "Field 8", "hpsw.field_8", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_field_9,
{ "Field 9", "hpsw.field_9", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_field_10,
{ "Field 10", "hpsw.field_10", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_neighbor_mac_addr,
{ "MAC Addr", "hpsw.neighbor_mac_addr", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_field_12,
{ "Field 12", "hpsw.field_12", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_own_mac_addr,
{ "Own MAC Addr", "hpsw.own_mac_addr", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_device_id,
{ "Device ID", "hpsw.device_id", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_device_id_data,
{ "Data", "hpsw.device_id_data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_hpsw_data,
{ "Data", "hpsw.data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_hpsw,
&ett_hpsw_tlv
};
static ei_register_info ei[] = {
{ &ei_hpsw_tlvlength_bad, { "hpsw.tlv_len.bad", PI_PROTOCOL, PI_WARN, "Bad length", EXPFILL }},
};
expert_module_t* expert_hpsw;
proto_hpsw = proto_register_protocol( "HP Switch Protocol", "HPSW", "hpsw");
proto_register_field_array(proto_hpsw, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_hpsw = expert_register_protocol(proto_hpsw);
expert_register_field_array(expert_hpsw, ei, array_length(ei));
hpsw_handle = register_dissector("hpsw", dissect_hpsw, proto_hpsw);
}
void
proto_reg_handoff_hpsw(void)
{
dissector_add_uint("hpext.dxsap", HPEXT_HPSW, hpsw_handle);
}
