static int
smbstat_packet(void *pss, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
smbstat_t *ss=(smbstat_t *)pss;
const smb_info_t *si=(const smb_info_t *)psi;
nstime_t t, deltat;
timestat_t *sp=NULL;
if(si->request){
return 0;
}
if(!si->sip){
return 0;
}
if(si->cmd==0xA0 && si->sip->extra_info_type == SMB_EI_NTI){
smb_nt_transact_info_t *sti=(smb_nt_transact_info_t *)si->sip->extra_info;
if(sti){
sp=&(ss->nt_trans[sti->subcmd]);
}
} else if(si->cmd==0x32 && si->sip->extra_info_type == SMB_EI_T2I){
smb_transact2_info_t *st2i=(smb_transact2_info_t *)si->sip->extra_info;
if(st2i){
sp=&(ss->trans2[st2i->subcmd]);
}
} else {
sp=&(ss->proc[si->cmd]);
}
t=pinfo->fd->abs_ts;
nstime_delta(&deltat, &t, &si->sip->req_time);
if(sp){
time_stat_update(sp,&deltat, pinfo);
}
return 1;
}
static void
smbstat_draw(void *pss)
{
smbstat_t *ss=(smbstat_t *)pss;
guint32 i;
guint64 td;
printf("\n");
printf("=================================================================\n");
printf("SMB SRT Statistics:\n");
printf("Filter: %s\n",ss->filter?ss->filter:"");
printf("Commands Calls Min SRT Max SRT Avg SRT\n");
for(i=0;i<256;i++){
if(ss->proc[i].num==0){
continue;
}
if(i==0x32){
continue;
}
if(i==0xA0){
continue;
}
td = ((guint64)(ss->proc[i].tot.secs)) * NANOSECS_PER_SEC + ss->proc[i].tot.nsecs;
td = ((td / ss->proc[i].num) + 500) / 1000;
printf("%-25s %6d %3d.%06d %3d.%06d %3" G_GINT64_MODIFIER "u.%06" G_GINT64_MODIFIER "u\n",
val_to_str_ext(i, &smb_cmd_vals_ext, "Unknown (0x%02x)"),
ss->proc[i].num,
(int)(ss->proc[i].min.secs),(ss->proc[i].min.nsecs+500)/1000,
(int)(ss->proc[i].max.secs),(ss->proc[i].max.nsecs+500)/1000,
td/MICROSECS_PER_SEC, td%MICROSECS_PER_SEC
);
}
printf("\n");
printf("Transaction2 Commands Calls Min SRT Max SRT Avg SRT\n");
for(i=0;i<256;i++){
if(ss->trans2[i].num==0){
continue;
}
td = ((guint64)(ss->trans2[i].tot.secs)) * NANOSECS_PER_SEC + ss->trans2[i].tot.nsecs;
td = ((td / ss->trans2[i].num) + 500) / 1000;
printf("%-25s %6d %3d.%06d %3d.%06d %3" G_GINT64_MODIFIER "u.%06" G_GINT64_MODIFIER "u\n",
val_to_str_ext(i, &trans2_cmd_vals_ext, "Unknown (0x%02x)"),
ss->trans2[i].num,
(int)(ss->trans2[i].min.secs),(ss->trans2[i].min.nsecs+500)/1000,
(int)(ss->trans2[i].max.secs),(ss->trans2[i].max.nsecs+500)/1000,
td/MICROSECS_PER_SEC, td%MICROSECS_PER_SEC
);
}
printf("\n");
printf("NT Transaction Commands Calls Min SRT Max SRT Avg SRT\n");
for(i=0;i<256;i++){
if(ss->nt_trans[i].num==0){
continue;
}
td = ((guint64)(ss->nt_trans[i].tot.secs)) * NANOSECS_PER_SEC + ss->nt_trans[i].tot.nsecs;
td = ((td / ss->nt_trans[i].num) + 500) / 1000;
printf("%-25s %6d %3d.%06d %3d.%06d %3" G_GINT64_MODIFIER "u.%06" G_GINT64_MODIFIER "u\n",
val_to_str_ext(i, &nt_cmd_vals_ext, "Unknown (0x%02x)"),
ss->nt_trans[i].num,
(int)(ss->nt_trans[i].min.secs),(ss->nt_trans[i].min.nsecs+500)/1000,
(int)(ss->nt_trans[i].max.secs),(ss->nt_trans[i].max.nsecs+500)/1000,
td/MICROSECS_PER_SEC, td%MICROSECS_PER_SEC
);
}
printf("=================================================================\n");
}
static void
smbstat_init(const char *opt_arg,void* userdata _U_)
{
smbstat_t *ss;
guint32 i;
const char *filter=NULL;
GString *error_string;
if(!strncmp(opt_arg,"smb,srt,",8)){
filter=opt_arg+8;
} else {
filter=NULL;
}
ss=g_new(smbstat_t,1);
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
ss->trans2[i].num=0;
ss->trans2[i].min_num=0;
ss->trans2[i].max_num=0;
ss->trans2[i].min.secs=0;
ss->trans2[i].min.nsecs=0;
ss->trans2[i].max.secs=0;
ss->trans2[i].max.nsecs=0;
ss->trans2[i].tot.secs=0;
ss->trans2[i].tot.nsecs=0;
ss->nt_trans[i].num=0;
ss->nt_trans[i].min_num=0;
ss->nt_trans[i].max_num=0;
ss->nt_trans[i].min.secs=0;
ss->nt_trans[i].min.nsecs=0;
ss->nt_trans[i].max.secs=0;
ss->nt_trans[i].max.nsecs=0;
ss->nt_trans[i].tot.secs=0;
ss->nt_trans[i].tot.nsecs=0;
}
error_string=register_tap_listener("smb", ss, filter, 0, NULL, smbstat_packet, smbstat_draw);
if(error_string){
g_free(ss->filter);
g_free(ss);
fprintf(stderr, "tshark: Couldn't register smb,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_smbstat(void)
{
register_stat_cmd_arg("smb,srt", smbstat_init,NULL);
}
