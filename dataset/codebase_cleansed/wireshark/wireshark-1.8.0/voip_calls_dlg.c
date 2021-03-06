static void
voip_calls_remove_tap_listener(void)
{
remove_tap_listener_sip_calls();
remove_tap_listener_isup_calls();
remove_tap_listener_mtp3_calls();
remove_tap_listener_h225_calls();
remove_tap_listener_h245dg_calls();
remove_tap_listener_q931_calls();
remove_tap_listener_h248_calls();
remove_tap_listener_sccp_calls();
remove_tap_listener_sdp_calls();
remove_tap_listener_rtp();
if (find_tap_id("unistim")) {
remove_tap_listener_unistim_calls();
}
if (find_tap_id("voip")) {
remove_tap_listener_voip_calls();
}
remove_tap_listener_rtp_event();
remove_tap_listener_mgcp_calls();
remove_tap_listener_actrace_calls();
remove_tap_listener_skinny_calls();
remove_tap_listener_iax2_calls();
remove_tap_listener_t38();
}
static void
voip_calls_on_destroy(GObject *object _U_, gpointer user_data _U_)
{
voip_calls_remove_tap_listener();
voip_calls_dlg_reset(NULL);
voip_calls_dlg = NULL;
g_free(graph_analysis_data);
graph_analysis_data = NULL;
}
static void
voip_calls_on_unselect(GtkButton *button _U_, gpointer user_data _U_)
{
gtk_widget_set_sensitive(bt_filter, FALSE);
gtk_widget_set_sensitive(bt_graph, FALSE);
#ifdef HAVE_LIBPORTAUDIO
gtk_widget_set_sensitive(bt_player, FALSE);
#endif
}
static void
voip_calls_on_filter(GtkButton *button _U_, gpointer user_data _U_)
{
gchar *filter_string;
GString *filter_string_fwd;
const gchar *filter_prepend;
gboolean is_first = TRUE;
GList* lista;
GList* listb;
voip_calls_info_t *listinfo;
graph_analysis_item_t *gai;
size_t filter_length;
size_t max_filter_length = 2048;
int pos;
const sip_calls_info_t *sipinfo;
const isup_calls_info_t *isupinfo;
const h323_calls_info_t *h323info;
const h245_address_t *h245_add = NULL;
const gcp_ctx_t* ctx;
filter_string = g_strdup(gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget)));
filter_length = strlen(filter_string);
pos = (int)filter_length;
g_strstrip(filter_string);
if (strlen(filter_string) > 0)
filter_prepend = " or ";
else
filter_prepend = "";
g_free(filter_string);
filter_string_fwd = g_string_new(filter_prepend);
g_string_append_printf(filter_string_fwd, "(");
lista = g_list_first(voip_calls_get_info()->callsinfo_list);
while (lista) {
listinfo = lista->data;
if (listinfo->selected) {
listb = g_list_first(voip_calls_get_info()->graph_analysis->list);
while (listb) {
gai = listb->data;
if (gai->conv_num == listinfo->call_num) {
g_string_append_printf(filter_string_fwd, "%sframe.number == %u", is_first?"":" or ", gai->fd->num);
is_first = FALSE;
}
listb = g_list_next(listb);
}
}
lista = g_list_next(lista);
}
g_string_append_printf(filter_string_fwd, ")");
filter_length += filter_string_fwd->len;
if (filter_length < max_filter_length) {
gtk_editable_insert_text(GTK_EDITABLE(main_display_filter_widget), filter_string_fwd->str, -1, &pos);
} else {
g_string_free(filter_string_fwd, TRUE);
filter_string_fwd = g_string_new(filter_prepend);
g_string_append_printf(filter_string_fwd, "(");
is_first = TRUE;
lista = g_list_first(voip_calls_get_info()->callsinfo_list);
while (lista) {
listinfo = lista->data;
if (listinfo->selected) {
if (!is_first)
g_string_append_printf(filter_string_fwd, " or ");
switch (listinfo->protocol) {
case VOIP_SIP:
sipinfo = listinfo->prot_info;
g_string_append_printf(filter_string_fwd,
"(sip.Call-ID == \"%s\")",
sipinfo->call_identifier
);
break;
case VOIP_ISUP:
isupinfo = listinfo->prot_info;
g_string_append_printf(filter_string_fwd,
"(isup.cic == %i and frame.number >= %i and frame.number <= %i and mtp3.network_indicator == %i and ((mtp3.dpc == %i) and (mtp3.opc == %i)) or ((mtp3.dpc == %i) and (mtp3.opc == %i)))",
isupinfo->cic, listinfo->start_fd->num,
listinfo->stop_fd->num,
isupinfo->ni, isupinfo->dpc, isupinfo->opc,
isupinfo->opc, isupinfo->dpc
);
break;
case VOIP_H323:
h323info = listinfo->prot_info;
g_string_append_printf(filter_string_fwd,
"((h225.guid == %s || q931.call_ref == %x:%x || q931.call_ref == %x:%x)",
guid_to_str(&h323info->guid[0]),
(guint8) (h323info->q931_crv & 0x00ff),
(guint8)((h323info->q931_crv & 0xff00)>>8),
(guint8) (h323info->q931_crv2 & 0x00ff),
(guint8)((h323info->q931_crv2 & 0xff00)>>8));
listb = g_list_first(h323info->h245_list);
while (listb) {
h245_add = listb->data;
g_string_append_printf(filter_string_fwd,
" || (ip.addr == %s && tcp.port == %d && h245)",
ip_to_str((guint8 *)(h245_add->h245_address.data)), h245_add->h245_port);
listb = g_list_next(listb);
}
g_string_append_printf(filter_string_fwd, ")");
break;
case TEL_H248:
ctx = listinfo->prot_info;
g_string_append_printf(filter_string_fwd,
"(h248.ctx == 0x%x)", ctx->id);
break;
default:
g_string_append_printf(filter_string_fwd,
"(frame)");
break;
}
is_first = FALSE;
}
lista = g_list_next(lista);
}
g_string_append_printf(filter_string_fwd, ")");
gtk_editable_insert_text(GTK_EDITABLE(main_display_filter_widget), filter_string_fwd->str, -1, &pos);
}
g_string_free(filter_string_fwd, TRUE);
}
static void
voip_calls_on_select_all(GtkButton *button _U_, gpointer user_data _U_)
{
GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_select_all(selection);
}
static gint
graph_analysis_sort_compare(gconstpointer a, gconstpointer b)
{
const graph_analysis_item_t *entry_a = (const graph_analysis_item_t *)a;
const graph_analysis_item_t *entry_b = (const graph_analysis_item_t *)b;
if(entry_a->fd->num < entry_b->fd->num)
return -1;
if(entry_a->fd->num > entry_b->fd->num)
return 1;
return 0;
}
static void
on_graph_bt_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
graph_analysis_item_t *gai;
GList* lista;
GList* listb;
voip_calls_info_t *listinfo;
if(!voip_calls_get_info()->reversed) {
voip_calls_get_info()->callsinfo_list=
g_list_reverse(voip_calls_get_info()->callsinfo_list);
voip_calls_get_info()->graph_analysis->list=
g_list_sort(voip_calls_get_info()->graph_analysis->list, graph_analysis_sort_compare);
voip_calls_get_info()->reversed=1;
}
listb = g_list_first(voip_calls_get_info()->graph_analysis->list);
while (listb) {
gai = listb->data;
gai->display = FALSE;
listb = g_list_next(listb);
}
lista = g_list_first(voip_calls_get_info()->callsinfo_list);
while (lista) {
listinfo = lista->data;
if (listinfo->selected) {
listb = g_list_first(voip_calls_get_info()->graph_analysis->list);
while (listb) {
gai = listb->data;
if (gai->conv_num == listinfo->call_num) {
gai->display = TRUE;
}
listb = g_list_next(listb);
}
}
lista = g_list_next(lista);
}
if (graph_analysis_data->dlg.window == NULL)
graph_analysis_create(graph_analysis_data);
else
graph_analysis_update(graph_analysis_data);
}
static void
on_player_bt_clicked(GtkButton *button _U_, gpointer user_data _U_)
{
rtp_player_init(voip_calls_get_info());
}
static gboolean
voip_calls_mark_selected(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter, gpointer data)
{
GtkTreeSelection *selection = (GtkTreeSelection *)data;
voip_calls_info_t* strinfo;
gtk_tree_model_get(model, iter, CALL_COL_DATA, &strinfo, -1);
strinfo->selected = gtk_tree_selection_iter_is_selected(selection, iter);
return FALSE;
}
static void
voip_calls_on_select_row_cb(GtkTreeSelection *selection, gpointer data _U_)
{
gchar label_text[80];
gtk_tree_model_foreach(GTK_TREE_MODEL(list_store), voip_calls_mark_selected, selection);
calls_ns = gtk_tree_selection_count_selected_rows(selection);
g_snprintf(label_text, 80,
"Detected %u VoIP %s. Selected %u %s.",
calls_nb,
plurality(calls_nb, "Call", "Calls"),
calls_ns,
plurality(calls_ns, "Call", "Calls"));
gtk_label_set_text(GTK_LABEL(top_label), label_text);
gtk_widget_set_sensitive(bt_filter, calls_ns ? TRUE : FALSE);
gtk_widget_set_sensitive(bt_graph, calls_ns ? TRUE : FALSE);
#ifdef HAVE_LIBPORTAUDIO
gtk_widget_set_sensitive(bt_player, calls_ns ? TRUE : FALSE);
#endif
}
static void
add_to_list_store(voip_calls_info_t* strinfo)
{
gchar field[NUM_COLS][50];
isup_calls_info_t *isupinfo;
h323_calls_info_t *h323info;
gboolean flag = FALSE;
g_snprintf(field[CALL_COL_INITIAL_SPEAKER], 30, "%s", get_addr_name(&(strinfo->initial_speaker)));
g_snprintf(field[CALL_COL_FROM], 50, "%s", strinfo->from_identity);
g_snprintf(field[CALL_COL_TO], 50, "%s", strinfo->to_identity);
g_snprintf(field[CALL_COL_PROTOCOL], 15, "%s",
((strinfo->protocol==VOIP_COMMON)&&strinfo->protocol_name)?
strinfo->protocol_name:voip_protocol_name[strinfo->protocol]);
g_snprintf(field[CALL_COL_STATE], 15, "%s", voip_call_state_name[strinfo->call_state]);
switch (strinfo->protocol) {
case VOIP_ISUP:
isupinfo = strinfo->prot_info;
g_snprintf(field[CALL_COL_COMMENTS],30, "%i-%i -> %i-%i", isupinfo->ni, isupinfo->opc,
isupinfo->ni, isupinfo->dpc);
break;
case VOIP_H323:
h323info = strinfo->prot_info;
if (strinfo->call_state == VOIP_CALL_SETUP)
flag = h323info->is_faststart_Setup;
else
if ((h323info->is_faststart_Setup == TRUE) && (h323info->is_faststart_Proc == TRUE))
flag = TRUE;
g_snprintf(field[CALL_COL_COMMENTS],35, "Tunneling: %s Fast Start: %s",
(h323info->is_h245Tunneling==TRUE?"ON":"OFF"),
(flag==TRUE?"ON":"OFF"));
break;
case VOIP_COMMON:
field[CALL_COL_COMMENTS][0]='\0';
if (strinfo->call_comment)
g_snprintf(field[CALL_COL_COMMENTS],30, "%s", strinfo->call_comment);
break;
default:
field[CALL_COL_COMMENTS][0]='\0';
}
gtk_list_store_append(list_store, &list_iter);
gtk_list_store_set(list_store, &list_iter,
CALL_COL_START_TIME, nstime_to_sec(&strinfo->start_fd->rel_ts),
CALL_COL_STOP_TIME, nstime_to_sec(&strinfo->stop_fd->rel_ts),
CALL_COL_INITIAL_SPEAKER, &field[CALL_COL_INITIAL_SPEAKER][0],
CALL_COL_FROM, &field[CALL_COL_FROM][0],
CALL_COL_TO, &field[CALL_COL_TO][0],
CALL_COL_PROTOCOL, &field[CALL_COL_PROTOCOL][0],
CALL_COL_PACKETS, strinfo->npackets,
CALL_COL_STATE, &field[CALL_COL_STATE][0],
CALL_COL_COMMENTS, &field[CALL_COL_COMMENTS][0],
CALL_COL_DATA, strinfo,
-1);
calls_nb += 1;
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
G_TYPE_DOUBLE,
G_TYPE_DOUBLE,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_POINTER
);
list = gtk_tree_view_new_with_model(GTK_TREE_MODEL(list_store));
g_object_unref(G_OBJECT(list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, CALL_COL_START_TIME, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
renderer = gtk_cell_renderer_text_new();
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
g_object_set(G_OBJECT(renderer), "xpad", 10, NULL);
column = gtk_tree_view_column_new_with_attributes("Start Time", renderer,
"text", CALL_COL_START_TIME,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_START_TIME);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
g_object_set(G_OBJECT(renderer), "xpad", 10, NULL);
column = gtk_tree_view_column_new_with_attributes("Stop Time", renderer,
"text", CALL_COL_STOP_TIME,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_STOP_TIME);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Initial Speaker", renderer,
"text", CALL_COL_INITIAL_SPEAKER,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_INITIAL_SPEAKER);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_column_set_fixed_width(column, 120);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("From", renderer,
"text", CALL_COL_FROM,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_FROM);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 130);
gtk_tree_view_column_set_fixed_width(column, 140);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("To", renderer,
"text", CALL_COL_TO,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_TO);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 130);
gtk_tree_view_column_set_fixed_width(column, 140);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Protocol", renderer,
"text", CALL_COL_PROTOCOL,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_PROTOCOL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
g_object_set(G_OBJECT(renderer), "xpad", 10, NULL);
column = gtk_tree_view_column_new_with_attributes("Packets", renderer,
"text", CALL_COL_PACKETS,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_PACKETS);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 70);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("State", renderer,
"text", CALL_COL_STATE,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_STATE);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column(list_view, column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Comments", renderer,
"text", CALL_COL_COMMENTS,
NULL);
gtk_tree_view_column_set_sort_column_id(column, CALL_COL_COMMENTS);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_column_set_fixed_width(column, 140);
gtk_tree_view_append_column(list_view, column);
gtk_tree_view_set_rules_hint(list_view, TRUE);
gtk_tree_view_set_headers_clickable(list_view, TRUE);
selection = gtk_tree_view_get_selection(list_view);
gtk_tree_selection_set_mode(selection, GTK_SELECTION_MULTIPLE);
g_signal_connect(G_OBJECT(selection), "changed",
G_CALLBACK(voip_calls_on_select_row_cb),
NULL);
}
static void
voip_calls_dlg_create(void)
{
GtkWidget *voip_calls_dlg_w;
GtkWidget *main_vb;
GtkWidget *scrolledwindow;
GtkWidget *hbuttonbox;
GtkWidget *bt_close;
GtkWidget *bt_select_all;
gchar *title_name_ptr;
gchar *win_name;
title_name_ptr = cf_get_display_name(&cfile);
win_name = g_strdup_printf("%s - VoIP Calls", title_name_ptr);
g_free(title_name_ptr);
voip_calls_dlg_w = dlg_window_new(win_name);
gtk_window_set_destroy_with_parent(GTK_WINDOW(voip_calls_dlg_w), TRUE);
gtk_window_set_default_size(GTK_WINDOW(voip_calls_dlg_w), 1000, 350);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(voip_calls_dlg_w), main_vb);
gtk_container_set_border_width(GTK_CONTAINER (main_vb), 12);
top_label = gtk_label_new("Detected 0 VoIP Calls. Selected 0 Calls.");
gtk_box_pack_start(GTK_BOX (main_vb), top_label, FALSE, FALSE, 8);
scrolledwindow = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX (main_vb), scrolledwindow, TRUE, TRUE, 0);
create_list_view();
gtk_container_add(GTK_CONTAINER(scrolledwindow), list);
gtk_widget_show(voip_calls_dlg_w);
status_label = gtk_label_new("Total: Calls: 0 Start packets: 0 Completed calls: 0 Rejected calls: 0");
gtk_box_pack_start(GTK_BOX(main_vb), status_label, FALSE, FALSE, 8);
hbuttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(main_vb), hbuttonbox, FALSE, FALSE, 0);
gtk_button_box_set_layout(GTK_BUTTON_BOX (hbuttonbox), GTK_BUTTONBOX_SPREAD);
gtk_box_set_spacing(GTK_BOX(hbuttonbox), 30);
bt_filter = gtk_button_new_from_stock(WIRESHARK_STOCK_PREPARE_FILTER);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_filter);
gtk_widget_set_tooltip_text(bt_filter, "Prepare a display filter of the selected conversation");
bt_graph = gtk_button_new_from_stock(WIRESHARK_STOCK_VOIP_FLOW);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_graph);
gtk_widget_show(bt_graph);
g_signal_connect(bt_graph, "clicked", G_CALLBACK(on_graph_bt_clicked), NULL);
gtk_widget_set_tooltip_text(bt_graph, "Show a flow graph of the selected calls.");
#ifdef HAVE_LIBPORTAUDIO
bt_player = gtk_button_new_from_stock(WIRESHARK_STOCK_AUDIO_PLAYER);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_player);
gtk_widget_show(bt_player);
g_signal_connect(bt_player, "clicked", G_CALLBACK(on_player_bt_clicked), NULL);
gtk_widget_set_tooltip_text(bt_player, "Launch the RTP player to listen the selected calls.");
#endif
bt_select_all = gtk_button_new_from_stock(GTK_STOCK_SELECT_ALL);
gtk_container_add(GTK_CONTAINER(hbuttonbox), bt_select_all);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(bt_select_all, TRUE);
#else
GTK_WIDGET_SET_FLAGS(bt_select_all, GTK_CAN_DEFAULT);
#endif
gtk_widget_set_tooltip_text(bt_select_all, "Select all the calls");
bt_close = gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_container_add(GTK_CONTAINER (hbuttonbox), bt_close);
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_set_can_default(bt_close, TRUE);
#else
GTK_WIDGET_SET_FLAGS(bt_close, GTK_CAN_DEFAULT);
#endif
gtk_widget_set_tooltip_text(bt_close, "Close this dialog");
g_signal_connect(bt_filter, "clicked", G_CALLBACK(voip_calls_on_filter), NULL);
window_set_cancel_button(voip_calls_dlg_w, bt_close, window_cancel_button_cb);
g_signal_connect(voip_calls_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(voip_calls_dlg_w, "destroy", G_CALLBACK(voip_calls_on_destroy), NULL);
g_signal_connect(bt_select_all, "clicked", G_CALLBACK(voip_calls_on_select_all), NULL);
gtk_widget_show_all(voip_calls_dlg_w);
window_present(voip_calls_dlg_w);
voip_calls_on_unselect(NULL, NULL);
voip_calls_dlg = voip_calls_dlg_w;
g_free(win_name);
}
void
voip_calls_dlg_update(GList *listx)
{
GtkTreeSortable *sortable;
gchar label_text[256];
sortable = GTK_TREE_SORTABLE(list_store);
if (voip_calls_dlg != NULL) {
calls_nb = 0;
calls_ns = 0;
gtk_list_store_clear(list_store);
g_snprintf(label_text, sizeof(label_text),
"Total: Calls: %u Start packets: %u Completed calls: %u Rejected calls: %u",
g_list_length(voip_calls_get_info()->callsinfo_list),
voip_calls_get_info()->start_packets,
voip_calls_get_info()->completed_calls,
voip_calls_get_info()->rejected_calls);
gtk_label_set_text(GTK_LABEL(status_label), label_text);
gtk_tree_sortable_set_sort_column_id(sortable, GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID, GTK_SORT_ASCENDING);
listx = g_list_first(listx);
while (listx) {
add_to_list_store((voip_calls_info_t*)(listx->data));
listx = g_list_next(listx);
}
gtk_tree_sortable_set_sort_column_id(sortable, CALL_COL_START_TIME, GTK_SORT_ASCENDING);
g_snprintf(label_text, sizeof(label_text),
"Detected %u VoIP %s. Selected %u %s.",
calls_nb,
plurality(calls_nb, "Call", "Calls"),
calls_ns,
plurality(calls_ns, "Call", "Calls"));
gtk_label_set_text(GTK_LABEL(top_label), label_text);
}
}
void
voip_calls_dlg_draw(void *ptr _U_)
{
if (voip_calls_get_info()->redraw) {
voip_calls_dlg_update(voip_calls_get_info()->callsinfo_list);
voip_calls_get_info()->redraw = FALSE;
}
}
void
voip_calls_dlg_reset(void *ptr _U_)
{
voip_calls_reset(voip_calls_get_info());
if (graph_analysis_data && graph_analysis_data->dlg.window != NULL) {
window_cancel_button_cb(NULL, graph_analysis_data->dlg.window);
graph_analysis_data->dlg.window = NULL;
}
}
static void
voip_calls_init_tap(const char *dummy _U_, void* userdata _U_)
{
if (graph_analysis_data == NULL) {
graph_analysis_data_init();
graph_analysis_data = graph_analysis_init();
graph_analysis_data->graph_info = voip_calls_get_info()->graph_analysis;
}
voip_calls_reset(voip_calls_get_info());
sip_calls_init_tap();
mtp3_calls_init_tap();
isup_calls_init_tap();
h225_calls_init_tap();
h245dg_calls_init_tap();
q931_calls_init_tap();
h248_calls_init_tap();
sccp_calls_init_tap();
sdp_calls_init_tap();
if (find_tap_id("unistim")) {
unistim_calls_init_tap();
}
if (find_tap_id("voip")) {
VoIPcalls_init_tap();
}
rtp_init_tap();
rtp_event_init_tap();
mgcp_calls_init_tap();
actrace_calls_init_tap();
skinny_calls_init_tap();
iax2_calls_init_tap();
t38_init_tap();
if (voip_calls_dlg == NULL) {
voip_calls_dlg_create();
} else {
reactivate_window(voip_calls_dlg);
}
voip_calls_get_info()->redraw = TRUE;
voip_calls_dlg_draw(NULL);
voip_calls_get_info()->redraw = TRUE;
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(voip_calls_dlg));
}
void
voip_calls_launch(GtkAction *action _U_, gpointer user_data _U_)
{
voip_calls_init_tap("", NULL);
}
void
register_tap_listener_voip_calls_dlg(void)
{
register_stat_cmd_arg("voip,calls", voip_calls_init_tap, NULL);
}
