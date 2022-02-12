guint wimax_compact_ulmap_ie_decoder(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint uiuc, byte, length = 0;
guint ul_map_type;
guint harq_region_change_indication;
guint cqi_region_change_indication;
guint ul_map_offset, nibble_length;
guint nband, band_count, i, allocation_mode;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Compact UL-MAP IEs");
#endif
ul_map_offset = offset;
byte = tvb_get_guint8(tvb, ul_map_offset);
if(nibble_offset & 1)
{
ul_map_type = ((byte & UL_MAP_TYPE_MASK_1) >> 1);
}
else
{
ul_map_type = ((byte & UL_MAP_TYPE_MASK) >> 5);
}
switch (ul_map_type)
{
case COMPACT_UL_MAP_TYPE_NORMAL_SUBCHANNEL:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_ulmap_rcid_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_nep_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_nsch_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_nep_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_nsch_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
ul_map_offset++;
length += 2;
}
nibble_length = wimax_compact_ulmap_harq_control_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_UL_MAP_TYPE_BAND_AMC:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_ulmap_rcid_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_nep_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_nsch_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_nep_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_nsch_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
ul_map_offset++;
length += 2;
}
if(max_logical_bands)
{
nband = tvb_get_guint8(tvb, ul_map_offset);
length++;
if(nibble_offset & 1)
{
nband = (nband & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_culmap_num_bands_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
nibble_offset = 0;
if(max_logical_bands == 3)
{
proto_tree_add_item(tree, hf_culmap_band_index, tvb, ul_map_offset, nband, ENC_NA);
length += (nband * 2);
ul_map_offset += nband;
}
else
{
nibble_offset = (nband & 1);
proto_tree_add_item(tree, hf_culmap_band_index, tvb, ul_map_offset, ((nband >> 1) + nibble_offset), ENC_NA);
length += nband;
ul_map_offset += (nband >> 1);
}
}
else
{
nband = ((nband & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_culmap_num_bands, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
if(max_logical_bands == 3)
{
proto_tree_add_item(tree, hf_culmap_band_index, tvb, ul_map_offset, (nband + nibble_offset), ENC_NA);
length += (nband * 2);
ul_map_offset += nband;
}
else
{
proto_tree_add_item(tree, hf_culmap_band_index, tvb, ul_map_offset, ((nband >> 1) + nibble_offset), ENC_NA);
length += nband;
ul_map_offset += ((nband + nibble_offset) >> 1);
if(nband & 1)
nibble_offset = 0;
}
}
band_count = nband;
}
else
{
band_count = 1;
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_nb_bitmap_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_nb_bitmap, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length++;
}
byte = tvb_get_guint8(tvb, ul_map_offset);
if(nibble_offset & 1)
{
allocation_mode = ((byte & ALLOCATION_MODE_MASK_1) >> 2);
proto_tree_add_item(tree, hf_culmap_allocation_mode_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_allocation_mode_rsvd_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 0;
ul_map_offset++;
}
else
{
allocation_mode = ((byte & ALLOCATION_MODE_MASK) >> 6);
proto_tree_add_item(tree, hf_culmap_allocation_mode, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_allocation_mode_rsvd, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length++;
if(!allocation_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_num_subchannels_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_num_subchannels, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
ul_map_offset++;
length += 2;
}
else if(allocation_mode == 1)
{
for(i=0; i<band_count; i++)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_num_subchannels_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_num_subchannels, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
ul_map_offset++;
}
length += (band_count * 2);
}
nibble_length = wimax_compact_ulmap_harq_control_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_UL_MAP_TYPE_SAFETY:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_ulmap_rcid_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_nep_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_nsch_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_nep_code, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_nsch_code_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_shortened_uiuc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_companded_sc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
ul_map_offset++;
length += 2;
}
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_bin_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
}
else
{
proto_tree_add_item(tree, hf_culmap_bin_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 2;
nibble_length = wimax_compact_ulmap_harq_control_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_UL_MAP_TYPE_UIUC:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
byte = tvb_get_guint8(tvb, ul_map_offset);
uiuc = ((byte & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_culmap_uiuc, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_reserved, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
uiuc = (byte & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_culmap_uiuc_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
}
length = 2;
nibble_length = wimax_compact_ulmap_rcid_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(uiuc == 15)
{
nibble_length = wimax_extended_uiuc_dependent_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
}
else if(uiuc == 14)
{
nibble_length = wimax_cdma_allocation_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
ul_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
}
else if(uiuc == 12)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset_7_1, tvb, ul_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols_7_1, tvb, ul_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels_7_1, tvb, ul_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_ranging_method_1, tvb, ul_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_reserved_1, tvb, ul_map_offset, 4, ENC_BIG_ENDIAN);
ul_map_offset += 3;
}
else
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset_7, tvb, ul_map_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols_7, tvb, ul_map_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels_7, tvb, ul_map_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_ranging_method, tvb, ul_map_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_reserved, tvb, ul_map_offset, 3, ENC_BIG_ENDIAN);
ul_map_offset += 3;
}
length += 8;
}
else
{
if(nibble_offset & 1)
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
length += 2;
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_uiuc_repetition_coding_indication_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_reserved_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_uiuc_repetition_coding_indication, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_uiuc_reserved, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length += 1;
}
nibble_length = wimax_compact_ulmap_harq_control_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_UL_MAP_TYPE_HARQ_REGION_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_harq_region_change_indication_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
harq_region_change_indication = (byte & 0x01);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_harq_region_change_indication, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
harq_region_change_indication = (byte & 0x10);
nibble_offset = 1;
}
length = 1;
if(harq_region_change_indication == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
}
else
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 8;
}
break;
case COMPACT_UL_MAP_TYPE_CQICH_REGION_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_ul_map_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_cqi_region_change_indication_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
cqi_region_change_indication = (byte & 0x01);
ul_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_culmap_ul_map_type, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_cqi_region_change_indication, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
cqi_region_change_indication = (byte & 0x10);
nibble_offset = 1;
}
length = 1;
if(cqi_region_change_indication == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels_1, tvb, ul_map_offset, 2, ENC_BIG_ENDIAN);
ul_map_offset++;
}
else
{
proto_tree_add_item(tree, hf_culmap_uiuc_ofdma_symbol_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_subchannel_offset, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_ofdma_symbols, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
proto_tree_add_item(tree, hf_culmap_uiuc_num_of_subchannels, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
ul_map_offset++;
}
length += 8;
}
break;
case COMPACT_UL_MAP_TYPE_EXTENSION:
nibble_length = wimax_culmap_extension_ie_decoder(tree, pinfo, tvb, ul_map_offset, nibble_offset);
length = nibble_length;
break;
default:
proto_tree_add_item(tree, hf_culmap_reserved_type_1, tvb, ul_map_offset, 1, ENC_BIG_ENDIAN);
length = 1;
break;
}
return length;
}
static guint wimax_compact_ulmap_rcid_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint length = 0;
guint prefix;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "RCID IE");
#endif
if(nibble_offset & 1)
{
if(cid_type == CID_TYPE_NORMAL)
{
proto_tree_add_item(tree, hf_rcid_ie_normal_cid_1, tvb, offset, 3, ENC_BIG_ENDIAN);
length = 4;
}
else
{
prefix = (tvb_get_guint8(tvb, offset) & 0x08);
proto_tree_add_item(tree, hf_rcid_ie_prefix_1, tvb, offset, 2, ENC_BIG_ENDIAN);
if(prefix)
{
proto_tree_add_item(tree, hf_rcid_ie_cid11_3, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else
{
if(cid_type == CID_TYPE_RCID11)
{
proto_tree_add_item(tree, hf_rcid_ie_cid11_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else if(cid_type == CID_TYPE_RCID7)
{
proto_tree_add_item(tree, hf_rcid_ie_cid7_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 2;
}
else if(cid_type == CID_TYPE_RCID3)
{
proto_tree_add_item(tree, hf_rcid_ie_cid3_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 1;
}
}
}
}
else
{
if(cid_type == CID_TYPE_NORMAL)
{
proto_tree_add_item(tree, hf_rcid_ie_normal_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 4;
}
else
{
prefix = (tvb_get_guint8(tvb, offset) & 0x08);
proto_tree_add_item(tree, hf_rcid_ie_prefix, tvb, offset, 2, ENC_BIG_ENDIAN);
if(prefix || (cid_type == CID_TYPE_RCID11))
{
proto_tree_add_item(tree, hf_rcid_ie_cid11_2, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else
{
if(cid_type == CID_TYPE_RCID11)
{
proto_tree_add_item(tree, hf_rcid_ie_cid11, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else if(cid_type == CID_TYPE_RCID7)
{
proto_tree_add_item(tree, hf_rcid_ie_cid7, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 2;
}
else if(cid_type == CID_TYPE_RCID3)
{
proto_tree_add_item(tree, hf_rcid_ie_cid3, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 1;
}
}
}
}
return length;
}
static guint wimax_compact_ulmap_harq_control_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint byte, prefix, length = 0;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "HARQ Control IE");
#endif
byte = tvb_get_guint8(tvb, offset);
if(nibble_offset & 1)
{
prefix = (byte & 0x08);
proto_tree_add_item(tree, hf_harq_control_ie_prefix_1, tvb, offset, 2, ENC_BIG_ENDIAN);
if(prefix)
{
proto_tree_add_item(tree, hf_harq_control_ie_ai_sn_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_harq_control_ie_spid_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_harq_control_ie_acid_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 2;
}
else
{
proto_tree_add_item(tree, hf_harq_control_ie_reserved_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 1;
}
}
else
{
prefix = (byte & 0x80);
proto_tree_add_item(tree, hf_harq_control_ie_prefix, tvb, offset, 1, ENC_BIG_ENDIAN);
if(prefix)
{
proto_tree_add_item(tree, hf_harq_control_ie_ai_sn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_harq_control_ie_spid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_harq_control_ie_acid, tvb, offset, 1, ENC_BIG_ENDIAN);
length = 2;
}
else
{
proto_tree_add_item(tree, hf_harq_control_ie_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
length = 1;
}
}
return length;
}
static guint wimax_culmap_extension_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint tvb_value, ul_map_type, sub_type, length;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "UL-MAP Extension IE");
#endif
tvb_value = tvb_get_ntohs(tvb, offset);
if(nibble_offset & 1)
{
ul_map_type = ((tvb_value & EXTENSION_TYPE_MASK_1) >> EXTENSION_TYPE_SHIFT_1);
if(ul_map_type != COMPACT_UL_MAP_TYPE_EXTENSION)
return 0;
sub_type = ((tvb_value & EXTENSION_SUBTYPE_MASK_1) >> EXTENSION_SUBTYPE_SHIFT_1);
length = (tvb_value & EXTENSION_LENGTH_MASK_1);
proto_tree_add_item(tree, hf_culmap_extension_type_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_extension_subtype_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_extension_length_1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (sub_type)
{
case HARQ_MODE_SWITCH:
proto_tree_add_item(tree, hf_culmap_extension_harq_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
tvb_value = tvb_get_guint8(tvb, offset);
harq_mode = ((tvb_value & MSB_NIBBLE_MASK) >> 4);
break;
default:
proto_tree_add_item(tree, hf_culmap_extension_unknown_sub_type_1, tvb, offset, (length - 2), ENC_NA);
break;
}
}
else
{
ul_map_type = ((tvb_value & EXTENSION_TYPE_MASK) >> EXTENSION_TYPE_SHIFT);
if(ul_map_type != COMPACT_UL_MAP_TYPE_EXTENSION)
return 0;
sub_type = ((tvb_value & EXTENSION_SUBTYPE_MASK) >> EXTENSION_SUBTYPE_SHIFT);
length = ((tvb_value & EXTENSION_LENGTH_MASK) >> EXTENSION_LENGTH_SHIFT);
proto_tree_add_item(tree, hf_culmap_extension_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_extension_subtype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_culmap_extension_length, tvb, offset, 2, ENC_BIG_ENDIAN);
switch (sub_type)
{
case HARQ_MODE_SWITCH:
proto_tree_add_item(tree, hf_culmap_extension_harq_mode_1, tvb, offset, 2, ENC_BIG_ENDIAN);
harq_mode = (tvb_value & LSB_NIBBLE_MASK);
break;
default:
proto_tree_add_item(tree, hf_culmap_extension_unknown_sub_type, tvb, (offset + 1), (length - 1), ENC_NA);
break;
}
}
return (length * 2);
}
guint wimax_cdma_allocation_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "CDMA Allocation IE");
#endif
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdma_allocation_duration_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_uiuc_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_repetition_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_frame_number_index_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_code_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_symbol_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_subchannel_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_bw_req_1, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdma_allocation_duration, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_uiuc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_repetition, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_frame_number_index, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_symbol, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_ranging_subchannel, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdma_allocation_bw_req, tvb, offset, 1, ENC_BIG_ENDIAN);
}
return 8;
}
guint wimax_extended_uiuc_dependent_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint ext_uiuc, length, m, i;
guint8 byte;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Extended UIUC IE");
#endif
byte = tvb_get_guint8(tvb, offset);
if(nibble_offset & 1)
{
ext_uiuc = (byte & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_extended_uiuc_ie_uiuc_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
byte = tvb_get_guint8(tvb, offset);
length = ((byte & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_extended_uiuc_ie_length_1, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
ext_uiuc = ((byte & MSB_NIBBLE_MASK) >> 4);
length = (byte & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_extended_uiuc_ie_uiuc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
switch (ext_uiuc)
{
case POWER_CONTROL_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_power_control_24, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_power_measurement_frame_24, tvb, offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_power_control, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_power_measurement_frame, tvb, (offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
case MINI_SUBCHANNEL_ALLOCATION_IE:
switch (length)
{
case 15:
m = 6;
break;
case 9:
m = 3;
break;
case 7:
default:
m = 2;
break;
}
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_ctype_16, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_duration_16, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_ctype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_duration, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset++;
for(i=0; i<m; i+=2)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_cid_1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_1, tvb, offset, 4, ENC_BIG_ENDIAN);
if(i < (m-2))
{
offset += 3;
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_cid_3, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_3, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_3, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 3;
}
else if(m == 3)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_padding_1, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_cid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_repetition, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if(i < (m-2))
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_cid_2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_2, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if(m == 3)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mini_subchannel_alloc_padding, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
}
break;
case AAS_UL_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_aas_ul, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_aas_ul, tvb, offset, length, ENC_NA);
}
break;
case CQICH_ALLOC_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_cqich_alloc, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_cqich_alloc, tvb, offset, length, ENC_NA);
}
break;
case UL_ZONE_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_zone, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_zone, tvb, offset, length, ENC_NA);
}
break;
case PHYMOD_UL_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_phymod_ul, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_phymod_ul, tvb, offset, length, ENC_NA);
}
break;
case MIMO_UL_BASIC_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mimo_ul_basic, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_mimo_ul_basic, tvb, offset, length, ENC_NA);
}
break;
case UL_MAP_FAST_TRACKING_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_fast_tracking, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_fast_tracking, tvb, offset, length, ENC_NA);
}
break;
case UL_PUSC_BURST_ALLOCATION_IN_OTHER_SEGMENT_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_pusc_burst_allocation, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_pusc_burst_allocation, tvb, offset, length, ENC_NA);
}
break;
case FAST_RANGING_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_fast_ranging, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_fast_ranging, tvb, offset, length, ENC_NA);
}
break;
case UL_ALLOCATION_START_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_allocation_start, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_ul_allocation_start, tvb, offset, length, ENC_NA);
}
break;
default:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_unknown_uiuc, tvb, offset, (length + 1), ENC_NA);
}
else
{
proto_tree_add_item(tree, hf_extended_uiuc_ie_unknown_uiuc, tvb, offset, length, ENC_NA);
}
break;
}
return ((length + 1) * 2 );
}
void proto_register_wimax_compact_ulmap_ie(void)
{
static hf_register_info hf_compact_ulmap[] =
{
{
&hf_culmap_ul_map_type,
{"UL-MAP Type", "wmx.compact_ulmap.ul_map_type", FT_UINT8, BASE_DEC, NULL, UL_MAP_TYPE_MASK, NULL, HFILL}
},
{
&hf_culmap_ul_map_type_1,
{"UL-MAP Type", "wmx.compact_ulmap.ul_map_type", FT_UINT8, BASE_DEC, NULL, UL_MAP_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_culmap_reserved,
{"Reserved", "wmx.compact_ulmap.reserved", FT_UINT8, BASE_HEX, NULL, UL_MAP_RESERVED_MASK, NULL, HFILL}
},
{
&hf_culmap_reserved_1,
{"Reserved", "wmx.compact_ulmap.reserved", FT_UINT8, BASE_HEX, NULL, UL_MAP_RESERVED_MASK_1, NULL, HFILL}
},
{
&hf_culmap_nep_code,
{"Nep Code", "wmx.compact_ulmap.nep_code", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_nep_code_1,
{"Nep Code", "wmx.compact_ulmap.nep_code", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_nsch_code,
{"Nsch Code", "wmx.compact_ulmap.nsch_code", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_nsch_code_1,
{"Nsch Code", "wmx.compact_ulmap.nsch_code", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_shortened_uiuc,
{"Shortened UIUC", "wmx.compact_ulmap.shortened_uiuc", FT_UINT8, BASE_HEX, NULL, SHORTENED_UIUC_MASK, NULL, HFILL}
},
{
&hf_culmap_companded_sc,
{"Companded SC", "wmx.compact_ulmap.companded_sc", FT_UINT8, BASE_HEX, NULL, COMPANDED_SC_MASK, NULL, HFILL}
},
{
&hf_culmap_shortened_uiuc_1,
{"Shortened UIUC", "wmx.compact_ulmap.shortened_uiuc", FT_UINT16, BASE_HEX, NULL, SHORTENED_UIUC_MASK_1, NULL, HFILL}
},
{
&hf_culmap_companded_sc_1,
{"Companded SC", "wmx.compact_ulmap.companded_sc", FT_UINT16, BASE_HEX, NULL, COMPANDED_SC_MASK_1, NULL, HFILL}
},
{
&hf_culmap_num_bands,
{"Number Of Bands", "wmx.compact_ulmap.num_bands", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_num_bands_1,
{"Number Of Bands", "wmx.compact_ulmap.num_bands", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_band_index,
{"Band Index", "wmx.compact_ulmap.band_index", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_nb_bitmap,
{"Number Of Bits For Band BITMAP", "wmx.compact_ulmap.nb_bitmap", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_nb_bitmap_1,
{"Number Of Bits For Band BITMAP", "wmx.compact_ulmap.nb_bitmap", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_allocation_mode,
{"Allocation Mode", "wmx.compact_ulmap.allocation_mode", FT_UINT8, BASE_DEC, VALS(vals_allocation_modes), ALLOCATION_MODE_MASK, NULL, HFILL}
},
{
&hf_culmap_allocation_mode_1,
{"Allocation Mode", "wmx.compact_ulmap.allocation_mode", FT_UINT8, BASE_DEC, VALS(vals_allocation_modes), ALLOCATION_MODE_MASK_1, NULL, HFILL}
},
{
&hf_culmap_allocation_mode_rsvd,
{"Reserved", "wmx.compact_ulmap.allocation_mode_rsvd", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL}
},
{
&hf_culmap_allocation_mode_rsvd_1,
{"Reserved", "wmx.compact_ulmap.allocation_mode_rsvd", FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL}
},
{
&hf_culmap_num_subchannels,
{"Number Of Subchannels", "wmx.compact_ulmap.num_subchannels", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_num_subchannels_1,
{"Number Of Subchannels", "wmx.compact_ulmap.num_subchannels", FT_UINT16, BASE_DEC, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_bin_offset,
{"BIN Offset", "wmx.compact_ulmap.bin_offset", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_bin_offset_1,
{"BIN Offset", "wmx.compact_ulmap.bin_offset", FT_UINT16, BASE_HEX, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc,
{"UIUC", "wmx.compact_ulmap.uiuc", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_1,
{"UIUC", "wmx.compact_ulmap.uiuc", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_ofdma_symbol_offset,
{"OFDMA Symbol Offset", "wmx.compact_ulmap.uiuc_ofdma_symbol_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_uiuc_ofdma_symbol_offset_1,
{"OFDMA Symbol Offset", "wmx.compact_ulmap.uiuc_ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_subchannel_offset_7,
{"Subchannel Offset", "wmx.compact_ulmap.uiuc_subchannel_offset", FT_UINT24, BASE_DEC, NULL, 0xFE0000, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_ofdma_symbols_7,
{"Number Of OFDMA Symbols", "wmx.compact_ulmap.uiuc_num_of_ofdma_symbols", FT_UINT24, BASE_DEC, NULL, 0x01FC00, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_subchannels_7,
{"Number Of Subchannels", "wmx.compact_ulmap.uiuc_num_of_subchannels", FT_UINT24, BASE_DEC, NULL, 0x0003F8, NULL, HFILL}
},
{
&hf_culmap_uiuc_ranging_method,
{"Ranging Method", "wmx.compact_ulmap.uiuc_ranging_method", FT_UINT24, BASE_DEC, NULL, 0x000006, NULL, HFILL}
},
{
&hf_culmap_uiuc_reserved,
{"Reserved", "wmx.compact_ulmap.uiuc_reserved", FT_UINT24, BASE_HEX, NULL, 0x000001, NULL, HFILL}
},
{
&hf_culmap_uiuc_subchannel_offset_7_1,
{"Subchannel Offset", "wmx.compact_ulmap.uiuc_subchannel_offset", FT_UINT32, BASE_DEC, NULL, 0x00FE0000, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_ofdma_symbols_7_1,
{"Number Of OFDMA Symbols", "wmx.compact_ulmap.uiuc_num_of_ofdma_symbols", FT_UINT32, BASE_DEC, NULL, 0x0001FC00, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_subchannels_7_1,
{"Number Of Subchannels", "wmx.compact_ulmap.uiuc_num_of_subchannels", FT_UINT32, BASE_DEC, NULL, 0x000003F80, NULL, HFILL}
},
{
&hf_culmap_uiuc_ranging_method_1,
{"Ranging Method", "wmx.compact_ulmap.uiuc_ranging_method", FT_UINT32, BASE_DEC, NULL, 0x00000006, NULL, HFILL}
},
{
&hf_culmap_uiuc_reserved_1,
{"Reserved", "wmx.compact_ulmap.uiuc_reserved", FT_UINT32, BASE_HEX, NULL, 0x00000001, NULL, HFILL}
},
{
&hf_culmap_uiuc_repetition_coding_indication,
{"Repetition Coding Indication", "wmx.compact_ulmap.uiuc_repetition_coding_indication", FT_UINT8, BASE_DEC, VALS(vals_repetitions), ALLOCATION_MODE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_repetition_coding_indication_1,
{"Repetition Coding Indication", "wmx.compact_ulmap.uiuc_repetition_coding_indication", FT_UINT8, BASE_DEC, VALS(vals_repetitions), ALLOCATION_MODE_MASK_1, NULL, HFILL}
},
{
&hf_culmap_uiuc_reserved1,
{"Reserved", "wmx.compact_ulmap.uiuc_reserved1", FT_UINT8, BASE_HEX, NULL, 0x30, NULL, HFILL}
},
{
&hf_culmap_uiuc_reserved11_1,
{"Reserved", "wmx.compact_ulmap.uiuc_reserved1", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL}
},
{
&hf_culmap_uiuc_subchannel_offset,
{"Subchannel Offset", "wmx.compact_ulmap.uiuc_subchannel_offset", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_uiuc_subchannel_offset_1,
{"Subchannel Offset", "wmx.compact_ulmap.uiuc_subchannel_offset", FT_UINT16, BASE_DEC, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_ofdma_symbols,
{"Number Of OFDMA Symbols", "wmx.compact_ulmap.uiuc_num_of_ofdma_symbols", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_ofdma_symbols_1,
{"Number Of OFDMA Symbols", "wmx.compact_ulmap.uiuc_num_of_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_subchannels,
{"Number Of Subchannels", "wmx.compact_ulmap.uiuc_num_of_subchannels", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_uiuc_num_of_subchannels_1,
{"Number Of Subchannels", "wmx.compact_ulmap.uiuc_num_of_subchannels", FT_UINT16, BASE_DEC, NULL, MIDDLE_BYTE_MASK, NULL, HFILL}
},
{
&hf_culmap_harq_region_change_indication,
{"HARQ Region Change Indication", "wmx.compact_ulmap.harq_region_change_indication", FT_BOOLEAN, 8, TFS(&tfs_region_change), 0x10, NULL, HFILL}
},
{
&hf_culmap_harq_region_change_indication_1,
{"HARQ Region Change Indication", "wmx.compact_ulmap.harq_region_change_indication", FT_BOOLEAN, 8, TFS(&tfs_region_change), 0x01, NULL, HFILL}
},
{
&hf_culmap_cqi_region_change_indication,
{"CQI Region Change Indication", "wmx.compact_ulmap.cqi_region_change_indication", FT_BOOLEAN, 8, TFS(&tfs_region_change), 0x10, NULL, HFILL}
},
{
&hf_culmap_cqi_region_change_indication_1,
{"CQI Region Change Indication", "wmx.compact_ulmap.cqi_region_change_indication", FT_BOOLEAN, 8, TFS(&tfs_region_change), 0x01, NULL, HFILL}
},
{
&hf_culmap_reserved_type,
{"UL-MAP Reserved Type", "wmx.compact_ulmap.reserved_type", FT_UINT8, BASE_DEC, NULL, UL_MAP_TYPE_MASK, NULL, HFILL}
},
{
&hf_culmap_reserved_type_1,
{"UL-MAP Reserved Type", "wmx.compact_ulmap.reserved_type", FT_UINT8, BASE_DEC, NULL, UL_MAP_TYPE_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_rcid[] =
{
{
&hf_rcid_ie_normal_cid,
{"Normal CID", "wmx.harq_map.rcid_ie.normal_cid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_rcid_ie_normal_cid_1,
{"Normal CID", "wmx.harq_map.rcid_ie.normal_cid", FT_UINT24, BASE_HEX, NULL, WIMAX_RCID_IE_NORMAL_CID_MASK_1, NULL, HFILL}
},
{
&hf_rcid_ie_prefix,
{"Prefix", "wmx.harq_map.rcid_ie.prefix", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_PREFIX_MASK, NULL, HFILL}
},
{
&hf_rcid_ie_prefix_1,
{"Prefix", "wmx.harq_map.rcid_ie.prefix", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_PREFIX_MASK_1, NULL, HFILL}
},
{
&hf_rcid_ie_cid3,
{"3 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid3", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID3_MASK, NULL, HFILL}
},
{
&hf_rcid_ie_cid3_1,
{"3 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid3", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID3_MASK_1, NULL, HFILL}
},
{
&hf_rcid_ie_cid7,
{"7 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid7", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID7_MASK, NULL, HFILL}
},
{
&hf_rcid_ie_cid7_1,
{"7 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid7", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID7_MASK_1, NULL, HFILL}
},
{
&hf_rcid_ie_cid11,
{"11 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK, NULL, HFILL}
},
{
&hf_rcid_ie_cid11_1,
{"11 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK_1, NULL, HFILL}
},
{
&hf_rcid_ie_cid11_2,
{"11 LSB Of Multicast, AAS or Broadcast CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK, NULL, HFILL}
},
{
&hf_rcid_ie_cid11_3,
{"11 LSB Of Multicast, AAS or Broadcast CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_harq_control[] =
{
{
&hf_harq_control_ie_prefix,
{"Prefix", "wmx.harq_map.harq_control_ie.prefix", FT_BOOLEAN, 8, TFS(&tfs_prefix), WIMAX_HARQ_CONTROL_IE_PREFIX_MASK, NULL, HFILL}
},
{
&hf_harq_control_ie_ai_sn,
{"HARQ ID Sequence Number(AI_SN)", "wmx.harq_map.harq_control_ie.ai_sn", FT_UINT8, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_AI_SN_MASK, NULL, HFILL}
},
{
&hf_harq_control_ie_spid,
{"Subpacket ID (SPID)", "wmx.harq_map.harq_control_ie.spid", FT_UINT8, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_SPID_MASK, NULL, HFILL}
},
{
&hf_harq_control_ie_acid,
{"HARQ CH ID (ACID)", "wmx.harq_map.harq_control_ie.acid", FT_UINT8, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_ACID_MASK, NULL, HFILL}
},
{
&hf_harq_control_ie_reserved,
{"Reserved", "wmx.harq_map.harq_control_ie.reserved", FT_UINT8, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_RESERVED_MASK, NULL, HFILL}
},
{
&hf_harq_control_ie_prefix_1,
{"Prefix", "wmx.harq_map.harq_control_ie.prefix", FT_BOOLEAN, 16, TFS(&tfs_prefix), WIMAX_HARQ_CONTROL_IE_PREFIX_MASK_1, NULL, HFILL}
},
{
&hf_harq_control_ie_ai_sn_1,
{"HARQ ID Sequence Number(AI_SN)", "wmx.harq_map.harq_control_ie.ai_sn", FT_UINT16, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_AI_SN_MASK_1, NULL, HFILL}
},
{
&hf_harq_control_ie_spid_1,
{"Subpacket ID (SPID)", "wmx.harq_map.harq_control_ie.spid", FT_UINT16, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_SPID_MASK_1, NULL, HFILL}
},
{
&hf_harq_control_ie_acid_1,
{"HARQ CH ID (ACID)", "wmx.harq_map.harq_control_ie.acid", FT_UINT16, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_ACID_MASK_1, NULL, HFILL}
},
{
&hf_harq_control_ie_reserved_1,
{"Reserved", "wmx.harq_map.harq_control_ie.reserved", FT_UINT16, BASE_HEX, NULL, WIMAX_HARQ_CONTROL_IE_RESERVED_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_extension_type[] =
{
{
&hf_culmap_extension_type,
{"UL-MAP Type", "wmx.extension_type.ul_map_type", FT_UINT16, BASE_DEC, NULL, EXTENSION_TYPE_MASK, NULL, HFILL}
},
{
&hf_culmap_extension_type_1,
{"UL-MAP Type", "wmx.extension_type.ul_map_type", FT_UINT16, BASE_DEC, NULL, EXTENSION_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_culmap_extension_subtype,
{"Extension Subtype", "wmx.extension_type.subtype", FT_UINT16, BASE_DEC, NULL, EXTENSION_SUBTYPE_MASK, NULL, HFILL}
},
{
&hf_culmap_extension_subtype_1,
{"Extension Subtype", "wmx.extension_type.subtype", FT_UINT16, BASE_DEC, NULL, EXTENSION_SUBTYPE_MASK_1, NULL, HFILL}
},
{
&hf_culmap_extension_length,
{"Extension Length", "wmx.extension_type.length", FT_UINT16, BASE_DEC, NULL, EXTENSION_LENGTH_MASK, NULL, HFILL}
},
{
&hf_culmap_extension_length_1,
{"Extension Length", "wmx.extension_type.length", FT_UINT16, BASE_DEC, NULL, EXTENSION_LENGTH_MASK_1, NULL, HFILL}
},
{
&hf_culmap_extension_time_diversity_mbs,
{"Time Diversity MBS", "wmx.extension_type.time_diversity_mbs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_extension_time_diversity_mbs_1,
{"Time Diversity MBS", "wmx.extension_type.time_diversity_mbs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_extension_harq_mode_1,
{"HARQ Mode Switch", "wmx.extension_type.harq_mode", FT_UINT16, BASE_HEX, NULL, 0x000F, NULL, HFILL}
},
{
&hf_culmap_extension_harq_mode,
{"HARQ Mode Switch", "wmx.extension_type.harq_mode", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_culmap_extension_unknown_sub_type,
{"Unknown Extension Subtype", "wmx.extension_type.unknown_sub_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_culmap_extension_unknown_sub_type_1,
{"Unknown Extension Subtype", "wmx.extension_type.unknown_sub_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_cdma_allocation[] =
{
{
&hf_cdma_allocation_duration,
{"Duration", "wmx.cdma_allocation.duration", FT_UINT16, BASE_DEC, NULL, CDMA_ALLOCATION_DURATION_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_uiuc,
{"UIUC For Transmission", "wmx.cdma_allocation.uiuc", FT_UINT16, BASE_DEC, NULL, CDMA_ALLOCATION_UIUC_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_repetition,
{"Repetition Coding Indication", "wmx.cdma_allocation.allocation_repetition", FT_UINT16, BASE_DEC, VALS(vals_repetitions), CDMA_ALLOCATION_REPETITION_CODE_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_frame_number_index,
{"Frame Number Index (LSBs of relevant frame number)", "wmx.cdma_allocation.frame_number_index", FT_UINT16, BASE_DEC, NULL, CDMA_ALLOCATION_FRAME_NUMBER_INDEX_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_code,
{"Ranging Code", "wmx.cdma_allocation.ranging_code", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_symbol,
{"Ranging Symbol", "wmx.cdma_allocation.ranging_symbol", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_subchannel,
{"Ranging Subchannel", "wmx.cdma_allocation.ranging_subchannel", FT_UINT8, BASE_DEC, NULL, CDMA_ALLOCATION_RANGING_SUBCHANNEL_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_bw_req,
{"BW Request Mandatory", "wmx.cdma_allocation.bw_req", FT_BOOLEAN, 8, TFS(&tfs_yes_no_ie), CDMA_ALLOCATION_BW_REQUEST_MANDATORY_MASK, NULL, HFILL}
},
{
&hf_cdma_allocation_duration_1,
{"Duration", "wmx.cdma_allocation.duration", FT_UINT16, BASE_DEC, NULL, CDMA_ALLOCATION_DURATION_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_uiuc_1,
{"UIUC For Transmission", "wmx.cdma_allocation.uiuc", FT_UINT16, BASE_DEC, NULL, CDMA_ALLOCATION_UIUC_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_repetition_1,
{"Repetition Coding Indication", "wmx.cdma_allocation.allocation_repetition", FT_UINT16, BASE_DEC, VALS(vals_repetitions), CDMA_ALLOCATION_REPETITION_CODE_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_frame_number_index_1,
{"Frame Number Index (LSBs of relevant frame number)", "wmx.cdma_allocation.frame_number_index", FT_UINT32, BASE_DEC, NULL, CDMA_ALLOCATION_FRAME_NUMBER_INDEX_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_code_1,
{"Ranging Code", "wmx.cdma_allocation.ranging_code", FT_UINT32, BASE_DEC, NULL, CDMA_ALLOCATION_RANGING_CODE_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_symbol_1,
{"Ranging Symbol", "wmx.cdma_allocation.ranging_symbol", FT_UINT32, BASE_DEC, NULL, CDMA_ALLOCATION_RANGING_SYMBOL_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_ranging_subchannel_1,
{"Ranging Subchannel", "wmx.cdma_allocation.ranging_subchannel", FT_UINT32, BASE_DEC, NULL, CDMA_ALLOCATION_RANGING_SUBCHANNEL_MASK_1, NULL, HFILL}
},
{
&hf_cdma_allocation_bw_req_1,
{"BW Request Mandatory", "wmx.cdma_allocation.bw_req", FT_BOOLEAN, 32, TFS(&tfs_yes_no_ie), CDMA_ALLOCATION_BW_REQUEST_MANDATORY_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_extended_uiuc[] =
{
{
&hf_extended_uiuc_ie_uiuc,
{"Extended UIUC", "wmx.extended_uiuc_ie.uiuc", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_uiuc_1,
{"Extended UIUC", "wmx.extended_uiuc_ie.uiuc", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_length,
{"Length", "wmx.extended_uiuc_ie.length", FT_UINT8, BASE_DEC, NULL, MSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_length_1,
{"Length", "wmx.extended_uiuc_ie.length", FT_UINT24, BASE_DEC, NULL, LSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_power_control,
{"Power Control", "wmx.extended_uiuc_ie.power_control", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_power_control_24,
{"Power Control", "wmx.extended_uiuc_ie.power_control", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_power_measurement_frame,
{"Power Measurement Frame", "wmx.extended_uiuc_ie.power_measurement_frame", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_power_measurement_frame_24,
{"Power Measurement Frame", "wmx.extended_uiuc_ie.power_measurement_frame", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_ctype,
{"C Type", "wmx.extended_uiuc_ie.mini_subchannel_alloc.ctype", FT_UINT8, BASE_HEX, VALS(vals_ctypes), MINI_SUBCHANNEL_CTYPE_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_ctype_16,
{"C Type", "wmx.extended_uiuc_ie.mini_subchannel_alloc.ctype", FT_UINT16, BASE_HEX, VALS(vals_ctypes), MINI_SUBCHANNEL_CTYPE_MASK_16, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_duration,
{"Duration", "wmx.extended_uiuc_ie.mini_subchannel_alloc.duration", FT_UINT8, BASE_DEC, NULL, MINI_SUBCHANNEL_DURATION_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_duration_16,
{"Duration", "wmx.extended_uiuc_ie.mini_subchannel_alloc.duration", FT_UINT16, BASE_DEC, NULL, MINI_SUBCHANNEL_DURATION_MASK_16, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_cid,
{"CID", "wmx.extended_uiuc_ie.mini_subchannel_alloc.cid", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_CID_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc,
{"UIUC", "wmx.extended_uiuc_ie.mini_subchannel_alloc.uiuc", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_UIUC_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_repetition,
{"Repetition", "wmx.extended_uiuc_ie.mini_subchannel_alloc.repetition", FT_UINT24, BASE_HEX, VALS(vals_repetitions), MINI_SUBCHANNEL_REPETITION_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_cid_1,
{"CID", "wmx.extended_uiuc_ie.mini_subchannel_alloc.cid", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_CID_MASK_1, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_1,
{"UIUC", "wmx.extended_uiuc_ie.mini_subchannel_alloc.uiuc", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_UIUC_MASK_1, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_1,
{"Repetition", "wmx.extended_uiuc_ie.mini_subchannel_alloc.repetition", FT_UINT24, BASE_HEX, VALS(vals_repetitions), MINI_SUBCHANNEL_REPETITION_MASK_1, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_cid_2,
{"CID", "wmx.extended_uiuc_ie.mini_subchannel_alloc.cid", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_CID_MASK_2, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_2,
{"UIUC", "wmx.extended_uiuc_ie.mini_subchannel_alloc.uiuc", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_UIUC_MASK_2, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_2,
{"Repetition", "wmx.extended_uiuc_ie.mini_subchannel_alloc.repetition", FT_UINT24, BASE_HEX, VALS(vals_repetitions), MINI_SUBCHANNEL_REPETITION_MASK_2, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_cid_3,
{"CID", "wmx.extended_uiuc_ie.mini_subchannel_alloc.cid", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_CID_MASK_3, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_uiuc_3,
{"UIUC", "wmx.extended_uiuc_ie.mini_subchannel_alloc.uiuc", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_UIUC_MASK_2, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_repetition_3,
{"Repetition", "wmx.extended_uiuc_ie.mini_subchannel_alloc.repetition", FT_UINT24, BASE_HEX, VALS(vals_repetitions), MINI_SUBCHANNEL_REPETITION_MASK_3, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_padding,
{"Padding", "wmx.extended_uiuc_ie.mini_subchannel_alloc.padding", FT_UINT8, BASE_HEX, NULL, MINI_SUBCHANNEL_PADDING_MASK, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mini_subchannel_alloc_padding_1,
{"Padding", "wmx.extended_uiuc_ie.mini_subchannel_alloc.padding", FT_UINT24, BASE_HEX, NULL, MINI_SUBCHANNEL_PADDING_MASK_1, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_aas_ul,
{"AAS_UL_IE (not implemented)", "wmx.extended_uiuc_ie.aas_ul", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_cqich_alloc,
{"CQICH Allocation IE (not implemented)", "wmx.extended_uiuc_ie.cqich_alloc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_ul_zone,
{"UL Zone IE (not implemented)", "wmx.extended_uiuc_ie.ul_zone", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_mimo_ul_basic,
{"MIMO UL Basic IE (not implemented)", "wmx.extended_uiuc_ie.mimo_ul_basic", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_fast_tracking,
{"UL-MAP Fast Tracking IE (not implemented)", "wmx.extended_uiuc_ie.fast_tracking", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_fast_ranging,
{"Fast Ranging IE (not implemented)", "wmx.extended_uiuc_ie.fast_ranging", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_phymod_ul,
{"UL-MAP Physical Modifier IE (not implemented)", "wmx.extended_uiuc_ie.phymod_ul", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_ul_pusc_burst_allocation,
{"UL_PUSC_Burst_Allocation_in_Other_Segment_IE (not implemented)", "wmx.extended_uiuc_ie.ul_pusc_burst_allocation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_ul_allocation_start,
{"UL Allocation Start IE (not implemented)", "wmx.extended_uiuc_ie.ul_allocation_start", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_uiuc_ie_unknown_uiuc,
{"Unknown Extended UIUC", "wmx.extended_uiuc.unknown_uiuc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
}
};
#if 0
static gint *ett[] =
{
&ett_wimax_compact_ulmap_ie_decoder,
&ett_wimax_rcid_ie_decoder,
&ett_wimax_harq_control_ie_decoder,
&ett_wimax_extended_uiuc_dependent_ie_decoder,
&ett_wimax_extension_type_ie_decoder,
};
proto_register_subtree_array(ett, array_length(ett));
#endif
proto_wimax_compact_ulmap_ie_decoder = proto_wimax;
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_compact_ulmap, array_length(hf_compact_ulmap));
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_rcid, array_length(hf_rcid));
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_harq_control, array_length(hf_harq_control));
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_extension_type, array_length(hf_extension_type));
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_cdma_allocation, array_length(hf_cdma_allocation));
proto_register_field_array(proto_wimax_compact_ulmap_ie_decoder, hf_extended_uiuc, array_length(hf_extended_uiuc));
}
