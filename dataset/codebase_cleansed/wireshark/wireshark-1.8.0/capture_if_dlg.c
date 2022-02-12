void
add_interface(void)
{
if_dlg_data_t data;
data.device_lb = NULL;
data.descr_lb = NULL;
data.ip_lb = NULL;
data.curr_lb = NULL;
data.last_lb = NULL;
data.choose_bt = NULL;
#ifdef _WIN32
data.details_bt = NULL;
#endif
data.hidden = FALSE;
g_array_append_val(gtk_list, data);
refresh_if_window();
}
void
update_selected_interface(gchar *name)
{
guint i;
interface_t device;
if_dlg_data_t data;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
data = g_array_index(gtk_list, if_dlg_data_t, i);
if (strcmp(name, device.name) == 0) {
gtk_toggle_button_set_active((GtkToggleButton *)data.choose_bt, device.selected);
break;
}
}
}
static void
store_selected(GtkWidget *choose_bt, gpointer name)
{
interface_t device;
guint i;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
if (strcmp(name, device.if_info.name) == 0) {
if (!device.locked) {
device.selected ^= 1;
if (device.selected) {
global_capture_opts.num_selected++;
} else {
global_capture_opts.num_selected--;
}
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
if (gtk_widget_is_focus(choose_bt) && get_welcome_window()) {
change_interface_selection(device.name, device.selected);
}
if (gtk_widget_is_focus(choose_bt) && dlg_window_present()) {
enable_selected_interface(device.name, device.selected);
}
device.locked = FALSE;
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, i);
g_array_insert_val(global_capture_opts.all_ifaces, i, device);
}
break;
}
}
if (cap_if_w) {
gtk_widget_set_sensitive(capture_bt, !gbl_capture_in_progress && (global_capture_opts.num_selected > 0));
}
}
static void
capture_do_cb(GtkWidget *capture_bt _U_, gpointer if_data _U_)
{
if_dlg_data_t data;
guint ifs;
for (ifs = 0; ifs < gtk_list->len; ifs++) {
data = g_array_index(gtk_list, if_dlg_data_t, ifs);
if (data.hidden) {
continue;
}
gtk_widget_set_sensitive(data.choose_bt, FALSE);
gtk_list = g_array_remove_index(gtk_list, ifs);
g_array_insert_val(gtk_list, ifs, data);
#ifdef HAVE_AIRPCAP
airpcap_if_active = get_airpcap_if_from_name(airpcap_if_list, gtk_label_get_text(GTK_LABEL(data.device_lb)));
airpcap_if_selected = airpcap_if_active;
#endif
}
if (global_capture_opts.save_file) {
g_free(global_capture_opts.save_file);
global_capture_opts.save_file = NULL;
}
if (global_capture_opts.ifaces->len > 1) {
global_capture_opts.use_pcapng = TRUE;
}
window_destroy(cap_if_w);
capture_start_cb(NULL, NULL);
}
static void
capture_prepare_cb(GtkWidget *prepare_bt _U_, gpointer if_data _U_)
{
window_destroy(cap_if_w);
if (global_capture_opts.ifaces->len > 1) {
global_capture_opts.use_pcapng = TRUE;
}
capture_prep_cb(NULL, NULL);
}
static void
capture_details_cb(GtkWidget *details_bt _U_, gpointer name)
{
capture_if_details_open(name);
}
static void
update_if(gchar *name, if_stat_cache_t *sc)
{
struct pcap_stat stats;
gchar *str;
guint diff, ifs, data_ifs;
interface_t device;
if_dlg_data_t data;
gboolean found = FALSE;
device.last_packets = 0;
data.curr_lb = NULL;
data.last_lb = NULL;
if (sc) {
for (ifs = 0, data_ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
if (device.type != IF_PIPE) {
data = g_array_index(gtk_list, if_dlg_data_t, data_ifs++);
if (!device.hidden && strcmp(name, device.name) == 0) {
found = TRUE;
break;
}
}
}
if (found) {
if (capture_stats(sc, name, &stats)) {
if ((int)(stats.ps_recv - device.last_packets) < 0) {
diff = 0;
} else {
diff = stats.ps_recv - device.last_packets;
}
device.last_packets = stats.ps_recv;
str = g_strdup_printf("%u", device.last_packets);
gtk_label_set_text(GTK_LABEL(data.curr_lb), str);
g_free(str);
str = g_strdup_printf("%u", diff);
gtk_label_set_text(GTK_LABEL(data.last_lb), str);
g_free(str);
gtk_widget_set_sensitive(data.curr_lb, diff);
gtk_widget_set_sensitive(data.last_lb, diff);
} else {
gtk_label_set_text(GTK_LABEL(data.curr_lb), "error");
gtk_label_set_text(GTK_LABEL(data.last_lb), "error");
}
global_capture_opts.all_ifaces = g_array_remove_index(global_capture_opts.all_ifaces, ifs);
g_array_insert_val(global_capture_opts.all_ifaces, ifs, device);
gtk_list = g_array_remove_index(gtk_list, ifs);
g_array_insert_val(gtk_list, ifs, data);
}
}
}
static gboolean
update_all(gpointer data)
{
interface_t device;
guint ifs;
if_stat_cache_t *sc = data;
if (!cap_if_w) {
return FALSE;
}
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
update_if(device.name, sc);
}
return TRUE;
}
void
set_capture_if_dialog_for_capture_in_progress(gboolean capture_in_progress)
{
gbl_capture_in_progress = capture_in_progress;
if (cap_if_w) {
gtk_widget_set_sensitive(stop_bt, capture_in_progress);
gtk_widget_set_sensitive(capture_bt, !capture_in_progress && (global_capture_opts.num_selected > 0));
}
}
void
set_capture_if_dialog_for_capture_stopping(void)
{
if (cap_if_w) {
gtk_widget_set_sensitive(stop_bt, FALSE);
}
}
static void
capture_if_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
g_source_remove(timer_id);
free_interface_list(if_list);
if (sc)
capture_stat_stop(sc);
window_destroy(GTK_WIDGET(cap_if_w));
cap_if_w = NULL;
#ifdef HAVE_AIRPCAP
if (airpcap_if_active)
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
}
gint if_list_comparator_alph (const void *first_arg, const void *second_arg){
const if_info_t *first = first_arg, *second = second_arg;
if (first != NULL && first->description != NULL &&
second != NULL && second->description != NULL) {
return g_ascii_strcasecmp(first->description, second->description);
} else {
return 0;
}
}
GtkWidget * capture_get_if_icon(interface_t *device)
{
#ifdef HAVE_PCAP_REMOTE
if (!device->local) {
return pixbuf_to_widget(remote_sat_pb_data);
}
#endif
switch (device->type) {
#ifdef _WIN32
case IF_DIALUP:
return xpm_to_widget(modem_16_xpm);
#endif
case IF_WIRELESS:
return pixbuf_to_widget(network_wireless_pb_data);
#ifdef HAVE_AIRPCAP
case IF_AIRPCAP:
return xpm_to_widget(capture_airpcap_16_xpm);
#endif
case IF_BLUETOOTH:
return pixbuf_to_widget(network_bluetooth_pb_data);
case IF_USB:
return pixbuf_to_widget(network_usb_pb_data);
case IF_VIRTUAL:
return xpm_to_widget(network_virtual_16_xpm);
case IF_WIRED:
return pixbuf_to_widget(network_wired_pb_data);
case IF_PIPE:
case IF_STDIN:
return pixbuf_to_widget(pipe_pb_data);
default:
printf("unknown device type\n");
}
return pixbuf_to_widget(network_wired_pb_data);
}
static int
get_ip_addr_count(GSList *addr_list)
{
GSList *curr_addr;
if_addr_t *addr;
int count;
count = 0;
for (curr_addr = addr_list; curr_addr != NULL;
curr_addr = g_slist_next(curr_addr)) {
addr = (if_addr_t *)curr_addr->data;
switch (addr->ifat_type) {
case IF_AT_IPv4:
case IF_AT_IPv6:
count++;
break;
default:
break;
}
}
return count;
}
static const gchar *
set_ip_addr_label(GSList *addr_list, GtkWidget *ip_lb, guint selected_ip_addr)
{
GSList *curr_addr;
if_addr_t *addr;
const gchar *addr_str = NULL;
curr_addr = g_slist_nth(addr_list, selected_ip_addr);
if (curr_addr) {
addr = (if_addr_t *)curr_addr->data;
switch (addr->ifat_type) {
case IF_AT_IPv4:
addr_str = ip_to_str((guint8 *)&addr->addr.ip4_addr);
break;
case IF_AT_IPv6:
addr_str = ip6_to_str((struct e_in6_addr *)&addr->addr.ip6_addr);
break;
default:
break;
}
}
if (addr_str) {
gtk_label_set_text(GTK_LABEL(ip_lb), addr_str);
} else {
gtk_label_set_text(GTK_LABEL(ip_lb), "none");
}
g_object_set_data(G_OBJECT(ip_lb), CAPTURE_IF_SELECTED_IP_ADDR, GINT_TO_POINTER(selected_ip_addr));
return addr_str;
}
static gboolean
ip_label_enter_cb(GtkWidget *eb, GdkEventCrossing *event _U_, gpointer user_data _U_)
{
gtk_widget_set_state(eb, GTK_STATE_PRELIGHT);
return FALSE;
}
static gboolean
ip_label_leave_cb(GtkWidget *eb, GdkEvent *event _U_, gpointer user_data _U_)
{
gtk_widget_set_state(eb, GTK_STATE_NORMAL);
return FALSE;
}
static gboolean
ip_label_press_cb(GtkWidget *widget, GdkEvent *event _U_, gpointer data)
{
GtkWidget *ip_lb = (GtkWidget *)g_object_get_data(G_OBJECT(widget), CAPTURE_IF_IP_ADDR_LABEL);
GSList *addr_list = (GSList *)data;
GSList *curr_addr, *start_addr;
if_addr_t *addr;
guint selected_ip_addr = GPOINTER_TO_UINT(g_object_get_data(G_OBJECT(ip_lb), CAPTURE_IF_SELECTED_IP_ADDR));
start_addr = g_slist_nth(addr_list, selected_ip_addr);
for (;;) {
selected_ip_addr++;
if (g_slist_length(addr_list) <= selected_ip_addr) {
selected_ip_addr = 0;
}
curr_addr = g_slist_nth(addr_list, selected_ip_addr);
if (curr_addr == start_addr) {
break;
}
addr = (if_addr_t *)curr_addr->data;
switch (addr->ifat_type) {
case IF_AT_IPv4:
case IF_AT_IPv6:
goto found;
default:
break;
}
}
found:
set_ip_addr_label(addr_list, ip_lb, selected_ip_addr);
return FALSE;
}
static void
capture_if_stop_cb(GtkWidget *w _U_, gpointer d _U_)
{
guint ifs;
if_dlg_data_t data;
for (ifs = 0; ifs < gtk_list->len; ifs++) {
data = g_array_index(gtk_list, if_dlg_data_t, ifs);
if (data.hidden) {
continue;
}
gtk_widget_set_sensitive(data.choose_bt, TRUE);
gtk_list = g_array_remove_index(gtk_list, ifs);
g_array_insert_val(gtk_list, ifs, data);
}
capture_stop_cb(NULL, NULL);
}
static void
make_gtk_array(void)
{
if_dlg_data_t data;
guint i;
gtk_list = g_array_new(FALSE, FALSE, sizeof(if_dlg_data_t));
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
data.device_lb = NULL;
data.descr_lb = NULL;
data.ip_lb = NULL;
data.curr_lb = NULL;
data.last_lb = NULL;
data.choose_bt = NULL;
#ifdef _WIN32
data.details_bt = NULL;
#endif
data.hidden = FALSE;
g_array_append_val(gtk_list, data);
}
}
void
capture_if_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *top_vb,
*if_vb,
*if_sw,
*bbox,
*close_bt,
*help_bt;
#ifdef HAVE_AIRPCAP
GtkWidget *decryption_cb;
#endif
GtkWidget *if_tb, *icon;
GtkWidget *if_lb;
GtkWidget *eb;
GtkRequisition requisition;
int row, height;
guint ifs;
interface_t device;
GString *if_tool_str = g_string_new("");
const gchar *addr_str;
gchar *user_descr;
if_dlg_data_t data;
if (cap_if_w != NULL) {
reactivate_window(cap_if_w);
return;
}
if (global_capture_opts.all_ifaces->len == 0) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"There are no interfaces on which a capture can be done.");
return;
}
#ifdef _WIN32
if (!has_wpcap) {
char *detailed_err;
detailed_err = cant_load_winpcap_err("Wireshark");
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", detailed_err);
g_free(detailed_err);
return;
}
#endif
#ifdef HAVE_AIRPCAP
decryption_cb = g_object_get_data(G_OBJECT(airpcap_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY);
update_decryption_mode_list(decryption_cb);
if (airpcap_if_active == NULL) {
if (airpcap_if_list == NULL) {
airpcap_enable_toolbar_widgets(airpcap_tb,FALSE);
} else {
if (airpcap_if_active)
airpcap_set_toolbar_stop_capture(airpcap_if_active);
airpcap_enable_toolbar_widgets(airpcap_tb,FALSE);
}
}
if (airpcap_if_active)
airpcap_set_toolbar_start_capture(airpcap_if_active);
#endif
make_gtk_array();
cap_if_w = dlg_window_new("Wireshark: Capture Interfaces");
gtk_window_set_destroy_with_parent (GTK_WINDOW(cap_if_w), TRUE);
top_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(cap_if_w), top_vb);
if_sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(if_sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_box_pack_start(GTK_BOX(top_vb), if_sw, TRUE, TRUE, 0);
if_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(if_vb), 5);
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(if_sw), if_vb);
if_tb = gtk_table_new(1,9, FALSE);
gtk_table_set_row_spacings(GTK_TABLE(if_tb), 3);
gtk_table_set_col_spacings(GTK_TABLE(if_tb), 3);
gtk_box_pack_start(GTK_BOX(if_vb), if_tb, FALSE, FALSE, 0);
row = 0;
height = 0;
if_lb = gtk_label_new("");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 0, 1, row, row+1);
#ifndef _WIN32
if_lb = gtk_label_new("Device");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 1, 4, row, row+1);
#endif
if_lb = gtk_label_new("Description");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 4, 5, row, row+1);
if_lb = gtk_label_new(" IP ");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 5, 6, row, row+1);
if_lb = gtk_label_new("Packets");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 6, 7, row, row+1);
if_lb = gtk_label_new(" Packets/s ");
gtk_table_attach_defaults(GTK_TABLE(if_tb), if_lb, 7, 8, row, row+1);
row++;
height += 30;
sc = capture_stat_start(&global_capture_opts);
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
data = g_array_index(gtk_list, if_dlg_data_t, ifs);
g_string_assign(if_tool_str, "");
if (device.hidden) {
data.hidden = TRUE;
gtk_list = g_array_remove_index(gtk_list, ifs);
g_array_insert_val(gtk_list, ifs, data);
continue;
}
data.choose_bt = gtk_check_button_new();
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.choose_bt, 0, 1, row, row+1);
if (gbl_capture_in_progress) {
gtk_widget_set_sensitive(data.choose_bt, FALSE);
} else {
gtk_widget_set_sensitive(data.choose_bt, TRUE);
}
gtk_toggle_button_set_active((GtkToggleButton *)data.choose_bt, device.selected);
g_signal_connect(data.choose_bt, "toggled", G_CALLBACK(store_selected), device.name);
icon = capture_get_if_icon(&(device));
gtk_table_attach_defaults(GTK_TABLE(if_tb), icon, 1, 2, row, row+1);
data.device_lb = gtk_label_new(device.name);
#ifndef _WIN32
gtk_misc_set_alignment(GTK_MISC(data.device_lb), 0.0f, 0.5f);
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.device_lb, 2, 4, row, row+1);
#endif
g_string_append(if_tool_str, "Device: ");
g_string_append(if_tool_str, device.name);
g_string_append(if_tool_str, "\n");
user_descr = capture_dev_user_descr_find(device.name);
if (user_descr) {
data.descr_lb = gtk_label_new(user_descr);
g_free (user_descr);
} else {
if (device.if_info.description)
data.descr_lb = gtk_label_new(device.if_info.description);
else
data.descr_lb = gtk_label_new("");
}
gtk_misc_set_alignment(GTK_MISC(data.descr_lb), 0.0f, 0.5f);
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.descr_lb, 4, 5, row, row+1);
if (device.if_info.description) {
g_string_append(if_tool_str, "Description: ");
g_string_append(if_tool_str, device.if_info.description);
g_string_append(if_tool_str, "\n");
}
g_string_append(if_tool_str, "IP: ");
data.ip_lb = gtk_label_new("");
addr_str = set_ip_addr_label (device.if_info.addrs, data.ip_lb, 0);
if (addr_str) {
gtk_widget_set_sensitive(data.ip_lb, TRUE);
g_string_append(if_tool_str, addr_str);
} else {
gtk_widget_set_sensitive(data.ip_lb, FALSE);
g_string_append(if_tool_str, "none");
}
eb = gtk_event_box_new ();
gtk_container_add(GTK_CONTAINER(eb), data.ip_lb);
gtk_table_attach_defaults(GTK_TABLE(if_tb), eb, 5, 6, row, row+1);
if (get_ip_addr_count(device.if_info.addrs) > 1) {
g_object_set_data(G_OBJECT(eb), CAPTURE_IF_IP_ADDR_LABEL, data.ip_lb);
g_signal_connect(eb, "enter-notify-event", G_CALLBACK(ip_label_enter_cb), NULL);
g_signal_connect(eb, "leave-notify-event", G_CALLBACK(ip_label_leave_cb), NULL);
g_signal_connect(eb, "button-press-event", G_CALLBACK(ip_label_press_cb), device.if_info.addrs);
}
g_string_append(if_tool_str, "\n");
data.curr_lb = gtk_label_new("-");
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.curr_lb, 6, 7, row, row+1);
data.last_lb = gtk_label_new("-");
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.last_lb, 7, 8, row, row+1);
#ifdef _WIN32
data.details_bt = gtk_button_new_from_stock(WIRESHARK_STOCK_CAPTURE_DETAILS);
gtk_widget_set_tooltip_text(data.details_bt, "Open the capture details dialog of this interface.");
gtk_table_attach_defaults(GTK_TABLE(if_tb), data.details_bt, 8, 9, row, row+1);
if (capture_if_has_details(device.name)) {
g_signal_connect(data.details_bt, "clicked", G_CALLBACK(capture_details_cb), device.name);
} else {
gtk_widget_set_sensitive(data.details_bt, FALSE);
}
#endif
gtk_list = g_array_remove_index(gtk_list, ifs);
g_array_insert_val(gtk_list, ifs, data);
row++;
if (row <= 20) {
gtk_widget_get_preferred_size(GTK_WIDGET(data.choose_bt), &requisition, NULL);
height += requisition.height;
}
}
g_string_free(if_tool_str, TRUE);
bbox = dlg_button_row_new(GTK_STOCK_HELP, WIRESHARK_STOCK_CAPTURE_START, WIRESHARK_STOCK_CAPTURE_OPTIONS, WIRESHARK_STOCK_CAPTURE_STOP, GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(top_vb), bbox, FALSE, FALSE, 5);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)(HELP_CAPTURE_INTERFACES_DIALOG));
stop_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CAPTURE_STOP);
g_signal_connect(stop_bt, "clicked", G_CALLBACK(capture_if_stop_cb), NULL);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(cap_if_w, close_bt, window_cancel_button_cb);
gtk_widget_set_tooltip_text(close_bt, "Close this window.");
options_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CAPTURE_OPTIONS);
g_signal_connect(options_bt, "clicked", G_CALLBACK(capture_prepare_cb), NULL);
capture_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CAPTURE_START);
g_signal_connect(capture_bt, "clicked", G_CALLBACK(capture_do_cb), NULL);
gtk_widget_get_preferred_size(GTK_WIDGET(close_bt), &requisition, NULL);
height += requisition.height + 40 + ifs;
gtk_window_set_default_size(GTK_WINDOW(cap_if_w), -1, height);
gtk_widget_grab_default(close_bt);
g_signal_connect(cap_if_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(cap_if_w, "destroy", G_CALLBACK(capture_if_destroy_cb), sc);
gtk_widget_show_all(cap_if_w);
window_present(cap_if_w);
set_capture_if_dialog_for_capture_in_progress(gbl_capture_in_progress);
timer_id = g_timeout_add(1000, update_all, sc);
}
gboolean interfaces_dialog_window_present(void)
{
return (cap_if_w?TRUE:FALSE);
}
void refresh_if_window(void)
{
destroy_if_window();
cap_if_w = NULL;
capture_if_cb(NULL, NULL);
}
void select_all_interfaces(gboolean enable _U_)
{
guint ifs;
interface_t device;
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
update_selected_interface(device.if_info.name);
}
}
void destroy_if_window(void)
{
if (cap_if_w) {
window_destroy(cap_if_w);
}
}
void
set_capture_if_dialog_for_capture_in_progress(gboolean capture_in_progress _U_)
{
}
