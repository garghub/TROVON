int qib_post_srq_receive(struct ib_srq *ibsrq, struct ib_recv_wr *wr,
struct ib_recv_wr **bad_wr)
{
struct qib_srq *srq = to_isrq(ibsrq);
struct qib_rwq *wq;
unsigned long flags;
int ret;
for (; wr; wr = wr->next) {
struct qib_rwqe *wqe;
u32 next;
int i;
if ((unsigned) wr->num_sge > srq->rq.max_sge) {
*bad_wr = wr;
ret = -EINVAL;
goto bail;
}
spin_lock_irqsave(&srq->rq.lock, flags);
wq = srq->rq.wq;
next = wq->head + 1;
if (next >= srq->rq.size)
next = 0;
if (next == wq->tail) {
spin_unlock_irqrestore(&srq->rq.lock, flags);
*bad_wr = wr;
ret = -ENOMEM;
goto bail;
}
wqe = get_rwqe_ptr(&srq->rq, wq->head);
wqe->wr_id = wr->wr_id;
wqe->num_sge = wr->num_sge;
for (i = 0; i < wr->num_sge; i++)
wqe->sg_list[i] = wr->sg_list[i];
smp_wmb();
wq->head = next;
spin_unlock_irqrestore(&srq->rq.lock, flags);
}
ret = 0;
bail:
return ret;
}
struct ib_srq *qib_create_srq(struct ib_pd *ibpd,
struct ib_srq_init_attr *srq_init_attr,
struct ib_udata *udata)
{
struct qib_ibdev *dev = to_idev(ibpd->device);
struct qib_srq *srq;
u32 sz;
struct ib_srq *ret;
if (srq_init_attr->attr.max_sge == 0 ||
srq_init_attr->attr.max_sge > ib_qib_max_srq_sges ||
srq_init_attr->attr.max_wr == 0 ||
srq_init_attr->attr.max_wr > ib_qib_max_srq_wrs) {
ret = ERR_PTR(-EINVAL);
goto done;
}
srq = kmalloc(sizeof(*srq), GFP_KERNEL);
if (!srq) {
ret = ERR_PTR(-ENOMEM);
goto done;
}
srq->rq.size = srq_init_attr->attr.max_wr + 1;
srq->rq.max_sge = srq_init_attr->attr.max_sge;
sz = sizeof(struct ib_sge) * srq->rq.max_sge +
sizeof(struct qib_rwqe);
srq->rq.wq = vmalloc_user(sizeof(struct qib_rwq) + srq->rq.size * sz);
if (!srq->rq.wq) {
ret = ERR_PTR(-ENOMEM);
goto bail_srq;
}
if (udata && udata->outlen >= sizeof(__u64)) {
int err;
u32 s = sizeof(struct qib_rwq) + srq->rq.size * sz;
srq->ip =
qib_create_mmap_info(dev, s, ibpd->uobject->context,
srq->rq.wq);
if (!srq->ip) {
ret = ERR_PTR(-ENOMEM);
goto bail_wq;
}
err = ib_copy_to_udata(udata, &srq->ip->offset,
sizeof(srq->ip->offset));
if (err) {
ret = ERR_PTR(err);
goto bail_ip;
}
} else
srq->ip = NULL;
spin_lock_init(&srq->rq.lock);
srq->rq.wq->head = 0;
srq->rq.wq->tail = 0;
srq->limit = srq_init_attr->attr.srq_limit;
spin_lock(&dev->n_srqs_lock);
if (dev->n_srqs_allocated == ib_qib_max_srqs) {
spin_unlock(&dev->n_srqs_lock);
ret = ERR_PTR(-ENOMEM);
goto bail_ip;
}
dev->n_srqs_allocated++;
spin_unlock(&dev->n_srqs_lock);
if (srq->ip) {
spin_lock_irq(&dev->pending_lock);
list_add(&srq->ip->pending_mmaps, &dev->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
}
ret = &srq->ibsrq;
goto done;
bail_ip:
kfree(srq->ip);
bail_wq:
vfree(srq->rq.wq);
bail_srq:
kfree(srq);
done:
return ret;
}
int qib_modify_srq(struct ib_srq *ibsrq, struct ib_srq_attr *attr,
enum ib_srq_attr_mask attr_mask,
struct ib_udata *udata)
{
struct qib_srq *srq = to_isrq(ibsrq);
struct qib_rwq *wq;
int ret = 0;
if (attr_mask & IB_SRQ_MAX_WR) {
struct qib_rwq *owq;
struct qib_rwqe *p;
u32 sz, size, n, head, tail;
if ((attr->max_wr > ib_qib_max_srq_wrs) ||
((attr_mask & IB_SRQ_LIMIT) ?
attr->srq_limit : srq->limit) > attr->max_wr) {
ret = -EINVAL;
goto bail;
}
sz = sizeof(struct qib_rwqe) +
srq->rq.max_sge * sizeof(struct ib_sge);
size = attr->max_wr + 1;
wq = vmalloc_user(sizeof(struct qib_rwq) + size * sz);
if (!wq) {
ret = -ENOMEM;
goto bail;
}
if (udata && udata->inlen >= sizeof(__u64)) {
__u64 offset_addr;
__u64 offset = 0;
ret = ib_copy_from_udata(&offset_addr, udata,
sizeof(offset_addr));
if (ret)
goto bail_free;
udata->outbuf =
(void __user *) (unsigned long) offset_addr;
ret = ib_copy_to_udata(udata, &offset,
sizeof(offset));
if (ret)
goto bail_free;
}
spin_lock_irq(&srq->rq.lock);
owq = srq->rq.wq;
head = owq->head;
tail = owq->tail;
if (head >= srq->rq.size || tail >= srq->rq.size) {
ret = -EINVAL;
goto bail_unlock;
}
n = head;
if (n < tail)
n += srq->rq.size - tail;
else
n -= tail;
if (size <= n) {
ret = -EINVAL;
goto bail_unlock;
}
n = 0;
p = wq->wq;
while (tail != head) {
struct qib_rwqe *wqe;
int i;
wqe = get_rwqe_ptr(&srq->rq, tail);
p->wr_id = wqe->wr_id;
p->num_sge = wqe->num_sge;
for (i = 0; i < wqe->num_sge; i++)
p->sg_list[i] = wqe->sg_list[i];
n++;
p = (struct qib_rwqe *)((char *) p + sz);
if (++tail >= srq->rq.size)
tail = 0;
}
srq->rq.wq = wq;
srq->rq.size = size;
wq->head = n;
wq->tail = 0;
if (attr_mask & IB_SRQ_LIMIT)
srq->limit = attr->srq_limit;
spin_unlock_irq(&srq->rq.lock);
vfree(owq);
if (srq->ip) {
struct qib_mmap_info *ip = srq->ip;
struct qib_ibdev *dev = to_idev(srq->ibsrq.device);
u32 s = sizeof(struct qib_rwq) + size * sz;
qib_update_mmap_info(dev, ip, s, wq);
if (udata && udata->inlen >= sizeof(__u64)) {
ret = ib_copy_to_udata(udata, &ip->offset,
sizeof(ip->offset));
if (ret)
goto bail;
}
spin_lock_irq(&dev->pending_lock);
if (list_empty(&ip->pending_mmaps))
list_add(&ip->pending_mmaps,
&dev->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
}
} else if (attr_mask & IB_SRQ_LIMIT) {
spin_lock_irq(&srq->rq.lock);
if (attr->srq_limit >= srq->rq.size)
ret = -EINVAL;
else
srq->limit = attr->srq_limit;
spin_unlock_irq(&srq->rq.lock);
}
goto bail;
bail_unlock:
spin_unlock_irq(&srq->rq.lock);
bail_free:
vfree(wq);
bail:
return ret;
}
int qib_query_srq(struct ib_srq *ibsrq, struct ib_srq_attr *attr)
{
struct qib_srq *srq = to_isrq(ibsrq);
attr->max_wr = srq->rq.size - 1;
attr->max_sge = srq->rq.max_sge;
attr->srq_limit = srq->limit;
return 0;
}
int qib_destroy_srq(struct ib_srq *ibsrq)
{
struct qib_srq *srq = to_isrq(ibsrq);
struct qib_ibdev *dev = to_idev(ibsrq->device);
spin_lock(&dev->n_srqs_lock);
dev->n_srqs_allocated--;
spin_unlock(&dev->n_srqs_lock);
if (srq->ip)
kref_put(&srq->ip->ref, qib_release_mmap_info);
else
vfree(srq->rq.wq);
kfree(srq);
return 0;
}
