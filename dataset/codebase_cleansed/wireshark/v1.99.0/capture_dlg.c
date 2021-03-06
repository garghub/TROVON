static
gchar *col_index_to_name(gint indx)
{
gchar *col_name;
switch (indx)
{
case INTERFACE: col_name = g_strdup("INTERFACE");
break;
case LINK: col_name = g_strdup("LINK");
break;
case PMODE: col_name = g_strdup("PMODE");
break;
case SNAPLEN: col_name = g_strdup("SNAPLEN");
break;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
case BUFFER: col_name = g_strdup("BUFFER");
break;
#endif
#if defined (HAVE_PCAP_CREATE)
case MONITOR: col_name = g_strdup("MONITOR");
break;
#endif
case FILTER: col_name = g_strdup("FILTER");
break;
default: return NULL;
}
return col_name;
}
static
gint col_title_to_index(const gchar *name)
{
if (strcmp(name, "Capture") == 0) return CAPTURE;
if (strcmp(name, "Interface") == 0) return INTERFACE;
if (strcmp(name, "Link-layer header") == 0) return LINK;
if (strcmp(name, "Prom. Mode") == 0) return PMODE;
if (strcmp(name, "Snaplen [B]") == 0) return SNAPLEN;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
if (strcmp(name, "Buffer [MiB]") == 0) return BUFFER;
#endif
#if defined (HAVE_PCAP_CREATE)
if (strcmp(name, "Mon. Mode") == 0) return MONITOR;
#endif
if (strcmp(name, "Capture Filter") == 0) return FILTER;
return -1;
}
static void
set_capture_column_visible(gchar *col, gboolean visible _U_)
{
GList *curr;
gchar *col_name;
if (visible && !prefs_capture_options_dialog_column_is_visible(col)) {
prefs.capture_columns = g_list_append(prefs.capture_columns, col);
} else if (!visible && prefs_capture_options_dialog_column_is_visible(col)) {
for (curr = g_list_first(prefs.capture_columns); curr; curr = g_list_next(curr)) {
col_name = (gchar *)curr->data;
if (col_name && (g_ascii_strcasecmp(col_name, col) == 0)) {
prefs.capture_columns = g_list_remove(prefs.capture_columns, curr->data);
break;
}
}
}
}
static void
toggle_visible_column_cb (GtkWidget *w _U_, gpointer data)
{
GtkTreeView *view;
GtkTreeViewColumn *col;
gchar *col_name;
gint col_id;
col_id = GPOINTER_TO_INT(data);
view = (GtkTreeView *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
col = gtk_tree_view_get_column(GTK_TREE_VIEW(view), col_id);
col_name = col_index_to_name(col_id);
gtk_tree_view_column_set_visible(col, prefs_capture_options_dialog_column_is_visible(col_name)?FALSE:TRUE);
set_capture_column_visible(col_name, prefs_capture_options_dialog_column_is_visible(col_name)?FALSE:TRUE);
}
static void
set_all_columns_visible (void)
{
GtkTreeViewColumn *col;
int col_id;
GtkTreeView *view;
gchar *name;
view = (GtkTreeView *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
for (col_id = 2; col_id < NUM_COLUMNS; col_id++) {
col = gtk_tree_view_get_column(GTK_TREE_VIEW(view), col_id);
gtk_tree_view_column_set_visible(col, TRUE);
if ((name = col_index_to_name(col_id)) != NULL) {
set_capture_column_visible(name, TRUE);
}
}
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
update_visible_columns_menu ();
}
static void
columns_activate_all_columns_cb(GtkAction *action _U_, gpointer user_data _U_)
{
set_all_columns_visible ();
}
void
update_visible_tree_view_columns(void)
{
GtkTreeView *view;
gint col_id;
GtkTreeViewColumn *col;
view = (GtkTreeView *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
gtk_tree_view_column_set_visible(gtk_tree_view_get_column(GTK_TREE_VIEW(view), INTERFACE), TRUE);
for (col_id = 3; col_id < NUM_COLUMNS; col_id++) {
col = gtk_tree_view_get_column(GTK_TREE_VIEW(view), col_id);
gtk_tree_view_column_set_visible(col, prefs_capture_options_dialog_column_is_visible(col_index_to_name(col_id))?TRUE:FALSE);
}
}
void
update_visible_columns_menu (void)
{
GtkWidget *menu_columns, *menu_item;
GtkWidget *sub_menu;
gchar *title;
gint col_id;
menu_columns = gtk_ui_manager_get_widget(ui_manager_columns, "/ColumnsPopup/DisplayedColumns");
if (! menu_columns){
fprintf (stderr, "Warning: couldn't find menu_columns path=/ColumnsPopup/DisplayedColumns");
}
sub_menu = gtk_menu_new();
gtk_menu_item_set_submenu (GTK_MENU_ITEM(menu_columns), sub_menu);
for (col_id = 3; col_id < NUM_COLUMNS; col_id++) {
title = col_index_to_name(col_id);
menu_item = gtk_check_menu_item_new_with_label(title);
gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_item), prefs_capture_options_dialog_column_is_visible(title));
g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(toggle_visible_column_cb), GINT_TO_POINTER(col_id));
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show (menu_item);
}
menu_item = gtk_menu_item_new();
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
gtk_widget_show (menu_item);
menu_item = gtk_menu_item_new_with_label ("Display All");
gtk_menu_shell_append (GTK_MENU_SHELL(sub_menu), menu_item);
g_signal_connect(menu_item, "activate", G_CALLBACK(columns_activate_all_columns_cb), NULL);
gtk_widget_show (menu_item);
}
static void
columns_pref_cb(GtkAction *action _U_, gpointer user_data)
{
GtkWidget *widget = gtk_ui_manager_get_widget(ui_manager_columns, "/ColumnsPopup/ColumnPreferences");
prefs_page_cb( widget , user_data, PREFS_PAGE_CAPTURE);
}
static void
columns_hide_col_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkTreeView *view;
GtkTreeViewColumn *col;
gint num;
gchar *name;
view = (GtkTreeView *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
col = (GtkTreeViewColumn *)g_object_get_data(G_OBJECT(view), E_MCAPTURE_COLUMNS_COLUMN_KEY);
gtk_tree_view_column_set_visible(col, FALSE);
num = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(col), E_MCAPTURE_COLUMNS_COL_KEY));
if ((name = col_index_to_name(num)) != NULL) {
set_capture_column_visible(name, FALSE);
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
update_visible_columns_menu ();
}
}
static void
init_columns_menu(void)
{
GtkActionGroup *columns_action_group;
GError *error = NULL;
columns_menu_object = gtk_menu_new();
columns_action_group = gtk_action_group_new ("ColumnsPopUpMenuActionGroup");
gtk_action_group_add_actions (columns_action_group,
(const GtkActionEntry *)columns_menu_popup_action_entries,
G_N_ELEMENTS(columns_menu_popup_action_entries),
columns_menu_object);
ui_manager_columns = gtk_ui_manager_new ();
gtk_ui_manager_insert_action_group (ui_manager_columns,
columns_action_group,
0);
gtk_ui_manager_add_ui_from_string (ui_manager_columns, ui_desc_columns_menu_popup, -1, &error);
if (error != NULL)
{
fprintf (stderr, "Warning: building Packet List Heading Pop-Up failed: %s\n", error->message);
g_error_free (error);
error = NULL;
}
g_object_set_data(G_OBJECT(columns_menu_object), PM_COLUMNS_KEY,
gtk_ui_manager_get_widget(ui_manager_columns, "/ColumnsPopup"));
popup_menu_list = g_slist_append((GSList *)popup_menu_list, ui_manager_columns);
}
void
capture_stop_cb(GtkWidget *w _U_, gpointer d _U_)
{
#ifdef HAVE_AIRPCAP
if (airpcap_if_active)
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
capture_stop(&global_capture_session);
}
void
capture_restart_cb(GtkWidget *w _U_, gpointer d _U_)
{
#ifdef HAVE_AIRPCAP
if (airpcap_if_active)
airpcap_set_toolbar_start_capture(airpcap_if_active);
#endif
capture_restart(&global_capture_session);
}
static void *
check_capture_filter_syntax(void *data _U_) {
struct bpf_program fcode;
int pc_err;
while (1) {
g_mutex_lock(cfc_data_mtx);
while (!cfc_data.filter_text || cfc_data.state != CFC_PENDING) {
g_cond_wait(cfc_data_cond, cfc_data_mtx);
}
cfc_data.state = CFC_UNKNOWN;
DEBUG_SYNTAX_CHECK("pending", "unknown");
g_mutex_unlock(cfc_data_mtx);
g_mutex_lock(pcap_compile_mtx);
pc_err = pcap_compile_nopcap(DUMMY_SNAPLENGTH ,
cfc_data.dlt, &fcode, cfc_data.filter_text, 1 ,
DUMMY_NETMASK );
g_mutex_unlock(pcap_compile_mtx);
g_mutex_lock(cfc_data_mtx);
if (cfc_data.state == CFC_UNKNOWN) {
if (pc_err) {
DEBUG_SYNTAX_CHECK("unknown", "known bad");
cfc_data.state = CFC_INVALID;
} else {
DEBUG_SYNTAX_CHECK("unknown", "known good");
cfc_data.state = CFC_VALID;
}
}
g_mutex_unlock(cfc_data_mtx);
}
return NULL;
}
static gboolean
update_capture_filter_te(gpointer data _U_) {
g_mutex_lock(cfc_data_mtx);
if (cfc_data.filter_text && cfc_data.filter_te) {
if (cfc_data.state == CFC_VALID) {
colorize_filter_te_as_valid(cfc_data.filter_te);
} else if (cfc_data.state == CFC_INVALID) {
colorize_filter_te_as_invalid(cfc_data.filter_te);
} else {
colorize_filter_te_as_empty(cfc_data.filter_te);
}
if (cfc_data.state == CFC_VALID || cfc_data.state == CFC_INVALID) {
DEBUG_SYNTAX_CHECK("known", "idle");
if (cfc_data.filter_text != NULL) {
g_free(cfc_data.filter_text);
}
cfc_data.filter_text = NULL;
cfc_data.state = CFC_PENDING;
}
}
g_mutex_unlock(cfc_data_mtx);
return TRUE;
}
void capture_filter_init(void) {
cfc_data.filter_text = NULL;
cfc_data.filter_te = NULL;
cfc_data.state = CFC_PENDING;
#if GLIB_CHECK_VERSION(2,31,0)
pcap_compile_mtx = g_new(GMutex,1);
g_mutex_init(pcap_compile_mtx);
cfc_data_cond = g_new(GCond,1);
g_cond_init(cfc_data_cond);
cfc_data_mtx = g_new(GMutex,1);
g_mutex_init(cfc_data_mtx);
g_thread_new("Capture filter syntax", check_capture_filter_syntax, NULL);
#else
pcap_compile_mtx = g_mutex_new();
cfc_data_cond = g_cond_new();
cfc_data_mtx = g_mutex_new();
g_thread_create(check_capture_filter_syntax, NULL, FALSE, NULL);
#endif
g_timeout_add(200, update_capture_filter_te, NULL);
}
static void
update_filter_string(gchar *name, gchar *text)
{
GtkTreeIter iter;
GtkTreeView *if_cb;
GtkTreeModel *model;
gchar *name_str;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
gtk_tree_model_get_iter_first(model, &iter);
do {
gtk_tree_model_get(model, &iter, IFACE_HIDDEN_NAME, &name_str, -1);
if (strcmp(name, name_str) == 0) {
gtk_list_store_set (GTK_LIST_STORE(model), &iter, FILTER, g_strdup(text), -1);
break;
}
} while (gtk_tree_model_iter_next(model, &iter));
}
static void
capture_all_filter_check_syntax_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
GtkWidget *filter_cm, *filter_te;
gchar *filter_text = NULL;
guint i;
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY);
if (!filter_cm)
return;
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
if (!filter_te)
return;
if (global_capture_opts.num_selected > 0) {
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.selected) {
continue;
}
if (device.active_dlt == -1) {
colorize_filter_te_as_empty(filter_te);
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The link type of interface %s was not specified.", device.name);
continue;
}
filter_text = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(filter_cm));
if (strlen(filter_text) == 0) {
colorize_filter_te_as_empty(filter_te);
if (strlen(device.cfilter) > 0) {
g_array_remove_index(global_capture_opts.all_ifaces, i);
device.cfilter = g_strdup(filter_text);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
update_filter_string(device.name, filter_text);
}
g_free(filter_text);
continue;
}
g_assert(filter_text != NULL);
g_array_remove_index(global_capture_opts.all_ifaces, i);
device.cfilter = g_strdup(filter_text);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
g_mutex_lock(cfc_data_mtx);
g_free(cfc_data.filter_text);
cfc_data.dlt = device.active_dlt;
cfc_data.filter_text = filter_text;
cfc_data.filter_te = filter_te;
cfc_data.state = CFC_PENDING;
DEBUG_SYNTAX_CHECK("?", "pending");
g_cond_signal(cfc_data_cond);
g_mutex_unlock(cfc_data_mtx);
update_filter_string(device.name, filter_text);
}
}
}
static void
capture_filter_check_syntax_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
GtkWidget *filter_cm, *filter_te, *linktype_combo_box;
gchar *filter_text;
gpointer dlt_ptr;
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(opt_edit_w), E_CFILTER_CM_KEY);
if (!filter_cm)
return;
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
if (!filter_te)
return;
linktype_combo_box = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_LT_CBX_KEY);
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(linktype_combo_box), &dlt_ptr)) {
colorize_filter_te_as_empty(filter_te);
return;
}
if ((cfc_data.dlt = GPOINTER_TO_INT(dlt_ptr)) == -1) {
g_assert_not_reached();
}
filter_text = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(filter_cm));
if (strlen(filter_text) == 0) {
colorize_filter_te_as_empty(filter_te);
g_free(filter_text);
return;
}
g_mutex_lock(cfc_data_mtx);
if (cfc_data.filter_text != NULL) {
g_free(cfc_data.filter_text);
}
cfc_data.filter_text = filter_text;
cfc_data.filter_te = filter_te;
cfc_data.state = CFC_PENDING;
DEBUG_SYNTAX_CHECK("?", "pending");
g_cond_signal(cfc_data_cond);
g_mutex_unlock(cfc_data_mtx);
}
static void
capture_filter_destroy_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
g_mutex_lock(cfc_data_mtx);
if (cfc_data.filter_text != NULL) {
g_free(cfc_data.filter_text);
}
cfc_data.filter_text = NULL;
cfc_data.filter_te = NULL;
cfc_data.state = CFC_PENDING;
g_mutex_unlock(cfc_data_mtx);
}
static GtkWidget *time_unit_combo_box_new(guint32 value) {
GtkWidget *unit_combo_box;
int i;
unit_combo_box = gtk_combo_box_text_new ();
for (i = 0; i < MAX_TIME_UNITS; i++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (unit_combo_box), time_unit_name[i]);
}
if (value >= 60 * 60 * 24) {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), TIME_UNIT_DAY);
} else {
if (value >= 60 * 60) {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), TIME_UNIT_HOUR);
} else {
if (value >= 60) {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), TIME_UNIT_MINUTE);
} else {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), TIME_UNIT_SECOND);
}
}
}
return unit_combo_box;
}
static guint32 time_unit_combo_box_convert_value(
guint32 value)
{
if (value >= 60 * 60 * 24) {
return value / (60 * 60 * 24);
}
if (value >= 60 * 60) {
return value / (60 * 60);
}
if (value >= 60) {
return value / 60;
}
return value;
}
static guint32 time_unit_combo_box_get_value(
GtkWidget *unit_combo_box,
guint32 value)
{
int unit;
unit = gtk_combo_box_get_active (GTK_COMBO_BOX(unit_combo_box));
switch(unit) {
case(TIME_UNIT_SECOND):
return value;
case(TIME_UNIT_MINUTE):
return value * 60;
case(TIME_UNIT_HOUR):
return value * 60 * 60;
case(TIME_UNIT_DAY):
return value * 60 * 60 * 24;
default:
g_assert_not_reached();
return 0;
}
}
static GtkWidget *size_unit_combo_box_new(guint32 value) {
GtkWidget *unit_combo_box;
int i;
unit_combo_box=gtk_combo_box_text_new();
for (i=0; i<MAX_SIZE_UNITS; i++){
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (unit_combo_box), size_unit_name[i]);
}
if (value >= 1000 * 1000) {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), SIZE_UNIT_GIGABYTES);
} else {
if (value >= 1000) {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), SIZE_UNIT_MEGABYTES);
} else {
gtk_combo_box_set_active(GTK_COMBO_BOX(unit_combo_box), SIZE_UNIT_KILOBYTES);
}
}
return unit_combo_box;
}
static guint32 size_unit_combo_box_set_value(
guint32 value)
{
if (value >= 1000 * 1000) {
return value / (1000 * 1000);
}
if (value >= 1000) {
return value / (1000);
}
return value;
}
static guint32 size_unit_combo_box_convert_value(
GtkWidget *unit_combo_box,
guint32 value)
{
int unit;
unit = gtk_combo_box_get_active (GTK_COMBO_BOX(unit_combo_box));
switch(unit) {
case(SIZE_UNIT_KILOBYTES):
if (value > (((guint32)G_MAXINT + 1) / 1000)) {
return 0;
} else {
return value;
}
case(SIZE_UNIT_MEGABYTES):
if (value > (((guint32)G_MAXINT + 1) / (1000 * 1000))) {
return 0;
} else {
return value * 1000;
}
case(SIZE_UNIT_GIGABYTES):
if (value > (((guint32)G_MAXINT + 1) / (1000 * 1000 * 1000))) {
return 0;
} else {
return value * 1000 * 1000;
}
default:
g_assert_not_reached();
return 0;
}
}
static void
options_airpcap_advanced_cb(GtkWidget *w, gpointer d)
{
int *from_widget;
from_widget = (gint*)g_malloc(sizeof(gint));
*from_widget = AIRPCAP_ADVANCED_FROM_OPTIONS;
g_object_set_data(G_OBJECT(wireless_tb),AIRPCAP_ADVANCED_FROM_KEY,from_widget);
airpcap_if_active = airpcap_if_selected;
airpcap_enable_toolbar_widgets(wireless_tb,FALSE);
display_airpcap_advanced_cb(w,d);
}
static void
iftype_combo_box_add_remote_separators (GtkWidget *iftype_cbx)
{
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(iftype_cbx), REMOTE_HOST_SEPARATOR);
gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(iftype_cbx), "Clear list");
}
static void
iftype_combo_box_add (GtkWidget *iftype_cbx, interface_t *device)
{
GtkTreeModel *model;
GtkTreeIter iter;
gboolean create_new = FALSE;
gchar *string;
guint pos = REMOTE_HOST_START;
struct remote_host *rh;
rh = recent_get_remote_host(device->remote_opts.remote_host_opts.remote_host);
if (!rh) {
rh = g_malloc0 (sizeof (*rh));
if (recent_get_remote_host_list_size() == 0) {
iftype_combo_box_add_remote_separators (iftype_cbx);
}
gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(iftype_cbx), pos, device->remote_opts.remote_host_opts.remote_host);
rh->r_host = g_strdup (device->remote_opts.remote_host_opts.remote_host);
create_new = TRUE;
} else {
model = (GtkTreeModel *)gtk_combo_box_get_model(GTK_COMBO_BOX(iftype_cbx));
if (gtk_tree_model_get_iter_first(GTK_TREE_MODEL(model), &iter)) {
while (gtk_tree_model_iter_next(model, &iter)) {
gtk_tree_model_get(model, &iter, 0, &string, -1);
if (string) {
if (strcmp (device->remote_opts.remote_host_opts.remote_host, string) == 0) {
g_free (string);
break;
}
g_free (string);
}
pos++;
}
}
g_free (rh->remote_port);
g_free (rh->auth_username);
g_free (rh->auth_password);
}
rh->remote_port = g_strdup (device->remote_opts.remote_host_opts.remote_port);
rh->auth_type = device->remote_opts.remote_host_opts.auth_type;
rh->auth_username = g_strdup (device->remote_opts.remote_host_opts.auth_username);
rh->auth_password = g_strdup (device->remote_opts.remote_host_opts.auth_password);
if (create_new) {
recent_add_remote_host(g_strdup (device->remote_opts.remote_host_opts.remote_host), rh);
}
g_object_set_data(G_OBJECT(iftype_cbx), E_CAP_CBX_IFTYPE_NOUPDATE_KEY, GINT_TO_POINTER(1));
gtk_combo_box_set_active(GTK_COMBO_BOX(iftype_cbx), pos);
g_object_set_data(G_OBJECT(iftype_cbx), E_CAP_CBX_IFTYPE_NOUPDATE_KEY, GINT_TO_POINTER(0));
}
static void
iftype_combo_box_add_remote_host (gpointer key, gpointer value _U_, gpointer user_data)
{
gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(user_data), REMOTE_HOST_START, key);
}
static GtkWidget *
iftype_combo_box_new(void)
{
GtkWidget *iftype_cbx;
GHashTable *ht;
iftype_cbx = gtk_combo_box_text_new_with_entry();
ht = get_remote_host_list();
if (g_hash_table_size (ht) > 0) {
g_hash_table_foreach (ht, iftype_combo_box_add_remote_host, iftype_cbx);
iftype_combo_box_add_remote_separators (iftype_cbx);
}
g_signal_connect(iftype_cbx, "changed", G_CALLBACK(select_if_type_cb), NULL);
return iftype_cbx;
}
static gboolean
iftype_combo_is_separator (GtkTreeModel *model, GtkTreeIter *iter, gpointer data _U_)
{
gboolean result = FALSE;
gchar *string;
gtk_tree_model_get(model, iter, 0, &string, -1);
if (string) {
result = !strcmp (string, REMOTE_HOST_SEPARATOR);
g_free (string);
}
return result;
}
static void
error_list_remote_interface_cb (gpointer dialog _U_, gint btn _U_, gpointer data)
{
capture_remote_cb(GTK_WIDGET(data), FALSE);
}
static void
insert_new_rows(GList *list)
{
interface_t device;
GtkTreeIter iter;
GList *if_entry;
if_info_t *if_info;
char *if_string = NULL, *temp = NULL, *snaplen_string;
gchar *descr;
if_capabilities_t *caps;
gint linktype_count;
gboolean monitor_mode;
GSList *curr_addr;
int ips = 0;
guint i;
if_addr_t *addr;
GList *lt_entry;
data_link_info_t *data_link_info;
gchar *str = NULL, *link_type_name = NULL;
gboolean found = FALSE;
GString *ip_str;
GtkTreeView *if_cb;
GtkTreeModel *model;
link_row *linkr = NULL;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
for (if_entry = g_list_first(list); if_entry != NULL; if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
#ifdef HAVE_PCAP_REMOTE
add_interface_to_remote_list(if_info);
#endif
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(device.name, if_info->name) == 0) {
found = TRUE;
break;
}
}
if (found) {
found = FALSE;
continue;
}
ip_str = g_string_new("");
str = "";
ips = 0;
device.name = g_strdup(if_info->name);
descr = capture_dev_user_descr_find(if_info->name);
if (descr != NULL) {
if_string = g_strdup_printf("%s: %s", descr, if_info->name);
g_free(descr);
} else {
if (if_info->vendor_description != NULL) {
if_string = g_strdup_printf("%s: %s", if_info->vendor_description, if_info->name);
} else {
if_string = g_strdup(if_info->name);
}
}
if (if_info->loopback) {
device.display_name = g_strdup_printf("%s (loopback)", if_string);
} else {
device.display_name = g_strdup(if_string);
}
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
if ((device.buffer = capture_dev_user_buffersize_find(if_string)) == -1) {
device.buffer = global_capture_opts.default_options.buffer_size;
}
#endif
if ((device.pmode = capture_dev_user_pmode_find(if_string)) == -1) {
device.pmode = global_capture_opts.default_options.promisc_mode;
}
device.has_snaplen = global_capture_opts.default_options.has_snaplen;
if ((device.snaplen = capture_dev_user_snaplen_find(if_string)) == -1) {
device.snaplen = global_capture_opts.default_options.snaplen;
}
device.cfilter = g_strdup(global_capture_opts.default_options.cfilter);
monitor_mode = prefs_capture_device_monitor_mode(if_string);
caps = capture_get_if_capabilities(if_string, monitor_mode, NULL, main_window_update);
gtk_list_store_append (GTK_LIST_STORE(model), &iter);
for (; (curr_addr = g_slist_nth(if_info->addrs, ips)) != NULL; ips++) {
if (ips != 0) {
g_string_append(ip_str, "\n");
}
addr = (if_addr_t *)curr_addr->data;
switch (addr->ifat_type) {
case IF_AT_IPv4:
g_string_append(ip_str, ip_to_str((guint8 *)&addr->addr.ip4_addr));
break;
case IF_AT_IPv6:
g_string_append(ip_str, ip6_to_str((struct e_in6_addr *)&addr->addr.ip6_addr));
break;
default:
break;
}
}
linktype_count = 0;
device.links = NULL;
if (caps != NULL) {
#ifdef HAVE_PCAP_CREATE
device.monitor_mode_enabled = monitor_mode;
device.monitor_mode_supported = caps->can_set_rfmon;
#endif
for (lt_entry = caps->data_link_types; lt_entry != NULL; lt_entry = g_list_next(lt_entry)) {
data_link_info = (data_link_info_t *)lt_entry->data;
linkr = (link_row *)g_malloc(sizeof(link_row));
if (data_link_info->description != NULL) {
str = g_strdup_printf("%s", data_link_info->description);
linkr->dlt = data_link_info->dlt;
} else {
str = g_strdup_printf("%s (not supported)", data_link_info->name);
linkr->dlt = -1;
}
if (linktype_count == 0) {
link_type_name = g_strdup(str);
device.active_dlt = data_link_info->dlt;
}
linkr->name = g_strdup(str);
g_free(str);
device.links = g_list_append(device.links, linkr);
linktype_count++;
}
} else {
#if defined(HAVE_PCAP_CREATE)
device.monitor_mode_enabled = FALSE;
device.monitor_mode_supported = FALSE;
#endif
device.active_dlt = -1;
link_type_name = g_strdup("default");
}
device.addresses = g_strdup(ip_str->str);
device.no_addresses = ips;
if (ips == 0) {
temp = g_strdup_printf("<b>%s</b>", device.display_name);
} else {
temp = g_strdup_printf("<b>%s</b>\n<span size='small'>%s</span>", device.display_name, device.addresses);
}
#ifdef HAVE_PCAP_REMOTE
device.remote_opts.src_type= global_remote_opts.src_type;
if (device.remote_opts.src_type == CAPTURE_IFREMOTE) {
device.local = FALSE;
}
device.remote_opts.remote_host_opts.remote_host = g_strdup(global_remote_opts.remote_host_opts.remote_host);
device.remote_opts.remote_host_opts.remote_port = g_strdup(global_remote_opts.remote_host_opts.remote_port);
device.remote_opts.remote_host_opts.auth_type = global_remote_opts.remote_host_opts.auth_type;
device.remote_opts.remote_host_opts.auth_username = g_strdup(global_remote_opts.remote_host_opts.auth_username);
device.remote_opts.remote_host_opts.auth_password = g_strdup(global_remote_opts.remote_host_opts.auth_password);
device.remote_opts.remote_host_opts.datatx_udp = global_remote_opts.remote_host_opts.datatx_udp;
device.remote_opts.remote_host_opts.nocap_rpcap = global_remote_opts.remote_host_opts.nocap_rpcap;
device.remote_opts.remote_host_opts.nocap_local = global_remote_opts.remote_host_opts.nocap_local;
#else
device.local = TRUE;
#endif
#ifdef HAVE_PCAP_SETSAMPLING
device.remote_opts.sampling_method = global_remote_opts.sampling_method;
device.remote_opts.sampling_param = global_remote_opts.sampling_param;
#endif
device.selected = TRUE;
global_capture_opts.num_selected++;
g_array_append_val(global_capture_opts.all_ifaces, device);
snaplen_string = g_strdup_printf("%d", device.snaplen);
#if defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, FALSE, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, link_type_name, PMODE, (device.pmode?"enabled":"disabled"), SNAPLEN, snaplen_string, BUFFER, device.buffer, MONITOR, "no",FILTER, "",-1);
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, FALSE, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, link_type_name, PMODE, (device.pmode?"enabled":"disabled"), SNAPLEN, snaplen_string, BUFFER, device.buffer, FILTER, "",-1);
#else
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, FALSE, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, link_type_name, PMODE, (device.pmode?"enabled":"disabled"), SNAPLEN, snaplen_string, -1);
#endif
g_string_free(ip_str, TRUE);
#ifdef HAVE_PCAP_REMOTE
add_interface_to_list(global_capture_opts.all_ifaces->len-1);
#endif
}
gtk_tree_view_set_model(GTK_TREE_VIEW(if_cb), model);
}
static void
update_interface_list(void)
{
GtkWidget *iftype_cbx;
GList *if_list, *if_r_list;
int iftype_id, err;
gchar *err_str;
if (cap_open_w == NULL)
return;
iftype_cbx = (GtkWidget *)g_object_get_data(G_OBJECT(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY)), E_REMOTE_HOST_TE_KEY);
iftype_id = CAPTURE_IFREMOTE;
if (iftype_id >= CAPTURE_IFREMOTE) {
if_r_list = get_remote_interface_list(global_remote_opts.remote_host_opts.remote_host,
global_remote_opts.remote_host_opts.remote_port,
global_remote_opts.remote_host_opts.auth_type,
global_remote_opts.remote_host_opts.auth_username,
global_remote_opts.remote_host_opts.auth_password,
&err, &err_str);
if_list = if_r_list;
} else {
if_list = capture_interface_list(&err, &err_str, main_window_update);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_IF_LIST_KEY, NULL);
}
if (if_list == NULL &&
(err == CANT_GET_INTERFACE_LIST || err == DONT_HAVE_PCAP)) {
gpointer dialog = simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_str);
g_free(err_str);
if (iftype_id >= CAPTURE_IFREMOTE) {
simple_dialog_set_cb(dialog, error_list_remote_interface_cb, iftype_cbx);
return;
}
} else if (iftype_id == CAPTURE_IFREMOTE) {
insert_new_rows(if_list);
refresh_non_local_interface_lists();
}
}
static void
capture_remote_adjust_sensitivity(GtkWidget *tb _U_, gpointer parent_w)
{
GtkWidget *auth_passwd_rb,
*username_lb, *username_te,
*passwd_lb, *passwd_te;
gboolean state;
auth_passwd_rb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_REMOTE_AUTH_PASSWD_KEY);
username_lb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_REMOTE_USERNAME_LB_KEY);
username_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w),
E_REMOTE_USERNAME_TE_KEY);
passwd_lb = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_REMOTE_PASSWD_LB_KEY);
passwd_te = (GtkWidget *)g_object_get_data(G_OBJECT(parent_w), E_REMOTE_PASSWD_TE_KEY);
state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(auth_passwd_rb));
gtk_widget_set_sensitive(GTK_WIDGET(username_lb), state);
gtk_widget_set_sensitive(GTK_WIDGET(username_te), state);
gtk_widget_set_sensitive(GTK_WIDGET(passwd_lb), state);
gtk_widget_set_sensitive(GTK_WIDGET(passwd_te), state);
}
static void
capture_remote_ok_cb(GtkWidget *win _U_, GtkWidget *remote_w)
{
GtkWidget *host_te, *port_te, *username_te, *passwd_te, *auth_passwd_rb;
gchar *hostname;
struct remote_host *rh;
if (remote_w == NULL) {
return;
}
host_te = (GtkWidget *)g_object_get_data(G_OBJECT(remote_w), E_REMOTE_HOST_TE_KEY);
hostname = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(host_te));
port_te = (GtkWidget *)g_object_get_data(G_OBJECT(remote_w), E_REMOTE_PORT_TE_KEY);
username_te = (GtkWidget *)g_object_get_data(G_OBJECT(remote_w),
E_REMOTE_USERNAME_TE_KEY);
passwd_te = (GtkWidget *)g_object_get_data(G_OBJECT(remote_w), E_REMOTE_PASSWD_TE_KEY);
auth_passwd_rb = (GtkWidget *) g_object_get_data(G_OBJECT(remote_w), E_REMOTE_AUTH_PASSWD_KEY);
g_free(global_remote_opts.remote_host_opts.remote_host);
global_remote_opts.remote_host_opts.remote_host = hostname;
g_free(global_remote_opts.remote_host_opts.remote_port);
global_remote_opts.remote_host_opts.remote_port = g_strdup(gtk_entry_get_text(GTK_ENTRY(port_te)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(auth_passwd_rb)))
global_remote_opts.remote_host_opts.auth_type = CAPTURE_AUTH_PWD;
else
global_remote_opts.remote_host_opts.auth_type = CAPTURE_AUTH_NULL;
g_free(global_remote_opts.remote_host_opts.auth_username);
global_remote_opts.remote_host_opts.auth_username =
g_strdup(gtk_entry_get_text(GTK_ENTRY(username_te)));
g_free(global_remote_opts.remote_host_opts.auth_password);
global_remote_opts.remote_host_opts.auth_password =
g_strdup(gtk_entry_get_text(GTK_ENTRY(passwd_te)));
rh = g_malloc (sizeof (*rh));
rh->r_host = g_strdup(global_remote_opts.remote_host_opts.remote_host);
rh->remote_port = g_strdup(global_remote_opts.remote_host_opts.remote_port);
rh->auth_type = global_remote_opts.remote_host_opts.auth_type;
rh->auth_password = g_strdup("");
rh->auth_username = g_strdup("");
recent_add_remote_host(hostname, rh);
update_interface_list();
fill_remote_list();
window_destroy(GTK_WIDGET(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY)));
}
static void
capture_remote_cancel_cb(GtkWidget *win, gpointer data)
{
window_cancel_button_cb (win, data);
}
static void
select_if_type_cb(GtkComboBox *iftype_cbx, gpointer data _U_)
{
gchar *string;
GtkWidget *port_te, *auth_rb, *user_te, *pass_te;
GtkWidget *remote_w;
struct remote_host *rh;
int new_iftype = gtk_combo_box_get_active(GTK_COMBO_BOX(iftype_cbx));
gint num_remote = recent_get_remote_host_list_size();
if (new_iftype != -1 && new_iftype == num_remote+1) {
free_remote_host_list();
num_remote += 2;
while (num_remote--) {
gtk_combo_box_text_remove (GTK_COMBO_BOX_TEXT(iftype_cbx), num_remote);
}
remote_w = g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY);
window_destroy(GTK_WIDGET(remote_w));
capture_remote_cb(GTK_WIDGET(iftype_cbx), FALSE);
} else {
string = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(iftype_cbx));
rh = recent_get_remote_host(string);
g_free (string);
if (rh) {
remote_w = g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY);
port_te = g_object_get_data(G_OBJECT(remote_w), E_REMOTE_PORT_TE_KEY);
gtk_entry_set_text(GTK_ENTRY(port_te), rh->remote_port);
auth_rb = g_object_get_data(G_OBJECT(remote_w), E_REMOTE_AUTH_PASSWD_KEY);
if (rh->auth_type == CAPTURE_AUTH_PWD) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(auth_rb), TRUE);
} else {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(auth_rb), FALSE);
}
user_te = g_object_get_data(G_OBJECT(remote_w), E_REMOTE_USERNAME_TE_KEY);
gtk_entry_set_text(GTK_ENTRY(user_te), rh->auth_username);
pass_te = g_object_get_data(G_OBJECT(remote_w), E_REMOTE_PASSWD_TE_KEY);
gtk_entry_set_text(GTK_ENTRY(pass_te), rh->auth_password);
}
}
}
static void
capture_remote_cb(GtkWidget *w, gboolean focus_username)
{
GtkWidget *remote_w,
*main_vb, *host_grid,
*host_lb, *host_te, *port_lb, *port_te,
*auth_fr, *auth_vb,
*auth_null_rb, *auth_passwd_rb, *auth_passwd_grid,
*user_lb, *user_te, *passwd_lb, *passwd_te,
*bbox, *ok_but, *cancel_bt;
gchar *title;
GSList *auth_group;
title = create_user_window_title("Wireshark: Remote Interface");
remote_w = dlg_window_new(title);
gtk_window_set_transient_for(GTK_WINDOW(remote_w), GTK_WINDOW(interface_management_w));
g_object_set_data(G_OBJECT(remote_w), E_CAP_REMOTE_CALLER_PTR_KEY, interface_management_w);
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY, remote_w);
g_free(title);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(remote_w), main_vb);
host_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(host_grid), DLG_LABEL_SPACING);
ws_gtk_grid_set_column_spacing(GTK_GRID(host_grid), DLG_UNRELATED_SPACING);
gtk_box_pack_start(GTK_BOX(main_vb), host_grid, FALSE, FALSE, 0);
host_lb = gtk_label_new("Host:");
ws_gtk_grid_attach_defaults(GTK_GRID (host_grid), host_lb, 0, 0, 1, 1);
host_te = iftype_combo_box_new();
ws_gtk_grid_attach_defaults(GTK_GRID (host_grid), host_te, 1, 0, 1, 1);
port_lb = gtk_label_new("Port:");
ws_gtk_grid_attach_defaults(GTK_GRID (host_grid), port_lb, 0, 1, 1, 1);
port_te = gtk_entry_new();
gtk_widget_set_tooltip_text(port_te, "Enter the TCP port number used by RPCAP server at remote host "
"(leave it empty for default port number).");
ws_gtk_grid_attach_defaults(GTK_GRID (host_grid), port_te, 1, 1, 1, 1);
auth_fr = gtk_frame_new("Authentication");
gtk_box_pack_start(GTK_BOX (main_vb), auth_fr, TRUE, TRUE, 0);
auth_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(auth_vb), 5);
gtk_container_add(GTK_CONTAINER(auth_fr), auth_vb);
auth_null_rb = gtk_radio_button_new_with_label(NULL,
"Null authentication");
gtk_box_pack_start(GTK_BOX(auth_vb), auth_null_rb, TRUE, TRUE, 0);
auth_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(auth_null_rb));
auth_passwd_rb = gtk_radio_button_new_with_label(auth_group,
"Password authentication");
gtk_box_pack_start(GTK_BOX(auth_vb), auth_passwd_rb, TRUE, TRUE, 0);
g_signal_connect(auth_passwd_rb, "toggled",
G_CALLBACK(capture_remote_adjust_sensitivity), remote_w);
auth_passwd_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(auth_passwd_grid), DLG_LABEL_SPACING);
ws_gtk_grid_set_column_spacing(GTK_GRID(auth_passwd_grid), DLG_UNRELATED_SPACING);
gtk_box_pack_start(GTK_BOX(auth_vb), auth_passwd_grid, FALSE, FALSE, 0);
user_lb = gtk_label_new("Username:");
ws_gtk_grid_attach_defaults(GTK_GRID (auth_passwd_grid), user_lb, 0, 0, 1, 1);
user_te = gtk_entry_new();
ws_gtk_grid_attach_defaults(GTK_GRID (auth_passwd_grid), user_te, 1, 0, 1, 1);
passwd_lb = gtk_label_new("Password:");
ws_gtk_grid_attach_defaults(GTK_GRID (auth_passwd_grid), passwd_lb, 0, 1, 1, 1);
passwd_te = gtk_entry_new();
gtk_entry_set_visibility(GTK_ENTRY(passwd_te), FALSE);
ws_gtk_grid_attach_defaults(GTK_GRID (auth_passwd_grid), passwd_te, 1, 1, 1, 1);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
ok_but = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_set_can_default(ok_but, TRUE);
g_signal_connect(ok_but, "clicked", G_CALLBACK(capture_remote_ok_cb), remote_w);
gtk_widget_set_tooltip_text(ok_but,
"Accept remote host parameters and lookup "
"remote interfaces.");
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_OK_BT_KEY, ok_but);
cancel_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel and exit dialog.");
window_set_cancel_button(remote_w, cancel_bt, capture_remote_cancel_cb);
if (focus_username) {
gtk_widget_grab_focus(user_te);
}
gtk_widget_grab_default(ok_but);
dlg_set_activate(port_te, ok_but);
dlg_set_activate(user_te, ok_but);
dlg_set_activate(passwd_te, ok_but);
g_signal_connect(remote_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_HOST_TE_KEY, host_te);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_PORT_TE_KEY, port_te);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_AUTH_NULL_KEY, auth_null_rb);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_AUTH_PASSWD_KEY, auth_passwd_rb);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_USERNAME_LB_KEY, user_lb);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_USERNAME_TE_KEY, user_te);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_PASSWD_LB_KEY, passwd_lb);
g_object_set_data(G_OBJECT(remote_w), E_REMOTE_PASSWD_TE_KEY, passwd_te);
if (global_remote_opts.remote_host_opts.auth_type == CAPTURE_AUTH_PWD)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(auth_passwd_rb), TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(auth_null_rb), TRUE);
capture_remote_adjust_sensitivity(NULL, remote_w);
gtk_widget_show_all(remote_w);
window_present(remote_w);
}
static void
options_remote_destroy_cb(GtkWidget *win, gpointer user_data _U_)
{
GtkWidget *caller;
caller = g_object_get_data(G_OBJECT(win), E_OPT_REMOTE_CALLER_PTR_KEY);
g_object_set_data(G_OBJECT(caller), E_OPT_REMOTE_DIALOG_PTR_KEY, NULL);
}
static void
options_remote_ok_cb(GtkWidget *win _U_, GtkWidget *parent_w)
{
GtkWidget *datatx_udp_cb, *nocap_rpcap_cb;
#ifdef HAVE_PCAP_SETSAMPLING
GtkWidget *samp_none_rb, *samp_count_rb, *samp_timer_rb,
*samp_count_sb, *samp_timer_sb;
#endif
interface_t device;
if (parent_w == NULL)
return;
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
datatx_udp_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_DATATX_UDP_CB_KEY);
nocap_rpcap_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_NOCAP_RPCAP_CB_KEY);
device.remote_opts.remote_host_opts.datatx_udp =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(datatx_udp_cb));
device.remote_opts.remote_host_opts.nocap_rpcap =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(nocap_rpcap_cb));
#ifdef HAVE_PCAP_SETSAMPLING
samp_none_rb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_NONE_RB_KEY);
samp_count_rb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_COUNT_RB_KEY);
samp_timer_rb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_TIMER_RB_KEY);
samp_count_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_COUNT_SB_KEY);
samp_timer_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_TIMER_SB_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(samp_none_rb)))
device.remote_opts.sampling_method = CAPTURE_SAMP_NONE;
else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(samp_count_rb))) {
device.remote_opts.sampling_method = CAPTURE_SAMP_BY_COUNT;
device.remote_opts.sampling_param = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(samp_count_sb));
} else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(samp_timer_rb))) {
device.remote_opts.sampling_method = CAPTURE_SAMP_BY_TIMER;
device.remote_opts.sampling_param = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(samp_timer_sb));
}
#endif
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
window_destroy(GTK_WIDGET(parent_w));
}
static void
options_prep_adjust_sensitivity(GtkWidget *tb _U_, gpointer parent_w)
{
GtkWidget *samp_count_rb, *samp_timer_rb,
*samp_count_sb, *samp_timer_sb;
samp_count_rb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_COUNT_RB_KEY);
samp_timer_rb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_TIMER_RB_KEY);
samp_count_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_COUNT_SB_KEY);
samp_timer_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SAMP_TIMER_SB_KEY);
if (samp_count_sb && samp_count_rb)
gtk_widget_set_sensitive(GTK_WIDGET(samp_count_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(samp_count_rb)));
if (samp_timer_sb && samp_timer_rb)
gtk_widget_set_sensitive(GTK_WIDGET(samp_timer_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(samp_timer_rb)));
}
static void
options_remote_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *opt_remote_w, *main_vb;
GtkWidget *caller, *bbox, *ok_but, *cancel_bt;
GtkWidget *capture_fr, *capture_vb;
GtkWidget *nocap_rpcap_cb, *datatx_udp_cb;
#ifdef HAVE_PCAP_SETSAMPLING
GtkWidget *sampling_fr, *sampling_vb, *sampling_grid, *sampling_lb,
*samp_none_rb, *samp_count_rb, *samp_timer_rb,
*samp_count_sb, *samp_timer_sb;
GtkAdjustment *samp_count_adj, *samp_timer_adj;
GSList *samp_group;
#endif
interface_t device;
caller = gtk_widget_get_toplevel(w);
opt_remote_w = g_object_get_data(G_OBJECT(caller), E_OPT_REMOTE_DIALOG_PTR_KEY);
if (opt_remote_w != NULL) {
reactivate_window(opt_remote_w);
return;
}
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
opt_remote_w = dlg_window_new("Remote Capture Settings");
gtk_window_set_modal(GTK_WINDOW(opt_remote_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(opt_remote_w), GTK_WINDOW(caller));
gtk_window_set_type_hint(GTK_WINDOW(opt_remote_w), GDK_WINDOW_TYPE_HINT_DIALOG);
g_object_set_data(G_OBJECT(opt_remote_w), E_OPT_REMOTE_CALLER_PTR_KEY, caller);
g_object_set_data(G_OBJECT(caller), E_OPT_REMOTE_DIALOG_PTR_KEY, opt_remote_w);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(opt_remote_w), main_vb);
capture_fr = gtk_frame_new("Capture Options");
gtk_box_pack_start(GTK_BOX (main_vb), capture_fr, TRUE, TRUE, 0);
capture_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(capture_vb), 5);
gtk_container_add(GTK_CONTAINER(capture_fr), capture_vb);
nocap_rpcap_cb = gtk_check_button_new_with_mnemonic("Do not capture own RPCAP traffic");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(nocap_rpcap_cb),
device.remote_opts.remote_host_opts.nocap_rpcap);
gtk_box_pack_start(GTK_BOX (capture_vb), nocap_rpcap_cb, TRUE, TRUE, 0);
datatx_udp_cb = gtk_check_button_new_with_mnemonic("Use UDP for data transfer");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(datatx_udp_cb),
device.remote_opts.remote_host_opts.datatx_udp);
gtk_box_pack_start(GTK_BOX (capture_vb), datatx_udp_cb, TRUE, TRUE, 0);
#ifdef HAVE_PCAP_SETSAMPLING
sampling_fr = gtk_frame_new("Sampling Options");
gtk_box_pack_start(GTK_BOX (main_vb), sampling_fr, TRUE, TRUE, 0);
sampling_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(sampling_vb), 5);
gtk_container_add(GTK_CONTAINER(sampling_fr), sampling_vb);
sampling_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(sampling_grid), DLG_LABEL_SPACING);
ws_gtk_grid_set_column_spacing(GTK_GRID(sampling_grid), DLG_UNRELATED_SPACING);
gtk_box_pack_start(GTK_BOX(sampling_vb), sampling_grid, FALSE, FALSE, 0);
samp_none_rb = gtk_radio_button_new_with_label(NULL, "None");
if (device.remote_opts.sampling_method == CAPTURE_SAMP_NONE)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(samp_none_rb), TRUE);
g_signal_connect(samp_none_rb, "toggled",
G_CALLBACK(options_prep_adjust_sensitivity), opt_remote_w);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), samp_none_rb, 0, 0, 1, 1);
samp_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(samp_none_rb));
samp_count_rb = gtk_radio_button_new_with_label(samp_group, "1 of");
if (device.remote_opts.sampling_method == CAPTURE_SAMP_BY_COUNT)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(samp_count_rb), TRUE);
g_signal_connect(samp_count_rb, "toggled",
G_CALLBACK(options_prep_adjust_sensitivity), opt_remote_w);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), samp_count_rb, 0, 1, 1, 1);
samp_count_adj = (GtkAdjustment *) gtk_adjustment_new(
(gfloat)device.remote_opts.sampling_param,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
samp_count_sb = gtk_spin_button_new(samp_count_adj, 0, 0);
gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(samp_count_sb), TRUE);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), samp_count_sb, 1, 1, 1, 1);
sampling_lb = gtk_label_new("packets");
gtk_misc_set_alignment(GTK_MISC(sampling_lb), 0, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), sampling_lb, 2, 1, 1, 1);
samp_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(samp_count_rb));
samp_timer_rb = gtk_radio_button_new_with_label(samp_group, "1 every");
if (device.remote_opts.sampling_method == CAPTURE_SAMP_BY_TIMER)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(samp_timer_rb), TRUE);
g_signal_connect(samp_timer_rb, "toggled",
G_CALLBACK(options_prep_adjust_sensitivity), opt_remote_w);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), samp_timer_rb, 0, 2, 1, 1);
samp_timer_adj = (GtkAdjustment *) gtk_adjustment_new(
(gfloat)device.remote_opts.sampling_param,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
samp_timer_sb = gtk_spin_button_new(samp_timer_adj, 0, 0);
gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(samp_timer_sb), TRUE);
ws_gtk_grid_attach_defaults(GTK_GRID(sampling_grid), samp_timer_sb, 1, 2, 1, 1);
sampling_lb = gtk_label_new("milliseconds");
gtk_misc_set_alignment(GTK_MISC(sampling_lb), 0, 0.5f);
ws_gtk_grid_attach_defaults(GTK_GRID (sampling_grid), sampling_lb, 2, 2, 1, 1);
#endif
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
ok_but = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_but, "clicked", G_CALLBACK(options_remote_ok_cb), opt_remote_w);
gtk_widget_set_tooltip_text(ok_but, "Accept parameters and close dialog");
cancel_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt, "Cancel and exit dialog.");
window_set_cancel_button(opt_remote_w, cancel_bt, window_cancel_button_cb);
gtk_widget_grab_default(ok_but);
g_signal_connect(opt_remote_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(opt_remote_w, "destroy", G_CALLBACK(options_remote_destroy_cb), NULL);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_NOCAP_RPCAP_CB_KEY, nocap_rpcap_cb);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_DATATX_UDP_CB_KEY, datatx_udp_cb);
#ifdef HAVE_PCAP_SETSAMPLING
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_SAMP_NONE_RB_KEY, samp_none_rb);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_SAMP_COUNT_RB_KEY, samp_count_rb);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_SAMP_COUNT_SB_KEY, samp_count_sb);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_SAMP_TIMER_RB_KEY, samp_timer_rb);
g_object_set_data(G_OBJECT(opt_remote_w), E_CAP_SAMP_TIMER_SB_KEY, samp_timer_sb);
#endif
#ifdef HAVE_PCAP_SETSAMPLING
options_prep_adjust_sensitivity(NULL, opt_remote_w);
#endif
gtk_widget_show_all(opt_remote_w);
window_present(opt_remote_w);
}
static void
compile_bpf_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
compile_bpf_w = NULL;
}
static void
select_first_entry(void)
{
GtkWidget *view;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreeSelection *selection;
view = (GtkWidget *)g_object_get_data(G_OBJECT(compile_bpf_w), E_COMPILE_TREE_VIEW_INTERFACES);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(view));
gtk_tree_model_get_iter_first(model, &iter);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
gtk_tree_selection_select_iter(selection, &iter);
}
static void
add_page(gchar *name, gchar *text, gboolean error)
{
GtkWidget *view, *icon;
GtkTreeModel *model;
GtkTreeIter iter;
view = (GtkWidget *)g_object_get_data(G_OBJECT(compile_bpf_w), E_COMPILE_TREE_VIEW_INTERFACES);
model = gtk_tree_view_get_model(GTK_TREE_VIEW(view));
gtk_list_store_append (GTK_LIST_STORE(model), &iter);
if (error) {
icon = pixbuf_to_widget(expert_error_pb_data);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, COMPILE_ERROR, 1, SIGN, gtk_image_get_pixbuf(GTK_IMAGE(icon)), INAME, name, -1);
} else {
icon = pixbuf_to_widget(expert_ok_pb_data);
gtk_list_store_set(GTK_LIST_STORE(model), &iter, COMPILE_ERROR, 0, SIGN, gtk_image_get_pixbuf(GTK_IMAGE(icon)), INAME, name, -1);
}
g_hash_table_insert(compile_results, name, text);
}
static void
compile_tree_select_cb(GtkTreeSelection *sel, gpointer dummy _U_)
{
gchar *name, *text;
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *textview;
GtkTextBuffer *buffer;
guint error;
if (gtk_tree_selection_get_selected(sel, &model, &iter))
{
gtk_tree_model_get(model, &iter, COMPILE_ERROR, &error, INAME, &name, -1);
text = (gchar *)g_hash_table_lookup(compile_results, name);
textview = (GtkWidget *)g_object_get_data(G_OBJECT(compile_bpf_w), CR_MAIN_NB);
if (error == 1) {
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_CHAR);
} else {
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_NONE);
}
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
gtk_text_buffer_set_text(buffer, text, -1);
gtk_widget_show_all(compile_bpf_w);
}
}
static void
compile_results_prep(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *main_box, *main_vb, *bbox, *ok_btn, *top_hb, *ct_sb;
GtkListStore *store;
GtkWidget *view, *scrolled_win, *textview;
GtkTreeSelection *selection;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
PangoFontDescription *font;
if (compile_bpf_w != NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "The requested dialog is already open. Please close it first.");
return;
}
compile_bpf_w = dlg_window_new("Compile selected BPFs");
gtk_window_set_position(GTK_WINDOW(compile_bpf_w), GTK_WIN_POS_CENTER_ON_PARENT);
gtk_window_set_default_size(GTK_WINDOW(compile_bpf_w), 600, 400);
gtk_window_set_modal(GTK_WINDOW(compile_bpf_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(compile_bpf_w), GTK_WINDOW(cap_open_w));
gtk_container_set_border_width(GTK_CONTAINER(compile_bpf_w), 6);
main_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_box), 6);
gtk_container_add(GTK_CONTAINER(compile_bpf_w), main_box);
gtk_widget_show(main_box);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_box_pack_start(GTK_BOX(main_box), top_hb, TRUE, TRUE, 0);
gtk_widget_show(top_hb);
ct_sb = scrolled_window_new(NULL, NULL);
gtk_widget_set_size_request(GTK_WIDGET(ct_sb), 50, -1);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(ct_sb),
GTK_SHADOW_IN);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ct_sb),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_box_pack_start(GTK_BOX(top_hb), ct_sb, TRUE, TRUE, 0);
gtk_widget_show(ct_sb);
g_object_set_data(G_OBJECT(compile_bpf_w), E_COMPILE_SW_SCROLLW_KEY, ct_sb);
store = gtk_list_store_new(3, G_TYPE_UINT, GDK_TYPE_PIXBUF, G_TYPE_STRING);
view = gtk_tree_view_new_with_model (GTK_TREE_MODEL(store));
gtk_tree_view_set_model(GTK_TREE_VIEW(view), GTK_TREE_MODEL (store));
g_object_set(G_OBJECT(view), "headers-visible", FALSE, NULL);
g_object_set_data(G_OBJECT(compile_bpf_w), E_COMPILE_TREE_VIEW_INTERFACES, view);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
column = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_text_new();
gtk_tree_view_column_pack_start(column, renderer, TRUE);
gtk_tree_view_column_set_attributes(column, renderer, "text", COMPILE_ERROR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_visible(column, FALSE);
column = gtk_tree_view_column_new();
renderer = gtk_cell_renderer_pixbuf_new();
gtk_tree_view_column_pack_start(column, renderer, FALSE);
gtk_tree_view_column_set_attributes(column, renderer, "pixbuf", SIGN, NULL);
renderer = gtk_cell_renderer_text_new();
gtk_tree_view_column_pack_start(column, renderer, TRUE);
gtk_tree_view_column_set_attributes(column, renderer, "text", INAME, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), 0), TRUE);
g_signal_connect(selection, "changed", G_CALLBACK(compile_tree_select_cb), NULL);
gtk_container_add(GTK_CONTAINER(ct_sb), view);
gtk_widget_show(view);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 10, FALSE);
gtk_box_pack_start(GTK_BOX(top_hb), main_vb, TRUE, TRUE, 0);
gtk_widget_show(main_vb);
g_object_set_data(G_OBJECT(compile_bpf_w), CR_MAIN_NB, main_vb);
font = pango_font_description_from_string("Monospace");
textview = gtk_text_view_new();
#if GTK_CHECK_VERSION(3, 0, 0)
gtk_widget_override_font(textview, font);
#else
gtk_widget_modify_font(textview, font);
#endif
scrolled_win = gtk_scrolled_window_new(NULL, NULL);
gtk_widget_set_size_request(GTK_WIDGET(scrolled_win), 350, -1);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_win),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_win),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(scrolled_win), textview);
gtk_box_pack_start(GTK_BOX(main_vb), scrolled_win, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(compile_bpf_w), CR_MAIN_NB, textview);
bbox = dlg_button_row_new(GTK_STOCK_OK, NULL);
gtk_box_pack_start(GTK_BOX(main_box), bbox, FALSE, FALSE, 0);
ok_btn = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_grab_focus(ok_btn);
gtk_widget_grab_default(ok_btn);
window_set_cancel_button(compile_bpf_w, ok_btn, window_cancel_button_cb);
g_signal_connect(compile_bpf_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(compile_bpf_w, "destroy", G_CALLBACK(compile_bpf_destroy_cb), NULL);
gtk_widget_show_all(compile_bpf_w);
window_present(compile_bpf_w);
compile_results = g_hash_table_new(g_str_hash, g_str_equal);
}
static void
capture_all_filter_compile_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
pcap_t *pd;
struct bpf_program fcode;
GtkWidget *filter_cm;
gchar *filter_text;
guint i;
gboolean set = FALSE;
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY);
if (!filter_cm)
return;
if (global_capture_opts.all_ifaces->len > 0) {
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.selected || device.hidden) {
continue;
}
if (device.active_dlt == -1) {
g_assert_not_reached();
}
if (!set) {
set = TRUE;
compile_results_prep(NULL, NULL);
}
pd = pcap_open_dead(device.active_dlt, DUMMY_SNAPLENGTH);
filter_text = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(filter_cm));
g_mutex_lock(pcap_compile_mtx);
#ifdef PCAP_NETMASK_UNKNOWN
if (pcap_compile(pd, &fcode, filter_text, 1 , PCAP_NETMASK_UNKNOWN) < 0)
#else
if (pcap_compile(pd, &fcode, filter_text, 1 , 0) < 0)
#endif
{
g_mutex_unlock(pcap_compile_mtx);
add_page(device.name, g_strdup(pcap_geterr(pd)), TRUE);
} else {
GString *bpf_code_dump = g_string_new("");
struct bpf_insn *insn = fcode.bf_insns;
int ii, n = fcode.bf_len;
gchar *bpf_code_str;
for (ii = 0; ii < n; ++insn, ++ii) {
g_string_append(bpf_code_dump, bpf_image(insn, ii));
g_string_append(bpf_code_dump, "\n");
}
bpf_code_str = g_string_free(bpf_code_dump, FALSE);
g_mutex_unlock(pcap_compile_mtx);
add_page(device.name, g_strdup(bpf_code_str), FALSE);
g_free(bpf_code_str);
}
g_free(filter_text);
pcap_close(pd);
}
}
select_first_entry();
}
static void
compile_results_win(gchar *text, gboolean error)
{
GtkWidget *main_box, *bbox, *ok_btn, *results_w;
GtkWidget *scrolled_win, *textview;
PangoFontDescription *font;
GtkTextBuffer *buffer;
results_w = dlg_window_new("Compile results");
gtk_window_set_position(GTK_WINDOW(results_w), GTK_WIN_POS_CENTER_ON_PARENT);
gtk_window_set_default_size(GTK_WINDOW(results_w), 400, 400);
gtk_window_set_modal(GTK_WINDOW(results_w), TRUE);
gtk_window_set_transient_for(GTK_WINDOW(results_w), GTK_WINDOW(opt_edit_w));
gtk_container_set_border_width(GTK_CONTAINER(results_w), 6);
main_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_box), 6);
gtk_container_add(GTK_CONTAINER(results_w), main_box);
gtk_widget_show(main_box);
font = pango_font_description_from_string("Monospace");
textview = gtk_text_view_new();
#if GTK_CHECK_VERSION(3, 0, 0)
gtk_widget_override_font(textview, font);
#else
gtk_widget_modify_font(textview, font);
#endif
scrolled_win = gtk_scrolled_window_new(NULL, NULL);
gtk_widget_set_size_request(GTK_WIDGET(scrolled_win), 350, -1);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_win),
GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_win),
GTK_SHADOW_IN);
gtk_container_add(GTK_CONTAINER(scrolled_win), textview);
gtk_box_pack_start(GTK_BOX(main_box), scrolled_win, TRUE, TRUE, 0);
if (error == 1) {
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_CHAR);
} else {
gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_NONE);
}
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
gtk_text_buffer_set_text(buffer, g_strdup(text), -1);
bbox = dlg_button_row_new(GTK_STOCK_OK, NULL);
gtk_box_pack_start(GTK_BOX(main_box), bbox, FALSE, FALSE, 0);
ok_btn = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
gtk_widget_grab_focus(ok_btn);
gtk_widget_grab_default(ok_btn);
window_set_cancel_button(results_w, ok_btn, window_cancel_button_cb);
g_signal_connect(results_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(results_w, "destroy", G_CALLBACK(compile_bpf_destroy_cb), NULL);
gtk_widget_show_all(results_w);
window_present(results_w);
}
static void
options_edit_destroy_cb(GtkWidget *win, gpointer user_data _U_)
{
GtkWidget *caller;
caller = (GtkWidget *)g_object_get_data(G_OBJECT(win), E_OPT_EDIT_CALLER_PTR_KEY);
g_object_set_data(G_OBJECT(caller), E_OPT_EDIT_DIALOG_PTR_KEY, NULL);
}
static void
update_options_table(gint indx)
{
interface_t device;
GtkTreePath *path;
GtkTreeView *if_cb;
GtkTreeModel *model;
GtkTreeIter iter;
gchar *temp, *path_str, *snaplen_string, *linkname;
GList *list;
link_row *linkr = NULL;
gboolean enabled;
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
if (!device.hidden) {
if (device.no_addresses == 0) {
temp = g_strdup_printf("<b>%s</b>", device.display_name);
} else {
temp = g_strdup_printf("<b>%s</b>\n<span size='small'>%s</span>", device.display_name, device.addresses);
}
linkname = NULL;
for (list=device.links; list!=NULL; list=g_list_next(list))
{
linkr = (link_row*)(list->data);
if (linkr->dlt == device.active_dlt) {
linkname = g_strdup(linkr->name);
break;
}
}
if (!linkname)
linkname = g_strdup("unknown");
snaplen_string = g_strdup_printf("%d", device.snaplen);
if (cap_open_w) {
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
path_str = g_strdup_printf("%d", indx);
path = gtk_tree_path_new_from_string(path_str);
model = gtk_tree_view_get_model(if_cb);
gtk_tree_model_get_iter(model, &iter, path);
gtk_tree_model_get(model, &iter, CAPTURE, &enabled, -1);
if (enabled == FALSE) {
device.selected = TRUE;
global_capture_opts.num_selected++;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
}
#if defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, MONITOR, device.monitor_mode_supported?(device.monitor_mode_enabled?"enabled":"disabled"):"n/a", FILTER, device.cfilter, -1);
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, FILTER, device.cfilter, -1);
#else
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, FILTER, device.cfilter, -1);
#endif
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
gtk_tree_path_free (path);
g_free(path_str);
}
if (interfaces_dialog_window_present()) {
update_selected_interface(g_strdup(device.name));
}
if (get_welcome_window() != NULL) {
change_interface_selection(g_strdup(device.name), device.selected);
}
g_free(linkname);
}
set_sensitivity_for_start_icon();
}
static void
save_options_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
GtkWidget *snap_cb, *snap_sb, *promisc_cb,
#ifdef HAVE_PCAP_CREATE
*monitor_cb,
#endif
*filter_cm, *linktype_combo_box;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
GtkWidget *buffer_size_sb;
#endif
#ifdef HAVE_EXTCAP
GtkWidget *extcap_vbox;
#endif
interface_t device;
gpointer ptr = NULL;
int dlt = -1;
gchar *filter_text;
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
snap_cb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_CB_KEY);
snap_sb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_SB_KEY);
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
buffer_size_sb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_BUFFER_SIZE_SB_KEY);
#endif
promisc_cb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_PROMISC_KEY);
#ifdef HAVE_PCAP_CREATE
monitor_cb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_MONITOR_KEY);
#endif
filter_cm = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CFILTER_CM_KEY);
linktype_combo_box = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_LT_CBX_KEY);
#ifdef HAVE_EXTCAP
extcap_vbox = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_EXTCAP_KEY);
#endif
if (device.links != NULL) {
if (ws_combo_box_get_active_pointer(GTK_COMBO_BOX(linktype_combo_box), &ptr)) {
if (ptr != NULL && (dlt = GPOINTER_TO_INT(ptr)) == -1)
g_assert_not_reached();
}
}
device.active_dlt = dlt;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
device.buffer = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(buffer_size_sb));
#endif
device.pmode = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(promisc_cb));
device.has_snaplen = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(snap_cb));
if (device.has_snaplen) {
if (device.snaplen != (guint)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(snap_sb))) {
}
device.snaplen = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(snap_sb));
if (device.snaplen < 1)
device.snaplen = WTAP_MAX_PACKET_SIZE;
else if (device.snaplen < MIN_PACKET_SIZE)
device.snaplen = MIN_PACKET_SIZE;
} else {
device.snaplen = WTAP_MAX_PACKET_SIZE;
}
filter_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(filter_cm));
if (device.cfilter)
g_free(device.cfilter);
g_assert(filter_text != NULL);
device.cfilter = filter_text;
#ifdef HAVE_EXTCAP
if (device.external_cap_args_settings != NULL)
g_hash_table_unref(device.external_cap_args_settings);
device.external_cap_args_settings = extcap_gtk_get_state(extcap_vbox);
#if 0
extcap_gtk_free_args(extcap_vbox);
#endif
#endif
#ifdef HAVE_PCAP_CREATE
device.monitor_mode_enabled = device.monitor_mode_supported ?
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(monitor_cb)) : FALSE;
#endif
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
window_destroy(opt_edit_w);
update_options_table(marked_row);
update_properties_all();
}
static void
adjust_snap_sensitivity(GtkWidget *tb _U_, gpointer parent_w _U_)
{
GtkWidget *snap_cb, *snap_sb;
interface_t device;
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
snap_cb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_CB_KEY);
snap_sb = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_SB_KEY);
gtk_widget_set_sensitive(GTK_WIDGET(snap_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(snap_cb)));
device.has_snaplen = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(snap_cb));
if (!device.has_snaplen) {
gtk_spin_button_set_value(GTK_SPIN_BUTTON (snap_sb), WTAP_MAX_PACKET_SIZE);
device.snaplen = WTAP_MAX_PACKET_SIZE;
}
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
}
static GtkWidget *build_extcap_options(const gchar *name, GHashTable *hash) {
GtkWidget *ret_box = NULL;
GList *arglist = NULL;
GList *elem = NULL;
arglist = extcap_get_if_configuration( name );
for ( elem = g_list_first(arglist); elem; elem = elem->next )
{
GSList *widget_list;
#if GTK_CHECK_VERSION(3, 0, 0)
ret_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);
#else
ret_box = gtk_vbox_new(FALSE, 3);
#endif
widget_list = extcap_populate_gtk_vbox((GList *) elem->data, ret_box, hash);
g_object_set_data(G_OBJECT(ret_box), EXTCAP_GTK_DATA_KEY_WIDGETLIST, widget_list);
}
return ret_box;
}
void options_interface_cb(GtkTreeView *view, GtkTreePath *path, GtkTreeViewColumn *column _U_, gpointer userdata)
{
GtkWidget *caller, *window, *swindow = NULL, *if_view,
*main_vb, *if_hb, *if_lb, *if_lb_name,
*main_hb, *left_vb,
#if defined (HAVE_AIRPCAP) || defined (HAVE_PCAP_REMOTE) || defined (HAVE_PCAP_CREATE)
*right_vb,
#endif
*capture_fr, *capture_vb,
*if_ip_hb, *if_ip_lb = NULL, *if_ip_name,
*if_vb_left, *if_vb_right,
*linktype_hb, *linktype_lb, *linktype_combo_box,
*snap_hb, *snap_cb, *snap_sb, *snap_lb,
*promisc_cb,
#ifdef HAVE_PCAP_CREATE
*monitor_cb,
#endif
*filter_hb, *filter_bt, *filter_te, *filter_cm,
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
*compile_bt,
#endif
*bbox, *ok_but, *cancel_bt,
#ifdef HAVE_EXTCAP
*extcap_vbox,
#endif
*help_bt;
GList *cf_entry, *list, *cfilter_list;
GtkAdjustment *snap_adj;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
GtkAdjustment *buffer_size_adj;
GtkWidget *buffer_size_lb, *buffer_size_sb, *buffer_size_hb;
#endif
#ifdef HAVE_PCAP_REMOTE
GtkWidget *remote_bt;
#endif
#ifdef HAVE_AIRPCAP
GtkWidget *advanced_bt;
#endif
interface_t device;
GtkTreeModel *model;
GtkTreeIter iter;
link_row *temp;
gboolean found = FALSE;
gint num_link_types, num_supported_link_types, first_supported_index;
guint i;
gchar *tok, *name;
GtkCellRenderer *renderer;
GtkListStore *store;
const gchar *new_cfilter;
#ifdef HAVE_EXTCAP
GHashTable *extcap_hash;
#endif
window = (GtkWidget *)userdata;
caller = gtk_widget_get_toplevel(GTK_WIDGET(window));
opt_edit_w = (GtkWidget *)g_object_get_data(G_OBJECT(caller), E_OPT_EDIT_DIALOG_PTR_KEY);
if (opt_edit_w != NULL) {
reactivate_window(opt_edit_w);
return;
}
device.name = NULL;
device.display_name = NULL;
device.no_addresses = 0;
device.addresses = NULL;
device.links = NULL;
device.active_dlt = -1;
device.pmode = FALSE;
#ifdef HAVE_PCAP_CREATE
device.monitor_mode_enabled = FALSE;
device.monitor_mode_supported = FALSE;
#endif
device.has_snaplen = FALSE;
device.snaplen = 65535;
device.cfilter = NULL;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
device.buffer = DEFAULT_CAPTURE_BUFFER_SIZE;
#endif
#ifdef HAVE_EXTCAP
device.external_cap_args_settings = NULL;
#endif
model = gtk_tree_view_get_model(view);
gtk_tree_model_get_iter (model, &iter, path);
if (window == get_welcome_window()) {
gtk_tree_model_get(model, &iter, IFACE_NAME, &name, -1);
} else if (window == cap_open_w) {
gtk_tree_model_get(model, &iter, IFACE_HIDDEN_NAME, &name, -1);
} else {
return;
}
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(device.name, name) == 0) {
marked_interface = i;
break;
}
}
marked_row = atoi(gtk_tree_path_to_string(path));
opt_edit_w = dlg_window_new("Edit Interface Settings");
gtk_window_set_modal(GTK_WINDOW(opt_edit_w), TRUE);
gtk_window_set_type_hint (GTK_WINDOW (opt_edit_w), GDK_WINDOW_TYPE_HINT_DIALOG);
g_object_set_data(G_OBJECT(opt_edit_w), E_OPT_EDIT_CALLER_PTR_KEY, caller);
g_object_set_data(G_OBJECT(caller), E_OPT_EDIT_DIALOG_PTR_KEY, opt_edit_w);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(opt_edit_w), main_vb);
capture_fr = gtk_frame_new("Capture");
gtk_box_pack_start(GTK_BOX (main_vb), capture_fr, TRUE, TRUE, 0);
capture_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(capture_vb), 5);
gtk_container_add(GTK_CONTAINER(capture_fr), capture_vb);
if_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(capture_vb), if_hb, FALSE, FALSE, 3);
if_lb = gtk_label_new("Interface: ");
gtk_box_pack_start(GTK_BOX(if_hb), if_lb, FALSE, FALSE, 3);
if_lb_name = gtk_label_new(device.display_name);
gtk_box_pack_start(GTK_BOX(if_hb), if_lb_name, FALSE, FALSE, 3);
if_ip_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_widget_set_tooltip_text(if_ip_hb, "Lists the IP address(es) "
"assigned to the selected interface. ");
if_vb_left = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(if_ip_hb), if_vb_left, FALSE, FALSE, 3);
if_vb_right = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
if_ip_lb = gtk_label_new("IP address:");
gtk_misc_set_alignment(GTK_MISC(if_ip_lb), 0, 0);
gtk_box_pack_start(GTK_BOX(if_vb_left), if_ip_lb, FALSE, FALSE, 0);
if (device.no_addresses > 0) {
gchar *temp_addresses = g_strdup(device.addresses);
gtk_box_pack_start(GTK_BOX(capture_vb), if_ip_hb, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(if_ip_hb), if_vb_right, TRUE, TRUE, 3);
swindow = gtk_scrolled_window_new (NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(swindow), GTK_SHADOW_IN);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(swindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_widget_set_size_request(GTK_WIDGET(swindow),-1, 50);
if_view = gtk_tree_view_new ();
g_object_set(G_OBJECT(if_view), "headers-visible", FALSE, NULL);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes ("",
GTK_CELL_RENDERER(renderer),
"text", 0,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(if_view), column);
store = gtk_list_store_new(1, G_TYPE_STRING);
for (tok = strtok (temp_addresses, "\n"); tok; tok = strtok(NULL, "\n")) {
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, 0, tok, -1);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(if_view), GTK_TREE_MODEL (store));
gtk_container_add (GTK_CONTAINER (swindow), if_view);
gtk_box_pack_start(GTK_BOX(if_vb_right), swindow, TRUE, TRUE, 0);
g_free(temp_addresses);
} else {
gtk_box_pack_start(GTK_BOX(capture_vb), if_ip_hb, FALSE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(if_ip_hb), if_vb_right, FALSE, FALSE, 3);
if_ip_name = gtk_label_new("none");
gtk_misc_set_alignment(GTK_MISC(if_ip_name), 0, 0);
gtk_box_pack_start(GTK_BOX(if_vb_right), if_ip_name, FALSE, FALSE, 0);
}
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_hb), 0);
gtk_box_pack_start(GTK_BOX(capture_vb), main_hb, FALSE, FALSE, 3);
left_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(left_vb), 0);
gtk_box_pack_start(GTK_BOX(main_hb), left_vb, TRUE, TRUE, 0);
#if defined (HAVE_AIRPCAP) || defined (HAVE_PCAP_REMOTE) || defined (HAVE_PCAP_CREATE)
right_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(right_vb), 0);
gtk_box_pack_start(GTK_BOX(main_hb), right_vb, FALSE, FALSE, 3);
#endif
linktype_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(left_vb), linktype_hb, FALSE, FALSE, 0);
linktype_lb = gtk_label_new("Link-layer header type:");
gtk_box_pack_start(GTK_BOX(linktype_hb), linktype_lb, FALSE, FALSE, 3);
linktype_combo_box = ws_combo_box_new_text_and_pointer();
g_object_set_data(G_OBJECT(linktype_combo_box), E_CAP_LT_CBX_LABEL_KEY, linktype_lb);
g_object_set_data(G_OBJECT(linktype_combo_box), E_CAP_IFACE_IP_KEY, if_ip_lb);
gtk_widget_set_tooltip_text(linktype_combo_box, "The selected interface supports multiple link-layer types; select the desired one.");
gtk_box_pack_start (GTK_BOX(linktype_hb), linktype_combo_box, FALSE, FALSE, 0);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_LT_CBX_KEY, linktype_combo_box);
num_link_types = 0;
num_supported_link_types = 0;
first_supported_index = -1;
for (list=device.links; list!=NULL; list=g_list_next(list))
{
temp = (link_row*)(list->data);
if (temp->dlt == -1)
{
ws_combo_box_append_text_and_pointer_full(GTK_COMBO_BOX(linktype_combo_box),
NULL,
temp->name,
GINT_TO_POINTER(-1),
FALSE);
}
else
{
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(linktype_combo_box),
temp->name,
GINT_TO_POINTER(temp->dlt));
if (first_supported_index == -1)
{
first_supported_index = num_link_types;
}
if (temp->dlt == device.active_dlt)
{
ws_combo_box_set_active(GTK_COMBO_BOX(linktype_combo_box), num_link_types);
found = TRUE;
}
num_supported_link_types++;
}
num_link_types++;
}
gtk_widget_set_sensitive(linktype_lb, num_link_types >= 2);
gtk_widget_set_sensitive(linktype_combo_box, num_link_types >= 2);
if (!found && first_supported_index >= 0)
{
ws_combo_box_set_active(GTK_COMBO_BOX(linktype_combo_box),first_supported_index);
}
g_signal_connect(linktype_combo_box, "changed", G_CALLBACK(select_link_type_cb), NULL);
promisc_cb = gtk_check_button_new_with_mnemonic(
"Capture packets in _promiscuous mode");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(promisc_cb),
device.pmode);
gtk_widget_set_tooltip_text(promisc_cb,
"Usually a network adapter will only capture the traffic sent to its own network address. "
"If you want to capture all traffic that the network adapter can \"see\", mark this option. "
"See the FAQ for some more details of capturing packets from a switched network.");
gtk_box_pack_start (GTK_BOX(left_vb), promisc_cb, FALSE, FALSE, 0);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_PROMISC_KEY, promisc_cb);
#ifdef HAVE_PCAP_CREATE
monitor_cb = gtk_check_button_new_with_mnemonic( "Capture packets in monitor mode");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(monitor_cb), device.monitor_mode_enabled);
gtk_widget_set_sensitive(monitor_cb, device.monitor_mode_supported);
g_signal_connect(monitor_cb, "toggled", G_CALLBACK(capture_prep_monitor_changed_cb), NULL);
gtk_widget_set_tooltip_text(monitor_cb,
"Usually a Wi-Fi adapter will, even in promiscuous mode, only capture the traffic on the BSS to which it's associated. "
"If you want to capture all traffic that the Wi-Fi adapter can \"receive\", mark this option. "
"In order to see IEEE 802.11 headers or to see radio information for captured packets, "
"it might be necessary to turn this option on.\n\n"
"Note that, in monitor mode, the adapter might disassociate from the network to which it's associated.");
gtk_box_pack_start (GTK_BOX(left_vb), monitor_cb, FALSE, FALSE, 0);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_MONITOR_KEY, monitor_cb);
#endif
snap_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start (GTK_BOX(left_vb), snap_hb, FALSE, FALSE, 0);
snap_cb = gtk_check_button_new_with_mnemonic("_Limit each packet to");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(snap_cb),
device.has_snaplen);
g_signal_connect(snap_cb, "toggled", G_CALLBACK(adjust_snap_sensitivity), NULL);
gtk_widget_set_tooltip_text(snap_cb,
"Limit the maximum number of bytes to be captured from each packet. This size includes the "
"link-layer header and all subsequent headers. ");
gtk_box_pack_start(GTK_BOX(snap_hb), snap_cb, FALSE, FALSE, 0);
snap_adj = (GtkAdjustment *) gtk_adjustment_new((gfloat) device.snaplen,
MIN_PACKET_SIZE, WTAP_MAX_PACKET_SIZE, 1.0, 10.0, 0.0);
snap_sb = gtk_spin_button_new (snap_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (snap_sb), TRUE);
gtk_widget_set_size_request(snap_sb, 80, -1);
gtk_box_pack_start (GTK_BOX(snap_hb), snap_sb, FALSE, FALSE, 0);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_CB_KEY, snap_cb);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_SNAP_SB_KEY, snap_sb);
snap_lb = gtk_label_new("bytes");
gtk_misc_set_alignment(GTK_MISC(snap_lb), 0, 0.5f);
gtk_box_pack_start(GTK_BOX(snap_hb), snap_lb, FALSE, FALSE, 0);
gtk_widget_set_sensitive(GTK_WIDGET(snap_sb), device.has_snaplen);
filter_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(capture_vb), filter_hb, FALSE, FALSE, 0);
filter_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(capture_filter_construct_cb), NULL);
g_signal_connect(filter_bt, "destroy", G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_widget_set_tooltip_text(filter_bt,
"Select a capture filter to reduce the amount of packets to be captured. "
"See \"Capture Filters\" in the online help for further information how to use it."
);
gtk_box_pack_start(GTK_BOX(filter_hb), filter_bt, FALSE, FALSE, 3);
filter_cm = gtk_combo_box_text_new_with_entry();
g_object_set_data(G_OBJECT(opt_edit_w), E_CFILTER_CM_KEY, filter_cm);
filter_te = gtk_bin_get_child(GTK_BIN(filter_cm));
colorize_filter_te_as_empty(filter_te);
g_signal_connect(filter_te, "changed", G_CALLBACK(capture_filter_check_syntax_cb), NULL);
g_signal_connect(filter_te, "destroy", G_CALLBACK(capture_filter_destroy_cb), NULL);
cfilter_list = recent_get_cfilter_list(name);
for (cf_entry = cfilter_list; cf_entry != NULL; cf_entry = g_list_next(cf_entry)) {
new_cfilter = (const gchar *)cf_entry->data;
if ((device.cfilter == NULL || strcmp(device.cfilter, new_cfilter) != 0) &&
(global_capture_opts.default_options.cfilter == NULL || strcmp(global_capture_opts.default_options.cfilter, new_cfilter) != 0)) {
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(filter_cm), new_cfilter);
}
}
if (global_capture_opts.default_options.cfilter && (strlen(global_capture_opts.default_options.cfilter) > 0)) {
if (device.cfilter == NULL || strcmp(device.cfilter, global_capture_opts.default_options.cfilter) != 0) {
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(filter_cm), global_capture_opts.default_options.cfilter);
}
}
if (device.cfilter && (strlen(device.cfilter) > 0)) {
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(filter_cm), device.cfilter);
gtk_combo_box_set_active(GTK_COMBO_BOX(filter_cm), 0);
}
gtk_widget_set_tooltip_text(filter_cm,
"Enter a capture filter to reduce the amount of packets to be captured. "
"See \"Capture Filters\" in the online help for further information how to use it. "
"Syntax checking can be disabled in Preferences -> Capture -> Syntax check capture filter."
);
gtk_box_pack_start(GTK_BOX(filter_hb), filter_cm, TRUE, TRUE, 3);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_te);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
compile_bt = gtk_button_new_with_label("Compile BPF");
g_signal_connect(compile_bt, "clicked", G_CALLBACK(capture_filter_compile_cb), NULL);
gtk_widget_set_tooltip_text(compile_bt,
"Compile the capture filter expression and show the BPF (Berkeley Packet Filter) code.");
gtk_widget_set_sensitive(compile_bt, (num_supported_link_types >= 1));
gtk_box_pack_start(GTK_BOX(filter_hb), compile_bt, FALSE, FALSE, 3);
#endif
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
buffer_size_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
buffer_size_lb = gtk_label_new("Buffer size:");
gtk_box_pack_start (GTK_BOX(buffer_size_hb), buffer_size_lb, FALSE, FALSE, 0);
buffer_size_adj = (GtkAdjustment *) gtk_adjustment_new((gfloat) device.buffer,
1, 65535, 1.0, 10.0, 0.0);
buffer_size_sb = gtk_spin_button_new (buffer_size_adj, 0, 0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON (buffer_size_sb), (gfloat) device.buffer);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (buffer_size_sb), TRUE);
gtk_widget_set_size_request(buffer_size_sb, 80, -1);
gtk_widget_set_tooltip_text(buffer_size_sb,
"The memory buffer size used while capturing. If you notice packet drops, you can try to increase this size.");
gtk_box_pack_start (GTK_BOX(buffer_size_hb), buffer_size_sb, FALSE, FALSE, 0);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_BUFFER_SIZE_SB_KEY, buffer_size_sb);
buffer_size_lb = gtk_label_new("mebibyte(s)");
gtk_box_pack_start (GTK_BOX(buffer_size_hb), buffer_size_lb, FALSE, FALSE, 3);
gtk_misc_set_alignment(GTK_MISC(buffer_size_lb), 1, 0);
#ifdef HAVE_PCAP_REMOTE
gtk_box_pack_start (GTK_BOX(left_vb), buffer_size_hb, FALSE, FALSE, 0);
#else
gtk_box_pack_start (GTK_BOX(right_vb), buffer_size_hb, FALSE, FALSE, 0);
#endif
#endif
#ifdef HAVE_PCAP_REMOTE
if (strncmp (device.name, "rpcap://", 8) == 0) {
remote_bt = gtk_button_new_with_label("Remote Settings");
gtk_widget_set_tooltip_text(remote_bt, "Various settings for remote capture.");
g_signal_connect(remote_bt, "clicked", G_CALLBACK(options_remote_cb), NULL);
gtk_box_pack_start(GTK_BOX(right_vb), remote_bt, FALSE, FALSE, 0);
gtk_widget_show(remote_bt);
}
#endif
#ifdef HAVE_AIRPCAP
airpcap_if_selected = get_airpcap_if_from_name(airpcap_if_list, device.name);
if (airpcap_if_selected != NULL) {
advanced_bt = gtk_button_new_with_label("Wireless Settings");
g_signal_connect(advanced_bt,"clicked", G_CALLBACK(options_airpcap_advanced_cb), wireless_tb);
gtk_box_pack_start(GTK_BOX(right_vb), advanced_bt, FALSE, FALSE, 0);
gtk_widget_show(advanced_bt);
}
#endif
#ifdef HAVE_EXTCAP
extcap_hash = device.external_cap_args_settings;
extcap_vbox = build_extcap_options(device.name, extcap_hash);
gtk_box_pack_start(GTK_BOX(capture_vb), extcap_vbox, FALSE, FALSE, 5);
gtk_widget_show(extcap_vbox);
g_object_set_data(G_OBJECT(opt_edit_w), E_CAP_EXTCAP_KEY, extcap_vbox);
#endif
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
ok_but = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_but, "clicked", G_CALLBACK(save_options_cb), NULL);
gtk_widget_set_tooltip_text(ok_but,
"Accept interface settings.");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
gtk_widget_set_tooltip_text(cancel_bt,
"Cancel and exit dialog.");
window_set_cancel_button(opt_edit_w, cancel_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
gtk_widget_set_tooltip_text(help_bt,
"Show help about capturing.");
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_CAPTURE_OPTIONS_DIALOG);
dlg_set_activate(filter_te, ok_but);
gtk_widget_grab_focus(filter_te);
g_signal_connect(opt_edit_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(opt_edit_w, "destroy", G_CALLBACK(options_edit_destroy_cb), NULL);
gtk_widget_show_all(opt_edit_w);
window_present(opt_edit_w);
}
static void toggle_callback(GtkCellRendererToggle *cell _U_,
gchar *path_str,
gpointer data _U_)
{
GtkTreeIter iter;
GtkTreeView *if_cb;
GtkTreeModel *model;
GtkTreePath *path = gtk_tree_path_new_from_string (path_str);
gboolean enabled;
GtkWidget *pcap_ng_cb, *filter_cm;
interface_t device;
gchar *name;
gint indx = -1;
guint i;
device.locked = FALSE;
device.cfilter = NULL;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
gtk_tree_model_get_iter (model, &iter, path);
gtk_tree_model_get (model, &iter, CAPTURE, &enabled, IFACE_HIDDEN_NAME, &name, -1);
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(device.name, name) == 0) {
indx = i;
break;
}
}
if (!device.locked) {
if (enabled == FALSE) {
device.selected = TRUE;
global_capture_opts.num_selected++;
} else {
device.selected = FALSE;
global_capture_opts.num_selected--;
}
device.locked = TRUE;
}
if (indx != -1) {
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, indx);
g_array_insert_val(global_capture_opts.all_ifaces, indx, device);
pcap_ng_cb = (GtkWidget *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_PCAP_NG_KEY);
if (global_capture_opts.num_selected >= 2) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(pcap_ng_cb), TRUE);
gtk_widget_set_sensitive(pcap_ng_cb, FALSE);
} else {
gtk_widget_set_sensitive(pcap_ng_cb, TRUE);
}
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
gtk_list_store_set(GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, -1);
if (interfaces_dialog_window_present()) {
update_selected_interface(g_strdup(device.name));
}
if (get_welcome_window() != NULL) {
change_interface_selection(g_strdup(device.name), device.selected);
}
}
if (device.cfilter != NULL) {
g_free(device.cfilter);
device.cfilter = NULL;
update_filter_string(device.name, NULL);
}
device.locked = FALSE;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, indx);
g_array_insert_val(global_capture_opts.all_ifaces, indx, device);
gtk_tree_path_free (path);
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY);
if (strcmp(gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(filter_cm)),"") != 0) {
capture_all_filter_check_syntax_cb(NULL, NULL);
}
update_properties_all();
}
void enable_selected_interface(gchar *name, gboolean selected)
{
GtkTreeIter iter;
GtkTreeView *if_cb;
GtkTreeModel *model;
gchar *name_str;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
gtk_tree_model_get_iter_first(model, &iter);
do {
gtk_tree_model_get(model, &iter, IFACE_HIDDEN_NAME, &name_str, -1);
if (strcmp(name, name_str) == 0) {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, CAPTURE, selected, -1);
break;
}
}
while (gtk_tree_model_iter_next(model, &iter));
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
}
static void capture_all_cb(GtkToggleButton *button, gpointer d _U_)
{
GtkTreeIter iter;
GtkTreeView *if_cb;
GtkTreeModel *model;
GtkWidget *filter_cm, *pcap_ng_cb;
gchar *interface = NULL, *filter_text = NULL;
gboolean enabled = FALSE, capture_set = FALSE, pseudo = FALSE;
guint16 num_temp, i;
interface_t device;
if (gtk_toggle_button_get_active(button))
enabled = TRUE;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
pcap_ng_cb = (GtkWidget *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_PCAP_NG_KEY);
num_temp = global_capture_opts.num_selected++;
filter_cm = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY);
filter_text = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(filter_cm));
if (gtk_tree_model_get_iter_first(model, &iter)) {
do {
gtk_tree_model_get (model, &iter, CAPTURE, &capture_set, IFACE_HIDDEN_NAME, &interface, -1);
if (strcmp(interface, "any") == 0) {
pseudo = TRUE;
}
if (!capture_set && enabled && !pseudo) {
num_temp++;
} else if (capture_set && (!enabled || (enabled && pseudo))) {
num_temp--;
}
if (!pseudo) {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, CAPTURE, enabled, -1);
if (strlen(filter_text) != 0) {
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(device.name, interface) == 0) {
g_array_remove_index(global_capture_opts.all_ifaces, i);
device.cfilter = g_strdup(filter_text);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
update_filter_string(device.name, filter_text);
}
}
}
} else {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, CAPTURE, FALSE, -1);
}
pseudo = FALSE;
} while (gtk_tree_model_iter_next(model, &iter));
}
if (num_temp >= 2) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(pcap_ng_cb), TRUE);
gtk_widget_set_sensitive(pcap_ng_cb, FALSE);
} else if (num_temp <= 1) {
gtk_widget_set_sensitive(pcap_ng_cb, TRUE);
}
if (interfaces_dialog_window_present()) {
select_all_interfaces(enabled);
}
if (get_welcome_window() != NULL) {
change_selection_for_all(enabled);
}
if (global_capture_opts.num_selected != num_temp) {
global_capture_opts.num_selected = num_temp;
}
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
set_sensitivity_for_start_icon();
}
static gboolean get_all_prom_mode(void)
{
interface_options interface_opts;
guint i;
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
if (!interface_opts.promisc_mode) {
return FALSE;
}
}
return TRUE;
}
static void promisc_mode_callback(GtkToggleButton *button, gpointer d _U_)
{
GtkTreeIter iter;
GtkTreeView *if_cb;
GtkTreeModel *model;
gboolean enabled = FALSE;
interface_t device;
interface_options interface_opts;
guint i;
if (gtk_toggle_button_get_active(button))
enabled = TRUE;
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
if (gtk_tree_model_get_iter_first(model, &iter)) {
do {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, PMODE, enabled?"enabled":"disabled", -1);
} while (gtk_tree_model_iter_next(model, &iter));
}
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
device.pmode = (enabled?TRUE:FALSE);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
}
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
global_capture_opts.ifaces = g_array_remove_index(global_capture_opts.ifaces, i);
interface_opts.promisc_mode = (enabled?TRUE:FALSE);
g_array_insert_val(global_capture_opts.ifaces, i, interface_opts);
}
}
static void
show_remote_dialog(GtkWidget *w)
{
g_free(global_remote_opts.remote_host_opts.remote_host);
g_free(global_remote_opts.remote_host_opts.remote_port);
g_free(global_remote_opts.remote_host_opts.auth_username);
g_free(global_remote_opts.remote_host_opts.auth_password);
global_remote_opts.src_type = CAPTURE_IFREMOTE;
global_remote_opts.remote_host_opts.remote_host = g_strdup(global_capture_opts.default_options.remote_host);
global_remote_opts.remote_host_opts.remote_port = g_strdup(global_capture_opts.default_options.remote_port);
global_remote_opts.remote_host_opts.auth_type = global_capture_opts.default_options.auth_type;
global_remote_opts.remote_host_opts.auth_username = g_strdup(global_capture_opts.default_options.auth_username);
global_remote_opts.remote_host_opts.auth_password = g_strdup(global_capture_opts.default_options.auth_password);
global_remote_opts.remote_host_opts.datatx_udp = global_capture_opts.default_options.datatx_udp;
global_remote_opts.remote_host_opts.nocap_rpcap = global_capture_opts.default_options.nocap_rpcap;
global_remote_opts.remote_host_opts.nocap_local = global_capture_opts.default_options.nocap_local;
#ifdef HAVE_PCAP_SETSAMPLING
global_remote_opts.sampling_method = global_capture_opts.default_options.sampling_method;
global_remote_opts.sampling_param = global_capture_opts.default_options.sampling_param;
#endif
capture_remote_cb(GTK_WIDGET(w), FALSE);
}
static void change_pipe_name_cb(gpointer dialog _U_, gint btn, gpointer data)
{
guint i;
interface_t device;
gchar *temp, *optname, *snaplen_string;
GtkTreeView *if_cb;
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *pipe_te;
switch(btn) {
case(ESD_BTN_OK):
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp((gchar *)data, device.name) == 0) {
simple_dialog(ESD_TYPE_INFO, ESD_BTN_OK,
"%sA pipe with this name already exists.%s",
simple_dialog_primary_start(), simple_dialog_primary_end());
if_cb = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY));
pipe_te = (GtkWidget *) g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
model = gtk_tree_view_get_model(if_cb);
if (gtk_tree_model_get_iter_first (model, &iter)) {
do {
gtk_tree_model_get(model, &iter, 0, &optname, -1);
if (strcmp(optname, (gchar *) data) == 0) {
gtk_list_store_set (GTK_LIST_STORE(model), &iter, 0, pipe_name, -1);
gtk_entry_set_text(GTK_ENTRY(pipe_te), pipe_name);
break;
}
} while (gtk_tree_model_iter_next(model, &iter));
g_free(optname);
}
return;
}
}
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(pipe_name, device.name) == 0) {
device.name = g_strdup((gchar *)data);
device.display_name = g_strdup_printf("%s", device.name);
g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
temp = g_strdup_printf("<b>%s</b>", device.display_name);
snaplen_string = g_strdup_printf("%d", device.snaplen);
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
model = gtk_tree_view_get_model(if_cb);
if (gtk_tree_model_get_iter_first (model, &iter)) {
do {
gtk_tree_model_get(model, &iter, IFACE_HIDDEN_NAME, &optname, -1);
if (strcmp(optname, pipe_name) == 0) {
#if defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, MONITOR, device.monitor_mode_supported?(device.monitor_mode_enabled?"enabled":"disabled"):"n/a", FILTER, device.cfilter, -1);
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, FILTER, device.cfilter, -1);
#else
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, FILTER, device.cfilter, -1);
#endif
#if 0
oldname = g_strdup(pipe_name);
#endif
pipe_name = g_strdup(device.name);
break;
}
} while (gtk_tree_model_iter_next(model, &iter));
g_free(optname);
}
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
refresh_non_local_interface_lists();
break;
}
}
break;
case(ESD_BTN_CANCEL): {
if_cb = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY));
pipe_te = (GtkWidget *) g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
model = gtk_tree_view_get_model(if_cb);
if (gtk_tree_model_get_iter_first (model, &iter)) {
do {
gtk_tree_model_get(model, &iter, 0, &optname, -1);
if (strcmp(optname, (gchar *) data) == 0) {
gtk_list_store_set (GTK_LIST_STORE(model), &iter, 0, pipe_name, -1);
gtk_entry_set_text(GTK_ENTRY(pipe_te), pipe_name);
break;
}
} while (gtk_tree_model_iter_next(model, &iter));
g_free(optname);
}
break;
}
default:
g_assert_not_reached();
}
}
static void
add_pipe_cb(gpointer w _U_)
{
interface_t device;
gint indx;
GtkTreeView *if_cb;
GtkTreeModel *model;
GtkTreeIter iter;
gchar *temp, *path_str, *snaplen_string;
GtkWidget *pipe_te;
const gchar *g_save_file;
gchar *name;
guint i;
gpointer dialog;
if (!pipe_name)
return;
pipe_te = (GtkWidget *) g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
g_save_file = gtk_entry_get_text(GTK_ENTRY(pipe_te));
name = g_strdup(g_save_file);
if (strcmp(name, "New pipe") == 0 || strcmp(name, "") == 0) {
g_free(name);
return;
}
if (strcmp(pipe_name, "New pipe") != 0) {
if (strcmp(pipe_name, name) != 0) {
dialog = simple_dialog(ESD_TYPE_CONFIRMATION, ESD_BTNS_OK_CANCEL,
"%sDo you want to change %s to %s?%s",
simple_dialog_primary_start(), pipe_name, name, simple_dialog_primary_end());
simple_dialog_set_cb(dialog, change_pipe_name_cb, name);
}
} else {
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(name, device.name) == 0) {
g_free(name);
return;
}
}
pipe_name = g_strdup(g_save_file);
device.name = g_strdup(g_save_file);
device.display_name = g_strdup_printf("%s", device.name);
device.hidden = FALSE;
device.selected = TRUE;
device.type = IF_PIPE;
device.pmode = global_capture_opts.default_options.promisc_mode;
device.has_snaplen = global_capture_opts.default_options.has_snaplen;
device.snaplen = global_capture_opts.default_options.snaplen;
device.cfilter = g_strdup(global_capture_opts.default_options.cfilter);
device.addresses = NULL;
device.no_addresses = 0;
device.last_packets = 0;
device.links = NULL;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
device.buffer = DEFAULT_CAPTURE_BUFFER_SIZE;
#endif
device.active_dlt = -1;
device.locked = FALSE;
device.if_info.name = g_strdup(g_save_file);
device.if_info.friendly_name = NULL;
device.if_info.vendor_description = NULL;
device.if_info.addrs = NULL;
device.if_info.loopback = FALSE;
device.if_info.type = IF_PIPE;
#if defined(HAVE_PCAP_CREATE)
device.monitor_mode_enabled = FALSE;
device.monitor_mode_supported = FALSE;
#endif
global_capture_opts.num_selected++;
indx = global_capture_opts.all_ifaces->len;
temp = g_strdup_printf("<b>%s</b>", device.display_name);
snaplen_string = g_strdup_printf("%d", device.snaplen);
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
path_str = g_strdup_printf("%d", indx);
model = gtk_tree_view_get_model(if_cb);
gtk_tree_model_get_iter_from_string(model, &iter, path_str);
g_array_append_val(global_capture_opts.all_ifaces, device);
gtk_list_store_append (GTK_LIST_STORE(model), &iter);
#if defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, MONITOR, device.monitor_mode_supported?(device.monitor_mode_enabled?"enabled":"disabled"):"n/a", FILTER, device.cfilter, -1);
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, FILTER, device.cfilter, -1);
#else
gtk_list_store_set (GTK_LIST_STORE(model), &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp,LINK, "", PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, FILTER, device.cfilter, -1);
#endif
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, TRUE);
#endif
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
gtk_widget_set_sensitive(all_compile_bt, FALSE);
#endif
}
refresh_non_local_interface_lists();
g_free(name);
}
}
static void
pipe_new_bt_clicked_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
GtkTreeView *pipe_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY));
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(pipe_l));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, "New pipe", -1);
pipe_name = "New pipe";
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(pipe_l), &iter);
gtk_editable_select_region(GTK_EDITABLE(name_te), 0, -1);
gtk_widget_grab_focus(name_te);
}
static void
pipe_del_bt_clicked_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *pipe_l = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY);
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
GtkTreeSelection *sel;
GtkTreeModel *model, *optmodel;
GtkTreeIter iter, optiter;
GtkTreeView *if_cb;
gchar *name, *optname = NULL;
guint i;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(pipe_l));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 0, &name, -1);
if (name != NULL && atoi(gtk_tree_model_get_string_from_iter(model, &iter)) < (gint)global_capture_opts.all_ifaces->len) {
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
if (strcmp(g_array_index(global_capture_opts.all_ifaces, interface_t, i).name, name) == 0) {
g_array_remove_index(global_capture_opts.all_ifaces, i);
break;
}
}
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
gtk_entry_set_text(GTK_ENTRY(name_te), "");
if_cb = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
optmodel = gtk_tree_view_get_model(if_cb);
if (gtk_tree_model_get_iter_first (optmodel, &optiter)) {
do {
gtk_tree_model_get(optmodel, &optiter, IFACE_HIDDEN_NAME, &optname, -1);
if (optname != NULL && strcmp(optname, name) == 0) {
gtk_list_store_remove(GTK_LIST_STORE(gtk_tree_view_get_model(if_cb)), &optiter);
break;
}
} while (gtk_tree_model_iter_next(optmodel, &optiter));
g_free(optname);
}
}
g_free(name);
}
if (gtk_tree_model_get_iter_first (model, &iter)) {
gtk_tree_selection_select_iter(sel, &iter);
} else {
gtk_widget_set_sensitive(name_te, FALSE);
}
refresh_non_local_interface_lists();
}
static void
pipe_name_te_changed_cb(GtkWidget *w _U_, gpointer data _U_)
{
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
GtkWidget *pipe_l = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY);
const gchar *name;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(pipe_l));
name = gtk_entry_get_text(GTK_ENTRY(name_te));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, 0, name, -1);
}
}
static void
fill_pipe_list(void)
{
guint i;
interface_t device;
GtkTreeIter iter;
GtkTreeView *pipe_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY));
GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(pipe_l));
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.type == IF_PIPE) {
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, 0, device.name, -1);
} else {
continue;
}
}
}
static void
pipe_sel_list_cb(GtkTreeSelection *sel, gpointer data _U_)
{
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *name_te = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY);
GtkWidget *del_bt = (GtkWidget *)g_object_get_data(G_OBJECT(interface_management_w), E_CAP_PIPE_DEL_KEY);
gchar *name = NULL;
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, 0, &name, -1);
if (name) {
if (name_te != NULL) {
gtk_entry_set_text(GTK_ENTRY(name_te), name ? name : "");
gtk_widget_set_sensitive(name_te, TRUE);
selected_name = gtk_entry_get_text(GTK_ENTRY(name_te));
pipe_name = g_strdup(selected_name);
}
if (del_bt != NULL) {
gtk_widget_set_sensitive(del_bt, TRUE);
}
g_free(name);
}
}
}
static void
cancel_pipe_cb (gpointer w _U_)
{
#ifdef HAVE_PCAP_REMOTE
GtkWidget *remote_w;
if (interface_management_w && G_IS_OBJECT(interface_management_w)) {
remote_w = g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_DIALOG_PTR_KEY);
}
if (remote_w != NULL && G_IS_OBJECT(remote_w))
window_destroy(remote_w);
#endif
window_destroy(GTK_WIDGET(interface_management_w));
pipe_name = NULL;
}
static void
fill_local_list(void)
{
guint i;
interface_t device;
GtkTreeIter iter;
GtkListStore *store;
GtkTreeView *local_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_LOCAL_L_KEY));
#ifdef _WIN32
store = gtk_list_store_new (3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_BOOLEAN);
#else
store = gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_BOOLEAN);
#endif
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.local && device.type != IF_PIPE && device.type != IF_STDIN) {
gtk_list_store_append(store, &iter);
#ifdef _WIN32
gtk_list_store_set(store, &iter, 0, device.friendly_name, 1, device.name, 2, device.hidden, -1);
#else
gtk_list_store_set(store, &iter, 0, device.name, 1, device.hidden, -1);
#endif
} else {
continue;
}
}
gtk_tree_view_set_model(GTK_TREE_VIEW(local_l), GTK_TREE_MODEL(store));
}
static void local_hide_cb(GtkCellRendererToggle *cell _U_,
gchar *path_str,
gpointer data _U_)
{
gboolean hide, hide_enabled = TRUE;
gchar *name;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreePath *path = gtk_tree_path_new_from_string (path_str);
GtkTreeView *local_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_LOCAL_L_KEY));
model = gtk_tree_view_get_model(local_l);
gtk_tree_model_get_iter (model, &iter, path);
gtk_tree_model_get (model, &iter, 0+LOCAL_OFFSET, &name, 1+LOCAL_OFFSET, &hide, -1);
if ((prefs.capture_device != NULL) && (*prefs.capture_device != '\0')) {
guint i;
interface_t device;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if ((strcmp(device.display_name, prefs.capture_device) == 0) &&
(strcmp(device.name, name) == 0)) {
hide_enabled = FALSE;
break;
}
}
}
if (hide_enabled) {
if (hide) {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, 1+LOCAL_OFFSET, FALSE, -1);
} else {
gtk_list_store_set(GTK_LIST_STORE(model), &iter, 1+LOCAL_OFFSET, TRUE, -1);
}
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Default interface cannot be hidden");
}
}
static void
apply_local_cb(GtkWidget *win _U_, gpointer *data _U_)
{
GtkTreeIter iter;
GtkTreeModel *model;
gchar *name, *new_hide;
gboolean hide;
gint first_if = TRUE;
GtkTreeView *local_l;
if (global_capture_opts.all_ifaces->len > 0) {
local_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_LOCAL_L_KEY));
model = gtk_tree_view_get_model(local_l);
new_hide = (gchar*)g_malloc0(MAX_VAL_LEN);
if (gtk_tree_model_get_iter_first (model, &iter)) {
do {
gtk_tree_model_get(model, &iter, 0+LOCAL_OFFSET, &name, 1+LOCAL_OFFSET, &hide, -1);
if (!hide) {
continue;
} else {
if (first_if != TRUE) {
g_strlcat (new_hide, ",", MAX_VAL_LEN);
}
g_strlcat (new_hide, name, MAX_VAL_LEN);
first_if = FALSE;
}
} while (gtk_tree_model_iter_next(model, &iter));
g_free(name);
}
g_free(prefs.capture_devices_hide);
prefs.capture_devices_hide = new_hide;
hide_interface(g_strdup(new_hide));
refresh_local_interface_lists();
if (!prefs.gui_use_pref_save) {
prefs_main_write();
}
}
}
void
capture_dlg_refresh_if (void)
{
GtkTreeView *view;
if (interface_management_w)
fill_local_list();
view = (GtkTreeView *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
create_and_fill_model(GTK_TREE_VIEW(view));
update_properties_all();
}
static void
rescan_local_cb(GtkWidget *button _U_, gpointer *data _U_)
{
refresh_local_interface_lists();
}
static void
fill_remote_list(void)
{
guint i;
interface_t device;
GtkTreeIter iter, child;
gchar *host = "";
GtkTreeView *remote_l;
GtkTreeStore *store;
num_selected = 0;
remote_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_L_KEY));
store = gtk_tree_store_new(4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_BOOLEAN, G_TYPE_STRING);
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.local) {
continue;
} else {
if (strcmp(host, device.remote_opts.remote_host_opts.remote_host) != 0) {
host = g_strdup(device.remote_opts.remote_host_opts.remote_host);
gtk_tree_store_append(store, &iter, NULL);
gtk_tree_store_set(store, &iter, 0, host, 3, "FALSE", -1);
gtk_tree_store_append(store, &child, &iter);
gtk_tree_store_set(store, &child, 1, device.name, 2, device.hidden, 3, "TRUE", -1);
} else {
gtk_tree_store_append(store, &child, &iter);
gtk_tree_store_set(store, &child, 1, device.name, 2, device.hidden, 3, "TRUE", -1);
}
}
}
gtk_tree_view_set_model(GTK_TREE_VIEW(remote_l), GTK_TREE_MODEL(store));
gtk_tree_view_expand_all(GTK_TREE_VIEW(remote_l));
}
static void
button_hide_cb(GtkTreeViewColumn *column, GtkCellRenderer *renderer,
GtkTreeModel *model, GtkTreeIter *iter, gpointer data _U_)
{
gchar *enabled;
gtk_tree_model_get(model, iter, 3, &enabled, -1);
if (strcmp(enabled, "TRUE") == 0) {
g_object_set(G_OBJECT(renderer), "visible", TRUE, NULL);
} else if (strcmp(enabled, "FALSE") == 0){
g_object_set(G_OBJECT(renderer), "visible", FALSE, NULL);
}
}
static void remote_hide_cb(GtkCellRendererToggle *cell _U_,
gchar *path_str,
gpointer data _U_)
{
gboolean hide;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreePath *path = gtk_tree_path_new_from_string (path_str);
GtkTreeView *remote_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_L_KEY));
model = gtk_tree_view_get_model(remote_l);
gtk_tree_model_get_iter (model, &iter, path);
gtk_tree_model_get (model, &iter, 2, &hide, -1);
if (hide) {
gtk_tree_store_set(GTK_TREE_STORE(model), &iter, 2, FALSE, -1);
} else {
gtk_tree_store_set(GTK_TREE_STORE(model), &iter, 2, TRUE, -1);
}
}
static void
ok_remote_cb(GtkWidget *win _U_, gpointer *data _U_)
{
GtkTreeIter iter, child;
GtkTreeModel *model;
gchar *name, *new_hide;
gboolean hide;
gint first_if = TRUE;
GtkTreeView *remote_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_L_KEY));
model = gtk_tree_view_get_model(remote_l);
new_hide = g_malloc0(MAX_VAL_LEN);
if (gtk_tree_model_get_iter_first (model, &iter)) {
do {
gtk_tree_model_get(model, &iter, 1, &name, 2, &hide, -1);
if (!name && gtk_tree_model_iter_children(model, &child, &iter)) {
do {
gtk_tree_model_get(model, &child, 1, &name, 2, &hide, -1);
if (!hide) {
continue;
} else {
if (first_if != TRUE) {
g_strlcat (new_hide, ",", MAX_VAL_LEN);
}
g_strlcat (new_hide, name, MAX_VAL_LEN);
first_if = FALSE;
}
} while (gtk_tree_model_iter_next(model, &child));
}
} while (gtk_tree_model_iter_next(model, &iter));
g_free(name);
}
hide_interface(g_strdup(new_hide));
refresh_non_local_interface_lists();
}
static gboolean
select_host_cb(GtkTreeSelection *selection _U_,
GtkTreeModel *model,
GtkTreePath *path,
gboolean path_currently_selected _U_,
gpointer data _U_)
{
GtkTreeIter iter;
gtk_tree_model_get_iter (model, &iter, path);
if (gtk_tree_model_iter_has_child(model, &iter)) {
num_selected++;
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(interface_management_w), E_REMOTE_DEL_BT_KEY), TRUE);
return TRUE;
} else {
return FALSE;
}
}
static void
remove_remote_host(GtkWidget *w _U_, gpointer data _U_)
{
GtkTreeIter iter, child;
GtkTreeModel *model;
gchar *host;
gint num_children, i;
interface_t device;
GtkTreeView *remote_l = GTK_TREE_VIEW(g_object_get_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_L_KEY));
GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(remote_l));
model = gtk_tree_view_get_model(remote_l);
if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
gtk_tree_model_get(model, &iter, 0, &host, -1);
if ((num_children = gtk_tree_model_iter_n_children(model, &iter)) > 0) {
for (i = num_children-1; i >= 0; i--) {
if (gtk_tree_model_iter_nth_child(model, &child, &iter, i)) {
gtk_tree_store_remove(GTK_TREE_STORE(model), &child);
}
}
}
gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
if (--num_selected == 0) {
gtk_widget_set_sensitive(g_object_get_data(G_OBJECT(interface_management_w), E_REMOTE_DEL_BT_KEY), FALSE);
}
for (i = global_capture_opts.all_ifaces->len-1; i >= 0; i--) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (device.local) {
continue;
} else {
if (strcmp(host, device.remote_opts.remote_host_opts.remote_host) == 0) {
g_array_remove_index(global_capture_opts.all_ifaces, i);
}
}
}
refresh_non_local_interface_lists();
}
}
static void
show_add_interfaces_dialog(GtkWidget *bt _U_, GtkWidget *parent_win)
{
GtkWidget *vbox, *top_hb;
GtkWidget *hbox, *bbox, *list_bb, *edit_fr, *pipe_fr, *pipe_sc, *pipe_l, *props_fr, *props_vb;
GtkWidget *main_nb;
GtkWidget *temp_page, *tmp;
GtkWidget *pipe_hb, *pipe_bt, *pipe_lb, *pipe_te, *pipe_vb;
GtkWidget *add_bt, *cancel_bt, *new_bt, *del_bt, *middle_hb;
GtkWidget *local_fr, *local_l, *local_sc, *local_vb;
GtkWidget *apply_bt, *refresh_bt;
GtkCellRenderer *renderer, *toggle_renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
GtkListStore *store;
#if defined(HAVE_PCAP_REMOTE)
GtkWidget *remote_fr, *remote_l, *remote_sc, *remote_vb;
GtkWidget *delete_bt, *add_but, *ok_but;
GtkWidget *button_hbox, *help_hbox;
GtkTreeSelection *selection;
#endif
if (interface_management_w != NULL && G_IS_OBJECT(interface_management_w)) {
reactivate_window(interface_management_w);
return;
}
interface_management_w = window_new(GTK_WINDOW_TOPLEVEL, "Interface Management");
gtk_window_set_transient_for(GTK_WINDOW(interface_management_w), GTK_WINDOW(parent_win));
gtk_window_set_destroy_with_parent(GTK_WINDOW(interface_management_w), TRUE);
gtk_window_set_default_size(GTK_WINDOW(interface_management_w), 700, 300);
vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(interface_management_w), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
main_nb = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(vbox), main_nb, TRUE, TRUE, 0);
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
tmp = gtk_label_new("Pipes");
gtk_widget_show(tmp);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (hbox), tmp, TRUE, TRUE, 0);
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, hbox);
pipe_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(pipe_hb), 5);
gtk_box_pack_start(GTK_BOX(temp_page), pipe_hb, TRUE, TRUE, 0);
pipe_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(pipe_vb), 0);
gtk_box_pack_start(GTK_BOX (pipe_hb), pipe_vb, TRUE, TRUE, 0);
gtk_widget_show(pipe_vb);
top_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX (pipe_vb), top_hb, TRUE, TRUE, 0);
gtk_widget_show(top_hb);
edit_fr = gtk_frame_new("");
gtk_box_pack_start(GTK_BOX(top_hb), edit_fr, FALSE, FALSE, 0);
gtk_widget_show(edit_fr);
list_bb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, TRUE);
gtk_container_set_border_width(GTK_CONTAINER(list_bb), 5);
gtk_container_add(GTK_CONTAINER(edit_fr), list_bb);
gtk_widget_show(list_bb);
new_bt = ws_gtk_button_new_from_stock(GTK_STOCK_NEW);
g_signal_connect(new_bt, "clicked", G_CALLBACK(pipe_new_bt_clicked_cb), NULL);
gtk_widget_show(new_bt);
gtk_box_pack_start (GTK_BOX (list_bb), new_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text (new_bt, "Add a new pipe (with default properties)");
del_bt = ws_gtk_button_new_from_stock(GTK_STOCK_DELETE);
g_signal_connect(del_bt, "clicked", G_CALLBACK(pipe_del_bt_clicked_cb), NULL);
gtk_widget_show(del_bt);
gtk_widget_set_sensitive(del_bt, FALSE);
gtk_box_pack_start (GTK_BOX (list_bb), del_bt, FALSE, FALSE, 0);
gtk_widget_set_tooltip_text (del_bt, "Remove the selected pipe from the list");
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_PIPE_DEL_KEY, del_bt);
pipe_fr = gtk_frame_new("Pipes");
gtk_box_pack_start(GTK_BOX(top_hb), pipe_fr, TRUE, TRUE, 0);
gtk_widget_show(pipe_fr);
pipe_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(pipe_sc),
GTK_SHADOW_IN);
gtk_container_set_border_width (GTK_CONTAINER (pipe_sc), 5);
gtk_container_add(GTK_CONTAINER(pipe_fr), pipe_sc);
gtk_widget_show(pipe_sc);
store = gtk_list_store_new(1, G_TYPE_STRING);
pipe_l = tree_view_new(GTK_TREE_MODEL(store));
gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(pipe_l), FALSE);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("", renderer, "text", 0, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, 0);
gtk_tree_view_append_column(GTK_TREE_VIEW(pipe_l), column);
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(pipe_l));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_PIPE_L_KEY, pipe_l);
g_signal_connect(sel, "changed", G_CALLBACK(pipe_sel_list_cb), pipe_vb);
gtk_container_add(GTK_CONTAINER(pipe_sc), pipe_l);
gtk_widget_show(pipe_l);
fill_pipe_list();
g_object_unref(G_OBJECT(store));
props_fr = gtk_frame_new("");
gtk_box_pack_start(GTK_BOX(pipe_vb), props_fr, FALSE, FALSE, 0);
gtk_widget_show(props_fr);
props_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(props_vb), 5);
gtk_container_add(GTK_CONTAINER(props_fr), props_vb);
gtk_widget_show(props_vb);
middle_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (props_vb), middle_hb, TRUE, TRUE, 0);
gtk_widget_show(middle_hb);
pipe_lb = gtk_label_new("Pipe:");
gtk_box_pack_start(GTK_BOX(middle_hb), pipe_lb, FALSE, FALSE, 3);
pipe_te = gtk_entry_new();
gtk_widget_set_tooltip_text(GTK_WIDGET(pipe_te),
"Enter the name of the pipe data should be captured from. "
);
gtk_box_pack_start(GTK_BOX(middle_hb), pipe_te, TRUE, TRUE, 3);
gtk_widget_set_sensitive(pipe_te, FALSE);
pipe_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_BROWSE);
gtk_widget_set_tooltip_text(GTK_WIDGET(pipe_bt),
"Select a pipe from which data should be captured, "
"instead of entering the pipe name directly. "
);
gtk_box_pack_start(GTK_BOX(middle_hb), pipe_bt, FALSE, FALSE, 0);
g_signal_connect(pipe_te, "changed", G_CALLBACK(pipe_name_te_changed_cb), NULL);
g_signal_connect(pipe_bt, "clicked", G_CALLBACK(capture_prep_pipe_cb), pipe_te);
bbox = dlg_button_row_new(GTK_STOCK_SAVE, GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(temp_page), bbox, FALSE, FALSE, 5);
add_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_SAVE);
g_signal_connect(add_bt, "clicked", G_CALLBACK(add_pipe_cb), interface_management_w);
gtk_widget_set_tooltip_text(GTK_WIDGET(add_bt), "Add pipe to the list of interfaces.");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
g_signal_connect(GTK_WIDGET(cancel_bt), "clicked", G_CALLBACK(cancel_pipe_cb), interface_management_w);
gtk_widget_set_tooltip_text(GTK_WIDGET(cancel_bt), "Cancel and exit dialog.");
gtk_widget_show(bbox);
gtk_widget_show(temp_page);
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_PIPE_TE_KEY, pipe_te);
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
tmp = gtk_label_new("Local Interfaces");
gtk_widget_show(tmp);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(hbox), tmp, TRUE, TRUE, 0);
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, hbox);
local_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(local_vb), 0);
gtk_box_pack_start(GTK_BOX(temp_page), local_vb, TRUE, TRUE, 0);
gtk_widget_show(local_vb);
local_fr = gtk_frame_new("Local Interfaces");
gtk_box_pack_start(GTK_BOX(local_vb), local_fr, TRUE, TRUE, 0);
gtk_widget_show(local_fr);
local_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(local_sc),
GTK_SHADOW_IN);
gtk_container_set_border_width (GTK_CONTAINER (local_sc), 5);
gtk_container_add(GTK_CONTAINER(local_fr), local_sc);
gtk_widget_show(local_sc);
local_l = gtk_tree_view_new();
#ifdef _WIN32
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Friendly Name", renderer, "text", 0, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, 0);
gtk_tree_view_append_column(GTK_TREE_VIEW(local_l), column);
#endif
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Interface Name", renderer, "text", 0+LOCAL_OFFSET, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, 0+LOCAL_OFFSET);
gtk_tree_view_append_column(GTK_TREE_VIEW(local_l), column);
toggle_renderer = gtk_cell_renderer_toggle_new();
column = gtk_tree_view_column_new_with_attributes("Hide", GTK_CELL_RENDERER(toggle_renderer), "active", 1+LOCAL_OFFSET, NULL);
g_signal_connect (G_OBJECT(toggle_renderer), "toggled", G_CALLBACK (local_hide_cb), NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(local_l), column);
gtk_cell_renderer_toggle_set_active(GTK_CELL_RENDERER_TOGGLE(toggle_renderer), TRUE);
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_LOCAL_L_KEY, local_l);
gtk_container_add(GTK_CONTAINER(local_sc), local_l);
gtk_widget_show(local_l);
fill_local_list();
bbox = dlg_button_row_new(GTK_STOCK_REFRESH, GTK_STOCK_APPLY, GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(temp_page), bbox, FALSE, FALSE, 5);
refresh_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_REFRESH);
g_signal_connect(refresh_bt, "clicked", G_CALLBACK(rescan_local_cb), NULL);
gtk_widget_set_tooltip_text(GTK_WIDGET(refresh_bt), "Rescan the local interfaces and refresh the list");
cancel_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
g_signal_connect(GTK_WIDGET(cancel_bt), "clicked", G_CALLBACK(cancel_pipe_cb), interface_management_w);
gtk_widget_set_tooltip_text(GTK_WIDGET(cancel_bt), "Cancel and exit dialog.");
apply_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_APPLY);
g_signal_connect(GTK_WIDGET(apply_bt), "clicked", G_CALLBACK(apply_local_cb), NULL);
gtk_widget_set_tooltip_text(GTK_WIDGET(apply_bt), "Apply the changes to the general list of local interfaces");
gtk_widget_show(bbox);
gtk_widget_show(temp_page);
#if defined (HAVE_PCAP_REMOTE)
temp_page = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
tmp = gtk_label_new("Remote Interfaces");
gtk_widget_show(tmp);
hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX (hbox), tmp, TRUE, TRUE, 0);
gtk_notebook_append_page(GTK_NOTEBOOK(main_nb), temp_page, hbox);
remote_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(remote_vb), 0);
gtk_box_pack_start(GTK_BOX(temp_page), remote_vb, TRUE, TRUE, 0);
gtk_widget_show(remote_vb);
remote_fr = gtk_frame_new("Remote Interfaces");
gtk_box_pack_start(GTK_BOX(remote_vb), remote_fr, TRUE, TRUE, 0);
gtk_widget_show(remote_fr);
remote_sc = scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(remote_sc),
GTK_SHADOW_IN);
gtk_container_set_border_width (GTK_CONTAINER (remote_sc), 5);
gtk_container_add(GTK_CONTAINER(remote_fr), remote_sc);
gtk_widget_show(remote_sc);
remote_l = gtk_tree_view_new();
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Host", renderer, "text", 0, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, 0);
gtk_tree_view_append_column(GTK_TREE_VIEW(remote_l), column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", 1, NULL);
gtk_tree_view_column_set_expand(column, TRUE);
gtk_tree_view_column_set_sort_column_id(column, 1);
gtk_tree_view_append_column(GTK_TREE_VIEW(remote_l), column);
toggle_renderer = gtk_cell_renderer_toggle_new();
column = gtk_tree_view_column_new_with_attributes("Hide", GTK_CELL_RENDERER(toggle_renderer), "active", 2, NULL);
g_signal_connect (G_OBJECT(toggle_renderer), "toggled", G_CALLBACK (remote_hide_cb), NULL);
gtk_tree_view_column_set_cell_data_func(column, toggle_renderer, button_hide_cb, NULL, FALSE);
gtk_tree_view_append_column(GTK_TREE_VIEW(remote_l), column);
gtk_cell_renderer_toggle_set_active(GTK_CELL_RENDERER_TOGGLE(toggle_renderer), TRUE);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Control", renderer, "text", 3, NULL);
gtk_tree_view_column_set_visible(column, FALSE);
gtk_tree_view_append_column(GTK_TREE_VIEW(remote_l), column);
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(remote_l));
gtk_tree_selection_set_select_function(selection, select_host_cb, NULL, FALSE);
g_object_set_data(G_OBJECT(interface_management_w), E_CAP_REMOTE_L_KEY, remote_l);
gtk_container_add(GTK_CONTAINER(remote_sc), remote_l);
gtk_widget_show(remote_l);
fill_remote_list();
bbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(temp_page), bbox, FALSE, FALSE, 5);
gtk_widget_show(bbox);
button_hbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_end(GTK_BOX(bbox), button_hbox, FALSE, FALSE, 0);
gtk_widget_show(button_hbox);
gtk_box_set_spacing(GTK_BOX(button_hbox), DLG_BUTTON_SPACING);
help_hbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
gtk_box_pack_start(GTK_BOX(bbox), help_hbox, FALSE, FALSE, 0);
gtk_widget_show(help_hbox);
gtk_box_set_spacing(GTK_BOX(help_hbox), DLG_BUTTON_SPACING);
add_but = ws_gtk_button_new_from_stock(GTK_STOCK_ADD);
g_object_set_data(G_OBJECT(bbox), GTK_STOCK_ADD, add_but);
gtk_box_pack_start(GTK_BOX(help_hbox), add_but, FALSE, FALSE, 0);
g_signal_connect(add_but, "clicked", G_CALLBACK(show_remote_dialog), NULL);
gtk_widget_set_tooltip_text(GTK_WIDGET(add_but), "Add a remote host to the list");
gtk_widget_show(add_but);
delete_bt = ws_gtk_button_new_from_stock(GTK_STOCK_DELETE);
g_object_set_data(G_OBJECT(bbox), GTK_STOCK_DELETE, delete_bt);
gtk_box_pack_start(GTK_BOX(help_hbox), delete_bt, FALSE, FALSE, 0);
g_signal_connect(delete_bt, "clicked", G_CALLBACK(remove_remote_host), NULL);
gtk_widget_set_tooltip_text(GTK_WIDGET(delete_bt), "Remove a remote host from the list");
gtk_widget_set_sensitive(GTK_WIDGET(delete_bt), FALSE);
g_object_set_data(G_OBJECT(interface_management_w), E_REMOTE_DEL_BT_KEY, delete_bt);
gtk_widget_show(delete_bt);
ok_but = ws_gtk_button_new_from_stock(GTK_STOCK_APPLY);
gtk_box_pack_end(GTK_BOX(button_hbox), ok_but, FALSE, FALSE, 0);
g_signal_connect(GTK_WIDGET(ok_but), "clicked", G_CALLBACK(ok_remote_cb), NULL);
gtk_widget_set_tooltip_text(GTK_WIDGET(ok_but), "Apply the changes to the general list of local interfaces");
gtk_widget_show(ok_but);
cancel_bt = ws_gtk_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_box_pack_end(GTK_BOX(button_hbox), cancel_bt, FALSE, FALSE, 0);
g_signal_connect(GTK_WIDGET(cancel_bt), "clicked", G_CALLBACK(cancel_pipe_cb), interface_management_w);
gtk_widget_set_tooltip_text(GTK_WIDGET(cancel_bt), "Cancel and exit dialog.");
gtk_widget_show(cancel_bt);
gtk_widget_show(temp_page);
#endif
gtk_widget_show_all(interface_management_w);
}
static gboolean
columns_menu_handler(GtkWidget *widget, GdkEvent *event, gpointer data)
{
GtkWidget *menu = (GtkWidget *)data;
GdkEventButton *event_button = NULL;
if (event->type == GDK_BUTTON_PRESS) {
event_button = (GdkEventButton *) event;
if (event_button->button == 3) {
gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, widget,
event_button->button,
event_button->time);
g_signal_stop_emission_by_name(widget, "button_press_event");
return TRUE;
}
}
return FALSE;
}
static void
update_properties_all(void)
{
unsigned int i;
interface_t device;
gboolean capture_all;
gboolean promisc_all;
gboolean filter_all;
gchar * filter_str;
GtkWidget *promisc_b;
GtkWidget *capture_b;
GtkWidget *all_filter_te;
if (!cap_open_w)
return;
capture_all = TRUE;
promisc_all = TRUE;
filter_all = TRUE;
filter_str = NULL;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.hidden) {
if (!device.selected) {
capture_all = FALSE;
} else {
if (!device.pmode) {
promisc_all = FALSE;
}
if (device.cfilter != NULL && filter_all) {
if (filter_str == NULL) {
filter_str = g_strdup(device.cfilter);
} else {
if (strcmp(device.cfilter, filter_str) != 0) {
if (filter_str != NULL) {
g_free(filter_str);
}
filter_str = NULL;
filter_all = FALSE;
}
}
}
}
}
}
capture_b = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_KEY_ALL);
g_signal_handler_block(capture_b, capture_all_handler_id);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(capture_b), capture_all);
g_signal_handler_unblock(capture_b, capture_all_handler_id);
promisc_b = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_PROMISC_KEY_ALL);
g_signal_handler_block(promisc_b, promisc_all_handler_id);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(promisc_b), promisc_all);
g_signal_handler_unblock(promisc_b, promisc_all_handler_id);
all_filter_te = gtk_bin_get_child(GTK_BIN(g_object_get_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY)));
if (filter_all) {
if (filter_str != NULL) {
gtk_entry_set_text(GTK_ENTRY(all_filter_te), filter_str);
g_free(filter_str);
} else {
gtk_entry_set_text(GTK_ENTRY(all_filter_te), "");
}
} else {
gtk_entry_set_text(GTK_ENTRY(all_filter_te), "");
}
}
static gboolean
column_button_pressed_cb (GtkWidget *widget, GdkEvent *event, gpointer data)
{
GtkWidget *col = (GtkWidget *) data;
GtkTreeView *view;
GtkWidget *menu = (GtkWidget *)g_object_get_data(G_OBJECT(columns_menu_object), PM_COLUMNS_KEY);
view = (GtkTreeView *)g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY);
g_object_set_data(G_OBJECT(view), E_MCAPTURE_COLUMNS_COLUMN_KEY, col);
return columns_menu_handler (widget, event, menu);
}
void
capture_prep_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb,
*main_hb, *left_vb, *right_vb,
*capture_fr, *capture_vb,
*all_hb, *all_cb,
*promisc_cb, *pcap_ng_cb,
*file_fr, *file_vb,
*file_hb, *file_bt, *file_lb, *file_te,
*multi_hb, *multi_grid, *multi_files_on_cb,
*ring_filesize_cb, *ring_filesize_sb, *ring_filesize_cbx,
*file_duration_cb, *file_duration_sb, *file_duration_cbx,
*ringbuffer_nbf_cb, *ringbuffer_nbf_sb, *ringbuffer_nbf_lb,
*stop_files_cb, *stop_files_sb, *stop_files_lb,
*limit_fr, *limit_vb, *limit_hb, *limit_grid,
*stop_packets_cb, *stop_packets_sb, *stop_packets_lb,
*stop_filesize_cb, *stop_filesize_sb, *stop_filesize_cbx,
*stop_duration_cb, *stop_duration_sb, *stop_duration_cbx,
*display_fr, *display_vb,
*sync_cb, *auto_scroll_cb, *hide_info_cb,
*resolv_fr, *resolv_vb,
*m_resolv_cb, *n_resolv_cb, *t_resolv_cb, *e_resolv_cb,
*bbox, *close_bt,
*all_filter_cm, *all_filter_te, *all_filter_bt, *all_filter_hb,
*all_vb,
*help_bt;
#ifdef HAVE_AIRPCAP
GtkWidget *decryption_cb;
int err;
gchar *err_str;
#endif
GtkWidget *iftype_cbx;
GtkAdjustment *ringbuffer_nbf_adj,
*stop_packets_adj, *stop_filesize_adj, *stop_duration_adj, *stop_files_adj,
*ring_filesize_adj, *file_duration_adj;
int row;
guint32 value;
gchar *cap_title;
GtkWidget *view;
GtkWidget *swindow;
GtkCellRenderer *renderer;
GtkCellRenderer *toggle_renderer;
GtkTreeSelection *selection;
GtkTreeViewColumn *column;
gboolean if_present = TRUE;
GList *all_cfilter_list, *cf_entry;
window_geometry_t tl_geom;
const gchar *new_cfilter;
if (interfaces_dialog_window_present()) {
destroy_if_window();
}
if (cap_open_w != NULL && G_IS_OBJECT(cap_open_w)) {
reactivate_window(cap_open_w);
return;
}
init_columns_menu();
cap_title = create_user_window_title("Wireshark: Capture Options");
cap_open_complete = FALSE;
cap_open_w = dlg_window_new(cap_title);
g_free(cap_title);
#ifdef HAVE_AIRPCAP
airpcap_if_list = get_airpcap_interface_list(&err, &err_str);
if (airpcap_if_list == NULL) {
if (err == CANT_GET_AIRPCAP_INTERFACE_LIST) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", err_str);
g_free(err_str);
}
}else{
decryption_cb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY);
update_decryption_mode_list(decryption_cb);
airpcap_if_active = airpcap_get_default_if(airpcap_if_list);
}
#endif
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(cap_open_w), main_vb);
capture_fr = frame_new("Capture");
gtk_box_pack_start(GTK_BOX (main_vb), capture_fr, TRUE, TRUE, 0);
capture_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(capture_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(capture_fr), capture_vb);
swindow = gtk_scrolled_window_new (NULL, NULL);
gtk_widget_set_size_request(swindow, 676, 100);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(swindow), GTK_SHADOW_IN);
view = gtk_tree_view_new ();
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW (view), TRUE);
g_signal_connect(view, "row-activated", G_CALLBACK(options_interface_cb), (gpointer)cap_open_w);
toggle_renderer = gtk_cell_renderer_toggle_new();
column = gtk_tree_view_column_new_with_attributes("Capture", GTK_CELL_RENDERER(toggle_renderer), "active", CAPTURE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
g_signal_connect (G_OBJECT(toggle_renderer), "toggled", G_CALLBACK (toggle_callback), NULL);
g_object_set (GTK_TREE_VIEW(view), "has-tooltip", TRUE, NULL);
g_signal_connect (GTK_TREE_VIEW(view), "query-tooltip", G_CALLBACK (query_tooltip_tree_view_cb), NULL);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes ("",
GTK_CELL_RENDERER(renderer),
"text", IFACE_HIDDEN_NAME,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_visible(column, FALSE);
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW (view), -1, "Interface", renderer, "markup", INTERFACE, NULL);
column = gtk_tree_view_get_column(GTK_TREE_VIEW (view), INTERFACE);
gtk_tree_view_column_set_min_width(column, 200);
gtk_tree_view_column_set_resizable(column, TRUE );
gtk_tree_view_column_set_alignment(column, 0.5f);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(INTERFACE));
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("INTERFACE"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
g_object_set(G_OBJECT(renderer), "ellipsize", PANGO_ELLIPSIZE_END, NULL);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes ("Link-layer header", renderer, "text", LINK, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_clickable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW (view),LINK), TRUE );
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(LINK));
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("LINK"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
gtk_tree_view_column_set_alignment(column, 0.5f);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prom. Mode", renderer, "text", PMODE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
g_object_set(renderer, "xalign", 0.5f, NULL);
gtk_tree_view_column_set_clickable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(PMODE));
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("PMODE"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
gtk_tree_view_column_set_alignment(column, 0.5f);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Snaplen [B]", renderer, "text", SNAPLEN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_clickable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(SNAPLEN));
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("SNAPLEN"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
g_object_set(renderer, "xalign", 0.5f, NULL);
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Buffer [MiB]", renderer, "text", BUFFER, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_reorderable(column, TRUE);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(BUFFER));
gtk_tree_view_column_set_clickable(column, TRUE);
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("BUFFER"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
g_object_set(renderer, "xalign", 0.5f, NULL);
#endif
#if defined (HAVE_PCAP_CREATE)
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes ("Mon. Mode", renderer, "text", MONITOR, NULL);
gtk_tree_view_column_set_cell_data_func(column, renderer, activate_monitor, NULL, FALSE);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_reorderable(column, TRUE);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(MONITOR));
gtk_tree_view_column_set_clickable(column, TRUE);
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("MONITOR"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
g_object_set(renderer, "xalign", 0.5f, NULL);
#endif
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Capture Filter", renderer, "text", FILTER, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
gtk_tree_view_column_set_alignment(column, 0.5f);
create_and_fill_model(GTK_TREE_VIEW(view));
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
gtk_tree_view_column_set_clickable(column, TRUE);
gtk_tree_view_column_set_reorderable(column, TRUE);
g_object_set_data(G_OBJECT(column), E_MCAPTURE_COLUMNS_COL_KEY, GINT_TO_POINTER(FILTER));
g_signal_connect(gtk_tree_view_column_get_button(column), "button_press_event",
G_CALLBACK(column_button_pressed_cb), column);
if (!prefs.capture_columns || prefs_capture_options_dialog_column_is_visible("FILTER"))
gtk_tree_view_column_set_visible(column, TRUE);
else
gtk_tree_view_column_set_visible(column, FALSE);
gtk_container_add (GTK_CONTAINER (swindow), view);
gtk_box_pack_start(GTK_BOX(capture_vb), swindow, TRUE, TRUE, 0);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_IFACE_KEY, view);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_hb), 0);
gtk_box_pack_start(GTK_BOX(capture_vb), main_hb, FALSE, FALSE, 0);
all_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(all_vb), 0);
gtk_box_pack_start(GTK_BOX(main_hb), all_vb, TRUE, TRUE, 0);
all_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(all_hb), 0);
gtk_box_pack_start(GTK_BOX(all_vb), all_hb, TRUE, TRUE, 0);
left_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(left_vb), 0);
gtk_box_pack_start(GTK_BOX(all_hb), left_vb, TRUE, TRUE, 0);
right_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(right_vb), 0);
gtk_box_pack_start(GTK_BOX(all_hb), right_vb, FALSE, FALSE, 3);
all_cb = gtk_check_button_new_with_mnemonic( "Capture on all interfaces");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(all_cb), FALSE);
capture_all_handler_id = g_signal_connect(all_cb, "toggled", G_CALLBACK(capture_all_cb), NULL);
gtk_widget_set_tooltip_text(all_cb, "Activate the box to capture on all interfaces. "
"Deactivate it to capture on none and set the interfaces individually.");
gtk_box_pack_start(GTK_BOX(left_vb), all_cb, TRUE, TRUE, 0);
gtk_widget_set_sensitive(GTK_WIDGET(all_cb), if_present);
promisc_cb = gtk_check_button_new_with_mnemonic("Use _promiscuous mode on all interfaces");
if (!global_capture_session.session_started) {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(promisc_cb), prefs.capture_prom_mode);
} else {
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(promisc_cb), get_all_prom_mode());
}
promisc_all_handler_id = g_signal_connect(promisc_cb, "toggled", G_CALLBACK(promisc_mode_callback), NULL);
gtk_widget_set_tooltip_text(promisc_cb,
"Usually a network adapter will only capture the traffic sent to its own network address. "
"If you want to capture all traffic that all network adapters can \"see\", select this option. "
"If you want to set this option on a per-interface basis, do not select this option. "
"Instead, select the individual checkboxes in the interface list's \"Prom. Mode\" column. "
"See the FAQ for some more details of capturing packets from a switched network.");
gtk_box_pack_start(GTK_BOX(left_vb), promisc_cb, TRUE, TRUE, DLG_LABEL_SPACING);
iftype_cbx = gtk_button_new_with_label("Manage Interfaces");
gtk_widget_set_tooltip_text(iftype_cbx, "Add a new interface or pipe to capture from or remove "
"an interface from the list.");
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_IFTYPE_CBX_KEY, iftype_cbx);
gtk_box_pack_start(GTK_BOX(right_vb), iftype_cbx, FALSE, FALSE, 0);
g_signal_connect(iftype_cbx, "clicked", G_CALLBACK(show_add_interfaces_dialog), NULL);
gtk_widget_show(iftype_cbx);
main_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_hb), 0);
gtk_box_pack_start(GTK_BOX(main_vb), main_hb, FALSE, FALSE, 0);
left_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(left_vb), 0);
gtk_box_pack_start(GTK_BOX(main_hb), left_vb, TRUE, TRUE, 0);
right_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(right_vb), 0);
gtk_box_pack_start(GTK_BOX(main_hb), right_vb, FALSE, FALSE, 0);
all_filter_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(all_vb), all_filter_hb, FALSE, FALSE, DLG_LABEL_SPACING);
all_filter_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_CAPTURE_FILTER_ENTRY);
g_signal_connect(all_filter_bt, "clicked", G_CALLBACK(capture_filter_construct_cb), NULL);
g_signal_connect(all_filter_bt, "destroy", G_CALLBACK(filter_button_destroy_cb), NULL);
gtk_widget_set_tooltip_text(all_filter_bt,
"Select a capture filter for all selected interfaces to reduce the amount of packets to be captured. "
"See \"Capture Filters\" in the online help for further information how to use it."
);
gtk_box_pack_start(GTK_BOX(all_filter_hb), all_filter_bt, FALSE, FALSE, 0);
all_filter_cm = gtk_combo_box_text_new_with_entry();
g_object_set_data(G_OBJECT(cap_open_w), E_ALL_CFILTER_CM_KEY, all_filter_cm);
all_filter_te = gtk_bin_get_child(GTK_BIN(all_filter_cm));
colorize_filter_te_as_empty(all_filter_te);
g_signal_connect(all_filter_te, "changed", G_CALLBACK(capture_all_filter_check_syntax_cb), NULL);
g_signal_connect(all_filter_te, "destroy", G_CALLBACK(capture_filter_destroy_cb), NULL);
all_cfilter_list = recent_get_cfilter_list(NULL);
for (cf_entry = all_cfilter_list; cf_entry != NULL; cf_entry = g_list_next(cf_entry)) {
new_cfilter = (const gchar *)cf_entry->data;
if (global_capture_opts.default_options.cfilter == NULL || strcmp(global_capture_opts.default_options.cfilter, new_cfilter) != 0) {
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(all_filter_cm), new_cfilter);
}
}
if (global_capture_opts.default_options.cfilter && (strlen(global_capture_opts.default_options.cfilter) > 0)) {
gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(all_filter_cm), global_capture_opts.default_options.cfilter);
gtk_combo_box_set_active(GTK_COMBO_BOX(all_filter_cm), 0);
}
gtk_widget_set_tooltip_text(all_filter_cm,
"Enter a capture filter for all selected interfaces to reduce the amount of packets to be captured. "
"See \"Capture Filters\" in the online help for further information how to use it. "
"Syntax checking can be disabled in Preferences -> Capture -> Syntax check capture filter."
);
gtk_box_pack_start(GTK_BOX(all_filter_hb), all_filter_cm, TRUE, TRUE, DLG_BUTTON_SPACING);
g_object_set_data(G_OBJECT(all_filter_bt), E_FILT_TE_PTR_KEY, all_filter_te);
#if defined(HAVE_PCAP_OPEN_DEAD) && defined(HAVE_BPF_IMAGE)
all_compile_bt = gtk_button_new_with_label("Compile selected BPFs");
g_signal_connect(all_compile_bt, "clicked", G_CALLBACK(capture_all_filter_compile_cb), NULL);
gtk_widget_set_tooltip_text(all_compile_bt,
"Compile the capture filter expression and show the BPF (Berkeley Packet Filter) code.");
gtk_box_pack_start(GTK_BOX(all_filter_hb), all_compile_bt, FALSE, FALSE, DLG_BUTTON_SPACING);
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(all_compile_bt, TRUE);
} else {
gtk_widget_set_sensitive(all_compile_bt, FALSE);
}
#endif
file_fr = frame_new("Capture Files");
gtk_box_pack_start(GTK_BOX (left_vb), file_fr, TRUE, TRUE, 0);
file_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(file_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(file_fr), file_vb);
file_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
gtk_box_pack_start(GTK_BOX(file_vb), file_hb, FALSE, FALSE, 0);
file_lb = gtk_label_new("File:");
gtk_box_pack_start(GTK_BOX(file_hb), file_lb, FALSE, FALSE, 3);
file_te = gtk_entry_new();
gtk_widget_set_tooltip_text(file_te,
"Enter the file name to which captured data will be written. "
"If you don't enter something here, a temporary file will be used."
);
gtk_box_pack_start(GTK_BOX(file_hb), file_te, TRUE, TRUE, 3);
file_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_BROWSE);
gtk_widget_set_tooltip_text(file_bt,
"Select a file to which captured data will be written, "
"instead of entering the file name directly. "
);
gtk_box_pack_start(GTK_BOX(file_hb), file_bt, FALSE, FALSE, 0);
g_signal_connect(file_bt, "clicked", G_CALLBACK(capture_prep_file_cb), file_te);
multi_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(file_vb), multi_hb, FALSE, FALSE, 0);
multi_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(multi_grid), DLG_LABEL_SPACING);
ws_gtk_grid_set_column_spacing(GTK_GRID(multi_grid), DLG_UNRELATED_SPACING);
gtk_box_pack_start(GTK_BOX(multi_hb), multi_grid, FALSE, FALSE, 0);
row = 0;
multi_files_on_cb = gtk_check_button_new_with_mnemonic("Use _multiple files");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(multi_files_on_cb),
global_capture_opts.multi_files_on);
g_signal_connect(multi_files_on_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity),
cap_open_w);
gtk_widget_set_tooltip_text(multi_files_on_cb,
"Instead of using a single capture file, multiple files will be created. "
"The generated file names will contain an incrementing number and the start time of the capture.");
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), multi_files_on_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
pcap_ng_cb = gtk_check_button_new_with_mnemonic("Use pcap-ng format");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(pcap_ng_cb), global_capture_opts.use_pcapng);
gtk_widget_set_tooltip_text(pcap_ng_cb, "Capture packets in the next-generation capture file format. "
"This is still experimental.");
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), pcap_ng_cb, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
row++;
ring_filesize_cb = gtk_check_button_new_with_label("Next file every");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ring_filesize_cb),
global_capture_opts.has_autostop_filesize || !global_capture_opts.has_file_duration);
g_signal_connect(ring_filesize_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(ring_filesize_cb,
"If the selected file size is exceeded, capturing switches to the next file.\n"
"PLEASE NOTE: at least one of the \"Next file every\" options MUST be selected.");
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ring_filesize_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
ring_filesize_adj = (GtkAdjustment *) gtk_adjustment_new(0.0,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
ring_filesize_sb = gtk_spin_button_new (ring_filesize_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (ring_filesize_sb), TRUE);
gtk_widget_set_size_request(ring_filesize_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ring_filesize_sb, 1, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
ring_filesize_cbx = size_unit_combo_box_new(global_capture_opts.autostop_filesize);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ring_filesize_cbx, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
value = size_unit_combo_box_set_value(global_capture_opts.autostop_filesize);
gtk_adjustment_set_value(ring_filesize_adj, (gdouble) value);
row++;
file_duration_cb = gtk_check_button_new_with_label("Next file every");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(file_duration_cb),
global_capture_opts.has_file_duration);
g_signal_connect(file_duration_cb, "toggled",
G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(file_duration_cb,
"If the selected duration is exceeded, capturing switches to the next file.\n"
"PLEASE NOTE: at least one of the \"Next file every\" options MUST be selected.");
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), file_duration_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
file_duration_adj = (GtkAdjustment *)gtk_adjustment_new(0.0,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
file_duration_sb = gtk_spin_button_new (file_duration_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (file_duration_sb), TRUE);
gtk_widget_set_size_request(file_duration_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), file_duration_sb, 1, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
file_duration_cbx = time_unit_combo_box_new(global_capture_opts.file_duration);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), file_duration_cbx, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
value = time_unit_combo_box_convert_value(global_capture_opts.file_duration);
gtk_adjustment_set_value(file_duration_adj, (gdouble) value);
row++;
ringbuffer_nbf_cb = gtk_check_button_new_with_label("Ring buffer with");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ringbuffer_nbf_cb),
global_capture_opts.has_ring_num_files);
g_signal_connect(ringbuffer_nbf_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(ringbuffer_nbf_cb,
"After capturing has switched to the next file and the given number of files has exceeded, "
"the oldest file will be removed."
);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ringbuffer_nbf_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
ringbuffer_nbf_adj = (GtkAdjustment *) gtk_adjustment_new((gfloat) global_capture_opts.ring_num_files,
2, RINGBUFFER_MAX_NUM_FILES, 1.0, 10.0, 0.0);
ringbuffer_nbf_sb = gtk_spin_button_new (ringbuffer_nbf_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (ringbuffer_nbf_sb), TRUE);
gtk_widget_set_size_request(ringbuffer_nbf_sb, 80, -1);
g_signal_connect(ringbuffer_nbf_sb, "changed", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ringbuffer_nbf_sb, 1, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
ringbuffer_nbf_lb = gtk_label_new("files");
gtk_misc_set_alignment(GTK_MISC(ringbuffer_nbf_lb), 0, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID (multi_grid), ringbuffer_nbf_lb, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
row++;
limit_fr = frame_new("Stop Capture Automatically After...");
gtk_box_pack_start(GTK_BOX (left_vb), limit_fr, TRUE, TRUE, 0);
limit_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(limit_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(limit_fr), limit_vb);
limit_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(limit_vb), limit_hb, FALSE, FALSE, 0);
limit_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(limit_grid), DLG_LABEL_SPACING);
ws_gtk_grid_set_column_spacing(GTK_GRID(limit_grid), DLG_UNRELATED_SPACING);
gtk_box_pack_start(GTK_BOX(limit_hb), limit_grid, FALSE, FALSE, 0);
row = 0;
stop_packets_cb = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_packets_cb),
global_capture_opts.has_autostop_packets);
g_signal_connect(stop_packets_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(stop_packets_cb, "Stop capturing after the specified number of packets have been captured.");
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_packets_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_packets_adj = (GtkAdjustment *) gtk_adjustment_new((gfloat)global_capture_opts.autostop_packets,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
stop_packets_sb = gtk_spin_button_new (stop_packets_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (stop_packets_sb), TRUE);
gtk_widget_set_size_request(stop_packets_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_packets_sb, 1, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_packets_lb = gtk_label_new("packet(s)");
gtk_misc_set_alignment(GTK_MISC(stop_packets_lb), 0, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_packets_lb, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_filesize_cb = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_filesize_cb),
global_capture_opts.has_autostop_filesize);
g_signal_connect(stop_filesize_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(stop_filesize_cb, "Stop capturing after the specified amount of data has been captured.");
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_filesize_cb, 3, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_filesize_adj = (GtkAdjustment *) gtk_adjustment_new(0.0,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
stop_filesize_sb = gtk_spin_button_new (stop_filesize_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (stop_filesize_sb), TRUE);
gtk_widget_set_size_request(stop_filesize_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_filesize_sb, 4, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_filesize_cbx = size_unit_combo_box_new(global_capture_opts.autostop_filesize);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_filesize_cbx, 5, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
value = size_unit_combo_box_set_value(global_capture_opts.autostop_filesize);
gtk_adjustment_set_value(stop_filesize_adj, (gdouble) value);
row++;
stop_files_cb = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_files_cb),
global_capture_opts.has_autostop_files);
g_signal_connect(stop_files_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(stop_files_cb, "Stop capturing after the given number of \"file switches\" have been done.");
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_files_cb, 0, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_files_adj = (GtkAdjustment *) gtk_adjustment_new((gfloat)global_capture_opts.autostop_files,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
stop_files_sb = gtk_spin_button_new (stop_files_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (stop_files_sb), TRUE);
gtk_widget_set_size_request(stop_files_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_files_sb, 1, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_files_lb = gtk_label_new("file(s)");
gtk_misc_set_alignment(GTK_MISC(stop_files_lb), 0, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_files_lb, 2, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_duration_cb = gtk_check_button_new();
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_duration_cb),
global_capture_opts.has_autostop_duration);
g_signal_connect(stop_duration_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(stop_duration_cb, "Stop capturing after the specified amount of time has passed.");
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_duration_cb, 3, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_duration_adj = (GtkAdjustment *) gtk_adjustment_new(0.0,
1, (gfloat)INT_MAX, 1.0, 10.0, 0.0);
stop_duration_sb = gtk_spin_button_new (stop_duration_adj, 0, 0);
gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (stop_duration_sb), TRUE);
gtk_widget_set_size_request(stop_duration_sb, 80, -1);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_duration_sb, 4, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
stop_duration_cbx = time_unit_combo_box_new(global_capture_opts.autostop_duration);
ws_gtk_grid_attach_extended(GTK_GRID (limit_grid), stop_duration_cbx, 5, row, 1, 1,
(GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(GTK_FILL), 0, 0);
value = time_unit_combo_box_convert_value(global_capture_opts.autostop_duration);
gtk_adjustment_set_value(stop_duration_adj, (gdouble) value);
row++;
display_fr = frame_new("Display Options");
gtk_box_pack_start(GTK_BOX (right_vb), display_fr, TRUE, TRUE, 0);
display_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(display_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(display_fr), display_vb);
sync_cb = gtk_check_button_new_with_mnemonic(
"_Update list of packets in real time");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(sync_cb),
global_capture_opts.real_time_mode);
g_signal_connect(sync_cb, "toggled", G_CALLBACK(capture_prep_adjust_sensitivity), cap_open_w);
gtk_widget_set_tooltip_text(sync_cb,
"Using this option will show the captured packets immediately on the main screen. "
"Please note: this will slow down capturing, so increased packet drops might appear.");
gtk_box_pack_start(GTK_BOX (display_vb), sync_cb, FALSE, TRUE, 0);
auto_scroll_cb = gtk_check_button_new_with_mnemonic("_Automatically scroll during live capture");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(auto_scroll_cb), auto_scroll_live);
gtk_widget_set_tooltip_text(auto_scroll_cb,
"This will scroll the \"Packet List\" automatically to the latest captured packet, "
"when the \"Update List of packets in real time\" option is used.");
gtk_box_pack_start(GTK_BOX (display_vb), auto_scroll_cb, FALSE, TRUE, 0);
hide_info_cb = gtk_check_button_new_with_mnemonic("_Hide capture info dialog");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hide_info_cb), !global_capture_opts.show_info);
gtk_widget_set_tooltip_text(hide_info_cb, "Hide the capture info dialog while capturing.");
gtk_box_pack_start(GTK_BOX (display_vb), hide_info_cb, FALSE, TRUE, 0);
resolv_fr = frame_new("Name Resolution");
gtk_box_pack_start(GTK_BOX (right_vb), resolv_fr, TRUE, TRUE, 0);
resolv_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_LABEL_SPACING, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(resolv_vb), DLG_OUTER_MARGIN);
gtk_container_add(GTK_CONTAINER(resolv_fr), resolv_vb);
m_resolv_cb = gtk_check_button_new_with_mnemonic(
"Resolve _MAC addresses");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(m_resolv_cb),
gbl_resolv_flags.mac_name);
gtk_widget_set_tooltip_text(m_resolv_cb, "Perform MAC layer name resolution while capturing.");
gtk_box_pack_start(GTK_BOX (resolv_vb), m_resolv_cb, FALSE, TRUE, 0);
n_resolv_cb = gtk_check_button_new_with_mnemonic(
"Resolve _network-layer names");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(n_resolv_cb),
gbl_resolv_flags.network_name);
gtk_widget_set_tooltip_text(n_resolv_cb, "Perform network layer name resolution while capturing.");
gtk_box_pack_start(GTK_BOX (resolv_vb), n_resolv_cb, FALSE, TRUE, 0);
t_resolv_cb = gtk_check_button_new_with_mnemonic(
"Resolve _transport-layer name");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(t_resolv_cb),
gbl_resolv_flags.transport_name);
gtk_widget_set_tooltip_text(t_resolv_cb,
"Perform transport layer name resolution while capturing.");
gtk_box_pack_start(GTK_BOX (resolv_vb), t_resolv_cb, FALSE, TRUE, 0);
e_resolv_cb = gtk_check_button_new_with_mnemonic(
"Use _external network name resolver");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(e_resolv_cb),
gbl_resolv_flags.use_external_net_name_resolver);
gtk_widget_set_tooltip_text(e_resolv_cb,
"Use the (system's) configured name resolver (e.g., DNS) to resolve network names.");
gtk_box_pack_start(GTK_BOX (resolv_vb), e_resolv_cb, FALSE, TRUE, 0);
bbox = dlg_button_row_new(WIRESHARK_STOCK_CAPTURE_START, GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 5);
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CAPTURE_START);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(capture_start_cb), NULL);
gtk_widget_set_tooltip_text(ok_bt, "Start the capture process.");
if (global_capture_opts.num_selected > 0) {
gtk_widget_set_sensitive(ok_bt, TRUE);
} else {
gtk_widget_set_sensitive(ok_bt, FALSE);
}
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
gtk_widget_set_tooltip_text(close_bt,
"Exit dialog.");
window_set_cancel_button(cap_open_w, close_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
gtk_widget_set_tooltip_text(help_bt,
"Show help about capturing.");
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), GUINT_TO_POINTER(HELP_CAPTURE_OPTIONS_DIALOG));
gtk_widget_grab_default(ok_bt);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_KEY_ALL, all_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_PROMISC_KEY_ALL, promisc_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_PCAP_NG_KEY, pcap_ng_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_FILE_TE_KEY, file_te);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_MULTI_FILES_ON_CB_KEY, multi_files_on_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_NBF_CB_KEY, ringbuffer_nbf_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_NBF_SB_KEY, ringbuffer_nbf_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_NBF_LB_KEY, ringbuffer_nbf_lb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_FILESIZE_CB_KEY, ring_filesize_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_FILESIZE_SB_KEY, ring_filesize_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_RING_FILESIZE_CBX_KEY, ring_filesize_cbx);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_FILE_DURATION_CB_KEY, file_duration_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_FILE_DURATION_SB_KEY, file_duration_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_FILE_DURATION_CBX_KEY, file_duration_cbx);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_SYNC_KEY, sync_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_AUTO_SCROLL_KEY, auto_scroll_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_HIDE_INFO_KEY, hide_info_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_PACKETS_CB_KEY, stop_packets_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_PACKETS_SB_KEY, stop_packets_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_PACKETS_LB_KEY, stop_packets_lb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILESIZE_CB_KEY, stop_filesize_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILESIZE_SB_KEY, stop_filesize_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILESIZE_CBX_KEY, stop_filesize_cbx);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_DURATION_CB_KEY, stop_duration_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_DURATION_SB_KEY, stop_duration_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_DURATION_CBX_KEY, stop_duration_cbx);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILES_CB_KEY, stop_files_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILES_SB_KEY, stop_files_sb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_STOP_FILES_LB_KEY, stop_files_lb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_M_RESOLVE_KEY, m_resolv_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_N_RESOLVE_KEY, n_resolv_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_T_RESOLVE_KEY, t_resolv_cb);
g_object_set_data(G_OBJECT(cap_open_w), E_CAP_E_RESOLVE_KEY, e_resolv_cb);
capture_prep_adjust_sensitivity(NULL, cap_open_w);
update_properties_all();
update_visible_columns_menu ();
dlg_set_activate(file_te, ok_bt);
dlg_set_activate(all_filter_te, ok_bt);
gtk_widget_grab_focus(all_filter_te);
g_signal_connect(cap_open_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(cap_open_w, "destroy", G_CALLBACK(capture_prep_destroy_cb), NULL);
window_get_geometry(top_level, &tl_geom);
gtk_window_set_default_size(GTK_WINDOW(cap_open_w), tl_geom.width * 8 / 10, -1);
gtk_widget_show_all(cap_open_w);
window_present(cap_open_w);
cap_open_complete = TRUE;
global_capture_session.session_started = TRUE;
}
void
capture_start_cb(GtkWidget *w _U_, gpointer d _U_)
{
interface_options interface_opts;
guint i;
gchar * filter_str;
#ifdef HAVE_AIRPCAP
airpcap_if_active = airpcap_if_selected;
if (airpcap_if_active)
airpcap_set_toolbar_start_capture(airpcap_if_active);
#endif
if(!do_file_close(&cfile, FALSE, " before starting a new capture")){
return;
}
if (cap_open_w) {
gboolean success;
if (cap_open_complete == FALSE) {
return;
}
success = capture_dlg_prep(cap_open_w);
if (success)
window_destroy(GTK_WIDGET(cap_open_w));
if (!success)
return;
}
if (global_capture_opts.num_selected == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"You didn't specify an interface on which to capture packets.");
return;
}
main_auto_scroll_live_changed(auto_scroll_live);
if (global_capture_session.state != CAPTURE_STOPPED)
return;
cf_close((capture_file *)global_capture_session.cf);
collect_ifaces(&global_capture_opts);
if (capture_start(&global_capture_opts, &global_capture_session, main_window_update)) {
filter_str = NULL;
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
if (interface_opts.cfilter) {
recent_add_cfilter(interface_opts.name, interface_opts.cfilter);
if (filter_str == NULL) {
filter_str = g_strdup(interface_opts.cfilter);
} else {
if (strcmp(interface_opts.cfilter, filter_str) != 0) {
if (filter_str != NULL) {
g_free(filter_str);
}
filter_str = NULL;
}
}
}
}
if (filter_str != NULL) {
if (filter_str[0] != '\0') {
recent_add_cfilter(NULL, filter_str);
}
g_free(filter_str);
}
}
}
static void
select_link_type_cb(GtkWidget *linktype_combo_box, gpointer data _U_)
{
gpointer ptr;
int dlt;
interface_t device;
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
if (! ws_combo_box_get_active_pointer(GTK_COMBO_BOX(linktype_combo_box), &ptr)) {
g_assert_not_reached();
}
if ((dlt = GPOINTER_TO_INT(ptr)) == -1) {
g_assert_not_reached();
}
device.active_dlt = dlt;
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
capture_filter_check_syntax_cb(linktype_combo_box, data);
}
static void
capture_prep_file_cb(GtkWidget *file_bt, GtkWidget *file_te)
{
file_selection_browse(file_bt, file_te, "Wireshark: Specify a Capture File", FILE_SELECTION_WRITE_BROWSE);
}
static void
capture_prep_pipe_cb(GtkWidget *pipe_bt, GtkWidget *pipe_te)
{
file_selection_browse(pipe_bt, pipe_te, "Wireshark: Specify a Pipe", FILE_SELECTION_WRITE_BROWSE);
}
static gboolean
capture_dlg_prep(gpointer parent_w) {
GtkWidget *pcap_ng_cb,
*file_te, *multi_files_on_cb, *ringbuffer_nbf_sb, *ringbuffer_nbf_cb,
*sync_cb, *auto_scroll_cb, *hide_info_cb,
*stop_packets_cb, *stop_packets_sb,
*stop_filesize_cb, *stop_filesize_sb, *stop_filesize_cbx,
*stop_duration_cb, *stop_duration_sb, *stop_duration_cbx,
*ring_filesize_cb, *ring_filesize_sb, *ring_filesize_cbx,
*file_duration_cb, *file_duration_sb, *file_duration_cbx,
*stop_files_cb, *stop_files_sb,
*m_resolv_cb, *n_resolv_cb, *t_resolv_cb, *e_resolv_cb;
const gchar *g_save_file;
gchar *cf_name;
gchar *dirname;
gint32 tmp;
pcap_ng_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_PCAP_NG_KEY);
file_te = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_TE_KEY);
multi_files_on_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_MULTI_FILES_ON_CB_KEY);
ringbuffer_nbf_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_NBF_CB_KEY);
ringbuffer_nbf_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_NBF_SB_KEY);
ring_filesize_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_CB_KEY);
ring_filesize_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_SB_KEY);
ring_filesize_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_CBX_KEY);
file_duration_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_CB_KEY);
file_duration_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_SB_KEY);
file_duration_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_CBX_KEY);
sync_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SYNC_KEY);
auto_scroll_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_AUTO_SCROLL_KEY);
hide_info_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_HIDE_INFO_KEY);
stop_packets_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_PACKETS_CB_KEY);
stop_packets_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_PACKETS_SB_KEY);
stop_filesize_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_CB_KEY);
stop_filesize_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_SB_KEY);
stop_filesize_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_CBX_KEY);
stop_duration_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_CB_KEY);
stop_duration_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_SB_KEY);
stop_duration_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_CBX_KEY);
stop_files_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILES_CB_KEY);
stop_files_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILES_SB_KEY);
m_resolv_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_M_RESOLVE_KEY);
n_resolv_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_N_RESOLVE_KEY);
t_resolv_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_T_RESOLVE_KEY);
e_resolv_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_E_RESOLVE_KEY);
if (global_capture_opts.num_selected == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"You didn't specify an interface on which to capture packets.");
return FALSE;
}
global_capture_opts.use_pcapng =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pcap_ng_cb));
global_capture_opts.saving_to_file = TRUE;
g_save_file = gtk_entry_get_text(GTK_ENTRY(file_te));
if (g_save_file && g_save_file[0]) {
global_capture_opts.save_file = g_strdup(g_save_file);
global_capture_opts.orig_save_file = g_strdup(g_save_file);
cf_name = g_strdup(g_save_file);
dirname = get_dirname(cf_name);
set_last_open_dir(dirname);
g_free(cf_name);
} else {
global_capture_opts.save_file = NULL;
}
global_capture_opts.has_autostop_packets =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_packets_cb));
if (global_capture_opts.has_autostop_packets)
global_capture_opts.autostop_packets =
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(stop_packets_sb));
global_capture_opts.has_autostop_duration =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_duration_cb));
if (global_capture_opts.has_autostop_duration) {
global_capture_opts.autostop_duration =
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(stop_duration_sb));
global_capture_opts.autostop_duration =
time_unit_combo_box_get_value(stop_duration_cbx, global_capture_opts.autostop_duration);
}
global_capture_opts.real_time_mode =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sync_cb));
auto_scroll_live =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(auto_scroll_cb));
global_capture_opts.show_info =
!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hide_info_cb));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(m_resolv_cb)))
gbl_resolv_flags.mac_name = TRUE;
else
gbl_resolv_flags.mac_name = FALSE;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(n_resolv_cb)))
gbl_resolv_flags.network_name = TRUE;
else
gbl_resolv_flags.network_name = FALSE;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(t_resolv_cb)))
gbl_resolv_flags.transport_name = TRUE;
else
gbl_resolv_flags.transport_name = FALSE;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(e_resolv_cb)))
gbl_resolv_flags.use_external_net_name_resolver = TRUE;
else
gbl_resolv_flags.use_external_net_name_resolver = FALSE;
global_capture_opts.has_ring_num_files =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ringbuffer_nbf_cb));
global_capture_opts.ring_num_files =
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ringbuffer_nbf_sb));
if (global_capture_opts.ring_num_files > RINGBUFFER_MAX_NUM_FILES)
global_capture_opts.ring_num_files = RINGBUFFER_MAX_NUM_FILES;
#if RINGBUFFER_MIN_NUM_FILES > 0
else if (global_capture_opts.ring_num_files < RINGBUFFER_MIN_NUM_FILES)
global_capture_opts.ring_num_files = RINGBUFFER_MIN_NUM_FILES;
#endif
global_capture_opts.multi_files_on =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(multi_files_on_cb));
global_capture_opts.has_file_duration =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(file_duration_cb));
if (global_capture_opts.has_file_duration) {
global_capture_opts.file_duration =
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(file_duration_sb));
global_capture_opts.file_duration =
time_unit_combo_box_get_value(file_duration_cbx, global_capture_opts.file_duration);
}
global_capture_opts.has_autostop_files =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_files_cb));
if (global_capture_opts.has_autostop_files)
global_capture_opts.autostop_files =
gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(stop_files_sb));
if (global_capture_opts.multi_files_on) {
global_capture_opts.has_autostop_filesize =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ring_filesize_cb));
if (global_capture_opts.has_autostop_filesize) {
tmp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ring_filesize_sb));
tmp = size_unit_combo_box_convert_value(ring_filesize_cbx, tmp);
if (tmp != 0) {
global_capture_opts.autostop_filesize = tmp;
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sMultiple files: Requested filesize too large!%s\n\n"
"The setting \"Next file every x byte(s)\" can't be greater than %u bytes (2GiB).",
simple_dialog_primary_start(), simple_dialog_primary_end(), (guint32)G_MAXINT + 1);
return FALSE;
}
}
if (global_capture_opts.save_file == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sMultiple files: No capture file name given!%s\n\n"
"You must specify a filename if you want to use multiple files.",
simple_dialog_primary_start(), simple_dialog_primary_end());
return FALSE;
} else if (!global_capture_opts.has_autostop_filesize && !global_capture_opts.has_file_duration) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sMultiple files: No file limit given!%s\n\n"
"You must specify a file size or duration at which is switched to the next capture file\n"
"if you want to use multiple files.",
simple_dialog_primary_start(), simple_dialog_primary_end());
g_free(global_capture_opts.save_file);
global_capture_opts.save_file = NULL;
return FALSE;
}
} else {
global_capture_opts.has_autostop_filesize =
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_filesize_cb));
if (global_capture_opts.has_autostop_filesize) {
tmp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(stop_filesize_sb));
tmp = size_unit_combo_box_convert_value(stop_filesize_cbx, tmp);
if (tmp != 0) {
global_capture_opts.autostop_filesize = tmp;
} else {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sStop Capture: Requested filesize too large!%s\n\n"
"The setting \"after x byte(s)\" can't be greater than %u bytes (2GiB).",
simple_dialog_primary_start(), simple_dialog_primary_end(), (guint32)G_MAXINT + 1);
return FALSE;
}
}
}
return TRUE;
}
static GtkTreeModel *
create_and_fill_model(GtkTreeView *view)
{
GtkListStore *store;
GtkTreeIter iter;
GList *list;
char *temp, *snaplen_string, *linkname;
guint i;
link_row *linkr = NULL;
interface_t device;
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
gint buffer;
#endif
gint snaplen;
gboolean hassnap, pmode;
#if defined(HAVE_PCAP_CREATE)
store = gtk_list_store_new (9, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING, G_TYPE_STRING);
#elif defined(_WIN32) && !defined (HAVE_PCAP_CREATE)
store = gtk_list_store_new (8, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING);
#else
store = gtk_list_store_new (7, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
#endif
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (!device.hidden) {
if (device.no_addresses == 0) {
temp = g_strdup_printf("<b>%s</b>", device.display_name);
} else {
temp = g_strdup_printf("<b>%s</b>\n<span size='small'>%s</span>", device.display_name, device.addresses);
}
linkname = NULL;
if(capture_dev_user_linktype_find(device.name) != -1) {
device.active_dlt = capture_dev_user_linktype_find(device.name);
}
for (list = device.links; list != NULL; list = g_list_next(list)) {
linkr = (link_row*)(list->data);
if (linkr->dlt == device.active_dlt) {
linkname = g_strdup(linkr->name);
break;
}
}
if (!linkname)
linkname = g_strdup("unknown");
pmode = capture_dev_user_pmode_find(device.name);
if (pmode != -1) {
device.pmode = pmode;
}
hassnap = capture_dev_user_hassnap_find(device.name);
snaplen = capture_dev_user_snaplen_find(device.name);
if(snaplen != -1 && hassnap != -1) {
device.snaplen = snaplen;
device.has_snaplen = hassnap;
} else {
device.snaplen = WTAP_MAX_PACKET_SIZE;
device.has_snaplen = FALSE;
}
snaplen_string = g_strdup_printf("%d", device.snaplen);
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
if (capture_dev_user_buffersize_find(device.name) != -1) {
buffer = capture_dev_user_buffersize_find(device.name);
device.buffer = buffer;
} else {
device.buffer = DEFAULT_CAPTURE_BUFFER_SIZE;
}
#endif
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
gtk_list_store_append (store, &iter);
#if defined(HAVE_PCAP_CREATE)
gtk_list_store_set (store, &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, MONITOR, device.monitor_mode_supported?(device.monitor_mode_enabled?"enabled":"disabled"):"n/a", FILTER, device.cfilter, -1);
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
gtk_list_store_set (store, &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, BUFFER, (guint) device.buffer, FILTER, device.cfilter, -1);
#else
gtk_list_store_set (store, &iter, CAPTURE, device.selected, IFACE_HIDDEN_NAME, device.name, INTERFACE, temp, LINK, linkname, PMODE, device.pmode?"enabled":"disabled", SNAPLEN, snaplen_string, FILTER, device.cfilter, -1);
#endif
g_free(linkname);
}
}
gtk_tree_view_set_model(GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));
return GTK_TREE_MODEL(store);
}
static gboolean
query_tooltip_tree_view_cb (GtkWidget *widget,
gint x,
gint y,
gboolean keyboard_tip,
GtkTooltip *tooltip,
gpointer data _U_)
{
GtkTreeIter iter;
GtkTreeView *tree_view = GTK_TREE_VIEW (widget);
GtkTreeModel *model = gtk_tree_view_get_model (tree_view);
GtkTreePath *path = NULL;
gchar *tmp;
GtkTreeViewColumn *column;
GtkCellRenderer* renderer = NULL;
GList *renderer_list;
gint idx;
char buffer[512];
if (!gtk_tree_view_get_tooltip_context (tree_view, &x, &y, keyboard_tip, &model, &path, &iter))
return FALSE;
gtk_tree_model_get (model, &iter, 0, &tmp, -1);
if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(tree_view), (gint) x, (gint) y, NULL, &column, NULL, NULL)) {
idx = col_title_to_index((const gchar *)gtk_tree_view_column_get_title(column));
switch (idx)
{
case CAPTURE: g_snprintf (buffer, sizeof(buffer), "Choose which interface (network adapter) will be used to capture packets from. "
"Be sure to select the correct one, as it's a common mistake to select the wrong interface.");
break;
case INTERFACE: g_snprintf (buffer, sizeof(buffer), "Lists the interface name and the IP address(es) assigned to it. ");
break;
case LINK: g_snprintf (buffer, sizeof(buffer), "Link-layer type the interface supports.");
break;
case PMODE: g_snprintf (buffer, sizeof(buffer), "Usually a network adapter will only capture the traffic sent to its own network address. "
"If you want to capture all traffic that the network adapter can \"see\", promiscuous mode should be configured.");
break;
case SNAPLEN: g_snprintf(buffer, sizeof(buffer), "Limit the maximum number of bytes to be captured from each packet. This size includes the "
"link-layer header and all subsequent headers.");
break;
#if defined(HAVE_PCAP_CREATE)
case BUFFER: g_snprintf (buffer, sizeof(buffer), "The memory buffer size used while capturing. "
"If you notice packet drops, you can try increasing this size.");
break;
case MONITOR: g_snprintf (buffer, sizeof(buffer), "Usually a Wi-Fi adapter will, even in promiscuous mode, only capture "
"the traffic on the BSS to which it's associated. "
"If you want to capture all traffic that the Wi-Fi adapter can \"receive\", select this option. "
"In order to see IEEE 802.11 headers or to see radio information for captured packets, "
"it might be necessary to turn this option on.\n\n"
"Note that, in monitor mode, the adapter might disassociate from the network to which it's associated.");
break;
#elif defined(_WIN32) && !defined(HAVE_PCAP_CREATE)
case BUFFER: g_snprintf (buffer, sizeof(buffer), "The memory buffer size used while capturing. "
"If you notice packet drops, you can try increasing this size.");
break;
#endif
case FILTER: g_snprintf(buffer, sizeof(buffer), "Selected capture filter to reduce the amount of packets to be captured.");
break;
default: g_snprintf(buffer, sizeof(buffer), "another option");
}
gtk_tooltip_set_markup (tooltip, buffer);
renderer_list = gtk_cell_layout_get_cells(GTK_CELL_LAYOUT(column));
if (g_list_first(renderer_list)) {
renderer = (GtkCellRenderer*)g_list_nth_data(renderer_list, 0);
gtk_tree_view_set_tooltip_cell (tree_view, tooltip, path, column, renderer);
}
}
gtk_tree_path_free (path);
return TRUE;
}
static void
activate_monitor(GtkTreeViewColumn *tree_column _U_, GtkCellRenderer *renderer,
GtkTreeModel *tree_model, GtkTreeIter *iter, gpointer data _U_)
{
interface_t device;
GtkTreePath *path = gtk_tree_model_get_path(tree_model, iter);
int indx = atoi(gtk_tree_path_to_string(path));
device = g_array_index(global_capture_opts.all_ifaces, interface_t, indx);
if (device.monitor_mode_supported == TRUE) {
g_object_set(G_OBJECT(renderer), "mode", GTK_CELL_RENDERER_MODE_ACTIVATABLE, NULL);
} else {
g_object_set(G_OBJECT(renderer), "mode", GTK_CELL_RENDERER_MODE_INERT, NULL);
}
}
static void
capture_prep_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
GtkWidget *fs;
#ifdef HAVE_PCAP_REMOTE
GList *if_list;
#endif
if (!cap_open_w || !G_IS_OBJECT(cap_open_w))
return;
fs = (GtkWidget *)g_object_get_data(G_OBJECT(cap_open_w), E_FILE_SEL_DIALOG_PTR_KEY);
#ifdef HAVE_PCAP_REMOTE
if_list = (GList *) g_object_get_data(G_OBJECT(cap_open_w), E_CAP_IF_LIST_KEY);
if (if_list && g_list_length(if_list)>0) {
free_interface_list(if_list);
}
#endif
if (fs != NULL && G_IS_OBJECT(fs)) {
window_destroy(fs);
}
cap_open_w = NULL;
#ifdef HAVE_AIRPCAP
if (airpcap_if_active)
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
}
static void
capture_prep_monitor_changed_cb(GtkWidget *monitor, gpointer argp _U_)
{
GList *lt_entry;
gchar *if_string;
gboolean monitor_mode;
if_capabilities_t *caps;
gint linktype_count = 0, i;
data_link_info_t *data_link_info;
interface_t device;
link_row *linkr;
GtkWidget *linktype_combo_box = (GtkWidget *) g_object_get_data(G_OBJECT(opt_edit_w), E_CAP_LT_CBX_KEY);
GtkWidget *linktype_lb = (GtkWidget *)g_object_get_data(G_OBJECT(linktype_combo_box), E_CAP_LT_CBX_LABEL_KEY);
device = g_array_index(global_capture_opts.all_ifaces, interface_t, marked_interface);
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, marked_interface);
if_string = g_strdup(device.name);
monitor_mode = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(monitor));
caps = capture_get_if_capabilities(if_string, monitor_mode, NULL, main_window_update);
if (caps != NULL) {
g_signal_handlers_disconnect_by_func(linktype_combo_box, G_CALLBACK(select_link_type_cb), NULL );
ws_combo_box_clear_text_and_pointer(GTK_COMBO_BOX(linktype_combo_box));
for (i = (gint)g_list_length(device.links)-1; i >= 0; i--) {
GList* rem = g_list_nth(device.links, i);
device.links = g_list_remove_link(device.links, rem);
g_list_free_1(rem);
}
device.active_dlt = -1;
linktype_count = 0;
device.monitor_mode_supported = caps->can_set_rfmon;
device.monitor_mode_enabled = monitor_mode;
for (lt_entry = caps->data_link_types; lt_entry != NULL; lt_entry = g_list_next(lt_entry)) {
linkr = (link_row *)g_malloc(sizeof(link_row));
data_link_info = (data_link_info_t *)lt_entry->data;
if (data_link_info->description != NULL) {
ws_combo_box_append_text_and_pointer(GTK_COMBO_BOX(linktype_combo_box),
data_link_info->description,
GINT_TO_POINTER(data_link_info->dlt));
linkr->dlt = data_link_info->dlt;
if (linktype_count == 0) {
device.active_dlt = data_link_info->dlt;
}
linkr->name = g_strdup(data_link_info->description);
} else {
gchar *str;
str = g_strdup_printf("%s (not supported)", data_link_info->name);
ws_combo_box_append_text_and_pointer_full(GTK_COMBO_BOX(linktype_combo_box),
NULL,
str,
GINT_TO_POINTER(-1),
FALSE);
linkr->dlt = -1;
linkr->name = g_strdup(str);
g_free(str);
}
device.links = g_list_append(device.links, linkr);
linktype_count++;
}
free_if_capabilities(caps);
} else {
device.monitor_mode_enabled = FALSE;
device.monitor_mode_supported = FALSE;
}
gtk_widget_set_sensitive(linktype_lb, linktype_count >= 2);
gtk_widget_set_sensitive(linktype_combo_box, linktype_count >= 2);
ws_combo_box_set_active(GTK_COMBO_BOX(linktype_combo_box),0);
g_array_insert_val(global_capture_opts.all_ifaces, marked_interface, device);
}
static void
capture_prep_adjust_sensitivity(GtkWidget *tb _U_, gpointer parent_w)
{
GtkWidget *multi_files_on_cb, *ringbuffer_nbf_cb, *ringbuffer_nbf_sb, *ringbuffer_nbf_lb,
*ring_filesize_cb, *ring_filesize_sb, *ring_filesize_cbx,
*file_duration_cb, *file_duration_sb, *file_duration_cbx,
*sync_cb, *auto_scroll_cb,
*stop_packets_cb, *stop_packets_sb, *stop_packets_lb,
*stop_filesize_cb, *stop_filesize_sb, *stop_filesize_cbx,
*stop_duration_cb, *stop_duration_sb, *stop_duration_cbx,
*stop_files_cb, *stop_files_sb, *stop_files_lb;
multi_files_on_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_MULTI_FILES_ON_CB_KEY);
ringbuffer_nbf_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_NBF_CB_KEY);
ringbuffer_nbf_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_NBF_SB_KEY);
ringbuffer_nbf_lb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_NBF_LB_KEY);
ring_filesize_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_CB_KEY);
ring_filesize_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_SB_KEY);
ring_filesize_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_RING_FILESIZE_CBX_KEY);
file_duration_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_CB_KEY);
file_duration_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_SB_KEY);
file_duration_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_FILE_DURATION_CBX_KEY);
sync_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_SYNC_KEY);
auto_scroll_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_AUTO_SCROLL_KEY);
stop_packets_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_PACKETS_CB_KEY);
stop_packets_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_PACKETS_SB_KEY);
stop_packets_lb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_PACKETS_LB_KEY);
stop_filesize_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_CB_KEY);
stop_filesize_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_SB_KEY);
stop_filesize_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILESIZE_CBX_KEY);
stop_duration_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_CB_KEY);
stop_duration_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_SB_KEY);
stop_duration_cbx = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_DURATION_CBX_KEY);
stop_files_cb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILES_CB_KEY);
stop_files_sb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILES_SB_KEY);
stop_files_lb = (GtkWidget *) g_object_get_data(G_OBJECT(parent_w), E_CAP_STOP_FILES_LB_KEY);
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sync_cb))) {
#if 0
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(multi_files_on_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(multi_files_on_cb), FALSE);
#endif
gtk_widget_set_sensitive(GTK_WIDGET(auto_scroll_cb), TRUE);
} else {
gtk_widget_set_sensitive(GTK_WIDGET(auto_scroll_cb), FALSE);
}
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(multi_files_on_cb))) {
if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ring_filesize_cb)) == FALSE) &&
(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(file_duration_cb)) == FALSE)) {
if (tb == ring_filesize_cb)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(file_duration_cb), TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ring_filesize_cb), TRUE);
}
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ringbuffer_nbf_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_lb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ringbuffer_nbf_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ring_filesize_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_cbx),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ring_filesize_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(file_duration_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_cbx),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(file_duration_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_sb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_cbx), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_files_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_lb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_files_cb)));
} else {
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_sb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ringbuffer_nbf_lb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_sb),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ring_filesize_cbx),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_sb),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(file_duration_cbx),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_cb), TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_filesize_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_filesize_cbx),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_filesize_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_cb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_sb), FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(stop_files_lb), FALSE);
}
gtk_widget_set_sensitive(GTK_WIDGET(stop_packets_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_packets_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_packets_lb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_packets_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_duration_sb),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_duration_cb)));
gtk_widget_set_sensitive(GTK_WIDGET(stop_duration_cbx),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_duration_cb)));
}
gboolean capture_dlg_window_present(void)
{
return (cap_open_w?TRUE:FALSE);
}
void
refresh_local_interface_lists(void)
{
scan_local_interfaces(main_window_update);
if (interfaces_dialog_window_present())
refresh_if_window();
if (capture_dlg_window_present())
capture_dlg_refresh_if();
if (get_welcome_window() != NULL)
welcome_if_panel_reload();
tb80211_refresh_interfaces();
}
void
refresh_non_local_interface_lists(void)
{
if (capture_dlg_window_present())
capture_dlg_refresh_if();
if (get_welcome_window() != NULL)
welcome_if_panel_reload();
}
