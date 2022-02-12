static struct hlist_head *unix_sockets_unbound(void *addr)
{
unsigned long hash = (unsigned long)addr;
hash ^= hash >> 16;
hash ^= hash >> 8;
hash %= UNIX_HASH_SIZE;
return &unix_socket_table[UNIX_HASH_SIZE + hash];
}
static void unix_get_secdata(struct scm_cookie *scm, struct sk_buff *skb)
{
memcpy(UNIXSID(skb), &scm->secid, sizeof(u32));
}
static inline void unix_set_secdata(struct scm_cookie *scm, struct sk_buff *skb)
{
scm->secid = *UNIXSID(skb);
}
static inline void unix_get_secdata(struct scm_cookie *scm, struct sk_buff *skb)
{ }
static inline void unix_set_secdata(struct scm_cookie *scm, struct sk_buff *skb)
{ }
static inline unsigned int unix_hash_fold(__wsum n)
{
unsigned int hash = (__force unsigned int)csum_fold(n);
hash ^= hash>>8;
return hash&(UNIX_HASH_SIZE-1);
}
static inline int unix_our_peer(struct sock *sk, struct sock *osk)
{
return unix_peer(osk) == sk;
}
static inline int unix_may_send(struct sock *sk, struct sock *osk)
{
return unix_peer(osk) == NULL || unix_our_peer(sk, osk);
}
static inline int unix_recvq_full(struct sock const *sk)
{
return skb_queue_len(&sk->sk_receive_queue) > sk->sk_max_ack_backlog;
}
struct sock *unix_peer_get(struct sock *s)
{
struct sock *peer;
unix_state_lock(s);
peer = unix_peer(s);
if (peer)
sock_hold(peer);
unix_state_unlock(s);
return peer;
}
static inline void unix_release_addr(struct unix_address *addr)
{
if (atomic_dec_and_test(&addr->refcnt))
kfree(addr);
}
static int unix_mkname(struct sockaddr_un *sunaddr, int len, unsigned int *hashp)
{
if (len <= sizeof(short) || len > sizeof(*sunaddr))
return -EINVAL;
if (!sunaddr || sunaddr->sun_family != AF_UNIX)
return -EINVAL;
if (sunaddr->sun_path[0]) {
((char *)sunaddr)[len] = 0;
len = strlen(sunaddr->sun_path)+1+sizeof(short);
return len;
}
*hashp = unix_hash_fold(csum_partial(sunaddr, len, 0));
return len;
}
static void __unix_remove_socket(struct sock *sk)
{
sk_del_node_init(sk);
}
static void __unix_insert_socket(struct hlist_head *list, struct sock *sk)
{
WARN_ON(!sk_unhashed(sk));
sk_add_node(sk, list);
}
static inline void unix_remove_socket(struct sock *sk)
{
spin_lock(&unix_table_lock);
__unix_remove_socket(sk);
spin_unlock(&unix_table_lock);
}
static inline void unix_insert_socket(struct hlist_head *list, struct sock *sk)
{
spin_lock(&unix_table_lock);
__unix_insert_socket(list, sk);
spin_unlock(&unix_table_lock);
}
static struct sock *__unix_find_socket_byname(struct net *net,
struct sockaddr_un *sunname,
int len, int type, unsigned int hash)
{
struct sock *s;
sk_for_each(s, &unix_socket_table[hash ^ type]) {
struct unix_sock *u = unix_sk(s);
if (!net_eq(sock_net(s), net))
continue;
if (u->addr->len == len &&
!memcmp(u->addr->name, sunname, len))
goto found;
}
s = NULL;
found:
return s;
}
static inline struct sock *unix_find_socket_byname(struct net *net,
struct sockaddr_un *sunname,
int len, int type,
unsigned int hash)
{
struct sock *s;
spin_lock(&unix_table_lock);
s = __unix_find_socket_byname(net, sunname, len, type, hash);
if (s)
sock_hold(s);
spin_unlock(&unix_table_lock);
return s;
}
static struct sock *unix_find_socket_byinode(struct inode *i)
{
struct sock *s;
spin_lock(&unix_table_lock);
sk_for_each(s,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct dentry *dentry = unix_sk(s)->path.dentry;
if (dentry && dentry->d_inode == i) {
sock_hold(s);
goto found;
}
}
s = NULL;
found:
spin_unlock(&unix_table_lock);
return s;
}
static inline int unix_writable(struct sock *sk)
{
return (atomic_read(&sk->sk_wmem_alloc) << 2) <= sk->sk_sndbuf;
}
static void unix_write_space(struct sock *sk)
{
struct socket_wq *wq;
rcu_read_lock();
if (unix_writable(sk)) {
wq = rcu_dereference(sk->sk_wq);
if (wq_has_sleeper(wq))
wake_up_interruptible_sync_poll(&wq->wait,
POLLOUT | POLLWRNORM | POLLWRBAND);
sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
}
rcu_read_unlock();
}
static void unix_dgram_disconnected(struct sock *sk, struct sock *other)
{
if (!skb_queue_empty(&sk->sk_receive_queue)) {
skb_queue_purge(&sk->sk_receive_queue);
wake_up_interruptible_all(&unix_sk(sk)->peer_wait);
if (!sock_flag(other, SOCK_DEAD) && unix_peer(other) == sk) {
other->sk_err = ECONNRESET;
other->sk_error_report(other);
}
}
}
static void unix_sock_destructor(struct sock *sk)
{
struct unix_sock *u = unix_sk(sk);
skb_queue_purge(&sk->sk_receive_queue);
WARN_ON(atomic_read(&sk->sk_wmem_alloc));
WARN_ON(!sk_unhashed(sk));
WARN_ON(sk->sk_socket);
if (!sock_flag(sk, SOCK_DEAD)) {
pr_info("Attempt to release alive unix socket: %p\n", sk);
return;
}
if (u->addr)
unix_release_addr(u->addr);
atomic_long_dec(&unix_nr_socks);
local_bh_disable();
sock_prot_inuse_add(sock_net(sk), sk->sk_prot, -1);
local_bh_enable();
#ifdef UNIX_REFCNT_DEBUG
pr_debug("UNIX %p is destroyed, %ld are still alive.\n", sk,
atomic_long_read(&unix_nr_socks));
#endif
}
static void unix_release_sock(struct sock *sk, int embrion)
{
struct unix_sock *u = unix_sk(sk);
struct path path;
struct sock *skpair;
struct sk_buff *skb;
int state;
unix_remove_socket(sk);
unix_state_lock(sk);
sock_orphan(sk);
sk->sk_shutdown = SHUTDOWN_MASK;
path = u->path;
u->path.dentry = NULL;
u->path.mnt = NULL;
state = sk->sk_state;
sk->sk_state = TCP_CLOSE;
unix_state_unlock(sk);
wake_up_interruptible_all(&u->peer_wait);
skpair = unix_peer(sk);
if (skpair != NULL) {
if (sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_SEQPACKET) {
unix_state_lock(skpair);
skpair->sk_shutdown = SHUTDOWN_MASK;
if (!skb_queue_empty(&sk->sk_receive_queue) || embrion)
skpair->sk_err = ECONNRESET;
unix_state_unlock(skpair);
skpair->sk_state_change(skpair);
sk_wake_async(skpair, SOCK_WAKE_WAITD, POLL_HUP);
}
sock_put(skpair);
unix_peer(sk) = NULL;
}
while ((skb = skb_dequeue(&sk->sk_receive_queue)) != NULL) {
if (state == TCP_LISTEN)
unix_release_sock(skb->sk, 1);
kfree_skb(skb);
}
if (path.dentry)
path_put(&path);
sock_put(sk);
if (unix_tot_inflight)
unix_gc();
}
static void init_peercred(struct sock *sk)
{
put_pid(sk->sk_peer_pid);
if (sk->sk_peer_cred)
put_cred(sk->sk_peer_cred);
sk->sk_peer_pid = get_pid(task_tgid(current));
sk->sk_peer_cred = get_current_cred();
}
static void copy_peercred(struct sock *sk, struct sock *peersk)
{
put_pid(sk->sk_peer_pid);
if (sk->sk_peer_cred)
put_cred(sk->sk_peer_cred);
sk->sk_peer_pid = get_pid(peersk->sk_peer_pid);
sk->sk_peer_cred = get_cred(peersk->sk_peer_cred);
}
static int unix_listen(struct socket *sock, int backlog)
{
int err;
struct sock *sk = sock->sk;
struct unix_sock *u = unix_sk(sk);
struct pid *old_pid = NULL;
err = -EOPNOTSUPP;
if (sock->type != SOCK_STREAM && sock->type != SOCK_SEQPACKET)
goto out;
err = -EINVAL;
if (!u->addr)
goto out;
unix_state_lock(sk);
if (sk->sk_state != TCP_CLOSE && sk->sk_state != TCP_LISTEN)
goto out_unlock;
if (backlog > sk->sk_max_ack_backlog)
wake_up_interruptible_all(&u->peer_wait);
sk->sk_max_ack_backlog = backlog;
sk->sk_state = TCP_LISTEN;
init_peercred(sk);
err = 0;
out_unlock:
unix_state_unlock(sk);
put_pid(old_pid);
out:
return err;
}
static int unix_set_peek_off(struct sock *sk, int val)
{
struct unix_sock *u = unix_sk(sk);
if (mutex_lock_interruptible(&u->readlock))
return -EINTR;
sk->sk_peek_off = val;
mutex_unlock(&u->readlock);
return 0;
}
static struct sock *unix_create1(struct net *net, struct socket *sock)
{
struct sock *sk = NULL;
struct unix_sock *u;
atomic_long_inc(&unix_nr_socks);
if (atomic_long_read(&unix_nr_socks) > 2 * get_max_files())
goto out;
sk = sk_alloc(net, PF_UNIX, GFP_KERNEL, &unix_proto);
if (!sk)
goto out;
sock_init_data(sock, sk);
lockdep_set_class(&sk->sk_receive_queue.lock,
&af_unix_sk_receive_queue_lock_key);
sk->sk_write_space = unix_write_space;
sk->sk_max_ack_backlog = net->unx.sysctl_max_dgram_qlen;
sk->sk_destruct = unix_sock_destructor;
u = unix_sk(sk);
u->path.dentry = NULL;
u->path.mnt = NULL;
spin_lock_init(&u->lock);
atomic_long_set(&u->inflight, 0);
INIT_LIST_HEAD(&u->link);
mutex_init(&u->readlock);
init_waitqueue_head(&u->peer_wait);
unix_insert_socket(unix_sockets_unbound(sk), sk);
out:
if (sk == NULL)
atomic_long_dec(&unix_nr_socks);
else {
local_bh_disable();
sock_prot_inuse_add(sock_net(sk), sk->sk_prot, 1);
local_bh_enable();
}
return sk;
}
static int unix_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
if (protocol && protocol != PF_UNIX)
return -EPROTONOSUPPORT;
sock->state = SS_UNCONNECTED;
switch (sock->type) {
case SOCK_STREAM:
sock->ops = &unix_stream_ops;
break;
case SOCK_RAW:
sock->type = SOCK_DGRAM;
case SOCK_DGRAM:
sock->ops = &unix_dgram_ops;
break;
case SOCK_SEQPACKET:
sock->ops = &unix_seqpacket_ops;
break;
default:
return -ESOCKTNOSUPPORT;
}
return unix_create1(net, sock) ? 0 : -ENOMEM;
}
static int unix_release(struct socket *sock)
{
struct sock *sk = sock->sk;
if (!sk)
return 0;
unix_release_sock(sk, 0);
sock->sk = NULL;
return 0;
}
static int unix_autobind(struct socket *sock)
{
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct unix_sock *u = unix_sk(sk);
static u32 ordernum = 1;
struct unix_address *addr;
int err;
unsigned int retries = 0;
err = mutex_lock_interruptible(&u->readlock);
if (err)
return err;
err = 0;
if (u->addr)
goto out;
err = -ENOMEM;
addr = kzalloc(sizeof(*addr) + sizeof(short) + 16, GFP_KERNEL);
if (!addr)
goto out;
addr->name->sun_family = AF_UNIX;
atomic_set(&addr->refcnt, 1);
retry:
addr->len = sprintf(addr->name->sun_path+1, "%05x", ordernum) + 1 + sizeof(short);
addr->hash = unix_hash_fold(csum_partial(addr->name, addr->len, 0));
spin_lock(&unix_table_lock);
ordernum = (ordernum+1)&0xFFFFF;
if (__unix_find_socket_byname(net, addr->name, addr->len, sock->type,
addr->hash)) {
spin_unlock(&unix_table_lock);
cond_resched();
if (retries++ == 0xFFFFF) {
err = -ENOSPC;
kfree(addr);
goto out;
}
goto retry;
}
addr->hash ^= sk->sk_type;
__unix_remove_socket(sk);
u->addr = addr;
__unix_insert_socket(&unix_socket_table[addr->hash], sk);
spin_unlock(&unix_table_lock);
err = 0;
out: mutex_unlock(&u->readlock);
return err;
}
static struct sock *unix_find_other(struct net *net,
struct sockaddr_un *sunname, int len,
int type, unsigned int hash, int *error)
{
struct sock *u;
struct path path;
int err = 0;
if (sunname->sun_path[0]) {
struct inode *inode;
err = kern_path(sunname->sun_path, LOOKUP_FOLLOW, &path);
if (err)
goto fail;
inode = path.dentry->d_inode;
err = inode_permission(inode, MAY_WRITE);
if (err)
goto put_fail;
err = -ECONNREFUSED;
if (!S_ISSOCK(inode->i_mode))
goto put_fail;
u = unix_find_socket_byinode(inode);
if (!u)
goto put_fail;
if (u->sk_type == type)
touch_atime(&path);
path_put(&path);
err = -EPROTOTYPE;
if (u->sk_type != type) {
sock_put(u);
goto fail;
}
} else {
err = -ECONNREFUSED;
u = unix_find_socket_byname(net, sunname, len, type, hash);
if (u) {
struct dentry *dentry;
dentry = unix_sk(u)->path.dentry;
if (dentry)
touch_atime(&unix_sk(u)->path);
} else
goto fail;
}
return u;
put_fail:
path_put(&path);
fail:
*error = err;
return NULL;
}
static int unix_mknod(const char *sun_path, umode_t mode, struct path *res)
{
struct dentry *dentry;
struct path path;
int err = 0;
dentry = kern_path_create(AT_FDCWD, sun_path, &path, 0);
err = PTR_ERR(dentry);
if (IS_ERR(dentry))
return err;
err = security_path_mknod(&path, dentry, mode, 0);
if (!err) {
err = vfs_mknod(path.dentry->d_inode, dentry, mode, 0);
if (!err) {
res->mnt = mntget(path.mnt);
res->dentry = dget(dentry);
}
}
done_path_create(&path, dentry);
return err;
}
static int unix_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct unix_sock *u = unix_sk(sk);
struct sockaddr_un *sunaddr = (struct sockaddr_un *)uaddr;
char *sun_path = sunaddr->sun_path;
int err;
unsigned int hash;
struct unix_address *addr;
struct hlist_head *list;
err = -EINVAL;
if (sunaddr->sun_family != AF_UNIX)
goto out;
if (addr_len == sizeof(short)) {
err = unix_autobind(sock);
goto out;
}
err = unix_mkname(sunaddr, addr_len, &hash);
if (err < 0)
goto out;
addr_len = err;
err = mutex_lock_interruptible(&u->readlock);
if (err)
goto out;
err = -EINVAL;
if (u->addr)
goto out_up;
err = -ENOMEM;
addr = kmalloc(sizeof(*addr)+addr_len, GFP_KERNEL);
if (!addr)
goto out_up;
memcpy(addr->name, sunaddr, addr_len);
addr->len = addr_len;
addr->hash = hash ^ sk->sk_type;
atomic_set(&addr->refcnt, 1);
if (sun_path[0]) {
struct path path;
umode_t mode = S_IFSOCK |
(SOCK_INODE(sock)->i_mode & ~current_umask());
err = unix_mknod(sun_path, mode, &path);
if (err) {
if (err == -EEXIST)
err = -EADDRINUSE;
unix_release_addr(addr);
goto out_up;
}
addr->hash = UNIX_HASH_SIZE;
hash = path.dentry->d_inode->i_ino & (UNIX_HASH_SIZE-1);
spin_lock(&unix_table_lock);
u->path = path;
list = &unix_socket_table[hash];
} else {
spin_lock(&unix_table_lock);
err = -EADDRINUSE;
if (__unix_find_socket_byname(net, sunaddr, addr_len,
sk->sk_type, hash)) {
unix_release_addr(addr);
goto out_unlock;
}
list = &unix_socket_table[addr->hash];
}
err = 0;
__unix_remove_socket(sk);
u->addr = addr;
__unix_insert_socket(list, sk);
out_unlock:
spin_unlock(&unix_table_lock);
out_up:
mutex_unlock(&u->readlock);
out:
return err;
}
static void unix_state_double_lock(struct sock *sk1, struct sock *sk2)
{
if (unlikely(sk1 == sk2) || !sk2) {
unix_state_lock(sk1);
return;
}
if (sk1 < sk2) {
unix_state_lock(sk1);
unix_state_lock_nested(sk2);
} else {
unix_state_lock(sk2);
unix_state_lock_nested(sk1);
}
}
static void unix_state_double_unlock(struct sock *sk1, struct sock *sk2)
{
if (unlikely(sk1 == sk2) || !sk2) {
unix_state_unlock(sk1);
return;
}
unix_state_unlock(sk1);
unix_state_unlock(sk2);
}
static int unix_dgram_connect(struct socket *sock, struct sockaddr *addr,
int alen, int flags)
{
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct sockaddr_un *sunaddr = (struct sockaddr_un *)addr;
struct sock *other;
unsigned int hash;
int err;
if (addr->sa_family != AF_UNSPEC) {
err = unix_mkname(sunaddr, alen, &hash);
if (err < 0)
goto out;
alen = err;
if (test_bit(SOCK_PASSCRED, &sock->flags) &&
!unix_sk(sk)->addr && (err = unix_autobind(sock)) != 0)
goto out;
restart:
other = unix_find_other(net, sunaddr, alen, sock->type, hash, &err);
if (!other)
goto out;
unix_state_double_lock(sk, other);
if (sock_flag(other, SOCK_DEAD)) {
unix_state_double_unlock(sk, other);
sock_put(other);
goto restart;
}
err = -EPERM;
if (!unix_may_send(sk, other))
goto out_unlock;
err = security_unix_may_send(sk->sk_socket, other->sk_socket);
if (err)
goto out_unlock;
} else {
other = NULL;
unix_state_double_lock(sk, other);
}
if (unix_peer(sk)) {
struct sock *old_peer = unix_peer(sk);
unix_peer(sk) = other;
unix_state_double_unlock(sk, other);
if (other != old_peer)
unix_dgram_disconnected(sk, old_peer);
sock_put(old_peer);
} else {
unix_peer(sk) = other;
unix_state_double_unlock(sk, other);
}
return 0;
out_unlock:
unix_state_double_unlock(sk, other);
sock_put(other);
out:
return err;
}
static long unix_wait_for_peer(struct sock *other, long timeo)
{
struct unix_sock *u = unix_sk(other);
int sched;
DEFINE_WAIT(wait);
prepare_to_wait_exclusive(&u->peer_wait, &wait, TASK_INTERRUPTIBLE);
sched = !sock_flag(other, SOCK_DEAD) &&
!(other->sk_shutdown & RCV_SHUTDOWN) &&
unix_recvq_full(other);
unix_state_unlock(other);
if (sched)
timeo = schedule_timeout(timeo);
finish_wait(&u->peer_wait, &wait);
return timeo;
}
static int unix_stream_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
struct sockaddr_un *sunaddr = (struct sockaddr_un *)uaddr;
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct unix_sock *u = unix_sk(sk), *newu, *otheru;
struct sock *newsk = NULL;
struct sock *other = NULL;
struct sk_buff *skb = NULL;
unsigned int hash;
int st;
int err;
long timeo;
err = unix_mkname(sunaddr, addr_len, &hash);
if (err < 0)
goto out;
addr_len = err;
if (test_bit(SOCK_PASSCRED, &sock->flags) && !u->addr &&
(err = unix_autobind(sock)) != 0)
goto out;
timeo = sock_sndtimeo(sk, flags & O_NONBLOCK);
err = -ENOMEM;
newsk = unix_create1(sock_net(sk), NULL);
if (newsk == NULL)
goto out;
skb = sock_wmalloc(newsk, 1, 0, GFP_KERNEL);
if (skb == NULL)
goto out;
restart:
other = unix_find_other(net, sunaddr, addr_len, sk->sk_type, hash, &err);
if (!other)
goto out;
unix_state_lock(other);
if (sock_flag(other, SOCK_DEAD)) {
unix_state_unlock(other);
sock_put(other);
goto restart;
}
err = -ECONNREFUSED;
if (other->sk_state != TCP_LISTEN)
goto out_unlock;
if (other->sk_shutdown & RCV_SHUTDOWN)
goto out_unlock;
if (unix_recvq_full(other)) {
err = -EAGAIN;
if (!timeo)
goto out_unlock;
timeo = unix_wait_for_peer(other, timeo);
err = sock_intr_errno(timeo);
if (signal_pending(current))
goto out;
sock_put(other);
goto restart;
}
st = sk->sk_state;
switch (st) {
case TCP_CLOSE:
break;
case TCP_ESTABLISHED:
err = -EISCONN;
goto out_unlock;
default:
err = -EINVAL;
goto out_unlock;
}
unix_state_lock_nested(sk);
if (sk->sk_state != st) {
unix_state_unlock(sk);
unix_state_unlock(other);
sock_put(other);
goto restart;
}
err = security_unix_stream_connect(sk, other, newsk);
if (err) {
unix_state_unlock(sk);
goto out_unlock;
}
sock_hold(sk);
unix_peer(newsk) = sk;
newsk->sk_state = TCP_ESTABLISHED;
newsk->sk_type = sk->sk_type;
init_peercred(newsk);
newu = unix_sk(newsk);
RCU_INIT_POINTER(newsk->sk_wq, &newu->peer_wq);
otheru = unix_sk(other);
if (otheru->addr) {
atomic_inc(&otheru->addr->refcnt);
newu->addr = otheru->addr;
}
if (otheru->path.dentry) {
path_get(&otheru->path);
newu->path = otheru->path;
}
copy_peercred(sk, other);
sock->state = SS_CONNECTED;
sk->sk_state = TCP_ESTABLISHED;
sock_hold(newsk);
smp_mb__after_atomic_inc();
unix_peer(sk) = newsk;
unix_state_unlock(sk);
spin_lock(&other->sk_receive_queue.lock);
__skb_queue_tail(&other->sk_receive_queue, skb);
spin_unlock(&other->sk_receive_queue.lock);
unix_state_unlock(other);
other->sk_data_ready(other);
sock_put(other);
return 0;
out_unlock:
if (other)
unix_state_unlock(other);
out:
kfree_skb(skb);
if (newsk)
unix_release_sock(newsk, 0);
if (other)
sock_put(other);
return err;
}
static int unix_socketpair(struct socket *socka, struct socket *sockb)
{
struct sock *ska = socka->sk, *skb = sockb->sk;
sock_hold(ska);
sock_hold(skb);
unix_peer(ska) = skb;
unix_peer(skb) = ska;
init_peercred(ska);
init_peercred(skb);
if (ska->sk_type != SOCK_DGRAM) {
ska->sk_state = TCP_ESTABLISHED;
skb->sk_state = TCP_ESTABLISHED;
socka->state = SS_CONNECTED;
sockb->state = SS_CONNECTED;
}
return 0;
}
static void unix_sock_inherit_flags(const struct socket *old,
struct socket *new)
{
if (test_bit(SOCK_PASSCRED, &old->flags))
set_bit(SOCK_PASSCRED, &new->flags);
if (test_bit(SOCK_PASSSEC, &old->flags))
set_bit(SOCK_PASSSEC, &new->flags);
}
static int unix_accept(struct socket *sock, struct socket *newsock, int flags)
{
struct sock *sk = sock->sk;
struct sock *tsk;
struct sk_buff *skb;
int err;
err = -EOPNOTSUPP;
if (sock->type != SOCK_STREAM && sock->type != SOCK_SEQPACKET)
goto out;
err = -EINVAL;
if (sk->sk_state != TCP_LISTEN)
goto out;
skb = skb_recv_datagram(sk, 0, flags&O_NONBLOCK, &err);
if (!skb) {
if (err == 0)
err = -EINVAL;
goto out;
}
tsk = skb->sk;
skb_free_datagram(sk, skb);
wake_up_interruptible(&unix_sk(sk)->peer_wait);
unix_state_lock(tsk);
newsock->state = SS_CONNECTED;
unix_sock_inherit_flags(sock, newsock);
sock_graft(tsk, newsock);
unix_state_unlock(tsk);
return 0;
out:
return err;
}
static int unix_getname(struct socket *sock, struct sockaddr *uaddr, int *uaddr_len, int peer)
{
struct sock *sk = sock->sk;
struct unix_sock *u;
DECLARE_SOCKADDR(struct sockaddr_un *, sunaddr, uaddr);
int err = 0;
if (peer) {
sk = unix_peer_get(sk);
err = -ENOTCONN;
if (!sk)
goto out;
err = 0;
} else {
sock_hold(sk);
}
u = unix_sk(sk);
unix_state_lock(sk);
if (!u->addr) {
sunaddr->sun_family = AF_UNIX;
sunaddr->sun_path[0] = 0;
*uaddr_len = sizeof(short);
} else {
struct unix_address *addr = u->addr;
*uaddr_len = addr->len;
memcpy(sunaddr, addr->name, *uaddr_len);
}
unix_state_unlock(sk);
sock_put(sk);
out:
return err;
}
static void unix_detach_fds(struct scm_cookie *scm, struct sk_buff *skb)
{
int i;
scm->fp = UNIXCB(skb).fp;
UNIXCB(skb).fp = NULL;
for (i = scm->fp->count-1; i >= 0; i--)
unix_notinflight(scm->fp->fp[i]);
}
static void unix_destruct_scm(struct sk_buff *skb)
{
struct scm_cookie scm;
memset(&scm, 0, sizeof(scm));
scm.pid = UNIXCB(skb).pid;
if (UNIXCB(skb).fp)
unix_detach_fds(&scm, skb);
scm_destroy(&scm);
sock_wfree(skb);
}
static int unix_attach_fds(struct scm_cookie *scm, struct sk_buff *skb)
{
int i;
unsigned char max_level = 0;
int unix_sock_count = 0;
for (i = scm->fp->count - 1; i >= 0; i--) {
struct sock *sk = unix_get_socket(scm->fp->fp[i]);
if (sk) {
unix_sock_count++;
max_level = max(max_level,
unix_sk(sk)->recursion_level);
}
}
if (unlikely(max_level > MAX_RECURSION_LEVEL))
return -ETOOMANYREFS;
UNIXCB(skb).fp = scm_fp_dup(scm->fp);
if (!UNIXCB(skb).fp)
return -ENOMEM;
if (unix_sock_count) {
for (i = scm->fp->count - 1; i >= 0; i--)
unix_inflight(scm->fp->fp[i]);
}
return max_level;
}
static int unix_scm_to_skb(struct scm_cookie *scm, struct sk_buff *skb, bool send_fds)
{
int err = 0;
UNIXCB(skb).pid = get_pid(scm->pid);
UNIXCB(skb).uid = scm->creds.uid;
UNIXCB(skb).gid = scm->creds.gid;
UNIXCB(skb).fp = NULL;
if (scm->fp && send_fds)
err = unix_attach_fds(scm, skb);
skb->destructor = unix_destruct_scm;
return err;
}
static void maybe_add_creds(struct sk_buff *skb, const struct socket *sock,
const struct sock *other)
{
if (UNIXCB(skb).pid)
return;
if (test_bit(SOCK_PASSCRED, &sock->flags) ||
!other->sk_socket ||
test_bit(SOCK_PASSCRED, &other->sk_socket->flags)) {
UNIXCB(skb).pid = get_pid(task_tgid(current));
current_uid_gid(&UNIXCB(skb).uid, &UNIXCB(skb).gid);
}
}
static int unix_dgram_sendmsg(struct kiocb *kiocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
struct sock_iocb *siocb = kiocb_to_siocb(kiocb);
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct unix_sock *u = unix_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_un *, sunaddr, msg->msg_name);
struct sock *other = NULL;
int namelen = 0;
int err;
unsigned int hash;
struct sk_buff *skb;
long timeo;
struct scm_cookie tmp_scm;
int max_level;
int data_len = 0;
if (NULL == siocb->scm)
siocb->scm = &tmp_scm;
wait_for_unix_gc();
err = scm_send(sock, msg, siocb->scm, false);
if (err < 0)
return err;
err = -EOPNOTSUPP;
if (msg->msg_flags&MSG_OOB)
goto out;
if (msg->msg_namelen) {
err = unix_mkname(sunaddr, msg->msg_namelen, &hash);
if (err < 0)
goto out;
namelen = err;
} else {
sunaddr = NULL;
err = -ENOTCONN;
other = unix_peer_get(sk);
if (!other)
goto out;
}
if (test_bit(SOCK_PASSCRED, &sock->flags) && !u->addr
&& (err = unix_autobind(sock)) != 0)
goto out;
err = -EMSGSIZE;
if (len > sk->sk_sndbuf - 32)
goto out;
if (len > SKB_MAX_ALLOC)
data_len = min_t(size_t,
len - SKB_MAX_ALLOC,
MAX_SKB_FRAGS * PAGE_SIZE);
skb = sock_alloc_send_pskb(sk, len - data_len, data_len,
msg->msg_flags & MSG_DONTWAIT, &err,
PAGE_ALLOC_COSTLY_ORDER);
if (skb == NULL)
goto out;
err = unix_scm_to_skb(siocb->scm, skb, true);
if (err < 0)
goto out_free;
max_level = err + 1;
unix_get_secdata(siocb->scm, skb);
skb_put(skb, len - data_len);
skb->data_len = data_len;
skb->len = len;
err = skb_copy_datagram_from_iovec(skb, 0, msg->msg_iov, 0, len);
if (err)
goto out_free;
timeo = sock_sndtimeo(sk, msg->msg_flags & MSG_DONTWAIT);
restart:
if (!other) {
err = -ECONNRESET;
if (sunaddr == NULL)
goto out_free;
other = unix_find_other(net, sunaddr, namelen, sk->sk_type,
hash, &err);
if (other == NULL)
goto out_free;
}
if (sk_filter(other, skb) < 0) {
err = len;
goto out_free;
}
unix_state_lock(other);
err = -EPERM;
if (!unix_may_send(sk, other))
goto out_unlock;
if (sock_flag(other, SOCK_DEAD)) {
unix_state_unlock(other);
sock_put(other);
err = 0;
unix_state_lock(sk);
if (unix_peer(sk) == other) {
unix_peer(sk) = NULL;
unix_state_unlock(sk);
unix_dgram_disconnected(sk, other);
sock_put(other);
err = -ECONNREFUSED;
} else {
unix_state_unlock(sk);
}
other = NULL;
if (err)
goto out_free;
goto restart;
}
err = -EPIPE;
if (other->sk_shutdown & RCV_SHUTDOWN)
goto out_unlock;
if (sk->sk_type != SOCK_SEQPACKET) {
err = security_unix_may_send(sk->sk_socket, other->sk_socket);
if (err)
goto out_unlock;
}
if (unix_peer(other) != sk && unix_recvq_full(other)) {
if (!timeo) {
err = -EAGAIN;
goto out_unlock;
}
timeo = unix_wait_for_peer(other, timeo);
err = sock_intr_errno(timeo);
if (signal_pending(current))
goto out_free;
goto restart;
}
if (sock_flag(other, SOCK_RCVTSTAMP))
__net_timestamp(skb);
maybe_add_creds(skb, sock, other);
skb_queue_tail(&other->sk_receive_queue, skb);
if (max_level > unix_sk(other)->recursion_level)
unix_sk(other)->recursion_level = max_level;
unix_state_unlock(other);
other->sk_data_ready(other);
sock_put(other);
scm_destroy(siocb->scm);
return len;
out_unlock:
unix_state_unlock(other);
out_free:
kfree_skb(skb);
out:
if (other)
sock_put(other);
scm_destroy(siocb->scm);
return err;
}
static int unix_stream_sendmsg(struct kiocb *kiocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
struct sock_iocb *siocb = kiocb_to_siocb(kiocb);
struct sock *sk = sock->sk;
struct sock *other = NULL;
int err, size;
struct sk_buff *skb;
int sent = 0;
struct scm_cookie tmp_scm;
bool fds_sent = false;
int max_level;
int data_len;
if (NULL == siocb->scm)
siocb->scm = &tmp_scm;
wait_for_unix_gc();
err = scm_send(sock, msg, siocb->scm, false);
if (err < 0)
return err;
err = -EOPNOTSUPP;
if (msg->msg_flags&MSG_OOB)
goto out_err;
if (msg->msg_namelen) {
err = sk->sk_state == TCP_ESTABLISHED ? -EISCONN : -EOPNOTSUPP;
goto out_err;
} else {
err = -ENOTCONN;
other = unix_peer(sk);
if (!other)
goto out_err;
}
if (sk->sk_shutdown & SEND_SHUTDOWN)
goto pipe_err;
while (sent < len) {
size = len - sent;
size = min_t(int, size, (sk->sk_sndbuf >> 1) - 64);
size = min_t(int, size, SKB_MAX_HEAD(0) + UNIX_SKB_FRAGS_SZ);
data_len = max_t(int, 0, size - SKB_MAX_HEAD(0));
skb = sock_alloc_send_pskb(sk, size - data_len, data_len,
msg->msg_flags & MSG_DONTWAIT, &err,
get_order(UNIX_SKB_FRAGS_SZ));
if (!skb)
goto out_err;
err = unix_scm_to_skb(siocb->scm, skb, !fds_sent);
if (err < 0) {
kfree_skb(skb);
goto out_err;
}
max_level = err + 1;
fds_sent = true;
skb_put(skb, size - data_len);
skb->data_len = data_len;
skb->len = size;
err = skb_copy_datagram_from_iovec(skb, 0, msg->msg_iov,
sent, size);
if (err) {
kfree_skb(skb);
goto out_err;
}
unix_state_lock(other);
if (sock_flag(other, SOCK_DEAD) ||
(other->sk_shutdown & RCV_SHUTDOWN))
goto pipe_err_free;
maybe_add_creds(skb, sock, other);
skb_queue_tail(&other->sk_receive_queue, skb);
if (max_level > unix_sk(other)->recursion_level)
unix_sk(other)->recursion_level = max_level;
unix_state_unlock(other);
other->sk_data_ready(other);
sent += size;
}
scm_destroy(siocb->scm);
siocb->scm = NULL;
return sent;
pipe_err_free:
unix_state_unlock(other);
kfree_skb(skb);
pipe_err:
if (sent == 0 && !(msg->msg_flags&MSG_NOSIGNAL))
send_sig(SIGPIPE, current, 0);
err = -EPIPE;
out_err:
scm_destroy(siocb->scm);
siocb->scm = NULL;
return sent ? : err;
}
static int unix_seqpacket_sendmsg(struct kiocb *kiocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
int err;
struct sock *sk = sock->sk;
err = sock_error(sk);
if (err)
return err;
if (sk->sk_state != TCP_ESTABLISHED)
return -ENOTCONN;
if (msg->msg_namelen)
msg->msg_namelen = 0;
return unix_dgram_sendmsg(kiocb, sock, msg, len);
}
static int unix_seqpacket_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t size,
int flags)
{
struct sock *sk = sock->sk;
if (sk->sk_state != TCP_ESTABLISHED)
return -ENOTCONN;
return unix_dgram_recvmsg(iocb, sock, msg, size, flags);
}
static void unix_copy_addr(struct msghdr *msg, struct sock *sk)
{
struct unix_sock *u = unix_sk(sk);
if (u->addr) {
msg->msg_namelen = u->addr->len;
memcpy(msg->msg_name, u->addr->name, u->addr->len);
}
}
static int unix_dgram_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t size,
int flags)
{
struct sock_iocb *siocb = kiocb_to_siocb(iocb);
struct scm_cookie tmp_scm;
struct sock *sk = sock->sk;
struct unix_sock *u = unix_sk(sk);
int noblock = flags & MSG_DONTWAIT;
struct sk_buff *skb;
int err;
int peeked, skip;
err = -EOPNOTSUPP;
if (flags&MSG_OOB)
goto out;
err = mutex_lock_interruptible(&u->readlock);
if (unlikely(err)) {
err = noblock ? -EAGAIN : -ERESTARTSYS;
goto out;
}
skip = sk_peek_offset(sk, flags);
skb = __skb_recv_datagram(sk, flags, &peeked, &skip, &err);
if (!skb) {
unix_state_lock(sk);
if (sk->sk_type == SOCK_SEQPACKET && err == -EAGAIN &&
(sk->sk_shutdown & RCV_SHUTDOWN))
err = 0;
unix_state_unlock(sk);
goto out_unlock;
}
wake_up_interruptible_sync_poll(&u->peer_wait,
POLLOUT | POLLWRNORM | POLLWRBAND);
if (msg->msg_name)
unix_copy_addr(msg, skb->sk);
if (size > skb->len - skip)
size = skb->len - skip;
else if (size < skb->len - skip)
msg->msg_flags |= MSG_TRUNC;
err = skb_copy_datagram_iovec(skb, skip, msg->msg_iov, size);
if (err)
goto out_free;
if (sock_flag(sk, SOCK_RCVTSTAMP))
__sock_recv_timestamp(msg, sk, skb);
if (!siocb->scm) {
siocb->scm = &tmp_scm;
memset(&tmp_scm, 0, sizeof(tmp_scm));
}
scm_set_cred(siocb->scm, UNIXCB(skb).pid, UNIXCB(skb).uid, UNIXCB(skb).gid);
unix_set_secdata(siocb->scm, skb);
if (!(flags & MSG_PEEK)) {
if (UNIXCB(skb).fp)
unix_detach_fds(siocb->scm, skb);
sk_peek_offset_bwd(sk, skb->len);
} else {
sk_peek_offset_fwd(sk, size);
if (UNIXCB(skb).fp)
siocb->scm->fp = scm_fp_dup(UNIXCB(skb).fp);
}
err = (flags & MSG_TRUNC) ? skb->len - skip : size;
scm_recv(sock, msg, siocb->scm, flags);
out_free:
skb_free_datagram(sk, skb);
out_unlock:
mutex_unlock(&u->readlock);
out:
return err;
}
static long unix_stream_data_wait(struct sock *sk, long timeo,
struct sk_buff *last)
{
DEFINE_WAIT(wait);
unix_state_lock(sk);
for (;;) {
prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
if (skb_peek_tail(&sk->sk_receive_queue) != last ||
sk->sk_err ||
(sk->sk_shutdown & RCV_SHUTDOWN) ||
signal_pending(current) ||
!timeo)
break;
set_bit(SOCK_ASYNC_WAITDATA, &sk->sk_socket->flags);
unix_state_unlock(sk);
timeo = freezable_schedule_timeout(timeo);
unix_state_lock(sk);
clear_bit(SOCK_ASYNC_WAITDATA, &sk->sk_socket->flags);
}
finish_wait(sk_sleep(sk), &wait);
unix_state_unlock(sk);
return timeo;
}
static unsigned int unix_skb_len(const struct sk_buff *skb)
{
return skb->len - UNIXCB(skb).consumed;
}
static int unix_stream_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t size,
int flags)
{
struct sock_iocb *siocb = kiocb_to_siocb(iocb);
struct scm_cookie tmp_scm;
struct sock *sk = sock->sk;
struct unix_sock *u = unix_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_un *, sunaddr, msg->msg_name);
int copied = 0;
int noblock = flags & MSG_DONTWAIT;
int check_creds = 0;
int target;
int err = 0;
long timeo;
int skip;
err = -EINVAL;
if (sk->sk_state != TCP_ESTABLISHED)
goto out;
err = -EOPNOTSUPP;
if (flags&MSG_OOB)
goto out;
target = sock_rcvlowat(sk, flags&MSG_WAITALL, size);
timeo = sock_rcvtimeo(sk, noblock);
if (!siocb->scm) {
siocb->scm = &tmp_scm;
memset(&tmp_scm, 0, sizeof(tmp_scm));
}
err = mutex_lock_interruptible(&u->readlock);
if (unlikely(err)) {
err = noblock ? -EAGAIN : -ERESTARTSYS;
goto out;
}
do {
int chunk;
struct sk_buff *skb, *last;
unix_state_lock(sk);
last = skb = skb_peek(&sk->sk_receive_queue);
again:
if (skb == NULL) {
unix_sk(sk)->recursion_level = 0;
if (copied >= target)
goto unlock;
err = sock_error(sk);
if (err)
goto unlock;
if (sk->sk_shutdown & RCV_SHUTDOWN)
goto unlock;
unix_state_unlock(sk);
err = -EAGAIN;
if (!timeo)
break;
mutex_unlock(&u->readlock);
timeo = unix_stream_data_wait(sk, timeo, last);
if (signal_pending(current)
|| mutex_lock_interruptible(&u->readlock)) {
err = sock_intr_errno(timeo);
goto out;
}
continue;
unlock:
unix_state_unlock(sk);
break;
}
skip = sk_peek_offset(sk, flags);
while (skip >= unix_skb_len(skb)) {
skip -= unix_skb_len(skb);
last = skb;
skb = skb_peek_next(skb, &sk->sk_receive_queue);
if (!skb)
goto again;
}
unix_state_unlock(sk);
if (check_creds) {
if ((UNIXCB(skb).pid != siocb->scm->pid) ||
!uid_eq(UNIXCB(skb).uid, siocb->scm->creds.uid) ||
!gid_eq(UNIXCB(skb).gid, siocb->scm->creds.gid))
break;
} else if (test_bit(SOCK_PASSCRED, &sock->flags)) {
scm_set_cred(siocb->scm, UNIXCB(skb).pid, UNIXCB(skb).uid, UNIXCB(skb).gid);
check_creds = 1;
}
if (sunaddr) {
unix_copy_addr(msg, skb->sk);
sunaddr = NULL;
}
chunk = min_t(unsigned int, unix_skb_len(skb) - skip, size);
if (skb_copy_datagram_iovec(skb, UNIXCB(skb).consumed + skip,
msg->msg_iov, chunk)) {
if (copied == 0)
copied = -EFAULT;
break;
}
copied += chunk;
size -= chunk;
if (!(flags & MSG_PEEK)) {
UNIXCB(skb).consumed += chunk;
sk_peek_offset_bwd(sk, chunk);
if (UNIXCB(skb).fp)
unix_detach_fds(siocb->scm, skb);
if (unix_skb_len(skb))
break;
skb_unlink(skb, &sk->sk_receive_queue);
consume_skb(skb);
if (siocb->scm->fp)
break;
} else {
if (UNIXCB(skb).fp)
siocb->scm->fp = scm_fp_dup(UNIXCB(skb).fp);
sk_peek_offset_fwd(sk, chunk);
break;
}
} while (size);
mutex_unlock(&u->readlock);
scm_recv(sock, msg, siocb->scm, flags);
out:
return copied ? : err;
}
static int unix_shutdown(struct socket *sock, int mode)
{
struct sock *sk = sock->sk;
struct sock *other;
if (mode < SHUT_RD || mode > SHUT_RDWR)
return -EINVAL;
++mode;
unix_state_lock(sk);
sk->sk_shutdown |= mode;
other = unix_peer(sk);
if (other)
sock_hold(other);
unix_state_unlock(sk);
sk->sk_state_change(sk);
if (other &&
(sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_SEQPACKET)) {
int peer_mode = 0;
if (mode&RCV_SHUTDOWN)
peer_mode |= SEND_SHUTDOWN;
if (mode&SEND_SHUTDOWN)
peer_mode |= RCV_SHUTDOWN;
unix_state_lock(other);
other->sk_shutdown |= peer_mode;
unix_state_unlock(other);
other->sk_state_change(other);
if (peer_mode == SHUTDOWN_MASK)
sk_wake_async(other, SOCK_WAKE_WAITD, POLL_HUP);
else if (peer_mode & RCV_SHUTDOWN)
sk_wake_async(other, SOCK_WAKE_WAITD, POLL_IN);
}
if (other)
sock_put(other);
return 0;
}
long unix_inq_len(struct sock *sk)
{
struct sk_buff *skb;
long amount = 0;
if (sk->sk_state == TCP_LISTEN)
return -EINVAL;
spin_lock(&sk->sk_receive_queue.lock);
if (sk->sk_type == SOCK_STREAM ||
sk->sk_type == SOCK_SEQPACKET) {
skb_queue_walk(&sk->sk_receive_queue, skb)
amount += unix_skb_len(skb);
} else {
skb = skb_peek(&sk->sk_receive_queue);
if (skb)
amount = skb->len;
}
spin_unlock(&sk->sk_receive_queue.lock);
return amount;
}
long unix_outq_len(struct sock *sk)
{
return sk_wmem_alloc_get(sk);
}
static int unix_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct sock *sk = sock->sk;
long amount = 0;
int err;
switch (cmd) {
case SIOCOUTQ:
amount = unix_outq_len(sk);
err = put_user(amount, (int __user *)arg);
break;
case SIOCINQ:
amount = unix_inq_len(sk);
if (amount < 0)
err = amount;
else
err = put_user(amount, (int __user *)arg);
break;
default:
err = -ENOIOCTLCMD;
break;
}
return err;
}
static unsigned int unix_poll(struct file *file, struct socket *sock, poll_table *wait)
{
struct sock *sk = sock->sk;
unsigned int mask;
sock_poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (sk->sk_err)
mask |= POLLERR;
if (sk->sk_shutdown == SHUTDOWN_MASK)
mask |= POLLHUP;
if (sk->sk_shutdown & RCV_SHUTDOWN)
mask |= POLLRDHUP | POLLIN | POLLRDNORM;
if (!skb_queue_empty(&sk->sk_receive_queue))
mask |= POLLIN | POLLRDNORM;
if ((sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_SEQPACKET) &&
sk->sk_state == TCP_CLOSE)
mask |= POLLHUP;
if (unix_writable(sk))
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
return mask;
}
static unsigned int unix_dgram_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
struct sock *sk = sock->sk, *other;
unsigned int mask, writable;
sock_poll_wait(file, sk_sleep(sk), wait);
mask = 0;
if (sk->sk_err || !skb_queue_empty(&sk->sk_error_queue))
mask |= POLLERR |
(sock_flag(sk, SOCK_SELECT_ERR_QUEUE) ? POLLPRI : 0);
if (sk->sk_shutdown & RCV_SHUTDOWN)
mask |= POLLRDHUP | POLLIN | POLLRDNORM;
if (sk->sk_shutdown == SHUTDOWN_MASK)
mask |= POLLHUP;
if (!skb_queue_empty(&sk->sk_receive_queue))
mask |= POLLIN | POLLRDNORM;
if (sk->sk_type == SOCK_SEQPACKET) {
if (sk->sk_state == TCP_CLOSE)
mask |= POLLHUP;
if (sk->sk_state == TCP_SYN_SENT)
return mask;
}
if (!(poll_requested_events(wait) & (POLLWRBAND|POLLWRNORM|POLLOUT)))
return mask;
writable = unix_writable(sk);
other = unix_peer_get(sk);
if (other) {
if (unix_peer(other) != sk) {
sock_poll_wait(file, &unix_sk(other)->peer_wait, wait);
if (unix_recvq_full(other))
writable = 0;
}
sock_put(other);
}
if (writable)
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
else
set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags);
return mask;
}
static struct sock *unix_from_bucket(struct seq_file *seq, loff_t *pos)
{
unsigned long offset = get_offset(*pos);
unsigned long bucket = get_bucket(*pos);
struct sock *sk;
unsigned long count = 0;
for (sk = sk_head(&unix_socket_table[bucket]); sk; sk = sk_next(sk)) {
if (sock_net(sk) != seq_file_net(seq))
continue;
if (++count == offset)
break;
}
return sk;
}
static struct sock *unix_next_socket(struct seq_file *seq,
struct sock *sk,
loff_t *pos)
{
unsigned long bucket;
while (sk > (struct sock *)SEQ_START_TOKEN) {
sk = sk_next(sk);
if (!sk)
goto next_bucket;
if (sock_net(sk) == seq_file_net(seq))
return sk;
}
do {
sk = unix_from_bucket(seq, pos);
if (sk)
return sk;
next_bucket:
bucket = get_bucket(*pos) + 1;
*pos = set_bucket_offset(bucket, 1);
} while (bucket < ARRAY_SIZE(unix_socket_table));
return NULL;
}
static void *unix_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(unix_table_lock)
{
spin_lock(&unix_table_lock);
if (!*pos)
return SEQ_START_TOKEN;
if (get_bucket(*pos) >= ARRAY_SIZE(unix_socket_table))
return NULL;
return unix_next_socket(seq, NULL, pos);
}
static void *unix_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return unix_next_socket(seq, v, pos);
}
static void unix_seq_stop(struct seq_file *seq, void *v)
__releases(unix_table_lock)
{
spin_unlock(&unix_table_lock);
}
static int unix_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq, "Num RefCount Protocol Flags Type St "
"Inode Path\n");
else {
struct sock *s = v;
struct unix_sock *u = unix_sk(s);
unix_state_lock(s);
seq_printf(seq, "%pK: %08X %08X %08X %04X %02X %5lu",
s,
atomic_read(&s->sk_refcnt),
0,
s->sk_state == TCP_LISTEN ? __SO_ACCEPTCON : 0,
s->sk_type,
s->sk_socket ?
(s->sk_state == TCP_ESTABLISHED ? SS_CONNECTED : SS_UNCONNECTED) :
(s->sk_state == TCP_ESTABLISHED ? SS_CONNECTING : SS_DISCONNECTING),
sock_i_ino(s));
if (u->addr) {
int i, len;
seq_putc(seq, ' ');
i = 0;
len = u->addr->len - sizeof(short);
if (!UNIX_ABSTRACT(s))
len--;
else {
seq_putc(seq, '@');
i++;
}
for ( ; i < len; i++)
seq_putc(seq, u->addr->name->sun_path[i]);
}
unix_state_unlock(s);
seq_putc(seq, '\n');
}
return 0;
}
static int unix_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &unix_seq_ops,
sizeof(struct seq_net_private));
}
static int __net_init unix_net_init(struct net *net)
{
int error = -ENOMEM;
net->unx.sysctl_max_dgram_qlen = 10;
if (unix_sysctl_register(net))
goto out;
#ifdef CONFIG_PROC_FS
if (!proc_create("unix", 0, net->proc_net, &unix_seq_fops)) {
unix_sysctl_unregister(net);
goto out;
}
#endif
error = 0;
out:
return error;
}
static void __net_exit unix_net_exit(struct net *net)
{
unix_sysctl_unregister(net);
remove_proc_entry("unix", net->proc_net);
}
static int __init af_unix_init(void)
{
int rc = -1;
BUILD_BUG_ON(sizeof(struct unix_skb_parms) > FIELD_SIZEOF(struct sk_buff, cb));
rc = proto_register(&unix_proto, 1);
if (rc != 0) {
pr_crit("%s: Cannot create unix_sock SLAB cache!\n", __func__);
goto out;
}
sock_register(&unix_family_ops);
register_pernet_subsys(&unix_net_ops);
out:
return rc;
}
static void __exit af_unix_exit(void)
{
sock_unregister(PF_UNIX);
proto_unregister(&unix_proto);
unregister_pernet_subsys(&unix_net_ops);
}
