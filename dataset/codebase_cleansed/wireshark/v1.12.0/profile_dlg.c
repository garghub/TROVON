static GtkTreeIter *
fill_list(GtkWidget *main_w)
{
GList *fl_entry;
profile_def *profile;
GtkTreeView *profile_l;
GtkListStore *store;
GtkTreeIter iter, *l_select = NULL;
const gchar *profile_name = get_profile_name();
profile_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY));
store = GTK_LIST_STORE(gtk_tree_view_get_model(profile_l));
init_profile_list();
fl_entry = edited_profile_list();
while (fl_entry && fl_entry->data) {
profile = (profile_def *)fl_entry->data;
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, NAME_COLUMN, profile->name, GLOBAL_COLUMN, profile->is_global, DATA_COLUMN, fl_entry, -1);
if (profile->name && (strcmp(profile_name, profile->name) == 0)) {
l_select = (GtkTreeIter *)g_memdup(&iter, sizeof(iter));
}
fl_entry = g_list_next(fl_entry);
}
return l_select;
}
static void
profile_select(GtkWidget *main_w, GtkTreeView *profile_l, gboolean destroy)
{
GList *fl_entry;
profile_def *profile;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(profile_l));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &fl_entry, -1);
if (fl_entry) {
profile = (profile_def *)fl_entry->data;
if (profile_exists(profile->name, FALSE) || profile_exists(profile->name, TRUE)) {
change_configuration_profile(profile->name);
} else if (!profile_exists(get_profile_name(), FALSE)) {
change_configuration_profile(NULL);
}
}
}
if (destroy) {
empty_profile_list(TRUE);
window_destroy(main_w);
}
}
static void
profile_apply(GtkWidget *main_w, GtkTreeView *profile_l, gboolean destroy)
{
const gchar *err_msg;
if ((err_msg = apply_profile_changes()) != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_msg);
return;
}
profile_select(main_w, profile_l, destroy);
}
static void
profile_dlg_ok_cb(GtkWidget *ok_bt, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(ok_bt);
GtkTreeView *profile_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY));
profile_apply(main_w, profile_l, TRUE);
}
static void
profile_dlg_apply_cb(GtkWidget *apply_bt, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(apply_bt);
GtkTreeView *profile_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY));
profile_apply(main_w, profile_l, FALSE);
}
static void
profile_dlg_cancel_cb(GtkWidget *cancel_bt, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(cancel_bt);
empty_profile_list(TRUE);
window_destroy(GTK_WIDGET(main_w));
}
static gboolean
profile_dlg_delete_event_cb(GtkWidget *main_w, GdkEvent *event _U_,
gpointer data)
{
profile_dlg_cancel_cb(main_w, data);
return FALSE;
}
static void
profile_dlg_destroy_cb(GtkWidget *w _U_, gpointer data _U_)
{
global_profile_w = NULL;
}
static gboolean
profile_button_press_cb(GtkWidget *list, GdkEventButton *event, gpointer data _U_)
{
if (event->type == GDK_2BUTTON_PRESS) {
GtkWidget *main_w = gtk_widget_get_toplevel(list);
profile_apply(main_w, GTK_TREE_VIEW(list), TRUE);
}
return FALSE;
}
static gboolean
profile_key_release_cb(GtkWidget *list, GdkEventKey *event, gpointer data _U_)
{
if ((event->keyval == GDK_Return) || (event->keyval == GDK_KP_Enter)) {
GtkWidget *main_w = gtk_widget_get_toplevel(list);
profile_apply(main_w, GTK_TREE_VIEW(list), TRUE);
}
return FALSE;
}
static void
profile_sel_list_cb(GtkTreeSelection *sel, gpointer data _U_)
{
GtkWidget *profile_l = GTK_WIDGET(gtk_tree_selection_get_tree_view(sel));
GtkWidget *main_w = gtk_widget_get_toplevel(profile_l);
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_NAME_TE_KEY);
GtkWidget *del_bt = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_DEL_BT_KEY);
profile_def *profile;
gchar *name = NULL;
GList *fl_entry;
gint sensitivity = FALSE;
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &fl_entry, -1);
if (fl_entry) {
profile = (profile_def *)fl_entry->data;
name = g_strdup(profile->name);
if ((profile->status != PROF_STAT_DEFAULT) && !profile->is_global) {
sensitivity = TRUE;
}
}
}
if (name_te != NULL) {
gtk_entry_set_text(GTK_ENTRY(name_te), name ? name : "");
gtk_widget_set_sensitive(name_te, sensitivity);
}
if (del_bt != NULL)
gtk_widget_set_sensitive(del_bt, sensitivity);
g_free(name);
}
static void
profile_new_bt_clicked_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_NAME_TE_KEY);
GtkTreeView *profile_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY));
GtkListStore *store;
GtkTreeIter iter;
GList *fl_entry;
const gchar *name = "New profile";
fl_entry = add_to_profile_list(name, "", PROF_STAT_NEW, FALSE, FALSE);
store = GTK_LIST_STORE(gtk_tree_view_get_model(profile_l));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, NAME_COLUMN, name, GLOBAL_COLUMN, FALSE, DATA_COLUMN, fl_entry, -1);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(profile_l), &iter);
gtk_editable_select_region(GTK_EDITABLE(name_te), 0, -1);
gtk_widget_grab_focus(name_te);
}
static void
profile_copy_bt_clicked_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_NAME_TE_KEY);
GtkTreeView *profile_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY));
GtkListStore *store;
GtkTreeIter iter;
GList *fl_entry;
const gchar *name = gtk_entry_get_text(GTK_ENTRY(name_te));
const gchar *parent = NULL;
gchar *new_name;
GtkTreeSelection *sel;
GtkTreeModel *model;
profile_def *profile = NULL;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(profile_l));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &fl_entry, -1);
if (fl_entry) {
profile = (profile_def *)fl_entry->data;
}
}
if (profile && profile->is_global) {
parent = profile->name;
} else {
parent = get_profile_parent(name);
}
if (profile && profile->is_global && !profile_exists(parent, FALSE)) {
new_name = g_strdup(name);
} else {
new_name = g_strdup_printf("%s (copy)", name);
}
fl_entry = add_to_profile_list(new_name, parent, PROF_STAT_COPY, FALSE, profile ? profile->from_global : FALSE);
store = GTK_LIST_STORE(gtk_tree_view_get_model(profile_l));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, NAME_COLUMN, new_name, GLOBAL_COLUMN, FALSE, DATA_COLUMN, fl_entry, -1);
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(profile_l), &iter);
gtk_editable_select_region(GTK_EDITABLE(name_te), 0, -1);
gtk_widget_grab_focus(name_te);
g_free(new_name);
}
static void
profile_name_te_changed_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_NAME_TE_KEY);
GtkWidget *profile_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY);
profile_def *profile;
GList *fl_entry;
const gchar *name;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(profile_l));
name = gtk_entry_get_text(GTK_ENTRY(name_te));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &fl_entry, -1);
if (fl_entry != NULL) {
profile = (profile_def *)fl_entry->data;
if ((strlen(name) > 0) && profile && !profile->is_global) {
if (profile->status != PROF_STAT_DEFAULT) {
g_free(profile->name);
profile->name = g_strdup(name);
if ((profile->status != PROF_STAT_NEW) &&
(profile->status != PROF_STAT_COPY)) {
profile->status = PROF_STAT_CHANGED;
}
gtk_list_store_set(GTK_LIST_STORE(model), &iter, NAME_COLUMN, name, -1);
}
}
}
}
}
static void
profile_del_bt_clicked_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *main_w = gtk_widget_get_toplevel(w);
GtkWidget *profile_l = (GtkWidget *)g_object_get_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY);
GList *fl_entry;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(profile_l));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, DATA_COLUMN, &fl_entry, -1);
if (fl_entry != NULL) {
remove_from_profile_list(fl_entry);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
}
}
if (gtk_tree_model_get_iter_first(model, &iter)) {
gtk_tree_selection_select_iter(sel, &iter);
}
}
static GtkWidget *
profile_dialog_new(void)
{
GtkWidget *main_w,
*main_vb,
*bbox,
*ok_bt,
*apply_bt,
*cancel_bt,
*help_bt;
GtkWidget *profile_vb,
*props_vb;
GtkWidget *top_hb,
*list_bb,
*new_bt,
*copy_bt,
*del_bt,
*profile_sc,
*profile_l,
*middle_hb,
*name_lb,
*name_te,
*profile_fr,
*edit_fr,
*props_fr;
GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
GtkTreeIter *l_select;
gboolean has_global = has_global_profiles();
main_w = dlg_conf_window_new("Wireshark: Configuration Profiles");
gtk_window_set_default_size(GTK_WINDOW(main_w), 400, 400);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(main_w), main_vb);
gtk_widget_show(main_vb);
profile_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(profile_vb), 0);
gtk_box_pack_start(GTK_BOX(main_vb), profile_vb, TRUE, TRUE, 0);
gtk_widget_show(profile_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(profile_vb), top_hb, TRUE, TRUE, 0);
gtk_widget_show(top_hb);
edit_fr = gtk_frame_new("Edit");
gtk_box_pack_start(GTK_BOX(top_hb), edit_fr, FALSE, FALSE, 0);
gtk_widget_show(edit_fr);
list_bb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width(GTK_CONTAINER(list_bb), 5);
gtk_container_add(GTK_CONTAINER(edit_fr), list_bb);
gtk_widget_show(list_bb);
new_bt = ws_gtk_button_new_from_stock(GTK_STOCK_NEW);
g_signal_connect(new_bt, "clicked", G_CALLBACK(profile_new_bt_clicked_cb), NULL);
gtk_widget_show(new_bt);
gtk_box_pack_start(GTK_BOX(list_bb), new_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(new_bt, "Create a new profile (with default properties)");
copy_bt = ws_gtk_button_new_from_stock(GTK_STOCK_COPY);
g_signal_connect(copy_bt, "clicked", G_CALLBACK(profile_copy_bt_clicked_cb), NULL);
gtk_widget_show(copy_bt);
gtk_box_pack_start(GTK_BOX(list_bb), copy_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(copy_bt, "Copy the selected profile");
del_bt = ws_gtk_button_new_from_stock(GTK_STOCK_DELETE);
gtk_widget_set_sensitive(del_bt, FALSE);
g_signal_connect(del_bt, "clicked", G_CALLBACK(profile_del_bt_clicked_cb), NULL);
g_object_set_data(G_OBJECT(main_w), E_PROF_DEL_BT_KEY, del_bt);
gtk_widget_show(del_bt);
gtk_box_pack_start(GTK_BOX(list_bb), del_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text(del_bt, "Delete the selected profile");
profile_fr = gtk_frame_new("Configuration Profiles");
gtk_box_pack_start(GTK_BOX(top_hb), profile_fr, TRUE, TRUE, 0);
gtk_widget_show(profile_fr);
profile_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(profile_sc),
GTK_SHADOW_IN);
gtk_container_set_border_width(GTK_CONTAINER(profile_sc), 5);
gtk_container_add(GTK_CONTAINER(profile_fr), profile_sc);
gtk_widget_show(profile_sc);
store = gtk_list_store_new(NUM_COLUMNS, G_TYPE_STRING, G_TYPE_BOOLEAN, G_TYPE_POINTER);
profile_l = tree_view_new(GTK_TREE_MODEL(store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(profile_l), has_global);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", NAME_COLUMN, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, NAME_COLUMN);
gtk_tree_view_append_column(GTK_TREE_VIEW(profile_l), column);
renderer = gtk_cell_renderer_toggle_new();
column = gtk_tree_view_column_new_with_attributes("Global", renderer, "active", GLOBAL_COLUMN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(profile_l), column);
gtk_widget_set_tooltip_text(gtk_tree_view_column_get_button(column),
"Global profiles will be copied to users profiles when used");
gtk_tree_view_column_set_visible(column, has_global);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(profile_l));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
g_signal_connect(sel, "changed", G_CALLBACK(profile_sel_list_cb), profile_vb);
g_signal_connect(profile_l, "button_press_event", G_CALLBACK(profile_button_press_cb), NULL);
g_signal_connect(profile_l, "key_release_event", G_CALLBACK(profile_key_release_cb), NULL);
g_object_set_data(G_OBJECT(main_w), E_PROF_PROFILE_L_KEY, profile_l);
gtk_container_add(GTK_CONTAINER(profile_sc), profile_l);
gtk_widget_show(profile_l);
l_select = fill_list(main_w);
g_object_unref(G_OBJECT(store));
props_fr = gtk_frame_new("Properties");
gtk_box_pack_start(GTK_BOX(profile_vb), props_fr, FALSE, FALSE, 0);
gtk_widget_show(props_fr);
props_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(props_vb), 5);
gtk_container_add(GTK_CONTAINER(props_fr), props_vb);
gtk_widget_show(props_vb);
middle_hb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(props_vb), middle_hb, TRUE, TRUE, 0);
gtk_widget_show(middle_hb);
name_lb = gtk_label_new("Profile name:");
gtk_box_pack_start(GTK_BOX(middle_hb), name_lb, FALSE, FALSE, 0);
gtk_widget_show(name_lb);
name_te = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(middle_hb), name_te, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(main_w), E_PROF_NAME_TE_KEY, name_te);
g_signal_connect(name_te, "changed", G_CALLBACK(profile_name_te_changed_cb), NULL);
#ifdef _WIN32
gtk_widget_set_tooltip_text(name_te,
"A profile name cannot start or end with a period (.), and cannot"
" contain any of the following characters:\n \\ / : * ? \" < > |");
#else
gtk_widget_set_tooltip_text(name_te, "A profile name cannot contain the '/' character");
#endif
gtk_widget_show(name_te);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(profile_dlg_ok_cb), NULL);
gtk_widget_set_tooltip_text(ok_bt, "Apply the profiles and close this dialog");
dlg_set_activate(name_te, ok_bt);
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(profile_dlg_apply_cb), NULL);
gtk_widget_set_tooltip_text(apply_bt, "Apply the profiles and keep this dialog open");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel the changes");
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(profile_dlg_cancel_cb), NULL);
window_set_cancel_button(main_w, cancel_bt, NULL);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_CONFIG_PROFILES_DIALOG);
gtk_widget_set_tooltip_text(help_bt, "Show topic specific help");
if (ok_bt) {
gtk_widget_grab_default(ok_bt);
}
if (l_select) {
gtk_tree_selection_select_iter(sel, l_select);
g_free(l_select);
}
if (profile_l) {
gtk_widget_grab_focus(profile_l);
}
g_signal_connect(main_w, "delete_event", G_CALLBACK(profile_dlg_delete_event_cb), NULL);
g_signal_connect(main_w, "destroy", G_CALLBACK(profile_dlg_destroy_cb), NULL);
gtk_widget_show(main_w);
window_present(main_w);
return main_w;
}
static void
select_profile_cb(GtkWidget *w _U_, gpointer data)
{
const gchar *current_profile = get_profile_name();
gchar *selected_profile = (gchar *)data;
if (strcmp(selected_profile, current_profile) != 0) {
change_configuration_profile(selected_profile);
}
}
gboolean
profile_show_popup_cb(GtkWidget *w _U_, GdkEvent *event, gpointer user_data _U_)
{
GdkEventButton *bevent = (GdkEventButton *)event;
const gchar *profile_name = get_profile_name();
GList *fl_entry;
profile_def *profile;
GtkWidget *menu;
GtkWidget *menu_item;
GtkWidget *sub_menu = NULL;
menu = gtk_menu_new();
if (bevent->button != 1) {
GtkWidget *change_menu = menus_get_profiles_change_menu();
#if GTK_CHECK_VERSION(2,16,0)
GtkWidget *rename_menu = menus_get_profiles_rename_menu();
GtkWidget *delete_menu = menus_get_profiles_delete_menu();
if (strcmp(profile_name, DEFAULT_PROFILE) != 0) {
gchar *label;
label = g_strdup_printf("Rename \"%s\"...", profile_name);
gtk_menu_item_set_label(GTK_MENU_ITEM(rename_menu), label);
g_free(label);
label = g_strdup_printf("Delete \"%s\"", profile_name);
gtk_menu_item_set_label(GTK_MENU_ITEM(delete_menu), label);
g_free(label);
} else {
gtk_menu_item_set_label(GTK_MENU_ITEM(rename_menu), "Rename...");
gtk_menu_item_set_label(GTK_MENU_ITEM(delete_menu), "Delete");
}
#endif
gtk_menu_item_set_submenu(GTK_MENU_ITEM(change_menu), menu);
}
init_profile_list();
fl_entry = current_profile_list();
while (fl_entry && fl_entry->data) {
profile = (profile_def *)fl_entry->data;
if (!profile->is_global) {
menu_item = gtk_check_menu_item_new_with_label(profile->name);
if (strcmp(profile->name, profile_name)==0) {
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_item), TRUE);
}
g_object_set(G_OBJECT(menu_item), "draw-as-radio", TRUE, NULL);
g_signal_connect(menu_item, "activate", G_CALLBACK(select_profile_cb), g_strdup(profile->name));
gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
gtk_widget_show(menu_item);
} else {
if (!sub_menu) {
menu_item = gtk_separator_menu_item_new();
gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
gtk_widget_show(menu_item);
menu_item = gtk_menu_item_new_with_label("New from Global");
gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
gtk_widget_show(menu_item);
sub_menu = gtk_menu_new();
gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), sub_menu);
}
menu_item = gtk_menu_item_new_with_label(profile->name);
g_signal_connect(menu_item, "activate", G_CALLBACK(select_profile_cb), g_strdup(profile->name));
if (profile_exists(profile->name, FALSE)) {
gtk_widget_set_sensitive(menu_item, FALSE);
}
gtk_menu_shell_append(GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show(menu_item);
}
fl_entry = g_list_next(fl_entry);
}
if (bevent->button != 1) {
return FALSE;
}
gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL,
bevent->button, bevent->time);
return TRUE;
}
static void
profile_name_edit_ok(GtkWidget *w _U_, gpointer parent_w)
{
gint operation = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(w), "operation"));
GtkComboBox *combo_box = (GtkComboBox *)g_object_get_data(G_OBJECT(w), "create_from");
GtkWidget *entry = (GtkWidget *)g_object_get_data(G_OBJECT(w), "entry");
GtkTreeStore *store;
GtkTreeIter iter;
const gchar *new_name = gtk_entry_get_text(GTK_ENTRY(entry));
const gchar *profile_name = "";
gboolean from_global = FALSE;
char *pf_dir_path, *pf_dir_path2, *pf_filename;
if ((strlen(new_name) == 0) || (profile_name_is_valid(new_name) != NULL)) {
return;
}
switch (operation) {
case PROF_OPERATION_NEW:
if (gtk_combo_box_get_active_iter(combo_box, &iter)) {
store = GTK_TREE_STORE(gtk_combo_box_get_model(combo_box));
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter, 0, &profile_name, 1, &from_global, -1);
}
break;
case PROF_OPERATION_RENAME:
profile_name = get_profile_name();
if (strcmp(new_name, profile_name) == 0) {
window_destroy(GTK_WIDGET(parent_w));
return;
}
break;
default:
g_assert_not_reached();
}
if (profile_exists(new_name, FALSE)) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"The profile already exists:\n%s.", new_name);
return;
}
write_profile_recent();
switch (operation) {
case PROF_OPERATION_NEW:
if (create_persconffile_profile(new_name, &pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
} else if (strlen(profile_name) &&
(copy_persconffile_profile(new_name, profile_name, from_global, &pf_filename,
&pf_dir_path, &pf_dir_path2) != 0))
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't copy file \"%s\" in directory\n\"%s\" to\n\"%s\":\n%s.",
pf_filename, pf_dir_path2, pf_dir_path, g_strerror(errno));
g_free(pf_filename);
g_free(pf_dir_path);
g_free(pf_dir_path2);
} else {
change_configuration_profile(new_name);
}
break;
case PROF_OPERATION_RENAME:
if (rename_persconffile_profile(profile_name, new_name,
&pf_dir_path, &pf_dir_path2) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't rename directory\n\"%s\" to\n\"%s\":\n%s.",
pf_dir_path, pf_dir_path2, g_strerror(errno));
g_free(pf_dir_path);
g_free(pf_dir_path2);
} else {
change_configuration_profile(new_name);
}
break;
default:
g_assert_not_reached();
}
window_destroy(GTK_WIDGET(parent_w));
}
static void
profile_rename_cancel(GtkWidget *w _U_, gpointer parent_w)
{
window_destroy(GTK_WIDGET(parent_w));
}
static void
profile_manage_profiles_dlg(gint operation)
{
GtkWidget *win, *main_grid, *main_vb, *bbox, *cancel_bt, *ok_bt;
GtkWidget *entry, *label;
GtkWidget *combo_box = NULL;
GtkCellRenderer *cell;
GtkTreeStore *store;
GtkTreeIter iter, parent;
gchar *window_title = NULL;
GList *fl_entry;
profile_def *profile;
const gchar *profile_name;
gboolean has_global = has_global_profiles();
profile_name = get_profile_name();
switch (operation) {
case PROF_OPERATION_NEW:
window_title = g_strdup("Create New Profile");
break;
case PROF_OPERATION_RENAME:
window_title = g_strdup_printf("Rename: %s", profile_name);
break;
default:
g_assert_not_reached();
}
win = dlg_window_new(window_title);
g_free(window_title);
gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
gtk_window_resize(GTK_WINDOW(win), 400, 100);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 5, FALSE);
gtk_container_add(GTK_CONTAINER(win), main_vb);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
main_grid = ws_gtk_grid_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_grid, FALSE, FALSE, 0);
ws_gtk_grid_set_column_spacing(GTK_GRID(main_grid), 10);
ws_gtk_grid_set_row_spacing(GTK_GRID(main_grid), 5);
if (operation == PROF_OPERATION_NEW) {
label = gtk_label_new("Create from:");
gtk_widget_set_tooltip_text(label, "All configuration files will be copied from this profile");
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), label, 0, 0, 1, 1);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
store = gtk_tree_store_new(3, G_TYPE_STRING, G_TYPE_BOOLEAN, G_TYPE_BOOLEAN);
combo_box = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
gtk_widget_set_tooltip_text(combo_box, "All configuration files will be copied from this profile");
cell = gtk_cell_renderer_text_new();
gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_box), cell, TRUE);
gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo_box), cell,
"text", 0, "sensitive", 2,
NULL);
gtk_tree_store_append(store, &iter, NULL);
gtk_tree_store_set(store, &iter, 0, "", 1, FALSE, 2, TRUE, -1);
if (has_global) {
gtk_tree_store_append(store, &parent, NULL);
gtk_tree_store_set(store, &parent, 0, "Personal", 1, FALSE, 2, FALSE, -1);
}
init_profile_list();
fl_entry = current_profile_list();
while (fl_entry && fl_entry->data) {
profile = (profile_def *)fl_entry->data;
if (!profile->is_global) {
gtk_tree_store_append(store, &iter, has_global ? &parent : NULL);
gtk_tree_store_set(store, &iter, 0, profile->name, 1, FALSE, 2, TRUE, -1);
}
fl_entry = g_list_next(fl_entry);
}
if (has_global) {
gtk_tree_store_append(store, &parent, NULL);
gtk_tree_store_set(store, &parent, 0, "Global", 1, FALSE, 2, FALSE, -1);
fl_entry = current_profile_list();
while (fl_entry && fl_entry->data) {
profile = (profile_def *)fl_entry->data;
if (profile->is_global) {
gtk_tree_store_append(store, &iter, &parent);
gtk_tree_store_set(store, &iter, 0, profile->name, 1, TRUE, 2, TRUE, -1);
}
fl_entry = g_list_next(fl_entry);
}
}
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), combo_box, 1, 0, 1, 1);
g_object_unref(store);
}
label = gtk_label_new("Profile name:");
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), label, 0, 1, 1, 1);
gtk_misc_set_alignment(GTK_MISC(label), 1.0f, 0.5f);
entry = gtk_entry_new();
ws_gtk_grid_attach_defaults(GTK_GRID(main_grid), entry, 1, 1, 1, 1);
switch (operation) {
case PROF_OPERATION_NEW:
gtk_entry_set_text(GTK_ENTRY(entry), "New profile");
break;
case PROF_OPERATION_RENAME:
gtk_entry_set_text(GTK_ENTRY(entry), profile_name);
break;
default:
g_assert_not_reached();
break;
}
#ifdef _WIN32
gtk_widget_set_tooltip_text(entry,
"A profile name cannot start or end with a period (.), and cannot"
" contain any of the following characters:\n \\ / : * ? \" < > |");
#else
gtk_widget_set_tooltip_text(entry, "A profile name cannot contain the '/' character");
#endif
bbox = dlg_button_row_new(GTK_STOCK_CANCEL, GTK_STOCK_OK, NULL);
gtk_box_pack_end(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_object_set_data(G_OBJECT(ok_bt), "entry", entry);
g_object_set_data(G_OBJECT(ok_bt), "create_from", combo_box);
g_object_set_data(G_OBJECT(ok_bt), "operation", GINT_TO_POINTER(operation));
g_signal_connect(ok_bt, "clicked", G_CALLBACK(profile_name_edit_ok), win);
dlg_set_activate(entry, ok_bt);
gtk_widget_grab_focus(entry);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
g_signal_connect(cancel_bt, "clicked", G_CALLBACK(profile_rename_cancel), win);
window_set_cancel_button(win, cancel_bt, NULL);
gtk_widget_grab_default(ok_bt);
gtk_widget_show_all(win);
}
void
profile_new_cb(GtkWidget *w _U_, gpointer data _U_)
{
profile_manage_profiles_dlg(PROF_OPERATION_NEW);
}
void
profile_delete_cb(GtkWidget *w _U_, gpointer data _U_)
{
if (delete_current_profile()) {
change_configuration_profile(NULL);
}
}
void
profile_rename_cb(GtkWidget *w _U_, gpointer data _U_)
{
profile_manage_profiles_dlg(PROF_OPERATION_RENAME);
}
void
profile_dialog_cb(GtkWidget *w _U_)
{
if (global_profile_w != NULL) {
reactivate_window(global_profile_w);
} else {
global_profile_w = profile_dialog_new();
}
}
