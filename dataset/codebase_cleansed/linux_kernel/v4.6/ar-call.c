static unsigned long rxrpc_call_hashfunc(
u8 in_clientflag,
u32 cid,
u32 call_id,
u32 epoch,
u16 service_id,
sa_family_t proto,
void *localptr,
unsigned int addr_size,
const u8 *peer_addr)
{
const u16 *p;
unsigned int i;
unsigned long key;
_enter("");
key = (unsigned long)localptr;
key += epoch;
key += service_id;
key += call_id;
key += (cid & RXRPC_CIDMASK) >> RXRPC_CIDSHIFT;
key += cid & RXRPC_CHANNELMASK;
key += in_clientflag;
key += proto;
for (i = 0, p = (const u16 *)peer_addr; i < addr_size >> 1; i++, p++)
key += *p;
_leave(" key = 0x%lx", key);
return key;
}
static void rxrpc_call_hash_add(struct rxrpc_call *call)
{
unsigned long key;
unsigned int addr_size = 0;
_enter("");
switch (call->proto) {
case AF_INET:
addr_size = sizeof(call->peer_ip.ipv4_addr);
break;
case AF_INET6:
addr_size = sizeof(call->peer_ip.ipv6_addr);
break;
default:
break;
}
key = rxrpc_call_hashfunc(call->in_clientflag, call->cid,
call->call_id, call->epoch,
call->service_id, call->proto,
call->conn->trans->local, addr_size,
call->peer_ip.ipv6_addr);
call->hash_key = key;
spin_lock(&rxrpc_call_hash_lock);
hash_add_rcu(rxrpc_call_hash, &call->hash_node, key);
spin_unlock(&rxrpc_call_hash_lock);
_leave("");
}
static void rxrpc_call_hash_del(struct rxrpc_call *call)
{
_enter("");
spin_lock(&rxrpc_call_hash_lock);
hash_del_rcu(&call->hash_node);
spin_unlock(&rxrpc_call_hash_lock);
_leave("");
}
struct rxrpc_call *rxrpc_find_call_hash(
struct rxrpc_host_header *hdr,
void *localptr,
sa_family_t proto,
const void *peer_addr)
{
unsigned long key;
unsigned int addr_size = 0;
struct rxrpc_call *call = NULL;
struct rxrpc_call *ret = NULL;
u8 in_clientflag = hdr->flags & RXRPC_CLIENT_INITIATED;
_enter("");
switch (proto) {
case AF_INET:
addr_size = sizeof(call->peer_ip.ipv4_addr);
break;
case AF_INET6:
addr_size = sizeof(call->peer_ip.ipv6_addr);
break;
default:
break;
}
key = rxrpc_call_hashfunc(in_clientflag, hdr->cid, hdr->callNumber,
hdr->epoch, hdr->serviceId,
proto, localptr, addr_size,
peer_addr);
hash_for_each_possible_rcu(rxrpc_call_hash, call, hash_node, key) {
if (call->hash_key == key &&
call->call_id == hdr->callNumber &&
call->cid == hdr->cid &&
call->in_clientflag == in_clientflag &&
call->service_id == hdr->serviceId &&
call->proto == proto &&
call->local == localptr &&
memcmp(call->peer_ip.ipv6_addr, peer_addr,
addr_size) == 0 &&
call->epoch == hdr->epoch) {
ret = call;
break;
}
}
_leave(" = %p", ret);
return ret;
}
static struct rxrpc_call *rxrpc_alloc_call(gfp_t gfp)
{
struct rxrpc_call *call;
call = kmem_cache_zalloc(rxrpc_call_jar, gfp);
if (!call)
return NULL;
call->acks_winsz = 16;
call->acks_window = kmalloc(call->acks_winsz * sizeof(unsigned long),
gfp);
if (!call->acks_window) {
kmem_cache_free(rxrpc_call_jar, call);
return NULL;
}
setup_timer(&call->lifetimer, &rxrpc_call_life_expired,
(unsigned long) call);
setup_timer(&call->deadspan, &rxrpc_dead_call_expired,
(unsigned long) call);
setup_timer(&call->ack_timer, &rxrpc_ack_time_expired,
(unsigned long) call);
setup_timer(&call->resend_timer, &rxrpc_resend_time_expired,
(unsigned long) call);
INIT_WORK(&call->destroyer, &rxrpc_destroy_call);
INIT_WORK(&call->processor, &rxrpc_process_call);
INIT_LIST_HEAD(&call->accept_link);
skb_queue_head_init(&call->rx_queue);
skb_queue_head_init(&call->rx_oos_queue);
init_waitqueue_head(&call->tx_waitq);
spin_lock_init(&call->lock);
rwlock_init(&call->state_lock);
atomic_set(&call->usage, 1);
call->debug_id = atomic_inc_return(&rxrpc_debug_id);
call->state = RXRPC_CALL_CLIENT_SEND_REQUEST;
memset(&call->sock_node, 0xed, sizeof(call->sock_node));
call->rx_data_expect = 1;
call->rx_data_eaten = 0;
call->rx_first_oos = 0;
call->ackr_win_top = call->rx_data_eaten + 1 + rxrpc_rx_window_size;
call->creation_jif = jiffies;
return call;
}
static struct rxrpc_call *rxrpc_alloc_client_call(
struct rxrpc_sock *rx,
struct rxrpc_transport *trans,
struct rxrpc_conn_bundle *bundle,
gfp_t gfp)
{
struct rxrpc_call *call;
int ret;
_enter("");
ASSERT(rx != NULL);
ASSERT(trans != NULL);
ASSERT(bundle != NULL);
call = rxrpc_alloc_call(gfp);
if (!call)
return ERR_PTR(-ENOMEM);
sock_hold(&rx->sk);
call->socket = rx;
call->rx_data_post = 1;
ret = rxrpc_connect_call(rx, trans, bundle, call, gfp);
if (ret < 0) {
kmem_cache_free(rxrpc_call_jar, call);
return ERR_PTR(ret);
}
call->proto = rx->proto;
call->local = trans->local;
switch (call->proto) {
case AF_INET:
call->peer_ip.ipv4_addr =
trans->peer->srx.transport.sin.sin_addr.s_addr;
break;
case AF_INET6:
memcpy(call->peer_ip.ipv6_addr,
trans->peer->srx.transport.sin6.sin6_addr.in6_u.u6_addr8,
sizeof(call->peer_ip.ipv6_addr));
break;
}
call->epoch = call->conn->epoch;
call->service_id = call->conn->service_id;
call->in_clientflag = call->conn->in_clientflag;
rxrpc_call_hash_add(call);
spin_lock(&call->conn->trans->peer->lock);
list_add(&call->error_link, &call->conn->trans->peer->error_targets);
spin_unlock(&call->conn->trans->peer->lock);
call->lifetimer.expires = jiffies + rxrpc_max_call_lifetime;
add_timer(&call->lifetimer);
_leave(" = %p", call);
return call;
}
struct rxrpc_call *rxrpc_get_client_call(struct rxrpc_sock *rx,
struct rxrpc_transport *trans,
struct rxrpc_conn_bundle *bundle,
unsigned long user_call_ID,
int create,
gfp_t gfp)
{
struct rxrpc_call *call, *candidate;
struct rb_node *p, *parent, **pp;
_enter("%p,%d,%d,%lx,%d",
rx, trans ? trans->debug_id : -1, bundle ? bundle->debug_id : -1,
user_call_ID, create);
read_lock(&rx->call_lock);
p = rx->calls.rb_node;
while (p) {
call = rb_entry(p, struct rxrpc_call, sock_node);
if (user_call_ID < call->user_call_ID)
p = p->rb_left;
else if (user_call_ID > call->user_call_ID)
p = p->rb_right;
else
goto found_extant_call;
}
read_unlock(&rx->call_lock);
if (!create || !trans)
return ERR_PTR(-EBADSLT);
candidate = rxrpc_alloc_client_call(rx, trans, bundle, gfp);
if (IS_ERR(candidate)) {
_leave(" = %ld", PTR_ERR(candidate));
return candidate;
}
candidate->user_call_ID = user_call_ID;
__set_bit(RXRPC_CALL_HAS_USERID, &candidate->flags);
write_lock(&rx->call_lock);
pp = &rx->calls.rb_node;
parent = NULL;
while (*pp) {
parent = *pp;
call = rb_entry(parent, struct rxrpc_call, sock_node);
if (user_call_ID < call->user_call_ID)
pp = &(*pp)->rb_left;
else if (user_call_ID > call->user_call_ID)
pp = &(*pp)->rb_right;
else
goto found_extant_second;
}
call = candidate;
candidate = NULL;
rxrpc_get_call(call);
rb_link_node(&call->sock_node, parent, pp);
rb_insert_color(&call->sock_node, &rx->calls);
write_unlock(&rx->call_lock);
write_lock_bh(&rxrpc_call_lock);
list_add_tail(&call->link, &rxrpc_calls);
write_unlock_bh(&rxrpc_call_lock);
_net("CALL new %d on CONN %d", call->debug_id, call->conn->debug_id);
_leave(" = %p [new]", call);
return call;
found_extant_call:
rxrpc_get_call(call);
read_unlock(&rx->call_lock);
_leave(" = %p [extant %d]", call, atomic_read(&call->usage));
return call;
found_extant_second:
rxrpc_get_call(call);
write_unlock(&rx->call_lock);
rxrpc_put_call(candidate);
_leave(" = %p [second %d]", call, atomic_read(&call->usage));
return call;
}
struct rxrpc_call *rxrpc_incoming_call(struct rxrpc_sock *rx,
struct rxrpc_connection *conn,
struct rxrpc_host_header *hdr,
gfp_t gfp)
{
struct rxrpc_call *call, *candidate;
struct rb_node **p, *parent;
u32 call_id;
_enter(",%d,,%x", conn->debug_id, gfp);
ASSERT(rx != NULL);
candidate = rxrpc_alloc_call(gfp);
if (!candidate)
return ERR_PTR(-EBUSY);
candidate->socket = rx;
candidate->conn = conn;
candidate->cid = hdr->cid;
candidate->call_id = hdr->callNumber;
candidate->channel = hdr->cid & RXRPC_CHANNELMASK;
candidate->rx_data_post = 0;
candidate->state = RXRPC_CALL_SERVER_ACCEPTING;
if (conn->security_ix > 0)
candidate->state = RXRPC_CALL_SERVER_SECURING;
write_lock_bh(&conn->lock);
call = conn->channels[candidate->channel];
_debug("channel[%u] is %p", candidate->channel, call);
if (call && call->call_id == hdr->callNumber) {
_debug("extant call [%d]", call->state);
ASSERTCMP(call->conn, ==, conn);
read_lock(&call->state_lock);
switch (call->state) {
case RXRPC_CALL_LOCALLY_ABORTED:
if (!test_and_set_bit(RXRPC_CALL_EV_ABORT, &call->events))
rxrpc_queue_call(call);
case RXRPC_CALL_REMOTELY_ABORTED:
read_unlock(&call->state_lock);
goto aborted_call;
default:
rxrpc_get_call(call);
read_unlock(&call->state_lock);
goto extant_call;
}
}
if (call) {
_debug("CALL: %u { %s }",
call->debug_id, rxrpc_call_states[call->state]);
if (call->state >= RXRPC_CALL_COMPLETE) {
conn->channels[call->channel] = NULL;
} else {
write_unlock_bh(&conn->lock);
kmem_cache_free(rxrpc_call_jar, candidate);
_leave(" = -EBUSY");
return ERR_PTR(-EBUSY);
}
}
_debug("check dup");
call_id = hdr->callNumber;
p = &conn->calls.rb_node;
parent = NULL;
while (*p) {
parent = *p;
call = rb_entry(parent, struct rxrpc_call, conn_node);
if (call_id < call->call_id)
p = &(*p)->rb_left;
else if (call_id > call->call_id)
p = &(*p)->rb_right;
else
goto old_call;
}
_debug("new call");
call = candidate;
candidate = NULL;
rb_link_node(&call->conn_node, parent, p);
rb_insert_color(&call->conn_node, &conn->calls);
conn->channels[call->channel] = call;
sock_hold(&rx->sk);
atomic_inc(&conn->usage);
write_unlock_bh(&conn->lock);
spin_lock(&conn->trans->peer->lock);
list_add(&call->error_link, &conn->trans->peer->error_targets);
spin_unlock(&conn->trans->peer->lock);
write_lock_bh(&rxrpc_call_lock);
list_add_tail(&call->link, &rxrpc_calls);
write_unlock_bh(&rxrpc_call_lock);
call->proto = rx->proto;
call->local = conn->trans->local;
switch (call->proto) {
case AF_INET:
call->peer_ip.ipv4_addr =
conn->trans->peer->srx.transport.sin.sin_addr.s_addr;
break;
case AF_INET6:
memcpy(call->peer_ip.ipv6_addr,
conn->trans->peer->srx.transport.sin6.sin6_addr.in6_u.u6_addr8,
sizeof(call->peer_ip.ipv6_addr));
break;
default:
break;
}
call->epoch = conn->epoch;
call->service_id = conn->service_id;
call->in_clientflag = conn->in_clientflag;
rxrpc_call_hash_add(call);
_net("CALL incoming %d on CONN %d", call->debug_id, call->conn->debug_id);
call->lifetimer.expires = jiffies + rxrpc_max_call_lifetime;
add_timer(&call->lifetimer);
_leave(" = %p {%d} [new]", call, call->debug_id);
return call;
extant_call:
write_unlock_bh(&conn->lock);
kmem_cache_free(rxrpc_call_jar, candidate);
_leave(" = %p {%d} [extant]", call, call ? call->debug_id : -1);
return call;
aborted_call:
write_unlock_bh(&conn->lock);
kmem_cache_free(rxrpc_call_jar, candidate);
_leave(" = -ECONNABORTED");
return ERR_PTR(-ECONNABORTED);
old_call:
write_unlock_bh(&conn->lock);
kmem_cache_free(rxrpc_call_jar, candidate);
_leave(" = -ECONNRESET [old]");
return ERR_PTR(-ECONNRESET);
}
struct rxrpc_call *rxrpc_find_server_call(struct rxrpc_sock *rx,
unsigned long user_call_ID)
{
struct rxrpc_call *call;
struct rb_node *p;
_enter("%p,%lx", rx, user_call_ID);
read_lock(&rx->call_lock);
p = rx->calls.rb_node;
while (p) {
call = rb_entry(p, struct rxrpc_call, sock_node);
if (user_call_ID < call->user_call_ID)
p = p->rb_left;
else if (user_call_ID > call->user_call_ID)
p = p->rb_right;
else
goto found_extant_call;
}
read_unlock(&rx->call_lock);
_leave(" = NULL");
return NULL;
found_extant_call:
rxrpc_get_call(call);
read_unlock(&rx->call_lock);
_leave(" = %p [%d]", call, atomic_read(&call->usage));
return call;
}
void rxrpc_release_call(struct rxrpc_call *call)
{
struct rxrpc_connection *conn = call->conn;
struct rxrpc_sock *rx = call->socket;
_enter("{%d,%d,%d,%d}",
call->debug_id, atomic_read(&call->usage),
atomic_read(&call->ackr_not_idle),
call->rx_first_oos);
spin_lock_bh(&call->lock);
if (test_and_set_bit(RXRPC_CALL_RELEASED, &call->flags))
BUG();
spin_unlock_bh(&call->lock);
_debug("RELEASE CALL %p (%d CONN %p)", call, call->debug_id, conn);
write_lock_bh(&rx->call_lock);
if (!list_empty(&call->accept_link)) {
_debug("unlinking once-pending call %p { e=%lx f=%lx }",
call, call->events, call->flags);
ASSERT(!test_bit(RXRPC_CALL_HAS_USERID, &call->flags));
list_del_init(&call->accept_link);
sk_acceptq_removed(&rx->sk);
} else if (test_bit(RXRPC_CALL_HAS_USERID, &call->flags)) {
rb_erase(&call->sock_node, &rx->calls);
memset(&call->sock_node, 0xdd, sizeof(call->sock_node));
clear_bit(RXRPC_CALL_HAS_USERID, &call->flags);
}
write_unlock_bh(&rx->call_lock);
spin_lock(&conn->trans->client_lock);
write_lock_bh(&conn->lock);
write_lock(&call->state_lock);
if (conn->channels[call->channel] == call)
conn->channels[call->channel] = NULL;
if (conn->out_clientflag && conn->bundle) {
conn->avail_calls++;
switch (conn->avail_calls) {
case 1:
list_move_tail(&conn->bundle_link,
&conn->bundle->avail_conns);
case 2 ... RXRPC_MAXCALLS - 1:
ASSERT(conn->channels[0] == NULL ||
conn->channels[1] == NULL ||
conn->channels[2] == NULL ||
conn->channels[3] == NULL);
break;
case RXRPC_MAXCALLS:
list_move_tail(&conn->bundle_link,
&conn->bundle->unused_conns);
ASSERT(conn->channels[0] == NULL &&
conn->channels[1] == NULL &&
conn->channels[2] == NULL &&
conn->channels[3] == NULL);
break;
default:
printk(KERN_ERR "RxRPC: conn->avail_calls=%d\n",
conn->avail_calls);
BUG();
}
}
spin_unlock(&conn->trans->client_lock);
if (call->state < RXRPC_CALL_COMPLETE &&
call->state != RXRPC_CALL_CLIENT_FINAL_ACK) {
_debug("+++ ABORTING STATE %d +++\n", call->state);
call->state = RXRPC_CALL_LOCALLY_ABORTED;
call->abort_code = RX_CALL_DEAD;
set_bit(RXRPC_CALL_EV_ABORT, &call->events);
rxrpc_queue_call(call);
}
write_unlock(&call->state_lock);
write_unlock_bh(&conn->lock);
if (!skb_queue_empty(&call->rx_queue) ||
!skb_queue_empty(&call->rx_oos_queue)) {
struct rxrpc_skb_priv *sp;
struct sk_buff *skb;
_debug("purge Rx queues");
spin_lock_bh(&call->lock);
while ((skb = skb_dequeue(&call->rx_queue)) ||
(skb = skb_dequeue(&call->rx_oos_queue))) {
sp = rxrpc_skb(skb);
if (sp->call) {
ASSERTCMP(sp->call, ==, call);
rxrpc_put_call(call);
sp->call = NULL;
}
skb->destructor = NULL;
spin_unlock_bh(&call->lock);
_debug("- zap %s %%%u #%u",
rxrpc_pkts[sp->hdr.type],
sp->hdr.serial, sp->hdr.seq);
rxrpc_free_skb(skb);
spin_lock_bh(&call->lock);
}
spin_unlock_bh(&call->lock);
ASSERTCMP(call->state, !=, RXRPC_CALL_COMPLETE);
}
del_timer_sync(&call->resend_timer);
del_timer_sync(&call->ack_timer);
del_timer_sync(&call->lifetimer);
call->deadspan.expires = jiffies + rxrpc_dead_call_expiry;
add_timer(&call->deadspan);
_leave("");
}
static void rxrpc_dead_call_expired(unsigned long _call)
{
struct rxrpc_call *call = (struct rxrpc_call *) _call;
_enter("{%d}", call->debug_id);
write_lock_bh(&call->state_lock);
call->state = RXRPC_CALL_DEAD;
write_unlock_bh(&call->state_lock);
rxrpc_put_call(call);
}
static void rxrpc_mark_call_released(struct rxrpc_call *call)
{
bool sched;
write_lock(&call->state_lock);
if (call->state < RXRPC_CALL_DEAD) {
sched = false;
if (call->state < RXRPC_CALL_COMPLETE) {
_debug("abort call %p", call);
call->state = RXRPC_CALL_LOCALLY_ABORTED;
call->abort_code = RX_CALL_DEAD;
if (!test_and_set_bit(RXRPC_CALL_EV_ABORT, &call->events))
sched = true;
}
if (!test_and_set_bit(RXRPC_CALL_EV_RELEASE, &call->events))
sched = true;
if (sched)
rxrpc_queue_call(call);
}
write_unlock(&call->state_lock);
}
void rxrpc_release_calls_on_socket(struct rxrpc_sock *rx)
{
struct rxrpc_call *call;
struct rb_node *p;
_enter("%p", rx);
read_lock_bh(&rx->call_lock);
for (p = rb_first(&rx->calls); p; p = rb_next(p)) {
call = rb_entry(p, struct rxrpc_call, sock_node);
rxrpc_mark_call_released(call);
}
list_for_each_entry(call, &rx->secureq, accept_link) {
rxrpc_mark_call_released(call);
}
list_for_each_entry(call, &rx->acceptq, accept_link) {
rxrpc_mark_call_released(call);
}
read_unlock_bh(&rx->call_lock);
_leave("");
}
void __rxrpc_put_call(struct rxrpc_call *call)
{
ASSERT(call != NULL);
_enter("%p{u=%d}", call, atomic_read(&call->usage));
ASSERTCMP(atomic_read(&call->usage), >, 0);
if (atomic_dec_and_test(&call->usage)) {
_debug("call %d dead", call->debug_id);
ASSERTCMP(call->state, ==, RXRPC_CALL_DEAD);
rxrpc_queue_work(&call->destroyer);
}
_leave("");
}
static void rxrpc_cleanup_call(struct rxrpc_call *call)
{
_net("DESTROY CALL %d", call->debug_id);
ASSERT(call->socket);
memset(&call->sock_node, 0xcd, sizeof(call->sock_node));
del_timer_sync(&call->lifetimer);
del_timer_sync(&call->deadspan);
del_timer_sync(&call->ack_timer);
del_timer_sync(&call->resend_timer);
ASSERT(test_bit(RXRPC_CALL_RELEASED, &call->flags));
ASSERTCMP(call->events, ==, 0);
if (work_pending(&call->processor)) {
_debug("defer destroy");
rxrpc_queue_work(&call->destroyer);
return;
}
if (call->conn) {
spin_lock(&call->conn->trans->peer->lock);
list_del(&call->error_link);
spin_unlock(&call->conn->trans->peer->lock);
write_lock_bh(&call->conn->lock);
rb_erase(&call->conn_node, &call->conn->calls);
write_unlock_bh(&call->conn->lock);
rxrpc_put_connection(call->conn);
}
rxrpc_call_hash_del(call);
if (call->acks_window) {
_debug("kill Tx window %d",
CIRC_CNT(call->acks_head, call->acks_tail,
call->acks_winsz));
smp_mb();
while (CIRC_CNT(call->acks_head, call->acks_tail,
call->acks_winsz) > 0) {
struct rxrpc_skb_priv *sp;
unsigned long _skb;
_skb = call->acks_window[call->acks_tail] & ~1;
sp = rxrpc_skb((struct sk_buff *)_skb);
_debug("+++ clear Tx %u", sp->hdr.seq);
rxrpc_free_skb((struct sk_buff *)_skb);
call->acks_tail =
(call->acks_tail + 1) & (call->acks_winsz - 1);
}
kfree(call->acks_window);
}
rxrpc_free_skb(call->tx_pending);
rxrpc_purge_queue(&call->rx_queue);
ASSERT(skb_queue_empty(&call->rx_oos_queue));
sock_put(&call->socket->sk);
kmem_cache_free(rxrpc_call_jar, call);
}
static void rxrpc_destroy_call(struct work_struct *work)
{
struct rxrpc_call *call =
container_of(work, struct rxrpc_call, destroyer);
_enter("%p{%d,%d,%p}",
call, atomic_read(&call->usage), call->channel, call->conn);
ASSERTCMP(call->state, ==, RXRPC_CALL_DEAD);
write_lock_bh(&rxrpc_call_lock);
list_del_init(&call->link);
write_unlock_bh(&rxrpc_call_lock);
rxrpc_cleanup_call(call);
_leave("");
}
void __exit rxrpc_destroy_all_calls(void)
{
struct rxrpc_call *call;
_enter("");
write_lock_bh(&rxrpc_call_lock);
while (!list_empty(&rxrpc_calls)) {
call = list_entry(rxrpc_calls.next, struct rxrpc_call, link);
_debug("Zapping call %p", call);
list_del_init(&call->link);
switch (atomic_read(&call->usage)) {
case 0:
ASSERTCMP(call->state, ==, RXRPC_CALL_DEAD);
break;
case 1:
if (del_timer_sync(&call->deadspan) != 0 &&
call->state != RXRPC_CALL_DEAD)
rxrpc_dead_call_expired((unsigned long) call);
if (call->state != RXRPC_CALL_DEAD)
break;
default:
printk(KERN_ERR "RXRPC:"
" Call %p still in use (%d,%d,%s,%lx,%lx)!\n",
call, atomic_read(&call->usage),
atomic_read(&call->ackr_not_idle),
rxrpc_call_states[call->state],
call->flags, call->events);
if (!skb_queue_empty(&call->rx_queue))
printk(KERN_ERR"RXRPC: Rx queue occupied\n");
if (!skb_queue_empty(&call->rx_oos_queue))
printk(KERN_ERR"RXRPC: OOS queue occupied\n");
break;
}
write_unlock_bh(&rxrpc_call_lock);
cond_resched();
write_lock_bh(&rxrpc_call_lock);
}
write_unlock_bh(&rxrpc_call_lock);
_leave("");
}
static void rxrpc_call_life_expired(unsigned long _call)
{
struct rxrpc_call *call = (struct rxrpc_call *) _call;
if (call->state >= RXRPC_CALL_COMPLETE)
return;
_enter("{%d}", call->debug_id);
read_lock_bh(&call->state_lock);
if (call->state < RXRPC_CALL_COMPLETE) {
set_bit(RXRPC_CALL_EV_LIFE_TIMER, &call->events);
rxrpc_queue_call(call);
}
read_unlock_bh(&call->state_lock);
}
static void rxrpc_resend_time_expired(unsigned long _call)
{
struct rxrpc_call *call = (struct rxrpc_call *) _call;
_enter("{%d}", call->debug_id);
if (call->state >= RXRPC_CALL_COMPLETE)
return;
clear_bit(RXRPC_CALL_RUN_RTIMER, &call->flags);
if (!test_and_set_bit(RXRPC_CALL_EV_RESEND_TIMER, &call->events))
rxrpc_queue_call(call);
}
static void rxrpc_ack_time_expired(unsigned long _call)
{
struct rxrpc_call *call = (struct rxrpc_call *) _call;
_enter("{%d}", call->debug_id);
if (call->state >= RXRPC_CALL_COMPLETE)
return;
read_lock_bh(&call->state_lock);
if (call->state < RXRPC_CALL_COMPLETE &&
!test_and_set_bit(RXRPC_CALL_EV_ACK, &call->events))
rxrpc_queue_call(call);
read_unlock_bh(&call->state_lock);
}
