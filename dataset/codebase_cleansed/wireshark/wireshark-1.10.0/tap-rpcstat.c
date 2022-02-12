static void
rpcstat_reset(void *prs)
{
rpcstat_t *rs=(rpcstat_t *)prs;
guint32 i;
for(i=0;i<rs->num_procedures;i++){
rs->procedures[i].num=0;
rs->procedures[i].min.secs=0;
rs->procedures[i].min.nsecs=0;
rs->procedures[i].max.secs=0;
rs->procedures[i].max.nsecs=0;
rs->procedures[i].tot.secs=0;
rs->procedures[i].tot.nsecs=0;
}
}
static int
rpcstat_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
rpcstat_t *rs=(rpcstat_t *)prs;
const rpc_call_info_value *ri=(const rpc_call_info_value *)pri;
nstime_t delta;
rpc_procedure_t *rp;
if(ri->proc>=rs->num_procedures){
return 0;
}
if(ri->request){
return 0;
}
if( (ri->prog!=rs->program) || (ri->vers!=rs->version) ){
return 0;
}
rp=&(rs->procedures[ri->proc]);
nstime_delta(&delta, &pinfo->fd->abs_ts, &ri->req_time);
if(rp->num==0){
rp->max.secs=delta.secs;
rp->max.nsecs=delta.nsecs;
}
if(rp->num==0){
rp->min.secs=delta.secs;
rp->min.nsecs=delta.nsecs;
}
if( (delta.secs<rp->min.secs)
||( (delta.secs==rp->min.secs)
&&(delta.nsecs<rp->min.nsecs) ) ){
rp->min.secs=delta.secs;
rp->min.nsecs=delta.nsecs;
}
if( (delta.secs>rp->max.secs)
||( (delta.secs==rp->max.secs)
&&(delta.nsecs>rp->max.nsecs) ) ){
rp->max.secs=delta.secs;
rp->max.nsecs=delta.nsecs;
}
rp->tot.secs += delta.secs;
rp->tot.nsecs += delta.nsecs;
if(rp->tot.nsecs > NANOSECS_PER_SEC){
rp->tot.nsecs -= NANOSECS_PER_SEC;
rp->tot.secs++;
}
rp->num++;
return 1;
}
static void
rpcstat_draw(void *prs)
{
rpcstat_t *rs=(rpcstat_t *)prs;
guint32 i;
guint64 td;
printf("\n");
printf("=======================================================\n");
printf("%s Version %d SRT Statistics:\n", rs->prog, rs->version);
printf("Filter: %s\n",rs->filter?rs->filter:"");
printf("Procedure Calls Min SRT Max SRT Avg SRT\n");
for(i=0;i<rs->num_procedures;i++){
if(rs->procedures[i].num==0){
continue;
}
td = ((guint64)(rs->procedures[i].tot.secs)) * NANOSECS_PER_SEC + rs->procedures[i].tot.nsecs;
td = ((td / rs->procedures[i].num) + 500) / 1000;
printf("%-15s %6d %3d.%06d %3d.%06d %3" G_GINT64_MODIFIER "u.%06" G_GINT64_MODIFIER "u\n",
rs->procedures[i].proc,
rs->procedures[i].num,
(int)(rs->procedures[i].min.secs),(rs->procedures[i].min.nsecs+500)/1000,
(int)(rs->procedures[i].max.secs),(rs->procedures[i].max.nsecs+500)/1000,
td/MICROSECS_PER_SEC, td%MICROSECS_PER_SEC
);
}
printf("=======================================================\n");
}
static void *
rpcstat_find_procs(gpointer *key, gpointer *value _U_, gpointer *user_data _U_)
{
rpc_proc_info_key *k=(rpc_proc_info_key *)key;
if(k->prog!=rpc_program){
return NULL;
}
if(k->vers!=rpc_version){
return NULL;
}
if(rpc_min_proc==-1){
rpc_min_proc=k->proc;
rpc_max_proc=k->proc;
}
if((gint32)k->proc<rpc_min_proc){
rpc_min_proc=k->proc;
}
if((gint32)k->proc>rpc_max_proc){
rpc_max_proc=k->proc;
}
return NULL;
}
static void
rpcstat_init(const char *optarg, void* userdata _U_)
{
rpcstat_t *rs;
guint32 i;
int program, version;
int pos=0;
const char *filter=NULL;
GString *error_string;
if(sscanf(optarg,"rpc,srt,%d,%d,%n",&program,&version,&pos)==2){
if(pos){
filter=optarg+pos;
} else {
filter=NULL;
}
} else {
fprintf(stderr, "tshark: invalid \"-z rpc,srt,<program>,<version>[,<filter>]\" argument\n");
exit(1);
}
rs=g_new(rpcstat_t,1);
rs->prog=rpc_prog_name(program);
rs->program=program;
rs->version=version;
if(filter){
rs->filter=g_strdup(filter);
} else {
rs->filter=NULL;
}
rpc_program=program;
rpc_version=version;
rpc_min_proc=-1;
rpc_max_proc=-1;
g_hash_table_foreach(rpc_procs, (GHFunc)rpcstat_find_procs, NULL);
if(rpc_min_proc==-1){
fprintf(stderr,"tshark: Invalid -z rpc,srt,%d,%d\n",rpc_program,rpc_version);
fprintf(stderr," Program:%d version:%d isn't supported by tshark.\n", rpc_program, rpc_version);
exit(1);
}
rs->num_procedures=rpc_max_proc+1;
rs->procedures=g_new(rpc_procedure_t,rs->num_procedures+1);
for(i=0;i<rs->num_procedures;i++){
rs->procedures[i].proc=rpc_proc_name(program, version, i);
rs->procedures[i].num=0;
rs->procedures[i].min.secs=0;
rs->procedures[i].min.nsecs=0;
rs->procedures[i].max.secs=0;
rs->procedures[i].max.nsecs=0;
rs->procedures[i].tot.secs=0;
rs->procedures[i].tot.nsecs=0;
}
error_string=register_tap_listener("rpc", rs, filter, 0, rpcstat_reset, rpcstat_packet, rpcstat_draw);
if(error_string){
g_free(rs->procedures);
g_free(rs->filter);
g_free(rs);
fprintf(stderr, "tshark: Couldn't register rpc,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_rpcstat(void)
{
register_stat_cmd_arg("rpc,srt,", rpcstat_init,NULL);
}
