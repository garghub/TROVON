struct ksock_tx *
ksocknal_alloc_tx(int type, int size)
{
struct ksock_tx *tx = NULL;
if (type == KSOCK_MSG_NOOP) {
LASSERT(size == KSOCK_NOOP_TX_SIZE);
spin_lock(&ksocknal_data.ksnd_tx_lock);
if (!list_empty(&ksocknal_data.ksnd_idle_noop_txs)) {
tx = list_entry(ksocknal_data.ksnd_idle_noop_txs. \
next, struct ksock_tx, tx_list);
LASSERT(tx->tx_desc_size == size);
list_del(&tx->tx_list);
}
spin_unlock(&ksocknal_data.ksnd_tx_lock);
}
if (!tx)
LIBCFS_ALLOC(tx, size);
if (!tx)
return NULL;
atomic_set(&tx->tx_refcount, 1);
tx->tx_zc_aborted = 0;
tx->tx_zc_capable = 0;
tx->tx_zc_checked = 0;
tx->tx_desc_size = size;
atomic_inc(&ksocknal_data.ksnd_nactive_txs);
return tx;
}
struct ksock_tx *
ksocknal_alloc_tx_noop(__u64 cookie, int nonblk)
{
struct ksock_tx *tx;
tx = ksocknal_alloc_tx(KSOCK_MSG_NOOP, KSOCK_NOOP_TX_SIZE);
if (!tx) {
CERROR("Can't allocate noop tx desc\n");
return NULL;
}
tx->tx_conn = NULL;
tx->tx_lnetmsg = NULL;
tx->tx_kiov = NULL;
tx->tx_nkiov = 0;
tx->tx_iov = tx->tx_frags.virt.iov;
tx->tx_niov = 1;
tx->tx_nonblk = nonblk;
socklnd_init_msg(&tx->tx_msg, KSOCK_MSG_NOOP);
tx->tx_msg.ksm_zc_cookies[1] = cookie;
return tx;
}
void
ksocknal_free_tx(struct ksock_tx *tx)
{
atomic_dec(&ksocknal_data.ksnd_nactive_txs);
if (!tx->tx_lnetmsg && tx->tx_desc_size == KSOCK_NOOP_TX_SIZE) {
spin_lock(&ksocknal_data.ksnd_tx_lock);
list_add(&tx->tx_list, &ksocknal_data.ksnd_idle_noop_txs);
spin_unlock(&ksocknal_data.ksnd_tx_lock);
} else {
LIBCFS_FREE(tx, tx->tx_desc_size);
}
}
static int
ksocknal_send_iov(struct ksock_conn *conn, struct ksock_tx *tx)
{
struct kvec *iov = tx->tx_iov;
int nob;
int rc;
LASSERT(tx->tx_niov > 0);
rc = ksocknal_lib_send_iov(conn, tx);
if (rc <= 0)
return rc;
nob = rc;
LASSERT(nob <= tx->tx_resid);
tx->tx_resid -= nob;
do {
LASSERT(tx->tx_niov > 0);
if (nob < (int)iov->iov_len) {
iov->iov_base = (void *)((char *)iov->iov_base + nob);
iov->iov_len -= nob;
return rc;
}
nob -= iov->iov_len;
tx->tx_iov = ++iov;
tx->tx_niov--;
} while (nob);
return rc;
}
static int
ksocknal_send_kiov(struct ksock_conn *conn, struct ksock_tx *tx)
{
lnet_kiov_t *kiov = tx->tx_kiov;
int nob;
int rc;
LASSERT(!tx->tx_niov);
LASSERT(tx->tx_nkiov > 0);
rc = ksocknal_lib_send_kiov(conn, tx);
if (rc <= 0)
return rc;
nob = rc;
LASSERT(nob <= tx->tx_resid);
tx->tx_resid -= nob;
do {
LASSERT(tx->tx_nkiov > 0);
if (nob < (int)kiov->kiov_len) {
kiov->kiov_offset += nob;
kiov->kiov_len -= nob;
return rc;
}
nob -= (int)kiov->kiov_len;
tx->tx_kiov = ++kiov;
tx->tx_nkiov--;
} while (nob);
return rc;
}
static int
ksocknal_transmit(struct ksock_conn *conn, struct ksock_tx *tx)
{
int rc;
int bufnob;
if (ksocknal_data.ksnd_stall_tx) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(ksocknal_data.ksnd_stall_tx));
}
LASSERT(tx->tx_resid);
rc = ksocknal_connsock_addref(conn);
if (rc) {
LASSERT(conn->ksnc_closing);
return -ESHUTDOWN;
}
do {
if (ksocknal_data.ksnd_enomem_tx > 0) {
ksocknal_data.ksnd_enomem_tx--;
rc = -EAGAIN;
} else if (tx->tx_niov) {
rc = ksocknal_send_iov(conn, tx);
} else {
rc = ksocknal_send_kiov(conn, tx);
}
bufnob = conn->ksnc_sock->sk->sk_wmem_queued;
if (rc > 0)
conn->ksnc_tx_bufnob += rc;
if (bufnob < conn->ksnc_tx_bufnob) {
conn->ksnc_tx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
conn->ksnc_peer->ksnp_last_alive = cfs_time_current();
conn->ksnc_tx_bufnob = bufnob;
mb();
}
if (rc <= 0) {
if (!rc)
rc = -EAGAIN;
if (rc == -EAGAIN && ksocknal_lib_memory_pressure(conn))
rc = -ENOMEM;
break;
}
atomic_sub(rc, &conn->ksnc_tx_nob);
rc = 0;
} while (tx->tx_resid);
ksocknal_connsock_decref(conn);
return rc;
}
static int
ksocknal_recv_iov(struct ksock_conn *conn)
{
struct kvec *iov = conn->ksnc_rx_iov;
int nob;
int rc;
LASSERT(conn->ksnc_rx_niov > 0);
rc = ksocknal_lib_recv_iov(conn);
if (rc <= 0)
return rc;
nob = rc;
conn->ksnc_peer->ksnp_last_alive = cfs_time_current();
conn->ksnc_rx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
mb();
conn->ksnc_rx_started = 1;
conn->ksnc_rx_nob_wanted -= nob;
conn->ksnc_rx_nob_left -= nob;
do {
LASSERT(conn->ksnc_rx_niov > 0);
if (nob < (int)iov->iov_len) {
iov->iov_len -= nob;
iov->iov_base += nob;
return -EAGAIN;
}
nob -= iov->iov_len;
conn->ksnc_rx_iov = ++iov;
conn->ksnc_rx_niov--;
} while (nob);
return rc;
}
static int
ksocknal_recv_kiov(struct ksock_conn *conn)
{
lnet_kiov_t *kiov = conn->ksnc_rx_kiov;
int nob;
int rc;
LASSERT(conn->ksnc_rx_nkiov > 0);
rc = ksocknal_lib_recv_kiov(conn);
if (rc <= 0)
return rc;
nob = rc;
conn->ksnc_peer->ksnp_last_alive = cfs_time_current();
conn->ksnc_rx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
mb();
conn->ksnc_rx_started = 1;
conn->ksnc_rx_nob_wanted -= nob;
conn->ksnc_rx_nob_left -= nob;
do {
LASSERT(conn->ksnc_rx_nkiov > 0);
if (nob < (int)kiov->kiov_len) {
kiov->kiov_offset += nob;
kiov->kiov_len -= nob;
return -EAGAIN;
}
nob -= kiov->kiov_len;
conn->ksnc_rx_kiov = ++kiov;
conn->ksnc_rx_nkiov--;
} while (nob);
return 1;
}
static int
ksocknal_receive(struct ksock_conn *conn)
{
int rc;
if (ksocknal_data.ksnd_stall_rx) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(ksocknal_data.ksnd_stall_rx));
}
rc = ksocknal_connsock_addref(conn);
if (rc) {
LASSERT(conn->ksnc_closing);
return -ESHUTDOWN;
}
for (;;) {
if (conn->ksnc_rx_niov)
rc = ksocknal_recv_iov(conn);
else
rc = ksocknal_recv_kiov(conn);
if (rc <= 0) {
if (rc == -EAGAIN) {
rc = 1;
} else if (!rc && conn->ksnc_rx_started) {
rc = -EPROTO;
}
break;
}
if (!conn->ksnc_rx_nob_wanted) {
rc = 1;
break;
}
}
ksocknal_connsock_decref(conn);
return rc;
}
void
ksocknal_tx_done(lnet_ni_t *ni, struct ksock_tx *tx)
{
lnet_msg_t *lnetmsg = tx->tx_lnetmsg;
int rc = (!tx->tx_resid && !tx->tx_zc_aborted) ? 0 : -EIO;
LASSERT(ni || tx->tx_conn);
if (tx->tx_conn)
ksocknal_conn_decref(tx->tx_conn);
if (!ni && tx->tx_conn)
ni = tx->tx_conn->ksnc_peer->ksnp_ni;
ksocknal_free_tx(tx);
if (lnetmsg)
lnet_finalize(ni, lnetmsg, rc);
}
void
ksocknal_txlist_done(lnet_ni_t *ni, struct list_head *txlist, int error)
{
struct ksock_tx *tx;
while (!list_empty(txlist)) {
tx = list_entry(txlist->next, struct ksock_tx, tx_list);
if (error && tx->tx_lnetmsg) {
CNETERR("Deleting packet type %d len %d %s->%s\n",
le32_to_cpu(tx->tx_lnetmsg->msg_hdr.type),
le32_to_cpu(tx->tx_lnetmsg->msg_hdr.payload_length),
libcfs_nid2str(le64_to_cpu(tx->tx_lnetmsg->msg_hdr.src_nid)),
libcfs_nid2str(le64_to_cpu(tx->tx_lnetmsg->msg_hdr.dest_nid)));
} else if (error) {
CNETERR("Deleting noop packet\n");
}
list_del(&tx->tx_list);
LASSERT(atomic_read(&tx->tx_refcount) == 1);
ksocknal_tx_done(ni, tx);
}
}
static void
ksocknal_check_zc_req(struct ksock_tx *tx)
{
struct ksock_conn *conn = tx->tx_conn;
struct ksock_peer *peer = conn->ksnc_peer;
LASSERT(tx->tx_msg.ksm_type != KSOCK_MSG_NOOP);
LASSERT(tx->tx_zc_capable);
tx->tx_zc_checked = 1;
if (conn->ksnc_proto == &ksocknal_protocol_v1x ||
!conn->ksnc_zc_capable)
return;
ksocknal_tx_addref(tx);
spin_lock(&peer->ksnp_lock);
tx->tx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
LASSERT(!tx->tx_msg.ksm_zc_cookies[0]);
tx->tx_msg.ksm_zc_cookies[0] = peer->ksnp_zc_next_cookie++;
if (!peer->ksnp_zc_next_cookie)
peer->ksnp_zc_next_cookie = SOCKNAL_KEEPALIVE_PING + 1;
list_add_tail(&tx->tx_zc_list, &peer->ksnp_zc_req_list);
spin_unlock(&peer->ksnp_lock);
}
static void
ksocknal_uncheck_zc_req(struct ksock_tx *tx)
{
struct ksock_peer *peer = tx->tx_conn->ksnc_peer;
LASSERT(tx->tx_msg.ksm_type != KSOCK_MSG_NOOP);
LASSERT(tx->tx_zc_capable);
tx->tx_zc_checked = 0;
spin_lock(&peer->ksnp_lock);
if (!tx->tx_msg.ksm_zc_cookies[0]) {
spin_unlock(&peer->ksnp_lock);
return;
}
tx->tx_msg.ksm_zc_cookies[0] = 0;
list_del(&tx->tx_zc_list);
spin_unlock(&peer->ksnp_lock);
ksocknal_tx_decref(tx);
}
static int
ksocknal_process_transmit(struct ksock_conn *conn, struct ksock_tx *tx)
{
int rc;
if (tx->tx_zc_capable && !tx->tx_zc_checked)
ksocknal_check_zc_req(tx);
rc = ksocknal_transmit(conn, tx);
CDEBUG(D_NET, "send(%d) %d\n", tx->tx_resid, rc);
if (!tx->tx_resid) {
LASSERT(!rc);
return 0;
}
if (rc == -EAGAIN)
return rc;
if (rc == -ENOMEM) {
static int counter;
counter++;
if ((counter & (-counter)) == counter)
CWARN("%u ENOMEM tx %p\n", counter, conn);
spin_lock_bh(&ksocknal_data.ksnd_reaper_lock);
LASSERT(conn->ksnc_tx_scheduled);
list_add_tail(&conn->ksnc_tx_list,
&ksocknal_data.ksnd_enomem_conns);
if (!cfs_time_aftereq(cfs_time_add(cfs_time_current(),
SOCKNAL_ENOMEM_RETRY),
ksocknal_data.ksnd_reaper_waketime))
wake_up(&ksocknal_data.ksnd_reaper_waitq);
spin_unlock_bh(&ksocknal_data.ksnd_reaper_lock);
return rc;
}
LASSERT(rc < 0);
if (!conn->ksnc_closing) {
switch (rc) {
case -ECONNRESET:
LCONSOLE_WARN("Host %pI4h reset our connection while we were sending data; it may have rebooted.\n",
&conn->ksnc_ipaddr);
break;
default:
LCONSOLE_WARN("There was an unexpected network error while writing to %pI4h: %d.\n",
&conn->ksnc_ipaddr, rc);
break;
}
CDEBUG(D_NET, "[%p] Error %d on write to %s ip %pI4h:%d\n",
conn, rc,
libcfs_id2str(conn->ksnc_peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
}
if (tx->tx_zc_checked)
ksocknal_uncheck_zc_req(tx);
ksocknal_close_conn_and_siblings(conn, (conn->ksnc_closing) ? 0 : rc);
return rc;
}
static void
ksocknal_launch_connection_locked(struct ksock_route *route)
{
LASSERT(!route->ksnr_scheduled);
LASSERT(!route->ksnr_connecting);
LASSERT(ksocknal_route_mask() & ~route->ksnr_connected);
route->ksnr_scheduled = 1;
ksocknal_route_addref(route);
spin_lock_bh(&ksocknal_data.ksnd_connd_lock);
list_add_tail(&route->ksnr_connd_list,
&ksocknal_data.ksnd_connd_routes);
wake_up(&ksocknal_data.ksnd_connd_waitq);
spin_unlock_bh(&ksocknal_data.ksnd_connd_lock);
}
void
ksocknal_launch_all_connections_locked(struct ksock_peer *peer)
{
struct ksock_route *route;
for (;;) {
route = ksocknal_find_connectable_route_locked(peer);
if (!route)
return;
ksocknal_launch_connection_locked(route);
}
}
struct ksock_conn *
ksocknal_find_conn_locked(struct ksock_peer *peer, struct ksock_tx *tx, int nonblk)
{
struct list_head *tmp;
struct ksock_conn *conn;
struct ksock_conn *typed = NULL;
struct ksock_conn *fallback = NULL;
int tnob = 0;
int fnob = 0;
list_for_each(tmp, &peer->ksnp_conns) {
struct ksock_conn *c = list_entry(tmp, struct ksock_conn, ksnc_list);
int nob = atomic_read(&c->ksnc_tx_nob) +
c->ksnc_sock->sk->sk_wmem_queued;
int rc;
LASSERT(!c->ksnc_closing);
LASSERT(c->ksnc_proto &&
c->ksnc_proto->pro_match_tx);
rc = c->ksnc_proto->pro_match_tx(c, tx, nonblk);
switch (rc) {
default:
LBUG();
case SOCKNAL_MATCH_NO:
continue;
case SOCKNAL_MATCH_YES:
if (!typed || tnob > nob ||
(tnob == nob && *ksocknal_tunables.ksnd_round_robin &&
cfs_time_after(typed->ksnc_tx_last_post, c->ksnc_tx_last_post))) {
typed = c;
tnob = nob;
}
break;
case SOCKNAL_MATCH_MAY:
if (!fallback || fnob > nob ||
(fnob == nob && *ksocknal_tunables.ksnd_round_robin &&
cfs_time_after(fallback->ksnc_tx_last_post, c->ksnc_tx_last_post))) {
fallback = c;
fnob = nob;
}
break;
}
}
conn = (typed) ? typed : fallback;
if (conn)
conn->ksnc_tx_last_post = cfs_time_current();
return conn;
}
void
ksocknal_tx_prep(struct ksock_conn *conn, struct ksock_tx *tx)
{
conn->ksnc_proto->pro_pack(tx);
atomic_add(tx->tx_nob, &conn->ksnc_tx_nob);
ksocknal_conn_addref(conn);
tx->tx_conn = conn;
}
void
ksocknal_queue_tx_locked(struct ksock_tx *tx, struct ksock_conn *conn)
{
struct ksock_sched *sched = conn->ksnc_scheduler;
ksock_msg_t *msg = &tx->tx_msg;
struct ksock_tx *ztx = NULL;
int bufnob = 0;
LASSERT(!conn->ksnc_closing);
CDEBUG(D_NET, "Sending to %s ip %pI4h:%d\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id),
&conn->ksnc_ipaddr, conn->ksnc_port);
ksocknal_tx_prep(conn, tx);
LASSERT(lnet_iov_nob(tx->tx_niov, tx->tx_iov) +
lnet_kiov_nob(tx->tx_nkiov, tx->tx_kiov) ==
(unsigned int)tx->tx_nob);
LASSERT(tx->tx_niov >= 1);
LASSERT(tx->tx_resid == tx->tx_nob);
CDEBUG(D_NET, "Packet %p type %d, nob %d niov %d nkiov %d\n",
tx, (tx->tx_lnetmsg) ? tx->tx_lnetmsg->msg_hdr.type :
KSOCK_MSG_NOOP,
tx->tx_nob, tx->tx_niov, tx->tx_nkiov);
bufnob = conn->ksnc_sock->sk->sk_wmem_queued;
spin_lock_bh(&sched->kss_lock);
if (list_empty(&conn->ksnc_tx_queue) && !bufnob) {
conn->ksnc_tx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
if (conn->ksnc_tx_bufnob > 0)
conn->ksnc_peer->ksnp_last_alive = cfs_time_current();
conn->ksnc_tx_bufnob = 0;
mb();
}
if (msg->ksm_type == KSOCK_MSG_NOOP) {
LASSERT(msg->ksm_zc_cookies[1]);
LASSERT(conn->ksnc_proto->pro_queue_tx_zcack);
if (conn->ksnc_proto->pro_queue_tx_zcack(conn, tx, 0))
ztx = tx;
} else {
LASSERT(!msg->ksm_zc_cookies[1]);
LASSERT(conn->ksnc_proto->pro_queue_tx_msg);
ztx = conn->ksnc_proto->pro_queue_tx_msg(conn, tx);
}
if (ztx) {
atomic_sub(ztx->tx_nob, &conn->ksnc_tx_nob);
list_add_tail(&ztx->tx_list, &sched->kss_zombie_noop_txs);
}
if (conn->ksnc_tx_ready &&
!conn->ksnc_tx_scheduled) {
ksocknal_conn_addref(conn);
list_add_tail(&conn->ksnc_tx_list, &sched->kss_tx_conns);
conn->ksnc_tx_scheduled = 1;
wake_up(&sched->kss_waitq);
}
spin_unlock_bh(&sched->kss_lock);
}
struct ksock_route *
ksocknal_find_connectable_route_locked(struct ksock_peer *peer)
{
unsigned long now = cfs_time_current();
struct list_head *tmp;
struct ksock_route *route;
list_for_each(tmp, &peer->ksnp_routes) {
route = list_entry(tmp, struct ksock_route, ksnr_list);
LASSERT(!route->ksnr_connecting || route->ksnr_scheduled);
if (route->ksnr_scheduled)
continue;
if (!(ksocknal_route_mask() & ~route->ksnr_connected))
continue;
if (!(!route->ksnr_retry_interval ||
cfs_time_aftereq(now, route->ksnr_timeout))) {
CDEBUG(D_NET,
"Too soon to retry route %pI4h (cnted %d, interval %ld, %ld secs later)\n",
&route->ksnr_ipaddr,
route->ksnr_connected,
route->ksnr_retry_interval,
cfs_duration_sec(route->ksnr_timeout - now));
continue;
}
return route;
}
return NULL;
}
struct ksock_route *
ksocknal_find_connecting_route_locked(struct ksock_peer *peer)
{
struct list_head *tmp;
struct ksock_route *route;
list_for_each(tmp, &peer->ksnp_routes) {
route = list_entry(tmp, struct ksock_route, ksnr_list);
LASSERT(!route->ksnr_connecting || route->ksnr_scheduled);
if (route->ksnr_scheduled)
return route;
}
return NULL;
}
int
ksocknal_launch_packet(lnet_ni_t *ni, struct ksock_tx *tx, lnet_process_id_t id)
{
struct ksock_peer *peer;
struct ksock_conn *conn;
rwlock_t *g_lock;
int retry;
int rc;
LASSERT(!tx->tx_conn);
g_lock = &ksocknal_data.ksnd_global_lock;
for (retry = 0;; retry = 1) {
read_lock(g_lock);
peer = ksocknal_find_peer_locked(ni, id);
if (peer) {
if (!ksocknal_find_connectable_route_locked(peer)) {
conn = ksocknal_find_conn_locked(peer, tx, tx->tx_nonblk);
if (conn) {
ksocknal_queue_tx_locked(tx, conn);
read_unlock(g_lock);
return 0;
}
}
}
read_unlock(g_lock);
write_lock_bh(g_lock);
peer = ksocknal_find_peer_locked(ni, id);
if (peer)
break;
write_unlock_bh(g_lock);
if (id.pid & LNET_PID_USERFLAG) {
CERROR("Refusing to create a connection to userspace process %s\n",
libcfs_id2str(id));
return -EHOSTUNREACH;
}
if (retry) {
CERROR("Can't find peer %s\n", libcfs_id2str(id));
return -EHOSTUNREACH;
}
rc = ksocknal_add_peer(ni, id,
LNET_NIDADDR(id.nid),
lnet_acceptor_port());
if (rc) {
CERROR("Can't add peer %s: %d\n",
libcfs_id2str(id), rc);
return rc;
}
}
ksocknal_launch_all_connections_locked(peer);
conn = ksocknal_find_conn_locked(peer, tx, tx->tx_nonblk);
if (conn) {
ksocknal_queue_tx_locked(tx, conn);
write_unlock_bh(g_lock);
return 0;
}
if (peer->ksnp_accepting > 0 ||
ksocknal_find_connecting_route_locked(peer)) {
tx->tx_deadline =
cfs_time_shift(*ksocknal_tunables.ksnd_timeout);
list_add_tail(&tx->tx_list, &peer->ksnp_tx_queue);
write_unlock_bh(g_lock);
return 0;
}
write_unlock_bh(g_lock);
CNETERR("No usable routes to %s\n", libcfs_id2str(id));
return -EHOSTUNREACH;
}
int
ksocknal_send(lnet_ni_t *ni, void *private, lnet_msg_t *lntmsg)
{
int mpflag = 1;
int type = lntmsg->msg_type;
lnet_process_id_t target = lntmsg->msg_target;
unsigned int payload_niov = lntmsg->msg_niov;
struct kvec *payload_iov = lntmsg->msg_iov;
lnet_kiov_t *payload_kiov = lntmsg->msg_kiov;
unsigned int payload_offset = lntmsg->msg_offset;
unsigned int payload_nob = lntmsg->msg_len;
struct ksock_tx *tx;
int desc_size;
int rc;
CDEBUG(D_NET, "sending %u bytes in %d frags to %s\n",
payload_nob, payload_niov, libcfs_id2str(target));
LASSERT(!payload_nob || payload_niov > 0);
LASSERT(payload_niov <= LNET_MAX_IOV);
LASSERT(!(payload_kiov && payload_iov));
LASSERT(!in_interrupt());
if (payload_iov)
desc_size = offsetof(struct ksock_tx,
tx_frags.virt.iov[1 + payload_niov]);
else
desc_size = offsetof(struct ksock_tx,
tx_frags.paged.kiov[payload_niov]);
if (lntmsg->msg_vmflush)
mpflag = cfs_memory_pressure_get_and_set();
tx = ksocknal_alloc_tx(KSOCK_MSG_LNET, desc_size);
if (!tx) {
CERROR("Can't allocate tx desc type %d size %d\n",
type, desc_size);
if (lntmsg->msg_vmflush)
cfs_memory_pressure_restore(mpflag);
return -ENOMEM;
}
tx->tx_conn = NULL;
tx->tx_lnetmsg = lntmsg;
if (payload_iov) {
tx->tx_kiov = NULL;
tx->tx_nkiov = 0;
tx->tx_iov = tx->tx_frags.virt.iov;
tx->tx_niov = 1 +
lnet_extract_iov(payload_niov, &tx->tx_iov[1],
payload_niov, payload_iov,
payload_offset, payload_nob);
} else {
tx->tx_niov = 1;
tx->tx_iov = &tx->tx_frags.paged.iov;
tx->tx_kiov = tx->tx_frags.paged.kiov;
tx->tx_nkiov = lnet_extract_kiov(payload_niov, tx->tx_kiov,
payload_niov, payload_kiov,
payload_offset, payload_nob);
if (payload_nob >= *ksocknal_tunables.ksnd_zc_min_payload)
tx->tx_zc_capable = 1;
}
socklnd_init_msg(&tx->tx_msg, KSOCK_MSG_LNET);
rc = ksocknal_launch_packet(ni, tx, target);
if (!mpflag)
cfs_memory_pressure_restore(mpflag);
if (!rc)
return 0;
ksocknal_free_tx(tx);
return -EIO;
}
int
ksocknal_thread_start(int (*fn)(void *arg), void *arg, char *name)
{
struct task_struct *task = kthread_run(fn, arg, "%s", name);
if (IS_ERR(task))
return PTR_ERR(task);
write_lock_bh(&ksocknal_data.ksnd_global_lock);
ksocknal_data.ksnd_nthreads++;
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
return 0;
}
void
ksocknal_thread_fini(void)
{
write_lock_bh(&ksocknal_data.ksnd_global_lock);
ksocknal_data.ksnd_nthreads--;
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
}
int
ksocknal_new_packet(struct ksock_conn *conn, int nob_to_skip)
{
static char ksocknal_slop_buffer[4096];
int nob;
unsigned int niov;
int skipped;
LASSERT(conn->ksnc_proto);
if (*ksocknal_tunables.ksnd_eager_ack & conn->ksnc_type) {
ksocknal_lib_eager_ack(conn);
}
if (!nob_to_skip) {
conn->ksnc_rx_started = 0;
mb();
switch (conn->ksnc_proto->pro_version) {
case KSOCK_PROTO_V2:
case KSOCK_PROTO_V3:
conn->ksnc_rx_state = SOCKNAL_RX_KSM_HEADER;
conn->ksnc_rx_iov = (struct kvec *)&conn->ksnc_rx_iov_space;
conn->ksnc_rx_iov[0].iov_base = &conn->ksnc_msg;
conn->ksnc_rx_nob_wanted = offsetof(ksock_msg_t, ksm_u);
conn->ksnc_rx_nob_left = offsetof(ksock_msg_t, ksm_u);
conn->ksnc_rx_iov[0].iov_len = offsetof(ksock_msg_t, ksm_u);
break;
case KSOCK_PROTO_V1:
conn->ksnc_rx_state = SOCKNAL_RX_LNET_HEADER;
conn->ksnc_rx_nob_wanted = sizeof(lnet_hdr_t);
conn->ksnc_rx_nob_left = sizeof(lnet_hdr_t);
conn->ksnc_rx_iov = (struct kvec *)&conn->ksnc_rx_iov_space;
conn->ksnc_rx_iov[0].iov_base = &conn->ksnc_msg.ksm_u.lnetmsg;
conn->ksnc_rx_iov[0].iov_len = sizeof(lnet_hdr_t);
break;
default:
LBUG();
}
conn->ksnc_rx_niov = 1;
conn->ksnc_rx_kiov = NULL;
conn->ksnc_rx_nkiov = 0;
conn->ksnc_rx_csum = ~0;
return 1;
}
conn->ksnc_rx_state = SOCKNAL_RX_SLOP;
conn->ksnc_rx_nob_left = nob_to_skip;
conn->ksnc_rx_iov = (struct kvec *)&conn->ksnc_rx_iov_space;
skipped = 0;
niov = 0;
do {
nob = min_t(int, nob_to_skip, sizeof(ksocknal_slop_buffer));
conn->ksnc_rx_iov[niov].iov_base = ksocknal_slop_buffer;
conn->ksnc_rx_iov[niov].iov_len = nob;
niov++;
skipped += nob;
nob_to_skip -= nob;
} while (nob_to_skip &&
niov < sizeof(conn->ksnc_rx_iov_space) / sizeof(struct iovec));
conn->ksnc_rx_niov = niov;
conn->ksnc_rx_kiov = NULL;
conn->ksnc_rx_nkiov = 0;
conn->ksnc_rx_nob_wanted = skipped;
return 0;
}
static int
ksocknal_process_receive(struct ksock_conn *conn)
{
lnet_hdr_t *lhdr;
lnet_process_id_t *id;
int rc;
LASSERT(atomic_read(&conn->ksnc_conn_refcount) > 0);
LASSERT(conn->ksnc_rx_state == SOCKNAL_RX_KSM_HEADER ||
conn->ksnc_rx_state == SOCKNAL_RX_LNET_PAYLOAD ||
conn->ksnc_rx_state == SOCKNAL_RX_LNET_HEADER ||
conn->ksnc_rx_state == SOCKNAL_RX_SLOP);
again:
if (conn->ksnc_rx_nob_wanted) {
rc = ksocknal_receive(conn);
if (rc <= 0) {
LASSERT(rc != -EAGAIN);
if (!rc)
CDEBUG(D_NET, "[%p] EOF from %s ip %pI4h:%d\n",
conn,
libcfs_id2str(conn->ksnc_peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
else if (!conn->ksnc_closing)
CERROR("[%p] Error %d on read from %s ip %pI4h:%d\n",
conn, rc,
libcfs_id2str(conn->ksnc_peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
ksocknal_close_conn_and_siblings(conn,
(conn->ksnc_closing) ? 0 : rc);
return (!rc ? -ESHUTDOWN : rc);
}
if (conn->ksnc_rx_nob_wanted) {
return -EAGAIN;
}
}
switch (conn->ksnc_rx_state) {
case SOCKNAL_RX_KSM_HEADER:
if (conn->ksnc_flip) {
__swab32s(&conn->ksnc_msg.ksm_type);
__swab32s(&conn->ksnc_msg.ksm_csum);
__swab64s(&conn->ksnc_msg.ksm_zc_cookies[0]);
__swab64s(&conn->ksnc_msg.ksm_zc_cookies[1]);
}
if (conn->ksnc_msg.ksm_type != KSOCK_MSG_NOOP &&
conn->ksnc_msg.ksm_type != KSOCK_MSG_LNET) {
CERROR("%s: Unknown message type: %x\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id),
conn->ksnc_msg.ksm_type);
ksocknal_new_packet(conn, 0);
ksocknal_close_conn_and_siblings(conn, -EPROTO);
return -EPROTO;
}
if (conn->ksnc_msg.ksm_type == KSOCK_MSG_NOOP &&
conn->ksnc_msg.ksm_csum &&
conn->ksnc_msg.ksm_csum != conn->ksnc_rx_csum) {
CERROR("%s: Checksum error, wire:0x%08X data:0x%08X\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id),
conn->ksnc_msg.ksm_csum, conn->ksnc_rx_csum);
ksocknal_new_packet(conn, 0);
ksocknal_close_conn_and_siblings(conn, -EPROTO);
return -EIO;
}
if (conn->ksnc_msg.ksm_zc_cookies[1]) {
__u64 cookie = 0;
LASSERT(conn->ksnc_proto != &ksocknal_protocol_v1x);
if (conn->ksnc_msg.ksm_type == KSOCK_MSG_NOOP)
cookie = conn->ksnc_msg.ksm_zc_cookies[0];
rc = conn->ksnc_proto->pro_handle_zcack(conn, cookie,
conn->ksnc_msg.ksm_zc_cookies[1]);
if (rc) {
CERROR("%s: Unknown ZC-ACK cookie: %llu, %llu\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id),
cookie, conn->ksnc_msg.ksm_zc_cookies[1]);
ksocknal_new_packet(conn, 0);
ksocknal_close_conn_and_siblings(conn, -EPROTO);
return rc;
}
}
if (conn->ksnc_msg.ksm_type == KSOCK_MSG_NOOP) {
ksocknal_new_packet(conn, 0);
return 0;
}
conn->ksnc_rx_state = SOCKNAL_RX_LNET_HEADER;
conn->ksnc_rx_nob_wanted = sizeof(ksock_lnet_msg_t);
conn->ksnc_rx_nob_left = sizeof(ksock_lnet_msg_t);
conn->ksnc_rx_iov = (struct kvec *)&conn->ksnc_rx_iov_space;
conn->ksnc_rx_iov[0].iov_base = &conn->ksnc_msg.ksm_u.lnetmsg;
conn->ksnc_rx_iov[0].iov_len = sizeof(ksock_lnet_msg_t);
conn->ksnc_rx_niov = 1;
conn->ksnc_rx_kiov = NULL;
conn->ksnc_rx_nkiov = 0;
goto again;
case SOCKNAL_RX_LNET_HEADER:
conn->ksnc_proto->pro_unpack(&conn->ksnc_msg);
if (conn->ksnc_peer->ksnp_id.pid & LNET_PID_USERFLAG) {
lhdr = &conn->ksnc_msg.ksm_u.lnetmsg.ksnm_hdr;
id = &conn->ksnc_peer->ksnp_id;
lhdr->src_pid = cpu_to_le32(id->pid);
lhdr->src_nid = cpu_to_le64(id->nid);
}
conn->ksnc_rx_state = SOCKNAL_RX_PARSE;
ksocknal_conn_addref(conn);
rc = lnet_parse(conn->ksnc_peer->ksnp_ni,
&conn->ksnc_msg.ksm_u.lnetmsg.ksnm_hdr,
conn->ksnc_peer->ksnp_id.nid, conn, 0);
if (rc < 0) {
ksocknal_new_packet(conn, 0);
ksocknal_close_conn_and_siblings(conn, rc);
ksocknal_conn_decref(conn);
return -EPROTO;
}
LASSERT(conn->ksnc_rx_state == SOCKNAL_RX_PARSE ||
conn->ksnc_rx_state == SOCKNAL_RX_LNET_PAYLOAD);
if (conn->ksnc_rx_state != SOCKNAL_RX_LNET_PAYLOAD)
return 0;
goto again;
case SOCKNAL_RX_LNET_PAYLOAD:
rc = 0;
if (!conn->ksnc_rx_nob_left &&
conn->ksnc_msg.ksm_csum &&
conn->ksnc_msg.ksm_csum != conn->ksnc_rx_csum) {
CERROR("%s: Checksum error, wire:0x%08X data:0x%08X\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id),
conn->ksnc_msg.ksm_csum, conn->ksnc_rx_csum);
rc = -EIO;
}
if (!rc && conn->ksnc_msg.ksm_zc_cookies[0]) {
LASSERT(conn->ksnc_proto != &ksocknal_protocol_v1x);
lhdr = &conn->ksnc_msg.ksm_u.lnetmsg.ksnm_hdr;
id = &conn->ksnc_peer->ksnp_id;
rc = conn->ksnc_proto->pro_handle_zcreq(conn,
conn->ksnc_msg.ksm_zc_cookies[0],
*ksocknal_tunables.ksnd_nonblk_zcack ||
le64_to_cpu(lhdr->src_nid) != id->nid);
}
lnet_finalize(conn->ksnc_peer->ksnp_ni, conn->ksnc_cookie, rc);
if (rc) {
ksocknal_new_packet(conn, 0);
ksocknal_close_conn_and_siblings(conn, rc);
return -EPROTO;
}
case SOCKNAL_RX_SLOP:
if (ksocknal_new_packet(conn, conn->ksnc_rx_nob_left))
return 0;
goto again;
default:
break;
}
LBUG();
return -EINVAL;
}
int
ksocknal_recv(lnet_ni_t *ni, void *private, lnet_msg_t *msg, int delayed,
unsigned int niov, struct kvec *iov, lnet_kiov_t *kiov,
unsigned int offset, unsigned int mlen, unsigned int rlen)
{
struct ksock_conn *conn = private;
struct ksock_sched *sched = conn->ksnc_scheduler;
LASSERT(mlen <= rlen);
LASSERT(niov <= LNET_MAX_IOV);
conn->ksnc_cookie = msg;
conn->ksnc_rx_nob_wanted = mlen;
conn->ksnc_rx_nob_left = rlen;
if (!mlen || iov) {
conn->ksnc_rx_nkiov = 0;
conn->ksnc_rx_kiov = NULL;
conn->ksnc_rx_iov = conn->ksnc_rx_iov_space.iov;
conn->ksnc_rx_niov =
lnet_extract_iov(LNET_MAX_IOV, conn->ksnc_rx_iov,
niov, iov, offset, mlen);
} else {
conn->ksnc_rx_niov = 0;
conn->ksnc_rx_iov = NULL;
conn->ksnc_rx_kiov = conn->ksnc_rx_iov_space.kiov;
conn->ksnc_rx_nkiov =
lnet_extract_kiov(LNET_MAX_IOV, conn->ksnc_rx_kiov,
niov, kiov, offset, mlen);
}
LASSERT(mlen ==
lnet_iov_nob(conn->ksnc_rx_niov, conn->ksnc_rx_iov) +
lnet_kiov_nob(conn->ksnc_rx_nkiov, conn->ksnc_rx_kiov));
LASSERT(conn->ksnc_rx_scheduled);
spin_lock_bh(&sched->kss_lock);
switch (conn->ksnc_rx_state) {
case SOCKNAL_RX_PARSE_WAIT:
list_add_tail(&conn->ksnc_rx_list, &sched->kss_rx_conns);
wake_up(&sched->kss_waitq);
LASSERT(conn->ksnc_rx_ready);
break;
case SOCKNAL_RX_PARSE:
break;
}
conn->ksnc_rx_state = SOCKNAL_RX_LNET_PAYLOAD;
spin_unlock_bh(&sched->kss_lock);
ksocknal_conn_decref(conn);
return 0;
}
static inline int
ksocknal_sched_cansleep(struct ksock_sched *sched)
{
int rc;
spin_lock_bh(&sched->kss_lock);
rc = !ksocknal_data.ksnd_shuttingdown &&
list_empty(&sched->kss_rx_conns) &&
list_empty(&sched->kss_tx_conns);
spin_unlock_bh(&sched->kss_lock);
return rc;
}
int ksocknal_scheduler(void *arg)
{
struct ksock_sched_info *info;
struct ksock_sched *sched;
struct ksock_conn *conn;
struct ksock_tx *tx;
int rc;
int nloops = 0;
long id = (long)arg;
info = ksocknal_data.ksnd_sched_info[KSOCK_THREAD_CPT(id)];
sched = &info->ksi_scheds[KSOCK_THREAD_SID(id)];
cfs_block_allsigs();
rc = cfs_cpt_bind(lnet_cpt_table(), info->ksi_cpt);
if (rc) {
CERROR("Can't set CPT affinity to %d: %d\n",
info->ksi_cpt, rc);
}
spin_lock_bh(&sched->kss_lock);
while (!ksocknal_data.ksnd_shuttingdown) {
int did_something = 0;
if (!list_empty(&sched->kss_rx_conns)) {
conn = list_entry(sched->kss_rx_conns.next,
struct ksock_conn, ksnc_rx_list);
list_del(&conn->ksnc_rx_list);
LASSERT(conn->ksnc_rx_scheduled);
LASSERT(conn->ksnc_rx_ready);
conn->ksnc_rx_ready = 0;
spin_unlock_bh(&sched->kss_lock);
rc = ksocknal_process_receive(conn);
spin_lock_bh(&sched->kss_lock);
LASSERT(conn->ksnc_rx_scheduled);
if (!rc)
conn->ksnc_rx_ready = 1;
if (conn->ksnc_rx_state == SOCKNAL_RX_PARSE) {
conn->ksnc_rx_state = SOCKNAL_RX_PARSE_WAIT;
} else if (conn->ksnc_rx_ready) {
list_add_tail(&conn->ksnc_rx_list,
&sched->kss_rx_conns);
} else {
conn->ksnc_rx_scheduled = 0;
ksocknal_conn_decref(conn);
}
did_something = 1;
}
if (!list_empty(&sched->kss_tx_conns)) {
LIST_HEAD(zlist);
if (!list_empty(&sched->kss_zombie_noop_txs)) {
list_add(&zlist, &sched->kss_zombie_noop_txs);
list_del_init(&sched->kss_zombie_noop_txs);
}
conn = list_entry(sched->kss_tx_conns.next,
struct ksock_conn, ksnc_tx_list);
list_del(&conn->ksnc_tx_list);
LASSERT(conn->ksnc_tx_scheduled);
LASSERT(conn->ksnc_tx_ready);
LASSERT(!list_empty(&conn->ksnc_tx_queue));
tx = list_entry(conn->ksnc_tx_queue.next,
struct ksock_tx, tx_list);
if (conn->ksnc_tx_carrier == tx)
ksocknal_next_tx_carrier(conn);
list_del(&tx->tx_list);
conn->ksnc_tx_ready = 0;
spin_unlock_bh(&sched->kss_lock);
if (!list_empty(&zlist)) {
ksocknal_txlist_done(NULL, &zlist, 0);
}
rc = ksocknal_process_transmit(conn, tx);
if (rc == -ENOMEM || rc == -EAGAIN) {
spin_lock_bh(&sched->kss_lock);
list_add(&tx->tx_list, &conn->ksnc_tx_queue);
} else {
ksocknal_tx_decref(tx);
spin_lock_bh(&sched->kss_lock);
conn->ksnc_tx_ready = 1;
}
if (rc == -ENOMEM) {
} else if (conn->ksnc_tx_ready &&
!list_empty(&conn->ksnc_tx_queue)) {
list_add_tail(&conn->ksnc_tx_list,
&sched->kss_tx_conns);
} else {
conn->ksnc_tx_scheduled = 0;
ksocknal_conn_decref(conn);
}
did_something = 1;
}
if (!did_something ||
++nloops == SOCKNAL_RESCHED) {
spin_unlock_bh(&sched->kss_lock);
nloops = 0;
if (!did_something) {
rc = wait_event_interruptible_exclusive(
sched->kss_waitq,
!ksocknal_sched_cansleep(sched));
LASSERT(!rc);
} else {
cond_resched();
}
spin_lock_bh(&sched->kss_lock);
}
}
spin_unlock_bh(&sched->kss_lock);
ksocknal_thread_fini();
return 0;
}
void ksocknal_read_callback(struct ksock_conn *conn)
{
struct ksock_sched *sched;
sched = conn->ksnc_scheduler;
spin_lock_bh(&sched->kss_lock);
conn->ksnc_rx_ready = 1;
if (!conn->ksnc_rx_scheduled) {
list_add_tail(&conn->ksnc_rx_list, &sched->kss_rx_conns);
conn->ksnc_rx_scheduled = 1;
ksocknal_conn_addref(conn);
wake_up(&sched->kss_waitq);
}
spin_unlock_bh(&sched->kss_lock);
}
void ksocknal_write_callback(struct ksock_conn *conn)
{
struct ksock_sched *sched;
sched = conn->ksnc_scheduler;
spin_lock_bh(&sched->kss_lock);
conn->ksnc_tx_ready = 1;
if (!conn->ksnc_tx_scheduled &&
!list_empty(&conn->ksnc_tx_queue)) {
list_add_tail(&conn->ksnc_tx_list, &sched->kss_tx_conns);
conn->ksnc_tx_scheduled = 1;
ksocknal_conn_addref(conn);
wake_up(&sched->kss_waitq);
}
spin_unlock_bh(&sched->kss_lock);
}
static struct ksock_proto *
ksocknal_parse_proto_version(ksock_hello_msg_t *hello)
{
__u32 version = 0;
if (hello->kshm_magic == LNET_PROTO_MAGIC)
version = hello->kshm_version;
else if (hello->kshm_magic == __swab32(LNET_PROTO_MAGIC))
version = __swab32(hello->kshm_version);
if (version) {
#if SOCKNAL_VERSION_DEBUG
if (*ksocknal_tunables.ksnd_protocol == 1)
return NULL;
if (*ksocknal_tunables.ksnd_protocol == 2 &&
version == KSOCK_PROTO_V3)
return NULL;
#endif
if (version == KSOCK_PROTO_V2)
return &ksocknal_protocol_v2x;
if (version == KSOCK_PROTO_V3)
return &ksocknal_protocol_v3x;
return NULL;
}
if (hello->kshm_magic == le32_to_cpu(LNET_PROTO_TCP_MAGIC)) {
lnet_magicversion_t *hmv = (lnet_magicversion_t *)hello;
CLASSERT(sizeof(lnet_magicversion_t) ==
offsetof(ksock_hello_msg_t, kshm_src_nid));
if (hmv->version_major == cpu_to_le16(KSOCK_PROTO_V1_MAJOR) &&
hmv->version_minor == cpu_to_le16(KSOCK_PROTO_V1_MINOR))
return &ksocknal_protocol_v1x;
}
return NULL;
}
int
ksocknal_send_hello(lnet_ni_t *ni, struct ksock_conn *conn,
lnet_nid_t peer_nid, ksock_hello_msg_t *hello)
{
struct ksock_net *net = (struct ksock_net *)ni->ni_data;
LASSERT(hello->kshm_nips <= LNET_MAX_INTERFACES);
LASSERT(conn->ksnc_proto);
hello->kshm_src_nid = ni->ni_nid;
hello->kshm_dst_nid = peer_nid;
hello->kshm_src_pid = the_lnet.ln_pid;
hello->kshm_src_incarnation = net->ksnn_incarnation;
hello->kshm_ctype = conn->ksnc_type;
return conn->ksnc_proto->pro_send_hello(conn, hello);
}
static int
ksocknal_invert_type(int type)
{
switch (type) {
case SOCKLND_CONN_ANY:
case SOCKLND_CONN_CONTROL:
return type;
case SOCKLND_CONN_BULK_IN:
return SOCKLND_CONN_BULK_OUT;
case SOCKLND_CONN_BULK_OUT:
return SOCKLND_CONN_BULK_IN;
default:
return SOCKLND_CONN_NONE;
}
}
int
ksocknal_recv_hello(lnet_ni_t *ni, struct ksock_conn *conn,
ksock_hello_msg_t *hello, lnet_process_id_t *peerid,
__u64 *incarnation)
{
struct socket *sock = conn->ksnc_sock;
int active = !!conn->ksnc_proto;
int timeout;
int proto_match;
int rc;
struct ksock_proto *proto;
lnet_process_id_t recv_id;
LASSERT(!active == !(conn->ksnc_type != SOCKLND_CONN_NONE));
timeout = active ? *ksocknal_tunables.ksnd_timeout :
lnet_acceptor_timeout();
rc = lnet_sock_read(sock, &hello->kshm_magic, sizeof(hello->kshm_magic), timeout);
if (rc) {
CERROR("Error %d reading HELLO from %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0);
return rc;
}
if (hello->kshm_magic != LNET_PROTO_MAGIC &&
hello->kshm_magic != __swab32(LNET_PROTO_MAGIC) &&
hello->kshm_magic != le32_to_cpu(LNET_PROTO_TCP_MAGIC)) {
CERROR("Bad magic(1) %#08x (%#08x expected) from %pI4h\n",
__cpu_to_le32(hello->kshm_magic),
LNET_PROTO_TCP_MAGIC,
&conn->ksnc_ipaddr);
return -EPROTO;
}
rc = lnet_sock_read(sock, &hello->kshm_version,
sizeof(hello->kshm_version), timeout);
if (rc) {
CERROR("Error %d reading HELLO from %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0);
return rc;
}
proto = ksocknal_parse_proto_version(hello);
if (!proto) {
if (!active) {
conn->ksnc_proto = &ksocknal_protocol_v3x;
#if SOCKNAL_VERSION_DEBUG
if (*ksocknal_tunables.ksnd_protocol == 2)
conn->ksnc_proto = &ksocknal_protocol_v2x;
else if (*ksocknal_tunables.ksnd_protocol == 1)
conn->ksnc_proto = &ksocknal_protocol_v1x;
#endif
hello->kshm_nips = 0;
ksocknal_send_hello(ni, conn, ni->ni_nid, hello);
}
CERROR("Unknown protocol version (%d.x expected) from %pI4h\n",
conn->ksnc_proto->pro_version,
&conn->ksnc_ipaddr);
return -EPROTO;
}
proto_match = (conn->ksnc_proto == proto);
conn->ksnc_proto = proto;
rc = conn->ksnc_proto->pro_recv_hello(conn, hello, timeout);
if (rc) {
CERROR("Error %d reading or checking hello from from %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0);
return rc;
}
*incarnation = hello->kshm_src_incarnation;
if (hello->kshm_src_nid == LNET_NID_ANY) {
CERROR("Expecting a HELLO hdr with a NID, but got LNET_NID_ANY from %pI4h\n",
&conn->ksnc_ipaddr);
return -EPROTO;
}
if (!active &&
conn->ksnc_port > LNET_ACCEPTOR_MAX_RESERVED_PORT) {
recv_id.pid = conn->ksnc_port | LNET_PID_USERFLAG;
recv_id.nid = LNET_MKNID(LNET_NIDNET(ni->ni_nid), conn->ksnc_ipaddr);
} else {
recv_id.nid = hello->kshm_src_nid;
recv_id.pid = hello->kshm_src_pid;
}
if (!active) {
*peerid = recv_id;
conn->ksnc_type = ksocknal_invert_type(hello->kshm_ctype);
if (conn->ksnc_type == SOCKLND_CONN_NONE) {
CERROR("Unexpected type %d from %s ip %pI4h\n",
hello->kshm_ctype, libcfs_id2str(*peerid),
&conn->ksnc_ipaddr);
return -EPROTO;
}
return 0;
}
if (peerid->pid != recv_id.pid ||
peerid->nid != recv_id.nid) {
LCONSOLE_ERROR_MSG(0x130, "Connected successfully to %s on host %pI4h, but they claimed they were %s; please check your Lustre configuration.\n",
libcfs_id2str(*peerid),
&conn->ksnc_ipaddr,
libcfs_id2str(recv_id));
return -EPROTO;
}
if (hello->kshm_ctype == SOCKLND_CONN_NONE) {
return proto_match ? EALREADY : EPROTO;
}
if (ksocknal_invert_type(hello->kshm_ctype) != conn->ksnc_type) {
CERROR("Mismatched types: me %d, %s ip %pI4h %d\n",
conn->ksnc_type, libcfs_id2str(*peerid),
&conn->ksnc_ipaddr, hello->kshm_ctype);
return -EPROTO;
}
return 0;
}
static int
ksocknal_connect(struct ksock_route *route)
{
LIST_HEAD(zombies);
struct ksock_peer *peer = route->ksnr_peer;
int type;
int wanted;
struct socket *sock;
unsigned long deadline;
int retry_later = 0;
int rc = 0;
deadline = cfs_time_add(cfs_time_current(),
cfs_time_seconds(*ksocknal_tunables.ksnd_timeout));
write_lock_bh(&ksocknal_data.ksnd_global_lock);
LASSERT(route->ksnr_scheduled);
LASSERT(!route->ksnr_connecting);
route->ksnr_connecting = 1;
for (;;) {
wanted = ksocknal_route_mask() & ~route->ksnr_connected;
if (peer->ksnp_closing || route->ksnr_deleted ||
!wanted) {
retry_later = 0;
break;
}
if (peer->ksnp_accepting > 0) {
CDEBUG(D_NET,
"peer %s(%d) already connecting to me, retry later.\n",
libcfs_nid2str(peer->ksnp_id.nid), peer->ksnp_accepting);
retry_later = 1;
}
if (retry_later)
break;
if (wanted & (1 << SOCKLND_CONN_ANY)) {
type = SOCKLND_CONN_ANY;
} else if (wanted & (1 << SOCKLND_CONN_CONTROL)) {
type = SOCKLND_CONN_CONTROL;
} else if (wanted & (1 << SOCKLND_CONN_BULK_IN)) {
type = SOCKLND_CONN_BULK_IN;
} else {
LASSERT(wanted & (1 << SOCKLND_CONN_BULK_OUT));
type = SOCKLND_CONN_BULK_OUT;
}
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
if (cfs_time_aftereq(cfs_time_current(), deadline)) {
rc = -ETIMEDOUT;
lnet_connect_console_error(rc, peer->ksnp_id.nid,
route->ksnr_ipaddr,
route->ksnr_port);
goto failed;
}
rc = lnet_connect(&sock, peer->ksnp_id.nid,
route->ksnr_myipaddr,
route->ksnr_ipaddr, route->ksnr_port);
if (rc)
goto failed;
rc = ksocknal_create_conn(peer->ksnp_ni, route, sock, type);
if (rc < 0) {
lnet_connect_console_error(rc, peer->ksnp_id.nid,
route->ksnr_ipaddr,
route->ksnr_port);
goto failed;
}
retry_later = (rc);
if (retry_later)
CDEBUG(D_NET, "peer %s: conn race, retry later.\n",
libcfs_nid2str(peer->ksnp_id.nid));
write_lock_bh(&ksocknal_data.ksnd_global_lock);
}
route->ksnr_scheduled = 0;
route->ksnr_connecting = 0;
if (retry_later) {
if (rc == EALREADY ||
(!rc && peer->ksnp_accepting > 0)) {
route->ksnr_retry_interval =
cfs_time_seconds(*ksocknal_tunables.ksnd_min_reconnectms) / 1000;
route->ksnr_timeout = cfs_time_add(cfs_time_current(),
route->ksnr_retry_interval);
}
ksocknal_launch_connection_locked(route);
}
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
return retry_later;
failed:
write_lock_bh(&ksocknal_data.ksnd_global_lock);
route->ksnr_scheduled = 0;
route->ksnr_connecting = 0;
route->ksnr_retry_interval *= 2;
route->ksnr_retry_interval =
max(route->ksnr_retry_interval,
cfs_time_seconds(*ksocknal_tunables.ksnd_min_reconnectms) / 1000);
route->ksnr_retry_interval =
min(route->ksnr_retry_interval,
cfs_time_seconds(*ksocknal_tunables.ksnd_max_reconnectms) / 1000);
LASSERT(route->ksnr_retry_interval);
route->ksnr_timeout = cfs_time_add(cfs_time_current(),
route->ksnr_retry_interval);
if (!list_empty(&peer->ksnp_tx_queue) &&
!peer->ksnp_accepting &&
!ksocknal_find_connecting_route_locked(peer)) {
struct ksock_conn *conn;
if (!list_empty(&peer->ksnp_conns)) {
conn = list_entry(peer->ksnp_conns.next,
struct ksock_conn, ksnc_list);
LASSERT(conn->ksnc_proto == &ksocknal_protocol_v3x);
}
list_splice_init(&peer->ksnp_tx_queue, &zombies);
}
#if 0
if (!route->ksnr_deleted) {
list_del(&route->ksnr_list);
list_add_tail(&route->ksnr_list, &peer->ksnp_routes);
}
#endif
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
ksocknal_peer_failed(peer);
ksocknal_txlist_done(peer->ksnp_ni, &zombies, 1);
return 0;
}
static int
ksocknal_connd_check_start(time64_t sec, long *timeout)
{
char name[16];
int rc;
int total = ksocknal_data.ksnd_connd_starting +
ksocknal_data.ksnd_connd_running;
if (unlikely(ksocknal_data.ksnd_init < SOCKNAL_INIT_ALL)) {
return 0;
}
if (total >= *ksocknal_tunables.ksnd_nconnds_max ||
total > ksocknal_data.ksnd_connd_connecting + SOCKNAL_CONND_RESV) {
return 0;
}
if (list_empty(&ksocknal_data.ksnd_connd_routes)) {
return 0;
}
if (sec - ksocknal_data.ksnd_connd_failed_stamp <= 1) {
*timeout = cfs_time_seconds(1);
return 0;
}
if (ksocknal_data.ksnd_connd_starting > 0) {
return 0;
}
ksocknal_data.ksnd_connd_starting_stamp = sec;
ksocknal_data.ksnd_connd_starting++;
spin_unlock_bh(&ksocknal_data.ksnd_connd_lock);
snprintf(name, sizeof(name), "socknal_cd%02d", total);
rc = ksocknal_thread_start(ksocknal_connd, NULL, name);
spin_lock_bh(&ksocknal_data.ksnd_connd_lock);
if (!rc)
return 1;
LASSERT(ksocknal_data.ksnd_connd_starting > 0);
ksocknal_data.ksnd_connd_starting--;
ksocknal_data.ksnd_connd_failed_stamp = ktime_get_real_seconds();
return 1;
}
static int
ksocknal_connd_check_stop(time64_t sec, long *timeout)
{
int val;
if (unlikely(ksocknal_data.ksnd_init < SOCKNAL_INIT_ALL)) {
return 0;
}
if (ksocknal_data.ksnd_connd_starting > 0) {
return 0;
}
if (ksocknal_data.ksnd_connd_running <=
*ksocknal_tunables.ksnd_nconnds) {
return 0;
}
val = (int)(ksocknal_data.ksnd_connd_starting_stamp +
SOCKNAL_CONND_TIMEOUT - sec);
*timeout = (val > 0) ? cfs_time_seconds(val) :
cfs_time_seconds(SOCKNAL_CONND_TIMEOUT);
if (val > 0)
return 0;
return ksocknal_data.ksnd_connd_running >
ksocknal_data.ksnd_connd_connecting + SOCKNAL_CONND_RESV;
}
static struct ksock_route *
ksocknal_connd_get_route_locked(signed long *timeout_p)
{
struct ksock_route *route;
unsigned long now;
now = cfs_time_current();
list_for_each_entry(route, &ksocknal_data.ksnd_connd_routes,
ksnr_connd_list) {
if (!route->ksnr_retry_interval ||
cfs_time_aftereq(now, route->ksnr_timeout))
return route;
if (*timeout_p == MAX_SCHEDULE_TIMEOUT ||
(int)*timeout_p > (int)(route->ksnr_timeout - now))
*timeout_p = (int)(route->ksnr_timeout - now);
}
return NULL;
}
int
ksocknal_connd(void *arg)
{
spinlock_t *connd_lock = &ksocknal_data.ksnd_connd_lock;
struct ksock_connreq *cr;
wait_queue_t wait;
int nloops = 0;
int cons_retry = 0;
cfs_block_allsigs();
init_waitqueue_entry(&wait, current);
spin_lock_bh(connd_lock);
LASSERT(ksocknal_data.ksnd_connd_starting > 0);
ksocknal_data.ksnd_connd_starting--;
ksocknal_data.ksnd_connd_running++;
while (!ksocknal_data.ksnd_shuttingdown) {
struct ksock_route *route = NULL;
time64_t sec = ktime_get_real_seconds();
long timeout = MAX_SCHEDULE_TIMEOUT;
int dropped_lock = 0;
if (ksocknal_connd_check_stop(sec, &timeout)) {
wake_up(&ksocknal_data.ksnd_connd_waitq);
break;
}
if (ksocknal_connd_check_start(sec, &timeout)) {
dropped_lock = 1;
}
if (!list_empty(&ksocknal_data.ksnd_connd_connreqs)) {
cr = list_entry(ksocknal_data.ksnd_connd_connreqs.next,
struct ksock_connreq, ksncr_list);
list_del(&cr->ksncr_list);
spin_unlock_bh(connd_lock);
dropped_lock = 1;
ksocknal_create_conn(cr->ksncr_ni, NULL,
cr->ksncr_sock, SOCKLND_CONN_NONE);
lnet_ni_decref(cr->ksncr_ni);
LIBCFS_FREE(cr, sizeof(*cr));
spin_lock_bh(connd_lock);
}
if (ksocknal_data.ksnd_connd_connecting + SOCKNAL_CONND_RESV <
ksocknal_data.ksnd_connd_running) {
route = ksocknal_connd_get_route_locked(&timeout);
}
if (route) {
list_del(&route->ksnr_connd_list);
ksocknal_data.ksnd_connd_connecting++;
spin_unlock_bh(connd_lock);
dropped_lock = 1;
if (ksocknal_connect(route)) {
if (cons_retry++ > SOCKNAL_INSANITY_RECONN) {
CWARN("massive consecutive re-connecting to %pI4h\n",
&route->ksnr_ipaddr);
cons_retry = 0;
}
} else {
cons_retry = 0;
}
ksocknal_route_decref(route);
spin_lock_bh(connd_lock);
ksocknal_data.ksnd_connd_connecting--;
}
if (dropped_lock) {
if (++nloops < SOCKNAL_RESCHED)
continue;
spin_unlock_bh(connd_lock);
nloops = 0;
cond_resched();
spin_lock_bh(connd_lock);
continue;
}
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue_exclusive(&ksocknal_data.ksnd_connd_waitq, &wait);
spin_unlock_bh(connd_lock);
nloops = 0;
schedule_timeout(timeout);
remove_wait_queue(&ksocknal_data.ksnd_connd_waitq, &wait);
spin_lock_bh(connd_lock);
}
ksocknal_data.ksnd_connd_running--;
spin_unlock_bh(connd_lock);
ksocknal_thread_fini();
return 0;
}
static struct ksock_conn *
ksocknal_find_timed_out_conn(struct ksock_peer *peer)
{
struct ksock_conn *conn;
struct list_head *ctmp;
list_for_each(ctmp, &peer->ksnp_conns) {
int error;
conn = list_entry(ctmp, struct ksock_conn, ksnc_list);
LASSERT(!conn->ksnc_closing);
error = conn->ksnc_sock->sk->sk_err;
if (error) {
ksocknal_conn_addref(conn);
switch (error) {
case ECONNRESET:
CNETERR("A connection with %s (%pI4h:%d) was reset; it may have rebooted.\n",
libcfs_id2str(peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
break;
case ETIMEDOUT:
CNETERR("A connection with %s (%pI4h:%d) timed out; the network or node may be down.\n",
libcfs_id2str(peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
break;
default:
CNETERR("An unexpected network error %d occurred with %s (%pI4h:%d\n",
error,
libcfs_id2str(peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
break;
}
return conn;
}
if (conn->ksnc_rx_started &&
cfs_time_aftereq(cfs_time_current(),
conn->ksnc_rx_deadline)) {
ksocknal_conn_addref(conn);
CNETERR("Timeout receiving from %s (%pI4h:%d), state %d wanted %d left %d\n",
libcfs_id2str(peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port,
conn->ksnc_rx_state,
conn->ksnc_rx_nob_wanted,
conn->ksnc_rx_nob_left);
return conn;
}
if ((!list_empty(&conn->ksnc_tx_queue) ||
conn->ksnc_sock->sk->sk_wmem_queued) &&
cfs_time_aftereq(cfs_time_current(),
conn->ksnc_tx_deadline)) {
ksocknal_conn_addref(conn);
CNETERR("Timeout sending data to %s (%pI4h:%d) the network or that node may be down.\n",
libcfs_id2str(peer->ksnp_id),
&conn->ksnc_ipaddr,
conn->ksnc_port);
return conn;
}
}
return NULL;
}
static inline void
ksocknal_flush_stale_txs(struct ksock_peer *peer)
{
struct ksock_tx *tx;
struct ksock_tx *tmp;
LIST_HEAD(stale_txs);
write_lock_bh(&ksocknal_data.ksnd_global_lock);
list_for_each_entry_safe(tx, tmp, &peer->ksnp_tx_queue, tx_list) {
if (!cfs_time_aftereq(cfs_time_current(),
tx->tx_deadline))
break;
list_del(&tx->tx_list);
list_add_tail(&tx->tx_list, &stale_txs);
}
write_unlock_bh(&ksocknal_data.ksnd_global_lock);
ksocknal_txlist_done(peer->ksnp_ni, &stale_txs, 1);
}
static int
ksocknal_send_keepalive_locked(struct ksock_peer *peer)
__must_hold(&ksocknal_data.ksnd_global_lock
static void
ksocknal_check_peer_timeouts(int idx)
{
struct list_head *peers = &ksocknal_data.ksnd_peers[idx];
struct ksock_peer *peer;
struct ksock_conn *conn;
struct ksock_tx *tx;
again:
read_lock(&ksocknal_data.ksnd_global_lock);
list_for_each_entry(peer, peers, ksnp_list) {
unsigned long deadline = 0;
int resid = 0;
int n = 0;
if (ksocknal_send_keepalive_locked(peer)) {
read_unlock(&ksocknal_data.ksnd_global_lock);
goto again;
}
conn = ksocknal_find_timed_out_conn(peer);
if (conn) {
read_unlock(&ksocknal_data.ksnd_global_lock);
ksocknal_close_conn_and_siblings(conn, -ETIMEDOUT);
ksocknal_conn_decref(conn);
goto again;
}
if (!list_empty(&peer->ksnp_tx_queue)) {
struct ksock_tx *tx = list_entry(peer->ksnp_tx_queue.next,
struct ksock_tx, tx_list);
if (cfs_time_aftereq(cfs_time_current(),
tx->tx_deadline)) {
ksocknal_peer_addref(peer);
read_unlock(&ksocknal_data.ksnd_global_lock);
ksocknal_flush_stale_txs(peer);
ksocknal_peer_decref(peer);
goto again;
}
}
if (list_empty(&peer->ksnp_zc_req_list))
continue;
spin_lock(&peer->ksnp_lock);
list_for_each_entry(tx, &peer->ksnp_zc_req_list, tx_zc_list) {
if (!cfs_time_aftereq(cfs_time_current(),
tx->tx_deadline))
break;
if (tx->tx_conn->ksnc_closing)
continue;
n++;
}
if (!n) {
spin_unlock(&peer->ksnp_lock);
continue;
}
tx = list_entry(peer->ksnp_zc_req_list.next,
struct ksock_tx, tx_zc_list);
deadline = tx->tx_deadline;
resid = tx->tx_resid;
conn = tx->tx_conn;
ksocknal_conn_addref(conn);
spin_unlock(&peer->ksnp_lock);
read_unlock(&ksocknal_data.ksnd_global_lock);
CERROR("Total %d stale ZC_REQs for peer %s detected; the oldest(%p) timed out %ld secs ago, resid: %d, wmem: %d\n",
n, libcfs_nid2str(peer->ksnp_id.nid), tx,
cfs_duration_sec(cfs_time_current() - deadline),
resid, conn->ksnc_sock->sk->sk_wmem_queued);
ksocknal_close_conn_and_siblings(conn, -ETIMEDOUT);
ksocknal_conn_decref(conn);
goto again;
}
read_unlock(&ksocknal_data.ksnd_global_lock);
}
int
ksocknal_reaper(void *arg)
{
wait_queue_t wait;
struct ksock_conn *conn;
struct ksock_sched *sched;
struct list_head enomem_conns;
int nenomem_conns;
long timeout;
int i;
int peer_index = 0;
unsigned long deadline = cfs_time_current();
cfs_block_allsigs();
INIT_LIST_HEAD(&enomem_conns);
init_waitqueue_entry(&wait, current);
spin_lock_bh(&ksocknal_data.ksnd_reaper_lock);
while (!ksocknal_data.ksnd_shuttingdown) {
if (!list_empty(&ksocknal_data.ksnd_deathrow_conns)) {
conn = list_entry(ksocknal_data.ksnd_deathrow_conns.next,
struct ksock_conn, ksnc_list);
list_del(&conn->ksnc_list);
spin_unlock_bh(&ksocknal_data.ksnd_reaper_lock);
ksocknal_terminate_conn(conn);
ksocknal_conn_decref(conn);
spin_lock_bh(&ksocknal_data.ksnd_reaper_lock);
continue;
}
if (!list_empty(&ksocknal_data.ksnd_zombie_conns)) {
conn = list_entry(ksocknal_data.ksnd_zombie_conns.next,
struct ksock_conn, ksnc_list);
list_del(&conn->ksnc_list);
spin_unlock_bh(&ksocknal_data.ksnd_reaper_lock);
ksocknal_destroy_conn(conn);
spin_lock_bh(&ksocknal_data.ksnd_reaper_lock);
continue;
}
if (!list_empty(&ksocknal_data.ksnd_enomem_conns)) {
list_add(&enomem_conns,
&ksocknal_data.ksnd_enomem_conns);
list_del_init(&ksocknal_data.ksnd_enomem_conns);
}
spin_unlock_bh(&ksocknal_data.ksnd_reaper_lock);
nenomem_conns = 0;
while (!list_empty(&enomem_conns)) {
conn = list_entry(enomem_conns.next, struct ksock_conn,
ksnc_tx_list);
list_del(&conn->ksnc_tx_list);
sched = conn->ksnc_scheduler;
spin_lock_bh(&sched->kss_lock);
LASSERT(conn->ksnc_tx_scheduled);
conn->ksnc_tx_ready = 1;
list_add_tail(&conn->ksnc_tx_list,
&sched->kss_tx_conns);
wake_up(&sched->kss_waitq);
spin_unlock_bh(&sched->kss_lock);
nenomem_conns++;
}
while ((timeout = cfs_time_sub(deadline,
cfs_time_current())) <= 0) {
const int n = 4;
const int p = 1;
int chunk = ksocknal_data.ksnd_peer_hash_size;
if (*ksocknal_tunables.ksnd_timeout > n * p)
chunk = (chunk * n * p) /
*ksocknal_tunables.ksnd_timeout;
if (!chunk)
chunk = 1;
for (i = 0; i < chunk; i++) {
ksocknal_check_peer_timeouts(peer_index);
peer_index = (peer_index + 1) %
ksocknal_data.ksnd_peer_hash_size;
}
deadline = cfs_time_add(deadline, cfs_time_seconds(p));
}
if (nenomem_conns) {
timeout = SOCKNAL_ENOMEM_RETRY;
}
ksocknal_data.ksnd_reaper_waketime =
cfs_time_add(cfs_time_current(), timeout);
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&ksocknal_data.ksnd_reaper_waitq, &wait);
if (!ksocknal_data.ksnd_shuttingdown &&
list_empty(&ksocknal_data.ksnd_deathrow_conns) &&
list_empty(&ksocknal_data.ksnd_zombie_conns))
schedule_timeout(timeout);
set_current_state(TASK_RUNNING);
remove_wait_queue(&ksocknal_data.ksnd_reaper_waitq, &wait);
spin_lock_bh(&ksocknal_data.ksnd_reaper_lock);
}
spin_unlock_bh(&ksocknal_data.ksnd_reaper_lock);
ksocknal_thread_fini();
return 0;
}
