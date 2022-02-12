static int
dissect_rfc2190( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ )
{
proto_item *ti = NULL;
proto_tree *rfc2190_tree = NULL;
int offset = 0;
unsigned int rfc2190_version = 0;
tvbuff_t *next_tvb;
int hdr_len = 0;
rfc2190_version = (tvb_get_guint8( tvb, offset ) & 0xc0 ) >> 6;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.263 ");
if( rfc2190_version == 0x00) {
col_append_str( pinfo->cinfo, COL_INFO, "MODE A ");
hdr_len = 4;
}
else if( rfc2190_version == 0x02) {
col_append_str( pinfo->cinfo, COL_INFO, "MODE B ");
hdr_len = 8;
}
else if( rfc2190_version == 0x03) {
col_append_str( pinfo->cinfo, COL_INFO, "MODE C ");
hdr_len = 12;
}
if ( tree ) {
ti = proto_tree_add_item( tree, proto_rfc2190, tvb, offset, hdr_len, ENC_NA );
rfc2190_tree = proto_item_add_subtree( ti, ett_rfc2190 );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_ftype, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_pbframes, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_sbit, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_ebit, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_srcformat, tvb, offset, 1, ENC_BIG_ENDIAN );
if(rfc2190_version == 0x00) {
proto_tree_add_item(rfc2190_tree, hf_rfc2190_picture_coding_type_modeA, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rfc2190_tree, hf_rfc2190_unrestricted_motion_vector_modeA, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rfc2190_tree, hf_rfc2190_syntax_based_arithmetic_modeA, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rfc2190_tree, hf_rfc2190_advanced_prediction_modeA, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_r_modeA, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_dbq, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_trb, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_tr, tvb, offset, 1, ENC_NA );
offset++;
} else {
proto_tree_add_item( rfc2190_tree, hf_rfc2190_quant, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_gobn, tvb, offset, 1, ENC_NA);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_mba, tvb, offset, 2, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_r_modeB, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_picture_coding_type_modeB, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_unrestricted_motion_vector_modeB, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_syntax_based_arithmetic_modeB, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_advanced_prediction_modeB, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( rfc2190_tree, hf_rfc2190_hmv1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_vmv1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_hmv2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_vmv2, tvb, offset, 1, ENC_NA);
offset++;
if(rfc2190_version == 0x03) {
proto_tree_add_item( rfc2190_tree, hf_rfc2190_rr, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_dbq, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rfc2190_tree, hf_rfc2190_trb, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( rfc2190_tree, hf_rfc2190_tr, tvb, offset, 1, ENC_NA );
offset++;
}
}
} else {
switch(rfc2190_version) {
case 0x00:
offset += 4;
break;
case 0x01:
offset += 8;
break;
case 0x02:
offset += 12;
break;
}
}
next_tvb = tvb_new_subset_remaining( tvb, offset);
call_dissector(h263_handle,next_tvb,pinfo,tree);
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_rfc2190(void)
{
dissector_add_uint("rtp.pt", PT_H263, rfc2190_handle);
dissector_add_uint("iax2.codec", AST_FORMAT_H263, rfc2190_handle);
h263_handle = find_dissector_add_dependency("h263data", proto_rfc2190);
}
void
proto_register_rfc2190(void)
{
static hf_register_info hf[] = {
{
&hf_rfc2190_ftype,
{
"F",
"rfc2190.ftype",
FT_BOOLEAN,
8,
NULL,
0x80,
"Indicates the mode of the payload header (MODE A or B/C)", HFILL
}
},
{
&hf_rfc2190_pbframes,
{
"p/b frame",
"rfc2190.pbframes",
FT_BOOLEAN,
8,
NULL,
0x40,
"Optional PB-frames mode as defined by H.263 (MODE C)", HFILL
}
},
{
&hf_rfc2190_sbit,
{
"Start bit position",
"rfc2190.sbit",
FT_UINT8,
BASE_DEC,
NULL,
0x38,
"Start bit position specifies number of most significant bits that shall be ignored in the first data byte.", HFILL
}
},
{
&hf_rfc2190_ebit,
{
"End bit position",
"rfc2190.ebit",
FT_UINT8,
BASE_DEC,
NULL,
0x7,
"End bit position specifies number of least significant bits that shall be ignored in the last data byte.", HFILL
}
},
{
&hf_rfc2190_srcformat,
{
"SRC format",
"rfc2190.srcformat",
FT_UINT8,
BASE_DEC,
VALS(h263_srcformat_vals),
0xe0,
"Source format specifies the resolution of the current picture.", HFILL
}
},
{
&hf_rfc2190_picture_coding_type_modeA,
{
"Inter-coded frame",
"rfc2190.picture_coding_type",
FT_BOOLEAN,
8,
NULL,
0x08,
"Picture coding type, intra-coded (false) or inter-coded (true)", HFILL
}
},
{
&hf_rfc2190_unrestricted_motion_vector_modeA,
{
"Motion vector",
"rfc2190.unrestricted_motion_vector",
FT_BOOLEAN,
8,
NULL,
0x10,
"Unrestricted Motion Vector option for current picture", HFILL
}
},
{
&hf_rfc2190_syntax_based_arithmetic_modeA,
{
"Syntax-based arithmetic coding",
"rfc2190.syntax_based_arithmetic",
FT_BOOLEAN,
8,
NULL,
0x20,
"Syntax-based Arithmetic Coding option for current picture", HFILL
}
},
{
&hf_rfc2190_advanced_prediction_modeA,
{
"Advanced prediction option",
"rfc2190.advanced_prediction",
FT_BOOLEAN,
8,
NULL,
0x40,
"Advanced Prediction option for current picture", HFILL
}
},
{
&hf_rfc2190_picture_coding_type_modeB,
{
"Inter-coded frame",
"rfc2190.picture_coding_type",
FT_BOOLEAN,
8,
NULL,
0x80,
"Picture coding type, intra-coded (false) or inter-coded (true)", HFILL
}
},
{
&hf_rfc2190_unrestricted_motion_vector_modeB,
{
"Motion vector",
"rfc2190.unrestricted_motion_vector",
FT_BOOLEAN,
8,
NULL,
0x40,
"Unrestricted Motion Vector option for current picture", HFILL
}
},
{
&hf_rfc2190_syntax_based_arithmetic_modeB,
{
"Syntax-based arithmetic coding",
"rfc2190.syntax_based_arithmetic",
FT_BOOLEAN,
8,
NULL,
0x20,
"Syntax-based Arithmetic Coding option for current picture", HFILL
}
},
{
&hf_rfc2190_advanced_prediction_modeB,
{
"Advanced prediction option",
"rfc2190.advanced_prediction",
FT_BOOLEAN,
8,
NULL,
0x10,
"Advanced Prediction option for current picture", HFILL
}
},
{
&hf_rfc2190_dbq,
{
"Differential quantization parameter",
"rfc2190.dbq",
FT_UINT8,
BASE_DEC,
NULL,
0x18,
"Differential quantization parameter used to calculate quantizer for the B frame based on quantizer for the P frame, when PB-frames option is used.", HFILL
}
},
{
&hf_rfc2190_trb,
{
"Temporal Reference for B frames",
"rfc2190.trb",
FT_UINT8,
BASE_DEC,
NULL,
0x07,
"Temporal Reference for the B frame as defined by H.263", HFILL
}
},
{
&hf_rfc2190_tr,
{
"Temporal Reference for P frames",
"rfc2190.tr",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Temporal Reference for the P frame as defined by H.263", HFILL
}
},
{
&hf_rfc2190_quant,
{
"Quantizer",
"rfc2190.quant",
FT_UINT8,
BASE_DEC,
NULL,
0x1F,
"Quantization value for the first MB coded at the starting of the packet.", HFILL
}
},
{
&hf_rfc2190_gobn,
{
"GOB Number",
"rfc2190.gobn",
FT_UINT8,
BASE_DEC,
NULL,
0xF8,
"GOB number in effect at the start of the packet.", HFILL
}
},
{
&hf_rfc2190_mba,
{
"Macroblock address",
"rfc2190.mba",
FT_UINT16,
BASE_DEC,
NULL,
0x3FE0,
"The address within the GOB of the first MB in the packet, counting from zero in scan order.", HFILL
}
},
{
&hf_rfc2190_hmv1,
{
"Horizontal motion vector 1",
"rfc2190.hmv1",
FT_UINT16,
BASE_DEC,
NULL,
0x07F0,
"Horizontal motion vector predictor for the first MB in this packet", HFILL
}
},
{
&hf_rfc2190_vmv1,
{
"Vertical motion vector 1",
"rfc2190.vmv1",
FT_UINT8,
BASE_DEC,
NULL,
0x03F8,
"Vertical motion vector predictor for the first MB in this packet", HFILL
}
},
{
&hf_rfc2190_hmv2,
{
"Horizontal motion vector 2",
"rfc2190.hmv2",
FT_UINT8,
BASE_DEC,
NULL,
0x01FC,
"Horizontal motion vector predictor for block number 3 in the first MB in this packet when four motion vectors are used with the advanced prediction option.", HFILL
}
},
{
&hf_rfc2190_vmv2,
{
"Vertical motion vector 2",
"rfc2190.vmv2",
FT_UINT8,
BASE_DEC,
NULL,
0x7F,
"Vertical motion vector predictor for block number 3 in the first MB in this packet when four motion vectors are used with the advanced prediction option.", HFILL
}
},
{
&hf_rfc2190_r_modeA,
{
"Reserved field",
"rfc2190.r",
FT_UINT16,
BASE_DEC,
NULL,
0x0380,
"Reserved field that should contain zeroes", HFILL
}
},
{
&hf_rfc2190_r_modeB,
{
"Reserved field",
"rfc2190.r",
FT_UINT8,
BASE_DEC,
NULL,
0x03,
"Reserved field that should contain zeroes", HFILL
}
},
{
&hf_rfc2190_rr,
{
"Reserved field 2",
"rfc2190.rr",
FT_UINT24,
BASE_DEC,
NULL,
0x07FFFF,
"Reserved field that should contain zeroes", HFILL
}
},
};
static gint *ett[] = {
&ett_rfc2190,
};
proto_register_subtree_array(ett, array_length(ett));
proto_rfc2190 = proto_register_protocol("H.263 RTP Payload header (RFC2190)",
"RFC2190", "rfc2190");
proto_register_field_array(proto_rfc2190, hf, array_length(hf));
rfc2190_handle = register_dissector("rfc2190", dissect_rfc2190, proto_rfc2190);
}
