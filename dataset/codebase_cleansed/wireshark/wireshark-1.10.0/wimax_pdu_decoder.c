static void dissect_wimax_pdu_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset;
guint mac_ht, mac_ec;
guint first_byte, length;
guint mac_hcs, mac_hcs_calculated;
proto_item *pdu_item = NULL;
proto_tree *pdu_tree = NULL;
#ifndef STATIC_DATA
wimax_mac_gen_crc32_table();
wimax_mac_gen_crc8_table();
#endif
for(offset = 0; offset < tvb_reported_length(tvb); )
{
if (offset == 0)
{
first_gmh = TRUE;
}
else
{
first_gmh = FALSE;
}
length = tvb_reported_length_remaining(tvb, offset);
first_byte = tvb_get_guint8(tvb, offset);
if(first_byte == WIMAX_PDU_PADDING_MASK)
{
pdu_item = proto_tree_add_protocol_format(tree, proto_wimax_pdu_decoder, tvb, offset, length, "Padding (%u bytes)", length);
pdu_tree = proto_item_add_subtree(pdu_item, ett_wimax_pdu_decoder);
proto_tree_add_item(pdu_tree, hf_wimax_value_bytes, tvb, offset, length, ENC_NA);
break;
}
else if((first_byte & WIMAX_MAP_TYPE_MASK) == WIMAX_HARQ_MAP_MSG_IND)
{
length = ((tvb_get_ntohs(tvb, offset) & WIMAX_HARQ_MAP_MSG_LENGTH_MASK1) >> 2);
if (length == 0)
{
length = 3;
}
dissector_wimax_harq_map_decoder(tvb_new_subset(tvb,offset,length,length), pinfo, tree);
offset += length;
continue;
}
else if((first_byte & WIMAX_MAP_TYPE_MASK) == WIMAX_COMPRESSED_DL_MAP_IND)
{
if(is_down_link(pinfo))
{
if ((first_byte & REDUCED_PRIVATE_MAP_MASK) == REDUCED_PRIVATE_MAP_MASK)
{
length = wimax_decode_dlmap_reduced_aas(tvb, pinfo, tree);
}
else
{
length = wimax_decode_dlmapc(tvb, pinfo, tree);
}
offset += length;
continue;
}
}
else if((first_byte & WIMAX_INVALID_PDU_MASK) == WIMAX_INVALID_PDU_MASK)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Invalid PDU");
pdu_item = proto_tree_add_protocol_format(tree, proto_wimax_pdu_decoder, tvb, offset, length, "Invalid PDU (%u bytes)", length);
pdu_tree = proto_item_add_subtree(pdu_item, ett_wimax_pdu_decoder);
proto_tree_add_item(pdu_tree, hf_wimax_value_bytes, tvb, offset, length, ENC_NA);
break;
}
mac_hcs_calculated = wimax_mac_calc_crc8(tvb_get_ptr(tvb, offset, WIMAX_MAC_HEADER_INFO_FIELDS), WIMAX_MAC_HEADER_INFO_FIELDS);
mac_hcs = tvb_get_guint8(tvb, offset + WIMAX_MAC_HEADER_SIZE - 1);
if(mac_hcs != mac_hcs_calculated)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "MAC Header CRC error");
pdu_item = proto_tree_add_protocol_format(tree, proto_wimax_pdu_decoder, tvb, offset, WIMAX_MAC_HEADER_SIZE, "MAC Header CRC error %X (in header) and %X (calculated)", mac_hcs, mac_hcs_calculated);
pdu_tree = proto_item_add_subtree(pdu_item, ett_wimax_pdu_decoder);
proto_tree_add_item(pdu_tree, hf_wimax_value_bytes, tvb, offset, length, ENC_NA);
break;
}
mac_ht = ((first_byte & WIMAX_MAC_HEADER_HT_FIELD)?1:0);
mac_ec = ((first_byte & WIMAX_MAC_HEADER_EC_FIELD)?1:0);
if(!mac_ht)
{
length = (tvb_get_guint8(tvb, offset+1) & WIMAX_MAC_HEADER_LENGTH_MSB_MASK);
length = ((length<<8) | tvb_get_guint8(tvb, offset+2));
}
else
{
length = WIMAX_MAC_HEADER_SIZE;
}
pdu_item = proto_tree_add_protocol_format(tree, proto_wimax_pdu_decoder, tvb, offset, length, "PDU (%u bytes)", length);
pdu_tree = proto_item_add_subtree(pdu_item, ett_wimax_pdu_decoder);
if (length == 0) {
offset += 6;
continue;
}
if(mac_ht)
{
if(mac_ec)
{
proto_item_append_text(pdu_item, " - Mac Type II Header: ");
dissect_mac_header_type_2_decoder(tvb_new_subset(tvb,offset,length,length), pinfo, pdu_tree);
}
else
{
proto_item_append_text(pdu_item, " - Mac Type I Header: ");
dissect_mac_header_type_1_decoder(tvb_new_subset(tvb,offset,length,length), pinfo, pdu_tree);
}
}
else
{
dissect_mac_header_generic_decoder(tvb_new_subset(tvb,offset,length,length), pinfo, pdu_tree);
}
offset += length;
}
}
void proto_register_wimax_pdu(void)
{
static hf_register_info hf[] =
{
{
&hf_wimax_value_bytes,
{
"Values", "wmx.pdu.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_wimax_pdu_decoder,
};
proto_wimax_pdu_decoder = proto_wimax;
register_dissector("wimax_pdu_burst_handler", dissect_wimax_pdu_decoder, -1);
proto_register_field_array(proto_wimax_pdu_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_register_mac_header_generic();
proto_register_mac_header_type_1();
proto_register_mac_header_type_2();
}
