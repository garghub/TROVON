static void sco_sock_timeout(unsigned long arg)
{
struct sock *sk = (struct sock *) arg;
BT_DBG("sock %p state %d", sk, sk->sk_state);
bh_lock_sock(sk);
sk->sk_err = ETIMEDOUT;
sk->sk_state_change(sk);
bh_unlock_sock(sk);
sco_sock_kill(sk);
sock_put(sk);
}
static void sco_sock_set_timer(struct sock *sk, long timeout)
{
BT_DBG("sock %p state %d timeout %ld", sk, sk->sk_state, timeout);
sk_reset_timer(sk, &sk->sk_timer, jiffies + timeout);
}
static void sco_sock_clear_timer(struct sock *sk)
{
BT_DBG("sock %p state %d", sk, sk->sk_state);
sk_stop_timer(sk, &sk->sk_timer);
}
static struct sco_conn *sco_conn_add(struct hci_conn *hcon, __u8 status)
{
struct hci_dev *hdev = hcon->hdev;
struct sco_conn *conn = hcon->sco_data;
if (conn || status)
return conn;
conn = kzalloc(sizeof(struct sco_conn), GFP_ATOMIC);
if (!conn)
return NULL;
spin_lock_init(&conn->lock);
hcon->sco_data = conn;
conn->hcon = hcon;
conn->src = &hdev->bdaddr;
conn->dst = &hcon->dst;
if (hdev->sco_mtu > 0)
conn->mtu = hdev->sco_mtu;
else
conn->mtu = 60;
BT_DBG("hcon %p conn %p", hcon, conn);
return conn;
}
static inline struct sock *sco_chan_get(struct sco_conn *conn)
{
struct sock *sk = NULL;
sco_conn_lock(conn);
sk = conn->sk;
sco_conn_unlock(conn);
return sk;
}
static int sco_conn_del(struct hci_conn *hcon, int err)
{
struct sco_conn *conn = hcon->sco_data;
struct sock *sk;
if (!conn)
return 0;
BT_DBG("hcon %p conn %p, err %d", hcon, conn, err);
sk = sco_chan_get(conn);
if (sk) {
bh_lock_sock(sk);
sco_sock_clear_timer(sk);
sco_chan_del(sk, err);
bh_unlock_sock(sk);
sco_sock_kill(sk);
}
hcon->sco_data = NULL;
kfree(conn);
return 0;
}
static inline int sco_chan_add(struct sco_conn *conn, struct sock *sk, struct sock *parent)
{
int err = 0;
sco_conn_lock(conn);
if (conn->sk)
err = -EBUSY;
else
__sco_chan_add(conn, sk, parent);
sco_conn_unlock(conn);
return err;
}
static int sco_connect(struct sock *sk)
{
bdaddr_t *src = &bt_sk(sk)->src;
bdaddr_t *dst = &bt_sk(sk)->dst;
struct sco_conn *conn;
struct hci_conn *hcon;
struct hci_dev *hdev;
int err, type;
BT_DBG("%s -> %s", batostr(src), batostr(dst));
hdev = hci_get_route(dst, src);
if (!hdev)
return -EHOSTUNREACH;
hci_dev_lock(hdev);
if (lmp_esco_capable(hdev) && !disable_esco)
type = ESCO_LINK;
else
type = SCO_LINK;
hcon = hci_connect(hdev, type, dst, BT_SECURITY_LOW, HCI_AT_NO_BONDING);
if (IS_ERR(hcon)) {
err = PTR_ERR(hcon);
goto done;
}
conn = sco_conn_add(hcon, 0);
if (!conn) {
hci_conn_put(hcon);
err = -ENOMEM;
goto done;
}
bacpy(src, conn->src);
err = sco_chan_add(conn, sk, NULL);
if (err)
goto done;
if (hcon->state == BT_CONNECTED) {
sco_sock_clear_timer(sk);
sk->sk_state = BT_CONNECTED;
} else {
sk->sk_state = BT_CONNECT;
sco_sock_set_timer(sk, sk->sk_sndtimeo);
}
done:
hci_dev_unlock(hdev);
hci_dev_put(hdev);
return err;
}
static inline int sco_send_frame(struct sock *sk, struct msghdr *msg, int len)
{
struct sco_conn *conn = sco_pi(sk)->conn;
struct sk_buff *skb;
int err, count;
if (len > conn->mtu)
return -EINVAL;
BT_DBG("sk %p len %d", sk, len);
count = min_t(unsigned int, conn->mtu, len);
skb = bt_skb_send_alloc(sk, count,
msg->msg_flags & MSG_DONTWAIT, &err);
if (!skb)
return err;
if (memcpy_fromiovec(skb_put(skb, count), msg->msg_iov, count)) {
kfree_skb(skb);
return -EFAULT;
}
hci_send_sco(conn->hcon, skb);
return count;
}
static inline void sco_recv_frame(struct sco_conn *conn, struct sk_buff *skb)
{
struct sock *sk = sco_chan_get(conn);
if (!sk)
goto drop;
BT_DBG("sk %p len %d", sk, skb->len);
if (sk->sk_state != BT_CONNECTED)
goto drop;
if (!sock_queue_rcv_skb(sk, skb))
return;
drop:
kfree_skb(skb);
}
static struct sock *__sco_get_sock_by_addr(bdaddr_t *ba)
{
struct sock *sk;
struct hlist_node *node;
sk_for_each(sk, node, &sco_sk_list.head)
if (!bacmp(&bt_sk(sk)->src, ba))
goto found;
sk = NULL;
found:
return sk;
}
static struct sock *sco_get_sock_listen(bdaddr_t *src)
{
struct sock *sk = NULL, *sk1 = NULL;
struct hlist_node *node;
read_lock(&sco_sk_list.lock);
sk_for_each(sk, node, &sco_sk_list.head) {
if (sk->sk_state != BT_LISTEN)
continue;
if (!bacmp(&bt_sk(sk)->src, src))
break;
if (!bacmp(&bt_sk(sk)->src, BDADDR_ANY))
sk1 = sk;
}
read_unlock(&sco_sk_list.lock);
return node ? sk : sk1;
}
static void sco_sock_destruct(struct sock *sk)
{
BT_DBG("sk %p", sk);
skb_queue_purge(&sk->sk_receive_queue);
skb_queue_purge(&sk->sk_write_queue);
}
static void sco_sock_cleanup_listen(struct sock *parent)
{
struct sock *sk;
BT_DBG("parent %p", parent);
while ((sk = bt_accept_dequeue(parent, NULL))) {
sco_sock_close(sk);
sco_sock_kill(sk);
}
parent->sk_state = BT_CLOSED;
sock_set_flag(parent, SOCK_ZAPPED);
}
static void sco_sock_kill(struct sock *sk)
{
if (!sock_flag(sk, SOCK_ZAPPED) || sk->sk_socket)
return;
BT_DBG("sk %p state %d", sk, sk->sk_state);
bt_sock_unlink(&sco_sk_list, sk);
sock_set_flag(sk, SOCK_DEAD);
sock_put(sk);
}
static void __sco_sock_close(struct sock *sk)
{
BT_DBG("sk %p state %d socket %p", sk, sk->sk_state, sk->sk_socket);
switch (sk->sk_state) {
case BT_LISTEN:
sco_sock_cleanup_listen(sk);
break;
case BT_CONNECTED:
case BT_CONFIG:
if (sco_pi(sk)->conn) {
sk->sk_state = BT_DISCONN;
sco_sock_set_timer(sk, SCO_DISCONN_TIMEOUT);
hci_conn_put(sco_pi(sk)->conn->hcon);
sco_pi(sk)->conn->hcon = NULL;
} else
sco_chan_del(sk, ECONNRESET);
break;
case BT_CONNECT:
case BT_DISCONN:
sco_chan_del(sk, ECONNRESET);
break;
default:
sock_set_flag(sk, SOCK_ZAPPED);
break;
}
}
static void sco_sock_close(struct sock *sk)
{
sco_sock_clear_timer(sk);
lock_sock(sk);
__sco_sock_close(sk);
release_sock(sk);
sco_sock_kill(sk);
}
static void sco_sock_init(struct sock *sk, struct sock *parent)
{
BT_DBG("sk %p", sk);
if (parent) {
sk->sk_type = parent->sk_type;
security_sk_clone(parent, sk);
}
}
static struct sock *sco_sock_alloc(struct net *net, struct socket *sock, int proto, gfp_t prio)
{
struct sock *sk;
sk = sk_alloc(net, PF_BLUETOOTH, prio, &sco_proto);
if (!sk)
return NULL;
sock_init_data(sock, sk);
INIT_LIST_HEAD(&bt_sk(sk)->accept_q);
sk->sk_destruct = sco_sock_destruct;
sk->sk_sndtimeo = SCO_CONN_TIMEOUT;
sock_reset_flag(sk, SOCK_ZAPPED);
sk->sk_protocol = proto;
sk->sk_state = BT_OPEN;
setup_timer(&sk->sk_timer, sco_sock_timeout, (unsigned long)sk);
bt_sock_link(&sco_sk_list, sk);
return sk;
}
static int sco_sock_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
BT_DBG("sock %p", sock);
sock->state = SS_UNCONNECTED;
if (sock->type != SOCK_SEQPACKET)
return -ESOCKTNOSUPPORT;
sock->ops = &sco_sock_ops;
sk = sco_sock_alloc(net, sock, protocol, GFP_ATOMIC);
if (!sk)
return -ENOMEM;
sco_sock_init(sk, NULL);
return 0;
}
static int sco_sock_bind(struct socket *sock, struct sockaddr *addr, int addr_len)
{
struct sockaddr_sco *sa = (struct sockaddr_sco *) addr;
struct sock *sk = sock->sk;
bdaddr_t *src = &sa->sco_bdaddr;
int err = 0;
BT_DBG("sk %p %s", sk, batostr(&sa->sco_bdaddr));
if (!addr || addr->sa_family != AF_BLUETOOTH)
return -EINVAL;
lock_sock(sk);
if (sk->sk_state != BT_OPEN) {
err = -EBADFD;
goto done;
}
write_lock(&sco_sk_list.lock);
if (bacmp(src, BDADDR_ANY) && __sco_get_sock_by_addr(src)) {
err = -EADDRINUSE;
} else {
bacpy(&bt_sk(sk)->src, &sa->sco_bdaddr);
sk->sk_state = BT_BOUND;
}
write_unlock(&sco_sk_list.lock);
done:
release_sock(sk);
return err;
}
static int sco_sock_connect(struct socket *sock, struct sockaddr *addr, int alen, int flags)
{
struct sockaddr_sco *sa = (struct sockaddr_sco *) addr;
struct sock *sk = sock->sk;
int err = 0;
BT_DBG("sk %p", sk);
if (alen < sizeof(struct sockaddr_sco) ||
addr->sa_family != AF_BLUETOOTH)
return -EINVAL;
if (sk->sk_state != BT_OPEN && sk->sk_state != BT_BOUND)
return -EBADFD;
if (sk->sk_type != SOCK_SEQPACKET)
return -EINVAL;
lock_sock(sk);
bacpy(&bt_sk(sk)->dst, &sa->sco_bdaddr);
err = sco_connect(sk);
if (err)
goto done;
err = bt_sock_wait_state(sk, BT_CONNECTED,
sock_sndtimeo(sk, flags & O_NONBLOCK));
done:
release_sock(sk);
return err;
}
static int sco_sock_listen(struct socket *sock, int backlog)
{
struct sock *sk = sock->sk;
int err = 0;
BT_DBG("sk %p backlog %d", sk, backlog);
lock_sock(sk);
if (sk->sk_state != BT_BOUND || sock->type != SOCK_SEQPACKET) {
err = -EBADFD;
goto done;
}
sk->sk_max_ack_backlog = backlog;
sk->sk_ack_backlog = 0;
sk->sk_state = BT_LISTEN;
done:
release_sock(sk);
return err;
}
static int sco_sock_accept(struct socket *sock, struct socket *newsock, int flags)
{
DECLARE_WAITQUEUE(wait, current);
struct sock *sk = sock->sk, *ch;
long timeo;
int err = 0;
lock_sock(sk);
timeo = sock_rcvtimeo(sk, flags & O_NONBLOCK);
BT_DBG("sk %p timeo %ld", sk, timeo);
add_wait_queue_exclusive(sk_sleep(sk), &wait);
while (1) {
set_current_state(TASK_INTERRUPTIBLE);
if (sk->sk_state != BT_LISTEN) {
err = -EBADFD;
break;
}
ch = bt_accept_dequeue(sk, newsock);
if (ch)
break;
if (!timeo) {
err = -EAGAIN;
break;
}
if (signal_pending(current)) {
err = sock_intr_errno(timeo);
break;
}
release_sock(sk);
timeo = schedule_timeout(timeo);
lock_sock(sk);
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(sk_sleep(sk), &wait);
if (err)
goto done;
newsock->state = SS_CONNECTED;
BT_DBG("new socket %p", ch);
done:
release_sock(sk);
return err;
}
static int sco_sock_getname(struct socket *sock, struct sockaddr *addr, int *len, int peer)
{
struct sockaddr_sco *sa = (struct sockaddr_sco *) addr;
struct sock *sk = sock->sk;
BT_DBG("sock %p, sk %p", sock, sk);
addr->sa_family = AF_BLUETOOTH;
*len = sizeof(struct sockaddr_sco);
if (peer)
bacpy(&sa->sco_bdaddr, &bt_sk(sk)->dst);
else
bacpy(&sa->sco_bdaddr, &bt_sk(sk)->src);
return 0;
}
static int sco_sock_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
struct sock *sk = sock->sk;
int err;
BT_DBG("sock %p, sk %p", sock, sk);
err = sock_error(sk);
if (err)
return err;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
lock_sock(sk);
if (sk->sk_state == BT_CONNECTED)
err = sco_send_frame(sk, msg, len);
else
err = -ENOTCONN;
release_sock(sk);
return err;
}
static int sco_sock_setsockopt(struct socket *sock, int level, int optname, char __user *optval, unsigned int optlen)
{
struct sock *sk = sock->sk;
int err = 0;
BT_DBG("sk %p", sk);
lock_sock(sk);
switch (optname) {
default:
err = -ENOPROTOOPT;
break;
}
release_sock(sk);
return err;
}
static int sco_sock_getsockopt_old(struct socket *sock, int optname, char __user *optval, int __user *optlen)
{
struct sock *sk = sock->sk;
struct sco_options opts;
struct sco_conninfo cinfo;
int len, err = 0;
BT_DBG("sk %p", sk);
if (get_user(len, optlen))
return -EFAULT;
lock_sock(sk);
switch (optname) {
case SCO_OPTIONS:
if (sk->sk_state != BT_CONNECTED) {
err = -ENOTCONN;
break;
}
opts.mtu = sco_pi(sk)->conn->mtu;
BT_DBG("mtu %d", opts.mtu);
len = min_t(unsigned int, len, sizeof(opts));
if (copy_to_user(optval, (char *)&opts, len))
err = -EFAULT;
break;
case SCO_CONNINFO:
if (sk->sk_state != BT_CONNECTED) {
err = -ENOTCONN;
break;
}
memset(&cinfo, 0, sizeof(cinfo));
cinfo.hci_handle = sco_pi(sk)->conn->hcon->handle;
memcpy(cinfo.dev_class, sco_pi(sk)->conn->hcon->dev_class, 3);
len = min_t(unsigned int, len, sizeof(cinfo));
if (copy_to_user(optval, (char *)&cinfo, len))
err = -EFAULT;
break;
default:
err = -ENOPROTOOPT;
break;
}
release_sock(sk);
return err;
}
static int sco_sock_getsockopt(struct socket *sock, int level, int optname, char __user *optval, int __user *optlen)
{
struct sock *sk = sock->sk;
int len, err = 0;
BT_DBG("sk %p", sk);
if (level == SOL_SCO)
return sco_sock_getsockopt_old(sock, optname, optval, optlen);
if (get_user(len, optlen))
return -EFAULT;
lock_sock(sk);
switch (optname) {
default:
err = -ENOPROTOOPT;
break;
}
release_sock(sk);
return err;
}
static int sco_sock_shutdown(struct socket *sock, int how)
{
struct sock *sk = sock->sk;
int err = 0;
BT_DBG("sock %p, sk %p", sock, sk);
if (!sk)
return 0;
lock_sock(sk);
if (!sk->sk_shutdown) {
sk->sk_shutdown = SHUTDOWN_MASK;
sco_sock_clear_timer(sk);
__sco_sock_close(sk);
if (sock_flag(sk, SOCK_LINGER) && sk->sk_lingertime)
err = bt_sock_wait_state(sk, BT_CLOSED,
sk->sk_lingertime);
}
release_sock(sk);
return err;
}
static int sco_sock_release(struct socket *sock)
{
struct sock *sk = sock->sk;
int err = 0;
BT_DBG("sock %p, sk %p", sock, sk);
if (!sk)
return 0;
sco_sock_close(sk);
if (sock_flag(sk, SOCK_LINGER) && sk->sk_lingertime) {
lock_sock(sk);
err = bt_sock_wait_state(sk, BT_CLOSED, sk->sk_lingertime);
release_sock(sk);
}
sock_orphan(sk);
sco_sock_kill(sk);
return err;
}
static void __sco_chan_add(struct sco_conn *conn, struct sock *sk, struct sock *parent)
{
BT_DBG("conn %p", conn);
sco_pi(sk)->conn = conn;
conn->sk = sk;
if (parent)
bt_accept_enqueue(parent, sk);
}
static void sco_chan_del(struct sock *sk, int err)
{
struct sco_conn *conn;
conn = sco_pi(sk)->conn;
BT_DBG("sk %p, conn %p, err %d", sk, conn, err);
if (conn) {
sco_conn_lock(conn);
conn->sk = NULL;
sco_pi(sk)->conn = NULL;
sco_conn_unlock(conn);
if (conn->hcon)
hci_conn_put(conn->hcon);
}
sk->sk_state = BT_CLOSED;
sk->sk_err = err;
sk->sk_state_change(sk);
sock_set_flag(sk, SOCK_ZAPPED);
}
static void sco_conn_ready(struct sco_conn *conn)
{
struct sock *parent;
struct sock *sk = conn->sk;
BT_DBG("conn %p", conn);
sco_conn_lock(conn);
if (sk) {
sco_sock_clear_timer(sk);
bh_lock_sock(sk);
sk->sk_state = BT_CONNECTED;
sk->sk_state_change(sk);
bh_unlock_sock(sk);
} else {
parent = sco_get_sock_listen(conn->src);
if (!parent)
goto done;
bh_lock_sock(parent);
sk = sco_sock_alloc(sock_net(parent), NULL,
BTPROTO_SCO, GFP_ATOMIC);
if (!sk) {
bh_unlock_sock(parent);
goto done;
}
sco_sock_init(sk, parent);
bacpy(&bt_sk(sk)->src, conn->src);
bacpy(&bt_sk(sk)->dst, conn->dst);
hci_conn_hold(conn->hcon);
__sco_chan_add(conn, sk, parent);
sk->sk_state = BT_CONNECTED;
parent->sk_data_ready(parent, 1);
bh_unlock_sock(parent);
}
done:
sco_conn_unlock(conn);
}
int sco_connect_ind(struct hci_dev *hdev, bdaddr_t *bdaddr)
{
register struct sock *sk;
struct hlist_node *node;
int lm = 0;
BT_DBG("hdev %s, bdaddr %s", hdev->name, batostr(bdaddr));
read_lock(&sco_sk_list.lock);
sk_for_each(sk, node, &sco_sk_list.head) {
if (sk->sk_state != BT_LISTEN)
continue;
if (!bacmp(&bt_sk(sk)->src, &hdev->bdaddr) ||
!bacmp(&bt_sk(sk)->src, BDADDR_ANY)) {
lm |= HCI_LM_ACCEPT;
break;
}
}
read_unlock(&sco_sk_list.lock);
return lm;
}
int sco_connect_cfm(struct hci_conn *hcon, __u8 status)
{
BT_DBG("hcon %p bdaddr %s status %d", hcon, batostr(&hcon->dst), status);
if (!status) {
struct sco_conn *conn;
conn = sco_conn_add(hcon, status);
if (conn)
sco_conn_ready(conn);
} else
sco_conn_del(hcon, bt_to_errno(status));
return 0;
}
int sco_disconn_cfm(struct hci_conn *hcon, __u8 reason)
{
BT_DBG("hcon %p reason %d", hcon, reason);
sco_conn_del(hcon, bt_to_errno(reason));
return 0;
}
int sco_recv_scodata(struct hci_conn *hcon, struct sk_buff *skb)
{
struct sco_conn *conn = hcon->sco_data;
if (!conn)
goto drop;
BT_DBG("conn %p len %d", conn, skb->len);
if (skb->len) {
sco_recv_frame(conn, skb);
return 0;
}
drop:
kfree_skb(skb);
return 0;
}
static int sco_debugfs_show(struct seq_file *f, void *p)
{
struct sock *sk;
struct hlist_node *node;
read_lock(&sco_sk_list.lock);
sk_for_each(sk, node, &sco_sk_list.head) {
seq_printf(f, "%s %s %d\n", batostr(&bt_sk(sk)->src),
batostr(&bt_sk(sk)->dst), sk->sk_state);
}
read_unlock(&sco_sk_list.lock);
return 0;
}
static int sco_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, sco_debugfs_show, inode->i_private);
}
int __init sco_init(void)
{
int err;
err = proto_register(&sco_proto, 0);
if (err < 0)
return err;
err = bt_sock_register(BTPROTO_SCO, &sco_sock_family_ops);
if (err < 0) {
BT_ERR("SCO socket registration failed");
goto error;
}
if (bt_debugfs) {
sco_debugfs = debugfs_create_file("sco", 0444,
bt_debugfs, NULL, &sco_debugfs_fops);
if (!sco_debugfs)
BT_ERR("Failed to create SCO debug file");
}
BT_INFO("SCO socket layer initialized");
return 0;
error:
proto_unregister(&sco_proto);
return err;
}
void __exit sco_exit(void)
{
debugfs_remove(sco_debugfs);
if (bt_sock_unregister(BTPROTO_SCO) < 0)
BT_ERR("SCO socket unregistration failed");
proto_unregister(&sco_proto);
}
