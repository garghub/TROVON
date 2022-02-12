void decode_as_init(void) {
decode_dcerpc_init();
}
static void
decode_build_reset_list (const gchar *table_name, ftenum_t selector_type,
gpointer key, gpointer value _U_,
gpointer user_data _U_)
{
dissector_delete_item_t *item;
item = g_new(dissector_delete_item_t,1);
item->ddi_table_name = table_name;
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
item->ddi_selector.sel_string = (char *)key;
break;
default:
g_assert_not_reached();
}
dissector_reset_list = g_slist_prepend(dissector_reset_list, item);
}
void change_dissector_if_matched(gpointer item, gpointer user_data) {
dissector_handle_t handle = (dissector_handle_t)item;
lookup_entry_t * lookup = (lookup_entry_t *)user_data;
if (strcmp(lookup->dissector_short_name, dissector_handle_get_short_name(handle)) == 0) {
lookup->handle = handle;
}
}
prefs_set_pref_e
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
lookup.dissector_short_name = values[3];
lookup.handle = NULL;
g_slist_foreach(sub_dissectors->dissector_handles, change_dissector_if_matched, &lookup);
if (lookup.handle != NULL) {
dissector_change_uint(values[0], atoi(values[1]), lookup.handle);
decode_build_reset_list(g_strdup(values[0]), sub_dissectors->type, g_strdup(values[1]), NULL, NULL);
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
void write_da_entry(gpointer item, gpointer user_data) {
da_entry_t *entry = (da_entry_t *)item;
FILE *daf = (FILE *)user_data;
fprintf (daf, DECODE_AS_ENTRY ": %s,%d,%s,%s\n", entry->table, entry->selector, entry->initial, entry->current);
}
void free_da_entry(gpointer item, gpointer user_data _U_) {
da_entry_t *entry = (da_entry_t *)item;
g_free(entry->table);
g_free(entry->initial);
g_free(entry->current);
}
static gint
sort_iter_compare_func (GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
gint sortcol = GPOINTER_TO_INT(user_data);
gint ret = 0;
switch (sortcol)
{
case SORT_ALPHABETICAL:
{
gchar *name1, *name2;
gtk_tree_model_get(model, a, 0, &name1, -1);
gtk_tree_model_get(model, b, 0, &name2, -1);
if (name1 == NULL || name2 == NULL)
{
if (name1 == NULL && name2 == NULL)
break;
ret = (name1 == NULL) ? -1 : 1;
}
else
{
ret = g_ascii_strcasecmp(name1,name2);
}
g_free(name1);
g_free(name2);
}
break;
default:
g_return_val_if_reached(0);
}
return ret;
}
void
decode_add_to_show_list (gpointer list_data,
const gchar *table_name,
gchar *selector_name,
const gchar *initial_proto_name,
const gchar *current_proto_name)
{
const gchar *text[E_LIST_D_COLUMNS];
GtkListStore *store;
GtkTreeIter iter;
store = (GtkListStore *)list_data;
text[E_LIST_D_TABLE] = table_name;
text[E_LIST_D_SELECTOR] = selector_name;
text[E_LIST_D_INITIAL] = initial_proto_name;
text[E_LIST_D_CURRENT] = current_proto_name;
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, E_LIST_D_TABLE, text[E_LIST_D_TABLE],
E_LIST_D_SELECTOR, text[E_LIST_D_SELECTOR],
E_LIST_D_INITIAL, text[E_LIST_D_INITIAL],
E_LIST_D_CURRENT, text[E_LIST_D_CURRENT], -1);
}
static void
decode_build_show_list (const gchar *table_name, ftenum_t selector_type,
gpointer key, gpointer value, gpointer user_data)
{
dissector_handle_t current, initial;
const gchar *current_proto_name, *initial_proto_name;
gchar *selector_name;
gchar string1[20];
da_entry_t *entry;
entry = g_new(da_entry_t,1);
g_assert(user_data);
g_assert(value);
current = (dissector_handle_t)dtbl_entry_get_handle((dtbl_entry_t *)value);
if (current == NULL)
current_proto_name = "(none)";
else
current_proto_name = dissector_handle_get_short_name(current);
initial = (dissector_handle_t)dtbl_entry_get_initial_handle((dtbl_entry_t *)value);
if (initial == NULL)
initial_proto_name = "(none)";
else
initial_proto_name = dissector_handle_get_short_name(initial);
switch (selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
switch (get_dissector_table_base(table_name)) {
case BASE_DEC:
g_snprintf(string1, sizeof(string1), "%u", GPOINTER_TO_UINT(key));
break;
case BASE_HEX:
switch (get_dissector_table_selector_type(table_name)) {
case FT_UINT8:
g_snprintf(string1, sizeof(string1), "0x%02x", GPOINTER_TO_UINT(key));
break;
case FT_UINT16:
g_snprintf(string1, sizeof(string1), "0x%04x", GPOINTER_TO_UINT(key));
break;
case FT_UINT24:
g_snprintf(string1, sizeof(string1), "0x%06x", GPOINTER_TO_UINT(key));
break;
case FT_UINT32:
g_snprintf(string1, sizeof(string1), "0x%08x", GPOINTER_TO_UINT(key));
break;
default:
g_assert_not_reached();
break;
}
break;
case BASE_OCT:
g_snprintf(string1, sizeof(string1), "%#o", GPOINTER_TO_UINT(key));
break;
}
selector_name = string1;
break;
case FT_STRING:
case FT_STRINGZ:
selector_name = (gchar *)key;
break;
default:
g_assert_not_reached();
selector_name = NULL;
break;
}
decode_add_to_show_list (
user_data,
get_dissector_table_ui_name(table_name),
selector_name,
initial_proto_name,
current_proto_name);
entry->table = g_strdup(table_name);
entry->selector = GPOINTER_TO_UINT(key);
entry->initial = g_strdup(initial_proto_name);
entry->current = g_strdup(current_proto_name);
da_entries = g_slist_append(da_entries, entry);
}
static void
decode_clear_all(gboolean redissect)
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
dissector_reset_string(item->ddi_table_name,
item->ddi_selector.sel_string);
break;
default:
g_assert_not_reached();
}
g_free(item);
}
g_slist_free(dissector_reset_list);
dissector_reset_list = NULL;
decode_dcerpc_reset_all();
if (redissect) {
redissect_packets();
redissect_all_packet_windows();
}
}
static void
decode_show_ok_cb (GtkWidget *ok_bt _U_, gpointer parent_w)
{
window_destroy(GTK_WIDGET(parent_w));
}
static void
decode_show_clear_cb (GtkWidget *clear_bt _U_, gpointer parent_w)
{
decode_clear_all(TRUE);
window_destroy(GTK_WIDGET(parent_w));
decode_show_cb(NULL, NULL);
}
static gboolean
decode_show_delete_cb (GtkWidget *win _U_, GdkEvent *event _U_, gpointer user_data _U_)
{
decode_show_ok_cb(NULL, decode_show_w);
return FALSE;
}
static void
decode_show_destroy_cb (GtkWidget *win _U_, gpointer user_data _U_)
{
decode_show_w = NULL;
g_slist_foreach(da_entries, free_da_entry, NULL);
g_slist_free(da_entries);
da_entries = NULL;
}
void
decode_show_save_cb (GtkWidget *win _U_, gpointer user_data _U_)
{
char *pf_dir_path;
char *daf_path;
FILE *daf;
if (create_persconffile_dir(&pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\"\nfor recent file: %s.", pf_dir_path,
g_strerror(errno));
g_free(pf_dir_path);
return;
}
daf_path = get_persconffile_path(DECODE_AS_ENTRIES_FILE_NAME, TRUE);
if ((daf = ws_fopen(daf_path, "w")) == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't open decode_as_entries file\n\"%s\": %s.", daf_path,
g_strerror(errno));
g_free(daf_path);
return;
}
fputs("# \"Decode As\" entries file for Wireshark " VERSION ".\n"
"#\n"
"# This file is regenerated when saving the \"Decode As...\" list.\n"
"# So be careful, if you want to make manual changes here.\n"
"\n"
"######## Decode As table entries, can be altered through command line ########\n"
"\n", daf);
g_slist_foreach(da_entries, write_da_entry, daf);
fclose(daf);
}
void
decode_show_cb (GtkWidget *w _U_, gpointer user_data _U_)
{
GtkWidget *main_vb, *bbox, *ok_bt, *clear_bt, *save_bt, *help_bt, *scrolled_window;
const gchar *titles[E_LIST_D_COLUMNS] = {
"Table", "Value", "Initial", "Current"
};
gint column;
GtkListStore *store;
GtkTreeView *list;
GtkCellRenderer *renderer;
GtkTreeViewColumn *tc;
GtkTreeIter iter;
if (decode_show_w != NULL) {
reactivate_window(decode_show_w);
return;
}
decode_show_w = dlg_window_new("Wireshark: Decode As: Show");
gtk_window_set_default_size(GTK_WINDOW(decode_show_w), -1, E_DECODE_MIN_HEIGHT);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(decode_show_w), main_vb);
store = gtk_list_store_new(E_LIST_D_COLUMNS, G_TYPE_STRING,
G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
list = GTK_TREE_VIEW(tree_view_new(GTK_TREE_MODEL(store)));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list), FALSE);
gtk_tree_selection_set_mode(gtk_tree_view_get_selection(list),
GTK_SELECTION_NONE);
for (column = 0; column < E_LIST_D_COLUMNS; column++) {
renderer = gtk_cell_renderer_text_new();
tc = gtk_tree_view_column_new_with_attributes(titles[column],
renderer, "text",
column, NULL);
gtk_tree_view_column_set_sizing(tc, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_column_set_resizable(tc, TRUE);
gtk_tree_view_append_column(list, tc);
}
dissector_all_tables_foreach_changed(decode_build_show_list, store);
g_object_unref(G_OBJECT(store));
decode_dcerpc_add_show_list(store);
scrolled_window = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(scrolled_window),
GTK_WIDGET(list));
gtk_box_pack_start(GTK_BOX(main_vb), scrolled_window, TRUE, TRUE, 0);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CLEAR, GTK_STOCK_SAVE, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(decode_show_ok_cb), decode_show_w);
clear_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLEAR);
g_signal_connect(clear_bt, "clicked", G_CALLBACK(decode_show_clear_cb), decode_show_w);
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(decode_show_save_cb), decode_show_w);
help_bt =(GtkWidget *) g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_DECODE_AS_SHOW_DIALOG);
window_set_cancel_button(decode_show_w, ok_bt, NULL);
g_signal_connect(decode_show_w, "delete_event", G_CALLBACK(decode_show_delete_cb), NULL);
g_signal_connect(decode_show_w, "destroy", G_CALLBACK(decode_show_destroy_cb), NULL);
gtk_widget_set_sensitive(clear_bt,
gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter));
gtk_widget_show_all(decode_show_w);
window_present(decode_show_w);
}
static void
decode_change_one_dissector(gchar *table_name, guint selector, GtkWidget *list)
{
dissector_handle_t handle;
gchar *abbrev;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
guint *selector_type;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
if (gtk_tree_selection_get_selected(selection, &model, &iter) == FALSE)
{
abbrev = NULL;
handle = NULL;
} else {
gtk_tree_model_get(model, &iter, E_LIST_S_PROTO_NAME, &abbrev,
E_LIST_S_TABLE+1, &handle, -1);
}
if (abbrev != NULL && strcmp(abbrev, "(default)") == 0) {
dissector_reset_uint(table_name, selector);
} else {
dissector_change_uint(table_name, selector, handle);
}
selector_type = g_new(guint,1);
*selector_type = selector;
decode_build_reset_list(g_strdup(table_name), FT_UINT32, selector_type, NULL, NULL);
g_free(abbrev);
}
static void
decode_debug (GtkTreeView *tree_view, gchar *leadin)
{
GtkListStore *store;
GtkTreeSelection *selection;
GtkTreeIter iter;
char *string, *text[E_LIST_S_COLUMNS];
dissector_handle_t handle;
selection = gtk_tree_view_get_selection(tree_view);
if (gtk_tree_selection_get_selected(selection, NULL, &iter)){
store = GTK_LIST_STORE(gtk_tree_view_get_model(tree_view));
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
E_LIST_S_PROTO_NAME, &text[E_LIST_S_PROTO_NAME],
E_LIST_S_TABLE, &text[E_LIST_S_TABLE],
E_LIST_S_TABLE+1, &handle,
-1);
string = g_strdup_printf("%s list: <put handle here>, name %s, table %s",
leadin, text[E_LIST_S_PROTO_NAME],
text[E_LIST_S_TABLE]);
} else {
string = g_strdup_printf("%s list row (none), aka do not decode", leadin);
}
simple_dialog(ESD_TYPE_INFO, ESD_BTN_OK, string);
g_free(string);
}
static void
decode_simple (GtkWidget *notebook_pg)
{
GtkWidget *list;
#ifdef DEBUG
gchar *string;
#endif
gchar *table_name;
guint value;
list = (GtkWidget *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_LIST);
if (requested_action == E_DECODE_NO)
gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)));
#ifdef DEBUG
string = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TITLE);
decode_debug(GTK_TREE_VIEW(list), string);
#endif
table_name = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TABLE);
value = GPOINTER_TO_UINT((gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_VALUE));
decode_change_one_dissector(table_name, value, list);
}
static void
decode_transport(GtkWidget *notebook_pg)
{
GtkWidget *combo_box;
GtkWidget *list;
gchar *table_name;
gint requested_srcdst, requested_port, ppid;
gpointer portp;
gpointer ptr;
#ifdef DEBUG
gchar *string;
#endif
list = (GtkWidget *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_LIST);
if (requested_action == E_DECODE_NO)
gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)));
combo_box = (GtkWidget *)g_object_get_data(G_OBJECT(notebook_pg), E_COMBO_BOX_SRCDST);
if (!ws_combo_box_get_active_pointer(GTK_COMBO_BOX(combo_box), &ptr))
g_assert_not_reached();
requested_srcdst = GPOINTER_TO_INT(ptr);
#ifdef DEBUG
string = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TITLE);
decode_debug(GTK_TREE_VIEW(list), string);
#endif
table_name = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TABLE);
if (requested_srcdst >= E_DECODE_PPID) {
if (requested_srcdst == E_DECODE_PPID)
ppid = 0;
else
if (requested_srcdst - E_DECODE_PPID - 1 < MAX_NUMBER_OF_PPIDS)
ppid = cfile.edt->pi.ppids[requested_srcdst - E_DECODE_PPID - 1];
else
return;
decode_change_one_dissector(table_name, ppid, list);
return;
}
if (requested_srcdst != E_DECODE_DPORT) {
portp = g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_SPORT);
if (portp != NULL) {
requested_port = GPOINTER_TO_INT(portp);
decode_change_one_dissector(table_name, requested_port, list);
}
}
if (requested_srcdst != E_DECODE_SPORT) {
portp = g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_DPORT);
if (portp != NULL) {
requested_port = GPOINTER_TO_INT(portp);
decode_change_one_dissector(table_name, requested_port, list);
}
}
}
static void
decode_ok_cb (GtkWidget *ok_bt _U_, gpointer parent_w)
{
GtkWidget *notebook, *notebook_pg;
void (* func)(GtkWidget *);
gint page_num;
void *binding = NULL;
notebook = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_NOTEBOOK);
page_num = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
notebook_pg = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), page_num);
func = (void (*)(GtkWidget *))g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_ACTION);
func(notebook_pg);
notebook_pg = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_PAGE_DCERPC);
if(notebook_pg) {
binding = g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_BINDING);
}
if(binding) {
decode_dcerpc_binding_free(binding);
}
window_destroy(GTK_WIDGET(parent_w));
g_slist_free(decode_dimmable);
decode_dimmable = NULL;
redissect_packets();
redissect_all_packet_windows();
}
static void
decode_apply_cb (GtkWidget *apply_bt _U_, gpointer parent_w)
{
GtkWidget *notebook, *notebook_pg;
void (* func)(GtkWidget *);
gint page_num;
notebook = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_NOTEBOOK);
page_num = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
notebook_pg = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), page_num);
func = (void (*)(GtkWidget *))g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_ACTION);
func(notebook_pg);
redissect_packets();
redissect_all_packet_windows();
}
static void
decode_close_cb (GtkWidget *close_bt _U_, gpointer parent_w)
{
GtkWidget *notebook_pg;
void *binding = NULL;
notebook_pg = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_PAGE_DCERPC);
if(notebook_pg) {
binding = g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_BINDING);
}
if(binding) {
decode_dcerpc_binding_free(binding);
}
window_destroy(GTK_WIDGET(parent_w));
g_slist_free(decode_dimmable);
decode_dimmable = NULL;
}
static gboolean
decode_delete_cb (GtkWidget *decode_w_lcl, GdkEvent *event _U_, gpointer user_data _U_)
{
decode_close_cb(NULL, decode_w_lcl);
return FALSE;
}
static void
decode_destroy_cb (GtkWidget *win _U_, gpointer user_data _U_)
{
decode_w = NULL;
}
static void
decode_clear_cb(GtkWidget *clear_bt _U_, gpointer user_data _U_)
{
decode_clear_all(TRUE);
}
static void
decode_update_action (GtkWidget *w _U_, gpointer user_data)
{
GSList *tmp;
gboolean enable;
requested_action = (enum action_type)GPOINTER_TO_INT(user_data);
enable = (requested_action == E_DECODE_YES);
for (tmp = decode_dimmable; tmp; tmp = g_slist_next(tmp)) {
gtk_widget_set_sensitive((GtkWidget *)tmp->data, enable);
}
}
static GtkWidget *
decode_add_yes_no (void)
{
GtkWidget *format_vb, *radio_button;
GSList *format_grp;
format_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
radio_button = gtk_radio_button_new_with_label(NULL, "Decode");
format_grp = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button));
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_button), TRUE);
g_signal_connect(radio_button, "clicked", G_CALLBACK(decode_update_action),
GINT_TO_POINTER(E_DECODE_YES));
gtk_box_pack_start(GTK_BOX(format_vb), radio_button, FALSE, FALSE, 0);
radio_button = gtk_radio_button_new_with_label(format_grp, "Do not decode");
g_signal_connect(radio_button, "clicked", G_CALLBACK(decode_update_action),
GINT_TO_POINTER(E_DECODE_NO));
gtk_box_pack_start(GTK_BOX(format_vb), radio_button, FALSE, FALSE, 0);
return(format_vb);
}
static GtkWidget *
decode_add_pack_combo_box (GtkWidget *combo_box)
{
GtkWidget *alignment;
alignment = gtk_alignment_new(0.0f, 0.5f, 0.0f, 0.0f);
gtk_container_add(GTK_CONTAINER(alignment), combo_box);
return(alignment);
}
static GtkWidget *
decode_add_srcdst_combo_box (GtkWidget *page)
{
GtkWidget *combo_box, *alignment;
gchar tmp[100];
combo_box = ws_combo_box_new_text_and_pointer();
g_snprintf(tmp, sizeof(tmp), "Source (%u%s)", cfile.edt->pi.srcport, UTF8_RIGHTWARDS_ARROW);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box), tmp, GINT_TO_POINTER(E_DECODE_SPORT));
g_snprintf(tmp, sizeof(tmp), "Destination (%s%u)", UTF8_RIGHTWARDS_ARROW, cfile.edt->pi.destport);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box), tmp, GINT_TO_POINTER(E_DECODE_DPORT));
g_snprintf(tmp, sizeof(tmp), "Both (%u%s%u)", cfile.edt->pi.srcport,UTF8_LEFT_RIGHT_ARROW, cfile.edt->pi.destport);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box), tmp, GINT_TO_POINTER(E_DECODE_BPORT));
ws_combo_box_set_active(GTK_COMBO_BOX(combo_box), 2);
g_object_set_data(G_OBJECT(page), E_COMBO_BOX_SRCDST, combo_box);
g_object_set_data(G_OBJECT(page), E_PAGE_SPORT, GINT_TO_POINTER(cfile.edt->pi.srcport));
g_object_set_data(G_OBJECT(page), E_PAGE_DPORT, GINT_TO_POINTER(cfile.edt->pi.destport));
alignment = decode_add_pack_combo_box(combo_box);
return(alignment);
}
static GtkWidget *
decode_add_ppid_combo_box (GtkWidget *page)
{
GtkWidget *combo_box;
gchar tmp[100];
guint number_of_ppid;
combo_box = ws_combo_box_new_text_and_pointer();
for(number_of_ppid = 0; number_of_ppid < MAX_NUMBER_OF_PPIDS; number_of_ppid++) {
if (cfile.edt->pi.ppids[number_of_ppid] != LAST_PPID) {
g_snprintf(tmp, sizeof(tmp), "PPID (%u)", cfile.edt->pi.ppids[number_of_ppid]);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(combo_box),
tmp, GINT_TO_POINTER(E_DECODE_PPID + 1 + number_of_ppid));
} else
break;
}
if (number_of_ppid)
ws_combo_box_set_active(GTK_COMBO_BOX(combo_box), 0);
g_object_set_data(G_OBJECT(page), E_COMBO_BOX_SRCDST, combo_box);
return(combo_box);
}
static gboolean
lookup_handle(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer user_data)
{
dissector_handle_t handle;
struct handle_lookup_info *hli = (struct handle_lookup_info *)user_data;
gtk_tree_model_get(model, iter, E_LIST_S_TABLE+1, &handle, -1);
if (hli->handle == handle) {
hli->found = TRUE;
return TRUE;
}
return FALSE;
}
void
decode_add_to_list (const gchar *table_name, const gchar *proto_name, gpointer value, gpointer user_data)
{
const gchar *text[E_LIST_S_COLUMNS];
GtkTreeView *list;
GtkListStore *store;
GtkTreeIter iter;
struct handle_lookup_info hli;
g_assert(user_data);
g_assert(value);
list = (GtkTreeView *)user_data;
hli.handle = (dissector_handle_t)value;
hli.found = FALSE;
store = GTK_LIST_STORE(gtk_tree_view_get_model(list));
gtk_tree_model_foreach(GTK_TREE_MODEL(store), lookup_handle, &hli);
if (hli.found) return;
text[E_LIST_S_PROTO_NAME] = proto_name;
text[E_LIST_S_TABLE] = table_name;
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
E_LIST_S_PROTO_NAME, text[E_LIST_S_PROTO_NAME],
E_LIST_S_TABLE, text[E_LIST_S_TABLE],
E_LIST_S_TABLE+1, value, -1);
}
static void
decode_proto_add_to_list (const gchar *table_name, gpointer value, gpointer user_data)
{
const gchar *proto_name;
gint i;
dissector_handle_t handle;
handle = (dissector_handle_t)value;
proto_name = dissector_handle_get_short_name(handle);
i = dissector_handle_get_protocol_index(handle);
if (i >= 0 && !proto_is_protocol_enabled(find_protocol_by_id(i)))
return;
decode_add_to_list (table_name, proto_name, value, user_data);
}
static gboolean
decode_list_button_press_cb(GtkWidget *list, GdkEventButton *event, gpointer user_data _U_)
{
if (event->type == GDK_2BUTTON_PRESS) {
GtkWidget *main_w = gtk_widget_get_toplevel(list);
decode_ok_cb (NULL, main_w);
}
return FALSE;
}
static gboolean
decode_list_key_release_cb(GtkWidget *list, GdkEventKey *event, gpointer user_data _U_)
{
if (event->keyval == GDK_Return || event->keyval == GDK_KP_Enter) {
GtkWidget *main_w = gtk_widget_get_toplevel(list);
decode_ok_cb (NULL, main_w);
}
return FALSE;
}
void
decode_list_menu_start(GtkWidget *page, GtkWidget **list_p,
GtkWidget **scrolled_win_p)
{
GtkTreeView *list;
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *tc;
GtkTreeSortable *sortable;
store = gtk_list_store_new(E_LIST_S_COLUMNS+1, G_TYPE_STRING,
G_TYPE_STRING, G_TYPE_POINTER);
g_object_set_data(G_OBJECT(decode_w), "sctp_data", store);
list = GTK_TREE_VIEW(tree_view_new(GTK_TREE_MODEL(store)));
g_object_unref(G_OBJECT(store));
sortable = GTK_TREE_SORTABLE(store);
gtk_tree_sortable_set_sort_func(sortable, SORT_ALPHABETICAL, sort_iter_compare_func, GINT_TO_POINTER(SORT_ALPHABETICAL), NULL);
gtk_tree_sortable_set_sort_column_id(sortable, SORT_ALPHABETICAL, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list, FALSE);
#ifndef DEBUG
gtk_tree_view_set_headers_visible(list, FALSE);
#endif
renderer = gtk_cell_renderer_text_new();
tc = gtk_tree_view_column_new_with_attributes("Short Name", renderer,
"text", E_LIST_S_PROTO_NAME,
NULL);
gtk_tree_view_column_set_sizing(tc, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(list, tc);
g_object_set_data(G_OBJECT(page), E_PAGE_LIST, list);
*scrolled_win_p = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(*scrolled_win_p),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(*scrolled_win_p),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(*scrolled_win_p), GTK_WIDGET(list));
*list_p = GTK_WIDGET(list);
}
void
decode_list_menu_finish(GtkWidget *list)
{
const gchar *text[E_LIST_S_COLUMNS];
GtkListStore *store;
GtkTreeIter iter;
text[E_LIST_S_PROTO_NAME] = "(default)";
text[E_LIST_S_TABLE] = "(none)";
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
gtk_list_store_prepend(store, &iter);
gtk_list_store_set(store, &iter,
E_LIST_S_PROTO_NAME, text[E_LIST_S_PROTO_NAME],
E_LIST_S_TABLE, text[E_LIST_S_TABLE],
E_LIST_S_TABLE+1, NULL, -1);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)), &iter);
g_signal_connect(list, "button_press_event", G_CALLBACK(decode_list_button_press_cb), NULL);
g_signal_connect(list, "key_release_event", G_CALLBACK(decode_list_key_release_cb), NULL);
}
static GtkWidget *
decode_add_simple_menu (GtkWidget *page, const gchar *table_name)
{
GtkWidget *scrolled_window;
GtkWidget *list;
decode_list_menu_start(page, &list, &scrolled_window);
dissector_table_foreach_handle(table_name, decode_proto_add_to_list, list);
decode_list_menu_finish(list);
return(scrolled_window);
}
static GtkWidget *
decode_add_simple_page (const gchar *prompt, const gchar *title, const gchar *table_name,
guint value)
{
GtkWidget *page, *label, *scrolled_window;
page = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page), E_PAGE_ACTION, decode_simple);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gchar *) table_name);
g_object_set_data(G_OBJECT(page), E_PAGE_TITLE, (gchar *) title);
g_object_set_data(G_OBJECT(page), E_PAGE_VALUE, GUINT_TO_POINTER(value));
label = gtk_label_new(prompt);
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
label = gtk_label_new("as");
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, label);
scrolled_window = decode_add_simple_menu(page, table_name);
gtk_box_pack_start(GTK_BOX(page), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
return(page);
}
static GtkWidget *
decode_add_tcpudp_page (const gchar *prompt, const gchar *table_name)
{
GtkWidget *page, *label, *scrolled_window, *combo_box;
page = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page), E_PAGE_ACTION, decode_transport);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gchar *) table_name);
g_object_set_data(G_OBJECT(page), E_PAGE_TITLE, (gpointer)"Transport");
label = gtk_label_new(prompt);
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
combo_box = decode_add_srcdst_combo_box(page);
gtk_box_pack_start(GTK_BOX(page), combo_box, FALSE, FALSE, 0);
label = gtk_label_new("port(s)");
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
label = gtk_label_new("as");
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, label);
scrolled_window = decode_add_simple_menu(page, table_name);
gtk_box_pack_start(GTK_BOX(page), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
return(page);
}
static void
decode_sctp_list_menu_start(GtkWidget **list_p, GtkWidget **scrolled_win_p)
{
GtkTreeView *list;
GtkListStore *sctp_store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *tc;
GtkTreeSortable *sortable;
sctp_store = (GtkListStore *)g_object_get_data(G_OBJECT(decode_w), "sctp_data");
list = GTK_TREE_VIEW(tree_view_new(GTK_TREE_MODEL(sctp_store)));
g_object_unref(G_OBJECT(sctp_store));
sortable = GTK_TREE_SORTABLE(sctp_store);
gtk_tree_sortable_set_sort_func(sortable, SORT_ALPHABETICAL, sort_iter_compare_func, GINT_TO_POINTER(SORT_ALPHABETICAL), NULL);
gtk_tree_sortable_set_sort_column_id(sortable, SORT_ALPHABETICAL, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list, FALSE);
#ifndef DEBUG
gtk_tree_view_set_headers_visible(list, FALSE);
#endif
renderer = gtk_cell_renderer_text_new();
tc = gtk_tree_view_column_new_with_attributes("Short Name", renderer,
"text", E_LIST_S_PROTO_NAME,
NULL);
gtk_tree_view_column_set_sizing(tc, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(list, tc);
*scrolled_win_p = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(*scrolled_win_p), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(*scrolled_win_p), GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(*scrolled_win_p), GTK_WIDGET(list));
*list_p = GTK_WIDGET(list);
}
static void
decode_sctp_update_ppid_combo_box(GtkWidget *w _U_, GtkWidget *page)
{
GtkWidget *list, *scrolled_window;
GtkWidget *sctp_combo_box;
gchar tmp[100];
guint number_of_ppid;
GtkListStore *sctp_store;
sctp_combo_box = (GtkWidget *)g_object_get_data(G_OBJECT(page), E_COMBO_BOX_SRCDST);
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box));
for(number_of_ppid = 0; number_of_ppid < MAX_NUMBER_OF_PPIDS; number_of_ppid++) {
if (cfile.edt->pi.ppids[number_of_ppid] != LAST_PPID) {
g_snprintf(tmp, sizeof(tmp), "PPID (%u)", cfile.edt->pi.ppids[number_of_ppid]);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box),
tmp, GINT_TO_POINTER(E_DECODE_PPID + 1 + number_of_ppid));
} else
break;
}
if (number_of_ppid)
ws_combo_box_set_active(GTK_COMBO_BOX(sctp_combo_box), 0);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gpointer)"sctp.ppi");
sctp_store = (GtkListStore *)g_object_get_data(G_OBJECT(G_OBJECT(decode_w)), "sctp_data");
gtk_list_store_clear(sctp_store);
decode_sctp_list_menu_start(&list, &scrolled_window);
dissector_table_foreach_handle("sctp.ppi", decode_proto_add_to_list, list);
decode_list_menu_finish(list);
}
static void
decode_sctp_update_srcdst_combo_box(GtkWidget *w _U_, GtkWidget *page)
{
GtkWidget *scrolled_window, *list;
GtkWidget *sctp_combo_box;
gchar tmp[100];
GtkListStore *sctp_store;
sctp_combo_box = (GtkWidget *)g_object_get_data(G_OBJECT(page), E_COMBO_BOX_SRCDST);
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box));
g_snprintf(tmp, sizeof(tmp), "source (%u)", cfile.edt->pi.srcport);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box), tmp, GINT_TO_POINTER(E_DECODE_SPORT));
g_snprintf(tmp, sizeof(tmp), "destination (%u)", cfile.edt->pi.destport);
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box), tmp, GINT_TO_POINTER(E_DECODE_DPORT));
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(sctp_combo_box), "both", GINT_TO_POINTER(E_DECODE_BPORT));
ws_combo_box_set_active(GTK_COMBO_BOX(sctp_combo_box), 0);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gpointer)"sctp.port");
g_object_set_data(G_OBJECT(page), E_PAGE_SPORT, GINT_TO_POINTER(cfile.edt->pi.srcport));
g_object_set_data(G_OBJECT(page), E_PAGE_DPORT, GINT_TO_POINTER(cfile.edt->pi.destport));
sctp_store = (GtkListStore *)g_object_get_data(G_OBJECT(G_OBJECT(decode_w)), "sctp_data");
gtk_list_store_clear(sctp_store);
decode_sctp_list_menu_start(&list, &scrolled_window);
dissector_table_foreach_handle("sctp.port", decode_proto_add_to_list, list);
decode_list_menu_finish(list);
}
static GtkWidget *
decode_sctp_add_port_ppid (GtkWidget *page)
{
GtkWidget *format_vb, *radio_button;
GSList *format_grp;
format_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
radio_button = gtk_radio_button_new_with_label(NULL, "PPID");
format_grp = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button));
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_button), TRUE);
g_signal_connect(radio_button, "clicked", G_CALLBACK(decode_sctp_update_ppid_combo_box), page);
gtk_box_pack_start(GTK_BOX(format_vb), radio_button, FALSE, FALSE, 0);
radio_button = gtk_radio_button_new_with_label(format_grp, "Port");
g_signal_connect(radio_button, "clicked", G_CALLBACK(decode_sctp_update_srcdst_combo_box), page);
gtk_box_pack_start(GTK_BOX(format_vb), radio_button, FALSE, FALSE, 0);
return(format_vb);
}
static GtkWidget *
decode_add_sctp_page (const gchar *prompt, const gchar *table_name)
{
GtkWidget *page, *label, *scrolled_window, *radio, *vbox, *alignment, *sctpbox, *sctp_combo_box;
page = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page), E_PAGE_ACTION, decode_transport);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gchar *) table_name);
g_object_set_data(G_OBJECT(page), E_PAGE_TITLE, (gpointer)"Transport");
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
radio = decode_sctp_add_port_ppid(page);
gtk_box_pack_start(GTK_BOX(vbox), radio, FALSE, FALSE, 0);
sctpbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
label = gtk_label_new(prompt);
gtk_box_pack_start(GTK_BOX(sctpbox), label, FALSE, FALSE, 0);
sctp_combo_box = decode_add_ppid_combo_box(page);
alignment = decode_add_pack_combo_box(sctp_combo_box);
gtk_box_pack_start(GTK_BOX(sctpbox), alignment, FALSE, FALSE, 0);
label = gtk_label_new("as");
gtk_box_pack_end(GTK_BOX(sctpbox), label, FALSE, FALSE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, label);
gtk_box_pack_end(GTK_BOX(vbox), sctpbox, FALSE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(page), vbox, FALSE, FALSE, 0);
scrolled_window = decode_add_simple_menu(page, table_name);
gtk_box_pack_start(GTK_BOX(page), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
return(page);
}
static void
decode_bluetooth(GtkWidget *notebook_pg)
{
#ifdef DEBUG
gchar *string;
#endif
GtkWidget *list;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
gchar *table_name;
guint value;
dissector_handle_t handle;
gchar *abbrev;
guint *value_type;
list = (GtkWidget *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_LIST);
if (requested_action == E_DECODE_NO)
gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(list)));
#ifdef DEBUG
string = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TITLE);
decode_debug(GTK_TREE_VIEW(list), string);
#endif
table_name = (gchar *)g_object_get_data(G_OBJECT(notebook_pg), E_PAGE_TABLE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
if (gtk_tree_selection_get_selected(selection, &model, &iter) == FALSE)
{
abbrev = NULL;
handle = NULL;
} else {
gtk_tree_model_get(model, &iter, E_LIST_S_PROTO_NAME, &abbrev,
E_LIST_S_TABLE+1, &handle, -1);
}
value = (guint)strtol(gtk_entry_get_text((GtkEntry *) g_hash_table_lookup(value_entry_table, table_name)), NULL, 0);
if (abbrev != NULL && strcmp(abbrev, "(default)") == 0) {
dissector_reset_uint(table_name, value);
} else {
dissector_change_uint(table_name, value, handle);
}
value_type = g_new(guint,1);
*value_type = value;
decode_build_reset_list(g_strdup(table_name), FT_UINT32, value_type, NULL, NULL);
g_free(abbrev);
}
static GtkWidget *
decode_add_bluetooth_page(const gchar *prompt, const gchar *table_name, const char *value)
{
GtkWidget *page;
GtkWidget *label;
GtkWidget *scrolled_window;
GtkWidget *value_entry = NULL;
const char *empty = "";
if (value == NULL)
value = empty;
page = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
g_object_set_data(G_OBJECT(page), E_PAGE_ACTION, decode_bluetooth);
g_object_set_data(G_OBJECT(page), E_PAGE_TABLE, (gchar *) table_name);
g_object_set_data(G_OBJECT(page), E_PAGE_TITLE, (gchar *) prompt);
label = gtk_label_new(prompt);
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
value_entry = (GtkWidget *)g_hash_table_lookup(value_entry_table, table_name);
if (!value_entry) {
value_entry = gtk_entry_new();
g_hash_table_insert(value_entry_table, (gchar *) table_name, value_entry);
}
gtk_entry_set_text((GtkEntry *) value_entry, value);
gtk_box_pack_start(GTK_BOX(page), value_entry, FALSE, FALSE, 0);
label = gtk_label_new("as");
gtk_box_pack_start(GTK_BOX(page), label, FALSE, FALSE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, label);
scrolled_window = decode_add_simple_menu(page, table_name);
gtk_box_pack_start(GTK_BOX(page), scrolled_window, TRUE, TRUE, 0);
decode_dimmable = g_slist_prepend(decode_dimmable, scrolled_window);
return(page);
}
gboolean
decode_as_ok(void)
{
return (cfile.edt->pi.ethertype != G_MAXINT) || cfile.edt->pi.ipproto ||
cfile.edt->pi.ptype == PT_TCP || cfile.edt->pi.ptype == PT_UDP ||
cfile.edt->pi.mpls_label ||
cfile.cd_t == WTAP_FILE_BER ||
cfile.edt->pi.ptype == PT_BLUETOOTH ||
wtap_file_encap(cfile.wth) == WTAP_ENCAP_BLUETOOTH_H4 ||
wtap_file_encap(cfile.wth) == WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR;
}
static void
decode_add_notebook (GtkWidget *format_hb)
{
GtkWidget *notebook, *page, *label;
gchar buffer[40];
notebook = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(format_hb), notebook, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(decode_w), E_NOTEBOOK, notebook);
if (cfile.edt->pi.ethertype != G_MAXINT) {
g_snprintf(buffer, sizeof(buffer), "Ethertype 0x%04x", cfile.edt->pi.ethertype);
page = decode_add_simple_page(buffer, "Link", "ethertype", cfile.edt->pi.ethertype);
label = gtk_label_new("Link");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
if (cfile.edt->pi.mpls_label) {
g_snprintf(buffer, sizeof(buffer), "Data after label %u", cfile.edt->pi.mpls_label);
page = decode_add_simple_page(buffer, "MPLS", "mpls.label", cfile.edt->pi.mpls_label);
label = gtk_label_new("MPLS");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
if (cfile.edt->pi.ipproto) {
g_snprintf(buffer, sizeof(buffer), "IP protocol %u", cfile.edt->pi.ipproto);
page = decode_add_simple_page(buffer, "Network", "ip.proto", cfile.edt->pi.ipproto);
g_object_set_data(G_OBJECT(page), E_PAGE_ACTION, decode_simple);
label = gtk_label_new("Network");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
switch (cfile.edt->pi.ptype) {
case PT_TCP:
page = decode_add_tcpudp_page("TCP", "tcp.port");
break;
case PT_UDP:
page = decode_add_tcpudp_page("UDP", "udp.port");
break;
case PT_SCTP:
page = decode_add_sctp_page("SCTP", "sctp.ppi");
break;
default:
page = NULL;
break;
}
if (page != NULL) {
label = gtk_label_new("Transport");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
if(cfile.edt->pi.dcetransporttype != -1) {
page = decode_dcerpc_add_page(&cfile.edt->pi);
label = gtk_label_new("DCE-RPC");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
g_object_set_data(G_OBJECT(decode_w), E_PAGE_DCERPC, page);
}
if(cfile.cd_t == WTAP_FILE_BER) {
page = decode_ber_add_page(&cfile.edt->pi);
label = gtk_label_new("ASN.1");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
g_object_set_data(G_OBJECT(decode_w), E_PAGE_ASN1, page);
}
if (wtap_file_encap(cfile.wth) == WTAP_ENCAP_BLUETOOTH_H4 ||
wtap_file_encap(cfile.wth) == WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR ||
cfile.edt->pi.ptype == PT_BLUETOOTH) {
gint page_l2cap_service = -1;
gint page_l2cap_cid = -1;
gint page_l2cap_psm = -1;
gint page_rfcomm_channel = -1;
gint page_rfcomm_service = -1;
gint page_avctp_service = -1;
header_field_info *hfinfo;
GPtrArray *ga;
guint i;
field_info *v;
const gchar *cid = NULL;
const gchar *psm = NULL;
const gchar *channel = NULL;
const gchar *pid = NULL;
gboolean have_rfcomm = FALSE;
ga = proto_all_finfos(cfile.edt->tree);
for (i = 0; i < ga->len; i += 1) {
v = (field_info *)g_ptr_array_index (ga, i);
hfinfo = v->hfinfo;
if (g_strcmp0(hfinfo->abbrev, "btl2cap.cid") == 0) {
cid = get_node_field_value(v, cfile.edt);
} else if (g_strcmp0(hfinfo->abbrev, "btl2cap.psm") == 0) {
psm = get_node_field_value(v, cfile.edt);
} else if (g_strcmp0(hfinfo->abbrev, "btrfcomm.channel") == 0) {
channel = get_node_field_value(v, cfile.edt);
} else if (g_strcmp0(hfinfo->abbrev, "btavctp.pid") == 0) {
pid = get_node_field_value(v, cfile.edt);
}
if (have_rfcomm == FALSE && g_str_has_prefix(hfinfo->abbrev, "btrfcommm")) {
have_rfcomm = TRUE;
}
}
value_entry_table = g_hash_table_new(g_str_hash, g_str_equal);
page = decode_add_bluetooth_page("L2CAP SERVICE", "btl2cap.service", NULL);
if (page != NULL) {
label = gtk_label_new("L2CAP SERVICE");
page_l2cap_service = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = decode_add_bluetooth_page("L2CAP CID", "btl2cap.cid", cid);
if (page != NULL) {
label = gtk_label_new("L2CAP CID");
page_l2cap_cid = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = decode_add_bluetooth_page("L2CAP PSM", "btl2cap.psm", psm);
if (page != NULL) {
label = gtk_label_new("L2CAP PSM");
page_l2cap_psm = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = decode_add_bluetooth_page("RFCOMM Channel", "btrfcomm.channel", channel);
if (page != NULL) {
label = gtk_label_new("RFCOMM Channel");
page_rfcomm_channel = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = decode_add_bluetooth_page("RFCOMM SERVICE", "btrfcomm.service", NULL);
if (page != NULL) {
label = gtk_label_new("RFCOMM SERVICE");
page_rfcomm_service = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = decode_add_bluetooth_page("AVCTP SERVICE", "btavctp.service", pid);
if (page != NULL) {
label = gtk_label_new("AVCTP SERVICE");
page_avctp_service = gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
}
page = NULL;
gtk_widget_show_all(notebook);
if (pid)
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_avctp_service);
else if (channel)
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_rfcomm_channel);
else if (psm)
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_l2cap_psm);
else if (cid)
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_l2cap_cid);
else if (have_rfcomm)
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_rfcomm_service);
else
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), page_l2cap_service);
} else {
gtk_widget_show_all(notebook);
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), -1);
}
}
void
decode_as_cb (GtkWidget * w _U_, gpointer user_data _U_)
{
GtkWidget *main_vb, *format_hb, *bbox, *ok_bt, *close_bt, *help_bt, *button;
GtkWidget *button_vb, *apply_bt;
if (decode_w != NULL) {
reactivate_window(decode_w);
return;
}
requested_action = E_DECODE_YES;
decode_w = dlg_window_new("Wireshark: Decode As");
gtk_window_set_default_size(GTK_WINDOW(decode_w), -1, E_DECODE_MIN_HEIGHT);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 2, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(decode_w), main_vb);
format_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), format_hb, TRUE, TRUE, 10);
button_vb = decode_add_yes_no();
gtk_box_pack_start(GTK_BOX(format_hb), button_vb, FALSE, FALSE, 10);
button = gtk_button_new_with_label("Show Current");
g_signal_connect(button, "clicked", G_CALLBACK(decode_show_cb), NULL);
gtk_widget_set_can_default(button, TRUE);
gtk_box_pack_end(GTK_BOX(button_vb), button, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(button, "Open a dialog showing the current settings.\n"
"Note you need to select and press apply first to be able to save the current setting");
button = gtk_button_new_from_stock(GTK_STOCK_CLEAR);
g_signal_connect(button, "clicked", G_CALLBACK(decode_clear_cb), NULL);
gtk_widget_set_can_default(button, TRUE);
gtk_box_pack_end(GTK_BOX(button_vb), button, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(button, "Clear ALL settings.");
decode_add_notebook(format_hb);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(decode_ok_cb), decode_w);
gtk_widget_set_tooltip_text(ok_bt, "Apply current setting, close dialog and redissect packets.");
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(decode_apply_cb), decode_w);
gtk_widget_set_tooltip_text(apply_bt, "Apply current setting, redissect packets and keep dialog open.");
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(decode_w, close_bt, NULL);
g_signal_connect(close_bt, "clicked", G_CALLBACK(decode_close_cb), decode_w);
gtk_widget_set_tooltip_text(close_bt, "Close the dialog, don't redissect packets.");
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_DECODE_AS_DIALOG);
gtk_widget_grab_default(ok_bt);
g_signal_connect(decode_w, "delete_event", G_CALLBACK(decode_delete_cb), NULL);
g_signal_connect(decode_w, "destroy", G_CALLBACK(decode_destroy_cb), NULL);
gtk_widget_show_all(decode_w);
window_present(decode_w);
}
void load_decode_as_entries(void)
{
char *daf_path;
FILE *daf;
if (dissector_reset_list) {
decode_clear_all(FALSE);
}
daf_path = get_persconffile_path(DECODE_AS_ENTRIES_FILE_NAME, TRUE);
if ((daf = ws_fopen(daf_path, "r")) != NULL) {
read_prefs_file(daf_path, daf, read_set_decode_as_entries, NULL);
fclose(daf);
}
g_free(daf_path);
}
