static void sdma_get(struct qib_sdma_state *ss)
{
kref_get(&ss->kref);
}
static void sdma_complete(struct kref *kref)
{
struct qib_sdma_state *ss =
container_of(kref, struct qib_sdma_state, kref);
complete(&ss->comp);
}
static void sdma_put(struct qib_sdma_state *ss)
{
kref_put(&ss->kref, sdma_complete);
}
static void sdma_finalput(struct qib_sdma_state *ss)
{
sdma_put(ss);
wait_for_completion(&ss->comp);
}
static void clear_sdma_activelist(struct qib_pportdata *ppd)
{
struct qib_sdma_txreq *txp, *txp_next;
list_for_each_entry_safe(txp, txp_next, &ppd->sdma_activelist, list) {
list_del_init(&txp->list);
if (txp->flags & QIB_SDMA_TXREQ_F_FREEDESC) {
unsigned idx;
idx = txp->start_idx;
while (idx != txp->next_descq_idx) {
unmap_desc(ppd, idx);
if (++idx == ppd->sdma_descq_cnt)
idx = 0;
}
}
if (txp->callback)
(*txp->callback)(txp, QIB_SDMA_TXREQ_S_ABORTED);
}
}
static void sdma_sw_clean_up_task(unsigned long opaque)
{
struct qib_pportdata *ppd = (struct qib_pportdata *) opaque;
unsigned long flags;
spin_lock_irqsave(&ppd->sdma_lock, flags);
qib_sdma_make_progress(ppd);
clear_sdma_activelist(ppd);
ppd->sdma_descq_removed = ppd->sdma_descq_added;
ppd->sdma_descq_tail = 0;
ppd->sdma_descq_head = 0;
ppd->sdma_head_dma[0] = 0;
ppd->sdma_generation = 0;
__qib_sdma_process_event(ppd, qib_sdma_event_e40_sw_cleaned);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
}
static void sdma_hw_start_up(struct qib_pportdata *ppd)
{
struct qib_sdma_state *ss = &ppd->sdma_state;
unsigned bufno;
for (bufno = ss->first_sendbuf; bufno < ss->last_sendbuf; ++bufno)
ppd->dd->f_sendctrl(ppd, QIB_SENDCTRL_DISARM_BUF(bufno));
ppd->dd->f_sdma_hw_start_up(ppd);
}
static void sdma_sw_tear_down(struct qib_pportdata *ppd)
{
struct qib_sdma_state *ss = &ppd->sdma_state;
sdma_put(ss);
}
static void sdma_start_sw_clean_up(struct qib_pportdata *ppd)
{
tasklet_hi_schedule(&ppd->sdma_sw_clean_up_task);
}
static void sdma_set_state(struct qib_pportdata *ppd,
enum qib_sdma_states next_state)
{
struct qib_sdma_state *ss = &ppd->sdma_state;
struct sdma_set_state_action *action = ss->set_state_action;
unsigned op = 0;
ss->previous_state = ss->current_state;
ss->previous_op = ss->current_op;
ss->current_state = next_state;
if (action[next_state].op_enable)
op |= QIB_SDMA_SENDCTRL_OP_ENABLE;
if (action[next_state].op_intenable)
op |= QIB_SDMA_SENDCTRL_OP_INTENABLE;
if (action[next_state].op_halt)
op |= QIB_SDMA_SENDCTRL_OP_HALT;
if (action[next_state].op_drain)
op |= QIB_SDMA_SENDCTRL_OP_DRAIN;
if (action[next_state].go_s99_running_tofalse)
ss->go_s99_running = 0;
if (action[next_state].go_s99_running_totrue)
ss->go_s99_running = 1;
ss->current_op = op;
ppd->dd->f_sdma_sendctrl(ppd, ss->current_op);
}
static void unmap_desc(struct qib_pportdata *ppd, unsigned head)
{
__le64 *descqp = &ppd->sdma_descq[head].qw[0];
u64 desc[2];
dma_addr_t addr;
size_t len;
desc[0] = le64_to_cpu(descqp[0]);
desc[1] = le64_to_cpu(descqp[1]);
addr = (desc[1] << 32) | (desc[0] >> 32);
len = (desc[0] >> 14) & (0x7ffULL << 2);
dma_unmap_single(&ppd->dd->pcidev->dev, addr, len, DMA_TO_DEVICE);
}
static int alloc_sdma(struct qib_pportdata *ppd)
{
ppd->sdma_descq_cnt = sdma_descq_cnt;
if (!ppd->sdma_descq_cnt)
ppd->sdma_descq_cnt = 256;
ppd->sdma_descq = dma_alloc_coherent(&ppd->dd->pcidev->dev,
ppd->sdma_descq_cnt * sizeof(u64[2]), &ppd->sdma_descq_phys,
GFP_KERNEL);
if (!ppd->sdma_descq) {
qib_dev_err(ppd->dd,
"failed to allocate SendDMA descriptor FIFO memory\n");
goto bail;
}
ppd->sdma_head_dma = dma_alloc_coherent(&ppd->dd->pcidev->dev,
PAGE_SIZE, &ppd->sdma_head_phys, GFP_KERNEL);
if (!ppd->sdma_head_dma) {
qib_dev_err(ppd->dd,
"failed to allocate SendDMA head memory\n");
goto cleanup_descq;
}
ppd->sdma_head_dma[0] = 0;
return 0;
cleanup_descq:
dma_free_coherent(&ppd->dd->pcidev->dev,
ppd->sdma_descq_cnt * sizeof(u64[2]), (void *)ppd->sdma_descq,
ppd->sdma_descq_phys);
ppd->sdma_descq = NULL;
ppd->sdma_descq_phys = 0;
bail:
ppd->sdma_descq_cnt = 0;
return -ENOMEM;
}
static void free_sdma(struct qib_pportdata *ppd)
{
struct qib_devdata *dd = ppd->dd;
if (ppd->sdma_head_dma) {
dma_free_coherent(&dd->pcidev->dev, PAGE_SIZE,
(void *)ppd->sdma_head_dma,
ppd->sdma_head_phys);
ppd->sdma_head_dma = NULL;
ppd->sdma_head_phys = 0;
}
if (ppd->sdma_descq) {
dma_free_coherent(&dd->pcidev->dev,
ppd->sdma_descq_cnt * sizeof(u64[2]),
ppd->sdma_descq, ppd->sdma_descq_phys);
ppd->sdma_descq = NULL;
ppd->sdma_descq_phys = 0;
}
}
static inline void make_sdma_desc(struct qib_pportdata *ppd,
u64 *sdmadesc, u64 addr, u64 dwlen,
u64 dwoffset)
{
WARN_ON(addr & 3);
sdmadesc[1] = addr >> 32;
sdmadesc[0] = (addr & 0xfffffffcULL) << 32;
sdmadesc[0] |= (ppd->sdma_generation & 3ULL) <<
SDMA_DESC_GEN_LSB;
sdmadesc[0] |= (dwlen & 0x7ffULL) << SDMA_DESC_COUNT_LSB;
sdmadesc[0] |= dwoffset & 0x7ffULL;
}
int qib_sdma_make_progress(struct qib_pportdata *ppd)
{
struct list_head *lp = NULL;
struct qib_sdma_txreq *txp = NULL;
struct qib_devdata *dd = ppd->dd;
int progress = 0;
u16 hwhead;
u16 idx = 0;
hwhead = dd->f_sdma_gethead(ppd);
if (!list_empty(&ppd->sdma_activelist)) {
lp = ppd->sdma_activelist.next;
txp = list_entry(lp, struct qib_sdma_txreq, list);
idx = txp->start_idx;
}
while (ppd->sdma_descq_head != hwhead) {
if (txp && (txp->flags & QIB_SDMA_TXREQ_F_FREEDESC) &&
(idx == ppd->sdma_descq_head)) {
unmap_desc(ppd, ppd->sdma_descq_head);
if (++idx == ppd->sdma_descq_cnt)
idx = 0;
}
ppd->sdma_descq_removed++;
if (++ppd->sdma_descq_head == ppd->sdma_descq_cnt)
ppd->sdma_descq_head = 0;
if (txp && txp->next_descq_idx == ppd->sdma_descq_head) {
list_del_init(&txp->list);
if (txp->callback)
(*txp->callback)(txp, QIB_SDMA_TXREQ_S_OK);
if (list_empty(&ppd->sdma_activelist))
txp = NULL;
else {
lp = ppd->sdma_activelist.next;
txp = list_entry(lp, struct qib_sdma_txreq,
list);
idx = txp->start_idx;
}
}
progress = 1;
}
if (progress)
qib_verbs_sdma_desc_avail(ppd, qib_sdma_descq_freecnt(ppd));
return progress;
}
void qib_sdma_intr(struct qib_pportdata *ppd)
{
unsigned long flags;
spin_lock_irqsave(&ppd->sdma_lock, flags);
__qib_sdma_intr(ppd);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
}
void __qib_sdma_intr(struct qib_pportdata *ppd)
{
if (__qib_sdma_running(ppd))
qib_sdma_make_progress(ppd);
}
int qib_setup_sdma(struct qib_pportdata *ppd)
{
struct qib_devdata *dd = ppd->dd;
unsigned long flags;
int ret = 0;
ret = alloc_sdma(ppd);
if (ret)
goto bail;
ppd->dd->f_sdma_init_early(ppd);
spin_lock_irqsave(&ppd->sdma_lock, flags);
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
kref_init(&ppd->sdma_state.kref);
init_completion(&ppd->sdma_state.comp);
ppd->sdma_generation = 0;
ppd->sdma_descq_head = 0;
ppd->sdma_descq_removed = 0;
ppd->sdma_descq_added = 0;
INIT_LIST_HEAD(&ppd->sdma_activelist);
tasklet_init(&ppd->sdma_sw_clean_up_task, sdma_sw_clean_up_task,
(unsigned long)ppd);
ret = dd->f_init_sdma_regs(ppd);
if (ret)
goto bail_alloc;
qib_sdma_process_event(ppd, qib_sdma_event_e10_go_hw_start);
return 0;
bail_alloc:
qib_teardown_sdma(ppd);
bail:
return ret;
}
void qib_teardown_sdma(struct qib_pportdata *ppd)
{
qib_sdma_process_event(ppd, qib_sdma_event_e00_go_hw_down);
sdma_finalput(&ppd->sdma_state);
free_sdma(ppd);
}
int qib_sdma_running(struct qib_pportdata *ppd)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&ppd->sdma_lock, flags);
ret = __qib_sdma_running(ppd);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return ret;
}
static void complete_sdma_err_req(struct qib_pportdata *ppd,
struct qib_verbs_txreq *tx)
{
atomic_inc(&tx->qp->s_dma_busy);
tx->txreq.start_idx = 0;
tx->txreq.next_descq_idx = 0;
list_add_tail(&tx->txreq.list, &ppd->sdma_activelist);
clear_sdma_activelist(ppd);
}
int qib_sdma_verbs_send(struct qib_pportdata *ppd,
struct qib_sge_state *ss, u32 dwords,
struct qib_verbs_txreq *tx)
{
unsigned long flags;
struct qib_sge *sge;
struct qib_qp *qp;
int ret = 0;
u16 tail;
__le64 *descqp;
u64 sdmadesc[2];
u32 dwoffset;
dma_addr_t addr;
spin_lock_irqsave(&ppd->sdma_lock, flags);
retry:
if (unlikely(!__qib_sdma_running(ppd))) {
complete_sdma_err_req(ppd, tx);
goto unlock;
}
if (tx->txreq.sg_count > qib_sdma_descq_freecnt(ppd)) {
if (qib_sdma_make_progress(ppd))
goto retry;
if (ppd->dd->flags & QIB_HAS_SDMA_TIMEOUT)
ppd->dd->f_sdma_set_desc_cnt(ppd,
ppd->sdma_descq_cnt / 2);
goto busy;
}
dwoffset = tx->hdr_dwords;
make_sdma_desc(ppd, sdmadesc, (u64) tx->txreq.addr, dwoffset, 0);
sdmadesc[0] |= SDMA_DESC_FIRST;
if (tx->txreq.flags & QIB_SDMA_TXREQ_F_USELARGEBUF)
sdmadesc[0] |= SDMA_DESC_USE_LARGE_BUF;
tail = ppd->sdma_descq_tail;
descqp = &ppd->sdma_descq[tail].qw[0];
*descqp++ = cpu_to_le64(sdmadesc[0]);
*descqp++ = cpu_to_le64(sdmadesc[1]);
if (++tail == ppd->sdma_descq_cnt) {
tail = 0;
descqp = &ppd->sdma_descq[0].qw[0];
++ppd->sdma_generation;
}
tx->txreq.start_idx = tail;
sge = &ss->sge;
while (dwords) {
u32 dw;
u32 len;
len = dwords << 2;
if (len > sge->length)
len = sge->length;
if (len > sge->sge_length)
len = sge->sge_length;
BUG_ON(len == 0);
dw = (len + 3) >> 2;
addr = dma_map_single(&ppd->dd->pcidev->dev, sge->vaddr,
dw << 2, DMA_TO_DEVICE);
if (dma_mapping_error(&ppd->dd->pcidev->dev, addr))
goto unmap;
sdmadesc[0] = 0;
make_sdma_desc(ppd, sdmadesc, (u64) addr, dw, dwoffset);
if (tx->txreq.flags & QIB_SDMA_TXREQ_F_USELARGEBUF)
sdmadesc[0] |= SDMA_DESC_USE_LARGE_BUF;
*descqp++ = cpu_to_le64(sdmadesc[0]);
*descqp++ = cpu_to_le64(sdmadesc[1]);
if (++tail == ppd->sdma_descq_cnt) {
tail = 0;
descqp = &ppd->sdma_descq[0].qw[0];
++ppd->sdma_generation;
}
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ss->num_sge)
*sge = *ss->sg_list++;
} else if (sge->length == 0 && sge->mr->lkey) {
if (++sge->n >= QIB_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
break;
sge->n = 0;
}
sge->vaddr =
sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length =
sge->mr->map[sge->m]->segs[sge->n].length;
}
dwoffset += dw;
dwords -= dw;
}
if (!tail)
descqp = &ppd->sdma_descq[ppd->sdma_descq_cnt].qw[0];
descqp -= 2;
descqp[0] |= cpu_to_le64(SDMA_DESC_LAST);
if (tx->txreq.flags & QIB_SDMA_TXREQ_F_HEADTOHOST)
descqp[0] |= cpu_to_le64(SDMA_DESC_DMA_HEAD);
if (tx->txreq.flags & QIB_SDMA_TXREQ_F_INTREQ)
descqp[0] |= cpu_to_le64(SDMA_DESC_INTR);
atomic_inc(&tx->qp->s_dma_busy);
tx->txreq.next_descq_idx = tail;
ppd->dd->f_sdma_update_tail(ppd, tail);
ppd->sdma_descq_added += tx->txreq.sg_count;
list_add_tail(&tx->txreq.list, &ppd->sdma_activelist);
goto unlock;
unmap:
for (;;) {
if (!tail)
tail = ppd->sdma_descq_cnt - 1;
else
tail--;
if (tail == ppd->sdma_descq_tail)
break;
unmap_desc(ppd, tail);
}
qp = tx->qp;
qib_put_txreq(tx);
spin_lock(&qp->r_lock);
spin_lock(&qp->s_lock);
if (qp->ibqp.qp_type == IB_QPT_RC) {
if (ib_qib_state_ops[qp->state] & QIB_PROCESS_RECV_OK)
qib_error_qp(qp, IB_WC_GENERAL_ERR);
} else if (qp->s_wqe)
qib_send_complete(qp, qp->s_wqe, IB_WC_GENERAL_ERR);
spin_unlock(&qp->s_lock);
spin_unlock(&qp->r_lock);
goto unlock;
busy:
qp = tx->qp;
spin_lock(&qp->s_lock);
if (ib_qib_state_ops[qp->state] & QIB_PROCESS_RECV_OK) {
struct qib_ibdev *dev;
tx->ss = ss;
tx->dwords = dwords;
qp->s_tx = tx;
dev = &ppd->dd->verbs_dev;
spin_lock(&dev->pending_lock);
if (list_empty(&qp->iowait)) {
struct qib_ibport *ibp;
ibp = &ppd->ibport_data;
ibp->n_dmawait++;
qp->s_flags |= QIB_S_WAIT_DMA_DESC;
list_add_tail(&qp->iowait, &dev->dmawait);
}
spin_unlock(&dev->pending_lock);
qp->s_flags &= ~QIB_S_BUSY;
spin_unlock(&qp->s_lock);
ret = -EBUSY;
} else {
spin_unlock(&qp->s_lock);
qib_put_txreq(tx);
}
unlock:
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return ret;
}
void dump_sdma_state(struct qib_pportdata *ppd)
{
struct qib_sdma_desc *descq;
struct qib_sdma_txreq *txp, *txpnext;
__le64 *descqp;
u64 desc[2];
u64 addr;
u16 gen, dwlen, dwoffset;
u16 head, tail, cnt;
head = ppd->sdma_descq_head;
tail = ppd->sdma_descq_tail;
cnt = qib_sdma_descq_freecnt(ppd);
descq = ppd->sdma_descq;
qib_dev_porterr(ppd->dd, ppd->port,
"SDMA ppd->sdma_descq_head: %u\n", head);
qib_dev_porterr(ppd->dd, ppd->port,
"SDMA ppd->sdma_descq_tail: %u\n", tail);
qib_dev_porterr(ppd->dd, ppd->port,
"SDMA sdma_descq_freecnt: %u\n", cnt);
while (head != tail) {
char flags[6] = { 'x', 'x', 'x', 'x', 'x', 0 };
descqp = &descq[head].qw[0];
desc[0] = le64_to_cpu(descqp[0]);
desc[1] = le64_to_cpu(descqp[1]);
flags[0] = (desc[0] & 1<<15) ? 'I' : '-';
flags[1] = (desc[0] & 1<<14) ? 'L' : 'S';
flags[2] = (desc[0] & 1<<13) ? 'H' : '-';
flags[3] = (desc[0] & 1<<12) ? 'F' : '-';
flags[4] = (desc[0] & 1<<11) ? 'L' : '-';
addr = (desc[1] << 32) | ((desc[0] >> 32) & 0xfffffffcULL);
gen = (desc[0] >> 30) & 3ULL;
dwlen = (desc[0] >> 14) & (0x7ffULL << 2);
dwoffset = (desc[0] & 0x7ffULL) << 2;
qib_dev_porterr(ppd->dd, ppd->port,
"SDMA sdmadesc[%u]: flags:%s addr:0x%016llx gen:%u len:%u bytes offset:%u bytes\n",
head, flags, addr, gen, dwlen, dwoffset);
if (++head == ppd->sdma_descq_cnt)
head = 0;
}
list_for_each_entry_safe(txp, txpnext, &ppd->sdma_activelist,
list)
qib_dev_porterr(ppd->dd, ppd->port,
"SDMA txp->start_idx: %u txp->next_descq_idx: %u\n",
txp->start_idx, txp->next_descq_idx);
}
void qib_sdma_process_event(struct qib_pportdata *ppd,
enum qib_sdma_events event)
{
unsigned long flags;
spin_lock_irqsave(&ppd->sdma_lock, flags);
__qib_sdma_process_event(ppd, event);
if (ppd->sdma_state.current_state == qib_sdma_state_s99_running)
qib_verbs_sdma_desc_avail(ppd, qib_sdma_descq_freecnt(ppd));
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
}
void __qib_sdma_process_event(struct qib_pportdata *ppd,
enum qib_sdma_events event)
{
struct qib_sdma_state *ss = &ppd->sdma_state;
switch (ss->current_state) {
case qib_sdma_state_s00_hw_down:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
break;
case qib_sdma_event_e30_go_running:
ss->go_s99_running = 1;
case qib_sdma_event_e10_go_hw_start:
sdma_get(&ppd->sdma_state);
sdma_set_state(ppd,
qib_sdma_state_s10_hw_start_up_wait);
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e40_sw_cleaned:
sdma_sw_tear_down(ppd);
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
break;
case qib_sdma_event_e70_go_idle:
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s10_hw_start_up_wait:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
sdma_sw_tear_down(ppd);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
sdma_set_state(ppd, ss->go_s99_running ?
qib_sdma_state_s99_running :
qib_sdma_state_s20_idle);
break;
case qib_sdma_event_e30_go_running:
ss->go_s99_running = 1;
break;
case qib_sdma_event_e40_sw_cleaned:
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
break;
case qib_sdma_event_e70_go_idle:
ss->go_s99_running = 0;
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s20_idle:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
sdma_sw_tear_down(ppd);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e30_go_running:
sdma_set_state(ppd, qib_sdma_state_s99_running);
ss->go_s99_running = 1;
break;
case qib_sdma_event_e40_sw_cleaned:
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
break;
case qib_sdma_event_e70_go_idle:
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s30_sw_clean_up_wait:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e30_go_running:
ss->go_s99_running = 1;
break;
case qib_sdma_event_e40_sw_cleaned:
sdma_set_state(ppd,
qib_sdma_state_s10_hw_start_up_wait);
sdma_hw_start_up(ppd);
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
break;
case qib_sdma_event_e70_go_idle:
ss->go_s99_running = 0;
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s40_hw_clean_up_wait:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e30_go_running:
ss->go_s99_running = 1;
break;
case qib_sdma_event_e40_sw_cleaned:
break;
case qib_sdma_event_e50_hw_cleaned:
sdma_set_state(ppd,
qib_sdma_state_s30_sw_clean_up_wait);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e60_hw_halted:
break;
case qib_sdma_event_e70_go_idle:
ss->go_s99_running = 0;
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s50_hw_halt_wait:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e30_go_running:
ss->go_s99_running = 1;
break;
case qib_sdma_event_e40_sw_cleaned:
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
sdma_set_state(ppd,
qib_sdma_state_s40_hw_clean_up_wait);
ppd->dd->f_sdma_hw_clean_up(ppd);
break;
case qib_sdma_event_e70_go_idle:
ss->go_s99_running = 0;
break;
case qib_sdma_event_e7220_err_halted:
break;
case qib_sdma_event_e7322_err_halted:
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
case qib_sdma_state_s99_running:
switch (event) {
case qib_sdma_event_e00_go_hw_down:
sdma_set_state(ppd, qib_sdma_state_s00_hw_down);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e10_go_hw_start:
break;
case qib_sdma_event_e20_hw_started:
break;
case qib_sdma_event_e30_go_running:
break;
case qib_sdma_event_e40_sw_cleaned:
break;
case qib_sdma_event_e50_hw_cleaned:
break;
case qib_sdma_event_e60_hw_halted:
sdma_set_state(ppd,
qib_sdma_state_s30_sw_clean_up_wait);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e70_go_idle:
sdma_set_state(ppd, qib_sdma_state_s50_hw_halt_wait);
ss->go_s99_running = 0;
break;
case qib_sdma_event_e7220_err_halted:
sdma_set_state(ppd,
qib_sdma_state_s30_sw_clean_up_wait);
sdma_start_sw_clean_up(ppd);
break;
case qib_sdma_event_e7322_err_halted:
sdma_set_state(ppd, qib_sdma_state_s50_hw_halt_wait);
break;
case qib_sdma_event_e90_timer_tick:
break;
}
break;
}
ss->last_event = event;
}
