static void
gtpstat_set_title(gtpstat_t *gtp)
{
set_window_title(gtp->win, "GTP Control Plane Response Time statistics");
}
static void
gtpstat_reset(void *pgtp)
{
gtpstat_t *gtp=(gtpstat_t *)pgtp;
reset_srt_table_data(&gtp->gtp_srt_table);
gtpstat_set_title(gtp);
}
static int
gtpstat_packet(void *pgtp, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
const gtp_msg_hash_t *gtp=(gtp_msg_hash_t *)psi;
gtpstat_t *fs=(gtpstat_t *)pgtp;
int idx=0;
if(gtp->is_request){
return 0;
}
if(!gtp->req_frame){
return 0;
}
switch(gtp->msgtype){
case GTP_MSG_ECHO_REQ: idx=0;
break;
case GTP_MSG_CREATE_PDP_REQ: idx=1;
break;
case GTP_MSG_UPDATE_PDP_REQ: idx=2;
break;
case GTP_MSG_DELETE_PDP_REQ: idx=3;
break;
default:
return 0;
}
add_srt_table_data(&fs->gtp_srt_table, idx, &gtp->req_time, pinfo);
return 1;
}
static void
gtpstat_draw(void *pgtp)
{
gtpstat_t *gtp=(gtpstat_t *)pgtp;
draw_srt_table_data(&gtp->gtp_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
gtpstat_t *gtp=(gtpstat_t *)data;
remove_tap_listener(gtp);
free_srt_table_data(&gtp->gtp_srt_table);
g_free(gtp);
}
static void
gtk_gtpstat_init(const char *opt_arg, void *userdata _U_)
{
gtpstat_t *gtp;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"gtp,",4)){
filter=opt_arg+4;
} else {
filter="gtp";
}
gtp=(gtpstat_t *)g_malloc(sizeof(gtpstat_t));
gtp->win = dlg_window_new("gtp-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(gtp->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(gtp->win), 550, 400);
gtpstat_set_title(gtp);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(gtp->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("GTP Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("GTP Requests");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(gtp->win);
init_srt_table(&gtp->gtp_srt_table, 4, vbox, NULL);
init_srt_table_row(&gtp->gtp_srt_table, 0, "Echo");
init_srt_table_row(&gtp->gtp_srt_table, 1, "Create PDP context");
init_srt_table_row(&gtp->gtp_srt_table, 2, "Update PDP context");
init_srt_table_row(&gtp->gtp_srt_table, 3, "Delete PDP context");
error_string=register_tap_listener("gtp", gtp, filter, 0, gtpstat_reset, gtpstat_packet, gtpstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(gtp);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(gtp->win, close_bt, window_cancel_button_cb);
g_signal_connect(gtp->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(gtp->win, "destroy", G_CALLBACK(win_destroy_cb), gtp);
gtk_widget_show_all(gtp->win);
window_present(gtp->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(gtp->win));
}
void
register_tap_listener_gtkgtpstat(void)
{
register_param_stat(&gtp_stat_dlg, "GTP",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
