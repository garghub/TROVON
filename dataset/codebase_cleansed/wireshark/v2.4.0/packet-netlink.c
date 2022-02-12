static int
dissect_netlink_attributes_common(tvbuff_t *tvb, header_field_info *hfi_type, int ett_tree, int ett_attrib, void *data, struct packet_netlink_data *nl_data, proto_tree *tree, int offset, int length, netlink_attributes_cb_t cb)
{
int encoding;
int padding = (4 - offset) & 3;
DISSECTOR_ASSERT(nl_data);
encoding = nl_data->encoding;
offset += padding;
if (length == -1) {
length = tvb_captured_length_remaining(tvb, offset);
} else {
length -= padding;
}
while (length >= 4) {
guint16 rta_len, rta_type, type;
proto_item *ti, *type_item;
proto_tree *attr_tree, *type_tree;
rta_len = tvb_get_guint16(tvb, offset, encoding);
if (rta_len < 4) {
break;
}
rta_len = MIN(rta_len, length);
attr_tree = proto_tree_add_subtree(tree, tvb, offset, rta_len, ett_tree, &ti, "Attribute");
proto_tree_add_item(attr_tree, &hfi_netlink_attr_len, tvb, offset, 2, encoding);
offset += 2;
rta_type = tvb_get_guint16(tvb, offset, encoding);
if (ett_attrib == -1) {
type = rta_type & NLA_TYPE_MASK;
type_item = proto_tree_add_item(attr_tree, &hfi_netlink_attr_type, tvb, offset, 2, encoding);
type_tree = proto_item_add_subtree(type_item, ett_netlink_attr_type);
proto_tree_add_item(type_tree, &hfi_netlink_attr_type_nested, tvb, offset, 2, encoding);
proto_tree_add_item(type_tree, &hfi_netlink_attr_type_net_byteorder, tvb, offset, 2, encoding);
proto_tree_add_item(type_tree, hfi_type, tvb, offset, 2, encoding);
offset += 2;
if (rta_type & NLA_F_NESTED)
proto_item_append_text(type_item, ", Nested");
if (hfi_type->strings) {
const char *rta_str;
if (hfi_type->display & BASE_EXT_STRING) {
rta_str = try_val_to_str_ext(type, (value_string_ext *)hfi_type->strings);
} else {
rta_str = try_val_to_str(type, (const value_string *) hfi_type->strings);
}
if (rta_str) {
proto_item_append_text(type_item, ", %s (%d)", rta_str, type);
proto_item_append_text(ti, ": %s", rta_str);
}
}
if (!cb(tvb, data, attr_tree, rta_type, offset, rta_len - 4)) {
proto_tree_add_item(attr_tree, &hfi_netlink_attr_data, tvb, offset, rta_len - 4, encoding);
}
} else {
proto_tree_add_item(attr_tree, &hfi_netlink_attr_index, tvb, offset, 2, encoding);
offset += 2;
proto_item_append_text(ti, " %u", rta_type);
dissect_netlink_attributes(tvb, hfi_type, ett_attrib, data, nl_data, attr_tree, offset, rta_len - 4, cb);
}
rta_len = MIN((rta_len + 3) & ~3, length);
offset += rta_len - 4;
length -= rta_len;
}
return offset;
}
int
dissect_netlink_attributes(tvbuff_t *tvb, header_field_info *hfi_type, int ett, void *data, struct packet_netlink_data *nl_data, proto_tree *tree, int offset, int length, netlink_attributes_cb_t cb)
{
return dissect_netlink_attributes_common(tvb, hfi_type, ett, -1, data, nl_data, tree, offset, length, cb);
}
int
dissect_netlink_attributes_array(tvbuff_t *tvb, header_field_info *hfi_type, int ett_array, int ett_attrib, void *data, struct packet_netlink_data *nl_data, proto_tree *tree, int offset, int length, netlink_attributes_cb_t cb)
{
DISSECTOR_ASSERT(ett_attrib != -1);
return dissect_netlink_attributes_common(tvb, hfi_type, ett_array, ett_attrib, data, nl_data, tree, offset, length, cb);
}
int
dissect_netlink_header(tvbuff_t *tvb, proto_tree *tree, int offset, int encoding, header_field_info *hfi_type, proto_item **pi_type)
{
guint16 hdr_flags;
guint16 hdr_type;
proto_tree *fh_hdr;
proto_item *pi;
fh_hdr = proto_tree_add_subtree(tree, tvb, offset, 16, ett_netlink_msghdr, NULL, "Netlink message header");
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_len, tvb, offset, 4, encoding);
offset += 4;
hdr_type = tvb_get_guint16(tvb, offset, encoding);
if (hdr_type < WS_NLMSG_MIN_TYPE) {
hfi_type = &hfi_netlink_hdr_type;
pi = proto_tree_add_item(fh_hdr, hfi_type, tvb, offset, 2, encoding);
} else {
if (hfi_type) {
pi = proto_tree_add_item(fh_hdr, hfi_type, tvb, offset, 2, encoding);
} else {
hfi_type = &hfi_netlink_hdr_type;
pi = proto_tree_add_item(fh_hdr, hfi_type, tvb, offset, 2, encoding);
proto_item_set_text(pi, "Message type: Protocol-specific (0x%04x)", hdr_type);
}
}
if (pi_type) {
*pi_type = pi;
}
if (hfi_type->strings && hfi_type->display & BASE_EXT_STRING) {
proto_item_append_text(fh_hdr, " (type: %s)", val_to_str_ext(hdr_type, (value_string_ext *)hfi_type->strings, "0x%04x"));
} else if (hfi_type->strings) {
proto_item_append_text(fh_hdr, " (type: %s)", val_to_str(hdr_type, (const value_string *)hfi_type->strings, "0x%04x"));
} else {
proto_item_append_text(fh_hdr, " (type: 0x%04x)", hdr_type);
}
offset += 2;
hdr_flags = tvb_get_guint16(tvb, offset, encoding);
if ((hdr_flags & WS_NLM_F_REQUEST) && (hdr_flags & 0x0f00)) {
proto_tree_add_bitmask(fh_hdr, tvb, offset, hfi_netlink_hdr_flags.id,
ett_netlink_hdr_flags, netlink_header_get_flags, encoding);
proto_tree_add_bitmask(fh_hdr, tvb, offset, hfi_netlink_hdr_flags.id,
ett_netlink_hdr_flags, netlink_header_new_flags, encoding);
} else {
proto_tree_add_bitmask(fh_hdr, tvb, offset, hfi_netlink_hdr_flags.id,
ett_netlink_hdr_flags, netlink_header_standard_flags, encoding);
}
offset += 2;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_seq, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_pid, tvb, offset, 4, encoding);
offset += 4;
return offset;
}
static void
dissect_netlink_error(tvbuff_t *tvb, proto_tree *tree, int offset, int encoding)
{
proto_tree_add_item(tree, &hfi_netlink_error, tvb, offset, 4, encoding);
offset += 4;
dissect_netlink_header(tvb, tree, offset, encoding, NULL, NULL);
}
static int
dissect_netlink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data _U_)
{
guint16 protocol, hatype;
proto_item *ti;
tvbuff_t *next_tvb;
proto_tree *fh_tree;
int offset;
int encoding;
guint len_rem, len_le, len_be;
hatype = tvb_get_ntohs(tvb, 2);
if (hatype != ARPHRD_NETLINK)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_protocol_format(tree, hfi_netlink->id, tvb, 0,
SLL_HEADER_SIZE, "Linux netlink (cooked header)");
fh_tree = proto_item_add_subtree(ti, ett_netlink_cooked);
offset = 2;
proto_tree_add_item(fh_tree, &hfi_netlink_hatype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 10;
protocol = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fh_tree, &hfi_netlink_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len_rem = tvb_reported_length_remaining(tvb, offset);
len_le = tvb_get_letohl(tvb, offset);
len_be = tvb_get_ntohl(tvb, offset);
#define abs_diff(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
if (abs_diff(len_be, len_rem) < abs_diff(len_le, len_rem)) {
encoding = ENC_BIG_ENDIAN;
} else {
encoding = ENC_LITTLE_ENDIAN;
}
while (tvb_reported_length_remaining(tvb, offset) >= 16) {
int pkt_end_offset;
guint16 msg_type;
guint32 pkt_len;
guint32 port_id;
proto_tree *fh_msg;
gboolean dissected = FALSE;
pkt_len = tvb_get_guint32(tvb, offset, encoding);
pkt_end_offset = offset + pkt_len;
if (pkt_len < 16) {
proto_tree *fh_hdr;
fh_hdr = proto_tree_add_subtree(tree, tvb, offset, 4, ett_netlink_msghdr, NULL, "Netlink message header");
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_len, tvb, offset, 4, encoding);
break;
}
msg_type = tvb_get_guint16(tvb, offset + 4, encoding);
port_id = tvb_get_guint32(tvb, offset + 12, encoding);
if (port_id == 0x00)
pinfo->p2p_dir = P2P_DIR_SENT;
else
pinfo->p2p_dir = P2P_DIR_RECV;
if (msg_type >= WS_NLMSG_MIN_TYPE && pkt_len > 16) {
struct packet_netlink_data data;
data.magic = PACKET_NETLINK_MAGIC;
data.encoding = encoding;
data.type = msg_type;
next_tvb = tvb_new_subset_length(tvb, offset, pkt_len);
if (dissector_try_uint_new(netlink_dissector_table, protocol, next_tvb, pinfo, tree, TRUE, &data)) {
dissected = TRUE;
}
}
if (!dissected) {
fh_msg = proto_tree_add_subtree(tree, tvb, offset, pkt_len, ett_netlink_msg, NULL, "Netlink message");
offset = dissect_netlink_header(tvb, fh_msg, offset, encoding, NULL, NULL);
if (msg_type == WS_NLMSG_ERROR) {
dissect_netlink_error(tvb, fh_msg, offset, encoding);
} else if (pkt_len > 16) {
next_tvb = tvb_new_subset_length(tvb, offset, pkt_len - 16);
call_data_dissector(next_tvb, pinfo, fh_msg);
}
}
offset = pkt_end_offset;
}
return offset;
}
void
proto_register_netlink(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_netlink_hatype,
&hfi_netlink_family,
&hfi_netlink_hdr_len,
&hfi_netlink_hdr_type,
&hfi_netlink_hdr_flags,
&hfi_netlink_hdr_flag_request,
&hfi_netlink_hdr_flag_multi,
&hfi_netlink_hdr_flag_ack,
&hfi_netlink_hdr_flag_echo,
&hfi_netlink_hdr_flag_dumpintr,
&hfi_netlink_hdr_flag_dumpfiltered,
&hfi_netlink_hdr_flag_root,
&hfi_netlink_hdr_flag_match,
&hfi_netlink_hdr_flag_atomic,
&hfi_netlink_hdr_flag_replace,
&hfi_netlink_hdr_flag_excl,
&hfi_netlink_hdr_flag_create,
&hfi_netlink_hdr_flag_append,
&hfi_netlink_hdr_seq,
&hfi_netlink_hdr_pid,
&hfi_netlink_attr_len,
&hfi_netlink_attr_type,
&hfi_netlink_attr_type_nested,
&hfi_netlink_attr_type_net_byteorder,
&hfi_netlink_attr_index,
&hfi_netlink_attr_data,
&hfi_netlink_error,
};
#endif
static gint *ett[] = {
&ett_netlink_cooked,
&ett_netlink_msghdr,
&ett_netlink_msg,
&ett_netlink_hdr_flags,
&ett_netlink_attr_type,
};
int proto_netlink;
proto_netlink = proto_register_protocol("Linux netlink protocol", "NETLINK", "netlink" );
hfi_netlink = proto_registrar_get_nth(proto_netlink);
proto_register_fields(proto_netlink, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_handle = create_dissector_handle(dissect_netlink, proto_netlink);
netlink_dissector_table = register_dissector_table(
"netlink.protocol",
"Linux netlink protocol type",
proto_netlink, FT_UINT16,
BASE_HEX
);
register_dissector("netlink", dissect_netlink, proto_netlink);
}
void
proto_reg_handoff_netlink(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETLINK, netlink_handle);
}
