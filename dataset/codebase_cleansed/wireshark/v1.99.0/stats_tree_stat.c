static void
draw_gtk_node(stat_node* node)
{
GtkTreeIter* parent = NULL;
stat_node* child;
int num_columns= node->st->num_columns+N_RESERVED_COL;
gint *columns = (gint*) g_malloc(sizeof(gint)*num_columns);
GValue *values = (GValue*) g_malloc0(sizeof(GValue)*num_columns);
gchar **valstrs = stats_tree_get_values_from_node(node);
int count;
columns[0]= 0;
g_value_init(values, G_TYPE_POINTER);
g_value_set_pointer(values, node);
for (count = N_RESERVED_COL; count<num_columns; count++) {
columns[count]= count;
g_value_init(values+count, G_TYPE_STRING);
g_value_take_string (values+count,valstrs[count-N_RESERVED_COL]);
}
if (!node->pr) {
node->pr = (st_node_pres *)g_malloc(sizeof(st_node_pres));
if (node->st->pr->store) {
node->pr->iter = (GtkTreeIter *)g_malloc0(sizeof(GtkTreeIter));
if ( node->parent && node->parent->pr ) {
parent = node->parent->pr->iter;
}
gtk_tree_store_append (node->st->pr->store, node->pr->iter, parent);
gtk_tree_store_set_valuesv(node->st->pr->store, node->pr->iter,
columns, values, num_columns);
}
}
if (node->st->pr->store && node->pr->iter) {
gtk_tree_store_set_valuesv(node->st->pr->store, node->pr->iter,
columns+N_RESERVED_COL+1, values+N_RESERVED_COL+1,
num_columns-N_RESERVED_COL-1);
}
for (count = 0; count<num_columns; count++) {
g_value_unset(values+count);
}
g_free(columns);
g_free(values);
g_free(valstrs);
if (node->children) {
for (child = node->children; child; child = child->next )
draw_gtk_node(child);
}
}
static void
draw_gtk_tree(void *psp)
{
stats_tree *st = (stats_tree *)psp;
stat_node* child;
int count;
gint sort_column= GTK_TREE_SORTABLE_DEFAULT_SORT_COLUMN_ID;
GtkSortType order= GTK_SORT_DESCENDING;
for (count = 0; count<st->num_columns; count++) {
gtk_tree_view_column_set_title(gtk_tree_view_get_column(GTK_TREE_VIEW(st->pr->tree),count),
stats_tree_get_column_name(count));
}
gtk_tree_sortable_get_sort_column_id (GTK_TREE_SORTABLE (st->pr->store), &sort_column, &order);
gtk_tree_sortable_set_sort_column_id (GTK_TREE_SORTABLE (st->pr->store),
GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID, GTK_SORT_DESCENDING);
for (child = st->root.children; child; child = child->next ) {
draw_gtk_node(child);
if ( (!(child->st_flags&ST_FLG_DEF_NOEXPAND)) && child->pr->iter && st->pr->store ) {
gtk_tree_view_expand_row(GTK_TREE_VIEW(st->pr->tree),
gtk_tree_model_get_path(GTK_TREE_MODEL(st->pr->store),child->pr->iter),
FALSE);
}
}
if ((sort_column==GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID)||
(sort_column==GTK_TREE_SORTABLE_DEFAULT_SORT_COLUMN_ID)) {
sort_column= stats_tree_get_default_sort_col(st)+N_RESERVED_COL;
order= stats_tree_is_default_sort_DESC(st)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
}
gtk_tree_sortable_set_sort_column_id (GTK_TREE_SORTABLE (st->pr->store), sort_column, order);
}
static gboolean
copy_tree_to_clipboard
(GtkWidget *win _U_, stats_tree *st)
{
gint sort_column= N_RESERVED_COL;
GtkSortType order= GTK_SORT_DESCENDING;
GString *s;
gtk_tree_sortable_get_sort_column_id (GTK_TREE_SORTABLE (st->pr->store), &sort_column, &order);
s= stats_tree_format_as_str(st,ST_FORMAT_PLAIN,sort_column-N_RESERVED_COL,order==GTK_SORT_DESCENDING);
copy_to_clipboard(s);
g_string_free (s,TRUE);
return TRUE;
}
static gboolean
gtk_save_as_statstree(GtkWidget *win, GString *file_name, int *file_type)
{
GtkWidget *saveas_w;
GtkWidget *main_vb;
GtkWidget *ft_hb, *ft_lb, *ft_combo_box;
char *st_name;
gpointer ptr;
saveas_w = file_selection_new("Wireshark: Save stats tree as ...",
GTK_WINDOW(win), FILE_SELECTION_SAVE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
file_selection_set_extra_widget(saveas_w, main_vb);
gtk_widget_show(main_vb);
ft_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), ft_hb, FALSE, FALSE, 0);
gtk_widget_show(ft_hb);
ft_lb = gtk_label_new("Save as format:");
gtk_box_pack_start(GTK_BOX(ft_hb), ft_lb, FALSE, FALSE, 0);
gtk_widget_show(ft_lb);
ft_combo_box = ws_combo_box_new_text_and_pointer();
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(ft_combo_box), "Plain text file (.txt)", GINT_TO_POINTER(ST_FORMAT_PLAIN));
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(ft_combo_box), "Comma separated values (.csv)", GINT_TO_POINTER(ST_FORMAT_CSV));
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(ft_combo_box), "XML document (.xml)", GINT_TO_POINTER(ST_FORMAT_XML));
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(ft_combo_box), "YAML document (.yaml)", GINT_TO_POINTER(ST_FORMAT_YAML));
gtk_box_pack_start(GTK_BOX(ft_hb), ft_combo_box, FALSE, FALSE, 0);
gtk_widget_show(ft_combo_box);
ws_combo_box_set_active(GTK_COMBO_BOX(ft_combo_box), 0);
st_name = file_selection_run(saveas_w);
if (st_name == NULL) {
return FALSE;
}
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(ft_combo_box), &ptr)) {
g_assert_not_reached();
}
*file_type = GPOINTER_TO_INT(ptr);
g_string_printf(file_name, "%s", st_name);
window_destroy(GTK_WIDGET(saveas_w));
g_free(st_name);
return TRUE;
}
static void
free_gtk_tree(GtkWindow *win _U_, stats_tree *st)
{
remove_tap_listener(st);
if (st->root.pr)
st->root.pr->iter = NULL;
st->cfg->in_use = FALSE;
stats_tree_free(st);
}
static void
clear_node_pr(stat_node* n)
{
stat_node* c;
for (c = n->children; c; c = c->next) {
clear_node_pr(c);
}
if (n->pr->iter) {
gtk_tree_store_remove(n->st->pr->store, n->pr->iter);
n->pr->iter = NULL;
}
}
static void
reset_tap(void* p)
{
stats_tree* st = (stats_tree *)p;
stat_node* c;
for (c = st->root.children; c; c = c->next) {
clear_node_pr(c);
}
stats_tree_reinit(st);
}
static gint
st_sort_func(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
gint sort_column= 1;
GtkSortType order= GTK_SORT_DESCENDING;
stat_node *node_a;
stat_node *node_b;
gint result;
gtk_tree_sortable_get_sort_column_id (GTK_TREE_SORTABLE (user_data), &sort_column, &order);
gtk_tree_model_get(model, a, NODEPTR_COLUMN, &node_a, -1);
gtk_tree_model_get(model, b, NODEPTR_COLUMN, &node_b, -1);
result= stats_tree_sort_compare(node_a,node_b,sort_column-N_RESERVED_COL,order==GTK_SORT_DESCENDING);
if (order==GTK_SORT_DESCENDING) {
result= -result;
}
return result;
}
static void
init_gtk_tree(const char* opt_arg, void *userdata _U_)
{
gchar *abbr = stats_tree_get_abbr(opt_arg);
stats_tree* st = NULL;
stats_tree_cfg* cfg = NULL;
tree_pres* pr = (tree_pres *)g_malloc(sizeof(tree_pres));
gchar* title = NULL;
gchar* window_name = NULL;
GString* error_string;
GtkWidget *scr_win;
size_t init_strlen;
GtkWidget *main_vb, *bbox, *bt_close, *bt_copy, *bt_saveas;
GtkTreeViewColumn* column;
GtkCellRenderer* renderer;
GtkTreeSortable *sortable;
GType *col_types;
int count;
if (abbr) {
cfg = stats_tree_get_cfg_by_abbr(abbr);
if (cfg && cfg->in_use) {
report_failure("cannot open more than one tree of the same type at once");
return;
}
if (cfg != NULL) {
init_strlen = strlen(cfg->pr->stat_dlg->init_string);
if (strncmp (opt_arg, cfg->pr->stat_dlg->init_string, init_strlen) == 0){
if (init_strlen == strlen(opt_arg)) {
st = stats_tree_new(cfg,pr,NULL);
} else {
st = stats_tree_new(cfg,pr,opt_arg+init_strlen+1);
}
} else {
st = stats_tree_new(cfg,pr,NULL);
}
} else {
report_failure("no such stats_tree (%s) in stats_tree registry",abbr);
g_free(abbr);
return;
}
g_free(abbr);
} else {
report_failure("could not obtain stats_tree abbr from opt_arg");
g_free(pr);
return;
}
cfg->in_use = TRUE;
window_name = g_strdup_printf("%s Stats Tree", st->display_name);
st->pr->win = window_new_with_geom(GTK_WINDOW_TOPLEVEL, window_name, NULL, GTK_WIN_POS_CENTER_ON_PARENT);
gtk_window_set_default_size(GTK_WINDOW(st->pr->win), st->num_columns*80+80, 400);
g_free(window_name);
if(st->filter){
title=g_strdup_printf("%s with filter: %s",st->display_name,st->filter);
} else {
st->filter=NULL;
title=g_strdup_printf("%s", st->display_name);
}
gtk_window_set_title(GTK_WINDOW(st->pr->win), title);
g_free(title);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
gtk_container_add(GTK_CONTAINER(st->pr->win), main_vb);
scr_win = scrolled_window_new(NULL, NULL);
col_types= (GType*)g_malloc(sizeof(GType)*(st->num_columns+N_RESERVED_COL));
col_types[0] = G_TYPE_POINTER;
for (count = 0; count<st->num_columns; count++) {
col_types[count+N_RESERVED_COL] = G_TYPE_STRING;
}
st->pr->store = gtk_tree_store_newv (st->num_columns+N_RESERVED_COL,col_types);
g_free (col_types);
sortable= GTK_TREE_SORTABLE (st->pr->store);
st->pr->tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (st->pr->store));
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(st->pr->tree), FALSE);
g_object_unref(G_OBJECT(st->pr->store));
gtk_container_add( GTK_CONTAINER(scr_win), st->pr->tree);
for (count = 0; count<st->num_columns; count++) {
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes (stats_tree_get_column_name(count),
renderer, "text", count+N_RESERVED_COL, NULL);
gtk_tree_view_column_set_sort_column_id(column, count+N_RESERVED_COL);
gtk_tree_sortable_set_sort_func(sortable,count+N_RESERVED_COL, st_sort_func, sortable, NULL);
gtk_tree_view_column_set_resizable (column,TRUE);
gtk_tree_view_column_set_sizing(column,GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_append_column (GTK_TREE_VIEW (st->pr->tree), column);
}
gtk_tree_sortable_set_default_sort_func (sortable, NULL, NULL, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), scr_win, TRUE, TRUE, 0);
error_string = register_tap_listener( cfg->tapname,
st,
st->filter,
cfg->flags,
reset_tap,
stats_tree_packet,
draw_gtk_tree);
if (error_string) {
report_failure("stats_tree for: %s failed to attach to the tap: %s",cfg->name,error_string->str);
g_string_free(error_string, TRUE);
}
bbox = dlg_button_row_new(GTK_STOCK_COPY, GTK_STOCK_SAVE_AS, GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
bt_close = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(st->pr->win, bt_close, window_cancel_button_cb);
g_signal_connect(GTK_WINDOW(st->pr->win), "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(GTK_WINDOW(st->pr->win), "destroy", G_CALLBACK(free_gtk_tree), st);
bt_copy = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_COPY);
g_signal_connect(GTK_WINDOW (bt_copy), "clicked", G_CALLBACK(copy_tree_to_clipboard), st);
bt_saveas = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE_AS);
g_signal_connect(GTK_WINDOW (bt_saveas), "clicked", G_CALLBACK(save_as_dialog), st);
gtk_widget_show_all(st->pr->win);
window_present(st->pr->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(st->pr->win));
}
static void
register_gtk_stats_tree_tap (gpointer k _U_, gpointer v, gpointer p _U_)
{
stats_tree_cfg* cfg = (stats_tree_cfg *)v;
gchar* display_name= stats_tree_get_displayname(cfg->name);
cfg->pr = (tree_cfg_pres *)g_malloc(sizeof(tree_cfg_pres));
cfg->pr->stat_dlg = (tap_param_dlg *)g_malloc(sizeof(tap_param_dlg));
cfg->pr->stat_dlg->win_title = g_strdup_printf("%s Stats Tree",display_name);
cfg->pr->stat_dlg->init_string = g_strdup_printf("%s,tree",cfg->abbr);
cfg->pr->stat_dlg->tap_init_cb = init_gtk_tree;
cfg->pr->stat_dlg->index = -1;
cfg->pr->stat_dlg->nparams = G_N_ELEMENTS(tree_stat_params);
cfg->pr->stat_dlg->params = tree_stat_params;
g_free(display_name);
}
static void
free_tree_presentation(stats_tree* st)
{
g_free(st->pr);
}
void
register_tap_listener_stats_tree_stat(void)
{
stats_tree_presentation(register_gtk_stats_tree_tap,
NULL,
NULL,
NULL,
NULL,
NULL,
free_tree_presentation,
NULL,
NULL,
NULL);
}
void gtk_stats_tree_cb(GtkAction *action, gpointer user_data _U_)
{
const gchar *action_name;
gchar *abbr;
stats_tree_cfg* cfg = NULL;
action_name = gtk_action_get_name (action);
abbr = strrchr(action_name,'/');
if(abbr){
abbr = abbr+1;
}else{
abbr = g_strdup_printf("%s",action_name);
}
cfg = stats_tree_get_cfg_by_abbr(abbr);
if(cfg){
tap_param_dlg_cb(action, cfg->pr->stat_dlg);
}else{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Failed to find the stat tree named %s",
abbr);
return;
}
}
