static void
radiusstat_reset(void *prs)
{
radiusstat_t *rs=(radiusstat_t *)prs;
int i;
for(i=0; i<RADIUS_CAT_NUM_TIMESTATS; i++) {
rs->radius_rtd[i].stats.num=0;
rs->radius_rtd[i].stats.min_num=0;
rs->radius_rtd[i].stats.max_num=0;
rs->radius_rtd[i].stats.min.secs=0;
rs->radius_rtd[i].stats.min.nsecs=0;
rs->radius_rtd[i].stats.max.secs=0;
rs->radius_rtd[i].stats.max.nsecs=0;
rs->radius_rtd[i].stats.tot.secs=0;
rs->radius_rtd[i].stats.tot.nsecs=0;
rs->radius_rtd[i].open_req_num = 0;
rs->radius_rtd[i].disc_rsp_num = 0;
rs->radius_rtd[i].req_dup_num = 0;
rs->radius_rtd[i].rsp_dup_num = 0;
}
}
static int
radiusstat_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
radiusstat_t *rs=(radiusstat_t *)prs;
const radius_info_t *ri=(radius_info_t *)pri;
nstime_t delta;
radius_category radius_cat = RADIUS_CAT_OTHERS;
int ret = 0;
switch (ri->code) {
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
radius_cat = RADIUS_CAT_ACCESS;
break;
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
radius_cat = RADIUS_CAT_ACCOUNTING;
break;
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
radius_cat = RADIUS_CAT_PASSWORD;
break;
case RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE:
radius_cat = RADIUS_CAT_RESOURCE_FREE;
break;
case RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE:
radius_cat = RADIUS_CAT_RESOURCE_QUERY;
break;
case RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST:
case RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE:
radius_cat = RADIUS_CAT_NAS_REBOOT;
break;
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
radius_cat = RADIUS_CAT_EVENT;
break;
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
radius_cat = RADIUS_CAT_DISCONNECT;
break;
case RADIUS_PKT_TYPE_COA_REQUEST:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
radius_cat = RADIUS_CAT_COA;
break;
}
switch (ri->code) {
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_COA_REQUEST:
if(ri->is_duplicate){
rs->radius_rtd[RADIUS_CAT_OVERALL].req_dup_num++;
rs->radius_rtd[radius_cat].req_dup_num++;
}
else {
rs->radius_rtd[RADIUS_CAT_OVERALL].open_req_num++;
rs->radius_rtd[radius_cat].open_req_num++;
}
break;
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
if(ri->is_duplicate){
rs->radius_rtd[RADIUS_CAT_OVERALL].rsp_dup_num++;
rs->radius_rtd[radius_cat].rsp_dup_num++;
}
else if (!ri->request_available) {
rs->radius_rtd[RADIUS_CAT_OVERALL].disc_rsp_num++;
rs->radius_rtd[radius_cat].disc_rsp_num++;
}
else {
rs->radius_rtd[RADIUS_CAT_OVERALL].open_req_num--;
rs->radius_rtd[radius_cat].open_req_num--;
nstime_delta(&delta, &pinfo->fd->abs_ts, &ri->req_time);
time_stat_update(&(rs->radius_rtd[RADIUS_CAT_OVERALL].stats),&delta, pinfo);
time_stat_update(&(rs->radius_rtd[radius_cat].stats),&delta, pinfo);
ret = 1;
}
break;
default:
break;
}
return ret;
}
static void
radiusstat_draw(void *prs)
{
radiusstat_t *rs=(radiusstat_t *)prs;
int i;
char str[5][256];
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(rs->table));
gtk_list_store_clear(store);
for(i=0; i<RADIUS_CAT_NUM_TIMESTATS; i++) {
if(rs->radius_rtd[i].stats.num==0){
continue;
}
g_snprintf(str[0], 256, "%8.2f msec", nstime_to_msec(&(rs->radius_rtd[i].stats.min)));
g_snprintf(str[1], 256, "%8.2f msec", nstime_to_msec(&(rs->radius_rtd[i].stats.max)));
g_snprintf(str[2], 256, "%8.2f msec", get_average(&(rs->radius_rtd[i].stats.tot), rs->radius_rtd[i].stats.num));
g_snprintf(str[3], 256, "%4u (%4.2f%%)", rs->radius_rtd[i].req_dup_num,
rs->radius_rtd[i].stats.num?((double)rs->radius_rtd[i].req_dup_num*100)/(double)rs->radius_rtd[i].stats.num:0);
g_snprintf(str[4], 256, "%4u (%4.2f%%)", rs->radius_rtd[i].rsp_dup_num,
rs->radius_rtd[i].stats.num?((double)rs->radius_rtd[i].rsp_dup_num*100)/(double)rs->radius_rtd[i].stats.num:0);
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, val_to_str(i, radius_message_code,"Other"),
1, rs->radius_rtd[i].stats.num,
2, str[0],
3, str[1],
4, str[2],
5, rs->radius_rtd[i].stats.min_num,
6, rs->radius_rtd[i].stats.max_num,
7, rs->radius_rtd[i].open_req_num,
8, rs->radius_rtd[i].disc_rsp_num,
9, str[3],
10, str[4],
-1);
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
radiusstat_t *rs=(radiusstat_t *)data;
remove_tap_listener(rs);
if(rs->filter){
g_free(rs->filter);
rs->filter=NULL;
}
g_free(rs);
}
static void
gtk_radiusstat_init(const char *opt_arg, void *userdata _U_)
{
radiusstat_t *rs;
GString *error_string;
GtkWidget *bt_close;
GtkWidget *bbox;
rs=(radiusstat_t *)g_malloc(sizeof(radiusstat_t));
if(strncmp(opt_arg,"radius,srt,",11) == 0){
rs->filter=g_strdup(opt_arg+11);
} else {
rs->filter=NULL;
}
radiusstat_reset(rs);
rs->win = dlg_window_new("RADIUS SRT");
gtk_window_set_destroy_with_parent (GTK_WINDOW(rs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(rs->win), 600, 150);
rs->vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
init_main_stat_window(rs->win, rs->vbox, "RADIUS Service Response Time (SRT) Statistics", rs->filter);
rs->scrolled_window = scrolled_window_new(NULL, NULL);
rs->table = create_stat_table(rs->scrolled_window, rs->vbox, NUM_COLUMNS, titles);
error_string=register_tap_listener("radius", rs, rs->filter, 0, radiusstat_reset, radiusstat_packet, radiusstat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(rs->filter);
g_free(rs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_start(GTK_BOX(rs->vbox), bbox, FALSE, FALSE, 0);
bt_close = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(rs->win, bt_close, window_cancel_button_cb);
g_signal_connect(rs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(rs->win, "destroy", G_CALLBACK(win_destroy_cb), rs);
gtk_widget_show_all(rs->win);
window_present(rs->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(rs->win));
}
void
register_tap_listener_gtkradiusstat(void)
{
register_dfilter_stat(&radius_srt_dlg, "RADIUS",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void radius_srt_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &radius_srt_dlg);
}
