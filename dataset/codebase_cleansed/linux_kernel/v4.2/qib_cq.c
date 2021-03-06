void qib_cq_enter(struct qib_cq *cq, struct ib_wc *entry, int solicited)
{
struct qib_cq_wc *wc;
unsigned long flags;
u32 head;
u32 next;
spin_lock_irqsave(&cq->lock, flags);
wc = cq->queue;
head = wc->head;
if (head >= (unsigned) cq->ibcq.cqe) {
head = cq->ibcq.cqe;
next = 0;
} else
next = head + 1;
if (unlikely(next == wc->tail)) {
spin_unlock_irqrestore(&cq->lock, flags);
if (cq->ibcq.event_handler) {
struct ib_event ev;
ev.device = cq->ibcq.device;
ev.element.cq = &cq->ibcq;
ev.event = IB_EVENT_CQ_ERR;
cq->ibcq.event_handler(&ev, cq->ibcq.cq_context);
}
return;
}
if (cq->ip) {
wc->uqueue[head].wr_id = entry->wr_id;
wc->uqueue[head].status = entry->status;
wc->uqueue[head].opcode = entry->opcode;
wc->uqueue[head].vendor_err = entry->vendor_err;
wc->uqueue[head].byte_len = entry->byte_len;
wc->uqueue[head].ex.imm_data =
(__u32 __force)entry->ex.imm_data;
wc->uqueue[head].qp_num = entry->qp->qp_num;
wc->uqueue[head].src_qp = entry->src_qp;
wc->uqueue[head].wc_flags = entry->wc_flags;
wc->uqueue[head].pkey_index = entry->pkey_index;
wc->uqueue[head].slid = entry->slid;
wc->uqueue[head].sl = entry->sl;
wc->uqueue[head].dlid_path_bits = entry->dlid_path_bits;
wc->uqueue[head].port_num = entry->port_num;
smp_wmb();
} else
wc->kqueue[head] = *entry;
wc->head = next;
if (cq->notify == IB_CQ_NEXT_COMP ||
(cq->notify == IB_CQ_SOLICITED &&
(solicited || entry->status != IB_WC_SUCCESS))) {
struct kthread_worker *worker;
smp_rmb();
worker = cq->dd->worker;
if (likely(worker)) {
cq->notify = IB_CQ_NONE;
cq->triggered++;
queue_kthread_work(worker, &cq->comptask);
}
}
spin_unlock_irqrestore(&cq->lock, flags);
}
int qib_poll_cq(struct ib_cq *ibcq, int num_entries, struct ib_wc *entry)
{
struct qib_cq *cq = to_icq(ibcq);
struct qib_cq_wc *wc;
unsigned long flags;
int npolled;
u32 tail;
if (cq->ip) {
npolled = -EINVAL;
goto bail;
}
spin_lock_irqsave(&cq->lock, flags);
wc = cq->queue;
tail = wc->tail;
if (tail > (u32) cq->ibcq.cqe)
tail = (u32) cq->ibcq.cqe;
for (npolled = 0; npolled < num_entries; ++npolled, ++entry) {
if (tail == wc->head)
break;
*entry = wc->kqueue[tail];
if (tail >= cq->ibcq.cqe)
tail = 0;
else
tail++;
}
wc->tail = tail;
spin_unlock_irqrestore(&cq->lock, flags);
bail:
return npolled;
}
static void send_complete(struct kthread_work *work)
{
struct qib_cq *cq = container_of(work, struct qib_cq, comptask);
for (;;) {
u8 triggered = cq->triggered;
local_bh_disable();
cq->ibcq.comp_handler(&cq->ibcq, cq->ibcq.cq_context);
local_bh_enable();
if (cq->triggered == triggered)
return;
}
}
struct ib_cq *qib_create_cq(struct ib_device *ibdev,
const struct ib_cq_init_attr *attr,
struct ib_ucontext *context,
struct ib_udata *udata)
{
int entries = attr->cqe;
struct qib_ibdev *dev = to_idev(ibdev);
struct qib_cq *cq;
struct qib_cq_wc *wc;
struct ib_cq *ret;
u32 sz;
if (attr->flags)
return ERR_PTR(-EINVAL);
if (entries < 1 || entries > ib_qib_max_cqes) {
ret = ERR_PTR(-EINVAL);
goto done;
}
cq = kmalloc(sizeof(*cq), GFP_KERNEL);
if (!cq) {
ret = ERR_PTR(-ENOMEM);
goto done;
}
sz = sizeof(*wc);
if (udata && udata->outlen >= sizeof(__u64))
sz += sizeof(struct ib_uverbs_wc) * (entries + 1);
else
sz += sizeof(struct ib_wc) * (entries + 1);
wc = vmalloc_user(sz);
if (!wc) {
ret = ERR_PTR(-ENOMEM);
goto bail_cq;
}
if (udata && udata->outlen >= sizeof(__u64)) {
int err;
cq->ip = qib_create_mmap_info(dev, sz, context, wc);
if (!cq->ip) {
ret = ERR_PTR(-ENOMEM);
goto bail_wc;
}
err = ib_copy_to_udata(udata, &cq->ip->offset,
sizeof(cq->ip->offset));
if (err) {
ret = ERR_PTR(err);
goto bail_ip;
}
} else
cq->ip = NULL;
spin_lock(&dev->n_cqs_lock);
if (dev->n_cqs_allocated == ib_qib_max_cqs) {
spin_unlock(&dev->n_cqs_lock);
ret = ERR_PTR(-ENOMEM);
goto bail_ip;
}
dev->n_cqs_allocated++;
spin_unlock(&dev->n_cqs_lock);
if (cq->ip) {
spin_lock_irq(&dev->pending_lock);
list_add(&cq->ip->pending_mmaps, &dev->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
}
cq->dd = dd_from_dev(dev);
cq->ibcq.cqe = entries;
cq->notify = IB_CQ_NONE;
cq->triggered = 0;
spin_lock_init(&cq->lock);
init_kthread_work(&cq->comptask, send_complete);
wc->head = 0;
wc->tail = 0;
cq->queue = wc;
ret = &cq->ibcq;
goto done;
bail_ip:
kfree(cq->ip);
bail_wc:
vfree(wc);
bail_cq:
kfree(cq);
done:
return ret;
}
int qib_destroy_cq(struct ib_cq *ibcq)
{
struct qib_ibdev *dev = to_idev(ibcq->device);
struct qib_cq *cq = to_icq(ibcq);
flush_kthread_work(&cq->comptask);
spin_lock(&dev->n_cqs_lock);
dev->n_cqs_allocated--;
spin_unlock(&dev->n_cqs_lock);
if (cq->ip)
kref_put(&cq->ip->ref, qib_release_mmap_info);
else
vfree(cq->queue);
kfree(cq);
return 0;
}
int qib_req_notify_cq(struct ib_cq *ibcq, enum ib_cq_notify_flags notify_flags)
{
struct qib_cq *cq = to_icq(ibcq);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&cq->lock, flags);
if (cq->notify != IB_CQ_NEXT_COMP)
cq->notify = notify_flags & IB_CQ_SOLICITED_MASK;
if ((notify_flags & IB_CQ_REPORT_MISSED_EVENTS) &&
cq->queue->head != cq->queue->tail)
ret = 1;
spin_unlock_irqrestore(&cq->lock, flags);
return ret;
}
int qib_resize_cq(struct ib_cq *ibcq, int cqe, struct ib_udata *udata)
{
struct qib_cq *cq = to_icq(ibcq);
struct qib_cq_wc *old_wc;
struct qib_cq_wc *wc;
u32 head, tail, n;
int ret;
u32 sz;
if (cqe < 1 || cqe > ib_qib_max_cqes) {
ret = -EINVAL;
goto bail;
}
sz = sizeof(*wc);
if (udata && udata->outlen >= sizeof(__u64))
sz += sizeof(struct ib_uverbs_wc) * (cqe + 1);
else
sz += sizeof(struct ib_wc) * (cqe + 1);
wc = vmalloc_user(sz);
if (!wc) {
ret = -ENOMEM;
goto bail;
}
if (udata && udata->outlen >= sizeof(__u64)) {
__u64 offset = 0;
ret = ib_copy_to_udata(udata, &offset, sizeof(offset));
if (ret)
goto bail_free;
}
spin_lock_irq(&cq->lock);
old_wc = cq->queue;
head = old_wc->head;
if (head > (u32) cq->ibcq.cqe)
head = (u32) cq->ibcq.cqe;
tail = old_wc->tail;
if (tail > (u32) cq->ibcq.cqe)
tail = (u32) cq->ibcq.cqe;
if (head < tail)
n = cq->ibcq.cqe + 1 + head - tail;
else
n = head - tail;
if (unlikely((u32)cqe < n)) {
ret = -EINVAL;
goto bail_unlock;
}
for (n = 0; tail != head; n++) {
if (cq->ip)
wc->uqueue[n] = old_wc->uqueue[tail];
else
wc->kqueue[n] = old_wc->kqueue[tail];
if (tail == (u32) cq->ibcq.cqe)
tail = 0;
else
tail++;
}
cq->ibcq.cqe = cqe;
wc->head = n;
wc->tail = 0;
cq->queue = wc;
spin_unlock_irq(&cq->lock);
vfree(old_wc);
if (cq->ip) {
struct qib_ibdev *dev = to_idev(ibcq->device);
struct qib_mmap_info *ip = cq->ip;
qib_update_mmap_info(dev, ip, sz, wc);
if (udata && udata->outlen >= sizeof(__u64)) {
ret = ib_copy_to_udata(udata, &ip->offset,
sizeof(ip->offset));
if (ret)
goto bail;
}
spin_lock_irq(&dev->pending_lock);
if (list_empty(&ip->pending_mmaps))
list_add(&ip->pending_mmaps, &dev->pending_mmaps);
spin_unlock_irq(&dev->pending_lock);
}
ret = 0;
goto bail;
bail_unlock:
spin_unlock_irq(&cq->lock);
bail_free:
vfree(wc);
bail:
return ret;
}
int qib_cq_init(struct qib_devdata *dd)
{
int ret = 0;
int cpu;
struct task_struct *task;
if (dd->worker)
return 0;
dd->worker = kzalloc(sizeof(*dd->worker), GFP_KERNEL);
if (!dd->worker)
return -ENOMEM;
init_kthread_worker(dd->worker);
task = kthread_create_on_node(
kthread_worker_fn,
dd->worker,
dd->assigned_node_id,
"qib_cq%d", dd->unit);
if (IS_ERR(task))
goto task_fail;
cpu = cpumask_first(cpumask_of_node(dd->assigned_node_id));
kthread_bind(task, cpu);
wake_up_process(task);
out:
return ret;
task_fail:
ret = PTR_ERR(task);
kfree(dd->worker);
dd->worker = NULL;
goto out;
}
void qib_cq_exit(struct qib_devdata *dd)
{
struct kthread_worker *worker;
worker = dd->worker;
if (!worker)
return;
dd->worker = NULL;
smp_wmb();
flush_kthread_worker(worker);
kthread_stop(worker->task);
kfree(worker);
}
