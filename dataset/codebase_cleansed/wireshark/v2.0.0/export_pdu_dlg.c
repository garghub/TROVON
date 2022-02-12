static void
export_pdu_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
export_pdu_dlg = NULL;
}
void
export_pdu_action(gpointer data)
{
const char *filter = NULL;
exp_pdu_dlg_t *exp_pdu_dlg_data = (exp_pdu_dlg_t *)data;
gchar *tap_name = NULL;
filter = gtk_entry_get_text(GTK_ENTRY(exp_pdu_dlg_data->filter_widget));
tap_name = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(exp_pdu_dlg_data->tap_name_widget));
do_export_pdu(filter, tap_name, &(exp_pdu_dlg_data->exp_pdu_tap_data));
window_destroy(export_pdu_dlg);
g_free(exp_pdu_dlg_data);
}
void
export_pdu_show_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb, *bbox, *close_bt, *ok_bt;
GtkWidget *grid, *filter_bt;
exp_pdu_dlg_t *exp_pdu_dlg_data;
const char *filter = NULL;
guint row;
GSList *tap_name_list;
static construct_args_t args = {
"Wireshark: Export PDUs Filter",
TRUE,
FALSE,
FALSE
};
if (export_pdu_dlg != NULL) {
reactivate_window(export_pdu_dlg);
return;
}
exp_pdu_dlg_data = (exp_pdu_dlg_t *)g_malloc(sizeof(exp_pdu_dlg_t));
exp_pdu_dlg_data->exp_pdu_tap_data.pkt_encap = wtap_wtap_encap_to_pcap_encap(WTAP_ENCAP_WIRESHARK_UPPER_PDU);
export_pdu_dlg = window_new(GTK_WINDOW_TOPLEVEL, "Wireshark: Export PDUs to pcap-ng file");
g_signal_connect(export_pdu_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(export_pdu_dlg, "destroy", G_CALLBACK(export_pdu_destroy_cb), NULL);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 3);
gtk_container_add(GTK_CONTAINER(export_pdu_dlg), main_vb);
grid = ws_gtk_grid_new();
ws_gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
ws_gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
gtk_box_pack_start(GTK_BOX(main_vb), grid, TRUE, TRUE, 0);
row = 0;
filter_bt=ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), filter_bt, 0, row, 1, 1);
gtk_widget_show(filter_bt);
exp_pdu_dlg_data->filter_widget=gtk_entry_new();
g_signal_connect(exp_pdu_dlg_data->filter_widget, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(grid), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(exp_pdu_dlg_data->filter_widget, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, exp_pdu_dlg_data->filter_widget);
filter=gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
if(filter){
gtk_entry_set_text(GTK_ENTRY(exp_pdu_dlg_data->filter_widget), filter);
} else {
colorize_filter_te_as_empty(exp_pdu_dlg_data->filter_widget);
}
ws_gtk_grid_attach_defaults(GTK_GRID(grid), exp_pdu_dlg_data->filter_widget, 1, row, 1, 1);
gtk_widget_show(exp_pdu_dlg_data->filter_widget);
row++;
exp_pdu_dlg_data->tap_name_widget = gtk_combo_box_text_new();
for (tap_name_list = get_export_pdu_tap_list(); tap_name_list; tap_name_list = g_slist_next(tap_name_list)) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(exp_pdu_dlg_data->tap_name_widget), (const char*)(tap_name_list->data));
}
gtk_combo_box_set_active(GTK_COMBO_BOX(exp_pdu_dlg_data->tap_name_widget), 0);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), exp_pdu_dlg_data->tap_name_widget, 0, row, 1, 1);
gtk_widget_show(exp_pdu_dlg_data->tap_name_widget);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_end(GTK_BOX(main_vb), bbox, FALSE, FALSE, 3);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(export_pdu_dlg, close_bt, window_cancel_button_cb);
gtk_widget_set_tooltip_text(close_bt, "Close this dialog");
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(file_export_pdu_ok_cb), exp_pdu_dlg_data);
gtk_widget_grab_default(ok_bt);
gtk_widget_set_tooltip_text(ok_bt, "Export PDUs to a temporary capture file");
gtk_widget_show_all(export_pdu_dlg);
window_present(export_pdu_dlg);
}
