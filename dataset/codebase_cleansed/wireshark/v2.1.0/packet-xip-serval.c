static guint8
display_xip_serval_control_ext(tvbuff_t *tvb, proto_tree *xip_serval_tree,
gint offset, guint8 type, guint8 length)
{
proto_tree *cext_tree;
proto_item *ti;
ti = proto_tree_add_item(xip_serval_tree, hf_xip_serval_cext, tvb,
offset, length, ENC_NA);
cext_tree = proto_item_add_subtree(ti, ett_xip_serval_cext);
proto_tree_add_uint(cext_tree, hf_xip_serval_ext_type, tvb,
offset, 1, type);
offset++;
ti = proto_tree_add_item(cext_tree, hf_xip_serval_ext_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " bytes");
offset++;
proto_tree_add_bitmask(cext_tree, tvb, offset,
hf_xip_serval_cext_flags, ett_xip_serval_cext_flags,
xip_serval_cext_flags, ENC_BIG_ENDIAN);
offset++;
offset++;
proto_tree_add_item(cext_tree, hf_xip_serval_cext_verno,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cext_tree, hf_xip_serval_cext_ackno,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cext_tree, hf_xip_serval_cext_nonce,
tvb, offset, 8, ENC_NA);
return XIP_SERVAL_CEXT_LEN;
}
static guint8
display_xip_serval_ext(tvbuff_t *tvb, packet_info *pinfo, proto_item *ti,
proto_tree *xip_serval_tree, gint offset)
{
guint8 type = tvb_get_guint8(tvb, offset) & XIP_SERVAL_EXT_TYPE_MASK;
guint8 length = tvb_get_guint8(tvb, offset + 1);
switch (type) {
case XIP_SERVAL_EXT_TYPE_CONTROL:
return display_xip_serval_control_ext(tvb, xip_serval_tree,
offset, type, length);
default:
expert_add_info_format(pinfo, ti, &ei_xip_serval_bad_ext,
"Unrecognized Serval extension header type: 0x%02x",
type);
return 0;
}
}
static void
display_xip_serval(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *xip_serval_tree;
proto_item *ti, *check_ti, *hl_ti;
tvbuff_t *next_tvb;
vec_t cksum_vec;
gint offset;
guint16 packet_checksum, actual_checksum;
guint8 xsh_len, protocol, bytes_remaining;
xsh_len = tvb_get_guint8(tvb, XSRVL_LEN) << 2;
ti = proto_tree_add_item(tree, proto_xip_serval, tvb,
0, xsh_len, ENC_NA);
xip_serval_tree = proto_item_add_subtree(ti, ett_xip_serval_tree);
hl_ti = proto_tree_add_item(xip_serval_tree, hf_xip_serval_hl, tvb,
XSRVL_LEN, 1, ENC_BIG_ENDIAN);
proto_item_append_text(hl_ti, " bytes");
if (tvb_captured_length(tvb) < xsh_len)
expert_add_info_format(pinfo, hl_ti, &ei_xip_serval_bad_len,
"Header Length field (%d bytes) cannot be greater than actual number of bytes left in packet (%d bytes)",
xsh_len, tvb_captured_length(tvb));
proto_tree_add_item(xip_serval_tree, hf_xip_serval_proto, tvb,
XSRVL_PRO, 1, ENC_BIG_ENDIAN);
protocol = tvb_get_guint8(tvb, XSRVL_PRO);
if (!try_val_to_str(protocol, xip_serval_proto_vals))
expert_add_info_format(pinfo, ti, &ei_xip_serval_bad_proto,
"Unrecognized protocol type: %d", protocol);
SET_CKSUM_VEC_TVB(cksum_vec, tvb, 0, xsh_len);
actual_checksum = in_cksum(&cksum_vec, 1);
packet_checksum = tvb_get_ntohs(tvb, XSRVL_CHK);
if (actual_checksum == 0) {
proto_tree_add_uint_format(xip_serval_tree,
hf_xip_serval_check, tvb, XSRVL_CHK, 2, packet_checksum,
"Header checksum: 0x%04x [correct]", packet_checksum);
} else {
check_ti = proto_tree_add_uint_format(xip_serval_tree,
hf_xip_serval_check, tvb, XSRVL_CHK, 2, packet_checksum,
"Header checksum: 0x%04x [incorrect, should be 0x%04x]",
packet_checksum,
in_cksum_shouldbe(packet_checksum, actual_checksum));
expert_add_info_format(pinfo, check_ti,
&ei_xip_serval_bad_checksum, "Bad checksum");
}
offset = XSRVL_EXT;
bytes_remaining = xsh_len - offset;
while (bytes_remaining >= XIP_SERVAL_EXT_MIN_LEN) {
gint8 bytes_displayed = display_xip_serval_ext(tvb, pinfo, ti,
xip_serval_tree, offset);
if (bytes_displayed <= 0)
return;
offset += bytes_displayed;
bytes_remaining -= bytes_displayed;
}
switch (protocol) {
case XIP_SERVAL_PROTO_DATA:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
break;
case IP_PROTO_TCP: {
guint8 tcp_len = hi_nibble(tvb_get_guint8(tvb, offset + 12))*4;
next_tvb = tvb_new_subset(tvb, offset, tcp_len, tcp_len);
call_dissector(tcp_handle, next_tvb, pinfo, tree);
break;
}
case IP_PROTO_UDP:
next_tvb = tvb_new_subset(tvb, offset, 8, 8);
call_dissector(udp_handle, next_tvb, pinfo, tree);
break;
default:
break;
}
}
static gint
dissect_xip_serval(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
if (tvb_reported_length(tvb) < XIP_SERVAL_MIN_LEN)
return 0;
col_append_str(pinfo->cinfo, COL_INFO, " (with Serval)");
display_xip_serval(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_xip_serval(void)
{
static hf_register_info hf[] = {
{ &hf_xip_serval_hl,
{ "Header Length", "xip_serval.hl", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_proto,
{ "Protocol", "xip_serval.proto", FT_UINT8,
BASE_DEC, VALS(xip_serval_proto_vals), 0x0, NULL, HFILL }},
{ &hf_xip_serval_check,
{ "Checksum", "xip_serval.check", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_ext_type,
{ "Extension Type", "xip_serval.ext_type", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_ext_length,
{ "Extension Length", "xip_serval.ext_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_cext,
{ "Serval Control Extension", "xip_serval.cext",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_cext_flags,
{ "Flags", "xip_serval.cext_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_cext_syn,
{ "SYN", "xip_serval.cext_syn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }},
{ &hf_xip_serval_cext_rsyn,
{ "RSYN", "xip_serval.cext_rsyn", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }},
{ &hf_xip_serval_cext_ack,
{ "ACK", "xip_serval.cext_ack", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }},
{ &hf_xip_serval_cext_nack,
{ "NACK", "xip_serval.cext_nack", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }},
{ &hf_xip_serval_cext_rst,
{ "RST", "xip_serval.cext_rst", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_xip_serval_cext_fin,
{ "FIN", "xip_serval.cext_fin", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }},
{ &hf_xip_serval_cext_verno,
{ "Version Number", "xip_serval.cext_verno", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_cext_ackno,
{ "Acknowledgement Number", "xip_serval.cext_ackno",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_serval_cext_nonce,
{ "Nonce", "xip_serval.cext_nonce", FT_BYTES,
SEP_SPACE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_xip_serval_tree,
&ett_xip_serval_cext,
&ett_xip_serval_cext_flags
};
static ei_register_info ei[] = {
{ &ei_xip_serval_bad_len,
{ "xip_serval.bad_len", PI_MALFORMED, PI_ERROR,
"Bad header length", EXPFILL }},
{ &ei_xip_serval_bad_ext,
{ "xip_serval.bad_ext", PI_MALFORMED, PI_ERROR,
"Bad extension header type", EXPFILL }},
{ &ei_xip_serval_bad_proto,
{ "xip_serval.bad_proto", PI_MALFORMED, PI_ERROR,
"Bad protocol type", EXPFILL }},
{ &ei_xip_serval_bad_checksum,
{ "xip_serval.bad_checksum", PI_MALFORMED, PI_ERROR,
"Incorrect checksum", EXPFILL }}
};
expert_module_t* expert_xip_serval;
proto_xip_serval = proto_register_protocol(
"XIP Serval",
"XIP Serval",
"xipserval");
register_dissector("xipserval", dissect_xip_serval,
proto_xip_serval);
proto_register_field_array(proto_xip_serval, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_xip_serval = expert_register_protocol(proto_xip_serval);
expert_register_field_array(expert_xip_serval, ei, array_length(ei));
}
void
proto_reg_handoff_xip_serval(void)
{
tcp_handle = find_dissector_add_dependency("tcp", proto_xip_serval);
udp_handle = find_dissector_add_dependency("udp", proto_xip_serval);
}
