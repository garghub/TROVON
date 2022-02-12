struct rxrpc_connection *rxrpc_alloc_connection(gfp_t gfp)
{
struct rxrpc_connection *conn;
_enter("");
conn = kzalloc(sizeof(struct rxrpc_connection), gfp);
if (conn) {
spin_lock_init(&conn->channel_lock);
init_waitqueue_head(&conn->channel_wq);
INIT_WORK(&conn->processor, &rxrpc_process_connection);
INIT_LIST_HEAD(&conn->link);
skb_queue_head_init(&conn->rx_queue);
conn->security = &rxrpc_no_security;
spin_lock_init(&conn->state_lock);
atomic_set(&conn->usage, 2);
conn->debug_id = atomic_inc_return(&rxrpc_debug_id);
atomic_set(&conn->avail_chans, RXRPC_MAXCALLS);
conn->size_align = 4;
conn->header_size = sizeof(struct rxrpc_wire_header);
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
void __rxrpc_disconnect_call(struct rxrpc_call *call)
{
struct rxrpc_connection *conn = call->conn;
struct rxrpc_channel *chan = &conn->channels[call->channel];
_enter("%d,%d", conn->debug_id, call->channel);
if (rcu_access_pointer(chan->call) == call) {
chan->last_result = call->local_abort;
smp_wmb();
chan->last_call = chan->call_id;
chan->call_id = chan->call_counter;
rcu_assign_pointer(chan->call, NULL);
atomic_inc(&conn->avail_chans);
wake_up(&conn->channel_wq);
}
_leave("");
}
void rxrpc_disconnect_call(struct rxrpc_call *call)
{
struct rxrpc_connection *conn = call->conn;
spin_lock(&conn->channel_lock);
__rxrpc_disconnect_call(call);
spin_unlock(&conn->channel_lock);
call->conn = NULL;
rxrpc_put_connection(conn);
}
void rxrpc_put_connection(struct rxrpc_connection *conn)
{
if (!conn)
return;
_enter("%p{u=%d,d=%d}",
conn, atomic_read(&conn->usage), conn->debug_id);
ASSERTCMP(atomic_read(&conn->usage), >, 1);
conn->put_time = ktime_get_seconds();
if (atomic_dec_return(&conn->usage) == 1) {
_debug("zombie");
rxrpc_queue_delayed_work(&rxrpc_connection_reap, 0);
}
_leave("");
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
unsigned long reap_older_than, earliest, put_time, now;
LIST_HEAD(graveyard);
_enter("");
now = ktime_get_seconds();
reap_older_than = now - rxrpc_connection_expiry;
earliest = ULONG_MAX;
write_lock(&rxrpc_connection_lock);
list_for_each_entry_safe(conn, _p, &rxrpc_connections, link) {
ASSERTCMP(atomic_read(&conn->usage), >, 0);
if (likely(atomic_read(&conn->usage) > 1))
continue;
put_time = READ_ONCE(conn->put_time);
if (time_after(put_time, reap_older_than)) {
if (time_before(put_time, earliest))
earliest = put_time;
continue;
}
if (atomic_cmpxchg(&conn->usage, 1, 0) != 1)
continue;
if (rxrpc_conn_is_client(conn))
rxrpc_unpublish_client_conn(conn);
else
rxrpc_unpublish_service_conn(conn);
list_move_tail(&conn->link, &graveyard);
}
write_unlock(&rxrpc_connection_lock);
if (earliest != ULONG_MAX) {
_debug("reschedule reaper %ld", (long) earliest - now);
ASSERTCMP(earliest, >, now);
rxrpc_queue_delayed_work(&rxrpc_connection_reap,
(earliest - now) * HZ);
}
while (!list_empty(&graveyard)) {
conn = list_entry(graveyard.next, struct rxrpc_connection,
link);
list_del_init(&conn->link);
ASSERTCMP(atomic_read(&conn->usage), ==, 0);
skb_queue_purge(&conn->rx_queue);
call_rcu(&conn->rcu, rxrpc_destroy_connection);
}
_leave("");
}
void __exit rxrpc_destroy_all_connections(void)
{
struct rxrpc_connection *conn, *_p;
bool leak = false;
_enter("");
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
rcu_barrier();
rxrpc_destroy_client_conn_ids();
_leave("");
}
