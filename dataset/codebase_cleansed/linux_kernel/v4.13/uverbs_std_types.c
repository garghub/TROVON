static int uverbs_free_ah(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
return rdma_destroy_ah((struct ib_ah *)uobject->object);
}
static int uverbs_free_flow(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
return ib_destroy_flow((struct ib_flow *)uobject->object);
}
static int uverbs_free_mw(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
return uverbs_dealloc_mw((struct ib_mw *)uobject->object);
}
static int uverbs_free_qp(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_qp *qp = uobject->object;
struct ib_uqp_object *uqp =
container_of(uobject, struct ib_uqp_object, uevent.uobject);
int ret;
if (why == RDMA_REMOVE_DESTROY) {
if (!list_empty(&uqp->mcast_list))
return -EBUSY;
} else if (qp == qp->real_qp) {
ib_uverbs_detach_umcast(qp, uqp);
}
ret = ib_destroy_qp(qp);
if (ret && why == RDMA_REMOVE_DESTROY)
return ret;
if (uqp->uxrcd)
atomic_dec(&uqp->uxrcd->refcnt);
ib_uverbs_release_uevent(uobject->context->ufile, &uqp->uevent);
return ret;
}
static int uverbs_free_rwq_ind_tbl(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_rwq_ind_table *rwq_ind_tbl = uobject->object;
struct ib_wq **ind_tbl = rwq_ind_tbl->ind_tbl;
int ret;
ret = ib_destroy_rwq_ind_table(rwq_ind_tbl);
if (!ret || why != RDMA_REMOVE_DESTROY)
kfree(ind_tbl);
return ret;
}
static int uverbs_free_wq(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_wq *wq = uobject->object;
struct ib_uwq_object *uwq =
container_of(uobject, struct ib_uwq_object, uevent.uobject);
int ret;
ret = ib_destroy_wq(wq);
if (!ret || why != RDMA_REMOVE_DESTROY)
ib_uverbs_release_uevent(uobject->context->ufile, &uwq->uevent);
return ret;
}
static int uverbs_free_srq(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_srq *srq = uobject->object;
struct ib_uevent_object *uevent =
container_of(uobject, struct ib_uevent_object, uobject);
enum ib_srq_type srq_type = srq->srq_type;
int ret;
ret = ib_destroy_srq(srq);
if (ret && why == RDMA_REMOVE_DESTROY)
return ret;
if (srq_type == IB_SRQT_XRC) {
struct ib_usrq_object *us =
container_of(uevent, struct ib_usrq_object, uevent);
atomic_dec(&us->uxrcd->refcnt);
}
ib_uverbs_release_uevent(uobject->context->ufile, uevent);
return ret;
}
static int uverbs_free_cq(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_cq *cq = uobject->object;
struct ib_uverbs_event_queue *ev_queue = cq->cq_context;
struct ib_ucq_object *ucq =
container_of(uobject, struct ib_ucq_object, uobject);
int ret;
ret = ib_destroy_cq(cq);
if (!ret || why != RDMA_REMOVE_DESTROY)
ib_uverbs_release_ucq(uobject->context->ufile, ev_queue ?
container_of(ev_queue,
struct ib_uverbs_completion_event_file,
ev_queue) : NULL,
ucq);
return ret;
}
static int uverbs_free_mr(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
return ib_dereg_mr((struct ib_mr *)uobject->object);
}
static int uverbs_free_xrcd(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_xrcd *xrcd = uobject->object;
struct ib_uxrcd_object *uxrcd =
container_of(uobject, struct ib_uxrcd_object, uobject);
int ret;
mutex_lock(&uobject->context->ufile->device->xrcd_tree_mutex);
if (why == RDMA_REMOVE_DESTROY && atomic_read(&uxrcd->refcnt))
ret = -EBUSY;
else
ret = ib_uverbs_dealloc_xrcd(uobject->context->ufile->device,
xrcd, why);
mutex_unlock(&uobject->context->ufile->device->xrcd_tree_mutex);
return ret;
}
static int uverbs_free_pd(struct ib_uobject *uobject,
enum rdma_remove_reason why)
{
struct ib_pd *pd = uobject->object;
if (why == RDMA_REMOVE_DESTROY && atomic_read(&pd->usecnt))
return -EBUSY;
ib_dealloc_pd((struct ib_pd *)uobject->object);
return 0;
}
static int uverbs_hot_unplug_completion_event_file(struct ib_uobject_file *uobj_file,
enum rdma_remove_reason why)
{
struct ib_uverbs_completion_event_file *comp_event_file =
container_of(uobj_file, struct ib_uverbs_completion_event_file,
uobj_file);
struct ib_uverbs_event_queue *event_queue = &comp_event_file->ev_queue;
spin_lock_irq(&event_queue->lock);
event_queue->is_closed = 1;
spin_unlock_irq(&event_queue->lock);
if (why == RDMA_REMOVE_DRIVER_REMOVE) {
wake_up_interruptible(&event_queue->poll_wait);
kill_fasync(&event_queue->async_queue, SIGIO, POLL_IN);
}
return 0;
}
