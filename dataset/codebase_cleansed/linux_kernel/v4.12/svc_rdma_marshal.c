static __be32 *xdr_check_read_list(__be32 *p, __be32 *end)
{
__be32 *next;
while (*p++ != xdr_zero) {
next = p + rpcrdma_readchunk_maxsz - 1;
if (next > end)
return NULL;
p = next;
}
return p;
}
static __be32 *xdr_check_write_list(__be32 *p, __be32 *end)
{
__be32 *next;
while (*p++ != xdr_zero) {
next = p + 1 + be32_to_cpup(p) * rpcrdma_segment_maxsz;
if (next > end)
return NULL;
p = next;
}
return p;
}
static __be32 *xdr_check_reply_chunk(__be32 *p, __be32 *end)
{
__be32 *next;
if (*p++ != xdr_zero) {
next = p + 1 + be32_to_cpup(p) * rpcrdma_segment_maxsz;
if (next > end)
return NULL;
p = next;
}
return p;
}
int svc_rdma_xdr_decode_req(struct xdr_buf *rq_arg)
{
__be32 *p, *end, *rdma_argp;
unsigned int hdr_len;
if (rq_arg->len <= RPCRDMA_HDRLEN_ERR)
goto out_short;
rdma_argp = rq_arg->head[0].iov_base;
if (*(rdma_argp + 1) != rpcrdma_version)
goto out_version;
switch (*(rdma_argp + 3)) {
case rdma_msg:
case rdma_nomsg:
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
