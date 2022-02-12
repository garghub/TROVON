static void
ansi_a_stat_reset(
void *tapdata)
{
ansi_a_stat_t *stat_p = tapdata;
memset(stat_p, 0, sizeof(ansi_a_stat_t));
}
static gboolean
ansi_a_stat_packet(
void *tapdata,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *data)
{
ansi_a_stat_t *stat_p = tapdata;
const ansi_a_tap_rec_t *data_p = data;
switch (data_p->pdu_type)
{
case BSSAP_PDU_TYPE_BSMAP:
stat_p->bsmap_message_type[data_p->message_type]++;
break;
case BSSAP_PDU_TYPE_DTAP:
stat_p->dtap_message_type[data_p->message_type]++;
break;
default:
return(FALSE);
}
return(TRUE);
}
static void
ansi_a_stat_draw(
void *tapdata)
{
ansi_a_stat_t *stat_p = tapdata;
int i;
GtkListStore *list_store;
GtkTreeIter iter;
if (dlg_bsmap.win && tapdata)
{
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (dlg_bsmap.table)));
i = 0;
while (ansi_a_bsmap_strings[i].strptr){
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
IEI_COLUMN, ansi_a_bsmap_strings[i].value,
MSG_NAME_COLUMN, (char *)ansi_a_bsmap_strings[i].strptr,
COUNT_COLUMN, stat_p->bsmap_message_type[ansi_a_bsmap_strings[i].value],
-1);
i++;
}
}
if (dlg_dtap.win && tapdata){
i = 0;
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (dlg_dtap.table)));
while (ansi_a_dtap_strings[i].strptr){
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
IEI_COLUMN, ansi_a_dtap_strings[i].value,
MSG_NAME_COLUMN, (char *)ansi_a_dtap_strings[i].strptr,
COUNT_COLUMN, stat_p->dtap_message_type[ansi_a_dtap_strings[i].value],
-1);
i++;
}
}
}
static void
ansi_a_stat_gtk_win_destroy_cb(
GtkWindow *win _U_,
gpointer user_data )
{
memset((void *) user_data, 0, sizeof(ansi_a_stat_dlg_t));
}
static
GtkWidget* create_list(void)
{
GtkListStore *list_store;
GtkWidget *list;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeView *list_view;
GtkTreeSelection *selection;
list_store = gtk_list_store_new(N_COLUMN,
G_TYPE_UINT,
G_TYPE_STRING,
G_TYPE_UINT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, IEI_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("IEI", renderer,
"text", IEI_COLUMN,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, present_as_hex_func,
GINT_TO_POINTER(IEI_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, IEI_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Message Name", renderer,
"text", MSG_NAME_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, MSG_NAME_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 280);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Count", renderer,
"text", COUNT_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, COUNT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 50);
gtk_tree_view_append_column (list_view, column);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(list_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list_view), TRUE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
return list;
}
static void
ansi_a_stat_gtk_win_create(
ansi_a_stat_dlg_t *dlg_p,
const char *title)
{
GtkWidget *vbox;
GtkWidget *bt_close;
GtkWidget *bbox;
dlg_p->win= dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(dlg_p->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(dlg_p->win), 480, 450);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(dlg_p->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
dlg_p->scrolled_win = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), dlg_p->scrolled_win, TRUE, TRUE, 0);
dlg_p->table = create_list();
gtk_widget_show(dlg_p->table);
gtk_container_add(GTK_CONTAINER(dlg_p->scrolled_win), dlg_p->table);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
bt_close = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(dlg_p->win, bt_close, window_cancel_button_cb);
g_signal_connect(dlg_p->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(dlg_p->win, "destroy", G_CALLBACK(ansi_a_stat_gtk_win_destroy_cb), dlg_p);
gtk_widget_show_all(dlg_p->win);
window_present(dlg_p->win);
}
void
ansi_a_stat_gtk_bsmap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
if (dlg_bsmap.win)
{
gdk_window_raise(gtk_widget_get_window(dlg_bsmap.win));
return;
}
ansi_a_stat_gtk_win_create(&dlg_bsmap, "ANSI A-I/F BSMAP Statistics");
ansi_a_stat_draw(&ansi_a_stat);
}
void
ansi_a_stat_gtk_dtap_cb(GtkAction *action _U_, gpointer user_data _U_)
{
if (dlg_dtap.win)
{
gdk_window_raise(gtk_widget_get_window(dlg_dtap.win));
return;
}
ansi_a_stat_gtk_win_create(&dlg_dtap, "ANSI A-I/F DTAP Statistics");
ansi_a_stat_draw(&ansi_a_stat);
}
void
register_tap_listener_gtkansi_a_stat(void)
{
GString *err_p;
memset((void *) &ansi_a_stat, 0, sizeof(ansi_a_stat_t));
err_p =
register_tap_listener("ansi_a", &ansi_a_stat, NULL, 0,
ansi_a_stat_reset,
ansi_a_stat_packet,
ansi_a_stat_draw);
if (err_p != NULL)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_p->str);
g_string_free(err_p, TRUE);
exit(1);
}
}
