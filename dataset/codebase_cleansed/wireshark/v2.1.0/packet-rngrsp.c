static int
dissect_rngrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *rngrsp_tree;
proto_item *rngrsptlv_item;
proto_tree *rngrsptlv_tree;
guint8 tlvtype, tlvlen;
int pos;
gint length;
guint8 upchid;
guint16 sid;
sid = tvb_get_ntohs (tvb, 0);
upchid = tvb_get_guint8 (tvb, 2);
if (upchid > 0)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Ranging Response: SID = %u, Upstream Channel = %u (U%u)",
sid, upchid, upchid - 1);
else
col_add_fstr (pinfo->cinfo, COL_INFO,
"Ranging Response: SID = %u, Telephony Return", sid);
it = proto_tree_add_protocol_format (tree, proto_docsis_rngrsp, tvb, 0, -1,
"Ranging Response");
rngrsp_tree = proto_item_add_subtree (it, ett_docsis_rngrsp);
proto_tree_add_item (rngrsp_tree, hf_docsis_rngrsp_sid, tvb, 0, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (rngrsp_tree, hf_docsis_rngrsp_upstream_chid, tvb,
2, 1, ENC_BIG_ENDIAN);
length = tvb_reported_length (tvb);
pos = 3;
while (pos < length)
{
tlvtype = tvb_get_guint8 (tvb, pos);
rngrsptlv_tree = proto_tree_add_subtree(rngrsp_tree, tvb, pos, -1,
ett_docsis_rngrsptlv, &rngrsptlv_item,
val_to_str(tlvtype, rngrsp_tlv_vals,
"Unknown TLV (%u)"));
proto_tree_add_uint (rngrsptlv_tree, hf_docsis_rngrsp_type,
tvb, pos, 1, tlvtype);
pos++;
tlvlen = tvb_get_guint8 (tvb, pos);
proto_tree_add_uint (rngrsptlv_tree, hf_docsis_rngrsp_length,
tvb, pos, 1, tlvlen);
pos++;
proto_item_set_len(rngrsptlv_item, tlvlen + 2);
switch (tlvtype)
{
case RNGRSP_TIMING:
if (tlvlen == 4)
{
proto_tree_add_item (rngrsptlv_tree,
hf_docsis_rngrsp_timing_adj, tvb, pos,
tlvlen, ENC_BIG_ENDIAN);
}
pos = pos + tlvlen;
break;
case RNGRSP_PWR_LEVEL_ADJ:
if (tlvlen == 1)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_power_adj,
tvb, pos, tlvlen, ENC_NA);
}
pos = pos + tlvlen;
break;
case RNGRSP_OFFSET_FREQ_ADJ:
if (tlvlen == 2)
{
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_freq_adj,
tvb, pos, tlvlen, ENC_BIG_ENDIAN);
}
pos = pos + tlvlen;
break;
case RNGRSP_TRANSMIT_EQ_ADJ:
proto_tree_add_item (rngrsptlv_tree, hf_docsis_rngrsp_xmit_eq_adj,
tvb, pos, tlvlen, ENC_NA);
pos = pos + tlvlen;
break;
case RNGRSP_RANGING_STATUS:
if (tlvlen == 1)
proto_tree_add_item (rngrsptlv_tree,
hf_docsis_rngrsp_ranging_status, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
pos = pos + tlvlen;
break;
case RNGRSP_DOWN_FREQ_OVER:
if (tlvlen == 4)
proto_tree_add_item (rngrsptlv_tree,
hf_docsis_rngrsp_down_freq_over, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
pos = pos + tlvlen;
break;
case RNGRSP_UP_CHID_OVER:
if (tlvlen == 1)
proto_tree_add_item (rngrsptlv_tree,
hf_docsis_rngrsp_upstream_ch_over, tvb,
pos, tlvlen, ENC_BIG_ENDIAN);
pos = pos + tlvlen;
break;
default:
pos = pos + tlvlen;
}
}
return length;
}
void
proto_register_docsis_rngrsp (void)
{
static hf_register_info hf[] = {
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
{&hf_docsis_rngrsp_upstream_chid,
{"Upstream Channel ID", "docsis_rngrsp.upchid",
FT_UINT8, BASE_DEC, NULL, 0x0,
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
};
static gint *ett[] = {
&ett_docsis_rngrsp,
&ett_docsis_rngrsptlv,
};
proto_docsis_rngrsp = proto_register_protocol ("DOCSIS Ranging Response",
"DOCSIS RNG-RSP",
"docsis_rngrsp");
proto_register_field_array (proto_docsis_rngrsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_rngrsp", dissect_rngrsp, proto_docsis_rngrsp);
}
void
proto_reg_handoff_docsis_rngrsp (void)
{
dissector_handle_t docsis_rngrsp_handle;
docsis_rngrsp_handle = find_dissector ("docsis_rngrsp");
dissector_add_uint ("docsis_mgmt", 0x05, docsis_rngrsp_handle);
}
