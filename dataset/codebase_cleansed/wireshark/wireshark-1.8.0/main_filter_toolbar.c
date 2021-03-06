static void
filter_activate_cb(GtkWidget *w _U_, gpointer data)
{
const char *s;
s = gtk_entry_get_text(GTK_ENTRY(data));
main_filter_packets(&cfile, s, FALSE);
}
static void
filter_changed_cb(GtkWidget *w _U_, gpointer data)
{
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(data), E_DFILTER_APPLY_KEY), TRUE);
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(data), E_DFILTER_CLEAR_KEY), TRUE);
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(data), E_DFILTER_SAVE_KEY), TRUE);
}
static void
filter_reset_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *filter_te = NULL;
if ((filter_te = g_object_get_data(G_OBJECT(w), E_DFILTER_TE_KEY))) {
gtk_entry_set_text(GTK_ENTRY(filter_te), "");
}
main_filter_packets(&cfile, NULL, FALSE);
}
static void
filter_save_cb(GtkWidget *w _U_, GtkWindow *parent_w)
{
filter_expression_save_dlg(parent_w);
}
GtkWidget *
filter_toolbar_new(void)
{
GtkWidget *filter_cm;
GtkWidget *filter_te;
GtkWidget *filter_tb;
GtkToolItem *filter_bt, *filter_add_expr_bt, *filter_reset;
GtkToolItem *filter_apply, *filter_save, *item;
static construct_args_t args = {
"Wireshark: Display Filter",
TRUE,
TRUE,
FALSE
};
filter_tb = gtk_toolbar_new();
gtk_orientable_set_orientation(GTK_ORIENTABLE(filter_tb),
GTK_ORIENTATION_HORIZONTAL);
g_object_set_data(G_OBJECT(top_level), E_TB_FILTER_KEY, filter_tb);
gtk_widget_show(filter_tb);
filter_bt = gtk_tool_button_new_from_stock (WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
gtk_widget_show(GTK_WIDGET (filter_bt));
g_object_set_data(G_OBJECT(top_level), E_FILT_BT_PTR_KEY, filter_bt);
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb),
filter_bt,
-1);
gtk_widget_set_tooltip_text(GTK_WIDGET(filter_bt), "Open the \"Display Filter\" dialog, to edit/apply filters");
filter_cm = gtk_combo_box_text_new_with_entry ();
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
main_display_filter_widget=filter_te;
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
g_object_set_data(G_OBJECT(filter_te), E_DFILTER_CM_KEY, filter_cm);
g_object_set_data(G_OBJECT(top_level), E_DFILTER_CM_KEY, filter_cm);
g_signal_connect(filter_te, "activate", G_CALLBACK(filter_activate_cb), filter_te);
g_signal_connect(filter_te, "changed", G_CALLBACK(filter_changed_cb), filter_cm);
g_signal_connect(filter_te, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_tb), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_object_set_data(G_OBJECT(filter_te), E_FILT_FIELD_USE_STATUSBAR_KEY, "");
g_signal_connect(filter_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(filter_tb, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
gtk_widget_set_size_request(filter_cm, 400, -1);
gtk_widget_show(filter_cm);
item = gtk_tool_item_new ();
gtk_container_add (GTK_CONTAINER (item), filter_cm);
gtk_widget_show (GTK_WIDGET (item));
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb), item, -1);
gtk_widget_set_tooltip_text(filter_cm,
"Enter a display filter, or choose one of your recently used filters. "
"The background color of this field is changed by a continuous syntax check "
"(green is valid, red is invalid, yellow may have unexpected results).");
filter_add_expr_bt = gtk_tool_button_new_from_stock(WIRESHARK_STOCK_ADD_EXPRESSION);
g_object_set_data(G_OBJECT(filter_tb), E_FILT_FILTER_TE_KEY, filter_te);
g_signal_connect(filter_add_expr_bt, "clicked", G_CALLBACK(filter_add_expr_bt_cb), filter_tb);
gtk_widget_show(GTK_WIDGET(filter_add_expr_bt));
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb),
filter_add_expr_bt,
-1);
gtk_widget_set_tooltip_text(GTK_WIDGET(filter_add_expr_bt), "Add an expression to this filter string");
filter_reset = gtk_tool_button_new_from_stock(WIRESHARK_STOCK_CLEAR_EXPRESSION);
g_object_set_data(G_OBJECT(filter_reset), E_DFILTER_TE_KEY, filter_te);
g_object_set_data (G_OBJECT(filter_cm), E_DFILTER_CLEAR_KEY, filter_reset);
g_signal_connect(filter_reset, "clicked", G_CALLBACK(filter_reset_cb), NULL);
gtk_widget_set_sensitive (GTK_WIDGET(filter_reset), FALSE);
gtk_widget_show(GTK_WIDGET(filter_reset));
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb),
filter_reset,
-1);
gtk_widget_set_tooltip_text(GTK_WIDGET(filter_reset), "Clear this filter string and update the display");
filter_apply = gtk_tool_button_new_from_stock(WIRESHARK_STOCK_APPLY_EXPRESSION);
g_object_set_data(G_OBJECT(filter_apply), E_DFILTER_CM_KEY, filter_cm);
g_object_set_data (G_OBJECT(filter_cm), E_DFILTER_APPLY_KEY, filter_apply);
g_signal_connect(filter_apply, "clicked", G_CALLBACK(filter_activate_cb), filter_te);
gtk_widget_set_sensitive (GTK_WIDGET(filter_apply), FALSE);
gtk_widget_show(GTK_WIDGET(filter_apply));
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb),
filter_apply,
-1);
gtk_widget_set_tooltip_text(GTK_WIDGET(filter_apply), "Apply this filter string to the display");
filter_save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
g_object_set_data(G_OBJECT(filter_save), E_DFILTER_CM_KEY, filter_cm);
g_object_set_data(G_OBJECT(filter_cm), E_DFILTER_SAVE_KEY, filter_save);
g_signal_connect(filter_save, "clicked", G_CALLBACK(filter_save_cb), filter_te);
gtk_widget_set_sensitive (GTK_WIDGET(filter_save), FALSE);
gtk_widget_show(GTK_WIDGET(filter_save));
gtk_toolbar_insert(GTK_TOOLBAR(filter_tb),
filter_save,
-1);
gtk_widget_set_tooltip_text(GTK_WIDGET(filter_save), "Save this filter string");
set_menu_object_data(MENU_BAR_PATH_FILE_OPEN, E_DFILTER_TE_KEY, filter_te);
set_menu_object_data(MENU_BAR_PATH_EDIT_COPY_AS_FLT, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_DISPLAY_FLT, E_FILT_TE_PTR_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_FOLLOW_TCP_STREAM, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_FOLLOW_UDP_STREAM, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_FOLLOW_SSL_STREAM, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_AND_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_OR_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_AND_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_APL_AS_FLT_OR_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_AND_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_OR_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_AND_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_menu_object_data(MENU_BAR_PATH_ANALYZE_PREP_A_FLT_OR_NOT_SEL, E_DFILTER_TE_KEY,
filter_te);
set_toolbar_object_data(E_DFILTER_TE_KEY, filter_te);
g_object_set_data(G_OBJECT(popup_menu_object), E_DFILTER_TE_KEY, filter_te);
filter_expression_save_dlg_init(filter_tb, filter_te);
toolbar_redraw_all();
return filter_tb;
}
static gboolean
dfilter_entry_match(GtkWidget *filter_cm, char *s, int *index)
{
GtkTreeModel *model = gtk_combo_box_get_model (GTK_COMBO_BOX(filter_cm));
GtkTreeIter iter;
GValue value = { 0, {{0}}};
const char *filter_str;
int i;
i = -1;
if (!gtk_tree_model_get_iter_first (model, &iter)) {
*index = i;
return FALSE;
}
do {
i++;
gtk_tree_model_get_value (model, &iter, 0, &value);
filter_str = g_value_get_string (&value);
if(filter_str) {
if(strcmp(s, filter_str) == 0) {
g_value_unset (&value);
*index = i;
return TRUE;
}
}
g_value_unset (&value);
} while (gtk_tree_model_iter_next (model, &iter));
*index = i;
return FALSE;
}
static gboolean
dfilter_combo_add(GtkWidget *filter_cm, char *s) {
int index;
if(!dfilter_entry_match(filter_cm,s, &index))
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(filter_cm), s);
g_free(s);
return TRUE;
}
void
dfilter_recent_combo_write_all(FILE *rf) {
GtkWidget *filter_cm = g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
GtkTreeModel *model = gtk_combo_box_get_model (GTK_COMBO_BOX(filter_cm));
GtkTreeIter iter;
GValue value = { 0, {{0}}};
const char *filter_str;
guint max_count = 0;
if (!gtk_tree_model_get_iter_first (model, &iter))
return;
do {
gtk_tree_model_get_value (model, &iter, 0, &value);
filter_str = g_value_get_string (&value);
if(filter_str)
fprintf (rf, RECENT_KEY_DISPLAY_FILTER ": %s\n", filter_str);
g_value_unset (&value);
} while (gtk_tree_model_iter_next (model, &iter)&& (max_count++ < prefs.gui_recent_df_entries_max));
}
gboolean
dfilter_combo_add_recent(gchar *s) {
GtkWidget *filter_cm = g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
char *dup;
dup = g_strdup(s);
return dfilter_combo_add(filter_cm, dup);
}
gboolean
main_filter_packets(capture_file *cf, const gchar *dftext, gboolean force)
{
GtkWidget *filter_cm = g_object_get_data(G_OBJECT(top_level), E_DFILTER_CM_KEY);
gboolean free_filter = TRUE;
char *s;
cf_status_t cf_status;
s = g_strdup(dftext);
cf_status = cf_filter_packets(cf, s, force);
if (cf_status == CF_OK) {
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(filter_cm), E_DFILTER_APPLY_KEY), FALSE);
if (!s || strlen (s) == 0) {
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(filter_cm), E_DFILTER_CLEAR_KEY), FALSE);
gtk_widget_set_sensitive (g_object_get_data (G_OBJECT(filter_cm), E_DFILTER_SAVE_KEY), FALSE);
}
}
if (!s)
return (cf_status == CF_OK);
if (cf_status == CF_OK && strlen(s) > 0) {
int index;
if(!dfilter_entry_match(filter_cm,s, &index) || index != 0) {
if (index > 0) {
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(filter_cm), index);
index--;
}
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(filter_cm), s);
index++;
}
while ((guint)index >= prefs.gui_recent_df_entries_max) {
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(filter_cm), index);
index--;
}
}
if (free_filter)
g_free(s);
return (cf_status == CF_OK);
}
