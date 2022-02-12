void fec_decode_ext_fti(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint8 encoding_id)
{
guint64 transfer_length;
fec_packet_data_t *fec_data;
guint8 instance_id = 0;
proto_item *ti;
if (encoding_id == 6){
transfer_length = tvb_get_ntoh40(tvb, offset+2);
}
else {
transfer_length = tvb_get_ntoh48(tvb, offset+2);
}
if (encoding_id >= 128)
{
instance_id = (guint8) tvb_get_ntohs(tvb, offset+8);
fec_data = wmem_new0(wmem_file_scope(), fec_packet_data_t);
fec_data->instance_id = instance_id;
p_add_proto_data(wmem_file_scope(), pinfo, proto_rmt_fec, 0, fec_data);
}
if (encoding_id == 6){
proto_tree_add_uint64(tree, hf_fti_transfer_length, tvb, offset+2, 5, transfer_length);
}
else {
proto_tree_add_uint64(tree, hf_fti_transfer_length, tvb, offset+2, 6, transfer_length);
ti = proto_tree_add_item(tree, hf_instance_id, tvb, offset+8, 2, ENC_BIG_ENDIAN);
if ((encoding_id < 128) && (instance_id != 0)) {
expert_add_info(pinfo, ti, &ei_fec_encoding_id);
}
}
switch (encoding_id)
{
case 1:
proto_tree_add_item(tree, hf_fti_encoding_symbol_length, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_num_blocks, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_num_subblocks, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_alignment, tvb, offset+15, 1, ENC_BIG_ENDIAN);
break;
case 6:
proto_tree_add_item(tree, hf_fti_encoding_symbol_length, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_num_blocks, tvb, offset+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_num_subblocks, tvb, offset+11, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_alignment, tvb, offset+13, 1, ENC_BIG_ENDIAN);
break;
case 0:
case 2:
case 128:
case 130:
proto_tree_add_item(tree, hf_fti_encoding_symbol_length, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_max_source_block_length, tvb, offset+12, 4, ENC_BIG_ENDIAN);
break;
case 129:
proto_tree_add_item(tree, hf_fti_encoding_symbol_length, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_max_source_block_length, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_max_number_encoding_symbols, tvb, offset+14, 2, ENC_BIG_ENDIAN);
break;
case 132:
proto_tree_add_item(tree, hf_fti_encoding_symbol_length, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_max_source_block_length, tvb, offset+12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fti_max_number_encoding_symbols, tvb, offset+16, 4, ENC_BIG_ENDIAN);
break;
}
}
static int
dissect_fec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *fec_tree;
guint offset = 0;
fec_data_exchange_t *fec = (fec_data_exchange_t*)data;
guint8 encoding_id = 0;
fec_packet_data_t *packet_data = (fec_packet_data_t*)p_get_proto_data(wmem_file_scope(), pinfo, proto_rmt_fec, 0);
if (fec != NULL)
{
encoding_id = fec->encoding_id;
}
ti = proto_tree_add_item(tree, proto_rmt_fec, tvb, offset, -1, ENC_NA);
fec_tree = proto_item_add_subtree(ti, ett_main);
proto_tree_add_uint(fec_tree, hf_encoding_id, tvb, offset, 0, encoding_id);
if (encoding_id >= 128 && (packet_data != NULL))
proto_tree_add_uint(fec_tree, hf_instance_id, tvb, offset, 0, packet_data->instance_id);
switch (encoding_id)
{
case 0:
case 1:
case 130:
proto_tree_add_item(fec_tree, hf_sbn, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_esi, tvb, offset+2, 2, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "SBN: %u", tvb_get_ntohs(tvb, offset));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ESI: 0x%X", tvb_get_ntohs(tvb, offset+2));
offset += 4;
break;
case 2:
case 128:
case 132:
proto_tree_add_item(fec_tree, hf_sbn, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_esi, tvb, offset+4, 4, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "SBN: %u", tvb_get_ntohl(tvb, offset));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ESI: 0x%X", tvb_get_ntohl(tvb, offset+4));
offset += 8;
break;
case 3:
case 4:
proto_tree_add_item(fec_tree, hf_sbn_with_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_esi_with_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "SBN: %u", tvb_get_ntohl(tvb, offset) >> 20);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ESI: 0x%X", tvb_get_ntohl(tvb, offset) & 0xfffff);
offset += 4;
break;
case 6:
proto_tree_add_item(fec_tree, hf_sbn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_esi, tvb, offset+1, 3, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "SBN: %u", tvb_get_guint8(tvb, offset));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ESI: 0x%X", tvb_get_ntoh24(tvb, offset+1));
offset += 4;
break;
case 129:
proto_tree_add_item(fec_tree, hf_sbn, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_sbl, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fec_tree, hf_esi, tvb, offset+6, 2, ENC_BIG_ENDIAN);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "SBN: %u", tvb_get_ntohl(tvb, offset));
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "ESI: 0x%X", tvb_get_ntohs(tvb, offset+6));
offset += 8;
break;
}
return offset;
}
void proto_register_rmt_fec(void)
{
static hf_register_info hf[] = {
{ &hf_encoding_id,
{ "FEC Encoding ID", "rmt-fec.encoding_id",
FT_UINT8, BASE_DEC, VALS(string_fec_encoding_id), 0x0,
NULL, HFILL }
},
{ &hf_instance_id,
{ "FEC Instance ID", "rmt-fec.instance_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sbn,
{ "Source Block Number", "rmt-fec.sbn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sbn_with_mask,
{ "Source Block Number", "rmt-fec.sbn",
FT_UINT32, BASE_DEC, NULL, 0xFFF00000,
NULL, HFILL }
},
{ &hf_sbl,
{ "Source Block Length", "rmt-fec.sbl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_esi,
{ "Encoding Symbol ID", "rmt-fec.esi",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_esi_with_mask,
{ "Encoding Symbol ID", "rmt-fec.esi",
FT_UINT32, BASE_HEX, NULL, 0x000FFFFF,
NULL, HFILL }
},
{ &hf_fti_transfer_length,
{ "Transfer Length", "rmt-fec.fti.transfer_length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_encoding_symbol_length,
{ "Encoding Symbol Length", "rmt-fec.fti.encoding_symbol_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_max_source_block_length,
{ "Maximum Source Block Length", "rmt-fec.fti.max_source_block_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_max_number_encoding_symbols,
{ "Maximum Number of Encoding Symbols", "rmt-fec.fti.max_number_encoding_symbols",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_num_blocks,
{ "Number of Source Blocks", "rmt-fec.fti.num_blocks",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_num_subblocks,
{ "Number of Sub-Blocks", "rmt-fec.fti.num_subblocks",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_fti_alignment,
{ "Symbol Alignment", "rmt-fec.fti.alignment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_main,
};
static ei_register_info ei[] = {
{ &ei_fec_encoding_id, { "rmt-fec.encoding_id.not0", PI_PROTOCOL, PI_WARN, "FEC Encoding ID < 128, should be zero", EXPFILL }},
};
expert_module_t* expert_rmt_fec;
proto_rmt_fec = proto_register_protocol("Forward Error Correction (FEC)", "RMT-FEC", "rmt-fec");
new_register_dissector("rmt-fec", dissect_fec, proto_rmt_fec);
proto_register_field_array(proto_rmt_fec, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rmt_fec = expert_register_protocol(proto_rmt_fec);
expert_register_field_array(expert_rmt_fec, ei, array_length(ei));
}
