static int map_xdr(struct svcxprt_rdma *xprt,
struct xdr_buf *xdr,
struct svc_rdma_req_map *vec)
{
int sge_no;
u32 sge_bytes;
u32 page_bytes;
u32 page_off;
int page_no;
if (xdr->len !=
(xdr->head[0].iov_len + xdr->page_len + xdr->tail[0].iov_len)) {
pr_err("svcrdma: map_xdr: XDR buffer length error\n");
return -EIO;
}
sge_no = 1;
vec->sge[sge_no].iov_base = xdr->head[0].iov_base;
vec->sge[sge_no].iov_len = xdr->head[0].iov_len;
sge_no++;
page_no = 0;
page_bytes = xdr->page_len;
page_off = xdr->page_base;
while (page_bytes) {
vec->sge[sge_no].iov_base =
page_address(xdr->pages[page_no]) + page_off;
sge_bytes = min_t(u32, page_bytes, (PAGE_SIZE - page_off));
page_bytes -= sge_bytes;
vec->sge[sge_no].iov_len = sge_bytes;
sge_no++;
page_no++;
page_off = 0;
}
if (xdr->tail[0].iov_len) {
vec->sge[sge_no].iov_base = xdr->tail[0].iov_base;
vec->sge[sge_no].iov_len = xdr->tail[0].iov_len;
sge_no++;
}
dprintk("svcrdma: map_xdr: sge_no %d page_no %d "
"page_base %u page_len %u head_len %zu tail_len %zu\n",
sge_no, page_no, xdr->page_base, xdr->page_len,
xdr->head[0].iov_len, xdr->tail[0].iov_len);
vec->count = sge_no;
return 0;
}
static dma_addr_t dma_map_xdr(struct svcxprt_rdma *xprt,
struct xdr_buf *xdr,
u32 xdr_off, size_t len, int dir)
{
struct page *page;
dma_addr_t dma_addr;
if (xdr_off < xdr->head[0].iov_len) {
xdr_off += (unsigned long)xdr->head[0].iov_base & ~PAGE_MASK;
page = virt_to_page(xdr->head[0].iov_base);
} else {
xdr_off -= xdr->head[0].iov_len;
if (xdr_off < xdr->page_len) {
xdr_off += xdr->page_base;
page = xdr->pages[xdr_off >> PAGE_SHIFT];
xdr_off &= ~PAGE_MASK;
} else {
xdr_off -= xdr->page_len;
xdr_off += (unsigned long)
xdr->tail[0].iov_base & ~PAGE_MASK;
page = virt_to_page(xdr->tail[0].iov_base);
}
}
dma_addr = ib_dma_map_page(xprt->sc_cm_id->device, page, xdr_off,
min_t(size_t, PAGE_SIZE, len), dir);
return dma_addr;
}
static int send_write(struct svcxprt_rdma *xprt, struct svc_rqst *rqstp,
u32 rmr, u64 to,
u32 xdr_off, int write_len,
struct svc_rdma_req_map *vec)
{
struct ib_send_wr write_wr;
struct ib_sge *sge;
int xdr_sge_no;
int sge_no;
int sge_bytes;
int sge_off;
int bc;
struct svc_rdma_op_ctxt *ctxt;
if (vec->count > RPCSVC_MAXPAGES) {
pr_err("svcrdma: Too many pages (%lu)\n", vec->count);
return -EIO;
}
dprintk("svcrdma: RDMA_WRITE rmr=%x, to=%llx, xdr_off=%d, "
"write_len=%d, vec->sge=%p, vec->count=%lu\n",
rmr, (unsigned long long)to, xdr_off,
write_len, vec->sge, vec->count);
ctxt = svc_rdma_get_context(xprt);
ctxt->direction = DMA_TO_DEVICE;
sge = ctxt->sge;
for (bc = xdr_off, xdr_sge_no = 1; bc && xdr_sge_no < vec->count;
xdr_sge_no++) {
if (vec->sge[xdr_sge_no].iov_len > bc)
break;
bc -= vec->sge[xdr_sge_no].iov_len;
}
sge_off = bc;
bc = write_len;
sge_no = 0;
while (bc != 0) {
sge_bytes = min_t(size_t,
bc, vec->sge[xdr_sge_no].iov_len-sge_off);
sge[sge_no].length = sge_bytes;
sge[sge_no].addr =
dma_map_xdr(xprt, &rqstp->rq_res, xdr_off,
sge_bytes, DMA_TO_DEVICE);
xdr_off += sge_bytes;
if (ib_dma_mapping_error(xprt->sc_cm_id->device,
sge[sge_no].addr))
goto err;
atomic_inc(&xprt->sc_dma_used);
sge[sge_no].lkey = xprt->sc_dma_lkey;
ctxt->count++;
sge_off = 0;
sge_no++;
xdr_sge_no++;
if (xdr_sge_no > vec->count) {
pr_err("svcrdma: Too many sges (%d)\n", xdr_sge_no);
goto err;
}
bc -= sge_bytes;
if (sge_no == xprt->sc_max_sge)
break;
}
memset(&write_wr, 0, sizeof write_wr);
ctxt->wr_op = IB_WR_RDMA_WRITE;
write_wr.wr_id = (unsigned long)ctxt;
write_wr.sg_list = &sge[0];
write_wr.num_sge = sge_no;
write_wr.opcode = IB_WR_RDMA_WRITE;
write_wr.send_flags = IB_SEND_SIGNALED;
write_wr.wr.rdma.rkey = rmr;
write_wr.wr.rdma.remote_addr = to;
atomic_inc(&rdma_stat_write);
if (svc_rdma_send(xprt, &write_wr))
goto err;
return write_len - bc;
err:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 0);
return -EIO;
}
static int send_write_chunks(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rdma_argp,
struct rpcrdma_msg *rdma_resp,
struct svc_rqst *rqstp,
struct svc_rdma_req_map *vec)
{
u32 xfer_len = rqstp->rq_res.page_len + rqstp->rq_res.tail[0].iov_len;
int write_len;
u32 xdr_off;
int chunk_off;
int chunk_no;
int nchunks;
struct rpcrdma_write_array *arg_ary;
struct rpcrdma_write_array *res_ary;
int ret;
arg_ary = svc_rdma_get_write_array(rdma_argp);
if (!arg_ary)
return 0;
res_ary = (struct rpcrdma_write_array *)
&rdma_resp->rm_body.rm_chunks[1];
nchunks = be32_to_cpu(arg_ary->wc_nchunks);
for (xdr_off = rqstp->rq_res.head[0].iov_len, chunk_no = 0;
xfer_len && chunk_no < nchunks;
chunk_no++) {
struct rpcrdma_segment *arg_ch;
u64 rs_offset;
arg_ch = &arg_ary->wc_array[chunk_no].wc_target;
write_len = min(xfer_len, be32_to_cpu(arg_ch->rs_length));
xdr_decode_hyper((__be32 *)&arg_ch->rs_offset, &rs_offset);
svc_rdma_xdr_encode_array_chunk(res_ary, chunk_no,
arg_ch->rs_handle,
arg_ch->rs_offset,
write_len);
chunk_off = 0;
while (write_len) {
ret = send_write(xprt, rqstp,
be32_to_cpu(arg_ch->rs_handle),
rs_offset + chunk_off,
xdr_off,
write_len,
vec);
if (ret <= 0) {
dprintk("svcrdma: RDMA_WRITE failed, ret=%d\n",
ret);
return -EIO;
}
chunk_off += ret;
xdr_off += ret;
xfer_len -= ret;
write_len -= ret;
}
}
svc_rdma_xdr_encode_write_list(rdma_resp, chunk_no);
return rqstp->rq_res.page_len + rqstp->rq_res.tail[0].iov_len;
}
static int send_reply_chunks(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rdma_argp,
struct rpcrdma_msg *rdma_resp,
struct svc_rqst *rqstp,
struct svc_rdma_req_map *vec)
{
u32 xfer_len = rqstp->rq_res.len;
int write_len;
u32 xdr_off;
int chunk_no;
int chunk_off;
int nchunks;
struct rpcrdma_segment *ch;
struct rpcrdma_write_array *arg_ary;
struct rpcrdma_write_array *res_ary;
int ret;
arg_ary = svc_rdma_get_reply_array(rdma_argp);
if (!arg_ary)
return 0;
res_ary = (struct rpcrdma_write_array *)
&rdma_resp->rm_body.rm_chunks[2];
nchunks = be32_to_cpu(arg_ary->wc_nchunks);
for (xdr_off = 0, chunk_no = 0;
xfer_len && chunk_no < nchunks;
chunk_no++) {
u64 rs_offset;
ch = &arg_ary->wc_array[chunk_no].wc_target;
write_len = min(xfer_len, be32_to_cpu(ch->rs_length));
xdr_decode_hyper((__be32 *)&ch->rs_offset, &rs_offset);
svc_rdma_xdr_encode_array_chunk(res_ary, chunk_no,
ch->rs_handle, ch->rs_offset,
write_len);
chunk_off = 0;
while (write_len) {
ret = send_write(xprt, rqstp,
be32_to_cpu(ch->rs_handle),
rs_offset + chunk_off,
xdr_off,
write_len,
vec);
if (ret <= 0) {
dprintk("svcrdma: RDMA_WRITE failed, ret=%d\n",
ret);
return -EIO;
}
chunk_off += ret;
xdr_off += ret;
xfer_len -= ret;
write_len -= ret;
}
}
svc_rdma_xdr_encode_reply_array(res_ary, chunk_no);
return rqstp->rq_res.len;
}
static int send_reply(struct svcxprt_rdma *rdma,
struct svc_rqst *rqstp,
struct page *page,
struct rpcrdma_msg *rdma_resp,
struct svc_rdma_op_ctxt *ctxt,
struct svc_rdma_req_map *vec,
int byte_count)
{
struct ib_send_wr send_wr;
int sge_no;
int sge_bytes;
int page_no;
int pages;
int ret;
ret = svc_rdma_post_recv(rdma);
if (ret) {
printk(KERN_INFO
"svcrdma: could not post a receive buffer, err=%d."
"Closing transport %p.\n", ret, rdma);
set_bit(XPT_CLOSE, &rdma->sc_xprt.xpt_flags);
svc_rdma_put_context(ctxt, 0);
return -ENOTCONN;
}
ctxt->pages[0] = page;
ctxt->count = 1;
ctxt->sge[0].lkey = rdma->sc_dma_lkey;
ctxt->sge[0].length = svc_rdma_xdr_get_reply_hdr_len(rdma_resp);
ctxt->sge[0].addr =
ib_dma_map_page(rdma->sc_cm_id->device, page, 0,
ctxt->sge[0].length, DMA_TO_DEVICE);
if (ib_dma_mapping_error(rdma->sc_cm_id->device, ctxt->sge[0].addr))
goto err;
atomic_inc(&rdma->sc_dma_used);
ctxt->direction = DMA_TO_DEVICE;
for (sge_no = 1; byte_count && sge_no < vec->count; sge_no++) {
int xdr_off = 0;
sge_bytes = min_t(size_t, vec->sge[sge_no].iov_len, byte_count);
byte_count -= sge_bytes;
ctxt->sge[sge_no].addr =
dma_map_xdr(rdma, &rqstp->rq_res, xdr_off,
sge_bytes, DMA_TO_DEVICE);
xdr_off += sge_bytes;
if (ib_dma_mapping_error(rdma->sc_cm_id->device,
ctxt->sge[sge_no].addr))
goto err;
atomic_inc(&rdma->sc_dma_used);
ctxt->sge[sge_no].lkey = rdma->sc_dma_lkey;
ctxt->sge[sge_no].length = sge_bytes;
}
if (byte_count != 0) {
pr_err("svcrdma: Could not map %d bytes\n", byte_count);
goto err;
}
pages = rqstp->rq_next_page - rqstp->rq_respages;
for (page_no = 0; page_no < pages; page_no++) {
ctxt->pages[page_no+1] = rqstp->rq_respages[page_no];
ctxt->count++;
rqstp->rq_respages[page_no] = NULL;
if (page_no+1 >= sge_no)
ctxt->sge[page_no+1].length = 0;
}
rqstp->rq_next_page = rqstp->rq_respages + 1;
if (sge_no > rdma->sc_max_sge) {
pr_err("svcrdma: Too many sges (%d)\n", sge_no);
goto err;
}
memset(&send_wr, 0, sizeof send_wr);
ctxt->wr_op = IB_WR_SEND;
send_wr.wr_id = (unsigned long)ctxt;
send_wr.sg_list = ctxt->sge;
send_wr.num_sge = sge_no;
send_wr.opcode = IB_WR_SEND;
send_wr.send_flags = IB_SEND_SIGNALED;
ret = svc_rdma_send(rdma, &send_wr);
if (ret)
goto err;
return 0;
err:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
return -EIO;
}
void svc_rdma_prep_reply_hdr(struct svc_rqst *rqstp)
{
}
int svc_rdma_sendto(struct svc_rqst *rqstp)
{
struct svc_xprt *xprt = rqstp->rq_xprt;
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
struct rpcrdma_msg *rdma_argp;
struct rpcrdma_msg *rdma_resp;
struct rpcrdma_write_array *reply_ary;
enum rpcrdma_proc reply_type;
int ret;
int inline_bytes;
struct page *res_page;
struct svc_rdma_op_ctxt *ctxt;
struct svc_rdma_req_map *vec;
dprintk("svcrdma: sending response for rqstp=%p\n", rqstp);
rdma_argp = page_address(rqstp->rq_pages[0]);
ctxt = svc_rdma_get_context(rdma);
ctxt->direction = DMA_TO_DEVICE;
vec = svc_rdma_get_req_map();
ret = map_xdr(rdma, &rqstp->rq_res, vec);
if (ret)
goto err0;
inline_bytes = rqstp->rq_res.len;
res_page = alloc_page(GFP_KERNEL | __GFP_NOFAIL);
rdma_resp = page_address(res_page);
reply_ary = svc_rdma_get_reply_array(rdma_argp);
if (reply_ary)
reply_type = RDMA_NOMSG;
else
reply_type = RDMA_MSG;
svc_rdma_xdr_encode_reply_header(rdma, rdma_argp,
rdma_resp, reply_type);
ret = send_write_chunks(rdma, rdma_argp, rdma_resp,
rqstp, vec);
if (ret < 0) {
printk(KERN_ERR "svcrdma: failed to send write chunks, rc=%d\n",
ret);
goto err1;
}
inline_bytes -= ret;
ret = send_reply_chunks(rdma, rdma_argp, rdma_resp,
rqstp, vec);
if (ret < 0) {
printk(KERN_ERR "svcrdma: failed to send reply chunks, rc=%d\n",
ret);
goto err1;
}
inline_bytes -= ret;
ret = send_reply(rdma, rqstp, res_page, rdma_resp, ctxt, vec,
inline_bytes);
svc_rdma_put_req_map(vec);
dprintk("svcrdma: send_reply returns %d\n", ret);
return ret;
err1:
put_page(res_page);
err0:
svc_rdma_put_req_map(vec);
svc_rdma_put_context(ctxt, 0);
return ret;
}
