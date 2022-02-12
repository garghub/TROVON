static void
ofdma_ir_pow_ctrl_start_pow(char *buf, guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH, "%f dBmV/1.6MHz", value/4.0);
}
static void
ofdma_ir_pow_ctrl_step_size(char *buf, guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH, "%f dB", value/4.0);
}
static void
subc_assign_range(char *buf, guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u - %u", value >> 16, value &0xFFFF);
}
static int
dissect_sync (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *sync_tree;
col_set_str(pinfo->cinfo, COL_INFO, "Sync Message");
it = proto_tree_add_item(tree, proto_docsis_sync, tvb, 0, -1, ENC_NA);
sync_tree = proto_item_add_subtree (it, ett_docsis_sync);
proto_tree_add_item (sync_tree, hf_docsis_sync_cmts_timestamp, tvb, 0, 4, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static void
dissect_ucd_burst_descr(tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int pos, guint16 len)
{
int tlvpos, endtlvpos;
guint8 tlvtype;
guint32 i, tlvlen;
proto_tree *burst_tree;
proto_item *burst_item, *burst_len_item;
tlvpos = pos;
endtlvpos = tlvpos + len;
proto_tree_add_item (tree, hf_docsis_ucd_iuc, tvb, tlvpos++, 1, ENC_BIG_ENDIAN);
while (tlvpos < endtlvpos)
{
tlvtype = tvb_get_guint8 (tvb, tlvpos);
burst_tree = proto_tree_add_subtree (tree, tvb, tlvpos, -1,
ett_docsis_burst_tlv, &burst_item,
val_to_str(tlvtype, burst_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (burst_tree, hf_docsis_ucd_burst_type, tvb, tlvpos++, 1, tlvtype);
burst_len_item = proto_tree_add_item_ret_uint (burst_tree, hf_docsis_ucd_burst_length, tvb, tlvpos++, 1, ENC_NA, &tlvlen);
proto_item_set_len(burst_item, tlvlen + 2);
switch (tlvtype)
{
case UCD_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_mod_type, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_diff_encoding, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_preamble_len, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_preamble_val_off, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_fec, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_fec_codeword, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_scrambler_seed, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_max_burst, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_guard_time, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_last_cw_len, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_burst_scrambler_onoff, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_RS_INT_DEPTH:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_rs_int_depth, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_RS_INT_BLOCK:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_rs_int_block, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_PREAMBLE_TYPE:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_preamble_type, tvb, tlvpos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SCMDA_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_ucd_scdma_scrambler_onoff, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SCDMA_CODES_PER_SUBFRAME:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_ucd_scdma_codes_per_subframe, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SCDMA_FRAMER_INT_STEP_SIZE:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_ucd_scdma_framer_int_step_size, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_TCM_ENABLED:
if (tlvlen == 1)
{
proto_tree_add_item (burst_tree, hf_docsis_ucd_tcm_enabled, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SUBC_INIT_RANG:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_subc_init_rang, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_SUBC_FINE_RANG:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_subc_fine_rang, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
case UCD_OFDMA_PROFILE:
if ((tlvlen % 2) == 0)
{
for(i =0; i < tlvlen; i+=2) {
proto_tree_add_item (burst_tree, hf_docsis_ofdma_prof_mod_order, tvb, pos + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (burst_tree, hf_docsis_ofdma_prof_pilot_pattern, tvb, pos + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (burst_tree, hf_docsis_ofdma_prof_num_add_minislots, tvb, pos + i + 1, 1, ENC_BIG_ENDIAN);
}
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u (even length expected)", tlvlen);
}
break;
case UCD_OFDMA_IR_POWER_CONTROL:
if (tlvlen == 2)
{
proto_tree_add_item (burst_tree, hf_docsis_ofdma_ir_pow_ctrl_start_pow, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
proto_tree_add_item (burst_tree, hf_docsis_ofdma_ir_pow_ctrl_step_size, tvb, pos + 1, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, burst_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", tlvlen);
}
break;
}
tlvpos += tlvlen;
}
}
static int
dissect_any_ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, int proto_id, int type_number)
{
int pos;
guint32 i, upchid, length;
guint8 type, symrate;
proto_tree *ucd_tree, *tlv_tree;
proto_item *ucd_item, *tlv_item, *tlv_len_item;
ucd_item = proto_tree_add_item(tree, proto_id, tvb, 0, -1, ENC_NA);
ucd_tree = proto_item_add_subtree (ucd_item, ett_docsis_ucd);
proto_tree_add_item_ret_uint (ucd_tree, hf_docsis_mgt_upstream_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &upchid);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_config_ch_cnt, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_mini_slot_size, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ucd_tree, hf_docsis_mgt_down_chid, tvb, 3, 1, ENC_BIG_ENDIAN);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Type %d UCD Message: Channel ID = %u (U%u)", type_number, upchid,
upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"Type %d UCD Message: Channel ID = %u (Telephony Return)",
type_number, upchid);
pos = 4;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(ucd_tree, tvb, pos, -1,
ett_docsis_tlv, &tlv_item,
val_to_str(type, channel_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_ucd_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_ucd_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case UCD_SYMBOL_RATE:
if (length == 1)
{
symrate = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (tlv_tree, hf_docsis_ucd_symbol_rate, tvb, pos, length, symrate * 160);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_FREQUENCY:
if (length == 4)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_frequency, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_PREAMBLE:
proto_tree_add_item (tlv_tree, hf_docsis_ucd_preamble_pat, tvb, pos, length, ENC_NA);
break;
case UCD_BURST_DESCR:
case UCD_BURST_DESCR5:
case UCD_BURST_DESCR23:
dissect_ucd_burst_descr(tvb, pinfo, tlv_tree, pos, length);
break;
case UCD_EXT_PREAMBLE:
proto_tree_add_item (tlv_tree, hf_docsis_ucd_ext_preamble_pat, tvb, pos, length, ENC_NA);
break;
case UCD_SCDMA_MODE_ENABLED:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_mode_enabled, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_SPREADING_INTERVAL:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_spreading_interval, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_CODES_PER_MINI_SLOT:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_codes_per_mini_slot, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_ACTIVE_CODES:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_active_codes, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_CODE_HOPPING_SEED:
if (length == 2)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_code_hopping_seed, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_US_RATIO_NUM:
if (length == 2)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_us_ratio_num, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_US_RATIO_DENOM:
if (length == 2)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_us_ratio_denom, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_TIMESTAMP_SNAPSHOT:
if (length == 9)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_timestamp_snapshot, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_MAINTAIN_POWER_SPECTRAL_DENSITY:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_maintain_power_spectral_density, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_RANGING_REQUIRED:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_ranging_required, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_MAX_SCHEDULED_CODES:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_max_scheduled_codes, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_RANGING_HOLD_OFF_PRIORITY_FIELD:
if (length == 4)
{
static const int * ucd_rnghoff[] = {
&hf_docsis_ucd_rnghoff_cm,
&hf_docsis_ucd_rnghoff_erouter,
&hf_docsis_ucd_rnghoff_emta,
&hf_docsis_ucd_rnghoff_estb,
&hf_docsis_ucd_rnghoff_rsvd,
&hf_docsis_ucd_rnghoff_id_ext,
NULL
};
proto_tree_add_bitmask_list(tlv_tree, tvb, pos, length, ucd_rnghoff, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_RANGING_CHANNEL_CLASS_ID:
if (length == 4)
{
static const int * ucd_chan_class_id[] = {
&hf_docsis_ucd_chan_class_id_cm,
&hf_docsis_ucd_chan_class_id_erouter,
&hf_docsis_ucd_chan_class_id_emta,
&hf_docsis_ucd_chan_class_id_estb,
&hf_docsis_ucd_chan_class_id_rsvd,
&hf_docsis_ucd_chan_class_id_id_ext,
NULL
};
proto_tree_add_bitmask_list(tlv_tree, tvb, pos, length, ucd_chan_class_id, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_SELECTION_ACTIVE_CODES_AND_CODE_HOPPING:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_active_code_hopping, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SCDMA_SELECTION_STRING_FOR_ACTIVE_CODES:
if (length == 16)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_scdma_selection_active_codes, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_HIGHER_UCD_FOR_SAME_UCID:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_higher_ucd_for_same_ucid, tvb, pos, length, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_higher_ucd_for_same_ucid_resv, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_CHANGE_IND_BITMASK:
if (length == 2)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_subc_excl_band, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_unused_subc, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_other_subc, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc5, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc6, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc9, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc10, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc11, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc12, tvb, pos, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc13, tvb, pos, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc3_or_4, tvb, pos, 1, ENC_NA);
proto_tree_add_item (tlv_tree, hf_docsis_ucd_change_ind_bitmask_reserved, tvb, pos, 1, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_OFDMA_TIMESTAMP_SNAPSHOT:
if (length == 9)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_ofdma_timestamp_snapshot, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_OFDMA_CYCLIC_PREFIX_SIZE:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_ofdma_cyclic_prefix_size, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_OFDMA_ROLLOFF_PERIOD_SIZE:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_ofdma_rolloff_period_size, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SUBCARRIER_SPACING:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_subc_spacing, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_CENTER_FREQ_SUBC_0:
if (length == 4)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_cent_freq_subc0, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SUBC_EXCL_BAND:
if ((length % 4) == 0)
{
for(i = 0; i < length; i+=4) {
proto_tree_add_item (tlv_tree, hf_docsis_ucd_subcarrier_range, tvb, pos+i, 4, ENC_NA);
}
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_UNUSED_SUBC_SPEC:
if ((length % 4) == 0)
{
for(i = 0; i < length; i+=4) {
proto_tree_add_item (tlv_tree, hf_docsis_ucd_subcarrier_range, tvb, pos+i, 4, ENC_NA);
}
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_SYMB_IN_OFDMA_FRAME:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_symb_ofdma_frame, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case UCD_RAND_SEED:
if (length == 3)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_rand_seed, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static int
dissect_ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
return dissect_any_ucd(tvb, pinfo, tree, proto_docsis_ucd, MGT_UCD);
}
static int
dissect_map (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint32 i, numie, upchid, ucd_count;
int pos;
proto_item *it;
proto_tree *map_tree;
static const int * ies[] = {
&hf_docsis_map_sid,
&hf_docsis_map_iuc,
&hf_docsis_map_offset,
NULL
};
it = proto_tree_add_item(tree, proto_docsis_map, tvb, 0, -1, ENC_NA);
map_tree = proto_item_add_subtree (it, ett_docsis_map);
proto_tree_add_item_ret_uint (map_tree, hf_docsis_mgt_upstream_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &upchid);
proto_tree_add_item_ret_uint (map_tree, hf_docsis_map_ucd_count, tvb, 1, 1, ENC_BIG_ENDIAN, &ucd_count);
proto_tree_add_item_ret_uint (map_tree, hf_docsis_map_numie, tvb, 2, 1, ENC_BIG_ENDIAN, &numie);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Map Message: Channel ID = %u (U%u), UCD Count = %u, # IE's = %u",
upchid, upchid - 1, ucd_count, numie);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"Map Message: Channel ID = %u (Telephony Return), UCD Count = %u, # IE's = %u",
upchid, ucd_count, numie);
proto_tree_add_item (map_tree, hf_docsis_map_rsvd, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_alloc_start, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_ack_time, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_rng_start, tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_rng_end, tvb, 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_data_start, tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (map_tree, hf_docsis_map_data_end, tvb, 15, 1, ENC_BIG_ENDIAN);
pos = 16;
for (i = 0; i < numie; i++)
{
proto_tree_add_bitmask_with_flags(map_tree, tvb, pos, hf_docsis_map_ie, ett_docsis_map_ie, ies, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
pos = pos + 4;
}
return tvb_captured_length(tvb);
}
static int
dissect_rngreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *rngreq_tree;
guint32 sid;
it = proto_tree_add_item(tree, proto_docsis_rngreq, tvb, 0, -1, ENC_NA);
rngreq_tree = proto_item_add_subtree (it, ett_docsis_rngreq);
proto_tree_add_item_ret_uint (rngreq_tree, hf_docsis_rngreq_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
if (sid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO, "Ranging Request: SID = %u",
sid);
else
col_set_str(pinfo->cinfo, COL_INFO, "Initial Ranging Request SID = 0");
proto_tree_add_item (rngreq_tree, hf_docsis_mgt_down_chid, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rngreq_tree, hf_docsis_rngreq_pend_compl, tvb, 3, 1, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static int
dissect_rngrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *rngrsp_tree;
proto_item *rngrsptlv_item;
proto_tree *rngrsptlv_tree;
guint8 tlvtype;
int pos;
guint tlvlen;
guint32 sid, upchid;
it = proto_tree_add_item(tree, proto_docsis_rngrsp, tvb, 0, -1, ENC_NA);
rngrsp_tree = proto_item_add_subtree (it, ett_docsis_rngrsp);
proto_tree_add_item_ret_uint (rngrsp_tree, hf_docsis_rngrsp_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
proto_tree_add_item_ret_uint (rngrsp_tree, hf_docsis_mgt_upstream_chid, tvb, 2, 1, ENC_BIG_ENDIAN, &upchid);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Ranging Response: SID = %u, Upstream Channel = %u (U%u)",
sid, upchid, upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"Ranging Response: SID = %u, Telephony Return", sid);
pos = 3;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
tlvtype = tvb_get_guint8 (tvb, pos);
rngrsptlv_tree = proto_tree_add_subtree(rngrsp_tree, tvb, pos, -1,
ett_docsis_rngrsptlv, &rngrsptlv_item,
val_to_str(tlvtype, rngrsp_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (rngrsptlv_tree, hf_docsis_rngrsp_type, tvb, pos, 1, tlvtype);
pos++;
proto_tree_add_item_ret_uint (rngrsptlv_tree, hf_docsis_rngrsp_length,
tvb, pos, 1, ENC_NA, &tlvlen);
pos++;
proto_item_set_len(rngrsptlv_item, tlvlen + 2);
switch (tlvtype)
{
case RNGRSP_TIMING:
if (tlvlen == 4)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_timing_adj, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
break;
case RNGRSP_PWR_LEVEL_ADJ:
if (tlvlen == 1)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_power_adj, tvb, pos, tlvlen, ENC_NA);
}
break;
case RNGRSP_OFFSET_FREQ_ADJ:
if (tlvlen == 2)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_freq_adj, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
break;
case RNGRSP_TRANSMIT_EQ_ADJ:
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_xmit_eq_adj, tvb, pos, tlvlen, ENC_NA);
break;
case RNGRSP_RANGING_STATUS:
if (tlvlen == 1)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_ranging_status, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
break;
case RNGRSP_DOWN_FREQ_OVER:
if (tlvlen == 4)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_down_freq_over, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
break;
case RNGRSP_UP_CHID_OVER:
if (tlvlen == 1)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_upstream_ch_over, tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
break;
default:
;
}
pos += tlvlen;
}
return tvb_captured_length(tvb);
}
static int
dissect_regreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regreq_tree;
guint32 sid;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_regreq, tvb, 0, -1, ENC_NA);
regreq_tree = proto_item_add_subtree (it, ett_docsis_regreq);
proto_tree_add_item_ret_uint (regreq_tree, hf_docsis_regreq_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
col_add_fstr (pinfo->cinfo, COL_INFO, "Registration Request SID = %u", sid);
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_regrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regrsp_tree;
guint32 sid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_regrsp, tvb, 0, -1, ENC_NA);
regrsp_tree = proto_item_add_subtree (it, ett_docsis_regrsp);
proto_tree_add_item_ret_uint (regrsp_tree, hf_docsis_regrsp_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
proto_tree_add_item_ret_uint (regrsp_tree, hf_docsis_regrsp_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Registration Response SID = %u (%s)", sid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regrsp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_uccreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *uccreq_tree;
guint32 chid;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_uccreq, tvb, 0, -1, ENC_NA);
uccreq_tree = proto_item_add_subtree (it, ett_docsis_uccreq);
proto_tree_add_item_ret_uint (uccreq_tree, hf_docsis_mgt_upstream_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &chid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Upstream Channel Change request Channel ID = %u (U%u)",
chid, (chid > 0 ? chid - 1 : chid));
next_tvb = tvb_new_subset_remaining (tvb, 1);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, uccreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_uccrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *uccrsp_tree;
guint32 chid;
it = proto_tree_add_item(tree, proto_docsis_uccrsp, tvb, 0, -1, ENC_NA);
uccrsp_tree = proto_item_add_subtree (it, ett_docsis_uccrsp);
proto_tree_add_item_ret_uint (uccrsp_tree, hf_docsis_mgt_upstream_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &chid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Upstream Channel Change response Channel ID = %u (U%u)",
chid, (chid > 0 ? chid - 1 : chid));
return tvb_captured_length(tvb);
}
static void
dissect_attrs (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint8 type;
guint32 length;
int pos = 0;
gint total_len;
proto_tree *attr_tree, *attr_subtree;
proto_item *ti, *tlv_item, *tlv_len_item;
tvbuff_t *attr_tvb;
total_len = tvb_reported_length_remaining (tvb, 0);
while (pos < total_len)
{
type = tvb_get_guint8 (tvb, pos);
attr_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_bpkmattrtlv, &tlv_item,
val_to_str(type, bpkmattr_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (attr_tree, hf_docsis_bpkmattr_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (attr_tree, hf_docsis_bpkmattr_length,
tvb, pos, 2, ENC_BIG_ENDIAN, &length);
pos += 2;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case BPKM_RESERVED:
break;
case BPKM_SERIAL_NUM:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_serial_num, tvb, pos, length, ENC_ASCII|ENC_NA);
break;
case BPKM_MANUFACTURER_ID:
if (length == 3)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_manf_id, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_MAC_ADDR:
if (length == 6)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_mac_addr, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_RSA_PUB_KEY:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_rsa_pub_key, tvb, pos, length, ENC_NA);
break;
case BPKM_CM_ID:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_cm_id, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_cmid);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
case BPKM_DISPLAY_STR:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_display_str, tvb, pos, length, ENC_ASCII|ENC_NA);
break;
case BPKM_AUTH_KEY:
if ((length == 96) || (length == 128) || (length == 256))
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_auth_key, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_TEK:
if (length == 8 || length == 16)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_tek, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_KEY_LIFETIME:
if (length == 4)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_key_life, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_KEY_SEQ_NUM:
if (length == 1)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_key_seq, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_HMAC_DIGEST:
if (length == 20)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_hmac_digest, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_SAID:
if (length == 2)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_said, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_TEK_PARAM:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_tek_params, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_tekp);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
case BPKM_OBSOLETED:
break;
case BPKM_CBC_IV:
if (length == 8 || length == 16)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_cbc_iv, tvb, pos, length, ENC_NA);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_ERROR_CODE:
if (length == 1)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_error_code, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_CA_CERT:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_ca_cert, tvb, pos, length, ENC_NA);
break;
case BPKM_CM_CERT:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_cm_cert, tvb, pos, length, ENC_NA);
break;
case BPKM_SEC_CAPABILITIES:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_security_cap, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_scap);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
case BPKM_CRYPTO_SUITE:
if (length == 2)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_crypto_suite, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_CRYPTO_SUITE_LIST:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_crypto_suite_list, tvb, pos, length, ENC_NA);
break;
case BPKM_BPI_VERSION:
if (length == 1)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_bpi_version, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_SA_DESCRIPTOR:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_sa_descr, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_sadsc);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
case BPKM_SA_TYPE:
if (length == 1)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_sa_type, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_SA_QUERY:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_sa_query, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_saqry);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
case BPKM_SA_QUERY_TYPE:
if (length == 1)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_sa_query_type, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_IP_ADDRESS:
if (length == 4)
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_ip_address, tvb, pos, length, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
break;
case BPKM_VENDOR_DEFINED:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_vendor_def, tvb, pos, length, ENC_NA);
break;
case BPKM_DNLD_PARAMS:
ti = proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_download_param, tvb, pos, length, ENC_NA);
attr_subtree = proto_item_add_subtree(ti, ett_docsis_bpkmattr_dnld);
attr_tvb = tvb_new_subset_length (tvb, pos, length);
dissect_attrs (attr_tvb, pinfo, attr_subtree);
break;
default:
proto_tree_add_item (attr_tree, hf_docsis_bpkmattr_vendor_def, tvb, pos, length, ENC_NA);
break;
}
pos += length;
}
}
static int
dissect_bpkmreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *bpkmreq_tree, *bpkmattr_tree;
guint32 code;
tvbuff_t *attrs_tvb;
it = proto_tree_add_item(tree, proto_docsis_bpkmreq, tvb, 0, -1, ENC_NA);
bpkmreq_tree = proto_item_add_subtree (it, ett_docsis_bpkmreq);
proto_tree_add_item_ret_uint (bpkmreq_tree, hf_docsis_bpkm_code, tvb, 0, 1,
ENC_BIG_ENDIAN, &code);
col_add_fstr (pinfo->cinfo, COL_INFO, "BPKM Request (%s)",
val_to_str (code, code_field_vals, "%d"));
proto_tree_add_item (bpkmreq_tree, hf_docsis_bpkm_ident, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmreq_tree, hf_docsis_bpkm_length, tvb, 2, 2, ENC_BIG_ENDIAN);
it = proto_tree_add_item(bpkmreq_tree, hf_docsis_bpkmattr, tvb, 4, tvb_reported_length_remaining(tvb, 4), ENC_NA);
bpkmattr_tree = proto_item_add_subtree (it, ett_docsis_bpkmattr);
attrs_tvb = tvb_new_subset_remaining (tvb, 4);
dissect_attrs(attrs_tvb, pinfo, bpkmattr_tree);
return tvb_captured_length(tvb);
}
static int
dissect_bpkmrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *bpkmrsp_tree, *bpkmattr_tree;
guint32 code;
tvbuff_t *attrs_tvb;
it = proto_tree_add_item(tree, proto_docsis_bpkmrsp, tvb, 0, -1, ENC_NA);
bpkmrsp_tree = proto_item_add_subtree (it, ett_docsis_bpkmrsp);
proto_tree_add_item_ret_uint (bpkmrsp_tree, hf_docsis_bpkm_code, tvb, 0, 1, ENC_BIG_ENDIAN, &code);
col_add_fstr (pinfo->cinfo, COL_INFO, "BPKM Response (%s)",
val_to_str (code, code_field_vals, "Unknown code %u"));
proto_tree_add_item (bpkmrsp_tree, hf_docsis_bpkm_ident, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (bpkmrsp_tree, hf_docsis_bpkm_length, tvb, 2, 2, ENC_BIG_ENDIAN);
it = proto_tree_add_item(bpkmrsp_tree, hf_docsis_bpkmattr, tvb, 4, tvb_reported_length_remaining(tvb, 4), ENC_NA);
bpkmattr_tree = proto_item_add_subtree (it, ett_docsis_bpkmattr);
attrs_tvb = tvb_new_subset_remaining (tvb, 4);
dissect_attrs(attrs_tvb, pinfo, bpkmattr_tree);
return tvb_captured_length(tvb);
}
static int
dissect_regack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regack_tree;
guint32 sid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_regack, tvb, 0, -1, ENC_NA);
regack_tree = proto_item_add_subtree (it, ett_docsis_regack);
proto_tree_add_item_ret_uint (regack_tree, hf_docsis_regack_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
proto_tree_add_item_ret_uint (regack_tree, hf_docsis_regack_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Registration Acknowledge SID = %u (%s)", sid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regack_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dsareq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsareq_tree;
guint32 transid;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_dsareq, tvb, 0, -1, ENC_NA);
dsareq_tree = proto_item_add_subtree (it, ett_docsis_dsareq);
proto_tree_add_item_ret_uint (dsareq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Addition Request Tran-id = %u", transid);
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsareq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dsarsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsarsp_tree;
guint32 transid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_dsarsp, tvb, 0, -1, ENC_NA);
dsarsp_tree = proto_item_add_subtree (it, ett_docsis_dsarsp);
proto_tree_add_item_ret_uint (dsarsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dsarsp_tree, hf_docsis_dsarsp_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Add Response ID = %u (%s)", transid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsarsp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dsaack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsaack_tree;
guint32 transid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_dsaack, tvb, 0, -1, ENC_NA);
dsaack_tree = proto_item_add_subtree (it, ett_docsis_dsaack);
proto_tree_add_item_ret_uint (dsaack_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dsaack_tree, hf_docsis_dsaack_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Add Ack ID = %u (%s)", transid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsaack_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dscreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dscreq_tree;
guint32 transid;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_dscreq, tvb, 0, -1, ENC_NA);
dscreq_tree = proto_item_add_subtree (it, ett_docsis_dscreq);
proto_tree_add_item_ret_uint (dscreq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Change Request Tran-id = %u", transid);
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dscreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dscrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dscrsp_tree;
guint32 transid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_dscrsp, tvb, 0, -1, ENC_NA);
dscrsp_tree = proto_item_add_subtree (it, ett_docsis_dscrsp);
proto_tree_add_item_ret_uint (dscrsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dscrsp_tree, hf_docsis_dscrsp_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Change Response ID = %u (%s)", transid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dscrsp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dscack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dscack_tree;
guint32 transid, response;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_dscack, tvb, 0, -1, ENC_NA);
dscack_tree = proto_item_add_subtree (it, ett_docsis_dscack);
proto_tree_add_item_ret_uint (dscack_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dscack_tree, hf_docsis_dscack_response, tvb, 2, 1, ENC_BIG_ENDIAN, &response);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Change Ack ID = %u (%s)", transid,
val_to_str_ext (response, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dscack_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dsdreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsdreq_tree;
guint32 transid;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_dsdreq, tvb, 0, -1, ENC_NA);
dsdreq_tree = proto_item_add_subtree (it, ett_docsis_dsdreq);
proto_tree_add_item_ret_uint (dsdreq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Delete Request Tran-id = %u", transid);
proto_tree_add_item (dsdreq_tree, hf_docsis_dsdreq_rsvd, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dsdreq_tree, hf_docsis_dsdreq_sfid, tvb, 4, 4, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining (tvb, 8);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dsdreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dsdrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dsdrsp_tree;
guint32 tranid, confcode;
it = proto_tree_add_item(tree, proto_docsis_dsdrsp, tvb, 0, -1, ENC_NA);
dsdrsp_tree = proto_item_add_subtree (it, ett_docsis_dsdrsp);
proto_tree_add_item_ret_uint (dsdrsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &tranid);
proto_tree_add_item_ret_uint (dsdrsp_tree, hf_docsis_dsdrsp_confcode, tvb, 2, 1, ENC_BIG_ENDIAN, &confcode);
proto_tree_add_item (dsdrsp_tree, hf_docsis_dsdrsp_rsvd, tvb, 3, 1, ENC_BIG_ENDIAN);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Service Delete Response Tran id = %u (%s)",
tranid, val_to_str_ext (confcode, &docsis_conf_code_ext, "%d"));
return tvb_captured_length(tvb);
}
static void
dissect_dccreq_ds_params (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcc_tree;
proto_item *dcc_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcc_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dccreq_ds_params, &dcc_item,
val_to_str(type, ds_param_subtlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcc_tree, hf_docsis_dcc_ds_params_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcc_tree, hf_docsis_dcc_ds_params_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcc_item, length + 2);
switch (type)
{
case DCCREQ_DS_FREQ:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_freq, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_MOD_TYPE:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_mod_type, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_SYM_RATE:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_sym_rate, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_INTLV_DEPTH:
if (length == 2)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_intlv_depth_i, tvb, pos, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_intlv_depth_j, tvb, pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_CHAN_ID:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_chan_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_SYNC_SUB:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_sync_sub, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_OFDM_BLOCK_FREQ:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_ofdm_block_freq, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static void
dissect_dccreq_sf_sub (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcc_tree;
proto_item *dcc_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcc_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dccreq_sf_sub, &dcc_item,
val_to_str(type, sf_sub_subtlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcc_tree, hf_docsis_dcc_sf_sub_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcc_tree, hf_docsis_dcc_sf_sub_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcc_item, length + 2);
switch (type)
{
case DCCREQ_SF_SFID:
if (length == 8)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sfid_cur, tvb, pos, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sfid_new, tvb, pos + 4, 4, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_SF_SID:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sid_cur, tvb, pos, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sid_new, tvb, pos + 2, 2, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_SF_UNSOL_GRANT_TREF:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_unsol_grant_tref, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static int
dissect_dccreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos;
guint8 type;
guint32 length;
proto_tree *dcc_tree, *tlv_tree;
proto_item *dcc_item, *tlv_item, *tlv_len_item;
col_set_str(pinfo->cinfo, COL_INFO, "DCC-REQ Message");
dcc_item = proto_tree_add_item (tree, proto_docsis_dccreq, tvb, 0, -1, ENC_NA);
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccreq);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_tran_id, tvb, 0, 2, ENC_BIG_ENDIAN);
pos = 2;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(dcc_tree, tvb, pos, -1,
ett_docsis_dccreq_tlv, &tlv_item,
val_to_str(type, dcc_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_dccreq_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dccreq_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case DCCREQ_UP_CHAN_ID:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_up_chan_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_DS_PARAMS:
dissect_dccreq_ds_params (tvb, pinfo, tlv_tree, pos, length);
break;
case DCCREQ_INIT_TECH:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_init_tech, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_UCD_SUB:
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_ucd_sub, tvb, pos, length, ENC_NA);
break;
case DCCREQ_SAID_SUB:
if (length == 4)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_said_sub_cur, tvb, pos, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_said_sub_new, tvb, pos + 2, 2, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_SF_SUB:
dissect_dccreq_sf_sub (tvb, pinfo, tlv_tree, pos, length );
break;
case DCCREQ_CMTS_MAC_ADDR:
if (length == 6)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_cmts_mac_addr, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_key_seq_num, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCREQ_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccreq_hmac_digest, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static void
dissect_dccrsp_cm_jump_time (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcc_tree;
proto_item *dcc_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcc_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dccrsp_cm_jump_time, &dcc_item,
val_to_str(type, cm_jump_subtlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcc_tree, hf_docsis_dcc_cm_jump_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcc_tree, hf_docsis_dcc_cm_jump_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcc_item, length + 2);
switch (type)
{
case DCCRSP_CM_JUMP_TIME_LENGTH:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_cm_jump_time_length, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCRSP_CM_JUMP_TIME_START:
if (length == 8)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_cm_jump_time_start, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static int
dissect_dccrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos;
guint8 type;
guint32 length;
proto_tree *dcc_tree, *tlv_tree;
proto_item *dcc_item, *tlv_item, *tlv_len_item;
col_set_str(pinfo->cinfo, COL_INFO, "DCC-RSP Message");
dcc_item = proto_tree_add_item (tree, proto_docsis_dccrsp, tvb, 0, -1, ENC_NA);
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccrsp);
proto_tree_add_item (dcc_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_conf_code, tvb, 2, 1, ENC_BIG_ENDIAN);
pos = 3;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(dcc_tree, tvb, pos, -1,
ett_docsis_dccrsp_tlv, &tlv_item,
val_to_str(type, dccrsp_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_dccrsp_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dccrsp_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case DCCRSP_CM_JUMP_TIME:
dissect_dccrsp_cm_jump_time (tvb, pinfo, tlv_tree, pos, length );
break;
case DCCRSP_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccrsp_key_seq_num, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCRSP_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccrsp_hmac_digest, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static int
dissect_dccack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos;
guint8 type;
guint32 length;
proto_tree *dcc_tree, *tlv_tree;
proto_item *dcc_item, *tlv_item, *tlv_len_item;
col_set_str(pinfo->cinfo, COL_INFO, "DCC-ACK Message");
dcc_item = proto_tree_add_item(tree, proto_docsis_dccack, tvb, 0, -1, ENC_NA);
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccack);
proto_tree_add_item (dcc_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN);
pos = 2;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(dcc_tree, tvb, pos, -1,
ett_docsis_dccack_tlv, &tlv_item,
val_to_str(type, dccack_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_dccack_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dccack_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case DCCACK_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccack_key_seq_num, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCCACK_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (tlv_tree, hf_docsis_dccack_hmac_digest, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static int
dissect_type29ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
return dissect_any_ucd(tvb, pinfo, tree, proto_docsis_type29ucd, MGT_TYPE29UCD);
}
static int
dissect_intrngreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *intrngreq_item;
proto_tree *intrngreq_tree;
guint32 sid;
intrngreq_item = proto_tree_add_item(tree, proto_docsis_intrngreq, tvb, 0, -1, ENC_NA);
intrngreq_tree = proto_item_add_subtree (intrngreq_item, ett_docsis_intrngreq);
proto_tree_add_item_ret_uint (intrngreq_tree, hf_docsis_intrngreq_sid, tvb, 0, 2, ENC_BIG_ENDIAN, &sid);
col_add_fstr (pinfo->cinfo, COL_INFO, "Initial Ranging Request: SID = %u",sid);
proto_tree_add_item (intrngreq_tree, hf_docsis_mgt_down_chid, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (intrngreq_tree, hf_docsis_mgt_upstream_chid, tvb, 3, 1, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static void
dissect_dcd_dsg_cfg (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcd_tree;
proto_tree *dcd_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dcd_cfg, &dcd_item,
val_to_str(type, dcd_cfg_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcd_tree, hf_docsis_dcd_cfg_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcd_tree, hf_docsis_dcd_cfg_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcd_item, length + 2);
switch (type)
{
case DCD_CFG_CHAN_LST:
if (length == 4)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_chan, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFG_TDSG1:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_tdsg1, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFG_TDSG2:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_tdsg2, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFG_TDSG3:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_tdsg3, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFG_TDSG4:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_tdsg4, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFG_VENDOR_SPEC:
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfg_vendor_spec, tvb, pos, length, ENC_NA);
break;
}
pos += length;
}
}
static void
dissect_dcd_down_classifier_ip (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcd_tree;
proto_tree *dcd_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dcd_cfr_ip, &dcd_item,
val_to_str(type, dcd_cfr_ip_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcd_tree, hf_docsis_dcd_cfr_ip_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcd_tree, hf_docsis_dcd_cfr_ip_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcd_item, length + 2);
switch (type)
{
case DCD_CFR_IP_SOURCE_ADDR:
if (length == 4)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_ip_source_addr, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_IP_SOURCE_MASK:
if (length == 4)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_ip_source_mask, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_IP_DEST_ADDR:
if (length == 4)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_ip_dest_addr, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_IP_DEST_MASK:
if (length == 4)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_ip_dest_mask, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_TCPUDP_SRCPORT_START:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_tcpudp_srcport_start, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_TCPUDP_SRCPORT_END:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_tcpudp_srcport_end, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_TCPUDP_DSTPORT_START:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_tcpudp_dstport_start, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_TCPUDP_DSTPORT_END:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_tcpudp_dstport_end, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static void
dissect_dcd_clid (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcd_tree;
proto_tree *dcd_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dcd_clid, &dcd_item,
val_to_str(type, dcd_clid_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcd_tree, hf_docsis_dcd_clid_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcd_tree, hf_docsis_dcd_clid_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcd_item, length + 2);
switch (type)
{
case DCD_CLID_BCAST_ID:
if (length == 2)
{
proto_tree_add_item(dcd_tree, hf_docsis_dcd_clid_bcast_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CLID_KNOWN_MAC_ADDR:
if (length == 6)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_clid_known_mac_addr, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CLID_CA_SYS_ID:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_clid_ca_sys_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CLID_APP_ID:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_clid_app_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static void
dissect_dcd_dsg_rule (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcd_tree;
proto_tree *dcd_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dcd_rule, &dcd_item,
val_to_str(type, dcd_dsg_rule_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcd_tree, hf_docsis_dcd_dsg_rule_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcd_tree, hf_docsis_dcd_dsg_rule_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcd_item, length + 2);
switch (type)
{
case DCD_RULE_ID:
if (length == 1)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_RULE_PRI:
if (length == 1)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_pri, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_RULE_UCID_RNG:
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_ucid_list, tvb, pos, length, ENC_NA);
break;
case DCD_RULE_CLIENT_ID:
dissect_dcd_clid (tvb, pinfo, dcd_tree, pos, length );
break;
case DCD_RULE_TUNL_ADDR:
if (length == 6)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_tunl_addr, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_RULE_CFR_ID:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_cfr_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_RULE_VENDOR_SPEC:
proto_tree_add_item (dcd_tree, hf_docsis_dcd_rule_vendor_spec, tvb, pos, length, ENC_NA);
break;
}
pos += length;
}
}
static void
dissect_dcd_down_classifier (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *dcd_tree;
proto_tree *dcd_item, *tlv_len_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
dcd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_dcd_cfr, &dcd_item,
val_to_str(type, dcd_down_classifier_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (dcd_tree, hf_docsis_dcd_down_classifier_subtype, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (dcd_tree, hf_docsis_dcd_down_classifier_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(dcd_item, length + 2);
switch (type)
{
case DCD_CFR_ID:
if (length == 2)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_RULE_PRI:
if (length == 1)
{
proto_tree_add_item (dcd_tree, hf_docsis_dcd_cfr_rule_pri, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DCD_CFR_IP_CLASSIFIER:
dissect_dcd_down_classifier_ip (tvb , pinfo , dcd_tree , pos , length );
break;
}
pos += length;
}
}
static int
dissect_dcd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos;
guint8 type;
guint32 length;
proto_tree *dcd_tree, *tlv_tree;
proto_item *dcd_item, *tlv_item;
col_set_str(pinfo->cinfo, COL_INFO, "DCD Message: ");
dcd_item = proto_tree_add_item(tree, proto_docsis_dcd, tvb, 0, -1, ENC_NA);
dcd_tree = proto_item_add_subtree (dcd_item, ett_docsis_dcd);
proto_tree_add_item (dcd_tree, hf_docsis_dcd_config_ch_cnt, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dcd_tree, hf_docsis_dcd_num_of_frag, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dcd_tree, hf_docsis_dcd_frag_sequence_num, tvb, 2, 1, ENC_BIG_ENDIAN);
pos = 3;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(dcd_tree, tvb, pos, -1,
ett_docsis_dcd_tlv, &tlv_item,
val_to_str(type, dcd_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_dcd_type, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dcd_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case DCD_DOWN_CLASSIFIER:
dissect_dcd_down_classifier (tvb, pinfo, tlv_tree, pos, length);
break;
case DCD_DSG_RULE:
dissect_dcd_dsg_rule (tvb, pinfo, tlv_tree, pos, length);
break;
case DCD_DSG_CONFIG:
dissect_dcd_dsg_cfg (tvb, pinfo, tlv_tree, pos, length);
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static void
dissect_mdd_ds_active_channel_list(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
static const int * order_annex[] = {
&hf_docsis_mdd_downstream_active_channel_list_modulation_order,
&hf_docsis_mdd_downstream_active_channel_list_annex,
NULL
};
static const int * cm_status_event[] = {
&hf_docsis_mdd_cm_status_event_enable_bitmask_mdd_timeout,
&hf_docsis_mdd_cm_status_event_enable_bitmask_qam_fec_lock_failure,
&hf_docsis_mdd_cm_status_event_enable_bitmask_mdd_recovery,
&hf_docsis_mdd_cm_status_event_enable_bitmask_qam_fec_lock_recovery,
NULL
};
static const int * ofdm_plc_parameters[] = {
&hf_docsis_mdd_ofdm_plc_parameters_tukey_raised_cosine_window,
&hf_docsis_mdd_ofdm_plc_parameters_cyclic_prefix,
&hf_docsis_mdd_ofdm_plc_parameters_sub_carrier_spacing,
NULL
};
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_ds_active_channel_list, &mdd_item,
val_to_str(type, mdd_ds_active_channel_list_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_ds_active_channel_list_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_ds_active_channel_list_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_CHANNEL_ID:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_downstream_active_channel_list_channel_id, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_FREQUENCY:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_downstream_active_channel_list_frequency, tvb, pos, 4, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_MODULATION_ORDER_ANNEX:
proto_tree_add_bitmask_list(mdd_tree, tvb, pos, 1, order_annex, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_PRIMARY_CAPABLE:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_downstream_active_channel_list_primary_capable, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_CM_STATUS_EVENT_ENABLE_BITMASK:
proto_tree_add_bitmask(mdd_tree, tvb, pos, hf_docsis_mdd_cm_status_event_enable_bitmask, ett_sub_tlv, cm_status_event, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_MAP_UCD_TRANSPORT_INDICATOR:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_downstream_active_channel_list_map_ucd_transport_indicator, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case DOWNSTREAM_ACTIVE_CHANNEL_LIST_OFDM_PLC_PARAMETERS:
proto_tree_add_bitmask(mdd_tree, tvb, pos, hf_docsis_mdd_ofdm_plc_parameters, ett_sub_tlv, ofdm_plc_parameters, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static void
dissect_mdd_ds_service_group(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 i, length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_ds_service_group, &mdd_item,
val_to_str(type, mdd_ds_service_group_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_ds_service_group_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_ds_service_group_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case MAC_DOMAIN_DOWNSTREAM_SERVICE_GROUP_MD_DS_SG_IDENTIFIER:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_mac_domain_downstream_service_group_md_ds_sg_identifier, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case MAC_DOMAIN_DOWNSTREAM_SERVICE_GROUP_CHANNEL_IDS:
for (i = 0; i < length; i++) {
proto_tree_add_item (mdd_tree, hf_docsis_mdd_mac_domain_downstream_service_group_channel_id, tvb, pos + i , 1, ENC_BIG_ENDIAN);
}
break;
}
pos += length;
}
}
static void
dissect_mdd_channel_profile_reporting_control(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_channel_profile_reporting_control, &mdd_item,
val_to_str(type, mdd_channel_profile_reporting_control_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_channel_profile_reporting_control_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_channel_profile_reporting_control_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case RCP_CENTER_FREQUENCY_SPACING:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_rpc_center_frequency_spacing, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case VERBOSE_RCP_REPORTING:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_verbose_rcp_reporting, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static void
dissect_mdd_ip_init_param(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_ip_init_param, &mdd_item,
val_to_str(type, mdd_ip_init_param_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_ip_init_param_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_ip_init_param_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case IP_PROVISIONING_MODE:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_ip_provisioning_mode, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case PRE_REGISTRATION_DSID:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_pre_registration_dsid, tvb, pos, 3, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static void
dissect_mdd_upstream_active_channel_list(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
static const int * cm_status_event[] = {
&hf_docsis_mdd_cm_status_event_enable_bitmask_t4_timeout,
&hf_docsis_mdd_cm_status_event_enable_bitmask_t3_retries_exceeded,
&hf_docsis_mdd_cm_status_event_enable_bitmask_successful_ranging_after_t3_retries_exceeded,
NULL
};
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_up_active_channel_list, &mdd_item,
val_to_str(type, mdd_up_active_channel_list_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_up_active_channel_list_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_up_active_channel_list_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case UPSTREAM_ACTIVE_CHANNEL_LIST_UPSTREAM_CHANNEL_ID:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_upstream_active_channel_list_upstream_channel_id, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case UPSTREAM_ACTIVE_CHANNEL_LIST_CM_STATUS_EVENT_ENABLE_BITMASK:
proto_tree_add_bitmask(mdd_tree, tvb, pos, hf_docsis_mdd_cm_status_event_enable_bitmask, ett_sub_tlv, cm_status_event, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static void
dissect_mdd_cm_status_event_control(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length, timer;
proto_tree *mdd_tree;
proto_item *mdd_item, *text_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_cm_status_event_control, &mdd_item,
val_to_str(type, mdd_cm_status_event_control_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_cm_status_event_control_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_cm_status_event_control_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case EVENT_TYPE_CODE:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_event_type, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case MAXIMUM_EVENT_HOLDOFF_TIMER:
text_item = proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_maximum_event_holdoff_timer, tvb, pos, 2, ENC_BIG_ENDIAN, &timer);
proto_item_append_text(text_item, " (%d ms)", timer * 20);
break;
case MAXIMUM_NUMBER_OF_REPORTS_PER_EVENT:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_maximum_number_of_reports_per_event, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static void
dissect_mdd_dsg_da_to_dsid(tvbuff_t * tvb, packet_info* pinfo _U_, proto_tree * tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *mdd_tree;
proto_item *mdd_item;
int pos;
pos = start;
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos);
mdd_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_mdd_dsg_da_to_dsid, &mdd_item,
val_to_str(type, mdd_cm_dsg_da_to_dsid_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (mdd_tree, hf_docsis_mdd_dsg_da_to_dsid_subtype, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (mdd_tree, hf_docsis_mdd_dsg_da_to_dsid_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(mdd_item, length + 2);
switch(type)
{
case DSG_DA_TO_DSID_ASSOCIATION_DA:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_dsg_da_to_dsid_association_da, tvb, pos, 6, ENC_NA);
break;
case DSG_DA_TO_DSID_ASSOCIATION_DSID:
proto_tree_add_item (mdd_tree, hf_docsis_mdd_dsg_da_to_dsid_association_dsid, tvb, pos, 3, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
}
static int
dissect_mdd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *mdd_tree;
int pos;
guint8 type;
guint32 i, length;
proto_tree *tlv_tree;
proto_item *tlv_item;
static const int * non_channel_events[] = {
&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_sequence_out_of_range,
&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_cm_operating_on_battery_backup,
&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_cm_returned_to_ac_power,
NULL
};
col_set_str(pinfo->cinfo, COL_INFO, "MDD Message:");
it = proto_tree_add_item (tree, proto_docsis_mdd, tvb, 0, -1,ENC_NA);
mdd_tree = proto_item_add_subtree (it, ett_docsis_mdd);
proto_tree_add_item (mdd_tree, hf_docsis_mdd_ccc, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mdd_tree, hf_docsis_mdd_number_of_fragments, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mdd_tree, hf_docsis_mdd_fragment_sequence_number, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mdd_tree, hf_docsis_mdd_current_channel_dcid, tvb, 3, 1, ENC_BIG_ENDIAN);
pos = 4;
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(mdd_tree, tvb, pos, -1,
ett_tlv, &tlv_item,
val_to_str(type, mdd_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_mdd_type, tvb, pos, 1, type);
pos++;
proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_mdd_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch(type)
{
case DOWNSTREAM_ACTIVE_CHANNEL_LIST:
dissect_mdd_ds_active_channel_list(tvb, pinfo, tlv_tree, pos, length );
break;
case MAC_DOMAIN_DOWNSTREAM_SERVICE_GROUP:
dissect_mdd_ds_service_group(tvb, pinfo, tlv_tree, pos, length );
break;
case DOWNSTREAM_AMBIGUITY_RESOLUTION_FREQUENCY_LIST:
for (i = 0; i < length; i+=4) {
proto_tree_add_item (tlv_tree, hf_docsis_mdd_downstream_ambiguity_resolution_frequency, tvb, pos + i, 4, ENC_BIG_ENDIAN);
}
break;
case RECEIVE_CHANNEL_PROFILE_REPORTING_CONTROL:
dissect_mdd_channel_profile_reporting_control(tvb, pinfo, tlv_tree, pos, length );
break;
case IP_INITIALIZATION_PARAMETERS:
dissect_mdd_ip_init_param(tvb, pinfo, tlv_tree, pos, length );
break;
case EARLY_AUTHENTICATION_AND_ENCRYPTION:
proto_tree_add_item (tlv_tree, hf_docsis_mdd_early_authentication_and_encryption, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case UPSTREAM_ACTIVE_CHANNEL_LIST:
dissect_mdd_upstream_active_channel_list(tvb, pinfo, tlv_tree, pos, length );
break;
case UPSTREAM_AMBIGUITY_RESOLUTION_CHANNEL_LIST:
for (i = 0; i < length; i++) {
proto_tree_add_item (tlv_tree, hf_docsis_mdd_upstream_ambiguity_resolution_channel_list_channel_id, tvb, pos + i , 1, ENC_BIG_ENDIAN);
}
break;
case UPSTREAM_FREQUENCY_RANGE:
proto_tree_add_item (tlv_tree, hf_docsis_mdd_upstream_frequency_range, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case SYMBOL_CLOCK_LOCKING_INDICATOR:
proto_tree_add_item (tlv_tree, hf_docsis_mdd_symbol_clock_locking_indicator, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case CM_STATUS_EVENT_CONTROL:
dissect_mdd_cm_status_event_control(tvb, pinfo, tlv_tree, pos, length );
break;
case UPSTREAM_TRANSMIT_POWER_REPORTING:
proto_tree_add_item (tlv_tree, hf_docsis_mdd_upstream_transmit_power_reporting, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case DSG_DA_TO_DSID_ASSOCIATION_ENTRY:
dissect_mdd_dsg_da_to_dsid(tvb, pinfo, tlv_tree, pos, length );
break;
case CM_STATUS_EVENT_ENABLE_NON_CHANNEL_SPECIFIC_EVENTS:
proto_tree_add_bitmask(tlv_tree, tvb, pos, hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events, ett_sub_tlv, non_channel_events, ENC_BIG_ENDIAN);
break;
case EXTENDED_UPSTREAM_TRANSMIT_POWER_SUPPORT:
proto_tree_add_item (tlv_tree, hf_docsis_mdd_extended_upstream_transmit_power_support, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
}
pos += length;
}
return tvb_captured_length(tvb);
}
static int
dissect_bintrngreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *bintrngreq_item;
proto_tree *bintrngreq_tree;
guint16 md_ds_sg_id;
guint16 offset = 0;
md_ds_sg_id = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO, "Bonded Ranging Request: MD-DS-SG-ID = %u (0x%X)",
md_ds_sg_id, md_ds_sg_id );
bintrngreq_item = proto_tree_add_item(tree, proto_docsis_bintrngreq, tvb, offset, -1, ENC_NA);
bintrngreq_tree = proto_item_add_subtree (bintrngreq_item, ett_docsis_bintrngreq);
proto_tree_add_item (bintrngreq_tree, hf_docsis_bintrngreq_capflags, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( bintrngreq_tree, hf_docsis_bintrngreq_capflags_frag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( bintrngreq_tree, hf_docsis_bintrngreq_capflags_encrypt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item (bintrngreq_tree, hf_docsis_bintrngreq_mddsgid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item (bintrngreq_tree, hf_docsis_mgt_down_chid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item (bintrngreq_tree, hf_docsis_mgt_upstream_chid, tvb, offset, 1, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static int
dissect_type35ucd(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
return dissect_any_ucd(tvb, pinfo, tree, proto_docsis_type35ucd, MGT_TYPE35UCD);
}
static int
dissect_dbcreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *dbcreq_item;
proto_tree *dbcreq_tree;
guint32 transid;
tvbuff_t *next_tvb;
dbcreq_item = proto_tree_add_item(tree, proto_docsis_dbcreq, tvb, 0, -1, ENC_NA);
dbcreq_tree = proto_item_add_subtree (dbcreq_item, ett_docsis_dbcreq);
proto_tree_add_item_ret_uint(dbcreq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item( dbcreq_tree, hf_docsis_dbcreq_number_of_fragments, tvb, 2, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( dbcreq_tree, hf_docsis_dbcreq_fragment_sequence_number, tvb, 3, 1, ENC_BIG_ENDIAN );
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Bonding Change Request: Tran-Id = %u", transid);
next_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dbcreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dbcrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *dbcrsp_item;
proto_tree *dbcrsp_tree;
guint32 transid, confcode;
tvbuff_t *next_tvb;
dbcrsp_item = proto_tree_add_item(tree, proto_docsis_dbcrsp, tvb, 0, -1, ENC_NA);
dbcrsp_tree = proto_item_add_subtree (dbcrsp_item, ett_docsis_dbcrsp);
proto_tree_add_item_ret_uint(dbcrsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint( dbcrsp_tree, hf_docsis_dbcrsp_conf_code, tvb, 2, 1, ENC_BIG_ENDIAN, &confcode);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Bonding Change Response: Tran-Id = %u (%s)", transid,
val_to_str_ext (confcode, &docsis_conf_code_ext, "%d"));
next_tvb = tvb_new_subset_remaining (tvb, 3);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dbcrsp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dbcack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *dbcack_item;
proto_tree *dbcack_tree = NULL;
guint16 transid;
tvbuff_t *next_tvb;
transid = tvb_get_ntohs (tvb, 0);
col_add_fstr (pinfo->cinfo, COL_INFO,
"Dynamic Bonding Change Acknowledge: Tran-Id = %u", transid);
dbcack_item = proto_tree_add_item(tree, proto_docsis_dbcack, tvb, 0, -1, ENC_NA);
dbcack_tree = proto_item_add_subtree (dbcack_item, ett_docsis_dbcack);
proto_tree_add_item (dbcack_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining (tvb, 2);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, dbcack_tree);
return tvb_captured_length(tvb);
}
static int
dissect_dpvreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dpvreq_tree;
guint32 transid, dschan;
it = proto_tree_add_item(tree, proto_docsis_dpvreq, tvb, 0, -1, ENC_NA);
dpvreq_tree = proto_item_add_subtree (it, ett_docsis_dpvreq);
proto_tree_add_item_ret_uint (dpvreq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dpvreq_tree, hf_docsis_mgt_down_chid, tvb, 2, 1, ENC_BIG_ENDIAN, &dschan);
col_add_fstr (pinfo->cinfo, COL_INFO,
"DOCSIS Path Verify Request: Transaction-Id = %u DS-Ch %d",
transid, dschan);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_flags, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_us_sf, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_n, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_start, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_end, tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_ts_start, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvreq_tree, hf_docsis_dpv_ts_end, tvb, 16, 4, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static int
dissect_dpvrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dpvrsp_tree = NULL;
guint32 transid, dschan;
it = proto_tree_add_item (tree, proto_docsis_dpvrsp, tvb, 0, -1, ENC_NA);
dpvrsp_tree = proto_item_add_subtree (it, ett_docsis_dpvrsp);
proto_tree_add_item_ret_uint (dpvrsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
proto_tree_add_item_ret_uint (dpvrsp_tree, hf_docsis_mgt_down_chid, tvb, 2, 1, ENC_BIG_ENDIAN, &dschan);
col_add_fstr (pinfo->cinfo, COL_INFO,
"DOCSIS Path Verify Response: Transaction-Id = %u DS-Ch %d",
transid, dschan);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_flags, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_us_sf, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_n, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_start, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_end, tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_ts_start, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dpvrsp_tree, hf_docsis_dpv_ts_end, tvb, 16, 4, ENC_BIG_ENDIAN);
return tvb_captured_length(tvb);
}
static void
dissect_cmstatus_tlv (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree)
{
proto_item *it, *tlv_item, *tlv_len_item;
proto_tree *tlv_tree;
guint16 pos = 0;
guint8 type;
guint32 length;
it = proto_tree_add_item(tree, hf_docsis_cmstatus_tlv_data, tvb, 0, tvb_reported_length(tvb), ENC_NA);
tlv_tree = proto_item_add_subtree (it, ett_docsis_cmstatus_tlv);
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(tlv_tree, tvb, pos, -1,
ett_docsis_cmstatus_tlvtlv, &tlv_item,
val_to_str(type, cmstatus_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_cmstatus_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_cmstatus_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case EVENT_DS_CH_ID:
if (length == 3)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_ds_ch_id, tvb, pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case EVENT_US_CH_ID:
if (length == 3)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_us_ch_id, tvb, pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case EVENT_DSID:
if (length == 5)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_dsid, tvb, pos + 1, 3, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case EVENT_DESCR:
if (length >= 3 && length <= 82)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_descr, tvb, pos + 1, length - 2, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static int
dissect_cmstatus (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *cmstatus_tree;
guint32 transid;
guint8 event_type;
tvbuff_t* next_tvb;
it = proto_tree_add_item(tree, proto_docsis_cmstatus, tvb, 0, -1, ENC_NA);
cmstatus_tree = proto_item_add_subtree (it, ett_docsis_cmstatus);
proto_tree_add_item_ret_uint (cmstatus_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO, "CM-STATUS Report: Transaction ID = %u", transid);
event_type = tvb_get_guint8 (tvb, 2);
switch (event_type)
{
case SEC_CH_MDD_TIMEOUT:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_mdd_t, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case QAM_FEC_LOCK_FAILURE:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_qfl_f, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SEQ_OUT_OF_RANGE:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_s_o, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SEC_CH_MDD_RECOVERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_mdd_r, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case QAM_FEC_LOCK_RECOVERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_qfl_r, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case T4_TIMEOUT:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_t4_t, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case T3_RETRIES_EXCEEDED:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_t3_e, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SUCCESS_RANGING_AFTER_T3_RETRIES_EXCEEDED:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_rng_s, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case CM_ON_BATTERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_cm_b, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case CM_ON_AC_POWER:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_cm_a, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
}
next_tvb = tvb_new_subset_remaining(tvb, 3);
dissect_cmstatus_tlv(next_tvb, pinfo, cmstatus_tree);
return tvb_captured_length(tvb);
}
static void
dissect_ds_event(tvbuff_t * tvb, packet_info* pinfo, proto_tree *tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *event_tree;
proto_item *event_item, *tlv_len_item;
int pos = start;
while (pos < (start + len))
{
type = tvb_get_guint8 (tvb, pos);
event_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_cmctrl_tlv_ds_event, &event_item,
val_to_str(type, cmctrlreq_ds_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (event_tree, hf_docsis_cmctrl_ds_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (event_tree, hf_docsis_cmctrl_ds_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(event_item, length + 2);
switch (type)
{
case DS_EVENT_CH_ID:
if (length == 1)
{
proto_tree_add_item (event_tree, hf_docsis_cmctrl_ds_event_ch_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case DS_EVENT_MASK:
if (length == 2)
{
proto_tree_add_item (event_tree, hf_docsis_cmctrl_ds_event_mask, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static void
dissect_us_event(tvbuff_t * tvb, packet_info* pinfo, proto_tree *tree, int start, guint16 len)
{
guint8 type;
guint32 length;
proto_tree *event_tree;
proto_item *event_item, *tlv_len_item;
int pos = start;
while (pos < (start + len))
{
type = tvb_get_guint8 (tvb, pos);
event_tree = proto_tree_add_subtree(tree, tvb, pos, -1,
ett_docsis_cmctrl_tlv_us_event, &event_item,
val_to_str(type, cmctrlreq_us_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (event_tree, hf_docsis_cmctrlreq_us_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (event_tree, hf_docsis_cmctrlreq_us_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(event_item, length + 2);
switch (type)
{
case US_EVENT_CH_ID:
if (length == 1)
{
proto_tree_add_item (event_tree, hf_docsis_cmctrl_us_event_ch_id, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case US_EVENT_MASK:
if (length == 2)
{
proto_tree_add_item (event_tree, hf_docsis_cmctrl_us_event_mask, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static void
dissect_cmctrlreq_tlv(tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree)
{
proto_item *it, *tlv_item, *tlv_len_item;
proto_tree *tlv_tree;
guint16 pos = 0;
guint8 type;
guint32 length;
it = proto_tree_add_item(tree, hf_docsis_cmctrlreq_tlv_data, tvb, 0, tvb_reported_length(tvb), ENC_NA);
tlv_tree = proto_item_add_subtree (it, ett_docsis_cmctrlreq_tlv);
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(tlv_tree, tvb, pos, -1,
ett_docsis_cmctrlreq_tlvtlv, &tlv_item,
val_to_str(type, cmctrlreq_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_cmctrlreq_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_cmctrlreq_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case CM_CTRL_MUTE:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_mute, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case CM_CTRL_MUTE_TIMEOUT:
if (length == 4 || length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_mute_timeout, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case CM_CTRL_REINIT:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_reinit, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case CM_CTRL_DISABLE_FWD:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_disable_fwd, tvb, pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case CM_CTRL_DS_EVENT:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_ds_event, tvb, pos, length, ENC_NA);
}
else
{
dissect_ds_event(tvb, pinfo, tlv_tree, pos, length);
}
break;
case CM_CTRL_US_EVENT:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_us_event, tvb, pos, length, ENC_NA);
}
else
{
dissect_us_event(tvb, pinfo, tlv_tree, pos, length);
}
break;
case CM_CTRL_EVENT:
if (length == 2 || length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmctrl_tlv_event, tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos += length;
}
}
static int
dissect_cmctrlreq(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *cmctrlreq_tree;
guint32 transid;
tvbuff_t *next_tvb;
it = proto_tree_add_item (tree, proto_docsis_cmctrlreq, tvb, 0, -1, ENC_NA);
cmctrlreq_tree = proto_item_add_subtree (it, ett_docsis_cmctrlreq);
proto_tree_add_item_ret_uint (cmctrlreq_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"CM Control Request: Transaction-Id = %u", transid);
next_tvb = tvb_new_subset_remaining(tvb, 2);
dissect_cmctrlreq_tlv(next_tvb, pinfo, cmctrlreq_tree);
return tvb_captured_length(tvb);
}
static int
dissect_cmctrlrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *cmctrlrsp_tree;
guint32 transid;
tvbuff_t *next_tvb;
it = proto_tree_add_item(tree, proto_docsis_cmctrlrsp, tvb, 0, -1, ENC_NA);
cmctrlrsp_tree = proto_item_add_subtree (it, ett_docsis_cmctrlrsp);
proto_tree_add_item_ret_uint (cmctrlrsp_tree, hf_docsis_mgt_tranid, tvb, 0, 2, ENC_BIG_ENDIAN, &transid);
col_add_fstr (pinfo->cinfo, COL_INFO,
"CM Control Response: Transaction-Id = %u", transid);
next_tvb = tvb_new_subset_remaining (tvb, 2);
dissect_cmctrlreq_tlv(next_tvb, pinfo, cmctrlrsp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_regreqmp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regreqmp_tree;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_INFO, "REG-REQ-MP Message:");
it = proto_tree_add_item(tree, proto_docsis_regreqmp, tvb, 0, -1, ENC_NA);
regreqmp_tree = proto_item_add_subtree (it, ett_docsis_regreqmp);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_sid, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_number_of_fragments, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regreqmp_tree, hf_docsis_regreqmp_fragment_sequence_number, tvb, 3, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining (tvb, 4);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regreqmp_tree);
return tvb_captured_length(tvb);
}
static int
dissect_regrspmp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *regrspmp_tree;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_INFO, "REG-RSP-MP Message:");
it = proto_tree_add_item(tree, proto_docsis_regrspmp, tvb, 0, -1, ENC_NA);
regrspmp_tree = proto_item_add_subtree (it, ett_docsis_regrspmp);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_sid, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_response, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_number_of_fragments, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (regrspmp_tree, hf_docsis_regrspmp_fragment_sequence_number, tvb, 4, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining (tvb, 5);
call_dissector (docsis_tlv_handle, next_tvb, pinfo, regrspmp_tree);
return tvb_captured_length(tvb);
}
static void
dissect_subcarrier_assignment_range_list(tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree, guint16 pos, guint32 len)
{
proto_item* type_item;
guint32 i, subcarrier_assignment_type;
type_item = proto_tree_add_item_ret_uint (tree, hf_docsis_ocd_tlv_subc_assign_type, tvb, pos, 1, ENC_BIG_ENDIAN, &subcarrier_assignment_type);
proto_tree_add_item (tree, hf_docsis_ocd_tlv_subc_assign_value, tvb, pos, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_docsis_ocd_subc_assign_subc_type, tvb, pos, 1, ENC_BIG_ENDIAN);
pos++;
switch (subcarrier_assignment_type) {
case SUBCARRIER_ASSIGNMENT_RANGE_CONT:
case SUBCARRIER_ASSIGNMENT_RANGE_SKIPBY1:
proto_tree_add_item (tree, hf_docsis_ocd_subc_assign_range, tvb, pos, 4, ENC_BIG_ENDIAN);
break;
case SUBCARRIER_ASSIGNMENT_LIST:
for (i = 0; i < len/2; ++i) {
proto_tree_add_item (tree, hf_docsis_ocd_subc_assign_index, tvb, pos, 2, ENC_BIG_ENDIAN);
pos += 2;
}
break;
default:
expert_add_info_format(pinfo, type_item, &ei_docsis_mgmt_tlvtype_unknown, "Unknown subcarrier assignment type %d", subcarrier_assignment_type);
break;
}
}
static void
dissect_ocd_tlv (tvbuff_t * tvb, packet_info* pinfo, proto_tree * tree)
{
proto_item *it, *tlv_item, *tlv_len_item;
proto_tree *tlv_tree;
guint16 pos = 0;
guint8 type;
guint32 length;
it = proto_tree_add_item(tree, hf_docsis_ocd_tlv_data, tvb, 0, tvb_reported_length(tvb), ENC_NA);
tlv_tree = proto_item_add_subtree (it, ett_docsis_ocd_tlv);
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(tlv_tree, tvb, pos, -1,
ett_docsis_ocd_tlvtlv, &tlv_item,
val_to_str(type, ocd_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_ocd_type, tvb, pos, 1, type);
pos++;
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_ocd_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case DISCRETE_FOURIER_TRANSFORM_SIZE:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_four_trans_size, tvb, pos, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case CYCLIC_PREFIX:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_cycl_pref, tvb, pos, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case ROLL_OFF:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_roll_off, tvb, pos, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case OFDM_SPECTRUM_LOCATION:
if (length == 4)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_ofdm_spec_loc, tvb, pos, 4, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case TIME_INTERLEAVING_DEPTH:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_time_int_depth, tvb, pos, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case SUBCARRIER_ASSIGNMENT_RANGE_LIST:
if (length >= 5)
{
dissect_subcarrier_assignment_range_list(tvb, pinfo, tlv_tree, pos, length);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case PRIMARY_CAPABILITY_INDICATOR:
if (length == 1)
{
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_prim_cap_ind, tvb, pos, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
default:
proto_tree_add_item (tlv_tree, hf_docsis_ocd_tlv_unknown, tvb, pos - 2, length+2, ENC_NA);
break;
}
pos += length;
}
}
static int
dissect_ocd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *ocd_tree;
tvbuff_t *next_tvb;
guint32 downstream_channel_id, configuration_change_count;
it = proto_tree_add_item(tree, proto_docsis_ocd, tvb, 0, -1, ENC_NA);
ocd_tree = proto_item_add_subtree (it, ett_docsis_ocd);
proto_tree_add_item_ret_uint (ocd_tree, hf_docsis_mgt_down_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &downstream_channel_id);
proto_tree_add_item_ret_uint (ocd_tree, hf_docsis_ocd_ccc, tvb, 1, 1, ENC_BIG_ENDIAN, &configuration_change_count);
col_add_fstr (pinfo->cinfo, COL_INFO, "OCD: DS CH ID: %u, CCC: %u", downstream_channel_id, configuration_change_count);
next_tvb = tvb_new_subset_remaining(tvb, 2);
dissect_ocd_tlv(next_tvb, pinfo, ocd_tree);
return tvb_captured_length(tvb);
}
static void
dissect_dpd_subcarrier_assignment_range_list(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, guint pos, guint len)
{
guint32 i, subcarrier_assignment_type;
proto_item* type_item;
type_item = proto_tree_add_item_ret_uint (tree, hf_docsis_dpd_tlv_subc_assign_type, tvb, pos, 1, ENC_BIG_ENDIAN, &subcarrier_assignment_type);
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_value, tvb, pos, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_reserved, tvb, pos, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_modulation, tvb, pos, 1, ENC_BIG_ENDIAN);
pos++;
switch (subcarrier_assignment_type)
{
case SUBCARRIER_ASSIGNMENT_RANGE_CONT:
case SUBCARRIER_ASSIGNMENT_RANGE_SKIPBY1:
proto_tree_add_item (tree, hf_docsis_dpd_subc_assign_range, tvb, pos, 4, ENC_BIG_ENDIAN);
break;
case SUBCARRIER_ASSIGNMENT_LIST:
for (i = 0; i < len/2; ++i) {
proto_tree_add_item (tree, hf_docsis_dpd_subc_assign_index, tvb, pos, 2, ENC_BIG_ENDIAN);
pos += 2;
}
break;
default:
expert_add_info_format(pinfo, type_item, &ei_docsis_mgmt_tlvtype_unknown, "Unknown subcarrier assignment type: %u", subcarrier_assignment_type);
break;
}
}
static void
dissect_dpd_subcarrier_assignment_vector(tvbuff_t * tvb, proto_tree * tree, guint start, guint len)
{
guint32 subcarrier_assignment_vector_oddness;
guint vector_index;
proto_tree_add_item_ret_uint (tree, hf_docsis_dpd_tlv_subc_assign_vector_oddness, tvb, start, 1, ENC_BIG_ENDIAN, &subcarrier_assignment_vector_oddness);
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_vector_reserved, tvb, start, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_vector_subc_start, tvb, start, 2, ENC_BIG_ENDIAN);
for(vector_index = 0; vector_index < len; ++vector_index)
{
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_vector_modulation_odd, tvb, start + 2 + vector_index, 1, ENC_BIG_ENDIAN);
if (!((vector_index == len -1) && subcarrier_assignment_vector_oddness))
{
proto_tree_add_item (tree, hf_docsis_dpd_tlv_subc_assign_vector_modulation_even, tvb, start + 2 + vector_index, 1, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_dpd_tlv (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it, *tlv_item, *tlv_len_item;
proto_tree *tlv_tree;
guint pos = 0;
guint length;
guint8 type;
it = proto_tree_add_item(tree, hf_docsis_dpd_tlv_data, tvb, 0, tvb_reported_length(tvb), ENC_NA);
tlv_tree = proto_item_add_subtree (it, ett_docsis_dpd_tlv);
while (tvb_reported_length_remaining(tvb, pos) > 0)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(tlv_tree, tvb, pos, -1,
ett_docsis_dpd_tlvtlv, &tlv_item,
val_to_str(type, dpd_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_dpd_type, tvb, pos, 1, type);
pos++;
if (type != SUBCARRIER_ASSIGNMENT_VECTOR)
{
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dpd_length, tvb, pos, 1, ENC_NA, &length);
pos++;
proto_item_set_len(tlv_item, length + 2);
}
switch (type)
{
case SUBCARRIER_ASSIGNMENT_RANGE_LIST:
if (length >= 5)
{
dissect_dpd_subcarrier_assignment_range_list(tvb, pinfo, tlv_tree, pos, length);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case SUBCARRIER_ASSIGNMENT_VECTOR:
tlv_len_item = proto_tree_add_item_ret_uint (tlv_tree, hf_docsis_dpd_length, tvb, pos, 2, ENC_BIG_ENDIAN, &length);
pos += 2;
proto_item_set_len(tlv_item, length + 2);
if (length >=2)
{
dissect_dpd_subcarrier_assignment_vector(tvb, tlv_tree, pos, length);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_docsis_mgmt_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
default:
proto_tree_add_item (tlv_tree, hf_docsis_dpd_tlv_unknown, tvb, pos - 2, length+2, ENC_NA);
expert_add_info_format(pinfo, tlv_item, &ei_docsis_mgmt_tlvtype_unknown, "Unknown TLV: %u", type);
break;
}
pos += length;
}
}
static int
dissect_dpd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *dpd_tree;
tvbuff_t *next_tvb;
guint32 downstream_channel_id, profile_identifier, configuration_change_count;
it = proto_tree_add_item(tree, proto_docsis_dpd, tvb, 0, -1, ENC_NA);
dpd_tree = proto_item_add_subtree (it, ett_docsis_dpd);
proto_tree_add_item_ret_uint (dpd_tree, hf_docsis_mgt_down_chid, tvb, 0, 1, ENC_BIG_ENDIAN, &downstream_channel_id);
proto_tree_add_item_ret_uint (dpd_tree, hf_docsis_dpd_prof_id, tvb, 1, 1, ENC_BIG_ENDIAN, &profile_identifier);
proto_tree_add_item_ret_uint (dpd_tree, hf_docsis_dpd_ccc, tvb, 2, 1, ENC_BIG_ENDIAN, &configuration_change_count);
col_add_fstr (pinfo->cinfo, COL_INFO, "DPD: DS CH ID: %u, Profile ID: %u, CCC: %u", downstream_channel_id, profile_identifier, configuration_change_count);
next_tvb = tvb_new_subset_remaining(tvb, 3);
dissect_dpd_tlv(next_tvb, pinfo, dpd_tree);
return tvb_captured_length(tvb);
}
static int
dissect_type51ucd(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
return dissect_any_ucd(tvb, pinfo, tree, proto_docsis_type51ucd, MGT_TYPE51UCD);
}
static int
dissect_macmgmt (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint32 type, msg_len;
proto_item *mgt_hdr_it;
proto_tree *mgt_hdr_tree;
tvbuff_t *payload_tvb;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "DOCSIS MGMT");
col_clear(pinfo->cinfo, COL_INFO);
set_address_tvb (&pinfo->dl_src, AT_ETHER, 6, tvb, 6);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
set_address_tvb (&pinfo->dl_dst, AT_ETHER, 6, tvb, 0);
copy_address_shallow(&pinfo->dst, &pinfo->dl_dst);
mgt_hdr_it = proto_tree_add_item (tree, proto_docsis_mgmt, tvb, 0, 20, ENC_NA);
mgt_hdr_tree = proto_item_add_subtree (mgt_hdr_it, ett_docsis_mgmt);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_dst_addr, tvb, 0, 6, ENC_NA);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_src_addr, tvb, 6, 6, ENC_NA);
proto_tree_add_item_ret_uint (mgt_hdr_tree, hf_docsis_mgt_msg_len, tvb, 12, 2, ENC_BIG_ENDIAN, &msg_len);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_dsap, tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_ssap, tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_control, tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_version, tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_item_ret_uint (mgt_hdr_tree, hf_docsis_mgt_type, tvb, 18, 1, ENC_BIG_ENDIAN, &type);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_rsvd, tvb, 19, 1, ENC_BIG_ENDIAN);
payload_tvb = tvb_new_subset_length (tvb, 20, msg_len - 6);
if (!dissector_try_uint(docsis_mgmt_dissector_table, type, payload_tvb, pinfo, tree))
call_data_dissector(payload_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_docsis_mgmt (void)
{
static hf_register_info hf[] = {
{&hf_docsis_sync_cmts_timestamp,
{"CMTS Timestamp", "docsis_sync.cmts_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sync CMTS Timestamp", HFILL}
},
{&hf_docsis_ucd_config_ch_cnt,
{"Config Change Count", "docsis_ucd.confcngcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Configuration Change Count", HFILL}
},
{&hf_docsis_ucd_mini_slot_size,
{"Mini Slot Size (6.25us TimeTicks)", "docsis_ucd.mslotsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_type,
{"Type", "docsis_ucd.type",
FT_UINT8, BASE_DEC, VALS(channel_tlv_vals), 0x0,
"Channel TLV type", HFILL}
},
{&hf_docsis_ucd_length,
{"Length", "docsis_ucd.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Channel TLV length", HFILL}
},
{&hf_docsis_ucd_burst_type,
{"Type", "docsis_ucd.burst.tlvtype",
FT_UINT8, BASE_DEC, VALS(burst_tlv_vals), 0x0,
"Burst TLV type", HFILL}
},
{&hf_docsis_ucd_burst_length,
{"Length", "docsis_ucd.burst.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Burst TLV length", HFILL}
},
{&hf_docsis_ucd_symbol_rate,
{"Symbol Rate (ksym/sec)", "docsis_ucd.symrate",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Symbol Rate", HFILL}
},
{&hf_docsis_ucd_frequency,
{"Frequency (Hz)", "docsis_ucd.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Upstream Center Frequency", HFILL}
},
{&hf_docsis_ucd_preamble_pat,
{"Preamble Pattern", "docsis_ucd.preamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Preamble Superstring", HFILL}
},
{&hf_docsis_ucd_ext_preamble_pat,
{"Extended Preamble Pattern", "docsis_ucd.extpreamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Extended Preamble Superstring", HFILL}
},
{&hf_docsis_ucd_scdma_mode_enabled,
{"S-CDMA Mode Enabled", "docsis_ucd.scdma",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_spreading_interval,
{"SCDMA Spreading Interval", "docsis_ucd.scdmaspreadinginterval",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_codes_per_mini_slot,
{"SCDMA Codes per mini slot", "docsis_ucd.scdmacodesperminislot",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_active_codes,
{"SCDMA Active Codes", "docsis_ucd.scdmaactivecodes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_code_hopping_seed,
{"SCDMA Code Hopping Seed", "docsis_ucd.scdmacodehoppingseed",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_us_ratio_num,
{"SCDMA US Ratio Numerator", "docsis_ucd.scdmausrationum",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_us_ratio_denom,
{"SCDMA US Ratio Denominator", "docsis_ucd.scdmausratiodenom",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_timestamp_snapshot,
{"SCDMA Timestamp Snapshot", "docsis_ucd.scdmatimestamp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_maintain_power_spectral_density,
{"Maintain Power Spectral Density", "docsis_ucd.maintpower",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_ranging_required,
{"Ranging Required", "docsis_ucd.rangingreq",
FT_UINT8, BASE_DEC, VALS (ranging_req_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_max_scheduled_codes,
{"S-CDMA Max Scheduled Codes", "docsis_ucd.scdmamaxcodes",
FT_UINT8, BASE_DEC, VALS (max_scheduled_codes_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_cm,
{"Ranging Hold-Off (CM)","docsis_ucd.rnghoffcm",
FT_BOOLEAN, 32, TFS(&tfs_allow_inhibit), 0x1,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_erouter,
{"Ranging Hold-Off (eRouter)",
"docsis_ucd.rnghofferouter",
FT_BOOLEAN, 32, TFS(&tfs_allow_inhibit), 0x2,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_emta,
{"Ranging Hold-Off (eMTA or EDVA)",
"docsis_ucd.rnghoffemta",
FT_BOOLEAN, 32, TFS(&tfs_allow_inhibit), 0x4,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_estb,
{"Ranging Hold-Off (DSG/eSTB)",
"docsis_ucd.rnghoffestb",
FT_BOOLEAN, 32, TFS(&tfs_allow_inhibit), 0x8,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_rsvd,
{"Reserved",
"docsis_ucd.rnghoffrsvd",
FT_UINT32, BASE_HEX, NULL, 0xFFF0,
NULL, HFILL}
},
{&hf_docsis_ucd_rnghoff_id_ext,
{"CM Ranging Class ID Extension",
"docsis_ucd.rngidext",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_cm,
{"Channel Class ID (CM)","docsis_ucd.classidcm",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x1,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_erouter,
{"Channel Class ID (eRouter)",
"docsis_ucd.classiderouter",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x2,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_emta,
{"Channel Class ID (eMTA or EDVA)",
"docsis_ucd.classidemta",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x4,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_estb,
{"Channel Class ID (DSG/eSTB)",
"docsis_ucd.classidestb",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x8,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_rsvd,
{"Reserved",
"docsis_ucd.classidrsvd",
FT_UINT32, BASE_HEX, NULL, 0xFFF0,
NULL, HFILL}
},
{&hf_docsis_ucd_chan_class_id_id_ext,
{"CM Ranging Class ID Extension",
"docsis_ucd.classidext",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_subc_excl_band,
{"UCD Change Indicator Bitmask: Subcarrier Exclusion Band TLV", "docsis_ucd.burst.ucd_change_ind_bitmask_subc_excl_band",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x01,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_unused_subc,
{"UCD Change Indicator Bitmask: Unused Subcarrier Specification TLV", "docsis_ucd.burst.ucd_change_ind_bitmask_unused_subc",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x02,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_other_subc,
{"UCD Change Indicator Bitmask: Other than Subcarrier Exclusion Band and Unused Subcarrier Specification TLV", "docsis_ucd.burst.ucd_change_ind_bitmask_other_subc",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x04,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc5,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC5", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc5",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x08,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc6,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC6", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc6",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x10,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc9,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC9", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc9",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x20,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc10,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC10", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc10",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x40,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc11,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC11", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc11",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x80,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc12,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC12", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc12",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x01,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc13,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC13", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc13",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x02,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_burst_attr_iuc3_or_4,
{"UCD Change Indicator Bitmask: Burst Attributes associated with IUC3 or IUC4", "docsis_ucd.burst.ucd_change_ind_bitmask_burst_attr_iuc3_or_4",
FT_BOOLEAN, 8, TFS(&tfs_ucd_change_ind_vals), 0x04,
NULL, HFILL}
},
{&hf_docsis_ucd_change_ind_bitmask_reserved,
{"UCD Change Indicator Bitmask: Reserved", "docsis_ucd.burst.ucd_change_ind_bitmask_reserved",
FT_UINT8, BASE_HEX, NULL, 0xF8,
NULL, HFILL}
},
{&hf_docsis_ucd_ofdma_timestamp_snapshot,
{"OFDMA Timestamp Snapshot", "docsis_ucd.ofdma_timestamp_snapshot",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_ofdma_cyclic_prefix_size,
{"OFDMA Cyclic Prefix Size", "docsis_ucd.ofdma_cyclic_prefix_size",
FT_UINT8, BASE_DEC, VALS(ofdma_cyclic_prefix_size_vals), 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_ofdma_rolloff_period_size,
{"OFDMA Rolloff Period Size", "docsis_ucd.ofdma_rolloff_period_size",
FT_UINT8, BASE_DEC, VALS(ofdma_rolloff_period_size_vals), 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_subc_spacing,
{"Subcarrier Spacing", "docsis_ucd.subc_spacing",
FT_UINT8, BASE_DEC, VALS(subc_spacing_vals), 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_cent_freq_subc0,
{"Center Frequency of Subcarrier 0", "docsis_ucd.cent_freq_subc0",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_subcarrier_range,
{"Subcarrier range", "docsis_ucd.subc_range",
FT_UINT32, BASE_CUSTOM, CF_FUNC(subc_assign_range), 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_symb_ofdma_frame,
{"Symbols in OFDMA frame", "docsis_ucd.symb_ofdma_frame",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_rand_seed,
{"Randomization Seed", "docsis_ucd.rand_seed",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL}
},
{&hf_docsis_ucd_iuc,
{"Interval Usage Code", "docsis_ucd.iuc",
FT_UINT8, BASE_DEC, VALS (iuc_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_mod_type,
{"Modulation Type", "docsis_ucd.burst.modtype",
FT_UINT8, BASE_DEC, VALS (mod_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_diff_encoding,
{"Differential Encoding", "docsis_ucd.burst.diffenc",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_preamble_len,
{"Preamble Length (Bits)", "docsis_ucd.burst.preamble_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_preamble_val_off,
{"Preamble Offset (Bits)", "docsis_ucd.burst.preamble_off",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_fec,
{"FEC (T)", "docsis_ucd.burst.fec",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC (T) Codeword Parity Bits = 2^T", HFILL}
},
{&hf_docsis_burst_fec_codeword,
{"FEC Codeword Info bytes (k)", "docsis_ucd.burst.fec_codeword",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_scrambler_seed,
{"Scrambler Seed", "docsis_ucd.burst.scrambler_seed",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Burst Descriptor", HFILL}
},
{&hf_docsis_burst_max_burst,
{"Max Burst Size (Minislots)", "docsis_ucd.burst.maxburst",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_guard_time,
{"Guard Time Size (Symbol Times)", "docsis_ucd.burst.guardtime",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Guard Time Size", HFILL}
},
{&hf_docsis_burst_last_cw_len,
{"Last Codeword Length", "docsis_ucd.burst.last_cw_len",
FT_UINT8, BASE_DEC, VALS (last_cw_len_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_scrambler_onoff,
{"Scrambler On/Off", "docsis_ucd.burst.scrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_rs_int_depth,
{"RS Interleaver Depth", "docsis_ucd.burst.rsintdepth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Depth", HFILL}
},
{&hf_docsis_rs_int_block,
{"RS Interleaver Block Size", "docsis_ucd.burst.rsintblock",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Block", HFILL}
},
{&hf_docsis_preamble_type,
{"Preamble Type", "docsis_ucd.burst.preambletype",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_scrambler_onoff,
{"Scrambler On/Off", "docsis_ucd.burst.scdmascrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"SCDMA Scrambler On/Off", HFILL}
},
{&hf_docsis_ucd_scdma_codes_per_subframe,
{"SCDMA Codes per Subframe", "docsis_ucd.burst.scdmacodespersubframe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_framer_int_step_size,
{"SCDMA Framer Interleaving Step Size", "docsis_ucd.burst.scdmaframerintstepsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_tcm_enabled,
{"TCM Enabled", "docsis_ucd.burst.tcmenabled",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_active_code_hopping,
{"S-CDMA Selection Mode for Active Codes and Code Hopping", "docsis_ucd.selectcodehop",
FT_UINT8, BASE_DEC, VALS (tlv20_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_scdma_selection_active_codes,
{"S-CDMA Selection String for Active Codes", "docsis_ucd.selectcode",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ucd_higher_ucd_for_same_ucid,
{"Higher UCD for the same UCID", "docsis_ucd.highucdpresent",
FT_BOOLEAN, 8, TFS(&type35ucd_tfs_present_not_present), 0x1,
NULL, HFILL}
},
{&hf_docsis_ucd_higher_ucd_for_same_ucid_resv,
{"Reserved", "docsis_ucd.highucdresv",
FT_UINT8, BASE_HEX, NULL, 0xFE,
NULL, HFILL}
},
{&hf_docsis_subc_init_rang,
{"Subcarriers (Nir) Initial Ranging", "docsis_ucd.burst.subc_init_rang",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_subc_fine_rang,
{"Subcarriers (Nfr) Fine Ranging", "docsis_ucd.burst.subc_fine_rang",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ofdma_prof_mod_order,
{"OFDMA Profile: modulation", "docsis_ucd.burst.ofma_prof_mod_order",
FT_UINT8, BASE_DEC, VALS(ofdma_prof_mod_order), 0xF0,
NULL, HFILL}
},
{&hf_docsis_ofdma_prof_pilot_pattern,
{"OFDMA Profile: pilot pattern", "docsis_ucd.burst.ofma_prof_pilot_pattern",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL}
},
{&hf_docsis_ofdma_prof_num_add_minislots,
{"OFDMA Profile: Additional Minislots that have identical bit-loading and pilot pattern index", "docsis_ucd.burst.ofma_prof_add_minislots",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{&hf_docsis_ofdma_ir_pow_ctrl_start_pow,
{"OFDMA IR Power Control Starting Power Level", "docsis_ucd.burst.ofma_ir_pow_ctrl_start_pow",
FT_UINT8, BASE_CUSTOM, CF_FUNC(ofdma_ir_pow_ctrl_start_pow), 0x00,
NULL, HFILL}
},
{&hf_docsis_ofdma_ir_pow_ctrl_step_size,
{"OFDMA IR Power Control Step Size", "docsis_ucd.burst.ofma_ir_pow_ctrl_step_size",
FT_UINT8, BASE_CUSTOM, CF_FUNC(ofdma_ir_pow_ctrl_step_size), 0x00,
NULL, HFILL}
},
{&hf_docsis_map_ucd_count,
{"UCD Count", "docsis_map.ucdcount",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Map UCD Count", HFILL}
},
{&hf_docsis_map_numie,
{"Number of IE's", "docsis_map.numie",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Information Elements", HFILL}
},
{&hf_docsis_map_alloc_start,
{"Alloc Start Time (minislots)", "docsis_map.allocstart",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_ack_time,
{"ACK Time (minislots)", "docsis_map.acktime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_rng_start,
{"Ranging Backoff Start", "docsis_map.rng_start",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_rng_end,
{"Ranging Backoff End", "docsis_map.rng_end",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_data_start,
{"Data Backoff Start", "docsis_map.data_start",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_data_end,
{"Data Backoff End", "docsis_map.data_end",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_ie,
{"Information Element", "docsis_map.ie",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_map_rsvd,
{"Reserved", "docsis_map.rsvd",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved Byte", HFILL}
},
{&hf_docsis_map_sid,
{"Service Identifier", "docsis_map.sid",
FT_UINT32, BASE_DEC, NULL, 0xFFFC0000,
NULL, HFILL}
},
{&hf_docsis_map_iuc,
{"Interval Usage Code", "docsis_map.iuc",
FT_UINT32, BASE_DEC, VALS(iuc_vals), 0x0003c000,
NULL, HFILL}
},
{&hf_docsis_map_offset,
{"Offset", "docsis_map.offset",
FT_UINT32, BASE_DEC, NULL, 0x00003fff,
NULL, HFILL}
},
{&hf_docsis_rngreq_sid,
{"Service Identifier", "docsis_rngreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_rngreq_pend_compl,
{"Pending Till Complete", "docsis_rngreq.pendcomp",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Upstream Channel ID", HFILL}
},
{&hf_docsis_rngrsp_type,
{"Type", "docsis_rngrsp.type",
FT_UINT8, BASE_DEC, VALS(rngrsp_tlv_vals), 0x0,
"TLV Type", HFILL}
},
{&hf_docsis_rngrsp_length,
{"Length", "docsis_rngrsp.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TLV Length", HFILL}
},
{&hf_docsis_rngrsp_sid,
{"Service Identifier", "docsis_rngrsp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_rngrsp_timing_adj,
{"Timing Adjust (6.25us/64)", "docsis_rngrsp.timingadj",
FT_INT32, BASE_DEC, NULL, 0x0,
"Timing Adjust", HFILL}
},
{&hf_docsis_rngrsp_power_adj,
{"Power Level Adjust (0.25dB units)", "docsis_rngrsp.poweradj",
FT_INT8, BASE_DEC, NULL, 0x0,
"Power Level Adjust", HFILL}
},
{&hf_docsis_rngrsp_freq_adj,
{"Offset Freq Adjust (Hz)", "docsis_rngrsp.freqadj",
FT_INT16, BASE_DEC, NULL, 0x0,
"Frequency Adjust", HFILL}
},
{&hf_docsis_rngrsp_xmit_eq_adj,
{"Transmit Equalisation Adjust", "docsis_rngrsp.xmit_eq_adj",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Timing Equalisation Adjust", HFILL}
},
{&hf_docsis_rngrsp_ranging_status,
{"Ranging Status", "docsis_rngrsp.rng_stat",
FT_UINT8, BASE_DEC, VALS (rng_stat_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_rngrsp_down_freq_over,
{"Downstream Frequency Override (Hz)", "docsis_rngrsp.freq_over",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Downstream Frequency Override", HFILL}
},
{&hf_docsis_rngrsp_upstream_ch_over,
{"Upstream Channel ID Override", "docsis_rngrsp.chid_override",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regreq_sid,
{"Service Identifier", "docsis_regreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regrsp_sid,
{"Service Identifier", "docsis_regrsp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regrsp_response,
{"Response Code", "docsis_regrsp.respnse",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkm_code,
{"BPKM Code", "docsis_bpkm.code",
FT_UINT8, BASE_DEC, VALS (code_field_vals), 0x0,
"BPKM Request Message", HFILL}
},
{&hf_docsis_bpkm_ident,
{"BPKM Identifier", "docsis_bpkm.ident",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr,
{"BPKM Attributes", "docsis_bpkm.attr",
FT_BYTES, BASE_NONE|BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkm_length,
{"BPKM Length", "docsis_bpkm.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_serial_num,
{"Serial Number", "docsis_bpkm.attr.serialnum",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_manf_id,
{"Manufacturer Id", "docsis_bpkm.attr.manfid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_mac_addr,
{"Mac Address", "docsis_bpkm.attr.macaddr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_rsa_pub_key,
{"RSA Public Key", "docsis_bpkm.attr.rsa_pub_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_cm_id,
{"CM Identification", "docsis_bpkm.attr.cmid",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_display_str,
{"Display String", "docsis_bpkm.attr.dispstr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_auth_key,
{"Auth Key", "docsis_bpkm.attr.auth_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_tek,
{"Traffic Encryption Key", "docsis_bpkm.attr.tek",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_key_life,
{"Key Lifetime(s)", "docsis_bpkm.attr.keylife",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_key_seq,
{"Key Sequence Number", "docsis_bpkm.attr.keyseq",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_hmac_digest,
{"HMAC Digest", "docsis_bpkm.attr.hmacdigest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_said,
{"SAID", "docsis_bpkm.attr.said",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Security Association ID", HFILL}
},
{&hf_docsis_bpkmattr_tek_params,
{"TEK Parameters", "docsis_bpkm.attr.tekparams",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_cbc_iv,
{"CBC IV", "docsis_bpkm.attr.cbciv",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Cypher Block Chaining", HFILL}
},
{&hf_docsis_bpkmattr_error_code,
{"Error Code", "docsis_bpkm.attr.errcode",
FT_UINT8, BASE_DEC, VALS (error_code_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_vendor_def,
{"Vendor Defined", "docsis_bpkm.attr.vendordef",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_ca_cert,
{"CA Certificate", "docsis_bpkm.attr.cacert",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_cm_cert,
{"CM Certificate", "docsis_bpkm.attr.cmcert",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_security_cap,
{"Security Capabilities", "docsis_bpkm.attr.seccap",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_crypto_suite,
{"Cryptographic Suite", "docsis_bpkm.attr.cryptosuite",
FT_UINT16, BASE_HEX, VALS(crypto_suite_attr_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_crypto_suite_list,
{"Cryptographic Suite List", "docsis_bpkm.attr.crypto_suite_lst",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_bpi_version,
{"BPI Version", "docsis_bpkm.attr.bpiver",
FT_UINT8, BASE_DEC, VALS (bpi_ver_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_sa_descr,
{"SA Descriptor", "docsis_bpkm.attr.sadescr",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_sa_type,
{"SA Type", "docsis_bpkm.attr.satype",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_sa_query,
{"SA Query", "docsis_bpkm.attr.saquery",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_sa_query_type,
{"SA Query Type", "docsis_bpkm.attr.saquery_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_ip_address,
{"IP Address", "docsis_bpkm.attr.ipaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_download_param,
{"Download Parameters", "docsis_bpkm.attr.dnld_params",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bpkmattr_type,
{"Type", "docsis_bpkm.attr.type",
FT_UINT8, BASE_DEC, VALS(bpkmattr_tlv_vals), 0x0,
"TLV Type", HFILL}
},
{&hf_docsis_bpkmattr_length,
{"Length", "docsis_bpkm.attr.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"TLV Length", HFILL}
},
{&hf_docsis_regack_sid,
{"Service Identifier", "docsis_regack.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regack_response,
{"Response Code", "docsis_regack.respnse",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsarsp_response,
{"Confirmation Code", "docsis_dsarsp.confcode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsaack_response,
{"Confirmation Code", "docsis_dsaack.confcode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dscrsp_response,
{"Confirmation Code", "docsis_dscrsp.confcode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dscack_response,
{"Confirmation Code", "docsis_dscack.confcode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsdreq_rsvd,
{"Reserved", "docsis_dsdreq.rsvd",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsdreq_sfid,
{"Service Flow ID", "docsis_dsdreq.sfid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsdrsp_confcode,
{"Confirmation Code", "docsis_dsdrsp.confcode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dsdrsp_rsvd,
{"Reserved", "docsis_dsdrsp.rsvd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dccreq_type,
{
"Type",
"docsis_dccreq.tlvtype",
FT_UINT8, BASE_DEC, VALS(dcc_tlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_length,
{
"Length",
"docsis_dccreq.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_tran_id ,
{
"Transaction ID",
"docsis_dccreq.tran_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_up_chan_id ,
{
"Up Channel ID",
"docsis_dccreq.up_chan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_ds_params_subtype,
{
"Type",
"docsis_dccreq.ds_tlvtype",
FT_UINT8, BASE_DEC, VALS(ds_param_subtlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_ds_params_length,
{
"Length",
"docsis_dccreq.ds_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_freq ,
{
"Frequency",
"docsis_dccreq.ds_freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_mod_type ,
{
"Modulation Type",
"docsis_dccreq.ds_mod_type",
FT_UINT8, BASE_DEC, VALS (ds_mod_type_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_sym_rate ,
{
"Symbol Rate",
"docsis_dccreq.ds_sym_rate",
FT_UINT8, BASE_DEC, VALS (ds_sym_rate_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_intlv_depth_i ,
{
"Interleaver Depth I Value",
"docsis_dccreq.ds_intlv_depth_i",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_intlv_depth_j ,
{
"Interleaver Depth J Value",
"docsis_dccreq.ds_intlv_depth_j",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_chan_id ,
{
"Downstream Channel ID",
"docsis_dccreq.ds_chan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_sync_sub ,
{
"SYNC Substitution",
"docsis_dccreq.ds_sync_sub",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_ofdm_block_freq ,
{
"OFDM Block Frequency",
"docsis_dccreq.ds_ofdm_block_freq",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &local_units_hz, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_init_tech ,
{
"Initialization Technique",
"docsis_dccreq.init_tech",
FT_UINT8, BASE_DEC, VALS (init_tech_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ucd_sub ,
{
"UCD Substitution",
"docsis_dccreq.ucd_sub",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_said_sub_cur ,
{
"SAID Sub - Current Value",
"docsis_dccreq.said_sub_cur",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_said_sub_new ,
{
"SAID Sub - New Value",
"docsis_dccreq.said_sub_new",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_sf_sub_subtype,
{
"Type",
"docsis_dccreq.sf_tlvtype",
FT_UINT8, BASE_DEC, VALS(sf_sub_subtlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_sf_sub_length,
{
"Length",
"docsis_dccreq.sf_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sfid_cur ,
{
"SF Sub - SFID Current Value",
"docsis_dccreq.sf_sfid_cur",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sfid_new ,
{
"SF Sub - SFID New Value",
"docsis_dccreq.sf_sfid_new",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sid_cur ,
{
"SF Sub - SID Current Value",
"docsis_dccreq.sf_sid_cur",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sid_new ,
{
"SF Sub - SID New Value",
"docsis_dccreq.sf_sid_new",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_unsol_grant_tref ,
{
"SF Sub - Unsolicited Grant Time Reference",
"docsis_dccreq.sf_unsol_grant_tref",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_cmts_mac_addr ,
{
"CMTS Mac Address",
"docsis_dccreq.cmts_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccreq.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_hmac_digest ,
{
"HMAC-DigestNumber",
"docsis_dccreq.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_conf_code ,
{
"Confirmation Code",
"docsis_dccrsp.conf_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_type,
{
"Type",
"docsis_dccrsp.tlvtype",
FT_UINT8, BASE_DEC, VALS(dccrsp_tlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_length,
{
"Length",
"docsis_dccrsp.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_cm_jump_subtype,
{
"Type",
"docsis_dccrsp.cm_jump_tlvtype",
FT_UINT8, BASE_DEC, VALS(cm_jump_subtlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcc_cm_jump_length,
{
"Length",
"docsis_dccrsp.cm_jump_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_cm_jump_time_length ,
{
"Length of Jump",
"docsis_dccrsp.cm_jump_time_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_cm_jump_time_start ,
{
"Start Time of Jump",
"docsis_dccrsp.cm_jump_time_start",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccrsp.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_hmac_digest ,
{
"HMAC-Digest Number",
"docsis_dccrsp.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_type,
{
"Type",
"docsis_dccack.tlvtype",
FT_UINT8, BASE_DEC, VALS(dccack_tlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_length,
{
"Length",
"docsis_dccack.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccack.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_hmac_digest ,
{
"HMAC-DigestNumber",
"docsis_dccack.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_intrngreq_sid,
{"Service Identifier", "docsis_intrngreq.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dcd_config_ch_cnt,
{
"Configuration Change Count",
"docsis_dcd.config_ch_cnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_num_of_frag,
{
"Number of Fragments",
"docsis_dcd.num_of_frag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_frag_sequence_num,
{
"Fragment Sequence Number",
"docsis_dcd.frag_sequence_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_type,
{
"Type",
"docsis_dcd.tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_tlv_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_length,
{
"Length",
"docsis_dcd.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_down_classifier_subtype,
{
"Type",
"docsis_dcd.down_classifier_tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_down_classifier_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_down_classifier_length,
{
"Length",
"docsis_dcd.down_classifier_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_id,
{
"Downstream Classifier Id",
"docsis_dcd.cfr_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_rule_pri,
{
"Downstream Classifier Rule Priority",
"docsis_dcd.cfr_rule_pri",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_subtype,
{
"Type",
"docsis_dcd.cfr_ip_tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_cfr_ip_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_length,
{
"Length",
"docsis_dcd.cfr_ip_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_source_addr,
{
"Downstream Classifier IP Source Address",
"docsis_dcd.cfr_ip_source_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_source_mask,
{
"Downstream Classifier IP Source Mask",
"docsis_dcd.cfr_ip_source_mask",
FT_IPv4, BASE_NETMASK, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_dest_addr,
{
"Downstream Classifier IP Destination Address",
"docsis_dcd.cfr_ip_dest_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_ip_dest_mask,
{
"Downstream Classifier IP Destination Mask",
"docsis_dcd.cfr_ip_dest_mask",
FT_IPv4, BASE_NETMASK, NULL, 0x0,
"Downstream Classifier IP Destination Address",
HFILL
}
},
{&hf_docsis_dcd_cfr_tcpudp_srcport_start,
{
"Downstream Classifier IP TCP/UDP Source Port Start",
"docsis_dcd.cfr_ip_tcpudp_srcport_start",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_tcpudp_srcport_end,
{
"Downstream Classifier IP TCP/UDP Source Port End",
"docsis_dcd.cfr_ip_tcpudp_srcport_end",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_tcpudp_dstport_start,
{
"Downstream Classifier IP TCP/UDP Destination Port Start",
"docsis_dcd.cfr_ip_tcpudp_dstport_start",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfr_tcpudp_dstport_end,
{
"Downstream Classifier IP TCP/UDP Destination Port End",
"docsis_dcd.cfr_ip_tcpudp_dstport_end",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_id,
{
"DSG Rule Id",
"docsis_dcd.rule_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_pri,
{
"DSG Rule Priority",
"docsis_dcd.rule_pri",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_ucid_list,
{
"DSG Rule UCID Range",
"docsis_dcd.rule_ucid_list",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_subtype,
{
"Type",
"docsis_dcd.clid_tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_clid_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_length,
{
"Length",
"docsis_dcd.clid_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_bcast_id,
{
"DSG Rule Client ID Broadcast ID",
"docsis_dcd.clid_bcast_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_known_mac_addr,
{
"DSG Rule Client ID Known MAC Address",
"docsis_dcd.clid_known_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_ca_sys_id,
{
"DSG Rule Client ID CA System ID",
"docsis_dcd.clid_ca_sys_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_clid_app_id,
{
"DSG Rule Client ID Application ID",
"docsis_dcd.clid_app_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_dsg_rule_subtype,
{
"Type",
"docsis_dcd.rule_tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_dsg_rule_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_dsg_rule_length,
{
"Length",
"docsis_dcd.rule_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_tunl_addr,
{
"DSG Rule Tunnel MAC Address",
"docsis_dcd.rule_tunl_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_cfr_id,
{
"DSG Rule Classifier ID",
"docsis_dcd.rule_cfr_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_rule_vendor_spec,
{
"DSG Rule Vendor Specific Parameters",
"docsis_dcd.rule_vendor_spec",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_subtype,
{
"Type",
"docsis_dcd.cfg_tlvtype",
FT_UINT8, BASE_DEC, VALS(dcd_cfg_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_length,
{
"Length",
"docsis_dcd.cfg_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_chan,
{
"DSG Configuration Channel",
"docsis_dcd.cfg_chan",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_tdsg1,
{
"DSG Initialization Timeout (Tdsg1)",
"docsis_dcd.cfg_tdsg1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_tdsg2,
{
"DSG Operational Timeout (Tdsg2)",
"docsis_dcd.cfg_tdsg2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_tdsg3,
{
"DSG Two-Way Retry Timer (Tdsg3)",
"docsis_dcd.cfg_tdsg3",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_tdsg4,
{
"DSG One-Way Retry Timer (Tdsg4)",
"docsis_dcd.cfg_tdsg4",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dcd_cfg_vendor_spec,
{
"DSG Configuration Vendor Specific Parameters",
"docsis_dcd.cfg_vendor_spec",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_mdd_ccc,
{"Configuration Change Count", "docsis_mdd.ccc",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Configuration Change Count", HFILL}
},
{&hf_docsis_mdd_number_of_fragments,
{"Number of Fragments", "docsis_mdd.number_of_fragments",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Number of Fragments", HFILL}
},
{&hf_docsis_mdd_fragment_sequence_number,
{"Fragment Sequence Number", "docsis_mdd.fragment_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Fragment Sequence Number", HFILL}
},
{&hf_docsis_mdd_current_channel_dcid,
{"Current Channel DCID", "docsis_mdd.current_channel_dcid",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Current Channel DCID", HFILL}
},
{&hf_docsis_mdd_ds_active_channel_list_subtype,
{"Type", "docsis_mdd.downstream_active_channel_list_tlvtype",
FT_UINT8, BASE_DEC, VALS(mdd_ds_active_channel_list_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_ds_active_channel_list_length,
{"Length", "docsis_mdd.downstream_active_channel_list_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_channel_id,
{"Channel ID", "docsis_mdd.downstream_active_channel_list_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Downstream Active Channel List Channel ID", HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_frequency,
{"Frequency", "docsis_mdd.downstream_active_channel_list_frequency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Mdd Downstream Active Channel List Frequency", HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_annex,
{"Annex", "docsis_mdd.downstream_active_channel_list_annex",
FT_UINT8, BASE_DEC, VALS(J83_annex_vals), 0xF0,
"Mdd Downstream Active Channel List Annex", HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_modulation_order,
{"Modulation Order", "docsis_mdd.downstream_active_channel_list_modulation_order",
FT_UINT8, BASE_DEC, VALS(modulation_order_vals), 0x0F,
"Mdd Downstream Active Channel List Modulation Order", HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_primary_capable,
{"Primary Capable", "docsis_mdd.downstream_active_channel_list_primary_capable",
FT_UINT8, BASE_DEC, VALS(primary_capable_vals), 0x0,
"Mdd Downstream Active Channel List Primary Capable", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask,
{"CM-STATUS Event Enable Bitmask", "docsis_mdd.cm_status_event_enable_bitmask",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_mdd_timeout,
{"MDD Timeout", "docsis_mdd.downstream_active_channel_list_mdd_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0002,
"Mdd Downstream Active Channel List MDD Timeout", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_qam_fec_lock_failure,
{"QAM/FEC Lock Failure", "docsis_mdd.cm_status_event_enable_bitmask_qam_fec_lock_failure",
FT_UINT16, BASE_DEC, NULL, 0x0004,
"Mdd Downstream Active Channel List QAM/FEC Lock Failure", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_mdd_recovery,
{"MDD Recovery", "docsis_mdd.cm_status_event_enable_bitmask_mdd_recovery",
FT_UINT16, BASE_DEC, NULL, 0x0010,
"CM-STATUS event MDD Recovery", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_qam_fec_lock_recovery,
{"QAM/FEC Lock Recovery", "docsis_mdd.cm_status_event_enable_bitmask_qam_fec_lock_recovery",
FT_UINT16, BASE_DEC, NULL, 0x0020,
"CM-STATUS event QAM/FEC Lock Recovery", HFILL}
},
{&hf_docsis_mdd_downstream_active_channel_list_map_ucd_transport_indicator,
{"MAP and UCD transport indicator", "docsis_mdd.downstream_active_channel_list_map_ucd_transport_indicator",
FT_UINT8, BASE_DEC, VALS(map_ucd_transport_indicator_vals), 0x0,
"Mdd Downstream Active Channel List MAP and UCD Transport Indicator", HFILL}
},
{&hf_docsis_mdd_ofdm_plc_parameters,
{"OFDM PLC Parameters", "docsis_mdd.ofdm_plc_parameters",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_ofdm_plc_parameters_tukey_raised_cosine_window,
{"Tukey raised cosine window", "docsis_mdd.ofdm_plc_parameters_tukey_raised_cosine_window",
FT_UINT8, BASE_DEC, VALS(tukey_raised_cosine_vals), 0x07,
"OFDM PLC Parameters Tukey raised cosine window", HFILL}
},
{&hf_docsis_mdd_ofdm_plc_parameters_cyclic_prefix,
{"Cyclic prefix", "docsis_mdd.ofdm_plc_parameters_cyclic_prefix",
FT_UINT8, BASE_DEC, VALS(cyclic_prefix_vals), 0x38,
"OFDM PLC parameters Cyclic prefix", HFILL}
},
{&hf_docsis_mdd_ofdm_plc_parameters_sub_carrier_spacing,
{"Sub carrier spacing", "docsis_mdd.ofdm_plc_parameters_sub_carrier_spacing",
FT_UINT8, BASE_DEC, VALS(spacing_vals), 0x40,
"OFDM PLC parameters Sub carrier spacing", HFILL}
},
{&hf_docsis_mdd_up_active_channel_list_subtype,
{"Type", "docsis_mdd.up_active_channel_list_tlvtype",
FT_UINT8, BASE_DEC, VALS(mdd_up_active_channel_list_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_up_active_channel_list_length,
{"Length", "docsis_mdd.up_active_channel_list_tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_t4_timeout,
{"T4 timeout", "docsis_mdd.cm_status_event_enable_bitmask_t4_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0040,
"CM-STATUS event T4 timeout", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_t3_retries_exceeded,
{"T3 Retries Exceeded", "docsis_mdd.cm_status_event_enable_bitmask_t3_retries_exceeded",
FT_UINT16, BASE_DEC, NULL, 0x0080,
"CM-STATUS event T3 Retries Exceeded", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_bitmask_successful_ranging_after_t3_retries_exceeded,
{"Successful Ranging after T3 Retries Exceeded", "docsis_mdd.cm_status_event_enable_bitmask_successful_ranging_after_t3_retries_exceeded",
FT_UINT16, BASE_DEC, NULL, 0x0100,
"CM-STATUS event Successful Ranging after T3 Retries Exceeded", HFILL}
},
{&hf_docsis_mdd_mac_domain_downstream_service_group_channel_id,
{"Channel Id", "docsis_mdd.mac_domain_downstream_service_group_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Mac Domain Downstream Service Group Channel Id", HFILL}
},
{&hf_docsis_mdd_ds_service_group_subtype,
{"Type", "docsis_mdd.ds_service_group_type",
FT_UINT8, BASE_DEC, VALS(mdd_ds_service_group_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_ds_service_group_length,
{"Length", "docsis_mdd.ds_service_group_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_mac_domain_downstream_service_group_md_ds_sg_identifier,
{"MD-DS-SG Identifier", "docsis_mdd.mac_domain_downstream_service_group_md_ds_sg_identifier",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Mac Domain Downstream Service Group MD-DS-SG Identifier", HFILL}
},
{&hf_docsis_mdd_type,
{"Type", "docsis_mdd.type",
FT_UINT8, BASE_DEC, VALS(mdd_tlv_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_length,
{"Length", "docsis_mdd.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_downstream_ambiguity_resolution_frequency,
{"Frequency", "docsis_mdd.downstream_ambiguity_resolution_frequency",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Mdd Downstream Ambiguity Resolution frequency", HFILL}
},
{&hf_docsis_mdd_channel_profile_reporting_control_subtype,
{"Type", "docsis_mdd.channel_profile_reporting_control_type",
FT_UINT8, BASE_DEC, VALS(mdd_channel_profile_reporting_control_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_channel_profile_reporting_control_length,
{"Length", "docsis_mdd.channel_profile_reporting_control_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_rpc_center_frequency_spacing,
{"RPC Center Frequency Spacing", "docsis_mdd.rpc_center_frequency_spacing",
FT_UINT8, BASE_DEC, VALS(rpc_center_frequency_spacing_vals), 0x0,
"Mdd RPC Center Frequency Spacing", HFILL}
},
{&hf_docsis_mdd_verbose_rcp_reporting,
{"Verbose RCP reporting", "docsis_mdd.verbose_rpc_reporting",
FT_UINT8, BASE_DEC, VALS(verbose_rpc_reporting_vals), 0x0,
"Mdd Verbose RPC Reporting", HFILL}
},
{&hf_docsis_mdd_ip_init_param_subtype,
{"Type", "docsis_mdd.ip_init_param_type",
FT_UINT8, BASE_DEC, VALS(mdd_ip_init_param_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_ip_init_param_length,
{"Length", "docsis_mdd.ip_init_param_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_ip_provisioning_mode,
{"IP Provisioning Mode", "docsis_mdd.ip_provisioning_mode",
FT_UINT8, BASE_DEC, VALS(ip_provisioning_mode_vals), 0x0,
"Mdd IP Provisioning Mode", HFILL}
},
{&hf_docsis_mdd_pre_registration_dsid,
{"Pre-registration DSID", "docsis_mdd.pre_registration_dsid",
FT_UINT24, BASE_DEC, NULL, 0x0FFFFF,
"Mdd Pre-registration DSID", HFILL}
},
{&hf_docsis_mdd_early_authentication_and_encryption,
{"Early Authentication and Encryption", "docsis_mdd.early_authentication_and_encryption",
FT_UINT8, BASE_DEC, VALS(eae_vals), 0x0,
"Mdd Early Authentication and Encryption", HFILL}
},
{&hf_docsis_mdd_upstream_active_channel_list_upstream_channel_id,
{"Upstream Channel Id", "docsis_mdd.upstream_active_channel_list_upstream_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Upstream Active Channel List Upstream Channel Id", HFILL}
},
{&hf_docsis_mdd_upstream_ambiguity_resolution_channel_list_channel_id,
{"Channel Id", "docsis_mdd.upstream_ambiguity_resolution_channel_list_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mdd Mac Domain Upstream Ambiguity Resolution Channel List Channel Id", HFILL}
},
{&hf_docsis_mdd_upstream_frequency_range,
{"Upstream Frequency Range", "docsis_mdd.upstream_frequency_range",
FT_UINT8, BASE_DEC, VALS(upstream_frequency_range_vals), 0x0,
"Mdd Upstream Frequency Range", HFILL}
},
{&hf_docsis_mdd_symbol_clock_locking_indicator,
{"Symbol Clock Locking Indicator", "docsis_mdd.symbol_clock_locking_indicator",
FT_UINT8, BASE_DEC, VALS(symbol_clock_locking_indicator_vals), 0x0,
"Mdd Symbol Clock Locking Indicator", HFILL}
},
{&hf_docsis_mdd_cm_status_event_control_subtype,
{"Type", "docsis_mdd.cm_status_event_control_type",
FT_UINT8, BASE_DEC, VALS(mdd_cm_status_event_control_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_cm_status_event_control_length,
{"Length", "docsis_mdd.cm_status_event_control_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_event_type,
{"Event Type", "docsis_mdd.event_type",
FT_UINT8, BASE_DEC, VALS(symbol_cm_status_event_vals), 0x0,
"Mdd CM-STATUS Event Type", HFILL}
},
{&hf_docsis_mdd_maximum_event_holdoff_timer,
{"Maximum Event Holdoff Timer (units of 20 ms)", "docsis_mdd.maximum_event_holdoff_timer",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Mdd Maximum Event Holdoff Timer", HFILL}
},
{&hf_docsis_mdd_maximum_number_of_reports_per_event,
{"Maximum Number of Reports per Event", "docsis_mdd.maximum_number_of_reports_per_event",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_unlimited), 0x0,
"Mdd Maximum Number of Reports per Event", HFILL}
},
{&hf_docsis_mdd_upstream_transmit_power_reporting,
{"Upstream Transmit Power Reporting", "docsis_mdd.upstream_transmit_power_reporting",
FT_UINT8, BASE_DEC, VALS(upstream_transmit_power_reporting_vals), 0x0,
"Mdd Upstream Transmit Power Reporting", HFILL}
},
{&hf_docsis_mdd_dsg_da_to_dsid_subtype,
{"Type", "docsis_mdd.dsg_da_to_dsid_type",
FT_UINT8, BASE_DEC, VALS(mdd_cm_dsg_da_to_dsid_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_dsg_da_to_dsid_length,
{"Length", "docsis_mdd.dsg_da_to_dsid_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_dsg_da_to_dsid_association_da,
{"Destination Address", "docsis_mdd.dsg_da_to_dsid_association_da",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Mdd DSG DA to DSID association Destination Address", HFILL}
},
{&hf_docsis_mdd_dsg_da_to_dsid_association_dsid,
{"DSID", "docsis_mdd.dsg_da_to_dsid_association_dsid",
FT_UINT24, BASE_DEC, NULL, 0x0FFFFF,
"Mdd Mdd DSG DA to DSID association DSID", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events,
{"CM-STATUS Event Enable Bitmask for Non-Channel-Specific Events", "docsis_mdd.cm_status_event_enable_non_channel_specific_events",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_sequence_out_of_range,
{"Sequence out of range", "docsis_mdd.cm_status_event_enable_non_channel_specific_events_sequence_out_of_range",
FT_UINT16, BASE_DEC, NULL, 0x0008,
"CM-STATUS event non-channel-event Sequence out of range", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_cm_operating_on_battery_backup,
{"CM operating on battery backup", "docsis_mdd.cm_status_event_enable_non_channel_specific_events_cm_operating_on_battery_backup",
FT_UINT16, BASE_DEC, NULL, 0x0200,
"CM-STATUS event non-channel-event Cm operating on battery backup", HFILL}
},
{&hf_docsis_mdd_cm_status_event_enable_non_channel_specific_events_cm_returned_to_ac_power,
{"Returned to AC power", "docsis_mdd.cm_status_event_enable_non_channel_specific_events_cm_returned_to_ac_power",
FT_UINT16, BASE_DEC, NULL, 0x0400,
"CM-STATUS event non-channel-event Cm returned to AC power", HFILL}
},
{&hf_docsis_mdd_extended_upstream_transmit_power_support,
{ "Extended Upstream Transmit Power Support", "docsis_mdd.extended_upstream_transmit_power_support",
FT_BOOLEAN, BASE_NONE, TFS(&mdd_tfs_on_off), 0x0,
"Mdd Extended Upstream Transmit Power Support", HFILL}
},
{&hf_docsis_bintrngreq_capflags,
{"Capability Flags", "docsis_bintrngreq.capflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_bintrngreq_capflags_frag,
{"Pre-3.0 Fragmentation", "docsis_bintrngreq.capflags.frag",
FT_BOOLEAN, 8, NULL, (1<<7),
"Pre-3.0 DOCSIS fragmentation is supported prior to registration", HFILL }
},
{&hf_docsis_bintrngreq_capflags_encrypt,
{"Early Auth. & Encrypt", "docsis_bintrngreq.capflags.encrypt",
FT_BOOLEAN, 8, NULL, (1<<6),
"Early Authentication and Encryption supported", HFILL }
},
{&hf_docsis_bintrngreq_mddsgid,
{"MD-DS-SG-ID", "docsis_bintrngreq.mddsgid",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
"MAC Domain Downstream Service Group Identifier", HFILL}
},
{&hf_docsis_dbcreq_number_of_fragments,
{"Number of Fragments", "docsis_dbcreq.number_of_fragments",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dbcreq_fragment_sequence_number,
{"Fragment Seq No", "docsis_dbcreq.fragment_sequence_number",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dbcrsp_conf_code,
{"Confirmation Code", "docsis_dbcrsp.conf_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &docsis_conf_code_ext, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_flags,
{"Flags", "docsis_dpv.flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_us_sf,
{"Upstream Service Flow ID", "docsis_dpv.us_sf",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_n,
{"N (Measurement avaraging factor)", "docsis_dpv.n",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_start,
{"Start Reference Point", "docsis_dpv.start",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_end,
{"End Reference Point", "docsis_dpv.end",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_ts_start,
{"Timestamp Start", "docsis_dpv.ts_start",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpv_ts_end,
{"Timestamp End", "docsis_dpv.ts_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_mdd_t,
{"Secondary Channel MDD timeout", "docsis_cmstatus.mdd_timeout", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_qfl_f,
{"QAM/FEC lock failure", "docsis_cmstatus.qam_fec_lock_failure", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_s_o,
{"Sequence out-of-range", "docsis_cmstatus.sequence_out_of_range", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_mdd_r,
{"Secondary Channel MDD Recovery", "docsis_cmstatus.mdd_recovery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_qfl_r,
{"QAM/FEC Lock Recovery", "docsis_cmstatus.qam_fec_lock_recovery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_t4_t,
{"T4 timeout", "docsis_cmstatus.t4_timeout", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_t3_e,
{"T3 retries exceeded", "docsis_cmstatus.t3_retries_exceeded", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_rng_s,
{"Successful ranging after T3 retries exceeded", "docsis_cmstatus.successful_ranging_after_t3_retries_exceeded", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_cm_b,
{"CM operating on battery backup", "docsis_cmstatus.cm_on_battery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_cm_a,
{"CM returned to A/C power", "docsis_cmstatus.cm_on_ac_power", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_descr,
{"Description", "docsis_cmstatus.description",FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_ds_ch_id,
{"Downstream Channel ID", "docsis_cmstatus.ds_chid",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_us_ch_id,
{"Upstream Channel ID", "docsis_cmstatus.us_chid",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_dsid,
{"DSID", "docsis_cmstatus.dsid", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_tlv_data,
{"TLV Data", "docsis_cmstatus.tlv_data", FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_type,
{"Type", "docsis_cmstatus.type",FT_UINT8, BASE_DEC, VALS(cmstatus_tlv_vals), 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_length,
{"Length", "docsis_cmstatus.length",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_mute,
{"Upstream Channel RF Mute", "docsis_cmctrl.mute",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_mute_timeout,
{"RF Mute Timeout Interval", "docsis_cmctrl.mute_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_reinit,
{"CM Reinitialize", "docsis_cmctrl.reinit",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_disable_fwd,
{"Disable Forwarding", "docsis_cmctrl.disable_fwd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_ds_event,
{"Override Downstream Events", "docsis_cmctrl.ds_event",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_us_event,
{"Override Upstream Events", "docsis_cmctrl.us_event",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_tlv_event,
{"Override Non-Channel-Specific Events", "docsis_cmctrl.event",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrlreq_tlv_data,
{"TLV Data", "docsis_cmctrl.tlv_data",
FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrlreq_type,
{"Type", "docsis_cmctrl.tlv_type",
FT_UINT8, BASE_DEC, VALS(cmctrlreq_tlv_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrlreq_length,
{"Length", "docsis_cmctrl.tlv_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrlreq_us_type,
{"Type", "docsis_cmctrl.us_event_type",
FT_UINT8, BASE_DEC, VALS(cmctrlreq_us_tlv_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrlreq_us_length,
{"Length", "docsis_cmctrl.us_event_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_us_event_ch_id,
{"Upstream Channel ID", "docsis_cmctrl.us_event.chid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_us_event_mask,
{"Upstream Status Event Enable Bitmask", "docsis_cmctrl.us_event.mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_ds_type,
{"Type", "docsis_cmctrl.ds_event_type",
FT_UINT8, BASE_DEC, VALS(cmctrlreq_ds_tlv_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_ds_length,
{"Length", "docsis_cmctrl.ds_event_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_ds_event_ch_id,
{"Downstream Channel ID", "docsis_cmctrl.ds_event.chid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_cmctrl_ds_event_mask,
{"Downstream Status Event Enable Bitmask", "docsis_cmctrl.ds_event.mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_regreqmp_sid,
{"Sid", "docsis_regreqmp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Sid", HFILL}
},
{&hf_docsis_regreqmp_number_of_fragments,
{"Number of Fragments", "docsis_regreqmp.number_of_fragments",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Number of Fragments", HFILL}
},
{&hf_docsis_regreqmp_fragment_sequence_number,
{"Fragment Sequence Number", "docsis_regreqmp.fragment_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Req-Mp Fragment Sequence Number", HFILL}
},
{&hf_docsis_regrspmp_sid,
{"Sid", "docsis_regrspmp.sid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Sid", HFILL}
},
{&hf_docsis_regrspmp_response,
{"Response", "docsis_regrspmp.response",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Response", HFILL}
},
{&hf_docsis_regrspmp_number_of_fragments,
{"Number of Fragments", "docsis_regrspmp.number_of_fragments",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Number of Fragments", HFILL}
},
{&hf_docsis_regrspmp_fragment_sequence_number,
{"Fragment Sequence Number", "docsis_regrspmp.fragment_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reg-Rsp-Mp Fragment Sequence Number", HFILL}
},
{&hf_docsis_ocd_tlv_unknown,
{"Unknown TLV", "docsis_ocd.unknown_tlv", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_ccc,
{"Configuration Change Count", "docsis_ocd.ccc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_four_trans_size,
{"Discrete Fourier Transform Size", "docsis_ocd.tlv.four_trans_size", FT_UINT8, BASE_DEC, VALS (docsis_ocd_four_trans_size), 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_cycl_pref,
{"Cylic Prefix", "docsis_ocd.tlv.cyc_pref", FT_UINT8, BASE_DEC, VALS (docsis_ocd_cyc_prefix), 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_roll_off,
{"Roll Off", "docsis_ocd.tlv.roll_off", FT_UINT8, BASE_DEC, VALS (docsis_ocd_roll_off), 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_ofdm_spec_loc,
{"OFDM Spectrum Location", "docsis_ocd.tlv.ofdm_spec_loc", FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &local_units_hz, 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_time_int_depth,
{"Time Interleaving Depth", "docsis_ocd.tlv.time_int_depth", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_prim_cap_ind,
{"Primary Capable Indicator", "docsis_ocd.tlv.prim_cap_ind", FT_UINT8, BASE_DEC, VALS(docsis_ocd_prim_cap_ind_str), 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_subc_assign_type,
{"Assignment type", "docsis_ocd.tlv.subc_assign.type", FT_UINT8, BASE_DEC, VALS(docsis_ocd_subc_assign_type_str), 0xC0, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_subc_assign_value,
{"Assignment value", "docsis_ocd.tlv.subc_assign.value", FT_UINT8, BASE_DEC, VALS(docsis_ocd_subc_assign_value_str), 0x20, NULL, HFILL}
},
{&hf_docsis_ocd_subc_assign_subc_type,
{"Subcarrier Type", "docsis_ocd.tlv.subc_assign.subc_type", FT_UINT8, BASE_DEC, VALS(docsis_ocd_subc_assign_subc_type_str), 0x1F, NULL, HFILL}
},
{&hf_docsis_ocd_subc_assign_range,
{"Subcarrier index range", "docsis_ocd.tlv.subc_assign.range", FT_UINT32, BASE_CUSTOM, CF_FUNC(subc_assign_range), 0x00, NULL, HFILL}
},
{&hf_docsis_ocd_subc_assign_index,
{"Subcarrier index", "docsis_ocd.tlv.subc_assign.index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{&hf_docsis_ocd_tlv_data,
{"TLV Data", "docsis_ocd.tlv_data", FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_type,
{"Type", "docsis_ocd.type",FT_UINT8, BASE_DEC, VALS(ocd_tlv_vals), 0x0, NULL, HFILL}
},
{&hf_docsis_ocd_length,
{"Length", "docsis_ocd.length",FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_unknown,
{"Unknown TLV", "docsis_dpd.unknown_tlv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_dpd_prof_id,
{"Profile Identifier", "docsis_dpd.prof_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_dpd_ccc,
{"Configuration Change Count", "docsis_dpd.ccc", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_type,
{"Subcarrier Assignment Type", "docsis_dpd.tlv.subc_assign.type", FT_UINT8, BASE_DEC, VALS(docsis_dpd_subc_assign_type_str), 0xC0, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_value,
{"Subcarrier Assignment Value", "docsis_dpd.tlv.subc_assign.value", FT_UINT8, BASE_DEC, VALS(docsis_dpd_subc_assign_value_str), 0x20, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_reserved,
{"reserved", "docsis_dpd.tlv.subc_assign.reserved", FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_modulation,
{"Subcarrier Assignment Modulation", "docsis_dpd.tlv.subc_assign.modulation", FT_UINT8, BASE_DEC, VALS(docsis_dpd_subc_assign_modulation_str), 0x0F, NULL, HFILL}
},
{&hf_docsis_dpd_subc_assign_range,
{"Subcarrier index range", "docsis_dpd.tlv.subc_assign.range", FT_UINT32, BASE_CUSTOM, CF_FUNC(subc_assign_range), 0x00, NULL, HFILL}
},
{&hf_docsis_dpd_subc_assign_index,
{"Subcarrier index", "docsis_dpd.tlv.subc_assign.index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_vector_oddness,
{"Odd or even", "docsis_dpd.tlv.subc_assign_vect.oddness", FT_UINT8, BASE_DEC, VALS(docsis_dpd_tlv_subc_assign_vector_oddness_str), 0x80, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_vector_reserved,
{"Reserved", "docsis_dpd.tlv.subc_assign_vect.reserved", FT_UINT8, BASE_DEC, NULL, 0x60, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_vector_subc_start,
{"Subcarrier start", "docsis_dpd.tlv.subc_assign_vect.subc_start", FT_UINT16, BASE_DEC, NULL, 0x1FFF, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_vector_modulation_odd,
{"Modulation", "docsis_dpd.tlv.subc_assign_vect.modulation", FT_UINT8, BASE_DEC, VALS(docsis_dpd_tlv_subc_assign_vector_modulation_str), 0xF0, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_subc_assign_vector_modulation_even,
{"Modulation", "docsis_dpd.tlv.subc_assign_vect.modulation", FT_UINT8, BASE_DEC, VALS(docsis_dpd_tlv_subc_assign_vector_modulation_str), 0x0F, NULL, HFILL}
},
{&hf_docsis_dpd_tlv_data,
{"TLV Data", "docsis_dpd.tlv_data", FT_BYTES, BASE_NO_DISPLAY_VALUE, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_dpd_type,
{"Type", "docsis_dpd.type",FT_UINT8, BASE_DEC, VALS(dpd_tlv_vals), 0x0, NULL, HFILL}
},
{&hf_docsis_dpd_length,
{"Length", "docsis_dpd.length",FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_mgt_upstream_chid,
{"Upstream Channel ID", "docsis_mgmt.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_down_chid,
{"Downstream Channel ID", "docsis_ucd.downchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Management Message", HFILL}
},
{&hf_docsis_mgt_tranid,
{"Transaction Id", "docsis_mgmt.tranid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_dst_addr,
{"Destination Address", "docsis_mgmt.dst",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_src_addr,
{"Source Address", "docsis_mgmt.src",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_msg_len,
{"Message Length - DSAP to End (Bytes)", "docsis_mgmt.msglen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_dsap,
{"DSAP", "docsis_mgmt.dsap",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Destination SAP", HFILL}
},
{&hf_docsis_mgt_ssap,
{"SSAP", "docsis_mgmt.ssap",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Source SAP", HFILL}
},
{&hf_docsis_mgt_control,
{"Control", "docsis_mgmt.control",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_version,
{"Version", "docsis_mgmt.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_type,
{"Type", "docsis_mgmt.type",
FT_UINT8, BASE_DEC, VALS (mgmt_type_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_rsvd,
{"Reserved", "docsis_mgmt.rsvd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_sync,
&ett_docsis_ucd,
&ett_docsis_tlv,
&ett_docsis_burst_tlv,
&ett_docsis_map,
&ett_docsis_map_ie,
&ett_docsis_rngreq,
&ett_docsis_rngrsp,
&ett_docsis_rngrsptlv,
&ett_docsis_regreq,
&ett_docsis_regrsp,
&ett_docsis_uccreq,
&ett_docsis_uccrsp,
&ett_docsis_bpkmreq,
&ett_docsis_bpkmrsp,
&ett_docsis_bpkmattr,
&ett_docsis_bpkmattr_cmid,
&ett_docsis_bpkmattr_scap,
&ett_docsis_bpkmattr_tekp,
&ett_docsis_bpkmattr_sadsc,
&ett_docsis_bpkmattr_saqry,
&ett_docsis_bpkmattr_dnld,
&ett_docsis_bpkmattrtlv,
&ett_docsis_regack,
&ett_docsis_dsareq,
&ett_docsis_dsarsp,
&ett_docsis_dsaack,
&ett_docsis_dscreq,
&ett_docsis_dscrsp,
&ett_docsis_dscack,
&ett_docsis_dsdreq,
&ett_docsis_dsdrsp,
&ett_docsis_dccreq,
&ett_docsis_dccreq_sf_sub,
&ett_docsis_dccreq_ds_params,
&ett_docsis_dccreq_tlv,
&ett_docsis_dccrsp,
&ett_docsis_dccrsp_cm_jump_time,
&ett_docsis_dccrsp_tlv,
&ett_docsis_dccack,
&ett_docsis_dccack_tlv,
&ett_docsis_intrngreq,
&ett_docsis_dcd,
&ett_docsis_dcd_cfr,
&ett_docsis_dcd_cfr_ip,
&ett_docsis_dcd_rule,
&ett_docsis_dcd_clid,
&ett_docsis_dcd_cfg,
&ett_docsis_dcd_tlv,
&ett_docsis_mdd,
&ett_tlv,
&ett_sub_tlv,
&ett_docsis_mdd_ds_active_channel_list,
&ett_docsis_mdd_ds_service_group,
&ett_docsis_mdd_channel_profile_reporting_control,
&ett_docsis_mdd_ip_init_param,
&ett_docsis_mdd_up_active_channel_list,
&ett_docsis_mdd_cm_status_event_control,
&ett_docsis_mdd_dsg_da_to_dsid,
&ett_docsis_bintrngreq,
&ett_docsis_dbcreq,
&ett_docsis_dbcrsp,
&ett_docsis_dbcack,
&ett_docsis_dpvreq,
&ett_docsis_dpvrsp,
&ett_docsis_cmstatus,
&ett_docsis_cmstatus_tlv,
&ett_docsis_cmstatus_tlvtlv,
&ett_docsis_cmctrlreq,
&ett_docsis_cmctrlreq_tlv,
&ett_docsis_cmctrlreq_tlvtlv,
&ett_docsis_cmctrl_tlv_us_event,
&ett_docsis_cmctrl_tlv_ds_event,
&ett_docsis_cmctrlrsp,
&ett_docsis_regreqmp,
&ett_docsis_regrspmp,
&ett_docsis_ocd,
&ett_docsis_ocd_tlv,
&ett_docsis_ocd_tlvtlv,
&ett_docsis_dpd,
&ett_docsis_dpd_tlv,
&ett_docsis_dpd_tlvtlv,
&ett_docsis_dpd_tlv_subcarrier_assignment,
&ett_docsis_dpd_tlv_subcarrier_assignment_vector,
&ett_docsis_mgmt,
&ett_mgmt_pay,
};
static ei_register_info ei[] = {
{&ei_docsis_mgmt_tlvlen_bad, {"docsis_mgmt.tlvlenbad", PI_MALFORMED, PI_ERROR, "Bad TLV length", EXPFILL}},
{&ei_docsis_mgmt_tlvtype_unknown, { "docsis_mgmt.tlvtypeunknown", PI_PROTOCOL, PI_WARN, "Unknown TLV type", EXPFILL}},
};
expert_module_t* expert_docsis_mgmt;
proto_docsis_mgmt = proto_register_protocol ("DOCSIS Mac Management", "DOCSIS MAC MGMT", "docsis_mgmt");
proto_register_field_array (proto_docsis_mgmt, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_docsis_mgmt = expert_register_protocol(proto_docsis_mgmt);
expert_register_field_array(expert_docsis_mgmt, ei, array_length(ei));
docsis_mgmt_dissector_table = register_dissector_table ("docsis_mgmt",
"DOCSIS Mac Management", proto_docsis_mgmt,
FT_UINT8, BASE_DEC);
proto_docsis_sync = proto_register_protocol_in_name_only("DOCSIS Synchronisation Message", "SYNC Message", "docsis_sync", proto_docsis_mgmt, FT_BYTES);
proto_docsis_ucd = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Descriptor", "DOCSIS UCD", "docsis_ucd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_map = proto_register_protocol_in_name_only("DOCSIS Upstream Bandwidth Allocation", "DOCSIS MAP", "docsis_map", proto_docsis_mgmt, FT_BYTES);
proto_docsis_rngreq = proto_register_protocol_in_name_only("DOCSIS Range Request Message", "DOCSIS RNG-REQ", "docsis_rngreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_rngrsp = proto_register_protocol_in_name_only("DOCSIS Ranging Response", "DOCSIS RNG-RSP", "docsis_rngrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_regreq = proto_register_protocol_in_name_only("DOCSIS Registration Requests", "DOCSIS REG-REQ", "docsis_regreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_regrsp = proto_register_protocol_in_name_only("DOCSIS Registration Responses", "DOCSIS REG-RSP", "docsis_regrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_uccreq = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Change Request", "DOCSIS UCC-REQ", "docsis_uccreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_uccrsp = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Change Response", "DOCSIS UCC-RSP", "docsis_uccrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_bpkmreq = proto_register_protocol_in_name_only("DOCSIS Baseline Privacy Key Management Request", "DOCSIS BPKM-REQ", "docsis_bpkm.req", proto_docsis_mgmt, FT_BYTES);
proto_docsis_bpkmrsp = proto_register_protocol_in_name_only("DOCSIS Baseline Privacy Key Management Response", "DOCSIS BPKM-RSP", "docsis_bpkm.rsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_regack = proto_register_protocol_in_name_only("DOCSIS Registration Acknowledge", "DOCSIS REG-ACK", "docsis_regack", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dsareq = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Addition Request", "DOCSIS DSA-REQ", "docsis_dsareq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dsarsp = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Addition Response", "DOCSIS DSA-RSP", "docsis_dsarsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dsaack = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Addition Acknowledge", "DOCSIS DSA-ACK", "docsis_dsaack", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dscreq = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Change Request", "DOCSIS DSC-REQ", "docsis_dscreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dscrsp = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Change Response", "DOCSIS DSC-RSP", "docsis_dscrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dscack = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Change Acknowledgement", "DOCSIS DSC-ACK", "docsis_dscack", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dsdreq = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Delete Request", "DOCSIS DSD-REQ", "docsis_dsdreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dsdrsp = proto_register_protocol_in_name_only("DOCSIS Dynamic Service Delete Response", "DOCSIS DSD-RSP", "docsis_dsdrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dccreq = proto_register_protocol_in_name_only("DOCSIS Downstream Channel Change Request", "DOCSIS DCC-REQ", "docsis_dccreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dccrsp = proto_register_protocol_in_name_only("DOCSIS Downstream Channel Change Response", "DOCSIS DCC-RSP", "docsis_dccrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dccack = proto_register_protocol_in_name_only("DOCSIS Downstream Channel Change Acknowledge", "DOCSIS DCC-ACK", "docsis_dccack", proto_docsis_mgmt, FT_BYTES);
proto_docsis_type29ucd = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Descriptor Type 29", "DOCSIS type29ucd", "docsis_type29ucd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_intrngreq = proto_register_protocol_in_name_only("DOCSIS Initial Ranging Message", "DOCSIS INT-RNG-REQ", "docsis_intrngreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dcd = proto_register_protocol_in_name_only("DOCSIS Downstream Channel Descriptor", "DOCSIS DCD", "docsis_dcd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_mdd = proto_register_protocol_in_name_only("DOCSIS Mac Domain Description", "DOCSIS Mdd", "docsis_mdd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_bintrngreq = proto_register_protocol_in_name_only("DOCSIS Bonded Initial Ranging Message", "DOCSIS B-INT-RNG-REQ", "docsis_bintrngreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_type35ucd = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Descriptor Type 35", "DOCSIS type35ucd", "docsis_type35ucd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dbcreq = proto_register_protocol_in_name_only("DOCSIS Dynamic Bonding Change Request", "DOCSIS DBC-REQ", "docsis_dbcreq", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dbcrsp = proto_register_protocol_in_name_only("DOCSIS Dynamic Bonding Change Response", "DOCSIS DBC-RSP", "docsis_dbcrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dbcack = proto_register_protocol_in_name_only("DOCSIS Dynamic Bonding Change Acknowledge", "DOCSIS DBC-ACK", "docsis_dbcack", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dpvreq = proto_register_protocol_in_name_only("DOCSIS Path Verify Request", "DOCSIS DPV-REQ", "docsis_dpv.req", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dpvrsp = proto_register_protocol_in_name_only("DOCSIS Path Verify Response", "DOCSIS DPV-RSP", "docsis_dpv.rsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_cmstatus = proto_register_protocol_in_name_only("DOCSIS CM-STATUS Report", "DOCSIS CM-STATUS", "docsis_cmstatus", proto_docsis_mgmt, FT_BYTES);
proto_docsis_cmctrlreq = proto_register_protocol_in_name_only("DOCSIS CM Control Request", "DOCSIS CM-CTRL-REQ", "docsis_cmctrl.req", proto_docsis_mgmt, FT_BYTES);
proto_docsis_cmctrlrsp = proto_register_protocol_in_name_only("DOCSIS CM Control Response", "DOCSIS CM-CTRL-RSP", "docsis_cmctrlrsp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_regreqmp = proto_register_protocol_in_name_only("DOCSIS Registration Request Multipart", "DOCSIS Reg-Req-Mp", "docsis_regreqmp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_regrspmp = proto_register_protocol_in_name_only("DOCSIS Registration Response Multipart", "DOCSIS Reg-Rsp-Mp", "docsis_regrspmp", proto_docsis_mgmt, FT_BYTES);
proto_docsis_ocd = proto_register_protocol_in_name_only("DOCSIS OFDM Channel Descriptor", "DOCSIS OCD", "docsis_ocd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_dpd = proto_register_protocol_in_name_only("DOCSIS Downstream Profile Descriptor", "DOCSIS DPD", "docsis_dpd", proto_docsis_mgmt, FT_BYTES);
proto_docsis_type51ucd = proto_register_protocol_in_name_only("DOCSIS Upstream Channel Descriptor Type 51", "DOCSIS type51ucd", "docsis_type51ucd", proto_docsis_mgmt, FT_BYTES);
register_dissector ("docsis_mgmt", dissect_macmgmt, proto_docsis_mgmt);
}
void
proto_reg_handoff_docsis_mgmt (void)
{
dissector_add_uint ("docsis_mgmt", MGT_SYNC, create_dissector_handle( dissect_sync, proto_docsis_sync ));
dissector_add_uint ("docsis_mgmt", MGT_UCD, create_dissector_handle( dissect_ucd, proto_docsis_ucd ));
dissector_add_uint ("docsis_mgmt", MGT_MAP, create_dissector_handle( dissect_map, proto_docsis_map ));
dissector_add_uint ("docsis_mgmt", MGT_RNG_REQ, create_dissector_handle( dissect_rngreq, proto_docsis_rngreq ));
dissector_add_uint ("docsis_mgmt", MGT_RNG_RSP, create_dissector_handle( dissect_rngrsp, proto_docsis_rngrsp ));
dissector_add_uint ("docsis_mgmt", MGT_REG_REQ, create_dissector_handle( dissect_regreq, proto_docsis_regreq ));
dissector_add_uint ("docsis_mgmt", MGT_REG_RSP, create_dissector_handle( dissect_regrsp, proto_docsis_regrsp ));
dissector_add_uint ("docsis_mgmt", MGT_UCC_REQ, create_dissector_handle( dissect_uccreq, proto_docsis_uccreq ));
dissector_add_uint ("docsis_mgmt", MGT_UCC_RSP, create_dissector_handle( dissect_uccrsp, proto_docsis_uccrsp ));
dissector_add_uint ("docsis_mgmt", MGT_BPKM_REQ, create_dissector_handle( dissect_bpkmreq, proto_docsis_bpkmreq ));
dissector_add_uint ("docsis_mgmt", MGT_BPKM_RSP, create_dissector_handle( dissect_bpkmrsp, proto_docsis_bpkmrsp ));
dissector_add_uint ("docsis_mgmt", MGT_REG_ACK, create_dissector_handle( dissect_regack, proto_docsis_regack ));
dissector_add_uint ("docsis_mgmt", MGT_DSA_REQ, create_dissector_handle( dissect_dsareq, proto_docsis_dsareq ));
dissector_add_uint ("docsis_mgmt", MGT_DSA_RSP, create_dissector_handle( dissect_dsarsp, proto_docsis_dsarsp ));
dissector_add_uint ("docsis_mgmt", MGT_DSA_ACK, create_dissector_handle( dissect_dsaack, proto_docsis_dsaack ));
dissector_add_uint ("docsis_mgmt", MGT_DSC_REQ, create_dissector_handle( dissect_dscreq, proto_docsis_dscreq ));
dissector_add_uint ("docsis_mgmt", MGT_DSC_RSP, create_dissector_handle( dissect_dscrsp, proto_docsis_dscrsp ));
dissector_add_uint ("docsis_mgmt", MGT_DSC_ACK, create_dissector_handle( dissect_dscack, proto_docsis_dscack ));
dissector_add_uint ("docsis_mgmt", MGT_DSD_REQ, create_dissector_handle( dissect_dsdreq, proto_docsis_dsdreq ));
dissector_add_uint ("docsis_mgmt", MGT_DSD_RSP, create_dissector_handle( dissect_dsdrsp, proto_docsis_dsdrsp ));
dissector_add_uint ("docsis_mgmt", MGT_DCC_REQ, create_dissector_handle( dissect_dccreq, proto_docsis_dccreq ));
dissector_add_uint ("docsis_mgmt", MGT_DCC_RSP, create_dissector_handle( dissect_dccrsp, proto_docsis_dccrsp ));
dissector_add_uint ("docsis_mgmt", MGT_DCC_ACK, create_dissector_handle( dissect_dccack, proto_docsis_dccack ));
dissector_add_uint ("docsis_mgmt", MGT_TYPE29UCD, create_dissector_handle( dissect_type29ucd, proto_docsis_type29ucd ));
dissector_add_uint ("docsis_mgmt", MGT_INIT_RNG_REQ, create_dissector_handle( dissect_intrngreq, proto_docsis_intrngreq ));
dissector_add_uint ("docsis_mgmt", MGT_DS_CH_DESC, create_dissector_handle( dissect_dcd, proto_docsis_dcd ));
dissector_add_uint ("docsis_mgmt", MGT_MDD, create_dissector_handle( dissect_mdd, proto_docsis_mdd ));
dissector_add_uint ("docsis_mgmt", MGT_B_INIT_RNG_REQ, create_dissector_handle( dissect_bintrngreq, proto_docsis_bintrngreq ));
dissector_add_uint ("docsis_mgmt", MGT_TYPE35UCD, create_dissector_handle( dissect_type35ucd, proto_docsis_type35ucd ));
dissector_add_uint ("docsis_mgmt", MGT_DBC_REQ, create_dissector_handle( dissect_dbcreq, proto_docsis_dbcreq ));
dissector_add_uint ("docsis_mgmt", MGT_DBC_RSP, create_dissector_handle( dissect_dbcrsp, proto_docsis_dbcrsp ));
dissector_add_uint ("docsis_mgmt", MGT_DBC_ACK, create_dissector_handle( dissect_dbcack, proto_docsis_dbcack ));
dissector_add_uint ("docsis_mgmt", MGT_DPV_REQ, create_dissector_handle( dissect_dpvreq, proto_docsis_dpvreq ));
dissector_add_uint ("docsis_mgmt", MGT_DPV_RSP, create_dissector_handle( dissect_dpvrsp, proto_docsis_dpvrsp ));
dissector_add_uint ("docsis_mgmt", MGT_CM_STATUS, create_dissector_handle( dissect_cmstatus, proto_docsis_cmstatus ));
dissector_add_uint ("docsis_mgmt", MGT_CM_CTRL_REQ, create_dissector_handle( dissect_cmctrlreq, proto_docsis_cmctrlreq ));
dissector_add_uint ("docsis_mgmt", MGT_CM_CTRL_RSP, create_dissector_handle( dissect_cmctrlrsp, proto_docsis_cmctrlrsp ));
dissector_add_uint ("docsis_mgmt", MGT_REG_REQ_MP, create_dissector_handle( dissect_regreqmp, proto_docsis_regreqmp ));
dissector_add_uint ("docsis_mgmt", MGT_REG_RSP_MP, create_dissector_handle( dissect_regrspmp, proto_docsis_regrspmp ));
dissector_add_uint ("docsis_mgmt", MGT_OCD, create_dissector_handle( dissect_ocd, proto_docsis_ocd ));
dissector_add_uint ("docsis_mgmt", MGT_DPD, create_dissector_handle( dissect_dpd, proto_docsis_dpd ));
dissector_add_uint ("docsis_mgmt", MGT_TYPE51UCD, create_dissector_handle( dissect_type51ucd, proto_docsis_type51ucd ));
docsis_tlv_handle = find_dissector ("docsis_tlv");
}
