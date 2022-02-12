static void
rpcrdma_run_tasklet(unsigned long data)
{
struct rpcrdma_rep *rep;
unsigned long flags;
data = data;
spin_lock_irqsave(&rpcrdma_tk_lock_g, flags);
while (!list_empty(&rpcrdma_tasklets_g)) {
rep = list_entry(rpcrdma_tasklets_g.next,
struct rpcrdma_rep, rr_list);
list_del(&rep->rr_list);
spin_unlock_irqrestore(&rpcrdma_tk_lock_g, flags);
rpcrdma_reply_handler(rep);
spin_lock_irqsave(&rpcrdma_tk_lock_g, flags);
}
spin_unlock_irqrestore(&rpcrdma_tk_lock_g, flags);
}
static void
rpcrdma_schedule_tasklet(struct list_head *sched_list)
{
unsigned long flags;
spin_lock_irqsave(&rpcrdma_tk_lock_g, flags);
list_splice_tail(sched_list, &rpcrdma_tasklets_g);
spin_unlock_irqrestore(&rpcrdma_tk_lock_g, flags);
tasklet_schedule(&rpcrdma_tasklet_g);
}
static void
rpcrdma_qp_async_error_upcall(struct ib_event *event, void *context)
{
struct rpcrdma_ep *ep = context;
pr_err("RPC: %s: %s on device %s ep %p\n",
__func__, ib_event_msg(event->event),
event->device->name, context);
if (ep->rep_connected == 1) {
ep->rep_connected = -EIO;
rpcrdma_conn_func(ep);
wake_up_all(&ep->rep_connect_wait);
}
}
static void
rpcrdma_cq_async_error_upcall(struct ib_event *event, void *context)
{
struct rpcrdma_ep *ep = context;
pr_err("RPC: %s: %s on device %s ep %p\n",
__func__, ib_event_msg(event->event),
event->device->name, context);
if (ep->rep_connected == 1) {
ep->rep_connected = -EIO;
rpcrdma_conn_func(ep);
wake_up_all(&ep->rep_connect_wait);
}
}
static void
rpcrdma_sendcq_process_wc(struct ib_wc *wc)
{
if (wc->wr_id == RPCRDMA_IGNORE_COMPLETION) {
if (wc->status != IB_WC_SUCCESS &&
wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("RPC: %s: SEND: %s\n",
__func__, ib_wc_status_msg(wc->status));
} else {
struct rpcrdma_mw *r;
r = (struct rpcrdma_mw *)(unsigned long)wc->wr_id;
r->mw_sendcompletion(wc);
}
}
static int
rpcrdma_sendcq_poll(struct ib_cq *cq, struct rpcrdma_ep *ep)
{
struct ib_wc *wcs;
int budget, count, rc;
budget = RPCRDMA_WC_BUDGET / RPCRDMA_POLLSIZE;
do {
wcs = ep->rep_send_wcs;
rc = ib_poll_cq(cq, RPCRDMA_POLLSIZE, wcs);
if (rc <= 0)
return rc;
count = rc;
while (count-- > 0)
rpcrdma_sendcq_process_wc(wcs++);
} while (rc == RPCRDMA_POLLSIZE && --budget);
return 0;
}
static void
rpcrdma_sendcq_upcall(struct ib_cq *cq, void *cq_context)
{
struct rpcrdma_ep *ep = (struct rpcrdma_ep *)cq_context;
int rc;
rc = rpcrdma_sendcq_poll(cq, ep);
if (rc) {
dprintk("RPC: %s: ib_poll_cq failed: %i\n",
__func__, rc);
return;
}
rc = ib_req_notify_cq(cq,
IB_CQ_NEXT_COMP | IB_CQ_REPORT_MISSED_EVENTS);
if (rc == 0)
return;
if (rc < 0) {
dprintk("RPC: %s: ib_req_notify_cq failed: %i\n",
__func__, rc);
return;
}
rpcrdma_sendcq_poll(cq, ep);
}
static void
rpcrdma_recvcq_process_wc(struct ib_wc *wc, struct list_head *sched_list)
{
struct rpcrdma_rep *rep =
(struct rpcrdma_rep *)(unsigned long)wc->wr_id;
if (wc->status != IB_WC_SUCCESS)
goto out_fail;
if (wc->opcode != IB_WC_RECV)
return;
dprintk("RPC: %s: rep %p opcode 'recv', length %u: success\n",
__func__, rep, wc->byte_len);
rep->rr_len = wc->byte_len;
ib_dma_sync_single_for_cpu(rep->rr_device,
rdmab_addr(rep->rr_rdmabuf),
rep->rr_len, DMA_FROM_DEVICE);
prefetch(rdmab_to_msg(rep->rr_rdmabuf));
out_schedule:
list_add_tail(&rep->rr_list, sched_list);
return;
out_fail:
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("RPC: %s: rep %p: %s\n",
__func__, rep, ib_wc_status_msg(wc->status));
rep->rr_len = ~0U;
goto out_schedule;
}
static int
rpcrdma_recvcq_poll(struct ib_cq *cq, struct rpcrdma_ep *ep)
{
struct list_head sched_list;
struct ib_wc *wcs;
int budget, count, rc;
INIT_LIST_HEAD(&sched_list);
budget = RPCRDMA_WC_BUDGET / RPCRDMA_POLLSIZE;
do {
wcs = ep->rep_recv_wcs;
rc = ib_poll_cq(cq, RPCRDMA_POLLSIZE, wcs);
if (rc <= 0)
goto out_schedule;
count = rc;
while (count-- > 0)
rpcrdma_recvcq_process_wc(wcs++, &sched_list);
} while (rc == RPCRDMA_POLLSIZE && --budget);
rc = 0;
out_schedule:
rpcrdma_schedule_tasklet(&sched_list);
return rc;
}
static void
rpcrdma_recvcq_upcall(struct ib_cq *cq, void *cq_context)
{
struct rpcrdma_ep *ep = (struct rpcrdma_ep *)cq_context;
int rc;
rc = rpcrdma_recvcq_poll(cq, ep);
if (rc) {
dprintk("RPC: %s: ib_poll_cq failed: %i\n",
__func__, rc);
return;
}
rc = ib_req_notify_cq(cq,
IB_CQ_NEXT_COMP | IB_CQ_REPORT_MISSED_EVENTS);
if (rc == 0)
return;
if (rc < 0) {
dprintk("RPC: %s: ib_req_notify_cq failed: %i\n",
__func__, rc);
return;
}
rpcrdma_recvcq_poll(cq, ep);
}
static void
rpcrdma_flush_cqs(struct rpcrdma_ep *ep)
{
struct ib_wc wc;
LIST_HEAD(sched_list);
while (ib_poll_cq(ep->rep_attr.recv_cq, 1, &wc) > 0)
rpcrdma_recvcq_process_wc(&wc, &sched_list);
if (!list_empty(&sched_list))
rpcrdma_schedule_tasklet(&sched_list);
while (ib_poll_cq(ep->rep_attr.send_cq, 1, &wc) > 0)
rpcrdma_sendcq_process_wc(&wc);
}
static int
rpcrdma_conn_upcall(struct rdma_cm_id *id, struct rdma_cm_event *event)
{
struct rpcrdma_xprt *xprt = id->context;
struct rpcrdma_ia *ia = &xprt->rx_ia;
struct rpcrdma_ep *ep = &xprt->rx_ep;
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
struct sockaddr *sap = (struct sockaddr *)&ep->rep_remote_addr;
#endif
struct ib_qp_attr *attr = &ia->ri_qp_attr;
struct ib_qp_init_attr *iattr = &ia->ri_qp_init_attr;
int connstate = 0;
switch (event->event) {
case RDMA_CM_EVENT_ADDR_RESOLVED:
case RDMA_CM_EVENT_ROUTE_RESOLVED:
ia->ri_async_rc = 0;
complete(&ia->ri_done);
break;
case RDMA_CM_EVENT_ADDR_ERROR:
ia->ri_async_rc = -EHOSTUNREACH;
dprintk("RPC: %s: CM address resolution error, ep 0x%p\n",
__func__, ep);
complete(&ia->ri_done);
break;
case RDMA_CM_EVENT_ROUTE_ERROR:
ia->ri_async_rc = -ENETUNREACH;
dprintk("RPC: %s: CM route resolution error, ep 0x%p\n",
__func__, ep);
complete(&ia->ri_done);
break;
case RDMA_CM_EVENT_ESTABLISHED:
connstate = 1;
ib_query_qp(ia->ri_id->qp, attr,
IB_QP_MAX_QP_RD_ATOMIC | IB_QP_MAX_DEST_RD_ATOMIC,
iattr);
dprintk("RPC: %s: %d responder resources"
" (%d initiator)\n",
__func__, attr->max_dest_rd_atomic,
attr->max_rd_atomic);
goto connected;
case RDMA_CM_EVENT_CONNECT_ERROR:
connstate = -ENOTCONN;
goto connected;
case RDMA_CM_EVENT_UNREACHABLE:
connstate = -ENETDOWN;
goto connected;
case RDMA_CM_EVENT_REJECTED:
connstate = -ECONNREFUSED;
goto connected;
case RDMA_CM_EVENT_DISCONNECTED:
connstate = -ECONNABORTED;
goto connected;
case RDMA_CM_EVENT_DEVICE_REMOVAL:
connstate = -ENODEV;
connected:
dprintk("RPC: %s: %sconnected\n",
__func__, connstate > 0 ? "" : "dis");
ep->rep_connected = connstate;
rpcrdma_conn_func(ep);
wake_up_all(&ep->rep_connect_wait);
default:
dprintk("RPC: %s: %pIS:%u (ep 0x%p): %s\n",
__func__, sap, rpc_get_port(sap), ep,
rdma_event_msg(event->event));
break;
}
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
if (connstate == 1) {
int ird = attr->max_dest_rd_atomic;
int tird = ep->rep_remote_cma.responder_resources;
pr_info("rpcrdma: connection to %pIS:%u on %s, memreg '%s', %d credits, %d responders%s\n",
sap, rpc_get_port(sap),
ia->ri_device->name,
ia->ri_ops->ro_displayname,
xprt->rx_buf.rb_max_requests,
ird, ird < 4 && ird < tird / 2 ? " (low!)" : "");
} else if (connstate < 0) {
pr_info("rpcrdma: connection to %pIS:%u closed (%d)\n",
sap, rpc_get_port(sap), connstate);
}
#endif
return 0;
}
static struct rdma_cm_id *
rpcrdma_create_id(struct rpcrdma_xprt *xprt,
struct rpcrdma_ia *ia, struct sockaddr *addr)
{
struct rdma_cm_id *id;
int rc;
init_completion(&ia->ri_done);
id = rdma_create_id(rpcrdma_conn_upcall, xprt, RDMA_PS_TCP, IB_QPT_RC);
if (IS_ERR(id)) {
rc = PTR_ERR(id);
dprintk("RPC: %s: rdma_create_id() failed %i\n",
__func__, rc);
return id;
}
ia->ri_async_rc = -ETIMEDOUT;
rc = rdma_resolve_addr(id, NULL, addr, RDMA_RESOLVE_TIMEOUT);
if (rc) {
dprintk("RPC: %s: rdma_resolve_addr() failed %i\n",
__func__, rc);
goto out;
}
wait_for_completion_interruptible_timeout(&ia->ri_done,
msecs_to_jiffies(RDMA_RESOLVE_TIMEOUT) + 1);
rc = ia->ri_async_rc;
if (rc)
goto out;
ia->ri_async_rc = -ETIMEDOUT;
rc = rdma_resolve_route(id, RDMA_RESOLVE_TIMEOUT);
if (rc) {
dprintk("RPC: %s: rdma_resolve_route() failed %i\n",
__func__, rc);
goto out;
}
wait_for_completion_interruptible_timeout(&ia->ri_done,
msecs_to_jiffies(RDMA_RESOLVE_TIMEOUT) + 1);
rc = ia->ri_async_rc;
if (rc)
goto out;
return id;
out:
rdma_destroy_id(id);
return ERR_PTR(rc);
}
static void
rpcrdma_clean_cq(struct ib_cq *cq)
{
struct ib_wc wc;
int count = 0;
while (1 == ib_poll_cq(cq, 1, &wc))
++count;
if (count)
dprintk("RPC: %s: flushed %d events (last 0x%x)\n",
__func__, count, wc.opcode);
}
int
rpcrdma_ia_open(struct rpcrdma_xprt *xprt, struct sockaddr *addr, int memreg)
{
int rc, mem_priv;
struct rpcrdma_ia *ia = &xprt->rx_ia;
struct ib_device_attr *devattr = &ia->ri_devattr;
ia->ri_id = rpcrdma_create_id(xprt, ia, addr);
if (IS_ERR(ia->ri_id)) {
rc = PTR_ERR(ia->ri_id);
goto out1;
}
ia->ri_device = ia->ri_id->device;
ia->ri_pd = ib_alloc_pd(ia->ri_device);
if (IS_ERR(ia->ri_pd)) {
rc = PTR_ERR(ia->ri_pd);
dprintk("RPC: %s: ib_alloc_pd() failed %i\n",
__func__, rc);
goto out2;
}
rc = ib_query_device(ia->ri_device, devattr);
if (rc) {
dprintk("RPC: %s: ib_query_device failed %d\n",
__func__, rc);
goto out3;
}
if (devattr->device_cap_flags & IB_DEVICE_LOCAL_DMA_LKEY) {
ia->ri_have_dma_lkey = 1;
ia->ri_dma_lkey = ia->ri_device->local_dma_lkey;
}
if (memreg == RPCRDMA_FRMR) {
if (((devattr->device_cap_flags &
(IB_DEVICE_MEM_MGT_EXTENSIONS|IB_DEVICE_LOCAL_DMA_LKEY)) !=
(IB_DEVICE_MEM_MGT_EXTENSIONS|IB_DEVICE_LOCAL_DMA_LKEY)) ||
(devattr->max_fast_reg_page_list_len == 0)) {
dprintk("RPC: %s: FRMR registration "
"not supported by HCA\n", __func__);
memreg = RPCRDMA_MTHCAFMR;
}
}
if (memreg == RPCRDMA_MTHCAFMR) {
if (!ia->ri_device->alloc_fmr) {
dprintk("RPC: %s: MTHCAFMR registration "
"not supported by HCA\n", __func__);
memreg = RPCRDMA_ALLPHYSICAL;
}
}
switch (memreg) {
case RPCRDMA_FRMR:
ia->ri_ops = &rpcrdma_frwr_memreg_ops;
break;
case RPCRDMA_ALLPHYSICAL:
ia->ri_ops = &rpcrdma_physical_memreg_ops;
mem_priv = IB_ACCESS_LOCAL_WRITE |
IB_ACCESS_REMOTE_WRITE |
IB_ACCESS_REMOTE_READ;
goto register_setup;
case RPCRDMA_MTHCAFMR:
ia->ri_ops = &rpcrdma_fmr_memreg_ops;
if (ia->ri_have_dma_lkey)
break;
mem_priv = IB_ACCESS_LOCAL_WRITE;
register_setup:
ia->ri_bind_mem = ib_get_dma_mr(ia->ri_pd, mem_priv);
if (IS_ERR(ia->ri_bind_mem)) {
printk(KERN_ALERT "%s: ib_get_dma_mr for "
"phys register failed with %lX\n",
__func__, PTR_ERR(ia->ri_bind_mem));
rc = -ENOMEM;
goto out3;
}
break;
default:
printk(KERN_ERR "RPC: Unsupported memory "
"registration mode: %d\n", memreg);
rc = -ENOMEM;
goto out3;
}
dprintk("RPC: %s: memory registration strategy is '%s'\n",
__func__, ia->ri_ops->ro_displayname);
rwlock_init(&ia->ri_qplock);
return 0;
out3:
ib_dealloc_pd(ia->ri_pd);
ia->ri_pd = NULL;
out2:
rdma_destroy_id(ia->ri_id);
ia->ri_id = NULL;
out1:
return rc;
}
void
rpcrdma_ia_close(struct rpcrdma_ia *ia)
{
int rc;
dprintk("RPC: %s: entering\n", __func__);
if (ia->ri_bind_mem != NULL) {
rc = ib_dereg_mr(ia->ri_bind_mem);
dprintk("RPC: %s: ib_dereg_mr returned %i\n",
__func__, rc);
}
if (ia->ri_id != NULL && !IS_ERR(ia->ri_id)) {
if (ia->ri_id->qp)
rdma_destroy_qp(ia->ri_id);
rdma_destroy_id(ia->ri_id);
ia->ri_id = NULL;
}
if (ia->ri_pd && !IS_ERR(ia->ri_pd))
WARN_ON(ib_dealloc_pd(ia->ri_pd));
}
int
rpcrdma_ep_create(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia,
struct rpcrdma_create_data_internal *cdata)
{
struct ib_device_attr *devattr = &ia->ri_devattr;
struct ib_cq *sendcq, *recvcq;
struct ib_cq_init_attr cq_attr = {};
int rc, err;
if (cdata->max_requests > devattr->max_qp_wr)
cdata->max_requests = devattr->max_qp_wr;
ep->rep_attr.event_handler = rpcrdma_qp_async_error_upcall;
ep->rep_attr.qp_context = ep;
ep->rep_attr.srq = NULL;
ep->rep_attr.cap.max_send_wr = cdata->max_requests;
rc = ia->ri_ops->ro_open(ia, ep, cdata);
if (rc)
return rc;
ep->rep_attr.cap.max_recv_wr = cdata->max_requests;
ep->rep_attr.cap.max_send_sge = (cdata->padding ? 4 : 2);
ep->rep_attr.cap.max_recv_sge = 1;
ep->rep_attr.cap.max_inline_data = 0;
ep->rep_attr.sq_sig_type = IB_SIGNAL_REQ_WR;
ep->rep_attr.qp_type = IB_QPT_RC;
ep->rep_attr.port_num = ~0;
if (cdata->padding) {
ep->rep_padbuf = rpcrdma_alloc_regbuf(ia, cdata->padding,
GFP_KERNEL);
if (IS_ERR(ep->rep_padbuf))
return PTR_ERR(ep->rep_padbuf);
} else
ep->rep_padbuf = NULL;
dprintk("RPC: %s: requested max: dtos: send %d recv %d; "
"iovs: send %d recv %d\n",
__func__,
ep->rep_attr.cap.max_send_wr,
ep->rep_attr.cap.max_recv_wr,
ep->rep_attr.cap.max_send_sge,
ep->rep_attr.cap.max_recv_sge);
ep->rep_cqinit = ep->rep_attr.cap.max_send_wr/2 - 1;
if (ep->rep_cqinit > RPCRDMA_MAX_UNSIGNALED_SENDS)
ep->rep_cqinit = RPCRDMA_MAX_UNSIGNALED_SENDS;
else if (ep->rep_cqinit <= 2)
ep->rep_cqinit = 0;
INIT_CQCOUNT(ep);
init_waitqueue_head(&ep->rep_connect_wait);
INIT_DELAYED_WORK(&ep->rep_connect_worker, rpcrdma_connect_worker);
cq_attr.cqe = ep->rep_attr.cap.max_send_wr + 1;
sendcq = ib_create_cq(ia->ri_device, rpcrdma_sendcq_upcall,
rpcrdma_cq_async_error_upcall, ep, &cq_attr);
if (IS_ERR(sendcq)) {
rc = PTR_ERR(sendcq);
dprintk("RPC: %s: failed to create send CQ: %i\n",
__func__, rc);
goto out1;
}
rc = ib_req_notify_cq(sendcq, IB_CQ_NEXT_COMP);
if (rc) {
dprintk("RPC: %s: ib_req_notify_cq failed: %i\n",
__func__, rc);
goto out2;
}
cq_attr.cqe = ep->rep_attr.cap.max_recv_wr + 1;
recvcq = ib_create_cq(ia->ri_device, rpcrdma_recvcq_upcall,
rpcrdma_cq_async_error_upcall, ep, &cq_attr);
if (IS_ERR(recvcq)) {
rc = PTR_ERR(recvcq);
dprintk("RPC: %s: failed to create recv CQ: %i\n",
__func__, rc);
goto out2;
}
rc = ib_req_notify_cq(recvcq, IB_CQ_NEXT_COMP);
if (rc) {
dprintk("RPC: %s: ib_req_notify_cq failed: %i\n",
__func__, rc);
ib_destroy_cq(recvcq);
goto out2;
}
ep->rep_attr.send_cq = sendcq;
ep->rep_attr.recv_cq = recvcq;
ep->rep_remote_cma.private_data = NULL;
ep->rep_remote_cma.private_data_len = 0;
ep->rep_remote_cma.initiator_depth = 0;
if (devattr->max_qp_rd_atom > 32)
ep->rep_remote_cma.responder_resources = 32;
else
ep->rep_remote_cma.responder_resources =
devattr->max_qp_rd_atom;
ep->rep_remote_cma.retry_count = 7;
ep->rep_remote_cma.flow_control = 0;
ep->rep_remote_cma.rnr_retry_count = 0;
return 0;
out2:
err = ib_destroy_cq(sendcq);
if (err)
dprintk("RPC: %s: ib_destroy_cq returned %i\n",
__func__, err);
out1:
rpcrdma_free_regbuf(ia, ep->rep_padbuf);
return rc;
}
void
rpcrdma_ep_destroy(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
int rc;
dprintk("RPC: %s: entering, connected is %d\n",
__func__, ep->rep_connected);
cancel_delayed_work_sync(&ep->rep_connect_worker);
if (ia->ri_id->qp) {
rpcrdma_ep_disconnect(ep, ia);
rdma_destroy_qp(ia->ri_id);
ia->ri_id->qp = NULL;
}
rpcrdma_free_regbuf(ia, ep->rep_padbuf);
rpcrdma_clean_cq(ep->rep_attr.recv_cq);
rc = ib_destroy_cq(ep->rep_attr.recv_cq);
if (rc)
dprintk("RPC: %s: ib_destroy_cq returned %i\n",
__func__, rc);
rpcrdma_clean_cq(ep->rep_attr.send_cq);
rc = ib_destroy_cq(ep->rep_attr.send_cq);
if (rc)
dprintk("RPC: %s: ib_destroy_cq returned %i\n",
__func__, rc);
}
int
rpcrdma_ep_connect(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
struct rdma_cm_id *id, *old;
int rc = 0;
int retry_count = 0;
if (ep->rep_connected != 0) {
struct rpcrdma_xprt *xprt;
retry:
dprintk("RPC: %s: reconnecting...\n", __func__);
rpcrdma_ep_disconnect(ep, ia);
rpcrdma_flush_cqs(ep);
xprt = container_of(ia, struct rpcrdma_xprt, rx_ia);
id = rpcrdma_create_id(xprt, ia,
(struct sockaddr *)&xprt->rx_data.addr);
if (IS_ERR(id)) {
rc = -EHOSTUNREACH;
goto out;
}
if (ia->ri_device != id->device) {
printk("RPC: %s: can't reconnect on "
"different device!\n", __func__);
rdma_destroy_id(id);
rc = -ENETUNREACH;
goto out;
}
rc = rdma_create_qp(id, ia->ri_pd, &ep->rep_attr);
if (rc) {
dprintk("RPC: %s: rdma_create_qp failed %i\n",
__func__, rc);
rdma_destroy_id(id);
rc = -ENETUNREACH;
goto out;
}
write_lock(&ia->ri_qplock);
old = ia->ri_id;
ia->ri_id = id;
write_unlock(&ia->ri_qplock);
rdma_destroy_qp(old);
rdma_destroy_id(old);
} else {
dprintk("RPC: %s: connecting...\n", __func__);
rc = rdma_create_qp(ia->ri_id, ia->ri_pd, &ep->rep_attr);
if (rc) {
dprintk("RPC: %s: rdma_create_qp failed %i\n",
__func__, rc);
return -ENETUNREACH;
}
}
ep->rep_connected = 0;
rc = rdma_connect(ia->ri_id, &ep->rep_remote_cma);
if (rc) {
dprintk("RPC: %s: rdma_connect() failed with %i\n",
__func__, rc);
goto out;
}
wait_event_interruptible(ep->rep_connect_wait, ep->rep_connected != 0);
if (ep->rep_connected == -ECONNREFUSED &&
++retry_count <= RDMA_CONNECT_RETRY_MAX) {
dprintk("RPC: %s: non-peer_reject, retry\n", __func__);
goto retry;
}
if (ep->rep_connected <= 0) {
if (retry_count++ <= RDMA_CONNECT_RETRY_MAX + 1 &&
(ep->rep_remote_cma.responder_resources == 0 ||
ep->rep_remote_cma.initiator_depth !=
ep->rep_remote_cma.responder_resources)) {
if (ep->rep_remote_cma.responder_resources == 0)
ep->rep_remote_cma.responder_resources = 1;
ep->rep_remote_cma.initiator_depth =
ep->rep_remote_cma.responder_resources;
goto retry;
}
rc = ep->rep_connected;
} else {
dprintk("RPC: %s: connected\n", __func__);
}
out:
if (rc)
ep->rep_connected = rc;
return rc;
}
void
rpcrdma_ep_disconnect(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
int rc;
rpcrdma_flush_cqs(ep);
rc = rdma_disconnect(ia->ri_id);
if (!rc) {
wait_event_interruptible(ep->rep_connect_wait,
ep->rep_connected != 1);
dprintk("RPC: %s: after wait, %sconnected\n", __func__,
(ep->rep_connected == 1) ? "still " : "dis");
} else {
dprintk("RPC: %s: rdma_disconnect %i\n", __func__, rc);
ep->rep_connected = rc;
}
}
static struct rpcrdma_req *
rpcrdma_create_req(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_req *req;
req = kzalloc(sizeof(*req), GFP_KERNEL);
if (req == NULL)
return ERR_PTR(-ENOMEM);
req->rl_buffer = &r_xprt->rx_buf;
return req;
}
static struct rpcrdma_rep *
rpcrdma_create_rep(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_rep *rep;
int rc;
rc = -ENOMEM;
rep = kzalloc(sizeof(*rep), GFP_KERNEL);
if (rep == NULL)
goto out;
rep->rr_rdmabuf = rpcrdma_alloc_regbuf(ia, cdata->inline_rsize,
GFP_KERNEL);
if (IS_ERR(rep->rr_rdmabuf)) {
rc = PTR_ERR(rep->rr_rdmabuf);
goto out_free;
}
rep->rr_device = ia->ri_device;
rep->rr_rxprt = r_xprt;
return rep;
out_free:
kfree(rep);
out:
return ERR_PTR(rc);
}
int
rpcrdma_buffer_create(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
char *p;
size_t len;
int i, rc;
buf->rb_max_requests = cdata->max_requests;
spin_lock_init(&buf->rb_lock);
len = buf->rb_max_requests *
(sizeof(struct rpcrdma_req *) + sizeof(struct rpcrdma_rep *));
p = kzalloc(len, GFP_KERNEL);
if (p == NULL) {
dprintk("RPC: %s: req_t/rep_t/pad kzalloc(%zd) failed\n",
__func__, len);
rc = -ENOMEM;
goto out;
}
buf->rb_pool = p;
buf->rb_send_bufs = (struct rpcrdma_req **) p;
p = (char *) &buf->rb_send_bufs[buf->rb_max_requests];
buf->rb_recv_bufs = (struct rpcrdma_rep **) p;
p = (char *) &buf->rb_recv_bufs[buf->rb_max_requests];
rc = ia->ri_ops->ro_init(r_xprt);
if (rc)
goto out;
for (i = 0; i < buf->rb_max_requests; i++) {
struct rpcrdma_req *req;
struct rpcrdma_rep *rep;
req = rpcrdma_create_req(r_xprt);
if (IS_ERR(req)) {
dprintk("RPC: %s: request buffer %d alloc"
" failed\n", __func__, i);
rc = PTR_ERR(req);
goto out;
}
buf->rb_send_bufs[i] = req;
rep = rpcrdma_create_rep(r_xprt);
if (IS_ERR(rep)) {
dprintk("RPC: %s: reply buffer %d alloc failed\n",
__func__, i);
rc = PTR_ERR(rep);
goto out;
}
buf->rb_recv_bufs[i] = rep;
}
return 0;
out:
rpcrdma_buffer_destroy(buf);
return rc;
}
static void
rpcrdma_destroy_rep(struct rpcrdma_ia *ia, struct rpcrdma_rep *rep)
{
if (!rep)
return;
rpcrdma_free_regbuf(ia, rep->rr_rdmabuf);
kfree(rep);
}
static void
rpcrdma_destroy_req(struct rpcrdma_ia *ia, struct rpcrdma_req *req)
{
if (!req)
return;
rpcrdma_free_regbuf(ia, req->rl_sendbuf);
rpcrdma_free_regbuf(ia, req->rl_rdmabuf);
kfree(req);
}
void
rpcrdma_buffer_destroy(struct rpcrdma_buffer *buf)
{
struct rpcrdma_ia *ia = rdmab_to_ia(buf);
int i;
dprintk("RPC: %s: entering\n", __func__);
for (i = 0; i < buf->rb_max_requests; i++) {
if (buf->rb_recv_bufs)
rpcrdma_destroy_rep(ia, buf->rb_recv_bufs[i]);
if (buf->rb_send_bufs)
rpcrdma_destroy_req(ia, buf->rb_send_bufs[i]);
}
ia->ri_ops->ro_destroy(buf);
kfree(buf->rb_pool);
}
struct rpcrdma_mw *
rpcrdma_get_mw(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_mw *mw = NULL;
spin_lock(&buf->rb_mwlock);
if (!list_empty(&buf->rb_mws)) {
mw = list_first_entry(&buf->rb_mws,
struct rpcrdma_mw, mw_list);
list_del_init(&mw->mw_list);
}
spin_unlock(&buf->rb_mwlock);
if (!mw)
pr_err("RPC: %s: no MWs available\n", __func__);
return mw;
}
void
rpcrdma_put_mw(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mw *mw)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
spin_lock(&buf->rb_mwlock);
list_add_tail(&mw->mw_list, &buf->rb_mws);
spin_unlock(&buf->rb_mwlock);
}
static void
rpcrdma_buffer_put_sendbuf(struct rpcrdma_req *req, struct rpcrdma_buffer *buf)
{
buf->rb_send_bufs[--buf->rb_send_index] = req;
req->rl_niovs = 0;
if (req->rl_reply) {
buf->rb_recv_bufs[--buf->rb_recv_index] = req->rl_reply;
req->rl_reply = NULL;
}
}
struct rpcrdma_req *
rpcrdma_buffer_get(struct rpcrdma_buffer *buffers)
{
struct rpcrdma_req *req;
unsigned long flags;
spin_lock_irqsave(&buffers->rb_lock, flags);
if (buffers->rb_send_index == buffers->rb_max_requests) {
spin_unlock_irqrestore(&buffers->rb_lock, flags);
dprintk("RPC: %s: out of request buffers\n", __func__);
return ((struct rpcrdma_req *)NULL);
}
req = buffers->rb_send_bufs[buffers->rb_send_index];
if (buffers->rb_send_index < buffers->rb_recv_index) {
dprintk("RPC: %s: %d extra receives outstanding (ok)\n",
__func__,
buffers->rb_recv_index - buffers->rb_send_index);
req->rl_reply = NULL;
} else {
req->rl_reply = buffers->rb_recv_bufs[buffers->rb_recv_index];
buffers->rb_recv_bufs[buffers->rb_recv_index++] = NULL;
}
buffers->rb_send_bufs[buffers->rb_send_index++] = NULL;
spin_unlock_irqrestore(&buffers->rb_lock, flags);
return req;
}
void
rpcrdma_buffer_put(struct rpcrdma_req *req)
{
struct rpcrdma_buffer *buffers = req->rl_buffer;
unsigned long flags;
spin_lock_irqsave(&buffers->rb_lock, flags);
rpcrdma_buffer_put_sendbuf(req, buffers);
spin_unlock_irqrestore(&buffers->rb_lock, flags);
}
void
rpcrdma_recv_buffer_get(struct rpcrdma_req *req)
{
struct rpcrdma_buffer *buffers = req->rl_buffer;
unsigned long flags;
spin_lock_irqsave(&buffers->rb_lock, flags);
if (buffers->rb_recv_index < buffers->rb_max_requests) {
req->rl_reply = buffers->rb_recv_bufs[buffers->rb_recv_index];
buffers->rb_recv_bufs[buffers->rb_recv_index++] = NULL;
}
spin_unlock_irqrestore(&buffers->rb_lock, flags);
}
void
rpcrdma_recv_buffer_put(struct rpcrdma_rep *rep)
{
struct rpcrdma_buffer *buffers = &rep->rr_rxprt->rx_buf;
unsigned long flags;
spin_lock_irqsave(&buffers->rb_lock, flags);
buffers->rb_recv_bufs[--buffers->rb_recv_index] = rep;
spin_unlock_irqrestore(&buffers->rb_lock, flags);
}
void
rpcrdma_mapping_error(struct rpcrdma_mr_seg *seg)
{
dprintk("RPC: map_one: offset %p iova %llx len %zu\n",
seg->mr_offset,
(unsigned long long)seg->mr_dma, seg->mr_dmalen);
}
static int
rpcrdma_register_internal(struct rpcrdma_ia *ia, void *va, int len,
struct ib_mr **mrp, struct ib_sge *iov)
{
struct ib_phys_buf ipb;
struct ib_mr *mr;
int rc;
iov->addr = ib_dma_map_single(ia->ri_device,
va, len, DMA_BIDIRECTIONAL);
if (ib_dma_mapping_error(ia->ri_device, iov->addr))
return -ENOMEM;
iov->length = len;
if (ia->ri_have_dma_lkey) {
*mrp = NULL;
iov->lkey = ia->ri_dma_lkey;
return 0;
} else if (ia->ri_bind_mem != NULL) {
*mrp = NULL;
iov->lkey = ia->ri_bind_mem->lkey;
return 0;
}
ipb.addr = iov->addr;
ipb.size = iov->length;
mr = ib_reg_phys_mr(ia->ri_pd, &ipb, 1,
IB_ACCESS_LOCAL_WRITE, &iov->addr);
dprintk("RPC: %s: phys convert: 0x%llx "
"registered 0x%llx length %d\n",
__func__, (unsigned long long)ipb.addr,
(unsigned long long)iov->addr, len);
if (IS_ERR(mr)) {
*mrp = NULL;
rc = PTR_ERR(mr);
dprintk("RPC: %s: failed with %i\n", __func__, rc);
} else {
*mrp = mr;
iov->lkey = mr->lkey;
rc = 0;
}
return rc;
}
static int
rpcrdma_deregister_internal(struct rpcrdma_ia *ia,
struct ib_mr *mr, struct ib_sge *iov)
{
int rc;
ib_dma_unmap_single(ia->ri_device,
iov->addr, iov->length, DMA_BIDIRECTIONAL);
if (NULL == mr)
return 0;
rc = ib_dereg_mr(mr);
if (rc)
dprintk("RPC: %s: ib_dereg_mr failed %i\n", __func__, rc);
return rc;
}
struct rpcrdma_regbuf *
rpcrdma_alloc_regbuf(struct rpcrdma_ia *ia, size_t size, gfp_t flags)
{
struct rpcrdma_regbuf *rb;
int rc;
rc = -ENOMEM;
rb = kmalloc(sizeof(*rb) + size, flags);
if (rb == NULL)
goto out;
rb->rg_size = size;
rb->rg_owner = NULL;
rc = rpcrdma_register_internal(ia, rb->rg_base, size,
&rb->rg_mr, &rb->rg_iov);
if (rc)
goto out_free;
return rb;
out_free:
kfree(rb);
out:
return ERR_PTR(rc);
}
void
rpcrdma_free_regbuf(struct rpcrdma_ia *ia, struct rpcrdma_regbuf *rb)
{
if (rb) {
rpcrdma_deregister_internal(ia, rb->rg_mr, &rb->rg_iov);
kfree(rb);
}
}
int
rpcrdma_ep_post(struct rpcrdma_ia *ia,
struct rpcrdma_ep *ep,
struct rpcrdma_req *req)
{
struct ib_send_wr send_wr, *send_wr_fail;
struct rpcrdma_rep *rep = req->rl_reply;
int rc;
if (rep) {
rc = rpcrdma_ep_post_recv(ia, ep, rep);
if (rc)
goto out;
req->rl_reply = NULL;
}
send_wr.next = NULL;
send_wr.wr_id = RPCRDMA_IGNORE_COMPLETION;
send_wr.sg_list = req->rl_send_iov;
send_wr.num_sge = req->rl_niovs;
send_wr.opcode = IB_WR_SEND;
if (send_wr.num_sge == 4)
ib_dma_sync_single_for_device(ia->ri_device,
req->rl_send_iov[3].addr,
req->rl_send_iov[3].length,
DMA_TO_DEVICE);
ib_dma_sync_single_for_device(ia->ri_device,
req->rl_send_iov[1].addr,
req->rl_send_iov[1].length,
DMA_TO_DEVICE);
ib_dma_sync_single_for_device(ia->ri_device,
req->rl_send_iov[0].addr,
req->rl_send_iov[0].length,
DMA_TO_DEVICE);
if (DECR_CQCOUNT(ep) > 0)
send_wr.send_flags = 0;
else {
INIT_CQCOUNT(ep);
send_wr.send_flags = IB_SEND_SIGNALED;
}
rc = ib_post_send(ia->ri_id->qp, &send_wr, &send_wr_fail);
if (rc)
dprintk("RPC: %s: ib_post_send returned %i\n", __func__,
rc);
out:
return rc;
}
int
rpcrdma_ep_post_recv(struct rpcrdma_ia *ia,
struct rpcrdma_ep *ep,
struct rpcrdma_rep *rep)
{
struct ib_recv_wr recv_wr, *recv_wr_fail;
int rc;
recv_wr.next = NULL;
recv_wr.wr_id = (u64) (unsigned long) rep;
recv_wr.sg_list = &rep->rr_rdmabuf->rg_iov;
recv_wr.num_sge = 1;
ib_dma_sync_single_for_cpu(ia->ri_device,
rdmab_addr(rep->rr_rdmabuf),
rdmab_length(rep->rr_rdmabuf),
DMA_BIDIRECTIONAL);
rc = ib_post_recv(ia->ri_id->qp, &recv_wr, &recv_wr_fail);
if (rc)
dprintk("RPC: %s: ib_post_recv returned %i\n", __func__,
rc);
return rc;
}
unsigned int
rpcrdma_max_segments(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
int bytes, segments;
bytes = min_t(unsigned int, cdata->inline_wsize, cdata->inline_rsize);
bytes -= RPCRDMA_HDRLEN_MIN;
if (bytes < sizeof(struct rpcrdma_segment) * 2) {
pr_warn("RPC: %s: inline threshold too small\n",
__func__);
return 0;
}
segments = 1 << (fls(bytes / sizeof(struct rpcrdma_segment)) - 1);
dprintk("RPC: %s: max chunk list size = %d segments\n",
__func__, segments);
return segments;
}
