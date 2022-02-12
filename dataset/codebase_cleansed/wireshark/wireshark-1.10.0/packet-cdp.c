static void
dissect_cdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *checksum_item;
proto_tree *cdp_tree = NULL, *checksum_tree;
int offset = 0;
guint16 type;
guint16 length, packet_checksum, computed_checksum, data_length;
gboolean checksum_good, checksum_bad;
proto_item *tlvi = NULL;
proto_tree *tlv_tree = NULL;
int real_length;
guint32 naddresses;
guint32 power_avail_len, power_avail;
guint32 power_req_len, power_req;
int addr_length;
guint32 ip_addr;
vec_t cksum_vec[1];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CDP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_cdp, tvb, offset, -1, ENC_NA);
cdp_tree = proto_item_add_subtree(ti, ett_cdp);
proto_tree_add_item(cdp_tree, hf_cdp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint_format_value(cdp_tree, hf_cdp_ttl, tvb, offset, 1,
tvb_get_guint8(tvb, offset),
"%u seconds",
tvb_get_guint8(tvb, offset));
offset += 1;
} else {
offset += 2;
}
packet_checksum = tvb_get_ntohs(tvb, offset);
data_length = tvb_reported_length(tvb);
if (data_length & 1) {
guint8 *padded_buffer;
padded_buffer = (guint8 *)ep_alloc(data_length+1);
tvb_memcpy(tvb, padded_buffer, 0, data_length);
padded_buffer[data_length] = padded_buffer[data_length-1];
padded_buffer[data_length-1] = 0;
if (padded_buffer[data_length] & 0x80) {
padded_buffer[data_length]--;
padded_buffer[data_length-1]--;
}
cksum_vec[0].ptr = padded_buffer;
cksum_vec[0].len = data_length+1;
} else {
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, data_length);
cksum_vec[0].len = data_length;
}
computed_checksum = in_cksum(cksum_vec, 1);
checksum_good = (computed_checksum == 0);
checksum_bad = !checksum_good;
if (checksum_good) {
checksum_item = proto_tree_add_uint_format(cdp_tree,
hf_cdp_checksum, tvb, offset, 2, packet_checksum,
"Checksum: 0x%04x [correct]", packet_checksum);
} else {
checksum_item = proto_tree_add_uint_format(cdp_tree,
hf_cdp_checksum, tvb, offset, 2, packet_checksum,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
packet_checksum,
in_cksum_shouldbe(packet_checksum, computed_checksum));
}
checksum_tree = proto_item_add_subtree(checksum_item, ett_cdp_checksum);
checksum_item = proto_tree_add_boolean(checksum_tree, hf_cdp_checksum_good,
tvb, offset, 2, checksum_good);
PROTO_ITEM_SET_GENERATED(checksum_item);
checksum_item = proto_tree_add_boolean(checksum_tree, hf_cdp_checksum_bad,
tvb, offset, 2, checksum_bad);
PROTO_ITEM_SET_GENERATED(checksum_item);
offset += 2;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
type = tvb_get_ntohs(tvb, offset + TLV_TYPE);
length = tvb_get_ntohs(tvb, offset + TLV_LENGTH);
if (length < 4) {
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset, 4,
"TLV with invalid length %u (< 4)",
length);
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
break;
}
switch (type) {
case TYPE_DEVICE_ID:
col_append_fstr(pinfo->cinfo, COL_INFO,
"Device ID: %s ",
tvb_format_stringzpad(tvb, offset + 4, length - 4));
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "Device ID: %s",
tvb_format_stringzpad(tvb, offset + 4, length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_deviceid, tvb, offset + 4, length - 4, ENC_ASCII|ENC_NA);
}
offset += length;
break;
case TYPE_PORT_ID:
real_length = length;
if (tvb_get_guint8(tvb, offset + real_length) != 0x00) {
real_length = length + 3;
}
col_append_fstr(pinfo->cinfo, COL_INFO,
"Port ID: %s ",
tvb_format_stringzpad(tvb, offset + 4,
length - 4));
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
real_length, "Port ID: %s",
tvb_format_text(tvb, offset + 4, real_length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_portid, tvb, offset + 4, real_length - 4, ENC_ASCII|ENC_NA);
}
offset += real_length;
break;
case TYPE_ADDRESS:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "Addresses");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
naddresses = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset, 4,
"Number of addresses: %u", naddresses);
}
offset += 4;
length -= 4;
while (naddresses != 0) {
addr_length = dissect_address_tlv(tvb, offset, length,
tlv_tree);
if (addr_length < 0)
break;
offset += addr_length;
length -= addr_length;
naddresses--;
}
offset += length;
break;
case TYPE_CAPABILITIES:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "Capabilities");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
dissect_capabilities(tvb, offset, length, tlv_tree);
offset += length;
break;
case TYPE_IOS_VERSION:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "Software Version");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
add_multi_line_string_to_tree(tlv_tree, tvb, offset + 4,
length - 4, "Software Version: ");
}
offset += length;
break;
case TYPE_PLATFORM:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Platform: %s",
tvb_format_text(tvb, offset + 4, length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_platform, tvb, offset + 4, length - 4, ENC_ASCII|ENC_NA);
}
offset += length;
break;
case TYPE_IP_PREFIX:
if (length == 8) {
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "ODR Default gateway: %s",
tvb_ip_to_str(tvb, offset+4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset+4, 4,
"ODR Default gateway = %s",
tvb_ip_to_str(tvb, offset+4));
}
offset += 8;
} else {
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "IP Prefixes: %d",length/5);
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
while (length > 0) {
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset, 5,
"IP Prefix = %s/%u",
tvb_ip_to_str(tvb, offset),
tvb_get_guint8(tvb,offset+4));
}
offset += 5;
length -= 5;
}
}
break;
case TYPE_PROTOCOL_HELLO:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset,length, "Protocol Hello: %s",
val_to_str(tvb_get_ntohs(tvb, offset+7), type_hello_vals, "Unknown (0x%04x)"));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset+4, 3,
"OUI: 0x%06X (%s)",
tvb_get_ntoh24(tvb,offset+4),
val_to_str_const(tvb_get_ntoh24(tvb,offset+4), oui_vals, "Unknown"));
proto_tree_add_text(tlv_tree, tvb, offset+7, 2,
"Protocol ID: 0x%04X (%s)",
tvb_get_ntohs(tvb, offset+7),
val_to_str_const(tvb_get_ntohs(tvb, offset+7), type_hello_vals, "Unknown"));
switch(tvb_get_ntohs(tvb, offset+7)) {
case TYPE_HELLO_CLUSTER_MGMT:
ip_addr = tvb_get_ipv4(tvb, offset+9);
proto_tree_add_text(tlv_tree, tvb, offset+9, 4,
"Cluster Master IP: %s",ip_to_str((guint8 *)&ip_addr));
ip_addr = tvb_get_ipv4(tvb, offset+13);
proto_tree_add_text(tlv_tree, tvb, offset+13, 4,
"UNKNOWN (IP?): 0x%08X (%s)",
ip_addr, ip_to_str((guint8 *)&ip_addr));
proto_tree_add_text(tlv_tree, tvb, offset+17, 1,
"Version?: 0x%02X",
tvb_get_guint8(tvb, offset+17));
proto_tree_add_text(tlv_tree, tvb, offset+18, 1,
"Sub Version?: 0x%02X",
tvb_get_guint8(tvb, offset+18));
proto_tree_add_text(tlv_tree, tvb, offset+19, 1,
"Status?: 0x%02X",
tvb_get_guint8(tvb, offset+19));
proto_tree_add_text(tlv_tree, tvb, offset+20, 1,
"UNKNOWN: 0x%02X",
tvb_get_guint8(tvb, offset+20));
proto_tree_add_text(tlv_tree, tvb, offset+21, 6,
"Cluster Commander MAC: %s",
tvb_ether_to_str(tvb, offset+21));
proto_tree_add_text(tlv_tree, tvb, offset+27, 6,
"Switch's MAC: %s",
tvb_ether_to_str(tvb, offset+27));
proto_tree_add_text(tlv_tree, tvb, offset+33, 1,
"UNKNOWN: 0x%02X",
tvb_get_guint8(tvb, offset+33));
proto_tree_add_text(tlv_tree, tvb, offset+34, 2,
"Management VLAN: %d",
tvb_get_ntohs(tvb, offset+34));
break;
default:
proto_tree_add_text(tlv_tree, tvb, offset + 9,
length - 9, "Unknown");
break;
}
}
offset += length;
break;
case TYPE_VTP_MGMT_DOMAIN:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "VTP Management Domain: %s",
tvb_format_text(tvb, offset + 4, length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "VTP Management Domain: %s",
tvb_format_text(tvb, offset + 4, length - 4));
}
offset += length;
break;
case TYPE_NATIVE_VLAN:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Native VLAN: %u",
tvb_get_ntohs(tvb, offset + 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Native VLAN: %u",
tvb_get_ntohs(tvb, offset + 4));
}
offset += length;
break;
case TYPE_DUPLEX:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Duplex: %s",
tvb_get_guint8(tvb, offset + 4) ?
"Full" : "Half" );
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Duplex: %s",
tvb_get_guint8(tvb, offset + 4) ?
"Full" : "Half" );
}
offset += length;
break;
case TYPE_VOIP_VLAN_REPLY:
if (tree) {
if (length >= 7) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset, length,
"VoIP VLAN Reply: %u", tvb_get_ntohs(tvb, offset + 5));
} else {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "VoIP VLAN Reply");
}
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
1, "Data");
if (length >= 7) {
proto_tree_add_text(tlv_tree, tvb, offset + 5,
2, "Voice VLAN: %u",
tvb_get_ntohs(tvb, offset + 5));
}
}
offset += length;
break;
case TYPE_VOIP_VLAN_QUERY:
if (tree) {
if (length >= 7) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "VoIP VLAN Query: %u", tvb_get_ntohs(tvb, offset + 5));
} else {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "VoIP VLAN Query");
}
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
1, "Data");
if (length >= 7) {
proto_tree_add_text(tlv_tree, tvb, offset + 5,
2, "Voice VLAN: %u",
tvb_get_ntohs(tvb, offset + 5));
}
}
offset += length;
break;
case TYPE_POWER:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Power Consumption: %u mW",
tvb_get_ntohs(tvb, offset + 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Power Consumption: %u mW",
tvb_get_ntohs(tvb, offset + 4));
}
offset += length;
break;
case TYPE_MTU:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "MTU: %u",
tvb_get_ntohl(tvb,offset + 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "MTU: %u",
tvb_get_ntohl(tvb,offset + 4));
}
offset += length;
break;
case TYPE_TRUST_BITMAP:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Trust Bitmap: 0x%02X",
tvb_get_guint8(tvb, offset + 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Trust Bitmap: %02x",
tvb_get_guint8(tvb, offset + 4));
}
offset += length;
break;
case TYPE_UNTRUSTED_COS:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Untrusted port CoS: 0x%02X",
tvb_get_guint8(tvb, offset + 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Untrusted port CoS: %02x",
tvb_get_guint8(tvb, offset + 4));
}
offset += length;
break;
case TYPE_SYSTEM_NAME:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "System Name: %s",
tvb_format_text(tvb, offset + 4, length - 4));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "System Name: %s",
tvb_format_text(tvb, offset + 4, length - 4));
}
offset += length;
break;
case TYPE_SYSTEM_OID:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "System Object Identifier");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "System Object Identifier: %s",
tvb_bytes_to_str(tvb, offset + 4, length - 4));
}
offset += length;
break;
case TYPE_MANAGEMENT_ADDR:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Management Addresses");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
naddresses = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset, 4,
"Number of addresses: %u", naddresses);
}
offset += 4;
length -= 4;
while (naddresses != 0) {
addr_length = dissect_address_tlv(tvb, offset, length,
tlv_tree);
if (addr_length < 0)
break;
offset += addr_length;
length -= addr_length;
naddresses--;
}
offset += length;
break;
case TYPE_LOCATION:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Location: %s",
tvb_format_text(tvb, offset + 5, length - 5));
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
1 , "UNKNOWN: 0x%02X",
tvb_get_guint8(tvb, offset + 4));
proto_tree_add_text(tlv_tree, tvb, offset + 5,
length - 5, "Location: %s",
tvb_format_text(tvb, offset + 5, length - 5));
}
offset += length;
break;
case TYPE_POWER_REQUESTED:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Power Request: ");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
2, "Request-ID: %u",
tvb_get_ntohs(tvb, offset + 4));
proto_tree_add_text(tlv_tree, tvb, offset + 6,
2, "Management-ID: %u",
tvb_get_ntohs(tvb, offset + 6));
}
power_req_len = (tvb_get_ntohs(tvb, offset + TLV_LENGTH)) - 8;
offset += 8;
while(power_req_len) {
if (power_req_len > 4) {
power_req = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset,
4, "Power Requested: %u mW", power_req);
proto_item_append_text(tlvi, "%u mW, ", power_req);
}
power_req_len -= 4;
offset += 4;
} else {
if (power_req_len == 4) {
power_req = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset,
4, "Power Requested: %u mW", power_req);
proto_item_append_text(tlvi, "%u mW", power_req);
}
}
offset += power_req_len;
break;
}
}
break;
case TYPE_POWER_AVAILABLE:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "Power Available: ");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
2, "Request-ID: %u",
tvb_get_ntohs(tvb, offset + 4));
proto_tree_add_text(tlv_tree, tvb, offset + 6,
2, "Management-ID: %u",
tvb_get_ntohs(tvb, offset + 6));
}
power_avail_len = (tvb_get_ntohs(tvb, offset + TLV_LENGTH)) - 8;
offset += 8;
while(power_avail_len) {
if (power_avail_len >= 4) {
power_avail = tvb_get_ntohl(tvb, offset);
if (tree) {
proto_tree_add_text(tlv_tree, tvb, offset,
4, "Power Available: %u mW", power_avail);
proto_item_append_text(tlvi, "%u mW, ", power_avail);
}
power_avail_len -= 4;
offset += 4;
} else {
offset += power_avail_len;
break;
}
}
break;
case TYPE_NRGYZ:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb,
offset, length, "EnergyWise");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tlv_tree, tvb, offset + 4,
20, "Encrypted Data");
proto_tree_add_text(tlv_tree, tvb, offset + 24,
4, "Unknown (Seen Sequence?): %u",
tvb_get_ntohl(tvb, offset + 24));
proto_tree_add_text(tlv_tree, tvb, offset + 28,
4, "Sequence Number: %u",
tvb_get_ntohl(tvb, offset + 28));
proto_tree_add_text(tlv_tree, tvb, offset + 32,
16, "Model Number: %s",
tvb_format_stringzpad(tvb, offset + 32, 16));
proto_tree_add_text(tlv_tree, tvb, offset + 48,
2, "Unknown Pad: %x",
tvb_get_ntohs(tvb, offset + 48));
proto_tree_add_text(tlv_tree, tvb, offset + 50,
3, "Hardware Version ID: %s",
tvb_format_stringzpad(tvb, offset + 50, 3));
proto_tree_add_text(tlv_tree, tvb, offset + 53,
11, "System Serial Number: %s",
tvb_format_stringzpad(tvb, offset + 53, 11));
proto_tree_add_text(tlv_tree, tvb, offset + 64,
8, "Unknown Values");
proto_tree_add_text(tlv_tree, tvb, offset + 72,
2, "Length of TLV table: %u",
tvb_get_ntohs(tvb, offset + 72));
proto_tree_add_text(tlv_tree, tvb, offset + 74,
2, "Number of TLVs in table: %u",
tvb_get_ntohs(tvb, offset + 74));
dissect_nrgyz_tlv(tvb, offset + 76,
tvb_get_ntohs(tvb, offset + 72),
tvb_get_ntohs(tvb, offset + 74),
tlv_tree);
}
offset += length;
break;
case TYPE_SPARE_POE:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset, length,
"Spare Pair PoE");
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
dissect_spare_poe_tlv(tvb, offset, length, tlv_tree);
offset += length;
break;
default:
if (tree) {
tlvi = proto_tree_add_text(cdp_tree, tvb, offset,
length, "Type: %s, length: %u",
val_to_str(type, type_vals, "Unknown (0x%04x)"),
length);
tlv_tree = proto_item_add_subtree(tlvi, ett_cdp_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_tlvtype, tvb, offset + TLV_TYPE, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_tlvlength, tvb, offset + TLV_LENGTH, 2, ENC_BIG_ENDIAN);
if (length > 4) {
proto_tree_add_text(tlv_tree, tvb, offset + 4,
length - 4, "Data");
} else {
return;
}
}
offset += length;
}
}
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo, cdp_tree);
}
static int
dissect_address_tlv(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
proto_item *ti;
proto_tree *address_tree;
guint8 protocol_type;
guint8 protocol_length;
int nlpid;
const char *protocol_str;
guint16 address_length;
const char *address_type_str;
const char *address_str;
if (length < 1)
return -1;
ti = proto_tree_add_text(tree, tvb, offset, length, "Truncated address");
address_tree = proto_item_add_subtree(ti, ett_cdp_address);
protocol_type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(address_tree, tvb, offset, 1, "Protocol type: %s",
val_to_str(protocol_type, proto_type_vals, "Unknown (0x%02x)"));
offset += 1;
length -= 1;
if (length < 1)
return -1;
protocol_length = tvb_get_guint8(tvb, offset);
proto_tree_add_text(address_tree, tvb, offset, 1, "Protocol length: %u",
protocol_length);
offset += 1;
length -= 1;
if (length < protocol_length) {
if (length != 0) {
proto_tree_add_text(address_tree, tvb, offset, length,
"Protocol: %s (truncated)",
tvb_bytes_to_str(tvb, offset, length));
}
return -1;
}
protocol_str = NULL;
if ((protocol_type == PROTO_TYPE_NLPID) && (protocol_length == 1)) {
nlpid = tvb_get_guint8(tvb, offset);
protocol_str = val_to_str(nlpid, nlpid_vals, "Unknown (0x%02x)");
} else
nlpid = -1;
if (protocol_str == NULL)
protocol_str = tvb_bytes_to_str(tvb, offset, protocol_length);
proto_tree_add_text(address_tree, tvb, offset, protocol_length,
"Protocol: %s", protocol_str);
offset += protocol_length;
length -= protocol_length;
if (length < 2)
return -1;
address_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(address_tree, tvb, offset, 2, "Address length: %u",
address_length);
offset += 2;
length -= 2;
if (length < address_length) {
if (length != 0) {
proto_tree_add_text(address_tree, tvb, offset, length,
"Address: %s (truncated)",
tvb_bytes_to_str(tvb, offset, length));
}
return -1;
}
length = 2 + protocol_length + 2 + address_length;
address_type_str = NULL;
address_str = NULL;
if ((protocol_type == PROTO_TYPE_NLPID) && (protocol_length == 1)) {
switch (nlpid) {
case NLPID_IP:
if (address_length == 4) {
address_type_str = "IP address";
address_str = tvb_ip_to_str(tvb, offset);
}
break;
}
}
if (address_type_str == NULL)
address_type_str = "Address";
if (address_str == NULL) {
address_str = tvb_bytes_to_str(tvb, offset, address_length);
}
proto_item_set_text(ti, "%s: %s", address_type_str, address_str);
proto_tree_add_text(address_tree, tvb, offset, address_length, "%s: %s",
address_type_str, address_str);
return 2 + protocol_length + 2 + address_length;
}
static void
dissect_capabilities(tvbuff_t *tvb, int offset, int length, proto_tree *tree)
{
proto_item *ti;
proto_tree *capabilities_tree;
if (length < 4)
return;
ti = proto_tree_add_item(tree, hf_cdp_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
capabilities_tree = proto_item_add_subtree(ti, ett_cdp_capabilities);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_router, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_trans_bridge, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_src_bridge, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_switch, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_host, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_igmp_capable, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_tree, hf_cdp_capabilities_repeater, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_nrgyz_tlv(tvbuff_t *tvb, int offset, guint16 length, guint16 num,
proto_tree *tree)
{
guint32 tlvt, tlvl, ip_addr;
proto_item *it = NULL;
proto_tree *etree = NULL;
char const *ttext = NULL;
while (num-- && (length >= 8)) {
tlvt = tvb_get_ntohl(tvb, offset);
tlvl = tvb_get_ntohl(tvb, offset + 4);
if (length < tlvl)
break;
length -= tlvl;
if (tlvl < 8) {
proto_tree_add_text(tree, tvb, offset, 8,
"TLV with invalid length %u (< 8)",
tlvl);
offset += 8;
break;
}
else {
ttext = val_to_str(tlvt, type_nrgyz_vals, "Unknown (0x%04x)");
switch (tlvt) {
case TYPE_NRGYZ_ROLE:
case TYPE_NRGYZ_DOMAIN:
case TYPE_NRGYZ_NAME:
it = proto_tree_add_text(tree, tvb, offset,
tlvl, "EnergyWise %s: %s", ttext,
tvb_format_stringzpad(tvb, offset + 8, tlvl - 8)
);
break;
case TYPE_NRGYZ_REPLYTO:
ip_addr = tvb_get_ipv4(tvb, offset + 12);
it = proto_tree_add_text(tree, tvb, offset,
tlvl, "EnergyWise %s: %s port %u",
ttext,
ip_to_str((guint8 *)&ip_addr),
tvb_get_ntohs(tvb, offset + 10)
);
break;
default:
it = proto_tree_add_text(tree, tvb, offset,
tlvl, "EnergyWise %s TLV", ttext);
}
etree = proto_item_add_subtree(it, ett_cdp_nrgyz_tlv);
proto_tree_add_text(etree, tvb, offset, 4,
"TLV Type: %x (%s)", tlvt, ttext);
proto_tree_add_text(etree, tvb, offset + 4, 4,
"TLV Length: %u", tlvl);
switch (tlvt) {
case TYPE_NRGYZ_ROLE:
case TYPE_NRGYZ_DOMAIN:
case TYPE_NRGYZ_NAME:
proto_tree_add_text(etree, tvb, offset + 8,
tlvl - 8, "%s %s", ttext,
tvb_format_stringzpad(tvb, offset + 8, tlvl - 8)
);
break;
case TYPE_NRGYZ_REPLYTO:
ip_addr = tvb_get_ipv4(tvb, offset + 12);
proto_tree_add_text(etree, tvb, offset + 8, 2,
"Unknown Field");
proto_tree_add_text(etree, tvb, offset + 10, 2,
"Port %d",
tvb_get_ntohs(tvb, offset + 10)
);
proto_tree_add_text(etree, tvb, offset + 12, 4,
"IP Address %s",
ip_to_str((guint8 *)&ip_addr)
);
proto_tree_add_text(etree, tvb, offset + 16, 2,
"Unknown Field (Backup server Port?)");
proto_tree_add_text(etree, tvb, offset + 18, 4,
"Unknown Field (Backup Server IP?)");
break;
default:
if (tlvl > 8) {
proto_tree_add_text(etree, tvb, offset + 8,
tlvl - 8, "Data");
}
}
offset += tlvl;
}
}
if (length) {
proto_tree_add_text(tree, tvb, offset, length,
"Invalid garbage at end");
}
}
static void
dissect_spare_poe_tlv(tvbuff_t *tvb, int offset, int length,
proto_tree *tree)
{
proto_item *ti;
proto_tree *tlv_tree;
if (length == 0) {
return;
}
ti = proto_tree_add_item(tree, hf_cdp_spare_poe_tlv, tvb, offset, 1, ENC_BIG_ENDIAN);
tlv_tree = proto_item_add_subtree(ti, ett_cdp_spare_poe_tlv);
proto_tree_add_item(tlv_tree, hf_cdp_spare_poe_tlv_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_spare_poe_tlv_spare_pair_arch, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_spare_poe_tlv_req_spare_pair_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cdp_spare_poe_tlv_pse_spare_pair_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
add_multi_line_string_to_tree(proto_tree *tree, tvbuff_t *tvb, gint start,
gint len, const gchar *prefix)
{
int prefix_len;
int i;
char blanks[64+1];
gint next;
int line_len;
int data_len;
prefix_len = (int)strlen(prefix);
if (prefix_len > 64)
prefix_len = 64;
for (i = 0; i < prefix_len; i++)
blanks[i] = ' ';
blanks[i] = '\0';
while (len > 0) {
line_len = tvb_find_line_end(tvb, start, len, &next, FALSE);
data_len = next - start;
proto_tree_add_text(tree, tvb, start, data_len, "%s%s", prefix,
tvb_format_stringzpad(tvb, start, line_len));
start += data_len;
len -= data_len;
prefix = blanks;
}
}
void
proto_register_cdp(void)
{
static hf_register_info hf[] = {
{ &hf_cdp_version,
{ "Version", "cdp.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cdp_ttl,
{ "TTL", "cdp.ttl", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cdp_checksum,
{ "Checksum", "cdp.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_cdp_checksum_good,
{ "Good", "cdp.checksum_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_cdp_checksum_bad,
{ "Bad", "cdp.checksum_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
{ &hf_cdp_tlvtype,
{ "Type", "cdp.tlv.type", FT_UINT16, BASE_HEX, VALS(type_vals), 0x0,
NULL, HFILL }},
{ &hf_cdp_tlvlength,
{ "Length", "cdp.tlv.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cdp_deviceid,
{"Device ID", "cdp.deviceid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_cdp_platform,
{"Platform", "cdp.platform", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_cdp_portid,
{"Sent through Interface", "cdp.portid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_cdp_capabilities,
{"Capabilities", "cdp.capabilities", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_cdp_capabilities_router,
{"Router", "cdp.capabilities.router", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x01, NULL, HFILL }},
{ &hf_cdp_capabilities_trans_bridge,
{"Transparent Bridge", "cdp.capabilities.trans_bridge", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x02, NULL, HFILL }},
{ &hf_cdp_capabilities_src_bridge,
{"Source Route Bridge", "cdp.capabilities.src_bridge", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x04, NULL, HFILL }},
{ &hf_cdp_capabilities_switch,
{"Switch", "cdp.capabilities.switch", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x08, NULL, HFILL }},
{ &hf_cdp_capabilities_host,
{"Host", "cdp.capabilities.host", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x10, NULL, HFILL }},
{ &hf_cdp_capabilities_igmp_capable,
{"IGMP capable", "cdp.capabilities.igmp_capable", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x20, NULL, HFILL }},
{ &hf_cdp_capabilities_repeater,
{"Repeater", "cdp.capabilities.repeater", FT_BOOLEAN, 32,
TFS(&tfs_yes_no), 0x40, NULL, HFILL }},
{ &hf_cdp_spare_poe_tlv,
{ "Spare Pair PoE", "cdp.spare_poe_tlv", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_cdp_spare_poe_tlv_poe,
{ "PSE Four-Wire PoE", "cdp.spare_poe_tlv.poe", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }
},
{ &hf_cdp_spare_poe_tlv_spare_pair_arch,
{ "PD Spare Pair Architecture", "cdp.spare_poe_tlv.spare_pair_arch", FT_BOOLEAN, 8,
TFS(&tfs_shared_independent), 0x02, NULL, HFILL }
},
{ &hf_cdp_spare_poe_tlv_req_spare_pair_poe,
{ "PD Request Spare Pair PoE", "cdp.spare_poe_tlv.req_spare_pair_poe", FT_BOOLEAN, 8,
TFS(&tfs_on_off), 0x04, NULL, HFILL }
},
{ &hf_cdp_spare_poe_tlv_pse_spare_pair_poe,
{ "PSE Spare Pair PoE", "cdp.spare_poe_tlv.pse_spare_pair_poe", FT_BOOLEAN, 8,
TFS(&tfs_on_off), 0x08, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_cdp,
&ett_cdp_tlv,
&ett_cdp_nrgyz_tlv,
&ett_cdp_address,
&ett_cdp_capabilities,
&ett_cdp_checksum,
&ett_cdp_spare_poe_tlv
};
proto_cdp = proto_register_protocol("Cisco Discovery Protocol",
"CDP", "cdp");
proto_register_field_array(proto_cdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cdp(void)
{
dissector_handle_t cdp_handle;
data_handle = find_dissector("data");
cdp_handle = create_dissector_handle(dissect_cdp, proto_cdp);
dissector_add_uint("llc.cisco_pid", 0x2000, cdp_handle);
dissector_add_uint("chdlctype", 0x2000, cdp_handle);
dissector_add_uint("ppp.protocol", 0x0207, cdp_handle);
}
