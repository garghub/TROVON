void
capture_filter_construct_cb(GtkWidget *w, gpointer user_data _U_)
{
GtkWidget *filter_browse_w;
GtkWidget *parent_filter_te;
static construct_args_t args = {
"Wireshark: Capture Filter",
FALSE,
FALSE,
FALSE
};
filter_browse_w = (GtkWidget *)g_object_get_data(G_OBJECT(w), E_FILT_DIALOG_PTR_KEY);
if (filter_browse_w != NULL) {
reactivate_window(filter_browse_w);
return;
}
parent_filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(w), E_FILT_TE_PTR_KEY);
filter_dialog_new(w, parent_filter_te, CFILTER_LIST, &args);
}
void
display_filter_construct_cb(GtkWidget *w, gpointer construct_args_ptr)
{
construct_args_t *construct_args = (construct_args_t *)construct_args_ptr;
GtkWidget *filter_browse_w;
GtkWidget *parent_filter_te;
filter_browse_w = (GtkWidget *)g_object_get_data(G_OBJECT(w), E_FILT_DIALOG_PTR_KEY);
if (filter_browse_w != NULL) {
reactivate_window(filter_browse_w);
return;
}
parent_filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(w), E_FILT_TE_PTR_KEY);
filter_dialog_new(w, parent_filter_te, DFILTER_LIST, construct_args);
}
void
filter_button_destroy_cb(GtkWidget *button, gpointer user_data _U_)
{
GtkWidget *filter_w;
filter_w = (GtkWidget *)g_object_get_data(G_OBJECT(button), E_FILT_DIALOG_PTR_KEY);
if (filter_w != NULL) {
g_object_set_data(G_OBJECT(button), E_FILT_DIALOG_PTR_KEY, NULL);
window_destroy(filter_w);
}
}
void
cfilter_dialog_cb(GtkWidget *w _U_)
{
static construct_args_t args = {
"Wireshark: Capture Filter",
FALSE,
FALSE,
FALSE
};
if (global_cfilter_w != NULL) {
reactivate_window(global_cfilter_w);
return;
}
global_cfilter_w = filter_dialog_new(NULL, NULL, CFILTER_LIST, &args);
}
void
dfilter_dialog_cb(GtkWidget *w _U_)
{
static construct_args_t args = {
"Wireshark: Display Filter",
TRUE,
TRUE,
FALSE
};
display_filter_construct_cb((GtkWidget *)g_object_get_data(G_OBJECT(top_level), E_FILT_BT_PTR_KEY), &args);
}
static void
remember_filter_dialog(GtkWidget *main_w, GList **filter_dialogs)
{
*filter_dialogs = g_list_append(*filter_dialogs, main_w);
}
static void
forget_filter_dialog(GtkWidget *main_w, filter_list_type_t list_type)
{
switch (list_type) {
case CFILTER_EDITED_LIST:
cfilter_dialogs = g_list_remove(cfilter_dialogs, main_w);
break;
case DFILTER_EDITED_LIST:
dfilter_dialogs = g_list_remove(dfilter_dialogs, main_w);
break;
default:
g_assert_not_reached();
break;
}
}
static GList *
get_filter_dialog_list(filter_list_type_t list_type)
{
switch (list_type) {
case CFILTER_EDITED_LIST:
return cfilter_dialogs;
case DFILTER_EDITED_LIST:
return dfilter_dialogs;
default:
g_assert_not_reached();
return NULL;
}
}
static GtkTreeIter *
fill_list(GtkWidget *main_w, filter_list_type_t list_type, const gchar *filter_te_str)
{
GList *fl_entry;
filter_def *filt;
GtkTreeView *filter_l;
GtkListStore *store;
GtkTreeIter iter;
GtkTreeIter *l_select = NULL;
filter_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY));
store = GTK_LIST_STORE(gtk_tree_view_get_model(filter_l));
fl_entry = get_filter_list_first(list_type);
while (fl_entry != NULL) {
filt = (filter_def *) fl_entry->data;
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, filt->name,
1, fl_entry, -1);
if (filter_te_str && filt->strval) {
if (strcmp(filter_te_str, filt->strval) == 0) {
l_select = (GtkTreeIter *)g_memdup(&iter, sizeof(iter));
}
}
fl_entry = fl_entry->next;
}
return l_select;
}
static GtkWidget *
filter_dialog_new(GtkWidget *button, GtkWidget *parent_filter_te,
filter_list_type_t list_type, construct_args_t *construct_args)
{
GtkWidget *main_w,
*main_vb,
*bbox,
*ok_bt,
*apply_bt,
*save_bt,
*cancel_bt,
*help_bt;
GtkWidget *filter_vb,
*props_vb;
GtkWidget *top_hb,
*list_bb,
*new_bt,
*del_bt,
*filter_sc,
*filter_l,
*middle_hb,
*name_lb,
*name_te,
*bottom_hb,
*filter_lb,
*filter_te,
*add_expression_bt,
*filter_fr,
*edit_fr,
*props_fr;
GdkWindow *parent;
static filter_list_type_t cfilter_list_type = CFILTER_EDITED_LIST;
static filter_list_type_t dfilter_list_type = DFILTER_EDITED_LIST;
filter_list_type_t *filter_list_type_p;
GList **filter_dialogs;
const gchar *filter_te_str = NULL;
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
GtkTreeIter *l_select;
const gchar *list_name = NULL;
switch (list_type) {
case CFILTER_LIST:
filter_dialogs = &cfilter_dialogs;
filter_list_type_p = &cfilter_list_type;
list_type = CFILTER_EDITED_LIST;
list_name = "Capture Filter";
break;
case DFILTER_LIST:
filter_dialogs = &dfilter_dialogs;
filter_list_type_p = &dfilter_list_type;
list_type = DFILTER_EDITED_LIST;
list_name = "Display Filter";
break;
default:
g_assert_not_reached();
filter_dialogs = NULL;
filter_list_type_p = NULL;
break;
}
main_w = dlg_conf_window_new(construct_args->title);
gtk_window_set_modal(GTK_WINDOW(main_w), TRUE);
gtk_window_set_default_size(GTK_WINDOW(main_w), 400, 400);
g_object_set_data(G_OBJECT(main_w), E_FILT_CONSTRUCT_ARGS_KEY, construct_args);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(main_w), main_vb);
gtk_widget_show(main_vb);
if (parent_filter_te)
filter_te_str = gtk_entry_get_text(GTK_ENTRY(parent_filter_te));
filter_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(filter_vb), 0);
gtk_box_pack_start(GTK_BOX (main_vb), filter_vb, TRUE, TRUE, 0);
gtk_widget_show(filter_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX (filter_vb), top_hb, TRUE, TRUE, 0);
gtk_widget_show(top_hb);
edit_fr = gtk_frame_new("Edit");
gtk_box_pack_start(GTK_BOX(top_hb), edit_fr, FALSE, FALSE, 0);
gtk_widget_show(edit_fr);
list_bb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width(GTK_CONTAINER(list_bb), 5);
gtk_container_add(GTK_CONTAINER(edit_fr), list_bb);
gtk_widget_show(list_bb);
new_bt = gtk_button_new_from_stock(GTK_STOCK_NEW);
g_signal_connect(new_bt, "clicked", G_CALLBACK(filter_new_bt_clicked_cb), filter_list_type_p);
gtk_widget_show(new_bt);
gtk_box_pack_start (GTK_BOX (list_bb), new_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(new_bt, "Create a new filter at the end of the list (with the current properties)");
del_bt = gtk_button_new_from_stock(GTK_STOCK_DELETE);
gtk_widget_set_sensitive(del_bt, FALSE);
g_signal_connect(del_bt, "clicked", G_CALLBACK(filter_del_bt_clicked_cb), filter_list_type_p);
g_object_set_data(G_OBJECT(main_w), E_FILT_DEL_BT_KEY, del_bt);
gtk_widget_show(del_bt);
gtk_box_pack_start (GTK_BOX (list_bb), del_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(del_bt, "Delete the selected filter");
filter_fr = gtk_frame_new(list_name);
gtk_box_pack_start(GTK_BOX(top_hb), filter_fr, TRUE, TRUE, 0);
gtk_widget_show(filter_fr);
filter_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(filter_sc),
GTK_SHADOW_IN);
gtk_container_set_border_width (GTK_CONTAINER (filter_sc), 5);
gtk_container_add(GTK_CONTAINER(filter_fr), filter_sc);
gtk_widget_show(filter_sc);
store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_POINTER);
filter_l = tree_view_new(GTK_TREE_MODEL(store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(filter_l), FALSE);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("", renderer, "text",
0, NULL);
gtk_tree_view_column_set_sort_column_id(column, 0);
gtk_tree_view_append_column(GTK_TREE_VIEW(filter_l), column);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(filter_l));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
g_signal_connect(sel, "changed", G_CALLBACK(filter_sel_list_cb), NULL);
g_signal_connect(filter_l, "button_press_event", G_CALLBACK(filter_sel_list_button_cb),
NULL);
g_object_set_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY, filter_l);
gtk_container_add(GTK_CONTAINER(filter_sc), filter_l);
gtk_widget_show(filter_l);
g_object_set_data(G_OBJECT(filter_l), E_FILT_DBLFUNC_KEY, filter_dlg_dclick);
g_object_set_data(G_OBJECT(filter_l), E_FILT_DBLARG_KEY, main_w);
g_object_set_data(G_OBJECT(filter_l), E_FILT_DBLACTIVATE_KEY,
construct_args->activate_on_ok ? (gpointer)"" : NULL);
l_select = fill_list(main_w, list_type, filter_te_str);
g_object_unref(G_OBJECT(store));
props_fr = gtk_frame_new("Properties");
gtk_box_pack_start(GTK_BOX(filter_vb), props_fr, FALSE, FALSE, 0);
gtk_widget_show(props_fr);
props_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(props_vb), 5);
gtk_container_add(GTK_CONTAINER(props_fr), props_vb);
gtk_widget_show(props_vb);
middle_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (props_vb), middle_hb, TRUE, TRUE, 0);
gtk_widget_show(middle_hb);
name_lb = gtk_label_new("Filter name:");
gtk_box_pack_start(GTK_BOX(middle_hb), name_lb, FALSE, FALSE, 0);
gtk_widget_show(name_lb);
name_te = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(middle_hb), name_te, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(main_w), E_FILT_NAME_TE_KEY, name_te);
g_signal_connect(name_te, "changed", G_CALLBACK(filter_name_te_changed_cb), filter_list_type_p);
gtk_widget_show(name_te);
bottom_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (props_vb), bottom_hb, TRUE, TRUE, 0);
gtk_widget_show(bottom_hb);
filter_lb = gtk_label_new("Filter string:");
gtk_box_pack_start(GTK_BOX(bottom_hb), filter_lb, FALSE, FALSE, 0);
gtk_widget_show(filter_lb);
filter_te = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(bottom_hb), filter_te, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY, filter_te);
g_signal_connect(filter_te, "changed", G_CALLBACK(filter_name_te_changed_cb), filter_list_type_p);
if (list_type == DFILTER_EDITED_LIST) {
colorize_filter_te_as_empty(filter_te);
g_object_set_data(G_OBJECT(main_w), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_te, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(main_w, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
}
gtk_widget_show(filter_te);
g_object_set_data(G_OBJECT(main_w), E_FILT_PARENT_FILTER_TE_KEY, parent_filter_te);
if (list_type == DFILTER_EDITED_LIST) {
gtk_widget_set_tooltip_text(filter_te,
"Enter a display filter. "
"The background color of this field is changed by a continuous syntax check"
" (green is valid, red is invalid, yellow may have unexpected results).");
add_expression_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_ADD_EXPRESSION);
g_signal_connect(add_expression_bt, "clicked", G_CALLBACK(filter_add_expr_bt_cb), main_w);
gtk_box_pack_start(GTK_BOX(bottom_hb), add_expression_bt, FALSE, FALSE, 0);
gtk_widget_show(add_expression_bt);
gtk_widget_set_tooltip_text(add_expression_bt, "Add an expression to the filter string");
}
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(filter_dlg_ok_cb), filter_list_type_p);
gtk_widget_set_tooltip_text(ok_bt, "Apply the filters and close this dialog");
if (parent_filter_te != NULL) {
dlg_set_activate(name_te, ok_bt);
dlg_set_activate(filter_te, ok_bt);
}
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(filter_dlg_apply_cb), filter_list_type_p);
gtk_widget_set_tooltip_text(apply_bt, "Apply the filters and keep this dialog open");
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(filter_dlg_save_cb), filter_list_type_p);
gtk_widget_set_tooltip_text(save_bt, "Save the filters permanently and keep this dialog open");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel the changes");
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(filter_dlg_cancel_cb), filter_list_type_p);
window_set_cancel_button(main_w, cancel_bt, NULL);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
if (list_type == CFILTER_EDITED_LIST) {
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_CAPTURE_FILTERS_DIALOG);
} else {
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_DISPLAY_FILTERS_DIALOG);
}
gtk_widget_set_tooltip_text(help_bt, "Show topic specific help");
if(ok_bt) {
gtk_widget_grab_default(ok_bt);
}
remember_filter_dialog(main_w, filter_dialogs);
if (button != NULL) {
g_object_set_data(G_OBJECT(main_w), E_FILT_BUTTON_PTR_KEY, button);
g_object_set_data(G_OBJECT(button), E_FILT_DIALOG_PTR_KEY, main_w);
}
if (l_select) {
gtk_tree_selection_select_iter(sel, l_select);
g_free(l_select);
} else if (filter_te_str && filter_te_str[0]) {
gtk_entry_set_text(GTK_ENTRY(name_te), "New filter");
gtk_entry_set_text(GTK_ENTRY(filter_te), filter_te_str);
}
g_signal_connect(main_w, "delete_event", G_CALLBACK(filter_dlg_delete_event_cb), filter_list_type_p);
g_signal_connect(main_w, "destroy", G_CALLBACK(filter_dlg_destroy_cb), filter_list_type_p);
gtk_widget_show(main_w);
if(construct_args->modal_and_transient) {
parent = gtk_widget_get_parent_window(parent_filter_te);
gdk_window_set_transient_for(gtk_widget_get_window(main_w), parent);
gtk_window_set_modal(GTK_WINDOW(main_w), TRUE);
}
if (parent_filter_te == NULL && prefs.gui_use_pref_save) {
gtk_widget_hide(ok_bt);
}
if (!construct_args->wants_apply_button) {
gtk_widget_hide(apply_bt);
}
if (!prefs.gui_use_pref_save) {
gtk_widget_hide(save_bt);
}
window_present(main_w);
return main_w;
}
static void
filter_dlg_dclick(GtkWidget *filter_l, gpointer main_w_arg, gpointer activate)
{
GtkWidget *main_w = GTK_WIDGET(main_w_arg);
GtkWidget *parent_filter_te =
(GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_PARENT_FILTER_TE_KEY);
GList *flp;
filter_def *filt;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(filter_l));
if (parent_filter_te != NULL) {
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 1, &flp, -1);
if (flp) {
filt = (filter_def *) flp->data;
gtk_entry_set_text(GTK_ENTRY(parent_filter_te),
filt->strval);
if (activate != NULL) {
g_signal_emit_by_name(G_OBJECT(parent_filter_te), "activate", NULL);
}
}
}
}
window_destroy(main_w);
}
static void
filter_dlg_ok_cb(GtkWidget *ok_bt, gpointer data)
{
filter_list_type_t list_type = *(filter_list_type_t *)data;
filter_apply(gtk_widget_get_toplevel(ok_bt), TRUE);
if (!prefs.gui_use_pref_save) {
filter_dlg_save(list_type);
}
}
static void
filter_dlg_apply_cb(GtkWidget *apply_bt, gpointer data)
{
filter_list_type_t list_type = *(filter_list_type_t *)data;
filter_apply(gtk_widget_get_toplevel(apply_bt), FALSE);
if (!prefs.gui_use_pref_save) {
filter_dlg_save(list_type);
}
}
static void
filter_apply(GtkWidget *main_w, gboolean destroy)
{
construct_args_t *construct_args =
(construct_args_t *)g_object_get_data(G_OBJECT(main_w), E_FILT_CONSTRUCT_ARGS_KEY);
GtkWidget *parent_filter_te =
(GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_PARENT_FILTER_TE_KEY);
GtkWidget *filter_te;
const gchar *filter_string;
if (parent_filter_te != NULL) {
filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY);
filter_string =
(const gchar *)gtk_entry_get_text(GTK_ENTRY(filter_te));
gtk_entry_set_text(GTK_ENTRY(parent_filter_te), filter_string);
}
if (destroy) {
window_destroy(main_w);
}
if (parent_filter_te != NULL) {
if (construct_args->activate_on_ok) {
g_signal_emit_by_name(G_OBJECT(parent_filter_te), "activate", NULL);
}
}
}
static void
filter_dlg_save(filter_list_type_t list_type)
{
char *pf_dir_path;
char *f_path;
int f_save_errno;
const char *filter_type;
switch (list_type) {
case CFILTER_EDITED_LIST:
filter_type = "capture";
list_type = CFILTER_LIST;
copy_filter_list(CFILTER_LIST, CFILTER_EDITED_LIST);
break;
case DFILTER_EDITED_LIST:
filter_type = "display";
list_type = DFILTER_LIST;
copy_filter_list(DFILTER_LIST, DFILTER_EDITED_LIST);
break;
default:
g_assert_not_reached();
filter_type = NULL;
break;
}
if (create_persconffile_dir(&pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\"\nfor filter files: %s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
return;
}
save_filter_list(list_type, &f_path, &f_save_errno);
if (f_path != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not save to your %s filter file\n\"%s\": %s.",
filter_type, f_path, g_strerror(f_save_errno));
g_free(f_path);
}
}
static void
filter_dlg_save_cb(GtkWidget *save_bt _U_, gpointer data)
{
filter_list_type_t list_type = *(filter_list_type_t *)data;
filter_dlg_save(list_type);
}
static void
filter_dlg_cancel_cb(GtkWidget *cancel_bt, gpointer data)
{
filter_list_type_t list_type = *(filter_list_type_t *)data;
GtkWidget *main_w = gtk_widget_get_toplevel(cancel_bt);
static GList *filter_list;
window_destroy(GTK_WIDGET(main_w));
filter_list = get_filter_dialog_list(list_type);
if(g_list_length(filter_list) == 0) {
switch (list_type) {
case CFILTER_EDITED_LIST:
copy_filter_list(CFILTER_EDITED_LIST, CFILTER_LIST);
break;
case DFILTER_EDITED_LIST:
copy_filter_list(DFILTER_EDITED_LIST, DFILTER_LIST);
break;
default:
g_assert_not_reached();
break;
}
}
#if 0
g_list_foreach(get_filter_dialog_list(list_type), filter_dlg_update_list_cb, &list_type);
#endif
}
static gboolean
filter_dlg_delete_event_cb(GtkWidget *main_w, GdkEvent *event _U_,
gpointer data)
{
filter_dlg_cancel_cb(main_w, data);
return FALSE;
}
static void
filter_dlg_destroy_cb(GtkWidget *win, gpointer data)
{
filter_list_type_t list_type = *(filter_list_type_t *)data;
GtkWidget *button;
button = (GtkWidget *)g_object_get_data(G_OBJECT(win), E_FILT_BUTTON_PTR_KEY);
if (button != NULL) {
g_object_set_data(G_OBJECT(button), E_FILT_DIALOG_PTR_KEY, NULL);
} else {
switch (list_type) {
#ifdef HAVE_LIBPCAP
case CFILTER_EDITED_LIST:
g_assert(win == global_cfilter_w);
global_cfilter_w = NULL;
break;
#endif
default:
g_assert_not_reached();
break;
}
}
forget_filter_dialog(win, list_type);
}
static gboolean
filter_sel_list_button_cb(GtkWidget *list, GdkEventButton *event,
gpointer data _U_)
{
void (* func)(GtkWidget *, gpointer, gpointer);
gpointer func_arg;
gpointer func_activate;
if (event->type == GDK_2BUTTON_PRESS) {
func = ( void (*)(GtkWidget *, void *, void *))g_object_get_data(G_OBJECT(list), E_FILT_DBLFUNC_KEY);
func_arg = g_object_get_data(G_OBJECT(list), E_FILT_DBLARG_KEY);
func_activate = g_object_get_data(G_OBJECT(list), E_FILT_DBLACTIVATE_KEY);
if (func)
(*func)(list, func_arg, func_activate);
}
return FALSE;
}
static void
filter_sel_list_cb(GtkTreeSelection *sel, gpointer data _U_)
{
GtkWidget *filter_l = GTK_WIDGET(gtk_tree_selection_get_tree_view(sel));
GtkWidget *main_w = gtk_widget_get_toplevel(filter_l);
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_NAME_TE_KEY);
GtkWidget *filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY);
GtkWidget *chg_bt = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_CHG_BT_KEY);
GtkWidget *copy_bt = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_COPY_BT_KEY);
GtkWidget *del_bt = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_DEL_BT_KEY);
filter_def *filt;
gchar *name = NULL, *strval = NULL;
GList *flp;
gint sensitivity = FALSE;
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 1, &flp, -1);
if (flp) {
filt = (filter_def *) flp->data;
name = g_strdup(filt->name);
strval = g_strdup(filt->strval);
sensitivity = TRUE;
}
}
if (name_te != NULL)
gtk_entry_set_text(GTK_ENTRY(name_te), name ? name : "");
if (filter_te != NULL)
gtk_entry_set_text(GTK_ENTRY(filter_te), strval ? strval : "");
if (chg_bt != NULL)
gtk_widget_set_sensitive(chg_bt, sensitivity);
if (copy_bt != NULL)
gtk_widget_set_sensitive(copy_bt, sensitivity);
if (del_bt != NULL)
gtk_widget_set_sensitive(del_bt, sensitivity);
g_free(name);
g_free(strval);
}
static void
new_filter_cb(gpointer data, gpointer user_data)
{
GtkWidget *main_w = (GtkWidget *)data;
GtkTreeView *filter_l;
GtkListStore *store;
GtkTreeIter iter;
new_filter_cb_args_t *args = (new_filter_cb_args_t *)user_data;
filter_def *nfilt = (filter_def *)args->nflp->data;
filter_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY));
store = GTK_LIST_STORE(gtk_tree_view_get_model(filter_l));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, nfilt->name, 1, args->nflp, -1);
if (GTK_WIDGET(filter_l) == args->active_filter_l) {
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(filter_l),
&iter);
}
}
static void
filter_new_bt_clicked_cb(GtkWidget *w, gpointer data)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_NAME_TE_KEY);
GtkWidget *filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY);
GtkWidget *filter_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY);
filter_list_type_t list_type = *(filter_list_type_t *)data;
GList *fl_entry;
const gchar *name, *strval;
new_filter_cb_args_t args;
name = gtk_entry_get_text(GTK_ENTRY(name_te));
strval = gtk_entry_get_text(GTK_ENTRY(filter_te));
if (strlen(name) == 0) {
name = "new";
}
if (strlen(strval) == 0) {
strval = "new";
}
fl_entry = add_to_filter_list(list_type, name, strval);
args.active_filter_l = filter_l;
args.nflp = fl_entry;
g_list_foreach(get_filter_dialog_list(list_type), new_filter_cb, &args);
}
static gboolean
chg_list_item_cb(GtkTreeModel *model, GtkTreePath *path _U_, GtkTreeIter *iter,
gpointer data)
{
GList *flp = (GList *)data;
filter_def *filt = (filter_def *)flp->data;
GList *nl_model;
gtk_tree_model_get(model, iter, 1, &nl_model, -1);
if (flp == nl_model) {
gtk_list_store_set(GTK_LIST_STORE(model), iter, 0, filt->name, -1);
return TRUE;
}
return FALSE;
}
static void
chg_filter_cb(gpointer data, gpointer user_data)
{
GtkWidget *main_w = (GtkWidget *)data;
GtkWidget *filter_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY);
gtk_tree_model_foreach(gtk_tree_view_get_model(GTK_TREE_VIEW(filter_l)),
chg_list_item_cb, user_data);
}
static void
filter_name_te_changed_cb(GtkWidget *w, gpointer data)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_NAME_TE_KEY);
GtkWidget *filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY);
GtkWidget *filter_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY);
filter_def *filt;
GList *fl_entry;
filter_list_type_t list_type = *(filter_list_type_t *)data;
const gchar *name = "";
const gchar *strval = "";
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(filter_l));
name = gtk_entry_get_text(GTK_ENTRY(name_te));
strval = gtk_entry_get_text(GTK_ENTRY(filter_te));
if (DFILTER_EDITED_LIST == list_type) {
filter_te_syntax_check_cb(filter_te, NULL);
}
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 1, &fl_entry, -1);
if (fl_entry != NULL) {
filt = (filter_def *) fl_entry->data;
if (strlen(name) > 0 && strlen(strval) > 0 && filt) {
g_free(filt->name);
g_free(filt->strval);
filt->name = g_strdup(name);
filt->strval = g_strdup(strval);
g_list_foreach(get_filter_dialog_list(list_type), chg_filter_cb,
fl_entry);
}
}
}
}
static void
delete_filter_cb(gpointer data, gpointer user_data)
{
GtkWidget *main_w = (GtkWidget *)data;
GtkWidget *filter_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY);
gchar *pos = (gchar *)user_data;
GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(filter_l));
GtkTreeIter iter;
gtk_tree_model_get_iter_from_string(model, &iter, pos);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
}
static void
filter_del_bt_clicked_cb(GtkWidget *w, gpointer data)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *filter_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_L_KEY);
filter_list_type_t list_type = *(filter_list_type_t *)data;
GList *fl_entry;
gchar *pos;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreePath *path;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(filter_l));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 1, &fl_entry, -1);
path = gtk_tree_model_get_path(model, &iter);
pos = gtk_tree_path_to_string(path);
gtk_tree_path_free(path);
if (fl_entry != NULL) {
remove_from_filter_list(list_type, fl_entry);
g_list_foreach(get_filter_dialog_list(list_type), delete_filter_cb, pos);
}
g_free(pos);
}
}
void
filter_add_expr_bt_cb(GtkWidget *w _U_, gpointer main_w_arg)
{
GtkWidget *main_w = GTK_WIDGET(main_w_arg);
GtkWidget *filter_te, *dfilter_w;
filter_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_FILT_FILTER_TE_KEY);
dfilter_w = dfilter_expr_dlg_new(filter_te);
if ( GTK_IS_WINDOW(main_w) && gtk_window_get_modal(GTK_WINDOW(main_w))) {
gtk_window_set_modal(GTK_WINDOW(dfilter_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(dfilter_w),
GTK_WINDOW(main_w));
}
}
static void
color_filter_te(GtkWidget *w, guint16 red, guint16 green, guint16 blue)
{
#if GTK_CHECK_VERSION(3,0,0)
static GdkRGBA black = { 0, 0, 0, 1.0 };
GdkRGBA bg;
bg.red = red / 65535.0;
bg.green = green / 65535.0;
bg.blue = blue / 65535.0;
bg.alpha = 1;
gtk_widget_override_color(w, GTK_STATE_FLAG_NORMAL, &black);
gtk_widget_override_background_color(w, GTK_STATE_FLAG_NORMAL, &bg);
gtk_widget_override_cursor(w, &black, &black);
#else
static GdkColor black = { 0, 0, 0, 0 };
GdkColor bg;
bg.pixel = 0;
bg.red = red;
bg.green = green;
bg.blue = blue;
gtk_widget_modify_text(w, GTK_STATE_NORMAL, &black);
gtk_widget_modify_base(w, GTK_STATE_NORMAL, &bg);
gtk_widget_modify_cursor(w, &black, &black);
#endif
}
void
colorize_filter_te_as_empty(GtkWidget *w)
{
#if GTK_CHECK_VERSION(3,0,0)
gtk_widget_override_color(w, GTK_STATE_FLAG_NORMAL, NULL);
gtk_widget_override_background_color(w, GTK_STATE_FLAG_NORMAL, NULL);
gtk_widget_override_cursor(w, NULL, NULL);
#else
gtk_widget_modify_text(w, GTK_STATE_NORMAL, NULL);
gtk_widget_modify_base(w, GTK_STATE_NORMAL, NULL);
gtk_widget_modify_cursor(w, NULL, NULL);
#endif
}
void
colorize_filter_te_as_invalid(GtkWidget *w)
{
color_filter_te(w, prefs.gui_text_invalid.red, prefs.gui_text_invalid.green, prefs.gui_text_invalid.blue);
}
static void
colorize_filter_te_as_deprecated(GtkWidget *w)
{
color_filter_te(w, prefs.gui_text_deprecated.red, prefs.gui_text_deprecated.green, prefs.gui_text_deprecated.blue);
}
void
colorize_filter_te_as_valid(GtkWidget *w)
{
color_filter_te(w, prefs.gui_text_valid.red, prefs.gui_text_valid.green, prefs.gui_text_valid.blue);
}
void
filter_te_syntax_check_cb(GtkWidget *w, gpointer user_data _U_)
{
const gchar *strval;
dfilter_t *dfp;
GPtrArray *depr = NULL;
gboolean use_statusbar;
guchar c;
strval = gtk_entry_get_text(GTK_ENTRY(w));
use_statusbar = g_object_get_data(G_OBJECT(w), E_FILT_FIELD_USE_STATUSBAR_KEY) ? TRUE : FALSE;
if (use_statusbar) {
statusbar_pop_filter_msg();
}
if (g_object_get_data(G_OBJECT(w), E_FILT_FIELD_NAME_ONLY_KEY) &&
strval && (c = proto_check_field_name(strval)) != 0)
{
colorize_filter_te_as_invalid(w);
if (use_statusbar) {
statusbar_push_filter_msg(" Illegal character in field name: '%c'", c);
}
} else if (strval && dfilter_compile(strval, &dfp)) {
if (dfp != NULL) {
depr = dfilter_deprecated_tokens(dfp);
}
if (strlen(strval) == 0) {
colorize_filter_te_as_empty(w);
} else if (depr) {
colorize_filter_te_as_deprecated(w);
if (use_statusbar) {
statusbar_push_temporary_msg(" \"%s\" may have unexpected results (see the User's Guide)",
(const char *) g_ptr_array_index(depr, 0));
}
} else {
colorize_filter_te_as_valid(w);
}
dfilter_free(dfp);
} else {
colorize_filter_te_as_invalid(w);
if (use_statusbar) {
if (dfilter_error_msg) {
statusbar_push_filter_msg(" Invalid filter: %s", dfilter_error_msg);
} else {
statusbar_push_filter_msg(" Invalid filter");
}
}
}
}
