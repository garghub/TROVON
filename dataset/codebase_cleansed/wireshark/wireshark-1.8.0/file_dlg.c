GtkWidget *
file_selection_new(const gchar *title, file_selection_action_t action)
{
GtkWidget *win;
GtkFileChooserAction gtk_action;
#ifdef _WIN32
char *u3devicedocumentpath;
#endif
const gchar *ok_button_text;
switch (action) {
case FILE_SELECTION_OPEN:
gtk_action = GTK_FILE_CHOOSER_ACTION_OPEN;
ok_button_text = GTK_STOCK_OPEN;
break;
case FILE_SELECTION_READ_BROWSE:
gtk_action = GTK_FILE_CHOOSER_ACTION_OPEN;
ok_button_text = GTK_STOCK_OK;
break;
case FILE_SELECTION_SAVE:
gtk_action = GTK_FILE_CHOOSER_ACTION_SAVE;
ok_button_text = GTK_STOCK_SAVE;
break;
case FILE_SELECTION_WRITE_BROWSE:
gtk_action = GTK_FILE_CHOOSER_ACTION_SAVE;
ok_button_text = GTK_STOCK_OK;
break;
case FILE_SELECTION_CREATE_FOLDER:
gtk_action = GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
ok_button_text = GTK_STOCK_OK;
break;
default:
g_assert_not_reached();
gtk_action = -1;
ok_button_text = NULL;
break;
}
win = gtk_file_chooser_dialog_new(title, GTK_WINDOW(top_level), gtk_action,
#ifndef _WIN32
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
ok_button_text, GTK_RESPONSE_ACCEPT,
#else
ok_button_text, GTK_RESPONSE_ACCEPT,
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
#endif
NULL);
if (last_open_dir)
file_selection_set_current_folder(win, last_open_dir);
#ifdef _WIN32
else {
u3devicedocumentpath = getenv_utf8("U3_DEVICE_DOCUMENT_PATH");
if(u3devicedocumentpath != NULL)
file_selection_set_current_folder(win, u3devicedocumentpath);
}
#endif
return win;
}
gboolean
file_selection_set_current_folder(GtkWidget *fs, const gchar *filename)
{
gboolean ret;
size_t filename_len = strlen(filename);
gchar *new_filename;
if (filename[filename_len -1] == G_DIR_SEPARATOR
#ifdef _WIN32
&& filename_len > 3)
#else
&& filename_len > 1)
#endif
{
new_filename = g_strdup(filename);
new_filename[filename_len-1] = '\0';
} else {
new_filename = g_strdup(filename);
}
ret = gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(fs
gboolean
file_target_unwritable_ui(GtkWidget *chooser_w, char *cf_name)
{
GtkWidget *msg_dialog;
gchar *display_basename;
gint response;
ws_statb64 statbuf;
if (ws_stat64(cf_name, &statbuf) == -1) {
return TRUE;
}
#ifdef HAVE_ST_FLAGS
if (statbuf.st_flags & UF_IMMUTABLE) {
display_basename = g_filename_display_basename(cf_name);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(chooser_w),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
#ifdef __APPLE__
"The file \"%s\" is locked.",
#else
"The file \"%s\" is immutable.",
#endif
display_basename);
g_free(display_basename);
} else
#endif
if ((statbuf.st_mode & (S_IWUSR|S_IWGRP|S_IWOTH)) == 0) {
display_basename = g_filename_display_basename(cf_name);
msg_dialog = gtk_message_dialog_new(GTK_WINDOW(chooser_w),
GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_QUESTION,
GTK_BUTTONS_NONE,
"The file \"%s\" is read-only.",
display_basename);
g_free(display_basename);
} else {
msg_dialog = NULL;
}
if (msg_dialog != NULL) {
gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(msg_dialog),
"Do you want to overwrite it anyway?");
gtk_dialog_add_buttons(GTK_DIALOG(msg_dialog),
"Overwrite", GTK_RESPONSE_ACCEPT,
"Don't overwrite", GTK_RESPONSE_REJECT,
NULL);
gtk_dialog_set_default_response(GTK_DIALOG(msg_dialog), GTK_RESPONSE_REJECT);
response = gtk_dialog_run(GTK_DIALOG(msg_dialog));
gtk_widget_destroy(msg_dialog);
if (response != GTK_RESPONSE_ACCEPT) {
return FALSE;
}
#ifdef HAVE_ST_FLAGS
if (statbuf.st_flags & UF_IMMUTABLE) {
chflags(cf_name, statbuf.st_flags & ~UF_IMMUTABLE);
}
#endif
}
return TRUE;
}
void
file_selection_browse(GtkWidget *file_bt, GtkWidget *file_te, const char *label, file_selection_action_t action)
{
GtkWidget *caller = gtk_widget_get_toplevel(file_bt);
GtkWidget *fs;
gchar *f_name;
fs = g_object_get_data(G_OBJECT(caller), E_FILE_SEL_DIALOG_PTR_KEY);
if (fs != NULL) {
reactivate_window(fs);
return;
}
fs = file_selection_new(label, action);
g_object_set_data(G_OBJECT(fs), PRINT_FILE_TE_KEY, file_te);
g_object_set_data(G_OBJECT(fs), E_FS_CALLER_PTR_KEY, caller);
g_object_set_data(G_OBJECT(caller), E_FILE_SEL_DIALOG_PTR_KEY, fs);
g_signal_connect(fs, "destroy", G_CALLBACK(file_selection_browse_destroy_cb),
file_te);
if (gtk_dialog_run(GTK_DIALOG(fs)) == GTK_RESPONSE_ACCEPT)
{
f_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
gtk_entry_set_text(GTK_ENTRY(file_te), f_name);
g_free(f_name);
}
window_destroy(fs);
}
static void
file_selection_browse_destroy_cb(GtkWidget *win, GtkWidget* parent_te)
{
GtkWidget *caller;
caller = g_object_get_data(G_OBJECT(win), E_FS_CALLER_PTR_KEY);
g_object_set_data(G_OBJECT(caller), E_FILE_SEL_DIALOG_PTR_KEY, NULL);
gtk_widget_grab_focus(parent_te);
}
void
set_last_open_dir(const char *dirname)
{
size_t len;
gchar *new_last_open_dir;
if (dirname) {
len = strlen(dirname);
if (dirname[len-1] == G_DIR_SEPARATOR) {
new_last_open_dir = g_strconcat(dirname, NULL);
}
else {
new_last_open_dir = g_strconcat(dirname,
G_DIR_SEPARATOR_S, NULL);
}
if (last_open_dir == NULL ||
strcmp(last_open_dir, new_last_open_dir) != 0)
updated_last_open_dir = TRUE;
}
else {
new_last_open_dir = NULL;
if (last_open_dir != NULL)
updated_last_open_dir = TRUE;
}
g_free(last_open_dir);
last_open_dir = new_last_open_dir;
}
char *
get_last_open_dir(void)
{
return last_open_dir;
}
