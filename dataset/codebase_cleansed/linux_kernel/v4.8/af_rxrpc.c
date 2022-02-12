static inline int rxrpc_writable(struct sock *sk)
{
return atomic_read(&sk->sk_wmem_alloc) < (size_t) sk->sk_sndbuf;
}
static void rxrpc_write_space(struct sock *sk)
{
_enter("%p", sk);
rcu_read_lock();
if (rxrpc_writable(sk)) {
struct socket_wq *wq = rcu_dereference(sk->sk_wq);
if (skwq_has_sleeper(wq))
wake_up_interruptible(&wq->wait);
sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
}
rcu_read_unlock();
}
static int rxrpc_validate_address(struct rxrpc_sock *rx,
struct sockaddr_rxrpc *srx,
int len)
{
unsigned int tail;
if (len < sizeof(struct sockaddr_rxrpc))
return -EINVAL;
if (srx->srx_family != AF_RXRPC)
return -EAFNOSUPPORT;
if (srx->transport_type != SOCK_DGRAM)
return -ESOCKTNOSUPPORT;
len -= offsetof(struct sockaddr_rxrpc, transport);
if (srx->transport_len < sizeof(sa_family_t) ||
srx->transport_len > len)
return -EINVAL;
if (srx->transport.family != rx->family)
return -EAFNOSUPPORT;
switch (srx->transport.family) {
case AF_INET:
if (srx->transport_len < sizeof(struct sockaddr_in))
return -EINVAL;
_debug("INET: %x @ %pI4",
ntohs(srx->transport.sin.sin_port),
&srx->transport.sin.sin_addr);
tail = offsetof(struct sockaddr_rxrpc, transport.sin.__pad);
break;
case AF_INET6:
default:
return -EAFNOSUPPORT;
}
if (tail < len)
memset((void *)srx + tail, 0, len - tail);
return 0;
}
static int rxrpc_bind(struct socket *sock, struct sockaddr *saddr, int len)
{
struct sockaddr_rxrpc *srx = (struct sockaddr_rxrpc *)saddr;
struct sock *sk = sock->sk;
struct rxrpc_local *local;
struct rxrpc_sock *rx = rxrpc_sk(sk), *prx;
int ret;
_enter("%p,%p,%d", rx, saddr, len);
ret = rxrpc_validate_address(rx, srx, len);
if (ret < 0)
goto error;
lock_sock(&rx->sk);
if (rx->sk.sk_state != RXRPC_UNBOUND) {
ret = -EINVAL;
goto error_unlock;
}
memcpy(&rx->srx, srx, sizeof(rx->srx));
local = rxrpc_lookup_local(&rx->srx);
if (IS_ERR(local)) {
ret = PTR_ERR(local);
goto error_unlock;
}
if (rx->srx.srx_service) {
write_lock_bh(&local->services_lock);
list_for_each_entry(prx, &local->services, listen_link) {
if (prx->srx.srx_service == rx->srx.srx_service)
goto service_in_use;
}
rx->local = local;
list_add_tail(&rx->listen_link, &local->services);
write_unlock_bh(&local->services_lock);
rx->sk.sk_state = RXRPC_SERVER_BOUND;
} else {
rx->local = local;
rx->sk.sk_state = RXRPC_CLIENT_BOUND;
}
release_sock(&rx->sk);
_leave(" = 0");
return 0;
service_in_use:
write_unlock_bh(&local->services_lock);
rxrpc_put_local(local);
ret = -EADDRINUSE;
error_unlock:
release_sock(&rx->sk);
error:
_leave(" = %d", ret);
return ret;
}
static int rxrpc_listen(struct socket *sock, int backlog)
{
struct sock *sk = sock->sk;
struct rxrpc_sock *rx = rxrpc_sk(sk);
unsigned int max;
int ret;
_enter("%p,%d", rx, backlog);
lock_sock(&rx->sk);
switch (rx->sk.sk_state) {
case RXRPC_UNBOUND:
ret = -EADDRNOTAVAIL;
break;
case RXRPC_SERVER_BOUND:
ASSERT(rx->local != NULL);
max = READ_ONCE(rxrpc_max_backlog);
ret = -EINVAL;
if (backlog == INT_MAX)
backlog = max;
else if (backlog < 0 || backlog > max)
break;
sk->sk_max_ack_backlog = backlog;
rx->sk.sk_state = RXRPC_SERVER_LISTENING;
ret = 0;
break;
default:
ret = -EBUSY;
break;
}
release_sock(&rx->sk);
_leave(" = %d", ret);
return ret;
}
struct rxrpc_call *rxrpc_kernel_begin_call(struct socket *sock,
struct sockaddr_rxrpc *srx,
struct key *key,
unsigned long user_call_ID,
gfp_t gfp)
{
struct rxrpc_conn_parameters cp;
struct rxrpc_call *call;
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
int ret;
_enter(",,%x,%lx", key_serial(key), user_call_ID);
ret = rxrpc_validate_address(rx, srx, sizeof(*srx));
if (ret < 0)
return ERR_PTR(ret);
lock_sock(&rx->sk);
if (!key)
key = rx->key;
if (key && !key->payload.data[0])
key = NULL;
memset(&cp, 0, sizeof(cp));
cp.local = rx->local;
cp.key = key;
cp.security_level = 0;
cp.exclusive = false;
cp.service_id = srx->srx_service;
call = rxrpc_new_client_call(rx, &cp, srx, user_call_ID, gfp);
release_sock(&rx->sk);
_leave(" = %p", call);
return call;
}
void rxrpc_kernel_end_call(struct rxrpc_call *call)
{
_enter("%d{%d}", call->debug_id, atomic_read(&call->usage));
rxrpc_remove_user_ID(call->socket, call);
rxrpc_put_call(call);
}
void rxrpc_kernel_intercept_rx_messages(struct socket *sock,
rxrpc_interceptor_t interceptor)
{
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
_enter("");
rx->interceptor = interceptor;
}
static int rxrpc_connect(struct socket *sock, struct sockaddr *addr,
int addr_len, int flags)
{
struct sockaddr_rxrpc *srx = (struct sockaddr_rxrpc *)addr;
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
int ret;
_enter("%p,%p,%d,%d", rx, addr, addr_len, flags);
ret = rxrpc_validate_address(rx, srx, addr_len);
if (ret < 0) {
_leave(" = %d [bad addr]", ret);
return ret;
}
lock_sock(&rx->sk);
ret = -EISCONN;
if (test_bit(RXRPC_SOCK_CONNECTED, &rx->flags))
goto error;
switch (rx->sk.sk_state) {
case RXRPC_UNBOUND:
rx->sk.sk_state = RXRPC_CLIENT_UNBOUND;
case RXRPC_CLIENT_UNBOUND:
case RXRPC_CLIENT_BOUND:
break;
default:
ret = -EBUSY;
goto error;
}
rx->connect_srx = *srx;
set_bit(RXRPC_SOCK_CONNECTED, &rx->flags);
ret = 0;
error:
release_sock(&rx->sk);
return ret;
}
static int rxrpc_sendmsg(struct socket *sock, struct msghdr *m, size_t len)
{
struct rxrpc_local *local;
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
int ret;
_enter(",{%d},,%zu", rx->sk.sk_state, len);
if (m->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
if (m->msg_name) {
ret = rxrpc_validate_address(rx, m->msg_name, m->msg_namelen);
if (ret < 0) {
_leave(" = %d [bad addr]", ret);
return ret;
}
}
lock_sock(&rx->sk);
switch (rx->sk.sk_state) {
case RXRPC_UNBOUND:
local = rxrpc_lookup_local(&rx->srx);
if (IS_ERR(local)) {
ret = PTR_ERR(local);
goto error_unlock;
}
rx->local = local;
rx->sk.sk_state = RXRPC_CLIENT_UNBOUND;
case RXRPC_CLIENT_UNBOUND:
case RXRPC_CLIENT_BOUND:
if (!m->msg_name &&
test_bit(RXRPC_SOCK_CONNECTED, &rx->flags)) {
m->msg_name = &rx->connect_srx;
m->msg_namelen = sizeof(rx->connect_srx);
}
case RXRPC_SERVER_BOUND:
case RXRPC_SERVER_LISTENING:
ret = rxrpc_do_sendmsg(rx, m, len);
break;
default:
ret = -EINVAL;
break;
}
error_unlock:
release_sock(&rx->sk);
_leave(" = %d", ret);
return ret;
}
static int rxrpc_setsockopt(struct socket *sock, int level, int optname,
char __user *optval, unsigned int optlen)
{
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
unsigned int min_sec_level;
int ret;
_enter(",%d,%d,,%d", level, optname, optlen);
lock_sock(&rx->sk);
ret = -EOPNOTSUPP;
if (level == SOL_RXRPC) {
switch (optname) {
case RXRPC_EXCLUSIVE_CONNECTION:
ret = -EINVAL;
if (optlen != 0)
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNBOUND)
goto error;
rx->exclusive = true;
goto success;
case RXRPC_SECURITY_KEY:
ret = -EINVAL;
if (rx->key)
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNBOUND)
goto error;
ret = rxrpc_request_key(rx, optval, optlen);
goto error;
case RXRPC_SECURITY_KEYRING:
ret = -EINVAL;
if (rx->key)
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNBOUND)
goto error;
ret = rxrpc_server_keyring(rx, optval, optlen);
goto error;
case RXRPC_MIN_SECURITY_LEVEL:
ret = -EINVAL;
if (optlen != sizeof(unsigned int))
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNBOUND)
goto error;
ret = get_user(min_sec_level,
(unsigned int __user *) optval);
if (ret < 0)
goto error;
ret = -EINVAL;
if (min_sec_level > RXRPC_SECURITY_MAX)
goto error;
rx->min_sec_level = min_sec_level;
goto success;
default:
break;
}
}
success:
ret = 0;
error:
release_sock(&rx->sk);
return ret;
}
static unsigned int rxrpc_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
unsigned int mask;
struct sock *sk = sock->sk;
sock_poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (!skb_queue_empty(&sk->sk_receive_queue))
mask |= POLLIN | POLLRDNORM;
if (rxrpc_writable(sk))
mask |= POLLOUT | POLLWRNORM;
return mask;
}
static int rxrpc_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct rxrpc_sock *rx;
struct sock *sk;
_enter("%p,%d", sock, protocol);
if (!net_eq(net, &init_net))
return -EAFNOSUPPORT;
if (protocol != PF_INET)
return -EPROTONOSUPPORT;
if (sock->type != SOCK_DGRAM)
return -ESOCKTNOSUPPORT;
sock->ops = &rxrpc_rpc_ops;
sock->state = SS_UNCONNECTED;
sk = sk_alloc(net, PF_RXRPC, GFP_KERNEL, &rxrpc_proto, kern);
if (!sk)
return -ENOMEM;
sock_init_data(sock, sk);
sk->sk_state = RXRPC_UNBOUND;
sk->sk_write_space = rxrpc_write_space;
sk->sk_max_ack_backlog = 0;
sk->sk_destruct = rxrpc_sock_destructor;
rx = rxrpc_sk(sk);
rx->family = protocol;
rx->calls = RB_ROOT;
INIT_LIST_HEAD(&rx->listen_link);
INIT_LIST_HEAD(&rx->secureq);
INIT_LIST_HEAD(&rx->acceptq);
rwlock_init(&rx->call_lock);
memset(&rx->srx, 0, sizeof(rx->srx));
_leave(" = 0 [%p]", rx);
return 0;
}
static void rxrpc_sock_destructor(struct sock *sk)
{
_enter("%p", sk);
rxrpc_purge_queue(&sk->sk_receive_queue);
WARN_ON(atomic_read(&sk->sk_wmem_alloc));
WARN_ON(!sk_unhashed(sk));
WARN_ON(sk->sk_socket);
if (!sock_flag(sk, SOCK_DEAD)) {
printk("Attempt to release alive rxrpc socket: %p\n", sk);
return;
}
}
static int rxrpc_release_sock(struct sock *sk)
{
struct rxrpc_sock *rx = rxrpc_sk(sk);
_enter("%p{%d,%d}", sk, sk->sk_state, atomic_read(&sk->sk_refcnt));
sock_orphan(sk);
sk->sk_shutdown = SHUTDOWN_MASK;
spin_lock_bh(&sk->sk_receive_queue.lock);
sk->sk_state = RXRPC_CLOSE;
spin_unlock_bh(&sk->sk_receive_queue.lock);
ASSERTCMP(rx->listen_link.next, !=, LIST_POISON1);
if (!list_empty(&rx->listen_link)) {
write_lock_bh(&rx->local->services_lock);
list_del(&rx->listen_link);
write_unlock_bh(&rx->local->services_lock);
}
rxrpc_release_calls_on_socket(rx);
flush_workqueue(rxrpc_workqueue);
rxrpc_purge_queue(&sk->sk_receive_queue);
rxrpc_put_local(rx->local);
rx->local = NULL;
key_put(rx->key);
rx->key = NULL;
key_put(rx->securities);
rx->securities = NULL;
sock_put(sk);
_leave(" = 0");
return 0;
}
static int rxrpc_release(struct socket *sock)
{
struct sock *sk = sock->sk;
_enter("%p{%p}", sock, sk);
if (!sk)
return 0;
sock->sk = NULL;
return rxrpc_release_sock(sk);
}
static int __init af_rxrpc_init(void)
{
int ret = -1;
BUILD_BUG_ON(sizeof(struct rxrpc_skb_priv) > FIELD_SIZEOF(struct sk_buff, cb));
rxrpc_epoch = get_seconds();
ret = -ENOMEM;
rxrpc_call_jar = kmem_cache_create(
"rxrpc_call_jar", sizeof(struct rxrpc_call), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!rxrpc_call_jar) {
pr_notice("Failed to allocate call jar\n");
goto error_call_jar;
}
rxrpc_workqueue = alloc_workqueue("krxrpcd", 0, 1);
if (!rxrpc_workqueue) {
pr_notice("Failed to allocate work queue\n");
goto error_work_queue;
}
ret = rxrpc_init_security();
if (ret < 0) {
pr_crit("Cannot initialise security\n");
goto error_security;
}
ret = proto_register(&rxrpc_proto, 1);
if (ret < 0) {
pr_crit("Cannot register protocol\n");
goto error_proto;
}
ret = sock_register(&rxrpc_family_ops);
if (ret < 0) {
pr_crit("Cannot register socket family\n");
goto error_sock;
}
ret = register_key_type(&key_type_rxrpc);
if (ret < 0) {
pr_crit("Cannot register client key type\n");
goto error_key_type;
}
ret = register_key_type(&key_type_rxrpc_s);
if (ret < 0) {
pr_crit("Cannot register server key type\n");
goto error_key_type_s;
}
ret = rxrpc_sysctl_init();
if (ret < 0) {
pr_crit("Cannot register sysctls\n");
goto error_sysctls;
}
#ifdef CONFIG_PROC_FS
proc_create("rxrpc_calls", 0, init_net.proc_net, &rxrpc_call_seq_fops);
proc_create("rxrpc_conns", 0, init_net.proc_net,
&rxrpc_connection_seq_fops);
#endif
return 0;
error_sysctls:
unregister_key_type(&key_type_rxrpc_s);
error_key_type_s:
unregister_key_type(&key_type_rxrpc);
error_key_type:
sock_unregister(PF_RXRPC);
error_sock:
proto_unregister(&rxrpc_proto);
error_proto:
rxrpc_exit_security();
error_security:
destroy_workqueue(rxrpc_workqueue);
error_work_queue:
kmem_cache_destroy(rxrpc_call_jar);
error_call_jar:
return ret;
}
static void __exit af_rxrpc_exit(void)
{
_enter("");
rxrpc_sysctl_exit();
unregister_key_type(&key_type_rxrpc_s);
unregister_key_type(&key_type_rxrpc);
sock_unregister(PF_RXRPC);
proto_unregister(&rxrpc_proto);
rxrpc_destroy_all_calls();
rxrpc_destroy_all_connections();
ASSERTCMP(atomic_read(&rxrpc_n_skbs), ==, 0);
rxrpc_destroy_all_locals();
remove_proc_entry("rxrpc_conns", init_net.proc_net);
remove_proc_entry("rxrpc_calls", init_net.proc_net);
destroy_workqueue(rxrpc_workqueue);
rxrpc_exit_security();
kmem_cache_destroy(rxrpc_call_jar);
_leave("");
}
