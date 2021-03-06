static u_long mac_get_tneg(struct s_smc *smc)
{
u_long tneg ;
tneg = (u_long)((long)inpw(FM_A(FM_TNEG))<<5) ;
return (u_long)((tneg + ((inpw(FM_A(FM_TMRS))>>10)&0x1f)) |
0xffe00000L) ;
}
void mac_update_counter(struct s_smc *smc)
{
smc->mib.m[MAC0].fddiMACFrame_Ct =
(smc->mib.m[MAC0].fddiMACFrame_Ct & 0xffff0000L)
+ (u_short) inpw(FM_A(FM_FCNTR)) ;
smc->mib.m[MAC0].fddiMACLost_Ct =
(smc->mib.m[MAC0].fddiMACLost_Ct & 0xffff0000L)
+ (u_short) inpw(FM_A(FM_LCNTR)) ;
smc->mib.m[MAC0].fddiMACError_Ct =
(smc->mib.m[MAC0].fddiMACError_Ct & 0xffff0000L)
+ (u_short) inpw(FM_A(FM_ECNTR)) ;
smc->mib.m[MAC0].fddiMACT_Neg = mac_get_tneg(smc) ;
#ifdef SMT_REAL_TOKEN_CT
TBD
#else
smt_emulate_token_ct( smc, MAC0 );
#endif
}
static void write_mdr(struct s_smc *smc, u_long val)
{
CHECK_NPP() ;
MDRW(val) ;
}
static void init_ram(struct s_smc *smc)
{
u_short i ;
smc->hw.fp.fifo.rbc_ram_start = 0 ;
smc->hw.fp.fifo.rbc_ram_end =
smc->hw.fp.fifo.rbc_ram_start + RBC_MEM_SIZE ;
CHECK_NPP() ;
MARW(smc->hw.fp.fifo.rbc_ram_start) ;
for (i = smc->hw.fp.fifo.rbc_ram_start;
i < (u_short) (smc->hw.fp.fifo.rbc_ram_end-1); i++)
write_mdr(smc,0L) ;
write_mdr(smc,0L) ;
}
static void set_recvptr(struct s_smc *smc)
{
outpw(FM_A(FM_RPR1),smc->hw.fp.fifo.rx1_fifo_start) ;
outpw(FM_A(FM_SWPR1),smc->hw.fp.fifo.rx1_fifo_start) ;
outpw(FM_A(FM_WPR1),smc->hw.fp.fifo.rx1_fifo_start) ;
outpw(FM_A(FM_EARV1),smc->hw.fp.fifo.tx_s_start-1) ;
if (smc->hw.fp.fifo.rx2_fifo_size) {
outpw(FM_A(FM_RPR2),smc->hw.fp.fifo.rx2_fifo_start) ;
outpw(FM_A(FM_SWPR2),smc->hw.fp.fifo.rx2_fifo_start) ;
outpw(FM_A(FM_WPR2),smc->hw.fp.fifo.rx2_fifo_start) ;
outpw(FM_A(FM_EARV2),smc->hw.fp.fifo.rbc_ram_end-1) ;
}
else {
outpw(FM_A(FM_RPR2),smc->hw.fp.fifo.rbc_ram_end-1) ;
outpw(FM_A(FM_SWPR2),smc->hw.fp.fifo.rbc_ram_end-1) ;
outpw(FM_A(FM_WPR2),smc->hw.fp.fifo.rbc_ram_end-1) ;
outpw(FM_A(FM_EARV2),smc->hw.fp.fifo.rbc_ram_end-1) ;
}
}
static void set_txptr(struct s_smc *smc)
{
outpw(FM_A(FM_CMDREG2),FM_IRSTQ) ;
outpw(FM_A(FM_RPXA0),smc->hw.fp.fifo.tx_a0_start) ;
outpw(FM_A(FM_SWPXA0),smc->hw.fp.fifo.tx_a0_start) ;
outpw(FM_A(FM_WPXA0),smc->hw.fp.fifo.tx_a0_start) ;
outpw(FM_A(FM_EAA0),smc->hw.fp.fifo.rx2_fifo_start-1) ;
if (smc->hw.fp.fifo.tx_s_size) {
outpw(FM_A(FM_RPXS),smc->hw.fp.fifo.tx_s_start) ;
outpw(FM_A(FM_SWPXS),smc->hw.fp.fifo.tx_s_start) ;
outpw(FM_A(FM_WPXS),smc->hw.fp.fifo.tx_s_start) ;
outpw(FM_A(FM_EAS),smc->hw.fp.fifo.tx_a0_start-1) ;
}
else {
outpw(FM_A(FM_RPXS),smc->hw.fp.fifo.tx_a0_start-1) ;
outpw(FM_A(FM_SWPXS),smc->hw.fp.fifo.tx_a0_start-1) ;
outpw(FM_A(FM_WPXS),smc->hw.fp.fifo.tx_a0_start-1) ;
outpw(FM_A(FM_EAS),smc->hw.fp.fifo.tx_a0_start-1) ;
}
}
static void init_rbc(struct s_smc *smc)
{
u_short rbc_ram_addr ;
rbc_ram_addr = smc->hw.fp.fifo.rx2_fifo_start - 1 ;
outpw(FM_A(FM_RPXA1),rbc_ram_addr) ;
outpw(FM_A(FM_WPXA1),rbc_ram_addr) ;
outpw(FM_A(FM_SWPXA1),rbc_ram_addr) ;
outpw(FM_A(FM_EAA1),rbc_ram_addr) ;
set_recvptr(smc) ;
set_txptr(smc) ;
}
static void init_rx(struct s_smc *smc)
{
struct s_smt_rx_queue *queue ;
smc->hw.fp.rx[QUEUE_R1] = queue = &smc->hw.fp.rx_q[QUEUE_R1] ;
queue->rx_bmu_ctl = (HW_PTR) ADDR(B0_R1_CSR) ;
queue->rx_bmu_dsc = (HW_PTR) ADDR(B4_R1_DA) ;
smc->hw.fp.rx[QUEUE_R2] = queue = &smc->hw.fp.rx_q[QUEUE_R2] ;
queue->rx_bmu_ctl = (HW_PTR) ADDR(B0_R2_CSR) ;
queue->rx_bmu_dsc = (HW_PTR) ADDR(B4_R2_DA) ;
}
void set_formac_tsync(struct s_smc *smc, long sync_bw)
{
outpw(FM_A(FM_TSYNC),(unsigned int) (((-sync_bw) >> 5) & 0xffff) ) ;
}
static void init_tx(struct s_smc *smc)
{
struct s_smt_tx_queue *queue ;
smc->hw.fp.tx[QUEUE_S] = queue = &smc->hw.fp.tx_q[QUEUE_S] ;
queue->tx_bmu_ctl = (HW_PTR) ADDR(B0_XS_CSR) ;
queue->tx_bmu_dsc = (HW_PTR) ADDR(B5_XS_DA) ;
#ifdef ESS
set_formac_tsync(smc,smc->ess.sync_bw) ;
#endif
smc->hw.fp.tx[QUEUE_A0] = queue = &smc->hw.fp.tx_q[QUEUE_A0] ;
queue->tx_bmu_ctl = (HW_PTR) ADDR(B0_XA_CSR) ;
queue->tx_bmu_dsc = (HW_PTR) ADDR(B5_XA_DA) ;
llc_recover_tx(smc) ;
}
static void mac_counter_init(struct s_smc *smc)
{
int i ;
u_long *ec ;
outpw(FM_A(FM_FCNTR),0) ;
outpw(FM_A(FM_LCNTR),0) ;
outpw(FM_A(FM_ECNTR),0) ;
ec = (u_long *)&smc->hw.fp.err_stats ;
for (i = (sizeof(struct err_st)/sizeof(long)) ; i ; i--)
*ec++ = 0L ;
smc->mib.m[MAC0].fddiMACRingOp_Ct = 0 ;
}
static void set_formac_addr(struct s_smc *smc)
{
long t_requ = smc->mib.m[MAC0].fddiMACT_Req ;
outpw(FM_A(FM_SAID),my_said) ;
outpw(FM_A(FM_LAIL),(unsigned short)((smc->hw.fddi_home_addr.a[4]<<8) +
smc->hw.fddi_home_addr.a[5])) ;
outpw(FM_A(FM_LAIC),(unsigned short)((smc->hw.fddi_home_addr.a[2]<<8) +
smc->hw.fddi_home_addr.a[3])) ;
outpw(FM_A(FM_LAIM),(unsigned short)((smc->hw.fddi_home_addr.a[0]<<8) +
smc->hw.fddi_home_addr.a[1])) ;
outpw(FM_A(FM_SAGP),my_sagp) ;
outpw(FM_A(FM_LAGL),(unsigned short)((smc->hw.fp.group_addr.a[4]<<8) +
smc->hw.fp.group_addr.a[5])) ;
outpw(FM_A(FM_LAGC),(unsigned short)((smc->hw.fp.group_addr.a[2]<<8) +
smc->hw.fp.group_addr.a[3])) ;
outpw(FM_A(FM_LAGM),(unsigned short)((smc->hw.fp.group_addr.a[0]<<8) +
smc->hw.fp.group_addr.a[1])) ;
outpw(FM_A(FM_TREQ1),(unsigned short)(t_requ>>16)) ;
outpw(FM_A(FM_TREQ0),(unsigned short)t_requ) ;
}
static void set_int(char *p, int l)
{
p[0] = (char)(l >> 24) ;
p[1] = (char)(l >> 16) ;
p[2] = (char)(l >> 8) ;
p[3] = (char)(l >> 0) ;
}
static void copy_tx_mac(struct s_smc *smc, u_long td, struct fddi_mac *mac,
unsigned int off, int len)
{
int i ;
__le32 *p ;
CHECK_NPP() ;
MARW(off) ;
p = (__le32 *) mac ;
for (i = (len + 3)/4 ; i ; i--) {
if (i == 1) {
outpw(FM_A(FM_CMDREG2),FM_ISTTB) ;
}
write_mdr(smc,le32_to_cpu(*p)) ;
p++ ;
}
outpw(FM_A(FM_CMDREG2),FM_ISTTB) ;
write_mdr(smc,td) ;
}
static void directed_beacon(struct s_smc *smc)
{
SK_LOC_DECL(__le32,a[2]) ;
* (char *) a = (char) ((long)DBEACON_INFO<<24L) ;
a[1] = 0 ;
memcpy((char *)a+1, (char *) &smc->mib.m[MAC0].fddiMACUpstreamNbr, ETH_ALEN);
CHECK_NPP() ;
MARW(smc->hw.fp.fifo.rbc_ram_start+DBEACON_FRAME_OFF+4) ;
write_mdr(smc,le32_to_cpu(a[0])) ;
outpw(FM_A(FM_CMDREG2),FM_ISTTB) ;
write_mdr(smc,le32_to_cpu(a[1])) ;
outpw(FM_A(FM_SABC),smc->hw.fp.fifo.rbc_ram_start + DBEACON_FRAME_OFF) ;
}
static void build_claim_beacon(struct s_smc *smc, u_long t_request)
{
u_int td ;
int len ;
struct fddi_mac_sf *mac ;
len = 17 ;
td = TX_DESCRIPTOR | ((((u_int)len-1)&3)<<27) ;
mac = &smc->hw.fp.mac_sfb ;
mac->mac_fc = FC_CLAIM ;
mac->mac_source = mac->mac_dest = MA ;
set_int((char *)mac->mac_info,(int)t_request) ;
copy_tx_mac(smc,td,(struct fddi_mac *)mac,
smc->hw.fp.fifo.rbc_ram_start + CLAIM_FRAME_OFF,len) ;
outpw(FM_A(FM_SACL),smc->hw.fp.fifo.rbc_ram_start + CLAIM_FRAME_OFF) ;
len = 17 ;
td = TX_DESCRIPTOR | ((((u_int)len-1)&3)<<27) ;
mac->mac_fc = FC_BEACON ;
mac->mac_source = MA ;
mac->mac_dest = null_addr ;
set_int((char *) mac->mac_info,((int)BEACON_INFO<<24) + 0 ) ;
copy_tx_mac(smc,td,(struct fddi_mac *)mac,
smc->hw.fp.fifo.rbc_ram_start + BEACON_FRAME_OFF,len) ;
outpw(FM_A(FM_SABC),smc->hw.fp.fifo.rbc_ram_start + BEACON_FRAME_OFF) ;
len = 23 ;
td = TX_DESCRIPTOR | ((((u_int)len-1)&3)<<27) ;
mac->mac_fc = FC_BEACON ;
mac->mac_source = MA ;
mac->mac_dest = dbeacon_multi ;
set_int((char *) mac->mac_info,((int)DBEACON_INFO<<24) + 0 ) ;
set_int((char *) mac->mac_info+4,0) ;
set_int((char *) mac->mac_info+8,0) ;
copy_tx_mac(smc,td,(struct fddi_mac *)mac,
smc->hw.fp.fifo.rbc_ram_start + DBEACON_FRAME_OFF,len) ;
outpw(FM_A(FM_EACB),smc->hw.fp.fifo.rx1_fifo_start-1) ;
outpw(FM_A(FM_WPXSF),0) ;
outpw(FM_A(FM_RPXSF),0) ;
}
static void formac_rcv_restart(struct s_smc *smc)
{
SETMASK(FM_A(FM_MDREG1),smc->hw.fp.rx_mode,FM_ADDRX) ;
outpw(FM_A(FM_CMDREG1),FM_ICLLR) ;
}
void formac_tx_restart(struct s_smc *smc)
{
outpw(FM_A(FM_CMDREG1),FM_ICLLS) ;
outpw(FM_A(FM_CMDREG1),FM_ICLLA0) ;
}
static void enable_formac(struct s_smc *smc)
{
outpw(FM_A(FM_IMSK1U),(unsigned short)~mac_imsk1u);
outpw(FM_A(FM_IMSK1L),(unsigned short)~mac_imsk1l);
outpw(FM_A(FM_IMSK2U),(unsigned short)~mac_imsk2u);
outpw(FM_A(FM_IMSK2L),(unsigned short)~mac_imsk2l);
outpw(FM_A(FM_IMSK3U),(unsigned short)~mac_imsk3u);
outpw(FM_A(FM_IMSK3L),(unsigned short)~mac_imsk3l);
}
static void disable_formac(struct s_smc *smc)
{
outpw(FM_A(FM_IMSK1U),MW) ;
outpw(FM_A(FM_IMSK1L),MW) ;
outpw(FM_A(FM_IMSK2U),MW) ;
outpw(FM_A(FM_IMSK2L),MW) ;
outpw(FM_A(FM_IMSK3U),MW) ;
outpw(FM_A(FM_IMSK3L),MW) ;
}
static void mac_ring_up(struct s_smc *smc, int up)
{
if (up) {
formac_rcv_restart(smc) ;
smc->hw.mac_ring_is_up = TRUE ;
llc_restart_tx(smc) ;
}
else {
SETMASK(FM_A(FM_MDREG1),FM_MDISRCV,FM_ADDET) ;
outpw(FM_A(FM_CMDREG2),FM_IACTR) ;
smc->hw.mac_ring_is_up = FALSE ;
}
}
void mac2_irq(struct s_smc *smc, u_short code_s2u, u_short code_s2l)
{
u_short change_s2l ;
u_short change_s2u ;
if (code_s2u & (FM_SCLM|FM_SHICLM|FM_SBEC|FM_SOTRBEC)) {
queue_event(smc,EVENT_RMT,RM_TX_STATE_CHANGE) ;
}
else if (code_s2l & (FM_STKISS)) {
queue_event(smc,EVENT_RMT,RM_TX_STATE_CHANGE) ;
}
change_s2l = smc->hw.fp.s2l ^ code_s2l ;
change_s2u = smc->hw.fp.s2u ^ code_s2u ;
if ((change_s2l & FM_SRNGOP) ||
(!smc->hw.mac_ring_is_up && ((code_s2l & FM_SRNGOP)))) {
if (code_s2l & FM_SRNGOP) {
mac_ring_up(smc,1) ;
queue_event(smc,EVENT_RMT,RM_RING_OP) ;
smc->mib.m[MAC0].fddiMACRingOp_Ct++ ;
}
else {
mac_ring_up(smc,0) ;
queue_event(smc,EVENT_RMT,RM_RING_NON_OP) ;
}
goto mac2_end ;
}
if (code_s2l & FM_SMISFRM) {
smc->mib.m[MAC0].fddiMACNotCopied_Ct++ ;
}
if (code_s2u & (FM_SRCVOVR |
FM_SRBFL)) {
smc->hw.mac_ct.mac_r_restart_counter++ ;
smt_stat_counter(smc,1) ;
}
if (code_s2u & FM_SOTRBEC)
queue_event(smc,EVENT_RMT,RM_OTHER_BEACON) ;
if (code_s2u & FM_SMYBEC)
queue_event(smc,EVENT_RMT,RM_MY_BEACON) ;
if (change_s2u & code_s2u & FM_SLOCLM) {
DB_RMTN(2, "RMT : lower claim received");
}
if ((code_s2u & FM_SMYCLM) && !(code_s2l & FM_SDUPCLM)) {
queue_event(smc,EVENT_RMT,RM_MY_CLAIM) ;
}
if (code_s2l & FM_SDUPCLM) {
queue_event(smc,EVENT_RMT,RM_VALID_CLAIM) ;
}
if (change_s2u & code_s2u & FM_SHICLM) {
DB_RMTN(2, "RMT : higher claim received");
}
if ( (code_s2l & FM_STRTEXP) ||
(code_s2l & FM_STRTEXR) )
queue_event(smc,EVENT_RMT,RM_TRT_EXP) ;
if (code_s2l & FM_SMULTDA) {
smc->r.dup_addr_test = DA_FAILED ;
queue_event(smc,EVENT_RMT,RM_DUP_ADDR) ;
}
if (code_s2u & FM_SBEC)
smc->hw.fp.err_stats.err_bec_stat++ ;
if (code_s2u & FM_SCLM)
smc->hw.fp.err_stats.err_clm_stat++ ;
if (code_s2l & FM_STVXEXP)
smc->mib.m[MAC0].fddiMACTvxExpired_Ct++ ;
if ((code_s2u & (FM_SBEC|FM_SCLM))) {
if (!(change_s2l & FM_SRNGOP) && (smc->hw.fp.s2l & FM_SRNGOP)) {
mac_ring_up(smc,0) ;
queue_event(smc,EVENT_RMT,RM_RING_NON_OP) ;
mac_ring_up(smc,1) ;
queue_event(smc,EVENT_RMT,RM_RING_OP) ;
smc->mib.m[MAC0].fddiMACRingOp_Ct++ ;
}
}
if (code_s2l & FM_SPHINV)
smc->hw.fp.err_stats.err_phinv++ ;
if (code_s2l & FM_SSIFG)
smc->hw.fp.err_stats.err_sifg_det++ ;
if (code_s2l & FM_STKISS)
smc->hw.fp.err_stats.err_tkiss++ ;
if (code_s2l & FM_STKERR)
smc->hw.fp.err_stats.err_tkerr++ ;
if (code_s2l & FM_SFRMCTR)
smc->mib.m[MAC0].fddiMACFrame_Ct += 0x10000L ;
if (code_s2l & FM_SERRCTR)
smc->mib.m[MAC0].fddiMACError_Ct += 0x10000L ;
if (code_s2l & FM_SLSTCTR)
smc->mib.m[MAC0].fddiMACLost_Ct += 0x10000L ;
if (code_s2u & FM_SERRSF) {
SMT_PANIC(smc,SMT_E0114, SMT_E0114_MSG) ;
}
mac2_end:
smc->hw.fp.s2l = code_s2l ;
smc->hw.fp.s2u = code_s2u ;
outpw(FM_A(FM_IMSK2U),~mac_imsk2u) ;
}
void mac3_irq(struct s_smc *smc, u_short code_s3u, u_short code_s3l)
{
UNUSED(code_s3l) ;
if (code_s3u & (FM_SRCVOVR2 |
FM_SRBFL2)) {
smc->hw.mac_ct.mac_r_restart_counter++ ;
smt_stat_counter(smc,1);
}
if (code_s3u & FM_SRPERRQ2) {
SMT_PANIC(smc,SMT_E0115, SMT_E0115_MSG) ;
}
if (code_s3u & FM_SRPERRQ1) {
SMT_PANIC(smc,SMT_E0116, SMT_E0116_MSG) ;
}
}
static void formac_offline(struct s_smc *smc)
{
outpw(FM_A(FM_CMDREG2),FM_IACTR) ;
SETMASK(FM_A(FM_MDREG1),FM_MDISRCV,FM_ADDET) ;
SETMASK(FM_A(FM_MDREG1),FM_MINIT,FM_MMODE) ;
disable_formac(smc) ;
smc->hw.mac_ring_is_up = FALSE ;
smc->hw.hw_state = STOPPED ;
}
static void formac_online(struct s_smc *smc)
{
enable_formac(smc) ;
SETMASK(FM_A(FM_MDREG1),FM_MONLINE | FM_SELRA | MDR1INIT |
smc->hw.fp.rx_mode, FM_MMODE | FM_SELRA | FM_ADDRX) ;
}
int init_fplus(struct s_smc *smc)
{
smc->hw.fp.nsa_mode = FM_MRNNSAFNMA ;
smc->hw.fp.rx_mode = FM_MDAMA ;
smc->hw.fp.group_addr = fddi_broadcast ;
smc->hw.fp.func_addr = 0 ;
smc->hw.fp.frselreg_init = 0 ;
init_driver_fplus(smc) ;
if (smc->s.sas == SMT_DAS)
smc->hw.fp.mdr3init |= FM_MENDAS ;
smc->hw.mac_ct.mac_nobuf_counter = 0 ;
smc->hw.mac_ct.mac_r_restart_counter = 0 ;
smc->hw.fp.fm_st1u = (HW_PTR) ADDR(B0_ST1U) ;
smc->hw.fp.fm_st1l = (HW_PTR) ADDR(B0_ST1L) ;
smc->hw.fp.fm_st2u = (HW_PTR) ADDR(B0_ST2U) ;
smc->hw.fp.fm_st2l = (HW_PTR) ADDR(B0_ST2L) ;
smc->hw.fp.fm_st3u = (HW_PTR) ADDR(B0_ST3U) ;
smc->hw.fp.fm_st3l = (HW_PTR) ADDR(B0_ST3L) ;
smc->hw.fp.s2l = smc->hw.fp.s2u = 0 ;
smc->hw.mac_ring_is_up = 0 ;
mac_counter_init(smc) ;
smc->hw.mac_pa.t_neg = (u_long)0 ;
smc->hw.mac_pa.t_pri = (u_long)0 ;
mac_do_pci_fix(smc) ;
return init_mac(smc, 1);
}
static int init_mac(struct s_smc *smc, int all)
{
u_short t_max,x ;
u_long time=0 ;
outpw(FM_A(FM_MDREG1),FM_MINIT) ;
set_formac_addr(smc) ;
outpw(FM_A(FM_MDREG1),FM_MMEMACT) ;
outpw(FM_A(FM_MDREG2),smc->hw.fp.mdr2init) ;
if (all) {
init_ram(smc) ;
}
else {
outp(ADDR(B0_CTRL), CTRL_HPI_SET) ;
time = hwt_quick_read(smc) ;
}
smt_split_up_fifo(smc) ;
init_tx(smc) ;
init_rx(smc) ;
init_rbc(smc) ;
build_claim_beacon(smc,smc->mib.m[MAC0].fddiMACT_Req) ;
outpw(FM_A(FM_FRMTHR),14<<12) ;
outpw(FM_A(FM_MDREG1),MDR1INIT | FM_SELRA | smc->hw.fp.rx_mode) ;
outpw(FM_A(FM_MDREG2),smc->hw.fp.mdr2init) ;
outpw(FM_A(FM_MDREG3),smc->hw.fp.mdr3init) ;
outpw(FM_A(FM_FRSELREG),smc->hw.fp.frselreg_init) ;
t_max = (u_short)(smc->mib.m[MAC0].fddiMACT_Max/32) ;
x = t_max/0x27 ;
x *= 0x27 ;
if ((t_max == 0xfffe) || (t_max - x == 0x16))
t_max-- ;
outpw(FM_A(FM_TMAX),(u_short)t_max) ;
if (smc->mib.m[MAC0].fddiMACTvxValue < (u_long) (- US2BCLK(52))) {
outpw(FM_A(FM_TVX), (u_short) (- US2BCLK(52))/255 & MB) ;
} else {
outpw(FM_A(FM_TVX),
(u_short)((smc->mib.m[MAC0].fddiMACTvxValue/255) & MB)) ;
}
outpw(FM_A(FM_CMDREG1),FM_ICLLS) ;
outpw(FM_A(FM_CMDREG1),FM_ICLLA0) ;
outpw(FM_A(FM_CMDREG1),FM_ICLLR);
outpw(FM_A(FM_UNLCKDLY),(0xff|(0xff<<8))) ;
rtm_init(smc) ;
if (!all) {
hwt_wait_time(smc,time,MS2BCLK(10)) ;
outpd(ADDR(B0_R1_CSR),CSR_SET_RESET) ;
outpd(ADDR(B0_XA_CSR),CSR_SET_RESET) ;
outpd(ADDR(B0_XS_CSR),CSR_SET_RESET) ;
outp(ADDR(B0_CTRL), CTRL_HPI_CLR) ;
outpd(ADDR(B0_R1_CSR),CSR_CLR_RESET) ;
outpd(ADDR(B0_XA_CSR),CSR_CLR_RESET) ;
outpd(ADDR(B0_XS_CSR),CSR_CLR_RESET) ;
if (!smc->hw.hw_is_64bit) {
outpd(ADDR(B4_R1_F), RX_WATERMARK) ;
outpd(ADDR(B5_XA_F), TX_WATERMARK) ;
outpd(ADDR(B5_XS_F), TX_WATERMARK) ;
}
smc->hw.hw_state = STOPPED ;
mac_drv_repair_descr(smc) ;
}
smc->hw.hw_state = STARTED ;
return 0;
}
void config_mux(struct s_smc *smc, int mux)
{
plc_config_mux(smc,mux) ;
SETMASK(FM_A(FM_MDREG1),FM_SELRA,FM_SELRA) ;
}
void sm_mac_check_beacon_claim(struct s_smc *smc)
{
outpw(FM_A(FM_IMSK2U),~(mac_imsk2u | mac_beacon_imsk2u)) ;
formac_rcv_restart(smc) ;
process_receive(smc) ;
}
void sm_ma_control(struct s_smc *smc, int mode)
{
switch(mode) {
case MA_OFFLINE :
formac_offline(smc) ;
break ;
case MA_RESET :
(void)init_mac(smc,0) ;
break ;
case MA_BEACON :
formac_online(smc) ;
break ;
case MA_DIRECTED :
directed_beacon(smc) ;
break ;
case MA_TREQ :
break ;
}
}
int sm_mac_get_tx_state(struct s_smc *smc)
{
return (inpw(FM_A(FM_STMCHN))>>4) & 7;
}
static struct s_fpmc* mac_get_mc_table(struct s_smc *smc,
struct fddi_addr *user,
struct fddi_addr *own,
int del, int can)
{
struct s_fpmc *tb ;
struct s_fpmc *slot ;
u_char *p ;
int i ;
*own = *user ;
if (can) {
p = own->a ;
for (i = 0 ; i < 6 ; i++, p++)
*p = bitrev8(*p);
}
slot = NULL;
for (i = 0, tb = smc->hw.fp.mc.table ; i < FPMAX_MULTICAST ; i++, tb++){
if (!tb->n) {
if (!del && !slot)
slot = tb ;
continue ;
}
if (!ether_addr_equal((char *)&tb->a, (char *)own))
continue ;
return tb;
}
return slot;
}
void mac_clear_multicast(struct s_smc *smc)
{
struct s_fpmc *tb ;
int i ;
smc->hw.fp.os_slots_used = 0 ;
for (i = 0, tb = smc->hw.fp.mc.table ; i < FPMAX_MULTICAST ; i++, tb++){
if (!tb->perm) {
tb->n = 0 ;
}
}
}
int mac_add_multicast(struct s_smc *smc, struct fddi_addr *addr, int can)
{
SK_LOC_DECL(struct fddi_addr,own) ;
struct s_fpmc *tb ;
if (can & 0x80) {
if (smc->hw.fp.smt_slots_used >= SMT_MAX_MULTI) {
return 1;
}
}
else {
if (smc->hw.fp.os_slots_used >= FPMAX_MULTICAST-SMT_MAX_MULTI) {
return 1;
}
}
if (!(tb = mac_get_mc_table(smc,addr,&own,0,can & ~0x80)))
return 1;
tb->n++ ;
tb->a = own ;
tb->perm = (can & 0x80) ? 1 : 0 ;
if (can & 0x80)
smc->hw.fp.smt_slots_used++ ;
else
smc->hw.fp.os_slots_used++ ;
return 0;
}
void mac_update_multicast(struct s_smc *smc)
{
struct s_fpmc *tb ;
u_char *fu ;
int i ;
outpw(FM_A(FM_AFCMD),FM_IINV_CAM) ;
if (smc->hw.fp.func_addr) {
fu = (u_char *) &smc->hw.fp.func_addr ;
outpw(FM_A(FM_AFMASK2),0xffff) ;
outpw(FM_A(FM_AFMASK1),(u_short) ~((fu[0] << 8) + fu[1])) ;
outpw(FM_A(FM_AFMASK0),(u_short) ~((fu[2] << 8) + fu[3])) ;
outpw(FM_A(FM_AFPERS),FM_VALID|FM_DA) ;
outpw(FM_A(FM_AFCOMP2), 0xc000) ;
outpw(FM_A(FM_AFCOMP1), 0x0000) ;
outpw(FM_A(FM_AFCOMP0), 0x0000) ;
outpw(FM_A(FM_AFCMD),FM_IWRITE_CAM) ;
}
outpw(FM_A(FM_AFMASK0),0xffff) ;
outpw(FM_A(FM_AFMASK1),0xffff) ;
outpw(FM_A(FM_AFMASK2),0xffff) ;
outpw(FM_A(FM_AFPERS),FM_VALID|FM_DA) ;
for (i = 0, tb = smc->hw.fp.mc.table; i < FPMAX_MULTICAST; i++, tb++) {
if (tb->n) {
CHECK_CAM() ;
outpw(FM_A(FM_AFCOMP2),
(u_short)((tb->a.a[0]<<8)+tb->a.a[1])) ;
outpw(FM_A(FM_AFCOMP1),
(u_short)((tb->a.a[2]<<8)+tb->a.a[3])) ;
outpw(FM_A(FM_AFCOMP0),
(u_short)((tb->a.a[4]<<8)+tb->a.a[5])) ;
outpw(FM_A(FM_AFCMD),FM_IWRITE_CAM) ;
}
}
}
void mac_set_rx_mode(struct s_smc *smc, int mode)
{
switch (mode) {
case RX_ENABLE_ALLMULTI :
smc->hw.fp.rx_prom |= RX_MODE_ALL_MULTI ;
break ;
case RX_DISABLE_ALLMULTI :
smc->hw.fp.rx_prom &= ~RX_MODE_ALL_MULTI ;
break ;
case RX_ENABLE_PROMISC :
smc->hw.fp.rx_prom |= RX_MODE_PROM ;
break ;
case RX_DISABLE_PROMISC :
smc->hw.fp.rx_prom &= ~RX_MODE_PROM ;
break ;
case RX_ENABLE_NSA :
smc->hw.fp.nsa_mode = FM_MDAMA ;
smc->hw.fp.rx_mode = (smc->hw.fp.rx_mode & ~FM_ADDET) |
smc->hw.fp.nsa_mode ;
break ;
case RX_DISABLE_NSA :
smc->hw.fp.nsa_mode = FM_MRNNSAFNMA ;
smc->hw.fp.rx_mode = (smc->hw.fp.rx_mode & ~FM_ADDET) |
smc->hw.fp.nsa_mode ;
break ;
}
if (smc->hw.fp.rx_prom & RX_MODE_PROM) {
smc->hw.fp.rx_mode = FM_MLIMPROM ;
}
else if (smc->hw.fp.rx_prom & RX_MODE_ALL_MULTI) {
smc->hw.fp.rx_mode = smc->hw.fp.nsa_mode | FM_EXGPA0 ;
}
else
smc->hw.fp.rx_mode = smc->hw.fp.nsa_mode ;
SETMASK(FM_A(FM_MDREG1),smc->hw.fp.rx_mode,FM_ADDRX) ;
mac_update_multicast(smc) ;
}
void rtm_irq(struct s_smc *smc)
{
outpw(ADDR(B2_RTM_CRTL),TIM_CL_IRQ) ;
if (inpw(ADDR(B2_RTM_CRTL)) & TIM_RES_TOK) {
outpw(FM_A(FM_CMDREG1),FM_ICL) ;
DB_RMT("RMT: fddiPATHT_Rmode expired");
AIX_EVENT(smc, (u_long) FDDI_RING_STATUS,
(u_long) FDDI_SMT_EVENT,
(u_long) FDDI_RTT, smt_get_event_word(smc));
}
outpw(ADDR(B2_RTM_CRTL),TIM_START) ;
}
static void rtm_init(struct s_smc *smc)
{
outpd(ADDR(B2_RTM_INI),0) ;
outpw(ADDR(B2_RTM_CRTL),TIM_START) ;
}
void rtm_set_timer(struct s_smc *smc)
{
DB_RMT("RMT: setting new fddiPATHT_Rmode, t = %d ns",
(int)smc->mib.a[PATH0].fddiPATHT_Rmode);
outpd(ADDR(B2_RTM_INI),smc->mib.a[PATH0].fddiPATHT_Rmode) ;
}
static void smt_split_up_fifo(struct s_smc *smc)
{
if (SMT_R1_RXD_COUNT == 0) {
SMT_PANIC(smc,SMT_E0117, SMT_E0117_MSG) ;
}
switch(SMT_R2_RXD_COUNT) {
case 0:
smc->hw.fp.fifo.rx1_fifo_size = RX_FIFO_SPACE ;
smc->hw.fp.fifo.rx2_fifo_size = 0 ;
break ;
case 1:
case 2:
case 3:
smc->hw.fp.fifo.rx1_fifo_size = RX_LARGE_FIFO ;
smc->hw.fp.fifo.rx2_fifo_size = RX_SMALL_FIFO ;
break ;
default:
smc->hw.fp.fifo.rx1_fifo_size = RX_FIFO_SPACE *
SMT_R1_RXD_COUNT/(SMT_R1_RXD_COUNT+SMT_R2_RXD_COUNT) ;
smc->hw.fp.fifo.rx2_fifo_size = RX_FIFO_SPACE *
SMT_R2_RXD_COUNT/(SMT_R1_RXD_COUNT+SMT_R2_RXD_COUNT) ;
break ;
}
if (smc->mib.a[PATH0].fddiPATHSbaPayload) {
#ifdef ESS
smc->hw.fp.fifo.fifo_config_mode |=
smc->mib.fddiESSSynchTxMode | SYNC_TRAFFIC_ON ;
#endif
}
else {
smc->hw.fp.fifo.fifo_config_mode &=
~(SEND_ASYNC_AS_SYNC|SYNC_TRAFFIC_ON) ;
}
if (smc->hw.fp.fifo.fifo_config_mode & SYNC_TRAFFIC_ON) {
if (smc->hw.fp.fifo.fifo_config_mode & SEND_ASYNC_AS_SYNC) {
smc->hw.fp.fifo.tx_s_size = TX_LARGE_FIFO ;
smc->hw.fp.fifo.tx_a0_size = TX_SMALL_FIFO ;
}
else {
smc->hw.fp.fifo.tx_s_size = TX_MEDIUM_FIFO ;
smc->hw.fp.fifo.tx_a0_size = TX_MEDIUM_FIFO ;
}
}
else {
smc->hw.fp.fifo.tx_s_size = 0 ;
smc->hw.fp.fifo.tx_a0_size = TX_FIFO_SPACE ;
}
smc->hw.fp.fifo.rx1_fifo_start = smc->hw.fp.fifo.rbc_ram_start +
RX_FIFO_OFF ;
smc->hw.fp.fifo.tx_s_start = smc->hw.fp.fifo.rx1_fifo_start +
smc->hw.fp.fifo.rx1_fifo_size ;
smc->hw.fp.fifo.tx_a0_start = smc->hw.fp.fifo.tx_s_start +
smc->hw.fp.fifo.tx_s_size ;
smc->hw.fp.fifo.rx2_fifo_start = smc->hw.fp.fifo.tx_a0_start +
smc->hw.fp.fifo.tx_a0_size ;
DB_SMT("FIFO split: mode = %x", smc->hw.fp.fifo.fifo_config_mode);
DB_SMT("rbc_ram_start = %x rbc_ram_end = %x",
smc->hw.fp.fifo.rbc_ram_start, smc->hw.fp.fifo.rbc_ram_end);
DB_SMT("rx1_fifo_start = %x tx_s_start = %x",
smc->hw.fp.fifo.rx1_fifo_start, smc->hw.fp.fifo.tx_s_start);
DB_SMT("tx_a0_start = %x rx2_fifo_start = %x",
smc->hw.fp.fifo.tx_a0_start, smc->hw.fp.fifo.rx2_fifo_start);
}
void formac_reinit_tx(struct s_smc *smc)
{
if (!smc->hw.fp.fifo.tx_s_size && smc->mib.a[PATH0].fddiPATHSbaPayload){
(void)init_mac(smc,0) ;
}
}
