static inline int is_my_addr(const struct s_smc *smc,
const struct fddi_addr *addr)
{
return(*(short *)(&addr->a[0]) ==
*(short *)(&smc->mib.m[MAC0].fddiMACSMTAddress.a[0])
&& *(short *)(&addr->a[2]) ==
*(short *)(&smc->mib.m[MAC0].fddiMACSMTAddress.a[2])
&& *(short *)(&addr->a[4]) ==
*(short *)(&smc->mib.m[MAC0].fddiMACSMTAddress.a[4])) ;
}
static inline int is_broadcast(const struct fddi_addr *addr)
{
return *(u_short *)(&addr->a[0]) == 0xffff &&
*(u_short *)(&addr->a[2]) == 0xffff &&
*(u_short *)(&addr->a[4]) == 0xffff;
}
static inline int is_individual(const struct fddi_addr *addr)
{
return !(addr->a[0] & GROUP_ADDR);
}
static inline int is_equal(const struct fddi_addr *addr1,
const struct fddi_addr *addr2)
{
return *(u_short *)(&addr1->a[0]) == *(u_short *)(&addr2->a[0]) &&
*(u_short *)(&addr1->a[2]) == *(u_short *)(&addr2->a[2]) &&
*(u_short *)(&addr1->a[4]) == *(u_short *)(&addr2->a[4]);
}
void smt_agent_init(struct s_smc *smc)
{
int i ;
smc->mib.m[MAC0].fddiMACSMTAddress = smc->hw.fddi_home_addr ;
smc->mib.fddiSMTStationId.sid_oem[0] = 0 ;
smc->mib.fddiSMTStationId.sid_oem[1] = 0 ;
driver_get_bia(smc,&smc->mib.fddiSMTStationId.sid_node) ;
for (i = 0 ; i < 6 ; i ++) {
smc->mib.fddiSMTStationId.sid_node.a[i] =
bitrev8(smc->mib.fddiSMTStationId.sid_node.a[i]);
}
smc->mib.fddiSMTManufacturerData[0] =
smc->mib.fddiSMTStationId.sid_node.a[0] ;
smc->mib.fddiSMTManufacturerData[1] =
smc->mib.fddiSMTStationId.sid_node.a[1] ;
smc->mib.fddiSMTManufacturerData[2] =
smc->mib.fddiSMTStationId.sid_node.a[2] ;
smc->sm.smt_tid = 0 ;
smc->mib.m[MAC0].fddiMACDupAddressTest = DA_NONE ;
smc->mib.m[MAC0].fddiMACUNDA_Flag = FALSE ;
#ifndef SLIM_SMT
smt_clear_una_dna(smc) ;
smt_clear_old_una_dna(smc) ;
#endif
for (i = 0 ; i < SMT_MAX_TEST ; i++)
smc->sm.pend[i] = 0 ;
smc->sm.please_reconnect = 0 ;
smc->sm.uniq_ticks = 0 ;
}
void smt_agent_task(struct s_smc *smc)
{
smt_timer_start(smc,&smc->sm.smt_timer, (u_long)1000000L,
EV_TOKEN(EVENT_SMT,SM_TIMER)) ;
DB_SMT("SMT agent task\n",0,0) ;
}
void smt_emulate_token_ct(struct s_smc *smc, int mac_index)
{
u_long count;
u_long time;
time = smt_get_time();
count = ((time - smc->sm.last_tok_time[mac_index]) *
100)/TICKS_PER_SECOND;
if (smc->hw.mac_ring_is_up){
smc->mib.m[mac_index].fddiMACToken_Ct += count;
}
smc->sm.last_tok_time[mac_index] = time;
}
void smt_event(struct s_smc *smc, int event)
{
u_long time ;
#ifndef SMT_REAL_TOKEN_CT
int i ;
#endif
if (smc->sm.please_reconnect) {
smc->sm.please_reconnect -- ;
if (smc->sm.please_reconnect == 0) {
queue_event(smc,EVENT_ECM,EC_CONNECT) ;
}
}
if (event == SM_FAST)
return ;
smt_timer_poll(smc) ;
smt_start_watchdog(smc) ;
#ifndef SLIM_SMT
#ifndef BOOT
#ifdef ESS
ess_timer_poll(smc) ;
#endif
#endif
#ifdef SBA
sba_timer_poll(smc) ;
#endif
smt_srf_event(smc,0,0,0) ;
#endif
time = smt_get_time() ;
if (time - smc->sm.smt_last_lem >= TICKS_PER_SECOND*8) {
struct fddi_mib_m *mib ;
u_long upper ;
u_long lower ;
int cond ;
int port;
struct s_phy *phy ;
sm_lem_evaluate(smc) ;
smc->sm.smt_last_lem = time ;
#ifndef SLIM_SMT
mac_update_counter(smc) ;
mib = smc->mib.m ;
upper =
(mib->fddiMACLost_Ct - mib->fddiMACOld_Lost_Ct) +
(mib->fddiMACError_Ct - mib->fddiMACOld_Error_Ct) ;
lower =
(mib->fddiMACFrame_Ct - mib->fddiMACOld_Frame_Ct) +
(mib->fddiMACLost_Ct - mib->fddiMACOld_Lost_Ct) ;
mib->fddiMACFrameErrorRatio = div_ratio(upper,lower) ;
cond =
((!mib->fddiMACFrameErrorThreshold &&
mib->fddiMACError_Ct != mib->fddiMACOld_Error_Ct) ||
(mib->fddiMACFrameErrorRatio >
mib->fddiMACFrameErrorThreshold)) ;
if (cond != mib->fddiMACFrameErrorFlag)
smt_srf_event(smc,SMT_COND_MAC_FRAME_ERROR,
INDEX_MAC,cond) ;
upper =
(mib->fddiMACNotCopied_Ct - mib->fddiMACOld_NotCopied_Ct) ;
lower =
upper +
(mib->fddiMACCopied_Ct - mib->fddiMACOld_Copied_Ct) ;
mib->fddiMACNotCopiedRatio = div_ratio(upper,lower) ;
cond =
((!mib->fddiMACNotCopiedThreshold &&
mib->fddiMACNotCopied_Ct !=
mib->fddiMACOld_NotCopied_Ct)||
(mib->fddiMACNotCopiedRatio >
mib->fddiMACNotCopiedThreshold)) ;
if (cond != mib->fddiMACNotCopiedFlag)
smt_srf_event(smc,SMT_COND_MAC_NOT_COPIED,
INDEX_MAC,cond) ;
mib->fddiMACOld_Frame_Ct = mib->fddiMACFrame_Ct ;
mib->fddiMACOld_Copied_Ct = mib->fddiMACCopied_Ct ;
mib->fddiMACOld_Error_Ct = mib->fddiMACError_Ct ;
mib->fddiMACOld_Lost_Ct = mib->fddiMACLost_Ct ;
mib->fddiMACOld_NotCopied_Ct = mib->fddiMACNotCopied_Ct ;
for (port = 0; port < NUMPHYS; port ++) {
phy = &smc->y[port] ;
if (!phy->mib->fddiPORTHardwarePresent) {
continue;
}
cond = (phy->mib->fddiPORTEBError_Ct -
phy->mib->fddiPORTOldEBError_Ct > 5) ;
smt_srf_event(smc,SMT_COND_PORT_EB_ERROR,
(int) (INDEX_PORT+ phy->np) ,cond) ;
phy->mib->fddiPORTOldEBError_Ct =
phy->mib->fddiPORTEBError_Ct ;
}
#endif
}
#ifndef SLIM_SMT
if (time - smc->sm.smt_last_notify >= (u_long)
(smc->mib.fddiSMTTT_Notify * TICKS_PER_SECOND) ) {
if (!smc->sm.pend[SMT_TID_NIF])
smc->sm.pend[SMT_TID_NIF] = smt_get_tid(smc) ;
smt_send_nif(smc,&fddi_broadcast, FC_SMT_NSA,
smc->sm.pend[SMT_TID_NIF], SMT_REQUEST,0) ;
smc->sm.smt_last_notify = time ;
}
if (smc->sm.smt_tvu &&
time - smc->sm.smt_tvu > 228*TICKS_PER_SECOND) {
DB_SMT("SMT : UNA expired\n",0,0) ;
smc->sm.smt_tvu = 0 ;
if (!is_equal(&smc->mib.m[MAC0].fddiMACUpstreamNbr,
&SMT_Unknown)){
smc->mib.m[MAC0].fddiMACOldUpstreamNbr=
smc->mib.m[MAC0].fddiMACUpstreamNbr ;
}
smc->mib.m[MAC0].fddiMACUpstreamNbr = SMT_Unknown ;
smc->mib.m[MAC0].fddiMACUNDA_Flag = FALSE ;
update_dac(smc,0) ;
smt_srf_event(smc, SMT_EVENT_MAC_NEIGHBOR_CHANGE,
INDEX_MAC,0) ;
}
if (smc->sm.smt_tvd &&
time - smc->sm.smt_tvd > 228*TICKS_PER_SECOND) {
DB_SMT("SMT : DNA expired\n",0,0) ;
smc->sm.smt_tvd = 0 ;
if (!is_equal(&smc->mib.m[MAC0].fddiMACDownstreamNbr,
&SMT_Unknown)){
smc->mib.m[MAC0].fddiMACOldDownstreamNbr=
smc->mib.m[MAC0].fddiMACDownstreamNbr ;
}
smc->mib.m[MAC0].fddiMACDownstreamNbr = SMT_Unknown ;
smt_srf_event(smc, SMT_EVENT_MAC_NEIGHBOR_CHANGE,
INDEX_MAC,0) ;
}
#endif
#ifndef SMT_REAL_TOKEN_CT
for (i = MAC0; i < NUMMACS; i++ ){
if (time - smc->sm.last_tok_time[i] > 2*TICKS_PER_SECOND ){
smt_emulate_token_ct( smc, i );
}
}
#endif
smt_timer_start(smc,&smc->sm.smt_timer, (u_long)1000000L,
EV_TOKEN(EVENT_SMT,SM_TIMER)) ;
}
static int div_ratio(u_long upper, u_long lower)
{
if ((upper<<16L) < upper)
upper = 0xffff0000L ;
else
upper <<= 16L ;
if (!lower)
return 0;
return (int)(upper/lower) ;
}
void smt_received_pack(struct s_smc *smc, SMbuf *mb, int fs)
{
struct smt_header *sm ;
int local ;
int illegal = 0 ;
switch (m_fc(mb)) {
case FC_SMT_INFO :
case FC_SMT_LAN_LOC :
case FC_SMT_LOC :
case FC_SMT_NSA :
break ;
default :
smt_free_mbuf(smc,mb) ;
return ;
}
smc->mib.m[MAC0].fddiMACSMTCopied_Ct++ ;
sm = smtod(mb,struct smt_header *) ;
local = ((fs & L_INDICATOR) != 0) ;
hwm_conv_can(smc,(char *)sm,12) ;
if (is_individual(&sm->smt_dest) && !is_my_addr(smc,&sm->smt_dest)) {
smt_free_mbuf(smc,mb) ;
return ;
}
#if 0
if (is_my_addr(smc,&sm->smt_source) && !local) {
smt_free_mbuf(smc,mb) ;
return ;
}
#endif
smt_swap_para(sm,(int) mb->sm_len,1) ;
DB_SMT("SMT : received packet [%s] at 0x%x\n",
smt_type_name[m_fc(mb) & 0xf],sm) ;
DB_SMT("SMT : version %d, class %s\n",sm->smt_version,
smt_class_name[(sm->smt_class>LAST_CLASS)?0 : sm->smt_class]) ;
#ifdef SBA
if (m_fc(mb) == FC_SMT_NSA && sm->smt_class == SMT_NIF &&
(sm->smt_type == SMT_ANNOUNCE || sm->smt_type == SMT_REQUEST)) {
smc->sba.sm = sm ;
sba(smc,NIF) ;
}
#endif
if ( (fs & A_INDICATOR) && m_fc(mb) == FC_SMT_NSA) {
DB_SMT("SMT : ignoring NSA with A-indicator set from %s\n",
addr_to_string(&sm->smt_source),0) ;
smt_free_mbuf(smc,mb) ;
return ;
}
if (((sm->smt_class == SMT_ECF) && (sm->smt_len > SMT_MAX_ECHO_LEN)) ||
((sm->smt_class != SMT_ECF) && (sm->smt_len > SMT_MAX_INFO_LEN))) {
smt_free_mbuf(smc,mb) ;
return ;
}
switch (sm->smt_class) {
case SMT_NIF :
case SMT_SIF_CONFIG :
case SMT_SIF_OPER :
case SMT_ECF :
if (sm->smt_version != SMT_VID)
illegal = 1;
break ;
default :
if (sm->smt_version != SMT_VID_2)
illegal = 1;
break ;
}
if (illegal) {
DB_SMT("SMT : version = %d, dest = %s\n",
sm->smt_version,addr_to_string(&sm->smt_source)) ;
smt_send_rdf(smc,mb,m_fc(mb),SMT_RDF_VERSION,local) ;
smt_free_mbuf(smc,mb) ;
return ;
}
if ((sm->smt_len > mb->sm_len - sizeof(struct smt_header)) ||
((sm->smt_len & 3) && (sm->smt_class != SMT_ECF))) {
DB_SMT("SMT: info length error, len = %d\n",sm->smt_len,0) ;
smt_send_rdf(smc,mb,m_fc(mb),SMT_RDF_LENGTH,local) ;
smt_free_mbuf(smc,mb) ;
return ;
}
switch (sm->smt_class) {
case SMT_NIF :
if (smt_check_para(smc,sm,plist_nif)) {
DB_SMT("SMT: NIF with para problem, ignoring\n",0,0) ;
break ;
}
switch (sm->smt_type) {
case SMT_ANNOUNCE :
case SMT_REQUEST :
if (!(fs & C_INDICATOR) && m_fc(mb) == FC_SMT_NSA
&& is_broadcast(&sm->smt_dest)) {
struct smt_p_state *st ;
if (!is_equal(
&smc->mib.m[MAC0].fddiMACUpstreamNbr,
&sm->smt_source)) {
DB_SMT("SMT : updated my UNA = %s\n",
addr_to_string(&sm->smt_source),0) ;
if (!is_equal(&smc->mib.m[MAC0].
fddiMACUpstreamNbr,&SMT_Unknown)){
smc->mib.m[MAC0].fddiMACOldUpstreamNbr=
smc->mib.m[MAC0].fddiMACUpstreamNbr ;
}
smc->mib.m[MAC0].fddiMACUpstreamNbr =
sm->smt_source ;
smt_srf_event(smc,
SMT_EVENT_MAC_NEIGHBOR_CHANGE,
INDEX_MAC,0) ;
smt_echo_test(smc,0) ;
}
smc->sm.smt_tvu = smt_get_time() ;
st = (struct smt_p_state *)
sm_to_para(smc,sm,SMT_P_STATE) ;
if (st) {
smc->mib.m[MAC0].fddiMACUNDA_Flag =
(st->st_dupl_addr & SMT_ST_MY_DUPA) ?
TRUE : FALSE ;
update_dac(smc,1) ;
}
}
if ((sm->smt_type == SMT_REQUEST) &&
is_individual(&sm->smt_source) &&
((!(fs & A_INDICATOR) && m_fc(mb) == FC_SMT_NSA) ||
(m_fc(mb) != FC_SMT_NSA))) {
DB_SMT("SMT : replying to NIF request %s\n",
addr_to_string(&sm->smt_source),0) ;
smt_send_nif(smc,&sm->smt_source,
FC_SMT_INFO,
sm->smt_tid,
SMT_REPLY,local) ;
}
break ;
case SMT_REPLY :
DB_SMT("SMT : received NIF response from %s\n",
addr_to_string(&sm->smt_source),0) ;
if (fs & A_INDICATOR) {
smc->sm.pend[SMT_TID_NIF] = 0 ;
DB_SMT("SMT : duplicate address\n",0,0) ;
smc->mib.m[MAC0].fddiMACDupAddressTest =
DA_FAILED ;
smc->r.dup_addr_test = DA_FAILED ;
queue_event(smc,EVENT_RMT,RM_DUP_ADDR) ;
smc->mib.m[MAC0].fddiMACDA_Flag = TRUE ;
update_dac(smc,1) ;
break ;
}
if (sm->smt_tid == smc->sm.pend[SMT_TID_NIF]) {
smc->sm.pend[SMT_TID_NIF] = 0 ;
if (!is_equal(
&smc->mib.m[MAC0].fddiMACDownstreamNbr,
&sm->smt_source)) {
DB_SMT("SMT : updated my DNA\n",0,0) ;
if (!is_equal(&smc->mib.m[MAC0].
fddiMACDownstreamNbr, &SMT_Unknown)){
smc->mib.m[MAC0].fddiMACOldDownstreamNbr =
smc->mib.m[MAC0].fddiMACDownstreamNbr ;
}
smc->mib.m[MAC0].fddiMACDownstreamNbr =
sm->smt_source ;
smt_srf_event(smc,
SMT_EVENT_MAC_NEIGHBOR_CHANGE,
INDEX_MAC,0) ;
smt_echo_test(smc,1) ;
}
smc->mib.m[MAC0].fddiMACDA_Flag = FALSE ;
update_dac(smc,1) ;
smc->sm.smt_tvd = smt_get_time() ;
smc->mib.m[MAC0].fddiMACDupAddressTest =
DA_PASSED ;
if (smc->r.dup_addr_test != DA_PASSED) {
smc->r.dup_addr_test = DA_PASSED ;
queue_event(smc,EVENT_RMT,RM_DUP_ADDR) ;
}
}
else if (sm->smt_tid ==
smc->sm.pend[SMT_TID_NIF_TEST]) {
DB_SMT("SMT : NIF test TID ok\n",0,0) ;
}
else {
DB_SMT("SMT : expected TID %lx, got %lx\n",
smc->sm.pend[SMT_TID_NIF],sm->smt_tid) ;
}
break ;
default :
illegal = 2 ;
break ;
}
break ;
case SMT_SIF_CONFIG :
if (sm->smt_type != SMT_REQUEST)
break ;
DB_SMT("SMT : replying to SIF Config request from %s\n",
addr_to_string(&sm->smt_source),0) ;
smt_send_sif_config(smc,&sm->smt_source,sm->smt_tid,local) ;
break ;
case SMT_SIF_OPER :
if (sm->smt_type != SMT_REQUEST)
break ;
DB_SMT("SMT : replying to SIF Operation request from %s\n",
addr_to_string(&sm->smt_source),0) ;
smt_send_sif_operation(smc,&sm->smt_source,sm->smt_tid,local) ;
break ;
case SMT_ECF :
switch (sm->smt_type) {
case SMT_REPLY :
smc->mib.priv.fddiPRIVECF_Reply_Rx++ ;
DB_SMT("SMT: received ECF reply from %s\n",
addr_to_string(&sm->smt_source),0) ;
if (sm_to_para(smc,sm,SMT_P_ECHODATA) == NULL) {
DB_SMT("SMT: ECHODATA missing\n",0,0) ;
break ;
}
if (sm->smt_tid == smc->sm.pend[SMT_TID_ECF]) {
DB_SMT("SMT : ECF test TID ok\n",0,0) ;
}
else if (sm->smt_tid == smc->sm.pend[SMT_TID_ECF_UNA]) {
DB_SMT("SMT : ECF test UNA ok\n",0,0) ;
}
else if (sm->smt_tid == smc->sm.pend[SMT_TID_ECF_DNA]) {
DB_SMT("SMT : ECF test DNA ok\n",0,0) ;
}
else {
DB_SMT("SMT : expected TID %lx, got %lx\n",
smc->sm.pend[SMT_TID_ECF],
sm->smt_tid) ;
}
break ;
case SMT_REQUEST :
smc->mib.priv.fddiPRIVECF_Req_Rx++ ;
{
if (sm->smt_len && !sm_to_para(smc,sm,SMT_P_ECHODATA)) {
DB_SMT("SMT: ECF with para problem,sending RDF\n",0,0) ;
smt_send_rdf(smc,mb,m_fc(mb),SMT_RDF_LENGTH,
local) ;
break ;
}
DB_SMT("SMT - sending ECF reply to %s\n",
addr_to_string(&sm->smt_source),0) ;
sm->smt_dest = sm->smt_source ;
sm->smt_type = SMT_REPLY ;
dump_smt(smc,sm,"ECF REPLY") ;
smc->mib.priv.fddiPRIVECF_Reply_Tx++ ;
smt_send_frame(smc,mb,FC_SMT_INFO,local) ;
return ;
}
default :
illegal = 1 ;
break ;
}
break ;
#ifndef BOOT
case SMT_RAF :
#ifdef ESS
DB_ESSN(2,"ESS: RAF frame received\n",0,0) ;
fs = ess_raf_received_pack(smc,mb,sm,fs) ;
#endif
#ifdef SBA
DB_SBAN(2,"SBA: RAF frame received\n",0,0) ;
sba_raf_received_pack(smc,sm,fs) ;
#endif
break ;
case SMT_RDF :
smc->mib.priv.fddiPRIVRDF_Rx++ ;
break ;
case SMT_ESF :
if (sm->smt_type == SMT_REQUEST) {
DB_SMT("SMT - received ESF, sending RDF\n",0,0) ;
smt_send_rdf(smc,mb,m_fc(mb),SMT_RDF_CLASS,local) ;
}
break ;
case SMT_PMF_GET :
case SMT_PMF_SET :
if (sm->smt_type != SMT_REQUEST)
break ;
if (sm->smt_class == SMT_PMF_GET)
smc->mib.priv.fddiPRIVPMF_Get_Rx++ ;
else
smc->mib.priv.fddiPRIVPMF_Set_Rx++ ;
if ((sm->smt_class == SMT_PMF_SET) &&
!is_individual(&sm->smt_dest)) {
DB_SMT("SMT: ignoring PMF-SET with I/G set\n",0,0) ;
break ;
}
smt_pmf_received_pack(smc,mb, local) ;
break ;
case SMT_SRF :
dump_smt(smc,sm,"SRF received") ;
break ;
default :
if (sm->smt_type != SMT_REQUEST)
break ;
DB_SMT("SMT : class = %d, send RDF to %s\n",
sm->smt_class, addr_to_string(&sm->smt_source)) ;
smt_send_rdf(smc,mb,m_fc(mb),SMT_RDF_CLASS,local) ;
break ;
#endif
}
if (illegal) {
DB_SMT("SMT: discarding invalid frame, reason = %d\n",
illegal,0) ;
}
smt_free_mbuf(smc,mb) ;
}
static void update_dac(struct s_smc *smc, int report)
{
int cond ;
cond = ( smc->mib.m[MAC0].fddiMACUNDA_Flag |
smc->mib.m[MAC0].fddiMACDA_Flag) != 0 ;
if (report && (cond != smc->mib.m[MAC0].fddiMACDuplicateAddressCond))
smt_srf_event(smc, SMT_COND_MAC_DUP_ADDR,INDEX_MAC,cond) ;
else
smc->mib.m[MAC0].fddiMACDuplicateAddressCond = cond ;
}
void smt_send_frame(struct s_smc *smc, SMbuf *mb, int fc, int local)
{
struct smt_header *sm ;
if (!smc->r.sm_ma_avail && !local) {
smt_free_mbuf(smc,mb) ;
return ;
}
sm = smtod(mb,struct smt_header *) ;
sm->smt_source = smc->mib.m[MAC0].fddiMACSMTAddress ;
sm->smt_sid = smc->mib.fddiSMTStationId ;
smt_swap_para(sm,(int) mb->sm_len,0) ;
hwm_conv_can(smc,(char *)sm,12) ;
smc->mib.m[MAC0].fddiMACSMTTransmit_Ct++ ;
smt_send_mbuf(smc,mb,local ? FC_SMT_LOC : fc) ;
}
static void smt_send_rdf(struct s_smc *smc, SMbuf *rej, int fc, int reason,
int local)
{
SMbuf *mb ;
struct smt_header *sm ;
struct smt_rdf *rdf ;
int len ;
int frame_len ;
sm = smtod(rej,struct smt_header *) ;
if (sm->smt_type != SMT_REQUEST)
return ;
DB_SMT("SMT: sending RDF to %s,reason = 0x%x\n",
addr_to_string(&sm->smt_source),reason) ;
frame_len = rej->sm_len ;
if (!(mb=smt_build_frame(smc,SMT_RDF,SMT_REPLY,sizeof(struct smt_rdf))))
return ;
rdf = smtod(mb,struct smt_rdf *) ;
rdf->smt.smt_tid = sm->smt_tid ;
rdf->smt.smt_dest = sm->smt_source ;
rdf->reason.para.p_type = SMT_P_REASON ;
rdf->reason.para.p_len = sizeof(struct smt_p_reason) - PARA_LEN ;
rdf->reason.rdf_reason = reason ;
rdf->version.para.p_type = SMT_P_VERSION ;
rdf->version.para.p_len = sizeof(struct smt_p_version) - PARA_LEN ;
rdf->version.v_pad = 0 ;
rdf->version.v_n = 1 ;
rdf->version.v_index = 1 ;
rdf->version.v_version[0] = SMT_VID_2 ;
rdf->version.v_pad2 = 0 ;
if ((unsigned) frame_len <= SMT_MAX_INFO_LEN - sizeof(*rdf) +
2*sizeof(struct smt_header))
len = frame_len ;
else
len = SMT_MAX_INFO_LEN - sizeof(*rdf) +
2*sizeof(struct smt_header) ;
len &= ~3 ;
rdf->refused.para.p_type = SMT_P_REFUSED ;
rdf->refused.para.p_len = len + 4 ;
rdf->refused.ref_fc = fc ;
smt_swap_para(sm,frame_len,0) ;
memcpy((char *) &rdf->refused.ref_header,(char *) sm,len) ;
len -= sizeof(struct smt_header) ;
mb->sm_len += len ;
rdf->smt.smt_len += len ;
dump_smt(smc,(struct smt_header *)rdf,"RDF") ;
smc->mib.priv.fddiPRIVRDF_Tx++ ;
smt_send_frame(smc,mb,FC_SMT_INFO,local) ;
}
static void smt_send_nif(struct s_smc *smc, const struct fddi_addr *dest,
int fc, u_long tid, int type, int local)
{
struct smt_nif *nif ;
SMbuf *mb ;
if (!(mb = smt_build_frame(smc,SMT_NIF,type,sizeof(struct smt_nif))))
return ;
nif = smtod(mb, struct smt_nif *) ;
smt_fill_una(smc,&nif->una) ;
smt_fill_sde(smc,&nif->sde) ;
smt_fill_state(smc,&nif->state) ;
#ifdef SMT6_10
smt_fill_fsc(smc,&nif->fsc) ;
#endif
nif->smt.smt_dest = *dest ;
nif->smt.smt_tid = tid ;
dump_smt(smc,(struct smt_header *)nif,"NIF") ;
smt_send_frame(smc,mb,fc,local) ;
}
static void smt_send_nif_request(struct s_smc *smc, struct fddi_addr *dest)
{
smc->sm.pend[SMT_TID_NIF_TEST] = smt_get_tid(smc) ;
smt_send_nif(smc,dest, FC_SMT_INFO, smc->sm.pend[SMT_TID_NIF_TEST],
SMT_REQUEST,0) ;
}
static void smt_send_ecf_request(struct s_smc *smc, struct fddi_addr *dest,
int len)
{
smc->sm.pend[SMT_TID_ECF] = smt_get_tid(smc) ;
smt_send_ecf(smc,dest, FC_SMT_INFO, smc->sm.pend[SMT_TID_ECF],
SMT_REQUEST,len) ;
}
static void smt_echo_test(struct s_smc *smc, int dna)
{
u_long tid ;
smc->sm.pend[dna ? SMT_TID_ECF_DNA : SMT_TID_ECF_UNA] =
tid = smt_get_tid(smc) ;
smt_send_ecf(smc, dna ?
&smc->mib.m[MAC0].fddiMACDownstreamNbr :
&smc->mib.m[MAC0].fddiMACUpstreamNbr,
FC_SMT_INFO,tid, SMT_REQUEST, (SMT_TEST_ECHO_LEN & ~3)-8) ;
}
static void smt_send_ecf(struct s_smc *smc, struct fddi_addr *dest, int fc,
u_long tid, int type, int len)
{
struct smt_ecf *ecf ;
SMbuf *mb ;
if (!(mb = smt_build_frame(smc,SMT_ECF,type,SMT_ECF_LEN + len)))
return ;
ecf = smtod(mb, struct smt_ecf *) ;
smt_fill_echo(smc,&ecf->ec_echo,tid,len) ;
ecf->smt.smt_dest = *dest ;
ecf->smt.smt_tid = tid ;
smc->mib.priv.fddiPRIVECF_Req_Tx++ ;
smt_send_frame(smc,mb,fc,0) ;
}
static void smt_send_sif_config(struct s_smc *smc, struct fddi_addr *dest,
u_long tid, int local)
{
struct smt_sif_config *sif ;
SMbuf *mb ;
int len ;
if (!(mb = smt_build_frame(smc,SMT_SIF_CONFIG,SMT_REPLY,
SIZEOF_SMT_SIF_CONFIG)))
return ;
sif = smtod(mb, struct smt_sif_config *) ;
smt_fill_timestamp(smc,&sif->ts) ;
smt_fill_sde(smc,&sif->sde) ;
smt_fill_version(smc,&sif->version) ;
smt_fill_state(smc,&sif->state) ;
smt_fill_policy(smc,&sif->policy) ;
smt_fill_latency(smc,&sif->latency);
smt_fill_neighbor(smc,&sif->neighbor);
smt_fill_setcount(smc,&sif->setcount) ;
len = smt_fill_path(smc,&sif->path);
sif->smt.smt_dest = *dest ;
sif->smt.smt_tid = tid ;
smt_add_frame_len(mb,len) ;
dump_smt(smc,(struct smt_header *)sif,"SIF Configuration Reply") ;
smt_send_frame(smc,mb,FC_SMT_INFO,local) ;
}
static void smt_send_sif_operation(struct s_smc *smc, struct fddi_addr *dest,
u_long tid, int local)
{
struct smt_sif_operation *sif ;
SMbuf *mb ;
int ports ;
int i ;
ports = NUMPHYS ;
#ifndef CONCENTRATOR
if (smc->s.sas == SMT_SAS)
ports = 1 ;
#endif
if (!(mb = smt_build_frame(smc,SMT_SIF_OPER,SMT_REPLY,
SIZEOF_SMT_SIF_OPERATION+ports*sizeof(struct smt_p_lem))))
return ;
sif = smtod(mb, struct smt_sif_operation *) ;
smt_fill_timestamp(smc,&sif->ts) ;
smt_fill_mac_status(smc,&sif->status) ;
smt_fill_mac_counter(smc,&sif->mc) ;
smt_fill_mac_fnc(smc,&sif->fnc) ;
smt_fill_manufacturer(smc,&sif->man) ;
smt_fill_user(smc,&sif->user) ;
smt_fill_setcount(smc,&sif->setcount) ;
if (ports == 1) {
smt_fill_lem(smc,sif->lem,PS) ;
}
else {
for (i = 0 ; i < ports ; i++) {
smt_fill_lem(smc,&sif->lem[i],i) ;
}
}
sif->smt.smt_dest = *dest ;
sif->smt.smt_tid = tid ;
dump_smt(smc,(struct smt_header *)sif,"SIF Operation Reply") ;
smt_send_frame(smc,mb,FC_SMT_INFO,local) ;
}
SMbuf *smt_build_frame(struct s_smc *smc, int class, int type,
int length)
{
SMbuf *mb ;
struct smt_header *smt ;
#if 0
if (!smc->r.sm_ma_avail) {
return 0;
}
#endif
if (!(mb = smt_get_mbuf(smc)))
return mb;
mb->sm_len = length ;
smt = smtod(mb, struct smt_header *) ;
smt->smt_dest = fddi_broadcast ;
smt->smt_class = class ;
smt->smt_type = type ;
switch (class) {
case SMT_NIF :
case SMT_SIF_CONFIG :
case SMT_SIF_OPER :
case SMT_ECF :
smt->smt_version = SMT_VID ;
break ;
default :
smt->smt_version = SMT_VID_2 ;
break ;
}
smt->smt_tid = smt_get_tid(smc) ;
smt->smt_pad = 0 ;
smt->smt_len = length - sizeof(struct smt_header) ;
return mb;
}
static void smt_add_frame_len(SMbuf *mb, int len)
{
struct smt_header *smt ;
smt = smtod(mb, struct smt_header *) ;
smt->smt_len += len ;
mb->sm_len += len ;
}
static void smt_fill_una(struct s_smc *smc, struct smt_p_una *una)
{
SMTSETPARA(una,SMT_P_UNA) ;
una->una_pad = 0 ;
una->una_node = smc->mib.m[MAC0].fddiMACUpstreamNbr ;
}
static void smt_fill_sde(struct s_smc *smc, struct smt_p_sde *sde)
{
SMTSETPARA(sde,SMT_P_SDE) ;
sde->sde_non_master = smc->mib.fddiSMTNonMaster_Ct ;
sde->sde_master = smc->mib.fddiSMTMaster_Ct ;
sde->sde_mac_count = NUMMACS ;
#ifdef CONCENTRATOR
sde->sde_type = SMT_SDE_CONCENTRATOR ;
#else
sde->sde_type = SMT_SDE_STATION ;
#endif
}
static void smt_fill_state(struct s_smc *smc, struct smt_p_state *state)
{
int top ;
int twist ;
SMTSETPARA(state,SMT_P_STATE) ;
state->st_pad = 0 ;
top = 0 ;
if (smc->mib.fddiSMTPeerWrapFlag) {
top |= SMT_ST_WRAPPED ;
}
#ifdef CONCENTRATOR
if (cfm_status_unattached(smc)) {
top |= SMT_ST_UNATTACHED ;
}
#endif
if ((twist = pcm_status_twisted(smc)) & 1) {
top |= SMT_ST_TWISTED_A ;
}
if (twist & 2) {
top |= SMT_ST_TWISTED_B ;
}
#ifdef OPT_SRF
top |= SMT_ST_SRF ;
#endif
if (pcm_rooted_station(smc))
top |= SMT_ST_ROOTED_S ;
if (smc->mib.a[0].fddiPATHSbaPayload != 0)
top |= SMT_ST_SYNC_SERVICE ;
state->st_topology = top ;
state->st_dupl_addr =
((smc->mib.m[MAC0].fddiMACDA_Flag ? SMT_ST_MY_DUPA : 0 ) |
(smc->mib.m[MAC0].fddiMACUNDA_Flag ? SMT_ST_UNA_DUPA : 0)) ;
}
static void smt_fill_timestamp(struct s_smc *smc, struct smt_p_timestamp *ts)
{
SMTSETPARA(ts,SMT_P_TIMESTAMP) ;
smt_set_timestamp(smc,ts->ts_time) ;
}
void smt_set_timestamp(struct s_smc *smc, u_char *p)
{
u_long time ;
u_long utime ;
utime = smt_get_time() ;
time = utime * 100 ;
time /= TICKS_PER_SECOND ;
p[0] = 0 ;
p[1] = (u_char)((time>>(8+8+8+8-1)) & 1) ;
p[2] = (u_char)(time>>(8+8+8-1)) ;
p[3] = (u_char)(time>>(8+8-1)) ;
p[4] = (u_char)(time>>(8-1)) ;
p[5] = (u_char)(time<<1) ;
p[6] = (u_char)(smc->sm.uniq_ticks>>8) ;
p[7] = (u_char)smc->sm.uniq_ticks ;
if (utime != smc->sm.uniq_time) {
smc->sm.uniq_ticks = 0 ;
}
smc->sm.uniq_ticks++ ;
smc->sm.uniq_time = utime ;
}
static void smt_fill_policy(struct s_smc *smc, struct smt_p_policy *policy)
{
int i ;
const u_char *map ;
u_short in ;
u_short out ;
static const u_char ansi_weirdness[16] = {
0,7,5,3,8,1,6,4,9,10,2,11,12,13,14,15
} ;
SMTSETPARA(policy,SMT_P_POLICY) ;
out = 0 ;
in = smc->mib.fddiSMTConnectionPolicy ;
for (i = 0, map = ansi_weirdness ; i < 16 ; i++) {
if (in & 1)
out |= (1<<*map) ;
in >>= 1 ;
map++ ;
}
policy->pl_config = smc->mib.fddiSMTConfigPolicy ;
policy->pl_connect = out ;
}
static void smt_fill_latency(struct s_smc *smc, struct smt_p_latency *latency)
{
SMTSETPARA(latency,SMT_P_LATENCY) ;
latency->lt_phyout_idx1 = phy_index(smc,0) ;
latency->lt_latency1 = 10 ;
if (smc->s.sas == SMT_DAS) {
latency->lt_phyout_idx2 = phy_index(smc,1) ;
latency->lt_latency2 = 10 ;
}
else {
latency->lt_phyout_idx2 = 0 ;
latency->lt_latency2 = 0 ;
}
}
static void smt_fill_neighbor(struct s_smc *smc, struct smt_p_neighbor *neighbor)
{
SMTSETPARA(neighbor,SMT_P_NEIGHBORS) ;
neighbor->nb_mib_index = INDEX_MAC ;
neighbor->nb_mac_index = mac_index(smc,1) ;
neighbor->nb_una = smc->mib.m[MAC0].fddiMACUpstreamNbr ;
neighbor->nb_dna = smc->mib.m[MAC0].fddiMACDownstreamNbr ;
}
static int smt_fill_path(struct s_smc *smc, struct smt_p_path *path)
{
SK_LOC_DECL(int,type) ;
SK_LOC_DECL(int,state) ;
SK_LOC_DECL(int,remote) ;
SK_LOC_DECL(int,mac) ;
int len ;
int p ;
int physp ;
struct smt_phy_rec *phy ;
struct smt_mac_rec *pd_mac ;
len = PARA_LEN +
sizeof(struct smt_mac_rec) * NUMMACS +
sizeof(struct smt_phy_rec) * ALLPHYS ;
path->para.p_type = SMT_P_PATH ;
path->para.p_len = len - PARA_LEN ;
for (p = 0,phy = path->pd_phy ; p < ALLPHYS ; p++, phy++) {
physp = p ;
#ifndef CONCENTRATOR
if (smc->s.sas == SMT_SAS)
physp = PS ;
#endif
pcm_status_state(smc,physp,&type,&state,&remote,&mac) ;
#ifdef LITTLE_ENDIAN
phy->phy_mib_index = smt_swap_short((u_short)p+INDEX_PORT) ;
#else
phy->phy_mib_index = p+INDEX_PORT ;
#endif
phy->phy_type = type ;
phy->phy_connect_state = state ;
phy->phy_remote_type = remote ;
phy->phy_remote_mac = mac ;
phy->phy_resource_idx = phy_con_resource_index(smc,p) ;
}
pd_mac = (struct smt_mac_rec *) phy ;
pd_mac->mac_addr = smc->mib.m[MAC0].fddiMACSMTAddress ;
pd_mac->mac_resource_idx = mac_con_resource_index(smc,1) ;
return len;
}
static void smt_fill_mac_status(struct s_smc *smc, struct smt_p_mac_status *st)
{
SMTSETPARA(st,SMT_P_MAC_STATUS) ;
st->st_mib_index = INDEX_MAC ;
st->st_mac_index = mac_index(smc,1) ;
mac_update_counter(smc) ;
st->st_t_req = smc->mib.m[MAC0].fddiMACT_Req ;
st->st_t_neg = smc->mib.m[MAC0].fddiMACT_Neg ;
st->st_t_max = smc->mib.m[MAC0].fddiMACT_Max ;
st->st_tvx_value = smc->mib.m[MAC0].fddiMACTvxValue ;
st->st_t_min = smc->mib.m[MAC0].fddiMACT_Min ;
st->st_sba = smc->mib.a[PATH0].fddiPATHSbaPayload ;
st->st_frame_ct = smc->mib.m[MAC0].fddiMACFrame_Ct ;
st->st_error_ct = smc->mib.m[MAC0].fddiMACError_Ct ;
st->st_lost_ct = smc->mib.m[MAC0].fddiMACLost_Ct ;
}
static void smt_fill_lem(struct s_smc *smc, struct smt_p_lem *lem, int phy)
{
struct fddi_mib_p *mib ;
mib = smc->y[phy].mib ;
SMTSETPARA(lem,SMT_P_LEM) ;
lem->lem_mib_index = phy+INDEX_PORT ;
lem->lem_phy_index = phy_index(smc,phy) ;
lem->lem_pad2 = 0 ;
lem->lem_cutoff = mib->fddiPORTLer_Cutoff ;
lem->lem_alarm = mib->fddiPORTLer_Alarm ;
lem->lem_estimate = mib->fddiPORTLer_Estimate ;
lem->lem_reject_ct = mib->fddiPORTLem_Reject_Ct ;
lem->lem_ct = mib->fddiPORTLem_Ct ;
}
static void smt_fill_version(struct s_smc *smc, struct smt_p_version *vers)
{
SK_UNUSED(smc) ;
SMTSETPARA(vers,SMT_P_VERSION) ;
vers->v_pad = 0 ;
vers->v_n = 1 ;
vers->v_index = 1 ;
vers->v_version[0] = SMT_VID_2 ;
vers->v_pad2 = 0 ;
}
static void smt_fill_fsc(struct s_smc *smc, struct smt_p_fsc *fsc)
{
SK_UNUSED(smc) ;
SMTSETPARA(fsc,SMT_P_FSC) ;
fsc->fsc_pad0 = 0 ;
fsc->fsc_mac_index = INDEX_MAC ;
fsc->fsc_pad1 = 0 ;
fsc->fsc_value = FSC_TYPE0 ;
#ifdef LITTLE_ENDIAN
fsc->fsc_mac_index = smt_swap_short(INDEX_MAC) ;
fsc->fsc_value = smt_swap_short(FSC_TYPE0) ;
#endif
}
static void smt_fill_mac_counter(struct s_smc *smc, struct smt_p_mac_counter *mc)
{
SMTSETPARA(mc,SMT_P_MAC_COUNTER) ;
mc->mc_mib_index = INDEX_MAC ;
mc->mc_index = mac_index(smc,1) ;
mc->mc_receive_ct = smc->mib.m[MAC0].fddiMACCopied_Ct ;
mc->mc_transmit_ct = smc->mib.m[MAC0].fddiMACTransmit_Ct ;
}
static void smt_fill_mac_fnc(struct s_smc *smc, struct smt_p_mac_fnc *fnc)
{
SMTSETPARA(fnc,SMT_P_MAC_FNC) ;
fnc->nc_mib_index = INDEX_MAC ;
fnc->nc_index = mac_index(smc,1) ;
fnc->nc_counter = smc->mib.m[MAC0].fddiMACNotCopied_Ct ;
}
static void smt_fill_manufacturer(struct s_smc *smc,
struct smp_p_manufacturer *man)
{
SMTSETPARA(man,SMT_P_MANUFACTURER) ;
memcpy((char *) man->mf_data,
(char *) smc->mib.fddiSMTManufacturerData,
sizeof(man->mf_data)) ;
}
static void smt_fill_user(struct s_smc *smc, struct smp_p_user *user)
{
SMTSETPARA(user,SMT_P_USER) ;
memcpy((char *) user->us_data,
(char *) smc->mib.fddiSMTUserData,
sizeof(user->us_data)) ;
}
static void smt_fill_setcount(struct s_smc *smc, struct smt_p_setcount *setcount)
{
SK_UNUSED(smc) ;
SMTSETPARA(setcount,SMT_P_SETCOUNT) ;
setcount->count = smc->mib.fddiSMTSetCount.count ;
memcpy((char *)setcount->timestamp,
(char *)smc->mib.fddiSMTSetCount.timestamp,8) ;
}
static void smt_fill_echo(struct s_smc *smc, struct smt_p_echo *echo, u_long seed,
int len)
{
u_char *p ;
SK_UNUSED(smc) ;
SMTSETPARA(echo,SMT_P_ECHODATA) ;
echo->para.p_len = len ;
for (p = echo->ec_data ; len ; len--) {
*p++ = (u_char) seed ;
seed += 13 ;
}
}
static void smt_clear_una_dna(struct s_smc *smc)
{
smc->mib.m[MAC0].fddiMACUpstreamNbr = SMT_Unknown ;
smc->mib.m[MAC0].fddiMACDownstreamNbr = SMT_Unknown ;
}
static void smt_clear_old_una_dna(struct s_smc *smc)
{
smc->mib.m[MAC0].fddiMACOldUpstreamNbr = SMT_Unknown ;
smc->mib.m[MAC0].fddiMACOldDownstreamNbr = SMT_Unknown ;
}
u_long smt_get_tid(struct s_smc *smc)
{
u_long tid ;
while ((tid = ++(smc->sm.smt_tid) ^ SMT_TID_MAGIC) == 0)
;
return tid & 0x3fffffffL;
}
int smt_check_para(struct s_smc *smc, struct smt_header *sm,
const u_short list[])
{
const u_short *p = list ;
while (*p) {
if (!sm_to_para(smc,sm,(int) *p)) {
DB_SMT("SMT: smt_check_para - missing para %x\n",*p,0);
return -1;
}
p++ ;
}
return 0;
}
void *sm_to_para(struct s_smc *smc, struct smt_header *sm, int para)
{
char *p ;
int len ;
int plen ;
void *found = NULL;
SK_UNUSED(smc) ;
len = sm->smt_len ;
p = (char *)(sm+1) ;
while (len > 0 ) {
if (((struct smt_para *)p)->p_type == para)
found = (void *) p ;
plen = ((struct smt_para *)p)->p_len + PARA_LEN ;
p += plen ;
len -= plen ;
if (len < 0) {
DB_SMT("SMT : sm_to_para - length error %d\n",plen,0) ;
return NULL;
}
if ((plen & 3) && (para != SMT_P_ECHODATA)) {
DB_SMT("SMT : sm_to_para - odd length %d\n",plen,0) ;
return NULL;
}
if (found)
return found;
}
return NULL;
}
char *addr_to_string(struct fddi_addr *addr)
{
int i ;
static char string[6*3] = "****" ;
for (i = 0 ; i < 6 ; i++) {
string[i * 3] = hex_asc_hi(addr->a[i]);
string[i * 3 + 1] = hex_asc_lo(addr->a[i]);
string[i * 3 + 2] = ':';
}
string[5 * 3 + 2] = 0;
return string;
}
int smt_ifconfig(int argc, char *argv[])
{
if (argc >= 2 && !strcmp(argv[0],"opt_bypass") &&
!strcmp(argv[1],"yes")) {
smc->mib.fddiSMTBypassPresent = 1 ;
return 0;
}
return amdfddi_config(0, argc, argv);
}
static int mac_index(struct s_smc *smc, int mac)
{
SK_UNUSED(mac) ;
#ifdef CONCENTRATOR
SK_UNUSED(smc) ;
return NUMPHYS + 1;
#else
return (smc->s.sas == SMT_SAS) ? 2 : 3;
#endif
}
static int phy_index(struct s_smc *smc, int phy)
{
SK_UNUSED(smc) ;
return phy + 1;
}
static int mac_con_resource_index(struct s_smc *smc, int mac)
{
#ifdef CONCENTRATOR
SK_UNUSED(smc) ;
SK_UNUSED(mac) ;
return entity_to_index(smc, cem_get_downstream(smc, ENTITY_MAC));
#else
SK_UNUSED(mac) ;
switch (smc->mib.fddiSMTCF_State) {
case SC9_C_WRAP_A :
case SC5_THRU_B :
case SC11_C_WRAP_S :
return 1;
case SC10_C_WRAP_B :
case SC4_THRU_A :
return 2;
}
return smc->s.sas == SMT_SAS ? 2 : 3;
#endif
}
static int phy_con_resource_index(struct s_smc *smc, int phy)
{
#ifdef CONCENTRATOR
return entity_to_index(smc, cem_get_downstream(smc, ENTITY_PHY(phy))) ;
#else
switch (smc->mib.fddiSMTCF_State) {
case SC9_C_WRAP_A :
return phy == PA ? 3 : 2;
case SC10_C_WRAP_B :
return phy == PA ? 1 : 3;
case SC4_THRU_A :
return phy == PA ? 3 : 1;
case SC5_THRU_B :
return phy == PA ? 2 : 3;
case SC11_C_WRAP_S :
return 2;
}
return phy;
#endif
}
static int entity_to_index(struct s_smc *smc, int e)
{
if (e == ENTITY_MAC)
return mac_index(smc, 1);
else
return phy_index(smc, e - ENTITY_PHY(0));
}
static int smt_swap_short(u_short s)
{
return ((s>>8)&0xff) | ((s&0xff)<<8);
}
void smt_swap_para(struct smt_header *sm, int len, int direction)
{
struct smt_para *pa ;
const struct smt_pdef *pd ;
char *p ;
int plen ;
int type ;
int i ;
smt_string_swap((char *)sm,SWAP_SMTHEADER,len) ;
len -= sizeof(struct smt_header) ;
p = (char *) (sm + 1) ;
while (len > 0) {
pa = (struct smt_para *) p ;
plen = pa->p_len ;
type = pa->p_type ;
pa->p_type = smt_swap_short(pa->p_type) ;
pa->p_len = smt_swap_short(pa->p_len) ;
if (direction) {
plen = pa->p_len ;
type = pa->p_type ;
}
if (plen < 0)
break ;
plen += PARA_LEN ;
for (i = N_SMT_PLEN, pd = smt_pdef; i ; i--,pd++) {
if (pd->ptype == type)
break ;
}
if (i && pd->pswap) {
smt_string_swap(p+PARA_LEN,pd->pswap,len) ;
}
len -= plen ;
p += plen ;
}
}
static void smt_string_swap(char *data, const char *format, int len)
{
const char *open_paren = NULL ;
int x ;
while (len > 0 && *format) {
switch (*format) {
case '[' :
open_paren = format ;
break ;
case ']' :
format = open_paren ;
break ;
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
data += *format - '0' ;
len -= *format - '0' ;
break ;
case 'c':
data++ ;
len-- ;
break ;
case 's' :
x = data[0] ;
data[0] = data[1] ;
data[1] = x ;
data += 2 ;
len -= 2 ;
break ;
case 'l' :
x = data[0] ;
data[0] = data[3] ;
data[3] = x ;
x = data[1] ;
data[1] = data[2] ;
data[2] = x ;
data += 4 ;
len -= 4 ;
break ;
}
format++ ;
}
}
void smt_swap_para(struct smt_header *sm, int len, int direction)
{
SK_UNUSED(sm) ;
SK_UNUSED(len) ;
SK_UNUSED(direction) ;
}
int smt_action(struct s_smc *smc, int class, int code, int index)
{
int event ;
int port ;
DB_SMT("SMT: action %d code %d\n",class,code) ;
switch(class) {
case SMT_STATION_ACTION :
switch(code) {
case SMT_STATION_ACTION_CONNECT :
smc->mib.fddiSMTRemoteDisconnectFlag = FALSE ;
queue_event(smc,EVENT_ECM,EC_CONNECT) ;
break ;
case SMT_STATION_ACTION_DISCONNECT :
queue_event(smc,EVENT_ECM,EC_DISCONNECT) ;
smc->mib.fddiSMTRemoteDisconnectFlag = TRUE ;
RS_SET(smc,RS_DISCONNECT) ;
AIX_EVENT(smc, (u_long) FDDI_RING_STATUS, (u_long)
FDDI_SMT_EVENT, (u_long) FDDI_REMOTE_DISCONNECT,
smt_get_event_word(smc));
break ;
case SMT_STATION_ACTION_PATHTEST :
AIX_EVENT(smc, (u_long) FDDI_RING_STATUS, (u_long)
FDDI_SMT_EVENT, (u_long) FDDI_PATH_TEST,
smt_get_event_word(smc));
break ;
case SMT_STATION_ACTION_SELFTEST :
AIX_EVENT(smc, (u_long) FDDI_RING_STATUS, (u_long)
FDDI_SMT_EVENT, (u_long) FDDI_REMOTE_SELF_TEST,
smt_get_event_word(smc));
break ;
case SMT_STATION_ACTION_DISABLE_A :
if (smc->y[PA].pc_mode == PM_PEER) {
RS_SET(smc,RS_EVENT) ;
queue_event(smc,EVENT_PCM+PA,PC_DISABLE) ;
}
break ;
case SMT_STATION_ACTION_DISABLE_B :
if (smc->y[PB].pc_mode == PM_PEER) {
RS_SET(smc,RS_EVENT) ;
queue_event(smc,EVENT_PCM+PB,PC_DISABLE) ;
}
break ;
case SMT_STATION_ACTION_DISABLE_M :
for (port = 0 ; port < NUMPHYS ; port++) {
if (smc->mib.p[port].fddiPORTMy_Type != TM)
continue ;
RS_SET(smc,RS_EVENT) ;
queue_event(smc,EVENT_PCM+port,PC_DISABLE) ;
}
break ;
default :
return 1;
}
break ;
case SMT_PORT_ACTION :
switch(code) {
case SMT_PORT_ACTION_ENABLE :
event = PC_ENABLE ;
break ;
case SMT_PORT_ACTION_DISABLE :
event = PC_DISABLE ;
break ;
case SMT_PORT_ACTION_MAINT :
event = PC_MAINT ;
break ;
case SMT_PORT_ACTION_START :
event = PC_START ;
break ;
case SMT_PORT_ACTION_STOP :
event = PC_STOP ;
break ;
default :
return 1;
}
queue_event(smc,EVENT_PCM+index,event) ;
break ;
default :
return 1;
}
return 0;
}
static void hwm_conv_can(struct s_smc *smc, char *data, int len)
{
int i ;
SK_UNUSED(smc) ;
for (i = len; i ; i--, data++)
*data = bitrev8(*data);
}
