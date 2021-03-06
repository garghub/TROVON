static void rds_iw_frag_drop_page(struct rds_page_frag *frag)
{
rdsdebug("frag %p page %p\n", frag, frag->f_page);
__free_page(frag->f_page);
frag->f_page = NULL;
}
static void rds_iw_frag_free(struct rds_page_frag *frag)
{
rdsdebug("frag %p page %p\n", frag, frag->f_page);
BUG_ON(frag->f_page);
kmem_cache_free(rds_iw_frag_slab, frag);
}
static void rds_iw_recv_unmap_page(struct rds_iw_connection *ic,
struct rds_iw_recv_work *recv)
{
struct rds_page_frag *frag = recv->r_frag;
rdsdebug("recv %p frag %p page %p\n", recv, frag, frag->f_page);
if (frag->f_mapped)
ib_dma_unmap_page(ic->i_cm_id->device,
frag->f_mapped,
RDS_FRAG_SIZE, DMA_FROM_DEVICE);
frag->f_mapped = 0;
}
void rds_iw_recv_init_ring(struct rds_iw_connection *ic)
{
struct rds_iw_recv_work *recv;
u32 i;
for (i = 0, recv = ic->i_recvs; i < ic->i_recv_ring.w_nr; i++, recv++) {
struct ib_sge *sge;
recv->r_iwinc = NULL;
recv->r_frag = NULL;
recv->r_wr.next = NULL;
recv->r_wr.wr_id = i;
recv->r_wr.sg_list = recv->r_sge;
recv->r_wr.num_sge = RDS_IW_RECV_SGE;
sge = rds_iw_data_sge(ic, recv->r_sge);
sge->addr = 0;
sge->length = RDS_FRAG_SIZE;
sge->lkey = 0;
sge = rds_iw_header_sge(ic, recv->r_sge);
sge->addr = ic->i_recv_hdrs_dma + (i * sizeof(struct rds_header));
sge->length = sizeof(struct rds_header);
sge->lkey = 0;
}
}
static void rds_iw_recv_clear_one(struct rds_iw_connection *ic,
struct rds_iw_recv_work *recv)
{
if (recv->r_iwinc) {
rds_inc_put(&recv->r_iwinc->ii_inc);
recv->r_iwinc = NULL;
}
if (recv->r_frag) {
rds_iw_recv_unmap_page(ic, recv);
if (recv->r_frag->f_page)
rds_iw_frag_drop_page(recv->r_frag);
rds_iw_frag_free(recv->r_frag);
recv->r_frag = NULL;
}
}
void rds_iw_recv_clear_ring(struct rds_iw_connection *ic)
{
u32 i;
for (i = 0; i < ic->i_recv_ring.w_nr; i++)
rds_iw_recv_clear_one(ic, &ic->i_recvs[i]);
if (ic->i_frag.f_page)
rds_iw_frag_drop_page(&ic->i_frag);
}
static int rds_iw_recv_refill_one(struct rds_connection *conn,
struct rds_iw_recv_work *recv,
gfp_t kptr_gfp, gfp_t page_gfp)
{
struct rds_iw_connection *ic = conn->c_transport_data;
dma_addr_t dma_addr;
struct ib_sge *sge;
int ret = -ENOMEM;
if (!recv->r_iwinc) {
if (!atomic_add_unless(&rds_iw_allocation, 1, rds_iw_sysctl_max_recv_allocation)) {
rds_iw_stats_inc(s_iw_rx_alloc_limit);
goto out;
}
recv->r_iwinc = kmem_cache_alloc(rds_iw_incoming_slab,
kptr_gfp);
if (!recv->r_iwinc) {
atomic_dec(&rds_iw_allocation);
goto out;
}
INIT_LIST_HEAD(&recv->r_iwinc->ii_frags);
rds_inc_init(&recv->r_iwinc->ii_inc, conn, conn->c_faddr);
}
if (!recv->r_frag) {
recv->r_frag = kmem_cache_alloc(rds_iw_frag_slab, kptr_gfp);
if (!recv->r_frag)
goto out;
INIT_LIST_HEAD(&recv->r_frag->f_item);
recv->r_frag->f_page = NULL;
}
if (!ic->i_frag.f_page) {
ic->i_frag.f_page = alloc_page(page_gfp);
if (!ic->i_frag.f_page)
goto out;
ic->i_frag.f_offset = 0;
}
dma_addr = ib_dma_map_page(ic->i_cm_id->device,
ic->i_frag.f_page,
ic->i_frag.f_offset,
RDS_FRAG_SIZE,
DMA_FROM_DEVICE);
if (ib_dma_mapping_error(ic->i_cm_id->device, dma_addr))
goto out;
recv->r_frag->f_page = ic->i_frag.f_page;
recv->r_frag->f_offset = ic->i_frag.f_offset;
recv->r_frag->f_mapped = dma_addr;
sge = rds_iw_data_sge(ic, recv->r_sge);
sge->addr = dma_addr;
sge->length = RDS_FRAG_SIZE;
sge = rds_iw_header_sge(ic, recv->r_sge);
sge->addr = ic->i_recv_hdrs_dma + (recv - ic->i_recvs) * sizeof(struct rds_header);
sge->length = sizeof(struct rds_header);
get_page(recv->r_frag->f_page);
if (ic->i_frag.f_offset < RDS_PAGE_LAST_OFF) {
ic->i_frag.f_offset += RDS_FRAG_SIZE;
} else {
put_page(ic->i_frag.f_page);
ic->i_frag.f_page = NULL;
ic->i_frag.f_offset = 0;
}
ret = 0;
out:
return ret;
}
int rds_iw_recv_refill(struct rds_connection *conn, gfp_t kptr_gfp,
gfp_t page_gfp, int prefill)
{
struct rds_iw_connection *ic = conn->c_transport_data;
struct rds_iw_recv_work *recv;
struct ib_recv_wr *failed_wr;
unsigned int posted = 0;
int ret = 0;
u32 pos;
while ((prefill || rds_conn_up(conn)) &&
rds_iw_ring_alloc(&ic->i_recv_ring, 1, &pos)) {
if (pos >= ic->i_recv_ring.w_nr) {
printk(KERN_NOTICE "Argh - ring alloc returned pos=%u\n",
pos);
ret = -EINVAL;
break;
}
recv = &ic->i_recvs[pos];
ret = rds_iw_recv_refill_one(conn, recv, kptr_gfp, page_gfp);
if (ret) {
ret = -1;
break;
}
ret = ib_post_recv(ic->i_cm_id->qp, &recv->r_wr, &failed_wr);
rdsdebug("recv %p iwinc %p page %p addr %lu ret %d\n", recv,
recv->r_iwinc, recv->r_frag->f_page,
(long) recv->r_frag->f_mapped, ret);
if (ret) {
rds_iw_conn_error(conn, "recv post on "
"%pI4 returned %d, disconnecting and "
"reconnecting\n", &conn->c_faddr,
ret);
ret = -1;
break;
}
posted++;
}
if (ic->i_flowctl && posted)
rds_iw_advertise_credits(conn, posted);
if (ret)
rds_iw_ring_unalloc(&ic->i_recv_ring, 1);
return ret;
}
static void rds_iw_inc_purge(struct rds_incoming *inc)
{
struct rds_iw_incoming *iwinc;
struct rds_page_frag *frag;
struct rds_page_frag *pos;
iwinc = container_of(inc, struct rds_iw_incoming, ii_inc);
rdsdebug("purging iwinc %p inc %p\n", iwinc, inc);
list_for_each_entry_safe(frag, pos, &iwinc->ii_frags, f_item) {
list_del_init(&frag->f_item);
rds_iw_frag_drop_page(frag);
rds_iw_frag_free(frag);
}
}
void rds_iw_inc_free(struct rds_incoming *inc)
{
struct rds_iw_incoming *iwinc;
iwinc = container_of(inc, struct rds_iw_incoming, ii_inc);
rds_iw_inc_purge(inc);
rdsdebug("freeing iwinc %p inc %p\n", iwinc, inc);
BUG_ON(!list_empty(&iwinc->ii_frags));
kmem_cache_free(rds_iw_incoming_slab, iwinc);
atomic_dec(&rds_iw_allocation);
BUG_ON(atomic_read(&rds_iw_allocation) < 0);
}
int rds_iw_inc_copy_to_user(struct rds_incoming *inc, struct iovec *first_iov,
size_t size)
{
struct rds_iw_incoming *iwinc;
struct rds_page_frag *frag;
struct iovec *iov = first_iov;
unsigned long to_copy;
unsigned long frag_off = 0;
unsigned long iov_off = 0;
int copied = 0;
int ret;
u32 len;
iwinc = container_of(inc, struct rds_iw_incoming, ii_inc);
frag = list_entry(iwinc->ii_frags.next, struct rds_page_frag, f_item);
len = be32_to_cpu(inc->i_hdr.h_len);
while (copied < size && copied < len) {
if (frag_off == RDS_FRAG_SIZE) {
frag = list_entry(frag->f_item.next,
struct rds_page_frag, f_item);
frag_off = 0;
}
while (iov_off == iov->iov_len) {
iov_off = 0;
iov++;
}
to_copy = min(iov->iov_len - iov_off, RDS_FRAG_SIZE - frag_off);
to_copy = min_t(size_t, to_copy, size - copied);
to_copy = min_t(unsigned long, to_copy, len - copied);
rdsdebug("%lu bytes to user [%p, %zu] + %lu from frag "
"[%p, %lu] + %lu\n",
to_copy, iov->iov_base, iov->iov_len, iov_off,
frag->f_page, frag->f_offset, frag_off);
ret = rds_page_copy_to_user(frag->f_page,
frag->f_offset + frag_off,
iov->iov_base + iov_off,
to_copy);
if (ret) {
copied = ret;
break;
}
iov_off += to_copy;
frag_off += to_copy;
copied += to_copy;
}
return copied;
}
void rds_iw_recv_init_ack(struct rds_iw_connection *ic)
{
struct ib_send_wr *wr = &ic->i_ack_wr;
struct ib_sge *sge = &ic->i_ack_sge;
sge->addr = ic->i_ack_dma;
sge->length = sizeof(struct rds_header);
sge->lkey = rds_iw_local_dma_lkey(ic);
wr->sg_list = sge;
wr->num_sge = 1;
wr->opcode = IB_WR_SEND;
wr->wr_id = RDS_IW_ACK_WR_ID;
wr->send_flags = IB_SEND_SIGNALED | IB_SEND_SOLICITED;
}
static void rds_iw_set_ack(struct rds_iw_connection *ic, u64 seq,
int ack_required)
{
unsigned long flags;
spin_lock_irqsave(&ic->i_ack_lock, flags);
ic->i_ack_next = seq;
if (ack_required)
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
spin_unlock_irqrestore(&ic->i_ack_lock, flags);
}
static u64 rds_iw_get_ack(struct rds_iw_connection *ic)
{
unsigned long flags;
u64 seq;
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
spin_lock_irqsave(&ic->i_ack_lock, flags);
seq = ic->i_ack_next;
spin_unlock_irqrestore(&ic->i_ack_lock, flags);
return seq;
}
static void rds_iw_set_ack(struct rds_iw_connection *ic, u64 seq,
int ack_required)
{
atomic64_set(&ic->i_ack_next, seq);
if (ack_required) {
smp_mb__before_atomic();
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
}
}
static u64 rds_iw_get_ack(struct rds_iw_connection *ic)
{
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
smp_mb__after_atomic();
return atomic64_read(&ic->i_ack_next);
}
static void rds_iw_send_ack(struct rds_iw_connection *ic, unsigned int adv_credits)
{
struct rds_header *hdr = ic->i_ack;
struct ib_send_wr *failed_wr;
u64 seq;
int ret;
seq = rds_iw_get_ack(ic);
rdsdebug("send_ack: ic %p ack %llu\n", ic, (unsigned long long) seq);
rds_message_populate_header(hdr, 0, 0, 0);
hdr->h_ack = cpu_to_be64(seq);
hdr->h_credit = adv_credits;
rds_message_make_checksum(hdr);
ic->i_ack_queued = jiffies;
ret = ib_post_send(ic->i_cm_id->qp, &ic->i_ack_wr, &failed_wr);
if (unlikely(ret)) {
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
rds_iw_stats_inc(s_iw_ack_send_failure);
rds_iw_conn_error(ic->conn, "sending ack failed\n");
} else
rds_iw_stats_inc(s_iw_ack_sent);
}
void rds_iw_attempt_ack(struct rds_iw_connection *ic)
{
unsigned int adv_credits;
if (!test_bit(IB_ACK_REQUESTED, &ic->i_ack_flags))
return;
if (test_and_set_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags)) {
rds_iw_stats_inc(s_iw_ack_send_delayed);
return;
}
if (!rds_iw_send_grab_credits(ic, 1, &adv_credits, 0, RDS_MAX_ADV_CREDIT)) {
rds_iw_stats_inc(s_iw_tx_throttle);
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
return;
}
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
rds_iw_send_ack(ic, adv_credits);
}
void rds_iw_ack_send_complete(struct rds_iw_connection *ic)
{
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
rds_iw_attempt_ack(ic);
}
u64 rds_iw_piggyb_ack(struct rds_iw_connection *ic)
{
if (test_and_clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags))
rds_iw_stats_inc(s_iw_ack_send_piggybacked);
return rds_iw_get_ack(ic);
}
static void rds_iw_cong_recv(struct rds_connection *conn,
struct rds_iw_incoming *iwinc)
{
struct rds_cong_map *map;
unsigned int map_off;
unsigned int map_page;
struct rds_page_frag *frag;
unsigned long frag_off;
unsigned long to_copy;
unsigned long copied;
uint64_t uncongested = 0;
void *addr;
if (be32_to_cpu(iwinc->ii_inc.i_hdr.h_len) != RDS_CONG_MAP_BYTES)
return;
map = conn->c_fcong;
map_page = 0;
map_off = 0;
frag = list_entry(iwinc->ii_frags.next, struct rds_page_frag, f_item);
frag_off = 0;
copied = 0;
while (copied < RDS_CONG_MAP_BYTES) {
uint64_t *src, *dst;
unsigned int k;
to_copy = min(RDS_FRAG_SIZE - frag_off, PAGE_SIZE - map_off);
BUG_ON(to_copy & 7);
addr = kmap_atomic(frag->f_page);
src = addr + frag_off;
dst = (void *)map->m_page_addrs[map_page] + map_off;
for (k = 0; k < to_copy; k += 8) {
uncongested |= ~(*src) & *dst;
*dst++ = *src++;
}
kunmap_atomic(addr);
copied += to_copy;
map_off += to_copy;
if (map_off == PAGE_SIZE) {
map_off = 0;
map_page++;
}
frag_off += to_copy;
if (frag_off == RDS_FRAG_SIZE) {
frag = list_entry(frag->f_item.next,
struct rds_page_frag, f_item);
frag_off = 0;
}
}
uncongested = le64_to_cpu(uncongested);
rds_cong_map_updated(map, uncongested);
}
static void rds_iw_process_recv(struct rds_connection *conn,
struct rds_iw_recv_work *recv, u32 byte_len,
struct rds_iw_ack_state *state)
{
struct rds_iw_connection *ic = conn->c_transport_data;
struct rds_iw_incoming *iwinc = ic->i_iwinc;
struct rds_header *ihdr, *hdr;
rdsdebug("ic %p iwinc %p recv %p byte len %u\n", ic, iwinc, recv,
byte_len);
if (byte_len < sizeof(struct rds_header)) {
rds_iw_conn_error(conn, "incoming message "
"from %pI4 didn't include a "
"header, disconnecting and "
"reconnecting\n",
&conn->c_faddr);
return;
}
byte_len -= sizeof(struct rds_header);
ihdr = &ic->i_recv_hdrs[recv - ic->i_recvs];
if (!rds_message_verify_checksum(ihdr)) {
rds_iw_conn_error(conn, "incoming message "
"from %pI4 has corrupted header - "
"forcing a reconnect\n",
&conn->c_faddr);
rds_stats_inc(s_recv_drop_bad_checksum);
return;
}
state->ack_recv = be64_to_cpu(ihdr->h_ack);
state->ack_recv_valid = 1;
if (ihdr->h_credit)
rds_iw_send_add_credits(conn, ihdr->h_credit);
if (ihdr->h_sport == 0 && ihdr->h_dport == 0 && byte_len == 0) {
rds_iw_stats_inc(s_iw_ack_received);
rds_iw_frag_drop_page(recv->r_frag);
return;
}
if (!iwinc) {
iwinc = recv->r_iwinc;
recv->r_iwinc = NULL;
ic->i_iwinc = iwinc;
hdr = &iwinc->ii_inc.i_hdr;
memcpy(hdr, ihdr, sizeof(*hdr));
ic->i_recv_data_rem = be32_to_cpu(hdr->h_len);
rdsdebug("ic %p iwinc %p rem %u flag 0x%x\n", ic, iwinc,
ic->i_recv_data_rem, hdr->h_flags);
} else {
hdr = &iwinc->ii_inc.i_hdr;
if (hdr->h_sequence != ihdr->h_sequence ||
hdr->h_len != ihdr->h_len ||
hdr->h_sport != ihdr->h_sport ||
hdr->h_dport != ihdr->h_dport) {
rds_iw_conn_error(conn,
"fragment header mismatch; forcing reconnect\n");
return;
}
}
list_add_tail(&recv->r_frag->f_item, &iwinc->ii_frags);
recv->r_frag = NULL;
if (ic->i_recv_data_rem > RDS_FRAG_SIZE)
ic->i_recv_data_rem -= RDS_FRAG_SIZE;
else {
ic->i_recv_data_rem = 0;
ic->i_iwinc = NULL;
if (iwinc->ii_inc.i_hdr.h_flags == RDS_FLAG_CONG_BITMAP)
rds_iw_cong_recv(conn, iwinc);
else {
rds_recv_incoming(conn, conn->c_faddr, conn->c_laddr,
&iwinc->ii_inc, GFP_ATOMIC);
state->ack_next = be64_to_cpu(hdr->h_sequence);
state->ack_next_valid = 1;
}
if (hdr->h_flags & RDS_FLAG_ACK_REQUIRED) {
rds_stats_inc(s_recv_ack_required);
state->ack_required = 1;
}
rds_inc_put(&iwinc->ii_inc);
}
}
void rds_iw_recv_cq_comp_handler(struct ib_cq *cq, void *context)
{
struct rds_connection *conn = context;
struct rds_iw_connection *ic = conn->c_transport_data;
rdsdebug("conn %p cq %p\n", conn, cq);
rds_iw_stats_inc(s_iw_rx_cq_call);
tasklet_schedule(&ic->i_recv_tasklet);
}
static inline void rds_poll_cq(struct rds_iw_connection *ic,
struct rds_iw_ack_state *state)
{
struct rds_connection *conn = ic->conn;
struct ib_wc wc;
struct rds_iw_recv_work *recv;
while (ib_poll_cq(ic->i_recv_cq, 1, &wc) > 0) {
rdsdebug("wc wr_id 0x%llx status %u byte_len %u imm_data %u\n",
(unsigned long long)wc.wr_id, wc.status, wc.byte_len,
be32_to_cpu(wc.ex.imm_data));
rds_iw_stats_inc(s_iw_rx_cq_event);
recv = &ic->i_recvs[rds_iw_ring_oldest(&ic->i_recv_ring)];
rds_iw_recv_unmap_page(ic, recv);
if (rds_conn_up(conn) || rds_conn_connecting(conn)) {
if (wc.status == IB_WC_SUCCESS) {
rds_iw_process_recv(conn, recv, wc.byte_len, state);
} else {
rds_iw_conn_error(conn, "recv completion on "
"%pI4 had status %u, disconnecting and "
"reconnecting\n", &conn->c_faddr,
wc.status);
}
}
rds_iw_ring_free(&ic->i_recv_ring, 1);
}
}
void rds_iw_recv_tasklet_fn(unsigned long data)
{
struct rds_iw_connection *ic = (struct rds_iw_connection *) data;
struct rds_connection *conn = ic->conn;
struct rds_iw_ack_state state = { 0, };
rds_poll_cq(ic, &state);
ib_req_notify_cq(ic->i_recv_cq, IB_CQ_SOLICITED);
rds_poll_cq(ic, &state);
if (state.ack_next_valid)
rds_iw_set_ack(ic, state.ack_next, state.ack_required);
if (state.ack_recv_valid && state.ack_recv > ic->i_ack_recv) {
rds_send_drop_acked(conn, state.ack_recv, NULL);
ic->i_ack_recv = state.ack_recv;
}
if (rds_conn_up(conn))
rds_iw_attempt_ack(ic);
if (rds_iw_ring_empty(&ic->i_recv_ring))
rds_iw_stats_inc(s_iw_rx_ring_empty);
if (rds_iw_ring_low(&ic->i_recv_ring))
queue_delayed_work(rds_wq, &conn->c_recv_w, 0);
}
int rds_iw_recv(struct rds_connection *conn)
{
struct rds_iw_connection *ic = conn->c_transport_data;
int ret = 0;
rdsdebug("conn %p\n", conn);
mutex_lock(&ic->i_recv_mutex);
if (rds_iw_recv_refill(conn, GFP_KERNEL, GFP_HIGHUSER, 0))
ret = -ENOMEM;
else
rds_iw_stats_inc(s_iw_rx_refill_from_thread);
mutex_unlock(&ic->i_recv_mutex);
if (rds_conn_up(conn))
rds_iw_attempt_ack(ic);
return ret;
}
int rds_iw_recv_init(void)
{
struct sysinfo si;
int ret = -ENOMEM;
si_meminfo(&si);
rds_iw_sysctl_max_recv_allocation = si.totalram / 3 * PAGE_SIZE / RDS_FRAG_SIZE;
rds_iw_incoming_slab = kmem_cache_create("rds_iw_incoming",
sizeof(struct rds_iw_incoming),
0, 0, NULL);
if (!rds_iw_incoming_slab)
goto out;
rds_iw_frag_slab = kmem_cache_create("rds_iw_frag",
sizeof(struct rds_page_frag),
0, 0, NULL);
if (!rds_iw_frag_slab)
kmem_cache_destroy(rds_iw_incoming_slab);
else
ret = 0;
out:
return ret;
}
void rds_iw_recv_exit(void)
{
kmem_cache_destroy(rds_iw_incoming_slab);
kmem_cache_destroy(rds_iw_frag_slab);
}
