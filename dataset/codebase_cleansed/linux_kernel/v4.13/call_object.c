static void rxrpc_call_timer_expired(unsigned long _call)
{
struct rxrpc_call *call = (struct rxrpc_call *)_call;
_enter("%d", call->debug_id);
if (call->state < RXRPC_CALL_COMPLETE)
rxrpc_set_timer(call, rxrpc_timer_expired, ktime_get_real());
}
struct rxrpc_call *rxrpc_find_call_by_user_ID(struct rxrpc_sock *rx,
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
rxrpc_get_call(call, rxrpc_call_got);
read_unlock(&rx->call_lock);
_leave(" = %p [%d]", call, atomic_read(&call->usage));
return call;
}
struct rxrpc_call *rxrpc_alloc_call(gfp_t gfp)
{
struct rxrpc_call *call;
call = kmem_cache_zalloc(rxrpc_call_jar, gfp);
if (!call)
return NULL;
call->rxtx_buffer = kcalloc(RXRPC_RXTX_BUFF_SIZE,
sizeof(struct sk_buff *),
gfp);
if (!call->rxtx_buffer)
goto nomem;
call->rxtx_annotations = kcalloc(RXRPC_RXTX_BUFF_SIZE, sizeof(u8), gfp);
if (!call->rxtx_annotations)
goto nomem_2;
mutex_init(&call->user_mutex);
setup_timer(&call->timer, rxrpc_call_timer_expired,
(unsigned long)call);
INIT_WORK(&call->processor, &rxrpc_process_call);
INIT_LIST_HEAD(&call->link);
INIT_LIST_HEAD(&call->chan_wait_link);
INIT_LIST_HEAD(&call->accept_link);
INIT_LIST_HEAD(&call->recvmsg_link);
INIT_LIST_HEAD(&call->sock_link);
init_waitqueue_head(&call->waitq);
spin_lock_init(&call->lock);
rwlock_init(&call->state_lock);
atomic_set(&call->usage, 1);
call->debug_id = atomic_inc_return(&rxrpc_debug_id);
call->tx_total_len = -1;
memset(&call->sock_node, 0xed, sizeof(call->sock_node));
call->rx_winsize = rxrpc_rx_window_size;
call->tx_winsize = 16;
call->rx_expect_next = 1;
call->cong_cwnd = 2;
call->cong_ssthresh = RXRPC_RXTX_BUFF_SIZE - 1;
return call;
nomem_2:
kfree(call->rxtx_buffer);
nomem:
kmem_cache_free(rxrpc_call_jar, call);
return NULL;
}
static struct rxrpc_call *rxrpc_alloc_client_call(struct sockaddr_rxrpc *srx,
gfp_t gfp)
{
struct rxrpc_call *call;
ktime_t now;
_enter("");
call = rxrpc_alloc_call(gfp);
if (!call)
return ERR_PTR(-ENOMEM);
call->state = RXRPC_CALL_CLIENT_AWAIT_CONN;
call->service_id = srx->srx_service;
call->tx_phase = true;
now = ktime_get_real();
call->acks_latest_ts = now;
call->cong_tstamp = now;
_leave(" = %p", call);
return call;
}
static void rxrpc_start_call_timer(struct rxrpc_call *call)
{
ktime_t now = ktime_get_real(), expire_at;
expire_at = ktime_add_ms(now, rxrpc_max_call_lifetime);
call->expire_at = expire_at;
call->ack_at = expire_at;
call->ping_at = expire_at;
call->resend_at = expire_at;
call->timer.expires = jiffies + LONG_MAX / 2;
rxrpc_set_timer(call, rxrpc_timer_begin, now);
}
struct rxrpc_call *rxrpc_new_client_call(struct rxrpc_sock *rx,
struct rxrpc_conn_parameters *cp,
struct sockaddr_rxrpc *srx,
unsigned long user_call_ID,
s64 tx_total_len,
gfp_t gfp)
__releases(&rx->sk.sk_lock.slock
void rxrpc_incoming_call(struct rxrpc_sock *rx,
struct rxrpc_call *call,
struct sk_buff *skb)
{
struct rxrpc_connection *conn = call->conn;
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
u32 chan;
_enter(",%d", call->conn->debug_id);
rcu_assign_pointer(call->socket, rx);
call->call_id = sp->hdr.callNumber;
call->service_id = sp->hdr.serviceId;
call->cid = sp->hdr.cid;
call->state = RXRPC_CALL_SERVER_ACCEPTING;
if (sp->hdr.securityIndex > 0)
call->state = RXRPC_CALL_SERVER_SECURING;
call->cong_tstamp = skb->tstamp;
chan = sp->hdr.cid & RXRPC_CHANNELMASK;
conn->channels[chan].call_counter = call->call_id;
conn->channels[chan].call_id = call->call_id;
rcu_assign_pointer(conn->channels[chan].call, call);
spin_lock(&conn->params.peer->lock);
hlist_add_head(&call->error_link, &conn->params.peer->error_targets);
spin_unlock(&conn->params.peer->lock);
_net("CALL incoming %d on CONN %d", call->debug_id, call->conn->debug_id);
rxrpc_start_call_timer(call);
_leave("");
}
bool rxrpc_queue_call(struct rxrpc_call *call)
{
const void *here = __builtin_return_address(0);
int n = __atomic_add_unless(&call->usage, 1, 0);
if (n == 0)
return false;
if (rxrpc_queue_work(&call->processor))
trace_rxrpc_call(call, rxrpc_call_queued, n + 1, here, NULL);
else
rxrpc_put_call(call, rxrpc_call_put_noqueue);
return true;
}
bool __rxrpc_queue_call(struct rxrpc_call *call)
{
const void *here = __builtin_return_address(0);
int n = atomic_read(&call->usage);
ASSERTCMP(n, >=, 1);
if (rxrpc_queue_work(&call->processor))
trace_rxrpc_call(call, rxrpc_call_queued_ref, n, here, NULL);
else
rxrpc_put_call(call, rxrpc_call_put_noqueue);
return true;
}
void rxrpc_see_call(struct rxrpc_call *call)
{
const void *here = __builtin_return_address(0);
if (call) {
int n = atomic_read(&call->usage);
trace_rxrpc_call(call, rxrpc_call_seen, n, here, NULL);
}
}
void rxrpc_get_call(struct rxrpc_call *call, enum rxrpc_call_trace op)
{
const void *here = __builtin_return_address(0);
int n = atomic_inc_return(&call->usage);
trace_rxrpc_call(call, op, n, here, NULL);
}
void rxrpc_release_call(struct rxrpc_sock *rx, struct rxrpc_call *call)
{
const void *here = __builtin_return_address(0);
struct rxrpc_connection *conn = call->conn;
bool put = false;
int i;
_enter("{%d,%d}", call->debug_id, atomic_read(&call->usage));
trace_rxrpc_call(call, rxrpc_call_release, atomic_read(&call->usage),
here, (const void *)call->flags);
ASSERTCMP(call->state, ==, RXRPC_CALL_COMPLETE);
spin_lock_bh(&call->lock);
if (test_and_set_bit(RXRPC_CALL_RELEASED, &call->flags))
BUG();
spin_unlock_bh(&call->lock);
del_timer_sync(&call->timer);
write_lock_bh(&rx->recvmsg_lock);
if (!list_empty(&call->recvmsg_link)) {
_debug("unlinking once-pending call %p { e=%lx f=%lx }",
call, call->events, call->flags);
list_del(&call->recvmsg_link);
put = true;
}
call->recvmsg_link.next = NULL;
call->recvmsg_link.prev = NULL;
write_unlock_bh(&rx->recvmsg_lock);
if (put)
rxrpc_put_call(call, rxrpc_call_put);
write_lock(&rx->call_lock);
if (test_and_clear_bit(RXRPC_CALL_HAS_USERID, &call->flags)) {
rb_erase(&call->sock_node, &rx->calls);
memset(&call->sock_node, 0xdd, sizeof(call->sock_node));
rxrpc_put_call(call, rxrpc_call_put_userid);
}
list_del(&call->sock_link);
write_unlock(&rx->call_lock);
_debug("RELEASE CALL %p (%d CONN %p)", call, call->debug_id, conn);
if (conn)
rxrpc_disconnect_call(call);
for (i = 0; i < RXRPC_RXTX_BUFF_SIZE; i++) {
rxrpc_free_skb(call->rxtx_buffer[i],
(call->tx_phase ? rxrpc_skb_tx_cleaned :
rxrpc_skb_rx_cleaned));
call->rxtx_buffer[i] = NULL;
}
_leave("");
}
void rxrpc_release_calls_on_socket(struct rxrpc_sock *rx)
{
struct rxrpc_call *call;
_enter("%p", rx);
while (!list_empty(&rx->to_be_accepted)) {
call = list_entry(rx->to_be_accepted.next,
struct rxrpc_call, accept_link);
list_del(&call->accept_link);
rxrpc_abort_call("SKR", call, 0, RX_CALL_DEAD, -ECONNRESET);
rxrpc_put_call(call, rxrpc_call_put);
}
while (!list_empty(&rx->sock_calls)) {
call = list_entry(rx->sock_calls.next,
struct rxrpc_call, sock_link);
rxrpc_get_call(call, rxrpc_call_got);
rxrpc_abort_call("SKT", call, 0, RX_CALL_DEAD, -ECONNRESET);
rxrpc_send_abort_packet(call);
rxrpc_release_call(rx, call);
rxrpc_put_call(call, rxrpc_call_put);
}
_leave("");
}
void rxrpc_put_call(struct rxrpc_call *call, enum rxrpc_call_trace op)
{
struct rxrpc_net *rxnet;
const void *here = __builtin_return_address(0);
int n;
ASSERT(call != NULL);
n = atomic_dec_return(&call->usage);
trace_rxrpc_call(call, op, n, here, NULL);
ASSERTCMP(n, >=, 0);
if (n == 0) {
_debug("call %d dead", call->debug_id);
ASSERTCMP(call->state, ==, RXRPC_CALL_COMPLETE);
if (!list_empty(&call->link)) {
rxnet = rxrpc_net(sock_net(&call->socket->sk));
write_lock(&rxnet->call_lock);
list_del_init(&call->link);
write_unlock(&rxnet->call_lock);
}
rxrpc_cleanup_call(call);
}
}
static void rxrpc_rcu_destroy_call(struct rcu_head *rcu)
{
struct rxrpc_call *call = container_of(rcu, struct rxrpc_call, rcu);
rxrpc_put_peer(call->peer);
kfree(call->rxtx_buffer);
kfree(call->rxtx_annotations);
kmem_cache_free(rxrpc_call_jar, call);
}
void rxrpc_cleanup_call(struct rxrpc_call *call)
{
int i;
_net("DESTROY CALL %d", call->debug_id);
memset(&call->sock_node, 0xcd, sizeof(call->sock_node));
del_timer_sync(&call->timer);
ASSERTCMP(call->state, ==, RXRPC_CALL_COMPLETE);
ASSERT(test_bit(RXRPC_CALL_RELEASED, &call->flags));
ASSERTCMP(call->conn, ==, NULL);
for (i = 0; i < RXRPC_RXTX_BUFF_SIZE; i++)
rxrpc_free_skb(call->rxtx_buffer[i],
(call->tx_phase ? rxrpc_skb_tx_cleaned :
rxrpc_skb_rx_cleaned));
rxrpc_free_skb(call->tx_pending, rxrpc_skb_tx_cleaned);
call_rcu(&call->rcu, rxrpc_rcu_destroy_call);
}
void rxrpc_destroy_all_calls(struct rxrpc_net *rxnet)
{
struct rxrpc_call *call;
_enter("");
if (list_empty(&rxnet->calls))
return;
write_lock(&rxnet->call_lock);
while (!list_empty(&rxnet->calls)) {
call = list_entry(rxnet->calls.next, struct rxrpc_call, link);
_debug("Zapping call %p", call);
rxrpc_see_call(call);
list_del_init(&call->link);
pr_err("Call %p still in use (%d,%s,%lx,%lx)!\n",
call, atomic_read(&call->usage),
rxrpc_call_states[call->state],
call->flags, call->events);
write_unlock(&rxnet->call_lock);
cond_resched();
write_lock(&rxnet->call_lock);
}
write_unlock(&rxnet->call_lock);
}
