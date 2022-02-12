static void
ssl_export_sessions_func(gpointer key, gpointer value, gpointer user_data)
{
guint i;
size_t offset;
StringInfo* sslid = (StringInfo*)key;
StringInfo* mastersecret = (StringInfo*)value;
StringInfo* keylist = (StringInfo*)user_data;
offset = strlen(keylist->data);
g_snprintf(keylist->data+offset,(gulong)(keylist->data_len-offset),"RSA Session-ID:");
offset += 15;
for( i=0; i<sslid->data_len; i++) {
g_snprintf(keylist->data+offset,(gulong)(keylist->data_len-offset),"%.2x",sslid->data[i]&255);
offset += 2;
}
g_snprintf(keylist->data+offset,(gulong)(keylist->data_len-offset)," Master-Key:");
offset += 12;
for( i=0; i<mastersecret->data_len; i++) {
g_snprintf(keylist->data+offset,(gulong)(keylist->data_len-offset),"%.2x",mastersecret->data[i]&255);
offset += 2;
}
g_snprintf(keylist->data+offset,(gulong)(keylist->data_len-offset),"\n");
}
StringInfo*
ssl_export_sessions(GHashTable *session_hash)
{
StringInfo* keylist;
keylist = g_malloc0(sizeof(StringInfo)+189*g_hash_table_size (session_hash));
keylist->data = ((guchar*)keylist+sizeof(StringInfo));
keylist->data_len = sizeof(StringInfo)+189*g_hash_table_size (session_hash);
g_hash_table_foreach(session_hash, ssl_export_sessions_func, (gpointer)keylist);
return keylist;
}
static void
savesslkeys_dlg_destroy_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
savesslkeys_dlg = NULL;
}
static gboolean
savesslkeys_save_clicked_cb(GtkWidget * w _U_, gpointer data _U_)
{
int fd;
char *file;
StringInfo *keylist;
file = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(savesslkeys_dlg));
if (test_for_directory(file) == EISDIR) {
set_last_open_dir(file);
g_free(file);
file_selection_set_current_folder(savesslkeys_dlg, get_last_open_dir());
gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(savesslkeys_dlg), "");
return FALSE;
}
keylist = ssl_export_sessions(ssl_session_hash);
if (keylist->data_len == 0 ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"No SSL Session Keys to export!");
g_free(keylist);
g_free(file);
return TRUE;
}
fd = ws_open(file, O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, 0666);
if (fd == -1) {
open_failure_alert_box(file, errno, TRUE);
g_free(keylist);
g_free(file);
return TRUE;
}
if (ws_write(fd, keylist->data, (unsigned int)strlen(keylist->data)) < 0) {
write_failure_alert_box(file, errno);
ws_close(fd);
g_free(keylist);
g_free(file);
return TRUE;
}
if (ws_close(fd) < 0) {
write_failure_alert_box(file, errno);
g_free(keylist);
g_free(file);
return TRUE;
}
g_free(keylist);
g_free(file);
return TRUE;
}
void
savesslkeys_cb(GtkWidget * w _U_, gpointer data _U_)
{
win32_export_sslkeys_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
return;
}
void
savesslkeys_cb(GtkWidget * w _U_, gpointer data _U_)
{
gchar *label;
GtkWidget *dlg_lb;
guint keylist_len;
keylist_len = g_hash_table_size(ssl_session_hash);
if (keylist_len==0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "There are no SSL Session Keys to save!");
return;
}
savesslkeys_dlg = file_selection_new("Wireshark: Export SSL Session Keys", FILE_SELECTION_SAVE);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(savesslkeys_dlg), TRUE);
label = g_strdup_printf("Will save %u SSL Session %s to specified file.",
keylist_len, plurality(keylist_len, "key", "keys"));
dlg_lb = gtk_label_new(label);
g_free(label);
file_selection_set_extra_widget(savesslkeys_dlg, dlg_lb);
gtk_widget_show(dlg_lb);
g_signal_connect(savesslkeys_dlg, "destroy", G_CALLBACK(savesslkeys_dlg_destroy_cb), NULL);
while (gtk_dialog_run(GTK_DIALOG(savesslkeys_dlg)) == GTK_RESPONSE_ACCEPT) {
if (savesslkeys_save_clicked_cb(NULL, savesslkeys_dlg)) {
break;
}
}
window_destroy(savesslkeys_dlg);
}
