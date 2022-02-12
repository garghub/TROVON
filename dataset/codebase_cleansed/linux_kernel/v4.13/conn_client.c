static int rxrpc_get_client_connection_id(struct rxrpc_connection *conn,
gfp_t gfp)
{
struct rxrpc_net *rxnet = conn->params.local->rxnet;
int id;
_enter("");
idr_preload(gfp);
spin_lock(&rxrpc_conn_id_lock);
id = idr_alloc_cyclic(&rxrpc_client_conn_ids, conn,
1, 0x40000000, GFP_NOWAIT);
if (id < 0)
goto error;
spin_unlock(&rxrpc_conn_id_lock);
idr_preload_end();
conn->proto.epoch = rxnet->epoch;
conn->proto.cid = id << RXRPC_CIDSHIFT;
set_bit(RXRPC_CONN_HAS_IDR, &conn->flags);
_leave(" [CID %x]", conn->proto.cid);
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
struct rxrpc_net *rxnet = cp->local->rxnet;
int ret;
_enter("");
conn = rxrpc_alloc_connection(gfp);
if (!conn) {
_leave(" = -ENOMEM");
return ERR_PTR(-ENOMEM);
}
atomic_set(&conn->usage, 1);
if (cp->exclusive)
__set_bit(RXRPC_CONN_DONT_REUSE, &conn->flags);
if (cp->upgrade)
__set_bit(RXRPC_CONN_PROBING_FOR_UPGRADE, &conn->flags);
conn->params = *cp;
conn->out_clientflag = RXRPC_CLIENT_INITIATED;
conn->state = RXRPC_CONN_CLIENT;
conn->service_id = cp->service_id;
ret = rxrpc_get_client_connection_id(conn, gfp);
if (ret < 0)
goto error_0;
ret = rxrpc_init_client_conn_security(conn);
if (ret < 0)
goto error_1;
ret = conn->security->prime_packet_security(conn);
if (ret < 0)
goto error_2;
write_lock(&rxnet->conn_lock);
list_add_tail(&conn->proc_link, &rxnet->conn_proc_list);
write_unlock(&rxnet->conn_lock);
cp->peer = NULL;
rxrpc_get_local(conn->params.local);
key_get(conn->params.key);
trace_rxrpc_conn(conn, rxrpc_conn_new_client, atomic_read(&conn->usage),
__builtin_return_address(0));
trace_rxrpc_client(conn, -1, rxrpc_client_alloc);
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
static bool rxrpc_may_reuse_conn(struct rxrpc_connection *conn)
{
struct rxrpc_net *rxnet = conn->params.local->rxnet;
int id_cursor, id, distance, limit;
if (test_bit(RXRPC_CONN_DONT_REUSE, &conn->flags))
goto dont_reuse;
if (conn->proto.epoch != rxnet->epoch)
goto mark_dont_reuse;
id_cursor = idr_get_cursor(&rxrpc_client_conn_ids);
id = conn->proto.cid >> RXRPC_CIDSHIFT;
distance = id - id_cursor;
if (distance < 0)
distance = -distance;
limit = max(rxrpc_max_client_connections * 4, 1024U);
if (distance > limit)
goto mark_dont_reuse;
return true;
mark_dont_reuse:
set_bit(RXRPC_CONN_DONT_REUSE, &conn->flags);
dont_reuse:
return false;
}
static int rxrpc_get_client_conn(struct rxrpc_call *call,
struct rxrpc_conn_parameters *cp,
struct sockaddr_rxrpc *srx,
gfp_t gfp)
{
struct rxrpc_connection *conn, *candidate = NULL;
struct rxrpc_local *local = cp->local;
struct rb_node *p, **pp, *parent;
long diff;
int ret = -ENOMEM;
_enter("{%d,%lx},", call->debug_id, call->user_call_ID);
cp->peer = rxrpc_lookup_peer(cp->local, srx, gfp);
if (!cp->peer)
goto error;
call->cong_cwnd = cp->peer->cong_cwnd;
if (call->cong_cwnd >= call->cong_ssthresh)
call->cong_mode = RXRPC_CALL_CONGEST_AVOIDANCE;
else
call->cong_mode = RXRPC_CALL_SLOW_START;
if (!cp->exclusive) {
_debug("search 1");
spin_lock(&local->client_conns_lock);
p = local->client_conns.rb_node;
while (p) {
conn = rb_entry(p, struct rxrpc_connection, client_node);
#define cmp(X) ((long)conn->params.X - (long)cp->X)
diff = (cmp(peer) ?:
cmp(key) ?:
cmp(security_level) ?:
cmp(upgrade));
#undef cmp
if (diff < 0) {
p = p->rb_left;
} else if (diff > 0) {
p = p->rb_right;
} else {
if (rxrpc_may_reuse_conn(conn) &&
rxrpc_get_connection_maybe(conn))
goto found_extant_conn;
break;
}
}
spin_unlock(&local->client_conns_lock);
}
_debug("new conn");
candidate = rxrpc_alloc_client_connection(cp, gfp);
if (IS_ERR(candidate)) {
ret = PTR_ERR(candidate);
goto error_peer;
}
list_add_tail(&call->chan_wait_link, &candidate->waiting_calls);
if (cp->exclusive) {
call->conn = candidate;
call->security_ix = candidate->security_ix;
call->service_id = candidate->service_id;
_leave(" = 0 [exclusive %d]", candidate->debug_id);
return 0;
}
_debug("search 2");
spin_lock(&local->client_conns_lock);
pp = &local->client_conns.rb_node;
parent = NULL;
while (*pp) {
parent = *pp;
conn = rb_entry(parent, struct rxrpc_connection, client_node);
#define cmp(X) ((long)conn->params.X - (long)candidate->params.X)
diff = (cmp(peer) ?:
cmp(key) ?:
cmp(security_level) ?:
cmp(upgrade));
#undef cmp
if (diff < 0) {
pp = &(*pp)->rb_left;
} else if (diff > 0) {
pp = &(*pp)->rb_right;
} else {
if (rxrpc_may_reuse_conn(conn) &&
rxrpc_get_connection_maybe(conn))
goto found_extant_conn;
_debug("replace conn");
clear_bit(RXRPC_CONN_IN_CLIENT_CONNS, &conn->flags);
rb_replace_node(&conn->client_node,
&candidate->client_node,
&local->client_conns);
trace_rxrpc_client(conn, -1, rxrpc_client_replace);
goto candidate_published;
}
}
_debug("new conn");
rb_link_node(&candidate->client_node, parent, pp);
rb_insert_color(&candidate->client_node, &local->client_conns);
candidate_published:
set_bit(RXRPC_CONN_IN_CLIENT_CONNS, &candidate->flags);
call->conn = candidate;
call->security_ix = candidate->security_ix;
call->service_id = candidate->service_id;
spin_unlock(&local->client_conns_lock);
_leave(" = 0 [new %d]", candidate->debug_id);
return 0;
found_extant_conn:
_debug("found conn");
spin_unlock(&local->client_conns_lock);
if (candidate) {
trace_rxrpc_client(candidate, -1, rxrpc_client_duplicate);
rxrpc_put_connection(candidate);
candidate = NULL;
}
spin_lock(&conn->channel_lock);
call->conn = conn;
call->security_ix = conn->security_ix;
call->service_id = conn->service_id;
list_add(&call->chan_wait_link, &conn->waiting_calls);
spin_unlock(&conn->channel_lock);
_leave(" = 0 [extant %d]", conn->debug_id);
return 0;
error_peer:
rxrpc_put_peer(cp->peer);
cp->peer = NULL;
error:
_leave(" = %d", ret);
return ret;
}
static void rxrpc_activate_conn(struct rxrpc_net *rxnet,
struct rxrpc_connection *conn)
{
if (test_bit(RXRPC_CONN_PROBING_FOR_UPGRADE, &conn->flags)) {
trace_rxrpc_client(conn, -1, rxrpc_client_to_upgrade);
conn->cache_state = RXRPC_CONN_CLIENT_UPGRADE;
} else {
trace_rxrpc_client(conn, -1, rxrpc_client_to_active);
conn->cache_state = RXRPC_CONN_CLIENT_ACTIVE;
}
rxnet->nr_active_client_conns++;
list_move_tail(&conn->cache_link, &rxnet->active_client_conns);
}
static void rxrpc_animate_client_conn(struct rxrpc_net *rxnet,
struct rxrpc_connection *conn)
{
unsigned int nr_conns;
_enter("%d,%d", conn->debug_id, conn->cache_state);
if (conn->cache_state == RXRPC_CONN_CLIENT_ACTIVE ||
conn->cache_state == RXRPC_CONN_CLIENT_UPGRADE)
goto out;
spin_lock(&rxnet->client_conn_cache_lock);
nr_conns = rxnet->nr_client_conns;
if (!test_and_set_bit(RXRPC_CONN_COUNTED, &conn->flags)) {
trace_rxrpc_client(conn, -1, rxrpc_client_count);
rxnet->nr_client_conns = nr_conns + 1;
}
switch (conn->cache_state) {
case RXRPC_CONN_CLIENT_ACTIVE:
case RXRPC_CONN_CLIENT_UPGRADE:
case RXRPC_CONN_CLIENT_WAITING:
break;
case RXRPC_CONN_CLIENT_INACTIVE:
case RXRPC_CONN_CLIENT_CULLED:
case RXRPC_CONN_CLIENT_IDLE:
if (nr_conns >= rxrpc_max_client_connections)
goto wait_for_capacity;
goto activate_conn;
default:
BUG();
}
out_unlock:
spin_unlock(&rxnet->client_conn_cache_lock);
out:
_leave(" [%d]", conn->cache_state);
return;
activate_conn:
_debug("activate");
rxrpc_activate_conn(rxnet, conn);
goto out_unlock;
wait_for_capacity:
_debug("wait");
trace_rxrpc_client(conn, -1, rxrpc_client_to_waiting);
conn->cache_state = RXRPC_CONN_CLIENT_WAITING;
list_move_tail(&conn->cache_link, &rxnet->waiting_client_conns);
goto out_unlock;
}
static void rxrpc_deactivate_one_channel(struct rxrpc_connection *conn,
unsigned int channel)
{
struct rxrpc_channel *chan = &conn->channels[channel];
rcu_assign_pointer(chan->call, NULL);
conn->active_chans &= ~(1 << channel);
}
static void rxrpc_activate_one_channel(struct rxrpc_connection *conn,
unsigned int channel)
{
struct rxrpc_channel *chan = &conn->channels[channel];
struct rxrpc_call *call = list_entry(conn->waiting_calls.next,
struct rxrpc_call, chan_wait_link);
u32 call_id = chan->call_counter + 1;
trace_rxrpc_client(conn, channel, rxrpc_client_chan_activate);
write_lock_bh(&call->state_lock);
call->state = RXRPC_CALL_CLIENT_SEND_REQUEST;
write_unlock_bh(&call->state_lock);
rxrpc_see_call(call);
list_del_init(&call->chan_wait_link);
conn->active_chans |= 1 << channel;
call->peer = rxrpc_get_peer(conn->params.peer);
call->cid = conn->proto.cid | channel;
call->call_id = call_id;
trace_rxrpc_connect_call(call);
_net("CONNECT call %08x:%08x as call %d on conn %d",
call->cid, call->call_id, call->debug_id, conn->debug_id);
smp_wmb();
chan->call_id = call_id;
rcu_assign_pointer(chan->call, call);
wake_up(&call->waitq);
}
static void rxrpc_activate_channels_locked(struct rxrpc_connection *conn)
{
u8 avail, mask;
switch (conn->cache_state) {
case RXRPC_CONN_CLIENT_ACTIVE:
mask = RXRPC_ACTIVE_CHANS_MASK;
break;
case RXRPC_CONN_CLIENT_UPGRADE:
mask = 0x01;
break;
default:
return;
}
while (!list_empty(&conn->waiting_calls) &&
(avail = ~conn->active_chans,
avail &= mask,
avail != 0))
rxrpc_activate_one_channel(conn, __ffs(avail));
}
static void rxrpc_activate_channels(struct rxrpc_connection *conn)
{
_enter("%d", conn->debug_id);
trace_rxrpc_client(conn, -1, rxrpc_client_activate_chans);
if (conn->active_chans == RXRPC_ACTIVE_CHANS_MASK)
return;
spin_lock(&conn->channel_lock);
rxrpc_activate_channels_locked(conn);
spin_unlock(&conn->channel_lock);
_leave("");
}
static int rxrpc_wait_for_channel(struct rxrpc_call *call, gfp_t gfp)
{
int ret = 0;
_enter("%d", call->debug_id);
if (!call->call_id) {
DECLARE_WAITQUEUE(myself, current);
if (!gfpflags_allow_blocking(gfp)) {
ret = -EAGAIN;
goto out;
}
add_wait_queue_exclusive(&call->waitq, &myself);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (call->call_id)
break;
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
schedule();
}
remove_wait_queue(&call->waitq, &myself);
__set_current_state(TASK_RUNNING);
}
smp_rmb();
out:
_leave(" = %d", ret);
return ret;
}
int rxrpc_connect_call(struct rxrpc_call *call,
struct rxrpc_conn_parameters *cp,
struct sockaddr_rxrpc *srx,
gfp_t gfp)
{
struct rxrpc_net *rxnet = cp->local->rxnet;
int ret;
_enter("{%d,%lx},", call->debug_id, call->user_call_ID);
rxrpc_discard_expired_client_conns(&rxnet->client_conn_reaper.work);
rxrpc_cull_active_client_conns(rxnet);
ret = rxrpc_get_client_conn(call, cp, srx, gfp);
if (ret < 0)
return ret;
rxrpc_animate_client_conn(rxnet, call->conn);
rxrpc_activate_channels(call->conn);
ret = rxrpc_wait_for_channel(call, gfp);
if (ret < 0)
rxrpc_disconnect_client_call(call);
_leave(" = %d", ret);
return ret;
}
static void rxrpc_expose_client_conn(struct rxrpc_connection *conn,
unsigned int channel)
{
if (!test_and_set_bit(RXRPC_CONN_EXPOSED, &conn->flags)) {
trace_rxrpc_client(conn, channel, rxrpc_client_exposed);
rxrpc_get_connection(conn);
}
}
void rxrpc_expose_client_call(struct rxrpc_call *call)
{
unsigned int channel = call->cid & RXRPC_CHANNELMASK;
struct rxrpc_connection *conn = call->conn;
struct rxrpc_channel *chan = &conn->channels[channel];
if (!test_and_set_bit(RXRPC_CALL_EXPOSED, &call->flags)) {
chan->call_counter++;
if (chan->call_counter >= INT_MAX)
set_bit(RXRPC_CONN_DONT_REUSE, &conn->flags);
rxrpc_expose_client_conn(conn, channel);
}
}
void rxrpc_disconnect_client_call(struct rxrpc_call *call)
{
unsigned int channel = call->cid & RXRPC_CHANNELMASK;
struct rxrpc_connection *conn = call->conn;
struct rxrpc_channel *chan = &conn->channels[channel];
struct rxrpc_net *rxnet = rxrpc_net(sock_net(&call->socket->sk));
trace_rxrpc_client(conn, channel, rxrpc_client_chan_disconnect);
call->conn = NULL;
spin_lock(&conn->channel_lock);
if (!list_empty(&call->chan_wait_link)) {
_debug("call is waiting");
ASSERTCMP(call->call_id, ==, 0);
ASSERT(!test_bit(RXRPC_CALL_EXPOSED, &call->flags));
list_del_init(&call->chan_wait_link);
trace_rxrpc_client(conn, channel, rxrpc_client_chan_unstarted);
spin_lock(&rxnet->client_conn_cache_lock);
if (conn->cache_state == RXRPC_CONN_CLIENT_WAITING &&
list_empty(&conn->waiting_calls) &&
!conn->active_chans)
goto idle_connection;
goto out;
}
ASSERTCMP(rcu_access_pointer(chan->call), ==, call);
if (test_bit(RXRPC_CALL_EXPOSED, &call->flags)) {
_debug("exposed %u,%u", call->call_id, call->abort_code);
__rxrpc_disconnect_call(conn, call);
}
if (conn->cache_state == RXRPC_CONN_CLIENT_ACTIVE &&
!list_empty(&conn->waiting_calls)) {
trace_rxrpc_client(conn, channel, rxrpc_client_chan_pass);
rxrpc_activate_one_channel(conn, channel);
goto out_2;
}
spin_lock(&rxnet->client_conn_cache_lock);
switch (conn->cache_state) {
case RXRPC_CONN_CLIENT_UPGRADE:
if (test_bit(RXRPC_CONN_EXPOSED, &conn->flags)) {
clear_bit(RXRPC_CONN_PROBING_FOR_UPGRADE, &conn->flags);
trace_rxrpc_client(conn, channel, rxrpc_client_to_active);
conn->cache_state = RXRPC_CONN_CLIENT_ACTIVE;
rxrpc_activate_channels_locked(conn);
}
case RXRPC_CONN_CLIENT_ACTIVE:
if (list_empty(&conn->waiting_calls)) {
rxrpc_deactivate_one_channel(conn, channel);
if (!conn->active_chans) {
rxnet->nr_active_client_conns--;
goto idle_connection;
}
goto out;
}
trace_rxrpc_client(conn, channel, rxrpc_client_chan_pass);
rxrpc_activate_one_channel(conn, channel);
goto out;
case RXRPC_CONN_CLIENT_CULLED:
rxrpc_deactivate_one_channel(conn, channel);
ASSERT(list_empty(&conn->waiting_calls));
if (!conn->active_chans)
goto idle_connection;
goto out;
case RXRPC_CONN_CLIENT_WAITING:
rxrpc_deactivate_one_channel(conn, channel);
goto out;
default:
BUG();
}
out:
spin_unlock(&rxnet->client_conn_cache_lock);
out_2:
spin_unlock(&conn->channel_lock);
rxrpc_put_connection(conn);
_leave("");
return;
idle_connection:
if (test_bit(RXRPC_CONN_EXPOSED, &conn->flags)) {
trace_rxrpc_client(conn, channel, rxrpc_client_to_idle);
conn->idle_timestamp = jiffies;
conn->cache_state = RXRPC_CONN_CLIENT_IDLE;
list_move_tail(&conn->cache_link, &rxnet->idle_client_conns);
if (rxnet->idle_client_conns.next == &conn->cache_link &&
!rxnet->kill_all_client_conns)
queue_delayed_work(rxrpc_workqueue,
&rxnet->client_conn_reaper,
rxrpc_conn_idle_client_expiry);
} else {
trace_rxrpc_client(conn, channel, rxrpc_client_to_inactive);
conn->cache_state = RXRPC_CONN_CLIENT_INACTIVE;
list_del_init(&conn->cache_link);
}
goto out;
}
static struct rxrpc_connection *
rxrpc_put_one_client_conn(struct rxrpc_connection *conn)
{
struct rxrpc_connection *next = NULL;
struct rxrpc_local *local = conn->params.local;
struct rxrpc_net *rxnet = local->rxnet;
unsigned int nr_conns;
trace_rxrpc_client(conn, -1, rxrpc_client_cleanup);
if (test_bit(RXRPC_CONN_IN_CLIENT_CONNS, &conn->flags)) {
spin_lock(&local->client_conns_lock);
if (test_and_clear_bit(RXRPC_CONN_IN_CLIENT_CONNS,
&conn->flags))
rb_erase(&conn->client_node, &local->client_conns);
spin_unlock(&local->client_conns_lock);
}
rxrpc_put_client_connection_id(conn);
ASSERTCMP(conn->cache_state, ==, RXRPC_CONN_CLIENT_INACTIVE);
if (test_bit(RXRPC_CONN_COUNTED, &conn->flags)) {
trace_rxrpc_client(conn, -1, rxrpc_client_uncount);
spin_lock(&rxnet->client_conn_cache_lock);
nr_conns = --rxnet->nr_client_conns;
if (nr_conns < rxrpc_max_client_connections &&
!list_empty(&rxnet->waiting_client_conns)) {
next = list_entry(rxnet->waiting_client_conns.next,
struct rxrpc_connection, cache_link);
rxrpc_get_connection(next);
rxrpc_activate_conn(rxnet, next);
}
spin_unlock(&rxnet->client_conn_cache_lock);
}
rxrpc_kill_connection(conn);
if (next)
rxrpc_activate_channels(next);
return next;
}
void rxrpc_put_client_conn(struct rxrpc_connection *conn)
{
const void *here = __builtin_return_address(0);
int n;
do {
n = atomic_dec_return(&conn->usage);
trace_rxrpc_conn(conn, rxrpc_conn_put_client, n, here);
if (n > 0)
return;
ASSERTCMP(n, >=, 0);
conn = rxrpc_put_one_client_conn(conn);
} while (conn);
}
static void rxrpc_cull_active_client_conns(struct rxrpc_net *rxnet)
{
struct rxrpc_connection *conn;
unsigned int nr_conns = rxnet->nr_client_conns;
unsigned int nr_active, limit;
_enter("");
ASSERTCMP(nr_conns, >=, 0);
if (nr_conns < rxrpc_max_client_connections) {
_leave(" [ok]");
return;
}
limit = rxrpc_reap_client_connections;
spin_lock(&rxnet->client_conn_cache_lock);
nr_active = rxnet->nr_active_client_conns;
while (nr_active > limit) {
ASSERT(!list_empty(&rxnet->active_client_conns));
conn = list_entry(rxnet->active_client_conns.next,
struct rxrpc_connection, cache_link);
ASSERTIFCMP(conn->cache_state != RXRPC_CONN_CLIENT_ACTIVE,
conn->cache_state, ==, RXRPC_CONN_CLIENT_UPGRADE);
if (list_empty(&conn->waiting_calls)) {
trace_rxrpc_client(conn, -1, rxrpc_client_to_culled);
conn->cache_state = RXRPC_CONN_CLIENT_CULLED;
list_del_init(&conn->cache_link);
} else {
trace_rxrpc_client(conn, -1, rxrpc_client_to_waiting);
conn->cache_state = RXRPC_CONN_CLIENT_WAITING;
list_move_tail(&conn->cache_link,
&rxnet->waiting_client_conns);
}
nr_active--;
}
rxnet->nr_active_client_conns = nr_active;
spin_unlock(&rxnet->client_conn_cache_lock);
ASSERTCMP(nr_active, >=, 0);
_leave(" [culled]");
}
void rxrpc_discard_expired_client_conns(struct work_struct *work)
{
struct rxrpc_connection *conn;
struct rxrpc_net *rxnet =
container_of(to_delayed_work(work),
struct rxrpc_net, client_conn_reaper);
unsigned long expiry, conn_expires_at, now;
unsigned int nr_conns;
bool did_discard = false;
_enter("");
if (list_empty(&rxnet->idle_client_conns)) {
_leave(" [empty]");
return;
}
if (!spin_trylock(&rxnet->client_conn_discard_lock)) {
_leave(" [already]");
return;
}
nr_conns = rxnet->nr_client_conns;
next:
spin_lock(&rxnet->client_conn_cache_lock);
if (list_empty(&rxnet->idle_client_conns))
goto out;
conn = list_entry(rxnet->idle_client_conns.next,
struct rxrpc_connection, cache_link);
ASSERT(test_bit(RXRPC_CONN_EXPOSED, &conn->flags));
if (!rxnet->kill_all_client_conns) {
expiry = rxrpc_conn_idle_client_expiry;
if (nr_conns > rxrpc_reap_client_connections)
expiry = rxrpc_conn_idle_client_fast_expiry;
conn_expires_at = conn->idle_timestamp + expiry;
now = READ_ONCE(jiffies);
if (time_after(conn_expires_at, now))
goto not_yet_expired;
}
trace_rxrpc_client(conn, -1, rxrpc_client_discard);
if (!test_and_clear_bit(RXRPC_CONN_EXPOSED, &conn->flags))
BUG();
conn->cache_state = RXRPC_CONN_CLIENT_INACTIVE;
list_del_init(&conn->cache_link);
spin_unlock(&rxnet->client_conn_cache_lock);
rxrpc_put_connection(conn);
did_discard = true;
nr_conns--;
goto next;
not_yet_expired:
_debug("not yet");
if (!rxnet->kill_all_client_conns)
queue_delayed_work(rxrpc_workqueue,
&rxnet->client_conn_reaper,
conn_expires_at - now);
out:
spin_unlock(&rxnet->client_conn_cache_lock);
spin_unlock(&rxnet->client_conn_discard_lock);
_leave("");
}
void rxrpc_destroy_all_client_connections(struct rxrpc_net *rxnet)
{
_enter("");
spin_lock(&rxnet->client_conn_cache_lock);
rxnet->kill_all_client_conns = true;
spin_unlock(&rxnet->client_conn_cache_lock);
cancel_delayed_work(&rxnet->client_conn_reaper);
if (!queue_delayed_work(rxrpc_workqueue, &rxnet->client_conn_reaper, 0))
_debug("destroy: queue failed");
_leave("");
}
