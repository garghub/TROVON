static void rds_iw_send_rdma_complete(struct rds_message *rm,
int wc_status)
{
int notify_status;
switch (wc_status) {
case IB_WC_WR_FLUSH_ERR:
return;
case IB_WC_SUCCESS:
notify_status = RDS_RDMA_SUCCESS;
break;
case IB_WC_REM_ACCESS_ERR:
notify_status = RDS_RDMA_REMOTE_ERROR;
break;
default:
notify_status = RDS_RDMA_OTHER_ERROR;
break;
}
rds_rdma_send_complete(rm, notify_status);
}
static void rds_iw_send_unmap_rdma(struct rds_iw_connection *ic,
struct rm_rdma_op *op)
{
if (op->op_mapped) {
ib_dma_unmap_sg(ic->i_cm_id->device,
op->op_sg, op->op_nents,
op->op_write ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
op->op_mapped = 0;
}
}
static void rds_iw_send_unmap_rm(struct rds_iw_connection *ic,
struct rds_iw_send_work *send,
int wc_status)
{
struct rds_message *rm = send->s_rm;
rdsdebug("ic %p send %p rm %p\n", ic, send, rm);
ib_dma_unmap_sg(ic->i_cm_id->device,
rm->data.op_sg, rm->data.op_nents,
DMA_TO_DEVICE);
if (rm->rdma.op_active) {
rds_iw_send_unmap_rdma(ic, &rm->rdma);
rds_iw_send_rdma_complete(rm, wc_status);
if (rm->rdma.op_write)
rds_stats_add(s_send_rdma_bytes, rm->rdma.op_bytes);
else
rds_stats_add(s_recv_rdma_bytes, rm->rdma.op_bytes);
}
rds_message_unmapped(rm);
rds_message_put(rm);
send->s_rm = NULL;
}
void rds_iw_send_init_ring(struct rds_iw_connection *ic)
{
struct rds_iw_send_work *send;
u32 i;
for (i = 0, send = ic->i_sends; i < ic->i_send_ring.w_nr; i++, send++) {
struct ib_sge *sge;
send->s_rm = NULL;
send->s_op = NULL;
send->s_mapping = NULL;
send->s_wr.next = NULL;
send->s_wr.wr_id = i;
send->s_wr.sg_list = send->s_sge;
send->s_wr.num_sge = 1;
send->s_wr.opcode = IB_WR_SEND;
send->s_wr.send_flags = 0;
send->s_wr.ex.imm_data = 0;
sge = rds_iw_data_sge(ic, send->s_sge);
sge->lkey = 0;
sge = rds_iw_header_sge(ic, send->s_sge);
sge->addr = ic->i_send_hdrs_dma + (i * sizeof(struct rds_header));
sge->length = sizeof(struct rds_header);
sge->lkey = 0;
send->s_mr = ib_alloc_fast_reg_mr(ic->i_pd, fastreg_message_size);
if (IS_ERR(send->s_mr)) {
printk(KERN_WARNING "RDS/IW: ib_alloc_fast_reg_mr failed\n");
break;
}
send->s_page_list = ib_alloc_fast_reg_page_list(
ic->i_cm_id->device, fastreg_message_size);
if (IS_ERR(send->s_page_list)) {
printk(KERN_WARNING "RDS/IW: ib_alloc_fast_reg_page_list failed\n");
break;
}
}
}
void rds_iw_send_clear_ring(struct rds_iw_connection *ic)
{
struct rds_iw_send_work *send;
u32 i;
for (i = 0, send = ic->i_sends; i < ic->i_send_ring.w_nr; i++, send++) {
BUG_ON(!send->s_mr);
ib_dereg_mr(send->s_mr);
BUG_ON(!send->s_page_list);
ib_free_fast_reg_page_list(send->s_page_list);
if (send->s_wr.opcode == 0xdead)
continue;
if (send->s_rm)
rds_iw_send_unmap_rm(ic, send, IB_WC_WR_FLUSH_ERR);
if (send->s_op)
rds_iw_send_unmap_rdma(ic, send->s_op);
}
}
void rds_iw_send_cq_comp_handler(struct ib_cq *cq, void *context)
{
struct rds_connection *conn = context;
struct rds_iw_connection *ic = conn->c_transport_data;
struct ib_wc wc;
struct rds_iw_send_work *send;
u32 completed;
u32 oldest;
u32 i;
int ret;
rdsdebug("cq %p conn %p\n", cq, conn);
rds_iw_stats_inc(s_iw_tx_cq_call);
ret = ib_req_notify_cq(cq, IB_CQ_NEXT_COMP);
if (ret)
rdsdebug("ib_req_notify_cq send failed: %d\n", ret);
while (ib_poll_cq(cq, 1, &wc) > 0) {
rdsdebug("wc wr_id 0x%llx status %u byte_len %u imm_data %u\n",
(unsigned long long)wc.wr_id, wc.status, wc.byte_len,
be32_to_cpu(wc.ex.imm_data));
rds_iw_stats_inc(s_iw_tx_cq_event);
if (wc.status != IB_WC_SUCCESS) {
printk(KERN_ERR "WC Error: status = %d opcode = %d\n", wc.status, wc.opcode);
break;
}
if (wc.opcode == IB_WC_LOCAL_INV && wc.wr_id == RDS_IW_LOCAL_INV_WR_ID) {
ic->i_fastreg_posted = 0;
continue;
}
if (wc.opcode == IB_WC_FAST_REG_MR && wc.wr_id == RDS_IW_FAST_REG_WR_ID) {
ic->i_fastreg_posted = 1;
continue;
}
if (wc.wr_id == RDS_IW_ACK_WR_ID) {
if (time_after(jiffies, ic->i_ack_queued + HZ/2))
rds_iw_stats_inc(s_iw_tx_stalled);
rds_iw_ack_send_complete(ic);
continue;
}
oldest = rds_iw_ring_oldest(&ic->i_send_ring);
completed = rds_iw_ring_completed(&ic->i_send_ring, wc.wr_id, oldest);
for (i = 0; i < completed; i++) {
send = &ic->i_sends[oldest];
switch (send->s_wr.opcode) {
case IB_WR_SEND:
if (send->s_rm)
rds_iw_send_unmap_rm(ic, send, wc.status);
break;
case IB_WR_FAST_REG_MR:
case IB_WR_RDMA_WRITE:
case IB_WR_RDMA_READ:
case IB_WR_RDMA_READ_WITH_INV:
break;
default:
printk_ratelimited(KERN_NOTICE
"RDS/IW: %s: unexpected opcode 0x%x in WR!\n",
__func__, send->s_wr.opcode);
break;
}
send->s_wr.opcode = 0xdead;
send->s_wr.num_sge = 1;
if (time_after(jiffies, send->s_queued + HZ/2))
rds_iw_stats_inc(s_iw_tx_stalled);
if (unlikely(wc.status == IB_WC_REM_ACCESS_ERR && send->s_op)) {
struct rds_message *rm;
rm = rds_send_get_message(conn, send->s_op);
if (rm)
rds_iw_send_rdma_complete(rm, wc.status);
}
oldest = (oldest + 1) % ic->i_send_ring.w_nr;
}
rds_iw_ring_free(&ic->i_send_ring, completed);
if (test_and_clear_bit(RDS_LL_SEND_FULL, &conn->c_flags) ||
test_bit(0, &conn->c_map_queued))
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
if (wc.status != IB_WC_SUCCESS && rds_conn_up(conn)) {
rds_iw_conn_error(conn,
"send completion on %pI4 "
"had status %u, disconnecting and reconnecting\n",
&conn->c_faddr, wc.status);
}
}
}
int rds_iw_send_grab_credits(struct rds_iw_connection *ic,
u32 wanted, u32 *adv_credits, int need_posted, int max_posted)
{
unsigned int avail, posted, got = 0, advertise;
long oldval, newval;
*adv_credits = 0;
if (!ic->i_flowctl)
return wanted;
try_again:
advertise = 0;
oldval = newval = atomic_read(&ic->i_credits);
posted = IB_GET_POST_CREDITS(oldval);
avail = IB_GET_SEND_CREDITS(oldval);
rdsdebug("rds_iw_send_grab_credits(%u): credits=%u posted=%u\n",
wanted, avail, posted);
if (avail && !posted)
avail--;
if (avail < wanted) {
struct rds_connection *conn = ic->i_cm_id->context;
set_bit(RDS_LL_SEND_FULL, &conn->c_flags);
got = avail;
} else {
got = wanted;
}
newval -= IB_SET_SEND_CREDITS(got);
if (posted && (got || need_posted)) {
advertise = min_t(unsigned int, posted, max_posted);
newval -= IB_SET_POST_CREDITS(advertise);
}
if (atomic_cmpxchg(&ic->i_credits, oldval, newval) != oldval)
goto try_again;
*adv_credits = advertise;
return got;
}
void rds_iw_send_add_credits(struct rds_connection *conn, unsigned int credits)
{
struct rds_iw_connection *ic = conn->c_transport_data;
if (credits == 0)
return;
rdsdebug("rds_iw_send_add_credits(%u): current=%u%s\n",
credits,
IB_GET_SEND_CREDITS(atomic_read(&ic->i_credits)),
test_bit(RDS_LL_SEND_FULL, &conn->c_flags) ? ", ll_send_full" : "");
atomic_add(IB_SET_SEND_CREDITS(credits), &ic->i_credits);
if (test_and_clear_bit(RDS_LL_SEND_FULL, &conn->c_flags))
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
WARN_ON(IB_GET_SEND_CREDITS(credits) >= 16384);
rds_iw_stats_inc(s_iw_rx_credit_updates);
}
void rds_iw_advertise_credits(struct rds_connection *conn, unsigned int posted)
{
struct rds_iw_connection *ic = conn->c_transport_data;
if (posted == 0)
return;
atomic_add(IB_SET_POST_CREDITS(posted), &ic->i_credits);
if (IB_GET_POST_CREDITS(atomic_read(&ic->i_credits)) >= 16)
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
}
static inline void
rds_iw_xmit_populate_wr(struct rds_iw_connection *ic,
struct rds_iw_send_work *send, unsigned int pos,
unsigned long buffer, unsigned int length,
int send_flags)
{
struct ib_sge *sge;
WARN_ON(pos != send - ic->i_sends);
send->s_wr.send_flags = send_flags;
send->s_wr.opcode = IB_WR_SEND;
send->s_wr.num_sge = 2;
send->s_wr.next = NULL;
send->s_queued = jiffies;
send->s_op = NULL;
if (length != 0) {
sge = rds_iw_data_sge(ic, send->s_sge);
sge->addr = buffer;
sge->length = length;
sge->lkey = rds_iw_local_dma_lkey(ic);
sge = rds_iw_header_sge(ic, send->s_sge);
} else {
send->s_wr.num_sge = 1;
sge = &send->s_sge[0];
}
sge->addr = ic->i_send_hdrs_dma + (pos * sizeof(struct rds_header));
sge->length = sizeof(struct rds_header);
sge->lkey = rds_iw_local_dma_lkey(ic);
}
int rds_iw_xmit(struct rds_connection *conn, struct rds_message *rm,
unsigned int hdr_off, unsigned int sg, unsigned int off)
{
struct rds_iw_connection *ic = conn->c_transport_data;
struct ib_device *dev = ic->i_cm_id->device;
struct rds_iw_send_work *send = NULL;
struct rds_iw_send_work *first;
struct rds_iw_send_work *prev;
struct ib_send_wr *failed_wr;
struct scatterlist *scat;
u32 pos;
u32 i;
u32 work_alloc;
u32 credit_alloc;
u32 posted;
u32 adv_credits = 0;
int send_flags = 0;
int sent;
int ret;
int flow_controlled = 0;
BUG_ON(off % RDS_FRAG_SIZE);
BUG_ON(hdr_off != 0 && hdr_off != sizeof(struct rds_header));
if (rds_rdma_cookie_key(rm->m_rdma_cookie) && !ic->i_fastreg_posted) {
ret = -EAGAIN;
goto out;
}
if (be32_to_cpu(rm->m_inc.i_hdr.h_len) == 0)
i = 1;
else
i = ceil(be32_to_cpu(rm->m_inc.i_hdr.h_len), RDS_FRAG_SIZE);
work_alloc = rds_iw_ring_alloc(&ic->i_send_ring, i, &pos);
if (work_alloc == 0) {
set_bit(RDS_LL_SEND_FULL, &conn->c_flags);
rds_iw_stats_inc(s_iw_tx_ring_full);
ret = -ENOMEM;
goto out;
}
credit_alloc = work_alloc;
if (ic->i_flowctl) {
credit_alloc = rds_iw_send_grab_credits(ic, work_alloc, &posted, 0, RDS_MAX_ADV_CREDIT);
adv_credits += posted;
if (credit_alloc < work_alloc) {
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc - credit_alloc);
work_alloc = credit_alloc;
flow_controlled++;
}
if (work_alloc == 0) {
set_bit(RDS_LL_SEND_FULL, &conn->c_flags);
rds_iw_stats_inc(s_iw_tx_throttle);
ret = -ENOMEM;
goto out;
}
}
if (!ic->i_rm) {
if (rm->data.op_nents) {
rm->data.op_count = ib_dma_map_sg(dev,
rm->data.op_sg,
rm->data.op_nents,
DMA_TO_DEVICE);
rdsdebug("ic %p mapping rm %p: %d\n", ic, rm, rm->data.op_count);
if (rm->data.op_count == 0) {
rds_iw_stats_inc(s_iw_tx_sg_mapping_failure);
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc);
ret = -ENOMEM;
goto out;
}
} else {
rm->data.op_count = 0;
}
ic->i_unsignaled_wrs = rds_iw_sysctl_max_unsig_wrs;
ic->i_unsignaled_bytes = rds_iw_sysctl_max_unsig_bytes;
rds_message_addref(rm);
ic->i_rm = rm;
if (test_bit(RDS_MSG_ACK_REQUIRED, &rm->m_flags))
rm->m_inc.i_hdr.h_flags |= RDS_FLAG_ACK_REQUIRED;
if (test_bit(RDS_MSG_RETRANSMITTED, &rm->m_flags))
rm->m_inc.i_hdr.h_flags |= RDS_FLAG_RETRANSMITTED;
if (rm->rdma.op_active) {
struct rds_ext_header_rdma ext_hdr;
ext_hdr.h_rdma_rkey = cpu_to_be32(rm->rdma.op_rkey);
rds_message_add_extension(&rm->m_inc.i_hdr,
RDS_EXTHDR_RDMA, &ext_hdr, sizeof(ext_hdr));
}
if (rm->m_rdma_cookie) {
rds_message_add_rdma_dest_extension(&rm->m_inc.i_hdr,
rds_rdma_cookie_key(rm->m_rdma_cookie),
rds_rdma_cookie_offset(rm->m_rdma_cookie));
}
rm->m_inc.i_hdr.h_ack = cpu_to_be64(rds_iw_piggyb_ack(ic));
rds_message_make_checksum(&rm->m_inc.i_hdr);
rds_iw_send_grab_credits(ic, 0, &posted, 1, RDS_MAX_ADV_CREDIT - adv_credits);
adv_credits += posted;
BUG_ON(adv_credits > 255);
}
send = &ic->i_sends[pos];
first = send;
prev = NULL;
scat = &rm->data.op_sg[sg];
sent = 0;
i = 0;
if (rm->rdma.op_active && rm->rdma.op_fence)
send_flags = IB_SEND_FENCE;
if (be32_to_cpu(rm->m_inc.i_hdr.h_len) == 0) {
rds_iw_xmit_populate_wr(ic, send, pos, 0, 0, send_flags);
goto add_header;
}
for (; i < work_alloc && scat != &rm->data.op_sg[rm->data.op_count]; i++) {
unsigned int len;
send = &ic->i_sends[pos];
len = min(RDS_FRAG_SIZE, ib_sg_dma_len(dev, scat) - off);
rds_iw_xmit_populate_wr(ic, send, pos,
ib_sg_dma_address(dev, scat) + off, len,
send_flags);
if (ic->i_unsignaled_wrs-- == 0) {
ic->i_unsignaled_wrs = rds_iw_sysctl_max_unsig_wrs;
send->s_wr.send_flags |= IB_SEND_SIGNALED | IB_SEND_SOLICITED;
}
ic->i_unsignaled_bytes -= len;
if (ic->i_unsignaled_bytes <= 0) {
ic->i_unsignaled_bytes = rds_iw_sysctl_max_unsig_bytes;
send->s_wr.send_flags |= IB_SEND_SIGNALED | IB_SEND_SOLICITED;
}
if (flow_controlled && i == (work_alloc-1))
send->s_wr.send_flags |= IB_SEND_SIGNALED | IB_SEND_SOLICITED;
rdsdebug("send %p wr %p num_sge %u next %p\n", send,
&send->s_wr, send->s_wr.num_sge, send->s_wr.next);
sent += len;
off += len;
if (off == ib_sg_dma_len(dev, scat)) {
scat++;
off = 0;
}
add_header:
memcpy(&ic->i_send_hdrs[pos], &rm->m_inc.i_hdr, sizeof(struct rds_header));
if (0) {
struct rds_header *hdr = &ic->i_send_hdrs[pos];
printk(KERN_NOTICE "send WR dport=%u flags=0x%x len=%d\n",
be16_to_cpu(hdr->h_dport),
hdr->h_flags,
be32_to_cpu(hdr->h_len));
}
if (adv_credits) {
struct rds_header *hdr = &ic->i_send_hdrs[pos];
hdr->h_credit = adv_credits;
rds_message_make_checksum(hdr);
adv_credits = 0;
rds_iw_stats_inc(s_iw_tx_credit_updates);
}
if (prev)
prev->s_wr.next = &send->s_wr;
prev = send;
pos = (pos + 1) % ic->i_send_ring.w_nr;
}
if (hdr_off == 0)
sent += sizeof(struct rds_header);
if (scat == &rm->data.op_sg[rm->data.op_count]) {
prev->s_rm = ic->i_rm;
prev->s_wr.send_flags |= IB_SEND_SIGNALED | IB_SEND_SOLICITED;
ic->i_rm = NULL;
}
if (i < work_alloc) {
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc - i);
work_alloc = i;
}
if (ic->i_flowctl && i < credit_alloc)
rds_iw_send_add_credits(conn, credit_alloc - i);
failed_wr = &first->s_wr;
ret = ib_post_send(ic->i_cm_id->qp, &first->s_wr, &failed_wr);
rdsdebug("ic %p first %p (wr %p) ret %d wr %p\n", ic,
first, &first->s_wr, ret, failed_wr);
BUG_ON(failed_wr != &first->s_wr);
if (ret) {
printk(KERN_WARNING "RDS/IW: ib_post_send to %pI4 "
"returned %d\n", &conn->c_faddr, ret);
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc);
if (prev->s_rm) {
ic->i_rm = prev->s_rm;
prev->s_rm = NULL;
}
goto out;
}
ret = sent;
out:
BUG_ON(adv_credits);
return ret;
}
static void rds_iw_build_send_fastreg(struct rds_iw_device *rds_iwdev, struct rds_iw_connection *ic, struct rds_iw_send_work *send, int nent, int len, u64 sg_addr)
{
BUG_ON(nent > send->s_page_list->max_page_list_len);
send->s_wr.opcode = IB_WR_FAST_REG_MR;
send->s_wr.wr.fast_reg.length = len;
send->s_wr.wr.fast_reg.rkey = send->s_mr->rkey;
send->s_wr.wr.fast_reg.page_list = send->s_page_list;
send->s_wr.wr.fast_reg.page_list_len = nent;
send->s_wr.wr.fast_reg.page_shift = PAGE_SHIFT;
send->s_wr.wr.fast_reg.access_flags = IB_ACCESS_REMOTE_WRITE;
send->s_wr.wr.fast_reg.iova_start = sg_addr;
ib_update_fast_reg_key(send->s_mr, send->s_remap_count++);
}
int rds_iw_xmit_rdma(struct rds_connection *conn, struct rm_rdma_op *op)
{
struct rds_iw_connection *ic = conn->c_transport_data;
struct rds_iw_send_work *send = NULL;
struct rds_iw_send_work *first;
struct rds_iw_send_work *prev;
struct ib_send_wr *failed_wr;
struct rds_iw_device *rds_iwdev;
struct scatterlist *scat;
unsigned long len;
u64 remote_addr = op->op_remote_addr;
u32 pos, fr_pos;
u32 work_alloc;
u32 i;
u32 j;
int sent;
int ret;
int num_sge;
rds_iwdev = ib_get_client_data(ic->i_cm_id->device, &rds_iw_client);
if (!op->op_mapped) {
op->op_count = ib_dma_map_sg(ic->i_cm_id->device,
op->op_sg, op->op_nents, (op->op_write) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE);
rdsdebug("ic %p mapping op %p: %d\n", ic, op, op->op_count);
if (op->op_count == 0) {
rds_iw_stats_inc(s_iw_tx_sg_mapping_failure);
ret = -ENOMEM;
goto out;
}
op->op_mapped = 1;
}
if (!op->op_write) {
work_alloc = rds_iw_ring_alloc(&ic->i_send_ring, 1, &fr_pos);
if (work_alloc != 1) {
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_iw_stats_inc(s_iw_tx_ring_full);
ret = -ENOMEM;
goto out;
}
}
i = ceil(op->op_count, rds_iwdev->max_sge);
work_alloc = rds_iw_ring_alloc(&ic->i_send_ring, i, &pos);
if (work_alloc != i) {
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_iw_stats_inc(s_iw_tx_ring_full);
ret = -ENOMEM;
goto out;
}
send = &ic->i_sends[pos];
if (!op->op_write) {
first = prev = &ic->i_sends[fr_pos];
} else {
first = send;
prev = NULL;
}
scat = &op->op_sg[0];
sent = 0;
num_sge = op->op_count;
for (i = 0; i < work_alloc && scat != &op->op_sg[op->op_count]; i++) {
send->s_wr.send_flags = 0;
send->s_queued = jiffies;
if (ic->i_unsignaled_wrs-- == 0) {
ic->i_unsignaled_wrs = rds_iw_sysctl_max_unsig_wrs;
send->s_wr.send_flags = IB_SEND_SIGNALED;
}
if (op->op_write)
send->s_wr.opcode = IB_WR_RDMA_WRITE;
else
send->s_wr.opcode = IB_WR_RDMA_READ_WITH_INV;
send->s_wr.wr.rdma.remote_addr = remote_addr;
send->s_wr.wr.rdma.rkey = op->op_rkey;
send->s_op = op;
if (num_sge > rds_iwdev->max_sge) {
send->s_wr.num_sge = rds_iwdev->max_sge;
num_sge -= rds_iwdev->max_sge;
} else
send->s_wr.num_sge = num_sge;
send->s_wr.next = NULL;
if (prev)
prev->s_wr.next = &send->s_wr;
for (j = 0; j < send->s_wr.num_sge && scat != &op->op_sg[op->op_count]; j++) {
len = ib_sg_dma_len(ic->i_cm_id->device, scat);
if (send->s_wr.opcode == IB_WR_RDMA_READ_WITH_INV)
send->s_page_list->page_list[j] = ib_sg_dma_address(ic->i_cm_id->device, scat);
else {
send->s_sge[j].addr = ib_sg_dma_address(ic->i_cm_id->device, scat);
send->s_sge[j].length = len;
send->s_sge[j].lkey = rds_iw_local_dma_lkey(ic);
}
sent += len;
rdsdebug("ic %p sent %d remote_addr %llu\n", ic, sent, remote_addr);
remote_addr += len;
scat++;
}
if (send->s_wr.opcode == IB_WR_RDMA_READ_WITH_INV) {
send->s_wr.num_sge = 1;
send->s_sge[0].addr = conn->c_xmit_rm->m_rs->rs_user_addr;
send->s_sge[0].length = conn->c_xmit_rm->m_rs->rs_user_bytes;
send->s_sge[0].lkey = ic->i_sends[fr_pos].s_mr->lkey;
}
rdsdebug("send %p wr %p num_sge %u next %p\n", send,
&send->s_wr, send->s_wr.num_sge, send->s_wr.next);
prev = send;
if (++send == &ic->i_sends[ic->i_send_ring.w_nr])
send = ic->i_sends;
}
if (scat == &op->op_sg[op->op_count])
first->s_wr.send_flags = IB_SEND_SIGNALED;
if (i < work_alloc) {
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc - i);
work_alloc = i;
}
if (!op->op_write) {
rds_iw_build_send_fastreg(rds_iwdev, ic, &ic->i_sends[fr_pos],
op->op_count, sent, conn->c_xmit_rm->m_rs->rs_user_addr);
work_alloc++;
}
failed_wr = &first->s_wr;
ret = ib_post_send(ic->i_cm_id->qp, &first->s_wr, &failed_wr);
rdsdebug("ic %p first %p (wr %p) ret %d wr %p\n", ic,
first, &first->s_wr, ret, failed_wr);
BUG_ON(failed_wr != &first->s_wr);
if (ret) {
printk(KERN_WARNING "RDS/IW: rdma ib_post_send to %pI4 "
"returned %d\n", &conn->c_faddr, ret);
rds_iw_ring_unalloc(&ic->i_send_ring, work_alloc);
goto out;
}
out:
return ret;
}
void rds_iw_xmit_complete(struct rds_connection *conn)
{
struct rds_iw_connection *ic = conn->c_transport_data;
rds_iw_attempt_ack(ic);
}
