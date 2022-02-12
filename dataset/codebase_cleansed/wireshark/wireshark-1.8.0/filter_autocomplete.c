static gboolean
is_protocol_name_being_typed(GtkWidget *filter_te, int str_len)
{
unsigned int i;
int op_len, cursor_pos;
gchar *start;
gchar *pos;
static const gchar *logic_ops[] =
{ "!", "not",
"||", "or",
"&&", "and",
"^^", "xor" };
if(!(cursor_pos = gtk_editable_get_position(GTK_EDITABLE(filter_te))))
return TRUE;
start = gtk_editable_get_chars(GTK_EDITABLE(filter_te), 0, (gint) cursor_pos);
pos = start + (cursor_pos - str_len);
while(pos > start) {
if(*pos != ' ' && *pos != '(') {
for(i = 0; i < (sizeof(logic_ops)/sizeof(logic_ops[0])); i++) {
op_len = (int) strlen(logic_ops[i]);
if(pos-start+1 < op_len)
continue;
if(!strncmp(pos-op_len+1, logic_ops[i], op_len)) {
g_free (start);
return TRUE;
}
}
g_free (start);
return FALSE;
}
pos--;
}
g_free (start);
return TRUE;
}
static void
autocomplete_protocol_string(GtkWidget *filter_te, gchar *selected_str)
{
int pos;
gchar *filter_str;
gchar *pch;
pos = gtk_editable_get_position(GTK_EDITABLE(filter_te));
filter_str = gtk_editable_get_chars(GTK_EDITABLE(filter_te), 0, pos);
pch = filter_str + strlen(filter_str);
while(pch != filter_str) {
pch--;
if(!g_ascii_isalnum(*pch) && (*pch) != '.' && (*pch) != '_' && (*pch) != '-') {
pch++;
break;
}
}
if(strncmp(pch, selected_str, pos-(pch-filter_str))) {
gtk_editable_delete_text(GTK_EDITABLE(filter_te), (gint) (pch-filter_str), pos);
pos = (int) (pch-filter_str);
pch = selected_str;
} else {
pch = (selected_str + strlen(pch));
}
gtk_editable_insert_text(GTK_EDITABLE(filter_te), pch, (gint) strlen(pch), &pos);
gtk_editable_set_position(GTK_EDITABLE(filter_te), pos);
g_free (filter_str);
}
static void
autoc_filter_row_activated_cb(GtkTreeView *treeview,
GtkTreePath *path,
GtkTreeViewColumn *column _U_,
gpointer data)
{
GtkWidget *w_main;
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *win;
gchar *proto;
model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)) {
gtk_tree_model_get(model, &iter, 0, &proto, -1);
autocomplete_protocol_string(GTK_WIDGET(data), proto);
g_free (proto);
}
w_main = gtk_widget_get_toplevel(GTK_WIDGET(data));
win = g_object_get_data(G_OBJECT(w_main), E_FILT_AUTOCOMP_PTR_KEY);
if(win != NULL) {
gtk_widget_destroy(win);
g_object_set_data(G_OBJECT(w_main), E_FILT_AUTOCOMP_PTR_KEY, NULL);
}
}
static gboolean
filter_te_focus_out_cb(GtkWidget *filter_te _U_,
GdkEvent *event _U_,
gpointer data)
{
GtkWidget *win;
win = g_object_get_data(G_OBJECT(data), E_FILT_AUTOCOMP_PTR_KEY);
if(win != NULL) {
gtk_widget_destroy(win);
g_object_set_data(G_OBJECT(data), E_FILT_AUTOCOMP_PTR_KEY, NULL);
}
return FALSE;
}
static gboolean
check_select_region (GtkWidget *filter_te, GtkWidget *popup_win,
const gchar *string, unsigned int str_len)
{
gint pos1 = gtk_editable_get_position(GTK_EDITABLE(filter_te));
gint pos2 = pos1 + (gint) strlen(string) - str_len;
gint pos3 = pos1;
if (pos2 > pos1) {
gtk_editable_insert_text(GTK_EDITABLE(filter_te), &string[str_len-1],
pos2-pos1+1, &pos3);
gtk_editable_set_position(GTK_EDITABLE(filter_te), pos1+1);
gtk_editable_select_region(GTK_EDITABLE(filter_te), pos1+1, pos2+1);
gtk_widget_hide (popup_win);
return TRUE;
}
return FALSE;
}
static void
init_autocompletion_list(GtkWidget *list)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(NULL, renderer, "text", 0, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);
store = gtk_list_store_new(1, G_TYPE_STRING);
gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
g_object_unref(store);
}
static void
add_to_autocompletion_list(GtkWidget *list, const gchar *str)
{
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, str, -1);
}
static gboolean
autocompletion_list_lookup(GtkWidget *filter_te, GtkWidget *popup_win, GtkWidget *list,
const gchar *str, gboolean *stop_propagation)
{
GtkRequisition requisition;
GtkListStore *store;
GtkTreeIter iter;
GtkAllocation popup_win_alloc;
gchar *curr_str;
unsigned int str_len = (unsigned int) strlen(str);
gchar *first = NULL;
gint count = 0;
gboolean loop = TRUE;
gboolean exact_match = FALSE;
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
do {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, 0, &curr_str, -1);
if( !g_ascii_strncasecmp(str, curr_str, str_len) ) {
loop = gtk_tree_model_iter_next(GTK_TREE_MODEL(store), &iter);
if (strlen(curr_str) == str_len) {
exact_match = TRUE;
}
count++;
if (count == 1)
first = g_strdup (curr_str);
} else {
loop = gtk_list_store_remove(store, &iter);
}
g_free(curr_str);
} while( loop );
if (count == 1 && !exact_match && strncmp(str, first, str_len) == 0) {
*stop_propagation = check_select_region(filter_te, popup_win, first, str_len);
}
if ((count == 1 && exact_match && strncmp(str, first, str_len) == 0) ||
!gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter))
{
g_free (first);
return FALSE;
}
g_free (first);
gtk_tree_view_columns_autosize(GTK_TREE_VIEW(list));
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_get_preferred_size(list, &requisition, NULL);
#else
gtk_widget_size_request(list, &requisition);
#endif
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_get_allocation(popup_win, &popup_win_alloc);
#else
popup_win_alloc = popup_win->allocation;
#endif
gtk_widget_set_size_request(popup_win, popup_win_alloc.width,
(requisition.height<200? requisition.height+8:200));
gtk_window_resize(GTK_WINDOW(popup_win), popup_win_alloc.width,
(requisition.height<200? requisition.height+8:200));
return TRUE;
}
return FALSE;
}
gboolean
filter_string_te_key_pressed_cb(GtkWidget *filter_te, GdkEventKey *event, gpointer user_data _U_)
{
GtkWidget *popup_win;
GtkWidget *w_toplevel;
GtkWidget *treeview;
GtkTreeModel *model;
GtkTreePath *path;
GtkTreeSelection *selection;
GtkTreeIter iter;
gchar* prefix;
gchar* prefix_start;
gboolean stop_propagation = FALSE;
guint k;
gchar ckey;
gint pos;
w_toplevel = gtk_widget_get_toplevel(filter_te);
popup_win = g_object_get_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY);
k = event->keyval;
ckey = event->string[0];
if( k == GDK_Shift_L || k == GDK_Shift_R)
return FALSE;
if (popup_win)
gtk_widget_show(popup_win);
pos = gtk_editable_get_position(GTK_EDITABLE(filter_te));
if (g_ascii_isalnum(ckey) ||
k == GDK_KP_Decimal || k == GDK_period ||
k == GDK_underscore || k == GDK_minus)
{
gtk_editable_delete_selection(GTK_EDITABLE(filter_te));
} else if (k == GDK_Return || k == GDK_KP_Enter) {
gtk_editable_select_region(GTK_EDITABLE(filter_te), pos, pos);
}
prefix_start = gtk_editable_get_chars(GTK_EDITABLE(filter_te), 0, pos);
if( !g_ascii_isalnum(ckey) &&
k != GDK_KP_Decimal && k != GDK_period &&
k != GDK_underscore && k != GDK_minus &&
k != GDK_space && k != GDK_Return && k != GDK_KP_Enter &&
k != GDK_Page_Down && k != GDK_Down && k != GDK_Page_Up && k != GDK_Up &&
k != GDK_BackSpace)
{
if (popup_win) {
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, NULL);
}
return FALSE;
}
prefix = prefix_start + strlen(prefix_start);
while(prefix != prefix_start) {
prefix--;
if(!g_ascii_isalnum((*prefix)) && (*prefix) != '.' && (*prefix) != '_' && (*prefix) != '-') {
prefix++;
break;
}
}
if(k==GDK_period || k==GDK_KP_Decimal) {
if( !strchr(prefix, '.') || !popup_win) {
gchar* name_with_period;
if (popup_win) {
gtk_widget_destroy (popup_win);
}
name_with_period = g_strconcat(prefix, event->string, NULL);
popup_win = filter_autocomplete_new(filter_te, name_with_period, FALSE, &stop_propagation);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, popup_win);
g_free(name_with_period);
g_free(prefix_start);
return stop_propagation;
}
} else if(k==GDK_BackSpace && !popup_win) {
if(strlen(prefix) > 1) {
prefix[strlen(prefix)-1] = '\0';
if(strchr(prefix, '.')) {
popup_win = filter_autocomplete_new(filter_te, prefix, FALSE, NULL);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, popup_win);
} else if(strlen(prefix) && is_protocol_name_being_typed(filter_te, (int) strlen(prefix)+2)) {
popup_win = filter_autocomplete_new(filter_te, prefix, TRUE, NULL);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, popup_win);
}
}
g_free(prefix_start);
return FALSE;
} else if(g_ascii_isalnum(ckey) && !popup_win) {
gchar *name = g_strconcat(prefix, event->string, NULL);
if( !strchr(name, '.') && is_protocol_name_being_typed(filter_te, (int) strlen(name)) ) {
popup_win = filter_autocomplete_new(filter_te, name, TRUE, &stop_propagation);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, popup_win);
}
g_free(name);
g_free(prefix_start);
return stop_propagation;
}
if( !popup_win ) {
g_free(prefix_start);
return FALSE;
}
treeview = g_object_get_data(G_OBJECT(popup_win), E_FILT_AUTOCOMP_TREE_KEY);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
switch(k)
{
case GDK_Page_Down:
case GDK_Down:
if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
if (gtk_tree_model_iter_next(model, &iter)) {
if (k == GDK_Page_Down) {
GtkTreeIter last_iter;
gint count = 0;
do {
last_iter = iter;
} while (++count < 8 && gtk_tree_model_iter_next(model, &iter));
iter = last_iter;
}
gtk_tree_selection_select_iter(GTK_TREE_SELECTION(selection), &iter);
path = gtk_tree_model_get_path(model, &iter);
gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(treeview), path,
NULL, FALSE, 0, 0);
gtk_tree_path_free(path);
} else {
gtk_tree_selection_unselect_all(selection);
}
} else if (gtk_tree_model_get_iter_first(model, &iter)) {
gtk_tree_selection_select_iter(GTK_TREE_SELECTION(selection), &iter);
path = gtk_tree_model_get_path(model, &iter);
gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(treeview), path,
NULL, FALSE, 0, 0);
gtk_tree_path_free(path);
}
g_free(prefix_start);
return TRUE;
case GDK_Page_Up:
case GDK_Up:
{
GtkTreeIter last_iter;
if (gtk_tree_selection_get_selected(selection, &model, &iter) ) {
path = gtk_tree_model_get_path(model, &iter);
if (gtk_tree_path_prev(path)) {
if (k == GDK_Page_Up) {
GtkTreePath *last_path;
gint count = 0;
do {
last_path = path;
} while (++count < 8 && gtk_tree_path_prev(path));
path = last_path;
}
gtk_tree_selection_select_path(GTK_TREE_SELECTION(selection), path);
gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(treeview), path, NULL, FALSE, 0, 0);
} else {
gtk_tree_selection_unselect_iter(selection, &iter);
}
gtk_tree_path_free(path);
} else if (gtk_tree_model_get_iter_first(model, &iter)) {
do {
last_iter = iter;
} while (gtk_tree_model_iter_next(model, &iter));
gtk_tree_selection_select_iter(GTK_TREE_SELECTION(selection), &last_iter);
path = gtk_tree_model_get_path(model, &last_iter);
gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(treeview), path,
NULL, FALSE, 0, 0);
gtk_tree_path_free(path);
}
g_free(prefix_start);
return TRUE;
}
case GDK_space:
case GDK_Return:
case GDK_KP_Enter:
if(gtk_tree_selection_get_selected(selection, &model, &iter) ) {
gchar *value;
if(k != GDK_space || strchr(prefix, '.')) {
gtk_tree_model_get(model, &iter, 0, &value, -1);
autocomplete_protocol_string(filter_te, value);
g_free(value);
}
if(k != GDK_space) {
stop_propagation = TRUE;
}
}
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, NULL);
break;
case GDK_BackSpace:
filter_autocomplete_handle_backspace(filter_te, treeview, popup_win, prefix, w_toplevel);
break;
default: {
gchar* updated_str;
updated_str = g_strconcat(prefix, event->string, NULL);
if( !autocompletion_list_lookup(filter_te, popup_win, treeview, updated_str, &stop_propagation) ) {
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(w_toplevel), E_FILT_AUTOCOMP_PTR_KEY, NULL);
}
g_free(updated_str);
}
}
g_free(prefix_start);
return stop_propagation;
}
static gboolean
build_autocompletion_list(GtkWidget *filter_te, GtkWidget *treeview, GtkWidget *popup_win,
const gchar *protocol_name, gboolean protocols_only, gboolean *stop_propagation)
{
void *cookie, *cookie2;
protocol_t *protocol;
unsigned int protocol_name_len;
header_field_info *hfinfo;
gint count = 0;
gboolean exact_match = FALSE;
const gchar *first = NULL;
int i;
protocol_name_len = (unsigned int) strlen(protocol_name);
if(protocol_name[protocol_name_len-1] == '.')
proto_registrar_get_byname(protocol_name);
for (i = proto_get_first_protocol(&cookie); i != -1; i = proto_get_next_protocol(&cookie)) {
protocol = find_protocol_by_id(i);
if (!proto_is_protocol_enabled(protocol))
continue;
if (protocols_only) {
const gchar *name = proto_get_protocol_filter_name (i);
if (!g_ascii_strncasecmp(protocol_name, name, protocol_name_len)) {
add_to_autocompletion_list(treeview, name);
if (strlen(name) == protocol_name_len) {
exact_match = TRUE;
}
count++;
if (count == 1)
first = name;
}
} else {
for (hfinfo = proto_get_first_protocol_field(i, &cookie2);
hfinfo != NULL;
hfinfo = proto_get_next_protocol_field(&cookie2))
{
if (hfinfo->same_name_prev != NULL)
continue;
if(!g_ascii_strncasecmp(protocol_name, hfinfo->abbrev, protocol_name_len)) {
add_to_autocompletion_list(treeview, hfinfo->abbrev);
if (strlen(hfinfo->abbrev) == protocol_name_len) {
exact_match = TRUE;
}
count++;
if (count == 1)
first = hfinfo->abbrev;
}
}
}
}
if (count == 1 && !exact_match && stop_propagation &&
strncmp(protocol_name, first, protocol_name_len) == 0)
{
*stop_propagation = check_select_region(filter_te, popup_win, first, protocol_name_len);
}
if (count == 0 || (count == 1 && exact_match &&
strncmp(protocol_name, first, protocol_name_len) == 0))
return FALSE;
return TRUE;
}
static void
filter_autocomplete_disable_sorting(GtkTreeModel *model)
{
gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(model),
GTK_TREE_SORTABLE_UNSORTED_SORT_COLUMN_ID, GTK_SORT_ASCENDING);
}
static void
filter_autocomplete_enable_sorting(GtkTreeModel *model)
{
gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(model), 0, GTK_SORT_ASCENDING);
}
static GtkWidget *
filter_autocomplete_new(GtkWidget *filter_te, const gchar *protocol_name,
gboolean protocols_only, gboolean *stop_propagation)
{
GtkWidget *popup_win;
GtkWidget *treeview;
GtkWidget *filter_sc;
gint x_pos, y_pos;
GtkTreeModel *model;
GtkTreeSelection *selection;
GtkRequisition requisition;
GtkWidget *w_toplevel;
GtkAllocation filter_te_alloc;
w_toplevel = gtk_widget_get_toplevel(filter_te);
popup_win = gtk_window_new (GTK_WINDOW_POPUP);
filter_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (filter_sc), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(filter_sc), GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(popup_win), filter_sc);
treeview = gtk_tree_view_new();
gtk_tree_view_set_hover_selection(GTK_TREE_VIEW(treeview), TRUE);
init_autocompletion_list(treeview);
g_object_set_data(G_OBJECT(popup_win), E_FILT_AUTOCOMP_TREE_KEY, treeview);
if (!build_autocompletion_list(filter_te, treeview, popup_win, protocol_name, protocols_only, stop_propagation)) {
gtk_widget_destroy(popup_win);
return NULL;
}
model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
if(model)
filter_autocomplete_enable_sorting(model);
gtk_container_add (GTK_CONTAINER (filter_sc), treeview);
g_signal_connect(treeview, "row-activated", G_CALLBACK(autoc_filter_row_activated_cb), filter_te);
g_signal_connect(filter_te, "focus-out-event", G_CALLBACK(filter_te_focus_out_cb), w_toplevel);
g_signal_connect(popup_win, "destroy", G_CALLBACK(filter_autocomplete_win_destroy_cb), NULL);
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_get_preferred_size(treeview, &requisition, NULL);
#else
gtk_widget_size_request(treeview, &requisition);
#endif
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_get_allocation(filter_te, &filter_te_alloc);
#else
filter_te_alloc = filter_te->allocation;
#endif
gtk_widget_set_size_request(popup_win, filter_te_alloc.width,
(requisition.height<200? requisition.height+8:200));
gtk_window_resize(GTK_WINDOW(popup_win), filter_te_alloc.width,
(requisition.height<200? requisition.height+8:200));
gdk_window_get_origin(gtk_widget_get_window(filter_te), &x_pos, &y_pos);
#if GTK_CHECK_VERSION(3,0,0)
x_pos += filter_te_alloc.x;
y_pos += (filter_te_alloc.y + filter_te_alloc.height);
#else
y_pos += filter_te_alloc.height;
#endif
gtk_window_move(GTK_WINDOW(popup_win), x_pos, y_pos);
gtk_widget_show_all (popup_win);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
gtk_tree_selection_unselect_all(selection);
return popup_win;
}
static void
filter_autocomplete_handle_backspace(GtkWidget *filter_te, GtkWidget *list, GtkWidget *popup_win,
gchar *prefix, GtkWidget *main_win)
{
GtkTreeModel *model;
GtkListStore *store;
GtkRequisition requisition;
size_t prefix_len;
gboolean protocols_only = FALSE;
GtkAllocation popup_win_alloc;
prefix_len = strlen(prefix);
if (prefix_len <= 1) {
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(main_win), E_FILT_AUTOCOMP_PTR_KEY, NULL);
return;
}
prefix_len--;
prefix[prefix_len] = '\0';
if(strchr(prefix, '.') == NULL) {
protocols_only = TRUE;
}
model = gtk_tree_view_get_model(GTK_TREE_VIEW(list));
store = GTK_LIST_STORE(model);
gtk_list_store_clear(store);
filter_autocomplete_disable_sorting(model);
if (!build_autocompletion_list(filter_te, list, popup_win, prefix, protocols_only, NULL)) {
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(main_win), E_FILT_AUTOCOMP_PTR_KEY, NULL);
return;
}
filter_autocomplete_enable_sorting(model);
gtk_tree_view_columns_autosize(GTK_TREE_VIEW(list));
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_get_preferred_size(list, &requisition, NULL);
#else
gtk_widget_size_request(list, &requisition);
#endif
#if GTK_CHECK_VERSION(2,18,0)
gtk_widget_get_allocation(popup_win, &popup_win_alloc);
#else
popup_win_alloc = popup_win->allocation;
#endif
gtk_widget_set_size_request(popup_win, popup_win_alloc.width,
(requisition.height<200? requisition.height+8:200));
gtk_window_resize(GTK_WINDOW(popup_win), popup_win_alloc.width,
(requisition.height<200? requisition.height+8:200));
}
static void
filter_autocomplete_win_destroy_cb(GtkWidget *win, gpointer data _U_)
{
g_object_set_data(G_OBJECT(win), E_FILT_AUTOCOMP_PTR_KEY, NULL);
}
gboolean
filter_parent_dlg_key_pressed_cb(GtkWidget *win, GdkEventKey *event, gpointer user_data _U_)
{
GtkWidget *popup_win;
popup_win = g_object_get_data(G_OBJECT(win), E_FILT_AUTOCOMP_PTR_KEY);
if(popup_win && event->keyval == GDK_Escape) {
gtk_widget_destroy(popup_win);
g_object_set_data(G_OBJECT(win), E_FILT_AUTOCOMP_PTR_KEY, NULL);
return TRUE;
}
return FALSE;
}
