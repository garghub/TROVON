static guint
pref_exists(pref_t *pref _U_, gpointer user_data _U_)
{
return 1;
}
static guint
pref_show(pref_t *pref, gpointer user_data)
{
GtkWidget *main_tb = user_data;
const char *title;
char *label_string;
size_t label_len;
char uint_str[10+1];
title = pref->title;
label_len = strlen(title) + 2;
label_string = g_malloc(label_len);
g_strlcpy(label_string, title, label_len);
if(pref->type != PREF_STATIC_TEXT)
g_strlcat(label_string, ":", label_len);
switch (pref->type) {
case PREF_UINT:
pref->saved_val.uint = *pref->varp.uint;
switch (pref->info.base) {
case 10:
g_snprintf(uint_str, sizeof(uint_str), "%u", pref->saved_val.uint);
break;
case 8:
g_snprintf(uint_str, sizeof(uint_str), "%o", pref->saved_val.uint);
break;
case 16:
g_snprintf(uint_str, sizeof(uint_str), "%x", pref->saved_val.uint);
break;
}
pref->control = create_preference_entry(main_tb, pref->ordinal,
label_string, pref->description,
uint_str);
break;
case PREF_BOOL:
pref->saved_val.boolval = *pref->varp.boolp;
pref->control = create_preference_check_button(main_tb, pref->ordinal,
label_string, pref->description,
pref->saved_val.boolval);
break;
case PREF_ENUM:
pref->saved_val.enumval = *pref->varp.enump;
if (pref->info.enum_info.radio_buttons) {
pref->control = create_preference_radio_buttons(main_tb, pref->ordinal,
label_string, pref->description,
pref->info.enum_info.enumvals,
pref->saved_val.enumval);
} else {
pref->control = create_preference_option_menu(main_tb, pref->ordinal,
label_string, pref->description,
pref->info.enum_info.enumvals,
pref->saved_val.enumval);
}
break;
case PREF_STRING:
g_free(pref->saved_val.string);
pref->saved_val.string = g_strdup(*pref->varp.string);
pref->control = create_preference_entry(main_tb, pref->ordinal,
label_string, pref->description,
pref->saved_val.string);
break;
case PREF_FILENAME:
g_free(pref->saved_val.string);
pref->saved_val.string = g_strdup(*pref->varp.string);
pref->control = create_preference_filename_entry(main_tb, pref->ordinal,
label_string,
pref->description,
pref->saved_val.string);
break;
case PREF_RANGE:
{
char *range_str_p;
g_free(pref->saved_val.range);
pref->saved_val.range = range_copy(*pref->varp.range);
range_str_p = range_convert_range(*pref->varp.range);
pref->control = create_preference_entry(main_tb, pref->ordinal,
label_string, pref->description,
range_str_p);
break;
}
case PREF_STATIC_TEXT:
{
pref->control = create_preference_static_text(main_tb, pref->ordinal,
label_string, pref->description);
break;
}
case PREF_UAT:
{
pref->control = create_preference_uat(main_tb, pref->ordinal,
label_string, pref->description,
pref->varp.uat);
break;
}
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
g_free(label_string);
return 0;
}
static guint
module_prefs_show(module_t *module, gpointer user_data)
{
struct ct_struct *cts = user_data;
struct ct_struct child_cts;
GtkWidget *main_vb, *main_tb, *frame, *main_sw;
gchar label_str[MAX_TREE_NODE_NAME_LEN];
GtkTreeStore *model;
GtkTreeIter iter;
if (!prefs_module_has_submodules(module)) {
if (prefs_pref_foreach(module, pref_exists, NULL) == 0) {
return 0;
}
}
g_strlcpy(label_str, module->title, MAX_TREE_NODE_NAME_LEN);
model = GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cts->tree)));
if (prefs_module_has_submodules(module) && !cts->iter.stamp)
gtk_tree_store_append(model, &iter, NULL);
else
gtk_tree_store_append(model, &iter, &cts->iter);
if (prefs_module_has_submodules(module)) {
gtk_tree_store_set(model, &iter, 0, label_str, 1, -1, -1);
child_cts = *cts;
child_cts.iter = iter;
if (module == protocols_module)
child_cts.is_protocol = TRUE;
prefs_modules_foreach_submodules(module, module_prefs_show, &child_cts);
cts->page = child_cts.page;
}
if(module->prefs) {
main_sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(main_sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
frame = gtk_frame_new(module->description);
gtk_container_set_border_width(GTK_CONTAINER(frame), 5);
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(main_sw), frame);
g_object_set_data(G_OBJECT(main_sw), E_PAGESW_FRAME_KEY, frame);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(frame), main_vb);
main_tb = gtk_table_new(module->numprefs, 2, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), main_tb, FALSE, FALSE, 0);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 15);
prefs_pref_foreach(module, pref_show, main_tb);
g_object_set_data(G_OBJECT(frame), E_PAGE_MODULE_KEY, module);
gtk_notebook_append_page(GTK_NOTEBOOK(cts->notebook), main_sw, NULL);
gtk_tree_store_set(model, &iter, 0, label_str, 1, cts->page, -1);
g_object_set_data(G_OBJECT(frame), E_PAGE_ITER_KEY, gtk_tree_iter_copy(&iter));
cts->page++;
gtk_widget_show_all(main_sw);
} else {
gtk_tree_store_set(model, &iter, 0, label_str, 1, protocols_page, -1);
}
return 0;
}
static prefs_tree_iter
prefs_tree_page_add(const gchar *title, gint page_nr,
gpointer store, prefs_tree_iter *parent_iter)
{
prefs_tree_iter iter;
gtk_tree_store_append(store, &iter, parent_iter);
gtk_tree_store_set(store, &iter, 0, title, 1, page_nr, -1);
return iter;
}
static GtkWidget *
prefs_nb_page_add(GtkWidget *notebook, const gchar *title, GtkWidget *page, const char *page_key)
{
GtkWidget *frame;
frame = gtk_frame_new(title);
gtk_widget_show(frame);
if(page) {
gtk_container_add(GTK_CONTAINER(frame), page);
g_object_set_data(G_OBJECT(prefs_w), page_key, page);
}
gtk_notebook_append_page (GTK_NOTEBOOK(notebook), frame, NULL);
return frame;
}
void
prefs_cb(GtkWidget *w, gpointer dummy)
{
prefs_page_cb (w, dummy, PREFS_PAGE_USER_INTERFACE);
}
void
prefs_page_cb(GtkWidget *w _U_, gpointer dummy _U_, PREFS_PAGE_E prefs_page)
{
GtkWidget *top_hb, *bbox, *prefs_nb, *ct_sb,
*ok_bt, *apply_bt, *save_bt, *cancel_bt, *help_bt;
GtkWidget *gui_font_pg;
gchar label_str[MAX_TREE_NODE_NAME_LEN];
struct ct_struct cts;
GtkTreeStore *store;
GtkTreeSelection *selection;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
gint col_offset;
prefs_tree_iter gui_iter, layout_iter, columns_iter;
gint layout_page, columns_page;
if (prefs_w != NULL) {
reactivate_window(prefs_w);
return;
}
copy_prefs(&saved_prefs, &prefs);
prefs_w = dlg_conf_window_new("Wireshark: Preferences");
cts.main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(cts.main_vb), 5);
gtk_container_add(GTK_CONTAINER(prefs_w), cts.main_vb);
gtk_widget_show(cts.main_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_container_add(GTK_CONTAINER(cts.main_vb), top_hb);
gtk_widget_show(top_hb);
ct_sb = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(ct_sb),
GTK_SHADOW_IN);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ct_sb),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(top_hb), ct_sb);
gtk_widget_show(ct_sb);
g_object_set_data(G_OBJECT(prefs_w), E_PREFSW_SCROLLW_KEY, ct_sb);
store = gtk_tree_store_new(2, G_TYPE_STRING, G_TYPE_INT);
cts.tree = tree_view_new(GTK_TREE_MODEL(store));
cts.iter.stamp = 0;
g_object_set_data(G_OBJECT(prefs_w), E_PREFSW_TREE_KEY, cts.tree);
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(cts.tree), FALSE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(cts.tree));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
renderer = gtk_cell_renderer_text_new();
col_offset = gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(cts.tree),
-1, "Name", renderer,
"text", 0, NULL);
column = gtk_tree_view_get_column(GTK_TREE_VIEW(cts.tree),
col_offset - 1);
gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN(column),
GTK_TREE_VIEW_COLUMN_AUTOSIZE);
g_signal_connect(selection, "changed", G_CALLBACK(prefs_tree_select_cb), NULL);
gtk_container_add(GTK_CONTAINER(ct_sb), cts.tree);
gtk_widget_show(cts.tree);
prefs_nb = gtk_notebook_new();
g_object_set_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY, prefs_nb);
gtk_notebook_set_show_tabs(GTK_NOTEBOOK(prefs_nb), FALSE);
gtk_notebook_set_show_border(GTK_NOTEBOOK(prefs_nb), FALSE);
gtk_container_add(GTK_CONTAINER(top_hb), prefs_nb);
gtk_widget_show(prefs_nb);
cts.page = 0;
g_strlcpy(label_str, "Protocols", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, protocols_prefs_show(), E_PROTOCOLS_PAGE_KEY);
protocols_page = cts.page++;
g_strlcpy(label_str, "User Interface", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, gui_prefs_show(), E_GUI_PAGE_KEY);
gui_iter = prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
g_strlcpy(label_str, "Layout", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, layout_prefs_show(), E_GUI_LAYOUT_PAGE_KEY);
layout_iter = prefs_tree_page_add(label_str, cts.page, store, &gui_iter);
layout_page = cts.page++;
g_strlcpy(label_str, "Columns", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, column_prefs_show(prefs_w), E_GUI_COLUMN_PAGE_KEY);
columns_iter = prefs_tree_page_add(label_str, cts.page, store, &gui_iter);
columns_page = cts.page++;
g_strlcpy(label_str, "Font", MAX_TREE_NODE_NAME_LEN);
gui_font_pg = gui_font_prefs_show();
prefs_nb_page_add(prefs_nb, label_str, gui_font_pg, E_GUI_FONT_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, &gui_iter);
cts.page++;
gtk_container_set_border_width( GTK_CONTAINER(gui_font_pg), 5 );
#if GTK_CHECK_VERSION(3,2,0)
gtk_font_chooser_set_font(GTK_FONT_CHOOSER(gui_font_pg), prefs.gui_font_name);
#else
gtk_font_selection_set_font_name(
GTK_FONT_SELECTION(gui_font_pg), prefs.gui_font_name);
#endif
g_strlcpy(label_str, "Colors", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, stream_prefs_show(), E_GUI_COLORS_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, &gui_iter);
cts.page++;
gtk_tree_selection_select_iter(selection, &gui_iter);
gtk_tree_view_expand_all(GTK_TREE_VIEW(cts.tree));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
g_strlcpy(label_str, "Capture", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, capture_prefs_show(), E_CAPTURE_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
#ifdef _WIN32
}
#endif
#endif
g_strlcpy(label_str, "Printing", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, printer_prefs_show(), E_PRINT_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
g_strlcpy(label_str, "Name Resolution", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, nameres_prefs_show(), E_NAMERES_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
g_strlcpy(label_str, "Filter Expressions", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, filter_expressions_prefs_show(),
E_FILTER_EXPRESSIONS_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
g_strlcpy(label_str, "Statistics", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, stats_prefs_show(), E_TAPS_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
cts.notebook = prefs_nb;
cts.is_protocol = FALSE;
prefs_modules_foreach_submodules(NULL, module_prefs_show, &cts);
bbox = dlg_button_row_new(GTK_STOCK_HELP, GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(cts.main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(prefs_main_ok_cb), prefs_w);
apply_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(prefs_main_apply_cb), prefs_w);
save_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(prefs_main_save_cb), prefs_w);
g_object_set_data(G_OBJECT(prefs_w), E_PREFSW_SAVE_BT_KEY, save_bt);
cancel_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(prefs_main_cancel_cb), prefs_w);
window_set_cancel_button(prefs_w, cancel_bt, NULL);
gtk_widget_grab_default(ok_bt);
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_PREFERENCES_DIALOG);
g_signal_connect(prefs_w, "delete_event", G_CALLBACK(prefs_main_delete_event_cb), NULL);
g_signal_connect(prefs_w, "destroy", G_CALLBACK(prefs_main_destroy_cb), prefs_w);
gtk_widget_show(prefs_w);
if(!prefs.gui_use_pref_save) {
gtk_widget_hide(save_bt);
}
window_present(prefs_w);
switch (prefs_page) {
case PREFS_PAGE_LAYOUT:
gtk_tree_selection_select_iter(selection, &layout_iter);
gtk_notebook_set_current_page(g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), layout_page);
break;
case PREFS_PAGE_COLUMNS:
gtk_tree_selection_select_iter(selection, &columns_iter);
gtk_notebook_set_current_page(g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), columns_page);
break;
default:
break;
}
g_object_unref(G_OBJECT(store));
}
static void
set_option_label(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text)
{
GtkWidget *label;
GtkWidget *event_box;
label = gtk_label_new(label_text);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
gtk_widget_show(label);
event_box = gtk_event_box_new();
gtk_event_box_set_visible_window (GTK_EVENT_BOX(event_box), FALSE);
gtk_table_attach_defaults(GTK_TABLE(main_tb), event_box, 0, 1,
table_position, table_position + 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(event_box, tooltip_text);
gtk_container_add(GTK_CONTAINER(event_box), label);
gtk_widget_show(event_box);
}
GtkWidget *
create_preference_check_button(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text, gboolean active)
{
GtkWidget *check_box;
set_option_label(main_tb, table_position, label_text, tooltip_text);
check_box = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_box), active);
gtk_table_attach_defaults(GTK_TABLE(main_tb), check_box, 1, 2,
table_position, table_position + 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(check_box, tooltip_text);
return check_box;
}
GtkWidget *
create_preference_radio_buttons(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text,
const enum_val_t *enumvals, gint current_val)
{
GtkWidget *radio_button_hbox, *button = NULL;
GSList *rb_group;
int idx;
const enum_val_t *enum_valp;
GtkWidget *event_box;
set_option_label(main_tb, table_position, label_text, tooltip_text);
radio_button_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
rb_group = NULL;
for (enum_valp = enumvals, idx = 0; enum_valp->name != NULL;
enum_valp++, idx++) {
button = gtk_radio_button_new_with_label(rb_group,
enum_valp->description);
gtk_widget_show(button);
rb_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));
gtk_box_pack_start(GTK_BOX(radio_button_hbox), button, FALSE,
FALSE, 10);
if (enum_valp->value == current_val) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button),
TRUE);
}
}
gtk_widget_show(radio_button_hbox);
event_box = gtk_event_box_new();
gtk_event_box_set_visible_window (GTK_EVENT_BOX(event_box), FALSE);
gtk_container_add(GTK_CONTAINER(event_box), radio_button_hbox);
gtk_table_attach_defaults(GTK_TABLE(main_tb), event_box, 1, 2,
table_position, table_position+1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(event_box, tooltip_text);
gtk_widget_show(event_box);
return button;
}
static gint
label_to_enum_val(GtkWidget *label, const enum_val_t *enumvals)
{
const gchar *label_string;
int i;
label_string = gtk_label_get_text(GTK_LABEL(label));
for (i = 0; enumvals[i].name != NULL; i++) {
if (g_ascii_strcasecmp(label_string, enumvals[i].description) == 0) {
return enumvals[i].value;
}
}
g_assert_not_reached();
return -1;
}
gint
fetch_preference_radio_buttons_val(GtkWidget *button,
const enum_val_t *enumvals)
{
GSList *rb_group;
GSList *rb_entry;
rb_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));
button = NULL;
for (rb_entry = rb_group; rb_entry != NULL;
rb_entry = g_slist_next(rb_entry)) {
button = rb_entry->data;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button)))
break;
}
return label_to_enum_val(gtk_bin_get_child(GTK_BIN(button)), enumvals);
}
GtkWidget *
create_preference_option_menu(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text,
const enum_val_t *enumvals, gint current_val)
{
GtkWidget *menu_box, *combo_box;
int menu_idx, idx;
const enum_val_t *enum_valp;
GtkWidget *event_box;
set_option_label(main_tb, table_position, label_text, tooltip_text);
combo_box = gtk_combo_box_text_new();
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(combo_box, tooltip_text);
menu_idx = 0;
for (enum_valp = enumvals, idx = 0; enum_valp->name != NULL;
enum_valp++, idx++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo_box), enum_valp->description);
if (enum_valp->value == current_val)
menu_idx = idx;
}
gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), menu_idx);
menu_box = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(menu_box), combo_box, FALSE, FALSE, 0);
event_box = gtk_event_box_new();
gtk_event_box_set_visible_window (GTK_EVENT_BOX(event_box), FALSE);
gtk_table_attach_defaults(GTK_TABLE(main_tb), event_box,
1, 2, table_position, table_position + 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(event_box, tooltip_text);
gtk_container_add(GTK_CONTAINER(event_box), menu_box);
return combo_box;
}
gint
fetch_preference_option_menu_val(GtkWidget *combo_box, const enum_val_t *enumvals)
{
int i;
i = gtk_combo_box_get_active (GTK_COMBO_BOX(combo_box));
return enumvals[i].value;
}
GtkWidget *
create_preference_entry(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text, char *value)
{
GtkWidget *entry;
set_option_label(main_tb, table_position, label_text, tooltip_text);
entry = gtk_entry_new();
if (value != NULL)
gtk_entry_set_text(GTK_ENTRY(entry), value);
gtk_table_attach_defaults(GTK_TABLE(main_tb), entry, 1, 2,
table_position, table_position + 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(entry, tooltip_text);
gtk_widget_show(entry);
return entry;
}
static void
preference_filename_entry_cb(GtkWidget *button, GtkWidget *filename_te)
{
file_selection_browse(button, filename_te, "Wireshark: file preference",
FILE_SELECTION_READ_BROWSE);
}
static GtkWidget *
create_preference_filename_entry(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text, char *value)
{
GtkWidget *entry;
GtkWidget *button, *file_bt_hb;
set_option_label(main_tb, table_position, label_text, tooltip_text);
file_bt_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_table_attach_defaults(GTK_TABLE(main_tb), file_bt_hb, 1, 2,
table_position, table_position + 1);
gtk_widget_show(file_bt_hb);
button = gtk_button_new_from_stock(WIRESHARK_STOCK_BROWSE);
gtk_box_pack_end(GTK_BOX(file_bt_hb), button, FALSE, FALSE, 0);
gtk_widget_show(button);
entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(file_bt_hb), entry, TRUE, TRUE, 0);
if (value != NULL)
gtk_entry_set_text(GTK_ENTRY(entry), value);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(entry, tooltip_text);
gtk_widget_show(entry);
g_signal_connect(button, "clicked", G_CALLBACK(preference_filename_entry_cb), entry);
return entry;
}
GtkWidget *
create_preference_static_text(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text)
{
GtkWidget *label;
if(label_text != NULL)
label = gtk_label_new(label_text);
else
label = gtk_label_new("");
gtk_table_attach_defaults(GTK_TABLE(main_tb), label, 0, 2,
table_position, table_position + 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(label, tooltip_text);
gtk_widget_show(label);
return label;
}
GtkWidget *
create_preference_uat(GtkWidget *main_tb, int table_position,
const gchar *label_text, const gchar *tooltip_text, void* uat)
{
GtkWidget *button;
set_option_label(main_tb, table_position, label_text, tooltip_text);
button = gtk_button_new_from_stock(WIRESHARK_STOCK_EDIT);
g_signal_connect(button, "clicked", G_CALLBACK(uat_window_cb), uat);
gtk_table_attach_defaults(GTK_TABLE(main_tb), button, 1, 2,
table_position, table_position+1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(button, tooltip_text);
gtk_widget_show(button);
return button;
}
static guint
pref_check(pref_t *pref, gpointer user_data)
{
const char *str_val;
char *p;
pref_t **badpref = user_data;
switch (pref->type) {
case PREF_UINT:
str_val = gtk_entry_get_text(GTK_ENTRY(pref->control));
errno = 0;
if(strtoul(str_val, &p, pref->info.base)){}
if (p == str_val || *p != '\0' || errno != 0) {
*badpref = pref;
return PREFS_SET_SYNTAX_ERR;
}
break;
case PREF_BOOL:
break;
case PREF_ENUM:
break;
case PREF_STRING:
case PREF_FILENAME:
break;
case PREF_RANGE:
str_val = gtk_entry_get_text(GTK_ENTRY(pref->control));
if (strlen(str_val) != 0) {
range_t *newrange;
if (range_convert_str(&newrange, str_val, pref->info.max_value) != CVT_NO_ERROR) {
*badpref = pref;
return PREFS_SET_SYNTAX_ERR;
}
g_free(newrange);
}
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_check(module_t *module, gpointer user_data)
{
return prefs_pref_foreach(module, pref_check, user_data);
}
static guint
pref_fetch(pref_t *pref, gpointer user_data)
{
const char *str_val;
char *p;
guint uval;
gboolean bval;
gint enumval;
gboolean *pref_changed_p = user_data;
switch (pref->type) {
case PREF_UINT:
str_val = gtk_entry_get_text(GTK_ENTRY(pref->control));
uval = strtoul(str_val, &p, pref->info.base);
#if 0
if (p == value || *p != '\0')
return PREFS_SET_SYNTAX_ERR;
#endif
if (*pref->varp.uint != uval) {
*pref_changed_p = TRUE;
*pref->varp.uint = uval;
}
break;
case PREF_BOOL:
bval = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pref->control));
if (*pref->varp.boolp != bval) {
*pref_changed_p = TRUE;
*pref->varp.boolp = bval;
}
break;
case PREF_ENUM:
if (pref->info.enum_info.radio_buttons) {
enumval = fetch_preference_radio_buttons_val(pref->control,
pref->info.enum_info.enumvals);
} else {
enumval = fetch_preference_option_menu_val(pref->control,
pref->info.enum_info.enumvals);
}
if (*pref->varp.enump != enumval) {
*pref_changed_p = TRUE;
*pref->varp.enump = enumval;
}
break;
case PREF_STRING:
case PREF_FILENAME:
str_val = gtk_entry_get_text(GTK_ENTRY(pref->control));
if (strcmp(*pref->varp.string, str_val) != 0) {
*pref_changed_p = TRUE;
g_free((void *)*pref->varp.string);
*pref->varp.string = g_strdup(str_val);
}
break;
case PREF_RANGE:
{
range_t *newrange;
convert_ret_t ret;
str_val = gtk_entry_get_text(GTK_ENTRY(pref->control));
ret = range_convert_str(&newrange, str_val, pref->info.max_value);
if (ret != CVT_NO_ERROR)
#if 0
return PREFS_SET_SYNTAX_ERR;
#else
return 0;
#endif
if (!ranges_are_equal(*pref->varp.range, newrange)) {
*pref_changed_p = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = newrange;
} else
g_free(newrange);
break;
}
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_fetch(module_t *module, gpointer user_data)
{
gboolean *must_redissect_p = user_data;
module->prefs_changed = FALSE;
prefs_pref_foreach(module, pref_fetch, &module->prefs_changed);
if (module->prefs_changed)
*must_redissect_p = TRUE;
return 0;
}
static void
prefs_airpcap_update(void)
{
GtkWidget *decryption_cm;
gint cur_active;
gboolean wireshark_decryption_was_enabled = FALSE;
gboolean airpcap_decryption_was_enabled = FALSE;
gboolean wireshark_decryption_is_now_enabled = FALSE;
decryption_cm = GTK_WIDGET(g_object_get_data(G_OBJECT(airpcap_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY));
if (decryption_cm == NULL) {
return;
}
cur_active = gtk_combo_box_get_active(GTK_COMBO_BOX(decryption_cm));
if (cur_active < 0) {
return;
}
switch(cur_active) {
case 1:
wireshark_decryption_was_enabled = TRUE;
airpcap_decryption_was_enabled = FALSE;
break;
case 2:
wireshark_decryption_was_enabled = FALSE;
airpcap_decryption_was_enabled = TRUE;
break;
default:
wireshark_decryption_was_enabled = FALSE;
airpcap_decryption_was_enabled = FALSE;
break;
}
wireshark_decryption_is_now_enabled = wireshark_decryption_on();
if(wireshark_decryption_is_now_enabled && airpcap_decryption_was_enabled)
{
set_airpcap_decryption(FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 1);
}
if(wireshark_decryption_is_now_enabled && !airpcap_decryption_was_enabled)
{
set_airpcap_decryption(FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 1);
}
else if(!wireshark_decryption_is_now_enabled && wireshark_decryption_was_enabled)
{
if(airpcap_decryption_was_enabled)
{
set_airpcap_decryption(TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 2);
}
else
{
set_airpcap_decryption(FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 0);
}
}
}
static guint
pref_clean(pref_t *pref, gpointer user_data _U_)
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
if (pref->saved_val.string != NULL) {
g_free(pref->saved_val.string);
pref->saved_val.string = NULL;
}
break;
case PREF_RANGE:
if (pref->saved_val.range != NULL) {
g_free(pref->saved_val.range);
pref->saved_val.range = NULL;
}
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_clean(module_t *module, gpointer user_data _U_)
{
prefs_pref_foreach(module, pref_clean, NULL);
return 0;
}
static gboolean
prefs_main_fetch_all(GtkWidget *dlg, gboolean *must_redissect)
{
pref_t *badpref;
switch (prefs_modules_foreach(module_prefs_check, (gpointer)&badpref)) {
case PREFS_SET_SYNTAX_ERR:
switch (badpref->type) {
case PREF_UINT:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value for \"%s\" isn't a valid number.",
badpref->title);
return FALSE;
case PREF_RANGE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value for \"%s\" isn't a valid range.",
badpref->title);
return FALSE;
default:
g_assert_not_reached();
break;
}
}
gui_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY));
layout_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
stream_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_GUI_COLORS_PAGE_KEY));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
printer_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_PRINT_PAGE_KEY));
nameres_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_NAMERES_PAGE_KEY));
filter_expressions_prefs_fetch(g_object_get_data(G_OBJECT(dlg),
E_FILTER_EXPRESSIONS_PAGE_KEY));
stats_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_TAPS_PAGE_KEY));
protocols_prefs_fetch(g_object_get_data(G_OBJECT(dlg), E_PROTOCOLS_PAGE_KEY));
prefs_modules_foreach(module_prefs_fetch, must_redissect);
return TRUE;
}
static void
prefs_main_apply_all(GtkWidget *dlg, gboolean redissect)
{
GtkWidget *save_bt;
prefs_apply_all();
gui_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY), redissect);
layout_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
stream_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_GUI_COLORS_PAGE_KEY));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
printer_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_PRINT_PAGE_KEY));
nameres_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_NAMERES_PAGE_KEY));
stats_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_TAPS_PAGE_KEY));
protocols_prefs_apply(g_object_get_data(G_OBJECT(dlg), E_PROTOCOLS_PAGE_KEY));
save_bt = g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_SAVE_BT_KEY);
if(prefs.gui_use_pref_save) {
gtk_widget_show(save_bt);
} else {
gtk_widget_hide(save_bt);
}
}
static void
prefs_main_destroy_all(GtkWidget *dlg)
{
int page_num;
GtkWidget *frame;
for (page_num = 0;
(frame = gtk_notebook_get_nth_page(g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page_num)) != NULL;
page_num++) {
if(g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY))
gtk_tree_iter_free(g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY));
}
gui_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY));
layout_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
stream_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_GUI_COLORS_PAGE_KEY));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
printer_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_PRINT_PAGE_KEY));
nameres_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_NAMERES_PAGE_KEY));
stats_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_TAPS_PAGE_KEY));
free_prefs(&saved_prefs);
prefs_modules_foreach(module_prefs_clean, NULL);
protocols_prefs_destroy(g_object_get_data(G_OBJECT(dlg), E_PROTOCOLS_PAGE_KEY));
}
static guint
pref_copy(pref_t *pref, gpointer user_data _U_)
{
switch (pref->type) {
case PREF_UINT:
pref->saved_val.uint = *pref->varp.uint;
break;
case PREF_BOOL:
pref->saved_val.boolval = *pref->varp.boolp;
break;
case PREF_ENUM:
pref->saved_val.enumval = *pref->varp.enump;
break;
case PREF_STRING:
case PREF_FILENAME:
g_free(pref->saved_val.string);
pref->saved_val.string = g_strdup(*pref->varp.string);
break;
case PREF_RANGE:
g_free(pref->saved_val.range);
pref->saved_val.range = range_copy(*pref->varp.range);
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_copy(module_t *module, gpointer user_data _U_)
{
prefs_pref_foreach(module, pref_copy, NULL);
return 0;
}
static void prefs_copy(void) {
free_prefs(&saved_prefs);
copy_prefs(&saved_prefs, &prefs);
prefs_modules_foreach(module_prefs_copy, NULL);
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
#ifdef HAVE_AIRPCAP
airpcap_load_decryption_keys(airpcap_if_list);
#endif
}
static void
prefs_main_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all(parent_w, &must_redissect))
return;
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
prefs_main_apply_all(parent_w, must_redissect);
prefs_to_capture_opts();
#ifdef HAVE_AIRPCAP
prefs_airpcap_update();
#endif
window_destroy(GTK_WIDGET(parent_w));
if (must_redissect) {
redissect_packets();
}
}
static void
prefs_main_apply_cb(GtkWidget *apply_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all(parent_w, &must_redissect))
return;
if (!prefs.gui_use_pref_save) {
prefs_main_write();
prefs_copy();
}
prefs_main_apply_all(parent_w, must_redissect);
prefs_to_capture_opts();
#ifdef HAVE_AIRPCAP
prefs_airpcap_update();
#endif
if (must_redissect) {
redissect_packets();
}
}
static void
prefs_main_save_cb(GtkWidget *save_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all(parent_w, &must_redissect))
return;
prefs_main_write();
prefs_copy();
prefs_main_apply_all(parent_w, must_redissect);
prefs_to_capture_opts();
if (must_redissect) {
redissect_packets();
}
}
static guint
pref_revert(pref_t *pref, gpointer user_data)
{
gboolean *pref_changed_p = user_data;
switch (pref->type) {
case PREF_UINT:
if (*pref->varp.uint != pref->saved_val.uint) {
*pref_changed_p = TRUE;
*pref->varp.uint = pref->saved_val.uint;
}
break;
case PREF_BOOL:
if (*pref->varp.boolp != pref->saved_val.boolval) {
*pref_changed_p = TRUE;
*pref->varp.boolp = pref->saved_val.boolval;
}
break;
case PREF_ENUM:
if (*pref->varp.enump != pref->saved_val.enumval) {
*pref_changed_p = TRUE;
*pref->varp.enump = pref->saved_val.enumval;
}
break;
case PREF_STRING:
case PREF_FILENAME:
if (strcmp(*pref->varp.string, pref->saved_val.string) != 0) {
*pref_changed_p = TRUE;
g_free((void *)*pref->varp.string);
*pref->varp.string = g_strdup(pref->saved_val.string);
}
break;
case PREF_RANGE:
if (!ranges_are_equal(*pref->varp.range, pref->saved_val.range)) {
*pref_changed_p = TRUE;
g_free(*pref->varp.range);
*pref->varp.range = range_copy(pref->saved_val.range);
}
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_revert(module_t *module, gpointer user_data)
{
gboolean *must_redissect_p = user_data;
module->prefs_changed = FALSE;
prefs_pref_foreach(module, pref_revert, &module->prefs_changed);
if (module->prefs_changed)
*must_redissect_p = TRUE;
return 0;
}
static void
prefs_main_cancel_cb(GtkWidget *cancel_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
free_prefs(&prefs);
copy_prefs(&prefs, &saved_prefs);
cfile.cinfo.columns_changed = FALSE;
prefs_modules_foreach(module_prefs_revert, &must_redissect);
prefs_main_apply_all(parent_w, must_redissect);
window_destroy(GTK_WIDGET(parent_w));
if (must_redissect) {
redissect_packets();
}
}
static gboolean
prefs_main_delete_event_cb(GtkWidget *prefs_w_lcl, GdkEvent *event _U_,
gpointer user_data _U_)
{
prefs_main_cancel_cb(NULL, prefs_w_lcl);
return FALSE;
}
static void
prefs_main_destroy_cb(GtkWidget *win _U_, gpointer parent_w)
{
prefs_main_destroy_all(parent_w);
prefs_w = NULL;
}
static guint
module_search_properties(module_t *module, gpointer user_data)
{
struct properties_data *p = (struct properties_data *)user_data;
if (strcmp(module->title, p->title) == 0) {
p->module = module;
return 1;
}
if(prefs_module_has_submodules(module))
return prefs_modules_foreach_submodules(module, module_search_properties, p);
return 0;
}
static void
tree_expand_row(GtkTreeModel *model, GtkTreeView *tree_view, GtkTreeIter *iter)
{
GtkTreeIter parent;
GtkTreePath *path;
if(gtk_tree_model_iter_parent(model, &parent, iter))
tree_expand_row(model, tree_view, &parent);
path = gtk_tree_model_get_path(model, iter);
gtk_tree_view_expand_row(tree_view, path, FALSE);
gtk_tree_path_free(path);
}
static void
tree_select_node(GtkWidget *tree, prefs_tree_iter *iter)
{
GtkTreeIter local_iter = *iter;
GtkTreeView *tree_view = GTK_TREE_VIEW(tree);
GtkTreeModel *model;
GtkTreePath *first_path;
model = gtk_tree_view_get_model(tree_view);
first_path = gtk_tree_model_get_path(model, &local_iter);
tree_expand_row(model, tree_view, &local_iter);
gtk_tree_selection_select_path(gtk_tree_view_get_selection(tree_view),
first_path);
gtk_tree_view_scroll_to_cell(tree_view, first_path, NULL, TRUE, 0.5f, 0.0f);
gtk_tree_path_free(first_path);
}
void
properties_cb(GtkWidget *w, gpointer dummy)
{
header_field_info *hfinfo;
const gchar *title;
struct properties_data p;
int page_num;
GtkWidget *sw;
GtkWidget *frame;
module_t *page_module;
if (cfile.finfo_selected == NULL) {
return;
}
hfinfo = cfile.finfo_selected->hfinfo;
if (hfinfo->parent == -1)
title = prefs_get_title_by_name(hfinfo->abbrev);
else
title = prefs_get_title_by_name(proto_registrar_get_abbrev(hfinfo->parent));
if (!title)
return;
p.title = title;
p.module = NULL;
prefs_modules_foreach_submodules(protocols_module, module_search_properties,
&p);
if (p.module == NULL) {
return;
}
if (prefs_w != NULL) {
reactivate_window(prefs_w);
} else {
prefs_cb(w, dummy);
}
for (page_num = 0;
(sw = gtk_notebook_get_nth_page(g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page_num)) != NULL;
page_num++) {
frame = g_object_get_data(G_OBJECT(sw), E_PAGESW_FRAME_KEY);
if(frame) {
page_module = g_object_get_data(G_OBJECT(frame), E_PAGE_MODULE_KEY);
if (page_module != NULL) {
if (page_module == p.module) {
tree_select_node(
g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_TREE_KEY),
g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY));
return;
}
}
}
}
}
static void
prefs_tree_select_cb(GtkTreeSelection *sel, gpointer dummy _U_)
{
gint page;
GtkTreeModel *model;
GtkTreeIter iter;
if (gtk_tree_selection_get_selected(sel, &model, &iter))
{
gtk_tree_model_get(model, &iter, 1, &page, -1);
if (page >= 0)
gtk_notebook_set_current_page(g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page);
}
}
