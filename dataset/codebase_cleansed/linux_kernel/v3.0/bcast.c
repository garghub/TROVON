static u32 buf_seqno(struct sk_buff *buf)
{
return msg_seqno(buf_msg(buf));
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
static void bclink_set_gap(struct tipc_node *n_ptr)
{
struct sk_buff *buf = n_ptr->bclink.deferred_head;
n_ptr->bclink.gap_after = n_ptr->bclink.gap_to =
mod(n_ptr->bclink.last_in);
if (unlikely(buf != NULL))
n_ptr->bclink.gap_to = mod(buf_seqno(buf) - 1);
}
static int bclink_ack_allowed(u32 n)
{
return (n % TIPC_MIN_LINK_WIN) == tipc_own_tag;
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
void tipc_bclink_acknowledge(struct tipc_node *n_ptr, u32 acked)
{
struct sk_buff *crs;
struct sk_buff *next;
unsigned int released = 0;
if (less_eq(acked, n_ptr->bclink.acked))
return;
spin_lock_bh(&bc_lock);
crs = bcl->first_out;
while (crs && less_eq(buf_seqno(crs), n_ptr->bclink.acked))
crs = crs->next;
while (crs && less_eq(buf_seqno(crs), acked)) {
next = crs->next;
bcbuf_decr_acks(crs);
if (bcbuf_acks(crs) == 0) {
bcl->first_out = next;
bcl->out_queue_size--;
buf_discard(crs);
released = 1;
}
crs = next;
}
n_ptr->bclink.acked = acked;
if (unlikely(bcl->next_out)) {
tipc_link_push_queue(bcl);
bclink_set_last_sent();
}
if (unlikely(released && !list_empty(&bcl->waiting_ports)))
tipc_link_wakeup_ports(bcl, 0);
spin_unlock_bh(&bc_lock);
}
static void bclink_send_ack(struct tipc_node *n_ptr)
{
struct link *l_ptr = n_ptr->active_links[n_ptr->addr & 1];
if (l_ptr != NULL)
tipc_link_send_proto_msg(l_ptr, STATE_MSG, 0, 0, 0, 0, 0);
}
static void bclink_send_nack(struct tipc_node *n_ptr)
{
struct sk_buff *buf;
struct tipc_msg *msg;
if (!less(n_ptr->bclink.gap_after, n_ptr->bclink.gap_to))
return;
buf = tipc_buf_acquire(INT_H_SIZE);
if (buf) {
msg = buf_msg(buf);
tipc_msg_init(msg, BCAST_PROTOCOL, STATE_MSG,
INT_H_SIZE, n_ptr->addr);
msg_set_non_seq(msg, 1);
msg_set_mc_netid(msg, tipc_net_id);
msg_set_bcast_ack(msg, mod(n_ptr->bclink.last_in));
msg_set_bcgap_after(msg, n_ptr->bclink.gap_after);
msg_set_bcgap_to(msg, n_ptr->bclink.gap_to);
msg_set_bcast_tag(msg, tipc_own_tag);
if (tipc_bearer_send(&bcbearer->bearer, buf, NULL)) {
bcl->stats.sent_nacks++;
buf_discard(buf);
} else {
tipc_bearer_schedule(bcl->b_ptr, bcl);
bcl->proto_msg_queue = buf;
bcl->stats.bearer_congs++;
}
n_ptr->bclink.nack_sync = tipc_own_tag;
}
}
void tipc_bclink_check_gap(struct tipc_node *n_ptr, u32 last_sent)
{
if (!n_ptr->bclink.supported ||
less_eq(last_sent, mod(n_ptr->bclink.last_in)))
return;
bclink_set_gap(n_ptr);
if (n_ptr->bclink.gap_after == n_ptr->bclink.gap_to)
n_ptr->bclink.gap_to = last_sent;
bclink_send_nack(n_ptr);
}
static void tipc_bclink_peek_nack(u32 dest, u32 sender_tag, u32 gap_after, u32 gap_to)
{
struct tipc_node *n_ptr = tipc_node_find(dest);
u32 my_after, my_to;
if (unlikely(!n_ptr || !tipc_node_is_up(n_ptr)))
return;
tipc_node_lock(n_ptr);
my_after = n_ptr->bclink.gap_after;
my_to = n_ptr->bclink.gap_to;
if (less_eq(gap_after, my_after)) {
if (less(my_after, gap_to) && less(gap_to, my_to))
n_ptr->bclink.gap_after = gap_to;
else if (less_eq(my_to, gap_to))
n_ptr->bclink.gap_to = n_ptr->bclink.gap_after;
} else if (less_eq(gap_after, my_to)) {
if (less_eq(my_to, gap_to))
n_ptr->bclink.gap_to = gap_after;
} else {
struct sk_buff *buf = n_ptr->bclink.deferred_head;
u32 prev = n_ptr->bclink.gap_to;
for (; buf; buf = buf->next) {
u32 seqno = buf_seqno(buf);
if (mod(seqno - prev) != 1) {
buf = NULL;
break;
}
if (seqno == gap_after)
break;
prev = seqno;
}
if (buf == NULL)
n_ptr->bclink.gap_to = gap_after;
}
if (bclink_ack_allowed(sender_tag + 1)) {
if (n_ptr->bclink.gap_to != n_ptr->bclink.gap_after) {
bclink_send_nack(n_ptr);
bclink_set_gap(n_ptr);
}
}
tipc_node_unlock(n_ptr);
}
int tipc_bclink_send_msg(struct sk_buff *buf)
{
int res;
spin_lock_bh(&bc_lock);
res = tipc_link_send_buf(bcl, buf);
if (likely(res > 0))
bclink_set_last_sent();
bcl->stats.queue_sz_counts++;
bcl->stats.accu_queue_sz += bcl->out_queue_size;
spin_unlock_bh(&bc_lock);
return res;
}
void tipc_bclink_recv_pkt(struct sk_buff *buf)
{
struct tipc_msg *msg = buf_msg(buf);
struct tipc_node *node = tipc_node_find(msg_prevnode(msg));
u32 next_in;
u32 seqno;
struct sk_buff *deferred;
if (unlikely(!node || !tipc_node_is_up(node) || !node->bclink.supported ||
(msg_mc_netid(msg) != tipc_net_id))) {
buf_discard(buf);
return;
}
if (unlikely(msg_user(msg) == BCAST_PROTOCOL)) {
if (msg_destnode(msg) == tipc_own_addr) {
tipc_node_lock(node);
tipc_bclink_acknowledge(node, msg_bcast_ack(msg));
tipc_node_unlock(node);
spin_lock_bh(&bc_lock);
bcl->stats.recv_nacks++;
bclink->retransmit_to = node;
bclink_retransmit_pkt(msg_bcgap_after(msg),
msg_bcgap_to(msg));
spin_unlock_bh(&bc_lock);
} else {
tipc_bclink_peek_nack(msg_destnode(msg),
msg_bcast_tag(msg),
msg_bcgap_after(msg),
msg_bcgap_to(msg));
}
buf_discard(buf);
return;
}
tipc_node_lock(node);
receive:
deferred = node->bclink.deferred_head;
next_in = mod(node->bclink.last_in + 1);
seqno = msg_seqno(msg);
if (likely(seqno == next_in)) {
bcl->stats.recv_info++;
node->bclink.last_in++;
bclink_set_gap(node);
if (unlikely(bclink_ack_allowed(seqno))) {
bclink_send_ack(node);
bcl->stats.sent_acks++;
}
if (likely(msg_isdata(msg))) {
tipc_node_unlock(node);
tipc_port_recv_mcast(buf, NULL);
} else if (msg_user(msg) == MSG_BUNDLER) {
bcl->stats.recv_bundles++;
bcl->stats.recv_bundled += msg_msgcnt(msg);
tipc_node_unlock(node);
tipc_link_recv_bundle(buf);
} else if (msg_user(msg) == MSG_FRAGMENTER) {
bcl->stats.recv_fragments++;
if (tipc_link_recv_fragment(&node->bclink.defragm,
&buf, &msg))
bcl->stats.recv_fragmented++;
tipc_node_unlock(node);
tipc_net_route_msg(buf);
} else {
tipc_node_unlock(node);
tipc_net_route_msg(buf);
}
if (deferred && (buf_seqno(deferred) == mod(next_in + 1))) {
tipc_node_lock(node);
buf = deferred;
msg = buf_msg(buf);
node->bclink.deferred_head = deferred->next;
goto receive;
}
return;
} else if (less(next_in, seqno)) {
u32 gap_after = node->bclink.gap_after;
u32 gap_to = node->bclink.gap_to;
if (tipc_link_defer_pkt(&node->bclink.deferred_head,
&node->bclink.deferred_tail,
buf)) {
node->bclink.nack_sync++;
bcl->stats.deferred_recv++;
if (seqno == mod(gap_after + 1))
node->bclink.gap_after = seqno;
else if (less(gap_after, seqno) && less(seqno, gap_to))
node->bclink.gap_to = seqno;
}
if (bclink_ack_allowed(node->bclink.nack_sync)) {
if (gap_to != gap_after)
bclink_send_nack(node);
bclink_set_gap(node);
}
} else {
bcl->stats.duplicates++;
buf_discard(buf);
}
tipc_node_unlock(node);
}
u32 tipc_bclink_acks_missing(struct tipc_node *n_ptr)
{
return (n_ptr->bclink.supported &&
(tipc_bclink_get_last_sent() != n_ptr->bclink.acked));
}
static int tipc_bcbearer_send(struct sk_buff *buf,
struct tipc_bearer *unused1,
struct tipc_media_addr *unused2)
{
int bp_index;
if (likely(!msg_non_seq(buf_msg(buf)))) {
struct tipc_msg *msg;
assert(tipc_bcast_nmap.count != 0);
bcbuf_set_acks(buf, tipc_bcast_nmap.count);
msg = buf_msg(buf);
msg_set_non_seq(msg, 1);
msg_set_mc_netid(msg, tipc_net_id);
bcl->stats.sent_info++;
}
bcbearer->remains = tipc_bcast_nmap;
for (bp_index = 0; bp_index < MAX_BEARERS; bp_index++) {
struct tipc_bearer *p = bcbearer->bpairs[bp_index].primary;
struct tipc_bearer *s = bcbearer->bpairs[bp_index].secondary;
if (!p)
break;
tipc_nmap_diff(&bcbearer->remains, &p->nodes, &bcbearer->remains_new);
if (bcbearer->remains_new.count == bcbearer->remains.count)
continue;
if (p->blocked ||
p->media->send_msg(buf, p, &p->media->bcast_addr)) {
if (!s || s->blocked ||
s->media->send_msg(buf, s,
&s->media->bcast_addr)) {
continue;
}
}
if (s) {
bcbearer->bpairs[bp_index].primary = s;
bcbearer->bpairs[bp_index].secondary = p;
}
if (bcbearer->remains_new.count == 0)
return 0;
bcbearer->remains = bcbearer->remains_new;
}
return TIPC_OK;
}
void tipc_bcbearer_sort(void)
{
struct bcbearer_pair *bp_temp = bcbearer->bpairs_temp;
struct bcbearer_pair *bp_curr;
int b_index;
int pri;
spin_lock_bh(&bc_lock);
memset(bp_temp, 0, sizeof(bcbearer->bpairs_temp));
for (b_index = 0; b_index < MAX_BEARERS; b_index++) {
struct tipc_bearer *b = &tipc_bearers[b_index];
if (!b->active || !b->nodes.count)
continue;
if (!bp_temp[b->priority].primary)
bp_temp[b->priority].primary = b;
else
bp_temp[b->priority].secondary = b;
}
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
spin_unlock_bh(&bc_lock);
}
void tipc_bcbearer_push(void)
{
struct tipc_bearer *b_ptr;
spin_lock_bh(&bc_lock);
b_ptr = &bcbearer->bearer;
if (b_ptr->blocked) {
b_ptr->blocked = 0;
tipc_bearer_lock_push(b_ptr);
}
spin_unlock_bh(&bc_lock);
}
int tipc_bclink_stats(char *buf, const u32 buf_size)
{
struct print_buf pb;
if (!bcl)
return 0;
tipc_printbuf_init(&pb, buf, buf_size);
spin_lock_bh(&bc_lock);
tipc_printf(&pb, "Link <%s>\n"
" Window:%u packets\n",
bcl->name, bcl->queue_limit[0]);
tipc_printf(&pb, " RX packets:%u fragments:%u/%u bundles:%u/%u\n",
bcl->stats.recv_info,
bcl->stats.recv_fragments,
bcl->stats.recv_fragmented,
bcl->stats.recv_bundles,
bcl->stats.recv_bundled);
tipc_printf(&pb, " TX packets:%u fragments:%u/%u bundles:%u/%u\n",
bcl->stats.sent_info,
bcl->stats.sent_fragments,
bcl->stats.sent_fragmented,
bcl->stats.sent_bundles,
bcl->stats.sent_bundled);
tipc_printf(&pb, " RX naks:%u defs:%u dups:%u\n",
bcl->stats.recv_nacks,
bcl->stats.deferred_recv,
bcl->stats.duplicates);
tipc_printf(&pb, " TX naks:%u acks:%u dups:%u\n",
bcl->stats.sent_nacks,
bcl->stats.sent_acks,
bcl->stats.retransmitted);
tipc_printf(&pb, " Congestion bearer:%u link:%u Send queue max:%u avg:%u\n",
bcl->stats.bearer_congs,
bcl->stats.link_congs,
bcl->stats.max_queue_sz,
bcl->stats.queue_sz_counts
? (bcl->stats.accu_queue_sz / bcl->stats.queue_sz_counts)
: 0);
spin_unlock_bh(&bc_lock);
return tipc_printbuf_validate(&pb);
}
int tipc_bclink_reset_stats(void)
{
if (!bcl)
return -ENOPROTOOPT;
spin_lock_bh(&bc_lock);
memset(&bcl->stats, 0, sizeof(bcl->stats));
spin_unlock_bh(&bc_lock);
return 0;
}
int tipc_bclink_set_queue_limits(u32 limit)
{
if (!bcl)
return -ENOPROTOOPT;
if ((limit < TIPC_MIN_LINK_WIN) || (limit > TIPC_MAX_LINK_WIN))
return -EINVAL;
spin_lock_bh(&bc_lock);
tipc_link_set_queue_limits(bcl, limit);
spin_unlock_bh(&bc_lock);
return 0;
}
int tipc_bclink_init(void)
{
bcbearer = kzalloc(sizeof(*bcbearer), GFP_ATOMIC);
bclink = kzalloc(sizeof(*bclink), GFP_ATOMIC);
if (!bcbearer || !bclink) {
warn("Multicast link creation failed, no memory\n");
kfree(bcbearer);
bcbearer = NULL;
kfree(bclink);
bclink = NULL;
return -ENOMEM;
}
INIT_LIST_HEAD(&bcbearer->bearer.cong_links);
bcbearer->bearer.media = &bcbearer->media;
bcbearer->media.send_msg = tipc_bcbearer_send;
sprintf(bcbearer->media.name, "tipc-multicast");
bcl = &bclink->link;
INIT_LIST_HEAD(&bcl->waiting_ports);
bcl->next_out_no = 1;
spin_lock_init(&bclink->node.lock);
bcl->owner = &bclink->node;
bcl->max_pkt = MAX_PKT_DEFAULT_MCAST;
tipc_link_set_queue_limits(bcl, BCLINK_WIN_DEFAULT);
bcl->b_ptr = &bcbearer->bearer;
bcl->state = WORKING_WORKING;
strlcpy(bcl->name, tipc_bclink_name, TIPC_MAX_LINK_NAME);
return 0;
}
void tipc_bclink_stop(void)
{
spin_lock_bh(&bc_lock);
if (bcbearer) {
tipc_link_stop(bcl);
bcl = NULL;
kfree(bclink);
bclink = NULL;
kfree(bcbearer);
bcbearer = NULL;
}
spin_unlock_bh(&bc_lock);
}
void tipc_nmap_add(struct tipc_node_map *nm_ptr, u32 node)
{
int n = tipc_node(node);
int w = n / WSIZE;
u32 mask = (1 << (n % WSIZE));
if ((nm_ptr->map[w] & mask) == 0) {
nm_ptr->count++;
nm_ptr->map[w] |= mask;
}
}
void tipc_nmap_remove(struct tipc_node_map *nm_ptr, u32 node)
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
void tipc_port_list_add(struct port_list *pl_ptr, u32 port)
{
struct port_list *item = pl_ptr;
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
warn("Incomplete multicast delivery, no memory\n");
return;
}
item->next->next = NULL;
}
}
}
void tipc_port_list_free(struct port_list *pl_ptr)
{
struct port_list *item;
struct port_list *next;
for (item = pl_ptr->next; item; item = next) {
next = item->next;
kfree(item);
}
}
