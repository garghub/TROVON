static void
dissect_ppi_gps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
guint length;
gint length_remaining;
int offset = 0;
proto_tree *ppi_gps_tree = NULL;
proto_tree *pt, *present_tree = NULL;
proto_tree *my_pt, *gpsflags_flags_tree = NULL;
proto_item *ti = NULL;
proto_item *gps_line = NULL;
int bit;
guint32 present, next_present;
guint32 version, gpsflags_flags;
gdouble lat, lon, alt, alt_gnd;
nstime_t gps_timestamp;
int gps_time_size, already_processed_fractime;
gdouble eph, epv, ept;
gchar *curr_str;
guint32 t_lat, t_lon, t_alt, t_alt_gnd;
guint32 t_herr, t_verr, t_terr;
guint32 t_appspecific_num;
gps_timestamp.secs = gps_timestamp.nsecs = already_processed_fractime = 0;
col_clear(pinfo->cinfo,COL_INFO);
version = tvb_get_guint8(tvb, offset);
length = tvb_get_letohs(tvb, offset+2);
present = tvb_get_letohl(tvb, offset+4);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "PPI_GPS Capture v%u, Length %u", version, length);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ppi_gps, tvb, 0, length, "GPS:");
gps_line = ti;
ppi_gps_tree= proto_item_add_subtree(ti, ett_ppi_gps);
proto_tree_add_uint(ppi_gps_tree, hf_ppi_gps_version, tvb, offset, 1, version);
proto_tree_add_item(ppi_gps_tree, hf_ppi_gps_pad, tvb, offset + 1, 1, ENC_NA);
ti = proto_tree_add_uint(ppi_gps_tree, hf_ppi_gps_length, tvb, offset + 2, 2, length);
}
if (! (version == 1 || version == 2) ) {
if (tree)
proto_item_append_text(ti, "invalid version (got %d, expected 1 or 2)", version);
return;
}
length_remaining = length;
if (length_remaining < PPI_GEOBASE_MIN_HEADER_LEN) {
if (tree)
proto_item_append_text(ti, " (invalid - minimum length is 8)");
return;
}
if (length > PPI_GPS_MAXTAGLEN ) {
if (tree)
proto_item_append_text(ti, "Invalid PPI-GPS length (got %d, %d max\n)", length, PPI_GPS_MAXTAGLEN);
return;
}
if (tree) {
pt = proto_tree_add_uint(ppi_gps_tree, hf_ppi_gps_present, tvb, offset + 4, 4, present);
present_tree = proto_item_add_subtree(pt, ett_ppi_gps_present);
proto_tree_add_item(present_tree, hf_ppi_gps_present_gpsflags_flags, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_lat, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_lon, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_alt, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_alt_gnd, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_gpstime, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_fractime, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_eph, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_epv, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_ept, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_descr, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_appspecific_num, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_appspecific_data, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_gps_present_ext, tvb, 4, 4, ENC_LITTLE_ENDIAN);
}
offset += PPI_GEOBASE_MIN_HEADER_LEN;
length_remaining -= PPI_GEOBASE_MIN_HEADER_LEN;
for (; present; present = next_present) {
next_present = present & (present - 1);
bit = BITNO_32(present ^ next_present);
switch (bit) {
case PPI_GEOTAG_GPSFLAGS:
if (length_remaining < 4)
break;
gpsflags_flags = tvb_get_letohl(tvb, offset);
if (tree) {
my_pt = proto_tree_add_uint(ppi_gps_tree, hf_ppi_gps_gpsflags_flags, tvb, offset , 4, gpsflags_flags);
gpsflags_flags_tree = proto_item_add_subtree(my_pt, ett_ppi_gps_gpsflags_flags);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag0_nofix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag1_gpsfix, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag2_diffgps, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag3_PPS, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag4_RTK, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag5_floatRTK, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag6_dead_reck, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag7_manual, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(gpsflags_flags_tree, hf_ppi_gps_gpsflags_flag8_sim, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_LAT:
if (length_remaining < 4)
break;
t_lat = tvb_get_letohl(tvb, offset);
lat = ppi_fixed3_7_to_gdouble(t_lat);
if (tree)
{
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_lat, tvb, offset, 4, lat);
proto_item_append_text(gps_line, " Lat:%f ", lat);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_LON:
if (length_remaining < 4)
break;
t_lon = tvb_get_letohl(tvb, offset);
lon = ppi_fixed3_7_to_gdouble(t_lon);
if (tree)
{
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_lon, tvb, offset, 4, lon);
proto_item_append_text(gps_line, " Lon:%f ", lon);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_ALT:
if (length_remaining < 4)
break;
t_alt = tvb_get_letohl(tvb, offset);
alt = ppi_fixed6_4_to_gdouble(t_alt);
if (tree)
{
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_alt, tvb, offset, 4, alt);
proto_item_append_text(gps_line, " Alt:%f ", alt);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_ALT_G:
if (length_remaining < 4)
break;
t_alt_gnd = tvb_get_letohl(tvb, offset);
alt_gnd = ppi_fixed6_4_to_gdouble(t_alt_gnd);
if (tree)
{
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_alt_gnd, tvb, offset, 4, alt_gnd);
proto_item_append_text(gps_line, " Alt_g:%f ", alt_gnd);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_GPSTIME:
if (length_remaining < 4)
break;
gps_timestamp.secs = tvb_get_letohl(tvb, offset);
gps_timestamp.nsecs = 0;
gps_time_size = 4;
if (length_remaining < 4 && (present & PPI_GPS_MASK_FRACTIME))
break;
else if (present & PPI_GPS_MASK_FRACTIME) {
gps_timestamp.nsecs = tvb_get_letohl(tvb, offset + 4);
already_processed_fractime = 1;
gps_time_size = 8;
}
if (tree) {
proto_tree_add_time(ppi_gps_tree, hf_ppi_gps_gpstime, tvb, offset, gps_time_size, &gps_timestamp);
}
offset += gps_time_size;
length_remaining -= gps_time_size;
break;
case PPI_GEOTAG_FRACTIONALTIME:
if (length_remaining < 4)
break;
if (already_processed_fractime)
break;
break;
case PPI_GEOTAG_EPH:
if (length_remaining < 4)
break;
t_herr = tvb_get_letohl(tvb, offset);
eph = ppi_fixed3_6_to_gdouble(t_herr);
if (tree)
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_eph, tvb, offset, 4, eph);
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_EPV:
if (length_remaining < 4)
break;
t_verr = tvb_get_letohl(tvb, offset);
epv = ppi_fixed3_6_to_gdouble(t_verr);
if (tree)
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_epv, tvb, offset, 4, epv);
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_EPT:
if (length_remaining < 4)
break;
t_terr = tvb_get_letohl(tvb, offset);
ept = ppi_ns_counter_to_gdouble(t_terr);
if (tree)
proto_tree_add_double(ppi_gps_tree, hf_ppi_gps_ept, tvb, offset, 4, ept);
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_DESCRIPTIONSTR:
if (length_remaining < 32)
break;
if (tree)
{
curr_str = tvb_format_stringzpad(tvb, offset, 32);
proto_tree_add_string(ppi_gps_tree, hf_ppi_gps_descstr, tvb, offset, 32, curr_str);
proto_item_append_text(gps_line, " (%s)", curr_str);
}
offset+=32;
length_remaining-=32;
break;
case PPI_GEOTAG_APPID:
if (length_remaining < 4)
break;
t_appspecific_num = tvb_get_letohl(tvb, offset);
if (tree) {
proto_tree_add_uint(ppi_gps_tree, hf_ppi_gps_appspecific_num, tvb, offset, 4, t_appspecific_num);
}
offset+=4;
length_remaining-=4;
break;
case PPI_GEOTAG_APPDATA:
if (length_remaining < 60)
break;
if (tree) {
proto_tree_add_item(ppi_gps_tree, hf_ppi_gps_appspecific_data, tvb, offset, 60, ENC_NA);
}
offset+=60;
length_remaining-=60;
break;
default:
next_present = 0;
proto_tree_add_text(ppi_gps_tree, tvb, offset, 0, "Error: PPI-GEOLOCATION-GPS: unknown bit (%d) set in present field.\n", bit);
continue;
}
}
return;
}
void
proto_register_ppi_gps(void) {
static hf_register_info hf[] = {
{ &hf_ppi_gps_version,
{ "Header revision", "ppi_gps.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Version of ppi_gps header format", HFILL } },
{ &hf_ppi_gps_pad,
{ "Header pad", "ppi_gps.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Padding", HFILL } },
{ &hf_ppi_gps_length,
{ "Header length", "ppi_gps.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of header including version, pad, length and data fields", HFILL } },
{ &hf_ppi_gps_present,
{ "Present", "ppi_gps.present",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Bitmask indicating which fields are present", HFILL } },
{ &hf_ppi_gps_present_gpsflags_flags,
{ "GPSFlags", "ppi_gps.present.gpsflagss",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_GPSFLAGS,
"32-bit bitmask indicating type of GPS fix (GPS/INS/software/etc)", HFILL } },
{ &hf_ppi_gps_present_lat,
{ "Lat", "ppi_gps.present.lat",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_LAT,
"Specifies if the latitude field is present", HFILL } },
{ &hf_ppi_gps_present_lon,
{ "Lon", "ppi_gps.present.lon",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_LON,
"Specifies if the longitude field is present", HFILL } },
{ &hf_ppi_gps_present_alt,
{ "Alt", "ppi_gps.present.alt",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_ALT,
"Specifies if the altitude field is present", HFILL } },
{ &hf_ppi_gps_present_alt_gnd,
{ "Alt-gnd", "ppi_gps.present.alt_gnd",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_ALT_G,
"Specifies if the altitude-g field is present", HFILL } },
{ &hf_ppi_gps_present_gpstime,
{ "GPStime", "ppi_gps.present.gpstime",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_GPSTIME,
"Specifies if the GPS time field is present", HFILL } },
{ &hf_ppi_gps_present_fractime,
{ "fractime", "ppi_gps.present.fractime",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_FRACTIME,
"Specifies if the fractional time field is present", HFILL } },
{ &hf_ppi_gps_present_eph,
{ "error_h", "ppi_gps.present.eph",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_EPH,
"Specifies if the horizontal error field is present (eph)", HFILL } },
{ &hf_ppi_gps_present_epv,
{ "error_v", "ppi_gps.present.epv",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_EPV,
"Specifies if the vertical error field present (epv)", HFILL } },
{ &hf_ppi_gps_present_ept,
{ "error_t", "ppi_gps.present.ept",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_EPT,
"Specifies if the estimed time error field is present (ept)", HFILL } },
{ &hf_ppi_gps_present_descr,
{ "Description", "ppi_gps.present.descr",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_DESCRSTR,
"Specifies if the (ASCII) description is present", HFILL } },
{ &hf_ppi_gps_present_appspecific_num,
{ "AppId", "ppi_gps.present.appid",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_APPID,
"Specifies if the application specific field id is present", HFILL } },
{ &hf_ppi_gps_present_appspecific_data,
{ "AppData", "ppi_gps.present.appdata",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_APPDATA,
"Specifies if the application specific data field is present", HFILL } },
{ &hf_ppi_gps_present_ext,
{ "Ext", "ppi_gps.present.ext",
FT_BOOLEAN, 32, NULL, PPI_GPS_MASK_EXT,
"Specifies if there are any extensions to the header present", HFILL } },
{ &hf_ppi_gps_gpsflags_flags,
{ "GPSFlags", "ppi_gps.gpsflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Bitmask indicating GPS/INS/manual fix", HFILL } },
{ &hf_ppi_gps_lat,
{ "Latitude", "ppi_gps.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Latitude packet was received at", HFILL } },
{ &hf_ppi_gps_lon,
{ "Longitude", "ppi_gps.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Longitude packet was received at", HFILL } },
{ &hf_ppi_gps_alt,
{ "Altitude", "ppi_gps.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Altitude packet was received at", HFILL } },
{ &hf_ppi_gps_alt_gnd,
{ "Altitude_gnd", "ppi_gps.alt_gnd",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Altitude packet was received at (relative to ground)", HFILL } },
{ &hf_ppi_gps_gpstime,
{ "GPSTimestamp", "ppi_gps.gpstime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
"GPSTimestamp packet was received at", HFILL } },
#if 0
{ &hf_ppi_gps_fractime,
{ "fractional Timestamp", "ppi_gps.fractime",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"fractional GPSTimestamp packet was received at", HFILL } },
#endif
{ &hf_ppi_gps_eph,
{ "Horizontal Error (m)", "ppi_gps.eph",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Horizontal margin of error (meters)", HFILL } },
{ &hf_ppi_gps_epv,
{ "Vertical Error (m)", "ppi_gps.epv",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Vertical margin of error (meters)", HFILL } },
{ &hf_ppi_gps_ept,
{ "Time Error (s)", "ppi_gps.ept",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Time margin of error (secs)", HFILL } },
{ &hf_ppi_gps_descstr,
{ "Description", "ppi_gps.descr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_ppi_gps_appspecific_num,
{ "Application Specific id", "ppi_gps.appid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_ppi_gps_appspecific_data,
{ "Application specific data", "ppi_gps.appdata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
#define PPI_GPS_GPSFLAGS_FLAG0_NOFIX 0x00000001
#define PPI_GPS_GPSFLAGS_FLAG1_GPS 0x00000002
#define PPI_GPS_GPSFLAGS_FLAG2_DIFFGPS 0x00000004
#define PPI_GPS_GPSFLAGS_FLAG3_PPS 0x00000008
#define PPI_GPS_GPSFLAGS_FLAG4_RTK 0x00000010
#define PPI_GPS_GPSFLAGS_FLAG5_FLOATRTK 0x00000020
#define PPI_GPS_GPSFLAGS_FLAG6_DEAD_RECK 0x00000040
#define PPI_GPS_GPSFLAGS_FLAG7_MANUAL 0x00000080
#define PPI_GPS_GPSFLAGS_FLAG8_SIM 0x00000100
{ &hf_ppi_gps_gpsflags_flag0_nofix,
{ "No fix available", "ppi_gps.gpsflagss.nofix",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG0_NOFIX,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag1_gpsfix,
{ "GPS provided fix", "ppi_gps.gpsflagss.gps",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG1_GPS,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag2_diffgps,
{ "Differential GPS provided fix", "ppi_gps.gpsflagss.diffgps",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG2_DIFFGPS,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag3_PPS,
{ "PPS fix", "ppi_gps.gpsflagss.pps",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG3_PPS,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag4_RTK,
{ "RTK fix", "ppi_gps.gpsflagss.rtk",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG4_RTK,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag5_floatRTK,
{ "floatRTK fix", "ppi_gps.gpsflagss.frtk",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG5_FLOATRTK,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag6_dead_reck,
{ "dead reckoning fix", "ppi_gps.gpsflagss.dead_reck",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG6_DEAD_RECK,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag7_manual,
{ "manual fix", "ppi_gps.gpsflagss.manual",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG7_MANUAL,
NULL, HFILL } },
{ &hf_ppi_gps_gpsflags_flag8_sim,
{ "simulated fix", "ppi_gps.gpsflagss.simulation",
FT_BOOLEAN, 32, NULL, PPI_GPS_GPSFLAGS_FLAG8_SIM,
NULL, HFILL } },
};
static gint *ett[] = {
&ett_ppi_gps,
&ett_ppi_gps_present,
&ett_ppi_gps_gpsflags_flags
};
proto_ppi_gps = proto_register_protocol("PPI Geotagging GPS tag decoder", "PPI GPS Decoder", "ppi_gps");
proto_register_field_array(proto_ppi_gps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ppi_gps", dissect_ppi_gps, proto_ppi_gps);
}
