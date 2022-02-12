static void
dissect_h261( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti = NULL;
proto_tree *h261_tree = NULL;
unsigned int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.261");
col_set_str(pinfo->cinfo, COL_INFO, "H.261 message");
if ( tree ) {
ti = proto_tree_add_item( tree, proto_h261, tvb, offset, -1, ENC_NA );
h261_tree = proto_item_add_subtree( ti, ett_h261 );
proto_tree_add_uint( h261_tree, hf_h261_sbit, tvb, offset, 1, tvb_get_guint8( tvb, offset ) >> 5 );
proto_tree_add_uint( h261_tree, hf_h261_ebit, tvb, offset, 1, ( tvb_get_guint8( tvb, offset ) >> 2 ) & 7 );
proto_tree_add_boolean( h261_tree, hf_h261_ibit, tvb, offset, 1, tvb_get_guint8( tvb, offset ) & 2 );
proto_tree_add_boolean( h261_tree, hf_h261_vbit, tvb, offset, 1, tvb_get_guint8( tvb, offset ) & 1 );
offset++;
proto_tree_add_uint( h261_tree, hf_h261_gobn, tvb, offset, 1, tvb_get_guint8( tvb, offset ) >> 4 );
proto_tree_add_uint( h261_tree, hf_h261_mbap, tvb, offset, 1,
( tvb_get_guint8( tvb, offset ) & 15 )
+ ( tvb_get_guint8( tvb, offset + 1 ) >> 7 ) );
offset++;
proto_tree_add_uint( h261_tree, hf_h261_quant, tvb, offset, 1, tvb_get_guint8( tvb, offset ) & 124 );
proto_tree_add_uint( h261_tree, hf_h261_hmvd, tvb, offset, 2,
( ( tvb_get_guint8( tvb, offset ) & 0x03 ) << 3 )
+ ( tvb_get_guint8( tvb, offset+1 ) >> 5 ) );
offset++;
proto_tree_add_uint( h261_tree, hf_h261_vmvd, tvb, offset, 1, tvb_get_guint8( tvb, offset ) & 31 );
offset++;
proto_tree_add_item( h261_tree, hf_h261_data, tvb, offset, -1, ENC_NA );
}
}
void
proto_register_h261(void)
{
static hf_register_info hf[] =
{
{
&hf_h261_sbit,
{
"Start bit position",
"h261.sbit",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_ebit,
{
"End bit position",
"h261.ebit",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_ibit,
{
"Intra frame encoded data flag",
"h261.i",
FT_BOOLEAN,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_vbit,
{
"Motion vector flag",
"h261.v",
FT_BOOLEAN,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_gobn,
{
"GOB Number",
"h261.gobn",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_mbap,
{
"Macroblock address predictor",
"h261.mbap",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_quant,
{
"Quantizer",
"h261.quant",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_hmvd,
{
"Horizontal motion vector data",
"h261.hmvd",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_vmvd,
{
"Vertical motion vector data",
"h261.vmvd",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_h261_data,
{
"H.261 stream",
"h261.stream",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_h261,
};
proto_h261 = proto_register_protocol("ITU-T Recommendation H.261",
"H.261", "h261");
proto_register_field_array(proto_h261, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_h261(void)
{
dissector_handle_t h261_handle;
h261_handle = create_dissector_handle(dissect_h261, proto_h261);
dissector_add_uint("rtp.pt", PT_H261, h261_handle);
dissector_add_uint("iax2.codec", AST_FORMAT_H261, h261_handle);
}
