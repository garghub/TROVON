static void
seg3a_latitude_fmt(gchar *s, guint32 v)
{
gint32 sv = (gint32)v;
char c;
if (sv < 0) {
c = 'S';
sv = -sv;
} else
c = 'N';
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f %c (%d)", sv / 10.0f, c, sv);
}
static void
seg3a_longitude_fmt(gchar *s, guint32 v)
{
gint32 sv;
char c;
if (v < 1800) {
c = 'W';
sv = v;
} else {
c = 'E';
sv = 3600 - v;
}
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f %c (%u)", sv / 10.0f, c, v);
}
static void
seg3a_satpos_radius_fmt(gchar *s, guint32 v)
{
gint32 sv = (gint32)v;
gint32 a = (42162 * 1000) + (sv * 5);
g_snprintf(s, ITEM_LABEL_LENGTH, "%.3lf km (%u)", a / 1000.0, sv);
}
static void
seg3a_miscinfo_sb_reselection_timer_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes (%u)", v*4, v);
}
static void
dissect_gmr1_bcch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *bcch_item = NULL;
proto_tree *bcch_tree = NULL;
csnStream_t ar;
gboolean is_si1;
col_append_str(pinfo->cinfo, COL_INFO, "(BCCH) ");
is_si1 = tvb_get_bits8(tvb, 0, 5) & 1;
bcch_item = proto_tree_add_protocol_format(
tree, proto_gmr1_bcch, tvb, 0, -1,
"GMR-1 BCCH - System Information type %d", is_si1 ? 1 : 2
);
bcch_tree = proto_item_add_subtree(bcch_item, ett_gmr1_bcch);
csnStreamInit(&ar, 0, tvb_length(tvb)*8);
if (is_si1) {
SystemInformation1_t *data;
data = ep_alloc(sizeof(SystemInformation1_t));
csnStreamDissector(bcch_tree, &ar, CSNDESCR(SystemInformation1_t), tvb, data, ett_gmr1_bcch);
col_append_fstr(
pinfo->cinfo, COL_INFO,
"System Information 1: Segment 1A, %s",
SI1_SegmentChoice[data->SegmentType].descr.sz
);
} else {
SystemInformation2_t *data;
data = ep_alloc(sizeof(SystemInformation2_t));
csnStreamDissector(bcch_tree, &ar, CSNDESCR(SystemInformation2_t), tvb, data, ett_gmr1_bcch);
col_append_fstr(
pinfo->cinfo, COL_INFO,
"System Information 2: %s",
SI2_SegmentChoice[data->SegmentType].descr.sz
);
}
}
void
proto_register_gmr1_bcch(void)
{
static hf_register_info hf[] = {
{ &hf_seg1a_class_2_version,
{ "Class 2 version", "gmr1.bcch.seg1a.class_2_version",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Version number for current Class 2 information", HFILL }
},
{ &hf_seg1a_class_3_version,
{ "Class 3 version", "gmr1.bcch.seg1a.class_3_version",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Version number for current Class 3 information", HFILL }
},
{ &hf_seg1a_syncinfo_sb_frame_ts_offset,
{ "SB_FRAME_TS_OFFSET", "gmr1.bcch.seg1a.syncinfo.sb_frame_ts_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_syncinfo_sb_symbol_offset,
{ "SB_SYMBOL_OFFSET", "gmr1.bcch.seg1a.syncinfo.sb_symbol_offset",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_syncinfo_sa_freq_offset,
{ "SA_FREQ_OFFSET", "gmr1.bcch.seg1a.syncinfo.sa_freq_offset",
FT_UINT8, BASE_CUSTOM, seg1a_syncinfo_sa_freq_offset_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_rachctrl_max_retrans,
{ "Max Retrans", "gmr1.bcch.seg1a.rachctrl.max_retrans",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_rachctrl_acc[15],
{ "AC15", "gmr1.bcch.seg1a.rachctrl.ac15",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 15 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[14],
{ "AC14", "gmr1.bcch.seg1a.rachctrl.ac14",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 14 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[13],
{ "AC13", "gmr1.bcch.seg1a.rachctrl.ac13",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 13 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[12],
{ "AC12", "gmr1.bcch.seg1a.rachctrl.ac12",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 12 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[11],
{ "AC11", "gmr1.bcch.seg1a.rachctrl.ac11",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 11 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[10],
{ "EC10", "gmr1.bcch.seg1a.rachctrl.ac10",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Emergency Class 10 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[9],
{ "AC9", "gmr1.bcch.seg1a.rachctrl.ac9",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 9 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[8],
{ "AC8", "gmr1.bcch.seg1a.rachctrl.ac8",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 8 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[7],
{ "AC7", "gmr1.bcch.seg1a.rachctrl.ac7",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 7 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[6],
{ "AC6", "gmr1.bcch.seg1a.rachctrl.ac6",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 6 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[5],
{ "AC5", "gmr1.bcch.seg1a.rachctrl.ac5",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 5 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[4],
{ "AC4", "gmr1.bcch.seg1a.rachctrl.ac4",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 4 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[3],
{ "AC3", "gmr1.bcch.seg1a.rachctrl.ac3",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 3 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[2],
{ "AC2", "gmr1.bcch.seg1a.rachctrl.ac2",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 2 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[1],
{ "AC1", "gmr1.bcch.seg1a.rachctrl.ac1",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 1 barred", HFILL }
},
{ &hf_seg1a_rachctrl_acc[0],
{ "AC0", "gmr1.bcch.seg1a.rachctrl.ac0",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_acc_vals), 0x00,
"Access Class 0 barred", HFILL }
},
{ &hf_seg1a_rachctrl_cell_bar_access,
{ "CELL_BAR_ACCESS", "gmr1.bcch.seg1a.rachctrl.cell_bar_access",
FT_UINT8, BASE_DEC, VALS(seg1a_rachctrl_cell_bar_access_vals), 0x00,
NULL, HFILL }
},
{ &hf_seg1a_miscinfo_sb_reselection_hysteresis,
{ "SB_RESELECTION_HYSTERESIS", "gmr1.bcch.seg1a.miscinfo.sb_reselection_hysteresis",
FT_UINT8, BASE_CUSTOM, segx_half_db_value_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_miscinfo_spare,
{ "Spare", "gmr1.bcch.seg1a.miscinfo.spare",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_miscinfo_priority_access_ind,
{ "Priority Access Ind", "gmr1.bcch.seg1a.miscinfo.priority_access_ind",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Reserved for future use", HFILL }
},
{ &hf_seg1a_gbch_present,
{ "GBCH Present", "gmr1.bcch.seg1a.gbch_present",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_test_gs,
{ "Test GS", "gmr1.bcch.seg1a.test_gs",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_test_gs2,
{ "Test GS2", "gmr1.bcch.seg1a.test_gs2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_spare1,
{ "Spare", "gmr1.bcch.seg1a.spare1",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_cell_bar_access_extension2,
{ "CELL_BAR_ACCESS_EXTENSION2", "gmr1.bcch.seg1a.cell_bar_access_extension2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_spare2,
{ "Spare", "gmr1.bcch.seg1a.spare2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg1a_cell_bar_access_extension,
{ "CELL_BAR_ACCESS_EXTENSION", "gmr1.bcch.seg1a.cell_bar_access_extension",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg2a_class_4_version,
{ "Class 4 version", "gmr1.bcch.seg2a.class_4_version",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Version number for current Class 4 information", HFILL }
},
{ &hf_seg2a_syncinfo_sa_sirfn_delay,
{ "SA_SIRFN_DELAY", "gmr1.bcch.seg2a.syncinfo.sa_sirfn_delay",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Delay of system information relative to superframe", HFILL }
},
{ &hf_seg2a_syncinfo_sa_bcch_stn,
{ "SA_BCCH_STN", "gmr1.bcch.seg2a.syncinfo.sa_bcch_stn",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Starting timeslot number", HFILL }
},
{ &hf_seg2a_syncinfo_superframe_num,
{ "Superframe Number", "gmr1.bcch.seg2a.syncinfo.superframe_num",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg2a_syncinfo_multiframe_num,
{ "Multiframe Number", "gmr1.bcch.seg2a.syncinfo.multiframe_num",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Multiframe number in a superframe", HFILL }
},
{ &hf_seg2a_syncinfo_mffn_high_bit,
{ "MFFN high bit", "gmr1.bcch.seg2a.syncinfo.mffn_high_bit",
FT_UINT8, BASE_DEC, NULL, 0x00,
"High bit of the TDMA FN in a multiframe", HFILL }
},
{ &hf_seg2a_selcrit_rxlev_select_min,
{ "RXLEV_SELECT_MIN", "gmr1.bcch.seg2a.selcrit.rxlev_select_min",
FT_UINT8, BASE_CUSTOM, segx_half_db_value_fmt, 0x00,
"Adjustment to threshold to camp-on system", HFILL }
},
{ &hf_seg2a_miscinfo_sb_selection_power,
{ "SB_SELECTION_POWER", "gmr1.bcch.seg2a.miscinfo.sb_selection_power",
FT_UINT8, BASE_CUSTOM, segx_half_db_value_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg2a_lainfo_sa_pch_config,
{ "SA_PCH_CONFIG", "gmr1.bcch.seg2a.lainfo.sa_pch_config",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Paging group configuration information", HFILL }
},
{ &hf_seg2a_lainfo_sa_bach_config,
{ "SA_BACH_CONFIG", "gmr1.bcch.seg2a.lainfo.sa_bach_config",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Alerting group configuration information", HFILL }
},
{ &hf_seg2a_lainfo_rach_ts_offset,
{ "RACH_TS_OFFSET", "gmr1.bcch.seg2a.lainfo.rach_ts_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Start of RACH window with respect to BCCH", HFILL }
},
{ &hf_seg2a_lainfo_n_page_occurrences,
{ "N Page Occurrences", "gmr1.bcch.seg2a.lainfo.n_page_occurrences",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of times a page shall be retransmitted after the initial transmission", HFILL }
},
{ &hf_seg2a_lainfo_imsi_attach_detach_ind,
{ "IMSI attach-detach ind", "gmr1.bcch.seg2a.lainfo.imsi_attach_detach_ind",
FT_UINT8, BASE_DEC, VALS(seg2a_lainfo_imsi_attach_detach_ind_vals), 0x00,
"Should MESs apply IMSI attach and detach procedure for this LA", HFILL }
},
{ &hf_seg2a_lainfo_ecsc_indication,
{ "ECSC indication", "gmr1.bcch.seg2a.lainfo.ecsc_indication",
FT_UINT8, BASE_DEC, VALS(seg2a_lainfo_ecsc_indication_vals), 0x00,
"Early Classmark Sending Control", HFILL }
},
{ &hf_seg2a_lainfo_si_update_ind,
{ "SI update ind", "gmr1.bcch.seg2a.lainfo.si_update_ind",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Flag for BACH reorganization. Value changes after each reorganization", HFILL }
},
{ &hf_seg3a_lai_mcc,
{ "Mobile Country Code (MCC)", "gmr1.bcch.seg3a.lai.mcc",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_lai_mnc,
{ "Mobile Network Code (MNC)", "gmr1.bcch.seg3a.lai.mnc",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_lai_lac,
{ "Location Area Code (LAC)", "gmr1.bcch.seg3a.lai.lac",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_lai_msc_id,
{ "MSC ID", "gmr1.bcch.seg3a.lai.msc_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_lai_spot_beam_id,
{ "Spot Beam ID", "gmr1.bcch.seg3a.lai.spot_beam_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_system_sat_id,
{ "Satellite ID", "gmr1.bcch.seg3a.system.sat_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_system_sys_id,
{ "System ID", "gmr1.bcch.seg3a.system.sys_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_satpos_latitude,
{ "Latitude", "gmr1.bcch.seg3a.satpos.latitude",
FT_INT8, BASE_CUSTOM, seg3a_latitude_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_satpos_longitude,
{ "Longitude", "gmr1.bcch.seg3a.satpos.longitude",
FT_UINT16, BASE_CUSTOM, seg3a_longitude_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_satpos_radius,
{ "Radius", "gmr1.bcch.seg3a.satpos.radius",
FT_INT16, BASE_CUSTOM, seg3a_satpos_radius_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_beam_latitude,
{ "Latitude", "gmr1.bcch.seg3a.beam.latitude",
FT_INT16, BASE_CUSTOM, seg3a_latitude_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_beam_longitude,
{ "Longitude", "gmr1.bcch.seg3a.beam.longitude",
FT_UINT16, BASE_CUSTOM, seg3a_longitude_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_miscinfo_sb_reselection_timer,
{ "SB_RESELECTION_TIMER", "gmr1.bcch.seg3a.sb_reselection_timer",
FT_UINT8, BASE_CUSTOM, seg3a_miscinfo_sb_reselection_timer_fmt, 0x00,
NULL, HFILL }
},
{ &hf_seg3a_spare,
{ "Spare", "gmr1.bcch.seg3a.spare",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_si_protocol_version,
{ "Protocol version", "gmr1.bcch.si.protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_si_block_type,
{ "Block Type", "gmr1.bcch.si.block_type",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_si_spare,
{ "Spare", "gmr1.bcch.si.spare",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_si1_randomization_period,
{ "Randomization Period", "gmr1.bcch.si.randomization_period",
FT_UINT8, BASE_DEC, VALS(si1_randomization_period_vals), 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_gmr1_bcch,
};
proto_gmr1_bcch = proto_register_protocol("GEO-Mobile Radio (1) BCCH", "GMR-1 BCCH", "gmr1_bcch");
proto_register_field_array(proto_gmr1_bcch, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gmr1_bcch", dissect_gmr1_bcch, proto_gmr1_bcch);
}
void
proto_reg_handoff_gmr1_bcch(void)
{
data_handle = find_dissector("data");
}
