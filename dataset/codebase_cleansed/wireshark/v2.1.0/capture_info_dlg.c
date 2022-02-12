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
static void
capture_info_count_init(capture_info_counts_t* count, int idx, GtkWidget *percent_pb, gboolean show, GtkWidget *counts_grid)
{
count->label = gtk_label_new(count->title);
gtk_misc_set_alignment(GTK_MISC(count->label), 0.0f, 0.5f);
count->value_lb = gtk_label_new("0");
gtk_misc_set_alignment(GTK_MISC(count->value_lb), 0.5f, 0.5f);
count->percent_pb = percent_pb;
if (!show)
{
gtk_widget_set_size_request(count->percent_pb, 70, -1);
}
count->percent_lb = gtk_label_new("0.0%");
gtk_misc_set_alignment(GTK_MISC(count->percent_lb), 1.0f, 0.5f);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), count->label,
0, idx, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), count->value_lb,
1, idx, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), count->percent_pb,
2, idx, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
ws_gtk_grid_attach_extended(GTK_GRID(counts_grid), count->percent_lb,
3, idx, 1, 1, (GtkAttachOptions)(GTK_EXPAND|GTK_FILL), (GtkAttachOptions)0, 0, 0);
gtk_widget_show(count->label);
gtk_widget_show(count->value_lb);
gtk_widget_show(count->percent_pb);
if (show) {
gtk_widget_show(count->percent_lb);
}
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
GString *str;
info = g_new0(capture_info_ui_t,1);
info->total_count.title = "Total";
info->other_count.title = "Other";
info->counts[0].title = "SCTP";
info->counts[0].proto = proto_get_id_by_short_name(info->counts[0].title);
info->counts[1].title = "TCP";
info->counts[1].proto = proto_get_id_by_short_name(info->counts[1].title);
info->counts[2].title = "UDP";
info->counts[2].proto = proto_get_id_by_short_name(info->counts[2].title);
info->counts[3].title = "ICMP";
info->counts[3].proto = proto_get_id_by_short_name(info->counts[3].title);
info->counts[4].title = "ARP";
info->counts[4].proto = proto_get_id_by_short_name(info->counts[4].title);
info->counts[5].title = "OSPF";
info->counts[5].proto = proto_get_id_by_short_name(info->counts[5].title);
info->counts[6].title = "GRE";
info->counts[6].proto = proto_get_id_by_short_name(info->counts[6].title);
info->counts[7].title = "NetBIOS";
info->counts[7].proto = proto_get_id_by_short_name(info->counts[7].title);
info->counts[8].title = "IPX";
info->counts[8].proto = proto_get_id_by_short_name(info->counts[8].title);
info->counts[9].title = "VINES";
info->counts[9].proto = proto_get_id_by_short_name(info->counts[9].title);
info->counts[10].title = "I2C Events";
info->counts[10].proto = proto_get_id_by_short_name(info->counts[10].title);
info->counts[11].title = "I2C Data";
info->counts[11].proto = proto_get_id_by_short_name(info->counts[11].title);
str = get_iface_list_string(capture_opts, 0);
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
capture_info_count_init(&info->total_count, 0, gtk_label_new("% of total"), FALSE, counts_grid);
for (i = 0; i < PACKET_COUNTS_SIZE; i++) {
capture_info_count_init(&info->counts[i], i+1, gtk_progress_bar_new(), TRUE, counts_grid);
}
capture_info_count_init(&info->other_count, i+1, gtk_progress_bar_new(), TRUE, counts_grid);
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
static void
capture_info_count_update(capture_info_counts_t* count, capture_info *cinfo)
{
gchar label_str[64];
float pb_frac;
guint32 proto_count;
proto_count = capture_dissector_get_count(cinfo->counts, count->proto);
g_snprintf(label_str, sizeof(label_str), "%d", proto_count);
gtk_label_set_text(GTK_LABEL(count->value_lb), label_str);
pb_frac = (cinfo->counts->total != 0) ?
((float)proto_count / cinfo->counts->total) : 0.0f;
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(count->percent_pb), pb_frac);
g_snprintf(label_str, sizeof(label_str), "%.1f%%", pb_frac * 100.0);
gtk_label_set_text(GTK_LABEL(count->percent_lb), label_str);
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
g_snprintf(label_str, sizeof(label_str), "%d", cinfo->counts->total);
gtk_label_set_text(GTK_LABEL(info->total_count.value_lb), label_str);
for (i = 0; i < PACKET_COUNTS_SIZE; i++) {
capture_info_count_update(&info->counts[i], cinfo);
}
g_snprintf(label_str, sizeof(label_str), "%d", cinfo->counts->other);
gtk_label_set_text(GTK_LABEL(info->other_count.value_lb), label_str);
pb_frac = (cinfo->counts->total != 0) ?
((float)cinfo->counts->other / cinfo->counts->total) : 0.0f;
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(info->other_count.percent_pb), pb_frac);
g_snprintf(label_str, sizeof(label_str), "%.1f%%", pb_frac * 100.0);
gtk_label_set_text(GTK_LABEL(info->other_count.percent_lb), label_str);
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
