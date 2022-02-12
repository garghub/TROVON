static inline struct svc_rdma_rw_ctxt *
svc_rdma_next_ctxt(struct list_head *list)
{
return list_first_entry_or_null(list, struct svc_rdma_rw_ctxt,
rw_list);
}
static struct svc_rdma_rw_ctxt *
svc_rdma_get_rw_ctxt(struct svcxprt_rdma *rdma, unsigned int sges)
{
struct svc_rdma_rw_ctxt *ctxt;
spin_lock(&rdma->sc_rw_ctxt_lock);
ctxt = svc_rdma_next_ctxt(&rdma->sc_rw_ctxts);
if (ctxt) {
list_del(&ctxt->rw_list);
spin_unlock(&rdma->sc_rw_ctxt_lock);
} else {
spin_unlock(&rdma->sc_rw_ctxt_lock);
ctxt = kmalloc(sizeof(*ctxt) +
SG_CHUNK_SIZE * sizeof(struct scatterlist),
GFP_KERNEL);
if (!ctxt)
goto out;
INIT_LIST_HEAD(&ctxt->rw_list);
}
ctxt->rw_sg_table.sgl = ctxt->rw_first_sgl;
if (sg_alloc_table_chained(&ctxt->rw_sg_table, sges,
ctxt->rw_sg_table.sgl)) {
kfree(ctxt);
ctxt = NULL;
}
out:
return ctxt;
}
static void svc_rdma_put_rw_ctxt(struct svcxprt_rdma *rdma,
struct svc_rdma_rw_ctxt *ctxt)
{
sg_free_table_chained(&ctxt->rw_sg_table, true);
spin_lock(&rdma->sc_rw_ctxt_lock);
list_add(&ctxt->rw_list, &rdma->sc_rw_ctxts);
spin_unlock(&rdma->sc_rw_ctxt_lock);
}
void svc_rdma_destroy_rw_ctxts(struct svcxprt_rdma *rdma)
{
struct svc_rdma_rw_ctxt *ctxt;
while ((ctxt = svc_rdma_next_ctxt(&rdma->sc_rw_ctxts)) != NULL) {
list_del(&ctxt->rw_list);
kfree(ctxt);
}
}
static void svc_rdma_cc_init(struct svcxprt_rdma *rdma,
struct svc_rdma_chunk_ctxt *cc,
enum dma_data_direction dir)
{
cc->cc_rdma = rdma;
svc_xprt_get(&rdma->sc_xprt);
INIT_LIST_HEAD(&cc->cc_rwctxts);
cc->cc_sqecount = 0;
cc->cc_dir = dir;
}
static void svc_rdma_cc_release(struct svc_rdma_chunk_ctxt *cc)
{
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_rdma_rw_ctxt *ctxt;
while ((ctxt = svc_rdma_next_ctxt(&cc->cc_rwctxts)) != NULL) {
list_del(&ctxt->rw_list);
rdma_rw_ctx_destroy(&ctxt->rw_ctx, rdma->sc_qp,
rdma->sc_port_num, ctxt->rw_sg_table.sgl,
ctxt->rw_nents, cc->cc_dir);
svc_rdma_put_rw_ctxt(rdma, ctxt);
}
svc_xprt_put(&rdma->sc_xprt);
}
static struct svc_rdma_write_info *
svc_rdma_write_info_alloc(struct svcxprt_rdma *rdma, __be32 *chunk)
{
struct svc_rdma_write_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return info;
info->wi_seg_off = 0;
info->wi_seg_no = 0;
info->wi_nsegs = be32_to_cpup(++chunk);
info->wi_segs = ++chunk;
svc_rdma_cc_init(rdma, &info->wi_cc, DMA_TO_DEVICE);
return info;
}
static void svc_rdma_write_info_free(struct svc_rdma_write_info *info)
{
svc_rdma_cc_release(&info->wi_cc);
kfree(info);
}
static void svc_rdma_write_done(struct ib_cq *cq, struct ib_wc *wc)
{
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_chunk_ctxt *cc =
container_of(cqe, struct svc_rdma_chunk_ctxt, cc_cqe);
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_rdma_write_info *info =
container_of(cc, struct svc_rdma_write_info, wi_cc);
atomic_add(cc->cc_sqecount, &rdma->sc_sq_avail);
wake_up(&rdma->sc_send_wait);
if (unlikely(wc->status != IB_WC_SUCCESS)) {
set_bit(XPT_CLOSE, &rdma->sc_xprt.xpt_flags);
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("svcrdma: write ctx: %s (%u/0x%x)\n",
ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
}
svc_rdma_write_info_free(info);
}
static int svc_rdma_post_chunk_ctxt(struct svc_rdma_chunk_ctxt *cc)
{
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_xprt *xprt = &rdma->sc_xprt;
struct ib_send_wr *first_wr, *bad_wr;
struct list_head *tmp;
struct ib_cqe *cqe;
int ret;
first_wr = NULL;
cqe = &cc->cc_cqe;
list_for_each(tmp, &cc->cc_rwctxts) {
struct svc_rdma_rw_ctxt *ctxt;
ctxt = list_entry(tmp, struct svc_rdma_rw_ctxt, rw_list);
first_wr = rdma_rw_ctx_wrs(&ctxt->rw_ctx, rdma->sc_qp,
rdma->sc_port_num, cqe, first_wr);
cqe = NULL;
}
do {
if (atomic_sub_return(cc->cc_sqecount,
&rdma->sc_sq_avail) > 0) {
ret = ib_post_send(rdma->sc_qp, first_wr, &bad_wr);
if (ret)
break;
return 0;
}
atomic_inc(&rdma_stat_sq_starve);
atomic_add(cc->cc_sqecount, &rdma->sc_sq_avail);
wait_event(rdma->sc_send_wait,
atomic_read(&rdma->sc_sq_avail) > cc->cc_sqecount);
} while (1);
pr_err("svcrdma: ib_post_send failed (%d)\n", ret);
set_bit(XPT_CLOSE, &xprt->xpt_flags);
if (bad_wr != first_wr)
return 0;
atomic_add(cc->cc_sqecount, &rdma->sc_sq_avail);
wake_up(&rdma->sc_send_wait);
return -ENOTCONN;
}
static void svc_rdma_vec_to_sg(struct svc_rdma_write_info *info,
unsigned int len,
struct svc_rdma_rw_ctxt *ctxt)
{
struct scatterlist *sg = ctxt->rw_sg_table.sgl;
sg_set_buf(&sg[0], info->wi_base, len);
info->wi_base += len;
ctxt->rw_nents = 1;
}
static void svc_rdma_pagelist_to_sg(struct svc_rdma_write_info *info,
unsigned int remaining,
struct svc_rdma_rw_ctxt *ctxt)
{
unsigned int sge_no, sge_bytes, page_off, page_no;
struct xdr_buf *xdr = info->wi_xdr;
struct scatterlist *sg;
struct page **page;
page_off = (info->wi_next_off + xdr->page_base) & ~PAGE_MASK;
page_no = (info->wi_next_off + xdr->page_base) >> PAGE_SHIFT;
page = xdr->pages + page_no;
info->wi_next_off += remaining;
sg = ctxt->rw_sg_table.sgl;
sge_no = 0;
do {
sge_bytes = min_t(unsigned int, remaining,
PAGE_SIZE - page_off);
sg_set_page(sg, *page, sge_bytes, page_off);
remaining -= sge_bytes;
sg = sg_next(sg);
page_off = 0;
sge_no++;
page++;
} while (remaining);
ctxt->rw_nents = sge_no;
}
static int
svc_rdma_build_writes(struct svc_rdma_write_info *info,
void (*constructor)(struct svc_rdma_write_info *info,
unsigned int len,
struct svc_rdma_rw_ctxt *ctxt),
unsigned int remaining)
{
struct svc_rdma_chunk_ctxt *cc = &info->wi_cc;
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_rdma_rw_ctxt *ctxt;
__be32 *seg;
int ret;
cc->cc_cqe.done = svc_rdma_write_done;
seg = info->wi_segs + info->wi_seg_no * rpcrdma_segment_maxsz;
do {
unsigned int write_len;
u32 seg_length, seg_handle;
u64 seg_offset;
if (info->wi_seg_no >= info->wi_nsegs)
goto out_overflow;
seg_handle = be32_to_cpup(seg);
seg_length = be32_to_cpup(seg + 1);
xdr_decode_hyper(seg + 2, &seg_offset);
seg_offset += info->wi_seg_off;
write_len = min(remaining, seg_length - info->wi_seg_off);
ctxt = svc_rdma_get_rw_ctxt(rdma,
(write_len >> PAGE_SHIFT) + 2);
if (!ctxt)
goto out_noctx;
constructor(info, write_len, ctxt);
ret = rdma_rw_ctx_init(&ctxt->rw_ctx, rdma->sc_qp,
rdma->sc_port_num, ctxt->rw_sg_table.sgl,
ctxt->rw_nents, 0, seg_offset,
seg_handle, DMA_TO_DEVICE);
if (ret < 0)
goto out_initerr;
list_add(&ctxt->rw_list, &cc->cc_rwctxts);
cc->cc_sqecount += ret;
if (write_len == seg_length - info->wi_seg_off) {
seg += 4;
info->wi_seg_no++;
info->wi_seg_off = 0;
} else {
info->wi_seg_off += write_len;
}
remaining -= write_len;
} while (remaining);
return 0;
out_overflow:
dprintk("svcrdma: inadequate space in Write chunk (%u)\n",
info->wi_nsegs);
return -E2BIG;
out_noctx:
dprintk("svcrdma: no R/W ctxs available\n");
return -ENOMEM;
out_initerr:
svc_rdma_put_rw_ctxt(rdma, ctxt);
pr_err("svcrdma: failed to map pagelist (%d)\n", ret);
return -EIO;
}
static int svc_rdma_send_xdr_kvec(struct svc_rdma_write_info *info,
struct kvec *vec)
{
info->wi_base = vec->iov_base;
return svc_rdma_build_writes(info, svc_rdma_vec_to_sg,
vec->iov_len);
}
static int svc_rdma_send_xdr_pagelist(struct svc_rdma_write_info *info,
struct xdr_buf *xdr)
{
info->wi_xdr = xdr;
info->wi_next_off = 0;
return svc_rdma_build_writes(info, svc_rdma_pagelist_to_sg,
xdr->page_len);
}
int svc_rdma_send_write_chunk(struct svcxprt_rdma *rdma, __be32 *wr_ch,
struct xdr_buf *xdr)
{
struct svc_rdma_write_info *info;
int ret;
if (!xdr->page_len)
return 0;
info = svc_rdma_write_info_alloc(rdma, wr_ch);
if (!info)
return -ENOMEM;
ret = svc_rdma_send_xdr_pagelist(info, xdr);
if (ret < 0)
goto out_err;
ret = svc_rdma_post_chunk_ctxt(&info->wi_cc);
if (ret < 0)
goto out_err;
return xdr->page_len;
out_err:
svc_rdma_write_info_free(info);
return ret;
}
int svc_rdma_send_reply_chunk(struct svcxprt_rdma *rdma, __be32 *rp_ch,
bool writelist, struct xdr_buf *xdr)
{
struct svc_rdma_write_info *info;
int consumed, ret;
info = svc_rdma_write_info_alloc(rdma, rp_ch);
if (!info)
return -ENOMEM;
ret = svc_rdma_send_xdr_kvec(info, &xdr->head[0]);
if (ret < 0)
goto out_err;
consumed = xdr->head[0].iov_len;
if (!writelist && xdr->page_len) {
ret = svc_rdma_send_xdr_pagelist(info, xdr);
if (ret < 0)
goto out_err;
consumed += xdr->page_len;
}
if (xdr->tail[0].iov_len) {
ret = svc_rdma_send_xdr_kvec(info, &xdr->tail[0]);
if (ret < 0)
goto out_err;
consumed += xdr->tail[0].iov_len;
}
ret = svc_rdma_post_chunk_ctxt(&info->wi_cc);
if (ret < 0)
goto out_err;
return consumed;
out_err:
svc_rdma_write_info_free(info);
return ret;
}
