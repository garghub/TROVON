static u32 *decode_read_list(u32 *va, u32 *vaend)
{
struct rpcrdma_read_chunk *ch = (struct rpcrdma_read_chunk *)va;
while (ch->rc_discrim != xdr_zero) {
u64 ch_offset;
if (((unsigned long)ch + sizeof(struct rpcrdma_read_chunk)) >
(unsigned long)vaend) {
dprintk("svcrdma: vaend=%p, ch=%p\n", vaend, ch);
return NULL;
}
ch->rc_discrim = ntohl(ch->rc_discrim);
ch->rc_position = ntohl(ch->rc_position);
ch->rc_target.rs_handle = ntohl(ch->rc_target.rs_handle);
ch->rc_target.rs_length = ntohl(ch->rc_target.rs_length);
va = (u32 *)&ch->rc_target.rs_offset;
xdr_decode_hyper(va, &ch_offset);
put_unaligned(ch_offset, (u64 *)va);
ch++;
}
return (u32 *)&ch->rc_position;
}
void svc_rdma_rcl_chunk_counts(struct rpcrdma_read_chunk *ch,
int *ch_count, int *byte_count)
{
*byte_count = 0;
*ch_count = 0;
for (; ch->rc_discrim != 0; ch++) {
*byte_count = *byte_count + ch->rc_target.rs_length;
*ch_count = *ch_count + 1;
}
}
static u32 *decode_write_list(u32 *va, u32 *vaend)
{
int ch_no;
struct rpcrdma_write_array *ary =
(struct rpcrdma_write_array *)va;
if (ary->wc_discrim == xdr_zero)
return (u32 *)&ary->wc_nchunks;
if ((unsigned long)ary + sizeof(struct rpcrdma_write_array) >
(unsigned long)vaend) {
dprintk("svcrdma: ary=%p, vaend=%p\n", ary, vaend);
return NULL;
}
ary->wc_discrim = ntohl(ary->wc_discrim);
ary->wc_nchunks = ntohl(ary->wc_nchunks);
if (((unsigned long)&ary->wc_array[0] +
(sizeof(struct rpcrdma_write_chunk) * ary->wc_nchunks)) >
(unsigned long)vaend) {
dprintk("svcrdma: ary=%p, wc_nchunks=%d, vaend=%p\n",
ary, ary->wc_nchunks, vaend);
return NULL;
}
for (ch_no = 0; ch_no < ary->wc_nchunks; ch_no++) {
u64 ch_offset;
ary->wc_array[ch_no].wc_target.rs_handle =
ntohl(ary->wc_array[ch_no].wc_target.rs_handle);
ary->wc_array[ch_no].wc_target.rs_length =
ntohl(ary->wc_array[ch_no].wc_target.rs_length);
va = (u32 *)&ary->wc_array[ch_no].wc_target.rs_offset;
xdr_decode_hyper(va, &ch_offset);
put_unaligned(ch_offset, (u64 *)va);
}
return (u32 *)&ary->wc_array[ch_no].wc_target.rs_length;
}
static u32 *decode_reply_array(u32 *va, u32 *vaend)
{
int ch_no;
struct rpcrdma_write_array *ary =
(struct rpcrdma_write_array *)va;
if (ary->wc_discrim == xdr_zero)
return (u32 *)&ary->wc_nchunks;
if ((unsigned long)ary + sizeof(struct rpcrdma_write_array) >
(unsigned long)vaend) {
dprintk("svcrdma: ary=%p, vaend=%p\n", ary, vaend);
return NULL;
}
ary->wc_discrim = ntohl(ary->wc_discrim);
ary->wc_nchunks = ntohl(ary->wc_nchunks);
if (((unsigned long)&ary->wc_array[0] +
(sizeof(struct rpcrdma_write_chunk) * ary->wc_nchunks)) >
(unsigned long)vaend) {
dprintk("svcrdma: ary=%p, wc_nchunks=%d, vaend=%p\n",
ary, ary->wc_nchunks, vaend);
return NULL;
}
for (ch_no = 0; ch_no < ary->wc_nchunks; ch_no++) {
u64 ch_offset;
ary->wc_array[ch_no].wc_target.rs_handle =
ntohl(ary->wc_array[ch_no].wc_target.rs_handle);
ary->wc_array[ch_no].wc_target.rs_length =
ntohl(ary->wc_array[ch_no].wc_target.rs_length);
va = (u32 *)&ary->wc_array[ch_no].wc_target.rs_offset;
xdr_decode_hyper(va, &ch_offset);
put_unaligned(ch_offset, (u64 *)va);
}
return (u32 *)&ary->wc_array[ch_no];
}
int svc_rdma_xdr_decode_req(struct rpcrdma_msg **rdma_req,
struct svc_rqst *rqstp)
{
struct rpcrdma_msg *rmsgp = NULL;
u32 *va;
u32 *vaend;
u32 hdr_len;
rmsgp = (struct rpcrdma_msg *)rqstp->rq_arg.head[0].iov_base;
if (rqstp->rq_arg.len <= RPCRDMA_HDRLEN_MIN) {
dprintk("svcrdma: header too short = %d\n",
rqstp->rq_arg.len);
return -EINVAL;
}
rmsgp->rm_xid = ntohl(rmsgp->rm_xid);
rmsgp->rm_vers = ntohl(rmsgp->rm_vers);
rmsgp->rm_credit = ntohl(rmsgp->rm_credit);
rmsgp->rm_type = ntohl(rmsgp->rm_type);
if (rmsgp->rm_vers != RPCRDMA_VERSION)
return -ENOSYS;
if (rmsgp->rm_type == RDMA_MSGP) {
int hdrlen;
rmsgp->rm_body.rm_padded.rm_align =
ntohl(rmsgp->rm_body.rm_padded.rm_align);
rmsgp->rm_body.rm_padded.rm_thresh =
ntohl(rmsgp->rm_body.rm_padded.rm_thresh);
va = &rmsgp->rm_body.rm_padded.rm_pempty[4];
rqstp->rq_arg.head[0].iov_base = va;
hdrlen = (u32)((unsigned long)va - (unsigned long)rmsgp);
rqstp->rq_arg.head[0].iov_len -= hdrlen;
if (hdrlen > rqstp->rq_arg.len)
return -EINVAL;
return hdrlen;
}
va = &rmsgp->rm_body.rm_chunks[0];
vaend = (u32 *)((unsigned long)rmsgp + rqstp->rq_arg.len);
va = decode_read_list(va, vaend);
if (!va)
return -EINVAL;
va = decode_write_list(va, vaend);
if (!va)
return -EINVAL;
va = decode_reply_array(va, vaend);
if (!va)
return -EINVAL;
rqstp->rq_arg.head[0].iov_base = va;
hdr_len = (unsigned long)va - (unsigned long)rmsgp;
rqstp->rq_arg.head[0].iov_len -= hdr_len;
*rdma_req = rmsgp;
return hdr_len;
}
int svc_rdma_xdr_decode_deferred_req(struct svc_rqst *rqstp)
{
struct rpcrdma_msg *rmsgp = NULL;
struct rpcrdma_read_chunk *ch;
struct rpcrdma_write_array *ary;
u32 *va;
u32 hdrlen;
dprintk("svcrdma: processing deferred RDMA header on rqstp=%p\n",
rqstp);
rmsgp = (struct rpcrdma_msg *)rqstp->rq_arg.head[0].iov_base;
if (rmsgp->rm_type == RDMA_MSGP) {
va = &rmsgp->rm_body.rm_padded.rm_pempty[4];
rqstp->rq_arg.head[0].iov_base = va;
hdrlen = (u32)((unsigned long)va - (unsigned long)rmsgp);
rqstp->rq_arg.head[0].iov_len -= hdrlen;
return hdrlen;
}
va = &rmsgp->rm_body.rm_chunks[0];
for (ch = (struct rpcrdma_read_chunk *)va;
ch->rc_discrim != xdr_zero; ch++);
va = (u32 *)&ch->rc_position;
ary = (struct rpcrdma_write_array *)va;
if (ary->wc_discrim == xdr_zero)
va = (u32 *)&ary->wc_nchunks;
else
va = (u32 *)&ary->wc_array[ary->wc_nchunks].wc_target.rs_length;
ary = (struct rpcrdma_write_array *)va;
if (ary->wc_discrim == xdr_zero)
va = (u32 *)&ary->wc_nchunks;
else
va = (u32 *)&ary->wc_array[ary->wc_nchunks];
rqstp->rq_arg.head[0].iov_base = va;
hdrlen = (unsigned long)va - (unsigned long)rmsgp;
rqstp->rq_arg.head[0].iov_len -= hdrlen;
return hdrlen;
}
int svc_rdma_xdr_encode_error(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rmsgp,
enum rpcrdma_errcode err, u32 *va)
{
u32 *startp = va;
*va++ = htonl(rmsgp->rm_xid);
*va++ = htonl(rmsgp->rm_vers);
*va++ = htonl(xprt->sc_max_requests);
*va++ = htonl(RDMA_ERROR);
*va++ = htonl(err);
if (err == ERR_VERS) {
*va++ = htonl(RPCRDMA_VERSION);
*va++ = htonl(RPCRDMA_VERSION);
}
return (int)((unsigned long)va - (unsigned long)startp);
}
int svc_rdma_xdr_get_reply_hdr_len(struct rpcrdma_msg *rmsgp)
{
struct rpcrdma_write_array *wr_ary;
wr_ary = (struct rpcrdma_write_array *)
&rmsgp->rm_body.rm_chunks[1];
if (wr_ary->wc_discrim)
wr_ary = (struct rpcrdma_write_array *)
&wr_ary->wc_array[ntohl(wr_ary->wc_nchunks)].
wc_target.rs_length;
else
wr_ary = (struct rpcrdma_write_array *)
&wr_ary->wc_nchunks;
if (wr_ary->wc_discrim)
wr_ary = (struct rpcrdma_write_array *)
&wr_ary->wc_array[ntohl(wr_ary->wc_nchunks)];
else
wr_ary = (struct rpcrdma_write_array *)
&wr_ary->wc_nchunks;
return (unsigned long) wr_ary - (unsigned long) rmsgp;
}
void svc_rdma_xdr_encode_write_list(struct rpcrdma_msg *rmsgp, int chunks)
{
struct rpcrdma_write_array *ary;
rmsgp->rm_body.rm_chunks[0] = xdr_zero;
ary = (struct rpcrdma_write_array *)
&rmsgp->rm_body.rm_chunks[1];
ary->wc_discrim = xdr_one;
ary->wc_nchunks = htonl(chunks);
ary->wc_array[chunks].wc_target.rs_handle = xdr_zero;
ary->wc_array[chunks].wc_target.rs_length = xdr_zero;
}
void svc_rdma_xdr_encode_reply_array(struct rpcrdma_write_array *ary,
int chunks)
{
ary->wc_discrim = xdr_one;
ary->wc_nchunks = htonl(chunks);
}
void svc_rdma_xdr_encode_array_chunk(struct rpcrdma_write_array *ary,
int chunk_no,
u32 rs_handle, u64 rs_offset,
u32 write_len)
{
struct rpcrdma_segment *seg = &ary->wc_array[chunk_no].wc_target;
seg->rs_handle = htonl(rs_handle);
seg->rs_length = htonl(write_len);
xdr_encode_hyper((u32 *) &seg->rs_offset, rs_offset);
}
void svc_rdma_xdr_encode_reply_header(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rdma_argp,
struct rpcrdma_msg *rdma_resp,
enum rpcrdma_proc rdma_type)
{
rdma_resp->rm_xid = htonl(rdma_argp->rm_xid);
rdma_resp->rm_vers = htonl(rdma_argp->rm_vers);
rdma_resp->rm_credit = htonl(xprt->sc_max_requests);
rdma_resp->rm_type = htonl(rdma_type);
rdma_resp->rm_body.rm_chunks[0] = xdr_zero;
rdma_resp->rm_body.rm_chunks[1] = xdr_zero;
rdma_resp->rm_body.rm_chunks[2] = xdr_zero;
}
