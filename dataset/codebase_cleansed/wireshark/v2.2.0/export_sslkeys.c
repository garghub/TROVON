static gboolean
savesslkeys_save_clicked_cb(char *file, gchar *keylist)
{
int fd;
fd = ws_open(file, O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, 0666);
if (fd == -1) {
open_failure_alert_box(file, errno, TRUE);
return FALSE;
}
if (ws_write(fd, keylist, (unsigned int)strlen(keylist)) < 0) {
write_failure_alert_box(file, errno);
ws_close(fd);
return FALSE;
}
if (ws_close(fd) < 0) {
write_failure_alert_box(file, errno);
return FALSE;
}
g_free(keylist);
return TRUE;
}
void
savesslkeys_cb(GtkWidget * w _U_, gpointer data _U_)
{
win32_export_sslkeys_file(GDK_WINDOW_HWND(gtk_widget_get_window(top_level)));
return;
}
static char *
gtk_export_sslkeys_file(guint keylist_len)
{
GtkWidget *savesslkeys_dlg;
gchar *label;
GtkWidget *dlg_lb;
char *pathname;
savesslkeys_dlg = file_selection_new("Wireshark: Export SSL Session Keys",
GTK_WINDOW(top_level),
FILE_SELECTION_SAVE);
label = g_strdup_printf("Will save %u SSL Session %s to specified file.",
keylist_len, plurality(keylist_len, "key", "keys"));
dlg_lb = gtk_label_new(label);
g_free(label);
file_selection_set_extra_widget(savesslkeys_dlg, dlg_lb);
gtk_widget_show(dlg_lb);
pathname = file_selection_run(savesslkeys_dlg);
if (pathname == NULL) {
return NULL;
}
window_destroy(savesslkeys_dlg);
return pathname;
}
void
savesslkeys_cb(GtkWidget * w _U_, gpointer data _U_)
{
char *pathname;
guint keylist_len;
gchar *keylist;
keylist_len = ssl_session_key_count();
if (keylist_len==0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "There are no SSL Session Keys to save.");
return;
}
keylist = ssl_export_sessions();
for (;;) {
pathname = gtk_export_sslkeys_file(keylist_len);
if (pathname == NULL) {
break;
}
if (savesslkeys_save_clicked_cb(pathname, keylist)) {
g_free(pathname);
break;
}
g_free(pathname);
}
}
