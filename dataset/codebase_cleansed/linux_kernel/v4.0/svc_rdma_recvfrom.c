static void rdma_build_arg_xdr(struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *ctxt,
u32 byte_count)
{
struct rpcrdma_msg *rmsgp;
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
rmsgp = (struct rpcrdma_msg *)rqstp->rq_arg.head[0].iov_base;
if (be32_to_cpu(rmsgp->rm_type) == RDMA_NOMSG)
rqstp->rq_arg.pages = &rqstp->rq_pages[0];
else
rqstp->rq_arg.pages = &rqstp->rq_pages[1];
sge_no = 1;
while (bc && sge_no < ctxt->count) {
page = ctxt->pages[sge_no];
put_page(rqstp->rq_pages[sge_no]);
rqstp->rq_pages[sge_no] = page;
bc -= min_t(u32, bc, ctxt->sge[sge_no].length);
rqstp->rq_arg.buflen += ctxt->sge[sge_no].length;
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
static int rdma_read_max_sge(struct svcxprt_rdma *xprt, int sge_count)
{
if (rdma_node_get_transport(xprt->sc_cm_id->device->node_type) ==
RDMA_TRANSPORT_IWARP)
return 1;
else
return min_t(int, sge_count, xprt->sc_max_sge);
}
int rdma_read_chunk_lcl(struct svcxprt_rdma *xprt,
struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head,
int *page_no,
u32 *page_offset,
u32 rs_handle,
u32 rs_length,
u64 rs_offset,
bool last)
{
struct ib_send_wr read_wr;
int pages_needed = PAGE_ALIGN(*page_offset + rs_length) >> PAGE_SHIFT;
struct svc_rdma_op_ctxt *ctxt = svc_rdma_get_context(xprt);
int ret, read, pno;
u32 pg_off = *page_offset;
u32 pg_no = *page_no;
ctxt->direction = DMA_FROM_DEVICE;
ctxt->read_hdr = head;
pages_needed =
min_t(int, pages_needed, rdma_read_max_sge(xprt, pages_needed));
read = min_t(int, pages_needed << PAGE_SHIFT, rs_length);
for (pno = 0; pno < pages_needed; pno++) {
int len = min_t(int, rs_length, PAGE_SIZE - pg_off);
head->arg.pages[pg_no] = rqstp->rq_arg.pages[pg_no];
head->arg.page_len += len;
head->arg.len += len;
if (!pg_off)
head->count++;
rqstp->rq_respages = &rqstp->rq_arg.pages[pg_no+1];
rqstp->rq_next_page = rqstp->rq_respages + 1;
ctxt->sge[pno].addr =
ib_dma_map_page(xprt->sc_cm_id->device,
head->arg.pages[pg_no], pg_off,
PAGE_SIZE - pg_off,
DMA_FROM_DEVICE);
ret = ib_dma_mapping_error(xprt->sc_cm_id->device,
ctxt->sge[pno].addr);
if (ret)
goto err;
atomic_inc(&xprt->sc_dma_used);
ctxt->sge[pno].lkey = xprt->sc_dma_lkey;
ctxt->sge[pno].length = len;
ctxt->count++;
pg_off += len;
if (pg_off == PAGE_SIZE) {
pg_off = 0;
pg_no++;
}
rs_length -= len;
}
if (last && rs_length == 0)
set_bit(RDMACTXT_F_LAST_CTXT, &ctxt->flags);
else
clear_bit(RDMACTXT_F_LAST_CTXT, &ctxt->flags);
memset(&read_wr, 0, sizeof(read_wr));
read_wr.wr_id = (unsigned long)ctxt;
read_wr.opcode = IB_WR_RDMA_READ;
ctxt->wr_op = read_wr.opcode;
read_wr.send_flags = IB_SEND_SIGNALED;
read_wr.wr.rdma.rkey = rs_handle;
read_wr.wr.rdma.remote_addr = rs_offset;
read_wr.sg_list = ctxt->sge;
read_wr.num_sge = pages_needed;
ret = svc_rdma_send(xprt, &read_wr);
if (ret) {
pr_err("svcrdma: Error %d posting RDMA_READ\n", ret);
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
goto err;
}
*page_no = pg_no;
*page_offset = pg_off;
ret = read;
atomic_inc(&rdma_stat_read);
return ret;
err:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 0);
return ret;
}
int rdma_read_chunk_frmr(struct svcxprt_rdma *xprt,
struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head,
int *page_no,
u32 *page_offset,
u32 rs_handle,
u32 rs_length,
u64 rs_offset,
bool last)
{
struct ib_send_wr read_wr;
struct ib_send_wr inv_wr;
struct ib_send_wr fastreg_wr;
u8 key;
int pages_needed = PAGE_ALIGN(*page_offset + rs_length) >> PAGE_SHIFT;
struct svc_rdma_op_ctxt *ctxt = svc_rdma_get_context(xprt);
struct svc_rdma_fastreg_mr *frmr = svc_rdma_get_frmr(xprt);
int ret, read, pno;
u32 pg_off = *page_offset;
u32 pg_no = *page_no;
if (IS_ERR(frmr))
return -ENOMEM;
ctxt->direction = DMA_FROM_DEVICE;
ctxt->frmr = frmr;
pages_needed = min_t(int, pages_needed, xprt->sc_frmr_pg_list_len);
read = min_t(int, pages_needed << PAGE_SHIFT, rs_length);
frmr->kva = page_address(rqstp->rq_arg.pages[pg_no]);
frmr->direction = DMA_FROM_DEVICE;
frmr->access_flags = (IB_ACCESS_LOCAL_WRITE|IB_ACCESS_REMOTE_WRITE);
frmr->map_len = pages_needed << PAGE_SHIFT;
frmr->page_list_len = pages_needed;
for (pno = 0; pno < pages_needed; pno++) {
int len = min_t(int, rs_length, PAGE_SIZE - pg_off);
head->arg.pages[pg_no] = rqstp->rq_arg.pages[pg_no];
head->arg.page_len += len;
head->arg.len += len;
if (!pg_off)
head->count++;
rqstp->rq_respages = &rqstp->rq_arg.pages[pg_no+1];
rqstp->rq_next_page = rqstp->rq_respages + 1;
frmr->page_list->page_list[pno] =
ib_dma_map_page(xprt->sc_cm_id->device,
head->arg.pages[pg_no], 0,
PAGE_SIZE, DMA_FROM_DEVICE);
ret = ib_dma_mapping_error(xprt->sc_cm_id->device,
frmr->page_list->page_list[pno]);
if (ret)
goto err;
atomic_inc(&xprt->sc_dma_used);
pg_off += len;
if (pg_off == PAGE_SIZE) {
pg_off = 0;
pg_no++;
}
rs_length -= len;
}
if (last && rs_length == 0)
set_bit(RDMACTXT_F_LAST_CTXT, &ctxt->flags);
else
clear_bit(RDMACTXT_F_LAST_CTXT, &ctxt->flags);
key = (u8)(frmr->mr->lkey & 0x000000FF);
ib_update_fast_reg_key(frmr->mr, ++key);
ctxt->sge[0].addr = (unsigned long)frmr->kva + *page_offset;
ctxt->sge[0].lkey = frmr->mr->lkey;
ctxt->sge[0].length = read;
ctxt->count = 1;
ctxt->read_hdr = head;
memset(&fastreg_wr, 0, sizeof(fastreg_wr));
fastreg_wr.opcode = IB_WR_FAST_REG_MR;
fastreg_wr.send_flags = IB_SEND_SIGNALED;
fastreg_wr.wr.fast_reg.iova_start = (unsigned long)frmr->kva;
fastreg_wr.wr.fast_reg.page_list = frmr->page_list;
fastreg_wr.wr.fast_reg.page_list_len = frmr->page_list_len;
fastreg_wr.wr.fast_reg.page_shift = PAGE_SHIFT;
fastreg_wr.wr.fast_reg.length = frmr->map_len;
fastreg_wr.wr.fast_reg.access_flags = frmr->access_flags;
fastreg_wr.wr.fast_reg.rkey = frmr->mr->lkey;
fastreg_wr.next = &read_wr;
memset(&read_wr, 0, sizeof(read_wr));
read_wr.send_flags = IB_SEND_SIGNALED;
read_wr.wr.rdma.rkey = rs_handle;
read_wr.wr.rdma.remote_addr = rs_offset;
read_wr.sg_list = ctxt->sge;
read_wr.num_sge = 1;
if (xprt->sc_dev_caps & SVCRDMA_DEVCAP_READ_W_INV) {
read_wr.opcode = IB_WR_RDMA_READ_WITH_INV;
read_wr.wr_id = (unsigned long)ctxt;
read_wr.ex.invalidate_rkey = ctxt->frmr->mr->lkey;
} else {
read_wr.opcode = IB_WR_RDMA_READ;
read_wr.next = &inv_wr;
memset(&inv_wr, 0, sizeof(inv_wr));
inv_wr.wr_id = (unsigned long)ctxt;
inv_wr.opcode = IB_WR_LOCAL_INV;
inv_wr.send_flags = IB_SEND_SIGNALED | IB_SEND_FENCE;
inv_wr.ex.invalidate_rkey = frmr->mr->lkey;
}
ctxt->wr_op = read_wr.opcode;
ret = svc_rdma_send(xprt, &fastreg_wr);
if (ret) {
pr_err("svcrdma: Error %d posting RDMA_READ\n", ret);
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
goto err;
}
*page_no = pg_no;
*page_offset = pg_off;
ret = read;
atomic_inc(&rdma_stat_read);
return ret;
err:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 0);
svc_rdma_put_frmr(xprt, frmr);
return ret;
}
static unsigned int
rdma_rcl_chunk_count(struct rpcrdma_read_chunk *ch)
{
unsigned int count;
for (count = 0; ch->rc_discrim != xdr_zero; ch++)
count++;
return count;
}
static int
rdma_copy_tail(struct svc_rqst *rqstp, struct svc_rdma_op_ctxt *head,
u32 position, u32 byte_count, u32 page_offset, int page_no)
{
char *srcp, *destp;
int ret;
ret = 0;
srcp = head->arg.head[0].iov_base + position;
byte_count = head->arg.head[0].iov_len - position;
if (byte_count > PAGE_SIZE) {
dprintk("svcrdma: large tail unsupported\n");
return 0;
}
if (page_offset != PAGE_SIZE) {
destp = page_address(rqstp->rq_arg.pages[page_no]);
destp += page_offset;
while (byte_count--) {
*destp++ = *srcp++;
page_offset++;
if (page_offset == PAGE_SIZE && byte_count)
goto more;
}
goto done;
}
more:
page_no++;
destp = page_address(rqstp->rq_arg.pages[page_no]);
while (byte_count--)
*destp++ = *srcp++;
rqstp->rq_respages = &rqstp->rq_arg.pages[page_no+1];
rqstp->rq_next_page = rqstp->rq_respages + 1;
done:
byte_count = head->arg.head[0].iov_len - position;
head->arg.page_len += byte_count;
head->arg.len += byte_count;
head->arg.buflen += byte_count;
return 1;
}
static int rdma_read_chunks(struct svcxprt_rdma *xprt,
struct rpcrdma_msg *rmsgp,
struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head)
{
int page_no, ret;
struct rpcrdma_read_chunk *ch;
u32 handle, page_offset, byte_count;
u32 position;
u64 rs_offset;
bool last;
ch = svc_rdma_get_read_chunk(rmsgp);
if (!ch)
return 0;
if (rdma_rcl_chunk_count(ch) > RPCSVC_MAXPAGES)
return -EINVAL;
head->arg.head[0] = rqstp->rq_arg.head[0];
head->arg.tail[0] = rqstp->rq_arg.tail[0];
head->hdr_count = head->count;
head->arg.page_base = 0;
head->arg.page_len = 0;
head->arg.len = rqstp->rq_arg.len;
head->arg.buflen = rqstp->rq_arg.buflen;
ch = (struct rpcrdma_read_chunk *)&rmsgp->rm_body.rm_chunks[0];
position = be32_to_cpu(ch->rc_position);
if (position == 0) {
head->arg.pages = &head->pages[0];
page_offset = head->byte_len;
} else {
head->arg.pages = &head->pages[head->count];
page_offset = 0;
}
ret = 0;
page_no = 0;
for (; ch->rc_discrim != xdr_zero; ch++) {
if (be32_to_cpu(ch->rc_position) != position)
goto err;
handle = be32_to_cpu(ch->rc_target.rs_handle),
byte_count = be32_to_cpu(ch->rc_target.rs_length);
xdr_decode_hyper((__be32 *)&ch->rc_target.rs_offset,
&rs_offset);
while (byte_count > 0) {
last = (ch + 1)->rc_discrim == xdr_zero;
ret = xprt->sc_reader(xprt, rqstp, head,
&page_no, &page_offset,
handle, byte_count,
rs_offset, last);
if (ret < 0)
goto err;
byte_count -= ret;
rs_offset += ret;
head->arg.buflen += ret;
}
}
if (page_offset & 3) {
u32 pad = 4 - (page_offset & 3);
head->arg.page_len += pad;
head->arg.len += pad;
head->arg.buflen += pad;
page_offset += pad;
}
ret = 1;
if (position && position < head->arg.head[0].iov_len)
ret = rdma_copy_tail(rqstp, head, position,
byte_count, page_offset, page_no);
head->arg.head[0].iov_len = position;
head->position = position;
err:
for (page_no = 0;
&rqstp->rq_pages[page_no] < rqstp->rq_respages; page_no++)
rqstp->rq_pages[page_no] = NULL;
return ret;
}
static int rdma_read_complete(struct svc_rqst *rqstp,
struct svc_rdma_op_ctxt *head)
{
int page_no;
int ret;
for (page_no = 0; page_no < head->count; page_no++) {
put_page(rqstp->rq_pages[page_no]);
rqstp->rq_pages[page_no] = head->pages[page_no];
}
if (head->position == 0) {
if (head->arg.len <= head->sge[0].length) {
head->arg.head[0].iov_len = head->arg.len -
head->byte_len;
head->arg.page_len = 0;
} else {
head->arg.head[0].iov_len = head->sge[0].length -
head->byte_len;
head->arg.page_len = head->arg.len -
head->sge[0].length;
}
}
rqstp->rq_arg.pages = &rqstp->rq_pages[head->hdr_count];
rqstp->rq_arg.page_len = head->arg.page_len;
rqstp->rq_arg.page_base = head->arg.page_base;
rqstp->rq_respages = &rqstp->rq_arg.pages[page_no];
rqstp->rq_next_page = rqstp->rq_respages + 1;
rqstp->rq_arg.head[0] = head->arg.head[0];
rqstp->rq_arg.tail[0] = head->arg.tail[0];
rqstp->rq_arg.len = head->arg.len;
rqstp->rq_arg.buflen = head->arg.buflen;
svc_rdma_put_context(head, 0);
rqstp->rq_prot = IPPROTO_MAX;
svc_xprt_copy_addrs(rqstp, rqstp->rq_xprt);
ret = rqstp->rq_arg.head[0].iov_len
+ rqstp->rq_arg.page_len
+ rqstp->rq_arg.tail[0].iov_len;
dprintk("svcrdma: deferred read ret=%d, rq_arg.len=%u, "
"rq_arg.head[0].iov_base=%p, rq_arg.head[0].iov_len=%zu\n",
ret, rqstp->rq_arg.len, rqstp->rq_arg.head[0].iov_base,
rqstp->rq_arg.head[0].iov_len);
return ret;
}
int svc_rdma_recvfrom(struct svc_rqst *rqstp)
{
struct svc_xprt *xprt = rqstp->rq_xprt;
struct svcxprt_rdma *rdma_xprt =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
struct svc_rdma_op_ctxt *ctxt = NULL;
struct rpcrdma_msg *rmsgp;
int ret = 0;
int len;
dprintk("svcrdma: rqstp=%p\n", rqstp);
spin_lock_bh(&rdma_xprt->sc_rq_dto_lock);
if (!list_empty(&rdma_xprt->sc_read_complete_q)) {
ctxt = list_entry(rdma_xprt->sc_read_complete_q.next,
struct svc_rdma_op_ctxt,
dto_q);
list_del_init(&ctxt->dto_q);
spin_unlock_bh(&rdma_xprt->sc_rq_dto_lock);
return rdma_read_complete(rqstp, ctxt);
} else if (!list_empty(&rdma_xprt->sc_rq_dto_q)) {
ctxt = list_entry(rdma_xprt->sc_rq_dto_q.next,
struct svc_rdma_op_ctxt,
dto_q);
list_del_init(&ctxt->dto_q);
} else {
atomic_inc(&rdma_stat_rq_starve);
clear_bit(XPT_DATA, &xprt->xpt_flags);
ctxt = NULL;
}
spin_unlock_bh(&rdma_xprt->sc_rq_dto_lock);
if (!ctxt) {
if (test_bit(XPT_CLOSE, &xprt->xpt_flags))
goto close_out;
goto out;
}
dprintk("svcrdma: processing ctxt=%p on xprt=%p, rqstp=%p, status=%d\n",
ctxt, rdma_xprt, rqstp, ctxt->wc_status);
atomic_inc(&rdma_stat_recv);
rdma_build_arg_xdr(rqstp, ctxt, ctxt->byte_len);
len = svc_rdma_xdr_decode_req(&rmsgp, rqstp);
rqstp->rq_xprt_hlen = len;
if (len < 0) {
if (len == -ENOSYS)
svc_rdma_send_error(rdma_xprt, rmsgp, ERR_VERS);
goto close_out;
}
ret = rdma_read_chunks(rdma_xprt, rmsgp, rqstp, ctxt);
if (ret > 0) {
goto defer;
} else if (ret < 0) {
svc_rdma_put_context(ctxt, 1);
return 0;
}
ret = rqstp->rq_arg.head[0].iov_len
+ rqstp->rq_arg.page_len
+ rqstp->rq_arg.tail[0].iov_len;
svc_rdma_put_context(ctxt, 0);
out:
dprintk("svcrdma: ret=%d, rq_arg.len=%u, "
"rq_arg.head[0].iov_base=%p, rq_arg.head[0].iov_len=%zd\n",
ret, rqstp->rq_arg.len,
rqstp->rq_arg.head[0].iov_base,
rqstp->rq_arg.head[0].iov_len);
rqstp->rq_prot = IPPROTO_MAX;
svc_xprt_copy_addrs(rqstp, xprt);
return ret;
close_out:
if (ctxt)
svc_rdma_put_context(ctxt, 1);
dprintk("svcrdma: transport %p is closing\n", xprt);
set_bit(XPT_CLOSE, &xprt->xpt_flags);
defer:
return 0;
}
