static void
visible_toggled(GtkCellRendererToggle *cell _U_, gchar *path_str, gpointer data)
{
GtkTreeModel *model = (GtkTreeModel *)data;
GtkTreeIter iter;
GtkTreePath *path = gtk_tree_path_new_from_string(path_str);
GList *clp;
fmt_data *cfmt;
gtk_tree_model_get_iter(model, &iter, path);
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
cfmt = (fmt_data *) clp->data;
if (cfmt->visible)
cfmt->visible = FALSE;
else
cfmt->visible = TRUE;
gtk_list_store_set(GTK_LIST_STORE(model), &iter, VISIBLE_COLUMN, cfmt->visible, -1);
cfile.columns_changed = TRUE;
gtk_tree_path_free(path);
}
GtkWidget *
column_prefs_show(GtkWidget *prefs_window) {
GtkWidget *main_vb, *bottom_hb, *column_l, *add_bt, *grid, *lb;
GtkWidget *list_vb, *list_lb, *list_sc;
GtkWidget *add_remove_vb;
GtkWidget *props_fr, *props_hb;
GList *clp;
fmt_data *cfmt;
gint i;
gchar *fmt;
const gchar *column_titles[] = {"Displayed", "Title", "Field type"};
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
GtkTreeIter iter;
GtkTreeIter first_iter;
gint first_row = TRUE;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_widget_show(main_vb);
list_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (list_vb), 5);
gtk_widget_show (list_vb);
gtk_box_pack_start (GTK_BOX (main_vb), list_vb, TRUE, TRUE, 0);
list_lb = gtk_label_new (
"[The first list entry will be displayed as the leftmost column"
" - Drag and drop entries to change column order]");
gtk_widget_show (list_lb);
gtk_box_pack_start (GTK_BOX (list_vb), list_lb, FALSE, FALSE, 0);
list_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(list_sc), GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(list_vb), list_sc, TRUE, TRUE, 0);
gtk_widget_show(list_sc);
store = gtk_list_store_new(N_COLUMN,
G_TYPE_BOOLEAN,
G_TYPE_STRING, G_TYPE_STRING, G_TYPE_POINTER);
column_row_deleted_handler_id =
g_signal_connect(GTK_TREE_MODEL(store), "row-deleted", G_CALLBACK(column_dnd_row_deleted_cb), NULL);
column_l = tree_view_new(GTK_TREE_MODEL(store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(column_l), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(column_l), FALSE);
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(column_l), TRUE);
gtk_widget_set_tooltip_text(column_l, "Click on a title to change its name.\nDrag an item to change its order.");
renderer = gtk_cell_renderer_toggle_new();
g_signal_connect(renderer, "toggled", G_CALLBACK(visible_toggled), store);
column = gtk_tree_view_column_new_with_attributes(column_titles[VISIBLE_COLUMN], renderer, "active", VISIBLE_COLUMN, NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(GTK_TREE_VIEW(column_l), column);
renderer = gtk_cell_renderer_text_new();
g_object_set(G_OBJECT(renderer), "editable", TRUE, NULL);
g_signal_connect (renderer, "edited", G_CALLBACK(column_title_changed_cb), GTK_TREE_MODEL(store));
column = gtk_tree_view_column_new_with_attributes(column_titles[TITLE_COLUMN], renderer, "text", TITLE_COLUMN, NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(GTK_TREE_VIEW(column_l), column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(column_titles[FORMAT_COLUMN], renderer, "text", FORMAT_COLUMN, NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(GTK_TREE_VIEW(column_l), column);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(column_l));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
g_signal_connect(sel, "changed", G_CALLBACK(column_list_select_cb), NULL);
gtk_container_add(GTK_CONTAINER(list_sc), column_l);
gtk_widget_show(column_l);
clp = g_list_first(prefs.col_list);
while (clp) {
cfmt = (fmt_data *) clp->data;
if (cfmt->fmt == COL_CUSTOM) {
if (cfmt->custom_occurrence) {
fmt = g_strdup_printf("%s (%s#%d)", col_format_desc(cfmt->fmt), cfmt->custom_field, cfmt->custom_occurrence);
} else {
fmt = g_strdup_printf("%s (%s)", col_format_desc(cfmt->fmt), cfmt->custom_field);
}
} else {
if (cfmt->custom_field) {
g_free (cfmt->custom_field);
cfmt->custom_field = NULL;
cfmt->custom_occurrence = 0;
}
fmt = g_strdup_printf("%s", col_format_desc(cfmt->fmt));
}
gtk_list_store_insert_with_values(store, &iter, G_MAXINT,
VISIBLE_COLUMN, cfmt->visible,
TITLE_COLUMN, cfmt->title, FORMAT_COLUMN, fmt, DATA_COLUMN, clp, -1);
if (first_row) {
first_iter = iter;
first_row = FALSE;
}
clp = clp->next;
g_free (fmt);
}
g_object_unref(G_OBJECT(store));
bottom_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
gtk_box_pack_start (GTK_BOX (main_vb), bottom_hb, FALSE, FALSE, 0);
gtk_widget_show(bottom_hb);
add_remove_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width (GTK_CONTAINER (add_remove_vb), 5);
gtk_box_pack_start (GTK_BOX (bottom_hb), add_remove_vb, FALSE, FALSE, 0);
gtk_widget_show(add_remove_vb);
add_bt = gtk_button_new_from_stock(GTK_STOCK_ADD);
g_signal_connect(add_bt, "clicked", G_CALLBACK(column_list_new_cb), column_l);
gtk_box_pack_start (GTK_BOX (add_remove_vb), add_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(add_bt, "Add a new column at the end of the list.");
gtk_widget_show(add_bt);
remove_bt = gtk_button_new_from_stock(GTK_STOCK_REMOVE);
gtk_widget_set_sensitive(remove_bt, FALSE);
g_signal_connect(remove_bt, "clicked", G_CALLBACK(column_list_delete_cb), column_l);
gtk_box_pack_start (GTK_BOX (add_remove_vb), remove_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(remove_bt, "Remove the selected column.");
gtk_widget_show(remove_bt);
props_fr = gtk_frame_new("Properties");
gtk_box_pack_start (GTK_BOX (bottom_hb), props_fr, TRUE, TRUE, 0);
gtk_widget_show(props_fr);
grid = ws_gtk_grid_new();
gtk_container_set_border_width(GTK_CONTAINER(grid), 5);
gtk_container_add(GTK_CONTAINER(props_fr), grid);
ws_gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
ws_gtk_grid_set_column_spacing(GTK_GRID(grid), 15);
gtk_widget_show(grid);
lb = gtk_label_new("Field type:");
gtk_misc_set_alignment(GTK_MISC(lb), 0.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(grid), lb, 0, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_tooltip_text(lb, "Select which packet information to present in the column.");
gtk_widget_show(lb);
props_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
ws_gtk_grid_attach_extended(GTK_GRID(grid), props_hb, 1, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_tooltip_text(props_hb, "Select which packet information to present in the column.");
gtk_widget_show(props_hb);
field_lb = gtk_label_new("Field name:");
gtk_misc_set_alignment(GTK_MISC(field_lb), 0.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(grid), field_lb, 0, 1, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_sensitive(field_lb, FALSE);
gtk_widget_set_tooltip_text(field_lb,
"Field name used when field type is \"Custom\". "
"This string has the same syntax as a display filter string.");
gtk_widget_show(field_lb);
field_te = gtk_entry_new();
g_object_set_data (G_OBJECT(field_te), E_FILT_FIELD_NAME_ONLY_KEY, (gpointer)"");
g_signal_connect(field_te, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
column_field_changed_handler_id =
g_signal_connect(field_te, "changed", G_CALLBACK(column_field_changed_cb), column_l);
g_object_set_data(G_OBJECT(main_vb), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(field_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(prefs_window, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
colorize_filter_te_as_empty(field_te);
ws_gtk_grid_attach_extended(GTK_GRID(grid), field_te, 1, 1, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_sensitive(field_te, FALSE);
gtk_widget_set_tooltip_text(field_te,
"Field name used when field type is \"Custom\". "
"This string has the same syntax as a display filter string.");
gtk_widget_show(field_te);
occurrence_lb = gtk_label_new("Field occurrence:");
gtk_misc_set_alignment(GTK_MISC(occurrence_lb), 0.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(grid), occurrence_lb, 2, 1, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_sensitive(occurrence_lb, FALSE);
gtk_widget_set_tooltip_text(occurrence_lb,
"Field occurrence to use. "
"0=all (default), 1=first, 2=second, ..., -1=last.");
gtk_widget_show(occurrence_lb);
occurrence_te = gtk_entry_new();
gtk_entry_set_max_length (GTK_ENTRY(occurrence_te),4);
g_object_set_data (G_OBJECT(occurrence_te), "occurrence", (gpointer)"");
column_occurrence_changed_handler_id =
g_signal_connect(occurrence_te, "changed", G_CALLBACK(column_occurrence_changed_cb), column_l);
ws_gtk_grid_attach_extended(GTK_GRID(grid), occurrence_te, 3, 1, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_set_sensitive(occurrence_te, FALSE);
gtk_widget_set_tooltip_text(occurrence_te,
"Field occurrence to use. "
"0=all (default), 1=first, 2=second, ..., -1=last.");
gtk_widget_show(occurrence_te);
fmt_cmb = gtk_combo_box_text_new();
for (i = 0; i < NUM_COL_FMTS; i++)
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(fmt_cmb), col_format_desc(i));
column_menu_changed_handler_id = g_signal_connect(fmt_cmb, "changed", G_CALLBACK(column_menu_changed_cb), column_l);
gtk_widget_set_sensitive(fmt_cmb, FALSE);
gtk_box_pack_start(GTK_BOX(props_hb), fmt_cmb, FALSE, FALSE, 0);
gtk_widget_show(fmt_cmb);
gtk_tree_selection_select_iter(sel, &first_iter);
return(main_vb);
}
static void
column_list_new_cb(GtkWidget *w _U_, gpointer data) {
gint cur_fmt;
const gchar *title = "New Column";
GtkTreeView *column_l = GTK_TREE_VIEW(data);
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreePath *path;
GtkTreeViewColumn *title_column;
cur_fmt = COL_NUMBER;
column_prefs_add_custom (cur_fmt, title, NULL, 0);
model = gtk_tree_view_get_model(column_l);
gtk_list_store_insert_with_values(GTK_LIST_STORE(model), &iter, G_MAXINT,
VISIBLE_COLUMN, TRUE,
TITLE_COLUMN, title,
FORMAT_COLUMN, col_format_desc(cur_fmt),
DATA_COLUMN, g_list_last(prefs.col_list),
-1);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(column_l), &iter);
path = gtk_tree_model_get_path(model, &iter);
title_column = gtk_tree_view_get_column(column_l, 0);
gtk_tree_view_set_cursor(column_l, path, title_column, TRUE);
gtk_tree_path_free(path);
cfile.columns_changed = TRUE;
}
static void
column_list_delete_cb(GtkWidget *w _U_, gpointer data) {
GtkTreeView *column_l = GTK_TREE_VIEW(data);
GList *clp;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreeIter new_iter;
sel = gtk_tree_view_get_selection(column_l);
if (gtk_tree_selection_get_selected(sel, &model, &iter))
{
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
column_prefs_remove_link(clp);
new_iter = iter;
if ( gtk_tree_model_iter_next(model, &new_iter)) {
gtk_tree_selection_select_iter(sel, &new_iter);
} else {
GtkTreePath *path = gtk_tree_model_get_path(model, &iter);
if (gtk_tree_path_prev(path)) {
gtk_tree_model_get_iter(model, &new_iter, path);
gtk_tree_selection_select_iter(sel, &new_iter);
}
gtk_tree_path_free(path);
}
g_signal_handler_block(model, column_row_deleted_handler_id);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
g_signal_handler_unblock (model, column_row_deleted_handler_id);
cfile.columns_changed = TRUE;
}
}
static gboolean
column_title_changed_cb(GtkCellRendererText *cell _U_, const gchar *str_path, const gchar *new_title, gpointer data) {
fmt_data *cfmt;
GList *clp;
GtkTreeModel *model = (GtkTreeModel *)data;
GtkTreePath *path = gtk_tree_path_new_from_string (str_path);
GtkTreeIter iter;
gtk_tree_model_get_iter(model, &iter, path);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, TITLE_COLUMN, new_title, -1);
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
if (clp) {
cfmt = (fmt_data *) clp->data;
g_free(cfmt->title);
cfmt->title = g_strdup(new_title);
}
gtk_tree_path_free (path);
cfile.columns_changed = TRUE;
return TRUE;
}
static void
column_list_select_cb(GtkTreeSelection *sel, gpointer data _U_)
{
fmt_data *cfmt;
GList *clp;
GtkTreeModel *model;
GtkTreeIter iter;
if (gtk_tree_selection_get_selected(sel, &model, &iter))
{
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
g_assert(clp != NULL);
cfmt = (fmt_data *) clp->data;
g_signal_handler_block (fmt_cmb, column_menu_changed_handler_id);
gtk_combo_box_set_active(GTK_COMBO_BOX(fmt_cmb), cfmt->fmt);
g_signal_handler_unblock(fmt_cmb, column_menu_changed_handler_id);
g_signal_handler_block (field_te, column_field_changed_handler_id);
g_signal_handler_block (occurrence_te, column_occurrence_changed_handler_id);
if (cfmt->fmt == COL_CUSTOM) {
gtk_entry_set_text(GTK_ENTRY(field_te), cfmt->custom_field);
gtk_widget_set_sensitive(field_lb, TRUE);
gtk_widget_set_sensitive(field_te, TRUE);
g_snprintf(custom_occurrence_str, sizeof(custom_occurrence_str), "%d", cfmt->custom_occurrence);
gtk_entry_set_text(GTK_ENTRY(occurrence_te), custom_occurrence_str);
gtk_widget_set_sensitive(occurrence_lb, TRUE);
gtk_widget_set_sensitive(occurrence_te, TRUE);
} else {
gtk_editable_delete_text(GTK_EDITABLE(field_te), 0, -1);
gtk_widget_set_sensitive(field_lb, FALSE);
gtk_widget_set_sensitive(field_te, FALSE);
gtk_editable_delete_text(GTK_EDITABLE(occurrence_te), 0, -1);
gtk_widget_set_sensitive(occurrence_lb, FALSE);
gtk_widget_set_sensitive(occurrence_te, FALSE);
}
g_signal_handler_unblock(occurrence_te, column_occurrence_changed_handler_id);
g_signal_handler_unblock(field_te, column_field_changed_handler_id);
gtk_widget_set_sensitive(remove_bt, TRUE);
gtk_widget_set_sensitive(fmt_cmb, TRUE);
}
else
{
gtk_editable_delete_text(GTK_EDITABLE(field_te), 0, -1);
gtk_editable_delete_text(GTK_EDITABLE(occurrence_te), 0, -1);
gtk_widget_set_sensitive(remove_bt, FALSE);
gtk_widget_set_sensitive(field_te, FALSE);
gtk_widget_set_sensitive(occurrence_te, FALSE);
gtk_widget_set_sensitive(fmt_cmb, FALSE);
}
}
static void
column_menu_changed_cb(GtkWidget *w, gpointer data) {
GtkTreeView *column_l = GTK_TREE_VIEW(data);
fmt_data *cfmt;
gint cur_cb_fmt;
GList *clp;
gchar *fmt;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(column_l);
if (! (gtk_tree_selection_get_selected(sel, &model, &iter)))
return;
cur_cb_fmt = gtk_combo_box_get_active(GTK_COMBO_BOX(w));
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
cfmt = (fmt_data *) clp->data;
g_assert(cur_cb_fmt != cfmt->fmt);
g_signal_handler_block (field_te, column_field_changed_handler_id);
g_signal_handler_block (occurrence_te, column_occurrence_changed_handler_id);
if (cfmt->fmt == COL_CUSTOM) {
gtk_editable_delete_text(GTK_EDITABLE(field_te), 0, -1);
gtk_editable_delete_text(GTK_EDITABLE(occurrence_te), 0, -1);
fmt = g_strdup_printf("%s", col_format_desc(cur_cb_fmt));
gtk_widget_set_sensitive(field_lb, FALSE);
gtk_widget_set_sensitive(field_te, FALSE);
gtk_widget_set_sensitive(occurrence_lb, FALSE);
gtk_widget_set_sensitive(occurrence_te, FALSE);
} else if (cur_cb_fmt == COL_CUSTOM) {
if (cfmt->custom_field == NULL)
cfmt->custom_field = g_strdup("");
gtk_entry_set_text(GTK_ENTRY(field_te), cfmt->custom_field);
g_snprintf(custom_occurrence_str, sizeof(custom_occurrence_str), "%d", cfmt->custom_occurrence);
gtk_entry_set_text(GTK_ENTRY(occurrence_te), custom_occurrence_str);
if (cfmt->custom_occurrence) {
fmt = g_strdup_printf("%s (%s#%d)", col_format_desc(cur_cb_fmt), cfmt->custom_field, cfmt->custom_occurrence);
} else {
fmt = g_strdup_printf("%s (%s)", col_format_desc(cur_cb_fmt), cfmt->custom_field);
}
gtk_widget_set_sensitive(field_lb, TRUE);
gtk_widget_set_sensitive(field_te, TRUE);
gtk_widget_set_sensitive(occurrence_lb, TRUE);
gtk_widget_set_sensitive(occurrence_te, TRUE);
} else {
fmt = g_strdup_printf("%s", col_format_desc(cur_cb_fmt));
}
g_signal_handler_unblock(occurrence_te, column_occurrence_changed_handler_id);
g_signal_handler_unblock(field_te, column_field_changed_handler_id);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, FORMAT_COLUMN, fmt, -1);
g_free(fmt);
cfmt->fmt = cur_cb_fmt;
cfile.columns_changed = TRUE;
}
static void
column_field_changed_cb(GtkEditable *te, gpointer data) {
fmt_data *cfmt;
GList *clp;
gchar *field, *fmt;
GtkTreeView *tree = (GtkTreeView *)data;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(tree);
if ( ! (gtk_tree_selection_get_selected(sel, &model, &iter))) {
return;
}
field = gtk_editable_get_chars(te, 0, -1);
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
cfmt = (fmt_data *) clp->data;
if (strcmp(cfmt->custom_field, field) == 0) {
return;
}
if (cfmt->custom_occurrence) {
fmt = g_strdup_printf("%s (%s#%d)", col_format_desc(cfmt->fmt), field, cfmt->custom_occurrence);
} else {
fmt = g_strdup_printf("%s (%s)", col_format_desc(cfmt->fmt), field);
}
gtk_list_store_set(GTK_LIST_STORE(model), &iter, FORMAT_COLUMN, fmt, -1);
g_free(fmt);
g_free(cfmt->custom_field);
cfmt->custom_field = field;
cfile.columns_changed = TRUE;
}
static void
column_occurrence_changed_cb(GtkEditable *te, gpointer data) {
fmt_data *cfmt;
gint occurrence;
GList *clp;
gchar *fmt;
GtkTreeView *tree = (GtkTreeView *)data;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(tree);
if ( ! (gtk_tree_selection_get_selected(sel, &model, &iter))) {
return;
}
occurrence = (gint)strtol(gtk_editable_get_chars(te, 0, -1), NULL, 10);
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
cfmt = (fmt_data *) clp->data;
if (cfmt->custom_occurrence == occurrence) {
return;
}
if (occurrence) {
fmt = g_strdup_printf("%s (%s#%d)", col_format_desc(cfmt->fmt), cfmt->custom_field, occurrence);
} else {
fmt = g_strdup_printf("%s (%s)", col_format_desc(cfmt->fmt), cfmt->custom_field);
}
gtk_list_store_set(GTK_LIST_STORE(model), &iter, FORMAT_COLUMN, fmt, -1);
g_free(fmt);
cfmt->custom_occurrence = occurrence;
cfile.columns_changed = TRUE;
}
static void
column_dnd_row_deleted_cb(GtkTreeModel *model, GtkTreePath *path _U_, gpointer data _U_) {
GtkTreeIter iter;
GList *clp, *new_col_list = NULL;
gboolean items_left;
for (items_left = gtk_tree_model_get_iter_first (model, &iter);
items_left;
items_left = gtk_tree_model_iter_next (model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &clp, -1);
if (clp) {
prefs.col_list = g_list_remove_link(prefs.col_list, clp);
new_col_list = g_list_concat(new_col_list, clp);
}
}
if (prefs.col_list) {
g_warning("column_dnd_row_deleted_cb: prefs.col_list has %d leftover data",
g_list_length(prefs.col_list));
g_list_free(prefs.col_list);
}
prefs.col_list = new_col_list;
cfile.columns_changed = TRUE;
}
void
column_prefs_fetch(GtkWidget *w _U_) {
}
void
column_prefs_apply(GtkWidget *w _U_)
{
if(cfile.columns_changed) {
packet_list_recreate();
cfile.columns_changed = FALSE;
}
}
void
column_prefs_destroy(GtkWidget *w _U_) {
}
