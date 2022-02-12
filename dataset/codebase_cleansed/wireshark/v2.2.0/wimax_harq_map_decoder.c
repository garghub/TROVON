static int dissector_wimax_harq_map_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint i, offset = 0;
guint tvb_len, length, dl_ie_count;
guint ie_length;
proto_item *harq_map_item = NULL;
proto_tree *harq_map_tree = NULL;
guint nibble_offset;
proto_item *parent_item = NULL;
guint ulmap_appended;
guint32 harq_map_msg_crc, calculated_crc;
guint32 first_24bits;
tvb_len = tvb_reported_length(tvb);
if(!tvb_len)
{
return 0;
}
first_24bits = tvb_get_ntoh24(tvb, offset);
if((first_24bits & WIMAX_HARQ_MAP_INDICATOR_MASK) != WIMAX_HARQ_MAP_INDICATOR_MASK)
{
return 0;
}
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "HARQ-MAP Message: ");
if (tree)
{
parent_item = proto_tree_get_parent(tree);
harq_map_item = proto_tree_add_protocol_format(tree, proto_wimax_harq_map_decoder, tvb, offset, tvb_len, "HARQ-MAP Message (%u bytes)", tvb_len);
harq_map_tree = proto_item_add_subtree(harq_map_item, ett_wimax_harq_map_decoder);
proto_tree_add_item(harq_map_tree, hf_harq_map_indicator, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(harq_map_tree, hf_harq_ul_map_appended, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(harq_map_tree, hf_harq_map_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(harq_map_tree, hf_harq_map_msg_length, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(harq_map_tree, hf_harq_dl_ie_count, tvb, offset, 3, ENC_BIG_ENDIAN);
length = ((first_24bits & WIMAX_HARQ_MAP_MSG_LENGTH_MASK) >> WIMAX_HARQ_MAP_MSG_LENGTH_SHIFT);
dl_ie_count = ((first_24bits & WIMAX_HARQ_MAP_DL_IE_COUNT_MASK) >> WIMAX_HARQ_MAP_DL_IE_COUNT_SHIFT);
ulmap_appended = (first_24bits & WIMAX_HARQ_UL_MAP_APPENDED_MASK);
offset += 2;
nibble_offset = 1;
for(i=0; i<dl_ie_count; i++)
{
proto_item_append_text(parent_item, " - DL-MAP IEs");
ie_length = wimax_compact_dlmap_ie_decoder(harq_map_tree, pinfo, tvb, offset, nibble_offset);
offset += ((nibble_offset + ie_length) >> 1);
nibble_offset = ((nibble_offset + ie_length) & 1);
}
if (ulmap_appended)
{
proto_item_append_text(parent_item, ",UL-MAP IEs");
while(offset < (length - (int)sizeof(harq_map_msg_crc)))
{
ie_length = wimax_compact_ulmap_ie_decoder(harq_map_tree, pinfo, tvb, offset, nibble_offset);
if (ie_length < 2)
ie_length = 2;
offset += ((nibble_offset + ie_length) >> 1);
nibble_offset = ((nibble_offset + ie_length) & 1);
}
}
if(nibble_offset)
{
proto_item_append_text(parent_item, ",Padding");
proto_tree_add_protocol_format(harq_map_tree, proto_wimax_harq_map_decoder, tvb, offset, 1, "Padding Nibble: 0x%x", (tvb_get_guint8(tvb, offset) & LSB_NIBBLE_MASK));
}
proto_item_append_text(parent_item, ",CRC");
calculated_crc = wimax_mac_calc_crc32(tvb_get_ptr(tvb, 0, length - (int)sizeof(harq_map_msg_crc)), length - (int)sizeof(harq_map_msg_crc));
proto_tree_add_checksum(tree, tvb, length - (int)sizeof(harq_map_msg_crc), hf_harq_map_msg_crc, -1, NULL, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
return tvb_captured_length(tvb);
}
void proto_register_wimax_harq_map(void)
{
static hf_register_info hf_harq_map[] =
{
{
&hf_harq_map_indicator,
{"HARQ MAP Indicator", "wmx.harq_map.indicator", FT_UINT24, BASE_HEX, NULL, WIMAX_HARQ_MAP_INDICATOR_MASK, NULL, HFILL}
},
{
&hf_harq_ul_map_appended,
{"HARQ UL-MAP Appended", "wmx.harq_map.ul_map_appended", FT_UINT24, BASE_HEX, NULL, WIMAX_HARQ_UL_MAP_APPENDED_MASK, NULL, HFILL}
},
{
&hf_harq_map_reserved,
{"Reserved", "wmx.harq_map.reserved", FT_UINT24, BASE_HEX, NULL, WIMAX_HARQ_MAP_RESERVED_MASK, NULL, HFILL}
},
{
&hf_harq_map_msg_length,
{"Map Message Length", "wmx.harq_map.msg_length", FT_UINT24, BASE_DEC, NULL, WIMAX_HARQ_MAP_MSG_LENGTH_MASK, NULL, HFILL}
},
{
&hf_harq_dl_ie_count,
{"DL IE Count", "wmx.harq_map.dl_ie_count", FT_UINT24, BASE_DEC, NULL, WIMAX_HARQ_MAP_DL_IE_COUNT_MASK, NULL, HFILL}
},
{
&hf_harq_map_msg_crc,
{"HARQ MAP Message CRC", "wmx.harq_map.msg_crc", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] =
{
&ett_wimax_harq_map_decoder,
};
proto_wimax_harq_map_decoder = proto_wimax;
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_wimax_harq_map_decoder, hf_harq_map, array_length(hf_harq_map));
register_dissector("wimax_harq_map_handler", dissector_wimax_harq_map_decoder, proto_wimax_harq_map_decoder);
}
