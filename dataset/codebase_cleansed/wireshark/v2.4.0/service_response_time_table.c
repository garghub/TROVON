static void
srt_select_filter_cb(GtkWidget *widget _U_, gpointer callback_data, guint callback_action)
{
gtk_srt_table_t *rst_table = (gtk_srt_table_t*)callback_data;
srt_stat_table* rst = rst_table->rst;
char *str = NULL;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
int selection;
if(rst->filter_string==NULL){
return;
}
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(rst_table->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get (model, &iter, SRT_COLUMN_INDEX, &selection, -1);
if(selection>=(int)rst->num_procs){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No procedure selected");
return;
}
str = g_strdup_printf("%s==%d", rst->filter_string, selection);
apply_selected_filter (callback_action, str);
g_free(str);
}
static gboolean
srt_show_popup_menu_cb(void *widg _U_, GdkEvent *event, gtk_srt_table_t *rst)
{
GdkEventButton *bevent = (GdkEventButton *)event;
if(event->type==GDK_BUTTON_PRESS && bevent->button==3){
gtk_menu_popup(GTK_MENU(rst->menu), NULL, NULL, NULL, NULL,
bevent->button, bevent->time);
}
return FALSE;
}
static void
apply_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_SELECTED, 0));
}
static void
apply_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, 0));
}
static void
apply_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, 0));
}
static void
apply_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, 0));
}
static void
apply_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
apply_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
prep_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, 0));
}
static void
prep_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, 0));
}
static void
prep_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, 0));
}
static void
prep_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, 0));
}
static void
prep_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
prep_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
find_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, 0));
}
static void
find_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_NOT_SELECTED, 0));
}
static void
find_prev_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_SELECTED, 0));
}
static void
find_prev_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_NOT_SELECTED, 0));
}
static void
find_next_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_SELECTED, 0));
}
static void
find_next_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, 0));
}
static void
color_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, 0));
}
static void
color_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
srt_select_filter_cb( widget , user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, 0));
}
static void
srt_create_popup_menu(gtk_srt_table_t* rst_table)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
action_group = gtk_action_group_new ("ServiceRespTFilterPopupActionGroup");
gtk_action_group_add_actions (action_group,
(GtkActionEntry *)service_resp_t__popup_entries,
G_N_ELEMENTS(service_resp_t__popup_entries),
rst_table);
ui_manager = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager,
action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager,ui_desc_service_resp_t_filter_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building service response time filter popup failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
rst_table->menu = gtk_ui_manager_get_widget(ui_manager, "/ServiceRespTFilterPopup");
g_signal_connect(rst_table->table, "button_press_event", G_CALLBACK(srt_show_popup_menu_cb), rst_table);
}
static void
srt_time_func (GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
gchar *str;
nstime_t *data;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, data_column, &data, -1);
if (!data) {
g_object_set(renderer, "text", "", NULL);
return;
}
str = g_strdup_printf("%3d.%06d", (int)data->secs, (data->nsecs+500)/1000);
g_object_set(renderer, "text", str, NULL);
g_free(str);
}
static void
srt_avg_func (GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
gchar *str;
guint64 td;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, data_column, &td, -1);
str=g_strdup_printf("%3d.%06d",
(int)(td/1000000), (int)(td%1000000));
g_object_set(renderer, "text", str, NULL);
g_free(str);
}
static gint
srt_time_sort_func(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
nstime_t *ns_a;
nstime_t *ns_b;
gint ret = 0;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, a, data_column, &ns_a, -1);
gtk_tree_model_get(model, b, data_column, &ns_b, -1);
if (ns_a == ns_b) {
ret = 0;
}
else if (ns_a == NULL || ns_b == NULL) {
ret = (ns_a == NULL) ? -1 : 1;
}
else {
ret = nstime_cmp(ns_a,ns_b);
}
return ret;
}
static void
srt_set_title(srt_t *ss)
{
gchar *str;
str = g_strdup_printf("%s Service Response Time statistics", proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(ss->srt))));
set_window_title(ss->gtk_data.win, str);
g_free(str);
}
static gtk_srt_table_t*
get_gtk_table_from_srt(srt_stat_table* rst, gtk_srt_t* gtk)
{
guint i;
gtk_srt_table_t* srt;
for (i = 0; i < gtk->gtk_srt_array->len; i++) {
srt = g_array_index(gtk->gtk_srt_array, gtk_srt_table_t*, i);
if (srt->rst == rst)
return srt;
}
return NULL;
}
void
free_table_data(srt_stat_table* rst, void* gui_data)
{
gtk_srt_t* gtk_data = (gtk_srt_t*)gui_data;
gtk_srt_table_t* gtk_table = get_gtk_table_from_srt(rst, gtk_data);
g_assert(gtk_table);
g_free(gtk_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
srt_t *ss=(srt_t *)data;
remove_tap_listener(&ss->data);
free_srt_table(ss->srt, ss->data.srt_array, free_table_data, &ss->gtk_data);
g_free(ss);
}
void
init_gtk_srt_table(srt_stat_table* rst, void* gui_data)
{
int i;
GtkListStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkWidget *label;
GtkWidget *tab_page;
gtk_srt_t *ss = (gtk_srt_t*)gui_data;
GtkWidget *parent_box = ss->vbox;
GtkTreeSelection *sel;
gtk_srt_table_t *gtk_table_data = g_new0(gtk_srt_table_t, 1);
gtk_table_data->rst = rst;
g_array_insert_val(ss->gtk_srt_array, ss->gtk_srt_array->len, gtk_table_data);
label=gtk_label_new(rst->name);
if (ss->main_nb == NULL)
{
gtk_box_pack_start(GTK_BOX(ss->vbox), label, FALSE, FALSE, 0);
}
else
{
GtkWidget *tab_label=gtk_label_new(rst->short_name);
tab_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_notebook_append_page(GTK_NOTEBOOK(ss->main_nb), tab_page, tab_label);
gtk_box_pack_start(GTK_BOX(tab_page), label, FALSE, FALSE, 0);
parent_box = tab_page;
}
store = gtk_list_store_new (NUM_SRT_COLUMNS,
G_TYPE_INT,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_POINTER,
G_TYPE_POINTER,
G_TYPE_UINT64,
G_TYPE_UINT64);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
gtk_table_data->table = GTK_TREE_VIEW(tree);
sortable = GTK_TREE_SORTABLE(store);
g_object_unref (G_OBJECT (store));
for (i = 0; i < NUM_SRT_COLUMNS; i++) {
renderer = gtk_cell_renderer_text_new ();
if (i != SRT_COLUMN_PROCEDURE) {
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
}
g_object_set(renderer, "ypad", 0, NULL);
switch (i) {
case SRT_COLUMN_MIN:
case SRT_COLUMN_MAX:
column = gtk_tree_view_column_new_with_attributes (service_response_time_get_column_name(i), renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, srt_time_func, GINT_TO_POINTER(i), NULL);
gtk_tree_sortable_set_sort_func(sortable, i, srt_time_sort_func, GINT_TO_POINTER(i), NULL);
break;
case SRT_COLUMN_AVG:
case SRT_COLUMN_SUM:
column = gtk_tree_view_column_new_with_attributes (service_response_time_get_column_name(i), renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, srt_avg_func, GINT_TO_POINTER(i), NULL);
break;
case PROCEDURE_COLUMN:
column = gtk_tree_view_column_new_with_attributes ((rst->proc_column_name != NULL) ? rst->proc_column_name : service_response_time_get_column_name(i), renderer, "text",
i, NULL);
break;
default:
column = gtk_tree_view_column_new_with_attributes (service_response_time_get_column_name(i), renderer, "text", i, NULL);
break;
}
gtk_tree_view_column_set_sort_column_id(column, i);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_append_column (gtk_table_data->table, column);
if (i == SRT_COLUMN_CALLS) {
gtk_tree_view_column_clicked(column);
gtk_tree_view_column_clicked(column);
}
}
gtk_table_data->scrolled_window=scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(gtk_table_data->scrolled_window),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(gtk_table_data->scrolled_window), GTK_WIDGET (gtk_table_data->table));
gtk_box_pack_start(GTK_BOX(parent_box), gtk_table_data->scrolled_window, TRUE, TRUE, 0);
gtk_tree_view_set_reorderable (gtk_table_data->table, FALSE);
gtk_tree_view_set_rules_hint(gtk_table_data->table, TRUE);
gtk_tree_view_set_headers_clickable(gtk_table_data->table, TRUE);
gtk_widget_show(gtk_table_data->scrolled_window);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(gtk_table_data->table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
if(rst->filter_string){
srt_create_popup_menu(gtk_table_data);
}
}
void
draw_srt_table_data(srt_stat_table *rst, gtk_srt_t* gtk_data)
{
int idx, new_idx;
GtkTreeIter iter;
gboolean first = TRUE;
gtk_srt_table_t* gtk_table;
GtkListStore *store;
gboolean iter_valid;
gtk_table = get_gtk_table_from_srt(rst, gtk_data);
g_assert(gtk_table);
store = GTK_LIST_STORE(gtk_tree_view_get_model(gtk_table->table));
iter_valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter);
new_idx = gtk_tree_model_iter_n_children(GTK_TREE_MODEL(store), NULL);
while (iter_valid || (new_idx < rst->num_procs)) {
srt_procedure_t* procedure;
guint64 td;
guint64 sum;
if (iter_valid) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, INDEX_COLUMN, &idx, -1);
} else {
idx = new_idx;
new_idx++;
}
procedure = &rst->procedures[idx];
if ((procedure->procedure == NULL) || (procedure->stats.num == 0)) {
iter_valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
continue;
}
if (first) {
g_object_ref(store);
gtk_tree_view_set_model(GTK_TREE_VIEW(gtk_table->table), NULL);
first = FALSE;
}
td = ((guint64)(procedure->stats.tot.secs))*NANOSECS_PER_SEC + procedure->stats.tot.nsecs;
sum = (td + 500) / 1000;
td = ((td / procedure->stats.num) + 500) / 1000;
if (iter_valid) {
gtk_list_store_set(store, &iter,
PROCEDURE_COLUMN, procedure->procedure,
CALLS_COLUMN, procedure->stats.num,
MIN_SRT_COLUMN, &procedure->stats.min,
MAX_SRT_COLUMN, &procedure->stats.max,
AVG_SRT_COLUMN, td,
SUM_SRT_COLUMN, sum,
-1);
} else {
gtk_list_store_insert_with_values(store, &iter, G_MAXINT,
PROCEDURE_COLUMN, procedure->procedure,
CALLS_COLUMN, procedure->stats.num,
MIN_SRT_COLUMN, &procedure->stats.min,
MAX_SRT_COLUMN, &procedure->stats.max,
AVG_SRT_COLUMN, td,
SUM_SRT_COLUMN, sum,
INDEX_COLUMN, idx,
-1);
}
iter_valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
}
if (!first) {
gtk_tree_view_set_model(GTK_TREE_VIEW(gtk_table->table), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
static void
srt_draw(void *arg)
{
guint i = 0;
srt_stat_table *srt_table;
srt_data_t *srt = (srt_data_t*)arg;
srt_t *ss = (srt_t*)srt->user_data;
for (i = 0; i < srt->srt_array->len; i++)
{
srt_table = g_array_index(srt->srt_array, srt_stat_table*, i);
draw_srt_table_data(srt_table, &ss->gtk_data);
}
}
void
reset_table_data(srt_stat_table* rst, void* gui_data)
{
GtkListStore *store;
gtk_srt_t* gtk_data = (gtk_srt_t*)gui_data;
gtk_srt_table_t* gtk_table = get_gtk_table_from_srt(rst, gtk_data);
g_assert(gtk_table);
store = GTK_LIST_STORE(gtk_tree_view_get_model(gtk_table->table));
gtk_list_store_clear(store);
}
static void
srt_reset(void *arg)
{
srt_data_t *srt = (srt_data_t*)arg;
srt_t *ss = (srt_t *)srt->user_data;
reset_srt_table(ss->data.srt_array, reset_table_data, &ss->gtk_data);
srt_set_title(ss);
}
static void
init_srt_tables(register_srt_t* srt, const char *filter)
{
srt_t *ss;
gchar *str;
GtkWidget *label;
char *filter_string, *tmp_filter_string;
GString *error_string;
GtkWidget *bbox;
GtkWidget *close_bt;
ss = g_new0(srt_t, 1);
str = g_strdup_printf("%s-stat", proto_get_protocol_filter_name(get_srt_proto_id(srt)));
ss->gtk_data.win=dlg_window_new(str);
g_free(str);
gtk_window_set_destroy_with_parent (GTK_WINDOW(ss->gtk_data.win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(ss->gtk_data.win), SRT_PREFERRED_WIDTH, 600);
str = g_strdup_printf("%s Service Response Time Statistics", proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(srt))));
set_window_title(ss->gtk_data.win, str);
ss->gtk_data.vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(ss->gtk_data.win), ss->gtk_data.vbox);
gtk_container_set_border_width(GTK_CONTAINER(ss->gtk_data.vbox), 12);
label=gtk_label_new(str);
gtk_box_pack_start(GTK_BOX(ss->gtk_data.vbox), label, FALSE, FALSE, 0);
g_free(str);
if ((filter != NULL) && (strlen(filter) > MAX_FILTER_STRING_LENGTH))
{
tmp_filter_string = g_strndup(filter, MAX_FILTER_STRING_LENGTH);
filter_string = g_strdup_printf("Filter: %s...", tmp_filter_string);
g_free(tmp_filter_string);
}
else
{
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
}
label=gtk_label_new(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_widget_set_tooltip_text (label, filter ? filter : "");
g_free(filter_string);
gtk_box_pack_start(GTK_BOX(ss->gtk_data.vbox), label, FALSE, FALSE, 0);
if (get_srt_max_tables(srt) > 3)
{
ss->gtk_data.main_nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(ss->gtk_data.vbox), ss->gtk_data.main_nb, TRUE, TRUE, 0);
}
gtk_widget_show_all(ss->gtk_data.win);
ss->type = proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(srt)));
ss->filter = g_strdup(filter);
ss->srt = srt;
ss->gtk_data.gtk_srt_array = g_array_new(FALSE, TRUE, sizeof(gtk_srt_table_t*));
ss->data.srt_array = g_array_new(FALSE, TRUE, sizeof(srt_stat_table*));
ss->data.user_data = ss;
srt_table_dissector_init(srt, ss->data.srt_array, init_gtk_srt_table, &ss->gtk_data);
error_string = register_tap_listener(get_srt_tap_listener_name(srt), &ss->data, filter, 0, srt_reset, get_srt_packet_func(srt), srt_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
free_srt_table(ss->srt, ss->data.srt_array, NULL, NULL);
g_free(ss);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(ss->gtk_data.vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(ss->gtk_data.win, close_bt, window_cancel_button_cb);
g_signal_connect(ss->gtk_data.win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(ss->gtk_data.win, "destroy", G_CALLBACK(win_destroy_cb), ss);
gtk_widget_show_all(ss->gtk_data.win);
window_present(ss->gtk_data.win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(ss->gtk_data.win));
}
static void
gtk_srtstat_init(const char *opt_arg, void *userdata _U_)
{
gchar** dissector_name;
register_srt_t *srt;
const char *filter=NULL;
char* err;
dissector_name = g_strsplit(opt_arg, ",", -1);
g_assert(dissector_name[0]);
srt = get_srt_table_by_name(dissector_name[0]);
g_assert(srt);
srt_table_get_filter(srt, opt_arg, &filter, &err);
if (err != NULL)
{
gchar* cmd_str = srt_table_get_tap_string(srt);
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "invalid \"-z %s,%s\" argument", cmd_str, err);
g_free(cmd_str);
g_free(err);
return;
}
init_srt_tables(srt, filter);
}
gboolean register_service_response_tables(const void *key _U_, void *value, void *userdata _U_)
{
register_srt_t *srt = (register_srt_t*)value;
const char* short_name = proto_get_protocol_short_name(find_protocol_by_id(get_srt_proto_id(srt)));
tap_param_dlg* srt_dlg;
if ((strcmp(short_name, "RPC") == 0) ||
(strcmp(short_name, "DCERPC") == 0))
return FALSE;
srt_dlg = g_new(tap_param_dlg, 1);
srt_dlg->win_title = g_strdup_printf("%s SRT Statistics", short_name);
srt_dlg->init_string = srt_table_get_tap_string(srt);
srt_dlg->tap_init_cb = gtk_srtstat_init;
srt_dlg->index = -1;
srt_dlg->user_data = srt;
if (get_srt_proto_id(srt) == proto_get_id_by_filter_name("scsi"))
{
srt_dlg->nparams = G_N_ELEMENTS(scsi_stat_params);
srt_dlg->params = scsi_stat_params;
}
else
{
srt_dlg->nparams = G_N_ELEMENTS(srt_stat_params);
srt_dlg->params = srt_stat_params;
}
register_param_stat(srt_dlg, short_name, REGISTER_STAT_GROUP_RESPONSE_TIME);
return FALSE;
}
