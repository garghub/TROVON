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
void rpcrdma_set_max_header_sizes(struct rpcrdma_ia *ia,
struct rpcrdma_create_data_internal *cdata,
unsigned int maxsegs)
{
ia->ri_max_inline_write = cdata->inline_wsize -
rpcrdma_max_call_header_size(maxsegs);
ia->ri_max_inline_read = cdata->inline_rsize -
rpcrdma_max_reply_header_size(maxsegs);
}
static bool rpcrdma_args_inline(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
return rqst->rq_snd_buf.len <= ia->ri_max_inline_write;
}
static bool rpcrdma_results_inline(struct rpcrdma_xprt *r_xprt,
struct rpc_rqst *rqst)
{
struct rpcrdma_ia *ia = &r_xprt->rx_ia;
return rqst->rq_rcv_buf.buflen <= ia->ri_max_inline_read;
}
static int
rpcrdma_tail_pullup(struct xdr_buf *buf)
{
size_t tlen = buf->tail[0].iov_len;
size_t skip = tlen & 3;
if (tlen < 4)
return 0;
if (skip) {
unsigned char *src, *dst;
unsigned int count;
src = buf->tail[0].iov_base;
dst = buf->head[0].iov_base;
dst += buf->head[0].iov_len;
src += skip;
tlen -= skip;
dprintk("RPC: %s: skip=%zu, memmove(%p, %p, %zu)\n",
__func__, skip, dst, src, tlen);
for (count = tlen; count; count--)
*dst++ = *src++;
}
return tlen;
}
static int
rpcrdma_convert_kvec(struct kvec *vec, struct rpcrdma_mr_seg *seg, int n)
{
size_t page_offset;
u32 remaining;
char *base;
base = vec->iov_base;
page_offset = offset_in_page(base);
remaining = vec->iov_len;
while (remaining && n < RPCRDMA_MAX_SEGS) {
seg[n].mr_page = NULL;
seg[n].mr_offset = base;
seg[n].mr_len = min_t(u32, PAGE_SIZE - page_offset, remaining);
remaining -= seg[n].mr_len;
base += seg[n].mr_len;
++n;
page_offset = 0;
}
return n;
}
static int
rpcrdma_convert_iovs(struct xdr_buf *xdrbuf, unsigned int pos,
enum rpcrdma_chunktype type, struct rpcrdma_mr_seg *seg)
{
int len, n, p, page_base;
struct page **ppages;
n = 0;
if (pos == 0) {
n = rpcrdma_convert_kvec(&xdrbuf->head[0], seg, n);
if (n == RPCRDMA_MAX_SEGS)
goto out_overflow;
}
len = xdrbuf->page_len;
ppages = xdrbuf->pages + (xdrbuf->page_base >> PAGE_SHIFT);
page_base = xdrbuf->page_base & ~PAGE_MASK;
p = 0;
while (len && n < RPCRDMA_MAX_SEGS) {
if (!ppages[p]) {
ppages[p] = alloc_page(GFP_ATOMIC);
if (!ppages[p])
return -EAGAIN;
}
seg[n].mr_page = ppages[p];
seg[n].mr_offset = (void *)(unsigned long) page_base;
seg[n].mr_len = min_t(u32, PAGE_SIZE - page_base, len);
if (seg[n].mr_len > PAGE_SIZE)
goto out_overflow;
len -= seg[n].mr_len;
++n;
++p;
page_base = 0;
}
if (len && n == RPCRDMA_MAX_SEGS)
goto out_overflow;
if (type == rpcrdma_readch)
return n;
if (xdrbuf->tail[0].iov_len) {
if (xdrbuf->tail[0].iov_len < 4 && xprt_rdma_pad_optimize)
return n;
n = rpcrdma_convert_kvec(&xdrbuf->tail[0], seg, n);
if (n == RPCRDMA_MAX_SEGS)
goto out_overflow;
}
return n;
out_overflow:
pr_err("rpcrdma: segment array overflow\n");
return -EIO;
}
static inline __be32 *
xdr_encode_rdma_segment(__be32 *iptr, struct rpcrdma_mw *mw)
{
*iptr++ = cpu_to_be32(mw->mw_handle);
*iptr++ = cpu_to_be32(mw->mw_length);
return xdr_encode_hyper(iptr, mw->mw_offset);
}
static __be32 *
rpcrdma_encode_read_list(struct rpcrdma_xprt *r_xprt,
struct rpcrdma_req *req, struct rpc_rqst *rqst,
__be32 *iptr, enum rpcrdma_chunktype rtype)
{
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
unsigned int pos;
int n, nsegs;
if (rtype == rpcrdma_noch) {
*iptr++ = xdr_zero;
return iptr;
}
pos = rqst->rq_snd_buf.head[0].iov_len;
if (rtype == rpcrdma_areadch)
pos = 0;
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(&rqst->rq_snd_buf, pos, rtype, seg);
if (nsegs < 0)
return ERR_PTR(nsegs);
do {
n = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
false, &mw);
if (n < 0)
return ERR_PTR(n);
list_add(&mw->mw_list, &req->rl_registered);
*iptr++ = xdr_one;
*iptr++ = cpu_to_be32(pos);
iptr = xdr_encode_rdma_segment(iptr, mw);
dprintk("RPC: %5u %s: pos %u %u@0x%016llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__, pos,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, n < nsegs ? "more" : "last");
r_xprt->rx_stats.read_chunk_count++;
seg += n;
nsegs -= n;
} while (nsegs);
*iptr++ = xdr_zero;
return iptr;
}
static __be32 *
rpcrdma_encode_write_list(struct rpcrdma_xprt *r_xprt, struct rpcrdma_req *req,
struct rpc_rqst *rqst, __be32 *iptr,
enum rpcrdma_chunktype wtype)
{
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
int n, nsegs, nchunks;
__be32 *segcount;
if (wtype != rpcrdma_writech) {
*iptr++ = xdr_zero;
return iptr;
}
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(&rqst->rq_rcv_buf,
rqst->rq_rcv_buf.head[0].iov_len,
wtype, seg);
if (nsegs < 0)
return ERR_PTR(nsegs);
*iptr++ = xdr_one;
segcount = iptr++;
nchunks = 0;
do {
n = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
true, &mw);
if (n < 0)
return ERR_PTR(n);
list_add(&mw->mw_list, &req->rl_registered);
iptr = xdr_encode_rdma_segment(iptr, mw);
dprintk("RPC: %5u %s: %u@0x016%llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, n < nsegs ? "more" : "last");
r_xprt->rx_stats.write_chunk_count++;
r_xprt->rx_stats.total_rdma_request += seg->mr_len;
nchunks++;
seg += n;
nsegs -= n;
} while (nsegs);
*segcount = cpu_to_be32(nchunks);
*iptr++ = xdr_zero;
return iptr;
}
static __be32 *
rpcrdma_encode_reply_chunk(struct rpcrdma_xprt *r_xprt,
struct rpcrdma_req *req, struct rpc_rqst *rqst,
__be32 *iptr, enum rpcrdma_chunktype wtype)
{
struct rpcrdma_mr_seg *seg;
struct rpcrdma_mw *mw;
int n, nsegs, nchunks;
__be32 *segcount;
if (wtype != rpcrdma_replych) {
*iptr++ = xdr_zero;
return iptr;
}
seg = req->rl_segments;
nsegs = rpcrdma_convert_iovs(&rqst->rq_rcv_buf, 0, wtype, seg);
if (nsegs < 0)
return ERR_PTR(nsegs);
*iptr++ = xdr_one;
segcount = iptr++;
nchunks = 0;
do {
n = r_xprt->rx_ia.ri_ops->ro_map(r_xprt, seg, nsegs,
true, &mw);
if (n < 0)
return ERR_PTR(n);
list_add(&mw->mw_list, &req->rl_registered);
iptr = xdr_encode_rdma_segment(iptr, mw);
dprintk("RPC: %5u %s: %u@0x%016llx:0x%08x (%s)\n",
rqst->rq_task->tk_pid, __func__,
mw->mw_length, (unsigned long long)mw->mw_offset,
mw->mw_handle, n < nsegs ? "more" : "last");
r_xprt->rx_stats.reply_chunk_count++;
r_xprt->rx_stats.total_rdma_request += seg->mr_len;
nchunks++;
seg += n;
nsegs -= n;
} while (nsegs);
*segcount = cpu_to_be32(nchunks);
return iptr;
}
static void rpcrdma_inline_pullup(struct rpc_rqst *rqst)
{
int i, npages, curlen;
int copy_len;
unsigned char *srcp, *destp;
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(rqst->rq_xprt);
int page_base;
struct page **ppages;
destp = rqst->rq_svec[0].iov_base;
curlen = rqst->rq_svec[0].iov_len;
destp += curlen;
dprintk("RPC: %s: destp 0x%p len %d hdrlen %d\n",
__func__, destp, rqst->rq_slen, curlen);
copy_len = rqst->rq_snd_buf.page_len;
if (rqst->rq_snd_buf.tail[0].iov_len) {
curlen = rqst->rq_snd_buf.tail[0].iov_len;
if (destp + copy_len != rqst->rq_snd_buf.tail[0].iov_base) {
memmove(destp + copy_len,
rqst->rq_snd_buf.tail[0].iov_base, curlen);
r_xprt->rx_stats.pullup_copy_count += curlen;
}
dprintk("RPC: %s: tail destp 0x%p len %d\n",
__func__, destp + copy_len, curlen);
rqst->rq_svec[0].iov_len += curlen;
}
r_xprt->rx_stats.pullup_copy_count += copy_len;
page_base = rqst->rq_snd_buf.page_base;
ppages = rqst->rq_snd_buf.pages + (page_base >> PAGE_SHIFT);
page_base &= ~PAGE_MASK;
npages = PAGE_ALIGN(page_base+copy_len) >> PAGE_SHIFT;
for (i = 0; copy_len && i < npages; i++) {
curlen = PAGE_SIZE - page_base;
if (curlen > copy_len)
curlen = copy_len;
dprintk("RPC: %s: page %d destp 0x%p len %d curlen %d\n",
__func__, i, destp, copy_len, curlen);
srcp = kmap_atomic(ppages[i]);
memcpy(destp, srcp+page_base, curlen);
kunmap_atomic(srcp);
rqst->rq_svec[0].iov_len += curlen;
destp += curlen;
copy_len -= curlen;
page_base = 0;
}
}
int
rpcrdma_marshal_req(struct rpc_rqst *rqst)
{
struct rpc_xprt *xprt = rqst->rq_xprt;
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(xprt);
struct rpcrdma_req *req = rpcr_to_rdmar(rqst);
enum rpcrdma_chunktype rtype, wtype;
struct rpcrdma_msg *headerp;
bool ddp_allowed;
ssize_t hdrlen;
size_t rpclen;
__be32 *iptr;
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
if (test_bit(RPC_BC_PA_IN_USE, &rqst->rq_bc_pa_state))
return rpcrdma_bc_marshal_reply(rqst);
#endif
headerp = rdmab_to_msg(req->rl_rdmabuf);
headerp->rm_xid = rqst->rq_xid;
headerp->rm_vers = rpcrdma_version;
headerp->rm_credit = cpu_to_be32(r_xprt->rx_buf.rb_max_requests);
headerp->rm_type = rdma_msg;
ddp_allowed = !(rqst->rq_cred->cr_auth->au_flags &
RPCAUTH_AUTH_DATATOUCH);
if (rpcrdma_results_inline(r_xprt, rqst))
wtype = rpcrdma_noch;
else if (ddp_allowed && rqst->rq_rcv_buf.flags & XDRBUF_READ)
wtype = rpcrdma_writech;
else
wtype = rpcrdma_replych;
if (rpcrdma_args_inline(r_xprt, rqst)) {
rtype = rpcrdma_noch;
rpcrdma_inline_pullup(rqst);
rpclen = rqst->rq_svec[0].iov_len;
} else if (ddp_allowed && rqst->rq_snd_buf.flags & XDRBUF_WRITE) {
rtype = rpcrdma_readch;
rpclen = rqst->rq_svec[0].iov_len;
rpclen += rpcrdma_tail_pullup(&rqst->rq_snd_buf);
} else {
r_xprt->rx_stats.nomsg_call_count++;
headerp->rm_type = htonl(RDMA_NOMSG);
rtype = rpcrdma_areadch;
rpclen = 0;
}
iptr = headerp->rm_body.rm_chunks;
iptr = rpcrdma_encode_read_list(r_xprt, req, rqst, iptr, rtype);
if (IS_ERR(iptr))
goto out_unmap;
iptr = rpcrdma_encode_write_list(r_xprt, req, rqst, iptr, wtype);
if (IS_ERR(iptr))
goto out_unmap;
iptr = rpcrdma_encode_reply_chunk(r_xprt, req, rqst, iptr, wtype);
if (IS_ERR(iptr))
goto out_unmap;
hdrlen = (unsigned char *)iptr - (unsigned char *)headerp;
if (hdrlen + rpclen > RPCRDMA_INLINE_WRITE_THRESHOLD(rqst))
goto out_overflow;
dprintk("RPC: %5u %s: %s/%s: hdrlen %zd rpclen %zd\n",
rqst->rq_task->tk_pid, __func__,
transfertypes[rtype], transfertypes[wtype],
hdrlen, rpclen);
req->rl_send_iov[0].addr = rdmab_addr(req->rl_rdmabuf);
req->rl_send_iov[0].length = hdrlen;
req->rl_send_iov[0].lkey = rdmab_lkey(req->rl_rdmabuf);
req->rl_niovs = 1;
if (rtype == rpcrdma_areadch)
return 0;
req->rl_send_iov[1].addr = rdmab_addr(req->rl_sendbuf);
req->rl_send_iov[1].length = rpclen;
req->rl_send_iov[1].lkey = rdmab_lkey(req->rl_sendbuf);
req->rl_niovs = 2;
return 0;
out_overflow:
pr_err("rpcrdma: send overflow: hdrlen %zd rpclen %zu %s/%s\n",
hdrlen, rpclen, transfertypes[rtype], transfertypes[wtype]);
iptr = ERR_PTR(-EIO);
out_unmap:
r_xprt->rx_ia.ri_ops->ro_unmap_safe(r_xprt, req, false);
return PTR_ERR(iptr);
}
static int
rpcrdma_count_chunks(struct rpcrdma_rep *rep, int wrchunk, __be32 **iptrp)
{
unsigned int i, total_len;
struct rpcrdma_write_chunk *cur_wchunk;
char *base = (char *)rdmab_to_msg(rep->rr_rdmabuf);
i = be32_to_cpu(**iptrp);
cur_wchunk = (struct rpcrdma_write_chunk *) (*iptrp + 1);
total_len = 0;
while (i--) {
struct rpcrdma_segment *seg = &cur_wchunk->wc_target;
ifdebug(FACILITY) {
u64 off;
xdr_decode_hyper((__be32 *)&seg->rs_offset, &off);
dprintk("RPC: %s: chunk %d@0x%llx:0x%x\n",
__func__,
be32_to_cpu(seg->rs_length),
(unsigned long long)off,
be32_to_cpu(seg->rs_handle));
}
total_len += be32_to_cpu(seg->rs_length);
++cur_wchunk;
}
if (wrchunk) {
__be32 *w = (__be32 *) cur_wchunk;
if (*w++ != xdr_zero)
return -1;
cur_wchunk = (struct rpcrdma_write_chunk *) w;
}
if ((char *)cur_wchunk > base + rep->rr_len)
return -1;
*iptrp = (__be32 *) cur_wchunk;
return total_len;
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
page_base = rqst->rq_rcv_buf.page_base;
ppages = rqst->rq_rcv_buf.pages + (page_base >> PAGE_SHIFT);
page_base &= ~PAGE_MASK;
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
void
rpcrdma_connect_worker(struct work_struct *work)
{
struct rpcrdma_ep *ep =
container_of(work, struct rpcrdma_ep, rep_connect_worker.work);
struct rpcrdma_xprt *r_xprt =
container_of(ep, struct rpcrdma_xprt, rx_ep);
struct rpc_xprt *xprt = &r_xprt->rx_xprt;
spin_lock_bh(&xprt->transport_lock);
if (++xprt->connect_cookie == 0)
++xprt->connect_cookie;
if (ep->rep_connected > 0) {
if (!xprt_test_and_set_connected(xprt))
xprt_wake_pending_tasks(xprt, 0);
} else {
if (xprt_test_and_clear_connected(xprt))
xprt_wake_pending_tasks(xprt, -ENOTCONN);
}
spin_unlock_bh(&xprt->transport_lock);
}
static bool
rpcrdma_is_bcall(struct rpcrdma_msg *headerp)
{
__be32 *p = (__be32 *)headerp;
if (headerp->rm_type != rdma_msg)
return false;
if (headerp->rm_body.rm_chunks[0] != xdr_zero)
return false;
if (headerp->rm_body.rm_chunks[1] != xdr_zero)
return false;
if (headerp->rm_body.rm_chunks[2] != xdr_zero)
return false;
if (p[7] != headerp->rm_xid)
return false;
if (p[8] != cpu_to_be32(RPC_CALL))
return false;
return true;
}
void
rpcrdma_conn_func(struct rpcrdma_ep *ep)
{
schedule_delayed_work(&ep->rep_connect_worker, 0);
}
void
rpcrdma_reply_handler(struct rpcrdma_rep *rep)
{
struct rpcrdma_msg *headerp;
struct rpcrdma_req *req;
struct rpc_rqst *rqst;
struct rpcrdma_xprt *r_xprt = rep->rr_rxprt;
struct rpc_xprt *xprt = &r_xprt->rx_xprt;
__be32 *iptr;
int rdmalen, status, rmerr;
unsigned long cwnd;
dprintk("RPC: %s: incoming rep %p\n", __func__, rep);
if (rep->rr_len == RPCRDMA_BAD_LEN)
goto out_badstatus;
if (rep->rr_len < RPCRDMA_HDRLEN_ERR)
goto out_shortreply;
headerp = rdmab_to_msg(rep->rr_rdmabuf);
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
if (rpcrdma_is_bcall(headerp))
goto out_bcall;
#endif
spin_lock_bh(&xprt->transport_lock);
rqst = xprt_lookup_rqst(xprt, headerp->rm_xid);
if (!rqst)
goto out_nomatch;
req = rpcr_to_rdmar(rqst);
if (req->rl_reply)
goto out_duplicate;
list_del_init(&rqst->rq_list);
spin_unlock_bh(&xprt->transport_lock);
dprintk("RPC: %s: reply %p completes request %p (xid 0x%08x)\n",
__func__, rep, req, be32_to_cpu(headerp->rm_xid));
req->rl_reply = rep;
xprt->reestablish_timeout = 0;
if (headerp->rm_vers != rpcrdma_version)
goto out_badversion;
switch (headerp->rm_type) {
case rdma_msg:
if (headerp->rm_body.rm_chunks[0] != xdr_zero ||
(headerp->rm_body.rm_chunks[1] == xdr_zero &&
headerp->rm_body.rm_chunks[2] != xdr_zero) ||
(headerp->rm_body.rm_chunks[1] != xdr_zero &&
list_empty(&req->rl_registered)))
goto badheader;
if (headerp->rm_body.rm_chunks[1] != xdr_zero) {
iptr = &headerp->rm_body.rm_chunks[2];
rdmalen = rpcrdma_count_chunks(rep, 1, &iptr);
if (rdmalen < 0 || *iptr++ != xdr_zero)
goto badheader;
rep->rr_len -=
((unsigned char *)iptr - (unsigned char *)headerp);
status = rep->rr_len + rdmalen;
r_xprt->rx_stats.total_rdma_reply += rdmalen;
if (rdmalen &= 3) {
rdmalen = 4 - rdmalen;
status += rdmalen;
}
} else {
rdmalen = 0;
iptr = (__be32 *)((unsigned char *)headerp +
RPCRDMA_HDRLEN_MIN);
rep->rr_len -= RPCRDMA_HDRLEN_MIN;
status = rep->rr_len;
}
r_xprt->rx_stats.fixup_copy_count +=
rpcrdma_inline_fixup(rqst, (char *)iptr, rep->rr_len,
rdmalen);
break;
case rdma_nomsg:
if (headerp->rm_body.rm_chunks[0] != xdr_zero ||
headerp->rm_body.rm_chunks[1] != xdr_zero ||
headerp->rm_body.rm_chunks[2] != xdr_one ||
list_empty(&req->rl_registered))
goto badheader;
iptr = (__be32 *)((unsigned char *)headerp +
RPCRDMA_HDRLEN_MIN);
rdmalen = rpcrdma_count_chunks(rep, 0, &iptr);
if (rdmalen < 0)
goto badheader;
r_xprt->rx_stats.total_rdma_reply += rdmalen;
status = rdmalen;
break;
case rdma_error:
goto out_rdmaerr;
badheader:
default:
dprintk("RPC: %5u %s: invalid rpcrdma reply (type %u)\n",
rqst->rq_task->tk_pid, __func__,
be32_to_cpu(headerp->rm_type));
status = -EIO;
r_xprt->rx_stats.bad_reply_count++;
break;
}
out:
if (!list_empty(&req->rl_registered))
r_xprt->rx_ia.ri_ops->ro_unmap_sync(r_xprt, req);
spin_lock_bh(&xprt->transport_lock);
cwnd = xprt->cwnd;
xprt->cwnd = atomic_read(&r_xprt->rx_buf.rb_credits) << RPC_CWNDSHIFT;
if (xprt->cwnd > cwnd)
xprt_release_rqst_cong(rqst->rq_task);
xprt_complete_rqst(rqst->rq_task, status);
spin_unlock_bh(&xprt->transport_lock);
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
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
out_bcall:
rpcrdma_bc_receive_call(r_xprt, rep);
return;
#endif
out_badversion:
dprintk("RPC: %s: invalid version %d\n",
__func__, be32_to_cpu(headerp->rm_vers));
status = -EIO;
r_xprt->rx_stats.bad_reply_count++;
goto out;
out_rdmaerr:
rmerr = be32_to_cpu(headerp->rm_body.rm_error.rm_err);
switch (rmerr) {
case ERR_VERS:
pr_err("%s: server reports header version error (%u-%u)\n",
__func__,
be32_to_cpu(headerp->rm_body.rm_error.rm_vers_low),
be32_to_cpu(headerp->rm_body.rm_error.rm_vers_high));
break;
case ERR_CHUNK:
pr_err("%s: server reports header decoding error\n",
__func__);
break;
default:
pr_err("%s: server reports unknown error %d\n",
__func__, rmerr);
}
status = -EREMOTEIO;
r_xprt->rx_stats.bad_reply_count++;
goto out;
out_shortreply:
dprintk("RPC: %s: short/invalid reply\n", __func__);
goto repost;
out_nomatch:
spin_unlock_bh(&xprt->transport_lock);
dprintk("RPC: %s: no match for incoming xid 0x%08x len %d\n",
__func__, be32_to_cpu(headerp->rm_xid),
rep->rr_len);
goto repost;
out_duplicate:
spin_unlock_bh(&xprt->transport_lock);
dprintk("RPC: %s: "
"duplicate reply %p to RPC request %p: xid 0x%08x\n",
__func__, rep, req, be32_to_cpu(headerp->rm_xid));
repost:
r_xprt->rx_stats.bad_reply_count++;
if (rpcrdma_ep_post_recv(&r_xprt->rx_ia, &r_xprt->rx_ep, rep))
rpcrdma_recv_buffer_put(rep);
}
