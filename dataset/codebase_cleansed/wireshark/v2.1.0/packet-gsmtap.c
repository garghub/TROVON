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
static int
dissect_gsmtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int sub_handle, rrc_sub_handle = 0, len, offset = 0;
proto_item *ti;
proto_tree *gsmtap_tree = NULL;
tvbuff_t *payload_tvb, *l1h_tvb = NULL;
guint8 hdr_len, type, sub_type, timeslot, subslot;
guint16 arfcn;
len = tvb_reported_length(tvb);
hdr_len = tvb_get_guint8(tvb, offset + 1) <<2;
type = tvb_get_guint8(tvb, offset + 2);
timeslot = tvb_get_guint8(tvb, offset + 3);
arfcn = tvb_get_ntohs(tvb, offset + 4);
sub_type = tvb_get_guint8(tvb, offset + 12);
subslot = tvb_get_guint8(tvb, offset + 14);
if (type == GSMTAP_TYPE_UM &&
sub_type & GSMTAP_CHANNEL_ACCH) {
l1h_tvb = tvb_new_subset_length(tvb, hdr_len, 2);
payload_tvb = tvb_new_subset_length(tvb, hdr_len+2, len-(hdr_len+2));
} else {
payload_tvb = tvb_new_subset_length(tvb, hdr_len, len-hdr_len);
}
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSMTAP");
if (dissector_try_uint(gsmtap_dissector_table, type, payload_tvb,
pinfo, tree))
return tvb_captured_length(tvb);
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
proto_tree_add_uint_format_value(gsmtap_tree, hf_gsmtap_hdrlen,
tvb, offset+1, 1, hdr_len,
"%u bytes", hdr_len);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_type,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_timeslot,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_arfcn,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_uplink,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_signal_dbm,
tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gsmtap_tree, hf_gsmtap_snr_db,
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
case GSMTAP_TYPE_UMTS_RRC:
sub_handle = GSMTAP_SUB_UMTS_RRC;
rrc_sub_handle = sub_type;
if (rrc_sub_handle >= GSMTAP_RRC_SUB_MAX) {
sub_handle = GSMTAP_SUB_DATA;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RRC");
break;
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
return tvb_captured_length(tvb);
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
case GSMTAP_GMR1_RACH:
sub_handle = GSMTAP_SUB_GMR1_RACH;
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
if (sub_handle == GSMTAP_SUB_UMTS_RRC)
call_dissector(rrc_sub_handles[rrc_sub_handle], payload_tvb,
pinfo, tree);
else if (sub_handles[sub_handle] != NULL)
call_dissector(sub_handles[sub_handle], payload_tvb, pinfo, tree);
return tvb_captured_length(tvb);
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
{ &hf_gsmtap_signal_dbm, { "Signal Level (dBm)", "gsmtap.signal_dbm",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_gsmtap_snr_db, { "Signal/Noise Ratio (dB)", "gsmtap.snr_db",
FT_INT8, BASE_DEC, NULL, 0, NULL, HFILL } },
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
"GSMTAP type", proto_gsmtap, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_gsmtap(void)
{
dissector_handle_t gsmtap_handle;
sub_handles[GSMTAP_SUB_DATA] = find_dissector("data");
sub_handles[GSMTAP_SUB_UM] = find_dissector_add_dependency("gsm_a_ccch", proto_gsmtap);
sub_handles[GSMTAP_SUB_UM_LAPDM] = find_dissector_add_dependency("lapdm", proto_gsmtap);
sub_handles[GSMTAP_SUB_UM_RLC_MAC_UL] = find_dissector_add_dependency("gsm_rlcmac_ul", proto_gsmtap);
sub_handles[GSMTAP_SUB_UM_RLC_MAC_DL] = find_dissector_add_dependency("gsm_rlcmac_dl", proto_gsmtap);
sub_handles[GSMTAP_SUB_LLC] = find_dissector_add_dependency("llcgprs", proto_gsmtap);
sub_handles[GSMTAP_SUB_SNDCP] = find_dissector_add_dependency("sndcp", proto_gsmtap);
sub_handles[GSMTAP_SUB_ABIS] = find_dissector_add_dependency("gsm_a_dtap", proto_gsmtap);
sub_handles[GSMTAP_SUB_CDMA_CODE] = find_dissector_add_dependency("wimax_cdma_code_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_FCH] = find_dissector_add_dependency("wimax_fch_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_FFB] = find_dissector_add_dependency("wimax_ffb_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_PDU] = find_dissector_add_dependency("wimax_pdu_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_HACK] = find_dissector_add_dependency("wimax_hack_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_PHY_ATTRIBUTES] = find_dissector_add_dependency("wimax_phy_attributes_burst_handler", proto_gsmtap);
sub_handles[GSMTAP_SUB_CBCH] = find_dissector_add_dependency("gsm_cbch", proto_gsmtap);
sub_handles[GSMTAP_SUB_GMR1_BCCH] = find_dissector_add_dependency("gmr1_bcch", proto_gsmtap);
sub_handles[GSMTAP_SUB_GMR1_CCCH] = find_dissector_add_dependency("gmr1_ccch", proto_gsmtap);
sub_handles[GSMTAP_SUB_GMR1_LAPSAT] = find_dissector_add_dependency("lapsat", proto_gsmtap);
sub_handles[GSMTAP_SUB_GMR1_RACH] = find_dissector_add_dependency("gmr1_rach", proto_gsmtap);
sub_handles[GSMTAP_SUB_UMTS_RRC] = find_dissector_add_dependency("rrc", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_DL_DCCH_Message] = find_dissector_add_dependency("rrc.dl.dcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_UL_DCCH_Message] = find_dissector_add_dependency("rrc.ul.dcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_DL_CCCH_Message] = find_dissector_add_dependency("rrc.dl.ccch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_UL_CCCH_Message] = find_dissector_add_dependency("rrc.ul.ccch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_PCCH_Message] = find_dissector_add_dependency("rrc.pcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_DL_SHCCH_Message] = find_dissector_add_dependency("rrc.dl.shcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_UL_SHCCH_Message] = find_dissector_add_dependency("rrc.ul.shcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_BCCH_FACH_Message] = find_dissector_add_dependency("rrc.bcch.fach", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_BCCH_BCH_Message] = find_dissector_add_dependency("rrc.bcch.bch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_MCCH_Message] = find_dissector_add_dependency("rrc.mcch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_MSCH_Message] = find_dissector_add_dependency("rrc.msch", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_HandoverToUTRANCommand] = find_dissector_add_dependency("rrc.irat.ho_to_utran_cmd", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_InterRATHandoverInfo] = find_dissector_add_dependency("rrc.irat.irat_ho_info", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SystemInformation_BCH] = find_dissector_add_dependency("rrc.sysinfo", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_System_Information_Container] = find_dissector_add_dependency("rrc.sysinfo.cont", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_UE_RadioAccessCapabilityInfo] = find_dissector_add_dependency("rrc.ue_radio_access_cap_info", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_MasterInformationBlock] = find_dissector_add_dependency("rrc.si.mib", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType1] = find_dissector_add_dependency("rrc.si.sib1", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType2] = find_dissector_add_dependency("rrc.si.sib2", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType3] = find_dissector_add_dependency("rrc.si.sib3", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType4] = find_dissector_add_dependency("rrc.si.sib4", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType5] = find_dissector_add_dependency("rrc.si.sib5", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType5bis] = find_dissector_add_dependency("rrc.si.sib5bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType6] = find_dissector_add_dependency("rrc.si.sib6", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType7] = find_dissector_add_dependency("rrc.si.sib7", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType8] = find_dissector_add_dependency("rrc.si.sib8", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType9] = find_dissector_add_dependency("rrc.si.sib9", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType10] = find_dissector_add_dependency("rrc.si.sib10", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType11] = find_dissector_add_dependency("rrc.si.sib11", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType11bis] = find_dissector_add_dependency("rrc.si.sib11bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType12] = find_dissector_add_dependency("rrc.si.sib12", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType13] = find_dissector_add_dependency("rrc.si.sib13", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType13_1] = find_dissector_add_dependency("rrc.si.sib13-1", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType13_2] = find_dissector_add_dependency("rrc.si.sib13-2", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType13_3] = find_dissector_add_dependency("rrc.si.sib13-3", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType13_4] = find_dissector_add_dependency("rrc.si.sib13-4", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType14] = find_dissector_add_dependency("rrc.si.sib14", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15] = find_dissector_add_dependency("rrc.si.sib15", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15bis] = find_dissector_add_dependency("rrc.si.sib15bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_1] = find_dissector_add_dependency("rrc.si.sib15-1", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_1bis] = find_dissector_add_dependency("rrc.si.sib15-1bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_2] = find_dissector_add_dependency("rrc.si.sib15-2", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_2bis] = find_dissector_add_dependency("rrc.si.sib15-2bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_2ter] = find_dissector_add_dependency("rrc.si.sib15-2ter", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_3] = find_dissector_add_dependency("rrc.si.sib15-3", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_3bis] = find_dissector_add_dependency("rrc.si.sib15-3bis", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_4] = find_dissector_add_dependency("rrc.si.sib15-4", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_5] = find_dissector_add_dependency("rrc.si.sib15-5", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_6] = find_dissector_add_dependency("rrc.si.sib15-6", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_7] = find_dissector_add_dependency("rrc.si.sib15-7", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType15_8] = find_dissector_add_dependency("rrc.si.sib15-8", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType16] = find_dissector_add_dependency("rrc.si.sib16", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType17] = find_dissector_add_dependency("rrc.si.sib17", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType18] = find_dissector_add_dependency("rrc.si.sib18", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType19] = find_dissector_add_dependency("rrc.si.sib19", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType20] = find_dissector_add_dependency("rrc.si.sib20", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType21] = find_dissector_add_dependency("rrc.si.sib21", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoType22] = find_dissector_add_dependency("rrc.si.sib22", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoTypeSB1] = find_dissector_add_dependency("rrc.si.sb1", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_SysInfoTypeSB2] = find_dissector_add_dependency("rrc.si.sb2", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_ToTargetRNC_Container] = find_dissector_add_dependency("rrc.s_to_trnc_cont", proto_gsmtap);
rrc_sub_handles[GSMTAP_RRC_SUB_TargetRNC_ToSourceRNC_Container] = find_dissector_add_dependency("rrc.t_to_srnc_cont", proto_gsmtap);
gsmtap_handle = create_dissector_handle(dissect_gsmtap, proto_gsmtap);
dissector_add_uint("udp.port", GSMTAP_UDP_PORT, gsmtap_handle);
}
