static void
prt_sa32(gchar *buff, guint32 val)
{
double deg, min, sec;
double x = (double) ((gint32) val);
x /= (double) (1UL<<30);
x *= 45.0;
deg = floor(x);
min = floor(60.0 * (x - deg));
sec = 60.0 * (60.0 * (x - deg) - min);
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.8f degrees (%.0f %.0f\' %.2f\")", x, deg, min, sec);
}
static void
prt_ba32(gchar *buff, guint32 val)
{
double deg, min, sec;
double x = (double) val;
x /= (double) (1UL<<30);
x *= 90.0;
deg = floor(x);
min = floor(60.0 * (x - deg));
sec = 60.0 * (60.0 * (x - deg) - min);
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.8f degrees (%.0f %.0f\' %.2f\")", x, deg, min, sec);
}
static void
prt_sa16(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= (double) (1<<14);
x *= 90.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.3f degrees", x);
}
static void
prt_ba16(gchar *buff, guint32 val)
{
double x = (double) val;
x /= (double) (1<<14);
x *= 90.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.3f degrees", x);
}
static void
prt_ba16_none(gchar *buff, guint32 val)
{
double x = (double) val;
x /= (double) (1<<14);
x *= 90.0;
if (val <= 65536)
g_snprintf(buff, ITEM_LABEL_LENGTH, "No Statement");
else
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.3f degrees", x);
}
static void
prt_kilo(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= 128.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.2f kilometers", x);
}
static void
prt_meters(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.0f meters", x);
}
static void
prt_decimeters(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= 10.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.1f meters", x);
}
static void
prt_centimeters(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= 100.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.2f meters", x);
}
static void
prt_speed(gchar *buff, guint32 val)
{
double x = (double) val;
x /= 1000.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.3f meters/second", x);
}
static void
prt_speed_centi(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= 100.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.2f meters/second", x);
}
static void
prt_speed_deci(gchar *buff, guint32 val)
{
double x = (double) ((gint32) val);
x /= 10.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.1f meters/second", x);
}
static void
prt_millisec(gchar *buff, guint32 val)
{
double x = (double) val;
x /= 1000.0;
g_snprintf(buff, ITEM_LABEL_LENGTH, "%.3f seconds", x);
}
static void
prt_none8(gchar *buff, guint32 val)
{
if (0xff == val)
g_snprintf(buff, ITEM_LABEL_LENGTH, "No Statement");
else
g_snprintf(buff, ITEM_LABEL_LENGTH, "%d", val);
}
static void
prt_none16(gchar *buff, guint32 val)
{
if (0xffff == val)
g_snprintf(buff, ITEM_LABEL_LENGTH, "No Statement");
else
g_snprintf(buff, ITEM_LABEL_LENGTH, "%d", val);
}
static gint
dissect_mission(tvbuff_t *tvb, proto_tree *seg_tree, gint offset)
{
proto_tree_add_item(seg_tree, hf_4607_mission_plan, tvb, offset, 12, ENC_ASCII|ENC_NA);
offset += 12;
proto_tree_add_item(seg_tree, hf_4607_mission_flight_plan, tvb, offset, 12, ENC_ASCII|ENC_NA);
offset += 12;
proto_tree_add_item(seg_tree, hf_4607_mission_platform, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_mission_platform_config, tvb, offset, 10, ENC_ASCII|ENC_NA);
offset += 10;
proto_tree_add_item(seg_tree, hf_4607_mission_time_year, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_mission_time_month, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_mission_time_day, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static gint
dissect_target(tvbuff_t *tvb, proto_tree *seg_tree, gint offset, guint64 mask)
{
proto_item *rpt_item = NULL;
proto_tree *rpt_tree = seg_tree;
if (SET(mask, D32_1)) {
rpt_item = proto_tree_add_item(rpt_tree, hf_4607_dwell_report_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
rpt_tree = proto_item_add_subtree(rpt_item, ett_4607_rpt);
}
if (SET(mask, D32_2)) {
rpt_item = proto_tree_add_item(rpt_tree, hf_4607_dwell_report_lat, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_lon, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
rpt_item = proto_tree_add_item(rpt_tree, hf_4607_dwell_report_delta_lat, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_delta_lon, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (rpt_item && rpt_tree == seg_tree) {
rpt_tree = proto_item_add_subtree(rpt_item, ett_4607_rpt);
}
if (SET(mask, D32_6)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_height, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D32_7)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_radial, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_wrap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D32_9)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_snr, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (SET(mask, D32_10)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_class, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (SET(mask, D32_11)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_prob, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (SET(mask, D32_12)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_unc_slant, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_unc_cross, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_unc_height, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_unc_radial, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D32_16)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_tag_app, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_tag_entity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (SET(mask, D32_18)) {
proto_tree_add_item(rpt_tree, hf_4607_dwell_report_section, tvb, offset, 1, ENC_NA);
offset += 1;
}
return offset;
}
static gint
dissect_dwell(tvbuff_t *tvb, proto_tree *seg_tree, gint offset)
{
guint64 mask;
guint32 count;
mask = tvb_get_ntoh64(tvb, offset);
proto_tree_add_item(seg_tree, hf_4607_dwell_mask, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(seg_tree, hf_4607_dwell_revisit_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_dwell_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_last_dwell, tvb, offset, 1, ENC_NA);
offset += 1;
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(seg_tree, hf_4607_dwell_count, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_lat, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_lon, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_alt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (SET(mask, D10)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_scale_lat, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_scale_lon, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (SET(mask, D12)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_unc_along, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_unc_cross, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_unc_alt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D15)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_track, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_vert_velocity, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (SET(mask, D18)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_track_unc, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_dwell_speed_unc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_vv_unc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D21)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_plat_heading, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_plat_pitch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_plat_roll, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_tree_add_item(seg_tree, hf_4607_dwell_da_lat, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_da_lon, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_dwell_da_range, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_da_angle, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (SET(mask, D28)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_heading, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_pitch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_dwell_sensor_roll, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (SET(mask, D31)) {
proto_tree_add_item(seg_tree, hf_4607_dwell_mdv, tvb, offset, 1, ENC_NA);
offset += 1;
}
while (count--) {
offset = dissect_target(tvb, seg_tree, offset, mask);
}
return offset;
}
static gint
dissect_jobdef(tvbuff_t *tvb, proto_tree *seg_tree, gint offset)
{
proto_tree_add_item(seg_tree, hf_4607_jobdef_job_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sensor_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sensor_model, tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
proto_tree_add_item(seg_tree, hf_4607_jobdef_filter, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_priority, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lat_a, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lon_a, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lat_b, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lon_b, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lat_c, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lon_c, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lat_d, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_ba_lon_d, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_jobdef_radar_mode, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_revisit_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_unc_along, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_unc_cross, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_unc_alt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_unc_heading, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_unc_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_slant, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_cross, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_vlos, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_mdv, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_prob, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_sense_alarm, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_terrain_model, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(seg_tree, hf_4607_jobdef_geoid_model, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static gint
dissect_platform_location(tvbuff_t *tvb, proto_tree *seg_tree, gint offset)
{
proto_tree_add_item(seg_tree, hf_4607_platloc_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_platloc_latitude, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_platloc_longitude, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_platloc_altitude, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_platloc_track, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(seg_tree, hf_4607_platloc_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(seg_tree, hf_4607_platloc_vertical_velocity, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static void
dissect_stanag4607(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 offset = 0;
gint8 first_segment;
guint32 pkt_size = 0;
proto_item *ti = NULL;
proto_tree *hdr_tree = NULL;
proto_item *seg_type = NULL;
proto_tree *seg_tree = NULL;
guint8 seg_id = 0;
if (tvb_length(tvb) < STANAG4607_MIN_LENGTH)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S4607");
col_clear(pinfo->cinfo, COL_INFO);
first_segment = tvb_get_guint8(tvb, 32);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(first_segment, stanag4607_segment_vals, "Unknown (0x%02x)"));
if (PLATFORM_LOCATION_SEGMENT == first_segment) {
guint32 millisecs;
nstime_t ts;
millisecs = tvb_get_ntohl(tvb, 37);
ts.secs = millisecs / 1000;
ts.nsecs = (int)((millisecs - 1000 * ts.secs) * 1000000);
col_set_time(pinfo->cinfo, COL_REL_TIME, &ts, "4607.ploc.time");
}
if (tree) {
ti = proto_tree_add_item(tree, proto_stanag4607, tvb, 0, -1, ENC_NA);
hdr_tree = proto_item_add_subtree(ti, ett_4607_hdr);
proto_tree_add_item(hdr_tree, hf_4607_version, tvb, 0, 2, ENC_ASCII|ENC_NA);
ti = proto_tree_add_item(hdr_tree, hf_4607_packet_size, tvb, 2, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hdr_tree, hf_4607_nationality, tvb, 6, 2, ENC_ASCII|ENC_NA);
proto_tree_add_item(hdr_tree, hf_4607_sec_class, tvb, 8, 1, ENC_NA);
proto_tree_add_item(hdr_tree, hf_4607_sec_system, tvb, 9, 2, ENC_ASCII|ENC_NA);
proto_tree_add_item(hdr_tree, hf_4607_sec_code, tvb, 11, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(hdr_tree, hf_4607_exercise_indicator, tvb, 13, 1, ENC_NA);
proto_tree_add_item(hdr_tree, hf_4607_platform_id, tvb, 14, 10, ENC_ASCII|ENC_NA);
proto_tree_add_item(hdr_tree, hf_4607_mission_id, tvb, 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hdr_tree, hf_4607_job_id, tvb, 28, 4, ENC_BIG_ENDIAN);
}
offset = 32;
pkt_size = tvb_get_ntohl(tvb, 2);
if (tvb_reported_length(tvb) != pkt_size) {
expert_add_info(pinfo, ti, &ei_bad_packet_size);
pkt_size = tvb_reported_length(tvb);
}
while (offset < pkt_size) {
guint32 seg_size = 0;
guint32 saved_offset = offset;
proto_item * pi;
seg_type = proto_tree_add_item(hdr_tree, hf_4607_segment_type, tvb, offset, 1, ENC_NA);
seg_id = tvb_get_guint8(tvb, offset);
offset += 1;
seg_tree = proto_item_add_subtree(seg_type, ett_4607_seg);
pi = proto_tree_add_item(seg_tree, hf_4607_segment_size, tvb, offset, 4, ENC_BIG_ENDIAN);
seg_size = tvb_get_ntohl(tvb, offset);
offset += 4;
if (seg_size < MINIMUM_SEGMENT_SIZE) {
seg_size = MINIMUM_SEGMENT_SIZE;
col_append_str(pinfo->cinfo, COL_INFO, ", Error: Invalid segment size ");
expert_add_info(pinfo, pi, &ei_too_short);
}
switch (seg_id) {
case MISSION_SEGMENT:
CHK_SIZE(MISSION_SEGMENT);
offset = dissect_mission(tvb, seg_tree, offset);
break;
case DWELL_SEGMENT:
offset = dissect_dwell(tvb, seg_tree, offset);
break;
case JOB_DEFINITION_SEGMENT:
CHK_SIZE(JOB_DEFINITION_SEGMENT);
offset = dissect_jobdef(tvb, seg_tree, offset);
break;
case PLATFORM_LOCATION_SEGMENT:
CHK_SIZE(PLATFORM_LOCATION_SEGMENT);
offset = dissect_platform_location(tvb, seg_tree, offset);
break;
default:
offset += seg_size - 5;
break;
}
if (offset < saved_offset) {
break;
}
}
}
void
proto_register_stanag4607(void)
{
static hf_register_info hf[] = {
{ &hf_4607_version,
{ "Version ID", "4607.version",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_packet_size,
{ "Packet Size", "4607.size",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_nationality,
{ "Nationality", "4607.nationality",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_sec_class,
{ "Security Classification", "4607.sec.class",
FT_UINT8, BASE_DEC,
VALS(stanag4607_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_sec_system,
{ "Security System", "4607.sec.system",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_sec_code,
{ "Security Codes", "4607.sec.codes",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_exercise_indicator,
{ "Exercise Indicator", "4607.exind",
FT_UINT8, BASE_DEC,
VALS(stanag4607_exind_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_platform_id,
{ "Platform ID", "4607.platform",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_id,
{ "Mission ID", "4607.mission",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_job_id,
{ "Job ID", "4607.job",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_segment_type,
{ "Segment Type", "4607.seg.type",
FT_UINT8, BASE_DEC,
VALS(stanag4607_segment_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_segment_size,
{ "Segment Size", "4607.seg.size",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_mask,
{ "Existence Mask", "4607.dwell.mask",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_revisit_index,
{ "Revisit Index", "4607.dwell.revisit",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_dwell_index,
{ "Dwell Index", "4607.dwell.dwell",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_last_dwell,
{ "Last Dwell of Revisit", "4607.dwell.last",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_count,
{ "Target Report Count", "4607.dwell.count",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_time,
{ "Dwell Time", "4607.dwell.time",
FT_UINT32, BASE_CUSTOM,
prt_millisec, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_lat,
{ "Sensor Position Latitude", "4607.dwell.sensor.lat",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_lon,
{ "Sensor Position Longitude", "4607.dwell.sensor.lon",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_alt,
{ "Sensor Position Altitude", "4607.dwell.sensor.alt",
FT_INT32, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_scale_lat,
{ "Scale Factor, Latitude", "4607.dwell.scale.lat",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_scale_lon,
{ "Scale Factor, Longitude", "4607.dwell.scale.lon",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_unc_along,
{ "Sensor Position Uncertainty Along Track", "4607.dwell.unc.along",
FT_UINT32, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_unc_cross,
{ "Sensor Position Uncertainty Cross Track", "4607.dwell.unc.cross",
FT_UINT32, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_unc_alt,
{ "Sensor Position Uncertainty Altitude", "4607.dwell.unc.alt",
FT_UINT16, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_track,
{ "Sensor Track", "4607.dwell.track",
FT_UINT16, BASE_CUSTOM,
prt_ba16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_speed,
{ "Sensor Speed", "4607.dwell.speed",
FT_UINT32, BASE_CUSTOM,
prt_speed, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_vert_velocity,
{ "Sensor Vertical Velocity", "4607.dwell.vvel",
FT_INT8, BASE_CUSTOM,
prt_speed_deci, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_track_unc,
{ "Sensor Track Uncertainty", "4607.dwell.track.unc",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_speed_unc,
{ "Sensor Speed Uncertainty", "4607.dwell.speed.unc",
FT_UINT16, BASE_CUSTOM,
prt_speed, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_vv_unc,
{ "Sensor Vertical Velocity Uncertainty", "4607.dwell.vvel.unc",
FT_UINT16, BASE_CUSTOM,
prt_speed_centi, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_plat_heading,
{ "Platform Orientation Heading", "4607.dwell.plat.heading",
FT_UINT16, BASE_CUSTOM,
prt_ba16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_plat_pitch,
{ "Platform Orientation Pitch", "4607.dwell.plat.pitch",
FT_INT16, BASE_CUSTOM,
prt_sa16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_plat_roll,
{ "Platform Orientation Roll (Bank Angle)", "4607.dwell.plat.roll",
FT_INT16, BASE_CUSTOM,
prt_sa16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_da_lat,
{ "Dwell Area Center Latitude", "4607.dwell.da.lat",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_da_lon,
{ "Dwell Area Center Longitude", "4607.dwell.da.lon",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_da_range,
{ "Dwell Area Range Half Extent", "4607.dwell.da.range",
FT_UINT16, BASE_CUSTOM,
prt_kilo, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_da_angle,
{ "Dwell Area Dwell Angle Half Extent", "4607.dwell.da.angle",
FT_UINT16, BASE_CUSTOM,
prt_ba16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_heading,
{ "Sensor Orientation Heading", "4607.dwell.sensor.heading",
FT_UINT16, BASE_CUSTOM,
prt_ba16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_pitch,
{ "Sensor Orientation Pitch", "4607.dwell.sensor.pitch",
FT_INT16, BASE_CUSTOM,
prt_sa16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_sensor_roll,
{ "Sensor Orientation Roll (Bank Angle)", "4607.dwell.sensor.roll",
FT_INT16, BASE_CUSTOM,
prt_sa16, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_mdv,
{ "Minimum Detectable Velocity (MDV)", "4607.dwell.mdv",
FT_UINT8, BASE_CUSTOM,
prt_speed_deci, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_index,
{ "MTI Report Index", "4607.dwell.rpt.idx",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_lat,
{ "Target Location Hi-Res Latitude", "4607.dwell.rpt.lat",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_lon,
{ "Target Location Hi-Res Longitude", "4607.dwell.rpt.lon",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_delta_lat,
{ "Target Location Delta Latitude", "4607.dwell.rpt.delta.lat",
FT_INT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_delta_lon,
{ "Target Location Delta Longitude", "4607.dwell.rpt.delta.lon",
FT_INT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_height,
{ "Target Location Geodetic Height", "4607.dwell.rpt.height",
FT_INT16, BASE_CUSTOM,
prt_meters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_radial,
{ "Target Velocity Line of Sight Component", "4607.dwell.rpt.radial",
FT_INT16, BASE_CUSTOM,
prt_speed_centi, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_wrap,
{ "Target Wrap Velocity", "4607.dwell.rpt.wrap",
FT_UINT16, BASE_CUSTOM,
prt_speed_centi, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_snr,
{ "Target SNR", "4607.dwell.rpt.snr",
FT_INT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_class,
{ "Target Classification", "4607.dwell.rpt.class",
FT_UINT8, BASE_DEC,
VALS(stanag4607_target_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_prob,
{ "Target Class Probability", "4607.dwell.rpt.prob",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_unc_slant,
{ "Target Measurement Uncertainty Slant Range", "4607.dwell.rpt.unc.slant",
FT_UINT16, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_unc_cross,
{ "Target Measurement Uncertainty Cross Range", "4607.dwell.rpt.unc.cross",
FT_UINT16, BASE_CUSTOM,
prt_decimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_unc_height,
{ "Target Measurement Uncertainty Height", "4607.dwell.rpt.unc.height",
FT_UINT8, BASE_CUSTOM,
prt_meters, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_unc_radial,
{ "Target Measurement Uncertainty Radial Velocity", "4607.dwell.rpt.unc.radial",
FT_UINT16, BASE_CUSTOM,
prt_speed_centi, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_tag_app,
{ "Truth Tag Application", "4607.dwell.rpt.tag.app",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_tag_entity,
{ "Truth Tag Entity", "4607.dwell.rpt.tag.entity",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_dwell_report_section,
{ "Radar Cross Section", "4607.dwell.rpt.section",
FT_INT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_job_id,
{ "Job ID", "4607.job.id",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sensor_type,
{ "Sensor Type", "4607.job.type",
FT_UINT8, BASE_DEC,
VALS(stanag4607_sensor_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sensor_model,
{ "Sensor Model", "4607.job.model",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_filter,
{ "Target Filtering Flag", "4607.job.filter",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_priority,
{ "Radar Priority", "4607.job.priority",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lat_a,
{ "Bounding Area Point A Latitude", "4607.job.ba.lat.a",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lon_a,
{ "Bounding Area Point A Longitude", "4607.job.ba.lon.a",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lat_b,
{ "Bounding Area Point B Latitude", "4607.job.ba.lat.b",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lon_b,
{ "Bounding Area Point B Longitude", "4607.job.ba.lon.b",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lat_c,
{ "Bounding Area Point C Latitude", "4607.job.ba.lat.c",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lon_c,
{ "Bounding Area Point C Longitude", "4607.job.ba.lon.c",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lat_d,
{ "Bounding Area Point D Latitude", "4607.job.ba.lat.d",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_ba_lon_d,
{ "Bounding Area Point D Longitude", "4607.job.ba.lon.d",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_radar_mode,
{ "Radar Mode", "4607.job.mode",
FT_UINT8, BASE_DEC,
VALS(stanag4607_radar_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_revisit_interval,
{ "Nominal Revisit Interval", "4607.job.revisit",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_unc_along,
{ "Nominal Sensor Position Uncertainty Along Track", "4607.job.unc.track",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_unc_cross,
{ "Nominal Sensor Position Uncertainty Cross Track", "4607.job.unc.cross",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_unc_alt,
{ "Nominal Sensor Position Uncertainty Altitude", "4607.job.unc.alt",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_unc_heading,
{ "Nominal Sensor Position Uncertainty Track Heading", "4607.job.unc.heading",
FT_UINT8, BASE_CUSTOM,
prt_none8, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_unc_speed,
{ "Nominal Sensor Position Uncertainty Speed", "4607.job.unc.speed",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_slant,
{ "Nominal Sensor Slant Range Standard Deviation", "4607.job.sense.slant",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_cross,
{ "Nominal Sensor Cross Range Standard Deviation", "4607.job.sense.cross",
FT_UINT16, BASE_CUSTOM,
prt_ba16_none, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_vlos,
{ "Nominal Sensor Velocity Line-Of-Sight Std. Dev", "4607.job.sense.vlos",
FT_UINT16, BASE_CUSTOM,
prt_none16, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_mdv,
{ "Nominal Sensor Minimum Dectectable Velocity (MDV)", "4607.job.sense.mdv",
FT_UINT8, BASE_CUSTOM,
prt_none8, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_prob,
{ "Nominal Sensor Detection Probability", "4607.job.sense.prob",
FT_UINT8, BASE_CUSTOM,
prt_none8, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_sense_alarm,
{ "Nominal Sensor False Alarm Density", "4607.job.sense.alarm",
FT_UINT8, BASE_CUSTOM,
prt_none8, 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_terrain_model,
{ "Terrain Elevation Model Used", "4607.job.terrain",
FT_UINT8, BASE_DEC,
VALS(stanag4607_terrain_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_jobdef_geoid_model,
{ "Geoid Model Used", "4607.job.geoid",
FT_UINT8, BASE_DEC,
VALS(stanag4607_geoid_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_plan,
{ "Mission Plan", "4607.mission.plan",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_flight_plan,
{ "Mission Flight Plan", "4607.mission.flight",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_platform,
{ "Mission Platform Type", "4607.mission.platform",
FT_UINT8, BASE_DEC,
VALS(stanag4607_platform_vals), 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_platform_config,
{ "Mission Platform Configuration", "4607.mission.config",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_time_year,
{ "Mission Reference Time Year", "4607.mission.year",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_time_month,
{ "Mission Reference Time Month", "4607.mission.month",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_mission_time_day,
{ "Mission Reference Time Day", "4607.mission.day",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_time,
{ "Platform Location Time", "4607.ploc.time",
FT_UINT32, BASE_CUSTOM,
prt_millisec, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_latitude,
{ "Platform Position Latitude", "4607.ploc.lat",
FT_INT32, BASE_CUSTOM,
prt_sa32, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_longitude,
{ "Platform Position Longitude", "4607.ploc.lon",
FT_UINT32, BASE_CUSTOM,
prt_ba32, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_altitude,
{ "Platform Position Altitude", "4607.ploc.alt",
FT_INT32, BASE_CUSTOM,
prt_centimeters, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_track,
{ "Platform Track", "4607.ploc.track",
FT_UINT16, BASE_CUSTOM,
prt_ba16, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_speed,
{ "Platform Speed", "4607.ploc.speed",
FT_UINT32, BASE_CUSTOM,
prt_speed, 0x0,
NULL, HFILL }
},
{ &hf_4607_platloc_vertical_velocity,
{ "Platform Vertical Velocity", "4607.ploc.velocity",
FT_INT8, BASE_CUSTOM,
prt_speed_deci, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_4607_hdr,
&ett_4607_seg,
&ett_4607_rpt,
};
static ei_register_info ei[] = {
{ &ei_too_short,
{ "4607.segment_too_short", PI_MALFORMED, PI_ERROR,
"Segment size too small", EXPFILL }},
{ &ei_bad_length,
{ "4607.segment_bad_length", PI_MALFORMED, PI_ERROR,
"Bad segment size", EXPFILL }},
{ &ei_bad_packet_size,
{ "4607.bad_packet_size", PI_MALFORMED, PI_ERROR,
"Bad packet size field", EXPFILL }}
};
expert_module_t* expert_4607;
proto_stanag4607 = proto_register_protocol (
"STANAG 4607 (GMTI Format)",
"STANAG 4607",
"4607"
);
proto_register_field_array(proto_stanag4607, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_4607 = expert_register_protocol(proto_stanag4607);
expert_register_field_array(expert_4607, ei, array_length(ei));
register_dissector("STANAG 4607", dissect_stanag4607, proto_stanag4607);
}
void
proto_reg_handoff_stanag4607(void)
{
static dissector_handle_t stanag4607_handle;
stanag4607_handle = create_dissector_handle(dissect_stanag4607,
proto_stanag4607);
dissector_add_uint("wtap_encap", WTAP_ENCAP_STANAG_4607, stanag4607_handle);
}
