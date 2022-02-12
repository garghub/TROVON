static guint get_optommp_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint len = OPTO_FRAME_HEADER_LEN;
guint8 tcode = 0;
tcode = tvb_get_guint8(tvb, offset + 3) >> 4;
if( tcode == OPTOMMP_WRITE_QUADLET_REQUEST ||
tcode == OPTOMMP_WRITE_BLOCK_REQUEST ||
tcode == OPTOMMP_READ_BLOCK_REQUEST ||
tcode == OPTOMMP_READ_QUADLET_RESPONSE ||
tcode == OPTOMMP_READ_BLOCK_RESPONSE )
{
len = 16;
}
else if( tcode == OPTOMMP_WRITE_RESPONSE ||
tcode == OPTOMMP_READ_QUADLET_REQUEST )
{
len = 12;
}
if( (tcode == OPTOMMP_WRITE_BLOCK_REQUEST ||
tcode == OPTOMMP_READ_BLOCK_RESPONSE) &&
tvb_reported_length_remaining(tvb, offset) >= 14 )
{
len += (guint) tvb_get_ntohs(tvb, offset + 12);
}
return len;
}
static gint dissect_optommp_reassemble_tcp(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, OPTO_FRAME_HEADER_LEN,
get_optommp_message_len, dissect_optommp, data);
return tvb_captured_length(tvb);
}
static gint dissect_optommp_reassemble_udp(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
dissect_optommp(tvb, pinfo, tree, data);
return tvb_captured_length(tvb);
}
static gint dissect_optommp(tvbuff_t *tvb, packet_info *pinfo, proto_tree
*tree, void *data _U_)
{
guint8 tcode = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OptoMMP");
col_clear(pinfo->cinfo, COL_INFO);
if( tvb_reported_length(tvb) >= OPTOMMP_MIN_LENGTH)
{
tcode = tvb_get_guint8(tvb, 3) >> 4;
if( optommp_has_destination_offset(tcode) != 0 &&
tvb_reported_length(tvb) >= 12)
{
guint64 destination_offset = 0;
destination_offset = tvb_get_ntoh48(tvb, 6);
col_add_fstr(pinfo->cinfo, COL_INFO,
" type: %s, dest_off: 0x%012" G_GINT64_MODIFIER "x",
val_to_str(tcode, optommp_tcode_names, "Unknown (0x%02x)"),
destination_offset);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, " type: %s",
val_to_str(tcode, optommp_tcode_names, "Unknown (0x%02x)"));
}
}
if( tree )
{
proto_item *root_ti = NULL;
proto_item *ti = NULL;
proto_tree *optommp_tree = NULL;
guint offset = 0;
root_ti = proto_tree_add_item(tree, proto_optommp, tvb, 0, -1,
ENC_NA);
if( tvb_reported_length(tvb) >= OPTOMMP_MIN_LENGTH)
{
tcode = tvb_get_guint8(tvb, 3) >> 4;
proto_item_append_text(root_ti, ", type: %s", val_to_str(tcode,
optommp_tcode_names, "Unknown (0x%02x)"));
if( optommp_has_destination_offset(tcode) != 0 )
{
guint64 destination_offset = 0;
destination_offset = tvb_get_ntoh48(tvb, 6);
proto_item_append_text(root_ti,
", dest_off: 0x%012" G_GINT64_MODIFIER "x",
destination_offset);
}
optommp_tree = proto_item_add_subtree(root_ti, ett_optommp);
dissect_optommp_dest_id(optommp_tree, tvb, &offset);
ti = proto_tree_add_item(optommp_tree, hf_optommp_tl, tvb, offset,
1, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(optommp_tree, hf_optommp_tcode, tvb,
offset, 1, ENC_BIG_ENDIAN);
tcode = tvb_get_guint8(tvb, offset) >> 4;
++offset;
switch( tcode )
{
case 0:
dissect_optommp_write_quadlet_request(&ti, optommp_tree, tvb,
&offset);
break;
case 1:
dissect_optommp_write_block_request(&ti, optommp_tree, tvb,
&offset);
break;
case 2:
dissect_optommp_write_response(&ti, optommp_tree, tvb,
&offset);
break;
case 4:
dissect_optommp_read_quadlet_request(&ti, optommp_tree, tvb,
&offset);
break;
case 5:
dissect_optommp_read_block_request(&ti, optommp_tree, tvb,
&offset);
break;
case 6:
dissect_optommp_read_quadlet_response(&ti, optommp_tree, tvb,
&offset);
break;
case 7:
dissect_optommp_read_block_response(&ti, optommp_tree, tvb,
&offset);
break;
}
}
}
return tvb_captured_length(tvb);
}
static void dissect_optommp_dest_id(proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
proto_tree *dest_id_tree = NULL;
guint16 dest_id = 0;
dest_id = tvb_get_ntohs(tvb, *poffset);
if( (dest_id & 0x8000) == 0x8000 )
{
dest_id_tree = proto_tree_add_subtree(tree, tvb, *poffset,
2, ett_dest_id, NULL, "destination_ID");
proto_tree_add_item(dest_id_tree, hf_optommp_dest_id,
tvb, *poffset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dest_id_tree, hf_optommp_boot_id,
tvb, *poffset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_optommp_nodest_id,
tvb, *poffset, 2, ENC_BIG_ENDIAN);
}
*poffset += 2;
}
static void dissect_optommp_write_quadlet_request(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_destination_offset_6(ti, tree, tvb, poffset);
dissect_optommp_quadlet_data(ti, tree, tvb, poffset);
}
static void dissect_optommp_write_block_request(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
guint16 data_length = 0;
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_destination_offset_6(ti, tree, tvb, poffset);
data_length = dissect_optommp_data_length(ti, tree, tvb, poffset);
*poffset += 2;
dissect_optommp_data_block(ti, tree, tvb, poffset, data_length);
}
static void dissect_optommp_write_response(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_rcode(ti, tree, tvb, poffset);
}
static void dissect_optommp_read_quadlet_request(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_destination_offset_6(ti, tree, tvb, poffset);
}
static void dissect_optommp_read_block_request(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_destination_offset_6(ti, tree, tvb, poffset);
dissect_optommp_data_length(ti, tree, tvb, poffset);
}
static void dissect_optommp_read_quadlet_response(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_rcode(ti, tree, tvb, poffset);
*poffset += 5;
dissect_optommp_quadlet_data(ti, tree, tvb, poffset);
}
static void dissect_optommp_read_block_response(proto_item **ti, proto_tree
*tree, tvbuff_t *tvb, guint *poffset)
{
guint16 data_length = 0;
dissect_optommp_source_ID(ti, tree, tvb, poffset);
dissect_optommp_rcode(ti, tree, tvb, poffset);
*poffset += 5;
data_length = dissect_optommp_data_length(ti, tree, tvb, poffset);
*poffset += 2;
dissect_optommp_data_block(ti, tree, tvb, poffset, data_length);
}
static void dissect_optommp_source_ID(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 2 )
{
*ti = proto_tree_add_item(tree, hf_optommp_source_ID, tvb, *poffset,
2, ENC_BIG_ENDIAN);
}
*poffset += 2;
}
static void dissect_optommp_destination_offset_6(proto_item **ti,
proto_tree *tree, tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 6 )
{
*poffset += 2;
*ti = proto_tree_add_item(tree, hf_optommp_dest_offset, tvb,
*poffset, 4, ENC_BIG_ENDIAN);
}
*poffset += 4;
}
static void dissect_optommp_quadlet_data(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 4 )
{
*ti = proto_tree_add_item(tree, hf_optommp_quadlet_data, tvb,
*poffset, 4, ENC_BIG_ENDIAN);
}
*poffset += 4;
}
static guint16 dissect_optommp_data_length(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
guint16 data_length = 0;
if( tvb_reported_length(tvb) >= *poffset + 2 )
{
data_length = tvb_get_ntohs(tvb, *poffset);
*ti = proto_tree_add_item(tree, hf_optommp_data_length, tvb,
*poffset, 2, ENC_BIG_ENDIAN);
}
*poffset += 2;
return data_length;
}
static void dissect_optommp_rcode(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 1 )
{
*ti = proto_tree_add_item(tree, hf_optommp_rcode, tvb, *poffset,
1, ENC_BIG_ENDIAN);
}
++(*poffset);
}
static void dissect_optommp_data_block(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset, guint16 data_length)
{
proto_tree *data_block_tree_b = NULL;
proto_tree *data_block_tree_q = NULL;
guint i = 0;
guint quadlet_offset = 0;
guint byte_offset = 0;
quadlet_offset = *poffset;
byte_offset = *poffset;
data_block_tree_q = proto_tree_add_subtree(tree, tvb, *poffset,
data_length, ett_data_block_q, ti, "data_block (as quadlets)");
for( i = 0; i < (guint16) (data_length / 4); ++i )
{
dissect_optommp_data_block_quadlet(ti, data_block_tree_q, tvb,
&quadlet_offset);
}
data_block_tree_b = proto_tree_add_subtree(tree, tvb, *poffset,
data_length, ett_data_block_b, ti, "data_block (as bytes)");
for( i = 0; i < data_length; ++i )
{
dissect_optommp_data_block_byte(ti, data_block_tree_b, tvb,
&byte_offset);
}
}
static void dissect_optommp_data_block_byte(proto_item **ti, proto_tree *tree,
tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 1 )
{
GByteArray *unused_ret_val = NULL;
unused_ret_val = g_byte_array_new();
*ti = proto_tree_add_bytes_item(tree, hf_optommp_data_block_byte, tvb,
*poffset, 1, 0x0, unused_ret_val, NULL, NULL);
g_byte_array_free(unused_ret_val, TRUE);
}
++(*poffset);
}
static void dissect_optommp_data_block_quadlet(proto_item **ti, proto_tree
*tree, tvbuff_t *tvb, guint *poffset)
{
if( tvb_reported_length(tvb) >= *poffset + 4 )
{
*ti = proto_tree_add_item(tree, hf_optommp_data_block_quadlet,
tvb, *poffset, 4, ENC_NA);
}
*poffset += 4;
}
static gint optommp_has_destination_offset(guint8 tcode)
{
if( tcode == 0 || tcode == 1 || tcode == 4 || tcode == 5 )
return 1;
return 0;
}
void proto_register_optommp(void)
{
static hf_register_info hf[] =
{
{ &hf_optommp_nodest_id,
{ "destination_ID", "optommp.destination_ID",
FT_UINT16, BASE_HEX,
NULL, 0x8000,
NULL, HFILL }
},
{ &hf_optommp_dest_id,
{ "destination_ID", "optommp.destination_ID",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_optommp_boot_id,
{ "boot_ID", "optommp.boot_ID",
FT_UINT16, BASE_HEX,
NULL, 0x7FFF,
NULL, HFILL }
},
{ &hf_optommp_tl,
{ "tl", "optommp.tl",
FT_UINT8, BASE_HEX,
NULL, 0xFC,
NULL, HFILL }
},
{ &hf_optommp_tcode,
{ "tcode", "optommp.tcode",
FT_UINT8, BASE_HEX,
VALS(optommp_tcode_names), 0xF0,
NULL, HFILL }
},
{ &hf_optommp_source_ID,
{ "source_ID", "optommp.source_id",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_optommp_rcode,
{ "rcode", "optommp.rcode",
FT_UINT8, BASE_HEX,
VALS(optommp_rcode_meanings), 0xF0,
NULL, HFILL }
},
{ &hf_optommp_quadlet_data,
{ "quadlet_data", "optommp.quadlet_data",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_optommp_data_length,
{ "data_length", "optommp.data_length",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_optommp_dest_offset,
{ "destination_offset", "optommp.destination_offset",
FT_UINT32, BASE_HEX | BASE_RANGE_STRING,
RVALS(optommp_mm_areas), 0x0,
NULL, HFILL }
},
{ &hf_optommp_data_block_byte,
{ "data_block_byte", "optommp.data_block_byte",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_optommp_data_block_quadlet,
{ "data_block_quadlet", "optommp.data_block_quadlet",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] =
{
&ett_optommp,
&ett_dest_id,
&ett_data_block_q,
&ett_data_block_b
};
proto_optommp = proto_register_protocol("OptoMMP", "OptoMMP", "optommp");
proto_register_field_array(proto_optommp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_optommp(void)
{
optommp_tcp_handle = create_dissector_handle(dissect_optommp_reassemble_tcp, proto_optommp);
optommp_udp_handle = create_dissector_handle(dissect_optommp_reassemble_udp, proto_optommp);
dissector_add_for_decode_as_with_preference("tcp.port", optommp_tcp_handle);
dissector_add_for_decode_as_with_preference("udp.port", optommp_udp_handle);
}
