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
int svc_rdma_xdr_encode_error(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rmsgp,
enum rpcrdma_errcode err, __be32 *va)
{
__be32 *startp = va;
*va++ = rmsgp->rm_xid;
*va++ = rmsgp->rm_vers;
*va++ = xprt->sc_fc_credits;
*va++ = rdma_error;
*va++ = cpu_to_be32(err);
if (err == ERR_VERS) {
*va++ = rpcrdma_version;
*va++ = rpcrdma_version;
}
return (int)((unsigned long)va - (unsigned long)startp);
}
unsigned int svc_rdma_xdr_get_reply_hdr_len(__be32 *rdma_resp)
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
void svc_rdma_xdr_encode_write_list(struct rpcrdma_msg *rmsgp, int chunks)
{
struct rpcrdma_write_array *ary;
rmsgp->rm_body.rm_chunks[0] = xdr_zero;
ary = (struct rpcrdma_write_array *)
&rmsgp->rm_body.rm_chunks[1];
ary->wc_discrim = xdr_one;
ary->wc_nchunks = cpu_to_be32(chunks);
ary->wc_array[chunks].wc_target.rs_handle = xdr_zero;
ary->wc_array[chunks].wc_target.rs_length = xdr_zero;
}
void svc_rdma_xdr_encode_reply_array(struct rpcrdma_write_array *ary,
int chunks)
{
ary->wc_discrim = xdr_one;
ary->wc_nchunks = cpu_to_be32(chunks);
}
void svc_rdma_xdr_encode_array_chunk(struct rpcrdma_write_array *ary,
int chunk_no,
__be32 rs_handle,
__be64 rs_offset,
u32 write_len)
{
struct rpcrdma_segment *seg = &ary->wc_array[chunk_no].wc_target;
seg->rs_handle = rs_handle;
seg->rs_offset = rs_offset;
seg->rs_length = cpu_to_be32(write_len);
}
