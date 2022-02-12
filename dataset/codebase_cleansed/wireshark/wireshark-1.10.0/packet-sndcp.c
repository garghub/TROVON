static void
sndcp_defragment_init(void)
{
reassembly_table_init(&npdu_reassembly_table, &addresses_reassembly_table_functions);
}
static void
dissect_sndcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 addr_field, comp_field, npdu_field1, nsapi, dcomp=0, pcomp=0;
guint16 offset=0, npdu=0, segment=0, npdu_field2;
tvbuff_t *next_tvb, *npdu_tvb;
gint len;
gboolean first, more_frags, unack;
proto_item *ti, *address_field_item, *compression_field_item, *npdu_field_item;
proto_tree *sndcp_tree = NULL, *address_field_tree, *compression_field_tree, *npdu_field_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SNDCP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_sndcp, tvb, 0, -1, ENC_NA);
sndcp_tree = proto_item_add_subtree(ti, ett_sndcp);
}
addr_field = tvb_get_guint8(tvb,offset);
nsapi = addr_field & 0xF;
first = addr_field & MASK_F;
more_frags = addr_field & MASK_M;
unack = addr_field & MASK_T;
if (tree) {
address_field_item = proto_tree_add_uint_format(sndcp_tree,hf_sndcp_nsapi,
tvb, offset,1, nsapi,
"Address field NSAPI: %d", nsapi );
address_field_tree = proto_item_add_subtree(address_field_item, ett_sndcp_address_field);
proto_tree_add_boolean(address_field_tree, hf_sndcp_x, tvb,offset,1, addr_field );
proto_tree_add_boolean(address_field_tree, hf_sndcp_f, tvb,offset,1, addr_field );
proto_tree_add_boolean(address_field_tree, hf_sndcp_t, tvb,offset,1, addr_field );
proto_tree_add_boolean(address_field_tree, hf_sndcp_m, tvb,offset,1, addr_field );
proto_tree_add_uint(address_field_tree, hf_sndcp_nsapib, tvb, offset, 1, addr_field );
}
offset++;
if (first) {
comp_field = tvb_get_guint8(tvb,offset);
dcomp = comp_field & 0xF0;
pcomp = comp_field & 0x0F;
if (tree) {
if (!pcomp) {
if (!dcomp) {
compression_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,1, "No compression");
}
else {
compression_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,1, "Data compression");
}
}
else {
if (!dcomp) {
compression_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,1, "Protocol compression");
}
else {
compression_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,1, "Data and Protocol compression");
}
}
compression_field_tree = proto_item_add_subtree(compression_field_item, ett_sndcp_compression_field);
proto_tree_add_uint(compression_field_tree, hf_sndcp_dcomp, tvb, offset, 1, comp_field );
proto_tree_add_uint(compression_field_tree, hf_sndcp_pcomp, tvb, offset, 1, comp_field );
}
offset++;
if (!unack) {
npdu = npdu_field1 = tvb_get_guint8(tvb,offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "SN-DATA N-PDU %d", npdu_field1);
if (tree) {
npdu_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,1, "Acknowledged mode, N-PDU %d", npdu_field1 );
npdu_field_tree = proto_item_add_subtree(npdu_field_item, ett_sndcp_npdu_field);
proto_tree_add_uint(npdu_field_tree, hf_sndcp_npdu1, tvb, offset, 1, npdu_field1 );
}
offset++;
}
}
if (unack) {
npdu_field2 = tvb_get_ntohs(tvb, offset);
segment = (npdu_field2 & 0xF000) >> 12;
npdu = (npdu_field2 & 0x0FFF);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "SN-UNITDATA N-PDU %d (segment %d)", npdu, segment);
if (tree) {
npdu_field_item = proto_tree_add_text(sndcp_tree, tvb, offset,2, "Unacknowledged mode, N-PDU %d (segment %d)", npdu, segment );
npdu_field_tree = proto_item_add_subtree(npdu_field_item, ett_sndcp_npdu_field);
proto_tree_add_uint(npdu_field_tree, hf_sndcp_segment, tvb, offset, 2, npdu_field2 );
proto_tree_add_uint(npdu_field_tree, hf_sndcp_npdu2, tvb, offset, 2, npdu_field2 );
}
offset += 2;
}
if (first && !more_frags) {
next_tvb = tvb_new_subset_remaining (tvb, offset);
if (!dcomp && !pcomp) {
call_dissector(ip_handle, next_tvb, pinfo, tree);
}
else {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
else {
fragment_data *fd_npdu = NULL;
guint32 reassembled_in = 0;
gboolean save_fragmented = pinfo->fragmented;
len = tvb_length_remaining(tvb, offset);
if(len<=0){
return;
}
pinfo->fragmented = TRUE;
if (unack)
fd_npdu = fragment_add_seq_check(&npdu_reassembly_table, tvb, offset,
pinfo, npdu, NULL, segment, len, more_frags);
else
fd_npdu = fragment_add(&npdu_reassembly_table, tvb, offset, pinfo, npdu, NULL,
offset, len, more_frags);
npdu_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled N-PDU", fd_npdu, &npdu_frag_items,
NULL, sndcp_tree);
if (fd_npdu) {
reassembled_in = fd_npdu->reassembled_in;
if (pinfo->fd->num == reassembled_in) {
call_dissector(ip_handle, npdu_tvb, pinfo, tree);
}
else {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
" (N-PDU payload reassembled in packet %u)",
fd_npdu->reassembled_in);
}
if (tree) {
proto_tree_add_text(sndcp_tree, tvb, offset, -1, "Payload");
}
}
} else {
if (check_col(pinfo->cinfo, COL_INFO)) {
if (unack)
col_append_fstr(pinfo->cinfo, COL_INFO, " (Unreassembled fragment %u)", segment);
else
col_append_str(pinfo->cinfo, COL_INFO, " (Unreassembled fragment)");
}
if (tree) {
proto_tree_add_text(sndcp_tree, tvb, offset, -1, "Payload");
}
}
pinfo->fragmented = save_fragmented;
}
}
void
proto_register_sndcp(void)
{
static hf_register_info hf[] = {
{ &hf_sndcp_nsapi,
{ "NSAPI",
"sndcp.nsapi",
FT_UINT8, BASE_DEC, VALS(nsapi_abrv), 0x0,
"Network Layer Service Access Point Identifier", HFILL
}
},
{ &hf_sndcp_x,
{ "Spare bit",
"sndcp.x",
FT_BOOLEAN,8, TFS(&x_bit), MASK_X,
"Spare bit (should be 0)", HFILL
}
},
{ &hf_sndcp_f,
{ "First segment indicator bit",
"sndcp.f",
FT_BOOLEAN,8, TFS(&f_bit), MASK_F,
NULL, HFILL
}
},
{ &hf_sndcp_t,
{ "Type",
"sndcp.t",
FT_BOOLEAN,8, TFS(&t_bit), MASK_T,
"SN-PDU Type", HFILL
}
},
{ &hf_sndcp_m,
{ "More bit",
"sndcp.m",
FT_BOOLEAN,8, TFS(&m_bit), MASK_M,
NULL, HFILL
}
},
{ &hf_sndcp_dcomp,
{ "DCOMP",
"sndcp.dcomp",
FT_UINT8, BASE_DEC, VALS(compression_vals), 0xF0,
"Data compression coding", HFILL
}
},
{ &hf_sndcp_pcomp,
{ "PCOMP",
"sndcp.pcomp",
FT_UINT8, BASE_DEC, VALS(compression_vals), 0x0F,
"Protocol compression coding", HFILL
}
},
{ &hf_sndcp_nsapib,
{ "NSAPI",
"sndcp.nsapib",
FT_UINT8, BASE_DEC , VALS(nsapi_t), 0xf,
"Network Layer Service Access Point Identifier",HFILL
}
},
{ &hf_sndcp_segment,
{ "Segment",
"sndcp.segment",
FT_UINT16, BASE_DEC, NULL, 0xF000,
"Segment number", HFILL
}
},
{ &hf_sndcp_npdu1,
{ "N-PDU",
"sndcp.npdu",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_sndcp_npdu2,
{ "N-PDU",
"sndcp.npdu",
FT_UINT16, BASE_DEC, NULL, 0x0FFF,
NULL, HFILL
}
},
{ &hf_npdu_fragment_overlap,
{ "Fragment overlap",
"npdu.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL
}
},
{ &hf_npdu_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap",
"npdu.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL
}
},
{ &hf_npdu_fragment_multiple_tails,
{ "Multiple tail fragments found",
"npdu.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL
}
},
{ &hf_npdu_fragment_too_long_fragment,
{ "Fragment too long",
"npdu.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL
}
},
{ &hf_npdu_fragment_error,
{ "Defragmentation error",
"npdu.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL
}
},
{ &hf_npdu_fragment_count,
{ "Fragment count",
"npdu.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_npdu_reassembled_in,
{ "Reassembled in",
"npdu.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"N-PDU fragments are reassembled in the given packet", HFILL
}
},
{ &hf_npdu_reassembled_length,
{ "Reassembled N-PDU length",
"npdu.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL
}
},
{ &hf_npdu_fragment,
{ "N-PDU Fragment",
"npdu.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_npdu_fragments,
{ "N-PDU Fragments",
"npdu.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_sndcp ,
&ett_sndcp_address_field,
&ett_sndcp_compression_field,
&ett_sndcp_npdu_field,
&ett_npdu_fragment,
&ett_npdu_fragments,
};
proto_sndcp = proto_register_protocol("Subnetwork Dependent Convergence Protocol",
"SNDCP", "sndcp");
proto_register_field_array(proto_sndcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sndcp", dissect_sndcp, proto_sndcp);
register_init_routine(sndcp_defragment_init);
}
void
proto_reg_handoff_sndcp(void)
{
dissector_handle_t sndcp_handle;
sndcp_handle = find_dissector("sndcp");
dissector_add_uint("llcgprs.sapi", 3, sndcp_handle);
dissector_add_uint("llcgprs.sapi", 5, sndcp_handle);
dissector_add_uint("llcgprs.sapi", 9, sndcp_handle);
dissector_add_uint("llcgprs.sapi", 11, sndcp_handle);
ip_handle = find_dissector("ip");
data_handle = find_dissector("data");
}
