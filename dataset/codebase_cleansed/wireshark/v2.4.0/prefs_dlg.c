static guint
pref_exists(pref_t *pref _U_, gpointer user_data _U_)
{
return 1;
}
static guint
pref_show(pref_t *pref, gpointer user_data)
{
GtkWidget *main_grid = (GtkWidget *)user_data;
module_t *module = (module_t *)g_object_get_data(G_OBJECT(main_grid), E_GRID_MODULE_KEY);
const char *title;
const char *type_name = prefs_pref_type_name(pref);
char *label_string;
size_t label_len;
char *uint_str;
char *tooltip_txt;
title = prefs_get_title(pref);
label_len = strlen(title) + 2;
label_string = (char *)g_malloc(label_len);
g_strlcpy(label_string, title, label_len);
tooltip_txt = prefs_get_description(pref) ? g_strdup_printf("%s\n\nName: %s.%s\nType: %s",
prefs_get_description(pref),
module->name,
prefs_get_name(pref),
type_name ? type_name : "Unknown"
): NULL;
if (prefs_get_type(pref) != PREF_STATIC_TEXT)
g_strlcat(label_string, ":", label_len);
pref_stash(pref, NULL);
switch (prefs_get_type(pref)) {
case PREF_UINT:
case PREF_DECODE_AS_UINT:
uint_str = prefs_pref_to_str(pref, pref_stashed);
prefs_set_control(pref, create_preference_entry(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
uint_str));
g_free(uint_str);
break;
case PREF_BOOL:
prefs_set_control(pref, create_preference_check_button(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
prefs_get_bool_value(pref, pref_stashed)));
break;
case PREF_ENUM:
if (prefs_get_enum_radiobuttons(pref)) {
prefs_set_control(pref, create_preference_radio_buttons(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
prefs_get_enumvals(pref),
prefs_get_enum_value(pref, pref_stashed)));
} else {
prefs_set_control(pref, create_preference_option_menu(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
prefs_get_enumvals(pref),
prefs_get_enum_value(pref, pref_stashed)));
}
break;
case PREF_STRING:
prefs_set_control(pref, create_preference_entry(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
prefs_get_string_value(pref, pref_stashed)));
break;
case PREF_SAVE_FILENAME:
case PREF_OPEN_FILENAME:
prefs_set_control(pref, create_preference_path_entry(main_grid, prefs_get_ordinal(pref),
label_string,
tooltip_txt,
prefs_get_string_value(pref, pref_stashed), FALSE));
break;
case PREF_DIRNAME:
prefs_set_control(pref, create_preference_path_entry(main_grid, prefs_get_ordinal(pref),
label_string,
tooltip_txt,
prefs_get_string_value(pref, pref_stashed), TRUE));
break;
case PREF_RANGE:
case PREF_DECODE_AS_RANGE:
{
char *range_str_p;
range_str_p = range_convert_range(NULL, prefs_get_range_value_real(pref, pref_current));
prefs_set_control(pref, create_preference_entry(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
range_str_p));
wmem_free(NULL, range_str_p);
break;
}
case PREF_STATIC_TEXT:
{
prefs_set_control(pref, create_preference_static_text(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt));
break;
}
case PREF_UAT:
{
if (prefs_get_gui_type(pref) == GUI_ALL || prefs_get_gui_type(pref) == GUI_GTK)
prefs_set_control(pref, create_preference_uat(main_grid, prefs_get_ordinal(pref),
label_string, tooltip_txt,
prefs_get_uat_value(pref)));
break;
}
case PREF_COLOR:
case PREF_CUSTOM:
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
g_free(tooltip_txt);
g_free(label_string);
return 0;
}
static prefs_tree_iter
prefs_tree_page_add(const gchar *title, gint page_nr,
gpointer store, prefs_tree_iter *parent_iter)
{
prefs_tree_iter iter;
gtk_tree_store_append((GtkTreeStore *)store, &iter, parent_iter);
gtk_tree_store_set((GtkTreeStore *)store, &iter, 0, title, 1, page_nr, -1);
return iter;
}
static GtkWidget *
prefs_nb_page_add(GtkWidget *notebook, const gchar *title _U_, GtkWidget *page, const char *page_key)
{
GtkWidget *sw;
GtkWidget *frame;
sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_widget_show(sw);
frame = gtk_frame_new(NULL);
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_NONE);
gtk_container_set_border_width(GTK_CONTAINER(frame), DLG_OUTER_MARGIN);
#if ! GTK_CHECK_VERSION(3,8,0)
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(sw), frame);
#else
gtk_container_add(GTK_CONTAINER(sw), frame);
#endif
gtk_widget_show(frame);
if (page) {
gtk_container_add(GTK_CONTAINER(frame), page);
g_object_set_data(G_OBJECT(prefs_w), page_key, page);
}
gtk_notebook_append_page (GTK_NOTEBOOK(notebook), sw, NULL);
return sw;
}
static guint
module_prefs_show(module_t *module, gpointer user_data)
{
struct ct_struct *cts = (struct ct_struct *)user_data;
struct ct_struct child_cts;
GtkWidget *main_vb, *main_grid, *frame, *main_sw;
gchar label_str[MAX_TREE_NODE_NAME_LEN];
GtkTreeStore *model;
GtkTreeIter iter;
if (!module->use_gui) {
return 0;
}
if (!prefs_module_has_submodules(module)) {
if (prefs_pref_foreach(module, pref_exists, NULL) == 0) {
return 0;
}
}
g_strlcpy(label_str, module->title, MAX_TREE_NODE_NAME_LEN);
model = GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cts->tree)));
if (module->parent == NULL)
gtk_tree_store_append(model, &iter, NULL);
else
gtk_tree_store_append(model, &iter, &cts->iter);
if (prefs_module_has_submodules(module)) {
gtk_tree_store_set(model, &iter, 0, label_str, 1, -1, -1);
child_cts = *cts;
child_cts.iter = iter;
prefs_modules_foreach_submodules(module, module_prefs_show, &child_cts);
cts->page = child_cts.page;
}
main_sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(main_sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
frame = gtk_frame_new(NULL);
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_NONE);
gtk_container_set_border_width(GTK_CONTAINER(frame), DLG_OUTER_MARGIN);
#if ! GTK_CHECK_VERSION(3,8,0)
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(main_sw), frame);
#else
gtk_container_add(GTK_CONTAINER(main_sw), frame);
#endif
g_object_set_data(G_OBJECT(main_sw), E_PAGESW_FRAME_KEY, frame);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(frame), main_vb);
main_grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_grid, FALSE, FALSE, 0);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_set_vexpand(GTK_WIDGET(main_grid), FALSE);
#endif
ws_gtk_grid_set_row_spacing(GTK_GRID(main_grid), 10);
ws_gtk_grid_set_column_spacing(GTK_GRID(main_grid), 15);
g_object_set_data(G_OBJECT(main_grid), E_GRID_MODULE_KEY, module);
prefs_pref_foreach(module, pref_show, main_grid);
g_object_set_data(G_OBJECT(main_grid), E_GRID_MODULE_KEY, NULL);
g_object_set_data(G_OBJECT(frame), E_PAGE_MODULE_KEY, module);
gtk_notebook_append_page(GTK_NOTEBOOK(cts->notebook), main_sw, NULL);
gtk_tree_store_set(model, &iter, 0, label_str, 1, cts->page, -1);
g_object_set_data(G_OBJECT(frame), E_PAGE_ITER_KEY, gtk_tree_iter_copy(&iter));
cts->page++;
gtk_widget_show_all(main_sw);
return 0;
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
gchar label_str[MAX_TREE_NODE_NAME_LEN];
struct ct_struct cts;
GtkTreeStore *store;
GtkTreeSelection *selection;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
gint col_offset;
prefs_tree_iter gui_iter, layout_iter, columns_iter, capture_iter;
gint layout_page, columns_page;
gint capture_page = 0;
if (prefs_w != NULL) {
reactivate_window(prefs_w);
return;
}
prefs_w = dlg_conf_window_new("Wireshark: Preferences");
gtk_window_set_default_size(GTK_WINDOW(prefs_w), 400, 650);
cts.main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(cts.main_vb), 5);
gtk_container_add(GTK_CONTAINER(prefs_w), cts.main_vb);
gtk_widget_show(cts.main_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_box_pack_start(GTK_BOX(cts.main_vb), top_hb, TRUE, TRUE, 0);
gtk_widget_show(top_hb);
ct_sb = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(ct_sb),
GTK_SHADOW_IN);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ct_sb),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_box_pack_start(GTK_BOX(top_hb), ct_sb, TRUE, TRUE, 0);
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
gtk_box_pack_start(GTK_BOX(top_hb), prefs_nb, TRUE, TRUE, 0);
gtk_widget_show(prefs_nb);
cts.page = 0;
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
g_strlcpy(label_str, "Font and Colors", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, font_color_prefs_show(), E_GUI_FONT_COLORS_PAGE_KEY);
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
capture_iter = prefs_tree_page_add(label_str, cts.page, store, NULL);
capture_page = cts.page++;
#ifdef _WIN32
}
#endif
#endif
g_strlcpy(label_str, "Filter Expressions", MAX_TREE_NODE_NAME_LEN);
prefs_nb_page_add(prefs_nb, label_str, filter_expressions_prefs_show(),
E_FILTER_EXPRESSIONS_PAGE_KEY);
prefs_tree_page_add(label_str, cts.page, store, NULL);
cts.page++;
cts.notebook = prefs_nb;
cts.store = store;
prefs_modules_foreach_submodules(NULL, module_prefs_show, &cts);
bbox = dlg_button_row_new(GTK_STOCK_HELP, GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(cts.main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(prefs_main_ok_cb), prefs_w);
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(prefs_main_apply_cb), prefs_w);
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(prefs_main_save_cb), prefs_w);
g_object_set_data(G_OBJECT(prefs_w), E_PREFSW_SAVE_BT_KEY, save_bt);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(prefs_main_cancel_cb), prefs_w);
window_set_cancel_button(prefs_w, cancel_bt, NULL);
gtk_widget_grab_default(ok_bt);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_PREFERENCES_DIALOG);
g_signal_connect(prefs_w, "delete_event", G_CALLBACK(prefs_main_delete_event_cb), NULL);
g_signal_connect(prefs_w, "destroy", G_CALLBACK(prefs_main_destroy_cb), prefs_w);
gtk_widget_show(prefs_w);
if (!prefs.gui_use_pref_save) {
gtk_widget_hide(save_bt);
}
window_present(prefs_w);
switch (prefs_page) {
case PREFS_PAGE_LAYOUT:
gtk_tree_selection_select_iter(selection, &layout_iter);
gtk_notebook_set_current_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), layout_page);
break;
case PREFS_PAGE_COLUMNS:
gtk_tree_selection_select_iter(selection, &columns_iter);
gtk_notebook_set_current_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), columns_page);
break;
case PREFS_PAGE_CAPTURE:
if (capture_page) {
gtk_tree_selection_select_iter(selection, &capture_iter);
gtk_notebook_set_current_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), capture_page);
}
break;
default:
break;
}
g_object_unref(G_OBJECT(store));
}
static void
set_option_label(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text)
{
GtkWidget *label;
GtkWidget *event_box;
label = gtk_label_new(label_text);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
gtk_widget_show(label);
event_box = gtk_event_box_new();
gtk_event_box_set_visible_window (GTK_EVENT_BOX(event_box), FALSE);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), event_box, 0, grid_position, 1, 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(event_box, tooltip_text);
gtk_container_add(GTK_CONTAINER(event_box), label);
gtk_widget_show(event_box);
}
GtkWidget *
create_preference_check_button(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text, gboolean active)
{
GtkWidget *check_box;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
check_box = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_box), active);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), check_box, 1, grid_position, 1, 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(check_box, tooltip_text);
return check_box;
}
GtkWidget *
create_preference_radio_buttons(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text,
const enum_val_t *enumvals, gint current_val)
{
GtkWidget *radio_button_hbox, *button = NULL;
GSList *rb_group;
int idx;
const enum_val_t *enum_valp;
GtkWidget *event_box;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
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
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), event_box, 1, grid_position, 1, 1);
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
button = (GtkWidget *)rb_entry->data;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button)))
break;
}
return label_to_enum_val(gtk_bin_get_child(GTK_BIN(button)), enumvals);
}
GtkWidget *
create_preference_option_menu(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text,
const enum_val_t *enumvals, gint current_val)
{
GtkWidget *menu_box, *combo_box;
int menu_idx, idx;
const enum_val_t *enum_valp;
GtkWidget *event_box;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
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
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), event_box, 1, grid_position, 1, 1);
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
create_preference_entry(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text, char *value)
{
GtkWidget *entry;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
entry = gtk_entry_new();
if (value != NULL)
gtk_entry_set_text(GTK_ENTRY(entry), value);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), entry, 1, grid_position, 1, 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(entry, tooltip_text);
gtk_widget_show(entry);
return entry;
}
static void
preference_filename_entry_cb(GtkWidget *button, GtkWidget *filename_te)
{
file_selection_browse(button, filename_te, "Wireshark: File preference",
FILE_SELECTION_READ_BROWSE);
}
static void
preference_dirname_entry_cb(GtkWidget *button, GtkWidget *filename_te)
{
file_selection_browse(button, filename_te, "Wireshark: Directory preference",
FILE_SELECTION_CREATE_FOLDER);
}
static GtkWidget *
create_preference_path_entry(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text, char *value, gboolean dir_only)
{
GtkWidget *entry;
GtkWidget *button, *file_bt_hb;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
file_bt_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), file_bt_hb, 1, grid_position, 1, 1);
gtk_widget_show(file_bt_hb);
button = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_BROWSE);
gtk_box_pack_end(GTK_BOX(file_bt_hb), button, FALSE, FALSE, 0);
gtk_widget_show(button);
entry = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(file_bt_hb), entry, TRUE, TRUE, 0);
if (value != NULL)
gtk_entry_set_text(GTK_ENTRY(entry), value);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(entry, tooltip_text);
gtk_widget_show(entry);
if (dir_only) {
g_signal_connect(button, "clicked", G_CALLBACK(preference_dirname_entry_cb), entry);
} else {
g_signal_connect(button, "clicked", G_CALLBACK(preference_filename_entry_cb), entry);
}
return entry;
}
GtkWidget *
create_preference_static_text(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text)
{
GtkWidget *label;
if (label_text != NULL) {
label = gtk_label_new(label_text);
gtk_label_set_line_wrap (GTK_LABEL (label), TRUE);
gtk_label_set_width_chars (GTK_LABEL (label), 80);
} else {
label = gtk_label_new("");
}
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), label, 0, grid_position, 2, 1);
if (tooltip_text != NULL)
gtk_widget_set_tooltip_text(label, tooltip_text);
gtk_widget_show(label);
return label;
}
GtkWidget *
create_preference_uat(GtkWidget *main_grid, int grid_position,
const gchar *label_text, const gchar *tooltip_text, void* uat)
{
GtkWidget *button;
set_option_label(main_grid, grid_position, label_text, tooltip_text);
button = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_EDIT);
g_signal_connect(button, "clicked", G_CALLBACK(uat_window_cb), uat);
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), button, 1, grid_position, 1, 1);
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
pref_t **badpref = (pref_t **)user_data;
switch (prefs_get_type(pref)) {
case PREF_UINT:
case PREF_DECODE_AS_UINT:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
errno = 0;
if (strtoul(str_val, &p, prefs_get_uint_base(pref))){}
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
case PREF_SAVE_FILENAME:
case PREF_OPEN_FILENAME:
case PREF_DIRNAME:
break;
case PREF_RANGE:
case PREF_DECODE_AS_RANGE:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
if (strlen(str_val) != 0) {
range_t *newrange;
if (range_convert_str(NULL, &newrange, str_val, prefs_get_max_value(pref)) != CVT_NO_ERROR) {
*badpref = pref;
wmem_free(NULL, newrange);
return PREFS_SET_SYNTAX_ERR;
}
wmem_free(NULL, newrange);
}
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_COLOR:
case PREF_CUSTOM:
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_check(module_t *module, gpointer user_data)
{
if (!module->use_gui) {
return 0;
}
return prefs_pref_foreach(module, pref_check, user_data);
}
static guint
pref_fetch(pref_t *pref, gpointer user_data)
{
const char *str_val;
char *p;
guint uval, uval_stashed;
gboolean bval;
gint enumval;
module_t *module = (module_t *)user_data;
pref_unstash_data_t unstash_data;
switch (prefs_get_type(pref)) {
case PREF_DECODE_AS_UINT:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
uval = (guint)strtoul(str_val, &p, prefs_get_uint_base(pref));
#if 0
if (p == value || *p != '\0')
return PREFS_SET_SYNTAX_ERR;
#endif
uval_stashed = prefs_get_uint_value_real(pref, pref_stashed);
prefs_set_uint_value(pref, uval, pref_stashed);
unstash_data.module = module;
unstash_data.handle_decode_as = TRUE;
pref_unstash(pref, (gpointer)&unstash_data);
prefs_set_uint_value(pref, uval_stashed, pref_stashed);
break;
case PREF_UINT:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
uval = (guint)strtoul(str_val, &p, prefs_get_uint_base(pref));
#if 0
if (p == value || *p != '\0')
return PREFS_SET_SYNTAX_ERR;
#endif
module->prefs_changed |= prefs_set_uint_value(pref, uval, pref_current);
break;
case PREF_BOOL:
bval = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(prefs_get_control(pref)));
module->prefs_changed |= prefs_set_bool_value(pref, bval, pref_current);
break;
case PREF_ENUM:
if (prefs_get_enum_radiobuttons(pref)) {
enumval = fetch_preference_radio_buttons_val((GtkWidget *)prefs_get_control(pref),
prefs_get_enumvals(pref));
} else {
enumval = fetch_preference_option_menu_val((GtkWidget *)prefs_get_control(pref),
prefs_get_enumvals(pref));
}
module->prefs_changed |= prefs_set_enum_value(pref, enumval, pref_current);
break;
case PREF_STRING:
case PREF_SAVE_FILENAME:
case PREF_OPEN_FILENAME:
case PREF_DIRNAME:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
module->prefs_changed |= prefs_set_string_value(pref, str_val, pref_current);
break;
case PREF_DECODE_AS_RANGE:
{
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
module->prefs_changed |= prefs_set_stashed_range_value(pref, str_val);
unstash_data.module = module;
unstash_data.handle_decode_as = TRUE;
pref_unstash(pref, (gpointer)&unstash_data);
break;
}
case PREF_RANGE:
str_val = gtk_entry_get_text(GTK_ENTRY(prefs_get_control(pref)));
if (!prefs_set_range_value_work(pref, str_val, TRUE, &module->prefs_changed))
#if 0
return PREFS_SET_SYNTAX_ERR;
#else
return 0;
#endif
break;
case PREF_STATIC_TEXT:
case PREF_UAT:
break;
case PREF_COLOR:
case PREF_CUSTOM:
case PREF_OBSOLETE:
g_assert_not_reached();
break;
}
return 0;
}
static guint
module_prefs_fetch(module_t *module, gpointer user_data)
{
gboolean *must_redissect_p = (gboolean *)user_data;
if (!module->use_gui) {
return 0;
}
module->prefs_changed = FALSE;
prefs_pref_foreach(module, pref_fetch, module);
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
decryption_cm = GTK_WIDGET(g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY));
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
if (wireshark_decryption_is_now_enabled && airpcap_decryption_was_enabled)
{
set_airpcap_decryption(FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 1);
}
if (wireshark_decryption_is_now_enabled && !airpcap_decryption_was_enabled)
{
set_airpcap_decryption(FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(decryption_cm), 1);
}
else if (!wireshark_decryption_is_now_enabled && wireshark_decryption_was_enabled)
{
if (airpcap_decryption_was_enabled)
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
module_prefs_clean_stash(module_t *module, gpointer user_data _U_)
{
if (!module->use_gui) {
return 0;
}
prefs_pref_foreach(module, pref_clean_stash, NULL);
return 0;
}
static gboolean
prefs_main_fetch_all(GtkWidget *dlg, gboolean *must_redissect)
{
pref_t *badpref;
switch (prefs_modules_foreach(module_prefs_check, (gpointer)&badpref)) {
case PREFS_SET_SYNTAX_ERR:
switch (prefs_get_type(badpref)) {
case PREF_UINT:
case PREF_DECODE_AS_UINT:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value for \"%s\" isn't a valid number.",
prefs_get_title(badpref));
return FALSE;
case PREF_RANGE:
case PREF_DECODE_AS_RANGE:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The value for \"%s\" isn't a valid range.",
prefs_get_title(badpref));
return FALSE;
default:
g_assert_not_reached();
break;
}
}
gui_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY));
layout_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
font_color_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_FONT_COLORS_PAGE_KEY));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
filter_expressions_prefs_fetch((GtkWidget *)g_object_get_data(G_OBJECT(dlg),
E_FILTER_EXPRESSIONS_PAGE_KEY));
prefs_modules_foreach(module_prefs_fetch, must_redissect);
return TRUE;
}
static void
prefs_main_apply_all(GtkWidget *dlg, gboolean redissect)
{
GtkWidget *save_bt;
prefs_apply_all();
gui_prefs_apply((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY));
layout_prefs_apply((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_apply((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
font_color_prefs_apply((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_FONT_COLORS_PAGE_KEY), redissect);
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_apply((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_SAVE_BT_KEY);
if (prefs.gui_use_pref_save) {
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
(frame = gtk_notebook_get_nth_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page_num)) != NULL;
page_num++) {
if (g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY))
gtk_tree_iter_free((GtkTreeIter *)g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY));
}
gui_prefs_destroy((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_PAGE_KEY));
layout_prefs_destroy((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_LAYOUT_PAGE_KEY));
column_prefs_destroy((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_COLUMN_PAGE_KEY));
font_color_prefs_destroy((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_GUI_FONT_COLORS_PAGE_KEY));
#ifdef HAVE_LIBPCAP
#ifdef _WIN32
if (has_wpcap) {
#endif
capture_prefs_destroy((GtkWidget *)g_object_get_data(G_OBJECT(dlg), E_CAPTURE_PAGE_KEY));
#ifdef _WIN32
}
#endif
#endif
prefs_modules_foreach(module_prefs_clean_stash, NULL);
}
static guint
module_prefs_copy(module_t *module, gpointer user_data _U_)
{
if (!module->use_gui) {
return 0;
}
prefs_pref_foreach(module, pref_stash, NULL);
return 0;
}
static void prefs_copy(void) {
prefs_modules_foreach(module_prefs_copy, NULL);
}
static void
overwrite_existing_prefs_cb(gpointer dialog _U_, gint btn, gpointer parent_w _U_)
{
gchar* err = NULL;
switch (btn) {
case(ESD_BTN_SAVE):
prefs_main_write();
prefs.unknown_prefs = FALSE;
if (save_decode_as_entries(&err) < 0)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err);
g_free(err);
}
break;
case(ESD_BTN_DONT_SAVE):
break;
default:
g_assert_not_reached();
}
}
static void
prefs_main_save(gpointer parent_w)
{
gchar* err = NULL;
if (prefs.unknown_prefs) {
gpointer dialog;
const gchar *msg =
"Obsolete or unrecognized preferences have been detected and will be "
"discarded when saving this profile. If you would like to preserve "
"these preferences for a different Wireshark version, click "
"'Continue without Saving' and save this profile under a different name.";
if (prefs.saved_at_version) {
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_SAVE_DONTSAVE,
"These preferences were last saved at version \"%s\".\n%s",
prefs.saved_at_version, msg);
} else {
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_SAVE_DONTSAVE,
"%s", msg);
}
simple_dialog_set_cb(dialog, overwrite_existing_prefs_cb, parent_w);
} else {
prefs_main_write();
if (save_decode_as_entries(&err) < 0)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err);
g_free(err);
}
}
}
static void
prefs_main_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all((GtkWidget *)parent_w, &must_redissect))
return;
if (!prefs.gui_use_pref_save) {
prefs_main_save(parent_w);
}
#ifdef HAVE_AIRPCAP
airpcap_load_decryption_keys(g_airpcap_if_list);
#endif
prefs_main_apply_all((GtkWidget *)parent_w, must_redissect);
prefs_to_capture_opts();
#ifdef HAVE_AIRPCAP
prefs_airpcap_update();
#endif
window_destroy(GTK_WIDGET(parent_w));
if (must_redissect) {
redissect_packets();
redissect_all_packet_windows();
}
}
static void
prefs_main_apply_cb(GtkWidget *apply_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all((GtkWidget *)parent_w, &must_redissect))
return;
if (!prefs.gui_use_pref_save) {
prefs_main_save(parent_w);
prefs_copy();
}
prefs_main_apply_all((GtkWidget *)parent_w, must_redissect);
prefs_to_capture_opts();
#ifdef HAVE_AIRPCAP
prefs_airpcap_update();
#endif
if (must_redissect) {
redissect_packets();
redissect_all_packet_windows();
}
}
static void
prefs_main_save_cb(GtkWidget *save_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
if (!prefs_main_fetch_all((GtkWidget *)parent_w, &must_redissect))
return;
prefs_main_save(parent_w);
prefs_copy();
prefs_main_apply_all((GtkWidget *)parent_w, must_redissect);
prefs_to_capture_opts();
if (must_redissect) {
redissect_packets();
redissect_all_packet_windows();
}
}
static guint
module_prefs_revert(module_t *module, gpointer user_data)
{
gboolean *must_redissect_p = (gboolean *)user_data;
pref_unstash_data_t unstashed_data;
if (!module->use_gui) {
return 0;
}
module->prefs_changed = FALSE;
unstashed_data.module = module;
unstashed_data.handle_decode_as = FALSE;
prefs_pref_foreach(module, pref_unstash, &unstashed_data);
if (module->prefs_changed)
*must_redissect_p = TRUE;
return 0;
}
static void
prefs_main_cancel_cb(GtkWidget *cancel_bt _U_, gpointer parent_w)
{
gboolean must_redissect = FALSE;
cfile.columns_changed = FALSE;
prefs_modules_foreach(module_prefs_revert, &must_redissect);
prefs_main_apply_all((GtkWidget *)parent_w, must_redissect);
window_destroy(GTK_WIDGET(parent_w));
if (must_redissect) {
redissect_packets();
redissect_all_packet_windows();
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
prefs_main_destroy_all((GtkWidget *)parent_w);
prefs_w = NULL;
}
static guint
module_search_properties(module_t *module, gpointer user_data)
{
struct properties_data *p = (struct properties_data *)user_data;
if (!module->use_gui) {
return 0;
}
if (strcmp(module->title, p->title) == 0) {
p->module = module;
return 1;
}
if (prefs_module_has_submodules(module))
return prefs_modules_foreach_submodules(module, module_search_properties, p);
return 0;
}
static void
tree_expand_row(GtkTreeModel *model, GtkTreeView *tree_view, GtkTreeIter *iter)
{
GtkTreeIter parent;
GtkTreePath *path;
if (gtk_tree_model_iter_parent(model, &parent, iter))
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
const gchar *title = NULL;
struct properties_data p;
int page_num;
GtkWidget *sw;
GtkWidget *frame;
module_t *page_module;
if (cfile.finfo_selected == NULL) {
const gchar *abbrev;
if (cfile.edt && cfile.edt->tree) {
GPtrArray *ga;
field_info *v;
guint i;
ga = proto_all_finfos(cfile.edt->tree);
for (i = ga->len - 1; i > 0 ; i -= 1) {
v = (field_info *)g_ptr_array_index (ga, i);
hfinfo = v->hfinfo;
if (!g_str_has_prefix(hfinfo->abbrev, "text") &&
!g_str_has_prefix(hfinfo->abbrev, "_ws.expert") &&
!g_str_has_prefix(hfinfo->abbrev, "_ws.malformed")) {
if (hfinfo->parent == -1) {
abbrev = hfinfo->abbrev;
} else {
abbrev = proto_registrar_get_abbrev(hfinfo->parent);
}
title = prefs_get_title_by_name(abbrev);
break;
}
}
}
} else {
hfinfo = cfile.finfo_selected->hfinfo;
if (hfinfo->parent == -1)
title = prefs_get_title_by_name(hfinfo->abbrev);
else
title = prefs_get_title_by_name(proto_registrar_get_abbrev(hfinfo->parent));
}
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
(sw = gtk_notebook_get_nth_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page_num)) != NULL;
page_num++) {
frame = (GtkWidget *)g_object_get_data(G_OBJECT(sw), E_PAGESW_FRAME_KEY);
if (frame) {
page_module = (module_t *)g_object_get_data(G_OBJECT(frame), E_PAGE_MODULE_KEY);
if (page_module != NULL) {
if (page_module == p.module) {
tree_select_node(
(GtkWidget *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_TREE_KEY),
(GtkTreeIter *)g_object_get_data(G_OBJECT(frame), E_PAGE_ITER_KEY));
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
gtk_notebook_set_current_page((GtkNotebook *)g_object_get_data(G_OBJECT(prefs_w), E_PREFSW_NOTEBOOK_KEY), page);
}
}
