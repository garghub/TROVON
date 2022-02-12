void
toolbar_redraw_all(void)
{
GtkWidget *main_tb;
GtkWidget *filter_tb;
main_tb = (GtkWidget *)g_object_get_data(G_OBJECT(top_level), E_TB_MAIN_KEY);
gtk_toolbar_set_style(GTK_TOOLBAR(main_tb),
(GtkToolbarStyle)prefs.gui_toolbar_main_style);
filter_tb = (GtkWidget *)g_object_get_data(G_OBJECT(top_level), E_TB_FILTER_KEY);
if(filter_tb)
gtk_toolbar_set_style(GTK_TOOLBAR(filter_tb),
(GtkToolbarStyle)prefs.gui_toolbar_filter_style);
}
void set_start_button_sensitive(gboolean enable) {
gtk_widget_set_sensitive(GTK_WIDGET(new_button), enable);
}
void set_toolbar_for_capture_file(capture_file *cf) {
if (toolbar_init) {
if (cf == NULL || cf->state == FILE_READ_IN_PROGRESS) {
gtk_widget_set_sensitive(GTK_WIDGET(save_button), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(close_button), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(reload_button), FALSE);
} else {
gtk_widget_set_sensitive(GTK_WIDGET(save_button), cf_can_save(cf));
gtk_widget_set_sensitive(GTK_WIDGET(close_button), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(reload_button), TRUE);
}
}
}
void set_toolbar_for_packet_history(gboolean back_history, gboolean forward_history) {
gtk_widget_set_sensitive(GTK_WIDGET(history_back_button), back_history);
gtk_widget_set_sensitive(GTK_WIDGET(history_forward_button), forward_history);
}
void set_toolbar_for_capture_in_progress(gboolean capture_in_progress) {
if (toolbar_init) {
#ifdef HAVE_LIBPCAP
gtk_widget_set_sensitive(GTK_WIDGET(capture_options_button), !capture_in_progress);
gtk_widget_set_sensitive(GTK_WIDGET(new_button), !capture_in_progress);
gtk_widget_set_sensitive(GTK_WIDGET(stop_button), capture_in_progress);
gtk_widget_set_sensitive(GTK_WIDGET(clear_button), capture_in_progress);
if (!capture_in_progress) {
gtk_widget_set_sensitive(GTK_WIDGET(new_button), (global_capture_opts.num_selected > 0));
}
#endif
gtk_widget_set_sensitive(GTK_WIDGET(open_button), !capture_in_progress);
}
}
void set_toolbar_for_capture_stopping(void) {
if (toolbar_init) {
#ifdef HAVE_LIBPCAP
gtk_widget_set_sensitive(GTK_WIDGET(stop_button), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(clear_button), FALSE);
#endif
}
}
void set_toolbar_for_captured_packets(gboolean have_captured_packets) {
if (toolbar_init) {
gtk_widget_set_sensitive(GTK_WIDGET(find_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(history_back_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(history_forward_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(go_to_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(go_to_top_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(go_to_bottom_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(zoom_in_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(zoom_out_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(zoom_100_button),
have_captured_packets);
gtk_widget_set_sensitive(GTK_WIDGET(resize_columns_button),
have_captured_packets);
}
}
static void toolbar_append_separator(GtkWidget *toolbar) {
GtkToolItem *tool_item = gtk_separator_tool_item_new();
gtk_toolbar_insert(GTK_TOOLBAR(toolbar), tool_item, -1);
gtk_widget_show(GTK_WIDGET(tool_item));
}
static void
colorize_toggle_cb(GtkWidget *toggle_button, gpointer user_data _U_) {
main_colorize_changed(TOGGLE_BUTTON_GET_ACTIVE(TOGGLE_BUTTON(toggle_button)));
}
void
toolbar_colorize_changed(gboolean packet_list_colorize) {
if(TOGGLE_BUTTON_GET_ACTIVE(TOGGLE_BUTTON(colorize_button)) != packet_list_colorize) {
TOGGLE_BUTTON_SET_ACTIVE(TOGGLE_BUTTON(colorize_button), packet_list_colorize);
}
}
static void
auto_scroll_live_toggle_cb(GtkWidget *autoscroll_button_lcl, gpointer user_data _U_) {
main_auto_scroll_live_changed(TOGGLE_BUTTON_GET_ACTIVE(TOGGLE_BUTTON(autoscroll_button_lcl)));
}
void
toolbar_auto_scroll_live_changed(gboolean auto_scroll_live_lcl) {
if(TOGGLE_BUTTON_GET_ACTIVE(TOGGLE_BUTTON(autoscroll_button)) != auto_scroll_live_lcl) {
TOGGLE_BUTTON_SET_ACTIVE(TOGGLE_BUTTON(autoscroll_button), auto_scroll_live_lcl);
}
}
static void
plugin_if_maintoolbar_goto_frame(gconstpointer user_data)
{
if ( user_data != NULL )
{
GHashTable * dataSet = (GHashTable *) user_data;
gpointer framenr;
if ( g_hash_table_lookup_extended(dataSet, "frame_nr", NULL, &framenr ) )
{
if ( GPOINTER_TO_UINT(framenr) != 0 )
cf_goto_frame(&cfile, GPOINTER_TO_UINT(framenr));
}
}
}
GtkWidget *
toolbar_new(void)
{
GtkWidget *main_tb;
GtkWidget *window = top_level;
g_assert(!toolbar_init);
gtk_widget_realize(window);
main_tb = gtk_toolbar_new();
gtk_orientable_set_orientation(GTK_ORIENTABLE(main_tb),
GTK_ORIENTATION_HORIZONTAL);
g_object_set_data(G_OBJECT(top_level), E_TB_MAIN_KEY, main_tb);
#ifdef HAVE_LIBPCAP
toolbar_item(if_button, main_tb,
WIRESHARK_STOCK_CAPTURE_INTERFACES, "List the available capture interfaces...", capture_if_cb, NULL);
toolbar_item(capture_options_button, main_tb,
WIRESHARK_STOCK_CAPTURE_OPTIONS, "Show the capture options...", capture_prep_cb, NULL);
toolbar_item(new_button, main_tb,
WIRESHARK_STOCK_CAPTURE_START, "Start a new live capture", capture_start_cb, NULL);
toolbar_item(stop_button, main_tb,
WIRESHARK_STOCK_CAPTURE_STOP, "Stop the running live capture", capture_stop_cb, NULL);
toolbar_item(clear_button, main_tb,
WIRESHARK_STOCK_CAPTURE_RESTART, "Restart the running live capture", capture_restart_cb, NULL);
toolbar_append_separator(main_tb);
#endif
toolbar_item(open_button, main_tb,
GTK_STOCK_OPEN, "Open a capture file...", file_open_cmd_cb, NULL);
toolbar_item(save_button, main_tb,
WIRESHARK_STOCK_SAVE, "Save this capture file", file_save_cmd_cb, NULL);
toolbar_item(close_button, main_tb,
GTK_STOCK_CLOSE, "Close this capture file", file_close_cmd_cb, NULL);
toolbar_item(reload_button, main_tb,
GTK_STOCK_REFRESH, "Reload this capture file", file_reload_cmd_cb, NULL);
toolbar_append_separator(main_tb);
toolbar_item(find_button, main_tb,
GTK_STOCK_FIND, "Find a packet...", find_frame_cb, NULL);
toolbar_item(history_back_button, main_tb,
GTK_STOCK_GO_BACK, "Go back in packet history", history_back_cb, NULL);
toolbar_item(history_forward_button, main_tb,
GTK_STOCK_GO_FORWARD, "Go forward in packet history", history_forward_cb, NULL);
toolbar_item(go_to_button, main_tb,
GTK_STOCK_JUMP_TO, "Go to the packet with number...", goto_frame_cb, NULL);
toolbar_item(go_to_top_button, main_tb,
GTK_STOCK_GOTO_TOP, "Go to the first packet", goto_top_frame_cb, NULL);
toolbar_item(go_to_bottom_button, main_tb,
GTK_STOCK_GOTO_BOTTOM, "Go to the last packet", goto_bottom_frame_cb, NULL);
toolbar_append_separator(main_tb);
toolbar_toggle_button(colorize_button, window, main_tb,
WIRESHARK_STOCK_COLORIZE, "Colorize Packet List", colorize_toggle_cb, NULL);
#ifdef HAVE_LIBPCAP
toolbar_toggle_button(autoscroll_button, window, main_tb,
WIRESHARK_STOCK_AUTOSCROLL, "Auto Scroll Packet List in Live Capture", auto_scroll_live_toggle_cb, NULL);
#endif
toolbar_append_separator(main_tb);
toolbar_item(zoom_in_button, main_tb,
GTK_STOCK_ZOOM_IN, "Zoom in", view_zoom_in_cb, NULL);
toolbar_item(zoom_out_button, main_tb,
GTK_STOCK_ZOOM_OUT, "Zoom out", view_zoom_out_cb, NULL);
toolbar_item(zoom_100_button, main_tb,
GTK_STOCK_ZOOM_100, "Zoom 100%", view_zoom_100_cb, NULL);
toolbar_item(resize_columns_button, main_tb,
WIRESHARK_STOCK_RESIZE_COLUMNS, "Resize All Columns", packet_list_resize_columns_cb, NULL);
toolbar_append_separator(main_tb);
#ifdef HAVE_LIBPCAP
toolbar_item(capture_filter_button, main_tb,
WIRESHARK_STOCK_CAPTURE_FILTER, "Edit capture filter...", cfilter_dialog_cb, NULL);
#endif
toolbar_item(display_filter_button, main_tb,
WIRESHARK_STOCK_DISPLAY_FILTER, "Edit/apply display filter...", dfilter_dialog_cb, NULL);
toolbar_item(color_display_button, main_tb,
GTK_STOCK_SELECT_COLOR, "Edit coloring rules...", color_display_cb, NULL);
toolbar_item(prefs_button, main_tb,
GTK_STOCK_PREFERENCES, "Edit preferences...", prefs_cb, NULL);
toolbar_append_separator(main_tb);
toolbar_item(help_button, main_tb,
GTK_STOCK_HELP, "Show some help...", topic_cb, GINT_TO_POINTER(HELP_CONTENT));
toolbar_init = TRUE;
set_toolbar_for_captured_packets(FALSE);
set_toolbar_for_capture_file(NULL);
#ifdef HAVE_LIBPCAP
set_toolbar_for_capture_in_progress(FALSE);
#endif
toolbar_redraw_all();
plugin_if_register_gui_cb(PLUGIN_IF_GOTO_FRAME, plugin_if_maintoolbar_goto_frame);
return main_tb;
}
void
set_toolbar_object_data(const gchar *key, gpointer data)
{
g_object_set_data(G_OBJECT(open_button), key, data);
g_object_set_data(G_OBJECT(reload_button), key, data);
}
