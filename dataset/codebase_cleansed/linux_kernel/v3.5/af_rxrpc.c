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
if (wq_has_sleeper(wq))
wake_up_interruptible(&wq->wait);
sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
}
rcu_read_unlock();
}
static int rxrpc_validate_address(struct rxrpc_sock *rx,
struct sockaddr_rxrpc *srx,
int len)
{
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
if (srx->transport.family != rx->proto)
return -EAFNOSUPPORT;
switch (srx->transport.family) {
case AF_INET:
_debug("INET: %x @ %pI4",
ntohs(srx->transport.sin.sin_port),
&srx->transport.sin.sin_addr);
if (srx->transport_len > 8)
memset((void *)&srx->transport + 8, 0,
srx->transport_len - 8);
break;
case AF_INET6:
default:
return -EAFNOSUPPORT;
}
return 0;
}
static int rxrpc_bind(struct socket *sock, struct sockaddr *saddr, int len)
{
struct sockaddr_rxrpc *srx = (struct sockaddr_rxrpc *) saddr;
struct sock *sk = sock->sk;
struct rxrpc_local *local;
struct rxrpc_sock *rx = rxrpc_sk(sk), *prx;
__be16 service_id;
int ret;
_enter("%p,%p,%d", rx, saddr, len);
ret = rxrpc_validate_address(rx, srx, len);
if (ret < 0)
goto error;
lock_sock(&rx->sk);
if (rx->sk.sk_state != RXRPC_UNCONNECTED) {
ret = -EINVAL;
goto error_unlock;
}
memcpy(&rx->srx, srx, sizeof(rx->srx));
local = rxrpc_lookup_local(&rx->srx);
if (IS_ERR(local)) {
ret = PTR_ERR(local);
goto error_unlock;
}
rx->local = local;
if (srx->srx_service) {
service_id = htons(srx->srx_service);
write_lock_bh(&local->services_lock);
list_for_each_entry(prx, &local->services, listen_link) {
if (prx->service_id == service_id)
goto service_in_use;
}
rx->service_id = service_id;
list_add_tail(&rx->listen_link, &local->services);
write_unlock_bh(&local->services_lock);
rx->sk.sk_state = RXRPC_SERVER_BOUND;
} else {
rx->sk.sk_state = RXRPC_CLIENT_BOUND;
}
release_sock(&rx->sk);
_leave(" = 0");
return 0;
service_in_use:
ret = -EADDRINUSE;
write_unlock_bh(&local->services_lock);
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
int ret;
_enter("%p,%d", rx, backlog);
lock_sock(&rx->sk);
switch (rx->sk.sk_state) {
case RXRPC_UNCONNECTED:
ret = -EADDRNOTAVAIL;
break;
case RXRPC_CLIENT_BOUND:
case RXRPC_CLIENT_CONNECTED:
default:
ret = -EBUSY;
break;
case RXRPC_SERVER_BOUND:
ASSERT(rx->local != NULL);
sk->sk_max_ack_backlog = backlog;
rx->sk.sk_state = RXRPC_SERVER_LISTENING;
ret = 0;
break;
}
release_sock(&rx->sk);
_leave(" = %d", ret);
return ret;
}
static struct rxrpc_transport *rxrpc_name_to_transport(struct socket *sock,
struct sockaddr *addr,
int addr_len, int flags,
gfp_t gfp)
{
struct sockaddr_rxrpc *srx = (struct sockaddr_rxrpc *) addr;
struct rxrpc_transport *trans;
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
struct rxrpc_peer *peer;
_enter("%p,%p,%d,%d", rx, addr, addr_len, flags);
ASSERT(rx->local != NULL);
ASSERT(rx->sk.sk_state > RXRPC_UNCONNECTED);
if (rx->srx.transport_type != srx->transport_type)
return ERR_PTR(-ESOCKTNOSUPPORT);
if (rx->srx.transport.family != srx->transport.family)
return ERR_PTR(-EAFNOSUPPORT);
peer = rxrpc_get_peer(srx, gfp);
if (IS_ERR(peer))
return ERR_CAST(peer);
trans = rxrpc_get_transport(rx->local, peer, gfp);
rxrpc_put_peer(peer);
_leave(" = %p", trans);
return trans;
}
struct rxrpc_call *rxrpc_kernel_begin_call(struct socket *sock,
struct sockaddr_rxrpc *srx,
struct key *key,
unsigned long user_call_ID,
gfp_t gfp)
{
struct rxrpc_conn_bundle *bundle;
struct rxrpc_transport *trans;
struct rxrpc_call *call;
struct rxrpc_sock *rx = rxrpc_sk(sock->sk);
__be16 service_id;
_enter(",,%x,%lx", key_serial(key), user_call_ID);
lock_sock(&rx->sk);
if (srx) {
trans = rxrpc_name_to_transport(sock, (struct sockaddr *) srx,
sizeof(*srx), 0, gfp);
if (IS_ERR(trans)) {
call = ERR_CAST(trans);
trans = NULL;
goto out_notrans;
}
} else {
trans = rx->trans;
if (!trans) {
call = ERR_PTR(-ENOTCONN);
goto out_notrans;
}
atomic_inc(&trans->usage);
}
service_id = rx->service_id;
if (srx)
service_id = htons(srx->srx_service);
if (!key)
key = rx->key;
if (key && !key->payload.data)
key = NULL;
bundle = rxrpc_get_bundle(rx, trans, key, service_id, gfp);
if (IS_ERR(bundle)) {
call = ERR_CAST(bundle);
goto out;
}
call = rxrpc_get_client_call(rx, trans, bundle, user_call_ID, true,
gfp);
rxrpc_put_bundle(trans, bundle);
out:
rxrpc_put_transport(trans);
out_notrans:
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
struct sockaddr_rxrpc *srx = (struct sockaddr_rxrpc *) addr;
struct sock *sk = sock->sk;
struct rxrpc_transport *trans;
struct rxrpc_local *local;
struct rxrpc_sock *rx = rxrpc_sk(sk);
int ret;
_enter("%p,%p,%d,%d", rx, addr, addr_len, flags);
ret = rxrpc_validate_address(rx, srx, addr_len);
if (ret < 0) {
_leave(" = %d [bad addr]", ret);
return ret;
}
lock_sock(&rx->sk);
switch (rx->sk.sk_state) {
case RXRPC_UNCONNECTED:
ASSERTCMP(rx->local, ==, NULL);
rx->srx.srx_family = AF_RXRPC;
rx->srx.srx_service = 0;
rx->srx.transport_type = srx->transport_type;
rx->srx.transport_len = sizeof(sa_family_t);
rx->srx.transport.family = srx->transport.family;
local = rxrpc_lookup_local(&rx->srx);
if (IS_ERR(local)) {
release_sock(&rx->sk);
return PTR_ERR(local);
}
rx->local = local;
rx->sk.sk_state = RXRPC_CLIENT_BOUND;
case RXRPC_CLIENT_BOUND:
break;
case RXRPC_CLIENT_CONNECTED:
release_sock(&rx->sk);
return -EISCONN;
default:
release_sock(&rx->sk);
return -EBUSY;
}
trans = rxrpc_name_to_transport(sock, addr, addr_len, flags,
GFP_KERNEL);
if (IS_ERR(trans)) {
release_sock(&rx->sk);
_leave(" = %ld", PTR_ERR(trans));
return PTR_ERR(trans);
}
rx->trans = trans;
rx->service_id = htons(srx->srx_service);
rx->sk.sk_state = RXRPC_CLIENT_CONNECTED;
release_sock(&rx->sk);
return 0;
}
static int rxrpc_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *m, size_t len)
{
struct rxrpc_transport *trans;
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
trans = NULL;
lock_sock(&rx->sk);
if (m->msg_name) {
ret = -EISCONN;
trans = rxrpc_name_to_transport(sock, m->msg_name,
m->msg_namelen, 0, GFP_KERNEL);
if (IS_ERR(trans)) {
ret = PTR_ERR(trans);
trans = NULL;
goto out;
}
} else {
trans = rx->trans;
if (trans)
atomic_inc(&trans->usage);
}
switch (rx->sk.sk_state) {
case RXRPC_SERVER_LISTENING:
if (!m->msg_name) {
ret = rxrpc_server_sendmsg(iocb, rx, m, len);
break;
}
case RXRPC_SERVER_BOUND:
case RXRPC_CLIENT_BOUND:
if (!m->msg_name) {
ret = -ENOTCONN;
break;
}
case RXRPC_CLIENT_CONNECTED:
ret = rxrpc_client_sendmsg(iocb, rx, trans, m, len);
break;
default:
ret = -ENOTCONN;
break;
}
out:
release_sock(&rx->sk);
if (trans)
rxrpc_put_transport(trans);
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
if (rx->sk.sk_state != RXRPC_UNCONNECTED)
goto error;
set_bit(RXRPC_SOCK_EXCLUSIVE_CONN, &rx->flags);
goto success;
case RXRPC_SECURITY_KEY:
ret = -EINVAL;
if (rx->key)
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNCONNECTED)
goto error;
ret = rxrpc_request_key(rx, optval, optlen);
goto error;
case RXRPC_SECURITY_KEYRING:
ret = -EINVAL;
if (rx->key)
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNCONNECTED)
goto error;
ret = rxrpc_server_keyring(rx, optval, optlen);
goto error;
case RXRPC_MIN_SECURITY_LEVEL:
ret = -EINVAL;
if (optlen != sizeof(unsigned int))
goto error;
ret = -EISCONN;
if (rx->sk.sk_state != RXRPC_UNCONNECTED)
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
sk = sk_alloc(net, PF_RXRPC, GFP_KERNEL, &rxrpc_proto);
if (!sk)
return -ENOMEM;
sock_init_data(sock, sk);
sk->sk_state = RXRPC_UNCONNECTED;
sk->sk_write_space = rxrpc_write_space;
sk->sk_max_ack_backlog = sysctl_rxrpc_max_qlen;
sk->sk_destruct = rxrpc_sock_destructor;
rx = rxrpc_sk(sk);
rx->proto = protocol;
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
if (rx->conn) {
rxrpc_put_connection(rx->conn);
rx->conn = NULL;
}
if (rx->bundle) {
rxrpc_put_bundle(rx->trans, rx->bundle);
rx->bundle = NULL;
}
if (rx->trans) {
rxrpc_put_transport(rx->trans);
rx->trans = NULL;
}
if (rx->local) {
rxrpc_put_local(rx->local);
rx->local = NULL;
}
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
struct sk_buff *dummy_skb;
int ret = -1;
BUILD_BUG_ON(sizeof(struct rxrpc_skb_priv) > sizeof(dummy_skb->cb));
rxrpc_epoch = htonl(get_seconds());
ret = -ENOMEM;
rxrpc_call_jar = kmem_cache_create(
"rxrpc_call_jar", sizeof(struct rxrpc_call), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!rxrpc_call_jar) {
printk(KERN_NOTICE "RxRPC: Failed to allocate call jar\n");
goto error_call_jar;
}
rxrpc_workqueue = alloc_workqueue("krxrpcd", 0, 1);
if (!rxrpc_workqueue) {
printk(KERN_NOTICE "RxRPC: Failed to allocate work queue\n");
goto error_work_queue;
}
ret = proto_register(&rxrpc_proto, 1);
if (ret < 0) {
printk(KERN_CRIT "RxRPC: Cannot register protocol\n");
goto error_proto;
}
ret = sock_register(&rxrpc_family_ops);
if (ret < 0) {
printk(KERN_CRIT "RxRPC: Cannot register socket family\n");
goto error_sock;
}
ret = register_key_type(&key_type_rxrpc);
if (ret < 0) {
printk(KERN_CRIT "RxRPC: Cannot register client key type\n");
goto error_key_type;
}
ret = register_key_type(&key_type_rxrpc_s);
if (ret < 0) {
printk(KERN_CRIT "RxRPC: Cannot register server key type\n");
goto error_key_type_s;
}
#ifdef CONFIG_PROC_FS
proc_net_fops_create(&init_net, "rxrpc_calls", 0, &rxrpc_call_seq_fops);
proc_net_fops_create(&init_net, "rxrpc_conns", 0, &rxrpc_connection_seq_fops);
#endif
return 0;
error_key_type_s:
unregister_key_type(&key_type_rxrpc);
error_key_type:
sock_unregister(PF_RXRPC);
error_sock:
proto_unregister(&rxrpc_proto);
error_proto:
destroy_workqueue(rxrpc_workqueue);
error_work_queue:
kmem_cache_destroy(rxrpc_call_jar);
error_call_jar:
return ret;
}
static void __exit af_rxrpc_exit(void)
{
_enter("");
unregister_key_type(&key_type_rxrpc_s);
unregister_key_type(&key_type_rxrpc);
sock_unregister(PF_RXRPC);
proto_unregister(&rxrpc_proto);
rxrpc_destroy_all_calls();
rxrpc_destroy_all_connections();
rxrpc_destroy_all_transports();
rxrpc_destroy_all_peers();
rxrpc_destroy_all_locals();
ASSERTCMP(atomic_read(&rxrpc_n_skbs), ==, 0);
_debug("flush scheduled work");
flush_workqueue(rxrpc_workqueue);
proc_net_remove(&init_net, "rxrpc_conns");
proc_net_remove(&init_net, "rxrpc_calls");
destroy_workqueue(rxrpc_workqueue);
kmem_cache_destroy(rxrpc_call_jar);
_leave("");
}
