static void
scsistat_reset(void *prs)
{
scsistat_t *rs=(scsistat_t *)prs;
guint32 i;
for(i=0; i < MAX_PROCEDURES; i++) {
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
scsistat_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
scsistat_t *rs = (scsistat_t *)prs;
const scsi_task_data_t *ri = (const scsi_task_data_t *)pri;
nstime_t delta;
scsi_procedure_t *rp;
if(ri->type!=SCSI_PDU_TYPE_RSP) {
return 0;
}
if( (!ri->itl) || ((ri->itl->cmdset&SCSI_CMDSET_MASK)!=rs->cmdset) ) {
return 0;
}
if( (!ri->itlq) || (ri->itlq->scsi_opcode > 255) ) {
return 0;
}
rp=&(rs->procedures[ri->itlq->scsi_opcode]);
nstime_delta(&delta, &pinfo->fd->abs_ts, &ri->itlq->fc_time);
if(rp->num==0) {
rp->max.secs=delta.secs;
rp->max.nsecs=delta.nsecs;
}
if(rp->num==0) {
rp->min.secs= delta.secs;
rp->min.nsecs=delta.nsecs;
}
if( (delta.secs < rp->min.secs)
||( (delta.secs == rp->min.secs)
&&(delta.nsecs < rp->min.nsecs) ) ) {
rp->min.secs = delta.secs;
rp->min.nsecs= delta.nsecs;
}
if( (delta.secs > rp->max.secs)
||( (delta.secs == rp->max.secs)
&&(delta.nsecs > rp->max.nsecs) ) ) {
rp->max.secs = delta.secs;
rp->max.nsecs= delta.nsecs;
}
rp->tot.secs += delta.secs;
rp->tot.nsecs += delta.nsecs;
if(rp->tot.nsecs > NANOSECS_PER_SEC) {
rp->tot.nsecs -= NANOSECS_PER_SEC;
rp->tot.secs++;
}
rp->num++;
return 1;
}
static void
scsistat_draw(void *prs)
{
scsistat_t *rs=(scsistat_t *)prs;
guint32 i;
guint64 td;
printf("\n");
printf("===========================================================\n");
printf("SCSI %s SRT Statistics:\n", rs->prog);
printf("Filter: %s\n", rs->filter?rs->filter:"");
printf("Procedure Calls Min SRT Max SRT Avg SRT\n");
for(i=0; i < MAX_PROCEDURES; i++) {
if(rs->procedures[i].num==0) {
continue;
}
td = ((guint64)(rs->procedures[i].tot.secs)) * NANOSECS_PER_SEC + rs->procedures[i].tot.nsecs;
td = ((td / rs->procedures[i].num) + 500) / 1000;
printf("%-19s %6d %3d.%06u %3d.%06u %3d.%06u \n",
rs->procedures[i].proc,
rs->procedures[i].num,
(int)(rs->procedures[i].min.secs),
(rs->procedures[i].min.nsecs+500)/1000,
(int)(rs->procedures[i].max.secs),
(rs->procedures[i].max.nsecs+500)/1000,
(int)(td/1000000), (int)(td%1000000)
);
}
printf("===========================================================\n");
}
static void
scsistat_init(const char *optarg, void* userdata _U_)
{
scsistat_t *rs;
guint32 i;
int program, pos;
const char *filter=NULL;
GString *error_string;
pos=0;
if(sscanf(optarg, "scsi,srt,%d,%n", &program, &pos)==1) {
if(pos) {
filter=optarg+pos;
} else {
filter=NULL;
}
} else {
fprintf(stderr, "tshark: invalid \"-z scsi,srt,<cmdset>[,<filter>]\" argument\n");
exit(1);
}
scsi_program=program;
rs=g_new(scsistat_t,1);
if(filter) {
rs->filter=g_strdup(filter);
} else {
rs->filter=NULL;
}
rs->cmdset=program;
switch(program) {
case SCSI_DEV_SBC:
rs->prog="SBC (disk)";
rs->cdbnames=scsi_sbc_vals;
break;
case SCSI_DEV_SSC:
rs->prog="SSC (tape)";
rs->cdbnames=scsi_ssc_vals;
break;
case SCSI_DEV_CDROM:
rs->prog="MMC (cd/dvd)";
rs->cdbnames=scsi_mmc_vals;
break;
case SCSI_DEV_SMC:
rs->prog="SMC (tape robot)";
rs->cdbnames=scsi_smc_vals;
break;
case SCSI_DEV_OSD:
rs->prog="OSD (object based)";
rs->cdbnames=scsi_osd_vals;
break;
default:
rs->cmdset=0;
rs->prog="SBC (disk)";
rs->cdbnames=scsi_sbc_vals;
break;
}
rs->procedures=g_new(scsi_procedure_t,MAX_PROCEDURES);
for(i=0; i < MAX_PROCEDURES; i++) {
rs->procedures[i].proc=val_to_str(i, rs->cdbnames, "Unknown-0x%02x");
rs->procedures[i].num=0;
rs->procedures[i].min.secs=0;
rs->procedures[i].min.nsecs=0;
rs->procedures[i].max.secs=0;
rs->procedures[i].max.nsecs=0;
rs->procedures[i].tot.secs=0;
rs->procedures[i].tot.nsecs=0;
}
error_string=register_tap_listener("scsi", rs, filter, 0, scsistat_reset, scsistat_packet, scsistat_draw);
if(error_string) {
g_free(rs->procedures);
g_free(rs->filter);
g_free(rs);
fprintf(stderr, "tshark: Couldn't register scsi,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_scsistat(void)
{
register_stat_cmd_arg("scsi,srt,", scsistat_init, NULL);
}
