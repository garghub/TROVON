gchar *
create_endpoint_geoip_map(const GArray *endp_array, gchar **err_str) {
char *tpl_filename, *tpl_line;
FILE *tpl_file, *out_file;
char *map_path;
gchar *map_filename = NULL;
guint i;
GString *tpl_entry;
gchar *esc_entry;
int db_lon, db_lat, db_country4, db_country6, db_city4, db_city6, db_asn4, db_asn6;
guint cur_db;
const char *map_endpoint_opener = "{\n";
db_lon = db_lat = db_country4 = db_country6 = db_city4 = db_city6 = db_asn4 = db_asn6 = -1;
tpl_filename = get_datafile_path("ipmap.html");
tpl_file = ws_fopen(tpl_filename, "r");
if(tpl_file == NULL) {
if (err_str) {
GString *err_descr = g_string_new("");
g_string_printf(err_descr, file_open_error_message(errno, FALSE), tpl_filename);
*err_str = g_string_free(err_descr, FALSE);
}
g_free(tpl_filename);
return NULL;
}
g_free(tpl_filename);
#if 1
if (! create_tempdir(&map_path, "Wireshark IP Map ")) {
if (err_str) {
GString *err_descr = g_string_new("");
g_string_printf(err_descr, "Could not create temporary directory\n%s",
map_path);
*err_str = g_string_free(err_descr, FALSE);
}
fclose(tpl_file);
return NULL;
}
#else
map_path = "/tmp";
#endif
map_filename = g_strdup_printf("%s%cipmap.html", map_path, G_DIR_SEPARATOR);
out_file = ws_fopen(map_filename, "w");
if(out_file == NULL) {
if (err_str) {
GString *err_descr = g_string_new("");
g_string_printf(err_descr, file_open_error_message(errno, FALSE), map_filename);
*err_str = g_string_free(err_descr, FALSE);
}
g_free(map_filename);
fclose(tpl_file);
return NULL;
}
tpl_line = (char *)g_malloc(MAX_TPL_LINE_LEN);
while (fgets(tpl_line, MAX_TPL_LINE_LEN, tpl_file) != NULL) {
fputs(tpl_line, out_file);
if (strstr(tpl_line, "// Start endpoint list")) {
break;
}
}
for (cur_db = 0; cur_db < geoip_db_num_dbs(); cur_db++) {
switch (geoip_db_type(cur_db)) {
case WS_LON_FAKE_EDITION:
db_lon = cur_db;
break;
case WS_LAT_FAKE_EDITION:
db_lat = cur_db;
break;
case GEOIP_COUNTRY_EDITION:
db_country4 = cur_db;
break;
case GEOIP_COUNTRY_EDITION_V6:
db_country6 = cur_db;
break;
case GEOIP_CITY_EDITION_REV0:
case GEOIP_CITY_EDITION_REV1:
db_city4 = cur_db;
break;
case GEOIP_CITY_EDITION_REV0_V6:
case GEOIP_CITY_EDITION_REV1_V6:
db_city6 = cur_db;
break;
}
}
if(db_lon < 0 || db_lat < 0) {
if (err_str) {
*err_str = g_strdup("Unable to open GeoIP database");
}
g_free(map_filename);
fclose(tpl_file);
return NULL;
}
tpl_entry = g_string_new("");
for (i = 0; i < endp_array->len; i++) {
const char *lat, *lon, *country, *city, *asn;
hostlist_talker_t *endp_item = &g_array_index(endp_array, hostlist_talker_t, i);
if (endp_item->myaddress.type == AT_IPv4) {
lon = geoip_db_lookup_ipv4(db_lon, pntoh32(endp_item->myaddress.data), NULL);
lat = geoip_db_lookup_ipv4(db_lat, pntoh32(endp_item->myaddress.data), NULL);
country = geoip_db_lookup_ipv4(db_country4, pntoh32(endp_item->myaddress.data), "-");
city = geoip_db_lookup_ipv4(db_city4, pntoh32(endp_item->myaddress.data), "-");
asn = geoip_db_lookup_ipv4(db_asn4, pntoh32(endp_item->myaddress.data), "-");
} else if (endp_item->myaddress.type == AT_IPv6) {
const struct e_in6_addr *addr = (const struct e_in6_addr *) endp_item->myaddress.data;
lon = geoip_db_lookup_ipv6(db_lon, *addr, NULL);
lat = geoip_db_lookup_ipv6(db_lat, *addr, NULL);
country = geoip_db_lookup_ipv6(db_country6, *addr, "-");
city = geoip_db_lookup_ipv6(db_city6, *addr, "-");
asn = geoip_db_lookup_ipv6(db_asn6, *addr, "-");
} else {
continue;
}
if (lon && lat) {
g_string_printf(tpl_entry, "%s", map_endpoint_opener);
g_string_append_printf(tpl_entry, " 'type': 'Feature', 'geometry': { 'type': 'Point', 'coordinates': [%s, %s] },\n", lon, lat);
g_string_append_printf(tpl_entry, " 'properties': { 'title': '%s', ", ep_address_to_display(&endp_item->myaddress));
esc_entry = string_replace(city, "'", "&#39;");
g_string_append_printf(tpl_entry, "'description': '<div class=\"geoip_property\">City: %s</div>", esc_entry);
g_free(esc_entry);
esc_entry = string_replace(country, "'", "&#39;");
g_string_append_printf(tpl_entry, "<div class=\"geoip_property\">Country: %s</div>", esc_entry);
g_free(esc_entry);
esc_entry = format_size(endp_item->tx_frames + endp_item->rx_frames,
(format_size_flags_e)(format_size_unit_none|format_size_prefix_si));
g_string_append_printf(tpl_entry, "<div class=\"geoip_property\">Packets: %s</div>", esc_entry);
g_free(esc_entry);
esc_entry = format_size(endp_item->tx_bytes + endp_item->rx_bytes,
(format_size_flags_e)(format_size_unit_none|format_size_prefix_si));
g_string_append_printf(tpl_entry, "<div class=\"geoip_property\">Bytes: %s</div>", esc_entry);
g_free(esc_entry);
esc_entry = string_replace(asn, "'", "&#39;");
g_string_append_printf(tpl_entry, "<div class=\"geoip_property\">AS Number: %s</div>", esc_entry);
g_free(esc_entry);
g_string_append(tpl_entry, "' }\n");
g_string_append(tpl_entry, "}");
fputs(tpl_entry->str, out_file);
map_endpoint_opener = ",\n{\n";
}
}
while (fgets(tpl_line, MAX_TPL_LINE_LEN, tpl_file) != NULL) {
fputs(tpl_line, out_file);
}
g_free(tpl_line);
fclose(tpl_file);
fclose(out_file);
return map_filename;
}
