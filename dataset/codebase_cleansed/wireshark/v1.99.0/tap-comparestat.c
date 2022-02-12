static void
comparestat_reset(void *dummy _U_)
{
}
static int
comparestat_packet(void *arg, packet_info *pinfo, epan_dissect_t *edt _U_, const void *arg2)
{
comparestat_t *cs=(comparestat_t *)arg;
const ws_ip *ci=(const ws_ip *)arg2;
frame_info *fInfo;
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
fInfo=(frame_info*)se_alloc(sizeof(frame_info));
fInfo->fp=(for_print*)se_alloc(sizeof(for_print));
fInfo->fp->partner=NULL;
fInfo->fp->count=1;
fInfo->fp->cksum=computed_cksum;
fInfo->num=pinfo->fd->num;
fInfo->id=ci->ip_id;
fInfo->ip_ttl=ci->ip_ttl;
fInfo->dl_dst=pinfo->dl_dst;
fInfo->abs_ts=pinfo->fd->abs_ts;
nstime_set_zero(&fInfo->zebra_time);
nstime_set_zero(&fInfo->fp->predecessor_time);
g_hash_table_insert(cs->packet_set, GINT_TO_POINTER(pinfo->fd->num), fInfo);
return 1;
}
static void
call_foreach_count_ip_id(gpointer key _U_, gpointer value, gpointer arg)
{
comparestat_t *cs=(comparestat_t*)arg;
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
fInfo->fp->count=1;
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
fInfo->fp->count=fInfoTemp->fp->count + 1;
if(fInfoTemp->fp->cksum!=fInfo->fp->cksum){
fInfo->fp->cksum=WRONG_CHKSUM;
fInfoTemp->fp->cksum=WRONG_CHKSUM;
}
fInfo->fp->partner=fInfoTemp;
if(fInfo->fp->count==MERGED_FILES){
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
comparestat_t *cs=(comparestat_t*)arg;
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
fInfo->fp->predecessor_time.nsecs=cs->current_time.nsecs;
}
cs->current_time.nsecs=fInfo->zebra_time.nsecs;
}
static void
call_foreach_merge_settings(gpointer key _U_, gpointer value, gpointer arg)
{
comparestat_t *cs=(comparestat_t*)arg;
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
printf("ERROR: start number not set correctly\n");
return;
}
if(fmod(fInfoTemp->zebra_time.nsecs, 2)){
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
printf("Start point couldn't be set, choose a lower compare start");
}
}
}
static void
call_foreach_print_ip_tree(gpointer key _U_, gpointer value, gpointer user_data)
{
frame_info *fInfo=(frame_info*)value;
comparestat_t *cs=(comparestat_t*)user_data;
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
if(fInfo->fp->count < MERGED_FILES){
printf("Packet id :%i, count:%i Problem:", fInfo->id, fInfo->fp->count);
printf("Packet lost\n");
}
if(fInfo->fp->count > MERGED_FILES){
printf("Packet id :%i, count:%i Problem:", fInfo->id, fInfo->fp->count);
printf("More than two packets\n");
if(fInfo->fp->cksum == WRONG_CHKSUM){
printf("Checksum error over IP header\n");
}
}
if(fInfo->fp->count == MERGED_FILES){
if(fInfo->fp->cksum == WRONG_CHKSUM){
printf("Packet id :%i, count:%i Problem:", fInfo->id, fInfo->fp->count);
printf("Checksum error over IP header\n");
if(((delta < (average-cs->stats.variance)) || (delta > (average+cs->stats.variance))) && (delta > 0.0) && (cs->stats.variance!=0)){
printf("Not arrived in time\n");
}
if((nstime_cmp(&fInfo->fp->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fp->partner->fp->predecessor_time, &fInfo->fp->partner->zebra_time)>0) && (fInfo->zebra_time.nsecs!=MERGED_FILES) && ON_method){
printf("Not correct order\n");
}
} else if(((delta < (average-cs->stats.variance)) || (delta > (average+cs->stats.variance))) && (delta > 0.0) && (cs->stats.variance!=0)) {
printf("Packet id :%i, count:%i Problem:", fInfo->id, fInfo->fp->count);
printf("Package not arrived in time\n");
if((nstime_cmp(&fInfo->fp->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fp->partner->fp->predecessor_time, &fInfo->fp->partner->zebra_time)>0) && fInfo->zebra_time.nsecs != MERGED_FILES && ON_method){
printf("Not correct order\n");
}
} else if((nstime_cmp(&fInfo->fp->predecessor_time, &fInfo->zebra_time)>0||nstime_cmp(&fInfo->fp->partner->fp->predecessor_time, &fInfo->fp->partner->zebra_time)>0) && fInfo->zebra_time.nsecs != MERGED_FILES && ON_method){
printf("Packet id :%i, count:%i Problem:", fInfo->id, fInfo->fp->count);
printf("Not correct order\n");
}
}
}
}
static void
comparestat_draw(void *prs)
{
comparestat_t *cs=(comparestat_t *)prs;
GString *filter_str = g_string_new("");
const gchar *statis_string;
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
cs->stats.variance=compare_variance;
statis_string=g_strdup_printf("Compare Statistics: \nFilter: %s\nNumber of packets total:%i 1st file:%i, 2nd file:%i\nScopes:\t start:%i stop:%i\nand:\t start:%i stop:%i\nEqual packets: %i \nAllowed variation: %f \nAverage time difference: %f\n", cs->filter ? cs->filter : "", (first_file_amount+second_file_amount), first_file_amount, second_file_amount, cs->start_packet_nr_first, cs->stop_packet_nr_first, cs->start_packet_nr_second, cs->stop_packet_nr_second, cs->stats.num, cs->stats.variance, fabs(get_average(&cs->stats.tot, cs->stats.num)));
printf("\n");
printf("===================================================================\n");
printf("%s", statis_string);
g_hash_table_foreach(cs->ip_id_set, call_foreach_print_ip_tree, cs);
printf("===================================================================\n");
g_string_free(filter_str, TRUE);
g_hash_table_destroy(cs->ip_id_set);
g_array_free(cs->ip_ttl_list, TRUE);
}
static void
comparestat_init(const char *opt_arg, void* userdata _U_)
{
comparestat_t *cs;
const char *filter=NULL;
GString *error_string;
gint start, stop,ttl, order, pos=0;
gdouble variance;
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
fprintf(stderr, "tshark: invalid \"-z compare,<start>,<stop>,<ttl[0|1]>,<order[0|1]>,<variance>[,<filter>]\" argument\n");
exit(1);
}
compare_variance=variance;
compare_start=start;
compare_stop=stop;
TTL_method=ttl;
ON_method=order;
cs=g_new(comparestat_t,1);
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
if(filter){
cs->filter=g_strdup(filter);
} else {
cs->filter=NULL;
}
cs->packet_set=g_hash_table_new(NULL, NULL);
error_string=register_tap_listener("ip", cs, filter, 0, comparestat_reset, comparestat_packet, comparestat_draw);
if(error_string){
g_free(cs->filter);
g_hash_table_destroy(cs->packet_set);
g_free(cs);
fprintf(stderr, "tshark: Couldn't register compare tap: %s\n", error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_comparestat(void)
{
register_stat_cmd_arg("compare,", comparestat_init,NULL);
}
