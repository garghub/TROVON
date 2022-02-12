static void
smbstat_set_title(smbstat_t *ss)
{
set_window_title(ss->win, "SMB Service Response Time statistics");
}
static void
smbstat_reset(void *pss)
{
smbstat_t *ss=(smbstat_t *)pss;
reset_srt_table_data(&ss->smb_srt_table);
reset_srt_table_data(&ss->trans2_srt_table);
reset_srt_table_data(&ss->nt_trans_srt_table);
smbstat_set_title(ss);
}
static int
smbstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
smbstat_t *ss=(smbstat_t *)pss;
const smb_info_t *si=(smb_info_t *)psi;
if(si->request){
return 0;
}
if(!si->sip){
return 0;
}
add_srt_table_data(&ss->smb_srt_table, si->cmd, &si->sip->req_time, pinfo);
if(si->cmd==0xA0 && si->sip->extra_info_type == SMB_EI_NTI){
smb_nt_transact_info_t *sti=(smb_nt_transact_info_t *)si->sip->extra_info;
if(sti){
add_srt_table_data(&ss->nt_trans_srt_table, sti->subcmd, &si->sip->req_time, pinfo);
}
} else if(si->cmd==0x32 && si->sip->extra_info_type == SMB_EI_T2I){
smb_transact2_info_t *st2i=(smb_transact2_info_t *)si->sip->extra_info;
if(st2i){
add_srt_table_data(&ss->trans2_srt_table, st2i->subcmd, &si->sip->req_time, pinfo);
}
}
return 1;
}
static void
smbstat_draw(void *pss)
{
smbstat_t *ss=(smbstat_t *)pss;
draw_srt_table_data(&ss->smb_srt_table);
draw_srt_table_data(&ss->trans2_srt_table);
draw_srt_table_data(&ss->nt_trans_srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
smbstat_t *ss=(smbstat_t *)data;
remove_tap_listener(ss);
free_srt_table_data(&ss->smb_srt_table);
free_srt_table_data(&ss->trans2_srt_table);
free_srt_table_data(&ss->nt_trans_srt_table);
g_free(ss);
}
static void
gtk_smbstat_init(const char *opt_arg, void *userdata _U_)
{
smbstat_t *ss;
const char *filter=NULL;
GtkWidget *label;
char *filter_string;
GString *error_string;
int i;
GtkWidget *vbox;
GtkWidget *bbox;
GtkWidget *close_bt;
if(!strncmp(opt_arg,"smb,srt,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
ss=(smbstat_t *)g_malloc(sizeof(smbstat_t));
ss->win = dlg_window_new("smb-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(ss->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(ss->win), 550, 600);
smbstat_set_title(ss);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(ss->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
label=gtk_label_new("SMB Service Response Time statistics");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
label=gtk_label_new("SMB Commands");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
gtk_widget_show_all(ss->win);
init_srt_table(&ss->smb_srt_table, 256, vbox, "smb.cmd");
for(i=0;i<256;i++){
init_srt_table_row(&ss->smb_srt_table, i, val_to_str_ext(i, &smb_cmd_vals_ext, "Unknown(0x%02x)"));
}
label=gtk_label_new("Transaction2 Sub-Commands");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
init_srt_table(&ss->trans2_srt_table, 256, vbox, "smb.trans2.cmd");
for(i=0;i<256;i++){
init_srt_table_row(&ss->trans2_srt_table, i, val_to_str_ext(i, &trans2_cmd_vals_ext, "Unknown(0x%02x)"));
}
label=gtk_label_new("NT Transaction Sub-Commands");
gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
init_srt_table(&ss->nt_trans_srt_table, 256, vbox, "smb.nt.function");
for(i=0;i<256;i++){
init_srt_table_row(&ss->nt_trans_srt_table, i, val_to_str_ext(i, &nt_cmd_vals_ext, "Unknown(0x%02x)"));
}
error_string=register_tap_listener("smb", ss, filter, 0, smbstat_reset, smbstat_packet, smbstat_draw);
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
register_tap_listener_gtksmbstat(void)
{
register_param_stat(&smb_stat_dlg, "SMB",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
