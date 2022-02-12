static guint32
fresh_handler(tvbuff_t *tvb, proto_tree *tree, guint len _U_, guint32 offset)
{
guint8 oct;
oct = tvb_get_guint8(tvb, offset);
if (oct & 0x80)
{
proto_tree_add_item(tree, hf_ansi_683_fresh_incl16, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_fresh, tvb, offset, 2, ENC_BIG_ENDIAN);
return(2);
}
proto_tree_add_item(tree, hf_ansi_683_fresh_incl8, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 7, ENC_NA);
return(1);
}
static void
rev_param_block_nam_cdma_analog(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value;
proto_tree *subtree;
proto_item *item;
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_firstchp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_home_sid, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_extended_address_indicator, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
offset += 2;
value = tvb_get_ntohs(tvb, offset);
item = proto_tree_add_item(tree, hf_ansi_683_station_class_mark, tvb, offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_scm);
proto_tree_add_item(subtree, hf_ansi_683_extended_scm_indicator, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_683_cdma_analog_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_683_cdma_analog_slotted, tvb, offset, 2, ENC_BIG_ENDIAN);
if (value & 0x0200)
proto_item_append_text(item, "%s", " (MEID configured)");
proto_tree_add_item(subtree, hf_ansi_683_meid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_683_25mhz_bandwidth, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_683_transmission, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_683_power_class, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_mob_p_rev_1fe0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_class10, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ansi_683_ismi_m_addr_num_e, tvb, offset + 1, 1, value,
"%u, %u digits in NMSI", (value & 0x0e) >> 1,
(value & 0x10) ? ((value & 0x0e) >> 1) + 4 : 0);
offset++;
proto_tree_add_item(tree, hf_ansi_683_mcc_m_01ff80, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_11_12_7f, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_10, tvb, offset, 5, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_ansi_683_accolc_3c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_local_control_status_02, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_home_01, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_sid_80, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_nid_40, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_max_sid_nid_3fc0, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_stored_sid_nid_3fc0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_sid_nid_pairs_3fff, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_reserved_bytes,
tvb, offset, len - (offset - saved_offset), ENC_NA);
}
static void
param_block_nam_mdn(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value, count, i;
char str[17];
saved_offset = offset;
value = tvb_get_guint8(tvb, offset);
count = (value & 0xf0) >> 4;
proto_tree_add_item(tree, hf_ansi_683_n_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
for (i=0; i < count; i++)
{
str[i] = dtmf_digits[(value & 0x0f)];
if ((i + 1) < count)
{
offset++;
value = tvb_get_guint8(tvb, offset);
str[i+1] = dtmf_digits[(value & 0xf0) >> 4];
i++;
}
}
str[i] = '\0';
proto_tree_add_string(tree, hf_ansi_683_mobile_directory_number,
tvb, saved_offset, len, str);
if (!(count & 0x01))
{
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 4, ENC_NA);
}
}
static void
rev_param_block_nam_cdma(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value;
saved_offset = offset;
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, (offset<<3)+6, 2, ENC_NA);
proto_tree_add_item(tree, hf_ansi_683_slotted_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 5, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_ansi_683_mob_p_rev_ff, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_class8000, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ansi_683_imsi_m_addr_num_7000, tvb, offset, 2, value,
"%u, %u digits in NMSI", (value & 0x7000) >> 12,
(value & 0x8000) ? ((value & 0x7000) >> 12) + 4 : 0);
proto_tree_add_item(tree, hf_ansi_683_mcc_m_0ffc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_11_12_3f80, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_10, tvb, offset, 5, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_ansi_683_accolc_01e0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_local_control_status_0010, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_home_08, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_sid_0004, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_nid_0002, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_max_sid_nid_01fe, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_stored_sid_nid_01fe, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_sid_nid_pairs_01ff, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_reserved_bytes,
tvb, offset, len - (offset - saved_offset), ENC_NA);
}
static void
param_block_nam_imsi_t(tvbuff_t *tvb, proto_tree *tree, guint len _U_, guint32 offset)
{
guint32 value;
value = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_imsi_t_class, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ansi_683_imsi_t_addr_num, tvb, offset, 1, value,
"%u, %u digits in NMSI", (value & 0x70) >> 4,
(value & 0x80) ? ((value & 0x70) >> 4) + 4 : 0);
proto_tree_add_item(tree, hf_ansi_683_mcc_t, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_t_11_12, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_t_10, tvb, offset, 5, ENC_NA);
offset += 4;
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 1, ENC_NA);
}
static void
for_param_block_nam_cdma_analog(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value;
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_firstchp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
value = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_home_sid, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_extended_address_indicator, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_class10, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ansi_683_ismi_m_addr_num_e, tvb, offset + 2, 1, value,
"%u, %u digits in NMSI", (value & 0x0e) >> 1,
(value & 0x10) ? ((value & 0x0e) >> 1) + 4 : 0);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_mcc_m_01ff80, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_11_12_7f, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_10, tvb, offset, 5, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_ansi_683_accolc_3c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_local_control_status_02, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_home_01, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_sid_8000, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_nid_4000, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_num_sid_nid_3fc0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_sid_nid_pairs_3fff, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_reserved_bytes,
tvb, offset, len - (offset - saved_offset), ENC_NA);
}
static void
for_param_block_nam_cdma(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value;
saved_offset = offset;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_imsi_m_class8000, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ansi_683_imsi_m_addr_num_7000, tvb, offset, 2, value,
"%u, %u digits in NMSI", (value & 0x7000) >> 12,
(value & 0x8000) ? ((value & 0x7000) >> 12) + 4 : 0);
proto_tree_add_item(tree, hf_ansi_683_mcc_m_0ffc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_11_12_3f80, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_imsi_m_10, tvb, offset, 5, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_ansi_683_accolc_01e0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_local_control_status_0010, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_home_08, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_sid_0004, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_mob_term_for_nid_0002, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_num_sid_nid_01fe, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_sid_nid_pairs_01ff, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_reserved_bytes,
tvb, offset, len - (offset - saved_offset), ENC_NA);
}
static void
for_param_block_val_spc(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 3);
proto_tree_add_string(tree, hf_ansi_683_service_programming_code,
tvb, offset, len, tvb_bcd_dig_to_wmem_packet_str(tvb, offset, 3, NULL, FALSE));
}
static void
for_param_block_val_spasm(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
if (len == 1)
{
proto_tree_add_item(tree, hf_ansi_683_otapa_spasm_validation_signature_indicator_80, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_ansi_683_spasm_protection_for_the_active_nam_40, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 6, ENC_NA);
}
else
{
EXACT_DATA_CHECK(len, 3);
proto_tree_add_item(tree, hf_ansi_683_otapa_spasm_validation_signature_indicator_800000, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_otapa_spasm_validation_signature, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_spasm_protection_for_the_active_nam_000010, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_reserved24_f, tvb, offset, 3, ENC_BIG_ENDIAN);
}
}
static void
msg_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_blocks;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_blocks);
for (i=0; i < num_blocks; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_rev_param_block_nam, tvb, offset, 1,
oct, "NAM Parameter Block Type #%u: %s (%u)", i+1,
rval_to_str_const(oct, rev_param_block_nam_rvals, "Reserved"), oct);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_tree *subtree;
proto_item *item;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_nam_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_for_param_block_nam,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_NAM_CDMA_ANALOG:
for_param_block_nam_cdma_analog(tvb, pinfo, subtree, block_len, offset);
break;
case FOR_BLOCK_NAM_MDN:
param_block_nam_mdn(tvb, pinfo, subtree, block_len, offset);
break;
case FOR_BLOCK_NAM_CDMA:
for_param_block_nam_cdma(tvb, pinfo, subtree, block_len, offset);
break;
case FOR_BLOCK_NAM_IMSI_T:
param_block_nam_imsi_t(tvb, subtree, block_len, offset);
break;
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_ms_key_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 akey_prev, param_len;
proto_tree *subtree;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
akey_prev = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_a_key_protocol_revision, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (akey_prev < 0x03)
{
param_len = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree(tree,
tvb, offset, param_len + 1,
ett_key_p, NULL, "Key exchange parameter P");
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, param_len);
offset++;
if (param_len > 0)
{
proto_tree_add_item(subtree, hf_ansi_683_parameter_p, tvb, offset, param_len, ENC_NA);
offset += param_len;
}
param_len = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree(tree,
tvb, offset, param_len + 1,
ett_key_g, NULL, "Key exchange parameter G");
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, param_len);
offset++;
if (param_len > 0)
{
proto_tree_add_item(subtree, hf_ansi_683_parameter_g, tvb, offset, param_len, ENC_NA);
offset += param_len;
}
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_key_gen_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 param_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
param_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, param_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), param_len);
if (param_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_base_station_calculation_result, tvb, offset, param_len, ENC_NA);
offset += param_len;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_reauth_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 4);
proto_tree_add_item(tree, hf_ansi_683_random_challenge_value, tvb, offset, 4, ENC_NA);
}
static void
msg_protocap_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint32 i, saved_offset;
guint8 oct, num_cap;
if (len == 0)
{
return;
}
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_otasp_protocol_revision, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
num_cap = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_capability_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_cap);
for (i=0; i < num_cap; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_cap_info_record_type, tvb, offset, 1, oct,
"Record Type #%u: %s (%u)", i+1, rval_to_str_const(oct, rev_cap_info_record_type_rvals, "Reserved"), oct);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_sspr_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
guint32 saved_offset;
proto_tree *subtree;
proto_item *item;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
oct = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_ansi_683_rev_param_block_sspr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (oct == REV_BLOCK_SSPR_PRL)
{
subtree = proto_item_add_subtree(item, ett_rev_sspr_block);
if ((len - (offset - saved_offset)) < 3)
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_tree_add_item(subtree, hf_ansi_683_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_ansi_683_maximum_segment_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_sspr_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
proto_tree *subtree;
proto_item *item;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
item = proto_tree_add_item(tree, hf_ansi_683_for_param_block_sspr, tvb, offset, 1, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_for_sspr_block);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
if (block_len > 0)
{
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_validate_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_tree *subtree;
proto_item *item;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_val_block, &item,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_param_block_val, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_VAL_VERIFY_SPC:
case FOR_BLOCK_VAL_CHANGE_SPC:
for_param_block_val_spc(tvb, pinfo, subtree, block_len, offset);
break;
case FOR_BLOCK_VAL_VALDATE_SPASM:
for_param_block_val_spasm(tvb, pinfo, subtree, block_len, offset);
break;
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_otapa_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_start_otapa_session, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 7, ENC_NA);
}
static void
msg_puzl_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
proto_tree *subtree;
proto_item *item;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
item = proto_tree_add_item(tree, hf_ansi_683_rev_param_block_puzl, tvb, offset, 1, ENC_BIG_ENDIAN);
block_len = len - (offset - saved_offset);
if (block_len > 0)
{
subtree = proto_item_add_subtree(item, ett_rev_puzl_block);
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_puzl_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_item *item;
proto_tree *subtree;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_puzl_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_for_param_block_puzl,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_PUZL_UZ_INS:
case FOR_BLOCK_PUZL_UZ_UPD:
case FOR_BLOCK_PUZL_UZ_DEL:
case FOR_BLOCK_PUZL_UZ_PRI_CHANGE:
case FOR_BLOCK_PUZL_FLAGS:
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_3gpd_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_blocks;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_blocks);
for (i=0; i < num_blocks; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_rev_param_block_3gpd,
tvb, offset, 1, oct,
"3GPD Parameter Block %u: %s (%u)",
i+1, val_to_str_const(oct, rev_param_block_3gpd_vals, "Reserved"), oct);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_3gpd_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_item *item;
proto_tree *subtree;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_3gpd_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_for_param_block_3gpd, tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_3GPD_OP_MODE:
case FOR_BLOCK_3GPD_SIP_USER_PRO:
case FOR_BLOCK_3GPD_MIP_USER_PRO:
case FOR_BLOCK_3GPD_SIP_STATUS:
case FOR_BLOCK_3GPD_MIP_STATUS:
case FOR_BLOCK_3GPD_SIP_PAP_SS:
case FOR_BLOCK_3GPD_SIP_CHAP_SS:
case FOR_BLOCK_3GPD_MIP_SS:
case FOR_BLOCK_3GPD_HRPD_ACC_AUTH_USER:
case FOR_BLOCK_3GPD_HRPD_ACC_AUTH_CHAP_SS:
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_secure_mode_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_start_secure_mode, tvb, offset, 1, ENC_NA);
if (oct & 0x80)
{
switch ((oct & 0x78) >> 3)
{
case 0x0: str = "SMCK generation using SSD_A and SSD_B"; break;
case 0x1: str = "SMCK generation using 3G Root Key"; break;
default: str = "Key in use indicator"; break;
}
}
else
{
str = "Key in use indicator";
}
proto_tree_add_uint_format_value(tree, hf_ansi_683_security,
tvb, offset, 1, oct, "%s", str);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 3, ENC_NA);
offset++;
if (oct & 0x80)
{
SHORT_DATA_CHECK(len, 8);
proto_tree_add_item(tree, hf_ansi_683_random_number_smck_generation, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mmd_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_blocks;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_blocks);
for (i=0; i < num_blocks; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_rev_param_block_mmd,
tvb, offset, 1, oct,
"MMD Parameter Block #%u: %s (%u)",
i+1, val_to_str_const(oct, param_block_mmd_vals, "Reserved"), oct);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mmd_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_item *item;
proto_tree *subtree;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_mmd_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_for_param_block_mmd,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_MMD_APP:
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_systag_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
proto_tree *subtree;
proto_item *item;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
item = proto_tree_add_item(tree, hf_ansi_683_rev_param_block_systag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (len > (offset - saved_offset))
{
SHORT_DATA_CHECK(len, 3);
subtree = proto_item_add_subtree(item, ett_segment);
proto_tree_add_item(subtree, hf_ansi_683_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(subtree, hf_ansi_683_maximum_segment_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_systag_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_for_param_block_systag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), block_len);
if (block_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_srvckey_gen_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint32 saved_offset;
guint32 value;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_boolean_format_value(tree, hf_ansi_683_key_id_ims_root_key, tvb, offset, 2, value, "IMS Root Key");
proto_tree_add_boolean_format_value(tree, hf_ansi_683_key_id_bcmcs_root_key, tvb, offset, 2, value, "BCMCS Root Key");
proto_tree_add_boolean_format_value(tree, hf_ansi_683_key_id_wlan_root_key, tvb, offset, 2, value, "WLAN Root Key");
proto_tree_add_uint_format_value(tree, hf_ansi_683_key_id_reserved, tvb, offset, 2, value, "Reserved");
proto_tree_add_item(tree, hf_ansi_683_reserved16_f,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mms_config_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_blocks;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_blocks);
for (i=0; i < num_blocks; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_rev_param_block_mms,
tvb, offset, 1, oct,
"MMS Parameter Block #%u: %s (%u)",
i+1, rval_to_str_const(oct, rev_param_block_mms_rvals, "Reserved"), oct);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mms_download_req(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
proto_item *item;
proto_tree *subtree;
guint32 i, saved_offset;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_mms_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_for_param_block_mms, tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case FOR_BLOCK_MMS_URI:
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, block_id, num_blocks, block_len;
guint32 i, saved_offset;
proto_item *item;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_rev_nam_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_rev_param_block_nam,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case REV_BLOCK_NAM_CDMA_ANALOG:
rev_param_block_nam_cdma_analog(tvb, pinfo, subtree, block_len, offset);
break;
case REV_BLOCK_NAM_MDN:
param_block_nam_mdn(tvb, pinfo, subtree, block_len, offset);
break;
case REV_BLOCK_NAM_CDMA:
rev_param_block_nam_cdma(tvb, pinfo, subtree, block_len, offset);
break;
case REV_BLOCK_NAM_IMSI_T:
param_block_nam_imsi_t(tvb, subtree, block_len, offset);
break;
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
SHORT_DATA_CHECK((len - (offset - saved_offset)), num_blocks);
for (i=0; i < num_blocks; i++)
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_result_code,
tvb, offset, 1, oct, "Block #%u result code: %s (%u)",
i+1, rval_to_str_const(oct, result_codes_rvals, "Reserved"), oct);
offset++;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 num_blocks;
guint32 i, saved_offset;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 2, ett_for_nam_block, NULL,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_for_param_block_nam,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_ms_key_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_key_exchange_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
msg_key_gen_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 result_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_key_exchange_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
result_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, result_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), result_len);
if (result_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_mobile_station_calculation_result, tvb, offset, result_len, ENC_NA);
offset += result_len;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_reauth_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 7);
proto_tree_add_item(tree, hf_ansi_683_authr, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_randc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_call_history_parameter, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_authentication_data_input_parameter, tvb, offset, 3, ENC_BIG_ENDIAN);
}
static void
msg_commit_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_data_commit_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
msg_protocap_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_feat, add_len;
guint32 i, saved_offset;
proto_tree *subtree;
proto_item *item;
SHORT_DATA_CHECK(len, 5);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_mobile_station_fw_rev, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_mobile_station_manuf_model_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
num_feat = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_num_features, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_feat * 2));
for (i=0; i < num_feat; i++)
{
oct = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint_format(tree, hf_ansi_683_feature_id,
tvb, offset, 1, oct,
"Feature ID #%u: %s (%u)",
i+1, rval_to_str_const(oct, feat_id_type_rvals, "Reserved"), oct);
subtree = proto_item_add_subtree(item, ett_rev_feat);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_feature_protocol_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
add_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, add_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), add_len);
if (add_len > 0)
{
subtree = proto_tree_add_subtree(tree,
tvb, offset, 1, ett_band_cap, NULL,
"Band/Mode Capability Information");
proto_tree_add_item(subtree, hf_ansi_683_band_class_0_analog, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_ansi_683_band_class_0_cdma, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_ansi_683_band_class_1_cdma, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_ansi_683_band_class_3_cdma, tvb, offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_ansi_683_band_class_6_cdma, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(subtree, hf_ansi_683_reserved8, tvb, offset<<3, 3, ENC_NA);
offset++;
if (add_len > 1)
{
proto_tree_add_item(tree, hf_ansi_683_more_additional_fields, tvb, offset, add_len - 1, ENC_NA);
offset += (add_len - 1);
}
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_sspr_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 3);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_rev_param_block_sspr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_sspr_configuration_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), block_len);
if (block_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_sspr_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id;
EXACT_DATA_CHECK(len, 5);
block_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_for_param_block_sspr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_sspr_download_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (block_id)
{
case FOR_BLOCK_SSPR_PRL:
case FOR_BLOCK_SSPR_EXT_PRL:
proto_tree_add_item(tree, hf_ansi_683_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_maximum_segment_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
}
static void
msg_validate_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 num_blocks;
guint32 i, saved_offset;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 2, ett_for_val_block, NULL,
"Block ID #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_param_block_val, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_otapa_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(tree, hf_ansi_683_result_code,
tvb, offset, 1, oct, "OTAPA result code: %s (%u)",
rval_to_str_const(oct, result_codes_rvals, "Reserved"), oct);
offset++;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, (offset<<3)+1, 7, ENC_NA);
proto_tree_add_item(tree, hf_ansi_683_nam_lock_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (oct & 0x01)
{
SHORT_DATA_CHECK((len - (offset - saved_offset)), 4);
proto_tree_add_item(tree, hf_ansi_683_spasm_random_challenge, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_puzl_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 3);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_rev_param_block_puzl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_puzl_configuration_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), block_len);
if (block_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_puzl_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, num_blocks;
guint32 i, saved_offset, block_offset;
proto_item *item;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 3));
for (i=0; i < num_blocks; i++)
{
block_offset = offset;
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_puzl_block, &item,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_for_param_block_puzl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oct = tvb_get_guint8(tvb, offset);
if (oct & 0x80)
{
SHORT_DATA_CHECK(len, 4);
proto_tree_add_item(tree, hf_ansi_683_identifiers_present16, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ansi_683_user_zone_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_user_zone_sid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(tree, hf_ansi_683_identifiers_present8, tvb, offset, 1, ENC_NA);
proto_tree_add_bits_item(tree, hf_ansi_683_reserved8, tvb, offset<<3, 7, ENC_NA);
offset++;
}
proto_item_set_len(item, offset - block_offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_3gpd_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
guint32 i, saved_offset;
proto_item *item;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 3));
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_rev_3gpd_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_rev_param_block_3gpd,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
case REV_BLOCK_3GPD_OP_CAP:
case REV_BLOCK_3GPD_OP_MODE:
case REV_BLOCK_3GPD_SIP_CAP:
case REV_BLOCK_3GPD_MIP_CAP:
case REV_BLOCK_3GPD_SIP_USER_PRO:
case REV_BLOCK_3GPD_MIP_USER_PRO:
case REV_BLOCK_3GPD_SIP_STATUS:
case REV_BLOCK_3GPD_MIP_STATUS:
case REV_BLOCK_3GPD_SIP_PAP_SS:
case REV_BLOCK_3GPD_SIP_CHAP_SS:
case REV_BLOCK_3GPD_MIP_SS:
case REV_BLOCK_3GPD_HRPD_ACC_AUTH_CAP:
case REV_BLOCK_3GPD_HRPD_ACC_AUTH_USER:
case REV_BLOCK_3GPD_HRPD_ACC_AUTH_CHAP_SS:
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
SHORT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_3gpd_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 num_blocks;
guint32 i, saved_offset;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 2, ett_for_3gpd_block, NULL,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_for_param_block_3gpd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_secure_mode_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_secure_mode_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
msg_ext_protocap_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, block_id, num_recs, block_len;
guint32 i, saved_offset;
proto_tree *subtree;
proto_item *item, *len_item;
SHORT_DATA_CHECK(len, 6);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_otasp_mobile_protocol_revision, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_mobile_station_fw_rev, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_mobile_station_manuf_model_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
num_recs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_num_features, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_recs * 2));
for (i=0; i < num_recs; i++)
{
oct = tvb_get_guint8(tvb, offset);
item = proto_tree_add_uint_format(tree, hf_ansi_683_feature_id,
tvb, offset, 1, oct,
"Feature ID #%u: %s (%u)",
i+1, rval_to_str_const(oct, feat_id_type_rvals, "Reserved"), oct);
subtree = proto_item_add_subtree(item, ett_rev_feat);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_feature_protocol_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
SHORT_DATA_CHECK((len - (offset - saved_offset)), 1);
num_recs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_capability_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_recs * 2));
for (i=0; i < num_recs; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_rev_cap, &item,
"Block ID #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_cap_info_record_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
len_item = proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
expert_add_info(pinfo, len_item, &ei_ansi_683_short_data);
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
#ifdef MLUM
case REV_TYPE_CAP_INFO_OP_MODE:
case REV_TYPE_CAP_INFO_CDMA_BAND:
case REV_TYPE_CAP_INFO_MEID:
case REV_TYPE_CAP_INFO_ICCID:
case REV_TYPE_CAP_INFO_EXT_UIM_ID:
rev_param_block_mmd_app(tvb, subtree, block_len, offset);
break;
#endif
default:
proto_tree_add_item(subtree, hf_ansi_683_capability_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mmd_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
guint32 i, saved_offset;
proto_item *item;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 3));
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_rev_mmd_block, &item,
"Block #%u", i+1);
proto_tree_add_uint(subtree, hf_ansi_683_rev_param_block_mmd,
tvb, offset, 1, block_id);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
#ifdef MLUM
case REV_BLOCK_MMD_APP:
rev_param_block_mmd_app(tvb, subtree, block_len, offset);
break;
#endif
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
SHORT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mmd_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 num_blocks;
guint32 i, saved_offset;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 2, ett_for_mmd_block, NULL,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_for_param_block_mmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_systag_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_len;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 3);
saved_offset = offset;
proto_tree_add_item(tree, hf_ansi_683_rev_param_block_systag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_system_tag_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), block_len);
if (block_len > 0)
{
proto_tree_add_item(tree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
offset += block_len;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_systag_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id;
guint32 saved_offset;
SHORT_DATA_CHECK(len, 2);
saved_offset = offset;
block_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_for_param_block_systag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ansi_683_system_tag_download_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (block_id)
{
case 0x01:
case 0x02:
case 0x03:
SHORT_DATA_CHECK(len, 3);
proto_tree_add_item(tree, hf_ansi_683_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ansi_683_segment_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
default:
break;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_srvckey_gen_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
EXACT_DATA_CHECK(len, 1);
proto_tree_add_item(tree, hf_ansi_683_service_key_generation_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
msg_mms_config_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 block_id, num_blocks, block_len;
guint32 i, saved_offset;
proto_tree *item;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 3));
for (i=0; i < num_blocks; i++)
{
block_id = tvb_get_guint8(tvb, offset);
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_rev_mms_block, &item,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_rev_param_block_mms, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
block_len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ansi_683_length,
tvb, offset, 1, block_len);
offset++;
if (block_len > (len - (offset - saved_offset)))
{
proto_tree_add_expert(subtree, pinfo, &ei_ansi_683_short_data, tvb, offset, len - (offset - saved_offset));
return;
}
proto_item_set_len(item, block_len+1);
if (block_len > 0)
{
switch (block_id)
{
#ifdef MLUM
case REV_BLOCK_MMS_URI:
rev_param_block_mms_uri(tvb, subtree, block_len, offset);
break;
case REV_BLOCK_MMS_URI_CAP:
rev_param_block_mms_uri_cap(tvb, subtree, block_len, offset);
break;
#endif
default:
proto_tree_add_item(subtree, hf_ansi_683_block_data, tvb, offset, block_len, ENC_NA);
break;
}
offset += block_len;
}
SHORT_DATA_CHECK(len, 1);
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (len > (offset - saved_offset))
{
offset +=
fresh_handler(tvb, tree, len - (offset - saved_offset), offset);
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
msg_mms_download_rsp(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint len, guint32 offset)
{
guint8 num_blocks;
guint32 i, saved_offset;
proto_tree *subtree;
SHORT_DATA_CHECK(len, 1);
saved_offset = offset;
num_blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_683_number_of_parameter_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
SHORT_DATA_CHECK((len - (offset - saved_offset)), (guint32)(num_blocks * 2));
for (i=0; i < num_blocks; i++)
{
subtree = proto_tree_add_subtree_format(tree,
tvb, offset, 1, ett_for_mms_block, NULL,
"Block #%u", i+1);
proto_tree_add_item(subtree, hf_ansi_683_for_param_block_mms, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_683_result_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
EXTRANEOUS_DATA_CHECK(len, offset - saved_offset);
}
static void
dissect_ansi_683_for_message(tvbuff_t *tvb, packet_info* pinfo, proto_tree *ansi_683_tree)
{
guint8 msg_type;
gint idx;
const gchar *str = NULL;
msg_type = tvb_get_guint8(tvb, 0);
str = try_val_to_str_idx(msg_type, for_msg_type_strings, &idx);
if (str == NULL)
{
return;
}
proto_tree_add_uint(ansi_683_tree, hf_ansi_683_for_msg_type,
tvb, 0, 1, msg_type);
if (ansi_683_for_msg_fcn[idx] != NULL)
{
(*ansi_683_for_msg_fcn[idx])(tvb, pinfo, ansi_683_tree, tvb_reported_length(tvb) - 1, 1);
}
}
static void
dissect_ansi_683_rev_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ansi_683_tree)
{
guint8 msg_type;
gint idx;
const gchar *str = NULL;
msg_type = tvb_get_guint8(tvb, 0);
str = try_val_to_str_idx(msg_type, rev_msg_type_strings, &idx);
if (str == NULL)
{
return;
}
proto_tree_add_uint(ansi_683_tree, hf_ansi_683_rev_msg_type,
tvb, 0, 1, msg_type);
(*ansi_683_rev_msg_fcn[idx])(tvb, pinfo, ansi_683_tree, tvb_reported_length(tvb) - 1, 1);
}
static int
dissect_ansi_683(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ansi_683_item;
proto_tree *ansi_683_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IS-683");
ansi_683_item =
proto_tree_add_protocol_format(tree, proto_ansi_683, tvb, 0, -1,
"%s %s Link",
ansi_proto_name,
(pinfo->match_uint == ANSI_683_FORWARD) ? "Forward" : "Reverse");
ansi_683_tree =
proto_item_add_subtree(ansi_683_item, ett_ansi_683);
if (pinfo->match_uint == ANSI_683_FORWARD)
{
dissect_ansi_683_for_message(tvb, pinfo, ansi_683_tree);
}
else
{
dissect_ansi_683_rev_message(tvb, pinfo, ansi_683_tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_ansi_683(void)
{
static hf_register_info hf[] =
{
{ &hf_ansi_683_for_msg_type,
{ "Forward Link Message Type",
"ansi_683.for_msg_type",
FT_UINT8, BASE_DEC, VALS(for_msg_type_strings), 0,
NULL, HFILL }},
{ &hf_ansi_683_rev_msg_type,
{ "Reverse Link Message Type",
"ansi_683.rev_msg_type",
FT_UINT8, BASE_DEC, VALS(rev_msg_type_strings), 0,
NULL, HFILL }},
{ &hf_ansi_683_length,
{ "Length", "ansi_683.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_683_reserved8,
{ "Reserved", "ansi_683.reserved",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ansi_683_reserved16_f,
{ "Reserved", "ansi_683.reserved",
FT_UINT16, BASE_HEX, NULL, 0x000f,
NULL, HFILL }
},
{ &hf_ansi_683_reserved24_f,
{ "Reserved", "ansi_683.reserved",
FT_UINT24, BASE_HEX, NULL, 0x00000f,
NULL, HFILL }
},
{ &hf_ansi_683_reserved_bytes,
{ "Reserved", "ansi_683.reserved_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_683_fresh_incl16, { "FRESH_INCL", "ansi_683.fresh_incl", FT_BOOLEAN, 16, TFS(&tfs_true_false), 0x8000, NULL, HFILL }},
{ &hf_ansi_683_fresh, { "FRESH", "ansi_683.fresh", FT_UINT16, BASE_DEC, NULL, 0x7fff, NULL, HFILL }},
{ &hf_ansi_683_fresh_incl8, { "FRESH_INCL", "ansi_683.fresh_incl", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80, NULL, HFILL }},
{ &hf_ansi_683_firstchp, { "First paging channel (FIRSTCHP) used in the home system", "ansi_683.firstchp", FT_UINT16, BASE_DEC, NULL, 0xffe0, NULL, HFILL }},
{ &hf_ansi_683_home_sid, { "Home system identification (HOME_SID)", "ansi_683.home_sid", FT_UINT24, BASE_DEC, NULL, 0x1fffc0, NULL, HFILL }},
{ &hf_ansi_683_extended_address_indicator, { "Extended address indicator (EX)", "ansi_683.extended_address_indicator", FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL }},
{ &hf_ansi_683_station_class_mark, { "Station class mark (SCM)", "ansi_683.station_class_mark", FT_UINT16, BASE_DEC, NULL, 0x1fe0, NULL, HFILL }},
{ &hf_ansi_683_extended_scm_indicator, { "Extended SCM Indicator", "ansi_683.extended_scm_indicator", FT_BOOLEAN, 16, TFS(&tfs_extended_scm_indicator), 0x1000, NULL, HFILL }},
{ &hf_ansi_683_cdma_analog_mode, { "Mode", "ansi_683.cdma_analog_mode", FT_BOOLEAN, 16, TFS(&tfs_cdma_analog_mode), 0x0800, NULL, HFILL }},
{ &hf_ansi_683_cdma_analog_slotted, { "Slotted", "ansi_683.cdma_analog_slotted", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0400, NULL, HFILL }},
{ &hf_ansi_683_meid, { "MEID", "ansi_683.meid", FT_BOOLEAN, 16, TFS(&tfs_configured_not_configured), 0x0200, NULL, HFILL }},
{ &hf_ansi_683_25mhz_bandwidth, { "25 MHz Bandwidth", "ansi_683.25mhz_bandwidth", FT_BOOLEAN, 16, NULL, 0x0100, NULL, HFILL }},
{ &hf_ansi_683_transmission, { "Transmission", "ansi_683.transmission", FT_BOOLEAN, 16, TFS(&tfs_discontinuous_continous), 0x0080, NULL, HFILL }},
{ &hf_ansi_683_power_class, { "Power Class for Band Class 0 Analog Operation", "ansi_683.power_class", FT_UINT16, BASE_DEC, VALS(power_class_vals), 0x0060, NULL, HFILL }},
{ &hf_ansi_683_mob_p_rev_1fe0, { "Mobile station protocol revision number (MOB_P_REV)", "ansi_683.mob_p_rev", FT_UINT16, BASE_DEC, NULL, 0x1fe0, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_class10, { "IMSI_M Class assignment of the mobile station (IMSI_M_CLASS)", "ansi_683.imsi_m_class", FT_UINT16, BASE_DEC, NULL, 0x10, NULL, HFILL }},
{ &hf_ansi_683_ismi_m_addr_num_e, { "Number of IMSI_M address digits (IMSI_M_ADDR_NUM)", "ansi_683.ismi_m_addr_num", FT_UINT16, BASE_DEC, NULL, 0x0e, NULL, HFILL }},
{ &hf_ansi_683_mcc_m_01ff80, { "Mobile country code (MCC_M)", "ansi_683.mcc_m", FT_UINT24, BASE_DEC, NULL, 0x01ff80, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_11_12_7f, { "11th and 12th digits of the IMSI_M (IMSI__M_11_12)", "ansi_683.imsi_m_11_12", FT_UINT24, BASE_HEX, NULL, 0x00007f, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_10, { "The least significant 10 digits of the IMSI_M (IMSI_M_S) (34 bits)", "ansi_683.imsi_m_10", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_accolc_3c, { "Access overload class (ACCOLC)", "ansi_683.accolc", FT_UINT8, BASE_DEC, NULL, 0x3c, NULL, HFILL }},
{ &hf_ansi_683_local_control_status_02, { "Local control status (LOCAL_CONTROL)", "ansi_683.local_control_status", FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL }},
{ &hf_ansi_683_mob_term_home_01, { "Termination indicator for the home system (MOB_TERM_HOME)", "ansi_683.mob_term_home", FT_UINT8, BASE_DEC, NULL, 0x1, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_sid_80, { "Termination indicator for SID roaming (MOB_TERM_FOR_SID)", "ansi_683.mob_term_for_sid", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_nid_40, { "Termination indicator for NID roaming (MOB_TERM_FOR_NID)", "ansi_683.mob_term_for_nid", FT_UINT8, BASE_DEC, NULL, 0x40, NULL, HFILL }},
{ &hf_ansi_683_max_sid_nid_3fc0, { "Maximum stored SID/NID pairs (MAX_SID_NID)", "ansi_683.max_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x3fc0, NULL, HFILL }},
{ &hf_ansi_683_stored_sid_nid_3fc0, { "Number of stored SID/NID pairs (STORED_SID_NID)", "ansi_683.stored_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x3fc0, NULL, HFILL }},
{ &hf_ansi_683_sid_nid_pairs_3fff, { "SID/NID pairs", "ansi_683.sid_nid_pairs", FT_UINT16, BASE_DEC, NULL, 0x3fff, NULL, HFILL }},
{ &hf_ansi_683_n_digits, { "Number of digits (N_DIGITS)", "ansi_683.n_digits", FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_ansi_683_slotted_mode, { "Slotted Mode", "ansi_683.slotted_mode", FT_UINT8, BASE_DEC, NULL, 0x20, NULL, HFILL }},
{ &hf_ansi_683_mob_p_rev_ff, { "Mobile station protocol revision number (MOB_P_REV)", "ansi_683.mob_p_rev", FT_UINT8, BASE_DEC, NULL, 0xFF, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_class8000, { "IMSI_M Class assignment of the mobile station (IMSI_M_CLASS)", "ansi_683.imsi_m_class", FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_addr_num_7000, { "Number of IMSI_M address digits (IMSI_M_ADDR_NUM)", "ansi_683.imsi_m_addr_num", FT_UINT16, BASE_DEC, NULL, 0x7000, NULL, HFILL }},
{ &hf_ansi_683_mcc_m_0ffc, { "Mobile country code (MCC_M)", "ansi_683.mcc_m", FT_UINT16, BASE_DEC, NULL, 0x0ffc, NULL, HFILL }},
{ &hf_ansi_683_imsi_m_11_12_3f80, { "11th and 12th digits of the IMSI_M (IMSI__M_11_12)", "ansi_683.imsi_m_11_12", FT_UINT16, BASE_DEC, NULL, 0x3f80, NULL, HFILL }},
{ &hf_ansi_683_accolc_01e0, { "Access overload class (ACCOLC)", "ansi_683.accolc", FT_UINT16, BASE_DEC, NULL, 0x01e0, NULL, HFILL }},
{ &hf_ansi_683_local_control_status_0010, { "Local control status (LOCAL_CONTROL)", "ansi_683.local_control_status", FT_UINT16, BASE_DEC, NULL, 0x0010, NULL, HFILL }},
{ &hf_ansi_683_mob_term_home_08, { "Termination indicator for the home system (MOB_TERM_HOME)", "ansi_683.mob_term_home", FT_UINT16, BASE_DEC, NULL, 0x0008, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_sid_0004, { "Termination indicator for SID roaming (MOB_TERM_FOR_SID)", "ansi_683.mob_term_for_sid", FT_UINT16, BASE_DEC, NULL, 0x0004, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_nid_0002, { "Termination indicator for NID roaming (MOB_TERM_FOR_NID)", "ansi_683.mob_term_for_nid", FT_UINT16, BASE_DEC, NULL, 0x0002, NULL, HFILL }},
{ &hf_ansi_683_max_sid_nid_01fe, { "Maximum stored SID/NID pairs (MAX_SID_NID)", "ansi_683.max_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x01fe, NULL, HFILL }},
{ &hf_ansi_683_stored_sid_nid_01fe, { "Number of stored SID/NID pairs (STORED_SID_NID)", "ansi_683.stored_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x01fe, NULL, HFILL }},
{ &hf_ansi_683_sid_nid_pairs_01ff, { "SID/NID pairs", "ansi_683.sid_nid_pairs", FT_UINT16, BASE_DEC, NULL, 0x01ff, NULL, HFILL }},
{ &hf_ansi_683_imsi_t_class, { "IMSI_T Class assignment of the mobile station (IMSI_T_CLASS)", "ansi_683.imsi_t_class", FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL }},
{ &hf_ansi_683_imsi_t_addr_num, { "Number of IMSI_T address digits (IMSI_T_ADDR_NUM )", "ansi_683.imsi_t_addr_num", FT_UINT8, BASE_DEC, NULL, 0x70, NULL, HFILL }},
{ &hf_ansi_683_mcc_t, { "Mobile country code (MCC_T)", "ansi_683.mcc_t", FT_UINT16, BASE_DEC, NULL, 0x0ffc, NULL, HFILL }},
{ &hf_ansi_683_imsi_t_11_12, { "11th and 12th digits of the IMSI_T (IMSI__T_11_12)", "ansi_683.imsi_t_11_12", FT_UINT16, BASE_DEC, NULL, 0x03f8, NULL, HFILL }},
{ &hf_ansi_683_imsi_t_10, { "The least significant 10 digits of the IMSI_T (IMSI_T_S) (34 bits)", "ansi_683.imsi_t_10", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_sid_8000, { "Termination indicator for SID roaming (MOB_TERM_FOR_SID)", "ansi_683.mob_term_for_sid", FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_ansi_683_mob_term_for_nid_4000, { "Termination indicator for NID roaming (MOB_TERM_FOR_NID)", "ansi_683.mob_term_for_nid", FT_UINT16, BASE_DEC, NULL, 0x4000, NULL, HFILL }},
{ &hf_ansi_683_num_sid_nid_3fc0, { "Number of SID/NID pairs (N_SID_NID)", "ansi_683.num_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x3fc0, NULL, HFILL }},
{ &hf_ansi_683_num_sid_nid_01fe, { "Number of SID/NID pairs (N_SID_NID)", "ansi_683.num_sid_nid", FT_UINT16, BASE_DEC, NULL, 0x01fe, NULL, HFILL }},
{ &hf_ansi_683_otapa_spasm_validation_signature_indicator_80, { "OTAPA SPASM validation signature indicator", "ansi_683.otapa_spasm_validation_signature_indicator", FT_BOOLEAN, 8, TFS(&tfs_included_not_included), 0x80, NULL, HFILL }},
{ &hf_ansi_683_spasm_protection_for_the_active_nam_40, { "SPASM protection for the active NAM", "ansi_683.spasm_protection_for_the_active_nam", FT_BOOLEAN, 8, TFS(&tfs_activate_do_not_activate), 0x40, NULL, HFILL }},
{ &hf_ansi_683_otapa_spasm_validation_signature_indicator_800000, { "OTAPA SPASM validation signature indicator", "ansi_683.otapa_spasm_validation_signature_indicator", FT_BOOLEAN, 24, TFS(&tfs_included_not_included), 0x800000, NULL, HFILL }},
{ &hf_ansi_683_otapa_spasm_validation_signature, { "OTAPA SPASM validation signature", "ansi_683.otapa_spasm_validation_signature", FT_UINT24, BASE_HEX, NULL, 0x7fffe0, NULL, HFILL }},
{ &hf_ansi_683_spasm_protection_for_the_active_nam_000010, { "SPASM protection for the active NAM", "ansi_683.spasm_protection_for_the_active_nam", FT_BOOLEAN, 24, TFS(&tfs_activate_do_not_activate), 0x000010, NULL, HFILL }},
{ &hf_ansi_683_number_of_parameter_blocks, { "Number of parameter blocks", "ansi_683.number_of_parameter_blocks", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_block_data, { "Block Data", "ansi_683.block_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_a_key_protocol_revision, { "A-Key Protocol Revision", "ansi_683.a_key_protocol_revision", FT_UINT8, BASE_DEC, VALS(akey_protocol_revision_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_parameter_p, { "Parameter P", "ansi_683.parameter_p", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_parameter_g, { "Parameter G", "ansi_683.parameter_g", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_base_station_calculation_result, { "Base Station Calculation Result", "ansi_683.base_station_calculation_result", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_random_challenge_value, { "Random Challenge value", "ansi_683.random_challenge_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_otasp_protocol_revision, { "OTASP protocol revision", "ansi_683.otasp_protocol_revision", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_number_of_capability_records, { "Number of Capability Records", "ansi_683.number_of_capability_records", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_segment_offset, { "Segment offset", "ansi_683.segment_offset", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_maximum_segment_size, { "Maximum segment size", "ansi_683.maximum_segment_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_start_otapa_session, { "OTAPA session", "ansi_683.otapa_session", FT_BOOLEAN, 8, TFS(&tfs_start_stop), 0x80, NULL, HFILL }},
{ &hf_ansi_683_start_secure_mode, { "Secure Mode", "ansi_683.secure_mode", FT_BOOLEAN, 8, TFS(&tfs_start_stop), 0x80, NULL, HFILL }},
{ &hf_ansi_683_security, { "Security", "ansi_683.security", FT_UINT8, BASE_DEC, NULL, 0x78, NULL, HFILL }},
{ &hf_ansi_683_random_number_smck_generation, { "Random Number used for SMCK generation", "ansi_683.random_number_smck_generation", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_key_id_ims_root_key, { "Key ID", "ansi_683.key_id.ims_root_key", FT_BOOLEAN, 16, NULL, 0x8000, NULL, HFILL }},
{ &hf_ansi_683_key_id_bcmcs_root_key, { "Key ID", "ansi_683.key_id.bcmcs_root_key", FT_BOOLEAN, 16, NULL, 0x4000, NULL, HFILL }},
{ &hf_ansi_683_key_id_wlan_root_key, { "Key ID", "ansi_683.key_id.wlan_root_key", FT_BOOLEAN, 16, NULL, 0x2000, NULL, HFILL }},
{ &hf_ansi_683_key_id_reserved, { "Key ID", "ansi_683.key_id.reserved", FT_UINT16, BASE_HEX, NULL, 0x1ff0, NULL, HFILL }},
{ &hf_ansi_683_key_exchange_result_code, { "Key exchange result code", "ansi_683.key_exchange_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_mobile_station_calculation_result, { "Mobile station calculation result", "ansi_683.mobile_station_calculation_result", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_authr, { "Authentication signature data (AUTHR)", "ansi_683.authr", FT_UINT24, BASE_DEC, NULL, 0xffffc0, NULL, HFILL }},
{ &hf_ansi_683_randc, { "Random challenge value (RANDC)", "ansi_683.randc", FT_UINT16, BASE_DEC, NULL, 0x3fc0, NULL, HFILL }},
{ &hf_ansi_683_call_history_parameter, { "Call history parameter (COUNT)", "ansi_683.call_history_parameter", FT_UINT8, BASE_DEC, NULL, 0x3f, NULL, HFILL }},
{ &hf_ansi_683_authentication_data_input_parameter, { "Authentication Data input parameter (AUTH_DATA)", "ansi_683.authentication_data_input_parameter", FT_UINT24, BASE_DEC, NULL, 0xffffff, NULL, HFILL }},
{ &hf_ansi_683_data_commit_result_code, { "Data commit result code", "ansi_683.data_commit_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_mobile_station_fw_rev, { "Mobile station firmware revision number", "ansi_683.mobile_station_fw_rev", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_mobile_station_manuf_model_number, { "Mobile station manufacturer's model number", "ansi_683.mobile_station_manuf_model_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_num_features, { "Number of features", "ansi_683.num_features", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_feature_id, { "Feature ID", "ansi_683.feature_id", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(feat_id_type_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_feature_protocol_version, { "Feature protocol version", "ansi_683.feature_protocol_version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_band_class_0_analog, { "Band Class 0 Analog", "ansi_683.band_class_0_analog", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ansi_683_band_class_0_cdma, { "Band Class 0 CDMA", "ansi_683.band_class_0_cdma", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ansi_683_band_class_1_cdma, { "Band Class 1 CDMA", "ansi_683.band_class_1_cdma", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ansi_683_band_class_3_cdma, { "Band Class 3 CDMA", "ansi_683.band_class_3_cdma", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ansi_683_band_class_6_cdma, { "Band Class 6 CDMA", "ansi_683.band_class_6_cdma", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ansi_683_more_additional_fields, { "More Additional Fields", "ansi_683.more_additional_fields", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_sspr_configuration_result_code, { "SSPR Configuration result code", "ansi_683.sspr_configuration_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_sspr_download_result_code, { "SSPR Download result code", "ansi_683.sspr_download_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_nam_lock_indicator, { "NAM_LOCK indicator", "ansi_683.nam_lock_indicator", FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL }},
{ &hf_ansi_683_spasm_random_challenge, { "SPASM random challenge", "ansi_683.spasm_random_challenge", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_puzl_configuration_result_code, { "PUZL Configuration result code", "ansi_683.puzl_configuration_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_identifiers_present16, { "Identifiers", "ansi_683.identifiers.present", FT_BOOLEAN, 16, TFS(&tfs_present_not_present), 0x8000, NULL, HFILL }},
{ &hf_ansi_683_user_zone_id, { "User Zone ID", "ansi_683.user_zone_id", FT_UINT24, BASE_DEC, NULL, 0x7fff80, NULL, HFILL }},
{ &hf_ansi_683_user_zone_sid, { "User Zone SID", "ansi_683.user_zone_sid", FT_UINT16, BASE_DEC, NULL, 0x7fff, NULL, HFILL }},
{ &hf_ansi_683_identifiers_present8, { "Identifiers", "ansi_683.identifiers.present", FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x80, NULL, HFILL }},
{ &hf_ansi_683_secure_mode_result_code, { "Secure Mode result code", "ansi_683.secure_mode_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_otasp_mobile_protocol_revision, { "OTASP Mobile Protocol Revision", "ansi_683.otasp_mobile_protocol_revision", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_capability_data, { "Capability Data", "ansi_683.capability_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_system_tag_result_code, { "System Tag result code", "ansi_683.system_tag_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_system_tag_download_result_code, { "System Tag Download result code", "ansi_683.system_tag_download_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_segment_size, { "Segment size", "ansi_683.segment_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_service_key_generation_result_code, { "Service Key Generation result code", "ansi_683.service_key_generation_result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_result_code, { "Result Code", "ansi_683.result_code", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(result_codes_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_cap_info_record_type, { "Capability Record Type", "ansi_683.cap_info_record_type", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(rev_cap_info_record_type_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_param_block_val, { "Parameter Block Value", "ansi_683.param_block_val", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_sspr, { "Parameter Block SSPR", "ansi_683.param_block_sspr", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(rev_param_block_sspr_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_sspr, { "Parameter Block SSPR", "ansi_683.param_block_sspr", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_sspr_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_nam, { "NAM Parameter Block Type", "ansi_683.param_block_nam", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(rev_param_block_nam_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_nam, { "NAM Parameter Block Type", "ansi_683.param_block_nam", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_nam_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_puzl, { "PUZL Parameter Block Type", "ansi_683.param_block_puzl", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(rev_param_block_puzl_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_puzl, { "PUZL Parameter Block Type", "ansi_683.param_block_puzl", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_puzl_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_3gpd, { "3GPD Parameter Block Type", "ansi_683.param_block_3gpd", FT_UINT8, BASE_DEC, VALS(rev_param_block_3gpd_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_3gpd, { "3GPD Parameter Block Type", "ansi_683.param_block_3gpd", FT_UINT8, BASE_DEC, VALS(for_param_block_3gpd_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_mmd, { "MMD Parameter Block Type", "ansi_683.param_block_mmd", FT_UINT8, BASE_DEC, VALS(param_block_mmd_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_mmd, { "MMD Parameter Block Type", "ansi_683.param_block_mmd", FT_UINT8, BASE_DEC, VALS(param_block_mmd_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_systag, { "System Tag Parameter Block Type", "ansi_683.param_block_systag", FT_UINT8, BASE_DEC, VALS(rev_param_block_systag_vals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_systag, { "System Tag Parameter Block Type", "ansi_683.param_block_systag", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_systag_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_rev_param_block_mms, { "MMS Parameter Block Type", "ansi_683.param_block_mms", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(rev_param_block_mms_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_for_param_block_mms, { "MMS Parameter Block Type", "ansi_683.param_block_mms", FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(for_param_block_mms_rvals), 0x0, NULL, HFILL }},
{ &hf_ansi_683_mobile_directory_number, { "Modbile directory number", "ansi_683.mobile_directory_number", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ansi_683_service_programming_code, { "Service programming code", "ansi_683.service_programming_code", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ansi_683,
&ett_for_nam_block,
&ett_rev_nam_block,
&ett_key_p,
&ett_key_g,
&ett_rev_feat,
&ett_for_val_block,
&ett_for_sspr_block,
&ett_band_cap,
&ett_rev_sspr_block,
&ett_scm,
&ett_for_puzl_block,
&ett_rev_puzl_block,
&ett_for_3gpd_block,
&ett_rev_3gpd_block,
&ett_for_mmd_block,
&ett_rev_mmd_block,
&ett_for_mms_block,
&ett_rev_mms_block,
&ett_rev_cap,
&ett_segment,
};
static ei_register_info ei[] = {
{ &ei_ansi_683_extraneous_data, { "ansi_683.extraneous_data", PI_PROTOCOL, PI_WARN, "Extraneous Data", EXPFILL }},
{ &ei_ansi_683_short_data, { "ansi_683.short_data", PI_MALFORMED, PI_ERROR, "Short Data (?)", EXPFILL }},
{ &ei_ansi_683_data_length, { "ansi_683.data_length.invalid", PI_PROTOCOL, PI_WARN, "Unexpected Data Length", EXPFILL }},
};
expert_module_t* expert_ansi_683;
proto_ansi_683 =
proto_register_protocol(ansi_proto_name, "ANSI IS-683 (OTA (Mobile))", "ansi_683");
proto_register_field_array(proto_ansi_683, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ansi_683 = expert_register_protocol(proto_ansi_683);
expert_register_field_array(expert_ansi_683, ei, array_length(ei));
}
void
proto_reg_handoff_ansi_683(void)
{
dissector_handle_t ansi_683_handle;
ansi_683_handle = create_dissector_handle(dissect_ansi_683, proto_ansi_683);
dissector_add_uint("ansi_map.ota", ANSI_683_FORWARD, ansi_683_handle);
dissector_add_uint("ansi_map.ota", ANSI_683_REVERSE, ansi_683_handle);
dissector_add_uint("ansi_a.ota", ANSI_683_FORWARD, ansi_683_handle);
dissector_add_uint("ansi_a.ota", ANSI_683_REVERSE, ansi_683_handle);
}
