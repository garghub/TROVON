u_int mac_drv_check_space(void)
{
#ifdef MB_OUTSIDE_SMC
#ifdef COMMON_MB_POOL
call_count++ ;
if (call_count == 1) {
return EXT_VIRT_MEM;
}
else {
return EXT_VIRT_MEM_2;
}
#else
return EXT_VIRT_MEM;
#endif
#else
return 0;
#endif
}
int mac_drv_init(struct s_smc *smc)
{
if (sizeof(struct s_smt_fp_rxd) % 16) {
SMT_PANIC(smc,HWM_E0001,HWM_E0001_MSG) ;
}
if (sizeof(struct s_smt_fp_txd) % 16) {
SMT_PANIC(smc,HWM_E0002,HWM_E0002_MSG) ;
}
if (!(smc->os.hwm.descr_p = (union s_fp_descr volatile *)
mac_drv_get_desc_mem(smc,(u_int)
(RXD_TXD_COUNT+1)*sizeof(struct s_smt_fp_txd)))) {
return 1;
}
#ifndef MB_OUTSIDE_SMC
smc->os.hwm.mbuf_pool.mb_start=(SMbuf *)(&smc->os.hwm.mbuf_pool.mb[0]) ;
#else
#ifndef COMMON_MB_POOL
if (!(smc->os.hwm.mbuf_pool.mb_start = (SMbuf *) mac_drv_get_space(smc,
MAX_MBUF*sizeof(SMbuf)))) {
return 1;
}
#else
if (!mb_start) {
if (!(mb_start = (SMbuf *) mac_drv_get_space(smc,
MAX_MBUF*sizeof(SMbuf)))) {
return 1;
}
}
#endif
#endif
return 0;
}
void init_driver_fplus(struct s_smc *smc)
{
smc->hw.fp.mdr2init = FM_LSB | FM_BMMODE | FM_ENNPRQ | FM_ENHSRQ | 3 ;
#ifdef PCI
smc->hw.fp.mdr2init |= FM_CHKPAR | FM_PARITY ;
#endif
smc->hw.fp.mdr3init = FM_MENRQAUNLCK | FM_MENRS ;
#ifdef USE_CAN_ADDR
smc->hw.fp.frselreg_init = FM_ENXMTADSWAP | FM_ENRCVADSWAP ;
#endif
}
static u_long init_descr_ring(struct s_smc *smc,
union s_fp_descr volatile *start,
int count)
{
int i ;
union s_fp_descr volatile *d1 ;
union s_fp_descr volatile *d2 ;
u_long phys ;
DB_GEN(3, "descr ring starts at = %p", start);
for (i=count-1, d1=start; i ; i--) {
d2 = d1 ;
d1++ ;
d2->r.rxd_rbctrl = cpu_to_le32(BMU_CHECK) ;
d2->r.rxd_next = &d1->r ;
phys = mac_drv_virt2phys(smc,(void *)d1) ;
d2->r.rxd_nrdadr = cpu_to_le32(phys) ;
}
DB_GEN(3, "descr ring ends at = %p", d1);
d1->r.rxd_rbctrl = cpu_to_le32(BMU_CHECK) ;
d1->r.rxd_next = &start->r ;
phys = mac_drv_virt2phys(smc,(void *)start) ;
d1->r.rxd_nrdadr = cpu_to_le32(phys) ;
for (i=count, d1=start; i ; i--) {
DRV_BUF_FLUSH(&d1->r,DDI_DMA_SYNC_FORDEV) ;
d1++;
}
return phys;
}
static void init_txd_ring(struct s_smc *smc)
{
struct s_smt_fp_txd volatile *ds ;
struct s_smt_tx_queue *queue ;
u_long phys ;
ds = (struct s_smt_fp_txd volatile *) ((char *)smc->os.hwm.descr_p +
SMT_R1_RXD_COUNT*sizeof(struct s_smt_fp_rxd)) ;
queue = smc->hw.fp.tx[QUEUE_A0] ;
DB_GEN(3, "Init async TxD ring, %d TxDs", HWM_ASYNC_TXD_COUNT);
(void)init_descr_ring(smc,(union s_fp_descr volatile *)ds,
HWM_ASYNC_TXD_COUNT) ;
phys = le32_to_cpu(ds->txd_ntdadr) ;
ds++ ;
queue->tx_curr_put = queue->tx_curr_get = ds ;
ds-- ;
queue->tx_free = HWM_ASYNC_TXD_COUNT ;
queue->tx_used = 0 ;
outpd(ADDR(B5_XA_DA),phys) ;
ds = (struct s_smt_fp_txd volatile *) ((char *)ds +
HWM_ASYNC_TXD_COUNT*sizeof(struct s_smt_fp_txd)) ;
queue = smc->hw.fp.tx[QUEUE_S] ;
DB_GEN(3, "Init sync TxD ring, %d TxDs", HWM_SYNC_TXD_COUNT);
(void)init_descr_ring(smc,(union s_fp_descr volatile *)ds,
HWM_SYNC_TXD_COUNT) ;
phys = le32_to_cpu(ds->txd_ntdadr) ;
ds++ ;
queue->tx_curr_put = queue->tx_curr_get = ds ;
queue->tx_free = HWM_SYNC_TXD_COUNT ;
queue->tx_used = 0 ;
outpd(ADDR(B5_XS_DA),phys) ;
}
static void init_rxd_ring(struct s_smc *smc)
{
struct s_smt_fp_rxd volatile *ds ;
struct s_smt_rx_queue *queue ;
u_long phys ;
ds = (struct s_smt_fp_rxd volatile *) smc->os.hwm.descr_p ;
queue = smc->hw.fp.rx[QUEUE_R1] ;
DB_GEN(3, "Init RxD ring, %d RxDs", SMT_R1_RXD_COUNT);
(void)init_descr_ring(smc,(union s_fp_descr volatile *)ds,
SMT_R1_RXD_COUNT) ;
phys = le32_to_cpu(ds->rxd_nrdadr) ;
ds++ ;
queue->rx_curr_put = queue->rx_curr_get = ds ;
queue->rx_free = SMT_R1_RXD_COUNT ;
queue->rx_used = 0 ;
outpd(ADDR(B4_R1_DA),phys) ;
}
void init_fddi_driver(struct s_smc *smc, u_char *mac_addr)
{
SMbuf *mb ;
int i ;
init_board(smc,mac_addr) ;
(void)init_fplus(smc) ;
#ifndef COMMON_MB_POOL
mb = smc->os.hwm.mbuf_pool.mb_start ;
smc->os.hwm.mbuf_pool.mb_free = (SMbuf *)NULL ;
for (i = 0; i < MAX_MBUF; i++) {
mb->sm_use_count = 1 ;
smt_free_mbuf(smc,mb) ;
mb++ ;
}
#else
mb = mb_start ;
if (!mb_init) {
mb_free = 0 ;
for (i = 0; i < MAX_MBUF; i++) {
mb->sm_use_count = 1 ;
smt_free_mbuf(smc,mb) ;
mb++ ;
}
mb_init = TRUE ;
}
#endif
smc->os.hwm.llc_rx_pipe = smc->os.hwm.llc_rx_tail = (SMbuf *)NULL ;
smc->os.hwm.txd_tx_pipe = smc->os.hwm.txd_tx_tail = NULL ;
smc->os.hwm.pass_SMT = smc->os.hwm.pass_NSA = smc->os.hwm.pass_DB = 0 ;
smc->os.hwm.pass_llc_promisc = TRUE ;
smc->os.hwm.queued_rx_frames = smc->os.hwm.queued_txd_mb = 0 ;
smc->os.hwm.detec_count = 0 ;
smc->os.hwm.rx_break = 0 ;
smc->os.hwm.rx_len_error = 0 ;
smc->os.hwm.isr_flag = FALSE ;
i = 16 - ((long)smc->os.hwm.descr_p & 0xf) ;
if (i != 16) {
DB_GEN(3, "i = %d", i);
smc->os.hwm.descr_p = (union s_fp_descr volatile *)
((char *)smc->os.hwm.descr_p+i) ;
}
DB_GEN(3, "pt to descr area = %p", smc->os.hwm.descr_p);
init_txd_ring(smc) ;
init_rxd_ring(smc) ;
mac_drv_fill_rxd(smc) ;
init_plc(smc) ;
}
SMbuf *smt_get_mbuf(struct s_smc *smc)
{
register SMbuf *mb ;
#ifndef COMMON_MB_POOL
mb = smc->os.hwm.mbuf_pool.mb_free ;
#else
mb = mb_free ;
#endif
if (mb) {
#ifndef COMMON_MB_POOL
smc->os.hwm.mbuf_pool.mb_free = mb->sm_next ;
#else
mb_free = mb->sm_next ;
#endif
mb->sm_off = 8 ;
mb->sm_use_count = 1 ;
}
DB_GEN(3, "get SMbuf: mb = %p", mb);
return mb;
}
void smt_free_mbuf(struct s_smc *smc, SMbuf *mb)
{
if (mb) {
mb->sm_use_count-- ;
DB_GEN(3, "free_mbuf: sm_use_count = %d", mb->sm_use_count);
if (!mb->sm_use_count) {
DB_GEN(3, "free SMbuf: mb = %p", mb);
#ifndef COMMON_MB_POOL
mb->sm_next = smc->os.hwm.mbuf_pool.mb_free ;
smc->os.hwm.mbuf_pool.mb_free = mb ;
#else
mb->sm_next = mb_free ;
mb_free = mb ;
#endif
}
}
else
SMT_PANIC(smc,HWM_E0003,HWM_E0003_MSG) ;
}
void mac_drv_repair_descr(struct s_smc *smc)
{
u_long phys ;
if (smc->hw.hw_state != STOPPED) {
SK_BREAK() ;
SMT_PANIC(smc,HWM_E0013,HWM_E0013_MSG) ;
return ;
}
phys = repair_txd_ring(smc,smc->hw.fp.tx[QUEUE_A0]) ;
outpd(ADDR(B5_XA_DA),phys) ;
if (smc->hw.fp.tx_q[QUEUE_A0].tx_used) {
outpd(ADDR(B0_XA_CSR),CSR_START) ;
}
phys = repair_txd_ring(smc,smc->hw.fp.tx[QUEUE_S]) ;
outpd(ADDR(B5_XS_DA),phys) ;
if (smc->hw.fp.tx_q[QUEUE_S].tx_used) {
outpd(ADDR(B0_XS_CSR),CSR_START) ;
}
phys = repair_rxd_ring(smc,smc->hw.fp.rx[QUEUE_R1]) ;
outpd(ADDR(B4_R1_DA),phys) ;
outpd(ADDR(B0_R1_CSR),CSR_START) ;
}
static u_long repair_txd_ring(struct s_smc *smc, struct s_smt_tx_queue *queue)
{
int i ;
int tx_used ;
u_long phys ;
u_long tbctrl ;
struct s_smt_fp_txd volatile *t ;
SK_UNUSED(smc) ;
t = queue->tx_curr_get ;
tx_used = queue->tx_used ;
for (i = tx_used+queue->tx_free-1 ; i ; i-- ) {
t = t->txd_next ;
}
phys = le32_to_cpu(t->txd_ntdadr) ;
t = queue->tx_curr_get ;
while (tx_used) {
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORCPU) ;
tbctrl = le32_to_cpu(t->txd_tbctrl) ;
if (tbctrl & BMU_OWN) {
if (tbctrl & BMU_STF) {
break ;
}
else {
t->txd_tbctrl &= ~cpu_to_le32(BMU_OWN) ;
}
}
phys = le32_to_cpu(t->txd_ntdadr) ;
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
t = t->txd_next ;
tx_used-- ;
}
return phys;
}
static u_long repair_rxd_ring(struct s_smc *smc, struct s_smt_rx_queue *queue)
{
int i ;
int rx_used ;
u_long phys ;
u_long rbctrl ;
struct s_smt_fp_rxd volatile *r ;
SK_UNUSED(smc) ;
r = queue->rx_curr_get ;
rx_used = queue->rx_used ;
for (i = SMT_R1_RXD_COUNT-1 ; i ; i-- ) {
r = r->rxd_next ;
}
phys = le32_to_cpu(r->rxd_nrdadr) ;
r = queue->rx_curr_get ;
while (rx_used) {
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
rbctrl = le32_to_cpu(r->rxd_rbctrl) ;
if (rbctrl & BMU_OWN) {
if (rbctrl & BMU_STF) {
break ;
}
else {
r->rxd_rbctrl &= ~cpu_to_le32(BMU_OWN) ;
}
}
phys = le32_to_cpu(r->rxd_nrdadr) ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORDEV) ;
r = r->rxd_next ;
rx_used-- ;
}
return phys;
}
void fddi_isr(struct s_smc *smc)
{
u_long is ;
u_short stu, stl ;
SMbuf *mb ;
#ifdef USE_BREAK_ISR
int force_irq ;
#endif
#ifdef ODI2
if (smc->os.hwm.rx_break) {
mac_drv_fill_rxd(smc) ;
if (smc->hw.fp.rx_q[QUEUE_R1].rx_used > 0) {
smc->os.hwm.rx_break = 0 ;
process_receive(smc) ;
}
else {
smc->os.hwm.detec_count = 0 ;
smt_force_irq(smc) ;
}
}
#endif
smc->os.hwm.isr_flag = TRUE ;
#ifdef USE_BREAK_ISR
force_irq = TRUE ;
if (smc->os.hwm.leave_isr) {
smc->os.hwm.leave_isr = FALSE ;
process_receive(smc) ;
}
#endif
while ((is = GET_ISR() & ISR_MASK)) {
NDD_TRACE("CH0B",is,0,0) ;
DB_GEN(7, "ISA = 0x%lx", is);
if (is & IMASK_SLOW) {
NDD_TRACE("CH1b",is,0,0) ;
if (is & IS_PLINT1) {
plc1_irq(smc) ;
}
if (is & IS_PLINT2) {
plc2_irq(smc) ;
}
if (is & IS_MINTR1) {
stu = inpw(FM_A(FM_ST1U)) ;
stl = inpw(FM_A(FM_ST1L)) ;
DB_GEN(6, "Slow transmit complete");
mac1_irq(smc,stu,stl) ;
}
if (is & IS_MINTR2) {
stu= inpw(FM_A(FM_ST2U)) ;
stl= inpw(FM_A(FM_ST2L)) ;
DB_GEN(6, "Slow receive complete");
DB_GEN(7, "stl = %x : stu = %x", stl, stu);
mac2_irq(smc,stu,stl) ;
}
if (is & IS_MINTR3) {
stu= inpw(FM_A(FM_ST3U)) ;
stl= inpw(FM_A(FM_ST3L)) ;
DB_GEN(6, "FORMAC Mode Register 3");
mac3_irq(smc,stu,stl) ;
}
if (is & IS_TIMINT) {
timer_irq(smc) ;
#ifdef NDIS_OS2
force_irq_pending = 0 ;
#endif
if (++smc->os.hwm.detec_count > 4) {
process_receive(smc) ;
}
}
if (is & IS_TOKEN) {
rtm_irq(smc) ;
}
if (is & IS_R1_P) {
outpd(ADDR(B4_R1_CSR),CSR_IRQ_CL_P) ;
SMT_PANIC(smc,HWM_E0004,HWM_E0004_MSG) ;
}
if (is & IS_R1_C) {
outpd(ADDR(B4_R1_CSR),CSR_IRQ_CL_C) ;
SMT_PANIC(smc,HWM_E0005,HWM_E0005_MSG) ;
}
if (is & IS_XA_C) {
outpd(ADDR(B5_XA_CSR),CSR_IRQ_CL_C) ;
SMT_PANIC(smc,HWM_E0006,HWM_E0006_MSG) ;
}
if (is & IS_XS_C) {
outpd(ADDR(B5_XS_CSR),CSR_IRQ_CL_C) ;
SMT_PANIC(smc,HWM_E0007,HWM_E0007_MSG) ;
}
}
if (is & (IS_XS_F|IS_XA_F)) {
DB_GEN(6, "Fast tx complete queue");
outpd(ADDR(B5_XS_CSR),CSR_IRQ_CL_F) ;
outpd(ADDR(B5_XA_CSR),CSR_IRQ_CL_F) ;
mac_drv_clear_txd(smc) ;
llc_restart_tx(smc) ;
}
if (is & IS_R1_F) {
DB_GEN(6, "Fast receive complete");
#ifndef USE_BREAK_ISR
outpd(ADDR(B4_R1_CSR),CSR_IRQ_CL_F) ;
process_receive(smc) ;
#else
process_receive(smc) ;
if (smc->os.hwm.leave_isr) {
force_irq = FALSE ;
} else {
outpd(ADDR(B4_R1_CSR),CSR_IRQ_CL_F) ;
process_receive(smc) ;
}
#endif
}
#ifndef NDIS_OS2
while ((mb = get_llc_rx(smc))) {
smt_to_llc(smc,mb) ;
}
#else
if (offDepth)
post_proc() ;
while (!offDepth && (mb = get_llc_rx(smc))) {
smt_to_llc(smc,mb) ;
}
if (!offDepth && smc->os.hwm.rx_break) {
process_receive(smc) ;
}
#endif
if (smc->q.ev_get != smc->q.ev_put) {
NDD_TRACE("CH2a",0,0,0) ;
ev_dispatcher(smc) ;
}
#ifdef NDIS_OS2
post_proc() ;
if (offDepth) {
break ;
}
#endif
#ifdef USE_BREAK_ISR
if (smc->os.hwm.leave_isr) {
break ;
}
#endif
}
#ifdef USE_BREAK_ISR
if (smc->os.hwm.leave_isr && force_irq) {
smt_force_irq(smc) ;
}
#endif
smc->os.hwm.isr_flag = FALSE ;
NDD_TRACE("CH0E",0,0,0) ;
}
void mac_drv_rx_mode(struct s_smc *smc, int mode)
{
switch(mode) {
case RX_ENABLE_PASS_SMT:
smc->os.hwm.pass_SMT = TRUE ;
break ;
case RX_DISABLE_PASS_SMT:
smc->os.hwm.pass_SMT = FALSE ;
break ;
case RX_ENABLE_PASS_NSA:
smc->os.hwm.pass_NSA = TRUE ;
break ;
case RX_DISABLE_PASS_NSA:
smc->os.hwm.pass_NSA = FALSE ;
break ;
case RX_ENABLE_PASS_DB:
smc->os.hwm.pass_DB = TRUE ;
break ;
case RX_DISABLE_PASS_DB:
smc->os.hwm.pass_DB = FALSE ;
break ;
case RX_DISABLE_PASS_ALL:
smc->os.hwm.pass_SMT = smc->os.hwm.pass_NSA = FALSE ;
smc->os.hwm.pass_DB = FALSE ;
smc->os.hwm.pass_llc_promisc = TRUE ;
mac_set_rx_mode(smc,RX_DISABLE_NSA) ;
break ;
case RX_DISABLE_LLC_PROMISC:
smc->os.hwm.pass_llc_promisc = FALSE ;
break ;
case RX_ENABLE_LLC_PROMISC:
smc->os.hwm.pass_llc_promisc = TRUE ;
break ;
case RX_ENABLE_ALLMULTI:
case RX_DISABLE_ALLMULTI:
case RX_ENABLE_PROMISC:
case RX_DISABLE_PROMISC:
case RX_ENABLE_NSA:
case RX_DISABLE_NSA:
default:
mac_set_rx_mode(smc,mode) ;
break ;
}
}
void process_receive(struct s_smc *smc)
{
int i ;
int n ;
int frag_count ;
int used_frags ;
struct s_smt_rx_queue *queue ;
struct s_smt_fp_rxd volatile *r ;
struct s_smt_fp_rxd volatile *rxd ;
u_long rbctrl ;
u_long rfsw ;
u_short rx_used ;
u_char far *virt ;
char far *data ;
SMbuf *mb ;
u_char fc ;
int len ;
smc->os.hwm.detec_count = 0 ;
queue = smc->hw.fp.rx[QUEUE_R1] ;
NDD_TRACE("RHxB",0,0,0) ;
for ( ; ; ) {
r = queue->rx_curr_get ;
rx_used = queue->rx_used ;
frag_count = 0 ;
#ifdef USE_BREAK_ISR
if (smc->os.hwm.leave_isr) {
goto rx_end ;
}
#endif
#ifdef NDIS_OS2
if (offDepth) {
smc->os.hwm.rx_break = 1 ;
goto rx_end ;
}
smc->os.hwm.rx_break = 0 ;
#endif
#ifdef ODI2
if (smc->os.hwm.rx_break) {
goto rx_end ;
}
#endif
n = 0 ;
do {
DB_RX(5, "Check RxD %p for OWN and EOF", r);
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
rbctrl = le32_to_cpu(CR_READ(r->rxd_rbctrl));
if (rbctrl & BMU_OWN) {
NDD_TRACE("RHxE",r,rfsw,rbctrl) ;
DB_RX(4, "End of RxDs");
goto rx_end ;
}
if (!rx_used) {
SK_BREAK() ;
SMT_PANIC(smc,HWM_E0009,HWM_E0009_MSG) ;
smc->hw.hw_state = STOPPED ;
mac_drv_clear_rx_queue(smc) ;
smc->hw.hw_state = STARTED ;
mac_drv_fill_rxd(smc) ;
smc->os.hwm.detec_count = 0 ;
goto rx_end ;
}
rfsw = le32_to_cpu(r->rxd_rfsw) ;
if ((rbctrl & BMU_STF) != ((rbctrl & BMU_ST_BUF) <<5)) {
SK_BREAK() ;
rfsw = 0 ;
if (frag_count) {
break ;
}
}
n += rbctrl & 0xffff ;
r = r->rxd_next ;
frag_count++ ;
rx_used-- ;
} while (!(rbctrl & BMU_EOF)) ;
used_frags = frag_count ;
DB_RX(5, "EOF set in RxD, used_frags = %d", used_frags);
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
while (rx_used && !(r->rxd_rbctrl & cpu_to_le32(BMU_ST_BUF))) {
DB_RX(5, "Check STF bit in %p", r);
r = r->rxd_next ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
frag_count++ ;
rx_used-- ;
}
DB_RX(5, "STF bit found");
rxd = queue->rx_curr_get ;
queue->rx_curr_get = r ;
queue->rx_free += frag_count ;
queue->rx_used = rx_used ;
rxd->rxd_rbctrl &= cpu_to_le32(~BMU_STF) ;
for (r=rxd, i=frag_count ; i ; r=r->rxd_next, i--){
DB_RX(5, "dma_complete for RxD %p", r);
dma_complete(smc,(union s_fp_descr volatile *)r,DMA_WR);
}
smc->hw.fp.err_stats.err_valid++ ;
smc->mib.m[MAC0].fddiMACCopied_Ct++ ;
len = (rfsw & RD_LENGTH) - 4 ;
DB_RX(4, "frame length = %d", len);
if (rfsw & (RX_MSRABT|RX_FS_E|RX_FS_CRC|RX_FS_IMPL)){
if (rfsw & RD_S_MSRABT) {
DB_RX(2, "Frame aborted by the FORMAC");
smc->hw.fp.err_stats.err_abort++ ;
}
if (rfsw & RD_S_SEAC2) {
DB_RX(2, "E-Indicator set");
smc->hw.fp.err_stats.err_e_indicator++ ;
}
if (rfsw & RD_S_SFRMERR) {
DB_RX(2, "CRC error");
smc->hw.fp.err_stats.err_crc++ ;
}
if (rfsw & RX_FS_IMPL) {
DB_RX(2, "Implementer frame");
smc->hw.fp.err_stats.err_imp_frame++ ;
}
goto abort_frame ;
}
if (len > FDDI_RAW_MTU-4) {
DB_RX(2, "Frame too long error");
smc->hw.fp.err_stats.err_too_long++ ;
goto abort_frame ;
}
if (len <= 4) {
DB_RX(2, "Frame length = 0");
goto abort_frame ;
}
if (len != (n-4)) {
DB_RX(4, "BMU: rx len differs: [%d:%d]", len, n);
smc->os.hwm.rx_len_error++ ;
goto abort_frame ;
}
virt = (u_char far *) rxd->rxd_virt ;
DB_RX(2, "FC = %x", *virt);
if (virt[12] == MA[5] &&
virt[11] == MA[4] &&
virt[10] == MA[3] &&
virt[9] == MA[2] &&
virt[8] == MA[1] &&
(virt[7] & ~GROUP_ADDR_BIT) == MA[0]) {
goto abort_frame ;
}
if (rfsw & RX_FS_LLC) {
if (!smc->os.hwm.pass_llc_promisc) {
if(!(virt[1] & GROUP_ADDR_BIT)) {
if (virt[6] != MA[5] ||
virt[5] != MA[4] ||
virt[4] != MA[3] ||
virt[3] != MA[2] ||
virt[2] != MA[1] ||
virt[1] != MA[0]) {
DB_RX(2, "DA != MA and not multi- or broadcast");
goto abort_frame ;
}
}
}
DB_RX(4, "LLC - receive");
mac_drv_rx_complete(smc,rxd,frag_count,len) ;
}
else {
if (!(mb = smt_get_mbuf(smc))) {
smc->hw.fp.err_stats.err_no_buf++ ;
DB_RX(4, "No SMbuf; receive terminated");
goto abort_frame ;
}
data = smtod(mb,char *) - 1 ;
#ifdef USE_OS_CPY
hwm_cpy_rxd2mb(rxd,data,len) ;
#else
for (r=rxd, i=used_frags ; i ; r=r->rxd_next, i--){
n = le32_to_cpu(r->rxd_rbctrl) & RD_LENGTH ;
DB_RX(6, "cp SMT frame to mb: len = %d", n);
memcpy(data,r->rxd_virt,n) ;
data += n ;
}
data = smtod(mb,char *) - 1 ;
#endif
fc = *(char *)mb->sm_data = *data ;
mb->sm_len = len - 1 ;
data++ ;
switch(fc) {
case FC_SMT_INFO :
smc->hw.fp.err_stats.err_smt_frame++ ;
DB_RX(5, "SMT frame received");
if (smc->os.hwm.pass_SMT) {
DB_RX(5, "pass SMT frame");
mac_drv_rx_complete(smc, rxd,
frag_count,len) ;
}
else {
DB_RX(5, "requeue RxD");
mac_drv_requeue_rxd(smc,rxd,frag_count);
}
smt_received_pack(smc,mb,(int)(rfsw>>25)) ;
break ;
case FC_SMT_NSA :
smc->hw.fp.err_stats.err_smt_frame++ ;
DB_RX(5, "SMT frame received");
if (smc->os.hwm.pass_NSA ||
(smc->os.hwm.pass_SMT &&
!(rfsw & A_INDIC))) {
DB_RX(5, "pass SMT frame");
mac_drv_rx_complete(smc, rxd,
frag_count,len) ;
}
else {
DB_RX(5, "requeue RxD");
mac_drv_requeue_rxd(smc,rxd,frag_count);
}
smt_received_pack(smc,mb,(int)(rfsw>>25)) ;
break ;
case FC_BEACON :
if (smc->os.hwm.pass_DB) {
DB_RX(5, "pass DB frame");
mac_drv_rx_complete(smc, rxd,
frag_count,len) ;
}
else {
DB_RX(5, "requeue RxD");
mac_drv_requeue_rxd(smc,rxd,frag_count);
}
smt_free_mbuf(smc,mb) ;
break ;
default :
DB_RX(2, "unknown FC error");
smt_free_mbuf(smc,mb) ;
DB_RX(5, "requeue RxD");
mac_drv_requeue_rxd(smc,rxd,frag_count) ;
if ((fc & 0xf0) == FC_MAC)
smc->hw.fp.err_stats.err_mac_frame++ ;
else
smc->hw.fp.err_stats.err_imp_frame++ ;
break ;
}
}
DB_RX(3, "next RxD is %p", queue->rx_curr_get);
NDD_TRACE("RHx1",queue->rx_curr_get,0,0) ;
continue ;
abort_frame:
DB_RX(5, "requeue RxD");
mac_drv_requeue_rxd(smc,rxd,frag_count) ;
DB_RX(3, "next RxD is %p", queue->rx_curr_get);
NDD_TRACE("RHx2",queue->rx_curr_get,0,0) ;
}
rx_end:
#ifdef ALL_RX_COMPLETE
mac_drv_all_receives_complete(smc) ;
#endif
return ;
}
static void smt_to_llc(struct s_smc *smc, SMbuf *mb)
{
u_char fc ;
DB_RX(4, "send a queued frame to the llc layer");
smc->os.hwm.r.len = mb->sm_len ;
smc->os.hwm.r.mb_pos = smtod(mb,char *) ;
fc = *smc->os.hwm.r.mb_pos ;
(void)mac_drv_rx_init(smc,(int)mb->sm_len,(int)fc,
smc->os.hwm.r.mb_pos,(int)mb->sm_len) ;
smt_free_mbuf(smc,mb) ;
}
void hwm_rx_frag(struct s_smc *smc, char far *virt, u_long phys, int len,
int frame_status)
{
struct s_smt_fp_rxd volatile *r ;
__le32 rbctrl;
NDD_TRACE("RHfB",virt,len,frame_status) ;
DB_RX(2, "hwm_rx_frag: len = %d, frame_status = %x", len, frame_status);
r = smc->hw.fp.rx_q[QUEUE_R1].rx_curr_put ;
r->rxd_virt = virt ;
r->rxd_rbadr = cpu_to_le32(phys) ;
rbctrl = cpu_to_le32( (((__u32)frame_status &
(FIRST_FRAG|LAST_FRAG))<<26) |
(((u_long) frame_status & FIRST_FRAG) << 21) |
BMU_OWN | BMU_CHECK | BMU_EN_IRQ_EOF | len) ;
r->rxd_rbctrl = rbctrl ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORDEV) ;
outpd(ADDR(B0_R1_CSR),CSR_START) ;
smc->hw.fp.rx_q[QUEUE_R1].rx_free-- ;
smc->hw.fp.rx_q[QUEUE_R1].rx_used++ ;
smc->hw.fp.rx_q[QUEUE_R1].rx_curr_put = r->rxd_next ;
NDD_TRACE("RHfE",r,le32_to_cpu(r->rxd_rbadr),0) ;
}
void mac_drv_clear_rx_queue(struct s_smc *smc)
{
struct s_smt_fp_rxd volatile *r ;
struct s_smt_fp_rxd volatile *next_rxd ;
struct s_smt_rx_queue *queue ;
int frag_count ;
int i ;
if (smc->hw.hw_state != STOPPED) {
SK_BREAK() ;
SMT_PANIC(smc,HWM_E0012,HWM_E0012_MSG) ;
return ;
}
queue = smc->hw.fp.rx[QUEUE_R1] ;
DB_RX(5, "clear_rx_queue");
r = queue->rx_curr_get ;
while (queue->rx_used) {
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
DB_RX(5, "switch OWN bit of RxD 0x%p", r);
r->rxd_rbctrl &= ~cpu_to_le32(BMU_OWN) ;
frag_count = 1 ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORDEV) ;
r = r->rxd_next ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
while (r != queue->rx_curr_put &&
!(r->rxd_rbctrl & cpu_to_le32(BMU_ST_BUF))) {
DB_RX(5, "Check STF bit in %p", r);
r->rxd_rbctrl &= ~cpu_to_le32(BMU_OWN) ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORDEV) ;
r = r->rxd_next ;
DRV_BUF_FLUSH(r,DDI_DMA_SYNC_FORCPU) ;
frag_count++ ;
}
DB_RX(5, "STF bit found");
next_rxd = r ;
for (r=queue->rx_curr_get,i=frag_count; i ; r=r->rxd_next,i--){
DB_RX(5, "dma_complete for RxD %p", r);
dma_complete(smc,(union s_fp_descr volatile *)r,DMA_WR);
}
DB_RX(5, "mac_drv_clear_rxd: RxD %p frag_count %d",
queue->rx_curr_get, frag_count);
mac_drv_clear_rxd(smc,queue->rx_curr_get,frag_count) ;
queue->rx_curr_get = next_rxd ;
queue->rx_used -= frag_count ;
queue->rx_free += frag_count ;
}
}
int hwm_tx_init(struct s_smc *smc, u_char fc, int frag_count, int frame_len,
int frame_status)
{
NDD_TRACE("THiB",fc,frag_count,frame_len) ;
smc->os.hwm.tx_p = smc->hw.fp.tx[frame_status & QUEUE_A0] ;
smc->os.hwm.tx_descr = TX_DESCRIPTOR | (((u_long)(frame_len-1)&3)<<27) ;
smc->os.hwm.tx_len = frame_len ;
DB_TX(3, "hwm_tx_init: fc = %x, len = %d", fc, frame_len);
if ((fc & ~(FC_SYNC_BIT|FC_LLC_PRIOR)) == FC_ASYNC_LLC) {
frame_status |= LAN_TX ;
}
else {
switch (fc) {
case FC_SMT_INFO :
case FC_SMT_NSA :
frame_status |= LAN_TX ;
break ;
case FC_SMT_LOC :
frame_status |= LOC_TX ;
break ;
case FC_SMT_LAN_LOC :
frame_status |= LAN_TX | LOC_TX ;
break ;
default :
SMT_PANIC(smc,HWM_E0010,HWM_E0010_MSG) ;
}
}
if (!smc->hw.mac_ring_is_up) {
frame_status &= ~LAN_TX ;
frame_status |= RING_DOWN ;
DB_TX(2, "Ring is down: terminate LAN_TX");
}
if (frag_count > smc->os.hwm.tx_p->tx_free) {
#ifndef NDIS_OS2
mac_drv_clear_txd(smc) ;
if (frag_count > smc->os.hwm.tx_p->tx_free) {
DB_TX(2, "Out of TxDs, terminate LAN_TX");
frame_status &= ~LAN_TX ;
frame_status |= OUT_OF_TXD ;
}
#else
DB_TX(2, "Out of TxDs, terminate LAN_TX");
frame_status &= ~LAN_TX ;
frame_status |= OUT_OF_TXD ;
#endif
}
DB_TX(3, "frame_status = %x", frame_status);
NDD_TRACE("THiE",frame_status,smc->os.hwm.tx_p->tx_free,0) ;
return frame_status;
}
void hwm_tx_frag(struct s_smc *smc, char far *virt, u_long phys, int len,
int frame_status)
{
struct s_smt_fp_txd volatile *t ;
struct s_smt_tx_queue *queue ;
__le32 tbctrl ;
queue = smc->os.hwm.tx_p ;
NDD_TRACE("THfB",virt,len,frame_status) ;
t = queue->tx_curr_put ;
DB_TX(2, "hwm_tx_frag: len = %d, frame_status = %x", len, frame_status);
if (frame_status & LAN_TX) {
DB_TX(3, "LAN_TX: TxD = %p, virt = %p", t, virt);
t->txd_virt = virt ;
t->txd_txdscr = cpu_to_le32(smc->os.hwm.tx_descr) ;
t->txd_tbadr = cpu_to_le32(phys) ;
tbctrl = cpu_to_le32((((__u32)frame_status &
(FIRST_FRAG|LAST_FRAG|EN_IRQ_EOF))<< 26) |
BMU_OWN|BMU_CHECK |len) ;
t->txd_tbctrl = tbctrl ;
#ifndef AIX
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
outpd(queue->tx_bmu_ctl,CSR_START) ;
#else
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
if (frame_status & QUEUE_A0) {
outpd(ADDR(B0_XA_CSR),CSR_START) ;
}
else {
outpd(ADDR(B0_XS_CSR),CSR_START) ;
}
#endif
queue->tx_free-- ;
queue->tx_used++ ;
queue->tx_curr_put = t->txd_next ;
if (frame_status & LAST_FRAG) {
smc->mib.m[MAC0].fddiMACTransmit_Ct++ ;
}
}
if (frame_status & LOC_TX) {
DB_TX(3, "LOC_TX:");
if (frame_status & FIRST_FRAG) {
if(!(smc->os.hwm.tx_mb = smt_get_mbuf(smc))) {
smc->hw.fp.err_stats.err_no_buf++ ;
DB_TX(4, "No SMbuf; transmit terminated");
}
else {
smc->os.hwm.tx_data =
smtod(smc->os.hwm.tx_mb,char *) - 1 ;
#ifdef USE_OS_CPY
#ifdef PASS_1ST_TXD_2_TX_COMP
hwm_cpy_txd2mb(t,smc->os.hwm.tx_data,
smc->os.hwm.tx_len) ;
#endif
#endif
}
}
if (smc->os.hwm.tx_mb) {
#ifndef USE_OS_CPY
DB_TX(3, "copy fragment into MBuf");
memcpy(smc->os.hwm.tx_data,virt,len) ;
smc->os.hwm.tx_data += len ;
#endif
if (frame_status & LAST_FRAG) {
#ifdef USE_OS_CPY
#ifndef PASS_1ST_TXD_2_TX_COMP
hwm_cpy_txd2mb(t,smc->os.hwm.tx_data,
smc->os.hwm.tx_len) ;
#endif
#endif
smc->os.hwm.tx_data =
smtod(smc->os.hwm.tx_mb,char *) - 1 ;
*(char *)smc->os.hwm.tx_mb->sm_data =
*smc->os.hwm.tx_data ;
smc->os.hwm.tx_data++ ;
smc->os.hwm.tx_mb->sm_len =
smc->os.hwm.tx_len - 1 ;
DB_TX(3, "pass LLC frame to SMT");
smt_received_pack(smc,smc->os.hwm.tx_mb,
RD_FS_LOCAL) ;
}
}
}
NDD_TRACE("THfE",t,queue->tx_free,0) ;
}
static void queue_llc_rx(struct s_smc *smc, SMbuf *mb)
{
DB_GEN(4, "queue_llc_rx: mb = %p", mb);
smc->os.hwm.queued_rx_frames++ ;
mb->sm_next = (SMbuf *)NULL ;
if (smc->os.hwm.llc_rx_pipe == NULL) {
smc->os.hwm.llc_rx_pipe = mb ;
}
else {
smc->os.hwm.llc_rx_tail->sm_next = mb ;
}
smc->os.hwm.llc_rx_tail = mb ;
if (!smc->os.hwm.isr_flag) {
smt_force_irq(smc) ;
}
}
static SMbuf *get_llc_rx(struct s_smc *smc)
{
SMbuf *mb ;
if ((mb = smc->os.hwm.llc_rx_pipe)) {
smc->os.hwm.queued_rx_frames-- ;
smc->os.hwm.llc_rx_pipe = mb->sm_next ;
}
DB_GEN(4, "get_llc_rx: mb = 0x%p", mb);
return mb;
}
static void queue_txd_mb(struct s_smc *smc, SMbuf *mb)
{
DB_GEN(4, "_rx: queue_txd_mb = %p", mb);
smc->os.hwm.queued_txd_mb++ ;
mb->sm_next = (SMbuf *)NULL ;
if (smc->os.hwm.txd_tx_pipe == NULL) {
smc->os.hwm.txd_tx_pipe = mb ;
}
else {
smc->os.hwm.txd_tx_tail->sm_next = mb ;
}
smc->os.hwm.txd_tx_tail = mb ;
}
static SMbuf *get_txd_mb(struct s_smc *smc)
{
SMbuf *mb ;
if ((mb = smc->os.hwm.txd_tx_pipe)) {
smc->os.hwm.queued_txd_mb-- ;
smc->os.hwm.txd_tx_pipe = mb->sm_next ;
}
DB_GEN(4, "get_txd_mb: mb = 0x%p", mb);
return mb;
}
void smt_send_mbuf(struct s_smc *smc, SMbuf *mb, int fc)
{
char far *data ;
int len ;
int n ;
int i ;
int frag_count ;
int frame_status ;
SK_LOC_DECL(char far,*virt[3]) ;
int frag_len[3] ;
struct s_smt_tx_queue *queue ;
struct s_smt_fp_txd volatile *t ;
u_long phys ;
__le32 tbctrl;
NDD_TRACE("THSB",mb,fc,0) ;
DB_TX(4, "smt_send_mbuf: mb = 0x%p, fc = 0x%x", mb, fc);
mb->sm_off-- ;
mb->sm_len++ ;
data = smtod(mb,char *) ;
*data = fc ;
if (fc == FC_SMT_LOC)
*data = FC_SMT_INFO ;
frag_count = 0 ;
len = mb->sm_len ;
while (len) {
n = SMT_PAGESIZE - ((long)data & (SMT_PAGESIZE-1)) ;
if (n >= len) {
n = len ;
}
DB_TX(5, "frag: virt/len = 0x%p/%d", data, n);
virt[frag_count] = data ;
frag_len[frag_count] = n ;
frag_count++ ;
len -= n ;
data += n ;
}
queue = smc->hw.fp.tx[QUEUE_A0] ;
if (fc == FC_BEACON || fc == FC_SMT_LOC) {
frame_status = LOC_TX ;
}
else {
frame_status = LAN_TX ;
if ((smc->os.hwm.pass_NSA &&(fc == FC_SMT_NSA)) ||
(smc->os.hwm.pass_SMT &&(fc == FC_SMT_INFO)))
frame_status |= LOC_TX ;
}
if (!smc->hw.mac_ring_is_up || frag_count > queue->tx_free) {
frame_status &= ~LAN_TX;
if (frame_status) {
DB_TX(2, "Ring is down: terminate LAN_TX");
}
else {
DB_TX(2, "Ring is down: terminate transmission");
smt_free_mbuf(smc,mb) ;
return ;
}
}
DB_TX(5, "frame_status = 0x%x", frame_status);
if ((frame_status & LAN_TX) && (frame_status & LOC_TX)) {
mb->sm_use_count = 2 ;
}
if (frame_status & LAN_TX) {
t = queue->tx_curr_put ;
frame_status |= FIRST_FRAG ;
for (i = 0; i < frag_count; i++) {
DB_TX(5, "init TxD = 0x%p", t);
if (i == frag_count-1) {
frame_status |= LAST_FRAG ;
t->txd_txdscr = cpu_to_le32(TX_DESCRIPTOR |
(((__u32)(mb->sm_len-1)&3) << 27)) ;
}
t->txd_virt = virt[i] ;
phys = dma_master(smc, (void far *)virt[i],
frag_len[i], DMA_RD|SMT_BUF) ;
t->txd_tbadr = cpu_to_le32(phys) ;
tbctrl = cpu_to_le32((((__u32)frame_status &
(FIRST_FRAG|LAST_FRAG)) << 26) |
BMU_OWN | BMU_CHECK | BMU_SMT_TX |frag_len[i]) ;
t->txd_tbctrl = tbctrl ;
#ifndef AIX
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
outpd(queue->tx_bmu_ctl,CSR_START) ;
#else
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
outpd(ADDR(B0_XA_CSR),CSR_START) ;
#endif
frame_status &= ~FIRST_FRAG ;
queue->tx_curr_put = t = t->txd_next ;
queue->tx_free-- ;
queue->tx_used++ ;
}
smc->mib.m[MAC0].fddiMACTransmit_Ct++ ;
queue_txd_mb(smc,mb) ;
}
if (frame_status & LOC_TX) {
DB_TX(5, "pass Mbuf to LLC queue");
queue_llc_rx(smc,mb) ;
}
mac_drv_clear_txd(smc) ;
NDD_TRACE("THSE",t,queue->tx_free,frag_count) ;
}
static void mac_drv_clear_txd(struct s_smc *smc)
{
struct s_smt_tx_queue *queue ;
struct s_smt_fp_txd volatile *t1 ;
struct s_smt_fp_txd volatile *t2 = NULL ;
SMbuf *mb ;
u_long tbctrl ;
int i ;
int frag_count ;
int n ;
NDD_TRACE("THcB",0,0,0) ;
for (i = QUEUE_S; i <= QUEUE_A0; i++) {
queue = smc->hw.fp.tx[i] ;
t1 = queue->tx_curr_get ;
DB_TX(5, "clear_txd: QUEUE = %d (0=sync/1=async)", i);
for ( ; ; ) {
frag_count = 0 ;
do {
DRV_BUF_FLUSH(t1,DDI_DMA_SYNC_FORCPU) ;
DB_TX(5, "check OWN/EOF bit of TxD 0x%p", t1);
tbctrl = le32_to_cpu(CR_READ(t1->txd_tbctrl));
if (tbctrl & BMU_OWN || !queue->tx_used){
DB_TX(4, "End of TxDs queue %d", i);
goto free_next_queue ;
}
t1 = t1->txd_next ;
frag_count++ ;
} while (!(tbctrl & BMU_EOF)) ;
t1 = queue->tx_curr_get ;
for (n = frag_count; n; n--) {
tbctrl = le32_to_cpu(t1->txd_tbctrl) ;
dma_complete(smc,
(union s_fp_descr volatile *) t1,
(int) (DMA_RD |
((tbctrl & BMU_SMT_TX) >> 18))) ;
t2 = t1 ;
t1 = t1->txd_next ;
}
if (tbctrl & BMU_SMT_TX) {
mb = get_txd_mb(smc) ;
smt_free_mbuf(smc,mb) ;
}
else {
#ifndef PASS_1ST_TXD_2_TX_COMP
DB_TX(4, "mac_drv_tx_comp for TxD 0x%p", t2);
mac_drv_tx_complete(smc,t2) ;
#else
DB_TX(4, "mac_drv_tx_comp for TxD 0x%x",
queue->tx_curr_get);
mac_drv_tx_complete(smc,queue->tx_curr_get) ;
#endif
}
queue->tx_curr_get = t1 ;
queue->tx_free += frag_count ;
queue->tx_used -= frag_count ;
}
free_next_queue: ;
}
NDD_TRACE("THcE",0,0,0) ;
}
void mac_drv_clear_tx_queue(struct s_smc *smc)
{
struct s_smt_fp_txd volatile *t ;
struct s_smt_tx_queue *queue ;
int tx_used ;
int i ;
if (smc->hw.hw_state != STOPPED) {
SK_BREAK() ;
SMT_PANIC(smc,HWM_E0011,HWM_E0011_MSG) ;
return ;
}
for (i = QUEUE_S; i <= QUEUE_A0; i++) {
queue = smc->hw.fp.tx[i] ;
DB_TX(5, "clear_tx_queue: QUEUE = %d (0=sync/1=async)", i);
t = queue->tx_curr_get ;
tx_used = queue->tx_used ;
while (tx_used) {
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORCPU) ;
DB_TX(5, "switch OWN bit of TxD 0x%p", t);
t->txd_tbctrl &= ~cpu_to_le32(BMU_OWN) ;
DRV_BUF_FLUSH(t,DDI_DMA_SYNC_FORDEV) ;
t = t->txd_next ;
tx_used-- ;
}
}
mac_drv_clear_txd(smc) ;
for (i = QUEUE_S; i <= QUEUE_A0; i++) {
queue = smc->hw.fp.tx[i] ;
t = queue->tx_curr_get ;
if (i == QUEUE_S) {
outpd(ADDR(B5_XS_DA),le32_to_cpu(t->txd_ntdadr)) ;
}
else {
outpd(ADDR(B5_XA_DA),le32_to_cpu(t->txd_ntdadr)) ;
}
queue->tx_curr_put = queue->tx_curr_get->txd_next ;
queue->tx_curr_get = queue->tx_curr_put ;
}
}
void mac_drv_debug_lev(struct s_smc *smc, int flag, int lev)
{
switch(flag) {
case (int)NULL:
DB_P.d_smtf = DB_P.d_smt = DB_P.d_ecm = DB_P.d_rmt = 0 ;
DB_P.d_cfm = 0 ;
DB_P.d_os.hwm_rx = DB_P.d_os.hwm_tx = DB_P.d_os.hwm_gen = 0 ;
#ifdef SBA
DB_P.d_sba = 0 ;
#endif
#ifdef ESS
DB_P.d_ess = 0 ;
#endif
break ;
case DEBUG_SMTF:
DB_P.d_smtf = lev ;
break ;
case DEBUG_SMT:
DB_P.d_smt = lev ;
break ;
case DEBUG_ECM:
DB_P.d_ecm = lev ;
break ;
case DEBUG_RMT:
DB_P.d_rmt = lev ;
break ;
case DEBUG_CFM:
DB_P.d_cfm = lev ;
break ;
case DEBUG_PCM:
DB_P.d_pcm = lev ;
break ;
case DEBUG_SBA:
#ifdef SBA
DB_P.d_sba = lev ;
#endif
break ;
case DEBUG_ESS:
#ifdef ESS
DB_P.d_ess = lev ;
#endif
break ;
case DB_HWM_RX:
DB_P.d_os.hwm_rx = lev ;
break ;
case DB_HWM_TX:
DB_P.d_os.hwm_tx = lev ;
break ;
case DB_HWM_GEN:
DB_P.d_os.hwm_gen = lev ;
break ;
default:
break ;
}
}
