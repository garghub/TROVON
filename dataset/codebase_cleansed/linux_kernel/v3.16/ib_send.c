char *rds_ib_wc_status_str(enum ib_wc_status status)
{
return rds_str_array(rds_ib_wc_status_strings,
ARRAY_SIZE(rds_ib_wc_status_strings), status);
}
static void rds_ib_send_complete(struct rds_message *rm,
int wc_status,
void (*complete)(struct rds_message *rm, int status))
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
complete(rm, notify_status);
}
static void rds_ib_send_unmap_data(struct rds_ib_connection *ic,
struct rm_data_op *op,
int wc_status)
{
if (op->op_nents)
ib_dma_unmap_sg(ic->i_cm_id->device,
op->op_sg, op->op_nents,
DMA_TO_DEVICE);
}
static void rds_ib_send_unmap_rdma(struct rds_ib_connection *ic,
struct rm_rdma_op *op,
int wc_status)
{
if (op->op_mapped) {
ib_dma_unmap_sg(ic->i_cm_id->device,
op->op_sg, op->op_nents,
op->op_write ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
op->op_mapped = 0;
}
rds_ib_send_complete(container_of(op, struct rds_message, rdma),
wc_status, rds_rdma_send_complete);
if (op->op_write)
rds_stats_add(s_send_rdma_bytes, op->op_bytes);
else
rds_stats_add(s_recv_rdma_bytes, op->op_bytes);
}
static void rds_ib_send_unmap_atomic(struct rds_ib_connection *ic,
struct rm_atomic_op *op,
int wc_status)
{
if (op->op_mapped) {
ib_dma_unmap_sg(ic->i_cm_id->device, op->op_sg, 1,
DMA_FROM_DEVICE);
op->op_mapped = 0;
}
rds_ib_send_complete(container_of(op, struct rds_message, atomic),
wc_status, rds_atomic_send_complete);
if (op->op_type == RDS_ATOMIC_TYPE_CSWP)
rds_ib_stats_inc(s_ib_atomic_cswp);
else
rds_ib_stats_inc(s_ib_atomic_fadd);
}
static struct rds_message *rds_ib_send_unmap_op(struct rds_ib_connection *ic,
struct rds_ib_send_work *send,
int wc_status)
{
struct rds_message *rm = NULL;
switch (send->s_wr.opcode) {
case IB_WR_SEND:
if (send->s_op) {
rm = container_of(send->s_op, struct rds_message, data);
rds_ib_send_unmap_data(ic, send->s_op, wc_status);
}
break;
case IB_WR_RDMA_WRITE:
case IB_WR_RDMA_READ:
if (send->s_op) {
rm = container_of(send->s_op, struct rds_message, rdma);
rds_ib_send_unmap_rdma(ic, send->s_op, wc_status);
}
break;
case IB_WR_ATOMIC_FETCH_AND_ADD:
case IB_WR_ATOMIC_CMP_AND_SWP:
if (send->s_op) {
rm = container_of(send->s_op, struct rds_message, atomic);
rds_ib_send_unmap_atomic(ic, send->s_op, wc_status);
}
break;
default:
printk_ratelimited(KERN_NOTICE
"RDS/IB: %s: unexpected opcode 0x%x in WR!\n",
__func__, send->s_wr.opcode);
break;
}
send->s_wr.opcode = 0xdead;
return rm;
}
void rds_ib_send_init_ring(struct rds_ib_connection *ic)
{
struct rds_ib_send_work *send;
u32 i;
for (i = 0, send = ic->i_sends; i < ic->i_send_ring.w_nr; i++, send++) {
struct ib_sge *sge;
send->s_op = NULL;
send->s_wr.wr_id = i;
send->s_wr.sg_list = send->s_sge;
send->s_wr.ex.imm_data = 0;
sge = &send->s_sge[0];
sge->addr = ic->i_send_hdrs_dma + (i * sizeof(struct rds_header));
sge->length = sizeof(struct rds_header);
sge->lkey = ic->i_mr->lkey;
send->s_sge[1].lkey = ic->i_mr->lkey;
}
}
void rds_ib_send_clear_ring(struct rds_ib_connection *ic)
{
struct rds_ib_send_work *send;
u32 i;
for (i = 0, send = ic->i_sends; i < ic->i_send_ring.w_nr; i++, send++) {
if (send->s_op && send->s_wr.opcode != 0xdead)
rds_ib_send_unmap_op(ic, send, IB_WC_WR_FLUSH_ERR);
}
}
static void rds_ib_sub_signaled(struct rds_ib_connection *ic, int nr)
{
if ((atomic_sub_return(nr, &ic->i_signaled_sends) == 0) &&
waitqueue_active(&rds_ib_ring_empty_wait))
wake_up(&rds_ib_ring_empty_wait);
BUG_ON(atomic_read(&ic->i_signaled_sends) < 0);
}
void rds_ib_send_cq_comp_handler(struct ib_cq *cq, void *context)
{
struct rds_connection *conn = context;
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_message *rm = NULL;
struct ib_wc wc;
struct rds_ib_send_work *send;
u32 completed;
u32 oldest;
u32 i = 0;
int ret;
int nr_sig = 0;
rdsdebug("cq %p conn %p\n", cq, conn);
rds_ib_stats_inc(s_ib_tx_cq_call);
ret = ib_req_notify_cq(cq, IB_CQ_NEXT_COMP);
if (ret)
rdsdebug("ib_req_notify_cq send failed: %d\n", ret);
while (ib_poll_cq(cq, 1, &wc) > 0) {
rdsdebug("wc wr_id 0x%llx status %u (%s) byte_len %u imm_data %u\n",
(unsigned long long)wc.wr_id, wc.status,
rds_ib_wc_status_str(wc.status), wc.byte_len,
be32_to_cpu(wc.ex.imm_data));
rds_ib_stats_inc(s_ib_tx_cq_event);
if (wc.wr_id == RDS_IB_ACK_WR_ID) {
if (time_after(jiffies, ic->i_ack_queued + HZ/2))
rds_ib_stats_inc(s_ib_tx_stalled);
rds_ib_ack_send_complete(ic);
continue;
}
oldest = rds_ib_ring_oldest(&ic->i_send_ring);
completed = rds_ib_ring_completed(&ic->i_send_ring, wc.wr_id, oldest);
for (i = 0; i < completed; i++) {
send = &ic->i_sends[oldest];
if (send->s_wr.send_flags & IB_SEND_SIGNALED)
nr_sig++;
rm = rds_ib_send_unmap_op(ic, send, wc.status);
if (time_after(jiffies, send->s_queued + HZ/2))
rds_ib_stats_inc(s_ib_tx_stalled);
if (send->s_op) {
if (send->s_op == rm->m_final_op) {
rds_message_unmapped(rm);
}
rds_message_put(rm);
send->s_op = NULL;
}
oldest = (oldest + 1) % ic->i_send_ring.w_nr;
}
rds_ib_ring_free(&ic->i_send_ring, completed);
rds_ib_sub_signaled(ic, nr_sig);
nr_sig = 0;
if (test_and_clear_bit(RDS_LL_SEND_FULL, &conn->c_flags) ||
test_bit(0, &conn->c_map_queued))
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
if (wc.status != IB_WC_SUCCESS && rds_conn_up(conn)) {
rds_ib_conn_error(conn, "send completion on %pI4 had status "
"%u (%s), disconnecting and reconnecting\n",
&conn->c_faddr, wc.status,
rds_ib_wc_status_str(wc.status));
}
}
}
int rds_ib_send_grab_credits(struct rds_ib_connection *ic,
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
rdsdebug("rds_ib_send_grab_credits(%u): credits=%u posted=%u\n",
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
void rds_ib_send_add_credits(struct rds_connection *conn, unsigned int credits)
{
struct rds_ib_connection *ic = conn->c_transport_data;
if (credits == 0)
return;
rdsdebug("rds_ib_send_add_credits(%u): current=%u%s\n",
credits,
IB_GET_SEND_CREDITS(atomic_read(&ic->i_credits)),
test_bit(RDS_LL_SEND_FULL, &conn->c_flags) ? ", ll_send_full" : "");
atomic_add(IB_SET_SEND_CREDITS(credits), &ic->i_credits);
if (test_and_clear_bit(RDS_LL_SEND_FULL, &conn->c_flags))
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
WARN_ON(IB_GET_SEND_CREDITS(credits) >= 16384);
rds_ib_stats_inc(s_ib_rx_credit_updates);
}
void rds_ib_advertise_credits(struct rds_connection *conn, unsigned int posted)
{
struct rds_ib_connection *ic = conn->c_transport_data;
if (posted == 0)
return;
atomic_add(IB_SET_POST_CREDITS(posted), &ic->i_credits);
if (IB_GET_POST_CREDITS(atomic_read(&ic->i_credits)) >= 16)
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
}
static inline int rds_ib_set_wr_signal_state(struct rds_ib_connection *ic,
struct rds_ib_send_work *send,
bool notify)
{
if (ic->i_unsignaled_wrs-- == 0 || notify) {
ic->i_unsignaled_wrs = rds_ib_sysctl_max_unsig_wrs;
send->s_wr.send_flags |= IB_SEND_SIGNALED;
return 1;
}
return 0;
}
int rds_ib_xmit(struct rds_connection *conn, struct rds_message *rm,
unsigned int hdr_off, unsigned int sg, unsigned int off)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct ib_device *dev = ic->i_cm_id->device;
struct rds_ib_send_work *send = NULL;
struct rds_ib_send_work *first;
struct rds_ib_send_work *prev;
struct ib_send_wr *failed_wr;
struct scatterlist *scat;
u32 pos;
u32 i;
u32 work_alloc;
u32 credit_alloc = 0;
u32 posted;
u32 adv_credits = 0;
int send_flags = 0;
int bytes_sent = 0;
int ret;
int flow_controlled = 0;
int nr_sig = 0;
BUG_ON(off % RDS_FRAG_SIZE);
BUG_ON(hdr_off != 0 && hdr_off != sizeof(struct rds_header));
if (conn->c_loopback
&& rm->m_inc.i_hdr.h_flags & RDS_FLAG_CONG_BITMAP) {
rds_cong_map_updated(conn->c_fcong, ~(u64) 0);
scat = &rm->data.op_sg[sg];
ret = max_t(int, RDS_CONG_MAP_BYTES, scat->length);
return sizeof(struct rds_header) + ret;
}
if (be32_to_cpu(rm->m_inc.i_hdr.h_len) == 0)
i = 1;
else
i = ceil(be32_to_cpu(rm->m_inc.i_hdr.h_len), RDS_FRAG_SIZE);
work_alloc = rds_ib_ring_alloc(&ic->i_send_ring, i, &pos);
if (work_alloc == 0) {
set_bit(RDS_LL_SEND_FULL, &conn->c_flags);
rds_ib_stats_inc(s_ib_tx_ring_full);
ret = -ENOMEM;
goto out;
}
if (ic->i_flowctl) {
credit_alloc = rds_ib_send_grab_credits(ic, work_alloc, &posted, 0, RDS_MAX_ADV_CREDIT);
adv_credits += posted;
if (credit_alloc < work_alloc) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc - credit_alloc);
work_alloc = credit_alloc;
flow_controlled = 1;
}
if (work_alloc == 0) {
set_bit(RDS_LL_SEND_FULL, &conn->c_flags);
rds_ib_stats_inc(s_ib_tx_throttle);
ret = -ENOMEM;
goto out;
}
}
if (!ic->i_data_op) {
if (rm->data.op_nents) {
rm->data.op_count = ib_dma_map_sg(dev,
rm->data.op_sg,
rm->data.op_nents,
DMA_TO_DEVICE);
rdsdebug("ic %p mapping rm %p: %d\n", ic, rm, rm->data.op_count);
if (rm->data.op_count == 0) {
rds_ib_stats_inc(s_ib_tx_sg_mapping_failure);
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
ret = -ENOMEM;
goto out;
}
} else {
rm->data.op_count = 0;
}
rds_message_addref(rm);
ic->i_data_op = &rm->data;
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
rm->m_inc.i_hdr.h_ack = cpu_to_be64(rds_ib_piggyb_ack(ic));
rds_message_make_checksum(&rm->m_inc.i_hdr);
if (ic->i_flowctl) {
rds_ib_send_grab_credits(ic, 0, &posted, 1, RDS_MAX_ADV_CREDIT - adv_credits);
adv_credits += posted;
BUG_ON(adv_credits > 255);
}
}
if (rm->rdma.op_active && rm->rdma.op_fence)
send_flags = IB_SEND_FENCE;
send = &ic->i_sends[pos];
first = send;
prev = NULL;
scat = &ic->i_data_op->op_sg[sg];
i = 0;
do {
unsigned int len = 0;
send->s_wr.send_flags = send_flags;
send->s_wr.opcode = IB_WR_SEND;
send->s_wr.num_sge = 1;
send->s_wr.next = NULL;
send->s_queued = jiffies;
send->s_op = NULL;
send->s_sge[0].addr = ic->i_send_hdrs_dma
+ (pos * sizeof(struct rds_header));
send->s_sge[0].length = sizeof(struct rds_header);
memcpy(&ic->i_send_hdrs[pos], &rm->m_inc.i_hdr, sizeof(struct rds_header));
if (i < work_alloc
&& scat != &rm->data.op_sg[rm->data.op_count]) {
len = min(RDS_FRAG_SIZE, ib_sg_dma_len(dev, scat) - off);
send->s_wr.num_sge = 2;
send->s_sge[1].addr = ib_sg_dma_address(dev, scat) + off;
send->s_sge[1].length = len;
bytes_sent += len;
off += len;
if (off == ib_sg_dma_len(dev, scat)) {
scat++;
off = 0;
}
}
rds_ib_set_wr_signal_state(ic, send, 0);
if (ic->i_flowctl && flow_controlled && i == (work_alloc-1))
send->s_wr.send_flags |= IB_SEND_SIGNALED | IB_SEND_SOLICITED;
if (send->s_wr.send_flags & IB_SEND_SIGNALED)
nr_sig++;
rdsdebug("send %p wr %p num_sge %u next %p\n", send,
&send->s_wr, send->s_wr.num_sge, send->s_wr.next);
if (ic->i_flowctl && adv_credits) {
struct rds_header *hdr = &ic->i_send_hdrs[pos];
hdr->h_credit = adv_credits;
rds_message_make_checksum(hdr);
adv_credits = 0;
rds_ib_stats_inc(s_ib_tx_credit_updates);
}
if (prev)
prev->s_wr.next = &send->s_wr;
prev = send;
pos = (pos + 1) % ic->i_send_ring.w_nr;
send = &ic->i_sends[pos];
i++;
} while (i < work_alloc
&& scat != &rm->data.op_sg[rm->data.op_count]);
if (hdr_off == 0)
bytes_sent += sizeof(struct rds_header);
if (scat == &rm->data.op_sg[rm->data.op_count]) {
prev->s_op = ic->i_data_op;
prev->s_wr.send_flags |= IB_SEND_SOLICITED;
ic->i_data_op = NULL;
}
if (i < work_alloc) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc - i);
work_alloc = i;
}
if (ic->i_flowctl && i < credit_alloc)
rds_ib_send_add_credits(conn, credit_alloc - i);
if (nr_sig)
atomic_add(nr_sig, &ic->i_signaled_sends);
failed_wr = &first->s_wr;
ret = ib_post_send(ic->i_cm_id->qp, &first->s_wr, &failed_wr);
rdsdebug("ic %p first %p (wr %p) ret %d wr %p\n", ic,
first, &first->s_wr, ret, failed_wr);
BUG_ON(failed_wr != &first->s_wr);
if (ret) {
printk(KERN_WARNING "RDS/IB: ib_post_send to %pI4 "
"returned %d\n", &conn->c_faddr, ret);
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_sub_signaled(ic, nr_sig);
if (prev->s_op) {
ic->i_data_op = prev->s_op;
prev->s_op = NULL;
}
rds_ib_conn_error(ic->conn, "ib_post_send failed\n");
goto out;
}
ret = bytes_sent;
out:
BUG_ON(adv_credits);
return ret;
}
int rds_ib_xmit_atomic(struct rds_connection *conn, struct rm_atomic_op *op)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_ib_send_work *send = NULL;
struct ib_send_wr *failed_wr;
struct rds_ib_device *rds_ibdev;
u32 pos;
u32 work_alloc;
int ret;
int nr_sig = 0;
rds_ibdev = ib_get_client_data(ic->i_cm_id->device, &rds_ib_client);
work_alloc = rds_ib_ring_alloc(&ic->i_send_ring, 1, &pos);
if (work_alloc != 1) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_stats_inc(s_ib_tx_ring_full);
ret = -ENOMEM;
goto out;
}
send = &ic->i_sends[pos];
send->s_queued = jiffies;
if (op->op_type == RDS_ATOMIC_TYPE_CSWP) {
send->s_wr.opcode = IB_WR_MASKED_ATOMIC_CMP_AND_SWP;
send->s_wr.wr.atomic.compare_add = op->op_m_cswp.compare;
send->s_wr.wr.atomic.swap = op->op_m_cswp.swap;
send->s_wr.wr.atomic.compare_add_mask = op->op_m_cswp.compare_mask;
send->s_wr.wr.atomic.swap_mask = op->op_m_cswp.swap_mask;
} else {
send->s_wr.opcode = IB_WR_MASKED_ATOMIC_FETCH_AND_ADD;
send->s_wr.wr.atomic.compare_add = op->op_m_fadd.add;
send->s_wr.wr.atomic.swap = 0;
send->s_wr.wr.atomic.compare_add_mask = op->op_m_fadd.nocarry_mask;
send->s_wr.wr.atomic.swap_mask = 0;
}
nr_sig = rds_ib_set_wr_signal_state(ic, send, op->op_notify);
send->s_wr.num_sge = 1;
send->s_wr.next = NULL;
send->s_wr.wr.atomic.remote_addr = op->op_remote_addr;
send->s_wr.wr.atomic.rkey = op->op_rkey;
send->s_op = op;
rds_message_addref(container_of(send->s_op, struct rds_message, atomic));
ret = ib_dma_map_sg(ic->i_cm_id->device, op->op_sg, 1, DMA_FROM_DEVICE);
rdsdebug("ic %p mapping atomic op %p. mapped %d pg\n", ic, op, ret);
if (ret != 1) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_stats_inc(s_ib_tx_sg_mapping_failure);
ret = -ENOMEM;
goto out;
}
send->s_sge[0].addr = ib_sg_dma_address(ic->i_cm_id->device, op->op_sg);
send->s_sge[0].length = ib_sg_dma_len(ic->i_cm_id->device, op->op_sg);
send->s_sge[0].lkey = ic->i_mr->lkey;
rdsdebug("rva %Lx rpa %Lx len %u\n", op->op_remote_addr,
send->s_sge[0].addr, send->s_sge[0].length);
if (nr_sig)
atomic_add(nr_sig, &ic->i_signaled_sends);
failed_wr = &send->s_wr;
ret = ib_post_send(ic->i_cm_id->qp, &send->s_wr, &failed_wr);
rdsdebug("ic %p send %p (wr %p) ret %d wr %p\n", ic,
send, &send->s_wr, ret, failed_wr);
BUG_ON(failed_wr != &send->s_wr);
if (ret) {
printk(KERN_WARNING "RDS/IB: atomic ib_post_send to %pI4 "
"returned %d\n", &conn->c_faddr, ret);
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_sub_signaled(ic, nr_sig);
goto out;
}
if (unlikely(failed_wr != &send->s_wr)) {
printk(KERN_WARNING "RDS/IB: atomic ib_post_send() rc=%d, but failed_wqe updated!\n", ret);
BUG_ON(failed_wr != &send->s_wr);
}
out:
return ret;
}
int rds_ib_xmit_rdma(struct rds_connection *conn, struct rm_rdma_op *op)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_ib_send_work *send = NULL;
struct rds_ib_send_work *first;
struct rds_ib_send_work *prev;
struct ib_send_wr *failed_wr;
struct scatterlist *scat;
unsigned long len;
u64 remote_addr = op->op_remote_addr;
u32 max_sge = ic->rds_ibdev->max_sge;
u32 pos;
u32 work_alloc;
u32 i;
u32 j;
int sent;
int ret;
int num_sge;
int nr_sig = 0;
if (!op->op_mapped) {
op->op_count = ib_dma_map_sg(ic->i_cm_id->device,
op->op_sg, op->op_nents, (op->op_write) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE);
rdsdebug("ic %p mapping op %p: %d\n", ic, op, op->op_count);
if (op->op_count == 0) {
rds_ib_stats_inc(s_ib_tx_sg_mapping_failure);
ret = -ENOMEM;
goto out;
}
op->op_mapped = 1;
}
i = ceil(op->op_count, max_sge);
work_alloc = rds_ib_ring_alloc(&ic->i_send_ring, i, &pos);
if (work_alloc != i) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_stats_inc(s_ib_tx_ring_full);
ret = -ENOMEM;
goto out;
}
send = &ic->i_sends[pos];
first = send;
prev = NULL;
scat = &op->op_sg[0];
sent = 0;
num_sge = op->op_count;
for (i = 0; i < work_alloc && scat != &op->op_sg[op->op_count]; i++) {
send->s_wr.send_flags = 0;
send->s_queued = jiffies;
send->s_op = NULL;
nr_sig += rds_ib_set_wr_signal_state(ic, send, op->op_notify);
send->s_wr.opcode = op->op_write ? IB_WR_RDMA_WRITE : IB_WR_RDMA_READ;
send->s_wr.wr.rdma.remote_addr = remote_addr;
send->s_wr.wr.rdma.rkey = op->op_rkey;
if (num_sge > max_sge) {
send->s_wr.num_sge = max_sge;
num_sge -= max_sge;
} else {
send->s_wr.num_sge = num_sge;
}
send->s_wr.next = NULL;
if (prev)
prev->s_wr.next = &send->s_wr;
for (j = 0; j < send->s_wr.num_sge && scat != &op->op_sg[op->op_count]; j++) {
len = ib_sg_dma_len(ic->i_cm_id->device, scat);
send->s_sge[j].addr =
ib_sg_dma_address(ic->i_cm_id->device, scat);
send->s_sge[j].length = len;
send->s_sge[j].lkey = ic->i_mr->lkey;
sent += len;
rdsdebug("ic %p sent %d remote_addr %llu\n", ic, sent, remote_addr);
remote_addr += len;
scat++;
}
rdsdebug("send %p wr %p num_sge %u next %p\n", send,
&send->s_wr, send->s_wr.num_sge, send->s_wr.next);
prev = send;
if (++send == &ic->i_sends[ic->i_send_ring.w_nr])
send = ic->i_sends;
}
if (scat == &op->op_sg[op->op_count]) {
prev->s_op = op;
rds_message_addref(container_of(op, struct rds_message, rdma));
}
if (i < work_alloc) {
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc - i);
work_alloc = i;
}
if (nr_sig)
atomic_add(nr_sig, &ic->i_signaled_sends);
failed_wr = &first->s_wr;
ret = ib_post_send(ic->i_cm_id->qp, &first->s_wr, &failed_wr);
rdsdebug("ic %p first %p (wr %p) ret %d wr %p\n", ic,
first, &first->s_wr, ret, failed_wr);
BUG_ON(failed_wr != &first->s_wr);
if (ret) {
printk(KERN_WARNING "RDS/IB: rdma ib_post_send to %pI4 "
"returned %d\n", &conn->c_faddr, ret);
rds_ib_ring_unalloc(&ic->i_send_ring, work_alloc);
rds_ib_sub_signaled(ic, nr_sig);
goto out;
}
if (unlikely(failed_wr != &first->s_wr)) {
printk(KERN_WARNING "RDS/IB: ib_post_send() rc=%d, but failed_wqe updated!\n", ret);
BUG_ON(failed_wr != &first->s_wr);
}
out:
return ret;
}
void rds_ib_xmit_complete(struct rds_connection *conn)
{
struct rds_ib_connection *ic = conn->c_transport_data;
rds_ib_attempt_ack(ic);
}
