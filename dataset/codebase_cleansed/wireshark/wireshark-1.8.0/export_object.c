static void
eo_remember_this_row(GtkTreeModel *model _U_, GtkTreePath *path,
GtkTreeIter *iter _U_, gpointer arg)
{
export_object_list_t *object_list = arg;
export_object_entry_t *entry;
gint *path_index;
if((path_index = gtk_tree_path_get_indices(path)) == NULL)
return;
object_list->row_selected = path_index[0];
entry = g_slist_nth_data(object_list->entries,
object_list->row_selected);
cf_goto_frame(&cfile, entry->pkt_num);
}
static void
eo_remember_row_num(GtkTreeSelection *sel, gpointer data)
{
gtk_tree_selection_selected_foreach(sel, eo_remember_this_row, data);
}
static void
eo_win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
export_object_list_t *object_list = data;
export_object_entry_t *entry;
GSList *slist = object_list->entries;
protect_thread_critical_region();
remove_tap_listener(object_list);
unprotect_thread_critical_region();
while(slist) {
entry = slist->data;
g_free(entry->hostname);
g_free(entry->content_type);
g_free(entry->filename);
g_free(entry->payload_data);
slist = slist->next;
g_free(entry);
}
g_slist_free(object_list->entries);
g_free(object_list);
if (eo_protocoldata_reset != NULL) eo_protocoldata_reset();
}
static gboolean
eo_save_entry(gchar *save_as_filename, export_object_entry_t *entry, gboolean show_err)
{
int to_fd;
gint64 bytes_left;
int bytes_to_write;
ssize_t bytes_written;
guint8 *ptr;
int err;
to_fd = ws_open(save_as_filename, O_WRONLY | O_CREAT | O_EXCL |
O_BINARY, 0644);
if(to_fd == -1) {
if (show_err)
open_failure_alert_box(save_as_filename, errno, TRUE);
g_free(save_as_filename);
return FALSE;
}
ptr = entry->payload_data;
bytes_left = entry->payload_len;
while (bytes_left != 0) {
if (bytes_left > 0x40000000)
bytes_to_write = 0x40000000;
else
bytes_to_write = (int)bytes_left;
bytes_written = ws_write(to_fd, ptr, bytes_to_write);
if(bytes_written <= 0) {
if (bytes_written < 0)
err = errno;
else
err = WTAP_ERR_SHORT_WRITE;
if (show_err)
write_failure_alert_box(save_as_filename, err);
ws_close(to_fd);
g_free(save_as_filename);
return FALSE;
}
bytes_left -= bytes_written;
ptr += bytes_written;
}
if (ws_close(to_fd) < 0) {
if (show_err)
write_failure_alert_box(save_as_filename, errno);
g_free(save_as_filename);
return FALSE;
}
g_free(save_as_filename);
return TRUE;
}
static void
eo_save_clicked_cb(GtkWidget *widget _U_, gpointer arg)
{
GtkWidget *save_as_w;
export_object_list_t *object_list = arg;
export_object_entry_t *entry = NULL;
entry = g_slist_nth_data(object_list->entries,
object_list->row_selected);
if(!entry) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK, "No object was selected for saving. Please click on an object and click save again.");
return;
}
save_as_w = file_selection_new("Wireshark: Save Object As ...",
FILE_SELECTION_SAVE);
gtk_window_set_transient_for(GTK_WINDOW(save_as_w),
GTK_WINDOW(object_list->dlg));
gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(save_as_w),
entry->filename);
if(gtk_dialog_run(GTK_DIALOG(save_as_w)) == GTK_RESPONSE_ACCEPT)
eo_save_entry(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(save_as_w)), entry, TRUE);
window_destroy(save_as_w);
}
static GString *eo_rename(GString *gstr, int dup)
{
GString *gstr_tmp;
gchar *tmp_ptr;
GString *ext_str;
gstr_tmp = g_string_new("(");
g_string_append_printf (gstr_tmp, "%d)", dup);
if ( (tmp_ptr = strrchr(gstr->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
gstr = g_string_truncate(gstr, gstr->len - ext_str->len);
if ( gstr->len >= (MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len)) )
gstr = g_string_truncate(gstr, MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len));
gstr = g_string_append(gstr, gstr_tmp->str);
gstr = g_string_append(gstr, ext_str->str);
g_string_free(ext_str, TRUE);
}
else {
if ( gstr->len >= (MAXFILELEN - strlen(gstr_tmp->str)) )
gstr = g_string_truncate(gstr, MAXFILELEN - strlen(gstr_tmp->str));
gstr = g_string_append(gstr, gstr_tmp->str);
}
g_string_free(gstr_tmp, TRUE);
return gstr;
}
static GString *
eo_massage_str(const gchar *in_str, gsize maxlen, int dup)
{
gchar *tmp_ptr;
const gchar *reject = "<>:\"/\\|?*"
"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a"
"\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14"
"\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
GString *out_str;
GString *ext_str;
out_str = g_string_new("");
while ( (tmp_ptr = strpbrk(in_str, reject)) != NULL ) {
out_str = g_string_append_len(out_str, in_str, tmp_ptr - in_str);
out_str = g_string_append_c(out_str, '%');
out_str = g_string_append_c(out_str, HEXTOASCII(HINIBBLE(*tmp_ptr)));
out_str = g_string_append_c(out_str, HEXTOASCII(LONIBBLE(*tmp_ptr)));
in_str = tmp_ptr + 1;
}
out_str = g_string_append(out_str, in_str);
if ( out_str->len > maxlen ) {
if ( (tmp_ptr = strrchr(out_str->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
out_str = g_string_truncate(out_str, maxlen - ext_str->len);
out_str = g_string_append(out_str, ext_str->str);
g_string_free(ext_str, TRUE);
}
else
out_str = g_string_truncate(out_str, maxlen);
}
if ( dup != 0 )
out_str = eo_rename(out_str, dup);
return out_str;
}
static const char *
ct2ext(const char *content_type)
{
return content_type;
}
static void
eo_save_all_clicked_cb(GtkWidget *widget _U_, gpointer arg)
{
gchar *save_as_fullpath;
export_object_list_t *object_list = arg;
export_object_entry_t *entry;
GtkWidget *save_in_w;
GSList *slist = object_list->entries;
gboolean all_saved = TRUE;
gchar *save_in_path;
GString *safe_filename;
int count = 0;
save_in_w = file_selection_new("Wireshark: Save All Objects In ...",
FILE_SELECTION_CREATE_FOLDER);
gtk_window_set_transient_for(GTK_WINDOW(save_in_w),
GTK_WINDOW(object_list->dlg));
if (gtk_dialog_run(GTK_DIALOG(save_in_w)) == GTK_RESPONSE_ACCEPT) {
while (slist) {
entry = slist->data;
save_in_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(save_in_w));
if ((strlen(save_in_path) < MAXFILELEN)) {
do {
if (entry->filename)
safe_filename = eo_massage_str(entry->filename,
MAXFILELEN - strlen(save_in_path), count);
else {
char generic_name[256];
const char *ext;
ext = ct2ext(entry->content_type);
g_snprintf(generic_name, sizeof(generic_name),
"object%u%s%s", entry->pkt_num, ext ? "." : "",
ext ? ext : "");
safe_filename = eo_massage_str(generic_name,
MAXFILELEN - strlen(save_in_path), count);
}
save_as_fullpath = g_build_filename(
save_in_path, safe_filename->str, NULL);
g_string_free(safe_filename, TRUE);
} while (g_file_test(save_as_fullpath, G_FILE_TEST_EXISTS) && ++count < 1000);
count = 0;
if (!eo_save_entry(save_as_fullpath, entry, FALSE))
all_saved = FALSE;
}
else
all_saved = FALSE;
slist = slist->next;
}
}
if (!all_saved)
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Some files could not be saved.");
window_destroy(save_in_w);
}
static void
eo_reset(void *tapdata)
{
export_object_list_t *object_list = tapdata;
object_list->entries = NULL;
object_list->iter = NULL;
object_list->row_selected = -1;
if (eo_protocoldata_reset != NULL) eo_protocoldata_reset();
}
static void
eo_draw(void *tapdata)
{
export_object_list_t *object_list = tapdata;
export_object_entry_t *eo_entry;
GSList *slist = object_list->entries;
GtkTreeIter new_iter;
gtk_tree_store_clear(object_list->store);
while(slist) {
eo_entry = slist->data;
gtk_tree_store_append(object_list->store, &new_iter,
object_list->iter);
gtk_tree_store_set(object_list->store, &new_iter,
EO_PKT_NUM_COLUMN, eo_entry->pkt_num,
EO_HOSTNAME_COLUMN, eo_entry->hostname,
EO_CONTENT_TYPE_COLUMN, eo_entry->content_type,
EO_BYTES_COLUMN, eo_entry->payload_len,
EO_FILENAME_COLUMN, eo_entry->filename,
-1);
slist = slist->next;
}
}
void
export_object_window(const gchar *tapname, const gchar *name, tap_packet_cb tap_packet, eo_protocoldata_reset_cb eo_protocoldata_resetfn)
{
GtkWidget *sw;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *selection;
GtkWidget *vbox, *bbox, *help_bt, *cancel_bt, *save_bt, *save_all_bt;
GString *error_msg;
export_object_list_t *object_list;
gchar *window_title;
eo_protocoldata_reset = eo_protocoldata_resetfn;
object_list = g_malloc0(sizeof(export_object_list_t));
error_msg = register_tap_listener(tapname, object_list, NULL, 0,
eo_reset,
tap_packet,
eo_draw);
if (error_msg) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't register %s tap: %s\n", name, error_msg->str);
g_string_free(error_msg, TRUE);
g_free(object_list);
return;
}
window_title = g_strdup_printf("Wireshark: %s object list", name);
object_list->dlg = dlg_window_new(window_title);
g_free(window_title);
gtk_window_set_default_size(GTK_WINDOW(object_list->dlg),
DEF_WIDTH, DEF_HEIGHT);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 5);
gtk_container_add(GTK_CONTAINER(object_list->dlg), vbox);
sw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(sw),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(vbox), sw);
object_list->store = gtk_tree_store_new(EO_NUM_COLUMNS,
G_TYPE_INT, G_TYPE_STRING,
G_TYPE_STRING, G_TYPE_INT64,
G_TYPE_STRING);
object_list->tree = tree_view_new(GTK_TREE_MODEL(object_list->store));
g_object_unref(G_OBJECT(object_list->store));
object_list->tree_view = GTK_TREE_VIEW(object_list->tree);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Packet num",
renderer,
"text",
EO_PKT_NUM_COLUMN,
NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(object_list->tree_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Hostname",
renderer,
"text",
EO_HOSTNAME_COLUMN,
NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(object_list->tree_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Content Type",
renderer,
"text",
EO_CONTENT_TYPE_COLUMN,
NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(object_list->tree_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Bytes",
renderer,
"text",
EO_BYTES_COLUMN,
NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(object_list->tree_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Filename",
renderer,
"text",
EO_FILENAME_COLUMN,
NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column(object_list->tree_view, column);
gtk_container_add(GTK_CONTAINER(sw), object_list->tree);
selection = gtk_tree_view_get_selection(object_list->tree_view);
g_signal_connect(selection, "changed", G_CALLBACK(eo_remember_row_num), object_list);
bbox = dlg_button_row_new(GTK_STOCK_HELP, WIRESHARK_STOCK_SAVE_ALL, GTK_STOCK_SAVE_AS, GTK_STOCK_CANCEL, NULL);
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_EXPORT_OBJECT_LIST);
gtk_widget_set_tooltip_text(help_bt, "Show help for this dialog.");
save_all_bt = g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_SAVE_ALL);
g_signal_connect(save_all_bt, "clicked", G_CALLBACK(eo_save_all_clicked_cb),
object_list);
gtk_widget_set_tooltip_text(save_all_bt, "Save all listed objects with their displayed filenames.");
save_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE_AS);
g_signal_connect(save_bt, "clicked", G_CALLBACK(eo_save_clicked_cb), object_list);
gtk_widget_set_tooltip_text(save_bt, "Saves the currently selected content to a file.");
cancel_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel this dialog.");
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
g_signal_connect(object_list->dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(object_list->dlg, "destroy",
G_CALLBACK(eo_win_destroy_cb), object_list);
window_set_cancel_button(object_list->dlg, cancel_bt,
window_cancel_button_cb);
gtk_widget_show_all(object_list->dlg);
window_present(object_list->dlg);
cf_retap_packets(&cfile);
}
