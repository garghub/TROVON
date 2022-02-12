static ksock_tx_t *
ksocknal_queue_tx_msg_v1(ksock_conn_t *conn, ksock_tx_t *tx_msg)
{
list_add_tail(&tx_msg->tx_list, &conn->ksnc_tx_queue);
return NULL;
}
void
ksocknal_next_tx_carrier(ksock_conn_t *conn)
{
ksock_tx_t *tx = conn->ksnc_tx_carrier;
LASSERT (!list_empty(&conn->ksnc_tx_queue));
LASSERT (tx != NULL);
if (tx->tx_list.next == &conn->ksnc_tx_queue) {
conn->ksnc_tx_carrier = NULL;
} else {
conn->ksnc_tx_carrier = list_entry(tx->tx_list.next,
ksock_tx_t, tx_list);
LASSERT (conn->ksnc_tx_carrier->tx_msg.ksm_type == tx->tx_msg.ksm_type);
}
}
static int
ksocknal_queue_tx_zcack_v2(ksock_conn_t *conn,
ksock_tx_t *tx_ack, __u64 cookie)
{
ksock_tx_t *tx = conn->ksnc_tx_carrier;
LASSERT (tx_ack == NULL ||
tx_ack->tx_msg.ksm_type == KSOCK_MSG_NOOP);
if (tx == NULL) {
if (tx_ack != NULL) {
list_add_tail(&tx_ack->tx_list,
&conn->ksnc_tx_queue);
conn->ksnc_tx_carrier = tx_ack;
}
return 0;
}
if (tx->tx_msg.ksm_type == KSOCK_MSG_NOOP) {
if (tx_ack != NULL)
list_add_tail(&tx_ack->tx_list,
&conn->ksnc_tx_queue);
return 0;
}
LASSERT(tx->tx_msg.ksm_type == KSOCK_MSG_LNET);
LASSERT(tx->tx_msg.ksm_zc_cookies[1] == 0);
if (tx_ack != NULL)
cookie = tx_ack->tx_msg.ksm_zc_cookies[1];
tx->tx_msg.ksm_zc_cookies[1] = cookie;
ksocknal_next_tx_carrier(conn);
return 1;
}
static ksock_tx_t *
ksocknal_queue_tx_msg_v2(ksock_conn_t *conn, ksock_tx_t *tx_msg)
{
ksock_tx_t *tx = conn->ksnc_tx_carrier;
if (tx == NULL) {
list_add_tail(&tx_msg->tx_list, &conn->ksnc_tx_queue);
conn->ksnc_tx_carrier = tx_msg;
return NULL;
}
if (tx->tx_msg.ksm_type == KSOCK_MSG_LNET) {
list_add_tail(&tx_msg->tx_list, &conn->ksnc_tx_queue);
return NULL;
}
LASSERT (tx->tx_msg.ksm_type == KSOCK_MSG_NOOP);
tx_msg->tx_msg.ksm_zc_cookies[1] = tx->tx_msg.ksm_zc_cookies[1];
ksocknal_next_tx_carrier(conn);
list_add(&tx_msg->tx_list, &tx->tx_list);
list_del(&tx->tx_list);
return tx;
}
static int
ksocknal_queue_tx_zcack_v3(ksock_conn_t *conn,
ksock_tx_t *tx_ack, __u64 cookie)
{
ksock_tx_t *tx;
if (conn->ksnc_type != SOCKLND_CONN_ACK)
return ksocknal_queue_tx_zcack_v2(conn, tx_ack, cookie);
LASSERT (tx_ack == NULL ||
tx_ack->tx_msg.ksm_type == KSOCK_MSG_NOOP);
tx = conn->ksnc_tx_carrier;
if (tx == NULL) {
if (tx_ack != NULL) {
list_add_tail(&tx_ack->tx_list,
&conn->ksnc_tx_queue);
conn->ksnc_tx_carrier = tx_ack;
}
return 0;
}
if (tx_ack != NULL)
cookie = tx_ack->tx_msg.ksm_zc_cookies[1];
if (cookie == SOCKNAL_KEEPALIVE_PING)
return 1;
if (tx->tx_msg.ksm_zc_cookies[1] == SOCKNAL_KEEPALIVE_PING) {
LASSERT (tx->tx_msg.ksm_zc_cookies[0] == 0);
tx->tx_msg.ksm_zc_cookies[1] = cookie;
return 1;
}
if (cookie == tx->tx_msg.ksm_zc_cookies[0] ||
cookie == tx->tx_msg.ksm_zc_cookies[1]) {
CWARN("%s: duplicated ZC cookie: %llu\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id), cookie);
return 1;
}
if (tx->tx_msg.ksm_zc_cookies[0] == 0) {
if (tx->tx_msg.ksm_zc_cookies[1] > cookie) {
tx->tx_msg.ksm_zc_cookies[0] = tx->tx_msg.ksm_zc_cookies[1];
tx->tx_msg.ksm_zc_cookies[1] = cookie;
} else {
tx->tx_msg.ksm_zc_cookies[0] = cookie;
}
if (tx->tx_msg.ksm_zc_cookies[0] - tx->tx_msg.ksm_zc_cookies[1] > 2) {
ksocknal_next_tx_carrier(conn);
}
return 1;
}
if (tx->tx_msg.ksm_zc_cookies[0] > tx->tx_msg.ksm_zc_cookies[1]) {
__u64 tmp = 0;
LASSERT (tx->tx_msg.ksm_zc_cookies[0] -
tx->tx_msg.ksm_zc_cookies[1] <= 2);
if (tx->tx_msg.ksm_zc_cookies[0] -
tx->tx_msg.ksm_zc_cookies[1] == 2) {
if (cookie == tx->tx_msg.ksm_zc_cookies[1] + 1)
tmp = cookie;
} else if (cookie == tx->tx_msg.ksm_zc_cookies[1] - 1) {
tmp = tx->tx_msg.ksm_zc_cookies[1];
} else if (cookie == tx->tx_msg.ksm_zc_cookies[0] + 1) {
tmp = tx->tx_msg.ksm_zc_cookies[0];
}
if (tmp != 0) {
tx->tx_msg.ksm_zc_cookies[0] = tmp - 1;
tx->tx_msg.ksm_zc_cookies[1] = tmp + 1;
return 1;
}
} else {
if (cookie >= tx->tx_msg.ksm_zc_cookies[0] &&
cookie <= tx->tx_msg.ksm_zc_cookies[1]) {
CWARN("%s: duplicated ZC cookie: %llu\n",
libcfs_id2str(conn->ksnc_peer->ksnp_id), cookie);
return 1;
}
if (cookie == tx->tx_msg.ksm_zc_cookies[1] + 1) {
tx->tx_msg.ksm_zc_cookies[1] = cookie;
return 1;
}
if (cookie == tx->tx_msg.ksm_zc_cookies[0] - 1) {
tx->tx_msg.ksm_zc_cookies[0] = cookie;
return 1;
}
}
if (tx_ack != NULL) {
list_add_tail(&tx_ack->tx_list, &conn->ksnc_tx_queue);
ksocknal_next_tx_carrier(conn);
}
return 0;
}
static int
ksocknal_match_tx(ksock_conn_t *conn, ksock_tx_t *tx, int nonblk)
{
int nob;
#if SOCKNAL_VERSION_DEBUG
if (!*ksocknal_tunables.ksnd_typed_conns)
return SOCKNAL_MATCH_YES;
#endif
if (tx == NULL || tx->tx_lnetmsg == NULL) {
nob = offsetof(ksock_msg_t, ksm_u);
} else {
nob = tx->tx_lnetmsg->msg_len +
((conn->ksnc_proto == &ksocknal_protocol_v1x) ?
sizeof(lnet_hdr_t) : sizeof(ksock_msg_t));
}
switch (conn->ksnc_type) {
default:
CERROR("ksnc_type bad: %u\n", conn->ksnc_type);
LBUG();
case SOCKLND_CONN_ANY:
return SOCKNAL_MATCH_YES;
case SOCKLND_CONN_BULK_IN:
return SOCKNAL_MATCH_MAY;
case SOCKLND_CONN_BULK_OUT:
if (nob < *ksocknal_tunables.ksnd_min_bulk)
return SOCKNAL_MATCH_MAY;
else
return SOCKNAL_MATCH_YES;
case SOCKLND_CONN_CONTROL:
if (nob >= *ksocknal_tunables.ksnd_min_bulk)
return SOCKNAL_MATCH_MAY;
else
return SOCKNAL_MATCH_YES;
}
}
static int
ksocknal_match_tx_v3(ksock_conn_t *conn, ksock_tx_t *tx, int nonblk)
{
int nob;
if (tx == NULL || tx->tx_lnetmsg == NULL)
nob = offsetof(ksock_msg_t, ksm_u);
else
nob = tx->tx_lnetmsg->msg_len + sizeof(ksock_msg_t);
switch (conn->ksnc_type) {
default:
CERROR("ksnc_type bad: %u\n", conn->ksnc_type);
LBUG();
case SOCKLND_CONN_ANY:
return SOCKNAL_MATCH_NO;
case SOCKLND_CONN_ACK:
if (nonblk)
return SOCKNAL_MATCH_YES;
else if (tx == NULL || tx->tx_lnetmsg == NULL)
return SOCKNAL_MATCH_MAY;
else
return SOCKNAL_MATCH_NO;
case SOCKLND_CONN_BULK_OUT:
if (nonblk)
return SOCKNAL_MATCH_NO;
else if (nob < *ksocknal_tunables.ksnd_min_bulk)
return SOCKNAL_MATCH_MAY;
else
return SOCKNAL_MATCH_YES;
case SOCKLND_CONN_CONTROL:
if (nonblk)
return SOCKNAL_MATCH_NO;
else if (nob >= *ksocknal_tunables.ksnd_min_bulk)
return SOCKNAL_MATCH_MAY;
else
return SOCKNAL_MATCH_YES;
}
}
static int
ksocknal_handle_zcreq(ksock_conn_t *c, __u64 cookie, int remote)
{
ksock_peer_t *peer = c->ksnc_peer;
ksock_conn_t *conn;
ksock_tx_t *tx;
int rc;
read_lock(&ksocknal_data.ksnd_global_lock);
conn = ksocknal_find_conn_locked(peer, NULL, !!remote);
if (conn != NULL) {
ksock_sched_t *sched = conn->ksnc_scheduler;
LASSERT(conn->ksnc_proto->pro_queue_tx_zcack != NULL);
spin_lock_bh(&sched->kss_lock);
rc = conn->ksnc_proto->pro_queue_tx_zcack(conn, NULL, cookie);
spin_unlock_bh(&sched->kss_lock);
if (rc) {
read_unlock(&ksocknal_data.ksnd_global_lock);
return 0;
}
}
read_unlock(&ksocknal_data.ksnd_global_lock);
tx = ksocknal_alloc_tx_noop(cookie, !!remote);
if (tx == NULL)
return -ENOMEM;
rc = ksocknal_launch_packet(peer->ksnp_ni, tx, peer->ksnp_id);
if (rc == 0)
return 0;
ksocknal_free_tx(tx);
return rc;
}
static int
ksocknal_handle_zcack(ksock_conn_t *conn, __u64 cookie1, __u64 cookie2)
{
ksock_peer_t *peer = conn->ksnc_peer;
ksock_tx_t *tx;
ksock_tx_t *tmp;
LIST_HEAD (zlist);
int count;
if (cookie1 == 0)
cookie1 = cookie2;
count = (cookie1 > cookie2) ? 2 : (cookie2 - cookie1 + 1);
if (cookie2 == SOCKNAL_KEEPALIVE_PING &&
conn->ksnc_proto == &ksocknal_protocol_v3x) {
return count == 1 ? 0 : -EPROTO;
}
spin_lock(&peer->ksnp_lock);
list_for_each_entry_safe(tx, tmp,
&peer->ksnp_zc_req_list, tx_zc_list) {
__u64 c = tx->tx_msg.ksm_zc_cookies[0];
if (c == cookie1 || c == cookie2 || (cookie1 < c && c < cookie2)) {
tx->tx_msg.ksm_zc_cookies[0] = 0;
list_del(&tx->tx_zc_list);
list_add(&tx->tx_zc_list, &zlist);
if (--count == 0)
break;
}
}
spin_unlock(&peer->ksnp_lock);
while (!list_empty(&zlist)) {
tx = list_entry(zlist.next, ksock_tx_t, tx_zc_list);
list_del(&tx->tx_zc_list);
ksocknal_tx_decref(tx);
}
return count == 0 ? 0 : -EPROTO;
}
static int
ksocknal_send_hello_v1 (ksock_conn_t *conn, ksock_hello_msg_t *hello)
{
struct socket *sock = conn->ksnc_sock;
lnet_hdr_t *hdr;
lnet_magicversion_t *hmv;
int rc;
int i;
CLASSERT(sizeof(lnet_magicversion_t) == offsetof(lnet_hdr_t, src_nid));
LIBCFS_ALLOC(hdr, sizeof(*hdr));
if (hdr == NULL) {
CERROR("Can't allocate lnet_hdr_t\n");
return -ENOMEM;
}
hmv = (lnet_magicversion_t *)&hdr->dest_nid;
hmv->magic = cpu_to_le32 (LNET_PROTO_TCP_MAGIC);
hmv->version_major = cpu_to_le16 (KSOCK_PROTO_V1_MAJOR);
hmv->version_minor = cpu_to_le16 (KSOCK_PROTO_V1_MINOR);
if (the_lnet.ln_testprotocompat != 0) {
LNET_LOCK();
if ((the_lnet.ln_testprotocompat & 1) != 0) {
hmv->version_major++;
the_lnet.ln_testprotocompat &= ~1;
}
if ((the_lnet.ln_testprotocompat & 2) != 0) {
hmv->magic = LNET_PROTO_MAGIC;
the_lnet.ln_testprotocompat &= ~2;
}
LNET_UNLOCK();
}
hdr->src_nid = cpu_to_le64 (hello->kshm_src_nid);
hdr->src_pid = cpu_to_le32 (hello->kshm_src_pid);
hdr->type = cpu_to_le32 (LNET_MSG_HELLO);
hdr->payload_length = cpu_to_le32 (hello->kshm_nips * sizeof(__u32));
hdr->msg.hello.type = cpu_to_le32 (hello->kshm_ctype);
hdr->msg.hello.incarnation = cpu_to_le64 (hello->kshm_src_incarnation);
rc = libcfs_sock_write(sock, hdr, sizeof(*hdr),
lnet_acceptor_timeout());
if (rc != 0) {
CNETERR("Error %d sending HELLO hdr to %pI4h/%d\n",
rc, &conn->ksnc_ipaddr, conn->ksnc_port);
goto out;
}
if (hello->kshm_nips == 0)
goto out;
for (i = 0; i < (int) hello->kshm_nips; i++) {
hello->kshm_ips[i] = __cpu_to_le32 (hello->kshm_ips[i]);
}
rc = libcfs_sock_write(sock, hello->kshm_ips,
hello->kshm_nips * sizeof(__u32),
lnet_acceptor_timeout());
if (rc != 0) {
CNETERR("Error %d sending HELLO payload (%d) to %pI4h/%d\n",
rc, hello->kshm_nips,
&conn->ksnc_ipaddr, conn->ksnc_port);
}
out:
LIBCFS_FREE(hdr, sizeof(*hdr));
return rc;
}
static int
ksocknal_send_hello_v2 (ksock_conn_t *conn, ksock_hello_msg_t *hello)
{
struct socket *sock = conn->ksnc_sock;
int rc;
hello->kshm_magic = LNET_PROTO_MAGIC;
hello->kshm_version = conn->ksnc_proto->pro_version;
if (the_lnet.ln_testprotocompat != 0) {
LNET_LOCK();
if ((the_lnet.ln_testprotocompat & 1) != 0) {
hello->kshm_version++;
the_lnet.ln_testprotocompat &= ~1;
}
LNET_UNLOCK();
}
rc = libcfs_sock_write(sock, hello, offsetof(ksock_hello_msg_t, kshm_ips),
lnet_acceptor_timeout());
if (rc != 0) {
CNETERR("Error %d sending HELLO hdr to %pI4h/%d\n",
rc, &conn->ksnc_ipaddr, conn->ksnc_port);
return rc;
}
if (hello->kshm_nips == 0)
return 0;
rc = libcfs_sock_write(sock, hello->kshm_ips,
hello->kshm_nips * sizeof(__u32),
lnet_acceptor_timeout());
if (rc != 0) {
CNETERR("Error %d sending HELLO payload (%d) to %pI4h/%d\n",
rc, hello->kshm_nips,
&conn->ksnc_ipaddr, conn->ksnc_port);
}
return rc;
}
static int
ksocknal_recv_hello_v1(ksock_conn_t *conn, ksock_hello_msg_t *hello,
int timeout)
{
struct socket *sock = conn->ksnc_sock;
lnet_hdr_t *hdr;
int rc;
int i;
LIBCFS_ALLOC(hdr, sizeof(*hdr));
if (hdr == NULL) {
CERROR("Can't allocate lnet_hdr_t\n");
return -ENOMEM;
}
rc = libcfs_sock_read(sock, &hdr->src_nid,
sizeof (*hdr) - offsetof (lnet_hdr_t, src_nid),
timeout);
if (rc != 0) {
CERROR("Error %d reading rest of HELLO hdr from %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT (rc < 0 && rc != -EALREADY);
goto out;
}
if (hdr->type != cpu_to_le32 (LNET_MSG_HELLO)) {
CERROR("Expecting a HELLO hdr, but got type %d from %pI4h\n",
le32_to_cpu(hdr->type),
&conn->ksnc_ipaddr);
rc = -EPROTO;
goto out;
}
hello->kshm_src_nid = le64_to_cpu (hdr->src_nid);
hello->kshm_src_pid = le32_to_cpu (hdr->src_pid);
hello->kshm_src_incarnation = le64_to_cpu (hdr->msg.hello.incarnation);
hello->kshm_ctype = le32_to_cpu (hdr->msg.hello.type);
hello->kshm_nips = le32_to_cpu (hdr->payload_length) /
sizeof (__u32);
if (hello->kshm_nips > LNET_MAX_INTERFACES) {
CERROR("Bad nips %d from ip %pI4h\n",
hello->kshm_nips, &conn->ksnc_ipaddr);
rc = -EPROTO;
goto out;
}
if (hello->kshm_nips == 0)
goto out;
rc = libcfs_sock_read(sock, hello->kshm_ips,
hello->kshm_nips * sizeof(__u32), timeout);
if (rc != 0) {
CERROR("Error %d reading IPs from ip %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0 && rc != -EALREADY);
goto out;
}
for (i = 0; i < (int) hello->kshm_nips; i++) {
hello->kshm_ips[i] = __le32_to_cpu(hello->kshm_ips[i]);
if (hello->kshm_ips[i] == 0) {
CERROR("Zero IP[%d] from ip %pI4h\n",
i, &conn->ksnc_ipaddr);
rc = -EPROTO;
break;
}
}
out:
LIBCFS_FREE(hdr, sizeof(*hdr));
return rc;
}
static int
ksocknal_recv_hello_v2 (ksock_conn_t *conn, ksock_hello_msg_t *hello, int timeout)
{
struct socket *sock = conn->ksnc_sock;
int rc;
int i;
if (hello->kshm_magic == LNET_PROTO_MAGIC)
conn->ksnc_flip = 0;
else
conn->ksnc_flip = 1;
rc = libcfs_sock_read(sock, &hello->kshm_src_nid,
offsetof(ksock_hello_msg_t, kshm_ips) -
offsetof(ksock_hello_msg_t, kshm_src_nid),
timeout);
if (rc != 0) {
CERROR("Error %d reading HELLO from %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0 && rc != -EALREADY);
return rc;
}
if (conn->ksnc_flip) {
__swab32s(&hello->kshm_src_pid);
__swab64s(&hello->kshm_src_nid);
__swab32s(&hello->kshm_dst_pid);
__swab64s(&hello->kshm_dst_nid);
__swab64s(&hello->kshm_src_incarnation);
__swab64s(&hello->kshm_dst_incarnation);
__swab32s(&hello->kshm_ctype);
__swab32s(&hello->kshm_nips);
}
if (hello->kshm_nips > LNET_MAX_INTERFACES) {
CERROR("Bad nips %d from ip %pI4h\n",
hello->kshm_nips, &conn->ksnc_ipaddr);
return -EPROTO;
}
if (hello->kshm_nips == 0)
return 0;
rc = libcfs_sock_read(sock, hello->kshm_ips,
hello->kshm_nips * sizeof(__u32), timeout);
if (rc != 0) {
CERROR("Error %d reading IPs from ip %pI4h\n",
rc, &conn->ksnc_ipaddr);
LASSERT(rc < 0 && rc != -EALREADY);
return rc;
}
for (i = 0; i < (int) hello->kshm_nips; i++) {
if (conn->ksnc_flip)
__swab32s(&hello->kshm_ips[i]);
if (hello->kshm_ips[i] == 0) {
CERROR("Zero IP[%d] from ip %pI4h\n",
i, &conn->ksnc_ipaddr);
return -EPROTO;
}
}
return 0;
}
static void
ksocknal_pack_msg_v1(ksock_tx_t *tx)
{
LASSERT(tx->tx_msg.ksm_type != KSOCK_MSG_NOOP);
LASSERT(tx->tx_lnetmsg != NULL);
tx->tx_iov[0].iov_base = &tx->tx_lnetmsg->msg_hdr;
tx->tx_iov[0].iov_len = sizeof(lnet_hdr_t);
tx->tx_resid = tx->tx_nob = tx->tx_lnetmsg->msg_len + sizeof(lnet_hdr_t);
}
static void
ksocknal_pack_msg_v2(ksock_tx_t *tx)
{
tx->tx_iov[0].iov_base = &tx->tx_msg;
if (tx->tx_lnetmsg != NULL) {
LASSERT(tx->tx_msg.ksm_type != KSOCK_MSG_NOOP);
tx->tx_msg.ksm_u.lnetmsg.ksnm_hdr = tx->tx_lnetmsg->msg_hdr;
tx->tx_iov[0].iov_len = sizeof(ksock_msg_t);
tx->tx_resid = tx->tx_nob = sizeof(ksock_msg_t) + tx->tx_lnetmsg->msg_len;
} else {
LASSERT(tx->tx_msg.ksm_type == KSOCK_MSG_NOOP);
tx->tx_iov[0].iov_len = offsetof(ksock_msg_t, ksm_u.lnetmsg.ksnm_hdr);
tx->tx_resid = tx->tx_nob = offsetof(ksock_msg_t, ksm_u.lnetmsg.ksnm_hdr);
}
}
static void
ksocknal_unpack_msg_v1(ksock_msg_t *msg)
{
msg->ksm_csum = 0;
msg->ksm_type = KSOCK_MSG_LNET;
msg->ksm_zc_cookies[0] = msg->ksm_zc_cookies[1] = 0;
}
static void
ksocknal_unpack_msg_v2(ksock_msg_t *msg)
{
return;
}
