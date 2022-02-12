static void
dissect_ucd (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
int pos, endtlvpos;
guint8 type, length;
guint8 tlvlen, tlvtype;
proto_tree *ucd_tree;
proto_item *ucd_item;
proto_tree *tlv_tree;
proto_item *tlv_item;
gint len;
guint8 upchid, symrate;
len = tvb_reported_length_remaining (tvb, 0);
upchid = tvb_get_guint8 (tvb, 0);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"UCD Message: Channel ID = %u (U%u)", upchid,
upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"UCD Message: Channel ID = %u (Telephony Return)",
upchid);
if (tree)
{
ucd_item =
proto_tree_add_protocol_format (tree, proto_docsis_ucd, tvb, 0, -1,
"UCD Message");
ucd_tree = proto_item_add_subtree (ucd_item, ett_docsis_ucd);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_upstream_chid, tvb, 0, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_config_ch_cnt, tvb, 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_mini_slot_size, tvb, 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ucd_tree, hf_docsis_ucd_down_chid, tvb, 3, 1,
ENC_BIG_ENDIAN);
pos = 4;
while (pos < len)
{
type = tvb_get_guint8 (tvb, pos);
tlv_tree = proto_tree_add_subtree(ucd_tree, tvb, pos, -1,
ett_tlv, &tlv_item,
val_to_str(type, channel_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (tlv_tree, hf_docsis_ucd_type,
tvb, pos, 1, type);
pos++;
length = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (tlv_tree, hf_docsis_ucd_length,
tvb, pos, 1, length);
pos++;
proto_item_set_len(tlv_item, length + 2);
switch (type)
{
case UCD_SYMBOL_RATE:
if (length == 1)
{
symrate = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (tlv_tree, hf_docsis_ucd_symbol_rate,
tvb, pos, length, symrate * 160);
}
else
{
THROW (ReportedBoundsError);
}
pos = pos + length;
break;
case UCD_FREQUENCY:
if (length == 4)
{
proto_tree_add_item (tlv_tree, hf_docsis_ucd_frequency, tvb,
pos, length, ENC_BIG_ENDIAN);
pos = pos + length;
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE:
proto_tree_add_item (tlv_tree, hf_docsis_ucd_preamble_pat, tvb,
pos, length, ENC_NA);
pos = pos + length;
break;
case UCD_BURST_DESCR:
proto_tree_add_item (tlv_tree, hf_docsis_ucd_iuc, tvb,
pos++, 1, ENC_BIG_ENDIAN);
endtlvpos = pos + length - 1;
while (pos < endtlvpos)
{
tlvtype = tvb_get_guint8 (tvb, pos++);
tlvlen = tvb_get_guint8 (tvb, pos++);
switch (tlvtype)
{
case UCD_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_mod_type, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_diff_encoding,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_preamble_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_preamble_val_off,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_fec, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_fec_codeword,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_scrambler_seed,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_max_burst, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_guard_time,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_last_cw_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
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
case UCD_BURST_DESCR5:
proto_tree_add_item (tlv_tree, hf_docsis_ucd_iuc, tvb,
pos++, 1, ENC_BIG_ENDIAN);
endtlvpos = pos + length - 1;
while (pos < endtlvpos)
{
tlvtype = tvb_get_guint8 (tvb, pos++);
tlvlen = tvb_get_guint8 (tvb, pos++);
switch (tlvtype)
{
case UCD_MODULATION:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_mod_type, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_DIFF_ENCODING:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_diff_encoding,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE_LEN:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_preamble_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE_VAL_OFF:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_preamble_val_off,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_FEC:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_fec, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_FEC_CODEWORD:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_fec_codeword,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCRAMBLER_SEED:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_scrambler_seed,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_MAX_BURST:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_max_burst, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_GUARD_TIME:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_guard_time,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_LAST_CW_LEN:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_last_cw_len,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_burst_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_RS_INT_DEPTH:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_rs_int_depth,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_RS_INT_BLOCK:
if (tlvlen == 2)
{
proto_tree_add_item (tlv_tree,
hf_docsis_rs_int_block,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_PREAMBLE_TYPE:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_preamble_type,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCMDA_SCRAMBLER_ONOFF:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_scdma_scrambler_onoff,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCDMA_CODES_PER_SUBFRAME:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_scdma_codes_per_subframe,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_SCDMA_FRAMER_INT_STEP_SIZE:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
hf_docsis_scdma_framer_int_step_size,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case UCD_TCM_ENABLED:
if (tlvlen == 1)
{
proto_tree_add_item (tlv_tree,
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
proto_register_docsis_ucd (void)
{
static hf_register_info hf[] = {
{&hf_docsis_ucd_upstream_chid,
{"Upstream Channel ID", "docsis_ucd.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
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
{&hf_docsis_ucd_down_chid,
{"Downstream Channel ID", "docsis_ucd.downchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Management Message", HFILL}
},
{&hf_docsis_ucd_type,
{"TLV Type", "docsis_ucd.type",
FT_UINT8, BASE_DEC, VALS(channel_tlv_vals), 0x0,
"Channel TLV type", HFILL}
},
{&hf_docsis_ucd_length,
{"TLV Length", "docsis_ucd.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Channel TLV length", HFILL}
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
{&hf_docsis_ucd_iuc,
{"Interval Usage Code", "docsis_ucd.iuc",
FT_UINT8, BASE_DEC, VALS (iuc_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_burst_mod_type,
{"1 Modulation Type", "docsis_ucd.burst.modtype",
FT_UINT8, BASE_DEC, VALS (mod_vals), 0x0,
"Modulation Type", HFILL}
},
{&hf_docsis_burst_diff_encoding,
{"2 Differential Encoding", "docsis_ucd.burst.diffenc",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"Differential Encoding", HFILL}
},
{&hf_docsis_burst_preamble_len,
{"3 Preamble Length (Bits)", "docsis_ucd.burst.preamble_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Preamble Length (Bits)", HFILL}
},
{&hf_docsis_burst_preamble_val_off,
{"4 Preamble Offset (Bits)", "docsis_ucd.burst.preamble_off",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Preamble Offset (Bits)", HFILL}
},
{&hf_docsis_burst_fec,
{"5 FEC (T)", "docsis_ucd.burst.fec",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC (T) Codeword Parity Bits = 2^T", HFILL}
},
{&hf_docsis_burst_fec_codeword,
{"6 FEC Codeword Info bytes (k)", "docsis_ucd.burst.fec_codeword",
FT_UINT8, BASE_DEC, NULL, 0x0,
"FEC Codeword Info Bytes (k)", HFILL}
},
{&hf_docsis_burst_scrambler_seed,
{"7 Scrambler Seed", "docsis_ucd.burst.scrambler_seed",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Burst Descriptor", HFILL}
},
{&hf_docsis_burst_max_burst,
{"8 Max Burst Size (Minislots)", "docsis_ucd.burst.maxburst",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Max Burst Size (Minislots)", HFILL}
},
{&hf_docsis_burst_guard_time,
{"9 Guard Time Size (Symbol Times)", "docsis_ucd.burst.guardtime",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Guard Time Size", HFILL}
},
{&hf_docsis_burst_last_cw_len,
{"10 Last Codeword Length", "docsis_ucd.burst.last_cw_len",
FT_UINT8, BASE_DEC, VALS (last_cw_len_vals), 0x0,
"Last Codeword Length", HFILL}
},
{&hf_docsis_burst_scrambler_onoff,
{"11 Scrambler On/Off", "docsis_ucd.burst.scrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"Scrambler On/Off", HFILL}
},
{&hf_docsis_rs_int_depth,
{"12 RS Interleaver Depth", "docsis_ucd.burst.rsintdepth",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Depth", HFILL}
},
{&hf_docsis_rs_int_block,
{"13 RS Interleaver Block Size", "docsis_ucd.burst.rsintblock",
FT_UINT8, BASE_DEC, NULL, 0x0,
"R-S Interleaver Block", HFILL}
},
{&hf_docsis_preamble_type,
{"14 Preamble Type", "docsis_ucd.burst.preambletype",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Preamble Type", HFILL}
},
{&hf_docsis_scdma_scrambler_onoff,
{"15 SCDMA Scrambler On/Off", "docsis_ucd.burst.scdmascrambleronoff",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"SCDMA Scrambler On/Off", HFILL}
},
{&hf_docsis_scdma_codes_per_subframe,
{"16 SCDMA Codes per Subframe", "docsis_ucd.burst.scdmacodespersubframe",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Codes per Subframe", HFILL}
},
{&hf_docsis_scdma_framer_int_step_size,
{"17 SDMA Framer Int Step Size", "docsis_ucd.burst.scdmaframerintstepsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SCDMA Framer Interleaving Step Size", HFILL}
},
{&hf_docsis_tcm_enabled,
{"18 TCM Enable", "docsis_ucd.burst.tcmenabled",
FT_UINT8, BASE_DEC, VALS (on_off_vals), 0x0,
"TCM Enabled", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_ucd,
&ett_tlv,
};
proto_docsis_ucd =
proto_register_protocol ("DOCSIS Upstream Channel Descriptor",
"DOCSIS UCD", "docsis_ucd");
proto_register_field_array (proto_docsis_ucd, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_ucd", dissect_ucd, proto_docsis_ucd);
}
void
proto_reg_handoff_docsis_ucd (void)
{
dissector_handle_t docsis_ucd_handle;
docsis_ucd_handle = find_dissector ("docsis_ucd");
dissector_add_uint ("docsis_mgmt", 0x02, docsis_ucd_handle);
}
