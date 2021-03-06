bool
fmr_is_supported(struct rpcrdma_ia *ia)
{
if (!ia->ri_device->alloc_fmr) {
pr_info("rpcrdma: 'fmr' mode is not supported by device %s\n",
ia->ri_device->name);
return false;
}
return true;
}
static int
fmr_op_init_mr(struct rpcrdma_ia *ia, struct rpcrdma_mw *mw)
{
static struct ib_fmr_attr fmr_attr = {
.max_pages = RPCRDMA_MAX_FMR_SGES,
.max_maps = 1,
.page_shift = PAGE_SHIFT
};
mw->fmr.fm_physaddrs = kcalloc(RPCRDMA_MAX_FMR_SGES,
sizeof(u64), GFP_KERNEL);
if (!mw->fmr.fm_physaddrs)
goto out_free;
mw->mw_sg = kcalloc(RPCRDMA_MAX_FMR_SGES,
sizeof(*mw->mw_sg), GFP_KERNEL);
if (!mw->mw_sg)
goto out_free;
sg_init_table(mw->mw_sg, RPCRDMA_MAX_FMR_SGES);
mw->fmr.fm_mr = ib_alloc_fmr(ia->ri_pd, RPCRDMA_FMR_ACCESS_FLAGS,
&fmr_attr);
if (IS_ERR(mw->fmr.fm_mr))
goto out_fmr_err;
return 0;
out_fmr_err:
dprintk("RPC: %s: ib_alloc_fmr returned %ld\n", __func__,
PTR_ERR(mw->fmr.fm_mr));
out_free:
kfree(mw->mw_sg);
kfree(mw->fmr.fm_physaddrs);
return -ENOMEM;
}
static int
__fmr_unmap(struct rpcrdma_mw *mw)
{
LIST_HEAD(l);
int rc;
list_add(&mw->fmr.fm_mr->list, &l);
rc = ib_unmap_fmr(&l);
list_del(&mw->fmr.fm_mr->list);
return rc;
}
static void
fmr_op_release_mr(struct rpcrdma_mw *r)
{
LIST_HEAD(unmap_list);
int rc;
if (!list_empty(&r->mw_list))
list_del(&r->mw_list);
kfree(r->fmr.fm_physaddrs);
kfree(r->mw_sg);
rc = __fmr_unmap(r);
if (rc)
pr_err("rpcrdma: final ib_unmap_fmr for %p failed %i\n",
r, rc);
rc = ib_dealloc_fmr(r->fmr.fm_mr);
if (rc)
pr_err("rpcrdma: final ib_dealloc_fmr for %p returned %i\n",
r, rc);
kfree(r);
}
static void
fmr_op_recover_mr(struct rpcrdma_mw *mw)
{
struct rpcrdma_xprt *r_xprt = mw->mw_xprt;
int rc;
rc = __fmr_unmap(mw);
ib_dma_unmap_sg(r_xprt->rx_ia.ri_device,
mw->mw_sg, mw->mw_nents, mw->mw_dir);
if (rc)
goto out_release;
rpcrdma_put_mw(r_xprt, mw);
r_xprt->rx_stats.mrs_recovered++;
return;
out_release:
pr_err("rpcrdma: FMR reset failed (%d), %p released\n", rc, mw);
r_xprt->rx_stats.mrs_orphaned++;
spin_lock(&r_xprt->rx_buf.rb_mwlock);
list_del(&mw->mw_all);
spin_unlock(&r_xprt->rx_buf.rb_mwlock);
fmr_op_release_mr(mw);
}
static int
fmr_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
ia->ri_max_segs = max_t(unsigned int, 1, RPCRDMA_MAX_DATA_SEGS /
RPCRDMA_MAX_FMR_SGES);
return 0;
}
static size_t
fmr_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * RPCRDMA_MAX_FMR_SGES);
}
static int
fmr_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing, struct rpcrdma_mw **out)
{
struct rpcrdma_mr_seg *seg1 = seg;
int len, pageoff, i, rc;
struct rpcrdma_mw *mw;
u64 *dma_pages;
mw = rpcrdma_get_mw(r_xprt);
if (!mw)
return -ENOBUFS;
pageoff = offset_in_page(seg1->mr_offset);
seg1->mr_offset -= pageoff;
seg1->mr_len += pageoff;
len = -pageoff;
if (nsegs > RPCRDMA_MAX_FMR_SGES)
nsegs = RPCRDMA_MAX_FMR_SGES;
for (i = 0; i < nsegs;) {
if (seg->mr_page)
sg_set_page(&mw->mw_sg[i],
seg->mr_page,
seg->mr_len,
offset_in_page(seg->mr_offset));
else
sg_set_buf(&mw->mw_sg[i], seg->mr_offset,
seg->mr_len);
len += seg->mr_len;
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
mw->mw_dir = rpcrdma_data_dir(writing);
mw->mw_nents = ib_dma_map_sg(r_xprt->rx_ia.ri_device,
mw->mw_sg, i, mw->mw_dir);
if (!mw->mw_nents)
goto out_dmamap_err;
for (i = 0, dma_pages = mw->fmr.fm_physaddrs; i < mw->mw_nents; i++)
dma_pages[i] = sg_dma_address(&mw->mw_sg[i]);
rc = ib_map_phys_fmr(mw->fmr.fm_mr, dma_pages, mw->mw_nents,
dma_pages[0]);
if (rc)
goto out_maperr;
mw->mw_handle = mw->fmr.fm_mr->rkey;
mw->mw_length = len;
mw->mw_offset = dma_pages[0] + pageoff;
*out = mw;
return mw->mw_nents;
out_dmamap_err:
pr_err("rpcrdma: failed to DMA map sg %p sg_nents %d\n",
mw->mw_sg, i);
rpcrdma_put_mw(r_xprt, mw);
return -EIO;
out_maperr:
pr_err("rpcrdma: ib_map_phys_fmr %u@0x%llx+%i (%d) status %i\n",
len, (unsigned long long)dma_pages[0],
pageoff, mw->mw_nents, rc);
ib_dma_unmap_sg(r_xprt->rx_ia.ri_device,
mw->mw_sg, mw->mw_nents, mw->mw_dir);
rpcrdma_put_mw(r_xprt, mw);
return -EIO;
}
static void
fmr_op_unmap_sync(struct rpcrdma_xprt *r_xprt, struct list_head *mws)
{
struct rpcrdma_mw *mw;
LIST_HEAD(unmap_list);
int rc;
list_for_each_entry(mw, mws, mw_list) {
dprintk("RPC: %s: unmapping fmr %p\n",
__func__, &mw->fmr);
list_add_tail(&mw->fmr.fm_mr->list, &unmap_list);
}
r_xprt->rx_stats.local_inv_needed++;
rc = ib_unmap_fmr(&unmap_list);
if (rc)
goto out_reset;
while (!list_empty(mws)) {
mw = rpcrdma_pop_mw(mws);
dprintk("RPC: %s: DMA unmapping fmr %p\n",
__func__, &mw->fmr);
list_del(&mw->fmr.fm_mr->list);
ib_dma_unmap_sg(r_xprt->rx_ia.ri_device,
mw->mw_sg, mw->mw_nents, mw->mw_dir);
rpcrdma_put_mw(r_xprt, mw);
}
return;
out_reset:
pr_err("rpcrdma: ib_unmap_fmr failed (%i)\n", rc);
while (!list_empty(mws)) {
mw = rpcrdma_pop_mw(mws);
list_del(&mw->fmr.fm_mr->list);
fmr_op_recover_mr(mw);
}
}
static void
fmr_op_unmap_safe(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
bool sync)
{
struct rpcrdma_mw *mw;
while (!list_empty(&req->rl_registered)) {
mw = rpcrdma_pop_mw(&req->rl_registered);
if (sync)
fmr_op_recover_mr(mw);
else
rpcrdma_defer_mr_recovery(mw);
}
}
