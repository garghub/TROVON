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
struct svc_rdma_chunk_ctxt *cc)
{
cc->cc_rdma = rdma;
svc_xprt_get(&rdma->sc_xprt);
INIT_LIST_HEAD(&cc->cc_rwctxts);
cc->cc_sqecount = 0;
}
static void svc_rdma_cc_release(struct svc_rdma_chunk_ctxt *cc,
enum dma_data_direction dir)
{
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_rdma_rw_ctxt *ctxt;
while ((ctxt = svc_rdma_next_ctxt(&cc->cc_rwctxts)) != NULL) {
list_del(&ctxt->rw_list);
rdma_rw_ctx_destroy(&ctxt->rw_ctx, rdma->sc_qp,
rdma->sc_port_num, ctxt->rw_sg_table.sgl,
ctxt->rw_nents, dir);
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
svc_rdma_cc_init(rdma, &info->wi_cc);
info->wi_cc.cc_cqe.done = svc_rdma_write_done;
return info;
}
static void svc_rdma_write_info_free(struct svc_rdma_write_info *info)
{
svc_rdma_cc_release(&info->wi_cc, DMA_TO_DEVICE);
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
static struct svc_rdma_read_info *
svc_rdma_read_info_alloc(struct svcxprt_rdma *rdma)
{
struct svc_rdma_read_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return info;
svc_rdma_cc_init(rdma, &info->ri_cc);
info->ri_cc.cc_cqe.done = svc_rdma_wc_read_done;
return info;
}
static void svc_rdma_read_info_free(struct svc_rdma_read_info *info)
{
svc_rdma_cc_release(&info->ri_cc, DMA_FROM_DEVICE);
kfree(info);
}
static void svc_rdma_wc_read_done(struct ib_cq *cq, struct ib_wc *wc)
{
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_chunk_ctxt *cc =
container_of(cqe, struct svc_rdma_chunk_ctxt, cc_cqe);
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_rdma_read_info *info =
container_of(cc, struct svc_rdma_read_info, ri_cc);
atomic_add(cc->cc_sqecount, &rdma->sc_sq_avail);
wake_up(&rdma->sc_send_wait);
if (unlikely(wc->status != IB_WC_SUCCESS)) {
set_bit(XPT_CLOSE, &rdma->sc_xprt.xpt_flags);
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("svcrdma: read ctx: %s (%u/0x%x)\n",
ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
svc_rdma_put_context(info->ri_readctxt, 1);
} else {
spin_lock(&rdma->sc_rq_dto_lock);
list_add_tail(&info->ri_readctxt->list,
&rdma->sc_read_complete_q);
spin_unlock(&rdma->sc_rq_dto_lock);
set_bit(XPT_DATA, &rdma->sc_xprt.xpt_flags);
svc_xprt_enqueue(&rdma->sc_xprt);
}
svc_rdma_read_info_free(info);
}
static int svc_rdma_post_chunk_ctxt(struct svc_rdma_chunk_ctxt *cc)
{
struct svcxprt_rdma *rdma = cc->cc_rdma;
struct svc_xprt *xprt = &rdma->sc_xprt;
struct ib_send_wr *first_wr, *bad_wr;
struct list_head *tmp;
struct ib_cqe *cqe;
int ret;
if (cc->cc_sqecount > rdma->sc_sq_depth)
return -EINVAL;
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
page_off = info->wi_next_off + xdr->page_base;
page_no = page_off >> PAGE_SHIFT;
page_off = offset_in_page(page_off);
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
static int svc_rdma_build_read_segment(struct svc_rdma_read_info *info,
struct svc_rqst *rqstp,
u32 rkey, u32 len, u64 offset)
{
struct svc_rdma_op_ctxt *head = info->ri_readctxt;
struct svc_rdma_chunk_ctxt *cc = &info->ri_cc;
struct svc_rdma_rw_ctxt *ctxt;
unsigned int sge_no, seg_len;
struct scatterlist *sg;
int ret;
sge_no = PAGE_ALIGN(info->ri_pageoff + len) >> PAGE_SHIFT;
ctxt = svc_rdma_get_rw_ctxt(cc->cc_rdma, sge_no);
if (!ctxt)
goto out_noctx;
ctxt->rw_nents = sge_no;
dprintk("svcrdma: reading segment %u@0x%016llx:0x%08x (%u sges)\n",
len, offset, rkey, sge_no);
sg = ctxt->rw_sg_table.sgl;
for (sge_no = 0; sge_no < ctxt->rw_nents; sge_no++) {
seg_len = min_t(unsigned int, len,
PAGE_SIZE - info->ri_pageoff);
head->arg.pages[info->ri_pageno] =
rqstp->rq_pages[info->ri_pageno];
if (!info->ri_pageoff)
head->count++;
sg_set_page(sg, rqstp->rq_pages[info->ri_pageno],
seg_len, info->ri_pageoff);
sg = sg_next(sg);
info->ri_pageoff += seg_len;
if (info->ri_pageoff == PAGE_SIZE) {
info->ri_pageno++;
info->ri_pageoff = 0;
}
len -= seg_len;
if (len &&
&rqstp->rq_pages[info->ri_pageno + 1] > rqstp->rq_page_end)
goto out_overrun;
}
ret = rdma_rw_ctx_init(&ctxt->rw_ctx, cc->cc_rdma->sc_qp,
cc->cc_rdma->sc_port_num,
ctxt->rw_sg_table.sgl, ctxt->rw_nents,
0, offset, rkey, DMA_FROM_DEVICE);
if (ret < 0)
goto out_initerr;
list_add(&ctxt->rw_list, &cc->cc_rwctxts);
cc->cc_sqecount += ret;
return 0;
out_noctx:
dprintk("svcrdma: no R/W ctxs available\n");
return -ENOMEM;
out_overrun:
dprintk("svcrdma: request overruns rq_pages\n");
return -EINVAL;
out_initerr:
svc_rdma_put_rw_ctxt(cc->cc_rdma, ctxt);
pr_err("svcrdma: failed to map pagelist (%d)\n", ret);
return -EIO;
}
static int svc_rdma_build_read_chunk(struct svc_rqst *rqstp,
struct svc_rdma_read_info *info,
__be32 *p)
{
int ret;
info->ri_chunklen = 0;
while (*p++ != xdr_zero) {
u32 rs_handle, rs_length;
u64 rs_offset;
if (be32_to_cpup(p++) != info->ri_position)
break;
rs_handle = be32_to_cpup(p++);
rs_length = be32_to_cpup(p++);
p = xdr_decode_hyper(p, &rs_offset);
ret = svc_rdma_build_read_segment(info, rqstp,
rs_handle, rs_length,
rs_offset);
if (ret < 0)
break;
info->ri_chunklen += rs_length;
}
return ret;
}
static int svc_rdma_copy_tail(struct svc_rqst *rqstp,
struct svc_rdma_read_info *info)
{
struct svc_rdma_op_ctxt *head = info->ri_readctxt;
unsigned int tail_length, remaining;
u8 *srcp, *destp;
if (head->arg.head[0].iov_len > PAGE_SIZE) {
pr_warn_once("svcrdma: too much trailing inline content\n");
return -EINVAL;
}
srcp = head->arg.head[0].iov_base;
srcp += info->ri_position;
tail_length = head->arg.head[0].iov_len - info->ri_position;
remaining = tail_length;
if (info->ri_pageoff > 0) {
unsigned int len;
len = min_t(unsigned int, remaining,
PAGE_SIZE - info->ri_pageoff);
destp = page_address(rqstp->rq_pages[info->ri_pageno]);
destp += info->ri_pageoff;
memcpy(destp, srcp, len);
srcp += len;
destp += len;
info->ri_pageoff += len;
remaining -= len;
if (info->ri_pageoff == PAGE_SIZE) {
info->ri_pageno++;
info->ri_pageoff = 0;
}
}
if (remaining) {
head->arg.pages[info->ri_pageno] =
rqstp->rq_pages[info->ri_pageno];
head->count++;
destp = page_address(rqstp->rq_pages[info->ri_pageno]);
memcpy(destp, srcp, remaining);
info->ri_pageoff += remaining;
}
head->arg.page_len += tail_length;
head->arg.len += tail_length;
head->arg.buflen += tail_length;
return 0;
}
static int svc_rdma_build_normal_read_chunk(struct svc_rqst *rqstp,
struct svc_rdma_read_info *info,
__be32 *p)
{
struct svc_rdma_op_ctxt *head = info->ri_readctxt;
int ret;
dprintk("svcrdma: Reading Read chunk at position %u\n",
info->ri_position);
info->ri_pageno = head->hdr_count;
info->ri_pageoff = 0;
ret = svc_rdma_build_read_chunk(rqstp, info, p);
if (ret < 0)
goto out;
if (info->ri_chunklen & 3) {
u32 padlen = 4 - (info->ri_chunklen & 3);
info->ri_chunklen += padlen;
info->ri_pageoff += padlen;
if (info->ri_pageoff == PAGE_SIZE) {
info->ri_pageno++;
info->ri_pageoff = 0;
}
}
head->arg.page_len = info->ri_chunklen;
head->arg.len += info->ri_chunklen;
head->arg.buflen += info->ri_chunklen;
if (info->ri_position < head->arg.head[0].iov_len) {
ret = svc_rdma_copy_tail(rqstp, info);
if (ret < 0)
goto out;
}
head->arg.head[0].iov_len = info->ri_position;
out:
return ret;
}
static int svc_rdma_build_pz_read_chunk(struct svc_rqst *rqstp,
struct svc_rdma_read_info *info,
__be32 *p)
{
struct svc_rdma_op_ctxt *head = info->ri_readctxt;
int ret;
dprintk("svcrdma: Reading Position Zero Read chunk\n");
info->ri_pageno = head->hdr_count - 1;
info->ri_pageoff = offset_in_page(head->byte_len);
ret = svc_rdma_build_read_chunk(rqstp, info, p);
if (ret < 0)
goto out;
head->arg.len += info->ri_chunklen;
head->arg.buflen += info->ri_chunklen;
if (head->arg.buflen <= head->sge[0].length) {
head->arg.head[0].iov_len = info->ri_chunklen;
} else {
head->arg.head[0].iov_len =
head->sge[0].length - head->byte_len;
head->arg.page_len =
info->ri_chunklen - head->arg.head[0].iov_len;
}
out:
return ret;
}
int svc_rdma_recv_read_chunk(struct svcxprt_rdma *rdma, struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head, __be32 *p)
{
struct svc_rdma_read_info *info;
struct page **page;
int ret;
head->hdr_count = head->count;
head->arg.head[0] = rqstp->rq_arg.head[0];
head->arg.tail[0] = rqstp->rq_arg.tail[0];
head->arg.pages = head->pages;
head->arg.page_base = 0;
head->arg.page_len = 0;
head->arg.len = rqstp->rq_arg.len;
head->arg.buflen = rqstp->rq_arg.buflen;
info = svc_rdma_read_info_alloc(rdma);
if (!info)
return -ENOMEM;
info->ri_readctxt = head;
info->ri_position = be32_to_cpup(p + 1);
if (info->ri_position)
ret = svc_rdma_build_normal_read_chunk(rqstp, info, p);
else
ret = svc_rdma_build_pz_read_chunk(rqstp, info, p);
if (info->ri_pageoff > 0)
info->ri_pageno++;
rqstp->rq_respages = &rqstp->rq_pages[info->ri_pageno];
rqstp->rq_next_page = rqstp->rq_respages + 1;
if (ret < 0)
goto out;
ret = svc_rdma_post_chunk_ctxt(&info->ri_cc);
out:
for (page = rqstp->rq_pages; page < rqstp->rq_respages; page++)
*page = NULL;
if (ret < 0)
svc_rdma_read_info_free(info);
return ret;
}
