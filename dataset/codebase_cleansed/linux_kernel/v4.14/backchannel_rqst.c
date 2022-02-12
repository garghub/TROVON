static inline int xprt_need_to_requeue(struct rpc_xprt *xprt)
{
return xprt->bc_alloc_count < atomic_read(&xprt->bc_free_slots);
}
static inline void xprt_inc_alloc_count(struct rpc_xprt *xprt, unsigned int n)
{
atomic_add(n, &xprt->bc_free_slots);
xprt->bc_alloc_count += n;
}
static inline int xprt_dec_alloc_count(struct rpc_xprt *xprt, unsigned int n)
{
atomic_sub(n, &xprt->bc_free_slots);
return xprt->bc_alloc_count -= n;
}
static void xprt_free_allocation(struct rpc_rqst *req)
{
struct xdr_buf *xbufp;
dprintk("RPC: free allocations for req= %p\n", req);
WARN_ON_ONCE(test_bit(RPC_BC_PA_IN_USE, &req->rq_bc_pa_state));
xbufp = &req->rq_rcv_buf;
free_page((unsigned long)xbufp->head[0].iov_base);
xbufp = &req->rq_snd_buf;
free_page((unsigned long)xbufp->head[0].iov_base);
kfree(req);
}
static int xprt_alloc_xdr_buf(struct xdr_buf *buf, gfp_t gfp_flags)
{
struct page *page;
page = alloc_page(gfp_flags);
if (page == NULL)
return -ENOMEM;
xdr_buf_init(buf, page_address(page), PAGE_SIZE);
return 0;
}
static
struct rpc_rqst *xprt_alloc_bc_req(struct rpc_xprt *xprt, gfp_t gfp_flags)
{
struct rpc_rqst *req;
req = kzalloc(sizeof(*req), gfp_flags);
if (req == NULL)
return NULL;
req->rq_xprt = xprt;
INIT_LIST_HEAD(&req->rq_list);
INIT_LIST_HEAD(&req->rq_bc_list);
if (xprt_alloc_xdr_buf(&req->rq_rcv_buf, gfp_flags) < 0) {
printk(KERN_ERR "Failed to create bc receive xbuf\n");
goto out_free;
}
req->rq_rcv_buf.len = PAGE_SIZE;
if (xprt_alloc_xdr_buf(&req->rq_snd_buf, gfp_flags) < 0) {
printk(KERN_ERR "Failed to create bc snd xbuf\n");
goto out_free;
}
return req;
out_free:
xprt_free_allocation(req);
return NULL;
}
int xprt_setup_backchannel(struct rpc_xprt *xprt, unsigned int min_reqs)
{
if (!xprt->ops->bc_setup)
return 0;
return xprt->ops->bc_setup(xprt, min_reqs);
}
int xprt_setup_bc(struct rpc_xprt *xprt, unsigned int min_reqs)
{
struct rpc_rqst *req;
struct list_head tmp_list;
int i;
dprintk("RPC: setup backchannel transport\n");
INIT_LIST_HEAD(&tmp_list);
for (i = 0; i < min_reqs; i++) {
req = xprt_alloc_bc_req(xprt, GFP_KERNEL);
if (req == NULL) {
printk(KERN_ERR "Failed to create bc rpc_rqst\n");
goto out_free;
}
dprintk("RPC: adding req= %p\n", req);
list_add(&req->rq_bc_pa_list, &tmp_list);
}
spin_lock(&xprt->bc_pa_lock);
list_splice(&tmp_list, &xprt->bc_pa_list);
xprt_inc_alloc_count(xprt, min_reqs);
spin_unlock(&xprt->bc_pa_lock);
dprintk("RPC: setup backchannel transport done\n");
return 0;
out_free:
while (!list_empty(&tmp_list)) {
req = list_first_entry(&tmp_list,
struct rpc_rqst,
rq_bc_pa_list);
list_del(&req->rq_bc_pa_list);
xprt_free_allocation(req);
}
dprintk("RPC: setup backchannel transport failed\n");
return -ENOMEM;
}
void xprt_destroy_backchannel(struct rpc_xprt *xprt, unsigned int max_reqs)
{
if (xprt->ops->bc_destroy)
xprt->ops->bc_destroy(xprt, max_reqs);
}
void xprt_destroy_bc(struct rpc_xprt *xprt, unsigned int max_reqs)
{
struct rpc_rqst *req = NULL, *tmp = NULL;
dprintk("RPC: destroy backchannel transport\n");
if (max_reqs == 0)
goto out;
spin_lock_bh(&xprt->bc_pa_lock);
xprt_dec_alloc_count(xprt, max_reqs);
list_for_each_entry_safe(req, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
dprintk("RPC: req=%p\n", req);
list_del(&req->rq_bc_pa_list);
xprt_free_allocation(req);
if (--max_reqs == 0)
break;
}
spin_unlock_bh(&xprt->bc_pa_lock);
out:
dprintk("RPC: backchannel list empty= %s\n",
list_empty(&xprt->bc_pa_list) ? "true" : "false");
}
static struct rpc_rqst *xprt_alloc_bc_request(struct rpc_xprt *xprt, __be32 xid)
{
struct rpc_rqst *req = NULL;
dprintk("RPC: allocate a backchannel request\n");
if (atomic_read(&xprt->bc_free_slots) <= 0)
goto not_found;
if (list_empty(&xprt->bc_pa_list)) {
req = xprt_alloc_bc_req(xprt, GFP_ATOMIC);
if (!req)
goto not_found;
list_add_tail(&req->rq_bc_pa_list, &xprt->bc_pa_list);
xprt->bc_alloc_count++;
}
req = list_first_entry(&xprt->bc_pa_list, struct rpc_rqst,
rq_bc_pa_list);
req->rq_reply_bytes_recvd = 0;
req->rq_bytes_sent = 0;
memcpy(&req->rq_private_buf, &req->rq_rcv_buf,
sizeof(req->rq_private_buf));
req->rq_xid = xid;
req->rq_connect_cookie = xprt->connect_cookie;
not_found:
dprintk("RPC: backchannel req=%p\n", req);
return req;
}
void xprt_free_bc_request(struct rpc_rqst *req)
{
struct rpc_xprt *xprt = req->rq_xprt;
xprt->ops->bc_free_rqst(req);
}
void xprt_free_bc_rqst(struct rpc_rqst *req)
{
struct rpc_xprt *xprt = req->rq_xprt;
dprintk("RPC: free backchannel req=%p\n", req);
req->rq_connect_cookie = xprt->connect_cookie - 1;
smp_mb__before_atomic();
clear_bit(RPC_BC_PA_IN_USE, &req->rq_bc_pa_state);
smp_mb__after_atomic();
spin_lock_bh(&xprt->bc_pa_lock);
if (xprt_need_to_requeue(xprt)) {
list_add_tail(&req->rq_bc_pa_list, &xprt->bc_pa_list);
xprt->bc_alloc_count++;
req = NULL;
}
spin_unlock_bh(&xprt->bc_pa_lock);
if (req != NULL) {
dprintk("RPC: Last session removed req=%p\n", req);
xprt_free_allocation(req);
return;
}
}
struct rpc_rqst *xprt_lookup_bc_request(struct rpc_xprt *xprt, __be32 xid)
{
struct rpc_rqst *req;
spin_lock(&xprt->bc_pa_lock);
list_for_each_entry(req, &xprt->bc_pa_list, rq_bc_pa_list) {
if (req->rq_connect_cookie != xprt->connect_cookie)
continue;
if (req->rq_xid == xid)
goto found;
}
req = xprt_alloc_bc_request(xprt, xid);
found:
spin_unlock(&xprt->bc_pa_lock);
return req;
}
void xprt_complete_bc_request(struct rpc_rqst *req, uint32_t copied)
{
struct rpc_xprt *xprt = req->rq_xprt;
struct svc_serv *bc_serv = xprt->bc_serv;
spin_lock(&xprt->bc_pa_lock);
list_del(&req->rq_bc_pa_list);
xprt_dec_alloc_count(xprt, 1);
spin_unlock(&xprt->bc_pa_lock);
req->rq_private_buf.len = copied;
set_bit(RPC_BC_PA_IN_USE, &req->rq_bc_pa_state);
dprintk("RPC: add callback request to list\n");
spin_lock(&bc_serv->sv_cb_lock);
list_add(&req->rq_bc_list, &bc_serv->sv_cb_list);
wake_up(&bc_serv->sv_cb_waitq);
spin_unlock(&bc_serv->sv_cb_lock);
}
