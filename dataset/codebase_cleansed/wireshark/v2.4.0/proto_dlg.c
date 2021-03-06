static void
proto_col_clicked_cb(GtkWidget *col _U_, GtkWidget *proto_list) {
gtk_widget_grab_focus(proto_list);
}
static void
status_toggled(GtkCellRendererToggle *cell _U_, gchar *path_str, gpointer data)
{
GtkTreeModel *model = (GtkTreeModel *)data;
GtkTreeIter iter;
GtkTreePath *path = gtk_tree_path_new_from_string(path_str);
protocol_data_t *p;
gtk_tree_model_get_iter(model, &iter, path);
gtk_tree_model_get(model, &iter, PROTO_DATA_COLUMN, &p, -1);
if (p->enabled)
p->enabled = FALSE;
else
p->enabled = TRUE;
gtk_list_store_set(GTK_LIST_STORE(model), &iter, ENABLE_COLUMN, p->enabled, -1);
gtk_tree_path_free(path);
}
static void
heur_status_toggled(GtkCellRendererToggle *cell _U_, gchar *path_str, gpointer data)
{
GtkTreeModel *model = (GtkTreeModel *)data;
GtkTreeIter iter;
GtkTreePath *path = gtk_tree_path_new_from_string(path_str);
heur_protocol_data_t *p;
gtk_tree_model_get_iter(model, &iter, path);
gtk_tree_model_get(model, &iter, PROTO_DATA_COLUMN, &p, -1);
if (p->enabled)
p->enabled = FALSE;
else
p->enabled = TRUE;
gtk_list_store_set(GTK_LIST_STORE(model), &iter, ENABLE_COLUMN, p->enabled, -1);
gtk_tree_path_free(path);
}
static gboolean toggle_all(const void *key _U_, void *value, void *userdata)
{
GtkListStore *s = (GtkListStore *)userdata;
protocol_data_t *p = (protocol_data_t *)value;
if (p->enabled)
p->enabled = FALSE;
else
p->enabled = TRUE;
gtk_list_store_set(s, &p->iter, ENABLE_COLUMN, p->enabled, -1);
return FALSE;
}
static void
toggle_all_cb(GtkWidget *button _U_, gpointer pl)
{
wmem_tree_foreach(protocol_list, toggle_all, GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(pl))));
}
static gboolean active_all(const void *key _U_, void *value, void *userdata)
{
struct active_all_data* data = (struct active_all_data*)userdata;
protocol_data_t *p = (protocol_data_t *)value;
p->enabled = data->new_state;
gtk_list_store_set(data->s, &p->iter, ENABLE_COLUMN, data->new_state, -1);
return FALSE;
}
static void
set_active_all(GtkWidget *w, gboolean new_state)
{
struct active_all_data data;
data.s = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(w)));
data.new_state = new_state;
wmem_tree_foreach(protocol_list, active_all, &data);
}
static void
enable_all_cb(GtkWidget *button _U_, gpointer pl)
{
set_active_all((GtkWidget *)pl, TRUE);
}
static void
disable_all_cb(GtkWidget *button _U_, gpointer pl)
{
set_active_all((GtkWidget *)pl, FALSE);
}
static void heur_toggle_all_cb(GtkWidget *button _U_, gpointer pl)
{
wmem_tree_foreach(heur_protocol_list, toggle_all, GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(pl))));
}
static void
heur_set_active_all(GtkWidget *w, gboolean new_state)
{
struct active_all_data data;
data.s = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(w)));
data.new_state = new_state;
wmem_tree_foreach(heur_protocol_list, active_all, &data);
}
static void heur_enable_all_cb(GtkWidget *button _U_, gpointer pl)
{
heur_set_active_all((GtkWidget *)pl, TRUE);
}
static void heur_disable_all_cb(GtkWidget *button _U_, gpointer pl)
{
heur_set_active_all((GtkWidget *)pl, FALSE);
}
static void
proto_destroy_cb(GtkWidget *w _U_, gpointer data _U_)
{
proto_w = NULL;
if (protocol_list) {
wmem_tree_destroy(protocol_list, TRUE, TRUE);
protocol_list = NULL;
}
}
static void
heur_proto_destroy_cb(GtkWidget *w _U_, gpointer data _U_)
{
proto_w = NULL;
if (heur_protocol_list) {
wmem_tree_destroy(heur_protocol_list, TRUE, TRUE);
heur_protocol_list = NULL;
}
}
static gboolean set_proto_was_enabled(const void *key _U_, void *value, void *userdata _U_)
{
protocol_data_t *p = (protocol_data_t *)value;
p->was_enabled = p->enabled;
return FALSE;
}
static gboolean set_heur_was_enabled(const void *key _U_, void *value, void *userdata _U_)
{
heur_protocol_data_t *p = (heur_protocol_data_t *)value;
p->was_enabled = p->enabled;
return FALSE;
}
static void
update_was_enabled(void)
{
wmem_tree_foreach(protocol_list, set_proto_was_enabled, NULL);
wmem_tree_foreach(heur_protocol_list, set_heur_was_enabled, NULL);
}
static void
proto_write(gpointer parent_w _U_)
{
save_enabled_and_disabled_lists();
}
static void
proto_ok_cb(GtkWidget *ok_bt _U_, gpointer parent_w)
{
gboolean redissect;
redissect = set_proto_selection(GTK_WIDGET(parent_w));
if (!prefs.gui_use_pref_save) {
proto_write(parent_w);
}
window_destroy(GTK_WIDGET(parent_w));
if (redissect)
redissect_packets();
}
static void
proto_apply_cb(GtkWidget *apply_bt _U_, gpointer parent_w)
{
gboolean redissect;
redissect = set_proto_selection(GTK_WIDGET(parent_w));
if (!prefs.gui_use_pref_save) {
proto_write(parent_w);
update_was_enabled();
}
if (redissect)
redissect_packets();
}
static void
proto_save_cb(GtkWidget *save_bt _U_, gpointer parent_w)
{
proto_write(parent_w);
if (set_proto_selection(GTK_WIDGET(parent_w))) {
redissect_packets();
}
}
static void
proto_cancel_cb(GtkWidget *cancel_bt _U_, gpointer parent_w)
{
gboolean redissect;
redissect = revert_proto_selection();
window_destroy(GTK_WIDGET(parent_w));
if (redissect)
redissect_packets();
}
static gboolean
proto_delete_event_cb(GtkWidget *proto_w_lcl, GdkEvent *event _U_,
gpointer dummy _U_)
{
proto_cancel_cb(NULL, proto_w_lcl);
return FALSE;
}
static gboolean set_proto_decoding(const void *key _U_, void *value, void *userdata)
{
protocol_data_t *p = (protocol_data_t *)value;
gboolean* need_redissect = (gboolean*)userdata;
protocol_t *protocol;
protocol = find_protocol_by_id(p->hfinfo_index);
if (proto_is_protocol_enabled(protocol) != p->enabled) {
proto_set_decoding(p->hfinfo_index, p->enabled);
*need_redissect = TRUE;
}
return FALSE;
}
static gboolean set_heur_decoding(const void *key _U_, void *value, void *userdata)
{
heur_protocol_data_t *p = (heur_protocol_data_t *)value;
gboolean* need_redissect = (gboolean*)userdata;
heur_dtbl_entry_t* h;
h = find_heur_dissector_by_unique_short_name(p->abbrev);
if ((h != NULL) && (h->enabled != p->enabled)) {
h->enabled = p->enabled;
*need_redissect = TRUE;
}
return FALSE;
}
static gboolean
set_proto_selection(GtkWidget *parent_w _U_)
{
gboolean need_redissect = FALSE;
wmem_tree_foreach(protocol_list, set_proto_decoding, &need_redissect);
wmem_tree_foreach(heur_protocol_list, set_heur_decoding, &need_redissect);
return need_redissect;
}
static gboolean revert_proto_decoding(const void *key _U_, void *value, void *userdata)
{
protocol_data_t *p = (protocol_data_t *)value;
gboolean* need_redissect = (gboolean*)userdata;
protocol_t *protocol;
protocol = find_protocol_by_id(p->hfinfo_index);
if (proto_is_protocol_enabled(protocol) != p->was_enabled) {
proto_set_decoding(p->hfinfo_index, p->was_enabled);
*need_redissect = TRUE;
}
return FALSE;
}
static gboolean revert_heur_decoding(const void *key _U_, void *value, void *userdata)
{
heur_protocol_data_t *p = (heur_protocol_data_t *)value;
gboolean* need_redissect = (gboolean*)userdata;
heur_dtbl_entry_t* h;
h = find_heur_dissector_by_unique_short_name(p->abbrev);
if ((h != NULL) && (h->enabled != p->was_enabled)) {
h->enabled = p->was_enabled;
*need_redissect = TRUE;
}
return FALSE;
}
static gboolean
revert_proto_selection(void)
{
gboolean need_redissect = FALSE;
wmem_tree_foreach(protocol_list, revert_proto_decoding, &need_redissect);
wmem_tree_foreach(heur_protocol_list, revert_heur_decoding, &need_redissect);
return need_redissect;
}
static void
create_protocol_list(void)
{
gint i;
void *cookie;
protocol_t *protocol;
protocol_data_t *p;
if (protocol_list == NULL) {
protocol_list = wmem_tree_new(NULL);
}
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
if (proto_can_toggle_protocol(i)) {
p = wmem_new(NULL, protocol_data_t);
protocol = find_protocol_by_id(i);
p->name = proto_get_protocol_name(i);
p->abbrev = proto_get_protocol_short_name(protocol);
p->hfinfo_index = i;
p->enabled = proto_is_protocol_enabled(protocol);
p->was_enabled = p->enabled;
wmem_tree_insert_string(protocol_list, p->abbrev, p, 0);
}
}
}
static gboolean show_proto_func(const void *key _U_, void *value, void *userdata)
{
protocol_data_t *p = (protocol_data_t *)value;
GtkListStore *proto_store = (GtkListStore*)userdata;
gtk_list_store_append(proto_store, &p->iter);
gtk_list_store_set(proto_store, &p->iter,
ENABLE_COLUMN, p->enabled,
PROTOCOL_COLUMN, p->abbrev,
DESCRIPTION_COLUMN, p->name,
PROTO_DATA_COLUMN, p,
-1);
return FALSE;
}
static void
show_proto_selection(GtkListStore *proto_store)
{
if (protocol_list == NULL)
create_protocol_list();
wmem_tree_foreach(protocol_list, show_proto_func, proto_store);
}
static void
populate_heur_dissector_table_entries(const char *table_name _U_,
heur_dtbl_entry_t *dtbl_entry, gpointer user_data _U_)
{
heur_protocol_data_t *p;
if (dtbl_entry->protocol) {
p = wmem_new(NULL, heur_protocol_data_t);
p->name = dtbl_entry->display_name;
p->abbrev = dtbl_entry->short_name;
p->enabled = dtbl_entry->enabled;
p->list_name = dtbl_entry->list_name;
p->was_enabled = p->enabled;
if (heur_protocol_list == NULL) {
heur_protocol_list = wmem_tree_new(NULL);
}
wmem_tree_insert_string(heur_protocol_list, p->abbrev, p, 0);
}else{
g_warning("no protocol info");
}
}
static void
populate_heur_dissector_tables(const char *table_name, struct heur_dissector_list *list, gpointer w)
{
if (list) {
heur_dissector_table_foreach(table_name, populate_heur_dissector_table_entries, w);
}
}
static gboolean show_heur_func(const void *key _U_, void *value, void *userdata)
{
heur_protocol_data_t *p = (heur_protocol_data_t*)value;
GtkListStore *proto_store = (GtkListStore*)userdata;
gtk_list_store_append(proto_store, &p->iter);
gtk_list_store_set(proto_store, &p->iter,
ENABLE_COLUMN, p->enabled,
PROTOCOL_COLUMN, p->name,
HEUR_SHORT_NAME_COLUMN, p->abbrev,
PROTO_DATA_COLUMN, p,
-1);
return FALSE;
}
static void
show_heur_selection(GtkListStore *proto_store)
{
if (heur_protocol_list == NULL)
dissector_all_heur_tables_foreach_table(populate_heur_dissector_tables, NULL, NULL);
wmem_tree_foreach(heur_protocol_list, show_heur_func, proto_store);
}
static void
proto_disable_dialog_cb(gpointer dialog _U_, gint btn, gpointer data)
{
protocol_t *protocol;
gint id = GPOINTER_TO_INT(data);
if (btn == ESD_BTN_OK) {
if (protocol_list == NULL)
create_protocol_list();
protocol = find_protocol_by_id(id);
if (proto_is_protocol_enabled(protocol) == TRUE) {
if (proto_can_toggle_protocol(id) == TRUE) {
proto_set_decoding(id, FALSE);
redissect_packets();
}
}
}
}
void
proto_disable_cb(GtkWidget *w _U_, gpointer data _U_)
{
header_field_info *hfinfo;
gint id;
gpointer dialog;
if (cfile.finfo_selected == NULL) {
return;
}
hfinfo = cfile.finfo_selected->hfinfo;
if (hfinfo->parent == -1)
id = proto_get_id((protocol_t *)hfinfo->strings);
else
id = hfinfo->parent;
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_OK_CANCEL,
"Do you want to temporarily disable protocol: %s ?",
proto_registrar_get_abbrev(id));
simple_dialog_set_cb(dialog, proto_disable_dialog_cb, GINT_TO_POINTER(id));
}
static GtkWidget *
build_heur_dissectors_treeview(void)
{
GtkWidget *bbox, *proto_list, *label, *proto_sw, *proto_vb, *button,
*ok_bt, *apply_bt, *save_bt, *cancel_bt, *help_bt;
static const gchar *titles[] = { "Status", "Heuristic Protocol", "Short name"};
GtkListStore *proto_store;
GtkCellRenderer *proto_rend;
GtkTreeViewColumn *proto_col;
proto_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_widget_show(proto_vb);
proto_sw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(proto_sw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(proto_vb), proto_sw, TRUE, TRUE, 0);
gtk_widget_show(proto_sw);
proto_store = gtk_list_store_new(4, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_POINTER);
show_heur_selection(proto_store);
gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(proto_store), PROTOCOL_COLUMN,
GTK_SORT_ASCENDING);
proto_list = tree_view_new(GTK_TREE_MODEL(proto_store));
gtk_container_add(GTK_CONTAINER(proto_sw), proto_list);
proto_rend = gtk_cell_renderer_toggle_new();
g_signal_connect(proto_rend, "toggled", G_CALLBACK(heur_status_toggled), proto_store);
proto_col = gtk_tree_view_column_new_with_attributes(titles[ENABLE_COLUMN], proto_rend, "active", ENABLE_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, ENABLE_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
proto_rend = gtk_cell_renderer_text_new();
proto_col = gtk_tree_view_column_new_with_attributes(titles[PROTOCOL_COLUMN], proto_rend, "text", PROTOCOL_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, PROTOCOL_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
proto_rend = gtk_cell_renderer_text_new();
proto_col = gtk_tree_view_column_new_with_attributes(titles[HEUR_SHORT_NAME_COLUMN], proto_rend, "text", HEUR_SHORT_NAME_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, HEUR_SHORT_NAME_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(proto_list), PROTOCOL_COLUMN);
g_object_unref(G_OBJECT(proto_store));
gtk_widget_show(proto_list);
label = gtk_label_new("Disabling a heuristic protocol prevents higher layer protocols from being displayed");
gtk_misc_set_alignment(GTK_MISC(label), 0.5f, 0.5f);
gtk_widget_show(label);
gtk_box_pack_start(GTK_BOX(proto_vb), label, FALSE, FALSE, 5);
bbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_button_box_set_layout(GTK_BUTTON_BOX(bbox), GTK_BUTTONBOX_END);
gtk_box_set_spacing(GTK_BOX(bbox), 5);
gtk_box_pack_start(GTK_BOX(proto_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
button = gtk_button_new_with_label("Enable All");
g_signal_connect(button, "clicked", G_CALLBACK(heur_enable_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
button = gtk_button_new_with_label("Disable All");
g_signal_connect(button, "clicked", G_CALLBACK(heur_disable_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
button = gtk_button_new_with_label("Invert");
g_signal_connect(button, "clicked", G_CALLBACK(heur_toggle_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(proto_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(proto_ok_cb), proto_w);
gtk_widget_grab_default(ok_bt);
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(proto_apply_cb), proto_w);
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(proto_save_cb), proto_w);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(proto_w, cancel_bt, proto_cancel_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_ENABLED_HEURISTICS_DIALOG);
g_signal_connect(proto_w, "delete_event", G_CALLBACK(proto_delete_event_cb), NULL);
g_signal_connect(proto_w, "destroy", G_CALLBACK(heur_proto_destroy_cb), NULL);
gtk_widget_show(proto_w);
gtk_widget_grab_focus(proto_list);
if(!prefs.gui_use_pref_save) {
gtk_widget_hide(save_bt);
}
return proto_vb;
}
static GtkWidget *
build_protocols_treeview(void)
{
GtkWidget *bbox, *proto_list, *label, *proto_sw, *proto_vb, *button,
*ok_bt, *apply_bt, *save_bt, *cancel_bt, *help_bt;
static const gchar *titles[] = { "Status", "Protocol", "Description" };
GtkListStore *proto_store;
GtkCellRenderer *proto_rend;
GtkTreeViewColumn *proto_col;
proto_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_widget_show(proto_vb);
proto_sw = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(proto_sw),
GTK_SHADOW_IN);
gtk_box_pack_start(GTK_BOX(proto_vb), proto_sw, TRUE, TRUE, 0);
gtk_widget_show(proto_sw);
proto_store = gtk_list_store_new(4, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_POINTER);
show_proto_selection(proto_store);
gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(proto_store), PROTOCOL_COLUMN,
GTK_SORT_ASCENDING);
proto_list = tree_view_new(GTK_TREE_MODEL(proto_store));
gtk_container_add(GTK_CONTAINER(proto_sw), proto_list);
proto_rend = gtk_cell_renderer_toggle_new();
g_signal_connect(proto_rend, "toggled", G_CALLBACK(status_toggled), proto_store);
proto_col = gtk_tree_view_column_new_with_attributes(titles[ENABLE_COLUMN], proto_rend, "active", ENABLE_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, ENABLE_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
proto_rend = gtk_cell_renderer_text_new();
proto_col = gtk_tree_view_column_new_with_attributes(titles[PROTOCOL_COLUMN], proto_rend, "text", PROTOCOL_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, PROTOCOL_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
proto_rend = gtk_cell_renderer_text_new();
proto_col = gtk_tree_view_column_new_with_attributes(titles[DESCRIPTION_COLUMN], proto_rend, "text", DESCRIPTION_COLUMN, NULL);
gtk_tree_view_column_set_sort_column_id(proto_col, DESCRIPTION_COLUMN);
g_signal_connect(proto_col, "clicked", G_CALLBACK(proto_col_clicked_cb), proto_list);
gtk_tree_view_append_column(GTK_TREE_VIEW(proto_list), proto_col);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(proto_list), PROTOCOL_COLUMN);
g_object_unref(G_OBJECT(proto_store));
gtk_widget_show(proto_list);
label = gtk_label_new("Disabling a protocol prevents higher layer protocols from being displayed");
gtk_misc_set_alignment(GTK_MISC(label), 0.5f, 0.5f);
gtk_widget_show(label);
gtk_box_pack_start(GTK_BOX(proto_vb), label, FALSE, FALSE, 5);
bbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_button_box_set_layout(GTK_BUTTON_BOX(bbox), GTK_BUTTONBOX_END);
gtk_box_set_spacing(GTK_BOX(bbox), 5);
gtk_box_pack_start(GTK_BOX(proto_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
button = gtk_button_new_with_label("Enable All");
g_signal_connect(button, "clicked", G_CALLBACK(enable_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
button = gtk_button_new_with_label("Disable All");
g_signal_connect(button, "clicked", G_CALLBACK(disable_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
button = gtk_button_new_with_label("Invert");
g_signal_connect(button, "clicked", G_CALLBACK(toggle_all_cb), proto_list);
gtk_box_pack_start(GTK_BOX(bbox), button, TRUE, TRUE, 0);
gtk_widget_show(button);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_APPLY, GTK_STOCK_SAVE, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(proto_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(proto_ok_cb), proto_w);
gtk_widget_grab_default(ok_bt);
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(apply_bt, "clicked", G_CALLBACK(proto_apply_cb), proto_w);
save_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(save_bt, "clicked", G_CALLBACK(proto_save_cb), proto_w);
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(proto_w, cancel_bt, proto_cancel_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_ENABLED_PROTOCOLS_DIALOG);
g_signal_connect(proto_w, "delete_event", G_CALLBACK(proto_delete_event_cb), NULL);
g_signal_connect(proto_w, "destroy", G_CALLBACK(proto_destroy_cb), NULL);
gtk_widget_show(proto_w);
gtk_widget_grab_focus(proto_list);
if(!prefs.gui_use_pref_save) {
gtk_widget_hide(save_bt);
}
return proto_vb;
}
void
proto_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *main_vb, *main_nb, *page_lb, *protocols_page;
GtkWidget *heur_dissectors_page;
if (proto_w != NULL) {
reactivate_window(proto_w);
return;
}
proto_w = dlg_conf_window_new("Wireshark: Enabled Protocols");
gtk_window_set_default_size(GTK_WINDOW(proto_w), DEF_WIDTH , DEF_HEIGHT);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 6);
gtk_container_add(GTK_CONTAINER(proto_w), main_vb);
gtk_widget_show(main_vb);
main_nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(main_vb), main_nb, TRUE, TRUE, 0);
page_lb = gtk_label_new("Enabled Protocols");
protocols_page = build_protocols_treeview();
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), protocols_page, page_lb);
page_lb = gtk_label_new("Enabled Heuristic dissectors");
heur_dissectors_page = build_heur_dissectors_treeview();
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), heur_dissectors_page, page_lb);
gtk_widget_show_all(proto_w);
window_present(proto_w);
}
