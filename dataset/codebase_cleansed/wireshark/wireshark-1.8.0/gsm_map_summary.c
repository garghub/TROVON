static void
add_string_to_box(gchar *str, GtkWidget *box)
{
GtkWidget *lb;
lb = gtk_label_new(str);
gtk_misc_set_alignment(GTK_MISC(lb), 0.0f, 0.5f);
gtk_box_pack_start(GTK_BOX(box), lb,FALSE,FALSE, 0);
gtk_widget_show(lb);
}
void gsm_map_stat_gtk_sum_cb(GtkAction *action _U_, gpointer user_data _U_)
{
summary_tally summary;
GtkWidget *sum_open_w,
*main_vb, *file_fr, *data_fr, *file_box,
*data_box, *bbox, *close_bt,
*invoke_fr, *invoke_box,
*rr_fr, *rr_box,
*tot_fr, *tot_box;
gchar string_buff[SUM_STR_MAX];
double seconds;
int i;
int tot_invokes, tot_rr;
double tot_invokes_size, tot_rr_size;
summary_fill_in(&cfile, &summary);
seconds = summary.stop_time - summary.start_time;
sum_open_w = dlg_window_new("GSM MAP Statistics: Summary");
gtk_window_set_destroy_with_parent (GTK_WINDOW(sum_open_w), TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 5);
gtk_container_add(GTK_CONTAINER(sum_open_w), main_vb);
gtk_widget_show(main_vb);
file_fr = gtk_frame_new("File");
gtk_container_add(GTK_CONTAINER(main_vb), file_fr);
gtk_widget_show(file_fr);
file_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(file_fr), file_box);
gtk_widget_show(file_box);
g_snprintf(string_buff, SUM_STR_MAX, "Name: %s", ((summary.filename) ? summary.filename : "None"));
add_string_to_box(string_buff, file_box);
g_snprintf(string_buff, SUM_STR_MAX, "Length: %" G_GINT64_MODIFIER "d", summary.file_length);
add_string_to_box(string_buff, file_box);
g_snprintf(string_buff, SUM_STR_MAX, "Format: %s", wtap_file_type_string(summary.file_type));
add_string_to_box(string_buff, file_box);
if (summary.has_snap) {
g_snprintf(string_buff, SUM_STR_MAX, "Snapshot length: %u", summary.snap);
add_string_to_box(string_buff, file_box);
}
data_fr = gtk_frame_new("Data");
gtk_container_add(GTK_CONTAINER(main_vb), data_fr);
gtk_widget_show(data_fr);
data_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(data_fr), data_box);
gtk_widget_show(data_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
g_snprintf(string_buff, SUM_STR_MAX, "Elapsed time: %.3f seconds", summary.elapsed_time);
add_string_to_box(string_buff, data_box);
g_snprintf(string_buff, SUM_STR_MAX, "Between first and last packet: %.3f seconds", seconds);
add_string_to_box(string_buff, data_box);
}
g_snprintf(string_buff, SUM_STR_MAX, "Packet count: %i", summary.packet_count);
add_string_to_box(string_buff, data_box);
tot_invokes = 0;
tot_invokes_size = 0;
for (i=0; i < GSM_MAP_MAX_NUM_OPR_CODES; i++)
{
tot_invokes += gsm_map_stat.opr_code[i];
tot_invokes_size += gsm_map_stat.size[i];
}
tot_rr = 0;
tot_rr_size = 0;
for (i=0; i < GSM_MAP_MAX_NUM_OPR_CODES; i++)
{
tot_rr += gsm_map_stat.opr_code_rr[i];
tot_rr_size += gsm_map_stat.size_rr[i];
}
invoke_fr = gtk_frame_new("Invokes");
gtk_container_add(GTK_CONTAINER(main_vb), invoke_fr);
gtk_widget_show(invoke_fr);
invoke_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(invoke_fr), invoke_box);
gtk_widget_show(invoke_box);
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Invokes: %u", tot_invokes);
add_string_to_box(string_buff, invoke_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Invokes per second: %.2f", tot_invokes/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Invokes per second: N/A");
add_string_to_box(string_buff, invoke_box);
}
g_snprintf(string_buff, SUM_STR_MAX, "Total number of bytes for Invokes: %.0f", tot_invokes_size);
add_string_to_box(string_buff, invoke_box);
if (tot_invokes)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per Invoke: %.2f", tot_invokes_size/tot_invokes);
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per Invoke: N/A");
add_string_to_box(string_buff, invoke_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per second: %.2f", tot_invokes_size/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per second: N/A");
add_string_to_box(string_buff, invoke_box);
}
rr_fr = gtk_frame_new("Return Results");
gtk_container_add(GTK_CONTAINER(main_vb), rr_fr);
gtk_widget_show(rr_fr);
rr_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(rr_fr), rr_box);
gtk_widget_show(rr_box);
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Return Results: %u", tot_rr);
add_string_to_box(string_buff, rr_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Return Results per second: %.2f", tot_rr/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Total number of Return Results per second: N/A");
add_string_to_box(string_buff, rr_box);
}
g_snprintf(string_buff, SUM_STR_MAX, "Total number of bytes for Return Results: %.0f", tot_rr_size);
add_string_to_box(string_buff, rr_box);
if (tot_rr)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per Return Result: %.2f", tot_rr_size/tot_rr);
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per Return Result: N/A");
add_string_to_box(string_buff, rr_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per second: %.2f", tot_rr_size/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per second: N/A");
add_string_to_box(string_buff, rr_box);
}
tot_fr = gtk_frame_new("Totals");
gtk_container_add(GTK_CONTAINER(main_vb), tot_fr);
gtk_widget_show(tot_fr);
tot_box = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(tot_fr), tot_box);
gtk_widget_show(tot_box);
g_snprintf(string_buff, SUM_STR_MAX, "Total number of GSM MAP messages: %u", tot_invokes + tot_rr);
add_string_to_box(string_buff, tot_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Total number of GSM MAP messages per second: %.2f",
(tot_invokes + tot_rr)/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Total number of GSM MAP messages per second: N/A");
add_string_to_box(string_buff, tot_box);
}
g_snprintf(string_buff, SUM_STR_MAX, "Total number of bytes for GSM MAP messages: %.0f", tot_invokes_size + tot_rr_size);
add_string_to_box(string_buff, tot_box);
if (tot_invokes + tot_rr)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per GSM MAP messages: %.2f",
(tot_invokes_size + tot_rr_size)/(tot_invokes + tot_rr));
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes per GSM MAP messages: N/A");
add_string_to_box(string_buff, tot_box);
if (summary.packet_count_ts == summary.packet_count &&
summary.packet_count_ts >= 2) {
if (seconds)
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes second: %.2f",
(tot_invokes_size + tot_rr_size)/seconds);
else
g_snprintf(string_buff, SUM_STR_MAX, "Average number of bytes second: N/A");
add_string_to_box(string_buff, tot_box);
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_container_add(GTK_CONTAINER(main_vb), bbox);
gtk_widget_show(bbox);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(sum_open_w, close_bt, window_cancel_button_cb);
g_signal_connect(sum_open_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show(sum_open_w);
window_present(sum_open_w);
}
void
register_tap_listener_gtkgsm_map_summary(void)
{
}
