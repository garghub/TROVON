static void
capture_info_stop(capture_options *capture_opts)
{
#ifdef HAVE_AIRPCAP
airpcap_set_toolbar_stop_capture(airpcap_if_active);
#endif
capture_stop(capture_opts);
}
static gboolean
capture_info_delete_cb(GtkWidget *w _U_, GdkEvent *event _U_, gpointer data) {
capture_info_stop(data);
return TRUE;
}
static void
capture_info_stop_clicked_cb(GtkButton *w _U_, gpointer data) {
capture_info_stop(data);
}
static gboolean
capture_info_ui_update_cb(gpointer data)
{
capture_info *cinfo = data;
capture_info_ui_t *info = cinfo->ui;
if (!info)
return TRUE;
cinfo->running_time = time(NULL) - info->start_time;
capture_info_ui_update(cinfo);
return TRUE;
}
void capture_info_ui_update(
capture_info *cinfo)
{
unsigned int i;
gchar label_str[64];
capture_info_ui_t *info = cinfo->ui;
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
capture_info_ui_t *info = cinfo->ui;
if (!info)
return;
g_source_remove(info->timer_id);
gtk_grab_remove(GTK_WIDGET(info->cap_w));
window_destroy(GTK_WIDGET(info->cap_w));
g_free(info);
cinfo->ui = NULL;
}
