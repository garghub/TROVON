GtkWidget*
protocols_prefs_show(void)
{
GtkWidget *main_tb, *main_vb;
GtkWidget *display_hidden_cb;
int pos = 0;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 7, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
main_tb = gtk_table_new(PROTOCOLS_TABLE_ROWS, 1, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), main_tb, FALSE, FALSE, 0);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 15);
gtk_widget_show(main_tb);
display_hidden_cb = create_preference_check_button(main_tb, pos++,
"Display hidden protocol items:",
"Display all hidden protocol items in the packet list.",
prefs.display_hidden_proto_items);
g_object_set_data(G_OBJECT(main_vb), PROTOCOLS_SHOW_HIDDEN_KEY, display_hidden_cb);
gtk_widget_show_all(main_vb);
return main_vb;
}
void
protocols_prefs_fetch(GtkWidget *w _U_)
{
GtkWidget *display_hidden_cb;
display_hidden_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), PROTOCOLS_SHOW_HIDDEN_KEY);
prefs.display_hidden_proto_items = (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (display_hidden_cb)) ? TRUE : FALSE);
}
void
protocols_prefs_apply(GtkWidget *w _U_)
{
}
void
protocols_prefs_destroy(GtkWidget *w _U_)
{
}
