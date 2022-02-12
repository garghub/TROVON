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
const h225_packet_info *pi=(const h225_packet_info *)phi;
ras_type rasmsg_type = RAS_OTHER;
ras_category rascategory = RAS_OTHERS;
if (pi->msg_type != H225_RAS || pi->msg_tag == -1) {
return 0;
}
if (pi->msg_tag < 21) {
rascategory = (ras_category)(pi->msg_tag / 3);
rasmsg_type = (ras_type)(pi->msg_tag % 3);
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
timestat_t *rtd_temp;
printf("======================================== H225 RAS Service Response Time ========================================\n");
printf("H225 RAS Service Response Time (SRT) Statistics:\n");
printf("RAS-Messages | Measurements | Min SRT | Max SRT | Avg SRT | Min in Frame | Max in Frame |\n");
for(i=0;i<NUM_RAS_STATS;i++) {
rtd_temp = &(hs->ras_rtd[i].stats);
if(rtd_temp->num){
printf("%s | %10u | %9.2f msec | %9.2f msec | %9.2f msec | %10u | %10u |\n",
val_to_str(i,ras_message_category,"Unknown "),rtd_temp->num,
nstime_to_msec(&(rtd_temp->min)), nstime_to_msec(&(rtd_temp->max)),
get_average(&(rtd_temp->tot), rtd_temp->num),
rtd_temp->min_num, rtd_temp->max_num
);
}
}
printf("================================================================================================================\n");
printf("RAS-Messages | Open REQ | Discarded RSP | Repeated REQ | Repeated RSP |\n");
for(i=0;i<NUM_RAS_STATS;i++) {
rtd_temp = &(hs->ras_rtd[i].stats);
if(rtd_temp->num){
printf("%s | %10u | %10u | %10u | %10u |\n",
val_to_str(i,ras_message_category,"Unknown "),
hs->ras_rtd[i].open_req_num, hs->ras_rtd[i].disc_rsp_num,
hs->ras_rtd[i].req_dup_num, hs->ras_rtd[i].rsp_dup_num
);
}
}
printf("================================================================================================================\n");
}
static void
h225rassrt_init(const char *optarg, void* userdata _U_)
{
h225rassrt_t *hs;
GString *error_string;
hs = g_new(h225rassrt_t,1);
if(!strncmp(optarg,"h225,srt,",9)){
hs->filter=g_strdup(optarg+9);
} else {
hs->filter=NULL;
}
h225rassrt_reset(hs);
error_string=register_tap_listener("h225", hs, hs->filter, 0, NULL, h225rassrt_packet, h225rassrt_draw);
if(error_string){
g_free(hs->filter);
g_free(hs);
fprintf(stderr, "tshark: Couldn't register h225,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_h225rassrt(void)
{
register_stat_cmd_arg("h225,srt", h225rassrt_init,NULL);
}
