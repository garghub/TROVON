void
capture_isl(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint8 type;
if (!BYTES_ARE_IN_FRAME(offset, len, ISL_HEADER_SIZE)) {
ld->other++;
return;
}
type = (pd[offset+5] >> 4)&0x0F;
switch (type) {
case TYPE_ETHER:
offset += 14+12;
capture_eth(pd, offset, len, ld);
break;
case TYPE_TR:
offset += 14+17;
capture_tr(pd, offset, len, ld);
break;
default:
ld->other++;
break;
}
}
void
dissect_isl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int fcs_len)
{
proto_tree *volatile fh_tree = NULL;
proto_tree *dst_tree;
proto_item *ti, *hidden_item;
volatile guint8 type;
volatile guint16 length;
gint captured_length;
tvbuff_t *volatile payload_tvb = NULL;
tvbuff_t *volatile next_tvb;
tvbuff_t *volatile trailer_tvb = NULL;
const char *saved_proto;
void *pd_save;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISL");
col_clear(pinfo->cinfo, COL_INFO);
type = (tvb_get_guint8(tvb, 5) >> 4)&0x0F;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_isl, tvb, 0, ISL_HEADER_SIZE,
"ISL");
fh_tree = proto_item_add_subtree(ti, ett_isl);
ti = proto_tree_add_item(fh_tree, hf_isl_dst, tvb, 0, 6, ENC_NA);
hidden_item = proto_tree_add_item(fh_tree, hf_isl_addr, tvb, 0, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
dst_tree = proto_item_add_subtree(ti, ett_isl_dst);
proto_tree_add_item(dst_tree, hf_isl_type, tvb, 5, 1, ENC_BIG_ENDIAN);
switch (type) {
case TYPE_ETHER:
proto_tree_add_item(dst_tree, hf_isl_user_eth, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(dst_tree, hf_isl_user, tvb, 5, 1, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(fh_tree, hf_isl_src, tvb, 6, 6, ENC_NA);
hidden_item = proto_tree_add_item(fh_tree, hf_isl_addr, tvb, 6, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
length = tvb_get_ntohs(tvb, 12);
if (tree)
proto_tree_add_uint(fh_tree, hf_isl_len, tvb, 12, 2, length);
if (length != 0) {
TRY {
payload_tvb = tvb_new_subset(tvb, 14, length, length);
trailer_tvb = tvb_new_subset_remaining(tvb, 14 + length);
}
CATCH2(BoundsError, ReportedBoundsError) {
payload_tvb = tvb_new_subset(tvb, 14, -1, length);
trailer_tvb = NULL;
}
ENDTRY;
} else {
length = tvb_reported_length_remaining(tvb, 14);
payload_tvb = tvb_new_subset_remaining(tvb, 14);
trailer_tvb = NULL;
}
if (tree) {
tvb_ensure_bytes_exist(payload_tvb, 0, 6);
proto_tree_add_text(fh_tree, payload_tvb, 0, 1, "DSAP: 0x%X", tvb_get_guint8(tvb, 14));
proto_tree_add_text(fh_tree, payload_tvb, 1, 1, "SSAP: 0x%X", tvb_get_guint8(tvb, 15));
proto_tree_add_text(fh_tree, payload_tvb, 2, 1, "Control: 0x%X", tvb_get_guint8(tvb, 16));
proto_tree_add_item(fh_tree, hf_isl_hsa, payload_tvb, 3, 3, ENC_BIG_ENDIAN);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "VLAN ID: %u",
tvb_get_ntohs(tvb, 20) >> 1);
if (tree) {
proto_tree_add_item(fh_tree, hf_isl_vlan_id, payload_tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_bpdu, payload_tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_index, payload_tvb, 8, 2, ENC_BIG_ENDIAN);
}
switch (type) {
case TYPE_ETHER:
if (length >= 12) {
length -= 12;
captured_length = tvb_length_remaining(payload_tvb, 12);
if (captured_length > length)
captured_length = length;
next_tvb = tvb_new_subset(payload_tvb, 12, captured_length, length);
saved_proto = pinfo->current_proto;
pd_save = pinfo->private_data;
TRY {
call_dissector(eth_withfcs_handle, next_tvb, pinfo, tree);
}
CATCH(BoundsError) {
RETHROW;
}
CATCH_ALL {
pinfo->private_data = pd_save;
show_exception(next_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->current_proto = saved_proto;
}
ENDTRY;
add_ethernet_trailer(pinfo, tree, fh_tree, hf_isl_trailer, tvb, trailer_tvb, fcs_len);
}
break;
case TYPE_TR:
if (tree) {
proto_tree_add_item(fh_tree, hf_isl_src_vlan_id, payload_tvb, 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_explorer, payload_tvb, 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_dst_route_descriptor, payload_tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_src_route_descriptor, payload_tvb, 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_fcs_not_incl, payload_tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fh_tree, hf_isl_esize, payload_tvb, 16, 1, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(payload_tvb, 17);
call_dissector(tr_handle, next_tvb, pinfo, tree);
break;
default:
next_tvb = tvb_new_subset_remaining(payload_tvb, 12);
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
void
proto_register_isl(void)
{
static hf_register_info hf[] = {
{ &hf_isl_dst,
{ "Destination", "isl.dst", FT_ETHER, BASE_NONE, NULL, 0x0,
"Destination Address", HFILL }},
{ &hf_isl_type,
{ "Type", "isl.type", FT_UINT8, BASE_DEC,
VALS(type_vals), 0xF0, NULL, HFILL }},
{ &hf_isl_user_eth,
{ "User", "isl.user_eth", FT_UINT8, BASE_DEC,
VALS(user_vals), 0x03, "Priority while passing through switch", HFILL }},
{ &hf_isl_user,
{ "User", "isl.user", FT_UINT8, BASE_HEX, NULL, 0x0F,
"User-defined bits", HFILL }},
{ &hf_isl_src,
{ "Source", "isl.src", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source Hardware Address", HFILL }},
{ &hf_isl_addr,
{ "Source or Destination Address", "isl.addr", FT_ETHER, BASE_NONE, NULL, 0x0,
"Source or Destination Hardware Address", HFILL }},
{ &hf_isl_len,
{ "Length", "isl.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isl_hsa,
{ "HSA", "isl.hsa", FT_UINT24, BASE_HEX, NULL, 0x0,
"High bits of source address", HFILL }},
{ &hf_isl_vlan_id,
{ "VLAN ID", "isl.vlan_id", FT_UINT16, BASE_DEC, NULL,
0xFFFE, "Virtual LAN ID (Color)", HFILL }},
{ &hf_isl_bpdu,
{ "BPDU/CDP/VTP", "isl.bpdu", FT_BOOLEAN, 16,
TFS(&tfs_yes_no), 0x0001, "BPDU/CDP/VTP indicator", HFILL }},
{ &hf_isl_index,
{ "Index", "isl.index", FT_UINT16, BASE_DEC, NULL, 0x0,
"Port index of packet source", HFILL }},
{ &hf_isl_crc,
{ "CRC", "isl.crc", FT_UINT32, BASE_HEX, NULL, 0x0,
"CRC field of encapsulated frame", HFILL }},
{ &hf_isl_src_vlan_id,
{ "Source VLAN ID", "isl.src_vlan_id", FT_UINT16, BASE_DEC, NULL,
0xFFFE, "Source Virtual LAN ID (Color)", HFILL }},
{ &hf_isl_explorer,
{ "Explorer", "isl.explorer", FT_BOOLEAN, 16,
TFS(&explorer_tfs), 0x0001, NULL, HFILL }},
{ &hf_isl_dst_route_descriptor,
{ "Destination route descriptor", "isl.dst_route_desc",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Route descriptor to be used for forwarding", HFILL }},
{ &hf_isl_src_route_descriptor,
{ "Source-route descriptor", "isl.src_route_desc",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Route descriptor to be used for source learning", HFILL }},
{ &hf_isl_fcs_not_incl,
{ "FCS Not Included", "isl.fcs_not_incl", FT_BOOLEAN, 9,
NULL, 0x40, NULL, HFILL }},
{ &hf_isl_esize,
{ "Esize", "isl.esize", FT_UINT8, BASE_DEC, NULL,
0x3F, "Frame size for frames less than 64 bytes", HFILL }},
{ &hf_isl_trailer,
{ "Trailer", "isl.trailer", FT_BYTES, BASE_NONE, NULL, 0x0,
"Ethernet Trailer or Checksum", HFILL }},
};
static gint *ett[] = {
&ett_isl,
&ett_isl_dst,
};
proto_isl = proto_register_protocol("Cisco ISL", "ISL", "isl");
proto_register_field_array(proto_isl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_isl(void)
{
eth_withfcs_handle = find_dissector("eth_withfcs");
tr_handle = find_dissector("tr");
data_handle = find_dissector("data");
}
