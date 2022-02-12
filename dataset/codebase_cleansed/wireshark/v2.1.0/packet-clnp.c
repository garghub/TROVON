static int
dissect_clnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *clnp_tree;
proto_item *ti, *ti_len = NULL, *ti_pdu_len = NULL, *ti_tot_len = NULL;
guint8 cnf_proto_id;
guint8 cnf_hdr_len;
guint8 cnf_vers;
guint8 cnf_ttl;
guint8 cnf_type;
char flag_string[6+1];
const char *pdu_type_string;
proto_tree *type_tree;
guint16 segment_length;
guint16 du_id = 0;
guint16 segment_offset = 0;
guint16 total_length;
guint16 cnf_cksum;
cksum_status_t cksum_status;
int offset;
guchar src_len, dst_len, nsel, opt_len = 0;
guint next_length;
proto_tree *discpdu_tree;
gboolean save_in_error_pkt;
fragment_head *fd_head;
tvbuff_t *next_tvb;
gboolean update_col_info = TRUE;
gboolean save_fragmented;
heur_dtbl_entry_t *hdtbl_entry;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CLNP");
col_clear(pinfo->cinfo, COL_INFO);
cnf_proto_id = tvb_get_guint8(tvb, P_CLNP_PROTO_ID);
if (cnf_proto_id == NLPID_NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "Inactive subset");
ti = proto_tree_add_item(tree, proto_clnp, tvb, P_CLNP_PROTO_ID, 1, ENC_NA);
clnp_tree = proto_item_add_subtree(ti, ett_clnp);
proto_tree_add_uint_format(clnp_tree, hf_clnp_id, tvb, P_CLNP_PROTO_ID, 1,
cnf_proto_id, "Inactive subset");
next_tvb = tvb_new_subset_remaining(tvb, 1);
call_dissector(ositp_inactive_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
cnf_vers = tvb_get_guint8(tvb, P_CLNP_VERS);
if (cnf_vers != ISO8473_V1) {
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
cnf_hdr_len = tvb_get_guint8(tvb, P_CLNP_HDR_LEN);
ti = proto_tree_add_item(tree, proto_clnp, tvb, 0, cnf_hdr_len, ENC_NA);
clnp_tree = proto_item_add_subtree(ti, ett_clnp);
proto_tree_add_uint(clnp_tree, hf_clnp_id, tvb, P_CLNP_PROTO_ID, 1,
cnf_proto_id);
ti_len = proto_tree_add_uint(clnp_tree, hf_clnp_length, tvb, P_CLNP_HDR_LEN, 1,
cnf_hdr_len);
if (cnf_hdr_len < FIXED_PART_LEN) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < minimum length %u",
FIXED_PART_LEN);
return 2;
}
proto_tree_add_uint(clnp_tree, hf_clnp_version, tvb, P_CLNP_VERS, 1,
cnf_vers);
cnf_ttl = tvb_get_guint8(tvb, P_CLNP_TTL);
proto_tree_add_uint_format(clnp_tree, hf_clnp_ttl, tvb, P_CLNP_TTL, 1,
cnf_ttl,
"Holding Time : %u (%u.%u secs)",
cnf_ttl, cnf_ttl / 2, (cnf_ttl % 2) * 5);
cnf_type = tvb_get_guint8(tvb, P_CLNP_TYPE);
pdu_type_string = val_to_str(cnf_type & CNF_TYPE, npdu_type_abbrev_vals,
"Unknown (0x%02x)");
flag_string[0] = '\0';
if (cnf_type & CNF_SEG_OK)
g_strlcat(flag_string, "S ", 7);
if (cnf_type & CNF_MORE_SEGS)
g_strlcat(flag_string, "M ", 7);
if (cnf_type & CNF_ERR_OK)
g_strlcat(flag_string, "E ", 7);
ti = proto_tree_add_uint_format(clnp_tree, hf_clnp_type, tvb, P_CLNP_TYPE, 1,
cnf_type,
"PDU Type : 0x%02x (%s%s)",
cnf_type,
flag_string,
pdu_type_string);
type_tree = proto_item_add_subtree(ti, ett_clnp_type);
proto_tree_add_item(type_tree, hf_clnp_cnf_segmentation, tvb, P_CLNP_TYPE, 1, ENC_NA);
proto_tree_add_item(type_tree, hf_clnp_cnf_more_segments, tvb, P_CLNP_TYPE, 1, ENC_NA);
proto_tree_add_item(type_tree, hf_clnp_cnf_report_error, tvb, P_CLNP_TYPE, 1, ENC_NA);
proto_tree_add_item(type_tree, hf_clnp_cnf_type, tvb, P_CLNP_TYPE, 1, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) < cnf_hdr_len) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s NPDU %s", pdu_type_string, flag_string);
}
segment_length = tvb_get_ntohs(tvb, P_CLNP_SEGLEN);
ti_pdu_len = proto_tree_add_uint(clnp_tree, hf_clnp_pdu_length, tvb, P_CLNP_SEGLEN, 2,
segment_length);
if (segment_length < cnf_hdr_len) {
expert_add_info_format(pinfo, ti_pdu_len, &ei_clnp_length,
"PDU length < header length %u", cnf_hdr_len);
return 7;
}
cnf_cksum = tvb_get_ntohs(tvb, P_CLNP_CKSUM);
cksum_status = calc_checksum(tvb, 0, cnf_hdr_len, cnf_cksum);
switch (cksum_status) {
default:
proto_tree_add_uint(clnp_tree, hf_clnp_checksum, tvb,
P_CLNP_CKSUM, 2,
cnf_cksum);
break;
case CKSUM_OK:
proto_tree_add_uint_format_value(clnp_tree, hf_clnp_checksum, tvb,
P_CLNP_CKSUM, 2,
cnf_cksum,
"0x%04x (correct)",
cnf_cksum);
break;
case CKSUM_NOT_OK:
proto_tree_add_uint_format_value(clnp_tree, hf_clnp_checksum, tvb,
P_CLNP_CKSUM, 2,
cnf_cksum,
"0x%04x (incorrect)",
cnf_cksum);
break;
}
opt_len = cnf_hdr_len;
opt_len -= FIXED_PART_LEN;
offset = P_CLNP_ADDRESS_PART;
if (opt_len < 1) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < %u",
FIXED_PART_LEN + 1);
return offset;
}
dst_len = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(clnp_tree, hf_clnp_dest_length, tvb, offset, 1,
dst_len);
}
offset += 1;
opt_len -= 1;
if (opt_len < dst_len) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < %u",
FIXED_PART_LEN + 1 + dst_len);
return offset;
}
nsel = tvb_get_guint8(tvb, offset + dst_len - 1);
set_address_tvb(&pinfo->net_dst, get_osi_address_type(), dst_len, tvb, offset);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
proto_tree_add_bytes_format_value(clnp_tree, hf_clnp_dest, tvb, offset, dst_len,
NULL,
"%s",
print_nsap_net(tvb, offset, dst_len));
offset += dst_len;
opt_len -= dst_len;
if (opt_len < 1) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < %u",
FIXED_PART_LEN + 1 + dst_len + 1);
return offset;
}
src_len = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(clnp_tree, hf_clnp_src_length, tvb,
offset, 1, src_len);
}
offset += 1;
opt_len -= 1;
if (opt_len < src_len) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < %u",
FIXED_PART_LEN + 1 + dst_len + 1 + src_len);
return offset;
}
set_address_tvb(&pinfo->net_src, get_osi_address_type(), src_len, tvb, offset);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
proto_tree_add_bytes_format_value(clnp_tree, hf_clnp_src, tvb, offset, src_len,
NULL,
"%s",
print_nsap_net(tvb, offset, src_len));
offset += src_len;
opt_len -= src_len;
if (cnf_type & CNF_SEG_OK) {
if (opt_len < SEGMENTATION_PART_LEN) {
expert_add_info_format(pinfo, ti_len, &ei_clnp_length,
"Header length value < %u",
FIXED_PART_LEN + 1 + dst_len + 1 + SEGMENTATION_PART_LEN);
return offset;
}
du_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(clnp_tree, hf_clnp_data_unit_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
segment_offset = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(clnp_tree, hf_clnp_segment_offset, tvb, offset + 2 , 2, ENC_BIG_ENDIAN);
total_length = tvb_get_ntohs(tvb, offset + 4);
ti_tot_len = proto_tree_add_item(clnp_tree, hf_clnp_total_length, tvb, offset + 4 , 2, ENC_BIG_ENDIAN);
if (total_length < segment_length) {
expert_add_info_format(pinfo, ti_tot_len, &ei_clnp_length,
"Total length < segment length %u", segment_length);
return offset;
}
offset += SEGMENTATION_PART_LEN;
opt_len -= SEGMENTATION_PART_LEN;
}
dissect_osi_options(opt_len, tvb, offset, clnp_tree, pinfo);
offset += opt_len;
save_fragmented = pinfo->fragmented;
if (clnp_reassemble && (cnf_type & CNF_SEG_OK) &&
((cnf_type & CNF_MORE_SEGS) || segment_offset != 0) &&
tvb_bytes_exist(tvb, offset, segment_length - cnf_hdr_len) &&
segment_length > cnf_hdr_len &&
cksum_status != CKSUM_NOT_OK) {
fd_head = fragment_add_check(&clnp_reassembly_table,
tvb, offset, pinfo, du_id, NULL,
segment_offset, segment_length - cnf_hdr_len,
cnf_type & CNF_MORE_SEGS);
next_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled CLNP",
fd_head, &clnp_frag_items, &update_col_info, clnp_tree);
} else {
if ((cnf_type & CNF_SEG_OK) && segment_offset != 0) {
next_tvb = NULL;
} else {
next_tvb = tvb_new_subset_length(tvb, offset, segment_length - cnf_hdr_len);
tvb_set_fragment(next_tvb);
if ((cnf_type & (CNF_SEG_OK|CNF_MORE_SEGS)) == (CNF_SEG_OK|CNF_MORE_SEGS))
pinfo->fragmented = TRUE;
else
pinfo->fragmented = FALSE;
}
}
if (next_tvb == NULL) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Fragmented %s NPDU %s(off=%u)",
pdu_type_string, flag_string, segment_offset);
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
if (tvb_offset_exists(tvb, offset)) {
switch (cnf_type & CNF_TYPE) {
case DT_NPDU:
case MD_NPDU:
if (nsel==NSEL_NET && tvb_get_guint8(next_tvb, 0)==NLPID_ISO10747_IDRP) {
if(call_dissector(idrp_handle, next_tvb, pinfo, tree) != 0) {
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
}
if (nsel == (guchar)tp_nsap_selector || always_decode_transport) {
if (call_dissector(ositp_handle, next_tvb, pinfo, tree) != 0) {
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
}
if (dissector_try_heuristic(clnp_heur_subdissector_list, next_tvb,
pinfo, tree, &hdtbl_entry, NULL)) {
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
break;
case ER_NPDU:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s NPDU %s", pdu_type_string, flag_string);
next_length = tvb_reported_length_remaining(tvb, offset);
if (next_length != 0) {
discpdu_tree = proto_tree_add_subtree(clnp_tree, tvb, offset, next_length,
ett_clnp_disc_pdu, NULL, "Discarded PDU");
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
call_dissector(clnp_handle, next_tvb, pinfo, discpdu_tree);
pinfo->flags.in_error_pkt = save_in_error_pkt;
}
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
case ERQ_NPDU:
case ERP_NPDU:
break;
}
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s NPDU %s", pdu_type_string, flag_string);
call_data_dissector(next_tvb, pinfo, tree);
pinfo->fragmented = save_fragmented;
return tvb_captured_length(tvb);
}
static void
clnp_reassemble_init(void)
{
reassembly_table_init(&clnp_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
clnp_reassemble_cleanup(void)
{
reassembly_table_destroy(&clnp_reassembly_table);
}
void
proto_register_clnp(void)
{
static hf_register_info hf[] = {
{ &hf_clnp_id,
{ "Network Layer Protocol Identifier", "clnp.nlpi", FT_UINT8, BASE_HEX,
VALS(nlpid_vals), 0x0, NULL, HFILL }},
{ &hf_clnp_length,
{ "HDR Length", "clnp.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_version,
{ "Version", "clnp.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_ttl,
{ "Holding Time", "clnp.ttl", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_type,
{ "PDU Type", "clnp.type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_cnf_segmentation,
{ "Segmentation permitted", "clnp.cnf.segmentation", FT_BOOLEAN, 8, TFS(&tfs_yes_no), CNF_SEG_OK, NULL, HFILL }},
{ &hf_clnp_cnf_more_segments,
{ "More segments", "clnp.cnf.more_segments", FT_BOOLEAN, 8, TFS(&tfs_yes_no), CNF_MORE_SEGS, NULL, HFILL }},
{ &hf_clnp_cnf_report_error,
{ "Report error if PDU discarded", "clnp.cnf.report_error", FT_BOOLEAN, 8, TFS(&tfs_yes_no), CNF_ERR_OK, NULL, HFILL }},
{ &hf_clnp_cnf_type,
{ "Type", "clnp.cnf.type", FT_UINT8, BASE_DEC, VALS(npdu_type_vals), CNF_TYPE, NULL, HFILL }},
{ &hf_clnp_pdu_length,
{ "PDU length", "clnp.pdu.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_data_unit_identifier,
{ "Data unit identifier", "clnp.data_unit_identifier", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_segment_offset,
{ "Segment offset", "clnp.segment_offset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_total_length,
{ "Total length", "clnp.total_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_checksum,
{ "Checksum", "clnp.checksum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_dest_length,
{ "DAL", "clnp.dsap.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_dest,
{ "DA", "clnp.dsap", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_src_length,
{ "SAL", "clnp.ssap.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_src,
{ "SA", "clnp.ssap", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_atntt,
{ "ATN traffic type", "clnp.atn.tt", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_atnsc,
{ "ATN security classification", "clnp.atn.sc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_clnp_segment_overlap,
{ "Segment overlap", "clnp.segment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment overlaps with other segments", HFILL }},
{ &hf_clnp_segment_overlap_conflict,
{ "Conflicting data in segment overlap", "clnp.segment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping segments contained conflicting data", HFILL }},
{ &hf_clnp_segment_multiple_tails,
{ "Multiple tail segments found", "clnp.segment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when reassembling the packet", HFILL }},
{ &hf_clnp_segment_too_long_segment,
{ "Segment too long", "clnp.segment.toolongsegment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of packet", HFILL }},
{ &hf_clnp_segment_error,
{ "Reassembly error", "clnp.segment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Reassembly error due to illegal segments", HFILL }},
{ &hf_clnp_segment_count,
{ "Segment count", "clnp.segment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_clnp_segment,
{ "CLNP Segment", "clnp.segment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_clnp_segments,
{ "CLNP Segments", "clnp.segments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_clnp_reassembled_in,
{ "Reassembled CLNP in frame", "clnp.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This CLNP packet is reassembled in this frame", HFILL }},
{ &hf_clnp_reassembled_length,
{ "Reassembled CLNP length", "clnp.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }}
};
static gint *ett[] = {
&ett_clnp,
&ett_clnp_type,
&ett_clnp_segments,
&ett_clnp_segment,
&ett_clnp_disc_pdu,
};
static ei_register_info ei[] = {
{ &ei_clnp_length, { "clnp.len.bad", PI_MALFORMED, PI_ERROR, "Header length value bad", EXPFILL }},
};
module_t *clnp_module;
expert_module_t* expert_clnp;
proto_clnp = proto_register_protocol(PROTO_STRING_CLNP, "CLNP", "clnp");
proto_register_field_array(proto_clnp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_clnp = expert_register_protocol(proto_clnp);
expert_register_field_array(expert_clnp, ei, array_length(ei));
clnp_handle = register_dissector("clnp", dissect_clnp, proto_clnp);
clnp_heur_subdissector_list = register_heur_dissector_list("clnp", proto_clnp);
register_init_routine(clnp_reassemble_init);
register_cleanup_routine(clnp_reassemble_cleanup);
register_osi_address_type();
clnp_module = prefs_register_protocol(proto_clnp, NULL);
prefs_register_uint_preference(clnp_module, "tp_nsap_selector",
"NSAP selector for Transport Protocol (last byte in hex)",
"NSAP selector for Transport Protocol (last byte in hex)",
16, &tp_nsap_selector);
prefs_register_bool_preference(clnp_module, "always_decode_transport",
"Always try to decode NSDU as transport PDUs",
"Always try to decode NSDU as transport PDUs",
&always_decode_transport);
prefs_register_bool_preference(clnp_module, "reassemble",
"Reassemble segmented CLNP datagrams",
"Whether segmented CLNP datagrams should be reassembled",
&clnp_reassemble);
prefs_register_bool_preference(clnp_module, "decode_atn_options",
"Decode ATN security label",
"Whether ATN security label should be decoded",
&clnp_decode_atn_options);
}
void
proto_reg_handoff_clnp(void)
{
ositp_handle = find_dissector_add_dependency("ositp", proto_clnp);
ositp_inactive_handle = find_dissector_add_dependency("ositp_inactive", proto_clnp);
idrp_handle = find_dissector_add_dependency("idrp", proto_clnp);
dissector_add_uint("osinl.incl", NLPID_ISO8473_CLNP, clnp_handle);
dissector_add_uint("osinl.incl", NLPID_NULL, clnp_handle);
dissector_add_uint("x.25.spi", NLPID_ISO8473_CLNP, clnp_handle);
}
