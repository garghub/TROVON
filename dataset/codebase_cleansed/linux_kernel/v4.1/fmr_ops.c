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
INIT_LIST_HEAD(&buf->rb_mws);
INIT_LIST_HEAD(&buf->rb_all);
i = (buf->rb_max_requests + 1) * RPCRDMA_MAX_SEGS;
dprintk("RPC: %s: initializing %d FMRs\n", __func__, i);
while (i--) {
r = kzalloc(sizeof(*r), GFP_KERNEL);
if (!r)
return -ENOMEM;
r->r.fmr = ib_alloc_fmr(pd, mr_access_flags, &fmr_attr);
if (IS_ERR(r->r.fmr))
goto out_fmr_err;
list_add(&r->mw_list, &buf->rb_mws);
list_add(&r->mw_all, &buf->rb_all);
}
return 0;
out_fmr_err:
rc = PTR_ERR(r->r.fmr);
dprintk("RPC: %s: ib_alloc_fmr status %i\n", __func__, rc);
kfree(r);
return rc;
}
static int
fmr_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct ib_device *device = ia->ri_id->device;
enum dma_data_direction direction = rpcrdma_data_dir(writing);
struct rpcrdma_mr_seg *seg1 = seg;
struct rpcrdma_mw *mw = seg1->rl_mw;
u64 physaddrs[RPCRDMA_MAX_DATA_SEGS];
int len, pageoff, i, rc;
pageoff = offset_in_page(seg1->mr_offset);
seg1->mr_offset -= pageoff;
seg1->mr_len += pageoff;
len = -pageoff;
if (nsegs > RPCRDMA_MAX_FMR_SGES)
nsegs = RPCRDMA_MAX_FMR_SGES;
for (i = 0; i < nsegs;) {
rpcrdma_map_one(device, seg, direction);
physaddrs[i] = seg->mr_dma;
len += seg->mr_len;
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
rc = ib_map_phys_fmr(mw->r.fmr, physaddrs, i, seg1->mr_dma);
if (rc)
goto out_maperr;
seg1->mr_rkey = mw->r.fmr->rkey;
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
static int
fmr_op_unmap(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_mr_seg *seg1 = seg;
struct ib_device *device;
int rc, nsegs = seg->mr_nsegs;
LIST_HEAD(l);
list_add(&seg1->rl_mw->r.fmr->list, &l);
rc = ib_unmap_fmr(&l);
read_lock(&ia->ri_qplock);
device = ia->ri_id->device;
while (seg1->mr_nsegs--)
rpcrdma_unmap_one(device, seg++);
read_unlock(&ia->ri_qplock);
if (rc)
goto out_err;
return nsegs;
out_err:
dprintk("RPC: %s: ib_unmap_fmr status %i\n", __func__, rc);
return nsegs;
}
static void
fmr_op_reset(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct rpcrdma_mw *r;
LIST_HEAD(list);
int rc;
list_for_each_entry(r, &buf->rb_all, mw_all)
list_add(&r->r.fmr->list, &list);
rc = ib_unmap_fmr(&list);
if (rc)
dprintk("RPC: %s: ib_unmap_fmr failed %i\n",
__func__, rc);
}
static void
fmr_op_destroy(struct rpcrdma_buffer *buf)
{
struct rpcrdma_mw *r;
int rc;
while (!list_empty(&buf->rb_all)) {
r = list_entry(buf->rb_all.next, struct rpcrdma_mw, mw_all);
list_del(&r->mw_all);
rc = ib_dealloc_fmr(r->r.fmr);
if (rc)
dprintk("RPC: %s: ib_dealloc_fmr failed %i\n",
__func__, rc);
kfree(r);
}
}
