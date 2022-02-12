static void
dissect_flexnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
void *saved_private_data;
tvbuff_t *next_tvb;
col_set_str( pinfo->cinfo, COL_PROTOCOL, "Flexnet");
col_clear( pinfo->cinfo, COL_INFO );
if ( parent_tree )
{
proto_item *ti;
proto_tree *flexnet_tree;
int offset;
ti = proto_tree_add_protocol_format( parent_tree, proto_flexnet, tvb, 0, FLEXNET_HDRLEN, "FLEXNET" );
flexnet_tree = proto_item_add_subtree( ti, ett_flexnet );
offset = 0;
proto_tree_add_item( flexnet_tree, hf_flexnet_dst, tvb, offset, FLEXNET_ADRLEN, ENC_NA );
offset +=FLEXNET_ADRLEN;
proto_tree_add_item( flexnet_tree, hf_flexnet_src, tvb, offset, FLEXNET_ADRLEN, ENC_NA );
offset +=FLEXNET_ADRLEN;
proto_tree_add_item( flexnet_tree, hf_flexnet_ctl, tvb, offset, FLEXNET_CTLLEN, ENC_NA );
}
saved_private_data = pinfo->private_data;
next_tvb = tvb_new_subset_remaining(tvb, FLEXNET_HDRLEN);
call_dissector( default_handle , next_tvb, pinfo, parent_tree );
pinfo->private_data = saved_private_data;
}
void
proto_register_flexnet(void)
{
static hf_register_info hf[] = {
{ &hf_flexnet_dst,
{ "Destination", "flexnet.dst",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Destination address", HFILL }
},
{ &hf_flexnet_src,
{ "Source", "flexnet.src",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Source address", HFILL }
},
{ &hf_flexnet_ctl,
{ "Control", "flexnet.ctl",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_flexnet,
&ett_flexnet_ctl,
};
proto_flexnet = proto_register_protocol("FlexNet", "FLEXNET", "flexnet");
proto_register_field_array( proto_flexnet, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_flexnet(void)
{
dissector_add_uint( "ax25.pid", AX25_P_FLEXNET, create_dissector_handle( dissect_flexnet, proto_flexnet ) );
default_handle = find_dissector( "data" );
}
