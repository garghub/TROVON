static int rxrpc_get_client_connection_id(struct rxrpc_connection *conn,
gfp_t gfp)
{
u32 epoch;
int id;
_enter("");
idr_preload(gfp);
spin_lock(&rxrpc_conn_id_lock);
epoch = rxrpc_epoch;
if (rxrpc_client_conn_ids.cur == 0)
rxrpc_client_conn_ids.cur = 1;
id = idr_alloc(&rxrpc_client_conn_ids, conn,
rxrpc_client_conn_ids.cur, 0x40000000, GFP_NOWAIT);
if (id < 0) {
if (id != -ENOSPC)
goto error;
id = idr_alloc(&rxrpc_client_conn_ids, conn,
1, 0x40000000, GFP_NOWAIT);
if (id < 0)
goto error;
epoch++;
rxrpc_epoch = epoch;
}
rxrpc_client_conn_ids.cur = id + 1;
spin_unlock(&rxrpc_conn_id_lock);
idr_preload_end();
conn->proto.epoch = epoch;
conn->proto.cid = id << RXRPC_CIDSHIFT;
set_bit(RXRPC_CONN_HAS_IDR, &conn->flags);
_leave(" [CID %x:%x]", epoch, conn->proto.cid);
return 0;
error:
spin_unlock(&rxrpc_conn_id_lock);
idr_preload_end();
_leave(" = %d", id);
return id;
}
static void rxrpc_put_client_connection_id(struct rxrpc_connection *conn)
{
if (test_bit(RXRPC_CONN_HAS_IDR, &conn->flags)) {
spin_lock(&rxrpc_conn_id_lock);
idr_remove(&rxrpc_client_conn_ids,
conn->proto.cid >> RXRPC_CIDSHIFT);
spin_unlock(&rxrpc_conn_id_lock);
}
}
void rxrpc_destroy_client_conn_ids(void)
{
struct rxrpc_connection *conn;
int id;
if (!idr_is_empty(&rxrpc_client_conn_ids)) {
idr_for_each_entry(&rxrpc_client_conn_ids, conn, id) {
pr_err("AF_RXRPC: Leaked client conn %p {%d}\n",
conn, atomic_read(&conn->usage));
}
BUG();
}
idr_destroy(&rxrpc_client_conn_ids);
}
static struct rxrpc_connection *
rxrpc_alloc_client_connection(struct rxrpc_conn_parameters *cp, gfp_t gfp)
{
struct rxrpc_connection *conn;
int ret;
_enter("");
conn = rxrpc_alloc_connection(gfp);
if (!conn) {
_leave(" = -ENOMEM");
return ERR_PTR(-ENOMEM);
}
conn->params = *cp;
conn->out_clientflag = RXRPC_CLIENT_INITIATED;
conn->state = RXRPC_CONN_CLIENT;
ret = rxrpc_get_client_connection_id(conn, gfp);
if (ret < 0)
goto error_0;
ret = rxrpc_init_client_conn_security(conn);
if (ret < 0)
goto error_1;
ret = conn->security->prime_packet_security(conn);
if (ret < 0)
goto error_2;
write_lock(&rxrpc_connection_lock);
list_add_tail(&conn->link, &rxrpc_connections);
write_unlock(&rxrpc_connection_lock);
cp->peer = NULL;
rxrpc_get_local(conn->params.local);
key_get(conn->params.key);
_leave(" = %p", conn);
return conn;
error_2:
conn->security->clear(conn);
error_1:
rxrpc_put_client_connection_id(conn);
error_0:
kfree(conn);
_leave(" = %d", ret);
return ERR_PTR(ret);
}
int rxrpc_connect_call(struct rxrpc_call *call,
struct rxrpc_conn_parameters *cp,
struct sockaddr_rxrpc *srx,
gfp_t gfp)
{
struct rxrpc_connection *conn, *candidate = NULL;
struct rxrpc_local *local = cp->local;
struct rb_node *p, **pp, *parent;
long diff;
int chan;
DECLARE_WAITQUEUE(myself, current);
_enter("{%d,%lx},", call->debug_id, call->user_call_ID);
cp->peer = rxrpc_lookup_peer(cp->local, srx, gfp);
if (!cp->peer)
return -ENOMEM;
if (!cp->exclusive) {
_debug("search 1");
spin_lock(&local->client_conns_lock);
p = local->client_conns.rb_node;
while (p) {
conn = rb_entry(p, struct rxrpc_connection, client_node);
#define cmp(X) ((long)conn->params.X - (long)cp->X)
diff = (cmp(peer) ?:
cmp(key) ?:
cmp(security_level));
if (diff < 0)
p = p->rb_left;
else if (diff > 0)
p = p->rb_right;
else
goto found_extant_conn;
}
spin_unlock(&local->client_conns_lock);
}
_debug("get new conn");
candidate = rxrpc_alloc_client_connection(cp, gfp);
if (!candidate) {
_leave(" = -ENOMEM");
return -ENOMEM;
}
if (cp->exclusive) {
_debug("exclusive chan 0");
conn = candidate;
atomic_set(&conn->avail_chans, RXRPC_MAXCALLS - 1);
spin_lock(&conn->channel_lock);
chan = 0;
goto found_channel;
}
_debug("search 2");
spin_lock(&local->client_conns_lock);
pp = &local->client_conns.rb_node;
parent = NULL;
while (*pp) {
parent = *pp;
conn = rb_entry(parent, struct rxrpc_connection, client_node);
diff = (cmp(peer) ?:
cmp(key) ?:
cmp(security_level));
if (diff < 0)
pp = &(*pp)->rb_left;
else if (diff > 0)
pp = &(*pp)->rb_right;
else
goto found_extant_conn;
}
_debug("new conn");
set_bit(RXRPC_CONN_IN_CLIENT_CONNS, &candidate->flags);
rb_link_node(&candidate->client_node, parent, pp);
rb_insert_color(&candidate->client_node, &local->client_conns);
attached:
conn = candidate;
candidate = NULL;
atomic_set(&conn->avail_chans, RXRPC_MAXCALLS - 1);
spin_lock(&conn->channel_lock);
spin_unlock(&local->client_conns_lock);
chan = 0;
found_channel:
_debug("found chan");
call->conn = conn;
call->channel = chan;
call->epoch = conn->proto.epoch;
call->cid = conn->proto.cid | chan;
call->call_id = ++conn->channels[chan].call_counter;
conn->channels[chan].call_id = call->call_id;
rcu_assign_pointer(conn->channels[chan].call, call);
_net("CONNECT call %d on conn %d", call->debug_id, conn->debug_id);
spin_unlock(&conn->channel_lock);
rxrpc_put_peer(cp->peer);
cp->peer = NULL;
_leave(" = %p {u=%d}", conn, atomic_read(&conn->usage));
return 0;
found_extant_conn:
_debug("found conn");
if (!rxrpc_get_connection_maybe(conn)) {
set_bit(RXRPC_CONN_IN_CLIENT_CONNS, &candidate->flags);
rb_replace_node(&conn->client_node,
&candidate->client_node,
&local->client_conns);
clear_bit(RXRPC_CONN_IN_CLIENT_CONNS, &conn->flags);
goto attached;
}
spin_unlock(&local->client_conns_lock);
rxrpc_put_connection(candidate);
if (!atomic_add_unless(&conn->avail_chans, -1, 0)) {
if (!gfpflags_allow_blocking(gfp)) {
rxrpc_put_connection(conn);
_leave(" = -EAGAIN");
return -EAGAIN;
}
add_wait_queue(&conn->channel_wq, &myself);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (atomic_add_unless(&conn->avail_chans, -1, 0))
break;
if (signal_pending(current))
goto interrupted;
schedule();
}
remove_wait_queue(&conn->channel_wq, &myself);
__set_current_state(TASK_RUNNING);
}
spin_lock(&conn->channel_lock);
for (chan = 0; chan < RXRPC_MAXCALLS; chan++)
if (!conn->channels[chan].call)
goto found_channel;
BUG();
interrupted:
remove_wait_queue(&conn->channel_wq, &myself);
__set_current_state(TASK_RUNNING);
rxrpc_put_connection(conn);
rxrpc_put_peer(cp->peer);
cp->peer = NULL;
_leave(" = -ERESTARTSYS");
return -ERESTARTSYS;
}
void rxrpc_unpublish_client_conn(struct rxrpc_connection *conn)
{
struct rxrpc_local *local = conn->params.local;
spin_lock(&local->client_conns_lock);
if (test_and_clear_bit(RXRPC_CONN_IN_CLIENT_CONNS, &conn->flags))
rb_erase(&conn->client_node, &local->client_conns);
spin_unlock(&local->client_conns_lock);
rxrpc_put_client_connection_id(conn);
}
