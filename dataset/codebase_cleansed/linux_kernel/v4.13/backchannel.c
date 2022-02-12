static void rpcrdma_bc_free_rqst(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_req *req = rpcr_to_rdmar(rqst);
spin_lock(&buf->rb_reqslock);
list_del(&req->rl_all);
spin_unlock(&buf->rb_reqslock);
rpcrdma_destroy_req(req);
kfree(rqst);
}
static int rpcrdma_bc_setup_rqst(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct rpcrdma_regbuf *rb;
struct rpcrdma_req *req;
size_t size;
req = rpcrdma_create_req(r_xprt);
if (IS_ERR(req))
return PTR_ERR(req);
req->rl_backchannel = true;
rb = rpcrdma_alloc_regbuf(RPCRDMA_HDRBUF_SIZE,
DMA_TO_DEVICE, GFP_KERNEL);
if (IS_ERR(rb))
goto out_fail;
req->rl_rdmabuf = rb;
size = r_xprt->rx_data.inline_rsize;
rb = rpcrdma_alloc_regbuf(size, DMA_TO_DEVICE, GFP_KERNEL);
if (IS_ERR(rb))
goto out_fail;
req->rl_sendbuf = rb;
xdr_buf_init(&rqst->rq_snd_buf, rb->rg_base,
min_t(size_t, size, PAGE_SIZE));
rpcrdma_set_xprtdata(rqst, req);
return 0;
out_fail:
rpcrdma_bc_free_rqst(r_xprt, rqst);
return -ENOMEM;
}
static int rpcrdma_bc_setup_reps(struct rpcrdma_xprt *r_xprt,
unsigned int count)
{
struct rpcrdma_rep *rep;
int rc = 0;
while (count--) {
rep = rpcrdma_create_rep(r_xprt);
if (IS_ERR(rep)) {
pr_err("RPC: %s: reply buffer alloc failed\n",
__func__);
rc = PTR_ERR(rep);
break;
}
rpcrdma_recv_buffer_put(rep);
}
return rc;
}
int xprt_rdma_bc_setup(struct rpc_xprt *xprt, unsigned int reqs)
{
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct rpcrdma_buffer *buffer = &r_xprt->rx_buf;
struct rpc_rqst *rqst;
unsigned int i;
int rc;
if (reqs > RPCRDMA_BACKWARD_WRS >> 1)
goto out_err;
for (i = 0; i < (reqs << 1); i++) {
rqst = kzalloc(sizeof(*rqst), GFP_KERNEL);
if (!rqst)
goto out_free;
dprintk("RPC: %s: new rqst %p\n", __func__, rqst);
rqst->rq_xprt = &r_xprt->rx_xprt;
INIT_LIST_HEAD(&rqst->rq_list);
INIT_LIST_HEAD(&rqst->rq_bc_list);
if (rpcrdma_bc_setup_rqst(r_xprt, rqst))
goto out_free;
spin_lock_bh(&xprt->bc_pa_lock);
list_add(&rqst->rq_bc_pa_list, &xprt->bc_pa_list);
spin_unlock_bh(&xprt->bc_pa_lock);
}
rc = rpcrdma_bc_setup_reps(r_xprt, reqs);
if (rc)
goto out_free;
rc = rpcrdma_ep_post_extra_recv(r_xprt, reqs);
if (rc)
goto out_free;
buffer->rb_bc_srv_max_requests = reqs;
request_module("svcrdma");
return 0;
out_free:
xprt_rdma_bc_destroy(xprt, reqs);
out_err:
pr_err("RPC: %s: setup backchannel transport failed\n", __func__);
return -ENOMEM;
}
int xprt_rdma_bc_up(struct svc_serv *serv, struct net *net)
{
int ret;
ret = svc_create_xprt(serv, "rdma-bc", net, PF_INET, 0, 0);
if (ret < 0)
return ret;
return 0;
}
size_t xprt_rdma_bc_maxpayload(struct rpc_xprt *xprt)
{
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
size_t maxmsg;
maxmsg = min_t(unsigned int, cdata->inline_rsize, cdata->inline_wsize);
maxmsg = min_t(unsigned int, maxmsg, PAGE_SIZE);
return maxmsg - RPCRDMA_HDRLEN_MIN;
}
int rpcrdma_bc_marshal_reply(struct rpc_rqst *rqst)
{
struct rpc_xprt *xprt = rqst->rq_xprt;
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct rpcrdma_req *req = rpcr_to_rdmar(rqst);
struct rpcrdma_msg *headerp;
headerp = rdmab_to_msg(req->rl_rdmabuf);
headerp->rm_xid = rqst->rq_xid;
headerp->rm_vers = rpcrdma_version;
headerp->rm_credit =
cpu_to_be32(r_xprt->rx_buf.rb_bc_srv_max_requests);
headerp->rm_type = rdma_msg;
headerp->rm_body.rm_chunks[0] = xdr_zero;
headerp->rm_body.rm_chunks[1] = xdr_zero;
headerp->rm_body.rm_chunks[2] = xdr_zero;
if (!rpcrdma_prepare_send_sges(&r_xprt->rx_ia, req, RPCRDMA_HDRLEN_MIN,
&rqst->rq_snd_buf, rpcrdma_noch))
return -EIO;
return 0;
}
void xprt_rdma_bc_destroy(struct rpc_xprt *xprt, unsigned int reqs)
{
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct rpc_rqst *rqst, *tmp;
spin_lock_bh(&xprt->bc_pa_lock);
list_for_each_entry_safe(rqst, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
list_del(&rqst->rq_bc_pa_list);
spin_unlock_bh(&xprt->bc_pa_lock);
rpcrdma_bc_free_rqst(r_xprt, rqst);
spin_lock_bh(&xprt->bc_pa_lock);
}
spin_unlock_bh(&xprt->bc_pa_lock);
}
void xprt_rdma_bc_free_rqst(struct rpc_rqst *rqst)
{
struct rpc_xprt *xprt = rqst->rq_xprt;
dprintk("RPC: %s: freeing rqst %p (req %p)\n",
__func__, rqst, rpcr_to_rdmar(rqst));
smp_mb__before_atomic();
WARN_ON_ONCE(!test_bit(RPC_BC_PA_IN_USE, &rqst->rq_bc_pa_state));
clear_bit(RPC_BC_PA_IN_USE, &rqst->rq_bc_pa_state);
smp_mb__after_atomic();
spin_lock_bh(&xprt->bc_pa_lock);
list_add_tail(&rqst->rq_bc_pa_list, &xprt->bc_pa_list);
spin_unlock_bh(&xprt->bc_pa_lock);
}
void rpcrdma_bc_receive_call(struct rpcrdma_xprt *r_xprt,
struct rpcrdma_rep *rep)
{
struct rpc_xprt *xprt = &r_xprt->rx_xprt;
struct rpcrdma_msg *headerp;
struct svc_serv *bc_serv;
struct rpcrdma_req *req;
struct rpc_rqst *rqst;
struct xdr_buf *buf;
size_t size;
__be32 *p;
headerp = rdmab_to_msg(rep->rr_rdmabuf);
#ifdef RPCRDMA_BACKCHANNEL_DEBUG
pr_info("RPC: %s: callback XID %08x, length=%u\n",
__func__, be32_to_cpu(headerp->rm_xid), rep->rr_len);
pr_info("RPC: %s: %*ph\n", __func__, rep->rr_len, headerp);
#endif
if (rep->rr_len < RPCRDMA_HDRLEN_MIN + 24)
goto out_short;
p = (__be32 *)((unsigned char *)headerp + RPCRDMA_HDRLEN_MIN);
size = rep->rr_len - RPCRDMA_HDRLEN_MIN;
spin_lock(&xprt->bc_pa_lock);
if (list_empty(&xprt->bc_pa_list)) {
spin_unlock(&xprt->bc_pa_lock);
goto out_overflow;
}
rqst = list_first_entry(&xprt->bc_pa_list,
struct rpc_rqst, rq_bc_pa_list);
list_del(&rqst->rq_bc_pa_list);
spin_unlock(&xprt->bc_pa_lock);
dprintk("RPC: %s: using rqst %p\n", __func__, rqst);
rqst->rq_reply_bytes_recvd = 0;
rqst->rq_bytes_sent = 0;
rqst->rq_xid = headerp->rm_xid;
rqst->rq_private_buf.len = size;
set_bit(RPC_BC_PA_IN_USE, &rqst->rq_bc_pa_state);
buf = &rqst->rq_rcv_buf;
memset(buf, 0, sizeof(*buf));
buf->head[0].iov_base = p;
buf->head[0].iov_len = size;
buf->len = size;
req = rpcr_to_rdmar(rqst);
dprintk("RPC: %s: attaching rep %p to req %p\n",
__func__, rep, req);
req->rl_reply = rep;
req->rl_connect_cookie = 0;
bc_serv = xprt->bc_serv;
spin_lock(&bc_serv->sv_cb_lock);
list_add(&rqst->rq_bc_list, &bc_serv->sv_cb_list);
spin_unlock(&bc_serv->sv_cb_lock);
wake_up(&bc_serv->sv_cb_waitq);
r_xprt->rx_stats.bcall_count++;
return;
out_overflow:
pr_warn("RPC/RDMA backchannel overflow\n");
xprt_disconnect_done(xprt);
return;
out_short:
pr_warn("RPC/RDMA short backward direction call\n");
if (rpcrdma_ep_post_recv(&r_xprt->rx_ia, rep))
xprt_disconnect_done(xprt);
else
pr_warn("RPC: %s: reposting rep %p\n",
__func__, rep);
}
