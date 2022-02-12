static bool rpcrdma_args_inline(struct rpc_rqst *rqst)
{
unsigned int callsize = RPCRDMA_HDRLEN_MIN + rqst->rq_snd_buf.len;
return callsize <= RPCRDMA_INLINE_WRITE_THRESHOLD(rqst);
}
static bool rpcrdma_results_inline(struct rpc_rqst *rqst)
{
unsigned int repsize = RPCRDMA_HDRLEN_MIN + rqst->rq_rcv_buf.buflen;
return repsize <= RPCRDMA_INLINE_READ_THRESHOLD(rqst);
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
rpcrdma_convert_iovs(struct xdr_buf *xdrbuf, unsigned int pos,
enum rpcrdma_chunktype type, struct rpcrdma_mr_seg *seg, int nsegs)
{
int len, n = 0, p;
int page_base;
struct page **ppages;
if (pos == 0 && xdrbuf->head[0].iov_len) {
seg[n].mr_page = NULL;
seg[n].mr_offset = xdrbuf->head[0].iov_base;
seg[n].mr_len = xdrbuf->head[0].iov_len;
++n;
}
len = xdrbuf->page_len;
ppages = xdrbuf->pages + (xdrbuf->page_base >> PAGE_SHIFT);
page_base = xdrbuf->page_base & ~PAGE_MASK;
p = 0;
while (len && n < nsegs) {
if (!ppages[p]) {
ppages[p] = alloc_page(GFP_ATOMIC);
if (!ppages[p])
return -ENOMEM;
}
seg[n].mr_page = ppages[p];
seg[n].mr_offset = (void *)(unsigned long) page_base;
seg[n].mr_len = min_t(u32, PAGE_SIZE - page_base, len);
if (seg[n].mr_len > PAGE_SIZE)
return -EIO;
len -= seg[n].mr_len;
++n;
++p;
page_base = 0;
}
if (len && n == nsegs)
return -EIO;
if (type == rpcrdma_readch)
return n;
if (xdrbuf->tail[0].iov_len) {
if (xdrbuf->tail[0].iov_len < 4 && xprt_rdma_pad_optimize)
return n;
if (n == nsegs)
return -EIO;
seg[n].mr_page = NULL;
seg[n].mr_offset = xdrbuf->tail[0].iov_base;
seg[n].mr_len = xdrbuf->tail[0].iov_len;
++n;
}
return n;
}
static ssize_t
rpcrdma_create_chunks(struct rpc_rqst *rqst, struct xdr_buf *target,
struct rpcrdma_msg *headerp, enum rpcrdma_chunktype type)
{
struct rpcrdma_req *req = rpcr_to_rdmar(rqst);
struct rpcrdma_xprt *r_xprt = rpcx_to_rdmax(rqst->rq_xprt);
int n, nsegs, nchunks = 0;
unsigned int pos;
struct rpcrdma_mr_seg *seg = req->rl_segments;
struct rpcrdma_read_chunk *cur_rchunk = NULL;
struct rpcrdma_write_array *warray = NULL;
struct rpcrdma_write_chunk *cur_wchunk = NULL;
__be32 *iptr = headerp->rm_body.rm_chunks;
int (*map)(struct rpcrdma_xprt *, struct rpcrdma_mr_seg *, int, bool);
if (type == rpcrdma_readch || type == rpcrdma_areadch) {
cur_rchunk = (struct rpcrdma_read_chunk *) iptr;
} else {
*iptr++ = xdr_zero;
if (type == rpcrdma_replych)
*iptr++ = xdr_zero;
warray = (struct rpcrdma_write_array *) iptr;
cur_wchunk = (struct rpcrdma_write_chunk *) (warray + 1);
}
if (type == rpcrdma_replych || type == rpcrdma_areadch)
pos = 0;
else
pos = target->head[0].iov_len;
nsegs = rpcrdma_convert_iovs(target, pos, type, seg, RPCRDMA_MAX_SEGS);
if (nsegs < 0)
return nsegs;
map = r_xprt->rx_ia.ri_ops->ro_map;
do {
n = map(r_xprt, seg, nsegs, cur_wchunk != NULL);
if (n <= 0)
goto out;
if (cur_rchunk) {
cur_rchunk->rc_discrim = xdr_one;
cur_rchunk->rc_position = cpu_to_be32(pos);
cur_rchunk->rc_target.rs_handle =
cpu_to_be32(seg->mr_rkey);
cur_rchunk->rc_target.rs_length =
cpu_to_be32(seg->mr_len);
xdr_encode_hyper(
(__be32 *)&cur_rchunk->rc_target.rs_offset,
seg->mr_base);
dprintk("RPC: %s: read chunk "
"elem %d@0x%llx:0x%x pos %u (%s)\n", __func__,
seg->mr_len, (unsigned long long)seg->mr_base,
seg->mr_rkey, pos, n < nsegs ? "more" : "last");
cur_rchunk++;
r_xprt->rx_stats.read_chunk_count++;
} else {
cur_wchunk->wc_target.rs_handle =
cpu_to_be32(seg->mr_rkey);
cur_wchunk->wc_target.rs_length =
cpu_to_be32(seg->mr_len);
xdr_encode_hyper(
(__be32 *)&cur_wchunk->wc_target.rs_offset,
seg->mr_base);
dprintk("RPC: %s: %s chunk "
"elem %d@0x%llx:0x%x (%s)\n", __func__,
(type == rpcrdma_replych) ? "reply" : "write",
seg->mr_len, (unsigned long long)seg->mr_base,
seg->mr_rkey, n < nsegs ? "more" : "last");
cur_wchunk++;
if (type == rpcrdma_replych)
r_xprt->rx_stats.reply_chunk_count++;
else
r_xprt->rx_stats.write_chunk_count++;
r_xprt->rx_stats.total_rdma_request += seg->mr_len;
}
nchunks++;
seg += n;
nsegs -= n;
} while (nsegs);
req->rl_nchunks = nchunks;
if (cur_rchunk) {
iptr = (__be32 *) cur_rchunk;
*iptr++ = xdr_zero;
*iptr++ = xdr_zero;
*iptr++ = xdr_zero;
} else {
warray->wc_discrim = xdr_one;
warray->wc_nchunks = cpu_to_be32(nchunks);
iptr = (__be32 *) cur_wchunk;
if (type == rpcrdma_writech) {
*iptr++ = xdr_zero;
*iptr++ = xdr_zero;
}
}
return (unsigned char *)iptr - (unsigned char *)headerp;
out:
for (pos = 0; nchunks--;)
pos += r_xprt->rx_ia.ri_ops->ro_unmap(r_xprt,
&req->rl_segments[pos]);
return n;
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
char *base;
size_t rpclen;
ssize_t hdrlen;
enum rpcrdma_chunktype rtype, wtype;
struct rpcrdma_msg *headerp;
base = rqst->rq_svec[0].iov_base;
rpclen = rqst->rq_svec[0].iov_len;
headerp = rdmab_to_msg(req->rl_rdmabuf);
headerp->rm_xid = rqst->rq_xid;
headerp->rm_vers = rpcrdma_version;
headerp->rm_credit = cpu_to_be32(r_xprt->rx_buf.rb_max_requests);
headerp->rm_type = rdma_msg;
if (rqst->rq_rcv_buf.flags & XDRBUF_READ)
wtype = rpcrdma_writech;
else if (rpcrdma_results_inline(rqst))
wtype = rpcrdma_noch;
else
wtype = rpcrdma_replych;
if (rpcrdma_args_inline(rqst)) {
rtype = rpcrdma_noch;
} else if (rqst->rq_snd_buf.flags & XDRBUF_WRITE) {
rtype = rpcrdma_readch;
} else {
r_xprt->rx_stats.nomsg_call_count++;
headerp->rm_type = htonl(RDMA_NOMSG);
rtype = rpcrdma_areadch;
rpclen = 0;
}
if (rtype != rpcrdma_noch && wtype == rpcrdma_replych)
wtype = rpcrdma_noch;
if (rtype != rpcrdma_noch && wtype != rpcrdma_noch) {
dprintk("RPC: %s: cannot marshal multiple chunk lists\n",
__func__);
return -EIO;
}
hdrlen = RPCRDMA_HDRLEN_MIN;
if (rtype == rpcrdma_noch) {
rpcrdma_inline_pullup(rqst);
headerp->rm_body.rm_nochunks.rm_empty[0] = xdr_zero;
headerp->rm_body.rm_nochunks.rm_empty[1] = xdr_zero;
headerp->rm_body.rm_nochunks.rm_empty[2] = xdr_zero;
rpclen = rqst->rq_svec[0].iov_len;
} else if (rtype == rpcrdma_readch)
rpclen += rpcrdma_tail_pullup(&rqst->rq_snd_buf);
if (rtype != rpcrdma_noch) {
hdrlen = rpcrdma_create_chunks(rqst, &rqst->rq_snd_buf,
headerp, rtype);
wtype = rtype;
} else if (wtype != rpcrdma_noch) {
hdrlen = rpcrdma_create_chunks(rqst, &rqst->rq_rcv_buf,
headerp, wtype);
}
if (hdrlen < 0)
return hdrlen;
dprintk("RPC: %s: %s: hdrlen %zd rpclen %zd"
" headerp 0x%p base 0x%p lkey 0x%x\n",
__func__, transfertypes[wtype], hdrlen, rpclen,
headerp, base, rdmab_lkey(req->rl_rdmabuf));
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
}
static int
rpcrdma_count_chunks(struct rpcrdma_rep *rep, unsigned int max, int wrchunk, __be32 **iptrp)
{
unsigned int i, total_len;
struct rpcrdma_write_chunk *cur_wchunk;
char *base = (char *)rdmab_to_msg(rep->rr_rdmabuf);
i = be32_to_cpu(**iptrp);
if (i > max)
return -1;
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
static void
rpcrdma_inline_fixup(struct rpc_rqst *rqst, char *srcp, int copy_len, int pad)
{
int i, npages, curlen, olen;
char *destp;
struct page **ppages;
int page_base;
curlen = rqst->rq_rcv_buf.head[0].iov_len;
if (curlen > copy_len) {
curlen = copy_len;
rqst->rq_rcv_buf.head[0].iov_len = curlen;
}
dprintk("RPC: %s: srcp 0x%p len %d hdrlen %d\n",
__func__, srcp, copy_len, curlen);
rqst->rq_rcv_buf.head[0].iov_base = srcp;
srcp += curlen;
copy_len -= curlen;
olen = copy_len;
i = 0;
rpcx_to_rdmax(rqst->rq_xprt)->rx_stats.fixup_copy_count += olen;
page_base = rqst->rq_rcv_buf.page_base;
ppages = rqst->rq_rcv_buf.pages + (page_base >> PAGE_SHIFT);
page_base &= ~PAGE_MASK;
if (copy_len && rqst->rq_rcv_buf.page_len) {
npages = PAGE_ALIGN(page_base +
rqst->rq_rcv_buf.page_len) >> PAGE_SHIFT;
for (; i < npages; i++) {
curlen = PAGE_SIZE - page_base;
if (curlen > copy_len)
curlen = copy_len;
dprintk("RPC: %s: page %d"
" srcp 0x%p len %d curlen %d\n",
__func__, i, srcp, copy_len, curlen);
destp = kmap_atomic(ppages[i]);
memcpy(destp + page_base, srcp, curlen);
flush_dcache_page(ppages[i]);
kunmap_atomic(destp);
srcp += curlen;
copy_len -= curlen;
if (copy_len == 0)
break;
page_base = 0;
}
}
if (copy_len && rqst->rq_rcv_buf.tail[0].iov_len) {
curlen = copy_len;
if (curlen > rqst->rq_rcv_buf.tail[0].iov_len)
curlen = rqst->rq_rcv_buf.tail[0].iov_len;
if (rqst->rq_rcv_buf.tail[0].iov_base != srcp)
memmove(rqst->rq_rcv_buf.tail[0].iov_base, srcp, curlen);
dprintk("RPC: %s: tail srcp 0x%p len %d curlen %d\n",
__func__, srcp, copy_len, curlen);
rqst->rq_rcv_buf.tail[0].iov_len = curlen;
copy_len -= curlen; ++i;
} else
rqst->rq_rcv_buf.tail[0].iov_len = 0;
if (pad) {
unsigned char *p = rqst->rq_rcv_buf.tail[0].iov_base;
while (pad--)
p[rqst->rq_rcv_buf.tail[0].iov_len++] = 0;
}
if (copy_len)
dprintk("RPC: %s: %d bytes in"
" %d extra segments (%d lost)\n",
__func__, olen, i, copy_len);
rqst->rq_private_buf = rqst->rq_rcv_buf;
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
int rdmalen, status;
unsigned long cwnd;
u32 credits;
if (rep->rr_len == ~0U) {
rpcrdma_recv_buffer_put(rep);
if (r_xprt->rx_ep.rep_connected == 1) {
r_xprt->rx_ep.rep_connected = -EIO;
rpcrdma_conn_func(&r_xprt->rx_ep);
}
return;
}
if (rep->rr_len < RPCRDMA_HDRLEN_MIN) {
dprintk("RPC: %s: short/invalid reply\n", __func__);
goto repost;
}
headerp = rdmab_to_msg(rep->rr_rdmabuf);
if (headerp->rm_vers != rpcrdma_version) {
dprintk("RPC: %s: invalid version %d\n",
__func__, be32_to_cpu(headerp->rm_vers));
goto repost;
}
spin_lock(&xprt->transport_lock);
rqst = xprt_lookup_rqst(xprt, headerp->rm_xid);
if (rqst == NULL) {
spin_unlock(&xprt->transport_lock);
dprintk("RPC: %s: reply 0x%p failed "
"to match any request xid 0x%08x len %d\n",
__func__, rep, be32_to_cpu(headerp->rm_xid),
rep->rr_len);
repost:
r_xprt->rx_stats.bad_reply_count++;
if (rpcrdma_ep_post_recv(&r_xprt->rx_ia, &r_xprt->rx_ep, rep))
rpcrdma_recv_buffer_put(rep);
return;
}
req = rpcr_to_rdmar(rqst);
if (req->rl_reply) {
spin_unlock(&xprt->transport_lock);
dprintk("RPC: %s: duplicate reply 0x%p to RPC "
"request 0x%p: xid 0x%08x\n", __func__, rep, req,
be32_to_cpu(headerp->rm_xid));
goto repost;
}
dprintk("RPC: %s: reply 0x%p completes request 0x%p\n"
" RPC request 0x%p xid 0x%08x\n",
__func__, rep, req, rqst,
be32_to_cpu(headerp->rm_xid));
req->rl_reply = rep;
xprt->reestablish_timeout = 0;
switch (headerp->rm_type) {
case rdma_msg:
if (headerp->rm_body.rm_chunks[0] != xdr_zero ||
(headerp->rm_body.rm_chunks[1] == xdr_zero &&
headerp->rm_body.rm_chunks[2] != xdr_zero) ||
(headerp->rm_body.rm_chunks[1] != xdr_zero &&
req->rl_nchunks == 0))
goto badheader;
if (headerp->rm_body.rm_chunks[1] != xdr_zero) {
iptr = &headerp->rm_body.rm_chunks[2];
rdmalen = rpcrdma_count_chunks(rep,
req->rl_nchunks, 1, &iptr);
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
rpcrdma_inline_fixup(rqst, (char *)iptr, rep->rr_len, rdmalen);
break;
case rdma_nomsg:
if (headerp->rm_body.rm_chunks[0] != xdr_zero ||
headerp->rm_body.rm_chunks[1] != xdr_zero ||
headerp->rm_body.rm_chunks[2] != xdr_one ||
req->rl_nchunks == 0)
goto badheader;
iptr = (__be32 *)((unsigned char *)headerp +
RPCRDMA_HDRLEN_MIN);
rdmalen = rpcrdma_count_chunks(rep, req->rl_nchunks, 0, &iptr);
if (rdmalen < 0)
goto badheader;
r_xprt->rx_stats.total_rdma_reply += rdmalen;
status = rdmalen;
break;
badheader:
default:
dprintk("%s: invalid rpcrdma reply header (type %d):"
" chunks[012] == %d %d %d"
" expected chunks <= %d\n",
__func__, be32_to_cpu(headerp->rm_type),
headerp->rm_body.rm_chunks[0],
headerp->rm_body.rm_chunks[1],
headerp->rm_body.rm_chunks[2],
req->rl_nchunks);
status = -EIO;
r_xprt->rx_stats.bad_reply_count++;
break;
}
credits = be32_to_cpu(headerp->rm_credit);
if (credits == 0)
credits = 1;
else if (credits > r_xprt->rx_buf.rb_max_requests)
credits = r_xprt->rx_buf.rb_max_requests;
cwnd = xprt->cwnd;
xprt->cwnd = credits << RPC_CWNDSHIFT;
if (xprt->cwnd > cwnd)
xprt_release_rqst_cong(rqst->rq_task);
dprintk("RPC: %s: xprt_complete_rqst(0x%p, 0x%p, %d)\n",
__func__, xprt, rqst, status);
xprt_complete_rqst(rqst->rq_task, status);
spin_unlock(&xprt->transport_lock);
}
