static int
dissect_trill( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
proto_item *ti ;
proto_tree *trill_tree ;
guint32 op_len ;
tvbuff_t *next_tvb ;
int offset = 0 ;
col_set_str( pinfo->cinfo, COL_PROTOCOL, TRILL_PROTO_COL_NAME ) ;
col_set_str( pinfo->cinfo, COL_INFO, TRILL_PROTO_COL_INFO ) ;
op_len = tvb_get_bits( tvb, 5, 5, ENC_BIG_ENDIAN ) * TRILL_OP_LENGTH_BYTE_UNITS ;
if (tree) {
ti = proto_tree_add_item( tree, proto_trill, tvb, 0,
TRILL_MIN_FRAME_LENGTH + op_len, ENC_NA ) ;
trill_tree = proto_item_add_subtree( ti, ett_trill ) ;
proto_tree_add_item( trill_tree, hf_trill_version, tvb, offset,
TRILL_BIT_FIELDS_LEN, ENC_BIG_ENDIAN ) ;
proto_tree_add_item( trill_tree, hf_trill_reserved, tvb, offset,
TRILL_BIT_FIELDS_LEN, ENC_BIG_ENDIAN ) ;
proto_tree_add_item( trill_tree, hf_trill_multi_dst, tvb, offset,
TRILL_BIT_FIELDS_LEN, ENC_BIG_ENDIAN ) ;
proto_tree_add_item( trill_tree, hf_trill_op_len, tvb, offset,
TRILL_BIT_FIELDS_LEN, ENC_BIG_ENDIAN ) ;
proto_tree_add_item( trill_tree, hf_trill_hop_cnt, tvb, offset,
TRILL_BIT_FIELDS_LEN, ENC_BIG_ENDIAN ) ;
offset += TRILL_BIT_FIELDS_LEN ;
proto_tree_add_item( trill_tree, hf_trill_egress_nick, tvb, offset,
TRILL_NICKNAME_LEN, ENC_BIG_ENDIAN ) ;
offset += TRILL_NICKNAME_LEN ;
proto_tree_add_item( trill_tree, hf_trill_ingress_nick, tvb, offset,
TRILL_NICKNAME_LEN , ENC_BIG_ENDIAN ) ;
offset += TRILL_NICKNAME_LEN ;
if( op_len != 0 ) {
proto_tree_add_item( trill_tree, hf_trill_options, tvb,
offset, op_len, ENC_NA ) ;
}
}
next_tvb = tvb_new_subset_remaining( tvb, TRILL_MIN_FRAME_LENGTH + op_len ) ;
call_dissector( eth_dissector, next_tvb, pinfo, tree ) ;
return tvb_reported_length( tvb ) ;
}
void
proto_register_trill(void)
{
static hf_register_info hf[] = {
{ &hf_trill_version,
{ "Version", "trill.version",
FT_UINT16, BASE_DEC_HEX|BASE_RANGE_STRING, RVALS(version_strings),
TRILL_VERSION_MASK, "The TRILL version number.", HFILL }},
{ &hf_trill_reserved,
{ "Reserved", "trill.reserved",
FT_UINT16, BASE_DEC_HEX|BASE_RANGE_STRING, RVALS(reserved_strings),
TRILL_RESERVED_MASK, "Bits reserved for future specification.", HFILL }},
{ &hf_trill_multi_dst,
{ "Multi Destination", "trill.multi_dst",
FT_BOOLEAN, 16, TFS(&multi_dst_strings), TRILL_MULTI_DST_MASK,
"A boolean specifying if this is a multi-destination frame.", HFILL }},
{ &hf_trill_op_len,
{ "Option Length", "trill.op_len",
FT_UINT16, BASE_DEC_HEX, NULL, TRILL_OP_LEN_MASK,
"The length of the options field of this frame.", HFILL }},
{ &hf_trill_hop_cnt,
{ "Hop Count", "trill.hop_cnt",
FT_UINT16, BASE_DEC_HEX, NULL, TRILL_HOP_CNT_MASK,
"The remaining hop count for this frame.", HFILL }},
{ &hf_trill_egress_nick,
{ "Egress/Root RBridge Nickname", "trill.egress_nick",
FT_UINT16, BASE_DEC_HEX|BASE_RANGE_STRING, RVALS(nickname_strings), 0x0,
"The Egress or Distribution Tree Root RBridge Nickname.", HFILL }},
{ &hf_trill_ingress_nick,
{ "Ingress RBridge Nickname", "trill.ingress_nick",
FT_UINT16, BASE_DEC_HEX|BASE_RANGE_STRING, RVALS(nickname_strings), 0x0,
"The Ingress RBridge Nickname.", HFILL }},
{ &hf_trill_options,
{ "Options", "trill.options",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The TRILL Options field.", HFILL }}
};
static gint *ett[] = {
&ett_trill
};
proto_trill = proto_register_protocol("TRILL", "TRILL", "trill");
proto_register_field_array(proto_trill, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_trill(void)
{
dissector_handle_t trill_handle;
trill_handle = create_dissector_handle(dissect_trill, proto_trill);
dissector_add_uint("ethertype", ETHERTYPE_TRILL, trill_handle);
eth_dissector = find_dissector_add_dependency( "eth_withoutfcs", proto_trill );
}
