static void
afpstat_set_title(afpstat_t *ss)
{
set_window_title(ss->win, "AFP Service Response Time statistics");
}
static void
afpstat_reset(void *pss)
{
afpstat_t *ss=(afpstat_t *)pss;
reset_srt_table_data(&ss->afp_srt_table);
afpstat_set_title(ss);
}
static int
afpstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
afpstat_t *ss=(afpstat_t *)pss;
const afp_request_val *request_val=(const afp_request_val *)prv;
if(!request_val){
return 0;
}
add_srt_table_data(&ss->afp_srt_table, request_val->command, &request_val->req_time, pinfo);
return 1;
}
static void
afpstat_draw(void *pss)
{
afpstat_t *ss=(afpstat_t *)pss;
draw_srt_table_data(&ss->afp_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
afpstat_t *ss=(afpstat_t *)data;
remove_tap_listener(ss);
free_srt_table_data(&ss->afp_srt_table);
g_free(ss);
}
static void
gtk_afpstat_init(const char *opt_arg, void *userdata _U_)
{
afpstat_t *ss;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
int i;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"afp,srt,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
ss=(afpstat_t *)g_malloc(sizeof(afpstat_t));
ss->win=dlg_window_new("afp-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(ss->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(ss->win), 550, 600);
afpstat_set_title(ss);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(ss->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("AFP Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
g_free(filter_string);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("AFP Commands");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(ss->win);
init_srt_table(&ss->afp_srt_table, 256, vbox, "afp.command");
for(i=0;i<256;i++){
init_srt_table_row(&ss->afp_srt_table, i, val_to_str_ext(i, &CommandCode_vals_ext, "Unknown(%u)"));
}
error_string=register_tap_listener("afp", ss, filter, 0, afpstat_reset, afpstat_packet, afpstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(ss);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(ss->win, close_bt, window_cancel_button_cb);
g_signal_connect(ss->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(ss->win, "destroy", G_CALLBACK(win_destroy_cb), ss);
gtk_widget_show_all(ss->win);
window_present(ss->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(ss->win));
}
void
register_tap_listener_gtkafpstat(void)
{
register_dfilter_stat(&afp_stat_dlg, "AFP",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void afp_srt_stat_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &afp_stat_dlg);
}
