void proto_help_menu_modify(GtkTreeSelection *selection _U_, capture_file *cf _U_) {}
void proto_help_menu_init(GtkWidget *widget _U_) {}
void proto_help_init(void) {}
void proto_help_init(void)
{
gchar *search_dir[PH_CONF_DIRS];
const gchar *ini_name;
gchar *ini_path;
GDir *conf_dir;
int i;
search_dir[0] = g_strdup_printf("%s" G_DIR_SEPARATOR_S PH_CONFFILE_SUBDIR, get_datafile_dir());
search_dir[1] = get_persconffile_path(PH_CONFFILE_SUBDIR, FALSE, FALSE);
#ifdef PH_DEBUG_LOG
g_log_set_handler(NULL, G_LOG_LEVEL_MASK | G_LOG_FLAG_FATAL | G_LOG_FLAG_RECURSION, ph_logging_handler, NULL);
#endif
if (g_ph_key_files)
return;
g_ph_key_files = g_ptr_array_new();
#ifdef PH_DEBUG_LOG
ph_log_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", g_get_tmp_dir(), PH_FILE_LOG);
#endif
for (i = 0; i < PH_CONF_DIRS; i++) {
g_log(NULL, G_LOG_LEVEL_INFO, "Looking for protocol help files in '%s'", search_dir[i]);
conf_dir = g_dir_open(search_dir[i], 0, NULL);
if (!conf_dir) {
continue;
}
while ((ini_name = g_dir_read_name(conf_dir)) != NULL) {
if (! g_str_has_suffix(ini_name, PH_INI_SUFFIX)) {
continue;
}
g_log(NULL, G_LOG_LEVEL_INFO, "-- Found '%s'", ini_name);
ini_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s", search_dir[i], ini_name);
ph_ini_load_file(ini_path);
g_free(ini_path);
}
g_dir_close(conf_dir);
}
}
void proto_help_menu_init(GtkWidget *widget)
{
g_ph_menu_factory = gtk_item_factory_from_widget(widget);
ph_menu_reset();
}
static void ph_menu_reset(void)
{
GtkWidget *menu_item = NULL;
GList *menu_entries = NULL;
GList *menu_entry = NULL;
if(!g_ph_menu_factory) return;
menu_item = gtk_item_factory_get_widget(g_ph_menu_factory, PH_MENU_TOP);
menu_entries = gtk_container_get_children(GTK_CONTAINER(menu_item));
for(menu_entry = g_list_first(menu_entries); menu_entry != NULL; menu_entry = g_list_next(menu_entry))
{
gtk_container_remove(GTK_CONTAINER(menu_item), menu_entry->data);
}
menu_item = gtk_item_factory_get_item(g_ph_menu_factory, PH_MENU_TOP);
gtk_widget_set_sensitive(menu_item, FALSE);
}
static void
url_destroy_cb(GtkWidget *w _U_, gpointer url) {
g_free(url);
}
void proto_help_menu_modify(GtkTreeSelection *selection, capture_file *cf)
{
gchar *description;
const gchar *proto_abbrev, *proto_name;
gchar *value;
gchar **keys;
GHashTable *table;
guint i = 0, cur_kf;
GtkWidget *menu_item = NULL;
GtkItemFactoryEntry *menu_entry = NULL;
proto_help_key_file* phkf;
gchar *loc;
gboolean add_separator = FALSE;
gboolean found = FALSE;
if(!g_ph_menu_factory) return;
ph_menu_reset();
proto_abbrev = ph_capture_get_protocol_abbrev(selection, cf);
if(!proto_abbrev) return;
proto_name = ph_capture_get_protocol_name(selection, cf);
if(!proto_name) return;
description = ph_capture_get_description(cf);
for (cur_kf = 0; cur_kf < g_ph_key_files->len; cur_kf++) {
phkf = (proto_help_key_file *) g_ptr_array_index(g_ph_key_files, cur_kf);
g_assert(phkf);
value = ph_ini_get_path(phkf->keyfile, proto_abbrev, PH_INI_KEY_OVERVIEW);
if(!value)
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Overview page of the protocol '%s' is not defined", proto_abbrev);
continue;
}
loc = string_replace(phkf->loc_template, PH_PATH_SEARCH_STR, value);
g_free(value);
if (!loc || !strlen(loc)) continue;
if (add_separator) {
menu_entry = g_malloc0(sizeof(GtkItemFactoryEntry));
menu_entry->path = g_strdup_printf("%s/<separator>", PH_MENU_TOP);
menu_entry->item_type = "<Separator>";
gtk_item_factory_create_item(g_ph_menu_factory, menu_entry, NULL, 2);
}
add_separator = TRUE;
menu_entry = g_malloc0(sizeof(GtkItemFactoryEntry));
menu_entry->path = g_strdup_printf("%s/%s %s Overview", PH_MENU_TOP, phkf->source, proto_name);
menu_entry->callback = ph_menu_onclick;
gtk_item_factory_create_item(g_ph_menu_factory, menu_entry, loc, 2);
menu_item = gtk_item_factory_get_widget(g_ph_menu_factory, menu_entry->path);
g_assert(menu_item);
g_signal_connect(menu_item, "destroy", G_CALLBACK(url_destroy_cb), loc);
found = TRUE;
if(description)
{
keys = ph_ini_get_keywords(phkf->keyfile, proto_abbrev);
table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
for(i = 0; keys[i] != NULL; i++)
{
if(!strcmp(keys[i], PH_INI_KEY_OVERVIEW)) continue;
if(!ph_parse_string(description, keys[i])) continue;
if(g_hash_table_lookup(table, g_ascii_strup(keys[i], -1)) != NULL) continue;
value = ph_ini_get_path(phkf->keyfile, proto_abbrev, keys[i]);
if(!value || !strlen(value)) continue;
loc = string_replace(phkf->loc_template, PH_PATH_SEARCH_STR, value);
g_free(value);
if (!loc || !strlen(loc)) continue;
g_hash_table_insert(table, g_ascii_strup(keys[i], -1), GINT_TO_POINTER(1));
menu_entry = g_malloc0(sizeof(GtkItemFactoryEntry));
menu_entry->path = g_strdup_printf("%s/%s", PH_MENU_TOP, keys[i]);
menu_entry->callback = ph_menu_onclick;
gtk_item_factory_create_item(g_ph_menu_factory, menu_entry, loc, 2);
menu_item = gtk_item_factory_get_widget(g_ph_menu_factory, menu_entry->path);
g_assert(menu_item);
g_signal_connect(menu_item, "destroy", G_CALLBACK(url_destroy_cb), loc);
}
g_hash_table_destroy(table);
}
}
g_free(description);
menu_item = gtk_item_factory_get_item(g_ph_menu_factory, PH_MENU_TOP);
gtk_widget_set_sensitive(menu_item, found);
}
static void ph_menu_onclick(GtkWidget *widget _U_, gpointer data, guint action _U_)
{
gchar *loc = (gchar *) data;
g_log(NULL, G_LOG_LEVEL_DEBUG, "Sending '%s' to the browser.", loc);
if (! loc) {
g_log(NULL, G_LOG_LEVEL_DEBUG, "Protocol help ended up with a NULL URL.");
return;
}
if (! browser_open_url(loc)) {
g_log(NULL, G_LOG_LEVEL_DEBUG, "Couldn't get protocol help for %s", loc);
}
}
static int
ph_capture_get_protocol_id(GtkTreeSelection *selection, capture_file *cf)
{
GtkTreeModel *model = NULL;
GtkTreeIter iter;
GtkTreeIter parent;
field_info *finfo = NULL;
int proto_id = 0;
if(!cf->finfo_selected) return 0;
proto_id = cf->finfo_selected->hfinfo->id;
if(!proto_id)
{
if(!gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model, &iter)) return 0;
while(gtk_tree_model_iter_parent(model, &parent, &iter))
{
gtk_tree_model_get(model, &parent, 1, &finfo, -1);
iter = parent;
if(finfo->hfinfo->id > 0)
{
proto_id = finfo->hfinfo->id;
break;
}
}
}
while(proto_id && !proto_registrar_is_protocol(proto_id))
{
proto_id = proto_registrar_get_parent(proto_id);
}
return proto_id;
}
static const gchar*
ph_capture_get_protocol_name(GtkTreeSelection *selection, capture_file *cf)
{
int proto_id = ph_capture_get_protocol_id(selection, cf);
return (!proto_id) ? NULL : proto_get_protocol_short_name(find_protocol_by_id(proto_id));
}
static const gchar*
ph_capture_get_protocol_abbrev(GtkTreeSelection *selection, capture_file *cf)
{
int proto_id = ph_capture_get_protocol_id(selection, cf);
return (!proto_id) ? NULL : proto_registrar_get_abbrev(proto_id);
}
static gchar* ph_capture_get_description(capture_file *cf)
{
gchar *buffer = NULL;
if(cf->finfo_selected->rep &&
strlen(cf->finfo_selected->rep->representation) > 0)
{
buffer = g_strdup(cf->finfo_selected->rep->representation);
}
else
{
buffer = g_malloc(ITEM_LABEL_LENGTH);
proto_item_fill_label(cf->finfo_selected, buffer);
}
return buffer;
}
static proto_help_key_file *
ph_ini_load_file(const gchar *filename)
{
GKeyFile *kf;
GError *error = NULL;
proto_help_key_file *phkf = NULL;
gchar *old_template, *loc_template;
gchar **loc_data, *loc_repl, *loc_search;
gsize i, len;
if(!g_file_test(filename, G_FILE_TEST_EXISTS))
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Configuration file %s does not exists", filename);
return NULL;
}
kf = g_key_file_new();
if(!g_key_file_load_from_file(kf, filename, G_KEY_FILE_NONE, &error))
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Configuration file '%s' could not be loaded (%s)", filename, error->message);
g_error_free(error);
g_key_file_free(kf);
return NULL;
}
loc_template = ph_ini_get_value(kf, PH_INI_GROUP_DATABASE, PH_INI_DB_KEY_LOCATION_TEMPLATE, NULL);
if (!loc_template) {
g_key_file_free(kf);
return NULL;
}
loc_data = g_key_file_get_keys(kf, PH_INI_GROUP_LOCATION_DATA, &len, NULL);
if (loc_data) {
for (i = 0; i < len; i++) {
loc_repl = ph_ini_get_value(kf, PH_INI_GROUP_LOCATION_DATA, loc_data[i], NULL);
old_template = loc_template;
loc_search = g_strdup_printf("${%s}", loc_data[i]);
loc_template = string_replace(loc_template, loc_search, loc_repl);
g_free(loc_repl);
g_free(loc_search);
g_free(old_template);
}
}
if (!strstr(loc_template, PH_PATH_SEARCH_STR)) {
old_template = loc_template;
loc_template = g_strdup_printf("%s" PH_PATH_SEARCH_STR, old_template);
g_free(old_template);
}
phkf = g_malloc(sizeof(proto_help_key_file));
phkf->keyfile = kf;
phkf->source = ph_ini_get_value(kf, PH_INI_GROUP_DATABASE, PH_INI_DB_KEY_SOURCE, "(Unknown source)");
phkf->loc_template = loc_template;
g_ptr_array_add(g_ph_key_files, phkf);
return phkf;
}
static gchar*
ph_ini_get_value(GKeyFile *keyfile, const gchar *group, const gchar *key, gchar *alt)
{
gchar *value = NULL;
if (keyfile) {
value = g_key_file_get_string(keyfile, group, key, NULL);
}
if (!value) {
value = g_strdup(alt);
}
return value;
}
static gchar*
ph_ini_get_path(GKeyFile *keyfile, const gchar *protocol, const gchar *keyword)
{
GError *error = NULL;
gchar *map;
gchar *value;
if(!keyfile || !protocol || !keyword) return NULL;
map = g_key_file_get_string(keyfile, PH_INI_GROUP_MAP, protocol, &error);
if(!map)
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Protocol '%s' is not defined (%s)", protocol, error->message);
g_error_free(error);
return NULL;
}
value = g_key_file_get_string(keyfile, map, keyword, NULL);
g_free(map);
return value;
}
static gchar**
ph_ini_get_keywords(GKeyFile *keyfile, const gchar *protocol)
{
GError *error = NULL;
gchar *map;
gchar **keys;
gsize length = 0;
if(!keyfile) return NULL;
map = g_key_file_get_string(keyfile, PH_INI_GROUP_MAP, protocol, &error);
if(!map)
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Protocol '%s' is not defined (%s)", protocol, error->message);
g_error_free(error);
return NULL;
}
error = NULL;
keys = g_key_file_get_keys(keyfile, map, &length, &error);
g_free(map);
if(!keys)
{
g_log(NULL, G_LOG_LEVEL_DEBUG, "Display titles are not defined (%s)", protocol);
g_error_free(error);
}
return keys;
}
static guint ph_parse_string(const gchar *description, const gchar *value)
{
GRegex *regex = NULL;
GMatchInfo *match_info = NULL;
gchar *pattern = NULL;
guint result = 0;
pattern = g_strdup_printf("(?<![0-9a-zA-Z_])%s(?![0-9a-zA-Z_])", value);
regex = g_regex_new(pattern, 0, 0, NULL);
g_regex_match(regex, description, 0, &match_info);
if(g_match_info_matches(match_info)) result = 1;
g_match_info_free(match_info);
g_regex_unref(regex);
return result;
}
static void ph_logging_handler(const gchar *domain _U_, GLogLevelFlags level, const gchar *message, gpointer data _U_)
{
gchar *log = NULL;
gchar *type = NULL;
FILE *file = NULL;
struct tm *timestamp = NULL;
time_t now;
time(&now);
timestamp = localtime(&now);
switch(level & G_LOG_LEVEL_MASK)
{
case G_LOG_LEVEL_ERROR:
type = "ERR";
break;
case G_LOG_LEVEL_DEBUG:
type = "WARNING";
break;
case G_LOG_LEVEL_INFO:
type = "INFO";
break;
default:
type = "OTHER";
}
file = ws_fopen(ph_log_path, "a+");
if(file)
{
log = g_strdup_printf("[%04u-%02u-%02u %02u:%02u:%02u %s] %s\n", timestamp->tm_year + 1900, timestamp->tm_mon + 1, timestamp->tm_mday, timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec, type, message);
fputs(log, file);
fclose(file);
}
}
