static long rxrpc_local_cmp_key(const struct rxrpc_local *local,
const struct sockaddr_rxrpc *srx)
{
long diff;
diff = ((local->srx.transport_type - srx->transport_type) ?:
(local->srx.transport_len - srx->transport_len) ?:
(local->srx.transport.family - srx->transport.family));
if (diff != 0)
return diff;
switch (srx->transport.family) {
case AF_INET:
return ((u16 __force)local->srx.transport.sin.sin_port -
(u16 __force)srx->transport.sin.sin_port) ?:
memcmp(&local->srx.transport.sin.sin_addr,
&srx->transport.sin.sin_addr,
sizeof(struct in_addr));
#ifdef CONFIG_AF_RXRPC_IPV6
case AF_INET6:
return ((u16 __force)local->srx.transport.sin6.sin6_port -
(u16 __force)srx->transport.sin6.sin6_port) ?:
memcmp(&local->srx.transport.sin6.sin6_addr,
&srx->transport.sin6.sin6_addr,
sizeof(struct in6_addr));
#endif
default:
BUG();
}
}
static struct rxrpc_local *rxrpc_alloc_local(const struct sockaddr_rxrpc *srx)
{
struct rxrpc_local *local;
local = kzalloc(sizeof(struct rxrpc_local), GFP_KERNEL);
if (local) {
atomic_set(&local->usage, 1);
INIT_LIST_HEAD(&local->link);
INIT_WORK(&local->processor, rxrpc_local_processor);
init_rwsem(&local->defrag_sem);
skb_queue_head_init(&local->reject_queue);
skb_queue_head_init(&local->event_queue);
local->client_conns = RB_ROOT;
spin_lock_init(&local->client_conns_lock);
spin_lock_init(&local->lock);
rwlock_init(&local->services_lock);
local->debug_id = atomic_inc_return(&rxrpc_debug_id);
memcpy(&local->srx, srx, sizeof(*srx));
}
_leave(" = %p", local);
return local;
}
static int rxrpc_open_socket(struct rxrpc_local *local)
{
struct sock *sock;
int ret, opt;
_enter("%p{%d,%d}",
local, local->srx.transport_type, local->srx.transport.family);
ret = sock_create_kern(&init_net, local->srx.transport.family,
local->srx.transport_type, 0, &local->socket);
if (ret < 0) {
_leave(" = %d [socket]", ret);
return ret;
}
if (local->srx.transport_len > sizeof(sa_family_t)) {
_debug("bind");
ret = kernel_bind(local->socket,
(struct sockaddr *)&local->srx.transport,
local->srx.transport_len);
if (ret < 0) {
_debug("bind failed %d", ret);
goto error;
}
}
opt = 1;
ret = kernel_setsockopt(local->socket, SOL_IP, IP_RECVERR,
(char *) &opt, sizeof(opt));
if (ret < 0) {
_debug("setsockopt failed");
goto error;
}
opt = IP_PMTUDISC_DO;
ret = kernel_setsockopt(local->socket, SOL_IP, IP_MTU_DISCOVER,
(char *) &opt, sizeof(opt));
if (ret < 0) {
_debug("setsockopt failed");
goto error;
}
sock = local->socket->sk;
sock->sk_user_data = local;
sock->sk_data_ready = rxrpc_data_ready;
sock->sk_error_report = rxrpc_error_report;
_leave(" = 0");
return 0;
error:
kernel_sock_shutdown(local->socket, SHUT_RDWR);
local->socket->sk->sk_user_data = NULL;
sock_release(local->socket);
local->socket = NULL;
_leave(" = %d", ret);
return ret;
}
struct rxrpc_local *rxrpc_lookup_local(const struct sockaddr_rxrpc *srx)
{
struct rxrpc_local *local;
struct list_head *cursor;
const char *age;
long diff;
int ret;
_enter("{%d,%d,%pISp}",
srx->transport_type, srx->transport.family, &srx->transport);
mutex_lock(&rxrpc_local_mutex);
for (cursor = rxrpc_local_endpoints.next;
cursor != &rxrpc_local_endpoints;
cursor = cursor->next) {
local = list_entry(cursor, struct rxrpc_local, link);
diff = rxrpc_local_cmp_key(local, srx);
if (diff < 0)
continue;
if (diff > 0)
break;
if (srx->srx_service) {
local = NULL;
goto addr_in_use;
}
if (!rxrpc_get_local_maybe(local)) {
cursor = cursor->next;
list_del_init(&local->link);
break;
}
age = "old";
goto found;
}
local = rxrpc_alloc_local(srx);
if (!local)
goto nomem;
ret = rxrpc_open_socket(local);
if (ret < 0)
goto sock_error;
list_add_tail(&local->link, cursor);
age = "new";
found:
mutex_unlock(&rxrpc_local_mutex);
_net("LOCAL %s %d {%pISp}",
age, local->debug_id, &local->srx.transport);
_leave(" = %p", local);
return local;
nomem:
ret = -ENOMEM;
sock_error:
mutex_unlock(&rxrpc_local_mutex);
kfree(local);
_leave(" = %d", ret);
return ERR_PTR(ret);
addr_in_use:
mutex_unlock(&rxrpc_local_mutex);
_leave(" = -EADDRINUSE");
return ERR_PTR(-EADDRINUSE);
}
void __rxrpc_put_local(struct rxrpc_local *local)
{
_enter("%d", local->debug_id);
rxrpc_queue_work(&local->processor);
}
static void rxrpc_local_destroyer(struct rxrpc_local *local)
{
struct socket *socket = local->socket;
_enter("%d", local->debug_id);
if (local->dead) {
_leave(" [already dead]");
return;
}
local->dead = true;
mutex_lock(&rxrpc_local_mutex);
list_del_init(&local->link);
mutex_unlock(&rxrpc_local_mutex);
ASSERT(RB_EMPTY_ROOT(&local->client_conns));
ASSERT(!local->service);
if (socket) {
local->socket = NULL;
kernel_sock_shutdown(socket, SHUT_RDWR);
socket->sk->sk_user_data = NULL;
sock_release(socket);
}
rxrpc_purge_queue(&local->reject_queue);
rxrpc_purge_queue(&local->event_queue);
_debug("rcu local %d", local->debug_id);
call_rcu(&local->rcu, rxrpc_local_rcu);
}
static void rxrpc_local_processor(struct work_struct *work)
{
struct rxrpc_local *local =
container_of(work, struct rxrpc_local, processor);
bool again;
_enter("%d", local->debug_id);
do {
again = false;
if (atomic_read(&local->usage) == 0)
return rxrpc_local_destroyer(local);
if (!skb_queue_empty(&local->reject_queue)) {
rxrpc_reject_packets(local);
again = true;
}
if (!skb_queue_empty(&local->event_queue)) {
rxrpc_process_local_events(local);
again = true;
}
} while (again);
}
static void rxrpc_local_rcu(struct rcu_head *rcu)
{
struct rxrpc_local *local = container_of(rcu, struct rxrpc_local, rcu);
_enter("%d", local->debug_id);
ASSERT(!work_pending(&local->processor));
_net("DESTROY LOCAL %d", local->debug_id);
kfree(local);
_leave("");
}
void __exit rxrpc_destroy_all_locals(void)
{
struct rxrpc_local *local;
_enter("");
flush_workqueue(rxrpc_workqueue);
if (!list_empty(&rxrpc_local_endpoints)) {
mutex_lock(&rxrpc_local_mutex);
list_for_each_entry(local, &rxrpc_local_endpoints, link) {
pr_err("AF_RXRPC: Leaked local %p {%d}\n",
local, atomic_read(&local->usage));
}
mutex_unlock(&rxrpc_local_mutex);
BUG();
}
rcu_barrier();
}
