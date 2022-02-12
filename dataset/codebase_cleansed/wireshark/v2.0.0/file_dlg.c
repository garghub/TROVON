GtkWidget *
file_selection_new(const gchar *title, GtkWindow *parent,
file_selection_action_t action)
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
ok_button_text = WIRESHARK_STOCK_SAVE;
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
gtk_action = (GtkFileChooserAction)-1;
ok_button_text = NULL;
break;
}
win = gtk_file_chooser_dialog_new(title, parent, gtk_action,
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
ok_button_text, GTK_RESPONSE_ACCEPT,
NULL);
gtk_dialog_set_alternative_button_order(GTK_DIALOG(win),
GTK_RESPONSE_ACCEPT,
GTK_RESPONSE_CANCEL,
-1);
if (action == FILE_SELECTION_SAVE)
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(win), TRUE);
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
static gchar *filesel_get_link(const gchar *link_file)
{
WIN32_FIND_DATAW wfd;
IShellLinkW *psl;
IPersistFile *ppf;
wchar_t *wlink_file;
wchar_t wtarget[MAX_PATH];
gchar *target = NULL;
wtarget[0] = 0L;
CoInitialize(NULL);
if (S_OK == CoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
&IID_IShellLinkW, (void **)&psl)) {
if (S_OK == IShellLinkW_QueryInterface(psl, &IID_IPersistFile,
(void **)&ppf)) {
wlink_file = g_utf8_to_utf16(link_file, -1, NULL, NULL, NULL);
if (S_OK == IPersistFile_Load(ppf, wlink_file, STGM_READ)) {
if (S_OK == IShellLinkW_GetPath(psl, wtarget, MAX_PATH, &wfd,
SLGP_UNCPRIORITY)) {
target = g_utf16_to_utf8(wtarget, -1, NULL, NULL, NULL);
}
}
IPersistFile_Release(ppf);
g_free(wlink_file);
}
IShellLinkW_Release(psl);
}
CoUninitialize();
return target;
}
gchar *
file_selection_run(GtkWidget *fs)
{
gchar *cf_name;
#ifdef _WIN32
gchar *target;
const gchar *ext;
#endif
for (;;) {
if (gtk_dialog_run(GTK_DIALOG(fs)) != GTK_RESPONSE_ACCEPT) {
window_destroy(fs);
return NULL;
}
cf_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
if (test_for_directory(cf_name) == EISDIR) {
set_last_open_dir(cf_name);
g_free(cf_name);
file_selection_set_current_folder(fs, get_last_open_dir());
continue;
}
#ifdef _WIN32
if ((ext = strrchr(cf_name, '.')) && g_ascii_strcasecmp(ext, ".lnk") == 0) {
target = filesel_get_link(cf_name);
if (target != NULL) {
g_free(cf_name);
if (test_for_directory(target)) {
set_last_open_dir(target);
g_free(target);
file_selection_set_current_folder(fs, get_last_open_dir());
continue;
}
cf_name = target;
}
}
#endif
break;
}
return cf_name;
}
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
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
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
(GtkDialogFlags)(GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT),
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
fs = file_selection_new(label, GTK_WINDOW(caller), action);
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
caller = (GtkWidget *)g_object_get_data(G_OBJECT(win), E_FS_CALLER_PTR_KEY);
g_object_set_data(G_OBJECT(caller), E_FILE_SEL_DIALOG_PTR_KEY, NULL);
gtk_widget_grab_focus(parent_te);
}
void
set_last_open_dir(const char *dirname)
{
size_t len;
gchar *new_last_open_dir;
if (dirname && dirname[0]) {
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
