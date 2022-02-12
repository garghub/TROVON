static void
diameterstat_set_title(diameterstat_t *diameter)
{
set_window_title(diameter->win, "Diameter Service Response Time statistics");
}
static void
diameterstat_reset(void *pdiameter)
{
diameterstat_t *diameter=(diameterstat_t *)pdiameter;
reset_srt_table_data(&diameter->diameter_srt_table);
diameterstat_set_title(diameter);
}
static int
diameterstat_packet(void *pdiameter, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pdi)
{
const diameter_req_ans_pair_t *diameter=pdi;
diameterstat_t *fs=(diameterstat_t *)pdiameter;
int* idx = NULL;
if(!diameter || diameter->processing_request || !diameter->req_frame)
return 0;
idx = (int*) g_hash_table_lookup(cmd_str_hash, diameter->cmd_str);
if (idx == NULL) {
idx = g_malloc(sizeof(int));
*idx = (int) g_hash_table_size(cmd_str_hash);
g_hash_table_insert(cmd_str_hash, (gchar*) diameter->cmd_str, idx);
init_srt_table_row(&fs->diameter_srt_table, *idx, (const char*) diameter->cmd_str);
}
add_srt_table_data(&fs->diameter_srt_table, *idx, &diameter->req_time, pinfo);
return 1;
}
static void
diameterstat_draw(void *pdiameter)
{
diameterstat_t *diameter=(diameterstat_t *)pdiameter;
draw_srt_table_data(&diameter->diameter_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
diameterstat_t *diameter=(diameterstat_t *)data;
protect_thread_critical_region();
remove_tap_listener(diameter);
unprotect_thread_critical_region();
free_srt_table_data(&diameter->diameter_srt_table);
g_free(diameter);
g_hash_table_destroy(cmd_str_hash);
}
static void
gtk_diameterstat_init(const char *optarg, void *userdata _U_)
{
diameterstat_t *diameter;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
int* idx;
if(!strncmp(optarg,"diameter,",9)){
filter=optarg+9;
} else {
filter="diameter";
}
diameter=g_malloc(sizeof(diameterstat_t));
idx = g_malloc(sizeof(int));
*idx = 0;
cmd_str_hash = g_hash_table_new(g_str_hash,g_str_equal);
g_hash_table_insert(cmd_str_hash, (gchar *)"Unknown", idx);
diameter->win = dlg_window_new("diameter-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(diameter->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(diameter->win), 550, 400);
diameterstat_set_title(diameter);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(diameter->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("Diameter Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("Diameter Requests");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(diameter->win);
init_srt_table(&diameter->diameter_srt_table, 1, vbox, NULL);
init_srt_table_row(&diameter->diameter_srt_table, 0, "Unknown");
error_string=register_tap_listener("diameter", diameter, filter, 0, diameterstat_reset, diameterstat_packet, diameterstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(diameter);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(diameter->win, close_bt, window_cancel_button_cb);
g_signal_connect(diameter->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(diameter->win, "destroy", G_CALLBACK(win_destroy_cb), diameter);
gtk_widget_show_all(diameter->win);
window_present(diameter->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(diameter->win));
}
void
register_tap_listener_gtkdiameterstat(void)
{
register_dfilter_stat(&diameter_stat_dlg, "Diameter",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void diameter_srt_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &diameter_stat_dlg);
}
