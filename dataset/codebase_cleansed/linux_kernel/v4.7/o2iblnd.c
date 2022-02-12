static __u32 kiblnd_cksum(void *ptr, int nob)
{
char *c = ptr;
__u32 sum = 0;
while (nob-- > 0)
sum = ((sum << 1) | (sum >> 31)) + *c++;
return !sum ? 1 : sum;
}
static char *kiblnd_msgtype2str(int type)
{
switch (type) {
case IBLND_MSG_CONNREQ:
return "CONNREQ";
case IBLND_MSG_CONNACK:
return "CONNACK";
case IBLND_MSG_NOOP:
return "NOOP";
case IBLND_MSG_IMMEDIATE:
return "IMMEDIATE";
case IBLND_MSG_PUT_REQ:
return "PUT_REQ";
case IBLND_MSG_PUT_NAK:
return "PUT_NAK";
case IBLND_MSG_PUT_ACK:
return "PUT_ACK";
case IBLND_MSG_PUT_DONE:
return "PUT_DONE";
case IBLND_MSG_GET_REQ:
return "GET_REQ";
case IBLND_MSG_GET_DONE:
return "GET_DONE";
default:
return "???";
}
}
static int kiblnd_msgtype2size(int type)
{
const int hdr_size = offsetof(kib_msg_t, ibm_u);
switch (type) {
case IBLND_MSG_CONNREQ:
case IBLND_MSG_CONNACK:
return hdr_size + sizeof(kib_connparams_t);
case IBLND_MSG_NOOP:
return hdr_size;
case IBLND_MSG_IMMEDIATE:
return offsetof(kib_msg_t, ibm_u.immediate.ibim_payload[0]);
case IBLND_MSG_PUT_REQ:
return hdr_size + sizeof(kib_putreq_msg_t);
case IBLND_MSG_PUT_ACK:
return hdr_size + sizeof(kib_putack_msg_t);
case IBLND_MSG_GET_REQ:
return hdr_size + sizeof(kib_get_msg_t);
case IBLND_MSG_PUT_NAK:
case IBLND_MSG_PUT_DONE:
case IBLND_MSG_GET_DONE:
return hdr_size + sizeof(kib_completion_msg_t);
default:
return -1;
}
}
static int kiblnd_unpack_rd(kib_msg_t *msg, int flip)
{
kib_rdma_desc_t *rd;
int nob;
int n;
int i;
LASSERT(msg->ibm_type == IBLND_MSG_GET_REQ ||
msg->ibm_type == IBLND_MSG_PUT_ACK);
rd = msg->ibm_type == IBLND_MSG_GET_REQ ?
&msg->ibm_u.get.ibgm_rd :
&msg->ibm_u.putack.ibpam_rd;
if (flip) {
__swab32s(&rd->rd_key);
__swab32s(&rd->rd_nfrags);
}
n = rd->rd_nfrags;
if (n <= 0 || n > IBLND_MAX_RDMA_FRAGS) {
CERROR("Bad nfrags: %d, should be 0 < n <= %d\n",
n, IBLND_MAX_RDMA_FRAGS);
return 1;
}
nob = offsetof(kib_msg_t, ibm_u) +
kiblnd_rd_msg_size(rd, msg->ibm_type, n);
if (msg->ibm_nob < nob) {
CERROR("Short %s: %d(%d)\n",
kiblnd_msgtype2str(msg->ibm_type), msg->ibm_nob, nob);
return 1;
}
if (!flip)
return 0;
for (i = 0; i < n; i++) {
__swab32s(&rd->rd_frags[i].rf_nob);
__swab64s(&rd->rd_frags[i].rf_addr);
}
return 0;
}
void kiblnd_pack_msg(lnet_ni_t *ni, kib_msg_t *msg, int version,
int credits, lnet_nid_t dstnid, __u64 dststamp)
{
kib_net_t *net = ni->ni_data;
msg->ibm_magic = IBLND_MSG_MAGIC;
msg->ibm_version = version;
msg->ibm_credits = credits;
msg->ibm_cksum = 0;
msg->ibm_srcnid = ni->ni_nid;
msg->ibm_srcstamp = net->ibn_incarnation;
msg->ibm_dstnid = dstnid;
msg->ibm_dststamp = dststamp;
if (*kiblnd_tunables.kib_cksum) {
msg->ibm_cksum = kiblnd_cksum(msg, msg->ibm_nob);
}
}
int kiblnd_unpack_msg(kib_msg_t *msg, int nob)
{
const int hdr_size = offsetof(kib_msg_t, ibm_u);
__u32 msg_cksum;
__u16 version;
int msg_nob;
int flip;
if (nob < 6) {
CERROR("Short message: %d\n", nob);
return -EPROTO;
}
if (msg->ibm_magic == IBLND_MSG_MAGIC) {
flip = 0;
} else if (msg->ibm_magic == __swab32(IBLND_MSG_MAGIC)) {
flip = 1;
} else {
CERROR("Bad magic: %08x\n", msg->ibm_magic);
return -EPROTO;
}
version = flip ? __swab16(msg->ibm_version) : msg->ibm_version;
if (version != IBLND_MSG_VERSION &&
version != IBLND_MSG_VERSION_1) {
CERROR("Bad version: %x\n", version);
return -EPROTO;
}
if (nob < hdr_size) {
CERROR("Short message: %d\n", nob);
return -EPROTO;
}
msg_nob = flip ? __swab32(msg->ibm_nob) : msg->ibm_nob;
if (msg_nob > nob) {
CERROR("Short message: got %d, wanted %d\n", nob, msg_nob);
return -EPROTO;
}
msg_cksum = flip ? __swab32(msg->ibm_cksum) : msg->ibm_cksum;
msg->ibm_cksum = 0;
if (msg_cksum &&
msg_cksum != kiblnd_cksum(msg, msg_nob)) {
CERROR("Bad checksum\n");
return -EPROTO;
}
msg->ibm_cksum = msg_cksum;
if (flip) {
msg->ibm_version = version;
CLASSERT(sizeof(msg->ibm_type) == 1);
CLASSERT(sizeof(msg->ibm_credits) == 1);
msg->ibm_nob = msg_nob;
__swab64s(&msg->ibm_srcnid);
__swab64s(&msg->ibm_srcstamp);
__swab64s(&msg->ibm_dstnid);
__swab64s(&msg->ibm_dststamp);
}
if (msg->ibm_srcnid == LNET_NID_ANY) {
CERROR("Bad src nid: %s\n", libcfs_nid2str(msg->ibm_srcnid));
return -EPROTO;
}
if (msg_nob < kiblnd_msgtype2size(msg->ibm_type)) {
CERROR("Short %s: %d(%d)\n", kiblnd_msgtype2str(msg->ibm_type),
msg_nob, kiblnd_msgtype2size(msg->ibm_type));
return -EPROTO;
}
switch (msg->ibm_type) {
default:
CERROR("Unknown message type %x\n", msg->ibm_type);
return -EPROTO;
case IBLND_MSG_NOOP:
case IBLND_MSG_IMMEDIATE:
case IBLND_MSG_PUT_REQ:
break;
case IBLND_MSG_PUT_ACK:
case IBLND_MSG_GET_REQ:
if (kiblnd_unpack_rd(msg, flip))
return -EPROTO;
break;
case IBLND_MSG_PUT_NAK:
case IBLND_MSG_PUT_DONE:
case IBLND_MSG_GET_DONE:
if (flip)
__swab32s(&msg->ibm_u.completion.ibcm_status);
break;
case IBLND_MSG_CONNREQ:
case IBLND_MSG_CONNACK:
if (flip) {
__swab16s(&msg->ibm_u.connparams.ibcp_queue_depth);
__swab16s(&msg->ibm_u.connparams.ibcp_max_frags);
__swab32s(&msg->ibm_u.connparams.ibcp_max_msg_size);
}
break;
}
return 0;
}
int kiblnd_create_peer(lnet_ni_t *ni, kib_peer_t **peerp, lnet_nid_t nid)
{
kib_peer_t *peer;
kib_net_t *net = ni->ni_data;
int cpt = lnet_cpt_of_nid(nid);
unsigned long flags;
LASSERT(net);
LASSERT(nid != LNET_NID_ANY);
LIBCFS_CPT_ALLOC(peer, lnet_cpt_table(), cpt, sizeof(*peer));
if (!peer) {
CERROR("Cannot allocate peer\n");
return -ENOMEM;
}
peer->ibp_ni = ni;
peer->ibp_nid = nid;
peer->ibp_error = 0;
peer->ibp_last_alive = 0;
peer->ibp_max_frags = kiblnd_cfg_rdma_frags(peer->ibp_ni);
peer->ibp_queue_depth = ni->ni_peertxcredits;
atomic_set(&peer->ibp_refcount, 1);
INIT_LIST_HEAD(&peer->ibp_list);
INIT_LIST_HEAD(&peer->ibp_conns);
INIT_LIST_HEAD(&peer->ibp_tx_queue);
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
LASSERT(!net->ibn_shutdown);
atomic_inc(&net->ibn_npeers);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
*peerp = peer;
return 0;
}
void kiblnd_destroy_peer(kib_peer_t *peer)
{
kib_net_t *net = peer->ibp_ni->ni_data;
LASSERT(net);
LASSERT(!atomic_read(&peer->ibp_refcount));
LASSERT(!kiblnd_peer_active(peer));
LASSERT(kiblnd_peer_idle(peer));
LASSERT(list_empty(&peer->ibp_tx_queue));
LIBCFS_FREE(peer, sizeof(*peer));
atomic_dec(&net->ibn_npeers);
}
kib_peer_t *kiblnd_find_peer_locked(lnet_nid_t nid)
{
struct list_head *peer_list = kiblnd_nid2peerlist(nid);
struct list_head *tmp;
kib_peer_t *peer;
list_for_each(tmp, peer_list) {
peer = list_entry(tmp, kib_peer_t, ibp_list);
LASSERT(!kiblnd_peer_idle(peer));
if (peer->ibp_nid != nid)
continue;
CDEBUG(D_NET, "got peer [%p] -> %s (%d) version: %x\n",
peer, libcfs_nid2str(nid),
atomic_read(&peer->ibp_refcount),
peer->ibp_version);
return peer;
}
return NULL;
}
void kiblnd_unlink_peer_locked(kib_peer_t *peer)
{
LASSERT(list_empty(&peer->ibp_conns));
LASSERT(kiblnd_peer_active(peer));
list_del_init(&peer->ibp_list);
kiblnd_peer_decref(peer);
}
static int kiblnd_get_peer_info(lnet_ni_t *ni, int index,
lnet_nid_t *nidp, int *count)
{
kib_peer_t *peer;
struct list_head *ptmp;
int i;
unsigned long flags;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
for (i = 0; i < kiblnd_data.kib_peer_hash_size; i++) {
list_for_each(ptmp, &kiblnd_data.kib_peers[i]) {
peer = list_entry(ptmp, kib_peer_t, ibp_list);
LASSERT(!kiblnd_peer_idle(peer));
if (peer->ibp_ni != ni)
continue;
if (index-- > 0)
continue;
*nidp = peer->ibp_nid;
*count = atomic_read(&peer->ibp_refcount);
read_unlock_irqrestore(&kiblnd_data.kib_global_lock,
flags);
return 0;
}
}
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
return -ENOENT;
}
static void kiblnd_del_peer_locked(kib_peer_t *peer)
{
struct list_head *ctmp;
struct list_head *cnxt;
kib_conn_t *conn;
if (list_empty(&peer->ibp_conns)) {
kiblnd_unlink_peer_locked(peer);
} else {
list_for_each_safe(ctmp, cnxt, &peer->ibp_conns) {
conn = list_entry(ctmp, kib_conn_t, ibc_list);
kiblnd_close_conn_locked(conn, 0);
}
}
}
static int kiblnd_del_peer(lnet_ni_t *ni, lnet_nid_t nid)
{
LIST_HEAD(zombies);
struct list_head *ptmp;
struct list_head *pnxt;
kib_peer_t *peer;
int lo;
int hi;
int i;
unsigned long flags;
int rc = -ENOENT;
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (nid != LNET_NID_ANY) {
lo = kiblnd_nid2peerlist(nid) - kiblnd_data.kib_peers;
hi = kiblnd_nid2peerlist(nid) - kiblnd_data.kib_peers;
} else {
lo = 0;
hi = kiblnd_data.kib_peer_hash_size - 1;
}
for (i = lo; i <= hi; i++) {
list_for_each_safe(ptmp, pnxt, &kiblnd_data.kib_peers[i]) {
peer = list_entry(ptmp, kib_peer_t, ibp_list);
LASSERT(!kiblnd_peer_idle(peer));
if (peer->ibp_ni != ni)
continue;
if (!(nid == LNET_NID_ANY || peer->ibp_nid == nid))
continue;
if (!list_empty(&peer->ibp_tx_queue)) {
LASSERT(list_empty(&peer->ibp_conns));
list_splice_init(&peer->ibp_tx_queue,
&zombies);
}
kiblnd_del_peer_locked(peer);
rc = 0;
}
}
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
kiblnd_txlist_done(ni, &zombies, -EIO);
return rc;
}
static kib_conn_t *kiblnd_get_conn_by_idx(lnet_ni_t *ni, int index)
{
kib_peer_t *peer;
struct list_head *ptmp;
kib_conn_t *conn;
struct list_head *ctmp;
int i;
unsigned long flags;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
for (i = 0; i < kiblnd_data.kib_peer_hash_size; i++) {
list_for_each(ptmp, &kiblnd_data.kib_peers[i]) {
peer = list_entry(ptmp, kib_peer_t, ibp_list);
LASSERT(!kiblnd_peer_idle(peer));
if (peer->ibp_ni != ni)
continue;
list_for_each(ctmp, &peer->ibp_conns) {
if (index-- > 0)
continue;
conn = list_entry(ctmp, kib_conn_t,
ibc_list);
kiblnd_conn_addref(conn);
read_unlock_irqrestore(
&kiblnd_data.kib_global_lock,
flags);
return conn;
}
}
}
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
return NULL;
}
int kiblnd_translate_mtu(int value)
{
switch (value) {
default:
return -1;
case 0:
return 0;
case 256:
return IB_MTU_256;
case 512:
return IB_MTU_512;
case 1024:
return IB_MTU_1024;
case 2048:
return IB_MTU_2048;
case 4096:
return IB_MTU_4096;
}
}
static void kiblnd_setup_mtu_locked(struct rdma_cm_id *cmid)
{
int mtu;
if (!cmid->route.path_rec)
return;
mtu = kiblnd_translate_mtu(*kiblnd_tunables.kib_ib_mtu);
LASSERT(mtu >= 0);
if (mtu)
cmid->route.path_rec->mtu = mtu;
}
static int kiblnd_get_completion_vector(kib_conn_t *conn, int cpt)
{
cpumask_t *mask;
int vectors;
int off;
int i;
lnet_nid_t nid = conn->ibc_peer->ibp_nid;
vectors = conn->ibc_cmid->device->num_comp_vectors;
if (vectors <= 1)
return 0;
mask = cfs_cpt_cpumask(lnet_cpt_table(), cpt);
if (!mask)
return 0;
off = do_div(nid, cpumask_weight(mask));
for_each_cpu(i, mask) {
if (!off--)
return i % vectors;
}
LBUG();
return 1;
}
kib_conn_t *kiblnd_create_conn(kib_peer_t *peer, struct rdma_cm_id *cmid,
int state, int version)
{
rwlock_t *glock = &kiblnd_data.kib_global_lock;
kib_net_t *net = peer->ibp_ni->ni_data;
kib_dev_t *dev;
struct ib_qp_init_attr *init_qp_attr;
struct kib_sched_info *sched;
struct ib_cq_init_attr cq_attr = {};
kib_conn_t *conn;
struct ib_cq *cq;
unsigned long flags;
int cpt;
int rc;
int i;
LASSERT(net);
LASSERT(!in_interrupt());
dev = net->ibn_dev;
cpt = lnet_cpt_of_nid(peer->ibp_nid);
sched = kiblnd_data.kib_scheds[cpt];
LASSERT(sched->ibs_nthreads > 0);
LIBCFS_CPT_ALLOC(init_qp_attr, lnet_cpt_table(), cpt,
sizeof(*init_qp_attr));
if (!init_qp_attr) {
CERROR("Can't allocate qp_attr for %s\n",
libcfs_nid2str(peer->ibp_nid));
goto failed_0;
}
LIBCFS_CPT_ALLOC(conn, lnet_cpt_table(), cpt, sizeof(*conn));
if (!conn) {
CERROR("Can't allocate connection for %s\n",
libcfs_nid2str(peer->ibp_nid));
goto failed_1;
}
conn->ibc_state = IBLND_CONN_INIT;
conn->ibc_version = version;
conn->ibc_peer = peer;
cmid->context = conn;
conn->ibc_cmid = cmid;
conn->ibc_max_frags = peer->ibp_max_frags;
conn->ibc_queue_depth = peer->ibp_queue_depth;
INIT_LIST_HEAD(&conn->ibc_early_rxs);
INIT_LIST_HEAD(&conn->ibc_tx_noops);
INIT_LIST_HEAD(&conn->ibc_tx_queue);
INIT_LIST_HEAD(&conn->ibc_tx_queue_rsrvd);
INIT_LIST_HEAD(&conn->ibc_tx_queue_nocred);
INIT_LIST_HEAD(&conn->ibc_active_txs);
spin_lock_init(&conn->ibc_lock);
LIBCFS_CPT_ALLOC(conn->ibc_connvars, lnet_cpt_table(), cpt,
sizeof(*conn->ibc_connvars));
if (!conn->ibc_connvars) {
CERROR("Can't allocate in-progress connection state\n");
goto failed_2;
}
write_lock_irqsave(glock, flags);
if (dev->ibd_failover) {
write_unlock_irqrestore(glock, flags);
CERROR("%s: failover in progress\n", dev->ibd_ifname);
goto failed_2;
}
if (dev->ibd_hdev->ibh_ibdev != cmid->device) {
if (kiblnd_dev_can_failover(dev)) {
list_add_tail(&dev->ibd_fail_list,
&kiblnd_data.kib_failed_devs);
wake_up(&kiblnd_data.kib_failover_waitq);
}
write_unlock_irqrestore(glock, flags);
CERROR("cmid HCA(%s), kib_dev(%s) need failover\n",
cmid->device->name, dev->ibd_ifname);
goto failed_2;
}
kiblnd_hdev_addref_locked(dev->ibd_hdev);
conn->ibc_hdev = dev->ibd_hdev;
kiblnd_setup_mtu_locked(cmid);
write_unlock_irqrestore(glock, flags);
LIBCFS_CPT_ALLOC(conn->ibc_rxs, lnet_cpt_table(), cpt,
IBLND_RX_MSGS(conn) * sizeof(kib_rx_t));
if (!conn->ibc_rxs) {
CERROR("Cannot allocate RX buffers\n");
goto failed_2;
}
rc = kiblnd_alloc_pages(&conn->ibc_rx_pages, cpt,
IBLND_RX_MSG_PAGES(conn));
if (rc)
goto failed_2;
kiblnd_map_rx_descs(conn);
cq_attr.cqe = IBLND_CQ_ENTRIES(conn);
cq_attr.comp_vector = kiblnd_get_completion_vector(conn, cpt);
cq = ib_create_cq(cmid->device,
kiblnd_cq_completion, kiblnd_cq_event, conn,
&cq_attr);
if (IS_ERR(cq)) {
CERROR("Failed to create CQ with %d CQEs: %ld\n",
IBLND_CQ_ENTRIES(conn), PTR_ERR(cq));
goto failed_2;
}
conn->ibc_cq = cq;
rc = ib_req_notify_cq(cq, IB_CQ_NEXT_COMP);
if (rc) {
CERROR("Can't request completion notification: %d\n", rc);
goto failed_2;
}
init_qp_attr->event_handler = kiblnd_qp_event;
init_qp_attr->qp_context = conn;
init_qp_attr->cap.max_send_wr = IBLND_SEND_WRS(conn);
init_qp_attr->cap.max_recv_wr = IBLND_RECV_WRS(conn);
init_qp_attr->cap.max_send_sge = 1;
init_qp_attr->cap.max_recv_sge = 1;
init_qp_attr->sq_sig_type = IB_SIGNAL_REQ_WR;
init_qp_attr->qp_type = IB_QPT_RC;
init_qp_attr->send_cq = cq;
init_qp_attr->recv_cq = cq;
conn->ibc_sched = sched;
rc = rdma_create_qp(cmid, conn->ibc_hdev->ibh_pd, init_qp_attr);
if (rc) {
CERROR("Can't create QP: %d, send_wr: %d, recv_wr: %d\n",
rc, init_qp_attr->cap.max_send_wr,
init_qp_attr->cap.max_recv_wr);
goto failed_2;
}
LIBCFS_FREE(init_qp_attr, sizeof(*init_qp_attr));
atomic_set(&conn->ibc_refcount, 1 + IBLND_RX_MSGS(conn));
conn->ibc_nrx = IBLND_RX_MSGS(conn);
for (i = 0; i < IBLND_RX_MSGS(conn); i++) {
rc = kiblnd_post_rx(&conn->ibc_rxs[i],
IBLND_POSTRX_NO_CREDIT);
if (rc) {
CERROR("Can't post rxmsg: %d\n", rc);
kiblnd_abort_receives(conn);
spin_lock_irqsave(&sched->ibs_lock, flags);
conn->ibc_nrx -= IBLND_RX_MSGS(conn) - i;
spin_unlock_irqrestore(&sched->ibs_lock, flags);
rdma_destroy_qp(conn->ibc_cmid);
conn->ibc_cmid = NULL;
while (i++ <= IBLND_RX_MSGS(conn))
kiblnd_conn_decref(conn);
return NULL;
}
}
LASSERT(state == IBLND_CONN_ACTIVE_CONNECT ||
state == IBLND_CONN_PASSIVE_WAIT);
conn->ibc_state = state;
atomic_inc(&net->ibn_nconns);
return conn;
failed_2:
kiblnd_destroy_conn(conn, true);
failed_1:
LIBCFS_FREE(init_qp_attr, sizeof(*init_qp_attr));
failed_0:
return NULL;
}
void kiblnd_destroy_conn(kib_conn_t *conn, bool free_conn)
{
struct rdma_cm_id *cmid = conn->ibc_cmid;
kib_peer_t *peer = conn->ibc_peer;
int rc;
LASSERT(!in_interrupt());
LASSERT(!atomic_read(&conn->ibc_refcount));
LASSERT(list_empty(&conn->ibc_early_rxs));
LASSERT(list_empty(&conn->ibc_tx_noops));
LASSERT(list_empty(&conn->ibc_tx_queue));
LASSERT(list_empty(&conn->ibc_tx_queue_rsrvd));
LASSERT(list_empty(&conn->ibc_tx_queue_nocred));
LASSERT(list_empty(&conn->ibc_active_txs));
LASSERT(!conn->ibc_noops_posted);
LASSERT(!conn->ibc_nsends_posted);
switch (conn->ibc_state) {
default:
LBUG();
case IBLND_CONN_DISCONNECTED:
LASSERT(!conn->ibc_connvars);
break;
case IBLND_CONN_INIT:
break;
}
if (cmid && cmid->qp)
rdma_destroy_qp(cmid);
if (conn->ibc_cq) {
rc = ib_destroy_cq(conn->ibc_cq);
if (rc)
CWARN("Error destroying CQ: %d\n", rc);
}
if (conn->ibc_rx_pages)
kiblnd_unmap_rx_descs(conn);
if (conn->ibc_rxs) {
LIBCFS_FREE(conn->ibc_rxs,
IBLND_RX_MSGS(conn) * sizeof(kib_rx_t));
}
if (conn->ibc_connvars)
LIBCFS_FREE(conn->ibc_connvars, sizeof(*conn->ibc_connvars));
if (conn->ibc_hdev)
kiblnd_hdev_decref(conn->ibc_hdev);
if (conn->ibc_state != IBLND_CONN_INIT) {
kib_net_t *net = peer->ibp_ni->ni_data;
kiblnd_peer_decref(peer);
rdma_destroy_id(cmid);
atomic_dec(&net->ibn_nconns);
}
LIBCFS_FREE(conn, sizeof(*conn));
}
int kiblnd_close_peer_conns_locked(kib_peer_t *peer, int why)
{
kib_conn_t *conn;
struct list_head *ctmp;
struct list_head *cnxt;
int count = 0;
list_for_each_safe(ctmp, cnxt, &peer->ibp_conns) {
conn = list_entry(ctmp, kib_conn_t, ibc_list);
CDEBUG(D_NET, "Closing conn -> %s, version: %x, reason: %d\n",
libcfs_nid2str(peer->ibp_nid),
conn->ibc_version, why);
kiblnd_close_conn_locked(conn, why);
count++;
}
return count;
}
int kiblnd_close_stale_conns_locked(kib_peer_t *peer,
int version, __u64 incarnation)
{
kib_conn_t *conn;
struct list_head *ctmp;
struct list_head *cnxt;
int count = 0;
list_for_each_safe(ctmp, cnxt, &peer->ibp_conns) {
conn = list_entry(ctmp, kib_conn_t, ibc_list);
if (conn->ibc_version == version &&
conn->ibc_incarnation == incarnation)
continue;
CDEBUG(D_NET,
"Closing stale conn -> %s version: %x, incarnation:%#llx(%x, %#llx)\n",
libcfs_nid2str(peer->ibp_nid),
conn->ibc_version, conn->ibc_incarnation,
version, incarnation);
kiblnd_close_conn_locked(conn, -ESTALE);
count++;
}
return count;
}
static int kiblnd_close_matching_conns(lnet_ni_t *ni, lnet_nid_t nid)
{
kib_peer_t *peer;
struct list_head *ptmp;
struct list_head *pnxt;
int lo;
int hi;
int i;
unsigned long flags;
int count = 0;
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (nid != LNET_NID_ANY) {
lo = kiblnd_nid2peerlist(nid) - kiblnd_data.kib_peers;
hi = kiblnd_nid2peerlist(nid) - kiblnd_data.kib_peers;
} else {
lo = 0;
hi = kiblnd_data.kib_peer_hash_size - 1;
}
for (i = lo; i <= hi; i++) {
list_for_each_safe(ptmp, pnxt, &kiblnd_data.kib_peers[i]) {
peer = list_entry(ptmp, kib_peer_t, ibp_list);
LASSERT(!kiblnd_peer_idle(peer));
if (peer->ibp_ni != ni)
continue;
if (!(nid == LNET_NID_ANY || nid == peer->ibp_nid))
continue;
count += kiblnd_close_peer_conns_locked(peer, 0);
}
}
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
if (nid == LNET_NID_ANY)
return 0;
return !count ? -ENOENT : 0;
}
static int kiblnd_ctl(lnet_ni_t *ni, unsigned int cmd, void *arg)
{
struct libcfs_ioctl_data *data = arg;
int rc = -EINVAL;
switch (cmd) {
case IOC_LIBCFS_GET_PEER: {
lnet_nid_t nid = 0;
int count = 0;
rc = kiblnd_get_peer_info(ni, data->ioc_count,
&nid, &count);
data->ioc_nid = nid;
data->ioc_count = count;
break;
}
case IOC_LIBCFS_DEL_PEER: {
rc = kiblnd_del_peer(ni, data->ioc_nid);
break;
}
case IOC_LIBCFS_GET_CONN: {
kib_conn_t *conn;
rc = 0;
conn = kiblnd_get_conn_by_idx(ni, data->ioc_count);
if (!conn) {
rc = -ENOENT;
break;
}
LASSERT(conn->ibc_cmid);
data->ioc_nid = conn->ibc_peer->ibp_nid;
if (!conn->ibc_cmid->route.path_rec)
data->ioc_u32[0] = 0;
else
data->ioc_u32[0] =
ib_mtu_enum_to_int(conn->ibc_cmid->route.path_rec->mtu);
kiblnd_conn_decref(conn);
break;
}
case IOC_LIBCFS_CLOSE_CONNECTION: {
rc = kiblnd_close_matching_conns(ni, data->ioc_nid);
break;
}
default:
break;
}
return rc;
}
static void kiblnd_query(lnet_ni_t *ni, lnet_nid_t nid, unsigned long *when)
{
unsigned long last_alive = 0;
unsigned long now = cfs_time_current();
rwlock_t *glock = &kiblnd_data.kib_global_lock;
kib_peer_t *peer;
unsigned long flags;
read_lock_irqsave(glock, flags);
peer = kiblnd_find_peer_locked(nid);
if (peer)
last_alive = peer->ibp_last_alive;
read_unlock_irqrestore(glock, flags);
if (last_alive)
*when = last_alive;
if (!peer)
kiblnd_launch_tx(ni, NULL, nid);
CDEBUG(D_NET, "Peer %s %p, alive %ld secs ago\n",
libcfs_nid2str(nid), peer,
last_alive ? cfs_duration_sec(now - last_alive) : -1);
}
static void kiblnd_free_pages(kib_pages_t *p)
{
int npages = p->ibp_npages;
int i;
for (i = 0; i < npages; i++) {
if (p->ibp_pages[i])
__free_page(p->ibp_pages[i]);
}
LIBCFS_FREE(p, offsetof(kib_pages_t, ibp_pages[npages]));
}
int kiblnd_alloc_pages(kib_pages_t **pp, int cpt, int npages)
{
kib_pages_t *p;
int i;
LIBCFS_CPT_ALLOC(p, lnet_cpt_table(), cpt,
offsetof(kib_pages_t, ibp_pages[npages]));
if (!p) {
CERROR("Can't allocate descriptor for %d pages\n", npages);
return -ENOMEM;
}
memset(p, 0, offsetof(kib_pages_t, ibp_pages[npages]));
p->ibp_npages = npages;
for (i = 0; i < npages; i++) {
p->ibp_pages[i] = alloc_pages_node(
cfs_cpt_spread_node(lnet_cpt_table(), cpt),
GFP_NOFS, 0);
if (!p->ibp_pages[i]) {
CERROR("Can't allocate page %d of %d\n", i, npages);
kiblnd_free_pages(p);
return -ENOMEM;
}
}
*pp = p;
return 0;
}
void kiblnd_unmap_rx_descs(kib_conn_t *conn)
{
kib_rx_t *rx;
int i;
LASSERT(conn->ibc_rxs);
LASSERT(conn->ibc_hdev);
for (i = 0; i < IBLND_RX_MSGS(conn); i++) {
rx = &conn->ibc_rxs[i];
LASSERT(rx->rx_nob >= 0);
kiblnd_dma_unmap_single(conn->ibc_hdev->ibh_ibdev,
KIBLND_UNMAP_ADDR(rx, rx_msgunmap,
rx->rx_msgaddr),
IBLND_MSG_SIZE, DMA_FROM_DEVICE);
}
kiblnd_free_pages(conn->ibc_rx_pages);
conn->ibc_rx_pages = NULL;
}
void kiblnd_map_rx_descs(kib_conn_t *conn)
{
kib_rx_t *rx;
struct page *pg;
int pg_off;
int ipg;
int i;
for (pg_off = ipg = i = 0; i < IBLND_RX_MSGS(conn); i++) {
pg = conn->ibc_rx_pages->ibp_pages[ipg];
rx = &conn->ibc_rxs[i];
rx->rx_conn = conn;
rx->rx_msg = (kib_msg_t *)(((char *)page_address(pg)) + pg_off);
rx->rx_msgaddr = kiblnd_dma_map_single(conn->ibc_hdev->ibh_ibdev,
rx->rx_msg,
IBLND_MSG_SIZE,
DMA_FROM_DEVICE);
LASSERT(!kiblnd_dma_mapping_error(conn->ibc_hdev->ibh_ibdev,
rx->rx_msgaddr));
KIBLND_UNMAP_ADDR_SET(rx, rx_msgunmap, rx->rx_msgaddr);
CDEBUG(D_NET, "rx %d: %p %#llx(%#llx)\n",
i, rx->rx_msg, rx->rx_msgaddr,
(__u64)(page_to_phys(pg) + pg_off));
pg_off += IBLND_MSG_SIZE;
LASSERT(pg_off <= PAGE_SIZE);
if (pg_off == PAGE_SIZE) {
pg_off = 0;
ipg++;
LASSERT(ipg <= IBLND_RX_MSG_PAGES(conn));
}
}
}
static void kiblnd_unmap_tx_pool(kib_tx_pool_t *tpo)
{
kib_hca_dev_t *hdev = tpo->tpo_hdev;
kib_tx_t *tx;
int i;
LASSERT(!tpo->tpo_pool.po_allocated);
if (!hdev)
return;
for (i = 0; i < tpo->tpo_pool.po_size; i++) {
tx = &tpo->tpo_tx_descs[i];
kiblnd_dma_unmap_single(hdev->ibh_ibdev,
KIBLND_UNMAP_ADDR(tx, tx_msgunmap,
tx->tx_msgaddr),
IBLND_MSG_SIZE, DMA_TO_DEVICE);
}
kiblnd_hdev_decref(hdev);
tpo->tpo_hdev = NULL;
}
static kib_hca_dev_t *kiblnd_current_hdev(kib_dev_t *dev)
{
kib_hca_dev_t *hdev;
unsigned long flags;
int i = 0;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
while (dev->ibd_failover) {
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
if (!(i++ % 50))
CDEBUG(D_NET, "%s: Wait for failover\n",
dev->ibd_ifname);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1) / 100);
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
}
kiblnd_hdev_addref_locked(dev->ibd_hdev);
hdev = dev->ibd_hdev;
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
return hdev;
}
static void kiblnd_map_tx_pool(kib_tx_pool_t *tpo)
{
kib_pages_t *txpgs = tpo->tpo_tx_pages;
kib_pool_t *pool = &tpo->tpo_pool;
kib_net_t *net = pool->po_owner->ps_net;
kib_dev_t *dev;
struct page *page;
kib_tx_t *tx;
int page_offset;
int ipage;
int i;
LASSERT(net);
dev = net->ibn_dev;
CLASSERT(IBLND_MSG_SIZE <= PAGE_SIZE);
CLASSERT(!(PAGE_SIZE % IBLND_MSG_SIZE));
tpo->tpo_hdev = kiblnd_current_hdev(dev);
for (ipage = page_offset = i = 0; i < pool->po_size; i++) {
page = txpgs->ibp_pages[ipage];
tx = &tpo->tpo_tx_descs[i];
tx->tx_msg = (kib_msg_t *)(((char *)page_address(page)) +
page_offset);
tx->tx_msgaddr = kiblnd_dma_map_single(
tpo->tpo_hdev->ibh_ibdev, tx->tx_msg,
IBLND_MSG_SIZE, DMA_TO_DEVICE);
LASSERT(!kiblnd_dma_mapping_error(tpo->tpo_hdev->ibh_ibdev,
tx->tx_msgaddr));
KIBLND_UNMAP_ADDR_SET(tx, tx_msgunmap, tx->tx_msgaddr);
list_add(&tx->tx_list, &pool->po_free_list);
page_offset += IBLND_MSG_SIZE;
LASSERT(page_offset <= PAGE_SIZE);
if (page_offset == PAGE_SIZE) {
page_offset = 0;
ipage++;
LASSERT(ipage <= txpgs->ibp_npages);
}
}
}
struct ib_mr *kiblnd_find_rd_dma_mr(struct lnet_ni *ni, kib_rdma_desc_t *rd,
int negotiated_nfrags)
{
kib_net_t *net = ni->ni_data;
kib_hca_dev_t *hdev = net->ibn_dev->ibd_hdev;
struct lnet_ioctl_config_o2iblnd_tunables *tunables;
__u16 nfrags;
int mod;
tunables = &ni->ni_lnd_tunables->lt_tun_u.lt_o2ib;
mod = tunables->lnd_map_on_demand;
nfrags = (negotiated_nfrags != -1) ? negotiated_nfrags : mod;
LASSERT(hdev->ibh_mrs);
if (mod > 0 && nfrags <= rd->rd_nfrags)
return NULL;
return hdev->ibh_mrs;
}
static void kiblnd_destroy_fmr_pool(kib_fmr_pool_t *fpo)
{
LASSERT(!fpo->fpo_map_count);
if (fpo->fpo_is_fmr) {
if (fpo->fmr.fpo_fmr_pool)
ib_destroy_fmr_pool(fpo->fmr.fpo_fmr_pool);
} else {
struct kib_fast_reg_descriptor *frd, *tmp;
int i = 0;
list_for_each_entry_safe(frd, tmp, &fpo->fast_reg.fpo_pool_list,
frd_list) {
list_del(&frd->frd_list);
ib_dereg_mr(frd->frd_mr);
LIBCFS_FREE(frd, sizeof(*frd));
i++;
}
if (i < fpo->fast_reg.fpo_pool_size)
CERROR("FastReg pool still has %d regions registered\n",
fpo->fast_reg.fpo_pool_size - i);
}
if (fpo->fpo_hdev)
kiblnd_hdev_decref(fpo->fpo_hdev);
LIBCFS_FREE(fpo, sizeof(*fpo));
}
static void kiblnd_destroy_fmr_pool_list(struct list_head *head)
{
kib_fmr_pool_t *fpo, *tmp;
list_for_each_entry_safe(fpo, tmp, head, fpo_list) {
list_del(&fpo->fpo_list);
kiblnd_destroy_fmr_pool(fpo);
}
}
static int
kiblnd_fmr_pool_size(struct lnet_ioctl_config_o2iblnd_tunables *tunables,
int ncpts)
{
int size = tunables->lnd_fmr_pool_size / ncpts;
return max(IBLND_FMR_POOL, size);
}
static int
kiblnd_fmr_flush_trigger(struct lnet_ioctl_config_o2iblnd_tunables *tunables,
int ncpts)
{
int size = tunables->lnd_fmr_flush_trigger / ncpts;
return max(IBLND_FMR_POOL_FLUSH, size);
}
static int kiblnd_alloc_fmr_pool(kib_fmr_poolset_t *fps, kib_fmr_pool_t *fpo)
{
struct ib_fmr_pool_param param = {
.max_pages_per_fmr = LNET_MAX_PAYLOAD / PAGE_SIZE,
.page_shift = PAGE_SHIFT,
.access = (IB_ACCESS_LOCAL_WRITE |
IB_ACCESS_REMOTE_WRITE),
.pool_size = fps->fps_pool_size,
.dirty_watermark = fps->fps_flush_trigger,
.flush_function = NULL,
.flush_arg = NULL,
.cache = !!fps->fps_cache };
int rc = 0;
fpo->fmr.fpo_fmr_pool = ib_create_fmr_pool(fpo->fpo_hdev->ibh_pd,
&param);
if (IS_ERR(fpo->fmr.fpo_fmr_pool)) {
rc = PTR_ERR(fpo->fmr.fpo_fmr_pool);
if (rc != -ENOSYS)
CERROR("Failed to create FMR pool: %d\n", rc);
else
CERROR("FMRs are not supported\n");
}
return rc;
}
static int kiblnd_alloc_freg_pool(kib_fmr_poolset_t *fps, kib_fmr_pool_t *fpo)
{
struct kib_fast_reg_descriptor *frd, *tmp;
int i, rc;
INIT_LIST_HEAD(&fpo->fast_reg.fpo_pool_list);
fpo->fast_reg.fpo_pool_size = 0;
for (i = 0; i < fps->fps_pool_size; i++) {
LIBCFS_CPT_ALLOC(frd, lnet_cpt_table(), fps->fps_cpt,
sizeof(*frd));
if (!frd) {
CERROR("Failed to allocate a new fast_reg descriptor\n");
rc = -ENOMEM;
goto out;
}
frd->frd_mr = ib_alloc_mr(fpo->fpo_hdev->ibh_pd,
IB_MR_TYPE_MEM_REG,
LNET_MAX_PAYLOAD / PAGE_SIZE);
if (IS_ERR(frd->frd_mr)) {
rc = PTR_ERR(frd->frd_mr);
CERROR("Failed to allocate ib_alloc_mr: %d\n", rc);
frd->frd_mr = NULL;
goto out_middle;
}
frd->frd_valid = true;
list_add_tail(&frd->frd_list, &fpo->fast_reg.fpo_pool_list);
fpo->fast_reg.fpo_pool_size++;
}
return 0;
out_middle:
if (frd->frd_mr)
ib_dereg_mr(frd->frd_mr);
LIBCFS_FREE(frd, sizeof(*frd));
out:
list_for_each_entry_safe(frd, tmp, &fpo->fast_reg.fpo_pool_list,
frd_list) {
list_del(&frd->frd_list);
ib_dereg_mr(frd->frd_mr);
LIBCFS_FREE(frd, sizeof(*frd));
}
return rc;
}
static int kiblnd_create_fmr_pool(kib_fmr_poolset_t *fps,
kib_fmr_pool_t **pp_fpo)
{
kib_dev_t *dev = fps->fps_net->ibn_dev;
struct ib_device_attr *dev_attr;
kib_fmr_pool_t *fpo;
int rc;
LIBCFS_CPT_ALLOC(fpo, lnet_cpt_table(), fps->fps_cpt, sizeof(*fpo));
if (!fpo)
return -ENOMEM;
fpo->fpo_hdev = kiblnd_current_hdev(dev);
dev_attr = &fpo->fpo_hdev->ibh_ibdev->attrs;
fpo->fpo_is_fmr = 0;
if (fpo->fpo_hdev->ibh_ibdev->alloc_fmr &&
fpo->fpo_hdev->ibh_ibdev->dealloc_fmr &&
fpo->fpo_hdev->ibh_ibdev->map_phys_fmr &&
fpo->fpo_hdev->ibh_ibdev->unmap_fmr) {
LCONSOLE_INFO("Using FMR for registration\n");
fpo->fpo_is_fmr = 1;
} else if (dev_attr->device_cap_flags & IB_DEVICE_MEM_MGT_EXTENSIONS) {
LCONSOLE_INFO("Using FastReg for registration\n");
} else {
rc = -ENOSYS;
LCONSOLE_ERROR_MSG(rc, "IB device does not support FMRs nor FastRegs, can't register memory\n");
goto out_fpo;
}
if (fpo->fpo_is_fmr)
rc = kiblnd_alloc_fmr_pool(fps, fpo);
else
rc = kiblnd_alloc_freg_pool(fps, fpo);
if (rc)
goto out_fpo;
fpo->fpo_deadline = cfs_time_shift(IBLND_POOL_DEADLINE);
fpo->fpo_owner = fps;
*pp_fpo = fpo;
return 0;
out_fpo:
kiblnd_hdev_decref(fpo->fpo_hdev);
LIBCFS_FREE(fpo, sizeof(*fpo));
return rc;
}
static void kiblnd_fail_fmr_poolset(kib_fmr_poolset_t *fps,
struct list_head *zombies)
{
if (!fps->fps_net)
return;
spin_lock(&fps->fps_lock);
while (!list_empty(&fps->fps_pool_list)) {
kib_fmr_pool_t *fpo = list_entry(fps->fps_pool_list.next,
kib_fmr_pool_t, fpo_list);
fpo->fpo_failed = 1;
list_del(&fpo->fpo_list);
if (!fpo->fpo_map_count)
list_add(&fpo->fpo_list, zombies);
else
list_add(&fpo->fpo_list, &fps->fps_failed_pool_list);
}
spin_unlock(&fps->fps_lock);
}
static void kiblnd_fini_fmr_poolset(kib_fmr_poolset_t *fps)
{
if (fps->fps_net) {
kiblnd_destroy_fmr_pool_list(&fps->fps_failed_pool_list);
kiblnd_destroy_fmr_pool_list(&fps->fps_pool_list);
}
}
static int
kiblnd_init_fmr_poolset(kib_fmr_poolset_t *fps, int cpt, int ncpts,
kib_net_t *net,
struct lnet_ioctl_config_o2iblnd_tunables *tunables)
{
kib_fmr_pool_t *fpo;
int rc;
memset(fps, 0, sizeof(*fps));
fps->fps_net = net;
fps->fps_cpt = cpt;
fps->fps_pool_size = kiblnd_fmr_pool_size(tunables, ncpts);
fps->fps_flush_trigger = kiblnd_fmr_flush_trigger(tunables, ncpts);
fps->fps_cache = tunables->lnd_fmr_cache;
spin_lock_init(&fps->fps_lock);
INIT_LIST_HEAD(&fps->fps_pool_list);
INIT_LIST_HEAD(&fps->fps_failed_pool_list);
rc = kiblnd_create_fmr_pool(fps, &fpo);
if (!rc)
list_add_tail(&fpo->fpo_list, &fps->fps_pool_list);
return rc;
}
static int kiblnd_fmr_pool_is_idle(kib_fmr_pool_t *fpo, unsigned long now)
{
if (fpo->fpo_map_count)
return 0;
if (fpo->fpo_failed)
return 1;
return cfs_time_aftereq(now, fpo->fpo_deadline);
}
static int
kiblnd_map_tx_pages(kib_tx_t *tx, kib_rdma_desc_t *rd)
{
__u64 *pages = tx->tx_pages;
kib_hca_dev_t *hdev;
int npages;
int size;
int i;
hdev = tx->tx_pool->tpo_hdev;
for (i = 0, npages = 0; i < rd->rd_nfrags; i++) {
for (size = 0; size < rd->rd_frags[i].rf_nob;
size += hdev->ibh_page_size) {
pages[npages++] = (rd->rd_frags[i].rf_addr &
hdev->ibh_page_mask) + size;
}
}
return npages;
}
void kiblnd_fmr_pool_unmap(kib_fmr_t *fmr, int status)
{
LIST_HEAD(zombies);
kib_fmr_pool_t *fpo = fmr->fmr_pool;
kib_fmr_poolset_t *fps;
unsigned long now = cfs_time_current();
kib_fmr_pool_t *tmp;
int rc;
if (!fpo)
return;
fps = fpo->fpo_owner;
if (fpo->fpo_is_fmr) {
if (fmr->fmr_pfmr) {
rc = ib_fmr_pool_unmap(fmr->fmr_pfmr);
LASSERT(!rc);
fmr->fmr_pfmr = NULL;
}
if (status) {
rc = ib_flush_fmr_pool(fpo->fmr.fpo_fmr_pool);
LASSERT(!rc);
}
} else {
struct kib_fast_reg_descriptor *frd = fmr->fmr_frd;
if (frd) {
frd->frd_valid = false;
spin_lock(&fps->fps_lock);
list_add_tail(&frd->frd_list, &fpo->fast_reg.fpo_pool_list);
spin_unlock(&fps->fps_lock);
fmr->fmr_frd = NULL;
}
}
fmr->fmr_pool = NULL;
spin_lock(&fps->fps_lock);
fpo->fpo_map_count--;
list_for_each_entry_safe(fpo, tmp, &fps->fps_pool_list, fpo_list) {
if (fps->fps_pool_list.next == &fpo->fpo_list)
continue;
if (kiblnd_fmr_pool_is_idle(fpo, now)) {
list_move(&fpo->fpo_list, &zombies);
fps->fps_version++;
}
}
spin_unlock(&fps->fps_lock);
if (!list_empty(&zombies))
kiblnd_destroy_fmr_pool_list(&zombies);
}
int kiblnd_fmr_pool_map(kib_fmr_poolset_t *fps, kib_tx_t *tx,
kib_rdma_desc_t *rd, __u32 nob, __u64 iov,
kib_fmr_t *fmr)
{
__u64 *pages = tx->tx_pages;
bool is_rx = (rd != tx->tx_rd);
bool tx_pages_mapped = 0;
kib_fmr_pool_t *fpo;
int npages = 0;
__u64 version;
int rc;
again:
spin_lock(&fps->fps_lock);
version = fps->fps_version;
list_for_each_entry(fpo, &fps->fps_pool_list, fpo_list) {
fpo->fpo_deadline = cfs_time_shift(IBLND_POOL_DEADLINE);
fpo->fpo_map_count++;
if (fpo->fpo_is_fmr) {
struct ib_pool_fmr *pfmr;
spin_unlock(&fps->fps_lock);
if (!tx_pages_mapped) {
npages = kiblnd_map_tx_pages(tx, rd);
tx_pages_mapped = 1;
}
pfmr = ib_fmr_pool_map_phys(fpo->fmr.fpo_fmr_pool,
pages, npages, iov);
if (likely(!IS_ERR(pfmr))) {
fmr->fmr_key = is_rx ? pfmr->fmr->rkey :
pfmr->fmr->lkey;
fmr->fmr_frd = NULL;
fmr->fmr_pfmr = pfmr;
fmr->fmr_pool = fpo;
return 0;
}
rc = PTR_ERR(pfmr);
} else {
if (!list_empty(&fpo->fast_reg.fpo_pool_list)) {
struct kib_fast_reg_descriptor *frd;
struct ib_reg_wr *wr;
struct ib_mr *mr;
int n;
frd = list_first_entry(&fpo->fast_reg.fpo_pool_list,
struct kib_fast_reg_descriptor,
frd_list);
list_del(&frd->frd_list);
spin_unlock(&fps->fps_lock);
mr = frd->frd_mr;
if (!frd->frd_valid) {
__u32 key = is_rx ? mr->rkey : mr->lkey;
struct ib_send_wr *inv_wr;
inv_wr = &frd->frd_inv_wr;
memset(inv_wr, 0, sizeof(*inv_wr));
inv_wr->opcode = IB_WR_LOCAL_INV;
inv_wr->wr_id = IBLND_WID_MR;
inv_wr->ex.invalidate_rkey = key;
key = ib_inc_rkey(key);
ib_update_fast_reg_key(mr, key);
}
n = ib_map_mr_sg(mr, tx->tx_frags,
tx->tx_nfrags, NULL, PAGE_SIZE);
if (unlikely(n != tx->tx_nfrags)) {
CERROR("Failed to map mr %d/%d elements\n",
n, tx->tx_nfrags);
return n < 0 ? n : -EINVAL;
}
mr->iova = iov;
wr = &frd->frd_fastreg_wr;
memset(wr, 0, sizeof(*wr));
wr->wr.opcode = IB_WR_REG_MR;
wr->wr.wr_id = IBLND_WID_MR;
wr->wr.num_sge = 0;
wr->wr.send_flags = 0;
wr->mr = mr;
wr->key = is_rx ? mr->rkey : mr->lkey;
wr->access = (IB_ACCESS_LOCAL_WRITE |
IB_ACCESS_REMOTE_WRITE);
fmr->fmr_key = is_rx ? mr->rkey : mr->lkey;
fmr->fmr_frd = frd;
fmr->fmr_pfmr = NULL;
fmr->fmr_pool = fpo;
return 0;
}
spin_unlock(&fps->fps_lock);
rc = -EBUSY;
}
spin_lock(&fps->fps_lock);
fpo->fpo_map_count--;
if (rc != -EAGAIN) {
spin_unlock(&fps->fps_lock);
return rc;
}
if (version != fps->fps_version) {
spin_unlock(&fps->fps_lock);
goto again;
}
}
if (fps->fps_increasing) {
spin_unlock(&fps->fps_lock);
CDEBUG(D_NET, "Another thread is allocating new FMR pool, waiting for her to complete\n");
schedule();
goto again;
}
if (time_before(cfs_time_current(), fps->fps_next_retry)) {
spin_unlock(&fps->fps_lock);
return -EAGAIN;
}
fps->fps_increasing = 1;
spin_unlock(&fps->fps_lock);
CDEBUG(D_NET, "Allocate new FMR pool\n");
rc = kiblnd_create_fmr_pool(fps, &fpo);
spin_lock(&fps->fps_lock);
fps->fps_increasing = 0;
if (!rc) {
fps->fps_version++;
list_add_tail(&fpo->fpo_list, &fps->fps_pool_list);
} else {
fps->fps_next_retry = cfs_time_shift(IBLND_POOL_RETRY);
}
spin_unlock(&fps->fps_lock);
goto again;
}
static void kiblnd_fini_pool(kib_pool_t *pool)
{
LASSERT(list_empty(&pool->po_free_list));
LASSERT(!pool->po_allocated);
CDEBUG(D_NET, "Finalize %s pool\n", pool->po_owner->ps_name);
}
static void kiblnd_init_pool(kib_poolset_t *ps, kib_pool_t *pool, int size)
{
CDEBUG(D_NET, "Initialize %s pool\n", ps->ps_name);
memset(pool, 0, sizeof(*pool));
INIT_LIST_HEAD(&pool->po_free_list);
pool->po_deadline = cfs_time_shift(IBLND_POOL_DEADLINE);
pool->po_owner = ps;
pool->po_size = size;
}
static void kiblnd_destroy_pool_list(struct list_head *head)
{
kib_pool_t *pool;
while (!list_empty(head)) {
pool = list_entry(head->next, kib_pool_t, po_list);
list_del(&pool->po_list);
LASSERT(pool->po_owner);
pool->po_owner->ps_pool_destroy(pool);
}
}
static void kiblnd_fail_poolset(kib_poolset_t *ps, struct list_head *zombies)
{
if (!ps->ps_net)
return;
spin_lock(&ps->ps_lock);
while (!list_empty(&ps->ps_pool_list)) {
kib_pool_t *po = list_entry(ps->ps_pool_list.next,
kib_pool_t, po_list);
po->po_failed = 1;
list_del(&po->po_list);
if (!po->po_allocated)
list_add(&po->po_list, zombies);
else
list_add(&po->po_list, &ps->ps_failed_pool_list);
}
spin_unlock(&ps->ps_lock);
}
static void kiblnd_fini_poolset(kib_poolset_t *ps)
{
if (ps->ps_net) {
kiblnd_destroy_pool_list(&ps->ps_failed_pool_list);
kiblnd_destroy_pool_list(&ps->ps_pool_list);
}
}
static int kiblnd_init_poolset(kib_poolset_t *ps, int cpt,
kib_net_t *net, char *name, int size,
kib_ps_pool_create_t po_create,
kib_ps_pool_destroy_t po_destroy,
kib_ps_node_init_t nd_init,
kib_ps_node_fini_t nd_fini)
{
kib_pool_t *pool;
int rc;
memset(ps, 0, sizeof(*ps));
ps->ps_cpt = cpt;
ps->ps_net = net;
ps->ps_pool_create = po_create;
ps->ps_pool_destroy = po_destroy;
ps->ps_node_init = nd_init;
ps->ps_node_fini = nd_fini;
ps->ps_pool_size = size;
if (strlcpy(ps->ps_name, name, sizeof(ps->ps_name))
>= sizeof(ps->ps_name))
return -E2BIG;
spin_lock_init(&ps->ps_lock);
INIT_LIST_HEAD(&ps->ps_pool_list);
INIT_LIST_HEAD(&ps->ps_failed_pool_list);
rc = ps->ps_pool_create(ps, size, &pool);
if (!rc)
list_add(&pool->po_list, &ps->ps_pool_list);
else
CERROR("Failed to create the first pool for %s\n", ps->ps_name);
return rc;
}
static int kiblnd_pool_is_idle(kib_pool_t *pool, unsigned long now)
{
if (pool->po_allocated)
return 0;
if (pool->po_failed)
return 1;
return cfs_time_aftereq(now, pool->po_deadline);
}
void kiblnd_pool_free_node(kib_pool_t *pool, struct list_head *node)
{
LIST_HEAD(zombies);
kib_poolset_t *ps = pool->po_owner;
kib_pool_t *tmp;
unsigned long now = cfs_time_current();
spin_lock(&ps->ps_lock);
if (ps->ps_node_fini)
ps->ps_node_fini(pool, node);
LASSERT(pool->po_allocated > 0);
list_add(node, &pool->po_free_list);
pool->po_allocated--;
list_for_each_entry_safe(pool, tmp, &ps->ps_pool_list, po_list) {
if (ps->ps_pool_list.next == &pool->po_list)
continue;
if (kiblnd_pool_is_idle(pool, now))
list_move(&pool->po_list, &zombies);
}
spin_unlock(&ps->ps_lock);
if (!list_empty(&zombies))
kiblnd_destroy_pool_list(&zombies);
}
struct list_head *kiblnd_pool_alloc_node(kib_poolset_t *ps)
{
struct list_head *node;
kib_pool_t *pool;
unsigned int interval = 1;
unsigned long time_before;
unsigned int trips = 0;
int rc;
again:
spin_lock(&ps->ps_lock);
list_for_each_entry(pool, &ps->ps_pool_list, po_list) {
if (list_empty(&pool->po_free_list))
continue;
pool->po_allocated++;
pool->po_deadline = cfs_time_shift(IBLND_POOL_DEADLINE);
node = pool->po_free_list.next;
list_del(node);
if (ps->ps_node_init) {
ps->ps_node_init(pool, node);
}
spin_unlock(&ps->ps_lock);
return node;
}
if (ps->ps_increasing) {
spin_unlock(&ps->ps_lock);
trips++;
CDEBUG(D_NET, "Another thread is allocating new %s pool, waiting %d HZs for her to complete. trips = %d\n",
ps->ps_name, interval, trips);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(interval);
if (interval < cfs_time_seconds(1))
interval *= 2;
goto again;
}
if (time_before(cfs_time_current(), ps->ps_next_retry)) {
spin_unlock(&ps->ps_lock);
return NULL;
}
ps->ps_increasing = 1;
spin_unlock(&ps->ps_lock);
CDEBUG(D_NET, "%s pool exhausted, allocate new pool\n", ps->ps_name);
time_before = cfs_time_current();
rc = ps->ps_pool_create(ps, ps->ps_pool_size, &pool);
CDEBUG(D_NET, "ps_pool_create took %lu HZ to complete",
cfs_time_current() - time_before);
spin_lock(&ps->ps_lock);
ps->ps_increasing = 0;
if (!rc) {
list_add_tail(&pool->po_list, &ps->ps_pool_list);
} else {
ps->ps_next_retry = cfs_time_shift(IBLND_POOL_RETRY);
CERROR("Can't allocate new %s pool because out of memory\n",
ps->ps_name);
}
spin_unlock(&ps->ps_lock);
goto again;
}
static void kiblnd_destroy_tx_pool(kib_pool_t *pool)
{
kib_tx_pool_t *tpo = container_of(pool, kib_tx_pool_t, tpo_pool);
int i;
LASSERT(!pool->po_allocated);
if (tpo->tpo_tx_pages) {
kiblnd_unmap_tx_pool(tpo);
kiblnd_free_pages(tpo->tpo_tx_pages);
}
if (!tpo->tpo_tx_descs)
goto out;
for (i = 0; i < pool->po_size; i++) {
kib_tx_t *tx = &tpo->tpo_tx_descs[i];
list_del(&tx->tx_list);
if (tx->tx_pages)
LIBCFS_FREE(tx->tx_pages,
LNET_MAX_IOV *
sizeof(*tx->tx_pages));
if (tx->tx_frags)
LIBCFS_FREE(tx->tx_frags,
IBLND_MAX_RDMA_FRAGS *
sizeof(*tx->tx_frags));
if (tx->tx_wrq)
LIBCFS_FREE(tx->tx_wrq,
(1 + IBLND_MAX_RDMA_FRAGS) *
sizeof(*tx->tx_wrq));
if (tx->tx_sge)
LIBCFS_FREE(tx->tx_sge,
(1 + IBLND_MAX_RDMA_FRAGS) *
sizeof(*tx->tx_sge));
if (tx->tx_rd)
LIBCFS_FREE(tx->tx_rd,
offsetof(kib_rdma_desc_t,
rd_frags[IBLND_MAX_RDMA_FRAGS]));
}
LIBCFS_FREE(tpo->tpo_tx_descs,
pool->po_size * sizeof(kib_tx_t));
out:
kiblnd_fini_pool(pool);
LIBCFS_FREE(tpo, sizeof(*tpo));
}
static int kiblnd_tx_pool_size(int ncpts)
{
int ntx = *kiblnd_tunables.kib_ntx / ncpts;
return max(IBLND_TX_POOL, ntx);
}
static int kiblnd_create_tx_pool(kib_poolset_t *ps, int size,
kib_pool_t **pp_po)
{
int i;
int npg;
kib_pool_t *pool;
kib_tx_pool_t *tpo;
LIBCFS_CPT_ALLOC(tpo, lnet_cpt_table(), ps->ps_cpt, sizeof(*tpo));
if (!tpo) {
CERROR("Failed to allocate TX pool\n");
return -ENOMEM;
}
pool = &tpo->tpo_pool;
kiblnd_init_pool(ps, pool, size);
tpo->tpo_tx_descs = NULL;
tpo->tpo_tx_pages = NULL;
npg = (size * IBLND_MSG_SIZE + PAGE_SIZE - 1) / PAGE_SIZE;
if (kiblnd_alloc_pages(&tpo->tpo_tx_pages, ps->ps_cpt, npg)) {
CERROR("Can't allocate tx pages: %d\n", npg);
LIBCFS_FREE(tpo, sizeof(*tpo));
return -ENOMEM;
}
LIBCFS_CPT_ALLOC(tpo->tpo_tx_descs, lnet_cpt_table(), ps->ps_cpt,
size * sizeof(kib_tx_t));
if (!tpo->tpo_tx_descs) {
CERROR("Can't allocate %d tx descriptors\n", size);
ps->ps_pool_destroy(pool);
return -ENOMEM;
}
memset(tpo->tpo_tx_descs, 0, size * sizeof(kib_tx_t));
for (i = 0; i < size; i++) {
kib_tx_t *tx = &tpo->tpo_tx_descs[i];
tx->tx_pool = tpo;
if (ps->ps_net->ibn_fmr_ps) {
LIBCFS_CPT_ALLOC(tx->tx_pages,
lnet_cpt_table(), ps->ps_cpt,
LNET_MAX_IOV * sizeof(*tx->tx_pages));
if (!tx->tx_pages)
break;
}
LIBCFS_CPT_ALLOC(tx->tx_frags, lnet_cpt_table(), ps->ps_cpt,
IBLND_MAX_RDMA_FRAGS * sizeof(*tx->tx_frags));
if (!tx->tx_frags)
break;
sg_init_table(tx->tx_frags, IBLND_MAX_RDMA_FRAGS);
LIBCFS_CPT_ALLOC(tx->tx_wrq, lnet_cpt_table(), ps->ps_cpt,
(1 + IBLND_MAX_RDMA_FRAGS) *
sizeof(*tx->tx_wrq));
if (!tx->tx_wrq)
break;
LIBCFS_CPT_ALLOC(tx->tx_sge, lnet_cpt_table(), ps->ps_cpt,
(1 + IBLND_MAX_RDMA_FRAGS) *
sizeof(*tx->tx_sge));
if (!tx->tx_sge)
break;
LIBCFS_CPT_ALLOC(tx->tx_rd, lnet_cpt_table(), ps->ps_cpt,
offsetof(kib_rdma_desc_t,
rd_frags[IBLND_MAX_RDMA_FRAGS]));
if (!tx->tx_rd)
break;
}
if (i == size) {
kiblnd_map_tx_pool(tpo);
*pp_po = pool;
return 0;
}
ps->ps_pool_destroy(pool);
return -ENOMEM;
}
static void kiblnd_tx_init(kib_pool_t *pool, struct list_head *node)
{
kib_tx_poolset_t *tps = container_of(pool->po_owner, kib_tx_poolset_t,
tps_poolset);
kib_tx_t *tx = list_entry(node, kib_tx_t, tx_list);
tx->tx_cookie = tps->tps_next_tx_cookie++;
}
static void kiblnd_net_fini_pools(kib_net_t *net)
{
int i;
cfs_cpt_for_each(i, lnet_cpt_table()) {
kib_tx_poolset_t *tps;
kib_fmr_poolset_t *fps;
if (net->ibn_tx_ps) {
tps = net->ibn_tx_ps[i];
kiblnd_fini_poolset(&tps->tps_poolset);
}
if (net->ibn_fmr_ps) {
fps = net->ibn_fmr_ps[i];
kiblnd_fini_fmr_poolset(fps);
}
}
if (net->ibn_tx_ps) {
cfs_percpt_free(net->ibn_tx_ps);
net->ibn_tx_ps = NULL;
}
if (net->ibn_fmr_ps) {
cfs_percpt_free(net->ibn_fmr_ps);
net->ibn_fmr_ps = NULL;
}
}
static int kiblnd_net_init_pools(kib_net_t *net, lnet_ni_t *ni, __u32 *cpts,
int ncpts)
{
struct lnet_ioctl_config_o2iblnd_tunables *tunables;
unsigned long flags;
int cpt;
int rc;
int i;
tunables = &ni->ni_lnd_tunables->lt_tun_u.lt_o2ib;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (!tunables->lnd_map_on_demand) {
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
goto create_tx_pool;
}
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
if (tunables->lnd_fmr_pool_size < *kiblnd_tunables.kib_ntx / 4) {
CERROR("Can't set fmr pool size (%d) < ntx / 4(%d)\n",
tunables->lnd_fmr_pool_size,
*kiblnd_tunables.kib_ntx / 4);
rc = -EINVAL;
goto failed;
}
LASSERT(!net->ibn_tx_ps);
net->ibn_fmr_ps = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(kib_fmr_poolset_t));
if (!net->ibn_fmr_ps) {
CERROR("Failed to allocate FMR pool array\n");
rc = -ENOMEM;
goto failed;
}
for (i = 0; i < ncpts; i++) {
cpt = !cpts ? i : cpts[i];
rc = kiblnd_init_fmr_poolset(net->ibn_fmr_ps[cpt], cpt, ncpts,
net, tunables);
if (rc) {
CERROR("Can't initialize FMR pool for CPT %d: %d\n",
cpt, rc);
goto failed;
}
}
if (i > 0)
LASSERT(i == ncpts);
create_tx_pool:
net->ibn_tx_ps = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(kib_tx_poolset_t));
if (!net->ibn_tx_ps) {
CERROR("Failed to allocate tx pool array\n");
rc = -ENOMEM;
goto failed;
}
for (i = 0; i < ncpts; i++) {
cpt = !cpts ? i : cpts[i];
rc = kiblnd_init_poolset(&net->ibn_tx_ps[cpt]->tps_poolset,
cpt, net, "TX",
kiblnd_tx_pool_size(ncpts),
kiblnd_create_tx_pool,
kiblnd_destroy_tx_pool,
kiblnd_tx_init, NULL);
if (rc) {
CERROR("Can't initialize TX pool for CPT %d: %d\n",
cpt, rc);
goto failed;
}
}
return 0;
failed:
kiblnd_net_fini_pools(net);
LASSERT(rc);
return rc;
}
static int kiblnd_hdev_get_attr(kib_hca_dev_t *hdev)
{
hdev->ibh_page_shift = PAGE_SHIFT;
hdev->ibh_page_size = 1 << PAGE_SHIFT;
hdev->ibh_page_mask = ~((__u64)hdev->ibh_page_size - 1);
hdev->ibh_mr_size = hdev->ibh_ibdev->attrs.max_mr_size;
if (hdev->ibh_mr_size == ~0ULL) {
hdev->ibh_mr_shift = 64;
return 0;
}
CERROR("Invalid mr size: %#llx\n", hdev->ibh_mr_size);
return -EINVAL;
}
static void kiblnd_hdev_cleanup_mrs(kib_hca_dev_t *hdev)
{
if (!hdev->ibh_mrs)
return;
ib_dereg_mr(hdev->ibh_mrs);
hdev->ibh_mrs = NULL;
}
void kiblnd_hdev_destroy(kib_hca_dev_t *hdev)
{
kiblnd_hdev_cleanup_mrs(hdev);
if (hdev->ibh_pd)
ib_dealloc_pd(hdev->ibh_pd);
if (hdev->ibh_cmid)
rdma_destroy_id(hdev->ibh_cmid);
LIBCFS_FREE(hdev, sizeof(*hdev));
}
static int kiblnd_hdev_setup_mrs(kib_hca_dev_t *hdev)
{
struct ib_mr *mr;
int rc;
int acflags = IB_ACCESS_LOCAL_WRITE | IB_ACCESS_REMOTE_WRITE;
rc = kiblnd_hdev_get_attr(hdev);
if (rc)
return rc;
mr = ib_get_dma_mr(hdev->ibh_pd, acflags);
if (IS_ERR(mr)) {
CERROR("Failed ib_get_dma_mr : %ld\n", PTR_ERR(mr));
kiblnd_hdev_cleanup_mrs(hdev);
return PTR_ERR(mr);
}
hdev->ibh_mrs = mr;
return 0;
}
static int kiblnd_dummy_callback(struct rdma_cm_id *cmid,
struct rdma_cm_event *event)
{
return 0;
}
static int kiblnd_dev_need_failover(kib_dev_t *dev)
{
struct rdma_cm_id *cmid;
struct sockaddr_in srcaddr;
struct sockaddr_in dstaddr;
int rc;
if (!dev->ibd_hdev ||
!dev->ibd_hdev->ibh_cmid ||
*kiblnd_tunables.kib_dev_failover > 1)
return 1;
cmid = kiblnd_rdma_create_id(kiblnd_dummy_callback, dev, RDMA_PS_TCP,
IB_QPT_RC);
if (IS_ERR(cmid)) {
rc = PTR_ERR(cmid);
CERROR("Failed to create cmid for failover: %d\n", rc);
return rc;
}
memset(&srcaddr, 0, sizeof(srcaddr));
srcaddr.sin_family = AF_INET;
srcaddr.sin_addr.s_addr = (__force u32)htonl(dev->ibd_ifip);
memset(&dstaddr, 0, sizeof(dstaddr));
dstaddr.sin_family = AF_INET;
rc = rdma_resolve_addr(cmid, (struct sockaddr *)&srcaddr,
(struct sockaddr *)&dstaddr, 1);
if (rc || !cmid->device) {
CERROR("Failed to bind %s:%pI4h to device(%p): %d\n",
dev->ibd_ifname, &dev->ibd_ifip,
cmid->device, rc);
rdma_destroy_id(cmid);
return rc;
}
rc = dev->ibd_hdev->ibh_ibdev != cmid->device;
rdma_destroy_id(cmid);
return rc;
}
int kiblnd_dev_failover(kib_dev_t *dev)
{
LIST_HEAD(zombie_tpo);
LIST_HEAD(zombie_ppo);
LIST_HEAD(zombie_fpo);
struct rdma_cm_id *cmid = NULL;
kib_hca_dev_t *hdev = NULL;
struct ib_pd *pd;
kib_net_t *net;
struct sockaddr_in addr;
unsigned long flags;
int rc = 0;
int i;
LASSERT(*kiblnd_tunables.kib_dev_failover > 1 ||
dev->ibd_can_failover || !dev->ibd_hdev);
rc = kiblnd_dev_need_failover(dev);
if (rc <= 0)
goto out;
if (dev->ibd_hdev &&
dev->ibd_hdev->ibh_cmid) {
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
cmid = dev->ibd_hdev->ibh_cmid;
dev->ibd_hdev->ibh_cmid = NULL;
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
rdma_destroy_id(cmid);
}
cmid = kiblnd_rdma_create_id(kiblnd_cm_callback, dev, RDMA_PS_TCP,
IB_QPT_RC);
if (IS_ERR(cmid)) {
rc = PTR_ERR(cmid);
CERROR("Failed to create cmid for failover: %d\n", rc);
goto out;
}
memset(&addr, 0, sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = (__force u32)htonl(dev->ibd_ifip);
addr.sin_port = htons(*kiblnd_tunables.kib_service);
rc = rdma_bind_addr(cmid, (struct sockaddr *)&addr);
if (rc || !cmid->device) {
CERROR("Failed to bind %s:%pI4h to device(%p): %d\n",
dev->ibd_ifname, &dev->ibd_ifip,
cmid->device, rc);
rdma_destroy_id(cmid);
goto out;
}
LIBCFS_ALLOC(hdev, sizeof(*hdev));
if (!hdev) {
CERROR("Failed to allocate kib_hca_dev\n");
rdma_destroy_id(cmid);
rc = -ENOMEM;
goto out;
}
atomic_set(&hdev->ibh_ref, 1);
hdev->ibh_dev = dev;
hdev->ibh_cmid = cmid;
hdev->ibh_ibdev = cmid->device;
pd = ib_alloc_pd(cmid->device);
if (IS_ERR(pd)) {
rc = PTR_ERR(pd);
CERROR("Can't allocate PD: %d\n", rc);
goto out;
}
hdev->ibh_pd = pd;
rc = rdma_listen(cmid, 0);
if (rc) {
CERROR("Can't start new listener: %d\n", rc);
goto out;
}
rc = kiblnd_hdev_setup_mrs(hdev);
if (rc) {
CERROR("Can't setup device: %d\n", rc);
goto out;
}
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
swap(dev->ibd_hdev, hdev);
list_for_each_entry(net, &dev->ibd_nets, ibn_list) {
cfs_cpt_for_each(i, lnet_cpt_table()) {
kiblnd_fail_poolset(&net->ibn_tx_ps[i]->tps_poolset,
&zombie_tpo);
if (net->ibn_fmr_ps)
kiblnd_fail_fmr_poolset(net->ibn_fmr_ps[i],
&zombie_fpo);
}
}
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
out:
if (!list_empty(&zombie_tpo))
kiblnd_destroy_pool_list(&zombie_tpo);
if (!list_empty(&zombie_ppo))
kiblnd_destroy_pool_list(&zombie_ppo);
if (!list_empty(&zombie_fpo))
kiblnd_destroy_fmr_pool_list(&zombie_fpo);
if (hdev)
kiblnd_hdev_decref(hdev);
if (rc)
dev->ibd_failed_failover++;
else
dev->ibd_failed_failover = 0;
return rc;
}
void kiblnd_destroy_dev(kib_dev_t *dev)
{
LASSERT(!dev->ibd_nnets);
LASSERT(list_empty(&dev->ibd_nets));
list_del(&dev->ibd_fail_list);
list_del(&dev->ibd_list);
if (dev->ibd_hdev)
kiblnd_hdev_decref(dev->ibd_hdev);
LIBCFS_FREE(dev, sizeof(*dev));
}
static kib_dev_t *kiblnd_create_dev(char *ifname)
{
struct net_device *netdev;
kib_dev_t *dev;
__u32 netmask;
__u32 ip;
int up;
int rc;
rc = lnet_ipif_query(ifname, &up, &ip, &netmask);
if (rc) {
CERROR("Can't query IPoIB interface %s: %d\n",
ifname, rc);
return NULL;
}
if (!up) {
CERROR("Can't query IPoIB interface %s: it's down\n", ifname);
return NULL;
}
LIBCFS_ALLOC(dev, sizeof(*dev));
if (!dev)
return NULL;
netdev = dev_get_by_name(&init_net, ifname);
if (!netdev) {
dev->ibd_can_failover = 0;
} else {
dev->ibd_can_failover = !!(netdev->flags & IFF_MASTER);
dev_put(netdev);
}
INIT_LIST_HEAD(&dev->ibd_nets);
INIT_LIST_HEAD(&dev->ibd_list);
INIT_LIST_HEAD(&dev->ibd_fail_list);
dev->ibd_ifip = ip;
strcpy(&dev->ibd_ifname[0], ifname);
rc = kiblnd_dev_failover(dev);
if (rc) {
CERROR("Can't initialize device: %d\n", rc);
LIBCFS_FREE(dev, sizeof(*dev));
return NULL;
}
list_add_tail(&dev->ibd_list, &kiblnd_data.kib_devs);
return dev;
}
static void kiblnd_base_shutdown(void)
{
struct kib_sched_info *sched;
int i;
LASSERT(list_empty(&kiblnd_data.kib_devs));
switch (kiblnd_data.kib_init) {
default:
LBUG();
case IBLND_INIT_ALL:
case IBLND_INIT_DATA:
LASSERT(kiblnd_data.kib_peers);
for (i = 0; i < kiblnd_data.kib_peer_hash_size; i++)
LASSERT(list_empty(&kiblnd_data.kib_peers[i]));
LASSERT(list_empty(&kiblnd_data.kib_connd_zombies));
LASSERT(list_empty(&kiblnd_data.kib_connd_conns));
LASSERT(list_empty(&kiblnd_data.kib_reconn_list));
LASSERT(list_empty(&kiblnd_data.kib_reconn_wait));
kiblnd_data.kib_shutdown = 1;
cfs_percpt_for_each(sched, i, kiblnd_data.kib_scheds)
wake_up_all(&sched->ibs_waitq);
wake_up_all(&kiblnd_data.kib_connd_waitq);
wake_up_all(&kiblnd_data.kib_failover_waitq);
i = 2;
while (atomic_read(&kiblnd_data.kib_nthreads)) {
i++;
CDEBUG(((i & (-i)) == i) ? D_WARNING : D_NET,
"Waiting for %d threads to terminate\n",
atomic_read(&kiblnd_data.kib_nthreads));
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1));
}
case IBLND_INIT_NOTHING:
break;
}
if (kiblnd_data.kib_peers) {
LIBCFS_FREE(kiblnd_data.kib_peers,
sizeof(struct list_head) *
kiblnd_data.kib_peer_hash_size);
}
if (kiblnd_data.kib_scheds)
cfs_percpt_free(kiblnd_data.kib_scheds);
kiblnd_data.kib_init = IBLND_INIT_NOTHING;
module_put(THIS_MODULE);
}
static void kiblnd_shutdown(lnet_ni_t *ni)
{
kib_net_t *net = ni->ni_data;
rwlock_t *g_lock = &kiblnd_data.kib_global_lock;
int i;
unsigned long flags;
LASSERT(kiblnd_data.kib_init == IBLND_INIT_ALL);
if (!net)
goto out;
write_lock_irqsave(g_lock, flags);
net->ibn_shutdown = 1;
write_unlock_irqrestore(g_lock, flags);
switch (net->ibn_init) {
default:
LBUG();
case IBLND_INIT_ALL:
kiblnd_del_peer(ni, LNET_NID_ANY);
i = 2;
while (atomic_read(&net->ibn_npeers)) {
i++;
CDEBUG(((i & (-i)) == i) ? D_WARNING : D_NET,
"%s: waiting for %d peers to disconnect\n",
libcfs_nid2str(ni->ni_nid),
atomic_read(&net->ibn_npeers));
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1));
}
kiblnd_net_fini_pools(net);
write_lock_irqsave(g_lock, flags);
LASSERT(net->ibn_dev->ibd_nnets > 0);
net->ibn_dev->ibd_nnets--;
list_del(&net->ibn_list);
write_unlock_irqrestore(g_lock, flags);
case IBLND_INIT_NOTHING:
LASSERT(!atomic_read(&net->ibn_nconns));
if (net->ibn_dev && !net->ibn_dev->ibd_nnets)
kiblnd_destroy_dev(net->ibn_dev);
break;
}
net->ibn_init = IBLND_INIT_NOTHING;
ni->ni_data = NULL;
LIBCFS_FREE(net, sizeof(*net));
out:
if (list_empty(&kiblnd_data.kib_devs))
kiblnd_base_shutdown();
}
static int kiblnd_base_startup(void)
{
struct kib_sched_info *sched;
int rc;
int i;
LASSERT(kiblnd_data.kib_init == IBLND_INIT_NOTHING);
try_module_get(THIS_MODULE);
memset(&kiblnd_data, 0, sizeof(kiblnd_data));
rwlock_init(&kiblnd_data.kib_global_lock);
INIT_LIST_HEAD(&kiblnd_data.kib_devs);
INIT_LIST_HEAD(&kiblnd_data.kib_failed_devs);
kiblnd_data.kib_peer_hash_size = IBLND_PEER_HASH_SIZE;
LIBCFS_ALLOC(kiblnd_data.kib_peers,
sizeof(struct list_head) * kiblnd_data.kib_peer_hash_size);
if (!kiblnd_data.kib_peers)
goto failed;
for (i = 0; i < kiblnd_data.kib_peer_hash_size; i++)
INIT_LIST_HEAD(&kiblnd_data.kib_peers[i]);
spin_lock_init(&kiblnd_data.kib_connd_lock);
INIT_LIST_HEAD(&kiblnd_data.kib_connd_conns);
INIT_LIST_HEAD(&kiblnd_data.kib_connd_zombies);
INIT_LIST_HEAD(&kiblnd_data.kib_reconn_list);
INIT_LIST_HEAD(&kiblnd_data.kib_reconn_wait);
init_waitqueue_head(&kiblnd_data.kib_connd_waitq);
init_waitqueue_head(&kiblnd_data.kib_failover_waitq);
kiblnd_data.kib_scheds = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(*sched));
if (!kiblnd_data.kib_scheds)
goto failed;
cfs_percpt_for_each(sched, i, kiblnd_data.kib_scheds) {
int nthrs;
spin_lock_init(&sched->ibs_lock);
INIT_LIST_HEAD(&sched->ibs_conns);
init_waitqueue_head(&sched->ibs_waitq);
nthrs = cfs_cpt_weight(lnet_cpt_table(), i);
if (*kiblnd_tunables.kib_nscheds > 0) {
nthrs = min(nthrs, *kiblnd_tunables.kib_nscheds);
} else {
nthrs = min(max(IBLND_N_SCHED, nthrs >> 1), nthrs);
}
sched->ibs_nthreads_max = nthrs;
sched->ibs_cpt = i;
}
kiblnd_data.kib_error_qpa.qp_state = IB_QPS_ERR;
kiblnd_data.kib_init = IBLND_INIT_DATA;
rc = kiblnd_thread_start(kiblnd_connd, NULL, "kiblnd_connd");
if (rc) {
CERROR("Can't spawn o2iblnd connd: %d\n", rc);
goto failed;
}
if (*kiblnd_tunables.kib_dev_failover)
rc = kiblnd_thread_start(kiblnd_failover_thread, NULL,
"kiblnd_failover");
if (rc) {
CERROR("Can't spawn o2iblnd failover thread: %d\n", rc);
goto failed;
}
kiblnd_data.kib_init = IBLND_INIT_ALL;
return 0;
failed:
kiblnd_base_shutdown();
return -ENETDOWN;
}
static int kiblnd_start_schedulers(struct kib_sched_info *sched)
{
int rc = 0;
int nthrs;
int i;
if (!sched->ibs_nthreads) {
if (*kiblnd_tunables.kib_nscheds > 0) {
nthrs = sched->ibs_nthreads_max;
} else {
nthrs = cfs_cpt_weight(lnet_cpt_table(),
sched->ibs_cpt);
nthrs = min(max(IBLND_N_SCHED, nthrs >> 1), nthrs);
nthrs = min(IBLND_N_SCHED_HIGH, nthrs);
}
} else {
LASSERT(sched->ibs_nthreads <= sched->ibs_nthreads_max);
nthrs = sched->ibs_nthreads < sched->ibs_nthreads_max;
}
for (i = 0; i < nthrs; i++) {
long id;
char name[20];
id = KIB_THREAD_ID(sched->ibs_cpt, sched->ibs_nthreads + i);
snprintf(name, sizeof(name), "kiblnd_sd_%02ld_%02ld",
KIB_THREAD_CPT(id), KIB_THREAD_TID(id));
rc = kiblnd_thread_start(kiblnd_scheduler, (void *)id, name);
if (!rc)
continue;
CERROR("Can't spawn thread %d for scheduler[%d]: %d\n",
sched->ibs_cpt, sched->ibs_nthreads + i, rc);
break;
}
sched->ibs_nthreads += i;
return rc;
}
static int kiblnd_dev_start_threads(kib_dev_t *dev, int newdev, __u32 *cpts,
int ncpts)
{
int cpt;
int rc;
int i;
for (i = 0; i < ncpts; i++) {
struct kib_sched_info *sched;
cpt = !cpts ? i : cpts[i];
sched = kiblnd_data.kib_scheds[cpt];
if (!newdev && sched->ibs_nthreads > 0)
continue;
rc = kiblnd_start_schedulers(kiblnd_data.kib_scheds[cpt]);
if (rc) {
CERROR("Failed to start scheduler threads for %s\n",
dev->ibd_ifname);
return rc;
}
}
return 0;
}
static kib_dev_t *kiblnd_dev_search(char *ifname)
{
kib_dev_t *alias = NULL;
kib_dev_t *dev;
char *colon;
char *colon2;
colon = strchr(ifname, ':');
list_for_each_entry(dev, &kiblnd_data.kib_devs, ibd_list) {
if (!strcmp(&dev->ibd_ifname[0], ifname))
return dev;
if (alias)
continue;
colon2 = strchr(dev->ibd_ifname, ':');
if (colon)
*colon = 0;
if (colon2)
*colon2 = 0;
if (!strcmp(&dev->ibd_ifname[0], ifname))
alias = dev;
if (colon)
*colon = ':';
if (colon2)
*colon2 = ':';
}
return alias;
}
static int kiblnd_startup(lnet_ni_t *ni)
{
char *ifname;
kib_dev_t *ibdev = NULL;
kib_net_t *net;
struct timespec64 tv;
unsigned long flags;
int rc;
int newdev;
LASSERT(ni->ni_lnd == &the_o2iblnd);
if (kiblnd_data.kib_init == IBLND_INIT_NOTHING) {
rc = kiblnd_base_startup();
if (rc)
return rc;
}
LIBCFS_ALLOC(net, sizeof(*net));
ni->ni_data = net;
if (!net)
goto net_failed;
ktime_get_real_ts64(&tv);
net->ibn_incarnation = tv.tv_sec * USEC_PER_SEC +
tv.tv_nsec / NSEC_PER_USEC;
rc = kiblnd_tunables_setup(ni);
if (rc)
goto net_failed;
if (ni->ni_interfaces[0]) {
CLASSERT(LNET_MAX_INTERFACES > 1);
if (ni->ni_interfaces[1]) {
CERROR("Multiple interfaces not supported\n");
goto failed;
}
ifname = ni->ni_interfaces[0];
} else {
ifname = *kiblnd_tunables.kib_default_ipif;
}
if (strlen(ifname) >= sizeof(ibdev->ibd_ifname)) {
CERROR("IPoIB interface name too long: %s\n", ifname);
goto failed;
}
ibdev = kiblnd_dev_search(ifname);
newdev = !ibdev;
if (!ibdev || strcmp(&ibdev->ibd_ifname[0], ifname))
ibdev = kiblnd_create_dev(ifname);
if (!ibdev)
goto failed;
net->ibn_dev = ibdev;
ni->ni_nid = LNET_MKNID(LNET_NIDNET(ni->ni_nid), ibdev->ibd_ifip);
rc = kiblnd_dev_start_threads(ibdev, newdev,
ni->ni_cpts, ni->ni_ncpts);
if (rc)
goto failed;
rc = kiblnd_net_init_pools(net, ni, ni->ni_cpts, ni->ni_ncpts);
if (rc) {
CERROR("Failed to initialize NI pools: %d\n", rc);
goto failed;
}
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
ibdev->ibd_nnets++;
list_add_tail(&net->ibn_list, &ibdev->ibd_nets);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
net->ibn_init = IBLND_INIT_ALL;
return 0;
failed:
if (!net->ibn_dev && ibdev)
kiblnd_destroy_dev(ibdev);
net_failed:
kiblnd_shutdown(ni);
CDEBUG(D_NET, "kiblnd_startup failed\n");
return -ENETDOWN;
}
static void __exit ko2iblnd_exit(void)
{
lnet_unregister_lnd(&the_o2iblnd);
}
static int __init ko2iblnd_init(void)
{
CLASSERT(sizeof(kib_msg_t) <= IBLND_MSG_SIZE);
CLASSERT(offsetof(kib_msg_t,
ibm_u.get.ibgm_rd.rd_frags[IBLND_MAX_RDMA_FRAGS])
<= IBLND_MSG_SIZE);
CLASSERT(offsetof(kib_msg_t,
ibm_u.putack.ibpam_rd.rd_frags[IBLND_MAX_RDMA_FRAGS])
<= IBLND_MSG_SIZE);
kiblnd_tunables_init();
lnet_register_lnd(&the_o2iblnd);
return 0;
}
