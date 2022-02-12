static inline bool _queue_empty(struct pl330_thread *thrd)
{
return thrd->req[0].desc == NULL && thrd->req[1].desc == NULL;
}
static inline bool _queue_full(struct pl330_thread *thrd)
{
return thrd->req[0].desc != NULL && thrd->req[1].desc != NULL;
}
static inline bool is_manager(struct pl330_thread *thrd)
{
return thrd->dmac->manager == thrd;
}
static inline bool _manager_ns(struct pl330_thread *thrd)
{
return (thrd->dmac->pcfg.mode & DMAC_MODE_NS) ? true : false;
}
static inline u32 get_revision(u32 periph_id)
{
return (periph_id >> PERIPH_REV_SHIFT) & PERIPH_REV_MASK;
}
static inline u32 _emit_ADDH(unsigned dry_run, u8 buf[],
enum pl330_dst da, u16 val)
{
if (dry_run)
return SZ_DMAADDH;
buf[0] = CMD_DMAADDH;
buf[0] |= (da << 1);
*((u16 *)&buf[1]) = val;
PL330_DBGCMD_DUMP(SZ_DMAADDH, "\tDMAADDH %s %u\n",
da == 1 ? "DA" : "SA", val);
return SZ_DMAADDH;
}
static inline u32 _emit_END(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMAEND;
buf[0] = CMD_DMAEND;
PL330_DBGCMD_DUMP(SZ_DMAEND, "\tDMAEND\n");
return SZ_DMAEND;
}
static inline u32 _emit_FLUSHP(unsigned dry_run, u8 buf[], u8 peri)
{
if (dry_run)
return SZ_DMAFLUSHP;
buf[0] = CMD_DMAFLUSHP;
peri &= 0x1f;
peri <<= 3;
buf[1] = peri;
PL330_DBGCMD_DUMP(SZ_DMAFLUSHP, "\tDMAFLUSHP %u\n", peri >> 3);
return SZ_DMAFLUSHP;
}
static inline u32 _emit_LD(unsigned dry_run, u8 buf[], enum pl330_cond cond)
{
if (dry_run)
return SZ_DMALD;
buf[0] = CMD_DMALD;
if (cond == SINGLE)
buf[0] |= (0 << 1) | (1 << 0);
else if (cond == BURST)
buf[0] |= (1 << 1) | (1 << 0);
PL330_DBGCMD_DUMP(SZ_DMALD, "\tDMALD%c\n",
cond == SINGLE ? 'S' : (cond == BURST ? 'B' : 'A'));
return SZ_DMALD;
}
static inline u32 _emit_LDP(unsigned dry_run, u8 buf[],
enum pl330_cond cond, u8 peri)
{
if (dry_run)
return SZ_DMALDP;
buf[0] = CMD_DMALDP;
if (cond == BURST)
buf[0] |= (1 << 1);
peri &= 0x1f;
peri <<= 3;
buf[1] = peri;
PL330_DBGCMD_DUMP(SZ_DMALDP, "\tDMALDP%c %u\n",
cond == SINGLE ? 'S' : 'B', peri >> 3);
return SZ_DMALDP;
}
static inline u32 _emit_LP(unsigned dry_run, u8 buf[],
unsigned loop, u8 cnt)
{
if (dry_run)
return SZ_DMALP;
buf[0] = CMD_DMALP;
if (loop)
buf[0] |= (1 << 1);
cnt--;
buf[1] = cnt;
PL330_DBGCMD_DUMP(SZ_DMALP, "\tDMALP_%c %u\n", loop ? '1' : '0', cnt);
return SZ_DMALP;
}
static inline u32 _emit_LPEND(unsigned dry_run, u8 buf[],
const struct _arg_LPEND *arg)
{
enum pl330_cond cond = arg->cond;
bool forever = arg->forever;
unsigned loop = arg->loop;
u8 bjump = arg->bjump;
if (dry_run)
return SZ_DMALPEND;
buf[0] = CMD_DMALPEND;
if (loop)
buf[0] |= (1 << 2);
if (!forever)
buf[0] |= (1 << 4);
if (cond == SINGLE)
buf[0] |= (0 << 1) | (1 << 0);
else if (cond == BURST)
buf[0] |= (1 << 1) | (1 << 0);
buf[1] = bjump;
PL330_DBGCMD_DUMP(SZ_DMALPEND, "\tDMALP%s%c_%c bjmpto_%x\n",
forever ? "FE" : "END",
cond == SINGLE ? 'S' : (cond == BURST ? 'B' : 'A'),
loop ? '1' : '0',
bjump);
return SZ_DMALPEND;
}
static inline u32 _emit_KILL(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMAKILL;
buf[0] = CMD_DMAKILL;
return SZ_DMAKILL;
}
static inline u32 _emit_MOV(unsigned dry_run, u8 buf[],
enum dmamov_dst dst, u32 val)
{
if (dry_run)
return SZ_DMAMOV;
buf[0] = CMD_DMAMOV;
buf[1] = dst;
*((u32 *)&buf[2]) = val;
PL330_DBGCMD_DUMP(SZ_DMAMOV, "\tDMAMOV %s 0x%x\n",
dst == SAR ? "SAR" : (dst == DAR ? "DAR" : "CCR"), val);
return SZ_DMAMOV;
}
static inline u32 _emit_NOP(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMANOP;
buf[0] = CMD_DMANOP;
PL330_DBGCMD_DUMP(SZ_DMANOP, "\tDMANOP\n");
return SZ_DMANOP;
}
static inline u32 _emit_RMB(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMARMB;
buf[0] = CMD_DMARMB;
PL330_DBGCMD_DUMP(SZ_DMARMB, "\tDMARMB\n");
return SZ_DMARMB;
}
static inline u32 _emit_SEV(unsigned dry_run, u8 buf[], u8 ev)
{
if (dry_run)
return SZ_DMASEV;
buf[0] = CMD_DMASEV;
ev &= 0x1f;
ev <<= 3;
buf[1] = ev;
PL330_DBGCMD_DUMP(SZ_DMASEV, "\tDMASEV %u\n", ev >> 3);
return SZ_DMASEV;
}
static inline u32 _emit_ST(unsigned dry_run, u8 buf[], enum pl330_cond cond)
{
if (dry_run)
return SZ_DMAST;
buf[0] = CMD_DMAST;
if (cond == SINGLE)
buf[0] |= (0 << 1) | (1 << 0);
else if (cond == BURST)
buf[0] |= (1 << 1) | (1 << 0);
PL330_DBGCMD_DUMP(SZ_DMAST, "\tDMAST%c\n",
cond == SINGLE ? 'S' : (cond == BURST ? 'B' : 'A'));
return SZ_DMAST;
}
static inline u32 _emit_STP(unsigned dry_run, u8 buf[],
enum pl330_cond cond, u8 peri)
{
if (dry_run)
return SZ_DMASTP;
buf[0] = CMD_DMASTP;
if (cond == BURST)
buf[0] |= (1 << 1);
peri &= 0x1f;
peri <<= 3;
buf[1] = peri;
PL330_DBGCMD_DUMP(SZ_DMASTP, "\tDMASTP%c %u\n",
cond == SINGLE ? 'S' : 'B', peri >> 3);
return SZ_DMASTP;
}
static inline u32 _emit_STZ(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMASTZ;
buf[0] = CMD_DMASTZ;
PL330_DBGCMD_DUMP(SZ_DMASTZ, "\tDMASTZ\n");
return SZ_DMASTZ;
}
static inline u32 _emit_WFE(unsigned dry_run, u8 buf[], u8 ev,
unsigned invalidate)
{
if (dry_run)
return SZ_DMAWFE;
buf[0] = CMD_DMAWFE;
ev &= 0x1f;
ev <<= 3;
buf[1] = ev;
if (invalidate)
buf[1] |= (1 << 1);
PL330_DBGCMD_DUMP(SZ_DMAWFE, "\tDMAWFE %u%s\n",
ev >> 3, invalidate ? ", I" : "");
return SZ_DMAWFE;
}
static inline u32 _emit_WFP(unsigned dry_run, u8 buf[],
enum pl330_cond cond, u8 peri)
{
if (dry_run)
return SZ_DMAWFP;
buf[0] = CMD_DMAWFP;
if (cond == SINGLE)
buf[0] |= (0 << 1) | (0 << 0);
else if (cond == BURST)
buf[0] |= (1 << 1) | (0 << 0);
else
buf[0] |= (0 << 1) | (1 << 0);
peri &= 0x1f;
peri <<= 3;
buf[1] = peri;
PL330_DBGCMD_DUMP(SZ_DMAWFP, "\tDMAWFP%c %u\n",
cond == SINGLE ? 'S' : (cond == BURST ? 'B' : 'P'), peri >> 3);
return SZ_DMAWFP;
}
static inline u32 _emit_WMB(unsigned dry_run, u8 buf[])
{
if (dry_run)
return SZ_DMAWMB;
buf[0] = CMD_DMAWMB;
PL330_DBGCMD_DUMP(SZ_DMAWMB, "\tDMAWMB\n");
return SZ_DMAWMB;
}
static inline u32 _emit_GO(unsigned dry_run, u8 buf[],
const struct _arg_GO *arg)
{
u8 chan = arg->chan;
u32 addr = arg->addr;
unsigned ns = arg->ns;
if (dry_run)
return SZ_DMAGO;
buf[0] = CMD_DMAGO;
buf[0] |= (ns << 1);
buf[1] = chan & 0x7;
*((u32 *)&buf[2]) = addr;
return SZ_DMAGO;
}
static bool _until_dmac_idle(struct pl330_thread *thrd)
{
void __iomem *regs = thrd->dmac->base;
unsigned long loops = msecs_to_loops(5);
do {
if (!(readl(regs + DBGSTATUS) & DBG_BUSY))
break;
cpu_relax();
} while (--loops);
if (!loops)
return true;
return false;
}
static inline void _execute_DBGINSN(struct pl330_thread *thrd,
u8 insn[], bool as_manager)
{
void __iomem *regs = thrd->dmac->base;
u32 val;
val = (insn[0] << 16) | (insn[1] << 24);
if (!as_manager) {
val |= (1 << 0);
val |= (thrd->id << 8);
}
writel(val, regs + DBGINST0);
val = *((u32 *)&insn[2]);
writel(val, regs + DBGINST1);
if (_until_dmac_idle(thrd)) {
dev_err(thrd->dmac->ddma.dev, "DMAC halted!\n");
return;
}
writel(0, regs + DBGCMD);
}
static inline u32 _state(struct pl330_thread *thrd)
{
void __iomem *regs = thrd->dmac->base;
u32 val;
if (is_manager(thrd))
val = readl(regs + DS) & 0xf;
else
val = readl(regs + CS(thrd->id)) & 0xf;
switch (val) {
case DS_ST_STOP:
return PL330_STATE_STOPPED;
case DS_ST_EXEC:
return PL330_STATE_EXECUTING;
case DS_ST_CMISS:
return PL330_STATE_CACHEMISS;
case DS_ST_UPDTPC:
return PL330_STATE_UPDTPC;
case DS_ST_WFE:
return PL330_STATE_WFE;
case DS_ST_FAULT:
return PL330_STATE_FAULTING;
case DS_ST_ATBRR:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_ATBARRIER;
case DS_ST_QBUSY:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_QUEUEBUSY;
case DS_ST_WFP:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_WFP;
case DS_ST_KILL:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_KILLING;
case DS_ST_CMPLT:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_COMPLETING;
case DS_ST_FLTCMP:
if (is_manager(thrd))
return PL330_STATE_INVALID;
else
return PL330_STATE_FAULT_COMPLETING;
default:
return PL330_STATE_INVALID;
}
}
static void _stop(struct pl330_thread *thrd)
{
void __iomem *regs = thrd->dmac->base;
u8 insn[6] = {0, 0, 0, 0, 0, 0};
if (_state(thrd) == PL330_STATE_FAULT_COMPLETING)
UNTIL(thrd, PL330_STATE_FAULTING | PL330_STATE_KILLING);
if (_state(thrd) == PL330_STATE_COMPLETING
|| _state(thrd) == PL330_STATE_KILLING
|| _state(thrd) == PL330_STATE_STOPPED)
return;
_emit_KILL(0, insn);
writel(readl(regs + INTEN) & ~(1 << thrd->ev), regs + INTEN);
_execute_DBGINSN(thrd, insn, is_manager(thrd));
}
static bool _trigger(struct pl330_thread *thrd)
{
void __iomem *regs = thrd->dmac->base;
struct _pl330_req *req;
struct dma_pl330_desc *desc;
struct _arg_GO go;
unsigned ns;
u8 insn[6] = {0, 0, 0, 0, 0, 0};
int idx;
if (_state(thrd) != PL330_STATE_STOPPED)
return true;
idx = 1 - thrd->lstenq;
if (thrd->req[idx].desc != NULL) {
req = &thrd->req[idx];
} else {
idx = thrd->lstenq;
if (thrd->req[idx].desc != NULL)
req = &thrd->req[idx];
else
req = NULL;
}
if (!req)
return true;
desc = req->desc;
ns = desc->rqcfg.nonsecure ? 1 : 0;
if (_manager_ns(thrd) && !ns)
dev_info(thrd->dmac->ddma.dev, "%s:%d Recipe for ABORT!\n",
__func__, __LINE__);
go.chan = thrd->id;
go.addr = req->mc_bus;
go.ns = ns;
_emit_GO(0, insn, &go);
writel(readl(regs + INTEN) | (1 << thrd->ev), regs + INTEN);
_execute_DBGINSN(thrd, insn, true);
thrd->req_running = idx;
return true;
}
static bool _start(struct pl330_thread *thrd)
{
switch (_state(thrd)) {
case PL330_STATE_FAULT_COMPLETING:
UNTIL(thrd, PL330_STATE_FAULTING | PL330_STATE_KILLING);
if (_state(thrd) == PL330_STATE_KILLING)
UNTIL(thrd, PL330_STATE_STOPPED)
case PL330_STATE_FAULTING:
_stop(thrd);
case PL330_STATE_KILLING:
case PL330_STATE_COMPLETING:
UNTIL(thrd, PL330_STATE_STOPPED)
case PL330_STATE_STOPPED:
return _trigger(thrd);
case PL330_STATE_WFP:
case PL330_STATE_QUEUEBUSY:
case PL330_STATE_ATBARRIER:
case PL330_STATE_UPDTPC:
case PL330_STATE_CACHEMISS:
case PL330_STATE_EXECUTING:
return true;
case PL330_STATE_WFE:
default:
return false;
}
}
static inline int _ldst_memtomem(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs, int cyc)
{
int off = 0;
struct pl330_config *pcfg = pxs->desc->rqcfg.pcfg;
if (get_revision(pcfg->periph_id) >= PERIPH_REV_R1P0) {
while (cyc--) {
off += _emit_LD(dry_run, &buf[off], ALWAYS);
off += _emit_ST(dry_run, &buf[off], ALWAYS);
}
} else {
while (cyc--) {
off += _emit_LD(dry_run, &buf[off], ALWAYS);
off += _emit_RMB(dry_run, &buf[off]);
off += _emit_ST(dry_run, &buf[off], ALWAYS);
off += _emit_WMB(dry_run, &buf[off]);
}
}
return off;
}
static inline int _ldst_devtomem(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs, int cyc)
{
int off = 0;
while (cyc--) {
off += _emit_WFP(dry_run, &buf[off], SINGLE, pxs->desc->peri);
off += _emit_LDP(dry_run, &buf[off], SINGLE, pxs->desc->peri);
off += _emit_ST(dry_run, &buf[off], ALWAYS);
off += _emit_FLUSHP(dry_run, &buf[off], pxs->desc->peri);
}
return off;
}
static inline int _ldst_memtodev(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs, int cyc)
{
int off = 0;
while (cyc--) {
off += _emit_WFP(dry_run, &buf[off], SINGLE, pxs->desc->peri);
off += _emit_LD(dry_run, &buf[off], ALWAYS);
off += _emit_STP(dry_run, &buf[off], SINGLE, pxs->desc->peri);
off += _emit_FLUSHP(dry_run, &buf[off], pxs->desc->peri);
}
return off;
}
static int _bursts(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs, int cyc)
{
int off = 0;
switch (pxs->desc->rqtype) {
case DMA_MEM_TO_DEV:
off += _ldst_memtodev(dry_run, &buf[off], pxs, cyc);
break;
case DMA_DEV_TO_MEM:
off += _ldst_devtomem(dry_run, &buf[off], pxs, cyc);
break;
case DMA_MEM_TO_MEM:
off += _ldst_memtomem(dry_run, &buf[off], pxs, cyc);
break;
default:
off += 0x40000000;
break;
}
return off;
}
static inline int _loop(unsigned dry_run, u8 buf[],
unsigned long *bursts, const struct _xfer_spec *pxs)
{
int cyc, cycmax, szlp, szlpend, szbrst, off;
unsigned lcnt0, lcnt1, ljmp0, ljmp1;
struct _arg_LPEND lpend;
if (*bursts >= 256*256) {
lcnt1 = 256;
lcnt0 = 256;
cyc = *bursts / lcnt1 / lcnt0;
} else if (*bursts > 256) {
lcnt1 = 256;
lcnt0 = *bursts / lcnt1;
cyc = 1;
} else {
lcnt1 = *bursts;
lcnt0 = 0;
cyc = 1;
}
szlp = _emit_LP(1, buf, 0, 0);
szbrst = _bursts(1, buf, pxs, 1);
lpend.cond = ALWAYS;
lpend.forever = false;
lpend.loop = 0;
lpend.bjump = 0;
szlpend = _emit_LPEND(1, buf, &lpend);
if (lcnt0) {
szlp *= 2;
szlpend *= 2;
}
cycmax = (255 - (szlp + szlpend)) / szbrst;
cyc = (cycmax < cyc) ? cycmax : cyc;
off = 0;
if (lcnt0) {
off += _emit_LP(dry_run, &buf[off], 0, lcnt0);
ljmp0 = off;
}
off += _emit_LP(dry_run, &buf[off], 1, lcnt1);
ljmp1 = off;
off += _bursts(dry_run, &buf[off], pxs, cyc);
lpend.cond = ALWAYS;
lpend.forever = false;
lpend.loop = 1;
lpend.bjump = off - ljmp1;
off += _emit_LPEND(dry_run, &buf[off], &lpend);
if (lcnt0) {
lpend.cond = ALWAYS;
lpend.forever = false;
lpend.loop = 0;
lpend.bjump = off - ljmp0;
off += _emit_LPEND(dry_run, &buf[off], &lpend);
}
*bursts = lcnt1 * cyc;
if (lcnt0)
*bursts *= lcnt0;
return off;
}
static inline int _setup_loops(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs)
{
struct pl330_xfer *x = &pxs->desc->px;
u32 ccr = pxs->ccr;
unsigned long c, bursts = BYTE_TO_BURST(x->bytes, ccr);
int off = 0;
while (bursts) {
c = bursts;
off += _loop(dry_run, &buf[off], &c, pxs);
bursts -= c;
}
return off;
}
static inline int _setup_xfer(unsigned dry_run, u8 buf[],
const struct _xfer_spec *pxs)
{
struct pl330_xfer *x = &pxs->desc->px;
int off = 0;
off += _emit_MOV(dry_run, &buf[off], SAR, x->src_addr);
off += _emit_MOV(dry_run, &buf[off], DAR, x->dst_addr);
off += _setup_loops(dry_run, &buf[off], pxs);
return off;
}
static int _setup_req(unsigned dry_run, struct pl330_thread *thrd,
unsigned index, struct _xfer_spec *pxs)
{
struct _pl330_req *req = &thrd->req[index];
struct pl330_xfer *x;
u8 *buf = req->mc_cpu;
int off = 0;
PL330_DBGMC_START(req->mc_bus);
off += _emit_MOV(dry_run, &buf[off], CCR, pxs->ccr);
x = &pxs->desc->px;
if (x->bytes % (BRST_SIZE(pxs->ccr) * BRST_LEN(pxs->ccr)))
return -EINVAL;
off += _setup_xfer(dry_run, &buf[off], pxs);
off += _emit_SEV(dry_run, &buf[off], thrd->ev);
off += _emit_END(dry_run, &buf[off]);
return off;
}
static inline u32 _prepare_ccr(const struct pl330_reqcfg *rqc)
{
u32 ccr = 0;
if (rqc->src_inc)
ccr |= CC_SRCINC;
if (rqc->dst_inc)
ccr |= CC_DSTINC;
if (rqc->privileged)
ccr |= CC_SRCPRI | CC_DSTPRI;
if (rqc->nonsecure)
ccr |= CC_SRCNS | CC_DSTNS;
if (rqc->insnaccess)
ccr |= CC_SRCIA | CC_DSTIA;
ccr |= (((rqc->brst_len - 1) & 0xf) << CC_SRCBRSTLEN_SHFT);
ccr |= (((rqc->brst_len - 1) & 0xf) << CC_DSTBRSTLEN_SHFT);
ccr |= (rqc->brst_size << CC_SRCBRSTSIZE_SHFT);
ccr |= (rqc->brst_size << CC_DSTBRSTSIZE_SHFT);
ccr |= (rqc->scctl << CC_SRCCCTRL_SHFT);
ccr |= (rqc->dcctl << CC_DSTCCTRL_SHFT);
ccr |= (rqc->swap << CC_SWAP_SHFT);
return ccr;
}
static int pl330_submit_req(struct pl330_thread *thrd,
struct dma_pl330_desc *desc)
{
struct pl330_dmac *pl330 = thrd->dmac;
struct _xfer_spec xs;
unsigned long flags;
void __iomem *regs;
unsigned idx;
u32 ccr;
int ret = 0;
if (!desc || !thrd || thrd->free)
return -EINVAL;
regs = thrd->dmac->base;
if (pl330->state == DYING
|| pl330->dmac_tbd.reset_chan & (1 << thrd->id)) {
dev_info(thrd->dmac->ddma.dev, "%s:%d\n",
__func__, __LINE__);
return -EAGAIN;
}
if (desc->rqtype != DMA_MEM_TO_MEM &&
desc->peri >= pl330->pcfg.num_peri) {
dev_info(thrd->dmac->ddma.dev,
"%s:%d Invalid peripheral(%u)!\n",
__func__, __LINE__, desc->peri);
return -EINVAL;
}
spin_lock_irqsave(&pl330->lock, flags);
if (_queue_full(thrd)) {
ret = -EAGAIN;
goto xfer_exit;
}
if (!_manager_ns(thrd))
desc->rqcfg.nonsecure = 0;
else
desc->rqcfg.nonsecure = 1;
ccr = _prepare_ccr(&desc->rqcfg);
idx = thrd->req[0].desc == NULL ? 0 : 1;
xs.ccr = ccr;
xs.desc = desc;
ret = _setup_req(1, thrd, idx, &xs);
if (ret < 0)
goto xfer_exit;
if (ret > pl330->mcbufsz / 2) {
dev_info(pl330->ddma.dev, "%s:%d Trying increasing mcbufsz\n",
__func__, __LINE__);
ret = -ENOMEM;
goto xfer_exit;
}
thrd->lstenq = idx;
thrd->req[idx].desc = desc;
_setup_req(0, thrd, idx, &xs);
ret = 0;
xfer_exit:
spin_unlock_irqrestore(&pl330->lock, flags);
return ret;
}
static void dma_pl330_rqcb(struct dma_pl330_desc *desc, enum pl330_op_err err)
{
struct dma_pl330_chan *pch;
unsigned long flags;
if (!desc)
return;
pch = desc->pchan;
if (!pch)
return;
spin_lock_irqsave(&pch->lock, flags);
desc->status = DONE;
spin_unlock_irqrestore(&pch->lock, flags);
tasklet_schedule(&pch->task);
}
static void pl330_dotask(unsigned long data)
{
struct pl330_dmac *pl330 = (struct pl330_dmac *) data;
unsigned long flags;
int i;
spin_lock_irqsave(&pl330->lock, flags);
if (pl330->dmac_tbd.reset_dmac) {
pl330->state = DYING;
pl330->dmac_tbd.reset_mngr = true;
pl330->dmac_tbd.reset_dmac = false;
}
if (pl330->dmac_tbd.reset_mngr) {
_stop(pl330->manager);
pl330->dmac_tbd.reset_chan = (1 << pl330->pcfg.num_chan) - 1;
pl330->dmac_tbd.reset_mngr = false;
}
for (i = 0; i < pl330->pcfg.num_chan; i++) {
if (pl330->dmac_tbd.reset_chan & (1 << i)) {
struct pl330_thread *thrd = &pl330->channels[i];
void __iomem *regs = pl330->base;
enum pl330_op_err err;
_stop(thrd);
if (readl(regs + FSC) & (1 << thrd->id))
err = PL330_ERR_FAIL;
else
err = PL330_ERR_ABORT;
spin_unlock_irqrestore(&pl330->lock, flags);
dma_pl330_rqcb(thrd->req[1 - thrd->lstenq].desc, err);
dma_pl330_rqcb(thrd->req[thrd->lstenq].desc, err);
spin_lock_irqsave(&pl330->lock, flags);
thrd->req[0].desc = NULL;
thrd->req[1].desc = NULL;
thrd->req_running = -1;
pl330->dmac_tbd.reset_chan &= ~(1 << i);
}
}
spin_unlock_irqrestore(&pl330->lock, flags);
return;
}
static int pl330_update(struct pl330_dmac *pl330)
{
struct dma_pl330_desc *descdone, *tmp;
unsigned long flags;
void __iomem *regs;
u32 val;
int id, ev, ret = 0;
regs = pl330->base;
spin_lock_irqsave(&pl330->lock, flags);
val = readl(regs + FSM) & 0x1;
if (val)
pl330->dmac_tbd.reset_mngr = true;
else
pl330->dmac_tbd.reset_mngr = false;
val = readl(regs + FSC) & ((1 << pl330->pcfg.num_chan) - 1);
pl330->dmac_tbd.reset_chan |= val;
if (val) {
int i = 0;
while (i < pl330->pcfg.num_chan) {
if (val & (1 << i)) {
dev_info(pl330->ddma.dev,
"Reset Channel-%d\t CS-%x FTC-%x\n",
i, readl(regs + CS(i)),
readl(regs + FTC(i)));
_stop(&pl330->channels[i]);
}
i++;
}
}
val = readl(regs + ES);
if (pl330->pcfg.num_events < 32
&& val & ~((1 << pl330->pcfg.num_events) - 1)) {
pl330->dmac_tbd.reset_dmac = true;
dev_err(pl330->ddma.dev, "%s:%d Unexpected!\n", __func__,
__LINE__);
ret = 1;
goto updt_exit;
}
for (ev = 0; ev < pl330->pcfg.num_events; ev++) {
if (val & (1 << ev)) {
struct pl330_thread *thrd;
u32 inten = readl(regs + INTEN);
int active;
if (inten & (1 << ev))
writel(1 << ev, regs + INTCLR);
ret = 1;
id = pl330->events[ev];
thrd = &pl330->channels[id];
active = thrd->req_running;
if (active == -1)
continue;
descdone = thrd->req[active].desc;
thrd->req[active].desc = NULL;
_start(thrd);
list_add_tail(&descdone->rqd, &pl330->req_done);
}
}
list_for_each_entry_safe(descdone, tmp, &pl330->req_done, rqd) {
list_del(&descdone->rqd);
spin_unlock_irqrestore(&pl330->lock, flags);
dma_pl330_rqcb(descdone, PL330_ERR_NONE);
spin_lock_irqsave(&pl330->lock, flags);
}
updt_exit:
spin_unlock_irqrestore(&pl330->lock, flags);
if (pl330->dmac_tbd.reset_dmac
|| pl330->dmac_tbd.reset_mngr
|| pl330->dmac_tbd.reset_chan) {
ret = 1;
tasklet_schedule(&pl330->tasks);
}
return ret;
}
static inline int _alloc_event(struct pl330_thread *thrd)
{
struct pl330_dmac *pl330 = thrd->dmac;
int ev;
for (ev = 0; ev < pl330->pcfg.num_events; ev++)
if (pl330->events[ev] == -1) {
pl330->events[ev] = thrd->id;
return ev;
}
return -1;
}
static bool _chan_ns(const struct pl330_dmac *pl330, int i)
{
return pl330->pcfg.irq_ns & (1 << i);
}
static struct pl330_thread *pl330_request_channel(struct pl330_dmac *pl330)
{
struct pl330_thread *thrd = NULL;
unsigned long flags;
int chans, i;
if (pl330->state == DYING)
return NULL;
chans = pl330->pcfg.num_chan;
spin_lock_irqsave(&pl330->lock, flags);
for (i = 0; i < chans; i++) {
thrd = &pl330->channels[i];
if ((thrd->free) && (!_manager_ns(thrd) ||
_chan_ns(pl330, i))) {
thrd->ev = _alloc_event(thrd);
if (thrd->ev >= 0) {
thrd->free = false;
thrd->lstenq = 1;
thrd->req[0].desc = NULL;
thrd->req[1].desc = NULL;
thrd->req_running = -1;
break;
}
}
thrd = NULL;
}
spin_unlock_irqrestore(&pl330->lock, flags);
return thrd;
}
static inline void _free_event(struct pl330_thread *thrd, int ev)
{
struct pl330_dmac *pl330 = thrd->dmac;
if (ev >= 0 && ev < pl330->pcfg.num_events
&& pl330->events[ev] == thrd->id)
pl330->events[ev] = -1;
}
static void pl330_release_channel(struct pl330_thread *thrd)
{
struct pl330_dmac *pl330;
unsigned long flags;
if (!thrd || thrd->free)
return;
_stop(thrd);
dma_pl330_rqcb(thrd->req[1 - thrd->lstenq].desc, PL330_ERR_ABORT);
dma_pl330_rqcb(thrd->req[thrd->lstenq].desc, PL330_ERR_ABORT);
pl330 = thrd->dmac;
spin_lock_irqsave(&pl330->lock, flags);
_free_event(thrd, thrd->ev);
thrd->free = true;
spin_unlock_irqrestore(&pl330->lock, flags);
}
static void read_dmac_config(struct pl330_dmac *pl330)
{
void __iomem *regs = pl330->base;
u32 val;
val = readl(regs + CRD) >> CRD_DATA_WIDTH_SHIFT;
val &= CRD_DATA_WIDTH_MASK;
pl330->pcfg.data_bus_width = 8 * (1 << val);
val = readl(regs + CRD) >> CRD_DATA_BUFF_SHIFT;
val &= CRD_DATA_BUFF_MASK;
pl330->pcfg.data_buf_dep = val + 1;
val = readl(regs + CR0) >> CR0_NUM_CHANS_SHIFT;
val &= CR0_NUM_CHANS_MASK;
val += 1;
pl330->pcfg.num_chan = val;
val = readl(regs + CR0);
if (val & CR0_PERIPH_REQ_SET) {
val = (val >> CR0_NUM_PERIPH_SHIFT) & CR0_NUM_PERIPH_MASK;
val += 1;
pl330->pcfg.num_peri = val;
pl330->pcfg.peri_ns = readl(regs + CR4);
} else {
pl330->pcfg.num_peri = 0;
}
val = readl(regs + CR0);
if (val & CR0_BOOT_MAN_NS)
pl330->pcfg.mode |= DMAC_MODE_NS;
else
pl330->pcfg.mode &= ~DMAC_MODE_NS;
val = readl(regs + CR0) >> CR0_NUM_EVENTS_SHIFT;
val &= CR0_NUM_EVENTS_MASK;
val += 1;
pl330->pcfg.num_events = val;
pl330->pcfg.irq_ns = readl(regs + CR3);
}
static inline void _reset_thread(struct pl330_thread *thrd)
{
struct pl330_dmac *pl330 = thrd->dmac;
thrd->req[0].mc_cpu = pl330->mcode_cpu
+ (thrd->id * pl330->mcbufsz);
thrd->req[0].mc_bus = pl330->mcode_bus
+ (thrd->id * pl330->mcbufsz);
thrd->req[0].desc = NULL;
thrd->req[1].mc_cpu = thrd->req[0].mc_cpu
+ pl330->mcbufsz / 2;
thrd->req[1].mc_bus = thrd->req[0].mc_bus
+ pl330->mcbufsz / 2;
thrd->req[1].desc = NULL;
thrd->req_running = -1;
}
static int dmac_alloc_threads(struct pl330_dmac *pl330)
{
int chans = pl330->pcfg.num_chan;
struct pl330_thread *thrd;
int i;
pl330->channels = kzalloc((1 + chans) * sizeof(*thrd),
GFP_KERNEL);
if (!pl330->channels)
return -ENOMEM;
for (i = 0; i < chans; i++) {
thrd = &pl330->channels[i];
thrd->id = i;
thrd->dmac = pl330;
_reset_thread(thrd);
thrd->free = true;
}
thrd = &pl330->channels[chans];
thrd->id = chans;
thrd->dmac = pl330;
thrd->free = false;
pl330->manager = thrd;
return 0;
}
static int dmac_alloc_resources(struct pl330_dmac *pl330)
{
int chans = pl330->pcfg.num_chan;
int ret;
pl330->mcode_cpu = dma_alloc_coherent(pl330->ddma.dev,
chans * pl330->mcbufsz,
&pl330->mcode_bus, GFP_KERNEL);
if (!pl330->mcode_cpu) {
dev_err(pl330->ddma.dev, "%s:%d Can't allocate memory!\n",
__func__, __LINE__);
return -ENOMEM;
}
ret = dmac_alloc_threads(pl330);
if (ret) {
dev_err(pl330->ddma.dev, "%s:%d Can't to create channels for DMAC!\n",
__func__, __LINE__);
dma_free_coherent(pl330->ddma.dev,
chans * pl330->mcbufsz,
pl330->mcode_cpu, pl330->mcode_bus);
return ret;
}
return 0;
}
static int pl330_add(struct pl330_dmac *pl330)
{
void __iomem *regs;
int i, ret;
regs = pl330->base;
if ((pl330->pcfg.periph_id & 0xfffff) != PERIPH_ID_VAL) {
dev_err(pl330->ddma.dev, "PERIPH_ID 0x%x !\n",
pl330->pcfg.periph_id);
return -EINVAL;
}
read_dmac_config(pl330);
if (pl330->pcfg.num_events == 0) {
dev_err(pl330->ddma.dev, "%s:%d Can't work without events!\n",
__func__, __LINE__);
return -EINVAL;
}
spin_lock_init(&pl330->lock);
INIT_LIST_HEAD(&pl330->req_done);
if (!pl330->mcbufsz)
pl330->mcbufsz = MCODE_BUFF_PER_REQ * 2;
for (i = 0; i < pl330->pcfg.num_events; i++)
pl330->events[i] = -1;
ret = dmac_alloc_resources(pl330);
if (ret) {
dev_err(pl330->ddma.dev, "Unable to create channels for DMAC\n");
return ret;
}
tasklet_init(&pl330->tasks, pl330_dotask, (unsigned long) pl330);
pl330->state = INIT;
return 0;
}
static int dmac_free_threads(struct pl330_dmac *pl330)
{
struct pl330_thread *thrd;
int i;
for (i = 0; i < pl330->pcfg.num_chan; i++) {
thrd = &pl330->channels[i];
pl330_release_channel(thrd);
}
kfree(pl330->channels);
return 0;
}
static void pl330_del(struct pl330_dmac *pl330)
{
pl330->state = UNINIT;
tasklet_kill(&pl330->tasks);
dmac_free_threads(pl330);
dma_free_coherent(pl330->ddma.dev,
pl330->pcfg.num_chan * pl330->mcbufsz, pl330->mcode_cpu,
pl330->mcode_bus);
}
static inline struct dma_pl330_chan *
to_pchan(struct dma_chan *ch)
{
if (!ch)
return NULL;
return container_of(ch, struct dma_pl330_chan, chan);
}
static inline struct dma_pl330_desc *
to_desc(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct dma_pl330_desc, txd);
}
static inline void fill_queue(struct dma_pl330_chan *pch)
{
struct dma_pl330_desc *desc;
int ret;
list_for_each_entry(desc, &pch->work_list, node) {
if (desc->status == BUSY)
continue;
ret = pl330_submit_req(pch->thread, desc);
if (!ret) {
desc->status = BUSY;
} else if (ret == -EAGAIN) {
break;
} else {
desc->status = DONE;
dev_err(pch->dmac->ddma.dev, "%s:%d Bad Desc(%d)\n",
__func__, __LINE__, desc->txd.cookie);
tasklet_schedule(&pch->task);
}
}
}
static void pl330_tasklet(unsigned long data)
{
struct dma_pl330_chan *pch = (struct dma_pl330_chan *)data;
struct dma_pl330_desc *desc, *_dt;
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
list_for_each_entry_safe(desc, _dt, &pch->work_list, node)
if (desc->status == DONE) {
if (!pch->cyclic)
dma_cookie_complete(&desc->txd);
list_move_tail(&desc->node, &pch->completed_list);
}
fill_queue(pch);
spin_lock(&pch->thread->dmac->lock);
_start(pch->thread);
spin_unlock(&pch->thread->dmac->lock);
while (!list_empty(&pch->completed_list)) {
dma_async_tx_callback callback;
void *callback_param;
desc = list_first_entry(&pch->completed_list,
struct dma_pl330_desc, node);
callback = desc->txd.callback;
callback_param = desc->txd.callback_param;
if (pch->cyclic) {
desc->status = PREP;
list_move_tail(&desc->node, &pch->work_list);
} else {
desc->status = FREE;
list_move_tail(&desc->node, &pch->dmac->desc_pool);
}
dma_descriptor_unmap(&desc->txd);
if (callback) {
spin_unlock_irqrestore(&pch->lock, flags);
callback(callback_param);
spin_lock_irqsave(&pch->lock, flags);
}
}
spin_unlock_irqrestore(&pch->lock, flags);
}
bool pl330_filter(struct dma_chan *chan, void *param)
{
u8 *peri_id;
if (chan->device->dev->driver != &pl330_driver.drv)
return false;
peri_id = chan->private;
return *peri_id == (unsigned long)param;
}
static struct dma_chan *of_dma_pl330_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
int count = dma_spec->args_count;
struct pl330_dmac *pl330 = ofdma->of_dma_data;
unsigned int chan_id;
if (!pl330)
return NULL;
if (count != 1)
return NULL;
chan_id = dma_spec->args[0];
if (chan_id >= pl330->num_peripherals)
return NULL;
return dma_get_slave_channel(&pl330->peripherals[chan_id].chan);
}
static int pl330_alloc_chan_resources(struct dma_chan *chan)
{
struct dma_pl330_chan *pch = to_pchan(chan);
struct pl330_dmac *pl330 = pch->dmac;
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
dma_cookie_init(chan);
pch->cyclic = false;
pch->thread = pl330_request_channel(pl330);
if (!pch->thread) {
spin_unlock_irqrestore(&pch->lock, flags);
return -ENOMEM;
}
tasklet_init(&pch->task, pl330_tasklet, (unsigned long) pch);
spin_unlock_irqrestore(&pch->lock, flags);
return 1;
}
static int pl330_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd, unsigned long arg)
{
struct dma_pl330_chan *pch = to_pchan(chan);
struct dma_pl330_desc *desc;
unsigned long flags;
struct pl330_dmac *pl330 = pch->dmac;
struct dma_slave_config *slave_config;
LIST_HEAD(list);
switch (cmd) {
case DMA_TERMINATE_ALL:
spin_lock_irqsave(&pch->lock, flags);
spin_lock(&pl330->lock);
_stop(pch->thread);
spin_unlock(&pl330->lock);
pch->thread->req[0].desc = NULL;
pch->thread->req[1].desc = NULL;
pch->thread->req_running = -1;
list_for_each_entry(desc, &pch->submitted_list, node) {
desc->status = FREE;
dma_cookie_complete(&desc->txd);
}
list_for_each_entry(desc, &pch->work_list , node) {
desc->status = FREE;
dma_cookie_complete(&desc->txd);
}
list_for_each_entry(desc, &pch->completed_list , node) {
desc->status = FREE;
dma_cookie_complete(&desc->txd);
}
list_splice_tail_init(&pch->submitted_list, &pl330->desc_pool);
list_splice_tail_init(&pch->work_list, &pl330->desc_pool);
list_splice_tail_init(&pch->completed_list, &pl330->desc_pool);
spin_unlock_irqrestore(&pch->lock, flags);
break;
case DMA_SLAVE_CONFIG:
slave_config = (struct dma_slave_config *)arg;
if (slave_config->direction == DMA_MEM_TO_DEV) {
if (slave_config->dst_addr)
pch->fifo_addr = slave_config->dst_addr;
if (slave_config->dst_addr_width)
pch->burst_sz = __ffs(slave_config->dst_addr_width);
if (slave_config->dst_maxburst)
pch->burst_len = slave_config->dst_maxburst;
} else if (slave_config->direction == DMA_DEV_TO_MEM) {
if (slave_config->src_addr)
pch->fifo_addr = slave_config->src_addr;
if (slave_config->src_addr_width)
pch->burst_sz = __ffs(slave_config->src_addr_width);
if (slave_config->src_maxburst)
pch->burst_len = slave_config->src_maxburst;
}
break;
default:
dev_err(pch->dmac->ddma.dev, "Not supported command.\n");
return -ENXIO;
}
return 0;
}
static void pl330_free_chan_resources(struct dma_chan *chan)
{
struct dma_pl330_chan *pch = to_pchan(chan);
unsigned long flags;
tasklet_kill(&pch->task);
spin_lock_irqsave(&pch->lock, flags);
pl330_release_channel(pch->thread);
pch->thread = NULL;
if (pch->cyclic)
list_splice_tail_init(&pch->work_list, &pch->dmac->desc_pool);
spin_unlock_irqrestore(&pch->lock, flags);
}
static enum dma_status
pl330_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
return dma_cookie_status(chan, cookie, txstate);
}
static void pl330_issue_pending(struct dma_chan *chan)
{
struct dma_pl330_chan *pch = to_pchan(chan);
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
list_splice_tail_init(&pch->submitted_list, &pch->work_list);
spin_unlock_irqrestore(&pch->lock, flags);
pl330_tasklet((unsigned long)pch);
}
static dma_cookie_t pl330_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct dma_pl330_desc *desc, *last = to_desc(tx);
struct dma_pl330_chan *pch = to_pchan(tx->chan);
dma_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
while (!list_empty(&last->node)) {
desc = list_entry(last->node.next, struct dma_pl330_desc, node);
if (pch->cyclic) {
desc->txd.callback = last->txd.callback;
desc->txd.callback_param = last->txd.callback_param;
}
dma_cookie_assign(&desc->txd);
list_move_tail(&desc->node, &pch->submitted_list);
}
cookie = dma_cookie_assign(&last->txd);
list_add_tail(&last->node, &pch->submitted_list);
spin_unlock_irqrestore(&pch->lock, flags);
return cookie;
}
static inline void _init_desc(struct dma_pl330_desc *desc)
{
desc->rqcfg.swap = SWAP_NO;
desc->rqcfg.scctl = CCTRL0;
desc->rqcfg.dcctl = CCTRL0;
desc->txd.tx_submit = pl330_tx_submit;
INIT_LIST_HEAD(&desc->node);
}
static int add_desc(struct pl330_dmac *pl330, gfp_t flg, int count)
{
struct dma_pl330_desc *desc;
unsigned long flags;
int i;
desc = kcalloc(count, sizeof(*desc), flg);
if (!desc)
return 0;
spin_lock_irqsave(&pl330->pool_lock, flags);
for (i = 0; i < count; i++) {
_init_desc(&desc[i]);
list_add_tail(&desc[i].node, &pl330->desc_pool);
}
spin_unlock_irqrestore(&pl330->pool_lock, flags);
return count;
}
static struct dma_pl330_desc *pluck_desc(struct pl330_dmac *pl330)
{
struct dma_pl330_desc *desc = NULL;
unsigned long flags;
spin_lock_irqsave(&pl330->pool_lock, flags);
if (!list_empty(&pl330->desc_pool)) {
desc = list_entry(pl330->desc_pool.next,
struct dma_pl330_desc, node);
list_del_init(&desc->node);
desc->status = PREP;
desc->txd.callback = NULL;
}
spin_unlock_irqrestore(&pl330->pool_lock, flags);
return desc;
}
static struct dma_pl330_desc *pl330_get_desc(struct dma_pl330_chan *pch)
{
struct pl330_dmac *pl330 = pch->dmac;
u8 *peri_id = pch->chan.private;
struct dma_pl330_desc *desc;
desc = pluck_desc(pl330);
if (!desc) {
if (!add_desc(pl330, GFP_ATOMIC, 1))
return NULL;
desc = pluck_desc(pl330);
if (!desc) {
dev_err(pch->dmac->ddma.dev,
"%s:%d ALERT!\n", __func__, __LINE__);
return NULL;
}
}
desc->pchan = pch;
desc->txd.cookie = 0;
async_tx_ack(&desc->txd);
desc->peri = peri_id ? pch->chan.chan_id : 0;
desc->rqcfg.pcfg = &pch->dmac->pcfg;
dma_async_tx_descriptor_init(&desc->txd, &pch->chan);
return desc;
}
static inline void fill_px(struct pl330_xfer *px,
dma_addr_t dst, dma_addr_t src, size_t len)
{
px->bytes = len;
px->dst_addr = dst;
px->src_addr = src;
}
static struct dma_pl330_desc *
__pl330_prep_dma_memcpy(struct dma_pl330_chan *pch, dma_addr_t dst,
dma_addr_t src, size_t len)
{
struct dma_pl330_desc *desc = pl330_get_desc(pch);
if (!desc) {
dev_err(pch->dmac->ddma.dev, "%s:%d Unable to fetch desc\n",
__func__, __LINE__);
return NULL;
}
fill_px(&desc->px, dst, src, len);
return desc;
}
static inline int get_burst_len(struct dma_pl330_desc *desc, size_t len)
{
struct dma_pl330_chan *pch = desc->pchan;
struct pl330_dmac *pl330 = pch->dmac;
int burst_len;
burst_len = pl330->pcfg.data_bus_width / 8;
burst_len *= pl330->pcfg.data_buf_dep;
burst_len >>= desc->rqcfg.brst_size;
if (burst_len > 16)
burst_len = 16;
while (burst_len > 1) {
if (!(len % (burst_len << desc->rqcfg.brst_size)))
break;
burst_len--;
}
return burst_len;
}
static struct dma_async_tx_descriptor *pl330_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t dma_addr, size_t len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct dma_pl330_desc *desc = NULL, *first = NULL;
struct dma_pl330_chan *pch = to_pchan(chan);
struct pl330_dmac *pl330 = pch->dmac;
unsigned int i;
dma_addr_t dst;
dma_addr_t src;
if (len % period_len != 0)
return NULL;
if (!is_slave_direction(direction)) {
dev_err(pch->dmac->ddma.dev, "%s:%d Invalid dma direction\n",
__func__, __LINE__);
return NULL;
}
for (i = 0; i < len / period_len; i++) {
desc = pl330_get_desc(pch);
if (!desc) {
dev_err(pch->dmac->ddma.dev, "%s:%d Unable to fetch desc\n",
__func__, __LINE__);
if (!first)
return NULL;
spin_lock_irqsave(&pl330->pool_lock, flags);
while (!list_empty(&first->node)) {
desc = list_entry(first->node.next,
struct dma_pl330_desc, node);
list_move_tail(&desc->node, &pl330->desc_pool);
}
list_move_tail(&first->node, &pl330->desc_pool);
spin_unlock_irqrestore(&pl330->pool_lock, flags);
return NULL;
}
switch (direction) {
case DMA_MEM_TO_DEV:
desc->rqcfg.src_inc = 1;
desc->rqcfg.dst_inc = 0;
src = dma_addr;
dst = pch->fifo_addr;
break;
case DMA_DEV_TO_MEM:
desc->rqcfg.src_inc = 0;
desc->rqcfg.dst_inc = 1;
src = pch->fifo_addr;
dst = dma_addr;
break;
default:
break;
}
desc->rqtype = direction;
desc->rqcfg.brst_size = pch->burst_sz;
desc->rqcfg.brst_len = 1;
fill_px(&desc->px, dst, src, period_len);
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->node);
dma_addr += period_len;
}
if (!desc)
return NULL;
pch->cyclic = true;
desc->txd.flags = flags;
return &desc->txd;
}
static struct dma_async_tx_descriptor *
pl330_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dst,
dma_addr_t src, size_t len, unsigned long flags)
{
struct dma_pl330_desc *desc;
struct dma_pl330_chan *pch = to_pchan(chan);
struct pl330_dmac *pl330 = pch->dmac;
int burst;
if (unlikely(!pch || !len))
return NULL;
desc = __pl330_prep_dma_memcpy(pch, dst, src, len);
if (!desc)
return NULL;
desc->rqcfg.src_inc = 1;
desc->rqcfg.dst_inc = 1;
desc->rqtype = DMA_MEM_TO_MEM;
burst = pl330->pcfg.data_bus_width / 8;
while (burst > 1) {
if (!(len % burst))
break;
burst /= 2;
}
desc->rqcfg.brst_size = 0;
while (burst != (1 << desc->rqcfg.brst_size))
desc->rqcfg.brst_size++;
desc->rqcfg.brst_len = get_burst_len(desc, len);
desc->txd.flags = flags;
return &desc->txd;
}
static void __pl330_giveback_desc(struct pl330_dmac *pl330,
struct dma_pl330_desc *first)
{
unsigned long flags;
struct dma_pl330_desc *desc;
if (!first)
return;
spin_lock_irqsave(&pl330->pool_lock, flags);
while (!list_empty(&first->node)) {
desc = list_entry(first->node.next,
struct dma_pl330_desc, node);
list_move_tail(&desc->node, &pl330->desc_pool);
}
list_move_tail(&first->node, &pl330->desc_pool);
spin_unlock_irqrestore(&pl330->pool_lock, flags);
}
static struct dma_async_tx_descriptor *
pl330_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flg, void *context)
{
struct dma_pl330_desc *first, *desc = NULL;
struct dma_pl330_chan *pch = to_pchan(chan);
struct scatterlist *sg;
int i;
dma_addr_t addr;
if (unlikely(!pch || !sgl || !sg_len))
return NULL;
addr = pch->fifo_addr;
first = NULL;
for_each_sg(sgl, sg, sg_len, i) {
desc = pl330_get_desc(pch);
if (!desc) {
struct pl330_dmac *pl330 = pch->dmac;
dev_err(pch->dmac->ddma.dev,
"%s:%d Unable to fetch desc\n",
__func__, __LINE__);
__pl330_giveback_desc(pl330, first);
return NULL;
}
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->node);
if (direction == DMA_MEM_TO_DEV) {
desc->rqcfg.src_inc = 1;
desc->rqcfg.dst_inc = 0;
fill_px(&desc->px,
addr, sg_dma_address(sg), sg_dma_len(sg));
} else {
desc->rqcfg.src_inc = 0;
desc->rqcfg.dst_inc = 1;
fill_px(&desc->px,
sg_dma_address(sg), addr, sg_dma_len(sg));
}
desc->rqcfg.brst_size = pch->burst_sz;
desc->rqcfg.brst_len = 1;
desc->rqtype = direction;
}
desc->txd.flags = flg;
return &desc->txd;
}
static irqreturn_t pl330_irq_handler(int irq, void *data)
{
if (pl330_update(data))
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static int pl330_dma_device_slave_caps(struct dma_chan *dchan,
struct dma_slave_caps *caps)
{
caps->src_addr_widths = PL330_DMA_BUSWIDTHS;
caps->dstn_addr_widths = PL330_DMA_BUSWIDTHS;
caps->directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
caps->cmd_pause = false;
caps->cmd_terminate = true;
caps->residue_granularity = DMA_RESIDUE_GRANULARITY_DESCRIPTOR;
return 0;
}
static int
pl330_probe(struct amba_device *adev, const struct amba_id *id)
{
struct dma_pl330_platdata *pdat;
struct pl330_config *pcfg;
struct pl330_dmac *pl330;
struct dma_pl330_chan *pch, *_p;
struct dma_device *pd;
struct resource *res;
int i, ret, irq;
int num_chan;
pdat = dev_get_platdata(&adev->dev);
ret = dma_set_mask_and_coherent(&adev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pl330 = devm_kzalloc(&adev->dev, sizeof(*pl330), GFP_KERNEL);
if (!pl330) {
dev_err(&adev->dev, "unable to allocate mem\n");
return -ENOMEM;
}
pl330->mcbufsz = pdat ? pdat->mcbuf_sz : 0;
res = &adev->res;
pl330->base = devm_ioremap_resource(&adev->dev, res);
if (IS_ERR(pl330->base))
return PTR_ERR(pl330->base);
amba_set_drvdata(adev, pl330);
for (i = 0; i < AMBA_NR_IRQS; i++) {
irq = adev->irq[i];
if (irq) {
ret = devm_request_irq(&adev->dev, irq,
pl330_irq_handler, 0,
dev_name(&adev->dev), pl330);
if (ret)
return ret;
} else {
break;
}
}
pcfg = &pl330->pcfg;
pcfg->periph_id = adev->periphid;
ret = pl330_add(pl330);
if (ret)
return ret;
INIT_LIST_HEAD(&pl330->desc_pool);
spin_lock_init(&pl330->pool_lock);
if (!add_desc(pl330, GFP_KERNEL, NR_DEFAULT_DESC))
dev_warn(&adev->dev, "unable to allocate desc\n");
pd = &pl330->ddma;
INIT_LIST_HEAD(&pd->channels);
if (pdat)
num_chan = max_t(int, pdat->nr_valid_peri, pcfg->num_chan);
else
num_chan = max_t(int, pcfg->num_peri, pcfg->num_chan);
pl330->num_peripherals = num_chan;
pl330->peripherals = kzalloc(num_chan * sizeof(*pch), GFP_KERNEL);
if (!pl330->peripherals) {
ret = -ENOMEM;
dev_err(&adev->dev, "unable to allocate pl330->peripherals\n");
goto probe_err2;
}
for (i = 0; i < num_chan; i++) {
pch = &pl330->peripherals[i];
if (!adev->dev.of_node)
pch->chan.private = pdat ? &pdat->peri_id[i] : NULL;
else
pch->chan.private = adev->dev.of_node;
INIT_LIST_HEAD(&pch->submitted_list);
INIT_LIST_HEAD(&pch->work_list);
INIT_LIST_HEAD(&pch->completed_list);
spin_lock_init(&pch->lock);
pch->thread = NULL;
pch->chan.device = pd;
pch->dmac = pl330;
list_add_tail(&pch->chan.device_node, &pd->channels);
}
pd->dev = &adev->dev;
if (pdat) {
pd->cap_mask = pdat->cap_mask;
} else {
dma_cap_set(DMA_MEMCPY, pd->cap_mask);
if (pcfg->num_peri) {
dma_cap_set(DMA_SLAVE, pd->cap_mask);
dma_cap_set(DMA_CYCLIC, pd->cap_mask);
dma_cap_set(DMA_PRIVATE, pd->cap_mask);
}
}
pd->device_alloc_chan_resources = pl330_alloc_chan_resources;
pd->device_free_chan_resources = pl330_free_chan_resources;
pd->device_prep_dma_memcpy = pl330_prep_dma_memcpy;
pd->device_prep_dma_cyclic = pl330_prep_dma_cyclic;
pd->device_tx_status = pl330_tx_status;
pd->device_prep_slave_sg = pl330_prep_slave_sg;
pd->device_control = pl330_control;
pd->device_issue_pending = pl330_issue_pending;
pd->device_slave_caps = pl330_dma_device_slave_caps;
ret = dma_async_device_register(pd);
if (ret) {
dev_err(&adev->dev, "unable to register DMAC\n");
goto probe_err3;
}
if (adev->dev.of_node) {
ret = of_dma_controller_register(adev->dev.of_node,
of_dma_pl330_xlate, pl330);
if (ret) {
dev_err(&adev->dev,
"unable to register DMA to the generic DT DMA helpers\n");
}
}
adev->dev.dma_parms = &pl330->dma_parms;
ret = dma_set_max_seg_size(&adev->dev, 1900800);
if (ret)
dev_err(&adev->dev, "unable to set the seg size\n");
dev_info(&adev->dev,
"Loaded driver for PL330 DMAC-%d\n", adev->periphid);
dev_info(&adev->dev,
"\tDBUFF-%ux%ubytes Num_Chans-%u Num_Peri-%u Num_Events-%u\n",
pcfg->data_buf_dep, pcfg->data_bus_width / 8, pcfg->num_chan,
pcfg->num_peri, pcfg->num_events);
return 0;
probe_err3:
list_for_each_entry_safe(pch, _p, &pl330->ddma.channels,
chan.device_node) {
list_del(&pch->chan.device_node);
pl330_control(&pch->chan, DMA_TERMINATE_ALL, 0);
pl330_free_chan_resources(&pch->chan);
}
probe_err2:
pl330_del(pl330);
return ret;
}
static int pl330_remove(struct amba_device *adev)
{
struct pl330_dmac *pl330 = amba_get_drvdata(adev);
struct dma_pl330_chan *pch, *_p;
if (adev->dev.of_node)
of_dma_controller_free(adev->dev.of_node);
dma_async_device_unregister(&pl330->ddma);
list_for_each_entry_safe(pch, _p, &pl330->ddma.channels,
chan.device_node) {
list_del(&pch->chan.device_node);
pl330_control(&pch->chan, DMA_TERMINATE_ALL, 0);
pl330_free_chan_resources(&pch->chan);
}
pl330_del(pl330);
return 0;
}
