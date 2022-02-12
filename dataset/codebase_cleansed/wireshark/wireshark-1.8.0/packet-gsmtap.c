static void
dissect_sacch_l1h(tvbuff_t *tvb, proto_tree *tree)
{
proto_item *ti;
proto_tree *l1h_tree = NULL;
if (!tree)
return;
ti = proto_tree_add_protocol_format(tree, proto_gsmtap, tvb, 0, 2,
"SACCH L1 Header, Power Level: %u, Timing Advance: %u",
tvb_get_guint8(tvb, 0) & 0x1f,
tvb_get_guint8(tvb, 1));
l1h_tree = proto_item_add_subtree(ti, ett_gsmtap);
proto_tree_add_item(l1h_tree, hf_sacch_l1h_power_lev, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(l1h_tree, hf_sacch_l1h_fpc, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(l1h_tree, hf_sacch_l1h_ta, tvb, 1, 1, ENC_BIG_ENDIAN);
}
static void
handle_tetra(int channel _U_, tvbuff_t *payload_tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
int tetra_chan;
if (channel < 0 || channel > GSMTAP_TETRA_TCH_F)
return;
tetra_chan = gsmtap_to_tetra[channel];
if (tetra_chan <= 0)
return;
tetra_dissect_pdu(tetra_chan, TETRA_DOWNLINK, payload_tvb, tree, pinfo);
}
static void
dissect_gsmtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int sub_handle, len, offset = 0;
proto_item *ti;
proto_tree *gsmtap_tree = NULL;
tvbuff_t *payload_tvb, *l1h_tvb = NULL;
guint8 hdr_len, type, sub_type, timeslot, subslot;
guint16 arfcn;
len = tvb_length(tvb);
hdr_len = tvb_get_guint8(tvb, offset + 1) <<2;
type = tvb_get_guint8(tvb, offset + 2);
timeslot = tvb_get_guint8(tvb, offset + 3);
arfcn = tvb_get_ntohs(tvb, offset + 4);
sub_type = tvb_get_guint8(tvb, offset + 12);
subslot = tvb_get_guint8(tvb, offset + 14);
if (type == GSMTAP_TYPE_UM &&
sub_type & GSMTAP_CHANNEL_ACCH) {
l1h_tvb = tvb_new_subset(tvb, hdr_len, 2, 2);
payload_tvb = tvb_new_subset(tvb, hdr_len+2, len-(hdr_len+2),
len-(hdr_len+2));
} else {
payload_tvb = tvb_new_subset(tvb, hdr_len, len-hdr_len,
len-hdr_len);
}
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSMTAP");
if (dissector_try_uint(gsmtap_dissector_table, type, payload_tvb,
pinfo, tree))
return;
if (arfcn & GSMTAP_ARFCN_F_UPLINK) {
col_append_str(pinfo->cinfo, COL_RES_NET_SRC, "MS");
col_append_str(pinfo->cinfo, COL_RES_NET_DST, "BTS");
pinfo->p2p_dir = P2P_DIR_SENT;
} else {
col_set_str(pinfo->cinfo, COL_RES_NET_SRC, "BTS");
switch (sub_type & ~GSMTAP_CHANNEL_ACCH) {
case GSMTAP_CHANNEL_BCCH:
case GSMTAP_CHANNEL_CCCH:
case GSMTAP_CHANNEL_PCH:
case GSMTAP_CHANNEL_AGCH:
case GSMTAP_CHANNEL_CBCH51:
case GSMTAP_CHANNEL_CBCH52:
col_set_str(pinfo->cinfo, COL_RES_NET_DST, "Broadcast");
break;
default:
col_set_str(pinfo->cinfo, COL_RES_NET_DST, "MS");
break;
}
pinfo->p2p_dir = P2P_DIR_RECV;
}
pinfo->circuit_id = (timeslot << 3) | subslot;
if (tree) {
guint8 channel;
const char *channel_str;
channel = tvb_get_guint8(tvb, offset+12);
if (type == GSMTAP_TYPE_TETRA_I1)
channel_str = val_to_str(channel, gsmtap_tetra_channels, "Unknown: %d");
else if (type == GSMTAP_TYPE_GMR1_UM)
channel_str = val_to_str(channel, gsmtap_gmr1_channels, "Unknown: %d");
else
channel_str = val_to_str(channel, gsmtap_channels, "Unknown: %d");
ti = proto_tree_add_protocol_format(tree, proto_gsmtap, tvb, 0, hdr_len,
"GSM TAP Header, ARFCN: %u (%s), TS: %u, Channel: %s (%u)",
arfcn & GSMTAP_ARFCN_MASK,
arfcn & GSMTAP_ARFCN_F_UPLINK ? "Uplink" : "Downlink",
tvb_get_guint8(tvb, offset+3),
channel_str,
tvb_get_guint8(tvb, offset+14));
gsmtap_tree = proto_item_add_subtree(ti, ett_gsmtap);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_version,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(gsmtap_tree, hf_gsmtap_hdrlen,
tvb, offset+1, 1, hdr_len,
"Header length: %u bytes", hdr_len);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_type,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_timeslot,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_arfcn,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_uplink,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_noise_dbm,
tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_signal_dbm,
tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_frame_nr,
tvb, offset+8, 4, ENC_BIG_ENDIAN);
if (type == GSMTAP_TYPE_UM_BURST)
proto_tree_add_item(gsmtap_tree, hf_gsmtap_burst_type,
tvb, offset+12, 1, ENC_BIG_ENDIAN);
else if (type == GSMTAP_TYPE_UM)
proto_tree_add_item(gsmtap_tree, hf_gsmtap_channel_type,
tvb, offset+12, 1, ENC_BIG_ENDIAN);
else if (type == GSMTAP_TYPE_TETRA_I1)
proto_tree_add_item(gsmtap_tree, hf_gsmtap_tetra_channel_type,
tvb, offset+12, 1, ENC_BIG_ENDIAN);
else if (type == GSMTAP_TYPE_WMX_BURST)
proto_tree_add_item(gsmtap_tree, hf_gsmtap_burst_type,
tvb, offset+12, 1, ENC_BIG_ENDIAN);
else if (type == GSMTAP_TYPE_GMR1_UM)
proto_tree_add_item(gsmtap_tree, hf_gsmtap_gmr1_channel_type,
tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_antenna,
tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_subslot,
tvb, offset+14, 1, ENC_BIG_ENDIAN);
}
switch (type) {
case GSMTAP_TYPE_UM:
if (l1h_tvb)
dissect_sacch_l1h(l1h_tvb, tree);
switch (sub_type & ~GSMTAP_CHANNEL_ACCH) {
case GSMTAP_CHANNEL_BCCH:
case GSMTAP_CHANNEL_CCCH:
case GSMTAP_CHANNEL_PCH:
case GSMTAP_CHANNEL_AGCH:
sub_handle = GSMTAP_SUB_UM;
break;
case GSMTAP_CHANNEL_SDCCH:
case GSMTAP_CHANNEL_SDCCH4:
case GSMTAP_CHANNEL_SDCCH8:
case GSMTAP_CHANNEL_TCH_F:
case GSMTAP_CHANNEL_TCH_H:
sub_handle = GSMTAP_SUB_UM_LAPDM;
break;
case GSMTAP_CHANNEL_PACCH:
if (pinfo->p2p_dir == P2P_DIR_SENT) {
sub_handle = GSMTAP_SUB_UM_RLC_MAC_UL;
}
else
{
sub_handle = GSMTAP_SUB_UM_RLC_MAC_DL;
}
break;
case GSMTAP_CHANNEL_CBCH51:
case GSMTAP_CHANNEL_CBCH52:
sub_handle = GSMTAP_SUB_CBCH;
break;
case GSMTAP_CHANNEL_RACH:
default:
sub_handle = GSMTAP_SUB_DATA;
break;
}
break;
case GSMTAP_TYPE_ABIS:
sub_handle = GSMTAP_SUB_ABIS;
break;
case GSMTAP_TYPE_GB_LLC:
sub_handle = GSMTAP_SUB_LLC;
break;
case GSMTAP_TYPE_GB_SNDCP:
sub_handle = GSMTAP_SUB_SNDCP;
break;
case GSMTAP_TYPE_TETRA_I1:
handle_tetra(tvb_get_guint8(tvb, offset+12), payload_tvb, pinfo, tree);
return;
case GSMTAP_TYPE_WMX_BURST:
switch (sub_type) {
case GSMTAP_BURST_CDMA_CODE:
sub_handle = GSMTAP_SUB_CDMA_CODE;
break;
case GSMTAP_BURST_FCH:
sub_handle = GSMTAP_SUB_FCH;
break;
case GSMTAP_BURST_FFB:
sub_handle = GSMTAP_SUB_FFB;
break;
case GSMTAP_BURST_PDU:
sub_handle = GSMTAP_SUB_PDU;
break;
case GSMTAP_BURST_HACK:
sub_handle = GSMTAP_SUB_HACK;
break;
case GSMTAP_BURST_PHY_ATTRIBUTES:
sub_handle = GSMTAP_SUB_PHY_ATTRIBUTES;
break;
default:
sub_handle = GSMTAP_SUB_DATA;
break;
}
break;
case GSMTAP_TYPE_GMR1_UM:
switch (sub_type) {
case GSMTAP_GMR1_BCCH:
sub_handle = GSMTAP_SUB_GMR1_BCCH;
break;
case GSMTAP_GMR1_CCCH:
case GSMTAP_GMR1_AGCH:
case GSMTAP_GMR1_PCH:
sub_handle = GSMTAP_SUB_GMR1_CCCH;
break;
case GSMTAP_GMR1_SDCCH:
case GSMTAP_GMR1_TCH3 | GSMTAP_GMR1_FACCH:
case GSMTAP_GMR1_TCH6 | GSMTAP_GMR1_FACCH:
case GSMTAP_GMR1_TCH9 | GSMTAP_GMR1_FACCH:
sub_handle = GSMTAP_SUB_GMR1_LAPSAT;
break;
default:
sub_handle = GSMTAP_SUB_DATA;
break;
}
break;
case GSMTAP_TYPE_UM_BURST:
default:
sub_handle = GSMTAP_SUB_DATA;
break;
}
call_dissector(sub_handles[sub_handle], payload_tvb, pinfo, tree);
}
void
proto_register_gsmtap(void)
{
static hf_register_info hf[] = {
{ &hf_gsmtap_version, { "Version", "gsmtap.version",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_hdrlen, { "Header Length", "gsmtap.hdr_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_type, { "Payload Type", "gsmtap.type",
FT_UINT8, BASE_DEC, VALS(gsmtap_types), 0, NULL, HFILL } },
{ &hf_gsmtap_timeslot, { "Time Slot", "gsmtap.ts",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_arfcn, { "ARFCN", "gsmtap.arfcn",
FT_UINT16, BASE_DEC, NULL, GSMTAP_ARFCN_MASK, NULL, HFILL } },
{ &hf_gsmtap_uplink, { "Uplink", "gsmtap.uplink",
FT_UINT16, BASE_DEC, NULL, GSMTAP_ARFCN_F_UPLINK, NULL, HFILL } },
{ &hf_gsmtap_noise_dbm, { "Signal/Noise Ratio (dB)", "gsmtap.snr_db",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_signal_dbm, { "Signal Level (dBm)", "gsmtap.signal_dbm",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_frame_nr, { "GSM Frame Number", "gsmtap.frame_nr",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_burst_type, { "Burst Type", "gsmtap.burst_type",
FT_UINT8, BASE_DEC, VALS(gsmtap_bursts), 0, NULL, HFILL }},
{ &hf_gsmtap_channel_type, { "Channel Type", "gsmtap.chan_type",
FT_UINT8, BASE_DEC, VALS(gsmtap_channels), 0, NULL, HFILL }},
{ &hf_gsmtap_tetra_channel_type, { "Channel Type", "gsmtap.tetra_chan_type",
FT_UINT8, BASE_DEC, VALS(gsmtap_tetra_channels), 0, NULL, HFILL }},
{ &hf_gsmtap_gmr1_channel_type, { "Channel Type", "gsmtap.gmr1_chan_type",
FT_UINT8, BASE_DEC, VALS(gsmtap_gmr1_channels), 0, NULL, HFILL }},
{ &hf_gsmtap_antenna, { "Antenna Number", "gsmtap.antenna",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_subslot, { "Sub-Slot", "gsmtap.sub_slot",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_sacch_l1h_power_lev, { "MS power level", "gsmtap.sacch_l1.power_lev",
FT_UINT8, BASE_DEC, NULL, 0x1f, NULL, HFILL } },
{ &hf_sacch_l1h_fpc, { "FPC", "gsmtap.sacch_l1.fpc",
FT_BOOLEAN, 8, TFS(&sacch_l1h_fpc_mode_vals), 0x04,
NULL, HFILL } },
{ &hf_sacch_l1h_ta, { "Actual Timing Advance", "gsmtap.sacch_l1.ta",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_gsmtap
};
proto_gsmtap = proto_register_protocol("GSM Radiotap", "GSMTAP", "gsmtap");
proto_register_field_array(proto_gsmtap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
gsmtap_dissector_table = register_dissector_table("gsmtap.type",
"GSMTAP type", FT_UINT8, BASE_HEX);
}
void
proto_reg_handoff_gsmtap(void)
{
dissector_handle_t gsmtap_handle;
sub_handles[GSMTAP_SUB_DATA] = find_dissector("data");
sub_handles[GSMTAP_SUB_UM] = find_dissector("gsm_a_ccch");
sub_handles[GSMTAP_SUB_UM_LAPDM] = find_dissector("lapdm");
sub_handles[GSMTAP_SUB_UM_RLC_MAC_UL] = find_dissector("gsm_rlcmac_ul");
sub_handles[GSMTAP_SUB_UM_RLC_MAC_DL] = find_dissector("gsm_rlcmac_dl");
sub_handles[GSMTAP_SUB_LLC] = find_dissector("llcgprs");
sub_handles[GSMTAP_SUB_SNDCP] = find_dissector("sndcp");
sub_handles[GSMTAP_SUB_ABIS] = find_dissector("gsm_a_dtap");
sub_handles[GSMTAP_SUB_CDMA_CODE] = find_dissector("wimax_cdma_code_burst_handler");
sub_handles[GSMTAP_SUB_FCH] = find_dissector("wimax_fch_burst_handler");
sub_handles[GSMTAP_SUB_FFB] = find_dissector("wimax_ffb_burst_handler");
sub_handles[GSMTAP_SUB_PDU] = find_dissector("wimax_pdu_burst_handler");
sub_handles[GSMTAP_SUB_HACK] = find_dissector("wimax_hack_burst_handler");
sub_handles[GSMTAP_SUB_PHY_ATTRIBUTES] = find_dissector("wimax_phy_attributes_burst_handler");
sub_handles[GSMTAP_SUB_CBCH] = find_dissector("gsm_cbch");
sub_handles[GSMTAP_SUB_GMR1_BCCH] = find_dissector("gmr1_bcch");
sub_handles[GSMTAP_SUB_GMR1_CCCH] = find_dissector("gmr1_ccch");
sub_handles[GSMTAP_SUB_GMR1_LAPSAT] = find_dissector("lapsat");
gsmtap_handle = create_dissector_handle(dissect_gsmtap, proto_gsmtap);
dissector_add_uint("udp.port", GSMTAP_UDP_PORT, gsmtap_handle);
}
