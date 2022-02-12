GtkWidget*
capture_prefs_show(void)
{
GtkWidget *main_tb, *main_vb;
GtkWidget *if_cbxe, *if_lb, *promisc_cb, *pcap_ng_cb, *sync_cb, *auto_scroll_cb, *show_info_cb;
GtkWidget *ifopts_lb, *ifopts_bt;
GList *if_list, *combo_list;
int err;
int row = 0;
const gchar *tooltips_text;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 7, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
main_tb = gtk_table_new(CAPTURE_TABLE_ROWS, 2, FALSE);
gtk_box_pack_start(GTK_BOX(main_vb), main_tb, FALSE, FALSE, 0);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 15);
gtk_widget_show(main_tb);
if_lb = gtk_label_new("Default interface:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_lb), 1.0f, 0.5f);
gtk_widget_show(if_lb);
if_cbxe = gtk_combo_box_text_new_with_entry();
if_list = capture_interface_list(&err, NULL);
combo_list = build_capture_combo_list(if_list, FALSE);
free_interface_list(if_list);
if (combo_list != NULL) {
GList *combo_entry;
for (combo_entry = combo_list; combo_entry != NULL; combo_entry = g_list_next(combo_entry)) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(if_cbxe), combo_entry->data);
}
}
if (prefs.capture_device) {
gtk_entry_set_text(GTK_ENTRY(gtk_bin_get_child(GTK_BIN(if_cbxe))),
prefs.capture_device);
}
else if (combo_list != NULL) {
gtk_combo_box_set_active(GTK_COMBO_BOX(if_cbxe), 0);
}
free_capture_combo_list(combo_list);
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_cbxe, 1, 2, row, row+1);
tooltips_text = "The default interface to be captured from.";
gtk_widget_set_tooltip_text(if_lb, tooltips_text);
gtk_widget_set_tooltip_text(gtk_bin_get_child(GTK_BIN(if_cbxe)), tooltips_text);
gtk_widget_show(if_cbxe);
g_object_set_data(G_OBJECT(main_vb), DEVICE_KEY, if_cbxe);
row++;
ifopts_lb = gtk_label_new("Interfaces:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), ifopts_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(ifopts_lb), 1.0f, 0.5f);
gtk_widget_show(ifopts_lb);
ifopts_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_EDIT);
tooltips_text = "Open a dialog box to set various interface options.";
gtk_widget_set_tooltip_text(ifopts_lb, tooltips_text);
gtk_widget_set_tooltip_text(ifopts_bt, tooltips_text);
g_signal_connect(ifopts_bt, "clicked", G_CALLBACK(ifopts_edit_cb), NULL);
gtk_table_attach_defaults(GTK_TABLE(main_tb), ifopts_bt, 1, 2, row, row+1);
row++;
promisc_cb = create_preference_check_button(main_tb, row++,
"Capture packets in promiscuous mode:",
"Usually a network card will only capture the traffic sent to its own network address. "
"If you want to capture all traffic that the network card can \"see\", mark this option. "
"See the FAQ for some more details of capturing packets from a switched network. ",
prefs.capture_prom_mode);
g_object_set_data(G_OBJECT(main_vb), PROM_MODE_KEY, promisc_cb);
pcap_ng_cb = create_preference_check_button(main_tb, row++,
"Capture packets in pcap-ng format:",
"Capture packets in the next-generation capture file format.",
prefs.capture_pcap_ng);
g_object_set_data(G_OBJECT(main_vb), PCAP_NG_KEY, pcap_ng_cb);
sync_cb = create_preference_check_button(main_tb, row++,
"Update list of packets in real time:",
"Update the list of packets while capture is in progress. "
"Don't use this option if you notice packet drops.",
prefs.capture_real_time);
g_object_set_data(G_OBJECT(main_vb), CAPTURE_REAL_TIME_KEY, sync_cb);
auto_scroll_cb = create_preference_check_button(main_tb, row++,
"Automatic scrolling in live capture:",
"Automatic scrolling of the packet list while live capture is in progress. ",
prefs.capture_auto_scroll);
g_object_set_data(G_OBJECT(main_vb), AUTO_SCROLL_KEY, auto_scroll_cb);
show_info_cb = create_preference_check_button(main_tb, row++,
"Hide capture info dialog:",
"Hide the capture info dialog while capturing. ",
!prefs.capture_show_info);
g_object_set_data(G_OBJECT(main_vb), SHOW_INFO_KEY, show_info_cb);
gtk_widget_show_all(main_vb);
return(main_vb);
}
void
capture_prefs_fetch(GtkWidget *w)
{
GtkWidget *if_cbxe, *promisc_cb, *pcap_ng_cb, *sync_cb, *auto_scroll_cb, *show_info_cb;
gchar *if_text;
if_cbxe = (GtkWidget *)g_object_get_data(G_OBJECT(w), DEVICE_KEY);
promisc_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), PROM_MODE_KEY);
pcap_ng_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), PCAP_NG_KEY);
sync_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), CAPTURE_REAL_TIME_KEY);
auto_scroll_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), AUTO_SCROLL_KEY);
show_info_cb = (GtkWidget *)g_object_get_data(G_OBJECT(w), SHOW_INFO_KEY);
if (prefs.capture_device != NULL) {
g_free(prefs.capture_device);
prefs.capture_device = NULL;
}
if_text = g_strdup(gtk_entry_get_text(GTK_ENTRY(gtk_bin_get_child(GTK_BIN(if_cbxe)))));
g_strstrip(if_text);
if (*if_text == '\0') {
g_free(if_text);
if_text = NULL;
}
prefs.capture_device = if_text;
prefs.capture_prom_mode = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(promisc_cb));
prefs.capture_pcap_ng = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pcap_ng_cb));
prefs.capture_real_time = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sync_cb));
prefs.capture_auto_scroll = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(auto_scroll_cb));
prefs.capture_show_info = !(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(show_info_cb)));
}
void
capture_prefs_apply(GtkWidget *w _U_)
{
}
void
capture_prefs_destroy(GtkWidget *w)
{
GtkWidget *caller = gtk_widget_get_toplevel(w);
GtkWidget *dlg;
dlg = g_object_get_data(G_OBJECT(caller), IFOPTS_DIALOG_PTR_KEY);
if (dlg != NULL) {
window_destroy(dlg);
}
}
static void
ifopts_edit_cb(GtkWidget *w, gpointer data _U_)
{
GtkWidget *ifopts_edit_dlg, *cur_scr_win, *main_hb, *main_tb,
*cur_opts_fr, *ed_opts_fr, *main_vb,
*if_descr_lb,
*if_hide_lb,
*bbox, *ok_bt, *cancel_bt, *help_bt;
GtkListStore *list_store;
GtkWidget *list;
GtkTreeViewColumn *column;
GtkCellRenderer *renderer;
GtkTreeView *list_view;
GtkTreeSelection *selection;
int row = 0;
GtkWidget *caller = gtk_widget_get_toplevel(w);
ifopts_edit_dlg = g_object_get_data(G_OBJECT(caller), IFOPTS_DIALOG_PTR_KEY);
if (ifopts_edit_dlg != NULL) {
reactivate_window(ifopts_edit_dlg);
return;
}
ifopts_edit_dlg = dlg_conf_window_new("Wireshark: Preferences: Interface Options");
gtk_window_set_default_size(GTK_WINDOW(ifopts_edit_dlg), 1000, 440);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(ifopts_edit_dlg), main_vb);
gtk_widget_show(main_vb);
cur_opts_fr = gtk_frame_new("Interfaces");
gtk_container_add(GTK_CONTAINER(main_vb), cur_opts_fr);
gtk_widget_show(cur_opts_fr);
cur_scr_win = scrolled_window_new(NULL, NULL);
gtk_container_set_border_width(GTK_CONTAINER(cur_scr_win), 3);
gtk_container_add(GTK_CONTAINER(cur_opts_fr), cur_scr_win);
gtk_widget_show(cur_scr_win);
list_store = gtk_list_store_new(N_COLUMN,
G_TYPE_STRING,
G_TYPE_STRING,
#ifdef HAVE_PCAP_CREATE
G_TYPE_BOOLEAN,
#endif
G_TYPE_STRING,
G_TYPE_STRING,
G_TYPE_BOOLEAN,
G_TYPE_INT);
list = gtk_tree_view_new_with_model (GTK_TREE_MODEL (list_store));
list_view = GTK_TREE_VIEW(list);
g_object_unref (G_OBJECT (list_store));
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Device", renderer,
"text", DEVICE_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
#ifdef _WIN32
gtk_tree_view_column_set_min_width(column, 230);
#else
gtk_tree_view_column_set_min_width(column, 70);
#endif
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Description", renderer,
"text", DESC_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 260);
gtk_tree_view_append_column (list_view, column);
#ifdef HAVE_PCAP_CREATE
renderer = gtk_cell_renderer_toggle_new ();
column = gtk_tree_view_column_new_with_attributes ("Default to monitor mode", renderer,
"active", DEF_MONITOR_MODE_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, FALSE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_append_column (list_view, column);
#endif
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Default link-layer", renderer,
"text", DEF_LINK_LAYER_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 230);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("Comment", renderer,
"text", COMMENT_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 100);
gtk_tree_view_append_column (list_view, column);
renderer = gtk_cell_renderer_toggle_new ();
column = gtk_tree_view_column_new_with_attributes ("Hide?", renderer,
"active", HIDE_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, FALSE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_append_column (list_view, column);
#if 0
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes ("DLT", renderer,
"text", DLT_COLUMN,
NULL);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
gtk_tree_view_column_set_min_width(column, 40);
gtk_tree_view_append_column (list_view, column);
#endif
selection = gtk_tree_view_get_selection(list_view);
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
cur_list = list;
gtk_container_add(GTK_CONTAINER(cur_scr_win), cur_list);
if_selection = selection;
g_signal_connect (G_OBJECT (selection), "changed",
G_CALLBACK (ifopts_edit_ifsel_cb),
NULL);
gtk_widget_show(cur_list);
ifopts_if_liststore_add();
ed_opts_fr = gtk_frame_new("Properties");
gtk_box_pack_start(GTK_BOX(main_vb), ed_opts_fr, FALSE, FALSE, 0);
gtk_widget_show(ed_opts_fr);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, TRUE);
gtk_container_set_border_width(GTK_CONTAINER(main_hb), 3);
gtk_container_add(GTK_CONTAINER(ed_opts_fr), main_hb);
gtk_widget_show(main_hb);
main_tb = gtk_table_new(IFOPTS_TABLE_ROWS, 4, FALSE);
gtk_box_pack_start(GTK_BOX(main_hb), main_tb, TRUE, FALSE, 10);
gtk_table_set_row_spacings(GTK_TABLE(main_tb), 10);
gtk_table_set_col_spacings(GTK_TABLE(main_tb), 10);
gtk_widget_show(main_tb);
if_dev_lb = gtk_label_new("Device:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_dev_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_dev_lb), 1.0f, 0.5f);
gtk_widget_show(if_dev_lb);
if_dev_lb = gtk_label_new("");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_dev_lb, 1, 2, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_dev_lb), 0.0f, 0.5f);
gtk_widget_show(if_dev_lb);
row++;
if_name_lb = gtk_label_new("Description:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_name_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_name_lb), 1.0f, 0.5f);
gtk_widget_show(if_name_lb);
if_name_lb = gtk_label_new("");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_name_lb, 1, 2, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_name_lb), 0.0f, 0.5f);
gtk_widget_show(if_name_lb);
row++;
#ifdef HAVE_PCAP_CREATE
if_monitor_lb = gtk_label_new("Monitor mode:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_monitor_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_monitor_lb), 1.0f, 0.5f);
gtk_widget_show(if_monitor_lb);
if_monitor_cb = gtk_check_button_new();
g_signal_connect(if_monitor_cb, "toggled", G_CALLBACK(ifopts_edit_monitor_changed_cb),
cur_list);
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_monitor_cb, 1, 2, row, row+1);
gtk_widget_show(if_monitor_cb);
row++;
#endif
if_linktype_lb = gtk_label_new("Default link-layer header type:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_linktype_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_linktype_lb), 1.0f, 0.5f);
gtk_widget_show(if_linktype_lb);
if_linktype_cb = gtk_combo_box_text_new();
num_linktypes = 0;
interfaces_info_nochange = FALSE;
g_signal_connect(if_linktype_cb, "changed", G_CALLBACK(ifopts_edit_linktype_changed_cb),
cur_list);
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_linktype_cb, 1, 2, row, row+1);
gtk_widget_show(if_linktype_cb);
row++;
if_descr_lb = gtk_label_new("Comment:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_descr_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_descr_lb), 1.0f, 0.5f);
gtk_widget_show(if_descr_lb);
if_descr_te = gtk_entry_new();
g_signal_connect(if_descr_te, "changed", G_CALLBACK(ifopts_edit_descr_changed_cb),
cur_list);
gtk_entry_set_max_length(GTK_ENTRY(if_descr_te), IFOPTS_MAX_DESCR_LEN);
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_descr_te, 1, 2, row, row+1);
gtk_widget_show(if_descr_te);
row++;
if_hide_lb = gtk_label_new("Hide interface?:");
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_hide_lb, 0, 1, row, row+1);
gtk_misc_set_alignment(GTK_MISC(if_hide_lb), 1.0f, 0.5f);
gtk_widget_show(if_hide_lb);
if_hide_cb = gtk_check_button_new();
g_signal_connect(if_hide_cb, "toggled", G_CALLBACK(ifopts_edit_hide_changed_cb),
cur_list);
gtk_table_attach_defaults(GTK_TABLE(main_tb), if_hide_cb, 1, 2, row, row+1);
gtk_widget_show(if_hide_cb);
row++;
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
ok_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_tooltip_text(ok_bt, "Save changes and exit dialog");
g_signal_connect(ok_bt, "clicked", G_CALLBACK(ifopts_edit_ok_cb), ifopts_edit_dlg);
cancel_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel and exit dialog");
window_set_cancel_button(ifopts_edit_dlg, cancel_bt, window_cancel_button_cb);
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb),
(gpointer)HELP_CAPTURE_INTERFACE_OPTIONS_DIALOG);
gtk_widget_set_tooltip_text (help_bt, "Show topic specific help");
gtk_widget_grab_default(ok_bt);
g_signal_connect(ifopts_edit_dlg, "delete_event", G_CALLBACK(window_delete_event_cb),
NULL);
g_signal_connect(ifopts_edit_dlg, "destroy", G_CALLBACK(ifopts_edit_destroy_cb), NULL);
g_object_set_data(G_OBJECT(ifopts_edit_dlg), IFOPTS_CALLER_PTR_KEY, caller);
g_object_set_data(G_OBJECT(caller), IFOPTS_DIALOG_PTR_KEY, ifopts_edit_dlg);
gtk_widget_show(ifopts_edit_dlg);
window_present(ifopts_edit_dlg);
}
static void
ifopts_edit_ok_cb(GtkWidget *w _U_, gpointer parent_w)
{
if (if_selection){
#ifdef HAVE_PCAP_CREATE
ifopts_write_new_monitor_mode();
#endif
ifopts_write_new_linklayer();
ifopts_write_new_descr();
ifopts_write_new_hide();
}
welcome_if_panel_reload ();
gtk_grab_remove(GTK_WIDGET(parent_w));
window_destroy(GTK_WIDGET(parent_w));
}
static void
ifopts_edit_destroy_cb(GtkWidget *win, gpointer data _U_)
{
GtkWidget *caller;
caller = g_object_get_data(G_OBJECT(win), IFOPTS_CALLER_PTR_KEY);
if (caller != NULL) {
g_object_set_data(G_OBJECT(caller), IFOPTS_DIALOG_PTR_KEY, NULL);
}
}
static gint
ifopts_description_to_val (const char *if_name, gboolean monitor_mode,
const char *descr)
{
if_capabilities_t *caps;
int dlt = -1;
caps = capture_get_if_capabilities(if_name, monitor_mode, NULL);
if (caps != NULL) {
if (caps->data_link_types != NULL) {
GList *lt_entry;
for (lt_entry = g_list_next(caps->data_link_types);
lt_entry != NULL;
lt_entry = g_list_next(lt_entry)) {
data_link_info_t *dli_p = lt_entry->data;
if (dli_p->description) {
if (strcmp(dli_p->description, descr) == 0) {
dlt = dli_p->dlt;
break;
}
} else {
if (strcmp(dli_p->name, descr) == 0) {
dlt = dli_p->dlt;
break;
}
}
}
}
free_if_capabilities(caps);
}
return dlt;
}
static void
ifopts_edit_ifsel_cb(GtkTreeSelection *selection _U_,
gpointer data _U_)
{
GtkTreeIter iter;
GtkTreeModel *model;
gchar *desc, *comment, *text;
gchar *if_name, *linktype;
#ifdef HAVE_PCAP_CREATE
gboolean monitor_mode;
#endif
gboolean hide;
if_capabilities_t *caps;
gint selected = 0;
if (!gtk_tree_selection_get_selected (if_selection, &model, &iter)){
return;
}
gtk_tree_model_get(model, &iter,
DEVICE_COLUMN, &if_name,
DESC_COLUMN, &desc,
#ifdef HAVE_PCAP_CREATE
DEF_MONITOR_MODE_COLUMN, &monitor_mode,
#endif
DEF_LINK_LAYER_COLUMN, &linktype,
COMMENT_COLUMN, &comment,
HIDE_COLUMN, &hide,
-1);
gtk_label_set_text(GTK_LABEL(if_dev_lb), if_name);
gtk_label_set_text(GTK_LABEL(if_name_lb), desc);
interfaces_info_nochange = TRUE;
while (num_linktypes > 0) {
num_linktypes--;
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(if_linktype_cb), num_linktypes);
}
#ifdef HAVE_PCAP_CREATE
caps = capture_get_if_capabilities(if_name, monitor_mode, NULL);
#else
caps = capture_get_if_capabilities(if_name, FALSE, NULL);
#endif
if (caps != NULL) {
#ifdef HAVE_PCAP_CREATE
gtk_widget_set_sensitive(if_monitor_lb, caps->can_set_rfmon);
gtk_widget_set_sensitive(if_monitor_cb, caps->can_set_rfmon);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(if_monitor_cb), monitor_mode);
#endif
if (caps->data_link_types != NULL) {
GList *lt_entry;
for (lt_entry = caps->data_link_types; lt_entry != NULL;
lt_entry = g_list_next(lt_entry)) {
data_link_info_t *dli_p = lt_entry->data;
text = (dli_p->description != NULL) ? dli_p->description : dli_p->name;
if (strcmp(linktype, text) == 0) {
selected = num_linktypes;
}
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(if_linktype_cb), text);
num_linktypes++;
}
gtk_widget_set_sensitive(if_linktype_lb, num_linktypes >= 2);
gtk_widget_set_sensitive(if_linktype_cb, num_linktypes >= 2);
gtk_combo_box_set_active(GTK_COMBO_BOX(if_linktype_cb), selected);
}
free_if_capabilities(caps);
}
#ifdef HAVE_PCAP_CREATE
else {
gtk_widget_set_sensitive(if_monitor_lb, FALSE);
gtk_widget_set_sensitive(if_monitor_cb, FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(if_monitor_cb), FALSE);
}
#endif
gtk_entry_set_text(GTK_ENTRY(if_descr_te), comment);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(if_hide_cb), hide);
interfaces_info_nochange = FALSE;
g_free(if_name);
g_free(desc);
g_free(linktype);
g_free(comment);
}
static void
ifopts_edit_monitor_changed_cb(GtkToggleButton *tbt, gpointer udata)
{
GtkTreeModel *list_model;
GtkTreeIter list_iter;
GtkListStore *list_store;
gchar *if_name, *text;
gboolean monitor_mode;
if_capabilities_t *caps;
if (interfaces_info_nochange)
return;
if (if_selection == NULL)
return;
if (!gtk_tree_selection_get_selected (if_selection, &list_model, &list_iter)){
return;
}
gtk_tree_model_get(list_model, &list_iter,
DEVICE_COLUMN, &if_name,
-1);
interfaces_info_nochange = TRUE;
while (num_linktypes > 0) {
num_linktypes--;
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(if_linktype_cb), num_linktypes);
}
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (udata)));
#ifdef HAVE_PCAP_CREATE
monitor_mode = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(tbt));
gtk_list_store_set (list_store, &list_iter,
DEF_MONITOR_MODE_COLUMN, monitor_mode,
-1);
caps = capture_get_if_capabilities(if_name, monitor_mode, NULL);
#else
caps = capture_get_if_capabilities(if_name, FALSE, NULL);
#endif
if (caps != NULL) {
#ifdef HAVE_PCAP_CREATE
gtk_widget_set_sensitive(if_monitor_lb, caps->can_set_rfmon);
gtk_widget_set_sensitive(if_monitor_cb, caps->can_set_rfmon);
#endif
if (caps->data_link_types != NULL) {
GList *lt_entry;
for (lt_entry = caps->data_link_types; lt_entry != NULL;
lt_entry = g_list_next(lt_entry)) {
data_link_info_t *dli_p = lt_entry->data;
text = (dli_p->description != NULL) ? dli_p->description : dli_p->name;
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(if_linktype_cb), text);
num_linktypes++;
}
gtk_widget_set_sensitive(if_linktype_lb, num_linktypes >= 2);
gtk_widget_set_sensitive(if_linktype_cb, num_linktypes >= 2);
gtk_combo_box_set_active(GTK_COMBO_BOX(if_linktype_cb), 0);
}
free_if_capabilities(caps);
}
#ifdef HAVE_PCAP_CREATE
else {
gtk_widget_set_sensitive(if_monitor_lb, FALSE);
gtk_widget_set_sensitive(if_monitor_cb, FALSE);
}
#endif
interfaces_info_nochange = FALSE;
g_signal_emit_by_name(if_linktype_cb, "changed");
g_free(if_name);
}
static void
ifopts_edit_linktype_changed_cb(GtkComboBox *cb, gpointer udata)
{
gchar *ifnm, *text;
#ifdef HAVE_PCAP_CREATE
gboolean monitor_mode;
#endif
gint linktype;
GtkTreeModel *list_model;
GtkTreeIter list_iter;
GtkListStore *list_store;
if (interfaces_info_nochange)
return;
if (if_selection == NULL)
return;
if (!gtk_tree_selection_get_selected (if_selection, &list_model, &list_iter)){
return;
}
gtk_tree_model_get(list_model, &list_iter,
DEVICE_COLUMN, &ifnm,
#ifdef HAVE_PCAP_CREATE
DEF_MONITOR_MODE_COLUMN, &monitor_mode,
#endif
-1);
text = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb));
if (text) {
#ifdef HAVE_PCAP_CREATE
linktype = ifopts_description_to_val(ifnm, monitor_mode, text);
#else
linktype = ifopts_description_to_val(ifnm, FALSE, text);
#endif
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (udata)));
gtk_list_store_set (list_store, &list_iter,
DEF_LINK_LAYER_COLUMN, text,
DLT_COLUMN, linktype,
-1);
g_free(text);
}
}
static void
ifopts_edit_descr_changed_cb(GtkEditable *ed, gpointer udata)
{
gchar *text;
GtkTreeModel *list_model;
GtkTreeIter list_iter;
GtkListStore *list_store;
if (interfaces_info_nochange)
return;
if (if_selection == NULL)
return;
if (!gtk_tree_selection_get_selected (if_selection, &list_model, &list_iter)){
return;
}
text = gtk_editable_get_chars(GTK_EDITABLE(ed), 0, -1);
g_strdelimit(text, "(),", ' ');
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (udata)));
gtk_list_store_set (list_store, &list_iter,
COMMENT_COLUMN, text,
-1);
g_free(text);
}
static void
ifopts_edit_hide_changed_cb(GtkToggleButton *tbt, gpointer udata)
{
GtkTreeModel *list_model;
GtkTreeIter list_iter;
GtkListStore *list_store;
if (interfaces_info_nochange)
return;
if (if_selection == NULL)
return;
if (!gtk_tree_selection_get_selected (if_selection, &list_model, &list_iter)){
return;
}
list_store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (udata)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(tbt)) == TRUE)
gtk_list_store_set (list_store, &list_iter,
HIDE_COLUMN, TRUE,
-1);
else
gtk_list_store_set (list_store, &list_iter,
HIDE_COLUMN, FALSE,
-1);
}
static void
ifopts_options_add(GtkListStore *list_store, if_info_t *if_info)
{
gchar *p;
gchar *ifnm;
gchar *desc;
gchar *pr_descr;
gchar *text[] = { NULL, NULL, NULL, NULL };
if_capabilities_t *caps;
#ifdef HAVE_PCAP_CREATE
gboolean monitor_mode;
#endif
gint linktype;
gboolean hide;
GtkTreeIter iter;
text[0] = g_strdup(if_info->name);
if (if_info->description != NULL)
text[1] = g_strdup(if_info->description);
else
text[1] = g_strdup("");
#ifdef HAVE_PCAP_CREATE
monitor_mode = prefs_capture_device_monitor_mode(if_info->name);
caps = capture_get_if_capabilities(if_info->name, monitor_mode, NULL);
#else
caps = capture_get_if_capabilities(if_info->name, FALSE, NULL);
#endif
linktype = capture_dev_user_linktype_find(if_info->name);
if (caps != NULL) {
if (caps->data_link_types != NULL) {
GList *lt_entry;
for (lt_entry = caps->data_link_types; lt_entry != NULL;
lt_entry = g_list_next(lt_entry)) {
data_link_info_t *dli_p = lt_entry->data;
if (linktype == -1 || linktype == dli_p->dlt) {
if (dli_p->description) {
text[2] = g_strdup(dli_p->description);
} else {
text[2] = g_strdup(dli_p->name);
}
break;
}
}
}
free_if_capabilities(caps);
}
if (text[2] == NULL)
text[2] = g_strdup("");
if (prefs.capture_devices_descr != NULL) {
pr_descr = g_strdup(prefs.capture_devices_descr);
if ((ifnm = strstr(pr_descr, if_info->name)) != NULL) {
p = ifnm;
while (*p != '\0') {
if (*p == '(') {
p++;
if ((*p == '\0') || (*p == ',') || (*p == '(') || (*p == ')'))
break;
desc = p;
p++;
while (*p != '\0') {
if ((*p == ',') || (*p == '('))
break;
else if (*p == ')') {
*p = '\0';
text[3] = g_strdup(desc);
break;
}
p++;
}
break;
} else
p++;
}
}
g_free(pr_descr);
}
if (text[3] == NULL)
text[3] = g_strdup("");
hide = prefs_is_capture_device_hidden(if_info->name);
gtk_list_store_insert_with_values( list_store , &iter, G_MAXINT,
DEVICE_COLUMN, text[0],
DESC_COLUMN, text[1],
#ifdef HAVE_PCAP_CREATE
DEF_MONITOR_MODE_COLUMN, monitor_mode,
#endif
DEF_LINK_LAYER_COLUMN, text[2],
COMMENT_COLUMN, text[3],
HIDE_COLUMN, hide,
DLT_COLUMN, linktype,
-1);
ifopts_options_free(text);
}
static void
ifopts_options_free(gchar *text[])
{
gint i;
for (i=0; i < IFOPTS_LIST_TEXT_COLS; i++) {
if (text[i] != NULL) {
g_free(text[i]);
text[i] = NULL;
}
}
}
static void
ifopts_if_liststore_add(void)
{
GList *if_list, *ifl_p;
int err;
gchar *err_str;
if_list = capture_interface_list(&err, &err_str);
if (if_list == NULL) {
if (err != NO_INTERFACES_FOUND) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_str);
}
g_free(err_str);
return;
}
for (ifl_p = if_list; ifl_p != NULL; ifl_p = g_list_next(ifl_p)) {
if ((ifl_p->data) == NULL)
continue;
ifopts_options_add(GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW (cur_list))),
(if_info_t *)ifl_p->data);
}
free_interface_list(if_list);
}
static void
ifopts_write_new_monitor_mode(void)
{
GtkListStore *store;
GtkTreeIter iter;
GtkTreeModel *model;
gboolean more_items = TRUE;
gint first_if = TRUE;
gchar *ifnm;
gboolean monitor_mode;
gchar *new_monitor_mode;
new_monitor_mode = g_malloc0(MAX_VAL_LEN);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(cur_list));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
DEVICE_COLUMN, &ifnm,
DEF_MONITOR_MODE_COLUMN, &monitor_mode,
-1);
if (!monitor_mode){
more_items = gtk_tree_model_iter_next (model,&iter);
continue;
}
if (first_if != TRUE)
g_strlcat (new_monitor_mode, ",", MAX_VAL_LEN);
g_strlcat (new_monitor_mode, ifnm, MAX_VAL_LEN);
first_if = FALSE;
more_items = gtk_tree_model_iter_next (model,&iter);
}
if (strlen(new_monitor_mode) > 0) {
g_free(prefs.capture_devices_monitor_mode);
prefs.capture_devices_monitor_mode = new_monitor_mode;
}
else {
g_free(prefs.capture_devices_monitor_mode);
g_free(new_monitor_mode);
prefs.capture_devices_monitor_mode = NULL;
}
}
}
static void
ifopts_write_new_linklayer(void)
{
GtkListStore *store;
GtkTreeIter iter;
GtkTreeModel *model;
gboolean more_items = TRUE, first_if = TRUE;
gchar *ifnm;
gint linktype;
gchar *tmp_linklayer;
gchar *new_linklayer;
new_linklayer = g_malloc0(MAX_VAL_LEN);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(cur_list));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
DEVICE_COLUMN, &ifnm,
DLT_COLUMN, &linktype,
-1);
if (linktype == -1){
more_items = gtk_tree_model_iter_next (model,&iter);
continue;
}
if (first_if != TRUE) {
g_strlcat (new_linklayer, ",", MAX_VAL_LEN);
}
tmp_linklayer = g_strdup_printf("%s(%d)", ifnm, linktype);
g_strlcat(new_linklayer, tmp_linklayer, MAX_VAL_LEN);
g_free(tmp_linklayer);
g_free(ifnm);
first_if = FALSE;
more_items = gtk_tree_model_iter_next (model,&iter);
}
if (strlen(new_linklayer) > 0) {
g_free(prefs.capture_devices_linktypes);
prefs.capture_devices_linktypes = new_linklayer;
}
else {
g_free(prefs.capture_devices_linktypes);
g_free(new_linklayer);
prefs.capture_devices_linktypes = NULL;
}
}
}
static void
ifopts_write_new_descr(void)
{
GtkListStore *store;
GtkTreeIter iter;
GtkTreeModel *model;
gboolean more_items = TRUE;
gboolean first_if = TRUE;
gchar *ifnm;
gchar *desc;
gchar *tmp_descr;
gchar *new_descr;
new_descr = g_malloc0(MAX_VAL_LEN);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(cur_list));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
DEVICE_COLUMN, &ifnm,
COMMENT_COLUMN, &desc,
-1);
if (strlen(desc) == 0){
more_items = gtk_tree_model_iter_next (model,&iter);
continue;
}
if (first_if != TRUE) {
g_strlcat (new_descr, ",", MAX_VAL_LEN);
}
tmp_descr = g_strdup_printf("%s(%s)", ifnm, desc);
g_strlcat(new_descr, tmp_descr, MAX_VAL_LEN);
g_free(tmp_descr);
first_if = FALSE;
more_items = gtk_tree_model_iter_next (model,&iter);
}
if (strlen(new_descr) > 0) {
g_free(prefs.capture_devices_descr);
prefs.capture_devices_descr = new_descr;
}
else {
g_free(prefs.capture_devices_descr);
g_free(new_descr);
prefs.capture_devices_descr = NULL;
}
}
}
static void
ifopts_write_new_hide(void)
{
GtkListStore *store;
GtkTreeIter iter;
GtkTreeModel *model;
gboolean more_items = TRUE;
gint first_if = TRUE;
gchar *ifnm;
gboolean hide;
gchar *new_hide;
new_hide = g_malloc0(MAX_VAL_LEN);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(cur_list));
store = GTK_LIST_STORE(model);
if( gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store), &iter) ) {
while (more_items) {
gtk_tree_model_get(GTK_TREE_MODEL(store), &iter,
DEVICE_COLUMN, &ifnm,
HIDE_COLUMN, &hide,
-1);
if (!hide){
more_items = gtk_tree_model_iter_next (model,&iter);
continue;
}
if (first_if != TRUE)
g_strlcat (new_hide, ",", MAX_VAL_LEN);
g_strlcat (new_hide, ifnm, MAX_VAL_LEN);
first_if = FALSE;
more_items = gtk_tree_model_iter_next (model,&iter);
}
if (strlen(new_hide) > 0) {
g_free(prefs.capture_devices_hide);
prefs.capture_devices_hide = new_hide;
}
else {
g_free(prefs.capture_devices_hide);
g_free(new_hide);
prefs.capture_devices_hide = NULL;
}
hide_interface(g_strdup(new_hide));
}
}
