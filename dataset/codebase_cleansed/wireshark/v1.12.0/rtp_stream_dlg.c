static void save_stream_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
rtpstream_save_dlg = NULL;
}
static gboolean save_stream_ok_cb(GtkWidget *ok_bt _U_, gpointer fs)
{
gchar *g_dest;
if (!selected_stream_fwd) {
return TRUE;
}
g_dest = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
if (test_for_directory(g_dest) == EISDIR) {
set_last_open_dir(g_dest);
g_free(g_dest);
file_selection_set_current_folder((GtkWidget *)fs, get_last_open_dir());
gtk_file_chooser_set_current_name((GtkFileChooser *)fs, "");
return FALSE;
}
#if 0
if (!rtpstream_save(selected_stream_fwd, g_dest)) {
g_free(g_dest);
return;
}
g_free(g_dest);
window_destroy(GTK_WIDGET(rtpstream_save_dlg));
return;
#else
rtpstream_save(selected_stream_fwd, g_dest);
g_free(g_dest);
return TRUE;
#endif
}
static void
rtpstream_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
remove_tap_listener_rtp_stream();
if (rtpstream_save_dlg != NULL)
window_destroy(rtpstream_save_dlg);
rtpstream_reset((rtpstream_tapinfo_t *)rtpstream_get_info());
rtp_stream_dlg = NULL;
}
static void
rtpstream_on_unselect(GtkButton *button _U_, gpointer user_data _U_)
{
GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_unselect_all(selection);
selected_stream_fwd = NULL;
selected_stream_rev = NULL;
gtk_label_set_text(GTK_LABEL(label_fwd), FWD_LABEL_TEXT);
gtk_label_set_text(GTK_LABEL(label_rev), REV_LABEL_TEXT);
}
static gint rtp_stream_info_cmp_reverse(gconstpointer aa, gconstpointer bb)
{
const struct _rtp_stream_info* a = (const struct _rtp_stream_info *)aa;
const struct _rtp_stream_info* b = (const struct _rtp_stream_info *)bb;
if (a==NULL || b==NULL)
return 1;
if ((ADDRESSES_EQUAL(&(a->src_addr), &(b->dest_addr)))
&& (a->src_port == b->dest_port)
&& (ADDRESSES_EQUAL(&(a->dest_addr), &(b->src_addr)))
&& (a->dest_port == b->src_port))
return 0;
else
return 1;
}
static void
rtpstream_on_findrev(GtkButton *button _U_, gpointer user_data _U_)
{
GtkTreeSelection *selection;
GList *path_list;
GList *path_list_item = NULL;
GtkTreePath *path = NULL;
GtkTreePath *path_fwd = NULL;
GtkTreePath *path_rev = NULL;
GtkTreeIter iter;
rtp_stream_info_t *stream = NULL;
gboolean found_it = FALSE;
if (selected_stream_fwd==NULL)
return;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
path_list = gtk_tree_selection_get_selected_rows(selection, NULL);
if (path_list) {
path_list_item = g_list_first(path_list);
path = (GtkTreePath *)(path_list_item->data);
}
if (path && gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path)) {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, RTP_COL_DATA, &stream, -1);
if (stream == selected_stream_fwd) {
path_fwd = path;
}
if (stream == selected_stream_rev) {
path_rev = path;
}
}
path = NULL;
if (path_list_item) {
path_list_item = g_list_next(path_list_item);
if (path_list_item)
path = (GtkTreePath *)(path_list_item->data);
}
if (path && gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path)) {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, RTP_COL_DATA, &stream, -1);
if (stream == selected_stream_fwd) {
path_fwd = path;
}
if (stream == selected_stream_rev) {
path_rev = path;
}
}
gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path_fwd);
while (gtk_tree_model_iter_next(GTK_TREE_MODEL(list_store), &iter)) {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, RTP_COL_DATA, &stream, -1);
if (rtp_stream_info_cmp_reverse(selected_stream_fwd, stream) == 0) {
found_it = TRUE;
break;
}
};
if (!found_it) {
gtk_tree_model_get_iter_first(GTK_TREE_MODEL(list_store), &iter);
do {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, RTP_COL_DATA, &stream, -1);
if (rtp_stream_info_cmp_reverse(selected_stream_fwd, stream) == 0) {
found_it = TRUE;
break;
}
if (stream == selected_stream_fwd)
break;
} while (gtk_tree_model_iter_next(GTK_TREE_MODEL(list_store), &iter));
}
if (found_it) {
if (path_rev)
gtk_tree_selection_unselect_path(selection, path_rev);
gtk_tree_selection_select_iter(selection, &iter);
}
g_list_foreach(path_list, (GFunc)gtk_tree_path_free, NULL);
g_list_free(path_list);
}
static void
rtpstream_on_save(GtkButton *button _U_, gpointer data _U_)
{
if (!selected_stream_fwd) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Please select a forward stream");
return;
}
#if 0
if (rtpstream_save_dlg != NULL) {
reactivate_window(rtpstream_save_dlg);
return;
}
#endif
rtpstream_save_dlg = gtk_file_chooser_dialog_new(
"Wireshark: Save selected stream in rtpdump ('-F dump') format",
GTK_WINDOW(rtp_stream_dlg), GTK_FILE_CHOOSER_ACTION_SAVE,
GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
NULL);
gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(rtpstream_save_dlg), TRUE);
g_signal_connect(rtpstream_save_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rtpstream_save_dlg, "destroy", G_CALLBACK(save_stream_destroy_cb), NULL);
gtk_widget_show(rtpstream_save_dlg);
window_present(rtpstream_save_dlg);
#if 0
if (gtk_dialog_run(GTK_DIALOG(rtpstream_save_dlg)) == GTK_RESPONSE_ACCEPT){
save_stream_ok_cb(rtpstream_save_dlg, rtpstream_save_dlg);
}else{
window_destroy(rtpstream_save_dlg);
}
#endif
while (gtk_dialog_run(GTK_DIALOG(rtpstream_save_dlg)) == GTK_RESPONSE_ACCEPT) {
if (save_stream_ok_cb(NULL, rtpstream_save_dlg)) {
break;
}
}
window_destroy(rtpstream_save_dlg);
}
static void
rtpstream_on_mark(GtkButton *button _U_, gpointer user_data _U_)
{
if (selected_stream_fwd==NULL && selected_stream_rev==NULL)
return;
rtpstream_mark(selected_stream_fwd, selected_stream_rev);
}
static void
rtpstream_on_filter(GtkButton *button _U_, gpointer user_data _U_)
{
gchar *filter_string = NULL;
gchar *filter_string_fwd = NULL;
gchar *filter_string_rev = NULL;
gchar ip_version[3];
if (selected_stream_fwd==NULL && selected_stream_rev==NULL)
return;
if (selected_stream_fwd)
{
if (selected_stream_fwd->src_addr.type==AT_IPv6) {
g_strlcpy(ip_version,"v6",sizeof(ip_version));
} else {
ip_version[0] = '\0';
}
filter_string_fwd = g_strdup_printf(
"(ip%s.src==%s && udp.srcport==%u && ip%s.dst==%s && udp.dstport==%u && rtp.ssrc==0x%X)",
ip_version,
ep_address_to_str(&(selected_stream_fwd->src_addr)),
selected_stream_fwd->src_port,
ip_version,
ep_address_to_str(&(selected_stream_fwd->dest_addr)),
selected_stream_fwd->dest_port,
selected_stream_fwd->ssrc);
filter_string = filter_string_fwd;
}
if (selected_stream_rev)
{
if (selected_stream_rev->src_addr.type==AT_IPv6) {
g_strlcpy(ip_version,"v6",sizeof(ip_version));
} else {
ip_version[0] = '\0';
}
filter_string_rev = g_strdup_printf(
"(ip%s.src==%s && udp.srcport==%u && ip%s.dst==%s && udp.dstport==%u && rtp.ssrc==0x%X)",
ip_version,
ep_address_to_str(&(selected_stream_rev->src_addr)),
selected_stream_rev->src_port,
ip_version,
ep_address_to_str(&(selected_stream_rev->dest_addr)),
selected_stream_rev->dest_port,
selected_stream_rev->ssrc);
filter_string = filter_string_rev;
}
if ((selected_stream_fwd) && (selected_stream_rev))
{
filter_string = g_strdup_printf("%s || %s", filter_string_fwd, filter_string_rev);
g_free(filter_string_fwd);
g_free(filter_string_rev);
}
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), filter_string);
g_free(filter_string);
}
static void
rtpstream_on_copy_as_csv(GtkWindow *win _U_, gpointer data _U_)
{
GtkTreeViewColumn *column;
const gchar *title;
GtkTreeIter iter;
guint i,j;
gchar *table_entry;
guint table_entry_uint;
GString *CSV_str;
GtkClipboard *cb;
CSV_str = g_string_sized_new(240*(1+streams_nb));
for (j=0; j<NUM_COLS-1; j++) {
column = gtk_tree_view_get_column(GTK_TREE_VIEW(list), j);
title = gtk_tree_view_column_get_title(column);
g_string_append_printf(CSV_str, "\"%s\"", title);
if (j<NUM_COLS-2) g_string_append(CSV_str, ",");
}
g_string_append(CSV_str,"\n");
if (gtk_tree_model_get_iter_first(GTK_TREE_MODEL(list_store), &iter)) {
for (i=0; i<streams_nb; i++) {
for (j=0; j<NUM_COLS-1; j++) {
if (j == RTP_COL_SRC_PORT || j == RTP_COL_DST_PORT || j == RTP_COL_PACKETS) {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, j, &table_entry_uint, -1);
g_string_append_printf(CSV_str, "\"%u\"", table_entry_uint);
} else {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, j, &table_entry, -1);
g_string_append_printf(CSV_str, "\"%s\"", table_entry);
g_free(table_entry);
}
if (j<NUM_COLS-2) g_string_append(CSV_str,",");
}
g_string_append(CSV_str,"\n");
gtk_tree_model_iter_next (GTK_TREE_MODEL(list_store),&iter);
}
}
cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
gtk_clipboard_set_text(cb, CSV_str->str, (gint)CSV_str->len);
g_string_free(CSV_str, TRUE);
}
static void
rtpstream_on_analyse(GtkButton *button _U_, gpointer user_data _U_)
{
address src_fwd;
guint32 port_src_fwd = 0;
address dst_fwd;
guint32 port_dst_fwd = 0;
guint32 ssrc_fwd = 0;
address src_rev;
guint32 port_src_rev = 0;
address dst_rev;
guint32 port_dst_rev = 0;
guint32 ssrc_rev = 0;
if (!(selected_stream_fwd || selected_stream_rev))
{
return;
}
SET_ADDRESS(&src_fwd,AT_NONE,0,NULL);
SET_ADDRESS(&dst_fwd,AT_NONE,0,NULL);
SET_ADDRESS(&src_rev,AT_NONE,0,NULL);
SET_ADDRESS(&dst_rev,AT_NONE,0,NULL);
if (selected_stream_fwd) {
COPY_ADDRESS(&(src_fwd), &(selected_stream_fwd->src_addr));
port_src_fwd = selected_stream_fwd->src_port;
COPY_ADDRESS(&(dst_fwd), &(selected_stream_fwd->dest_addr));
port_dst_fwd = selected_stream_fwd->dest_port;
ssrc_fwd = selected_stream_fwd->ssrc;
}
if (selected_stream_rev) {
COPY_ADDRESS(&(src_rev), &(selected_stream_rev->src_addr));
port_src_rev = selected_stream_rev->src_port;
COPY_ADDRESS(&(dst_rev), &(selected_stream_rev->dest_addr));
port_dst_rev = selected_stream_rev->dest_port;
ssrc_rev = selected_stream_rev->ssrc;
}
rtp_analysis(
&src_fwd,
port_src_fwd,
&dst_fwd,
port_dst_fwd,
ssrc_fwd,
&src_rev,
port_src_rev,
&dst_rev,
port_dst_rev,
ssrc_rev
);
}
static gboolean
rtpstream_view_selection_func(GtkTreeSelection *selection, GtkTreeModel *model, GtkTreePath *path, gboolean path_currently_selected, gpointer userdata _U_)
{
GtkTreeIter iter;
gint nb_selected;
rtp_stream_info_t* selected_stream;
gboolean result = TRUE;
gchar label_text[80];
nb_selected = gtk_tree_selection_count_selected_rows(selection);
if (gtk_tree_model_get_iter(model, &iter, path)) {
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &iter, RTP_COL_DATA, &selected_stream, -1);
switch (nb_selected)
{
case 0:
{
if (path_currently_selected)
g_print("Select: He, we've got a selected path while none is selected?\n");
else
selected_stream_fwd = selected_stream;
break;
}
case 1:
{
if (path_currently_selected)
if (selected_stream == selected_stream_fwd)
selected_stream_fwd = NULL;
else
selected_stream_rev = NULL;
else
if (selected_stream == selected_stream_fwd)
g_print("Select: He, this can't be. 1 not selected but equal to fwd\n");
else
if (selected_stream_rev)
selected_stream_fwd = selected_stream;
else
selected_stream_rev = selected_stream;
break;
}
case 2:
{
if (path_currently_selected) {
if (selected_stream == selected_stream_fwd)
selected_stream_fwd = NULL;
else if (selected_stream == selected_stream_rev)
selected_stream_rev = NULL;
else
g_print("Select: He, this can't be. 2 selected but not equal to fwd or rev\n");
}
result = path_currently_selected;
break;
}
default:
{
g_print("Select: He, we're getting a too high selection count\n");
result = path_currently_selected;
}
}
}
if (selected_stream_fwd) {
g_snprintf(label_text, sizeof(label_text), "Forward: %s:%u -> %s:%u, SSRC=0x%X",
ep_address_to_display(&(selected_stream_fwd->src_addr)),
selected_stream_fwd->src_port,
ep_address_to_display(&(selected_stream_fwd->dest_addr)),
selected_stream_fwd->dest_port,
selected_stream_fwd->ssrc
);
gtk_label_set_text(GTK_LABEL(label_fwd), label_text);
} else {
if (selected_stream_rev)
gtk_label_set_text(GTK_LABEL(label_fwd), FWD_ONLY_LABEL_TEXT);
else
gtk_label_set_text(GTK_LABEL(label_fwd), FWD_LABEL_TEXT);
}
if (selected_stream_rev) {
g_snprintf(label_text, sizeof(label_text), "Reverse: %s:%u -> %s:%u, SSRC=0x%X",
ep_address_to_display(&(selected_stream_rev->src_addr)),
selected_stream_rev->src_port,
ep_address_to_display(&(selected_stream_rev->dest_addr)),
selected_stream_rev->dest_port,
selected_stream_rev->ssrc
);
gtk_label_set_text(GTK_LABEL(label_rev), label_text);
} else {
gtk_label_set_text(GTK_LABEL(label_rev), REV_LABEL_TEXT);
}
return result;
}
static void
add_to_list_store(rtp_stream_info_t* strinfo)
{
gchar label_text[256];
gchar *data[NUM_COLS];
guint32 expected;
gint32 lost;
double perc;
int i;
char *savelocale;
savelocale = g_strdup(setlocale(LC_NUMERIC, NULL));
setlocale(LC_NUMERIC, "C");
data[0] = g_strdup(ep_address_to_display(&(strinfo->src_addr)));
data[1] = NULL;
data[2] = g_strdup(ep_address_to_display(&(strinfo->dest_addr)));
data[3] = NULL;
data[4] = g_strdup_printf("0x%X", strinfo->ssrc);
if (strinfo->info_payload_type_str != NULL) {
data[5] = g_strdup(strinfo->info_payload_type_str);
} else {
data[5] = g_strdup(val_to_str_ext(strinfo->pt, &rtp_payload_type_short_vals_ext,
"Unknown (%u)"));
}
data[6] = NULL;
expected = (strinfo->rtp_stats.stop_seq_nr + strinfo->rtp_stats.cycles*65536)
- strinfo->rtp_stats.start_seq_nr + 1;
lost = expected - strinfo->rtp_stats.total_nr;
if (expected) {
perc = (double)(lost*100)/(double)expected;
} else {
perc = 0;
}
data[7] = g_strdup_printf("%d (%.1f%%)", lost, perc);
data[8] = NULL;
data[9] = NULL;
data[10] = NULL;
if (strinfo->problem)
data[11] = g_strdup("X");
else
data[11] = g_strdup("");
setlocale(LC_NUMERIC, savelocale);
g_free(savelocale);
gtk_list_store_append(list_store, &list_iter);
gtk_list_store_set(list_store, &list_iter,
RTP_COL_SRC_ADDR, data[0],
RTP_COL_SRC_PORT, strinfo->src_port,
RTP_COL_DST_ADDR, data[2],
RTP_COL_DST_PORT, strinfo->dest_port,
RTP_COL_SSRC, data[4],
RTP_COL_PAYLOAD, data[5],
RTP_COL_PACKETS, strinfo->npackets,
RTP_COL_LOST, data[7],
RTP_COL_MAX_DELTA, strinfo->rtp_stats.max_delta,
RTP_COL_MAX_JITTER, strinfo->rtp_stats.max_jitter,
RTP_COL_MEAN_JITTER, strinfo->rtp_stats.mean_jitter,
RTP_COL_PROBLEM, data[11],
RTP_COL_DATA, strinfo,
-1);
for (i = 0; i < NUM_COLS-1; i++)
g_free(data[i]);
g_snprintf(label_text, sizeof(label_text),
"Detected %d RTP streams. Choose one for forward and reverse direction for analysis",
++streams_nb);
gtk_label_set_text(GTK_LABEL(top_label), label_text);
}
static void
create_list_view(void)
{
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeView *list_view;
GtkTreeSelection *selection;
list_store = gtk_list_store_new(NUM_COLS,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_DOUBLE,
G_TYPE_DOUBLE,
G_TYPE_DOUBLE,
G_TYPE_STRING,
G_TYPE_POINTER
);
list = gtk_tree_view_new_with_model(GTK_TREE_MODEL(list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, RTP_COL_SRC_ADDR, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref(G_OBJECT(list_store));
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Src addr", renderer,
"text", RTP_COL_SRC_ADDR,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_SRC_ADDR);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Src port", renderer,
"text", RTP_COL_SRC_PORT,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_SRC_PORT);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Dst addr", renderer,
"text", RTP_COL_DST_ADDR,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_DST_ADDR);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Dst port", renderer,
"text", RTP_COL_DST_PORT,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_DST_PORT);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("SSRC", renderer,
"text", RTP_COL_SSRC,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_SSRC);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_column_set_fixed_width(column, 90);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Payload", renderer,
"text", RTP_COL_PAYLOAD,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_PAYLOAD);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Packets", renderer,
"text", RTP_COL_PACKETS,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_PACKETS);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 70);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Lost", renderer,
"text", RTP_COL_LOST,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_LOST);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 90);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Max Delta (ms)", renderer,
"text", RTP_COL_MAX_DELTA,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_MAX_DELTA);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_column_set_fixed_width(column, 130);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Max Jitter (ms)", renderer,
"text", RTP_COL_MAX_JITTER,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_MAX_JITTER);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_column_set_fixed_width(column, 120);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mean Jitter (ms)", renderer,
"text", RTP_COL_MEAN_JITTER,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_MEAN_JITTER);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_column_set_fixed_width(column, 130);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Pb?", renderer,
"text", RTP_COL_PROBLEM,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RTP_COL_PROBLEM);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 30);
gtk_tree_view_column_set_fixed_width(column, 50);
gtk_tree_view_append_column(list_view, column);
gtk_tree_view_set_rules_hint(list_view, TRUE);
gtk_tree_view_set_headers_clickable(list_view, TRUE);
selection = gtk_tree_view_get_selection(list_view);
gtk_tree_selection_set_mode(selection, GTK_SELECTION_MULTIPLE);
gtk_tree_selection_set_select_function(selection, rtpstream_view_selection_func, NULL, NULL);
}
static void
rtpstream_dlg_create (void)
{
GtkWidget *rtpstream_dlg_w;
GtkWidget *main_vb;
GtkWidget *scrolledwindow;
GtkWidget *hbuttonbox;
GtkWidget *bt_unselect;
GtkWidget *bt_findrev;
GtkWidget *bt_save;
GtkWidget *bt_mark;
GtkWidget *bt_filter;
GtkWidget *bt_analyze;
GtkWidget *bt_close;
GtkWidget *bt_copy;
rtpstream_dlg_w = dlg_window_new("Wireshark: RTP Streams");
gtk_window_set_default_size(GTK_WINDOW(rtpstream_dlg_w), 620, 400);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(rtpstream_dlg_w), main_vb);
gtk_container_set_border_width (GTK_CONTAINER (main_vb), 12);
top_label = gtk_label_new ("Detected 0 RTP streams. Choose one for forward and reverse direction for analysis");
gtk_box_pack_start (GTK_BOX (main_vb), top_label, FALSE, FALSE, 8);
scrolledwindow = scrolled_window_new (NULL, NULL);
gtk_box_pack_start (GTK_BOX (main_vb), scrolledwindow, TRUE, TRUE, 0);
create_list_view();
gtk_container_add(GTK_CONTAINER(scrolledwindow), list);
gtk_widget_show(rtpstream_dlg_w);
label_fwd = gtk_label_new (FWD_LABEL_TEXT);
gtk_box_pack_start (GTK_BOX (main_vb), label_fwd, FALSE, FALSE, 0);
label_rev = gtk_label_new (REV_LABEL_TEXT);
gtk_box_pack_start (GTK_BOX (main_vb), label_rev, FALSE, FALSE, 0);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start (GTK_BOX (main_vb), hbuttonbox, FALSE, FALSE, 0);
gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_END);
gtk_box_set_spacing (GTK_BOX (hbuttonbox), 0);
bt_unselect = gtk_button_new_with_label ("Unselect");
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_unselect);
gtk_widget_set_tooltip_text (bt_unselect, "Undo stream selection");
bt_findrev = gtk_button_new_with_label ("Find Reverse");
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_findrev);
gtk_widget_set_tooltip_text (bt_findrev, "Find the reverse stream matching the selected forward stream");
bt_save = ws_gtk_button_new_from_stock(GTK_STOCK_SAVE_AS);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_save);
gtk_widget_set_tooltip_text (bt_save, "Save stream payload in rtpdump format");
bt_mark = gtk_button_new_with_label ("Mark Packets");
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_mark);
gtk_widget_set_tooltip_text (bt_mark, "Mark packets of the selected stream(s)");
bt_filter = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_PREPARE_FILTER);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_filter);
gtk_widget_set_tooltip_text (bt_filter, "Prepare a display filter of the selected stream(s)");
bt_copy = ws_gtk_button_new_from_stock(GTK_STOCK_COPY);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_copy);
gtk_widget_set_tooltip_text(bt_copy,
"Copy all statistical values of this page to the clipboard in CSV (Comma Separated Values) format.");
bt_analyze = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_ANALYZE);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_analyze);
gtk_widget_set_tooltip_text (bt_analyze, "Open an analyze window of the selected stream(s)");
bt_close = ws_gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_close);
gtk_widget_set_tooltip_text (bt_close, "Close this dialog");
gtk_widget_set_can_default(bt_close, TRUE);
g_signal_connect(bt_unselect, "clicked", G_CALLBACK(rtpstream_on_unselect), NULL);
g_signal_connect(bt_findrev, "clicked", G_CALLBACK(rtpstream_on_findrev), NULL);
g_signal_connect(bt_save, "clicked", G_CALLBACK(rtpstream_on_save), NULL);
g_signal_connect(bt_mark, "clicked", G_CALLBACK(rtpstream_on_mark), NULL);
g_signal_connect(bt_filter, "clicked", G_CALLBACK(rtpstream_on_filter), NULL);
g_signal_connect(bt_copy, "clicked", G_CALLBACK(rtpstream_on_copy_as_csv), NULL);
g_signal_connect(bt_analyze, "clicked", G_CALLBACK(rtpstream_on_analyse), NULL);
window_set_cancel_button(rtpstream_dlg_w, bt_close, window_cancel_button_cb);
g_signal_connect(rtpstream_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rtpstream_dlg_w, "destroy", G_CALLBACK(rtpstream_on_destroy), NULL);
gtk_widget_show_all(rtpstream_dlg_w);
window_present(rtpstream_dlg_w);
rtpstream_on_unselect(NULL, NULL);
rtp_stream_dlg = rtpstream_dlg_w;
}
void rtpstream_dlg_update(GList *list_lcl)
{
if (rtp_stream_dlg != NULL) {
gtk_list_store_clear(list_store);
streams_nb = 0;
list_lcl = g_list_first(list_lcl);
while (list_lcl)
{
add_to_list_store((rtp_stream_info_t*)(list_lcl->data));
list_lcl = g_list_next(list_lcl);
}
rtpstream_on_unselect(NULL, NULL);
}
last_list = list_lcl;
}
void rtpstream_dlg_show(GList *list_lcl)
{
if (rtp_stream_dlg != NULL) {
reactivate_window(rtp_stream_dlg);
if (list_lcl != last_list) {
rtpstream_dlg_update(list_lcl);
}
}
else {
rtpstream_dlg_create();
rtpstream_dlg_update(list_lcl);
}
}
void rtpstream_launch(GtkAction *action _U_, gpointer user_data _U_)
{
register_tap_listener_rtp_stream();
rtpstream_scan();
rtpstream_dlg_show(rtpstream_get_info()->strinfo_list);
}
void
register_tap_listener_rtp_stream_dlg(void)
{
}
