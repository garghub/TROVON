void rds_ib_recv_init_ring(struct rds_ib_connection *ic)
{
struct rds_ib_recv_work *recv;
u32 i;
for (i = 0, recv = ic->i_recvs; i < ic->i_recv_ring.w_nr; i++, recv++) {
struct ib_sge *sge;
recv->r_ibinc = NULL;
recv->r_frag = NULL;
recv->r_wr.next = NULL;
recv->r_wr.wr_id = i;
recv->r_wr.sg_list = recv->r_sge;
recv->r_wr.num_sge = RDS_IB_RECV_SGE;
sge = &recv->r_sge[0];
sge->addr = ic->i_recv_hdrs_dma + (i * sizeof(struct rds_header));
sge->length = sizeof(struct rds_header);
sge->lkey = ic->i_pd->local_dma_lkey;
sge = &recv->r_sge[1];
sge->addr = 0;
sge->length = RDS_FRAG_SIZE;
sge->lkey = ic->i_pd->local_dma_lkey;
}
}
static void list_splice_entire_tail(struct list_head *from,
struct list_head *to)
{
struct list_head *from_last = from->prev;
list_splice_tail(from_last, to);
list_add_tail(from_last, to);
}
static void rds_ib_cache_xfer_to_ready(struct rds_ib_refill_cache *cache)
{
struct list_head *tmp;
tmp = xchg(&cache->xfer, NULL);
if (tmp) {
if (cache->ready)
list_splice_entire_tail(tmp, cache->ready);
else
cache->ready = tmp;
}
}
static int rds_ib_recv_alloc_cache(struct rds_ib_refill_cache *cache)
{
struct rds_ib_cache_head *head;
int cpu;
cache->percpu = alloc_percpu(struct rds_ib_cache_head);
if (!cache->percpu)
return -ENOMEM;
for_each_possible_cpu(cpu) {
head = per_cpu_ptr(cache->percpu, cpu);
head->first = NULL;
head->count = 0;
}
cache->xfer = NULL;
cache->ready = NULL;
return 0;
}
int rds_ib_recv_alloc_caches(struct rds_ib_connection *ic)
{
int ret;
ret = rds_ib_recv_alloc_cache(&ic->i_cache_incs);
if (!ret) {
ret = rds_ib_recv_alloc_cache(&ic->i_cache_frags);
if (ret)
free_percpu(ic->i_cache_incs.percpu);
}
return ret;
}
static void rds_ib_cache_splice_all_lists(struct rds_ib_refill_cache *cache,
struct list_head *caller_list)
{
struct rds_ib_cache_head *head;
int cpu;
for_each_possible_cpu(cpu) {
head = per_cpu_ptr(cache->percpu, cpu);
if (head->first) {
list_splice_entire_tail(head->first, caller_list);
head->first = NULL;
}
}
if (cache->ready) {
list_splice_entire_tail(cache->ready, caller_list);
cache->ready = NULL;
}
}
void rds_ib_recv_free_caches(struct rds_ib_connection *ic)
{
struct rds_ib_incoming *inc;
struct rds_ib_incoming *inc_tmp;
struct rds_page_frag *frag;
struct rds_page_frag *frag_tmp;
LIST_HEAD(list);
rds_ib_cache_xfer_to_ready(&ic->i_cache_incs);
rds_ib_cache_splice_all_lists(&ic->i_cache_incs, &list);
free_percpu(ic->i_cache_incs.percpu);
list_for_each_entry_safe(inc, inc_tmp, &list, ii_cache_entry) {
list_del(&inc->ii_cache_entry);
WARN_ON(!list_empty(&inc->ii_frags));
kmem_cache_free(rds_ib_incoming_slab, inc);
}
rds_ib_cache_xfer_to_ready(&ic->i_cache_frags);
rds_ib_cache_splice_all_lists(&ic->i_cache_frags, &list);
free_percpu(ic->i_cache_frags.percpu);
list_for_each_entry_safe(frag, frag_tmp, &list, f_cache_entry) {
list_del(&frag->f_cache_entry);
WARN_ON(!list_empty(&frag->f_item));
kmem_cache_free(rds_ib_frag_slab, frag);
}
}
static void rds_ib_frag_free(struct rds_ib_connection *ic,
struct rds_page_frag *frag)
{
rdsdebug("frag %p page %p\n", frag, sg_page(&frag->f_sg));
rds_ib_recv_cache_put(&frag->f_cache_entry, &ic->i_cache_frags);
}
void rds_ib_inc_free(struct rds_incoming *inc)
{
struct rds_ib_incoming *ibinc;
struct rds_page_frag *frag;
struct rds_page_frag *pos;
struct rds_ib_connection *ic = inc->i_conn->c_transport_data;
ibinc = container_of(inc, struct rds_ib_incoming, ii_inc);
list_for_each_entry_safe(frag, pos, &ibinc->ii_frags, f_item) {
list_del_init(&frag->f_item);
rds_ib_frag_free(ic, frag);
}
BUG_ON(!list_empty(&ibinc->ii_frags));
rdsdebug("freeing ibinc %p inc %p\n", ibinc, inc);
rds_ib_recv_cache_put(&ibinc->ii_cache_entry, &ic->i_cache_incs);
}
static void rds_ib_recv_clear_one(struct rds_ib_connection *ic,
struct rds_ib_recv_work *recv)
{
if (recv->r_ibinc) {
rds_inc_put(&recv->r_ibinc->ii_inc);
recv->r_ibinc = NULL;
}
if (recv->r_frag) {
ib_dma_unmap_sg(ic->i_cm_id->device, &recv->r_frag->f_sg, 1, DMA_FROM_DEVICE);
rds_ib_frag_free(ic, recv->r_frag);
recv->r_frag = NULL;
}
}
void rds_ib_recv_clear_ring(struct rds_ib_connection *ic)
{
u32 i;
for (i = 0; i < ic->i_recv_ring.w_nr; i++)
rds_ib_recv_clear_one(ic, &ic->i_recvs[i]);
}
static struct rds_ib_incoming *rds_ib_refill_one_inc(struct rds_ib_connection *ic,
gfp_t slab_mask)
{
struct rds_ib_incoming *ibinc;
struct list_head *cache_item;
int avail_allocs;
cache_item = rds_ib_recv_cache_get(&ic->i_cache_incs);
if (cache_item) {
ibinc = container_of(cache_item, struct rds_ib_incoming, ii_cache_entry);
} else {
avail_allocs = atomic_add_unless(&rds_ib_allocation,
1, rds_ib_sysctl_max_recv_allocation);
if (!avail_allocs) {
rds_ib_stats_inc(s_ib_rx_alloc_limit);
return NULL;
}
ibinc = kmem_cache_alloc(rds_ib_incoming_slab, slab_mask);
if (!ibinc) {
atomic_dec(&rds_ib_allocation);
return NULL;
}
}
INIT_LIST_HEAD(&ibinc->ii_frags);
rds_inc_init(&ibinc->ii_inc, ic->conn, ic->conn->c_faddr);
return ibinc;
}
static struct rds_page_frag *rds_ib_refill_one_frag(struct rds_ib_connection *ic,
gfp_t slab_mask, gfp_t page_mask)
{
struct rds_page_frag *frag;
struct list_head *cache_item;
int ret;
cache_item = rds_ib_recv_cache_get(&ic->i_cache_frags);
if (cache_item) {
frag = container_of(cache_item, struct rds_page_frag, f_cache_entry);
} else {
frag = kmem_cache_alloc(rds_ib_frag_slab, slab_mask);
if (!frag)
return NULL;
sg_init_table(&frag->f_sg, 1);
ret = rds_page_remainder_alloc(&frag->f_sg,
RDS_FRAG_SIZE, page_mask);
if (ret) {
kmem_cache_free(rds_ib_frag_slab, frag);
return NULL;
}
}
INIT_LIST_HEAD(&frag->f_item);
return frag;
}
static int rds_ib_recv_refill_one(struct rds_connection *conn,
struct rds_ib_recv_work *recv, gfp_t gfp)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct ib_sge *sge;
int ret = -ENOMEM;
gfp_t slab_mask = GFP_NOWAIT;
gfp_t page_mask = GFP_NOWAIT;
if (gfp & __GFP_DIRECT_RECLAIM) {
slab_mask = GFP_KERNEL;
page_mask = GFP_HIGHUSER;
}
if (!ic->i_cache_incs.ready)
rds_ib_cache_xfer_to_ready(&ic->i_cache_incs);
if (!ic->i_cache_frags.ready)
rds_ib_cache_xfer_to_ready(&ic->i_cache_frags);
if (!recv->r_ibinc) {
recv->r_ibinc = rds_ib_refill_one_inc(ic, slab_mask);
if (!recv->r_ibinc)
goto out;
}
WARN_ON(recv->r_frag);
recv->r_frag = rds_ib_refill_one_frag(ic, slab_mask, page_mask);
if (!recv->r_frag)
goto out;
ret = ib_dma_map_sg(ic->i_cm_id->device, &recv->r_frag->f_sg,
1, DMA_FROM_DEVICE);
WARN_ON(ret != 1);
sge = &recv->r_sge[0];
sge->addr = ic->i_recv_hdrs_dma + (recv - ic->i_recvs) * sizeof(struct rds_header);
sge->length = sizeof(struct rds_header);
sge = &recv->r_sge[1];
sge->addr = ib_sg_dma_address(ic->i_cm_id->device, &recv->r_frag->f_sg);
sge->length = ib_sg_dma_len(ic->i_cm_id->device, &recv->r_frag->f_sg);
ret = 0;
out:
return ret;
}
static int acquire_refill(struct rds_connection *conn)
{
return test_and_set_bit(RDS_RECV_REFILL, &conn->c_flags) == 0;
}
static void release_refill(struct rds_connection *conn)
{
clear_bit(RDS_RECV_REFILL, &conn->c_flags);
if (waitqueue_active(&conn->c_waitq))
wake_up_all(&conn->c_waitq);
}
void rds_ib_recv_refill(struct rds_connection *conn, int prefill, gfp_t gfp)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_ib_recv_work *recv;
struct ib_recv_wr *failed_wr;
unsigned int posted = 0;
int ret = 0;
bool can_wait = !!(gfp & __GFP_DIRECT_RECLAIM);
u32 pos;
if (!acquire_refill(conn))
return;
while ((prefill || rds_conn_up(conn)) &&
rds_ib_ring_alloc(&ic->i_recv_ring, 1, &pos)) {
if (pos >= ic->i_recv_ring.w_nr) {
printk(KERN_NOTICE "Argh - ring alloc returned pos=%u\n",
pos);
break;
}
recv = &ic->i_recvs[pos];
ret = rds_ib_recv_refill_one(conn, recv, gfp);
if (ret) {
break;
}
ret = ib_post_recv(ic->i_cm_id->qp, &recv->r_wr, &failed_wr);
rdsdebug("recv %p ibinc %p page %p addr %lu ret %d\n", recv,
recv->r_ibinc, sg_page(&recv->r_frag->f_sg),
(long) ib_sg_dma_address(
ic->i_cm_id->device,
&recv->r_frag->f_sg),
ret);
if (ret) {
rds_ib_conn_error(conn, "recv post on "
"%pI4 returned %d, disconnecting and "
"reconnecting\n", &conn->c_faddr,
ret);
break;
}
posted++;
}
if (ic->i_flowctl && posted)
rds_ib_advertise_credits(conn, posted);
if (ret)
rds_ib_ring_unalloc(&ic->i_recv_ring, 1);
release_refill(conn);
if (rds_conn_up(conn) &&
((can_wait && rds_ib_ring_low(&ic->i_recv_ring)) ||
rds_ib_ring_empty(&ic->i_recv_ring))) {
queue_delayed_work(rds_wq, &conn->c_recv_w, 1);
}
}
static void rds_ib_recv_cache_put(struct list_head *new_item,
struct rds_ib_refill_cache *cache)
{
unsigned long flags;
struct list_head *old, *chpfirst;
local_irq_save(flags);
chpfirst = __this_cpu_read(cache->percpu->first);
if (!chpfirst)
INIT_LIST_HEAD(new_item);
else
list_add_tail(new_item, chpfirst);
__this_cpu_write(cache->percpu->first, new_item);
__this_cpu_inc(cache->percpu->count);
if (__this_cpu_read(cache->percpu->count) < RDS_IB_RECYCLE_BATCH_COUNT)
goto end;
do {
old = xchg(&cache->xfer, NULL);
if (old)
list_splice_entire_tail(old, chpfirst);
old = cmpxchg(&cache->xfer, NULL, chpfirst);
} while (old);
__this_cpu_write(cache->percpu->first, NULL);
__this_cpu_write(cache->percpu->count, 0);
end:
local_irq_restore(flags);
}
static struct list_head *rds_ib_recv_cache_get(struct rds_ib_refill_cache *cache)
{
struct list_head *head = cache->ready;
if (head) {
if (!list_empty(head)) {
cache->ready = head->next;
list_del_init(head);
} else
cache->ready = NULL;
}
return head;
}
int rds_ib_inc_copy_to_user(struct rds_incoming *inc, struct iov_iter *to)
{
struct rds_ib_incoming *ibinc;
struct rds_page_frag *frag;
unsigned long to_copy;
unsigned long frag_off = 0;
int copied = 0;
int ret;
u32 len;
ibinc = container_of(inc, struct rds_ib_incoming, ii_inc);
frag = list_entry(ibinc->ii_frags.next, struct rds_page_frag, f_item);
len = be32_to_cpu(inc->i_hdr.h_len);
while (iov_iter_count(to) && copied < len) {
if (frag_off == RDS_FRAG_SIZE) {
frag = list_entry(frag->f_item.next,
struct rds_page_frag, f_item);
frag_off = 0;
}
to_copy = min_t(unsigned long, iov_iter_count(to),
RDS_FRAG_SIZE - frag_off);
to_copy = min_t(unsigned long, to_copy, len - copied);
rds_stats_add(s_copy_to_user, to_copy);
ret = copy_page_to_iter(sg_page(&frag->f_sg),
frag->f_sg.offset + frag_off,
to_copy,
to);
if (ret != to_copy)
return -EFAULT;
frag_off += to_copy;
copied += to_copy;
}
return copied;
}
void rds_ib_recv_init_ack(struct rds_ib_connection *ic)
{
struct ib_send_wr *wr = &ic->i_ack_wr;
struct ib_sge *sge = &ic->i_ack_sge;
sge->addr = ic->i_ack_dma;
sge->length = sizeof(struct rds_header);
sge->lkey = ic->i_pd->local_dma_lkey;
wr->sg_list = sge;
wr->num_sge = 1;
wr->opcode = IB_WR_SEND;
wr->wr_id = RDS_IB_ACK_WR_ID;
wr->send_flags = IB_SEND_SIGNALED | IB_SEND_SOLICITED;
}
void rds_ib_set_ack(struct rds_ib_connection *ic, u64 seq, int ack_required)
{
unsigned long flags;
spin_lock_irqsave(&ic->i_ack_lock, flags);
ic->i_ack_next = seq;
if (ack_required)
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
spin_unlock_irqrestore(&ic->i_ack_lock, flags);
}
static u64 rds_ib_get_ack(struct rds_ib_connection *ic)
{
unsigned long flags;
u64 seq;
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
spin_lock_irqsave(&ic->i_ack_lock, flags);
seq = ic->i_ack_next;
spin_unlock_irqrestore(&ic->i_ack_lock, flags);
return seq;
}
void rds_ib_set_ack(struct rds_ib_connection *ic, u64 seq, int ack_required)
{
atomic64_set(&ic->i_ack_next, seq);
if (ack_required) {
smp_mb__before_atomic();
set_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
}
}
static u64 rds_ib_get_ack(struct rds_ib_connection *ic)
{
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
smp_mb__after_atomic();
return atomic64_read(&ic->i_ack_next);
}
static void rds_ib_send_ack(struct rds_ib_connection *ic, unsigned int adv_credits)
{
struct rds_header *hdr = ic->i_ack;
struct ib_send_wr *failed_wr;
u64 seq;
int ret;
seq = rds_ib_get_ack(ic);
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
rds_ib_stats_inc(s_ib_ack_send_failure);
rds_ib_conn_error(ic->conn, "sending ack failed\n");
} else
rds_ib_stats_inc(s_ib_ack_sent);
}
void rds_ib_attempt_ack(struct rds_ib_connection *ic)
{
unsigned int adv_credits;
if (!test_bit(IB_ACK_REQUESTED, &ic->i_ack_flags))
return;
if (test_and_set_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags)) {
rds_ib_stats_inc(s_ib_ack_send_delayed);
return;
}
if (!rds_ib_send_grab_credits(ic, 1, &adv_credits, 0, RDS_MAX_ADV_CREDIT)) {
rds_ib_stats_inc(s_ib_tx_throttle);
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
return;
}
clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags);
rds_ib_send_ack(ic, adv_credits);
}
void rds_ib_ack_send_complete(struct rds_ib_connection *ic)
{
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
rds_ib_attempt_ack(ic);
}
u64 rds_ib_piggyb_ack(struct rds_ib_connection *ic)
{
if (test_and_clear_bit(IB_ACK_REQUESTED, &ic->i_ack_flags))
rds_ib_stats_inc(s_ib_ack_send_piggybacked);
return rds_ib_get_ack(ic);
}
static void rds_ib_cong_recv(struct rds_connection *conn,
struct rds_ib_incoming *ibinc)
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
if (be32_to_cpu(ibinc->ii_inc.i_hdr.h_len) != RDS_CONG_MAP_BYTES)
return;
map = conn->c_fcong;
map_page = 0;
map_off = 0;
frag = list_entry(ibinc->ii_frags.next, struct rds_page_frag, f_item);
frag_off = 0;
copied = 0;
while (copied < RDS_CONG_MAP_BYTES) {
uint64_t *src, *dst;
unsigned int k;
to_copy = min(RDS_FRAG_SIZE - frag_off, PAGE_SIZE - map_off);
BUG_ON(to_copy & 7);
addr = kmap_atomic(sg_page(&frag->f_sg));
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
static void rds_ib_process_recv(struct rds_connection *conn,
struct rds_ib_recv_work *recv, u32 data_len,
struct rds_ib_ack_state *state)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_ib_incoming *ibinc = ic->i_ibinc;
struct rds_header *ihdr, *hdr;
rdsdebug("ic %p ibinc %p recv %p byte len %u\n", ic, ibinc, recv,
data_len);
if (data_len < sizeof(struct rds_header)) {
rds_ib_conn_error(conn, "incoming message "
"from %pI4 didn't include a "
"header, disconnecting and "
"reconnecting\n",
&conn->c_faddr);
return;
}
data_len -= sizeof(struct rds_header);
ihdr = &ic->i_recv_hdrs[recv - ic->i_recvs];
if (!rds_message_verify_checksum(ihdr)) {
rds_ib_conn_error(conn, "incoming message "
"from %pI4 has corrupted header - "
"forcing a reconnect\n",
&conn->c_faddr);
rds_stats_inc(s_recv_drop_bad_checksum);
return;
}
state->ack_recv = be64_to_cpu(ihdr->h_ack);
state->ack_recv_valid = 1;
if (ihdr->h_credit)
rds_ib_send_add_credits(conn, ihdr->h_credit);
if (ihdr->h_sport == 0 && ihdr->h_dport == 0 && data_len == 0) {
rds_ib_stats_inc(s_ib_ack_received);
rds_ib_frag_free(ic, recv->r_frag);
recv->r_frag = NULL;
return;
}
if (!ibinc) {
ibinc = recv->r_ibinc;
recv->r_ibinc = NULL;
ic->i_ibinc = ibinc;
hdr = &ibinc->ii_inc.i_hdr;
memcpy(hdr, ihdr, sizeof(*hdr));
ic->i_recv_data_rem = be32_to_cpu(hdr->h_len);
rdsdebug("ic %p ibinc %p rem %u flag 0x%x\n", ic, ibinc,
ic->i_recv_data_rem, hdr->h_flags);
} else {
hdr = &ibinc->ii_inc.i_hdr;
if (hdr->h_sequence != ihdr->h_sequence ||
hdr->h_len != ihdr->h_len ||
hdr->h_sport != ihdr->h_sport ||
hdr->h_dport != ihdr->h_dport) {
rds_ib_conn_error(conn,
"fragment header mismatch; forcing reconnect\n");
return;
}
}
list_add_tail(&recv->r_frag->f_item, &ibinc->ii_frags);
recv->r_frag = NULL;
if (ic->i_recv_data_rem > RDS_FRAG_SIZE)
ic->i_recv_data_rem -= RDS_FRAG_SIZE;
else {
ic->i_recv_data_rem = 0;
ic->i_ibinc = NULL;
if (ibinc->ii_inc.i_hdr.h_flags == RDS_FLAG_CONG_BITMAP)
rds_ib_cong_recv(conn, ibinc);
else {
rds_recv_incoming(conn, conn->c_faddr, conn->c_laddr,
&ibinc->ii_inc, GFP_ATOMIC);
state->ack_next = be64_to_cpu(hdr->h_sequence);
state->ack_next_valid = 1;
}
if (hdr->h_flags & RDS_FLAG_ACK_REQUIRED) {
rds_stats_inc(s_recv_ack_required);
state->ack_required = 1;
}
rds_inc_put(&ibinc->ii_inc);
}
}
void rds_ib_recv_cqe_handler(struct rds_ib_connection *ic,
struct ib_wc *wc,
struct rds_ib_ack_state *state)
{
struct rds_connection *conn = ic->conn;
struct rds_ib_recv_work *recv;
rdsdebug("wc wr_id 0x%llx status %u (%s) byte_len %u imm_data %u\n",
(unsigned long long)wc->wr_id, wc->status,
ib_wc_status_msg(wc->status), wc->byte_len,
be32_to_cpu(wc->ex.imm_data));
rds_ib_stats_inc(s_ib_rx_cq_event);
recv = &ic->i_recvs[rds_ib_ring_oldest(&ic->i_recv_ring)];
ib_dma_unmap_sg(ic->i_cm_id->device, &recv->r_frag->f_sg, 1,
DMA_FROM_DEVICE);
if (wc->status == IB_WC_SUCCESS) {
rds_ib_process_recv(conn, recv, wc->byte_len, state);
} else {
if (rds_conn_up(conn) || rds_conn_connecting(conn))
rds_ib_conn_error(conn, "recv completion on %pI4 had status %u (%s), disconnecting and reconnecting\n",
&conn->c_faddr,
wc->status,
ib_wc_status_msg(wc->status));
}
if (recv->r_frag) {
rds_ib_frag_free(ic, recv->r_frag);
recv->r_frag = NULL;
}
rds_ib_ring_free(&ic->i_recv_ring, 1);
if (rds_ib_ring_empty(&ic->i_recv_ring))
rds_ib_stats_inc(s_ib_rx_ring_empty);
if (rds_ib_ring_low(&ic->i_recv_ring))
rds_ib_recv_refill(conn, 0, GFP_NOWAIT);
}
int rds_ib_recv(struct rds_connection *conn)
{
struct rds_ib_connection *ic = conn->c_transport_data;
int ret = 0;
rdsdebug("conn %p\n", conn);
if (rds_conn_up(conn)) {
rds_ib_attempt_ack(ic);
rds_ib_recv_refill(conn, 0, GFP_KERNEL);
}
return ret;
}
int rds_ib_recv_init(void)
{
struct sysinfo si;
int ret = -ENOMEM;
si_meminfo(&si);
rds_ib_sysctl_max_recv_allocation = si.totalram / 3 * PAGE_SIZE / RDS_FRAG_SIZE;
rds_ib_incoming_slab = kmem_cache_create("rds_ib_incoming",
sizeof(struct rds_ib_incoming),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!rds_ib_incoming_slab)
goto out;
rds_ib_frag_slab = kmem_cache_create("rds_ib_frag",
sizeof(struct rds_page_frag),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!rds_ib_frag_slab) {
kmem_cache_destroy(rds_ib_incoming_slab);
rds_ib_incoming_slab = NULL;
} else
ret = 0;
out:
return ret;
}
void rds_ib_recv_exit(void)
{
kmem_cache_destroy(rds_ib_incoming_slab);
kmem_cache_destroy(rds_ib_frag_slab);
}
