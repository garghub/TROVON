static void
proto_data_func (GtkTreeViewColumn *column _U_,
GtkCellRenderer *renderer,
GtkTreeModel *model,
GtkTreeIter *iter,
gpointer user_data)
{
gchar *str = NULL;
gchar *grp = NULL;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, iter, data_column, &str, -1);
gtk_tree_model_get(model, iter, GROUP_COLUMN, &grp, -1);
g_object_set(renderer, "text", str, NULL);
if (grp == packet) {
g_object_set(renderer, "xalign", 1.0, NULL);
}
else {
g_object_set(renderer, "xalign", 0.0, NULL);
}
g_free(str);
}
static gint
proto_sort_func(GtkTreeModel *model,
GtkTreeIter *a,
GtkTreeIter *b,
gpointer user_data)
{
gchar *str_a = NULL;
gchar *str_b = NULL;
gchar *grp = NULL;
gint ret = 0;
gint data_column = GPOINTER_TO_INT(user_data);
gtk_tree_model_get(model, a, data_column, &str_a, -1);
gtk_tree_model_get(model, b, data_column, &str_b, -1);
gtk_tree_model_get(model, a, GROUP_COLUMN, &grp, -1);
if (str_a == str_b) {
ret = 0;
}
else if (str_a == NULL || str_b == NULL) {
ret = (str_a == NULL) ? -1 : 1;
}
else {
if (grp == packet) {
gint int_a = atoi(str_a);
gint int_b = atoi(str_b);
if (int_a == int_b)
ret = 0;
else if (int_a < int_b)
ret = -1;
else
ret = 1;
}
else
ret = g_ascii_strcasecmp(str_a,str_b);
}
g_free(str_a);
g_free(str_b);
return ret;
}
static gint find_summary_data(error_equiv_table *err, const expert_info_t *expert_data)
{
guint i;
error_procedure_t *procedure;
if (err->num_procs==0) {
return -1;
}
for (i=0;i<err->num_procs;i++) {
procedure = &g_array_index(err->procs_array, error_procedure_t, i);
if (strcmp(procedure->entries[0], expert_data->protocol) == 0 &&
strcmp(procedure->entries[1], expert_data->summary) == 0) {
return i;
}
}
return -1;
}
static void
error_select_filter_cb(GtkWidget *widget _U_, gpointer callback_data, guint callback_action)
{
int action, type, selection;
error_equiv_table *err = (error_equiv_table *)callback_data;
char str[512];
const char *current_filter;
error_procedure_t *procedure;
GtkTreeIter iter;
GtkTreeModel *model;
expert_info_t expert_data;
gchar *grp;
action=FILTER_ACTION(callback_action);
type=FILTER_ACTYPE(callback_action);
if(!gtk_tree_selection_get_selected(err->select, &model, &iter)){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No selection made or the table is empty");
return;
}
gtk_tree_model_get (model, &iter,
GROUP_COLUMN, &grp,
PROTOCOL_COLUMN, &expert_data.protocol,
SUMMARY_COLUMN, &expert_data.summary,
-1);
if (strcmp(grp, packet)==0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "You cannot filter or search for packet number. Click on a valid item header.");
g_free(expert_data.summary);
return;
}
selection = find_summary_data(err, &expert_data);
g_free(expert_data.summary);
if(selection>=(int)err->num_procs){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "No items are selected");
return;
}
current_filter=gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
procedure = &g_array_index(err->procs_array, error_procedure_t, selection);
if (action != ACTION_WEB_LOOKUP && action != ACTION_COPY) {
char *msg;
if (0 ) {
if (action != ACTION_FIND_FRAME && action != ACTION_FIND_NEXT && action != ACTION_FIND_PREVIOUS) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Wireshark cannot create a filter on this item - %s, try using find instead.",
procedure->entries[1]);
return;
}
}
msg = g_malloc(escape_string_len(procedure->entries[1]));
escape_string(msg, procedure->entries[1]);
switch(type){
case ACTYPE_SELECTED:
if (procedure->fvalue_value==NULL) {
g_snprintf(str, sizeof(str), "expert.message==%s", msg);
}
else
{
g_strlcpy(str, procedure->fvalue_value, sizeof(str));
}
break;
case ACTYPE_NOT_SELECTED:
if (procedure->fvalue_value==NULL) {
g_snprintf(str, sizeof(str), "!(expert.message==%s)", msg);
}
else
{
g_snprintf(str, sizeof(str), "!(%s)", procedure->fvalue_value);
}
break;
case ACTYPE_AND_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
g_snprintf(str, sizeof(str), "expert.message==%s", msg);
else
g_snprintf(str, sizeof(str), "(%s) && (expert.message==%s)", current_filter, msg);
break;
case ACTYPE_OR_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
g_snprintf(str, sizeof(str), "expert.message==%s", msg);
else
g_snprintf(str, sizeof(str), "(%s) || (expert.message==%s)", current_filter, msg);
break;
case ACTYPE_AND_NOT_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
g_snprintf(str, sizeof(str), "!(expert.message==%s)", msg);
else
g_snprintf(str, sizeof(str), "(%s) && !(expert.message==%s)", current_filter, msg);
break;
case ACTYPE_OR_NOT_SELECTED:
if ((!current_filter) || (0 == strlen(current_filter)))
g_snprintf(str, sizeof(str), "!(expert.message==%s)", msg);
else
g_snprintf(str, sizeof(str), "(%s) || !(expert.message==%s)", current_filter, msg);
break;
default:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Can't find menu type - %u", type);
}
g_free(msg);
}
switch(action){
case ACTION_MATCH:
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), str);
main_filter_packets(&cfile, str, FALSE);
gdk_window_raise(gtk_widget_get_window(top_level));
break;
case ACTION_PREPARE:
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), str);
break;
case ACTION_FIND_FRAME:
find_frame_with_filter(str);
break;
case ACTION_FIND_NEXT:
case ACTION_FIND_PREVIOUS:
if (procedure->fvalue_value==NULL) {
find_frame_with_filter(str);
}
else
{
cf_find_packet_dfilter_string(&cfile, str, SD_FORWARD);
}
break;
case ACTION_COLORIZE:
color_display_with_filter(str);
break;
case ACTION_WEB_LOOKUP:
g_snprintf(str, sizeof(str), "http://www.google.com/search?hl=en&q=%s+'%s'", procedure->entries[0], procedure->entries[1]);
browser_open_url(str);
break;
case ACTION_COPY:
{
GString *copyString = g_string_sized_new(0);
g_string_printf(copyString, "%s: %s",
procedure->entries[0], procedure->entries[1]);
copy_to_clipboard(copyString);
g_string_free(copyString, TRUE);
}
break;
default:
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Can't find menu action - %u", action);
}
}
static gboolean
error_show_popup_menu_cb(void *widg _U_, GdkEvent *event, gpointer user_data)
{
error_equiv_table *err = user_data;
GdkEventButton *bevent = (GdkEventButton *)event;
if(event->type==GDK_BUTTON_PRESS && bevent->button==3){
gtk_menu_popup(GTK_MENU(err->menu), NULL, NULL, NULL, NULL,
bevent->button, bevent->time);
}
return FALSE;
}
static void
apply_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_SELECTED, 0));
}
static void
apply_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_NOT_SELECTED, 0));
}
static void
apply_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_SELECTED, 0));
}
static void
apply_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_SELECTED, 0));
}
static void
apply_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
apply_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_MATCH(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
prep_as_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_SELECTED, 0));
}
static void
prep_as_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_NOT_SELECTED, 0));
}
static void
prep_as_and_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_SELECTED, 0));
}
static void
prep_as_or_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_SELECTED, 0));
}
static void
prep_as_and_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_AND_NOT_SELECTED, 0));
}
static void
prep_as_or_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_PREPARE(ACTYPE_OR_NOT_SELECTED, 0));
}
static void
find_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_SELECTED, 0));
}
static void
find_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_FRAME(ACTYPE_NOT_SELECTED, 0));
}
static void
find_prev_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_SELECTED, 0));
}
static void
find_prev_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_PREVIOUS(ACTYPE_NOT_SELECTED, 0));
}
static void
find_next_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_SELECTED, 0));
}
static void
find_next_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_FIND_NEXT(ACTYPE_NOT_SELECTED, 0));
}
static void
color_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, 0));
}
static void
color_not_selected_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_COLORIZE(ACTYPE_SELECTED, 0));
}
static void
internet_search_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_WEB_LOOKUP);
}
static void
copy_cb(GtkWidget *widget, gpointer user_data)
{
error_select_filter_cb( widget , user_data, CALLBACK_COPY);
}
static void
expert_goto_pkt_cb (GtkTreeSelection *selection, gpointer data _U_)
{
GtkTreeIter iter;
GtkTreeModel *model;
gchar *pkt;
gchar *grp;
if (gtk_tree_selection_get_selected (selection, &model, &iter))
{
gtk_tree_model_get (model, &iter,
PROTOCOL_COLUMN, &pkt,
GROUP_COLUMN, &grp,
-1);
if (strcmp(grp, packet)==0) {
cf_goto_frame(&cfile, atoi(pkt));
}
g_free (pkt);
}
}
static void
error_create_popup_menu(error_equiv_table *err)
{
GtkUIManager *ui_manager;
GtkActionGroup *action_group;
GError *error = NULL;
err->select = gtk_tree_view_get_selection (GTK_TREE_VIEW (err->tree_view));
gtk_tree_selection_set_mode (err->select, GTK_SELECTION_SINGLE);
g_signal_connect (G_OBJECT (err->select), "changed", G_CALLBACK(expert_goto_pkt_cb), NULL);
action_group = gtk_action_group_new ("ExpertFilterPopupActionGroup");
gtk_action_group_add_actions (action_group,
(gpointer)expert_popup_entries,
G_N_ELEMENTS(expert_popup_entries),
err);
ui_manager = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager, action_group, 0);
gtk_ui_manager_add_ui_from_string (ui_manager,ui_desc_expert_filter_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building expert filter popup failed: %s\n",
error->message);
g_error_free (error);
error = NULL;
}
err->menu = gtk_ui_manager_get_widget(ui_manager, "/ExpertFilterPopup");
g_signal_connect(err->tree_view, "button_press_event", G_CALLBACK(error_show_popup_menu_cb), err);
}
void
init_error_table(error_equiv_table *err, guint num_procs, GtkWidget *vbox)
{
GtkTreeStore *store;
GtkWidget *tree;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeSortable *sortable;
store = gtk_tree_store_new (4,
G_TYPE_POINTER,
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_INT);
tree = gtk_tree_view_new_with_model (GTK_TREE_MODEL (store));
err->tree_view = GTK_TREE_VIEW(tree);
sortable = GTK_TREE_SORTABLE(store);
gtk_tree_view_set_fixed_height_mode(err->tree_view, TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW (tree), FALSE);
g_object_unref (G_OBJECT (store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Group", renderer, NULL);
gtk_tree_view_column_set_sort_column_id(column, GROUP_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_cell_data_func(column, renderer, str_ptr_data_func,
GINT_TO_POINTER(GROUP_COLUMN), NULL);
gtk_tree_sortable_set_sort_func(sortable, GROUP_COLUMN, str_ptr_sort_func,
GINT_TO_POINTER(GROUP_COLUMN), NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_column_set_fixed_width(column, 80);
gtk_tree_view_append_column (GTK_TREE_VIEW (err->tree_view), column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Protocol", renderer, "text", PROTOCOL_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(column, PROTOCOL_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_cell_data_func(column, renderer, proto_data_func,
GINT_TO_POINTER(PROTOCOL_COLUMN), NULL);
gtk_tree_sortable_set_sort_func(sortable, PROTOCOL_COLUMN, proto_sort_func,
GINT_TO_POINTER(PROTOCOL_COLUMN), NULL);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_column_set_fixed_width(column, 100);
gtk_tree_view_append_column (GTK_TREE_VIEW (err->tree_view), column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Summary", renderer, "text", SUMMARY_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(column, SUMMARY_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 300);
gtk_tree_view_column_set_fixed_width(column,
700 -
(80 + 100 + 80 +
24 + 22 ));
gtk_tree_view_append_column (GTK_TREE_VIEW (err->tree_view), column);
renderer = gtk_cell_renderer_text_new ();
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
column = gtk_tree_view_column_new_with_attributes ("Count", renderer, "text", COUNT_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(column, COUNT_COLUMN);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 80);
gtk_tree_view_append_column (GTK_TREE_VIEW (err->tree_view), column);
err->scrolled_window=scrolled_window_new(NULL, NULL);
gtk_container_add(GTK_CONTAINER(err->scrolled_window), GTK_WIDGET (err->tree_view));
gtk_box_pack_start(GTK_BOX(vbox), err->scrolled_window, TRUE, TRUE, 0);
gtk_tree_view_set_search_column (err->tree_view, SUMMARY_COLUMN);
gtk_tree_view_set_reorderable (err->tree_view, TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(err->tree_view), TRUE);
gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(err->tree_view), TRUE);
gtk_widget_show(err->scrolled_window);
err->num_procs=num_procs;
err->text = g_string_chunk_new(100);
err->procs_array = g_array_sized_new(FALSE, FALSE, sizeof(error_procedure_t), num_procs);
error_create_popup_menu(err);
}
void
init_error_table_row(error_equiv_table *err, const expert_info_t *expert_data)
{
guint old_num_procs=err->num_procs;
gint row=0;
error_procedure_t *procedure;
GtkTreeStore *store;
GtkTreeIter new_iter;
gchar num[10];
row = find_summary_data(err, expert_data);
if(row==-1){
error_procedure_t new_procedure;
row = old_num_procs;
new_procedure.count=0;
new_procedure.fvalue_value = NULL;
g_array_append_val(err->procs_array, new_procedure);
procedure = &g_array_index(err->procs_array, error_procedure_t, row);
procedure->entries[0]=(char *)g_string_chunk_insert_const(err->text, expert_data->protocol);
procedure->entries[1]=(char *)g_string_chunk_insert_const(err->text, expert_data->summary);
store = GTK_TREE_STORE(gtk_tree_view_get_model(err->tree_view));
gtk_tree_store_append (store, &procedure->iter, NULL);
gtk_tree_store_set (store, &procedure->iter,
GROUP_COLUMN, match_strval(expert_data->group, expert_group_vals),
PROTOCOL_COLUMN, procedure->entries[0],
SUMMARY_COLUMN, procedure->entries[1], -1);
if (expert_data->pitem) {
char *filter;
g_assert(PITEM_FINFO(expert_data->pitem));
filter = proto_construct_match_selected_string(PITEM_FINFO(expert_data->pitem), NULL);
if (filter != NULL)
procedure->fvalue_value = g_string_chunk_insert_const(err->text, filter);
}
err->num_procs = ++old_num_procs;
}
procedure = &g_array_index(err->procs_array, error_procedure_t, row);
procedure->count++;
store = GTK_TREE_STORE(gtk_tree_view_get_model(err->tree_view));
gtk_tree_store_set(store, &procedure->iter,
COUNT_COLUMN, procedure->count,
-1);
g_snprintf(num, sizeof(num), "%d", expert_data->packet_num);
#if 0
This does not have a big performance improvment :(
gtk_tree_store_insert_with_values (store,
&new_iter,
&procedure->iter,
G_MAXINT,
#else
if (procedure->count > 1000) {
gtk_tree_store_prepend(store, &new_iter, &procedure->iter);
}
else {
gtk_tree_store_append(store, &new_iter, &procedure->iter);
}
gtk_tree_store_set(store, &new_iter,
#endif
GROUP_COLUMN, packet,
PROTOCOL_COLUMN, num,
COUNT_COLUMN, 1,
-1);
}
void
reset_error_table_data(error_equiv_table *err)
{
GtkTreeStore *store;
store = GTK_TREE_STORE(gtk_tree_view_get_model(err->tree_view));
gtk_tree_store_clear(store);
err->num_procs = 0;
g_string_chunk_free(err->text);
err->text = g_string_chunk_new(100);
g_array_set_size(err->procs_array, 0);
}
void
free_error_table_data(error_equiv_table *err)
{
err->num_procs=0;
g_string_chunk_free(err->text);
g_array_free(err->procs_array, TRUE);
}
