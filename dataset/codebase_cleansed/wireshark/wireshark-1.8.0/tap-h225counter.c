static void
h225counter_reset(void *phs)
{
h225counter_t *hs=(h225counter_t *)phs;
char *save_filter = hs->filter;
memset(hs, 0, sizeof(h225counter_t));
hs->filter = save_filter;
}
static int
h225counter_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
h225counter_t *hs=(h225counter_t *)phs;
const h225_packet_info *pi=phi;
switch (pi->msg_type) {
case H225_RAS:
if(pi->msg_tag==-1) {
return 0;
}
else if (pi->msg_tag >= RAS_MSG_TYPES) {
hs->ras_msg[RAS_MSG_TYPES]++;
}
else {
hs->ras_msg[pi->msg_tag]++;
}
if(pi->reason==-1) {
break;
}
switch(pi->msg_tag) {
case 2:
if(pi->reason < GRJ_REASONS)
hs->grj_reason[pi->reason]++;
else
hs->grj_reason[GRJ_REASONS]++;
break;
case 5:
if(pi->reason < RRJ_REASONS)
hs->rrj_reason[pi->reason]++;
else
hs->rrj_reason[RRJ_REASONS]++;
break;
case 6:
if(pi->reason < URQ_REASONS)
hs->urq_reason[pi->reason]++;
else
hs->urq_reason[URQ_REASONS]++;
break;
case 8:
if(pi->reason < URJ_REASONS)
hs->urj_reason[pi->reason]++;
else
hs->urj_reason[URJ_REASONS]++;
break;
case 11:
if(pi->reason < ARJ_REASONS)
hs->arj_reason[pi->reason]++;
else
hs->arj_reason[ARJ_REASONS]++;
break;
case 14:
if(pi->reason < BRJ_REASONS)
hs->brj_reason[pi->reason]++;
else
hs->brj_reason[BRJ_REASONS]++;
break;
case 15:
if(pi->reason < DRQ_REASONS)
hs->drq_reason[pi->reason]++;
else
hs->drq_reason[DRQ_REASONS]++;
break;
case 17:
if(pi->reason < DRJ_REASONS)
hs->drj_reason[pi->reason]++;
else
hs->drj_reason[DRJ_REASONS]++;
break;
case 20:
if(pi->reason < LRJ_REASONS)
hs->lrj_reason[pi->reason]++;
else
hs->lrj_reason[LRJ_REASONS]++;
break;
case 29:
if(pi->reason < IRQNAK_REASONS)
hs->irqnak_reason[pi->reason]++;
else
hs->irqnak_reason[IRQNAK_REASONS]++;
break;
default:
break;
}
break;
case H225_CS:
if(pi->msg_tag==-1) {
return 0;
}
else if (pi->msg_tag >= CS_MSG_TYPES) {
hs->cs_msg[CS_MSG_TYPES]++;
}
else {
hs->cs_msg[pi->msg_tag]++;
}
if(pi->reason==-1) {
break;
}
switch(pi->msg_tag) {
case 5:
if(pi->reason < REL_CMP_REASONS)
hs->rel_cmp_reason[pi->reason]++;
else
hs->rel_cmp_reason[REL_CMP_REASONS]++;
break;
case 6:
if(pi->reason < FACILITY_REASONS)
hs->facility_reason[pi->reason]++;
else
hs->facility_reason[FACILITY_REASONS]++;
break;
default:
break;
}
break;
default:
return 0;
}
return 1;
}
static void
h225counter_draw(void *phs)
{
h225counter_t *hs=(h225counter_t *)phs;
int i,j;
printf("================== H225 Message and Reason Counter ==================\n");
printf("RAS-Messages:\n");
for(i=0;i<=RAS_MSG_TYPES;i++) {
if(hs->ras_msg[i]!=0) {
printf(" %s : %u\n", val_to_str(i,h225_RasMessage_vals,"unknown ras-messages "), hs->ras_msg[i]);
switch(i) {
case 2:
for(j=0;j<=GRJ_REASONS;j++) {
if(hs->grj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,GatekeeperRejectReason_vals,"unknown reason "), hs->grj_reason[j]);
}
}
break;
case 5:
for(j=0;j<=RRJ_REASONS;j++) {
if(hs->rrj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,RegistrationRejectReason_vals,"unknown reason "), hs->rrj_reason[j]);
}
}
break;
case 6:
for(j=0;j<=URQ_REASONS;j++) {
if(hs->urq_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,UnregRequestReason_vals,"unknown reason "), hs->urq_reason[j]);
}
}
break;
case 8:
for(j=0;j<=URJ_REASONS;j++) {
if(hs->urj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,UnregRejectReason_vals,"unknown reason "), hs->urj_reason[j]);
}
}
break;
case 11:
for(j=0;j<=ARJ_REASONS;j++) {
if(hs->arj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,AdmissionRejectReason_vals,"unknown reason "), hs->arj_reason[j]);
}
}
break;
case 14:
for(j=0;j<=BRJ_REASONS;j++) {
if(hs->brj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,BandRejectReason_vals,"unknown reason "), hs->brj_reason[j]);
}
}
break;
case 15:
for(j=0;j<=DRQ_REASONS;j++) {
if(hs->drq_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,DisengageReason_vals,"unknown reason "), hs->drq_reason[j]);
}
}
break;
case 17:
for(j=0;j<=DRJ_REASONS;j++) {
if(hs->drj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,DisengageRejectReason_vals,"unknown reason "), hs->drj_reason[j]);
}
}
break;
case 20:
for(j=0;j<=LRJ_REASONS;j++) {
if(hs->lrj_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,LocationRejectReason_vals,"unknown reason "), hs->lrj_reason[j]);
}
}
break;
case 29:
for(j=0;j<=IRQNAK_REASONS;j++) {
if(hs->irqnak_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,InfoRequestNakReason_vals,"unknown reason "), hs->irqnak_reason[j]);
}
}
break;
default:
break;
}
}
}
printf("Call Signalling:\n");
for(i=0;i<=CS_MSG_TYPES;i++) {
if(hs->cs_msg[i]!=0) {
printf(" %s : %u\n", val_to_str(i,T_h323_message_body_vals,"unknown cs-messages "), hs->cs_msg[i]);
switch(i) {
case 5:
for(j=0;j<=REL_CMP_REASONS;j++) {
if(hs->rel_cmp_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,h225_ReleaseCompleteReason_vals,"unknown reason "), hs->rel_cmp_reason[j]);
}
}
break;
case 6:
for(j=0;j<=FACILITY_REASONS;j++) {
if(hs->facility_reason[j]!=0) {
printf(" %s : %u\n", val_to_str(j,FacilityReason_vals,"unknown reason "), hs->facility_reason[j]);
}
}
break;
default:
break;
}
}
}
printf("=====================================================================\n");
}
static void
h225counter_init(const char *optarg, void* userdata _U_)
{
h225counter_t *hs;
GString *error_string;
hs = g_malloc(sizeof(h225counter_t));
if(!strncmp(optarg,"h225,counter,",13)){
hs->filter=g_strdup(optarg+13);
} else {
hs->filter=NULL;
}
h225counter_reset(hs);
error_string=register_tap_listener("h225", hs, hs->filter, 0, NULL, h225counter_packet, h225counter_draw);
if(error_string){
g_free(hs->filter);
g_free(hs);
fprintf(stderr, "tshark: Couldn't register h225,counter tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_h225counter(void)
{
register_stat_cmd_arg("h225,counter", h225counter_init,NULL);
}
