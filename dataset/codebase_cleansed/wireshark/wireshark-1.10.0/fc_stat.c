static void
fcstat_set_title(fcstat_t *fc)
{
set_window_title(fc->win, "Fibre Channel Service Response Time statistics");
}
static void
fcstat_reset(void *pfc)
{
fcstat_t *fc=(fcstat_t *)pfc;
reset_srt_table_data(&fc->fc_srt_table);
fcstat_set_title(fc);
}
static int
fcstat_packet(void *pfc, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
const fc_hdr *fc=(fc_hdr *)psi;
fcstat_t *fs=(fcstat_t *)pfc;
if(!(fc->fctl&FC_FCTL_EXCHANGE_RESPONDER)){
return 0;
}
if( (!fc->itlq) || (fc->itlq->first_exchange_frame==0) ){
return 0;
}
add_srt_table_data(&fs->fc_srt_table, fc->type, &fc->itlq->fc_time, pinfo);
return 1;
}
static void
fcstat_draw(void *pfc)
{
fcstat_t *fc=(fcstat_t *)pfc;
draw_srt_table_data(&fc->fc_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
fcstat_t *fc=(fcstat_t *)data;
remove_tap_listener(fc);
free_srt_table_data(&fc->fc_srt_table);
g_free(fc);
}
static void
gtk_fcstat_init(const char *opt_arg, void *userdata _U_)
{
fcstat_t *fc;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
int i;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"fc,srt,",7)){
filter=opt_arg+7;
} else {
filter=NULL;
}
fc=(fcstat_t *)g_malloc(sizeof(fcstat_t));
fc->win = dlg_window_new("fc-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(fc->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(fc->win), 550, 400);
fcstat_set_title(fc);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(fc->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("Fibre Channel Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("Fibre Channel Types");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(fc->win);
init_srt_table(&fc->fc_srt_table, 256, vbox, NULL);
for(i=0;i<256;i++){
init_srt_table_row(&fc->fc_srt_table, i, val_to_str(i, fc_fc4_val, "Unknown(0x%02x)"));
}
error_string=register_tap_listener("fc", fc, filter, 0, fcstat_reset, fcstat_packet, fcstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(fc);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(fc->win, close_bt, window_cancel_button_cb);
g_signal_connect(fc->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(fc->win, "destroy", G_CALLBACK(win_destroy_cb), fc);
gtk_widget_show_all(fc->win);
window_present(fc->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(fc->win));
}
void
register_tap_listener_gtkfcstat(void)
{
register_dfilter_stat(&fc_stat_dlg, "Fibre Channel",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void fc_srt_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &fc_stat_dlg);
}
