static void
dissect_gmr1_rach_kls1(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *root_tree,
int *is_moc, int *is_pdt)
{
proto_tree *tree = NULL;
proto_item *ec_item = NULL;
proto_tree *ec_tree = NULL;
guint8 ec;
tree = proto_tree_add_subtree(
root_tree, tvb, 0, 2,
ett_rach_kls1, NULL, "Class-1 informations");
proto_tree_add_item(tree, hf_rach_prio,
tvb, offset, 1, ENC_BIG_ENDIAN);
ec = (tvb_get_guint8(tvb, offset) >> 1) & 0x1f;
*is_moc = !!(ec & 0x10);
*is_pdt = (ec == 14);
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
else if (ec == 7)
{
proto_tree_add_item(tree, hf_rach_est_cause,
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
gint32 sv = v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.5f %s (%d)",
abs(sv) / 2912.7f, sv < 0 ? "S" : "N", sv);
}
static void
rach_gps_pos_long_fmt(gchar *s, guint32 v)
{
gint32 sv = v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%.5f %s (%d)",
abs(sv) / 2912.70555f, sv < 0 ? "W" : "E", sv);
}
static void
dissect_gmr1_rach_gps_pos(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 lat, lng;
lat = (tvb_get_ntohl(tvb, offset) >> 12) & 0x7ffff;
lng = tvb_get_ntohl(tvb, offset + 1) & 0xfffff;
if (lat == 0x40000) {
proto_tree_add_int_format(tree, hf_rach_gps_pos_lat, tvb, offset, 5, lat,
"NULL GPS Position (latitude == 0x40000)");
return;
} else if (lng == 0x80000) {
proto_tree_add_int_format(tree, hf_rach_gps_pos_long, tvb, offset, 5, lng,
"NULL GPS Position (longitude == 0x80000)");
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
if (v <= 999) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%03d", v);
} else if (v == 1023) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"All digits in the preceding group are valid (%d)", v);
} else if (v == 1022) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"First two digits in the preceding group are valid, "
"and the third digit (i.e. 0) is padding (%d)", v);
} else if (v == 1021) {
g_snprintf(s, ITEM_LABEL_LENGTH,
"First digit in the preceding group is valid, and "
"the second and third 0s are padding (%d)", v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid (%d)", v);
}
}
static void
rach_dialed_num_grp5_fmt(gchar *s, guint32 v)
{
if (v >= 1100 && v <= 1199) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%02d (%d)", v - 1100, v);
} else if (v >= 1200 && v <= 1209) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%01d (%d)", v - 1200, v);
} else {
rach_dialed_num_grp1234_fmt(s, v);
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
int rv, i, done;
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
rv = 0;
done = 0;
for (i=0; i<4; i++)
{
if (grp[i+1] <= 999)
{
rv += g_snprintf(s + rv, slen - rv, "%03d", grp[i]);
}
else if (grp[i+1] == 1023)
{
rv += g_snprintf(s + rv, slen - rv, "%03d", grp[i]);
done = 1;
break;
}
else if (grp[i+1] == 1022)
{
rv += g_snprintf(s + rv, slen - rv, "%02d", grp[i] / 10);
done = 1;
break;
}
else if (grp[i+1] == 1021)
{
rv += g_snprintf(s + rv, slen - rv, "%01d", grp[i] / 100);
done = 1;
break;
}
else if ((i==3) && (grp[i+1] >= 1100) && (grp[i+1] <= 1209))
{
rv += g_snprintf(s + rv, slen - rv, "%03d", grp[i]);
}
else
{
return g_snprintf(s, slen, "(Invalid)");
}
}
if (!done) {
if (grp[4] <= 999)
{
rv += g_snprintf(s + rv, slen - rv, "%03d", grp[4]);
}
else if (grp[4] >= 1100 && grp[4] <= 1199)
{
rv += g_snprintf(s + rv, slen - rv, "%02d", grp[4] - 1100);
}
else if (grp[4] >= 1200 && grp[4] <= 1209)
{
rv += g_snprintf(s + rv, slen - rv, "%01d", grp[4] - 1200);
}
else
{
return g_snprintf(s, slen, "(Invalid)");
}
}
return rv;
}
static void
dissect_gmr1_rach_kls2(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *root_tree,
int is_moc)
{
proto_tree *tree = NULL;
proto_item *dialed_num_item = NULL;
proto_tree *dialed_num_tree = NULL, *gps_pos_tree = NULL;
tree = proto_tree_add_subtree(
root_tree, tvb, 2, 16,
ett_rach_kls2, NULL, "Class-2 informations");
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
dissect_gmprs_rach_type1_kls2(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *root_tree, int is_pdt)
{
proto_tree *tree = NULL;
proto_tree *gps_pos_tree = NULL;
guint8 term_type;
int is_class_d;
tree = proto_tree_add_subtree(
root_tree, tvb, 2, 16,
ett_rach_gmprs_type1_kls2, NULL, "GmPRS Type-1 Class-2 informations");
proto_tree_add_split_bits_item_ret_val(
tree, hf_rach_gmprs_term_type,
tvb, offset << 3,
rach_gmprs_type1_term_type_crumbs,
NULL);
term_type = ((tvb_get_guint8(tvb, offset) >> 1) & 0x78 ) |
( tvb_get_guint8(tvb, offset + 3) & 0x07);
is_class_d = (term_type == 0x0d) ||
(term_type == 0x0e) ||
(term_type == 0x0f);
if (is_class_d) {
proto_tree_add_item(tree, hf_rach_gmprs_dl_peak_tput,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_reserved1,
tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_rach_sp_hplmn_id,
tvb, offset, 3, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_rach_gmprs_radio_prio,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_spare1,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_pd,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_tlli,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
if (is_pdt) {
proto_tree_add_split_bits_item_ret_val(
tree, hf_rach_gmprs_num_rlc_blks,
tvb, (offset + 8) << 3,
rach_gmprs_num_rlc_blks_crumbs,
NULL);
proto_tree_add_item(tree, is_class_d ?
hf_rach_gmprs_ul_peak_tput :
hf_rach_gmprs_peak_tput,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_spare2,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_rach_gps_timestamp,
tvb, offset + 8, 2, ENC_BIG_ENDIAN);
}
gps_pos_tree = proto_tree_add_subtree(
tree, tvb, offset + 10, 5,
ett_rach_gps_pos, NULL, "GPS Position");
dissect_gmr1_rach_gps_pos(tvb, offset + 10, pinfo, gps_pos_tree);
proto_tree_add_item(tree, hf_rach_gmprs_rlc_mode,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_llc_mode,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_spare3,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gmprs_rach_type2_kls2(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *root_tree)
{
proto_tree *tree = NULL;
proto_tree *gps_pos_tree = NULL;
guint8 req_type;
tree = proto_tree_add_subtree(
root_tree, tvb, 2, 16,
ett_rach_gmprs_type2_kls2, NULL, "GmPRS Type-2 Class-2 informations");
proto_tree_add_split_bits_item_ret_val(
tree, hf_rach_gmprs_term_type,
tvb, offset << 3,
rach_gmprs_type2_term_type_crumbs,
NULL);
proto_tree_add_item(tree, hf_rach_sp_hplmn_id,
tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_pd,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_msc_id,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_gmprs_tlli,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
req_type = tvb_get_guint8(tvb, offset + 8) & 0x1f;
if ((req_type & 0x1c) == 0) {
proto_item *rt_item = proto_tree_add_item(
tree, hf_rach_gmprs_req_type_pag_resp,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree *rt_tree = proto_item_add_subtree(rt_item, ett_rach_gmprs_req_type);
col_append_str(pinfo->cinfo, COL_INFO, "Paging response ");
proto_tree_add_item(rt_tree, hf_rach_gmprs_chan_needed,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_rach_gmprs_req_type,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(req_type, rach_gmprs_req_type_vals, "Unknown (%u)"));
}
proto_tree_add_item(tree, hf_rach_software_version,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_spare,
tvb, offset + 9, 1, ENC_BIG_ENDIAN);
gps_pos_tree = proto_tree_add_subtree(
tree, tvb, offset + 10, 5,
ett_rach_gps_pos, NULL, "GPS Position");
dissect_gmr1_rach_gps_pos(tvb, offset + 10, pinfo, gps_pos_tree);
proto_tree_add_item(tree, hf_rach_gci,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_r,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_rach_o,
tvb, offset + 15, 1, ENC_BIG_ENDIAN);
}
static int
dissect_gmr1_rach(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
const int RACH_IE_CLASS1 = (1 << 0);
const int RACH_IE_CLASS2_GMR1 = (1 << 1);
const int RACH_IE_CLASS2_GMPRS_TYPE1 = (1 << 2);
const int RACH_IE_CLASS2_GMPRS_TYPE2 = (1 << 3);
proto_item *rach_item;
proto_tree *rach_tree;
const char *desc;
int len, is_moc, is_pdt, ies;
len = tvb_reported_length(tvb);
desc = "GMR-1 Channel Request (RACH)";
ies = 0;
if (len == 18) {
guint8 ec = (tvb_get_guint8(tvb, 0) >> 1) & 0x1f;
ies |= RACH_IE_CLASS1;
if ((ec == 13) || (ec == 14)) {
desc = "GMR-1 GmPRS Channel Request Type 1 (RACH)";
ies |= RACH_IE_CLASS2_GMPRS_TYPE1;
} else if (ec == 7) {
desc = "GMR-1 GmPRS Channel Request Type 2 (RACH)";
ies |= RACH_IE_CLASS2_GMPRS_TYPE2;
} else if (ec == 12) {
ies |= RACH_IE_CLASS2_GMR1;
} else {
ies |= RACH_IE_CLASS2_GMR1;
}
}
rach_item = proto_tree_add_protocol_format(
tree, proto_gmr1_rach, tvb, 0, len, "%s", desc);
rach_tree = proto_item_add_subtree(rach_item, ett_rach_msg);
if (!ies) {
col_append_str(pinfo->cinfo, COL_INFO, "(Invalid)");
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
col_append_str(pinfo->cinfo, COL_INFO, "(RACH) ");
if (ies & RACH_IE_CLASS1)
dissect_gmr1_rach_kls1(tvb, 0, pinfo, rach_tree, &is_moc, &is_pdt);
if (ies & RACH_IE_CLASS2_GMR1)
dissect_gmr1_rach_kls2(tvb, 2, pinfo, rach_tree, is_moc);
if (ies & RACH_IE_CLASS2_GMPRS_TYPE1)
dissect_gmprs_rach_type1_kls2(tvb, 2, pinfo, rach_tree, is_pdt);
if (ies & RACH_IE_CLASS2_GMPRS_TYPE2)
dissect_gmprs_rach_type2_kls2(tvb, 2, pinfo, rach_tree);
return tvb_captured_length(tvb);
}
void
proto_register_gmr1_rach(void)
{
static hf_register_info hf[] = {
{ &hf_rach_prio,
{ "Priority", "gmr1.rach.priority",
FT_BOOLEAN, 8, TFS(&rach_prio_tfs), 0x01,
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
FT_BOOLEAN, 8, TFS(&rach_gps_pos_cpi_tfs), 0x80,
"Current Position Indicator", HFILL }
},
{ &hf_rach_gps_pos_lat,
{ "Latitude", "gmr1.rach.gps_pos.latitude",
FT_INT24, BASE_CUSTOM, CF_FUNC(rach_gps_pos_lat_fmt), 0x7ffff0,
NULL, HFILL }
},
{ &hf_rach_gps_pos_long,
{ "Longitude", "gmr1.rach.gps_pos.longitude",
FT_INT24, BASE_CUSTOM, CF_FUNC(rach_gps_pos_long_fmt), 0x0fffff,
NULL, HFILL }
},
{ &hf_rach_mes_pwr_class,
{ "MES Power Class", "gmr1.rach.mes_power_class",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"See GMR 05.005 for infos", HFILL }
},
{ &hf_rach_sp_hplmn_id,
{ "SP/HPLMN ID", "gmr1.rach.sp_hplmn_id",
FT_UINT24, BASE_CUSTOM, CF_FUNC(rach_sp_hplmn_id_fmt), 0x0fffff,
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
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_dialed_num_grp1234_fmt), 0x3ff0,
NULL, HFILL }
},
{ &hf_rach_number_grp2,
{ "Group 2", "gmr1.rach.number.grp2",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_dialed_num_grp1234_fmt), 0x0ffc,
NULL, HFILL }
},
{ &hf_rach_number_grp3,
{ "Group 3", "gmr1.rach.number.grp3",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_dialed_num_grp1234_fmt), 0x03ff,
NULL, HFILL }
},
{ &hf_rach_number_grp4,
{ "Group 4", "gmr1.rach.number.grp4",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_dialed_num_grp1234_fmt), 0xffc0,
NULL, HFILL }
},
{ &hf_rach_number_grp5,
{ "Group 5", "gmr1.rach.number.grp5",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_dialed_num_grp5_fmt), 0x3ff8,
NULL, HFILL }
},
{ &hf_rach_msc_id,
{ "MSC ID", "gmr1.rach.msc_id",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_rach_gps_timestamp,
{ "GPS Timestamp", "gmr1.rach.gps_timestamp",
FT_UINT16, BASE_CUSTOM, CF_FUNC(rach_gps_timestamp_fmt), 0xffff,
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
FT_BOOLEAN, 8, TFS(&rach_gci_tfs), 0x01,
"GPS Capability Indicator", HFILL }
},
{ &hf_rach_r,
{ "R", "gmr1.rach.r",
FT_BOOLEAN, 8, TFS(&rach_r_tfs), 0x02,
"See GMR 04.008 10.1.8 for full description" , HFILL }
},
{ &hf_rach_o,
{ "O", "gmr1.rach.o",
FT_BOOLEAN, 8, TFS(&rach_o_tfs), 0x04,
"See GMR 04.008 10.1.8 for full description", HFILL }
},
{ &hf_rach_number_type,
{ "Number Type", "gmr1.rach.number_type",
FT_UINT8, BASE_DEC, VALS(rach_number_type_vals), 0x07,
"For MO Call only", HFILL }
},
{ &hf_rach_gmprs_term_type,
{ "GmPRS Terminal Type", "gmr1.rach.gmprs_term_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &rach_gmprs_term_type_ext_vals, 0x00,
"See GMR-1 3G 45.002 Annex C for infos", HFILL }
},
{ &hf_rach_gmprs_radio_prio,
{ "Radio Priority", "gmr1.rach.gmprs_radio_prio",
FT_UINT8, BASE_DEC, VALS(rach_gmprs_radio_prio_vals), 0x18,
"See GMPRS-1 04.060 for infos", HFILL }
},
{ &hf_rach_gmprs_tlli,
{ "TLLI", "gmr1.rach.gmprs_tlli",
FT_UINT32, BASE_HEX, NULL, 0x00,
"See GMPRS-1 04.060 for infos", HFILL }
},
{ &hf_rach_gmprs_num_rlc_blks,
{ "Number of RLC blocks", "gmr1.rach.gmprs_num_rlc_blks",
FT_UINT16, BASE_DEC, NULL, 0x00,
"See GMPRS-1 04.060 12.31 for infos", HFILL }
},
{ &hf_rach_gmprs_peak_tput,
{ "Peak Throughput", "gmr1.rach.gmprs_peak_tput",
FT_UINT8, BASE_DEC, NULL, 0x3c,
"See GMPRS-1 04.060 for infos", HFILL }
},
{ &hf_rach_gmprs_dl_peak_tput,
{ "DL Peak Throughput", "gmr1.rach.gmprs_dl_peak_tput",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"See 3GPP TS 23.060 for infos", HFILL }
},
{ &hf_rach_gmprs_ul_peak_tput,
{ "UL Peak Throughput", "gmr1.rach.gmprs_ul_peak_tput",
FT_UINT8, BASE_DEC, NULL, 0x3c,
"See 3GPP TS 23.060 for infos", HFILL }
},
{ &hf_rach_gmprs_rlc_mode,
{ "RLC mode", "gmr1.rach.gmprs_rlc_mode",
FT_BOOLEAN, 8, TFS(&rach_gmprs_rlc_mode_tfs), 0x01,
NULL, HFILL }
},
{ &hf_rach_gmprs_llc_mode,
{ "LLC mode", "gmr1.rach.gmprs_llc_mode",
FT_BOOLEAN, 8, TFS(&rach_gmprs_llc_mode_tfs), 0x02,
NULL, HFILL }
},
{ &hf_rach_gmprs_spare1,
{ "Spare", "gmr1.rach.gmprs_spare1",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_rach_gmprs_spare2,
{ "Spare", "gmr1.rach.gmprs_spare2",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_rach_gmprs_spare3,
{ "Spare", "gmr1.rach.gmprs_spare3",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_rach_gmprs_reserved1,
{ "Reserved", "gmr1.rach.gmprs_reserved1",
FT_UINT16, BASE_HEX, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_rach_gmprs_req_type,
{ "Request Type", "gmr1.rach.gmprs_req_type",
FT_UINT8, BASE_DEC, VALS(rach_gmprs_req_type_vals), 0x1f,
NULL, HFILL }
},
{ &hf_rach_gmprs_req_type_pag_resp,
{ "Request Type", "gmr1.rach.gmprs_req_type.pag_resp",
FT_UINT8, BASE_DEC, VALS(rach_gmprs_req_type_pag_resp_vals), 0x1c,
NULL, HFILL }
},
{ &hf_rach_gmprs_chan_needed,
{ "Channel Needed", "gmr1.rach.gmprs_chan_needed",
FT_UINT8, BASE_DEC, VALS(rach_chan_needed_vals), 0x03,
"Echoed from Paging Request", HFILL }
},
};
static gint *ett[] = {
&ett_rach_msg,
&ett_rach_kls1,
&ett_rach_kls2,
&ett_rach_gmprs_type1_kls2,
&ett_rach_gmprs_type2_kls2,
&ett_rach_est_cause,
&ett_rach_dialed_num,
&ett_rach_gps_pos,
&ett_rach_gmprs_req_type,
};
proto_gmr1_rach = proto_register_protocol("GEO-Mobile Radio (1) RACH", "GMR-1 RACH", "gmr1.rach");
proto_register_field_array(proto_gmr1_rach, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gmr1_rach", dissect_gmr1_rach, proto_gmr1_rach);
}
