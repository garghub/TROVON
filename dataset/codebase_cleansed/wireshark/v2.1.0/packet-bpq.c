static int
dissect_bpq( tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_ )
{
proto_item *ti;
proto_tree *bpq_tree;
int offset;
guint16 bpq_len;
tvbuff_t *next_tvb;
col_set_str( pinfo->cinfo, COL_PROTOCOL, "BPQ" );
col_clear( pinfo->cinfo, COL_INFO );
offset = 0;
bpq_len = tvb_get_letohs( tvb, offset );
col_add_fstr( pinfo->cinfo, COL_INFO, "%u", bpq_len );
if ( parent_tree )
{
offset = 0;
ti = proto_tree_add_protocol_format( parent_tree, proto_bpq, tvb, offset, BPQ_HEADER_SIZE,
"BPQ, Len: %u",
bpq_len & 0xfff
);
bpq_tree = proto_item_add_subtree( ti, ett_bpq );
proto_tree_add_item( bpq_tree, hf_bpq_len, tvb, offset, BPQ_HEADER_SIZE, ENC_LITTLE_ENDIAN );
}
offset += BPQ_HEADER_SIZE;
next_tvb = tvb_new_subset_remaining( tvb, offset );
call_dissector( ax25_handle, next_tvb, pinfo, parent_tree );
return tvb_captured_length(tvb);
}
static gboolean
capture_bpq( const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
int l_offset;
if ( ! BYTES_ARE_IN_FRAME( offset, len, BPQ_HEADER_SIZE ) )
return FALSE;
l_offset = offset;
l_offset += BPQ_HEADER_SIZE;
return capture_ax25( pd, l_offset, len, cpinfo, pseudo_header );
}
void
proto_register_bpq(void)
{
static hf_register_info hf[] = {
{ &hf_bpq_len,
{ "BPQ len", "bpq.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bpq,
};
proto_bpq = proto_register_protocol( "Amateur Radio BPQ", "BPQ", "bpq" );
bpq_handle = register_dissector("bpq", dissect_bpq, proto_bpq);
proto_register_field_array( proto_bpq, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_bpq(void)
{
dissector_add_uint("ethertype", ETHERTYPE_BPQ, bpq_handle);
register_capture_dissector("ethertype", ETHERTYPE_BPQ, capture_bpq, proto_bpq);
ax25_handle = find_dissector_add_dependency( "ax25", proto_bpq );
}
