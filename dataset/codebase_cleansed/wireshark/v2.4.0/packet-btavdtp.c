static const char *
get_sep_type(guint32 interface_id,
guint32 adapter_id, guint32 chandle, guint32 direction, guint32 seid, guint32 frame_number)
{
wmem_tree_key_t key[6];
wmem_tree_t *subtree;
sep_entry_t *sep;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_list, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep) {
return val_to_str_const(sep->type, sep_type_vals, "unknown");
}
return "unknown";
}
static const char *
get_sep_media_type(guint32 interface_id,
guint32 adapter_id, guint32 chandle, guint32 direction, guint32 seid, guint32 frame_number)
{
wmem_tree_key_t key[6];
wmem_tree_t *subtree;
sep_entry_t *sep;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_list, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep) {
return val_to_str_const(sep->media_type, media_type_vals, "unknown");
}
return "unknown";
}
static gint
dissect_sep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
guint32 interface_id, guint32 adapter_id, guint32 chandle)
{
proto_tree *sep_tree;
proto_item *sep_item;
guint i_sep = 1;
guint media_type;
guint type;
guint seid;
guint in_use;
guint items;
guint32 direction;
direction = (pinfo->p2p_dir == P2P_DIR_SENT) ? P2P_DIR_RECV : P2P_DIR_SENT;
items = tvb_reported_length_remaining(tvb, offset) / 2;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
seid = tvb_get_guint8(tvb, offset);
in_use = seid & 0x02;
seid = seid >> 2;
media_type = tvb_get_guint8(tvb, offset + 1) >> 4;
type = (tvb_get_guint8(tvb, offset + 1) & 0x08) >> 3;
sep_item = proto_tree_add_none_format(tree, hf_btavdtp_acp_sep, tvb, offset, 2, "ACP SEP [%u - %s %s] item %u/%u",
seid, val_to_str_const(media_type, media_type_vals, "unknown"),
val_to_str_const(type, sep_type_vals, "unknown"), i_sep, items);
sep_tree = proto_item_add_subtree(sep_item, ett_btavdtp_sep);
proto_tree_add_item(sep_tree, hf_btavdtp_sep_seid , tvb, offset, 1, ENC_NA);
proto_tree_add_item(sep_tree, hf_btavdtp_sep_inuse, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sep_tree, hf_btavdtp_sep_rfa0 , tvb, offset, 1, ENC_NA);
offset+=1;
proto_tree_add_item(sep_tree, hf_btavdtp_sep_media_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(sep_tree, hf_btavdtp_sep_type , tvb, offset, 1, ENC_NA);
proto_tree_add_item(sep_tree, hf_btavdtp_sep_rfa1 , tvb, offset, 1, ENC_NA);
if (!pinfo->fd->flags.visited) {
sep_entry_t *sep_data;
wmem_tree_key_t key[7];
guint32 frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
sep_data = wmem_new(wmem_file_scope(), sep_entry_t);
sep_data->seid = seid;
sep_data->type = type;
sep_data->media_type = media_type;
sep_data->int_seid = 0;
sep_data->codec = -1;
sep_data->content_protection_type = 0;
if (in_use) {
sep_data->state = SEP_STATE_IN_USE;
} else {
sep_data->state = SEP_STATE_FREE;
}
wmem_tree_insert32_array(sep_list, key, sep_data);
}
offset += 1;
i_sep += 1;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " - items: %u", items);
return offset;
}
static gint
dissect_codec(tvbuff_t *tvb, packet_info *pinfo, proto_item *service_item, proto_tree *tree, gint offset,
guint losc, gint media_type, gint media_codec_type, guint32 *vendor_id, guint16 *vendor_codec)
{
proto_item *pitem;
guint32 value;
guint8 *value8 = (guint8 *) &value;
switch(media_type) {
case MEDIA_TYPE_AUDIO:
switch(media_codec_type) {
case CODEC_SBC:
proto_tree_add_item(tree, hf_btavdtp_sbc_sampling_frequency_16000, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_sampling_frequency_32000, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_sampling_frequency_44100, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_sampling_frequency_48000, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_channel_mode_mono, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_channel_mode_dual_channel, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_channel_mode_stereo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_channel_mode_joint_stereo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_block_4, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_block_8, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_block_12, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_block_16, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_subbands_4, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_subbands_8, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_allocation_method_snr, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_sbc_allocation_method_loudness, tvb, offset + 1, 1, ENC_NA);
pitem = proto_tree_add_item(tree, hf_btavdtp_sbc_min_bitpool, tvb, offset + 2, 1, ENC_NA);
value = tvb_get_guint8(tvb, offset + 2);
if (value < 2 || value > 250) {
expert_add_info(pinfo, pitem, &ei_btavdtp_sbc_min_bitpool_out_of_range);
}
pitem = proto_tree_add_item(tree, hf_btavdtp_sbc_max_bitpool, tvb, offset + 3, 1, ENC_NA);
value = tvb_get_guint8(tvb, offset + 3);
if (value < 2 || value > 250) {
expert_add_info(pinfo, pitem, &ei_btavdtp_sbc_max_bitpool_out_of_range);
}
value = tvb_get_h_guint32(tvb, offset);
if (value) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s%s%s%s%s| %s%s%s%s%s| block: %s%s%s%s%s| subbands: %s%s%s| allocation: %s%s%s| bitpool: %u..%u)",
(value8[0] & 0x80) ? "16000 " : "",
(value8[0] & 0x40) ? "32000 " : "",
(value8[0] & 0x20) ? "44100 " : "",
(value8[0] & 0x10) ? "48000 " : "",
(value8[0] & 0xF0) ? "" : "not set ",
(value8[0] & 0x08) ? "Mono " : "",
(value8[0] & 0x04) ? "DualChannel " : "",
(value8[0] & 0x02) ? "Stereo " : "",
(value8[0] & 0x01) ? "JointStereo " : "",
(value8[0] & 0x0F) ? "" : "not set ",
(value8[1] & 0x80) ? "4 " : "",
(value8[1] & 0x40) ? "8 " : "",
(value8[1] & 0x20) ? "12 " : "",
(value8[1] & 0x10) ? "16 " : "",
(value8[1] & 0xF0) ? "" : "not set ",
(value8[1] & 0x08) ? "4 " : "",
(value8[1] & 0x04) ? "8 " : "",
(value8[1] & 0x0C) ? "" : "not set ",
(value8[1] & 0x02) ? "SNR " : "",
(value8[1] & 0x01) ? "Loudness " : "",
(value8[0] & 0x03) ? "" : "not set ",
value8[2],
value8[3]);
proto_item_append_text(service_item, " (%s%s%s%s%s| %s%s%s%s%s| block: %s%s%s%s%s| subbands: %s%s%s| allocation: %s%s%s| bitpool: %u..%u)",
(value8[0] & 0x80) ? "16000 " : "",
(value8[0] & 0x40) ? "32000 " : "",
(value8[0] & 0x20) ? "44100 " : "",
(value8[0] & 0x10) ? "48000 " : "",
(value8[0] & 0xF0) ? "" : "not set ",
(value8[0] & 0x08) ? "Mono " : "",
(value8[0] & 0x04) ? "DualChannel " : "",
(value8[0] & 0x02) ? "Stereo " : "",
(value8[0] & 0x01) ? "JointStereo " : "",
(value8[0] & 0x0F) ? "" : "not set ",
(value8[1] & 0x80) ? "4 " : "",
(value8[1] & 0x40) ? "8 " : "",
(value8[1] & 0x20) ? "12 " : "",
(value8[1] & 0x10) ? "16 " : "",
(value8[1] & 0xF0) ? "" : "not set ",
(value8[1] & 0x08) ? "4 " : "",
(value8[1] & 0x04) ? "8 " : "",
(value8[1] & 0x0C) ? "" : "not set ",
(value8[1] & 0x02) ? "SNR " : "",
(value8[1] & 0x01) ? "Loudness " : "",
(value8[0] & 0x03) ? "" : "not set ",
value8[2],
value8[3]);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (none)");
proto_item_append_text(service_item, " (none)");
}
break;
case CODEC_MPEG12_AUDIO:
proto_tree_add_item(tree, hf_btavdtp_mpeg12_layer_1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_layer_2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_layer_3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_crc_protection, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_channel_mode_mono, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_channel_mode_dual_channel, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_channel_mode_stereo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_channel_mode_joint_stereo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_rfa, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_mpf_2, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_16000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_22050, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_24000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_32000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_44100, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_sampling_frequency_48000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_vbr_supported, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_mpeg12_bit_rate, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
break;
case CODEC_MPEG24_AAC:
proto_tree_add_item(tree, hf_btavdtp_mpeg24_object_type_mpeg2_aac_lc, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_object_type_mpeg4_aac_lc, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_object_type_mpeg4_aac_ltp, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_object_type_mpeg4_aac_scalable, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_object_type_rfa, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_8000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_11025, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_12000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_16000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_22050, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_24000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_32000, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_44100, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_48000, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_64000, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_88200, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_sampling_frequency_96000, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_channels_1, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_channels_2, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_rfa, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_vbr_supported, tvb, offset + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_mpeg24_bit_rate, tvb, offset + 3, 3, ENC_BIG_ENDIAN);
break;
case CODEC_ATRAC:
proto_tree_add_item(tree, hf_btavdtp_atrac_version, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_atrac_channel_mode_single_channel, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_atrac_channel_mode_dual_channel, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_atrac_channel_mode_joint_stereo, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_atrac_rfa1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_atrac_rfa2, tvb, offset + 1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_sampling_frequency_44100, tvb, offset + 1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_sampling_frequency_48000, tvb, offset + 1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_vbr_supported, tvb, offset + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_bit_rate, tvb, offset + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_maximum_sul, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_atrac_rfa3, tvb, offset + 6, 1, ENC_NA);
break;
case CODEC_VENDOR:
proto_tree_add_item(tree, hf_btavdtp_vendor_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if (vendor_id)
*vendor_id = tvb_get_letohl(tvb, offset);
if (vendor_codec)
*vendor_codec = tvb_get_letohs(tvb, offset + 4);
switch (tvb_get_letohl(tvb, offset)) {
case 0x004F:
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_apt_codec_id, tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
value = tvb_get_letohs(tvb, offset + 4);
if (value == 0x0001) {
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_sampling_frequency_16000, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_sampling_frequency_32000, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_sampling_frequency_44100, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_sampling_frequency_48000, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_channel_mode_mono, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_channel_mode_dual_channel, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_channel_mode_stereo, tvb, offset + 6, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_aptx_channel_mode_joint_stereo, tvb, offset + 6, 1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s -",
val_to_str_const(value, vendor_apt_codec_vals, "unknown codec"));
proto_item_append_text(service_item, " (%s -",
val_to_str_const(value, vendor_apt_codec_vals, "unknown codec"));
value = tvb_get_guint8(tvb, offset + 6);
if (value) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s%s%s%s%s,%s%s%s%s%s)",
(value & 0x80) ? " 16000" : "",
(value & 0x40) ? " 32000" : "",
(value & 0x20) ? " 44100" : "",
(value & 0x10) ? " 48000" : "",
(value & 0xF0) ? "" : "not set ",
(value & 0x08) ? " Mono" : "",
(value & 0x04) ? " DualChannel" : "",
(value & 0x02) ? " Stereo" : "",
(value & 0x01) ? " JointStereo" : "",
(value & 0x0F) ? "" : "not set ");
proto_item_append_text(service_item, "%s%s%s%s%s,%s%s%s%s%s)",
(value & 0x80) ? " 16000" : "",
(value & 0x40) ? " 32000" : "",
(value & 0x20) ? " 44100" : "",
(value & 0x10) ? " 48000" : "",
(value & 0xF0) ? "" : "not set ",
(value & 0x08) ? " Mono" : "",
(value & 0x04) ? " DualChannel" : "",
(value & 0x02) ? " Stereo" : "",
(value & 0x01) ? " JointStereo" : "",
(value & 0x0F) ? "" : "not set ");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " none)");
proto_item_append_text(service_item, " none)");
}
} else {
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_value, tvb, offset + 6, losc - 6, ENC_NA);
}
break;
default:
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_codec_id, tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_value, tvb, offset + 6, losc - 6, ENC_NA);
}
break;
default:
proto_tree_add_item(tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
}
break;
case MEDIA_TYPE_VIDEO:
switch(media_codec_type) {
case CODEC_H263_BASELINE:
case CODEC_H263_PROFILE_3:
case CODEC_H263_PROFILE_8:
proto_tree_add_item(tree, hf_btavdtp_h263_level_10, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_h263_level_20, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_h263_level_30, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_h263_level_rfa, tvb, offset, 1, ENC_NA);
break;
case CODEC_MPEG4_VSP:
proto_tree_add_item(tree, hf_btavdtp_mpeg4_level_0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg4_level_1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg4_level_2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg4_level_3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_btavdtp_mpeg4_level_rfa, tvb, offset, 1, ENC_NA);
break;
case CODEC_VENDOR:
proto_tree_add_item(tree, hf_btavdtp_vendor_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_codec_id, tvb, offset + 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_btavdtp_vendor_specific_value, tvb, offset + 6, losc - 6, ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
}
break;
default:
proto_tree_add_item(tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
}
offset += losc;
return offset;
}
static gint
dissect_capabilities(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, gint offset, gint *codec,
gint *content_protection_type, guint32 *vendor_id,
guint16 *vendor_codec, guint32 *configuration_offset,
guint8 *configuration_length)
{
proto_item *pitem = NULL;
proto_item *ptree = NULL;
proto_tree *capabilities_tree;
proto_item *capabilities_item;
proto_tree *service_tree = NULL;
proto_item *service_item = NULL;
gint service_category = 0;
gint losc = 0;
gint recovery_type = 0;
gint maximum_recovery_window_size = 0;
gint maximum_number_of_media_packet_in_parity_code = 0;
gint media_type = 0;
gint media_codec_type = 0;
capabilities_item = proto_tree_add_item(tree, hf_btavdtp_capabilities, tvb, offset, tvb_reported_length(tvb) - offset, ENC_NA);
capabilities_tree = proto_item_add_subtree(capabilities_item, ett_btavdtp_capabilities);
if (codec)
*codec = -1;
if (vendor_id)
*vendor_id = 0x003F;
if (vendor_codec)
*vendor_codec = 0;
if (configuration_length)
*configuration_length = 0;
if (configuration_offset)
*configuration_offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
service_category = tvb_get_guint8(tvb, offset);
losc = tvb_get_guint8(tvb, offset + 1);
service_item = proto_tree_add_none_format(capabilities_tree, hf_btavdtp_service, tvb, offset, 2 + losc, "Service: %s", val_to_str_const(service_category, service_category_vals, "RFD"));
service_tree = proto_item_add_subtree(service_item, ett_btavdtp_service);
proto_tree_add_item(service_tree, hf_btavdtp_service_category, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(service_tree, hf_btavdtp_length_of_service_category, tvb, offset, 1, ENC_NA);
offset += 1;
switch (service_category) {
case SERVICE_CATEGORY_MEDIA_TRANSPORT:
case SERVICE_CATEGORY_REPORTING:
case SERVICE_CATEGORY_DELAY_REPORTING:
break;
case SERVICE_CATEGORY_RECOVERY:
recovery_type = tvb_get_guint8(tvb, offset);
pitem = proto_tree_add_item(service_tree, hf_btavdtp_recovery_type, tvb, offset, 1, ENC_NA);
proto_item_append_text(pitem, " (%s)", val_to_str_const(recovery_type, recovery_type_vals, "RFD"));
offset += 1;
losc -= 1;
maximum_recovery_window_size = tvb_get_guint8(tvb, offset);
pitem = proto_tree_add_item(service_tree, hf_btavdtp_maximum_recovery_window_size, tvb, offset, 1, ENC_NA);
if (maximum_recovery_window_size == 0x00) {
proto_item_append_text(pitem, " (Forbidden)");
} else if (maximum_recovery_window_size >= 0x18) {
proto_item_append_text(pitem, " (Undocumented)");
}
offset += 1;
losc -= 1;
maximum_number_of_media_packet_in_parity_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item(service_tree, hf_btavdtp_maximum_number_of_media_packet_in_parity_code, tvb, offset, 1, ENC_NA);
pitem = proto_tree_add_item(service_tree, hf_btavdtp_maximum_recovery_window_size, tvb, offset, 1, ENC_NA);
if (maximum_number_of_media_packet_in_parity_code == 0x00) {
proto_item_append_text(pitem, " (Forbidden)");
} else if (maximum_number_of_media_packet_in_parity_code >= 0x18) {
proto_item_append_text(pitem, " (Undocumented)");
}
offset += 1;
losc -= 1;
break;
case SERVICE_CATEGORY_MEDIA_CODEC:
if (configuration_length)
*configuration_length = losc;
if (configuration_offset)
*configuration_offset = offset;
media_type = tvb_get_guint8(tvb, offset) >> 4;
proto_tree_add_item(service_tree, hf_btavdtp_media_codec_media_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(service_tree, hf_btavdtp_media_codec_rfa , tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
media_codec_type = tvb_get_guint8(tvb, offset);
if (codec) {
*codec = media_codec_type;
}
if (media_type == MEDIA_TYPE_AUDIO) {
proto_tree_add_item(service_tree, hf_btavdtp_media_codec_audio_type, tvb, offset, 1, ENC_NA);
proto_item_append_text(service_item, " - Audio %s",
val_to_str_const(media_codec_type, media_codec_audio_type_vals, "unknown codec"));
col_append_fstr(pinfo->cinfo, COL_INFO, " - Audio %s",
val_to_str_const(media_codec_type, media_codec_audio_type_vals, "unknown codec"));
} else if (media_type == MEDIA_TYPE_VIDEO) {
proto_tree_add_item(service_tree, hf_btavdtp_media_codec_video_type, tvb, offset, 1, ENC_NA);
proto_item_append_text(service_item, " - Video %s",
val_to_str_const(media_codec_type, media_codec_video_type_vals, "unknown codec"));
col_append_fstr(pinfo->cinfo, COL_INFO, " - Video %s",
val_to_str_const(media_codec_type, media_codec_video_type_vals, "unknown codec"));
} else {
proto_tree_add_item(service_tree, hf_btavdtp_media_codec_unknown_type, tvb, offset, 1, ENC_NA);
proto_item_append_text(service_item, " - Unknown 0x%02x", media_codec_type);
col_append_fstr(pinfo->cinfo, COL_INFO, " - Unknown 0x%02x", media_codec_type);
}
offset += 1;
losc -= 1;
offset = dissect_codec(tvb, pinfo, service_item, service_tree,
offset, losc, media_type, media_codec_type,
vendor_id, vendor_codec);
losc = 0;
break;
case SERVICE_CATEGORY_CONTENT_PROTECTION:
proto_tree_add_item(service_tree, hf_btavdtp_content_protection_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (content_protection_type) {
*content_protection_type = tvb_get_letohs(tvb, offset);
}
proto_item_append_text(service_item, " - %s",
val_to_str_const(tvb_get_letohs(tvb, offset), content_protection_type_vals, "unknown"));
offset += 2;
losc -= 2;
if (losc > 0) {
proto_tree_add_item(service_tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
offset += losc;
losc = 0;
}
break;
case SERVICE_CATEGORY_HEADER_COMPRESSION:
proto_tree_add_item(service_tree, hf_btavdtp_header_compression_backch, tvb, offset, 1, ENC_NA);
proto_tree_add_item(service_tree, hf_btavdtp_header_compression_media, tvb, offset, 1, ENC_NA);
proto_tree_add_item(service_tree, hf_btavdtp_header_compression_recovery, tvb, offset, 1, ENC_NA);
proto_tree_add_item(service_tree, hf_btavdtp_header_compression_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
break;
case SERVICE_CATEGORY_MULTIPLEXING:
proto_tree_add_item(service_tree, hf_btavdtp_multiplexing_fragmentation, tvb, offset, 1, ENC_NA);
proto_tree_add_item(service_tree, hf_btavdtp_multiplexing_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
if (losc >= 2) {
pitem = proto_tree_add_none_format(service_tree, hf_btavdtp_service_multiplexing_entry, tvb, offset, 1 + losc, "Entry: Media Transport Session");
ptree = proto_item_add_subtree(pitem, ett_btavdtp_service);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tsid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tcid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
}
if (losc >= 2) {
pitem = proto_tree_add_none_format(service_tree, hf_btavdtp_service_multiplexing_entry, tvb, offset, 1 + losc, "Entry: Reporting Transport Session");
ptree = proto_item_add_subtree(pitem, ett_btavdtp_service);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tsid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tcid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
}
if (losc >= 2) {
pitem = proto_tree_add_none_format(service_tree, hf_btavdtp_service_multiplexing_entry, tvb, offset, 1 + losc, "Entry: Recovery Transport Session");
ptree = proto_item_add_subtree(pitem, ett_btavdtp_service);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tsid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_tcid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ptree, hf_btavdtp_multiplexing_entry_rfa, tvb, offset, 1, ENC_NA);
offset += 1;
losc -= 1;
}
break;
default:
proto_tree_add_item(service_tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
offset += losc;
losc = 0;
}
if (losc > 0) {
pitem = proto_tree_add_item(service_tree, hf_btavdtp_data, tvb, offset, losc, ENC_NA);
offset += losc;
expert_add_info(pinfo, pitem, &ei_btavdtp_unexpected_losc_data);
}
}
return offset;
}
static gint
dissect_seid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset,
gint seid_side, gint i_item, guint32 *sep_seid,
guint32 interface_id, guint32 adapter_id, guint32 chandle,
guint32 frame_number)
{
guint32 seid;
proto_tree *seid_tree = NULL;
proto_item *seid_item = NULL;
guint32 direction;
seid = tvb_get_guint8(tvb, offset) >> 2;
if (sep_seid) {
*sep_seid = seid;
}
if (seid_side == SEID_ACP) {
direction = pinfo->p2p_dir;
seid_item = proto_tree_add_none_format(tree, hf_btavdtp_acp_seid_item, tvb, offset, 1,
"ACP SEID [%u - %s %s]", seid,
get_sep_media_type(interface_id, adapter_id, chandle, direction, seid, frame_number),
get_sep_type(interface_id, adapter_id, chandle, direction, seid, frame_number));
seid_tree = proto_item_add_subtree(seid_item, ett_btavdtp_sep);
proto_tree_add_item(seid_tree, hf_btavdtp_acp_seid, tvb, offset, 1, ENC_NA);
if (i_item > 0) proto_item_append_text(seid_item, " item %u", i_item);
col_append_fstr(pinfo->cinfo, COL_INFO, " - ACP SEID [%u - %s %s]",
seid, get_sep_media_type(interface_id, adapter_id, chandle, direction, seid, frame_number),
get_sep_type(interface_id, adapter_id, chandle, direction, seid, frame_number));
} else {
direction = (pinfo->p2p_dir == P2P_DIR_SENT) ? P2P_DIR_RECV : P2P_DIR_SENT;
seid_item = proto_tree_add_none_format(tree, hf_btavdtp_int_seid_item, tvb, offset, 1,
"INT SEID [%u - %s %s]", seid,
get_sep_media_type(interface_id, adapter_id, chandle, direction, seid, frame_number),
get_sep_type(interface_id, adapter_id, chandle, direction, seid, frame_number));
seid_tree = proto_item_add_subtree(seid_item, ett_btavdtp_sep);
proto_tree_add_item(seid_tree, hf_btavdtp_int_seid, tvb, offset, 1, ENC_NA);
if (i_item > 0) proto_item_append_text(seid_item, " item %u", i_item);
col_append_fstr(pinfo->cinfo, COL_INFO, " - INT SEID [%u - %s %s]",
seid, get_sep_media_type(interface_id, adapter_id, chandle, direction, seid, frame_number),
get_sep_type(interface_id, adapter_id, chandle, direction, seid, frame_number));
}
proto_tree_add_item(seid_tree, hf_btavdtp_rfa_seid, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static gint
dissect_btavdtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *btavdtp_tree = NULL;
proto_tree *signal_tree = NULL;
proto_item *signal_item = NULL;
btl2cap_data_t *l2cap_data;
gint offset = 0;
gint i_sep = 1;
gint packet_type = 0;
gint message_type = 0;
gint signal_id = 0;
guint delay;
wmem_tree_t *subtree;
wmem_tree_key_t key[8];
channels_info_t *channels_info;
guint32 interface_id;
guint32 adapter_id;
guint32 chandle;
guint32 psm;
guint32 direction;
guint32 cid;
guint32 frame_number;
sep_entry_t *sep;
tvbuff_t *next_tvb;
guint32 seid;
gint codec = -1;
gint content_protection_type = 0;
guint32 configuration_offset;
guint8 configuration_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AVDTP");
direction = pinfo->p2p_dir;
switch (direction) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection ");
goto LABEL_data;
}
l2cap_data = (btl2cap_data_t *) data;
DISSECTOR_ASSERT(l2cap_data);
interface_id = l2cap_data->interface_id;
adapter_id = l2cap_data->adapter_id;
chandle = l2cap_data->chandle;
psm = l2cap_data->psm;
cid = l2cap_data->cid;
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &psm;
key[4].length = 0;
key[4].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(channels, key);
channels_info = (subtree) ? (channels_info_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (!(channels_info &&
((*channels_info->adapter_disconnect_in_frame >= pinfo->num &&
*channels_info->hci_disconnect_in_frame >= pinfo->num &&
*channels_info->l2cap_disconnect_in_frame >= pinfo->num &&
channels_info->disconnect_in_frame >= pinfo->num) ||
(*channels_info->adapter_disconnect_in_frame == 0 ||
*channels_info->hci_disconnect_in_frame == 0 ||
*channels_info->l2cap_disconnect_in_frame == 0 ||
channels_info->disconnect_in_frame == 0)))) {
channels_info = (channels_info_t *) wmem_new (wmem_file_scope(), channels_info_t);
channels_info->control_local_cid = l2cap_data->local_cid;
channels_info->control_remote_cid = l2cap_data->remote_cid;
channels_info->media_local_cid = BTL2CAP_UNKNOWN_CID;
channels_info->media_remote_cid = BTL2CAP_UNKNOWN_CID;
channels_info->disconnect_in_frame = max_disconnect_in_frame;
channels_info->l2cap_disconnect_in_frame = l2cap_data->disconnect_in_frame;
channels_info->hci_disconnect_in_frame = l2cap_data->hci_disconnect_in_frame;
channels_info->adapter_disconnect_in_frame = l2cap_data->adapter_disconnect_in_frame;
channels_info->sep = NULL;
if (!pinfo->fd->flags.visited || (
*channels_info->adapter_disconnect_in_frame == 0 ||
*channels_info->hci_disconnect_in_frame == 0 ||
*channels_info->l2cap_disconnect_in_frame == 0 ||
channels_info->disconnect_in_frame == 0)) {
key[4].length = 1;
key[4].key = &frame_number;
key[5].length = 0;
key[5].key = NULL;
channels_info->stream_numbers = wmem_tree_new(wmem_file_scope());
if (*channels_info->adapter_disconnect_in_frame > 0 &&
*channels_info->hci_disconnect_in_frame > 0 &&
*channels_info->l2cap_disconnect_in_frame > 0 &&
channels_info->disconnect_in_frame > 0) {
wmem_tree_insert32_array(channels, key, channels_info);
}
} else {
channels_info->stream_numbers = NULL;
}
}
if (!(l2cap_data->local_cid == channels_info->control_local_cid &&
l2cap_data->remote_cid == channels_info->control_remote_cid) &&
(channels_info->media_local_cid == BTL2CAP_UNKNOWN_CID ||
(l2cap_data->local_cid == channels_info->media_local_cid &&
l2cap_data->remote_cid == channels_info->media_remote_cid))) {
if (!pinfo->fd->flags.visited && channels_info->media_local_cid == BTL2CAP_UNKNOWN_CID) {
channels_info->media_local_cid = l2cap_data->local_cid;
channels_info->media_remote_cid = l2cap_data->remote_cid;
}
if (!channels_info->sep) {
ti = proto_tree_add_item(tree, proto_btavdtp, tvb, offset, -1, ENC_NA);
btavdtp_tree = proto_item_add_subtree(ti, ett_btavdtp);
col_append_fstr(pinfo->cinfo, COL_INFO, "Media stream on cid=0x%04x", l2cap_data->cid);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "Media stream ACP SEID [%u - %s %s]",
channels_info->sep->seid, get_sep_media_type(
interface_id, adapter_id, chandle, direction,
channels_info->sep->seid,
frame_number),
get_sep_type(interface_id, adapter_id, chandle, direction,
channels_info->sep->seid,
frame_number));
if (channels_info->sep->media_type == MEDIA_TYPE_AUDIO) {
sep_data_t sep_data;
media_stream_number_value_t *media_stream_number_value;
media_packet_info_t *previous_media_packet_info;
media_packet_info_t *current_media_packet_info;
nstime_t first_abs_ts;
gdouble cumulative_frame_duration;
gdouble avrcp_song_position = -1.0;
btavrcp_song_position_data_t *song_position_data;
sep_data.codec = channels_info->sep->codec;
sep_data.vendor_id = channels_info->sep->vendor_id;
sep_data.vendor_codec = channels_info->sep->vendor_codec;
sep_data.acp_seid = channels_info->sep->seid;
sep_data.int_seid = channels_info->sep->int_seid;
sep_data.content_protection_type = channels_info->sep->content_protection_type;
sep_data.stream_start_in_frame = 0;
sep_data.stream_end_in_frame = 0;
sep_data.configuration_length = channels_info->sep->configuration_length;
sep_data.configuration = channels_info->sep->configuration;
media_stream_number_value = (media_stream_number_value_t *) wmem_tree_lookup32_le(channels_info->stream_numbers, frame_number - 1);
if (media_stream_number_value) {
sep_data.stream_number = media_stream_number_value->stream_number;
if (media_stream_number_value->stream_start_in_frame == 0)
media_stream_number_value->stream_start_in_frame = pinfo->num;
if (!pinfo->fd->flags.visited)
media_stream_number_value->stream_end_in_frame = pinfo->num;
sep_data.stream_start_in_frame = media_stream_number_value->stream_start_in_frame;
sep_data.stream_end_in_frame = media_stream_number_value->stream_end_in_frame;
} else {
sep_data.stream_number = 1;
}
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &cid;
key[4].length = 1;
key[4].key = &direction;
key[5].length = 0;
key[5].key = NULL;
key[2].length = 0;
key[2].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(btavrcp_song_positions, key);
song_position_data = (subtree) ? (btavrcp_song_position_data_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (song_position_data && (song_position_data->used_in_frame == 0 ||
song_position_data->used_in_frame == frame_number)) {
avrcp_song_position = song_position_data->song_position;
if (!pinfo->fd->flags.visited)
song_position_data->used_in_frame = frame_number;
}
key[2].length = 1;
key[2].key = &chandle;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(media_packet_times, key);
previous_media_packet_info = (subtree) ? (media_packet_info_t *) wmem_tree_lookup32_le(subtree, frame_number - 1) : NULL;
if (previous_media_packet_info && previous_media_packet_info->stream_number == sep_data.stream_number ) {
sep_data.previous_media_packet_info = previous_media_packet_info;
first_abs_ts = previous_media_packet_info->first_abs_ts;
cumulative_frame_duration = previous_media_packet_info->cumulative_frame_duration;
if (avrcp_song_position == -1.0)
avrcp_song_position = previous_media_packet_info->avrcp_song_position;
else
previous_media_packet_info->avrcp_song_position = avrcp_song_position;
} else {
if (avrcp_song_position == -1.0)
avrcp_song_position = 0.0;
first_abs_ts = pinfo->abs_ts;
cumulative_frame_duration = 0.0;
sep_data.previous_media_packet_info = (media_packet_info_t *) wmem_new(wmem_epan_scope(), media_packet_info_t);
sep_data.previous_media_packet_info->abs_ts = pinfo->abs_ts;
sep_data.previous_media_packet_info->first_abs_ts = first_abs_ts;
sep_data.previous_media_packet_info->cumulative_frame_duration = cumulative_frame_duration;
sep_data.previous_media_packet_info->avrcp_song_position = avrcp_song_position;
sep_data.previous_media_packet_info->stream_number = sep_data.stream_number;
}
if (!pinfo->fd->flags.visited) {
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
if (avrcp_song_position == -1.0)
avrcp_song_position = 0.0;
current_media_packet_info = wmem_new(wmem_file_scope(), media_packet_info_t);
current_media_packet_info->abs_ts = pinfo->abs_ts;
current_media_packet_info->first_abs_ts = first_abs_ts;
current_media_packet_info->cumulative_frame_duration = cumulative_frame_duration;
current_media_packet_info->avrcp_song_position = avrcp_song_position;
current_media_packet_info->stream_number = sep_data.stream_number;
wmem_tree_insert32_array(media_packet_times, key, current_media_packet_info);
}
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(media_packet_times, key);
current_media_packet_info = (subtree) ? (media_packet_info_t *) wmem_tree_lookup32(subtree, frame_number) : NULL;
if (current_media_packet_info)
sep_data.current_media_packet_info = current_media_packet_info;
else
sep_data.current_media_packet_info = NULL;
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(bta2dp_handle, next_tvb, pinfo, tree, &sep_data);
} else if (channels_info->sep->media_type == MEDIA_TYPE_VIDEO) {
sep_data_t sep_data;
media_stream_number_value_t *media_stream_number_value;
sep_data.codec = channels_info->sep->codec;
sep_data.vendor_id = channels_info->sep->vendor_id;
sep_data.vendor_codec = channels_info->sep->vendor_codec;
sep_data.acp_seid = channels_info->sep->seid;
sep_data.int_seid = channels_info->sep->int_seid;
sep_data.content_protection_type = channels_info->sep->content_protection_type;
sep_data.stream_start_in_frame = 0;
sep_data.stream_end_in_frame = 0;
sep_data.configuration_length = channels_info->sep->configuration_length;
sep_data.configuration = channels_info->sep->configuration;
media_stream_number_value = (media_stream_number_value_t *) wmem_tree_lookup32_le(channels_info->stream_numbers, frame_number - 1);
if (media_stream_number_value) {
sep_data.stream_number = media_stream_number_value->stream_number;
} else {
sep_data.stream_number = 1;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(btvdp_handle, next_tvb, pinfo, tree, &sep_data);
} else {
ti = proto_tree_add_item(tree, proto_btavdtp, tvb, offset, -1, ENC_NA);
btavdtp_tree = proto_item_add_subtree(ti, ett_btavdtp);
col_append_fstr(pinfo->cinfo, COL_INFO, "Media stream on cid=0x%04x", l2cap_data->cid);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
}
}
return tvb_reported_length(tvb);
} else if (!(l2cap_data->local_cid == channels_info->control_local_cid &&
l2cap_data->remote_cid == channels_info->control_remote_cid)) {
ti = proto_tree_add_item(tree, proto_btavdtp, tvb, offset, -1, ENC_NA);
btavdtp_tree = proto_item_add_subtree(ti, ett_btavdtp);
col_append_fstr(pinfo->cinfo, COL_INFO, "Unknown channel stream on cid=0x%04x", l2cap_data->cid);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
return tvb_reported_length(tvb);
}
ti = proto_tree_add_item(tree, proto_btavdtp, tvb, offset, -1, ENC_NA);
btavdtp_tree = proto_item_add_subtree(ti, ett_btavdtp);
message_type = (tvb_get_guint8(tvb, offset) & AVDTP_MESSAGE_TYPE_MASK);
packet_type = (tvb_get_guint8(tvb, offset) & AVDTP_PACKET_TYPE_MASK) >> 2;
signal_item = proto_tree_add_item(btavdtp_tree, hf_btavdtp_signal, tvb, offset,
(packet_type == PACKET_TYPE_START) ? 3 : 2, ENC_NA);
signal_tree = proto_item_add_subtree(signal_item, ett_btavdtp_sep);
proto_tree_add_item(signal_tree, hf_btavdtp_transaction, tvb, offset, 1, ENC_NA);
proto_tree_add_item(signal_tree, hf_btavdtp_packet_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(signal_tree, hf_btavdtp_message_type, tvb, offset, 1, ENC_NA);
if (packet_type == PACKET_TYPE_START) {
offset += 1;
proto_tree_add_item(signal_tree, hf_btavdtp_number_of_signal_packets, tvb, offset, 1, ENC_NA);
}
if (packet_type == PACKET_TYPE_CONTINUE || packet_type == PACKET_TYPE_END) goto LABEL_data;
offset += 1;
proto_tree_add_item(signal_tree, hf_btavdtp_rfa0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(signal_tree, hf_btavdtp_signal_id, tvb, offset, 1, ENC_NA);
signal_id = tvb_get_guint8(tvb, offset) & AVDTP_SIGNAL_ID_MASK;
proto_item_append_text(signal_item, ": %s (%s)",
val_to_str_const(signal_id, signal_id_vals, "Unknown signal"),
val_to_str_const(message_type, message_type_vals, "Unknown message type"));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s - %s",
val_to_str_const(message_type, message_type_vals, "Unknown message type"),
val_to_str_const(signal_id, signal_id_vals, "Unknown signal"));
offset += 1;
if (message_type != MESSAGE_TYPE_GENERAL_REJECT) switch (signal_id) {
case SIGNAL_ID_DISCOVER:
if (message_type == MESSAGE_TYPE_COMMAND) break;
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
offset = dissect_sep(tvb, pinfo, btavdtp_tree, offset,
interface_id, adapter_id, chandle);
break;
case SIGNAL_ID_GET_CAPABILITIES:
case SIGNAL_ID_GET_ALL_CAPABILITIES:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
offset = dissect_capabilities(tvb, pinfo, btavdtp_tree, offset, NULL, NULL, NULL, NULL, NULL, NULL);
break;
case SIGNAL_ID_SET_CONFIGURATION:
if (message_type == MESSAGE_TYPE_COMMAND) {
guint32 int_seid;
guint32 vendor_id;
guint16 vendor_codec;
guint32 reverse_direction;
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, &seid, interface_id,
adapter_id, chandle, frame_number);
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_INT, 0, &int_seid, interface_id,
adapter_id, chandle, frame_number);
offset = dissect_capabilities(tvb, pinfo, btavdtp_tree, offset,
&codec, &content_protection_type, &vendor_id,
&vendor_codec, &configuration_offset, &configuration_length);
if (!pinfo->fd->flags.visited) {
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_list, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep) {
sep->codec = codec;
sep->vendor_id = vendor_id;
sep->vendor_codec = vendor_codec;
sep->content_protection_type = content_protection_type;
sep->int_seid = int_seid;
if (configuration_length > 0) {
sep->configuration_length = configuration_length;
sep->configuration = (guint8 *) tvb_memdup(wmem_file_scope(),
tvb, configuration_offset, configuration_length);
}
if (direction == P2P_DIR_SENT)
reverse_direction = P2P_DIR_RECV;
else if (direction == P2P_DIR_RECV)
reverse_direction = P2P_DIR_SENT;
else
reverse_direction = P2P_DIR_UNKNOWN;
key[3].length = 1;
key[3].key = &reverse_direction;
key[4].length = 1;
key[4].key = &int_seid;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
wmem_tree_insert32_array(sep_list, key, sep);
}
}
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_service_category, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
case SIGNAL_ID_GET_CONFIGURATION:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
offset = dissect_capabilities(tvb, pinfo, btavdtp_tree, offset, NULL, NULL, NULL, NULL, NULL, NULL);
break;
case SIGNAL_ID_RECONFIGURE:
if (message_type == MESSAGE_TYPE_COMMAND) {
guint32 vendor_id;
guint16 vendor_codec;
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, &seid, interface_id,
adapter_id, chandle, frame_number);
offset = dissect_capabilities(tvb, pinfo, btavdtp_tree, offset,
&codec, &content_protection_type, &vendor_id,
&vendor_codec, &configuration_offset, &configuration_length);
if (!pinfo->fd->flags.visited) {
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_list, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep) {
sep->codec = codec;
sep->vendor_id = vendor_id;
sep->vendor_codec = vendor_codec;
sep->content_protection_type = content_protection_type;
if (configuration_length > 0) {
sep->configuration_length = configuration_length;
sep->configuration = (guint8 *) tvb_memdup(wmem_file_scope(),
tvb, configuration_offset, configuration_length);
}
}
}
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_service_category, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
case SIGNAL_ID_OPEN:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, &seid, interface_id,
adapter_id, chandle, frame_number);
if (!pinfo->fd->flags.visited) {
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &seid;
key[5].length = 0;
key[5].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_list, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep) {
sep->state = SEP_STATE_OPEN;
key[3].length = 1;
key[3].key = &frame_number;
key[4].length = 0;
key[4].key = NULL;
wmem_tree_insert32_array(sep_open, key, sep);
}
}
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
if (message_type == MESSAGE_TYPE_ACCEPT && !pinfo->fd->flags.visited) {
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 0;
key[3].key = NULL;
subtree = (wmem_tree_t *) wmem_tree_lookup32_array(sep_open, key);
sep = (subtree) ? (sep_entry_t *) wmem_tree_lookup32_le(subtree, frame_number) : NULL;
if (sep && sep->state == SEP_STATE_OPEN) {
sep->state = SEP_STATE_IN_USE;
channels_info->sep = sep;
}
}
break;
case SIGNAL_ID_START:
if (message_type == MESSAGE_TYPE_COMMAND) {
i_sep = 1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, i_sep, NULL,
interface_id, adapter_id, chandle, frame_number);
i_sep += 1;
}
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL,
interface_id, adapter_id, chandle, frame_number);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
if (message_type == MESSAGE_TYPE_ACCEPT && !pinfo->fd->flags.visited) {
media_stream_number_value_t *media_stream_number_value;
guint32 stream_number = 0;
media_stream_number_value = (media_stream_number_value_t *) wmem_tree_lookup32_le(channels_info->stream_numbers, frame_number - 1);
#if RTP_PLAYER_WORKAROUND == TRUE
{
media_stream_number_value_t *file_scope_stream_number_value;
if (media_stream_number_value) {
stream_number = media_stream_number_value->stream_number;
} else {
file_scope_stream_number_value = (media_stream_number_value_t *) wmem_tree_lookup32_le(file_scope_stream_number, frame_number - 1);
if (file_scope_stream_number_value)
stream_number = file_scope_stream_number_value->stream_number + 1;
else
stream_number = 0;
}
file_scope_stream_number_value = wmem_new(wmem_file_scope(), media_stream_number_value_t);
file_scope_stream_number_value->stream_number = stream_number;
wmem_tree_insert32(file_scope_stream_number, frame_number, file_scope_stream_number_value);
}
#else
if (media_stream_number_value)
stream_number = media_stream_number_value->stream_number;
else
stream_number = 0;
#endif
media_stream_number_value = wmem_new(wmem_file_scope(), media_stream_number_value_t);
media_stream_number_value->stream_number = stream_number + 1;
media_stream_number_value->stream_start_in_frame = 0;
media_stream_number_value->stream_end_in_frame = 0;
wmem_tree_insert32(channels_info->stream_numbers, frame_number, media_stream_number_value);
}
break;
case SIGNAL_ID_CLOSE:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
if (!pinfo->fd->flags.visited && message_type == MESSAGE_TYPE_ACCEPT &&
channels_info->disconnect_in_frame > pinfo->num) {
channels_info->disconnect_in_frame = pinfo->num;
}
break;
case SIGNAL_ID_SUSPEND:
if (message_type == MESSAGE_TYPE_COMMAND) {
i_sep = 1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, i_sep, NULL,
interface_id, adapter_id, chandle, frame_number);
i_sep += 1;
}
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
case SIGNAL_ID_ABORT:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
if (!pinfo->fd->flags.visited && message_type == MESSAGE_TYPE_ACCEPT &&
channels_info->disconnect_in_frame > pinfo->num) {
channels_info->disconnect_in_frame = pinfo->num;
}
break;
case SIGNAL_ID_SECURITY_CONTROL:
if (message_type == MESSAGE_TYPE_COMMAND) {
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL, interface_id,
adapter_id, chandle, frame_number);
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
break;
case SIGNAL_ID_DELAY_REPORT:
if (message_type == MESSAGE_TYPE_COMMAND) {
proto_item *pitem;
delay = tvb_get_ntohs(tvb, offset + 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "(%u.%u ms)", delay/10, delay%10);
offset = dissect_seid(tvb, pinfo, btavdtp_tree, offset,
SEID_ACP, 0, NULL,
interface_id, adapter_id, chandle, frame_number);
pitem = proto_tree_add_item(btavdtp_tree, hf_btavdtp_delay, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pitem, " (1/10 ms)");
offset += 2;
break;
}
if (message_type == MESSAGE_TYPE_REJECT) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_error_code, tvb, offset, 1, ENC_NA);
offset += 1;
break;
}
break;
}
LABEL_data:
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(btavdtp_tree, hf_btavdtp_data, tvb, offset, -1, ENC_NA);
}
return offset;
}
void
proto_register_btavdtp(void)
{
module_t *module;
static hf_register_info hf[] = {
{ &hf_btavdtp_signal,
{ "Signal", "btavdtp.signal",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_message_type,
{ "Message Type", "btavdtp.message_type",
FT_UINT8, BASE_HEX, VALS(message_type_vals), AVDTP_MESSAGE_TYPE_MASK,
NULL, HFILL }
},
{ &hf_btavdtp_packet_type,
{ "Packet Type", "btavdtp.packet_type",
FT_UINT8, BASE_HEX, VALS(packet_type_vals), AVDTP_PACKET_TYPE_MASK,
NULL, HFILL }
},
{ &hf_btavdtp_transaction,
{ "Transaction", "btavdtp.transaction",
FT_UINT8, BASE_HEX, NULL, AVDTP_TRANSACTION_MASK,
NULL, HFILL }
},
{ &hf_btavdtp_signal_id,
{ "Signal", "btavdtp.signal_id",
FT_UINT8, BASE_HEX, VALS(signal_id_vals), AVDTP_SIGNAL_ID_MASK,
NULL, HFILL }
},
{ &hf_btavdtp_rfa0,
{ "RFA", "btavdtp.rfa0",
FT_UINT8, BASE_HEX, NULL, AVDTP_RFA0_MASK,
NULL, HFILL }
},
{ &hf_btavdtp_number_of_signal_packets,
{ "Number of signal packets", "btavdtp.num_signal_packets",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_btavdtp_error_code,
{ "Error Code", "btavdtp.error_code",
FT_UINT8, BASE_HEX, VALS(error_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_sep_seid,
{ "SEID", "btavdtp.sep_seid",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL }
},
{ &hf_btavdtp_sep_inuse,
{ "In Use", "btavdtp.sep_inuse",
FT_UINT8, BASE_HEX, VALS(true_false), 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_sep_rfa0,
{ "RFA0", "btavdtp.sep_rfa0",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_sep_media_type,
{ "Media Type", "btavdtp.sep_media_type",
FT_UINT8, BASE_HEX, VALS(media_type_vals), 0xF0,
NULL, HFILL }
},
{ &hf_btavdtp_sep_type,
{ "Type", "btavdtp.sep_type",
FT_UINT8, BASE_HEX, VALS(sep_type_vals), 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_sep_rfa1,
{ "RFA1", "btavdtp.sep_rfa1",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_btavdtp_acp_sep,
{ "ACP SEP", "btavdtp.acp_sep",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_acp_seid_item,
{ "ACP SEID", "btavdtp.acp_seid_item",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_int_seid_item,
{ "INT SEID", "btavdtp.int_seid_item",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_acp_seid,
{ "ACP SEID", "btavdtp.acp_seid",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL }
},
{ &hf_btavdtp_int_seid,
{ "INT SEID", "btavdtp.int_seid",
FT_UINT8, BASE_DEC, NULL, 0xFC,
NULL, HFILL }
},
{ &hf_btavdtp_rfa_seid,
{ "RFA", "btavdtp.rfa_seid",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }
},
{ &hf_btavdtp_service_category,
{ "Service Category", "btavdtp.service_category",
FT_UINT8, BASE_HEX, VALS(service_category_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_length_of_service_category,
{ "Length of Service Category", "btavdtp.length_of_service_category",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_delay,
{ "Delay", "btavdtp.delay",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_recovery_type,
{ "Service Category", "btavdtp.recovery_type",
FT_UINT8, BASE_HEX, VALS(recovery_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_maximum_recovery_window_size,
{ "Service Category", "btavdtp.maximum_recovery_window_size",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_maximum_number_of_media_packet_in_parity_code,
{ "Service Category", "btavdtp.maximum_number_of_media_packet_in_parity_code",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_multiplexing_fragmentation,
{ "Fragmentation", "btavdtp.multiplexing_fragmentation",
FT_UINT8, BASE_HEX, VALS(true_false), 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_multiplexing_rfa,
{ "RFA", "btavdtp.multiplexing_rfa",
FT_UINT8, BASE_HEX, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_btavdtp_multiplexing_tsid,
{ "TSID", "btavdtp.multiplexing_tsid",
FT_UINT8, BASE_HEX, VALS(multiplexing_tsid_vals), 0xF8,
NULL, HFILL }
},
{ &hf_btavdtp_multiplexing_tcid,
{ "TCID", "btavdtp.multiplexing_tcid",
FT_UINT8, BASE_HEX, VALS(multiplexing_tcid_vals), 0xF8,
NULL, HFILL }
},
{ &hf_btavdtp_multiplexing_entry_rfa,
{ "RFA", "btavdtp.multiplexing_entry_rfa",
FT_UINT8, BASE_HEX, NULL, 0x07,
NULL, HFILL }
},
{ &hf_btavdtp_header_compression_backch,
{ "BackCh", "btavdtp.header_compression_backch",
FT_UINT8, BASE_HEX, VALS(true_false), 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_header_compression_media,
{ "Media", "btavdtp.header_compression_media",
FT_UINT8, BASE_HEX, VALS(true_false), 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_header_compression_recovery,
{ "Recovery", "btavdtp.header_compression_recovery",
FT_UINT8, BASE_HEX, VALS(true_false), 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_header_compression_rfa,
{ "RFA", "btavdtp.header_compression_rfa",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_btavdtp_content_protection_type,
{ "Type", "btavdtp.content_protection_type",
FT_UINT16, BASE_HEX, VALS(content_protection_type_vals), 0x0000,
NULL, HFILL }
},
{ &hf_btavdtp_media_codec_media_type,
{ "Media Type", "btavdtp.media_codec_media_type",
FT_UINT8, BASE_HEX, VALS(media_type_vals), 0xF0,
NULL, HFILL }
},
{ &hf_btavdtp_media_codec_rfa,
{ "RFA", "btavdtp.media_codec_rfa",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_btavdtp_media_codec_audio_type,
{ "Media Codec Audio Type", "btavdtp.media_codec_audio_type",
FT_UINT8, BASE_HEX, VALS(media_codec_audio_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_media_codec_video_type,
{ "Media Codec Video Type", "btavdtp.media_codec_video_type",
FT_UINT8, BASE_HEX, VALS(media_codec_video_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_media_codec_unknown_type,
{ "Media Codec Unknown Type", "btavdtp.media_codec_unknown_type",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_sampling_frequency_16000,
{ "Sampling Frequency 16000 Hz", "btavdtp.codec.sbc.sampling_frequency.16000",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_sampling_frequency_32000,
{ "Sampling Frequency 32000 Hz", "btavdtp.codec.sbc.sampling_frequency.32000",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_sampling_frequency_44100,
{ "Sampling Frequency 44100 Hz", "btavdtp.codec.sbc.sampling_frequency.44100",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_sampling_frequency_48000,
{ "Sampling Frequency 48000 Hz", "btavdtp.codec.sbc.sampling_frequency.48000",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_channel_mode_mono,
{ "Channel Mode Mono", "btavdtp.codec.sbc.channel_mode.mono",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_channel_mode_dual_channel,
{ "Channel Mode Dual Channel", "btavdtp.codec.sbc.channel_mode.dual_channel",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_channel_mode_stereo,
{ "Channel Mode Stereo", "btavdtp.codec.sbc.channel_mode.stereo",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_channel_mode_joint_stereo,
{ "Channel Mode Joint Stereo", "btavdtp.codec.sbc.channel_mode.joint_stereo",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_block_4,
{ "Block Length 4", "btavdtp.codec.sbc.block.4",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_block_8,
{ "Block Length 8", "btavdtp.codec.sbc.block.8",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_block_12,
{ "Block Length 12", "btavdtp.codec.sbc.block.12",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_block_16,
{ "Block Length 16", "btavdtp.codec.sbc.block.16",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_subbands_4,
{ "Subbands 4", "btavdtp.codec.sbc.subbands.4",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_subbands_8,
{ "Subbands 8", "btavdtp.codec.sbc.subbands.8",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_allocation_method_snr,
{ "Allocation Method SNR", "btavdtp.codec.sbc.allocation_method.snr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_allocation_method_loudness,
{ "Allocation Method Loudness", "btavdtp.codec.sbc.allocation_method.loudness",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_min_bitpool,
{ "Minimum Bitpool", "btavdtp.codec.sbc.minimum_bitpool",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_sbc_max_bitpool,
{ "Maximum Bitpool", "btavdtp.codec.sbc.maximum_bitpool",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_layer_1,
{ "MP1", "btavdtp.codec.mpeg12.layer_1",
FT_BOOLEAN, 8, NULL, 0x80,
"MPEG Layer 1", HFILL }
},
{ &hf_btavdtp_mpeg12_layer_2,
{ "MP2", "btavdtp.codec.mpeg12.layer_2",
FT_BOOLEAN, 8, NULL, 0x40,
"MPEG Layer 2", HFILL }
},
{ &hf_btavdtp_mpeg12_layer_3,
{ "MP3", "btavdtp.codec.mpeg12.layer_3",
FT_BOOLEAN, 8, NULL, 0x20,
"MPEG Layer 3", HFILL }
},
{ &hf_btavdtp_mpeg12_crc_protection,
{ "CRC Protection", "btavdtp.codec.mpeg12.crc_protection",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_channel_mode_mono,
{ "Channel Mode Mono", "btavdtp.codec.mpeg12.channel_mode.mono",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_channel_mode_dual_channel,
{ "Channel Mode Dual Channel", "btavdtp.codec.mpeg12.channel_mode.dual_channel",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_channel_mode_stereo,
{ "Channel Mode Stereo", "btavdtp.codec.mpeg12.channel_mode.stereo",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_channel_mode_joint_stereo,
{ "Channel Mode Joint Stereo", "btavdtp.codec.mpeg12.channel_mode.joint_stereo",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_rfa,
{ "RFA", "btavdtp.codec.mpeg12.rfa",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_mpf_2,
{ "Media Payload Format 2", "btavdtp.codec.mpeg12.mpf_2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_16000,
{ "Sampling Frequency 16000 Hz", "btavdtp.codec.sbc.sampling_frequency.16000",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_22050,
{ "Sampling Frequency 22050 Hz", "btavdtp.codec.sbc.sampling_frequency.22050",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_24000,
{ "Sampling Frequency 24000 Hz", "btavdtp.codec.sbc.sampling_frequency.24000",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_32000,
{ "Sampling Frequency 32000 Hz", "btavdtp.codec.sbc.sampling_frequency.32000",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_44100,
{ "Sampling Frequency 44100 Hz", "btavdtp.codec.sbc.sampling_frequency.44100",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_sampling_frequency_48000,
{ "Sampling Frequency 48000 Hz", "btavdtp.codec.sbc.sampling_frequency.48000",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_vbr_supported,
{ "VBR Supported", "btavdtp.codec.mpeg12.vbr",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg12_bit_rate,
{ "Bit Rate", "btavdtp.codec.mpeg12.bit_rate",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_object_type_mpeg2_aac_lc,
{ "MPEG2 ACC LC", "btavdtp.codec.mpeg24.object_type.mpeg2_aac_lc",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_object_type_mpeg4_aac_lc,
{ "MPEG4 ACC LC", "btavdtp.codec.mpeg24.object_type.mpeg4_aac_lc",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_object_type_mpeg4_aac_ltp,
{ "MPEG4 ACC LTP", "btavdtp.codec.mpeg24.object_type.mpeg4_aac_ltp",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_object_type_mpeg4_aac_scalable,
{ "MPEG4 ACC Scalable", "btavdtp.codec.mpeg24.object_type.mpeg4_aac_scalable",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_object_type_rfa,
{ "RFA", "btavdtp.codec.mpeg24.object_type.rfa",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_8000,
{ "Sampling Frequency 8000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.8000",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_11025,
{ "Sampling Frequency 11025 Hz", "btavdtp.codec.mpeg24.sampling_frequency.11025",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_12000,
{ "Sampling Frequency 12000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.12000",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_16000,
{ "Sampling Frequency 16000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.16000",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_22050,
{ "Sampling Frequency 22050 Hz", "btavdtp.codec.mpeg24.sampling_frequency.22050",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_24000,
{ "Sampling Frequency 24000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.24000",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_32000,
{ "Sampling Frequency 32000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.32000",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_44100,
{ "Sampling Frequency 44100 Hz", "btavdtp.codec.mpeg24.sampling_frequency.44100",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_48000,
{ "Sampling Frequency 48000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.48000",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_64000,
{ "Sampling Frequency 64000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.64000",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_88200,
{ "Sampling Frequency 88200 Hz", "btavdtp.codec.mpeg24.sampling_frequency.88200",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_sampling_frequency_96000,
{ "Sampling Frequency 96000 Hz", "btavdtp.codec.mpeg24.sampling_frequency.96000",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_channels_1,
{ "Channels 1", "btavdtp.codec.mpeg24.channels.1",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_channels_2,
{ "Channels 2", "btavdtp.codec.mpeg24.channels.2",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_rfa,
{ "RFA", "btavdtp.codec.mpeg24.rfa",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_vbr_supported,
{ "VBR Supported", "btavdtp.codec.mpeg24.vbr",
FT_BOOLEAN, 24, NULL, 0x800000,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg24_bit_rate,
{ "Bit Rate", "btavdtp.codec.mpeg24.bit_rate",
FT_UINT24, BASE_HEX, NULL, 0x7FFFFF,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_version,
{ "Version", "btavdtp.codec.atrac.version",
FT_UINT8, BASE_DEC, NULL, 0xE0,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_channel_mode_single_channel,
{ "Channel Mode Single Channel", "btavdtp.codec.atrac.channel_mode.single_channel",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_channel_mode_dual_channel,
{ "Channel Mode Dual Channel", "btavdtp.codec.atrac.channel_mode.dual_channel",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_channel_mode_joint_stereo,
{ "Channel Mode Joint Stereo", "btavdtp.codec.atrac.channel_mode.joint_stereo",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_rfa1,
{ "RFA", "btavdtp.codec.atrac.rfa1",
FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_rfa2,
{ "RFA", "btavdtp.codec.atrac.rfa2",
FT_UINT24, BASE_HEX, NULL, 0xC00000,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_sampling_frequency_44100,
{ "Sampling Frequency 44100 Hz", "btavdtp.codec.sbc.sampling_frequency.44100",
FT_BOOLEAN, 24, NULL, 0x200000,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_sampling_frequency_48000,
{ "Sampling Frequency 48000 Hz", "btavdtp.codec.sbc.sampling_frequency.48000",
FT_BOOLEAN, 24, NULL, 0x100000,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_vbr_supported,
{ "VBR Supported", "btavdtp.codec.atrac.vbr",
FT_BOOLEAN, 24, NULL, 0x080000,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_bit_rate,
{ "Bit Rate", "btavdtp.codec.atrac.bit_rate",
FT_UINT24, BASE_HEX, NULL, 0x07FFFF,
NULL, HFILL }
},
{ &hf_btavdtp_atrac_maximum_sul,
{ "Maximum SUL", "btavdtp.codec.atrac.maximum_sul",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Sound Unit Length (SUL) is one of the parameters that determine bit rate of the audio stream.", HFILL }
},
{ &hf_btavdtp_atrac_rfa3,
{ "RFA", "btavdtp.codec.atrac.rfa3",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_h263_level_10,
{ "H264 Level 10", "btavdtp.codec.h264.level.10",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_h263_level_20,
{ "H264 Level 20", "btavdtp.codec.h264.level.20",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_h263_level_30,
{ "H264 Level 30", "btavdtp.codec.h264.level.30",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_h263_level_rfa,
{ "H264 Level RFA", "btavdtp.codec.h264.level.rfa",
FT_UINT8, BASE_HEX, NULL, 0x1F,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg4_level_0,
{ "MPEG Level 0", "btavdtp.codec.mpeg4.level.0",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg4_level_1,
{ "MPEG Level 1", "btavdtp.codec.mpeg4.level.1",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg4_level_2,
{ "MPEG Level 2", "btavdtp.codec.mpeg4.level.2",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg4_level_3,
{ "MPEG4 Level 3", "btavdtp.codec.mpeg4.level.3",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_mpeg4_level_rfa,
{ "MPEG4 Level RFA", "btavdtp.codec.mpeg4.level.rfa",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_id,
{ "Vendor ID", "btavdtp.codec.vendor.vendor_id",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &bluetooth_company_id_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_codec_id,
{ "Codec", "btavdtp.codec.vendor.codec_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_value,
{ "Value", "btavdtp.codec.vendor.value",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_apt_codec_id,
{ "Codec", "btavdtp.codec.vendor.codec_id",
FT_UINT16, BASE_HEX, VALS(vendor_apt_codec_vals), 0x00,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_sampling_frequency_16000,
{ "Sampling Frequency 16000 Hz", "btavdtp.codec.aptx.sampling_frequency.16000",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_sampling_frequency_32000,
{ "Sampling Frequency 32000 Hz", "btavdtp.codec.aptx.sampling_frequency.32000",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_sampling_frequency_44100,
{ "Sampling Frequency 44100 Hz", "btavdtp.codec.aptx.sampling_frequency.44100",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_sampling_frequency_48000,
{ "Sampling Frequency 48000 Hz", "btavdtp.codec.aptx.sampling_frequency.48000",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_channel_mode_mono,
{ "Channel Mode Mono", "btavdtp.codec.aptx.channel_mode.mono",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_channel_mode_dual_channel,
{ "Channel Mode Dual Channel", "btavdtp.codec.aptx.channel_mode.dual_channel",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_channel_mode_stereo,
{ "Channel Mode Stereo", "btavdtp.codec.aptx.channel_mode.stereo",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btavdtp_vendor_specific_aptx_channel_mode_joint_stereo,
{ "Channel Mode Joint Stereo", "btavdtp.codec.aptx.channel_mode.joint_stereo",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btavdtp_capabilities,
{ "Capabilities", "btavdtp.capabilities",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btavdtp_service,
{ "Service", "btavdtp.service",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btavdtp_service_multiplexing_entry,
{ "Entry", "btavdtp.service_multiplexing_entry",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btavdtp_data,
{ "Data", "btavdtp.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_btavdtp,
&ett_btavdtp_sep,
&ett_btavdtp_capabilities,
&ett_btavdtp_service,
};
proto_btavdtp = proto_register_protocol("Bluetooth AVDTP Protocol", "BT AVDTP", "btavdtp");
btavdtp_handle = register_dissector("btavdtp", dissect_btavdtp, proto_btavdtp);
proto_register_field_array(proto_btavdtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
module = prefs_register_protocol(proto_btavdtp, NULL);
prefs_register_static_text_preference(module, "avdtp.version",
"Bluetooth Protocol AVDTP version: 1.3",
"Version of protocol supported by this dissector.");
channels = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
sep_list = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
sep_open = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
media_packet_times = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
#if RTP_PLAYER_WORKAROUND == TRUE
file_scope_stream_number = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
#endif
}
void
proto_reg_handoff_btavdtp(void)
{
dissector_add_string("bluetooth.uuid", "19", btavdtp_handle);
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_AVDTP, btavdtp_handle);
dissector_add_for_decode_as("btl2cap.cid", btavdtp_handle);
}
static gint
dissect_aptx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *aptx_item;
proto_tree *aptx_tree;
proto_item *pitem;
bta2dp_codec_info_t *info;
gdouble cumulative_frame_duration = 0;
info = (bta2dp_codec_info_t *) data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "APT-X");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
col_clear(pinfo->cinfo, COL_INFO);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "APT-X");
aptx_item = proto_tree_add_item(tree, proto_aptx, tvb, 0, -1, ENC_NA);
aptx_tree = proto_item_add_subtree(aptx_item, ett_aptx);
proto_tree_add_item(aptx_tree, hf_aptx_data, tvb, 0, -1, ENC_NA);
if (info && info->configuration && info->configuration_length >= 9) {
gboolean fail = FALSE;
gdouble expected_speed_data;
gdouble frame_duration;
gdouble frame_length = 2 * 2 * 4;
gint number_of_channels;
gint frequency;
gint sample_bits;
switch (info->configuration[8] >> 4) {
case 0x01:
frequency = 48000;
break;
case 0x02:
frequency = 44100;
break;
case 0x04:
frequency = 32000;
break;
case 0x08:
frequency = 16000;
break;
default:
fail = TRUE;
}
if (fail)
return tvb_reported_length(tvb);
switch (info->configuration[8] & 0x0F) {
case 0x01:
case 0x02:
case 0x04:
number_of_channels = 2;
break;
case 0x08:
number_of_channels = 1;
break;
default:
fail = TRUE;
}
if (fail)
return tvb_reported_length(tvb);
sample_bits = 16;
expected_speed_data = frequency * (sample_bits / 8.0) * number_of_channels;
frame_duration = (((double) frame_length / (double) expected_speed_data) * 1000.0);
cumulative_frame_duration = (tvb_reported_length(tvb) / 4.0) * frame_duration;
pitem = proto_tree_add_double(aptx_tree, hf_aptx_cumulative_frame_duration, tvb, 0, 0, cumulative_frame_duration);
PROTO_ITEM_SET_GENERATED(pitem);
if (info && info->previous_media_packet_info && info->current_media_packet_info) {
nstime_t delta;
nstime_delta(&delta, &pinfo->abs_ts, &info->previous_media_packet_info->abs_ts);
pitem = proto_tree_add_double(aptx_tree, hf_aptx_delta_time, tvb, 0, 0, nstime_to_msec(&delta));
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_double(aptx_tree, hf_aptx_avrcp_song_position, tvb, 0, 0, info->previous_media_packet_info->avrcp_song_position);
PROTO_ITEM_SET_GENERATED(pitem);
nstime_delta(&delta, &pinfo->abs_ts, &info->previous_media_packet_info->first_abs_ts);
pitem = proto_tree_add_double(aptx_tree, hf_aptx_delta_time_from_the_beginning, tvb, 0, 0, nstime_to_msec(&delta));
PROTO_ITEM_SET_GENERATED(pitem);
if (!pinfo->fd->flags.visited)
info->current_media_packet_info->cumulative_frame_duration += cumulative_frame_duration;
pitem = proto_tree_add_double(aptx_tree, hf_aptx_cumulative_duration, tvb, 0, 0, info->previous_media_packet_info->cumulative_frame_duration);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_double(aptx_tree, hf_aptx_diff, tvb, 0, 0, info->previous_media_packet_info->cumulative_frame_duration - nstime_to_msec(&delta));
PROTO_ITEM_SET_GENERATED(pitem);
}
}
return tvb_reported_length(tvb);
}
void
proto_register_aptx(void)
{
static hf_register_info hf[] = {
{ &hf_aptx_data,
{ "Data", "aptx.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_aptx_cumulative_frame_duration,
{ "Cumulative Frame Duration", "aptx.cumulative_frame_duration",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
{ &hf_aptx_delta_time,
{ "Delta time", "aptx.delta_time",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
{ &hf_aptx_avrcp_song_position,
{ "AVRCP Song Position", "aptx.avrcp_song_position",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
{ &hf_aptx_delta_time_from_the_beginning,
{ "Delta time from the beginning", "aptx.delta_time_from_the_beginning",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
{ &hf_aptx_cumulative_duration,
{ "Cumulative Music Duration", "aptx.cumulative_music_duration",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
{ &hf_aptx_diff,
{ "Diff", "aptx.diff",
FT_DOUBLE, BASE_NONE|BASE_UNIT_STRING, &units_milliseconds, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_aptx
};
proto_aptx = proto_register_protocol("APT-X Codec", "APT-X", "aptx");
proto_register_field_array(proto_aptx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
aptx_handle = register_dissector("aptx", dissect_aptx, proto_aptx);
}
static gint
dissect_bta2dp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *bta2dp_tree;
proto_item *pitem;
gint offset = 0;
dissector_handle_t codec_dissector = NULL;
bta2dp_codec_info_t bta2dp_codec_info;
sep_data_t sep_data;
gboolean no_avdtp_session;
no_avdtp_session = (proto_btavdtp != (gint) GPOINTER_TO_UINT(wmem_list_frame_data(
wmem_list_frame_prev(wmem_list_tail(pinfo->layers)))));
sep_data.codec = CODEC_SBC;
sep_data.content_protection_type = 0;
sep_data.acp_seid = 0;
sep_data.int_seid = 0;
sep_data.previous_media_packet_info = NULL;
sep_data.current_media_packet_info = NULL;
sep_data.stream_start_in_frame = 0;
sep_data.stream_end_in_frame = 0;
sep_data.stream_number = 1;
sep_data.vendor_id = 0;
sep_data.vendor_codec = 0;
sep_data.configuration_length = 0;
sep_data.configuration = NULL;
if (force_a2dp_scms_t || force_a2dp_codec != CODEC_DEFAULT) {
if (force_a2dp_scms_t)
sep_data.content_protection_type = 2;
else if (data && !no_avdtp_session)
sep_data.content_protection_type = ((sep_data_t *) data)->content_protection_type;
if (force_a2dp_codec != CODEC_DEFAULT)
sep_data.codec = force_a2dp_codec;
else if (data && !no_avdtp_session)
sep_data.codec = ((sep_data_t *) data)->codec;
} else {
if (data && !no_avdtp_session)
sep_data = *((sep_data_t *) data);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "A2DP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
col_clear(pinfo->cinfo, COL_INFO);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
ti = proto_tree_add_item(tree, proto_bta2dp, tvb, offset, -1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "Audio stream - %s",
val_to_str_const(sep_data.codec, media_codec_audio_type_vals, "unknown codec"));
bta2dp_tree = proto_item_add_subtree(ti, ett_bta2dp);
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_acp_seid, tvb, 0, 0, sep_data.acp_seid);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_int_seid, tvb, 0, 0, sep_data.int_seid);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_codec, tvb, 0, 0, sep_data.codec);
PROTO_ITEM_SET_GENERATED(pitem);
if (sep_data.codec == 0xFF) {
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_vendor_id, tvb, 0, 0, sep_data.vendor_id);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_vendor_codec_id, tvb, 0, 0, sep_data.vendor_codec);
PROTO_ITEM_SET_GENERATED(pitem);
if (sep_data.vendor_id == 0x004F && sep_data.vendor_codec == 0x0001)
codec_dissector = aptx_handle;
}
if (sep_data.content_protection_type > 0) {
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_content_protection, tvb, 0, 0, sep_data.content_protection_type);
PROTO_ITEM_SET_GENERATED(pitem);
}
if (sep_data.stream_start_in_frame > 0) {
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_stream_start_in_frame, tvb, 0, 0, sep_data.stream_start_in_frame);
PROTO_ITEM_SET_GENERATED(pitem);
}
if (sep_data.stream_end_in_frame > 0) {
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_stream_end_in_frame, tvb, 0, 0, sep_data.stream_end_in_frame);
PROTO_ITEM_SET_GENERATED(pitem);
}
pitem = proto_tree_add_uint(bta2dp_tree, hf_bta2dp_stream_number, tvb, 0, 0, sep_data.stream_number);
PROTO_ITEM_SET_GENERATED(pitem);
switch (sep_data.codec) {
case CODEC_SBC:
codec_dissector = sbc_handle;
break;
case CODEC_MPEG12_AUDIO:
codec_dissector = mp2t_handle;
break;
case CODEC_MPEG24_AAC:
codec_dissector = mpeg_audio_handle;
break;
case CODEC_ATRAC:
codec_dissector = atrac_handle;
break;
case CODEC_APT_X:
codec_dissector = aptx_handle;
break;
}
bta2dp_codec_info.codec_dissector = codec_dissector;
bta2dp_codec_info.configuration_length = sep_data.configuration_length;
bta2dp_codec_info.configuration = sep_data.configuration;
bta2dp_codec_info.content_protection_type = sep_data.content_protection_type;
bta2dp_codec_info.previous_media_packet_info = sep_data.previous_media_packet_info;
bta2dp_codec_info.current_media_packet_info = sep_data.current_media_packet_info;
#if RTP_PLAYER_WORKAROUND == TRUE
pinfo->srcport = sep_data.stream_number;
pinfo->destport = sep_data.stream_number;
#endif
if (bta2dp_codec_info.content_protection_type == 0 && codec_dissector == aptx_handle) {
call_dissector_with_data(aptx_handle, tvb, pinfo, tree, &bta2dp_codec_info);
} else {
bluetooth_add_address(pinfo, &pinfo->net_dst, sep_data.stream_number, "BT A2DP", pinfo->num, FALSE, &bta2dp_codec_info);
call_dissector(rtp_handle, tvb, pinfo, tree);
}
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
void
proto_register_bta2dp(void)
{
module_t *module;
static hf_register_info hf[] = {
{ &hf_bta2dp_acp_seid,
{ "ACP SEID", "bta2dp.acp_seid",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_int_seid,
{ "INT SEID", "bta2dp.int_seid",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_codec,
{ "Codec", "bta2dp.codec",
FT_UINT8, BASE_HEX, VALS(media_codec_audio_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_vendor_id,
{ "Vendor ID", "bta2dp.codec.vendor.vendor_id",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &bluetooth_company_id_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_vendor_codec_id,
{ "Vendor Codec", "bta2dp.codec.vendor.codec_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_content_protection,
{ "Content Protection", "bta2dp.content_protection",
FT_UINT16, BASE_HEX, VALS(content_protection_type_vals), 0x0000,
NULL, HFILL }
},
{ &hf_bta2dp_stream_start_in_frame,
{ "Stream Start in Frame", "bta2dp.stream_start_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_stream_end_in_frame,
{ "Stream End in Frame", "bta2dp.stream_end_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_bta2dp_stream_number,
{ "Stream Number", "bta2dp.stream_number",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_bta2dp
};
proto_bta2dp = proto_register_protocol("Bluetooth A2DP Profile", "BT A2DP", "bta2dp");
proto_register_field_array(proto_bta2dp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bta2dp_handle = register_dissector("bta2dp", dissect_bta2dp, proto_bta2dp);
module = prefs_register_protocol(proto_bta2dp, NULL);
prefs_register_static_text_preference(module, "a2dp.version",
"Bluetooth Profile A2DP version: 1.3",
"Version of profile supported by this dissector.");
prefs_register_bool_preference(module, "a2dp.content_protection.scms_t",
"Force SCMS-T decoding",
"Force decoding stream as A2DP with Content Protection SCMS-T ",
&force_a2dp_scms_t);
prefs_register_enum_preference(module, "a2dp.codec",
"Force codec",
"Force decoding stream as A2DP with specified codec",
&force_a2dp_codec, pref_a2dp_codec, FALSE);
}
void
proto_reg_handoff_bta2dp(void)
{
sbc_handle = find_dissector_add_dependency("sbc", proto_bta2dp);
mp2t_handle = find_dissector_add_dependency("mp2t", proto_bta2dp);
mpeg_audio_handle = find_dissector_add_dependency("mpeg-audio", proto_bta2dp);
atrac_handle = find_dissector_add_dependency("atrac", proto_bta2dp);
rtp_handle = find_dissector_add_dependency("rtp", proto_bta2dp);
dissector_add_string("bluetooth.uuid", "110a", bta2dp_handle);
dissector_add_string("bluetooth.uuid", "110b", bta2dp_handle);
dissector_add_string("bluetooth.uuid", "110d", bta2dp_handle);
dissector_add_for_decode_as("btl2cap.cid", bta2dp_handle);
}
static gint
dissect_btvdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *btvdp_tree;
proto_item *pitem;
gint offset = 0;
dissector_handle_t codec_dissector = NULL;
btvdp_codec_info_t btvdp_codec_info;
sep_data_t sep_data;
gboolean no_avdtp_session;
no_avdtp_session = (proto_btavdtp != (gint) GPOINTER_TO_UINT(wmem_list_frame_data(
wmem_list_frame_prev(wmem_list_tail(pinfo->layers)))));
sep_data.codec = CODEC_H263_BASELINE;
sep_data.content_protection_type = 0;
sep_data.acp_seid = 0;
sep_data.int_seid = 0;
sep_data.previous_media_packet_info = NULL;
sep_data.current_media_packet_info = NULL;
sep_data.stream_start_in_frame = 0;
sep_data.stream_end_in_frame = 0;
sep_data.stream_number = 1;
sep_data.vendor_id = 0;
sep_data.vendor_codec = 0;
sep_data.configuration_length = 0;
sep_data.configuration = NULL;
if (force_vdp_scms_t || force_vdp_codec) {
if (force_vdp_scms_t)
sep_data.content_protection_type = 2;
else if (data && !no_avdtp_session)
sep_data.content_protection_type = ((sep_data_t *) data)->content_protection_type;
if (force_vdp_codec)
sep_data.codec = force_vdp_codec;
else if (data && !no_avdtp_session)
sep_data.codec = ((sep_data_t *) data)->codec;
} else {
if (data && !no_avdtp_session)
sep_data = *((sep_data_t *) data);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VDP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
col_clear(pinfo->cinfo, COL_INFO);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
ti = proto_tree_add_item(tree, proto_btvdp, tvb, offset, -1, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "Video stream - %s",
val_to_str_const(sep_data.codec, media_codec_video_type_vals, "unknown codec"));
btvdp_tree = proto_item_add_subtree(ti, ett_btvdp);
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_acp_seid, tvb, 0, 0, sep_data.acp_seid);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_int_seid, tvb, 0, 0, sep_data.int_seid);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_codec, tvb, 0, 0, sep_data.codec);
PROTO_ITEM_SET_GENERATED(pitem);
if (sep_data.codec == 0xFF) {
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_vendor_id, tvb, 0, 0, sep_data.vendor_id);
PROTO_ITEM_SET_GENERATED(pitem);
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_vendor_codec_id, tvb, 0, 0, sep_data.vendor_codec);
PROTO_ITEM_SET_GENERATED(pitem);
}
if (sep_data.content_protection_type > 0) {
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_content_protection, tvb, 0, 0, sep_data.content_protection_type);
PROTO_ITEM_SET_GENERATED(pitem);
}
if (sep_data.stream_start_in_frame > 0) {
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_stream_start_in_frame, tvb, 0, 0, sep_data.stream_start_in_frame);
PROTO_ITEM_SET_GENERATED(pitem);
}
if (sep_data.stream_end_in_frame > 0) {
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_stream_end_in_frame, tvb, 0, 0, sep_data.stream_end_in_frame);
PROTO_ITEM_SET_GENERATED(pitem);
}
pitem = proto_tree_add_uint(btvdp_tree, hf_btvdp_stream_number, tvb, 0, 0, sep_data.stream_number);
PROTO_ITEM_SET_GENERATED(pitem);
switch (sep_data.codec) {
case CODEC_H263_BASELINE:
case CODEC_H263_PROFILE_3:
case CODEC_H263_PROFILE_8:
codec_dissector = h263_handle;
break;
case CODEC_MPEG4_VSP:
codec_dissector = mp4v_es_handle;
break;
}
btvdp_codec_info.codec_dissector = codec_dissector;
btvdp_codec_info.content_protection_type = sep_data.content_protection_type;
#if RTP_PLAYER_WORKAROUND == TRUE
pinfo->srcport = sep_data.stream_number;
pinfo->destport = sep_data.stream_number;
#endif
bluetooth_add_address(pinfo, &pinfo->net_dst, 0, "BT VDP", pinfo->num, TRUE, &btvdp_codec_info);
call_dissector(rtp_handle, tvb, pinfo, tree);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
void
proto_register_btvdp(void)
{
module_t *module;
expert_module_t* expert_btavdtp;
static hf_register_info hf[] = {
{ &hf_btvdp_acp_seid,
{ "ACP SEID", "btvdp.acp_seid",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_int_seid,
{ "INT SEID", "btvdp.int_seid",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_codec,
{ "Codec", "btvdp.codec",
FT_UINT8, BASE_HEX, VALS(media_codec_video_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_btvdp_vendor_id,
{ "Vendor ID", "btvdp.codec.vendor.vendor_id",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &bluetooth_company_id_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_vendor_codec_id,
{ "Vendor Codec", "btvdp.codec.vendor.codec_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_content_protection,
{ "Content Protection", "btvdp.content_protection",
FT_UINT16, BASE_HEX, VALS(content_protection_type_vals), 0x0000,
NULL, HFILL }
},
{ &hf_btvdp_stream_start_in_frame,
{ "Stream Start in Frame", "btvdp.stream_start_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_stream_end_in_frame,
{ "Stream End in Frame", "btvdp.stream_end_in_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_btvdp_stream_number,
{ "Stream Number", "btvdp.stream_number",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btvdp
};
static ei_register_info ei[] = {
{ &ei_btavdtp_sbc_min_bitpool_out_of_range, { "btavdtp.codec.sbc.minimum_bitpool.out_of_range", PI_PROTOCOL, PI_WARN, "Bitpool is out of range. Should be 2..250.", EXPFILL }},
{ &ei_btavdtp_sbc_max_bitpool_out_of_range, { "btavdtp.codec.sbc.maximum_bitpool.out_of_range", PI_PROTOCOL, PI_WARN, "Bitpool is out of range. Should be 2..250.", EXPFILL }},
{ &ei_btavdtp_unexpected_losc_data, { "btavdtp.unexpected_losc_data", PI_PROTOCOL, PI_WARN, "Unexpected losc data", EXPFILL }},
};
proto_btvdp = proto_register_protocol("Bluetooth VDP Profile", "BT VDP", "btvdp");
btvdp_handle = register_dissector("btvdp", dissect_btvdp, proto_btvdp);
proto_register_field_array(proto_btvdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_btavdtp = expert_register_protocol(proto_btvdp);
expert_register_field_array(expert_btavdtp, ei, array_length(ei));
module = prefs_register_protocol(proto_btvdp, NULL);
prefs_register_static_text_preference(module, "vdp.version",
"Bluetooth Profile VDP version: 1.1",
"Version of profile supported by this dissector.");
prefs_register_bool_preference(module, "vdp.content_protection.scms_t",
"Force SCMS-T decoding",
"Force decoding stream as VDP with Content Protection SCMS-T ",
&force_vdp_scms_t);
prefs_register_enum_preference(module, "vdp.codec",
"Force codec",
"Force decoding stream as VDP with specified codec",
&force_vdp_codec, pref_vdp_codec, FALSE);
}
void
proto_reg_handoff_btvdp(void)
{
h263_handle = find_dissector_add_dependency("h263", proto_btvdp);
mp4v_es_handle = find_dissector_add_dependency("mp4v-es", proto_btvdp);
rtp_handle = find_dissector_add_dependency("rtp", proto_btvdp);
dissector_add_string("bluetooth.uuid", "1303", btvdp_handle);
dissector_add_string("bluetooth.uuid", "1304", btvdp_handle);
dissector_add_string("bluetooth.uuid", "1305", btvdp_handle);
dissector_add_for_decode_as("btl2cap.cid", btvdp_handle);
}
static gint
dissect_a2dp_cp_scms_t(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *main_item;
proto_tree *main_tree;
gint offset = 0;
main_item = proto_tree_add_item(tree, proto_bta2dp_cph_scms_t, tvb, offset, 1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_bta2dp_cph_scms_t);
proto_tree_add_item(main_tree, hf_bta2dp_reserved , tvb, offset, 1, ENC_NA);
proto_tree_add_item(main_tree, hf_bta2dp_cp_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(main_tree, hf_bta2dp_l_bit , tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
void
proto_register_bta2dp_content_protection_header_scms_t(void)
{
static hf_register_info hf[] = {
{ &hf_bta2dp_l_bit,
{ "L-bit", "bta2dp.content_protection_header.scms_t.l_bit",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_bta2dp_cp_bit,
{ "Cp-bit", "bta2dp.content_protection_header.scms_t.cp_bit",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_bta2dp_reserved,
{ "Reserved", "bta2dp.content_protection_header.scms_t.reserved",
FT_BOOLEAN, 8, NULL, 0xFC,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_bta2dp_cph_scms_t
};
proto_bta2dp_cph_scms_t = proto_register_protocol("Bluetooth A2DP Content Protection Header SCMS-T", "BT A2DP Content Protection Header SCMS-T", "bta2dp_content_protection_header_scms_t");
proto_register_field_array(proto_bta2dp_cph_scms_t, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bta2dp_content_protection_header_scms_t", dissect_a2dp_cp_scms_t, proto_bta2dp_cph_scms_t);
}
static gint
dissect_vdp_cp_scms_t(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *main_item;
proto_tree *main_tree;
gint offset = 0;
main_item = proto_tree_add_item(tree, proto_btvdp_cph_scms_t, tvb, offset, 1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_btvdp_cph_scms_t);
proto_tree_add_item(main_tree, hf_btvdp_reserved , tvb, offset, 1, ENC_NA);
proto_tree_add_item(main_tree, hf_btvdp_cp_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(main_tree, hf_btvdp_l_bit , tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
void
proto_register_btvdp_content_protection_header_scms_t(void)
{
static hf_register_info hf[] = {
{ &hf_btvdp_l_bit,
{ "L-bit", "btvdp.content_protection_header.scms_t.l_bit",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_btvdp_cp_bit,
{ "Cp-bit", "btvdp.content_protection_header.scms_t.cp_bit",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_btvdp_reserved,
{ "Reserved", "btvdp.content_protection_header.scms_t.reserved",
FT_BOOLEAN, 8, NULL, 0xFC,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_btvdp_cph_scms_t
};
proto_btvdp_cph_scms_t = proto_register_protocol("Bluetooth VDP Content Protection Header SCMS-T", "BT VDP Content Protection Header SCMS-T", "btvdp_content_protection_header_scms_t");
proto_register_field_array(proto_btvdp_cph_scms_t, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("btvdp_content_protection_header_scms_t", dissect_vdp_cp_scms_t, proto_btvdp_cph_scms_t);
}
