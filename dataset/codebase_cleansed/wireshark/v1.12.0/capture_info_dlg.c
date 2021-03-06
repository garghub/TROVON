static void
capture_info_stop(capture_session *cap_session)
{
#ifdef HAVE_AIRPCAP
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
capture_stop(cap_session);
}
static gboolean
capture_info_delete_cb(GtkWidget *w _U_, GdkEvent *event _U_, gpointer data) {
capture_info_stop((capture_session *)data);
return TRUE;
}
static void
capture_info_stop_clicked_cb(GtkButton *w _U_, gpointer data) {
capture_info_stop((capture_session *)data);
}
static gboolean
capture_info_ui_update_cb(gpointer data)
{
capture_info *cinfo = (capture_info *)data;
capture_info_ui_t *info = (capture_info_ui_t *)cinfo->ui;
if (!info)
return TRUE;
cinfo->running_time = time(NULL) - info->start_time;
capture_info_ui_update(cinfo);
return TRUE;
}
void
capture_info_ui_create(capture_info *cinfo, capture_session *cap_session)
{
capture_options *capture_opts = cap_session->capture_opts;
unsigned int i;
GtkWidget *main_vb, *stop_bt, *counts_grid;
GtkWidget *counts_fr, *running_grid, *running_label, *lb, *bbox, *ci_help;
capture_info_ui_t *info;
gchar *cap_w_title;
gchar *title_iface;
gchar *descr;
GString *str;
info = g_new0(capture_info_ui_t,1);
info->counts[0].title = "Total";
info->counts[0].value_ptr = &(cinfo->counts->total);
info->counts[1].title = "SCTP";
info->counts[1].value_ptr = &(cinfo->counts->sctp);
info->counts[2].title = "TCP";
info->counts[2].value_ptr = &(cinfo->counts->tcp);
info->counts[3].title = "UDP";
info->counts[3].value_ptr = &(cinfo->counts->udp);
info->counts[4].title = "ICMP";
info->counts[4].value_ptr = &(cinfo->counts->icmp);
info->counts[5].title = "ARP";
info->counts[5].value_ptr = &(cinfo->counts->arp);
info->counts[6].title = "OSPF";
info->counts[6].value_ptr = &(cinfo->counts->ospf);
info->counts[7].title = "GRE";
info->counts[7].value_ptr = &(cinfo->counts->gre);
info->counts[8].title = "NetBIOS";
info->counts[8].value_ptr = &(cinfo->counts->netbios);
info->counts[9].title = "IPX";
info->counts[9].value_ptr = &(cinfo->counts->ipx);
info->counts[10].title = "VINES";
info->counts[10].value_ptr = &(cinfo->counts->vines);
info->counts[11].title = "Other";
info->counts[11].value_ptr = &(cinfo->counts->other);
info->counts[12].title = "I2C Events";
info->counts[12].value_ptr = &(cinfo->counts->i2c_event);
info->counts[13].title = "I2C Data";
info->counts[13].value_ptr = &(cinfo->counts->i2c_data);
str = g_string_new("");
#ifdef _WIN32
if (capture_opts->ifaces->len < 2)
#else
if (capture_opts->ifaces->len < 4)
#endif
{
for (i = 0; i < capture_opts->ifaces->len; i++) {
interface_options interface_opts;
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
descr = get_interface_descriptive_name(interface_opts.name);
if (i > 0) {
if (capture_opts->ifaces->len > 2) {
g_string_append_printf(str, ",");
}
g_string_append_printf(str, " ");
if (i == capture_opts->ifaces->len - 1) {
g_string_append_printf(str, "and ");
}
}
g_string_append_printf(str, "%s", descr);
g_free(descr);
}
} else {
g_string_append_printf(str, "%u interfaces", capture_opts->ifaces->len);
}
title_iface = g_strdup_printf("Wireshark: Capture from %s", str->str);
g_string_free(str, TRUE);
cap_w_title = create_user_window_title(title_iface);
g_free(title_iface);
info->cap_w = dlg_window_new(cap_w_title);
g_free(cap_w_title);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 1, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(info->cap_w), main_vb);
gtk_widget_show(main_vb);
counts_fr = gtk_frame_new("Captured Packets");
gtk_box_pack_start(GTK_BOX(main_vb), counts_fr, FALSE, FALSE, 3);
gtk_widget_show(counts_fr);
counts_grid = ws_gtk_grid_new();
ws_gtk_grid_set_homogeneous(GTK_GRID(counts_grid), TRUE);
gtk_container_add(GTK_CONTAINER(counts_fr), counts_grid);
gtk_container_set_border_width(GTK_CONTAINER(counts_grid), 5);
gtk_widget_show(counts_grid);
ws_gtk_grid_set_row_spacing(GTK_GRID(counts_grid), 0);
ws_gtk_grid_set_column_spacing(GTK_GRID(counts_grid), 5);
for (i = 0; i < PACKET_COUNTS_SIZE; i++) {
info->counts[i].label = gtk_label_new(info->counts[i].title);
gtk_misc_set_alignment(GTK_MISC(info->counts[i].label), 0.0f, 0.5f);
info->counts[i].value_lb = gtk_label_new("0");
gtk_misc_set_alignment(GTK_MISC(info->counts[i].value_lb), 0.5f, 0.5f);
if (i == 0) {
info->counts[i].percent_pb = gtk_label_new("% of total");
} else {
info->counts[i].percent_pb = gtk_progress_bar_new();
gtk_widget_set_size_request(info->counts[i].percent_pb, 70, -1);
}
info->counts[i].percent_lb = gtk_label_new("0.0%");
gtk_misc_set_alignment(GTK_MISC(info->counts[i].percent_lb), 1.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), info->counts[i].label,
0, i, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), info->counts[i].value_lb,
1, i, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), info->counts[i].percent_pb,
2, i, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), info->counts[i].percent_lb,
3, i, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_show(info->counts[i].label);
gtk_widget_show(info->counts[i].value_lb);
gtk_widget_show(info->counts[i].percent_pb);
if (i != 0) {
gtk_widget_show(info->counts[i].percent_lb);
}
}
running_grid = ws_gtk_grid_new();
ws_gtk_grid_set_homogeneous(GTK_GRID(running_grid), TRUE);
running_label = gtk_label_new("Running");
gtk_misc_set_alignment(GTK_MISC(running_label), 0.0f, 0.0f);
gtk_widget_show(running_label);
ws_gtk_grid_attach_extended(GTK_GRID(running_grid), running_label,
0, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
info->running_time_lb = gtk_label_new("00:00:00");
gtk_misc_set_alignment(GTK_MISC(info->running_time_lb), 0.5f, 0.0f);
gtk_widget_show(info->running_time_lb);
ws_gtk_grid_attach_extended(GTK_GRID(running_grid), info->running_time_lb,
1, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 5, 0);
lb = gtk_label_new("");
gtk_widget_show(lb);
ws_gtk_grid_attach_extended(GTK_GRID(running_grid), lb,
2, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
lb = gtk_label_new("");
gtk_widget_show(lb);
ws_gtk_grid_attach_extended(GTK_GRID(running_grid), lb,
3, 0, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_box_pack_start(GTK_BOX(main_vb), running_grid, FALSE, FALSE, 3);
gtk_widget_show(running_grid);
bbox = dlg_button_row_new(WIRESHARK_STOCK_CAPTURE_STOP, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE, FALSE, 3);
gtk_widget_show(bbox);
stop_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CAPTURE_STOP);
window_set_cancel_button(info->cap_w, stop_bt, NULL);
g_signal_connect(stop_bt, "clicked", G_CALLBACK(capture_info_stop_clicked_cb), cap_session);
g_signal_connect(info->cap_w, "delete_event", G_CALLBACK(capture_info_delete_cb), cap_session);
ci_help = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
gtk_widget_set_tooltip_text(ci_help, "Get help about this dialog");
g_signal_connect(ci_help, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_CAPTURE_INFO_DIALOG);
gtk_widget_show(info->cap_w);
window_present(info->cap_w);
info->start_time = time(NULL);
cinfo->ui = info;
info->timer_id = g_timeout_add(1000, capture_info_ui_update_cb,cinfo);
}
void capture_info_ui_update(
capture_info *cinfo)
{
unsigned int i;
gchar label_str[64];
capture_info_ui_t *info = (capture_info_ui_t *)cinfo->ui;
if (!info)
return;
g_snprintf(label_str, sizeof(label_str), "%02ld:%02ld:%02ld",
(long)(cinfo->running_time/3600), (long)((cinfo->running_time%3600)/60),
(long)(cinfo->running_time%60));
gtk_label_set_text(GTK_LABEL(info->running_time_lb), label_str);
if (cinfo->new_packets) {
float pb_frac;
for (i = 0; i < PACKET_COUNTS_SIZE; i++) {
g_snprintf(label_str, sizeof(label_str), "%d", *info->counts[i].value_ptr);
gtk_label_set_text(GTK_LABEL(info->counts[i].value_lb), label_str);
pb_frac = (*info->counts[0].value_ptr != 0) ?
((float)*info->counts[i].value_ptr / *info->counts[0].value_ptr) : 0.0f;
if (i != 0) {
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(info->counts[i].percent_pb), pb_frac);
g_snprintf(label_str, sizeof(label_str), "%.1f%%", pb_frac * 100.0);
gtk_label_set_text(GTK_LABEL(info->counts[i].percent_lb), label_str);
}
}
}
}
void capture_info_ui_destroy(
capture_info *cinfo)
{
capture_info_ui_t *info = (capture_info_ui_t *)cinfo->ui;
if (!info)
return;
g_source_remove(info->timer_id);
gtk_grab_remove(GTK_WIDGET(info->cap_w));
window_destroy(GTK_WIDGET(info->cap_w));
g_free(info);
cinfo->ui = NULL;
}
