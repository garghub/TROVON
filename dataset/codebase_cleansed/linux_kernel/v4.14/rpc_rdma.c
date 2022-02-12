static unsigned int rpcrdma_max_call_header_size(unsigned int maxsegs)
{
unsigned int size;
size = RPCRDMA_HDRLEN_MIN;
maxsegs += 2;
size = maxsegs * sizeof(struct rpcrdma_read_chunk);
size += sizeof(__be32);
size += sizeof(struct rpcrdma_segment);
size += sizeof(__be32);
dprintk("RPC: %s: max call header size = %u\n",
__func__, size);
return size;
}
static unsigned int rpcrdma_max_reply_header_size(unsigned int maxsegs)
{
unsigned int size;
size = RPCRDMA_HDRLEN_MIN;
maxsegs += 2;
size = sizeof(__be32);
size += maxsegs * sizeof(struct rpcrdma_segment);
size += sizeof(__be32);
dprintk("RPC: %s: max reply header size = %u\n",
__func__, size);
return size;
}
void rpcrdma_set_max_header_sizes(struct rpcrdma_xprt *r_xprt)
{
struct rpcrdma_create_data_internal *cdata = &r_xprt->rx_data;
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
unsigned int maxsegs = ia->ri_max_segs;
ia->ri_max_inline_write = cdata->inline_wsize -
rpcrdma_max_call_header_size(maxsegs);
ia->ri_max_inline_read = cdata->inline_rsize -
rpcrdma_max_reply_header_size(maxsegs);
}
static bool rpcrdma_args_inline(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct xdr_buf *xdr = &rqst->rq_snd_buf;
unsigned int count, remaining, offset;
if (xdr->len > r_xprt->rx_ia.ri_max_inline_write)
return false;
if (xdr->page_len) {
remaining = xdr->page_len;
offset = offset_in_page(xdr->page_base);
count = 0;
while (remaining) {
remaining -= min_t(unsigned int,
PAGE_SIZE - offset, remaining);
offset = 0;
if (++count > r_xprt->rx_ia.ri_max_send_sges)
return false;
}
}
return true;
}
static bool rpcrdma_results_inline(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
return rqst->rq_rcv_buf.buflen <= ia->ri_max_inline_read;
}
static struct rpcrdma_mr_seg *
rpcrdma_convert_kvec(struct kvec *vec, struct rpcrdma_mr_seg *seg,
unsigned int *n)
{
u32 remaining, page_offset;
char *base;
base = vec->iov_base;
page_offset = offset_in_page(base);
remaining = vec->iov_len;
while (remaining) {
seg->mr_page = NULL;
seg->mr_offset = base;
seg->mr_len = min_t(u32, PAGE_SIZE - page_offset, remaining);
remaining -= seg->mr_len;
base += seg->mr_len;
++seg;
++(*n);
page_offset = 0;
}
return seg;
}
static int
rpcrdma_convert_iovs(struct rpcrdma_xprt *r_xprt, struct xdr_buf *xdrbuf,
unsigned int pos, enum rpcrdma_chunktype type,
struct rpcrdma_mr_seg *seg)
{
unsigned long page_base;
unsigned int len, n;
struct page **ppages;
n = 0;
if (pos == 0)
seg = rpcrdma_convert_kvec(&xdrbuf->head[0], seg, &n);
len = xdrbuf->page_len;
ppages = xdrbuf->pages + (xdrbuf->page_base >> PAGE_SHIFT);
page_base = offset_in_page(xdrbuf->page_base);
while (len) {
if (unlikely(!*ppages)) {
*ppages = alloc_page(GFP_ATOMIC);
if (!*ppages)
return -EAGAIN;
}
seg->mr_page = *ppages;
seg->mr_offset = (char *)page_base;
seg->mr_len = min_t(u32, PAGE_SIZE - page_base, len);
len -= seg->mr_len;
++ppages;
++seg;
++n;
page_base = 0;
}
if (type == rpcrdma_readch && r_xprt->rx_ia.ri_implicit_roundup)
goto out;
if (type == rpcrdma_writech && r_xprt->rx_ia.ri_implicit_roundup)
goto out;
if (xdrbuf->tail[0].iov_len)
seg = rpcrdma_convert_kvec(&xdrbuf->tail[0], seg, &n);
out:
if (unlikely(n > RPCRDMA_MAX_SEGS))
return -EIO;
return n;
}
static inline int
encode_item_present(struct xdr_stream *xdr)
{
__be32 *p;
p = xdr_reserve_space(xdr, sizeof(*p));
if (unlikely(!p))
return -EMSGSIZE;
*p = xdr_one;
return 0;
}
static inline int
encode_item_not_present(struct xdr_stream *xdr)
{
__be32 *p;
p = xdr_reserve_space(xdr, sizeof(*p));
if (unlikely(!p))
return -EMSGSIZE;
*p = xdr_zero;
return 0;
}
static void
xdr_encode_rdma_segment(__be32 *iptr, struct rpcrdma_mw *mw)
{
*iptr++ = cpu_to_be32(mw->mw_handle);
*iptr++ = cpu_to_be32(mw->mw_length);
xdr_encode_hyper(iptr, mw->mw_offset);
}
static int
encode_rdma_segment(struct xdr_stream *xdr, struct rpcrdma_mw *mw)
{
__be32 *p;
p = xdr_reserve_space(xdr, 4 * sizeof(*p));
if (unlikely(!p))
return -EMSGSIZE;
xdr_encode_rdma_segment(p, mw);
return 0;
}
static int
encode_read_segment(struct xdr_stream *xdr, struct rpcrdma_mw *mw,
u32 position)
{
__be32 *p;
p = xdr_reserve_space(xdr, 6 * sizeof(*p));
if (unlikely(!p))
return -EMSGSIZE;
*p++ = xdr_one;
*p++ = cpu_to_be32(position);
xdr_encode_rdma_segment(p, mw);
return 0;
}
static noinline int
rpcrdma_encode_read_list(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
struct rpc_rqst *rqst, enum rpcrdma_chunktype rtype)
{
struct xdr_stream *xdr = &req->rl_stream;
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
unsigned int pos;
int nsegs;
pos = rqst->rq_snd_buf.head[0].iov_len;
if (rtype == rpcrdma_areadch)
pos = 0;
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(r_xprt, &rqst->rq_snd_buf, pos,
rtype, seg);
if (nsegs < 0)
return nsegs;
do {
seg = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
false, &mw);
if (IS_ERR(seg))
return PTR_ERR(seg);
rpcrdma_push_mw(mw, &req->rl_registered);
if (encode_read_segment(xdr, mw, pos) < 0)
return -EMSGSIZE;
dprintk("RPC: %5u %s: pos %u %u@0x%016llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__, pos,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, mw->mw_nents < nsegs ? "more" : "last");
r_xprt->rx_stats.read_chunk_count++;
nsegs -= mw->mw_nents;
} while (nsegs);
return 0;
}
static noinline int
rpcrdma_encode_write_list(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
struct rpc_rqst *rqst, enum rpcrdma_chunktype wtype)
{
struct xdr_stream *xdr = &req->rl_stream;
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
int nsegs, nchunks;
__be32 *segcount;
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(r_xprt, &rqst->rq_rcv_buf,
rqst->rq_rcv_buf.head[0].iov_len,
wtype, seg);
if (nsegs < 0)
return nsegs;
if (encode_item_present(xdr) < 0)
return -EMSGSIZE;
segcount = xdr_reserve_space(xdr, sizeof(*segcount));
if (unlikely(!segcount))
return -EMSGSIZE;
nchunks = 0;
do {
seg = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
true, &mw);
if (IS_ERR(seg))
return PTR_ERR(seg);
rpcrdma_push_mw(mw, &req->rl_registered);
if (encode_rdma_segment(xdr, mw) < 0)
return -EMSGSIZE;
dprintk("RPC: %5u %s: %u@0x016%llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, mw->mw_nents < nsegs ? "more" : "last");
r_xprt->rx_stats.write_chunk_count++;
r_xprt->rx_stats.total_rdma_request += seg->mr_len;
nchunks++;
nsegs -= mw->mw_nents;
} while (nsegs);
*segcount = cpu_to_be32(nchunks);
return 0;
}
static noinline int
rpcrdma_encode_reply_chunk(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
struct rpc_rqst *rqst, enum rpcrdma_chunktype wtype)
{
struct xdr_stream *xdr = &req->rl_stream;
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
int nsegs, nchunks;
__be32 *segcount;
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(r_xprt, &rqst->rq_rcv_buf, 0, wtype, seg);
if (nsegs < 0)
return nsegs;
if (encode_item_present(xdr) < 0)
return -EMSGSIZE;
segcount = xdr_reserve_space(xdr, sizeof(*segcount));
if (unlikely(!segcount))
return -EMSGSIZE;
nchunks = 0;
do {
seg = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
true, &mw);
if (IS_ERR(seg))
return PTR_ERR(seg);
rpcrdma_push_mw(mw, &req->rl_registered);
if (encode_rdma_segment(xdr, mw) < 0)
return -EMSGSIZE;
dprintk("RPC: %5u %s: %u@0x%016llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, mw->mw_nents < nsegs ? "more" : "last");
r_xprt->rx_stats.reply_chunk_count++;
r_xprt->rx_stats.total_rdma_request += seg->mr_len;
nchunks++;
nsegs -= mw->mw_nents;
} while (nsegs);
*segcount = cpu_to_be32(nchunks);
return 0;
}
static bool
rpcrdma_prepare_hdr_sge(struct rpcrdma_ia *ia, struct rpcrdma_req *req,
u32 len)
{
struct rpcrdma_regbuf *rb = req->rl_rdmabuf;
struct ib_sge *sge = &req->rl_send_sge[0];
if (unlikely(!rpcrdma_regbuf_is_mapped(rb))) {
if (!__rpcrdma_dma_map_regbuf(ia, rb))
return false;
sge->addr = rdmab_addr(rb);
sge->lkey = rdmab_lkey(rb);
}
sge->length = len;
ib_dma_sync_single_for_device(rdmab_device(rb), sge->addr,
sge->length, DMA_TO_DEVICE);
req->rl_send_wr.num_sge++;
return true;
}
static bool
rpcrdma_prepare_msg_sges(struct rpcrdma_ia *ia, struct rpcrdma_req *req,
struct xdr_buf *xdr, enum rpcrdma_chunktype rtype)
{
unsigned int sge_no, page_base, len, remaining;
struct rpcrdma_regbuf *rb = req->rl_sendbuf;
struct ib_device *device = ia->ri_device;
struct ib_sge *sge = req->rl_send_sge;
u32 lkey = ia->ri_pd->local_dma_lkey;
struct page *page, **ppages;
if (!rpcrdma_dma_map_regbuf(ia, rb))
return false;
sge_no = 1;
sge[sge_no].addr = rdmab_addr(rb);
sge[sge_no].length = xdr->head[0].iov_len;
sge[sge_no].lkey = rdmab_lkey(rb);
ib_dma_sync_single_for_device(rdmab_device(rb), sge[sge_no].addr,
sge[sge_no].length, DMA_TO_DEVICE);
if (rtype == rpcrdma_readch) {
len = xdr->tail[0].iov_len;
if (len < 4)
goto out;
page = virt_to_page(xdr->tail[0].iov_base);
page_base = offset_in_page(xdr->tail[0].iov_base);
page_base += len & 3;
len -= len & 3;
goto map_tail;
}
if (xdr->page_len) {
ppages = xdr->pages + (xdr->page_base >> PAGE_SHIFT);
page_base = offset_in_page(xdr->page_base);
remaining = xdr->page_len;
while (remaining) {
sge_no++;
if (sge_no > RPCRDMA_MAX_SEND_SGES - 2)
goto out_mapping_overflow;
len = min_t(u32, PAGE_SIZE - page_base, remaining);
sge[sge_no].addr = ib_dma_map_page(device, *ppages,
page_base, len,
DMA_TO_DEVICE);
if (ib_dma_mapping_error(device, sge[sge_no].addr))
goto out_mapping_err;
sge[sge_no].length = len;
sge[sge_no].lkey = lkey;
req->rl_mapped_sges++;
ppages++;
remaining -= len;
page_base = 0;
}
}
if (xdr->tail[0].iov_len) {
page = virt_to_page(xdr->tail[0].iov_base);
page_base = offset_in_page(xdr->tail[0].iov_base);
len = xdr->tail[0].iov_len;
map_tail:
sge_no++;
sge[sge_no].addr = ib_dma_map_page(device, page,
page_base, len,
DMA_TO_DEVICE);
if (ib_dma_mapping_error(device, sge[sge_no].addr))
goto out_mapping_err;
sge[sge_no].length = len;
sge[sge_no].lkey = lkey;
req->rl_mapped_sges++;
}
out:
req->rl_send_wr.num_sge = sge_no + 1;
return true;
out_mapping_overflow:
pr_err("rpcrdma: too many Send SGEs (%u)\n", sge_no);
return false;
out_mapping_err:
pr_err("rpcrdma: Send mapping error\n");
return false;
}
bool
rpcrdma_prepare_send_sges(struct rpcrdma_ia *ia, struct rpcrdma_req *req,
u32 hdrlen, struct xdr_buf *xdr,
enum rpcrdma_chunktype rtype)
{
req->rl_send_wr.num_sge = 0;
req->rl_mapped_sges = 0;
if (!rpcrdma_prepare_hdr_sge(ia, req, hdrlen))
goto out_map;
if (rtype != rpcrdma_areadch)
if (!rpcrdma_prepare_msg_sges(ia, req, xdr, rtype))
goto out_map;
return true;
out_map:
pr_err("rpcrdma: failed to DMA map a Send buffer\n");
return false;
}
void
rpcrdma_unmap_sges(struct rpcrdma_ia *ia, struct rpcrdma_req *req)
{
struct ib_device *device = ia->ri_device;
struct ib_sge *sge;
int count;
sge = &req->rl_send_sge[2];
for (count = req->rl_mapped_sges; count--; sge++)
ib_dma_unmap_page(device, sge->addr, sge->length,
DMA_TO_DEVICE);
req->rl_mapped_sges = 0;
}
int
rpcrdma_marshal_req(struct rpcrdma_xprt *r_xprt, struct rpc_rqst *rqst)
{
struct rpcrdma_req *req = rpcr_to_rdmar(rqst);
struct xdr_stream *xdr = &req->rl_stream;
enum rpcrdma_chunktype rtype, wtype;
bool ddp_allowed;
__be32 *p;
int ret;
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
if (test_bit(RPC_BC_PA_IN_USE, &rqst->rq_bc_pa_state))
return rpcrdma_bc_marshal_reply(rqst);
#endif
rpcrdma_set_xdrlen(&req->rl_hdrbuf, 0);
xdr_init_encode(xdr, &req->rl_hdrbuf,
req->rl_rdmabuf->rg_base);
ret = -EMSGSIZE;
p = xdr_reserve_space(xdr, 4 * sizeof(*p));
if (!p)
goto out_err;
*p++ = rqst->rq_xid;
*p++ = rpcrdma_version;
*p++ = cpu_to_be32(r_xprt->rx_buf.rb_max_requests);
ddp_allowed = !(rqst->rq_cred->cr_auth->au_flags &
RPCAUTH_AUTH_DATATOUCH);
if (rpcrdma_results_inline(r_xprt, rqst))
wtype = rpcrdma_noch;
else if (ddp_allowed && rqst->rq_rcv_buf.flags & XDRBUF_READ)
wtype = rpcrdma_writech;
else
wtype = rpcrdma_replych;
if (rpcrdma_args_inline(r_xprt, rqst)) {
*p++ = rdma_msg;
rtype = rpcrdma_noch;
} else if (ddp_allowed && rqst->rq_snd_buf.flags & XDRBUF_WRITE) {
*p++ = rdma_msg;
rtype = rpcrdma_readch;
} else {
r_xprt->rx_stats.nomsg_call_count++;
*p++ = rdma_nomsg;
rtype = rpcrdma_areadch;
}
if (rtype != rpcrdma_noch) {
ret = rpcrdma_encode_read_list(r_xprt, req, rqst, rtype);
if (ret)
goto out_err;
}
ret = encode_item_not_present(xdr);
if (ret)
goto out_err;
if (wtype == rpcrdma_writech) {
ret = rpcrdma_encode_write_list(r_xprt, req, rqst, wtype);
if (ret)
goto out_err;
}
ret = encode_item_not_present(xdr);
if (ret)
goto out_err;
if (wtype != rpcrdma_replych)
ret = encode_item_not_present(xdr);
else
ret = rpcrdma_encode_reply_chunk(r_xprt, req, rqst, wtype);
if (ret)
goto out_err;
dprintk("RPC: %5u %s: %s/%s: hdrlen %u rpclen\n",
rqst->rq_task->tk_pid, __func__,
transfertypes[rtype], transfertypes[wtype],
xdr_stream_pos(xdr));
if (!rpcrdma_prepare_send_sges(&r_xprt->rx_ia, req,
xdr_stream_pos(xdr),
&rqst->rq_snd_buf, rtype)) {
ret = -EIO;
goto out_err;
}
return 0;
out_err:
if (ret != -ENOBUFS) {
pr_err("rpcrdma: header marshaling failed (%d)\n", ret);
r_xprt->rx_stats.failed_marshal_count++;
}
return ret;
}
static unsigned long
rpcrdma_inline_fixup(struct rpc_rqst *rqst, char *srcp, int copy_len, int pad)
{
unsigned long fixup_copy_count;
int i, npages, curlen;
char *destp;
struct page **ppages;
int page_base;
rqst->rq_rcv_buf.head[0].iov_base = srcp;
rqst->rq_private_buf.head[0].iov_base = srcp;
curlen = rqst->rq_rcv_buf.head[0].iov_len;
if (curlen > copy_len)
curlen = copy_len;
dprintk("RPC: %s: srcp 0x%p len %d hdrlen %d\n",
__func__, srcp, copy_len, curlen);
srcp += curlen;
copy_len -= curlen;
ppages = rqst->rq_rcv_buf.pages +
(rqst->rq_rcv_buf.page_base >> PAGE_SHIFT);
page_base = offset_in_page(rqst->rq_rcv_buf.page_base);
fixup_copy_count = 0;
if (copy_len && rqst->rq_rcv_buf.page_len) {
int pagelist_len;
pagelist_len = rqst->rq_rcv_buf.page_len;
if (pagelist_len > copy_len)
pagelist_len = copy_len;
npages = PAGE_ALIGN(page_base + pagelist_len) >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
curlen = PAGE_SIZE - page_base;
if (curlen > pagelist_len)
curlen = pagelist_len;
dprintk("RPC: %s: page %d"
" srcp 0x%p len %d curlen %d\n",
__func__, i, srcp, copy_len, curlen);
destp = kmap_atomic(ppages[i]);
memcpy(destp + page_base, srcp, curlen);
flush_dcache_page(ppages[i]);
kunmap_atomic(destp);
srcp += curlen;
copy_len -= curlen;
fixup_copy_count += curlen;
pagelist_len -= curlen;
if (!pagelist_len)
break;
page_base = 0;
}
if (pad)
srcp -= pad;
}
if (copy_len || pad) {
rqst->rq_rcv_buf.tail[0].iov_base = srcp;
rqst->rq_private_buf.tail[0].iov_base = srcp;
}
return fixup_copy_count;
}
static void
rpcrdma_mark_remote_invalidation(struct list_head *mws,
struct rpcrdma_rep *rep)
{
struct rpcrdma_mw *mw;
if (!(rep->rr_wc_flags & IB_WC_WITH_INVALIDATE))
return;
list_for_each_entry(mw, mws, mw_list)
if (mw->mw_handle == rep->rr_inv_rkey) {
mw->mw_flags = RPCRDMA_MW_F_RI;
break;
}
}
static bool
rpcrdma_is_bcall(struct rpcrdma_xprt *r_xprt, struct rpcrdma_rep *rep,
__be32 xid, __be32 proc)
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
{
struct xdr_stream *xdr = &rep->rr_stream;
__be32 *p;
if (proc != rdma_msg)
return false;
p = xdr_inline_decode(xdr, 0);
if (*p++ != xdr_zero)
return false;
if (*p++ != xdr_zero)
return false;
if (*p++ != xdr_zero)
return false;
if (*p++ != xid)
return false;
if (*p != cpu_to_be32(RPC_CALL))
return false;
p = xdr_inline_decode(xdr, 3 * sizeof(*p));
if (unlikely(!p))
goto out_short;
rpcrdma_bc_receive_call(r_xprt, rep);
return true;
out_short:
pr_warn("RPC/RDMA short backward direction call\n");
if (rpcrdma_ep_post_recv(&r_xprt->rx_ia, rep))
xprt_disconnect_done(&r_xprt->rx_xprt);
return true;
}
static int decode_rdma_segment(struct xdr_stream *xdr, u32 *length)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4 * sizeof(*p));
if (unlikely(!p))
return -EIO;
ifdebug(FACILITY) {
u64 offset;
u32 handle;
handle = be32_to_cpup(p++);
*length = be32_to_cpup(p++);
xdr_decode_hyper(p, &offset);
dprintk("RPC: %s: segment %u@0x%016llx:0x%08x\n",
__func__, *length, (unsigned long long)offset,
handle);
} else {
*length = be32_to_cpup(p + 1);
}
return 0;
}
static int decode_write_chunk(struct xdr_stream *xdr, u32 *length)
{
u32 segcount, seglength;
__be32 *p;
p = xdr_inline_decode(xdr, sizeof(*p));
if (unlikely(!p))
return -EIO;
*length = 0;
segcount = be32_to_cpup(p);
while (segcount--) {
if (decode_rdma_segment(xdr, &seglength))
return -EIO;
*length += seglength;
}
dprintk("RPC: %s: segcount=%u, %u bytes\n",
__func__, be32_to_cpup(p), *length);
return 0;
}
static int decode_read_list(struct xdr_stream *xdr)
{
__be32 *p;
p = xdr_inline_decode(xdr, sizeof(*p));
if (unlikely(!p))
return -EIO;
if (unlikely(*p != xdr_zero))
return -EIO;
return 0;
}
static int decode_write_list(struct xdr_stream *xdr, u32 *length)
{
u32 chunklen;
bool first;
__be32 *p;
*length = 0;
first = true;
do {
p = xdr_inline_decode(xdr, sizeof(*p));
if (unlikely(!p))
return -EIO;
if (*p == xdr_zero)
break;
if (!first)
return -EIO;
if (decode_write_chunk(xdr, &chunklen))
return -EIO;
*length += chunklen;
first = false;
} while (true);
return 0;
}
static int decode_reply_chunk(struct xdr_stream *xdr, u32 *length)
{
__be32 *p;
p = xdr_inline_decode(xdr, sizeof(*p));
if (unlikely(!p))
return -EIO;
*length = 0;
if (*p != xdr_zero)
if (decode_write_chunk(xdr, length))
return -EIO;
return 0;
}
static int
rpcrdma_decode_msg(struct rpcrdma_xprt *r_xprt, struct rpcrdma_rep *rep,
struct rpc_rqst *rqst)
{
struct xdr_stream *xdr = &rep->rr_stream;
u32 writelist, replychunk, rpclen;
char *base;
if (decode_read_list(xdr))
return -EIO;
if (decode_write_list(xdr, &writelist))
return -EIO;
if (decode_reply_chunk(xdr, &replychunk))
return -EIO;
if (unlikely(replychunk))
return -EIO;
base = (char *)xdr_inline_decode(xdr, 0);
rpclen = xdr_stream_remaining(xdr);
r_xprt->rx_stats.fixup_copy_count +=
rpcrdma_inline_fixup(rqst, base, rpclen, writelist & 3);
r_xprt->rx_stats.total_rdma_reply += writelist;
return rpclen + xdr_align_size(writelist);
}
static noinline int
rpcrdma_decode_nomsg(struct rpcrdma_xprt *r_xprt, struct rpcrdma_rep *rep)
{
struct xdr_stream *xdr = &rep->rr_stream;
u32 writelist, replychunk;
if (decode_read_list(xdr))
return -EIO;
if (decode_write_list(xdr, &writelist))
return -EIO;
if (decode_reply_chunk(xdr, &replychunk))
return -EIO;
if (unlikely(writelist))
return -EIO;
if (unlikely(!replychunk))
return -EIO;
r_xprt->rx_stats.total_rdma_reply += replychunk;
return replychunk;
}
static noinline int
rpcrdma_decode_error(struct rpcrdma_xprt *r_xprt, struct rpcrdma_rep *rep,
struct rpc_rqst *rqst)
{
struct xdr_stream *xdr = &rep->rr_stream;
__be32 *p;
p = xdr_inline_decode(xdr, sizeof(*p));
if (unlikely(!p))
return -EIO;
switch (*p) {
case err_vers:
p = xdr_inline_decode(xdr, 2 * sizeof(*p));
if (!p)
break;
dprintk("RPC: %5u: %s: server reports version error (%u-%u)\n",
rqst->rq_task->tk_pid, __func__,
be32_to_cpup(p), be32_to_cpu(*(p + 1)));
break;
case err_chunk:
dprintk("RPC: %5u: %s: server reports header decoding error\n",
rqst->rq_task->tk_pid, __func__);
break;
default:
dprintk("RPC: %5u: %s: server reports unrecognized error %d\n",
rqst->rq_task->tk_pid, __func__, be32_to_cpup(p));
}
r_xprt->rx_stats.bad_reply_count++;
return -EREMOTEIO;
}
void
rpcrdma_reply_handler(struct work_struct *work)
{
struct rpcrdma_rep *rep =
container_of(work, struct rpcrdma_rep, rr_work);
struct rpcrdma_xprt *r_xprt = rep->rr_rxprt;
struct rpc_xprt *xprt = &r_xprt->rx_xprt;
struct xdr_stream *xdr = &rep->rr_stream;
struct rpcrdma_req *req;
struct rpc_rqst *rqst;
__be32 *p, xid, vers, proc;
unsigned long cwnd;
int status;
dprintk("RPC: %s: incoming rep %p\n", __func__, rep);
if (rep->rr_hdrbuf.head[0].iov_len == 0)
goto out_badstatus;
xdr_init_decode(xdr, &rep->rr_hdrbuf,
rep->rr_hdrbuf.head[0].iov_base);
p = xdr_inline_decode(xdr, 4 * sizeof(*p));
if (unlikely(!p))
goto out_shortreply;
xid = *p++;
vers = *p++;
p++;
proc = *p++;
if (rpcrdma_is_bcall(r_xprt, rep, xid, proc))
return;
spin_lock(&xprt->recv_lock);
rqst = xprt_lookup_rqst(xprt, xid);
if (!rqst)
goto out_norqst;
xprt_pin_rqst(rqst);
spin_unlock(&xprt->recv_lock);
req = rpcr_to_rdmar(rqst);
req->rl_reply = rep;
dprintk("RPC: %s: reply %p completes request %p (xid 0x%08x)\n",
__func__, rep, req, be32_to_cpu(xid));
if (!list_empty(&req->rl_registered)) {
rpcrdma_mark_remote_invalidation(&req->rl_registered, rep);
r_xprt->rx_ia.ri_ops->ro_unmap_sync(r_xprt,
&req->rl_registered);
}
xprt->reestablish_timeout = 0;
if (vers != rpcrdma_version)
goto out_badversion;
switch (proc) {
case rdma_msg:
status = rpcrdma_decode_msg(r_xprt, rep, rqst);
break;
case rdma_nomsg:
status = rpcrdma_decode_nomsg(r_xprt, rep);
break;
case rdma_error:
status = rpcrdma_decode_error(r_xprt, rep, rqst);
break;
default:
status = -EIO;
}
if (status < 0)
goto out_badheader;
out:
spin_lock(&xprt->recv_lock);
cwnd = xprt->cwnd;
xprt->cwnd = atomic_read(&r_xprt->rx_buf.rb_credits) << RPC_CWNDSHIFT;
if (xprt->cwnd > cwnd)
xprt_release_rqst_cong(rqst->rq_task);
xprt_complete_rqst(rqst->rq_task, status);
xprt_unpin_rqst(rqst);
spin_unlock(&xprt->recv_lock);
dprintk("RPC: %s: xprt_complete_rqst(0x%p, 0x%p, %d)\n",
__func__, xprt, rqst, status);
return;
out_badstatus:
rpcrdma_recv_buffer_put(rep);
if (r_xprt->rx_ep.rep_connected == 1) {
r_xprt->rx_ep.rep_connected = -EIO;
rpcrdma_conn_func(&r_xprt->rx_ep);
}
return;
out_badversion:
dprintk("RPC: %s: invalid version %d\n",
__func__, be32_to_cpu(vers));
status = -EIO;
r_xprt->rx_stats.bad_reply_count++;
goto out;
out_badheader:
dprintk("RPC: %5u %s: invalid rpcrdma reply (type %u)\n",
rqst->rq_task->tk_pid, __func__, be32_to_cpu(proc));
r_xprt->rx_stats.bad_reply_count++;
status = -EIO;
goto out;
out_norqst:
spin_unlock(&xprt->recv_lock);
dprintk("RPC: %s: no match for incoming xid 0x%08x\n",
__func__, be32_to_cpu(xid));
goto repost;
out_shortreply:
dprintk("RPC: %s: short/invalid reply\n", __func__);
goto repost;
repost:
r_xprt->rx_stats.bad_reply_count++;
if (rpcrdma_ep_post_recv(&r_xprt->rx_ia, rep))
rpcrdma_recv_buffer_put(rep);
}
