void
color_display_cb(GtkWidget *w _U_, gpointer d _U_)
{
if (colorize_win != NULL) {
reactivate_window(colorize_win);
} else {
colorize_win = colorize_dialog_new(NULL);
}
}
void
color_display_with_filter(char *filter)
{
if (colorize_win != NULL) {
reactivate_window(colorize_win);
} else {
colorize_win = colorize_dialog_new(filter);
}
}
static void
count_this_select(gpointer filter_arg, gpointer counter_arg)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
int * cnt = (int *)counter_arg;
if (colorf->selected)
(*cnt)++;
}
int color_selected_count(void)
{
int count = 0;
g_slist_foreach(color_filter_edit_list, count_this_select, &count);
return count;
}
void
color_filter_add_cb(color_filter_t *colorf, gpointer user_data)
{
GtkWidget *color_filters = (GtkWidget*)user_data;
add_filter_to_list(colorf, color_filters, FALSE);
gtk_widget_grab_focus(color_filters);
}
static GtkWidget*
colorize_dialog_new (char *filter)
{
GtkWidget *color_win;
GtkWidget *dlg_vbox;
GtkWidget *main_hbox;
GtkWidget *ctrl_vbox;
GtkWidget *order_fr;
GtkWidget *order_vbox;
GtkWidget *color_filter_up;
GtkWidget *order_move_label;
GtkWidget *color_filter_down;
GtkWidget *list_fr;
GtkWidget *list_vbox;
GtkWidget *scrolledwindow1;
GtkWidget *color_filters;
GtkWidget *list_label;
GtkWidget *edit_fr;
GtkWidget *edit_vbox;
GtkWidget *color_new;
GtkWidget *color_edit;
GtkWidget *color_enable;
GtkWidget *color_disable;
GtkWidget *color_delete;
GtkWidget *manage_fr;
GtkWidget *manage_vbox;
GtkWidget *color_import;
GtkWidget *color_export;
GtkWidget *color_clear;
GtkWidget *button_ok_hbox;
GtkWidget *color_ok;
GtkWidget *color_apply;
GtkWidget *color_save;
GtkWidget *color_cancel;
GtkWidget *color_help;
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *selection;
static const gchar *titles[] = { "Name", "String" };
color_dlg_num_of_filters = 0;
color_dlg_row_selected = -1;
color_win = dlg_conf_window_new ("Wireshark: Coloring Rules");
g_object_set_data(G_OBJECT(color_win), "color_win", color_win);
gtk_window_set_default_size(GTK_WINDOW(color_win), DEF_WIDTH, DEF_HEIGHT * 2/3);
dlg_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (dlg_vbox), 5);
gtk_container_add (GTK_CONTAINER (color_win), dlg_vbox);
main_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start (GTK_BOX (dlg_vbox), main_hbox, TRUE, TRUE, 0);
ctrl_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_box_pack_start (GTK_BOX (main_hbox), ctrl_vbox, FALSE, FALSE, 0);
edit_fr = gtk_frame_new("Edit");
gtk_box_pack_start (GTK_BOX (ctrl_vbox), edit_fr, TRUE, TRUE, 0);
edit_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width (GTK_CONTAINER (edit_vbox), 5);
gtk_container_add(GTK_CONTAINER(edit_fr), edit_vbox);
color_new = ws_gtk_button_new_from_stock(GTK_STOCK_NEW);
gtk_box_pack_start (GTK_BOX (edit_vbox), color_new, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_new, "Create a new filter at the top of the list");
color_edit = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_EDIT);
gtk_box_pack_start (GTK_BOX (edit_vbox), color_edit, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_edit, " If more than one filter is selected, edit the first selected one");
gtk_widget_set_sensitive (color_edit, FALSE);
color_enable = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_ENABLE);
gtk_box_pack_start (GTK_BOX (edit_vbox), color_enable, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_enable, "Enable the selected filter(s)");
gtk_widget_set_sensitive (color_enable, FALSE);
color_disable = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISABLE);
gtk_box_pack_start (GTK_BOX (edit_vbox), color_disable, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_disable, "Disable the selected filter(s)");
gtk_widget_set_sensitive (color_disable, FALSE);
color_delete = ws_gtk_button_new_from_stock(GTK_STOCK_DELETE);
gtk_box_pack_start (GTK_BOX (edit_vbox), color_delete, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_delete, "Delete the selected filter(s)");
gtk_widget_set_sensitive (color_delete, FALSE);
manage_fr = gtk_frame_new("Manage");
gtk_box_pack_start (GTK_BOX (ctrl_vbox), manage_fr, TRUE, TRUE, 0);
manage_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width (GTK_CONTAINER (manage_vbox), 5);
gtk_container_add(GTK_CONTAINER(manage_fr), manage_vbox);
color_import = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_IMPORT);
gtk_box_pack_start (GTK_BOX (manage_vbox), color_import, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_import, "Load filters from a file and append them to the list");
color_export = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_EXPORT);
gtk_box_pack_start (GTK_BOX (manage_vbox), color_export, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_export, "Save all/selected filters to a file");
color_clear = ws_gtk_button_new_from_stock(GTK_STOCK_CLEAR);
gtk_box_pack_start(GTK_BOX (manage_vbox), color_clear, FALSE, FALSE, 5);
gtk_widget_set_tooltip_text(color_clear, "Clear the filter list and revert to system-wide default filter set");
list_fr = gtk_frame_new("Filter");
gtk_box_pack_start (GTK_BOX (main_hbox), list_fr, TRUE, TRUE, 0);
list_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (list_vbox), 5);
gtk_container_add(GTK_CONTAINER(list_fr), list_vbox);
list_label = gtk_label_new (("List is processed in order until match is found"));
gtk_box_pack_start (GTK_BOX (list_vbox), list_label, FALSE, FALSE, 0);
scrolledwindow1 = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow1),
GTK_SHADOW_IN);
gtk_box_pack_start (GTK_BOX (list_vbox), scrolledwindow1, TRUE, TRUE, 0);
store = gtk_list_store_new(6,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_BOOLEAN,
G_TYPE_POINTER);
color_filters = tree_view_new(GTK_TREE_MODEL(store));
g_object_unref(store);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(titles[0], renderer,
"text", 0,
"foreground", 2,
"background", 3,
"strikethrough", 4,
NULL);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(GTK_TREE_VIEW(color_filters), column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(titles[1], renderer,
"text", 1,
"foreground", 2,
"background", 3,
"strikethrough", 4,
NULL);
gtk_tree_view_column_set_fixed_width(column, 300);
gtk_tree_view_append_column(GTK_TREE_VIEW(color_filters), column);
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(color_filters), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(color_filters), FALSE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_MULTIPLE);
gtk_container_add (GTK_CONTAINER (scrolledwindow1), color_filters);
order_fr = gtk_frame_new("Order");
gtk_box_pack_start (GTK_BOX (main_hbox), order_fr, FALSE, FALSE, 0);
order_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width (GTK_CONTAINER (order_vbox), 5);
gtk_container_add(GTK_CONTAINER(order_fr), order_vbox);
color_filter_up = ws_gtk_button_new_from_stock(GTK_STOCK_GO_UP);
gtk_box_pack_start (GTK_BOX (order_vbox), color_filter_up, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(color_filter_up, "Move filter higher in list");
gtk_widget_set_sensitive (color_filter_up, FALSE);
order_move_label = gtk_label_new (("Move\nselected filter\nup or down"));
gtk_box_pack_start (GTK_BOX (order_vbox), order_move_label, FALSE, FALSE, 0);
color_filter_down = ws_gtk_button_new_from_stock(GTK_STOCK_GO_DOWN);
gtk_box_pack_start (GTK_BOX (order_vbox), color_filter_down, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(color_filter_down, "Move filter lower in list");
gtk_widget_set_sensitive (color_filter_down, FALSE);
button_ok_hbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start (GTK_BOX (dlg_vbox), button_ok_hbox, FALSE, FALSE, 5);
color_ok = (GtkWidget *)g_object_get_data(G_OBJECT(button_ok_hbox), GTK_STOCK_OK);
gtk_widget_set_tooltip_text(color_ok, "Apply the color filters to the display and close this dialog");
color_apply = (GtkWidget *)g_object_get_data(G_OBJECT(button_ok_hbox), GTK_STOCK_APPLY);
gtk_widget_set_tooltip_text(color_apply, "Apply the color filters to the display and keep this dialog open");
color_save = (GtkWidget *)g_object_get_data(G_OBJECT(button_ok_hbox), GTK_STOCK_SAVE);
gtk_widget_set_tooltip_text(color_save, "Save the color filters permanently and keep this dialog open");
color_cancel = (GtkWidget *)g_object_get_data(G_OBJECT(button_ok_hbox), GTK_STOCK_CANCEL);
window_set_cancel_button(color_win, color_cancel, color_cancel_cb);
gtk_widget_set_tooltip_text(color_cancel, "Cancel changes done (since last \"Apply\") and close this dialog");
color_help = (GtkWidget *)g_object_get_data(G_OBJECT(button_ok_hbox), GTK_STOCK_HELP);
gtk_widget_set_tooltip_text(color_help, "Get help about this dialog");
g_signal_connect(color_help, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_COLORING_RULES_DIALOG);
gtk_widget_grab_default(color_ok);
g_signal_connect(color_win, "destroy", G_CALLBACK(color_destroy_cb), NULL);
g_object_set_data(G_OBJECT(color_filter_up), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_filter_up, "clicked", G_CALLBACK(color_filter_up_cb), NULL);
g_object_set_data(G_OBJECT(color_filter_down), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_filter_down, "clicked", G_CALLBACK(color_filter_down_cb), NULL);
g_signal_connect(selection, "changed", G_CALLBACK(remember_selected_row), color_filters);
g_signal_connect(color_filters, "button_press_event", G_CALLBACK(color_filters_button_cb), NULL);
g_object_set_data(G_OBJECT(color_filters), COLOR_UP_LB, color_filter_up);
g_object_set_data(G_OBJECT(color_filters), COLOR_DOWN_LB, color_filter_down);
g_object_set_data(G_OBJECT(color_filters), COLOR_EDIT_LB, color_edit);
g_object_set_data(G_OBJECT(color_filters), COLOR_ENABLE_LB, color_enable);
g_object_set_data(G_OBJECT(color_filters), COLOR_DISABLE_LB, color_disable);
g_object_set_data(G_OBJECT(color_filters), COLOR_DELETE_LB, color_delete);
g_object_set_data(G_OBJECT(color_new), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_new, "clicked", G_CALLBACK(color_new_cb), NULL);
g_object_set_data(G_OBJECT(color_edit), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_edit, "clicked", G_CALLBACK(color_edit_cb), NULL);
g_object_set_data(G_OBJECT(color_enable), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_enable, "clicked", G_CALLBACK(color_disable_cb), FALSE);
g_object_set_data(G_OBJECT(color_disable), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_disable, "clicked", G_CALLBACK(color_disable_cb), (gpointer)TRUE);
g_object_set_data(G_OBJECT(color_delete), COLOR_EDIT_LB, color_edit);
g_object_set_data(G_OBJECT(color_delete), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_delete, "clicked", G_CALLBACK(color_delete_cb), NULL);
g_object_set_data(G_OBJECT(color_import), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_import, "clicked", G_CALLBACK(color_import_cb), NULL);
g_signal_connect(color_export, "clicked", G_CALLBACK(color_export_cb), NULL);
g_object_set_data(G_OBJECT(color_clear), COLOR_FILTERS_CL, color_filters);
g_signal_connect(color_clear, "clicked", G_CALLBACK(color_clear_cb), NULL);
g_signal_connect(color_ok, "clicked", G_CALLBACK(color_ok_cb), NULL);
g_signal_connect(color_apply, "clicked", G_CALLBACK(color_apply_cb), NULL);
g_signal_connect(color_save, "clicked", G_CALLBACK(color_save_cb), NULL);
g_signal_connect(color_win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_grab_focus(color_filters);
color_filters_clone(color_filters, color_filter_add_cb);
g_object_set_data(G_OBJECT(color_win), COLOR_FILTER_LIST, &color_filter_edit_list);
gtk_widget_show_all(color_win);
if(!prefs.gui_use_pref_save) {
gtk_widget_hide(color_save);
}
window_present(color_win);
if(filter){
create_new_color_filter(GTK_BUTTON(color_new), filter);
}
return color_win;
}
static void move_this_row (GtkWidget *color_filters,
gint filter_number,
gint amount)
{
color_filter_t *colorf;
GtkTreeModel *model;
GtkTreeIter iter1, iter2;
gchar *name, *string, *fg_str, *bg_str;
gboolean disabled;
g_assert(amount == +1 || amount == -1);
g_assert(amount == +1 || filter_number > 0);
g_assert(amount == -1 || filter_number < color_dlg_num_of_filters - 1);
row_is_moving = TRUE;
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter1, NULL, filter_number);
gtk_tree_model_iter_nth_child(model, &iter2, NULL, filter_number + amount);
gtk_tree_model_get(model, &iter1, 0, &name, 1, &string,
2, &fg_str, 3, &bg_str, 4, &disabled, 5, &colorf, -1);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter1);
if (amount < 0)
gtk_list_store_insert_before(GTK_LIST_STORE(model), &iter1, &iter2);
else
gtk_list_store_insert_after(GTK_LIST_STORE(model), &iter1, &iter2);
gtk_list_store_set(GTK_LIST_STORE(model), &iter1,
0, name,
1, string,
2, fg_str,
3, bg_str,
4, disabled,
5, colorf, -1);
g_free(name);
g_free(string);
g_free(fg_str);
g_free(bg_str);
row_is_moving = FALSE;
gtk_widget_grab_focus(color_filters);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters)), &iter1);
color_filter_edit_list = g_slist_remove(color_filter_edit_list, colorf);
color_filter_edit_list = g_slist_insert(color_filter_edit_list, colorf, filter_number + amount);
}
static void
color_filter_up_cb(GtkButton *button, gpointer user_data _U_)
{
gint amount;
gint filter_number;
GtkWidget * color_filters;
color_filter_t *colorf;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
amount = -1;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
for (filter_number = 0; filter_number < color_dlg_num_of_filters; filter_number++)
{
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, filter_number);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
if (gtk_tree_selection_iter_is_selected(sel, &iter))
move_this_row (color_filters, filter_number, amount);
}
}
static void
color_filter_down_cb(GtkButton *button, gpointer user_data _U_)
{
gint amount;
gint filter_number;
GtkWidget * color_filters;
color_filter_t *colorf;
GtkTreeIter iter;
GtkTreeModel *model;
amount = +1;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
for (filter_number = color_dlg_num_of_filters - 1; filter_number >= 0; filter_number--)
{
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, filter_number);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
if (colorf->selected)
move_this_row (color_filters, filter_number, amount);
}
}
static void remember_this_row (GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer arg)
{
gint *path_index;
color_filter_t *colorf;
struct remember_data *data = (struct remember_data *)arg;
gtk_tree_model_get(model, iter, 5, &colorf, -1);
colorf->selected = TRUE;
data->all_enabled &= (!colorf->disabled);
data->all_disabled &= colorf->disabled;
path_index = gtk_tree_path_get_indices(path);
if (path_index == NULL)
{
return;
}
color_dlg_row_selected = path_index[0];
if (color_dlg_row_selected == 0)
data->first_selected = TRUE;
if (color_dlg_row_selected == color_dlg_num_of_filters - 1)
data->last_selected = TRUE;
data->count++;
gtk_tree_view_scroll_to_cell((GtkTreeView *)data->color_filters, path, NULL, FALSE, 0.0f, 0.0f);
}
static void
clear_select_flag(gpointer filter_arg, gpointer arg _U_)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
colorf->selected = FALSE;
}
static void
remember_selected_row(GtkTreeSelection *sel, gpointer color_filters)
{
GtkWidget *button;
struct remember_data data;
data.first_selected = data.last_selected = FALSE;
data.all_enabled = data.all_disabled = TRUE;
data.count = 0;
data.color_filters = color_filters;
g_slist_foreach(color_filter_edit_list, clear_select_flag, NULL);
gtk_tree_selection_selected_foreach(sel,remember_this_row, &data);
if (data.count > 0)
{
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_EDIT_LB);
gtk_widget_set_sensitive (button, data.count == 1);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_ENABLE_LB);
gtk_widget_set_sensitive (button, !data.all_enabled);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DISABLE_LB);
gtk_widget_set_sensitive (button, !data.all_disabled);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DELETE_LB);
gtk_widget_set_sensitive (button, TRUE);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_UP_LB);
gtk_widget_set_sensitive(button, !data.first_selected);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DOWN_LB);
gtk_widget_set_sensitive(button, !data.last_selected);
}
else
{
color_dlg_row_selected = -1;
if (!row_is_moving) {
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_UP_LB);
gtk_widget_set_sensitive (button, FALSE);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DOWN_LB);
gtk_widget_set_sensitive (button, FALSE);
}
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_EDIT_LB);
gtk_widget_set_sensitive (button, FALSE);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_ENABLE_LB);
gtk_widget_set_sensitive (button, FALSE);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DISABLE_LB);
gtk_widget_set_sensitive (button, FALSE);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DELETE_LB);
gtk_widget_set_sensitive (button, FALSE);
}
}
static void
destroy_edit_dialog_cb(gpointer filter_arg, gpointer dummy _U_)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
color_edit_dlg_destroy((color_edit_dlg_info_t *)colorf->color_edit_dlg_info);
}
static void
color_destroy_cb (GtkButton *button _U_,
gpointer user_data _U_)
{
g_slist_foreach(color_filter_edit_list, destroy_edit_dialog_cb, NULL);
color_filter_list_delete(&color_filter_edit_list);
color_filter_list_delete(&color_filter_tmp_list);
colorize_win = NULL;
}
static void
select_row(GtkWidget *color_filters, int row)
{
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreeSelection *sel;
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, row);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
gtk_tree_selection_select_iter(sel, &iter);
}
static void
add_filter_to_list(gpointer filter_arg, gpointer list_arg, gboolean prepend)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
gchar fg_str[14], bg_str[14];
GtkListStore *store;
GtkTreeIter iter;
if( strstr(colorf->filter_name,CONVERSATION_COLOR_PREFIX)==NULL) {
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list_arg)));
if (prepend) {
gtk_list_store_prepend(store, &iter);
} else {
gtk_list_store_append(store, &iter);
}
g_snprintf(fg_str, sizeof(fg_str), "#%04X%04X%04X",
colorf->fg_color.red, colorf->fg_color.green, colorf->fg_color.blue);
g_snprintf(bg_str, sizeof(bg_str), "#%04X%04X%04X",
colorf->bg_color.red, colorf->bg_color.green, colorf->bg_color.blue);
gtk_list_store_set(store, &iter,
0, colorf->filter_name,
1, colorf->filter_text,
2, fg_str,
3, bg_str,
4, colorf->disabled,
5, colorf, -1);
if (prepend) {
color_filter_edit_list = g_slist_prepend(color_filter_edit_list, colorf);
} else {
color_filter_edit_list = g_slist_append(color_filter_edit_list, colorf);
}
color_dlg_num_of_filters++;
} else {
color_filter_tmp_list = g_slist_append(color_filter_tmp_list, colorf);
}
}
static void
create_new_color_filter(GtkButton *button, const char *filter)
{
#if GTK_CHECK_VERSION(3,0,0)
GtkStyleContext *context;
GdkRGBA *rgba_bg_color;
GdkRGBA *rgba_fg_color;
#else
GtkStyle *style;
#endif
color_filter_t *colorf;
color_t bg_color, fg_color;
GtkWidget *color_filters;
GtkTreeSelection *sel;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
gtk_tree_selection_unselect_all (sel);
#if GTK_CHECK_VERSION(3,0,0)
context = gtk_widget_get_style_context (packet_list_get_widget());
gtk_style_context_get (context, GTK_STATE_FLAG_NORMAL,
"background-color", &rgba_bg_color,
NULL);
gtk_style_context_get (context, GTK_STATE_FLAG_NORMAL,
"color", &rgba_fg_color,
NULL);
gdkRGBAcolor_to_color_t(&bg_color, rgba_bg_color);
gdkRGBAcolor_to_color_t(&fg_color, rgba_fg_color);
gdk_rgba_free (rgba_bg_color);
gdk_rgba_free (rgba_fg_color);
#else
style = gtk_widget_get_style(packet_list_get_widget());
gdkcolor_to_color_t(&bg_color, &style->base[GTK_STATE_NORMAL]);
gdkcolor_to_color_t(&fg_color, &style->text[GTK_STATE_NORMAL]);
#endif
colorf = color_filter_new("name", filter, &bg_color, &fg_color, FALSE);
add_filter_to_list(colorf, color_filters, TRUE);
select_row(color_filters, 0);
color_edit_dlg_new(color_filters, TRUE );
gtk_widget_grab_focus(color_filters);
}
static void
color_new_cb(GtkButton *button, gpointer user_data _U_)
{
create_new_color_filter(button, "filter");
}
static void
color_edit_cb(GtkButton *button, gpointer user_data _U_)
{
GtkWidget *color_filters;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
g_assert(color_dlg_row_selected != -1);
color_edit_dlg_new(color_filters, FALSE );
}
static gboolean
color_filters_button_cb(GtkWidget *list, GdkEventButton *event,
gpointer data _U_)
{
if (event->type == GDK_2BUTTON_PRESS) {
color_edit_dlg_new(list, FALSE);
}
return FALSE;
}
static void
color_disable_cb(GtkWidget *widget, gboolean action_disable)
{
gint filter_number;
GtkWidget *button;
GtkWidget * color_filters;
color_filter_t *colorf;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(widget), COLOR_FILTERS_CL);
for (filter_number = 0; filter_number < color_dlg_num_of_filters; filter_number++)
{
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, filter_number);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
if (gtk_tree_selection_iter_is_selected(sel, &iter)) {
colorf->disabled = action_disable;
gtk_list_store_set(GTK_LIST_STORE(model), &iter,
4, action_disable, -1);
}
}
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_ENABLE_LB);
gtk_widget_set_sensitive(button, action_disable);
button = (GtkWidget *)g_object_get_data(G_OBJECT(color_filters), COLOR_DISABLE_LB);
gtk_widget_set_sensitive(button, !action_disable);
}
void
color_delete_single(gint row, GtkWidget *color_filters)
{
color_filter_t *colorf;
GtkTreeModel *model;
GtkTreeIter iter;
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, row);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
color_dlg_num_of_filters--;
color_edit_dlg_destroy((color_edit_dlg_info_t *)colorf->color_edit_dlg_info);
color_filter_edit_list = g_slist_remove(color_filter_edit_list, colorf);
color_filter_delete(colorf);
gtk_widget_grab_focus(color_filters);
}
static void
color_delete_cb(GtkWidget *widget, gpointer user_data _U_)
{
GtkWidget *color_filters;
gint row, num_filters;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreeSelection *sel;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(widget), COLOR_FILTERS_CL);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
num_filters = gtk_tree_model_iter_n_children(model, NULL);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
for (row = num_filters - 1; row >= 0; row--)
{
gtk_tree_model_iter_nth_child(model, &iter, NULL, row);
if (gtk_tree_selection_iter_is_selected(sel, &iter))
color_delete_single (row, color_filters);
}
}
static void
color_import_cb(GtkButton *button, gpointer data _U_)
{
GtkWidget *color_filters;
GtkTreeSelection *sel;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(color_filters));
gtk_tree_selection_unselect_all (sel);
file_color_import_cmd_cb(color_filters, &color_filter_edit_list);
}
static void
color_export_cb(GtkButton *button, gpointer data _U_)
{
GtkWidget *color_filters;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
file_color_export_cmd_cb(color_filters, color_filter_edit_list);
}
static void
color_clear_cmd(GtkWidget *widget)
{
GtkWidget * color_filters;
gchar* err_msg = NULL;
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(widget), COLOR_FILTERS_CL);
while (color_dlg_num_of_filters > 0)
{
color_delete_single (color_dlg_num_of_filters-1, color_filters);
}
if (!color_filters_read_globals(color_filters, &err_msg, color_filter_add_cb))
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
}
void
color_clear_cb(GtkWidget *widget, gpointer data _U_) {
GtkWidget *msg_dialog;
gint response;
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"Do you want to remove all your personal color settings?");
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"This will revert the color settings to global defaults.\n\n"
"Are you really sure?");
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
gtk_dialog_add_button(GTK_DIALOG(msg_dialog),
GTK_STOCK_CLEAR, GTK_RESPONSE_ACCEPT);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(msg_dialog),
GTK_RESPONSE_ACCEPT,
GTK_RESPONSE_CANCEL,
-1);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog), GTK_RESPONSE_CANCEL);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
switch (response) {
case GTK_RESPONSE_ACCEPT:
color_clear_cmd(widget);
break;
case GTK_RESPONSE_CANCEL:
case GTK_RESPONSE_NONE:
case GTK_RESPONSE_DELETE_EVENT:
default:
break;
}
}
static void
overwrite_existing_colorfilters_cb(gpointer dialog _U_, gint btn, gpointer data _U_)
{
gchar* err_msg = NULL;
switch (btn) {
case(ESD_BTN_SAVE):
if (!color_filters_write(color_filter_edit_list, &err_msg))
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open colorfilter file: %s", err_msg);
g_free(err_msg);
}
else
prefs.unknown_colorfilters = FALSE;
break;
case(ESD_BTN_DONT_SAVE):
break;
default:
g_assert_not_reached();
}
}
static void
colorfilters_main_save(void)
{
gchar* err_msg = NULL;
if (prefs.unknown_colorfilters) {
gpointer dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_SAVE_DONTSAVE,
"Obsolete or unrecognized color filters have been detected. "
"If this profile will be used with an older or nonstandard Wireshark version "
"or one that includes a proprietary dissector plugin, click 'Continue "
"without Saving' and save this profile under a different name.\n\n");
simple_dialog_set_cb(dialog, overwrite_existing_colorfilters_cb, NULL);
} else {
if (!color_filters_write(color_filter_edit_list, &err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Could not open filter file: %s", err_msg);
g_free(err_msg);
}
}
}
static void
color_ok_cb(GtkButton *button _U_, gpointer user_data _U_)
{
color_apply_cb(button,user_data);
window_destroy(colorize_win);
}
static void
color_apply_cb(GtkButton *button _U_, gpointer user_data _U_)
{
gchar* err_msg = NULL;
if (!prefs.gui_use_pref_save)
colorfilters_main_save();
if (!color_filters_apply(color_filter_tmp_list, color_filter_edit_list, &err_msg)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
g_free(err_msg);
}
packet_list_colorize_packets();
}
static void
color_save_cb(GtkButton *button _U_, gpointer user_data _U_)
{
colorfilters_main_save();
}
static void
color_cancel_cb(GtkWidget *widget _U_, gpointer user_data _U_)
{
window_destroy(colorize_win);
}
