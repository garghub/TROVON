static void
filter_expr_cb(GtkWidget *w _U_, gpointer filter_te)
{
dfilter_expr_dlg_new(GTK_WIDGET(filter_te));
}
void
edit_color_filter_dialog(GtkWidget *color_filters,
gboolean is_new_filter)
{
color_filter_t *colorf;
GtkWidget *edit_dialog;
GtkWidget *dialog_vbox;
#if GTK_CHECK_VERSION(3,0,0)
GdkRGBA bg_rgba_color, fg_rgba_color;
#else
GdkColor bg_color, fg_color;
#endif
GtkWidget *filter_fr;
GtkWidget *filter_fr_vbox;
GtkWidget *filter_name_hbox;
GtkWidget *color_filter_name;
GtkWidget *filter_string_hbox;
GtkWidget *add_expression_bt;
GtkWidget *color_filter_text;
GtkWidget *settings_hbox;
GtkWidget *colorize_fr;
GtkWidget *colorize_hbox;
GtkWidget *colorize_filter_fg;
GtkWidget *colorize_filter_bg;
GtkWidget *status_fr;
GtkWidget *status_vbox;
GtkWidget *bbox;
GtkWidget *edit_color_filter_ok;
GtkWidget *edit_color_filter_cancel;
GtkTreeModel *model;
GtkTreeIter iter;
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, color_dlg_row_selected);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
if (colorf->edit_dialog != NULL) {
reactivate_window(colorf->edit_dialog);
return;
}
edit_dialog = dlg_conf_window_new ("Wireshark: Edit Color Filter");
gtk_window_set_default_size(GTK_WINDOW(edit_dialog), 500, -1);
g_object_set_data(G_OBJECT(edit_dialog), "edit_dialog", edit_dialog);
colorf->edit_dialog = edit_dialog;
dialog_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (dialog_vbox), 5);
gtk_container_add (GTK_CONTAINER (edit_dialog), dialog_vbox);
filter_fr = gtk_frame_new("Filter");
gtk_box_pack_start (GTK_BOX (dialog_vbox), filter_fr, FALSE, FALSE, 0);
filter_fr_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (filter_fr_vbox), 5);
gtk_container_add(GTK_CONTAINER(filter_fr), filter_fr_vbox);
filter_name_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start (GTK_BOX (filter_fr_vbox), filter_name_hbox, TRUE, FALSE, 3);
color_filter_name = gtk_label_new (("Name: "));
gtk_box_pack_start (GTK_BOX (filter_name_hbox), color_filter_name, FALSE, FALSE, 0);
filt_name_entry = gtk_entry_new ();
gtk_entry_set_text(GTK_ENTRY(filt_name_entry), colorf->filter_name);
#if GTK_CHECK_VERSION(3,0,0)
color_t_to_gdkRGBAcolor(&bg_rgba_color, &colorf->bg_color);
color_t_to_gdkRGBAcolor(&fg_rgba_color, &colorf->fg_color);
gtk_widget_override_background_color(filt_name_entry, GTK_STATE_NORMAL, &bg_rgba_color);
gtk_widget_override_color(filt_name_entry, GTK_STATE_NORMAL, &fg_rgba_color);
#else
color_t_to_gdkcolor(&bg_color, &colorf->bg_color);
color_t_to_gdkcolor(&fg_color, &colorf->fg_color);
gtk_widget_modify_base(filt_name_entry, GTK_STATE_NORMAL, &bg_color);
gtk_widget_modify_text(filt_name_entry, GTK_STATE_NORMAL, &fg_color);
#endif
gtk_box_pack_start (GTK_BOX (filter_name_hbox), filt_name_entry, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(filt_name_entry, "This is the editable name of the filter. (No @ characters allowed.)");
filter_string_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start (GTK_BOX (filter_fr_vbox), filter_string_hbox, TRUE, FALSE, 3);
color_filter_text = gtk_label_new (("String: "));
gtk_box_pack_start (GTK_BOX (filter_string_hbox), color_filter_text, FALSE, FALSE, 0);
filt_text_entry = gtk_entry_new ();
g_signal_connect(filt_text_entry, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_string_hbox), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filt_text_entry, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(edit_dialog, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_entry_set_text(GTK_ENTRY(filt_text_entry), colorf->filter_text);
gtk_box_pack_start (GTK_BOX (filter_string_hbox), filt_text_entry, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(filt_text_entry, "This is the editable text of the filter");
add_expression_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_ADD_EXPRESSION);
g_signal_connect(add_expression_bt, "clicked", G_CALLBACK(filter_expr_cb), filt_text_entry);
gtk_box_pack_start (GTK_BOX(filter_string_hbox), add_expression_bt, FALSE, FALSE, 3);
gtk_widget_set_tooltip_text(add_expression_bt, "Add an expression to the filter string");
filter_te_syntax_check_cb(filt_text_entry, NULL);
settings_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start (GTK_BOX (dialog_vbox), settings_hbox, FALSE, FALSE, 0);
colorize_fr = gtk_frame_new("Display Colors");
gtk_box_pack_start (GTK_BOX (settings_hbox), colorize_fr, TRUE, TRUE, 0);
colorize_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (colorize_hbox), 5);
gtk_container_add(GTK_CONTAINER(colorize_fr), colorize_hbox);
colorize_filter_fg = gtk_button_new_with_label (("Foreground Color..."));
gtk_box_pack_start (GTK_BOX (colorize_hbox), colorize_filter_fg, TRUE, FALSE, 0);
gtk_widget_set_tooltip_text(colorize_filter_fg, "Select foreground color for data display");
colorize_filter_bg = gtk_button_new_with_label (("Background Color..."));
gtk_box_pack_start (GTK_BOX (colorize_hbox), colorize_filter_bg, TRUE, FALSE, 0);
gtk_widget_set_tooltip_text(colorize_filter_bg, "Select background color for data display");
status_fr = gtk_frame_new("Status");
gtk_box_pack_start (GTK_BOX (settings_hbox), status_fr, TRUE, TRUE, 0);
status_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (status_vbox), 5);
gtk_container_add(GTK_CONTAINER(status_fr), status_vbox);
disabled_cb = gtk_check_button_new_with_label("Disabled");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(disabled_cb), colorf->disabled);
gtk_box_pack_start (GTK_BOX (status_vbox), disabled_cb, TRUE, FALSE, 0);
gtk_widget_set_tooltip_text(disabled_cb, "Color rule won't be checked if this box is selected");
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(dialog_vbox), bbox, FALSE, FALSE, 0);
gtk_container_set_border_width (GTK_CONTAINER (bbox), 0);
edit_color_filter_ok = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_tooltip_text(edit_color_filter_ok, "Accept filter color change");
edit_color_filter_cancel = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(edit_color_filter_cancel, "Reject filter color change");
gtk_widget_grab_default(edit_color_filter_ok);
g_object_set_data(G_OBJECT(edit_dialog), COLOR_FILTER, colorf);
g_signal_connect(edit_dialog, "destroy", G_CALLBACK(edit_color_filter_destroy_cb), NULL);
g_object_set_data(G_OBJECT(colorize_filter_fg), COLOR_FILTER, colorf);
g_signal_connect(colorize_filter_fg, "clicked", G_CALLBACK(edit_color_filter_fg_cb), NULL);
g_object_set_data(G_OBJECT(colorize_filter_bg), COLOR_FILTER, colorf);
g_signal_connect(colorize_filter_bg, "clicked", G_CALLBACK(edit_color_filter_bg_cb), NULL);
g_object_set_data(G_OBJECT(disabled_cb), COLOR_FILTER, colorf);
g_object_set_data(G_OBJECT(edit_color_filter_ok), COLOR_FILTERS_CL, color_filters);
g_object_set_data(G_OBJECT(edit_color_filter_ok), COLOR_FILTER, colorf);
g_signal_connect(edit_color_filter_ok, "clicked", G_CALLBACK(edit_color_filter_ok_cb), edit_dialog);
if (is_new_filter)
{
g_object_set_data(G_OBJECT(edit_color_filter_cancel), COLOR_FILTERS_CL, color_filters);
g_signal_connect(edit_color_filter_cancel, "clicked",
G_CALLBACK(edit_new_color_filter_cancel_cb), edit_dialog);
}
window_set_cancel_button(edit_dialog, edit_color_filter_cancel, window_cancel_button_cb);
g_signal_connect(edit_dialog, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show_all(edit_dialog);
window_present(edit_dialog);
}
static void
edit_color_filter_destroy_cb(GObject *object, gpointer user_data _U_)
{
color_filter_t *colorf;
GtkWidget *color_sel;
colorf = (color_filter_t *)g_object_get_data(G_OBJECT(object), COLOR_FILTER);
colorf->edit_dialog = NULL;
color_sel = (GtkWidget *)g_object_get_data(G_OBJECT(object), COLOR_SELECTION_FG);
if (color_sel != NULL)
window_destroy(color_sel);
color_sel = (GtkWidget *)g_object_get_data(G_OBJECT(object), COLOR_SELECTION_BG);
if (color_sel != NULL)
window_destroy(color_sel);
}
static void
edit_color_filter_fg_cb(GtkButton *button, gpointer user_data _U_)
{
color_filter_t *colorf;
GtkWidget *color_selection_fg;
colorf = (color_filter_t *)g_object_get_data(G_OBJECT(button), COLOR_FILTER);
color_selection_fg = g_object_get_data(G_OBJECT(colorf->edit_dialog), COLOR_SELECTION_FG);
if (color_selection_fg != NULL) {
reactivate_window(color_selection_fg);
} else {
color_selection_fg = color_sel_win_new(colorf, FALSE);
g_object_set_data(G_OBJECT(colorf->edit_dialog), COLOR_SELECTION_FG, color_selection_fg);
g_object_set_data(G_OBJECT(color_selection_fg), COLOR_SELECTION_PARENT, colorf->edit_dialog);
}
}
static void
edit_color_filter_bg_cb (GtkButton *button,
gpointer user_data _U_)
{
color_filter_t *colorf;
GtkWidget *color_selection_bg;
colorf = (color_filter_t *)g_object_get_data(G_OBJECT(button), COLOR_FILTER);
color_selection_bg = g_object_get_data(G_OBJECT(colorf->edit_dialog), COLOR_SELECTION_BG);
if (color_selection_bg != NULL) {
reactivate_window(color_selection_bg);
} else {
color_selection_bg = color_sel_win_new(colorf, TRUE);
g_object_set_data(G_OBJECT(colorf->edit_dialog), COLOR_SELECTION_BG, color_selection_bg);
g_object_set_data(G_OBJECT(color_selection_bg), COLOR_SELECTION_PARENT, colorf->edit_dialog);
}
}
static void
edit_color_filter_ok_cb (GtkButton *button,
gpointer user_data)
{
GtkWidget *dialog;
#if GTK_CHECK_VERSION(3,0,0)
GtkStyleContext *context;
GdkRGBA *new_rgba_bg_color;
GdkRGBA *new_rgba_fg_color;
#else
GtkStyle *style;
GdkColor new_fg_color;
GdkColor new_bg_color;
#endif
gchar *filter_name;
gchar *filter_text;
gboolean filter_disabled;
color_filter_t *colorf;
dfilter_t *compiled_filter;
GtkWidget *color_filters;
GtkTreeModel *model;
GtkTreeIter iter;
gchar fg_str[14], bg_str[14];
dialog = (GtkWidget *)user_data;
#if GTK_CHECK_VERSION(3,0,0)
context = gtk_widget_get_style_context (filt_name_entry);
gtk_style_context_get (context, GTK_STATE_NORMAL,
"background-color", &new_rgba_bg_color,
NULL);
gtk_style_context_get (context, GTK_STATE_NORMAL,
"forground-color", &new_rgba_fg_color,
NULL);
#else
style = gtk_widget_get_style(filt_name_entry);
new_bg_color = style->base[GTK_STATE_NORMAL];
new_fg_color = style->text[GTK_STATE_NORMAL];
#endif
filter_name = g_strdup(gtk_entry_get_text(GTK_ENTRY(filt_name_entry)));
filter_text = g_strdup(gtk_entry_get_text(GTK_ENTRY(filt_text_entry)));
filter_disabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(disabled_cb));
if(strchr(filter_name,'@') || strchr(filter_text,'@')){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Filter names and strings must not"
" use the '@' character. Filter unchanged.");
g_free(filter_name);
g_free(filter_text);
return;
}
if(!dfilter_compile(filter_text, &compiled_filter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Filter \"%s\" didn't compile correctly.\n"
" Please try again. Filter unchanged.\n%s\n", filter_name,
dfilter_error_msg);
} else {
color_filters = (GtkWidget *)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL);
colorf = (color_filter_t *)g_object_get_data(G_OBJECT(button), COLOR_FILTER);
g_free(colorf->filter_name);
colorf->filter_name = filter_name;
g_free(colorf->filter_text);
colorf->filter_text = filter_text;
colorf->disabled = filter_disabled;
#if GTK_CHECK_VERSION(3,0,0)
gdkRGBAcolor_to_color_t(&colorf->fg_color, new_rgba_fg_color);
gdkRGBAcolor_to_color_t(&colorf->bg_color, new_rgba_bg_color);
#else
gdkcolor_to_color_t(&colorf->fg_color, &new_fg_color);
gdkcolor_to_color_t(&colorf->bg_color, &new_bg_color);
#endif
g_snprintf(fg_str, sizeof(fg_str), "#%04X%04X%04X",
colorf->fg_color.red, colorf->fg_color.green, colorf->fg_color.blue);
g_snprintf(bg_str, sizeof(bg_str), "#%04X%04X%04X",
colorf->bg_color.red, colorf->bg_color.green, colorf->bg_color.blue);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, color_dlg_row_selected);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, filter_name,
1, filter_text, 2, fg_str, 3, bg_str,
4, filter_disabled, -1);
if(colorf->c_colorfilter != NULL)
dfilter_free(colorf->c_colorfilter);
colorf->c_colorfilter = compiled_filter;
window_destroy(dialog);
}
#if GTK_CHECK_VERSION(3,0,0)
gdk_rgba_free (new_rgba_fg_color);
gdk_rgba_free (new_rgba_bg_color);
#endif
}
static void
edit_new_color_filter_cancel_cb(GtkButton *button, gpointer user_data _U_)
{
color_delete_single(color_dlg_num_of_filters-1, (GtkWidget*)g_object_get_data(G_OBJECT(button), COLOR_FILTERS_CL));
}
static GtkWidget*
color_sel_win_new(color_filter_t *colorf, gboolean is_bg)
{
gchar *title;
GtkWidget *color_sel_win;
color_t *color;
GdkColor gcolor;
GtkWidget *color_sel_ok;
GtkWidget *color_sel_cancel;
GtkWidget *color_sel_help;
if (is_bg) {
color = &colorf->bg_color;
title = g_strdup_printf("Wireshark: Choose background color for \"%s\"",
colorf->filter_name);
} else {
color = &colorf->fg_color;
title = g_strdup_printf("Wireshark: Choose foreground color for \"%s\"",
colorf->filter_name);
}
color_sel_win = gtk_color_selection_dialog_new(title);
g_free(title);
g_object_set_data(G_OBJECT(color_sel_win), "color_sel_win", color_sel_win);
gtk_container_set_border_width (GTK_CONTAINER (color_sel_win), 10);
if (color != NULL) {
color_t_to_gdkcolor(&gcolor, color);
gtk_color_selection_set_current_color(GTK_COLOR_SELECTION(gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_sel_win))), &gcolor);
}
g_object_get(color_sel_win, "ok-button", &color_sel_ok, NULL);
g_object_set_data(G_OBJECT(color_sel_win), "color_sel_ok", color_sel_ok);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(color_sel_ok, TRUE);
#else
GTK_WIDGET_SET_FLAGS (color_sel_ok, GTK_CAN_DEFAULT);
#endif
g_object_get(color_sel_win, "cancel-button", &color_sel_cancel, NULL);
g_object_set_data(G_OBJECT(color_sel_win), "color_sel_cancel", color_sel_cancel);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(color_sel_cancel, TRUE);
#else
GTK_WIDGET_SET_FLAGS (color_sel_cancel, GTK_CAN_DEFAULT);
#endif
window_set_cancel_button(color_sel_win, color_sel_cancel, NULL);
g_object_get(color_sel_win, "help-button", &color_sel_help, NULL);
g_object_set_data(G_OBJECT(color_sel_win), "color_sel_help", color_sel_help);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(color_sel_help, TRUE);
#else
GTK_WIDGET_SET_FLAGS (color_sel_help, GTK_CAN_DEFAULT);
#endif
g_signal_connect(color_sel_ok, "clicked", G_CALLBACK(color_sel_ok_cb), color_sel_win);
g_signal_connect(color_sel_cancel, "clicked", G_CALLBACK(color_sel_cancel_cb), color_sel_win);
gtk_widget_show_all(color_sel_win);
return color_sel_win;
}
static void
color_sel_win_destroy(GtkWidget *sel_win)
{
GtkWidget *parent;
GtkWidget *color_selection_fg, *color_selection_bg;
parent = (GtkWidget *)g_object_get_data(G_OBJECT(sel_win), COLOR_SELECTION_PARENT);
color_selection_fg = g_object_get_data(G_OBJECT(parent), COLOR_SELECTION_FG);
color_selection_bg = g_object_get_data(G_OBJECT(parent), COLOR_SELECTION_BG);
if (sel_win == color_selection_fg) {
g_object_set_data(G_OBJECT(parent), COLOR_SELECTION_FG, NULL);
}
if (sel_win == color_selection_bg) {
g_object_set_data(G_OBJECT(parent), COLOR_SELECTION_BG, NULL);
}
window_destroy(sel_win);
}
static void
color_sel_ok_cb (GtkButton *button _U_,
gpointer user_data)
{
#if GTK_CHECK_VERSION(3,0,0)
GdkRGBA new_rgba_color;
#else
GdkColor new_color;
#endif
GtkWidget *color_dialog;
GtkWidget *parent;
GtkWidget *color_selection_bg;
gboolean is_bg;
color_dialog = (GtkWidget *)user_data;
#if GTK_CHECK_VERSION(3,0,0)
gtk_color_selection_get_current_rgba(GTK_COLOR_SELECTION(gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_dialog))), &new_rgba_color);
#else
gtk_color_selection_get_current_color(GTK_COLOR_SELECTION(gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_dialog))), &new_color);
#endif
#if 0
if ( ! get_color(&new_color) ){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not allocate color. Try again.");
} else {
#endif
parent = (GtkWidget *)g_object_get_data(G_OBJECT(color_dialog), COLOR_SELECTION_PARENT);
color_selection_bg = g_object_get_data(G_OBJECT(parent), COLOR_SELECTION_BG);
is_bg = (color_dialog == color_selection_bg);
color_sel_win_destroy(color_dialog);
#if GTK_CHECK_VERSION(3,0,0)
if (is_bg)
gtk_widget_override_background_color(filt_name_entry, GTK_STATE_NORMAL, &new_rgba_color);
else
gtk_widget_override_color(filt_name_entry, GTK_STATE_NORMAL, &new_rgba_color);
#else
if (is_bg)
gtk_widget_modify_base(filt_name_entry, GTK_STATE_NORMAL, &new_color);
else
gtk_widget_modify_text(filt_name_entry, GTK_STATE_NORMAL, &new_color);
#endif
#if 0
}
#endif
}
static void
color_sel_cancel_cb (GObject *object _U_,
gpointer user_data)
{
GtkWidget *color_dialog;
color_dialog = (GtkWidget *)user_data;
color_sel_win_destroy(color_dialog);
}
