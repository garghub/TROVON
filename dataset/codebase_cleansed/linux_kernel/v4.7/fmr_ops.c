int
fmr_alloc_recovery_wq(void)
{
fmr_recovery_wq = alloc_workqueue("fmr_recovery", WQ_UNBOUND, 0);
return !fmr_recovery_wq ? -ENOMEM : 0;
}
void
fmr_destroy_recovery_wq(void)
{
struct workqueue_struct *wq;
if (!fmr_recovery_wq)
return;
wq = fmr_recovery_wq;
fmr_recovery_wq = NULL;
destroy_workqueue(wq);
}
static int
__fmr_unmap(struct rpcrdma_mw *mw)
{
LIST_HEAD(l);
list_add(&mw->fmr.fmr->list, &l);
return ib_unmap_fmr(&l);
}
static void
__fmr_recovery_worker(struct work_struct *work)
{
struct rpcrdma_mw *mw = container_of(work, struct rpcrdma_mw,
mw_work);
struct rpcrdma_xprt *r_xprt = mw->mw_xprt;
__fmr_unmap(mw);
rpcrdma_put_mw(r_xprt, mw);
return;
}
static void
__fmr_queue_recovery(struct rpcrdma_mw *mw)
{
INIT_WORK(&mw->mw_work, __fmr_recovery_worker);
queue_work(fmr_recovery_wq, &mw->mw_work);
}
static int
fmr_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
rpcrdma_set_max_header_sizes(ia, cdata, max_t(unsigned int, 1,
RPCRDMA_MAX_DATA_SEGS /
RPCRDMA_MAX_FMR_SGES));
return 0;
}
static size_t
fmr_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * RPCRDMA_MAX_FMR_SGES);
}
static int
fmr_op_init(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
int mr_access_flags = IB_ACCESS_REMOTE_WRITE | IB_ACCESS_REMOTE_READ;
struct ib_fmr_attr fmr_attr = {
.max_pages = RPCRDMA_MAX_FMR_SGES,
.max_maps = 1,
.page_shift = PAGE_SHIFT
};
struct ib_pd *pd = r_xprt->rx_ia.ri_pd;
struct rpcrdma_mw *r;
int i, rc;
spin_lock_init(&buf->rb_mwlock);
INIT_LIST_HEAD(&buf->rb_mws);
INIT_LIST_HEAD(&buf->rb_all);
i = max_t(int, RPCRDMA_MAX_DATA_SEGS / RPCRDMA_MAX_FMR_SGES, 1);
i += 2;
i *= buf->rb_max_requests;
dprintk("RPC: %s: initalizing %d FMRs\n", __func__, i);
rc = -ENOMEM;
while (i--) {
r = kzalloc(sizeof(*r), GFP_KERNEL);
if (!r)
goto out;
r->fmr.physaddrs = kmalloc(RPCRDMA_MAX_FMR_SGES *
sizeof(u64), GFP_KERNEL);
if (!r->fmr.physaddrs)
goto out_free;
r->fmr.fmr = ib_alloc_fmr(pd, mr_access_flags, &fmr_attr);
if (IS_ERR(r->fmr.fmr))
goto out_fmr_err;
r->mw_xprt = r_xprt;
list_add(&r->mw_list, &buf->rb_mws);
list_add(&r->mw_all, &buf->rb_all);
}
return 0;
out_fmr_err:
rc = PTR_ERR(r->fmr.fmr);
dprintk("RPC: %s: ib_alloc_fmr status %i\n", __func__, rc);
kfree(r->fmr.physaddrs);
out_free:
kfree(r);
out:
return rc;
}
static int
fmr_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct ib_device *device = ia->ri_device;
enum dma_data_direction direction = rpcrdma_data_dir(writing);
struct rpcrdma_mr_seg *seg1 = seg;
int len, pageoff, i, rc;
struct rpcrdma_mw *mw;
mw = seg1->rl_mw;
seg1->rl_mw = NULL;
if (!mw) {
mw = rpcrdma_get_mw(r_xprt);
if (!mw)
return -ENOMEM;
} else {
rc = __fmr_unmap(mw);
if (rc)
return rc;
}
pageoff = offset_in_page(seg1->mr_offset);
seg1->mr_offset -= pageoff;
seg1->mr_len += pageoff;
len = -pageoff;
if (nsegs > RPCRDMA_MAX_FMR_SGES)
nsegs = RPCRDMA_MAX_FMR_SGES;
for (i = 0; i < nsegs;) {
rpcrdma_map_one(device, seg, direction);
mw->fmr.physaddrs[i] = seg->mr_dma;
len += seg->mr_len;
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
rc = ib_map_phys_fmr(mw->fmr.fmr, mw->fmr.physaddrs,
i, seg1->mr_dma);
if (rc)
goto out_maperr;
seg1->rl_mw = mw;
seg1->mr_rkey = mw->fmr.fmr->rkey;
seg1->mr_base = seg1->mr_dma + pageoff;
seg1->mr_nsegs = i;
seg1->mr_len = len;
return i;
out_maperr:
dprintk("RPC: %s: ib_map_phys_fmr %u@0x%llx+%i (%d) status %i\n",
__func__, len, (unsigned long long)seg1->mr_dma,
pageoff, i, rc);
while (i--)
rpcrdma_unmap_one(device, --seg);
return rc;
}
static void
__fmr_dma_unmap(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg)
{
struct ib_device *device = r_xprt->rx_ia.ri_device;
int nsegs = seg->mr_nsegs;
while (nsegs--)
rpcrdma_unmap_one(device, seg++);
}
static void
fmr_op_unmap_sync(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req)
{
struct rpcrdma_mr_seg *seg;
unsigned int i, nchunks;
struct rpcrdma_mw *mw;
LIST_HEAD(unmap_list);
int rc;
dprintk("RPC: %s: req %p\n", __func__, req);
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
mw = seg->rl_mw;
list_add(&mw->fmr.fmr->list, &unmap_list);
i += seg->mr_nsegs;
}
rc = ib_unmap_fmr(&unmap_list);
if (rc)
pr_warn("%s: ib_unmap_fmr failed (%i)\n", __func__, rc);
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
__fmr_dma_unmap(r_xprt, seg);
rpcrdma_put_mw(r_xprt, seg->rl_mw);
i += seg->mr_nsegs;
seg->mr_nsegs = 0;
seg->rl_mw = NULL;
}
req->rl_nchunks = 0;
}
static void
fmr_op_unmap_safe(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
bool sync)
{
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
unsigned int i;
for (i = 0; req->rl_nchunks; req->rl_nchunks--) {
seg = &req->rl_segments[i];
mw = seg->rl_mw;
if (sync) {
__fmr_unmap(mw);
__fmr_dma_unmap(r_xprt, seg);
rpcrdma_put_mw(r_xprt, mw);
} else {
__fmr_dma_unmap(r_xprt, seg);
__fmr_queue_recovery(mw);
}
i += seg->mr_nsegs;
seg->mr_nsegs = 0;
seg->rl_mw = NULL;
}
}
static void
fmr_op_destroy(struct rpcrdma_buffer *buf)
{
struct rpcrdma_mw *r;
int rc;
while (!list_empty(&buf->rb_all)) {
r = list_entry(buf->rb_all.next, struct rpcrdma_mw, mw_all);
list_del(&r->mw_all);
kfree(r->fmr.physaddrs);
rc = ib_dealloc_fmr(r->fmr.fmr);
if (rc)
dprintk("RPC: %s: ib_dealloc_fmr failed %i\n",
__func__, rc);
kfree(r);
}
}
