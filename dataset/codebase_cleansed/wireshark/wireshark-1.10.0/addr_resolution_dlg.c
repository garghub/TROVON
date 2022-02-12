static void
addres_resolution_to_texbuff(GtkTextBuffer *buffer)
{
struct addrinfo *ai;
struct sockaddr_in *sa4;
struct sockaddr_in6 *sa6;
char addr_str[ADDRSTRLEN];
int i, tab_count;
gchar string_buff[ADDRESS_STR_MAX];
g_snprintf(string_buff, ADDRESS_STR_MAX, "# Hosts information in Wireshark \n#\n");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
g_snprintf(string_buff, ADDRESS_STR_MAX, "# Host data gathered from %s\n\n", cfile.filename);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
for (ai = get_addrinfo_list(); ai; ai = ai->ai_next) {
if (ai->ai_family != AF_INET) {
continue;
}
sa4 = (struct sockaddr_in *)(void *)ai->ai_addr;
if (inet_ntop(AF_INET, &(sa4->sin_addr.s_addr), addr_str, ADDRSTRLEN)) {
tab_count = (HOSTNAME_POS - (int)strlen(addr_str)) / 8;
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s", addr_str);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
for (i = 0; i < tab_count; i++){
g_snprintf(string_buff, ADDRESS_STR_MAX, "\t");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s\n", ai->ai_canonname);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
}
for (ai = get_addrinfo_list(); ai; ai = ai->ai_next) {
if (ai->ai_family != AF_INET6) {
continue;
}
sa6 = (struct sockaddr_in6 *)(void *)ai->ai_addr;
if (inet_ntop(AF_INET6, sa6->sin6_addr.s6_addr, addr_str, ADDRSTRLEN)) {
tab_count = (HOSTNAME_POS - (int)strlen(addr_str)) / 8;
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s", addr_str);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
for (i = 0; i < tab_count; i++){
g_snprintf(string_buff, ADDRESS_STR_MAX, "\t");
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
g_snprintf(string_buff, ADDRESS_STR_MAX, "%s\n", ai->ai_canonname);
gtk_text_buffer_insert_at_cursor (buffer, string_buff, -1);
}
}
}
void
addr_resolution_dlg (GtkAction *action _U_, gpointer data _U_)
{
GtkWidget *vbox;
GtkWidget *view;
GtkWidget *scroll;
GtkWidget *bbox;
GtkWidget *ok_bt, *cancel_bt, *help_bt;
GtkTextBuffer *buffer;
addr_resolution_dlg_w = dlg_window_new ("Address Resolution");
gtk_widget_set_size_request (addr_resolution_dlg_w, 750, 350);
gtk_window_set_resizable (GTK_WINDOW (addr_resolution_dlg_w), TRUE);
gtk_container_set_border_width (GTK_CONTAINER (addr_resolution_dlg_w), DLG_OUTER_MARGIN);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add (GTK_CONTAINER (addr_resolution_dlg_w), vbox);
gtk_widget_show (vbox);
view = gtk_text_view_new ();
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(view), GTK_WRAP_WORD);
buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
gtk_widget_modify_font(view, user_font_get_regular());
gtk_widget_show (view);
scroll = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(scroll), view);
gtk_widget_show(scroll);
gtk_box_pack_start(GTK_BOX (vbox), scroll, TRUE, TRUE, 0);
addres_resolution_to_texbuff(buffer);
bbox = dlg_button_row_new (GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_sensitive (ok_bt, TRUE);
cancel_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button (addr_resolution_dlg_w, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data (G_OBJECT(bbox), GTK_STOCK_HELP);
#if 0
g_signal_connect (help_bt, "clicked",NULL, NULL);
#endif
gtk_widget_set_sensitive (help_bt, FALSE);
gtk_widget_grab_default (ok_bt);
gtk_widget_show (addr_resolution_dlg_w);
}
