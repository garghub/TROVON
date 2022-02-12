static void
h225rassrt_reset(void *phs)
{
h225rassrt_t *hs=(h225rassrt_t *)phs;
int i;
for(i=0;i<NUM_RAS_STATS;i++) {
hs->ras_rtd[i].stats.num = 0;
hs->ras_rtd[i].stats.min_num = 0;
hs->ras_rtd[i].stats.max_num = 0;
hs->ras_rtd[i].stats.min.secs = 0;
hs->ras_rtd[i].stats.min.nsecs = 0;
hs->ras_rtd[i].stats.max.secs = 0;
hs->ras_rtd[i].stats.max.nsecs = 0;
hs->ras_rtd[i].stats.tot.secs = 0;
hs->ras_rtd[i].stats.tot.nsecs = 0;
hs->ras_rtd[i].open_req_num = 0;
hs->ras_rtd[i].disc_rsp_num = 0;
hs->ras_rtd[i].req_dup_num = 0;
hs->ras_rtd[i].rsp_dup_num = 0;
}
}
static int
h225rassrt_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
h225rassrt_t *hs=(h225rassrt_t *)phs;
const h225_packet_info *pi=phi;
ras_type rasmsg_type = RAS_OTHER;
ras_category rascategory = RAS_OTHERS;
if (pi->msg_type != H225_RAS || pi->msg_tag == -1) {
return 0;
}
if (pi->msg_tag < 21) {
rascategory = pi->msg_tag / 3;
rasmsg_type = pi->msg_tag % 3;
}
else {
return 0;
}
switch(rasmsg_type) {
case RAS_REQUEST:
if(pi->is_duplicate){
hs->ras_rtd[rascategory].req_dup_num++;
}
else {
hs->ras_rtd[rascategory].open_req_num++;
}
break;
case RAS_CONFIRM:
case RAS_REJECT:
if(pi->is_duplicate){
hs->ras_rtd[rascategory].rsp_dup_num++;
}
else if (!pi->request_available) {
hs->ras_rtd[rascategory].disc_rsp_num++;
}
else {
hs->ras_rtd[rascategory].open_req_num--;
time_stat_update(&(hs->ras_rtd[rascategory].stats),&(pi->delta_time), pinfo);
}
break;
default:
return 0;
}
return 1;
}
static void
h225rassrt_draw(void *phs)
{
h225rassrt_t *hs=(h225rassrt_t *)phs;
int i;
char str[3][256];
GtkListStore *store;
GtkTreeIter iter;
store = GTK_LIST_STORE(gtk_tree_view_get_model(hs->table));
gtk_list_store_clear(store);
for(i=0;i<NUM_RAS_STATS;i++) {
if(hs->ras_rtd[i].stats.num==0){
continue;
}
g_snprintf(str[0], sizeof(char[256]),
"%8.2f msec", nstime_to_msec(&(hs->ras_rtd[i].stats.min)));
g_snprintf(str[1], sizeof(char[256]),
"%8.2f msec", nstime_to_msec(&(hs->ras_rtd[i].stats.max)));
g_snprintf(str[2], sizeof(char[256]),
"%8.2f msec", get_average(&(hs->ras_rtd[i].stats.tot), hs->ras_rtd[i].stats.num));
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,
0, val_to_str(i,ras_message_category,"Other"),
1, hs->ras_rtd[i].stats.num,
2, str[0],
3, str[1],
4, str[2],
5, hs->ras_rtd[i].stats.min_num,
6, hs->ras_rtd[i].stats.max_num,
7, hs->ras_rtd[i].open_req_num,
8, hs->ras_rtd[i].disc_rsp_num,
9, hs->ras_rtd[i].req_dup_num,
10, hs->ras_rtd[i].rsp_dup_num,
-1);
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
h225rassrt_t *hs=(h225rassrt_t *)data;
protect_thread_critical_region();
remove_tap_listener(hs);
unprotect_thread_critical_region();
if(hs->filter){
g_free(hs->filter);
hs->filter=NULL;
}
g_free(hs);
}
static void
gtk_h225rassrt_init(const char *optarg, void *userdata _U_)
{
h225rassrt_t *hs;
GString *error_string;
GtkWidget *bbox;
GtkWidget *close_bt;
hs=g_malloc(sizeof(h225rassrt_t));
if(strncmp(optarg,"h225,srt,",9) == 0){
hs->filter=g_strdup(optarg+9);
} else {
hs->filter=NULL;
}
h225rassrt_reset(hs);
hs->win = dlg_window_new("h225-ras-srt");
gtk_window_set_destroy_with_parent (GTK_WINDOW(hs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(hs->win), 600, 300);
hs->vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(hs->vbox), 12);
init_main_stat_window(hs->win, hs->vbox, "H.225 RAS Service Response Time", hs->filter);
hs->scrolled_window = scrolled_window_new(NULL, NULL);
hs->table = create_stat_table(hs->scrolled_window, hs->vbox, 11, titles);
error_string=register_tap_listener("h225", hs, hs->filter, 0, h225rassrt_reset, h225rassrt_packet, h225rassrt_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(hs->filter);
g_free(hs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, NULL);
gtk_box_pack_end(GTK_BOX(hs->vbox), bbox, FALSE, FALSE, 0);
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(hs->win, close_bt, window_cancel_button_cb);
g_signal_connect(hs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(hs->win, "destroy", G_CALLBACK(win_destroy_cb), hs);
gtk_widget_show_all(hs->win);
window_present(hs->win);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(hs->win));
}
void
register_tap_listener_gtk_h225rassrt(void)
{
register_dfilter_stat(&h225_rassrt_dlg, "H.225 RAS",
REGISTER_STAT_GROUP_RESPONSE_TIME);
}
void h225_srt_cb(GtkAction *action, gpointer user_data _U_)
{
tap_param_dlg_cb(action, &h225_rassrt_dlg);
}
