static void
rr_gen_ie_seconds_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u seconds", v);
}
static void
rr_timing_ofs_value_fmt(gchar *s, guint32 v)
{
gint32 sv = (signed)v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.3f symbols ( ~ %.3f ms )",
sv / 40.0f, (sv / 40.0f) * (10.0f / 234.0f));
}
static void
rr_freq_ofs_value_fmt(gchar *s, guint32 v)
{
gint32 sv = (signed)v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%d Hz", sv);
}
static void
rr_pos_upd_info_dist_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d km", v);
}
static void
rr_pos_upd_info_time_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes", v);
}
static void
rr_gps_timestamp_fmt(gchar *s, guint32 v)
{
if (v == 0xffff)
g_snprintf(s, ITEM_LABEL_LENGTH, "> 65535 minutes or N/A");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes", v);
}
static void
rr_gps_almanac_pn_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d", v+1);
}
static void
rr_pkt_freq_prm_xx_bw_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d * 31.25 kHz = %.2f kHz (%d)", v, 31.25f*v, v);
}
static void
rr_pkt_pwr_ctrl_prm_par_fmt(gchar *s, guint32 v)
{
if (v >= 61) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Escape %d (%d)", v-60, v);
return;
}
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f dB (%d)", v*0.4f, v);
}
void
gmr1_get_msg_rr_params(guint8 oct, int dcch, const gchar **msg_str,
int *ett_tree, int *hf_idx, gmr1_msg_func_t *msg_func_p)
{
const gchar *m = NULL;
gint idx;
if (dcch)
m = try_val_to_str_idx((guint32)oct | 0x100, gmr1_msg_rr_strings, &idx);
if (!m)
m = try_val_to_str_idx((guint32)oct, gmr1_msg_rr_strings, &idx);
*msg_str = m;
*hf_idx = hf_rr_msg_type;
if (m != NULL) {
*ett_tree = ett_msg_rr[idx];
*msg_func_p = gmr1_msg_rr_func[idx];
} else {
*ett_tree = -1;
*msg_func_p = NULL;
}
}
static void
dissect_gmr1_ccch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 len, offset;
gmr1_msg_func_t msg_func;
const gchar *msg_str;
gint ett_tree;
int hf_idx;
proto_item *ccch_item = NULL, *pd_item = NULL;
proto_tree *ccch_tree = NULL, *pd_tree = NULL;
guint32 oct[3];
guint8 pd;
gint ti = -1;
len = tvb_reported_length(tvb);
offset = 0;
if (len < 3) {
goto err;
}
col_append_str(pinfo->cinfo, COL_INFO, "(CCCH) ");
oct[0] = tvb_get_guint8(tvb, offset++);
oct[1] = tvb_get_guint8(tvb, offset++);
if ((oct[1] & GMR1_PD_EXT_MSK) == GMR1_PD_EXT_VAL)
pd = oct[1] & 0xff;
else
pd = oct[1] & 0x0f;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",
val_to_str(pd, gmr1_pd_short_vals, "Unknown (%u)"));
if (pd != GMR1_PD_RR)
goto err;
oct[2] = tvb_get_guint8(tvb, offset);
gmr1_get_msg_rr_params(oct[2], 0, &msg_str, &ett_tree, &hf_idx, &msg_func);
if (msg_str == NULL)
{
ccch_item = proto_tree_add_protocol_format(
tree, proto_gmr1_ccch, tvb, 0, len,
"GMR-1 CCCH - Message Type (0x%02x)", oct[2]);
ccch_tree = proto_item_add_subtree(ccch_item, ett_msg_ccch);
col_append_fstr(pinfo->cinfo, COL_INFO, "Message Type (0x%02x) ", oct[2]);
}
else
{
ccch_item = proto_tree_add_protocol_format(
tree, proto_gmr1_ccch, tvb, 0, -1,
"GMR-1 CCCH - %s", msg_str);
ccch_tree = proto_item_add_subtree(ccch_item, ett_tree);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
}
offset = 0;
offset += elem_v(tvb, ccch_tree, pinfo, GMR1_IE_RR, GMR1_IE_RR_L2_PSEUDO_LEN, offset, NULL);
pd_item = proto_tree_add_uint(
ccch_tree, hf_rr_protocol_discriminator, tvb, 1, 1, pd);
pd_tree = proto_item_add_subtree(pd_item, ett_rr_pd);
if (ti == -1) {
proto_tree_add_item(pd_tree, hf_gmr1_skip_ind, tvb, 1, 1, ENC_BIG_ENDIAN);
} else {
}
proto_tree_add_item(pd_tree, hf_gmr1_l3_pd, tvb, 1, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_uint_format(
ccch_tree, hf_idx, tvb, offset, 1, oct[2],
"Message Type: %s", msg_str ? msg_str : "(Unknown)"
);
offset++;
if (msg_func) {
(*msg_func)(tvb, ccch_tree, pinfo, offset, len - offset);
} else {
proto_tree_add_item(ccch_tree, hf_rr_message_elements, tvb, offset, len - offset, ENC_NA);
}
return;
err:
call_dissector(data_handle, tvb, pinfo, tree);
}
void
proto_register_gmr1_rr(void)
{
static hf_register_info hf[] = {
{ &hf_rr_msg_type,
{ "Radio Resources Management Message Type", "gmr1.rr.msg_type",
FT_UINT8, BASE_HEX, VALS(gmr1_msg_rr_strings), 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_desc_kab_loc,
{ "KAB Location", "gmr1.rr.chan_desc.kab_loc",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_desc_rx_tn,
{ "RX Timeslot", "gmr1.rr.chan_desc.rx_tn",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_desc_arfcn,
{ "ARFCN", "gmr1.rr.chan_desc.arfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_desc_tx_tn,
{ "TX Timeslot", "gmr1.rr.chan_desc.tx_tn",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_desc_chan_type,
{ "Channel Type", "gmr1.rr.chan_desc.chan_type",
FT_UINT8, BASE_DEC, VALS(rr_chan_desc_chan_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_chan_mode,
{ "Channel Mode", "gmr1.rr.chan_mode",
FT_UINT8, BASE_DEC, VALS(rr_chan_mode_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_ciph_mode_setting_sc,
{ "SC", "gmr1.rr.ciph_mode_setting.sc",
FT_UINT8, BASE_DEC, VALS(rr_ciph_mode_setting_sc_vals), 0x01,
NULL, HFILL }
},
{ &hf_rr_ciph_mode_setting_algo,
{ "Algorithm", "gmr1.rr.ciph_mode_setting.algo",
FT_UINT8, BASE_DEC, VALS(rr_ciph_mode_setting_algo_vals), 0x0e,
NULL, HFILL }
},
{ &hf_rr_ciph_resp_cr,
{ "CR", "gmr1.rr.ciph_resp.cr",
FT_UINT8, BASE_DEC, VALS(rr_ciph_resp_cr_vals), 0x10,
NULL, HFILL }
},
{ &hf_rr_ciph_resp_spare,
{ "Spare", "gmr1.rr.ciph_resp.spare",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL }
},
{ &hf_rr_l2_pseudo_len,
{ "L2 Pseudo Length value", "gmr1.rr.l2_pseudo_len",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_rr_page_mode,
{ "Page Mode", "gmr1.rr.page_mode.mode",
FT_UINT8, BASE_DEC, VALS(rr_page_mode_vals), 0x03,
NULL, HFILL }
},
{ &hf_rr_page_mode_spare,
{ "Spare", "gmr1.rr.page_mode.spare",
FT_UINT8, BASE_DEC, NULL, 0x0c,
NULL, HFILL }
},
{ &hf_rr_req_ref_est_cause,
{ "Establishment cause group ID", "gmr1.rr.req_ref.est_cause",
FT_UINT8, BASE_DEC, VALS(rr_req_ref_est_cause_vals), 0xe0,
NULL, HFILL }
},
{ &hf_rr_req_ref_ra,
{ "Random Access Information", "gmr1.rr.req_ref.ra",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_rr_req_ref_fn,
{ "Frame Number mod 256", "gmr1.rr.req_ref.fn",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_cause,
{ "RR Cause", "gmr1.rr.cause",
FT_UINT8, BASE_DEC, VALS(rr_cause_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_timing_ofs_ti,
{ "TI", "gmr1.rr.timing_offset.ti",
FT_UINT8, BASE_DEC, VALS(rr_timing_ofs_ti_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_timing_ofs_value,
{ "Timing Offset value", "gmr1.rr.timing_offset.value",
FT_INT16, BASE_CUSTOM, CF_FUNC(rr_timing_ofs_value_fmt), 0x00,
NULL, HFILL }
},
{ &hf_rr_tmsi_ptmsi,
{ "TMSI/P-TMSI Value","gmr1.rr.tmsi_ptmsi",
FT_UINT32,BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_wait_ind_timeout,
{ "T3122/T3142 timeout", "gmr1.rr.wait_ind.timeout",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_gen_ie_seconds_fmt), 0x00,
NULL, HFILL }
},
{ &hf_rr_mif_mes1_ab,
{ "MES1 - Assignment Type", "gmr1.rr.mes_info_flag.1.ab",
FT_UINT8, BASE_DEC, VALS(rr_mif_mes1_ab_vals), 0x03,
NULL, HFILL }
},
{ &hf_rr_mif_mes1_i,
{ "MES1 - Idle mode position update", "gmr1.rr.mes_info_flag.1.i",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x04,
NULL, HFILL }
},
{ &hf_rr_mif_mes1_d,
{ "MES1 - Dedicated mode position update", "gmr1.rr.mes_info_flag.1.d",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x08,
NULL, HFILL }
},
{ &hf_rr_mif_mes2,
{ "MES2", "gmr1.rr.mes_info_flag.2",
FT_UINT8, BASE_DEC, VALS(rr_mif_mes234_vals), 0x10,
NULL, HFILL }
},
{ &hf_rr_mif_mes3,
{ "MES3", "gmr1.rr.mes_info_flag.3",
FT_UINT8, BASE_DEC, VALS(rr_mif_mes234_vals), 0x20,
NULL, HFILL }
},
{ &hf_rr_mif_mes4,
{ "MES4", "gmr1.rr.mes_info_flag.4",
FT_UINT8, BASE_DEC, VALS(rr_mif_mes234_vals), 0x40,
NULL, HFILL }
},
{ &hf_rr_mif_pv,
{ "Position Verification indicator", "gmr1.rr.mes_info_flag.pv",
FT_UINT8, BASE_DEC, VALS(rr_mif_pv_vals), 0x80,
NULL, HFILL }
},
{ &hf_rr_freq_ofs_fi,
{ "FI", "gmr1.rr.frequency_offset.fi",
FT_UINT8, BASE_DEC, VALS(rr_freq_ofs_fi_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_freq_ofs_value,
{ "Frequency Offset value", "gmr1.rr.frequency_offset.value",
FT_INT16, BASE_CUSTOM, CF_FUNC(rr_freq_ofs_value_fmt), 0x00,
NULL, HFILL }
},
{ &hf_rr_freq_ofs_spare,
{ "Spare", "gmr1.rr.frequency_offset.spare",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_page_info_msc_id,
{ "MSC ID", "gmr1.rr.paging_info.msc_id",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_rr_page_info_chan_needed,
{ "Channel Needed", "gmr1.rr.paging_info.chan_needed",
FT_UINT8, BASE_DEC, VALS(rr_page_info_chan_needed_vals), 0x03,
NULL, HFILL }
},
{ &hf_rr_pos_display_flag,
{ "Display Information Flag", "gmr1.rr.pos_display.flag",
FT_UINT8, BASE_DEC, VALS(rr_pos_display_flag_vals), 0xf0,
NULL, HFILL }
},
{ &hf_rr_pos_display_text,
{ "Country and Region name", "gmr1.rr.pos_display.text",
FT_STRING, STR_UNICODE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pos_upd_info_v,
{ "Valid", "gmr1.rr.pos_upd_info.valid",
FT_UINT8, BASE_DEC, VALS(rr_pos_upd_info_v_vals), 0x01,
NULL, HFILL }
},
{ &hf_rr_pos_upd_info_dist,
{ "GPS Update Distance", "gmr1.rr.pos_upd_info.distance",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_pos_upd_info_dist_fmt), 0xfe,
NULL, HFILL }
},
{ &hf_rr_pos_upd_info_time,
{ "GPS Update Timer", "gmr1.rr.pos_upd_info.time",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_pos_upd_info_time_fmt), 0xff,
NULL, HFILL }
},
{ &hf_rr_bcch_carrier_arfcn,
{ "ARFCN", "gmr1.rr.bcch_carrier.arfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_bcch_carrier_si,
{ "Satellite Indication", "gmr1.rr.bcch_carrier.si",
FT_UINT8, BASE_DEC, VALS(rr_bcch_carrier_si_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_bcch_carrier_ri,
{ "Reselection Indication", "gmr1.rr.bcch_carrier.ri",
FT_UINT8, BASE_DEC, VALS(rr_bcch_carrier_ri_vals), 0x00,
NULL, HFILL }
},
{ &hf_rr_bcch_carrier_spare,
{ "Spare", "gmr1.rr.bcch_carrier.spare",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_reject_cause,
{ "Cause", "gmr1.rr.reject_cause.cause",
FT_UINT8, BASE_DEC, VALS(rr_reject_cause_vals), 0xfc,
NULL, HFILL }
},
{ &hf_rr_reject_cause_b,
{ "BCCH Carrier IE presence", "gmr1.rr.reject_cause.b",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x01,
NULL, HFILL }
},
{ &hf_rr_gps_timestamp,
{ "GPS timestamp", "gmr1.rr.gps_timestamp",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rr_gps_timestamp_fmt), 0xffff,
NULL, HFILL }
},
{ &hf_rr_gps_power_control_params,
{ "Power Control Parameters", "gmr1.rr.power_control_params",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rr_tmsi_avail_msk_tmsi[0],
{ "TMSI 1 Presence", "gmr1.rr.tmsi_avail_msk.tmsi1",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x10,
NULL, HFILL }
},
{ &hf_rr_tmsi_avail_msk_tmsi[1],
{ "TMSI 2 Presence", "gmr1.rr.tmsi_avail_msk.tmsi2",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x20,
NULL, HFILL }
},
{ &hf_rr_tmsi_avail_msk_tmsi[2],
{ "TMSI 3 Presence", "gmr1.rr.tmsi_avail_msk.tmsi3",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x40,
NULL, HFILL }
},
{ &hf_rr_tmsi_avail_msk_tmsi[3],
{ "TMSI 4 Presence", "gmr1.rr.tmsi_avail_msk.tmsi4",
FT_UINT8, BASE_DEC, VALS(rr_gen_ie_presence_vals), 0x80,
NULL, HFILL }
},
{ &hf_rr_gps_almanac_pn,
{ "Page Number", "gmr1.rr.gps_almanac.pn",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_gps_almanac_pn_fmt), 0xf8,
"See ICD-GPS-200", HFILL }
},
{ &hf_rr_gps_almanac_wn,
{ "Word Number", "gmr1.rr.gps_almanac.wn",
FT_UINT8, BASE_DEC, NULL, 0x07,
"See ICD-GPS-200", HFILL }
},
{ &hf_rr_gps_almanac_word,
{ "GPS Almanac Word", "gmr1.rr.gps_almanac.word",
FT_UINT24, BASE_HEX, NULL, 0x00,
"See ICD-GPS-200", HFILL }
},
{ &hf_rr_gps_almanac_sfn,
{ "Sub Frame Number", "gmr1.rr.gps_almanac.sfn",
FT_UINT8, BASE_DEC, VALS(rr_gps_almanac_sfn_vals), 0x80,
"See ICD-GPS-200", HFILL }
},
{ &hf_rr_gps_almanac_co,
{ "CO", "gmr1.rr.gps_almanac.co",
FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL }
},
{ &hf_rr_gps_almanac_spare,
{ "Spare", "gmr1.rr.gps_almanac.spare",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rr_msc_id,
{ "MSC ID", "gmr1.rr.msc_id",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_rr_msc_id_spare,
{ "Spare", "gmr1.rr.msc_id.spare",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }
},
{ &hf_rr_gps_discr,
{ "GPS Position field CRC-16", "gmr1.rr.gps_discriminator",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_3_prm_rlc_mode,
{ "RLC Mode", "gmr1.rr.pkt_imm_ass_3_prm",
FT_UINT8, BASE_DEC, VALS(rr_pkt_imm_ass_3_prm_rlc_mode_vals), 0x01,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_3_prm_spare,
{ "Spare", "gmr1.rr.pkt_imm_ass_3_prm.spare",
FT_UINT8, BASE_DEC, NULL, 0x1e,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_3_prm_dl_tfi,
{ "Downlink TFI", "gmr1.rr.pkt_imm_ass_3_prm.tfi",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Temporary Flow Identifier", HFILL }
},
{ &hf_rr_pkt_imm_ass_3_prm_start_fn,
{ "Start Framenumber", "gmr1.rr.pkt_imm_ass_3_prm.start_fn",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_3_prm_mac_slot_alloc,
{ "MAC-slot Allocation", "gmr1.rr.pkt_imm_ass_3_prm.mac_slot_alloc",
FT_UINT8, BASE_HEX, NULL, 0xff,
"LSB=slot 0, MSB=slot 7", HFILL }
},
{ &hf_rr_pkt_freq_prm_arfcn,
{ "ARFCN", "gmr1.rr.pkt_freq_prm.arfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pkt_freq_prm_dl_freq_plan_id,
{ "Downlink Freq. Plan ID", "gmr1.rr.pkt_freq_prm.dl_freq_plan_id",
FT_UINT8, BASE_DEC, VALS(rr_pkt_freq_prm_dl_freq_plan_id_vals), 0x08,
NULL, HFILL }
},
{ &hf_rr_pkt_freq_prm_dl_bw,
{ "Downlink Bandwidth", "gmr1.rr.pkt_freq_prm.dl_bw",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_pkt_freq_prm_xx_bw_fmt), 0x70,
NULL, HFILL }
},
{ &hf_rr_pkt_freq_prm_ul_freq_dist,
{ "Uplink Freq. Distance", "gmr1.rr.pkt_freq_prm.ul_freq_dist",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pkt_freq_prm_ul_bw,
{ "Uplink Bandwidth", "gmr1.rr.pkt_freq_prm.ul_bw",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_pkt_freq_prm_xx_bw_fmt), 0x70,
NULL, HFILL }
},
{ &hf_rr_pkt_freq_prm_spare,
{ "Spare", "gmr1.rr.pkt_freq_prm.spare",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_spare1,
{ "Spare", "gmr1.rr.pkt_imm_ass_2_prm.ac.spare1",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_final_alloc,
{ "Final Allocation", "gmr1.rr.pkt_imm_ass_2_prm.ac.final_alloc",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_usf_granularity,
{ "USF Granularity", "gmr1.rr.pkt_imm_ass_2_prm.ac.usf_granularity",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_dl_ctl_mac_slot,
{ "Downlink Control MAC-slot", "gmr1.rr.pkt_imm_ass_2_prm.ac.dl_ctl_mac_slot",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_mac_mode,
{ "MAC mode", "gmr1.rr.pkt_imm_ass_2_prm.ac.mac_mode",
FT_UINT8, BASE_DEC, VALS(rr_pkt_imm_ass_2_prm_ac_mac_mode_vals), 0xc0,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_start_fn,
{ "Starting Frame Number", "gmr1.rr.pkt_imm_ass_2_prm.ac.start_fn",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_rlc_dblk_gnt,
{ "RLC Data Blocks Granted", "gmr1.rr.pkt_imm_ass_2_prm.ac.rlc_dblk_gnt",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_mcs,
{ "MCS", "gmr1.rr.pkt_imm_ass_2_prm.ac.mcs",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_tfi,
{ "TFI", "gmr1.rr.pkt_imm_ass_2_prm.ac.tfi",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_spare2,
{ "Spare", "gmr1.rr.pkt_imm_ass_2_prm.ac.spare2",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_ac_mac_slot_alloc,
{ "MAC-slot Allocation", "gmr1.rr.pkt_imm_ass_2_prm.ac.mac_slot_alloc",
FT_UINT8, BASE_HEX, NULL, 0xff,
"LSB=slot 0, MSB=slot 7", HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_chan_mcs_cmd,
{ "Channel MCS Command", "gmr1.rr.pkt_imm_ass_2_prm.d.chan_mcs_cmd",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_chan_mcs_cmd_pnb512,
{ "Channel MCS Command PNB 5,12", "gmr1.rr.pkt_imm_ass_2_prm.d.chan_mcs_cmd_pnb512",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_spare1,
{ "Spare", "gmr1.rr.pkt_imm_ass_2_prm.d.spare1",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_rlc_dblk_gnt,
{ "RLC Data Blocks Granted", "gmr1.rr.pkt_imm_ass_2_prm.d.rlc_dblk_gnt",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_spare2,
{ "Spare", "gmr1.rr.pkt_imm_ass_2_prm.d.spare2",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_tfi,
{ "TFI", "gmr1.rr.pkt_imm_ass_2_prm.d.tfi",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_usf_granularity,
{ "USF Granularity", "gmr1.rr.pkt_imm_ass_2_prm.ac.usf_granularity",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_rr_pkt_imm_ass_2_prm_d_mac_slot_alloc,
{ "MAC-slot Allocation", "gmr1.rr.pkt_imm_ass_2_prm.d.mac_slot_alloc",
FT_UINT8, BASE_HEX, NULL, 0xff,
"LSB=slot 0, MSB=slot 7", HFILL }
},
{ &hf_rr_usf_value,
{ "Uplink state flag (USF)", "gmr1.rr.usf.value",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rr_usf_spare,
{ "Spare", "gmr1.rr.usf.spare",
FT_UINT24, BASE_DEC, NULL, 0xffffc0,
NULL, HFILL }
},
{ &hf_rr_timing_adv_idx_value,
{ "TAI Value", "gmr1.rr.timing_adv_idx.tai",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_rr_timing_adv_idx_spare,
{ "Spare", "gmr1.rr.timing_adv_idx.spare",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_rr_tlli,
{ "TLLI", "gmr1.rr.tlli",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rr_pkt_pwr_ctrl_prm_par,
{ "Power Attenuation Request (PAR)", "gmr1.rr.pkt_pwr_ctrl_prm.par",
FT_UINT8, BASE_CUSTOM, CF_FUNC(rr_pkt_pwr_ctrl_prm_par_fmt), 0x3f,
NULL, HFILL }
},
{ &hf_rr_pkt_pwr_ctrl_prm_spare,
{ "Spare", "gmr1.rr.pkt_pwr_ctrl_prm.spare",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_rr_persistence_lvl[0],
{ "for Radio priority 1", "gmr1.rr.persistence_lvl.p1",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_rr_persistence_lvl[1],
{ "for Radio priority 2", "gmr1.rr.persistence_lvl.p2",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_rr_persistence_lvl[2],
{ "for Radio priority 3", "gmr1.rr.persistence_lvl.p3",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_rr_persistence_lvl[3],
{ "for Radio priority 4", "gmr1.rr.persistence_lvl.p4",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_rr_protocol_discriminator,
{ "Protocol Discriminator", "gmr1.rr.protocol_discriminator",
FT_UINT8, BASE_DEC, VALS(gmr1_pd_vals), 0x0,
NULL, HFILL }
},
{ &hf_rr_message_elements,
{ "Message elements", "gmr1.rr.message_elements",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
#define NUM_INDIVIDUAL_ELEMS 2
static gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GMR1_IE_RR +
NUM_GMR1_MSG_RR];
unsigned int last_offset, i;
ett[0] = &ett_msg_ccch;
ett[1] = &ett_rr_pd;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i<NUM_GMR1_IE_RR; i++,last_offset++) {
ett_gmr1_ie_rr[i] = -1;
ett[last_offset] = &ett_gmr1_ie_rr[i];
}
for (i=0; i<NUM_GMR1_MSG_RR; i++,last_offset++) {
ett_msg_rr[i] = -1;
ett[last_offset] = &ett_msg_rr[i];
}
proto_register_subtree_array(ett, array_length(ett));
proto_gmr1_rr = proto_register_protocol("GEO-Mobile Radio (1) RR", "GMR-1 RR", "gmr1.rr");
proto_register_field_array(proto_gmr1_rr, hf, array_length(hf));
proto_gmr1_ccch = proto_register_protocol("GEO-Mobile Radio (1) CCCH", "GMR-1 CCCH", "gmr1.ccch");
register_dissector("gmr1_ccch", dissect_gmr1_ccch, proto_gmr1_ccch);
}
void
proto_reg_handoff_gmr1_rr(void)
{
data_handle = find_dissector("data");
}
