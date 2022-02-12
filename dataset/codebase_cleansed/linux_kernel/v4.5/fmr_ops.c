static int
fmr_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
return 0;
}
static size_t
fmr_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * RPCRDMA_MAX_FMR_SGES);
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
r->r.fmr.physaddrs = kmalloc(RPCRDMA_MAX_FMR_SGES *
sizeof(u64), GFP_KERNEL);
if (!r->r.fmr.physaddrs)
goto out_free;
r->r.fmr.fmr = ib_alloc_fmr(pd, mr_access_flags, &fmr_attr);
if (IS_ERR(r->r.fmr.fmr))
goto out_fmr_err;
list_add(&r->mw_list, &buf->rb_mws);
list_add(&r->mw_all, &buf->rb_all);
}
return 0;
out_fmr_err:
rc = PTR_ERR(r->r.fmr.fmr);
dprintk("RPC: %s: ib_alloc_fmr status %i\n", __func__, rc);
kfree(r->r.fmr.physaddrs);
out_free:
kfree(r);
out:
return rc;
}
static int
__fmr_unmap(struct rpcrdma_mw *r)
{
LIST_HEAD(l);
list_add(&r->r.fmr.fmr->list, &l);
return ib_unmap_fmr(&l);
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
mw->r.fmr.physaddrs[i] = seg->mr_dma;
len += seg->mr_len;
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
rc = ib_map_phys_fmr(mw->r.fmr.fmr, mw->r.fmr.physaddrs,
i, seg1->mr_dma);
if (rc)
goto out_maperr;
seg1->rl_mw = mw;
seg1->mr_rkey = mw->r.fmr.fmr->rkey;
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
struct rpcrdma_mw *mw = seg->rl_mw;
int nsegs = seg->mr_nsegs;
seg->rl_mw = NULL;
while (nsegs--)
rpcrdma_unmap_one(device, seg++);
rpcrdma_put_mw(r_xprt, mw);
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
list_add(&mw->r.fmr.fmr->list, &unmap_list);
i += seg->mr_nsegs;
}
rc = ib_unmap_fmr(&unmap_list);
if (rc)
pr_warn("%s: ib_unmap_fmr failed (%i)\n", __func__, rc);
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
__fmr_dma_unmap(r_xprt, seg);
i += seg->mr_nsegs;
seg->mr_nsegs = 0;
}
req->rl_nchunks = 0;
}
static int
fmr_op_unmap(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_mr_seg *seg1 = seg;
struct rpcrdma_mw *mw = seg1->rl_mw;
int rc, nsegs = seg->mr_nsegs;
dprintk("RPC: %s: FMR %p\n", __func__, mw);
seg1->rl_mw = NULL;
while (seg1->mr_nsegs--)
rpcrdma_unmap_one(ia->ri_device, seg++);
rc = __fmr_unmap(mw);
if (rc)
goto out_err;
rpcrdma_put_mw(r_xprt, mw);
return nsegs;
out_err:
dprintk("RPC: %s: ib_unmap_fmr status %i\n", __func__, rc);
return nsegs;
}
static void
fmr_op_destroy(struct rpcrdma_buffer *buf)
{
struct rpcrdma_mw *r;
int rc;
while (!list_empty(&buf->rb_all)) {
r = list_entry(buf->rb_all.next, struct rpcrdma_mw, mw_all);
list_del(&r->mw_all);
kfree(r->r.fmr.physaddrs);
rc = ib_dealloc_fmr(r->r.fmr.fmr);
if (rc)
dprintk("RPC: %s: ib_dealloc_fmr failed %i\n",
__func__, rc);
kfree(r);
}
}
