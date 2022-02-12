static void
smb2stat_set_title(smb2stat_t *ss)
{
set_window_title(ss->win, "SMB2 Service Response Time statistics");
}
static void
smb2stat_reset(void *pss)
{
smb2stat_t *ss=(smb2stat_t *)pss;
reset_srt_table_data(&ss->smb2_srt_table);
smb2stat_set_title(ss);
}
static int
smb2stat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
smb2stat_t *ss=(smb2stat_t *)pss;
const smb2_info_t *si=(smb2_info_t *)psi;
if(!(si->flags&SMB2_FLAGS_RESPONSE)){
return 0;
}
if(!si->saved){
return 0;
}
if(si->saved->frame_req
&& si->saved->frame_res==pinfo->fd->num)
add_srt_table_data(&ss->smb2_srt_table, si->opcode, &si->saved->req_time, pinfo);
else
return 0;
return 1;
}
static void
smb2stat_draw(void *pss)
{
smb2stat_t *ss=(smb2stat_t *)pss;
draw_srt_table_data(&ss->smb2_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
smb2stat_t *ss=(smb2stat_t *)data;
remove_tap_listener(ss);
free_srt_table_data(&ss->smb2_srt_table);
g_free(ss);
}
static void
gtk_smb2stat_init(const char *opt_arg, void *userdata _U_)
{
smb2stat_t *ss;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
int i;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"smb2,srt,",9)){
filter=opt_arg+9;
} else {
filter=NULL;
}
ss=(smb2stat_t *)g_malloc(sizeof(smb2stat_t));
ss->win = dlg_window_new("smb2-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(ss->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(ss->win), 550, 400);
smb2stat_set_title(ss);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(ss->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("SMB2 Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("SMB2 Commands");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(ss->win);
init_srt_table(&ss->smb2_srt_table, 256, vbox, "smb2.cmd");
for(i=0;i<256;i++){
init_srt_table_row(&ss->smb2_srt_table, i, val_to_str_ext(i, &smb2_cmd_vals_ext, "Unknown(0x%02x)"));
}
error_string=register_tap_listener("smb2", ss, filter, 0, smb2stat_reset, smb2stat_packet, smb2stat_draw);
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
register_tap_listener_gtksmb2stat(void)
{
register_param_stat(&smb2_stat_dlg, "SMB2",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
