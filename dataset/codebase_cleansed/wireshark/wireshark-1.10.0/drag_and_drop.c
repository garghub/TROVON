static gchar *
dnd_uri2filename(gchar *cf_name)
{
gchar *src, *dest;
gint ret;
guint i;
gchar esc[3];
#ifdef _WIN32
if (strncmp("file:////", cf_name, 9) == 0) {
cf_name += 7;
} else if (strncmp("file:///", cf_name, 8) == 0) {
cf_name += 8;
}
#else
if (strncmp("file:", cf_name, 5) == 0) {
cf_name += 5;
for(; cf_name[1] == '/'; ++cf_name);
}
#endif
src = cf_name;
dest = cf_name;
while (*src) {
if (*src == '%') {
src++;
if (*src == '%') {
*dest = *src;
src++;
dest++;
} else {
esc[0] = src[0];
esc[1] = src[1];
esc[2] = '\0';
ret = sscanf(esc, "%x", &i);
if (ret == 1) {
src+=2;
*dest = (gchar) i;
dest++;
} else {
src++;
}
}
#ifdef _WIN32
} else if (*src == '/') {
*dest = '\\';
src++;
dest++;
#endif
} else {
*dest = *src;
src++;
dest++;
}
}
*dest = '\0';
return cf_name;
}
void
dnd_open_file_cmd(gchar *cf_names_freeme)
{
int err;
gchar *cf_name;
int in_file_count;
int files_work;
char **in_filenames;
char *tmpname;
if (cf_names_freeme == NULL) return;
cf_name = cf_names_freeme;
for(in_file_count = 0; (cf_name = strstr(cf_name, "\r\n")) != NULL; ) {
cf_name += 2;
in_file_count++;
}
if (in_file_count == 0) {
g_free(cf_names_freeme);
return;
}
in_filenames = (char **)g_malloc(sizeof(char*) * in_file_count);
cf_name = cf_names_freeme;
in_filenames[0] = cf_name;
for(files_work = 1; (cf_name = strstr(cf_name, "\r\n")) != NULL && files_work < in_file_count; ) {
cf_name += 2;
in_filenames[files_work] = cf_name;
files_work++;
}
cf_name = cf_names_freeme;
g_strdelimit(cf_name, "\r\n", '\0');
for(files_work = 0; files_work < in_file_count; files_work++) {
in_filenames[files_work] = dnd_uri2filename(in_filenames[files_work]);
}
if (in_file_count == 1) {
if (cf_open(&cfile, in_filenames[0], FALSE, &err) == CF_OK) {
cf_read(&cfile, FALSE);
add_menu_recent_capture_file(in_filenames[0]);
} else {
}
} else {
tmpname = NULL;
if (cf_merge_files(&tmpname, in_file_count, in_filenames,
WTAP_FILE_PCAP, FALSE) == CF_OK) {
cf_close(&cfile);
if (cf_open(&cfile, tmpname, TRUE , &err) == CF_OK) {
g_free(tmpname);
cf_read(&cfile, FALSE);
} else {
g_free(tmpname);
}
} else {
g_free(tmpname);
}
}
g_free(in_filenames);
g_free(cf_names_freeme);
}
static void
dnd_data_received(GtkWidget *widget _U_, GdkDragContext *dc _U_, gint x _U_, gint y _U_,
GtkSelectionData *selection_data, guint info, guint t _U_, gpointer data _U_)
{
gchar *cf_names_freeme;
const guchar *sel_data_data;
gint sel_data_len;
if (info == DND_TARGET_URL) {
#ifdef HAVE_LIBPCAP
if((global_capture_session.state != CAPTURE_STOPPED)) {
simple_dialog(ESD_TYPE_CONFIRMATION,
ESD_BTN_OK,
"%sDrag and Drop currently not possible!%s\n\n"
"Dropping a file isn't possible while a capture is in progress.",
simple_dialog_primary_start(), simple_dialog_primary_end());
return;
}
#endif
if(cfile.state == FILE_READ_IN_PROGRESS) {
simple_dialog(ESD_TYPE_CONFIRMATION,
ESD_BTN_OK,
"%sDrag and Drop currently not possible!%s\n\n"
"Dropping a file isn't possible while loading another capture file.",
simple_dialog_primary_start(), simple_dialog_primary_end());
return;
}
sel_data_len = gtk_selection_data_get_length(selection_data);
sel_data_data = gtk_selection_data_get_data(selection_data);
cf_names_freeme = (gchar *)g_malloc(sel_data_len + 1);
memcpy(cf_names_freeme, sel_data_data, sel_data_len);
cf_names_freeme[sel_data_len] = '\0';
if (do_file_close(&cfile, FALSE, " before opening a new capture file"))
dnd_open_file_cmd(cf_names_freeme);
}
}
gboolean
gtk_osx_openFile (GtkosxApplication *app _U_, gchar *path, gpointer user_data _U_)
{
GtkSelectionData selection_data;
gchar* selection_path;
size_t length = strlen(path);
selection_path = (gchar *)g_malloc(length + 3);
memcpy(selection_path, path, length);
selection_path[length] = '\r';
selection_path[length + 1] = '\n';
selection_path[length + 2] = '\0';
memset(&selection_data, 0, sizeof(selection_data));
gtk_selection_data_set(&selection_data, gdk_atom_intern_static_string ("text/uri-list"), 8, (guchar*) selection_path, (gint)(length + 2));
dnd_data_received(NULL, NULL, 0, 0, &selection_data, DND_TARGET_URL, 0, 0);
return TRUE;
}
void
dnd_init(GtkWidget *w)
{
static GtkTargetEntry target_entry[] = {
{(gchar *)"text/uri-list", 0, DND_TARGET_URL}
};
gtk_drag_dest_set(
w, GTK_DEST_DEFAULT_ALL, target_entry,
sizeof(target_entry) / sizeof(GtkTargetEntry),
(GdkDragAction)(GDK_ACTION_MOVE | GDK_ACTION_COPY) );
g_signal_connect(w, "drag_data_received", G_CALLBACK(dnd_data_received), NULL);
#ifdef HAVE_GTKOSXAPPLICATION
g_signal_connect(g_object_new(GTKOSX_TYPE_APPLICATION, NULL), "NSApplicationOpenFile", G_CALLBACK(gtk_osx_openFile), NULL);
#endif
}
