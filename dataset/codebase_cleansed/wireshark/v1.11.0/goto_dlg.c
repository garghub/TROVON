void
goto_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *goto_frame_w, *main_vb, *fnumber_hb, *fnumber_lb, *fnumber_te,
*bbox, *ok_bt, *cancel_bt, *help_bt;
goto_frame_w = dlg_window_new("Wireshark: Go To Packet");
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(goto_frame_w), main_vb);
gtk_widget_show(main_vb);
fnumber_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (main_vb), fnumber_hb, TRUE, TRUE, 0);
gtk_widget_show(fnumber_hb);
fnumber_lb = gtk_label_new("Packet number:");
gtk_box_pack_start(GTK_BOX(fnumber_hb), fnumber_lb, FALSE, FALSE, 0);
gtk_widget_show(fnumber_lb);
fnumber_te = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(fnumber_hb), fnumber_te, FALSE, FALSE, 0);
gtk_widget_show(fnumber_te);
bbox = dlg_button_row_new(GTK_STOCK_JUMP_TO, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX (main_vb), bbox, TRUE, TRUE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_JUMP_TO);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(goto_frame_ok_cb), goto_frame_w);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(goto_frame_w, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_GOTO_DIALOG);
gtk_widget_grab_default(ok_bt);
dlg_set_activate(fnumber_te, ok_bt);
gtk_widget_grab_focus(fnumber_te);
g_object_set_data(G_OBJECT(goto_frame_w), E_GOTO_FNUMBER_KEY, fnumber_te);
g_signal_connect(goto_frame_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show(goto_frame_w);
window_present(goto_frame_w);
}
static void
goto_frame_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
GtkWidget *fnumber_te;
const gchar *fnumber_text;
guint fnumber;
char *p;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_GOTO_FNUMBER_KEY);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (guint) strtoul(fnumber_text, &p, 10);
if (p == fnumber_text || *p != '\0') {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"The packet number you entered isn't a valid number.");
return;
}
if (cf_goto_frame(&cfile, fnumber)) {
window_destroy(GTK_WIDGET(parent_w));
}
}
void
goto_framenum_cb(GtkWidget *w _U_, gpointer data _U_)
{
cf_goto_framenum(&cfile);
}
void
goto_top_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
cf_goto_top_frame();
}
void
goto_bottom_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
cf_goto_bottom_frame();
}
void
goto_next_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
packet_list_next();
}
void
goto_previous_frame_cb(GtkWidget *w _U_, gpointer d _U_)
{
packet_list_prev();
}
