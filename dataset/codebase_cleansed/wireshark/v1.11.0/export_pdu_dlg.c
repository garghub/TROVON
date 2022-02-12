static int
export_pdu_packet(void *tapdata, packet_info *pinfo, epan_dissect_t *edt _U_, const void *data)
{
const exp_pdu_data_t *exp_pdu_data = (exp_pdu_data_t *)data;
exp_pdu_t *exp_pdu_tap_data = (exp_pdu_t *)tapdata;
struct wtap_pkthdr pkthdr;
int err;
int buffer_len;
guint8 *packet_buf;
buffer_len = exp_pdu_data->tvb_length + exp_pdu_data->tlv_buffer_len;
packet_buf = (guint8 *)g_malloc(buffer_len);
if(exp_pdu_data->tlv_buffer_len > 0){
memcpy(packet_buf, exp_pdu_data->tlv_buffer, exp_pdu_data->tlv_buffer_len);
g_free(exp_pdu_data->tlv_buffer);
}
if(exp_pdu_data->tvb_length > 0){
tvb_memcpy(exp_pdu_data->pdu_tvb, packet_buf+exp_pdu_data->tlv_buffer_len, 0, exp_pdu_data->tvb_length);
}
pkthdr.ts.secs = pinfo->fd->abs_ts.secs;
pkthdr.ts.nsecs = pinfo->fd->abs_ts.nsecs;
pkthdr.caplen = pkthdr.len = buffer_len;
pkthdr.pkt_encap = exp_pdu_tap_data->pkt_encap;
pkthdr.interface_id = 0;
pkthdr.presence_flags = 0;
pkthdr.opt_comment = g_strdup(pinfo->pkt_comment);
pkthdr.drop_count = 0;
pkthdr.pack_flags = 0;
pkthdr.presence_flags = WTAP_HAS_CAP_LEN|WTAP_HAS_INTERFACE_ID|WTAP_HAS_TS|WTAP_HAS_PACK_FLAGS;
wtap_dump(exp_pdu_tap_data->wdh, &pkthdr, packet_buf, &err);
g_free(packet_buf);
g_free(pkthdr.opt_comment);
return FALSE;
}
static void
export_pdu_reset(void *data _U_)
{
}
static void
export_pdu_draw(void *data _U_)
{
}
static void
exp_pdu_file_open(exp_pdu_t *exp_pdu_tap_data)
{
int import_file_fd;
char *tmpname, *capfile_name;
int err;
wtapng_section_t *shb_hdr;
wtapng_iface_descriptions_t *idb_inf;
wtapng_if_descr_t int_data;
GString *os_info_str;
char appname[100];
import_file_fd = create_tempfile(&tmpname, "Wireshark_PDU_");
capfile_name = g_strdup(tmpname);
os_info_str = g_string_new("");
get_os_version_info(os_info_str);
g_snprintf(appname, sizeof(appname), "Wireshark " VERSION "%s", wireshark_svnversion);
shb_hdr = g_new(wtapng_section_t,1);
shb_hdr->section_length = -1;
shb_hdr->opt_comment = g_strdup_printf("Dump of PDU:s from %s", cfile.filename);
shb_hdr->shb_hardware = NULL;
shb_hdr->shb_os = os_info_str->str;
g_string_free(os_info_str, FALSE);
shb_hdr->shb_user_appl = appname;
idb_inf = g_new(wtapng_iface_descriptions_t,1);
idb_inf->number_of_interfaces = 1;
idb_inf->interface_data = g_array_new(FALSE, FALSE, sizeof(wtapng_if_descr_t));
int_data.wtap_encap = WTAP_ENCAP_WIRESHARK_UPPER_PDU;
int_data.time_units_per_second = 1000000;
int_data.link_type = wtap_wtap_encap_to_pcap_encap(WTAP_ENCAP_WIRESHARK_UPPER_PDU);
int_data.snap_len = WTAP_MAX_PACKET_SIZE;
int_data.if_name = g_strdup("Fake IF, PDU->Export");
int_data.opt_comment = NULL;
int_data.if_description = NULL;
int_data.if_speed = 0;
int_data.if_tsresol = 6;
int_data.if_filter_str = NULL;
int_data.bpf_filter_len = 0;
int_data.if_filter_bpf_bytes = NULL;
int_data.if_os = NULL;
int_data.if_fcslen = -1;
int_data.num_stat_entries = 0;
int_data.interface_statistics = NULL;
g_array_append_val(idb_inf->interface_data, int_data);
exp_pdu_tap_data->wdh = wtap_dump_fdopen_ng(import_file_fd, WTAP_FILE_PCAPNG, WTAP_ENCAP_WIRESHARK_UPPER_PDU, WTAP_MAX_PACKET_SIZE, FALSE, shb_hdr, idb_inf, &err);
if (exp_pdu_tap_data->wdh == NULL) {
open_failure_alert_box(capfile_name, err, TRUE);
goto end;
}
cf_retap_packets(&cfile);
if (!wtap_dump_close(exp_pdu_tap_data->wdh, &err)) {
write_failure_alert_box(capfile_name, err);
}
remove_tap_listener(exp_pdu_tap_data);
if (cf_open(&cfile, capfile_name, TRUE , &err) != CF_OK) {
open_failure_alert_box(capfile_name, err, FALSE);
goto end;
}
switch (cf_read(&cfile, FALSE)) {
case CF_READ_OK:
case CF_READ_ERROR:
break;
case CF_READ_ABORTED:
break;
}
end:
g_free(capfile_name);
}
static void
export_pdu_destroy_cb(GtkWidget *win _U_, gpointer user_data _U_)
{
export_pdu_dlg = NULL;
}
void
do_export_pdu(gpointer data)
{
const char *filter = NULL;
GString *error_string;
exp_pdu_t *exp_pdu_tap_data = (exp_pdu_t *)data;
gchar *tap_name = NULL;
filter = gtk_entry_get_text(GTK_ENTRY(exp_pdu_tap_data->filter_widget));
tap_name = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(exp_pdu_tap_data->tap_name_widget));
error_string = register_tap_listener(tap_name,
exp_pdu_tap_data,
filter,
TL_REQUIRES_NOTHING,
export_pdu_reset,
export_pdu_packet,
export_pdu_draw);
if (error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_free(exp_pdu_tap_data);
g_string_free(error_string, TRUE);
return;
}
exp_pdu_file_open(exp_pdu_tap_data);
window_destroy(export_pdu_dlg);
}
void
export_pdu_show_cb(GtkWidget *w _U_, gpointer d _U_)
{
GtkWidget *main_vb, *bbox, *close_bt, *ok_bt;
GtkWidget *grid, *filter_bt;
exp_pdu_t *exp_pdu_tap_data;
const char *filter = NULL;
guint row;
static construct_args_t args = {
"Wireshark: Export PDUs Filter",
TRUE,
FALSE,
FALSE
};
if (export_pdu_dlg != NULL) {
reactivate_window(export_pdu_dlg);
return;
}
exp_pdu_tap_data = (exp_pdu_t *)g_malloc(sizeof(exp_pdu_t));
exp_pdu_tap_data->pkt_encap = wtap_wtap_encap_to_pcap_encap(WTAP_ENCAP_WIRESHARK_UPPER_PDU);
export_pdu_dlg = window_new(GTK_WINDOW_TOPLEVEL, "Wireshark: Export PDU:s to pcap-ng file");
g_signal_connect(export_pdu_dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(export_pdu_dlg, "destroy", G_CALLBACK(export_pdu_destroy_cb), NULL);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 3);
gtk_container_add(GTK_CONTAINER(export_pdu_dlg), main_vb);
grid = ws_gtk_grid_new();
ws_gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
ws_gtk_grid_set_row_spacing(GTK_GRID(grid), 3);
gtk_box_pack_start(GTK_BOX(main_vb), grid, TRUE, TRUE, 0);
row = 0;
filter_bt=gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), filter_bt, 0, row, 1, 1);
gtk_widget_show(filter_bt);
exp_pdu_tap_data->filter_widget=gtk_entry_new();
g_signal_connect(exp_pdu_tap_data->filter_widget, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(grid), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(exp_pdu_tap_data->filter_widget, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, exp_pdu_tap_data->filter_widget);
filter=gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
if(filter){
gtk_entry_set_text(GTK_ENTRY(exp_pdu_tap_data->filter_widget), filter);
} else {
colorize_filter_te_as_empty(exp_pdu_tap_data->filter_widget);
}
ws_gtk_grid_attach_defaults(GTK_GRID(grid), exp_pdu_tap_data->filter_widget, 1, row, 1, 1);
gtk_widget_show(exp_pdu_tap_data->filter_widget);
row++;
exp_pdu_tap_data->tap_name_widget = gtk_combo_box_text_new();
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(exp_pdu_tap_data->tap_name_widget), EXPORT_PDU_TAP_NAME_LAYER_7);
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(exp_pdu_tap_data->tap_name_widget), EXPORT_PDU_TAP_NAME_LAYER_3);
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(exp_pdu_tap_data->tap_name_widget), EXPORT_PDU_TAP_NAME_DVB_CI);
gtk_combo_box_set_active(GTK_COMBO_BOX(exp_pdu_tap_data->tap_name_widget), 0);
ws_gtk_grid_attach_defaults(GTK_GRID(grid), exp_pdu_tap_data->tap_name_widget, 0, row, 1, 1);
gtk_widget_show(exp_pdu_tap_data->tap_name_widget);
bbox = dlg_button_row_new(GTK_STOCK_OK, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_end(GTK_BOX(main_vb), bbox, FALSE, FALSE, 3);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(export_pdu_dlg, close_bt, window_cancel_button_cb);
gtk_widget_set_tooltip_text(close_bt, "Close this dialog");
ok_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_OK);
g_signal_connect(ok_bt, "clicked", G_CALLBACK(file_export_pdu_ok_cb), exp_pdu_tap_data);
gtk_widget_grab_default(ok_bt);
gtk_widget_set_tooltip_text(ok_bt, "Export PDU:s to a temporary capture file");
gtk_widget_show_all(export_pdu_dlg);
window_present(export_pdu_dlg);
}
