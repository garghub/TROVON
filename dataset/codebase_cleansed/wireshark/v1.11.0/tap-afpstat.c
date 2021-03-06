static int
afpstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *prv)
{
afpstat_t *ss=(afpstat_t *)pss;
const afp_request_val *request_val=(const afp_request_val *)prv;
nstime_t t, deltat;
timestat_t *sp=NULL;
if(!request_val){
return 0;
}
sp=&(ss->proc[request_val->command]);
t=pinfo->fd->abs_ts;
nstime_delta(&deltat, &t, &request_val->req_time);
if(sp){
time_stat_update(sp,&deltat, pinfo);
}
return 1;
}
static void
afpstat_draw(void *pss)
{
afpstat_t *ss=(afpstat_t *)pss;
guint32 i;
guint64 td;
printf("\n");
printf("===================================================================\n");
printf("AFP SRT Statistics:\n");
printf("Filter: %s\n",ss->filter?ss->filter:"");
printf("Commands Calls Min SRT Max SRT Avg SRT\n");
for(i=0;i<256;i++){
if(ss->proc[i].num==0){
continue;
}
td=ss->proc[i].tot.secs;
td=td*100000+(int)ss->proc[i].tot.nsecs/10000;
if(ss->proc[i].num){
td/=ss->proc[i].num;
} else {
td=0;
}
printf("%-25s %6d %3d.%05d %3d.%05d %3" G_GINT64_MODIFIER "u.%05" G_GINT64_MODIFIER "u\n",
val_to_str_ext(i, &CommandCode_vals_ext, "Unknown (%u)"),
ss->proc[i].num,
(int)ss->proc[i].min.secs,ss->proc[i].min.nsecs/10000,
(int)ss->proc[i].max.secs,ss->proc[i].max.nsecs/10000,
td/100000, td%100000
);
}
printf("===================================================================\n");
}
static void
afpstat_init(const char *opt_arg, void* userdata _U_)
{
afpstat_t *ss;
guint32 i;
const char *filter=NULL;
GString *error_string;
if(!strncmp(opt_arg,"afp,srt,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
ss=g_new(afpstat_t,1);
if(filter){
ss->filter=g_strdup(filter);
} else {
ss->filter=NULL;
}
for(i=0;i<256;i++){
ss->proc[i].num=0;
ss->proc[i].min_num=0;
ss->proc[i].max_num=0;
ss->proc[i].min.secs=0;
ss->proc[i].min.nsecs=0;
ss->proc[i].max.secs=0;
ss->proc[i].max.nsecs=0;
ss->proc[i].tot.secs=0;
ss->proc[i].tot.nsecs=0;
}
error_string=register_tap_listener("afp", ss, filter, 0, NULL, afpstat_packet, afpstat_draw);
if(error_string){
g_free(ss->filter);
g_free(ss);
fprintf(stderr, "tshark: Couldn't register afp,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_afpstat(void)
{
register_stat_cmd_arg("afp,srt", afpstat_init,NULL);
}
