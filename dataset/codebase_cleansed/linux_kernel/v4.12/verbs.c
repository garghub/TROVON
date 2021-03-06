int
rpcrdma_alloc_wq(void)
{
struct workqueue_struct *recv_wq;
recv_wq = alloc_workqueue("xprtrdma_receive",
WQ_MEM_RECLAIM | WQ_UNBOUND | WQ_HIGHPRI,
0);
if (!recv_wq)
return -ENOMEM;
rpcrdma_receive_wq = recv_wq;
return 0;
}
void
rpcrdma_destroy_wq(void)
{
struct workqueue_struct *wq;
if (rpcrdma_receive_wq) {
wq = rpcrdma_receive_wq;
rpcrdma_receive_wq = NULL;
destroy_workqueue(wq);
}
}
static void
rpcrdma_qp_async_error_upcall(struct ib_event *event, void *context)
{
struct rpcrdma_ep *ep = context;
pr_err("rpcrdma: %s on device %s ep %p\n",
ib_event_msg(event->event), event->device->name, context);
if (ep->rep_connected == 1) {
ep->rep_connected = -EIO;
rpcrdma_conn_func(ep);
wake_up_all(&ep->rep_connect_wait);
}
}
static void
rpcrdma_wc_send(struct ib_cq *cq, struct ib_wc *wc)
{
if (wc->status != IB_WC_SUCCESS && wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("rpcrdma: Send: %s (%u/0x%x)\n",
ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
}
static void
rpcrdma_update_granted_credits(struct rpcrdma_rep *rep)
{
struct rpcrdma_msg *rmsgp = rdmab_to_msg(rep->rr_rdmabuf);
struct rpcrdma_buffer *buffer = &rep->rr_rxprt->rx_buf;
u32 credits;
if (rep->rr_len < RPCRDMA_HDRLEN_ERR)
return;
credits = be32_to_cpu(rmsgp->rm_credit);
if (credits == 0)
credits = 1;
else if (credits > buffer->rb_max_requests)
credits = buffer->rb_max_requests;
atomic_set(&buffer->rb_credits, credits);
}
static void
rpcrdma_wc_receive(struct ib_cq *cq, struct ib_wc *wc)
{
struct ib_cqe *cqe = wc->wr_cqe;
struct rpcrdma_rep *rep = container_of(cqe, struct rpcrdma_rep,
rr_cqe);
if (wc->status != IB_WC_SUCCESS)
goto out_fail;
if (wc->opcode != IB_WC_RECV)
return;
dprintk("RPC: %s: rep %p opcode 'recv', length %u: success\n",
__func__, rep, wc->byte_len);
rep->rr_len = wc->byte_len;
rep->rr_wc_flags = wc->wc_flags;
rep->rr_inv_rkey = wc->ex.invalidate_rkey;
ib_dma_sync_single_for_cpu(rdmab_device(rep->rr_rdmabuf),
rdmab_addr(rep->rr_rdmabuf),
rep->rr_len, DMA_FROM_DEVICE);
rpcrdma_update_granted_credits(rep);
out_schedule:
queue_work(rpcrdma_receive_wq, &rep->rr_work);
return;
out_fail:
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("rpcrdma: Recv: %s (%u/0x%x)\n",
ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
rep->rr_len = RPCRDMA_BAD_LEN;
goto out_schedule;
}
static void
rpcrdma_update_connect_private(struct rpcrdma_xprt *r_xprt,
struct rdma_conn_param *param)
{
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
const struct rpcrdma_connect_private *pmsg = param->private_data;
unsigned int rsize, wsize;
r_xprt->rx_ia.ri_reminv_expected = false;
r_xprt->rx_ia.ri_implicit_roundup = xprt_rdma_pad_optimize;
rsize = RPCRDMA_V1_DEF_INLINE_SIZE;
wsize = RPCRDMA_V1_DEF_INLINE_SIZE;
if (pmsg &&
pmsg->cp_magic == rpcrdma_cmp_magic &&
pmsg->cp_version == RPCRDMA_CMP_VERSION) {
r_xprt->rx_ia.ri_reminv_expected = true;
r_xprt->rx_ia.ri_implicit_roundup = true;
rsize = rpcrdma_decode_buffer_size(pmsg->cp_send_size);
wsize = rpcrdma_decode_buffer_size(pmsg->cp_recv_size);
}
if (rsize < cdata->inline_rsize)
cdata->inline_rsize = rsize;
if (wsize < cdata->inline_wsize)
cdata->inline_wsize = wsize;
dprintk("RPC: %s: max send %u, max recv %u\n",
__func__, cdata->inline_wsize, cdata->inline_rsize);
rpcrdma_set_max_header_sizes(r_xprt);
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
case RDMA_CM_EVENT_DEVICE_REMOVAL:
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
pr_info("rpcrdma: removing device for %pIS:%u\n",
sap, rpc_get_port(sap));
#endif
set_bit(RPCRDMA_IAF_REMOVING, &ia->ri_flags);
ep->rep_connected = -ENODEV;
xprt_force_disconnect(&xprt->rx_xprt);
wait_for_completion(&ia->ri_remove_done);
ia->ri_id = NULL;
ia->ri_pd = NULL;
ia->ri_device = NULL;
return 1;
case RDMA_CM_EVENT_ESTABLISHED:
connstate = 1;
ib_query_qp(ia->ri_id->qp, attr,
IB_QP_MAX_QP_RD_ATOMIC | IB_QP_MAX_DEST_RD_ATOMIC,
iattr);
dprintk("RPC: %s: %d responder resources"
" (%d initiator)\n",
__func__, attr->max_dest_rd_atomic,
attr->max_rd_atomic);
rpcrdma_update_connect_private(xprt, &event->param.conn);
goto connected;
case RDMA_CM_EVENT_CONNECT_ERROR:
connstate = -ENOTCONN;
goto connected;
case RDMA_CM_EVENT_UNREACHABLE:
connstate = -ENETDOWN;
goto connected;
case RDMA_CM_EVENT_REJECTED:
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
pr_info("rpcrdma: connection to %pIS:%u on %s rejected: %s\n",
sap, rpc_get_port(sap), ia->ri_device->name,
rdma_reject_msg(id, event->status));
#endif
connstate = -ECONNREFUSED;
if (event->status == IB_CM_REJ_STALE_CONN)
connstate = -EAGAIN;
goto connected;
case RDMA_CM_EVENT_DISCONNECTED:
connstate = -ECONNABORTED;
connected:
dprintk("RPC: %s: %sconnected\n",
__func__, connstate > 0 ? "" : "dis");
atomic_set(&xprt->rx_buf.rb_credits, 1);
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
unsigned long wtimeout = msecs_to_jiffies(RDMA_RESOLVE_TIMEOUT) + 1;
struct rdma_cm_id *id;
int rc;
init_completion(&ia->ri_done);
init_completion(&ia->ri_remove_done);
id = rdma_create_id(&init_net, rpcrdma_conn_upcall, xprt, RDMA_PS_TCP,
IB_QPT_RC);
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
rc = wait_for_completion_interruptible_timeout(&ia->ri_done, wtimeout);
if (rc < 0) {
dprintk("RPC: %s: wait() exited: %i\n",
__func__, rc);
goto out;
}
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
rc = wait_for_completion_interruptible_timeout(&ia->ri_done, wtimeout);
if (rc < 0) {
dprintk("RPC: %s: wait() exited: %i\n",
__func__, rc);
goto out;
}
rc = ia->ri_async_rc;
if (rc)
goto out;
return id;
out:
rdma_destroy_id(id);
return ERR_PTR(rc);
}
int
rpcrdma_ia_open(struct rpcrdma_xprt *xprt, struct sockaddr *addr)
{
struct rpcrdma_ia *ia = &xprt->rx_ia;
int rc;
ia->ri_id = rpcrdma_create_id(xprt, ia, addr);
if (IS_ERR(ia->ri_id)) {
rc = PTR_ERR(ia->ri_id);
goto out_err;
}
ia->ri_device = ia->ri_id->device;
ia->ri_pd = ib_alloc_pd(ia->ri_device, 0);
if (IS_ERR(ia->ri_pd)) {
rc = PTR_ERR(ia->ri_pd);
pr_err("rpcrdma: ib_alloc_pd() returned %d\n", rc);
goto out_err;
}
switch (xprt_rdma_memreg_strategy) {
case RPCRDMA_FRMR:
if (frwr_is_supported(ia)) {
ia->ri_ops = &rpcrdma_frwr_memreg_ops;
break;
}
case RPCRDMA_MTHCAFMR:
if (fmr_is_supported(ia)) {
ia->ri_ops = &rpcrdma_fmr_memreg_ops;
break;
}
default:
pr_err("rpcrdma: Device %s does not support memreg mode %d\n",
ia->ri_device->name, xprt_rdma_memreg_strategy);
rc = -EINVAL;
goto out_err;
}
return 0;
out_err:
rpcrdma_ia_close(ia);
return rc;
}
void
rpcrdma_ia_remove(struct rpcrdma_ia *ia)
{
struct rpcrdma_xprt *r_xprt = container_of(ia, struct rpcrdma_xprt,
rx_ia);
struct rpcrdma_ep *ep = &r_xprt->rx_ep;
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_req *req;
struct rpcrdma_rep *rep;
cancel_delayed_work_sync(&buf->rb_refresh_worker);
if (ia->ri_id->qp) {
ib_drain_qp(ia->ri_id->qp);
rdma_destroy_qp(ia->ri_id);
ia->ri_id->qp = NULL;
}
ib_free_cq(ep->rep_attr.recv_cq);
ib_free_cq(ep->rep_attr.send_cq);
list_for_each_entry(rep, &buf->rb_recv_bufs, rr_list)
rpcrdma_dma_unmap_regbuf(rep->rr_rdmabuf);
list_for_each_entry(req, &buf->rb_allreqs, rl_all) {
rpcrdma_dma_unmap_regbuf(req->rl_rdmabuf);
rpcrdma_dma_unmap_regbuf(req->rl_sendbuf);
rpcrdma_dma_unmap_regbuf(req->rl_recvbuf);
}
rpcrdma_destroy_mrs(buf);
complete(&ia->ri_remove_done);
}
void
rpcrdma_ia_close(struct rpcrdma_ia *ia)
{
dprintk("RPC: %s: entering\n", __func__);
if (ia->ri_id != NULL && !IS_ERR(ia->ri_id)) {
if (ia->ri_id->qp)
rdma_destroy_qp(ia->ri_id);
rdma_destroy_id(ia->ri_id);
}
ia->ri_id = NULL;
ia->ri_device = NULL;
if (ia->ri_pd && !IS_ERR(ia->ri_pd))
ib_dealloc_pd(ia->ri_pd);
ia->ri_pd = NULL;
}
int
rpcrdma_ep_create(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia,
struct rpcrdma_create_data_internal *cdata)
{
struct rpcrdma_connect_private *pmsg = &ep->rep_cm_private;
unsigned int max_qp_wr, max_sge;
struct ib_cq *sendcq, *recvcq;
int rc;
max_sge = min_t(unsigned int, ia->ri_device->attrs.max_sge,
RPCRDMA_MAX_SEND_SGES);
if (max_sge < RPCRDMA_MIN_SEND_SGES) {
pr_warn("rpcrdma: HCA provides only %d send SGEs\n", max_sge);
return -ENOMEM;
}
ia->ri_max_send_sges = max_sge - RPCRDMA_MIN_SEND_SGES;
if (ia->ri_device->attrs.max_qp_wr <= RPCRDMA_BACKWARD_WRS) {
dprintk("RPC: %s: insufficient wqe's available\n",
__func__);
return -ENOMEM;
}
max_qp_wr = ia->ri_device->attrs.max_qp_wr - RPCRDMA_BACKWARD_WRS - 1;
if (cdata->max_requests > max_qp_wr)
cdata->max_requests = max_qp_wr;
ep->rep_attr.event_handler = rpcrdma_qp_async_error_upcall;
ep->rep_attr.qp_context = ep;
ep->rep_attr.srq = NULL;
ep->rep_attr.cap.max_send_wr = cdata->max_requests;
ep->rep_attr.cap.max_send_wr += RPCRDMA_BACKWARD_WRS;
ep->rep_attr.cap.max_send_wr += 1;
rc = ia->ri_ops->ro_open(ia, ep, cdata);
if (rc)
return rc;
ep->rep_attr.cap.max_recv_wr = cdata->max_requests;
ep->rep_attr.cap.max_recv_wr += RPCRDMA_BACKWARD_WRS;
ep->rep_attr.cap.max_recv_wr += 1;
ep->rep_attr.cap.max_send_sge = max_sge;
ep->rep_attr.cap.max_recv_sge = 1;
ep->rep_attr.cap.max_inline_data = 0;
ep->rep_attr.sq_sig_type = IB_SIGNAL_REQ_WR;
ep->rep_attr.qp_type = IB_QPT_RC;
ep->rep_attr.port_num = ~0;
dprintk("RPC: %s: requested max: dtos: send %d recv %d; "
"iovs: send %d recv %d\n",
__func__,
ep->rep_attr.cap.max_send_wr,
ep->rep_attr.cap.max_recv_wr,
ep->rep_attr.cap.max_send_sge,
ep->rep_attr.cap.max_recv_sge);
ep->rep_cqinit = ep->rep_attr.cap.max_send_wr/2 - 1;
if (ep->rep_cqinit <= 2)
ep->rep_cqinit = 0;
rpcrdma_init_cqcount(ep, 0);
init_waitqueue_head(&ep->rep_connect_wait);
INIT_DELAYED_WORK(&ep->rep_connect_worker, rpcrdma_connect_worker);
sendcq = ib_alloc_cq(ia->ri_device, NULL,
ep->rep_attr.cap.max_send_wr + 1,
0, IB_POLL_SOFTIRQ);
if (IS_ERR(sendcq)) {
rc = PTR_ERR(sendcq);
dprintk("RPC: %s: failed to create send CQ: %i\n",
__func__, rc);
goto out1;
}
recvcq = ib_alloc_cq(ia->ri_device, NULL,
ep->rep_attr.cap.max_recv_wr + 1,
0, IB_POLL_SOFTIRQ);
if (IS_ERR(recvcq)) {
rc = PTR_ERR(recvcq);
dprintk("RPC: %s: failed to create recv CQ: %i\n",
__func__, rc);
goto out2;
}
ep->rep_attr.send_cq = sendcq;
ep->rep_attr.recv_cq = recvcq;
memset(&ep->rep_remote_cma, 0, sizeof(ep->rep_remote_cma));
pmsg->cp_magic = rpcrdma_cmp_magic;
pmsg->cp_version = RPCRDMA_CMP_VERSION;
pmsg->cp_flags |= ia->ri_ops->ro_send_w_inv_ok;
pmsg->cp_send_size = rpcrdma_encode_buffer_size(cdata->inline_wsize);
pmsg->cp_recv_size = rpcrdma_encode_buffer_size(cdata->inline_rsize);
ep->rep_remote_cma.private_data = pmsg;
ep->rep_remote_cma.private_data_len = sizeof(*pmsg);
ep->rep_remote_cma.initiator_depth = 0;
if (ia->ri_device->attrs.max_qp_rd_atom > 32)
ep->rep_remote_cma.responder_resources = 32;
else
ep->rep_remote_cma.responder_resources =
ia->ri_device->attrs.max_qp_rd_atom;
ep->rep_remote_cma.retry_count = 6;
ep->rep_remote_cma.flow_control = 0;
ep->rep_remote_cma.rnr_retry_count = 0;
return 0;
out2:
ib_free_cq(sendcq);
out1:
return rc;
}
void
rpcrdma_ep_destroy(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
dprintk("RPC: %s: entering, connected is %d\n",
__func__, ep->rep_connected);
cancel_delayed_work_sync(&ep->rep_connect_worker);
if (ia->ri_id->qp) {
rpcrdma_ep_disconnect(ep, ia);
rdma_destroy_qp(ia->ri_id);
ia->ri_id->qp = NULL;
}
ib_free_cq(ep->rep_attr.recv_cq);
ib_free_cq(ep->rep_attr.send_cq);
}
static int
rpcrdma_ep_recreate_xprt(struct rpcrdma_xprt *r_xprt,
struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
struct sockaddr *sap = (struct sockaddr *)&r_xprt->rx_data.addr;
int rc, err;
pr_info("%s: r_xprt = %p\n", __func__, r_xprt);
rc = -EHOSTUNREACH;
if (rpcrdma_ia_open(r_xprt, sap))
goto out1;
rc = -ENOMEM;
err = rpcrdma_ep_create(ep, ia, &r_xprt->rx_data);
if (err) {
pr_err("rpcrdma: rpcrdma_ep_create returned %d\n", err);
goto out2;
}
rc = -ENETUNREACH;
err = rdma_create_qp(ia->ri_id, ia->ri_pd, &ep->rep_attr);
if (err) {
pr_err("rpcrdma: rdma_create_qp returned %d\n", err);
goto out3;
}
rpcrdma_create_mrs(r_xprt);
return 0;
out3:
rpcrdma_ep_destroy(ep, ia);
out2:
rpcrdma_ia_close(ia);
out1:
return rc;
}
static int
rpcrdma_ep_reconnect(struct rpcrdma_xprt *r_xprt, struct rpcrdma_ep *ep,
struct rpcrdma_ia *ia)
{
struct sockaddr *sap = (struct sockaddr *)&r_xprt->rx_data.addr;
struct rdma_cm_id *id, *old;
int err, rc;
dprintk("RPC: %s: reconnecting...\n", __func__);
rpcrdma_ep_disconnect(ep, ia);
rc = -EHOSTUNREACH;
id = rpcrdma_create_id(r_xprt, ia, sap);
if (IS_ERR(id))
goto out;
old = id;
rc = -ENETUNREACH;
if (ia->ri_device != id->device) {
pr_err("rpcrdma: can't reconnect on different device!\n");
goto out_destroy;
}
err = rdma_create_qp(id, ia->ri_pd, &ep->rep_attr);
if (err) {
dprintk("RPC: %s: rdma_create_qp returned %d\n",
__func__, err);
goto out_destroy;
}
rc = 0;
old = ia->ri_id;
ia->ri_id = id;
rdma_destroy_qp(old);
out_destroy:
rdma_destroy_id(old);
out:
return rc;
}
int
rpcrdma_ep_connect(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
struct rpcrdma_xprt *r_xprt = container_of(ia, struct rpcrdma_xprt,
rx_ia);
unsigned int extras;
int rc;
retry:
switch (ep->rep_connected) {
case 0:
dprintk("RPC: %s: connecting...\n", __func__);
rc = rdma_create_qp(ia->ri_id, ia->ri_pd, &ep->rep_attr);
if (rc) {
dprintk("RPC: %s: rdma_create_qp failed %i\n",
__func__, rc);
rc = -ENETUNREACH;
goto out_noupdate;
}
break;
case -ENODEV:
rc = rpcrdma_ep_recreate_xprt(r_xprt, ep, ia);
if (rc)
goto out_noupdate;
break;
default:
rc = rpcrdma_ep_reconnect(r_xprt, ep, ia);
if (rc)
goto out;
}
ep->rep_connected = 0;
rc = rdma_connect(ia->ri_id, &ep->rep_remote_cma);
if (rc) {
dprintk("RPC: %s: rdma_connect() failed with %i\n",
__func__, rc);
goto out;
}
wait_event_interruptible(ep->rep_connect_wait, ep->rep_connected != 0);
if (ep->rep_connected <= 0) {
if (ep->rep_connected == -EAGAIN)
goto retry;
rc = ep->rep_connected;
goto out;
}
dprintk("RPC: %s: connected\n", __func__);
extras = r_xprt->rx_buf.rb_bc_srv_max_requests;
if (extras)
rpcrdma_ep_post_extra_recv(r_xprt, extras);
out:
if (rc)
ep->rep_connected = rc;
out_noupdate:
return rc;
}
void
rpcrdma_ep_disconnect(struct rpcrdma_ep *ep, struct rpcrdma_ia *ia)
{
int rc;
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
ib_drain_qp(ia->ri_id->qp);
}
static void
rpcrdma_mr_recovery_worker(struct work_struct *work)
{
struct rpcrdma_buffer *buf = container_of(work, struct rpcrdma_buffer,
rb_recovery_worker.work);
struct rpcrdma_mw *mw;
spin_lock(&buf->rb_recovery_lock);
while (!list_empty(&buf->rb_stale_mrs)) {
mw = rpcrdma_pop_mw(&buf->rb_stale_mrs);
spin_unlock(&buf->rb_recovery_lock);
dprintk("RPC: %s: recovering MR %p\n", __func__, mw);
mw->mw_xprt->rx_ia.ri_ops->ro_recover_mr(mw);
spin_lock(&buf->rb_recovery_lock);
}
spin_unlock(&buf->rb_recovery_lock);
}
void
rpcrdma_defer_mr_recovery(struct rpcrdma_mw *mw)
{
struct rpcrdma_xprt *r_xprt = mw->mw_xprt;
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
spin_lock(&buf->rb_recovery_lock);
rpcrdma_push_mw(mw, &buf->rb_stale_mrs);
spin_unlock(&buf->rb_recovery_lock);
schedule_delayed_work(&buf->rb_recovery_worker, 0);
}
static void
rpcrdma_create_mrs(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
unsigned int count;
LIST_HEAD(free);
LIST_HEAD(all);
for (count = 0; count < 32; count++) {
struct rpcrdma_mw *mw;
int rc;
mw = kzalloc(sizeof(*mw), GFP_KERNEL);
if (!mw)
break;
rc = ia->ri_ops->ro_init_mr(ia, mw);
if (rc) {
kfree(mw);
break;
}
mw->mw_xprt = r_xprt;
list_add(&mw->mw_list, &free);
list_add(&mw->mw_all, &all);
}
spin_lock(&buf->rb_mwlock);
list_splice(&free, &buf->rb_mws);
list_splice(&all, &buf->rb_all);
r_xprt->rx_stats.mrs_allocated += count;
spin_unlock(&buf->rb_mwlock);
dprintk("RPC: %s: created %u MRs\n", __func__, count);
}
static void
rpcrdma_mr_refresh_worker(struct work_struct *work)
{
struct rpcrdma_buffer *buf = container_of(work, struct rpcrdma_buffer,
rb_refresh_worker.work);
struct rpcrdma_xprt *r_xprt = container_of(buf, struct rpcrdma_xprt,
rx_buf);
rpcrdma_create_mrs(r_xprt);
}
struct rpcrdma_req *
rpcrdma_create_req(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buffer = &r_xprt->rx_buf;
struct rpcrdma_req *req;
req = kzalloc(sizeof(*req), GFP_KERNEL);
if (req == NULL)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&req->rl_free);
spin_lock(&buffer->rb_reqslock);
list_add(&req->rl_all, &buffer->rb_allreqs);
spin_unlock(&buffer->rb_reqslock);
req->rl_cqe.done = rpcrdma_wc_send;
req->rl_buffer = &r_xprt->rx_buf;
INIT_LIST_HEAD(&req->rl_registered);
req->rl_send_wr.next = NULL;
req->rl_send_wr.wr_cqe = &req->rl_cqe;
req->rl_send_wr.sg_list = req->rl_send_sge;
req->rl_send_wr.opcode = IB_WR_SEND;
return req;
}
struct rpcrdma_rep *
rpcrdma_create_rep(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
struct rpcrdma_rep *rep;
int rc;
rc = -ENOMEM;
rep = kzalloc(sizeof(*rep), GFP_KERNEL);
if (rep == NULL)
goto out;
rep->rr_rdmabuf = rpcrdma_alloc_regbuf(cdata->inline_rsize,
DMA_FROM_DEVICE, GFP_KERNEL);
if (IS_ERR(rep->rr_rdmabuf)) {
rc = PTR_ERR(rep->rr_rdmabuf);
goto out_free;
}
rep->rr_cqe.done = rpcrdma_wc_receive;
rep->rr_rxprt = r_xprt;
INIT_WORK(&rep->rr_work, rpcrdma_reply_handler);
rep->rr_recv_wr.next = NULL;
rep->rr_recv_wr.wr_cqe = &rep->rr_cqe;
rep->rr_recv_wr.sg_list = &rep->rr_rdmabuf->rg_iov;
rep->rr_recv_wr.num_sge = 1;
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
int i, rc;
buf->rb_max_requests = r_xprt->rx_data.max_requests;
buf->rb_bc_srv_max_requests = 0;
atomic_set(&buf->rb_credits, 1);
spin_lock_init(&buf->rb_mwlock);
spin_lock_init(&buf->rb_lock);
spin_lock_init(&buf->rb_recovery_lock);
INIT_LIST_HEAD(&buf->rb_mws);
INIT_LIST_HEAD(&buf->rb_all);
INIT_LIST_HEAD(&buf->rb_stale_mrs);
INIT_DELAYED_WORK(&buf->rb_refresh_worker,
rpcrdma_mr_refresh_worker);
INIT_DELAYED_WORK(&buf->rb_recovery_worker,
rpcrdma_mr_recovery_worker);
rpcrdma_create_mrs(r_xprt);
INIT_LIST_HEAD(&buf->rb_send_bufs);
INIT_LIST_HEAD(&buf->rb_allreqs);
spin_lock_init(&buf->rb_reqslock);
for (i = 0; i < buf->rb_max_requests; i++) {
struct rpcrdma_req *req;
req = rpcrdma_create_req(r_xprt);
if (IS_ERR(req)) {
dprintk("RPC: %s: request buffer %d alloc"
" failed\n", __func__, i);
rc = PTR_ERR(req);
goto out;
}
req->rl_backchannel = false;
list_add(&req->rl_free, &buf->rb_send_bufs);
}
INIT_LIST_HEAD(&buf->rb_recv_bufs);
for (i = 0; i < buf->rb_max_requests + RPCRDMA_MAX_BC_REQUESTS; i++) {
struct rpcrdma_rep *rep;
rep = rpcrdma_create_rep(r_xprt);
if (IS_ERR(rep)) {
dprintk("RPC: %s: reply buffer %d alloc failed\n",
__func__, i);
rc = PTR_ERR(rep);
goto out;
}
list_add(&rep->rr_list, &buf->rb_recv_bufs);
}
return 0;
out:
rpcrdma_buffer_destroy(buf);
return rc;
}
static struct rpcrdma_req *
rpcrdma_buffer_get_req_locked(struct rpcrdma_buffer *buf)
{
struct rpcrdma_req *req;
req = list_first_entry(&buf->rb_send_bufs,
struct rpcrdma_req, rl_free);
list_del(&req->rl_free);
return req;
}
static struct rpcrdma_rep *
rpcrdma_buffer_get_rep_locked(struct rpcrdma_buffer *buf)
{
struct rpcrdma_rep *rep;
rep = list_first_entry(&buf->rb_recv_bufs,
struct rpcrdma_rep, rr_list);
list_del(&rep->rr_list);
return rep;
}
static void
rpcrdma_destroy_rep(struct rpcrdma_rep *rep)
{
rpcrdma_free_regbuf(rep->rr_rdmabuf);
kfree(rep);
}
void
rpcrdma_destroy_req(struct rpcrdma_req *req)
{
rpcrdma_free_regbuf(req->rl_recvbuf);
rpcrdma_free_regbuf(req->rl_sendbuf);
rpcrdma_free_regbuf(req->rl_rdmabuf);
kfree(req);
}
static void
rpcrdma_destroy_mrs(struct rpcrdma_buffer *buf)
{
struct rpcrdma_xprt *r_xprt = container_of(buf, struct rpcrdma_xprt,
rx_buf);
struct rpcrdma_ia *ia = rdmab_to_ia(buf);
struct rpcrdma_mw *mw;
unsigned int count;
count = 0;
spin_lock(&buf->rb_mwlock);
while (!list_empty(&buf->rb_all)) {
mw = list_entry(buf->rb_all.next, struct rpcrdma_mw, mw_all);
list_del(&mw->mw_all);
spin_unlock(&buf->rb_mwlock);
ia->ri_ops->ro_release_mr(mw);
count++;
spin_lock(&buf->rb_mwlock);
}
spin_unlock(&buf->rb_mwlock);
r_xprt->rx_stats.mrs_allocated = 0;
dprintk("RPC: %s: released %u MRs\n", __func__, count);
}
void
rpcrdma_buffer_destroy(struct rpcrdma_buffer *buf)
{
cancel_delayed_work_sync(&buf->rb_recovery_worker);
cancel_delayed_work_sync(&buf->rb_refresh_worker);
while (!list_empty(&buf->rb_recv_bufs)) {
struct rpcrdma_rep *rep;
rep = rpcrdma_buffer_get_rep_locked(buf);
rpcrdma_destroy_rep(rep);
}
buf->rb_send_count = 0;
spin_lock(&buf->rb_reqslock);
while (!list_empty(&buf->rb_allreqs)) {
struct rpcrdma_req *req;
req = list_first_entry(&buf->rb_allreqs,
struct rpcrdma_req, rl_all);
list_del(&req->rl_all);
spin_unlock(&buf->rb_reqslock);
rpcrdma_destroy_req(req);
spin_lock(&buf->rb_reqslock);
}
spin_unlock(&buf->rb_reqslock);
buf->rb_recv_count = 0;
rpcrdma_destroy_mrs(buf);
}
struct rpcrdma_mw *
rpcrdma_get_mw(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_mw *mw = NULL;
spin_lock(&buf->rb_mwlock);
if (!list_empty(&buf->rb_mws))
mw = rpcrdma_pop_mw(&buf->rb_mws);
spin_unlock(&buf->rb_mwlock);
if (!mw)
goto out_nomws;
return mw;
out_nomws:
dprintk("RPC: %s: no MWs available\n", __func__);
if (r_xprt->rx_ep.rep_connected != -ENODEV)
schedule_delayed_work(&buf->rb_refresh_worker, 0);
cond_resched();
return NULL;
}
void
rpcrdma_put_mw(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mw *mw)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
spin_lock(&buf->rb_mwlock);
rpcrdma_push_mw(mw, &buf->rb_mws);
spin_unlock(&buf->rb_mwlock);
}
static struct rpcrdma_rep *
rpcrdma_buffer_get_rep(struct rpcrdma_buffer *buffers)
{
if (unlikely(buffers->rb_send_count < buffers->rb_recv_count))
return NULL;
if (unlikely(list_empty(&buffers->rb_recv_bufs)))
return NULL;
buffers->rb_recv_count++;
return rpcrdma_buffer_get_rep_locked(buffers);
}
struct rpcrdma_req *
rpcrdma_buffer_get(struct rpcrdma_buffer *buffers)
{
struct rpcrdma_req *req;
spin_lock(&buffers->rb_lock);
if (list_empty(&buffers->rb_send_bufs))
goto out_reqbuf;
buffers->rb_send_count++;
req = rpcrdma_buffer_get_req_locked(buffers);
req->rl_reply = rpcrdma_buffer_get_rep(buffers);
spin_unlock(&buffers->rb_lock);
return req;
out_reqbuf:
spin_unlock(&buffers->rb_lock);
pr_warn("RPC: %s: out of request buffers\n", __func__);
return NULL;
}
void
rpcrdma_buffer_put(struct rpcrdma_req *req)
{
struct rpcrdma_buffer *buffers = req->rl_buffer;
struct rpcrdma_rep *rep = req->rl_reply;
req->rl_send_wr.num_sge = 0;
req->rl_reply = NULL;
spin_lock(&buffers->rb_lock);
buffers->rb_send_count--;
list_add_tail(&req->rl_free, &buffers->rb_send_bufs);
if (rep) {
buffers->rb_recv_count--;
list_add_tail(&rep->rr_list, &buffers->rb_recv_bufs);
}
spin_unlock(&buffers->rb_lock);
}
void
rpcrdma_recv_buffer_get(struct rpcrdma_req *req)
{
struct rpcrdma_buffer *buffers = req->rl_buffer;
spin_lock(&buffers->rb_lock);
req->rl_reply = rpcrdma_buffer_get_rep(buffers);
spin_unlock(&buffers->rb_lock);
}
void
rpcrdma_recv_buffer_put(struct rpcrdma_rep *rep)
{
struct rpcrdma_buffer *buffers = &rep->rr_rxprt->rx_buf;
spin_lock(&buffers->rb_lock);
buffers->rb_recv_count--;
list_add_tail(&rep->rr_list, &buffers->rb_recv_bufs);
spin_unlock(&buffers->rb_lock);
}
struct rpcrdma_regbuf *
rpcrdma_alloc_regbuf(size_t size, enum dma_data_direction direction,
gfp_t flags)
{
struct rpcrdma_regbuf *rb;
rb = kmalloc(sizeof(*rb) + size, flags);
if (rb == NULL)
return ERR_PTR(-ENOMEM);
rb->rg_device = NULL;
rb->rg_direction = direction;
rb->rg_iov.length = size;
return rb;
}
bool
__rpcrdma_dma_map_regbuf(struct rpcrdma_ia *ia, struct rpcrdma_regbuf *rb)
{
struct ib_device *device = ia->ri_device;
if (rb->rg_direction == DMA_NONE)
return false;
rb->rg_iov.addr = ib_dma_map_single(device,
(void *)rb->rg_base,
rdmab_length(rb),
rb->rg_direction);
if (ib_dma_mapping_error(device, rdmab_addr(rb)))
return false;
rb->rg_device = device;
rb->rg_iov.lkey = ia->ri_pd->local_dma_lkey;
return true;
}
static void
rpcrdma_dma_unmap_regbuf(struct rpcrdma_regbuf *rb)
{
if (!rpcrdma_regbuf_is_mapped(rb))
return;
ib_dma_unmap_single(rb->rg_device, rdmab_addr(rb),
rdmab_length(rb), rb->rg_direction);
rb->rg_device = NULL;
}
void
rpcrdma_free_regbuf(struct rpcrdma_regbuf *rb)
{
if (!rb)
return;
rpcrdma_dma_unmap_regbuf(rb);
kfree(rb);
}
int
rpcrdma_ep_post(struct rpcrdma_ia *ia,
struct rpcrdma_ep *ep,
struct rpcrdma_req *req)
{
struct ib_send_wr *send_wr = &req->rl_send_wr;
struct ib_send_wr *send_wr_fail;
int rc;
if (req->rl_reply) {
rc = rpcrdma_ep_post_recv(ia, req->rl_reply);
if (rc)
return rc;
req->rl_reply = NULL;
}
dprintk("RPC: %s: posting %d s/g entries\n",
__func__, send_wr->num_sge);
rpcrdma_set_signaled(ep, send_wr);
rc = ib_post_send(ia->ri_id->qp, send_wr, &send_wr_fail);
if (rc)
goto out_postsend_err;
return 0;
out_postsend_err:
pr_err("rpcrdma: RDMA Send ib_post_send returned %i\n", rc);
return -ENOTCONN;
}
int
rpcrdma_ep_post_recv(struct rpcrdma_ia *ia,
struct rpcrdma_rep *rep)
{
struct ib_recv_wr *recv_wr_fail;
int rc;
if (!rpcrdma_dma_map_regbuf(ia, rep->rr_rdmabuf))
goto out_map;
rc = ib_post_recv(ia->ri_id->qp, &rep->rr_recv_wr, &recv_wr_fail);
if (rc)
goto out_postrecv;
return 0;
out_map:
pr_err("rpcrdma: failed to DMA map the Receive buffer\n");
return -EIO;
out_postrecv:
pr_err("rpcrdma: ib_post_recv returned %i\n", rc);
return -ENOTCONN;
}
int
rpcrdma_ep_post_extra_recv(struct rpcrdma_xprt *r_xprt, unsigned int count)
{
struct rpcrdma_buffer *buffers = &r_xprt->rx_buf;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_rep *rep;
int rc;
while (count--) {
spin_lock(&buffers->rb_lock);
if (list_empty(&buffers->rb_recv_bufs))
goto out_reqbuf;
rep = rpcrdma_buffer_get_rep_locked(buffers);
spin_unlock(&buffers->rb_lock);
rc = rpcrdma_ep_post_recv(ia, rep);
if (rc)
goto out_rc;
}
return 0;
out_reqbuf:
spin_unlock(&buffers->rb_lock);
pr_warn("%s: no extra receive buffers\n", __func__);
return -ENOMEM;
out_rc:
rpcrdma_recv_buffer_put(rep);
return rc;
}
