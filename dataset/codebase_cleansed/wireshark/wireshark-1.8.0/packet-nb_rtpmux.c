static int
dissect_nb_rtpmux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *cmp_rtp_item;
proto_tree *nb_rtpmux_tree, *nb_rtpmux_cmp_rtp_tree;
unsigned int offset = 0;
if (tvb_length(tvb) < 6)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NB_RTPMUX");
while (offset < tvb_reported_length(tvb)-5)
{
guint16 dstport, srcport;
unsigned int length;
gint captured_length;
tvbuff_t* next_tvb;
gboolean tbit;
length = tvb_get_guint8(tvb, offset+2);
ti = proto_tree_add_item(tree, proto_nb_rtpmux, tvb, offset,
length+5, ENC_NA);
nb_rtpmux_tree = proto_item_add_subtree(ti, ett_nb_rtpmux);
proto_tree_add_item(nb_rtpmux_tree,
hf_nb_rtpmux_compressed, tvb, offset, 1, ENC_BIG_ENDIAN);
tbit = tvb_get_guint8(tvb,offset)>>7;
if(tbit == 1){
dstport = (tvb_get_ntohs(tvb, offset) & 0x7fff) << 1;
proto_tree_add_uint(nb_rtpmux_tree, hf_nb_rtpmux_dstport, tvb, offset, 2, dstport );
proto_tree_add_item(nb_rtpmux_tree,
hf_nb_rtpmux_length, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nb_rtpmux_tree, hf_nb_r_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
srcport = (tvb_get_ntohs(tvb, offset+3) & 0x7fff) << 1;
proto_tree_add_uint(nb_rtpmux_tree, hf_nb_rtpmux_srcport, tvb, offset+3, 2, srcport );
cmp_rtp_item = proto_tree_add_text( nb_rtpmux_tree, tvb, offset+5, 3, "Compressed RTP header" );
nb_rtpmux_cmp_rtp_tree = proto_item_add_subtree(cmp_rtp_item, ett_nb_rtpmux_cmp_rtp_hdr);
proto_tree_add_item(nb_rtpmux_cmp_rtp_tree, hf_nb_rtpmux_cmp_rtp_sequence_no, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nb_rtpmux_cmp_rtp_tree, hf_nb_rtpmux_cmp_rtp_timestamp, tvb, offset+6, 2, ENC_BIG_ENDIAN);
if (length != 0)
proto_tree_add_item(nb_rtpmux_cmp_rtp_tree, hf_nb_rtpmux_cmp_rtp_data,tvb, offset+8, length-3, ENC_NA);
}else{
dstport = (tvb_get_ntohs(tvb, offset) & 0x7fff) << 1;
proto_tree_add_uint(nb_rtpmux_tree, hf_nb_rtpmux_dstport, tvb, offset, 2, dstport );
proto_tree_add_item(nb_rtpmux_tree,
hf_nb_rtpmux_length, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nb_rtpmux_tree, hf_nb_r_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
srcport = (tvb_get_ntohs(tvb, offset+3) & 0x7fff) << 1;
proto_tree_add_uint(nb_rtpmux_tree, hf_nb_rtpmux_srcport, tvb, offset+3, 2, srcport );
if (length != 0)
{
if (rtpdissector)
{
captured_length = tvb_length_remaining(tvb, offset + 5);
if (captured_length > (gint)length)
captured_length = length;
next_tvb = tvb_new_subset(tvb, offset+5, captured_length,
length);
call_dissector(rtpdissector, next_tvb, pinfo, nb_rtpmux_tree);
}
else
{
proto_tree_add_item(nb_rtpmux_tree,
hf_nb_rtpmux_data, tvb, offset+5, length, ENC_NA);
}
}
}
offset += 5+length;
}
return tvb_length(tvb);
}
void
proto_register_nb_rtpmux(void)
{
static hf_register_info hf[] = {
{ &hf_nb_rtpmux_compressed,
{ "Compressed headers(T bit)", "nb_rtpmux.compressed",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_nb_rtpmux_dstport,
{ "Dst port", "nb_rtpmux.dstport",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
NULL, HFILL }
},
{ &hf_nb_rtpmux_length,
{ "Length", "nb_rtpmux.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nb_r_bit,
{ "R bit", "nb_rtpmux.r_bit",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_nb_rtpmux_srcport,
{ "Src port", "nb_rtpmux.srcport",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
NULL, HFILL }
},
{ &hf_nb_rtpmux_data,
{ "RTP Packet", "nb_rtpmux.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nb_rtpmux_cmp_rtp_sequence_no,
{ "Sequence Number", "nb_rtpmux.cmp_rtp.sequence_no",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nb_rtpmux_cmp_rtp_timestamp,
{ "Timestamp", "nb_rtpmux.cmp_rtp.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_nb_rtpmux_cmp_rtp_data,
{ "RTP Data", "nb_rtpmux.cmp_rtp.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL,HFILL }
}
};
static gint *ett[] = {
&ett_nb_rtpmux,
&ett_nb_rtpmux_cmp_rtp_hdr
};
proto_nb_rtpmux = proto_register_protocol("3GPP Nb Interface RTP Multiplex",
"NB_RTPMUX", "nb_rtpmux");
proto_register_field_array(proto_nb_rtpmux, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nb_rtpmux(void)
{
dissector_handle_t nb_rtpmux_handle;
nb_rtpmux_handle = new_create_dissector_handle(dissect_nb_rtpmux,
proto_nb_rtpmux);
dissector_add_handle("udp.port", nb_rtpmux_handle);
rtpdissector = find_dissector("rtp");
}
