static void
dissect_type29ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint16 pos, endtlvpos;
guint8 type, length;
guint8 tlvlen, tlvtype;
proto_tree *burst_descr_tree;
proto_item *it;
proto_tree *type29ucd_tree;
proto_item *type29ucd_item;
guint16 len;
guint8 upchid, symrate;
len = tvb_length_remaining (tvb, 0);
upchid = tvb_get_guint8 (tvb, 0);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"type29ucd Message: Channel ID = %u (U%u)", upchid,
upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"type29ucd Message: Channel ID = %u (Telephony Return)",
upchid);
if (tree)
{
type29ucd_item =
proto_tree_add_protocol_format (tree, proto_docsis_type29ucd, tvb, 0,
tvb_length_remaining (tvb, 0),
"type29ucd Message");
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
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case type29ucd_SYMBOL_RATE:
if (length == 1)
{
symrate = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (type29ucd_tree, hf_docsis_type29ucd_symbol_rate,
tvb, pos, length, symrate * 160);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_FREQUENCY:
if (length == 4)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_frequency, tvb,
pos, length, ENC_BIG_ENDIAN);
pos = pos + length;
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE:
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_preamble_pat, tvb,
pos, length, ENC_NA);
pos = pos + length;
break;
case type29ucd_EXT_PREAMBLE:
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_ext_preamble, tvb,
pos, length, ENC_NA);
pos = pos + length;
break;
case type29ucd_SCDMA_MODE_ENABLE:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_mode_enable,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_SPREADING_INTERVAL:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_spreading_interval,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_CODES_PER_MINI_SLOT:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_codes_per_mini_slot,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_ACTIVE_CODES:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_active_codes,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_CODE_HOPPING_SEED:
if (length == 2)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_code_hopping_seed,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_US_RATIO_NUM:
if (length == 2)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_us_ratio_num,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_US_RATIO_DENOM:
if (length == 2)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_us_ratio_denom,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_SCDMA_TIMESTAMP_SNAPSHOT:
if (length == 9)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_scdma_timestamp_snapshot,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_MAINTAIN_POWER_SPECTRAL_DENSITY:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_maintain_power_spectral_density,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_RANGING_REQUIRED:
if (length == 1)
{
proto_tree_add_item (type29ucd_tree, hf_docsis_type29ucd_ranging_required,
tvb, pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case type29ucd_BURST_DESCR:
it =
proto_tree_add_text (type29ucd_tree, tvb, pos, length,
"4 Burst Descriptor (Length = %u)",
length);
burst_descr_tree = proto_item_add_subtree (it, ett_burst_descr);
proto_tree_add_item (burst_descr_tree, hf_docsis_type29ucd_iuc, tvb,
pos++, 1, ENC_BIG_ENDIAN);
endtlvpos = pos + length - 1;
while (pos < endtlvpos)
{
tlvtype = tvb_get_guint8 (tvb, pos++);
tlvlen = tvb_get_guint8 (tvb, pos++);
switch (tlvtype)
{
case type29ucd_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_mod_type, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_diff_encoding,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_preamble_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_preamble_val_off,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_fec, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_fec_codeword,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_scrambler_seed,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_max_burst, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_guard_time,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_last_cw_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
}
pos = pos + tlvlen;
}
break;
case type29ucd_BURST_DESCR5:
it =
proto_tree_add_text (type29ucd_tree, tvb, pos, length,
"5 Burst Descriptor (Length = %u)",
length);
burst_descr_tree = proto_item_add_subtree (it, ett_burst_descr);
proto_tree_add_item (burst_descr_tree, hf_docsis_type29ucd_iuc, tvb,
pos++, 1, ENC_BIG_ENDIAN);
endtlvpos = pos + length - 1;
while (pos < endtlvpos)
{
tlvtype = tvb_get_guint8 (tvb, pos++);
tlvlen = tvb_get_guint8 (tvb, pos++);
switch (tlvtype)
{
case type29ucd_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_mod_type, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_diff_encoding,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_preamble_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_preamble_val_off,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_fec, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_fec_codeword,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_scrambler_seed,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_max_burst, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_guard_time,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_last_cw_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_burst_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_RS_INT_DEPTH:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_rs_int_depth,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_RS_INT_BLOCK:
if (tlvlen == 2)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_rs_int_block,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_PREAMBLE_TYPE:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_preamble_type,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCMDA_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_scdma_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCDMA_CODES_PER_SUBFRAME:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_scdma_codes_per_subframe,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_SCDMA_FRAMER_INT_STEP_SIZE:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_scdma_framer_int_step_size,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case type29ucd_TCM_ENABLED:
if (tlvlen == 1)
{
proto_tree_add_item (burst_descr_tree,
hf_docsis_tcm_enabled,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
}
pos = pos + tlvlen;
}
break;
}
}
}
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
{&hf_docsis_type29ucd_symbol_rate,
{"1 Symbol Rate (ksym/sec)", "docsis_type29ucd.symrate",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Symbol Rate", HFILL}
},
{&hf_docsis_type29ucd_frequency,
{"2 Frequency (Hz)", "docsis_type29ucd.freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Upstream Center Frequency", HFILL}
},
{&hf_docsis_type29ucd_preamble_pat,
{"3 Preamble Pattern", "docsis_type29ucd.preamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Preamble Superstring", HFILL}
},
{&hf_docsis_type29ucd_iuc,
{"Interval Usage Code", "docsis_type29ucd.iuc",
FT_UINT8, BASE_DEC, VALS (iuc_vals2), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_mod_type,
{"1 Modulation Type", "docsis_type29ucd.burst.modtype",
FT_UINT8, BASE_DEC, VALS (mod_vals2), 0x0,
"Modulation Type", HFILL}
},
{&hf_docsis_burst_diff_encoding,
{"2 Differential Encoding", "docsis_type29ucd.burst.diffenc",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"Differential Encoding", HFILL}
},
{&hf_docsis_burst_preamble_len,
{"3 Preamble Length (Bits)", "docsis_type29ucd.burst.preamble_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Preamble Length (Bits)", HFILL}
},
{&hf_docsis_burst_preamble_val_off,
{"4 Preamble Offset (Bits)", "docsis_type29ucd.burst.preamble_off",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Preamble Offset (Bits)", HFILL}
},
{&hf_docsis_burst_fec,
{"5 FEC (T)", "docsis_type29ucd.burst.fec",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC (T) Codeword Parity Bits = 2^T", HFILL}
},
{&hf_docsis_burst_fec_codeword,
{"6 FEC Codeword Info bytes (k)", "docsis_type29ucd.burst.fec_codeword",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC Codeword Info Bytes (k)", HFILL}
},
{&hf_docsis_burst_scrambler_seed,
{"7 Scrambler Seed", "docsis_type29ucd.burst.scrambler_seed",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Burst Descriptor", HFILL}
},
{&hf_docsis_burst_max_burst,
{"8 Max Burst Size (Minislots)", "docsis_type29ucd.burst.maxburst",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max Burst Size (Minislots)", HFILL}
},
{&hf_docsis_burst_guard_time,
{"9 Guard Time Size (Symbol Times)", "docsis_type29ucd.burst.guardtime",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Guard Time Size", HFILL}
},
{&hf_docsis_burst_last_cw_len,
{"10 Last Codeword Length", "docsis_type29ucd.burst.last_cw_len",
FT_UINT8, BASE_DEC, VALS (last_cw_len_vals), 0x0,
"Last Codeword Length", HFILL}
},
{&hf_docsis_burst_scrambler_onoff,
{"11 Scrambler On/Off", "docsis_type29ucd.burst.scrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"Scrambler On/Off", HFILL}
},
{&hf_docsis_type29ucd_ext_preamble,
{"6 Extended Preamble Pattern", "docsis_type29ucd.extpreamble",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Extended Preamble Pattern", HFILL}
},
{&hf_docsis_type29ucd_scdma_mode_enable,
{"7 SCDMA Mode Enable", "docsis_type29ucd.scdmaenable",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Mode Enable", HFILL}
},
{&hf_docsis_type29ucd_scdma_spreading_interval,
{"8 SCDMA Spreading Interval", "docsis_type29ucd.scdmaspreadinginterval",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Spreading Interval", HFILL}
},
{&hf_docsis_type29ucd_scdma_codes_per_mini_slot,
{"9 SCDMA Codes per mini slot", "docsis_type29ucd.scdmacodesperminislot",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Codes per mini slot", HFILL}
},
{&hf_docsis_type29ucd_scdma_active_codes,
{"10 SCDMA Active Codes", "docsis_type29ucd.scdmaactivecodes",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Active Codes", HFILL}
},
{&hf_docsis_type29ucd_scdma_code_hopping_seed,
{"11 SCDMA Code Hopping Seed", "docsis_type29ucd.scdmacodehoppingseed",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Code Hopping Seed", HFILL}
},
{&hf_docsis_type29ucd_scdma_us_ratio_num,
{"12 SCDMA US Ratio Numerator", "docsis_type29ucd.scdmausrationum",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA US Ratio Numerator", HFILL}
},
{&hf_docsis_type29ucd_scdma_us_ratio_denom,
{"13 SCDMA US Ratio Denominator", "docsis_type29ucd.scdmausratiodenom",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA US Ratio Denominator", HFILL}
},
{&hf_docsis_type29ucd_scdma_timestamp_snapshot,
{"14 SCDMA Timestamp Snapshot", "docsis_type29ucd.scdmatimestamp",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SCDMA Timestamp Snapshot", HFILL}
},
{&hf_docsis_type29ucd_maintain_power_spectral_density,
{"15 Maintain power spectral density", "docsis_type29ucd.maintainpowerspectraldensity",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Maintain power spectral density", HFILL}
},
{&hf_docsis_type29ucd_ranging_required,
{"16 Ranging Required", "docsis_type29ucd.rangingrequired",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Ranging Required", HFILL}
},
{&hf_docsis_rs_int_depth,
{"12 Scrambler On/Off", "docsis_type29ucd.burst.rsintdepth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Depth", HFILL}
},
{&hf_docsis_rs_int_block,
{"13 Scrambler On/Off", "docsis_type29ucd.burst.rsintblock",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Block", HFILL}
},
{&hf_docsis_preamble_type,
{"14 Scrambler On/Off", "docsis_type29ucd.burst.preambletype",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Preamble Type", HFILL}
},
{&hf_docsis_scdma_scrambler_onoff,
{"15 Scrambler On/Off", "docsis_type29ucd.burst.scdmascrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"SCDMA Scrambler On/Off", HFILL}
},
{&hf_docsis_scdma_codes_per_subframe,
{"16 Scrambler On/Off", "docsis_type29ucd.burst.scdmacodespersubframe",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Codes per Subframe", HFILL}
},
{&hf_docsis_scdma_framer_int_step_size,
{"17 Scrambler On/Off", "docsis_type29ucd.burst.scdmaframerintstepsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Framer Interleaving Step Size", HFILL}
},
{&hf_docsis_tcm_enabled,
{"18 Scrambler On/Off", "docsis_type29ucd.burst.tcmenabled",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"TCM Enabled", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_type29ucd,
&ett_burst_descr,
};
proto_docsis_type29ucd =
proto_register_protocol ("DOCSIS Upstream Channel Descriptor Type 29",
"DOCSIS type29ucd", "docsis_type29ucd");
proto_register_field_array (proto_docsis_type29ucd, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_type29ucd", dissect_type29ucd, proto_docsis_type29ucd);
}
void
proto_reg_handoff_docsis_type29ucd (void)
{
dissector_handle_t docsis_type29ucd_handle;
docsis_type29ucd_handle = find_dissector ("docsis_type29ucd");
dissector_add_uint ("docsis_mgmt", 0x1D, docsis_type29ucd_handle);
}
