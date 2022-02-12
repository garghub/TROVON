static void
pkt_comment_text_buff_ok_cb(GtkWidget *w _U_, GtkWidget *view)
{
GtkTextBuffer *buffer;
GtkTextIter start_iter;
GtkTextIter end_iter;
gchar *new_packet_comment;
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
gtk_text_buffer_get_start_iter (buffer, &start_iter);
gtk_text_buffer_get_end_iter (buffer, &end_iter);
new_packet_comment = gtk_text_buffer_get_text (buffer, &start_iter, &end_iter, FALSE );
packet_list_update_packet_comment(new_packet_comment);
expert_comp_packet_comment_updated();
status_expert_update();
window_destroy(edit_or_add_pkt_comment_dlg);
}
static void
capture_comment_text_buff_ok_cb(GtkWidget *w _U_, GtkWidget *view)
{
GtkTextBuffer *buffer;
GtkTextIter start_iter;
GtkTextIter end_iter;
gchar *new_capture_comment;
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
gtk_text_buffer_get_start_iter (buffer, &start_iter);
gtk_text_buffer_get_end_iter (buffer, &end_iter);
new_capture_comment = gtk_text_buffer_get_text (buffer, &start_iter, &end_iter, FALSE );
cf_update_section_comment(&cfile, new_capture_comment);
main_update_for_unsaved_changes(&cfile);
status_capture_comment_update();
window_destroy(edit_or_add_capture_comment_dlg);
}
void
edit_packet_comment_dlg (GtkAction *action _U_, gpointer data _U_)
{
GtkWidget *vbox;
GtkWidget *view;
GtkWidget *scroll;
GtkWidget *bbox;
GtkWidget *ok_bt, *cancel_bt, *help_bt;
GtkTextBuffer *buffer;
gchar *opt_comment;
edit_or_add_pkt_comment_dlg = dlg_window_new ("Edit or Add Packet Comments");
gtk_widget_set_size_request (edit_or_add_pkt_comment_dlg, 500, 160);
gtk_window_set_resizable (GTK_WINDOW (edit_or_add_pkt_comment_dlg), TRUE);
gtk_container_set_border_width (GTK_CONTAINER (edit_or_add_pkt_comment_dlg), DLG_OUTER_MARGIN);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add (GTK_CONTAINER (edit_or_add_pkt_comment_dlg), vbox);
gtk_widget_show (vbox);
view = gtk_text_view_new ();
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(view), GTK_WRAP_WORD);
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
gtk_widget_show (view);
scroll = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(scroll), view);
gtk_widget_show(scroll);
gtk_box_pack_start(GTK_BOX (vbox), scroll, TRUE, TRUE, 0);
opt_comment = packet_list_get_packet_comment();
if(opt_comment){
gtk_text_buffer_set_text(buffer, opt_comment, -1);
g_free(opt_comment);
}
bbox = dlg_button_row_new (GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect (ok_bt, "clicked", G_CALLBACK(pkt_comment_text_buff_ok_cb), view);
gtk_widget_set_sensitive (ok_bt, TRUE);
cancel_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button (edit_or_add_pkt_comment_dlg, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_HELP);
#if 0
g_signal_connect (help_bt, "clicked",NULL, NULL);
#endif
gtk_widget_set_sensitive (help_bt, FALSE);
gtk_widget_grab_default (ok_bt);
g_signal_connect (edit_or_add_pkt_comment_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show (edit_or_add_pkt_comment_dlg);
}
static void
edit_capture_comment_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
edit_or_add_capture_comment_dlg = NULL;
}
void
edit_capture_comment_dlg_launch (GtkAction *action _U_, gpointer data _U_)
{
GtkWidget *vbox;
GtkWidget *view;
GtkWidget *scroll;
GtkWidget *bbox;
GtkWidget *ok_bt, *cancel_bt, *help_bt;
GtkTextBuffer *buffer = NULL;
const gchar *comment_str = NULL;
if (edit_or_add_capture_comment_dlg != NULL) {
reactivate_window(edit_or_add_capture_comment_dlg);
return;
}
edit_or_add_capture_comment_dlg = dlg_window_new ("Edit or Add Capture Comments");
gtk_widget_set_size_request (edit_or_add_capture_comment_dlg, 500, 160);
gtk_window_set_resizable (GTK_WINDOW (edit_or_add_capture_comment_dlg), TRUE);
gtk_container_set_border_width (GTK_CONTAINER (edit_or_add_capture_comment_dlg), DLG_OUTER_MARGIN);
g_signal_connect(edit_or_add_capture_comment_dlg, "destroy",
G_CALLBACK(edit_capture_comment_destroy_cb), NULL);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add (GTK_CONTAINER (edit_or_add_capture_comment_dlg), vbox);
gtk_widget_show (vbox);
view = gtk_text_view_new ();
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(view), GTK_WRAP_WORD);
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
gtk_widget_show (view);
scroll = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(scroll), view);
gtk_widget_show(scroll);
gtk_box_pack_start(GTK_BOX (vbox), scroll, TRUE, TRUE, 0);
comment_str = cf_read_section_comment(&cfile);
if(comment_str != NULL){
gtk_text_buffer_set_text (buffer, comment_str, -1);
}
bbox = dlg_button_row_new (GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect (ok_bt, "clicked", G_CALLBACK(capture_comment_text_buff_ok_cb), view);
gtk_widget_set_sensitive (ok_bt, TRUE);
cancel_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button (edit_or_add_capture_comment_dlg, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_HELP);
#if 0
g_signal_connect (help_bt, "clicked",NULL, NULL);
#endif
gtk_widget_set_sensitive (help_bt, FALSE);
gtk_widget_grab_default (ok_bt);
g_signal_connect (edit_or_add_capture_comment_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show (edit_or_add_capture_comment_dlg);
}
void
edit_capture_comment_dlg_hide(void)
{
window_destroy(edit_or_add_capture_comment_dlg);
}
