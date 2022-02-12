static const gchar *
my_try_val_to_str_idx(guint32 val, const ext_value_string_t *vs, gint *dec_idx)
{
gint i = 0;
while (vs[i].strptr)
{
if (vs[i].value == val)
{
*dec_idx = vs[i].dec_index;
return(vs[i].strptr);
}
i++;
}
*dec_idx = -1;
return(NULL);
}
static const gchar *ansi_a_so_int_to_str(gint32 so)
{
const gchar *str = try_val_to_str_ext(so, &ansi_a_so_str_vals_ext);
if (str == NULL)
{
if ((so >= 4105) && (so <= 32767))
{
str = "Reserved for standard service options";
}
else
{
str = "Reserved";
}
}
return(str);
}
static void
content_fill_aux(
tvbuff_t *tvb,
proto_tree *tree,
guint32 offset,
guint8 content_len,
guint8 fill_bits,
int hf_content,
int hf_content_fill_bits)
{
proto_tree_add_item(tree, hf_content, tvb, offset, content_len, ENC_NA);
offset += content_len;
if (fill_bits)
{
proto_tree_add_bits_item(tree, hf_content_fill_bits, tvb, (offset - 1)*8, fill_bits-1, ENC_NA);
}
}
static guint8
elem_chan_num(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
curr_offset = offset;
value = tvb_get_ntohs(tvb, curr_offset);
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(tree, hf_ansi_a_channel_number, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (%u)", value);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_16_f800, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_IOS5_channel_number, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (ARFCN: %u)", value & 0x07ff);
break;
}
curr_offset += 2;
return(curr_offset - offset);
}
static guint8
elem_chan_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_speech_or_data_indicator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%s)",
val_to_str_const(oct, ansi_a_speech_or_data_indicator_vals, "Unknown"));
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_chan_rate_and_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (oct == 0x02)
{
proto_tree_add_item(tree, hf_ansi_a_chan_type_data_ext, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_chan_type_data_transparent, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_3f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_ansi_a_speech_enc_or_data_rate, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_return_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_return_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_rf_chan_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_rf_chan_id_color_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_rf_chan_id_n_amps_based, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_rf_chan_id_amps_based, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_rf_chan_id_timeslot, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_16_f800, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_rf_chan_id_channel_number, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (ARFCN: %u)", value & 0x07ff);
curr_offset += 2;
return(curr_offset - offset);
}
static guint8
elem_sr_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_sr_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_sid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_16_8000, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_sid, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (SID: %u)", value & 0x7fff);
curr_offset += 2;
return(curr_offset - offset);
}
static guint8
elem_is95_chan_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint8 num_chans;
guint8 chan_num;
guint32 value;
guint32 curr_offset;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_is95_chan_id_hho, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is95_chan_id_num_chans_add, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format_value(tree, hf_ansi_a_is95_chan_id_frame_offset, tvb, curr_offset, 1,
oct, "%u (%.2f ms)", oct & 0x0f, (oct & 0x0f) * 1.25);
num_chans = (oct & 0x70) >> 4;
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (num_chans > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 4);
chan_num = 0;
do
{
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, 4,
ett_chan_list, NULL, "Channel [%u]", chan_num + 1);
proto_tree_add_item(subtree, hf_ansi_a_is95_chan_id_walsh_code_chan_idx, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_item(subtree, hf_ansi_a_is95_chan_id_pilot_pn, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is95_chan_id_power_combined, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is95_chan_id_freq_incl, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_24_001800, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is95_chan_id_channel_number, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
if (chan_num == 0)
{
value = tvb_get_ntohs(tvb, curr_offset + 1);
proto_item_append_text(data_p->elem_item, " - (ARFCN: %u)", value & 0x07ff);
}
curr_offset += 3;
chan_num++;
}
while (((len - (curr_offset - offset)) >= 4) &&
(chan_num < num_chans));
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_enc_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset, saved_offset;
guint8 num_recs;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
num_recs = 0;
while ((len - (curr_offset - offset)) >= 2)
{
saved_offset = curr_offset;
oct = tvb_get_guint8(tvb, curr_offset);
subtree =
proto_tree_add_subtree_format(tree,
tvb, curr_offset, -1, ett_ansi_enc_info, &item,
"Encryption Info [%u]: %s (%u)",
num_recs + 1,
val_to_str_const((oct & 0x7c) >> 2, ansi_a_enc_info_ident_vals, "Reserved"),
(oct & 0x7c) >> 2);
proto_tree_add_item(subtree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_enc_info_enc_parm_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_enc_info_status, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_enc_info_available, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (oct & 0x80)
{
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(subtree, hf_ansi_a_length, tvb,
curr_offset, 1, oct);
curr_offset++;
if (oct > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct);
proto_tree_add_item(subtree, hf_ansi_a_encryption_parameter_value, tvb, curr_offset, oct, ENC_NA);
curr_offset += oct;
}
}
proto_item_set_len(item, curr_offset - saved_offset);
num_recs++;
}
proto_item_append_text(data_p->elem_item, " - %u record%s", num_recs, plurality(num_recs, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cm_info_type_2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint8 num_bands, band_class_count, band_class_entry_len, p_rev;
guint32 curr_offset;
gint band_class;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_cm2_mob_p_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_10, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_see_list, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_rf_power_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - P_REV (%u)", (oct & 0xe0) >> 5);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_ff, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_cm2_nar_an_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_is95, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_slotted, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_18, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_dtx, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_mobile_term, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_analog_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_ff, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_mobile_term, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cm2_psi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_cm2_scm_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
item =
proto_tree_add_item(tree, hf_ansi_a_cm2_scm, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_scm);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_ext_scm_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_dual_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_slotted, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_meid_configured, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_25MHz_bandwidth, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_transmission, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm2_scm_power_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x10)
{
proto_item_append_text(data_p->elem_item, " (MEID configured)");
data_p->meid_configured = TRUE;
}
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_cm2_scm_band_class_count, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
band_class_count = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_cm2_scm_band_class_entry_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
band_class_entry_len = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (band_class_entry_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), band_class_entry_len);
num_bands = 0;
do
{
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, band_class_entry_len,
ett_cm2_band_class, NULL, "Band Class Entry [%u]", num_bands + 1);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_band_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
band_class = oct & 0x1f;
curr_offset++;
p_rev = tvb_get_guint8(tvb, curr_offset + 1);
if (p_rev < 4)
{
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode0_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode1_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode2_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode3_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode4_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_07, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode0_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode1_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode2_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode3_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode4_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode5_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_opmode6_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_01, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
curr_offset++;
proto_tree_add_item(subtree, hf_ansi_a_scm_band_class_entry_p_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_item_append_text(item, ": (%d)", band_class);
num_bands++;
}
while (((len - (curr_offset - offset)) >= band_class_entry_len) &&
(num_bands < band_class_count));
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_mid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 value;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x07)
{
case 1:
proto_tree_add_item(tree, hf_ansi_a_meid_mid_digit_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (curr_offset - offset >= len)
return (curr_offset - offset);
str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, len - (curr_offset - offset), &Dgt_meid, TRUE);
proto_tree_add_string(tree, hf_ansi_a_meid, tvb, curr_offset, len - (curr_offset - offset), str);
proto_item_append_text(data_p->elem_item, " - MEID (%s)", str);
curr_offset += len - (curr_offset - offset);
break;
case 2:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_mid_broadcast_priority, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_broadcast_message_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_mid_broadcast_zone_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - Broadcast (Zone ID: %u)", oct);
curr_offset++;
value = tvb_get_ntohs(tvb, curr_offset);
str = val_to_str_ext_const(value, &ansi_tsb58_srvc_cat_vals_ext, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_mid_broadcast_srvc_cat, tvb, curr_offset, 2,
value,
"%s (%u)",
str,
value);
curr_offset += 2;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_ext_const(oct, &ansi_tsb58_language_ind_vals_ext, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_mid_broadcast_language, tvb, curr_offset, 1,
oct,
"%s (%u)",
str,
oct);
curr_offset++;
break;
case 5:
proto_tree_add_item(tree, hf_ansi_a_mid_unused, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
value = tvb_get_ntohl(tvb, curr_offset);
proto_tree_add_uint(tree, hf_ansi_a_esn,
tvb, curr_offset, 4,
value);
proto_item_append_text(data_p->elem_item, " - %sESN (0x%04x)",
data_p->meid_configured ? "p" : "",
value);
curr_offset += 4;
break;
case 6:
proto_tree_add_uint_format_value(tree, hf_ansi_a_imsi_mid_digit_1, tvb, curr_offset, 1,
oct, "%c", Dgt_msid.out[(oct & 0xf0) >> 4]);
proto_tree_add_item(tree, hf_ansi_a_mid_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_mid_type_of_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (curr_offset - offset >= len)
return (curr_offset - offset);
str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, len - (curr_offset - offset), &Dgt_msid, TRUE);
proto_tree_add_string_format(tree, hf_ansi_a_imsi, tvb, curr_offset, len - (curr_offset - offset),
str, "BCD Digits: %s", str);
proto_item_append_text(data_p->elem_item, " - IMSI (%s)", str);
if (data_p->message_item)
{
proto_item_append_text(data_p->message_item, " MID=%s", str);
}
if (global_a_info_display)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "MID=%s ", str);
}
curr_offset += len - (curr_offset - offset);
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_ansi_a_unknown_format, tvb, curr_offset, len,
"Mobile Identity ID type, %u, unknown/unsupported",
(oct & 0x07));
proto_item_append_text(data_p->elem_item, " - Format Unknown/Unsupported");
curr_offset += len;
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_sci(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_sci_sign, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format_value(tree, hf_ansi_a_sci, tvb, curr_offset, 1,
oct, "%s%u", (oct & 0x08) ? "-" : "", oct & 0x07);
proto_item_append_text(data_p->elem_item, " - (%s%u)",
(oct & 0x08) ? "-" : "", oct & 0x07);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_prio(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format_value(tree, hf_ansi_a_prio_call_priority, tvb, curr_offset, 1,
oct, "Priority Level %u", (oct & 0x3c) >> 2);
proto_tree_add_item(tree, hf_ansi_a_prio_queue_allowed, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_prio_preempt_allowed, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (%u)", (oct & 0x3c) >> 2);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_p_rev(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_mob_p_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x80)
{
proto_tree_add_item(tree, hf_ansi_a_cause_2_ext, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cause_2, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
}
else
{
proto_tree_add_item(tree, hf_ansi_a_cause_1_ext, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
str = val_to_str_ext_const(oct & 0x7f, &ansi_a_elem_cause_vals_ext, "Reserved for future use");
proto_tree_add_uint_format_value(tree, hf_ansi_a_cause_1, tvb, curr_offset, 1, oct,
"%s (%u)", str, oct & 0x7f);
proto_item_append_text(data_p->elem_item, " - (%u) %s", oct & 0x7f, str);
curr_offset++;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cell_id_aux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, guint8 disc, proto_item *parent_item_p)
{
guint32 value;
guint32 market_id;
guint32 switch_num;
guint32 curr_offset;
curr_offset = offset;
switch (disc)
{
case 0x02:
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint(tree, hf_ansi_a_cell_ci, tvb, curr_offset, 2, value);
curr_offset += 2;
if (parent_item_p)
{
proto_item_append_text(parent_item_p, " - CI (%u)", value);
}
break;
case 0x05:
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint(tree, hf_ansi_a_cell_lac, tvb, curr_offset, 2, value);
curr_offset += 2;
if (parent_item_p)
{
proto_item_append_text(parent_item_p, " - LAC (%u)", value);
}
break;
case 0x07:
market_id = tvb_get_ntohs(tvb, curr_offset);
switch_num = tvb_get_guint8(tvb, curr_offset + 2);
value = tvb_get_ntoh24(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_ansi_a_cell_mscid, tvb, curr_offset, 3,
value,
"Market ID %u Switch Number %u",
market_id, switch_num);
curr_offset += 3;
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint(tree, hf_ansi_a_cell_ci, tvb, curr_offset, 2, value);
curr_offset += 2;
if (parent_item_p)
{
proto_item_append_text(parent_item_p, " - Market ID (%u) Switch Number (%u) CI (%u)",
market_id, switch_num, value);
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_ansi_a_unknown_format, tvb, curr_offset, len,
"Cell ID - Non IOS format");
curr_offset += len;
break;
}
return(curr_offset - offset);
}
static guint8
elem_cell_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
curr_offset +=
elem_cell_id_aux(tvb, pinfo, tree, curr_offset, len - (curr_offset - offset), oct, data_p->elem_item);
return(curr_offset - offset);
}
static guint8
elem_cell_id_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint16 consumed;
guint8 num_cells;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
NO_MORE_DATA_CHECK(len);
num_cells = 0;
do
{
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_cell_list, &item, "Cell [%u]", num_cells + 1);
consumed =
elem_cell_id_aux(tvb, pinfo, subtree, curr_offset, len - (curr_offset - offset), oct, item);
proto_item_set_len(item, consumed);
curr_offset += consumed;
num_cells++;
}
while ((len - (curr_offset - offset)) > 0);
proto_item_append_text(data_p->elem_item, " - %u cell%s", num_cells, plurality(num_cells, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cic(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
item =
proto_tree_add_item(tree, hf_ansi_a_cic, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_cic);
proto_tree_add_item(subtree, hf_ansi_a_cic_pcm_multi, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cic_timeslot, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u) (0x%04x)", value, value);
curr_offset += 2;
return(curr_offset - offset);
}
static guint8
elem_cic_ext(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 value;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
const gchar *str;
curr_offset = offset;
item =
proto_tree_add_item(tree, hf_ansi_a_cic_ext_cic, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_cic);
proto_tree_add_item(subtree, hf_ansi_a_cic_ext_pcm_multi, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cic_ext_timeslot, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u) (0x%04x)", value, value);
curr_offset += 2;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x0f)
{
case 0x00: str = "Full-rate"; break;
default:
str = "Reserved";
break;
}
proto_tree_add_uint_format_value(tree, hf_ansi_a_cic_ext_circuit_mode, tvb, curr_offset, 1,
oct, "%s (%u)", str, oct);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_ssci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ssci_mopd, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ssci_geci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_downlink_re_aux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, proto_item *parent_item_p)
{
guint8 disc;
guint16 consumed;
guint8 num_cells;
guint8 curr_cell;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_downlink_re_num_cells, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
num_cells = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
disc = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
curr_cell = 0;
do
{
SHORT_DATA_CHECK(len - (curr_offset - offset), (guint32) 3 + ANSI_A_CELL_ID_LEN(disc));
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_cell_list, &item, "Cell [%u]", curr_cell + 1);
consumed =
elem_cell_id_aux(tvb, pinfo, subtree, curr_offset, len - (curr_offset - offset), disc, item);
proto_item_set_len(item, consumed);
curr_offset += consumed;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_downlink_re_sig_str_raw, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_item(tree, hf_ansi_a_downlink_re_cdma_towd, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_cell++;
}
while (curr_cell < num_cells);
proto_item_append_text(parent_item_p, " - %u cell%s", num_cells, plurality(num_cells, "", "s"));
return(curr_offset - offset);
}
static guint8
elem_downlink_re(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset +=
elem_downlink_re_aux(tvb, pinfo, tree, offset, len, data_p->elem_item);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_downlink_re_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint8 num_envs;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
num_envs = 0;
while ((len - (curr_offset - offset)) > 0)
{
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_re_list, &item, "Environment [%u]",
num_envs + 1);
proto_tree_add_item(subtree, hf_ansi_a_downlink_re_entry_env_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
consumed =
elem_downlink_re_aux(tvb, pinfo, subtree, curr_offset, len - (curr_offset - offset), item);
proto_item_set_len(item, consumed + 1);
curr_offset += consumed;
num_envs++;
}
proto_item_append_text(data_p->elem_item, " - %u environment%s", num_envs, plurality(num_envs, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_pdsn_ip_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_pdsn_ip_addr, tvb, curr_offset, len, ENC_BIG_ENDIAN);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_s_pdsn_ip_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_s_pdsn_ip_addr, tvb, curr_offset, len, ENC_BIG_ENDIAN);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_ho_pow_lev(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint8 num_cells;
proto_item *item;
proto_tree *subtree;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_ho_pow_lev_num_cells, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
SHORT_DATA_CHECK(len - (curr_offset - offset), (guint32) 6);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ho_pow_lev_id_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ho_pow_lev_pow_lev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_cell_list, &item, "Cell [1]");
consumed =
elem_cell_id_aux(tvb, pinfo, subtree, curr_offset, len - (curr_offset - offset), 0x7, item);
proto_item_set_len(item, consumed);
curr_offset += consumed;
num_cells = 0;
while ((len - (curr_offset - offset)) >= 3)
{
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ho_pow_lev_pow_lev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_cell_list, &item, "Cell [%u]", num_cells + 1);
consumed =
elem_cell_id_aux(tvb, pinfo, subtree, curr_offset, len - (curr_offset - offset), 0x2, item);
proto_item_set_len(item, consumed);
curr_offset += consumed;
num_cells++;
}
proto_item_append_text(data_p->elem_item, " - %u cell%s", num_cells, plurality(num_cells, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_uz_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_uz_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
value = tvb_get_ntohs(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", value);
curr_offset += 2;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_info_rec_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
guint8 num_recs;
const gchar *str;
curr_offset = offset;
num_recs = 0;
while ((len - (curr_offset - offset)) > 0)
{
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const((guint32) oct, ansi_rev_ms_info_rec_str, "Reserved");
proto_tree_add_uint_format(tree, hf_ansi_a_info_rec_req, tvb, curr_offset, 1,
oct,
"Information Record Type - %u: %s (%u)",
num_recs + 1, str, oct);
curr_offset++;
num_recs++;
}
proto_item_append_text(data_p->elem_item, " - %u request%s", num_recs, plurality(num_recs, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is2000_chan_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint8 num_chans;
guint8 chan_num;
guint32 curr_offset;
proto_tree *subtree;
const gchar *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_otd, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_chan_count, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format_value(tree, hf_ansi_a_is2000_chan_id_frame_offset, tvb, curr_offset, 1,
oct, "%u (%.2f ms)", oct & 0x0f, (oct & 0x0f) * 1.25);
num_chans = (oct & 0x70) >> 4;
curr_offset++;
NO_MORE_DATA_CHECK(len);
SHORT_DATA_CHECK(len - (curr_offset - offset), 6);
chan_num = 0;
do
{
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 6,
ett_chan_list, NULL, "Channel [%u]", chan_num + 1);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x01: str = "Fundamental Channel (FCH) TIA/EIA/IS-2000"; break;
case 0x02: str = "Dedicated Control Channel (DCCH) TIA/EIA/IS-2000"; break;
case 0x03: str = "Supplemental Channel (SCH) TIA/EIA/IS-2000"; break;
default:
str = "Reserved";
break;
}
proto_tree_add_uint_format_value(subtree, hf_ansi_a_is2000_chan_id_chan_chan_type, tvb, curr_offset, 1,
oct, "%s", str);
curr_offset += 1;
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_16_8000, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_rev_fch_gating, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_rev_pilot_gating_rate, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_qof_mask, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_walsh_code_chan_idx, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_expert(subtree, pinfo, &ei_ansi_a_is2000_chan_id_pilot_pn, tvb, curr_offset, 2);
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_pilot_pn_code, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_24_007000, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_24_006000, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_power_combined, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_freq_incl, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_chan_id_chan_channel_number, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
chan_num++;
}
while (((len - (curr_offset - offset)) >= 6) &&
(chan_num < num_chans));
switch (global_a_variant)
{
case A_VARIANT_IOS501:
SHORT_DATA_CHECK(len - (curr_offset - offset), 5);
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_chan_fdc_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_chan_fdc_band_class, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_chan_fdc_fwd_chan_freq, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_chan_id_chan_fdc_rev_chan_freq, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_16_001f, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is95_ms_meas_chan_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_is95_ms_meas_chan_id_band_class, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is95_ms_meas_chan_id_channel_number, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (ARFCN: %u)", tvb_get_ntohs(tvb, curr_offset) & 0x07ff);
curr_offset += 2;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_auth_conf_param(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_auth_conf_param_randc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_clg_party_ascii_num(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
guint8 *poctets;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_ascii_num_ton, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_ascii_num_plan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
if (!(oct & 0x80))
{
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_ascii_num_pi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_1c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_ascii_num_si, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
poctets = tvb_get_string_enc(wmem_packet_scope(), tvb, curr_offset, len - (curr_offset - offset), ENC_ASCII|ENC_NA);
proto_tree_add_string_format(tree, hf_ansi_a_clg_party_ascii_num, tvb, curr_offset, len - (curr_offset - offset),
(gchar *) poctets,
"Digits: %s",
(gchar *) format_text(poctets, len - (curr_offset - offset)));
proto_item_append_text(data_p->elem_item, " - (%s)", poctets);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_l3_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
tvbuff_t *l3_tvb;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_layer3_info, tvb, curr_offset, len, ENC_NA);
l3_tvb = tvb_new_subset_length(tvb, curr_offset, len);
call_dissector(dtap_handle, l3_tvb, pinfo, data_p->g_tree);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_lai(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint32 curr_offset;
gchar mcc[4];
gchar mnc[4];
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
mcc[0] = Dgt_tbcd.out[oct & 0x0f];
mcc[1] = Dgt_tbcd.out[(oct & 0xf0) >> 4];
oct = tvb_get_guint8(tvb, curr_offset+1);
mcc[2] = Dgt_tbcd.out[(oct & 0x0f)];
mcc[3] = '\0';
proto_tree_add_string(tree, hf_ansi_a_lai_mcc, tvb, curr_offset, 2, mcc);
mnc[2] = Dgt_tbcd.out[(oct & 0xf0) >> 4];
oct = tvb_get_guint8(tvb, curr_offset+2);
mnc[0] = Dgt_tbcd.out[(oct & 0x0f)];
mnc[1] = Dgt_tbcd.out[(oct & 0xf0) >> 4];
mnc[3] = '\0';
proto_tree_add_string(tree, hf_ansi_a_lai_mnc, tvb, curr_offset + 1, 2, mnc);
curr_offset += 3;
proto_tree_add_item(tree, hf_ansi_a_lai_lac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
return(curr_offset - offset);
}
static guint8
elem_rej_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct, ansi_a_rej_cause_vals, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_rej_cause, tvb, curr_offset, 1,
oct, "%s (%u)", str, oct);
if (data_p->message_item)
{
proto_item_append_text(data_p->message_item, " - (%s)", str);
}
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_anchor_pdsn_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_anchor_ip_addr, tvb, curr_offset, len, ENC_BIG_ENDIAN);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_anchor_pp_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_anchor_pp_ip_addr, tvb, curr_offset, len, ENC_BIG_ENDIAN);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_auth_chlg_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct & 0x0F, ansi_a_auth_chlg_param_rand_num_type_vals, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_auth_chlg_param_rand_num_type, tvb, curr_offset, 1,
oct, "%s (%u)", str, oct & 0x0f);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_auth_chlg_param_rand, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_auth_resp_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct & 0x0F, ansi_a_auth_resp_param_sig_type_vals, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_auth_resp_param_sig_type, tvb, curr_offset, 1,
oct, "%s (%u)", str, oct & 0x0f);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_auth_resp_param_sig, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_auth_param_count(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_auth_param_count_count, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct & 0x3f);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_mwi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_mwi_num_messages, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_signal(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct, ansi_a_signal_signal_vals, "Unknown");
proto_tree_add_item(tree, hf_ansi_a_signal_signal_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_signal_alert_pitch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_cld_party_bcd_num(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
const char *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_bcd_num_ton, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_clg_party_bcd_num_plan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (curr_offset - offset >= len)
return (curr_offset - offset);
str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, len - (curr_offset - offset), &Dgt_tbcd, FALSE);
proto_tree_add_string(tree, hf_ansi_a_cld_party_bcd_num, tvb, curr_offset, len - (curr_offset - offset), str);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_qos_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_qos_params_packet_priority, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct & 0x0f);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cause_l3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str = NULL;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cause_l3_coding_standard, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_10, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cause_l3_location, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cause_l3_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cause_l3_value_without_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_ext_const(oct & 0x7f, &ansi_a_cause_l3_value_vals_ext, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_cause_l3_value, tvb, curr_offset, 1,
oct & 0x7f, "%s (%u)", str, oct & 0x7f);
proto_item_append_text(data_p->elem_item, " - (%u) %s", oct & 0x7f, str);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_xmode(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fe, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_ansi_a_xmode_tfo_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (%s)",
(oct & 0x01) ? tfs_ansi_a_xmode_tfo_mode.true_string : tfs_ansi_a_xmode_tfo_mode.false_string);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_reg_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct, ansi_a_reg_type_type_vals, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_reg_type_type, tvb, curr_offset, 1,
oct, "%s", str);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_tag(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_tag_value, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
value = tvb_get_ntohl(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", value);
curr_offset += 4;
return(curr_offset - offset);
}
static guint8
elem_hho_params(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_band_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const(oct & 0x1f, ansi_a_band_class_vals, "Reserved");
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_hho_params_num_pream_frames, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_reset_l2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_reset_fpc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_enc_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_private_lcm, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(tree, hf_ansi_a_hho_params_rev_pwr_cntl_delay_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_rev_pwr_cntl_delay, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(tree, hf_ansi_a_hho_params_nom_pwr_ext, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_nom_pwr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_fpc_subchan_info, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_fpc_subchan_info_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_pwr_cntl_step, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_hho_params_pwr_cntl_step_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_sw_ver(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 major, minor, point;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_sw_ver_major, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
major = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_sw_ver_minor, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
minor = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_sw_ver_point, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
point = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (IOS %u.%u.%u)", major, minor, point);
curr_offset++;
if (len > 3)
{
proto_tree_add_item(tree, hf_ansi_a_manufacturer_software_info, tvb, curr_offset, len - 3, ENC_NA);
curr_offset += len - 3;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_so_aux(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, guint16 *value_p)
{
proto_tree_add_item(tree, hf_ansi_a_so_proprietary_ind, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_so_revision, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_so_base_so_num, tvb, offset, 2, ENC_BIG_ENDIAN);
*value_p = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_a_so, tvb, offset, 2,
*value_p,
"%s",
ansi_a_so_int_to_str(*value_p));
return(2);
}
static guint8
elem_so(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 value;
guint32 curr_offset;
curr_offset = offset + elem_so_aux(tvb, pinfo, tree, offset, len, &value);
proto_item_append_text(data_p->elem_item, " - (%u) %s", value, ansi_a_so_int_to_str(value));
if (data_p->message_item)
{
proto_item_append_text(data_p->message_item, " - SO (%u)", value);
}
if (global_a_info_display)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "- SO (%u)", value);
}
return(curr_offset - offset);
}
static guint8
elem_soci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_soci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%u)", oct);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_so_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 num_so;
guint8 inst;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_so_list_num, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
num_so = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - %u service options", num_so);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
SHORT_DATA_CHECK(len - (curr_offset - offset), 3);
inst = 0;
do
{
guint16 value;
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, 3,
ett_so_list, &item, "Service Option [%u]",
inst + 1);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_so_list_sr_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_so_list_soci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
curr_offset += elem_so_aux(tvb, pinfo, subtree, curr_offset, len, &value);
proto_item_append_text(item, " - (%u) %s", value, ansi_a_so_int_to_str(value));
inst++;
}
while (((len - (curr_offset - offset)) >= 3) &&
(inst < num_so));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_acc_net_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 sid, nid, pzid;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_16_8000, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_sid, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_nid, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_pzid, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
sid = tvb_get_ntohs(tvb, curr_offset) & 0x7fff;
curr_offset += 2;
nid = tvb_get_ntohs(tvb, curr_offset);
curr_offset += 2;
pzid = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (SID/NID/PZID: %u/%u/%u)", sid, nid, pzid);
curr_offset += 1;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_adds_user_part(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
tvbuff_t *adds_tvb;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_adds_user_part_burst_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%s)",
val_to_str_const(oct & 0x3f, ansi_a_adds_vals, "Reserved"));
curr_offset++;
subtree = proto_tree_add_subtree(tree, tvb, curr_offset, len - 1, ett_adds_user_part, NULL, "Application Data Message");
switch (oct & 0x3f)
{
case ADDS_APP_SMS:
adds_tvb = tvb_new_subset_length(tvb, curr_offset, len - 1);
dissector_try_uint(is637_dissector_table, 0, adds_tvb, pinfo, data_p->g_tree);
curr_offset += (len - 1);
break;
case ADDS_APP_OTA:
adds_tvb = tvb_new_subset_length(tvb, curr_offset, len - 1);
dissector_try_uint(is683_dissector_table, data_p->is_reverse, adds_tvb, pinfo, data_p->g_tree);
curr_offset += (len - 1);
break;
case ADDS_APP_PDS:
adds_tvb = tvb_new_subset_length(tvb, curr_offset, len - 1);
dissector_try_uint(is801_dissector_table, data_p->is_reverse, adds_tvb, pinfo, data_p->g_tree);
curr_offset += (len - 1);
break;
case ADDS_APP_SDB:
curr_offset += (len - 1);
break;
case ADDS_APP_EXT_INTL:
case ADDS_APP_EXT:
proto_tree_add_item(subtree, hf_ansi_a_adds_user_part_ext_burst_type, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(subtree, hf_ansi_a_adds_user_part_ext_data, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
curr_offset += len - (curr_offset - offset);
break;
default:
proto_tree_add_item(subtree, hf_ansi_a_adds_user_part_unknown_data, tvb, curr_offset, len - 1, ENC_NA);
curr_offset += (len - 1);
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_amps_hho_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_amps_hho_params_enc_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is2000_scr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct, num_con_rec, ii;
guint8 bit_mask, bit_offset;
guint32 curr_offset, saved_offset;
guint32 value;
guint is2000_portion_len;
proto_tree *scr_subtree, *subtree;
const gchar *str = NULL;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_scr_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
is2000_portion_len = len - (curr_offset - offset);
SHORT_DATA_CHECK(is2000_portion_len, 7);
saved_offset = curr_offset;
scr_subtree = proto_tree_add_subtree(tree, tvb, curr_offset, is2000_portion_len,
ett_scr, NULL, "IS-2000 Service Configuration Record Content");
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_for_mux_option, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_rev_mux_option, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_for_fch_rate, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_rev_fch_rate, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_num_socr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
num_con_rec = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
for (ii=0; ii < num_con_rec; ii++)
{
oct = tvb_get_guint8(tvb, curr_offset);
subtree = proto_tree_add_subtree_format(scr_subtree, tvb,
curr_offset, oct ,
ett_scr_socr, NULL, "Service option connection record [%u]", ii+1);
curr_offset += 1;
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_soc_ref, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint_format_value(subtree, hf_ansi_a_is2000_scr_socr_so, tvb, curr_offset, 2,
value,
"%s (%u)",
ansi_a_so_int_to_str(value), value);
curr_offset += 2;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const((oct & 0xf0) >> 4, ansi_a_is2000_scr_socr_for_chan_type_vals, "Reserved");
proto_tree_add_uint_format_value(subtree, hf_ansi_a_is2000_scr_socr_for_chan_type, tvb, curr_offset, 1,
oct, "Forward Traffic Channel traffic type, %s", str);
str = val_to_str_const(oct & 0x0f, ansi_a_is2000_scr_socr_rev_chan_type_vals, "Reserved");
proto_tree_add_uint_format_value(subtree, hf_ansi_a_is2000_scr_socr_rev_chan_type, tvb, curr_offset, 1,
oct, "Reverse Traffic Channel traffic type, %s", str);
curr_offset += 1;
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_ui_enc_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_sr_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_rlp_info_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x02)
{
value = (oct & 0x01) << 3;
curr_offset += 1;
oct = tvb_get_guint8(tvb, curr_offset);
value |= (oct & 0xe0) >> 5;
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_rlp_blob_len, tvb, curr_offset - 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_rlp_blob_msb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
if (value > 1)
{
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_rlp_blob, tvb, curr_offset, value - 1, ENC_NA);
curr_offset += value - 1;
}
proto_tree_add_item(subtree, hf_ansi_a_is2000_scr_socr_rlp_blob_lsb, tvb, curr_offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_1f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_01, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
curr_offset += 1;
}
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_socr_fch_cc_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x80)
{
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_socr_fch_frame_size_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_socr_for_fch_rc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(scr_subtree, hf_ansi_a_is2000_scr_socr_rev_fch_rc, tvb, curr_offset - 1, 2, ENC_BIG_ENDIAN);
bit_mask = 0x08;
bit_offset = 3;
}
else
{
bit_offset = 6;
bit_mask = 0x40;
}
proto_tree_add_bits_item(scr_subtree, hf_ansi_a_dcch_cc_incl, tvb, (curr_offset*8)+(8-bit_offset), 1, ENC_NA);
if (oct & bit_mask)
{
proto_tree_add_expert_format(scr_subtree, pinfo, &ei_ansi_a_undecoded, tvb, curr_offset, (is2000_portion_len - (curr_offset - saved_offset)), "DCCH + ? + Reserved");
curr_offset += (is2000_portion_len - (curr_offset - saved_offset));
}
else
{
bit_mask >>= 1;
bit_offset--;
proto_tree_add_bits_item(scr_subtree, hf_ansi_a_for_sch_cc_incl, tvb, (curr_offset*8)+(8-bit_offset), 1, ENC_NA);
if (oct & bit_mask)
{
proto_tree_add_expert_format(scr_subtree, pinfo, &ei_ansi_a_undecoded, tvb, curr_offset, (is2000_portion_len - (curr_offset - saved_offset)), "FOR_SCH + ? + Reserved");
curr_offset += (is2000_portion_len - (curr_offset - saved_offset));
}
else
{
bit_mask >>= 1;
bit_offset--;
proto_tree_add_bits_item(scr_subtree, hf_ansi_a_rev_sch_cc_incl, tvb, (curr_offset*8)+(8-bit_offset), 1, ENC_NA);
if (oct & bit_mask)
{
proto_tree_add_expert_format(scr_subtree, pinfo, &ei_ansi_a_undecoded, tvb, curr_offset, (is2000_portion_len - (curr_offset - saved_offset)), "REV_SCH + ? + Reserved");
curr_offset += (is2000_portion_len - (curr_offset - saved_offset));
}
else
{
proto_tree_add_bits_item(scr_subtree, hf_ansi_a_reserved_bits_8_generic, tvb, (curr_offset*8)+(8-bit_offset), bit_offset, ENC_NA);
curr_offset += 1;
}
}
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is2000_nn_scr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
guint is2000_portion_len;
guint8 fill_bits;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_nn_scr_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
fill_bits = tvb_get_guint8(tvb, curr_offset) & 0x07;
curr_offset++;
NO_MORE_DATA_CHECK(len);
is2000_portion_len = len - (curr_offset - offset);
if (is2000_portion_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), is2000_portion_len);
content_fill_aux(tvb, tree, curr_offset, is2000_portion_len, fill_bits,
hf_ansi_a_is2000_nn_scr_content,
hf_ansi_a_is2000_nn_scr_fill_bits);
curr_offset += is2000_portion_len;
NO_MORE_DATA_CHECK(len);
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is2000_mob_cap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint8 oct_len;
guint32 curr_offset;
guint8 fill_bits;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_rev_pdch_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_for_pdch_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_eram_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_dcch_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_fch_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_otd_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_enh_rc_cfg_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_qpch_support_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_fch_info_octet_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct_len = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_fch_info_geo_loc_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_fch_info_geo_loc_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_fch_info_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
fill_bits = tvb_get_guint8(tvb, curr_offset) & 0x07;
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
subtree =
proto_tree_add_subtree(tree, tvb, curr_offset, oct_len,
ett_is2000_mob_cap_fch_info, NULL, "FCH Information");
content_fill_aux(tvb, subtree, curr_offset, oct_len, fill_bits,
hf_ansi_a_is2000_mob_cap_fch_info_content,
hf_ansi_a_is2000_mob_cap_fch_info_fill_bits);
curr_offset += oct_len;
}
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_dcch_info_octet_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct_len = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_dcch_info_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
fill_bits = tvb_get_guint8(tvb, curr_offset) & 0x07;
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
subtree = proto_tree_add_subtree(tree, tvb, curr_offset, oct_len,
ett_is2000_mob_cap_dcch_info, NULL, "DCCH Information");
content_fill_aux(tvb, subtree, curr_offset, oct_len, fill_bits,
hf_ansi_a_is2000_mob_cap_dcch_info_content,
hf_ansi_a_is2000_mob_cap_dcch_info_fill_bits);
curr_offset += oct_len;
}
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_for_pdch_info_octet_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct_len = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_for_pdch_info_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
fill_bits = tvb_get_guint8(tvb, curr_offset) & 0x07;
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
subtree = proto_tree_add_subtree(tree, tvb, curr_offset, oct_len,
ett_is2000_mob_cap_for_pdch_info, NULL, "FOR_PDCH Information");
content_fill_aux(tvb, subtree, curr_offset, oct_len, fill_bits,
hf_ansi_a_is2000_mob_cap_for_pdch_info_content,
hf_ansi_a_is2000_mob_cap_for_pdch_info_fill_bits);
curr_offset += oct_len;
}
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_rev_pdch_info_octet_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct_len = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_is2000_mob_cap_rev_pdch_info_num_fill_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
fill_bits = tvb_get_guint8(tvb, curr_offset) & 0x07;
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
subtree = proto_tree_add_subtree(tree, tvb, curr_offset, oct_len,
ett_is2000_mob_cap_rev_pdch_info, NULL, "REV_PDCH Information");
content_fill_aux(tvb, subtree, curr_offset, oct_len, fill_bits,
hf_ansi_a_is2000_mob_cap_rev_pdch_info_content,
hf_ansi_a_is2000_mob_cap_rev_pdch_info_fill_bits);
curr_offset += oct_len;
}
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
item = proto_tree_add_uint_format(tree, hf_ansi_a_is2000_mob_cap_vp_support, tvb, curr_offset, 1,
oct & 0x7f,
"VP Algorithms Supported%s",
(oct & 0x7f) ? "" : ": No voice privacy supported");
if (oct & 0x7f)
{
subtree = proto_item_add_subtree(item, ett_vp_algs);
proto_tree_add_item(subtree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_is2000_mob_cap_vp_support_a1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_ptype(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 value;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
value = tvb_get_ntohs(tvb, curr_offset);
switch (value)
{
case 0x880b: str = "PPP"; break;
case 0x8881: str = "Unstructured Byte Stream"; break;
default:
str = "Unknown";
break;
}
proto_tree_add_uint_format(tree, hf_ansi_a_protocol_type, tvb, curr_offset, 2,
value,
"%s (%u)",
str, value);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset += 2;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_fwd_ms_info_recs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint8 oct_len;
guint8 rec_type;
guint8 num_recs;
guint32 value;
guint32 curr_offset, saved_offset;
const gchar *str;
gchar *str_num;
gint ett_elem_idx, idx, i;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
num_recs = 0;
while ((len - (curr_offset - offset)) >= 2)
{
saved_offset = curr_offset;
rec_type = tvb_get_guint8(tvb, curr_offset);
str = try_val_to_str_idx((guint32) rec_type, ansi_fwd_ms_info_rec_str, &idx);
if (str == NULL)
{
str = "Reserved";
ett_elem_idx = ett_ansi_ms_info_rec_reserved;
}
else
{
ett_elem_idx = ett_ansi_fwd_ms_info_rec[idx];
}
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_elem_idx, &item,
"Information Record Type [%u]: (%u) %s",
num_recs + 1,
rec_type,
str);
curr_offset++;
oct_len = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(subtree, hf_ansi_a_length, tvb, curr_offset, 1, oct_len);
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
switch (rec_type)
{
case ANSI_FWD_MS_INFO_REC_CLD_PN:
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_cld_pn_num_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_cld_pn_num_plan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (oct_len > 1)
{
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(subtree, hf_ansi_a_msb_first_digit, tvb, (curr_offset*8)+7, 1, ENC_NA);
curr_offset++;
str_num = (gchar*)wmem_alloc(wmem_packet_scope(), oct_len);
for (i=0; i < (oct_len - 1); i++)
{
str_num[i] = (oct & 0x01) << 7;
oct = tvb_get_guint8(tvb, curr_offset + i);
str_num[i] |= (oct & 0xfe) >> 1;
}
str_num[i] = '\0';
proto_tree_add_string_format(subtree, hf_ansi_a_fwd_ms_info_rec_cld_pn_num, tvb,
curr_offset, oct_len - 1, str_num, "Digits: %s", str_num);
curr_offset += (oct_len - 2);
}
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_01, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
case ANSI_FWD_MS_INFO_REC_CLG_PN:
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_clg_pn_num_type, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_clg_pn_num_plan, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_clg_pn_pi, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_clg_pn_si, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
if (oct_len > 2)
{
value = tvb_get_ntohs(tvb, curr_offset);
oct = (value & 0x00ff);
proto_tree_add_bits_item(subtree, hf_ansi_a_msb_first_digit, tvb, (curr_offset*8)+11, 5, ENC_NA);
curr_offset += 2;
str_num = (gchar*)wmem_alloc(wmem_packet_scope(), oct_len - 1);
for (i=0; i < (oct_len - 2); i++)
{
str_num[i] = (oct & 0x1f) << 3;
oct = tvb_get_guint8(tvb, curr_offset + i);
str_num[i] |= (oct & 0xe0) >> 5;
}
str_num[i] = '\0';
proto_tree_add_string_format(subtree, hf_ansi_a_fwd_ms_info_rec_clg_pn_num, tvb,
curr_offset, oct_len - 2, str_num, "Digits: %s", str_num);
curr_offset += (oct_len - 3);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_1f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
else
{
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_16_001f, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
}
break;
case ANSI_FWD_MS_INFO_REC_MW:
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_mw_num, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
case ANSI_FWD_MS_INFO_REC_SIGNAL:
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_signal_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_signal_alert_pitch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0xc0)
{
case 0x00:
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_signal_tone, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
case 0x40:
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_signal_isdn_alert, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
case 0x80:
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_signal_is54b_alert, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_16_003f, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += oct_len;
break;
case ANSI_FWD_MS_INFO_REC_CWI:
proto_tree_add_item(subtree, hf_ansi_a_ms_info_rec_call_waiting_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_7f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += oct_len;
break;
default:
proto_tree_add_item(subtree, hf_ansi_a_fwd_ms_info_rec_content, tvb, curr_offset, oct_len, ENC_NA);
curr_offset += oct_len;
break;
}
}
proto_item_set_len(item, curr_offset - saved_offset);
num_recs++;
}
proto_item_append_text(data_p->elem_item, " - %u record%s", num_recs, plurality(num_recs, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_rev_ms_info_recs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint8 oct_len;
guint8 rec_type;
guint8 num_recs;
guint32 value;
guint32 curr_offset, saved_offset, saved_offset2;
const gchar *str;
gchar *str_num;
gint ett_elem_idx, idx, i;
proto_item *item, *item2;
proto_tree *subtree, *subtree2;
guint8 *poctets;
curr_offset = offset;
num_recs = 0;
while ((len - (curr_offset - offset)) >= 2)
{
saved_offset = curr_offset;
rec_type = tvb_get_guint8(tvb, curr_offset);
str = try_val_to_str_idx((guint32) rec_type, ansi_rev_ms_info_rec_str, &idx);
if (str == NULL)
{
str = "Reserved";
ett_elem_idx = ett_ansi_ms_info_rec_reserved;
}
else
{
ett_elem_idx = ett_ansi_rev_ms_info_rec[idx];
}
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_elem_idx, &item,
"Information Record Type [%u]: (%u) %s",
num_recs + 1,
rec_type,
str);
curr_offset++;
oct_len = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(subtree, hf_ansi_a_length, tvb, curr_offset, 1, oct_len);
curr_offset++;
if (oct_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), oct_len);
switch (rec_type)
{
case ANSI_REV_MS_INFO_REC_KEYPAD_FAC:
poctets = tvb_get_string_enc(wmem_packet_scope(), tvb, curr_offset, oct_len, ENC_ASCII|ENC_NA);
proto_tree_add_string_format(subtree, hf_ansi_a_cld_party_ascii_num, tvb, curr_offset, oct_len,
(gchar *) poctets,
"Digits: %s",
(gchar *) format_text(poctets, oct_len));
curr_offset += oct_len;
break;
case ANSI_REV_MS_INFO_REC_CLD_PN:
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_cld_pn_num_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_cld_pn_num_plan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (oct_len > 1)
{
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(subtree, hf_ansi_a_msb_first_digit, tvb, (curr_offset*8)+7, 1, ENC_NA);
curr_offset++;
str_num = (gchar*)wmem_alloc(wmem_packet_scope(), oct_len);
for (i=0; i < (oct_len - 1); i++)
{
str_num[i] = (oct & 0x01) << 7;
oct = tvb_get_guint8(tvb, curr_offset + i);
str_num[i] |= (oct & 0xfe) >> 1;
}
str_num[i] = '\0';
proto_tree_add_string_format(subtree, hf_ansi_a_rev_ms_info_rec_cld_pn_num, tvb,
curr_offset, oct_len - 1, str_num, "Digits: %s", str_num);
curr_offset += (oct_len - 2);
}
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_01, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
break;
case ANSI_REV_MS_INFO_REC_CLG_PN:
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_clg_pn_num_type, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_clg_pn_num_plan, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_clg_pn_pi, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_clg_pn_si, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
if (oct_len > 2)
{
value = tvb_get_ntohs(tvb, curr_offset);
oct = (value & 0x00ff);
proto_tree_add_bits_item(subtree, hf_ansi_a_msb_first_digit, tvb, (curr_offset*8)+11, 5, ENC_NA);
curr_offset += 2;
str_num = (gchar*)wmem_alloc(wmem_packet_scope(), oct_len - 1);
for (i=0; i < (oct_len - 2); i++)
{
str_num[i] = (oct & 0x1f) << 3;
oct = tvb_get_guint8(tvb, curr_offset + i);
str_num[i] |= (oct & 0xe0) >> 5;
}
str_num[i] = '\0';
proto_tree_add_string_format(subtree, hf_ansi_a_rev_ms_info_rec_clg_pn_num, tvb,
curr_offset, oct_len - 2, str_num, "Digits: %s", str_num);
curr_offset += (oct_len - 3);
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_8_1f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
else
{
proto_tree_add_item(subtree, hf_ansi_a_reserved_bits_16_001f, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
}
break;
case ANSI_REV_MS_INFO_REC_SO_INFO:
i = 0;
saved_offset2 = curr_offset;
while ((oct_len - (curr_offset - saved_offset2)) > 2)
{
subtree2 = proto_tree_add_subtree_format(subtree, tvb, curr_offset, 3,
ett_so_list, &item2, "Service Option [%u]", i + 1);
proto_tree_add_item(subtree2, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree2, hf_ansi_a_rev_ms_info_rec_so_info_fwd_support, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree2, hf_ansi_a_rev_ms_info_rec_so_info_rev_support, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
value = tvb_get_ntohs(tvb, curr_offset);
str = ansi_a_so_int_to_str(value);
proto_tree_add_uint_format(subtree2, hf_ansi_a_rev_ms_info_rec_so_info_so, tvb, curr_offset, 2,
value,
"%s",
str);
proto_item_append_text(item2, " - (%u) %s", value, str);
i++;
curr_offset += 2;
}
break;
default:
proto_tree_add_item(subtree, hf_ansi_a_rev_ms_info_rec_content, tvb, curr_offset, oct_len, ENC_NA);
curr_offset += oct_len;
break;
}
}
proto_item_set_len(item, curr_offset - saved_offset);
num_recs++;
}
proto_item_append_text(data_p->elem_item, " - %u record%s", num_recs, plurality(num_recs, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_ext_ho_dir_params(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_srch_win_a, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_srch_win_n, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_srch_win_r, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_t_add, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_t_drop, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_t_comp, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_t_tdrop, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_nghbor_max_age, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (global_a_variant)
{
case A_VARIANT_IOS401:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_0f, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
case A_VARIANT_IOS501:
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_0c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_target_bs_values_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
}
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_soft_slope, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_add_intercept, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_drop_intercept, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_ext_ho_dir_params_target_bs_p_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cdma_sowd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 disc;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
disc = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
curr_offset +=
elem_cell_id_aux(tvb, pinfo, tree, curr_offset, len - (curr_offset - offset), disc, NULL);
proto_tree_add_item(tree, hf_ansi_a_cdma_sowd_sowd, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cdma_sowd_resolution, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((len - (curr_offset - offset)) > 1)
{
proto_tree_add_item(tree, hf_ansi_a_cdma_sowd_timestamp, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_re_res(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset, guint len _U_, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_re_res_prio_incl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_re_res_forward, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_re_res_reverse, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_re_res_alloc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_re_res_avail, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint8
elem_cld_party_ascii_num(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint8 *poctets;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cld_party_ascii_num_ton, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cld_party_ascii_num_plan, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
poctets = tvb_get_string_enc(wmem_packet_scope(), tvb, curr_offset, len - (curr_offset - offset), ENC_ASCII|ENC_NA);
proto_tree_add_string_format(tree, hf_ansi_a_cld_party_ascii_num, tvb, curr_offset, len - (curr_offset - offset),
(gchar *) poctets,
"Digits: %s",
(gchar *) format_text(poctets, len - (curr_offset - offset)));
proto_item_append_text(data_p->elem_item, " - (%s)", poctets);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_band_class(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_e0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_band_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%s)",
val_to_str_const(oct & 0x1f, ansi_a_band_class_vals, "Reserved"));
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_is2000_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_is2000_cause, tvb, curr_offset, len, ENC_NA);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_auth_event(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
if (len == 1)
{
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x01: str = "Event: Authentication parameters were NOT received from mobile"; break;
case 0x02: str = "Event: RANDC mis-match"; break;
case 0x03: str = "Event: Recently requested"; break;
case 0x04: str = "Event: Direct channel assignment"; break;
default:
str = "Event";
break;
}
proto_tree_add_bytes_format(tree, hf_ansi_a_auth_event, tvb, curr_offset, len,
NULL,
"%s",
str);
}
else
{
proto_tree_add_item(tree, hf_ansi_a_auth_event, tvb, curr_offset, len, ENC_NA);
}
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_psmm_count(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_psmm_count, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_geo_loc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_geo_loc, tvb, curr_offset, len, ENC_NA);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_cct_group(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
proto_item *item;
proto_tree *subtree;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cct_group_all_circuits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_cct_group_inclusive, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_ansi_a_cct_group_count, tvb, curr_offset, 1,
oct,
"Count: %u circuit%s",
oct,
plurality(oct, "", "s"));
proto_item_append_text(data_p->elem_item, " - %u circuit%s", oct, plurality(oct, "", "s"));
curr_offset++;
item = proto_tree_add_item(tree, hf_ansi_a_cct_group_first_cic, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_cic);
proto_tree_add_item(subtree, hf_ansi_a_cct_group_first_cic_pcm_multi, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cct_group_first_cic_timeslot, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_ansi_a_circuit_bitmap, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_paca_ts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_paca_timestamp_queuing_time, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_paca_order(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_f8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_paca_order_action_reqd, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%s)",
val_to_str_const(oct & 0x07, ansi_a_paca_order_action_reqd_vals, "Reserved"));
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_paca_reoi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_fe, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_paca_reoi_pri, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
proto_item_append_text(data_p->elem_item, " - (%sReorigination)", (oct & 0x01) ? "" : "Not ");
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_a2p_bearer_session(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_max_frames, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_ip_addr_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_addr_flag, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
if (oct & 0x01)
{
if ((oct & 0x06) >> 1)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 18);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_ipv6_addr, tvb, curr_offset, 16, ENC_NA);
data_p->rtp_src_addr.type = AT_IPv6;
data_p->rtp_src_addr.len = 16;
data_p->rtp_src_addr.data = (guint8 *) &data_p->rtp_ipv6_addr;
tvb_get_ipv6(tvb, curr_offset, &data_p->rtp_ipv6_addr);
curr_offset += 16;
}
else
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 6);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_ipv4_addr, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
data_p->rtp_src_addr.type = AT_IPv4;
data_p->rtp_src_addr.len = 4;
data_p->rtp_src_addr.data = (guint8 *) &data_p->rtp_ipv4_addr;
data_p->rtp_ipv4_addr = tvb_get_ipv4(tvb, curr_offset);
curr_offset += 4;
}
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_sess_udp_port, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
data_p->rtp_port = tvb_get_ntohs(tvb, curr_offset);
curr_offset += 2;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_a2p_bearer_format(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
proto_item *item;
proto_tree *subtree;
guint8 num_bearers;
guint32 curr_offset, orig_offset;
guint8 ip_addr_type;
gboolean ext;
guint8 ext_len;
const gchar *mime_type;
int sample_rate;
gboolean format_assigned;
gboolean in_band_format_assigned;
gboolean first_assigned_found;
gboolean rtp_dyn_payload_used;
guint8 rtp_payload_type;
rtp_dyn_payload_t *rtp_dyn_payload;
rtp_dyn_payload = rtp_dyn_payload_new();
rtp_dyn_payload_used = FALSE;
first_assigned_found = FALSE;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_form_num_formats, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_a2p_bearer_form_ip_addr_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
ip_addr_type = tvb_get_guint8(tvb, curr_offset) & 0x03;
curr_offset++;
num_bearers = 0;
while ((len - (curr_offset - offset)) > 0)
{
orig_offset = curr_offset;
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, -1,
ett_bearer_list, &item, "Bearer Format [%u]", num_bearers + 1);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(subtree, hf_ansi_a_extension_8_80, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_tag_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_format_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
ext = (oct & 0x80) ? TRUE : FALSE;
format_assigned = FALSE;
in_band_format_assigned = FALSE;
switch ((oct & 0x70) >> 4)
{
case 1:
in_band_format_assigned = TRUE;
break;
case 2:
format_assigned = TRUE;
break;
}
if (((oct & 0x0f) >= 10) &&
((oct & 0x0f) <= 15))
{
sample_rate = 16000;
}
else
{
sample_rate = 8000;
}
mime_type = val_to_str_const(oct & 0xf, ansi_a_a2p_bearer_form_format_format_id_vals, "Reserved");
proto_item_append_text(item, " - (%s)", mime_type);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_rtp_payload_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_bearer_addr_flag, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
rtp_payload_type = (oct & 0xfe) >> 1;
curr_offset++;
if (oct & 0x01)
{
if (ip_addr_type != 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 18);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_ipv6_addr, tvb, curr_offset, 16, ENC_NA);
if (format_assigned)
{
data_p->rtp_src_addr.type = AT_IPv6;
data_p->rtp_src_addr.len = 16;
data_p->rtp_src_addr.data = (guint8 *) &data_p->rtp_ipv6_addr;
tvb_get_ipv6(tvb, curr_offset, &data_p->rtp_ipv6_addr);
}
curr_offset += 16;
}
else
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 6);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_ipv4_addr, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
if (format_assigned)
{
data_p->rtp_src_addr.type = AT_IPv4;
data_p->rtp_src_addr.len = 4;
data_p->rtp_src_addr.data = (guint8 *) &data_p->rtp_ipv4_addr;
data_p->rtp_ipv4_addr = tvb_get_ipv4(tvb, curr_offset);
}
curr_offset += 4;
}
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_udp_port, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
if (format_assigned)
{
data_p->rtp_port = tvb_get_ntohs(tvb, curr_offset);
}
curr_offset += 2;
}
if (ext)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), 1);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_ext_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_a2p_bearer_form_format_ext_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
ext_len = (oct & 0xf0) >> 4;
curr_offset++;
if (ext_len > 0)
{
SHORT_DATA_CHECK(len - (curr_offset - offset), ext_len);
proto_tree_add_item(subtree, hf_ansi_a_extension_parameter_value, tvb, curr_offset, ext_len, ENC_NA);
curr_offset += ext_len;
}
}
proto_item_set_len(item, curr_offset - orig_offset);
if (format_assigned &&
(first_assigned_found == FALSE))
{
rtp_dyn_payload_insert(rtp_dyn_payload, rtp_payload_type, mime_type, sample_rate);
rtp_dyn_payload_used = TRUE;
first_assigned_found = TRUE;
rtp_add_address(pinfo, &data_p->rtp_src_addr, data_p->rtp_port, 0, "IOS5",
pinfo->num, FALSE, rtp_dyn_payload);
}
if (in_band_format_assigned)
{
rtp_dyn_payload_insert(rtp_dyn_payload, rtp_payload_type, "telephone-event", sample_rate);
rtp_dyn_payload_used = TRUE;
}
num_bearers++;
}
if (rtp_dyn_payload_used == FALSE)
{
rtp_dyn_payload_free(rtp_dyn_payload);
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_ms_des_freq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_ms_des_freq_band_class, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_ms_des_freq_cdma_channel, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(data_p->elem_item, " - (CDMA Channel: %u)",
tvb_get_ntohs(tvb, curr_offset) & 0x07ff);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_plcm_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = val_to_str_const((oct & 0xf0) >> 4, ansi_a_plcm_id_plcm_type_vals, "Reserved");
proto_tree_add_uint_format_value(tree, hf_ansi_a_plcm_id_plcm_type, tvb, curr_offset, 1,
oct, "%s", str);
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_0c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_plcm42, tvb, curr_offset, 6, ENC_BIG_ENDIAN);
curr_offset += 6;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_bdtmf_trans_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_reserved_bits_8_c0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_bdtmf_trans_info_dtmf_off_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_a_bdtmf_trans_info_dtmf_on_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint8
elem_dtmf_chars(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint32 curr_offset;
guint8 packed_len;
char *str;
curr_offset = offset;
proto_tree_add_item(tree, hf_ansi_a_bdtmf_chars_num_chars, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
if (curr_offset - offset >= len)
return (curr_offset - offset);
packed_len = len - (curr_offset - offset);
str = (char*)tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, packed_len, &Dgt_dtmf, FALSE);
if (oct & 0x01)
{
str[(2*packed_len)-1] = '\0';
}
proto_tree_add_string(tree, hf_ansi_a_bdtmf_chars_digits, tvb, curr_offset, packed_len, str);
proto_item_append_text(data_p->elem_item, " - (%s)", str);
curr_offset += packed_len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
elem_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, elem_idx_t idx, guint32 offset, guint len _U_, const gchar *name_add, ansi_a_shared_data_t *data_p)
{
guint8 oct, parm_len;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
gint dec_idx;
curr_offset = offset;
consumed = 0;
if ((int) idx < 0 || idx >= ansi_a_elem_1_max-1)
{
return tvb_reported_length_remaining(tvb, offset);
}
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == (guint8) ansi_a_elem_1_strings[idx].value)
{
dec_idx = ansi_a_elem_1_strings[idx].dec_index;
parm_len = tvb_get_guint8(tvb, curr_offset + 1);
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 2,
ett_ansi_elem_1[idx], &data_p->elem_item, "%s%s",
ansi_a_elem_1_strings[idx].strptr,
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree, hf_ansi_a_elem_id, tvb, curr_offset, 1, oct);
proto_tree_add_uint(subtree, hf_ansi_a_length, tvb, curr_offset + 1, 1, parm_len);
if (parm_len > 0)
{
if (elem_1_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(subtree, pinfo, &ei_ansi_a_no_tlv_elem_diss, tvb, curr_offset + 2, parm_len,
"Element Value");
consumed = parm_len;
}
else
{
consumed = (*elem_1_fcn[dec_idx])(tvb, pinfo, subtree, curr_offset + 2, parm_len, data_p);
}
}
consumed += 2;
}
return(consumed);
}
static guint16
elem_tv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, elem_idx_t idx, guint32 offset, const gchar *name_add, ansi_a_shared_data_t *data_p)
{
guint8 oct;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
gint dec_idx;
curr_offset = offset;
consumed = 0;
if ((int) idx < 0 || idx >= ansi_a_elem_1_max-1)
{
return tvb_reported_length_remaining(tvb, offset);
}
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == (guint8) ansi_a_elem_1_strings[idx].value)
{
dec_idx = ansi_a_elem_1_strings[idx].dec_index;
subtree =
proto_tree_add_subtree_format(tree,
tvb, curr_offset, -1,
ett_ansi_elem_1[idx], &data_p->elem_item, "%s%s",
ansi_a_elem_1_strings[idx].strptr,
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree, hf_ansi_a_elem_id, tvb, curr_offset, 1, oct);
if (elem_1_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(subtree, pinfo, &ei_ansi_a_no_tv_elem_diss, tvb, curr_offset + 1, 1,
"No element dissector, rest of dissection may be incorrect");
consumed = 1;
}
else
{
consumed = (*elem_1_fcn[dec_idx])(tvb, pinfo, subtree, curr_offset + 1, -1, data_p);
}
consumed++;
proto_item_set_len(data_p->elem_item, consumed);
}
return(consumed);
}
static guint16
elem_t(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, elem_idx_t idx, guint32 offset, const gchar *name_add, ansi_a_shared_data_t *data_p _U_)
{
guint8 oct;
guint32 curr_offset;
guint16 consumed;
curr_offset = offset;
consumed = 0;
if ((int) idx < 0 || idx >= ansi_a_elem_1_max-1)
{
return tvb_reported_length_remaining(tvb, offset);
}
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == (guint8) ansi_a_elem_1_strings[idx].value)
{
proto_tree_add_uint_format(tree, hf_ansi_a_elem_id, tvb, curr_offset, 1, oct,
"%s%s",
ansi_a_elem_1_strings[idx].strptr,
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
consumed = 1;
}
return(consumed);
}
static guint16
elem_lv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, elem_idx_t idx, guint32 offset, guint len _U_, const gchar *name_add, ansi_a_shared_data_t *data_p)
{
guint8 parm_len;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
gint dec_idx;
curr_offset = offset;
consumed = 0;
if ((int) idx < 0 || idx >= ansi_a_elem_1_max-1)
{
return tvb_reported_length_remaining(tvb, offset);
}
dec_idx = ansi_a_elem_1_strings[idx].dec_index;
parm_len = tvb_get_guint8(tvb, curr_offset);
subtree =
proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 1,
ett_ansi_elem_1[idx], &data_p->elem_item, "%s%s",
ansi_a_elem_1_strings[idx].strptr,
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree, hf_ansi_a_length, tvb,
curr_offset, 1, parm_len);
if (parm_len > 0)
{
if (elem_1_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(subtree, pinfo, &ei_ansi_a_no_lv_elem_diss, tvb, curr_offset + 1, parm_len,
"Element Value");
consumed = parm_len;
}
else
{
consumed = (*elem_1_fcn[dec_idx])(tvb, pinfo, subtree, curr_offset + 1, parm_len, data_p);
}
}
return(consumed + 1);
}
static guint16
elem_v(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, elem_idx_t idx, guint32 offset, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
gint dec_idx;
curr_offset = offset;
if ((int) idx < 0 || idx >= ansi_a_elem_1_max-1)
{
return tvb_reported_length_remaining(tvb, offset) ;
}
dec_idx = ansi_a_elem_1_strings[idx].dec_index;
data_p->elem_item = NULL;
if (elem_1_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(tree, pinfo, &ei_ansi_a_no_v_elem_diss, tvb, curr_offset, 1,
"No element dissector, rest of dissection may be incorrect");
consumed = 1;
}
else
{
consumed = (*elem_1_fcn[dec_idx])(tvb, pinfo, tree, curr_offset, -1, data_p);
}
return(consumed);
}
static void
bsmap_cl3_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint16 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
if (!data_p->from_sip)
{
ELEM_MAND_TLV(ANSI_A_E_CELL_ID, "");
ELEM_MAND_TLV(ANSI_A_E_L3_INFO, "");
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cm_srvc_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
curr_offset = offset;
curr_len = len;
oct = tvb_get_guint8(tvb, curr_offset);
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 1, ett_cm_srvc_type, NULL,
"CM Service Type: %s", val_to_str_const(oct & 0x0f, dtap_cm_service_type_vals, "Unknown"));
proto_tree_add_item(subtree, hf_ansi_a_elem_id_f0, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_a_cm_svrc_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
curr_len--;
ELEM_MAND_LV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_MAND_LV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_BCD_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_CNF_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_PARAM_COUNT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_T(ANSI_A_E_VP_REQ, "");
ELEM_OPT_TV(ANSI_A_E_RE_RES, "");
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_ASCII_NUM, "");
ELEM_OPT_TV(ANSI_A_E_CIC, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_EVENT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_DATA, "");
ELEM_OPT_TLV(ANSI_A_E_PACA_REOI, "");
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_SSCI, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_T(ANSI_A_E_ORIG_CI, "");
ELEM_OPT_TV(ANSI_A_E_RETURN_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cm_srvc_req_cont(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_BCD_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_ASCII_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_REV_MS_INFO_RECS, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_page_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_page_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_MAND_LV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_CNF_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_PARAM_COUNT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_T(ANSI_A_E_VP_REQ, "");
ELEM_OPT_TV(ANSI_A_E_CIC, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_EVENT, "");
ELEM_OPT_TV(ANSI_A_E_RE_RES, "");
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_progress(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(ANSI_A_E_SIGNAL, "");
ELEM_OPT_TLV(ANSI_A_E_FWD_MS_INFO_RECS, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_srvc_redirection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_IS2000_RED_RECORD, "");
ELEM_MAND_TLV(ANSI_A_E_S_RED_INFO, "");
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_srvc_release(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_SOCI, "");
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE_L3, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_srvc_release_complete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ass_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CHAN_TYPE, "");
ELEM_OPT_TV(ANSI_A_E_CIC, "");
ELEM_OPT_TLV(ANSI_A_E_ENC_INFO, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TV(ANSI_A_E_SIGNAL, "");
ELEM_OPT_TLV(ANSI_A_E_CLG_PARTY_ASCII_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_FWD_MS_INFO_RECS, "");
ELEM_OPT_TLV(ANSI_A_E_PRIO, "");
ELEM_OPT_TLV(ANSI_A_E_PACA_TS, "");
ELEM_OPT_TLV(ANSI_A_E_QOS_PARAMS, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_TLV(ANSI_A_E_SR_ID, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ass_complete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CHAN_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_ENC_INFO, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ass_failure(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_clr_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE_L3, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_clr_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE_L3, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_clr_complete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint16 consumed;
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_T(ANSI_A_E_PDI, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_alert_with_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_FWD_MS_INFO_RECS, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bs_srvc_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_ADDS_USER_PART, "");
ELEM_OPT_TLV(ANSI_A_E_SR_ID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bs_srvc_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_add_srvc_noti(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_MAND_TV(ANSI_A_E_SO, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_add_srvc_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_BCD_NUM, "");
ELEM_MAND_TV(ANSI_A_E_SO, "");
ELEM_OPT_T(ANSI_A_E_VP_REQ, "");
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_ASCII_NUM, "");
ELEM_OPT_TV(ANSI_A_E_CIC, "");
ELEM_OPT_TLV(ANSI_A_E_SSCI, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_connect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_flash_with_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CLD_PARTY_BCD_NUM, "");
ELEM_OPT_TV(ANSI_A_E_SIGNAL, "");
ELEM_OPT_TV(ANSI_A_E_MWI, "");
ELEM_OPT_TLV(ANSI_A_E_CLG_PARTY_ASCII_NUM, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
if (data_p->is_reverse)
{
ELEM_OPT_TLV(ANSI_A_E_REV_MS_INFO_RECS, "");
}
else
{
ELEM_OPT_TLV(ANSI_A_E_FWD_MS_INFO_RECS, "");
}
ELEM_OPT_TLV(ANSI_A_E_SSCI, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_flash_with_info_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_feat_noti(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TV(ANSI_A_E_SIGNAL, "");
ELEM_OPT_TV(ANSI_A_E_MWI, "");
ELEM_OPT_TLV(ANSI_A_E_CLG_PARTY_ASCII_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_FWD_MS_INFO_RECS, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_feat_noti_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_paca_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_PRIO, "");
ELEM_OPT_TLV(ANSI_A_E_PACA_TS, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_paca_command_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_paca_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_PACA_ORDER, "");
ELEM_OPT_TLV(ANSI_A_E_PRIO, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_CNF_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_PARAM_COUNT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_EVENT, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_paca_update_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_PRIO, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_rm_pos_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_PSMM_COUNT, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_rm_pos_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_DOWNLINK_RE_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_GEO_LOC, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_auth_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_auth_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_auth_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_MAND_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bearer_upd_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bearer_upd_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bearer_upd_reqd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_auth_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_AUTH_RESP_PARAM, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_user_zone_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_user_zone_update_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_UZ_ID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_user_zone_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_UZ_ID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_send_burst_dtmf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_BDTMF_TRANS_INFO, "");
ELEM_MAND_LV(ANSI_A_E_DTMF_CHARS, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_send_burst_dtmf_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_start_dtmf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_DTMF_CHARS, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_start_dtmf_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_stop_dtmf_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_user_zone_reject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_user_zone_reject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_reg_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ms_reg_noti(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bs_auth_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_bs_auth_req_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_ssd_update_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_AUTH_CHLG_PARAM, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_bs_challenge(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_AUTH_CHLG_PARAM, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_bs_challenge_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_AUTH_RESP_PARAM, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_ssd_update_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_CAUSE_L3, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_lu_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_LAI, "");
ELEM_OPT_TLV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_OPT_TV(ANSI_A_E_REG_TYPE, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_CNF_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_PARAM_COUNT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_EVENT, "");
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TV(ANSI_A_E_RETURN_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_lu_accept(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
switch (global_a_variant)
{
case A_VARIANT_IOS401:
ELEM_OPT_TV(ANSI_A_E_LAI, "");
break;
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_lu_reject(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(ANSI_A_E_REJ_CAUSE);
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_priv_mode_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_ENC_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_priv_mode_complete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_ENC_INFO, "");
ELEM_OPT_T(ANSI_A_E_VP_REQ, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_status_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_IE_REQD, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_status_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_IE_REQD, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_status_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_REV_MS_INFO_RECS, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_status_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_REV_MS_INFO_RECS, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_reqd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_MAND_TLV(ANSI_A_E_CELL_ID_LIST, " (Target)");
ELEM_OPT_TLV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_OPT_T(ANSI_A_E_RESP_REQ, "");
ELEM_OPT_TLV(ANSI_A_E_ENC_INFO, "");
ELEM_OPT_TLV(ANSI_A_E_IS95_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_DOWNLINK_RE, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
ELEM_OPT_TLV(ANSI_A_E_IS95_MS_MEAS_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_QOS_PARAMS, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_SCR, "");
switch (global_a_variant)
{
case A_VARIANT_IOS401:
ELEM_OPT_TLV(ANSI_A_E_PDSN_IP_ADDR, "");
break;
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_S_PDSN_ADDR, "");
break;
}
ELEM_OPT_TLV(ANSI_A_E_PTYPE, "");
ELEM_OPT_TLV(ANSI_A_E_SRNC_TRNC_TC, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TV(ANSI_A_E_ACC_NET_ID, "");
ELEM_OPT_TLV(ANSI_A_E_SO_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID_3X, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_NN_SCR, "");
ELEM_OPT_TLV(ANSI_A_E_ANCH_PDSN_ADDR, "");
ELEM_OPT_TLV(ANSI_A_E_ANCH_PP_ADDR, "");
ELEM_OPT_TLV(ANSI_A_E_PSP, "");
ELEM_OPT_TLV(ANSI_A_E_PLCM_ID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CHAN_TYPE, "");
ELEM_MAND_TLV(ANSI_A_E_ENC_INFO, "");
ELEM_MAND_TLV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_MAND_TLV(ANSI_A_E_CELL_ID_LIST, "(Target)");
ELEM_OPT_TLV(ANSI_A_E_CIC_EXT, "");
ELEM_OPT_TLV(ANSI_A_E_IS95_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_DOWNLINK_RE, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
ELEM_OPT_TLV(ANSI_A_E_IS95_MS_MEAS_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_QOS_PARAMS, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_SCR, "");
switch (global_a_variant)
{
case A_VARIANT_IOS401:
ELEM_OPT_TLV(ANSI_A_E_PDSN_IP_ADDR, "");
break;
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_S_PDSN_ADDR, "");
break;
}
ELEM_OPT_TLV(ANSI_A_E_PTYPE, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_SRNC_TRNC_TC, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TV(ANSI_A_E_ACC_NET_ID, "");
ELEM_OPT_TLV(ANSI_A_E_SO_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID_3X, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_NN_SCR, "");
ELEM_OPT_TLV(ANSI_A_E_ANCH_PDSN_ADDR, "");
ELEM_OPT_TLV(ANSI_A_E_ANCH_PP_ADDR, "");
ELEM_OPT_TLV(ANSI_A_E_PSP, "");
ELEM_OPT_TLV(ANSI_A_E_PLCM_ID, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_req_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_IS95_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_EXT_HO_DIR_PARAMS, "");
ELEM_OPT_TV(ANSI_A_E_HHO_PARAMS, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_SCR, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_NN_SCR, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_TRNC_SRNC_TC, "");
ELEM_OPT_TLV(ANSI_A_E_SO_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID_3X, "");
ELEM_OPT_TLV(ANSI_A_E_PLCM_ID, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_SESSION, "");
ELEM_OPT_TLV(ANSI_A_E_A2P_BEARER_FORMAT, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_failure(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(ANSI_A_E_RF_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS95_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_HO_POW_LEV, "");
ELEM_OPT_TV(ANSI_A_E_SID, "");
ELEM_OPT_TLV(ANSI_A_E_EXT_HO_DIR_PARAMS, "");
ELEM_OPT_TV(ANSI_A_E_HHO_PARAMS, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_SCR, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_NN_SCR, "");
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ELEM_OPT_TLV(ANSI_A_E_TRNC_SRNC_TC, "");
ELEM_OPT_TLV(ANSI_A_E_SO_LIST, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_AMPS_HHO_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CHAN_ID_3X, "");
ELEM_OPT_TLV(ANSI_A_E_PLCM_ID, "");
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_complete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(ANSI_A_E_SO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_reqd_rej(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_ho_performed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_CHAN_NUM, "");
ELEM_OPT_TLV(ANSI_A_E_BAND_CLASS, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CCT_GROUP, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_block_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_unblock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
ELEM_OPT_TLV(ANSI_A_E_CCT_GROUP, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_unblock_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_reset(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_SW_VER, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_reset_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_SW_VER, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_reset_cct(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CCT_GROUP, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_reset_cct_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TV(ANSI_A_E_CIC, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_xmode_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_XMODE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_xmode_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_adds_page(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_MAND_TLV(ANSI_A_E_ADDS_USER_PART, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID_LIST, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_P_REV, "");
ELEM_OPT_TLV(ANSI_A_E_MS_DES_FREQ, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_adds_transfer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_MAND_TLV(ANSI_A_E_ADDS_USER_PART, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_RESP_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_CNF_PARAM, "");
ELEM_OPT_TV(ANSI_A_E_AUTH_PARAM_COUNT, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_CHLG_PARAM, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_EVENT, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
ELEM_OPT_TLV(ANSI_A_E_AUTH_DATA, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CM_INFO_TYPE_2, "");
ELEM_OPT_TV(ANSI_A_E_SCI, "");
ELEM_OPT_TV(ANSI_A_E_SO, "");
ELEM_OPT_TLV(ANSI_A_E_UZ_ID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_MOB_CAP, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MOB_SUB_INFO, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_adds_transfer_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_adds_deliver(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(ANSI_A_E_ADDS_USER_PART, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CDMA_SOWD, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_adds_page_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_CELL_ID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_adds_deliver_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(ANSI_A_E_TAG, "");
ELEM_OPT_TLV(ANSI_A_E_CAUSE, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bsmap_rejection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rejection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, ansi_a_shared_data_t *data_p)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(ANSI_A_E_MID, "");
ELEM_OPT_TLV(ANSI_A_E_IS2000_CAUSE, "");
ELEM_OPT_TLV(ANSI_A_E_SOCI, "");
ELEM_OPT_TLV(ANSI_A_E_MID, "");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
dissect_cdma2000_a1_elements(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
unsigned idx;
guint8 oct;
ansi_a_shared_data_t shared_data;
ansi_a_shared_data_t *data_p;
memset((void *) &shared_data, 0, sizeof(shared_data));
data_p = &shared_data;
shared_data.g_tree = tree;
curr_offset = offset;
curr_len = len;
while (curr_len > 1)
{
oct = tvb_get_guint8(tvb, curr_offset);
for (idx=0; idx < (unsigned) ansi_a_elem_1_max; idx++)
{
if (oct == (guint8) ansi_a_elem_1_strings[idx].value)
{
ELEM_OPT_TLV((elem_idx_t) idx, "");
break;
}
}
if (idx == (elem_idx_t) ansi_a_elem_1_max)
{
consumed = 2 + tvb_get_guint8(tvb, curr_offset + 1);
curr_offset += consumed;
curr_len -= consumed;
}
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dissect_bsmap_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean from_sip)
{
static ansi_a_tap_rec_t tap_rec[16];
static ansi_a_tap_rec_t *tap_p;
static int tap_current = 0;
guint8 oct;
guint32 offset;
guint32 len;
gint dec_idx;
proto_item *bsmap_item = NULL;
proto_tree *bsmap_tree = NULL;
const gchar *msg_str;
ansi_a_shared_data_t shared_data;
memset((void *) &shared_data, 0, sizeof(shared_data));
shared_data.g_tree = tree;
shared_data.from_sip = from_sip;
shared_data.is_reverse = (pinfo->p2p_dir == P2P_DIR_RECV);
col_append_str(pinfo->cinfo, COL_INFO, "(BSMAP) ");
tap_current++;
if (tap_current == array_length(tap_rec))
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
len = tvb_reported_length(tvb);
offset = 0;
oct = tvb_get_guint8(tvb, offset);
msg_str = my_try_val_to_str_idx((guint32) oct, ansi_a_bsmap_strings, &dec_idx);
if (msg_str == NULL)
{
bsmap_item =
proto_tree_add_expert_format(tree, pinfo, &ei_ansi_a_unknown_bsmap_msg, tvb, 0, len,
"ANSI A-I/F BSMAP - Unknown BSMAP Message Type (%u)",
oct);
bsmap_tree = proto_item_add_subtree(bsmap_item, ett_bsmap);
}
else
{
bsmap_item =
proto_tree_add_protocol_format(tree, proto_a_bsmap, tvb, 0, len,
"ANSI A-I/F BSMAP - %s",
msg_str);
bsmap_tree = proto_item_add_subtree(bsmap_item, ett_bsmap_msg[dec_idx]);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
}
shared_data.message_item = bsmap_item;
proto_tree_add_item(bsmap_tree, hf_ansi_a_bsmap_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tap_p->pdu_type = BSSAP_PDU_TYPE_BSMAP;
tap_p->message_type = oct;
tap_queue_packet(ansi_a_tap, pinfo, tap_p);
if (msg_str == NULL) return;
if ((len - offset) <= 0) return;
if (bsmap_msg_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(bsmap_tree, pinfo, &ei_ansi_a_miss_bsmap_msg_diss, tvb, offset, len - offset,
"Message Elements");
}
else
{
(*bsmap_msg_fcn[dec_idx])(tvb, pinfo, bsmap_tree, offset, len - offset, &shared_data);
}
}
static int
dissect_bsmap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_bsmap_common(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static void
dissect_dtap_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean from_sip)
{
static ansi_a_tap_rec_t tap_rec[16];
static ansi_a_tap_rec_t *tap_p;
static int tap_current = 0;
guint8 oct, oct_1 = 0;
guint32 offset;
guint32 len;
gint dec_idx;
proto_item *dtap_item = NULL;
proto_tree *dtap_tree = NULL;
proto_item *oct_1_item = NULL;
proto_tree *oct_1_tree = NULL;
const gchar *msg_str;
const gchar *str;
ansi_a_shared_data_t shared_data;
len = tvb_reported_length(tvb);
if ((len < 3) && !from_sip)
{
call_data_dissector(tvb, pinfo, tree);
return;
}
memset((void *) &shared_data, 0, sizeof(shared_data));
shared_data.g_tree = tree;
shared_data.from_sip = from_sip;
shared_data.is_reverse = (pinfo->p2p_dir == P2P_DIR_RECV);
col_append_str(pinfo->cinfo, COL_INFO, "(DTAP) ");
tap_current++;
if (tap_current == array_length(tap_rec))
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
if (!from_sip)
{
oct_1 = tvb_get_guint8(tvb, offset);
offset++;
offset++;
}
oct = tvb_get_guint8(tvb, offset);
msg_str = my_try_val_to_str_idx((guint32) oct, ansi_a_dtap_strings, &dec_idx);
if (msg_str == NULL)
{
dtap_item =
proto_tree_add_expert_format(tree, pinfo, &ei_ansi_a_unknown_dtap_msg, tvb, 0, len,
"ANSI A-I/F DTAP - Unknown DTAP Message Type (%u)",
oct);
dtap_tree = proto_item_add_subtree(dtap_item, ett_dtap);
}
else
{
dtap_item =
proto_tree_add_protocol_format(tree, proto_a_dtap, tvb, 0, len,
"ANSI A-I/F DTAP - %s",
msg_str);
dtap_tree = proto_item_add_subtree(dtap_item, ett_dtap_msg[dec_idx]);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
}
shared_data.message_item = dtap_item;
if (!from_sip)
{
switch (oct_1 & 0x0f)
{
case 3: str = "Call Control, call related SS"; break;
case 5: str = "Mobility Management"; break;
case 6: str = "Radio Resource Management"; break;
case 9: str = "Facility Management"; break;
case 11: str = "Other Signaling Procedures"; break;
case 15: str = "Reserved for tests"; break;
default:
str = "Unknown";
break;
}
oct_1_item =
proto_tree_add_uint_format(dtap_tree, hf_ansi_a_protocol_disc, tvb, 0, 1,
(oct_1 & 0x0f),
"Protocol Discriminator: %s",
str);
oct_1_tree = proto_item_add_subtree(oct_1_item, ett_dtap_oct_1);
proto_tree_add_item(oct_1_tree, hf_ansi_a_reserved_bits_8_f0, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(oct_1_tree, hf_ansi_a_protocol_disc, tvb, 0, 1, ENC_BIG_ENDIAN);
switch (global_a_variant)
{
case A_VARIANT_IS634:
proto_tree_add_item(dtap_tree, hf_ansi_a_ti_flag, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dtap_tree, hf_ansi_a_ti_ti, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dtap_tree, hf_ansi_a_reserved_bits_8_0f, tvb, 1, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(dtap_tree, hf_ansi_a_reserved_octet, tvb, 1, 1, ENC_BIG_ENDIAN);
break;
}
}
proto_tree_add_item(dtap_tree, hf_ansi_a_dtap_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tap_p->pdu_type = BSSAP_PDU_TYPE_DTAP;
tap_p->message_type = oct;
tap_queue_packet(ansi_a_tap, pinfo, tap_p);
if (msg_str == NULL) return;
if ((len - offset) <= 0) return;
if (dtap_msg_fcn[dec_idx] == NULL)
{
proto_tree_add_expert_format(dtap_tree, pinfo, &ei_ansi_a_miss_dtap_msg_diss, tvb, offset, len - offset,
"Message Elements");
}
else
{
(*dtap_msg_fcn[dec_idx])(tvb, pinfo, dtap_tree, offset, len - offset, &shared_data);
}
}
static int
dissect_dtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_dtap_common(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_sip_dtap_bsmap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint linelen, offset, next_offset, begin;
guint8 *msg_type;
tvbuff_t *ansi_a_tvb;
gboolean is_dtap = TRUE;
offset = 0;
if ((linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, TRUE)) > 0)
{
if (linelen >= 2)
{
ansi_a_tvb = tvb_new_composite();
msg_type = (guint8 *) wmem_alloc(pinfo->pool, 1);
msg_type[0] = (guint8) strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2, ENC_ASCII|ENC_NA), NULL, 16);
if ((begin = tvb_find_guint8(tvb, offset, linelen, '"')) > 0)
{
if (tvb_get_guint8(tvb, begin + 1) == '1')
{
is_dtap = FALSE;
}
}
else
{
if (my_try_val_to_str_idx((guint32) msg_type[0], ansi_a_dtap_strings, &linelen) == NULL)
{
is_dtap = FALSE;
}
}
tvb_composite_append(ansi_a_tvb, tvb_new_child_real_data(tvb, msg_type, 1, 1));
offset = next_offset;
while ((linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, TRUE)) > 0)
{
if ((begin = tvb_find_guint8(tvb, offset, linelen, '=')) > 0)
{
begin++;
tvb_composite_append(ansi_a_tvb, base64_to_tvb(tvb, tvb_get_string_enc(wmem_packet_scope(), tvb, begin, offset + linelen - begin, ENC_ASCII|ENC_NA)));
}
offset = next_offset;
}
tvb_composite_finalize(ansi_a_tvb);
if (is_dtap)
{
add_new_data_source(pinfo, ansi_a_tvb, "ANSI DTAP");
dissect_dtap_common(ansi_a_tvb, pinfo, tree, TRUE);
}
else
{
add_new_data_source(pinfo, ansi_a_tvb, "ANSI BSMAP");
dissect_bsmap_common(ansi_a_tvb, pinfo, tree, TRUE);
}
}
}
return tvb_captured_length(tvb);
}
static void ansi_a_dtap_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(dtap_stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* table = new_stat_tap_init_table("ANSI A-I/F DTAP Statistics", num_fields, 0, NULL, gui_callback, gui_data);
int i = 0;
stat_tap_table_item_type items[sizeof(dtap_stat_fields)/sizeof(stat_tap_table_item)];
new_stat_tap_add_table(new_stat, table);
while (ansi_a_dtap_strings[i].strptr)
{
items[IEI_COLUMN].type = TABLE_ITEM_UINT;
items[IEI_COLUMN].value.uint_value = ansi_a_dtap_strings[i].value;
items[MESSAGE_NAME_COLUMN].type = TABLE_ITEM_STRING;
items[MESSAGE_NAME_COLUMN].value.string_value = ansi_a_dtap_strings[i].strptr;
items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
items[COUNT_COLUMN].value.uint_value = 0;
new_stat_tap_init_table_row(table, i, num_fields, items);
i++;
}
}
static gboolean
ansi_a_dtap_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *data)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const ansi_a_tap_rec_t *data_p = (const ansi_a_tap_rec_t *)data;
stat_tap_table_item_type* dtap_data;
stat_tap_table* table;
guint i = 0, idx;
if (data_p->pdu_type == BSSAP_PDU_TYPE_DTAP)
{
if (my_try_val_to_str_idx(data_p->message_type, ansi_a_dtap_strings, &idx) == NULL)
return FALSE;
table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, i);
dtap_data = new_stat_tap_get_field_data(table, data_p->message_type, COUNT_COLUMN);
dtap_data->value.uint_value++;
new_stat_tap_set_field_data(table, data_p->message_type, COUNT_COLUMN, dtap_data);
return TRUE;
}
return FALSE;
}
static void
ansi_a_stat_reset(stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, COUNT_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, COUNT_COLUMN, item_data);
}
}
static void ansi_a_bsmap_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(bsmap_stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* table = new_stat_tap_init_table("ANSI A-I/F BSMAP Statistics", num_fields, 0, NULL, gui_callback, gui_data);
int i = 0;
stat_tap_table_item_type items[sizeof(bsmap_stat_fields)/sizeof(stat_tap_table_item)];
new_stat_tap_add_table(new_stat, table);
while (ansi_a_bsmap_strings[i].strptr)
{
items[IEI_COLUMN].type = TABLE_ITEM_UINT;
items[IEI_COLUMN].value.uint_value = ansi_a_bsmap_strings[i].value;
items[MESSAGE_NAME_COLUMN].type = TABLE_ITEM_STRING;
items[MESSAGE_NAME_COLUMN].value.string_value = ansi_a_bsmap_strings[i].strptr;
items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
items[COUNT_COLUMN].value.uint_value = 0;
new_stat_tap_init_table_row(table, i, num_fields, items);
i++;
}
}
static gboolean
ansi_a_bsmap_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *data)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const ansi_a_tap_rec_t *data_p = (const ansi_a_tap_rec_t *)data;
stat_tap_table_item_type* dtap_data;
stat_tap_table* table;
guint i = 0, idx;
if (data_p->pdu_type == BSSAP_PDU_TYPE_BSMAP)
{
if (my_try_val_to_str_idx(data_p->message_type, ansi_a_bsmap_strings, &idx) == NULL)
return FALSE;
table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, i);
dtap_data = new_stat_tap_get_field_data(table, data_p->message_type, COUNT_COLUMN);
dtap_data->value.uint_value++;
new_stat_tap_set_field_data(table, data_p->message_type, COUNT_COLUMN, dtap_data);
return TRUE;
}
return FALSE;
}
void
proto_register_ansi_a(void)
{
module_t *ansi_a_module;
guint i;
gint last_offset;
static hf_register_info hf[] = {
{ &hf_ansi_a_bsmap_msgtype,
{ "BSMAP Message Type", "ansi_a_bsmap.msgtype",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_dtap_msgtype,
{ "DTAP Message Type", "ansi_a_bsmap.dtap_msgtype",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_protocol_disc,
{ "Protocol Discriminator", "ansi_a_bsmap.protocol_disc",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_octet,
{ "Reserved Octet", "ansi_a_bsmap.reserved_octet",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_ti_flag,
{ "Transaction Identifier (TI) Flag", "ansi_a_bsmap.ti.flag",
FT_BOOLEAN, 8, TFS(&tfs_allocated_by_receiver_sender), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_ti_ti,
{ "Transaction Identifier (TI)", "ansi_a_bsmap.ti.ti",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_cm_svrc_type,
{ "CM Service Type", "ansi_a_bsmap.cm_srvc_type",
FT_UINT8, BASE_DEC, VALS(dtap_cm_service_type_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_elem_id,
{ "Element ID", "ansi_a_bsmap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_elem_id_f0,
{ "Element ID", "ansi_a_bsmap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_length,
{ "Length", "ansi_a_bsmap.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_esn,
{ "ESN", "ansi_a_bsmap.esn",
FT_UINT32, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_imsi,
{ "IMSI", "ansi_a_bsmap.imsi",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_ansi_a_meid,
{ "MEID", "ansi_a_bsmap.meid",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cld_party_bcd_num,
{ "Called Party BCD Number", "ansi_a_bsmap.cld_party_bcd_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cld_party_ascii_num,
{ "Called Party ASCII Number", "ansi_a_bsmap.cld_party_ascii_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_ascii_num,
{ "Calling Party ASCII Number", "ansi_a_bsmap.clg_party_ascii_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cell_ci,
{ "Cell CI", "ansi_a_bsmap.cell_ci",
FT_UINT16, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_cell_lac,
{ "Cell LAC", "ansi_a_bsmap.cell_lac",
FT_UINT16, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_cell_mscid,
{ "Cell MSCID", "ansi_a_bsmap.cell_mscid",
FT_UINT24, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_pdsn_ip_addr,
{ "PDSN IP Address", "ansi_a_bsmap.pdsn_ip_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address", HFILL }
},
{ &hf_ansi_a_s_pdsn_ip_addr,
{ "Source PDSN Address", "ansi_a_bsmap.s_pdsn_ip_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address", HFILL }
},
{ &hf_ansi_a_anchor_ip_addr,
{ "Anchor PDSN Address", "ansi_a_bsmap.anchor_pdsn_ip_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address", HFILL }
},
{ &hf_ansi_a_anchor_pp_ip_addr,
{ "Anchor P-P Address", "ansi_a_bsmap.anchor_pp_ip_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address", HFILL }
},
{ &hf_ansi_a_so,
{ "Service Option", "ansi_a_bsmap.so",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cause_1,
{ "Cause", "ansi_a_bsmap.cause_1",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cause_2,
{ "Cause", "ansi_a_bsmap.cause_2",
FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_signal_type,
{ "Signal Type", "ansi_a_bsmap.ms_info_rec.signal.type",
FT_UINT8, BASE_HEX, VALS(ansi_a_ms_info_rec_signal_type_vals), 0xc0,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_signal_alert_pitch,
{ "Alert Type", "ansi_a_bsmap.ms_info_rec.signal.alert_pitch",
FT_UINT8, BASE_HEX, VALS(ansi_a_ms_info_rec_signal_alert_pitch_vals), 0x30,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_signal_tone,
{ "Signal", "ansi_a_bsmap.ms_info_rec.signal.tone",
FT_UINT16, BASE_HEX, VALS(ansi_a_ms_info_rec_signal_tone_vals), 0x0fc0,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_signal_isdn_alert,
{ "Signal", "ansi_a_bsmap.ms_info_rec.signal.isdn_alert",
FT_UINT16, BASE_HEX, VALS(ansi_a_ms_info_rec_signal_isdn_alert_vals), 0x0fc0,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_signal_is54b_alert,
{ "Signal", "ansi_a_bsmap.ms_info_rec.signal.is54b_alert",
FT_UINT16, BASE_HEX, VALS(ansi_a_ms_info_rec_signal_is54b_alert_vals), 0x0fc0,
NULL, HFILL }
},
{ &hf_ansi_a_ms_info_rec_call_waiting_ind,
{ "Call Waiting Indicator", "ansi_a_bsmap.ms_info_rec.call_waiting_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_extension_8_80,
{ "Extended", "ansi_a_bsmap.extended",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_generic,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_01,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_07,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_0c,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0c,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_0f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_10,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_18,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x18,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_1c,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x1c,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_1f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_3f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_7f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_80,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_c0,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_e0,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_f0,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_f8,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_fc,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_fe,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_8_ff,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_16_001f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT16, BASE_DEC, NULL, 0x001f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_16_003f,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT16, BASE_DEC, NULL, 0x003f,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_16_8000,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT16, BASE_DEC, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_16_f800,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT16, BASE_DEC, NULL, 0xf800,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_24_001800,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT24, BASE_DEC, NULL, 0x001800,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_24_006000,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT24, BASE_DEC, NULL, 0x006000,
NULL, HFILL }
},
{ &hf_ansi_a_reserved_bits_24_007000,
{ "Reserved bit(s)", "ansi_a_bsmap.reserved",
FT_UINT24, BASE_DEC, NULL, 0x007000,
NULL, HFILL }
},
{ &hf_ansi_a_channel_number,
{ "Channel Number", "ansi_a_bsmap.channel_number.channel_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_IOS5_channel_number,
{ "Channel Number", "ansi_a_bsmap.channel_number.channel_number",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ansi_a_speech_or_data_indicator,
{ "Speech or Data Indicator", "ansi_a_bsmap.channel_type.speech_or_data_indicator",
FT_UINT8, BASE_HEX, VALS(ansi_a_speech_or_data_indicator_vals), 0x00,
NULL, HFILL }
},
{ &hf_ansi_a_chan_rate_and_type,
{ "Channel Rate and Type", "ansi_a_bsmap.channel_type.rate_and_type",
FT_UINT8, BASE_HEX, VALS(ansi_a_channel_rate_and_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_ansi_a_speech_enc_or_data_rate,
{ "Speech Encoding Algorithm/data rate + Transparency Indicator", "ansi_a_bsmap.channel_type.speech_enc_or_data_rate",
FT_UINT8, BASE_HEX, VALS(ansi_a_speech_enc_or_data_rate_vals), 0x00,
NULL, HFILL }
},
{ &hf_ansi_a_chan_type_data_ext,
{ "Extension", "ansi_a_bsmap.channel_type.data_ext",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_chan_type_data_transparent,
{ "Transparent", "ansi_a_bsmap.channel_type.data_transparent",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_return_cause,
{ "Return Cause", "ansi_a_bsmap.return_cause.cause",
FT_UINT8, BASE_DEC, VALS(ansi_a_return_cause_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_rf_chan_id_color_code,
{ "Color Code", "ansi_a_bsmap.rf_channel_id.color_code",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rf_chan_id_n_amps_based,
{ "N-AMPS", "ansi_a_bsmap.rf_channel_id.n_amps_based",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_rf_chan_id_amps_based,
{ "ANSI/EIA/TIA-553", "ansi_a_bsmap.rf_channel_id.amps_based",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_rf_chan_id_timeslot,
{ "Timeslot Number", "ansi_a_bsmap.rf_channel_id.timeslot",
FT_UINT8, BASE_DEC, VALS(ansi_a_rf_chan_id_timeslot_number_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_rf_chan_id_channel_number,
{ "Channel Number", "ansi_a_bsmap.rf_channel_id.channel_number",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ansi_a_sr_id,
{ "SR_ID", "ansi_a_bsmap.sr_id",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_sid,
{ "SID", "ansi_a_bsmap.sid",
FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_hho,
{ "Hard Handoff", "ansi_a_bsmap.is95_chan_id.hho",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_num_chans_add,
{ "Number of Channels to Add", "ansi_a_bsmap.is95_chan_id.num_chans_add",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_frame_offset,
{ "Frame Offset", "ansi_a_bsmap.is95_chan_id.frame_offset",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_walsh_code_chan_idx,
{ "Walsh Code Channel Index", "ansi_a_bsmap.is95_chan_id.walsh_code_chan_idx",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_pilot_pn,
{ "Pilot PN Code", "ansi_a_bsmap.is95_chan_id.pilot_pn",
FT_UINT24, BASE_DEC, NULL, 0xff8000,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_power_combined,
{ "Power Combined", "ansi_a_bsmap.is95_chan_id.power_combined",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), 0x004000,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_freq_incl,
{ "Frequency Included", "ansi_a_bsmap.is95_chan_id.freq_incl",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), 0x002000,
NULL, HFILL }
},
{ &hf_ansi_a_is95_chan_id_channel_number,
{ "Channel Number", "ansi_a_bsmap.is95_chan_id.channel_number",
FT_UINT24, BASE_DEC, NULL, 0x0007ff,
NULL, HFILL }
},
{ &hf_ansi_a_enc_info_enc_parm_id,
{ "Encryption Parameter Identifier", "ansi_a_bsmap.enc_info.parm_id",
FT_UINT8, BASE_DEC, VALS(ansi_a_enc_info_ident_vals), 0x7c,
NULL, HFILL }
},
{ &hf_ansi_a_enc_info_status,
{ "Status", "ansi_a_bsmap.enc_info.status",
FT_UINT8, BASE_DEC, VALS(ansi_a_enc_info_status_vals), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_enc_info_available,
{ "Available", "ansi_a_bsmap.enc_info.available",
FT_UINT8, BASE_DEC, VALS(ansi_a_enc_info_available_vals), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_mob_p_rev,
{ "MOB_P_REV", "ansi_a_bsmap.cm2.mob_p_rev",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_see_list,
{ "See List of Entries", "ansi_a_bsmap.cm2.see_list",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_rf_power_cap,
{ "RF Power Capability", "ansi_a_bsmap.cm2.rf_power_cap",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_rf_power_cap_vals), 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_nar_an_cap,
{ "NAR_AN_CAP", "ansi_a_bsmap.cm2.nar_an_cap",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_is95,
{ "IS-95 supported", "ansi_a_bsmap.cm2.is95",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_slotted,
{ "Operating in slotted mode", "ansi_a_bsmap.cm2.slotted",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_dtx,
{ "DTX capable", "ansi_a_bsmap.cm2.dtx",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_mobile_term,
{ "Mobile Term; can receive incoming calls", "ansi_a_bsmap.cm2.mobile_term",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_analog_cap,
{ "ANSI/EIA/TIA-553; supports analog capabilities", "ansi_a_bsmap.cm2.ansi_eia_tia_553",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_psi,
{ "PACA Supported Indicator (PSI)", "ansi_a_bsmap.cm2.psi",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_len,
{ "SCM Length", "ansi_a_bsmap.cm2.scm_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm,
{ "Station Class Mark", "ansi_a_bsmap.cm2.scm",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_ext_scm_ind,
{ "Extended SCM Indicator", "ansi_a_bsmap.cm2.scm.ext_scm_ind",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_ext_scm_ind_vals), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_dual_mode,
{ "Dual Mode", "ansi_a_bsmap.cm2.scm.dual_mode",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_dual_mode_vals), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_slotted,
{ "Slotted Class", "ansi_a_bsmap.cm2.scm.slotted_class",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_slotted_class_vals), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_meid_configured,
{ "MEID support indicator", "ansi_a_bsmap.cm2.scm.meid_configured",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_meid_configured_vals), 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_25MHz_bandwidth,
{ "25 MHz Bandwidth", "ansi_a_bsmap.cm2.scm.25MHz_bandwidth",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_transmission,
{ "Transmission", "ansi_a_bsmap.cm2.scm.transmission",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_transmission_vals), 0x04,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_power_class,
{ "Power Class for Band Class 0 Analog Operation", "ansi_a_bsmap.cm2.scm.power_class",
FT_UINT8, BASE_DEC, VALS(ansi_a_cm2_scm_power_class_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_band_class_count,
{ "Count of Band Class Entries", "ansi_a_bsmap.cm2.scm.band_class_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cm2_scm_band_class_entry_len,
{ "Band Class Entry Length", "ansi_a_bsmap.cm2.scm.band_class_entry_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_band_class,
{ "Band Class", "ansi_a_bsmap.cm2.scm.bc_entry.band_class",
FT_UINT8, BASE_DEC, VALS(ansi_a_band_class_vals), 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode0_1,
{ "Air Interface OP_MODE0: CDMA mode in Band Class 1 and Band Class 4", "ansi_a_bsmap.cm2.scm.bc_entry.opmode0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode1_1,
{ "Air Interface OP_MODE1: CDMA mode in Band Class 0 and Band Class 3", "ansi_a_bsmap.cm2.scm.bc_entry.opmode1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode2_1,
{ "Air Interface OP_MODE2: Reserved (Previously Analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode3_1,
{ "Air Interface OP_MODE3: Reserved (Previously Wide analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode4_1,
{ "Air Interface OP_MODE4: Reserved (Previously Narrow analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode0_2,
{ "Air Interface OP_MODE0: CDMA mode", "ansi_a_bsmap.cm2.scm.bc_entry.opmode0",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode1_2,
{ "Air Interface OP_MODE1: CDMA mode", "ansi_a_bsmap.cm2.scm.bc_entry.opmode1",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode2_2,
{ "Air Interface OP_MODE2: Reserved (Previously Analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode2",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode3_2,
{ "Air Interface OP_MODE3: Reserved (Previously Wide analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode3",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode4_2,
{ "Air Interface OP_MODE4: Reserved (Previously Narrow analog mode)", "ansi_a_bsmap.cm2.scm.bc_entry.opmode4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode5_2,
{ "Air Interface OP_MODE5: DS-41", "ansi_a_bsmap.cm2.scm.bc_entry.opmode4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_opmode6_2,
{ "Air Interface OP_MODE6: MC-MAP", "ansi_a_bsmap.cm2.scm.bc_entry.opmode4",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_scm_band_class_entry_p_rev,
{ "Band Class MS Protocol Level", "ansi_a_bsmap.cm2.scm.bc_entry.p_rev",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_meid_mid_digit_1,
{ "MEID Hex Digit 1", "ansi_a_bsmap.mid.digit_1",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_imsi_mid_digit_1,
{ "Identity Digit 1", "ansi_a_bsmap.mid.digit_1",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_mid_odd_even_ind,
{ "Odd/Even Indicator", "ansi_a_bsmap.mid.odd_even_ind",
FT_UINT8, BASE_DEC, VALS(ansi_a_mid_odd_even_ind_vals), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_mid_type_of_id,
{ "Type of Identity", "ansi_a_bsmap.mid.type_of_identity",
FT_UINT8, BASE_DEC, VALS(ansi_a_mid_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_mid_broadcast_priority,
{ "Priority", "ansi_a_bsmap.mid.broadcast.priority",
FT_UINT8, BASE_DEC, VALS(ansi_a_mid_broadcast_priority_vals), 0xc0,
NULL, HFILL }
},
{ &hf_ansi_a_mid_broadcast_message_id,
{ "Message ID", "ansi_a_bsmap.mid.broadcast.message_id",
FT_UINT8, BASE_DEC, NULL, 0x2f,
NULL, HFILL }
},
{ &hf_ansi_a_mid_broadcast_zone_id,
{ "Zone ID", "ansi_a_bsmap.mid.broadcast.zone_id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_mid_broadcast_srvc_cat,
{ "Service Category", "ansi_a_bsmap.mid.broadcast.srvc_cat",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_mid_broadcast_language,
{ "Language", "ansi_a_bsmap.mid.broadcast.language",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_mid_unused,
{ "Unused", "ansi_a_bsmap.mid.unused",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_sci_sign,
{ "SCI Sign", "ansi_a_bsmap.slot_cycle_index_sign",
FT_UINT8, BASE_DEC, NULL, 0x08,
"1 indicates a negative sign is associated with the SCI", HFILL }
},
{ &hf_ansi_a_sci,
{ "Slot Cycle Index", "ansi_a_bsmap.slot_cycle_index",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_prio_call_priority,
{ "Call Priority Level", "ansi_a_bsmap.prio.call_priority",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL }
},
{ &hf_ansi_a_prio_queue_allowed,
{ "Queuing allowed", "ansi_a_bsmap.prio.queuing_allowed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_prio_preempt_allowed,
{ "Preemption allowed", "ansi_a_bsmap.prio.preempt_allowed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_mob_p_rev,
{ "MOB_P_REV", "ansi_a_bsmap.mob_p_rev",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_ansi_a_cause_1_ext,
{ "Extension", "ansi_a_bsmap.cause.ext",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_cause_2_ext,
{ "Extension", "ansi_a_bsmap.cause.ext",
FT_UINT16, BASE_DEC, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_ansi_a_cell_id_disc,
{ "Cell Identification Discriminator", "ansi_a_bsmap.cell_id_discriminator",
FT_UINT8, BASE_DEC, VALS(cell_disc_vals), 0x00,
NULL, HFILL }
},
{ &hf_ansi_a_cic,
{ "CIC", "ansi_a_bsmap.cic",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cic_pcm_multi,
{ "PCM Multiplexer", "ansi_a_bsmap.cic.pcm_multi",
FT_UINT16, BASE_DEC, NULL, 0xffe0,
NULL, HFILL }
},
{ &hf_ansi_a_cic_timeslot,
{ "Timeslot", "ansi_a_bsmap.cic.timeslot",
FT_UINT16, BASE_DEC, NULL, 0x001f,
NULL, HFILL }
},
{ &hf_ansi_a_cic_ext_cic,
{ "CIC", "ansi_a_bsmap.cic_ext.cic",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cic_ext_pcm_multi,
{ "PCM Multiplexer", "ansi_a_bsmap.cic_ext.pcm_multi",
FT_UINT16, BASE_DEC, NULL, 0xffe0,
NULL, HFILL }
},
{ &hf_ansi_a_cic_ext_timeslot,
{ "Timeslot", "ansi_a_bsmap.cic_ext.timeslot",
FT_UINT16, BASE_DEC, NULL, 0x001f,
NULL, HFILL }
},
{ &hf_ansi_a_cic_ext_circuit_mode,
{ "Circuit Mode", "ansi_a_bsmap.cic_ext.circuit_mode",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_ssci_mopd,
{ "Mobile Originated Position Determination", "ansi_a_bsmap.ssci.mopd",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_ssci_geci,
{ "Global Emergency Call Indication", "ansi_a_bsmap.ssci.geci",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_downlink_re_num_cells,
{ "Number of Cells", "ansi_a_bsmap.downlink_re.num_cells",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_downlink_re_sig_str_raw,
{ "Downlink Signal Strength Raw", "ansi_a_bsmap.downlink_re.sig_str_raw",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_downlink_re_cdma_towd,
{ "CDMA Target One Way Delay", "ansi_a_bsmap.downlink_re.cdma_towd",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_downlink_re_entry_env_len,
{ "Environment Length", "ansi_a_bsmap.downlink_re.entry.env_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_ho_pow_lev_num_cells,
{ "Number of Cells", "ansi_a_bsmap.ho_pow_lev.num_cells",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_ho_pow_lev_id_type,
{ "ID Type", "ansi_a_bsmap.ho_pow_lev.id_type",
FT_UINT8, BASE_DEC, NULL, 0x60,
NULL, HFILL }
},
{ &hf_ansi_a_ho_pow_lev_pow_lev,
{ "Handoff Power Level", "ansi_a_bsmap.ho_pow_lev.pow_lev",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_uz_id,
{ "UZID", "ansi_a_bsmap.uzid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_info_rec_req,
{ "Information Record Type", "ansi_a_bsmap.info_rec.rev_ms",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_otd,
{ "OTD", "ansi_a_bsmap.is2000_chan_id.otd",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
"1 indicates mobile is using OTD", HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_count,
{ "Physical Channel Count", "ansi_a_bsmap.is2000_chan_id.chan_count",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_frame_offset,
{ "Frame Offset", "ansi_a_bsmap.is2000_chan_id.frame_offset",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_chan_type,
{ "Physical Channel Type", "ansi_a_bsmap.is2000_chan_id.chan.chan_type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_rev_fch_gating,
{ "Rev_FCH_Gating", "ansi_a_bsmap.is2000_chan_id.chan.rev_fch_gating",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_rev_pilot_gating_rate,
{ "Reverse Pilot Gating Rate", "ansi_a_bsmap.is2000_chan_id.chan.rev_pilot_gating_rate",
FT_UINT16, BASE_DEC, VALS(ansi_a_is2000_chan_id_chan_rev_pilot_gating_rate_vals), 0x6000,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_qof_mask,
{ "QOF Mask", "ansi_a_bsmap.is2000_chan_id.chan.qof_mask",
FT_UINT16, BASE_DEC, NULL, 0x1800,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_walsh_code_chan_idx,
{ "Walsh Code Channel Index", "ansi_a_bsmap.is2000_chan_id.chan.walsh_code_chan_idx",
FT_UINT16, BASE_DEC, NULL, 0x7ff,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_pilot_pn_code,
{ "Pilot PN Code", "ansi_a_bsmap.is2000_chan_id.chan.pilot_pn_code",
FT_UINT24, BASE_DEC, NULL, 0xff8000,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_power_combined,
{ "Power Combined", "ansi_a_bsmap.is2000_chan_id.chan.power_combined",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), 0x001000,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_freq_incl,
{ "Frequency Included", "ansi_a_bsmap.is2000_chan_id.chan.freq_incl",
FT_BOOLEAN, 24, TFS(&tfs_yes_no), 0x000800,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_channel_number,
{ "Channel Number (ARFCN)", "ansi_a_bsmap.is2000_chan_id.chan.channel_number",
FT_UINT24, BASE_DEC, NULL, 0x0007ff,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_fdc_length,
{ "FDC Length", "ansi_a_bsmap.is2000_chan_id.chan.fdc_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_fdc_band_class,
{ "FDC Length", "ansi_a_bsmap.is2000_chan_id.chan.fdc_band_class",
FT_UINT16, BASE_DEC, VALS(ansi_a_band_class_vals), 0xf800,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_fdc_fwd_chan_freq,
{ "FDC Forward Channel Frequency", "ansi_a_bsmap.is2000_chan_id.chan.fdc_fwd_chan_freq",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_chan_id_chan_fdc_rev_chan_freq,
{ "FDC Reverse Channel Frequency", "ansi_a_bsmap.is2000_chan_id.chan.fdc_rev_chan_freq",
FT_UINT16, BASE_DEC, NULL, 0xffe0,
NULL, HFILL }
},
{ &hf_ansi_a_is95_ms_meas_chan_id_band_class,
{ "Band Class", "ansi_a_bsmap.is95_ms_meas_chan_id.band_class",
FT_UINT16, BASE_DEC, VALS(ansi_a_band_class_vals), 0xf800,
NULL, HFILL }
},
{ &hf_ansi_a_is95_ms_meas_chan_id_channel_number,
{ "Channel Number (ARFCN)", "ansi_a_bsmap.is95_ms_meas_chan_id.channel_number",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_ascii_num_ton,
{ "Type of Number", "ansi_a_bsmap.clg_party_ascii_num.ton",
FT_UINT8, BASE_DEC, VALS(ansi_a_clg_party_ascii_num_ton_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_ascii_num_plan,
{ "Numbering Plan Identification", "ansi_a_bsmap.clg_party_ascii_num.plan",
FT_UINT8, BASE_DEC, VALS(ansi_a_clg_party_ascii_num_plan_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_ascii_num_pi,
{ "Presentation Indicator", "ansi_a_bsmap.clg_party_ascii_num.pi",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_pi_vals), 0x60,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_ascii_num_si,
{ "Screening Indicator", "ansi_a_bsmap.clg_party_ascii_num.si",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_si_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_lai_mcc,
{ "Mobile Country Code (MCC)", "ansi_a_bsmap.lai.mcc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_lai_mnc,
{ "Mobile Network Code (MNC)", "ansi_a_bsmap.lai.mnc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_lai_lac,
{ "Location Area Code", "ansi_a_bsmap.lai.lac",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rej_cause,
{ "Reject Cause Value", "ansi_a_bsmap.rej_cause",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_auth_chlg_param_rand_num_type,
{ "Random Number Type", "ansi_a_bsmap.auth_chlg_param.rand_num_type",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_auth_chlg_param_rand,
{ "RAND/RANDU/RANDBS/RANDSSD Value", "ansi_a_bsmap.auth_chlg_param.rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_auth_resp_param_sig_type,
{ "Auth Signature Type", "ansi_a_bsmap.auth_resp_param.sig_type",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_auth_resp_param_sig,
{ "Auth Signature", "ansi_a_bsmap.auth_resp_param.sig",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_auth_param_count_count,
{ "Count", "ansi_a_bsmap.auth_param_count.count",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_mwi_num_messages,
{ "Number of Messages", "ansi_a_bsmap.mwi.num_messages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_signal_signal_value,
{ "Signal Value", "ansi_a_bsmap.signal.signal_value",
FT_UINT8, BASE_DEC, VALS(ansi_a_signal_signal_vals), 0,
NULL, HFILL }
},
{ &hf_ansi_a_signal_alert_pitch,
{ "Alert Pitch", "ansi_a_bsmap.signal.alert_pitch",
FT_UINT8, BASE_DEC, VALS(ansi_a_signal_alert_pitch_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_bcd_num_ton,
{ "Type of Number", "ansi_a_bsmap.clg_party_bcd_num.ton",
FT_UINT8, BASE_DEC, VALS(ansi_a_cld_party_bcd_num_ton_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_clg_party_bcd_num_plan,
{ "Numbering Plan Identification", "ansi_a_bsmap.clg_party_bcd_num.plan",
FT_UINT8, BASE_DEC, VALS(ansi_a_cld_party_bcd_num_plan_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_qos_params_packet_priority,
{ "Packet Priority", "ansi_a_bsmap.qos_params.packet_priority",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_cause_l3_coding_standard,
{ "Coding Standard", "ansi_a_bsmap.cause_l3.coding_standard",
FT_UINT8, BASE_DEC, VALS(ansi_a_cause_l3_coding_standard_vals), 0x60,
NULL, HFILL }
},
{ &hf_ansi_a_cause_l3_location,
{ "Location", "ansi_a_bsmap.cause_l3.location",
FT_UINT8, BASE_DEC, VALS(ansi_a_cause_l3_location_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_cause_l3_class,
{ "Class", "ansi_a_bsmap.cause_l3.class",
FT_UINT8, BASE_DEC, VALS(ansi_a_cause_l3_class_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_cause_l3_value_without_class,
{ "Value (Without class)", "ansi_a_bsmap.cause_l3.value_without_class",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_cause_l3_value,
{ "Value", "ansi_a_bsmap.cause_l3.value",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_auth_conf_param_randc,
{ "RANDC", "ansi_a_bsmap.auth_conf_param.randc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_xmode_tfo_mode,
{ "TFO Mode", "ansi_a_bsmap.xmode.tfo_mode",
FT_BOOLEAN, 8, TFS(&tfs_ansi_a_xmode_tfo_mode), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_reg_type_type,
{ "Location Registration Type", "ansi_a_bsmap.reg_type.type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_tag_value,
{ "Tag value", "ansi_a_bsmap.tag.value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_band_class,
{ "Band Class", "ansi_a_bsmap.hho_params.band_class",
FT_UINT8, BASE_DEC, VALS(ansi_a_band_class_vals), 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_num_pream_frames,
{ "Number of Preamble Frames", "ansi_a_bsmap.hho_params.num_pream_frames",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_reset_l2,
{ "Reset L2", "ansi_a_bsmap.hho_params.reset_l2",
FT_BOOLEAN, 8, TFS(&tfs_l2_reset_dont_reset), 0x10,
"1 means reset Layer 2 Ack", HFILL }
},
{ &hf_ansi_a_hho_params_reset_fpc,
{ "Reset FPC", "ansi_a_bsmap.hho_params.reset_fpc",
FT_BOOLEAN, 8, TFS(&tfs_fpc_reset_dont_reset), 0x08,
"1 means reset counters", HFILL }
},
{ &hf_ansi_a_hho_params_enc_mode,
{ "Encryption Mode", "ansi_a_bsmap.hho_params.enc_mode",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x06,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_private_lcm,
{ "Private LCM", "ansi_a_bsmap.hho_params.private_lcm",
FT_BOOLEAN, 8, TFS(&tfs_use_dont_use), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_rev_pwr_cntl_delay_incl,
{ "Rev_Pwr_Cntl_Delay_Incl", "ansi_a_bsmap.hho_params.rev_pwr_cntl_delay_incl",
FT_BOOLEAN, 8, TFS(&tfs_use_dont_use), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_rev_pwr_cntl_delay,
{ "Rev_Pwr_Cntl_Delay", "ansi_a_bsmap.hho_params.rev_pwr_cntl_delay",
FT_UINT8, BASE_DEC, NULL, 0x60,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_nom_pwr_ext,
{ "Nom_Pwr_Ext", "ansi_a_bsmap.hho_params.nom_pwr_ext",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_nom_pwr,
{ "Nom_Pwr", "ansi_a_bsmap.hho_params.nom_pwr",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_fpc_subchan_info,
{ "FPC Subchannel Information", "ansi_a_bsmap.hho_params.fpc_subchan_info",
FT_UINT8, BASE_DEC, NULL, 0x3e,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_fpc_subchan_info_incl,
{ "FPC Subchannel Info Included", "ansi_a_bsmap.hho_params.fpc_subchan_info_incl",
FT_BOOLEAN, 8, TFS(&tfs_use_dont_use), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_pwr_cntl_step,
{ "Power Control Step", "ansi_a_bsmap.hho_params.pwr_cntl_step",
FT_UINT8, BASE_DEC, NULL, 0x0e,
NULL, HFILL }
},
{ &hf_ansi_a_hho_params_pwr_cntl_step_incl,
{ "Power Control Step Included", "ansi_a_bsmap.hho_params.pwr_cntl_step_incl",
FT_BOOLEAN, 8, TFS(&tfs_use_dont_use), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_sw_ver_major,
{ "IOS Major Revision Level", "ansi_a_bsmap.sw_ver.major",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_sw_ver_minor,
{ "IOS Minor Revision Level", "ansi_a_bsmap.sw_ver.minor",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_sw_ver_point,
{ "IOS Point Release Level", "ansi_a_bsmap.sw_ver.point",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_so_proprietary_ind,
{ "Proprietary Indicator", "ansi_a_bsmap.so.proprietary_ind",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
NULL, HFILL }
},
{ &hf_ansi_a_so_revision,
{ "Service Option Revision", "ansi_a_bsmap.so.revision",
FT_UINT16, BASE_DEC, NULL, 0x7000,
NULL, HFILL }
},
{ &hf_ansi_a_so_base_so_num,
{ "Base Service Option Number", "ansi_a_bsmap.so.base_so_num",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_ansi_a_soci,
{ "Service Option Connection Identifier", "ansi_a_bsmap.soci",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_so_list_num,
{ "Number of Service Option instances", "ansi_a_bsmap.so_list.num",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_so_list_sr_id,
{ "SR_ID", "ansi_a_bsmap.so_list.sr_id",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL }
},
{ &hf_ansi_a_so_list_soci,
{ "SOCI", "ansi_a_bsmap.so_list.soci",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_nid,
{ "NID", "ansi_a_bsmap.nid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_pzid,
{ "PZID", "ansi_a_bsmap.pzid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_adds_user_part_burst_type,
{ "Data Burst Type", "ansi_a_bsmap.adds_user_part.burst_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_adds_vals), 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_adds_user_part_ext_burst_type,
{ "Extended Burst Type", "ansi_a_bsmap.adds_user_part.ext_burst_type",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_adds_user_part_ext_data,
{ "Data", "ansi_a_bsmap.adds_user_part.ext_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_adds_user_part_unknown_data,
{ "Data", "ansi_a_bsmap.adds_user_part.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_amps_hho_params_enc_mode,
{ "Encryption Mode", "ansi_a_bsmap.amps_hho_params.enc_mode",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_scr.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_for_mux_option,
{ "FOR_MUX_OPTION: Forward Traffic Channel multiplex option", "ansi_a_bsmap.is2000_scr.for_mux_opt",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_rev_mux_option,
{ "REV_MUX_OPTION: Reverse Traffic Channel multiplex option", "ansi_a_bsmap.is2000_scr.rev_mux_opt",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_for_fch_rate,
{ "FOR_RATES: Transmission rates of the Forward Fundamental Channel", "ansi_a_bsmap.is2000_scr.for_fch_rate",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_rev_fch_rate,
{ "REV_RATES: Transmission rates of the Reverse Fundamental Channel", "ansi_a_bsmap.is2000_scr.rev_fch_rate",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_num_socr,
{ "NUM_CON_REC: Number of service option connection records", "ansi_a_bsmap.is2000_scr.num_socr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_soc_ref,
{ "CON_REF: Service option connection reference", "ansi_a_bsmap.is2000_scr.socr.soc_ref",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_so,
{ "SERVICE_OPTION", "ansi_a_bsmap.is2000_scr.socr.so",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_for_chan_type,
{ "FOR_TRAFFIC", "ansi_a_bsmap.is2000_scr.socr.for_chan_type",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rev_chan_type,
{ "REV_TRAFFIC", "ansi_a_bsmap.is2000_scr.socr.rev_chan_type",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_ui_enc_mode,
{ "UI_ENCRYPT_MODE: Encryption mode indicator for user information privacy", "ansi_a_bsmap.is2000_scr.socr.ui_enc_mode",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_sr_id,
{ "SR_ID: Service reference identifier", "ansi_a_bsmap.is2000_scr.socr.sr_id",
FT_UINT8, BASE_DEC, NULL, 0x1c,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rlp_info_incl,
{ "RLP_INFO_INCL: RLP information included indicator", "ansi_a_bsmap.is2000_scr.socr.rlp_info_incl",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rlp_blob_len,
{ "RLP_BLOB_LEN", "ansi_a_bsmap.is2000_scr.socr.rlp_blob_len",
FT_UINT16, BASE_DEC, NULL, 0x01E0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rlp_blob_msb,
{ "RLP_BLOB (MSB)", "ansi_a_bsmap.is2000_scr.socr.rlp_blob_msb",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rlp_blob,
{ "RLP_BLOB", "ansi_a_bsmap.is2000_scr.socr.rlp_blob",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rlp_blob_lsb,
{ "RLP_BLOB (LSB)", "ansi_a_bsmap.is2000_scr.socr.rlp_blob_lsb",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_fch_cc_incl,
{ "FCH_CC_INCL: Channel configuration for the Fundamental Channel included indicator", "ansi_a_bsmap.is2000_scr.socr.fch_cc_incl",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_fch_frame_size_support_ind,
{ "FCH_FRAME_SIZE: Fundamental Channel frame size supported indicator", "ansi_a_bsmap.is2000_scr.socr.fch_frame_size_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_for_fch_rc,
{ "FOR_FCH_RC: Forward Fundamental Channel Radio Configuration", "ansi_a_bsmap.is2000_scr.socr.for_fch_rc",
FT_UINT8, BASE_DEC, NULL, 0x3e,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_scr_socr_rev_fch_rc,
{ "REV_FCH_RC", "ansi_a_bsmap.is2000_scr.socr.rev_fch_rc",
FT_UINT16, BASE_DEC, NULL, 0x01F0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_nn_scr_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_nn_scr.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_nn_scr_content,
{ "IS-2000 Non-Negotiable Service Configuration Record Content", "ansi_a_bsmap.is2000_nn_scr.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_nn_scr_fill_bits,
{ "Fill Bits", "ansi_a_bsmap.is2000_nn_scr.fill_bits",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_rev_pdch_support_ind,
{ "REV_PDCH: IS-2000 R-PDCH supported", "ansi_a_bsmap.is2000_mob_cap.rev_pdch_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_for_pdch_support_ind,
{ "FOR_PDCH: IS-2000 F-PDCH supported", "ansi_a_bsmap.is2000_mob_cap.for_pdch_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_eram_support_ind,
{ "ERAM: Enhanced Rate Adaptation Mode supported", "ansi_a_bsmap.is2000_mob_cap.eram_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_dcch_support_ind,
{ "DCCH: IS-2000 DCCH supported", "ansi_a_bsmap.is2000_mob_cap.dcch_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_support_ind,
{ "FCH: IS-2000 FCH supported", "ansi_a_bsmap.is2000_mob_cap.fch_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_otd_support_ind,
{ "OTD: Orthogonal Transmit Diversity supported", "ansi_a_bsmap.is2000_mob_cap.otd_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_enh_rc_cfg_support_ind,
{ "Enhanced RC CFG Supported: Radio configuration in radio class 2 supported", "ansi_a_bsmap.is2000_mob_cap.enh_rc_cfg_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_qpch_support_ind,
{ "QPCH Supported: Quick Paging Channel supported", "ansi_a_bsmap.is2000_mob_cap.qpch_support_ind",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_octet_len,
{ "FCH Information: Bit-Exact Length Octet Count", "ansi_a_bsmap.is2000_mob_cap.fch_info.octet_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_geo_loc_type,
{ "Geo Location Type", "ansi_a_bsmap.is2000_mob_cap.fch_info.geo_loc_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_is2000_mob_cap_fch_info_geo_loc_type_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_geo_loc_incl,
{ "Geo Location Included", "ansi_a_bsmap.is2000_mob_cap.fch_info.geo_loc_incl",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_mob_cap.fch_info.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_content,
{ "FCH Information Content", "ansi_a_bsmap.is2000_mob_cap.fch_info.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_fch_info_fill_bits,
{ "Fill Bits", "ansi_a_bsmap.is2000_mob_cap.fch_info.fill_bits",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_dcch_info_octet_len,
{ "DCCH Information: Bit-Exact Length Octet Count", "ansi_a_bsmap.is2000_mob_cap.dcch_info.octet_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_dcch_info_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_mob_cap.dcch_info.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_dcch_info_content,
{ "DCCH Information Content", "ansi_a_bsmap.is2000_mob_cap.dcch_info.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_dcch_info_fill_bits,
{ "Fill Bits", "ansi_a_bsmap.is2000_mob_cap.dcch_info.fill_bits",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_for_pdch_info_octet_len,
{ "FOR_PDCH Information: Bit-Exact Length Octet Count", "ansi_a_bsmap.is2000_mob_cap.for_pdch_info.octet_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_for_pdch_info_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_mob_cap.for_pdch_info.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_for_pdch_info_content,
{ "FOR_PDCH Information Content", "ansi_a_bsmap.is2000_mob_cap.for_pdch_info.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_for_pdch_info_fill_bits,
{ "Fill Bits", "ansi_a_bsmap.is2000_mob_cap.for_pdch_info.fill_bits",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_rev_pdch_info_octet_len,
{ "REV_PDCH Information: Bit-Exact Length Octet Count", "ansi_a_bsmap.is2000_mob_cap.rev_pdch_info.octet_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_rev_pdch_info_num_fill_bits,
{ "Bit-Exact Length Fill Bits", "ansi_a_bsmap.is2000_mob_cap.rev_pdch_info.num_fill_bits",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_rev_pdch_info_content,
{ "REV_PDCH Information Content", "ansi_a_bsmap.is2000_mob_cap.rev_pdch_info.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_rev_pdch_info_fill_bits,
{ "Fill Bits", "ansi_a_bsmap.is2000_mob_cap.rev_pdch_info.fill_bits",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support,
{ "VP Algorithms Supported", "ansi_a_bsmap.is2000_mob_cap.vp_support",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a7,
{ "VP Algorithm A7", "ansi_a_bsmap.is2000_mob_cap.vp_support.a7",
FT_BOOLEAN, 8, TFS(&tfs_reserved_no_voice_privacy), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a6,
{ "VP Algorithm A6", "ansi_a_bsmap.is2000_mob_cap.vp_support.a6",
FT_BOOLEAN, 8, TFS(&tfs_reserved_no_voice_privacy), 0x20,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a5,
{ "VP Algorithm A5", "ansi_a_bsmap.is2000_mob_cap.vp_support.a5",
FT_BOOLEAN, 8, TFS(&tfs_reserved_no_voice_privacy), 0x10,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a4,
{ "VP Algorithm A4", "ansi_a_bsmap.is2000_mob_cap.vp_support.a4",
FT_BOOLEAN, 8, TFS(&tfs_reserved_no_voice_privacy), 0x08,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a3,
{ "VP Algorithm A3", "ansi_a_bsmap.is2000_mob_cap.vp_support.a3",
FT_BOOLEAN, 8, TFS(&tfs_reserved_no_voice_privacy), 0x04,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a2,
{ "VP Algorithm A2", "ansi_a_bsmap.is2000_mob_cap.vp_support.a2",
FT_BOOLEAN, 8, TFS(&tfs_reserved_aes), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_mob_cap_vp_support_a1,
{ "VP Algorithm A1", "ansi_a_bsmap.is2000_mob_cap.vp_support.a1",
FT_BOOLEAN, 8, TFS(&tfs_reserved_private_long_code), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_protocol_type,
{ "Protocol Type", "ansi_a_bsmap.protocol_type",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_cld_pn_num_type,
{ "Forward MS Information Record Called Party Number: Number Type", "ansi_a_bsmap.fwd_ms_info_rec.cld_pn.num_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_num_type_vals), 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_cld_pn_num_plan,
{ "Forward MS Information Record Called Party Number: Number Plan", "ansi_a_bsmap.fwd_ms_info_rec.cld_pn.num_plan",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_num_plan_vals), 0x1e,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_cld_pn_num,
{ "Forward MS Information Record Called Party Number: Number", "ansi_a_bsmap.fwd_ms_info_rec.cld_pn.num",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_clg_pn_num_type,
{ "Forward MS Information Record Calling Party Number: Number Type", "ansi_a_bsmap.fwd_ms_info_rec.clg_pn.num_type",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_num_type_vals), 0xe000,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_clg_pn_num_plan,
{ "Forward MS Information Record Calling Party Number: Number Plan", "ansi_a_bsmap.fwd_ms_info_rec.clg_pn.num_plan",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_num_plan_vals), 0x1e00,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_clg_pn_num,
{ "Forward MS Information Record Calling Party Number: Number", "ansi_a_bsmap.fwd_ms_info_rec.clg_pn.num",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_clg_pn_pi,
{ "Forward MS Information Record Calling Party Number: PI", "ansi_a_bsmap.fwd_ms_info_rec.clg_pn.pi",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_pi_vals), 0x0180,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_clg_pn_si,
{ "Forward MS Information Record Calling Party Number: SI", "ansi_a_bsmap.fwd_ms_info_rec.clg_pn.si",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_si_vals), 0x0060,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_mw_num,
{ "Number of messages waiting", "ansi_a_bsmap.fwd_ms_info_rec.mw.num",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_fwd_ms_info_rec_content,
{ "Forward MS Information Record Content", "ansi_a_bsmap.fwd_ms_info_rec.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_cld_pn_num_type,
{ "Reverse MS Information Record Called Party Number: Number Type", "ansi_a_bsmap.rev_ms_info_rec.cld_pn.num_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_num_type_vals), 0xe0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_cld_pn_num_plan,
{ "Reverse MS Information Record Called Party Number: Number Plan", "ansi_a_bsmap.rev_ms_info_rec.cld_pn.num_plan",
FT_UINT8, BASE_DEC, VALS(ansi_a_ms_info_rec_num_plan_vals), 0x1e,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_cld_pn_num,
{ "Reverse MS Information Record Called Party Number: Number", "ansi_a_bsmap.rev_ms_info_rec.cld_pn.num",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_clg_pn_num_type,
{ "Reverse MS Information Record Calling Party Number: Number Type", "ansi_a_bsmap.rev_ms_info_rec.clg_pn.num_type",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_num_type_vals), 0xe000,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_clg_pn_num_plan,
{ "Reverse MS Information Record Calling Party Number: Number Plan", "ansi_a_bsmap.rev_ms_info_rec.clg_pn.num_plan",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_num_plan_vals), 0x1e00,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_clg_pn_pi,
{ "Reverse MS Information Record Calling Party Number: PI", "ansi_a_bsmap.rev_ms_info_rec.clg_pn.pi",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_pi_vals), 0x0180,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_clg_pn_si,
{ "Reverse MS Information Record Calling Party Number: SI", "ansi_a_bsmap.rev_ms_info_rec.clg_pn.si",
FT_UINT16, BASE_DEC, VALS(ansi_a_ms_info_rec_clg_pn_si_vals), 0x0060,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_clg_pn_num,
{ "Reverse MS Information Record Calling Party Number: Number", "ansi_a_bsmap.rev_ms_info_rec.clg_pn.num",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_so_info_fwd_support,
{ "Forward Support", "ansi_a_bsmap.rev_ms_info_rec.so_info.fwd_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_so_info_rev_support,
{ "Reverse Support", "ansi_a_bsmap.rev_ms_info_rec.so_info.rev_support",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_so_info_so,
{ "Service Option", "ansi_a_bsmap.rev_ms_info_rec.so_info.so",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_ms_info_rec_content,
{ "Reverse MS Information Record Content", "ansi_a_bsmap.rev_ms_info_rec.content",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_srch_win_a,
{ "Search Window A Size (Srch_Win_A)", "ansi_a_bsmap.ext_ho_dir_params.srch_win_a",
FT_UINT8, BASE_DEC, VALS(ansi_a_srch_win_sizes_vals), 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_srch_win_n,
{ "Search Window N Size (Srch_Win_N)", "ansi_a_bsmap.ext_ho_dir_params.srch_win_n",
FT_UINT8, BASE_DEC, VALS(ansi_a_srch_win_sizes_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_srch_win_r,
{ "Search Window R Size (Srch_Win_R)", "ansi_a_bsmap.ext_ho_dir_params.srch_win_r",
FT_UINT8, BASE_DEC, VALS(ansi_a_srch_win_sizes_vals), 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_t_add,
{ "Add Pilot Threshold (T_Add)", "ansi_a_bsmap.ext_ho_dir_params.t_add",
FT_UINT16, BASE_DEC, NULL, 0x0fc0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_t_drop,
{ "Drop Pilot Threshold (T_Drop)", "ansi_a_bsmap.ext_ho_dir_params.t_drop",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_t_comp,
{ "Compare Threshold (T_Comp)", "ansi_a_bsmap.ext_ho_dir_params.t_comp",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_t_tdrop,
{ "Drop Timer Value (T_TDrop)", "ansi_a_bsmap.ext_ho_dir_params.t_tdrop",
FT_UINT8, BASE_DEC, VALS(ansi_a_t_tdrop_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_nghbor_max_age,
{ "Neighbor Max Age (Nghbor_Max_AGE)", "ansi_a_bsmap.ext_ho_dir_params.nghbor_max_age",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_target_bs_values_incl,
{ "Target BS Values Included", "ansi_a_bsmap.ext_ho_dir_params.target_bs_values_incl",
FT_UINT8, BASE_DEC, VALS(ansi_a_ext_ho_dir_params_target_bs_values_incl_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_soft_slope,
{ "SOFT_SLOPE", "ansi_a_bsmap.ext_ho_dir_params.soft_slope",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_add_intercept,
{ "ADD_INTERCEPT", "ansi_a_bsmap.ext_ho_dir_params.add_intercept",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_drop_intercept,
{ "DROP_INTERCEPT", "ansi_a_bsmap.ext_ho_dir_params.drop_intercept",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_ansi_a_ext_ho_dir_params_target_bs_p_rev,
{ "Target BS P_REV", "ansi_a_bsmap.ext_ho_dir_params.target_bs_p_rev",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cdma_sowd_sowd,
{ "CDMA Serving One Way Delay", "ansi_a_bsmap.cdma_sowd.sowd",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cdma_sowd_resolution,
{ "Resolution", "ansi_a_bsmap.cdma_sowd.resolution",
FT_UINT8, BASE_DEC, VALS(ansi_a_cdma_sowd_resolution_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_cdma_sowd_timestamp,
{ "CDMA Serving One Way Delay Time Stamp", "ansi_a_bsmap.cdma_sowd.timestamp",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_re_res_prio_incl,
{ "Include Priority", "ansi_a_bsmap.re_res.prio_incl",
FT_BOOLEAN, 8, TFS(&tfs_prio_incl_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_ansi_a_re_res_forward,
{ "Forward", "ansi_a_bsmap.re_res.forward",
FT_UINT8, BASE_DEC, VALS(ansi_a_re_res_vals), 0x30,
NULL, HFILL }
},
{ &hf_ansi_a_re_res_reverse,
{ "Reverse", "ansi_a_bsmap.re_res.reverse",
FT_UINT8, BASE_DEC, VALS(ansi_a_re_res_vals), 0x0c,
NULL, HFILL }
},
{ &hf_ansi_a_re_res_alloc,
{ "Alloc", "ansi_a_bsmap.re_res.alloc",
FT_BOOLEAN, 8, TFS(&tfs_alloc_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_re_res_avail,
{ "Avail", "ansi_a_bsmap.re_res.avail",
FT_BOOLEAN, 8, TFS(&tfs_avail_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_cld_party_ascii_num_ton,
{ "Type of Number", "ansi_a_bsmap.cld_party_ascii_num.ton",
FT_UINT8, BASE_DEC, VALS(ansi_a_cld_party_bcd_num_ton_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_cld_party_ascii_num_plan,
{ "Numbering Plan Identification", "ansi_a_bsmap.cld_party_ascii_num.plan",
FT_UINT8, BASE_DEC, VALS(ansi_a_cld_party_bcd_num_plan_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_band_class,
{ "Band Class", "ansi_a_bsmap.band_class",
FT_UINT8, BASE_DEC, VALS(ansi_a_band_class_vals), 0x1f,
NULL, HFILL }
},
{ &hf_ansi_a_is2000_cause,
{ "Cause", "ansi_a_bsmap.is2000_cause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_auth_event,
{ "Event", "ansi_a_bsmap.auth_event",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_psmm_count,
{ "PSMM Count", "ansi_a_bsmap.psmm_count",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_geo_loc,
{ "Calling Geodetic Location (CGL)", "ansi_a_bsmap.geo_loc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_all_circuits,
{ "All Circuits", "ansi_a_bsmap.cct_group.all_circuits",
FT_BOOLEAN, 8, TFS(&tfs_avail_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_inclusive,
{ "Inclusive", "ansi_a_bsmap.cct_group.inclusive",
FT_BOOLEAN, 8, TFS(&tfs_avail_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_count,
{ "Count", "ansi_a_bsmap.cct_group.count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_first_cic,
{ "First CIC", "ansi_a_bsmap.cct_group.first_cic",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_first_cic_pcm_multi,
{ "First CIC PCM Multiplexer", "ansi_a_bsmap.cct_group.first_cic.pcm_multi",
FT_UINT16, BASE_DEC, NULL, 0xffe0,
NULL, HFILL }
},
{ &hf_ansi_a_cct_group_first_cic_timeslot,
{ "First CIC Timeslot", "ansi_a_bsmap.cct_group.first_cic.timeslot",
FT_UINT16, BASE_DEC, NULL, 0x001f,
NULL, HFILL }
},
{ &hf_ansi_a_paca_timestamp_queuing_time,
{ "PACA Queuing Time", "ansi_a_bsmap.paca_timestamp.queuing_time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_paca_order_action_reqd,
{ "PACA Action Required", "ansi_a_bsmap.paca_order.action_reqd",
FT_UINT8, BASE_DEC, VALS(ansi_a_paca_order_action_reqd_vals), 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_paca_reoi_pri,
{ "PACA Reorigination Indicator (PRI)", "ansi_a_bsmap.paca_reoi.pri",
FT_BOOLEAN, 8, TFS(&tfs_reoi_pri_reorig_no_reorig), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_max_frames,
{ "Max Frames", "ansi_a_bsmap.a2p_bearer_sess.max_frames",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_ip_addr_type,
{ "Session IP Address Type", "ansi_a_bsmap.a2p_bearer_sess.ip_addr_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_ip_addr_type_vals), 0x06,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_addr_flag,
{ "Session Address Flag", "ansi_a_bsmap.a2p_bearer_sess.addr_flag",
FT_BOOLEAN, 8, TFS(&tfs_a2p_bearer_sess_addr_flag), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_ipv4_addr,
{ "Session IP Address", "ansi_a_bsmap.a2p_bearer_sess.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_ipv6_addr,
{ "Session IP Address", "ansi_a_bsmap.a2p_bearer_sess.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_sess_udp_port,
{ "Session UDP Port", "ansi_a_bsmap.a2p_bearer_sess.udp_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_num_formats,
{ "Number of Bearer Formats", "ansi_a_bsmap.a2p_bearer_form.num_formats",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_ip_addr_type,
{ "Bearer IP Address Type", "ansi_a_bsmap.a2p_bearer_form.ip_addr_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_ip_addr_type_vals), 0x03,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_len,
{ "Bearer Format Length", "ansi_a_bsmap.a2p_bearer_form.format.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_tag_type,
{ "Bearer Format Tag Type", "ansi_a_bsmap.a2p_bearer_form.format.tag_type",
FT_UINT8, BASE_DEC, VALS(ansi_a_a2p_bearer_form_format_tag_type_vals), 0x70,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_format_id,
{ "Bearer Format ID", "ansi_a_bsmap.a2p_bearer_form.format.format_id",
FT_UINT8, BASE_DEC, VALS(ansi_a_a2p_bearer_form_format_format_id_vals), 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_rtp_payload_type,
{ "RTP Payload Type", "ansi_a_bsmap.a2p_bearer_form.format.rtp_payload_type",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_bearer_addr_flag,
{ "Bearer Address Flag", "ansi_a_bsmap.a2p_bearer_form.format.bearer_addr_flag",
FT_BOOLEAN, 8, TFS(&tfs_a2p_bearer_form_format_bearer_addr_flag), 0x01,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_ipv4_addr,
{ "Bearer IP Address", "ansi_a_bsmap.a2p_bearer_form.format.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_ipv6_addr,
{ "Bearer IP Address", "ansi_a_bsmap.a2p_bearer_form.format.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_udp_port,
{ "Bearer UDP Port", "ansi_a_bsmap.a2p_bearer_form.format.udp_port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_ext_len,
{ "Extension Length", "ansi_a_bsmap.a2p_bearer_form.format.ext_len",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_a2p_bearer_form_format_ext_id,
{ "Extension ID", "ansi_a_bsmap.a2p_bearer_form.format.ext_id",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_ansi_a_ms_des_freq_band_class,
{ "Band Class", "ansi_a_bsmap.ms_des_freq.band_class",
FT_UINT16, BASE_DEC, VALS(ansi_a_band_class_vals), 0xf800,
NULL, HFILL }
},
{ &hf_ansi_a_ms_des_freq_cdma_channel,
{ "CDMA Channel", "ansi_a_bsmap.ms_des_freq.cdma_channel",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ansi_a_plcm_id_plcm_type,
{ "PLCM_TYPE", "ansi_a_bsmap.plcm_id.plcm_type",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ansi_a_bdtmf_trans_info_dtmf_off_len,
{ "DTMF Off Length", "ansi_a_bsmap.bdtmf_trans_info.dtmf_off_len",
FT_UINT8, BASE_DEC, VALS(ansi_a_bdtmf_trans_info_dtmf_off_len_vals), 0x38,
NULL, HFILL }
},
{ &hf_ansi_a_bdtmf_trans_info_dtmf_on_len,
{ "DTMF On Length", "ansi_a_bsmap.bdtmf_trans_info.dtmf_on_len",
FT_UINT8, BASE_DEC, VALS(ansi_a_bdtmf_trans_info_dtmf_on_len_vals), 0x07,
NULL, HFILL }
},
{ &hf_ansi_a_bdtmf_chars_num_chars,
{ "DTMF Number of Characters", "ansi_a_bsmap.bdtmf_chars.num_chars",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_bdtmf_chars_digits,
{ "DTMF Digits", "ansi_a_bsmap.bdtmf_chars.digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_encryption_parameter_value,
{ "Encryption Parameter value", "ansi_a_bsmap.encryption_parameter_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_layer3_info,
{ "Layer 3 Information", "ansi_a_bsmap.layer3_info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_manufacturer_software_info,
{ "Manufacturer/Carrier Software Information", "ansi_a_bsmap.manufacturer_software_info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_circuit_bitmap,
{ "Circuit Bitmap", "ansi_a_bsmap.circuit_bitmap",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_extension_parameter_value,
{ "Extension Parameter value", "ansi_a_bsmap.extension_parameter_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_msb_first_digit,
{ "MSB of first digit", "ansi_a_bsmap.msb_first_digit",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_dcch_cc_incl,
{ "DCCH_CC_INCL (Channel configuration for the Dedicated Control Channel included indicator)", "ansi_a_bsmap.dcch_cc_incl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_for_sch_cc_incl,
{ "FOR_SCH_CC_INCL (Channel configuration for the Dedicated Control Channel included indicator)", "ansi_a_bsmap.for_sch_cc_incl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_rev_sch_cc_incl,
{ "REV_SCH_CC_INCL (Channel configuration for the Dedicated Control Channel included indicator)", "ansi_a_bsmap.rev_sch_cc_incl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_a_plcm42,
{ "PLCM_42", "ansi_a_bsmap.plcm42",
FT_BOOLEAN, 56, NULL, G_GUINT64_CONSTANT(0x3FFFFFFFFFF),
NULL, HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_ansi_a_extraneous_data,
{ "ansi_a.extraneous_data", PI_PROTOCOL, PI_NOTE,
"Extraneous Data - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_short_data,
{ "ansi_a.short_data", PI_PROTOCOL, PI_NOTE,
"Short Data (?) - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_missing_mand_elem,
{ "ansi_a.missing_mand_elem", PI_PROTOCOL, PI_WARN,
"Missing Mandatory element, rest of dissection is suspect - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_unknown_format,
{ "ansi_a.unknown_format", PI_PROTOCOL, PI_WARN,
"Format Unknown/Unsupported - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_no_tlv_elem_diss,
{ "ansi_a.no_tlv_elem_dissector", PI_PROTOCOL, PI_NOTE,
"No TLV element dissector - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_no_tv_elem_diss,
{ "ansi_a.no_tv_elem_dissector", PI_PROTOCOL, PI_WARN ,
"No TV element dissector, rest of dissection is suspect - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_no_lv_elem_diss,
{ "ansi_a.no_lv_elem_dissector", PI_PROTOCOL, PI_NOTE,
"No LV element dissector - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_no_v_elem_diss,
{ "ansi_a.no_v_elem_dissector", PI_PROTOCOL, PI_WARN ,
"No V element dissector, rest of dissection is suspect - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_miss_dtap_msg_diss,
{ "ansi_a.miss_dtap_msg_dissector", PI_PROTOCOL, PI_NOTE,
"Missing DTAP message dissector - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_miss_bsmap_msg_diss,
{ "ansi_a.miss_bsmap_msg_dissector", PI_PROTOCOL, PI_NOTE,
"Missing BSMAP message dissector - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_is2000_chan_id_pilot_pn,
{ "ansi_a.is2000_chan_id_pilot_pn", PI_PROTOCOL, PI_NOTE,
"This parameter has a unique encoding. The most significant bit comes after the LSBs unlike typical IOS octet split values.",
EXPFILL }
},
{ &ei_ansi_a_unknown_dtap_msg,
{ "ansi_a.unknown_dtap_msg", PI_PROTOCOL, PI_WARN,
"DTAP Message Unknown/Unsupported - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_unknown_bsmap_msg,
{ "ansi_a.unknown_bsmap_msg", PI_PROTOCOL, PI_WARN,
"BSMAP Message Unknown/Unsupported - try checking decoder variant preference or dissector bug/later version spec (report to wireshark.org)",
EXPFILL }
},
{ &ei_ansi_a_undecoded,
{ "ansi_a.undecoded", PI_UNDECODED, PI_WARN,
"Can't be bothered to do the rest of the decode",
EXPFILL }
}
};
expert_module_t *expert_a_bsmap;
static const enum_val_t a_variant_options[] = {
{ "is-634-rev0", "IS-634 rev. 0", A_VARIANT_IS634 },
{ "tsb-80", "TSB-80", A_VARIANT_TSB80 },
{ "is-634-a", "IS-634-A", A_VARIANT_IS634A },
{ "ios-2.x", "IOS 2.x", A_VARIANT_IOS2 },
{ "ios-3.x", "IOS 3.x", A_VARIANT_IOS3 },
{ "ios-4.0.1", "IOS 4.0.1", A_VARIANT_IOS401 },
{ "ios-5.0.1", "IOS 5.0.1", A_VARIANT_IOS501 },
{ NULL, NULL, 0 }
};
#define MAX_NUM_DTAP_MSG MAX(ANSI_A_IOS401_DTAP_NUM_MSG, ANSI_A_IOS501_DTAP_NUM_MSG)
#define MAX_NUM_BSMAP_MSG MAX(ANSI_A_IOS401_BSMAP_NUM_MSG, ANSI_A_IOS501_BSMAP_NUM_MSG)
#define MAX_NUM_ELEM_1 MAX(MAX_IOS401_NUM_ELEM_1, MAX_IOS501_NUM_ELEM_1)
#define NUM_INDIVIDUAL_ELEMS 24
gint *ett[NUM_INDIVIDUAL_ELEMS+MAX_NUM_DTAP_MSG+MAX_NUM_BSMAP_MSG+MAX_NUM_ELEM_1+NUM_FWD_MS_INFO_REC+NUM_REV_MS_INFO_REC];
static stat_tap_table_ui dtap_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_ANSI,
"A-I/F DTAP Statistics",
"ansi_a",
"ansi_a,dtap",
ansi_a_dtap_stat_init,
ansi_a_dtap_stat_packet,
ansi_a_stat_reset,
NULL,
NULL,
sizeof(dtap_stat_fields)/sizeof(stat_tap_table_item), dtap_stat_fields,
0, NULL,
NULL
};
static stat_tap_table_ui bsmap_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_ANSI,
"A-I/F BSMAP Statistics",
"ansi_a",
"ansi_a,bsmap",
ansi_a_bsmap_stat_init,
ansi_a_bsmap_stat_packet,
ansi_a_stat_reset,
NULL,
NULL,
sizeof(bsmap_stat_fields)/sizeof(stat_tap_table_item), bsmap_stat_fields,
0, NULL,
NULL
};
memset((void *) ett_dtap_msg, -1, sizeof(ett_dtap_msg));
memset((void *) ett_bsmap_msg, -1, sizeof(ett_bsmap_msg));
memset((void *) ett_ansi_elem_1, -1, sizeof(ett_ansi_elem_1));
memset((void *) ett_ansi_fwd_ms_info_rec, -1, sizeof(gint) * NUM_FWD_MS_INFO_REC);
memset((void *) ett_ansi_rev_ms_info_rec, -1, sizeof(gint) * NUM_REV_MS_INFO_REC);
ett[0] = &ett_bsmap;
ett[1] = &ett_dtap;
ett[2] = &ett_elems;
ett[3] = &ett_elem;
ett[4] = &ett_dtap_oct_1;
ett[5] = &ett_cm_srvc_type;
ett[6] = &ett_ansi_ms_info_rec_reserved;
ett[7] = &ett_ansi_enc_info;
ett[8] = &ett_cell_list;
ett[9] = &ett_bearer_list;
ett[10] = &ett_re_list;
ett[11] = &ett_so_list;
ett[12] = &ett_scm;
ett[13] = &ett_adds_user_part;
ett[14] = &ett_scr;
ett[15] = &ett_scr_socr;
ett[16] = &ett_cm2_band_class;
ett[17] = &ett_vp_algs;
ett[18] = &ett_chan_list;
ett[19] = &ett_cic;
ett[20] = &ett_is2000_mob_cap_fch_info;
ett[21] = &ett_is2000_mob_cap_dcch_info;
ett[22] = &ett_is2000_mob_cap_for_pdch_info;
ett[23] = &ett_is2000_mob_cap_rev_pdch_info;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < MAX_NUM_DTAP_MSG; i++, last_offset++)
{
ett[last_offset] = &ett_dtap_msg[i];
}
for (i=0; i < MAX_NUM_BSMAP_MSG; i++, last_offset++)
{
ett[last_offset] = &ett_bsmap_msg[i];
}
for (i=0; i < MAX_NUM_ELEM_1; i++, last_offset++)
{
ett[last_offset] = &ett_ansi_elem_1[i];
}
for (i=0; i < NUM_FWD_MS_INFO_REC; i++, last_offset++)
{
ett[last_offset] = &ett_ansi_fwd_ms_info_rec[i];
}
for (i=0; i < NUM_REV_MS_INFO_REC; i++, last_offset++)
{
ett[last_offset] = &ett_ansi_rev_ms_info_rec[i];
}
proto_a_bsmap =
proto_register_protocol("ANSI A-I/F BSMAP", "ANSI BSMAP", "ansi_a_bsmap");
proto_register_field_array(proto_a_bsmap, hf, array_length(hf));
expert_a_bsmap =
expert_register_protocol(proto_a_bsmap);
expert_register_field_array(expert_a_bsmap, ei, array_length(ei));
proto_a_dtap =
proto_register_protocol("ANSI A-I/F DTAP", "ANSI DTAP", "ansi_a_dtap");
is637_dissector_table =
register_dissector_table("ansi_a.sms", "IS-637-A (SMS)",
proto_a_bsmap, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
is683_dissector_table =
register_dissector_table("ansi_a.ota", "IS-683-A (OTA)",
proto_a_bsmap, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
is801_dissector_table =
register_dissector_table("ansi_a.pld", "IS-801 (PLD)",
proto_a_bsmap, FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
proto_register_subtree_array(ett, array_length(ett));
ansi_a_tap = register_tap("ansi_a");
ansi_a_module = prefs_register_protocol(proto_a_bsmap, proto_reg_handoff_ansi_a);
prefs_register_enum_preference(ansi_a_module,
"global_variant",
"Dissect PDU as",
"(if other than the default of IOS 4.0.1)",
&global_a_variant,
a_variant_options,
FALSE);
prefs_register_bool_preference(ansi_a_module,
"top_display_mid_so",
"Show mobile ID and service option in the INFO column",
"Whether the mobile ID and service options are displayed in the INFO column",
&global_a_info_display);
register_stat_tap_table_ui(&dtap_stat_table);
register_stat_tap_table_ui(&bsmap_stat_table);
}
void
proto_reg_handoff_ansi_a(void)
{
static gboolean ansi_a_prefs_initialized = FALSE;
if (!ansi_a_prefs_initialized)
{
dissector_handle_t bsmap_handle, sip_dtap_bsmap_handle;
bsmap_handle = create_dissector_handle(dissect_bsmap, proto_a_bsmap);
dtap_handle = create_dissector_handle(dissect_dtap, proto_a_dtap);
sip_dtap_bsmap_handle = create_dissector_handle(dissect_sip_dtap_bsmap, proto_a_dtap);
dissector_add_uint("bsap.pdu_type", BSSAP_PDU_TYPE_BSMAP, bsmap_handle);
dissector_add_uint("bsap.pdu_type", BSSAP_PDU_TYPE_DTAP, dtap_handle);
dissector_add_string("media_type", "application/femtointerfacemsg", sip_dtap_bsmap_handle);
dissector_add_string("media_type", "application/vnd.3gpp2.femtointerfacemsg", sip_dtap_bsmap_handle);
ansi_a_prefs_initialized = TRUE;
}
switch (global_a_variant)
{
case A_VARIANT_IOS501:
ansi_a_bsmap_strings = ansi_a_ios501_bsmap_strings;
ansi_a_dtap_strings = ansi_a_ios501_dtap_strings;
ansi_a_elem_1_strings = ansi_a_ios501_elem_1_strings;
ansi_a_elem_1_max = (elem_idx_t) MAX_IOS501_NUM_ELEM_1;
break;
default:
ansi_a_bsmap_strings = ansi_a_ios401_bsmap_strings;
ansi_a_dtap_strings = ansi_a_ios401_dtap_strings;
ansi_a_elem_1_strings = ansi_a_ios401_elem_1_strings;
ansi_a_elem_1_max = (elem_idx_t) MAX_IOS401_NUM_ELEM_1;
break;
}
}
