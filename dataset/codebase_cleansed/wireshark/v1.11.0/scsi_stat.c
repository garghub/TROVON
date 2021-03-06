static char *
scsistat_gen_title(scsistat_t *rs)
{
char *display_name;
char *title;
display_name = cf_get_display_name(&cfile);
title = g_strdup_printf("SCSI Service Response Time statistics for %s: %s",
rs->prog, display_name);
g_free(display_name);
return title;
}
static void
scsistat_set_title(scsistat_t *rs)
{
char *title;
title = scsistat_gen_title(rs);
gtk_window_set_title(GTK_WINDOW(rs->win), title);
g_free(title);
}
static void
scsistat_reset(void *arg)
{
scsistat_t *rs = (scsistat_t *)arg;
reset_srt_table_data(&rs->srt_table);
scsistat_set_title(rs);
}
static int
scsistat_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2)
{
scsistat_t *rs = (scsistat_t *)arg;
const scsi_task_data_t *ri = (const scsi_task_data_t *)arg2;
if(ri->type!=SCSI_PDU_TYPE_RSP){
return 0;
}
if( (!ri->itl) || ((ri->itl->cmdset&SCSI_CMDSET_MASK)!=rs->cmdset) ){
return 0;
}
if( (!ri->itlq) || (ri->itlq->scsi_opcode>255) ){
return 0;
}
add_srt_table_data(&rs->srt_table, ri->itlq->scsi_opcode, &ri->itlq->fc_time, pinfo);
return 1;
}
static void
scsistat_draw(void *arg)
{
scsistat_t *rs = (scsistat_t *)arg;
draw_srt_table_data(&rs->srt_table);
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
scsistat_t *rs=(scsistat_t *)data;
remove_tap_listener(rs);
free_srt_table_data(&rs->srt_table);
g_free(rs);
}
static void
gtk_scsistat_init(const char *opt_arg, void* userdata _U_)
{
scsistat_t *rs;
guint32 i;
char *title_string;
char *filter_string;
GtkWidget *vbox;
GtkWidget *stat_label;
GtkWidget *filter_label;
GtkWidget *bbox;
GtkWidget *close_bt;
int program, pos;
const char *filter=NULL;
GString *error_string;
const char *hf_name=NULL;
pos=0;
if(sscanf(opt_arg,"scsi,srt,%d,%n",&program,&pos)==1){
if(pos){
filter=opt_arg+pos;
} else {
filter=NULL;
}
} else {
fprintf(stderr, "wireshark: invalid \"-z scsi,srt,<cmdset>[,<filter>]\" argument\n");
exit(1);
}
scsi_program=program;
rs=(scsistat_t *)g_malloc(sizeof(scsistat_t));
rs->cmdset=program;
switch(program){
case SCSI_DEV_SBC:
rs->prog="SBC (disk)";
rs->cdbnames=scsi_sbc_vals;
hf_name="scsi_sbc.opcode";
break;
case SCSI_DEV_SSC:
rs->prog="SSC (tape)";
rs->cdbnames=scsi_ssc_vals;
hf_name="scsi_ssc.opcode";
break;
case SCSI_DEV_CDROM:
rs->prog="MMC (cd/dvd)";
rs->cdbnames=scsi_mmc_vals;
hf_name="scsi_mmc.opcode";
break;
case SCSI_DEV_SMC:
rs->prog="SMC (tape robot)";
rs->cdbnames=scsi_smc_vals;
hf_name="scsi_smc.opcode";
break;
case SCSI_DEV_OSD:
rs->prog="OSD (object based)";
rs->cdbnames=scsi_osd_vals;
hf_name="scsi_osd.opcode";
break;
}
rs->win = dlg_window_new("scsi-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(rs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(rs->win), 550, 400);
scsistat_set_title(rs);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(rs->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
title_string = scsistat_gen_title(rs);
stat_label=gtk_label_new(title_string);
g_free(title_string);
gtk_box_pack_start(GTK_BOX(vbox), stat_label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
filter_label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(filter_label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), filter_label, FALSE, FALSE, 0);
gtk_widget_show_all(rs->win);
init_srt_table(&rs->srt_table, 256, vbox, hf_name);
for(i=0;i<256;i++){
init_srt_table_row(&rs->srt_table, i, val_to_str(i, rs->cdbnames, "Unknown-0x%02x"));
}
error_string=register_tap_listener("scsi", rs, filter, 0, scsistat_reset, scsistat_packet, scsistat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
free_srt_table_data(&rs->srt_table);
g_free(rs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(rs->win, close_bt, window_cancel_button_cb);
g_signal_connect(rs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rs->win, "destroy", G_CALLBACK(win_destroy_cb), rs);
gtk_widget_show_all(rs->win);
window_present(rs->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(rs->win));
}
void
register_tap_listener_gtkscsistat(void)
{
register_param_stat(&scsi_stat_dlg, "SCSI",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
