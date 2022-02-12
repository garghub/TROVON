static u32 xdr_padsize(u32 len)
{
return (len & 3) ? (4 - (len & 3)) : 0;
}
static unsigned int svc_rdma_reply_hdr_len(__be32 *rdma_resp)
{
unsigned int nsegs;
__be32 *p;
p = rdma_resp;
p += rpcrdma_fixed_maxsz + 1;
while (*p++ != xdr_zero) {
nsegs = be32_to_cpup(p++);
p += nsegs * rpcrdma_segment_maxsz;
}
if (*p++ != xdr_zero) {
nsegs = be32_to_cpup(p++);
p += nsegs * rpcrdma_segment_maxsz;
}
return (unsigned long)p - (unsigned long)rdma_resp;
}
static unsigned int xdr_encode_write_chunk(__be32 *dst, __be32 *src,
unsigned int remaining)
{
unsigned int i, nsegs;
u32 seg_len;
*dst++ = *src++;
nsegs = be32_to_cpup(src);
*dst++ = *src++;
for (i = nsegs; i; i--) {
*dst++ = *src++;
seg_len = be32_to_cpu(*src);
if (remaining >= seg_len) {
*dst = *src;
remaining -= seg_len;
} else {
*dst = cpu_to_be32(remaining);
remaining = 0;
}
dst++; src++;
*dst++ = *src++;
*dst++ = *src++;
}
return nsegs;
}
static void svc_rdma_xdr_encode_write_list(__be32 *rdma_resp, __be32 *wr_ch,
unsigned int consumed)
{
unsigned int nsegs;
__be32 *p, *q;
p = rdma_resp + rpcrdma_fixed_maxsz + 1;
q = wr_ch;
while (*q != xdr_zero) {
nsegs = xdr_encode_write_chunk(p, q, consumed);
q += 2 + nsegs * rpcrdma_segment_maxsz;
p += 2 + nsegs * rpcrdma_segment_maxsz;
consumed = 0;
}
*p++ = xdr_zero;
*p = xdr_zero;
}
static void svc_rdma_xdr_encode_reply_chunk(__be32 *rdma_resp, __be32 *rp_ch,
unsigned int consumed)
{
__be32 *p;
p = rdma_resp + rpcrdma_fixed_maxsz + 1;
while (*p++ != xdr_zero)
p += 1 + be32_to_cpup(p) * rpcrdma_segment_maxsz;
xdr_encode_write_chunk(p, rp_ch, consumed);
}
static void svc_rdma_get_write_arrays(__be32 *rdma_argp,
__be32 **write, __be32 **reply)
{
__be32 *p;
p = rdma_argp + rpcrdma_fixed_maxsz;
while (*p++ != xdr_zero)
p += 5;
if (*p != xdr_zero) {
*write = p;
while (*p++ != xdr_zero)
p += 1 + be32_to_cpu(*p) * 4;
} else {
*write = NULL;
p++;
}
if (*p != xdr_zero)
*reply = p;
else
*reply = NULL;
}
static u32 svc_rdma_get_inv_rkey(__be32 *rdma_argp,
__be32 *wr_lst, __be32 *rp_ch)
{
__be32 *p;
p = rdma_argp + rpcrdma_fixed_maxsz;
if (*p != xdr_zero)
p += 2;
else if (wr_lst && be32_to_cpup(wr_lst + 1))
p = wr_lst + 2;
else if (rp_ch && be32_to_cpup(rp_ch + 1))
p = rp_ch + 2;
else
return 0;
return be32_to_cpup(p);
}
static int svc_rdma_dma_map_buf(struct svcxprt_rdma *rdma,
struct svc_rdma_op_ctxt *ctxt,
unsigned int sge_no,
unsigned char *base,
unsigned int len)
{
unsigned long offset = (unsigned long)base & ~PAGE_MASK;
struct ib_device *dev = rdma->sc_cm_id->device;
dma_addr_t dma_addr;
dma_addr = ib_dma_map_page(dev, virt_to_page(base),
offset, len, DMA_TO_DEVICE);
if (ib_dma_mapping_error(dev, dma_addr))
return -EIO;
ctxt->sge[sge_no].addr = dma_addr;
ctxt->sge[sge_no].length = len;
ctxt->sge[sge_no].lkey = rdma->sc_pd->local_dma_lkey;
svc_rdma_count_mappings(rdma, ctxt);
return 0;
}
static int svc_rdma_dma_map_page(struct svcxprt_rdma *rdma,
struct svc_rdma_op_ctxt *ctxt,
unsigned int sge_no,
struct page *page,
unsigned int offset,
unsigned int len)
{
struct ib_device *dev = rdma->sc_cm_id->device;
dma_addr_t dma_addr;
dma_addr = ib_dma_map_page(dev, page, offset, len, DMA_TO_DEVICE);
if (ib_dma_mapping_error(dev, dma_addr))
return -EIO;
ctxt->sge[sge_no].addr = dma_addr;
ctxt->sge[sge_no].length = len;
ctxt->sge[sge_no].lkey = rdma->sc_pd->local_dma_lkey;
svc_rdma_count_mappings(rdma, ctxt);
return 0;
}
int svc_rdma_map_reply_hdr(struct svcxprt_rdma *rdma,
struct svc_rdma_op_ctxt *ctxt,
__be32 *rdma_resp,
unsigned int len)
{
ctxt->direction = DMA_TO_DEVICE;
ctxt->pages[0] = virt_to_page(rdma_resp);
ctxt->count = 1;
return svc_rdma_dma_map_page(rdma, ctxt, 0, ctxt->pages[0], 0, len);
}
static int svc_rdma_map_reply_msg(struct svcxprt_rdma *rdma,
struct svc_rdma_op_ctxt *ctxt,
struct xdr_buf *xdr, __be32 *wr_lst)
{
unsigned int len, sge_no, remaining, page_off;
struct page **ppages;
unsigned char *base;
u32 xdr_pad;
int ret;
sge_no = 1;
ret = svc_rdma_dma_map_buf(rdma, ctxt, sge_no++,
xdr->head[0].iov_base,
xdr->head[0].iov_len);
if (ret < 0)
return ret;
if (wr_lst) {
base = xdr->tail[0].iov_base;
len = xdr->tail[0].iov_len;
xdr_pad = xdr_padsize(xdr->page_len);
if (len && xdr_pad) {
base += xdr_pad;
len -= xdr_pad;
}
goto tail;
}
ppages = xdr->pages + (xdr->page_base >> PAGE_SHIFT);
page_off = xdr->page_base & ~PAGE_MASK;
remaining = xdr->page_len;
while (remaining) {
len = min_t(u32, PAGE_SIZE - page_off, remaining);
ret = svc_rdma_dma_map_page(rdma, ctxt, sge_no++,
*ppages++, page_off, len);
if (ret < 0)
return ret;
remaining -= len;
page_off = 0;
}
base = xdr->tail[0].iov_base;
len = xdr->tail[0].iov_len;
tail:
if (len) {
ret = svc_rdma_dma_map_buf(rdma, ctxt, sge_no++, base, len);
if (ret < 0)
return ret;
}
return sge_no - 1;
}
static void svc_rdma_save_io_pages(struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *ctxt)
{
int i, pages = rqstp->rq_next_page - rqstp->rq_respages;
ctxt->count += pages;
for (i = 0; i < pages; i++) {
ctxt->pages[i + 1] = rqstp->rq_respages[i];
rqstp->rq_respages[i] = NULL;
}
rqstp->rq_next_page = rqstp->rq_respages + 1;
}
int svc_rdma_post_send_wr(struct svcxprt_rdma *rdma,
struct svc_rdma_op_ctxt *ctxt, int num_sge,
u32 inv_rkey)
{
struct ib_send_wr *send_wr = &ctxt->send_wr;
dprintk("svcrdma: posting Send WR with %u sge(s)\n", num_sge);
send_wr->next = NULL;
ctxt->cqe.done = svc_rdma_wc_send;
send_wr->wr_cqe = &ctxt->cqe;
send_wr->sg_list = ctxt->sge;
send_wr->num_sge = num_sge;
send_wr->send_flags = IB_SEND_SIGNALED;
if (inv_rkey) {
send_wr->opcode = IB_WR_SEND_WITH_INV;
send_wr->ex.invalidate_rkey = inv_rkey;
} else {
send_wr->opcode = IB_WR_SEND;
}
return svc_rdma_send(rdma, send_wr);
}
static int svc_rdma_send_reply_msg(struct svcxprt_rdma *rdma,
__be32 *rdma_argp, __be32 *rdma_resp,
struct svc_rqst *rqstp,
__be32 *wr_lst, __be32 *rp_ch)
{
struct svc_rdma_op_ctxt *ctxt;
u32 inv_rkey;
int ret;
dprintk("svcrdma: sending %s reply: head=%zu, pagelen=%u, tail=%zu\n",
(rp_ch ? "RDMA_NOMSG" : "RDMA_MSG"),
rqstp->rq_res.head[0].iov_len,
rqstp->rq_res.page_len,
rqstp->rq_res.tail[0].iov_len);
ctxt = svc_rdma_get_context(rdma);
ret = svc_rdma_map_reply_hdr(rdma, ctxt, rdma_resp,
svc_rdma_reply_hdr_len(rdma_resp));
if (ret < 0)
goto err;
if (!rp_ch) {
ret = svc_rdma_map_reply_msg(rdma, ctxt,
&rqstp->rq_res, wr_lst);
if (ret < 0)
goto err;
}
svc_rdma_save_io_pages(rqstp, ctxt);
inv_rkey = 0;
if (rdma->sc_snd_w_inv)
inv_rkey = svc_rdma_get_inv_rkey(rdma_argp, wr_lst, rp_ch);
ret = svc_rdma_post_send_wr(rdma, ctxt, 1 + ret, inv_rkey);
if (ret)
goto err;
return 0;
err:
pr_err("svcrdma: failed to post Send WR (%d)\n", ret);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
return ret;
}
static int svc_rdma_send_error_msg(struct svcxprt_rdma *rdma,
__be32 *rdma_resp, struct svc_rqst *rqstp)
{
struct svc_rdma_op_ctxt *ctxt;
__be32 *p;
int ret;
ctxt = svc_rdma_get_context(rdma);
p = rdma_resp + 3;
*p++ = rdma_error;
*p = err_chunk;
ret = svc_rdma_map_reply_hdr(rdma, ctxt, rdma_resp, 20);
if (ret < 0)
goto err;
svc_rdma_save_io_pages(rqstp, ctxt);
ret = svc_rdma_post_send_wr(rdma, ctxt, 1 + ret, 0);
if (ret)
goto err;
return 0;
err:
pr_err("svcrdma: failed to post Send WR (%d)\n", ret);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
return ret;
}
void svc_rdma_prep_reply_hdr(struct svc_rqst *rqstp)
{
}
int svc_rdma_sendto(struct svc_rqst *rqstp)
{
struct svc_xprt *xprt = rqstp->rq_xprt;
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
__be32 *p, *rdma_argp, *rdma_resp, *wr_lst, *rp_ch;
struct xdr_buf *xdr = &rqstp->rq_res;
struct page *res_page;
int ret;
rdma_argp = page_address(rqstp->rq_pages[0]);
svc_rdma_get_write_arrays(rdma_argp, &wr_lst, &rp_ch);
dprintk("svcrdma: preparing response for XID 0x%08x\n",
be32_to_cpup(rdma_argp));
ret = -ENOMEM;
res_page = alloc_page(GFP_KERNEL);
if (!res_page)
goto err0;
rdma_resp = page_address(res_page);
p = rdma_resp;
*p++ = *rdma_argp;
*p++ = *(rdma_argp + 1);
*p++ = rdma->sc_fc_credits;
*p++ = rp_ch ? rdma_nomsg : rdma_msg;
*p++ = xdr_zero;
*p++ = xdr_zero;
*p = xdr_zero;
if (wr_lst) {
ret = svc_rdma_send_write_chunk(rdma, wr_lst, xdr);
if (ret < 0)
goto err2;
svc_rdma_xdr_encode_write_list(rdma_resp, wr_lst, ret);
}
if (rp_ch) {
ret = svc_rdma_send_reply_chunk(rdma, rp_ch, wr_lst, xdr);
if (ret < 0)
goto err2;
svc_rdma_xdr_encode_reply_chunk(rdma_resp, rp_ch, ret);
}
ret = svc_rdma_post_recv(rdma, GFP_KERNEL);
if (ret)
goto err1;
ret = svc_rdma_send_reply_msg(rdma, rdma_argp, rdma_resp, rqstp,
wr_lst, rp_ch);
if (ret < 0)
goto err0;
return 0;
err2:
if (ret != -E2BIG)
goto err1;
ret = svc_rdma_post_recv(rdma, GFP_KERNEL);
if (ret)
goto err1;
ret = svc_rdma_send_error_msg(rdma, rdma_resp, rqstp);
if (ret < 0)
goto err0;
return 0;
err1:
put_page(res_page);
err0:
pr_err("svcrdma: Could not send reply, err=%d. Closing transport.\n",
ret);
set_bit(XPT_CLOSE, &xprt->xpt_flags);
return -ENOTCONN;
}
