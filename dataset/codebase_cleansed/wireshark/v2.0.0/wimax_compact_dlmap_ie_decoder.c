guint wimax_compact_dlmap_ie_decoder(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint diuc, byte, length = 0;
guint dl_map_type, ul_map_append;
guint dl_map_offset, nibble_length, bit_map_length;
guint nband, band_count, i, allocation_mode;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Compact DL-MAP IEs");
#endif
dl_map_offset = offset;
byte = tvb_get_guint8(tvb, dl_map_offset);
if(nibble_offset & 1)
{
dl_map_type = ((byte & DL_MAP_TYPE_MASK_1) >> 1);
ul_map_append = (byte & UL_MAP_APPEND_MASK_1);
}
else
{
dl_map_type = ((byte & DL_MAP_TYPE_MASK) >> 5);
ul_map_append = (byte & UL_MAP_APPEND_MASK);
}
switch (dl_map_type)
{
case COMPACT_DL_MAP_TYPE_NORMAL_SUBCHANNEL:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_ul_map_append_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_ul_map_append, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_dlmap_rcid_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nep_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_nsch_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nep_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_nsch_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
length += 2;
}
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
nibble_length = wimax_compact_dlmap_cqich_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
if(ul_map_append)
{
if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_shortened_uiuc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_shortened_uiuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
length += 2;
}
else if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nep_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_nsch_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nep_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_nsch_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
}
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
}
break;
case COMPACT_DL_MAP_TYPE_BAND_AMC:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_dlmap_rcid_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nep_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_nsch_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nep_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_nsch_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
length += 2;
}
if(max_logical_bands)
{
nband = tvb_get_guint8(tvb, dl_map_offset);
if(nibble_offset & 1)
{
nband = (nband & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_cdlmap_num_bands_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
nibble_offset = 0;
if(max_logical_bands == 3)
{
proto_tree_add_item(tree, hf_cdlmap_band_index, tvb, dl_map_offset, nband, ENC_NA);
length += (nband * 2);
dl_map_offset += nband;
}
else
{
nibble_offset = (nband & 1);
proto_tree_add_item(tree, hf_cdlmap_band_index, tvb, dl_map_offset, ((nband >> 1) + nibble_offset), ENC_NA);
length += nband;
dl_map_offset += (nband >> 1);
}
}
else
{
nband = ((nband & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_cdlmap_num_bands, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
if(max_logical_bands == 3)
{
proto_tree_add_item(tree, hf_cdlmap_band_index, tvb, dl_map_offset, (nband + nibble_offset), ENC_NA);
length += (nband * 2);
dl_map_offset += nband;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_band_index, tvb, dl_map_offset, ((nband >> 1) + nibble_offset), ENC_NA);
length += nband;
dl_map_offset += ((nband + nibble_offset) >> 1);
if(nband & 1)
nibble_offset = 0;
}
}
length++;
band_count = nband;
}
else
{
band_count = 1;
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nb_bitmap_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nb_bitmap, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length++;
}
byte = tvb_get_guint8(tvb, dl_map_offset);
if(nibble_offset & 1)
{
allocation_mode = ((byte & 0x0C) >> 2);
proto_tree_add_item(tree, hf_cdlmap_allocation_mode_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_allocation_mode_rsvd_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 0;
dl_map_offset++;
}
else
{
allocation_mode = ((byte & 0xC0) >> 6);
proto_tree_add_item(tree, hf_cdlmap_allocation_mode, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_allocation_mode_rsvd, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
if(!allocation_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_num_subchannels_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_num_subchannels, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
}
else if(allocation_mode == 1)
{
for(i=0; i<band_count; i++)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_num_subchannels_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_num_subchannels, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
}
}
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
nibble_length = wimax_compact_dlmap_cqich_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_DL_MAP_TYPE_SAFETY:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_ul_map_append_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
nibble_offset = 0;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_ul_map_append, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
nibble_offset = 1;
}
length = 1;
nibble_length = wimax_compact_dlmap_rcid_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nep_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_nsch_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nep_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_nsch_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
}
else if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
length += 2;
}
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_bin_offset_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
dl_map_offset++;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_bin_offset, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
nibble_length = wimax_compact_dlmap_cqich_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
if(ul_map_append)
{
if(harq_mode == 1)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_shortened_diuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_companded_sc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
dl_map_offset++;
length += 2;
}
else if(!harq_mode)
{
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_nep_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_nsch_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_nep_code, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_nsch_code_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
}
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_bin_offset_1, tvb, dl_map_offset, 2, ENC_BIG_ENDIAN);
dl_map_offset++;
}
else
{
proto_tree_add_item(tree, hf_cdlmap_bin_offset, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length += 2;
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
}
break;
case COMPACT_DL_MAP_TYPE_UIUC:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
byte = tvb_get_guint8(tvb, dl_map_offset);
diuc = ((byte & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_cdlmap_diuc, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
diuc = (tvb_get_guint8(tvb, dl_map_offset) & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_cdlmap_diuc_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
dl_map_offset++;
}
length = 2;
if(diuc == 15)
{
nibble_length = wimax_extended_diuc_dependent_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
}
else
{
nibble_length = wimax_compact_dlmap_rcid_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += (nibble_length >> 1);
nibble_offset = (nibble_length & 1);
if(nibble_offset & 1)
proto_tree_add_item(tree, hf_cdlmap_diuc_num_of_subchannels_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree, hf_cdlmap_diuc_num_of_subchannels, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length += 2;
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_diuc_repetition_coding_indication_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_diuc_reserved_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_diuc_repetition_coding_indication, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_diuc_reserved, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
}
length += 1;
}
nibble_length = wimax_compact_dlmap_harq_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
dl_map_offset += ((nibble_offset + nibble_length) >> 1);
nibble_offset = ((nibble_offset + nibble_length) & 1);
nibble_length = wimax_compact_dlmap_cqich_control_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length += nibble_length;
break;
case COMPACT_DL_MAP_TYPE_FORMAT_CONF_IE:
nibble_length = wimax_compact_dlmap_format_configuration_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length = nibble_length;
break;
case COMPACT_DL_MAP_TYPE_HARQ_ACK_BITMAP_IE:
if(nibble_offset & 1)
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length = 1;
dl_map_offset++;
byte = tvb_get_guint8(tvb, dl_map_offset);
bit_map_length = ((byte & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_cdlmap_bit_map_length, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_bit_map, tvb, dl_map_offset, bit_map_length + 1, ENC_NA);
length += (1 + bit_map_length * 2);
}
else
{
proto_tree_add_item(tree, hf_cdlmap_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_reserved, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_bit_map_length_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length = 2;
bit_map_length = (byte & LSB_NIBBLE_MASK);
dl_map_offset++;
proto_tree_add_item(tree, hf_cdlmap_bit_map, tvb, dl_map_offset, bit_map_length, ENC_NA);
length += (bit_map_length * 2);
}
break;
case COMPACT_DL_MAP_TYPE_EXTENSION:
nibble_length = wimax_cdlmap_extension_ie_decoder(tree, pinfo, tvb, dl_map_offset, nibble_offset);
length = nibble_length;
break;
default:
proto_tree_add_item(tree, hf_cdlmap_reserved_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length = 1;
break;
}
return length;
}
static guint wimax_compact_dlmap_format_configuration_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint length = 0;
guint dl_map_type, new_format_ind;
guint dl_map_offset;
guint32 tvb_value;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Format Configuration IE");
#endif
dl_map_offset = offset;
tvb_value = tvb_get_guint8(tvb, dl_map_offset);
if(nibble_offset & 1)
{
dl_map_type = ((tvb_value & DL_MAP_TYPE_MASK_1) >> 1);
if(dl_map_type != COMPACT_DL_MAP_TYPE_FORMAT_CONF_IE)
return 0;
new_format_ind = (tvb_value & 0x01);
proto_tree_add_item(tree, hf_format_config_ie_dl_map_type_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_new_format_indication_1, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length = 1;
dl_map_offset++;
if(new_format_ind)
{
proto_tree_add_item(tree, hf_format_config_ie_cid_type, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_safety_pattern, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_subchannel_type, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_max_logical_bands, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_broadcast_symbol, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_dl_band_amc_symbol, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_ul_band_amc_symbol, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
length += 7;
tvb_value = tvb_get_ntohl(tvb, dl_map_offset);
cid_type = ((tvb_value & CID_TYPE_MASK) >> CID_TYPE_SHIFT);
band_amc_subchannel_type = ((tvb_value & BAND_AMC_SUBCHANNEL_TYPE_MASK) >> BAND_AMC_SUBCHANNEL_TYPE_SHIFT);
max_logical_bands = ((tvb_value & MAX_LOGICAL_BANDS_MASK) >> MAX_LOGICAL_BANDS_SHIFT);
num_of_broadcast_symbols = ((tvb_value & NUM_BROADCAST_SYMBOLS_MASK) >> NUM_BROADCAST_SYMBOLS_SHIFT);
num_of_dl_band_amc_symbols = ((tvb_value & NUM_DL_AMC_SYMBOLS_MASK) >> NUM_DL_AMC_SYMBOLS_SHIFT);
num_of_ul_band_amc_symbols = ((tvb_value & NUM_UL_AMC_SYMBOLS_MASK) >> NUM_UL_AMC_SYMBOLS_SHIFT);
}
}
else
{
dl_map_type = ((tvb_value & DL_MAP_TYPE_MASK) >> 5);
if(dl_map_type != COMPACT_DL_MAP_TYPE_FORMAT_CONF_IE)
return 0;
new_format_ind = (tvb_value & 0x10);
if(new_format_ind)
{
proto_tree_add_item(tree, hf_format_config_ie_dl_map_type_32, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_new_format_indication_32, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_cid_type_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_safety_pattern_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_subchannel_type_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_max_logical_bands_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_broadcast_symbol_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_dl_band_amc_symbol_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_num_of_ul_band_amc_symbol_1, tvb, dl_map_offset, 4, ENC_BIG_ENDIAN);
length = 8;
tvb_value = tvb_get_ntohl(tvb, dl_map_offset);
cid_type = ((tvb_value & CID_TYPE_MASK_1) >> CID_TYPE_SHIFT_1);
band_amc_subchannel_type = ((tvb_value & BAND_AMC_SUBCHANNEL_TYPE_MASK_1) >> BAND_AMC_SUBCHANNEL_TYPE_SHIFT_1);
max_logical_bands = ((tvb_value & MAX_LOGICAL_BANDS_MASK_1) >> MAX_LOGICAL_BANDS_SHIFT_1);
num_of_broadcast_symbols = ((tvb_value & NUM_BROADCAST_SYMBOLS_MASK_1) >> NUM_BROADCAST_SYMBOLS_SHIFT_1);
num_of_dl_band_amc_symbols = ((tvb_value & NUM_DL_AMC_SYMBOLS_MASK_1) >> NUM_DL_AMC_SYMBOLS_SHIFT_1);
num_of_ul_band_amc_symbols = (tvb_value & NUM_UL_AMC_SYMBOLS_MASK_1);
}
else
{
proto_tree_add_item(tree, hf_format_config_ie_dl_map_type, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_format_config_ie_new_format_indication, tvb, dl_map_offset, 1, ENC_BIG_ENDIAN);
length = 1;
}
}
return length;
}
static guint wimax_compact_dlmap_rcid_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
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
proto_tree_add_item(tree, hf_harq_rcid_ie_normal_cid_1, tvb, offset, 3, ENC_BIG_ENDIAN);
length = 4;
}
else
{
prefix = (tvb_get_guint8(tvb, offset) & 0x08);
proto_tree_add_item(tree, hf_harq_rcid_ie_prefix_1, tvb, offset, 2, ENC_BIG_ENDIAN);
if(prefix)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid11_3, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else
{
if(cid_type == CID_TYPE_RCID11)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid11_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else if(cid_type == CID_TYPE_RCID7)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid7_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 2;
}
else if(cid_type == CID_TYPE_RCID3)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid3_1, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 1;
}
}
}
}
else
{
if(cid_type == CID_TYPE_NORMAL)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_normal_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 4;
}
else
{
prefix = (tvb_get_guint8(tvb, offset) & 0x08);
proto_tree_add_item(tree, hf_harq_rcid_ie_prefix, tvb, offset, 2, ENC_BIG_ENDIAN);
if(prefix || (cid_type == CID_TYPE_RCID11))
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid11_2, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else
{
if(cid_type == CID_TYPE_RCID11)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid11, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 3;
}
else if(cid_type == CID_TYPE_RCID7)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid7, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 2;
}
else if(cid_type == CID_TYPE_RCID3)
{
proto_tree_add_item(tree, hf_harq_rcid_ie_cid3, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 1;
}
}
}
}
return length;
}
static guint wimax_compact_dlmap_harq_control_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
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
static guint wimax_compact_dlmap_cqich_control_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint byte, cqich_indicator, length = 0;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "CQICH Control IE");
#endif
byte = tvb_get_guint8(tvb, offset);
if(nibble_offset & 1)
{
cqich_indicator = (byte & 0x08);
if(cqich_indicator)
{
proto_tree_add_item(tree, hf_cqich_control_ie_indicator_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_alloc_id_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_period_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_frame_offset_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_duration_1, tvb, offset, 3, ENC_BIG_ENDIAN);
length = 4;
}
else
{
proto_tree_add_item(tree, hf_cqich_control_ie_indicator_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_cqi_rep_threshold_1, tvb, offset, 1, ENC_BIG_ENDIAN);
length = 1;
}
}
else
{
cqich_indicator = (byte & 0x80);
if(cqich_indicator)
{
proto_tree_add_item(tree, hf_cqich_control_ie_indicator, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_alloc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_period, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_frame_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_duration, tvb, offset, 2, ENC_BIG_ENDIAN);
length = 4;
}
else
{
proto_tree_add_item(tree, hf_cqich_control_ie_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cqich_control_ie_cqi_rep_threshold, tvb, offset, 1, ENC_BIG_ENDIAN);
length = 1;
}
}
return length;
}
static guint wimax_cdlmap_extension_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint tvb_value, dl_map_type, sub_type, length;
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "DL-MAP Extension IE");
#endif
tvb_value = tvb_get_ntohs(tvb, offset);
if(nibble_offset & 1)
{
dl_map_type = ((tvb_value & 0x0E00) >> 9);
if(dl_map_type != COMPACT_DL_MAP_TYPE_EXTENSION)
return 0;
sub_type = ((tvb_value & 0x01F0) >> 4);
length = (tvb_value & 0x000F);
proto_tree_add_item(tree, hf_cdlmap_extension_type_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_extension_subtype_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_extension_length_1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (sub_type)
{
case TIME_DIVERSITY_MBS:
proto_tree_add_item(tree, hf_cdlmap_extension_time_diversity_mbs_1, tvb, offset, (length - 2), ENC_NA);
break;
case HARQ_MODE_SWITCH:
proto_tree_add_item(tree, hf_cdlmap_extension_harq_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
tvb_value = tvb_get_guint8(tvb, offset);
harq_mode = ((tvb_value & MSB_NIBBLE_MASK) >> 4);
break;
default:
proto_tree_add_item(tree, hf_cdlmap_extension_unknown_sub_type_1, tvb, offset, (length - 2), ENC_NA);
break;
}
}
else
{
dl_map_type = ((tvb_value & 0xE000) >> 13);
if(dl_map_type != COMPACT_DL_MAP_TYPE_EXTENSION)
return 0;
sub_type = ((tvb_value & 0x1F00) >> 8);
length = ((tvb_value & 0x00F0) >> 4);
proto_tree_add_item(tree, hf_cdlmap_extension_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_extension_subtype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cdlmap_extension_length, tvb, offset, 2, ENC_BIG_ENDIAN);
switch (sub_type)
{
case TIME_DIVERSITY_MBS:
proto_tree_add_item(tree, hf_cdlmap_extension_time_diversity_mbs, tvb, (offset + 1), (length - 1), ENC_NA);
break;
case HARQ_MODE_SWITCH:
proto_tree_add_item(tree, hf_cdlmap_extension_harq_mode_1, tvb, offset, 2, ENC_BIG_ENDIAN);
harq_mode = (tvb_value & 0x000F);
break;
default:
proto_tree_add_item(tree, hf_cdlmap_extension_unknown_sub_type, tvb, (offset + 1), (length - 1), ENC_NA);
break;
}
}
return (length * 2);
}
guint wimax_extended_diuc_dependent_ie_decoder(proto_tree *tree, packet_info *pinfo _U_, tvbuff_t *tvb, guint offset, guint nibble_offset)
{
guint ext_diuc, length;
guint8 byte;
byte = tvb_get_guint8(tvb, offset);
if(nibble_offset & 1)
{
ext_diuc = (byte & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_diuc_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
byte = tvb_get_guint8(tvb, offset);
length = ((byte & MSB_NIBBLE_MASK) >> 4);
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_length, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (ext_diuc)
{
case CHANNEL_MEASUREMENT_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_channel_measurement, tvb, offset, (length + 1), ENC_NA);
break;
case STC_ZONE_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_stc_zone, tvb, offset, (length + 1), ENC_NA);
break;
case AAS_DL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_aas_dl, tvb, offset, (length + 1), ENC_NA);
break;
case DATA_LOCATION_IN_ANOTHER_BS_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_data_location, tvb, offset, (length + 1), ENC_NA);
break;
case CID_SWITCH_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_cid_switch, tvb, offset, (length + 1), ENC_NA);
break;
case MIMO_DL_BASIC_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_mimo_dl_basic, tvb, offset, (length + 1), ENC_NA);
break;
case MIMO_DL_ENHANCED_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_mimo_dl_enhanced, tvb, offset, (length + 1), ENC_NA);
break;
case HARQ_MAP_POINTER_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_harq_map_pointer, tvb, offset, (length + 1), ENC_NA);
break;
case PHYMOD_DL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_phymod_dl, tvb, offset, (length + 1), ENC_NA);
break;
case DL_PUSC_BURST_ALLOCATION_IN_OTHER_SEGMENT_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_dl_pusc_burst_allocation, tvb, offset, (length + 1), ENC_NA);
break;
case UL_INTERFERENCE_AND_NOISE_LEVEL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_ul_interference_and_noise_level, tvb, offset, (length + 1), ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_unknown_diuc, tvb, offset, (length + 1), ENC_NA);
break;
}
}
else
{
ext_diuc = ((byte & MSB_NIBBLE_MASK) >> 4);
length = (byte & LSB_NIBBLE_MASK);
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_diuc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_length_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (ext_diuc)
{
case CHANNEL_MEASUREMENT_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_channel_measurement, tvb, offset, length, ENC_NA);
break;
case STC_ZONE_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_stc_zone, tvb, offset, length, ENC_NA);
break;
case AAS_DL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_aas_dl, tvb, offset, length, ENC_NA);
break;
case DATA_LOCATION_IN_ANOTHER_BS_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_data_location, tvb, offset, length, ENC_NA);
break;
case CID_SWITCH_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_cid_switch, tvb, offset, length, ENC_NA);
break;
case MIMO_DL_BASIC_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_mimo_dl_basic, tvb, offset, length, ENC_NA);
break;
case MIMO_DL_ENHANCED_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_mimo_dl_enhanced, tvb, offset, length, ENC_NA);
break;
case HARQ_MAP_POINTER_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_harq_map_pointer, tvb, offset, length, ENC_NA);
break;
case PHYMOD_DL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_phymod_dl, tvb, offset, length, ENC_NA);
break;
case DL_PUSC_BURST_ALLOCATION_IN_OTHER_SEGMENT_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_dl_pusc_burst_allocation, tvb, offset, length, ENC_NA);
break;
case UL_INTERFERENCE_AND_NOISE_LEVEL_IE:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_ul_interference_and_noise_level, tvb, offset, length, ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_extended_diuc_dependent_ie_unknown_diuc, tvb, offset, length, ENC_NA);
break;
}
}
return ((length + 1) * 2 );
}
void proto_register_wimax_compact_dlmap_ie(void)
{
static hf_register_info hf_compact_dlmap[] =
{
{
&hf_cdlmap_dl_map_type,
{"DL-MAP Type", "wmx.compact_dlmap.dl_map_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_dl_map_type_1,
{"DL-MAP Type", "wmx.compact_dlmap.dl_map_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_ul_map_append,
{"UL-MAP Append", "wmx.compact_dlmap.ul_map_append", FT_UINT8, BASE_HEX, NULL, UL_MAP_APPEND_MASK, NULL, HFILL}
},
{
&hf_cdlmap_ul_map_append_1,
{"UL-MAP Append", "wmx.compact_dlmap.ul_map_append", FT_UINT8, BASE_HEX, NULL, UL_MAP_APPEND_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_reserved,
{"Reserved", "wmx.compact_dlmap.reserved", FT_UINT8, BASE_HEX, NULL, UL_MAP_APPEND_MASK, NULL, HFILL}
},
{
&hf_cdlmap_reserved_1,
{"Reserved", "wmx.compact_dlmap.reserved", FT_UINT8, BASE_HEX, NULL, UL_MAP_APPEND_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_nep_code,
{"Nep Code", "wmx.compact_dlmap.nep_code", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_nep_code_1,
{"Nep Code", "wmx.compact_dlmap.nep_code", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_nsch_code,
{"Nsch Code", "wmx.compact_dlmap.nsch_code", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_nsch_code_1,
{"Nsch Code", "wmx.compact_dlmap.nsch_code", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_num_bands,
{"Number Of Bands", "wmx.compact_dlmap.num_bands", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_num_bands_1,
{"Number Of Bands", "wmx.compact_dlmap.num_bands", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_band_index,
{"Band Index", "wmx.compact_dlmap.band_index", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{
&hf_cdlmap_band_index_1,
{"Band Index", "wmx.compact_dlmap.band_index", FT_BYTES, BASE_HEX, NULL, 0x0, "", HFILL}
},
#endif
{
&hf_cdlmap_nb_bitmap,
{"Number Of Bits For Band BITMAP", "wmx.compact_dlmap.nb_bitmap", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_nb_bitmap_1,
{"Number Of Bits For Band BITMAP", "wmx.compact_dlmap.nb_bitmap", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_shortened_uiuc,
{"Shortened UIUC", "wmx.compact_dlmap.shortened_uiuc", FT_UINT8, BASE_HEX, NULL, SHORTENED_DIUC_MASK, NULL, HFILL}
},
{
&hf_cdlmap_shortened_uiuc_1,
{"Shortened UIUC", "wmx.compact_dlmap.shortened_uiuc", FT_UINT16, BASE_HEX, NULL, SHORTENED_DIUC_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_shortened_diuc,
{"Shortened DIUC", "wmx.compact_dlmap.shortened_diuc", FT_UINT8, BASE_HEX, NULL, SHORTENED_DIUC_MASK, NULL, HFILL}
},
{
&hf_cdlmap_shortened_diuc_1,
{"Shortened DIUC", "wmx.compact_dlmap.shortened_diuc", FT_UINT16, BASE_HEX, NULL, SHORTENED_DIUC_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_companded_sc,
{"Companded SC", "wmx.compact_dlmap.companded_sc", FT_UINT8, BASE_HEX, NULL, COMPANDED_SC_MASK, NULL, HFILL}
},
{
&hf_cdlmap_companded_sc_1,
{"Companded SC", "wmx.compact_dlmap.companded_sc", FT_UINT16, BASE_HEX, NULL, COMPANDED_SC_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_bin_offset,
{"BIN Offset", "wmx.compact_dlmap.bin_offset", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_bin_offset_1,
{"BIN Offset", "wmx.compact_dlmap.bin_offset", FT_UINT16, BASE_HEX, NULL, 0x0FF0, NULL, HFILL}
},
{
&hf_cdlmap_diuc_num_of_subchannels,
{"Number Of Subchannels", "wmx.compact_dlmap.diuc_num_of_subchannels", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_diuc_num_of_subchannels_1,
{"Number Of Subchannels", "wmx.compact_dlmap.diuc_num_of_subchannels", FT_UINT16, BASE_DEC, NULL, 0x0FF0, NULL, HFILL}
},
{
&hf_cdlmap_diuc_repetition_coding_indication,
{"Repetition Coding Indication", "wmx.compact_dlmap.diuc_repetition_coding_indication", FT_UINT8, BASE_DEC, VALS(rep_msgs), 0xC0, NULL, HFILL}
},
{
&hf_cdlmap_diuc_repetition_coding_indication_1,
{"Repetition Coding Indication", "wmx.compact_dlmap.diuc_repetition_coding_indication", FT_UINT8, BASE_DEC, VALS(rep_msgs), 0x0C, NULL, HFILL}
},
{
&hf_cdlmap_diuc_reserved,
{"Reserved", "wmx.compact_dlmap.diuc_reserved", FT_UINT8, BASE_HEX, NULL, 0x30, NULL, HFILL}
},
{
&hf_cdlmap_diuc_reserved_1,
{"Reserved", "wmx.compact_dlmap.diuc_reserved", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL}
},
{
&hf_cdlmap_bit_map_length,
{"BIT MAP Length", "wmx.compact_dlmap.bit_map_length", FT_UINT8, BASE_DEC, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_bit_map_length_1,
{"BIT MAP Length", "wmx.compact_dlmap.bit_map_length", FT_UINT8, BASE_DEC, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_bit_map,
{"BIT MAP", "wmx.compact_dlmap.bit_map", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_diuc,
{"DIUC", "wmx.compact_dlmap.diuc", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_diuc_1,
{"DIUC", "wmx.compact_dlmap.diuc", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_allocation_mode,
{"Allocation Mode", "wmx.compact_dlmap.allocation_mode", FT_UINT8, BASE_DEC, VALS(vals_allocation_modes), 0xC0, NULL, HFILL}
},
{
&hf_cdlmap_allocation_mode_1,
{"Allocation Mode", "wmx.compact_dlmap.allocation_mode", FT_UINT8, BASE_DEC, VALS(vals_allocation_modes), 0x0C, NULL, HFILL}
},
{
&hf_cdlmap_allocation_mode_rsvd,
{"Reserved", "wmx.compact_dlmap.allocation_mode_rsvd", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL}
},
{
&hf_cdlmap_allocation_mode_rsvd_1,
{"Reserved", "wmx.compact_dlmap.allocation_mode_rsvd", FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL}
},
{
&hf_cdlmap_num_subchannels,
{"Number Of Subchannels", "wmx.compact_dlmap.num_subchannels", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_num_subchannels_1,
{"Number Of Subchannels", "wmx.compact_dlmap.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x0FF0, NULL, HFILL}
},
#if 0
{
&hf_cdlmap_reserved_type,
{"DL-MAP Reserved Type", "wmx.compact_dlmap.reserved_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK, NULL, HFILL}
},
#endif
{
&hf_cdlmap_reserved_type_1,
{"DL-MAP Reserved Type", "wmx.compact_dlmap.reserved_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_format_config[] =
{
{
&hf_format_config_ie_dl_map_type,
{"DL-MAP Type", "wmx.format_config_ie.dl_map_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_dl_map_type_1,
{"DL-MAP Type", "wmx.format_config_ie.dl_map_type", FT_UINT8, BASE_DEC, NULL, DL_MAP_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_dl_map_type_32,
{"DL-MAP Type", "wmx.format_config_ie.dl_map_type", FT_UINT32, BASE_DEC, NULL, FORMAT_CONFIG_IE_DL_MAP_TYPE_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_new_format_indication,
{"New Format Indication", "wmx.format_config_ie.new_format_indication", FT_BOOLEAN, 8, TFS(&tfs_indication), UL_MAP_APPEND_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_new_format_indication_1,
{"New Format Indication", "wmx.format_config_ie.new_format_indication", FT_BOOLEAN, 8, TFS(&tfs_indication), UL_MAP_APPEND_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_new_format_indication_32,
{"New Format Indication", "wmx.format_config_ie.new_format_indication", FT_BOOLEAN, 32, TFS(&tfs_indication), FORMAT_CONFIG_IE_NEW_FORMAT_IND_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_cid_type,
{"HARQ MAP Indicator", "wmx.harq_map.format_config_ie.indicator", FT_UINT32, BASE_HEX, VALS(vals_cid_types), CID_TYPE_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_cid_type_1,
{"CID Type", "wmx.harq_map.format_config_ie.cid_type", FT_UINT32, BASE_HEX, VALS(vals_cid_types), CID_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_safety_pattern,
{"Safety Pattern", "wmx.harq_map.format_config_ie.safety_pattern", FT_UINT32, BASE_HEX, NULL, SAFETY_PATTERN_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_safety_pattern_1,
{"Safety Pattern", "wmx.harq_map.format_config_ie.safety_pattern", FT_UINT32, BASE_HEX, NULL, SAFETY_PATTERN_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_subchannel_type,
{"Subchannel Type For Band AMC", "wmx.harq_map.format_config_ie.subchannel_type", FT_UINT32, BASE_HEX, VALS(vals_subchannel_types), BAND_AMC_SUBCHANNEL_TYPE_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_subchannel_type_1,
{"Subchannel Type For Band AMC", "wmx.harq_map.format_config_ie.subchannel_type", FT_UINT32, BASE_HEX, VALS(vals_subchannel_types), BAND_AMC_SUBCHANNEL_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_max_logical_bands,
{"Max Logical Bands", "wmx.harq_map.format_config_ie.max_logical_bands", FT_UINT32, BASE_HEX, VALS(vals_max_logical_bands), MAX_LOGICAL_BANDS_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_max_logical_bands_1,
{"Max Logical Bands", "wmx.harq_map.format_config_ie.max_logical_bands", FT_UINT32, BASE_HEX, VALS(vals_max_logical_bands), MAX_LOGICAL_BANDS_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_broadcast_symbol,
{"Number Of Symbols for Broadcast", "wmx.harq_map.format_config_ie.num_of_broadcast_symbol", FT_UINT32, BASE_HEX, NULL, NUM_BROADCAST_SYMBOLS_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_broadcast_symbol_1,
{"Number Of Symbols for Broadcast", "wmx.harq_map.num_of_broadcast_symbol", FT_UINT32, BASE_HEX, NULL, NUM_BROADCAST_SYMBOLS_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_dl_band_amc_symbol,
{"Number Of Symbols for Broadcast", "wmx.harq_map.format_config_ie.num_of_dl_band_amc_symbol", FT_UINT32, BASE_HEX, NULL, NUM_DL_AMC_SYMBOLS_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_dl_band_amc_symbol_1,
{"Number Of Symbols for Broadcast", "wmx.harq_map.num_of_dl_band_amc_symbol", FT_UINT32, BASE_HEX, NULL, NUM_DL_AMC_SYMBOLS_MASK_1, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_ul_band_amc_symbol,
{"Number Of Symbols for Broadcast", "wmx.harq_map.format_config_ie.num_of_ul_band_amc_symbol", FT_UINT32, BASE_HEX, NULL, NUM_UL_AMC_SYMBOLS_MASK, NULL, HFILL}
},
{
&hf_format_config_ie_num_of_ul_band_amc_symbol_1,
{"Number Of Symbols for Broadcast", "wmx.harq_map.num_of_ul_band_amc_symbol", FT_UINT32, BASE_HEX, NULL, NUM_UL_AMC_SYMBOLS_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_rcid[] =
{
{
&hf_harq_rcid_ie_normal_cid,
{"Normal CID", "wmx.harq_map.rcid_ie.normal_cid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{
&hf_harq_rcid_ie_normal_cid_1,
{"Normal CID", "wmx.harq_map.rcid_ie.normal_cid", FT_UINT24, BASE_HEX, NULL, WIMAX_RCID_IE_NORMAL_CID_MASK_1, NULL, HFILL}
},
{
&hf_harq_rcid_ie_prefix,
{"Prefix", "wmx.harq_map.rcid_ie.prefix", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_PREFIX_MASK, NULL, HFILL}
},
{
&hf_harq_rcid_ie_prefix_1,
{"Prefix", "wmx.harq_map.rcid_ie.prefix", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_PREFIX_MASK_1, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid3,
{"3 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid3", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID3_MASK, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid3_1,
{"3 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid3", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID3_MASK_1, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid7,
{"7 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid7", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID7_MASK, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid7_1,
{"7 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid7", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID7_MASK_1, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid11,
{"11 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid11_1,
{"11 LSB Of Basic CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK_1, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid11_2,
{"11 LSB Of Multicast, AAS or Broadcast CID", "wmx.harq_map.rcid_ie.cid11", FT_UINT16, BASE_HEX, NULL, WIMAX_RCID_IE_CID11_MASK, NULL, HFILL}
},
{
&hf_harq_rcid_ie_cid11_3,
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
static hf_register_info hf_cqich_control[] =
{
{
&hf_cqich_control_ie_indicator,
{"CQICH Indicator", "wmx.harq_map.cqich_control_ie.cqich_indicator", FT_BOOLEAN, 16, TFS(&tfs_cqich_ind), WIMAX_CQICH_CONTROL_IE_INDICATOR_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_alloc_id,
{"Allocation Index", "wmx.harq_map.cqich_control_ie.alloc_id", FT_UINT16, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_ALLOCATION_INDEX_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_period,
{"PERIOD", "wmx.harq_map.cqich_control_ie.period", FT_UINT16, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_PERIOD_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_frame_offset,
{"Frame Offset", "wmx.harq_map.cqich_control_ie.frame_offset", FT_UINT16, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_FRAME_OFFSET_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_duration,
{"Duration", "wmx.harq_map.cqich_control_ie.duration", FT_UINT16, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_DURATION_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_cqi_rep_threshold,
{"CQI Reporting Threshold", "wmx.harq_map.cqich_control_ie.cqi_rep_threshold", FT_UINT16, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_CQI_REP_THRESHOLD_MASK, NULL, HFILL}
},
{
&hf_cqich_control_ie_indicator_1,
{"CQICH Indicator", "wmx.harq_map.cqich_control_ie.cqich_indicator", FT_BOOLEAN, 24, TFS(&tfs_cqich_ind), WIMAX_CQICH_CONTROL_IE_INDICATOR_MASK_1, NULL, HFILL}
},
{
&hf_cqich_control_ie_alloc_id_1,
{"Allocation Index", "wmx.harq_map.cqich_control_ie.alloc_id", FT_UINT24, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_ALLOCATION_INDEX_MASK_1, NULL, HFILL}
},
{
&hf_cqich_control_ie_period_1,
{"PERIOD", "wmx.harq_map.cqich_control_ie.period", FT_UINT24, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_PERIOD_MASK_1, NULL, HFILL}
},
{
&hf_cqich_control_ie_frame_offset_1,
{"Frame Offset", "wmx.harq_map.cqich_control_ie.frame_offset", FT_UINT24, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_FRAME_OFFSET_MASK_1, NULL, HFILL}
},
{
&hf_cqich_control_ie_duration_1,
{"Duration", "wmx.harq_map.cqich_control_ie.duration", FT_UINT24, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_DURATION_MASK_1, NULL, HFILL}
},
{
&hf_cqich_control_ie_cqi_rep_threshold_1,
{"CQI Reporting Threshold", "wmx.harq_map.cqich_control_ie.cqi_rep_threshold", FT_UINT24, BASE_HEX, NULL, WIMAX_CQICH_CONTROL_IE_CQI_REP_THRESHOLD_MASK_1, NULL, HFILL}
}
};
static hf_register_info hf_extension_type[] =
{
{
&hf_cdlmap_extension_type,
{"DL-MAP Type", "wmx.extension_type.dl_map_type", FT_UINT16, BASE_DEC, NULL, EXTENSION_TYPE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_extension_type_1,
{"DL-MAP Type", "wmx.extension_type.dl_map_type", FT_UINT16, BASE_DEC, NULL, EXTENSION_TYPE_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_extension_subtype,
{"Extension Subtype", "wmx.extension_type.subtype", FT_UINT16, BASE_DEC, NULL, EXTENSION_SUBTYPE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_extension_subtype_1,
{"Extension Subtype", "wmx.extension_type.subtype", FT_UINT16, BASE_DEC, NULL, EXTENSION_SUBTYPE_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_extension_length,
{"Extension Length", "wmx.extension_type.length", FT_UINT16, BASE_DEC, NULL, EXTENSION_LENGTH_MASK, NULL, HFILL}
},
{
&hf_cdlmap_extension_length_1,
{"Extension Length", "wmx.extension_type.length", FT_UINT16, BASE_DEC, NULL, EXTENSION_LENGTH_MASK_1, NULL, HFILL}
},
{
&hf_cdlmap_extension_time_diversity_mbs,
{"Time Diversity MBS", "wmx.extension_type.time_diversity_mbs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_extension_time_diversity_mbs_1,
{"Time Diversity MBS", "wmx.extension_type.time_diversity_mbs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_extension_harq_mode_1,
{"HARQ Mode Switch", "wmx.extension_type.harq_mode", FT_UINT16, BASE_HEX, NULL, 0x000F, NULL, HFILL}
},
{
&hf_cdlmap_extension_harq_mode,
{"HARQ Mode Switch", "wmx.extension_type.harq_mode", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL}
},
{
&hf_cdlmap_extension_unknown_sub_type,
{"Unknown Extension Subtype", "wmx.extension_type.unknown_sub_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{
&hf_cdlmap_extension_unknown_sub_type_1,
{"Unknown Extension Subtype", "wmx.extension_type.unknown_sub_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static hf_register_info hf_extended_diuc[] =
{
{
&hf_extended_diuc_dependent_ie_diuc,
{"Extended DIUC", "wmx.extended_diuc_dependent_ie.diuc", FT_UINT8, BASE_HEX, NULL, MSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_diuc_1,
{"Extended DIUC", "wmx.extended_diuc_dependent_ie.diuc", FT_UINT8, BASE_HEX, NULL, LSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_length,
{"Length", "wmx.extended_diuc_dependent_ie.length", FT_UINT8, BASE_DEC, NULL, MSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_length_1,
{"Length", "wmx.extended_diuc_dependent_ie.length", FT_UINT8, BASE_DEC, NULL, LSB_NIBBLE_MASK, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_channel_measurement,
{"Channel_Measurement_IE (not implemented)", "wmx.extended_diuc_dependent_ie.channel_measurement", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_stc_zone,
{"STC_Zone_IE (not implemented)", "wmx.extended_diuc_dependent_ie.stc_zone", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_aas_dl,
{"AAS_DL_IE (not implemented)", "wmx.extended_diuc_dependent_ie.aas_dl", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_data_location,
{"Data_location_in_another_BS_IE (not implemented)", "wmx.extended_diuc_dependent_ie.data_location", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_cid_switch,
{"CID_Switch_IE (not implemented)", "wmx.extended_diuc_dependent_ie.cid_switch", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_mimo_dl_basic,
{"MIMO_DL_Basic_IE (not implemented)", "wmx.extended_diuc_dependent_ie.mimo_dl_basic", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_mimo_dl_enhanced,
{"MIMO_DL_Enhanced_IE (not implemented)", "wmx.extended_diuc_dependent_ie.mimo_dl_enhanced", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_harq_map_pointer,
{"HARQ_Map_Pointer_IE (not implemented)", "wmx.extended_diuc_dependent_ie.harq_map_pointer", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_phymod_dl,
{"PHYMOD_DL_IE (not implemented)", "wmx.extended_diuc_dependent_ie.phymod_dl", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_dl_pusc_burst_allocation,
{"DL_PUSC_Burst_Allocation_in_Other_Segment_IE (not implemented)", "wmx.extended_diuc_dependent_ie.dl_pusc_burst_allocation", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_ul_interference_and_noise_level,
{"UL_interference_and_noise_level_IE (not implemented)", "wmx.extended_diuc_dependent_ie.ul_interference_and_noise_level", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{
&hf_extended_diuc_dependent_ie_unknown_diuc,
{"Unknown Extended DIUC", "wmx.extended_diuc_dependent_ie.unknown_diuc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
}
};
#if 0
static gint *ett[] =
{
&ett_wimax_compact_dlmap_ie_decoder,
&ett_wimax_format_configuration_ie_decoder,
&ett_wimax_rcid_ie_decoder,
&ett_wimax_harq_control_ie_decoder,
&ett_wimax_extended_diuc_dependent_ie_decoder,
&ett_wimax_cqich_control_ie_decoder,
&ett_wimax_extension_type_ie_decoder,
};
proto_register_subtree_array(ett, array_length(ett));
#endif
proto_wimax_compact_dlmap_ie_decoder = proto_wimax;
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_compact_dlmap, array_length(hf_compact_dlmap));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_format_config, array_length(hf_format_config));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_rcid, array_length(hf_rcid));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_harq_control, array_length(hf_harq_control));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_cqich_control, array_length(hf_cqich_control));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_extension_type, array_length(hf_extension_type));
proto_register_field_array(proto_wimax_compact_dlmap_ie_decoder, hf_extended_diuc, array_length(hf_extended_diuc));
}
