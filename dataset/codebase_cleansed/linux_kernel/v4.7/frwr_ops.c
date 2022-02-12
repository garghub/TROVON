int
frwr_alloc_recovery_wq(void)
{
frwr_recovery_wq = alloc_workqueue("frwr_recovery",
FRWR_RECOVERY_WQ_FLAGS, 0);
return !frwr_recovery_wq ? -ENOMEM : 0;
}
void
frwr_destroy_recovery_wq(void)
{
struct workqueue_struct *wq;
if (!frwr_recovery_wq)
return;
wq = frwr_recovery_wq;
frwr_recovery_wq = NULL;
destroy_workqueue(wq);
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
__frwr_reset_and_unmap(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mw *mw)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct rpcrdma_frmr *f = &mw->frmr;
int rc;
rc = __frwr_reset_mr(ia, mw);
ib_dma_unmap_sg(ia->ri_device, f->fr_sg, f->fr_nents, f->fr_dir);
if (rc)
return;
rpcrdma_put_mw(r_xprt, mw);
}
static void
__frwr_recovery_worker(struct work_struct *work)
{
struct rpcrdma_mw *r = container_of(work, struct rpcrdma_mw,
mw_work);
__frwr_reset_and_unmap(r->mw_xprt, r);
return;
}
static void
__frwr_queue_recovery(struct rpcrdma_mw *r)
{
INIT_WORK(&r->mw_work, __frwr_recovery_worker);
queue_work(frwr_recovery_wq, &r->mw_work);
}
static int
__frwr_init(struct rpcrdma_mw *r, struct ib_pd *pd, struct ib_device *device,
unsigned int depth)
{
struct rpcrdma_frmr *f = &r->frmr;
int rc;
f->fr_mr = ib_alloc_mr(pd, IB_MR_TYPE_MEM_REG, depth);
if (IS_ERR(f->fr_mr))
goto out_mr_err;
f->fr_sg = kcalloc(depth, sizeof(*f->fr_sg), GFP_KERNEL);
if (!f->fr_sg)
goto out_list_err;
sg_init_table(f->fr_sg, depth);
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
__frwr_release(struct rpcrdma_mw *r)
{
int rc;
rc = ib_dereg_mr(r->frmr.fr_mr);
if (rc)
dprintk("RPC: %s: ib_dereg_mr status %i\n",
__func__, rc);
kfree(r->frmr.fr_sg);
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
frwr_op_init(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_buffer *buf = &r_xprt->rx_buf;
struct ib_device *device = r_xprt->rx_ia.ri_device;
unsigned int depth = r_xprt->rx_ia.ri_max_frmr_depth;
struct ib_pd *pd = r_xprt->rx_ia.ri_pd;
int i;
spin_lock_init(&buf->rb_mwlock);
INIT_LIST_HEAD(&buf->rb_mws);
INIT_LIST_HEAD(&buf->rb_all);
i = max_t(int, RPCRDMA_MAX_DATA_SEGS / depth, 1);
i += 2;
i *= buf->rb_max_requests;
dprintk("RPC: %s: initalizing %d FRMRs\n", __func__, i);
while (i--) {
struct rpcrdma_mw *r;
int rc;
r = kzalloc(sizeof(*r), GFP_KERNEL);
if (!r)
return -ENOMEM;
rc = __frwr_init(r, pd, device, depth);
if (rc) {
kfree(r);
return rc;
}
r->mw_xprt = r_xprt;
list_add(&r->mw_list, &buf->rb_mws);
list_add(&r->mw_all, &buf->rb_all);
}
return 0;
}
static int
frwr_op_map(struct rpcrdma_xprt *r_xprt, struct rpcrdma_mr_seg *seg,
int nsegs, bool writing)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
struct ib_device *device = ia->ri_device;
enum dma_data_direction direction = rpcrdma_data_dir(writing);
struct rpcrdma_mr_seg *seg1 = seg;
struct rpcrdma_mw *mw;
struct rpcrdma_frmr *frmr;
struct ib_mr *mr;
struct ib_reg_wr *reg_wr;
struct ib_send_wr *bad_wr;
int rc, i, n, dma_nents;
u8 key;
mw = seg1->rl_mw;
seg1->rl_mw = NULL;
do {
if (mw)
__frwr_queue_recovery(mw);
mw = rpcrdma_get_mw(r_xprt);
if (!mw)
return -ENOMEM;
} while (mw->frmr.fr_state != FRMR_IS_INVALID);
frmr = &mw->frmr;
frmr->fr_state = FRMR_IS_VALID;
mr = frmr->fr_mr;
reg_wr = &frmr->fr_regwr;
if (nsegs > ia->ri_max_frmr_depth)
nsegs = ia->ri_max_frmr_depth;
for (i = 0; i < nsegs;) {
if (seg->mr_page)
sg_set_page(&frmr->fr_sg[i],
seg->mr_page,
seg->mr_len,
offset_in_page(seg->mr_offset));
else
sg_set_buf(&frmr->fr_sg[i], seg->mr_offset,
seg->mr_len);
++seg;
++i;
if ((i < nsegs && offset_in_page(seg->mr_offset)) ||
offset_in_page((seg-1)->mr_offset + (seg-1)->mr_len))
break;
}
frmr->fr_nents = i;
frmr->fr_dir = direction;
dma_nents = ib_dma_map_sg(device, frmr->fr_sg, frmr->fr_nents, direction);
if (!dma_nents) {
pr_err("RPC: %s: failed to dma map sg %p sg_nents %u\n",
__func__, frmr->fr_sg, frmr->fr_nents);
return -ENOMEM;
}
n = ib_map_mr_sg(mr, frmr->fr_sg, frmr->fr_nents, NULL, PAGE_SIZE);
if (unlikely(n != frmr->fr_nents)) {
pr_err("RPC: %s: failed to map mr %p (%u/%u)\n",
__func__, frmr->fr_mr, n, frmr->fr_nents);
rc = n < 0 ? n : -EINVAL;
goto out_senderr;
}
dprintk("RPC: %s: Using frmr %p to map %u segments (%u bytes)\n",
__func__, mw, frmr->fr_nents, mr->length);
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
seg1->rl_mw = mw;
seg1->mr_rkey = mr->rkey;
seg1->mr_base = mr->iova;
seg1->mr_nsegs = frmr->fr_nents;
seg1->mr_len = mr->length;
return frmr->fr_nents;
out_senderr:
dprintk("RPC: %s: ib_post_send status %i\n", __func__, rc);
__frwr_queue_recovery(mw);
return rc;
}
static struct ib_send_wr *
__frwr_prepare_linv_wr(struct rpcrdma_mr_seg *seg)
{
struct rpcrdma_mw *mw = seg->rl_mw;
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
struct rpcrdma_mr_seg *seg;
unsigned int i, nchunks;
struct rpcrdma_frmr *f;
struct rpcrdma_mw *mw;
int rc;
dprintk("RPC: %s: req %p\n", __func__, req);
invalidate_wrs = pos = prev = NULL;
seg = NULL;
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
pos = __frwr_prepare_linv_wr(seg);
if (!invalidate_wrs)
invalidate_wrs = pos;
else
prev->next = pos;
prev = pos;
i += seg->mr_nsegs;
}
f = &seg->rl_mw->frmr;
f->fr_invwr.send_flags = IB_SEND_SIGNALED;
f->fr_cqe.done = frwr_wc_localinv_wake;
reinit_completion(&f->fr_linv_done);
INIT_CQCOUNT(&r_xprt->rx_ep);
rc = ib_post_send(ia->ri_id->qp, invalidate_wrs, &bad_wr);
if (rc)
goto reset_mrs;
wait_for_completion(&f->fr_linv_done);
unmap:
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
mw = seg->rl_mw;
seg->rl_mw = NULL;
ib_dma_unmap_sg(ia->ri_device, f->fr_sg, f->fr_nents,
f->fr_dir);
rpcrdma_put_mw(r_xprt, mw);
i += seg->mr_nsegs;
seg->mr_nsegs = 0;
}
req->rl_nchunks = 0;
return;
reset_mrs:
pr_warn("%s: ib_post_send failed %i\n", __func__, rc);
for (i = 0, nchunks = req->rl_nchunks; nchunks; nchunks--) {
seg = &req->rl_segments[i];
mw = seg->rl_mw;
f = &mw->frmr;
if (mw->frmr.fr_mr->rkey == bad_wr->ex.invalidate_rkey) {
__frwr_reset_mr(ia, mw);
bad_wr = bad_wr->next;
}
i += seg->mr_nsegs;
}
goto unmap;
}
static void
frwr_op_unmap_safe(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
bool sync)
{
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
unsigned int i;
for (i = 0; req->rl_nchunks; req->rl_nchunks--) {
seg = &req->rl_segments[i];
mw = seg->rl_mw;
if (sync)
__frwr_reset_and_unmap(r_xprt, mw);
else
__frwr_queue_recovery(mw);
i += seg->mr_nsegs;
seg->mr_nsegs = 0;
seg->rl_mw = NULL;
}
}
static void
frwr_op_destroy(struct rpcrdma_buffer *buf)
{
struct rpcrdma_mw *r;
flush_workqueue(frwr_recovery_wq);
while (!list_empty(&buf->rb_all)) {
r = list_entry(buf->rb_all.next, struct rpcrdma_mw, mw_all);
list_del(&r->mw_all);
__frwr_release(r);
kfree(r);
}
}
