static void
srt_select_filter_cb(GtkWidget *widget _U_, gpointer callback_data, guint callback_action)
{
srt_stat_table *rst = (srt_stat_table *)callback_data;
char *str = NULL;
GtkTreeIter iter;
GtkTreeModel *model;
GtkTreeSelection *sel;
int selection;
if(rst->filter_string==NULL){
return;
}
sel = gtk_tree_view_get_selection (GTK_TREE_VIEW(rst->table));
if (!gtk_tree_selection_get_selected(sel, &model, &iter))
return;
gtk_tree_model_get (model, &iter, INDEX_COLUMN, &selection, -1);
if(selection>=(int)rst->num_procs){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No procedure selected");
return;
}
str = g_strdup_printf("%s==%d", rst->filter_string, selection);
apply_selected_filter (callback_action, str);
g_free(str);
}
static gboolean
srt_show_popup_menu_cb(void *widg _U_, GdkEvent *event, srt_stat_table *rst)
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
srt_create_popup_menu(srt_stat_table *rst)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
action_group = gtk_action_group_new ("ServiceRespTFilterPopupActionGroup");
gtk_action_group_add_actions (action_group,
(GtkActionEntry *)service_resp_t__popup_entries,
G_N_ELEMENTS(service_resp_t__popup_entries),
rst);
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
rst->menu = gtk_ui_manager_get_widget(ui_manager, "/ServiceRespTFilterPopup");
g_signal_connect(rst->table, "button_press_event", G_CALLBACK(srt_show_popup_menu_cb), rst);
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
void
init_srt_table(srt_stat_table *rst, int num_procs, GtkWidget *vbox, const char *filter_string)
{
int i;
GtkListStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
GtkTreeSelection *sel;
const char *default_titles[] = { "Index", "Procedure", "Calls", "Min SRT", "Max SRT", "Avg SRT" };
store = gtk_list_store_new (N_COLUMNS,
G_TYPE_INT,
G_TYPE_STRING,
G_TYPE_UINT,
G_TYPE_POINTER,
G_TYPE_POINTER,
G_TYPE_UINT64);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
rst->table = GTK_TREE_VIEW(tree);
sortable = GTK_TREE_SORTABLE(store);
g_object_unref (G_OBJECT (store));
if(filter_string){
rst->filter_string=g_strdup(filter_string);
} else {
rst->filter_string=NULL;
}
for (i = 0; i < N_COLUMNS; i++) {
renderer = gtk_cell_renderer_text_new ();
if (i != PROCEDURE_COLUMN) {
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
}
g_object_set(renderer, "ypad", 0, NULL);
switch (i) {
case MIN_SRT_COLUMN:
case MAX_SRT_COLUMN:
column = gtk_tree_view_column_new_with_attributes (default_titles[i], renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, srt_time_func, GINT_TO_POINTER(i), NULL);
gtk_tree_sortable_set_sort_func(sortable, i, srt_time_sort_func, GINT_TO_POINTER(i), NULL);
break;
case AVG_SRT_COLUMN:
column = gtk_tree_view_column_new_with_attributes (default_titles[i], renderer, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, srt_avg_func, GINT_TO_POINTER(i), NULL);
break;
default:
column = gtk_tree_view_column_new_with_attributes (default_titles[i], renderer, "text",
i, NULL);
break;
}
gtk_tree_view_column_set_sort_column_id(column, i);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_append_column (rst->table, column);
if (i == CALLS_COLUMN) {
gtk_tree_view_column_clicked(column);
gtk_tree_view_column_clicked(column);
}
}
rst->scrolled_window=scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(rst->scrolled_window),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(rst->scrolled_window), GTK_WIDGET (rst->table));
gtk_box_pack_start(GTK_BOX(vbox), rst->scrolled_window, TRUE, TRUE, 0);
gtk_tree_view_set_reorderable (rst->table, FALSE);
gtk_tree_view_set_rules_hint(rst->table, TRUE);
gtk_tree_view_set_headers_clickable(rst->table, TRUE);
gtk_widget_show(rst->scrolled_window);
rst->num_procs=num_procs;
rst->procedures=(srt_procedure_t *)g_malloc(sizeof(srt_procedure_t)*num_procs);
for(i=0;i<num_procs;i++){
time_stat_init(&rst->procedures[i].stats);
rst->procedures[i].index = 0;
rst->procedures[i].procedure = NULL;
}
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(rst->table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
if(rst->filter_string){
srt_create_popup_menu(rst);
}
}
void
init_srt_table_row(srt_stat_table *rst, int indx, const char *procedure)
{
if(indx>=rst->num_procs){
int old_num_procs=rst->num_procs;
int i;
rst->num_procs=indx+1;
rst->procedures=(srt_procedure_t *)g_realloc(rst->procedures, sizeof(srt_procedure_t)*(rst->num_procs));
for(i=old_num_procs;i<rst->num_procs;i++){
time_stat_init(&rst->procedures[i].stats);
rst->procedures[i].index = i;
rst->procedures[i].procedure=NULL;
}
}
rst->procedures[indx].index = indx;
rst->procedures[indx].procedure=g_strdup(procedure);
}
void
add_srt_table_data(srt_stat_table *rst, int indx, const nstime_t *req_time, packet_info *pinfo)
{
srt_procedure_t *rp;
nstime_t t, delta;
g_assert(indx >= 0 && indx < rst->num_procs);
rp=&rst->procedures[indx];
if (rp->stats.num==0){
GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(rst->table));
gtk_list_store_append(store, &rp->iter);
gtk_list_store_set(store, &rp->iter,
INDEX_COLUMN, rp->index,
PROCEDURE_COLUMN, rp->procedure,
CALLS_COLUMN, rp->stats.num,
MIN_SRT_COLUMN, NULL,
MAX_SRT_COLUMN, NULL,
AVG_SRT_COLUMN, (guint64)0,
-1);
}
t=pinfo->fd->abs_ts;
nstime_delta(&delta, &t, req_time);
time_stat_update(&rp->stats, &delta, pinfo);
}
void
draw_srt_table_data(srt_stat_table *rst)
{
int i;
guint64 td;
GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(rst->table));
for(i=0;i<rst->num_procs;i++){
if(rst->procedures[i].stats.num==0){
continue;
}
td = ((guint64)(rst->procedures[i].stats.tot.secs))*NANOSECS_PER_SEC + rst->procedures[i].stats.tot.nsecs;
td = ((td / rst->procedures[i].stats.num) + 500) / 1000;
gtk_list_store_set(store, &rst->procedures[i].iter,
CALLS_COLUMN, rst->procedures[i].stats.num,
MIN_SRT_COLUMN, &rst->procedures[i].stats.min,
MAX_SRT_COLUMN, &rst->procedures[i].stats.max,
AVG_SRT_COLUMN, td,
-1);
}
}
void
reset_srt_table_data(srt_stat_table *rst)
{
int i;
GtkListStore *store;
for(i=0;i<rst->num_procs;i++){
time_stat_init(&rst->procedures[i].stats);
}
store = GTK_LIST_STORE(gtk_tree_view_get_model(rst->table));
gtk_list_store_clear(store);
}
void
free_srt_table_data(srt_stat_table *rst)
{
int i;
for(i=0;i<rst->num_procs;i++){
g_free(rst->procedures[i].procedure);
rst->procedures[i].procedure=NULL;
}
g_free(rst->filter_string);
rst->filter_string=NULL;
g_free(rst->procedures);
rst->procedures=NULL;
rst->num_procs=0;
}
