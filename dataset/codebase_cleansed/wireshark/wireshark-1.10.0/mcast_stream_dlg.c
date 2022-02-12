static void
mcaststream_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
remove_tap_listener_mcast_stream();
if (mcast_params_dlg != NULL)
window_destroy(mcast_params_dlg);
mcaststream_reset((mcaststream_tapinfo_t*)mcaststream_get_info());
mcast_stream_dlg = NULL;
}
static void
mcaststream_on_unselect(GtkButton *button _U_, gpointer user_data _U_)
{
GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list_w));
gtk_tree_selection_unselect_all(selection);
selected_stream_fwd = NULL;
gtk_label_set_text(GTK_LABEL(label_fwd), FWD_LABEL_TEXT);
gtk_widget_set_sensitive(bt_filter, FALSE);
}
static void
mcaststream_on_filter(GtkButton *button _U_, gpointer user_data _U_)
{
gchar *filter_string_fwd;
gchar ip_version[3];
if (selected_stream_fwd == NULL)
return;
if (selected_stream_fwd->src_addr.type == AT_IPv6) {
g_strlcpy(ip_version,"v6",sizeof(ip_version));
} else {
ip_version[0] = '\0';
}
filter_string_fwd = g_strdup_printf(
"(ip%s.src==%s && udp.srcport==%u && ip%s.dst==%s && udp.dstport==%u)",
ip_version,
ep_address_to_str(&(selected_stream_fwd->src_addr)),
selected_stream_fwd->src_port,
ip_version,
ep_address_to_str(&(selected_stream_fwd->dest_addr)),
selected_stream_fwd->dest_port);
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), filter_string_fwd);
g_free(filter_string_fwd);
#if 0
main_filter_packets(&cfile, filter_string, FALSE);
mcaststream_dlg_update(mcaststream_get_info()->strinfo_list);
#endif
}
static void
mcaststream_on_select_row(GtkTreeSelection *selection, gpointer data _U_)
{
gchar label_text[80];
if (gtk_tree_selection_get_selected(selection, NULL, &list_iter))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store), &list_iter, MC_COL_DATA, &selected_stream_fwd, -1);
g_snprintf(label_text, sizeof(label_text), "Selected: %s:%u -> %s:%u",
get_addr_name(&(selected_stream_fwd->src_addr)),
selected_stream_fwd->src_port,
get_addr_name(&(selected_stream_fwd->dest_addr)),
selected_stream_fwd->dest_port
);
gtk_label_set_text(GTK_LABEL(label_fwd), label_text);
gtk_widget_set_sensitive(bt_filter, TRUE);
} else {
selected_stream_fwd = NULL;
gtk_label_set_text(GTK_LABEL(label_fwd), FWD_LABEL_TEXT);
gtk_widget_set_sensitive(bt_filter, FALSE);
}
}
static void
mcast_params_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
mcast_params_dlg = NULL;
}
static void
mcast_params_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
GtkWidget *fnumber_te;
const gchar *fnumber_text;
gint32 fnumber;
char *p;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_MCAST_ENTRY_1);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (gint)strtol(fnumber_text, &p, 10);
if ( ((p == fnumber_text) || (*p != '\0')) || (fnumber <= 0) || (fnumber > 1000) ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The burst interval should be between 1 and 1000 ms.");
return;
}
mcast_stream_burstint = fnumber;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_MCAST_ENTRY_2);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (gint)strtol(fnumber_text, &p, 10);
if ( ((p == fnumber_text) || (*p != '\0')) || (fnumber <= 0) ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The burst alarm threshold you entered isn't valid.");
return;
}
mcast_stream_trigger = fnumber;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_MCAST_ENTRY_3);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (gint)strtol(fnumber_text, &p, 10);
if ( ((p == fnumber_text) || (*p != '\0')) || (fnumber <= 0) ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The buffer alarm threshold you entered isn't valid.");
return;
}
mcast_stream_bufferalarm = fnumber;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_MCAST_ENTRY_4);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (gint)strtol(fnumber_text, &p, 10);
if ( ((p == fnumber_text) || (*p != '\0')) || (fnumber <= 0) || (fnumber > 10000000) ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The stream empty speed should be between 1 and 10000000");
return;
}
mcast_stream_emptyspeed = fnumber;
fnumber_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_MCAST_ENTRY_5);
fnumber_text = gtk_entry_get_text(GTK_ENTRY(fnumber_te));
fnumber = (gint)strtol(fnumber_text, &p, 10);
if ( ((p == fnumber_text) || (*p != '\0')) || (fnumber <= 0) || (fnumber > 10000000) ) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The total empty speed should be between 1 and 10000000");
return;
}
mcast_stream_cumulemptyspeed = fnumber;
window_destroy(GTK_WIDGET(parent_w));
mcaststream_reset((mcaststream_tapinfo_t*)mcaststream_get_info());
cf_retap_packets(&cfile);
}
static void
mcast_on_params(GtkButton *button _U_, gpointer data _U_)
{
GtkWidget *main_vb;
GtkWidget *label, *hbuttonbox, *grid;
GtkWidget *ok_bt, *cancel_bt;
GtkWidget *entry1, *entry2, *entry3, *entry4, *entry5;
gchar label_text[51];
if (mcast_params_dlg != NULL) {
reactivate_window(mcast_params_dlg);
return;
}
mcast_params_dlg = dlg_window_new("Wireshark: Set parameters for Multicast Stream Analysis");
gtk_window_set_destroy_with_parent(GTK_WINDOW(mcast_params_dlg), TRUE);
gtk_window_set_default_size(GTK_WINDOW(mcast_params_dlg), 210, 210);
gtk_widget_show(mcast_params_dlg);
main_vb =ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 2);
gtk_container_add(GTK_CONTAINER(mcast_params_dlg), main_vb);
gtk_widget_show(main_vb);
grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), grid, TRUE, TRUE, 0);
label = gtk_label_new(" Burst measurement interval (ms) ");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, 0, 1, 1);
entry1 = gtk_entry_new();
g_snprintf(label_text, sizeof(label_text), "%u", mcast_stream_burstint);
gtk_entry_set_text(GTK_ENTRY(entry1), label_text);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), entry1, 1, 0, 1, 1);
label = gtk_label_new(" Burst alarm threshold (packets) ");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, 1, 1, 1);
entry2 = gtk_entry_new();
g_snprintf(label_text, sizeof(label_text), "%u", mcast_stream_trigger);
gtk_entry_set_text(GTK_ENTRY(entry2), label_text);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), entry2, 1, 1, 1, 1);
label = gtk_label_new(" Buffer alarm threshold (bytes) ");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, 2, 1, 1);
entry3 = gtk_entry_new();
g_snprintf(label_text, sizeof(label_text), "%u", mcast_stream_bufferalarm);
gtk_entry_set_text(GTK_ENTRY(entry3), label_text);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), entry3, 1, 2, 1, 1);
label = gtk_label_new(" Stream empty speed (kbit/s) ");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, 3, 1, 1);
entry4 = gtk_entry_new();
g_snprintf(label_text, sizeof(label_text), "%u", mcast_stream_emptyspeed);
gtk_entry_set_text(GTK_ENTRY(entry4), label_text);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), entry4, 1, 3, 1, 1);
label = gtk_label_new(" Total empty speed (kbit/s) ");
ws_gtk_grid_attach_defaults(GTK_GRID(grid), label, 0, 4, 1, 1);
entry5 = gtk_entry_new();
g_snprintf(label_text, sizeof(label_text), "%u", mcast_stream_cumulemptyspeed);
gtk_entry_set_text(GTK_ENTRY(entry5), label_text);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), entry5, 1, 4, 1, 1);
gtk_widget_show (grid);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), hbuttonbox, 0, 5, 2, 1);
ok_bt = gtk_button_new_from_stock(GTK_STOCK_OK);
gtk_container_add (GTK_CONTAINER(hbuttonbox), ok_bt);
cancel_bt = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
gtk_container_add (GTK_CONTAINER(hbuttonbox), cancel_bt);
gtk_widget_set_can_default(cancel_bt, TRUE);
gtk_button_box_set_layout(GTK_BUTTON_BOX(hbuttonbox), GTK_BUTTONBOX_END);
gtk_box_set_spacing(GTK_BOX(hbuttonbox), 0);
g_signal_connect(mcast_params_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(mcast_params_dlg, "destroy", G_CALLBACK(mcast_params_destroy_cb), NULL);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(mcast_params_ok_cb), mcast_params_dlg);
window_set_cancel_button(mcast_params_dlg, cancel_bt, window_cancel_button_cb);
g_object_set_data(G_OBJECT(mcast_params_dlg), E_MCAST_ENTRY_1, entry1);
g_object_set_data(G_OBJECT(mcast_params_dlg), E_MCAST_ENTRY_2, entry2);
g_object_set_data(G_OBJECT(mcast_params_dlg), E_MCAST_ENTRY_3, entry3);
g_object_set_data(G_OBJECT(mcast_params_dlg), E_MCAST_ENTRY_4, entry4);
g_object_set_data(G_OBJECT(mcast_params_dlg), E_MCAST_ENTRY_5, entry5);
gtk_widget_show_all(mcast_params_dlg);
window_present(mcast_params_dlg);
}
static void
add_to_list_store(mcast_stream_info_t* strinfo)
{
gchar label_text[256];
gchar *data[NUM_COLS];
int i;
char *savelocale;
savelocale = setlocale(LC_NUMERIC, NULL);
setlocale(LC_NUMERIC, "C");
data[0] = g_strdup(get_addr_name(&(strinfo->src_addr)));
data[1] = g_strdup_printf("%u", strinfo->src_port);
data[2] = g_strdup(get_addr_name(&(strinfo->dest_addr)));
data[3] = g_strdup_printf("%u", strinfo->dest_port);
data[4] = g_strdup_printf("%u", strinfo->npackets);
data[5] = g_strdup_printf("%u /s", strinfo->apackets);
data[6] = g_strdup_printf("%2.1f Mbps", strinfo->average_bw);
data[7] = g_strdup_printf("%2.1f Mbps", strinfo->element.maxbw);
data[8] = g_strdup_printf("%u / %dms", strinfo->element.topburstsize, mcast_stream_burstint);
data[9] = g_strdup_printf("%u", strinfo->element.numbursts);
data[10] = g_strdup_printf("%.1f KB", (float)strinfo->element.topbuffusage/1000);
data[11] = g_strdup_printf("%u", strinfo->element.numbuffalarms);
setlocale(LC_NUMERIC, savelocale);
gtk_list_store_append(list_store, &list_iter);
gtk_list_store_set(list_store, &list_iter,
MC_COL_SRC_ADDR, data[0],
MC_COL_SRC_PORT, data[1],
MC_COL_DST_ADDR, data[2],
MC_COL_DST_PORT, data[3],
MC_COL_PACKETS, data[4],
MC_COL_PPS, data[5],
MC_COL_AVG_BW, data[6],
MC_COL_MAX_BW, data[7],
MC_COL_MAX_BURST, data[8],
MC_COL_BURST_ALARM, data[9],
MC_COL_MAX_BUFFER, data[10],
MC_COL_BUFFER_ALARM, data[11],
MC_COL_DATA, strinfo,
-1);
for (i = 0; i < NUM_COLS-1; i++)
g_free(data[i]);
g_snprintf(label_text, sizeof(label_text),
"Detected %d Multicast streams, Average Bw: %.1f Mbps Max Bw: %.1f Mbps Max burst: %d / %dms Max buffer: %.1f KB",
++streams_nb,
mcaststream_get_info()->allstreams->average_bw, mcaststream_get_info()->allstreams->element.maxbw,
mcaststream_get_info()->allstreams->element.topburstsize, mcast_stream_burstint,
(float)(mcaststream_get_info()->allstreams->element.topbuffusage)/1000);
gtk_label_set_text(GTK_LABEL(top_label), label_text);
g_snprintf(label_text, sizeof(label_text), "\nBurst int: %u ms Burst alarm: %u pps Buffer alarm: %u Bytes Stream empty speed: %u Kbps Total empty speed: %u Kbps\n",
mcast_stream_burstint, mcast_stream_trigger, mcast_stream_bufferalarm, mcast_stream_emptyspeed, mcast_stream_cumulemptyspeed);
gtk_label_set_text(GTK_LABEL(label_par), label_text);
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
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_POINTER
);
list_w = gtk_tree_view_new_with_model(GTK_TREE_MODEL(list_store));
list_view = GTK_TREE_VIEW(list_w);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, MC_COL_SRC_ADDR, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref(G_OBJECT(list_store));
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Src IP addr", renderer,
"text", MC_COL_SRC_ADDR,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_SRC_ADDR);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Src port", renderer,
"text", MC_COL_SRC_PORT,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_SRC_PORT);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Dst IP addr", renderer,
"text", MC_COL_DST_ADDR,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_DST_ADDR);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Dst port", renderer,
"text", MC_COL_DST_PORT,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_DST_PORT);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Packets", renderer,
"text", MC_COL_PACKETS,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_PACKETS);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Packets/s", renderer,
"text", MC_COL_PPS,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_PPS);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 90);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Avg Bw", renderer,
"text", MC_COL_AVG_BW,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_AVG_BW);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Max Bw", renderer,
"text", MC_COL_MAX_BW,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_MAX_BW);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Max bursts", renderer,
"text", MC_COL_MAX_BURST,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_MAX_BURST);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Burst alarms", renderer,
"text", MC_COL_BURST_ALARM,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_BURST_ALARM);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_column_set_fixed_width(column, 110);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Max buffers", renderer,
"text", MC_COL_MAX_BUFFER,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_MAX_BUFFER);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Buffer alarms", renderer,
"text", MC_COL_BUFFER_ALARM,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MC_COL_BUFFER_ALARM);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 90);
gtk_tree_view_column_set_fixed_width(column, 120);
gtk_tree_view_append_column(list_view, column);
gtk_tree_view_set_rules_hint(list_view, TRUE);
gtk_tree_view_set_headers_clickable(list_view, TRUE);
selection = gtk_tree_view_get_selection(list_view);
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
g_signal_connect(G_OBJECT(selection), "changed",
G_CALLBACK(mcaststream_on_select_row),
NULL);
}
static void
mcaststream_dlg_create(void)
{
GtkWidget *mcaststream_dlg_w;
GtkWidget *main_vb;
GtkWidget *scrolledwindow;
GtkWidget *hbuttonbox;
GtkWidget *bt_params;
GtkWidget *bt_close;
gchar *title_name_ptr;
gchar *win_name;
title_name_ptr = cf_get_display_name(&cfile);
win_name = g_strdup_printf("%s - UDP Multicast Streams", title_name_ptr);
g_free(title_name_ptr);
mcaststream_dlg_w = dlg_window_new(win_name);
gtk_window_set_default_size(GTK_WINDOW(mcaststream_dlg_w), 1150, 400);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(mcaststream_dlg_w), main_vb);
gtk_container_set_border_width (GTK_CONTAINER (main_vb), 12);
top_label = gtk_label_new ("Detected 0 Multicast streams");
gtk_box_pack_start (GTK_BOX (main_vb), top_label, FALSE, FALSE, 8);
scrolledwindow = scrolled_window_new (NULL, NULL);
gtk_box_pack_start (GTK_BOX (main_vb), scrolledwindow, TRUE, TRUE, 0);
create_list_view();
gtk_container_add(GTK_CONTAINER(scrolledwindow), list_w);
gtk_widget_show(mcaststream_dlg_w);
label_fwd = gtk_label_new (FWD_LABEL_TEXT);
gtk_box_pack_start (GTK_BOX (main_vb), label_fwd, FALSE, FALSE, 0);
label_par = gtk_label_new (PAR_LABEL_TEXT);
gtk_box_pack_start (GTK_BOX (main_vb), label_par, FALSE, FALSE, 0);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start (GTK_BOX (main_vb), hbuttonbox, FALSE, FALSE, 0);
gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_END);
gtk_box_set_spacing (GTK_BOX (hbuttonbox), 0);
bt_params = gtk_button_new_with_label ("Set parameters");
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_params);
gtk_widget_set_tooltip_text (bt_params, "Set buffer, limit and speed parameters");
bt_filter = gtk_button_new_with_label ("Prepare Filter");
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_filter);
gtk_widget_set_tooltip_text (bt_filter, "Prepare a display filter of the selected stream");
bt_close = gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add (GTK_CONTAINER (hbuttonbox), bt_close);
gtk_widget_set_tooltip_text (bt_close, "Close this dialog");
gtk_widget_set_can_default(bt_close, TRUE);
g_signal_connect(bt_params, "clicked", G_CALLBACK(mcast_on_params), NULL);
g_signal_connect(bt_filter, "clicked", G_CALLBACK(mcaststream_on_filter), NULL);
window_set_cancel_button(mcaststream_dlg_w, bt_close, window_cancel_button_cb);
g_signal_connect(mcaststream_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(mcaststream_dlg_w, "destroy", G_CALLBACK(mcaststream_on_destroy), NULL);
gtk_widget_show_all(mcaststream_dlg_w);
window_present(mcaststream_dlg_w);
mcaststream_on_unselect(NULL, NULL);
mcast_stream_dlg = mcaststream_dlg_w;
g_free(win_name);
}
void
mcaststream_dlg_update(GList *list)
{
if (mcast_stream_dlg != NULL) {
gtk_list_store_clear(list_store);
streams_nb = 0;
list = g_list_first(list);
while (list)
{
add_to_list_store((mcast_stream_info_t*)(list->data));
list = g_list_next(list);
}
mcaststream_on_unselect(NULL, NULL);
}
last_list = list;
}
void
mcaststream_dlg_show(GList *list)
{
if (mcast_stream_dlg != NULL) {
reactivate_window(mcast_stream_dlg);
if (list != last_list) {
mcaststream_dlg_update(list);
}
}
else {
mcaststream_dlg_create();
mcaststream_dlg_update(list);
}
}
void
mcaststream_launch(GtkAction *action _U_, gpointer user_data _U_)
{
register_tap_listener_mcast_stream();
mcaststream_scan();
mcaststream_dlg_show(mcaststream_get_info()->strinfo_list);
}
void
register_tap_listener_mcast_stream_dlg(void)
{
}
