static const wimaxasncp_dict_tlv_t *wimaxasncp_get_tlv_info(
guint16 type)
{
wimaxasncp_dict_tlv_t *res = NULL;
if (wimaxasncp_dict)
{
wimaxasncp_dict_tlv_t *tlv;
for (tlv = wimaxasncp_dict->tlvs; tlv; tlv = tlv->next)
{
if (tlv->type == type)
{
if (tlv->since<= global_wimaxasncp_nwg_ver)
{
if (!res || (tlv->since > res->since))
{
res = tlv;
}
}
}
}
}
if (debug_enabled && !res)
{
g_print("fix-me: unknown TLV type: %u\n", type);
}
return res? res:&wimaxasncp_tlv_not_found;
}
static const gchar *wimaxasncp_get_enum_name(
const wimaxasncp_dict_tlv_t *tlv_info,
guint32 code)
{
if (tlv_info->enum_vs)
{
return val_to_str(code, tlv_info->enum_vs, "Unknown");
}
else
{
return "Unknown";
}
}
static void wimaxasncp_proto_tree_add_tlv_ipv4_value(
tvbuff_t *tvb,
proto_tree *tree,
proto_item *tlv_item,
guint offset,
const wimaxasncp_dict_tlv_t *tlv_info)
{
int hf_value;
guint32 ip;
const gchar *hostname;
const gchar *ip_str;
if (tlv_info->hf_ipv4 != -1)
{
hf_value = tlv_info->hf_ipv4;
}
else
{
hf_value = tlv_info->hf_value;
}
ip = tvb_get_ipv4(tvb, offset);
hostname = get_hostname(ip);
ip_str = ip_to_str((guint8 *)&ip);
proto_tree_add_ipv4_format(
tree, hf_value,
tvb, offset, 4, ip,
"Value: %s (%s)", hostname, ip_str);
proto_item_append_text(
tlv_item, " - %s (%s)",
hostname, ip_str);
}
static void wimaxasncp_proto_tree_add_tlv_ipv6_value(
tvbuff_t *tvb,
proto_tree *tree,
proto_item *tlv_item,
guint offset,
const wimaxasncp_dict_tlv_t *tlv_info)
{
int hf_value;
struct e_in6_addr ip;
const gchar *hostname;
const gchar *ip_str;
if (tlv_info->hf_ipv4 != -1)
{
hf_value = tlv_info->hf_ipv6;
}
else
{
hf_value = tlv_info->hf_value;
}
tvb_get_ipv6(tvb, offset, &ip);
hostname = get_hostname6(&ip);
ip_str = ip6_to_str(&ip);
proto_tree_add_ipv6_format(
tree, hf_value,
tvb, offset, 16, (guint8 *)&ip,
"Value: %s (%s)", hostname, ip_str);
proto_item_append_text(
tlv_item, " - %s (%s)",
hostname, ip_str);
}
static void wimaxasncp_proto_tree_add_ether_value(
tvbuff_t *tvb,
proto_tree *tree,
proto_item *tlv_item,
guint offset,
guint length,
const wimaxasncp_dict_tlv_t *tlv_info)
{
int hf_value;
const guint8 *p;
const gchar *ether_name;
const gchar *ether_str;
if (tlv_info->hf_bsid != -1)
{
hf_value = tlv_info->hf_bsid;
}
else
{
hf_value = tlv_info->hf_value;
}
p = tvb_get_ptr(tvb, offset, length);
ether_name = get_ether_name(p);
ether_str = ether_to_str(p);
proto_tree_add_ether_format(
tree, hf_value,
tvb, offset, length, p,
"Value: %s (%s)",
ether_name, ether_str);
proto_item_append_text(
tlv_item, " - %s (%s)",
ether_name, ether_str);
}
static void wimaxasncp_dissect_tlv_value(
tvbuff_t *tvb,
packet_info *pinfo _U_,
proto_tree *tree,
proto_item *tlv_item,
const wimaxasncp_dict_tlv_t *tlv_info)
{
guint offset = 0;
guint length;
const guint max_show_bytes = 24;
static const gchar *hex_note = "[hex]";
length = tvb_reported_length(tvb);
switch (tlv_info->decoder)
{
case WIMAXASNCP_TLV_ENUM8:
{
if (length != 1)
{
break;
}
if (tlv_info->enums == NULL)
{
if (debug_enabled)
{
g_print("fix-me: enum values missing for TLV %s (%u)\n",
tlv_info->name, tlv_info->type);
}
}
if (tree)
{
guint8 value;
const gchar *s;
value = tvb_get_guint8(tvb, offset);
s = wimaxasncp_get_enum_name(tlv_info, value);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %s (%u)", s, value);
proto_item_append_text(tlv_item, " - %s", s);
}
return;
}
case WIMAXASNCP_TLV_ENUM16:
{
if (length != 2)
{
break;
}
if (tlv_info->enums == NULL)
{
if (debug_enabled)
{
g_print("fix-me: enum values missing for TLV %s (%u)\n",
tlv_info->name, tlv_info->type);
}
}
if (tree)
{
guint16 value;
const gchar *s;
value = tvb_get_ntohs(tvb, offset);
s = wimaxasncp_get_enum_name(tlv_info, value);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %s (%u)", s, value);
proto_item_append_text(tlv_item, " - %s", s);
}
return;
}
case WIMAXASNCP_TLV_ENUM32:
{
if (length != 4)
{
break;
}
if (tlv_info->enums == NULL)
{
if (debug_enabled)
{
g_print("fix-me: enum values missing for TLV %s (%u)\n",
tlv_info->name, tlv_info->type);
}
}
if (tree)
{
guint32 value;
const gchar *s;
value = tvb_get_ntohl(tvb, offset);
s = wimaxasncp_get_enum_name(tlv_info, value);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %s (%u)", s, value);
proto_item_append_text(tlv_item, " - %s", s);
}
return;
}
case WIMAXASNCP_TLV_ETHER:
{
if (length != 6)
{
break;
}
if (tree)
{
wimaxasncp_proto_tree_add_ether_value(
tvb, tree, tlv_item, offset, length, tlv_info);
}
return;
}
case WIMAXASNCP_TLV_ASCII_STRING:
{
if (tree)
{
const guint8 *p;
const gchar *s = tvb_get_string(wmem_packet_scope(), tvb, offset, length);
p = tvb_get_ptr(tvb, offset, length);
proto_tree_add_string_format(
tree, tlv_info->hf_value,
tvb, offset, length, p,
"Value: %s", s);
proto_item_append_text(
tlv_item, " - %s", s);
}
return;
}
case WIMAXASNCP_TLV_FLAG0:
{
if (length != 0)
{
break;
}
return;
}
case WIMAXASNCP_TLV_BITFLAGS8:
{
if (length != 1)
{
break;
}
if (tlv_info->enums == NULL)
{
}
if (tree)
{
proto_tree *flags_tree;
proto_item *item;
guint8 value;
guint i;
value = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(
tree, tlv_info->hf_value,
tvb, offset, 1, ENC_NA);
proto_item_append_text(tlv_item, " - 0x%02x", value);
if (value != 0)
{
flags_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_value_bitflags8);
for (i = 0; i < 8; ++i)
{
guint8 mask;
mask = 1 << (7 - i);
if (value & mask)
{
const gchar *s;
s = wimaxasncp_get_enum_name(tlv_info, value & mask);
proto_tree_add_uint_format(
flags_tree, hf_wimaxasncp_tlv_value_bitflags8,
tvb, offset, length, value,
"Bit #%u is set: %s", i, s);
}
}
}
}
return;
}
case WIMAXASNCP_TLV_BITFLAGS16:
{
if (length != 2)
{
break;
}
if (tlv_info->enums == NULL)
{
}
if (tree)
{
proto_tree *flags_tree;
proto_item *item;
guint16 value;
guint i;
value = tvb_get_ntohs(tvb, offset);
item = proto_tree_add_item(
tree, tlv_info->hf_value,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item, " - 0x%04x", value);
if (value != 0)
{
flags_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_value_bitflags16);
for (i = 0; i < 16; ++i)
{
guint16 mask;
mask = 1 << (15 - i);
if (value & mask)
{
const gchar *s;
s = wimaxasncp_get_enum_name(tlv_info, value & mask);
proto_tree_add_uint_format(
flags_tree, hf_wimaxasncp_tlv_value_bitflags16,
tvb, offset, length, value,
"Bit #%u is set: %s", i, s);
}
}
}
}
return;
}
case WIMAXASNCP_TLV_BITFLAGS32:
{
if (length != 4)
{
break;
}
if (tlv_info->enums == NULL)
{
}
if (tree)
{
proto_tree *flags_tree;
proto_item *item;
guint32 value;
guint i;
value = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(
tree, tlv_info->hf_value,
tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tlv_item, " - 0x%08x", value);
if (value != 0)
{
flags_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_value_bitflags32);
for (i = 0; i < 32; ++i)
{
guint32 mask;
mask = 1 << (31 - i);
if (value & mask)
{
const gchar *s;
s = wimaxasncp_get_enum_name(tlv_info, value & mask);
proto_tree_add_uint_format(
flags_tree, hf_wimaxasncp_tlv_value_bitflags32,
tvb, offset, length, value,
"Bit #%u is set: %s", i, s);
}
}
}
}
return;
}
case WIMAXASNCP_TLV_ID:
{
if (length == 4)
{
if (tree)
{
wimaxasncp_proto_tree_add_tlv_ipv4_value(
tvb, tree, tlv_item, offset, tlv_info);
}
return;
}
else if (length == 6)
{
if (tree)
{
wimaxasncp_proto_tree_add_ether_value(
tvb, tree, tlv_item, offset, length, tlv_info);
}
return;
}
else if (length == 16)
{
if (tree)
{
wimaxasncp_proto_tree_add_tlv_ipv6_value(
tvb, tree, tlv_item, offset, tlv_info);
}
return;
}
else
{
break;
}
}
case WIMAXASNCP_TLV_BYTES:
{
if (tree)
{
const gchar *format1;
const gchar *format2;
const guint8 *p = tvb_get_ptr(tvb, offset, length);
const gchar *s = bytestring_to_str(p, MIN(length, max_show_bytes), 0);
if (length <= max_show_bytes)
{
format1 = "Value: %s";
format2 = " - %s";
}
else
{
format1 = "Value: %s...";
format2 = " - %s...";
}
proto_tree_add_bytes_format(
tree, tlv_info->hf_value,
tvb, offset, length, p,
format1, s);
proto_item_append_text(
tlv_item, format2, s);
}
return;
}
case WIMAXASNCP_TLV_HEX8:
{
if (length != 1)
{
break;
}
if (tree)
{
guint8 value;
value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: 0x%02x", value);
proto_item_append_text(tlv_item, " - 0x%02x", value);
}
return;
}
case WIMAXASNCP_TLV_HEX16:
{
if (length != 2)
{
break;
}
if (tree)
{
guint16 value;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: 0x%04x", value);
proto_item_append_text(tlv_item, " - 0x%04x", value);
}
return;
}
case WIMAXASNCP_TLV_HEX32:
{
if (length != 4)
{
break;
}
if (tree)
{
guint32 value;
value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: 0x%08x", value);
proto_item_append_text(tlv_item, " - 0x%08x", value);
}
return;
}
case WIMAXASNCP_TLV_DEC8:
{
if (length != 1)
{
break;
}
if (tree)
{
guint8 value;
value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %u", value);
proto_item_append_text(tlv_item, " - %u", value);
}
return;
}
case WIMAXASNCP_TLV_DEC16:
{
if (length != 2)
{
break;
}
if (tree)
{
guint16 value;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %u", value);
proto_item_append_text(tlv_item, " - %u", value);
}
return;
}
case WIMAXASNCP_TLV_DEC32:
{
if (length != 4)
{
break;
}
if (tree)
{
guint32 value;
value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(
tree, tlv_info->hf_value,
tvb, offset, length, value,
"Value: %u", value);
proto_item_append_text(tlv_item, " - %u", value);
}
return;
}
case WIMAXASNCP_TLV_TBD:
{
if (debug_enabled)
{
g_print(
"fix-me: TBD: TLV %s (%u)\n", tlv_info->name, tlv_info->type);
}
if (tree)
{
const gchar *format;
const guint8 *p = tvb_get_ptr(tvb, offset, length);
const gchar *s = bytestring_to_str(p, MIN(length, max_show_bytes), 0);
if (length <= max_show_bytes)
{
format = "Value: %s %s";
}
else
{
format = "Value: %s %s...";
}
proto_tree_add_bytes_format(
tree, tlv_info->hf_value,
tvb, offset, length, p,
format, hex_note, s);
proto_item_append_text(tlv_item, " - TBD");
}
return;
}
case WIMAXASNCP_TLV_IP_ADDRESS:
{
if (length == 4)
{
if (tree)
{
wimaxasncp_proto_tree_add_tlv_ipv4_value(
tvb, tree, tlv_item, offset, tlv_info);
}
return;
}
else if (length == 16)
{
if (tree)
{
wimaxasncp_proto_tree_add_tlv_ipv6_value(
tvb, tree, tlv_item, offset, tlv_info);
}
return;
}
else
{
break;
}
}
case WIMAXASNCP_TLV_IPV4_ADDRESS:
{
if (length != 4)
{
break;
}
if (tree)
{
wimaxasncp_proto_tree_add_tlv_ipv4_value(
tvb, tree, tlv_item, offset, tlv_info);
}
return;
}
case WIMAXASNCP_TLV_PROTOCOL_LIST:
{
if (length % 2 != 0)
{
break;
}
if (tree && length > 0)
{
proto_tree *protocol_list_tree;
proto_item *item;
const guint max_protocols_in_tlv_item = 8;
item = proto_tree_add_text(
tree, tvb, offset, length,
"Value");
protocol_list_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_protocol_list);
item = proto_tree_add_item(
protocol_list_tree, tlv_info->hf_value,
tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
while (offset < tvb_length(tvb))
{
guint16 protocol;
const gchar *protocol_name;
protocol = tvb_get_ntohs(tvb, offset);
protocol_name = ipprotostr(protocol);
proto_tree_add_uint_format(
protocol_list_tree, tlv_info->hf_protocol,
tvb, offset, 2, protocol,
"Protocol: %s (%u)", protocol_name, protocol);
if (offset == 0)
{
proto_item_append_text(tlv_item, " - %s", protocol_name);
}
else if (offset < 2 * max_protocols_in_tlv_item)
{
proto_item_append_text(tlv_item, ", %s", protocol_name);
}
else if (offset == 2 * max_protocols_in_tlv_item)
{
proto_item_append_text(tlv_item, ", ...");
}
offset += 2;
}
}
return;
}
case WIMAXASNCP_TLV_PORT_RANGE_LIST:
{
if (length % 4 != 0)
{
break;
}
if (tree && length > 0)
{
proto_tree *port_range_list_tree;
proto_item *item;
const guint max_port_ranges_in_tlv_item = 3;
item = proto_tree_add_text(
tree, tvb, offset, length,
"Value");
port_range_list_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_port_range_list);
item = proto_tree_add_item(
port_range_list_tree, tlv_info->hf_value,
tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
while (offset < tvb_length(tvb))
{
guint16 portLow;
guint16 portHigh;
portLow = tvb_get_ntohs(tvb, offset);
portHigh = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_text(
port_range_list_tree, tvb, offset, 4,
"Port Range: %u-%u", portLow, portHigh);
item = proto_tree_add_item(
port_range_list_tree, tlv_info->hf_port_low,
tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_item(
port_range_list_tree, tlv_info->hf_port_high,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
if (offset == 0)
{
proto_item_append_text(
tlv_item, " - %u-%u", portLow, portHigh);
}
else if (offset < 4 * max_port_ranges_in_tlv_item)
{
proto_item_append_text(
tlv_item, ", %u-%u", portLow, portHigh);
}
else if (offset == 4 * max_port_ranges_in_tlv_item)
{
proto_item_append_text(tlv_item, ", ...");
}
offset += 4;
}
}
return;
}
case WIMAXASNCP_TLV_IP_ADDRESS_MASK_LIST:
{
if (length % 8 != 0)
{
break;
}
if (tree && length > 0)
{
proto_tree *ip_address_mask_list_tree;
proto_item *item;
item = proto_tree_add_text(
tree, tvb, offset, length,
"Value");
ip_address_mask_list_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_ip_address_mask_list);
item = proto_tree_add_item(
ip_address_mask_list_tree, tlv_info->hf_value,
tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
if (length % 32 == 0)
{
while (offset < tvb_length(tvb))
{
proto_tree *ip_address_mask_tree;
struct e_in6_addr ip;
const gchar *s;
item = proto_tree_add_text(
ip_address_mask_list_tree, tvb, offset, 32,
"IPv6 Address and Mask");
ip_address_mask_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_ip_address_mask);
tvb_get_ipv6(tvb, offset, &ip);
proto_tree_add_item(
ip_address_mask_tree,
tlv_info->hf_ipv6,
tvb, offset, 16, ENC_NA);
offset += 16;
tvb_get_ipv6(tvb, offset, &ip);
s = ip6_to_str(&ip);
proto_tree_add_ipv6_format_value(
ip_address_mask_tree,
tlv_info->hf_ipv6_mask,
tvb, offset, 16, (const guint8*)&ip,
"%s", s);
offset += 16;
}
}
else
{
while (offset < tvb_length(tvb))
{
proto_tree *ip_address_mask_tree;
guint32 ip;
const gchar *s;
item = proto_tree_add_text(
ip_address_mask_list_tree, tvb, offset, 8,
"IPv4 Address and Mask");
ip_address_mask_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_ip_address_mask);
ip = tvb_get_ipv4(tvb, offset);
proto_tree_add_item(
ip_address_mask_tree,
tlv_info->hf_ipv4,
tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(
item, " - %s (%s)",
get_hostname(ip), ip_to_str((guint8 *)&ip));
offset += 4;
ip = tvb_get_ipv4(tvb, offset);
s = ip_to_str((guint8 *)&ip);
proto_tree_add_ipv4_format_value(
ip_address_mask_tree,
tlv_info->hf_ipv4_mask,
tvb, offset, 4, ip,
"%s", s);
proto_item_append_text(
item, " / %s", s);
offset += 4;
}
}
}
return;
}
case WIMAXASNCP_TLV_EAP:
{
guint8 eap_code;
guint8 eap_type = 0;
eap_code = tvb_get_guint8(tvb, offset);
if (eap_code == EAP_REQUEST || eap_code == EAP_RESPONSE)
{
eap_type = tvb_get_guint8(tvb, offset + 4);
}
col_append_str(pinfo->cinfo, COL_INFO, " [");
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(eap_code, eap_code_vals, "Unknown code (0x%02X)"));
if (eap_code == EAP_REQUEST || eap_code == EAP_RESPONSE)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(eap_type, &eap_type_vals_ext, "Unknown type (0x%02X)"));
}
col_append_str(pinfo->cinfo, COL_INFO, "]");
{
proto_tree *eap_tree;
proto_item *item;
gboolean save_writable;
tvbuff_t *eap_tvb;
item = proto_tree_add_item(tree, tlv_info->hf_value, tvb,
offset, length, ENC_NA);
proto_item_set_text(item, "Value");
eap_tree = proto_item_add_subtree(item, ett_wimaxasncp_tlv_eap);
proto_item_append_text(item, " (%s",
val_to_str(eap_code, eap_code_vals,
"Unknown code (0x%02X)"));
if (eap_code == EAP_REQUEST || eap_code == EAP_RESPONSE)
{
proto_item_append_text(item, ", %s",
val_to_str_ext(eap_type, &eap_type_vals_ext,
"Unknown type (0x%02X)"));
}
proto_item_append_text(item, ")");
eap_tvb = tvb_new_subset(tvb, offset, length,
tvb_length_remaining(tvb, offset));
save_writable = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
call_dissector(eap_handle, eap_tvb, pinfo, eap_tree);
col_set_writable(pinfo->cinfo, save_writable);
}
return;
}
case WIMAXASNCP_TLV_VENDOR_SPECIFIC:
{
if (length < 3)
{
break;
}
if (tree)
{
proto_tree *vsif_tree;
proto_item *item;
guint32 vendorId;
const gchar *vendorName;
item = proto_tree_add_text(
tree, tvb, offset, length,
"Value");
vsif_tree = proto_item_add_subtree(
item, ett_wimaxasncp_tlv_vendor_specific_information_field);
item = proto_tree_add_item(
vsif_tree, tlv_info->hf_value,
tvb, offset, length, ENC_NA);
PROTO_ITEM_SET_HIDDEN(item);
vendorId = tvb_get_ntoh24(tvb, offset);
vendorName = val_to_str_ext_const(vendorId, &sminmpec_values_ext, "Unknown");
proto_tree_add_uint_format(
vsif_tree, tlv_info->hf_vendor_id,
tvb, offset, 3, vendorId,
"Vendor ID: %s (%u)", vendorName, vendorId);
proto_item_append_text(tlv_item, " - %s", vendorName);
offset += 3;
if (offset < tvb_length(tvb))
{
proto_tree_add_item(
vsif_tree, tlv_info->hf_vendor_rest_of_info,
tvb, offset, length - offset, ENC_NA);
}
}
return;
}
case WIMAXASNCP_TLV_UNKNOWN:
{
if (tree)
{
const gchar *format1;
const gchar *format2;
const guint8 *p = tvb_get_ptr(tvb, offset, length);
const gchar *s =
bytestring_to_str(p, MIN(length, max_show_bytes), 0);
if (length <= max_show_bytes)
{
format1 = "Value: %s %s";
format2 = " - %s %s";
}
else
{
format1 = "Value: %s %s...";
format2 = " - %s %s...";
}
proto_tree_add_bytes_format(
tree, tlv_info->hf_value,
tvb, offset, length, p,
format1, hex_note, s);
proto_item_append_text(
tlv_item, format2, hex_note, s);
}
return;
}
default:
if (debug_enabled)
{
g_print(
"fix-me: unknown decoder: %d\n", tlv_info->decoder);
}
break;
}
if (tree)
{
const gchar *format;
const guint8 *p = tvb_get_ptr(tvb, offset, length);
const gchar *s = bytestring_to_str(p, MIN(length, max_show_bytes), 0);
if (length <= max_show_bytes)
{
format = "Value: %s %s";
}
else
{
format = "Value: %s %s...";
}
proto_tree_add_bytes_format(
tree, hf_wimaxasncp_tlv_value_bytes,
tvb, offset, length, p,
format, hex_note, s);
}
}
static guint dissect_wimaxasncp_tlvs(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
guint offset;
offset = 0;
while (offset < tvb_reported_length(tvb))
{
const wimaxasncp_dict_tlv_t *tlv_info;
proto_tree *tlv_tree;
proto_item *tlv_item;
guint16 type;
guint16 length;
guint pad;
type = tvb_get_ntohs(tvb, offset);
tlv_info = wimaxasncp_get_tlv_info(type);
length = tvb_get_ntohs(tvb, offset + 2);
#if 0
pad = 4 - (length % 4);
if (pad == 4)
{
pad = 0;
}
#endif
pad = 0;
{
proto_item *type_item;
gint tree_length = MIN(
(gint)(4 + length + pad), tvb_length_remaining(tvb, offset));
tlv_item = proto_tree_add_item(
tree, tlv_info->hf_root,
tvb, offset, tree_length, ENC_NA);
proto_item_set_text(tlv_item, "TLV: %s", tlv_info->name);
if (tlv_info->decoder == WIMAXASNCP_TLV_UNKNOWN)
{
proto_item_append_text(tlv_item, " (%u)", type);
}
if (tlv_info->decoder == WIMAXASNCP_TLV_COMPOUND)
{
proto_item_append_text(tlv_item, " [Compound]");
}
tlv_tree = proto_item_add_subtree(
tlv_item, ett_wimaxasncp_tlv);
type_item = proto_tree_add_uint_format(
tlv_tree, hf_wimaxasncp_tlv_type,
tvb, offset, 2, type,
"Type: %s (%u)", tlv_info->name, type);
if (tlv_info->decoder == WIMAXASNCP_TLV_UNKNOWN)
{
expert_add_info_format(pinfo, type_item, &ei_wimaxasncp_tlv_type,
"Unknown TLV type (%u)",
type);
}
proto_tree_add_uint(
tlv_tree, hf_wimaxasncp_tlv_length,
tvb, offset + 2, 2, length);
}
offset += 4;
if (tlv_info->decoder == WIMAXASNCP_TLV_COMPOUND)
{
if (length == 0)
{
}
else if (tvb_length_remaining(tvb, offset) > 0)
{
tvbuff_t *tlv_tvb;
tlv_tvb = tvb_new_subset(
tvb, offset,
MIN(length, tvb_length_remaining(tvb, offset)),
length);
dissect_wimaxasncp_tlvs(tlv_tvb, pinfo, tlv_tree);
}
else
{
tvb_ensure_bytes_exist(tvb, offset, length + pad);
}
}
else
{
tvbuff_t *tlv_tvb;
tvb_ensure_bytes_exist(tvb, offset, length + pad);
tlv_tvb = tvb_new_subset(
tvb, offset,
MIN(length, tvb_length_remaining(tvb, offset)),
length);
wimaxasncp_dissect_tlv_value(
tlv_tvb, pinfo, tlv_tree, tlv_item, tlv_info);
}
offset += length + pad;
}
return offset;
}
static guint dissect_wimaxasncp_backend(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
guint offset = 0;
guint16 ui16;
guint32 ui32;
const guint8 *pmsid;
guint16 tid = 0;
gboolean dbit_show;
if (tree)
{
proto_tree_add_item(
tree, hf_wimaxasncp_msid,
tvb, offset, 6, ENC_NA);
}
pmsid = tvb_ether_to_str(tvb, offset);
offset += 6;
ui32 = tvb_get_ntohl(tvb, offset);
if (tree)
{
proto_tree_add_uint(
tree, hf_wimaxasncp_reserved1,
tvb, offset, 4, ui32);
}
offset += 4;
dbit_show = FALSE;
ui16 = tvb_get_ntohs(tvb, offset);
if (show_transaction_id_d_bit)
{
const guint16 mask = 0x7fff;
if (ui16 & 0x8000)
{
proto_tree_add_uint_format(
tree, hf_wimaxasncp_transaction_id,
tvb, offset, 2, ui16,
"Transaction ID: D + 0x%04x (0x%04x)", mask & ui16, ui16);
tid = ui16 & mask;
dbit_show = TRUE;
}
else
{
proto_tree_add_uint_format(
tree, hf_wimaxasncp_transaction_id,
tvb, offset, 2, ui16,
"Transaction ID: 0x%04x", ui16);
tid = ui16;
}
}
else
{
proto_tree_add_uint(
tree, hf_wimaxasncp_transaction_id,
tvb, offset, 2, ui16);
tid = ui16;
}
offset += 2;
ui16 = tvb_get_ntohs(tvb, offset);
if (tree)
{
proto_tree_add_uint(
tree, hf_wimaxasncp_reserved2,
tvb, offset, 2, ui16);
}
offset += 2;
if (offset < tvb_length(tvb))
{
tvbuff_t *tlv_tvb;
tlv_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_wimaxasncp_tlvs(tlv_tvb, pinfo, tree);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " - MSID:%s", pmsid);
if (dbit_show)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", TID:D+0x%04x", tid);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", TID:0x%04x", tid);
}
return offset;
}
static const gchar*
match_ver_value_string(
const guint32 val,
const ver_value_string* const strings,
const guint32 max_ver)
{
const ver_value_string* vvs;
const ver_value_string* res = NULL;
for(vvs=strings; vvs->vs.strptr; vvs++)
{
if ((vvs->vs.value == val) && (vvs->since <= max_ver))
{
if (!res || (vvs->since > res->since))
{
res = vvs;
}
}
}
return res? res->vs.strptr : NULL;
}
static int
dissect_wimaxasncp(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
const gchar *unknown = "Unknown";
proto_item *packet_item = NULL;
proto_item *item = NULL;
proto_tree *wimaxasncp_tree = NULL;
tvbuff_t *subtree;
guint offset;
guint8 ui8;
guint8 function_type;
const gchar *function_type_name;
proto_item *function_type_item;
guint16 length;
const wimaxasncp_func_msg_t *p = NULL;
const gchar *message_name;
gsize i;
#if 0
if (tvb_reported_length(tvb) < WIMAXASNCP_HEADER_SIZE)
{
return 0;
}
#endif
if (tvb_bytes_exist(tvb, 0, 1) && tvb_get_guint8(tvb, 0) != 1)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WiMAX");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
if (wimaxasncp_dict == NULL)
{
register_wimaxasncp_fields(NULL);
}
if (tree)
{
packet_item = proto_tree_add_item(
tree, proto_wimaxasncp,
tvb, 0, MIN(WIMAXASNCP_HEADER_LENGTH_END, tvb_length(tvb)), ENC_NA);
wimaxasncp_tree = proto_item_add_subtree(
packet_item, ett_wimaxasncp);
}
if (tree)
{
proto_tree_add_item(
wimaxasncp_tree, hf_wimaxasncp_version,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
ui8 = tvb_get_guint8(tvb, offset);
if (tree)
{
proto_tree *flags_tree;
if (ui8 == 0)
{
proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_flags,
tvb, offset, 1, ui8,
"Flags: 0x%02x", ui8);
}
else
{
guint j;
item = proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_flags,
tvb, offset, 1, ui8,
"Flags: ");
if (ui8 & (WIMAXASNCP_FLAGS_T | WIMAXASNCP_FLAGS_R))
{
if (ui8 & WIMAXASNCP_FLAGS_T)
{
proto_item_append_text(item, "T");
}
if (ui8 & WIMAXASNCP_FLAGS_R)
{
proto_item_append_text(item, "R");
}
proto_item_append_text(item, " - ");
}
proto_item_append_text(item, "0x%02x", ui8);
flags_tree = proto_item_add_subtree(
item, ett_wimaxasncp_flags);
for (j = 0; j < 8; ++j)
{
guint8 mask;
mask = 1 << (7 - j);
if (ui8 & mask)
{
proto_tree_add_uint_format(
flags_tree, hf_wimaxasncp_flags,
tvb, offset, 1, ui8,
"Bit #%u is set: %s",
j,
val_to_str(
ui8 & mask, wimaxasncp_flag_vals, "Unknown"));
}
}
}
}
offset += 1;
function_type = tvb_get_guint8(tvb, offset);
function_type_name = match_ver_value_string(function_type,
wimaxasncp_function_type_vals,
global_wimaxasncp_nwg_ver);
if (function_type_name)
{
proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_function_type,
tvb, offset, 1, function_type,
"%s (%u)", function_type_name, function_type);
}
else
{
function_type_item = proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_function_type,
tvb, offset, 1, function_type,
"Unknown (%u)", function_type);
expert_add_info_format(pinfo, function_type_item,
&ei_wimaxasncp_function_type,
"Unknown function type (%u)",
function_type);
}
offset += 1;
ui8 = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_op_id,
tvb, offset, 1, ui8,
"OP ID: %s", val_to_str(ui8 >> 5, wimaxasncp_op_id_vals, unknown));
proto_item_append_text(item, " (%u)", ((ui8 >> 5) & 7));
for (i = 0; i < array_length(wimaxasncp_func_to_msg_vals_map); ++i)
{
p = &wimaxasncp_func_to_msg_vals_map[i];
if (function_type == p->function_type)
{
break;
}
}
message_name = p ? match_ver_value_string(0x1f & ui8, p->vals, global_wimaxasncp_nwg_ver) : unknown;
if (message_name == NULL)
{
message_name = unknown;
}
item = proto_tree_add_uint_format(
wimaxasncp_tree, hf_wimaxasncp_op_id,
tvb, offset, 1, ui8,
"Message Type: %s", message_name);
proto_item_append_text(item, " (%u)", ui8 & 0x1F);
if (strcmp(message_name, unknown) == 0)
{
expert_add_info_format(pinfo, item, &ei_wimaxasncp_op_id,
"Unknown message op (%u)",
0x1f & ui8);
}
col_add_str(pinfo->cinfo, COL_INFO, message_name);
offset += 1;
length = tvb_get_ntohs(tvb, offset);
if (tree)
{
proto_item_set_len(
packet_item, MAX(WIMAXASNCP_HEADER_LENGTH_END, length));
item = proto_tree_add_uint(
wimaxasncp_tree, hf_wimaxasncp_length,
tvb, offset, 2, length);
}
offset += 2;
if (length < WIMAXASNCP_HEADER_SIZE)
{
expert_add_info(pinfo, item, &ei_wimaxasncp_length_bad);
if (tree)
{
proto_item_append_text(
item, " [error: specified length less than header size (20)]");
}
if (length <= WIMAXASNCP_HEADER_LENGTH_END)
{
return offset;
}
}
subtree = tvb_new_subset(
tvb, offset,
MIN(length, tvb_length(tvb) - offset),
length - WIMAXASNCP_HEADER_LENGTH_END);
offset += dissect_wimaxasncp_backend(
subtree, pinfo, wimaxasncp_tree);
return offset;
}
static char *alnumerize(
char *name)
{
char *r = name;
char *w = name;
char c;
for ( ; (c = *r); ++r)
{
if (isalnum((unsigned char)c) || c == '_' || c == '.')
{
*(w++) = c;
}
else if (c == ' ' || c == '-' || c == '/')
{
if (w == name)
{
continue;
}
if (*(w - 1) == '_')
{
continue;
}
*(w++) = '_';
}
}
*w = '\0';
return name;
}
static void add_reg_info(
int *hf_ptr,
const char *name,
const char *abbrev,
enum ftenum type,
int display,
const char *blurb)
{
hf_register_info hf = {
hf_ptr, { name, abbrev, type, display, NULL, 0x0, blurb, HFILL } };
g_array_append_val(wimaxasncp_build_dict.hf, hf);
}
static void add_tlv_reg_info(
wimaxasncp_dict_tlv_t *tlv)
{
char *name;
char *abbrev;
const char *root_blurb;
char *blurb;
name = g_strdup(tlv->name);
abbrev = alnumerize(g_strdup_printf("wimaxasncp.tlv.%s", tlv->name));
switch (tlv->decoder)
{
case WIMAXASNCP_TLV_UNKNOWN:
root_blurb = "type=Unknown";
break;
case WIMAXASNCP_TLV_TBD:
root_blurb = g_strdup_printf("type=%u, TBD", tlv->type);
break;
case WIMAXASNCP_TLV_COMPOUND:
root_blurb = g_strdup_printf("type=%u, Compound", tlv->type);
break;
case WIMAXASNCP_TLV_FLAG0:
root_blurb = g_strdup_printf("type=%u, Value = Null", tlv->type);
break;
default:
root_blurb = g_strdup_printf("type=%u", tlv->type);
break;
}
add_reg_info(
&tlv->hf_root, name, abbrev, FT_BYTES, BASE_NONE, root_blurb);
name = g_strdup("Value");
abbrev = alnumerize(g_strdup_printf("wimaxasncp.tlv.%s.value", tlv->name));
blurb = g_strdup_printf("value for type=%u", tlv->type);
switch (tlv->decoder)
{
case WIMAXASNCP_TLV_UNKNOWN:
g_free(blurb);
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE,
"value for unknown type");
break;
case WIMAXASNCP_TLV_TBD:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_COMPOUND:
case WIMAXASNCP_TLV_FLAG0:
g_free(name);
g_free(abbrev);
g_free(blurb);
break;
case WIMAXASNCP_TLV_BYTES:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_ENUM8:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT8, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_ENUM16:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT16, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_ENUM32:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT32, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_ETHER:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_ETHER, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_ASCII_STRING:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_STRING, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_BITFLAGS8:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT8, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_BITFLAGS16:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT16, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_BITFLAGS32:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT32, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_ID:
g_free(abbrev);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.ipv4_value", tlv->name));
add_reg_info(
&tlv->hf_ipv4, "IPv4 Address", abbrev, FT_IPv4, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.ipv6_value", tlv->name));
add_reg_info(
&tlv->hf_ipv6, "IPv6 Address", abbrev, FT_IPv6, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.bsid_value", tlv->name));
add_reg_info(
&tlv->hf_bsid, "BS ID", abbrev, FT_ETHER, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_HEX8:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT8, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_HEX16:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT16, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_HEX32:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT32, BASE_HEX, blurb);
break;
case WIMAXASNCP_TLV_DEC8:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT8, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_DEC16:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT16, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_DEC32:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_UINT32, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_IP_ADDRESS:
g_free(abbrev);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.ipv4_value", tlv->name));
add_reg_info(
&tlv->hf_ipv4, "IPv4 Address", abbrev, FT_IPv4, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.ipv6_value", tlv->name));
add_reg_info(
&tlv->hf_ipv6, "IPv6 Address", abbrev, FT_IPv6, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_IPV4_ADDRESS:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_IPv4, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_PROTOCOL_LIST:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
blurb = g_strdup_printf("value component for type=%u", tlv->type);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.protocol", tlv->name));
add_reg_info(
&tlv->hf_protocol, "Protocol", abbrev, FT_UINT16, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_PORT_RANGE_LIST:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
blurb = g_strdup_printf("value component for type=%u", tlv->type);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.port_low", tlv->name));
add_reg_info(
&tlv->hf_port_low, "Port Low", abbrev, FT_UINT16, BASE_DEC, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.port_high", tlv->name));
add_reg_info(
&tlv->hf_port_high, "Port High", abbrev, FT_UINT16, BASE_DEC, blurb);
break;
case WIMAXASNCP_TLV_IP_ADDRESS_MASK_LIST:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
blurb = g_strdup_printf("value component for type=%u", tlv->type);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.ipv4", tlv->name));
add_reg_info(
&tlv->hf_ipv4, "IPv4 Address", abbrev, FT_IPv4, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.ipv4_mask", tlv->name));
add_reg_info(
&tlv->hf_ipv4_mask, "IPv4 Mask", abbrev, FT_IPv4, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.ipv6", tlv->name));
add_reg_info(
&tlv->hf_ipv6, "IPv6 Address", abbrev, FT_IPv6, BASE_NONE, blurb);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.ipv6_mask", tlv->name));
add_reg_info(
&tlv->hf_ipv6_mask, "IPv6 Mask", abbrev, FT_IPv6, BASE_NONE, blurb);
break;
case WIMAXASNCP_TLV_VENDOR_SPECIFIC:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
blurb = g_strdup_printf("value component for type=%u", tlv->type);
abbrev = alnumerize(
g_strdup_printf("wimaxasncp.tlv.%s.value.vendor_id", tlv->name));
add_reg_info(
&tlv->hf_vendor_id, "Vendor ID", abbrev, FT_UINT24, BASE_DEC, blurb);
abbrev = alnumerize(
g_strdup_printf(
"wimaxasncp.tlv.%s.value.vendor_rest_of_info", tlv->name));
add_reg_info(
&tlv->hf_vendor_rest_of_info, "Rest of Info", abbrev, FT_BYTES, BASE_NONE,
blurb);
break;
case WIMAXASNCP_TLV_EAP:
blurb = g_strdup_printf("EAP payload embedded in %s", name);
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
break;
default:
add_reg_info(
&tlv->hf_value, name, abbrev, FT_BYTES, BASE_NONE, blurb);
if (debug_enabled)
{
g_print(
"fix-me: unknown decoder: %d\n", tlv->decoder);
}
break;
}
}
static void
register_wimaxasncp_fields(const char* unused _U_)
{
gboolean debug_parser;
gboolean dump_dict;
gchar *dir;
gchar* dict_error;
static hf_register_info hf_base[] = {
{
&hf_wimaxasncp_version,
{
"Version",
"wimaxasncp.version",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_flags,
{
"Flags",
"wimaxasncp.flags",
FT_UINT8,
BASE_HEX,
NULL,
0xff,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_function_type,
{
"Function Type",
"wimaxasncp.function_type",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_op_id,
{
"OP ID",
"wimaxasncp.opid",
FT_UINT8,
BASE_HEX,
VALS(wimaxasncp_op_id_vals),
0xE0,
NULL,
HFILL
}
},
#if 0
{
&hf_wimaxasncp_message_type,
{
"Message Type",
"wimaxasncp.message_type",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_qos_msg,
{
"Message Type",
"wimaxasncp.qos_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_ho_control_msg,
{
"Message Type",
"wimaxasncp.ho_control_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_data_path_control_msg,
{
"Message Type",
"wimaxasncp.data_path_control_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_context_delivery_msg,
{
"Message Type",
"wimaxasncp.context_delivery_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_r3_mobility_msg,
{
"Message Type",
"wimaxasncp.r3_mobility_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_paging_msg,
{
"Message Type",
"wimaxasncp.paging_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_rrm_msg,
{
"Message Type",
"wimaxasncp.rrm_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_authentication_msg,
{
"Message Type",
"wimaxasncp.authentication_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_ms_state_msg,
{
"Message Type",
"wimaxasncp.ms_state_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_reauthentication_msg,
{
"Message Type",
"wimaxasncp.reauthentication_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_session_msg,
{
"Message Type",
"wimaxasncp.session_msg",
FT_UINT8,
BASE_HEX,
NULL,
0x1F,
NULL,
HFILL
}
},
#endif
{
&hf_wimaxasncp_length,
{
"Length",
"wimaxasncp.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_msid,
{
"MSID",
"wimaxasncp.msid",
FT_ETHER,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_reserved1,
{
"Reserved",
"wimaxasncp.reserved1",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_transaction_id,
{
"Transaction ID",
"wimaxasncp.transaction_id",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_reserved2,
{
"Reserved",
"wimaxasncp.reserved2",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
#if 0
{
&hf_wimaxasncp_tlv,
{
"TLV",
"wimaxasncp.tlv",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
#endif
{
&hf_wimaxasncp_tlv_type,
{
"Type",
"wimaxasncp.tlv.type",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_tlv_length,
{
"Length",
"wimaxasncp.tlv.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_tlv_value_bytes,
{
"Value",
"wimaxasncp.tlv_value_bytes",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_tlv_value_bitflags8,
{
"Value",
"wimaxasncp.tlv_value_bitflags8",
FT_UINT8,
BASE_HEX,
NULL,
0xff,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_tlv_value_bitflags16,
{
"Value",
"wimaxasncp.tlv_value_bitflags16",
FT_UINT16,
BASE_HEX,
NULL,
0xffff,
NULL,
HFILL
}
},
{
&hf_wimaxasncp_tlv_value_bitflags32,
{
"Value",
"wimaxasncp.tlv_value_bitflags32",
FT_UINT32,
BASE_HEX,
NULL,
0xffffffff,
NULL,
HFILL
}
},
#if 0
{
&hf_wimaxasncp_tlv_value_protocol,
{
"Value",
"wimaxasncp.tlv_value_protocol",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
#endif
#if 0
{
&hf_wimaxasncp_tlv_value_vendor_id,
{
"Vendor ID",
"wimaxasncp.tlv_value_vendor_id",
FT_UINT24,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
}
#endif
};
static gint *ett_base[] = {
&ett_wimaxasncp,
&ett_wimaxasncp_flags,
&ett_wimaxasncp_tlv,
&ett_wimaxasncp_tlv_value_bitflags8,
&ett_wimaxasncp_tlv_value_bitflags16,
&ett_wimaxasncp_tlv_value_bitflags32,
&ett_wimaxasncp_tlv_protocol_list,
&ett_wimaxasncp_tlv_port_range_list,
&ett_wimaxasncp_tlv_ip_address_mask_list,
&ett_wimaxasncp_tlv_ip_address_mask,
&ett_wimaxasncp_tlv_eap,
&ett_wimaxasncp_tlv_vendor_specific_information_field
};
static ei_register_info ei[] = {
{ &ei_wimaxasncp_tlv_type, { "wimaxasncp.tlv.type.unknown", PI_UNDECODED, PI_WARN, "Unknown tlv", EXPFILL }},
{ &ei_wimaxasncp_function_type, { "wimaxasncp.function_type.unknown", PI_UNDECODED, PI_WARN, "Unknown function type", EXPFILL }},
{ &ei_wimaxasncp_op_id, { "wimaxasncp.opid.unknown", PI_UNDECODED, PI_WARN, "Unknown message op", EXPFILL }},
{ &ei_wimaxasncp_length_bad, { "wimaxasncp.length.bad", PI_MALFORMED, PI_ERROR, "Bad length", EXPFILL }},
};
expert_module_t* expert_wimaxasncp;
debug_parser = getenv("WIRESHARK_DEBUG_WIMAXASNCP_DICT_PARSER") != NULL;
dump_dict = getenv("WIRESHARK_DUMP_WIMAXASNCP_DICT") != NULL;
dir = g_strdup_printf(
"%s" G_DIR_SEPARATOR_S "wimaxasncp",
get_datafile_dir());
wimaxasncp_dict =
wimaxasncp_dict_scan(dir, "dictionary.xml", debug_parser, &dict_error);
g_free(dir);
if (dict_error)
{
report_failure("wimaxasncp - %s", dict_error);
g_free(dict_error);
}
if (wimaxasncp_dict && dump_dict)
{
wimaxasncp_dict_print(stdout, wimaxasncp_dict);
}
wimaxasncp_build_dict.hf =
g_array_new(FALSE, TRUE, sizeof(hf_register_info));
g_array_append_vals(
wimaxasncp_build_dict.hf, hf_base, array_length(hf_base));
wimaxasncp_build_dict.ett =
g_array_new(FALSE, TRUE, sizeof(gint*));
g_array_append_vals(
wimaxasncp_build_dict.ett, ett_base, array_length(ett_base));
if (wimaxasncp_dict)
{
wimaxasncp_dict_tlv_t *tlv;
for (tlv = wimaxasncp_dict->tlvs; tlv; tlv = tlv->next)
{
if (tlv->enums)
{
wimaxasncp_dict_enum_t *e;
GArray* array = g_array_new(TRUE, TRUE, sizeof(value_string));
for (e = tlv->enums; e; e = e->next)
{
value_string item = { e->code, e->name };
g_array_append_val(array, item);
}
tlv->enum_vs = (value_string*)(void*)array->data;
}
add_tlv_reg_info(tlv);
}
}
add_tlv_reg_info(&wimaxasncp_tlv_not_found);
if (debug_enabled)
{
if (wimaxasncp_dict)
{
wimaxasncp_dict_tlv_t *tlv;
for (tlv = wimaxasncp_dict->tlvs; tlv; tlv = tlv->next)
{
printf(
"%s\n"
" type = %d\n"
" description = %s\n"
" decoder = %s\n"
" hf_root = %d\n"
" hf_value = %d\n"
" hf_ipv4 = %d\n"
" hf_ipv6 = %d\n"
" hf_bsid = %d\n"
" hf_protocol = %d\n"
" hf_port_low = %d\n"
" hf_port_high = %d\n"
" hf_ipv4_mask = %d\n"
" hf_ipv6_mask = %d\n"
" hf_vendor_id = %d\n"
" hf_vendor_rest_of_info = %d\n",
tlv->name,
tlv->type,
tlv->description,
val_to_str(
tlv->decoder, wimaxasncp_decode_type_vals, "Unknown"),
tlv->hf_root,
tlv->hf_value,
tlv->hf_ipv4,
tlv->hf_ipv6,
tlv->hf_bsid,
tlv->hf_protocol,
tlv->hf_port_low,
tlv->hf_port_high,
tlv->hf_ipv4_mask,
tlv->hf_ipv6_mask,
tlv->hf_vendor_id,
tlv->hf_vendor_rest_of_info);
}
}
}
proto_register_field_array(
proto_wimaxasncp,
(hf_register_info*)(void *)wimaxasncp_build_dict.hf->data,
wimaxasncp_build_dict.hf->len);
proto_register_subtree_array(
(gint**)(void *)wimaxasncp_build_dict.ett->data,
wimaxasncp_build_dict.ett->len);
expert_wimaxasncp = expert_register_protocol(proto_wimaxasncp);
expert_register_field_array(expert_wimaxasncp, ei, array_length(ei));
}
void
proto_register_wimaxasncp(void)
{
module_t *wimaxasncp_module;
proto_wimaxasncp = proto_register_protocol(
"WiMAX ASN Control Plane Protocol",
"WiMAX ASN CP",
"wimaxasncp");
new_register_dissector("wimaxasncp", dissect_wimaxasncp, proto_wimaxasncp);
wimaxasncp_module = prefs_register_protocol(
proto_wimaxasncp,
proto_reg_handoff_wimaxasncp);
prefs_register_bool_preference(
wimaxasncp_module,
"show_transaction_id_d_bit",
"Show transaction ID direction bit",
"Show transaction ID direction bit separately from the rest of "
"the transaction ID field.",
&show_transaction_id_d_bit);
prefs_register_bool_preference(
wimaxasncp_module,
"debug_enabled",
"Enable debug output",
"Print debug output to the console.",
&debug_enabled);
prefs_register_uint_preference(
wimaxasncp_module,
"udp.wimax_port",
"UDP Port for WiMAX ASN Control Plane Protocol",
"Set UDP port for WiMAX ASN Control Plane Protocol",
10, &global_wimaxasncp_udp_port);
prefs_register_enum_preference(
wimaxasncp_module,
"nwg_version",
"NWG Version",
"Version of the NWG that the R6 protocol complies with",
&global_wimaxasncp_nwg_ver,
wimaxasncp_nwg_versions,
FALSE);
proto_register_prefix("wimaxasncp", register_wimaxasncp_fields);
}
void
proto_reg_handoff_wimaxasncp(void)
{
static gboolean inited = FALSE;
static dissector_handle_t wimaxasncp_handle;
static int currentPort = -1;
if (!inited)
{
wimaxasncp_handle = new_create_dissector_handle(
dissect_wimaxasncp,
proto_wimaxasncp);
eap_handle = find_dissector("eap");
inited = TRUE;
}
if (currentPort != -1)
{
dissector_delete_uint("udp.port", currentPort, wimaxasncp_handle);
}
currentPort = global_wimaxasncp_udp_port;
dissector_add_uint("udp.port", currentPort, wimaxasncp_handle);
}
