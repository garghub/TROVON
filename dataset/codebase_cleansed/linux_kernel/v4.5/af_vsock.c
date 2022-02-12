int vm_sockets_get_local_cid(void)
{
return transport->get_local_cid();
}
static int vsock_auto_bind(struct vsock_sock *vsk)
{
struct sock *sk = sk_vsock(vsk);
struct sockaddr_vm local_addr;
if (vsock_addr_bound(&vsk->local_addr))
return 0;
vsock_addr_init(&local_addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
return __vsock_bind(sk, &local_addr);
}
static void vsock_init_tables(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(vsock_bind_table); i++)
INIT_LIST_HEAD(&vsock_bind_table[i]);
for (i = 0; i < ARRAY_SIZE(vsock_connected_table); i++)
INIT_LIST_HEAD(&vsock_connected_table[i]);
}
static void __vsock_insert_bound(struct list_head *list,
struct vsock_sock *vsk)
{
sock_hold(&vsk->sk);
list_add(&vsk->bound_table, list);
}
static void __vsock_insert_connected(struct list_head *list,
struct vsock_sock *vsk)
{
sock_hold(&vsk->sk);
list_add(&vsk->connected_table, list);
}
static void __vsock_remove_bound(struct vsock_sock *vsk)
{
list_del_init(&vsk->bound_table);
sock_put(&vsk->sk);
}
static void __vsock_remove_connected(struct vsock_sock *vsk)
{
list_del_init(&vsk->connected_table);
sock_put(&vsk->sk);
}
static struct sock *__vsock_find_bound_socket(struct sockaddr_vm *addr)
{
struct vsock_sock *vsk;
list_for_each_entry(vsk, vsock_bound_sockets(addr), bound_table)
if (addr->svm_port == vsk->local_addr.svm_port)
return sk_vsock(vsk);
return NULL;
}
static struct sock *__vsock_find_connected_socket(struct sockaddr_vm *src,
struct sockaddr_vm *dst)
{
struct vsock_sock *vsk;
list_for_each_entry(vsk, vsock_connected_sockets(src, dst),
connected_table) {
if (vsock_addr_equals_addr(src, &vsk->remote_addr) &&
dst->svm_port == vsk->local_addr.svm_port) {
return sk_vsock(vsk);
}
}
return NULL;
}
static bool __vsock_in_bound_table(struct vsock_sock *vsk)
{
return !list_empty(&vsk->bound_table);
}
static bool __vsock_in_connected_table(struct vsock_sock *vsk)
{
return !list_empty(&vsk->connected_table);
}
static void vsock_insert_unbound(struct vsock_sock *vsk)
{
spin_lock_bh(&vsock_table_lock);
__vsock_insert_bound(vsock_unbound_sockets, vsk);
spin_unlock_bh(&vsock_table_lock);
}
void vsock_insert_connected(struct vsock_sock *vsk)
{
struct list_head *list = vsock_connected_sockets(
&vsk->remote_addr, &vsk->local_addr);
spin_lock_bh(&vsock_table_lock);
__vsock_insert_connected(list, vsk);
spin_unlock_bh(&vsock_table_lock);
}
void vsock_remove_bound(struct vsock_sock *vsk)
{
spin_lock_bh(&vsock_table_lock);
__vsock_remove_bound(vsk);
spin_unlock_bh(&vsock_table_lock);
}
void vsock_remove_connected(struct vsock_sock *vsk)
{
spin_lock_bh(&vsock_table_lock);
__vsock_remove_connected(vsk);
spin_unlock_bh(&vsock_table_lock);
}
struct sock *vsock_find_bound_socket(struct sockaddr_vm *addr)
{
struct sock *sk;
spin_lock_bh(&vsock_table_lock);
sk = __vsock_find_bound_socket(addr);
if (sk)
sock_hold(sk);
spin_unlock_bh(&vsock_table_lock);
return sk;
}
struct sock *vsock_find_connected_socket(struct sockaddr_vm *src,
struct sockaddr_vm *dst)
{
struct sock *sk;
spin_lock_bh(&vsock_table_lock);
sk = __vsock_find_connected_socket(src, dst);
if (sk)
sock_hold(sk);
spin_unlock_bh(&vsock_table_lock);
return sk;
}
static bool vsock_in_bound_table(struct vsock_sock *vsk)
{
bool ret;
spin_lock_bh(&vsock_table_lock);
ret = __vsock_in_bound_table(vsk);
spin_unlock_bh(&vsock_table_lock);
return ret;
}
static bool vsock_in_connected_table(struct vsock_sock *vsk)
{
bool ret;
spin_lock_bh(&vsock_table_lock);
ret = __vsock_in_connected_table(vsk);
spin_unlock_bh(&vsock_table_lock);
return ret;
}
void vsock_for_each_connected_socket(void (*fn)(struct sock *sk))
{
int i;
spin_lock_bh(&vsock_table_lock);
for (i = 0; i < ARRAY_SIZE(vsock_connected_table); i++) {
struct vsock_sock *vsk;
list_for_each_entry(vsk, &vsock_connected_table[i],
connected_table)
fn(sk_vsock(vsk));
}
spin_unlock_bh(&vsock_table_lock);
}
void vsock_add_pending(struct sock *listener, struct sock *pending)
{
struct vsock_sock *vlistener;
struct vsock_sock *vpending;
vlistener = vsock_sk(listener);
vpending = vsock_sk(pending);
sock_hold(pending);
sock_hold(listener);
list_add_tail(&vpending->pending_links, &vlistener->pending_links);
}
void vsock_remove_pending(struct sock *listener, struct sock *pending)
{
struct vsock_sock *vpending = vsock_sk(pending);
list_del_init(&vpending->pending_links);
sock_put(listener);
sock_put(pending);
}
void vsock_enqueue_accept(struct sock *listener, struct sock *connected)
{
struct vsock_sock *vlistener;
struct vsock_sock *vconnected;
vlistener = vsock_sk(listener);
vconnected = vsock_sk(connected);
sock_hold(connected);
sock_hold(listener);
list_add_tail(&vconnected->accept_queue, &vlistener->accept_queue);
}
static struct sock *vsock_dequeue_accept(struct sock *listener)
{
struct vsock_sock *vlistener;
struct vsock_sock *vconnected;
vlistener = vsock_sk(listener);
if (list_empty(&vlistener->accept_queue))
return NULL;
vconnected = list_entry(vlistener->accept_queue.next,
struct vsock_sock, accept_queue);
list_del_init(&vconnected->accept_queue);
sock_put(listener);
return sk_vsock(vconnected);
}
static bool vsock_is_accept_queue_empty(struct sock *sk)
{
struct vsock_sock *vsk = vsock_sk(sk);
return list_empty(&vsk->accept_queue);
}
static bool vsock_is_pending(struct sock *sk)
{
struct vsock_sock *vsk = vsock_sk(sk);
return !list_empty(&vsk->pending_links);
}
static int vsock_send_shutdown(struct sock *sk, int mode)
{
return transport->shutdown(vsock_sk(sk), mode);
}
void vsock_pending_work(struct work_struct *work)
{
struct sock *sk;
struct sock *listener;
struct vsock_sock *vsk;
bool cleanup;
vsk = container_of(work, struct vsock_sock, dwork.work);
sk = sk_vsock(vsk);
listener = vsk->listener;
cleanup = true;
lock_sock(listener);
lock_sock(sk);
if (vsock_is_pending(sk)) {
vsock_remove_pending(listener, sk);
} else if (!vsk->rejected) {
cleanup = false;
goto out;
}
listener->sk_ack_backlog--;
if (vsock_in_connected_table(vsk))
vsock_remove_connected(vsk);
sk->sk_state = SS_FREE;
out:
release_sock(sk);
release_sock(listener);
if (cleanup)
sock_put(sk);
sock_put(sk);
sock_put(listener);
}
static int __vsock_bind_stream(struct vsock_sock *vsk,
struct sockaddr_vm *addr)
{
static u32 port = LAST_RESERVED_PORT + 1;
struct sockaddr_vm new_addr;
vsock_addr_init(&new_addr, addr->svm_cid, addr->svm_port);
if (addr->svm_port == VMADDR_PORT_ANY) {
bool found = false;
unsigned int i;
for (i = 0; i < MAX_PORT_RETRIES; i++) {
if (port <= LAST_RESERVED_PORT)
port = LAST_RESERVED_PORT + 1;
new_addr.svm_port = port++;
if (!__vsock_find_bound_socket(&new_addr)) {
found = true;
break;
}
}
if (!found)
return -EADDRNOTAVAIL;
} else {
if (addr->svm_port <= LAST_RESERVED_PORT &&
!capable(CAP_NET_BIND_SERVICE)) {
return -EACCES;
}
if (__vsock_find_bound_socket(&new_addr))
return -EADDRINUSE;
}
vsock_addr_init(&vsk->local_addr, new_addr.svm_cid, new_addr.svm_port);
__vsock_remove_bound(vsk);
__vsock_insert_bound(vsock_bound_sockets(&vsk->local_addr), vsk);
return 0;
}
static int __vsock_bind_dgram(struct vsock_sock *vsk,
struct sockaddr_vm *addr)
{
return transport->dgram_bind(vsk, addr);
}
static int __vsock_bind(struct sock *sk, struct sockaddr_vm *addr)
{
struct vsock_sock *vsk = vsock_sk(sk);
u32 cid;
int retval;
if (vsock_addr_bound(&vsk->local_addr))
return -EINVAL;
cid = transport->get_local_cid();
if (addr->svm_cid != cid && addr->svm_cid != VMADDR_CID_ANY)
return -EADDRNOTAVAIL;
switch (sk->sk_socket->type) {
case SOCK_STREAM:
spin_lock_bh(&vsock_table_lock);
retval = __vsock_bind_stream(vsk, addr);
spin_unlock_bh(&vsock_table_lock);
break;
case SOCK_DGRAM:
retval = __vsock_bind_dgram(vsk, addr);
break;
default:
retval = -EINVAL;
break;
}
return retval;
}
struct sock *__vsock_create(struct net *net,
struct socket *sock,
struct sock *parent,
gfp_t priority,
unsigned short type,
int kern)
{
struct sock *sk;
struct vsock_sock *psk;
struct vsock_sock *vsk;
sk = sk_alloc(net, AF_VSOCK, priority, &vsock_proto, kern);
if (!sk)
return NULL;
sock_init_data(sock, sk);
if (!sock)
sk->sk_type = type;
vsk = vsock_sk(sk);
vsock_addr_init(&vsk->local_addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
vsock_addr_init(&vsk->remote_addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
sk->sk_destruct = vsock_sk_destruct;
sk->sk_backlog_rcv = vsock_queue_rcv_skb;
sk->sk_state = 0;
sock_reset_flag(sk, SOCK_DONE);
INIT_LIST_HEAD(&vsk->bound_table);
INIT_LIST_HEAD(&vsk->connected_table);
vsk->listener = NULL;
INIT_LIST_HEAD(&vsk->pending_links);
INIT_LIST_HEAD(&vsk->accept_queue);
vsk->rejected = false;
vsk->sent_request = false;
vsk->ignore_connecting_rst = false;
vsk->peer_shutdown = 0;
psk = parent ? vsock_sk(parent) : NULL;
if (parent) {
vsk->trusted = psk->trusted;
vsk->owner = get_cred(psk->owner);
vsk->connect_timeout = psk->connect_timeout;
} else {
vsk->trusted = capable(CAP_NET_ADMIN);
vsk->owner = get_current_cred();
vsk->connect_timeout = VSOCK_DEFAULT_CONNECT_TIMEOUT;
}
if (transport->init(vsk, psk) < 0) {
sk_free(sk);
return NULL;
}
if (sock)
vsock_insert_unbound(vsk);
return sk;
}
static void __vsock_release(struct sock *sk)
{
if (sk) {
struct sk_buff *skb;
struct sock *pending;
struct vsock_sock *vsk;
vsk = vsock_sk(sk);
pending = NULL;
if (vsock_in_bound_table(vsk))
vsock_remove_bound(vsk);
if (vsock_in_connected_table(vsk))
vsock_remove_connected(vsk);
transport->release(vsk);
lock_sock(sk);
sock_orphan(sk);
sk->sk_shutdown = SHUTDOWN_MASK;
while ((skb = skb_dequeue(&sk->sk_receive_queue)))
kfree_skb(skb);
while ((pending = vsock_dequeue_accept(sk)) != NULL) {
__vsock_release(pending);
sock_put(pending);
}
release_sock(sk);
sock_put(sk);
}
}
static void vsock_sk_destruct(struct sock *sk)
{
struct vsock_sock *vsk = vsock_sk(sk);
transport->destruct(vsk);
vsock_addr_init(&vsk->local_addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
vsock_addr_init(&vsk->remote_addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
put_cred(vsk->owner);
}
static int vsock_queue_rcv_skb(struct sock *sk, struct sk_buff *skb)
{
int err;
err = sock_queue_rcv_skb(sk, skb);
if (err)
kfree_skb(skb);
return err;
}
s64 vsock_stream_has_data(struct vsock_sock *vsk)
{
return transport->stream_has_data(vsk);
}
s64 vsock_stream_has_space(struct vsock_sock *vsk)
{
return transport->stream_has_space(vsk);
}
static int vsock_release(struct socket *sock)
{
__vsock_release(sock->sk);
sock->sk = NULL;
sock->state = SS_FREE;
return 0;
}
static int
vsock_bind(struct socket *sock, struct sockaddr *addr, int addr_len)
{
int err;
struct sock *sk;
struct sockaddr_vm *vm_addr;
sk = sock->sk;
if (vsock_addr_cast(addr, addr_len, &vm_addr) != 0)
return -EINVAL;
lock_sock(sk);
err = __vsock_bind(sk, vm_addr);
release_sock(sk);
return err;
}
static int vsock_getname(struct socket *sock,
struct sockaddr *addr, int *addr_len, int peer)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
struct sockaddr_vm *vm_addr;
sk = sock->sk;
vsk = vsock_sk(sk);
err = 0;
lock_sock(sk);
if (peer) {
if (sock->state != SS_CONNECTED) {
err = -ENOTCONN;
goto out;
}
vm_addr = &vsk->remote_addr;
} else {
vm_addr = &vsk->local_addr;
}
if (!vm_addr) {
err = -EINVAL;
goto out;
}
BUILD_BUG_ON(sizeof(*vm_addr) > 128);
memcpy(addr, vm_addr, sizeof(*vm_addr));
*addr_len = sizeof(*vm_addr);
out:
release_sock(sk);
return err;
}
static int vsock_shutdown(struct socket *sock, int mode)
{
int err;
struct sock *sk;
mode++;
if ((mode & ~SHUTDOWN_MASK) || !mode)
return -EINVAL;
sk = sock->sk;
if (sock->state == SS_UNCONNECTED) {
err = -ENOTCONN;
if (sk->sk_type == SOCK_STREAM)
return err;
} else {
sock->state = SS_DISCONNECTING;
err = 0;
}
mode = mode & (RCV_SHUTDOWN | SEND_SHUTDOWN);
if (mode) {
lock_sock(sk);
sk->sk_shutdown |= mode;
sk->sk_state_change(sk);
release_sock(sk);
if (sk->sk_type == SOCK_STREAM) {
sock_reset_flag(sk, SOCK_DONE);
vsock_send_shutdown(sk, mode);
}
}
return err;
}
static unsigned int vsock_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
struct sock *sk;
unsigned int mask;
struct vsock_sock *vsk;
sk = sock->sk;
vsk = vsock_sk(sk);
poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (sk->sk_err)
mask |= POLLERR;
if ((sk->sk_shutdown == SHUTDOWN_MASK) ||
((sk->sk_shutdown & SEND_SHUTDOWN) &&
(vsk->peer_shutdown & SEND_SHUTDOWN))) {
mask |= POLLHUP;
}
if (sk->sk_shutdown & RCV_SHUTDOWN ||
vsk->peer_shutdown & SEND_SHUTDOWN) {
mask |= POLLRDHUP;
}
if (sock->type == SOCK_DGRAM) {
if (!skb_queue_empty(&sk->sk_receive_queue) ||
(sk->sk_shutdown & RCV_SHUTDOWN)) {
mask |= POLLIN | POLLRDNORM;
}
if (!(sk->sk_shutdown & SEND_SHUTDOWN))
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
} else if (sock->type == SOCK_STREAM) {
lock_sock(sk);
if (sk->sk_state == VSOCK_SS_LISTEN
&& !vsock_is_accept_queue_empty(sk))
mask |= POLLIN | POLLRDNORM;
if (transport->stream_is_active(vsk) &&
!(sk->sk_shutdown & RCV_SHUTDOWN)) {
bool data_ready_now = false;
int ret = transport->notify_poll_in(
vsk, 1, &data_ready_now);
if (ret < 0) {
mask |= POLLERR;
} else {
if (data_ready_now)
mask |= POLLIN | POLLRDNORM;
}
}
if (sk->sk_shutdown & RCV_SHUTDOWN ||
vsk->peer_shutdown & SEND_SHUTDOWN) {
mask |= POLLIN | POLLRDNORM;
}
if (sk->sk_state == SS_CONNECTED) {
if (!(sk->sk_shutdown & SEND_SHUTDOWN)) {
bool space_avail_now = false;
int ret = transport->notify_poll_out(
vsk, 1, &space_avail_now);
if (ret < 0) {
mask |= POLLERR;
} else {
if (space_avail_now)
mask |= POLLOUT | POLLWRNORM;
}
}
}
if (sk->sk_state == SS_UNCONNECTED) {
if (!(sk->sk_shutdown & SEND_SHUTDOWN))
mask |= POLLOUT | POLLWRNORM;
}
release_sock(sk);
}
return mask;
}
static int vsock_dgram_sendmsg(struct socket *sock, struct msghdr *msg,
size_t len)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
struct sockaddr_vm *remote_addr;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
err = 0;
sk = sock->sk;
vsk = vsock_sk(sk);
lock_sock(sk);
err = vsock_auto_bind(vsk);
if (err)
goto out;
if (msg->msg_name &&
vsock_addr_cast(msg->msg_name, msg->msg_namelen,
&remote_addr) == 0) {
if (remote_addr->svm_cid == VMADDR_CID_ANY)
remote_addr->svm_cid = transport->get_local_cid();
if (!vsock_addr_bound(remote_addr)) {
err = -EINVAL;
goto out;
}
} else if (sock->state == SS_CONNECTED) {
remote_addr = &vsk->remote_addr;
if (remote_addr->svm_cid == VMADDR_CID_ANY)
remote_addr->svm_cid = transport->get_local_cid();
if (!vsock_addr_bound(&vsk->remote_addr)) {
err = -EINVAL;
goto out;
}
} else {
err = -EINVAL;
goto out;
}
if (!transport->dgram_allow(remote_addr->svm_cid,
remote_addr->svm_port)) {
err = -EINVAL;
goto out;
}
err = transport->dgram_enqueue(vsk, remote_addr, msg, len);
out:
release_sock(sk);
return err;
}
static int vsock_dgram_connect(struct socket *sock,
struct sockaddr *addr, int addr_len, int flags)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
struct sockaddr_vm *remote_addr;
sk = sock->sk;
vsk = vsock_sk(sk);
err = vsock_addr_cast(addr, addr_len, &remote_addr);
if (err == -EAFNOSUPPORT && remote_addr->svm_family == AF_UNSPEC) {
lock_sock(sk);
vsock_addr_init(&vsk->remote_addr, VMADDR_CID_ANY,
VMADDR_PORT_ANY);
sock->state = SS_UNCONNECTED;
release_sock(sk);
return 0;
} else if (err != 0)
return -EINVAL;
lock_sock(sk);
err = vsock_auto_bind(vsk);
if (err)
goto out;
if (!transport->dgram_allow(remote_addr->svm_cid,
remote_addr->svm_port)) {
err = -EINVAL;
goto out;
}
memcpy(&vsk->remote_addr, remote_addr, sizeof(vsk->remote_addr));
sock->state = SS_CONNECTED;
out:
release_sock(sk);
return err;
}
static int vsock_dgram_recvmsg(struct socket *sock, struct msghdr *msg,
size_t len, int flags)
{
return transport->dgram_dequeue(vsock_sk(sock->sk), msg, len, flags);
}
static void vsock_connect_timeout(struct work_struct *work)
{
struct sock *sk;
struct vsock_sock *vsk;
vsk = container_of(work, struct vsock_sock, dwork.work);
sk = sk_vsock(vsk);
lock_sock(sk);
if (sk->sk_state == SS_CONNECTING &&
(sk->sk_shutdown != SHUTDOWN_MASK)) {
sk->sk_state = SS_UNCONNECTED;
sk->sk_err = ETIMEDOUT;
sk->sk_error_report(sk);
}
release_sock(sk);
sock_put(sk);
}
static int vsock_stream_connect(struct socket *sock, struct sockaddr *addr,
int addr_len, int flags)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
struct sockaddr_vm *remote_addr;
long timeout;
DEFINE_WAIT(wait);
err = 0;
sk = sock->sk;
vsk = vsock_sk(sk);
lock_sock(sk);
switch (sock->state) {
case SS_CONNECTED:
err = -EISCONN;
goto out;
case SS_DISCONNECTING:
err = -EINVAL;
goto out;
case SS_CONNECTING:
err = -EALREADY;
break;
default:
if ((sk->sk_state == VSOCK_SS_LISTEN) ||
vsock_addr_cast(addr, addr_len, &remote_addr) != 0) {
err = -EINVAL;
goto out;
}
if (!transport->stream_allow(remote_addr->svm_cid,
remote_addr->svm_port)) {
err = -ENETUNREACH;
goto out;
}
memcpy(&vsk->remote_addr, remote_addr,
sizeof(vsk->remote_addr));
err = vsock_auto_bind(vsk);
if (err)
goto out;
sk->sk_state = SS_CONNECTING;
err = transport->connect(vsk);
if (err < 0)
goto out;
sock->state = SS_CONNECTING;
err = -EINPROGRESS;
}
timeout = vsk->connect_timeout;
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
while (sk->sk_state != SS_CONNECTED && sk->sk_err == 0) {
if (flags & O_NONBLOCK) {
sock_hold(sk);
INIT_DELAYED_WORK(&vsk->dwork,
vsock_connect_timeout);
schedule_delayed_work(&vsk->dwork, timeout);
goto out_wait;
}
release_sock(sk);
timeout = schedule_timeout(timeout);
lock_sock(sk);
if (signal_pending(current)) {
err = sock_intr_errno(timeout);
goto out_wait_error;
} else if (timeout == 0) {
err = -ETIMEDOUT;
goto out_wait_error;
}
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
}
if (sk->sk_err) {
err = -sk->sk_err;
goto out_wait_error;
} else
err = 0;
out_wait:
finish_wait(sk_sleep(sk), &wait);
out:
release_sock(sk);
return err;
out_wait_error:
sk->sk_state = SS_UNCONNECTED;
sock->state = SS_UNCONNECTED;
goto out_wait;
}
static int vsock_accept(struct socket *sock, struct socket *newsock, int flags)
{
struct sock *listener;
int err;
struct sock *connected;
struct vsock_sock *vconnected;
long timeout;
DEFINE_WAIT(wait);
err = 0;
listener = sock->sk;
lock_sock(listener);
if (sock->type != SOCK_STREAM) {
err = -EOPNOTSUPP;
goto out;
}
if (listener->sk_state != VSOCK_SS_LISTEN) {
err = -EINVAL;
goto out;
}
timeout = sock_sndtimeo(listener, flags & O_NONBLOCK);
prepare_to_wait(sk_sleep(listener), &wait, TASK_INTERRUPTIBLE);
while ((connected = vsock_dequeue_accept(listener)) == NULL &&
listener->sk_err == 0) {
release_sock(listener);
timeout = schedule_timeout(timeout);
lock_sock(listener);
if (signal_pending(current)) {
err = sock_intr_errno(timeout);
goto out_wait;
} else if (timeout == 0) {
err = -EAGAIN;
goto out_wait;
}
prepare_to_wait(sk_sleep(listener), &wait, TASK_INTERRUPTIBLE);
}
if (listener->sk_err)
err = -listener->sk_err;
if (connected) {
listener->sk_ack_backlog--;
lock_sock(connected);
vconnected = vsock_sk(connected);
if (err) {
vconnected->rejected = true;
release_sock(connected);
sock_put(connected);
goto out_wait;
}
newsock->state = SS_CONNECTED;
sock_graft(connected, newsock);
release_sock(connected);
sock_put(connected);
}
out_wait:
finish_wait(sk_sleep(listener), &wait);
out:
release_sock(listener);
return err;
}
static int vsock_listen(struct socket *sock, int backlog)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
sk = sock->sk;
lock_sock(sk);
if (sock->type != SOCK_STREAM) {
err = -EOPNOTSUPP;
goto out;
}
if (sock->state != SS_UNCONNECTED) {
err = -EINVAL;
goto out;
}
vsk = vsock_sk(sk);
if (!vsock_addr_bound(&vsk->local_addr)) {
err = -EINVAL;
goto out;
}
sk->sk_max_ack_backlog = backlog;
sk->sk_state = VSOCK_SS_LISTEN;
err = 0;
out:
release_sock(sk);
return err;
}
static int vsock_stream_setsockopt(struct socket *sock,
int level,
int optname,
char __user *optval,
unsigned int optlen)
{
int err;
struct sock *sk;
struct vsock_sock *vsk;
u64 val;
if (level != AF_VSOCK)
return -ENOPROTOOPT;
#define COPY_IN(_v) \
do { \
if (optlen < sizeof(_v)) { \
err = -EINVAL; \
goto exit; \
} \
if (copy_from_user(&_v, optval, sizeof(_v)) != 0) { \
err = -EFAULT; \
goto exit; \
} \
} while (0)
err = 0;
sk = sock->sk;
vsk = vsock_sk(sk);
lock_sock(sk);
switch (optname) {
case SO_VM_SOCKETS_BUFFER_SIZE:
COPY_IN(val);
transport->set_buffer_size(vsk, val);
break;
case SO_VM_SOCKETS_BUFFER_MAX_SIZE:
COPY_IN(val);
transport->set_max_buffer_size(vsk, val);
break;
case SO_VM_SOCKETS_BUFFER_MIN_SIZE:
COPY_IN(val);
transport->set_min_buffer_size(vsk, val);
break;
case SO_VM_SOCKETS_CONNECT_TIMEOUT: {
struct timeval tv;
COPY_IN(tv);
if (tv.tv_sec >= 0 && tv.tv_usec < USEC_PER_SEC &&
tv.tv_sec < (MAX_SCHEDULE_TIMEOUT / HZ - 1)) {
vsk->connect_timeout = tv.tv_sec * HZ +
DIV_ROUND_UP(tv.tv_usec, (1000000 / HZ));
if (vsk->connect_timeout == 0)
vsk->connect_timeout =
VSOCK_DEFAULT_CONNECT_TIMEOUT;
} else {
err = -ERANGE;
}
break;
}
default:
err = -ENOPROTOOPT;
break;
}
#undef COPY_IN
exit:
release_sock(sk);
return err;
}
static int vsock_stream_getsockopt(struct socket *sock,
int level, int optname,
char __user *optval,
int __user *optlen)
{
int err;
int len;
struct sock *sk;
struct vsock_sock *vsk;
u64 val;
if (level != AF_VSOCK)
return -ENOPROTOOPT;
err = get_user(len, optlen);
if (err != 0)
return err;
#define COPY_OUT(_v) \
do { \
if (len < sizeof(_v)) \
return -EINVAL; \
\
len = sizeof(_v); \
if (copy_to_user(optval, &_v, len) != 0) \
return -EFAULT; \
\
} while (0)
err = 0;
sk = sock->sk;
vsk = vsock_sk(sk);
switch (optname) {
case SO_VM_SOCKETS_BUFFER_SIZE:
val = transport->get_buffer_size(vsk);
COPY_OUT(val);
break;
case SO_VM_SOCKETS_BUFFER_MAX_SIZE:
val = transport->get_max_buffer_size(vsk);
COPY_OUT(val);
break;
case SO_VM_SOCKETS_BUFFER_MIN_SIZE:
val = transport->get_min_buffer_size(vsk);
COPY_OUT(val);
break;
case SO_VM_SOCKETS_CONNECT_TIMEOUT: {
struct timeval tv;
tv.tv_sec = vsk->connect_timeout / HZ;
tv.tv_usec =
(vsk->connect_timeout -
tv.tv_sec * HZ) * (1000000 / HZ);
COPY_OUT(tv);
break;
}
default:
return -ENOPROTOOPT;
}
err = put_user(len, optlen);
if (err != 0)
return -EFAULT;
#undef COPY_OUT
return 0;
}
static int vsock_stream_sendmsg(struct socket *sock, struct msghdr *msg,
size_t len)
{
struct sock *sk;
struct vsock_sock *vsk;
ssize_t total_written;
long timeout;
int err;
struct vsock_transport_send_notify_data send_data;
DEFINE_WAIT(wait);
sk = sock->sk;
vsk = vsock_sk(sk);
total_written = 0;
err = 0;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
lock_sock(sk);
if (msg->msg_namelen) {
err = sk->sk_state == SS_CONNECTED ? -EISCONN : -EOPNOTSUPP;
goto out;
}
if (sk->sk_shutdown & SEND_SHUTDOWN ||
vsk->peer_shutdown & RCV_SHUTDOWN) {
err = -EPIPE;
goto out;
}
if (sk->sk_state != SS_CONNECTED ||
!vsock_addr_bound(&vsk->local_addr)) {
err = -ENOTCONN;
goto out;
}
if (!vsock_addr_bound(&vsk->remote_addr)) {
err = -EDESTADDRREQ;
goto out;
}
timeout = sock_sndtimeo(sk, msg->msg_flags & MSG_DONTWAIT);
err = transport->notify_send_init(vsk, &send_data);
if (err < 0)
goto out;
while (total_written < len) {
ssize_t written;
while (vsock_stream_has_space(vsk) == 0 &&
sk->sk_err == 0 &&
!(sk->sk_shutdown & SEND_SHUTDOWN) &&
!(vsk->peer_shutdown & RCV_SHUTDOWN)) {
if (timeout == 0) {
err = -EAGAIN;
goto out_wait;
}
err = transport->notify_send_pre_block(vsk, &send_data);
if (err < 0)
goto out_wait;
release_sock(sk);
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
timeout = schedule_timeout(timeout);
finish_wait(sk_sleep(sk), &wait);
lock_sock(sk);
if (signal_pending(current)) {
err = sock_intr_errno(timeout);
goto out_wait;
} else if (timeout == 0) {
err = -EAGAIN;
goto out_wait;
}
}
if (sk->sk_err) {
err = -sk->sk_err;
goto out_wait;
} else if ((sk->sk_shutdown & SEND_SHUTDOWN) ||
(vsk->peer_shutdown & RCV_SHUTDOWN)) {
err = -EPIPE;
goto out_wait;
}
err = transport->notify_send_pre_enqueue(vsk, &send_data);
if (err < 0)
goto out_wait;
written = transport->stream_enqueue(
vsk, msg,
len - total_written);
if (written < 0) {
err = -ENOMEM;
goto out_wait;
}
total_written += written;
err = transport->notify_send_post_enqueue(
vsk, written, &send_data);
if (err < 0)
goto out_wait;
}
out_wait:
if (total_written > 0)
err = total_written;
out:
release_sock(sk);
return err;
}
static int
vsock_stream_recvmsg(struct socket *sock, struct msghdr *msg, size_t len,
int flags)
{
struct sock *sk;
struct vsock_sock *vsk;
int err;
size_t target;
ssize_t copied;
long timeout;
struct vsock_transport_recv_notify_data recv_data;
DEFINE_WAIT(wait);
sk = sock->sk;
vsk = vsock_sk(sk);
err = 0;
lock_sock(sk);
if (sk->sk_state != SS_CONNECTED) {
if (sock_flag(sk, SOCK_DONE))
err = 0;
else
err = -ENOTCONN;
goto out;
}
if (flags & MSG_OOB) {
err = -EOPNOTSUPP;
goto out;
}
if (sk->sk_shutdown & RCV_SHUTDOWN) {
err = 0;
goto out;
}
if (!len) {
err = 0;
goto out;
}
target = sock_rcvlowat(sk, flags & MSG_WAITALL, len);
if (target >= transport->stream_rcvhiwat(vsk)) {
err = -ENOMEM;
goto out;
}
timeout = sock_rcvtimeo(sk, flags & MSG_DONTWAIT);
copied = 0;
err = transport->notify_recv_init(vsk, target, &recv_data);
if (err < 0)
goto out;
while (1) {
s64 ready = vsock_stream_has_data(vsk);
if (ready < 0) {
err = -ENOMEM;
goto out;
} else if (ready > 0) {
ssize_t read;
err = transport->notify_recv_pre_dequeue(
vsk, target, &recv_data);
if (err < 0)
break;
read = transport->stream_dequeue(
vsk, msg,
len - copied, flags);
if (read < 0) {
err = -ENOMEM;
break;
}
copied += read;
err = transport->notify_recv_post_dequeue(
vsk, target, read,
!(flags & MSG_PEEK), &recv_data);
if (err < 0)
goto out;
if (read >= target || flags & MSG_PEEK)
break;
target -= read;
} else {
if (sk->sk_err != 0 || (sk->sk_shutdown & RCV_SHUTDOWN)
|| (vsk->peer_shutdown & SEND_SHUTDOWN)) {
break;
}
if (timeout == 0) {
err = -EAGAIN;
break;
}
err = transport->notify_recv_pre_block(
vsk, target, &recv_data);
if (err < 0)
break;
release_sock(sk);
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
timeout = schedule_timeout(timeout);
finish_wait(sk_sleep(sk), &wait);
lock_sock(sk);
if (signal_pending(current)) {
err = sock_intr_errno(timeout);
break;
} else if (timeout == 0) {
err = -EAGAIN;
break;
}
}
}
if (sk->sk_err)
err = -sk->sk_err;
else if (sk->sk_shutdown & RCV_SHUTDOWN)
err = 0;
if (copied > 0) {
if (!(flags & MSG_PEEK)) {
if (vsk->peer_shutdown & SEND_SHUTDOWN) {
if (vsock_stream_has_data(vsk) <= 0) {
sk->sk_state = SS_UNCONNECTED;
sock_set_flag(sk, SOCK_DONE);
sk->sk_state_change(sk);
}
}
}
err = copied;
}
out:
release_sock(sk);
return err;
}
static int vsock_create(struct net *net, struct socket *sock,
int protocol, int kern)
{
if (!sock)
return -EINVAL;
if (protocol && protocol != PF_VSOCK)
return -EPROTONOSUPPORT;
switch (sock->type) {
case SOCK_DGRAM:
sock->ops = &vsock_dgram_ops;
break;
case SOCK_STREAM:
sock->ops = &vsock_stream_ops;
break;
default:
return -ESOCKTNOSUPPORT;
}
sock->state = SS_UNCONNECTED;
return __vsock_create(net, sock, NULL, GFP_KERNEL, 0, kern) ? 0 : -ENOMEM;
}
static long vsock_dev_do_ioctl(struct file *filp,
unsigned int cmd, void __user *ptr)
{
u32 __user *p = ptr;
int retval = 0;
switch (cmd) {
case IOCTL_VM_SOCKETS_GET_LOCAL_CID:
if (put_user(transport->get_local_cid(), p) != 0)
retval = -EFAULT;
break;
default:
pr_err("Unknown ioctl %d\n", cmd);
retval = -EINVAL;
}
return retval;
}
static long vsock_dev_ioctl(struct file *filp,
unsigned int cmd, unsigned long arg)
{
return vsock_dev_do_ioctl(filp, cmd, (void __user *)arg);
}
static long vsock_dev_compat_ioctl(struct file *filp,
unsigned int cmd, unsigned long arg)
{
return vsock_dev_do_ioctl(filp, cmd, compat_ptr(arg));
}
int __vsock_core_init(const struct vsock_transport *t, struct module *owner)
{
int err = mutex_lock_interruptible(&vsock_register_mutex);
if (err)
return err;
if (transport) {
err = -EBUSY;
goto err_busy;
}
vsock_proto.owner = owner;
transport = t;
vsock_init_tables();
vsock_device.minor = MISC_DYNAMIC_MINOR;
err = misc_register(&vsock_device);
if (err) {
pr_err("Failed to register misc device\n");
goto err_reset_transport;
}
err = proto_register(&vsock_proto, 1);
if (err) {
pr_err("Cannot register vsock protocol\n");
goto err_deregister_misc;
}
err = sock_register(&vsock_family_ops);
if (err) {
pr_err("could not register af_vsock (%d) address family: %d\n",
AF_VSOCK, err);
goto err_unregister_proto;
}
mutex_unlock(&vsock_register_mutex);
return 0;
err_unregister_proto:
proto_unregister(&vsock_proto);
err_deregister_misc:
misc_deregister(&vsock_device);
err_reset_transport:
transport = NULL;
err_busy:
mutex_unlock(&vsock_register_mutex);
return err;
}
void vsock_core_exit(void)
{
mutex_lock(&vsock_register_mutex);
misc_deregister(&vsock_device);
sock_unregister(AF_VSOCK);
proto_unregister(&vsock_proto);
mb();
transport = NULL;
mutex_unlock(&vsock_register_mutex);
}
