int hfi1_alloc_lkey(struct hfi1_mregion *mr, int dma_region)
{
unsigned long flags;
u32 r;
u32 n;
int ret = 0;
struct hfi1_ibdev *dev = to_idev(mr->pd->device);
struct hfi1_lkey_table *rkt = &dev->lk_table;
hfi1_get_mr(mr);
spin_lock_irqsave(&rkt->lock, flags);
if (dma_region) {
struct hfi1_mregion *tmr;
tmr = rcu_access_pointer(dev->dma_mr);
if (!tmr) {
rcu_assign_pointer(dev->dma_mr, mr);
mr->lkey_published = 1;
} else {
hfi1_put_mr(mr);
}
goto success;
}
r = rkt->next;
n = r;
for (;;) {
if (!rcu_access_pointer(rkt->table[r]))
break;
r = (r + 1) & (rkt->max - 1);
if (r == n)
goto bail;
}
rkt->next = (r + 1) & (rkt->max - 1);
rkt->gen++;
mr->lkey = (r << (32 - hfi1_lkey_table_size)) |
((((1 << (24 - hfi1_lkey_table_size)) - 1) & rkt->gen)
<< 8);
if (mr->lkey == 0) {
mr->lkey |= 1 << 8;
rkt->gen++;
}
rcu_assign_pointer(rkt->table[r], mr);
mr->lkey_published = 1;
success:
spin_unlock_irqrestore(&rkt->lock, flags);
out:
return ret;
bail:
hfi1_put_mr(mr);
spin_unlock_irqrestore(&rkt->lock, flags);
ret = -ENOMEM;
goto out;
}
void hfi1_free_lkey(struct hfi1_mregion *mr)
{
unsigned long flags;
u32 lkey = mr->lkey;
u32 r;
struct hfi1_ibdev *dev = to_idev(mr->pd->device);
struct hfi1_lkey_table *rkt = &dev->lk_table;
int freed = 0;
spin_lock_irqsave(&rkt->lock, flags);
if (!mr->lkey_published)
goto out;
if (lkey == 0)
RCU_INIT_POINTER(dev->dma_mr, NULL);
else {
r = lkey >> (32 - hfi1_lkey_table_size);
RCU_INIT_POINTER(rkt->table[r], NULL);
}
mr->lkey_published = 0;
freed++;
out:
spin_unlock_irqrestore(&rkt->lock, flags);
if (freed) {
synchronize_rcu();
hfi1_put_mr(mr);
}
}
int hfi1_lkey_ok(struct hfi1_lkey_table *rkt, struct hfi1_pd *pd,
struct hfi1_sge *isge, struct ib_sge *sge, int acc)
{
struct hfi1_mregion *mr;
unsigned n, m;
size_t off;
rcu_read_lock();
if (sge->lkey == 0) {
struct hfi1_ibdev *dev = to_idev(pd->ibpd.device);
if (pd->user)
goto bail;
mr = rcu_dereference(dev->dma_mr);
if (!mr)
goto bail;
atomic_inc(&mr->refcount);
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
rkt->table[(sge->lkey >> (32 - hfi1_lkey_table_size))]);
if (unlikely(!mr || mr->lkey != sge->lkey || mr->pd != &pd->ibpd))
goto bail;
off = sge->addr - mr->user_base;
if (unlikely(sge->addr < mr->user_base ||
off + sge->length > mr->length ||
(mr->access_flags & acc) != acc))
goto bail;
atomic_inc(&mr->refcount);
rcu_read_unlock();
off += mr->offset;
if (mr->page_shift) {
size_t entries_spanned_by_off;
entries_spanned_by_off = off >> mr->page_shift;
off -= (entries_spanned_by_off << mr->page_shift);
m = entries_spanned_by_off / HFI1_SEGSZ;
n = entries_spanned_by_off % HFI1_SEGSZ;
} else {
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= HFI1_SEGSZ) {
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
int hfi1_rkey_ok(struct hfi1_qp *qp, struct hfi1_sge *sge,
u32 len, u64 vaddr, u32 rkey, int acc)
{
struct hfi1_lkey_table *rkt = &to_idev(qp->ibqp.device)->lk_table;
struct hfi1_mregion *mr;
unsigned n, m;
size_t off;
rcu_read_lock();
if (rkey == 0) {
struct hfi1_pd *pd = to_ipd(qp->ibqp.pd);
struct hfi1_ibdev *dev = to_idev(pd->ibpd.device);
if (pd->user)
goto bail;
mr = rcu_dereference(dev->dma_mr);
if (!mr)
goto bail;
atomic_inc(&mr->refcount);
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
rkt->table[(rkey >> (32 - hfi1_lkey_table_size))]);
if (unlikely(!mr || mr->lkey != rkey || qp->ibqp.pd != mr->pd))
goto bail;
off = vaddr - mr->iova;
if (unlikely(vaddr < mr->iova || off + len > mr->length ||
(mr->access_flags & acc) == 0))
goto bail;
atomic_inc(&mr->refcount);
rcu_read_unlock();
off += mr->offset;
if (mr->page_shift) {
size_t entries_spanned_by_off;
entries_spanned_by_off = off >> mr->page_shift;
off -= (entries_spanned_by_off << mr->page_shift);
m = entries_spanned_by_off / HFI1_SEGSZ;
n = entries_spanned_by_off % HFI1_SEGSZ;
} else {
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= HFI1_SEGSZ) {
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
