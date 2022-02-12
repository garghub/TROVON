static void
comparestat_set_title(compstat_t *cs)
{
set_window_title(cs->win, "Compare two capture files");
}
static void
comparestat_reset(void *arg)
{
compstat_t *cs=(compstat_t *)arg;
SET_ADDRESS(&cs->eth_src, AT_ETHER, 0, NULL);
SET_ADDRESS(&cs->eth_dst, AT_ETHER, 0, NULL);
gtk_tree_store_clear(cs->simple_list);
comparestat_set_title(cs);
}
static int
comparestat_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2)
{
compstat_t *cs=(compstat_t *)arg;
const ws_ip *ci=(const ws_ip *)arg2;
frame_info *fInfo, *fInfoTemp;
vec_t cksum_vec[3];
guint16 computed_cksum=0;
if(cs->eth_dst.len==0) {
cs->eth_dst=pinfo->dl_dst;
cs->eth_src=pinfo->dl_src;
}
cksum_vec[0].ptr=&ci->ip_v_hl;
cksum_vec[0].len=BYTES;
cksum_vec[1].ptr=&ci->ip_p;
cksum_vec[1].len=1;
cksum_vec[2].ptr=(const guint8 *)ci->ip_dst.data;
cksum_vec[2].ptr=cksum_vec[2].ptr+ci->ip_dst.len;
cksum_vec[2].len=ci->ip_len-20;
computed_cksum=in_cksum(&cksum_vec[0], 3);
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(pinfo->fd->num));
if((fInfoTemp!=NULL)){
col_set_time(pinfo->cinfo, COL_INFO, &fInfoTemp->zebra_time, "ZebraTime");
}
fInfo=(frame_info*)se_alloc(sizeof(frame_info));
fInfo->fg=(for_gui*)se_alloc(sizeof(for_gui));
fInfo->fg->partner=NULL;
fInfo->fg->count=1;
fInfo->fg->cksum=computed_cksum;
fInfo->num=pinfo->fd->num;
fInfo->id=ci->ip_id;
fInfo->ip_ttl=ci->ip_ttl;
fInfo->dl_dst=pinfo->dl_dst;
fInfo->abs_ts=pinfo->fd->abs_ts;
nstime_set_zero(&fInfo->zebra_time);
nstime_set_zero(&fInfo->fg->predecessor_time);
g_hash_table_insert(cs->packet_set, GINT_TO_POINTER(pinfo->fd->num), fInfo);
if((guint32)cf_get_packet_count(&cfile)==fInfo->num){
nstime_set_unset(&cs->current_time);
return 1;
} else {
return 0;
}
}
static void
call_foreach_count_ip_id(gpointer key _U_, gpointer value, gpointer arg)
{
compstat_t *cs=(compstat_t*)arg;
frame_info *fInfo=(frame_info*)value, *fInfoTemp;
nstime_t delta;
guint i;
packet_info *pinfo=(packet_info*)ep_alloc(sizeof(packet_info));
pinfo->fd=(frame_data*)ep_alloc(sizeof(frame_data));
pinfo->fd->num = fInfo->num;
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->ip_id_set, GINT_TO_POINTER((gint)fInfo->id));
if(fInfoTemp==NULL){
if((cs->last_hit==FALSE)&&(cs->start_ongoing_hits>compare_start)&&(cs->stop_ongoing_hits<compare_stop)){
cs->stop_ongoing_hits++;
cs->stop_packet_nr_first=fInfo->num;
} else if(cs->stop_ongoing_hits<compare_stop){
cs->stop_ongoing_hits=0;
cs->stop_packet_nr_first=G_MAXINT32;
}
cs->last_hit=FALSE;
fInfo->fg->count=1;
g_hash_table_insert(cs->ip_id_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
} else {
if((cs->last_hit||(compare_start==0))&&(cs->start_ongoing_hits<compare_start||(compare_start==0))){
if((compare_start==0)&&(cs->start_ongoing_hits!=0)){
} else {
cs->start_ongoing_hits++;
cs->start_packet_nr_first=fInfoTemp->num;
cs->start_packet_nr_second=fInfo->num;
}
} else if(cs->start_ongoing_hits<compare_start){
cs->start_ongoing_hits=0;
cs->start_packet_nr_first=G_MAXINT32;
}
cs->last_hit=TRUE;
fInfo->fg->count=fInfoTemp->fg->count + 1;
if(fInfoTemp->fg->cksum!=fInfo->fg->cksum){
fInfo->fg->cksum=WRONG_CHKSUM;
fInfoTemp->fg->cksum=WRONG_CHKSUM;
}
fInfo->fg->partner=fInfoTemp;
if(fInfo->fg->count==MERGED_FILES){
nstime_delta(&delta, &fInfo->abs_ts, &fInfoTemp->abs_ts);
nstime_set_zero(&fInfoTemp->delta);
nstime_add(&fInfoTemp->delta, &delta);
nstime_set_zero(&fInfo->delta);
nstime_add(&fInfo->delta, &delta);
time_stat_update(&cs->stats, &delta, pinfo);
}
g_hash_table_insert(cs->ip_id_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
}
if(TTL_method && (fInfo->num<TTL_SEARCH)){
for(i=0; i < cs->ip_ttl_list->len; i++){
if(g_array_index(cs->ip_ttl_list, guint8, i) == fInfo->ip_ttl){
return;
}
}
g_array_append_val(cs->ip_ttl_list, fInfo->ip_ttl);
}
}
static void
call_foreach_new_order(gpointer key _U_, gpointer value, gpointer arg)
{
compstat_t *cs=(compstat_t*)arg;
frame_info *fInfo=(frame_info*)value, *fInfoTemp;
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->nr_set, GINT_TO_POINTER((gint)fInfo->id));
if(fInfoTemp==NULL){
if(TTL_method==FALSE){
if((ADDRESSES_EQUAL(&cs->eth_dst, &fInfo->dl_dst)) || (ADDRESSES_EQUAL(&cs->eth_src, &fInfo->dl_dst))){
g_hash_table_insert(cs->nr_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
fInfo->zebra_time=cs->zebra_time;
cs->zebra_time.nsecs=cs->zebra_time.nsecs + MERGED_FILES;
} else {
cs->zebra_time.nsecs++;
g_hash_table_insert(cs->nr_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
fInfo->zebra_time=cs->zebra_time;
cs->zebra_time.nsecs++;
}
} else {
if((g_array_index(cs->ip_ttl_list, guint8, 0)==fInfo->ip_ttl) || (g_array_index(cs->ip_ttl_list, guint8, 1)==fInfo->ip_ttl)){
g_hash_table_insert(cs->nr_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
fInfo->zebra_time=cs->zebra_time;
cs->zebra_time.nsecs=cs->zebra_time.nsecs + MERGED_FILES;
} else {
cs->zebra_time.nsecs++;
g_hash_table_insert(cs->nr_set, GINT_TO_POINTER((gint)fInfo->id), fInfo);
fInfo->zebra_time=cs->zebra_time;
cs->zebra_time.nsecs++;
}
}
} else {
if(TTL_method==FALSE){
if(((ADDRESSES_EQUAL(&cs->eth_dst, &fInfo->dl_dst)) || (ADDRESSES_EQUAL(&cs->eth_src, &fInfo->dl_dst)))&&(!fmod(fInfoTemp->zebra_time.nsecs,MERGED_FILES))){
fInfo->zebra_time.nsecs=fInfoTemp->zebra_time.nsecs;
} else {
fInfo->zebra_time.nsecs=fInfoTemp->zebra_time.nsecs+1;
}
} else {
if(((g_array_index(cs->ip_ttl_list, guint8, 0)==fInfo->ip_ttl) || (g_array_index(cs->ip_ttl_list, guint8, 1)==fInfo->ip_ttl))&&(!fmod(fInfoTemp->zebra_time.nsecs,MERGED_FILES))){
fInfo->zebra_time.nsecs=fInfoTemp->zebra_time.nsecs;
} else {
fInfo->zebra_time.nsecs=fInfoTemp->zebra_time.nsecs+1;
}
}
}
if(fmod(fInfo->zebra_time.nsecs, MERGED_FILES)){
cs->first_file_amount++;
} else {
cs->second_file_amount++;
}
if(!nstime_is_unset(&cs->current_time)){
fInfo->fg->predecessor_time.nsecs=cs->current_time.nsecs;
}
cs->current_time.nsecs=fInfo->zebra_time.nsecs;
}
static void
call_foreach_merge_settings(gpointer key _U_, gpointer value, gpointer arg)
{
compstat_t *cs=(compstat_t*)arg;
frame_info *fInfo=(frame_info*)value, *fInfoTemp=NULL;
guint32 tot_packet_amount=cs->first_file_amount+cs->second_file_amount, swap;
if((fInfo->num==tot_packet_amount)&&(cs->stop_packet_nr_first!=G_MAXINT32)){
swap=cs->stop_packet_nr_first;
cs->stop_packet_nr_first=tot_packet_amount-cs->second_file_amount;
cs->stop_packet_nr_second=swap;
}
if((fInfo->num==tot_packet_amount)&&(cs->stop_packet_nr_first==G_MAXINT32)&&(cs->start_packet_nr_first!=G_MAXINT32)){
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->start_packet_nr_first));
if(fInfoTemp==NULL){
fprintf(stderr,"ERROR: Incorrect start number\n");
}
if(fInfoTemp && fmod(fInfoTemp->zebra_time.nsecs, 2)){
cs->stop_packet_nr_first=cs->start_packet_nr_first+(cs->second_file_amount-(cs->start_packet_nr_second-cs->first_file_amount));
if(cs->stop_packet_nr_first>(tot_packet_amount-cs->second_file_amount)){
cs->stop_packet_nr_first=tot_packet_amount-cs->second_file_amount;
}
if(cs->stop_packet_nr_first>cs->start_packet_nr_second){
cs->stop_packet_nr_first=cs->start_packet_nr_second-1;
}
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->stop_packet_nr_first));
while((fInfoTemp!=NULL)?fmod(!fInfoTemp->zebra_time.nsecs, 2):TRUE){
cs->stop_packet_nr_first--;
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->stop_packet_nr_first));
}
} else {
cs->stop_packet_nr_first=cs->first_file_amount+cs->start_packet_nr_first;
if(cs->stop_packet_nr_first>tot_packet_amount-cs->first_file_amount){
cs->stop_packet_nr_first=tot_packet_amount-cs->first_file_amount;
}
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->stop_packet_nr_first));
while((fInfoTemp!=NULL)?fmod(fInfoTemp->zebra_time.nsecs, 2):TRUE){
cs->stop_packet_nr_first--;
fInfoTemp=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->stop_packet_nr_first));
}
}
cs->stop_packet_nr_second=cs->start_packet_nr_second+(cs->stop_packet_nr_first-cs->start_packet_nr_first);
if(cs->stop_packet_nr_second>tot_packet_amount){
cs->stop_packet_nr_second=tot_packet_amount;
}
}
if(fInfo->num==tot_packet_amount&&compare_start!=0&&compare_stop!=0){
if(cs->start_packet_nr_first==G_MAXINT32){
report_failure("Start point couldn't be set. Please choose a lower start number.");
}
}
}
static void
call_foreach_print_ip_tree(gpointer key _U_, gpointer value, gpointer user_data)
{
frame_info *fInfo=(frame_info*)value;
compstat_t *cs=(compstat_t*)user_data;
gdouble delta, average;
gboolean show_it=FALSE;
delta=fabs(get_average(&fInfo->delta,1));
average=fabs(get_average(&cs->stats.tot, cs->stats.num));
if(compare_start!=0&&compare_stop!=0){
if((cs->start_packet_nr_first<fInfo->num)&&(cs->stop_packet_nr_first>fInfo->num)){
show_it=TRUE;
} else {
if((fInfo->num>cs->start_packet_nr_second)&&(fInfo->num<cs->stop_packet_nr_second)){
show_it=TRUE;
}
}
} else {
show_it=TRUE;
}
if(show_it){
if((fInfo->fg->count<MERGED_FILES)){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "Lost packet", COUNT, fInfo->fg->count, DELTA, 0.0, -1);
}
if(fInfo->fg->count > MERGED_FILES){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "More than two packets", COUNT, fInfo->fg->count, DELTA, 0.0, -1);
if(fInfo->fg->cksum == WRONG_CHKSUM) {
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, &cs->iter);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, IP_ID, fInfo->id, PROBLEM, "IP header checksum incorrect", COUNT, fInfo->fg->count, DELTA, 0.0, -1);
}
}
if(fInfo->fg->count == MERGED_FILES){
if(fInfo->fg->cksum == WRONG_CHKSUM) {
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "IP header checksum incorrect", COUNT, fInfo->fg->count, DELTA, delta, -1);
if(((delta < (average-cs->stats.variance)) || (delta > (average+cs->stats.variance))) && (delta > 0.0) && (cs->stats.variance!=0)){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, &cs->iter);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, IP_ID, fInfo->id, PROBLEM, "Late arrival", COUNT, fInfo->fg->count, DELTA, delta, -1);
}
if((nstime_cmp(&fInfo->fg->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fg->partner->fg->predecessor_time, &fInfo->fg->partner->zebra_time)>0) && (fInfo->zebra_time.nsecs!=MERGED_FILES) && ON_method){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, &cs->iter);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, IP_ID, fInfo->id, PROBLEM, "Out of order", COUNT, fInfo->fg->count, DELTA, delta, -1);
}
} else if(((delta < (average-cs->stats.variance)) || (delta > (average+cs->stats.variance))) && (delta > 0.0) && (cs->stats.variance!=0)) {
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "Late arrival", COUNT, fInfo->fg->count, DELTA, delta, -1);
if((nstime_cmp(&fInfo->fg->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fg->partner->fg->predecessor_time, &fInfo->fg->partner->zebra_time)>0) && fInfo->zebra_time.nsecs != MERGED_FILES && ON_method){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, &cs->iter);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->child, IP_ID, fInfo->id, PROBLEM, "Out of order", COUNT, fInfo->fg->count, DELTA, delta, -1);
}
} else if((nstime_cmp(&fInfo->fg->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fg->partner->fg->predecessor_time, &fInfo->fg->partner->zebra_time)>0) && fInfo->zebra_time.nsecs != MERGED_FILES && ON_method){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "Out of order", COUNT, fInfo->fg->count, DELTA, delta, -1);
}
}
}
}
static void
win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
compstat_t *cs=(compstat_t *)data;
remove_tap_listener(cs);
first_window=TRUE;
gtk_tree_store_clear(cs->simple_list);
g_hash_table_destroy(cs->packet_set);
g_hash_table_destroy(cs->nr_set);
g_free(cs);
}
static void
comparestat_draw(void *arg)
{
compstat_t *cs = (compstat_t *)arg;
GString *filter_str = g_string_new("");
const gchar *statis_string;
frame_info *fInfo;
guint32 first_file_amount, second_file_amount;
cs->zebra_time.secs=0;
cs->zebra_time.nsecs=1;
nstime_set_unset(&cs->current_time);
cs->ip_ttl_list=g_array_new(FALSE, FALSE, sizeof(guint8));
cs->last_hit=FALSE;
cs->start_ongoing_hits=0;
cs->stop_ongoing_hits=0;
cs->start_packet_nr_first=G_MAXINT32;
cs->start_packet_nr_second=G_MAXINT32;
cs->stop_packet_nr_first=G_MAXINT32;
cs->stop_packet_nr_second=G_MAXINT32;
cs->first_file_amount=0;
cs->second_file_amount=0;
time_stat_init(&cs->stats);
if(cf_get_packet_count(&cfile)==0){
statis_string=g_strdup_printf("No file open");
gtk_label_set_text((GtkLabel *) cs->statis_label, statis_string);
return;
}
cs->ip_id_set=g_hash_table_new(NULL, NULL);
g_hash_table_foreach(cs->packet_set, call_foreach_count_ip_id, cs);
if(TTL_method&&cs->ip_ttl_list->len==1){
g_array_append_val(cs->ip_ttl_list, g_array_index(cs->ip_ttl_list, guint8, 1));
}
g_hash_table_foreach(cs->packet_set, call_foreach_new_order,cs);
g_hash_table_foreach(cs->packet_set, call_foreach_merge_settings, cs);
first_file_amount=cs->first_file_amount;
second_file_amount=cs->second_file_amount;
g_hash_table_remove_all(cs->nr_set);
timestamp_set_precision(TS_PREC_AUTO_NSEC);
nstime_set_unset(&cs->current_time);
if(TTL_method&&cs->ip_ttl_list->len!=0){
g_string_printf(filter_str, "%s %i %s %i", "ip.ttl ==", g_array_index(cs->ip_ttl_list, guint8, 0), "|| ip.ttl ==", g_array_index(cs->ip_ttl_list, guint8, 1));
} else if(cs->eth_dst.len!=0&&cs->eth_src.len!=0){
g_string_printf(filter_str, "%s %s %s %s", "eth.dst==", ep_address_to_str(&cs->eth_dst), "|| eth.dst==", ep_address_to_str(&cs->eth_src));
}
color_filters_set_tmp(COLOR_N, filter_str->str, FALSE);
packet_list_colorize_packets();
cs->stats.variance=compare_variance;
statis_string=g_strdup_printf("Compare Statistics: \nNumber of packets total:%i 1st file:%i, 2nd file:%i\nScopes:\t start:%i stop:%i\nand:\t start:%i stop:%i\nEqual packets: %i \nAllowed variation: %f \nAverage time difference: %f", cf_get_packet_count(&cfile), first_file_amount, second_file_amount, cs->start_packet_nr_first, cs->stop_packet_nr_first, cs->start_packet_nr_second, cs->stop_packet_nr_second, cs->stats.num, cs->stats.variance, fabs(get_average(&cs->stats.tot, cs->stats.num)));
gtk_label_set_text((GtkLabel *) cs->statis_label, statis_string);
if(cs->start_packet_nr_first!=G_MAXINT32&&compare_start!=0&&compare_stop!=0){
fInfo=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->start_packet_nr_first));
if(fInfo){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "Start scanning", COUNT, 0, DELTA, 0.0, -1);
}
}
if(cs->stop_packet_nr_first!=G_MAXINT32&&compare_start!=0&&compare_stop!=0){
fInfo=(frame_info *)g_hash_table_lookup(cs->packet_set, GINT_TO_POINTER(cs->stop_packet_nr_first));
if(fInfo){
gtk_tree_store_append(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, NULL);
gtk_tree_store_set(GTK_TREE_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(cs->treeview))), &cs->iter, IP_ID, fInfo->id, PROBLEM, "Stop scanning", COUNT, 0, DELTA, 0.0, -1);
}
}
g_hash_table_foreach(cs->ip_id_set, call_foreach_print_ip_tree, cs);
g_hash_table_destroy(cs->ip_id_set);
g_string_free(filter_str, TRUE);
g_array_free(cs->ip_ttl_list, TRUE);
}
static void
new_tree_view_selection_changed(GtkTreeSelection *sel, gpointer user_data)
{
gchar *problem;
GtkTreeModel *model;
GtkTreeIter iter;
frame_info *fInfo;
gint id=-1;
compstat_t *cs=(compstat_t*)user_data;
if(gtk_tree_selection_get_selected(sel, &model, &iter)){
gtk_tree_model_get(model, &iter, 0, &id, 1, &problem, -1);
if (id<0) return;
if(strcmp("Start scanning",problem)==0){
cf_goto_frame(&cfile, cs->start_packet_nr_first);
return;
}
if(strcmp("Stop scanning",problem)==0){
cf_goto_frame(&cfile, cs->stop_packet_nr_first);
return;
}
fInfo=(frame_info *)g_hash_table_lookup(cs->ip_id_set, GINT_TO_POINTER(id));
if(fInfo != NULL){
cf_goto_frame(&cfile, fInfo->num);
}
}
}
static void
setup_tree_view(GtkWidget *treeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("IP ID", renderer, "text", IP_ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (treeview), column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Problem", renderer, "text", PROBLEM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (treeview), column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Count", renderer, "text", COUNT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (treeview), column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Delta", renderer, "text", DELTA, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (treeview), column);
}
static void
gtk_comparestat_init(const char *opt_arg, void* userdata _U_)
{
compstat_t *cs;
char *display_name;
char *title_string;
char *filter_string;
GtkWidget *stat_label;
GtkWidget *filter_label;
GtkWidget *bbox;
GtkWidget *close_bt;
GtkWidget *help_bt;
GtkWidget *vbox;
gdouble variance;
gint start, stop,ttl, order, pos=0;
const char *filter=NULL;
GString *error_string;
if(sscanf(opt_arg,"compare,%d,%d,%d,%d,%lf%n",&start, &stop, &ttl, &order, &variance, &pos)==5){
if(pos){
if(*(opt_arg+pos)==',')
filter=opt_arg+pos+1;
else
filter=opt_arg+pos;
} else {
filter=NULL;
}
} else {
fprintf(stderr, "wireshark: invalid \"-z compare,<start>,<stop>,<ttl[0|1]>,<order[0|1]>,<variance>[,<filter>]\" argument\n");
exit(1);
}
compare_variance=variance;
compare_start=start;
compare_stop=stop;
TTL_method=ttl;
ON_method=order;
cs=(compstat_t *)g_malloc(sizeof(compstat_t));
nstime_set_unset(&cs->current_time);
cs->ip_ttl_list=g_array_new(FALSE, FALSE, sizeof(guint8));
cs->last_hit=FALSE;
cs->start_ongoing_hits=0;
cs->stop_ongoing_hits=0;
cs->start_packet_nr_first=G_MAXINT32;
cs->start_packet_nr_second=G_MAXINT32;
cs->stop_packet_nr_first=G_MAXINT32;
cs->stop_packet_nr_second=G_MAXINT32;
cs->first_file_amount=0;
cs->second_file_amount=0;
cs->zebra_time.secs=0;
cs->zebra_time.nsecs=1;
cs->nr_set=g_hash_table_new(NULL, NULL);
timestamp_set_precision(TS_PREC_AUTO_NSEC);
cs->win=dlg_window_new("compare-stat");
gtk_window_set_destroy_with_parent (GTK_WINDOW(cs->win), TRUE);
gtk_window_set_default_size(GTK_WINDOW(cs->win), 550, 400);
comparestat_set_title(cs);
vbox=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(cs->win), vbox);
gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
display_name = cf_get_display_name(&cfile);
title_string = g_strdup_printf("Compare two capture files: %s", display_name);
g_free(display_name);
stat_label=gtk_label_new(title_string);
g_free(title_string);
gtk_box_pack_start(GTK_BOX(vbox), stat_label, FALSE, FALSE, 0);
filter_string = g_strdup_printf("Filter: %s", filter ? filter : "");
filter_label=gtk_label_new(filter_string);
g_free(filter_string);
gtk_label_set_line_wrap(GTK_LABEL(filter_label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), filter_label, FALSE, FALSE, 0);
cs->statis_label=gtk_label_new("Statistics:");
gtk_label_set_line_wrap(GTK_LABEL(cs->statis_label), TRUE);
gtk_box_pack_start(GTK_BOX(vbox), cs->statis_label, FALSE, FALSE, 0);
gtk_widget_show_all(cs->win);
cs->treeview=gtk_tree_view_new();
setup_tree_view(cs->treeview);
cs->simple_list=gtk_tree_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_DOUBLE);
gtk_tree_view_set_model(GTK_TREE_VIEW (cs->treeview), GTK_TREE_MODEL (cs->simple_list));
g_object_unref(cs->simple_list);
gtk_tree_selection_set_mode(gtk_tree_view_get_selection(GTK_TREE_VIEW(cs->treeview)),GTK_SELECTION_SINGLE);
g_signal_connect(gtk_tree_view_get_selection(GTK_TREE_VIEW(cs->treeview)), "changed", G_CALLBACK(new_tree_view_selection_changed), cs);
cs->scrolled_win=gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(cs->scrolled_win), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(cs->scrolled_win), cs->treeview);
gtk_box_pack_start(GTK_BOX(vbox), cs->scrolled_win, TRUE, TRUE, 0);
cs->packet_set=g_hash_table_new(NULL, NULL);
error_string=register_tap_listener("ip", cs, filter, 0, comparestat_reset, comparestat_packet, comparestat_draw);
if(error_string){
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
gtk_tree_store_clear(cs->simple_list);
g_hash_table_destroy(cs->packet_set);
g_free(cs);
return;
}
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_end(GTK_BOX(vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(cs->win, close_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_COMPARE_FILES_DIALOG);
g_signal_connect(cs->win, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(cs->win, "destroy", G_CALLBACK(win_destroy_cb), cs);
gtk_widget_show_all(cs->win);
window_present(cs->win);
cf_retap_packets(&cfile);
}
static void
comparestat_start_button_clicked(GtkWidget *item _U_, gpointer data _U_)
{
GString *str;
const char *filter;
compare_start=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_start_int));
compare_stop=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_stop_int));
compare_variance=gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin_var_int));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_TTL))){
TTL_method=TRUE;
} else {
TTL_method=FALSE;
}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_ON))){
ON_method=TRUE;
} else {
ON_method=FALSE;
}
str = g_string_new("compare");
g_string_append_printf(str, ",%d,%d,%d,%d,%lf",compare_start, compare_stop, TTL_method, ON_method, compare_variance);
filter=gtk_entry_get_text(GTK_ENTRY(filter_entry));
if(filter[0]!=0){
g_string_append_printf(str, ",%s", filter);
}
if(first_window){
first_window = FALSE;
gtk_comparestat_init(str->str,NULL);
} else {
report_failure("cannot open more than one compare of the same type at once");
}
g_string_free(str, TRUE);
}
static void
dlg_destroy_cb(GtkWidget *w _U_, gpointer user_data _U_)
{
dlg=NULL;
}
void
gtk_comparestat_cb(GtkAction *action _U_, gpointer user_data _U_)
{
GtkAdjustment *start_integer, *stop_integer, *var_integer;
GtkWidget *dlg_box;
GtkWidget *spin_start_label, *spin_stop_label, *spin_start_box, *spin_stop_box;
GtkWidget *spin_var_box, *spin_var_label;
GtkWidget *order_box, *radio_MAC, *order_label;
GtkWidget *differ_box, *radio_OFF, *differ_label;
GtkWidget *filter_box, *filter_bt;
GtkWidget *bbox, *start_button, *cancel_button;
const char *filter;
static construct_args_t args = {
"Compare statistics",
TRUE,
FALSE,
FALSE
};
if(dlg){
gdk_window_raise(gtk_widget_get_window(dlg));
return;
}
dlg=dlg_window_new("Wireshark: Compare two capture files");
gtk_window_set_default_size(GTK_WINDOW(dlg), 300, -1);
dlg_box=ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(dlg_box), 10);
gtk_container_add(GTK_CONTAINER(dlg), dlg_box);
gtk_widget_show(dlg_box);
spin_start_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
spin_stop_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(spin_start_box), 1);
spin_start_label=gtk_label_new("Start compare:");
gtk_box_pack_start(GTK_BOX(spin_start_box), spin_start_label, FALSE, FALSE, 0);
gtk_widget_show(spin_start_label);
gtk_container_set_border_width(GTK_CONTAINER(spin_stop_box), 1);
spin_stop_label=gtk_label_new("Stop compare: ");
gtk_box_pack_start(GTK_BOX(spin_stop_box), spin_stop_label, FALSE, FALSE, 0);
gtk_widget_show(spin_stop_label);
start_integer=GTK_ADJUSTMENT(gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 5.0, 0.0));
stop_integer=GTK_ADJUSTMENT(gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 5.0, 0.0));
spin_start_int=gtk_spin_button_new(start_integer, 1.0, 0);
spin_stop_int=gtk_spin_button_new(stop_integer, 1.0, 0);
gtk_box_pack_start(GTK_BOX(spin_start_box), spin_start_int, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(spin_stop_box), spin_stop_int, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(dlg_box), spin_start_box, FALSE, FALSE, 0);
gtk_widget_show(spin_start_box);
gtk_box_pack_start(GTK_BOX(dlg_box), spin_stop_box, FALSE, FALSE, 0);
gtk_widget_show(spin_stop_box);
differ_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(differ_box), 1);
differ_label=gtk_label_new("Endpoint distinction:");
gtk_box_pack_start(GTK_BOX(differ_box), differ_label, FALSE, FALSE, 0);
gtk_widget_show(differ_label);
radio_MAC=gtk_radio_button_new_with_label (NULL, "MAC");
radio_TTL=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(radio_MAC), "TTL");
gtk_box_pack_start(GTK_BOX(differ_box), radio_MAC, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(differ_box), radio_TTL, TRUE, TRUE, 0);
gtk_widget_show(radio_MAC);
gtk_widget_show(radio_TTL);
gtk_box_pack_start(GTK_BOX(dlg_box), differ_box, FALSE, FALSE, 0);
gtk_widget_show(differ_box);
order_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(order_box), 1);
order_label=gtk_label_new("Check order: ");
gtk_box_pack_start(GTK_BOX(order_box), order_label, FALSE, FALSE, 0);
gtk_widget_show(order_label);
radio_ON=gtk_radio_button_new_with_label (NULL, "On");
radio_OFF=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(radio_ON), "Off");
gtk_box_pack_start(GTK_BOX(order_box), radio_ON, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(order_box), radio_OFF, TRUE, TRUE, 0);
gtk_widget_show(radio_ON);
gtk_widget_show(radio_OFF);
gtk_box_pack_start(GTK_BOX(dlg_box), order_box, FALSE, FALSE, 0);
gtk_widget_show(order_box);
spin_var_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(spin_var_box), 1);
spin_var_label=gtk_label_new("Time variance (sec +/-):");
gtk_box_pack_start(GTK_BOX(spin_var_box), spin_var_label, FALSE, FALSE, 0);
gtk_widget_show(spin_var_label);
var_integer=GTK_ADJUSTMENT(gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 5.0, 0.0));
spin_var_int=gtk_spin_button_new(var_integer, 0.0, 2);
gtk_box_pack_start(GTK_BOX(spin_var_box), spin_var_int, TRUE, TRUE, 0);
gtk_widget_show(spin_var_int);
gtk_box_pack_start(GTK_BOX(dlg_box), spin_var_box, FALSE, FALSE, 0);
gtk_widget_show(spin_var_box);
filter_box=ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3, FALSE);
filter_bt=ws_gtk_button_new_from_stock(WIRESHARK_STOCK_DISPLAY_FILTER_ENTRY);
g_signal_connect(filter_bt, "clicked", G_CALLBACK(display_filter_construct_cb), &args);
gtk_box_pack_start(GTK_BOX(filter_box), filter_bt, FALSE, TRUE, 0);
gtk_widget_show(filter_bt);
filter_entry=gtk_entry_new();
g_signal_connect(filter_entry, "changed", G_CALLBACK(filter_te_syntax_check_cb), NULL);
g_object_set_data(G_OBJECT(filter_box), E_FILT_AUTOCOMP_PTR_KEY, NULL);
g_signal_connect(filter_entry, "key-press-event", G_CALLBACK (filter_string_te_key_pressed_cb), NULL);
g_signal_connect(dlg, "key-press-event", G_CALLBACK (filter_parent_dlg_key_pressed_cb), NULL);
g_object_set_data(G_OBJECT(filter_bt), E_FILT_TE_PTR_KEY, filter_entry);
gtk_box_pack_start(GTK_BOX(filter_box), filter_entry, TRUE, TRUE, 0);
filter=gtk_entry_get_text(GTK_ENTRY(main_display_filter_widget));
if(filter){
gtk_entry_set_text(GTK_ENTRY(filter_entry), filter);
}
gtk_widget_show(filter_entry);
gtk_box_pack_start(GTK_BOX(dlg_box), filter_box, TRUE, TRUE, 0);
gtk_widget_show(filter_box);
bbox = dlg_button_row_new(WIRESHARK_STOCK_CREATE_STAT, GTK_STOCK_CANCEL, NULL);
gtk_box_pack_start(GTK_BOX(dlg_box), bbox, FALSE, FALSE, 0);
gtk_widget_show(bbox);
start_button = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), WIRESHARK_STOCK_CREATE_STAT);
g_signal_connect_swapped(start_button, "clicked", G_CALLBACK(comparestat_start_button_clicked), NULL);
cancel_button = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CANCEL);
window_set_cancel_button(dlg, cancel_button, window_cancel_button_cb);
gtk_widget_grab_focus(filter_entry);
gtk_widget_grab_default(start_button );
g_signal_connect(dlg, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(dlg, "destroy", G_CALLBACK(dlg_destroy_cb), NULL);
gtk_widget_show_all(dlg);
window_present(dlg);
}
void
register_tap_listener_gtkcomparestat(void)
{
register_stat_cmd_arg("compare", gtk_comparestat_init, NULL);
}
