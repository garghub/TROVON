int
dissect_h263_group_of_blocks_layer( tvbuff_t *tvb, proto_tree *tree, gint offset, gboolean is_rfc4626)
{
unsigned int offset_in_bits = offset << 3;
if(is_rfc4626){
proto_tree_add_bits_item(tree, hf_h263_gbsc, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
}else{
proto_tree_add_bits_item(tree, hf_h263_gbsc, tvb, offset_in_bits, 17, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +17;
}
proto_tree_add_bits_item(tree, hf_h263_GN, tvb, offset_in_bits, 5, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +5;
return offset_in_bits>>3;
}
int
dissect_h263_picture_layer( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint length _U_, gboolean is_rfc4626)
{
proto_tree *h263_opptype_tree = NULL;
proto_item *opptype_item = NULL;
unsigned int offset_in_bits = offset << 3;
unsigned int saved_bit_offset;
guint64 source_format;
guint64 ufep;
guint64 picture_coding_type;
guint64 PB_frames_mode = 0;
guint64 custom_pcf = 0;
guint64 picture_type_code =0;
guint64 cpm;
guint64 pei;
if(is_rfc4626){
proto_tree_add_bits_item(tree, hf_h263_psc, tvb, offset_in_bits, 6, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +6;
}else{
proto_tree_add_bits_item(tree, hf_h263_psc, tvb, offset_in_bits, 22, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +22;
}
proto_tree_add_bits_item(tree, hf_h263_TR, tvb, offset_in_bits, 8, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +8;
offset_in_bits = offset_in_bits +2;
proto_tree_add_bits_item( tree, hf_h263_split_screen_indicator, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_document_camera_indicator, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_full_picture_freeze_release, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_ret_val( tree, hf_h263_source_format, tvb, offset_in_bits, 3 ,&source_format, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +3;
if (source_format != H263_PLUSPTYPE){
proto_tree_add_bits_ret_val( tree, hf_h263_payload_picture_coding_type, tvb, offset_in_bits, 1, &picture_coding_type, ENC_BIG_ENDIAN);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str((guint32)picture_coding_type, picture_coding_type_vals, "Unknown (%u)"));
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_opt_unres_motion_vector_mode, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_syntax_based_arithmetic_coding_mode, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_optional_advanced_prediction_mode, tvb, offset_in_bits, 1, ENC_BIG_ENDIAN);
offset_in_bits++;
proto_tree_add_bits_ret_val( tree, hf_h263_PB_frames_mode, tvb, offset_in_bits, 1, &PB_frames_mode, ENC_BIG_ENDIAN);
offset_in_bits++;
}else{
proto_tree_add_bits_ret_val( tree, hf_h263_UFEP, tvb, offset_in_bits, 3, &ufep, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +3;
if(ufep==1){
opptype_item = proto_tree_add_bits_item( tree, hf_h263_opptype, tvb, offset_in_bits, 18, ENC_BIG_ENDIAN);
h263_opptype_tree = proto_item_add_subtree( opptype_item, ett_h263_optype );
proto_tree_add_bits_item( h263_opptype_tree, hf_h263_ext_source_format, tvb, offset_in_bits, 3, ENC_BIG_ENDIAN);
offset_in_bits+=3;
proto_tree_add_bits_ret_val( h263_opptype_tree, hf_h263_custom_pcf, tvb, offset_in_bits, 1, &custom_pcf, ENC_BIG_ENDIAN);
offset_in_bits++;
saved_bit_offset=offset_in_bits;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
proto_tree_add_bits_item( h263_opptype_tree, hf_h263_not_dissected, tvb, saved_bit_offset, offset_in_bits-saved_bit_offset, ENC_BIG_ENDIAN);
}
proto_tree_add_bits_ret_val( tree, hf_h263_picture_type_code, tvb, offset_in_bits, 3, &picture_type_code, ENC_BIG_ENDIAN);
offset_in_bits+=3;
saved_bit_offset=offset_in_bits;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
offset_in_bits++;
proto_tree_add_bits_item( tree, hf_h263_not_dissected, tvb, saved_bit_offset, offset_in_bits-saved_bit_offset, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val( tree, hf_h263_cpm, tvb, offset_in_bits, 1, &cpm, ENC_BIG_ENDIAN);
offset_in_bits++;
if(cpm==1){
proto_tree_add_bits_item( tree, hf_h263_psbi, tvb, offset_in_bits, 2, ENC_BIG_ENDIAN);
offset_in_bits+=2;
}
return offset_in_bits>>3;
}
proto_tree_add_bits_item( tree, hf_h263_pquant, tvb, offset_in_bits, 5, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +5;
if (source_format != H263_PLUSPTYPE){
proto_tree_add_bits_ret_val( tree, hf_h263_cpm, tvb, offset_in_bits, 1, &cpm, ENC_BIG_ENDIAN);
offset_in_bits++;
if(cpm==1){
proto_tree_add_bits_item( tree, hf_h263_psbi, tvb, offset_in_bits, 2, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +2;
}
}
if((PB_frames_mode == 1)||(picture_type_code == 2 )){
if(custom_pcf == 0){
proto_tree_add_bits_item( tree, hf_h263_trb, tvb, offset_in_bits, 3, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +3;
}else{
proto_tree_add_bits_item( tree, hf_h263_trb, tvb, offset_in_bits, 5, ENC_BIG_ENDIAN);
offset_in_bits = offset_in_bits +5;
}
}
if((PB_frames_mode == 1)||(picture_type_code == 2 )){
offset_in_bits = offset_in_bits +2;
}
proto_tree_add_bits_ret_val( tree, hf_h263_pei, tvb, offset_in_bits, 1, &pei, ENC_BIG_ENDIAN);
offset_in_bits++;
while(pei==1)
{
proto_tree_add_bits_item( tree, hf_h263_psupp, tvb, offset_in_bits, 8, ENC_BIG_ENDIAN);
offset_in_bits+=8;
proto_tree_add_bits_ret_val( tree, hf_h263_pei, tvb, offset_in_bits, 1, &pei, ENC_BIG_ENDIAN);
offset_in_bits++;
}
return offset_in_bits>>3;
}
static void dissect_h263_data( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
guint offset = 0;
proto_item *h263_payload_item = NULL;
proto_tree *h263_payload_tree = NULL;
guint32 data;
guint8 startcode;
int length;
col_append_str( pinfo->cinfo, COL_INFO, "H263 payload ");
h263_payload_item = proto_tree_add_item( tree, proto_h263_data, tvb, offset, -1, ENC_NA );
h263_payload_tree = proto_item_add_subtree( h263_payload_item, ett_h263_payload );
length = tvb_reported_length_remaining(tvb,0);
if(length<4){
if( tree )
proto_tree_add_item( h263_payload_tree, hf_h263_data, tvb, offset, -1, ENC_NA );
return;
}
data = tvb_get_ntohl(tvb, offset);
if (( data & 0xffff8000) == 0x00008000 ) {
startcode = tvb_get_guint8(tvb,offset+2)&0xfe;
if (startcode & 0x80){
switch(startcode){
case 0xf8:
break;
case 0x80:
case 0x82:
col_append_str( pinfo->cinfo, COL_INFO, "(PSC) ");
offset = dissect_h263_picture_layer( tvb, pinfo, h263_payload_tree, offset, -1, ENC_NA);
break;
case 0xfc:
case 0xfe:
default:
col_append_str( pinfo->cinfo, COL_INFO, "(GBSC) ");
offset = dissect_h263_group_of_blocks_layer( tvb, h263_payload_tree, offset,FALSE);
break;
}
}else{
}
}
if( tree )
proto_tree_add_item( h263_payload_tree, hf_h263_data, tvb, offset, -1, ENC_NA );
}
void
proto_register_h263_data(void)
{
static hf_register_info hf[] =
{
{
&hf_h263_psc,
{
"H.263 Picture start Code",
"h263.psc",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
"Picture start Code, PSC", HFILL
}
},
{ &hf_h263_gbsc,
{
"H.263 Group of Block Start Code",
"h263.gbsc",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
"Group of Block Start Code", HFILL
}
},
{
&hf_h263_TR,
{
"H.263 Temporal Reference",
"h263.tr2",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Temporal Reference, TR", HFILL
}
},
{
&hf_h263_trb,
{
"Temporal Reference for B frames",
"h263.trb",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Temporal Reference for the B frame as defined by H.263", HFILL
}
},
{
&hf_h263_split_screen_indicator,
{
"H.263 Split screen indicator",
"h263.split_screen_indicator",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Split screen indicator", HFILL
}
},
{
&hf_h263_document_camera_indicator,
{
"H.263 Document camera indicator",
"h263.document_camera_indicator",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Document camera indicator", HFILL
}
},
{
&hf_h263_full_picture_freeze_release,
{
"H.263 Full Picture Freeze Release",
"h263.split_screen_indicator",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Full Picture Freeze Release", HFILL
}
},
{
&hf_h263_source_format,
{
"H.263 Source Format",
"h263.source_format",
FT_UINT8,
BASE_HEX,
VALS(h263_srcformat_vals),
0x0,
"Source Format", HFILL
}
},
{
&hf_h263_ext_source_format,
{
"H.263 Source Format",
"h263.ext_source_format",
FT_UINT8,
BASE_HEX,
VALS(ext_srcformat_vals),
0x0,
"Source Format", HFILL
}
},
{
&hf_h263_UFEP,
{
"H.263 Update Full Extended PTYPE",
"h263.ufep",
FT_UINT16,
BASE_DEC,
VALS(h263_ufep_vals),
0x0,
"Update Full Extended PTYPE", HFILL
}
},
{
&hf_h263_opptype,
{
"H.263 Optional Part of PLUSPTYPE",
"h263.opptype",
FT_UINT24,
BASE_DEC,
NULL,
0x0,
"Optional Part of PLUSPTYPE", HFILL
}
},
{
&hf_h263_payload_picture_coding_type,
{
"H.263 Picture Coding Type",
"h263.picture_coding_type",
FT_BOOLEAN,
BASE_NONE,
TFS(&picture_coding_type_flg),
0x0,
"Picture Coding Type", HFILL
}
},
{
&hf_h263_opt_unres_motion_vector_mode,
{
"H.263 Optional Unrestricted Motion Vector mode",
"h263.opt_unres_motion_vector_mode",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Optional Unrestricted Motion Vector mode", HFILL
}
},
{
&hf_h263_syntax_based_arithmetic_coding_mode,
{
"H.263 Optional Syntax-based Arithmetic Coding mode",
"h263.syntax_based_arithmetic_coding_mode",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Optional Syntax-based Arithmetic Coding mode", HFILL
}
},
{
&hf_h263_optional_advanced_prediction_mode,
{
"H.263 Optional Advanced Prediction mode",
"h263.optional_advanced_prediction_mode",
FT_BOOLEAN,
BASE_NONE,
TFS(&on_off_flg),
0x0,
"Optional Advanced Prediction mode", HFILL
}
},
{
&hf_h263_PB_frames_mode,
{
"H.263 Optional PB-frames mode",
"h263.PB_frames_mode",
FT_BOOLEAN,
BASE_NONE,
TFS(&PB_frames_mode_flg),
0x0,
"Optional PB-frames mode", HFILL
}
},
{
&hf_h263_GN,
{
"H.263 Group Number",
"h263.gn",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Group Number, GN", HFILL
}
},
{
&hf_h263_pquant,
{
"H.263 Quantizer Information (PQUANT)",
"h263.pquant",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Quantizer Information (PQUANT)", HFILL
}
},
{
&hf_h263_cpm,
{
"H.263 Continuous Presence Multipoint and Video Multiplex (CPM)",
"h263.cpm",
FT_BOOLEAN,
BASE_NONE,
TFS(&cpm_flg),
0x0,
"Continuous Presence Multipoint and Video Multiplex (CPM)", HFILL
}
},
{
&hf_h263_psbi,
{
"H.263 Picture Sub-Bitstream Indicator (PSBI)",
"h263.psbi",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Picture Sub-Bitstream Indicator (PSBI)", HFILL
}
},
{
&hf_h263_picture_type_code,
{
"H.263 Picture Type Code",
"h263.psi",
FT_UINT32,
BASE_DEC,
VALS(picture_type_code_vals),
0x0,
"Picture Type Code", HFILL
}
},
{
&hf_h263_custom_pcf,
{
"H.263 Custom PCF",
"h263.custom_pcf",
FT_BOOLEAN,
BASE_NONE,
TFS(&custom_pcf_flg),
0x0,
"Custom PCF", HFILL
}
},
{
&hf_h263_pei,
{
"H.263 Extra Insertion Information (PEI)",
"h263.pei",
FT_BOOLEAN,
BASE_NONE,
NULL,
0x0,
"Extra Insertion Information (PEI)", HFILL
}
},
{
&hf_h263_psupp,
{
"H.263 Supplemental Enhancement Information (PSUPP)",
"h263.psupp",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Supplemental Enhancement Information (PSUPP)", HFILL
}
},
{
&hf_h263_data,
{
"H.263 stream",
"h263.stream",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
"The H.263 stream including its Picture, GOB or Macro block start code.", HFILL
}
},
{
&hf_h263_not_dissected,
{
"H.263 Bits currently not dissected",
"h263.not_dis",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"These bits are not dissected(yet), displayed for clarity", HFILL
}
},
};
static gint *ett[] =
{
&ett_h263_payload,
&ett_h263_optype,
};
proto_register_subtree_array(ett, array_length(ett));
proto_h263_data = proto_register_protocol("ITU-T Recommendation H.263",
"H.263", "h263");
proto_register_field_array(proto_h263_data, hf, array_length(hf));
register_dissector("h263data", dissect_h263_data, proto_h263_data);
}
