static int
dissect_h261( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ )
{
proto_item *ti = NULL;
proto_tree *h261_tree = NULL;
unsigned int offset = 0;
static const int * bits[] = {
&hf_h261_sbit,
&hf_h261_ebit,
&hf_h261_ibit,
&hf_h261_vbit,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.261");
col_set_str(pinfo->cinfo, COL_INFO, "H.261 message");
if ( tree ) {
ti = proto_tree_add_item( tree, proto_h261, tvb, offset, -1, ENC_NA );
h261_tree = proto_item_add_subtree( ti, ett_h261 );
proto_tree_add_bitmask_list(h261_tree, tvb, offset, 1, bits, ENC_NA);
offset++;
proto_tree_add_item( h261_tree, hf_h261_gobn, tvb, offset, 1, ENC_NA);
proto_tree_add_item( h261_tree, hf_h261_mbap, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( h261_tree, hf_h261_quant, tvb, offset, 1, ENC_NA );
proto_tree_add_item( h261_tree, hf_h261_hmvd, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( h261_tree, hf_h261_vmvd, tvb, offset, 1, 0x1F );
offset++;
proto_tree_add_item( h261_tree, hf_h261_data, tvb, offset, -1, ENC_NA );
}
return tvb_captured_length(tvb);
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
0xe0,
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
0x1c,
NULL, HFILL
}
},
{
&hf_h261_ibit,
{
"Intra frame encoded data flag",
"h261.i",
FT_BOOLEAN,
8,
NULL,
0x02,
NULL, HFILL
}
},
{
&hf_h261_vbit,
{
"Motion vector flag",
"h261.v",
FT_BOOLEAN,
8,
NULL,
0x01,
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
0xF0,
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
0x0E80,
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
0x7C,
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
0x03E0,
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
