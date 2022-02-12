int qib_alloc_lkey(struct qib_mregion *mr, int dma_region)
{
unsigned long flags;
u32 r;
u32 n;
int ret = 0;
struct qib_ibdev *dev = to_idev(mr->pd->device);
struct qib_lkey_table *rkt = &dev->lk_table;
spin_lock_irqsave(&rkt->lock, flags);
if (dma_region) {
struct qib_mregion *tmr;
tmr = rcu_access_pointer(dev->dma_mr);
if (!tmr) {
qib_get_mr(mr);
rcu_assign_pointer(dev->dma_mr, mr);
mr->lkey_published = 1;
}
goto success;
}
r = rkt->next;
n = r;
for (;;) {
if (rkt->table[r] == NULL)
break;
r = (r + 1) & (rkt->max - 1);
if (r == n)
goto bail;
}
rkt->next = (r + 1) & (rkt->max - 1);
rkt->gen++;
mr->lkey = (r << (32 - ib_qib_lkey_table_size)) |
((((1 << (24 - ib_qib_lkey_table_size)) - 1) & rkt->gen)
<< 8);
if (mr->lkey == 0) {
mr->lkey |= 1 << 8;
rkt->gen++;
}
qib_get_mr(mr);
rcu_assign_pointer(rkt->table[r], mr);
mr->lkey_published = 1;
success:
spin_unlock_irqrestore(&rkt->lock, flags);
out:
return ret;
bail:
spin_unlock_irqrestore(&rkt->lock, flags);
ret = -ENOMEM;
goto out;
}
void qib_free_lkey(struct qib_mregion *mr)
{
unsigned long flags;
u32 lkey = mr->lkey;
u32 r;
struct qib_ibdev *dev = to_idev(mr->pd->device);
struct qib_lkey_table *rkt = &dev->lk_table;
spin_lock_irqsave(&rkt->lock, flags);
if (!mr->lkey_published)
goto out;
if (lkey == 0)
RCU_INIT_POINTER(dev->dma_mr, NULL);
else {
r = lkey >> (32 - ib_qib_lkey_table_size);
RCU_INIT_POINTER(rkt->table[r], NULL);
}
qib_put_mr(mr);
mr->lkey_published = 0;
out:
spin_unlock_irqrestore(&rkt->lock, flags);
}
int qib_lkey_ok(struct qib_lkey_table *rkt, struct qib_pd *pd,
struct qib_sge *isge, struct ib_sge *sge, int acc)
{
struct qib_mregion *mr;
unsigned n, m;
size_t off;
rcu_read_lock();
if (sge->lkey == 0) {
struct qib_ibdev *dev = to_idev(pd->ibpd.device);
if (pd->user)
goto bail;
mr = rcu_dereference(dev->dma_mr);
if (!mr)
goto bail;
if (unlikely(!atomic_inc_not_zero(&mr->refcount)))
goto bail;
rcu_read_unlock();
isge->mr = mr;
isge->vaddr = (void *) sge->addr;
isge->length = sge->length;
isge->sge_length = sge->length;
isge->m = 0;
isge->n = 0;
goto ok;
}
mr = rcu_dereference(
rkt->table[(sge->lkey >> (32 - ib_qib_lkey_table_size))]);
if (unlikely(!mr || mr->lkey != sge->lkey || mr->pd != &pd->ibpd))
goto bail;
off = sge->addr - mr->user_base;
if (unlikely(sge->addr < mr->user_base ||
off + sge->length > mr->length ||
(mr->access_flags & acc) != acc))
goto bail;
if (unlikely(!atomic_inc_not_zero(&mr->refcount)))
goto bail;
rcu_read_unlock();
off += mr->offset;
if (mr->page_shift) {
size_t entries_spanned_by_off;
entries_spanned_by_off = off >> mr->page_shift;
off -= (entries_spanned_by_off << mr->page_shift);
m = entries_spanned_by_off/QIB_SEGSZ;
n = entries_spanned_by_off%QIB_SEGSZ;
} else {
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= QIB_SEGSZ) {
m++;
n = 0;
}
}
}
isge->mr = mr;
isge->vaddr = mr->map[m]->segs[n].vaddr + off;
isge->length = mr->map[m]->segs[n].length - off;
isge->sge_length = sge->length;
isge->m = m;
isge->n = n;
ok:
return 1;
bail:
rcu_read_unlock();
return 0;
}
int qib_rkey_ok(struct qib_qp *qp, struct qib_sge *sge,
u32 len, u64 vaddr, u32 rkey, int acc)
{
struct qib_lkey_table *rkt = &to_idev(qp->ibqp.device)->lk_table;
struct qib_mregion *mr;
unsigned n, m;
size_t off;
rcu_read_lock();
if (rkey == 0) {
struct qib_pd *pd = to_ipd(qp->ibqp.pd);
struct qib_ibdev *dev = to_idev(pd->ibpd.device);
if (pd->user)
goto bail;
mr = rcu_dereference(dev->dma_mr);
if (!mr)
goto bail;
if (unlikely(!atomic_inc_not_zero(&mr->refcount)))
goto bail;
rcu_read_unlock();
sge->mr = mr;
sge->vaddr = (void *) vaddr;
sge->length = len;
sge->sge_length = len;
sge->m = 0;
sge->n = 0;
goto ok;
}
mr = rcu_dereference(
rkt->table[(rkey >> (32 - ib_qib_lkey_table_size))]);
if (unlikely(!mr || mr->lkey != rkey || qp->ibqp.pd != mr->pd))
goto bail;
off = vaddr - mr->iova;
if (unlikely(vaddr < mr->iova || off + len > mr->length ||
(mr->access_flags & acc) == 0))
goto bail;
if (unlikely(!atomic_inc_not_zero(&mr->refcount)))
goto bail;
rcu_read_unlock();
off += mr->offset;
if (mr->page_shift) {
size_t entries_spanned_by_off;
entries_spanned_by_off = off >> mr->page_shift;
off -= (entries_spanned_by_off << mr->page_shift);
m = entries_spanned_by_off/QIB_SEGSZ;
n = entries_spanned_by_off%QIB_SEGSZ;
} else {
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= QIB_SEGSZ) {
m++;
n = 0;
}
}
}
sge->mr = mr;
sge->vaddr = mr->map[m]->segs[n].vaddr + off;
sge->length = mr->map[m]->segs[n].length - off;
sge->sge_length = len;
sge->m = m;
sge->n = n;
ok:
return 1;
bail:
rcu_read_unlock();
return 0;
}
int qib_fast_reg_mr(struct qib_qp *qp, struct ib_send_wr *wr)
{
struct qib_lkey_table *rkt = &to_idev(qp->ibqp.device)->lk_table;
struct qib_pd *pd = to_ipd(qp->ibqp.pd);
struct qib_mregion *mr;
u32 rkey = wr->wr.fast_reg.rkey;
unsigned i, n, m;
int ret = -EINVAL;
unsigned long flags;
u64 *page_list;
size_t ps;
spin_lock_irqsave(&rkt->lock, flags);
if (pd->user || rkey == 0)
goto bail;
mr = rcu_dereference_protected(
rkt->table[(rkey >> (32 - ib_qib_lkey_table_size))],
lockdep_is_held(&rkt->lock));
if (unlikely(mr == NULL || qp->ibqp.pd != mr->pd))
goto bail;
if (wr->wr.fast_reg.page_list_len > mr->max_segs)
goto bail;
ps = 1UL << wr->wr.fast_reg.page_shift;
if (wr->wr.fast_reg.length > ps * wr->wr.fast_reg.page_list_len)
goto bail;
mr->user_base = wr->wr.fast_reg.iova_start;
mr->iova = wr->wr.fast_reg.iova_start;
mr->lkey = rkey;
mr->length = wr->wr.fast_reg.length;
mr->access_flags = wr->wr.fast_reg.access_flags;
page_list = wr->wr.fast_reg.page_list->page_list;
m = 0;
n = 0;
for (i = 0; i < wr->wr.fast_reg.page_list_len; i++) {
mr->map[m]->segs[n].vaddr = (void *) page_list[i];
mr->map[m]->segs[n].length = ps;
if (++n == QIB_SEGSZ) {
m++;
n = 0;
}
}
ret = 0;
bail:
spin_unlock_irqrestore(&rkt->lock, flags);
return ret;
}
