static void
dissect_bmp_peer_down_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, gint8 flags _U_)
{
guint8 down_reason;
down_reason = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_peer_down_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (down_reason != BMP_PEER_DOWN_REMOTE_NO_NOTIFY) {
if (down_reason == BMP_PEER_DOWN_LOCAL_NO_NOTIFY) {
proto_tree_add_item(tree, hf_peer_down_data, tvb, offset, 2, ENC_NA);
} else {
call_dissector(dissector_bgp, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
}
}
static void
dissect_bmp_peer_up_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, gint8 flags)
{
if (flags & BMP_PEER_FLAG_IPV6) {
proto_tree_add_item(tree, hf_peer_up_ipv6_address, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
proto_tree_add_item(tree, hf_bmp_unused, tvb, offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(tree, hf_peer_up_ipv4_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_peer_up_local_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_peer_up_remote_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
call_dissector(dissector_bgp, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
static void
dissect_bmp_stat_report(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, int offset, gint8 flags _U_)
{
guint16 stat_len;
guint32 i;
guint32 stats_count = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_stats_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < stats_count; i++) {
proto_item *ti;
proto_item *subtree;
ti = proto_tree_add_item(tree, hf_stat_type, tvb, offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(ti, ett_bmp_stat_type);
offset += 2;
stat_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_stat_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (stat_len == 4) {
proto_tree_add_item(subtree, hf_stat_data_4, tvb, offset, stat_len, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(subtree, hf_stat_data_8, tvb, offset, stat_len, ENC_BIG_ENDIAN);
}
offset += stat_len;
}
}
static void
dissect_bmp_termination(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, int offset, guint8 bmp_type _U_, guint16 len)
{
guint16 term_type;
guint16 term_len;
proto_item *ti;
proto_item *subtree;
ti = proto_tree_add_item(tree, hf_term_types, tvb, offset, len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bmp_term_types);
term_type = tvb_get_ntohs(tvb, offset);
proto_item_append_text(subtree, ", Type %s",
val_to_str(term_type, term_typevals, "Unknown (0x%02x)"));
proto_tree_add_item(subtree, hf_term_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
term_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_term_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (term_type == BMP_TERM_TYPE_STRING) {
proto_tree_add_item(subtree, hf_term_info, tvb, offset, term_len, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(subtree, hf_term_reason, tvb, offset, term_len, ENC_BIG_ENDIAN);
}
}
static void
dissect_bmp_peer_header(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint8 bmp_type, guint16 len)
{
guint8 flags;
proto_item *item;
proto_item *ti;
proto_item *subtree;
static const int * peer_flags[] = {
&hf_peer_flags_ipv6,
&hf_peer_flags_post_policy,
&hf_peer_flags_res,
NULL
};
ti = proto_tree_add_item(tree, hf_peer_header, tvb, offset, len, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bmp_peer_header);
proto_tree_add_item(subtree, hf_peer_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(subtree, tvb, offset, hf_peer_flags, ett_bmp_peer_flags, peer_flags, ENC_NA);
offset += 1;
item = proto_tree_add_item(subtree, hf_peer_distinguisher, tvb, offset, 8, ENC_NA);
proto_item_set_text(item, "Peer Distinguisher: %s", decode_bgp_rd(tvb, offset));
offset += 8;
if (flags & BMP_PEER_FLAG_IPV6) {
proto_tree_add_item(subtree, hf_peer_ipv6_address, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
proto_tree_add_item(subtree, hf_bmp_unused, tvb, offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(subtree, hf_peer_ipv4_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(subtree, hf_peer_asn, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_peer_bgp_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_peer_timestamp_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_peer_timestamp_msec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (bmp_type) {
case BMP_MSG_TYPE_ROUTE_MONITORING:
call_dissector(dissector_bgp, tvb_new_subset_remaining(tvb, offset), pinfo, tree);
break;
case BMP_MSG_TYPE_STAT_REPORT:
dissect_bmp_stat_report(tvb, tree, pinfo, offset, flags);
break;
case BMP_MSG_TYPE_PEER_DOWN:
dissect_bmp_peer_down_notification(tvb, tree, pinfo, offset, flags);
break;
case BMP_MSG_TYPE_PEER_UP:
dissect_bmp_peer_up_notification(tvb, tree, pinfo, offset, flags);
break;
case BMP_MSG_TYPE_INIT:
case BMP_MSG_TYPE_TERM:
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
static void
dissect_bmp_init(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, int offset, guint8 bmp_type _U_, guint16 len)
{
guint16 init_type;
guint16 init_len;
proto_tree *pti;
proto_tree *parent_tree;
pti = proto_tree_add_item(tree, hf_init_types, tvb, offset, len, ENC_NA);
parent_tree = proto_item_add_subtree(pti, ett_bmp_init_types);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree *ti;
proto_tree *subtree;
init_type = tvb_get_ntohs(tvb, offset);
proto_item_append_text(pti, ", Type %s",
val_to_str(init_type, init_typevals, "Unknown (0x%02x)"));
ti = proto_tree_add_item(parent_tree, hf_init_type, tvb, offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(ti, ett_bmp_init_type);
offset += 2;
init_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(subtree, hf_init_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_init_info, tvb, offset, init_len, ENC_ASCII|ENC_NA);
offset += init_len;
}
}
static guint
get_bmp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset + 1);
}
static int
dissect_bmp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint8 bmp_type;
guint16 len;
gint arg;
proto_item *ti;
proto_item *bmp_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BMP");
col_clear(pinfo->cinfo, COL_INFO);
bmp_type = tvb_get_guint8(tvb, 5);
col_add_fstr(pinfo->cinfo, COL_INFO, "Type: %s",
val_to_str(bmp_type, bmp_typevals, "Unknown (0x%02x)"));
ti = proto_tree_add_item(tree, proto_bmp, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Type %s",
val_to_str(bmp_type, bmp_typevals, "Unknown (0x%02x)"));
switch (bmp_type) {
case BMP_MSG_TYPE_ROUTE_MONITORING:
arg = ett_bmp_route_monitoring;
break;
case BMP_MSG_TYPE_STAT_REPORT:
arg = ett_bmp_stat_report;
break;
case BMP_MSG_TYPE_PEER_DOWN:
arg = ett_bmp_peer_down;
break;
case BMP_MSG_TYPE_PEER_UP:
arg = ett_bmp_peer_up;
break;
case BMP_MSG_TYPE_INIT:
arg = ett_bmp_init;
break;
case BMP_MSG_TYPE_TERM:
arg = ett_bmp_term;
break;
default:
arg = ett_bmp;
break;
}
bmp_tree = proto_item_add_subtree(ti, arg);
proto_tree_add_item(bmp_tree, hf_bmp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(bmp_tree, hf_bmp_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(bmp_tree, hf_bmp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
switch (bmp_type) {
case BMP_MSG_TYPE_INIT:
dissect_bmp_init(tvb, bmp_tree, pinfo, offset, bmp_type, len);
break;
case BMP_MSG_TYPE_ROUTE_MONITORING:
case BMP_MSG_TYPE_STAT_REPORT:
case BMP_MSG_TYPE_PEER_DOWN:
case BMP_MSG_TYPE_PEER_UP:
dissect_bmp_peer_header(tvb, bmp_tree, pinfo, offset, bmp_type, len);
break;
case BMP_MSG_TYPE_TERM:
dissect_bmp_termination(tvb, bmp_tree, pinfo, offset, bmp_type, len);
break;
default:
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_bmp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, bmp_desegment, FRAME_HEADER_LEN, get_bmp_pdu_len, dissect_bmp_pdu, data);
return tvb_captured_length(tvb);
}
void
proto_register_bmp(void)
{
static hf_register_info hf[] = {
{ &hf_bmp_version,
{ "Version", "bmp.version", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bmp_length,
{ "Length", "bmp.length", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bmp_type,
{ "Type", "bmp.type", FT_UINT8, BASE_DEC,
VALS(bmp_typevals), 0x0, "BMP message type", HFILL }},
{ &hf_bmp_unused,
{ "Unused", "bmp.unused", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_init_types,
{ "Information Types", "bmp.init.types", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_init_type,
{ "Type", "bmp.init.type", FT_UINT16, BASE_DEC,
VALS(init_typevals), 0x0, "Initiation type", HFILL }},
{ &hf_init_length,
{ "Length", "bmp.init.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_init_info,
{ "Information", "bmp.init.info", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_header,
{ "Per Peer Header", "bmp.peer.header", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_type,
{ "Type", "bmp.peer.type", FT_UINT8, BASE_DEC,
VALS(peer_typevals), 0x0, NULL, HFILL }},
{ &hf_peer_flags,
{ "Flags", "bmp.peer.flags", FT_UINT8, BASE_HEX,
NULL, BMP_PEER_FLAG_MASK, NULL, HFILL }},
{ &hf_peer_flags_ipv6,
{ "IPv6", "bmp.peer.flags.ipv6", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BMP_PEER_FLAG_IPV6, NULL, HFILL }},
{ &hf_peer_flags_post_policy,
{ "Post-policy", "bmp.peer.flags.post_policy", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BMP_PEER_FLAG_POST_POLICY, NULL, HFILL }},
{ &hf_peer_flags_res,
{ "Reserved", "bmp.peer.flags.reserved", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), BMP_PEER_FLAG_RES, NULL, HFILL }},
{ &hf_peer_distinguisher,
{ "Peer Distinguisher", "bmp.peer.distinguisher", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_ipv4_address,
{ "Address", "bmp.peer.ip.addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_ipv6_address,
{ "Address", "bmp.peer.ipv6.addr", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_asn,
{ "ASN", "bmp.peer.asn", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_bgp_id,
{ "BGP ID", "bmp.peer.id", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_timestamp_sec,
{ "Timestamp (sec)", "bmp.peer.timestamp.sec", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_timestamp_msec,
{ "Timestamp (msec)", "bmp.peer.timestamp.msec", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_up_ipv4_address,
{ "Local Address", "bmp.peer.up.ip.addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_up_ipv6_address,
{ "Local Address", "bmp.peer.up.ipv6.addr", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_up_local_port,
{ "Local Port", "bmp.peer.up.port.local", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_up_remote_port,
{ "Remote Port", "bmp.peer.up.port.remote", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_peer_down_reason,
{ "Reason", "bmp.peer.down.reason", FT_UINT8, BASE_DEC,
VALS(down_reason_typevals), 0x0, NULL, HFILL }},
{ &hf_peer_down_data,
{ "Data", "bmp.peer.down.data", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_stats_count,
{ "Stats Count", "bmp.stats.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_stat_type,
{ "Type", "bmp.stats.type", FT_UINT16, BASE_DEC,
VALS(stat_typevals), 0x0, NULL, HFILL }},
{ &hf_stat_len,
{ "Length", "bmp.stats.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_stat_data_4,
{ "Data", "bmp.stats.data.4byte", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_stat_data_8,
{ "Data", "bmp.stats.data.8byte", FT_UINT64, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_term_types,
{ "Termination Types", "bmp.term.types", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_term_type,
{ "Type", "bmp.term.type", FT_UINT16, BASE_DEC,
VALS(term_typevals), 0x0, NULL, HFILL }},
{ &hf_term_len,
{ "Length", "bmp.term.length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_term_info,
{ "Information", "bmp.term.info", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_term_reason,
{ "Reason", "bmp.term.reason", FT_UINT16, BASE_DEC,
VALS(term_reason_typevals), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_bmp,
&ett_bmp_route_monitoring,
&ett_bmp_stat_report,
&ett_bmp_stat_type,
&ett_bmp_peer_down,
&ett_bmp_peer_up,
&ett_bmp_peer_header,
&ett_bmp_peer_flags,
&ett_bmp_init,
&ett_bmp_init_type,
&ett_bmp_init_types,
&ett_bmp_term,
&ett_bmp_term_type,
&ett_bmp_term_types,
};
module_t *bmp_module;
proto_bmp = proto_register_protocol(
"BGP Monitoring Protocol",
"BMP",
"bmp"
);
proto_register_field_array(proto_bmp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bmp_module = prefs_register_protocol(proto_bmp, NULL);
prefs_register_bool_preference(bmp_module, "desegment",
"Reassemble BMP messages spanning multiple TCP segments",
"Whether the BMP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&bmp_desegment);
}
void
proto_reg_handoff_bmp(void)
{
static dissector_handle_t bmp_handle;
bmp_handle = new_create_dissector_handle(dissect_bmp, proto_bmp);
dissector_add_for_decode_as("tcp.port", bmp_handle);
dissector_bgp = find_dissector("bgp");
}
