static void
change_dissector_if_matched(gpointer item, gpointer user_data)
{
dissector_handle_t handle = (dissector_handle_t)item;
lookup_entry_t * lookup = (lookup_entry_t *)user_data;
const gchar *proto_short_name = dissector_handle_get_short_name(handle);
if (proto_short_name && strcmp(lookup->dissector_short_name, proto_short_name) == 0) {
lookup->handle = handle;
}
}
static prefs_set_pref_e
read_set_decode_as_entries(gchar *key, const gchar *value,
void *user_data _U_,
gboolean return_range_errors _U_)
{
gchar *values[4] = {NULL, NULL, NULL, NULL};
gchar delimiter[4] = {',', ',', ',','\0'};
gchar *pch;
guint i, j;
dissector_table_t sub_dissectors;
prefs_set_pref_e retval = PREFS_SET_OK;
gboolean is_valid = FALSE;
if (strcmp(key, DECODE_AS_ENTRY) == 0) {
for (i = 0; i < 4; i++) {
pch = strchr(value, delimiter[i]);
if (pch == NULL) {
for (j = 0; j < i; j++) {
g_free(values[j]);
}
return PREFS_SET_SYNTAX_ERR;
}
values[i] = g_strndup(value, pch - value);
value = pch + 1;
}
sub_dissectors = find_dissector_table(values[0]);
if (sub_dissectors != NULL) {
lookup_entry_t lookup;
ftenum_t selector_type;
lookup.dissector_short_name = values[3];
lookup.handle = NULL;
selector_type = dissector_table_get_type(sub_dissectors);
g_slist_foreach(dissector_table_get_dissector_handles(sub_dissectors),
change_dissector_if_matched, &lookup);
if (lookup.handle != NULL || g_ascii_strcasecmp(values[3], DECODE_AS_NONE) == 0) {
is_valid = TRUE;
}
if (is_valid) {
if (IS_FT_STRING(selector_type)) {
dissector_change_string(values[0], values[1], lookup.handle);
} else {
char *p;
long long_value;
long_value = strtol(values[1], &p, 0);
if (p == values[0] || *p != '\0' || long_value < 0 ||
(unsigned long)long_value > UINT_MAX) {
retval = PREFS_SET_SYNTAX_ERR;
is_valid = FALSE;
} else
dissector_change_uint(values[0], (guint)long_value, lookup.handle);
}
}
if (is_valid) {
decode_build_reset_list(values[0], selector_type, values[1], NULL, NULL);
}
} else {
retval = PREFS_SET_SYNTAX_ERR;
}
} else {
retval = PREFS_SET_NO_SUCH_PREF;
}
for (i = 0; i < 4; i++) {
g_free(values[i]);
}
return retval;
}
void
load_decode_as_entries(void)
{
char *daf_path;
FILE *daf;
if (dissector_reset_list) {
decode_clear_all();
}
daf_path = get_persconffile_path(DECODE_AS_ENTRIES_FILE_NAME, TRUE);
if ((daf = ws_fopen(daf_path, "r")) != NULL) {
read_prefs_file(daf_path, daf, read_set_decode_as_entries, NULL);
fclose(daf);
}
g_free(daf_path);
}
void
decode_build_reset_list (const gchar *table_name, ftenum_t selector_type,
gpointer key, gpointer value _U_,
gpointer user_data _U_)
{
dissector_delete_item_t *item;
item = g_new(dissector_delete_item_t,1);
item->ddi_table_name = g_strdup(table_name);
item->ddi_selector_type = selector_type;
switch (selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
item->ddi_selector.sel_uint = GPOINTER_TO_UINT(key);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
item->ddi_selector.sel_string = g_strdup((char *)key);
break;
default:
g_assert_not_reached();
}
dissector_reset_list = g_slist_prepend(dissector_reset_list, item);
}
void
decode_clear_all(void)
{
dissector_delete_item_t *item;
GSList *tmp;
dissector_all_tables_foreach_changed(decode_build_reset_list, NULL);
for (tmp = dissector_reset_list; tmp; tmp = g_slist_next(tmp)) {
item = (dissector_delete_item_t *)tmp->data;
switch (item->ddi_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
dissector_reset_uint(item->ddi_table_name,
item->ddi_selector.sel_uint);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_reset_string(item->ddi_table_name,
item->ddi_selector.sel_string);
g_free(item->ddi_selector.sel_string);
break;
default:
g_assert_not_reached();
}
g_free(item->ddi_table_name);
g_free(item);
}
g_slist_free(dissector_reset_list);
dissector_reset_list = NULL;
decode_dcerpc_reset_all();
}
static void
decode_as_write_entry (const gchar *table_name, ftenum_t selector_type,
gpointer key, gpointer value, gpointer user_data)
{
FILE *da_file = (FILE *)user_data;
dissector_handle_t current, initial;
const gchar *current_proto_name, *initial_proto_name;
current = dtbl_entry_get_handle((dtbl_entry_t *)value);
if (current == NULL)
current_proto_name = DECODE_AS_NONE;
else
current_proto_name = dissector_handle_get_short_name(current);
initial = dtbl_entry_get_initial_handle((dtbl_entry_t *)value);
if (initial == NULL)
initial_proto_name = DECODE_AS_NONE;
else
initial_proto_name = dissector_handle_get_short_name(initial);
switch (selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
fprintf (da_file,
DECODE_AS_ENTRY ": %s,%u,%s,%s\n",
table_name, GPOINTER_TO_UINT(key), initial_proto_name,
current_proto_name);
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
fprintf (da_file,
DECODE_AS_ENTRY ": %s,%s,%s,%s\n",
table_name, (gchar *)key, initial_proto_name,
current_proto_name);
break;
default:
g_assert_not_reached();
break;
}
}
int
save_decode_as_entries(gchar** err)
{
char *pf_dir_path;
char *daf_path;
FILE *da_file;
if (create_persconffile_dir(&pf_dir_path) == -1) {
*err = g_strdup_printf("Can't create directory\n\"%s\"\nfor recent file: %s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
return -1;
}
daf_path = get_persconffile_path(DECODE_AS_ENTRIES_FILE_NAME, TRUE);
if ((da_file = ws_fopen(daf_path, "w")) == NULL) {
*err = g_strdup_printf("Can't open decode_as_entries file\n\"%s\": %s.",
daf_path, g_strerror(errno));
g_free(daf_path);
return -1;
}
fputs("# \"Decode As\" entries file for Wireshark " VERSION ".\n"
"#\n"
"# This file is regenerated each time \"Decode As\" preferences\n"
"# are saved within Wireshark. Making manual changes should be safe,\n"
"# however.\n", da_file);
dissector_all_tables_foreach_changed(decode_as_write_entry, da_file);
fclose(da_file);
return 0;
}
static void
display_dissector_table_names(const char *table_name, const char *ui_name,
gpointer output)
{
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, table_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n", table_name, ui_name);
prev_display_dissector_name = table_name;
}
}
static void
display_dissector_names(const gchar *table _U_, gpointer handle, gpointer output)
{
int proto_id;
const gchar *proto_filter_name;
const gchar *proto_ui_name;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
proto_filter_name = proto_get_protocol_filter_name(proto_id);
proto_ui_name = proto_get_protocol_name(proto_id);
g_assert(proto_filter_name != NULL);
g_assert(proto_ui_name != NULL);
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, proto_filter_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n",
proto_filter_name,
proto_ui_name);
prev_display_dissector_name = proto_filter_name;
}
}
}
static gint
compare_dissector_key_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
return strcmp((const char*)dissector_a, (const char*)dissector_b);
}
static void
fprint_all_layer_types(FILE *output)
{
prev_display_dissector_name = NULL;
dissector_all_tables_foreach_table(display_dissector_table_names, (gpointer)output, (GCompareFunc)compare_dissector_key_name);
}
static void
fprint_all_protocols_for_layer_types(FILE *output, gchar *table_name)
{
prev_display_dissector_name = NULL;
dissector_table_foreach_handle(table_name,
display_dissector_names,
(gpointer)output);
}
static void
find_protocol_name_func(const gchar *table _U_, gpointer handle, gpointer user_data)
{
int proto_id;
const gchar *protocol_filter_name;
protocol_name_search_t search_info;
g_assert(handle);
search_info = (protocol_name_search_t)user_data;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
protocol_filter_name = proto_get_protocol_filter_name(proto_id);
g_assert(protocol_filter_name != NULL);
if (strcmp(protocol_filter_name, search_info->searched_name) == 0) {
if (search_info->nb_match == 0) {
search_info->matched_handle = (dissector_handle_t)handle;
}
search_info->nb_match++;
}
}
}
gboolean decode_as_command_option(const gchar *cl_param)
{
gchar *table_name;
guint32 selector, selector2;
gchar *decoded_param;
gchar *remaining_param;
gchar *selector_str;
gchar *dissector_str;
dissector_handle_t dissector_matching;
dissector_table_t table_matching;
ftenum_t dissector_table_selector_type;
struct protocol_name_search user_protocol_name;
guint64 i;
char op;
g_assert(cl_param);
decoded_param = g_strdup(cl_param);
g_assert(decoded_param);
table_name = decoded_param;
remaining_param = strchr(table_name, '=');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, DECODE_AS_ARG_TEMPLATE);
}
else {
*remaining_param = '\0';
}
while (table_name[0] == ' ')
table_name++;
while (table_name[strlen(table_name) - 1] == ' ')
table_name[strlen(table_name) - 1] = '\0';
table_matching = NULL;
if (!(*(table_name))) {
cmdarg_err("No layer type specified");
}
else {
table_matching = find_dissector_table(table_name);
if (!table_matching) {
cmdarg_err("Unknown layer type -- %s", table_name);
}
}
if (!table_matching) {
cmdarg_err("Valid layer types are:");
fprint_all_layer_types(stderr);
}
if (remaining_param == NULL || !table_matching) {
g_free(decoded_param);
return FALSE;
}
if (*(remaining_param + 1) != '=') {
cmdarg_err("WARNING: -d requires \"==\" instead of \"=\". Option will be treated as \"%s==%s\"", table_name, remaining_param + 1);
}
else {
remaining_param++;
*remaining_param = '\0';
}
remaining_param++;
selector_str = remaining_param;
remaining_param = strchr(selector_str, ',');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, DECODE_AS_ARG_TEMPLATE);
}
else {
*remaining_param = '\0';
}
dissector_table_selector_type = get_dissector_table_selector_type(table_name);
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
switch (sscanf(selector_str, "%u%c%u", &selector, &op, &selector2)) {
case 1:
op = '\0';
break;
case 3:
if (op != ':' && op != '-') {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
if (op == ':') {
if ((selector2 == 0) || ((guint64)selector + selector2 - 1) > G_MAXUINT32) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
}
else if (selector2 < selector) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
default:
cmdarg_err("Invalid selector number \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
break;
default:
g_assert_not_reached();
}
if (remaining_param == NULL) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
remaining_param++;
dissector_str = remaining_param;
while (dissector_str[0] == ' ')
dissector_str++;
while (dissector_str[strlen(dissector_str) - 1] == ' ')
dissector_str[strlen(dissector_str) - 1] = '\0';
dissector_matching = NULL;
if (!(*dissector_str)) {
cmdarg_err("No protocol name specified");
}
else {
user_protocol_name.nb_match = 0;
user_protocol_name.searched_name = dissector_str;
user_protocol_name.matched_handle = NULL;
dissector_table_foreach_handle(table_name, find_protocol_name_func, &user_protocol_name);
if (user_protocol_name.nb_match != 0) {
dissector_matching = user_protocol_name.matched_handle;
if (user_protocol_name.nb_match > 1) {
cmdarg_err("WARNING: Protocol \"%s\" matched %u dissectors, first one will be used", dissector_str, user_protocol_name.nb_match);
}
}
else {
if (proto_get_id_by_filter_name(dissector_str) == -1) {
cmdarg_err("Unknown protocol -- \"%s\"", dissector_str);
}
else {
cmdarg_err("Protocol \"%s\" isn't valid for layer type \"%s\"",
dissector_str, table_name);
}
}
}
if (!dissector_matching) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (op == '\0') {
dissector_change_uint(table_name, selector, dissector_matching);
}
else if (op == ':') {
for (i = selector; i < (guint64)selector + selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
}
else {
for (i = selector; i <= selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_change_string(table_name, selector_str, dissector_matching);
break;
default:
g_assert_not_reached();
}
g_free(decoded_param);
return TRUE;
}
