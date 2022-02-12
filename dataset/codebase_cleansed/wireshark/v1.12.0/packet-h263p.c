static void
dissect_h263P( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti = NULL;
proto_item *data_item = NULL;
proto_item *extra_hdr_item = NULL;
proto_tree *h263P_tree = NULL;
proto_tree *h263P_extr_hdr_tree = NULL;
proto_tree *h263P_data_tree = NULL;
unsigned int offset = 0;
guint16 data16, plen;
guint8 startcode;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "H.263 RFC4629 ");
if ( tree ) {
ti = proto_tree_add_item( tree, proto_h263P, tvb, offset, -1, ENC_NA );
h263P_tree = proto_item_add_subtree( ti, ett_h263P );
data16 = tvb_get_ntohs(tvb,offset);
proto_tree_add_item( h263P_tree, hf_h263P_rr, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_pbit, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_vbit, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_plen, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_pebit, tvb, offset, 2, ENC_BIG_ENDIAN );
offset = offset +2;
if ((data16&0x0200)==0x0200){
proto_tree_add_item( h263P_tree, hf_h263P_tid, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_trun, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( h263P_tree, hf_h263P_s, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
}
plen = (data16 & 0x01f8) >> 3;
if (plen != 0){
extra_hdr_item = proto_tree_add_item( h263P_tree, hf_h263P_extra_hdr, tvb, offset, plen, ENC_NA );
h263P_extr_hdr_tree = proto_item_add_subtree( extra_hdr_item, ett_h263P_extra_hdr );
dissect_h263_picture_layer( tvb, pinfo, h263P_extr_hdr_tree, offset, plen, TRUE);
offset += plen;
}
if ((data16&0x0400)!=0){
data_item = proto_tree_add_item( h263P_tree, hf_h263P_payload, tvb, offset, -1, ENC_NA );
h263P_data_tree = proto_item_add_subtree( data_item, ett_h263P_data );
startcode = tvb_get_guint8(tvb,offset)&0xfe;
if (startcode & 0x80){
switch(startcode){
case 0xf8:
break;
case 0x80:
case 0x82:
col_append_str( pinfo->cinfo, COL_INFO, "(PSC) ");
dissect_h263_picture_layer( tvb, pinfo, h263P_data_tree, offset, -1, TRUE);
break;
case 0xfc:
case 0xfe:
default:
col_append_str( pinfo->cinfo, COL_INFO, "(GBSC) ");
dissect_h263_group_of_blocks_layer( tvb, h263P_data_tree, offset,TRUE);
break;
}
}else{
}
return;
}
proto_tree_add_item( h263P_tree, hf_h263P_payload, tvb, offset, -1, ENC_NA );
}
}
void
proto_reg_handoff_h263P(void)
{
static dissector_handle_t h263P_handle;
static guint dynamic_payload_type;
static gboolean h263P_prefs_initialized = FALSE;
if (!h263P_prefs_initialized) {
h263P_handle = find_dissector("h263P");
dissector_add_string("rtp_dyn_payload_type","H263-1998", h263P_handle);
dissector_add_string("rtp_dyn_payload_type","H263-2000", h263P_handle);
h263P_prefs_initialized = TRUE;
}
else {
if ( dynamic_payload_type > 95 )
dissector_delete_uint("rtp.pt", dynamic_payload_type, h263P_handle);
}
dynamic_payload_type = temp_dynamic_payload_type;
if ( dynamic_payload_type > 95 ){
dissector_add_uint("rtp.pt", dynamic_payload_type, h263P_handle);
}
}
void
proto_register_h263P(void)
{
module_t *h263P_module;
static hf_register_info hf[] =
{
{
&hf_h263P_payload,
{
"H.263 RFC4629 payload",
"h263p.payload",
FT_NONE,
BASE_NONE,
NULL,
0x0,
"The actual H.263 RFC4629 data", HFILL
}
},
{
&hf_h263P_rr,
{
"Reserved",
"h263p.rr",
FT_UINT16,
BASE_DEC,
NULL,
0xf800,
"Reserved SHALL be zero", HFILL
}
},
{
&hf_h263P_pbit,
{
"P",
"h263p.p",
FT_BOOLEAN,
16,
NULL,
0x0400,
"Indicates (GOB/Slice) start or (EOS or EOSBS)", HFILL
}
},
{
&hf_h263P_vbit,
{
"V",
"h263p.v",
FT_BOOLEAN,
16,
NULL,
0x0200,
"presence of Video Redundancy Coding (VRC) field", HFILL
}
},
{
&hf_h263P_plen,
{
"PLEN",
"h263p.plen",
FT_UINT16,
BASE_DEC,
NULL,
0x01f8,
"Length, in bytes, of the extra picture header", HFILL
}
},
{
&hf_h263P_pebit,
{
"PEBIT",
"h263p.pebit",
FT_UINT16,
BASE_DEC,
NULL,
0x0003,
"number of bits that shall be ignored in the last byte of the picture header", HFILL
}
},
{
&hf_h263P_tid,
{
"Thread ID",
"h263p.tid",
FT_UINT8,
BASE_DEC,
NULL,
0xe0,
NULL, HFILL
}
},
{
&hf_h263P_trun,
{
"Trun",
"h263p.trun",
FT_UINT8,
BASE_DEC,
NULL,
0x1e,
"Monotonically increasing (modulo 16) 4-bit number counting the packet number within each thread", HFILL
}
},
{
&hf_h263P_s,
{
"S",
"h263p.s",
FT_UINT8,
BASE_DEC,
NULL,
0x01,
"Indicates that the packet content is for a sync frame", HFILL
}
},
{
&hf_h263P_extra_hdr,
{
"Extra picture header",
"h263p.extra_hdr",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
#if 0
{
&hf_h263P_PSC,
{
"H.263 PSC",
"h263p.PSC",
FT_UINT16,
BASE_HEX,
NULL,
0xfc00,
"Picture Start Code(PSC)", HFILL
}
},
#endif
#if 0
{
&hf_h263P_TR,
{
"H.263 Temporal Reference",
"h263p.tr",
FT_UINT16,
BASE_HEX,
NULL,
0x03fc,
"Temporal Reference, TR", HFILL
}
},
#endif
};
static gint *ett[] =
{
&ett_h263P,
&ett_h263P_extra_hdr,
&ett_h263P_payload,
&ett_h263P_data,
};
proto_h263P = proto_register_protocol("ITU-T Recommendation H.263 RTP Payload header (RFC4629)",
"H263P", "h263p");
proto_register_field_array(proto_h263P, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h263P_module = prefs_register_protocol(proto_h263P, proto_reg_handoff_h263P);
prefs_register_uint_preference(h263P_module, "dynamic.payload.type",
"H263-1998 and H263-2000 dynamic payload type",
"The dynamic payload type which will be interpreted as H264"
"; The value must be greater than 95",
10,
&temp_dynamic_payload_type);
register_dissector("h263P", dissect_h263P, proto_h263P);
}
