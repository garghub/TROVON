static void rdma_build_arg_xdr(struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *ctxt,
u32 byte_count)
{
struct page *page;
u32 bc;
int sge_no;
page = ctxt->pages[0];
put_page(rqstp->rq_pages[0]);
rqstp->rq_pages[0] = page;
rqstp->rq_arg.head[0].iov_base = page_address(page);
rqstp->rq_arg.head[0].iov_len =
min_t(size_t, byte_count, ctxt->sge[0].length);
rqstp->rq_arg.len = byte_count;
rqstp->rq_arg.buflen = byte_count;
bc = byte_count - rqstp->rq_arg.head[0].iov_len;
rqstp->rq_arg.page_len = bc;
rqstp->rq_arg.page_base = 0;
sge_no = 1;
while (bc && sge_no < ctxt->count) {
page = ctxt->pages[sge_no];
put_page(rqstp->rq_pages[sge_no]);
rqstp->rq_pages[sge_no] = page;
bc -= min_t(u32, bc, ctxt->sge[sge_no].length);
sge_no++;
}
rqstp->rq_respages = &rqstp->rq_pages[sge_no];
rqstp->rq_next_page = rqstp->rq_respages + 1;
bc = sge_no;
while (sge_no < ctxt->count) {
page = ctxt->pages[sge_no++];
put_page(page);
}
ctxt->count = bc;
rqstp->rq_arg.tail[0].iov_base = NULL;
rqstp->rq_arg.tail[0].iov_len = 0;
}
static __be32 *xdr_check_read_list(__be32 *p, const __be32 *end)
{
u32 position;
bool first;
first = true;
while (*p++ != xdr_zero) {
if (first) {
position = be32_to_cpup(p++);
first = false;
} else if (be32_to_cpup(p++) != position) {
return NULL;
}
p++;
if (be32_to_cpup(p++) > MAX_BYTES_SPECIAL_SEG)
return NULL;
p += 2;
if (p > end)
return NULL;
}
return p;
}
static __be32 *xdr_check_write_chunk(__be32 *p, const __be32 *end,
u32 maxlen)
{
u32 i, segcount;
segcount = be32_to_cpup(p++);
for (i = 0; i < segcount; i++) {
p++;
if (be32_to_cpup(p++) > maxlen)
return NULL;
p += 2;
if (p > end)
return NULL;
}
return p;
}
static __be32 *xdr_check_write_list(__be32 *p, const __be32 *end)
{
u32 chcount;
chcount = 0;
while (*p++ != xdr_zero) {
p = xdr_check_write_chunk(p, end, MAX_BYTES_WRITE_SEG);
if (!p)
return NULL;
if (chcount++ > 1)
return NULL;
}
return p;
}
static __be32 *xdr_check_reply_chunk(__be32 *p, const __be32 *end)
{
if (*p++ != xdr_zero) {
p = xdr_check_write_chunk(p, end, MAX_BYTES_SPECIAL_SEG);
if (!p)
return NULL;
}
return p;
}
static int svc_rdma_xdr_decode_req(struct xdr_buf *rq_arg)
{
__be32 *p, *end, *rdma_argp;
unsigned int hdr_len;
char *proc;
if (rq_arg->len <= RPCRDMA_HDRLEN_ERR)
goto out_short;
rdma_argp = rq_arg->head[0].iov_base;
if (*(rdma_argp + 1) != rpcrdma_version)
goto out_version;
switch (*(rdma_argp + 3)) {
case rdma_msg:
proc = "RDMA_MSG";
break;
case rdma_nomsg:
proc = "RDMA_NOMSG";
break;
case rdma_done:
goto out_drop;
case rdma_error:
goto out_drop;
default:
goto out_proc;
}
end = (__be32 *)((unsigned long)rdma_argp + rq_arg->len);
p = xdr_check_read_list(rdma_argp + 4, end);
if (!p)
goto out_inval;
p = xdr_check_write_list(p, end);
if (!p)
goto out_inval;
p = xdr_check_reply_chunk(p, end);
if (!p)
goto out_inval;
if (p > end)
goto out_inval;
rq_arg->head[0].iov_base = p;
hdr_len = (unsigned long)p - (unsigned long)rdma_argp;
rq_arg->head[0].iov_len -= hdr_len;
rq_arg->len -= hdr_len;
dprintk("svcrdma: received %s request for XID 0x%08x, hdr_len=%u\n",
proc, be32_to_cpup(rdma_argp), hdr_len);
return hdr_len;
out_short:
dprintk("svcrdma: header too short = %d\n", rq_arg->len);
return -EINVAL;
out_version:
dprintk("svcrdma: bad xprt version: %u\n",
be32_to_cpup(rdma_argp + 1));
return -EPROTONOSUPPORT;
out_drop:
dprintk("svcrdma: dropping RDMA_DONE/ERROR message\n");
return 0;
out_proc:
dprintk("svcrdma: bad rdma procedure (%u)\n",
be32_to_cpup(rdma_argp + 3));
return -EINVAL;
out_inval:
dprintk("svcrdma: failed to parse transport header\n");
return -EINVAL;
}
static void rdma_read_complete(struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head)
{
int page_no;
for (page_no = 0; page_no < head->count; page_no++) {
put_page(rqstp->rq_pages[page_no]);
rqstp->rq_pages[page_no] = head->pages[page_no];
}
rqstp->rq_arg.pages = &rqstp->rq_pages[head->hdr_count];
rqstp->rq_arg.page_len = head->arg.page_len;
rqstp->rq_respages = &rqstp->rq_pages[page_no];
rqstp->rq_next_page = rqstp->rq_respages + 1;
rqstp->rq_arg.head[0] = head->arg.head[0];
rqstp->rq_arg.tail[0] = head->arg.tail[0];
rqstp->rq_arg.len = head->arg.len;
rqstp->rq_arg.buflen = head->arg.buflen;
}
static void svc_rdma_send_error(struct svcxprt_rdma *xprt,
__be32 *rdma_argp, int status)
{
struct svc_rdma_op_ctxt *ctxt;
__be32 *p, *err_msgp;
unsigned int length;
struct page *page;
int ret;
ret = svc_rdma_repost_recv(xprt, GFP_KERNEL);
if (ret)
return;
page = alloc_page(GFP_KERNEL);
if (!page)
return;
err_msgp = page_address(page);
p = err_msgp;
*p++ = *rdma_argp;
*p++ = *(rdma_argp + 1);
*p++ = xprt->sc_fc_credits;
*p++ = rdma_error;
if (status == -EPROTONOSUPPORT) {
*p++ = err_vers;
*p++ = rpcrdma_version;
*p++ = rpcrdma_version;
} else {
*p++ = err_chunk;
}
length = (unsigned long)p - (unsigned long)err_msgp;
ctxt = svc_rdma_get_context(xprt);
ret = svc_rdma_map_reply_hdr(xprt, ctxt, err_msgp, length);
if (ret) {
dprintk("svcrdma: Error %d mapping send for protocol error\n",
ret);
return;
}
ret = svc_rdma_post_send_wr(xprt, ctxt, 1, 0);
if (ret) {
dprintk("svcrdma: Error %d posting send for protocol error\n",
ret);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
}
}
static bool svc_rdma_is_backchannel_reply(struct svc_xprt *xprt,
__be32 *rdma_resp)
{
__be32 *p;
if (!xprt->xpt_bc_xprt)
return false;
p = rdma_resp + 3;
if (*p++ != rdma_msg)
return false;
if (*p++ != xdr_zero)
return false;
if (*p++ != xdr_zero)
return false;
if (*p++ != xdr_zero)
return false;
if (*p++ != *rdma_resp)
return false;
if (*p == cpu_to_be32(RPC_CALL))
return false;
return true;
}
int svc_rdma_recvfrom(struct svc_rqst *rqstp)
{
struct svc_xprt *xprt = rqstp->rq_xprt;
struct svcxprt_rdma *rdma_xprt =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
struct svc_rdma_op_ctxt *ctxt;
__be32 *p;
int ret;
spin_lock(&rdma_xprt->sc_rq_dto_lock);
if (!list_empty(&rdma_xprt->sc_read_complete_q)) {
ctxt = list_first_entry(&rdma_xprt->sc_read_complete_q,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
spin_unlock(&rdma_xprt->sc_rq_dto_lock);
rdma_read_complete(rqstp, ctxt);
goto complete;
} else if (!list_empty(&rdma_xprt->sc_rq_dto_q)) {
ctxt = list_first_entry(&rdma_xprt->sc_rq_dto_q,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
} else {
clear_bit(XPT_DATA, &xprt->xpt_flags);
spin_unlock(&rdma_xprt->sc_rq_dto_lock);
return 0;
}
spin_unlock(&rdma_xprt->sc_rq_dto_lock);
dprintk("svcrdma: recvfrom: ctxt=%p on xprt=%p, rqstp=%p\n",
ctxt, rdma_xprt, rqstp);
atomic_inc(&rdma_stat_recv);
rdma_build_arg_xdr(rqstp, ctxt, ctxt->byte_len);
p = (__be32 *)rqstp->rq_arg.head[0].iov_base;
ret = svc_rdma_xdr_decode_req(&rqstp->rq_arg);
if (ret < 0)
goto out_err;
if (ret == 0)
goto out_drop;
rqstp->rq_xprt_hlen = ret;
if (svc_rdma_is_backchannel_reply(xprt, p)) {
ret = svc_rdma_handle_bc_reply(xprt->xpt_bc_xprt, p,
&rqstp->rq_arg);
svc_rdma_put_context(ctxt, 0);
if (ret)
goto repost;
return ret;
}
p += rpcrdma_fixed_maxsz;
if (*p != xdr_zero)
goto out_readchunk;
complete:
svc_rdma_put_context(ctxt, 0);
dprintk("svcrdma: recvfrom: xprt=%p, rqstp=%p, rq_arg.len=%u\n",
rdma_xprt, rqstp, rqstp->rq_arg.len);
rqstp->rq_prot = IPPROTO_MAX;
svc_xprt_copy_addrs(rqstp, xprt);
return rqstp->rq_arg.len;
out_readchunk:
ret = svc_rdma_recv_read_chunk(rdma_xprt, rqstp, ctxt, p);
if (ret < 0)
goto out_postfail;
return 0;
out_err:
svc_rdma_send_error(rdma_xprt, p, ret);
svc_rdma_put_context(ctxt, 0);
return 0;
out_postfail:
if (ret == -EINVAL)
svc_rdma_send_error(rdma_xprt, p, ret);
svc_rdma_put_context(ctxt, 1);
return ret;
out_drop:
svc_rdma_put_context(ctxt, 1);
repost:
return svc_rdma_repost_recv(rdma_xprt, GFP_KERNEL);
}
