int svc_rdma_handle_bc_reply(struct rpc_xprt *xprt, __be32 *rdma_resp,
struct xdr_buf *rcvbuf)
{
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct kvec *dst, *src = &rcvbuf->head[0];
struct rpc_rqst *req;
unsigned long cwnd;
u32 credits;
size_t len;
__be32 xid;
__be32 *p;
int ret;
p = (__be32 *)src->iov_base;
len = src->iov_len;
xid = *rdma_resp;
#ifdef SVCRDMA_BACKCHANNEL_DEBUG
pr_info("%s: xid=%08x, length=%zu\n",
__func__, be32_to_cpu(xid), len);
pr_info("%s: RPC/RDMA: %*ph\n",
__func__, (int)RPCRDMA_HDRLEN_MIN, rdma_resp);
pr_info("%s: RPC: %*ph\n",
__func__, (int)len, p);
#endif
ret = -EAGAIN;
if (src->iov_len < 24)
goto out_shortreply;
spin_lock(&xprt->recv_lock);
req = xprt_lookup_rqst(xprt, xid);
if (!req)
goto out_notfound;
dst = &req->rq_private_buf.head[0];
memcpy(&req->rq_private_buf, &req->rq_rcv_buf, sizeof(struct xdr_buf));
if (dst->iov_len < len)
goto out_unlock;
memcpy(dst->iov_base, p, len);
credits = be32_to_cpup(rdma_resp + 2);
if (credits == 0)
credits = 1;
else if (credits > r_xprt->rx_buf.rb_bc_max_requests)
credits = r_xprt->rx_buf.rb_bc_max_requests;
spin_lock_bh(&xprt->transport_lock);
cwnd = xprt->cwnd;
xprt->cwnd = credits << RPC_CWNDSHIFT;
if (xprt->cwnd > cwnd)
xprt_release_rqst_cong(req->rq_task);
spin_unlock_bh(&xprt->transport_lock);
ret = 0;
xprt_complete_rqst(req->rq_task, rcvbuf->len);
rcvbuf->len = 0;
out_unlock:
spin_unlock(&xprt->recv_lock);
out:
return ret;
out_shortreply:
dprintk("svcrdma: short bc reply: xprt=%p, len=%zu\n",
xprt, src->iov_len);
goto out;
out_notfound:
dprintk("svcrdma: unrecognized bc reply: xprt=%p, xid=%08x\n",
xprt, be32_to_cpu(xid));
goto out_unlock;
}
static int svc_rdma_bc_sendto(struct svcxprt_rdma *rdma,
struct rpc_rqst *rqst)
{
struct svc_rdma_op_ctxt *ctxt;
int ret;
ctxt = svc_rdma_get_context(rdma);
ret = svc_rdma_map_reply_hdr(rdma, ctxt, rqst->rq_buffer,
rqst->rq_snd_buf.len);
if (ret < 0)
goto out_err;
ret = svc_rdma_repost_recv(rdma, GFP_NOIO);
if (ret)
goto out_err;
ret = svc_rdma_post_send_wr(rdma, ctxt, 1, 0);
if (ret)
goto out_unmap;
out_err:
dprintk("svcrdma: %s returns %d\n", __func__, ret);
return ret;
out_unmap:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
ret = -EIO;
goto out_err;
}
static int
xprt_rdma_bc_allocate(struct rpc_task *task)
{
struct rpc_rqst *rqst = task->tk_rqstp;
size_t size = rqst->rq_callsize;
struct page *page;
if (size > PAGE_SIZE) {
WARN_ONCE(1, "svcrdma: large bc buffer request (size %zu)\n",
size);
return -EINVAL;
}
page = alloc_page(RPCRDMA_DEF_GFP);
if (!page)
return -ENOMEM;
rqst->rq_buffer = page_address(page);
rqst->rq_rbuffer = kmalloc(rqst->rq_rcvsize, RPCRDMA_DEF_GFP);
if (!rqst->rq_rbuffer) {
put_page(page);
return -ENOMEM;
}
return 0;
}
static void
xprt_rdma_bc_free(struct rpc_task *task)
{
struct rpc_rqst *rqst = task->tk_rqstp;
kfree(rqst->rq_rbuffer);
}
static int
rpcrdma_bc_send_request(struct svcxprt_rdma *rdma, struct rpc_rqst *rqst)
{
struct rpc_xprt *xprt = rqst->rq_xprt;
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
__be32 *p;
int rc;
p = rqst->rq_buffer;
*p++ = rqst->rq_xid;
*p++ = rpcrdma_version;
*p++ = cpu_to_be32(r_xprt->rx_buf.rb_bc_max_requests);
*p++ = rdma_msg;
*p++ = xdr_zero;
*p++ = xdr_zero;
*p = xdr_zero;
#ifdef SVCRDMA_BACKCHANNEL_DEBUG
pr_info("%s: %*ph\n", __func__, 64, rqst->rq_buffer);
#endif
rc = svc_rdma_bc_sendto(rdma, rqst);
if (rc)
goto drop_connection;
return rc;
drop_connection:
dprintk("svcrdma: failed to send bc call\n");
xprt_disconnect_done(xprt);
return -ENOTCONN;
}
static int
xprt_rdma_bc_send_request(struct rpc_task *task)
{
struct rpc_rqst *rqst = task->tk_rqstp;
struct svc_xprt *sxprt = rqst->rq_xprt->bc_xprt;
struct svcxprt_rdma *rdma;
int ret;
dprintk("svcrdma: sending bc call with xid: %08x\n",
be32_to_cpu(rqst->rq_xid));
if (!mutex_trylock(&sxprt->xpt_mutex)) {
rpc_sleep_on(&sxprt->xpt_bc_pending, task, NULL);
if (!mutex_trylock(&sxprt->xpt_mutex))
return -EAGAIN;
rpc_wake_up_queued_task(&sxprt->xpt_bc_pending, task);
}
ret = -ENOTCONN;
rdma = container_of(sxprt, struct svcxprt_rdma, sc_xprt);
if (!test_bit(XPT_DEAD, &sxprt->xpt_flags))
ret = rpcrdma_bc_send_request(rdma, rqst);
mutex_unlock(&sxprt->xpt_mutex);
if (ret < 0)
return ret;
return 0;
}
static void
xprt_rdma_bc_close(struct rpc_xprt *xprt)
{
dprintk("svcrdma: %s: xprt %p\n", __func__, xprt);
}
static void
xprt_rdma_bc_put(struct rpc_xprt *xprt)
{
dprintk("svcrdma: %s: xprt %p\n", __func__, xprt);
xprt_free(xprt);
module_put(THIS_MODULE);
}
static struct rpc_xprt *
xprt_setup_rdma_bc(struct xprt_create *args)
{
struct rpc_xprt *xprt;
struct rpcrdma_xprt *new_xprt;
if (args->addrlen > sizeof(xprt->addr)) {
dprintk("RPC: %s: address too large\n", __func__);
return ERR_PTR(-EBADF);
}
xprt = xprt_alloc(args->net, sizeof(*new_xprt),
RPCRDMA_MAX_BC_REQUESTS,
RPCRDMA_MAX_BC_REQUESTS);
if (!xprt) {
dprintk("RPC: %s: couldn't allocate rpc_xprt\n",
__func__);
return ERR_PTR(-ENOMEM);
}
xprt->timeout = &xprt_rdma_bc_timeout;
xprt_set_bound(xprt);
xprt_set_connected(xprt);
xprt->bind_timeout = RPCRDMA_BIND_TO;
xprt->reestablish_timeout = RPCRDMA_INIT_REEST_TO;
xprt->idle_timeout = RPCRDMA_IDLE_DISC_TO;
xprt->prot = XPRT_TRANSPORT_BC_RDMA;
xprt->tsh_size = RPCRDMA_HDRLEN_MIN / sizeof(__be32);
xprt->ops = &xprt_rdma_bc_procs;
memcpy(&xprt->addr, args->dstaddr, args->addrlen);
xprt->addrlen = args->addrlen;
xprt_rdma_format_addresses(xprt, (struct sockaddr *)&xprt->addr);
xprt->resvport = 0;
xprt->max_payload = xprt_rdma_max_inline_read;
new_xprt = rpcx_to_rdmax(xprt);
new_xprt->rx_buf.rb_bc_max_requests = xprt->max_reqs;
xprt_get(xprt);
args->bc_xprt->xpt_bc_xprt = xprt;
xprt->bc_xprt = args->bc_xprt;
if (!try_module_get(THIS_MODULE))
goto out_fail;
xprt_get(xprt);
return xprt;
out_fail:
xprt_rdma_free_addresses(xprt);
args->bc_xprt->xpt_bc_xprt = NULL;
args->bc_xprt->xpt_bc_xps = NULL;
xprt_put(xprt);
xprt_free(xprt);
return ERR_PTR(-EINVAL);
}
