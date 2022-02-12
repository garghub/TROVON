struct rxrpc_connection *rxrpc_alloc_connection(gfp_t gfp)
{
struct rxrpc_connection *conn;
_enter("");
conn = kzalloc(sizeof(struct rxrpc_connection), gfp);
if (conn) {
INIT_LIST_HEAD(&conn->cache_link);
spin_lock_init(&conn->channel_lock);
INIT_LIST_HEAD(&conn->waiting_calls);
INIT_WORK(&conn->processor, &rxrpc_process_connection);
INIT_LIST_HEAD(&conn->proc_link);
INIT_LIST_HEAD(&conn->link);
skb_queue_head_init(&conn->rx_queue);
conn->security = &rxrpc_no_security;
spin_lock_init(&conn->state_lock);
conn->debug_id = atomic_inc_return(&rxrpc_debug_id);
conn->size_align = 4;
conn->idle_timestamp = jiffies;
}
_leave(" = %p{%d}", conn, conn ? conn->debug_id : 0);
return conn;
}
struct rxrpc_connection *rxrpc_find_connection_rcu(struct rxrpc_local *local,
struct sk_buff *skb)
{
struct rxrpc_connection *conn;
struct rxrpc_conn_proto k;
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
struct sockaddr_rxrpc srx;
struct rxrpc_peer *peer;
_enter(",%x", sp->hdr.cid & RXRPC_CIDMASK);
if (rxrpc_extract_addr_from_skb(&srx, skb) < 0)
goto not_found;
k.epoch = sp->hdr.epoch;
k.cid = sp->hdr.cid & RXRPC_CIDMASK;
if (srx.transport.family != local->srx.transport.family) {
pr_warn_ratelimited("AF_RXRPC: Protocol mismatch %u not %u\n",
srx.transport.family,
local->srx.transport.family);
goto not_found;
}
k.epoch = sp->hdr.epoch;
k.cid = sp->hdr.cid & RXRPC_CIDMASK;
if (sp->hdr.flags & RXRPC_CLIENT_INITIATED) {
peer = rxrpc_lookup_peer_rcu(local, &srx);
if (!peer)
goto not_found;
conn = rxrpc_find_service_conn_rcu(peer, skb);
if (!conn || atomic_read(&conn->usage) == 0)
goto not_found;
_leave(" = %p", conn);
return conn;
} else {
conn = idr_find(&rxrpc_client_conn_ids,
sp->hdr.cid >> RXRPC_CIDSHIFT);
if (!conn || atomic_read(&conn->usage) == 0) {
_debug("no conn");
goto not_found;
}
if (conn->proto.epoch != k.epoch ||
conn->params.local != local)
goto not_found;
peer = conn->params.peer;
switch (srx.transport.family) {
case AF_INET:
if (peer->srx.transport.sin.sin_port !=
srx.transport.sin.sin_port ||
peer->srx.transport.sin.sin_addr.s_addr !=
srx.transport.sin.sin_addr.s_addr)
goto not_found;
break;
#ifdef CONFIG_AF_RXRPC_IPV6
case AF_INET6:
if (peer->srx.transport.sin6.sin6_port !=
srx.transport.sin6.sin6_port ||
memcmp(&peer->srx.transport.sin6.sin6_addr,
&srx.transport.sin6.sin6_addr,
sizeof(struct in6_addr)) != 0)
goto not_found;
break;
#endif
default:
BUG();
}
_leave(" = %p", conn);
return conn;
}
not_found:
_leave(" = NULL");
return NULL;
}
void __rxrpc_disconnect_call(struct rxrpc_connection *conn,
struct rxrpc_call *call)
{
struct rxrpc_channel *chan =
&conn->channels[call->cid & RXRPC_CHANNELMASK];
_enter("%d,%x", conn->debug_id, call->cid);
if (rcu_access_pointer(chan->call) == call) {
chan->last_service_id = call->service_id;
if (call->abort_code) {
chan->last_abort = call->abort_code;
chan->last_type = RXRPC_PACKET_TYPE_ABORT;
} else {
chan->last_seq = call->rx_hard_ack;
chan->last_type = RXRPC_PACKET_TYPE_ACK;
}
smp_wmb();
chan->last_call = chan->call_id;
chan->call_id = chan->call_counter;
rcu_assign_pointer(chan->call, NULL);
}
_leave("");
}
void rxrpc_disconnect_call(struct rxrpc_call *call)
{
struct rxrpc_connection *conn = call->conn;
spin_lock_bh(&conn->params.peer->lock);
hlist_del_init(&call->error_link);
spin_unlock_bh(&conn->params.peer->lock);
if (rxrpc_is_client_call(call))
return rxrpc_disconnect_client_call(call);
spin_lock(&conn->channel_lock);
__rxrpc_disconnect_call(conn, call);
spin_unlock(&conn->channel_lock);
call->conn = NULL;
conn->idle_timestamp = jiffies;
rxrpc_put_connection(conn);
}
void rxrpc_kill_connection(struct rxrpc_connection *conn)
{
ASSERT(!rcu_access_pointer(conn->channels[0].call) &&
!rcu_access_pointer(conn->channels[1].call) &&
!rcu_access_pointer(conn->channels[2].call) &&
!rcu_access_pointer(conn->channels[3].call));
ASSERT(list_empty(&conn->cache_link));
write_lock(&rxrpc_connection_lock);
list_del_init(&conn->proc_link);
write_unlock(&rxrpc_connection_lock);
rxrpc_purge_queue(&conn->rx_queue);
call_rcu(&conn->rcu, rxrpc_destroy_connection);
}
bool rxrpc_queue_conn(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
int n = __atomic_add_unless(&conn->usage, 1, 0);
if (n == 0)
return false;
if (rxrpc_queue_work(&conn->processor))
trace_rxrpc_conn(conn, rxrpc_conn_queued, n + 1, here);
else
rxrpc_put_connection(conn);
return true;
}
void rxrpc_see_connection(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
if (conn) {
int n = atomic_read(&conn->usage);
trace_rxrpc_conn(conn, rxrpc_conn_seen, n, here);
}
}
void rxrpc_get_connection(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
int n = atomic_inc_return(&conn->usage);
trace_rxrpc_conn(conn, rxrpc_conn_got, n, here);
}
struct rxrpc_connection *
rxrpc_get_connection_maybe(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
if (conn) {
int n = __atomic_add_unless(&conn->usage, 1, 0);
if (n > 0)
trace_rxrpc_conn(conn, rxrpc_conn_got, n + 1, here);
else
conn = NULL;
}
return conn;
}
void rxrpc_put_service_conn(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
int n;
n = atomic_dec_return(&conn->usage);
trace_rxrpc_conn(conn, rxrpc_conn_put_service, n, here);
ASSERTCMP(n, >=, 0);
if (n == 0)
rxrpc_queue_delayed_work(&rxrpc_connection_reap, 0);
}
static void rxrpc_destroy_connection(struct rcu_head *rcu)
{
struct rxrpc_connection *conn =
container_of(rcu, struct rxrpc_connection, rcu);
_enter("{%d,u=%d}", conn->debug_id, atomic_read(&conn->usage));
ASSERTCMP(atomic_read(&conn->usage), ==, 0);
_net("DESTROY CONN %d", conn->debug_id);
rxrpc_purge_queue(&conn->rx_queue);
conn->security->clear(conn);
key_put(conn->params.key);
key_put(conn->server_key);
rxrpc_put_peer(conn->params.peer);
rxrpc_put_local(conn->params.local);
kfree(conn);
_leave("");
}
static void rxrpc_connection_reaper(struct work_struct *work)
{
struct rxrpc_connection *conn, *_p;
unsigned long reap_older_than, earliest, idle_timestamp, now;
LIST_HEAD(graveyard);
_enter("");
now = jiffies;
reap_older_than = now - rxrpc_connection_expiry * HZ;
earliest = ULONG_MAX;
write_lock(&rxrpc_connection_lock);
list_for_each_entry_safe(conn, _p, &rxrpc_connections, link) {
ASSERTCMP(atomic_read(&conn->usage), >, 0);
if (likely(atomic_read(&conn->usage) > 1))
continue;
if (conn->state == RXRPC_CONN_SERVICE_PREALLOC)
continue;
idle_timestamp = READ_ONCE(conn->idle_timestamp);
_debug("reap CONN %d { u=%d,t=%ld }",
conn->debug_id, atomic_read(&conn->usage),
(long)reap_older_than - (long)idle_timestamp);
if (time_after(idle_timestamp, reap_older_than)) {
if (time_before(idle_timestamp, earliest))
earliest = idle_timestamp;
continue;
}
if (atomic_cmpxchg(&conn->usage, 1, 0) != 1)
continue;
if (rxrpc_conn_is_client(conn))
BUG();
else
rxrpc_unpublish_service_conn(conn);
list_move_tail(&conn->link, &graveyard);
}
write_unlock(&rxrpc_connection_lock);
if (earliest != ULONG_MAX) {
_debug("reschedule reaper %ld", (long) earliest - now);
ASSERT(time_after(earliest, now));
rxrpc_queue_delayed_work(&rxrpc_connection_reap,
earliest - now);
}
while (!list_empty(&graveyard)) {
conn = list_entry(graveyard.next, struct rxrpc_connection,
link);
list_del_init(&conn->link);
ASSERTCMP(atomic_read(&conn->usage), ==, 0);
rxrpc_kill_connection(conn);
}
_leave("");
}
void __exit rxrpc_destroy_all_connections(void)
{
struct rxrpc_connection *conn, *_p;
bool leak = false;
_enter("");
rxrpc_destroy_all_client_connections();
rxrpc_connection_expiry = 0;
cancel_delayed_work(&rxrpc_connection_reap);
rxrpc_queue_delayed_work(&rxrpc_connection_reap, 0);
flush_workqueue(rxrpc_workqueue);
write_lock(&rxrpc_connection_lock);
list_for_each_entry_safe(conn, _p, &rxrpc_connections, link) {
pr_err("AF_RXRPC: Leaked conn %p {%d}\n",
conn, atomic_read(&conn->usage));
leak = true;
}
write_unlock(&rxrpc_connection_lock);
BUG_ON(leak);
ASSERT(list_empty(&rxrpc_connection_proc_list));
rcu_barrier();
rxrpc_destroy_client_conn_ids();
_leave("");
}
