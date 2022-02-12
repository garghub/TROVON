static gchar *
tvb_atalkid_to_str(tvbuff_t *tvb, gint offset)
{
gint node;
gchar *cur;
cur=(gchar *)wmem_alloc(wmem_packet_scope(), 16);
node=tvb_get_guint8(tvb, offset+1)<<8|tvb_get_guint8(tvb, offset+2);
g_snprintf(cur, 16, "%d.%d",node,tvb_get_guint8(tvb, offset+3));
return cur;
}
static const gchar *
tvb_aarphrdaddr_to_str(tvbuff_t *tvb, gint offset, int ad_len, guint16 type)
{
if (AARP_HW_IS_ETHER(type, ad_len)) {
return tvb_ether_to_str(tvb, offset);
}
return tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, ad_len);
}
static gchar *
tvb_aarpproaddr_to_str(tvbuff_t *tvb, gint offset, int ad_len, guint16 type)
{
if (AARP_PRO_IS_ATALK(type, ad_len)) {
return tvb_atalkid_to_str(tvb, offset);
}
return tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, ad_len);
}
static int
dissect_aarp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
guint16 ar_hrd;
guint16 ar_pro;
guint8 ar_hln;
guint8 ar_pln;
guint16 ar_op;
proto_tree *aarp_tree;
proto_item *ti;
const gchar *op_str;
int sha_offset, spa_offset, tha_offset, tpa_offset;
const gchar *sha_str, *spa_str, *tpa_str;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AARP");
col_clear(pinfo->cinfo, COL_INFO);
ar_hrd = tvb_get_ntohs(tvb, AR_HRD);
ar_pro = tvb_get_ntohs(tvb, AR_PRO);
ar_hln = tvb_get_guint8(tvb, AR_HLN);
ar_pln = tvb_get_guint8(tvb, AR_PLN);
ar_op = tvb_get_ntohs(tvb, AR_OP);
sha_offset = MIN_AARP_HEADER_SIZE;
spa_offset = sha_offset + ar_hln;
tha_offset = spa_offset + ar_pln;
tpa_offset = tha_offset + ar_hln;
sha_str = tvb_aarphrdaddr_to_str(tvb, sha_offset, ar_hln, ar_hrd);
spa_str = tvb_aarpproaddr_to_str(tvb, spa_offset, ar_pln, ar_pro);
#if 0
tha_str = tvb_aarphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd);
#endif
tpa_str = tvb_aarpproaddr_to_str(tvb, tpa_offset, ar_pln, ar_pro);
switch (ar_op) {
case AARP_REQUEST:
case AARP_REQUEST_SWAPPED:
col_add_fstr(pinfo->cinfo, COL_INFO, "Who has %s? Tell %s", tpa_str, spa_str);
break;
case AARP_REPLY:
case AARP_REPLY_SWAPPED:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s", spa_str, sha_str);
break;
case AARP_PROBE:
case AARP_PROBE_SWAPPED:
col_add_fstr(pinfo->cinfo, COL_INFO, "Is there a %s", tpa_str);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown AARP opcode 0x%04x", ar_op);
break;
}
if (tree) {
if ((op_str = try_val_to_str(ar_op, op_vals)))
ti = proto_tree_add_protocol_format(tree, proto_aarp, tvb, 0,
MIN_AARP_HEADER_SIZE + 2*ar_hln +
2*ar_pln, "AppleTalk Address Resolution Protocol (%s)", op_str);
else
ti = proto_tree_add_protocol_format(tree, proto_aarp, tvb, 0,
MIN_AARP_HEADER_SIZE + 2*ar_hln +
2*ar_pln,
"AppleTalk Address Resolution Protocol (opcode 0x%04x)", ar_op);
aarp_tree = proto_item_add_subtree(ti, ett_aarp);
proto_tree_add_uint(aarp_tree, hf_aarp_hard_type, tvb, AR_HRD, 2,
ar_hrd);
proto_tree_add_uint(aarp_tree, hf_aarp_proto_type, tvb, AR_PRO, 2,
ar_pro);
proto_tree_add_uint(aarp_tree, hf_aarp_hard_size, tvb, AR_HLN, 1,
ar_hln);
proto_tree_add_uint(aarp_tree, hf_aarp_proto_size, tvb, AR_PLN, 1,
ar_pln);
proto_tree_add_uint(aarp_tree, hf_aarp_opcode, tvb, AR_OP, 2,
ar_op);
if (ar_hln != 0) {
proto_tree_add_item(aarp_tree,
AARP_HW_IS_ETHER(ar_hrd, ar_hln) ? hf_aarp_src_hw_mac : hf_aarp_src_hw,
tvb, sha_offset, ar_hln, ENC_NA);
}
if (ar_pln != 0) {
if (AARP_PRO_IS_ATALK(ar_pro, ar_pln)) {
proto_tree_add_bytes_format_value(aarp_tree, hf_aarp_src_proto_id, tvb,
spa_offset, ar_pln, NULL,
"%s", spa_str);
} else {
proto_tree_add_bytes_format_value(aarp_tree, hf_aarp_src_proto, tvb,
spa_offset, ar_pln, NULL,
"%s", spa_str);
}
}
if (ar_hln != 0) {
proto_tree_add_item(aarp_tree,
AARP_HW_IS_ETHER(ar_hrd, ar_hln) ? hf_aarp_dst_hw_mac : hf_aarp_dst_hw,
tvb, tha_offset, ar_hln, ENC_NA);
}
if (ar_pln != 0) {
if (AARP_PRO_IS_ATALK(ar_pro, ar_pln)) {
proto_tree_add_bytes_format_value(aarp_tree, hf_aarp_dst_proto_id, tvb,
tpa_offset, ar_pln,
NULL, "%s", tpa_str);
} else {
proto_tree_add_bytes_format_value(aarp_tree, hf_aarp_dst_proto, tvb,
tpa_offset, ar_pln,
NULL, "%s", tpa_str);
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_aarp(void)
{
static hf_register_info hf[] = {
{ &hf_aarp_hard_type,
{ "Hardware type", "aarp.hard.type",
FT_UINT16, BASE_HEX, VALS(hrd_vals), 0x0,
NULL, HFILL }},
{ &hf_aarp_proto_type,
{ "Protocol type", "aarp.proto.type",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_aarp_hard_size,
{ "Hardware size", "aarp.hard.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_proto_size,
{ "Protocol size", "aarp.proto.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_opcode,
{ "Opcode", "aarp.opcode",
FT_UINT16, BASE_DEC, VALS(op_vals), 0x0,
NULL, HFILL }},
{ &hf_aarp_src_hw,
{ "Sender hardware address", "aarp.src.hw",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_src_hw_mac,
{ "Sender MAC address", "aarp.src.hw_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_src_proto,
{ "Sender protocol address", "aarp.src.proto",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_src_proto_id,
{ "Sender ID", "aarp.src.proto_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_dst_hw,
{ "Target hardware address", "aarp.dst.hw",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_dst_hw_mac,
{ "Target MAC address", "aarp.dst.hw_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_dst_proto,
{ "Target protocol address", "aarp.dst.proto",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_aarp_dst_proto_id,
{ "Target ID", "aarp.dst.proto_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_aarp,
};
proto_aarp = proto_register_protocol("Appletalk Address Resolution Protocol",
"AARP",
"aarp");
proto_register_field_array(proto_aarp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aarp(void)
{
dissector_handle_t aarp_handle;
aarp_handle = create_dissector_handle(dissect_aarp, proto_aarp);
dissector_add_uint("ethertype", ETHERTYPE_AARP, aarp_handle);
dissector_add_uint("chdlc.protocol", ETHERTYPE_AARP, aarp_handle);
}
