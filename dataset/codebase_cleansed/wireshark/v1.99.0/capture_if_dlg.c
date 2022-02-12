void
update_selected_interface(gchar *name)
{
guint i;
interface_t device;
if_dlg_data_t data;
for (i = 0; i < global_capture_opts.all_ifaces->len; i++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, i);
data = g_array_index(if_array, if_dlg_data_t, i);
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
if (strcmp((char *)name, device.if_info.name) == 0) {
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
if (gtk_widget_is_focus(choose_bt) && capture_dlg_window_present()) {
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
capture_do_cb(GtkWidget *capture_bt_arg _U_, gpointer if_data _U_)
{
if_dlg_data_t data;
guint ifs;
for (ifs = 0; ifs < if_array->len; ifs++) {
data = g_array_index(if_array, if_dlg_data_t, ifs);
if (data.hidden) {
continue;
}
gtk_widget_set_sensitive(data.choose_bt, FALSE);
if_array = g_array_remove_index(if_array, ifs);
g_array_insert_val(if_array, ifs, data);
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
update_if(gchar *name, if_stat_cache_t *sc_p)
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
if (sc_p) {
for (ifs = 0, data_ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
if (device.type != IF_PIPE) {
data = g_array_index(if_array, if_dlg_data_t, data_ifs++);
if (!device.hidden && strcmp(name, device.name) == 0) {
found = TRUE;
break;
}
}
}
if (found) {
if (capture_stats(sc_p, name, &stats)) {
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
if_array = g_array_remove_index(if_array, ifs);
g_array_insert_val(if_array, ifs, data);
}
}
}
static gboolean
update_all(gpointer data)
{
interface_t device;
guint ifs;
if_stat_cache_t *sc_p = (if_stat_cache_t *)data;
if (!cap_if_w) {
return FALSE;
}
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
update_if(device.name, sc_p);
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
if (sc) {
capture_stat_stop(sc);
sc = NULL;
}
window_destroy(GTK_WIDGET(cap_if_w));
cap_if_w = NULL;
cap_if_top_vb = NULL;
cap_if_sw = NULL;
#ifdef HAVE_AIRPCAP
if (airpcap_if_active)
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
}
GtkWidget * capture_get_if_icon(interface_t *device)
{
#ifdef HAVE_PCAP_REMOTE
if (!device->local) {
return pixbuf_to_widget(remote_sat_pb_data);
}
#endif
if (device->display_name && strstr(device->display_name,"Wi-Fi") != NULL) {
return pixbuf_to_widget(network_wireless_pb_data);
}
switch (device->type) {
case IF_DIALUP:
return xpm_to_widget(modem_16_xpm);
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
#ifdef HAVE_EXTCAP
case IF_EXTCAP:
#endif
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
for (ifs = 0; ifs < if_array->len; ifs++) {
data = g_array_index(if_array, if_dlg_data_t, ifs);
if (data.hidden) {
continue;
}
gtk_widget_set_sensitive(data.choose_bt, TRUE);
if_array = g_array_remove_index(if_array, ifs);
g_array_insert_val(if_array, ifs, data);
}
capture_stop_cb(NULL, NULL);
}
static void
make_if_array(void)
{
if_dlg_data_t data;
guint i;
if_array = g_array_new(FALSE, FALSE, sizeof(if_dlg_data_t));
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
g_array_append_val(if_array, data);
}
}
static gboolean
can_capture(void)
{
#ifdef _WIN32
if (!has_wpcap) {
char *detailed_err;
detailed_err = cant_load_winpcap_err("Wireshark");
simple_error_message_box("%s", detailed_err);
g_free(detailed_err);
return FALSE;
}
#endif
if (global_capture_opts.all_ifaces->len == 0) {
simple_error_message_box("There are no interfaces on which a capture can be done.");
return FALSE;
}
return TRUE;
}
static void
capture_if_refresh_if_list(void)
{
GtkWidget *if_vb, *if_grid, *icon, *if_lb, *eb;
GtkRequisition requisition;
int row = 0, height = 0;
guint ifs;
interface_t device;
const gchar *addr_str;
gchar *user_descr;
if_dlg_data_t data;
if (!can_capture()) {
destroy_if_window();
return;
}
if (cap_if_sw) {
gtk_container_remove(GTK_CONTAINER(cap_if_top_vb), cap_if_sw);
capture_stat_stop(sc);
g_source_remove(timer_id);
}
make_if_array();
cap_if_sw = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(cap_if_sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
gtk_box_pack_start(GTK_BOX(cap_if_top_vb), cap_if_sw, TRUE, TRUE, 0);
if_vb = gtk_alignment_new(0.0F, 0.0F, 1.0F, 0.0F);
gtk_container_set_border_width(GTK_CONTAINER(if_vb), 5);
#if ! GTK_CHECK_VERSION(3,8,0)
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(cap_if_sw), if_vb);
#else
gtk_container_add(GTK_CONTAINER(cap_if_sw), if_vb);
#endif
if_grid = ws_gtk_grid_new();
ws_gtk_grid_set_row_spacing(GTK_GRID(if_grid), 3);
ws_gtk_grid_set_column_spacing(GTK_GRID(if_grid), 3);
gtk_container_add(GTK_CONTAINER(if_vb), if_grid);
if_lb = gtk_label_new("");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), if_lb, 0, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
if_lb = gtk_label_new("Device");
ws_gtk_grid_attach_defaults(GTK_GRID(if_grid), if_lb, 1, row, 3, 1);
if_lb = gtk_label_new("Description");
ws_gtk_grid_attach_defaults(GTK_GRID(if_grid), if_lb, 4, row, 1, 1);
if_lb = gtk_label_new(" IP ");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), if_lb, 5, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
if_lb = gtk_label_new("Packets");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), if_lb, 6, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
if_lb = gtk_label_new(" Packets/s ");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), if_lb, 7, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
row++;
height += 30;
sc = capture_stat_start(&global_capture_opts);
for (ifs = 0; ifs < global_capture_opts.all_ifaces->len; ifs++) {
device = g_array_index(global_capture_opts.all_ifaces, interface_t, ifs);
data = g_array_index(if_array, if_dlg_data_t, ifs);
if (device.hidden) {
data.hidden = TRUE;
if_array = g_array_remove_index(if_array, ifs);
g_array_insert_val(if_array, ifs, data);
continue;
}
data.choose_bt = gtk_check_button_new();
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), data.choose_bt, 0, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
if (gbl_capture_in_progress) {
gtk_widget_set_sensitive(data.choose_bt, FALSE);
} else {
gtk_widget_set_sensitive(data.choose_bt, TRUE);
}
gtk_toggle_button_set_active((GtkToggleButton *)data.choose_bt, device.selected);
g_signal_connect(data.choose_bt, "toggled", G_CALLBACK(store_selected), device.name);
icon = capture_get_if_icon(&(device));
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), icon, 1, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
#ifdef _WIN32
data.device_lb = gtk_label_new(device.display_name);
#else
data.device_lb = gtk_label_new(device.name);
#endif
gtk_misc_set_alignment(GTK_MISC(data.device_lb), 0.0f, 0.5f);
if (strlen(gtk_label_get_text(GTK_LABEL(data.device_lb))) > SOFT_LABEL_LEN) {
gtk_label_set_ellipsize(GTK_LABEL(data.device_lb), PANGO_ELLIPSIZE_MIDDLE);
gtk_label_set_width_chars(GTK_LABEL(data.device_lb), SOFT_LABEL_LEN);
}
ws_gtk_grid_attach_defaults(GTK_GRID(if_grid), data.device_lb, 2, row, 2, 1);
user_descr = capture_dev_user_descr_find(device.name);
if (user_descr) {
data.descr_lb = gtk_label_new(user_descr);
g_free (user_descr);
} else {
if (device.if_info.vendor_description)
data.descr_lb = gtk_label_new(device.if_info.vendor_description);
else
data.descr_lb = gtk_label_new("");
}
gtk_misc_set_alignment(GTK_MISC(data.descr_lb), 0.0f, 0.5f);
if (strlen(gtk_label_get_text(GTK_LABEL(data.descr_lb))) > SOFT_LABEL_LEN) {
gtk_label_set_ellipsize(GTK_LABEL(data.descr_lb), PANGO_ELLIPSIZE_MIDDLE);
gtk_label_set_width_chars(GTK_LABEL(data.descr_lb), SOFT_LABEL_LEN);
}
ws_gtk_grid_attach_defaults(GTK_GRID(if_grid), data.descr_lb, 4, row, 1, 1);
data.ip_lb = gtk_label_new("");
addr_str = set_ip_addr_label (device.if_info.addrs, data.ip_lb, 0);
if (addr_str) {
gtk_widget_set_sensitive(data.ip_lb, TRUE);
} else {
gtk_widget_set_sensitive(data.ip_lb, FALSE);
}
eb = gtk_event_box_new ();
gtk_container_add(GTK_CONTAINER(eb), data.ip_lb);
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), eb, 5, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
if (get_ip_addr_count(device.if_info.addrs) > 1) {
g_object_set_data(G_OBJECT(eb), CAPTURE_IF_IP_ADDR_LABEL, data.ip_lb);
gtk_widget_set_tooltip_text(eb, "Click to see additional IP addresses");
g_signal_connect(eb, "enter-notify-event", G_CALLBACK(ip_label_enter_cb), NULL);
g_signal_connect(eb, "leave-notify-event", G_CALLBACK(ip_label_leave_cb), NULL);
g_signal_connect(eb, "button-press-event", G_CALLBACK(ip_label_press_cb), device.if_info.addrs);
}
data.curr_lb = gtk_label_new("-");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), data.curr_lb, 6, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
data.last_lb = gtk_label_new("-");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), data.last_lb, 7, row, 1, 1,
(GtkAttachOptions)0, (GtkAttachOptions)0, 0, 0);
#ifdef _WIN32
data.details_bt = ws_gtk_button_new_from_stock(WIRESHARK_STOCK_CAPTURE_DETAILS);
gtk_widget_set_tooltip_text(data.details_bt, "Open the capture details dialog of this interface.");
ws_gtk_grid_attach_extended(GTK_GRID(if_grid), data.details_bt, 8, row, 1, 1, 0, 0, 0, 0);
if (capture_if_has_details(device.name)) {
g_signal_connect(data.details_bt, "clicked", G_CALLBACK(capture_details_cb), device.name);
} else {
gtk_widget_set_sensitive(data.details_bt, FALSE);
}
#endif
if_array = g_array_remove_index(if_array, ifs);
g_array_insert_val(if_array, ifs, data);
row++;
if (row <= 20) {
#ifdef _WIN32
gtk_widget_get_preferred_size(GTK_WIDGET(data.details_bt), &requisition, NULL);
#else
gtk_widget_get_preferred_size(GTK_WIDGET(data.choose_bt), &requisition, NULL);
#endif
height += requisition.height;
}
}
gtk_widget_get_preferred_size(GTK_WIDGET(close_bt), &requisition, NULL);
height += requisition.height + 40 + (row * 3);
gtk_window_set_default_size(GTK_WINDOW(cap_if_w), -1, height);
gtk_widget_show_all(cap_if_w);
timer_id = g_timeout_add(1000, update_all, sc);
}
void
capture_if_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *bbox,
*help_bt;
#ifdef HAVE_AIRPCAP
GtkWidget *decryption_cb;
#endif
if (cap_if_w != NULL) {
reactivate_window(cap_if_w);
return;
}
if (!can_capture()) {
return;
}
#ifdef HAVE_AIRPCAP
if (airpcap_if_active == NULL) {
if (airpcap_if_list == NULL) {
airpcap_enable_toolbar_widgets(wireless_tb,FALSE);
} else {
if (airpcap_if_active){
airpcap_set_toolbar_stop_capture(airpcap_if_active);
}
airpcap_enable_toolbar_widgets(wireless_tb,FALSE);
}
}
if (airpcap_if_active){
decryption_cb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY);
update_decryption_mode_list(decryption_cb);
airpcap_set_toolbar_start_capture(airpcap_if_active);
}
#endif
cap_if_w = dlg_window_new("Wireshark: Capture Interfaces");
gtk_window_set_destroy_with_parent (GTK_WINDOW(cap_if_w), TRUE);
cap_if_top_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, DLG_UNRELATED_SPACING, FALSE);
gtk_container_add(GTK_CONTAINER(cap_if_w), cap_if_top_vb);
gtk_container_set_border_width(GTK_CONTAINER(cap_if_top_vb), DLG_OUTER_MARGIN);
bbox = dlg_button_row_new(GTK_STOCK_HELP, WIRESHARK_STOCK_CAPTURE_START, WIRESHARK_STOCK_CAPTURE_OPTIONS, WIRESHARK_STOCK_CAPTURE_STOP, GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(cap_if_top_vb), bbox, FALSE, FALSE, 0);
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
gtk_widget_grab_default(close_bt);
g_signal_connect(cap_if_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(cap_if_w, "destroy", G_CALLBACK(capture_if_destroy_cb), sc);
capture_if_refresh_if_list();
window_present(cap_if_w);
set_capture_if_dialog_for_capture_in_progress(gbl_capture_in_progress);
}
gboolean interfaces_dialog_window_present(void)
{
return (cap_if_w?TRUE:FALSE);
}
void refresh_if_window(void)
{
if (cap_if_w) {
capture_if_refresh_if_list();
}
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
