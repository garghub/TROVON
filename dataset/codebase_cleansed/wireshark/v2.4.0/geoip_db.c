static void
geoip_dat_scan_dir(const char *dirname) {
WS_DIR *dir;
WS_DIRENT *file;
const char *name;
char *datname;
GeoIP *gi;
if ((dir = ws_dir_open(dirname, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
if (g_str_has_prefix(file, "Geo") && g_str_has_suffix(file, ".dat")) {
datname = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", dirname, name);
gi = GeoIP_open(datname, GEOIP_MEMORY_CACHE);
if (gi) {
g_array_append_val(geoip_dat_arr, gi);
}
g_free(datname);
}
}
ws_dir_close (dir);
}
}
static void* geoip_db_path_copy_cb(void* dest, const void* orig, size_t len _U_) {
const geoip_db_path_t *m = (const geoip_db_path_t *)orig;
geoip_db_path_t *d = (geoip_db_path_t *)dest;
d->path = g_strdup(m->path);
return d;
}
static void geoip_db_path_free_cb(void* p) {
geoip_db_path_t *m = (geoip_db_path_t *)p;
g_free(m->path);
}
static void geoip_dat_cleanup(void) {
GeoIP *gi;
guint i;
if (geoip_dat_arr) {
for (i = 0; i < geoip_db_num_dbs() - 2; i++) {
gi = g_array_index(geoip_dat_arr, GeoIP *, i);
if (gi) {
GeoIP_delete(gi);
}
}
gi = g_array_index(geoip_dat_arr, GeoIP *, i);
if (gi) {
g_free(gi);
}
gi = g_array_index(geoip_dat_arr, GeoIP *, i+1);
if (gi) {
g_free(gi);
}
g_array_free(geoip_dat_arr, TRUE);
geoip_dat_arr = NULL;
}
}
static void geoip_db_post_update_cb(void) {
guint i;
GeoIP* gi;
geoip_dat_cleanup();
geoip_dat_arr = g_array_new(FALSE, FALSE, sizeof(GeoIP *));
for (i = 0; geoip_db_system_paths[i].path != NULL; i++) {
geoip_dat_scan_dir(geoip_db_system_paths[i].path);
}
for (i = 0; i < num_geoip_db_paths; i++) {
if (geoip_db_paths[i].path) {
geoip_dat_scan_dir(geoip_db_paths[i].path);
}
}
gi = (GeoIP *)g_malloc(sizeof (GeoIP));
gi->databaseType = WS_LAT_FAKE_EDITION;
g_array_append_val(geoip_dat_arr, gi);
gi = (GeoIP *)g_malloc(sizeof (GeoIP));
gi->databaseType = WS_LON_FAKE_EDITION;
g_array_append_val(geoip_dat_arr, gi);
}
static void geoip_db_cleanup(void)
{
geoip_dat_cleanup();
}
void
geoip_db_pref_init(module_t *nameres)
{
static uat_field_t geoip_db_paths_fields[] = {
UAT_FLD_DIRECTORYNAME(geoip_mod, path, "GeoIP Database Directory", "The GeoIP database directory path"),
UAT_END_FIELDS
};
geoip_db_paths_uat = uat_new("GeoIP Database Paths",
sizeof(geoip_db_path_t),
"geoip_db_paths",
FALSE,
(void**)&geoip_db_paths,
&num_geoip_db_paths,
UAT_AFFECTS_DISSECTION,
"ChGeoIPDbPaths",
geoip_db_path_copy_cb,
NULL,
geoip_db_path_free_cb,
geoip_db_post_update_cb,
geoip_db_cleanup,
geoip_db_paths_fields);
prefs_register_uat_preference(nameres,
"geoip_db_paths",
"GeoIP database directories",
"Search paths for GeoIP address mapping databases."
" Wireshark will look in each directory for files beginning"
" with \"Geo\" and ending with \".dat\".",
geoip_db_paths_uat);
}
guint
geoip_db_num_dbs(void) {
return (geoip_dat_arr == NULL) ? 0 : geoip_dat_arr->len;
}
const gchar *
geoip_db_name(guint dbnum) {
GeoIP *gi;
gi = g_array_index(geoip_dat_arr, GeoIP *, dbnum);
if (gi) {
return (val_to_str_const(gi->databaseType, geoip_type_name_vals, "Unknown database"));
}
return "Invalid database";
}
int
geoip_db_type(guint dbnum) {
GeoIP *gi;
gi = g_array_index(geoip_dat_arr, GeoIP *, dbnum);
if (gi) {
return (gi->databaseType);
}
return -1;
}
static int
geoip_db_lookup_latlon4(guint32 addr, float *lat, float *lon) {
GeoIP *gi;
GeoIPRecord *gir;
guint i;
for (i = 0; i < geoip_db_num_dbs(); i++) {
gi = g_array_index(geoip_dat_arr, GeoIP *, i);
if (gi) {
switch (gi->databaseType) {
case GEOIP_CITY_EDITION_REV0:
case GEOIP_CITY_EDITION_REV1:
gir = GeoIP_record_by_ipnum(gi, addr);
if (gir) {
*lat = gir->latitude;
*lon = gir->longitude;
GeoIPRecord_delete(gir);
return 0;
}
return -1;
default:
break;
}
}
}
return -1;
}
static char *
db_val_to_utf_8(const char *val, GeoIP *gi) {
if (GeoIP_charset(gi) == GEOIP_CHARSET_ISO_8859_1) {
char *utf8_val;
utf8_val = g_convert(val, -1, "UTF-8", "ISO-8859-1", NULL, NULL, NULL);
if (utf8_val) {
char *ret_val = wmem_strdup(NULL, utf8_val);
g_free(utf8_val);
return ret_val;
}
}
return wmem_strdup(NULL, val);
}
char *
geoip_db_lookup_ipv4(guint dbnum, guint32 addr, const char *not_found) {
GeoIP *gi;
GeoIPRecord *gir;
char *name;
const char *country;
char *val, *ret = NULL;
if (dbnum > geoip_db_num_dbs()) {
if (not_found == NULL)
return NULL;
return wmem_strdup(NULL, not_found);
}
gi = g_array_index(geoip_dat_arr, GeoIP *, dbnum);
if (gi) {
switch (gi->databaseType) {
case GEOIP_COUNTRY_EDITION:
country = GeoIP_country_name_by_ipnum(gi, addr);
if (country) {
ret = db_val_to_utf_8(country, gi);
}
break;
case GEOIP_CITY_EDITION_REV0:
case GEOIP_CITY_EDITION_REV1:
gir = GeoIP_record_by_ipnum(gi, addr);
if (gir && gir->city && gir->region) {
val = wmem_strdup_printf(NULL, "%s, %s", gir->city, gir->region);
ret = db_val_to_utf_8(val, gi);
wmem_free(NULL, val);
} else if (gir && gir->city) {
ret = db_val_to_utf_8(gir->city, gi);
}
if (gir)
GeoIPRecord_delete(gir);
break;
case GEOIP_ORG_EDITION:
case GEOIP_ISP_EDITION:
case GEOIP_ASNUM_EDITION:
name = GeoIP_name_by_ipnum(gi, addr);
if (name) {
ret = db_val_to_utf_8(name, gi);
GeoIP_free(name);
}
break;
case WS_LAT_FAKE_EDITION:
{
float lat;
float lon;
char *c;
if(geoip_db_lookup_latlon4(addr, &lat, &lon) == 0) {
val = wmem_strdup_printf(NULL, "%f", lat);
c = strchr(val, ',');
if (c != NULL) *c = '.';
ret = val;
}
}
break;
case WS_LON_FAKE_EDITION:
{
float lat;
float lon;
char *c;
if(geoip_db_lookup_latlon4(addr, &lat, &lon) == 0) {
val = wmem_strdup_printf(NULL, "%f", lon);
c = strchr(val, ',');
if (c != NULL) *c = '.';
ret = val;
}
}
break;
default:
break;
}
}
if (ret == NULL) {
if (not_found == NULL)
return NULL;
return wmem_strdup(NULL, not_found);
}
return ret;
}
static int
#if NUM_DB_TYPES > 31
geoip_db_lookup_latlon6(geoipv6_t addr, float *lat, float *lon) {
GeoIP *gi;
GeoIPRecord *gir;
guint i;
for (i = 0; i < geoip_db_num_dbs(); i++) {
gi = g_array_index(geoip_dat_arr, GeoIP *, i);
if (gi) {
switch (gi->databaseType) {
case GEOIP_CITY_EDITION_REV0_V6:
case GEOIP_CITY_EDITION_REV1_V6:
gir = GeoIP_record_by_ipnum_v6(gi, addr);
if(gir) {
*lat = gir->latitude;
*lon = gir->longitude;
return 0;
}
return -1;
default:
break;
}
}
}
return -1;
}
char *
geoip_db_lookup_ipv6(guint dbnum, struct e_in6_addr addr, const char *not_found) {
GeoIP *gi;
geoipv6_t gaddr;
char *name;
const char *country;
char *val, *ret = NULL;
#if NUM_DB_TYPES > 31
GeoIPRecord *gir;
#endif
if (dbnum > geoip_db_num_dbs()) {
if (not_found == NULL)
return NULL;
return wmem_strdup(NULL, not_found);
}
memcpy(&gaddr, &addr, sizeof(addr));
gi = g_array_index(geoip_dat_arr, GeoIP *, dbnum);
if (gi) {
switch (gi->databaseType) {
case GEOIP_COUNTRY_EDITION_V6:
country = GeoIP_country_name_by_ipnum_v6(gi, gaddr);
if (country) {
ret = db_val_to_utf_8(country, gi);
}
break;
#if NUM_DB_TYPES > 31
case GEOIP_CITY_EDITION_REV0_V6:
case GEOIP_CITY_EDITION_REV1_V6:
gir = GeoIP_record_by_ipnum_v6(gi, gaddr);
if (gir && gir->city && gir->region) {
val = wmem_strdup_printf(NULL, "%s, %s", gir->city, gir->region);
ret = db_val_to_utf_8(val, gi);
wmem_free(NULL, val);
} else if (gir && gir->city) {
ret = db_val_to_utf_8(gir->city, gi);
}
break;
case GEOIP_ORG_EDITION_V6:
case GEOIP_ISP_EDITION_V6:
case GEOIP_ASNUM_EDITION_V6:
name = GeoIP_name_by_ipnum_v6(gi, gaddr);
if (name) {
ret = db_val_to_utf_8(name, gi);
GeoIP_free(name);
}
break;
#endif
case WS_LAT_FAKE_EDITION:
{
float lat;
float lon;
char *c;
if(geoip_db_lookup_latlon6(gaddr, &lat, &lon) == 0) {
val = wmem_strdup_printf(NULL, "%f", lat);
c = strchr(val, ',');
if (c != NULL) *c = '.';
ret = val;
}
}
break;
case WS_LON_FAKE_EDITION:
{
float lat;
float lon;
char *c;
if(geoip_db_lookup_latlon6(gaddr, &lat, &lon) == 0) {
val = wmem_strdup_printf(NULL, "%f", lon);
c = strchr(val, ',');
if (c != NULL) *c = '.';
ret = val;
}
}
break;
default:
break;
}
}
if (ret == NULL) {
if (not_found == NULL)
return NULL;
return wmem_strdup(NULL, not_found);
}
return ret;
}
char *
geoip_db_lookup_ipv6(guint dbnum _U_, struct e_in6_addr addr _U_, const char *not_found) {
if (not_found == NULL)
return NULL;
return wmem_strdup(NULL, not_found);
}
gchar *
geoip_db_get_paths(void) {
GString* path_str = NULL;
guint i;
path_str = g_string_new("");
for (i = 0; geoip_db_system_paths[i].path != NULL; i++) {
g_string_append_printf(path_str,
"%s" G_SEARCHPATH_SEPARATOR_S, geoip_db_system_paths[i].path);
}
for (i = 0; i < num_geoip_db_paths; i++) {
if (geoip_db_paths[i].path) {
g_string_append_printf(path_str,
"%s" G_SEARCHPATH_SEPARATOR_S, geoip_db_paths[i].path);
}
}
g_string_truncate(path_str, path_str->len-1);
return g_string_free(path_str, FALSE);
}
guint
geoip_db_num_dbs(void) {
return 0;
}
const gchar *
geoip_db_name(guint dbnum _U_) {
return "Unsupported";
}
int
geoip_db_type(guint dbnum _U_) {
return -1;
}
char *
geoip_db_lookup_ipv4(guint dbnum _U_, guint32 addr _U_, const char *not_found) {
if (not_found == NULL)
return NULL;
return (char *)wmem_strdup(NULL, not_found);
}
char *
geoip_db_lookup_ipv6(guint dbnum _U_, guint32 addr _U_, const char *not_found) {
if (not_found == NULL)
return NULL;
return (char *)wmem_strdup(NULL, not_found);
}
gchar *
geoip_db_get_paths(void) {
return g_strdup("");
}
