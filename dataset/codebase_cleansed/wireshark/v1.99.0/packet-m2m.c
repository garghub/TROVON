static void
m2m_defragment_init(void)
{
reassembly_table_init(&pdu_reassembly_table,
&addresses_reassembly_table_functions);
}
static void dissect_m2m(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_item *m2m_item = NULL;
proto_tree *m2m_tree = NULL;
proto_tree *tlv_tree = NULL;
gint burst_number = 0;
gint length, offset = 0;
gint tlv_count;
gint tlv_type, tlv_len, tlv_offset, tlv_value;
gint tlv_frag_type = 0;
gint tlv_frag_number = 0;
tlv_info_t m2m_tlv_info;
gint hf;
guint encoding;
guint frame_number;
int expected_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WiMax");
col_clear(pinfo->cinfo, COL_INFO);
{
m2m_item = proto_tree_add_item(tree, proto_m2m, tvb, 0, -1, ENC_NA);
m2m_tree = proto_item_add_subtree(m2m_item, ett_m2m);
length = tvb_reported_length(tvb);
proto_item_append_text(m2m_item, " (%u bytes)", length);
proto_tree_add_item(m2m_tree, hf_m2m_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(m2m_tree, hf_m2m_tlv_count, tvb, offset, 2, ENC_BIG_ENDIAN);
tlv_count = tvb_get_ntohs(tvb, offset);
offset += 2;
while ( tlv_count > 0)
{
init_tlv_info(&m2m_tlv_info, tvb, offset);
tlv_type = get_tlv_type(&m2m_tlv_info);
tlv_len = get_tlv_length(&m2m_tlv_info);
if(tlv_type == -1 || tlv_len > 64000 || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "M2M TLV error");
proto_tree_add_item(m2m_tree, hf_wimax_invalid_tlv, tvb, offset, (length - offset), ENC_NA);
break;
}
tlv_offset = get_tlv_value_offset(&m2m_tlv_info);
ti = proto_tree_add_protocol_format(m2m_tree, proto_m2m, tvb, offset, (tlv_len + tlv_offset), "%s", val_to_str(tlv_type, tlv_name, "Unknown TLV"));
tlv_tree = proto_item_add_subtree(ti, ett_m2m_tlv);
offset += tlv_offset;
expected_len = 0;
hf = 0;
encoding = ENC_NA;
switch (tlv_type)
{
case TLV_PROTO_VER:
tlv_value = tvb_get_guint8( tvb, offset );
proto_item_append_text(ti, ": %d", tlv_value);
hf = hf_m2m_value_protocol_vers_uint8;
encoding = ENC_BIG_ENDIAN;
expected_len = 1;
break;
case TLV_BURST_NUM:
burst_number = tvb_get_guint8( tvb, offset );
proto_item_append_text(ti, ": %d", burst_number);
hf = hf_m2m_value_burst_num_uint8;
encoding = ENC_BIG_ENDIAN;
expected_len = 1;
break;
case TLV_FRAG_TYPE:
tlv_frag_type = tvb_get_guint8( tvb, offset );
proto_item_append_text(ti, ": %s", val_to_str(tlv_frag_type, tlv_frag_type_name, "Unknown"));
hf = hf_m2m_value_frag_type_uint8;
encoding = ENC_BIG_ENDIAN;
expected_len = 1;
break;
case TLV_FRAG_NUM:
tlv_frag_number = tvb_get_guint8( tvb, offset );
proto_item_append_text(ti, ": %d", tlv_frag_number);
hf = hf_m2m_value_frag_num_uint8;
encoding = ENC_BIG_ENDIAN;
expected_len = 1;
break;
case TLV_PDU_BURST:
proto_item_append_text(ti, " (%u bytes)", tlv_len);
pdu_burst_decoder(tree, tvb, offset, tlv_len, pinfo, burst_number, tlv_frag_type, tlv_frag_number);
hf = hf_m2m_value_pdu_burst;
encoding = ENC_NA;
break;
case TLV_FAST_FB:
proto_item_append_text(ti, " (%u bytes)", tlv_len);
fast_feedback_burst_decoder(tree, tvb, offset, tlv_len, pinfo);
hf = hf_m2m_value_fast_fb;
encoding = ENC_NA;
break;
case TLV_FRAME_NUM:
frame_number = tvb_get_ntoh24( tvb, offset );
proto_tree_add_item(tlv_tree, hf_m2m_frame_number, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ": %d", frame_number);
break;
case TLV_FCH_BURST:
tlv_value = tvb_get_ntoh24( tvb, offset );
proto_item_append_text(ti, ": 0x%X", tlv_value);
fch_burst_decoder(tree, tvb, offset, tlv_len, pinfo);
hf = hf_m2m_value_fch_burst_uint24;
encoding = ENC_BIG_ENDIAN;
expected_len = 3;
break;
case TLV_CDMA_CODE:
tlv_value = tvb_get_ntoh24( tvb, offset );
proto_item_append_text(ti, ": 0x%X", tlv_value);
cdma_code_decoder(tree, tvb, offset, tlv_len, pinfo);
hf = hf_m2m_value_cdma_code_uint24;
encoding = ENC_BIG_ENDIAN;
expected_len = 3;
break;
case TLV_CRC16_STATUS:
tlv_value = tvb_get_guint8( tvb, offset );
proto_item_append_text(ti, ": %s", val_to_str(tlv_value, tlv_crc16_status, "Unknown"));
hf = hf_m2m_value_crc16_status_uint8;
encoding = ENC_BIG_ENDIAN;
expected_len = 1;
break;
case TLV_BURST_POWER:
tlv_value = tvb_get_ntohs( tvb, offset );
proto_item_append_text(ti, ": %d", tlv_value);
hf = hf_m2m_value_burst_power_uint16;
encoding = ENC_BIG_ENDIAN;
expected_len = 2;
break;
case TLV_BURST_CINR:
tlv_value = tvb_get_ntohs( tvb, offset );
proto_item_append_text(ti, ": 0x%X", tlv_value);
hf = hf_m2m_value_burst_cinr_uint16;
encoding = ENC_BIG_ENDIAN;
expected_len = 2;
break;
case TLV_PREAMBLE:
tlv_value = tvb_get_ntohs( tvb, offset );
proto_item_append_text(ti, ": 0x%X", tlv_value);
hf = hf_m2m_value_preamble_uint16;
encoding = ENC_BIG_ENDIAN;
expected_len = 2;
break;
case TLV_HARQ_ACK_BURST:
proto_item_append_text(ti, " (%u bytes)", tlv_len);
harq_ack_bursts_decoder(tree, tvb, offset, tlv_len, pinfo);
hf = hf_m2m_value_harq_ack_burst_bytes;
encoding = ENC_NA;
break;
case TLV_PHY_ATTRIBUTES:
proto_item_append_text(ti, " (%u bytes)", tlv_len);
physical_attributes_decoder(tree, tvb, offset, tlv_len, pinfo);
hf = hf_m2m_phy_attributes;
encoding = ENC_NA;
break;
case TLV_EXTENDED_TLV:
proto_item_append_text(ti, " (%u bytes)", tlv_len);
extended_tlv_decoder(pinfo);
break;
default:
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "Unknown TLV Type");
break;
}
if (hf) {
if (offset - tlv_offset == expected_len) {
proto_tree_add_tlv(&m2m_tlv_info, tvb, offset - tlv_offset, pinfo, tlv_tree, hf, encoding);
} else {
expert_add_info_format(pinfo, NULL, &ei_m2m_unexpected_length, "Expected length %d, got %d.", expected_len, offset - tlv_offset);
}
}
offset += tlv_len;
tlv_count--;
}
}
}
static void fch_burst_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo)
{
if(wimax_fch_burst_handle)
{
call_dissector(wimax_fch_burst_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "FCH Burst: DL Frame Prefix");
}
}
static void cdma_code_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo)
{
if(wimax_cdma_code_burst_handle)
{
call_dissector(wimax_cdma_code_burst_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "CDMA Code Attribute");
}
}
static void pdu_burst_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo, gint burst_number, gint frag_type, gint frag_number)
{
fragment_head *pdu_frag;
tvbuff_t *pdu_tvb = NULL;
switch (frag_type)
{
case TLV_FIRST_FRAG:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "First TLV Fragment (%d)", frag_number);
break;
case TLV_LAST_FRAG:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Last TLV Fragment (%d)", frag_number);
break;
case TLV_MIDDLE_FRAG:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Middle TLV Fragment %d", frag_number);
break;
}
if(frag_type == TLV_NO_FRAG)
{
pdu_tvb = tvb_new_subset_length(tvb, offset, length);
}
else
{
pdu_frag = fragment_add_seq(&pdu_reassembly_table, tvb, offset, pinfo, burst_number, NULL, frag_number - 1, length, ((frag_type==TLV_LAST_FRAG)?0:1), 0);
if(pdu_frag && frag_type == TLV_LAST_FRAG)
{
pdu_tvb = tvb_new_chain(tvb, pdu_frag->tvb_data);
add_new_data_source(pinfo, pdu_tvb, "Reassembled WiMax PDU Frame");
}
else
{
pdu_tvb = NULL;
if(frag_type == TLV_LAST_FRAG)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "Incomplete PDU frame");
}
}
}
if(pdu_tvb)
{
if(wimax_pdu_burst_handle)
{
call_dissector(wimax_pdu_burst_handle, pdu_tvb, pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "PDU Burst");
}
}
}
static void fast_feedback_burst_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo)
{
if(wimax_ffb_burst_handle)
{
call_dissector(wimax_ffb_burst_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "Fast Feedback Burst");
}
}
static void harq_ack_bursts_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo)
{
if(wimax_hack_burst_handle)
{
call_dissector(wimax_hack_burst_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "HARQ ACK Bursts");
}
}
static void physical_attributes_decoder(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, packet_info *pinfo)
{
if(wimax_phy_attributes_burst_handle)
{
call_dissector(wimax_phy_attributes_burst_handle, tvb_new_subset_length(tvb, offset, length), pinfo, tree);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "PHY-attr");
}
}
static void extended_tlv_decoder(packet_info *pinfo)
{
col_append_str(pinfo->cinfo, COL_INFO, "Extended TLV");
}
void proto_tree_add_tlv(tlv_info_t *self, tvbuff_t *tvb, guint offset, packet_info *pinfo, proto_tree *tree, gint hf, guint encoding)
{
guint tlv_offset;
gint tlv_type, tlv_len;
if(!self->valid)
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "Invalid TLV");
return;
}
tlv_offset = offset;
proto_tree_add_item(tree, hf_m2m_type, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
tlv_offset++;
if( self->length_type )
{
proto_tree_add_item(tree, hf_m2m_len_size, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
tlv_offset++;
if(self->size_of_length)
proto_tree_add_item(tree, hf_m2m_len, tvb, tlv_offset, self->size_of_length, ENC_BIG_ENDIAN);
else
return;
}
else
proto_tree_add_item(tree, hf_m2m_len, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
tlv_type = get_tlv_type(self);
if ( tlv_type == TLV_FRAME_NUM )
{
return;
}
tlv_len = get_tlv_length(self);
proto_tree_add_item(tree, hf, tvb, (offset + self->value_offset), tlv_len, encoding);
}
void proto_register_m2m(void)
{
static hf_register_info hf[] =
{
{
&hf_m2m_sequence_number,
{
"Packet Sequence Number", "m2m.seq_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_frame_number,
{
"Value", "m2m.frame_number",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_tlv_count,
{
"Number of TLVs in the packet", "m2m.tlv_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
}
};
static hf_register_info hf_tlv[] =
{
{
&hf_m2m_type,
{
"Type", "m2m.tlv_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_len,
{
"Length", "m2m.tlv_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_len_size,
{
"Length Size", "m2m.tlv_len_size",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{
&hf_m2m_value_bytes,
{
"Value (hex)", "m2m.multibyte_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
{
&hf_m2m_value_protocol_vers_uint8,
{
"Value", "m2m.protocol_vers_tlv_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_burst_num_uint8,
{
"Value", "m2m.burst_num_tlv_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_frag_type_uint8,
{
"Value", "m2m.frag_type_tlv_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_frag_num_uint8,
{
"Value", "m2m.frag_num_tlv_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_pdu_burst,
{
"Value (hex)", "m2m.pdu_burst_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_fast_fb,
{
"Value (hex)", "m2m.fast_fb_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_fch_burst_uint24,
{
"Value", "m2m.fch_burst_tlv_value",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_cdma_code_uint24,
{
"Value", "m2m.cdma_code_tlv_value",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_crc16_status_uint8,
{
"Value", "m2m.crc16_status_tlv_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_burst_power_uint16,
{
"Value", "m2m.burst_power_tlv_value",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_burst_cinr_uint16,
{
"Value", "m2m.burst_cinr_tlv_value",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_preamble_uint16,
{
"Value", "m2m.preamble_tlv_value",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_value_harq_ack_burst_bytes,
{
"Value (hex)", "m2m.harq_ack_burst_tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_m2m_phy_attributes,
{
"Value (hex)", "m2m.phy_attributes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_wimax_invalid_tlv,
{
"Invalid TLV (hex)", "m2m.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_m2m,
&ett_m2m_tlv,
&ett_m2m_fch,
&ett_m2m_cdma,
&ett_m2m_ffb,
};
static ei_register_info ei[] = {
{ &ei_m2m_unexpected_length, { "m2m.unexpected_length", PI_MALFORMED, PI_ERROR, "Unexpected length", EXPFILL }},
};
expert_module_t* expert_m2m;
proto_m2m = proto_register_protocol (
"WiMax Mac to Mac Packet",
"M2M (m2m)",
"m2m"
);
proto_register_field_array(proto_m2m, hf, array_length(hf));
proto_register_field_array(proto_m2m, hf_tlv, array_length(hf_tlv));
proto_register_subtree_array(ett, array_length(ett));
expert_m2m = expert_register_protocol(proto_m2m);
expert_register_field_array(expert_m2m, ei, array_length(ei));
register_init_routine(m2m_defragment_init);
}
void proto_reg_handoff_m2m(void)
{
dissector_handle_t m2m_handle;
m2m_handle = create_dissector_handle(dissect_m2m, proto_m2m);
dissector_add_uint("ethertype", ETHERTYPE_WMX_M2M, m2m_handle);
wimax_cdma_code_burst_handle = find_dissector("wimax_cdma_code_burst_handler");
wimax_fch_burst_handle = find_dissector("wimax_fch_burst_handler");
wimax_ffb_burst_handle = find_dissector("wimax_ffb_burst_handler");
wimax_hack_burst_handle = find_dissector("wimax_hack_burst_handler");
wimax_pdu_burst_handle = find_dissector("wimax_pdu_burst_handler");
wimax_phy_attributes_burst_handle = find_dissector("wimax_phy_attributes_burst_handler");
}
