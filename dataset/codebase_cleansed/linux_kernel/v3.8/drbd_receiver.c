static struct page *page_chain_del(struct page **head, int n)
{
struct page *page;
struct page *tmp;
BUG_ON(!n);
BUG_ON(!head);
page = *head;
if (!page)
return NULL;
while (page) {
tmp = page_chain_next(page);
if (--n == 0)
break;
if (tmp == NULL)
return NULL;
page = tmp;
}
set_page_private(page, 0);
page = *head;
*head = tmp;
return page;
}
static struct page *page_chain_tail(struct page *page, int *len)
{
struct page *tmp;
int i = 1;
while ((tmp = page_chain_next(page)))
++i, page = tmp;
if (len)
*len = i;
return page;
}
static int page_chain_free(struct page *page)
{
struct page *tmp;
int i = 0;
page_chain_for_each_safe(page, tmp) {
put_page(page);
++i;
}
return i;
}
static void page_chain_add(struct page **head,
struct page *chain_first, struct page *chain_last)
{
#if 1
struct page *tmp;
tmp = page_chain_tail(chain_first, NULL);
BUG_ON(tmp != chain_last);
#endif
set_page_private(chain_last, (unsigned long)*head);
*head = chain_first;
}
static struct page *__drbd_alloc_pages(struct drbd_conf *mdev,
unsigned int number)
{
struct page *page = NULL;
struct page *tmp = NULL;
unsigned int i = 0;
if (drbd_pp_vacant >= number) {
spin_lock(&drbd_pp_lock);
page = page_chain_del(&drbd_pp_pool, number);
if (page)
drbd_pp_vacant -= number;
spin_unlock(&drbd_pp_lock);
if (page)
return page;
}
for (i = 0; i < number; i++) {
tmp = alloc_page(GFP_TRY);
if (!tmp)
break;
set_page_private(tmp, (unsigned long)page);
page = tmp;
}
if (i == number)
return page;
if (page) {
tmp = page_chain_tail(page, NULL);
spin_lock(&drbd_pp_lock);
page_chain_add(&drbd_pp_pool, page, tmp);
drbd_pp_vacant += i;
spin_unlock(&drbd_pp_lock);
}
return NULL;
}
static void reclaim_finished_net_peer_reqs(struct drbd_conf *mdev,
struct list_head *to_be_freed)
{
struct drbd_peer_request *peer_req;
struct list_head *le, *tle;
list_for_each_safe(le, tle, &mdev->net_ee) {
peer_req = list_entry(le, struct drbd_peer_request, w.list);
if (drbd_peer_req_has_active_page(peer_req))
break;
list_move(le, to_be_freed);
}
}
static void drbd_kick_lo_and_reclaim_net(struct drbd_conf *mdev)
{
LIST_HEAD(reclaimed);
struct drbd_peer_request *peer_req, *t;
spin_lock_irq(&mdev->tconn->req_lock);
reclaim_finished_net_peer_reqs(mdev, &reclaimed);
spin_unlock_irq(&mdev->tconn->req_lock);
list_for_each_entry_safe(peer_req, t, &reclaimed, w.list)
drbd_free_net_peer_req(mdev, peer_req);
}
struct page *drbd_alloc_pages(struct drbd_conf *mdev, unsigned int number,
bool retry)
{
struct page *page = NULL;
struct net_conf *nc;
DEFINE_WAIT(wait);
int mxb;
rcu_read_lock();
nc = rcu_dereference(mdev->tconn->net_conf);
mxb = nc ? nc->max_buffers : 1000000;
rcu_read_unlock();
if (atomic_read(&mdev->pp_in_use) < mxb)
page = __drbd_alloc_pages(mdev, number);
while (page == NULL) {
prepare_to_wait(&drbd_pp_wait, &wait, TASK_INTERRUPTIBLE);
drbd_kick_lo_and_reclaim_net(mdev);
if (atomic_read(&mdev->pp_in_use) < mxb) {
page = __drbd_alloc_pages(mdev, number);
if (page)
break;
}
if (!retry)
break;
if (signal_pending(current)) {
dev_warn(DEV, "drbd_alloc_pages interrupted!\n");
break;
}
schedule();
}
finish_wait(&drbd_pp_wait, &wait);
if (page)
atomic_add(number, &mdev->pp_in_use);
return page;
}
static void drbd_free_pages(struct drbd_conf *mdev, struct page *page, int is_net)
{
atomic_t *a = is_net ? &mdev->pp_in_use_by_net : &mdev->pp_in_use;
int i;
if (page == NULL)
return;
if (drbd_pp_vacant > (DRBD_MAX_BIO_SIZE/PAGE_SIZE) * minor_count)
i = page_chain_free(page);
else {
struct page *tmp;
tmp = page_chain_tail(page, &i);
spin_lock(&drbd_pp_lock);
page_chain_add(&drbd_pp_pool, page, tmp);
drbd_pp_vacant += i;
spin_unlock(&drbd_pp_lock);
}
i = atomic_sub_return(i, a);
if (i < 0)
dev_warn(DEV, "ASSERTION FAILED: %s: %d < 0\n",
is_net ? "pp_in_use_by_net" : "pp_in_use", i);
wake_up(&drbd_pp_wait);
}
struct drbd_peer_request *
drbd_alloc_peer_req(struct drbd_conf *mdev, u64 id, sector_t sector,
unsigned int data_size, gfp_t gfp_mask) __must_hold(local)
{
struct drbd_peer_request *peer_req;
struct page *page = NULL;
unsigned nr_pages = (data_size + PAGE_SIZE -1) >> PAGE_SHIFT;
if (drbd_insert_fault(mdev, DRBD_FAULT_AL_EE))
return NULL;
peer_req = mempool_alloc(drbd_ee_mempool, gfp_mask & ~__GFP_HIGHMEM);
if (!peer_req) {
if (!(gfp_mask & __GFP_NOWARN))
dev_err(DEV, "%s: allocation failed\n", __func__);
return NULL;
}
if (data_size) {
page = drbd_alloc_pages(mdev, nr_pages, (gfp_mask & __GFP_WAIT));
if (!page)
goto fail;
}
drbd_clear_interval(&peer_req->i);
peer_req->i.size = data_size;
peer_req->i.sector = sector;
peer_req->i.local = false;
peer_req->i.waiting = false;
peer_req->epoch = NULL;
peer_req->w.mdev = mdev;
peer_req->pages = page;
atomic_set(&peer_req->pending_bios, 0);
peer_req->flags = 0;
peer_req->block_id = id;
return peer_req;
fail:
mempool_free(peer_req, drbd_ee_mempool);
return NULL;
}
void __drbd_free_peer_req(struct drbd_conf *mdev, struct drbd_peer_request *peer_req,
int is_net)
{
if (peer_req->flags & EE_HAS_DIGEST)
kfree(peer_req->digest);
drbd_free_pages(mdev, peer_req->pages, is_net);
D_ASSERT(atomic_read(&peer_req->pending_bios) == 0);
D_ASSERT(drbd_interval_empty(&peer_req->i));
mempool_free(peer_req, drbd_ee_mempool);
}
int drbd_free_peer_reqs(struct drbd_conf *mdev, struct list_head *list)
{
LIST_HEAD(work_list);
struct drbd_peer_request *peer_req, *t;
int count = 0;
int is_net = list == &mdev->net_ee;
spin_lock_irq(&mdev->tconn->req_lock);
list_splice_init(list, &work_list);
spin_unlock_irq(&mdev->tconn->req_lock);
list_for_each_entry_safe(peer_req, t, &work_list, w.list) {
__drbd_free_peer_req(mdev, peer_req, is_net);
count++;
}
return count;
}
static int drbd_finish_peer_reqs(struct drbd_conf *mdev)
{
LIST_HEAD(work_list);
LIST_HEAD(reclaimed);
struct drbd_peer_request *peer_req, *t;
int err = 0;
spin_lock_irq(&mdev->tconn->req_lock);
reclaim_finished_net_peer_reqs(mdev, &reclaimed);
list_splice_init(&mdev->done_ee, &work_list);
spin_unlock_irq(&mdev->tconn->req_lock);
list_for_each_entry_safe(peer_req, t, &reclaimed, w.list)
drbd_free_net_peer_req(mdev, peer_req);
list_for_each_entry_safe(peer_req, t, &work_list, w.list) {
int err2;
err2 = peer_req->w.cb(&peer_req->w, !!err);
if (!err)
err = err2;
drbd_free_peer_req(mdev, peer_req);
}
wake_up(&mdev->ee_wait);
return err;
}
static void _drbd_wait_ee_list_empty(struct drbd_conf *mdev,
struct list_head *head)
{
DEFINE_WAIT(wait);
while (!list_empty(head)) {
prepare_to_wait(&mdev->ee_wait, &wait, TASK_UNINTERRUPTIBLE);
spin_unlock_irq(&mdev->tconn->req_lock);
io_schedule();
finish_wait(&mdev->ee_wait, &wait);
spin_lock_irq(&mdev->tconn->req_lock);
}
}
static void drbd_wait_ee_list_empty(struct drbd_conf *mdev,
struct list_head *head)
{
spin_lock_irq(&mdev->tconn->req_lock);
_drbd_wait_ee_list_empty(mdev, head);
spin_unlock_irq(&mdev->tconn->req_lock);
}
static int drbd_recv_short(struct socket *sock, void *buf, size_t size, int flags)
{
mm_segment_t oldfs;
struct kvec iov = {
.iov_base = buf,
.iov_len = size,
};
struct msghdr msg = {
.msg_iovlen = 1,
.msg_iov = (struct iovec *)&iov,
.msg_flags = (flags ? flags : MSG_WAITALL | MSG_NOSIGNAL)
};
int rv;
oldfs = get_fs();
set_fs(KERNEL_DS);
rv = sock_recvmsg(sock, &msg, size, msg.msg_flags);
set_fs(oldfs);
return rv;
}
static int drbd_recv(struct drbd_tconn *tconn, void *buf, size_t size)
{
int rv;
rv = drbd_recv_short(tconn->data.socket, buf, size, 0);
if (rv < 0) {
if (rv == -ECONNRESET)
conn_info(tconn, "sock was reset by peer\n");
else if (rv != -ERESTARTSYS)
conn_err(tconn, "sock_recvmsg returned %d\n", rv);
} else if (rv == 0) {
if (test_bit(DISCONNECT_SENT, &tconn->flags)) {
long t;
rcu_read_lock();
t = rcu_dereference(tconn->net_conf)->ping_timeo * HZ/10;
rcu_read_unlock();
t = wait_event_timeout(tconn->ping_wait, tconn->cstate < C_WF_REPORT_PARAMS, t);
if (t)
goto out;
}
conn_info(tconn, "sock was shut down by peer\n");
}
if (rv != size)
conn_request_state(tconn, NS(conn, C_BROKEN_PIPE), CS_HARD);
out:
return rv;
}
static int drbd_recv_all(struct drbd_tconn *tconn, void *buf, size_t size)
{
int err;
err = drbd_recv(tconn, buf, size);
if (err != size) {
if (err >= 0)
err = -EIO;
} else
err = 0;
return err;
}
static int drbd_recv_all_warn(struct drbd_tconn *tconn, void *buf, size_t size)
{
int err;
err = drbd_recv_all(tconn, buf, size);
if (err && !signal_pending(current))
conn_warn(tconn, "short read (expected size %d)\n", (int)size);
return err;
}
static void drbd_setbufsize(struct socket *sock, unsigned int snd,
unsigned int rcv)
{
if (snd) {
sock->sk->sk_sndbuf = snd;
sock->sk->sk_userlocks |= SOCK_SNDBUF_LOCK;
}
if (rcv) {
sock->sk->sk_rcvbuf = rcv;
sock->sk->sk_userlocks |= SOCK_RCVBUF_LOCK;
}
}
static struct socket *drbd_try_connect(struct drbd_tconn *tconn)
{
const char *what;
struct socket *sock;
struct sockaddr_in6 src_in6;
struct sockaddr_in6 peer_in6;
struct net_conf *nc;
int err, peer_addr_len, my_addr_len;
int sndbuf_size, rcvbuf_size, connect_int;
int disconnect_on_error = 1;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
if (!nc) {
rcu_read_unlock();
return NULL;
}
sndbuf_size = nc->sndbuf_size;
rcvbuf_size = nc->rcvbuf_size;
connect_int = nc->connect_int;
rcu_read_unlock();
my_addr_len = min_t(int, tconn->my_addr_len, sizeof(src_in6));
memcpy(&src_in6, &tconn->my_addr, my_addr_len);
if (((struct sockaddr *)&tconn->my_addr)->sa_family == AF_INET6)
src_in6.sin6_port = 0;
else
((struct sockaddr_in *)&src_in6)->sin_port = 0;
peer_addr_len = min_t(int, tconn->peer_addr_len, sizeof(src_in6));
memcpy(&peer_in6, &tconn->peer_addr, peer_addr_len);
what = "sock_create_kern";
err = sock_create_kern(((struct sockaddr *)&src_in6)->sa_family,
SOCK_STREAM, IPPROTO_TCP, &sock);
if (err < 0) {
sock = NULL;
goto out;
}
sock->sk->sk_rcvtimeo =
sock->sk->sk_sndtimeo = connect_int * HZ;
drbd_setbufsize(sock, sndbuf_size, rcvbuf_size);
what = "bind before connect";
err = sock->ops->bind(sock, (struct sockaddr *) &src_in6, my_addr_len);
if (err < 0)
goto out;
disconnect_on_error = 0;
what = "connect";
err = sock->ops->connect(sock, (struct sockaddr *) &peer_in6, peer_addr_len, 0);
out:
if (err < 0) {
if (sock) {
sock_release(sock);
sock = NULL;
}
switch (-err) {
case ETIMEDOUT: case EAGAIN: case EINPROGRESS:
case EINTR: case ERESTARTSYS:
case ECONNREFUSED: case ENETUNREACH:
case EHOSTDOWN: case EHOSTUNREACH:
disconnect_on_error = 0;
break;
default:
conn_err(tconn, "%s failed, err = %d\n", what, err);
}
if (disconnect_on_error)
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
}
return sock;
}
static void drbd_incoming_connection(struct sock *sk)
{
struct accept_wait_data *ad = sk->sk_user_data;
void (*state_change)(struct sock *sk);
state_change = ad->original_sk_state_change;
if (sk->sk_state == TCP_ESTABLISHED)
complete(&ad->door_bell);
state_change(sk);
}
static int prepare_listen_socket(struct drbd_tconn *tconn, struct accept_wait_data *ad)
{
int err, sndbuf_size, rcvbuf_size, my_addr_len;
struct sockaddr_in6 my_addr;
struct socket *s_listen;
struct net_conf *nc;
const char *what;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
if (!nc) {
rcu_read_unlock();
return -EIO;
}
sndbuf_size = nc->sndbuf_size;
rcvbuf_size = nc->rcvbuf_size;
rcu_read_unlock();
my_addr_len = min_t(int, tconn->my_addr_len, sizeof(struct sockaddr_in6));
memcpy(&my_addr, &tconn->my_addr, my_addr_len);
what = "sock_create_kern";
err = sock_create_kern(((struct sockaddr *)&my_addr)->sa_family,
SOCK_STREAM, IPPROTO_TCP, &s_listen);
if (err) {
s_listen = NULL;
goto out;
}
s_listen->sk->sk_reuse = SK_CAN_REUSE;
drbd_setbufsize(s_listen, sndbuf_size, rcvbuf_size);
what = "bind before listen";
err = s_listen->ops->bind(s_listen, (struct sockaddr *)&my_addr, my_addr_len);
if (err < 0)
goto out;
ad->s_listen = s_listen;
write_lock_bh(&s_listen->sk->sk_callback_lock);
ad->original_sk_state_change = s_listen->sk->sk_state_change;
s_listen->sk->sk_state_change = drbd_incoming_connection;
s_listen->sk->sk_user_data = ad;
write_unlock_bh(&s_listen->sk->sk_callback_lock);
what = "listen";
err = s_listen->ops->listen(s_listen, 5);
if (err < 0)
goto out;
return 0;
out:
if (s_listen)
sock_release(s_listen);
if (err < 0) {
if (err != -EAGAIN && err != -EINTR && err != -ERESTARTSYS) {
conn_err(tconn, "%s failed, err = %d\n", what, err);
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
}
}
return -EIO;
}
static void unregister_state_change(struct sock *sk, struct accept_wait_data *ad)
{
write_lock_bh(&sk->sk_callback_lock);
sk->sk_state_change = ad->original_sk_state_change;
sk->sk_user_data = NULL;
write_unlock_bh(&sk->sk_callback_lock);
}
static struct socket *drbd_wait_for_connect(struct drbd_tconn *tconn, struct accept_wait_data *ad)
{
int timeo, connect_int, err = 0;
struct socket *s_estab = NULL;
struct net_conf *nc;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
if (!nc) {
rcu_read_unlock();
return NULL;
}
connect_int = nc->connect_int;
rcu_read_unlock();
timeo = connect_int * HZ;
timeo += (random32() & 1) ? timeo / 7 : -timeo / 7;
err = wait_for_completion_interruptible_timeout(&ad->door_bell, timeo);
if (err <= 0)
return NULL;
err = kernel_accept(ad->s_listen, &s_estab, 0);
if (err < 0) {
if (err != -EAGAIN && err != -EINTR && err != -ERESTARTSYS) {
conn_err(tconn, "accept failed, err = %d\n", err);
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
}
}
if (s_estab)
unregister_state_change(s_estab->sk, ad);
return s_estab;
}
static int send_first_packet(struct drbd_tconn *tconn, struct drbd_socket *sock,
enum drbd_packet cmd)
{
if (!conn_prepare_command(tconn, sock))
return -EIO;
return conn_send_command(tconn, sock, cmd, 0, NULL, 0);
}
static int receive_first_packet(struct drbd_tconn *tconn, struct socket *sock)
{
unsigned int header_size = drbd_header_size(tconn);
struct packet_info pi;
int err;
err = drbd_recv_short(sock, tconn->data.rbuf, header_size, 0);
if (err != header_size) {
if (err >= 0)
err = -EIO;
return err;
}
err = decode_header(tconn, tconn->data.rbuf, &pi);
if (err)
return err;
return pi.cmd;
}
static int drbd_socket_okay(struct socket **sock)
{
int rr;
char tb[4];
if (!*sock)
return false;
rr = drbd_recv_short(*sock, tb, 4, MSG_DONTWAIT | MSG_PEEK);
if (rr > 0 || rr == -EAGAIN) {
return true;
} else {
sock_release(*sock);
*sock = NULL;
return false;
}
}
int drbd_connected(struct drbd_conf *mdev)
{
int err;
atomic_set(&mdev->packet_seq, 0);
mdev->peer_seq = 0;
mdev->state_mutex = mdev->tconn->agreed_pro_version < 100 ?
&mdev->tconn->cstate_mutex :
&mdev->own_state_mutex;
err = drbd_send_sync_param(mdev);
if (!err)
err = drbd_send_sizes(mdev, 0, 0);
if (!err)
err = drbd_send_uuids(mdev);
if (!err)
err = drbd_send_current_state(mdev);
clear_bit(USE_DEGR_WFC_T, &mdev->flags);
clear_bit(RESIZE_PENDING, &mdev->flags);
mod_timer(&mdev->request_timer, jiffies + HZ);
return err;
}
static int conn_connect(struct drbd_tconn *tconn)
{
struct drbd_socket sock, msock;
struct drbd_conf *mdev;
struct net_conf *nc;
int vnr, timeout, h, ok;
bool discard_my_data;
enum drbd_state_rv rv;
struct accept_wait_data ad = {
.tconn = tconn,
.door_bell = COMPLETION_INITIALIZER_ONSTACK(ad.door_bell),
};
clear_bit(DISCONNECT_SENT, &tconn->flags);
if (conn_request_state(tconn, NS(conn, C_WF_CONNECTION), CS_VERBOSE) < SS_SUCCESS)
return -2;
mutex_init(&sock.mutex);
sock.sbuf = tconn->data.sbuf;
sock.rbuf = tconn->data.rbuf;
sock.socket = NULL;
mutex_init(&msock.mutex);
msock.sbuf = tconn->meta.sbuf;
msock.rbuf = tconn->meta.rbuf;
msock.socket = NULL;
tconn->agreed_pro_version = 80;
if (prepare_listen_socket(tconn, &ad))
return 0;
do {
struct socket *s;
s = drbd_try_connect(tconn);
if (s) {
if (!sock.socket) {
sock.socket = s;
send_first_packet(tconn, &sock, P_INITIAL_DATA);
} else if (!msock.socket) {
clear_bit(RESOLVE_CONFLICTS, &tconn->flags);
msock.socket = s;
send_first_packet(tconn, &msock, P_INITIAL_META);
} else {
conn_err(tconn, "Logic error in conn_connect()\n");
goto out_release_sockets;
}
}
if (sock.socket && msock.socket) {
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
timeout = nc->ping_timeo * HZ / 10;
rcu_read_unlock();
schedule_timeout_interruptible(timeout);
ok = drbd_socket_okay(&sock.socket);
ok = drbd_socket_okay(&msock.socket) && ok;
if (ok)
break;
}
retry:
s = drbd_wait_for_connect(tconn, &ad);
if (s) {
int fp = receive_first_packet(tconn, s);
drbd_socket_okay(&sock.socket);
drbd_socket_okay(&msock.socket);
switch (fp) {
case P_INITIAL_DATA:
if (sock.socket) {
conn_warn(tconn, "initial packet S crossed\n");
sock_release(sock.socket);
sock.socket = s;
goto randomize;
}
sock.socket = s;
break;
case P_INITIAL_META:
set_bit(RESOLVE_CONFLICTS, &tconn->flags);
if (msock.socket) {
conn_warn(tconn, "initial packet M crossed\n");
sock_release(msock.socket);
msock.socket = s;
goto randomize;
}
msock.socket = s;
break;
default:
conn_warn(tconn, "Error receiving initial packet\n");
sock_release(s);
randomize:
if (random32() & 1)
goto retry;
}
}
if (tconn->cstate <= C_DISCONNECTING)
goto out_release_sockets;
if (signal_pending(current)) {
flush_signals(current);
smp_rmb();
if (get_t_state(&tconn->receiver) == EXITING)
goto out_release_sockets;
}
ok = drbd_socket_okay(&sock.socket);
ok = drbd_socket_okay(&msock.socket) && ok;
} while (!ok);
if (ad.s_listen)
sock_release(ad.s_listen);
sock.socket->sk->sk_reuse = SK_CAN_REUSE;
msock.socket->sk->sk_reuse = SK_CAN_REUSE;
sock.socket->sk->sk_allocation = GFP_NOIO;
msock.socket->sk->sk_allocation = GFP_NOIO;
sock.socket->sk->sk_priority = TC_PRIO_INTERACTIVE_BULK;
msock.socket->sk->sk_priority = TC_PRIO_INTERACTIVE;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
sock.socket->sk->sk_sndtimeo =
sock.socket->sk->sk_rcvtimeo = nc->ping_timeo*4*HZ/10;
msock.socket->sk->sk_rcvtimeo = nc->ping_int*HZ;
timeout = nc->timeout * HZ / 10;
discard_my_data = nc->discard_my_data;
rcu_read_unlock();
msock.socket->sk->sk_sndtimeo = timeout;
drbd_tcp_nodelay(sock.socket);
drbd_tcp_nodelay(msock.socket);
tconn->data.socket = sock.socket;
tconn->meta.socket = msock.socket;
tconn->last_received = jiffies;
h = drbd_do_features(tconn);
if (h <= 0)
return h;
if (tconn->cram_hmac_tfm) {
switch (drbd_do_auth(tconn)) {
case -1:
conn_err(tconn, "Authentication of peer failed\n");
return -1;
case 0:
conn_err(tconn, "Authentication of peer failed, trying again.\n");
return 0;
}
}
tconn->data.socket->sk->sk_sndtimeo = timeout;
tconn->data.socket->sk->sk_rcvtimeo = MAX_SCHEDULE_TIMEOUT;
if (drbd_send_protocol(tconn) == -EOPNOTSUPP)
return -1;
set_bit(STATE_SENT, &tconn->flags);
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
kref_get(&mdev->kref);
mutex_lock(mdev->state_mutex);
mutex_unlock(mdev->state_mutex);
rcu_read_unlock();
if (discard_my_data)
set_bit(DISCARD_MY_DATA, &mdev->flags);
else
clear_bit(DISCARD_MY_DATA, &mdev->flags);
drbd_connected(mdev);
kref_put(&mdev->kref, &drbd_minor_destroy);
rcu_read_lock();
}
rcu_read_unlock();
rv = conn_request_state(tconn, NS(conn, C_WF_REPORT_PARAMS), CS_VERBOSE);
if (rv < SS_SUCCESS || tconn->cstate != C_WF_REPORT_PARAMS) {
clear_bit(STATE_SENT, &tconn->flags);
return 0;
}
drbd_thread_start(&tconn->asender);
mutex_lock(&tconn->conf_update);
tconn->net_conf->discard_my_data = 0;
mutex_unlock(&tconn->conf_update);
return h;
out_release_sockets:
if (ad.s_listen)
sock_release(ad.s_listen);
if (sock.socket)
sock_release(sock.socket);
if (msock.socket)
sock_release(msock.socket);
return -1;
}
static int decode_header(struct drbd_tconn *tconn, void *header, struct packet_info *pi)
{
unsigned int header_size = drbd_header_size(tconn);
if (header_size == sizeof(struct p_header100) &&
*(__be32 *)header == cpu_to_be32(DRBD_MAGIC_100)) {
struct p_header100 *h = header;
if (h->pad != 0) {
conn_err(tconn, "Header padding is not zero\n");
return -EINVAL;
}
pi->vnr = be16_to_cpu(h->volume);
pi->cmd = be16_to_cpu(h->command);
pi->size = be32_to_cpu(h->length);
} else if (header_size == sizeof(struct p_header95) &&
*(__be16 *)header == cpu_to_be16(DRBD_MAGIC_BIG)) {
struct p_header95 *h = header;
pi->cmd = be16_to_cpu(h->command);
pi->size = be32_to_cpu(h->length);
pi->vnr = 0;
} else if (header_size == sizeof(struct p_header80) &&
*(__be32 *)header == cpu_to_be32(DRBD_MAGIC)) {
struct p_header80 *h = header;
pi->cmd = be16_to_cpu(h->command);
pi->size = be16_to_cpu(h->length);
pi->vnr = 0;
} else {
conn_err(tconn, "Wrong magic value 0x%08x in protocol version %d\n",
be32_to_cpu(*(__be32 *)header),
tconn->agreed_pro_version);
return -EINVAL;
}
pi->data = header + header_size;
return 0;
}
static int drbd_recv_header(struct drbd_tconn *tconn, struct packet_info *pi)
{
void *buffer = tconn->data.rbuf;
int err;
err = drbd_recv_all_warn(tconn, buffer, drbd_header_size(tconn));
if (err)
return err;
err = decode_header(tconn, buffer, pi);
tconn->last_received = jiffies;
return err;
}
static void drbd_flush(struct drbd_tconn *tconn)
{
int rv;
struct drbd_conf *mdev;
int vnr;
if (tconn->write_ordering >= WO_bdev_flush) {
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
if (!get_ldev(mdev))
continue;
kref_get(&mdev->kref);
rcu_read_unlock();
rv = blkdev_issue_flush(mdev->ldev->backing_bdev,
GFP_NOIO, NULL);
if (rv) {
dev_info(DEV, "local disk flush failed with status %d\n", rv);
drbd_bump_write_ordering(tconn, WO_drain_io);
}
put_ldev(mdev);
kref_put(&mdev->kref, &drbd_minor_destroy);
rcu_read_lock();
if (rv)
break;
}
rcu_read_unlock();
}
}
static enum finish_epoch drbd_may_finish_epoch(struct drbd_tconn *tconn,
struct drbd_epoch *epoch,
enum epoch_event ev)
{
int epoch_size;
struct drbd_epoch *next_epoch;
enum finish_epoch rv = FE_STILL_LIVE;
spin_lock(&tconn->epoch_lock);
do {
next_epoch = NULL;
epoch_size = atomic_read(&epoch->epoch_size);
switch (ev & ~EV_CLEANUP) {
case EV_PUT:
atomic_dec(&epoch->active);
break;
case EV_GOT_BARRIER_NR:
set_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags);
break;
case EV_BECAME_LAST:
break;
}
if (epoch_size != 0 &&
atomic_read(&epoch->active) == 0 &&
(test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags) || ev & EV_CLEANUP)) {
if (!(ev & EV_CLEANUP)) {
spin_unlock(&tconn->epoch_lock);
drbd_send_b_ack(epoch->tconn, epoch->barrier_nr, epoch_size);
spin_lock(&tconn->epoch_lock);
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->tconn);
#endif
if (tconn->current_epoch != epoch) {
next_epoch = list_entry(epoch->list.next, struct drbd_epoch, list);
list_del(&epoch->list);
ev = EV_BECAME_LAST | (ev & EV_CLEANUP);
tconn->epochs--;
kfree(epoch);
if (rv == FE_STILL_LIVE)
rv = FE_DESTROYED;
} else {
epoch->flags = 0;
atomic_set(&epoch->epoch_size, 0);
if (rv == FE_STILL_LIVE)
rv = FE_RECYCLED;
}
}
if (!next_epoch)
break;
epoch = next_epoch;
} while (1);
spin_unlock(&tconn->epoch_lock);
return rv;
}
void drbd_bump_write_ordering(struct drbd_tconn *tconn, enum write_ordering_e wo)
{
struct disk_conf *dc;
struct drbd_conf *mdev;
enum write_ordering_e pwo;
int vnr;
static char *write_ordering_str[] = {
[WO_none] = "none",
[WO_drain_io] = "drain",
[WO_bdev_flush] = "flush",
};
pwo = tconn->write_ordering;
wo = min(pwo, wo);
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
if (!get_ldev_if_state(mdev, D_ATTACHING))
continue;
dc = rcu_dereference(mdev->ldev->disk_conf);
if (wo == WO_bdev_flush && !dc->disk_flushes)
wo = WO_drain_io;
if (wo == WO_drain_io && !dc->disk_drain)
wo = WO_none;
put_ldev(mdev);
}
rcu_read_unlock();
tconn->write_ordering = wo;
if (pwo != tconn->write_ordering || wo == WO_bdev_flush)
conn_info(tconn, "Method to ensure write ordering: %s\n", write_ordering_str[tconn->write_ordering]);
}
int drbd_submit_peer_request(struct drbd_conf *mdev,
struct drbd_peer_request *peer_req,
const unsigned rw, const int fault_type)
{
struct bio *bios = NULL;
struct bio *bio;
struct page *page = peer_req->pages;
sector_t sector = peer_req->i.sector;
unsigned ds = peer_req->i.size;
unsigned n_bios = 0;
unsigned nr_pages = (ds + PAGE_SIZE -1) >> PAGE_SHIFT;
int err = -ENOMEM;
next_bio:
bio = bio_alloc(GFP_NOIO, nr_pages);
if (!bio) {
dev_err(DEV, "submit_ee: Allocation of a bio failed\n");
goto fail;
}
bio->bi_sector = sector;
bio->bi_bdev = mdev->ldev->backing_bdev;
bio->bi_rw = rw;
bio->bi_private = peer_req;
bio->bi_end_io = drbd_peer_request_endio;
bio->bi_next = bios;
bios = bio;
++n_bios;
page_chain_for_each(page) {
unsigned len = min_t(unsigned, ds, PAGE_SIZE);
if (!bio_add_page(bio, page, len, 0)) {
if (bio->bi_vcnt == 0) {
dev_err(DEV,
"bio_add_page failed for len=%u, "
"bi_vcnt=0 (bi_sector=%llu)\n",
len, (unsigned long long)bio->bi_sector);
err = -ENOSPC;
goto fail;
}
goto next_bio;
}
ds -= len;
sector += len >> 9;
--nr_pages;
}
D_ASSERT(page == NULL);
D_ASSERT(ds == 0);
atomic_set(&peer_req->pending_bios, n_bios);
do {
bio = bios;
bios = bios->bi_next;
bio->bi_next = NULL;
drbd_generic_make_request(mdev, fault_type, bio);
} while (bios);
return 0;
fail:
while (bios) {
bio = bios;
bios = bios->bi_next;
bio_put(bio);
}
return err;
}
static void drbd_remove_epoch_entry_interval(struct drbd_conf *mdev,
struct drbd_peer_request *peer_req)
{
struct drbd_interval *i = &peer_req->i;
drbd_remove_interval(&mdev->write_requests, i);
drbd_clear_interval(i);
if (i->waiting)
wake_up(&mdev->misc_wait);
}
void conn_wait_active_ee_empty(struct drbd_tconn *tconn)
{
struct drbd_conf *mdev;
int vnr;
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
kref_get(&mdev->kref);
rcu_read_unlock();
drbd_wait_ee_list_empty(mdev, &mdev->active_ee);
kref_put(&mdev->kref, &drbd_minor_destroy);
rcu_read_lock();
}
rcu_read_unlock();
}
static int receive_Barrier(struct drbd_tconn *tconn, struct packet_info *pi)
{
int rv;
struct p_barrier *p = pi->data;
struct drbd_epoch *epoch;
tconn->current_epoch->barrier_nr = p->barrier;
tconn->current_epoch->tconn = tconn;
rv = drbd_may_finish_epoch(tconn, tconn->current_epoch, EV_GOT_BARRIER_NR);
switch (tconn->write_ordering) {
case WO_none:
if (rv == FE_RECYCLED)
return 0;
epoch = kmalloc(sizeof(struct drbd_epoch), GFP_NOIO);
if (epoch)
break;
else
conn_warn(tconn, "Allocation of an epoch failed, slowing down\n");
case WO_bdev_flush:
case WO_drain_io:
conn_wait_active_ee_empty(tconn);
drbd_flush(tconn);
if (atomic_read(&tconn->current_epoch->epoch_size)) {
epoch = kmalloc(sizeof(struct drbd_epoch), GFP_NOIO);
if (epoch)
break;
}
return 0;
default:
conn_err(tconn, "Strangeness in tconn->write_ordering %d\n", tconn->write_ordering);
return -EIO;
}
epoch->flags = 0;
atomic_set(&epoch->epoch_size, 0);
atomic_set(&epoch->active, 0);
spin_lock(&tconn->epoch_lock);
if (atomic_read(&tconn->current_epoch->epoch_size)) {
list_add(&epoch->list, &tconn->current_epoch->list);
tconn->current_epoch = epoch;
tconn->epochs++;
} else {
kfree(epoch);
}
spin_unlock(&tconn->epoch_lock);
return 0;
}
static struct drbd_peer_request *
read_in_block(struct drbd_conf *mdev, u64 id, sector_t sector,
int data_size) __must_hold(local)
{
const sector_t capacity = drbd_get_capacity(mdev->this_bdev);
struct drbd_peer_request *peer_req;
struct page *page;
int dgs, ds, err;
void *dig_in = mdev->tconn->int_dig_in;
void *dig_vv = mdev->tconn->int_dig_vv;
unsigned long *data;
dgs = 0;
if (mdev->tconn->peer_integrity_tfm) {
dgs = crypto_hash_digestsize(mdev->tconn->peer_integrity_tfm);
err = drbd_recv_all_warn(mdev->tconn, dig_in, dgs);
if (err)
return NULL;
data_size -= dgs;
}
if (!expect(IS_ALIGNED(data_size, 512)))
return NULL;
if (!expect(data_size <= DRBD_MAX_BIO_SIZE))
return NULL;
if (sector + (data_size>>9) > capacity) {
dev_err(DEV, "request from peer beyond end of local disk: "
"capacity: %llus < sector: %llus + size: %u\n",
(unsigned long long)capacity,
(unsigned long long)sector, data_size);
return NULL;
}
peer_req = drbd_alloc_peer_req(mdev, id, sector, data_size, GFP_NOIO);
if (!peer_req)
return NULL;
if (!data_size)
return peer_req;
ds = data_size;
page = peer_req->pages;
page_chain_for_each(page) {
unsigned len = min_t(int, ds, PAGE_SIZE);
data = kmap(page);
err = drbd_recv_all_warn(mdev->tconn, data, len);
if (drbd_insert_fault(mdev, DRBD_FAULT_RECEIVE)) {
dev_err(DEV, "Fault injection: Corrupting data on receive\n");
data[0] = data[0] ^ (unsigned long)-1;
}
kunmap(page);
if (err) {
drbd_free_peer_req(mdev, peer_req);
return NULL;
}
ds -= len;
}
if (dgs) {
drbd_csum_ee(mdev, mdev->tconn->peer_integrity_tfm, peer_req, dig_vv);
if (memcmp(dig_in, dig_vv, dgs)) {
dev_err(DEV, "Digest integrity check FAILED: %llus +%u\n",
(unsigned long long)sector, data_size);
drbd_free_peer_req(mdev, peer_req);
return NULL;
}
}
mdev->recv_cnt += data_size>>9;
return peer_req;
}
static int drbd_drain_block(struct drbd_conf *mdev, int data_size)
{
struct page *page;
int err = 0;
void *data;
if (!data_size)
return 0;
page = drbd_alloc_pages(mdev, 1, 1);
data = kmap(page);
while (data_size) {
unsigned int len = min_t(int, data_size, PAGE_SIZE);
err = drbd_recv_all_warn(mdev->tconn, data, len);
if (err)
break;
data_size -= len;
}
kunmap(page);
drbd_free_pages(mdev, page, 0);
return err;
}
static int recv_dless_read(struct drbd_conf *mdev, struct drbd_request *req,
sector_t sector, int data_size)
{
struct bio_vec *bvec;
struct bio *bio;
int dgs, err, i, expect;
void *dig_in = mdev->tconn->int_dig_in;
void *dig_vv = mdev->tconn->int_dig_vv;
dgs = 0;
if (mdev->tconn->peer_integrity_tfm) {
dgs = crypto_hash_digestsize(mdev->tconn->peer_integrity_tfm);
err = drbd_recv_all_warn(mdev->tconn, dig_in, dgs);
if (err)
return err;
data_size -= dgs;
}
mdev->recv_cnt += data_size>>9;
bio = req->master_bio;
D_ASSERT(sector == bio->bi_sector);
bio_for_each_segment(bvec, bio, i) {
void *mapped = kmap(bvec->bv_page) + bvec->bv_offset;
expect = min_t(int, data_size, bvec->bv_len);
err = drbd_recv_all_warn(mdev->tconn, mapped, expect);
kunmap(bvec->bv_page);
if (err)
return err;
data_size -= expect;
}
if (dgs) {
drbd_csum_bio(mdev, mdev->tconn->peer_integrity_tfm, bio, dig_vv);
if (memcmp(dig_in, dig_vv, dgs)) {
dev_err(DEV, "Digest integrity check FAILED. Broken NICs?\n");
return -EINVAL;
}
}
D_ASSERT(data_size == 0);
return 0;
}
static int e_end_resync_block(struct drbd_work *w, int unused)
{
struct drbd_peer_request *peer_req =
container_of(w, struct drbd_peer_request, w);
struct drbd_conf *mdev = w->mdev;
sector_t sector = peer_req->i.sector;
int err;
D_ASSERT(drbd_interval_empty(&peer_req->i));
if (likely((peer_req->flags & EE_WAS_ERROR) == 0)) {
drbd_set_in_sync(mdev, sector, peer_req->i.size);
err = drbd_send_ack(mdev, P_RS_WRITE_ACK, peer_req);
} else {
drbd_rs_failed_io(mdev, sector, peer_req->i.size);
err = drbd_send_ack(mdev, P_NEG_ACK, peer_req);
}
dec_unacked(mdev);
return err;
}
static int recv_resync_read(struct drbd_conf *mdev, sector_t sector, int data_size) __releases(local)
{
struct drbd_peer_request *peer_req;
peer_req = read_in_block(mdev, ID_SYNCER, sector, data_size);
if (!peer_req)
goto fail;
dec_rs_pending(mdev);
inc_unacked(mdev);
peer_req->w.cb = e_end_resync_block;
spin_lock_irq(&mdev->tconn->req_lock);
list_add(&peer_req->w.list, &mdev->sync_ee);
spin_unlock_irq(&mdev->tconn->req_lock);
atomic_add(data_size >> 9, &mdev->rs_sect_ev);
if (drbd_submit_peer_request(mdev, peer_req, WRITE, DRBD_FAULT_RS_WR) == 0)
return 0;
dev_err(DEV, "submit failed, triggering re-connect\n");
spin_lock_irq(&mdev->tconn->req_lock);
list_del(&peer_req->w.list);
spin_unlock_irq(&mdev->tconn->req_lock);
drbd_free_peer_req(mdev, peer_req);
fail:
put_ldev(mdev);
return -EIO;
}
static struct drbd_request *
find_request(struct drbd_conf *mdev, struct rb_root *root, u64 id,
sector_t sector, bool missing_ok, const char *func)
{
struct drbd_request *req;
req = (struct drbd_request *)(unsigned long)id;
if (drbd_contains_interval(root, sector, &req->i) && req->i.local)
return req;
if (!missing_ok) {
dev_err(DEV, "%s: failed to find request 0x%lx, sector %llus\n", func,
(unsigned long)id, (unsigned long long)sector);
}
return NULL;
}
static int receive_DataReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct drbd_request *req;
sector_t sector;
int err;
struct p_data *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
sector = be64_to_cpu(p->sector);
spin_lock_irq(&mdev->tconn->req_lock);
req = find_request(mdev, &mdev->read_requests, p->block_id, sector, false, __func__);
spin_unlock_irq(&mdev->tconn->req_lock);
if (unlikely(!req))
return -EIO;
err = recv_dless_read(mdev, req, sector, pi->size);
if (!err)
req_mod(req, DATA_RECEIVED);
return err;
}
static int receive_RSDataReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
sector_t sector;
int err;
struct p_data *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
sector = be64_to_cpu(p->sector);
D_ASSERT(p->block_id == ID_SYNCER);
if (get_ldev(mdev)) {
err = recv_resync_read(mdev, sector, pi->size);
} else {
if (__ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Can not write resync data to local disk.\n");
err = drbd_drain_block(mdev, pi->size);
drbd_send_ack_dp(mdev, P_NEG_ACK, p, pi->size);
}
atomic_add(pi->size >> 9, &mdev->rs_sect_in);
return err;
}
static void restart_conflicting_writes(struct drbd_conf *mdev,
sector_t sector, int size)
{
struct drbd_interval *i;
struct drbd_request *req;
drbd_for_each_overlap(i, &mdev->write_requests, sector, size) {
if (!i->local)
continue;
req = container_of(i, struct drbd_request, i);
if (req->rq_state & RQ_LOCAL_PENDING ||
!(req->rq_state & RQ_POSTPONED))
continue;
__req_mod(req, CONFLICT_RESOLVED, NULL);
}
}
static int e_end_block(struct drbd_work *w, int cancel)
{
struct drbd_peer_request *peer_req =
container_of(w, struct drbd_peer_request, w);
struct drbd_conf *mdev = w->mdev;
sector_t sector = peer_req->i.sector;
int err = 0, pcmd;
if (peer_req->flags & EE_SEND_WRITE_ACK) {
if (likely((peer_req->flags & EE_WAS_ERROR) == 0)) {
pcmd = (mdev->state.conn >= C_SYNC_SOURCE &&
mdev->state.conn <= C_PAUSED_SYNC_T &&
peer_req->flags & EE_MAY_SET_IN_SYNC) ?
P_RS_WRITE_ACK : P_WRITE_ACK;
err = drbd_send_ack(mdev, pcmd, peer_req);
if (pcmd == P_RS_WRITE_ACK)
drbd_set_in_sync(mdev, sector, peer_req->i.size);
} else {
err = drbd_send_ack(mdev, P_NEG_ACK, peer_req);
}
dec_unacked(mdev);
}
if (peer_req->flags & EE_IN_INTERVAL_TREE) {
spin_lock_irq(&mdev->tconn->req_lock);
D_ASSERT(!drbd_interval_empty(&peer_req->i));
drbd_remove_epoch_entry_interval(mdev, peer_req);
if (peer_req->flags & EE_RESTART_REQUESTS)
restart_conflicting_writes(mdev, sector, peer_req->i.size);
spin_unlock_irq(&mdev->tconn->req_lock);
} else
D_ASSERT(drbd_interval_empty(&peer_req->i));
drbd_may_finish_epoch(mdev->tconn, peer_req->epoch, EV_PUT + (cancel ? EV_CLEANUP : 0));
return err;
}
static int e_send_ack(struct drbd_work *w, enum drbd_packet ack)
{
struct drbd_conf *mdev = w->mdev;
struct drbd_peer_request *peer_req =
container_of(w, struct drbd_peer_request, w);
int err;
err = drbd_send_ack(mdev, ack, peer_req);
dec_unacked(mdev);
return err;
}
static int e_send_superseded(struct drbd_work *w, int unused)
{
return e_send_ack(w, P_SUPERSEDED);
}
static int e_send_retry_write(struct drbd_work *w, int unused)
{
struct drbd_tconn *tconn = w->mdev->tconn;
return e_send_ack(w, tconn->agreed_pro_version >= 100 ?
P_RETRY_WRITE : P_SUPERSEDED);
}
static bool seq_greater(u32 a, u32 b)
{
return (s32)a - (s32)b > 0;
}
static u32 seq_max(u32 a, u32 b)
{
return seq_greater(a, b) ? a : b;
}
static bool need_peer_seq(struct drbd_conf *mdev)
{
struct drbd_tconn *tconn = mdev->tconn;
int tp;
rcu_read_lock();
tp = rcu_dereference(mdev->tconn->net_conf)->two_primaries;
rcu_read_unlock();
return tp && test_bit(RESOLVE_CONFLICTS, &tconn->flags);
}
static void update_peer_seq(struct drbd_conf *mdev, unsigned int peer_seq)
{
unsigned int newest_peer_seq;
if (need_peer_seq(mdev)) {
spin_lock(&mdev->peer_seq_lock);
newest_peer_seq = seq_max(mdev->peer_seq, peer_seq);
mdev->peer_seq = newest_peer_seq;
spin_unlock(&mdev->peer_seq_lock);
if (peer_seq == newest_peer_seq)
wake_up(&mdev->seq_wait);
}
}
static inline int overlaps(sector_t s1, int l1, sector_t s2, int l2)
{
return !((s1 + (l1>>9) <= s2) || (s1 >= s2 + (l2>>9)));
}
static bool overlapping_resync_write(struct drbd_conf *mdev, struct drbd_peer_request *peer_req)
{
struct drbd_peer_request *rs_req;
bool rv = 0;
spin_lock_irq(&mdev->tconn->req_lock);
list_for_each_entry(rs_req, &mdev->sync_ee, w.list) {
if (overlaps(peer_req->i.sector, peer_req->i.size,
rs_req->i.sector, rs_req->i.size)) {
rv = 1;
break;
}
}
spin_unlock_irq(&mdev->tconn->req_lock);
return rv;
}
static int wait_for_and_update_peer_seq(struct drbd_conf *mdev, const u32 peer_seq)
{
DEFINE_WAIT(wait);
long timeout;
int ret;
if (!need_peer_seq(mdev))
return 0;
spin_lock(&mdev->peer_seq_lock);
for (;;) {
if (!seq_greater(peer_seq - 1, mdev->peer_seq)) {
mdev->peer_seq = seq_max(mdev->peer_seq, peer_seq);
ret = 0;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
prepare_to_wait(&mdev->seq_wait, &wait, TASK_INTERRUPTIBLE);
spin_unlock(&mdev->peer_seq_lock);
rcu_read_lock();
timeout = rcu_dereference(mdev->tconn->net_conf)->ping_timeo*HZ/10;
rcu_read_unlock();
timeout = schedule_timeout(timeout);
spin_lock(&mdev->peer_seq_lock);
if (!timeout) {
ret = -ETIMEDOUT;
dev_err(DEV, "Timed out waiting for missing ack packets; disconnecting\n");
break;
}
}
spin_unlock(&mdev->peer_seq_lock);
finish_wait(&mdev->seq_wait, &wait);
return ret;
}
static unsigned long wire_flags_to_bio(struct drbd_conf *mdev, u32 dpf)
{
return (dpf & DP_RW_SYNC ? REQ_SYNC : 0) |
(dpf & DP_FUA ? REQ_FUA : 0) |
(dpf & DP_FLUSH ? REQ_FLUSH : 0) |
(dpf & DP_DISCARD ? REQ_DISCARD : 0);
}
static void fail_postponed_requests(struct drbd_conf *mdev, sector_t sector,
unsigned int size)
{
struct drbd_interval *i;
repeat:
drbd_for_each_overlap(i, &mdev->write_requests, sector, size) {
struct drbd_request *req;
struct bio_and_error m;
if (!i->local)
continue;
req = container_of(i, struct drbd_request, i);
if (!(req->rq_state & RQ_POSTPONED))
continue;
req->rq_state &= ~RQ_POSTPONED;
__req_mod(req, NEG_ACKED, &m);
spin_unlock_irq(&mdev->tconn->req_lock);
if (m.bio)
complete_master_bio(mdev, &m);
spin_lock_irq(&mdev->tconn->req_lock);
goto repeat;
}
}
static int handle_write_conflicts(struct drbd_conf *mdev,
struct drbd_peer_request *peer_req)
{
struct drbd_tconn *tconn = mdev->tconn;
bool resolve_conflicts = test_bit(RESOLVE_CONFLICTS, &tconn->flags);
sector_t sector = peer_req->i.sector;
const unsigned int size = peer_req->i.size;
struct drbd_interval *i;
bool equal;
int err;
drbd_insert_interval(&mdev->write_requests, &peer_req->i);
repeat:
drbd_for_each_overlap(i, &mdev->write_requests, sector, size) {
if (i == &peer_req->i)
continue;
if (!i->local) {
err = drbd_wait_misc(mdev, i);
if (err)
goto out;
goto repeat;
}
equal = i->sector == sector && i->size == size;
if (resolve_conflicts) {
bool superseded = i->sector <= sector && i->sector +
(i->size >> 9) >= sector + (size >> 9);
if (!equal)
dev_alert(DEV, "Concurrent writes detected: "
"local=%llus +%u, remote=%llus +%u, "
"assuming %s came first\n",
(unsigned long long)i->sector, i->size,
(unsigned long long)sector, size,
superseded ? "local" : "remote");
inc_unacked(mdev);
peer_req->w.cb = superseded ? e_send_superseded :
e_send_retry_write;
list_add_tail(&peer_req->w.list, &mdev->done_ee);
wake_asender(mdev->tconn);
err = -ENOENT;
goto out;
} else {
struct drbd_request *req =
container_of(i, struct drbd_request, i);
if (!equal)
dev_alert(DEV, "Concurrent writes detected: "
"local=%llus +%u, remote=%llus +%u\n",
(unsigned long long)i->sector, i->size,
(unsigned long long)sector, size);
if (req->rq_state & RQ_LOCAL_PENDING ||
!(req->rq_state & RQ_POSTPONED)) {
err = drbd_wait_misc(mdev, &req->i);
if (err) {
_conn_request_state(mdev->tconn,
NS(conn, C_TIMEOUT),
CS_HARD);
fail_postponed_requests(mdev, sector, size);
goto out;
}
goto repeat;
}
peer_req->flags |= EE_RESTART_REQUESTS;
}
}
err = 0;
out:
if (err)
drbd_remove_epoch_entry_interval(mdev, peer_req);
return err;
}
static int receive_Data(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
sector_t sector;
struct drbd_peer_request *peer_req;
struct p_data *p = pi->data;
u32 peer_seq = be32_to_cpu(p->seq_num);
int rw = WRITE;
u32 dp_flags;
int err, tp;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
if (!get_ldev(mdev)) {
int err2;
err = wait_for_and_update_peer_seq(mdev, peer_seq);
drbd_send_ack_dp(mdev, P_NEG_ACK, p, pi->size);
atomic_inc(&tconn->current_epoch->epoch_size);
err2 = drbd_drain_block(mdev, pi->size);
if (!err)
err = err2;
return err;
}
sector = be64_to_cpu(p->sector);
peer_req = read_in_block(mdev, p->block_id, sector, pi->size);
if (!peer_req) {
put_ldev(mdev);
return -EIO;
}
peer_req->w.cb = e_end_block;
dp_flags = be32_to_cpu(p->dp_flags);
rw |= wire_flags_to_bio(mdev, dp_flags);
if (peer_req->pages == NULL) {
D_ASSERT(peer_req->i.size == 0);
D_ASSERT(dp_flags & DP_FLUSH);
}
if (dp_flags & DP_MAY_SET_IN_SYNC)
peer_req->flags |= EE_MAY_SET_IN_SYNC;
spin_lock(&tconn->epoch_lock);
peer_req->epoch = tconn->current_epoch;
atomic_inc(&peer_req->epoch->epoch_size);
atomic_inc(&peer_req->epoch->active);
spin_unlock(&tconn->epoch_lock);
rcu_read_lock();
tp = rcu_dereference(mdev->tconn->net_conf)->two_primaries;
rcu_read_unlock();
if (tp) {
peer_req->flags |= EE_IN_INTERVAL_TREE;
err = wait_for_and_update_peer_seq(mdev, peer_seq);
if (err)
goto out_interrupted;
spin_lock_irq(&mdev->tconn->req_lock);
err = handle_write_conflicts(mdev, peer_req);
if (err) {
spin_unlock_irq(&mdev->tconn->req_lock);
if (err == -ENOENT) {
put_ldev(mdev);
return 0;
}
goto out_interrupted;
}
} else
spin_lock_irq(&mdev->tconn->req_lock);
list_add(&peer_req->w.list, &mdev->active_ee);
spin_unlock_irq(&mdev->tconn->req_lock);
if (mdev->state.conn == C_SYNC_TARGET)
wait_event(mdev->ee_wait, !overlapping_resync_write(mdev, peer_req));
if (mdev->tconn->agreed_pro_version < 100) {
rcu_read_lock();
switch (rcu_dereference(mdev->tconn->net_conf)->wire_protocol) {
case DRBD_PROT_C:
dp_flags |= DP_SEND_WRITE_ACK;
break;
case DRBD_PROT_B:
dp_flags |= DP_SEND_RECEIVE_ACK;
break;
}
rcu_read_unlock();
}
if (dp_flags & DP_SEND_WRITE_ACK) {
peer_req->flags |= EE_SEND_WRITE_ACK;
inc_unacked(mdev);
}
if (dp_flags & DP_SEND_RECEIVE_ACK) {
drbd_send_ack(mdev, P_RECV_ACK, peer_req);
}
if (mdev->state.pdsk < D_INCONSISTENT) {
drbd_set_out_of_sync(mdev, peer_req->i.sector, peer_req->i.size);
peer_req->flags |= EE_CALL_AL_COMPLETE_IO;
peer_req->flags &= ~EE_MAY_SET_IN_SYNC;
drbd_al_begin_io(mdev, &peer_req->i);
}
err = drbd_submit_peer_request(mdev, peer_req, rw, DRBD_FAULT_DT_WR);
if (!err)
return 0;
dev_err(DEV, "submit failed, triggering re-connect\n");
spin_lock_irq(&mdev->tconn->req_lock);
list_del(&peer_req->w.list);
drbd_remove_epoch_entry_interval(mdev, peer_req);
spin_unlock_irq(&mdev->tconn->req_lock);
if (peer_req->flags & EE_CALL_AL_COMPLETE_IO)
drbd_al_complete_io(mdev, &peer_req->i);
out_interrupted:
drbd_may_finish_epoch(tconn, peer_req->epoch, EV_PUT + EV_CLEANUP);
put_ldev(mdev);
drbd_free_peer_req(mdev, peer_req);
return err;
}
int drbd_rs_should_slow_down(struct drbd_conf *mdev, sector_t sector)
{
struct gendisk *disk = mdev->ldev->backing_bdev->bd_contains->bd_disk;
unsigned long db, dt, dbdt;
struct lc_element *tmp;
int curr_events;
int throttle = 0;
unsigned int c_min_rate;
rcu_read_lock();
c_min_rate = rcu_dereference(mdev->ldev->disk_conf)->c_min_rate;
rcu_read_unlock();
if (c_min_rate == 0)
return 0;
spin_lock_irq(&mdev->al_lock);
tmp = lc_find(mdev->resync, BM_SECT_TO_EXT(sector));
if (tmp) {
struct bm_extent *bm_ext = lc_entry(tmp, struct bm_extent, lce);
if (test_bit(BME_PRIORITY, &bm_ext->flags)) {
spin_unlock_irq(&mdev->al_lock);
return 0;
}
}
spin_unlock_irq(&mdev->al_lock);
curr_events = (int)part_stat_read(&disk->part0, sectors[0]) +
(int)part_stat_read(&disk->part0, sectors[1]) -
atomic_read(&mdev->rs_sect_ev);
if (!mdev->rs_last_events || curr_events - mdev->rs_last_events > 64) {
unsigned long rs_left;
int i;
mdev->rs_last_events = curr_events;
i = (mdev->rs_last_mark + DRBD_SYNC_MARKS-1) % DRBD_SYNC_MARKS;
if (mdev->state.conn == C_VERIFY_S || mdev->state.conn == C_VERIFY_T)
rs_left = mdev->ov_left;
else
rs_left = drbd_bm_total_weight(mdev) - mdev->rs_failed;
dt = ((long)jiffies - (long)mdev->rs_mark_time[i]) / HZ;
if (!dt)
dt++;
db = mdev->rs_mark_left[i] - rs_left;
dbdt = Bit2KB(db/dt);
if (dbdt > c_min_rate)
throttle = 1;
}
return throttle;
}
static int receive_DataRequest(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
sector_t sector;
sector_t capacity;
struct drbd_peer_request *peer_req;
struct digest_info *di = NULL;
int size, verb;
unsigned int fault_type;
struct p_block_req *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
capacity = drbd_get_capacity(mdev->this_bdev);
sector = be64_to_cpu(p->sector);
size = be32_to_cpu(p->blksize);
if (size <= 0 || !IS_ALIGNED(size, 512) || size > DRBD_MAX_BIO_SIZE) {
dev_err(DEV, "%s:%d: sector: %llus, size: %u\n", __FILE__, __LINE__,
(unsigned long long)sector, size);
return -EINVAL;
}
if (sector + (size>>9) > capacity) {
dev_err(DEV, "%s:%d: sector: %llus, size: %u\n", __FILE__, __LINE__,
(unsigned long long)sector, size);
return -EINVAL;
}
if (!get_ldev_if_state(mdev, D_UP_TO_DATE)) {
verb = 1;
switch (pi->cmd) {
case P_DATA_REQUEST:
drbd_send_ack_rp(mdev, P_NEG_DREPLY, p);
break;
case P_RS_DATA_REQUEST:
case P_CSUM_RS_REQUEST:
case P_OV_REQUEST:
drbd_send_ack_rp(mdev, P_NEG_RS_DREPLY , p);
break;
case P_OV_REPLY:
verb = 0;
dec_rs_pending(mdev);
drbd_send_ack_ex(mdev, P_OV_RESULT, sector, size, ID_IN_SYNC);
break;
default:
BUG();
}
if (verb && __ratelimit(&drbd_ratelimit_state))
dev_err(DEV, "Can not satisfy peer's read request, "
"no local data.\n");
return drbd_drain_block(mdev, pi->size);
}
peer_req = drbd_alloc_peer_req(mdev, p->block_id, sector, size, GFP_NOIO);
if (!peer_req) {
put_ldev(mdev);
return -ENOMEM;
}
switch (pi->cmd) {
case P_DATA_REQUEST:
peer_req->w.cb = w_e_end_data_req;
fault_type = DRBD_FAULT_DT_RD;
goto submit;
case P_RS_DATA_REQUEST:
peer_req->w.cb = w_e_end_rsdata_req;
fault_type = DRBD_FAULT_RS_RD;
mdev->bm_resync_fo = BM_SECT_TO_BIT(sector);
break;
case P_OV_REPLY:
case P_CSUM_RS_REQUEST:
fault_type = DRBD_FAULT_RS_RD;
di = kmalloc(sizeof(*di) + pi->size, GFP_NOIO);
if (!di)
goto out_free_e;
di->digest_size = pi->size;
di->digest = (((char *)di)+sizeof(struct digest_info));
peer_req->digest = di;
peer_req->flags |= EE_HAS_DIGEST;
if (drbd_recv_all(mdev->tconn, di->digest, pi->size))
goto out_free_e;
if (pi->cmd == P_CSUM_RS_REQUEST) {
D_ASSERT(mdev->tconn->agreed_pro_version >= 89);
peer_req->w.cb = w_e_end_csum_rs_req;
mdev->bm_resync_fo = BM_SECT_TO_BIT(sector);
} else if (pi->cmd == P_OV_REPLY) {
atomic_add(size >> 9, &mdev->rs_sect_in);
peer_req->w.cb = w_e_end_ov_reply;
dec_rs_pending(mdev);
goto submit_for_resync;
}
break;
case P_OV_REQUEST:
if (mdev->ov_start_sector == ~(sector_t)0 &&
mdev->tconn->agreed_pro_version >= 90) {
unsigned long now = jiffies;
int i;
mdev->ov_start_sector = sector;
mdev->ov_position = sector;
mdev->ov_left = drbd_bm_bits(mdev) - BM_SECT_TO_BIT(sector);
mdev->rs_total = mdev->ov_left;
for (i = 0; i < DRBD_SYNC_MARKS; i++) {
mdev->rs_mark_left[i] = mdev->ov_left;
mdev->rs_mark_time[i] = now;
}
dev_info(DEV, "Online Verify start sector: %llu\n",
(unsigned long long)sector);
}
peer_req->w.cb = w_e_end_ov_req;
fault_type = DRBD_FAULT_RS_RD;
break;
default:
BUG();
}
if (mdev->state.peer != R_PRIMARY && drbd_rs_should_slow_down(mdev, sector))
schedule_timeout_uninterruptible(HZ/10);
if (drbd_rs_begin_io(mdev, sector))
goto out_free_e;
submit_for_resync:
atomic_add(size >> 9, &mdev->rs_sect_ev);
submit:
inc_unacked(mdev);
spin_lock_irq(&mdev->tconn->req_lock);
list_add_tail(&peer_req->w.list, &mdev->read_ee);
spin_unlock_irq(&mdev->tconn->req_lock);
if (drbd_submit_peer_request(mdev, peer_req, READ, fault_type) == 0)
return 0;
dev_err(DEV, "submit failed, triggering re-connect\n");
spin_lock_irq(&mdev->tconn->req_lock);
list_del(&peer_req->w.list);
spin_unlock_irq(&mdev->tconn->req_lock);
out_free_e:
put_ldev(mdev);
drbd_free_peer_req(mdev, peer_req);
return -EIO;
}
static int drbd_asb_recover_0p(struct drbd_conf *mdev) __must_hold(local)
{
int self, peer, rv = -100;
unsigned long ch_self, ch_peer;
enum drbd_after_sb_p after_sb_0p;
self = mdev->ldev->md.uuid[UI_BITMAP] & 1;
peer = mdev->p_uuid[UI_BITMAP] & 1;
ch_peer = mdev->p_uuid[UI_SIZE];
ch_self = mdev->comm_bm_set;
rcu_read_lock();
after_sb_0p = rcu_dereference(mdev->tconn->net_conf)->after_sb_0p;
rcu_read_unlock();
switch (after_sb_0p) {
case ASB_CONSENSUS:
case ASB_DISCARD_SECONDARY:
case ASB_CALL_HELPER:
case ASB_VIOLENTLY:
dev_err(DEV, "Configuration error.\n");
break;
case ASB_DISCONNECT:
break;
case ASB_DISCARD_YOUNGER_PRI:
if (self == 0 && peer == 1) {
rv = -1;
break;
}
if (self == 1 && peer == 0) {
rv = 1;
break;
}
case ASB_DISCARD_OLDER_PRI:
if (self == 0 && peer == 1) {
rv = 1;
break;
}
if (self == 1 && peer == 0) {
rv = -1;
break;
}
dev_warn(DEV, "Discard younger/older primary did not find a decision\n"
"Using discard-least-changes instead\n");
case ASB_DISCARD_ZERO_CHG:
if (ch_peer == 0 && ch_self == 0) {
rv = test_bit(RESOLVE_CONFLICTS, &mdev->tconn->flags)
? -1 : 1;
break;
} else {
if (ch_peer == 0) { rv = 1; break; }
if (ch_self == 0) { rv = -1; break; }
}
if (after_sb_0p == ASB_DISCARD_ZERO_CHG)
break;
case ASB_DISCARD_LEAST_CHG:
if (ch_self < ch_peer)
rv = -1;
else if (ch_self > ch_peer)
rv = 1;
else
rv = test_bit(RESOLVE_CONFLICTS, &mdev->tconn->flags)
? -1 : 1;
break;
case ASB_DISCARD_LOCAL:
rv = -1;
break;
case ASB_DISCARD_REMOTE:
rv = 1;
}
return rv;
}
static int drbd_asb_recover_1p(struct drbd_conf *mdev) __must_hold(local)
{
int hg, rv = -100;
enum drbd_after_sb_p after_sb_1p;
rcu_read_lock();
after_sb_1p = rcu_dereference(mdev->tconn->net_conf)->after_sb_1p;
rcu_read_unlock();
switch (after_sb_1p) {
case ASB_DISCARD_YOUNGER_PRI:
case ASB_DISCARD_OLDER_PRI:
case ASB_DISCARD_LEAST_CHG:
case ASB_DISCARD_LOCAL:
case ASB_DISCARD_REMOTE:
case ASB_DISCARD_ZERO_CHG:
dev_err(DEV, "Configuration error.\n");
break;
case ASB_DISCONNECT:
break;
case ASB_CONSENSUS:
hg = drbd_asb_recover_0p(mdev);
if (hg == -1 && mdev->state.role == R_SECONDARY)
rv = hg;
if (hg == 1 && mdev->state.role == R_PRIMARY)
rv = hg;
break;
case ASB_VIOLENTLY:
rv = drbd_asb_recover_0p(mdev);
break;
case ASB_DISCARD_SECONDARY:
return mdev->state.role == R_PRIMARY ? 1 : -1;
case ASB_CALL_HELPER:
hg = drbd_asb_recover_0p(mdev);
if (hg == -1 && mdev->state.role == R_PRIMARY) {
enum drbd_state_rv rv2;
drbd_set_role(mdev, R_SECONDARY, 0);
rv2 = drbd_change_state(mdev, CS_VERBOSE, NS(role, R_SECONDARY));
if (rv2 != SS_SUCCESS) {
drbd_khelper(mdev, "pri-lost-after-sb");
} else {
dev_warn(DEV, "Successfully gave up primary role.\n");
rv = hg;
}
} else
rv = hg;
}
return rv;
}
static int drbd_asb_recover_2p(struct drbd_conf *mdev) __must_hold(local)
{
int hg, rv = -100;
enum drbd_after_sb_p after_sb_2p;
rcu_read_lock();
after_sb_2p = rcu_dereference(mdev->tconn->net_conf)->after_sb_2p;
rcu_read_unlock();
switch (after_sb_2p) {
case ASB_DISCARD_YOUNGER_PRI:
case ASB_DISCARD_OLDER_PRI:
case ASB_DISCARD_LEAST_CHG:
case ASB_DISCARD_LOCAL:
case ASB_DISCARD_REMOTE:
case ASB_CONSENSUS:
case ASB_DISCARD_SECONDARY:
case ASB_DISCARD_ZERO_CHG:
dev_err(DEV, "Configuration error.\n");
break;
case ASB_VIOLENTLY:
rv = drbd_asb_recover_0p(mdev);
break;
case ASB_DISCONNECT:
break;
case ASB_CALL_HELPER:
hg = drbd_asb_recover_0p(mdev);
if (hg == -1) {
enum drbd_state_rv rv2;
rv2 = drbd_change_state(mdev, CS_VERBOSE, NS(role, R_SECONDARY));
if (rv2 != SS_SUCCESS) {
drbd_khelper(mdev, "pri-lost-after-sb");
} else {
dev_warn(DEV, "Successfully gave up primary role.\n");
rv = hg;
}
} else
rv = hg;
}
return rv;
}
static void drbd_uuid_dump(struct drbd_conf *mdev, char *text, u64 *uuid,
u64 bits, u64 flags)
{
if (!uuid) {
dev_info(DEV, "%s uuid info vanished while I was looking!\n", text);
return;
}
dev_info(DEV, "%s %016llX:%016llX:%016llX:%016llX bits:%llu flags:%llX\n",
text,
(unsigned long long)uuid[UI_CURRENT],
(unsigned long long)uuid[UI_BITMAP],
(unsigned long long)uuid[UI_HISTORY_START],
(unsigned long long)uuid[UI_HISTORY_END],
(unsigned long long)bits,
(unsigned long long)flags);
}
static int drbd_uuid_compare(struct drbd_conf *mdev, int *rule_nr) __must_hold(local)
{
u64 self, peer;
int i, j;
self = mdev->ldev->md.uuid[UI_CURRENT] & ~((u64)1);
peer = mdev->p_uuid[UI_CURRENT] & ~((u64)1);
*rule_nr = 10;
if (self == UUID_JUST_CREATED && peer == UUID_JUST_CREATED)
return 0;
*rule_nr = 20;
if ((self == UUID_JUST_CREATED || self == (u64)0) &&
peer != UUID_JUST_CREATED)
return -2;
*rule_nr = 30;
if (self != UUID_JUST_CREATED &&
(peer == UUID_JUST_CREATED || peer == (u64)0))
return 2;
if (self == peer) {
int rct, dc;
if (mdev->p_uuid[UI_BITMAP] == (u64)0 && mdev->ldev->md.uuid[UI_BITMAP] != (u64)0) {
if (mdev->tconn->agreed_pro_version < 91)
return -1091;
if ((mdev->ldev->md.uuid[UI_BITMAP] & ~((u64)1)) == (mdev->p_uuid[UI_HISTORY_START] & ~((u64)1)) &&
(mdev->ldev->md.uuid[UI_HISTORY_START] & ~((u64)1)) == (mdev->p_uuid[UI_HISTORY_START + 1] & ~((u64)1))) {
dev_info(DEV, "was SyncSource, missed the resync finished event, corrected myself:\n");
drbd_uuid_move_history(mdev);
mdev->ldev->md.uuid[UI_HISTORY_START] = mdev->ldev->md.uuid[UI_BITMAP];
mdev->ldev->md.uuid[UI_BITMAP] = 0;
drbd_uuid_dump(mdev, "self", mdev->ldev->md.uuid,
mdev->state.disk >= D_NEGOTIATING ? drbd_bm_total_weight(mdev) : 0, 0);
*rule_nr = 34;
} else {
dev_info(DEV, "was SyncSource (peer failed to write sync_uuid)\n");
*rule_nr = 36;
}
return 1;
}
if (mdev->ldev->md.uuid[UI_BITMAP] == (u64)0 && mdev->p_uuid[UI_BITMAP] != (u64)0) {
if (mdev->tconn->agreed_pro_version < 91)
return -1091;
if ((mdev->ldev->md.uuid[UI_HISTORY_START] & ~((u64)1)) == (mdev->p_uuid[UI_BITMAP] & ~((u64)1)) &&
(mdev->ldev->md.uuid[UI_HISTORY_START + 1] & ~((u64)1)) == (mdev->p_uuid[UI_HISTORY_START] & ~((u64)1))) {
dev_info(DEV, "was SyncTarget, peer missed the resync finished event, corrected peer:\n");
mdev->p_uuid[UI_HISTORY_START + 1] = mdev->p_uuid[UI_HISTORY_START];
mdev->p_uuid[UI_HISTORY_START] = mdev->p_uuid[UI_BITMAP];
mdev->p_uuid[UI_BITMAP] = 0UL;
drbd_uuid_dump(mdev, "peer", mdev->p_uuid, mdev->p_uuid[UI_SIZE], mdev->p_uuid[UI_FLAGS]);
*rule_nr = 35;
} else {
dev_info(DEV, "was SyncTarget (failed to write sync_uuid)\n");
*rule_nr = 37;
}
return -1;
}
rct = (test_bit(CRASHED_PRIMARY, &mdev->flags) ? 1 : 0) +
(mdev->p_uuid[UI_FLAGS] & 2);
*rule_nr = 40;
switch (rct) {
case 0: return 0;
case 1: return 1;
case 2: return -1;
case 3:
dc = test_bit(RESOLVE_CONFLICTS, &mdev->tconn->flags);
return dc ? -1 : 1;
}
}
*rule_nr = 50;
peer = mdev->p_uuid[UI_BITMAP] & ~((u64)1);
if (self == peer)
return -1;
*rule_nr = 51;
peer = mdev->p_uuid[UI_HISTORY_START] & ~((u64)1);
if (self == peer) {
if (mdev->tconn->agreed_pro_version < 96 ?
(mdev->ldev->md.uuid[UI_HISTORY_START] & ~((u64)1)) ==
(mdev->p_uuid[UI_HISTORY_START + 1] & ~((u64)1)) :
peer + UUID_NEW_BM_OFFSET == (mdev->p_uuid[UI_BITMAP] & ~((u64)1))) {
if (mdev->tconn->agreed_pro_version < 91)
return -1091;
mdev->p_uuid[UI_BITMAP] = mdev->p_uuid[UI_HISTORY_START];
mdev->p_uuid[UI_HISTORY_START] = mdev->p_uuid[UI_HISTORY_START + 1];
dev_info(DEV, "Lost last syncUUID packet, corrected:\n");
drbd_uuid_dump(mdev, "peer", mdev->p_uuid, mdev->p_uuid[UI_SIZE], mdev->p_uuid[UI_FLAGS]);
return -1;
}
}
*rule_nr = 60;
self = mdev->ldev->md.uuid[UI_CURRENT] & ~((u64)1);
for (i = UI_HISTORY_START; i <= UI_HISTORY_END; i++) {
peer = mdev->p_uuid[i] & ~((u64)1);
if (self == peer)
return -2;
}
*rule_nr = 70;
self = mdev->ldev->md.uuid[UI_BITMAP] & ~((u64)1);
peer = mdev->p_uuid[UI_CURRENT] & ~((u64)1);
if (self == peer)
return 1;
*rule_nr = 71;
self = mdev->ldev->md.uuid[UI_HISTORY_START] & ~((u64)1);
if (self == peer) {
if (mdev->tconn->agreed_pro_version < 96 ?
(mdev->ldev->md.uuid[UI_HISTORY_START + 1] & ~((u64)1)) ==
(mdev->p_uuid[UI_HISTORY_START] & ~((u64)1)) :
self + UUID_NEW_BM_OFFSET == (mdev->ldev->md.uuid[UI_BITMAP] & ~((u64)1))) {
if (mdev->tconn->agreed_pro_version < 91)
return -1091;
__drbd_uuid_set(mdev, UI_BITMAP, mdev->ldev->md.uuid[UI_HISTORY_START]);
__drbd_uuid_set(mdev, UI_HISTORY_START, mdev->ldev->md.uuid[UI_HISTORY_START + 1]);
dev_info(DEV, "Last syncUUID did not get through, corrected:\n");
drbd_uuid_dump(mdev, "self", mdev->ldev->md.uuid,
mdev->state.disk >= D_NEGOTIATING ? drbd_bm_total_weight(mdev) : 0, 0);
return 1;
}
}
*rule_nr = 80;
peer = mdev->p_uuid[UI_CURRENT] & ~((u64)1);
for (i = UI_HISTORY_START; i <= UI_HISTORY_END; i++) {
self = mdev->ldev->md.uuid[i] & ~((u64)1);
if (self == peer)
return 2;
}
*rule_nr = 90;
self = mdev->ldev->md.uuid[UI_BITMAP] & ~((u64)1);
peer = mdev->p_uuid[UI_BITMAP] & ~((u64)1);
if (self == peer && self != ((u64)0))
return 100;
*rule_nr = 100;
for (i = UI_HISTORY_START; i <= UI_HISTORY_END; i++) {
self = mdev->ldev->md.uuid[i] & ~((u64)1);
for (j = UI_HISTORY_START; j <= UI_HISTORY_END; j++) {
peer = mdev->p_uuid[j] & ~((u64)1);
if (self == peer)
return -100;
}
}
return -1000;
}
static enum drbd_conns drbd_sync_handshake(struct drbd_conf *mdev, enum drbd_role peer_role,
enum drbd_disk_state peer_disk) __must_hold(local)
{
enum drbd_conns rv = C_MASK;
enum drbd_disk_state mydisk;
struct net_conf *nc;
int hg, rule_nr, rr_conflict, tentative;
mydisk = mdev->state.disk;
if (mydisk == D_NEGOTIATING)
mydisk = mdev->new_state_tmp.disk;
dev_info(DEV, "drbd_sync_handshake:\n");
spin_lock_irq(&mdev->ldev->md.uuid_lock);
drbd_uuid_dump(mdev, "self", mdev->ldev->md.uuid, mdev->comm_bm_set, 0);
drbd_uuid_dump(mdev, "peer", mdev->p_uuid,
mdev->p_uuid[UI_SIZE], mdev->p_uuid[UI_FLAGS]);
hg = drbd_uuid_compare(mdev, &rule_nr);
spin_unlock_irq(&mdev->ldev->md.uuid_lock);
dev_info(DEV, "uuid_compare()=%d by rule %d\n", hg, rule_nr);
if (hg == -1000) {
dev_alert(DEV, "Unrelated data, aborting!\n");
return C_MASK;
}
if (hg < -1000) {
dev_alert(DEV, "To resolve this both sides have to support at least protocol %d\n", -hg - 1000);
return C_MASK;
}
if ((mydisk == D_INCONSISTENT && peer_disk > D_INCONSISTENT) ||
(peer_disk == D_INCONSISTENT && mydisk > D_INCONSISTENT)) {
int f = (hg == -100) || abs(hg) == 2;
hg = mydisk > D_INCONSISTENT ? 1 : -1;
if (f)
hg = hg*2;
dev_info(DEV, "Becoming sync %s due to disk states.\n",
hg > 0 ? "source" : "target");
}
if (abs(hg) == 100)
drbd_khelper(mdev, "initial-split-brain");
rcu_read_lock();
nc = rcu_dereference(mdev->tconn->net_conf);
if (hg == 100 || (hg == -100 && nc->always_asbp)) {
int pcount = (mdev->state.role == R_PRIMARY)
+ (peer_role == R_PRIMARY);
int forced = (hg == -100);
switch (pcount) {
case 0:
hg = drbd_asb_recover_0p(mdev);
break;
case 1:
hg = drbd_asb_recover_1p(mdev);
break;
case 2:
hg = drbd_asb_recover_2p(mdev);
break;
}
if (abs(hg) < 100) {
dev_warn(DEV, "Split-Brain detected, %d primaries, "
"automatically solved. Sync from %s node\n",
pcount, (hg < 0) ? "peer" : "this");
if (forced) {
dev_warn(DEV, "Doing a full sync, since"
" UUIDs where ambiguous.\n");
hg = hg*2;
}
}
}
if (hg == -100) {
if (test_bit(DISCARD_MY_DATA, &mdev->flags) && !(mdev->p_uuid[UI_FLAGS]&1))
hg = -1;
if (!test_bit(DISCARD_MY_DATA, &mdev->flags) && (mdev->p_uuid[UI_FLAGS]&1))
hg = 1;
if (abs(hg) < 100)
dev_warn(DEV, "Split-Brain detected, manually solved. "
"Sync from %s node\n",
(hg < 0) ? "peer" : "this");
}
rr_conflict = nc->rr_conflict;
tentative = nc->tentative;
rcu_read_unlock();
if (hg == -100) {
dev_alert(DEV, "Split-Brain detected but unresolved, dropping connection!\n");
drbd_khelper(mdev, "split-brain");
return C_MASK;
}
if (hg > 0 && mydisk <= D_INCONSISTENT) {
dev_err(DEV, "I shall become SyncSource, but I am inconsistent!\n");
return C_MASK;
}
if (hg < 0 &&
mdev->state.role == R_PRIMARY && mdev->state.disk >= D_CONSISTENT) {
switch (rr_conflict) {
case ASB_CALL_HELPER:
drbd_khelper(mdev, "pri-lost");
case ASB_DISCONNECT:
dev_err(DEV, "I shall become SyncTarget, but I am primary!\n");
return C_MASK;
case ASB_VIOLENTLY:
dev_warn(DEV, "Becoming SyncTarget, violating the stable-data"
"assumption\n");
}
}
if (tentative || test_bit(CONN_DRY_RUN, &mdev->tconn->flags)) {
if (hg == 0)
dev_info(DEV, "dry-run connect: No resync, would become Connected immediately.\n");
else
dev_info(DEV, "dry-run connect: Would become %s, doing a %s resync.",
drbd_conn_str(hg > 0 ? C_SYNC_SOURCE : C_SYNC_TARGET),
abs(hg) >= 2 ? "full" : "bit-map based");
return C_MASK;
}
if (abs(hg) >= 2) {
dev_info(DEV, "Writing the whole bitmap, full sync required after drbd_sync_handshake.\n");
if (drbd_bitmap_io(mdev, &drbd_bmio_set_n_write, "set_n_write from sync_handshake",
BM_LOCKED_SET_ALLOWED))
return C_MASK;
}
if (hg > 0) {
rv = C_WF_BITMAP_S;
} else if (hg < 0) {
rv = C_WF_BITMAP_T;
} else {
rv = C_CONNECTED;
if (drbd_bm_total_weight(mdev)) {
dev_info(DEV, "No resync, but %lu bits in bitmap!\n",
drbd_bm_total_weight(mdev));
}
}
return rv;
}
static enum drbd_after_sb_p convert_after_sb(enum drbd_after_sb_p peer)
{
if (peer == ASB_DISCARD_REMOTE)
return ASB_DISCARD_LOCAL;
if (peer == ASB_DISCARD_LOCAL)
return ASB_DISCARD_REMOTE;
return peer;
}
static int receive_protocol(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct p_protocol *p = pi->data;
enum drbd_after_sb_p p_after_sb_0p, p_after_sb_1p, p_after_sb_2p;
int p_proto, p_discard_my_data, p_two_primaries, cf;
struct net_conf *nc, *old_net_conf, *new_net_conf = NULL;
char integrity_alg[SHARED_SECRET_MAX] = "";
struct crypto_hash *peer_integrity_tfm = NULL;
void *int_dig_in = NULL, *int_dig_vv = NULL;
p_proto = be32_to_cpu(p->protocol);
p_after_sb_0p = be32_to_cpu(p->after_sb_0p);
p_after_sb_1p = be32_to_cpu(p->after_sb_1p);
p_after_sb_2p = be32_to_cpu(p->after_sb_2p);
p_two_primaries = be32_to_cpu(p->two_primaries);
cf = be32_to_cpu(p->conn_flags);
p_discard_my_data = cf & CF_DISCARD_MY_DATA;
if (tconn->agreed_pro_version >= 87) {
int err;
if (pi->size > sizeof(integrity_alg))
return -EIO;
err = drbd_recv_all(tconn, integrity_alg, pi->size);
if (err)
return err;
integrity_alg[SHARED_SECRET_MAX - 1] = 0;
}
if (pi->cmd != P_PROTOCOL_UPDATE) {
clear_bit(CONN_DRY_RUN, &tconn->flags);
if (cf & CF_DRY_RUN)
set_bit(CONN_DRY_RUN, &tconn->flags);
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
if (p_proto != nc->wire_protocol) {
conn_err(tconn, "incompatible %s settings\n", "protocol");
goto disconnect_rcu_unlock;
}
if (convert_after_sb(p_after_sb_0p) != nc->after_sb_0p) {
conn_err(tconn, "incompatible %s settings\n", "after-sb-0pri");
goto disconnect_rcu_unlock;
}
if (convert_after_sb(p_after_sb_1p) != nc->after_sb_1p) {
conn_err(tconn, "incompatible %s settings\n", "after-sb-1pri");
goto disconnect_rcu_unlock;
}
if (convert_after_sb(p_after_sb_2p) != nc->after_sb_2p) {
conn_err(tconn, "incompatible %s settings\n", "after-sb-2pri");
goto disconnect_rcu_unlock;
}
if (p_discard_my_data && nc->discard_my_data) {
conn_err(tconn, "incompatible %s settings\n", "discard-my-data");
goto disconnect_rcu_unlock;
}
if (p_two_primaries != nc->two_primaries) {
conn_err(tconn, "incompatible %s settings\n", "allow-two-primaries");
goto disconnect_rcu_unlock;
}
if (strcmp(integrity_alg, nc->integrity_alg)) {
conn_err(tconn, "incompatible %s settings\n", "data-integrity-alg");
goto disconnect_rcu_unlock;
}
rcu_read_unlock();
}
if (integrity_alg[0]) {
int hash_size;
peer_integrity_tfm = crypto_alloc_hash(integrity_alg, 0, CRYPTO_ALG_ASYNC);
if (!peer_integrity_tfm) {
conn_err(tconn, "peer data-integrity-alg %s not supported\n",
integrity_alg);
goto disconnect;
}
hash_size = crypto_hash_digestsize(peer_integrity_tfm);
int_dig_in = kmalloc(hash_size, GFP_KERNEL);
int_dig_vv = kmalloc(hash_size, GFP_KERNEL);
if (!(int_dig_in && int_dig_vv)) {
conn_err(tconn, "Allocation of buffers for data integrity checking failed\n");
goto disconnect;
}
}
new_net_conf = kmalloc(sizeof(struct net_conf), GFP_KERNEL);
if (!new_net_conf) {
conn_err(tconn, "Allocation of new net_conf failed\n");
goto disconnect;
}
mutex_lock(&tconn->data.mutex);
mutex_lock(&tconn->conf_update);
old_net_conf = tconn->net_conf;
*new_net_conf = *old_net_conf;
new_net_conf->wire_protocol = p_proto;
new_net_conf->after_sb_0p = convert_after_sb(p_after_sb_0p);
new_net_conf->after_sb_1p = convert_after_sb(p_after_sb_1p);
new_net_conf->after_sb_2p = convert_after_sb(p_after_sb_2p);
new_net_conf->two_primaries = p_two_primaries;
rcu_assign_pointer(tconn->net_conf, new_net_conf);
mutex_unlock(&tconn->conf_update);
mutex_unlock(&tconn->data.mutex);
crypto_free_hash(tconn->peer_integrity_tfm);
kfree(tconn->int_dig_in);
kfree(tconn->int_dig_vv);
tconn->peer_integrity_tfm = peer_integrity_tfm;
tconn->int_dig_in = int_dig_in;
tconn->int_dig_vv = int_dig_vv;
if (strcmp(old_net_conf->integrity_alg, integrity_alg))
conn_info(tconn, "peer data-integrity-alg: %s\n",
integrity_alg[0] ? integrity_alg : "(none)");
synchronize_rcu();
kfree(old_net_conf);
return 0;
disconnect_rcu_unlock:
rcu_read_unlock();
disconnect:
crypto_free_hash(peer_integrity_tfm);
kfree(int_dig_in);
kfree(int_dig_vv);
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
return -EIO;
}
struct crypto_hash *drbd_crypto_alloc_digest_safe(const struct drbd_conf *mdev,
const char *alg, const char *name)
{
struct crypto_hash *tfm;
if (!alg[0])
return NULL;
tfm = crypto_alloc_hash(alg, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm)) {
dev_err(DEV, "Can not allocate \"%s\" as %s (reason: %ld)\n",
alg, name, PTR_ERR(tfm));
return tfm;
}
return tfm;
}
static int ignore_remaining_packet(struct drbd_tconn *tconn, struct packet_info *pi)
{
void *buffer = tconn->data.rbuf;
int size = pi->size;
while (size) {
int s = min_t(int, size, DRBD_SOCKET_BUFFER_SIZE);
s = drbd_recv(tconn, buffer, s);
if (s <= 0) {
if (s < 0)
return s;
break;
}
size -= s;
}
if (size)
return -EIO;
return 0;
}
static int config_unknown_volume(struct drbd_tconn *tconn, struct packet_info *pi)
{
conn_warn(tconn, "%s packet received for volume %u, which is not configured locally\n",
cmdname(pi->cmd), pi->vnr);
return ignore_remaining_packet(tconn, pi);
}
static int receive_SyncParam(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_rs_param_95 *p;
unsigned int header_size, data_size, exp_max_sz;
struct crypto_hash *verify_tfm = NULL;
struct crypto_hash *csums_tfm = NULL;
struct net_conf *old_net_conf, *new_net_conf = NULL;
struct disk_conf *old_disk_conf = NULL, *new_disk_conf = NULL;
const int apv = tconn->agreed_pro_version;
struct fifo_buffer *old_plan = NULL, *new_plan = NULL;
int fifo_size = 0;
int err;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return config_unknown_volume(tconn, pi);
exp_max_sz = apv <= 87 ? sizeof(struct p_rs_param)
: apv == 88 ? sizeof(struct p_rs_param)
+ SHARED_SECRET_MAX
: apv <= 94 ? sizeof(struct p_rs_param_89)
: sizeof(struct p_rs_param_95);
if (pi->size > exp_max_sz) {
dev_err(DEV, "SyncParam packet too long: received %u, expected <= %u bytes\n",
pi->size, exp_max_sz);
return -EIO;
}
if (apv <= 88) {
header_size = sizeof(struct p_rs_param);
data_size = pi->size - header_size;
} else if (apv <= 94) {
header_size = sizeof(struct p_rs_param_89);
data_size = pi->size - header_size;
D_ASSERT(data_size == 0);
} else {
header_size = sizeof(struct p_rs_param_95);
data_size = pi->size - header_size;
D_ASSERT(data_size == 0);
}
p = pi->data;
memset(p->verify_alg, 0, 2 * SHARED_SECRET_MAX);
err = drbd_recv_all(mdev->tconn, p, header_size);
if (err)
return err;
mutex_lock(&mdev->tconn->conf_update);
old_net_conf = mdev->tconn->net_conf;
if (get_ldev(mdev)) {
new_disk_conf = kzalloc(sizeof(struct disk_conf), GFP_KERNEL);
if (!new_disk_conf) {
put_ldev(mdev);
mutex_unlock(&mdev->tconn->conf_update);
dev_err(DEV, "Allocation of new disk_conf failed\n");
return -ENOMEM;
}
old_disk_conf = mdev->ldev->disk_conf;
*new_disk_conf = *old_disk_conf;
new_disk_conf->resync_rate = be32_to_cpu(p->resync_rate);
}
if (apv >= 88) {
if (apv == 88) {
if (data_size > SHARED_SECRET_MAX || data_size == 0) {
dev_err(DEV, "verify-alg of wrong size, "
"peer wants %u, accepting only up to %u byte\n",
data_size, SHARED_SECRET_MAX);
err = -EIO;
goto reconnect;
}
err = drbd_recv_all(mdev->tconn, p->verify_alg, data_size);
if (err)
goto reconnect;
D_ASSERT(p->verify_alg[data_size-1] == 0);
p->verify_alg[data_size-1] = 0;
} else {
D_ASSERT(p->verify_alg[SHARED_SECRET_MAX-1] == 0);
D_ASSERT(p->csums_alg[SHARED_SECRET_MAX-1] == 0);
p->verify_alg[SHARED_SECRET_MAX-1] = 0;
p->csums_alg[SHARED_SECRET_MAX-1] = 0;
}
if (strcmp(old_net_conf->verify_alg, p->verify_alg)) {
if (mdev->state.conn == C_WF_REPORT_PARAMS) {
dev_err(DEV, "Different verify-alg settings. me=\"%s\" peer=\"%s\"\n",
old_net_conf->verify_alg, p->verify_alg);
goto disconnect;
}
verify_tfm = drbd_crypto_alloc_digest_safe(mdev,
p->verify_alg, "verify-alg");
if (IS_ERR(verify_tfm)) {
verify_tfm = NULL;
goto disconnect;
}
}
if (apv >= 89 && strcmp(old_net_conf->csums_alg, p->csums_alg)) {
if (mdev->state.conn == C_WF_REPORT_PARAMS) {
dev_err(DEV, "Different csums-alg settings. me=\"%s\" peer=\"%s\"\n",
old_net_conf->csums_alg, p->csums_alg);
goto disconnect;
}
csums_tfm = drbd_crypto_alloc_digest_safe(mdev,
p->csums_alg, "csums-alg");
if (IS_ERR(csums_tfm)) {
csums_tfm = NULL;
goto disconnect;
}
}
if (apv > 94 && new_disk_conf) {
new_disk_conf->c_plan_ahead = be32_to_cpu(p->c_plan_ahead);
new_disk_conf->c_delay_target = be32_to_cpu(p->c_delay_target);
new_disk_conf->c_fill_target = be32_to_cpu(p->c_fill_target);
new_disk_conf->c_max_rate = be32_to_cpu(p->c_max_rate);
fifo_size = (new_disk_conf->c_plan_ahead * 10 * SLEEP_TIME) / HZ;
if (fifo_size != mdev->rs_plan_s->size) {
new_plan = fifo_alloc(fifo_size);
if (!new_plan) {
dev_err(DEV, "kmalloc of fifo_buffer failed");
put_ldev(mdev);
goto disconnect;
}
}
}
if (verify_tfm || csums_tfm) {
new_net_conf = kzalloc(sizeof(struct net_conf), GFP_KERNEL);
if (!new_net_conf) {
dev_err(DEV, "Allocation of new net_conf failed\n");
goto disconnect;
}
*new_net_conf = *old_net_conf;
if (verify_tfm) {
strcpy(new_net_conf->verify_alg, p->verify_alg);
new_net_conf->verify_alg_len = strlen(p->verify_alg) + 1;
crypto_free_hash(mdev->tconn->verify_tfm);
mdev->tconn->verify_tfm = verify_tfm;
dev_info(DEV, "using verify-alg: \"%s\"\n", p->verify_alg);
}
if (csums_tfm) {
strcpy(new_net_conf->csums_alg, p->csums_alg);
new_net_conf->csums_alg_len = strlen(p->csums_alg) + 1;
crypto_free_hash(mdev->tconn->csums_tfm);
mdev->tconn->csums_tfm = csums_tfm;
dev_info(DEV, "using csums-alg: \"%s\"\n", p->csums_alg);
}
rcu_assign_pointer(tconn->net_conf, new_net_conf);
}
}
if (new_disk_conf) {
rcu_assign_pointer(mdev->ldev->disk_conf, new_disk_conf);
put_ldev(mdev);
}
if (new_plan) {
old_plan = mdev->rs_plan_s;
rcu_assign_pointer(mdev->rs_plan_s, new_plan);
}
mutex_unlock(&mdev->tconn->conf_update);
synchronize_rcu();
if (new_net_conf)
kfree(old_net_conf);
kfree(old_disk_conf);
kfree(old_plan);
return 0;
reconnect:
if (new_disk_conf) {
put_ldev(mdev);
kfree(new_disk_conf);
}
mutex_unlock(&mdev->tconn->conf_update);
return -EIO;
disconnect:
kfree(new_plan);
if (new_disk_conf) {
put_ldev(mdev);
kfree(new_disk_conf);
}
mutex_unlock(&mdev->tconn->conf_update);
crypto_free_hash(csums_tfm);
crypto_free_hash(verify_tfm);
conn_request_state(mdev->tconn, NS(conn, C_DISCONNECTING), CS_HARD);
return -EIO;
}
static void warn_if_differ_considerably(struct drbd_conf *mdev,
const char *s, sector_t a, sector_t b)
{
sector_t d;
if (a == 0 || b == 0)
return;
d = (a > b) ? (a - b) : (b - a);
if (d > (a>>3) || d > (b>>3))
dev_warn(DEV, "Considerable difference in %s: %llus vs. %llus\n", s,
(unsigned long long)a, (unsigned long long)b);
}
static int receive_sizes(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_sizes *p = pi->data;
enum determine_dev_size dd = unchanged;
sector_t p_size, p_usize, my_usize;
int ldsc = 0;
enum dds_flags ddsf;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return config_unknown_volume(tconn, pi);
p_size = be64_to_cpu(p->d_size);
p_usize = be64_to_cpu(p->u_size);
mdev->p_size = p_size;
if (get_ldev(mdev)) {
rcu_read_lock();
my_usize = rcu_dereference(mdev->ldev->disk_conf)->disk_size;
rcu_read_unlock();
warn_if_differ_considerably(mdev, "lower level device sizes",
p_size, drbd_get_max_capacity(mdev->ldev));
warn_if_differ_considerably(mdev, "user requested size",
p_usize, my_usize);
if (mdev->state.conn == C_WF_REPORT_PARAMS)
p_usize = min_not_zero(my_usize, p_usize);
if (drbd_new_dev_size(mdev, mdev->ldev, p_usize, 0) <
drbd_get_capacity(mdev->this_bdev) &&
mdev->state.disk >= D_OUTDATED &&
mdev->state.conn < C_CONNECTED) {
dev_err(DEV, "The peer's disk size is too small!\n");
conn_request_state(mdev->tconn, NS(conn, C_DISCONNECTING), CS_HARD);
put_ldev(mdev);
return -EIO;
}
if (my_usize != p_usize) {
struct disk_conf *old_disk_conf, *new_disk_conf = NULL;
new_disk_conf = kzalloc(sizeof(struct disk_conf), GFP_KERNEL);
if (!new_disk_conf) {
dev_err(DEV, "Allocation of new disk_conf failed\n");
put_ldev(mdev);
return -ENOMEM;
}
mutex_lock(&mdev->tconn->conf_update);
old_disk_conf = mdev->ldev->disk_conf;
*new_disk_conf = *old_disk_conf;
new_disk_conf->disk_size = p_usize;
rcu_assign_pointer(mdev->ldev->disk_conf, new_disk_conf);
mutex_unlock(&mdev->tconn->conf_update);
synchronize_rcu();
kfree(old_disk_conf);
dev_info(DEV, "Peer sets u_size to %lu sectors\n",
(unsigned long)my_usize);
}
put_ldev(mdev);
}
ddsf = be16_to_cpu(p->dds_flags);
if (get_ldev(mdev)) {
dd = drbd_determine_dev_size(mdev, ddsf);
put_ldev(mdev);
if (dd == dev_size_error)
return -EIO;
drbd_md_sync(mdev);
} else {
drbd_set_my_capacity(mdev, p_size);
}
mdev->peer_max_bio_size = be32_to_cpu(p->max_bio_size);
drbd_reconsider_max_bio_size(mdev);
if (get_ldev(mdev)) {
if (mdev->ldev->known_size != drbd_get_capacity(mdev->ldev->backing_bdev)) {
mdev->ldev->known_size = drbd_get_capacity(mdev->ldev->backing_bdev);
ldsc = 1;
}
put_ldev(mdev);
}
if (mdev->state.conn > C_WF_REPORT_PARAMS) {
if (be64_to_cpu(p->c_size) !=
drbd_get_capacity(mdev->this_bdev) || ldsc) {
drbd_send_sizes(mdev, 0, ddsf);
}
if (test_and_clear_bit(RESIZE_PENDING, &mdev->flags) ||
(dd == grew && mdev->state.conn == C_CONNECTED)) {
if (mdev->state.pdsk >= D_INCONSISTENT &&
mdev->state.disk >= D_INCONSISTENT) {
if (ddsf & DDSF_NO_RESYNC)
dev_info(DEV, "Resync of new storage suppressed with --assume-clean\n");
else
resync_after_online_grow(mdev);
} else
set_bit(RESYNC_AFTER_NEG, &mdev->flags);
}
}
return 0;
}
static int receive_uuids(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_uuids *p = pi->data;
u64 *p_uuid;
int i, updated_uuids = 0;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return config_unknown_volume(tconn, pi);
p_uuid = kmalloc(sizeof(u64)*UI_EXTENDED_SIZE, GFP_NOIO);
if (!p_uuid) {
dev_err(DEV, "kmalloc of p_uuid failed\n");
return false;
}
for (i = UI_CURRENT; i < UI_EXTENDED_SIZE; i++)
p_uuid[i] = be64_to_cpu(p->uuid[i]);
kfree(mdev->p_uuid);
mdev->p_uuid = p_uuid;
if (mdev->state.conn < C_CONNECTED &&
mdev->state.disk < D_INCONSISTENT &&
mdev->state.role == R_PRIMARY &&
(mdev->ed_uuid & ~((u64)1)) != (p_uuid[UI_CURRENT] & ~((u64)1))) {
dev_err(DEV, "Can only connect to data with current UUID=%016llX\n",
(unsigned long long)mdev->ed_uuid);
conn_request_state(mdev->tconn, NS(conn, C_DISCONNECTING), CS_HARD);
return -EIO;
}
if (get_ldev(mdev)) {
int skip_initial_sync =
mdev->state.conn == C_CONNECTED &&
mdev->tconn->agreed_pro_version >= 90 &&
mdev->ldev->md.uuid[UI_CURRENT] == UUID_JUST_CREATED &&
(p_uuid[UI_FLAGS] & 8);
if (skip_initial_sync) {
dev_info(DEV, "Accepted new current UUID, preparing to skip initial sync\n");
drbd_bitmap_io(mdev, &drbd_bmio_clear_n_write,
"clear_n_write from receive_uuids",
BM_LOCKED_TEST_ALLOWED);
_drbd_uuid_set(mdev, UI_CURRENT, p_uuid[UI_CURRENT]);
_drbd_uuid_set(mdev, UI_BITMAP, 0);
_drbd_set_state(_NS2(mdev, disk, D_UP_TO_DATE, pdsk, D_UP_TO_DATE),
CS_VERBOSE, NULL);
drbd_md_sync(mdev);
updated_uuids = 1;
}
put_ldev(mdev);
} else if (mdev->state.disk < D_INCONSISTENT &&
mdev->state.role == R_PRIMARY) {
updated_uuids = drbd_set_ed_uuid(mdev, p_uuid[UI_CURRENT]);
}
mutex_lock(mdev->state_mutex);
mutex_unlock(mdev->state_mutex);
if (mdev->state.conn >= C_CONNECTED && mdev->state.disk < D_INCONSISTENT)
updated_uuids |= drbd_set_ed_uuid(mdev, p_uuid[UI_CURRENT]);
if (updated_uuids)
drbd_print_uuids(mdev, "receiver updated UUIDs to");
return 0;
}
static union drbd_state convert_state(union drbd_state ps)
{
union drbd_state ms;
static enum drbd_conns c_tab[] = {
[C_WF_REPORT_PARAMS] = C_WF_REPORT_PARAMS,
[C_CONNECTED] = C_CONNECTED,
[C_STARTING_SYNC_S] = C_STARTING_SYNC_T,
[C_STARTING_SYNC_T] = C_STARTING_SYNC_S,
[C_DISCONNECTING] = C_TEAR_DOWN,
[C_VERIFY_S] = C_VERIFY_T,
[C_MASK] = C_MASK,
};
ms.i = ps.i;
ms.conn = c_tab[ps.conn];
ms.peer = ps.role;
ms.role = ps.peer;
ms.pdsk = ps.disk;
ms.disk = ps.pdsk;
ms.peer_isp = (ps.aftr_isp | ps.user_isp);
return ms;
}
static int receive_req_state(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_req_state *p = pi->data;
union drbd_state mask, val;
enum drbd_state_rv rv;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
mask.i = be32_to_cpu(p->mask);
val.i = be32_to_cpu(p->val);
if (test_bit(RESOLVE_CONFLICTS, &mdev->tconn->flags) &&
mutex_is_locked(mdev->state_mutex)) {
drbd_send_sr_reply(mdev, SS_CONCURRENT_ST_CHG);
return 0;
}
mask = convert_state(mask);
val = convert_state(val);
rv = drbd_change_state(mdev, CS_VERBOSE, mask, val);
drbd_send_sr_reply(mdev, rv);
drbd_md_sync(mdev);
return 0;
}
static int receive_req_conn_state(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct p_req_state *p = pi->data;
union drbd_state mask, val;
enum drbd_state_rv rv;
mask.i = be32_to_cpu(p->mask);
val.i = be32_to_cpu(p->val);
if (test_bit(RESOLVE_CONFLICTS, &tconn->flags) &&
mutex_is_locked(&tconn->cstate_mutex)) {
conn_send_sr_reply(tconn, SS_CONCURRENT_ST_CHG);
return 0;
}
mask = convert_state(mask);
val = convert_state(val);
rv = conn_request_state(tconn, mask, val, CS_VERBOSE | CS_LOCAL_ONLY | CS_IGN_OUTD_FAIL);
conn_send_sr_reply(tconn, rv);
return 0;
}
static int receive_state(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_state *p = pi->data;
union drbd_state os, ns, peer_state;
enum drbd_disk_state real_peer_disk;
enum chg_state_flags cs_flags;
int rv;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return config_unknown_volume(tconn, pi);
peer_state.i = be32_to_cpu(p->state);
real_peer_disk = peer_state.disk;
if (peer_state.disk == D_NEGOTIATING) {
real_peer_disk = mdev->p_uuid[UI_FLAGS] & 4 ? D_INCONSISTENT : D_CONSISTENT;
dev_info(DEV, "real peer disk state = %s\n", drbd_disk_str(real_peer_disk));
}
spin_lock_irq(&mdev->tconn->req_lock);
retry:
os = ns = drbd_read_state(mdev);
spin_unlock_irq(&mdev->tconn->req_lock);
if (os.conn <= C_TEAR_DOWN)
return -ECONNRESET;
if ((os.pdsk == D_INCONSISTENT || os.pdsk == D_CONSISTENT) &&
real_peer_disk == D_UP_TO_DATE &&
os.conn > C_CONNECTED && os.disk == D_UP_TO_DATE) {
if (peer_state.conn > C_CONNECTED &&
peer_state.conn < C_SYNC_SOURCE)
real_peer_disk = D_INCONSISTENT;
else if (os.conn >= C_SYNC_SOURCE &&
peer_state.conn == C_CONNECTED) {
if (drbd_bm_total_weight(mdev) <= mdev->rs_failed)
drbd_resync_finished(mdev);
return 0;
}
}
if (os.conn == C_VERIFY_T && os.disk == D_UP_TO_DATE &&
peer_state.conn == C_CONNECTED && real_peer_disk == D_UP_TO_DATE) {
ov_out_of_sync_print(mdev);
drbd_resync_finished(mdev);
return 0;
}
if (os.pdsk == D_UP_TO_DATE && real_peer_disk == D_INCONSISTENT &&
os.conn == C_CONNECTED && peer_state.conn > C_SYNC_SOURCE)
real_peer_disk = D_UP_TO_DATE;
if (ns.conn == C_WF_REPORT_PARAMS)
ns.conn = C_CONNECTED;
if (peer_state.conn == C_AHEAD)
ns.conn = C_BEHIND;
if (mdev->p_uuid && peer_state.disk >= D_NEGOTIATING &&
get_ldev_if_state(mdev, D_NEGOTIATING)) {
int cr;
cr = (os.conn < C_CONNECTED);
cr |= (os.conn == C_CONNECTED &&
(peer_state.disk == D_NEGOTIATING ||
os.disk == D_NEGOTIATING));
cr |= test_bit(CONSIDER_RESYNC, &mdev->flags);
cr |= (os.conn == C_CONNECTED &&
(peer_state.conn >= C_STARTING_SYNC_S &&
peer_state.conn <= C_WF_BITMAP_T));
if (cr)
ns.conn = drbd_sync_handshake(mdev, peer_state.role, real_peer_disk);
put_ldev(mdev);
if (ns.conn == C_MASK) {
ns.conn = C_CONNECTED;
if (mdev->state.disk == D_NEGOTIATING) {
drbd_force_state(mdev, NS(disk, D_FAILED));
} else if (peer_state.disk == D_NEGOTIATING) {
dev_err(DEV, "Disk attach process on the peer node was aborted.\n");
peer_state.disk = D_DISKLESS;
real_peer_disk = D_DISKLESS;
} else {
if (test_and_clear_bit(CONN_DRY_RUN, &mdev->tconn->flags))
return -EIO;
D_ASSERT(os.conn == C_WF_REPORT_PARAMS);
conn_request_state(mdev->tconn, NS(conn, C_DISCONNECTING), CS_HARD);
return -EIO;
}
}
}
spin_lock_irq(&mdev->tconn->req_lock);
if (os.i != drbd_read_state(mdev).i)
goto retry;
clear_bit(CONSIDER_RESYNC, &mdev->flags);
ns.peer = peer_state.role;
ns.pdsk = real_peer_disk;
ns.peer_isp = (peer_state.aftr_isp | peer_state.user_isp);
if ((ns.conn == C_CONNECTED || ns.conn == C_WF_BITMAP_S) && ns.disk == D_NEGOTIATING)
ns.disk = mdev->new_state_tmp.disk;
cs_flags = CS_VERBOSE + (os.conn < C_CONNECTED && ns.conn >= C_CONNECTED ? 0 : CS_HARD);
if (ns.pdsk == D_CONSISTENT && drbd_suspended(mdev) && ns.conn == C_CONNECTED && os.conn < C_CONNECTED &&
test_bit(NEW_CUR_UUID, &mdev->flags)) {
spin_unlock_irq(&mdev->tconn->req_lock);
dev_err(DEV, "Aborting Connect, can not thaw IO with an only Consistent peer\n");
tl_clear(mdev->tconn);
drbd_uuid_new_current(mdev);
clear_bit(NEW_CUR_UUID, &mdev->flags);
conn_request_state(mdev->tconn, NS2(conn, C_PROTOCOL_ERROR, susp, 0), CS_HARD);
return -EIO;
}
rv = _drbd_set_state(mdev, ns, cs_flags, NULL);
ns = drbd_read_state(mdev);
spin_unlock_irq(&mdev->tconn->req_lock);
if (rv < SS_SUCCESS) {
conn_request_state(mdev->tconn, NS(conn, C_DISCONNECTING), CS_HARD);
return -EIO;
}
if (os.conn > C_WF_REPORT_PARAMS) {
if (ns.conn > C_CONNECTED && peer_state.conn <= C_CONNECTED &&
peer_state.disk != D_NEGOTIATING ) {
drbd_send_uuids(mdev);
drbd_send_current_state(mdev);
}
}
clear_bit(DISCARD_MY_DATA, &mdev->flags);
drbd_md_sync(mdev);
return 0;
}
static int receive_sync_uuid(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_rs_uuid *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
wait_event(mdev->misc_wait,
mdev->state.conn == C_WF_SYNC_UUID ||
mdev->state.conn == C_BEHIND ||
mdev->state.conn < C_CONNECTED ||
mdev->state.disk < D_NEGOTIATING);
if (get_ldev_if_state(mdev, D_NEGOTIATING)) {
_drbd_uuid_set(mdev, UI_CURRENT, be64_to_cpu(p->uuid));
_drbd_uuid_set(mdev, UI_BITMAP, 0UL);
drbd_print_uuids(mdev, "updated sync uuid");
drbd_start_resync(mdev, C_SYNC_TARGET);
put_ldev(mdev);
} else
dev_err(DEV, "Ignoring SyncUUID packet!\n");
return 0;
}
static int
receive_bitmap_plain(struct drbd_conf *mdev, unsigned int size,
unsigned long *p, struct bm_xfer_ctx *c)
{
unsigned int data_size = DRBD_SOCKET_BUFFER_SIZE -
drbd_header_size(mdev->tconn);
unsigned int num_words = min_t(size_t, data_size / sizeof(*p),
c->bm_words - c->word_offset);
unsigned int want = num_words * sizeof(*p);
int err;
if (want != size) {
dev_err(DEV, "%s:want (%u) != size (%u)\n", __func__, want, size);
return -EIO;
}
if (want == 0)
return 0;
err = drbd_recv_all(mdev->tconn, p, want);
if (err)
return err;
drbd_bm_merge_lel(mdev, c->word_offset, num_words, p);
c->word_offset += num_words;
c->bit_offset = c->word_offset * BITS_PER_LONG;
if (c->bit_offset > c->bm_bits)
c->bit_offset = c->bm_bits;
return 1;
}
static enum drbd_bitmap_code dcbp_get_code(struct p_compressed_bm *p)
{
return (enum drbd_bitmap_code)(p->encoding & 0x0f);
}
static int dcbp_get_start(struct p_compressed_bm *p)
{
return (p->encoding & 0x80) != 0;
}
static int dcbp_get_pad_bits(struct p_compressed_bm *p)
{
return (p->encoding >> 4) & 0x7;
}
static int
recv_bm_rle_bits(struct drbd_conf *mdev,
struct p_compressed_bm *p,
struct bm_xfer_ctx *c,
unsigned int len)
{
struct bitstream bs;
u64 look_ahead;
u64 rl;
u64 tmp;
unsigned long s = c->bit_offset;
unsigned long e;
int toggle = dcbp_get_start(p);
int have;
int bits;
bitstream_init(&bs, p->code, len, dcbp_get_pad_bits(p));
bits = bitstream_get_bits(&bs, &look_ahead, 64);
if (bits < 0)
return -EIO;
for (have = bits; have > 0; s += rl, toggle = !toggle) {
bits = vli_decode_bits(&rl, look_ahead);
if (bits <= 0)
return -EIO;
if (toggle) {
e = s + rl -1;
if (e >= c->bm_bits) {
dev_err(DEV, "bitmap overflow (e:%lu) while decoding bm RLE packet\n", e);
return -EIO;
}
_drbd_bm_set_bits(mdev, s, e);
}
if (have < bits) {
dev_err(DEV, "bitmap decoding error: h:%d b:%d la:0x%08llx l:%u/%u\n",
have, bits, look_ahead,
(unsigned int)(bs.cur.b - p->code),
(unsigned int)bs.buf_len);
return -EIO;
}
look_ahead >>= bits;
have -= bits;
bits = bitstream_get_bits(&bs, &tmp, 64 - have);
if (bits < 0)
return -EIO;
look_ahead |= tmp << have;
have += bits;
}
c->bit_offset = s;
bm_xfer_ctx_bit_to_word_offset(c);
return (s != c->bm_bits);
}
static int
decode_bitmap_c(struct drbd_conf *mdev,
struct p_compressed_bm *p,
struct bm_xfer_ctx *c,
unsigned int len)
{
if (dcbp_get_code(p) == RLE_VLI_Bits)
return recv_bm_rle_bits(mdev, p, c, len - sizeof(*p));
dev_err(DEV, "receive_bitmap_c: unknown encoding %u\n", p->encoding);
conn_request_state(mdev->tconn, NS(conn, C_PROTOCOL_ERROR), CS_HARD);
return -EIO;
}
void INFO_bm_xfer_stats(struct drbd_conf *mdev,
const char *direction, struct bm_xfer_ctx *c)
{
unsigned int header_size = drbd_header_size(mdev->tconn);
unsigned int data_size = DRBD_SOCKET_BUFFER_SIZE - header_size;
unsigned int plain =
header_size * (DIV_ROUND_UP(c->bm_words, data_size) + 1) +
c->bm_words * sizeof(unsigned long);
unsigned int total = c->bytes[0] + c->bytes[1];
unsigned int r;
if (total == 0)
return;
if (total >= plain)
return;
r = (total > UINT_MAX/1000) ? (total / (plain/1000))
: (1000 * total / plain);
if (r > 1000)
r = 1000;
r = 1000 - r;
dev_info(DEV, "%s bitmap stats [Bytes(packets)]: plain %u(%u), RLE %u(%u), "
"total %u; compression: %u.%u%%\n",
direction,
c->bytes[1], c->packets[1],
c->bytes[0], c->packets[0],
total, r/10, r % 10);
}
static int receive_bitmap(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct bm_xfer_ctx c;
int err;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
drbd_bm_lock(mdev, "receive bitmap", BM_LOCKED_SET_ALLOWED);
c = (struct bm_xfer_ctx) {
.bm_bits = drbd_bm_bits(mdev),
.bm_words = drbd_bm_words(mdev),
};
for(;;) {
if (pi->cmd == P_BITMAP)
err = receive_bitmap_plain(mdev, pi->size, pi->data, &c);
else if (pi->cmd == P_COMPRESSED_BITMAP) {
struct p_compressed_bm *p = pi->data;
if (pi->size > DRBD_SOCKET_BUFFER_SIZE - drbd_header_size(tconn)) {
dev_err(DEV, "ReportCBitmap packet too large\n");
err = -EIO;
goto out;
}
if (pi->size <= sizeof(*p)) {
dev_err(DEV, "ReportCBitmap packet too small (l:%u)\n", pi->size);
err = -EIO;
goto out;
}
err = drbd_recv_all(mdev->tconn, p, pi->size);
if (err)
goto out;
err = decode_bitmap_c(mdev, p, &c, pi->size);
} else {
dev_warn(DEV, "receive_bitmap: cmd neither ReportBitMap nor ReportCBitMap (is 0x%x)", pi->cmd);
err = -EIO;
goto out;
}
c.packets[pi->cmd == P_BITMAP]++;
c.bytes[pi->cmd == P_BITMAP] += drbd_header_size(tconn) + pi->size;
if (err <= 0) {
if (err < 0)
goto out;
break;
}
err = drbd_recv_header(mdev->tconn, pi);
if (err)
goto out;
}
INFO_bm_xfer_stats(mdev, "receive", &c);
if (mdev->state.conn == C_WF_BITMAP_T) {
enum drbd_state_rv rv;
err = drbd_send_bitmap(mdev);
if (err)
goto out;
rv = _drbd_request_state(mdev, NS(conn, C_WF_SYNC_UUID), CS_VERBOSE);
D_ASSERT(rv == SS_SUCCESS);
} else if (mdev->state.conn != C_WF_BITMAP_S) {
dev_info(DEV, "unexpected cstate (%s) in receive_bitmap\n",
drbd_conn_str(mdev->state.conn));
}
err = 0;
out:
drbd_bm_unlock(mdev);
if (!err && mdev->state.conn == C_WF_BITMAP_S)
drbd_start_resync(mdev, C_SYNC_SOURCE);
return err;
}
static int receive_skip(struct drbd_tconn *tconn, struct packet_info *pi)
{
conn_warn(tconn, "skipping unknown optional packet type %d, l: %d!\n",
pi->cmd, pi->size);
return ignore_remaining_packet(tconn, pi);
}
static int receive_UnplugRemote(struct drbd_tconn *tconn, struct packet_info *pi)
{
drbd_tcp_quickack(tconn->data.socket);
return 0;
}
static int receive_out_of_sync(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_desc *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
switch (mdev->state.conn) {
case C_WF_SYNC_UUID:
case C_WF_BITMAP_T:
case C_BEHIND:
break;
default:
dev_err(DEV, "ASSERT FAILED cstate = %s, expected: WFSyncUUID|WFBitMapT|Behind\n",
drbd_conn_str(mdev->state.conn));
}
drbd_set_out_of_sync(mdev, be64_to_cpu(p->sector), be32_to_cpu(p->blksize));
return 0;
}
static void drbdd(struct drbd_tconn *tconn)
{
struct packet_info pi;
size_t shs;
int err;
while (get_t_state(&tconn->receiver) == RUNNING) {
struct data_cmd *cmd;
drbd_thread_current_set_cpu(&tconn->receiver);
if (drbd_recv_header(tconn, &pi))
goto err_out;
cmd = &drbd_cmd_handler[pi.cmd];
if (unlikely(pi.cmd >= ARRAY_SIZE(drbd_cmd_handler) || !cmd->fn)) {
conn_err(tconn, "Unexpected data packet %s (0x%04x)",
cmdname(pi.cmd), pi.cmd);
goto err_out;
}
shs = cmd->pkt_size;
if (pi.size > shs && !cmd->expect_payload) {
conn_err(tconn, "No payload expected %s l:%d\n",
cmdname(pi.cmd), pi.size);
goto err_out;
}
if (shs) {
err = drbd_recv_all_warn(tconn, pi.data, shs);
if (err)
goto err_out;
pi.size -= shs;
}
err = cmd->fn(tconn, &pi);
if (err) {
conn_err(tconn, "error receiving %s, e: %d l: %d!\n",
cmdname(pi.cmd), err, pi.size);
goto err_out;
}
}
return;
err_out:
conn_request_state(tconn, NS(conn, C_PROTOCOL_ERROR), CS_HARD);
}
void conn_flush_workqueue(struct drbd_tconn *tconn)
{
struct drbd_wq_barrier barr;
barr.w.cb = w_prev_work_done;
barr.w.tconn = tconn;
init_completion(&barr.done);
drbd_queue_work(&tconn->sender_work, &barr.w);
wait_for_completion(&barr.done);
}
static void conn_disconnect(struct drbd_tconn *tconn)
{
struct drbd_conf *mdev;
enum drbd_conns oc;
int vnr;
if (tconn->cstate == C_STANDALONE)
return;
conn_request_state(tconn, NS(conn, C_NETWORK_FAILURE), CS_HARD);
drbd_thread_stop(&tconn->asender);
drbd_free_sock(tconn);
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
kref_get(&mdev->kref);
rcu_read_unlock();
drbd_disconnected(mdev);
kref_put(&mdev->kref, &drbd_minor_destroy);
rcu_read_lock();
}
rcu_read_unlock();
if (!list_empty(&tconn->current_epoch->list))
conn_err(tconn, "ASSERTION FAILED: tconn->current_epoch->list not empty\n");
atomic_set(&tconn->current_epoch->epoch_size, 0);
tconn->send.seen_any_write_yet = false;
conn_info(tconn, "Connection closed\n");
if (conn_highest_role(tconn) == R_PRIMARY && conn_highest_pdsk(tconn) >= D_UNKNOWN)
conn_try_outdate_peer_async(tconn);
spin_lock_irq(&tconn->req_lock);
oc = tconn->cstate;
if (oc >= C_UNCONNECTED)
_conn_request_state(tconn, NS(conn, C_UNCONNECTED), CS_VERBOSE);
spin_unlock_irq(&tconn->req_lock);
if (oc == C_DISCONNECTING)
conn_request_state(tconn, NS(conn, C_STANDALONE), CS_VERBOSE | CS_HARD);
}
static int drbd_disconnected(struct drbd_conf *mdev)
{
unsigned int i;
spin_lock_irq(&mdev->tconn->req_lock);
_drbd_wait_ee_list_empty(mdev, &mdev->active_ee);
_drbd_wait_ee_list_empty(mdev, &mdev->sync_ee);
_drbd_wait_ee_list_empty(mdev, &mdev->read_ee);
spin_unlock_irq(&mdev->tconn->req_lock);
drbd_rs_cancel_all(mdev);
mdev->rs_total = 0;
mdev->rs_failed = 0;
atomic_set(&mdev->rs_pending_cnt, 0);
wake_up(&mdev->misc_wait);
del_timer_sync(&mdev->resync_timer);
resync_timer_fn((unsigned long)mdev);
drbd_flush_workqueue(mdev);
drbd_finish_peer_reqs(mdev);
drbd_flush_workqueue(mdev);
drbd_rs_cancel_all(mdev);
kfree(mdev->p_uuid);
mdev->p_uuid = NULL;
if (!drbd_suspended(mdev))
tl_clear(mdev->tconn);
drbd_md_sync(mdev);
wait_event(mdev->misc_wait, !test_bit(BITMAP_IO, &mdev->flags));
i = drbd_free_peer_reqs(mdev, &mdev->net_ee);
if (i)
dev_info(DEV, "net_ee not empty, killed %u entries\n", i);
i = atomic_read(&mdev->pp_in_use_by_net);
if (i)
dev_info(DEV, "pp_in_use_by_net = %d, expected 0\n", i);
i = atomic_read(&mdev->pp_in_use);
if (i)
dev_info(DEV, "pp_in_use = %d, expected 0\n", i);
D_ASSERT(list_empty(&mdev->read_ee));
D_ASSERT(list_empty(&mdev->active_ee));
D_ASSERT(list_empty(&mdev->sync_ee));
D_ASSERT(list_empty(&mdev->done_ee));
return 0;
}
static int drbd_send_features(struct drbd_tconn *tconn)
{
struct drbd_socket *sock;
struct p_connection_features *p;
sock = &tconn->data;
p = conn_prepare_command(tconn, sock);
if (!p)
return -EIO;
memset(p, 0, sizeof(*p));
p->protocol_min = cpu_to_be32(PRO_VERSION_MIN);
p->protocol_max = cpu_to_be32(PRO_VERSION_MAX);
return conn_send_command(tconn, sock, P_CONNECTION_FEATURES, sizeof(*p), NULL, 0);
}
static int drbd_do_features(struct drbd_tconn *tconn)
{
struct p_connection_features *p;
const int expect = sizeof(struct p_connection_features);
struct packet_info pi;
int err;
err = drbd_send_features(tconn);
if (err)
return 0;
err = drbd_recv_header(tconn, &pi);
if (err)
return 0;
if (pi.cmd != P_CONNECTION_FEATURES) {
conn_err(tconn, "expected ConnectionFeatures packet, received: %s (0x%04x)\n",
cmdname(pi.cmd), pi.cmd);
return -1;
}
if (pi.size != expect) {
conn_err(tconn, "expected ConnectionFeatures length: %u, received: %u\n",
expect, pi.size);
return -1;
}
p = pi.data;
err = drbd_recv_all_warn(tconn, p, expect);
if (err)
return 0;
p->protocol_min = be32_to_cpu(p->protocol_min);
p->protocol_max = be32_to_cpu(p->protocol_max);
if (p->protocol_max == 0)
p->protocol_max = p->protocol_min;
if (PRO_VERSION_MAX < p->protocol_min ||
PRO_VERSION_MIN > p->protocol_max)
goto incompat;
tconn->agreed_pro_version = min_t(int, PRO_VERSION_MAX, p->protocol_max);
conn_info(tconn, "Handshake successful: "
"Agreed network protocol version %d\n", tconn->agreed_pro_version);
return 1;
incompat:
conn_err(tconn, "incompatible DRBD dialects: "
"I support %d-%d, peer supports %d-%d\n",
PRO_VERSION_MIN, PRO_VERSION_MAX,
p->protocol_min, p->protocol_max);
return -1;
}
static int drbd_do_auth(struct drbd_tconn *tconn)
{
dev_err(DEV, "This kernel was build without CONFIG_CRYPTO_HMAC.\n");
dev_err(DEV, "You need to disable 'cram-hmac-alg' in drbd.conf.\n");
return -1;
}
static int drbd_do_auth(struct drbd_tconn *tconn)
{
struct drbd_socket *sock;
char my_challenge[CHALLENGE_LEN];
struct scatterlist sg;
char *response = NULL;
char *right_response = NULL;
char *peers_ch = NULL;
unsigned int key_len;
char secret[SHARED_SECRET_MAX];
unsigned int resp_size;
struct hash_desc desc;
struct packet_info pi;
struct net_conf *nc;
int err, rv;
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
key_len = strlen(nc->shared_secret);
memcpy(secret, nc->shared_secret, key_len);
rcu_read_unlock();
desc.tfm = tconn->cram_hmac_tfm;
desc.flags = 0;
rv = crypto_hash_setkey(tconn->cram_hmac_tfm, (u8 *)secret, key_len);
if (rv) {
conn_err(tconn, "crypto_hash_setkey() failed with %d\n", rv);
rv = -1;
goto fail;
}
get_random_bytes(my_challenge, CHALLENGE_LEN);
sock = &tconn->data;
if (!conn_prepare_command(tconn, sock)) {
rv = 0;
goto fail;
}
rv = !conn_send_command(tconn, sock, P_AUTH_CHALLENGE, 0,
my_challenge, CHALLENGE_LEN);
if (!rv)
goto fail;
err = drbd_recv_header(tconn, &pi);
if (err) {
rv = 0;
goto fail;
}
if (pi.cmd != P_AUTH_CHALLENGE) {
conn_err(tconn, "expected AuthChallenge packet, received: %s (0x%04x)\n",
cmdname(pi.cmd), pi.cmd);
rv = 0;
goto fail;
}
if (pi.size > CHALLENGE_LEN * 2) {
conn_err(tconn, "expected AuthChallenge payload too big.\n");
rv = -1;
goto fail;
}
peers_ch = kmalloc(pi.size, GFP_NOIO);
if (peers_ch == NULL) {
conn_err(tconn, "kmalloc of peers_ch failed\n");
rv = -1;
goto fail;
}
err = drbd_recv_all_warn(tconn, peers_ch, pi.size);
if (err) {
rv = 0;
goto fail;
}
resp_size = crypto_hash_digestsize(tconn->cram_hmac_tfm);
response = kmalloc(resp_size, GFP_NOIO);
if (response == NULL) {
conn_err(tconn, "kmalloc of response failed\n");
rv = -1;
goto fail;
}
sg_init_table(&sg, 1);
sg_set_buf(&sg, peers_ch, pi.size);
rv = crypto_hash_digest(&desc, &sg, sg.length, response);
if (rv) {
conn_err(tconn, "crypto_hash_digest() failed with %d\n", rv);
rv = -1;
goto fail;
}
if (!conn_prepare_command(tconn, sock)) {
rv = 0;
goto fail;
}
rv = !conn_send_command(tconn, sock, P_AUTH_RESPONSE, 0,
response, resp_size);
if (!rv)
goto fail;
err = drbd_recv_header(tconn, &pi);
if (err) {
rv = 0;
goto fail;
}
if (pi.cmd != P_AUTH_RESPONSE) {
conn_err(tconn, "expected AuthResponse packet, received: %s (0x%04x)\n",
cmdname(pi.cmd), pi.cmd);
rv = 0;
goto fail;
}
if (pi.size != resp_size) {
conn_err(tconn, "expected AuthResponse payload of wrong size\n");
rv = 0;
goto fail;
}
err = drbd_recv_all_warn(tconn, response , resp_size);
if (err) {
rv = 0;
goto fail;
}
right_response = kmalloc(resp_size, GFP_NOIO);
if (right_response == NULL) {
conn_err(tconn, "kmalloc of right_response failed\n");
rv = -1;
goto fail;
}
sg_set_buf(&sg, my_challenge, CHALLENGE_LEN);
rv = crypto_hash_digest(&desc, &sg, sg.length, right_response);
if (rv) {
conn_err(tconn, "crypto_hash_digest() failed with %d\n", rv);
rv = -1;
goto fail;
}
rv = !memcmp(response, right_response, resp_size);
if (rv)
conn_info(tconn, "Peer authenticated using %d bytes HMAC\n",
resp_size);
else
rv = -1;
fail:
kfree(peers_ch);
kfree(response);
kfree(right_response);
return rv;
}
int drbdd_init(struct drbd_thread *thi)
{
struct drbd_tconn *tconn = thi->tconn;
int h;
conn_info(tconn, "receiver (re)started\n");
do {
h = conn_connect(tconn);
if (h == 0) {
conn_disconnect(tconn);
schedule_timeout_interruptible(HZ);
}
if (h == -1) {
conn_warn(tconn, "Discarding network configuration.\n");
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
}
} while (h == 0);
if (h > 0)
drbdd(tconn);
conn_disconnect(tconn);
conn_info(tconn, "receiver terminated\n");
return 0;
}
static int got_conn_RqSReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct p_req_state_reply *p = pi->data;
int retcode = be32_to_cpu(p->retcode);
if (retcode >= SS_SUCCESS) {
set_bit(CONN_WD_ST_CHG_OKAY, &tconn->flags);
} else {
set_bit(CONN_WD_ST_CHG_FAIL, &tconn->flags);
conn_err(tconn, "Requested state change failed by peer: %s (%d)\n",
drbd_set_st_err_str(retcode), retcode);
}
wake_up(&tconn->ping_wait);
return 0;
}
static int got_RqSReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_req_state_reply *p = pi->data;
int retcode = be32_to_cpu(p->retcode);
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
if (test_bit(CONN_WD_ST_CHG_REQ, &tconn->flags)) {
D_ASSERT(tconn->agreed_pro_version < 100);
return got_conn_RqSReply(tconn, pi);
}
if (retcode >= SS_SUCCESS) {
set_bit(CL_ST_CHG_SUCCESS, &mdev->flags);
} else {
set_bit(CL_ST_CHG_FAIL, &mdev->flags);
dev_err(DEV, "Requested state change failed by peer: %s (%d)\n",
drbd_set_st_err_str(retcode), retcode);
}
wake_up(&mdev->state_wait);
return 0;
}
static int got_Ping(struct drbd_tconn *tconn, struct packet_info *pi)
{
return drbd_send_ping_ack(tconn);
}
static int got_PingAck(struct drbd_tconn *tconn, struct packet_info *pi)
{
tconn->meta.socket->sk->sk_rcvtimeo = tconn->net_conf->ping_int*HZ;
if (!test_and_set_bit(GOT_PING_ACK, &tconn->flags))
wake_up(&tconn->ping_wait);
return 0;
}
static int got_IsInSync(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_ack *p = pi->data;
sector_t sector = be64_to_cpu(p->sector);
int blksize = be32_to_cpu(p->blksize);
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
D_ASSERT(mdev->tconn->agreed_pro_version >= 89);
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
if (get_ldev(mdev)) {
drbd_rs_complete_io(mdev, sector);
drbd_set_in_sync(mdev, sector, blksize);
mdev->rs_same_csum += (blksize >> BM_BLOCK_SHIFT);
put_ldev(mdev);
}
dec_rs_pending(mdev);
atomic_add(blksize >> 9, &mdev->rs_sect_in);
return 0;
}
static int
validate_req_change_req_state(struct drbd_conf *mdev, u64 id, sector_t sector,
struct rb_root *root, const char *func,
enum drbd_req_event what, bool missing_ok)
{
struct drbd_request *req;
struct bio_and_error m;
spin_lock_irq(&mdev->tconn->req_lock);
req = find_request(mdev, root, id, sector, missing_ok, func);
if (unlikely(!req)) {
spin_unlock_irq(&mdev->tconn->req_lock);
return -EIO;
}
__req_mod(req, what, &m);
spin_unlock_irq(&mdev->tconn->req_lock);
if (m.bio)
complete_master_bio(mdev, &m);
return 0;
}
static int got_BlockAck(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_ack *p = pi->data;
sector_t sector = be64_to_cpu(p->sector);
int blksize = be32_to_cpu(p->blksize);
enum drbd_req_event what;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
if (p->block_id == ID_SYNCER) {
drbd_set_in_sync(mdev, sector, blksize);
dec_rs_pending(mdev);
return 0;
}
switch (pi->cmd) {
case P_RS_WRITE_ACK:
what = WRITE_ACKED_BY_PEER_AND_SIS;
break;
case P_WRITE_ACK:
what = WRITE_ACKED_BY_PEER;
break;
case P_RECV_ACK:
what = RECV_ACKED_BY_PEER;
break;
case P_SUPERSEDED:
what = CONFLICT_RESOLVED;
break;
case P_RETRY_WRITE:
what = POSTPONE_WRITE;
break;
default:
BUG();
}
return validate_req_change_req_state(mdev, p->block_id, sector,
&mdev->write_requests, __func__,
what, false);
}
static int got_NegAck(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_ack *p = pi->data;
sector_t sector = be64_to_cpu(p->sector);
int size = be32_to_cpu(p->blksize);
int err;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
if (p->block_id == ID_SYNCER) {
dec_rs_pending(mdev);
drbd_rs_failed_io(mdev, sector, size);
return 0;
}
err = validate_req_change_req_state(mdev, p->block_id, sector,
&mdev->write_requests, __func__,
NEG_ACKED, true);
if (err) {
drbd_set_out_of_sync(mdev, sector, size);
}
return 0;
}
static int got_NegDReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_ack *p = pi->data;
sector_t sector = be64_to_cpu(p->sector);
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
dev_err(DEV, "Got NegDReply; Sector %llus, len %u.\n",
(unsigned long long)sector, be32_to_cpu(p->blksize));
return validate_req_change_req_state(mdev, p->block_id, sector,
&mdev->read_requests, __func__,
NEG_ACKED, false);
}
static int got_NegRSDReply(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
sector_t sector;
int size;
struct p_block_ack *p = pi->data;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
sector = be64_to_cpu(p->sector);
size = be32_to_cpu(p->blksize);
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
dec_rs_pending(mdev);
if (get_ldev_if_state(mdev, D_FAILED)) {
drbd_rs_complete_io(mdev, sector);
switch (pi->cmd) {
case P_NEG_RS_DREPLY:
drbd_rs_failed_io(mdev, sector, size);
case P_RS_CANCEL:
break;
default:
BUG();
}
put_ldev(mdev);
}
return 0;
}
static int got_BarrierAck(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct p_barrier_ack *p = pi->data;
struct drbd_conf *mdev;
int vnr;
tl_release(tconn, p->barrier, be32_to_cpu(p->set_size));
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
if (mdev->state.conn == C_AHEAD &&
atomic_read(&mdev->ap_in_flight) == 0 &&
!test_and_set_bit(AHEAD_TO_SYNC_SOURCE, &mdev->flags)) {
mdev->start_resync_timer.expires = jiffies + HZ;
add_timer(&mdev->start_resync_timer);
}
}
rcu_read_unlock();
return 0;
}
static int got_OVResult(struct drbd_tconn *tconn, struct packet_info *pi)
{
struct drbd_conf *mdev;
struct p_block_ack *p = pi->data;
struct drbd_work *w;
sector_t sector;
int size;
mdev = vnr_to_mdev(tconn, pi->vnr);
if (!mdev)
return -EIO;
sector = be64_to_cpu(p->sector);
size = be32_to_cpu(p->blksize);
update_peer_seq(mdev, be32_to_cpu(p->seq_num));
if (be64_to_cpu(p->block_id) == ID_OUT_OF_SYNC)
drbd_ov_out_of_sync_found(mdev, sector, size);
else
ov_out_of_sync_print(mdev);
if (!get_ldev(mdev))
return 0;
drbd_rs_complete_io(mdev, sector);
dec_rs_pending(mdev);
--mdev->ov_left;
if ((mdev->ov_left & 0x200) == 0x200)
drbd_advance_rs_marks(mdev, mdev->ov_left);
if (mdev->ov_left == 0) {
w = kmalloc(sizeof(*w), GFP_NOIO);
if (w) {
w->cb = w_ov_finished;
w->mdev = mdev;
drbd_queue_work(&mdev->tconn->sender_work, w);
} else {
dev_err(DEV, "kmalloc(w) failed.");
ov_out_of_sync_print(mdev);
drbd_resync_finished(mdev);
}
}
put_ldev(mdev);
return 0;
}
static int got_skip(struct drbd_tconn *tconn, struct packet_info *pi)
{
return 0;
}
static int tconn_finish_peer_reqs(struct drbd_tconn *tconn)
{
struct drbd_conf *mdev;
int vnr, not_empty = 0;
do {
clear_bit(SIGNAL_ASENDER, &tconn->flags);
flush_signals(current);
rcu_read_lock();
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
kref_get(&mdev->kref);
rcu_read_unlock();
if (drbd_finish_peer_reqs(mdev)) {
kref_put(&mdev->kref, &drbd_minor_destroy);
return 1;
}
kref_put(&mdev->kref, &drbd_minor_destroy);
rcu_read_lock();
}
set_bit(SIGNAL_ASENDER, &tconn->flags);
spin_lock_irq(&tconn->req_lock);
idr_for_each_entry(&tconn->volumes, mdev, vnr) {
not_empty = !list_empty(&mdev->done_ee);
if (not_empty)
break;
}
spin_unlock_irq(&tconn->req_lock);
rcu_read_unlock();
} while (not_empty);
return 0;
}
int drbd_asender(struct drbd_thread *thi)
{
struct drbd_tconn *tconn = thi->tconn;
struct asender_cmd *cmd = NULL;
struct packet_info pi;
int rv;
void *buf = tconn->meta.rbuf;
int received = 0;
unsigned int header_size = drbd_header_size(tconn);
int expect = header_size;
bool ping_timeout_active = false;
struct net_conf *nc;
int ping_timeo, tcp_cork, ping_int;
current->policy = SCHED_RR;
current->rt_priority = 2;
while (get_t_state(thi) == RUNNING) {
drbd_thread_current_set_cpu(thi);
rcu_read_lock();
nc = rcu_dereference(tconn->net_conf);
ping_timeo = nc->ping_timeo;
tcp_cork = nc->tcp_cork;
ping_int = nc->ping_int;
rcu_read_unlock();
if (test_and_clear_bit(SEND_PING, &tconn->flags)) {
if (drbd_send_ping(tconn)) {
conn_err(tconn, "drbd_send_ping has failed\n");
goto reconnect;
}
tconn->meta.socket->sk->sk_rcvtimeo = ping_timeo * HZ / 10;
ping_timeout_active = true;
}
if (tcp_cork)
drbd_tcp_cork(tconn->meta.socket);
if (tconn_finish_peer_reqs(tconn)) {
conn_err(tconn, "tconn_finish_peer_reqs() failed\n");
goto reconnect;
}
if (tcp_cork)
drbd_tcp_uncork(tconn->meta.socket);
if (signal_pending(current))
continue;
rv = drbd_recv_short(tconn->meta.socket, buf, expect-received, 0);
clear_bit(SIGNAL_ASENDER, &tconn->flags);
flush_signals(current);
if (likely(rv > 0)) {
received += rv;
buf += rv;
} else if (rv == 0) {
if (test_bit(DISCONNECT_SENT, &tconn->flags)) {
long t;
rcu_read_lock();
t = rcu_dereference(tconn->net_conf)->ping_timeo * HZ/10;
rcu_read_unlock();
t = wait_event_timeout(tconn->ping_wait,
tconn->cstate < C_WF_REPORT_PARAMS,
t);
if (t)
break;
}
conn_err(tconn, "meta connection shut down by peer.\n");
goto reconnect;
} else if (rv == -EAGAIN) {
if (time_after(tconn->last_received,
jiffies - tconn->meta.socket->sk->sk_rcvtimeo))
continue;
if (ping_timeout_active) {
conn_err(tconn, "PingAck did not arrive in time.\n");
goto reconnect;
}
set_bit(SEND_PING, &tconn->flags);
continue;
} else if (rv == -EINTR) {
continue;
} else {
conn_err(tconn, "sock_recvmsg returned %d\n", rv);
goto reconnect;
}
if (received == expect && cmd == NULL) {
if (decode_header(tconn, tconn->meta.rbuf, &pi))
goto reconnect;
cmd = &asender_tbl[pi.cmd];
if (pi.cmd >= ARRAY_SIZE(asender_tbl) || !cmd->fn) {
conn_err(tconn, "Unexpected meta packet %s (0x%04x)\n",
cmdname(pi.cmd), pi.cmd);
goto disconnect;
}
expect = header_size + cmd->pkt_size;
if (pi.size != expect - header_size) {
conn_err(tconn, "Wrong packet size on meta (c: %d, l: %d)\n",
pi.cmd, pi.size);
goto reconnect;
}
}
if (received == expect) {
bool err;
err = cmd->fn(tconn, &pi);
if (err) {
conn_err(tconn, "%pf failed\n", cmd->fn);
goto reconnect;
}
tconn->last_received = jiffies;
if (cmd == &asender_tbl[P_PING_ACK]) {
tconn->meta.socket->sk->sk_rcvtimeo = ping_int * HZ;
ping_timeout_active = false;
}
buf = tconn->meta.rbuf;
received = 0;
expect = header_size;
cmd = NULL;
}
}
if (0) {
reconnect:
conn_request_state(tconn, NS(conn, C_NETWORK_FAILURE), CS_HARD);
conn_md_sync(tconn);
}
if (0) {
disconnect:
conn_request_state(tconn, NS(conn, C_DISCONNECTING), CS_HARD);
}
clear_bit(SIGNAL_ASENDER, &tconn->flags);
conn_info(tconn, "asender terminated\n");
return 0;
}
