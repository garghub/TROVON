static void camelsrt_reset(void *phs)
{
struct camelsrt_t *hs=(struct camelsrt_t *)phs;
memset(hs,0,sizeof(struct camelsrt_t));
}
static int camelsrt_packet(void *phs,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *phi)
{
struct camelsrt_t *hs=(struct camelsrt_t *)phs;
const struct camelsrt_info_t * pi=phi;
int i;
for (i=0; i<NB_CAMELSRT_CATEGORY; i++) {
if (pi->bool_msginfo[i] &&
pi->msginfo[i].is_delta_time
&& pi->msginfo[i].request_available
&& !pi->msginfo[i].is_duplicate ) {
time_stat_update(&(hs->stats[i]),
&(pi->msginfo[i].delta_time),
pinfo);
if (hs->count[i] < NUM_RAS_STATS) {
hs->delta_time[i][hs->count[i]++]
= pi->msginfo[i].delta_time;
}
}
}
return 1;
}
static void camelsrt_draw(void *phs)
{
struct camelsrt_t *hs=(struct camelsrt_t *)phs;
guint j,z;
guint32 li;
int somme,iteration=0;
timestat_t *rtd_temp;
double x,delay,delay_max,delay_min,delta;
double criteria[NB_CRITERIA]={ 5.0, 10.0, 75.0, 90.0, 95.0,99.0,99.90 };
double delay_criteria[NB_CRITERIA];
printf("\n");
printf("Camel Service Response Time (SRT) Statistics:\n");
printf("=================================================================================================\n");
printf("| Category | Measure | Min SRT | Max SRT | Avg SRT | Min frame | Max frame |\n");
printf("|-------------------------|---------|-----------|-----------|-----------|-----------|-----------|\n");
j=1;
printf("|%24s |%8u |%8.2f s |%8.2f s |%8.2f s |%10u |%10u |\n",
val_to_str(j,camelSRTtype_naming,"Unknown Message 0x%02x"),
hs->stats[j].num,
nstime_to_sec(&(hs->stats[j].min)),
nstime_to_sec(&(hs->stats[j].max)),
get_average(&(hs->stats[j].tot),hs->stats[j].num)/1000.0,
hs->stats[j].min_num,
hs->stats[j].max_num
);
for(j=2; j<NB_CAMELSRT_CATEGORY; j++) {
if(hs->stats[j].num==0){
printf("|%24s |%8u |%8.2f ms|%8.2f ms|%8.2f ms|%10u |%10u |\n",
val_to_str(j,camelSRTtype_naming,"Unknown Message 0x%02x"),
0, 0.0, 0.0, 0.0, 0, 0);
continue;
}
printf("|%24s |%8u |%8.2f ms|%8.2f ms|%8.2f ms|%10u |%10u |\n",
val_to_str(j,camelSRTtype_naming,"Unknown Message 0x%02x"),
hs->stats[j].num,
MIN(9999,nstime_to_msec(&(hs->stats[j].min))),
MIN(9999,nstime_to_msec(&(hs->stats[j].max))),
MIN(9999,get_average(&(hs->stats[j].tot),hs->stats[j].num)),
hs->stats[j].min_num,
hs->stats[j].max_num
);
}
printf("=================================================================================================\n");
printf("| Category/Criteria |");
for(z=0; z<NB_CRITERIA; z++) printf("%7.2f%% |", criteria[z]);
printf("\n");
printf("|-------------------------|");
for(z=0; z<NB_CRITERIA; z++) printf("---------|");
printf("\n");
for(j=2;j<NB_CAMELSRT_CATEGORY;j++) {
rtd_temp = &(hs->stats[j]);
if (hs->count[j]>0) {
for(z=0; z<NB_CRITERIA; z++) {
iteration=0;
delay_max=(double)rtd_temp->max.secs*1000 +(double)rtd_temp->max.nsecs/1000000;
delay_min=(double)rtd_temp->min.secs*1000 +(double)rtd_temp->min.nsecs/1000000;
delay=delay_min;
delta=delay_max-delay_min;
while( (delta > 0.001) && (iteration < 10000) ) {
somme=0;
iteration++;
for(li=0;li<hs->count[j];li++) {
x=hs->delta_time[j][li].secs*1000
+ (double)hs->delta_time[j][li].nsecs/1000000;
if (x <= delay) somme++;
}
if ( somme*100 > hs->count[j]*criteria[z] ) {
delay_max=delay;
delay=(delay_max+delay_min)/2;
delta=delay_max-delay_min;
} else {
delay_min=delay;
delay=(delay_max+delay_min)/2;
delta=delay_max-delay_min;
}
}
delay_criteria[z]=delay;
}
printf("X%24s |", val_to_str(j, camelSRTtype_naming, "Unknown") );
for(z=0; z<NB_CRITERIA; z++) printf("%8.2f |", MIN(9999,delay_criteria[z]));
printf("\n");
} else {
printf("X%24s |", val_to_str(j, camelSRTtype_naming, "Unknown") );
for(z=0; z<NB_CRITERIA; z++) printf("%8.2f |", 0.0);
printf("\n");
}
}
printf("===========================");
for(z=0; z<NB_CRITERIA; z++) printf("==========");
printf("\n");
}
static void camelsrt_init(const char *optarg, void* userdata _U_)
{
struct camelsrt_t *p_camelsrt;
GString *error_string;
p_camelsrt = g_malloc(sizeof(struct camelsrt_t));
if(!strncmp(optarg,"camel,srt,",9)){
p_camelsrt->filter=g_strdup(optarg+9);
} else {
p_camelsrt->filter=NULL;
}
camelsrt_reset(p_camelsrt);
error_string=register_tap_listener("CAMEL",
p_camelsrt,
p_camelsrt->filter,
0,
NULL,
camelsrt_packet,
camelsrt_draw);
if(error_string){
g_free(p_camelsrt->filter);
g_free(p_camelsrt);
fprintf(stderr, "tshark: Couldn't register camel,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
gtcap_StatSRT=TRUE;
gcamel_StatSRT=TRUE;
}
void
register_tap_listener_camelsrt(void)
{
register_stat_cmd_arg("camel,srt", camelsrt_init, NULL);
}
