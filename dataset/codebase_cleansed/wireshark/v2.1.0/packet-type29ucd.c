static int
dissect_type29ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos, endtlvpos;
guint8 type, length;
guint8 tlvlen, tlvtype;
proto_tree *type29ucd_burst_tree;
proto_item *type29ucd_burst_item;
proto_tree *type29ucd_tree;
proto_item *type29ucd_item;
proto_tree *type29tlv_tree;
proto_item *type29tlv_item;
guint16 len;
guint8 upchid, symrate;
len = tvb_reported_length(tvb);
upchid = tvb_get_guint8 (tvb, 0);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Type 29 UCD Message: Channel ID = %u (U%u)", upchid,
upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"Type 29 UCD Message: Channel ID = %u (Telephony Return)",
upchid);
if (tree)
{
type29ucd_item =
proto_tree_add_protocol_format (tree, proto_docsis_type29ucd, tvb, 0,
tvb_captured_length(tvb),
"UCD Message (Type 29)");
type29ucd_tree = proto_item_add_subtree (type29ucd_item, ett_docsis_type29ucd);
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_upstream_chid, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_config_ch_cnt, tvb, 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_mini_slot_size, tvb, 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_down_chid, tvb, 3, 1,
ENC_BIG_ENDIAN);
pos = 4;
while (pos < len)
{
type = tvb_get_guint8 (tvb, pos);
type29tlv_tree = proto_tree_add_subtree(type29ucd_tree, tvb, pos, -1,
ett_docsis_type29tlv, &type29tlv_item,
val_to_str(type, channel_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (type29tlv_tree, hf_docsis_type29ucd_type,
tvb, pos, 1, type);
pos++;
length = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (type29tlv_tree, hf_docsis_type29ucd_length,
tvb, pos, 1, length);
pos++;
proto_item_set_len(type29tlv_item, length + 2);
switch (type)
{
case type29ucd_SYMBOL_RATE:
if (length == 1)
{
symrate = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (type29tlv_tree, hf_docsis_type29ucd_symbol_rate,
tvb, pos, length, symrate * 160);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_FREQUENCY:
if (length == 4)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_frequency, tvb,
pos, length, ENC_BIG_ENDIAN);
pos = pos + length;
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_PREAMBLE:
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_preamble_pat, tvb,
pos, length, ENC_NA);
pos = pos + length;
break;
case type29ucd_EXT_PREAMBLE:
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_ext_preamble, tvb,
pos, length, ENC_NA);
pos = pos + length;
break;
case type29ucd_SCDMA_MODE_ENABLE:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_mode_enable,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_SPREADING_INTERVAL:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_spreading_interval,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_CODES_PER_MINI_SLOT:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_codes_per_mini_slot,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_ACTIVE_CODES:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_active_codes,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_CODE_HOPPING_SEED:
if (length == 2)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_code_hopping_seed,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_US_RATIO_NUM:
if (length == 2)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_us_ratio_num,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_US_RATIO_DENOM:
if (length == 2)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_us_ratio_denom,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_SCDMA_TIMESTAMP_SNAPSHOT:
if (length == 9)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_scdma_timestamp_snapshot,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_MAINTAIN_POWER_SPECTRAL_DENSITY:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_maintain_power_spectral_density,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_RANGING_REQUIRED:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_ranging_required,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_MAX_SCHEDULED_CODES:
if (length == 1)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_max_scheduled_codes,
tvb, pos, length, ENC_NA);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_RANGING_HOLD_OFF_PRIORITY_FIELD:
if (length == 4)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_cm, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_erouter, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_emta, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_estb, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_rsvd, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_rnghoff_id_ext, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_RANGING_CHANNEL_CLASS_ID:
if (length == 4)
{
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_cm, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_erouter, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_emta, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_estb, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_rsvd, tvb,
pos, length, ENC_BIG_ENDIAN);
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_chan_class_id_id_ext, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29tlv_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
pos = pos + length;
break;
case type29ucd_BURST_DESCR5:
proto_tree_add_item (type29tlv_tree, hf_docsis_type29ucd_iuc, tvb,
pos++, 1, ENC_BIG_ENDIAN);
endtlvpos = pos + length - 1;
while (pos < endtlvpos)
{
type29ucd_burst_tree = proto_tree_add_subtree (type29tlv_tree, tvb, pos, -1,
ett_docsis_type29_burst_tlv, &type29ucd_burst_item,
val_to_str(type, burst_tlv_vals,
"Unknown TLV (%u)"));
tlvtype = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (type29ucd_burst_tree, hf_docsis_type29ucd_burst_type, tvb, pos++, 1, tlvtype);
tlvlen = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (type29ucd_burst_tree, hf_docsis_type29ucd_burst_length, tvb, pos++, 1, tlvlen);
proto_item_set_len(type29ucd_burst_item, tlvlen + 2);
switch (tlvtype)
{
case type29ucd_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_mod_type, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_diff_encoding,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_preamble_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_preamble_val_off,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_fec, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_fec_codeword,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_scrambler_seed,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_max_burst, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_guard_time,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_last_cw_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_burst_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_RS_INT_DEPTH:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_rs_int_depth,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_RS_INT_BLOCK:
if (tlvlen == 2)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_rs_int_block,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_PREAMBLE_TYPE:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_preamble_type,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_SCMDA_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_scdma_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_SCDMA_CODES_PER_SUBFRAME:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_scdma_codes_per_subframe,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_SCDMA_FRAMER_INT_STEP_SIZE:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_scdma_framer_int_step_size,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
case type29ucd_TCM_ENABLED:
if (tlvlen == 1)
{
proto_tree_add_item (type29ucd_burst_tree,
hf_docsis_tcm_enabled,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, type29ucd_burst_item, &ei_docsis_type29ucd_tlvlen_bad, "Wrong TLV length: %u", length);
}
break;
}
pos = pos + tlvlen;
}
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_docsis_type29ucd (void)
{
static hf_register_info hf[] = {
{&hf_docsis_type29ucd_upstream_chid,
{"Upstream Channel ID", "docsis_type29ucd.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_config_ch_cnt,
{"Config Change Count", "docsis_type29ucd.confcngcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Configuration Change Count", HFILL}
},
{&hf_docsis_type29ucd_mini_slot_size,
{"Mini Slot Size (6.25us TimeTicks)", "docsis_type29ucd.mslotsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_down_chid,
{"Downstream Channel ID", "docsis_type29ucd.downchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Management Message", HFILL}
},
{&hf_docsis_type29ucd_type,
{"Type", "docsis_type29ucd.type",
FT_UINT8, BASE_DEC, VALS(channel_tlv_vals), 0x0,
"Channel TLV type", HFILL}
},
{&hf_docsis_type29ucd_length,
{"Length", "docsis_type29ucd.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Channel TLV length", HFILL}
},
{&hf_docsis_type29ucd_burst_type,
{"Type", "docsis_type29ucd.burst.tlvtype",
FT_UINT8, BASE_DEC, VALS(channel_tlv_vals), 0x0,
"Burst TLV type", HFILL}
},
{&hf_docsis_type29ucd_burst_length,
{"Length", "docsis_type29ucd.burst.tlvlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Burst TLV length", HFILL}
},
{&hf_docsis_type29ucd_symbol_rate,
{"Symbol Rate (ksym/sec)", "docsis_type29ucd.symrate",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Symbol Rate", HFILL}
},
{&hf_docsis_type29ucd_frequency,
{"Frequency (Hz)", "docsis_type29ucd.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Upstream Center Frequency", HFILL}
},
{&hf_docsis_type29ucd_preamble_pat,
{"Preamble Pattern", "docsis_type29ucd.preamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Preamble Superstring", HFILL}
},
{&hf_docsis_type29ucd_iuc,
{"Interval Usage Code", "docsis_type29ucd.iuc",
FT_UINT8, BASE_DEC, VALS (iuc_vals2), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_mod_type,
{"Modulation Type", "docsis_type29ucd.burst.modtype",
FT_UINT8, BASE_DEC, VALS (mod_vals2), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_diff_encoding,
{"Differential Encoding", "docsis_type29ucd.burst.diffenc",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_preamble_len,
{"Preamble Length (Bits)", "docsis_type29ucd.burst.preamble_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_preamble_val_off,
{"Preamble Offset (Bits)", "docsis_type29ucd.burst.preamble_off",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_fec,
{"FEC (T)", "docsis_type29ucd.burst.fec",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC (T) Codeword Parity Bits = 2^T", HFILL}
},
{&hf_docsis_burst_fec_codeword,
{"FEC Codeword Info bytes (k)", "docsis_type29ucd.burst.fec_codeword",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_scrambler_seed,
{"Scrambler Seed", "docsis_type29ucd.burst.scrambler_seed",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Burst Descriptor", HFILL}
},
{&hf_docsis_burst_max_burst,
{"Max Burst Size (Minislots)", "docsis_type29ucd.burst.maxburst",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_guard_time,
{"Guard Time Size (Symbol Times)", "docsis_type29ucd.burst.guardtime",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Guard Time Size", HFILL}
},
{&hf_docsis_burst_last_cw_len,
{"Last Codeword Length", "docsis_type29ucd.burst.last_cw_len",
FT_UINT8, BASE_DEC, VALS (last_cw_len_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_scrambler_onoff,
{"Scrambler On/Off", "docsis_type29ucd.burst.scrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_ext_preamble,
{"Extended Preamble Pattern", "docsis_type29ucd.extpreamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_mode_enable,
{"SCDMA Mode Enable", "docsis_type29ucd.scdmaenable",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_spreading_interval,
{"SCDMA Spreading Interval", "docsis_type29ucd.scdmaspreadinginterval",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_codes_per_mini_slot,
{"SCDMA Codes per mini slot", "docsis_type29ucd.scdmacodesperminislot",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_active_codes,
{"SCDMA Active Codes", "docsis_type29ucd.scdmaactivecodes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_code_hopping_seed,
{"SCDMA Code Hopping Seed", "docsis_type29ucd.scdmacodehoppingseed",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_us_ratio_num,
{"SCDMA US Ratio Numerator", "docsis_type29ucd.scdmausrationum",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_us_ratio_denom,
{"SCDMA US Ratio Denominator", "docsis_type29ucd.scdmausratiodenom",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_scdma_timestamp_snapshot,
{"SCDMA Timestamp Snapshot", "docsis_type29ucd.scdmatimestamp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_maintain_power_spectral_density,
{"Maintain power spectral density", "docsis_type29ucd.maintainpowerspectraldensity",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_ranging_required,
{"Ranging Required", "docsis_type29ucd.rangingrequired",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_cm,
{"Ranging Hold-Off (CM)","docsis_type29ucd.rnghoffcm",
FT_UINT32, BASE_DEC, VALS (allow_inhibit_vals), 0x1,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_erouter,
{"Ranging Hold-Off (eRouter)",
"docsis_type29ucd.rnghofferouter",
FT_UINT32, BASE_DEC, VALS (allow_inhibit_vals), 0x2,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_emta,
{"Ranging Hold-Off (eMTA or EDVA)",
"docsis_type29ucd.rnghoffemta",
FT_UINT32, BASE_DEC, VALS (allow_inhibit_vals), 0x4,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_estb,
{"Ranging Hold-Off (DSG/eSTB)",
"docsis_type29ucd.rnghoffestb",
FT_UINT32, BASE_DEC, VALS (allow_inhibit_vals), 0x8,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_rsvd,
{"Reserved [0x000000]",
"docsis_type29ucd.rnghoffrsvd",
FT_UINT32, BASE_HEX, NULL, 0xFFF0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_rnghoff_id_ext,
{"CM Ranging Class ID Extension",
"docsis_type29ucd.rngidext",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_cm,
{"Channel Class ID (CM)","docsis_type29ucd.classidcm",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x1,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_erouter,
{"Channel Class ID (eRouter)",
"docsis_type29ucd.classiderouter",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x2,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_emta,
{"Channel Class ID (eMTA or EDVA)",
"docsis_type29ucd.classidemta",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x4,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_estb,
{"Channel Class ID (DSG/eSTB)",
"docsis_type29ucd.classidestb",
FT_UINT32, BASE_DEC, VALS (inhibit_allow_vals), 0x8,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_rsvd,
{"Reserved [0x000000]",
"docsis_type29ucd.classidrsvd",
FT_UINT32, BASE_HEX, NULL, 0xFFF0,
NULL, HFILL}
},
{&hf_docsis_type29ucd_chan_class_id_id_ext,
{"CM Ranging Class ID Extension",
"docsis_type29ucd.classidext",
FT_UINT32, BASE_HEX, NULL, 0xFFFF0000,
NULL, HFILL}
},
{&hf_docsis_type29ucd_max_scheduled_codes,
{"S-CDMA Max Scheduled Codes", "docsis_type29ucd.scdmamaxcodes",
FT_UINT8, BASE_DEC, VALS (max_scheduled_codes_vals), 0x0,
"S-CDMA Maximum Scheduled Codes", HFILL}
},
{&hf_docsis_rs_int_depth,
{"Scrambler On/Off", "docsis_type29ucd.burst.rsintdepth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Depth", HFILL}
},
{&hf_docsis_rs_int_block,
{"Scrambler On/Off", "docsis_type29ucd.burst.rsintblock",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Block", HFILL}
},
{&hf_docsis_preamble_type,
{"Scrambler On/Off", "docsis_type29ucd.burst.preambletype",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Preamble Type", HFILL}
},
{&hf_docsis_scdma_scrambler_onoff,
{"Scrambler On/Off", "docsis_type29ucd.burst.scdmascrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"SCDMA Scrambler On/Off", HFILL}
},
{&hf_docsis_scdma_codes_per_subframe,
{"Scrambler On/Off", "docsis_type29ucd.burst.scdmacodespersubframe",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Codes per Subframe", HFILL}
},
{&hf_docsis_scdma_framer_int_step_size,
{"Scrambler On/Off", "docsis_type29ucd.burst.scdmaframerintstepsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Framer Interleaving Step Size", HFILL}
},
{&hf_docsis_tcm_enabled,
{"Scrambler On/Off", "docsis_type29ucd.burst.tcmenabled",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"TCM Enabled", HFILL}
},
};
static ei_register_info ei[] = {
{&ei_docsis_type29ucd_tlvlen_bad, {"docsis_type29ucd.tlvlenbad", PI_MALFORMED, PI_ERROR, "Bad TLV length", EXPFILL}},
};
static gint *ett[] = {
&ett_docsis_type29ucd,
&ett_docsis_type29tlv,
&ett_docsis_type29_burst_tlv,
};
expert_module_t* expert_docsis_type29ucd;
proto_docsis_type29ucd =
proto_register_protocol ("DOCSIS Upstream Channel Descriptor Type 29",
"DOCSIS type29ucd", "docsis_type29ucd");
proto_register_field_array (proto_docsis_type29ucd, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_docsis_type29ucd = expert_register_protocol(proto_docsis_type29ucd);
expert_register_field_array(expert_docsis_type29ucd, ei, array_length(ei));
register_dissector ("docsis_type29ucd", dissect_type29ucd, proto_docsis_type29ucd);
}
void
proto_reg_handoff_docsis_type29ucd (void)
{
dissector_handle_t docsis_type29ucd_handle;
docsis_type29ucd_handle = find_dissector ("docsis_type29ucd");
dissector_add_uint ("docsis_mgmt", 0x1D, docsis_type29ucd_handle);
}
