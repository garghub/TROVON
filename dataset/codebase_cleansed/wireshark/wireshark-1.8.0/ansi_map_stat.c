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
G_TYPE_UINT,
G_TYPE_UINT,
G_TYPE_FLOAT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, OP_CODE_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Op Code", renderer,
"text", OP_CODE_COLUMN,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, present_as_hex_func,
GINT_TO_POINTER(OP_CODE_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, OP_CODE_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Operation Name", renderer,
"text", OP_CODE_NAME_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, OP_CODE_NAME_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 290);
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
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Total Bytes", renderer,
"text", TOT_BYTES_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, TOT_BYTES_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Avg Bytes", renderer,
"text", AVG_BYTES_COLUMN,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, float_data_func,
GINT_TO_POINTER(AVG_BYTES_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, AVG_BYTES_COLUMN);
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
ansi_map_stat_reset(
void *tapdata)
{
ansi_map_stat_t *stat_p = tapdata;
memset(stat_p, 0, sizeof(ansi_map_stat_t));
}
static gboolean
ansi_map_stat_packet(
void *tapdata,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *data)
{
ansi_map_stat_t *stat_p = tapdata;
const ansi_map_tap_rec_t *data_p = data;
#if 0
if (data_p->message_type >= ANSI_MAP_MAX_NUM_MESSAGE_TYPES)
{
return(FALSE);
}
#endif
stat_p->message_type[data_p->message_type]++;
stat_p->size[data_p->message_type] += data_p->size;
return(TRUE);
}
static void
ansi_map_stat_draw(
void *tapdata)
{
ansi_map_stat_t *stat_p = tapdata;
int i;
float avg;
GtkListStore *list_store;
GtkTreeIter iter;
if (dlg.win && tapdata)
{
i = 0;
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (dlg.table)));
while (ansi_map_opr_code_strings[i].strptr)
{
avg = 0.0f;
if (stat_p->message_type[ansi_map_opr_code_strings[i].value] !=0 ){
avg = (float)stat_p->size[ansi_map_opr_code_strings[i].value]/(float)stat_p->message_type[ansi_map_opr_code_strings[i].value];
}
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
OP_CODE_COLUMN, ansi_map_opr_code_strings[i].value,
OP_CODE_NAME_COLUMN, ansi_map_opr_code_strings[i].strptr,
COUNT_COLUMN, (guint)stat_p->message_type[ansi_map_opr_code_strings[i].value],
TOT_BYTES_COLUMN, (guint)stat_p->size[ansi_map_opr_code_strings[i].value],
AVG_BYTES_COLUMN, avg,
-1);
i++;
}
}
}
static void
ansi_map_stat_gtk_win_destroy_cb(
GtkWindow *win _U_,
gpointer user_data)
{
memset((void *) user_data, 0, sizeof(ansi_map_stat_dlg_t));
}
static void
ansi_map_stat_gtk_win_create(
ansi_map_stat_dlg_t *dlg_p,
const char *title)
{
GtkWidget *vbox;
GtkWidget *bt_close;
GtkWidget *bbox;
dlg_p->win= dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(dlg_p->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(dlg_p->win), 500, 450);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(dlg_p->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
dlg_p->scrolled_win = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(vbox), dlg_p->scrolled_win, TRUE, TRUE, 0);
dlg_p->table = create_list();
gtk_container_add(GTK_CONTAINER(dlg_p->scrolled_win), dlg_p->table);
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
bt_close = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(dlg_p->win, bt_close, window_cancel_button_cb);
g_signal_connect(dlg_p->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(dlg_p->win, "destroy", G_CALLBACK(ansi_map_stat_gtk_win_destroy_cb), dlg_p);
gtk_widget_show_all(dlg_p->win);
window_present(dlg_p->win);
}
void
ansi_map_stat_gtk_cb(GtkAction *action _U_, gpointer user_data _U_)
{
if (dlg.win){
gdk_window_raise(gtk_widget_get_window(dlg.win));
return;
}
ansi_map_stat_gtk_win_create(&dlg, "ANSI MAP Operation Statistics");
ansi_map_stat_draw(&ansi_a_stat);
}
static void
ansi_map_stat_gtk_init(
const char *optarg _U_,
void* userdata _U_ )
{
ansi_map_stat_gtk_cb(NULL, NULL);
}
void
register_tap_listener_gtkansi_map_stat(void)
{
GString *err_p;
memset((void *) &ansi_a_stat, 0, sizeof(ansi_map_stat_t));
err_p =
register_tap_listener("ansi_map", &ansi_a_stat, NULL, 0,
ansi_map_stat_reset,
ansi_map_stat_packet,
ansi_map_stat_draw);
if (err_p != NULL)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_p->str);
g_string_free(err_p, TRUE);
exit(1);
}
register_stat_cmd_arg("ansi_map", ansi_map_stat_gtk_init,NULL);
}
