static void tipc_bclink_lock(void)
{
spin_lock_bh(&bclink->lock);
}
static void tipc_bclink_unlock(void)
{
struct tipc_node *node = NULL;
if (likely(!bclink->flags)) {
spin_unlock_bh(&bclink->lock);
return;
}
if (bclink->flags & TIPC_BCLINK_RESET) {
bclink->flags &= ~TIPC_BCLINK_RESET;
node = tipc_bclink_retransmit_to();
}
spin_unlock_bh(&bclink->lock);
if (node)
tipc_link_reset_all(node);
}
uint tipc_bclink_get_mtu(void)
{
return MAX_PKT_DEFAULT_MCAST;
}
void tipc_bclink_set_flags(unsigned int flags)
{
bclink->flags |= flags;
}
static u32 bcbuf_acks(struct sk_buff *buf)
{
return (u32)(unsigned long)TIPC_SKB_CB(buf)->handle;
}
static void bcbuf_set_acks(struct sk_buff *buf, u32 acks)
{
TIPC_SKB_CB(buf)->handle = (void *)(unsigned long)acks;
}
static void bcbuf_decr_acks(struct sk_buff *buf)
{
bcbuf_set_acks(buf, bcbuf_acks(buf) - 1);
}
void tipc_bclink_add_node(u32 addr)
{
tipc_bclink_lock();
tipc_nmap_add(&bclink->bcast_nodes, addr);
tipc_bclink_unlock();
}
void tipc_bclink_remove_node(u32 addr)
{
tipc_bclink_lock();
tipc_nmap_remove(&bclink->bcast_nodes, addr);
tipc_bclink_unlock();
}
static void bclink_set_last_sent(void)
{
if (bcl->next_out)
bcl->fsm_msg_cnt = mod(buf_seqno(bcl->next_out) - 1);
else
bcl->fsm_msg_cnt = mod(bcl->next_out_no - 1);
}
u32 tipc_bclink_get_last_sent(void)
{
return bcl->fsm_msg_cnt;
}
static void bclink_update_last_sent(struct tipc_node *node, u32 seqno)
{
node->bclink.last_sent = less_eq(node->bclink.last_sent, seqno) ?
seqno : node->bclink.last_sent;
}
struct tipc_node *tipc_bclink_retransmit_to(void)
{
return bclink->retransmit_to;
}
static void bclink_retransmit_pkt(u32 after, u32 to)
{
struct sk_buff *buf;
buf = bcl->first_out;
while (buf && less_eq(buf_seqno(buf), after))
buf = buf->next;
tipc_link_retransmit(bcl, buf, mod(to - after));
}
void tipc_bclink_wakeup_users(void)
{
while (skb_queue_len(&bclink->link.waiting_sks))
tipc_sk_rcv(skb_dequeue(&bclink->link.waiting_sks));
}
void tipc_bclink_acknowledge(struct tipc_node *n_ptr, u32 acked)
{
struct sk_buff *crs;
struct sk_buff *next;
unsigned int released = 0;
tipc_bclink_lock();
crs = bcl->first_out;
if (!crs)
goto exit;
if (acked == INVALID_LINK_SEQ) {
if (bclink->bcast_nodes.count)
acked = bcl->fsm_msg_cnt;
else
acked = bcl->next_out_no;
} else {
if (less(acked, buf_seqno(crs)) ||
less(bcl->fsm_msg_cnt, acked) ||
less_eq(acked, n_ptr->bclink.acked))
goto exit;
}
while (crs && less_eq(buf_seqno(crs), n_ptr->bclink.acked))
crs = crs->next;
while (crs && less_eq(buf_seqno(crs), acked)) {
next = crs->next;
if (crs != bcl->next_out)
bcbuf_decr_acks(crs);
else {
bcbuf_set_acks(crs, 0);
bcl->next_out = next;
bclink_set_last_sent();
}
if (bcbuf_acks(crs) == 0) {
bcl->first_out = next;
bcl->out_queue_size--;
kfree_skb(crs);
released = 1;
}
crs = next;
}
n_ptr->bclink.acked = acked;
if (unlikely(bcl->next_out)) {
tipc_link_push_queue(bcl);
bclink_set_last_sent();
}
if (unlikely(released && !skb_queue_empty(&bcl->waiting_sks)))
n_ptr->action_flags |= TIPC_WAKEUP_BCAST_USERS;
exit:
tipc_bclink_unlock();
}
void tipc_bclink_update_link_state(struct tipc_node *n_ptr, u32 last_sent)
{
struct sk_buff *buf;
if (less_eq(last_sent, n_ptr->bclink.last_in))
return;
bclink_update_last_sent(n_ptr, last_sent);
if (n_ptr->bclink.last_sent == n_ptr->bclink.last_in)
return;
if ((++n_ptr->bclink.oos_state) == 1) {
if (n_ptr->bclink.deferred_size < (TIPC_MIN_LINK_WIN / 2))
return;
n_ptr->bclink.oos_state++;
}
if (n_ptr->bclink.oos_state & 0x1)
return;
buf = tipc_buf_acquire(INT_H_SIZE);
if (buf) {
struct tipc_msg *msg = buf_msg(buf);
tipc_msg_init(msg, BCAST_PROTOCOL, STATE_MSG,
INT_H_SIZE, n_ptr->addr);
msg_set_non_seq(msg, 1);
msg_set_mc_netid(msg, tipc_net_id);
msg_set_bcast_ack(msg, n_ptr->bclink.last_in);
msg_set_bcgap_after(msg, n_ptr->bclink.last_in);
msg_set_bcgap_to(msg, n_ptr->bclink.deferred_head
? buf_seqno(n_ptr->bclink.deferred_head) - 1
: n_ptr->bclink.last_sent);
tipc_bclink_lock();
tipc_bearer_send(MAX_BEARERS, buf, NULL);
bcl->stats.sent_nacks++;
tipc_bclink_unlock();
kfree_skb(buf);
n_ptr->bclink.oos_state++;
}
}
static void bclink_peek_nack(struct tipc_msg *msg)
{
struct tipc_node *n_ptr = tipc_node_find(msg_destnode(msg));
if (unlikely(!n_ptr))
return;
tipc_node_lock(n_ptr);
if (n_ptr->bclink.recv_permitted &&
(n_ptr->bclink.last_in != n_ptr->bclink.last_sent) &&
(n_ptr->bclink.last_in == msg_bcgap_after(msg)))
n_ptr->bclink.oos_state = 2;
tipc_node_unlock(n_ptr);
}
int tipc_bclink_xmit(struct sk_buff *buf)
{
int rc = 0;
int bc = 0;
struct sk_buff *clbuf;
clbuf = tipc_msg_reassemble(buf);
if (unlikely(!clbuf)) {
kfree_skb_list(buf);
return -EHOSTUNREACH;
}
if (likely(bclink)) {
tipc_bclink_lock();
if (likely(bclink->bcast_nodes.count)) {
rc = __tipc_link_xmit(bcl, buf);
if (likely(!rc)) {
bclink_set_last_sent();
bcl->stats.queue_sz_counts++;
bcl->stats.accu_queue_sz += bcl->out_queue_size;
}
bc = 1;
}
tipc_bclink_unlock();
}
if (unlikely(!bc))
kfree_skb_list(buf);
if (likely(!rc))
tipc_sk_mcast_rcv(clbuf);
else
kfree_skb(clbuf);
return rc;
}
static void bclink_accept_pkt(struct tipc_node *node, u32 seqno)
{
bclink_update_last_sent(node, seqno);
node->bclink.last_in = seqno;
node->bclink.oos_state = 0;
bcl->stats.recv_info++;
if (((seqno - tipc_own_addr) % TIPC_MIN_LINK_WIN) == 0) {
tipc_link_proto_xmit(node->active_links[node->addr & 1],
STATE_MSG, 0, 0, 0, 0, 0);
bcl->stats.sent_acks++;
}
}
void tipc_bclink_rcv(struct sk_buff *buf)
{
struct tipc_msg *msg = buf_msg(buf);
struct tipc_node *node;
u32 next_in;
u32 seqno;
int deferred = 0;
if (msg_mc_netid(msg) != tipc_net_id)
goto exit;
node = tipc_node_find(msg_prevnode(msg));
if (unlikely(!node))
goto exit;
tipc_node_lock(node);
if (unlikely(!node->bclink.recv_permitted))
goto unlock;
if (unlikely(msg_user(msg) == BCAST_PROTOCOL)) {
if (msg_type(msg) != STATE_MSG)
goto unlock;
if (msg_destnode(msg) == tipc_own_addr) {
tipc_bclink_acknowledge(node, msg_bcast_ack(msg));
tipc_node_unlock(node);
tipc_bclink_lock();
bcl->stats.recv_nacks++;
bclink->retransmit_to = node;
bclink_retransmit_pkt(msg_bcgap_after(msg),
msg_bcgap_to(msg));
tipc_bclink_unlock();
} else {
tipc_node_unlock(node);
bclink_peek_nack(msg);
}
goto exit;
}
seqno = msg_seqno(msg);
next_in = mod(node->bclink.last_in + 1);
if (likely(seqno == next_in)) {
receive:
if (likely(msg_isdata(msg))) {
tipc_bclink_lock();
bclink_accept_pkt(node, seqno);
tipc_bclink_unlock();
tipc_node_unlock(node);
if (likely(msg_mcast(msg)))
tipc_sk_mcast_rcv(buf);
else
kfree_skb(buf);
} else if (msg_user(msg) == MSG_BUNDLER) {
tipc_bclink_lock();
bclink_accept_pkt(node, seqno);
bcl->stats.recv_bundles++;
bcl->stats.recv_bundled += msg_msgcnt(msg);
tipc_bclink_unlock();
tipc_node_unlock(node);
tipc_link_bundle_rcv(buf);
} else if (msg_user(msg) == MSG_FRAGMENTER) {
tipc_buf_append(&node->bclink.reasm_buf, &buf);
if (unlikely(!buf && !node->bclink.reasm_buf))
goto unlock;
tipc_bclink_lock();
bclink_accept_pkt(node, seqno);
bcl->stats.recv_fragments++;
if (buf) {
bcl->stats.recv_fragmented++;
msg = buf_msg(buf);
tipc_bclink_unlock();
goto receive;
}
tipc_bclink_unlock();
tipc_node_unlock(node);
} else if (msg_user(msg) == NAME_DISTRIBUTOR) {
tipc_bclink_lock();
bclink_accept_pkt(node, seqno);
tipc_bclink_unlock();
tipc_node_unlock(node);
tipc_named_rcv(buf);
} else {
tipc_bclink_lock();
bclink_accept_pkt(node, seqno);
tipc_bclink_unlock();
tipc_node_unlock(node);
kfree_skb(buf);
}
buf = NULL;
tipc_node_lock(node);
if (unlikely(!tipc_node_is_up(node)))
goto unlock;
if (node->bclink.last_in == node->bclink.last_sent)
goto unlock;
if (!node->bclink.deferred_head) {
node->bclink.oos_state = 1;
goto unlock;
}
msg = buf_msg(node->bclink.deferred_head);
seqno = msg_seqno(msg);
next_in = mod(next_in + 1);
if (seqno != next_in)
goto unlock;
buf = node->bclink.deferred_head;
node->bclink.deferred_head = buf->next;
buf->next = NULL;
node->bclink.deferred_size--;
goto receive;
}
if (less(next_in, seqno)) {
deferred = tipc_link_defer_pkt(&node->bclink.deferred_head,
&node->bclink.deferred_tail,
buf);
node->bclink.deferred_size += deferred;
bclink_update_last_sent(node, seqno);
buf = NULL;
}
tipc_bclink_lock();
if (deferred)
bcl->stats.deferred_recv++;
else
bcl->stats.duplicates++;
tipc_bclink_unlock();
unlock:
tipc_node_unlock(node);
exit:
kfree_skb(buf);
}
u32 tipc_bclink_acks_missing(struct tipc_node *n_ptr)
{
return (n_ptr->bclink.recv_permitted &&
(tipc_bclink_get_last_sent() != n_ptr->bclink.acked));
}
static int tipc_bcbearer_send(struct sk_buff *buf, struct tipc_bearer *unused1,
struct tipc_media_addr *unused2)
{
int bp_index;
struct tipc_msg *msg = buf_msg(buf);
if (likely(!msg_non_seq(buf_msg(buf)))) {
bcbuf_set_acks(buf, bclink->bcast_nodes.count);
msg_set_non_seq(msg, 1);
msg_set_mc_netid(msg, tipc_net_id);
bcl->stats.sent_info++;
if (WARN_ON(!bclink->bcast_nodes.count)) {
dump_stack();
return 0;
}
}
bcbearer->remains = bclink->bcast_nodes;
for (bp_index = 0; bp_index < MAX_BEARERS; bp_index++) {
struct tipc_bearer *p = bcbearer->bpairs[bp_index].primary;
struct tipc_bearer *s = bcbearer->bpairs[bp_index].secondary;
struct tipc_bearer *bp[2] = {p, s};
struct tipc_bearer *b = bp[msg_link_selector(msg)];
struct sk_buff *tbuf;
if (!p)
break;
if (!b)
b = p;
tipc_nmap_diff(&bcbearer->remains, &b->nodes,
&bcbearer->remains_new);
if (bcbearer->remains_new.count == bcbearer->remains.count)
continue;
if (bp_index == 0) {
tipc_bearer_send(b->identity, buf, &b->bcast_addr);
} else {
tbuf = pskb_copy_for_clone(buf, GFP_ATOMIC);
if (!tbuf)
break;
tipc_bearer_send(b->identity, tbuf, &b->bcast_addr);
kfree_skb(tbuf);
}
if (bcbearer->remains_new.count == 0)
break;
bcbearer->remains = bcbearer->remains_new;
}
return 0;
}
void tipc_bcbearer_sort(struct tipc_node_map *nm_ptr, u32 node, bool action)
{
struct tipc_bcbearer_pair *bp_temp = bcbearer->bpairs_temp;
struct tipc_bcbearer_pair *bp_curr;
struct tipc_bearer *b;
int b_index;
int pri;
tipc_bclink_lock();
if (action)
tipc_nmap_add(nm_ptr, node);
else
tipc_nmap_remove(nm_ptr, node);
memset(bp_temp, 0, sizeof(bcbearer->bpairs_temp));
rcu_read_lock();
for (b_index = 0; b_index < MAX_BEARERS; b_index++) {
b = rcu_dereference_rtnl(bearer_list[b_index]);
if (!b || !b->nodes.count)
continue;
if (!bp_temp[b->priority].primary)
bp_temp[b->priority].primary = b;
else
bp_temp[b->priority].secondary = b;
}
rcu_read_unlock();
bp_curr = bcbearer->bpairs;
memset(bcbearer->bpairs, 0, sizeof(bcbearer->bpairs));
for (pri = TIPC_MAX_LINK_PRI; pri >= 0; pri--) {
if (!bp_temp[pri].primary)
continue;
bp_curr->primary = bp_temp[pri].primary;
if (bp_temp[pri].secondary) {
if (tipc_nmap_equal(&bp_temp[pri].primary->nodes,
&bp_temp[pri].secondary->nodes)) {
bp_curr->secondary = bp_temp[pri].secondary;
} else {
bp_curr++;
bp_curr->primary = bp_temp[pri].secondary;
}
}
bp_curr++;
}
tipc_bclink_unlock();
}
int tipc_bclink_stats(char *buf, const u32 buf_size)
{
int ret;
struct tipc_stats *s;
if (!bcl)
return 0;
tipc_bclink_lock();
s = &bcl->stats;
ret = tipc_snprintf(buf, buf_size, "Link <%s>\n"
" Window:%u packets\n",
bcl->name, bcl->queue_limit[0]);
ret += tipc_snprintf(buf + ret, buf_size - ret,
" RX packets:%u fragments:%u/%u bundles:%u/%u\n",
s->recv_info, s->recv_fragments,
s->recv_fragmented, s->recv_bundles,
s->recv_bundled);
ret += tipc_snprintf(buf + ret, buf_size - ret,
" TX packets:%u fragments:%u/%u bundles:%u/%u\n",
s->sent_info, s->sent_fragments,
s->sent_fragmented, s->sent_bundles,
s->sent_bundled);
ret += tipc_snprintf(buf + ret, buf_size - ret,
" RX naks:%u defs:%u dups:%u\n",
s->recv_nacks, s->deferred_recv, s->duplicates);
ret += tipc_snprintf(buf + ret, buf_size - ret,
" TX naks:%u acks:%u dups:%u\n",
s->sent_nacks, s->sent_acks, s->retransmitted);
ret += tipc_snprintf(buf + ret, buf_size - ret,
" Congestion link:%u Send queue max:%u avg:%u\n",
s->link_congs, s->max_queue_sz,
s->queue_sz_counts ?
(s->accu_queue_sz / s->queue_sz_counts) : 0);
tipc_bclink_unlock();
return ret;
}
int tipc_bclink_reset_stats(void)
{
if (!bcl)
return -ENOPROTOOPT;
tipc_bclink_lock();
memset(&bcl->stats, 0, sizeof(bcl->stats));
tipc_bclink_unlock();
return 0;
}
int tipc_bclink_set_queue_limits(u32 limit)
{
if (!bcl)
return -ENOPROTOOPT;
if ((limit < TIPC_MIN_LINK_WIN) || (limit > TIPC_MAX_LINK_WIN))
return -EINVAL;
tipc_bclink_lock();
tipc_link_set_queue_limits(bcl, limit);
tipc_bclink_unlock();
return 0;
}
int tipc_bclink_init(void)
{
bcbearer = kzalloc(sizeof(*bcbearer), GFP_ATOMIC);
if (!bcbearer)
return -ENOMEM;
bclink = kzalloc(sizeof(*bclink), GFP_ATOMIC);
if (!bclink) {
kfree(bcbearer);
return -ENOMEM;
}
bcl = &bclink->link;
bcbearer->bearer.media = &bcbearer->media;
bcbearer->media.send_msg = tipc_bcbearer_send;
sprintf(bcbearer->media.name, "tipc-broadcast");
spin_lock_init(&bclink->lock);
__skb_queue_head_init(&bcl->waiting_sks);
bcl->next_out_no = 1;
spin_lock_init(&bclink->node.lock);
__skb_queue_head_init(&bclink->node.waiting_sks);
bcl->owner = &bclink->node;
bcl->max_pkt = MAX_PKT_DEFAULT_MCAST;
tipc_link_set_queue_limits(bcl, BCLINK_WIN_DEFAULT);
bcl->bearer_id = MAX_BEARERS;
rcu_assign_pointer(bearer_list[MAX_BEARERS], &bcbearer->bearer);
bcl->state = WORKING_WORKING;
strlcpy(bcl->name, tipc_bclink_name, TIPC_MAX_LINK_NAME);
return 0;
}
void tipc_bclink_stop(void)
{
tipc_bclink_lock();
tipc_link_purge_queues(bcl);
tipc_bclink_unlock();
RCU_INIT_POINTER(bearer_list[BCBEARER], NULL);
synchronize_net();
kfree(bcbearer);
kfree(bclink);
}
static void tipc_nmap_add(struct tipc_node_map *nm_ptr, u32 node)
{
int n = tipc_node(node);
int w = n / WSIZE;
u32 mask = (1 << (n % WSIZE));
if ((nm_ptr->map[w] & mask) == 0) {
nm_ptr->count++;
nm_ptr->map[w] |= mask;
}
}
static void tipc_nmap_remove(struct tipc_node_map *nm_ptr, u32 node)
{
int n = tipc_node(node);
int w = n / WSIZE;
u32 mask = (1 << (n % WSIZE));
if ((nm_ptr->map[w] & mask) != 0) {
nm_ptr->map[w] &= ~mask;
nm_ptr->count--;
}
}
static void tipc_nmap_diff(struct tipc_node_map *nm_a,
struct tipc_node_map *nm_b,
struct tipc_node_map *nm_diff)
{
int stop = ARRAY_SIZE(nm_a->map);
int w;
int b;
u32 map;
memset(nm_diff, 0, sizeof(*nm_diff));
for (w = 0; w < stop; w++) {
map = nm_a->map[w] ^ (nm_a->map[w] & nm_b->map[w]);
nm_diff->map[w] = map;
if (map != 0) {
for (b = 0 ; b < WSIZE; b++) {
if (map & (1 << b))
nm_diff->count++;
}
}
}
}
void tipc_port_list_add(struct tipc_port_list *pl_ptr, u32 port)
{
struct tipc_port_list *item = pl_ptr;
int i;
int item_sz = PLSIZE;
int cnt = pl_ptr->count;
for (; ; cnt -= item_sz, item = item->next) {
if (cnt < PLSIZE)
item_sz = cnt;
for (i = 0; i < item_sz; i++)
if (item->ports[i] == port)
return;
if (i < PLSIZE) {
item->ports[i] = port;
pl_ptr->count++;
return;
}
if (!item->next) {
item->next = kmalloc(sizeof(*item), GFP_ATOMIC);
if (!item->next) {
pr_warn("Incomplete multicast delivery, no memory\n");
return;
}
item->next->next = NULL;
}
}
}
void tipc_port_list_free(struct tipc_port_list *pl_ptr)
{
struct tipc_port_list *item;
struct tipc_port_list *next;
for (item = pl_ptr->next; item; item = next) {
next = item->next;
kfree(item);
}
}
