static int
mgcpstat_packet(void *pms, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pmi)
{
mgcpstat_t *ms=(mgcpstat_t *)pms;
const mgcp_info_t *mi=pmi;
nstime_t delta;
int ret = 0;
switch (mi->mgcp_type) {
case MGCP_REQUEST:
if(mi->is_duplicate){
ms->req_dup_num++;
}
else {
ms->open_req_num++;
}
break;
case MGCP_RESPONSE:
if(mi->is_duplicate){
ms->rsp_dup_num++;
}
else if (!mi->request_available) {
ms->disc_rsp_num++;
}
else {
ms->open_req_num--;
nstime_delta(&delta, &pinfo->fd->abs_ts, &mi->req_time);
time_stat_update(&(ms->rtd[0]),&delta, pinfo);
if (g_ascii_strncasecmp(mi->code, "EPCF", 4) == 0 ) {
time_stat_update(&(ms->rtd[1]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "CRCX", 4) == 0 ) {
time_stat_update(&(ms->rtd[2]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "MDCX", 4) == 0 ) {
time_stat_update(&(ms->rtd[3]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "DLCX", 4) == 0 ) {
time_stat_update(&(ms->rtd[4]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "RQNT", 4) == 0 ) {
time_stat_update(&(ms->rtd[5]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "NTFY", 4) == 0 ) {
time_stat_update(&(ms->rtd[6]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "AUEP", 4) == 0 ) {
time_stat_update(&(ms->rtd[7]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "AUCX", 4) == 0 ) {
time_stat_update(&(ms->rtd[8]),&delta, pinfo);
}
else if (g_ascii_strncasecmp(mi->code, "RSIP", 4) == 0 ) {
time_stat_update(&(ms->rtd[9]),&delta, pinfo);
}
else {
time_stat_update(&(ms->rtd[10]),&delta, pinfo);
}
ret = 1;
}
break;
default:
break;
}
return ret;
}
static void
mgcpstat_draw(void *pms)
{
mgcpstat_t *ms=(mgcpstat_t *)pms;
int i;
printf("\n");
printf("=====================================================================================================\n");
printf("MGCP Response Time Delay (RTD) Statistics:\n");
printf("Filter for statistics: %s\n",ms->filter?ms->filter:"");
printf("Duplicate requests: %u\n",ms->req_dup_num);
printf("Duplicate responses: %u\n",ms->rsp_dup_num);
printf("Open requests: %u\n",ms->open_req_num);
printf("Discarded responses: %u\n",ms->disc_rsp_num);
printf("Type | Messages | Min RTD | Max RTD | Avg RTD | Min in Frame | Max in Frame |\n");
for(i=0;i<NUM_TIMESTATS;i++) {
if(ms->rtd[i].num) {
printf("%s | %7u | %8.2f msec | %8.2f msec | %8.2f msec | %10u | %10u |\n",
val_to_str(i,mgcp_mesage_type,"Other "),ms->rtd[i].num,
nstime_to_msec(&(ms->rtd[i].min)), nstime_to_msec(&(ms->rtd[i].max)),
get_average(&(ms->rtd[i].tot), ms->rtd[i].num),
ms->rtd[i].min_num, ms->rtd[i].max_num
);
}
}
printf("=====================================================================================================\n");
}
static void
mgcpstat_init(const char *optarg, void* userdata _U_)
{
mgcpstat_t *ms;
int i;
GString *error_string;
ms=g_malloc(sizeof(mgcpstat_t));
if(!strncmp(optarg,"mgcp,rtd,",9)){
ms->filter=g_strdup(optarg+9);
} else {
ms->filter=NULL;
}
for(i=0;i<NUM_TIMESTATS;i++) {
ms->rtd[i].num=0;
ms->rtd[i].min_num=0;
ms->rtd[i].max_num=0;
ms->rtd[i].min.secs=0;
ms->rtd[i].min.nsecs=0;
ms->rtd[i].max.secs=0;
ms->rtd[i].max.nsecs=0;
ms->rtd[i].tot.secs=0;
ms->rtd[i].tot.nsecs=0;
}
ms->open_req_num=0;
ms->disc_rsp_num=0;
ms->req_dup_num=0;
ms->rsp_dup_num=0;
error_string=register_tap_listener("mgcp", ms, ms->filter, 0, NULL, mgcpstat_packet, mgcpstat_draw);
if(error_string){
g_free(ms->filter);
g_free(ms);
fprintf(stderr, "tshark: Couldn't register mgcp,rtd tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_mgcpstat(void)
{
if (find_tap_id("mgcp")) {
register_stat_cmd_arg("mgcp,rtd", mgcpstat_init, NULL);
}
}
