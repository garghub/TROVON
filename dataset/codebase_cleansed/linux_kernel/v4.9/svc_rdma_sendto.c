static u32 xdr_padsize(u32 len)
{
return (len & 3) ? (4 - (len & 3)) : 0;
}
int svc_rdma_map_xdr(struct svcxprt_rdma *xprt,
struct xdr_buf *xdr,
struct svc_rdma_req_map *vec,
bool write_chunk_present)
{
int sge_no;
u32 sge_bytes;
u32 page_bytes;
u32 page_off;
int page_no;
if (xdr->len !=
(xdr->head[0].iov_len + xdr->page_len + xdr->tail[0].iov_len)) {
pr_err("svcrdma: %s: XDR buffer length error\n", __func__);
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
unsigned char *base = xdr->tail[0].iov_base;
size_t len = xdr->tail[0].iov_len;
u32 xdr_pad = xdr_padsize(xdr->page_len);
if (write_chunk_present && xdr_pad) {
base += xdr_pad;
len -= xdr_pad;
}
if (len) {
vec->sge[sge_no].iov_base = base;
vec->sge[sge_no].iov_len = len;
sge_no++;
}
}
dprintk("svcrdma: %s: sge_no %d page_no %d "
"page_base %u page_len %u head_len %zu tail_len %zu\n",
__func__, sge_no, page_no, xdr->page_base, xdr->page_len,
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
struct rpcrdma_read_chunk *
svc_rdma_get_read_chunk(struct rpcrdma_msg *rmsgp)
{
struct rpcrdma_read_chunk *ch =
(struct rpcrdma_read_chunk *)&rmsgp->rm_body.rm_chunks[0];
if (ch->rc_discrim == xdr_zero)
return NULL;
return ch;
}
static struct rpcrdma_write_array *
svc_rdma_get_write_array(struct rpcrdma_msg *rmsgp)
{
if (rmsgp->rm_body.rm_chunks[0] != xdr_zero ||
rmsgp->rm_body.rm_chunks[1] == xdr_zero)
return NULL;
return (struct rpcrdma_write_array *)&rmsgp->rm_body.rm_chunks[1];
}
static struct rpcrdma_write_array *
svc_rdma_get_reply_array(struct rpcrdma_msg *rmsgp,
struct rpcrdma_write_array *wr_ary)
{
struct rpcrdma_read_chunk *rch;
struct rpcrdma_write_array *rp_ary;
if (rmsgp->rm_body.rm_chunks[0] != xdr_zero ||
rmsgp->rm_body.rm_chunks[1] != xdr_zero)
return NULL;
rch = svc_rdma_get_read_chunk(rmsgp);
if (rch) {
while (rch->rc_discrim != xdr_zero)
rch++;
rp_ary = (struct rpcrdma_write_array *)&rch->rc_target;
goto found_it;
}
if (wr_ary) {
int chunk = be32_to_cpu(wr_ary->wc_nchunks);
rp_ary = (struct rpcrdma_write_array *)
&wr_ary->wc_array[chunk].wc_target.rs_length;
goto found_it;
}
rp_ary = (struct rpcrdma_write_array *)&rmsgp->rm_body.rm_chunks[2];
found_it:
if (rp_ary->wc_discrim == xdr_zero)
return NULL;
return rp_ary;
}
static u32 svc_rdma_get_inv_rkey(struct rpcrdma_msg *rdma_argp,
struct rpcrdma_write_array *wr_ary,
struct rpcrdma_write_array *rp_ary)
{
struct rpcrdma_read_chunk *rd_ary;
struct rpcrdma_segment *arg_ch;
u32 inv_rkey;
inv_rkey = 0;
rd_ary = svc_rdma_get_read_chunk(rdma_argp);
if (rd_ary) {
inv_rkey = be32_to_cpu(rd_ary->rc_target.rs_handle);
goto out;
}
if (wr_ary && be32_to_cpu(wr_ary->wc_nchunks)) {
arg_ch = &wr_ary->wc_array[0].wc_target;
inv_rkey = be32_to_cpu(arg_ch->rs_handle);
goto out;
}
if (rp_ary && be32_to_cpu(rp_ary->wc_nchunks)) {
arg_ch = &rp_ary->wc_array[0].wc_target;
inv_rkey = be32_to_cpu(arg_ch->rs_handle);
goto out;
}
out:
dprintk("svcrdma: Send With Invalidate rkey=%08x\n", inv_rkey);
return inv_rkey;
}
static int send_write(struct svcxprt_rdma *xprt, struct svc_rqst *rqstp,
u32 rmr, u64 to,
u32 xdr_off, int write_len,
struct svc_rdma_req_map *vec)
{
struct ib_rdma_wr write_wr;
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
svc_rdma_count_mappings(xprt, ctxt);
sge[sge_no].lkey = xprt->sc_pd->local_dma_lkey;
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
ctxt->cqe.done = svc_rdma_wc_write;
write_wr.wr.wr_cqe = &ctxt->cqe;
write_wr.wr.sg_list = &sge[0];
write_wr.wr.num_sge = sge_no;
write_wr.wr.opcode = IB_WR_RDMA_WRITE;
write_wr.wr.send_flags = IB_SEND_SIGNALED;
write_wr.rkey = rmr;
write_wr.remote_addr = to;
atomic_inc(&rdma_stat_write);
if (svc_rdma_send(xprt, &write_wr.wr))
goto err;
return write_len - bc;
err:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 0);
return -EIO;
}
noinline
static int send_write_chunks(struct svcxprt_rdma *xprt,
struct rpcrdma_write_array *wr_ary,
struct rpcrdma_msg *rdma_resp,
struct svc_rqst *rqstp,
struct svc_rdma_req_map *vec)
{
u32 xfer_len = rqstp->rq_res.page_len;
int write_len;
u32 xdr_off;
int chunk_off;
int chunk_no;
int nchunks;
struct rpcrdma_write_array *res_ary;
int ret;
res_ary = (struct rpcrdma_write_array *)
&rdma_resp->rm_body.rm_chunks[1];
nchunks = be32_to_cpu(wr_ary->wc_nchunks);
for (xdr_off = rqstp->rq_res.head[0].iov_len, chunk_no = 0;
xfer_len && chunk_no < nchunks;
chunk_no++) {
struct rpcrdma_segment *arg_ch;
u64 rs_offset;
arg_ch = &wr_ary->wc_array[chunk_no].wc_target;
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
if (ret <= 0)
goto out_err;
chunk_off += ret;
xdr_off += ret;
xfer_len -= ret;
write_len -= ret;
}
}
svc_rdma_xdr_encode_write_list(rdma_resp, chunk_no);
return rqstp->rq_res.page_len;
out_err:
pr_err("svcrdma: failed to send write chunks, rc=%d\n", ret);
return -EIO;
}
noinline
static int send_reply_chunks(struct svcxprt_rdma *xprt,
struct rpcrdma_write_array *rp_ary,
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
struct rpcrdma_write_array *res_ary;
int ret;
res_ary = (struct rpcrdma_write_array *)
&rdma_resp->rm_body.rm_chunks[2];
nchunks = be32_to_cpu(rp_ary->wc_nchunks);
for (xdr_off = 0, chunk_no = 0;
xfer_len && chunk_no < nchunks;
chunk_no++) {
u64 rs_offset;
ch = &rp_ary->wc_array[chunk_no].wc_target;
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
if (ret <= 0)
goto out_err;
chunk_off += ret;
xdr_off += ret;
xfer_len -= ret;
write_len -= ret;
}
}
svc_rdma_xdr_encode_reply_array(res_ary, chunk_no);
return rqstp->rq_res.len;
out_err:
pr_err("svcrdma: failed to send reply chunks, rc=%d\n", ret);
return -EIO;
}
static int send_reply(struct svcxprt_rdma *rdma,
struct svc_rqst *rqstp,
struct page *page,
struct rpcrdma_msg *rdma_resp,
struct svc_rdma_req_map *vec,
int byte_count,
u32 inv_rkey)
{
struct svc_rdma_op_ctxt *ctxt;
struct ib_send_wr send_wr;
u32 xdr_off;
int sge_no;
int sge_bytes;
int page_no;
int pages;
int ret = -EIO;
ctxt = svc_rdma_get_context(rdma);
ctxt->direction = DMA_TO_DEVICE;
ctxt->pages[0] = page;
ctxt->count = 1;
ctxt->sge[0].lkey = rdma->sc_pd->local_dma_lkey;
ctxt->sge[0].length = svc_rdma_xdr_get_reply_hdr_len(rdma_resp);
ctxt->sge[0].addr =
ib_dma_map_page(rdma->sc_cm_id->device, page, 0,
ctxt->sge[0].length, DMA_TO_DEVICE);
if (ib_dma_mapping_error(rdma->sc_cm_id->device, ctxt->sge[0].addr))
goto err;
svc_rdma_count_mappings(rdma, ctxt);
ctxt->direction = DMA_TO_DEVICE;
xdr_off = 0;
for (sge_no = 1; byte_count && sge_no < vec->count; sge_no++) {
sge_bytes = min_t(size_t, vec->sge[sge_no].iov_len, byte_count);
byte_count -= sge_bytes;
ctxt->sge[sge_no].addr =
dma_map_xdr(rdma, &rqstp->rq_res, xdr_off,
sge_bytes, DMA_TO_DEVICE);
xdr_off += sge_bytes;
if (ib_dma_mapping_error(rdma->sc_cm_id->device,
ctxt->sge[sge_no].addr))
goto err;
svc_rdma_count_mappings(rdma, ctxt);
ctxt->sge[sge_no].lkey = rdma->sc_pd->local_dma_lkey;
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
}
rqstp->rq_next_page = rqstp->rq_respages + 1;
if (sge_no > rdma->sc_max_sge) {
pr_err("svcrdma: Too many sges (%d)\n", sge_no);
goto err;
}
memset(&send_wr, 0, sizeof send_wr);
ctxt->cqe.done = svc_rdma_wc_send;
send_wr.wr_cqe = &ctxt->cqe;
send_wr.sg_list = ctxt->sge;
send_wr.num_sge = sge_no;
if (inv_rkey) {
send_wr.opcode = IB_WR_SEND_WITH_INV;
send_wr.ex.invalidate_rkey = inv_rkey;
} else
send_wr.opcode = IB_WR_SEND;
send_wr.send_flags = IB_SEND_SIGNALED;
ret = svc_rdma_send(rdma, &send_wr);
if (ret)
goto err;
return 0;
err:
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
struct rpcrdma_msg *rdma_argp;
struct rpcrdma_msg *rdma_resp;
struct rpcrdma_write_array *wr_ary, *rp_ary;
enum rpcrdma_proc reply_type;
int ret;
int inline_bytes;
struct page *res_page;
struct svc_rdma_req_map *vec;
u32 inv_rkey;
dprintk("svcrdma: sending response for rqstp=%p\n", rqstp);
rdma_argp = page_address(rqstp->rq_pages[0]);
wr_ary = svc_rdma_get_write_array(rdma_argp);
rp_ary = svc_rdma_get_reply_array(rdma_argp, wr_ary);
inv_rkey = 0;
if (rdma->sc_snd_w_inv)
inv_rkey = svc_rdma_get_inv_rkey(rdma_argp, wr_ary, rp_ary);
vec = svc_rdma_get_req_map(rdma);
ret = svc_rdma_map_xdr(rdma, &rqstp->rq_res, vec, wr_ary != NULL);
if (ret)
goto err0;
inline_bytes = rqstp->rq_res.len;
ret = -ENOMEM;
res_page = alloc_page(GFP_KERNEL);
if (!res_page)
goto err0;
rdma_resp = page_address(res_page);
if (rp_ary)
reply_type = RDMA_NOMSG;
else
reply_type = RDMA_MSG;
svc_rdma_xdr_encode_reply_header(rdma, rdma_argp,
rdma_resp, reply_type);
if (wr_ary) {
ret = send_write_chunks(rdma, wr_ary, rdma_resp, rqstp, vec);
if (ret < 0)
goto err1;
inline_bytes -= ret + xdr_padsize(ret);
}
if (rp_ary) {
ret = send_reply_chunks(rdma, rp_ary, rdma_resp, rqstp, vec);
if (ret < 0)
goto err1;
inline_bytes -= ret;
}
ret = svc_rdma_post_recv(rdma, GFP_KERNEL);
if (ret)
goto err1;
ret = send_reply(rdma, rqstp, res_page, rdma_resp, vec,
inline_bytes, inv_rkey);
if (ret < 0)
goto err0;
svc_rdma_put_req_map(rdma, vec);
dprintk("svcrdma: send_reply returns %d\n", ret);
return ret;
err1:
put_page(res_page);
err0:
svc_rdma_put_req_map(rdma, vec);
pr_err("svcrdma: Could not send reply, err=%d. Closing transport.\n",
ret);
set_bit(XPT_CLOSE, &rdma->sc_xprt.xpt_flags);
return -ENOTCONN;
}
void svc_rdma_send_error(struct svcxprt_rdma *xprt, struct rpcrdma_msg *rmsgp,
int status)
{
struct ib_send_wr err_wr;
struct page *p;
struct svc_rdma_op_ctxt *ctxt;
enum rpcrdma_errcode err;
__be32 *va;
int length;
int ret;
ret = svc_rdma_repost_recv(xprt, GFP_KERNEL);
if (ret)
return;
p = alloc_page(GFP_KERNEL);
if (!p)
return;
va = page_address(p);
err = ERR_CHUNK;
if (status == -EPROTONOSUPPORT)
err = ERR_VERS;
length = svc_rdma_xdr_encode_error(xprt, rmsgp, err, va);
ctxt = svc_rdma_get_context(xprt);
ctxt->direction = DMA_TO_DEVICE;
ctxt->count = 1;
ctxt->pages[0] = p;
ctxt->sge[0].lkey = xprt->sc_pd->local_dma_lkey;
ctxt->sge[0].length = length;
ctxt->sge[0].addr = ib_dma_map_page(xprt->sc_cm_id->device,
p, 0, length, DMA_TO_DEVICE);
if (ib_dma_mapping_error(xprt->sc_cm_id->device, ctxt->sge[0].addr)) {
dprintk("svcrdma: Error mapping buffer for protocol error\n");
svc_rdma_put_context(ctxt, 1);
return;
}
svc_rdma_count_mappings(xprt, ctxt);
memset(&err_wr, 0, sizeof(err_wr));
ctxt->cqe.done = svc_rdma_wc_send;
err_wr.wr_cqe = &ctxt->cqe;
err_wr.sg_list = ctxt->sge;
err_wr.num_sge = 1;
err_wr.opcode = IB_WR_SEND;
err_wr.send_flags = IB_SEND_SIGNALED;
ret = svc_rdma_send(xprt, &err_wr);
if (ret) {
dprintk("svcrdma: Error %d posting send for protocol error\n",
ret);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
}
}
