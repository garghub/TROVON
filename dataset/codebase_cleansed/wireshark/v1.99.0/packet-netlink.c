int
dissect_netlink_attributes(tvbuff_t *tvb, header_field_info *hfi_type, int ett, void *data, proto_tree *tree, int offset, netlink_attributes_cb_t cb)
{
offset = (offset + 3) & ~3;
while (tvb_length_remaining(tvb, offset) >= 4) {
guint16 rta_len, rta_type;
int end_offset;
proto_item *ti;
proto_tree *attr_tree;
rta_len = tvb_get_letohs(tvb, offset);
if (rta_len < 4) {
break;
}
end_offset = (offset + rta_len + 3) & ~3;
attr_tree = proto_tree_add_subtree(tree, tvb, offset, end_offset - offset, ett, &ti, "Attribute");
proto_tree_add_item(attr_tree, &hfi_netlink_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
rta_type = tvb_get_letohs(tvb, offset);
proto_tree_add_item(attr_tree, hfi_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (hfi_type->strings) {
const char *rta_str = try_val_to_str(rta_type, (const value_string *) hfi_type->strings);
if (rta_str)
proto_item_append_text(ti, ": %s", rta_str);
}
if (!cb(tvb, data, attr_tree, rta_type, offset, rta_len - 4)) {
}
if (end_offset <= offset)
break;
offset = end_offset;
}
return offset;
}
static int
dissect_netlink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data _U_)
{
guint16 protocol, hatype;
proto_item *ti;
tvbuff_t *next_tvb;
proto_tree *fh_tree = NULL;
int offset;
hatype = tvb_get_ntohs(tvb, 2);
if (hatype != ARPHRD_NETLINK)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_protocol_format(tree, hfi_netlink->id, tvb, 0,
SLL_HEADER_SIZE, "Linux netlink (cooked header)");
fh_tree = proto_item_add_subtree(ti, ett_netlink_cooked);
}
offset = 2;
proto_tree_add_item(fh_tree, &hfi_netlink_hatype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 10;
protocol = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fh_tree, &hfi_netlink_family, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (tvb_reported_length_remaining(tvb, offset) >= 16) {
struct packet_netlink_data data;
int pkt_end_offset;
guint32 pkt_len;
guint32 port_id;
proto_tree *fh_msg;
proto_tree *fh_hdr;
int encoding = ENC_LITTLE_ENDIAN;
pkt_len = tvb_get_letohl(tvb, offset);
pkt_end_offset = offset + pkt_len;
fh_msg = proto_tree_add_subtree(tree, tvb, offset, pkt_len, ett_netlink_msg, NULL, "Netlink message");
fh_hdr = proto_tree_add_subtree(fh_msg, tvb, offset, 16, ett_netlink_msghdr, NULL, "Header");
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_len, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_type, tvb, offset, 2, encoding);
data.type = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_flags, tvb, offset, 2, encoding);
offset += 2;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_seq, tvb, offset, 4, encoding);
offset += 4;
proto_tree_add_item(fh_hdr, &hfi_netlink_hdr_pid, tvb, offset, 4, encoding);
port_id = tvb_get_letohl(tvb, offset);
offset += 4;
if (port_id == 0x00)
pinfo->p2p_dir = P2P_DIR_SENT;
else
pinfo->p2p_dir = P2P_DIR_RECV;
if (pkt_len > 16) {
data.magic = PACKET_NETLINK_MAGIC;
data.encoding = encoding;
next_tvb = tvb_new_subset_length(tvb, offset, pkt_len-16);
if (!dissector_try_uint_new(netlink_dissector_table, protocol, next_tvb, pinfo, fh_msg, TRUE, &data))
call_dissector(data_handle, next_tvb, pinfo, fh_msg);
} else if (pkt_len != 16) {
break;
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
&hfi_netlink_hdr_seq,
&hfi_netlink_hdr_pid,
};
#endif
static gint *ett[] = {
&ett_netlink_cooked,
&ett_netlink_msghdr,
&ett_netlink_msg
};
int proto_netlink;
proto_netlink = proto_register_protocol("Linux netlink protocol", "NETLINK", "netlink" );
hfi_netlink = proto_registrar_get_nth(proto_netlink);
proto_register_fields(proto_netlink, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_handle = new_create_dissector_handle(dissect_netlink, proto_netlink);
netlink_dissector_table = register_dissector_table(
"netlink.protocol",
"Linux netlink protocol type",
FT_UINT16,
BASE_HEX
);
}
void
proto_reg_handoff_netlink(void)
{
data_handle = find_dissector("data");
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETLINK, netlink_handle);
}
