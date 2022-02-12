static void
dissect_hpsw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *hp_tree = NULL;
proto_tree *tlv_tree = NULL;
proto_item *ti = NULL;
guint8 version;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HP");
col_set_str(pinfo->cinfo, COL_INFO, "HP Switch Protocol");
version = tvb_get_guint8(tvb, 0);
if (tree) {
guint16 offset =0;
ti = proto_tree_add_item(tree, proto_hpsw, tvb, 0, -1, ENC_NA);
hp_tree = proto_item_add_subtree(ti, ett_hpsw);
proto_tree_add_uint(hp_tree, hf_hpsw_version, tvb, 0, 1, version);
offset++;
proto_tree_add_item(hp_tree, hf_hpsw_type, tvb, 1, 1, ENC_BIG_ENDIAN);
offset++;
while ( tvb_reported_length_remaining(tvb, offset) > 0 )
{
guint8 type,length;
type = tvb_get_guint8(tvb, offset);
length = tvb_get_guint8(tvb, offset+1);
if (( length < 1 ) || ( length > tvb_length_remaining(tvb,offset+2)))
break;
ti = proto_tree_add_text(hp_tree,tvb,offset,length+2,"%s",
val_to_str(type,hpsw_tlv_type_vals,"Unknown TLV type: 0x%02x"));
tlv_tree=proto_item_add_subtree(ti,ett_hpsw_tlv);
proto_tree_add_uint(tlv_tree, hf_hpsw_tlvtype, tvb, offset, 1, type);
offset++;
proto_tree_add_uint(tlv_tree, hf_hpsw_tlvlength, tvb, offset, 1, length);
offset++;
dissect_hpsw_tlv(tvb,offset,length,tlv_tree,ti,type);
offset += length;
}
}
}
static void
dissect_hpsw_tlv(tvbuff_t *tvb, int offset, int length,
proto_tree *tree, proto_item *ti, guint8 type)
{
switch (type) {
case HPFOO_DEVICE_NAME:
if (length > 0) {
proto_item_set_text(ti, "Device Name: %s", tvb_format_text(tvb, offset, length - 1));
proto_tree_add_text(tree, tvb, offset, length, "Device Name: %s", tvb_format_text(tvb, offset, length - 1));
} else {
proto_item_set_text(ti, "Device Name: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Device Name: Bad length %u", length);
}
break;
case HPFOO_DEVICE_VERSION:
if (length > 0) {
proto_item_set_text(ti, "Version: %s", tvb_format_text(tvb, offset, length - 1));
proto_tree_add_text(tree, tvb, offset, length, "Version: %s", tvb_format_text(tvb, offset, length - 1));
} else {
proto_item_set_text(ti, "Version: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Version: Bad length %u", length);
}
break;
case HPFOO_CONFIG_NAME:
if (length > 0) {
proto_item_set_text(ti, "Config Name: %s", tvb_format_text(tvb, offset, length - 1));
proto_tree_add_text(tree, tvb, offset, length, "Config Name: %s", tvb_format_text(tvb, offset, length - 1));
} else {
proto_item_set_text(ti, "Config Name: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Config Name: Bad length %u", length);
}
break;
case HPFOO_ROOT_MAC_ADDR:
if (length == 6) {
const gchar *macstr = tvb_ether_to_str(tvb, offset);
proto_item_set_text(ti, "Root MAC Addr: %s", macstr);
proto_tree_add_text(tree, tvb, offset, length, "Root MAC Addr: %s", macstr);
} else {
proto_item_set_text(ti, "Root MAC Addr: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Root MAC Addr: Bad length %u", length);
}
break;
case HPFOO_IP_ADDR:
if (length == 4) {
const char *ipstr = tvb_ip_to_str(tvb, offset);
proto_item_set_text(ti, "IP Addr: %s", ipstr);
proto_tree_add_text(tree, tvb, offset, length, "IP Addr: %s", ipstr);
} else {
proto_item_set_text(ti, "IP Addr: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "IP Addr: Bad length %u", length);
}
break;
case HPFOO_FIELD_6:
if (length == 2) {
proto_item_set_text(ti, "Field 6: 0x%04x", tvb_get_ntohs(tvb,offset));
proto_tree_add_text(tree, tvb, offset, length, "Field 6: 0x%04x", tvb_get_ntohs(tvb,offset));
} else {
proto_item_set_text(ti, "Field 6: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Field 6: Bad length %u", length);
}
break;
case HPFOO_DOMAIN:
if (length > 0) {
proto_item_set_text(ti, "Domain: %s", tvb_format_text(tvb, offset, length - 1));
proto_tree_add_text(tree, tvb, offset, length, "Domain: %s", tvb_format_text(tvb, offset, length - 1));
} else {
proto_item_set_text(ti, "Domain: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Domain: Bad length %u", length);
}
break;
case HPFOO_FIELD_8:
if (length == 2) {
proto_item_set_text(ti, "Field 8: 0x%04x", tvb_get_ntohs(tvb,offset));
proto_tree_add_text(tree, tvb, offset, length, "Field 8: 0x%04x", tvb_get_ntohs(tvb,offset));
} else {
proto_item_set_text(ti, "Field 8: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Field 8: Bad length %u", length);
}
break;
case HPFOO_FIELD_9:
if (length == 2) {
proto_item_set_text(ti, "Field 9: 0x%04x", tvb_get_ntohs(tvb,offset));
proto_tree_add_text(tree, tvb, offset, length, "Field 9: 0x%04x", tvb_get_ntohs(tvb,offset));
} else {
proto_item_set_text(ti, "Field 9: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Field 9: Bad length %u", length);
}
break;
case HPFOO_FIELD_10:
if (length == 4) {
proto_item_set_text(ti, "Field 10: 0x%08x", tvb_get_ntohl(tvb,offset));
proto_tree_add_text(tree, tvb, offset, length, "Field 10: 0x%08x", tvb_get_ntohl(tvb,offset));
} else {
proto_item_set_text(ti, "Field 10: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Field 10: Bad length %u", length);
}
break;
case HPFOO_NEIGHBORS:
if (!(length % 6))
{ int i = length/6;
proto_item_set_text(ti, "Number of neighbor MAC Addresses: %u", i);
for ( ; i; i--)
{
const gchar *macstr = tvb_ether_to_str(tvb, offset);
proto_tree_add_text(tree, tvb, offset, length, "MAC Addr: %s", macstr);
offset += 6;
}
} else {
proto_item_set_text(ti, "Neighbors: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Neighbors: Bad length %u", length);
}
break;
case HPFOO_FIELD_12:
if (length == 1) {
proto_item_set_text(ti, "Field 12: 0x%02x", tvb_get_guint8(tvb,offset));
proto_tree_add_text(tree, tvb, offset, length, "Field 12: 0x%02x", tvb_get_guint8(tvb,offset));
} else {
proto_item_set_text(ti, "Field 12: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Field 12: Bad length %u", length);
}
break;
case HPFOO_DEVICE_ID:
if (length > 6) {
const gchar *macstr = tvb_ether_to_str(tvb, offset);
const gchar *idstr = tvb_bytes_to_str(tvb, offset+6, length-6);
proto_item_set_text(ti, "Device ID: %s / %s", macstr, idstr);
proto_tree_add_text(tree, tvb, offset, 10, "Device ID: %s / %s", macstr, idstr);
} else {
proto_item_set_text(ti, "Device ID: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Device ID: Bad length %u", length);
}
break;
case HPFOO_OWN_MAC_ADDR:
if (length == 6) {
const gchar *macstr = tvb_ether_to_str(tvb, offset);
proto_item_set_text(ti, "Own MAC Addr: %s", macstr);
proto_tree_add_text(tree, tvb, offset, length, "Own MAC Addr: %s", macstr);
} else {
proto_item_set_text(ti, "Own MAC Addr: Bad length %u", length);
proto_tree_add_text(tree, tvb, offset, length, "Own MAC Addr: Bad length %u", length);
}
break;
default:
proto_tree_add_text(tree, tvb, offset, length, "Data");
break;
}
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
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_hpsw,
&ett_hpsw_tlv
};
proto_hpsw = proto_register_protocol( "HP Switch Protocol", "HPSW", "hpsw");
proto_register_field_array(proto_hpsw, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("hpsw", dissect_hpsw, proto_hpsw);
}
void
proto_reg_handoff_hpsw(void)
{
dissector_handle_t hpsw_handle;
hpsw_handle = find_dissector("hpsw");
dissector_add_uint("hpext.dxsap", HPEXT_HPSW, hpsw_handle);
}
