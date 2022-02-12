void smt_pmf_received_pack(struct s_smc *smc, SMbuf *mb, int local)
{
struct smt_header *sm ;
SMbuf *reply ;
sm = smtod(mb,struct smt_header *) ;
DB_SMT("SMT: processing PMF frame at %x len %d\n",sm,mb->sm_len) ;
#ifdef DEBUG
dump_smt(smc,sm,"PMF Received") ;
#endif
smt_start_watchdog(smc) ;
if (sm->smt_class == SMT_PMF_GET ||
sm->smt_class == SMT_PMF_SET) {
reply = smt_build_pmf_response(smc,sm,
sm->smt_class == SMT_PMF_SET,local) ;
if (reply) {
sm = smtod(reply,struct smt_header *) ;
#ifdef DEBUG
dump_smt(smc,sm,"PMF Reply") ;
#endif
smt_send_frame(smc,reply,FC_SMT_INFO,local) ;
}
}
}
static SMbuf *smt_build_pmf_response(struct s_smc *smc, struct smt_header *req,
int set, int local)
{
SMbuf *mb ;
struct smt_header *smt ;
struct smt_para *pa ;
struct smt_p_reason *res ;
const struct s_p_tab *pt ;
int len ;
int index ;
int idx_end ;
int error ;
int range ;
SK_LOC_DECL(struct s_pcon,pcon) ;
SK_LOC_DECL(struct s_pcon,set_pcon) ;
if (!(mb = smt_get_mbuf(smc)))
return mb;
smt = smtod(mb, struct smt_header *) ;
smt->smt_dest = req->smt_source ;
smt->smt_class = req->smt_class ;
smt->smt_type = SMT_REPLY ;
smt->smt_version = SMT_VID_2 ;
smt->smt_tid = req->smt_tid ;
smt->smt_pad = 0 ;
smt->smt_len = 0 ;
pcon.pc_len = SMT_MAX_INFO_LEN ;
pcon.pc_err = 0 ;
pcon.pc_badset = 0 ;
pcon.pc_p = (void *) (smt + 1) ;
error = 0 ;
if (set) {
if (!local && smt_authorize(smc,req))
error = SMT_RDF_AUTHOR ;
else if (smt_check_set_count(smc,req))
pcon.pc_badset = SMT_RDF_BADSET ;
}
res = (struct smt_p_reason *) pcon.pc_p ;
smt_add_para(smc,&pcon,(u_short) SMT_P_REASON,0,0) ;
smt_add_para(smc,&pcon,(u_short) SMT_P1033,0,0) ;
set_pcon = pcon ;
smt_add_para(smc,&pcon,(u_short) SMT_P1035,0,0) ;
smt_add_para(smc,&pcon,(u_short) SMT_P1036,0,0) ;
pcon.pc_err = error ;
len = req->smt_len ;
pa = (struct smt_para *) (req + 1) ;
while (!pcon.pc_err && len > 0 ) {
if (((u_short)len < pa->p_len + PARA_LEN) || (pa->p_len & 3)) {
pcon.pc_err = SMT_RDF_LENGTH ;
break ;
}
if (((range = (pa->p_type & 0xf000)) == 0x2000) ||
range == 0x3000 || range == 0x4000) {
index = *((u_char *)pa + PARA_LEN + 3) ;
idx_end = index ;
if (!set && (pa->p_len != 4)) {
pcon.pc_err = SMT_RDF_LENGTH ;
break ;
}
if (!index && !set) {
switch (range) {
case 0x2000 :
index = INDEX_MAC ;
idx_end = index - 1 + NUMMACS ;
break ;
case 0x3000 :
index = INDEX_PATH ;
idx_end = index - 1 + NUMPATHS ;
break ;
case 0x4000 :
index = INDEX_PORT ;
idx_end = index - 1 + NUMPHYS ;
#ifndef CONCENTRATOR
if (smc->s.sas == SMT_SAS)
idx_end = INDEX_PORT ;
#endif
break ;
}
}
}
else {
if (!set && (pa->p_len != 0)) {
pcon.pc_err = SMT_RDF_LENGTH ;
break ;
}
index = 0 ;
idx_end = 0 ;
}
while (index <= idx_end) {
pt = smt_get_ptab(pa->p_type) ;
if (pt && pt->p_access == AC_GROUP && !set) {
pt++ ;
while (pt->p_access == AC_G ||
pt->p_access == AC_GR) {
smt_add_para(smc,&pcon,pt->p_num,
index,local);
pt++ ;
}
}
else if (pa->p_type != SMT_P_AUTHOR &&
(!set || (pa->p_type != SMT_P1035))) {
int st ;
if (pcon.pc_badset) {
smt_add_para(smc,&pcon,pa->p_type,
index,local) ;
}
else if (set) {
st = smt_set_para(smc,pa,index,local,1);
smt_add_para(smc,&pcon,pa->p_type,
index,local) ;
pcon.pc_err = st ;
}
else {
if (pt && pt->p_access == AC_S) {
pcon.pc_err =
SMT_RDF_ILLEGAL ;
}
smt_add_para(smc,&pcon,pa->p_type,
index,local) ;
}
}
if (pcon.pc_err)
break ;
index++ ;
}
len -= pa->p_len + PARA_LEN ;
pa = (struct smt_para *) ((char *)pa + pa->p_len + PARA_LEN) ;
}
smt->smt_len = SMT_MAX_INFO_LEN - pcon.pc_len ;
mb->sm_len = smt->smt_len + sizeof(struct smt_header) ;
res->rdf_reason = pcon.pc_badset ? pcon.pc_badset :
pcon.pc_err ? pcon.pc_err : SMT_RDF_SUCCESS ;
if (set && (res->rdf_reason == SMT_RDF_SUCCESS)) {
smc->mib.fddiSMTSetCount.count++ ;
smt_set_timestamp(smc,smc->mib.fddiSMTSetCount.timestamp) ;
smc->mib.fddiSMTLastSetStationId = req->smt_sid ;
smt_add_para(smc,&set_pcon,(u_short) SMT_P1035,0,0) ;
smt_add_para(smc,&set_pcon,(u_short) SMT_P1036,0,0) ;
}
return mb;
}
static int smt_authorize(struct s_smc *smc, struct smt_header *sm)
{
struct smt_para *pa ;
int i ;
char *p ;
p = (char *) &smc->mib.fddiPRPMFStation ;
for (i = 0 ; i < 8 && !p[i] ; i++)
;
if (i != 8) {
if (memcmp((char *) &sm->smt_sid,
(char *) &smc->mib.fddiPRPMFStation,8))
return 1;
}
p = (char *) smc->mib.fddiPRPMFPasswd ;
for (i = 0 ; i < 8 && !p[i] ; i++)
;
if (i != 8) {
pa = (struct smt_para *) sm_to_para(smc,sm,SMT_P_AUTHOR) ;
if (!pa)
return 1;
if (pa->p_len != 8)
return 1;
if (memcmp((char *)(pa+1),(char *)smc->mib.fddiPRPMFPasswd,8))
return 1;
}
return 0;
}
static int smt_check_set_count(struct s_smc *smc, struct smt_header *sm)
{
struct smt_para *pa ;
struct smt_p_setcount *sc ;
pa = (struct smt_para *) sm_to_para(smc,sm,SMT_P1035) ;
if (pa) {
sc = (struct smt_p_setcount *) pa ;
if ((smc->mib.fddiSMTSetCount.count != sc->count) ||
memcmp((char *) smc->mib.fddiSMTSetCount.timestamp,
(char *)sc->timestamp,8))
return 1;
}
return 0;
}
void smt_add_para(struct s_smc *smc, struct s_pcon *pcon, u_short para,
int index, int local)
{
struct smt_para *pa ;
const struct s_p_tab *pt ;
struct fddi_mib_m *mib_m = NULL;
struct fddi_mib_p *mib_p = NULL;
int len ;
int plen ;
char *from ;
char *to ;
const char *swap ;
char c ;
int range ;
char *mib_addr ;
int mac ;
int path ;
int port ;
int sp_len ;
if (pcon->pc_err)
return ;
pt = smt_get_ptab(para) ;
if (pt && pt->p_access == AC_S)
return ;
to = (char *) (pcon->pc_p) ;
len = pcon->pc_len ;
plen = len ;
pa = (struct smt_para *) to ;
to += PARA_LEN ;
len -= PARA_LEN ;
if (((range = (para & 0xf000)) == 0x2000) ||
range == 0x3000 || range == 0x4000) {
if (len < 4)
goto wrong_error ;
to[0] = 0 ;
to[1] = 0 ;
to[2] = 0 ;
to[3] = index ;
len -= 4 ;
to += 4 ;
}
mac = index - INDEX_MAC ;
path = index - INDEX_PATH ;
port = index - INDEX_PORT ;
switch (range) {
case 0x1000 :
default :
mib_addr = (char *) (&smc->mib) ;
break ;
case 0x2000 :
if (mac < 0 || mac >= NUMMACS) {
pcon->pc_err = SMT_RDF_NOPARAM ;
return ;
}
mib_addr = (char *) (&smc->mib.m[mac]) ;
mib_m = (struct fddi_mib_m *) mib_addr ;
break ;
case 0x3000 :
if (path < 0 || path >= NUMPATHS) {
pcon->pc_err = SMT_RDF_NOPARAM ;
return ;
}
mib_addr = (char *) (&smc->mib.a[path]) ;
break ;
case 0x4000 :
if (port < 0 || port >= smt_mib_phys(smc)) {
pcon->pc_err = SMT_RDF_NOPARAM ;
return ;
}
mib_addr = (char *) (&smc->mib.p[port_to_mib(smc,port)]) ;
mib_p = (struct fddi_mib_p *) mib_addr ;
break ;
}
swap = NULL;
switch (para) {
case SMT_P10F0 :
case SMT_P10F1 :
#ifdef ESS
case SMT_P10F2 :
case SMT_P10F3 :
case SMT_P10F4 :
case SMT_P10F5 :
case SMT_P10F6 :
case SMT_P10F7 :
#endif
#ifdef SBA
case SMT_P10F8 :
case SMT_P10F9 :
#endif
case SMT_P20F1 :
if (!local) {
pcon->pc_err = SMT_RDF_NOPARAM ;
return ;
}
break ;
case SMT_P2034 :
case SMT_P2046 :
case SMT_P2047 :
case SMT_P204A :
case SMT_P2051 :
case SMT_P2052 :
mac_update_counter(smc) ;
break ;
case SMT_P4022:
mib_p->fddiPORTPC_LS = LS2MIB(
sm_pm_get_ls(smc,port_to_mib(smc,port))) ;
break ;
case SMT_P_REASON :
*(u32 *)to = 0 ;
sp_len = 4 ;
goto sp_done ;
case SMT_P1033 :
smt_set_timestamp(smc,smc->mib.fddiSMTTimeStamp) ;
break ;
case SMT_P1020:
#if NUMPHYS == 12
swap = "IIIIIIIIIIII" ;
#else
#if NUMPHYS == 2
if (smc->s.sas == SMT_SAS)
swap = "I" ;
else
swap = "II" ;
#else
#if NUMPHYS == 24
swap = "IIIIIIIIIIIIIIIIIIIIIIII" ;
#else
????
#endif
#endif
#endif
break ;
case SMT_P3212 :
{
sp_len = cem_build_path(smc,to,path) ;
goto sp_done ;
}
case SMT_P1048 :
{
struct smt_p_1048 *sp ;
sp = (struct smt_p_1048 *) to ;
sp->p1048_flag = smc->mib.fddiSMTPeerWrapFlag ;
sp->p1048_cf_state = smc->mib.fddiSMTCF_State ;
sp_len = sizeof(struct smt_p_1048) ;
goto sp_done ;
}
case SMT_P208C :
{
struct smt_p_208c *sp ;
sp = (struct smt_p_208c *) to ;
sp->p208c_flag =
smc->mib.m[MAC0].fddiMACDuplicateAddressCond ;
sp->p208c_dupcondition =
(mib_m->fddiMACDA_Flag ? SMT_ST_MY_DUPA : 0) |
(mib_m->fddiMACUNDA_Flag ? SMT_ST_UNA_DUPA : 0);
sp->p208c_fddilong =
mib_m->fddiMACSMTAddress ;
sp->p208c_fddiunalong =
mib_m->fddiMACUpstreamNbr ;
sp->p208c_pad = 0 ;
sp_len = sizeof(struct smt_p_208c) ;
goto sp_done ;
}
case SMT_P208D :
{
struct smt_p_208d *sp ;
sp = (struct smt_p_208d *) to ;
sp->p208d_flag =
mib_m->fddiMACFrameErrorFlag ;
sp->p208d_frame_ct =
mib_m->fddiMACFrame_Ct ;
sp->p208d_error_ct =
mib_m->fddiMACError_Ct ;
sp->p208d_lost_ct =
mib_m->fddiMACLost_Ct ;
sp->p208d_ratio =
mib_m->fddiMACFrameErrorRatio ;
sp_len = sizeof(struct smt_p_208d) ;
goto sp_done ;
}
case SMT_P208E :
{
struct smt_p_208e *sp ;
sp = (struct smt_p_208e *) to ;
sp->p208e_flag =
mib_m->fddiMACNotCopiedFlag ;
sp->p208e_not_copied =
mib_m->fddiMACNotCopied_Ct ;
sp->p208e_copied =
mib_m->fddiMACCopied_Ct ;
sp->p208e_not_copied_ratio =
mib_m->fddiMACNotCopiedRatio ;
sp_len = sizeof(struct smt_p_208e) ;
goto sp_done ;
}
case SMT_P208F :
{
struct smt_p_208f *sp ;
sp = (struct smt_p_208f *) to ;
sp->p208f_multiple =
mib_m->fddiMACMultiple_N ;
sp->p208f_nacondition =
mib_m->fddiMACDuplicateAddressCond ;
sp->p208f_old_una =
mib_m->fddiMACOldUpstreamNbr ;
sp->p208f_new_una =
mib_m->fddiMACUpstreamNbr ;
sp->p208f_old_dna =
mib_m->fddiMACOldDownstreamNbr ;
sp->p208f_new_dna =
mib_m->fddiMACDownstreamNbr ;
sp->p208f_curren_path =
mib_m->fddiMACCurrentPath ;
sp->p208f_smt_address =
mib_m->fddiMACSMTAddress ;
sp_len = sizeof(struct smt_p_208f) ;
goto sp_done ;
}
case SMT_P2090 :
{
struct smt_p_2090 *sp ;
sp = (struct smt_p_2090 *) to ;
sp->p2090_multiple =
mib_m->fddiMACMultiple_P ;
sp->p2090_availablepaths =
mib_m->fddiMACAvailablePaths ;
sp->p2090_currentpath =
mib_m->fddiMACCurrentPath ;
sp->p2090_requestedpaths =
mib_m->fddiMACRequestedPaths ;
sp_len = sizeof(struct smt_p_2090) ;
goto sp_done ;
}
case SMT_P4050 :
{
struct smt_p_4050 *sp ;
sp = (struct smt_p_4050 *) to ;
sp->p4050_flag =
mib_p->fddiPORTLerFlag ;
sp->p4050_pad = 0 ;
sp->p4050_cutoff =
mib_p->fddiPORTLer_Cutoff ;
sp->p4050_alarm =
mib_p->fddiPORTLer_Alarm ;
sp->p4050_estimate =
mib_p->fddiPORTLer_Estimate ;
sp->p4050_reject_ct =
mib_p->fddiPORTLem_Reject_Ct ;
sp->p4050_ct =
mib_p->fddiPORTLem_Ct ;
sp_len = sizeof(struct smt_p_4050) ;
goto sp_done ;
}
case SMT_P4051 :
{
struct smt_p_4051 *sp ;
sp = (struct smt_p_4051 *) to ;
sp->p4051_multiple =
mib_p->fddiPORTMultiple_U ;
sp->p4051_porttype =
mib_p->fddiPORTMy_Type ;
sp->p4051_connectstate =
mib_p->fddiPORTConnectState ;
sp->p4051_pc_neighbor =
mib_p->fddiPORTNeighborType ;
sp->p4051_pc_withhold =
mib_p->fddiPORTPC_Withhold ;
sp_len = sizeof(struct smt_p_4051) ;
goto sp_done ;
}
case SMT_P4052 :
{
struct smt_p_4052 *sp ;
sp = (struct smt_p_4052 *) to ;
sp->p4052_flag =
mib_p->fddiPORTEB_Condition ;
sp->p4052_eberrorcount =
mib_p->fddiPORTEBError_Ct ;
sp_len = sizeof(struct smt_p_4052) ;
goto sp_done ;
}
case SMT_P4053 :
{
struct smt_p_4053 *sp ;
sp = (struct smt_p_4053 *) to ;
sp->p4053_multiple =
mib_p->fddiPORTMultiple_P ;
sp->p4053_availablepaths =
mib_p->fddiPORTAvailablePaths ;
sp->p4053_currentpath =
mib_p->fddiPORTCurrentPath ;
memcpy( (char *) &sp->p4053_requestedpaths,
(char *) mib_p->fddiPORTRequestedPaths,4) ;
sp->p4053_mytype =
mib_p->fddiPORTMy_Type ;
sp->p4053_neighbortype =
mib_p->fddiPORTNeighborType ;
sp_len = sizeof(struct smt_p_4053) ;
goto sp_done ;
}
default :
break ;
}
if (!pt) {
pcon->pc_err = (para & 0xff00) ? SMT_RDF_NOPARAM :
SMT_RDF_ILLEGAL ;
return ;
}
switch (pt->p_access) {
case AC_G :
case AC_GR :
break ;
default :
pcon->pc_err = SMT_RDF_ILLEGAL ;
return ;
}
from = mib_addr + pt->p_offset ;
if (!swap)
swap = pt->p_swap ;
while ((c = *swap++)) {
switch(c) {
case 'b' :
case 'w' :
case 'l' :
break ;
case 'S' :
case 'E' :
case 'R' :
case 'r' :
if (len < 4)
goto len_error ;
to[0] = 0 ;
to[1] = 0 ;
#ifdef LITTLE_ENDIAN
if (c == 'r') {
to[2] = *from++ ;
to[3] = *from++ ;
}
else {
to[3] = *from++ ;
to[2] = *from++ ;
}
#else
to[2] = *from++ ;
to[3] = *from++ ;
#endif
to += 4 ;
len -= 4 ;
break ;
case 'I' :
if (len < 2)
goto len_error ;
#ifdef LITTLE_ENDIAN
to[1] = *from++ ;
to[0] = *from++ ;
#else
to[0] = *from++ ;
to[1] = *from++ ;
#endif
to += 2 ;
len -= 2 ;
break ;
case 'F' :
case 'B' :
if (len < 4)
goto len_error ;
len -= 4 ;
to[0] = 0 ;
to[1] = 0 ;
to[2] = 0 ;
to[3] = *from++ ;
to += 4 ;
break ;
case 'C' :
case 'T' :
case 'L' :
if (len < 4)
goto len_error ;
#ifdef LITTLE_ENDIAN
to[3] = *from++ ;
to[2] = *from++ ;
to[1] = *from++ ;
to[0] = *from++ ;
#else
to[0] = *from++ ;
to[1] = *from++ ;
to[2] = *from++ ;
to[3] = *from++ ;
#endif
len -= 4 ;
to += 4 ;
break ;
case '2' :
if (len < 4)
goto len_error ;
to[0] = 0 ;
to[1] = 0 ;
to[2] = *from++ ;
to[3] = *from++ ;
len -= 4 ;
to += 4 ;
break ;
case '4' :
if (len < 4)
goto len_error ;
to[0] = *from++ ;
to[1] = *from++ ;
to[2] = *from++ ;
to[3] = *from++ ;
len -= 4 ;
to += 4 ;
break ;
case 'A' :
if (len < 8)
goto len_error ;
to[0] = 0 ;
to[1] = 0 ;
memcpy((char *) to+2,(char *) from,6) ;
to += 8 ;
from += 8 ;
len -= 8 ;
break ;
case '8' :
if (len < 8)
goto len_error ;
memcpy((char *) to,(char *) from,8) ;
to += 8 ;
from += 8 ;
len -= 8 ;
break ;
case 'D' :
if (len < 32)
goto len_error ;
memcpy((char *) to,(char *) from,32) ;
to += 32 ;
from += 32 ;
len -= 32 ;
break ;
case 'P' :
if (len < 8)
goto len_error ;
to[0] = *from++ ;
to[1] = *from++ ;
to[2] = *from++ ;
to[3] = *from++ ;
to[4] = *from++ ;
to[5] = *from++ ;
to[6] = *from++ ;
to[7] = *from++ ;
to += 8 ;
len -= 8 ;
break ;
default :
SMT_PANIC(smc,SMT_E0119, SMT_E0119_MSG) ;
break ;
}
}
done:
if (len & 3) {
to[0] = 0 ;
to[1] = 0 ;
to += 4 - (len & 3 ) ;
len = len & ~ 3 ;
}
pa->p_type = para ;
pa->p_len = plen - len - PARA_LEN ;
pcon->pc_p = (void *) to ;
pcon->pc_len = len ;
return ;
sp_done:
len -= sp_len ;
to += sp_len ;
goto done ;
len_error:
pcon->pc_err = SMT_RDF_TOOLONG ;
return ;
wrong_error:
pcon->pc_err = SMT_RDF_LENGTH ;
}
static int smt_set_para(struct s_smc *smc, struct smt_para *pa, int index,
int local, int set)
{
#define IFSET(x) if (set) (x)
const struct s_p_tab *pt ;
int len ;
char *from ;
char *to ;
const char *swap ;
char c ;
char *mib_addr ;
struct fddi_mib *mib ;
struct fddi_mib_m *mib_m = NULL;
struct fddi_mib_a *mib_a = NULL;
struct fddi_mib_p *mib_p = NULL;
int mac ;
int path ;
int port ;
SK_LOC_DECL(u_char,byte_val) ;
SK_LOC_DECL(u_short,word_val) ;
SK_LOC_DECL(u_long,long_val) ;
mac = index - INDEX_MAC ;
path = index - INDEX_PATH ;
port = index - INDEX_PORT ;
len = pa->p_len ;
from = (char *) (pa + 1 ) ;
mib = &smc->mib ;
switch (pa->p_type & 0xf000) {
case 0x1000 :
default :
mib_addr = (char *) mib ;
break ;
case 0x2000 :
if (mac < 0 || mac >= NUMMACS) {
return SMT_RDF_NOPARAM;
}
mib_m = &smc->mib.m[mac] ;
mib_addr = (char *) mib_m ;
from += 4 ;
len -= 4 ;
break ;
case 0x3000 :
if (path < 0 || path >= NUMPATHS) {
return SMT_RDF_NOPARAM;
}
mib_a = &smc->mib.a[path] ;
mib_addr = (char *) mib_a ;
from += 4 ;
len -= 4 ;
break ;
case 0x4000 :
if (port < 0 || port >= smt_mib_phys(smc)) {
return SMT_RDF_NOPARAM;
}
mib_p = &smc->mib.p[port_to_mib(smc,port)] ;
mib_addr = (char *) mib_p ;
from += 4 ;
len -= 4 ;
break ;
}
switch (pa->p_type) {
case SMT_P10F0 :
case SMT_P10F1 :
#ifdef ESS
case SMT_P10F2 :
case SMT_P10F3 :
case SMT_P10F4 :
case SMT_P10F5 :
case SMT_P10F6 :
case SMT_P10F7 :
#endif
#ifdef SBA
case SMT_P10F8 :
case SMT_P10F9 :
#endif
case SMT_P20F1 :
if (!local)
return SMT_RDF_NOPARAM;
break ;
}
pt = smt_get_ptab(pa->p_type) ;
if (!pt)
return (pa->p_type & 0xff00) ? SMT_RDF_NOPARAM :
SMT_RDF_ILLEGAL;
switch (pt->p_access) {
case AC_GR :
case AC_S :
break ;
default :
return SMT_RDF_ILLEGAL;
}
to = mib_addr + pt->p_offset ;
swap = pt->p_swap ;
while (swap && (c = *swap++)) {
switch(c) {
case 'b' :
to = (char *) &byte_val ;
break ;
case 'w' :
to = (char *) &word_val ;
break ;
case 'l' :
to = (char *) &long_val ;
break ;
case 'S' :
case 'E' :
case 'R' :
case 'r' :
if (len < 4) {
goto len_error ;
}
if (from[0] | from[1])
goto val_error ;
#ifdef LITTLE_ENDIAN
if (c == 'r') {
to[0] = from[2] ;
to[1] = from[3] ;
}
else {
to[1] = from[2] ;
to[0] = from[3] ;
}
#else
to[0] = from[2] ;
to[1] = from[3] ;
#endif
from += 4 ;
to += 2 ;
len -= 4 ;
break ;
case 'F' :
case 'B' :
if (len < 4) {
goto len_error ;
}
if (from[0] | from[1] | from[2])
goto val_error ;
to[0] = from[3] ;
len -= 4 ;
from += 4 ;
to += 4 ;
break ;
case 'C' :
case 'T' :
case 'L' :
if (len < 4) {
goto len_error ;
}
#ifdef LITTLE_ENDIAN
to[3] = *from++ ;
to[2] = *from++ ;
to[1] = *from++ ;
to[0] = *from++ ;
#else
to[0] = *from++ ;
to[1] = *from++ ;
to[2] = *from++ ;
to[3] = *from++ ;
#endif
len -= 4 ;
to += 4 ;
break ;
case 'A' :
if (len < 8)
goto len_error ;
if (set)
memcpy(to,from+2,6) ;
to += 8 ;
from += 8 ;
len -= 8 ;
break ;
case '4' :
if (len < 4)
goto len_error ;
if (set)
memcpy(to,from,4) ;
to += 4 ;
from += 4 ;
len -= 4 ;
break ;
case '8' :
if (len < 8)
goto len_error ;
if (set)
memcpy(to,from,8) ;
to += 8 ;
from += 8 ;
len -= 8 ;
break ;
case 'D' :
if (len < 32)
goto len_error ;
if (set)
memcpy(to,from,32) ;
to += 32 ;
from += 32 ;
len -= 32 ;
break ;
case 'P' :
if (set) {
to[0] = *from++ ;
to[1] = *from++ ;
to[2] = *from++ ;
to[3] = *from++ ;
to[4] = *from++ ;
to[5] = *from++ ;
to[6] = *from++ ;
to[7] = *from++ ;
}
to += 8 ;
len -= 8 ;
break ;
default :
SMT_PANIC(smc,SMT_E0120, SMT_E0120_MSG) ;
return SMT_RDF_ILLEGAL;
}
}
switch (pa->p_type) {
case SMT_P101A:
if (word_val & ~1)
goto val_error ;
IFSET(mib->fddiSMTConfigPolicy = word_val) ;
break ;
case SMT_P101B :
if (!(word_val & POLICY_MM))
goto val_error ;
IFSET(mib->fddiSMTConnectionPolicy = word_val) ;
break ;
case SMT_P101D :
if (word_val < 2 || word_val > 30)
goto val_error ;
IFSET(mib->fddiSMTTT_Notify = word_val) ;
break ;
case SMT_P101E :
if (byte_val & ~1)
goto val_error ;
IFSET(mib->fddiSMTStatRptPolicy = byte_val) ;
break ;
case SMT_P101F :
if (long_val < (long)0x478bf51L)
goto val_error ;
IFSET(mib->fddiSMTTrace_MaxExpiration = long_val) ;
break ;
#ifdef ESS
case SMT_P10F2 :
if (long_val > 1562)
goto val_error ;
if (set && smc->mib.fddiESSPayload != long_val) {
smc->ess.raf_act_timer_poll = TRUE ;
smc->mib.fddiESSPayload = long_val ;
}
break ;
case SMT_P10F3 :
if (long_val < 50 || long_val > 5000)
goto val_error ;
if (set && smc->mib.fddiESSPayload &&
smc->mib.fddiESSOverhead != long_val) {
smc->ess.raf_act_timer_poll = TRUE ;
smc->mib.fddiESSOverhead = long_val ;
}
break ;
case SMT_P10F4 :
if (long_val > -MS2BCLK(5) || long_val < -MS2BCLK(165))
goto val_error ;
IFSET(mib->fddiESSMaxTNeg = long_val) ;
break ;
case SMT_P10F5 :
if (long_val < 1 || long_val > 4478)
goto val_error ;
IFSET(mib->fddiESSMinSegmentSize = long_val) ;
break ;
case SMT_P10F6 :
if ((long_val & 0xffff) != 1)
goto val_error ;
IFSET(mib->fddiESSCategory = long_val) ;
break ;
case SMT_P10F7 :
if (word_val > 1)
goto val_error ;
IFSET(mib->fddiESSSynchTxMode = word_val) ;
break ;
#endif
#ifdef SBA
case SMT_P10F8 :
if (byte_val != SB_STOP && byte_val != SB_START)
goto val_error ;
IFSET(mib->fddiSBACommand = byte_val) ;
break ;
case SMT_P10F9 :
if (byte_val > 100)
goto val_error ;
IFSET(mib->fddiSBAAvailable = byte_val) ;
break ;
#endif
case SMT_P2020 :
if ((word_val & (MIB_P_PATH_PRIM_PREFER |
MIB_P_PATH_PRIM_ALTER)) == 0 )
goto val_error ;
IFSET(mib_m->fddiMACRequestedPaths = word_val) ;
break ;
case SMT_P205F :
IFSET(mib_m->fddiMACFrameErrorThreshold = word_val) ;
break ;
case SMT_P2067 :
IFSET(mib_m->fddiMACNotCopiedThreshold = word_val) ;
break ;
case SMT_P2076:
if (byte_val & ~1)
goto val_error ;
if (set) {
mib_m->fddiMACMA_UnitdataEnable = byte_val ;
queue_event(smc,EVENT_RMT,RM_ENABLE_FLAG) ;
}
break ;
case SMT_P20F1 :
IFSET(mib_m->fddiMACT_Min = long_val) ;
break ;
case SMT_P320F :
if (long_val > 1562)
goto val_error ;
IFSET(mib_a->fddiPATHSbaPayload = long_val) ;
#ifdef ESS
if (set)
ess_para_change(smc) ;
#endif
break ;
case SMT_P3210 :
if (long_val > 5000)
goto val_error ;
if (long_val != 0 && mib_a->fddiPATHSbaPayload == 0)
goto val_error ;
IFSET(mib_a->fddiPATHSbaOverhead = long_val) ;
#ifdef ESS
if (set)
ess_para_change(smc) ;
#endif
break ;
case SMT_P3213:
if (set) {
mib_a->fddiPATHT_Rmode = long_val ;
rtm_set_timer(smc) ;
}
break ;
case SMT_P3214 :
if (long_val > 0x00BEBC20L)
goto val_error ;
#ifdef SBA
if (set && mib->fddiSBACommand == SB_STOP)
goto val_error ;
#endif
IFSET(mib_a->fddiPATHSbaAvailable = long_val) ;
break ;
case SMT_P3215 :
IFSET(mib_a->fddiPATHTVXLowerBound = long_val) ;
goto change_mac_para ;
case SMT_P3216 :
IFSET(mib_a->fddiPATHT_MaxLowerBound = long_val) ;
goto change_mac_para ;
case SMT_P3217 :
IFSET(mib_a->fddiPATHMaxT_Req = long_val) ;
change_mac_para:
if (set && smt_set_mac_opvalues(smc)) {
RS_SET(smc,RS_EVENT) ;
smc->sm.please_reconnect = 1 ;
queue_event(smc,EVENT_ECM,EC_DISCONNECT) ;
}
break ;
case SMT_P400E :
if (byte_val > 1)
goto val_error ;
IFSET(mib_p->fddiPORTConnectionPolicies = byte_val) ;
break ;
case SMT_P4011 :
IFSET(memcpy((char *)mib_p->fddiPORTRequestedPaths,
(char *)&long_val,4)) ;
break ;
case SMT_P401F:
if (word_val > 4)
goto val_error ;
IFSET(mib_p->fddiPORTMaint_LS = word_val) ;
break ;
case SMT_P403A :
if (byte_val < 4 || byte_val > 15)
goto val_error ;
IFSET(mib_p->fddiPORTLer_Cutoff = byte_val) ;
break ;
case SMT_P403B :
if (byte_val < 4 || byte_val > 15)
goto val_error ;
IFSET(mib_p->fddiPORTLer_Alarm = byte_val) ;
break ;
case SMT_P103C :
if (smt_action(smc,SMT_STATION_ACTION, (int) word_val, 0))
goto val_error ;
break ;
case SMT_P4046:
if (smt_action(smc,SMT_PORT_ACTION, (int) word_val,
port_to_mib(smc,port)))
goto val_error ;
break ;
default :
break ;
}
return 0;
val_error:
return SMT_RDF_RANGE;
len_error:
return SMT_RDF_LENGTH;
#if 0
no_author_error:
return SMT_RDF_AUTHOR;
#endif
}
static const struct s_p_tab *smt_get_ptab(u_short para)
{
const struct s_p_tab *pt ;
for (pt = p_tab ; pt->p_num && pt->p_num != para ; pt++)
;
return pt->p_num ? pt : NULL;
}
static int smt_mib_phys(struct s_smc *smc)
{
#ifdef CONCENTRATOR
SK_UNUSED(smc) ;
return NUMPHYS;
#else
if (smc->s.sas == SMT_SAS)
return 1;
return NUMPHYS;
#endif
}
static int port_to_mib(struct s_smc *smc, int p)
{
#ifdef CONCENTRATOR
SK_UNUSED(smc) ;
return p;
#else
if (smc->s.sas == SMT_SAS)
return PS;
return p;
#endif
}
void dump_smt(struct s_smc *smc, struct smt_header *sm, char *text)
{
int len ;
struct smt_para *pa ;
char *c ;
int n ;
int nn ;
#ifdef LITTLE_ENDIAN
int smtlen ;
#endif
SK_UNUSED(smc) ;
#ifdef DEBUG_BRD
if (smc->debug.d_smtf < 2)
#else
if (debug.d_smtf < 2)
#endif
return ;
#ifdef LITTLE_ENDIAN
smtlen = sm->smt_len + sizeof(struct smt_header) ;
#endif
printf("SMT Frame [%s]:\nDA ",text) ;
dump_hex((char *) &sm->smt_dest,6) ;
printf("\tSA ") ;
dump_hex((char *) &sm->smt_source,6) ;
printf(" Class %x Type %x Version %x\n",
sm->smt_class,sm->smt_type,sm->smt_version) ;
printf("TID %lx\t\tSID ",sm->smt_tid) ;
dump_hex((char *) &sm->smt_sid,8) ;
printf(" LEN %x\n",sm->smt_len) ;
len = sm->smt_len ;
pa = (struct smt_para *) (sm + 1) ;
while (len > 0 ) {
int plen ;
#ifdef UNIX
printf("TYPE %x LEN %x VALUE\t",pa->p_type,pa->p_len) ;
#else
printf("TYPE %04x LEN %2x VALUE\t",pa->p_type,pa->p_len) ;
#endif
n = pa->p_len ;
if ( (n < 0 ) || (n > (int)(len - PARA_LEN))) {
n = len - PARA_LEN ;
printf(" BAD LENGTH\n") ;
break ;
}
#ifdef LITTLE_ENDIAN
smt_swap_para(sm,smtlen,0) ;
#endif
if (n < 24) {
dump_hex((char *)(pa+1),(int) n) ;
printf("\n") ;
}
else {
int first = 0 ;
c = (char *)(pa+1) ;
dump_hex(c,16) ;
printf("\n") ;
n -= 16 ;
c += 16 ;
while (n > 0) {
nn = (n > 16) ? 16 : n ;
if (n > 64) {
if (first == 0)
printf("\t\t\t...\n") ;
first = 1 ;
}
else {
printf("\t\t\t") ;
dump_hex(c,nn) ;
printf("\n") ;
}
n -= nn ;
c += 16 ;
}
}
#ifdef LITTLE_ENDIAN
smt_swap_para(sm,smtlen,1) ;
#endif
plen = (pa->p_len + PARA_LEN + 3) & ~3 ;
len -= plen ;
pa = (struct smt_para *)((char *)pa + plen) ;
}
printf("-------------------------------------------------\n\n") ;
}
void dump_hex(char *p, int len)
{
int n = 0 ;
while (len--) {
n++ ;
#ifdef UNIX
printf("%x%s",*p++ & 0xff,len ? ( (n & 7) ? " " : "-") : "") ;
#else
printf("%02x%s",*p++ & 0xff,len ? ( (n & 7) ? " " : "-") : "") ;
#endif
}
}
