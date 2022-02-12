static void
filter_expr_cb(GtkWidget *w _U_, gpointer filter_te)
{
dfilter_expr_dlg_new(GTK_WIDGET(filter_te));
}
static void
colorize_filter_new(GtkWidget *colorize_hbox,
color_selection_type_t color_selection_type,
const gchar *t1,
const gchar *t2,
const gchar *t3,
color_filter_t *colorf,
color_t *color,
GtkWidget *filt_name_entry)
{
GtkWidget *colorize_filter;
color_selection_dlg_info_t *csdi;
colorize_filter = gtk_button_new_with_label(t2);
gtk_box_pack_start (GTK_BOX (colorize_hbox), colorize_filter, TRUE, FALSE, 0);
gtk_widget_set_tooltip_text(colorize_filter, t3);
csdi = g_new(color_selection_dlg_info_t, 1);
csdi->color_selection_dlg = NULL;
csdi->color_selection_type = color_selection_type;
csdi->colorf = colorf;
csdi->color = color;
csdi->color_selection_type_text = t1;
csdi->filt_name_entry = filt_name_entry;
g_signal_connect(colorize_filter, "clicked", G_CALLBACK(color_edit_dlg_fg_bg_btn_cb), csdi);
g_signal_connect(colorize_filter, "destroy", G_CALLBACK(color_edit_dlg_fg_bg_btn_destroy_cb), csdi);
}
void
color_edit_dlg_new(GtkWidget *color_filters,
gboolean is_new_filter)
{
color_edit_dlg_info_t *cedi;
color_filter_t *colorf;
GtkWidget *color_edit_dlg;
GtkWidget *dialog_vbox;
GtkWidget *filter_fr;
GtkWidget *filter_fr_vbox;
GtkWidget *filter_name_hbox;
GtkWidget *filt_name_entry;
GtkWidget *filt_text_entry;
GtkWidget *color_filter_name;
GtkWidget *filter_string_hbox;
GtkWidget *add_expression_bt;
GtkWidget *color_filter_text;
GtkWidget *settings_hbox;
GtkWidget *colorize_fr;
GtkWidget *colorize_hbox;
GtkWidget *status_fr;
GtkWidget *status_vbox;
GtkWidget *disabled_cb;
GtkWidget *bbox;
GtkWidget *edit_color_filter_ok;
GtkWidget *edit_color_filter_cancel;
GtkTreeModel *model;
GtkTreeIter iter;
model = gtk_tree_view_get_model(GTK_TREE_VIEW(color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, color_dlg_row_selected);
gtk_tree_model_get(model, &iter, 5, &colorf, -1);
if (colorf->color_edit_dlg_info != NULL) {
cedi = (color_edit_dlg_info_t *)colorf->color_edit_dlg_info;
g_assert(cedi->color_edit_dlg != NULL);
reactivate_window(cedi->color_edit_dlg);
return;
}
color_edit_dlg = dlg_conf_window_new ("Wireshark: Edit Color Filter");
gtk_window_set_default_size(GTK_WINDOW(color_edit_dlg), 500, -1);
dialog_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width (GTK_CONTAINER (dialog_vbox), 5);
gtk_container_add (GTK_CONTAINER (color_edit_dlg), dialog_vbox);
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
{
GdkRGBA bg_rgba_color, fg_rgba_color;
color_t_to_gdkRGBAcolor(&bg_rgba_color, &colorf->bg_color);
color_t_to_gdkRGBAcolor(&fg_rgba_color, &colorf->fg_color);
gtk_widget_override_background_color(filt_name_entry, GTK_STATE_FLAG_NORMAL, &bg_rgba_color);
gtk_widget_override_color(filt_name_entry, GTK_STATE_FLAG_NORMAL, &fg_rgba_color);
}
#else
{
GdkColor bg_color, fg_color;
color_t_to_gdkcolor(&bg_color, &colorf->bg_color);
color_t_to_gdkcolor(&fg_color, &colorf->fg_color);
gtk_widget_modify_base(filt_name_entry, GTK_STATE_NORMAL, &bg_color);
gtk_widget_modify_text(filt_name_entry, GTK_STATE_NORMAL, &fg_color);
}
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
g_signal_connect(color_edit_dlg, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_entry_set_text(GTK_ENTRY(filt_text_entry), colorf->filter_text);
gtk_box_pack_start (GTK_BOX (filter_string_hbox), filt_text_entry, TRUE, TRUE, 0);
gtk_widget_set_tooltip_text(filt_text_entry, "This is the editable text of the filter");
add_expression_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_ADD_EXPRESSION);
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
colorize_filter_new(colorize_hbox,
COLOR_SELECTION_TYPE_FG,
"Foreground", "Foreground Color...", "Select foreground color for data display",
colorf, &colorf->fg_color,
filt_name_entry);
colorize_filter_new(colorize_hbox,
COLOR_SELECTION_TYPE_BG,
"Background", "Background Color...", "Select background color for data display",
colorf, &colorf->bg_color,
filt_name_entry);
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
edit_color_filter_cancel = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(edit_color_filter_cancel, "Reject filter color change");
window_set_cancel_button(color_edit_dlg, edit_color_filter_cancel, window_cancel_button_cb);
edit_color_filter_ok = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_tooltip_text(edit_color_filter_ok, "Accept filter color change");
gtk_widget_grab_default(edit_color_filter_ok);
cedi = g_new(color_edit_dlg_info_t, 1);
colorf->color_edit_dlg_info = cedi;
cedi->color_filters = color_filters;
cedi->colorf = colorf;
cedi->color_edit_dlg = color_edit_dlg;
cedi->filt_name_entry = filt_name_entry;
cedi->filt_text_entry = filt_text_entry;
cedi->disabled_cb = disabled_cb;
g_signal_connect(color_edit_dlg, "destroy", G_CALLBACK(color_edit_dlg_destroy_cb), cedi);
g_signal_connect(edit_color_filter_ok, "clicked", G_CALLBACK(color_edit_dlg_ok_cb), cedi);
if (is_new_filter) {
g_signal_connect(edit_color_filter_cancel, "clicked",
G_CALLBACK(color_edit_dlg_cancel_cb), cedi);
}
g_signal_connect(color_edit_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show_all(color_edit_dlg);
window_present(color_edit_dlg);
}
static void
color_edit_dlg_ok_cb(GtkWidget *w _U_, gpointer user_data)
{
color_edit_dlg_info_t *cedi = (color_edit_dlg_info_t *)user_data;
gchar *filter_name;
gchar *filter_text;
gboolean filter_disabled;
color_filter_t *colorf;
dfilter_t *compiled_filter;
GtkTreeModel *model;
GtkTreeIter iter;
gchar fg_str[14], bg_str[14];
filter_name = g_strdup(gtk_entry_get_text(GTK_ENTRY(cedi->filt_name_entry)));
filter_text = g_strdup(gtk_entry_get_text(GTK_ENTRY(cedi->filt_text_entry)));
filter_disabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cedi->disabled_cb));
if (strchr(filter_name,'@') || strchr(filter_text,'@')) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Filter names and strings must not"
" use the '@' character. Filter unchanged.");
g_free(filter_name);
g_free(filter_text);
return;
}
if (!dfilter_compile(filter_text, &compiled_filter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Filter \"%s\" didn't compile correctly.\n"
" Please try again. Filter unchanged.\n%s\n", filter_name,
dfilter_error_msg);
g_free(filter_name);
g_free(filter_text);
return;
}
colorf = cedi->colorf;
g_free(colorf->filter_name);
g_free(colorf->filter_text);
colorf->filter_name = filter_name;
colorf->filter_text = filter_text;
colorf->disabled = filter_disabled;
#if GTK_CHECK_VERSION(3,0,0)
{
GtkStyleContext *context;
GdkRGBA new_rgba_fg_color;
GdkRGBA new_rgba_bg_color;
context = gtk_widget_get_style_context (cedi->filt_name_entry);
gtk_style_context_get_color(context, (GtkStateFlags)GTK_STATE_NORMAL, &new_rgba_fg_color);
gtk_style_context_get_background_color(context, (GtkStateFlags)GTK_STATE_NORMAL, &new_rgba_bg_color);
gdkRGBAcolor_to_color_t(&colorf->fg_color, &new_rgba_fg_color);
gdkRGBAcolor_to_color_t(&colorf->bg_color, &new_rgba_bg_color);
}
#else
{
GtkStyle *style;
GdkColor new_fg_color;
GdkColor new_bg_color;
style = gtk_widget_get_style(cedi->filt_name_entry);
new_bg_color = style->base[GTK_STATE_NORMAL];
new_fg_color = style->text[GTK_STATE_NORMAL];
gdkcolor_to_color_t(&colorf->fg_color, &new_fg_color);
gdkcolor_to_color_t(&colorf->bg_color, &new_bg_color);
}
#endif
g_snprintf(fg_str, sizeof(fg_str), "#%04X%04X%04X",
colorf->fg_color.red, colorf->fg_color.green, colorf->fg_color.blue);
g_snprintf(bg_str, sizeof(bg_str), "#%04X%04X%04X",
colorf->bg_color.red, colorf->bg_color.green, colorf->bg_color.blue);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(cedi->color_filters));
gtk_tree_model_iter_nth_child(model, &iter, NULL, color_dlg_row_selected);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, filter_name,
1, filter_text, 2, fg_str, 3, bg_str,
4, filter_disabled, -1);
if (colorf->c_colorfilter != NULL) {
dfilter_free(colorf->c_colorfilter);
}
colorf->c_colorfilter = compiled_filter;
window_destroy(cedi->color_edit_dlg);
}
static void
color_edit_dlg_cancel_cb(GtkWidget *w _U_, gpointer user_data)
{
color_edit_dlg_info_t *cedi = (color_edit_dlg_info_t *)user_data;
color_delete_single(0, cedi->color_filters);
}
void
color_edit_dlg_destroy(color_edit_dlg_info_t *cedi)
{
if (cedi == NULL) {
return;
}
g_assert(cedi->color_edit_dlg != NULL);
window_destroy(cedi->color_edit_dlg);
}
static void
color_edit_dlg_destroy_cb(GObject *object _U_, gpointer user_data)
{
color_edit_dlg_info_t *cedi = (color_edit_dlg_info_t *)user_data;
g_assert(cedi->color_edit_dlg);
cedi->colorf->color_edit_dlg_info = NULL;
g_free(cedi);
}
static void
color_edit_dlg_fg_bg_btn_cb(GtkWidget *button, gpointer user_data)
{
color_selection_dlg_info_t *csdi = (color_selection_dlg_info_t *)user_data;
GtkWidget *color_selection_dlg;
gchar *title;
if (csdi->color_selection_dlg != NULL) {
reactivate_window(csdi->color_selection_dlg);
return;
}
title = g_strdup_printf("Wireshark: Choose %s color for \"%s\"",
csdi->color_selection_type_text,
csdi->colorf->filter_name);
#if GTK_CHECK_VERSION(3,4,0)
{
GdkRGBA rgba_color;
color_selection_dlg = gtk_color_chooser_dialog_new(title, GTK_WINDOW(gtk_widget_get_toplevel(button)));
csdi->color_selection_dlg = color_selection_dlg;
color_t_to_gdkRGBAcolor(&rgba_color, csdi->color);
gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(color_selection_dlg), &rgba_color);
}
#else
{
GdkColor gcolor;
GtkWidget *color_selection;
GtkWidget *color_selection_dlg_help_btn;
color_selection_dlg = gtk_color_selection_dialog_new(title);
gtk_container_set_border_width (GTK_CONTAINER (color_selection_dlg), 10);
gtk_window_set_transient_for(GTK_WINDOW(color_selection_dlg), GTK_WINDOW(gtk_widget_get_toplevel(button)));
gtk_window_set_destroy_with_parent(GTK_WINDOW(color_selection_dlg), TRUE);
g_object_get(color_selection_dlg, "help-button", &color_selection_dlg_help_btn, NULL);
gtk_widget_destroy(color_selection_dlg_help_btn);
color_selection =
gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_selection_dlg));
color_t_to_gdkcolor(&gcolor, csdi->color);
gtk_color_selection_set_current_color(GTK_COLOR_SELECTION(color_selection), &gcolor);
csdi->color_selection_dlg = color_selection_dlg;
}
#endif
g_free(title);
g_signal_connect(G_OBJECT(color_selection_dlg), "response", G_CALLBACK(color_selection_dlg_response_cb), csdi);
g_signal_connect(G_OBJECT(color_selection_dlg), "destroy", G_CALLBACK(color_selection_dlg_destroy_cb), csdi);
gtk_widget_show_all(color_selection_dlg);
}
static void
color_edit_dlg_fg_bg_btn_destroy_cb(GObject *object _U_, gpointer user_data)
{
color_selection_dlg_info_t *csdi = (color_selection_dlg_info_t *)user_data;
g_free(csdi);
}
static void
color_selection_dlg_response_cb(GtkWidget *color_selection_dlg, gint response, gpointer user_data)
{
color_selection_dlg_info_t *csdi = (color_selection_dlg_info_t *)user_data;
if (response != GTK_RESPONSE_OK) {
window_destroy(color_selection_dlg);
return;
}
#if GTK_CHECK_VERSION(3,4,0)
{
GdkRGBA new_rgba_color;
gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(color_selection_dlg), &new_rgba_color);
if (csdi->color_selection_type == COLOR_SELECTION_TYPE_FG)
gtk_widget_override_color(csdi->filt_name_entry, GTK_STATE_FLAG_NORMAL, &new_rgba_color);
else
gtk_widget_override_background_color(csdi->filt_name_entry, GTK_STATE_FLAG_NORMAL, &new_rgba_color);
}
#elif GTK_CHECK_VERSION(3,0,0)
{
GtkWidget *color_selection;
GdkRGBA new_rgba_color;
color_selection =
gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_selection_dlg));
gtk_color_selection_get_current_rgba(GTK_COLOR_SELECTION(color_selection), &new_rgba_color);
if (csdi->color_selection_type == COLOR_SELECTION_TYPE_FG)
gtk_widget_override_color(csdi->filt_name_entry, GTK_STATE_FLAG_NORMAL, &new_rgba_color);
else
gtk_widget_override_background_color(csdi->filt_name_entry, GTK_STATE_FLAG_NORMAL, &new_rgba_color);
}
#else
{
GtkWidget *color_selection;
GdkColor new_color;
color_selection =
gtk_color_selection_dialog_get_color_selection(GTK_COLOR_SELECTION_DIALOG(color_selection_dlg));
gtk_color_selection_get_current_color(GTK_COLOR_SELECTION(color_selection), &new_color);
if (csdi->color_selection_type == COLOR_SELECTION_TYPE_FG)
gtk_widget_modify_text(csdi->filt_name_entry, GTK_STATE_NORMAL, &new_color);
else
gtk_widget_modify_base(csdi->filt_name_entry, GTK_STATE_NORMAL, &new_color);
}
#endif
window_destroy(color_selection_dlg);
}
static void
color_selection_dlg_destroy_cb(GObject *object _U_, gpointer user_data)
{
color_selection_dlg_info_t *csdi = (color_selection_dlg_info_t *)user_data;
g_assert(csdi->color_selection_dlg);
csdi->color_selection_dlg = NULL;
}
