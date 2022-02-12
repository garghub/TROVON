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
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_FLOAT,
G_TYPE_INT,
G_TYPE_INT,
G_TYPE_FLOAT,
G_TYPE_INT,
G_TYPE_FLOAT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
sortable = GTK_TREE_SORTABLE(list_store);
gtk_tree_view_set_fixed_height_mode(list_view, TRUE);
gtk_tree_sortable_set_sort_column_id(sortable, ID_COLUMN, GTK_SORT_ASCENDING);
gtk_tree_view_set_headers_clickable(list_view, FALSE);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ID", renderer,
"text", ID_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, ID_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 40);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Operation Code", renderer,
"text", OP_CODE_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, OP_CODE_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 210);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Invokes", renderer,
"text", INVOKES_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, INVOKES_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Num Bytes", renderer,
"text", NUM_BYTES_FWD_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, NUM_BYTES_FWD_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Avg Bytes", renderer,
"text", AVG_BYTES_FWD_COLUMN,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, float_data_func,
GINT_TO_POINTER(AVG_BYTES_FWD_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, AVG_BYTES_FWD_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("ReturnResult", renderer,
"text", RET_RES_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, RET_RES_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Num Bytes", renderer,
"text", NUM_BYTES_REV_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, NUM_BYTES_FWD_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Avg Bytes", renderer,
"text", AVG_BYTES_REV_COLUMN,
NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, float_data_func,
GINT_TO_POINTER(AVG_BYTES_REV_COLUMN), NULL);
gtk_tree_view_column_set_sort_column_id(column, AVG_BYTES_REV_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Total Bytes", renderer,
"text", TOT_BYTES_COLUMN,
NULL);
gtk_tree_view_column_set_sort_column_id(column, NUM_BYTES_FWD_COLUMN);
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
gtk_tree_view_column_set_min_width(column, 60);
gtk_tree_view_append_column (list_view, column);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(list_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(list_view), TRUE);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
return list;
}
static void
gsm_map_stat_reset(
void *tapdata)
{
gsm_map_stat_t *stat_p = tapdata;
memset(stat_p, 0, sizeof(gsm_map_stat_t));
}
static gboolean
gsm_map_stat_packet(
void *tapdata,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *data)
{
gsm_map_stat_t *stat_p = tapdata;
const gsm_map_tap_rec_t *data_p = data;
#if 0
if (data_p->opr_code_idx > sizeof(stat_p->opr_code))
{
return(FALSE);
}
#endif
if (data_p->invoke)
{
stat_p->opr_code[data_p->opr_code_idx]++;
stat_p->size[data_p->opr_code_idx] += data_p->size;
}
else
{
stat_p->opr_code_rr[data_p->opr_code_idx]++;
stat_p->size_rr[data_p->opr_code_idx] += data_p->size;
}
return(TRUE);
}
static void
gsm_map_stat_draw(
void *tapdata)
{
gsm_map_stat_t *stat_p = tapdata;
int i;
GtkListStore *list_store;
GtkTreeIter iter;
if (dlg.win && tapdata)
{
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (dlg.table)));
i = 0;
while (gsm_map_opr_code_strings[i].strptr){
float avrage_bytes_fwd;
float avrage_bytes_rev;
float avrage_bytes_tot;
if (stat_p->opr_code[i] >0){
avrage_bytes_fwd =(float)stat_p->size[i]/(float)stat_p->opr_code[i];
}else{
avrage_bytes_fwd = 0;
}
if (stat_p->opr_code_rr[i] >0){
avrage_bytes_rev = (float)stat_p->size_rr[i]/(float)stat_p->opr_code_rr[i];
}else{
avrage_bytes_rev = 0;
}
if ((stat_p->opr_code[i] + stat_p->opr_code_rr[i])>0){
avrage_bytes_tot = (float)(stat_p->size[i] +stat_p->size_rr[i])/(float)(stat_p->opr_code[i] + stat_p->opr_code_rr[i]);
}else{
avrage_bytes_tot = 0;
}
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
ID_COLUMN, gsm_map_opr_code_strings[i].value,
OP_CODE_COLUMN, (char*)gsm_map_opr_code_strings[i].strptr,
INVOKES_COLUMN, stat_p->opr_code[i],
NUM_BYTES_FWD_COLUMN, (gint)stat_p->size[i],
AVG_BYTES_FWD_COLUMN, avrage_bytes_fwd,
RET_RES_COLUMN, stat_p->opr_code_rr[i],
NUM_BYTES_REV_COLUMN, stat_p->size_rr[i],
AVG_BYTES_REV_COLUMN, avrage_bytes_rev,
TOT_BYTES_COLUMN, stat_p->size[i] + stat_p->size_rr[i],
AVG_BYTES_COLUMN, avrage_bytes_tot,
-1);
i++;
}
}
}
static void
gsm_map_stat_gtk_win_destroy_cb(
GtkWindow *win _U_,
gpointer user_data)
{
memset((void *) user_data, 0, sizeof(gsm_map_stat_dlg_t));
}
static void
gsm_map_stat_gtk_win_create(
gsm_map_stat_dlg_t *dlg_p,
const char *title)
{
GtkWidget *vbox;
GtkWidget *bt_close;
GtkWidget *bbox;
dlg_p->win = dlg_window_new(title);
gtk_window_set_destroy_with_parent (GTK_WINDOW(dlg_p->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(dlg_p->win), 560, 390);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
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
g_signal_connect(dlg_p->win, "destroy", G_CALLBACK(gsm_map_stat_gtk_win_destroy_cb), dlg_p);
gtk_widget_show_all(dlg_p->win);
window_present(dlg_p->win);
}
void
gsm_map_stat_gtk_cb(GtkAction *action _U_, gpointer user_data _U_)
{
if (dlg.win){
gdk_window_raise(gtk_widget_get_window(dlg.win));
return;
}
gsm_map_stat_gtk_win_create(&dlg, "GSM MAP Operation Statistics");
gsm_map_stat_draw(&gsm_map_stat);
}
static void
gsm_map_stat_gtk_init(const char *optarg _U_,
void* userdata _U_)
{
gsm_map_stat_gtk_cb(NULL, NULL);
}
void
register_tap_listener_gtkgsm_map_stat(void)
{
GString *err_p;
memset((void *) &gsm_map_stat, 0, sizeof(gsm_map_stat_t));
err_p =
register_tap_listener("gsm_map", &gsm_map_stat, NULL, 0,
gsm_map_stat_reset,
gsm_map_stat_packet,
gsm_map_stat_draw);
if (err_p != NULL)
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_p->str);
g_string_free(err_p, TRUE);
exit(1);
}
register_stat_cmd_arg("gsm_map", gsm_map_stat_gtk_init,NULL);
}
