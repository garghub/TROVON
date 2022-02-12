void
prefs_init(void)
{
prefs_modules = pe_tree_create(EMEM_TREE_TYPE_RED_BLACK, "prefs_modules");
prefs_top_level_modules = pe_tree_create(EMEM_TREE_TYPE_RED_BLACK, "prefs_top_level_modules");
}
static void
free_pref(gpointer data, gpointer user_data _U_)
{
pref_t *pref = data;
switch (pref->type) {
case PREF_OBSOLETE:
case PREF_BOOL:
case PREF_ENUM:
case PREF_UINT:
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_STRING:
case PREF_FILENAME:
g_free((char *)*pref->varp.string);
*pref->varp.string = NULL;
g_free(pref->default_val.string);
break;
case PREF_RANGE:
g_free(*pref->varp.range);
*pref->varp.range = NULL;
g_free(pref->default_val.range);
break;
}
g_free(pref);
}
static guint
free_module_prefs(module_t *module, gpointer data _U_)
{
g_list_foreach(module->prefs, free_pref, NULL);
g_list_free(module->prefs);
module->prefs = NULL;
module->numprefs = 0;
return 0;
}
void
prefs_cleanup(void)
{
prefs_modules_foreach(free_module_prefs, NULL);
free_prefs(&prefs);
}
module_t *
prefs_register_module(module_t *parent, const char *name, const char *title,
const char *description, void (*apply_cb)(void))
{
return prefs_register_module_or_subtree(parent, name, title, description,
FALSE, apply_cb);
}
module_t *
prefs_register_subtree(module_t *parent, const char *title, const char *description)
{
return prefs_register_module_or_subtree(parent, NULL, title,
description, TRUE, NULL);
}
static module_t *
prefs_register_module_or_subtree(module_t *parent, const char *name,
const char *title, const char *description,
gboolean is_subtree, void (*apply_cb)(void))
{
module_t *module;
const char *p;
guchar c;
if((module = find_subtree(parent, title))) {
module->name = name;
module->apply_cb = apply_cb;
module->description = description;
if (prefs_find_module(name) == NULL) {
pe_tree_insert_string(prefs_modules, name, module,
EMEM_TREE_STRING_NOCASE);
}
return module;
}
module = g_malloc(sizeof (module_t));
module->name = name;
module->title = title;
module->description = description;
module->apply_cb = apply_cb;
module->prefs = NULL;
module->submodules = NULL;
module->numprefs = 0;
module->prefs_changed = FALSE;
module->obsolete = FALSE;
if (name != NULL) {
for (p = name; (c = *p) != '\0'; p++)
g_assert(isascii(c) &&
(islower(c) || isdigit(c) || c == '_' ||
c == '-' || c == '.'));
g_assert(prefs_find_module(name) == NULL);
pe_tree_insert_string(prefs_modules, name, module, EMEM_TREE_STRING_NOCASE);
} else {
g_assert(is_subtree);
}
if (parent == NULL) {
pe_tree_insert_string(prefs_top_level_modules, title, module, EMEM_TREE_STRING_NOCASE);
} else {
if (parent->submodules == NULL)
parent->submodules = pe_tree_create(EMEM_TREE_TYPE_RED_BLACK, "prefs_submodules");
pe_tree_insert_string(parent->submodules, title, module, EMEM_TREE_STRING_NOCASE);
}
return module;
}
module_t *
prefs_register_protocol(int id, void (*apply_cb)(void))
{
protocol_t *protocol;
if (protocols_module == NULL) {
protocols_module = prefs_register_subtree(NULL, "Protocols", NULL);
}
protocol = find_protocol_by_id(id);
return prefs_register_module(protocols_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), apply_cb);
}
module_t *
prefs_register_protocol_subtree(const char *subtree, int id, void (*apply_cb)(void))
{
protocol_t *protocol;
module_t *subtree_module;
module_t *new_module;
char *sep = NULL, *ptr = NULL;
if (protocols_module == NULL) {
protocols_module = prefs_register_subtree(NULL, "Protocols", NULL);
}
subtree_module = protocols_module;
if(subtree) {
ptr = g_strdup(subtree);
while(ptr && *ptr) {
if((sep = strchr(ptr, '/')))
*sep++ = '\0';
if(!(new_module = find_subtree(subtree_module, ptr))) {
new_module = prefs_register_subtree(subtree_module, ptr, NULL);
}
subtree_module = new_module;
ptr = sep;
}
}
protocol = find_protocol_by_id(id);
return prefs_register_module(subtree_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), apply_cb);
}
module_t *
prefs_register_protocol_obsolete(int id)
{
module_t *module;
protocol_t *protocol;
if (protocols_module == NULL) {
protocols_module = prefs_register_subtree(NULL, "Protocols", NULL);
}
protocol = find_protocol_by_id(id);
module = prefs_register_module(protocols_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), NULL);
module->obsolete = TRUE;
return module;
}
module_t *
prefs_find_module(const char *name)
{
return pe_tree_lookup_string(prefs_modules, name, EMEM_TREE_STRING_NOCASE);
}
static module_t *
find_subtree(module_t *parent, const char *name)
{
return pe_tree_lookup_string(parent ? parent->submodules : prefs_top_level_modules, name, EMEM_TREE_STRING_NOCASE);
}
static gboolean
call_foreach_cb(void *value, void *data)
{
module_t *module = (module_t*)value;
call_foreach_t *call_data = (call_foreach_t*)data;
if (!module->obsolete) {
call_data->ret = (*call_data->callback)(module, call_data->user_data);
}
return (call_data->ret != 0);
}
static guint
prefs_module_list_foreach(emem_tree_t *module_list, module_cb callback,
gpointer user_data)
{
call_foreach_t call_data;
if (module_list == NULL)
module_list = prefs_top_level_modules;
call_data.callback = callback;
call_data.user_data = user_data;
call_data.ret = 0;
pe_tree_foreach(module_list, call_foreach_cb, &call_data);
return call_data.ret;
}
gboolean
prefs_module_has_submodules(module_t *module)
{
if (module->submodules == NULL) {
return FALSE;
}
if (module->submodules->tree == NULL) {
return FALSE;
}
return TRUE;
}
guint
prefs_modules_foreach(module_cb callback, gpointer user_data)
{
return prefs_module_list_foreach(prefs_modules, callback, user_data);
}
guint
prefs_modules_foreach_submodules(module_t *module, module_cb callback,
gpointer user_data)
{
return prefs_module_list_foreach((module)?module->submodules:prefs_top_level_modules, callback, user_data);
}
static gboolean
call_apply_cb(void *value, void *data _U_)
{
module_t *module = value;
if (module->obsolete)
return FALSE;
if (module->prefs_changed) {
if (module->apply_cb != NULL)
(*module->apply_cb)();
module->prefs_changed = FALSE;
}
return FALSE;
}
void
prefs_apply_all(void)
{
pe_tree_foreach(prefs_modules, call_apply_cb, NULL);
}
void
prefs_apply(module_t *module)
{
if (module && module->prefs_changed)
call_apply_cb(module, NULL);
}
static pref_t *
register_preference(module_t *module, const char *name, const char *title,
const char *description, pref_type_t type)
{
pref_t *preference;
const gchar *p;
preference = g_malloc(sizeof (pref_t));
preference->name = name;
preference->title = title;
preference->description = description;
preference->type = type;
if (title != NULL)
preference->ordinal = module->numprefs;
else
preference->ordinal = -1;
for (p = name; *p != '\0'; p++)
if (!(isascii((guchar)*p) &&
(islower((guchar)*p) || isdigit((guchar)*p) || *p == '_' || *p == '.')))
g_error("Preference %s.%s contains invalid characters", module->name, name);
if (prefs_find_preference(module, name) != NULL)
g_error("Preference %s has already been registered", name);
if (type != PREF_OBSOLETE) {
if(!((strncmp(name, module->name, strlen(module->name)) != 0) ||
(((name[strlen(module->name)]) != '.') && ((name[strlen(module->name)]) != '_'))))
g_error("Preference %s begins with the module name", name);
}
module->prefs = g_list_append(module->prefs, preference);
if (title != NULL)
module->numprefs++;
return preference;
}
static gint
preference_match(gconstpointer a, gconstpointer b)
{
const pref_t *pref = a;
const char *name = b;
return strcmp(name, pref->name);
}
struct preference *
prefs_find_preference(module_t *module, const char *name)
{
GList *list_entry;
if (module == NULL)
return NULL;
list_entry = g_list_find_custom(module->prefs, name,
preference_match);
if (list_entry == NULL)
return NULL;
return (struct preference *) list_entry->data;
}
gboolean
prefs_is_registered_protocol(const char *name)
{
module_t *m = prefs_find_module(name);
return (m != NULL && !m->obsolete);
}
const char *
prefs_get_title_by_name(const char *name)
{
module_t *m = prefs_find_module(name);
return (m != NULL && !m->obsolete) ? m->title : NULL;
}
void
prefs_register_uint_preference(module_t *module, const char *name,
const char *title, const char *description,
guint base, guint *var)
{
pref_t *preference;
preference = register_preference(module, name, title, description,
PREF_UINT);
preference->varp.uint = var;
preference->default_val.uint = *var;
g_assert(base > 0 && base != 1 && base < 37);
preference->info.base = base;
}
void
prefs_register_bool_preference(module_t *module, const char *name,
const char *title, const char *description,
gboolean *var)
{
pref_t *preference;
preference = register_preference(module, name, title, description,
PREF_BOOL);
preference->varp.boolp = var;
preference->default_val.boolval = *var;
}
void
prefs_register_enum_preference(module_t *module, const char *name,
const char *title, const char *description,
gint *var, const enum_val_t *enumvals,
gboolean radio_buttons)
{
pref_t *preference;
preference = register_preference(module, name, title, description,
PREF_ENUM);
preference->varp.enump = var;
preference->default_val.enumval = *var;
preference->info.enum_info.enumvals = enumvals;
preference->info.enum_info.radio_buttons = radio_buttons;
}
static void
register_string_like_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var, pref_type_t type)
{
pref_t *preference;
char *varcopy;
preference = register_preference(module, name, title, description,
type);
if (*var == NULL) {
*var = g_strdup("");
varcopy = g_strdup("");
} else {
*var = g_strdup(*var);
varcopy = g_strdup(*var);
}
preference->varp.string = var;
preference->default_val.string = varcopy;
preference->saved_val.string = NULL;
}
void
prefs_register_string_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var)
{
register_string_like_preference(module, name, title, description, var,
PREF_STRING);
}
void
prefs_register_filename_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var)
{
register_string_like_preference(module, name, title, description, var,
PREF_FILENAME);
}
void
prefs_register_range_preference(module_t *module, const char *name,
const char *title, const char *description,
range_t **var, guint32 max_value)
{
pref_t *preference;
preference = register_preference(module, name, title, description,
PREF_RANGE);
preference->info.max_value = max_value;
if (*var == NULL)
*var = range_empty();
preference->varp.range = var;
preference->default_val.range = range_copy(*var);
preference->saved_val.range = NULL;
}
void
prefs_register_static_text_preference(module_t *module, const char *name,
const char *title,
const char *description)
{
register_preference(module, name, title, description, PREF_STATIC_TEXT);
}
extern void
prefs_register_uat_preference(module_t *module, const char *name,
const char *title, const char *description,
void* uat)
{
pref_t* preference = register_preference(module, name, title, description, PREF_UAT);
preference->varp.uat = uat;
}
void
prefs_register_obsolete_preference(module_t *module, const char *name)
{
register_preference(module, name, NULL, NULL, PREF_OBSOLETE);
}
extern gboolean
prefs_get_preference_obsolete(pref_t *pref)
{
if (pref) {
return pref->type == PREF_OBSOLETE ? TRUE : FALSE;
}
return TRUE;
}
extern prefs_set_pref_e
prefs_set_preference_obsolete(pref_t *pref)
{
if (pref) {
pref->type = PREF_OBSOLETE;
return PREFS_SET_OK;
}
return PREFS_SET_NO_SUCH_PREF;
}
guint prefs_get_uint_preference(pref_t *pref)
{
if (pref && pref->type == PREF_UINT)
return *pref->varp.uint;
return 0;
}
guint
prefs_pref_foreach(module_t *module, pref_cb callback, gpointer user_data)
{
GList *elem;
pref_t *pref;
guint ret;
for (elem = g_list_first(module->prefs); elem != NULL; elem = g_list_next(elem)) {
pref = elem->data;
if (pref->type == PREF_OBSOLETE) {
continue;
}
ret = (*callback)(pref, user_data);
if (ret != 0)
return ret;
}
return 0;
}
void
prefs_register_modules(void)
{
}
GList *
prefs_get_string_list(gchar *str)
{
enum { PRE_STRING, IN_QUOT, NOT_IN_QUOT };
gint state = PRE_STRING, i = 0, j = 0;
gboolean backslash = FALSE;
guchar cur_c;
gchar *slstr = NULL;
GList *sl = NULL;
slstr = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
j = 0;
for (;;) {
cur_c = str[i];
if (cur_c == '\0') {
if (state == IN_QUOT || backslash) {
g_free(slstr);
prefs_clear_string_list(sl);
return NULL;
}
slstr[j] = '\0';
sl = g_list_append(sl, slstr);
break;
}
if (cur_c == '"' && ! backslash) {
switch (state) {
case PRE_STRING:
state = IN_QUOT;
break;
case IN_QUOT:
state = NOT_IN_QUOT;
break;
case NOT_IN_QUOT:
state = IN_QUOT;
break;
default:
break;
}
} else if (cur_c == '\\' && ! backslash) {
backslash = TRUE;
if (state == PRE_STRING)
state = NOT_IN_QUOT;
} else if (cur_c == ',' && state != IN_QUOT && ! backslash) {
slstr[j] = '\0';
sl = g_list_append(sl, slstr);
state = PRE_STRING;
slstr = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
j = 0;
} else if (!isspace(cur_c) || state != PRE_STRING) {
if (j < COL_MAX_LEN) {
slstr[j] = cur_c;
j++;
}
backslash = FALSE;
}
i++;
}
return(sl);
}
static gchar *
put_string_list(GList *sl)
{
static gchar pref_str[MAX_FMT_PREF_LEN] = "";
GList *clp = g_list_first(sl);
gchar *str;
size_t cur_len = 0;
gchar *quoted_str;
size_t str_len;
gchar *strp, *quoted_strp, c;
size_t fmt_len;
guint item_count = 0;
while (clp) {
item_count++;
str = clp->data;
str_len = strlen(str);
quoted_str = g_malloc(str_len*2 + 1);
strp = str;
quoted_strp = quoted_str;
while ((c = *strp++) != '\0') {
if (c == '"' || c == '\\') {
*quoted_strp++ = '\\';
}
*quoted_strp++ = c;
}
*quoted_strp = '\0';
fmt_len = strlen(quoted_str) + 4;
if ((fmt_len + cur_len) < (MAX_FMT_PREF_LEN - 1)) {
if (item_count % 2) {
if (cur_len > 0) cur_len--;
pref_str[cur_len] = '\n'; cur_len++;
pref_str[cur_len] = '\t'; cur_len++;
}
g_snprintf(&pref_str[cur_len], MAX_FMT_PREF_LEN - (gulong) cur_len, "\"%s\", ", quoted_str);
cur_len += fmt_len;
}
g_free(quoted_str);
g_free(str);
clp = clp->next;
}
if (cur_len >= 2)
pref_str[cur_len - 2] = '\0';
return(pref_str);
}
void
prefs_clear_string_list(GList *sl)
{
GList *l = sl;
while (l) {
g_free(l->data);
l = g_list_remove_link(l, l);
}
}
static gint
find_val_for_string(const char *needle, const enum_val_t *haystack,
gint default_value)
{
int i;
for (i = 0; haystack[i].name != NULL; i++) {
if (g_ascii_strcasecmp(needle, haystack[i].name) == 0) {
return haystack[i].value;
}
}
for (i = 0; haystack[i].name != NULL; i++) {
if (g_ascii_strcasecmp(needle, haystack[i].description) == 0) {
return haystack[i].value;
}
}
return default_value;
}
static int
find_index_from_string_array(char *needle, const char **haystack, int default_value)
{
int i = 0;
while (haystack[i] != NULL) {
if (strcmp(needle, haystack[i]) == 0) {
return i;
}
i++;
}
return default_value;
}
static gboolean
parse_column_format(fmt_data *cfmt, const char *fmt)
{
const gchar *cust_format = col_format_to_string(COL_CUSTOM);
size_t cust_format_len = strlen(cust_format);
gchar **cust_format_info;
char *p;
int col_fmt;
gchar *col_custom_field;
long col_custom_occurrence;
gboolean col_resolved;
if ((strlen(fmt) > cust_format_len) && (fmt[cust_format_len] == ':') &&
strncmp(fmt, cust_format, cust_format_len) == 0) {
col_fmt = COL_CUSTOM;
cust_format_info = g_strsplit(&fmt[cust_format_len+1],":",3);
col_custom_field = g_strdup(cust_format_info[0]);
if (col_custom_field && cust_format_info[1]) {
col_custom_occurrence = strtol(cust_format_info[1], &p, 10);
if (p == cust_format_info[1] || *p != '\0') {
g_free(col_custom_field);
g_strfreev(cust_format_info);
return FALSE;
}
} else {
col_custom_occurrence = 0;
}
if (col_custom_field && cust_format_info[1] && cust_format_info[2]) {
col_resolved = (cust_format_info[2][0] == 'U') ? FALSE : TRUE;
} else {
col_resolved = TRUE;
}
g_strfreev(cust_format_info);
} else {
col_fmt = get_column_format_from_str(fmt);
if (col_fmt == -1)
return FALSE;
col_custom_field = NULL;
col_custom_occurrence = 0;
col_resolved = TRUE;
}
cfmt->fmt = col_fmt;
cfmt->custom_field = col_custom_field;
cfmt->custom_occurrence = (int)col_custom_occurrence;
cfmt->resolved = col_resolved;
return TRUE;
}
static void
init_prefs(void)
{
int i;
fmt_data *cfmt;
static const gchar *col_fmt[DEF_NUM_COLS*2] = {
"No.", "%m", "Time", "%t",
"Source", "%s", "Destination", "%d",
"Protocol", "%p", "Length", "%L",
"Info", "%i"};
if (prefs_initialized)
return;
uat_load_all();
prefs.pr_format = PR_FMT_TEXT;
prefs.pr_dest = PR_DEST_CMD;
prefs.pr_file = g_strdup("wireshark.out");
prefs.pr_cmd = g_strdup("lpr");
prefs.col_list = NULL;
for (i = 0; i < DEF_NUM_COLS; i++) {
cfmt = (fmt_data *) g_malloc(sizeof(fmt_data));
cfmt->title = g_strdup(col_fmt[i * 2]);
parse_column_format(cfmt, col_fmt[(i * 2) + 1]);
cfmt->visible = TRUE;
cfmt->resolved = TRUE;
cfmt->custom_field = NULL;
cfmt->custom_occurrence = 0;
prefs.col_list = g_list_append(prefs.col_list, cfmt);
}
prefs.num_cols = DEF_NUM_COLS;
prefs.st_client_fg.pixel = 0;
prefs.st_client_fg.red = 32767;
prefs.st_client_fg.green = 0;
prefs.st_client_fg.blue = 0;
prefs.st_client_bg.pixel = 0;
prefs.st_client_bg.red = 64507;
prefs.st_client_bg.green = 60909;
prefs.st_client_bg.blue = 60909;
prefs.st_server_fg.pixel = 0;
prefs.st_server_fg.red = 0;
prefs.st_server_fg.green = 0;
prefs.st_server_fg.blue = 32767;
prefs.st_server_bg.pixel = 0;
prefs.st_server_bg.red = 60909;
prefs.st_server_bg.green = 60909;
prefs.st_server_bg.blue = 64507;
prefs.gui_scrollbar_on_right = TRUE;
prefs.gui_plist_sel_browse = FALSE;
prefs.gui_ptree_sel_browse = FALSE;
prefs.gui_altern_colors = FALSE;
prefs.gui_expert_composite_eyecandy = FALSE;
prefs.gui_ptree_line_style = 0;
prefs.gui_ptree_expander_style = 1;
prefs.gui_hex_dump_highlight_style = 1;
prefs.filter_toolbar_show_in_statusbar = FALSE;
prefs.gui_toolbar_main_style = TB_STYLE_ICONS;
prefs.gui_toolbar_filter_style = TB_STYLE_TEXT;
#ifdef _WIN32
prefs.gui_font_name = g_strdup("Lucida Console 10");
#else
prefs.gui_font_name = g_strdup("Monospace 10");
#endif
prefs.gui_marked_fg.pixel = 65535;
prefs.gui_marked_fg.red = 65535;
prefs.gui_marked_fg.green = 65535;
prefs.gui_marked_fg.blue = 65535;
prefs.gui_marked_bg.pixel = 0;
prefs.gui_marked_bg.red = 0;
prefs.gui_marked_bg.green = 0;
prefs.gui_marked_bg.blue = 0;
prefs.gui_ignored_fg.pixel = 32767;
prefs.gui_ignored_fg.red = 32767;
prefs.gui_ignored_fg.green = 32767;
prefs.gui_ignored_fg.blue = 32767;
prefs.gui_ignored_bg.pixel = 65535;
prefs.gui_ignored_bg.red = 65535;
prefs.gui_ignored_bg.green = 65535;
prefs.gui_ignored_bg.blue = 65535;
prefs.gui_colorized_fg = g_strdup("000000,000000,000000,000000,000000,000000,000000,000000,000000,000000");
prefs.gui_colorized_bg = g_strdup("ffc0c0,ffc0ff,e0c0e0,c0c0ff,c0e0e0,c0ffff,c0ffc0,ffffc0,e0e0c0,e0e0e0");
prefs.gui_geometry_save_position = FALSE;
prefs.gui_geometry_save_size = TRUE;
prefs.gui_geometry_save_maximized= TRUE;
prefs.gui_macosx_style = TRUE;
prefs.gui_console_open = console_open_never;
prefs.gui_fileopen_style = FO_STYLE_LAST_OPENED;
prefs.gui_recent_df_entries_max = 10;
prefs.gui_recent_files_count_max = 10;
prefs.gui_fileopen_dir = g_strdup(get_persdatafile_dir());
prefs.gui_fileopen_preview = 3;
prefs.gui_ask_unsaved = TRUE;
prefs.gui_find_wrap = TRUE;
prefs.gui_use_pref_save = FALSE;
prefs.gui_webbrowser = g_strdup(HTML_VIEWER " %s");
prefs.gui_window_title = g_strdup("");
prefs.gui_start_title = g_strdup("The World's Most Popular Network Protocol Analyzer");
prefs.gui_version_in_start_page = TRUE;
prefs.gui_auto_scroll_on_expand = FALSE;
prefs.gui_auto_scroll_percentage = 0;
prefs.gui_layout_type = layout_type_5;
prefs.gui_layout_content_1 = layout_pane_content_plist;
prefs.gui_layout_content_2 = layout_pane_content_pdetails;
prefs.gui_layout_content_3 = layout_pane_content_pbytes;
prefs.console_log_level =
G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_ERROR;
prefs.capture_device = NULL;
prefs.capture_devices_linktypes = NULL;
prefs.capture_devices_descr = NULL;
prefs.capture_devices_hide = NULL;
prefs.capture_devices_monitor_mode = NULL;
prefs.capture_prom_mode = TRUE;
#ifdef PCAP_NG_DEFAULT
prefs.capture_pcap_ng = TRUE;
#else
prefs.capture_pcap_ng = FALSE;
#endif
prefs.capture_real_time = TRUE;
prefs.capture_auto_scroll = TRUE;
prefs.capture_show_info = FALSE;
prefs.name_resolve = RESOLV_ALL ^ RESOLV_NETWORK;
prefs.name_resolve_concurrency = 500;
prefs.load_smi_modules = FALSE;
prefs.suppress_smi_errors = FALSE;
prefs.tap_update_interval = TAP_UPDATE_DEFAULT_INTERVAL;
prefs.rtp_player_max_visible = RTP_PLAYER_DEFAULT_VISIBLE;
prefs.display_hidden_proto_items = FALSE;
filter_expression_init(TRUE);
prefs_initialized = TRUE;
copy_prefs(&default_prefs, &prefs);
}
static void
reset_pref(gpointer data, gpointer user_data _U_)
{
pref_t *pref = data;
switch (pref->type) {
case PREF_UINT:
*pref->varp.uint = pref->default_val.uint;
break;
case PREF_BOOL:
*pref->varp.boolp = pref->default_val.boolval;
break;
case PREF_ENUM:
*pref->varp.enump = pref->default_val.enumval;
break;
case PREF_STRING:
case PREF_FILENAME:
g_free((void *)*pref->varp.string);
*pref->varp.string = g_strdup(pref->default_val.string);
break;
case PREF_RANGE:
g_free(*pref->varp.range);
*pref->varp.range = range_copy(pref->default_val.range);
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
break;
}
}
static gboolean
reset_module_prefs(void *value, void *data _U_)
{
reset_pref_arg_t arg;
arg.module = value;
g_list_foreach(arg.module->prefs, reset_pref, &arg);
return FALSE;
}
void
prefs_reset(void)
{
prefs_initialized = FALSE;
g_free(prefs.pr_file);
g_free(prefs.pr_cmd);
free_col_info(&prefs);
g_free(prefs.gui_font_name);
g_free(prefs.gui_colorized_fg);
g_free(prefs.gui_colorized_bg);
g_free(prefs.gui_fileopen_dir);
g_free(prefs.gui_webbrowser);
g_free(prefs.gui_window_title);
g_free(prefs.gui_start_title);
g_free(prefs.capture_device);
g_free(prefs.capture_devices_linktypes);
g_free(prefs.capture_devices_descr);
g_free(prefs.capture_devices_hide);
g_free(prefs.capture_devices_monitor_mode);
uat_unload_all();
oids_cleanup();
init_prefs();
pe_tree_foreach(prefs_modules, reset_module_prefs, NULL);
}
e_prefs *
read_prefs(int *gpf_errno_return, int *gpf_read_errno_return,
char **gpf_path_return, int *pf_errno_return,
int *pf_read_errno_return, char **pf_path_return)
{
int err;
char *pf_path;
FILE *pf;
if (prefs.load_smi_modules) {
oids_cleanup();
}
init_prefs();
if (gpf_path == NULL) {
gpf_path = get_datafile_path(PF_NAME);
if ((pf = ws_fopen(gpf_path, "r")) == NULL && errno == ENOENT) {
g_free(gpf_path);
gpf_path = get_datafile_path(OLD_GPF_NAME);
pf = ws_fopen(gpf_path, "r");
}
} else {
pf = ws_fopen(gpf_path, "r");
}
*gpf_path_return = NULL;
if (pf != NULL) {
mgcp_tcp_port_count = 0;
mgcp_udp_port_count = 0;
err = read_prefs_file(gpf_path, pf, set_pref, NULL);
if (err != 0) {
*gpf_errno_return = 0;
*gpf_read_errno_return = err;
*gpf_path_return = gpf_path;
}
fclose(pf);
} else {
if (errno != ENOENT) {
*gpf_errno_return = errno;
*gpf_read_errno_return = 0;
*gpf_path_return = gpf_path;
}
}
pf_path = get_persconffile_path(PF_NAME, TRUE, FALSE);
*pf_path_return = NULL;
if ((pf = ws_fopen(pf_path, "r")) != NULL) {
mgcp_tcp_port_count = 0;
mgcp_udp_port_count = 0;
err = read_prefs_file(pf_path, pf, set_pref, NULL);
if (err != 0) {
*pf_errno_return = 0;
*pf_read_errno_return = err;
*pf_path_return = pf_path;
} else
g_free(pf_path);
fclose(pf);
} else {
if (errno != ENOENT) {
*pf_errno_return = errno;
*pf_read_errno_return = 0;
*pf_path_return = pf_path;
} else
g_free(pf_path);
}
if (prefs.load_smi_modules) {
oids_init();
}
return &prefs;
}
int
read_prefs_file(const char *pf_path, FILE *pf,
pref_set_pair_cb pref_set_pair_fct, void *private_data)
{
enum { START, IN_VAR, PRE_VAL, IN_VAL, IN_SKIP };
int got_c, state = START;
GString *cur_val;
GString *cur_var;
gboolean got_val = FALSE;
gint fline = 1, pline = 1;
gchar hint[] = "(applying your preferences once should remove this warning)";
cur_val = g_string_new("");
cur_var = g_string_new("");
while ((got_c = getc(pf)) != EOF) {
if (got_c == '\n') {
state = START;
fline++;
continue;
}
switch (state) {
case START:
if (isalnum(got_c)) {
if (cur_var->len > 0) {
if (got_val) {
switch (pref_set_pair_fct(cur_var->str, cur_val->str, private_data, FALSE)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
g_warning ("%s line %d: Syntax error in preference %s %s", pf_path, pline, cur_var->str, hint);
break;
case PREFS_SET_NO_SUCH_PREF:
g_warning ("%s line %d: No such preference \"%s\" %s", pf_path,
pline, cur_var->str, hint);
break;
case PREFS_SET_OBSOLETE:
break;
}
} else {
g_warning ("%s line %d: Incomplete preference %s", pf_path, pline, hint);
}
}
state = IN_VAR;
got_val = FALSE;
g_string_truncate(cur_var, 0);
g_string_append_c(cur_var, (gchar) got_c);
pline = fline;
} else if (isspace(got_c) && cur_var->len > 0 && got_val) {
state = PRE_VAL;
} else if (got_c == '#') {
state = IN_SKIP;
} else {
g_warning ("%s line %d: Malformed line %s", pf_path, fline, hint);
}
break;
case IN_VAR:
if (got_c != ':') {
g_string_append_c(cur_var, (gchar) got_c);
} else {
state = PRE_VAL;
g_string_truncate(cur_val, 0);
got_val = TRUE;
}
break;
case PRE_VAL:
if (!isspace(got_c)) {
state = IN_VAL;
g_string_append_c(cur_val, (gchar) got_c);
}
break;
case IN_VAL:
g_string_append_c(cur_val, (gchar) got_c);
break;
}
}
if (cur_var->len > 0) {
if (got_val) {
switch (pref_set_pair_fct(cur_var->str, cur_val->str, private_data, FALSE)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
g_warning ("%s line %d: Syntax error in preference %s %s", pf_path, pline, cur_var->str, hint);
break;
case PREFS_SET_NO_SUCH_PREF:
g_warning ("%s line %d: No such preference \"%s\" %s", pf_path,
pline, cur_var->str, hint);
break;
case PREFS_SET_OBSOLETE:
break;
}
} else {
g_warning ("%s line %d: Incomplete preference %s", pf_path, pline, hint);
}
}
g_string_free(cur_val, TRUE);
g_string_free(cur_var, TRUE);
if (ferror(pf))
return errno;
else
return 0;
}
static gboolean
prefs_set_uat_pref(char *uat_entry) {
gchar *p, *colonp;
uat_t *uat;
gchar *err;
colonp = strchr(uat_entry, ':');
if (colonp == NULL)
return FALSE;
p = colonp;
*p++ = '\0';
while (isspace((guchar)*p))
p++;
if (*p == '\0') {
*colonp = ':';
return FALSE;
}
uat = uat_find(uat_entry);
*colonp = ':';
if (uat == NULL) {
return FALSE;
}
if (uat_load_str(uat, p, &err)) {
return TRUE;
}
return FALSE;
}
prefs_set_pref_e
prefs_set_pref(char *prefarg)
{
gchar *p, *colonp;
prefs_set_pref_e ret;
mgcp_tcp_port_count = -1;
mgcp_udp_port_count = -1;
colonp = strchr(prefarg, ':');
if (colonp == NULL)
return PREFS_SET_SYNTAX_ERR;
p = colonp;
*p++ = '\0';
while (isspace((guchar)*p))
p++;
if (*p == '\0') {
*colonp = ':';
return PREFS_SET_SYNTAX_ERR;
}
if (strcmp(prefarg, "uat")) {
ret = set_pref(prefarg, p, NULL, TRUE);
} else {
ret = prefs_set_uat_pref(p) ? PREFS_SET_OK : PREFS_SET_SYNTAX_ERR;
}
*colonp = ':';
return ret;
}
gboolean
prefs_is_capture_device_hidden(const char *name)
{
gchar *tok, *devices;
size_t len;
if (prefs.capture_devices_hide && name) {
devices = g_strdup (prefs.capture_devices_hide);
len = strlen (name);
for (tok = strtok (devices, ","); tok; tok = strtok(NULL, ",")) {
if (strlen (tok) == len && strcmp (name, tok) == 0) {
g_free (devices);
return TRUE;
}
}
g_free (devices);
}
return FALSE;
}
static gboolean
prefs_is_column_visible(const gchar *cols_hidden, fmt_data *cfmt)
{
gchar *tok, *cols;
fmt_data cfmt_hidden;
if (cols_hidden) {
cols = g_strdup(cols_hidden);
for (tok = strtok(cols, ","); tok; tok = strtok(NULL, ",")) {
tok = g_strstrip(tok);
if (!parse_column_format(&cfmt_hidden, tok)) {
continue;
}
if (cfmt->fmt != cfmt_hidden.fmt) {
g_free(cfmt_hidden.custom_field);
continue;
}
if (cfmt->fmt == COL_CUSTOM) {
if (strcmp(cfmt->custom_field,
cfmt_hidden.custom_field) != 0) {
g_free(cfmt_hidden.custom_field);
continue;
}
if (cfmt->custom_occurrence !=
cfmt_hidden.custom_occurrence) {
g_free(cfmt_hidden.custom_field);
continue;
}
}
g_free(cfmt_hidden.custom_field);
g_free(cols);
return FALSE;
}
g_free(cols);
}
return TRUE;
}
gboolean
prefs_capture_device_monitor_mode(const char *name)
{
gchar *tok, *devices;
size_t len;
if (prefs.capture_devices_monitor_mode && name) {
devices = g_strdup (prefs.capture_devices_monitor_mode);
len = strlen (name);
for (tok = strtok (devices, ","); tok; tok = strtok(NULL, ",")) {
if (strlen (tok) == len && strcmp (name, tok) == 0) {
g_free (devices);
return TRUE;
}
}
g_free (devices);
}
return FALSE;
}
static const char *
name_resolve_to_string(guint32 name_resolve)
{
static char string[N_NAME_RESOLVE_OPT+1];
char *p;
unsigned int i;
gboolean all_opts_set = TRUE;
if (name_resolve == RESOLV_NONE)
return "FALSE";
p = &string[0];
for (i = 0; i < N_NAME_RESOLVE_OPT; i++) {
if (name_resolve & name_resolve_opt[i].value)
*p++ = name_resolve_opt[i].letter;
else
all_opts_set = FALSE;
}
*p = '\0';
if (all_opts_set)
return "TRUE";
return string;
}
char
string_to_name_resolve(char *string, guint32 *name_resolve)
{
char c;
unsigned int i;
*name_resolve = 0;
while ((c = *string++) != '\0') {
for (i = 0; i < N_NAME_RESOLVE_OPT; i++) {
if (c == name_resolve_opt[i].letter) {
*name_resolve |= name_resolve_opt[i].value;
break;
}
}
if (i == N_NAME_RESOLVE_OPT) {
return c;
}
}
return '\0';
}
static void
try_convert_to_custom_column(gpointer *el_data)
{
struct {
gint el;
gchar *col_expr;
} migrated_columns[] = {
{ COL_COS_VALUE, "vlan.priority" },
{ COL_CIRCUIT_ID, "iax2.call" },
{ COL_BSSGP_TLLI, "bssgp.tlli" },
{ COL_HPUX_SUBSYS, "nettl.subsys" },
{ COL_HPUX_DEVID, "nettl.devid" },
{ COL_FR_DLCI, "fr.dlci" },
{ COL_REL_CONV_TIME, "tcp.time_relative" },
{ COL_DELTA_CONV_TIME, "tcp.time_delta" },
{ COL_OXID, "fc.ox_id" },
{ COL_RXID, "fc.rx_id" },
{ COL_SRCIDX, "mdshdr.srcidx" },
{ COL_DSTIDX, "mdshdr.dstidx" },
{ COL_DCE_CTX, "dcerpc.cn_ctx_id" }
};
guint haystack_idx;
const gchar *haystack_fmt;
gchar **fmt = (gchar **) el_data;
for (haystack_idx = 0;
haystack_idx < G_N_ELEMENTS(migrated_columns);
++haystack_idx) {
haystack_fmt = col_format_to_string(migrated_columns[haystack_idx].el);
if (strcmp(haystack_fmt, *fmt) == 0) {
gchar *cust_col = g_strdup_printf("%%Cus:%s:0",
migrated_columns[haystack_idx].col_expr);
g_free(*fmt);
*fmt = cust_col;
}
}
}
static prefs_set_pref_e
set_pref(gchar *pref_name, gchar *value, void *private_data _U_,
gboolean return_range_errors)
{
GList *clp, *col_l, *col_l_elt;
gint llen;
fmt_data *cfmt;
unsigned long int cval;
guint uval;
gboolean bval;
gint enum_val;
char *p;
gchar *dotp, *last_dotp;
static gchar *filter_label = NULL;
static gboolean filter_enabled = FALSE;
gchar *filter_expr = NULL;
module_t *module;
pref_t *pref;
gboolean had_a_dot;
if (strcmp(pref_name, PRS_PRINT_FMT) == 0) {
if (strcmp(value, pr_formats[PR_FMT_TEXT]) == 0) {
prefs.pr_format = PR_FMT_TEXT;
} else if (strcmp(value, pr_formats[PR_FMT_PS]) == 0) {
prefs.pr_format = PR_FMT_PS;
} else {
return PREFS_SET_SYNTAX_ERR;
}
} else if (strcmp(pref_name, PRS_PRINT_DEST) == 0) {
if (strcmp(value, pr_dests[PR_DEST_CMD]) == 0) {
prefs.pr_dest = PR_DEST_CMD;
} else if (strcmp(value, pr_dests[PR_DEST_FILE]) == 0) {
prefs.pr_dest = PR_DEST_FILE;
} else {
return PREFS_SET_SYNTAX_ERR;
}
} else if (strcmp(pref_name, PRS_PRINT_FILE) == 0) {
g_free(prefs.pr_file);
prefs.pr_file = g_strdup(value);
} else if (strcmp(pref_name, PRS_PRINT_CMD) == 0) {
g_free(prefs.pr_cmd);
prefs.pr_cmd = g_strdup(value);
} else if (strcmp(pref_name, PRS_COL_HIDDEN) == 0) {
g_free(cols_hidden_list);
cols_hidden_list = g_strdup(value);
for (clp = prefs.col_list; clp != NULL; clp = clp->next) {
cfmt = (fmt_data *)clp->data;
cfmt->visible = prefs_is_column_visible(cols_hidden_list, cfmt);
}
} else if (strcmp(pref_name, PRS_GUI_FILTER_LABEL) == 0) {
filter_label = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_FILTER_ENABLED) == 0) {
filter_enabled = (strcmp(value, "TRUE") == 0) ? TRUE : FALSE;
} else if (strcmp(pref_name, PRS_GUI_FILTER_EXPR) == 0) {
filter_expr = g_strdup(value);
filter_expression_new(filter_label, filter_expr, filter_enabled);
g_free(filter_label);
g_free(filter_expr);
} else if (strcmp(pref_name, PRS_COL_FMT) == 0) {
col_l = prefs_get_string_list(value);
if (col_l == NULL)
return PREFS_SET_SYNTAX_ERR;
if ((g_list_length(col_l) % 2) != 0) {
prefs_clear_string_list(col_l);
return PREFS_SET_SYNTAX_ERR;
}
col_l_elt = g_list_first(col_l);
while(col_l_elt) {
fmt_data cfmt_check;
col_l_elt = col_l_elt->next;
if (!parse_column_format(&cfmt_check, col_l_elt->data)) {
prefs_clear_string_list(col_l);
return PREFS_SET_SYNTAX_ERR;
}
if (cfmt_check.fmt != COL_CUSTOM) {
try_convert_to_custom_column(&col_l_elt->data);
} else {
g_free(cfmt_check.custom_field);
}
col_l_elt = col_l_elt->next;
}
free_col_info(&prefs);
prefs.col_list = NULL;
llen = g_list_length(col_l);
prefs.num_cols = llen / 2;
col_l_elt = g_list_first(col_l);
while(col_l_elt) {
cfmt = (fmt_data *) g_malloc(sizeof(fmt_data));
cfmt->title = g_strdup(col_l_elt->data);
col_l_elt = col_l_elt->next;
parse_column_format(cfmt, col_l_elt->data);
cfmt->visible = prefs_is_column_visible(cols_hidden_list, cfmt);
col_l_elt = col_l_elt->next;
prefs.col_list = g_list_append(prefs.col_list, cfmt);
}
prefs_clear_string_list(col_l);
g_free (cols_hidden_list);
cols_hidden_list = NULL;
} else if (strcmp(pref_name, PRS_STREAM_CL_FG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.st_client_fg.pixel = 0;
prefs.st_client_fg.red = RED_COMPONENT(cval);
prefs.st_client_fg.green = GREEN_COMPONENT(cval);
prefs.st_client_fg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_STREAM_CL_BG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.st_client_bg.pixel = 0;
prefs.st_client_bg.red = RED_COMPONENT(cval);
prefs.st_client_bg.green = GREEN_COMPONENT(cval);
prefs.st_client_bg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_STREAM_SR_FG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.st_server_fg.pixel = 0;
prefs.st_server_fg.red = RED_COMPONENT(cval);
prefs.st_server_fg.green = GREEN_COMPONENT(cval);
prefs.st_server_fg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_STREAM_SR_BG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.st_server_bg.pixel = 0;
prefs.st_server_bg.red = RED_COMPONENT(cval);
prefs.st_server_bg.green = GREEN_COMPONENT(cval);
prefs.st_server_bg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_GUI_SCROLLBAR_ON_RIGHT) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_scrollbar_on_right = TRUE;
}
else {
prefs.gui_scrollbar_on_right = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_PLIST_SEL_BROWSE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_plist_sel_browse = TRUE;
}
else {
prefs.gui_plist_sel_browse = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_PTREE_SEL_BROWSE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_ptree_sel_browse = TRUE;
}
else {
prefs.gui_ptree_sel_browse = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_ALTERN_COLORS) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_altern_colors = TRUE;
}
else {
prefs.gui_altern_colors = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_EXPERT_COMPOSITE_EYECANDY) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_expert_composite_eyecandy = TRUE;
}
else {
prefs.gui_expert_composite_eyecandy = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_PTREE_LINE_STYLE) == 0) {
prefs.gui_ptree_line_style =
find_index_from_string_array(value, gui_ptree_line_style_text, 0);
} else if (strcmp(pref_name, PRS_GUI_PTREE_EXPANDER_STYLE) == 0) {
prefs.gui_ptree_expander_style =
find_index_from_string_array(value, gui_ptree_expander_style_text, 1);
} else if (strcmp(pref_name, PRS_GUI_HEX_DUMP_HIGHLIGHT_STYLE) == 0) {
prefs.gui_hex_dump_highlight_style =
find_index_from_string_array(value, gui_hex_dump_highlight_style_text, 1);
} else if (strcmp(pref_name, PRS_GUI_FILTER_TOOLBAR_IN_STATUSBAR) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.filter_toolbar_show_in_statusbar = TRUE;
}
else {
prefs.filter_toolbar_show_in_statusbar = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_TOOLBAR_MAIN_SHOW) == 0) {
} else if (strcmp(pref_name, PRS_GUI_TOOLBAR_MAIN_STYLE) == 0) {
prefs.gui_toolbar_main_style =
find_index_from_string_array(value, gui_toolbar_style_text,
TB_STYLE_ICONS);
} else if (strcmp(pref_name, PRS_GUI_TOOLBAR_FILTER_STYLE) == 0) {
prefs.gui_toolbar_filter_style =
find_index_from_string_array(value, gui_toolbar_style_text,
TB_STYLE_TEXT);
} else if (strcmp(pref_name, PRS_GUI_FONT_NAME_1) == 0) {
} else if (strcmp(pref_name, PRS_GUI_FONT_NAME_2) == 0) {
g_free(prefs.gui_font_name);
prefs.gui_font_name = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_MARKED_FG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.gui_marked_fg.pixel = 0;
prefs.gui_marked_fg.red = RED_COMPONENT(cval);
prefs.gui_marked_fg.green = GREEN_COMPONENT(cval);
prefs.gui_marked_fg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_GUI_MARKED_BG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.gui_marked_bg.pixel = 0;
prefs.gui_marked_bg.red = RED_COMPONENT(cval);
prefs.gui_marked_bg.green = GREEN_COMPONENT(cval);
prefs.gui_marked_bg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_GUI_IGNORED_FG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.gui_ignored_fg.pixel = 0;
prefs.gui_ignored_fg.red = RED_COMPONENT(cval);
prefs.gui_ignored_fg.green = GREEN_COMPONENT(cval);
prefs.gui_ignored_fg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_GUI_IGNORED_BG) == 0) {
cval = strtoul(value, NULL, 16);
prefs.gui_ignored_bg.pixel = 0;
prefs.gui_ignored_bg.red = RED_COMPONENT(cval);
prefs.gui_ignored_bg.green = GREEN_COMPONENT(cval);
prefs.gui_ignored_bg.blue = BLUE_COMPONENT(cval);
} else if (strcmp(pref_name, PRS_GUI_COLORIZED_FG) == 0) {
g_free(prefs.gui_colorized_fg);
prefs.gui_colorized_fg = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_COLORIZED_BG) == 0) {
g_free(prefs.gui_colorized_bg);
prefs.gui_colorized_bg = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_SAVE_POSITION) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_geometry_save_position = TRUE;
}
else {
prefs.gui_geometry_save_position = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_SAVE_SIZE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_geometry_save_size = TRUE;
}
else {
prefs.gui_geometry_save_size = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_SAVE_MAXIMIZED) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_geometry_save_maximized = TRUE;
}
else {
prefs.gui_geometry_save_maximized = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_MACOSX_STYLE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_macosx_style = TRUE;
}
else {
prefs.gui_macosx_style = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_MAIN_X) == 0) {
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_MAIN_Y) == 0) {
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_MAIN_WIDTH) == 0) {
} else if (strcmp(pref_name, PRS_GUI_GEOMETRY_MAIN_HEIGHT) == 0) {
} else if (strcmp(pref_name, PRS_GUI_CONSOLE_OPEN) == 0) {
prefs.gui_console_open =
find_index_from_string_array(value, gui_console_open_text,
console_open_never);
} else if (strcmp(pref_name, PRS_GUI_RECENT_COUNT_MAX) == 0) {
prefs.gui_recent_files_count_max = strtoul(value, NULL, 10);
if (prefs.gui_recent_files_count_max == 0) {
prefs.gui_recent_files_count_max = 10;
}
} else if (strcmp(pref_name, PRS_GUI_RECENT_DF_ENTRIES_MAX) == 0) {
prefs.gui_recent_df_entries_max = strtoul(value, NULL, 10);
if (prefs.gui_recent_df_entries_max == 0) {
prefs.gui_recent_df_entries_max = 10;
}
} else if (strcmp(pref_name, PRS_GUI_FILEOPEN_STYLE) == 0) {
prefs.gui_fileopen_style =
find_index_from_string_array(value, gui_fileopen_style_text,
FO_STYLE_LAST_OPENED);
} else if (strcmp(pref_name, PRS_GUI_FILEOPEN_DIR) == 0) {
g_free(prefs.gui_fileopen_dir);
prefs.gui_fileopen_dir = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_FILEOPEN_REMEMBERED_DIR) == 0) {
} else if (strcmp(pref_name, PRS_GUI_FILEOPEN_PREVIEW) == 0) {
prefs.gui_fileopen_preview = strtoul(value, NULL, 10);
} else if (strcmp(pref_name, PRS_GUI_ASK_UNSAVED) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_ask_unsaved = TRUE;
}
else {
prefs.gui_ask_unsaved = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_FIND_WRAP) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_find_wrap = TRUE;
}
else {
prefs.gui_find_wrap = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_USE_PREF_SAVE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_use_pref_save = TRUE;
}
else {
prefs.gui_use_pref_save = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_WEBBROWSER) == 0) {
g_free(prefs.gui_webbrowser);
prefs.gui_webbrowser = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_WINDOW_TITLE) == 0) {
g_free(prefs.gui_window_title);
prefs.gui_window_title = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_START_TITLE) == 0) {
g_free(prefs.gui_start_title);
prefs.gui_start_title = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_VERSION_IN_START_PAGE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_version_in_start_page = TRUE;
} else {
prefs.gui_version_in_start_page = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_AUTO_SCROLL) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_auto_scroll_on_expand = TRUE;
} else {
prefs.gui_auto_scroll_on_expand = FALSE;
}
} else if (strcmp(pref_name, PRS_GUI_AUTO_SCROLL_PERCENTAGE) == 0) {
prefs.gui_auto_scroll_percentage = strtoul(value, NULL, 10);
} else if (strcmp(pref_name, PRS_GUI_LAYOUT_TYPE) == 0) {
prefs.gui_layout_type = strtoul(value, NULL, 10);
if (prefs.gui_layout_type == layout_unused ||
prefs.gui_layout_type >= layout_type_max) {
prefs.gui_layout_type = layout_type_5;
}
} else if (strcmp(pref_name, PRS_GUI_LAYOUT_CONTENT_1) == 0) {
prefs.gui_layout_content_1 =
find_index_from_string_array(value, gui_layout_content_text, 0);
} else if (strcmp(pref_name, PRS_GUI_LAYOUT_CONTENT_2) == 0) {
prefs.gui_layout_content_2 =
find_index_from_string_array(value, gui_layout_content_text, 0);
} else if (strcmp(pref_name, PRS_GUI_LAYOUT_CONTENT_3) == 0) {
prefs.gui_layout_content_3 =
find_index_from_string_array(value, gui_layout_content_text, 0);
} else if (strcmp(pref_name, PRS_CONSOLE_LOG_LEVEL) == 0) {
prefs.console_log_level = strtoul(value, NULL, 10);
if (prefs.console_log_level & (G_LOG_LEVEL_INFO|G_LOG_LEVEL_DEBUG)) {
g_setenv("G_MESSAGES_DEBUG", "all", TRUE);
}
} else if (strcmp(pref_name, PRS_CAP_DEVICE) == 0) {
g_free(prefs.capture_device);
prefs.capture_device = g_strdup(value);
} else if (strcmp(pref_name, PRS_CAP_DEVICES_LINKTYPES) == 0) {
g_free(prefs.capture_devices_linktypes);
prefs.capture_devices_linktypes = g_strdup(value);
} else if (strcmp(pref_name, PRS_CAP_DEVICES_DESCR) == 0) {
g_free(prefs.capture_devices_descr);
prefs.capture_devices_descr = g_strdup(value);
} else if (strcmp(pref_name, PRS_CAP_DEVICES_HIDE) == 0) {
g_free(prefs.capture_devices_hide);
prefs.capture_devices_hide = g_strdup(value);
} else if (strcmp(pref_name, PRS_CAP_DEVICES_MONITOR_MODE) == 0) {
g_free(prefs.capture_devices_monitor_mode);
prefs.capture_devices_monitor_mode = g_strdup(value);
} else if (strcmp(pref_name, PRS_CAP_PROM_MODE) == 0) {
prefs.capture_prom_mode = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_CAP_PCAP_NG) == 0) {
prefs.capture_pcap_ng = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_CAP_REAL_TIME) == 0) {
prefs.capture_real_time = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_CAP_AUTO_SCROLL) == 0) {
prefs.capture_auto_scroll = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_CAP_SHOW_INFO) == 0) {
prefs.capture_show_info = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_CAP_SYNTAX_CHECK_FILTER) == 0) {
;
} else if (strcmp(pref_name, PRS_NAME_RESOLVE) == 0 ||
strcmp(pref_name, PRS_CAP_NAME_RESOLVE) == 0) {
if (g_ascii_strcasecmp(value, "true") == 0)
prefs.name_resolve = RESOLV_ALL;
else if (g_ascii_strcasecmp(value, "false") == 0)
prefs.name_resolve = RESOLV_NONE;
else {
prefs.name_resolve = RESOLV_NONE;
if (string_to_name_resolve(value, &prefs.name_resolve) != '\0')
return PREFS_SET_SYNTAX_ERR;
}
} else if (strcmp(pref_name, PRS_NAME_RESOLVE_CONCURRENCY) == 0) {
prefs.name_resolve_concurrency = strtol(value, NULL, 10);
} else if (strcmp(pref_name, PRS_NAME_RESOLVE_LOAD_SMI_MODULES) == 0) {
prefs.load_smi_modules = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if (strcmp(pref_name, PRS_NAME_RESOLVE_SUPPRESS_SMI_ERRORS) == 0) {
prefs.suppress_smi_errors = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else if ((strcmp(pref_name, PRS_RTP_PLAYER_MAX_VISIBLE) == 0) ||
(strcmp(pref_name, "rtp_player.max_visible") == 0)) {
prefs.rtp_player_max_visible = strtol(value, NULL, 10);
} else if (strcmp(pref_name, PRS_TAP_UPDATE_INTERVAL) == 0) {
prefs.tap_update_interval = strtol(value, NULL, 10);
} else if (strcmp(pref_name, PRS_DISPLAY_HIDDEN_PROTO_ITEMS) == 0) {
prefs.display_hidden_proto_items = ((g_ascii_strcasecmp(value, "true") == 0)?TRUE:FALSE);
} else {
module = NULL;
last_dotp = pref_name;
had_a_dot = FALSE;
while (!module) {
dotp = strchr(last_dotp, '.');
if (dotp == NULL) {
if (had_a_dot) {
return PREFS_SET_NO_SUCH_PREF;
}
else {
return PREFS_SET_SYNTAX_ERR;
}
}
else {
had_a_dot = TRUE;
}
*dotp = '\0';
module = prefs_find_module(pref_name);
if (module == NULL) {
if (strcmp(pref_name, "Diameter") == 0)
module = prefs_find_module("diameter");
else if (strcmp(pref_name, "bxxp") == 0)
module = prefs_find_module("beep");
else if (strcmp(pref_name, "gtpv0") == 0 ||
strcmp(pref_name, "gtpv1") == 0)
module = prefs_find_module("gtp");
else if (strcmp(pref_name, "smpp-gsm-sms") == 0)
module = prefs_find_module("gsm-sms-ud");
else if (strcmp(pref_name, "dcp") == 0)
module = prefs_find_module("dccp");
else if (strcmp(pref_name, "x.25") == 0)
module = prefs_find_module("x25");
else if (strcmp(pref_name, "x411") == 0)
module = prefs_find_module("p1");
else if (strcmp(pref_name, "nsip") == 0)
module = prefs_find_module("gprs-ns");
else if (strcmp(pref_name, "sonmp") == 0)
module = prefs_find_module("ndp");
else if (strcmp(pref_name, "etheric") == 0 ||
strcmp(pref_name, "isup_thin") == 0)
return PREFS_SET_OBSOLETE;
}
*dotp = '.';
dotp++;
last_dotp = dotp;
}
pref = prefs_find_preference(module, dotp);
if (pref == NULL) {
if (strcmp(module->name, "mgcp") == 0) {
if (strcmp(dotp, "display raw text toggle") == 0)
pref = prefs_find_preference(module, "display_raw_text");
else if (strcmp(dotp, "display dissect tree") == 0)
pref = prefs_find_preference(module, "display_dissect_tree");
else if (strcmp(dotp, "tcp.port") == 0) {
mgcp_tcp_port_count++;
if (mgcp_tcp_port_count == 1) {
pref = prefs_find_preference(module, "tcp.gateway_port");
} else if (mgcp_tcp_port_count == 2) {
pref = prefs_find_preference(module, "tcp.callagent_port");
}
} else if (strcmp(dotp, "udp.port") == 0) {
mgcp_udp_port_count++;
if (mgcp_udp_port_count == 1) {
pref = prefs_find_preference(module, "udp.gateway_port");
} else if (mgcp_udp_port_count == 2) {
pref = prefs_find_preference(module, "udp.callagent_port");
}
}
} else if (strcmp(module->name, "smb") == 0) {
if (strcmp(dotp, "smb.trans.reassembly") == 0)
pref = prefs_find_preference(module, "trans_reassembly");
else if (strcmp(dotp, "smb.dcerpc.reassembly") == 0)
pref = prefs_find_preference(module, "dcerpc_reassembly");
} else if (strcmp(module->name, "ndmp") == 0) {
if (strcmp(dotp, "ndmp.desegment") == 0)
pref = prefs_find_preference(module, "desegment");
} else if (strcmp(module->name, "diameter") == 0) {
if (strcmp(dotp, "diameter.desegment") == 0)
pref = prefs_find_preference(module, "desegment");
} else if (strcmp(module->name, "pcli") == 0) {
if (strcmp(dotp, "pcli.udp_port") == 0)
pref = prefs_find_preference(module, "udp_port");
} else if (strcmp(module->name, "artnet") == 0) {
if (strcmp(dotp, "artnet.udp_port") == 0)
pref = prefs_find_preference(module, "udp_port");
} else if (strcmp(module->name, "mapi") == 0) {
if (strcmp(dotp, "mapi_decrypt") == 0)
pref = prefs_find_preference(module, "decrypt");
} else if (strcmp(module->name, "fc") == 0) {
if (strcmp(dotp, "reassemble_fc") == 0)
pref = prefs_find_preference(module, "reassemble");
else if (strcmp(dotp, "fc_max_frame_size") == 0)
pref = prefs_find_preference(module, "max_frame_size");
} else if (strcmp(module->name, "fcip") == 0) {
if (strcmp(dotp, "desegment_fcip_messages") == 0)
pref = prefs_find_preference(module, "desegment");
else if (strcmp(dotp, "fcip_port") == 0)
pref = prefs_find_preference(module, "target_port");
} else if (strcmp(module->name, "gtp") == 0) {
if (strcmp(dotp, "gtpv0_port") == 0)
pref = prefs_find_preference(module, "v0_port");
else if (strcmp(dotp, "gtpv1c_port") == 0)
pref = prefs_find_preference(module, "v1c_port");
else if (strcmp(dotp, "gtpv1u_port") == 0)
pref = prefs_find_preference(module, "v1u_port");
else if (strcmp(dotp, "gtp_dissect_tpdu") == 0)
pref = prefs_find_preference(module, "dissect_tpdu");
else if (strcmp(dotp, "gtpv0_dissect_cdr_as") == 0)
pref = prefs_find_preference(module, "v0_dissect_cdr_as");
else if (strcmp(dotp, "gtpv0_check_etsi") == 0)
pref = prefs_find_preference(module, "v0_check_etsi");
else if (strcmp(dotp, "gtpv1_check_etsi") == 0)
pref = prefs_find_preference(module, "v1_check_etsi");
} else if (strcmp(module->name, "ip") == 0) {
if (strcmp(dotp, "ip_summary_in_tree") == 0)
pref = prefs_find_preference(module, "summary_in_tree");
} else if (strcmp(module->name, "iscsi") == 0) {
if (strcmp(dotp, "iscsi_port") == 0)
pref = prefs_find_preference(module, "target_port");
} else if (strcmp(module->name, "lmp") == 0) {
if (strcmp(dotp, "lmp_version") == 0)
pref = prefs_find_preference(module, "version");
} else if (strcmp(module->name, "mtp3") == 0) {
if (strcmp(dotp, "mtp3_standard") == 0)
pref = prefs_find_preference(module, "standard");
else if (strcmp(dotp, "net_addr_format") == 0)
pref = prefs_find_preference(module, "addr_format");
} else if (strcmp(module->name, "nlm") == 0) {
if (strcmp(dotp, "nlm_msg_res_matching") == 0)
pref = prefs_find_preference(module, "msg_res_matching");
} else if (strcmp(module->name, "ppp") == 0) {
if (strcmp(dotp, "ppp_fcs") == 0)
pref = prefs_find_preference(module, "fcs_type");
else if (strcmp(dotp, "ppp_vj") == 0)
pref = prefs_find_preference(module, "decompress_vj");
} else if (strcmp(module->name, "rsvp") == 0) {
if (strcmp(dotp, "rsvp_process_bundle") == 0)
pref = prefs_find_preference(module, "process_bundle");
} else if (strcmp(module->name, "tcp") == 0) {
if (strcmp(dotp, "tcp_summary_in_tree") == 0)
pref = prefs_find_preference(module, "summary_in_tree");
else if (strcmp(dotp, "tcp_analyze_sequence_numbers") == 0)
pref = prefs_find_preference(module, "analyze_sequence_numbers");
else if (strcmp(dotp, "tcp_relative_sequence_numbers") == 0)
pref = prefs_find_preference(module, "relative_sequence_numbers");
} else if (strcmp(module->name, "udp") == 0) {
if (strcmp(dotp, "udp_summary_in_tree") == 0)
pref = prefs_find_preference(module, "summary_in_tree");
} else if (strcmp(module->name, "ndps") == 0) {
if (strcmp(dotp, "desegment_ndps") == 0)
pref = prefs_find_preference(module, "desegment_tcp");
} else if (strcmp(module->name, "http") == 0) {
if (strcmp(dotp, "desegment_http_headers") == 0)
pref = prefs_find_preference(module, "desegment_headers");
else if (strcmp(dotp, "desegment_http_body") == 0)
pref = prefs_find_preference(module, "desegment_body");
} else if (strcmp(module->name, "smpp") == 0) {
module_t *new_module = prefs_find_module("gsm-sms-ud");
if(new_module){
if (strcmp(dotp, "port_number_udh_means_wsp") == 0)
pref = prefs_find_preference(new_module, "port_number_udh_means_wsp");
else if (strcmp(dotp, "try_dissect_1st_fragment") == 0)
pref = prefs_find_preference(new_module, "try_dissect_1st_fragment");
}
} else if (strcmp(module->name, "asn1") == 0) {
if (strcmp(dotp, "tcp_port") == 0)
pref = prefs_find_preference(module, "tcp_ports");
else if (strcmp(dotp, "udp_port") == 0)
pref = prefs_find_preference(module, "udp_ports");
else if (strcmp(dotp, "sctp_port") == 0)
pref = prefs_find_preference(module, "sctp_ports");
} else if (strcmp(module->name, "llcgprs") == 0) {
if (strcmp(dotp, "ignore_cipher_bit") == 0)
pref = prefs_find_preference(module, "autodetect_cipher_bit");
} else if (strcmp(module->name, "erf") == 0) {
if (strcmp(dotp, "erfeth") == 0) {
pref = prefs_find_preference(module, "ethfcs");
if (strcmp(value, "ethfcs") == 0 || strcmp(value, "Ethernet with FCS") == 0)
value = "TRUE";
else if (strcmp(value, "eth") == 0 || strcmp(value, "Ethernet") == 0)
value = "FALSE";
else if (strcmp(value, "raw") == 0 || strcmp(value, "Raw data") == 0)
value = "TRUE";
} else if (strcmp(dotp, "erfatm") == 0) {
pref = prefs_find_preference(module, "aal5_type");
if (strcmp(value, "atm") == 0 || strcmp(value, "ATM") == 0)
value = "guess";
else if (strcmp(value, "llc") == 0 || strcmp(value, "LLC") == 0)
value = "llc";
else if (strcmp(value, "raw") == 0 || strcmp(value, "Raw data") == 0)
value = "guess";
} else if (strcmp(dotp, "erfhdlc") == 0) {
pref = prefs_find_preference(module, "hdlc_type");
if (strcmp(value, "chdlc") == 0 || strcmp(value, "Cisco HDLC") == 0)
value = "chdlc";
else if (strcmp(value, "ppp") == 0 || strcmp(value, "PPP serial") == 0)
value = "ppp";
else if (strcmp(value, "fr") == 0 || strcmp(value, "Frame Relay") == 0)
value = "frelay";
else if (strcmp(value, "mtp2") == 0 || strcmp(value, "SS7 MTP2") == 0)
value = "mtp2";
else if (strcmp(value, "raw") == 0 || strcmp(value, "Raw data") == 0)
value = "guess";
}
} else if (strcmp(module->name, "eth") == 0) {
if (strcmp(dotp, "qinq_ethertype") == 0) {
module_t *new_module = prefs_find_module("vlan");
if(new_module) {
pref = prefs_find_preference(new_module, "qinq_ethertype");
module = new_module;
}
}
}
}
if (pref == NULL)
return PREFS_SET_NO_SUCH_PREF;
switch (pref->type) {
case PREF_UINT:
uval = strtoul(value, &p, pref->info.base);
if (p == value || *p != '\0')
return PREFS_SET_SYNTAX_ERR;
if (*pref->varp.uint != uval) {
module->prefs_changed = TRUE;
*pref->varp.uint = uval;
}
break;
case PREF_BOOL:
if (g_ascii_strcasecmp(value, "true") == 0)
bval = TRUE;
else
bval = FALSE;
if (*pref->varp.boolp != bval) {
module->prefs_changed = TRUE;
*pref->varp.boolp = bval;
}
break;
case PREF_ENUM:
enum_val = find_val_for_string(value, pref->info.enum_info.enumvals,
*pref->varp.enump);
if (*pref->varp.enump != enum_val) {
module->prefs_changed = TRUE;
*pref->varp.enump = enum_val;
}
break;
case PREF_STRING:
case PREF_FILENAME:
if (strcmp(*pref->varp.string, value) != 0) {
module->prefs_changed = TRUE;
g_free((void *)*pref->varp.string);
*pref->varp.string = g_strdup(value);
}
break;
case PREF_RANGE:
{
range_t *newrange;
if (range_convert_str_work(&newrange, value, pref->info.max_value,
return_range_errors) != CVT_NO_ERROR) {
return PREFS_SET_SYNTAX_ERR;
}
if (!ranges_are_equal(*pref->varp.range, newrange)) {
module->prefs_changed = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = newrange;
} else {
g_free (newrange);
}
break;
}
case PREF_STATIC_TEXT:
case PREF_UAT:
{
break;
}
case PREF_OBSOLETE:
return PREFS_SET_OBSOLETE;
}
}
return PREFS_SET_OK;
}
static void
write_pref(gpointer data, gpointer user_data)
{
pref_t *pref = data;
write_pref_arg_t *arg = user_data;
const enum_val_t *enum_valp;
const char *val_string;
gchar **desc_lines;
int i;
if (pref->type == PREF_OBSOLETE) {
return;
}
if (pref->description &&
(g_ascii_strncasecmp(pref->description,"", 2) != 0)) {
desc_lines = g_strsplit(pref->description,"\n",0);
for (i = 0; desc_lines[i] != NULL; ++i) {
fprintf(arg->pf, "\n# %s", desc_lines[i]);
}
fprintf(arg->pf, "\n");
g_strfreev(desc_lines);
} else {
fprintf(arg->pf, "\n# No description\n");
}
switch (pref->type) {
case PREF_UINT:
switch (pref->info.base) {
case 10:
fprintf(arg->pf, "# A decimal number.\n");
if (pref->default_val.uint == *pref->varp.uint)
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %u\n", arg->module->name,
pref->name, *pref->varp.uint);
break;
case 8:
fprintf(arg->pf, "# An octal number.\n");
if (pref->default_val.uint == *pref->varp.uint)
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %#o\n", arg->module->name,
pref->name, *pref->varp.uint);
break;
case 16:
fprintf(arg->pf, "# A hexadecimal number.\n");
if (pref->default_val.uint == *pref->varp.uint)
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %#x\n", arg->module->name,
pref->name, *pref->varp.uint);
break;
}
break;
case PREF_BOOL:
fprintf(arg->pf, "# TRUE or FALSE (case-insensitive).\n");
if (pref->default_val.boolval == *pref->varp.boolp)
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %s\n", arg->module->name, pref->name,
*pref->varp.boolp ? "TRUE" : "FALSE");
break;
case PREF_ENUM:
fprintf(arg->pf, "# One of: ");
enum_valp = pref->info.enum_info.enumvals;
val_string = NULL;
while (enum_valp->name != NULL) {
if (enum_valp->value == *pref->varp.enump)
val_string = enum_valp->description;
fprintf(arg->pf, "%s", enum_valp->description);
enum_valp++;
if (enum_valp->name == NULL)
fprintf(arg->pf, "\n");
else
fprintf(arg->pf, ", ");
}
fprintf(arg->pf, "# (case-insensitive).\n");
if (pref->default_val.enumval == *pref->varp.enump)
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %s\n", arg->module->name,
pref->name, val_string);
break;
case PREF_STRING:
case PREF_FILENAME:
fprintf(arg->pf, "# A string.\n");
if (!(strcmp(pref->default_val.string, *pref->varp.string)))
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %s\n", arg->module->name, pref->name,
*pref->varp.string);
break;
case PREF_RANGE:
{
char *range_string_p;
range_string_p = range_convert_range(*pref->varp.range);
fprintf(arg->pf, "# A string denoting an positive integer range (e.g., \"1-20,30-40\").\n");
if ((ranges_are_equal(pref->default_val.range, *pref->varp.range)))
fprintf(arg->pf, "#");
fprintf(arg->pf, "%s.%s: %s\n", arg->module->name, pref->name,
range_string_p);
break;
}
case PREF_STATIC_TEXT:
case PREF_UAT:
{
break;
}
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
}
static gboolean
write_module_prefs(void *value, void *data)
{
write_pref_arg_t arg;
arg.module = value;
arg.pf = data;
g_list_foreach(arg.module->prefs, write_pref, &arg);
return FALSE;
}
int
write_prefs(char **pf_path_return)
{
char *pf_path;
FILE *pf;
GList *clp, *col_l;
fmt_data *cfmt;
GString *cols_hidden = g_string_new ("");
init_prefs();
if (pf_path_return != NULL) {
pf_path = get_persconffile_path(PF_NAME, TRUE, TRUE);
if ((pf = ws_fopen(pf_path, "w")) == NULL) {
*pf_path_return = pf_path;
return errno;
}
} else {
pf = stdout;
}
fputs("# Configuration file for Wireshark " VERSION ".\n"
"#\n"
"# This file is regenerated each time preferences are saved within\n"
"# Wireshark. Making manual changes should be safe, however.\n"
"# Preferences that have been commented out have not been\n"
"# changed from their default value.\n", pf);
fprintf (pf, "\n######## User Interface ########\n");
fprintf(pf, "\n# Vertical scrollbars should be on right side?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_scrollbar_on_right == default_prefs.gui_scrollbar_on_right)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_SCROLLBAR_ON_RIGHT ": %s\n",
prefs.gui_scrollbar_on_right == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Packet-list selection bar can be used to browse w/o selecting?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_plist_sel_browse == default_prefs.gui_plist_sel_browse)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_PLIST_SEL_BROWSE ": %s\n",
prefs.gui_plist_sel_browse == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Protocol-tree selection bar can be used to browse w/o selecting?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_ptree_sel_browse == default_prefs.gui_ptree_sel_browse)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_PTREE_SEL_BROWSE ": %s\n",
prefs.gui_ptree_sel_browse == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Alternating colors in TreeViews?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_altern_colors == default_prefs.gui_altern_colors)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_ALTERN_COLORS ": %s\n",
prefs.gui_altern_colors == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Display LEDs on Expert Composite Dialog Tabs?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_expert_composite_eyecandy == default_prefs.gui_expert_composite_eyecandy)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_EXPERT_COMPOSITE_EYECANDY ": %s\n",
prefs.gui_expert_composite_eyecandy == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Place filter toolbar inside the statusbar?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.filter_toolbar_show_in_statusbar == default_prefs.filter_toolbar_show_in_statusbar)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FILTER_TOOLBAR_IN_STATUSBAR ": %s\n",
prefs.filter_toolbar_show_in_statusbar == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Protocol-tree line style.\n");
fprintf(pf, "# One of: NONE, SOLID, DOTTED, TABBED\n");
if (prefs.gui_ptree_line_style == default_prefs.gui_ptree_line_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_PTREE_LINE_STYLE ": %s\n",
gui_ptree_line_style_text[prefs.gui_ptree_line_style]);
fprintf(pf, "\n# Protocol-tree expander style.\n");
fprintf(pf, "# One of: NONE, SQUARE, TRIANGLE, CIRCULAR\n");
if (prefs.gui_ptree_expander_style == default_prefs.gui_ptree_expander_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_PTREE_EXPANDER_STYLE ": %s\n",
gui_ptree_expander_style_text[prefs.gui_ptree_expander_style]);
fprintf(pf, "\n# Hex dump highlight style.\n");
fprintf(pf, "# One of: BOLD, INVERSE\n");
if (prefs.gui_hex_dump_highlight_style == default_prefs.gui_hex_dump_highlight_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_HEX_DUMP_HIGHLIGHT_STYLE ": %s\n",
gui_hex_dump_highlight_style_text[prefs.gui_hex_dump_highlight_style]);
fprintf(pf, "\n# Main Toolbar style.\n");
fprintf(pf, "# One of: ICONS, TEXT, BOTH\n");
if (prefs.gui_toolbar_main_style == default_prefs.gui_toolbar_main_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_TOOLBAR_MAIN_STYLE ": %s\n",
gui_toolbar_style_text[prefs.gui_toolbar_main_style]);
fprintf(pf, "\n# Filter Toolbar style.\n");
fprintf(pf, "# One of: ICONS, TEXT, BOTH\n");
if (prefs.gui_toolbar_filter_style == default_prefs.gui_toolbar_filter_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_TOOLBAR_FILTER_STYLE ": %s\n",
gui_toolbar_style_text[prefs.gui_toolbar_filter_style]);
fprintf(pf, "\n# Save window position at exit?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_geometry_save_position == default_prefs.gui_geometry_save_position)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_GEOMETRY_SAVE_POSITION ": %s\n",
prefs.gui_geometry_save_position == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Save window size at exit?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_geometry_save_size == default_prefs.gui_geometry_save_size)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_GEOMETRY_SAVE_SIZE ": %s\n",
prefs.gui_geometry_save_size == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Save window maximized state at exit?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_geometry_save_maximized == default_prefs.gui_geometry_save_maximized)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_GEOMETRY_SAVE_MAXIMIZED ": %s\n",
prefs.gui_geometry_save_maximized == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Use Mac OS X style (Mac OS X with native GTK only)?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_macosx_style == default_prefs.gui_macosx_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_MACOSX_STYLE ": %s\n",
prefs.gui_macosx_style == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Open a console window (WIN32 only)?\n");
fprintf(pf, "# One of: NEVER, AUTOMATIC, ALWAYS\n");
if (prefs.gui_console_open == default_prefs.gui_console_open)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_CONSOLE_OPEN ": %s\n",
gui_console_open_text[prefs.gui_console_open]);
fprintf(pf, "\n# The max. number of entries in the display filter list.\n");
fprintf(pf, "# A decimal number.\n");
if (prefs.gui_recent_df_entries_max == default_prefs.gui_recent_df_entries_max)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_RECENT_DF_ENTRIES_MAX ": %d\n",
prefs.gui_recent_df_entries_max);
fprintf(pf, "\n# The max. number of items in the open recent files list.\n");
fprintf(pf, "# A decimal number.\n");
if (prefs.gui_recent_files_count_max == default_prefs.gui_recent_files_count_max)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_RECENT_COUNT_MAX ": %d\n",
prefs.gui_recent_files_count_max);
fprintf(pf, "\n# Where to start the File Open dialog box.\n");
fprintf(pf, "# One of: LAST_OPENED, SPECIFIED\n");
if (prefs.gui_fileopen_style == default_prefs.gui_fileopen_style)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FILEOPEN_STYLE ": %s\n",
gui_fileopen_style_text[prefs.gui_fileopen_style]);
if (prefs.gui_fileopen_dir != NULL) {
fprintf(pf, "\n# Directory to start in when opening File Open dialog.\n");
if (strcmp(prefs.gui_fileopen_dir, default_prefs.gui_fileopen_dir) == 0)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FILEOPEN_DIR ": %s\n",
prefs.gui_fileopen_dir);
}
fprintf(pf, "\n# The preview timeout in the File Open dialog.\n");
fprintf(pf, "# A decimal number (in seconds).\n");
if (prefs.gui_fileopen_preview == default_prefs.gui_fileopen_preview)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FILEOPEN_PREVIEW ": %d\n",
prefs.gui_fileopen_preview);
fprintf(pf, "\n# Ask to save unsaved capture files?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_ask_unsaved == default_prefs.gui_ask_unsaved)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_ASK_UNSAVED ": %s\n",
prefs.gui_ask_unsaved == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Wrap to beginning/end of file during search?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_find_wrap == default_prefs.gui_find_wrap)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FIND_WRAP ": %s\n",
prefs.gui_find_wrap == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Settings dialogs use a save button?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_use_pref_save == default_prefs.gui_use_pref_save)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_USE_PREF_SAVE ": %s\n",
prefs.gui_use_pref_save == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# The path to the webbrowser.\n");
fprintf(pf, "# Ex: mozilla %%s\n");
if (strcmp(prefs.gui_webbrowser, default_prefs.gui_webbrowser) == 0)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_WEBBROWSER ": %s\n", prefs.gui_webbrowser);
fprintf(pf, "\n# Custom window title. (Appended to existing titles.)\n");
if (strcmp(prefs.gui_window_title, default_prefs.gui_window_title) == 0)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_WINDOW_TITLE ": %s\n",
prefs.gui_window_title);
fprintf(pf, "\n# Custom start page title.\n");
if (strcmp(prefs.gui_start_title, default_prefs.gui_start_title) == 0)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_START_TITLE ": %s\n",
prefs.gui_start_title);
fprintf(pf, "\n# Show version in the start page and main screen's title bar.\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_version_in_start_page == default_prefs.gui_version_in_start_page)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_VERSION_IN_START_PAGE ": %s\n",
prefs.gui_version_in_start_page == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Automatically scroll the recently expanded item.\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.gui_auto_scroll_on_expand == default_prefs.gui_auto_scroll_on_expand)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_AUTO_SCROLL ": %s\n",
prefs.gui_auto_scroll_on_expand == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# The percentage down the view the recently expanded item should be scrolled.\n");
fprintf(pf, "# A decimal number (a percentage).\n");
if (prefs.gui_auto_scroll_percentage == default_prefs.gui_auto_scroll_percentage)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_AUTO_SCROLL_PERCENTAGE ": %d\n",
prefs.gui_auto_scroll_percentage);
fprintf (pf, "\n######## User Interface: Layout ########\n");
fprintf(pf, "\n# Layout type (1-6).\n");
if (prefs.gui_layout_type == default_prefs.gui_layout_type)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_LAYOUT_TYPE ": %d\n",
prefs.gui_layout_type);
fprintf(pf, "\n# Layout content of the panes (1-3).\n");
fprintf(pf, "# One of: NONE, PLIST, PDETAILS, PBYTES\n");
if (prefs.gui_layout_content_1 == default_prefs.gui_layout_content_1)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_LAYOUT_CONTENT_1 ": %s\n",
gui_layout_content_text[prefs.gui_layout_content_1]);
if (prefs.gui_layout_content_2 == default_prefs.gui_layout_content_2)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_LAYOUT_CONTENT_2 ": %s\n",
gui_layout_content_text[prefs.gui_layout_content_2]);
if (prefs.gui_layout_content_3 == default_prefs.gui_layout_content_3)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_LAYOUT_CONTENT_3 ": %s\n",
gui_layout_content_text[prefs.gui_layout_content_3]);
fprintf (pf, "\n######## User Interface: Columns ########\n");
clp = prefs.col_list;
col_l = NULL;
while (clp) {
gchar *prefs_fmt;
cfmt = (fmt_data *) clp->data;
col_l = g_list_append(col_l, g_strdup(cfmt->title));
if ((cfmt->fmt == COL_CUSTOM) && (cfmt->custom_field)) {
prefs_fmt = g_strdup_printf("%s:%s:%d:%c",
col_format_to_string(cfmt->fmt),
cfmt->custom_field,
cfmt->custom_occurrence,
cfmt->resolved ? 'R' : 'U');
} else {
prefs_fmt = g_strdup(col_format_to_string(cfmt->fmt));
}
col_l = g_list_append(col_l, prefs_fmt);
if (!cfmt->visible) {
if (cols_hidden->len) {
g_string_append (cols_hidden, ",");
}
g_string_append (cols_hidden, prefs_fmt);
}
clp = clp->next;
}
fprintf (pf, "\n# Packet list hidden columns.\n");
fprintf (pf, "# List all columns to hide in the packet list.\n");
fprintf (pf, "%s: %s\n", PRS_COL_HIDDEN, cols_hidden->str);
g_string_free (cols_hidden, TRUE);
fprintf (pf, "\n# Packet list column format.\n");
fprintf (pf, "# Each pair of strings consists of a column title and its format.\n");
fprintf (pf, "%s: %s\n", PRS_COL_FMT, put_string_list(col_l));
g_list_free(col_l);
fprintf (pf, "\n######## User Interface: Font ########\n");
fprintf(pf, "\n# Font name for packet list, protocol tree, and hex dump panes.\n");
if (strcmp(prefs.gui_font_name, default_prefs.gui_font_name) == 0)
fprintf(pf, "#");
fprintf(pf, PRS_GUI_FONT_NAME_2 ": %s\n", prefs.gui_font_name);
fprintf (pf, "\n######## User Interface: Colors ########\n");
fprintf (pf, "\n# Color preferences for a marked frame.\n");
fprintf (pf, "# Each value is a six digit hexadecimal color value in the form rrggbb.\n");
if (prefs.gui_marked_fg.red == default_prefs.gui_marked_fg.red &&
prefs.gui_marked_fg.green == default_prefs.gui_marked_fg.green &&
prefs.gui_marked_fg.blue == default_prefs.gui_marked_fg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_GUI_MARKED_FG,
(prefs.gui_marked_fg.red * 255 / 65535),
(prefs.gui_marked_fg.green * 255 / 65535),
(prefs.gui_marked_fg.blue * 255 / 65535));
if (prefs.gui_marked_bg.red == default_prefs.gui_marked_bg.red &&
prefs.gui_marked_bg.green == default_prefs.gui_marked_bg.green &&
prefs.gui_marked_bg.blue == default_prefs.gui_marked_bg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_GUI_MARKED_BG,
(prefs.gui_marked_bg.red * 255 / 65535),
(prefs.gui_marked_bg.green * 255 / 65535),
(prefs.gui_marked_bg.blue * 255 / 65535));
fprintf (pf, "\n# Color preferences for a ignored frame.\n");
fprintf (pf, "# Each value is a six digit hexadecimal color value in the form rrggbb.\n");
if (prefs.gui_ignored_fg.red == default_prefs.gui_ignored_fg.red &&
prefs.gui_ignored_fg.green == default_prefs.gui_ignored_fg.green &&
prefs.gui_ignored_fg.blue == default_prefs.gui_ignored_fg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_GUI_IGNORED_FG,
(prefs.gui_ignored_fg.red * 255 / 65535),
(prefs.gui_ignored_fg.green * 255 / 65535),
(prefs.gui_ignored_fg.blue * 255 / 65535));
if (prefs.gui_ignored_bg.red == default_prefs.gui_ignored_bg.red &&
prefs.gui_ignored_bg.green == default_prefs.gui_ignored_bg.green &&
prefs.gui_ignored_bg.blue == default_prefs.gui_ignored_bg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_GUI_IGNORED_BG,
(prefs.gui_ignored_bg.red * 255 / 65535),
(prefs.gui_ignored_bg.green * 255 / 65535),
(prefs.gui_ignored_bg.blue * 255 / 65535));
fprintf (pf, "\n# TCP stream window color preferences.\n");
fprintf (pf, "# Each value is a six digit hexadecimal color value in the form rrggbb.\n");
if (prefs.st_client_fg.red == default_prefs.st_client_fg.red &&
prefs.st_client_fg.green == default_prefs.st_client_fg.green &&
prefs.st_client_fg.blue == default_prefs.st_client_fg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_STREAM_CL_FG,
(prefs.st_client_fg.red * 255 / 65535),
(prefs.st_client_fg.green * 255 / 65535),
(prefs.st_client_fg.blue * 255 / 65535));
if (prefs.st_client_bg.red == default_prefs.st_client_bg.red &&
prefs.st_client_bg.green == default_prefs.st_client_bg.green &&
prefs.st_client_bg.blue == default_prefs.st_client_bg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_STREAM_CL_BG,
(prefs.st_client_bg.red * 255 / 65535),
(prefs.st_client_bg.green * 255 / 65535),
(prefs.st_client_bg.blue * 255 / 65535));
if (prefs.st_server_fg.red == default_prefs.st_server_fg.red &&
prefs.st_server_fg.green == default_prefs.st_server_fg.green &&
prefs.st_server_fg.blue == default_prefs.st_server_fg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_STREAM_SR_FG,
(prefs.st_server_fg.red * 255 / 65535),
(prefs.st_server_fg.green * 255 / 65535),
(prefs.st_server_fg.blue * 255 / 65535));
if (prefs.st_server_bg.red == default_prefs.st_server_bg.red &&
prefs.st_server_bg.green == default_prefs.st_server_bg.green &&
prefs.st_server_bg.blue == default_prefs.st_server_bg.blue)
fprintf(pf, "#");
fprintf (pf, "%s: %02x%02x%02x\n", PRS_STREAM_SR_BG,
(prefs.st_server_bg.red * 255 / 65535),
(prefs.st_server_bg.green * 255 / 65535),
(prefs.st_server_bg.blue * 255 / 65535));
fprintf(pf, "\n######## Console: logging level ########\n");
fprintf(pf, "# (debugging only, not in the Preferences dialog)\n");
fprintf(pf, "# A bitmask of glib log levels:\n"
"# G_LOG_LEVEL_ERROR = 4\n"
"# G_LOG_LEVEL_CRITICAL = 8\n"
"# G_LOG_LEVEL_WARNING = 16\n"
"# G_LOG_LEVEL_MESSAGE = 32\n"
"# G_LOG_LEVEL_INFO = 64\n"
"# G_LOG_LEVEL_DEBUG = 128\n");
if (prefs.console_log_level == default_prefs.console_log_level)
fprintf(pf, "#");
fprintf(pf, PRS_CONSOLE_LOG_LEVEL ": %u\n",
prefs.console_log_level);
fprintf(pf, "\n####### Capture ########\n");
if (prefs.capture_device != NULL) {
fprintf(pf, "\n# Default capture device\n");
fprintf(pf, PRS_CAP_DEVICE ": %s\n", prefs.capture_device);
}
if (prefs.capture_devices_linktypes != NULL) {
fprintf(pf, "\n# Interface link-layer header types.\n");
fprintf(pf, "# A decimal number for the DLT.\n");
fprintf(pf, "# Ex: en0(1),en1(143),...\n");
fprintf(pf, PRS_CAP_DEVICES_LINKTYPES ": %s\n", prefs.capture_devices_linktypes);
}
if (prefs.capture_devices_descr != NULL) {
fprintf(pf, "\n# Interface descriptions.\n");
fprintf(pf, "# Ex: eth0(eth0 descr),eth1(eth1 descr),...\n");
fprintf(pf, PRS_CAP_DEVICES_DESCR ": %s\n", prefs.capture_devices_descr);
}
if (prefs.capture_devices_hide != NULL) {
fprintf(pf, "\n# Hide interface?\n");
fprintf(pf, "# Ex: eth0,eth3,...\n");
fprintf(pf, PRS_CAP_DEVICES_HIDE ": %s\n", prefs.capture_devices_hide);
}
if (prefs.capture_devices_monitor_mode != NULL) {
fprintf(pf, "\n# By default, capture in monitor mode on interface?\n");
fprintf(pf, "# Ex: eth0,eth3,...\n");
fprintf(pf, PRS_CAP_DEVICES_MONITOR_MODE ": %s\n", prefs.capture_devices_monitor_mode);
}
fprintf(pf, "\n# Capture in promiscuous mode?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.capture_prom_mode == default_prefs.capture_prom_mode)
fprintf(pf, "#");
fprintf(pf, PRS_CAP_PROM_MODE ": %s\n",
prefs.capture_prom_mode == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Capture in Pcap-NG format?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.capture_pcap_ng == default_prefs.capture_pcap_ng)
fprintf(pf, "#");
fprintf(pf, PRS_CAP_PCAP_NG ": %s\n",
prefs.capture_pcap_ng == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Update packet list in real time during capture?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.capture_real_time == default_prefs.capture_real_time)
fprintf(pf, "#");
fprintf(pf, PRS_CAP_REAL_TIME ": %s\n",
prefs.capture_real_time == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Scroll packet list during capture?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.capture_auto_scroll == default_prefs.capture_auto_scroll)
fprintf(pf, "#");
fprintf(pf, PRS_CAP_AUTO_SCROLL ": %s\n",
prefs.capture_auto_scroll == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Show capture info dialog while capturing?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.capture_show_info == default_prefs.capture_show_info)
fprintf(pf, "#");
fprintf(pf, PRS_CAP_SHOW_INFO ": %s\n",
prefs.capture_show_info == TRUE ? "TRUE" : "FALSE");
fprintf (pf, "\n######## Printing ########\n");
fprintf (pf, "\n# Can be one of \"text\" or \"postscript\".\n");
if (prefs.pr_format == default_prefs.pr_format)
fprintf(pf, "#");
fprintf (pf, "print.format: %s\n", pr_formats[prefs.pr_format]);
fprintf (pf, "\n# Can be one of \"command\" or \"file\".\n");
if (prefs.pr_dest == default_prefs.pr_dest)
fprintf(pf, "#");
fprintf (pf, "print.destination: %s\n", pr_dests[prefs.pr_dest]);
fprintf (pf, "\n# This is the file that gets written to when the "
"destination is set to \"file\"\n");
if (strcmp(prefs.pr_file, default_prefs.pr_file) == 0)
fprintf(pf, "#");
fprintf (pf, "%s: %s\n", PRS_PRINT_FILE, prefs.pr_file);
fprintf (pf, "\n# Output gets piped to this command when the destination "
"is set to \"command\"\n");
if (strcmp(prefs.pr_cmd, default_prefs.pr_cmd) == 0)
fprintf(pf, "#");
fprintf (pf, "%s: %s\n", PRS_PRINT_CMD, prefs.pr_cmd);
fprintf(pf, "\n####### Name Resolution ########\n");
fprintf(pf, "\n# Resolve addresses to names?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive), or a list of address types to resolve.\n");
if (prefs.name_resolve == default_prefs.name_resolve)
fprintf(pf, "#");
fprintf(pf, PRS_NAME_RESOLVE ": %s\n",
name_resolve_to_string(prefs.name_resolve));
fprintf(pf, "\n# Name resolution concurrency.\n");
fprintf(pf, "# A decimal number.\n");
if (prefs.name_resolve_concurrency == default_prefs.name_resolve_concurrency)
fprintf(pf, "#");
fprintf(pf, PRS_NAME_RESOLVE_CONCURRENCY ": %d\n",
prefs.name_resolve_concurrency);
fprintf(pf, "\n# Load SMI modules?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.load_smi_modules == default_prefs.load_smi_modules)
fprintf(pf, "#");
fprintf(pf, PRS_NAME_RESOLVE_LOAD_SMI_MODULES ": %s\n",
prefs.load_smi_modules == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n# Suppress SMI errors?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.suppress_smi_errors == default_prefs.suppress_smi_errors)
fprintf(pf, "#");
fprintf(pf, PRS_NAME_RESOLVE_SUPPRESS_SMI_ERRORS ": %s\n",
prefs.suppress_smi_errors == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "\n####### Taps/Statistics ########\n");
fprintf(pf, "\n# Tap update interval in ms.\n");
fprintf(pf, "# An integer value greater between 100 and 10000.\n");
if (prefs.tap_update_interval == default_prefs.tap_update_interval)
fprintf(pf, "#");
fprintf(pf, PRS_TAP_UPDATE_INTERVAL ": %d\n",
prefs.tap_update_interval);
fprintf(pf, "\n# Maximum visible channels in RTP Player window.\n");
fprintf(pf, "# An integer value greater than 0.\n");
if (prefs.rtp_player_max_visible == default_prefs.rtp_player_max_visible)
fprintf(pf, "#");
fprintf(pf, PRS_RTP_PLAYER_MAX_VISIBLE ": %d\n",
prefs.rtp_player_max_visible);
fprintf(pf, "\n####### Filter Expressions ########\n");
{
struct filter_expression *fe;
fe = *(struct filter_expression **)prefs.filter_expressions;
while (fe != NULL) {
if (fe->deleted == FALSE) {
fprintf(pf, "%s: %s\n", PRS_GUI_FILTER_LABEL, fe->label);
fprintf(pf, "%s: %s\n", PRS_GUI_FILTER_ENABLED,
fe->enabled == TRUE ? "TRUE" : "FALSE");
fprintf(pf, "%s: %s\n", PRS_GUI_FILTER_EXPR, fe->expression);
}
fe = fe->next;
}
}
fprintf(pf, "\n####### Protocols ########\n");
fprintf(pf, "\n# Display hidden items in packet details pane?\n");
fprintf(pf, "# TRUE or FALSE (case-insensitive).\n");
if (prefs.display_hidden_proto_items == default_prefs.display_hidden_proto_items)
fprintf(pf, "#");
fprintf(pf, PRS_DISPLAY_HIDDEN_PROTO_ITEMS ": %s\n",
prefs.display_hidden_proto_items == TRUE ? "TRUE" : "FALSE");
pe_tree_foreach(prefs_modules, write_module_prefs, pf);
fclose(pf);
return 0;
}
void
copy_prefs(e_prefs *dest, e_prefs *src)
{
fmt_data *src_cfmt, *dest_cfmt;
GList *entry;
dest->pr_format = src->pr_format;
dest->pr_dest = src->pr_dest;
dest->pr_file = g_strdup(src->pr_file);
dest->pr_cmd = g_strdup(src->pr_cmd);
dest->col_list = NULL;
for (entry = src->col_list; entry != NULL; entry = g_list_next(entry)) {
src_cfmt = entry->data;
dest_cfmt = (fmt_data *) g_malloc(sizeof(fmt_data));
dest_cfmt->title = g_strdup(src_cfmt->title);
dest_cfmt->fmt = src_cfmt->fmt;
if (src_cfmt->custom_field) {
dest_cfmt->custom_field = g_strdup(src_cfmt->custom_field);
dest_cfmt->custom_occurrence = src_cfmt->custom_occurrence;
} else {
dest_cfmt->custom_field = NULL;
dest_cfmt->custom_occurrence = 0;
}
dest_cfmt->visible = src_cfmt->visible;
dest_cfmt->resolved = src_cfmt->resolved;
dest->col_list = g_list_append(dest->col_list, dest_cfmt);
}
dest->num_cols = src->num_cols;
dest->st_client_fg = src->st_client_fg;
dest->st_client_bg = src->st_client_bg;
dest->st_server_fg = src->st_server_fg;
dest->st_server_bg = src->st_server_bg;
dest->gui_scrollbar_on_right = src->gui_scrollbar_on_right;
dest->gui_plist_sel_browse = src->gui_plist_sel_browse;
dest->gui_ptree_sel_browse = src->gui_ptree_sel_browse;
dest->gui_altern_colors = src->gui_altern_colors;
dest->gui_expert_composite_eyecandy = src->gui_expert_composite_eyecandy;
dest->filter_toolbar_show_in_statusbar = src->filter_toolbar_show_in_statusbar;
dest->gui_ptree_line_style = src->gui_ptree_line_style;
dest->gui_ptree_expander_style = src->gui_ptree_expander_style;
dest->gui_hex_dump_highlight_style = src->gui_hex_dump_highlight_style;
dest->gui_toolbar_main_style = src->gui_toolbar_main_style;
dest->gui_toolbar_filter_style = src->gui_toolbar_filter_style;
dest->gui_fileopen_dir = g_strdup(src->gui_fileopen_dir);
dest->gui_console_open = src->gui_console_open;
dest->gui_fileopen_style = src->gui_fileopen_style;
dest->gui_recent_df_entries_max = src->gui_recent_df_entries_max;
dest->gui_recent_files_count_max = src->gui_recent_files_count_max;
dest->gui_fileopen_preview = src->gui_fileopen_preview;
dest->gui_ask_unsaved = src->gui_ask_unsaved;
dest->gui_find_wrap = src->gui_find_wrap;
dest->gui_use_pref_save = src->gui_use_pref_save;
dest->gui_layout_type = src->gui_layout_type;
dest->gui_layout_content_1 = src->gui_layout_content_1;
dest->gui_layout_content_2 = src->gui_layout_content_2;
dest->gui_layout_content_3 = src->gui_layout_content_3;
dest->gui_font_name = g_strdup(src->gui_font_name);
dest->gui_marked_fg = src->gui_marked_fg;
dest->gui_marked_bg = src->gui_marked_bg;
dest->gui_ignored_fg = src->gui_ignored_fg;
dest->gui_ignored_bg = src->gui_ignored_bg;
dest->gui_geometry_save_position = src->gui_geometry_save_position;
dest->gui_geometry_save_size = src->gui_geometry_save_size;
dest->gui_geometry_save_maximized = src->gui_geometry_save_maximized;
dest->gui_macosx_style = src->gui_macosx_style;
dest->gui_webbrowser = g_strdup(src->gui_webbrowser);
dest->gui_window_title = g_strdup(src->gui_window_title);
dest->gui_start_title = g_strdup(src->gui_start_title);
dest->gui_version_in_start_page = src->gui_version_in_start_page;
dest->console_log_level = src->console_log_level;
dest->capture_device = g_strdup(src->capture_device);
dest->capture_devices_linktypes = g_strdup(src->capture_devices_linktypes);
dest->capture_devices_descr = g_strdup(src->capture_devices_descr);
dest->capture_devices_hide = g_strdup(src->capture_devices_hide);
dest->capture_devices_monitor_mode = g_strdup(src->capture_devices_monitor_mode);
dest->capture_prom_mode = src->capture_prom_mode;
dest->capture_pcap_ng = src->capture_pcap_ng;
dest->capture_real_time = src->capture_real_time;
dest->capture_auto_scroll = src->capture_auto_scroll;
dest->capture_show_info = src->capture_show_info;
dest->name_resolve = src->name_resolve;
dest->name_resolve_concurrency = src->name_resolve_concurrency;
dest->tap_update_interval = src->tap_update_interval;
dest->rtp_player_max_visible = src->rtp_player_max_visible;
dest->display_hidden_proto_items = src->display_hidden_proto_items;
}
void
free_prefs(e_prefs *pr)
{
if (pr->pr_file != NULL) {
g_free(pr->pr_file);
pr->pr_file = NULL;
}
if (pr->pr_cmd != NULL) {
g_free(pr->pr_cmd);
pr->pr_cmd = NULL;
}
free_col_info(pr);
if (pr->gui_font_name != NULL) {
g_free(pr->gui_font_name);
pr->gui_font_name = NULL;
}
if (pr->gui_fileopen_dir != NULL) {
g_free(pr->gui_fileopen_dir);
pr->gui_fileopen_dir = NULL;
}
g_free(pr->gui_webbrowser);
pr->gui_webbrowser = NULL;
if (pr->gui_window_title != NULL) {
g_free(pr->gui_window_title);
pr->gui_window_title = NULL;
}
if (pr->gui_start_title != NULL) {
g_free(pr->gui_start_title);
pr->gui_start_title = NULL;
}
if (pr->capture_device != NULL) {
g_free(pr->capture_device);
pr->capture_device = NULL;
}
if (pr->capture_devices_linktypes != NULL) {
g_free(pr->capture_devices_linktypes);
pr->capture_devices_linktypes = NULL;
}
if (pr->capture_devices_descr != NULL) {
g_free(pr->capture_devices_descr);
pr->capture_devices_descr = NULL;
}
if (pr->capture_devices_hide != NULL) {
g_free(pr->capture_devices_hide);
pr->capture_devices_hide = NULL;
}
if (pr->capture_devices_monitor_mode != NULL) {
g_free(pr->capture_devices_monitor_mode);
pr->capture_devices_monitor_mode = NULL;
}
}
static void
free_col_info(e_prefs *pr)
{
fmt_data *cfmt;
while (pr->col_list != NULL) {
cfmt = pr->col_list->data;
g_free(cfmt->title);
g_free(cfmt->custom_field);
g_free(cfmt);
pr->col_list = g_list_remove_link(pr->col_list, pr->col_list);
}
g_list_free(pr->col_list);
pr->col_list = NULL;
}
