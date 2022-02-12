static void
dissect_gmr1_rach_kls1(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree,
int *is_moc)
{
proto_item *ec_item = NULL;
proto_tree *ec_tree = NULL;
guint8 ec;
proto_tree_add_item(tree, hf_rach_prio,
tvb, offset, 1, ENC_BIG_ENDIAN);
ec = (tvb_get_guint8(tvb, offset) >> 1) & 0x1f;
*is_moc = !!(ec & 0x10);
if (ec & 0x10)
{
ec_item = proto_tree_add_item(tree, hf_rach_est_cause_moc,
tvb, offset, 1, ENC_BIG_ENDIAN);
ec_tree = proto_item_add_subtree(ec_item, ett_rach_est_cause);
col_append_str(pinfo->cinfo, COL_INFO, "Mobile Originated Call ");
proto_tree_add_item(ec_tree, hf_rach_num_plan,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else if ((ec & 0x1c) == 0x00)
{
ec_item = proto_tree_add_item(tree, hf_rach_est_cause_pag_resp,
tvb, offset, 1, ENC_BIG_ENDIAN);
ec_tree = proto_item_add_subtree(ec_item, ett_rach_est_cause);
col_append_str(pinfo->cinfo, COL_INFO, "Paging response ");
proto_tree_add_item(ec_tree, hf_rach_chan_needed,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(tree, hf_rach_est_cause,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(ec, rach_est_cause_vals, "Unknown (%u)"));
}
proto_tree_add_item(tree, hf_rach_retry_cnt,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_precorr,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_rand_ref,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
rach_gps_pos_lat_fmt(gchar *s, guint32 v)
{
gint32 sv;
if (v & (1<<18))
v |= 0xfff80000;
sv = v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.5f %s (%d)",
abs(sv) / 2912.7f, sv < 0 ? "S" : "N", sv);
}
static void
rach_gps_pos_long_fmt(gchar *s, guint32 v)
{
gint32 sv;
if (v & (1<<19))
v |= 0xfff00000;
sv = v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.5f %s (%d)",
abs(sv) / 2912.70555f, sv < 0 ? "W" : "E", sv);
}
static void
dissect_gmr1_rach_gps_pos(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 lat;
lat = (tvb_get_ntohl(tvb, offset) >> 4) & 0x7ffff;
if (lat == 0x40000) {
proto_tree_add_uint_format(tree, hf_rach_gps_pos_lat, tvb, offset, 5, 0x40000, "NULL GPS Position");
return;
}
proto_tree_add_item(tree, hf_rach_gps_pos_cpi,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gps_pos_lat,
tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gps_pos_long,
tvb, offset + 2, 3, ENC_BIG_ENDIAN);
}
static void
rach_sp_hplmn_id_fmt(gchar *s, guint32 v)
{
if (v == 0xfffff) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%05x (Null)", v);
} else if ((v & 0xf8000) == 0xf8000) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%05x (SP ID %4d)", v, v & 0x7fff);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%05x (HPLMN ID)", v);
}
}
static void
rach_dialed_num_grp1234_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%03d", v);
}
static void
rach_dialed_num_grp5_fmt(gchar *s, guint32 v)
{
if (v <= 999) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%03d", v);
} else if (v == 1023) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"All digits in the preceding group are valid (%d)", v);
} else if (v == 1022) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"First two digits in the preceding group are valid, "
"and the third digit (i.e. 0) is padding(%d)", v);
} else if (v == 1021) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"First digit in the preceding group is valid, and "
"the second and third 0s are padding(%d)", v);
} else if (v >= 1100 && v <= 1199) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%02d (%d)", v - 1100, v);
} else if (v >= 1200 && v <= 1209) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%01d (%d)", v - 1200, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid (%d)", v);
}
}
static void
rach_gps_timestamp_fmt(gchar *s, guint32 v)
{
if (v == 0xffff) {
g_snprintf(s, ITEM_LABEL_LENGTH, ">= 65535 minutes or N/A (%04x)", v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%d minutes (%04x)", v, v);
}
}
static int
_parse_dialed_number(gchar *s, int slen, tvbuff_t *tvb, int offset)
{
guint16 grp[5];
int rv;
grp[0] = ((tvb_get_guint8(tvb, offset+0) & 0x3f) << 4) |
((tvb_get_guint8(tvb, offset+1) & 0xf0) >> 4);
grp[1] = ((tvb_get_guint8(tvb, offset+1) & 0x0f) << 6) |
((tvb_get_guint8(tvb, offset+2) & 0xfc) >> 2);
grp[2] = ((tvb_get_guint8(tvb, offset+2) & 0x03) << 8) |
tvb_get_guint8(tvb, offset+3);
grp[3] = ((tvb_get_guint8(tvb, offset+4) & 0xff) << 2) |
((tvb_get_guint8(tvb, offset+5) & 0xc0) >> 6);
grp[4] = ((tvb_get_guint8(tvb, offset+5) & 0x3f) << 5) |
((tvb_get_guint8(tvb, offset+6) & 0xf8) >> 3);
rv = g_snprintf(s, slen, "%03d%03d%03d", grp[0], grp[1], grp[2]);
if (grp[4] <= 999) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%03d%03d", grp[3], grp[4]);
} else if (grp[4] == 1023) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%03d", grp[3]);
} else if (grp[4] == 1022) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%02d", grp[3] / 10);
} else if (grp[4] == 1021) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%01d", grp[3] / 100);
} else if (grp[4] >= 1100 && grp[4] <= 1199) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%03d%02d", grp[3], grp[4] - 1100);
} else if (grp[4] >= 1200 && grp[4] <= 1209) {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%03d%01d", grp[3], grp[4] - 1200);
} else {
rv += g_snprintf(s + rv, ITEM_LABEL_LENGTH,
"%03d%03d (Invalid)", grp[3], grp[4]);
}
return rv;
}
static void
dissect_gmr1_rach_kls2(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree,
int is_moc)
{
proto_item *dialed_num_item = NULL;
proto_tree *dialed_num_tree = NULL, *gps_pos_tree = NULL;
proto_tree_add_item(tree, hf_rach_mes_pwr_class,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_sp_hplmn_id,
tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_pd,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
if (is_moc) {
gchar s[32];
_parse_dialed_number(s, sizeof(s), tvb, offset + 3);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", s);
dialed_num_item = proto_tree_add_string(
tree, hf_rach_number, tvb, offset + 3, 7, s);
dialed_num_tree = proto_item_add_subtree(
dialed_num_item, ett_rach_dialed_num);
proto_tree_add_item(dialed_num_tree, hf_rach_number_grp1,
tvb, offset + 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dialed_num_tree, hf_rach_number_grp2,
tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dialed_num_tree, hf_rach_number_grp3,
tvb, offset + 5, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dialed_num_tree, hf_rach_number_grp4,
tvb, offset + 7, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dialed_num_tree, hf_rach_number_grp5,
tvb, offset + 8, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_rach_msc_id,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gps_timestamp,
tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_software_version,
tvb, offset + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_spare,
tvb, offset + 6, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_rach_gci,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_r,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_o,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
gps_pos_tree = proto_tree_add_subtree(
tree, tvb, offset + 10, 5,
ett_rach_gps_pos, NULL, "GPS Position");
dissect_gmr1_rach_gps_pos(tvb, offset + 10, pinfo, gps_pos_tree);
proto_tree_add_item(tree, hf_rach_number_type,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gmr1_rach(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *rach_item;
proto_tree *rach_tree, *kls1_tree, *kls2_tree;
int len, is_moc;
len = tvb_length(tvb);
rach_item = proto_tree_add_protocol_format(
tree, proto_gmr1_rach, tvb, 0, len,
"GMR-1 Channel Request (RACH)");
rach_tree = proto_item_add_subtree(rach_item, ett_rach_msg);
if (len != 18) {
col_append_str(pinfo->cinfo, COL_INFO, "(Invalid)");
call_dissector(data_handle, tvb, pinfo, tree);
return;
}
col_append_str(pinfo->cinfo, COL_INFO, "(RACH) ");
kls1_tree = proto_tree_add_subtree(
rach_tree, tvb, 0, 2,
ett_rach_kls1, NULL, "Class-1 informations");
dissect_gmr1_rach_kls1(tvb, 0, pinfo, kls1_tree, &is_moc);
kls2_tree = proto_tree_add_subtree(
rach_tree, tvb, 2, 16,
ett_rach_kls2, NULL, "Class-2 informations");
dissect_gmr1_rach_kls2(tvb, 2, pinfo, kls2_tree, is_moc);
}
void
proto_register_gmr1_rach(void)
{
static hf_register_info hf[] = {
{ &hf_rach_prio,
{ "Priority", "gmr1.rach.priority",
FT_UINT8, BASE_DEC, VALS(rach_prio_vals), 0x01,
NULL, HFILL }
},
{ &hf_rach_est_cause,
{ "Establishment Cause", "gmr1.rach.est_cause",
FT_UINT8, BASE_HEX, VALS(rach_est_cause_vals), 0x3e,
NULL, HFILL }
},
{ &hf_rach_est_cause_moc,
{ "Establishment Cause", "gmr1.rach.est_cause.moc",
FT_UINT8, BASE_HEX, VALS(rach_est_cause_moc_vals), 0x20,
NULL, HFILL }
},
{ &hf_rach_est_cause_pag_resp,
{ "Establishment Cause", "gmr1.rach.est_cause.pag_resp",
FT_UINT8, BASE_HEX, VALS(rach_est_cause_pag_resp_vals), 0x38,
NULL, HFILL }
},
{ &hf_rach_num_plan,
{ "Numbering Plan Identification", "gmr1.rach.numbering_plan",
FT_UINT8, BASE_DEC, VALS(rach_num_plan_vals), 0x1e,
NULL, HFILL }
},
{ &hf_rach_chan_needed,
{ "Channel Needed", "gmr1.rach.chan_needed",
FT_UINT8, BASE_DEC, VALS(rach_chan_needed_vals), 0x06,
"Echoed from Paging Request", HFILL }
},
{ &hf_rach_retry_cnt,
{ "Retry Counter", "gmr1.rach.retry_counter",
FT_UINT8, BASE_DEC, NULL, 0xc0,
"Retransmission count for current access attempt", HFILL }
},
{ &hf_rach_precorr,
{ "Precorrection Indication", "gmr1.rach.precorr_ind",
FT_UINT8, BASE_DEC, VALS(rach_precorr_vals), 0xe0,
"This is the timing correction applied to RACH while "
"sending this message. See GMR 05.010.", HFILL }
},
{ &hf_rach_rand_ref,
{ "Random Reference", "gmr1.rach.random_reference",
FT_UINT8, BASE_HEX, NULL, 0x1f,
"A random number of 5 bits", HFILL }
},
{ &hf_rach_gps_pos_cpi,
{ "CPI", "gmr1.rach.gps_pos.cpi",
FT_UINT8, BASE_DEC, VALS(rach_gps_pos_cpi_vals), 0x80,
"Current Position Indicator", HFILL }
},
{ &hf_rach_gps_pos_lat,
{ "Latitude", "gmr1.rach.gps_pos.latitude",
FT_UINT24, BASE_CUSTOM, rach_gps_pos_lat_fmt, 0x7ffff0,
NULL, HFILL }
},
{ &hf_rach_gps_pos_long,
{ "Longitude", "gmr1.rach.gps_pos.longitude",
FT_UINT24, BASE_CUSTOM, rach_gps_pos_long_fmt, 0x0fffff,
NULL, HFILL }
},
{ &hf_rach_mes_pwr_class,
{ "MES Power Class", "gmr1.rach.mes_power_class",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"See GMR 05.005 for infos", HFILL }
},
{ &hf_rach_sp_hplmn_id,
{ "SP/HPLMN ID", "gmr1.rach.sp_hplmn_id",
FT_UINT24, BASE_CUSTOM, rach_sp_hplmn_id_fmt, 0x0fffff,
NULL, HFILL }
},
{ &hf_rach_pd,
{ "PD", "gmr1.rach.pd",
FT_UINT8, BASE_DEC, VALS(rach_pd_vals), 0xc0,
"Protocol Discriminator", HFILL }
},
{ &hf_rach_number,
{ "Dialed Number", "gmr1.rach.number",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_rach_number_grp1,
{ "Group 1", "gmr1.rach.number.grp1",
FT_UINT16, BASE_CUSTOM, rach_dialed_num_grp1234_fmt, 0x3ff0,
NULL, HFILL }
},
{ &hf_rach_number_grp2,
{ "Group 2", "gmr1.rach.number.grp2",
FT_UINT16, BASE_CUSTOM, rach_dialed_num_grp1234_fmt, 0x0ffc,
NULL, HFILL }
},
{ &hf_rach_number_grp3,
{ "Group 3", "gmr1.rach.number.grp3",
FT_UINT16, BASE_CUSTOM, rach_dialed_num_grp1234_fmt, 0x03ff,
NULL, HFILL }
},
{ &hf_rach_number_grp4,
{ "Group 4", "gmr1.rach.number.grp4",
FT_UINT16, BASE_CUSTOM, rach_dialed_num_grp1234_fmt, 0xffc0,
NULL, HFILL }
},
{ &hf_rach_number_grp5,
{ "Group 5", "gmr1.rach.number.grp5",
FT_UINT16, BASE_CUSTOM, rach_dialed_num_grp5_fmt, 0x3ff8,
NULL, HFILL }
},
{ &hf_rach_msc_id,
{ "MSC ID", "gmr1.rach.msc_id",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rach_gps_timestamp,
{ "GPS Timestamp", "gmr1.rach.gps_timestamp",
FT_UINT16, BASE_CUSTOM, rach_gps_timestamp_fmt, 0xffff,
NULL, HFILL }
},
{ &hf_rach_software_version,
{ "Software Version", "gmr1.rach.software_version",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_rach_spare,
{ "Spare", "gmr1.rach.spare",
FT_UINT32, BASE_DEC, NULL, 0x01fffff8,
NULL, HFILL }
},
{ &hf_rach_gci,
{ "GCI", "gmr1.rach.gci",
FT_UINT8, BASE_DEC, VALS(rach_gci_vals), 0x01,
"GPS Capability Indicator", HFILL }
},
{ &hf_rach_r,
{ "R", "gmr1.rach.r",
FT_UINT8, BASE_DEC, NULL, 0x02,
"See GMR 04.008 10.1.8 for full description" , HFILL }
},
{ &hf_rach_o,
{ "O", "gmr1.rach.o",
FT_UINT8, BASE_DEC, NULL, 0x04,
"See GMR 04.008 10.1.8 for full description", HFILL }
},
{ &hf_rach_number_type,
{ "Number Type", "gmr1.rach.number_type",
FT_UINT8, BASE_DEC, VALS(rach_number_type_vals), 0x07,
"For MO Call only", HFILL }
},
};
static gint *ett[] = {
&ett_rach_msg,
&ett_rach_kls1,
&ett_rach_kls2,
&ett_rach_est_cause,
&ett_rach_dialed_num,
&ett_rach_gps_pos,
};
proto_gmr1_rach = proto_register_protocol("GEO-Mobile Radio (1) RACH", "GMR-1 RACH", "gmr1.rach");
proto_register_field_array(proto_gmr1_rach, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gmr1_rach", dissect_gmr1_rach, proto_gmr1_rach);
}
void
proto_reg_handoff_gmr1_rach(void)
{
data_handle = find_dissector("data");
}
