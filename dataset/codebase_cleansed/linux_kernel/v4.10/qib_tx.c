void qib_disarm_piobufs(struct qib_devdata *dd, unsigned first, unsigned cnt)
{
unsigned long flags;
unsigned i;
unsigned last;
last = first + cnt;
spin_lock_irqsave(&dd->pioavail_lock, flags);
for (i = first; i < last; i++) {
__clear_bit(i, dd->pio_need_disarm);
dd->f_sendctrl(dd->pport, QIB_SENDCTRL_DISARM_BUF(i));
}
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
}
int qib_disarm_piobufs_ifneeded(struct qib_ctxtdata *rcd)
{
struct qib_devdata *dd = rcd->dd;
unsigned i;
unsigned last;
unsigned n = 0;
last = rcd->pio_base + rcd->piocnt;
if (rcd->user_event_mask) {
clear_bit(_QIB_EVENT_DISARM_BUFS_BIT, &rcd->user_event_mask[0]);
for (i = 1; i < rcd->subctxt_cnt; i++)
clear_bit(_QIB_EVENT_DISARM_BUFS_BIT,
&rcd->user_event_mask[i]);
}
spin_lock_irq(&dd->pioavail_lock);
for (i = rcd->pio_base; i < last; i++) {
if (__test_and_clear_bit(i, dd->pio_need_disarm)) {
n++;
dd->f_sendctrl(rcd->ppd, QIB_SENDCTRL_DISARM_BUF(i));
}
}
spin_unlock_irq(&dd->pioavail_lock);
return 0;
}
static struct qib_pportdata *is_sdma_buf(struct qib_devdata *dd, unsigned i)
{
struct qib_pportdata *ppd;
unsigned pidx;
for (pidx = 0; pidx < dd->num_pports; pidx++) {
ppd = dd->pport + pidx;
if (i >= ppd->sdma_state.first_sendbuf &&
i < ppd->sdma_state.last_sendbuf)
return ppd;
}
return NULL;
}
static int find_ctxt(struct qib_devdata *dd, unsigned bufn)
{
struct qib_ctxtdata *rcd;
unsigned ctxt;
int ret = 0;
spin_lock(&dd->uctxt_lock);
for (ctxt = dd->first_user_ctxt; ctxt < dd->cfgctxts; ctxt++) {
rcd = dd->rcd[ctxt];
if (!rcd || bufn < rcd->pio_base ||
bufn >= rcd->pio_base + rcd->piocnt)
continue;
if (rcd->user_event_mask) {
int i;
set_bit(_QIB_EVENT_DISARM_BUFS_BIT,
&rcd->user_event_mask[0]);
for (i = 1; i < rcd->subctxt_cnt; i++)
set_bit(_QIB_EVENT_DISARM_BUFS_BIT,
&rcd->user_event_mask[i]);
}
ret = 1;
break;
}
spin_unlock(&dd->uctxt_lock);
return ret;
}
void qib_disarm_piobufs_set(struct qib_devdata *dd, unsigned long *mask,
unsigned cnt)
{
struct qib_pportdata *ppd, *pppd[QIB_MAX_IB_PORTS];
unsigned i;
unsigned long flags;
for (i = 0; i < dd->num_pports; i++)
pppd[i] = NULL;
for (i = 0; i < cnt; i++) {
int which;
if (!test_bit(i, mask))
continue;
ppd = is_sdma_buf(dd, i);
if (ppd) {
pppd[ppd->port] = ppd;
continue;
}
spin_lock_irqsave(&dd->pioavail_lock, flags);
if (test_bit(i, dd->pio_writing) ||
(!test_bit(i << 1, dd->pioavailkernel) &&
find_ctxt(dd, i))) {
__set_bit(i, dd->pio_need_disarm);
which = 0;
} else {
which = 1;
dd->f_sendctrl(dd->pport, QIB_SENDCTRL_DISARM_BUF(i));
}
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
}
for (i = 0; i < dd->num_pports; i++)
if (pppd[i])
qib_cancel_sends(pppd[i]);
}
static void update_send_bufs(struct qib_devdata *dd)
{
unsigned long flags;
unsigned i;
const unsigned piobregs = dd->pioavregs;
if (!dd->pioavailregs_dma)
return;
spin_lock_irqsave(&dd->pioavail_lock, flags);
for (i = 0; i < piobregs; i++) {
u64 pchbusy, pchg, piov, pnew;
piov = le64_to_cpu(dd->pioavailregs_dma[i]);
pchg = dd->pioavailkernel[i] &
~(dd->pioavailshadow[i] ^ piov);
pchbusy = pchg << QLOGIC_IB_SENDPIOAVAIL_BUSY_SHIFT;
if (pchg && (pchbusy & dd->pioavailshadow[i])) {
pnew = dd->pioavailshadow[i] & ~pchbusy;
pnew |= piov & pchbusy;
dd->pioavailshadow[i] = pnew;
}
}
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
}
static noinline void no_send_bufs(struct qib_devdata *dd)
{
dd->upd_pio_shadow = 1;
qib_stats.sps_nopiobufs++;
}
u32 __iomem *qib_getsendbuf_range(struct qib_devdata *dd, u32 *pbufnum,
u32 first, u32 last)
{
unsigned i, j, updated = 0;
unsigned nbufs;
unsigned long flags;
unsigned long *shadow = dd->pioavailshadow;
u32 __iomem *buf;
if (!(dd->flags & QIB_PRESENT))
return NULL;
nbufs = last - first + 1;
if (dd->upd_pio_shadow) {
update_shadow:
update_send_bufs(dd);
updated++;
}
i = first;
spin_lock_irqsave(&dd->pioavail_lock, flags);
if (dd->last_pio >= first && dd->last_pio <= last)
i = dd->last_pio + 1;
if (!first)
nbufs = last - dd->min_kernel_pio + 1;
for (j = 0; j < nbufs; j++, i++) {
if (i > last)
i = !first ? dd->min_kernel_pio : first;
if (__test_and_set_bit((2 * i) + 1, shadow))
continue;
__change_bit(2 * i, shadow);
__set_bit(i, dd->pio_writing);
if (!first && first != last)
dd->last_pio = i;
break;
}
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
if (j == nbufs) {
if (!updated)
goto update_shadow;
no_send_bufs(dd);
buf = NULL;
} else {
if (i < dd->piobcnt2k)
buf = (u32 __iomem *)(dd->pio2kbase +
i * dd->palign);
else if (i < dd->piobcnt2k + dd->piobcnt4k || !dd->piovl15base)
buf = (u32 __iomem *)(dd->pio4kbase +
(i - dd->piobcnt2k) * dd->align4k);
else
buf = (u32 __iomem *)(dd->piovl15base +
(i - (dd->piobcnt2k + dd->piobcnt4k)) *
dd->align4k);
if (pbufnum)
*pbufnum = i;
dd->upd_pio_shadow = 0;
}
return buf;
}
void qib_sendbuf_done(struct qib_devdata *dd, unsigned n)
{
unsigned long flags;
spin_lock_irqsave(&dd->pioavail_lock, flags);
__clear_bit(n, dd->pio_writing);
if (__test_and_clear_bit(n, dd->pio_need_disarm))
dd->f_sendctrl(dd->pport, QIB_SENDCTRL_DISARM_BUF(n));
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
}
void qib_chg_pioavailkernel(struct qib_devdata *dd, unsigned start,
unsigned len, u32 avail, struct qib_ctxtdata *rcd)
{
unsigned long flags;
unsigned end;
unsigned ostart = start;
start *= 2;
end = start + len * 2;
spin_lock_irqsave(&dd->pioavail_lock, flags);
while (start < end) {
if (avail) {
unsigned long dma;
int i;
i = start / BITS_PER_LONG;
__clear_bit(QLOGIC_IB_SENDPIOAVAIL_BUSY_SHIFT + start,
dd->pioavailshadow);
dma = (unsigned long)
le64_to_cpu(dd->pioavailregs_dma[i]);
if (test_bit((QLOGIC_IB_SENDPIOAVAIL_CHECK_SHIFT +
start) % BITS_PER_LONG, &dma))
__set_bit(QLOGIC_IB_SENDPIOAVAIL_CHECK_SHIFT +
start, dd->pioavailshadow);
else
__clear_bit(QLOGIC_IB_SENDPIOAVAIL_CHECK_SHIFT
+ start, dd->pioavailshadow);
__set_bit(start, dd->pioavailkernel);
if ((start >> 1) < dd->min_kernel_pio)
dd->min_kernel_pio = start >> 1;
} else {
__set_bit(start + QLOGIC_IB_SENDPIOAVAIL_BUSY_SHIFT,
dd->pioavailshadow);
__clear_bit(start, dd->pioavailkernel);
if ((start >> 1) > dd->min_kernel_pio)
dd->min_kernel_pio = start >> 1;
}
start += 2;
}
if (dd->min_kernel_pio > 0 && dd->last_pio < dd->min_kernel_pio - 1)
dd->last_pio = dd->min_kernel_pio - 1;
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
dd->f_txchk_change(dd, ostart, len, avail, rcd);
}
void qib_cancel_sends(struct qib_pportdata *ppd)
{
struct qib_devdata *dd = ppd->dd;
struct qib_ctxtdata *rcd;
unsigned long flags;
unsigned ctxt;
unsigned i;
unsigned last;
for (ctxt = dd->first_user_ctxt; ctxt < dd->cfgctxts; ctxt++) {
spin_lock_irqsave(&dd->uctxt_lock, flags);
rcd = dd->rcd[ctxt];
if (rcd && rcd->ppd == ppd) {
last = rcd->pio_base + rcd->piocnt;
if (rcd->user_event_mask) {
set_bit(_QIB_EVENT_DISARM_BUFS_BIT,
&rcd->user_event_mask[0]);
for (i = 1; i < rcd->subctxt_cnt; i++)
set_bit(_QIB_EVENT_DISARM_BUFS_BIT,
&rcd->user_event_mask[i]);
}
i = rcd->pio_base;
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
spin_lock_irqsave(&dd->pioavail_lock, flags);
for (; i < last; i++)
__set_bit(i, dd->pio_need_disarm);
spin_unlock_irqrestore(&dd->pioavail_lock, flags);
} else
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
}
if (!(dd->flags & QIB_HAS_SEND_DMA))
dd->f_sendctrl(ppd, QIB_SENDCTRL_DISARM_ALL |
QIB_SENDCTRL_FLUSH);
}
void qib_force_pio_avail_update(struct qib_devdata *dd)
{
dd->f_sendctrl(dd->pport, QIB_SENDCTRL_AVAIL_BLIP);
}
void qib_hol_down(struct qib_pportdata *ppd)
{
if (!(ppd->lflags & QIBL_IB_AUTONEG_INPROG))
qib_cancel_sends(ppd);
}
void qib_hol_init(struct qib_pportdata *ppd)
{
if (ppd->hol_state != QIB_HOL_INIT) {
ppd->hol_state = QIB_HOL_INIT;
mod_timer(&ppd->hol_timer,
jiffies + msecs_to_jiffies(qib_hol_timeout_ms));
}
}
void qib_hol_up(struct qib_pportdata *ppd)
{
ppd->hol_state = QIB_HOL_UP;
}
void qib_hol_event(unsigned long opaque)
{
struct qib_pportdata *ppd = (struct qib_pportdata *)opaque;
if (!(ppd->dd->flags & QIB_INITTED))
return;
if (ppd->hol_state != QIB_HOL_UP) {
qib_hol_down(ppd);
mod_timer(&ppd->hol_timer,
jiffies + msecs_to_jiffies(qib_hol_timeout_ms));
}
}
