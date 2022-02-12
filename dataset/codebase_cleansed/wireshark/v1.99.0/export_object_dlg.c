static void
eo_remember_this_row(GtkTreeModel *model _U_, GtkTreePath *path,
GtkTreeIter *iter _U_, gpointer arg)
{
export_object_list_t *object_list = (export_object_list_t *)arg;
export_object_entry_t *entry;
gint *path_index;
if((path_index = gtk_tree_path_get_indices(path)) == NULL)
return;
object_list->row_selected = path_index[0];
entry = (export_object_entry_t *)g_slist_nth_data(object_list->entries,
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
export_object_list_t *object_list = (export_object_list_t *)data;
export_object_entry_t *entry;
GSList *slist = object_list->entries;
remove_tap_listener(object_list);
while(slist) {
entry = (export_object_entry_t *)slist->data;
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
static gchar *eo_saveable_pathname(gchar *filename) {
gchar **splitted_pathname;
gchar *auxstring, *saveable_pathname;
guint nparts,i;
saveable_pathname = NULL;
splitted_pathname = g_strsplit_set(filename,"\\",-1);
nparts = g_strv_length(splitted_pathname);
if (nparts>0) {
saveable_pathname=g_strdup(splitted_pathname[0]);
}
for (i=1;i<nparts;i++) {
auxstring = g_strconcat(saveable_pathname,"__",splitted_pathname[i],NULL);
g_free(saveable_pathname);
saveable_pathname = auxstring;
}
return saveable_pathname;
}
static char *
gtk_eo_save_object_as_file(export_object_list_t *object_list, char *auxfilename)
{
GtkWidget *save_as_w;
char *pathname;
save_as_w = file_selection_new("Wireshark: Save Object As ...",
GTK_WINDOW(object_list->dlg),
FILE_SELECTION_SAVE);
gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(save_as_w),
auxfilename);
pathname = file_selection_run(save_as_w);
if (pathname == NULL) {
return NULL;
}
window_destroy(save_as_w);
return pathname;
}
static void
eo_save_clicked_cb(GtkWidget *widget _U_, gpointer arg)
{
export_object_list_t *object_list = (export_object_list_t *)arg;
export_object_entry_t *entry;
gchar *auxfilename = NULL;
char *pathname;
entry =(export_object_entry_t *) g_slist_nth_data(object_list->entries,
object_list->row_selected);
if(!entry) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK, "No object was selected for saving. Please click on an object and click save again.");
return;
}
auxfilename = eo_saveable_pathname(entry->filename);
for (;;) {
pathname = gtk_eo_save_object_as_file(object_list, auxfilename);
if (pathname == NULL) {
break;
}
if (eo_save_entry(pathname, entry, TRUE)) {
g_free(pathname);
break;
}
g_free(pathname);
}
g_free(auxfilename);
}
static void
eo_save_all_clicked_cb(GtkWidget *widget _U_, gpointer arg)
{
gchar *save_as_fullpath = NULL;
export_object_list_t *object_list = (export_object_list_t *)arg;
export_object_entry_t *entry;
GtkWidget *save_in_w;
GSList *slist = object_list->entries;
gboolean all_saved = TRUE;
gchar *save_in_path;
GString *safe_filename;
gchar *auxfilename = NULL;
int count = 0;
save_in_w = file_selection_new("Wireshark: Save All Objects In ...",
GTK_WINDOW(object_list->dlg),
FILE_SELECTION_CREATE_FOLDER);
if (gtk_dialog_run(GTK_DIALOG(save_in_w)) == GTK_RESPONSE_ACCEPT) {
while (slist) {
entry = (export_object_entry_t *)slist->data;
save_in_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(save_in_w));
if ((strlen(save_in_path) < MAXFILELEN)) {
do {
g_free(save_as_fullpath);
if (entry->filename) {
auxfilename = eo_saveable_pathname(entry->filename);
safe_filename = eo_massage_str(auxfilename,
MAXFILELEN - strlen(save_in_path), count);
g_free(auxfilename);
} else {
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
g_free(save_as_fullpath);
save_as_fullpath = NULL;
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
export_object_list_t *object_list = (export_object_list_t *)tapdata;
object_list->entries = NULL;
object_list->iter = NULL;
object_list->row_selected = -1;
if (eo_protocoldata_reset != NULL) eo_protocoldata_reset();
}
static void
eo_draw(void *tapdata)
{
export_object_list_t *object_list = (export_object_list_t *)tapdata;
export_object_entry_t *eo_entry;
gchar *size_str;
GSList *slist = object_list->entries;
GtkTreeIter new_iter;
gtk_tree_store_clear(object_list->store);
while(slist) {
eo_entry = (export_object_entry_t *)slist->data;
gtk_tree_store_append(object_list->store, &new_iter,
object_list->iter);
size_str = format_size(eo_entry->payload_len, (format_size_flags_e)(format_size_unit_bytes|format_size_prefix_si));
gtk_tree_store_set(object_list->store, &new_iter,
EO_PKT_NUM_COLUMN, eo_entry->pkt_num,
EO_HOSTNAME_COLUMN, eo_entry->hostname,
EO_CONTENT_TYPE_COLUMN, eo_entry->content_type,
EO_BYTES_COLUMN, size_str,
EO_FILENAME_COLUMN, eo_entry->filename,
-1);
g_free(size_str);
slist = slist->next;
}
}
void object_list_add_entry(export_object_list_t *object_list, export_object_entry_t *entry)
{
object_list->entries = g_slist_append(object_list->entries, entry);
}
export_object_entry_t *object_list_get_entry(export_object_list_t *object_list, int row) {
return (export_object_entry_t *)g_slist_nth_data(object_list->entries, row);
}
static void
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
object_list = g_new0(export_object_list_t,1);
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
gtk_box_pack_start(GTK_BOX (vbox), sw, TRUE, TRUE, 0);
object_list->store = gtk_tree_store_new(EO_NUM_COLUMNS,
G_TYPE_INT, G_TYPE_STRING,
G_TYPE_STRING, G_TYPE_STRING,
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
column = gtk_tree_view_column_new_with_attributes("Size",
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
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_EXPORT_OBJECT_LIST);
gtk_widget_set_tooltip_text(help_bt, "Show help for this dialog.");
save_all_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_SAVE_ALL);
g_signal_connect(save_all_bt, "clicked", G_CALLBACK(eo_save_all_clicked_cb),
object_list);
gtk_widget_set_tooltip_text(save_all_bt, "Save all listed objects with their displayed filenames.");
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE_AS);
g_signal_connect(save_bt, "clicked", G_CALLBACK(eo_save_clicked_cb), object_list);
gtk_widget_set_tooltip_text(save_bt, "Saves the currently selected content to a file.");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
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
void
eo_dicom_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("dicom_eo", "DICOM", eo_dicom_packet, NULL);
}
void
eo_http_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("http_eo", "HTTP", eo_http_packet, NULL);
}
void
eo_smb_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("smb_eo", "SMB", eo_smb_packet, eo_smb_cleanup);
}
void
eo_tftp_cb(GtkWidget *widget _U_, gpointer data _U_)
{
export_object_window("tftp_eo", "TFTP", eo_tftp_packet, eo_tftp_cleanup);
}
