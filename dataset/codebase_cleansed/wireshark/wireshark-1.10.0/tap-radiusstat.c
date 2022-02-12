static int
radiusstat_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
radiusstat_t *rs=(radiusstat_t *)prs;
const radius_info_t *ri=(const radius_info_t *)pri;
nstime_t delta;
int ret = 0;
switch (ri->code) {
case RADIUS_PKT_TYPE_ACCESS_REQUEST:
case RADIUS_PKT_TYPE_ACCOUNTING_REQUEST:
case RADIUS_PKT_TYPE_PASSWORD_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_FREE_REQUEST:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_REQUEST:
case RADIUS_PKT_TYPE_NAS_REBOOT_REQUEST:
case RADIUS_PKT_TYPE_EVENT_REQUEST:
case RADIUS_PKT_TYPE_DISCONNECT_REQUEST:
case RADIUS_PKT_TYPE_COA_REQUEST:
if(ri->is_duplicate){
rs->req_dup_num++;
}
else {
rs->open_req_num++;
}
break;
case RADIUS_PKT_TYPE_ACCESS_ACCEPT:
case RADIUS_PKT_TYPE_ACCESS_REJECT:
case RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE:
case RADIUS_PKT_TYPE_PASSWORD_ACK:
case RADIUS_PKT_TYPE_PASSWORD_REJECT:
case RADIUS_PKT_TYPE_RESOURCE_FREE_RESPONSE:
case RADIUS_PKT_TYPE_RESOURCE_QUERY_RESPONSE:
case RADIUS_PKT_TYPE_NAS_REBOOT_RESPONSE:
case RADIUS_PKT_TYPE_EVENT_RESPONSE:
case RADIUS_PKT_TYPE_DISCONNECT_ACK:
case RADIUS_PKT_TYPE_DISCONNECT_NAK:
case RADIUS_PKT_TYPE_COA_ACK:
case RADIUS_PKT_TYPE_COA_NAK:
if(ri->is_duplicate){
rs->rsp_dup_num++;
}
else if (!ri->request_available) {
rs->disc_rsp_num++;
}
else {
rs->open_req_num--;
nstime_delta(&delta, &pinfo->fd->abs_ts, &ri->req_time);
time_stat_update(&(rs->rtd[RADIUS_CAT_OVERALL]),&delta, pinfo);
if (ri->code == RADIUS_PKT_TYPE_ACCESS_ACCEPT || ri->code == RADIUS_PKT_TYPE_ACCESS_REJECT) {
time_stat_update(&(rs->rtd[RADIUS_CAT_ACCESS]),&delta, pinfo);
}
else if (ri->code == RADIUS_PKT_TYPE_ACCOUNTING_RESPONSE) {
time_stat_update(&(rs->rtd[RADIUS_CAT_ACCOUNTING]),&delta, pinfo);
}
else {
time_stat_update(&(rs->rtd[RADIUS_CAT_OTHERS]),&delta, pinfo);
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
radiusstat_draw(void *prs)
{
radiusstat_t *rs=(radiusstat_t *)prs;
int i;
printf("\n");
printf("===========================================================================================================\n");
printf("RADIUS Response Time Delay (RTD) Statistics:\n");
printf("Filter for statistics: %s\n",rs->filter?rs->filter:"");
printf("Duplicate requests: %u\n",rs->req_dup_num);
printf("Duplicate responses: %u\n",rs->rsp_dup_num);
printf("Open requests: %u\n",rs->open_req_num);
printf("Discarded responses: %u\n",rs->disc_rsp_num);
printf("Type | Messages | Min RTD | Max RTD | Avg RTD | Min in Frame | Max in Frame |\n");
for(i=0;i<RADIUS_CAT_NUM_TIMESTATS;i++) {
if(rs->rtd[i].num) {
printf("%s | %7u | %8.2f msec | %8.2f msec | %8.2f msec | %10u | %10u |\n",
val_to_str(i,radius_message_code,"Other "),rs->rtd[i].num,
nstime_to_msec(&(rs->rtd[i].min)), nstime_to_msec(&(rs->rtd[i].max)),
get_average(&(rs->rtd[i].tot), rs->rtd[i].num),
rs->rtd[i].min_num, rs->rtd[i].max_num
);
}
}
printf("===========================================================================================================\n");
}
static void
radiusstat_init(const char *optarg, void* userdata _U_)
{
radiusstat_t *rs;
int i;
GString *error_string;
rs=g_new(radiusstat_t,1);
if(!strncmp(optarg,"radius,rtd,",11)){
rs->filter=g_strdup(optarg+11);
} else {
rs->filter=NULL;
}
for(i=0;i<RADIUS_CAT_NUM_TIMESTATS;i++) {
rs->rtd[i].num=0;
rs->rtd[i].min_num=0;
rs->rtd[i].max_num=0;
rs->rtd[i].min.secs=0;
rs->rtd[i].min.nsecs=0;
rs->rtd[i].max.secs=0;
rs->rtd[i].max.nsecs=0;
rs->rtd[i].tot.secs=0;
rs->rtd[i].tot.nsecs=0;
}
rs->open_req_num=0;
rs->disc_rsp_num=0;
rs->req_dup_num=0;
rs->rsp_dup_num=0;
error_string=register_tap_listener("radius", rs, rs->filter, 0, NULL, radiusstat_packet, radiusstat_draw);
if(error_string){
g_free(rs->filter);
g_free(rs);
fprintf(stderr, "tshark: Couldn't register radius,rtd tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_radiusstat(void)
{
register_stat_cmd_arg("radius,rtd", radiusstat_init, NULL);
}
