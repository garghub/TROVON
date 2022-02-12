int ipath_alloc_lkey(struct ipath_lkey_table *rkt, struct ipath_mregion *mr)
{
unsigned long flags;
u32 r;
u32 n;
int ret;
spin_lock_irqsave(&rkt->lock, flags);
r = n = rkt->next;
for (;;) {
if (rkt->table[r] == NULL)
break;
r = (r + 1) & (rkt->max - 1);
if (r == n) {
spin_unlock_irqrestore(&rkt->lock, flags);
ipath_dbg("LKEY table full\n");
ret = 0;
goto bail;
}
}
rkt->next = (r + 1) & (rkt->max - 1);
rkt->gen++;
mr->lkey = (r << (32 - ib_ipath_lkey_table_size)) |
((((1 << (24 - ib_ipath_lkey_table_size)) - 1) & rkt->gen)
<< 8);
if (mr->lkey == 0) {
mr->lkey |= 1 << 8;
rkt->gen++;
}
rkt->table[r] = mr;
spin_unlock_irqrestore(&rkt->lock, flags);
ret = 1;
bail:
return ret;
}
void ipath_free_lkey(struct ipath_lkey_table *rkt, u32 lkey)
{
unsigned long flags;
u32 r;
if (lkey == 0)
return;
r = lkey >> (32 - ib_ipath_lkey_table_size);
spin_lock_irqsave(&rkt->lock, flags);
rkt->table[r] = NULL;
spin_unlock_irqrestore(&rkt->lock, flags);
}
int ipath_lkey_ok(struct ipath_qp *qp, struct ipath_sge *isge,
struct ib_sge *sge, int acc)
{
struct ipath_lkey_table *rkt = &to_idev(qp->ibqp.device)->lk_table;
struct ipath_mregion *mr;
unsigned n, m;
size_t off;
int ret;
if (sge->lkey == 0) {
struct ipath_pd *pd = to_ipd(qp->ibqp.pd);
if (pd->user) {
ret = 0;
goto bail;
}
isge->mr = NULL;
isge->vaddr = (void *) sge->addr;
isge->length = sge->length;
isge->sge_length = sge->length;
ret = 1;
goto bail;
}
mr = rkt->table[(sge->lkey >> (32 - ib_ipath_lkey_table_size))];
if (unlikely(mr == NULL || mr->lkey != sge->lkey ||
qp->ibqp.pd != mr->pd)) {
ret = 0;
goto bail;
}
off = sge->addr - mr->user_base;
if (unlikely(sge->addr < mr->user_base ||
off + sge->length > mr->length ||
(mr->access_flags & acc) != acc)) {
ret = 0;
goto bail;
}
off += mr->offset;
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= IPATH_SEGSZ) {
m++;
n = 0;
}
}
isge->mr = mr;
isge->vaddr = mr->map[m]->segs[n].vaddr + off;
isge->length = mr->map[m]->segs[n].length - off;
isge->sge_length = sge->length;
isge->m = m;
isge->n = n;
ret = 1;
bail:
return ret;
}
int ipath_rkey_ok(struct ipath_qp *qp, struct ipath_sge_state *ss,
u32 len, u64 vaddr, u32 rkey, int acc)
{
struct ipath_ibdev *dev = to_idev(qp->ibqp.device);
struct ipath_lkey_table *rkt = &dev->lk_table;
struct ipath_sge *sge = &ss->sge;
struct ipath_mregion *mr;
unsigned n, m;
size_t off;
int ret;
if (rkey == 0) {
struct ipath_pd *pd = to_ipd(qp->ibqp.pd);
if (pd->user) {
ret = 0;
goto bail;
}
sge->mr = NULL;
sge->vaddr = (void *) vaddr;
sge->length = len;
sge->sge_length = len;
ss->sg_list = NULL;
ss->num_sge = 1;
ret = 1;
goto bail;
}
mr = rkt->table[(rkey >> (32 - ib_ipath_lkey_table_size))];
if (unlikely(mr == NULL || mr->lkey != rkey ||
qp->ibqp.pd != mr->pd)) {
ret = 0;
goto bail;
}
off = vaddr - mr->iova;
if (unlikely(vaddr < mr->iova || off + len > mr->length ||
(mr->access_flags & acc) == 0)) {
ret = 0;
goto bail;
}
off += mr->offset;
m = 0;
n = 0;
while (off >= mr->map[m]->segs[n].length) {
off -= mr->map[m]->segs[n].length;
n++;
if (n >= IPATH_SEGSZ) {
m++;
n = 0;
}
}
sge->mr = mr;
sge->vaddr = mr->map[m]->segs[n].vaddr + off;
sge->length = mr->map[m]->segs[n].length - off;
sge->sge_length = len;
sge->m = m;
sge->n = n;
ss->sg_list = NULL;
ss->num_sge = 1;
ret = 1;
bail:
return ret;
}
