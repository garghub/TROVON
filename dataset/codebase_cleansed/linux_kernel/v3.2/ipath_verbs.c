static inline struct ipath_ucontext *to_iucontext(struct ib_ucontext
*ibucontext)
{
return container_of(ibucontext, struct ipath_ucontext, ibucontext);
}
void ipath_copy_sge(struct ipath_sge_state *ss, void *data, u32 length)
{
struct ipath_sge *sge = &ss->sge;
while (length) {
u32 len = sge->length;
if (len > length)
len = length;
if (len > sge->sge_length)
len = sge->sge_length;
BUG_ON(len == 0);
memcpy(sge->vaddr, data, len);
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ss->num_sge)
*sge = *ss->sg_list++;
} else if (sge->length == 0 && sge->mr != NULL) {
if (++sge->n >= IPATH_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
break;
sge->n = 0;
}
sge->vaddr =
sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length =
sge->mr->map[sge->m]->segs[sge->n].length;
}
data += len;
length -= len;
}
}
void ipath_skip_sge(struct ipath_sge_state *ss, u32 length)
{
struct ipath_sge *sge = &ss->sge;
while (length) {
u32 len = sge->length;
if (len > length)
len = length;
if (len > sge->sge_length)
len = sge->sge_length;
BUG_ON(len == 0);
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ss->num_sge)
*sge = *ss->sg_list++;
} else if (sge->length == 0 && sge->mr != NULL) {
if (++sge->n >= IPATH_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
break;
sge->n = 0;
}
sge->vaddr =
sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length =
sge->mr->map[sge->m]->segs[sge->n].length;
}
length -= len;
}
}
static u32 ipath_count_sge(struct ipath_sge_state *ss, u32 length)
{
struct ipath_sge *sg_list = ss->sg_list;
struct ipath_sge sge = ss->sge;
u8 num_sge = ss->num_sge;
u32 ndesc = 1;
while (length) {
u32 len = sge.length;
if (len > length)
len = length;
if (len > sge.sge_length)
len = sge.sge_length;
BUG_ON(len == 0);
if (((long) sge.vaddr & (sizeof(u32) - 1)) ||
(len != length && (len & (sizeof(u32) - 1)))) {
ndesc = 0;
break;
}
ndesc++;
sge.vaddr += len;
sge.length -= len;
sge.sge_length -= len;
if (sge.sge_length == 0) {
if (--num_sge)
sge = *sg_list++;
} else if (sge.length == 0 && sge.mr != NULL) {
if (++sge.n >= IPATH_SEGSZ) {
if (++sge.m >= sge.mr->mapsz)
break;
sge.n = 0;
}
sge.vaddr =
sge.mr->map[sge.m]->segs[sge.n].vaddr;
sge.length =
sge.mr->map[sge.m]->segs[sge.n].length;
}
length -= len;
}
return ndesc;
}
static void ipath_copy_from_sge(void *data, struct ipath_sge_state *ss,
u32 length)
{
struct ipath_sge *sge = &ss->sge;
while (length) {
u32 len = sge->length;
if (len > length)
len = length;
if (len > sge->sge_length)
len = sge->sge_length;
BUG_ON(len == 0);
memcpy(data, sge->vaddr, len);
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ss->num_sge)
*sge = *ss->sg_list++;
} else if (sge->length == 0 && sge->mr != NULL) {
if (++sge->n >= IPATH_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
break;
sge->n = 0;
}
sge->vaddr =
sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length =
sge->mr->map[sge->m]->segs[sge->n].length;
}
data += len;
length -= len;
}
}
static int ipath_post_one_send(struct ipath_qp *qp, struct ib_send_wr *wr)
{
struct ipath_swqe *wqe;
u32 next;
int i;
int j;
int acc;
int ret;
unsigned long flags;
struct ipath_devdata *dd = to_idev(qp->ibqp.device)->dd;
spin_lock_irqsave(&qp->s_lock, flags);
if (qp->ibqp.qp_type != IB_QPT_SMI &&
!(dd->ipath_flags & IPATH_LINKACTIVE)) {
ret = -ENETDOWN;
goto bail;
}
if (unlikely(!(ib_ipath_state_ops[qp->state] & IPATH_POST_SEND_OK)))
goto bail_inval;
if (wr->num_sge > qp->s_max_sge)
goto bail_inval;
if (qp->ibqp.qp_type == IB_QPT_UC) {
if ((unsigned) wr->opcode >= IB_WR_RDMA_READ)
goto bail_inval;
} else if (qp->ibqp.qp_type == IB_QPT_UD) {
if (wr->opcode != IB_WR_SEND &&
wr->opcode != IB_WR_SEND_WITH_IMM)
goto bail_inval;
if (qp->ibqp.pd != wr->wr.ud.ah->pd)
goto bail_inval;
} else if ((unsigned) wr->opcode > IB_WR_ATOMIC_FETCH_AND_ADD)
goto bail_inval;
else if (wr->opcode >= IB_WR_ATOMIC_CMP_AND_SWP &&
(wr->num_sge == 0 ||
wr->sg_list[0].length < sizeof(u64) ||
wr->sg_list[0].addr & (sizeof(u64) - 1)))
goto bail_inval;
else if (wr->opcode >= IB_WR_RDMA_READ && !qp->s_max_rd_atomic)
goto bail_inval;
next = qp->s_head + 1;
if (next >= qp->s_size)
next = 0;
if (next == qp->s_last) {
ret = -ENOMEM;
goto bail;
}
wqe = get_swqe_ptr(qp, qp->s_head);
wqe->wr = *wr;
wqe->length = 0;
if (wr->num_sge) {
acc = wr->opcode >= IB_WR_RDMA_READ ?
IB_ACCESS_LOCAL_WRITE : 0;
for (i = 0, j = 0; i < wr->num_sge; i++) {
u32 length = wr->sg_list[i].length;
int ok;
if (length == 0)
continue;
ok = ipath_lkey_ok(qp, &wqe->sg_list[j],
&wr->sg_list[i], acc);
if (!ok)
goto bail_inval;
wqe->length += length;
j++;
}
wqe->wr.num_sge = j;
}
if (qp->ibqp.qp_type == IB_QPT_UC ||
qp->ibqp.qp_type == IB_QPT_RC) {
if (wqe->length > 0x80000000U)
goto bail_inval;
} else if (wqe->length > to_idev(qp->ibqp.device)->dd->ipath_ibmtu)
goto bail_inval;
wqe->ssn = qp->s_ssn++;
qp->s_head = next;
ret = 0;
goto bail;
bail_inval:
ret = -EINVAL;
bail:
spin_unlock_irqrestore(&qp->s_lock, flags);
return ret;
}
static int ipath_post_send(struct ib_qp *ibqp, struct ib_send_wr *wr,
struct ib_send_wr **bad_wr)
{
struct ipath_qp *qp = to_iqp(ibqp);
int err = 0;
for (; wr; wr = wr->next) {
err = ipath_post_one_send(qp, wr);
if (err) {
*bad_wr = wr;
goto bail;
}
}
ipath_do_send((unsigned long) qp);
bail:
return err;
}
static int ipath_post_receive(struct ib_qp *ibqp, struct ib_recv_wr *wr,
struct ib_recv_wr **bad_wr)
{
struct ipath_qp *qp = to_iqp(ibqp);
struct ipath_rwq *wq = qp->r_rq.wq;
unsigned long flags;
int ret;
if (!(ib_ipath_state_ops[qp->state] & IPATH_POST_RECV_OK) || !wq) {
*bad_wr = wr;
ret = -EINVAL;
goto bail;
}
for (; wr; wr = wr->next) {
struct ipath_rwqe *wqe;
u32 next;
int i;
if ((unsigned) wr->num_sge > qp->r_rq.max_sge) {
*bad_wr = wr;
ret = -EINVAL;
goto bail;
}
spin_lock_irqsave(&qp->r_rq.lock, flags);
next = wq->head + 1;
if (next >= qp->r_rq.size)
next = 0;
if (next == wq->tail) {
spin_unlock_irqrestore(&qp->r_rq.lock, flags);
*bad_wr = wr;
ret = -ENOMEM;
goto bail;
}
wqe = get_rwqe_ptr(&qp->r_rq, wq->head);
wqe->wr_id = wr->wr_id;
wqe->num_sge = wr->num_sge;
for (i = 0; i < wr->num_sge; i++)
wqe->sg_list[i] = wr->sg_list[i];
smp_wmb();
wq->head = next;
spin_unlock_irqrestore(&qp->r_rq.lock, flags);
}
ret = 0;
bail:
return ret;
}
static void ipath_qp_rcv(struct ipath_ibdev *dev,
struct ipath_ib_header *hdr, int has_grh,
void *data, u32 tlen, struct ipath_qp *qp)
{
if (!(ib_ipath_state_ops[qp->state] & IPATH_PROCESS_RECV_OK)) {
dev->n_pkt_drops++;
return;
}
switch (qp->ibqp.qp_type) {
case IB_QPT_SMI:
case IB_QPT_GSI:
if (ib_ipath_disable_sma)
break;
case IB_QPT_UD:
ipath_ud_rcv(dev, hdr, has_grh, data, tlen, qp);
break;
case IB_QPT_RC:
ipath_rc_rcv(dev, hdr, has_grh, data, tlen, qp);
break;
case IB_QPT_UC:
ipath_uc_rcv(dev, hdr, has_grh, data, tlen, qp);
break;
default:
break;
}
}
void ipath_ib_rcv(struct ipath_ibdev *dev, void *rhdr, void *data,
u32 tlen)
{
struct ipath_ib_header *hdr = rhdr;
struct ipath_other_headers *ohdr;
struct ipath_qp *qp;
u32 qp_num;
int lnh;
u8 opcode;
u16 lid;
if (unlikely(dev == NULL))
goto bail;
if (unlikely(tlen < 24)) {
dev->rcv_errors++;
goto bail;
}
lid = be16_to_cpu(hdr->lrh[1]);
if (lid < IPATH_MULTICAST_LID_BASE) {
lid &= ~((1 << dev->dd->ipath_lmc) - 1);
if (unlikely(lid != dev->dd->ipath_lid)) {
dev->rcv_errors++;
goto bail;
}
}
lnh = be16_to_cpu(hdr->lrh[0]) & 3;
if (lnh == IPATH_LRH_BTH)
ohdr = &hdr->u.oth;
else if (lnh == IPATH_LRH_GRH)
ohdr = &hdr->u.l.oth;
else {
dev->rcv_errors++;
goto bail;
}
opcode = be32_to_cpu(ohdr->bth[0]) >> 24;
dev->opstats[opcode].n_bytes += tlen;
dev->opstats[opcode].n_packets++;
qp_num = be32_to_cpu(ohdr->bth[1]) & IPATH_QPN_MASK;
if (qp_num == IPATH_MULTICAST_QPN) {
struct ipath_mcast *mcast;
struct ipath_mcast_qp *p;
if (lnh != IPATH_LRH_GRH) {
dev->n_pkt_drops++;
goto bail;
}
mcast = ipath_mcast_find(&hdr->u.l.grh.dgid);
if (mcast == NULL) {
dev->n_pkt_drops++;
goto bail;
}
dev->n_multicast_rcv++;
list_for_each_entry_rcu(p, &mcast->qp_list, list)
ipath_qp_rcv(dev, hdr, 1, data, tlen, p->qp);
if (atomic_dec_return(&mcast->refcount) <= 1)
wake_up(&mcast->wait);
} else {
qp = ipath_lookup_qpn(&dev->qp_table, qp_num);
if (qp) {
dev->n_unicast_rcv++;
ipath_qp_rcv(dev, hdr, lnh == IPATH_LRH_GRH, data,
tlen, qp);
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
} else
dev->n_pkt_drops++;
}
bail:;
}
static void ipath_ib_timer(struct ipath_ibdev *dev)
{
struct ipath_qp *resend = NULL;
struct ipath_qp *rnr = NULL;
struct list_head *last;
struct ipath_qp *qp;
unsigned long flags;
if (dev == NULL)
return;
spin_lock_irqsave(&dev->pending_lock, flags);
if (++dev->pending_index >= ARRAY_SIZE(dev->pending))
dev->pending_index = 0;
last = &dev->pending[dev->pending_index];
while (!list_empty(last)) {
qp = list_entry(last->next, struct ipath_qp, timerwait);
list_del_init(&qp->timerwait);
qp->timer_next = resend;
resend = qp;
atomic_inc(&qp->refcount);
}
last = &dev->rnrwait;
if (!list_empty(last)) {
qp = list_entry(last->next, struct ipath_qp, timerwait);
if (--qp->s_rnr_timeout == 0) {
do {
list_del_init(&qp->timerwait);
qp->timer_next = rnr;
rnr = qp;
atomic_inc(&qp->refcount);
if (list_empty(last))
break;
qp = list_entry(last->next, struct ipath_qp,
timerwait);
} while (qp->s_rnr_timeout == 0);
}
}
if (dev->pma_sample_status == IB_PMA_SAMPLE_STATUS_STARTED &&
--dev->pma_sample_start == 0) {
dev->pma_sample_status = IB_PMA_SAMPLE_STATUS_RUNNING;
ipath_snapshot_counters(dev->dd, &dev->ipath_sword,
&dev->ipath_rword,
&dev->ipath_spkts,
&dev->ipath_rpkts,
&dev->ipath_xmit_wait);
}
if (dev->pma_sample_status == IB_PMA_SAMPLE_STATUS_RUNNING) {
if (dev->pma_sample_interval == 0) {
u64 ta, tb, tc, td, te;
dev->pma_sample_status = IB_PMA_SAMPLE_STATUS_DONE;
ipath_snapshot_counters(dev->dd, &ta, &tb,
&tc, &td, &te);
dev->ipath_sword = ta - dev->ipath_sword;
dev->ipath_rword = tb - dev->ipath_rword;
dev->ipath_spkts = tc - dev->ipath_spkts;
dev->ipath_rpkts = td - dev->ipath_rpkts;
dev->ipath_xmit_wait = te - dev->ipath_xmit_wait;
}
else
dev->pma_sample_interval--;
}
spin_unlock_irqrestore(&dev->pending_lock, flags);
while (resend != NULL) {
qp = resend;
resend = qp->timer_next;
spin_lock_irqsave(&qp->s_lock, flags);
if (qp->s_last != qp->s_tail &&
ib_ipath_state_ops[qp->state] & IPATH_PROCESS_SEND_OK) {
dev->n_timeouts++;
ipath_restart_rc(qp, qp->s_last_psn + 1);
}
spin_unlock_irqrestore(&qp->s_lock, flags);
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
}
while (rnr != NULL) {
qp = rnr;
rnr = qp->timer_next;
spin_lock_irqsave(&qp->s_lock, flags);
if (ib_ipath_state_ops[qp->state] & IPATH_PROCESS_SEND_OK)
ipath_schedule_send(qp);
spin_unlock_irqrestore(&qp->s_lock, flags);
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
}
}
static void update_sge(struct ipath_sge_state *ss, u32 length)
{
struct ipath_sge *sge = &ss->sge;
sge->vaddr += length;
sge->length -= length;
sge->sge_length -= length;
if (sge->sge_length == 0) {
if (--ss->num_sge)
*sge = *ss->sg_list++;
} else if (sge->length == 0 && sge->mr != NULL) {
if (++sge->n >= IPATH_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
return;
sge->n = 0;
}
sge->vaddr = sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length = sge->mr->map[sge->m]->segs[sge->n].length;
}
}
static inline u32 get_upper_bits(u32 data, u32 shift)
{
return data >> shift;
}
static inline u32 set_upper_bits(u32 data, u32 shift)
{
return data << shift;
}
static inline u32 clear_upper_bytes(u32 data, u32 n, u32 off)
{
data <<= ((sizeof(u32) - n) * BITS_PER_BYTE);
data >>= ((sizeof(u32) - n - off) * BITS_PER_BYTE);
return data;
}
static inline u32 get_upper_bits(u32 data, u32 shift)
{
return data << shift;
}
static inline u32 set_upper_bits(u32 data, u32 shift)
{
return data >> shift;
}
static inline u32 clear_upper_bytes(u32 data, u32 n, u32 off)
{
data >>= ((sizeof(u32) - n) * BITS_PER_BYTE);
data <<= ((sizeof(u32) - n - off) * BITS_PER_BYTE);
return data;
}
static void copy_io(u32 __iomem *piobuf, struct ipath_sge_state *ss,
u32 length, unsigned flush_wc)
{
u32 extra = 0;
u32 data = 0;
u32 last;
while (1) {
u32 len = ss->sge.length;
u32 off;
if (len > length)
len = length;
if (len > ss->sge.sge_length)
len = ss->sge.sge_length;
BUG_ON(len == 0);
off = (unsigned long)ss->sge.vaddr & (sizeof(u32) - 1);
if (off) {
u32 *addr = (u32 *)((unsigned long)ss->sge.vaddr &
~(sizeof(u32) - 1));
u32 v = get_upper_bits(*addr, off * BITS_PER_BYTE);
u32 y;
y = sizeof(u32) - off;
if (len > y)
len = y;
if (len + extra >= sizeof(u32)) {
data |= set_upper_bits(v, extra *
BITS_PER_BYTE);
len = sizeof(u32) - extra;
if (len == length) {
last = data;
break;
}
__raw_writel(data, piobuf);
piobuf++;
extra = 0;
data = 0;
} else {
data |= clear_upper_bytes(v, len, extra);
if (len == length) {
last = data;
break;
}
extra += len;
}
} else if (extra) {
u32 *addr = (u32 *) ss->sge.vaddr;
int shift = extra * BITS_PER_BYTE;
int ushift = 32 - shift;
u32 l = len;
while (l >= sizeof(u32)) {
u32 v = *addr;
data |= set_upper_bits(v, shift);
__raw_writel(data, piobuf);
data = get_upper_bits(v, ushift);
piobuf++;
addr++;
l -= sizeof(u32);
}
if (l) {
u32 v = *addr;
if (l + extra >= sizeof(u32)) {
data |= set_upper_bits(v, shift);
len -= l + extra - sizeof(u32);
if (len == length) {
last = data;
break;
}
__raw_writel(data, piobuf);
piobuf++;
extra = 0;
data = 0;
} else {
data |= clear_upper_bytes(v, l,
extra);
if (len == length) {
last = data;
break;
}
extra += l;
}
} else if (len == length) {
last = data;
break;
}
} else if (len == length) {
u32 w;
w = (len + 3) >> 2;
__iowrite32_copy(piobuf, ss->sge.vaddr, w - 1);
piobuf += w - 1;
last = ((u32 *) ss->sge.vaddr)[w - 1];
break;
} else {
u32 w = len >> 2;
__iowrite32_copy(piobuf, ss->sge.vaddr, w);
piobuf += w;
extra = len & (sizeof(u32) - 1);
if (extra) {
u32 v = ((u32 *) ss->sge.vaddr)[w];
data = clear_upper_bytes(v, extra, 0);
}
}
update_sge(ss, len);
length -= len;
}
update_sge(ss, length);
if (flush_wc) {
ipath_flush_wc();
__raw_writel(last, piobuf);
ipath_flush_wc();
} else
__raw_writel(last, piobuf);
}
unsigned ipath_ib_rate_to_mult(enum ib_rate rate)
{
switch (rate) {
case IB_RATE_2_5_GBPS: return 8;
case IB_RATE_5_GBPS: return 4;
case IB_RATE_10_GBPS: return 2;
case IB_RATE_20_GBPS: return 1;
default: return 0;
}
}
static enum ib_rate ipath_mult_to_ib_rate(unsigned mult)
{
switch (mult) {
case 8: return IB_RATE_2_5_GBPS;
case 4: return IB_RATE_5_GBPS;
case 2: return IB_RATE_10_GBPS;
case 1: return IB_RATE_20_GBPS;
default: return IB_RATE_PORT_CURRENT;
}
}
static inline struct ipath_verbs_txreq *get_txreq(struct ipath_ibdev *dev)
{
struct ipath_verbs_txreq *tx = NULL;
unsigned long flags;
spin_lock_irqsave(&dev->pending_lock, flags);
if (!list_empty(&dev->txreq_free)) {
struct list_head *l = dev->txreq_free.next;
list_del(l);
tx = list_entry(l, struct ipath_verbs_txreq, txreq.list);
}
spin_unlock_irqrestore(&dev->pending_lock, flags);
return tx;
}
static inline void put_txreq(struct ipath_ibdev *dev,
struct ipath_verbs_txreq *tx)
{
unsigned long flags;
spin_lock_irqsave(&dev->pending_lock, flags);
list_add(&tx->txreq.list, &dev->txreq_free);
spin_unlock_irqrestore(&dev->pending_lock, flags);
}
static void sdma_complete(void *cookie, int status)
{
struct ipath_verbs_txreq *tx = cookie;
struct ipath_qp *qp = tx->qp;
struct ipath_ibdev *dev = to_idev(qp->ibqp.device);
unsigned long flags;
enum ib_wc_status ibs = status == IPATH_SDMA_TXREQ_S_OK ?
IB_WC_SUCCESS : IB_WC_WR_FLUSH_ERR;
if (atomic_dec_and_test(&qp->s_dma_busy)) {
spin_lock_irqsave(&qp->s_lock, flags);
if (tx->wqe)
ipath_send_complete(qp, tx->wqe, ibs);
if ((ib_ipath_state_ops[qp->state] & IPATH_FLUSH_SEND &&
qp->s_last != qp->s_head) ||
(qp->s_flags & IPATH_S_WAIT_DMA))
ipath_schedule_send(qp);
spin_unlock_irqrestore(&qp->s_lock, flags);
wake_up(&qp->wait_dma);
} else if (tx->wqe) {
spin_lock_irqsave(&qp->s_lock, flags);
ipath_send_complete(qp, tx->wqe, ibs);
spin_unlock_irqrestore(&qp->s_lock, flags);
}
if (tx->txreq.flags & IPATH_SDMA_TXREQ_F_FREEBUF)
kfree(tx->txreq.map_addr);
put_txreq(dev, tx);
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
}
static void decrement_dma_busy(struct ipath_qp *qp)
{
unsigned long flags;
if (atomic_dec_and_test(&qp->s_dma_busy)) {
spin_lock_irqsave(&qp->s_lock, flags);
if ((ib_ipath_state_ops[qp->state] & IPATH_FLUSH_SEND &&
qp->s_last != qp->s_head) ||
(qp->s_flags & IPATH_S_WAIT_DMA))
ipath_schedule_send(qp);
spin_unlock_irqrestore(&qp->s_lock, flags);
wake_up(&qp->wait_dma);
}
}
static inline unsigned ipath_pkt_delay(u32 plen, u8 snd_mult, u8 rcv_mult)
{
return (rcv_mult > snd_mult) ?
(plen * (rcv_mult - snd_mult) + 1) >> 1 : 0;
}
static int ipath_verbs_send_dma(struct ipath_qp *qp,
struct ipath_ib_header *hdr, u32 hdrwords,
struct ipath_sge_state *ss, u32 len,
u32 plen, u32 dwords)
{
struct ipath_ibdev *dev = to_idev(qp->ibqp.device);
struct ipath_devdata *dd = dev->dd;
struct ipath_verbs_txreq *tx;
u32 *piobuf;
u32 control;
u32 ndesc;
int ret;
tx = qp->s_tx;
if (tx) {
qp->s_tx = NULL;
atomic_inc(&qp->s_dma_busy);
ret = ipath_sdma_verbs_send(dd, tx->ss, tx->len, tx);
if (ret) {
qp->s_tx = tx;
decrement_dma_busy(qp);
}
goto bail;
}
tx = get_txreq(dev);
if (!tx) {
ret = -EBUSY;
goto bail;
}
control = qp->s_pkt_delay;
qp->s_pkt_delay = ipath_pkt_delay(plen, dd->delay_mult, qp->s_dmult);
tx->qp = qp;
atomic_inc(&qp->refcount);
tx->wqe = qp->s_wqe;
tx->txreq.callback = sdma_complete;
tx->txreq.callback_cookie = tx;
tx->txreq.flags = IPATH_SDMA_TXREQ_F_HEADTOHOST |
IPATH_SDMA_TXREQ_F_INTREQ | IPATH_SDMA_TXREQ_F_FREEDESC;
if (plen + 1 >= IPATH_SMALLBUF_DWORDS)
tx->txreq.flags |= IPATH_SDMA_TXREQ_F_USELARGEBUF;
if ((be16_to_cpu(hdr->lrh[0]) >> 12) == 15) {
control |= 1ULL << 31;
tx->txreq.flags |= IPATH_SDMA_TXREQ_F_VL15;
}
if (len) {
ndesc = ipath_count_sge(ss, len);
if (ndesc >= dd->ipath_sdma_descq_cnt)
ndesc = 0;
} else
ndesc = 1;
if (ndesc) {
tx->hdr.pbc[0] = cpu_to_le32(plen);
tx->hdr.pbc[1] = cpu_to_le32(control);
memcpy(&tx->hdr.hdr, hdr, hdrwords << 2);
tx->txreq.sg_count = ndesc;
tx->map_len = (hdrwords + 2) << 2;
tx->txreq.map_addr = &tx->hdr;
atomic_inc(&qp->s_dma_busy);
ret = ipath_sdma_verbs_send(dd, ss, dwords, tx);
if (ret) {
tx->ss = ss;
tx->len = dwords;
qp->s_tx = tx;
decrement_dma_busy(qp);
}
goto bail;
}
tx->map_len = (plen + 1) << 2;
piobuf = kmalloc(tx->map_len, GFP_ATOMIC);
if (unlikely(piobuf == NULL)) {
ret = -EBUSY;
goto err_tx;
}
tx->txreq.map_addr = piobuf;
tx->txreq.flags |= IPATH_SDMA_TXREQ_F_FREEBUF;
tx->txreq.sg_count = 1;
*piobuf++ = (__force u32) cpu_to_le32(plen);
*piobuf++ = (__force u32) cpu_to_le32(control);
memcpy(piobuf, hdr, hdrwords << 2);
ipath_copy_from_sge(piobuf + hdrwords, ss, len);
atomic_inc(&qp->s_dma_busy);
ret = ipath_sdma_verbs_send(dd, NULL, 0, tx);
if (ret) {
tx->ss = NULL;
tx->len = 0;
qp->s_tx = tx;
decrement_dma_busy(qp);
}
dev->n_unaligned++;
goto bail;
err_tx:
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
put_txreq(dev, tx);
bail:
return ret;
}
static int ipath_verbs_send_pio(struct ipath_qp *qp,
struct ipath_ib_header *ibhdr, u32 hdrwords,
struct ipath_sge_state *ss, u32 len,
u32 plen, u32 dwords)
{
struct ipath_devdata *dd = to_idev(qp->ibqp.device)->dd;
u32 *hdr = (u32 *) ibhdr;
u32 __iomem *piobuf;
unsigned flush_wc;
u32 control;
int ret;
unsigned long flags;
piobuf = ipath_getpiobuf(dd, plen, NULL);
if (unlikely(piobuf == NULL)) {
ret = -EBUSY;
goto bail;
}
control = qp->s_pkt_delay;
qp->s_pkt_delay = ipath_pkt_delay(plen, dd->delay_mult, qp->s_dmult);
if ((be16_to_cpu(ibhdr->lrh[0]) >> 12) == 15)
control |= 1ULL << 31;
writeq(((u64) control << 32) | plen, piobuf);
piobuf += 2;
flush_wc = dd->ipath_flags & IPATH_PIO_FLUSH_WC;
if (len == 0) {
if (flush_wc) {
ipath_flush_wc();
__iowrite32_copy(piobuf, hdr, hdrwords - 1);
ipath_flush_wc();
__raw_writel(hdr[hdrwords - 1], piobuf + hdrwords - 1);
ipath_flush_wc();
} else
__iowrite32_copy(piobuf, hdr, hdrwords);
goto done;
}
if (flush_wc)
ipath_flush_wc();
__iowrite32_copy(piobuf, hdr, hdrwords);
piobuf += hdrwords;
if (likely(ss->num_sge == 1 && len <= ss->sge.length &&
!((unsigned long)ss->sge.vaddr & (sizeof(u32) - 1)))) {
u32 *addr = (u32 *) ss->sge.vaddr;
update_sge(ss, len);
if (flush_wc) {
__iowrite32_copy(piobuf, addr, dwords - 1);
ipath_flush_wc();
__raw_writel(addr[dwords - 1], piobuf + dwords - 1);
ipath_flush_wc();
} else
__iowrite32_copy(piobuf, addr, dwords);
goto done;
}
copy_io(piobuf, ss, len, flush_wc);
done:
if (qp->s_wqe) {
spin_lock_irqsave(&qp->s_lock, flags);
ipath_send_complete(qp, qp->s_wqe, IB_WC_SUCCESS);
spin_unlock_irqrestore(&qp->s_lock, flags);
}
ret = 0;
bail:
return ret;
}
int ipath_verbs_send(struct ipath_qp *qp, struct ipath_ib_header *hdr,
u32 hdrwords, struct ipath_sge_state *ss, u32 len)
{
struct ipath_devdata *dd = to_idev(qp->ibqp.device)->dd;
u32 plen;
int ret;
u32 dwords = (len + 3) >> 2;
plen = hdrwords + dwords + 1;
if (qp->ibqp.qp_type == IB_QPT_SMI ||
!(dd->ipath_flags & IPATH_HAS_SEND_DMA))
ret = ipath_verbs_send_pio(qp, hdr, hdrwords, ss, len,
plen, dwords);
else
ret = ipath_verbs_send_dma(qp, hdr, hdrwords, ss, len,
plen, dwords);
return ret;
}
int ipath_snapshot_counters(struct ipath_devdata *dd, u64 *swords,
u64 *rwords, u64 *spkts, u64 *rpkts,
u64 *xmit_wait)
{
int ret;
if (!(dd->ipath_flags & IPATH_INITTED)) {
ret = -EINVAL;
goto bail;
}
*swords = ipath_snap_cntr(dd, dd->ipath_cregs->cr_wordsendcnt);
*rwords = ipath_snap_cntr(dd, dd->ipath_cregs->cr_wordrcvcnt);
*spkts = ipath_snap_cntr(dd, dd->ipath_cregs->cr_pktsendcnt);
*rpkts = ipath_snap_cntr(dd, dd->ipath_cregs->cr_pktrcvcnt);
*xmit_wait = ipath_snap_cntr(dd, dd->ipath_cregs->cr_sendstallcnt);
ret = 0;
bail:
return ret;
}
int ipath_get_counters(struct ipath_devdata *dd,
struct ipath_verbs_counters *cntrs)
{
struct ipath_cregs const *crp = dd->ipath_cregs;
int ret;
if (!(dd->ipath_flags & IPATH_INITTED)) {
ret = -EINVAL;
goto bail;
}
cntrs->symbol_error_counter =
ipath_snap_cntr(dd, crp->cr_ibsymbolerrcnt);
cntrs->link_error_recovery_counter =
ipath_snap_cntr(dd, crp->cr_iblinkerrrecovcnt);
cntrs->link_downed_counter =
ipath_snap_cntr(dd, crp->cr_iblinkdowncnt);
cntrs->port_rcv_errors =
ipath_snap_cntr(dd, crp->cr_rxdroppktcnt) +
ipath_snap_cntr(dd, crp->cr_rcvovflcnt) +
ipath_snap_cntr(dd, crp->cr_portovflcnt) +
ipath_snap_cntr(dd, crp->cr_err_rlencnt) +
ipath_snap_cntr(dd, crp->cr_invalidrlencnt) +
ipath_snap_cntr(dd, crp->cr_errlinkcnt) +
ipath_snap_cntr(dd, crp->cr_erricrccnt) +
ipath_snap_cntr(dd, crp->cr_errvcrccnt) +
ipath_snap_cntr(dd, crp->cr_errlpcrccnt) +
ipath_snap_cntr(dd, crp->cr_badformatcnt) +
dd->ipath_rxfc_unsupvl_errs;
if (crp->cr_rxotherlocalphyerrcnt)
cntrs->port_rcv_errors +=
ipath_snap_cntr(dd, crp->cr_rxotherlocalphyerrcnt);
if (crp->cr_rxvlerrcnt)
cntrs->port_rcv_errors +=
ipath_snap_cntr(dd, crp->cr_rxvlerrcnt);
cntrs->port_rcv_remphys_errors =
ipath_snap_cntr(dd, crp->cr_rcvebpcnt);
cntrs->port_xmit_discards = ipath_snap_cntr(dd, crp->cr_unsupvlcnt);
cntrs->port_xmit_data = ipath_snap_cntr(dd, crp->cr_wordsendcnt);
cntrs->port_rcv_data = ipath_snap_cntr(dd, crp->cr_wordrcvcnt);
cntrs->port_xmit_packets = ipath_snap_cntr(dd, crp->cr_pktsendcnt);
cntrs->port_rcv_packets = ipath_snap_cntr(dd, crp->cr_pktrcvcnt);
cntrs->local_link_integrity_errors =
crp->cr_locallinkintegrityerrcnt ?
ipath_snap_cntr(dd, crp->cr_locallinkintegrityerrcnt) :
((dd->ipath_flags & IPATH_GPIO_ERRINTRS) ?
dd->ipath_lli_errs : dd->ipath_lli_errors);
cntrs->excessive_buffer_overrun_errors =
crp->cr_excessbufferovflcnt ?
ipath_snap_cntr(dd, crp->cr_excessbufferovflcnt) :
dd->ipath_overrun_thresh_errs;
cntrs->vl15_dropped = crp->cr_vl15droppedpktcnt ?
ipath_snap_cntr(dd, crp->cr_vl15droppedpktcnt) : 0;
ret = 0;
bail:
return ret;
}
int ipath_ib_piobufavail(struct ipath_ibdev *dev)
{
struct list_head *list;
struct ipath_qp *qplist;
struct ipath_qp *qp;
unsigned long flags;
if (dev == NULL)
goto bail;
list = &dev->piowait;
qplist = NULL;
spin_lock_irqsave(&dev->pending_lock, flags);
while (!list_empty(list)) {
qp = list_entry(list->next, struct ipath_qp, piowait);
list_del_init(&qp->piowait);
qp->pio_next = qplist;
qplist = qp;
atomic_inc(&qp->refcount);
}
spin_unlock_irqrestore(&dev->pending_lock, flags);
while (qplist != NULL) {
qp = qplist;
qplist = qp->pio_next;
spin_lock_irqsave(&qp->s_lock, flags);
if (ib_ipath_state_ops[qp->state] & IPATH_PROCESS_SEND_OK)
ipath_schedule_send(qp);
spin_unlock_irqrestore(&qp->s_lock, flags);
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
}
bail:
return 0;
}
static int ipath_query_device(struct ib_device *ibdev,
struct ib_device_attr *props)
{
struct ipath_ibdev *dev = to_idev(ibdev);
memset(props, 0, sizeof(*props));
props->device_cap_flags = IB_DEVICE_BAD_PKEY_CNTR |
IB_DEVICE_BAD_QKEY_CNTR | IB_DEVICE_SHUTDOWN_PORT |
IB_DEVICE_SYS_IMAGE_GUID | IB_DEVICE_RC_RNR_NAK_GEN |
IB_DEVICE_PORT_ACTIVE_EVENT | IB_DEVICE_SRQ_RESIZE;
props->page_size_cap = PAGE_SIZE;
props->vendor_id =
IPATH_SRC_OUI_1 << 16 | IPATH_SRC_OUI_2 << 8 | IPATH_SRC_OUI_3;
props->vendor_part_id = dev->dd->ipath_deviceid;
props->hw_ver = dev->dd->ipath_pcirev;
props->sys_image_guid = dev->sys_image_guid;
props->max_mr_size = ~0ull;
props->max_qp = ib_ipath_max_qps;
props->max_qp_wr = ib_ipath_max_qp_wrs;
props->max_sge = ib_ipath_max_sges;
props->max_cq = ib_ipath_max_cqs;
props->max_ah = ib_ipath_max_ahs;
props->max_cqe = ib_ipath_max_cqes;
props->max_mr = dev->lk_table.max;
props->max_fmr = dev->lk_table.max;
props->max_map_per_fmr = 32767;
props->max_pd = ib_ipath_max_pds;
props->max_qp_rd_atom = IPATH_MAX_RDMA_ATOMIC;
props->max_qp_init_rd_atom = 255;
props->max_srq = ib_ipath_max_srqs;
props->max_srq_wr = ib_ipath_max_srq_wrs;
props->max_srq_sge = ib_ipath_max_srq_sges;
props->atomic_cap = IB_ATOMIC_GLOB;
props->max_pkeys = ipath_get_npkeys(dev->dd);
props->max_mcast_grp = ib_ipath_max_mcast_grps;
props->max_mcast_qp_attach = ib_ipath_max_mcast_qp_attached;
props->max_total_mcast_qp_attach = props->max_mcast_qp_attach *
props->max_mcast_grp;
return 0;
}
u32 ipath_get_cr_errpkey(struct ipath_devdata *dd)
{
return ipath_read_creg32(dd, dd->ipath_cregs->cr_errpkey);
}
static int ipath_query_port(struct ib_device *ibdev,
u8 port, struct ib_port_attr *props)
{
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_devdata *dd = dev->dd;
enum ib_mtu mtu;
u16 lid = dd->ipath_lid;
u64 ibcstat;
memset(props, 0, sizeof(*props));
props->lid = lid ? lid : be16_to_cpu(IB_LID_PERMISSIVE);
props->lmc = dd->ipath_lmc;
props->sm_lid = dev->sm_lid;
props->sm_sl = dev->sm_sl;
ibcstat = dd->ipath_lastibcstat;
props->state = ipath_ib_linkstate(dd, ibcstat) + 1;
props->phys_state =
ipath_cvt_physportstate[dd->ipath_lastibcstat &
dd->ibcs_lts_mask];
props->port_cap_flags = dev->port_cap_flags;
props->gid_tbl_len = 1;
props->max_msg_sz = 0x80000000;
props->pkey_tbl_len = ipath_get_npkeys(dd);
props->bad_pkey_cntr = ipath_get_cr_errpkey(dd) -
dev->z_pkey_violations;
props->qkey_viol_cntr = dev->qkey_violations;
props->active_width = dd->ipath_link_width_active;
props->active_speed = dd->ipath_link_speed_active;
props->max_vl_num = 1;
props->init_type_reply = 0;
props->max_mtu = ipath_mtu4096 ? IB_MTU_4096 : IB_MTU_2048;
switch (dd->ipath_ibmtu) {
case 4096:
mtu = IB_MTU_4096;
break;
case 2048:
mtu = IB_MTU_2048;
break;
case 1024:
mtu = IB_MTU_1024;
break;
case 512:
mtu = IB_MTU_512;
break;
case 256:
mtu = IB_MTU_256;
break;
default:
mtu = IB_MTU_2048;
}
props->active_mtu = mtu;
props->subnet_timeout = dev->subnet_timeout;
return 0;
}
static int ipath_modify_device(struct ib_device *device,
int device_modify_mask,
struct ib_device_modify *device_modify)
{
int ret;
if (device_modify_mask & ~(IB_DEVICE_MODIFY_SYS_IMAGE_GUID |
IB_DEVICE_MODIFY_NODE_DESC)) {
ret = -EOPNOTSUPP;
goto bail;
}
if (device_modify_mask & IB_DEVICE_MODIFY_NODE_DESC)
memcpy(device->node_desc, device_modify->node_desc, 64);
if (device_modify_mask & IB_DEVICE_MODIFY_SYS_IMAGE_GUID)
to_idev(device)->sys_image_guid =
cpu_to_be64(device_modify->sys_image_guid);
ret = 0;
bail:
return ret;
}
static int ipath_modify_port(struct ib_device *ibdev,
u8 port, int port_modify_mask,
struct ib_port_modify *props)
{
struct ipath_ibdev *dev = to_idev(ibdev);
dev->port_cap_flags |= props->set_port_cap_mask;
dev->port_cap_flags &= ~props->clr_port_cap_mask;
if (port_modify_mask & IB_PORT_SHUTDOWN)
ipath_set_linkstate(dev->dd, IPATH_IB_LINKDOWN);
if (port_modify_mask & IB_PORT_RESET_QKEY_CNTR)
dev->qkey_violations = 0;
return 0;
}
static int ipath_query_gid(struct ib_device *ibdev, u8 port,
int index, union ib_gid *gid)
{
struct ipath_ibdev *dev = to_idev(ibdev);
int ret;
if (index >= 1) {
ret = -EINVAL;
goto bail;
}
gid->global.subnet_prefix = dev->gid_prefix;
gid->global.interface_id = dev->dd->ipath_guid;
ret = 0;
bail:
return ret;
}
static struct ib_pd *ipath_alloc_pd(struct ib_device *ibdev,
struct ib_ucontext *context,
struct ib_udata *udata)
{
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_pd *pd;
struct ib_pd *ret;
pd = kmalloc(sizeof *pd, GFP_KERNEL);
if (!pd) {
ret = ERR_PTR(-ENOMEM);
goto bail;
}
spin_lock(&dev->n_pds_lock);
if (dev->n_pds_allocated == ib_ipath_max_pds) {
spin_unlock(&dev->n_pds_lock);
kfree(pd);
ret = ERR_PTR(-ENOMEM);
goto bail;
}
dev->n_pds_allocated++;
spin_unlock(&dev->n_pds_lock);
pd->user = udata != NULL;
ret = &pd->ibpd;
bail:
return ret;
}
static int ipath_dealloc_pd(struct ib_pd *ibpd)
{
struct ipath_pd *pd = to_ipd(ibpd);
struct ipath_ibdev *dev = to_idev(ibpd->device);
spin_lock(&dev->n_pds_lock);
dev->n_pds_allocated--;
spin_unlock(&dev->n_pds_lock);
kfree(pd);
return 0;
}
static struct ib_ah *ipath_create_ah(struct ib_pd *pd,
struct ib_ah_attr *ah_attr)
{
struct ipath_ah *ah;
struct ib_ah *ret;
struct ipath_ibdev *dev = to_idev(pd->device);
unsigned long flags;
if (ah_attr->dlid >= IPATH_MULTICAST_LID_BASE &&
ah_attr->dlid != IPATH_PERMISSIVE_LID &&
!(ah_attr->ah_flags & IB_AH_GRH)) {
ret = ERR_PTR(-EINVAL);
goto bail;
}
if (ah_attr->dlid == 0) {
ret = ERR_PTR(-EINVAL);
goto bail;
}
if (ah_attr->port_num < 1 ||
ah_attr->port_num > pd->device->phys_port_cnt) {
ret = ERR_PTR(-EINVAL);
goto bail;
}
ah = kmalloc(sizeof *ah, GFP_ATOMIC);
if (!ah) {
ret = ERR_PTR(-ENOMEM);
goto bail;
}
spin_lock_irqsave(&dev->n_ahs_lock, flags);
if (dev->n_ahs_allocated == ib_ipath_max_ahs) {
spin_unlock_irqrestore(&dev->n_ahs_lock, flags);
kfree(ah);
ret = ERR_PTR(-ENOMEM);
goto bail;
}
dev->n_ahs_allocated++;
spin_unlock_irqrestore(&dev->n_ahs_lock, flags);
ah->attr = *ah_attr;
ah->attr.static_rate = ipath_ib_rate_to_mult(ah_attr->static_rate);
ret = &ah->ibah;
bail:
return ret;
}
static int ipath_destroy_ah(struct ib_ah *ibah)
{
struct ipath_ibdev *dev = to_idev(ibah->device);
struct ipath_ah *ah = to_iah(ibah);
unsigned long flags;
spin_lock_irqsave(&dev->n_ahs_lock, flags);
dev->n_ahs_allocated--;
spin_unlock_irqrestore(&dev->n_ahs_lock, flags);
kfree(ah);
return 0;
}
static int ipath_query_ah(struct ib_ah *ibah, struct ib_ah_attr *ah_attr)
{
struct ipath_ah *ah = to_iah(ibah);
*ah_attr = ah->attr;
ah_attr->static_rate = ipath_mult_to_ib_rate(ah->attr.static_rate);
return 0;
}
unsigned ipath_get_npkeys(struct ipath_devdata *dd)
{
return ARRAY_SIZE(dd->ipath_pd[0]->port_pkeys);
}
unsigned ipath_get_pkey(struct ipath_devdata *dd, unsigned index)
{
unsigned ret;
if (index >= ARRAY_SIZE(dd->ipath_pd[0]->port_pkeys))
ret = 0;
else
ret = dd->ipath_pd[0]->port_pkeys[index];
return ret;
}
static int ipath_query_pkey(struct ib_device *ibdev, u8 port, u16 index,
u16 *pkey)
{
struct ipath_ibdev *dev = to_idev(ibdev);
int ret;
if (index >= ipath_get_npkeys(dev->dd)) {
ret = -EINVAL;
goto bail;
}
*pkey = ipath_get_pkey(dev->dd, index);
ret = 0;
bail:
return ret;
}
static struct ib_ucontext *ipath_alloc_ucontext(struct ib_device *ibdev,
struct ib_udata *udata)
{
struct ipath_ucontext *context;
struct ib_ucontext *ret;
context = kmalloc(sizeof *context, GFP_KERNEL);
if (!context) {
ret = ERR_PTR(-ENOMEM);
goto bail;
}
ret = &context->ibucontext;
bail:
return ret;
}
static int ipath_dealloc_ucontext(struct ib_ucontext *context)
{
kfree(to_iucontext(context));
return 0;
}
static void __verbs_timer(unsigned long arg)
{
struct ipath_devdata *dd = (struct ipath_devdata *) arg;
ipath_ib_timer(dd->verbs_dev);
mod_timer(&dd->verbs_timer, jiffies + 1);
}
static int enable_timer(struct ipath_devdata *dd)
{
if (dd->ipath_flags & IPATH_GPIO_INTR) {
ipath_write_kreg(dd, dd->ipath_kregs->kr_debugportselect,
0x2074076542310ULL);
dd->ipath_gpio_mask |= (u64) (1 << IPATH_GPIO_PORT0_BIT);
ipath_write_kreg(dd, dd->ipath_kregs->kr_gpio_mask,
dd->ipath_gpio_mask);
}
init_timer(&dd->verbs_timer);
dd->verbs_timer.function = __verbs_timer;
dd->verbs_timer.data = (unsigned long)dd;
dd->verbs_timer.expires = jiffies + 1;
add_timer(&dd->verbs_timer);
return 0;
}
static int disable_timer(struct ipath_devdata *dd)
{
if (dd->ipath_flags & IPATH_GPIO_INTR) {
dd->ipath_gpio_mask &= ~((u64) (1 << IPATH_GPIO_PORT0_BIT));
ipath_write_kreg(dd, dd->ipath_kregs->kr_gpio_mask,
dd->ipath_gpio_mask);
}
del_timer_sync(&dd->verbs_timer);
return 0;
}
int ipath_register_ib_device(struct ipath_devdata *dd)
{
struct ipath_verbs_counters cntrs;
struct ipath_ibdev *idev;
struct ib_device *dev;
struct ipath_verbs_txreq *tx;
unsigned i;
int ret;
idev = (struct ipath_ibdev *)ib_alloc_device(sizeof *idev);
if (idev == NULL) {
ret = -ENOMEM;
goto bail;
}
dev = &idev->ibdev;
if (dd->ipath_sdma_descq_cnt) {
tx = kmalloc(dd->ipath_sdma_descq_cnt * sizeof *tx,
GFP_KERNEL);
if (tx == NULL) {
ret = -ENOMEM;
goto err_tx;
}
} else
tx = NULL;
idev->txreq_bufs = tx;
spin_lock_init(&idev->n_pds_lock);
spin_lock_init(&idev->n_ahs_lock);
spin_lock_init(&idev->n_cqs_lock);
spin_lock_init(&idev->n_qps_lock);
spin_lock_init(&idev->n_srqs_lock);
spin_lock_init(&idev->n_mcast_grps_lock);
spin_lock_init(&idev->qp_table.lock);
spin_lock_init(&idev->lk_table.lock);
idev->sm_lid = __constant_be16_to_cpu(IB_LID_PERMISSIVE);
idev->gid_prefix = __constant_cpu_to_be64(0xfe80000000000000ULL);
ret = ipath_init_qp_table(idev, ib_ipath_qp_table_size);
if (ret)
goto err_qp;
idev->lk_table.max = 1 << ib_ipath_lkey_table_size;
idev->lk_table.table = kzalloc(idev->lk_table.max *
sizeof(*idev->lk_table.table),
GFP_KERNEL);
if (idev->lk_table.table == NULL) {
ret = -ENOMEM;
goto err_lk;
}
INIT_LIST_HEAD(&idev->pending_mmaps);
spin_lock_init(&idev->pending_lock);
idev->mmap_offset = PAGE_SIZE;
spin_lock_init(&idev->mmap_offset_lock);
INIT_LIST_HEAD(&idev->pending[0]);
INIT_LIST_HEAD(&idev->pending[1]);
INIT_LIST_HEAD(&idev->pending[2]);
INIT_LIST_HEAD(&idev->piowait);
INIT_LIST_HEAD(&idev->rnrwait);
INIT_LIST_HEAD(&idev->txreq_free);
idev->pending_index = 0;
idev->port_cap_flags =
IB_PORT_SYS_IMAGE_GUID_SUP | IB_PORT_CLIENT_REG_SUP;
if (dd->ipath_flags & IPATH_HAS_LINK_LATENCY)
idev->port_cap_flags |= IB_PORT_LINK_LATENCY_SUP;
idev->pma_counter_select[0] = IB_PMA_PORT_XMIT_DATA;
idev->pma_counter_select[1] = IB_PMA_PORT_RCV_DATA;
idev->pma_counter_select[2] = IB_PMA_PORT_XMIT_PKTS;
idev->pma_counter_select[3] = IB_PMA_PORT_RCV_PKTS;
idev->pma_counter_select[4] = IB_PMA_PORT_XMIT_WAIT;
ipath_get_counters(dd, &cntrs);
idev->z_symbol_error_counter = cntrs.symbol_error_counter;
idev->z_link_error_recovery_counter =
cntrs.link_error_recovery_counter;
idev->z_link_downed_counter = cntrs.link_downed_counter;
idev->z_port_rcv_errors = cntrs.port_rcv_errors;
idev->z_port_rcv_remphys_errors =
cntrs.port_rcv_remphys_errors;
idev->z_port_xmit_discards = cntrs.port_xmit_discards;
idev->z_port_xmit_data = cntrs.port_xmit_data;
idev->z_port_rcv_data = cntrs.port_rcv_data;
idev->z_port_xmit_packets = cntrs.port_xmit_packets;
idev->z_port_rcv_packets = cntrs.port_rcv_packets;
idev->z_local_link_integrity_errors =
cntrs.local_link_integrity_errors;
idev->z_excessive_buffer_overrun_errors =
cntrs.excessive_buffer_overrun_errors;
idev->z_vl15_dropped = cntrs.vl15_dropped;
for (i = 0; i < dd->ipath_sdma_descq_cnt; i++, tx++)
list_add(&tx->txreq.list, &idev->txreq_free);
if (!sys_image_guid)
sys_image_guid = dd->ipath_guid;
idev->sys_image_guid = sys_image_guid;
idev->ib_unit = dd->ipath_unit;
idev->dd = dd;
strlcpy(dev->name, "ipath%d", IB_DEVICE_NAME_MAX);
dev->owner = THIS_MODULE;
dev->node_guid = dd->ipath_guid;
dev->uverbs_abi_ver = IPATH_UVERBS_ABI_VERSION;
dev->uverbs_cmd_mask =
(1ull << IB_USER_VERBS_CMD_GET_CONTEXT) |
(1ull << IB_USER_VERBS_CMD_QUERY_DEVICE) |
(1ull << IB_USER_VERBS_CMD_QUERY_PORT) |
(1ull << IB_USER_VERBS_CMD_ALLOC_PD) |
(1ull << IB_USER_VERBS_CMD_DEALLOC_PD) |
(1ull << IB_USER_VERBS_CMD_CREATE_AH) |
(1ull << IB_USER_VERBS_CMD_DESTROY_AH) |
(1ull << IB_USER_VERBS_CMD_QUERY_AH) |
(1ull << IB_USER_VERBS_CMD_REG_MR) |
(1ull << IB_USER_VERBS_CMD_DEREG_MR) |
(1ull << IB_USER_VERBS_CMD_CREATE_COMP_CHANNEL) |
(1ull << IB_USER_VERBS_CMD_CREATE_CQ) |
(1ull << IB_USER_VERBS_CMD_RESIZE_CQ) |
(1ull << IB_USER_VERBS_CMD_DESTROY_CQ) |
(1ull << IB_USER_VERBS_CMD_POLL_CQ) |
(1ull << IB_USER_VERBS_CMD_REQ_NOTIFY_CQ) |
(1ull << IB_USER_VERBS_CMD_CREATE_QP) |
(1ull << IB_USER_VERBS_CMD_QUERY_QP) |
(1ull << IB_USER_VERBS_CMD_MODIFY_QP) |
(1ull << IB_USER_VERBS_CMD_DESTROY_QP) |
(1ull << IB_USER_VERBS_CMD_POST_SEND) |
(1ull << IB_USER_VERBS_CMD_POST_RECV) |
(1ull << IB_USER_VERBS_CMD_ATTACH_MCAST) |
(1ull << IB_USER_VERBS_CMD_DETACH_MCAST) |
(1ull << IB_USER_VERBS_CMD_CREATE_SRQ) |
(1ull << IB_USER_VERBS_CMD_MODIFY_SRQ) |
(1ull << IB_USER_VERBS_CMD_QUERY_SRQ) |
(1ull << IB_USER_VERBS_CMD_DESTROY_SRQ) |
(1ull << IB_USER_VERBS_CMD_POST_SRQ_RECV);
dev->node_type = RDMA_NODE_IB_CA;
dev->phys_port_cnt = 1;
dev->num_comp_vectors = 1;
dev->dma_device = &dd->pcidev->dev;
dev->query_device = ipath_query_device;
dev->modify_device = ipath_modify_device;
dev->query_port = ipath_query_port;
dev->modify_port = ipath_modify_port;
dev->query_pkey = ipath_query_pkey;
dev->query_gid = ipath_query_gid;
dev->alloc_ucontext = ipath_alloc_ucontext;
dev->dealloc_ucontext = ipath_dealloc_ucontext;
dev->alloc_pd = ipath_alloc_pd;
dev->dealloc_pd = ipath_dealloc_pd;
dev->create_ah = ipath_create_ah;
dev->destroy_ah = ipath_destroy_ah;
dev->query_ah = ipath_query_ah;
dev->create_srq = ipath_create_srq;
dev->modify_srq = ipath_modify_srq;
dev->query_srq = ipath_query_srq;
dev->destroy_srq = ipath_destroy_srq;
dev->create_qp = ipath_create_qp;
dev->modify_qp = ipath_modify_qp;
dev->query_qp = ipath_query_qp;
dev->destroy_qp = ipath_destroy_qp;
dev->post_send = ipath_post_send;
dev->post_recv = ipath_post_receive;
dev->post_srq_recv = ipath_post_srq_receive;
dev->create_cq = ipath_create_cq;
dev->destroy_cq = ipath_destroy_cq;
dev->resize_cq = ipath_resize_cq;
dev->poll_cq = ipath_poll_cq;
dev->req_notify_cq = ipath_req_notify_cq;
dev->get_dma_mr = ipath_get_dma_mr;
dev->reg_phys_mr = ipath_reg_phys_mr;
dev->reg_user_mr = ipath_reg_user_mr;
dev->dereg_mr = ipath_dereg_mr;
dev->alloc_fmr = ipath_alloc_fmr;
dev->map_phys_fmr = ipath_map_phys_fmr;
dev->unmap_fmr = ipath_unmap_fmr;
dev->dealloc_fmr = ipath_dealloc_fmr;
dev->attach_mcast = ipath_multicast_attach;
dev->detach_mcast = ipath_multicast_detach;
dev->process_mad = ipath_process_mad;
dev->mmap = ipath_mmap;
dev->dma_ops = &ipath_dma_mapping_ops;
snprintf(dev->node_desc, sizeof(dev->node_desc),
IPATH_IDSTR " %s", init_utsname()->nodename);
ret = ib_register_device(dev, NULL);
if (ret)
goto err_reg;
if (ipath_verbs_register_sysfs(dev))
goto err_class;
enable_timer(dd);
goto bail;
err_class:
ib_unregister_device(dev);
err_reg:
kfree(idev->lk_table.table);
err_lk:
kfree(idev->qp_table.table);
err_qp:
kfree(idev->txreq_bufs);
err_tx:
ib_dealloc_device(dev);
ipath_dev_err(dd, "cannot register verbs: %d!\n", -ret);
idev = NULL;
bail:
dd->verbs_dev = idev;
return ret;
}
void ipath_unregister_ib_device(struct ipath_ibdev *dev)
{
struct ib_device *ibdev = &dev->ibdev;
u32 qps_inuse;
ib_unregister_device(ibdev);
disable_timer(dev->dd);
if (!list_empty(&dev->pending[0]) ||
!list_empty(&dev->pending[1]) ||
!list_empty(&dev->pending[2]))
ipath_dev_err(dev->dd, "pending list not empty!\n");
if (!list_empty(&dev->piowait))
ipath_dev_err(dev->dd, "piowait list not empty!\n");
if (!list_empty(&dev->rnrwait))
ipath_dev_err(dev->dd, "rnrwait list not empty!\n");
if (!ipath_mcast_tree_empty())
ipath_dev_err(dev->dd, "multicast table memory leak!\n");
qps_inuse = ipath_free_all_qps(&dev->qp_table);
if (qps_inuse)
ipath_dev_err(dev->dd, "QP memory leak! %u still in use\n",
qps_inuse);
kfree(dev->qp_table.table);
kfree(dev->lk_table.table);
kfree(dev->txreq_bufs);
ib_dealloc_device(ibdev);
}
static ssize_t show_rev(struct device *device, struct device_attribute *attr,
char *buf)
{
struct ipath_ibdev *dev =
container_of(device, struct ipath_ibdev, ibdev.dev);
return sprintf(buf, "%x\n", dev->dd->ipath_pcirev);
}
static ssize_t show_hca(struct device *device, struct device_attribute *attr,
char *buf)
{
struct ipath_ibdev *dev =
container_of(device, struct ipath_ibdev, ibdev.dev);
int ret;
ret = dev->dd->ipath_f_get_boardname(dev->dd, buf, 128);
if (ret < 0)
goto bail;
strcat(buf, "\n");
ret = strlen(buf);
bail:
return ret;
}
static ssize_t show_stats(struct device *device, struct device_attribute *attr,
char *buf)
{
struct ipath_ibdev *dev =
container_of(device, struct ipath_ibdev, ibdev.dev);
int i;
int len;
len = sprintf(buf,
"RC resends %d\n"
"RC no QACK %d\n"
"RC ACKs %d\n"
"RC SEQ NAKs %d\n"
"RC RDMA seq %d\n"
"RC RNR NAKs %d\n"
"RC OTH NAKs %d\n"
"RC timeouts %d\n"
"RC RDMA dup %d\n"
"piobuf wait %d\n"
"unaligned %d\n"
"PKT drops %d\n"
"WQE errs %d\n",
dev->n_rc_resends, dev->n_rc_qacks, dev->n_rc_acks,
dev->n_seq_naks, dev->n_rdma_seq, dev->n_rnr_naks,
dev->n_other_naks, dev->n_timeouts,
dev->n_rdma_dup_busy, dev->n_piowait, dev->n_unaligned,
dev->n_pkt_drops, dev->n_wqe_errs);
for (i = 0; i < ARRAY_SIZE(dev->opstats); i++) {
const struct ipath_opcode_stats *si = &dev->opstats[i];
if (!si->n_packets && !si->n_bytes)
continue;
len += sprintf(buf + len, "%02x %llu/%llu\n", i,
(unsigned long long) si->n_packets,
(unsigned long long) si->n_bytes);
}
return len;
}
static int ipath_verbs_register_sysfs(struct ib_device *dev)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(ipath_class_attributes); ++i)
if (device_create_file(&dev->dev,
ipath_class_attributes[i])) {
ret = 1;
goto bail;
}
ret = 0;
bail:
return ret;
}
