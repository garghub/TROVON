guint
pref_stash(pref_t *pref, gpointer unused _U_)
{
switch (pref->type) {
case PREF_UINT:
pref->stashed_val.uint = *pref->varp.uint;
break;
case PREF_BOOL:
pref->stashed_val.boolval = *pref->varp.boolp;
break;
case PREF_ENUM:
pref->stashed_val.enumval = *pref->varp.enump;
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
g_free(pref->stashed_val.string);
pref->stashed_val.string = g_strdup(*pref->varp.string);
break;
case PREF_RANGE:
g_free(pref->stashed_val.range);
pref->stashed_val.range = range_copy(*pref->varp.range);
break;
case PREF_COLOR:
pref->stashed_val.color = *pref->varp.colorp;
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
case PREF_CUSTOM:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
guint
pref_unstash(pref_t *pref, gpointer changed_p)
{
gboolean *pref_changed_p = (gboolean *)changed_p;
switch (pref->type) {
case PREF_UINT:
if (*pref->varp.uint != pref->stashed_val.uint) {
*pref_changed_p = TRUE;
*pref->varp.uint = pref->stashed_val.uint;
}
break;
case PREF_BOOL:
if (*pref->varp.boolp != pref->stashed_val.boolval) {
*pref_changed_p = TRUE;
*pref->varp.boolp = pref->stashed_val.boolval;
}
break;
case PREF_ENUM:
if (*pref->varp.enump != pref->stashed_val.enumval) {
*pref_changed_p = TRUE;
*pref->varp.enump = pref->stashed_val.enumval;
}
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
if (strcmp(*pref->varp.string, pref->stashed_val.string) != 0) {
*pref_changed_p = TRUE;
g_free(*pref->varp.string);
*pref->varp.string = g_strdup(pref->stashed_val.string);
}
break;
case PREF_RANGE:
if (!ranges_are_equal(*pref->varp.range, pref->stashed_val.range)) {
*pref_changed_p = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = range_copy(pref->stashed_val.range);
}
break;
case PREF_COLOR:
*pref->varp.colorp = pref->stashed_val.color;
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
case PREF_CUSTOM:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
void
reset_stashed_pref(pref_t *pref) {
switch (pref->type) {
case PREF_UINT:
pref->stashed_val.uint = pref->default_val.uint;
break;
case PREF_BOOL:
pref->stashed_val.boolval = pref->default_val.boolval;
break;
case PREF_ENUM:
pref->stashed_val.enumval = pref->default_val.enumval;
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
g_free(pref->stashed_val.string);
pref->stashed_val.string = g_strdup(pref->default_val.string);
break;
case PREF_RANGE:
g_free(pref->stashed_val.range);
pref->stashed_val.range = range_copy(pref->default_val.range);
break;
case PREF_COLOR:
memcpy(&pref->stashed_val.color, &pref->default_val.color, sizeof(color_t));
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
case PREF_CUSTOM:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
}
guint
pref_clean_stash(pref_t *pref, gpointer unused _U_)
{
switch (pref->type) {
case PREF_UINT:
break;
case PREF_BOOL:
break;
case PREF_ENUM:
break;
case PREF_STRING:
case PREF_FILENAME:
case PREF_DIRNAME:
if (pref->stashed_val.string != NULL) {
g_free(pref->stashed_val.string);
pref->stashed_val.string = NULL;
}
break;
case PREF_RANGE:
if (pref->stashed_val.range != NULL) {
g_free(pref->stashed_val.range);
pref->stashed_val.range = NULL;
}
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
case PREF_COLOR:
case PREF_CUSTOM:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
void
prefs_to_capture_opts(void)
{
#ifdef HAVE_LIBPCAP
global_capture_opts.default_options.promisc_mode = prefs.capture_prom_mode;
global_capture_opts.use_pcapng = prefs.capture_pcap_ng;
global_capture_opts.show_info = prefs.capture_show_info;
global_capture_opts.real_time_mode = prefs.capture_real_time;
auto_scroll_live = prefs.capture_auto_scroll;
#endif
}
void
prefs_main_write(void)
{
int err;
char *pf_dir_path;
char *pf_path;
if (create_persconffile_dir(&pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\"\nfor preferences file: %s.", pf_dir_path,
g_strerror(errno));
g_free(pf_dir_path);
} else {
err = write_prefs(&pf_path);
if (err != 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't open preferences file\n\"%s\": %s.", pf_path,
g_strerror(err));
g_free(pf_path);
}
}
}
static gboolean
prefs_store_ext_helper(const char * module_name, const char *pref_name, const char *pref_value)
{
module_t * module = NULL;
pref_t * pref = NULL;
gboolean pref_changed = TRUE;
if ( ! prefs_is_registered_protocol(module_name))
return FALSE;
module = prefs_find_module(module_name);
if ( ! module )
return FALSE;
pref = prefs_find_preference(module, pref_name);
if (!pref)
return FALSE;
if ( pref->type == PREF_STRING )
{
g_free((void *)pref->stashed_val.string);
pref->stashed_val.string = (gchar *) g_strdup(pref_value);
if (strcmp(*pref->varp.string, pref->stashed_val.string) != 0)
{
pref_changed = TRUE;
g_free(*pref->varp.string);
*pref->varp.string = g_strdup(pref->stashed_val.string);
}
}
return pref_changed;
}
gboolean
prefs_store_ext(const char * module_name, const char *pref_name, const char *pref_value)
{
if ( prefs_store_ext_helper(module_name, pref_name, pref_value) )
{
prefs_main_write();
prefs_apply_all();
prefs_to_capture_opts();
return TRUE;
}
return FALSE;
}
gboolean
prefs_store_ext_multiple(const char * module, GHashTable * pref_values)
{
gboolean pref_changed = FALSE;
GList * keys = NULL;
if ( ! prefs_is_registered_protocol(module))
return pref_changed;
keys = g_hash_table_get_keys(pref_values);
if ( ! keys )
return pref_changed;
while ( keys != NULL )
{
gchar * pref_name = (gchar *)keys->data;
gchar * pref_value = (gchar *) g_hash_table_lookup(pref_values, keys->data);
if ( pref_name && pref_value )
{
if ( prefs_store_ext_helper(module, pref_name, pref_value) )
pref_changed = TRUE;
}
keys = g_list_next(keys);
}
if ( pref_changed )
{
prefs_main_write();
prefs_apply_all();
prefs_to_capture_opts();
}
return TRUE;
}
gint
column_prefs_add_custom(gint fmt, const gchar *title, const gchar *custom_fields, gint custom_occurrence)
{
GList *clp;
fmt_data *cfmt, *last_cfmt;
gint colnr;
cfmt = (fmt_data *) g_malloc(sizeof(fmt_data));
cfmt->title = g_strdup(title);
cfmt->fmt = fmt;
cfmt->custom_fields = g_strdup(custom_fields);
cfmt->custom_occurrence = custom_occurrence;
cfmt->resolved = TRUE;
colnr = g_list_length(prefs.col_list);
if (custom_fields) {
cfmt->visible = TRUE;
clp = g_list_last(prefs.col_list);
last_cfmt = (fmt_data *) clp->data;
if (last_cfmt->fmt == COL_INFO) {
colnr -= 1;
prefs.col_list = g_list_insert(prefs.col_list, cfmt, colnr);
} else {
prefs.col_list = g_list_append(prefs.col_list, cfmt);
}
} else {
cfmt->visible = FALSE;
prefs.col_list = g_list_append(prefs.col_list, cfmt);
}
return colnr;
}
void
column_prefs_remove_link(GList *col_link)
{
fmt_data *cfmt;
if (!col_link || !col_link->data) return;
cfmt = (fmt_data *) col_link->data;
g_free(cfmt->title);
g_free(cfmt->custom_fields);
g_free(cfmt);
prefs.col_list = g_list_remove_link(prefs.col_list, col_link);
}
void
column_prefs_remove_nth(gint col)
{
column_prefs_remove_link(g_list_nth(prefs.col_list, col));
}
