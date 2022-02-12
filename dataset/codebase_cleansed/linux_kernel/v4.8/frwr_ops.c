bool
frwr_is_supported(struct rpcrdma_ia *ia)
{
struct ib_device_attr *attrs = &ia->ri_device->attrs;
if (!(attrs->device_cap_flags & IB_DEVICE_MEM_MGT_EXTENSIONS))
goto out_not_supported;
if (attrs->max_fast_reg_page_list_len == 0)
goto out_not_supported;
return true;
out_not_supported:
pr_info("rpcrdma: 'frwr' mode is not supported by device %s\n",
ia->ri_device->name);
return false;
}
static int
frwr_op_init_mr(struct rpcrdma_ia *ia, struct rpcrdma_mw *r)
{
unsigned int depth = ia->ri_max_frmr_depth;
struct rpcrdma_frmr *f = &r->frmr;
int rc;
f->fr_mr = ib_alloc_mr(ia->ri_pd, IB_MR_TYPE_MEM_REG, depth);
if (IS_ERR(f->fr_mr))
goto out_mr_err;
r->mw_sg = kcalloc(depth, sizeof(*r->mw_sg), GFP_KERNEL);
if (!r->mw_sg)
goto out_list_err;
sg_init_table(r->mw_sg, depth);
init_completion(&f->fr_linv_done);
return 0;
out_mr_err:
rc = PTR_ERR(f->fr_mr);
dprintk("RPC: %s: ib_alloc_mr status %i\n",
__func__, rc);
return rc;
out_list_err:
rc = -ENOMEM;
dprintk("RPC: %s: sg allocation failure\n",
__func__);
ib_dereg_mr(f->fr_mr);
return rc;
}
static void
frwr_op_release_mr(struct rpcrdma_mw *r)
{
int rc;
if (!list_empty(&r->mw_list))
list_del(&r->mw_list);
rc = ib_dereg_mr(r->frmr.fr_mr);
if (rc)
pr_err("rpcrdma: final ib_dereg_mr for %p returned %i\n",
r, rc);
kfree(r->mw_sg);
kfree(r);
}
static int
__frwr_reset_mr(struct rpcrdma_ia *ia, struct rpcrdma_mw *r)
{
struct rpcrdma_frmr *f = &r->frmr;
int rc;
rc = ib_dereg_mr(f->fr_mr);
if (rc) {
pr_warn("rpcrdma: ib_dereg_mr status %d, frwr %p orphaned\n",
rc, r);
return rc;
}
f->fr_mr = ib_alloc_mr(ia->ri_pd, IB_MR_TYPE_MEM_REG,
ia->ri_max_frmr_depth);
if (IS_ERR(f->fr_mr)) {
pr_warn("rpcrdma: ib_alloc_mr status %ld, frwr %p orphaned\n",
PTR_ERR(f->fr_mr), r);
return PTR_ERR(f->fr_mr);
}
dprintk("RPC: %s: recovered FRMR %p\n", __func__, r);
f->fr_state = FRMR_IS_INVALID;
return 0;
}
static void
frwr_op_recover_mr(struct rpcrdma_mw *mw)
{
struct rpcrdma_xprt *r_xprt = mw->mw_xprt;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
int rc;
rc = __frwr_reset_mr(ia, mw);
ib_dma_unmap_sg(ia->ri_device, mw->mw_sg, mw->mw_nents, mw->mw_dir);
if (rc)
goto out_release;
rpcrdma_put_mw(r_xprt, mw);
r_xprt->rx_stats.mrs_recovered++;
return;
out_release:
pr_err("rpcrdma: FRMR reset failed %d, %p release\n", rc, mw);
r_xprt->rx_stats.mrs_orphaned++;
spin_lock(&r_xprt->rx_buf.rb_mwlock);
list_del(&mw->mw_all);
spin_unlock(&r_xprt->rx_buf.rb_mwlock);
frwr_op_release_mr(mw);
}
static int
frwr_op_open(struct rpcrdma_ia *ia, struct rpcrdma_ep *ep,
struct rpcrdma_create_data_internal *cdata)
{
int depth, delta;
ia->ri_max_frmr_depth =
min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len);
dprintk("RPC: %s: device's max FR page list len = %u\n",
__func__, ia->ri_max_frmr_depth);
depth = 7;
if (ia->ri_max_frmr_depth < RPCRDMA_MAX_DATA_SEGS) {
delta = RPCRDMA_MAX_DATA_SEGS - ia->ri_max_frmr_depth;
do {
depth += 2;
delta -= ia->ri_max_frmr_depth;
} while (delta > 0);
}
ep->rep_attr.cap.max_send_wr *= depth;
if (ep->rep_attr.cap.max_send_wr > ia->ri_device->attrs.max_qp_wr) {
cdata->max_requests = ia->ri_device->attrs.max_qp_wr / depth;
if (!cdata->max_requests)
return -EINVAL;
ep->rep_attr.cap.max_send_wr = cdata->max_requests *
depth;
}
rpcrdma_set_max_header_sizes(ia, cdata, max_t(unsigned int, 1,
RPCRDMA_MAX_DATA_SEGS /
ia->ri_max_frmr_depth));
return 0;
}
static size_t
frwr_op_maxpages(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
return min_t(unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * ia->ri_max_frmr_depth);
}
static void
__frwr_sendcompletion_flush(struct ib_wc *wc, struct rpcrdma_frmr *frmr,
const char *wr)
{
frmr->fr_state = FRMR_IS_STALE;
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("rpcrdma: %s: %s (%u/0x%x)\n",
wr, ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
}
static void
frwr_wc_fastreg(struct ib_cq *cq, struct ib_wc *wc)
{
struct rpcrdma_frmr *frmr;
struct ib_cqe *cqe;
if (wc->status != IB_WC_SUCCESS) {
cqe = wc->wr_cqe;
frmr = container_of(cqe, struct rpcrdma_frmr, fr_cqe);
__frwr_sendcompletion_flush(wc, frmr, "fastreg");
}
}
static void
frwr_wc_localinv(struct ib_cq *cq, struct ib_wc *wc)
{
struct rpcrdma_frmr *frmr;
struct ib_cqe *cqe;
if (wc->status != IB_WC_SUCCESS) {
cqe = wc->wr_cqe;
frmr = container_of(cqe, struct rpcrdma_frmr, fr_cqe);
__frwr_sendcompletion_flush(wc, frmr, "localinv");
}
}
static void
frwr_wc_localinv_wake(struct ib_cq *cq, struct ib_wc *wc)
{
struct rpcrdma_frmr *frmr;
struct ib_cqe *cqe;
cqe = wc->wr_cqe;
frmr = container_of(cqe, struct rpcrdma_frmr, fr_cqe);
if (wc->status != IB_WC_SUCCESS)
__frwr_sendcompletion_flush(wc, frmr, "localinv");
complete_all(&frmr->fr_linv_done);
}
static int
frwr_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing, struct rpcrdma_mw **out)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_mw *mw;
struct rpcrdma_frmr *frmr;
struct ib_mr *mr;
struct ib_reg_wr *reg_wr;
struct ib_send_wr *bad_wr;
int rc, i, n, dma_nents;
u8 key;
mw = NULL;
do {
if (mw)
rpcrdma_defer_mr_recovery(mw);
mw = rpcrdma_get_mw(r_xprt);
if (!mw)
return -ENOBUFS;
} while (mw->frmr.fr_state != FRMR_IS_INVALID);
frmr = &mw->frmr;
frmr->fr_state = FRMR_IS_VALID;
mr = frmr->fr_mr;
reg_wr = &frmr->fr_regwr;
if (nsegs > ia->ri_max_frmr_depth)
nsegs = ia->ri_max_frmr_depth;
for (i = 0; i < nsegs;) {
if (seg->mr_page)
sg_set_page(&mw->mw_sg[i],
seg->mr_page,
seg->mr_len,
offset_in_page(seg->mr_offset));
else
sg_set_buf(&mw->mw_sg[i], seg->mr_offset,
seg->mr_len);
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
mw->mw_nents = i;
mw->mw_dir = rpcrdma_data_dir(writing);
if (i == 0)
goto out_dmamap_err;
dma_nents = ib_dma_map_sg(ia->ri_device,
mw->mw_sg, mw->mw_nents, mw->mw_dir);
if (!dma_nents)
goto out_dmamap_err;
n = ib_map_mr_sg(mr, mw->mw_sg, mw->mw_nents, NULL, PAGE_SIZE);
if (unlikely(n != mw->mw_nents))
goto out_mapmr_err;
dprintk("RPC: %s: Using frmr %p to map %u segments (%u bytes)\n",
__func__, mw, mw->mw_nents, mr->length);
key = (u8)(mr->rkey & 0x000000FF);
ib_update_fast_reg_key(mr, ++key);
reg_wr->wr.next = NULL;
reg_wr->wr.opcode = IB_WR_REG_MR;
frmr->fr_cqe.done = frwr_wc_fastreg;
reg_wr->wr.wr_cqe = &frmr->fr_cqe;
reg_wr->wr.num_sge = 0;
reg_wr->wr.send_flags = 0;
reg_wr->mr = mr;
reg_wr->key = mr->rkey;
reg_wr->access = writing ?
IB_ACCESS_REMOTE_WRITE | IB_ACCESS_LOCAL_WRITE :
IB_ACCESS_REMOTE_READ;
DECR_CQCOUNT(&r_xprt->rx_ep);
rc = ib_post_send(ia->ri_id->qp, &reg_wr->wr, &bad_wr);
if (rc)
goto out_senderr;
mw->mw_handle = mr->rkey;
mw->mw_length = mr->length;
mw->mw_offset = mr->iova;
*out = mw;
return mw->mw_nents;
out_dmamap_err:
pr_err("rpcrdma: failed to dma map sg %p sg_nents %u\n",
mw->mw_sg, mw->mw_nents);
rpcrdma_defer_mr_recovery(mw);
return -EIO;
out_mapmr_err:
pr_err("rpcrdma: failed to map mr %p (%u/%u)\n",
frmr->fr_mr, n, mw->mw_nents);
rpcrdma_defer_mr_recovery(mw);
return -EIO;
out_senderr:
pr_err("rpcrdma: FRMR registration ib_post_send returned %i\n", rc);
rpcrdma_defer_mr_recovery(mw);
return -ENOTCONN;
}
static struct ib_send_wr *
__frwr_prepare_linv_wr(struct rpcrdma_mw *mw)
{
struct rpcrdma_frmr *f = &mw->frmr;
struct ib_send_wr *invalidate_wr;
f->fr_state = FRMR_IS_INVALID;
invalidate_wr = &f->fr_invwr;
memset(invalidate_wr, 0, sizeof(*invalidate_wr));
f->fr_cqe.done = frwr_wc_localinv;
invalidate_wr->wr_cqe = &f->fr_cqe;
invalidate_wr->opcode = IB_WR_LOCAL_INV;
invalidate_wr->ex.invalidate_rkey = f->fr_mr->rkey;
return invalidate_wr;
}
static void
frwr_op_unmap_sync(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req)
{
struct ib_send_wr *invalidate_wrs, *pos, *prev, *bad_wr;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_mw *mw, *tmp;
struct rpcrdma_frmr *f;
int rc;
dprintk("RPC: %s: req %p\n", __func__, req);
f = NULL;
invalidate_wrs = pos = prev = NULL;
list_for_each_entry(mw, &req->rl_registered, mw_list) {
pos = __frwr_prepare_linv_wr(mw);
if (!invalidate_wrs)
invalidate_wrs = pos;
else
prev->next = pos;
prev = pos;
f = &mw->frmr;
}
f->fr_invwr.send_flags = IB_SEND_SIGNALED;
f->fr_cqe.done = frwr_wc_localinv_wake;
reinit_completion(&f->fr_linv_done);
INIT_CQCOUNT(&r_xprt->rx_ep);
rc = ib_post_send(ia->ri_id->qp, invalidate_wrs, &bad_wr);
if (rc)
goto reset_mrs;
wait_for_completion(&f->fr_linv_done);
unmap:
list_for_each_entry_safe(mw, tmp, &req->rl_registered, mw_list) {
list_del_init(&mw->mw_list);
ib_dma_unmap_sg(ia->ri_device,
mw->mw_sg, mw->mw_nents, mw->mw_dir);
rpcrdma_put_mw(r_xprt, mw);
}
return;
reset_mrs:
pr_err("rpcrdma: FRMR invalidate ib_post_send returned %i\n", rc);
rdma_disconnect(ia->ri_id);
list_for_each_entry(mw, &req->rl_registered, mw_list) {
f = &mw->frmr;
if (mw->frmr.fr_mr->rkey == bad_wr->ex.invalidate_rkey) {
__frwr_reset_mr(ia, mw);
bad_wr = bad_wr->next;
}
}
goto unmap;
}
static void
frwr_op_unmap_safe(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
bool sync)
{
struct rpcrdma_mw *mw;
while (!list_empty(&req->rl_registered)) {
mw = list_first_entry(&req->rl_registered,
struct rpcrdma_mw, mw_list);
list_del_init(&mw->mw_list);
if (sync)
frwr_op_recover_mr(mw);
else
rpcrdma_defer_mr_recovery(mw);
}
}
