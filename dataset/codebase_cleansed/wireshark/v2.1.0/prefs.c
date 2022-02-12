void
prefs_init(void)
{
memset(&prefs, 0, sizeof(prefs));
prefs_modules = wmem_tree_new(wmem_epan_scope());
prefs_top_level_modules = wmem_tree_new(wmem_epan_scope());
}
static void
free_string_like_preference(pref_t *pref)
{
g_free(*pref->varp.string);
*pref->varp.string = NULL;
g_free(pref->default_val.string);
pref->default_val.string = NULL;
}
static void
free_pref(gpointer data, gpointer user_data _U_)
{
pref_t *pref = (pref_t *)data;
int type = pref->type;
RESET_PREF_OBSOLETE(type);
switch (type) {
case PREF_BOOL:
case PREF_ENUM:
case PREF_UINT:
case PREF_STATIC_TEXT:
case PREF_UAT:
case PREF_COLOR:
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
g_free(*pref->varp.string);
*pref->varp.string = NULL;
g_free(pref->default_val.string);
pref->default_val.string = NULL;
break;
case PREF_RANGE:
g_free(*pref->varp.range);
*pref->varp.range = NULL;
g_free(pref->default_val.range);
pref->default_val.range = NULL;
break;
case PREF_CUSTOM:
if (strcmp(pref->name, "columns") == 0)
pref->stashed_val.boolval = TRUE;
pref->custom_cbs.free_cb(pref);
break;
}
g_free(pref);
}
static guint
free_module_prefs(module_t *module, gpointer data _U_)
{
if (module->prefs) {
g_list_foreach(module->prefs, free_pref, NULL);
g_list_free(module->prefs);
}
module->prefs = NULL;
module->numprefs = 0;
if (module->submodules) {
prefs_modules_foreach_submodules(module, free_module_prefs, NULL);
}
return 0;
}
void
prefs_cleanup(void)
{
prefs_modules_foreach(free_module_prefs, NULL);
}
module_t *
prefs_register_module(module_t *parent, const char *name, const char *title,
const char *description, void (*apply_cb)(void),
const gboolean use_gui)
{
return prefs_register_module_or_subtree(parent, name, title, description,
FALSE, apply_cb, use_gui);
}
static void
prefs_deregister_module(module_t *parent, const char *name, const char *title)
{
module_t *module = (module_t *)wmem_tree_remove_string(prefs_modules, name, WMEM_TREE_STRING_NOCASE);
if (!module)
return;
if (parent == NULL) {
wmem_tree_remove_string(prefs_top_level_modules, title, WMEM_TREE_STRING_NOCASE);
} else if (parent->submodules) {
wmem_tree_remove_string(parent->submodules, title, WMEM_TREE_STRING_NOCASE);
}
free_module_prefs(module, NULL);
wmem_free(wmem_epan_scope(), module);
}
module_t *
prefs_register_subtree(module_t *parent, const char *title, const char *description,
void (*apply_cb)(void))
{
return prefs_register_module_or_subtree(parent, NULL, title, description,
TRUE, apply_cb,
parent ? parent->use_gui : FALSE);
}
static module_t *
prefs_register_module_or_subtree(module_t *parent, const char *name,
const char *title, const char *description,
gboolean is_subtree, void (*apply_cb)(void),
gboolean use_gui)
{
module_t *module;
const char *p;
guchar c;
if ((module = find_subtree(parent, title))) {
module->name = name;
module->apply_cb = apply_cb;
module->description = description;
if (prefs_find_module(name) == NULL) {
wmem_tree_insert_string(prefs_modules, name, module,
WMEM_TREE_STRING_NOCASE);
}
return module;
}
module = wmem_new(wmem_epan_scope(), module_t);
module->name = name;
module->title = title;
module->description = description;
module->apply_cb = apply_cb;
module->prefs = NULL;
module->parent = parent;
module->submodules = NULL;
module->numprefs = 0;
module->prefs_changed = FALSE;
module->obsolete = FALSE;
module->use_gui = use_gui;
if (name != NULL) {
for (p = name; (c = *p) != '\0'; p++)
g_assert(g_ascii_islower(c) || g_ascii_isdigit(c) || c == '_' ||
c == '-' || c == '.');
g_assert(prefs_find_module(name) == NULL);
wmem_tree_insert_string(prefs_modules, name, module, WMEM_TREE_STRING_NOCASE);
} else {
g_assert(is_subtree);
}
if (parent == NULL) {
wmem_tree_insert_string(prefs_top_level_modules, title, module, WMEM_TREE_STRING_NOCASE);
} else {
if (parent->submodules == NULL)
parent->submodules = wmem_tree_new(wmem_epan_scope());
wmem_tree_insert_string(parent->submodules, title, module, WMEM_TREE_STRING_NOCASE);
}
return module;
}
module_t *
prefs_register_protocol(int id, void (*apply_cb)(void))
{
protocol_t *protocol;
if (protocols_module == NULL) {
pre_init_prefs();
prefs_register_modules();
}
protocol = find_protocol_by_id(id);
return prefs_register_module(protocols_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), apply_cb, TRUE);
}
void
prefs_deregister_protocol (int id)
{
protocol_t *protocol = find_protocol_by_id(id);
prefs_deregister_module (protocols_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol));
}
module_t *
prefs_register_protocol_subtree(const char *subtree, int id, void (*apply_cb)(void))
{
protocol_t *protocol;
module_t *subtree_module;
module_t *new_module;
char *sep = NULL, *ptr = NULL, *orig = NULL;
if (protocols_module == NULL) {
pre_init_prefs();
prefs_register_modules();
}
subtree_module = protocols_module;
if (subtree) {
orig = ptr = g_strdup(subtree);
while (ptr && *ptr) {
if ((sep = strchr(ptr, '/')))
*sep++ = '\0';
if (!(new_module = find_subtree(subtree_module, ptr))) {
ptr = wmem_strdup(wmem_epan_scope(), ptr),
new_module = prefs_register_subtree(subtree_module, ptr, ptr, NULL);
}
subtree_module = new_module;
ptr = sep;
}
g_free(orig);
}
protocol = find_protocol_by_id(id);
return prefs_register_module(subtree_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), apply_cb, TRUE);
}
module_t *
prefs_register_protocol_obsolete(int id)
{
module_t *module;
protocol_t *protocol;
if (protocols_module == NULL) {
pre_init_prefs();
prefs_register_modules();
}
protocol = find_protocol_by_id(id);
module = prefs_register_module(protocols_module,
proto_get_protocol_filter_name(id),
proto_get_protocol_short_name(protocol),
proto_get_protocol_name(id), NULL, TRUE);
module->obsolete = TRUE;
return module;
}
module_t *
prefs_register_stat(const char *name, const char *title,
const char *description, void (*apply_cb)(void))
{
if (stats_module == NULL) {
pre_init_prefs();
prefs_register_modules();
}
return prefs_register_module(stats_module, name, title, description,
apply_cb, TRUE);
}
module_t *
prefs_find_module(const char *name)
{
return (module_t *)wmem_tree_lookup_string(prefs_modules, name, WMEM_TREE_STRING_NOCASE);
}
static module_t *
find_subtree(module_t *parent, const char *name)
{
return (module_t *)wmem_tree_lookup_string(parent ? parent->submodules : prefs_top_level_modules, name, WMEM_TREE_STRING_NOCASE);
}
static gboolean
call_foreach_cb(const void *key _U_, void *value, void *data)
{
module_t *module = (module_t*)value;
call_foreach_t *call_data = (call_foreach_t*)data;
if (!module->obsolete)
call_data->ret = (*call_data->callback)(module, call_data->user_data);
return (call_data->ret != 0);
}
static guint
prefs_module_list_foreach(wmem_tree_t *module_list, module_cb callback,
gpointer user_data)
{
call_foreach_t call_data;
if (module_list == NULL)
module_list = prefs_top_level_modules;
call_data.callback = callback;
call_data.user_data = user_data;
call_data.ret = 0;
wmem_tree_foreach(module_list, call_foreach_cb, &call_data);
return call_data.ret;
}
gboolean
prefs_module_has_submodules(module_t *module)
{
if (module->submodules == NULL) {
return FALSE;
}
if (wmem_tree_is_empty(module->submodules)) {
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
call_apply_cb(const void *key _U_, void *value, void *data _U_)
{
module_t *module = (module_t *)value;
if (module->obsolete)
return FALSE;
if (module->prefs_changed) {
if (module->apply_cb != NULL)
(*module->apply_cb)();
module->prefs_changed = FALSE;
}
if (module->submodules)
wmem_tree_foreach(module->submodules, call_apply_cb, NULL);
return FALSE;
}
void
prefs_apply_all(void)
{
wmem_tree_foreach(prefs_modules, call_apply_cb, NULL);
}
void
prefs_apply(module_t *module)
{
if (module && module->prefs_changed)
call_apply_cb(NULL, module, NULL);
}
static pref_t *
register_preference(module_t *module, const char *name, const char *title,
const char *description, int type)
{
pref_t *preference;
const gchar *p;
preference = g_new(pref_t,1);
preference->name = name;
preference->title = title;
preference->description = description;
preference->type = type;
preference->gui = GUI_ALL;
if (title != NULL)
preference->ordinal = module->numprefs;
else
preference->ordinal = -1;
for (p = name; *p != '\0'; p++)
if (!(g_ascii_islower(*p) || g_ascii_isdigit(*p) || *p == '_' || *p == '.'))
g_error("Preference %s.%s contains invalid characters", module->name, name);
if (prefs_find_preference(module, name) != NULL)
g_error("Preference %s has already been registered", name);
if ((!IS_PREF_OBSOLETE(type)) &&
(module->name != NULL)) {
if (!((strncmp(name, module->name, strlen(module->name)) != 0) ||
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
const pref_t *pref = (const pref_t *)a;
const char *name = (const char *)b;
return strcmp(name, pref->name);
}
static gboolean
module_find_pref_cb(const void *key _U_, void *value, void *data)
{
find_pref_arg_t* arg = (find_pref_arg_t*)data;
GList *list_entry;
module_t *module = (module_t *)value;
if (module == NULL)
return FALSE;
list_entry = g_list_find_custom(module->prefs, arg->name,
preference_match);
if (list_entry == NULL)
return FALSE;
arg->list_entry = list_entry;
arg->submodule = module;
return TRUE;
}
static struct preference *
prefs_find_preference_with_submodule(module_t *module, const char *name,
module_t **containing_module)
{
find_pref_arg_t arg;
GList *list_entry;
if (module == NULL)
return NULL;
list_entry = g_list_find_custom(module->prefs, name,
preference_match);
arg.submodule = NULL;
if (list_entry == NULL)
{
arg.list_entry = NULL;
if (module->submodules != NULL)
{
arg.name = name;
wmem_tree_foreach(module->submodules, module_find_pref_cb, &arg);
}
list_entry = arg.list_entry;
}
if (list_entry == NULL)
return NULL;
if (containing_module)
*containing_module = arg.submodule ? arg.submodule : module;
return (struct preference *) list_entry->data;
}
struct preference *
prefs_find_preference(module_t *module, const char *name)
{
return prefs_find_preference_with_submodule(module, name, NULL);
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
static void
prefs_register_uint_custom_preference(module_t *module, const char *name,
const char *title, const char *description,
struct pref_custom_cbs* custom_cbs, guint *var)
{
pref_t *preference;
preference = register_preference(module, name, title, description,
PREF_CUSTOM);
preference->custom_cbs = *custom_cbs;
preference->varp.uint = var;
preference->default_val.uint = *var;
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
char **var, int type,
struct pref_custom_cbs* custom_cbs,
gboolean free_tmp)
{
pref_t *pref;
gchar *tmp;
pref = register_preference(module, name, title, description, type);
tmp = *var;
if (*var == NULL) {
*var = g_strdup("");
} else {
*var = g_strdup(*var);
}
if (free_tmp) {
g_free(tmp);
}
pref->varp.string = var;
pref->default_val.string = g_strdup(*var);
pref->stashed_val.string = NULL;
if (type == PREF_CUSTOM) {
g_assert(custom_cbs);
pref->custom_cbs = *custom_cbs;
}
}
void
prefs_set_string_like_value(pref_t *pref, const gchar *value, gboolean *changed)
{
if (*pref->varp.string) {
if (strcmp(*pref->varp.string, value) != 0) {
*changed = TRUE;
g_free(*pref->varp.string);
*pref->varp.string = g_strdup(value);
}
} else if (value) {
*pref->varp.string = g_strdup(value);
}
}
static void
reset_string_like_preference(pref_t *pref)
{
g_free(*pref->varp.string);
*pref->varp.string = g_strdup(pref->default_val.string);
}
void
prefs_register_string_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var)
{
DIAG_OFF(cast-qual)
register_string_like_preference(module, name, title, description,
(char **)var, PREF_STRING, NULL, FALSE);
DIAG_ON(cast-qual)
}
void
prefs_register_filename_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var)
{
DIAG_OFF(cast-qual)
register_string_like_preference(module, name, title, description,
(char **)var, PREF_FILENAME, NULL, FALSE);
DIAG_ON(cast-qual)
}
void
prefs_register_directory_preference(module_t *module, const char *name,
const char *title, const char *description,
const char **var)
{
DIAG_OFF(cast-qual)
register_string_like_preference(module, name, title, description,
(char **)var, PREF_DIRNAME, NULL, FALSE);
DIAG_ON(cast-qual)
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
preference->stashed_val.range = NULL;
}
static gboolean
prefs_set_range_value_work(pref_t *pref, const gchar *value,
gboolean return_range_errors, gboolean *changed)
{
range_t *newrange;
if (range_convert_str_work(&newrange, value, pref->info.max_value,
return_range_errors) != CVT_NO_ERROR) {
return FALSE;
}
if (!ranges_are_equal(*pref->varp.range, newrange)) {
*changed = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = newrange;
} else {
g_free(newrange);
}
return TRUE;
}
gboolean
prefs_set_range_value(pref_t *pref, const gchar *value, gboolean *changed)
{
return prefs_set_range_value_work(pref, value, TRUE, changed);
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
uat_t* uat)
{
pref_t* preference = register_preference(module, name, title, description, PREF_UAT);
preference->varp.uat = uat;
}
extern void
prefs_register_uat_preference_qt(module_t *module, const char *name,
const char *title, const char *description,
uat_t* uat)
{
pref_t* preference = register_preference(module, name, title, description, PREF_UAT);
preference->varp.uat = uat;
preference->gui = GUI_QT;
}
void
prefs_register_color_preference(module_t *module, const char *name,
const char *title, const char *description,
color_t *color)
{
pref_t* preference = register_preference(module, name, title, description, PREF_COLOR);
preference->varp.colorp = color;
preference->default_val.color = *color;
}
static void
prefs_register_list_custom_preference(module_t *module, const char *name,
const char *title, const char *description,
struct pref_custom_cbs* custom_cbs,
pref_custom_list_init_cb init_cb,
GList** list)
{
pref_t* preference = register_preference(module, name, title, description, PREF_CUSTOM);
preference->custom_cbs = *custom_cbs;
init_cb(preference, list);
}
void
prefs_register_custom_preference(module_t *module, const char *name,
const char *title, const char *description,
struct pref_custom_cbs* custom_cbs,
void **custom_data _U_)
{
pref_t* preference = register_preference(module, name, title, description, PREF_CUSTOM);
preference->custom_cbs = *custom_cbs;
}
void
prefs_register_obsolete_preference(module_t *module, const char *name)
{
register_preference(module, name, NULL, NULL, PREF_OBSOLETE);
}
extern gboolean
prefs_get_preference_obsolete(pref_t *pref)
{
if (pref)
return (IS_PREF_OBSOLETE(pref->type) ? TRUE : FALSE);
return TRUE;
}
extern prefs_set_pref_e
prefs_set_preference_obsolete(pref_t *pref)
{
if (pref) {
SET_PREF_OBSOLETE(pref->type);
return PREFS_SET_OK;
}
return PREFS_SET_NO_SUCH_PREF;
}
guint
prefs_pref_foreach(module_t *module, pref_cb callback, gpointer user_data)
{
GList *elem;
pref_t *pref;
guint ret;
for (elem = g_list_first(module->prefs); elem != NULL; elem = g_list_next(elem)) {
pref = (pref_t *)elem->data;
if (IS_PREF_OBSOLETE(pref->type)) {
continue;
}
ret = (*callback)(pref, user_data);
if (ret != 0)
return ret;
}
return 0;
}
static void
stats_callback(void)
{
if (prefs.tap_update_interval < 100 || prefs.tap_update_interval > 10000)
prefs.tap_update_interval = TAP_UPDATE_DEFAULT_INTERVAL;
#ifdef HAVE_LIBPORTAUDIO
if (prefs.rtp_player_max_visible < 1 || prefs.rtp_player_max_visible > 10)
prefs.rtp_player_max_visible = RTP_PLAYER_DEFAULT_VISIBLE;
#endif
if (prefs.st_burst_resolution < 1) {
prefs.st_burst_resolution = 1;
}
else if (prefs.st_burst_resolution > ST_MAX_BURSTRES) {
prefs.st_burst_resolution = ST_MAX_BURSTRES;
}
if (prefs.st_burst_windowlen < prefs.st_burst_resolution) {
prefs.st_burst_windowlen = prefs.st_burst_resolution;
}
prefs.st_burst_windowlen -= prefs.st_burst_windowlen%prefs.st_burst_resolution;
if ((prefs.st_burst_windowlen/prefs.st_burst_resolution) > ST_MAX_BURSTBUCKETS) {
prefs.st_burst_windowlen = prefs.st_burst_resolution*ST_MAX_BURSTBUCKETS;
}
}
static void
gui_callback(void)
{
if (prefs.gui_recent_files_count_max == 0)
prefs.gui_recent_files_count_max = 10;
if (prefs.gui_recent_df_entries_max == 0)
prefs.gui_recent_df_entries_max = 10;
}
static void
gui_layout_callback(void)
{
if (prefs.gui_layout_type == layout_unused ||
prefs.gui_layout_type >= layout_type_max) {
prefs.gui_layout_type = layout_type_5;
}
}
static void custom_pref_no_cb(pref_t* pref _U_) {}
static void
console_log_level_reset_cb(pref_t* pref)
{
*pref->varp.uint = pref->default_val.uint;
}
static prefs_set_pref_e
console_log_level_set_cb(pref_t* pref, const gchar* value, gboolean* changed)
{
guint uval;
uval = (guint)strtoul(value, NULL, 10);
if (*pref->varp.uint != uval) {
*changed = TRUE;
*pref->varp.uint = uval;
}
if (*pref->varp.uint & (G_LOG_LEVEL_INFO|G_LOG_LEVEL_DEBUG)) {
g_setenv("G_MESSAGES_DEBUG", "all", TRUE);
}
return PREFS_SET_OK;
}
static const char * console_log_level_type_name_cb(void) {
return "Log level";
}
static char * console_log_level_type_description_cb(void) {
return g_strdup_printf(
"Console log level (for debugging)\n"
"A bitmask of log levels:\n"
"ERROR = 4\n"
"CRITICAL = 8\n"
"WARNING = 16\n"
"MESSAGE = 32\n"
"INFO = 64\n"
"DEBUG = 128");
}
static gboolean console_log_level_is_default_cb(pref_t* pref) {
return *pref->varp.uint == pref->default_val.uint;
}
static char * console_log_level_to_str_cb(pref_t* pref, gboolean default_val) {
return g_strdup_printf("%u", default_val ? pref->default_val.uint : *pref->varp.uint);
}
static prefs_set_pref_e
column_hidden_set_cb(pref_t* pref, const gchar* value, gboolean* changed)
{
GList *clp;
fmt_data *cfmt;
pref_t *format_pref;
prefs_set_string_like_value(pref, value, changed);
format_pref = prefs_find_preference(gui_column_module, PRS_COL_FMT);
for (clp = *format_pref->varp.list; clp != NULL; clp = clp->next) {
cfmt = (fmt_data *)clp->data;
cfmt->visible = prefs_is_column_visible(*pref->varp.string, cfmt);
}
return PREFS_SET_OK;
}
static const char *
column_hidden_type_name_cb(void)
{
return "Packet list hidden columns";
}
static char *
column_hidden_type_description_cb(void)
{
return g_strdup("List all columns to hide in the packet list.");
}
static char *
column_hidden_to_str_cb(pref_t* pref, gboolean default_val)
{
GString *cols_hidden = g_string_new ("");
GList *clp;
fmt_data *cfmt;
pref_t *format_pref;
if (default_val)
return g_strdup(pref->default_val.string);
format_pref = prefs_find_preference(gui_column_module, PRS_COL_FMT);
clp = (format_pref) ? *format_pref->varp.list : NULL;
while (clp) {
gchar *prefs_fmt;
cfmt = (fmt_data *) clp->data;
if ((cfmt->fmt == COL_CUSTOM) && (cfmt->custom_fields)) {
prefs_fmt = g_strdup_printf("%s:%s:%d:%c",
col_format_to_string(cfmt->fmt),
cfmt->custom_fields,
cfmt->custom_occurrence,
cfmt->resolved ? 'R' : 'U');
} else {
prefs_fmt = g_strdup(col_format_to_string(cfmt->fmt));
}
if (!cfmt->visible) {
if (cols_hidden->len)
g_string_append (cols_hidden, ",");
g_string_append (cols_hidden, prefs_fmt);
}
g_free(prefs_fmt);
clp = clp->next;
}
return g_string_free (cols_hidden, FALSE);
}
static gboolean
column_hidden_is_default_cb(pref_t* pref)
{
char *cur_hidden_str = column_hidden_to_str_cb(pref, FALSE);
gboolean is_default = g_strcmp0(cur_hidden_str, pref->default_val.string) == 0;
g_free(cur_hidden_str);
return is_default;
}
static void
column_num_reset_cb(pref_t* pref)
{
*pref->varp.uint = pref->default_val.uint;
}
static prefs_set_pref_e
column_num_set_cb(pref_t* pref _U_, const gchar* value _U_, gboolean* changed _U_)
{
return PREFS_SET_OK;
}
static const char *
column_num_type_name_cb(void)
{
return NULL;
}
static char *
column_num_type_description_cb(void)
{
return g_strdup("");
}
static gboolean
column_num_is_default_cb(pref_t* pref _U_)
{
return TRUE;
}
static char *
column_num_to_str_cb(pref_t* pref _U_, gboolean default_val _U_)
{
return g_strdup("");
}
static void
column_format_init_cb(pref_t* pref, GList** value)
{
fmt_data *src_cfmt, *dest_cfmt;
GList *entry;
pref->varp.list = value;
pref->default_val.list = NULL;
for (entry = *pref->varp.list; entry != NULL; entry = g_list_next(entry)) {
src_cfmt = (fmt_data *)entry->data;
dest_cfmt = g_new(fmt_data,1);
dest_cfmt->title = g_strdup(src_cfmt->title);
dest_cfmt->fmt = src_cfmt->fmt;
if (src_cfmt->custom_fields) {
dest_cfmt->custom_fields = g_strdup(src_cfmt->custom_fields);
dest_cfmt->custom_occurrence = src_cfmt->custom_occurrence;
} else {
dest_cfmt->custom_fields = NULL;
dest_cfmt->custom_occurrence = 0;
}
dest_cfmt->visible = src_cfmt->visible;
dest_cfmt->resolved = src_cfmt->resolved;
pref->default_val.list = g_list_append(pref->default_val.list, dest_cfmt);
}
}
static void
column_format_free_cb(pref_t* pref)
{
free_col_info(*pref->varp.list);
free_col_info(pref->default_val.list);
}
static void
column_format_reset_cb(pref_t* pref)
{
fmt_data *src_cfmt, *dest_cfmt;
GList *entry;
pref_t *col_num_pref;
free_col_info(*pref->varp.list);
*pref->varp.list = NULL;
for (entry = pref->default_val.list; entry != NULL; entry = g_list_next(entry)) {
src_cfmt = (fmt_data *)entry->data;
dest_cfmt = g_new(fmt_data,1);
dest_cfmt->title = g_strdup(src_cfmt->title);
dest_cfmt->fmt = src_cfmt->fmt;
if (src_cfmt->custom_fields) {
dest_cfmt->custom_fields = g_strdup(src_cfmt->custom_fields);
dest_cfmt->custom_occurrence = src_cfmt->custom_occurrence;
} else {
dest_cfmt->custom_fields = NULL;
dest_cfmt->custom_occurrence = 0;
}
dest_cfmt->visible = src_cfmt->visible;
dest_cfmt->resolved = src_cfmt->resolved;
*pref->varp.list = g_list_append(*pref->varp.list, dest_cfmt);
}
col_num_pref = prefs_find_preference(gui_column_module, PRS_COL_NUM);
g_assert(col_num_pref != NULL);
column_num_reset_cb(col_num_pref);
}
static prefs_set_pref_e
column_format_set_cb(pref_t* pref, const gchar* value, gboolean* changed _U_)
{
GList *col_l, *col_l_elt;
fmt_data *cfmt;
gint llen;
pref_t *hidden_pref, *col_num_pref;
col_l = prefs_get_string_list(value);
if (col_l == NULL)
return PREFS_SET_SYNTAX_ERR;
if ((g_list_length(col_l) % 2) != 0) {
prefs_clear_string_list(col_l);
return PREFS_SET_SYNTAX_ERR;
}
col_l_elt = g_list_first(col_l);
while (col_l_elt) {
fmt_data cfmt_check;
col_l_elt = col_l_elt->next;
if (!parse_column_format(&cfmt_check, (char *)col_l_elt->data)) {
prefs_clear_string_list(col_l);
return PREFS_SET_SYNTAX_ERR;
}
if (cfmt_check.fmt != COL_CUSTOM) {
try_convert_to_custom_column(&col_l_elt->data);
} else {
g_free(cfmt_check.custom_fields);
}
col_l_elt = col_l_elt->next;
}
free_col_info(*pref->varp.list);
*pref->varp.list = NULL;
hidden_pref = prefs_find_preference(gui_column_module, PRS_COL_HIDDEN);
g_assert(hidden_pref != NULL);
col_num_pref = prefs_find_preference(gui_column_module, PRS_COL_NUM);
g_assert(col_num_pref != NULL);
llen = g_list_length(col_l);
*col_num_pref->varp.uint = llen / 2;
col_l_elt = g_list_first(col_l);
while (col_l_elt) {
cfmt = g_new(fmt_data,1);
cfmt->title = g_strdup((gchar *)col_l_elt->data);
col_l_elt = col_l_elt->next;
parse_column_format(cfmt, (char *)col_l_elt->data);
cfmt->visible = prefs_is_column_visible(*hidden_pref->varp.string, cfmt);
col_l_elt = col_l_elt->next;
*pref->varp.list = g_list_append(*pref->varp.list, cfmt);
}
prefs_clear_string_list(col_l);
free_string_like_preference(hidden_pref);
return PREFS_SET_OK;
}
static const char *
column_format_type_name_cb(void)
{
return "Packet list column format";
}
static char *
column_format_type_description_cb(void)
{
return g_strdup("Each pair of strings consists of a column title and its format");
}
static gboolean
column_format_is_default_cb(pref_t* pref)
{
GList *clp = *pref->varp.list,
*pref_col = g_list_first(clp),
*def_col = g_list_first(pref->default_val.list);
fmt_data *cfmt, *def_cfmt;
gboolean is_default = TRUE;
pref_t *col_num_pref;
col_num_pref = prefs_find_preference(gui_column_module, PRS_COL_NUM);
if (col_num_pref && *col_num_pref->varp.uint != col_num_pref->default_val.uint) {
is_default = FALSE;
} else {
while (pref_col && def_col) {
cfmt = (fmt_data *) pref_col->data;
def_cfmt = (fmt_data *) def_col->data;
if ((g_strcmp0(cfmt->title, def_cfmt->title) != 0) ||
(cfmt->fmt != def_cfmt->fmt) ||
(((cfmt->fmt == COL_CUSTOM) && (cfmt->custom_fields)) &&
((g_strcmp0(cfmt->custom_fields, def_cfmt->custom_fields) != 0) ||
(cfmt->resolved != def_cfmt->resolved)))) {
is_default = FALSE;
break;
}
pref_col = pref_col->next;
def_col = def_col->next;
}
}
return is_default;
}
static char *
column_format_to_str_cb(pref_t* pref, gboolean default_val)
{
GList *pref_l = default_val ? pref->default_val.list : *pref->varp.list;
GList *clp = g_list_first(pref_l);
GList *col_l;
fmt_data *cfmt;
gchar *prefs_fmt;
char *column_format_str;
col_l = NULL;
while (clp) {
cfmt = (fmt_data *) clp->data;
col_l = g_list_append(col_l, g_strdup(cfmt->title));
if ((cfmt->fmt == COL_CUSTOM) && (cfmt->custom_fields)) {
prefs_fmt = g_strdup_printf("%s:%s:%d:%c",
col_format_to_string(cfmt->fmt),
cfmt->custom_fields,
cfmt->custom_occurrence,
cfmt->resolved ? 'R' : 'U');
} else {
prefs_fmt = g_strdup(col_format_to_string(cfmt->fmt));
}
col_l = g_list_append(col_l, prefs_fmt);
clp = clp->next;
}
column_format_str = join_string_list(col_l);
prefs_clear_string_list(col_l);
return column_format_str;
}
static void
capture_column_init_cb(pref_t* pref, GList** capture_cols_values)
{
GList *ccv_list = *capture_cols_values,
*dlist = NULL;
while (ccv_list) {
dlist = g_list_append(dlist, g_strdup((gchar *)ccv_list->data));
ccv_list = ccv_list->next;
}
pref->default_val.list = dlist;
pref->varp.list = &prefs.capture_columns;
pref->stashed_val.boolval = FALSE;
}
static void
capture_column_free_cb(pref_t* pref)
{
prefs_clear_string_list(prefs.capture_columns);
prefs.capture_columns = NULL;
if (pref->stashed_val.boolval == TRUE) {
prefs_clear_string_list(pref->default_val.list);
pref->default_val.list = NULL;
}
}
static void
capture_column_reset_cb(pref_t* pref)
{
GList *vlist = NULL, *dlist;
prefs_clear_string_list(*pref->varp.list);
for (dlist = pref->default_val.list; dlist != NULL; dlist = g_list_next(dlist)) {
vlist = g_list_append(vlist, g_strdup((gchar *)dlist->data));
}
*pref->varp.list = vlist;
}
static prefs_set_pref_e
capture_column_set_cb(pref_t* pref, const gchar* value, gboolean* changed _U_)
{
GList *col_l = prefs_get_string_list(value);
GList *col_l_elt;
gchar *col_name;
int i;
if (col_l == NULL)
return PREFS_SET_SYNTAX_ERR;
capture_column_free_cb(pref);
col_l_elt = g_list_first(col_l);
if (!(*(gchar *)col_l_elt->data)) {
for (i = 0; i < num_capture_cols; i++) {
col_name = g_strdup(capture_cols[i]);
prefs.capture_columns = g_list_append(prefs.capture_columns, col_name);
}
}
while (col_l_elt) {
gboolean found_match = FALSE;
col_name = (gchar *)col_l_elt->data;
for (i = 0; i < num_capture_cols; i++) {
if (strcmp(col_name, capture_cols[i])==0) {
found_match = TRUE;
break;
}
}
if (!found_match) {
for (i = 0; i < num_capture_cols; i++) {
col_name = g_strdup(capture_cols[i]);
prefs.capture_columns = g_list_append(prefs.capture_columns, col_name);
}
pref->varp.list = &prefs.capture_columns;
prefs_clear_string_list(col_l);
return PREFS_SET_SYNTAX_ERR;
}
col_l_elt = col_l_elt->next;
}
col_l_elt = g_list_first(col_l);
while (col_l_elt) {
col_name = (gchar *)col_l_elt->data;
prefs.capture_columns = g_list_append(prefs.capture_columns, col_name);
col_l_elt = col_l_elt->next;
}
pref->varp.list = &prefs.capture_columns;
g_list_free(col_l);
return PREFS_SET_OK;
}
static const char *
capture_column_type_name_cb(void)
{
return "Column list";
}
static char *
capture_column_type_description_cb(void)
{
return g_strdup(
"List of columns to be displayed in the capture options dialog.\n"
CAPTURE_COL_TYPE_DESCRIPTION);
}
static gboolean
capture_column_is_default_cb(pref_t* pref)
{
GList *pref_col = g_list_first(prefs.capture_columns),
*def_col = g_list_first(pref->default_val.list);
gboolean is_default = TRUE;
while (pref_col && def_col) {
if (strcmp((gchar *)pref_col->data, (gchar *)def_col->data) != 0) {
is_default = FALSE;
break;
}
pref_col = pref_col->next;
def_col = def_col->next;
}
if (((pref_col == NULL) && (def_col != NULL)) ||
((pref_col != NULL) && (def_col == NULL)))
is_default = FALSE;
return is_default;
}
static char *
capture_column_to_str_cb(pref_t* pref, gboolean default_val)
{
GList *pref_l = default_val ? pref->default_val.list : prefs.capture_columns;
GList *clp = g_list_first(pref_l);
GList *col_l = NULL;
gchar *col;
char *capture_column_str;
while (clp) {
col = (gchar *) clp->data;
col_l = g_list_append(col_l, g_strdup(col));
clp = clp->next;
}
capture_column_str = join_string_list(col_l);
prefs_clear_string_list(col_l);
return capture_column_str;
}
static prefs_set_pref_e
colorized_frame_set_cb(pref_t* pref, const gchar* value, gboolean* changed)
{
prefs_set_string_like_value(pref, value, changed);
return PREFS_SET_OK;
}
static const char *
colorized_frame_type_name_cb(void)
{
return NULL;
}
static char *
colorized_frame_type_description_cb(void)
{
return g_strdup("");
}
static gboolean
colorized_frame_is_default_cb(pref_t* pref _U_)
{
return TRUE;
}
static char *
colorized_frame_to_str_cb(pref_t* pref _U_, gboolean default_val _U_)
{
return g_strdup("");
}
static void
prefs_register_modules(void)
{
module_t *printing, *capture_module, *console_module,
*gui_layout_module, *gui_font_module;
#ifdef HAVE_EXTCAP
module_t *extcap_module;
#endif
struct pref_custom_cbs custom_cbs;
if (protocols_module != NULL) {
return;
}
#ifdef HAVE_EXTCAP
extcap_module = prefs_register_module(NULL, "extcap", "Extcap Utilities",
"Extcap Utilities", NULL, FALSE);
prefs.extcap_save_on_start = TRUE;
prefs_register_bool_preference(extcap_module, "gui_save_on_start",
"Save arguments on start of capture",
"Save arguments on start of capture",
&prefs.extcap_save_on_start);
#endif
gui_module = prefs_register_module(NULL, "gui", "User Interface",
"User Interface", &gui_callback, FALSE);
prefs_register_enum_preference(gui_module, "console_open",
"Open a console window",
"Open a console window (Windows only)",
(gint*)(void*)(&prefs.gui_console_open), gui_console_open_type, FALSE);
prefs_register_obsolete_preference(gui_module, "scrollbar_on_right");
prefs_register_obsolete_preference(gui_module, "packet_list_sel_browse");
prefs_register_obsolete_preference(gui_module, "protocol_tree_sel_browse");
prefs_register_bool_preference(gui_module, "tree_view_altern_colors",
"Alternating colors in TreeViews",
"Alternating colors in TreeViews?",
&prefs.gui_altern_colors);
prefs_register_bool_preference(gui_module, "expert_composite_eyecandy",
"Display Icons on Expert Composite Dialog Tabs",
"Display Icons on Expert Composite Dialog Tabs?",
&prefs.gui_expert_composite_eyecandy);
prefs_register_bool_preference(gui_module, "filter_toolbar_show_in_statusbar",
"Place filter toolbar inside the statusbar",
"Place filter toolbar inside the statusbar?",
&prefs.filter_toolbar_show_in_statusbar);
prefs_register_enum_preference(gui_module, "protocol_tree_line_style",
"Protocol-tree line style",
"Protocol-tree line style",
&prefs.gui_ptree_line_style, gui_ptree_line_style, FALSE);
prefs_register_enum_preference(gui_module, "protocol_tree_expander_style",
"Protocol-tree expander style",
"Protocol-tree expander style",
&prefs.gui_ptree_expander_style, gui_ptree_expander_style, FALSE);
prefs_register_enum_preference(gui_module, "hex_dump_highlight_style",
"Hex dump highlight style",
"Hex dump highlight style",
&prefs.gui_hex_dump_highlight_style, gui_hex_dump_highlight_style, FALSE);
gui_column_module = prefs_register_subtree(gui_module, "Columns", "Columns", NULL);
custom_cbs.free_cb = free_string_like_preference;
custom_cbs.reset_cb = reset_string_like_preference;
custom_cbs.set_cb = column_hidden_set_cb;
custom_cbs.type_name_cb = column_hidden_type_name_cb;
custom_cbs.type_description_cb = column_hidden_type_description_cb;
custom_cbs.is_default_cb = column_hidden_is_default_cb;
custom_cbs.to_str_cb = column_hidden_to_str_cb;
register_string_like_preference(gui_column_module, PRS_COL_HIDDEN, "Packet list hidden columns",
"List all columns to hide in the packet list",
&cols_hidden_list, PREF_CUSTOM, &custom_cbs, FALSE);
custom_cbs.free_cb = column_format_free_cb;
custom_cbs.reset_cb = column_format_reset_cb;
custom_cbs.set_cb = column_format_set_cb;
custom_cbs.type_name_cb = column_format_type_name_cb;
custom_cbs.type_description_cb = column_format_type_description_cb;
custom_cbs.is_default_cb = column_format_is_default_cb;
custom_cbs.to_str_cb = column_format_to_str_cb;
prefs_register_list_custom_preference(gui_column_module, PRS_COL_FMT, "Packet list column format",
"Each pair of strings consists of a column title and its format", &custom_cbs,
column_format_init_cb, &prefs.col_list);
custom_cbs.free_cb = custom_pref_no_cb;
custom_cbs.reset_cb = column_num_reset_cb;
custom_cbs.set_cb = column_num_set_cb;
custom_cbs.type_name_cb = column_num_type_name_cb;
custom_cbs.type_description_cb = column_num_type_description_cb;
custom_cbs.is_default_cb = column_num_is_default_cb;
custom_cbs.to_str_cb = column_num_to_str_cb;
prefs_register_uint_custom_preference(gui_column_module, PRS_COL_NUM, "Number of columns",
"Number of columns in col_list", &custom_cbs, &prefs.num_cols);
gui_font_module = prefs_register_subtree(gui_module, "Font", "Font", NULL);
prefs_register_obsolete_preference(gui_font_module, "font_name");
register_string_like_preference(gui_font_module, "gtk2.font_name", "Font name",
"Font name for packet list, protocol tree, and hex dump panes. (GTK+)",
&prefs.gui_gtk2_font_name, PREF_STRING, NULL, TRUE);
register_string_like_preference(gui_font_module, "qt.font_name", "Font name",
"Font name for packet list, protocol tree, and hex dump panes. (Qt)",
&prefs.gui_qt_font_name, PREF_STRING, NULL, TRUE);
gui_color_module = prefs_register_subtree(gui_module, "Colors", "Colors", NULL);
prefs_register_color_preference(gui_color_module, "marked_frame.fg", "Color preferences for a marked frame",
"Color preferences for a marked frame", &prefs.gui_marked_fg);
prefs_register_color_preference(gui_color_module, "marked_frame.bg", "Color preferences for a marked frame",
"Color preferences for a marked frame", &prefs.gui_marked_bg);
prefs_register_color_preference(gui_color_module, "ignored_frame.fg", "Color preferences for a ignored frame",
"Color preferences for a ignored frame", &prefs.gui_ignored_fg);
prefs_register_color_preference(gui_color_module, "ignored_frame.bg", "Color preferences for a ignored frame",
"Color preferences for a ignored frame", &prefs.gui_ignored_bg);
prefs_register_color_preference(gui_color_module, "stream.client.fg", "TCP stream window color preference",
"TCP stream window color preference", &prefs.st_client_fg);
prefs_register_color_preference(gui_color_module, "stream.client.bg", "TCP stream window color preference",
"TCP stream window color preference", &prefs.st_client_bg);
prefs_register_color_preference(gui_color_module, "stream.server.fg", "TCP stream window color preference",
"TCP stream window color preference", &prefs.st_server_fg);
prefs_register_color_preference(gui_color_module, "stream.server.bg", "TCP stream window color preference",
"TCP stream window color preference", &prefs.st_server_bg);
custom_cbs.free_cb = free_string_like_preference;
custom_cbs.reset_cb = reset_string_like_preference;
custom_cbs.set_cb = colorized_frame_set_cb;
custom_cbs.type_name_cb = colorized_frame_type_name_cb;
custom_cbs.type_description_cb = colorized_frame_type_description_cb;
custom_cbs.is_default_cb = colorized_frame_is_default_cb;
custom_cbs.to_str_cb = colorized_frame_to_str_cb;
register_string_like_preference(gui_column_module, "colorized_frame.fg", "Colorized Foreground",
"Filter Colorized Foreground",
&prefs.gui_colorized_fg, PREF_CUSTOM, &custom_cbs, TRUE);
custom_cbs.free_cb = free_string_like_preference;
custom_cbs.reset_cb = reset_string_like_preference;
custom_cbs.set_cb = colorized_frame_set_cb;
custom_cbs.type_name_cb = colorized_frame_type_name_cb;
custom_cbs.type_description_cb = colorized_frame_type_description_cb;
custom_cbs.is_default_cb = colorized_frame_is_default_cb;
custom_cbs.to_str_cb = colorized_frame_to_str_cb;
register_string_like_preference(gui_column_module, "colorized_frame.bg", "Colorized Background",
"Filter Colorized Background",
&prefs.gui_colorized_bg, PREF_CUSTOM, &custom_cbs, TRUE);
prefs_register_color_preference(gui_color_module, "color_filter_bg.valid", "Valid color filter background",
"Valid color filter background", &prefs.gui_text_valid);
prefs_register_color_preference(gui_color_module, "color_filter_bg.invalid", "Invalid color filter background",
"Invalid color filter background", &prefs.gui_text_invalid);
prefs_register_color_preference(gui_color_module, "color_filter_bg.deprecated", "Deprecated color filter background",
"Deprecated color filter background", &prefs.gui_text_deprecated);
prefs_register_enum_preference(gui_module, "fileopen.style",
"Where to start the File Open dialog box",
"Where to start the File Open dialog box",
&prefs.gui_fileopen_style, gui_fileopen_style, FALSE);
prefs_register_uint_preference(gui_module, "recent_files_count.max",
"The max. number of items in the open recent files list",
"The max. number of items in the open recent files list",
10,
&prefs.gui_recent_files_count_max);
prefs_register_uint_preference(gui_module, "recent_display_filter_entries.max",
"The max. number of entries in the display filter list",
"The max. number of entries in the display filter list",
10,
&prefs.gui_recent_df_entries_max);
register_string_like_preference(gui_module, "fileopen.dir", "Start Directory",
"Directory to start in when opening File Open dialog.",
&prefs.gui_fileopen_dir, PREF_DIRNAME, NULL, TRUE);
prefs_register_obsolete_preference(gui_module, "fileopen.remembered_dir");
prefs_register_uint_preference(gui_module, "fileopen.preview",
"The preview timeout in the File Open dialog",
"The preview timeout in the File Open dialog",
10,
&prefs.gui_fileopen_preview);
prefs_register_bool_preference(gui_module, "ask_unsaved",
"Ask to save unsaved capture files",
"Ask to save unsaved capture files?",
&prefs.gui_ask_unsaved);
prefs_register_bool_preference(gui_module, "find_wrap",
"Wrap to beginning/end of file during search",
"Wrap to beginning/end of file during search?",
&prefs.gui_find_wrap);
prefs_register_bool_preference(gui_module, "use_pref_save",
"Settings dialogs use a save button",
"Settings dialogs use a save button?",
&prefs.gui_use_pref_save);
prefs_register_bool_preference(gui_module, "geometry.save.position",
"Save window position at exit",
"Save window position at exit?",
&prefs.gui_geometry_save_position);
prefs_register_bool_preference(gui_module, "geometry.save.size",
"Save window size at exit",
"Save window size at exit?",
&prefs.gui_geometry_save_size);
prefs_register_bool_preference(gui_module, "geometry.save.maximized",
"Save window maximized state at exit",
"Save window maximized state at exit?",
&prefs.gui_geometry_save_maximized);
prefs_register_bool_preference(gui_module, "macosx_style",
"Use OS X style",
"Use OS X style (OS X with native GTK only)?",
&prefs.gui_macosx_style);
prefs_register_obsolete_preference(gui_module, "geometry.main.x");
prefs_register_obsolete_preference(gui_module, "geometry.main.y");
prefs_register_obsolete_preference(gui_module, "geometry.main.width");
prefs_register_obsolete_preference(gui_module, "geometry.main.height");
prefs_register_obsolete_preference(gui_module, "toolbar_main_show");
prefs_register_enum_preference(gui_module, "toolbar_main_style",
"Main Toolbar style",
"Main Toolbar style",
&prefs.gui_toolbar_main_style, gui_toolbar_style, FALSE);
prefs_register_enum_preference(gui_module, "toolbar_filter_style",
"Filter Toolbar style",
"Filter Toolbar style",
&prefs.gui_toolbar_filter_style, gui_toolbar_style, FALSE);
register_string_like_preference(gui_module, "webbrowser", "The path to the webbrowser",
"The path to the webbrowser (Ex: mozilla)",
&prefs.gui_webbrowser, PREF_STRING, NULL, TRUE);
prefs_register_bool_preference(gui_module, "update.enabled",
"Check for updates",
"Check for updates (Windows only)",
&prefs.gui_update_enabled);
prefs_register_enum_preference(gui_module, "update.channel",
"Update channel",
"The type of update to fetch. You should probably leave this set to UPDATE_CHANNEL_STABLE.",
(gint*)(void*)(&prefs.gui_update_channel), gui_update_channel, FALSE);
prefs_register_uint_preference(gui_module, "update.interval",
"How often to check for software updates",
"How often to check for software updates in seconds",
10,
&prefs.gui_update_interval);
register_string_like_preference(gui_module, "window_title", "Custom window title",
"Custom window title to be appended to the existing title\n%P = profile name\n%V = version info",
&prefs.gui_window_title, PREF_STRING, NULL, TRUE);
register_string_like_preference(gui_module, "prepend_window_title", "Custom window title prefix",
"Custom window title to be prepended to the existing title\n%P = profile name\n%V = version info",
&prefs.gui_prepend_window_title, PREF_STRING, NULL, TRUE);
register_string_like_preference(gui_module, "start_title", "Custom start page title",
"Custom start page title",
&prefs.gui_start_title, PREF_STRING, NULL, TRUE);
prefs_register_enum_preference(gui_module, "version_placement",
"Show version in the start page and/or main screen's title bar",
"Show version in the start page and/or main screen's title bar",
(gint*)(void*)(&prefs.gui_version_placement), gui_version_placement_type, FALSE);
prefs_register_bool_preference(gui_module, "auto_scroll_on_expand",
"Automatically scroll the recently expanded item",
"Automatically scroll the recently expanded item",
&prefs.gui_auto_scroll_on_expand);
prefs_register_uint_preference(gui_module, "auto_scroll_percentage",
"The percentage down the view the recently expanded item should be scrolled",
"The percentage down the view the recently expanded item should be scrolled",
10,
&prefs.gui_auto_scroll_percentage);
gui_layout_module = prefs_register_subtree(gui_module, "Layout", "Layout", gui_layout_callback);
prefs_register_uint_preference(gui_layout_module, "layout_type",
"Layout type",
"Layout type (1-6)",
10,
(guint*)(void*)(&prefs.gui_layout_type));
prefs_register_enum_preference(gui_layout_module, "layout_content_1",
"Layout content of the pane 1",
"Layout content of the pane 1",
(gint*)(void*)(&prefs.gui_layout_content_1), gui_layout_content, FALSE);
prefs_register_enum_preference(gui_layout_module, "layout_content_2",
"Layout content of the pane 2",
"Layout content of the pane 2",
(gint*)(void*)(&prefs.gui_layout_content_2), gui_layout_content, FALSE);
prefs_register_enum_preference(gui_layout_module, "layout_content_3",
"Layout content of the pane 3",
"Layout content of the pane 3",
(gint*)(void*)(&prefs.gui_layout_content_3), gui_layout_content, FALSE);
prefs_register_bool_preference(gui_layout_module, "packet_list_separator.enabled",
"Enable Packet List Separator",
"Enable Packet List Separator",
&prefs.gui_qt_packet_list_separator);
prefs_register_bool_preference(gui_module, "packet_editor.enabled",
"Enable Packet Editor",
"Enable Packet Editor (Experimental)",
&prefs.gui_packet_editor);
prefs_register_enum_preference(gui_module, "packet_list_elide_mode",
"Elide mode",
"The position of \"...\" in packet list text.",
(gint*)(void*)(&prefs.gui_packet_list_elide_mode), gui_packet_list_elide_mode, FALSE);
prefs_register_bool_preference(gui_layout_module, "packet_list_show_related",
"Show Related Packets",
"Show related packet indicators in the first column",
&prefs.gui_packet_list_show_related);
prefs_register_bool_preference(gui_layout_module, "packet_list_show_minimap",
"Enable Intelligent Scroll Bar",
"Show the intelligent scroll bar (a minimap of packet list colors in the scrollbar)",
&prefs.gui_packet_list_show_minimap);
console_module = prefs_register_module(NULL, "console", "Console",
"CONSOLE", NULL, FALSE);
custom_cbs.free_cb = custom_pref_no_cb;
custom_cbs.reset_cb = console_log_level_reset_cb;
custom_cbs.set_cb = console_log_level_set_cb;
custom_cbs.type_name_cb = console_log_level_type_name_cb;
custom_cbs.type_description_cb = console_log_level_type_description_cb;
custom_cbs.is_default_cb = console_log_level_is_default_cb;
custom_cbs.to_str_cb = console_log_level_to_str_cb;
prefs_register_uint_custom_preference(console_module, "log.level", "logging level",
"A bitmask of glib log levels", &custom_cbs, &prefs.console_log_level);
capture_module = prefs_register_module(NULL, "capture", "Capture",
"CAPTURE", NULL, FALSE);
register_string_like_preference(capture_module, "device", "Default capture device",
"Default capture device",
&prefs.capture_device, PREF_STRING, NULL, FALSE);
register_string_like_preference(capture_module, "devices_linktypes", "Interface link-layer header type",
"Interface link-layer header types (Ex: en0(1),en1(143),...)",
&prefs.capture_devices_linktypes, PREF_STRING, NULL, FALSE);
register_string_like_preference(capture_module, "devices_descr", "Interface descriptions",
"Interface descriptions (Ex: eth0(eth0 descr),eth1(eth1 descr),...)",
&prefs.capture_devices_descr, PREF_STRING, NULL, FALSE);
register_string_like_preference(capture_module, "devices_hide", "Hide interface",
"Hide interface? (Ex: eth0,eth3,...)",
&prefs.capture_devices_hide, PREF_STRING, NULL, FALSE);
register_string_like_preference(capture_module, "devices_monitor_mode", "Capture in monitor mode",
"By default, capture in monitor mode on interface? (Ex: eth0,eth3,...)",
&prefs.capture_devices_monitor_mode, PREF_STRING, NULL, FALSE);
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
register_string_like_preference(capture_module, "devices_buffersize", "Interface buffer size",
"Interface buffer size (Ex: en0(1),en1(143),...)",
&prefs.capture_devices_buffersize, PREF_STRING, NULL, FALSE);
#endif
register_string_like_preference(capture_module, "devices_snaplen", "Interface snap length",
"Interface snap length (Ex: en0(65535),en1(1430),...)",
&prefs.capture_devices_snaplen, PREF_STRING, NULL, FALSE);
register_string_like_preference(capture_module, "devices_pmode", "Interface promiscuous mode",
"Interface promiscuous mode (Ex: en0(0),en1(1),...)",
&prefs.capture_devices_pmode, PREF_STRING, NULL, FALSE);
prefs_register_bool_preference(capture_module, "prom_mode", "Capture in promiscuous mode",
"Capture in promiscuous mode?", &prefs.capture_prom_mode);
register_string_like_preference(capture_module, "devices_filter", "Interface capture filter",
"Interface capture filter (Ex: en0(tcp),en1(udp),...)",
&prefs.capture_devices_filter, PREF_STRING, NULL, FALSE);
prefs_register_bool_preference(capture_module, "pcap_ng", "Capture in Pcap-NG format",
"Capture in Pcap-NG format?", &prefs.capture_pcap_ng);
prefs_register_bool_preference(capture_module, "real_time_update", "Update packet list in real time during capture",
"Update packet list in real time during capture?", &prefs.capture_real_time);
prefs_register_bool_preference(capture_module, "auto_scroll", "Scroll packet list during capture",
"Scroll packet list during capture?", &prefs.capture_auto_scroll);
prefs_register_bool_preference(capture_module, "show_info", "Show capture info dialog while capturing",
"Show capture info dialog while capturing?", &prefs.capture_show_info);
prefs_register_obsolete_preference(capture_module, "syntax_check_filter");
custom_cbs.free_cb = capture_column_free_cb;
custom_cbs.reset_cb = capture_column_reset_cb;
custom_cbs.set_cb = capture_column_set_cb;
custom_cbs.type_name_cb = capture_column_type_name_cb;
custom_cbs.type_description_cb = capture_column_type_description_cb;
custom_cbs.is_default_cb = capture_column_is_default_cb;
custom_cbs.to_str_cb = capture_column_to_str_cb;
prefs_register_list_custom_preference(capture_module, "columns", "Capture options dialog column list",
"List of columns to be displayed", &custom_cbs, capture_column_init_cb, &prefs.capture_columns);
nameres_module = prefs_register_module(NULL, "nameres", "Name Resolution",
"Name Resolution", NULL, TRUE);
addr_resolve_pref_init(nameres_module);
oid_pref_init(nameres_module);
#ifdef HAVE_GEOIP
geoip_db_pref_init(nameres_module);
#endif
printing = prefs_register_module(NULL, "print", "Printing",
"Printing", NULL, TRUE);
prefs_register_enum_preference(printing, "format",
"Format", "Can be one of \"text\" or \"postscript\"",
&prefs.pr_format, print_format_vals, TRUE);
prefs_register_enum_preference(printing, "destination",
"Print to", "Can be one of \"command\" or \"file\"",
&prefs.pr_dest, print_dest_vals, TRUE);
#ifndef _WIN32
register_string_like_preference(printing, "command", "Command",
"Output gets piped to this command when the destination is set to \"command\"",
&prefs.pr_cmd, PREF_STRING, NULL, TRUE);
#endif
register_string_like_preference(printing, "file", "File",
"This is the file that gets written to when the destination is set to \"file\"",
&prefs.pr_file, PREF_FILENAME, NULL, TRUE);
stats_module = prefs_register_module(NULL, "statistics", "Statistics",
"Statistics", &stats_callback, TRUE);
prefs_register_uint_preference(stats_module, "update_interval",
"Tap update interval in ms",
"Determines time between tap updates",
10,
&prefs.tap_update_interval);
#ifdef HAVE_LIBPORTAUDIO
prefs_register_uint_preference(stats_module, "rtp_player_max_visible",
"Max visible channels in RTP Player",
"Determines maximum height of RTP Player window",
10,
&prefs.rtp_player_max_visible);
#endif
prefs_register_bool_preference(stats_module, "st_enable_burstinfo",
"Enable the calculation of burst information",
"If enabled burst rates will be calcuted for statistics that use the stats_tree system. "
"Burst rates are calculated over a much shorter time interval than the rate column.",
&prefs.st_enable_burstinfo);
prefs_register_bool_preference(stats_module, "st_burst_showcount",
"Show burst count for item rather than rate",
"If selected the stats_tree statistics nodes will show the count of events "
"within the burst window instead of a burst rate. Burst rate is calculated "
"as number of events within burst window divided by the burst windown length.",
&prefs.st_burst_showcount);
prefs_register_uint_preference(stats_module, "st_burst_resolution",
"Burst rate resolution (ms)",
"Sets the duration of the time interval into which events are grouped when calculating "
"the burst rate. Higher resolution (smaller number) increases processing overhead.",
10,&prefs.st_burst_resolution);
prefs_register_uint_preference(stats_module, "st_burst_windowlen",
"Burst rate window size (ms)",
"Sets the duration of the sliding window during which the burst rate is "
"measured. Longer window relative to burst rate resolution increases "
"processing overhead. Will be truncated to a multiple of burst resolution.",
10,&prefs.st_burst_windowlen);
prefs_register_enum_preference(stats_module, "st_sort_defcolflag",
"Default sort column for stats_tree stats",
"Sets the default column by which stats based on the stats_tree "
"system is sorted.",
&prefs.st_sort_defcolflag, st_sort_col_vals, FALSE);
prefs_register_bool_preference(stats_module, "st_sort_defdescending",
"Default stats_tree sort order is descending",
"When selected, statistics based on the stats_tree system will by default "
"be sorted in descending order.",
&prefs.st_sort_defdescending);
prefs_register_bool_preference(stats_module, "st_sort_casesensitve",
"Case sensitive sort of stats_tree item names",
"When selected, the item/node names of statistics based on the stats_tree "
"system will be sorted taking case into account. Else the case of the name "
"will be ignored.",
&prefs.st_sort_casesensitve);
prefs_register_bool_preference(stats_module, "st_sort_rng_nameonly",
"Always sort 'range' nodes by name",
"When selected, the stats_tree nodes representing a range of values "
"(0-49, 50-100, etc.) will always be sorted by name (the range of the "
"node). Else range nodes are sorted by the same column as the rest of "
" the tree.",
&prefs.st_sort_rng_nameonly);
prefs_register_bool_preference(stats_module, "st_sort_rng_fixorder",
"Always sort 'range' nodes in ascending order",
"When selected, the stats_tree nodes representing a range of values "
"(0-49, 50-100, etc.) will always be sorted ascending; else it follows "
"the sort direction of the tree. Only effective if \"Always sort "
"'range' nodes by name\" is also selected.",
&prefs.st_sort_rng_fixorder);
prefs_register_bool_preference(stats_module, "st_sort_showfullname",
"Display the full stats_tree plug-in name",
"When selected, the full name (including menu path) of the stats_tree "
"plug-in is show in windows. If cleared the plug-in name is shown "
"without menu path (only the part of the name after last '/' character.)",
&prefs.st_sort_showfullname);
protocols_module = prefs_register_module(NULL, "protocols", "Protocols",
"Protocols", NULL, TRUE);
prefs_register_bool_preference(protocols_module, "display_hidden_proto_items",
"Display hidden protocol items",
"Display all hidden protocol items in the packet list.",
&prefs.display_hidden_proto_items);
prefs_register_bool_preference(protocols_module, "display_byte_fields_with_spaces",
"Display byte fields with a space character between bytes",
"Display all byte fields with a space character between each byte in the packet list.",
&prefs.display_byte_fields_with_spaces);
prefs_register_bool_preference(protocols_module, "enable_incomplete_dissectors_check",
"Look for incomplete dissectors",
"Look for dissectors that left some bytes undecoded.",
&prefs.enable_incomplete_dissectors_check);
prefs_register_module(NULL, "taps", "TAPS", "TAPS", NULL, FALSE);
prefs_register_module(NULL, "packet_list", "PACKET_LIST", "PACKET_LIST", NULL, FALSE);
prefs_register_module(NULL, "stream", "STREAM", "STREAM", NULL, FALSE);
}
GList *
prefs_get_string_list(const gchar *str)
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
} else if (!g_ascii_isspace(cur_c) || state != PRE_STRING) {
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
char *join_string_list(GList *sl)
{
GString *joined_str = g_string_new("");
GList *cur, *first;
gchar *str;
gchar *quoted_str;
guint item_count = 0;
cur = first = g_list_first(sl);
while (cur) {
item_count++;
str = (gchar *)cur->data;
if (cur != first)
g_string_append_c(joined_str, ',');
if (item_count % 2) {
g_string_append(joined_str, "\n\t");
} else
g_string_append_c(joined_str, ' ');
quoted_str = g_strescape(str, "");
g_string_append_printf(joined_str, "\"%s\"", quoted_str);
g_free(quoted_str);
cur = cur->next;
}
return g_string_free(joined_str, FALSE);
}
void
prefs_clear_string_list(GList *sl)
{
g_list_foreach(sl, (GFunc)g_free, NULL);
g_list_free(sl);
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
static gboolean
is_deprecated_column_format(const gchar* fmt)
{
guint haystack_idx;
for (haystack_idx = 0;
haystack_idx < G_N_ELEMENTS(migrated_columns);
++haystack_idx) {
if (strcmp(migrated_columns[haystack_idx].col_fmt, fmt) == 0) {
return TRUE;
}
}
return FALSE;
}
static gboolean
parse_column_format(fmt_data *cfmt, const char *fmt)
{
const gchar *cust_format = col_format_to_string(COL_CUSTOM);
size_t cust_format_len = strlen(cust_format);
gchar **cust_format_info;
char *p;
int col_fmt;
gchar *col_custom_fields = NULL;
long col_custom_occurrence = 0;
gboolean col_resolved = TRUE;
if ((strlen(fmt) > cust_format_len) && (fmt[cust_format_len] == ':') &&
strncmp(fmt, cust_format, cust_format_len) == 0) {
col_fmt = COL_CUSTOM;
cust_format_info = g_strsplit(&fmt[cust_format_len+1],":",3);
col_custom_fields = g_strdup(cust_format_info[0]);
if (col_custom_fields && cust_format_info[1]) {
col_custom_occurrence = strtol(cust_format_info[1], &p, 10);
if (p == cust_format_info[1] || *p != '\0') {
g_free(col_custom_fields);
g_strfreev(cust_format_info);
return FALSE;
}
}
if (col_custom_fields && cust_format_info[1] && cust_format_info[2]) {
col_resolved = (cust_format_info[2][0] == 'U') ? FALSE : TRUE;
}
g_strfreev(cust_format_info);
} else {
col_fmt = get_column_format_from_str(fmt);
if ((col_fmt == -1) && (!is_deprecated_column_format(fmt)))
return FALSE;
}
cfmt->fmt = col_fmt;
cfmt->custom_fields = col_custom_fields;
cfmt->custom_occurrence = (int)col_custom_occurrence;
cfmt->resolved = col_resolved;
return TRUE;
}
static void
init_prefs(void)
{
if (prefs_initialized)
return;
uat_load_all();
pre_init_prefs();
prefs_register_modules();
filter_expression_init();
prefs_initialized = TRUE;
}
static void
pre_init_prefs(void)
{
int i;
gchar *col_name;
fmt_data *cfmt;
static const gchar *col_fmt[DEF_NUM_COLS*2] = {
"No.", "%m", "Time", "%t",
"Source", "%s", "Destination", "%d",
"Protocol", "%p", "Length", "%L",
"Info", "%i"};
prefs.pr_format = PR_FMT_TEXT;
prefs.pr_dest = PR_DEST_CMD;
if (prefs.pr_file) g_free(prefs.pr_file);
prefs.pr_file = g_strdup("wireshark.out");
if (prefs.pr_cmd) g_free(prefs.pr_cmd);
prefs.pr_cmd = g_strdup("lpr");
prefs.gui_altern_colors = FALSE;
prefs.gui_expert_composite_eyecandy = FALSE;
prefs.gui_ptree_line_style = 0;
prefs.gui_ptree_expander_style = 1;
prefs.gui_hex_dump_highlight_style = 1;
prefs.filter_toolbar_show_in_statusbar = FALSE;
prefs.gui_toolbar_main_style = TB_STYLE_ICONS;
prefs.gui_toolbar_filter_style = TB_STYLE_TEXT;
if (prefs.gui_gtk2_font_name) g_free(prefs.gui_gtk2_font_name);
#ifdef _WIN32
prefs.gui_gtk2_font_name = g_strdup("Lucida Console 10");
#else
prefs.gui_gtk2_font_name = g_strdup("Monospace 10");
#endif
if (prefs.gui_qt_font_name) g_free(prefs.gui_qt_font_name);
prefs.gui_qt_font_name = g_strdup("");
prefs.gui_marked_fg.red = 65535;
prefs.gui_marked_fg.green = 65535;
prefs.gui_marked_fg.blue = 65535;
prefs.gui_marked_bg.red = 0;
prefs.gui_marked_bg.green = 8224;
prefs.gui_marked_bg.blue = 10794;
prefs.gui_ignored_fg.red = 32767;
prefs.gui_ignored_fg.green = 32767;
prefs.gui_ignored_fg.blue = 32767;
prefs.gui_ignored_bg.red = 65535;
prefs.gui_ignored_bg.green = 65535;
prefs.gui_ignored_bg.blue = 65535;
if (prefs.gui_colorized_fg) g_free(prefs.gui_colorized_fg);
prefs.gui_colorized_fg = g_strdup("000000,000000,000000,000000,000000,000000,000000,000000,000000,000000");
if (prefs.gui_colorized_bg) g_free(prefs.gui_colorized_bg);
prefs.gui_colorized_bg = g_strdup("ffc0c0,ffc0ff,e0c0e0,c0c0ff,c0e0e0,c0ffff,c0ffc0,ffffc0,e0e0c0,e0e0e0");
prefs.st_client_fg.red = 32767;
prefs.st_client_fg.green = 0;
prefs.st_client_fg.blue = 0;
prefs.st_client_bg.red = 64507;
prefs.st_client_bg.green = 60909;
prefs.st_client_bg.blue = 60909;
prefs.st_server_fg.red = 0;
prefs.st_server_fg.green = 0;
prefs.st_server_fg.blue = 32767;
prefs.st_server_bg.red = 60909;
prefs.st_server_bg.green = 60909;
prefs.st_server_bg.blue = 64507;
prefs.gui_text_valid.red = 0xAFFF;
prefs.gui_text_valid.green = 0xFFFF;
prefs.gui_text_valid.blue = 0xAFFF;
prefs.gui_text_invalid.red = 0xFFFF;
prefs.gui_text_invalid.green = 0xAFFF;
prefs.gui_text_invalid.blue = 0xAFFF;
prefs.gui_text_deprecated.red = 0xFFFF;
prefs.gui_text_deprecated.green = 0xFFFF;
prefs.gui_text_deprecated.blue = 0xAFFF;
prefs.gui_geometry_save_position = TRUE;
prefs.gui_geometry_save_size = TRUE;
prefs.gui_geometry_save_maximized= TRUE;
prefs.gui_macosx_style = TRUE;
prefs.gui_console_open = console_open_never;
prefs.gui_fileopen_style = FO_STYLE_LAST_OPENED;
prefs.gui_recent_df_entries_max = 10;
prefs.gui_recent_files_count_max = 10;
if (prefs.gui_fileopen_dir) g_free(prefs.gui_fileopen_dir);
prefs.gui_fileopen_dir = g_strdup(get_persdatafile_dir());
prefs.gui_fileopen_preview = 3;
prefs.gui_ask_unsaved = TRUE;
prefs.gui_find_wrap = TRUE;
prefs.gui_use_pref_save = FALSE;
prefs.gui_update_enabled = TRUE;
prefs.gui_update_channel = UPDATE_CHANNEL_STABLE;
prefs.gui_update_interval = 60*60*24;
if (prefs.gui_webbrowser) g_free(prefs.gui_webbrowser);
prefs.gui_webbrowser = g_strdup("");
if (prefs.gui_window_title) g_free(prefs.gui_window_title);
prefs.gui_window_title = g_strdup("");
if (prefs.gui_prepend_window_title) g_free(prefs.gui_prepend_window_title);
prefs.gui_prepend_window_title = g_strdup("");
if (prefs.gui_start_title) g_free(prefs.gui_start_title);
prefs.gui_start_title = g_strdup("The World's Most Popular Network Protocol Analyzer");
prefs.gui_version_placement = version_both;
prefs.gui_auto_scroll_on_expand = FALSE;
prefs.gui_auto_scroll_percentage = 0;
prefs.gui_layout_type = layout_type_5;
prefs.gui_layout_content_1 = layout_pane_content_plist;
prefs.gui_layout_content_2 = layout_pane_content_pdetails;
prefs.gui_layout_content_3 = layout_pane_content_pbytes;
prefs.gui_packet_editor = FALSE;
prefs.gui_packet_list_elide_mode = ELIDE_RIGHT;
prefs.gui_packet_list_show_related = TRUE;
prefs.gui_packet_list_show_minimap = TRUE;
prefs.gui_qt_packet_list_separator = FALSE;
if (prefs.col_list) {
free_col_info(prefs.col_list);
prefs.col_list = NULL;
}
for (i = 0; i < DEF_NUM_COLS; i++) {
cfmt = g_new(fmt_data,1);
cfmt->title = g_strdup(col_fmt[i * 2]);
parse_column_format(cfmt, col_fmt[(i * 2) + 1]);
cfmt->visible = TRUE;
cfmt->resolved = TRUE;
cfmt->custom_fields = NULL;
cfmt->custom_occurrence = 0;
prefs.col_list = g_list_append(prefs.col_list, cfmt);
}
prefs.num_cols = DEF_NUM_COLS;
prefs.capture_prom_mode = TRUE;
#ifdef PCAP_NG_DEFAULT
prefs.capture_pcap_ng = TRUE;
#else
prefs.capture_pcap_ng = FALSE;
#endif
prefs.capture_real_time = TRUE;
prefs.capture_auto_scroll = TRUE;
prefs.capture_show_info = FALSE;
if (!prefs.capture_columns) {
for (i = 0; i < num_capture_cols; i++) {
col_name = g_strdup(capture_cols[i]);
prefs.capture_columns = g_list_append(prefs.capture_columns, col_name);
}
}
prefs.console_log_level =
G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_ERROR;
prefs.tap_update_interval = TAP_UPDATE_DEFAULT_INTERVAL;
prefs.rtp_player_max_visible = RTP_PLAYER_DEFAULT_VISIBLE;
prefs.st_enable_burstinfo = TRUE;
prefs.st_burst_showcount = FALSE;
prefs.st_burst_resolution = ST_DEF_BURSTRES;
prefs.st_burst_windowlen = ST_DEF_BURSTLEN;
prefs.st_sort_casesensitve = TRUE;
prefs.st_sort_rng_fixorder = TRUE;
prefs.st_sort_rng_nameonly = TRUE;
prefs.st_sort_defcolflag = ST_SORT_COL_COUNT;
prefs.st_sort_defdescending = TRUE;
prefs.st_sort_showfullname = FALSE;
prefs.display_hidden_proto_items = FALSE;
prefs.display_byte_fields_with_spaces = FALSE;
}
static void
reset_pref(pref_t *pref)
{
int type;
if (!pref) return;
type = pref->type;
if (IS_PREF_OBSOLETE(type))
return;
else
RESET_PREF_OBSOLETE(type);
switch (type) {
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
case PREF_DIRNAME:
reset_string_like_preference(pref);
break;
case PREF_RANGE:
g_free(*pref->varp.range);
*pref->varp.range = range_copy(pref->default_val.range);
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_COLOR:
*pref->varp.colorp = pref->default_val.color;
break;
case PREF_CUSTOM:
pref->custom_cbs.reset_cb(pref);
break;
}
}
static void
reset_pref_cb(gpointer data, gpointer user_data _U_)
{
pref_t *pref = (pref_t *) data;
reset_pref(pref);
}
static gboolean
reset_module_prefs(const void *key _U_, void *value, void *data _U_)
{
reset_pref_arg_t arg;
arg.module = (module_t *)value;
g_list_foreach(arg.module->prefs, reset_pref_cb, &arg);
return FALSE;
}
void
prefs_reset(void)
{
prefs_initialized = FALSE;
g_free(prefs.saved_at_version);
prefs.saved_at_version = NULL;
uat_unload_all();
oids_cleanup();
filter_expression_free(*pfilter_expression_head);
*pfilter_expression_head = NULL;
init_prefs();
wmem_tree_foreach(prefs_modules, reset_module_prefs, NULL);
}
e_prefs *
read_prefs(int *gpf_errno_return, int *gpf_read_errno_return,
char **gpf_path_return, int *pf_errno_return,
int *pf_read_errno_return, char **pf_path_return)
{
int err;
char *pf_path;
FILE *pf;
oids_cleanup();
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
pf_path = get_persconffile_path(PF_NAME, TRUE);
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
oids_init();
return &prefs;
}
int
read_prefs_file(const char *pf_path, FILE *pf,
pref_set_pair_cb pref_set_pair_fct, void *private_data)
{
enum {
START,
IN_VAR,
PRE_VAL,
IN_VAL,
IN_SKIP
} state = START;
int got_c;
GString *cur_val;
GString *cur_var;
gboolean got_val = FALSE;
gint fline = 1, pline = 1;
gchar hint[] = "(save preferences to remove this warning)";
gchar ver[128];
cur_val = g_string_new("");
cur_var = g_string_new("");
if (fscanf(pf, "# Configuration file for %127[^\r\n]", ver) == 1) {
g_free(prefs.saved_at_version);
prefs.saved_at_version = g_strndup(ver, strlen(ver) - 1);
}
rewind(pf);
while ((got_c = getc(pf)) != EOF) {
if (got_c == '\r') {
got_c = getc(pf);
if (got_c == EOF)
break;
if (got_c != '\n') {
ungetc(got_c, pf);
got_c = '\r';
}
}
if (got_c == '\n') {
state = START;
fline++;
continue;
}
switch (state) {
case START:
if (g_ascii_isalnum(got_c)) {
if (cur_var->len > 0) {
if (got_val) {
if (cur_val->len > 0) {
if (cur_val->str[cur_val->len-1] == ',') {
cur_val->str[cur_val->len-1] = '\0';
g_warning ("%s line %d: trailing comma in \"%s\" %s", pf_path, pline, cur_var->str, hint);
}
}
switch (pref_set_pair_fct(cur_var->str, cur_val->str, private_data, FALSE)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
g_warning ("Syntax error in preference \"%s\" at line %d of\n%s %s",
cur_var->str, pline, pf_path, hint);
break;
case PREFS_SET_NO_SUCH_PREF:
if (strcmp(cur_var->str, "print.command") != 0)
g_warning ("No such preference \"%s\" at line %d of\n%s %s",
cur_var->str, pline, pf_path, hint);
prefs.unknown_prefs = TRUE;
break;
case PREFS_SET_OBSOLETE:
if (strcmp(cur_var->str, "print.command") != 0)
g_warning ("Obsolete preference \"%s\" at line %d of\n%s %s",
cur_var->str, pline, pf_path, hint);
prefs.unknown_prefs = TRUE;
break;
}
} else {
g_warning ("Incomplete preference at line %d: of\n%s %s", pline, pf_path, hint);
}
}
state = IN_VAR;
got_val = FALSE;
g_string_truncate(cur_var, 0);
g_string_append_c(cur_var, (gchar) got_c);
pline = fline;
} else if (g_ascii_isspace(got_c) && cur_var->len > 0 && got_val) {
state = PRE_VAL;
} else if (got_c == '#') {
state = IN_SKIP;
} else {
g_warning ("Malformed preference at line %d of\n%s %s", fline, pf_path, hint);
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
if (!g_ascii_isspace(got_c)) {
state = IN_VAL;
g_string_append_c(cur_val, (gchar) got_c);
}
break;
case IN_VAL:
g_string_append_c(cur_val, (gchar) got_c);
break;
case IN_SKIP:
break;
}
}
if (cur_var->len > 0) {
if (got_val) {
switch (pref_set_pair_fct(cur_var->str, cur_val->str, private_data, FALSE)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
g_warning ("Syntax error in preference %s at line %d of\n%s %s",
cur_var->str, pline, pf_path, hint);
break;
case PREFS_SET_NO_SUCH_PREF:
g_warning ("No such preference \"%s\" at line %d of\n%s %s",
cur_var->str, pline, pf_path, hint);
prefs.unknown_prefs = TRUE;
break;
case PREFS_SET_OBSOLETE:
prefs.unknown_prefs = TRUE;
break;
}
} else {
g_warning ("Incomplete preference at line %d of\n%s %s",
pline, pf_path, hint);
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
gchar *err = NULL;
gboolean ret;
colonp = strchr(uat_entry, ':');
if (colonp == NULL)
return FALSE;
p = colonp;
*p++ = '\0';
while (g_ascii_isspace(*p))
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
ret = uat_load_str(uat, p, &err);
g_free(err);
return ret;
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
while (g_ascii_isspace(*p))
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
g_free(cfmt_hidden.custom_fields);
cfmt_hidden.custom_fields = NULL;
continue;
}
if (cfmt->fmt == COL_CUSTOM) {
if (cfmt_hidden.custom_fields && cfmt->custom_fields) {
if (strcmp(cfmt->custom_fields,
cfmt_hidden.custom_fields) != 0) {
g_free(cfmt_hidden.custom_fields);
cfmt_hidden.custom_fields = NULL;
continue;
}
if (cfmt->custom_occurrence != cfmt_hidden.custom_occurrence) {
g_free(cfmt_hidden.custom_fields);
cfmt_hidden.custom_fields = NULL;
continue;
}
}
}
g_free(cfmt_hidden.custom_fields);
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
gboolean
prefs_capture_options_dialog_column_is_visible(const gchar *column)
{
GList *curr;
gchar *col;
for (curr = g_list_first(prefs.capture_columns); curr; curr = g_list_next(curr)) {
col = (gchar *)curr->data;
if (col && (g_ascii_strcasecmp(col, column) == 0)) {
return TRUE;
}
}
return FALSE;
}
char
string_to_name_resolve(const char *string, e_addr_resolve *name_resolve)
{
char c;
memset(name_resolve, 0, sizeof(e_addr_resolve));
while ((c = *string++) != '\0') {
switch (c) {
case 'm':
name_resolve->mac_name = TRUE;
break;
case 'n':
name_resolve->network_name = TRUE;
break;
case 'N':
name_resolve->use_external_net_name_resolver = TRUE;
break;
case 't':
name_resolve->transport_name = TRUE;
break;
case 'C':
break;
case 'd':
name_resolve->dns_pkt_addr_resolution = TRUE;
break;
case 'v':
name_resolve->vlan_name = TRUE;
break;
default:
return c;
}
}
return '\0';
}
static void
try_convert_to_custom_column(gpointer *el_data)
{
guint haystack_idx;
gchar **fmt = (gchar **) el_data;
for (haystack_idx = 0;
haystack_idx < G_N_ELEMENTS(migrated_columns);
++haystack_idx) {
if (strcmp(migrated_columns[haystack_idx].col_fmt, *fmt) == 0) {
gchar *cust_col = g_strdup_printf("%%Cus:%s:0",
migrated_columns[haystack_idx].col_expr);
g_free(*fmt);
*fmt = cust_col;
}
}
}
static gboolean
deprecated_heur_dissector_pref(gchar *pref_name, const gchar *value)
{
struct heur_pref_name
{
const char* pref_name;
const char* short_name;
gboolean more_dissectors;
};
struct heur_pref_name heur_prefs[] = {
{"acn.heuristic_acn", "acn_udp", 0},
{"bfcp.enable", "bfcp_tcp", 1},
{"bfcp.enable", "bfcp_udp", 0},
{"bt-dht.enable", "bittorrent_dht_udp", 0},
{"bt-utp.enable", "bt_utp_udp", 0},
{"cattp.enable", "cattp_udp", 0},
{"cfp.enable", "fp_eth", 0},
{"dicom.heuristic", "dicom_tcp", 0},
{"dnp3.heuristics", "dnp3_tcp", 1},
{"dnp3.heuristics", "dnp3_udp", 0},
{"dvb-s2_modeadapt.enable", "dvb_s2_udp", 0},
{"esl.enable", "esl_eth", 0},
{"fp.udp_heur", "fp_udp", 0},
{"gvsp.enable_heuristic", "gvsp_udp", 0},
{"hdcp2.enable", "hdcp2_tcp", 0},
{"hislip.enable_heuristic", "hislip_tcp", 0},
{"jxta.udp.heuristic", "jxta_udp", 0},
{"jxta.tcp.heuristic", "jxta_tcp", 0},
{"jxta.sctp.heuristic", "jxta_sctp", 0},
{"mac-lte.heuristic_mac_lte_over_udp", "mac_lte_udp", 0},
{"mbim.bulk_heuristic", "mbim_usb_bulk", 0},
{"norm.heuristic_norm", "rmt_norm_udp", 0},
{"openflow.heuristic", "openflow_tcp", 0},
{"pdcp-lte.heuristic_pdcp_lte_over_udp", "pdcp_lte_udp", 0},
{"rlc.heuristic_rlc_over_udp", "rlc_udp", 0},
{"rlc-lte.heuristic_rlc_lte_over_udp", "rlc_lte_udp", 0},
{"rtcp.heuristic_rtcp", "rtcp_udp", 1},
{"rtcp.heuristic_rtcp", "rtcp_stun", 0},
{"rtp.heuristic_rtp", "rtp_udp", 1},
{"rtp.heuristic_rtp", "rtp_stun", 0},
{"teredo.heuristic_teredo", "teredo_udp", 0},
{"vssmonitoring.use_heuristics", "vssmonitoring_eth", 0},
{"xml.heuristic", "xml_http", 1},
{"xml.heuristic", "xml_sip", 1},
{"xml.heuristic", "xml_media", 0},
{"xml.heuristic_tcp", "xml_tcp", 0},
{"xml.heuristic_udp", "xml_udp", 0},
};
unsigned int i;
heur_dtbl_entry_t* heuristic;
for (i = 0; i < sizeof(heur_prefs)/sizeof(struct heur_pref_name); i++)
{
if (strcmp(pref_name, heur_prefs[i].pref_name) == 0)
{
heuristic = find_heur_dissector_by_unique_short_name(heur_prefs[i].short_name);
if (heuristic != NULL) {
heuristic->enabled = ((g_ascii_strcasecmp(value, "true") == 0) ? TRUE : FALSE);
}
if (!heur_prefs[i].more_dissectors)
return TRUE;
}
}
return FALSE;
}
static prefs_set_pref_e
set_pref(gchar *pref_name, const gchar *value, void *private_data _U_,
gboolean return_range_errors)
{
unsigned long int cval;
guint uval;
gboolean bval;
gint enum_val;
char *p;
gchar *dotp, *last_dotp;
static gchar *filter_label = NULL;
static gboolean filter_enabled = FALSE;
gchar *filter_expr = NULL;
module_t *module, *containing_module;
pref_t *pref;
int type;
if (strcmp(pref_name, PRS_GUI_FILTER_LABEL) == 0) {
filter_label = g_strdup(value);
} else if (strcmp(pref_name, PRS_GUI_FILTER_ENABLED) == 0) {
filter_enabled = (strcmp(value, "TRUE") == 0) ? TRUE : FALSE;
} else if (strcmp(pref_name, PRS_GUI_FILTER_EXPR) == 0) {
filter_expr = g_strdup(value);
filter_expression_new(filter_label, filter_expr, filter_enabled);
g_free(filter_label);
g_free(filter_expr);
} else if (strcmp(pref_name, "gui.version_in_start_page") == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
prefs.gui_version_placement = version_both;
} else {
prefs.gui_version_placement = version_neither;
}
} else if (strcmp(pref_name, "name_resolve") == 0 ||
strcmp(pref_name, "capture.name_resolve") == 0) {
if (g_ascii_strcasecmp(value, "true") == 0) {
gbl_resolv_flags.mac_name = TRUE;
gbl_resolv_flags.network_name = TRUE;
gbl_resolv_flags.transport_name = TRUE;
}
else if (g_ascii_strcasecmp(value, "false") == 0) {
disable_name_resolution();
}
else {
disable_name_resolution();
if (string_to_name_resolve(value, &gbl_resolv_flags) != '\0')
return PREFS_SET_SYNTAX_ERR;
}
} else if (deprecated_heur_dissector_pref(pref_name, value)) {
} else {
if ((strcmp(pref_name, "name_resolve_concurrency") == 0) ||
(strcmp(pref_name, "name_resolve_load_smi_modules") == 0) ||
(strcmp(pref_name, "name_resolve_suppress_smi_errors") == 0)) {
module = nameres_module;
dotp = pref_name;
} else {
module = NULL;
last_dotp = pref_name;
while (!module) {
dotp = strchr(last_dotp, '.');
if (dotp == NULL) {
return PREFS_SET_NO_SUCH_PREF;
}
*dotp = '\0';
module = prefs_find_module(pref_name);
if (module == NULL) {
if (strcmp(pref_name, "column") == 0)
module = gui_column_module;
else if (strcmp(pref_name, "Diameter") == 0)
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
strcmp(pref_name, "isup_thin") == 0) {
return PREFS_SET_OBSOLETE;
}
if (module) {
g_warning ("Preference \"%s.%s\" has been converted to \"%s.%s.%s\"\n"
"Save your preferences to make this change permanent.",
pref_name, dotp+1, module->parent->name, pref_name, dotp+1);
prefs.unknown_prefs = TRUE;
}
}
*dotp = '.';
dotp++;
last_dotp = dotp;
}
}
containing_module = module;
pref = prefs_find_preference_with_submodule(module, dotp, &containing_module);
if (pref == NULL) {
prefs.unknown_prefs = TRUE;
if ((strcmp(pref_name, PRS_COL_HIDDEN) == 0) ||
(strcmp(pref_name, PRS_COL_FMT) == 0)) {
pref = prefs_find_preference(module, pref_name);
}
else if (strcmp(module->name, "mgcp") == 0) {
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
if (new_module) {
if (strcmp(dotp, "port_number_udh_means_wsp") == 0) {
pref = prefs_find_preference(new_module, "port_number_udh_means_wsp");
containing_module = new_module;
} else if (strcmp(dotp, "try_dissect_1st_fragment") == 0) {
pref = prefs_find_preference(new_module, "try_dissect_1st_fragment");
containing_module = new_module;
}
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
if (new_module) {
pref = prefs_find_preference(new_module, "qinq_ethertype");
containing_module = new_module;
}
}
} else if (strcmp(module->name, "taps") == 0) {
if (strcmp(dotp, "update_interval") == 0 ||
strcmp(dotp, "rtp_player_max_visible") == 0)
pref = prefs_find_preference(stats_module, dotp);
} else if (strcmp(module->name, "packet_list") == 0) {
if (strcmp(dotp, "display_hidden_proto_items") == 0)
pref = prefs_find_preference(protocols_module, dotp);
} else if (strcmp(module->name, "stream") == 0) {
if ((strcmp(dotp, "client.fg") == 0) ||
(strcmp(dotp, "client.bg") == 0) ||
(strcmp(dotp, "server.fg") == 0) ||
(strcmp(dotp, "server.bg") == 0))
pref = prefs_find_preference(gui_color_module, pref_name);
} else if (strcmp(module->name, "nameres") == 0) {
if (strcmp(pref_name, "name_resolve_concurrency") == 0) {
pref = prefs_find_preference(nameres_module, pref_name);
} else if (strcmp(pref_name, "name_resolve_load_smi_modules") == 0) {
pref = prefs_find_preference(nameres_module, "load_smi_modules");
} else if (strcmp(pref_name, "name_resolve_suppress_smi_errors") == 0) {
pref = prefs_find_preference(nameres_module, "suppress_smi_errors");
}
}
}
if (pref == NULL)
return PREFS_SET_NO_SUCH_PREF;
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
return PREFS_SET_OBSOLETE;
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_UINT:
uval = (guint)strtoul(value, &p, pref->info.base);
if (p == value || *p != '\0')
return PREFS_SET_SYNTAX_ERR;
if (*pref->varp.uint != uval) {
containing_module->prefs_changed = TRUE;
*pref->varp.uint = uval;
}
break;
case PREF_BOOL:
if (g_ascii_strcasecmp(value, "true") == 0)
bval = TRUE;
else
bval = FALSE;
if (*pref->varp.boolp != bval) {
containing_module->prefs_changed = TRUE;
*pref->varp.boolp = bval;
}
break;
case PREF_ENUM:
enum_val = find_val_for_string(value, pref->info.enum_info.enumvals,
*pref->varp.enump);
if (*pref->varp.enump != enum_val) {
containing_module->prefs_changed = TRUE;
*pref->varp.enump = enum_val;
}
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
prefs_set_string_like_value(pref, value, &containing_module->prefs_changed);
break;
case PREF_RANGE:
{
if (!prefs_set_range_value_work(pref, value, return_range_errors,
&containing_module->prefs_changed))
return PREFS_SET_SYNTAX_ERR;
break;
}
case PREF_COLOR:
{
cval = strtoul(value, NULL, 16);
if ((pref->varp.colorp->red != RED_COMPONENT(cval)) ||
(pref->varp.colorp->green != GREEN_COMPONENT(cval)) ||
(pref->varp.colorp->blue != BLUE_COMPONENT(cval))) {
containing_module->prefs_changed = TRUE;
pref->varp.colorp->red = RED_COMPONENT(cval);
pref->varp.colorp->green = GREEN_COMPONENT(cval);
pref->varp.colorp->blue = BLUE_COMPONENT(cval);
}
break;
}
case PREF_CUSTOM:
return pref->custom_cbs.set_cb(pref, value, &containing_module->prefs_changed);
case PREF_STATIC_TEXT:
case PREF_UAT:
{
break;
}
}
}
return PREFS_SET_OK;
}
const char *
prefs_pref_type_name(pref_t *pref)
{
const char *type_name = "[Unknown]";
int type;
if (!pref) {
return type_name;
}
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
type_name = "Obsolete";
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_UINT:
switch (pref->info.base) {
case 10:
type_name = "Decimal";
break;
case 8:
type_name = "Octal";
break;
case 16:
type_name = "Hexadecimal";
break;
}
break;
case PREF_BOOL:
type_name = "Boolean";
break;
case PREF_ENUM:
type_name = "Choice";
break;
case PREF_STRING:
type_name = "String";
break;
case PREF_FILENAME:
type_name = "Filename";
break;
case PREF_DIRNAME:
type_name = "Directory";
break;
case PREF_RANGE:
type_name = "Range";
break;
case PREF_COLOR:
type_name = "Color";
break;
case PREF_CUSTOM:
if (pref->custom_cbs.type_name_cb)
return pref->custom_cbs.type_name_cb();
type_name = "Custom";
break;
case PREF_STATIC_TEXT:
type_name = "Static text";
break;
case PREF_UAT:
type_name = "UAT";
break;
}
return type_name;
}
char *
prefs_pref_type_description(pref_t *pref)
{
const char *type_desc = "An unknown preference type";
int type;
if (!pref) {
return g_strdup_printf("%s.", type_desc);
}
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
type_desc = "An obsolete preference";
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_UINT:
switch (pref->info.base) {
case 10:
type_desc = "A decimal number";
break;
case 8:
type_desc = "An octal number";
break;
case 16:
type_desc = "A hexadecimal number";
break;
}
break;
case PREF_BOOL:
type_desc = "TRUE or FALSE (case-insensitive)";
break;
case PREF_ENUM:
{
const enum_val_t *enum_valp = pref->info.enum_info.enumvals;
GString *enum_str = g_string_new("One of: ");
while (enum_valp->name != NULL) {
g_string_append(enum_str, enum_valp->description);
enum_valp++;
if (enum_valp->name != NULL)
g_string_append(enum_str, ", ");
}
g_string_append(enum_str, "\n(case-insensitive).");
return g_string_free(enum_str, FALSE);
break;
}
case PREF_STRING:
type_desc = "A string";
break;
case PREF_FILENAME:
type_desc = "A path to a file";
break;
case PREF_DIRNAME:
type_desc = "A path to a directory";
break;
case PREF_RANGE:
{
type_desc = "A string denoting an positive integer range (e.g., \"1-20,30-40\")";
break;
}
case PREF_COLOR:
{
type_desc = "A six-digit hexadecimal RGB color triplet (e.g. fce94f)";
break;
}
case PREF_CUSTOM:
if (pref->custom_cbs.type_description_cb)
return pref->custom_cbs.type_description_cb();
type_desc = "A custom value";
break;
case PREF_STATIC_TEXT:
type_desc = "[Static text]";
break;
case PREF_UAT:
type_desc = "Configuration data stored in its own file";
break;
default:
break;
}
return g_strdup(type_desc);
}
static gboolean
prefs_pref_is_default(pref_t *pref)
{
int type;
if (!pref) return FALSE;
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
return FALSE;
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_UINT:
if (pref->default_val.uint == *pref->varp.uint)
return TRUE;
break;
case PREF_BOOL:
if (pref->default_val.boolval == *pref->varp.boolp)
return TRUE;
break;
case PREF_ENUM:
if (pref->default_val.enumval == *pref->varp.enump)
return TRUE;
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
if (!(g_strcmp0(pref->default_val.string, *pref->varp.string)))
return TRUE;
break;
case PREF_RANGE:
{
if ((ranges_are_equal(pref->default_val.range, *pref->varp.range)))
return TRUE;
break;
}
case PREF_COLOR:
{
if ((pref->default_val.color.red == pref->varp.colorp->red) &&
(pref->default_val.color.green == pref->varp.colorp->green) &&
(pref->default_val.color.blue == pref->varp.colorp->blue))
return TRUE;
break;
}
case PREF_CUSTOM:
return pref->custom_cbs.is_default_cb(pref);
case PREF_STATIC_TEXT:
case PREF_UAT:
return FALSE;
break;
}
return FALSE;
}
char *
prefs_pref_to_str(pref_t *pref, pref_source_t source) {
const char *pref_text = "[Unknown]";
void *valp;
color_t *pref_color;
gchar *tmp_value, *ret_value;
int type;
if (!pref) {
return g_strdup(pref_text);
}
switch (source) {
case pref_default:
valp = &pref->default_val;
pref_color = &pref->default_val.color;
break;
case pref_stashed:
valp = &pref->stashed_val;
pref_color = &pref->stashed_val.color;
break;
case pref_current:
valp = pref->varp.uint;
pref_color = pref->varp.colorp;
break;
default:
return g_strdup(pref_text);
}
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
pref_text = "[Obsolete]";
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_UINT:
{
guint pref_uint = *(guint *) valp;
switch (pref->info.base) {
case 10:
return g_strdup_printf("%u", pref_uint);
case 8:
return g_strdup_printf("%#o", pref_uint);
case 16:
return g_strdup_printf("%#x", pref_uint);
}
break;
}
case PREF_BOOL:
return g_strdup((*(gboolean *) valp) ? "TRUE" : "FALSE");
case PREF_ENUM:
{
gint pref_enumval = *(gint *) valp;
const enum_val_t *enum_valp = pref->info.enum_info.enumvals;
while (enum_valp->name != NULL) {
if (enum_valp->value == pref_enumval)
return g_strdup(enum_valp->description);
enum_valp++;
}
break;
}
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
return g_strdup(*(const char **) valp);
case PREF_RANGE:
tmp_value = range_convert_range(NULL, *(range_t **) valp);
ret_value = g_strdup(tmp_value);
wmem_free(NULL, tmp_value);
return ret_value;
case PREF_COLOR:
return g_strdup_printf("%02x%02x%02x",
(pref_color->red * 255 / 65535),
(pref_color->green * 255 / 65535),
(pref_color->blue * 255 / 65535));
case PREF_CUSTOM:
if (pref->custom_cbs.to_str_cb)
return pref->custom_cbs.to_str_cb(pref, source == pref_default ? TRUE : FALSE);
pref_text = "[Custom]";
break;
case PREF_STATIC_TEXT:
pref_text = "[Static text]";
break;
case PREF_UAT:
{
uat_t *uat = pref->varp.uat;
if (uat && uat->filename)
return g_strdup_printf("[Managed in the file \"%s\"]", uat->filename);
else
pref_text = "[Managed in an unknown file]";
break;
}
default:
break;
}
return g_strdup(pref_text);
}
static void
write_pref(gpointer data, gpointer user_data)
{
pref_t *pref = (pref_t *)data;
write_pref_arg_t *arg = (write_pref_arg_t *)user_data;
gchar **desc_lines;
int i;
int type;
type = pref->type;
if (IS_PREF_OBSOLETE(type)) {
return;
} else {
RESET_PREF_OBSOLETE(type);
}
switch (type) {
case PREF_STATIC_TEXT:
case PREF_UAT:
return;
default:
break;
}
if (pref->type != PREF_CUSTOM || pref->custom_cbs.type_name_cb() != NULL) {
const char *name_prefix = (arg->module->name != NULL) ? arg->module->name : arg->module->parent->name;
char *type_desc, *pref_text;
const char * def_prefix = prefs_pref_is_default(pref) ? "#" : "";
if (pref->type == PREF_CUSTOM) fprintf(arg->pf, "\n# %s", pref->custom_cbs.type_name_cb());
fprintf(arg->pf, "\n");
if (pref->description &&
(g_ascii_strncasecmp(pref->description,"", 2) != 0)) {
if (pref->type != PREF_CUSTOM) {
desc_lines = g_strsplit(pref->description,"\n",0);
for (i = 0; desc_lines[i] != NULL; ++i) {
fprintf(arg->pf, "# %s\n", desc_lines[i]);
}
g_strfreev(desc_lines);
}
} else {
fprintf(arg->pf, "# No description\n");
}
type_desc = prefs_pref_type_description(pref);
desc_lines = g_strsplit(type_desc,"\n",0);
for (i = 0; desc_lines[i] != NULL; ++i) {
fprintf(arg->pf, "# %s\n", desc_lines[i]);
}
g_strfreev(desc_lines);
g_free(type_desc);
pref_text = prefs_pref_to_str(pref, pref_current);
fprintf(arg->pf, "%s%s.%s: ", def_prefix, name_prefix, pref->name);
desc_lines = g_strsplit(pref_text,"\n",0);
for (i = 0; desc_lines[i] != NULL; ++i) {
fprintf(arg->pf, "%s%s\n", i == 0 ? "" : def_prefix, desc_lines[i]);
}
if (i == 0) fprintf(arg->pf, "\n");
g_strfreev(desc_lines);
g_free(pref_text);
}
}
static guint
write_module_prefs(module_t *module, gpointer user_data)
{
write_gui_pref_arg_t *gui_pref_arg = (write_gui_pref_arg_t*)user_data;
write_pref_arg_t arg;
if ((module == gui_module) && (gui_pref_arg->is_gui_module != TRUE))
return 0;
if (((module->parent == NULL) || (module->parent == gui_module)) &&
((prefs_module_has_submodules(module)) ||
(module->numprefs > 0) ||
(module->name == NULL))) {
if ((module->name == NULL) && (module->parent != NULL)) {
fprintf(gui_pref_arg->pf, "\n####### %s: %s ########\n", module->parent->title, module->title);
} else {
fprintf(gui_pref_arg->pf, "\n####### %s ########\n", module->title);
}
}
arg.module = module;
arg.pf = gui_pref_arg->pf;
g_list_foreach(arg.module->prefs, write_pref, &arg);
if (prefs_module_has_submodules(module))
return prefs_modules_foreach_submodules(module, write_module_prefs, user_data);
return 0;
}
int
write_prefs(char **pf_path_return)
{
char *pf_path;
FILE *pf;
write_gui_pref_arg_t write_gui_pref_info;
init_prefs();
if (pf_path_return != NULL) {
pf_path = get_persconffile_path(PF_NAME, TRUE);
if ((pf = ws_fopen(pf_path, "w")) == NULL) {
*pf_path_return = pf_path;
return errno;
}
g_free(pf_path);
} else {
pf = stdout;
}
fputs("# Configuration file for Wireshark " VERSION ".\n"
"#\n"
"# This file is regenerated each time preferences are saved within\n"
"# Wireshark. Making manual changes should be safe, however.\n"
"# Preferences that have been commented out have not been\n"
"# changed from their default value.\n", pf);
write_gui_pref_info.pf = pf;
write_gui_pref_info.is_gui_module = TRUE;
write_module_prefs(gui_module, &write_gui_pref_info);
{
struct filter_expression *fe = *(struct filter_expression **)prefs.filter_expressions;
if (fe != NULL)
fprintf(pf, "\n####### Filter Expressions ########\n\n");
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
write_gui_pref_info.is_gui_module = FALSE;
prefs_modules_foreach_submodules(NULL, write_module_prefs, &write_gui_pref_info);
fclose(pf);
return 0;
}
static void
free_col_info(GList *list)
{
fmt_data *cfmt;
GList *list_head = list;
while (list != NULL) {
cfmt = (fmt_data *)list->data;
g_free(cfmt->title);
g_free(cfmt->custom_fields);
g_free(cfmt);
list = g_list_next(list);
}
g_list_free(list_head);
}
