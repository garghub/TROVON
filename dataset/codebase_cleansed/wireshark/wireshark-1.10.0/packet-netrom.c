static void
dissect_netrom_type(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree,
int hf_netrom_type_param, gint ett_netrom_type_param, const netrom_tf_items *type_items )
{
proto_tree *tc;
proto_tree *type_tree;
char *info_buffer;
guint8 type;
guint8 op_code;
type = tvb_get_guint8( tvb, offset );
op_code = type &0x0f;
info_buffer = ep_strdup_printf( "%s%s%s%s (0x%02x)",
val_to_str_const( op_code, op_code_vals_text, "Unknown" ),
( type & NETROM_MORE_FLAG ) ? ", More" : "",
( type & NETROM_NAK_FLAG ) ? ", NAK" : "",
( type & NETROM_CHOKE_FLAG ) ? ", Choke" : "",
type );
col_add_str( pinfo->cinfo, COL_INFO, info_buffer );
if ( tree )
{
tc = proto_tree_add_uint_format( tree,
hf_netrom_type_param,
tvb,
offset,
1,
type,
"Type field: %s",
info_buffer
);
type_tree = proto_item_add_subtree( tc, ett_netrom_type_param );
proto_tree_add_item( type_tree, *type_items->hf_tf_op, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( type_tree, *type_items->hf_tf_choke, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( type_tree, *type_items->hf_tf_nak, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( type_tree, *type_items->hf_tf_more, tvb, offset, 1, ENC_BIG_ENDIAN );
}
}
static void
dissect_netrom_proto(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *netrom_tree;
int offset;
const guint8 *src_addr;
const guint8 *dst_addr;
const guint8 *user_addr;
const guint8 *node_addr;
#if 0
guint8 src_ssid;
guint8 dst_ssid;
#endif
guint8 op_code;
guint8 cct_index;
guint8 cct_id;
void *saved_private_data;
tvbuff_t *next_tvb = NULL;
col_set_str( pinfo->cinfo, COL_PROTOCOL, "NET/ROM" );
col_clear( pinfo->cinfo, COL_INFO );
offset = 0;
src_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
SET_ADDRESS(&pinfo->dl_src, AT_AX25, AX25_ADDR_LEN, src_addr);
SET_ADDRESS(&pinfo->src, AT_AX25, AX25_ADDR_LEN, src_addr);
offset += AX25_ADDR_LEN;
dst_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
SET_ADDRESS(&pinfo->dl_dst, AT_AX25, AX25_ADDR_LEN, dst_addr);
SET_ADDRESS(&pinfo->dst, AT_AX25, AX25_ADDR_LEN, dst_addr);
offset += AX25_ADDR_LEN;
offset += 1;
cct_index = tvb_get_guint8( tvb, offset );
offset += 1;
cct_id = tvb_get_guint8( tvb, offset );
offset += 1;
offset += 1;
offset += 1;
op_code = tvb_get_guint8( tvb, offset ) & 0x0f;
offset += 1;
col_add_fstr( pinfo->cinfo, COL_INFO, "%s", val_to_str_const( op_code, op_code_vals_text, "Unknown" ));
if ( tree )
{
ti = proto_tree_add_protocol_format( tree, proto_netrom, tvb, 0, NETROM_HEADER_SIZE,
"NET/ROM, Src: %s (%s), Dst: %s (%s)",
get_ax25_name( src_addr ),
ax25_to_str( src_addr ),
get_ax25_name( dst_addr ),
ax25_to_str( dst_addr ) );
netrom_tree = proto_item_add_subtree( ti, ett_netrom );
offset = 0;
proto_tree_add_ax25( netrom_tree, hf_netrom_src, tvb, offset, AX25_ADDR_LEN, src_addr );
offset += AX25_ADDR_LEN;
proto_tree_add_ax25( netrom_tree, hf_netrom_dst, tvb, offset, AX25_ADDR_LEN, dst_addr );
offset += AX25_ADDR_LEN;
proto_tree_add_item( netrom_tree, hf_netrom_ttl, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
switch ( op_code )
{
case NETROM_PROTOEXT :
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
offset += 1;
break;
case NETROM_CONNREQ :
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
offset += 1;
break;
case NETROM_CONNACK :
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_my_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
break;
case NETROM_DISCREQ :
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
offset += 1;
break;
case NETROM_DISCACK :
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
offset += 1;
break;
case NETROM_INFO :
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_n_s, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_n_r, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
break;
case NETROM_INFOACK :
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_index, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_your_cct_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
offset += 1;
proto_tree_add_item( netrom_tree, hf_netrom_n_r, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
break;
default :
offset += 1;
offset += 1;
offset += 1;
offset += 1;
break;
}
dissect_netrom_type( tvb,
offset,
pinfo,
netrom_tree,
hf_netrom_type,
ett_netrom_type,
&netrom_type_items
);
offset += 1;
switch ( op_code )
{
case NETROM_PROTOEXT :
break;
case NETROM_CONNREQ :
proto_tree_add_item( netrom_tree, hf_netrom_pwindow, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
user_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
proto_tree_add_ax25( netrom_tree, hf_netrom_user, tvb, offset, AX25_ADDR_LEN, user_addr );
offset += AX25_ADDR_LEN;
node_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
proto_tree_add_ax25( netrom_tree, hf_netrom_node, tvb, offset, AX25_ADDR_LEN, node_addr );
offset += AX25_ADDR_LEN;
break;
case NETROM_CONNACK :
proto_tree_add_item( netrom_tree, hf_netrom_awindow, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
break;
case NETROM_DISCREQ :
break;
case NETROM_DISCACK :
break;
case NETROM_INFO :
break;
case NETROM_INFOACK :
break;
default :
break;
}
}
saved_private_data = pinfo->private_data;
next_tvb = tvb_new_subset_remaining(tvb, offset);
switch ( op_code )
{
case NETROM_PROTOEXT :
if ( cct_index == NETROM_PROTO_IP && cct_id == NETROM_PROTO_IP )
call_dissector( ip_handle , next_tvb, pinfo, tree );
else
call_dissector( default_handle , next_tvb, pinfo, tree );
break;
case NETROM_INFO :
default :
call_dissector( default_handle , next_tvb, pinfo, tree );
break;
}
pinfo->private_data = saved_private_data;
}
static void
dissect_netrom_routing(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
void *saved_private_data;
tvbuff_t *next_tvb;
col_set_str( pinfo->cinfo, COL_PROTOCOL, "NET/ROM");
col_set_str( pinfo->cinfo, COL_INFO, "routing table frame");
if (tree)
{
proto_item *ti;
proto_tree *netrom_tree;
ti = proto_tree_add_protocol_format( tree, proto_netrom, tvb, 0, -1,
"NET/ROM, routing table frame, Node: %.6s",
tvb_get_ptr( tvb, 1, 6 )
);
netrom_tree = proto_item_add_subtree( ti, ett_netrom );
proto_tree_add_item( netrom_tree, hf_netrom_mnemonic, tvb, 1, 6, ENC_ASCII|ENC_NA );
}
saved_private_data = pinfo->private_data;
next_tvb = tvb_new_subset_remaining(tvb, 7);
call_dissector( default_handle , next_tvb, pinfo, tree );
pinfo->private_data = saved_private_data;
}
static void
dissect_netrom(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if ( tvb_get_guint8( tvb, 0 ) == 0xff )
dissect_netrom_routing( tvb, pinfo, tree );
else
dissect_netrom_proto( tvb, pinfo, tree );
}
void
capture_netrom( const guchar *pd _U_, int offset, int len, packet_counts *ld)
{
if ( ! BYTES_ARE_IN_FRAME( offset, len, NETROM_MIN_SIZE ) )
{
ld->other++;
return;
}
ld->other++;
}
void
proto_register_netrom(void)
{
static const true_false_string flags_set_truth =
{
"Set",
"Not set"
};
static hf_register_info hf[] = {
{ &hf_netrom_src,
{ "Source", "netrom.src",
FT_AX25, BASE_NONE, NULL, 0x0,
"Source callsign", HFILL }
},
{ &hf_netrom_dst,
{ "Destination", "netrom.dst",
FT_AX25, BASE_NONE, NULL, 0x0,
"Destination callsign", HFILL }
},
{ &hf_netrom_ttl,
{ "TTL", "netrom.ttl",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_my_cct_index,
{ "My circuit index", "netrom.my.cct.index",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_my_cct_id,
{ "My circuit ID", "netrom.my.cct.id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_your_cct_index,
{ "Your circuit index", "netrom.your.cct.index",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_your_cct_id,
{ "Your circuit ID", "netrom.your.cct.id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_n_r,
{ "N(r)", "netrom.n_r",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_n_s,
{ "N(s)", "netrom.n_s",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_netrom_type,
{ "Type", "netrom.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Packet type field", HFILL }
},
{ &hf_netrom_op,
{ "OP code", "netrom.op",
FT_UINT8, BASE_HEX, VALS( op_code_vals_abbrev ), 0x0f,
"Protocol operation code", HFILL }
},
{ &hf_netrom_more,
{ "More", "netrom.flag.more",
FT_BOOLEAN, 8, TFS(&flags_set_truth), NETROM_MORE_FLAG,
"More flag", HFILL }
},
{ &hf_netrom_nak,
{ "NAK", "netrom.flag.nak",
FT_BOOLEAN, 8, TFS(&flags_set_truth), NETROM_NAK_FLAG,
"NAK flag", HFILL }
},
{ &hf_netrom_choke,
{ "Choke", "netrom.flag.choke",
FT_BOOLEAN, 8, TFS(&flags_set_truth), NETROM_CHOKE_FLAG,
"Choke flag", HFILL }
},
{ &hf_netrom_user,
{ "User", "netrom.user",
FT_AX25, BASE_NONE, NULL, 0x0,
"User callsign", HFILL }
},
{ &hf_netrom_node,
{ "Node", "netrom.node",
FT_AX25, BASE_NONE, NULL, 0x0,
"Node callsign", HFILL }
},
{ &hf_netrom_pwindow,
{ "Window", "netrom.pwindow",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Proposed window", HFILL }
},
{ &hf_netrom_awindow,
{ "Window", "netrom.awindow",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Accepted window", HFILL }
},
{ &hf_netrom_mnemonic,
{ "Node name", "netrom.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_netrom,
&ett_netrom_type,
};
proto_netrom = proto_register_protocol( "Amateur Radio NET/ROM", "NET/ROM", "netrom" );
proto_register_field_array( proto_netrom, hf, array_length(hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_netrom(void)
{
dissector_add_uint( "ax25.pid", AX25_P_NETROM, create_dissector_handle( dissect_netrom, proto_netrom ) );
ip_handle = find_dissector( "ip" );
default_handle = find_dissector( "data" );
}
