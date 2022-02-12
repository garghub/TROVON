static void
kiblnd_tx_done(lnet_ni_t *ni, struct kib_tx *tx)
{
lnet_msg_t *lntmsg[2];
struct kib_net *net = ni->ni_data;
int rc;
int i;
LASSERT(net);
LASSERT(!in_interrupt());
LASSERT(!tx->tx_queued);
LASSERT(!tx->tx_sending);
LASSERT(!tx->tx_waiting);
LASSERT(tx->tx_pool);
kiblnd_unmap_tx(ni, tx);
lntmsg[0] = tx->tx_lntmsg[0]; tx->tx_lntmsg[0] = NULL;
lntmsg[1] = tx->tx_lntmsg[1]; tx->tx_lntmsg[1] = NULL;
rc = tx->tx_status;
if (tx->tx_conn) {
LASSERT(ni == tx->tx_conn->ibc_peer->ibp_ni);
kiblnd_conn_decref(tx->tx_conn);
tx->tx_conn = NULL;
}
tx->tx_nwrq = 0;
tx->tx_status = 0;
kiblnd_pool_free_node(&tx->tx_pool->tpo_pool, &tx->tx_list);
for (i = 0; i < 2; i++) {
if (!lntmsg[i])
continue;
lnet_finalize(ni, lntmsg[i], rc);
}
}
void
kiblnd_txlist_done(lnet_ni_t *ni, struct list_head *txlist, int status)
{
struct kib_tx *tx;
while (!list_empty(txlist)) {
tx = list_entry(txlist->next, struct kib_tx, tx_list);
list_del(&tx->tx_list);
tx->tx_waiting = 0;
tx->tx_status = status;
kiblnd_tx_done(ni, tx);
}
}
static struct kib_tx *
kiblnd_get_idle_tx(lnet_ni_t *ni, lnet_nid_t target)
{
struct kib_net *net = (struct kib_net *)ni->ni_data;
struct list_head *node;
struct kib_tx *tx;
struct kib_tx_poolset *tps;
tps = net->ibn_tx_ps[lnet_cpt_of_nid(target)];
node = kiblnd_pool_alloc_node(&tps->tps_poolset);
if (!node)
return NULL;
tx = list_entry(node, struct kib_tx, tx_list);
LASSERT(!tx->tx_nwrq);
LASSERT(!tx->tx_queued);
LASSERT(!tx->tx_sending);
LASSERT(!tx->tx_waiting);
LASSERT(!tx->tx_status);
LASSERT(!tx->tx_conn);
LASSERT(!tx->tx_lntmsg[0]);
LASSERT(!tx->tx_lntmsg[1]);
LASSERT(!tx->tx_nfrags);
return tx;
}
static void
kiblnd_drop_rx(struct kib_rx *rx)
{
struct kib_conn *conn = rx->rx_conn;
struct kib_sched_info *sched = conn->ibc_sched;
unsigned long flags;
spin_lock_irqsave(&sched->ibs_lock, flags);
LASSERT(conn->ibc_nrx > 0);
conn->ibc_nrx--;
spin_unlock_irqrestore(&sched->ibs_lock, flags);
kiblnd_conn_decref(conn);
}
int
kiblnd_post_rx(struct kib_rx *rx, int credit)
{
struct kib_conn *conn = rx->rx_conn;
struct kib_net *net = conn->ibc_peer->ibp_ni->ni_data;
struct ib_recv_wr *bad_wrq = NULL;
struct ib_mr *mr = conn->ibc_hdev->ibh_mrs;
int rc;
LASSERT(net);
LASSERT(!in_interrupt());
LASSERT(credit == IBLND_POSTRX_NO_CREDIT ||
credit == IBLND_POSTRX_PEER_CREDIT ||
credit == IBLND_POSTRX_RSRVD_CREDIT);
LASSERT(mr);
rx->rx_sge.lkey = mr->lkey;
rx->rx_sge.addr = rx->rx_msgaddr;
rx->rx_sge.length = IBLND_MSG_SIZE;
rx->rx_wrq.next = NULL;
rx->rx_wrq.sg_list = &rx->rx_sge;
rx->rx_wrq.num_sge = 1;
rx->rx_wrq.wr_id = kiblnd_ptr2wreqid(rx, IBLND_WID_RX);
LASSERT(conn->ibc_state >= IBLND_CONN_INIT);
LASSERT(rx->rx_nob >= 0);
if (conn->ibc_state > IBLND_CONN_ESTABLISHED) {
kiblnd_drop_rx(rx);
return 0;
}
rx->rx_nob = -1;
kiblnd_conn_addref(conn);
rc = ib_post_recv(conn->ibc_cmid->qp, &rx->rx_wrq, &bad_wrq);
if (unlikely(rc)) {
CERROR("Can't post rx for %s: %d, bad_wrq: %p\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), rc, bad_wrq);
rx->rx_nob = 0;
}
if (conn->ibc_state < IBLND_CONN_ESTABLISHED)
goto out;
if (unlikely(rc)) {
kiblnd_close_conn(conn, rc);
kiblnd_drop_rx(rx);
goto out;
}
if (credit == IBLND_POSTRX_NO_CREDIT)
goto out;
spin_lock(&conn->ibc_lock);
if (credit == IBLND_POSTRX_PEER_CREDIT)
conn->ibc_outstanding_credits++;
else
conn->ibc_reserved_credits++;
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
out:
kiblnd_conn_decref(conn);
return rc;
}
static struct kib_tx *
kiblnd_find_waiting_tx_locked(struct kib_conn *conn, int txtype, __u64 cookie)
{
struct list_head *tmp;
list_for_each(tmp, &conn->ibc_active_txs) {
struct kib_tx *tx = list_entry(tmp, struct kib_tx, tx_list);
LASSERT(!tx->tx_queued);
LASSERT(tx->tx_sending || tx->tx_waiting);
if (tx->tx_cookie != cookie)
continue;
if (tx->tx_waiting &&
tx->tx_msg->ibm_type == txtype)
return tx;
CWARN("Bad completion: %swaiting, type %x (wanted %x)\n",
tx->tx_waiting ? "" : "NOT ",
tx->tx_msg->ibm_type, txtype);
}
return NULL;
}
static void
kiblnd_handle_completion(struct kib_conn *conn, int txtype, int status, __u64 cookie)
{
struct kib_tx *tx;
lnet_ni_t *ni = conn->ibc_peer->ibp_ni;
int idle;
spin_lock(&conn->ibc_lock);
tx = kiblnd_find_waiting_tx_locked(conn, txtype, cookie);
if (!tx) {
spin_unlock(&conn->ibc_lock);
CWARN("Unmatched completion type %x cookie %#llx from %s\n",
txtype, cookie, libcfs_nid2str(conn->ibc_peer->ibp_nid));
kiblnd_close_conn(conn, -EPROTO);
return;
}
if (!tx->tx_status) {
if (status < 0)
tx->tx_status = status;
else if (txtype == IBLND_MSG_GET_REQ)
lnet_set_reply_msg_len(ni, tx->tx_lntmsg[1], status);
}
tx->tx_waiting = 0;
idle = !tx->tx_queued && !tx->tx_sending;
if (idle)
list_del(&tx->tx_list);
spin_unlock(&conn->ibc_lock);
if (idle)
kiblnd_tx_done(ni, tx);
}
static void
kiblnd_send_completion(struct kib_conn *conn, int type, int status, __u64 cookie)
{
lnet_ni_t *ni = conn->ibc_peer->ibp_ni;
struct kib_tx *tx = kiblnd_get_idle_tx(ni, conn->ibc_peer->ibp_nid);
if (!tx) {
CERROR("Can't get tx for completion %x for %s\n",
type, libcfs_nid2str(conn->ibc_peer->ibp_nid));
return;
}
tx->tx_msg->ibm_u.completion.ibcm_status = status;
tx->tx_msg->ibm_u.completion.ibcm_cookie = cookie;
kiblnd_init_tx_msg(ni, tx, type, sizeof(struct kib_completion_msg));
kiblnd_queue_tx(tx, conn);
}
static void
kiblnd_handle_rx(struct kib_rx *rx)
{
struct kib_msg *msg = rx->rx_msg;
struct kib_conn *conn = rx->rx_conn;
lnet_ni_t *ni = conn->ibc_peer->ibp_ni;
int credits = msg->ibm_credits;
struct kib_tx *tx;
int rc = 0;
int rc2;
int post_credit;
LASSERT(conn->ibc_state >= IBLND_CONN_ESTABLISHED);
CDEBUG(D_NET, "Received %x[%d] from %s\n",
msg->ibm_type, credits,
libcfs_nid2str(conn->ibc_peer->ibp_nid));
if (credits) {
spin_lock(&conn->ibc_lock);
if (conn->ibc_credits + credits >
conn->ibc_queue_depth) {
rc2 = conn->ibc_credits;
spin_unlock(&conn->ibc_lock);
CERROR("Bad credits from %s: %d + %d > %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
rc2, credits, conn->ibc_queue_depth);
kiblnd_close_conn(conn, -EPROTO);
kiblnd_post_rx(rx, IBLND_POSTRX_NO_CREDIT);
return;
}
conn->ibc_credits += credits;
if (msg->ibm_type == IBLND_MSG_NOOP &&
!IBLND_OOB_CAPABLE(conn->ibc_version))
conn->ibc_outstanding_credits++;
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
}
switch (msg->ibm_type) {
default:
CERROR("Bad IBLND message type %x from %s\n",
msg->ibm_type, libcfs_nid2str(conn->ibc_peer->ibp_nid));
post_credit = IBLND_POSTRX_NO_CREDIT;
rc = -EPROTO;
break;
case IBLND_MSG_NOOP:
if (IBLND_OOB_CAPABLE(conn->ibc_version)) {
post_credit = IBLND_POSTRX_NO_CREDIT;
break;
}
if (credits)
post_credit = IBLND_POSTRX_NO_CREDIT;
else
post_credit = IBLND_POSTRX_PEER_CREDIT;
break;
case IBLND_MSG_IMMEDIATE:
post_credit = IBLND_POSTRX_DONT_POST;
rc = lnet_parse(ni, &msg->ibm_u.immediate.ibim_hdr,
msg->ibm_srcnid, rx, 0);
if (rc < 0)
post_credit = IBLND_POSTRX_PEER_CREDIT;
break;
case IBLND_MSG_PUT_REQ:
post_credit = IBLND_POSTRX_DONT_POST;
rc = lnet_parse(ni, &msg->ibm_u.putreq.ibprm_hdr,
msg->ibm_srcnid, rx, 1);
if (rc < 0)
post_credit = IBLND_POSTRX_PEER_CREDIT;
break;
case IBLND_MSG_PUT_NAK:
CWARN("PUT_NACK from %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
post_credit = IBLND_POSTRX_RSRVD_CREDIT;
kiblnd_handle_completion(conn, IBLND_MSG_PUT_REQ,
msg->ibm_u.completion.ibcm_status,
msg->ibm_u.completion.ibcm_cookie);
break;
case IBLND_MSG_PUT_ACK:
post_credit = IBLND_POSTRX_RSRVD_CREDIT;
spin_lock(&conn->ibc_lock);
tx = kiblnd_find_waiting_tx_locked(conn, IBLND_MSG_PUT_REQ,
msg->ibm_u.putack.ibpam_src_cookie);
if (tx)
list_del(&tx->tx_list);
spin_unlock(&conn->ibc_lock);
if (!tx) {
CERROR("Unmatched PUT_ACK from %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
rc = -EPROTO;
break;
}
LASSERT(tx->tx_waiting);
tx->tx_nwrq = 0;
rc2 = kiblnd_init_rdma(conn, tx, IBLND_MSG_PUT_DONE,
kiblnd_rd_size(&msg->ibm_u.putack.ibpam_rd),
&msg->ibm_u.putack.ibpam_rd,
msg->ibm_u.putack.ibpam_dst_cookie);
if (rc2 < 0)
CERROR("Can't setup rdma for PUT to %s: %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), rc2);
spin_lock(&conn->ibc_lock);
tx->tx_waiting = 0;
kiblnd_queue_tx_locked(tx, conn);
spin_unlock(&conn->ibc_lock);
break;
case IBLND_MSG_PUT_DONE:
post_credit = IBLND_POSTRX_PEER_CREDIT;
kiblnd_handle_completion(conn, IBLND_MSG_PUT_ACK,
msg->ibm_u.completion.ibcm_status,
msg->ibm_u.completion.ibcm_cookie);
break;
case IBLND_MSG_GET_REQ:
post_credit = IBLND_POSTRX_DONT_POST;
rc = lnet_parse(ni, &msg->ibm_u.get.ibgm_hdr,
msg->ibm_srcnid, rx, 1);
if (rc < 0)
post_credit = IBLND_POSTRX_PEER_CREDIT;
break;
case IBLND_MSG_GET_DONE:
post_credit = IBLND_POSTRX_RSRVD_CREDIT;
kiblnd_handle_completion(conn, IBLND_MSG_GET_REQ,
msg->ibm_u.completion.ibcm_status,
msg->ibm_u.completion.ibcm_cookie);
break;
}
if (rc < 0)
kiblnd_close_conn(conn, rc);
if (post_credit != IBLND_POSTRX_DONT_POST)
kiblnd_post_rx(rx, post_credit);
}
static void
kiblnd_rx_complete(struct kib_rx *rx, int status, int nob)
{
struct kib_msg *msg = rx->rx_msg;
struct kib_conn *conn = rx->rx_conn;
lnet_ni_t *ni = conn->ibc_peer->ibp_ni;
struct kib_net *net = ni->ni_data;
int rc;
int err = -EIO;
LASSERT(net);
LASSERT(rx->rx_nob < 0);
rx->rx_nob = 0;
if (conn->ibc_state > IBLND_CONN_ESTABLISHED)
goto ignore;
if (status != IB_WC_SUCCESS) {
CNETERR("Rx from %s failed: %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), status);
goto failed;
}
LASSERT(nob >= 0);
rx->rx_nob = nob;
rc = kiblnd_unpack_msg(msg, rx->rx_nob);
if (rc) {
CERROR("Error %d unpacking rx from %s\n",
rc, libcfs_nid2str(conn->ibc_peer->ibp_nid));
goto failed;
}
if (msg->ibm_srcnid != conn->ibc_peer->ibp_nid ||
msg->ibm_dstnid != ni->ni_nid ||
msg->ibm_srcstamp != conn->ibc_incarnation ||
msg->ibm_dststamp != net->ibn_incarnation) {
CERROR("Stale rx from %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
err = -ESTALE;
goto failed;
}
kiblnd_peer_alive(conn->ibc_peer);
if (conn->ibc_state < IBLND_CONN_ESTABLISHED) {
rwlock_t *g_lock = &kiblnd_data.kib_global_lock;
unsigned long flags;
write_lock_irqsave(g_lock, flags);
if (conn->ibc_state < IBLND_CONN_ESTABLISHED) {
list_add_tail(&rx->rx_list, &conn->ibc_early_rxs);
write_unlock_irqrestore(g_lock, flags);
return;
}
write_unlock_irqrestore(g_lock, flags);
}
kiblnd_handle_rx(rx);
return;
failed:
CDEBUG(D_NET, "rx %p conn %p\n", rx, conn);
kiblnd_close_conn(conn, err);
ignore:
kiblnd_drop_rx(rx);
}
static struct page *
kiblnd_kvaddr_to_page(unsigned long vaddr)
{
struct page *page;
if (is_vmalloc_addr((void *)vaddr)) {
page = vmalloc_to_page((void *)vaddr);
LASSERT(page);
return page;
}
#ifdef CONFIG_HIGHMEM
if (vaddr >= PKMAP_BASE &&
vaddr < (PKMAP_BASE + LAST_PKMAP * PAGE_SIZE)) {
CERROR("find page for address in highmem\n");
LBUG();
}
#endif
page = virt_to_page(vaddr);
LASSERT(page);
return page;
}
static int
kiblnd_fmr_map_tx(struct kib_net *net, struct kib_tx *tx, struct kib_rdma_desc *rd, __u32 nob)
{
struct kib_hca_dev *hdev;
struct kib_fmr_poolset *fps;
int cpt;
int rc;
LASSERT(tx->tx_pool);
LASSERT(tx->tx_pool->tpo_pool.po_owner);
hdev = tx->tx_pool->tpo_hdev;
cpt = tx->tx_pool->tpo_pool.po_owner->ps_cpt;
fps = net->ibn_fmr_ps[cpt];
rc = kiblnd_fmr_pool_map(fps, tx, rd, nob, 0, &tx->fmr);
if (rc) {
CERROR("Can't map %u bytes: %d\n", nob, rc);
return rc;
}
rd->rd_key = tx->fmr.fmr_key;
rd->rd_frags[0].rf_addr &= ~hdev->ibh_page_mask;
rd->rd_frags[0].rf_nob = nob;
rd->rd_nfrags = 1;
return 0;
}
static void kiblnd_unmap_tx(lnet_ni_t *ni, struct kib_tx *tx)
{
struct kib_net *net = ni->ni_data;
LASSERT(net);
if (net->ibn_fmr_ps)
kiblnd_fmr_pool_unmap(&tx->fmr, tx->tx_status);
if (tx->tx_nfrags) {
kiblnd_dma_unmap_sg(tx->tx_pool->tpo_hdev->ibh_ibdev,
tx->tx_frags, tx->tx_nfrags, tx->tx_dmadir);
tx->tx_nfrags = 0;
}
}
static int kiblnd_map_tx(lnet_ni_t *ni, struct kib_tx *tx, struct kib_rdma_desc *rd,
int nfrags)
{
struct kib_net *net = ni->ni_data;
struct kib_hca_dev *hdev = net->ibn_dev->ibd_hdev;
struct ib_mr *mr = NULL;
__u32 nob;
int i;
tx->tx_dmadir = (rd != tx->tx_rd) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
tx->tx_nfrags = nfrags;
rd->rd_nfrags = kiblnd_dma_map_sg(hdev->ibh_ibdev, tx->tx_frags,
tx->tx_nfrags, tx->tx_dmadir);
for (i = 0, nob = 0; i < rd->rd_nfrags; i++) {
rd->rd_frags[i].rf_nob = kiblnd_sg_dma_len(
hdev->ibh_ibdev, &tx->tx_frags[i]);
rd->rd_frags[i].rf_addr = kiblnd_sg_dma_address(
hdev->ibh_ibdev, &tx->tx_frags[i]);
nob += rd->rd_frags[i].rf_nob;
}
mr = kiblnd_find_rd_dma_mr(ni, rd, tx->tx_conn ?
tx->tx_conn->ibc_max_frags : -1);
if (mr) {
rd->rd_key = (rd != tx->tx_rd) ? mr->rkey : mr->lkey;
return 0;
}
if (net->ibn_fmr_ps)
return kiblnd_fmr_map_tx(net, tx, rd, nob);
return -EINVAL;
}
static int
kiblnd_setup_rd_iov(lnet_ni_t *ni, struct kib_tx *tx, struct kib_rdma_desc *rd,
unsigned int niov, const struct kvec *iov, int offset, int nob)
{
struct kib_net *net = ni->ni_data;
struct page *page;
struct scatterlist *sg;
unsigned long vaddr;
int fragnob;
int page_offset;
LASSERT(nob > 0);
LASSERT(niov > 0);
LASSERT(net);
while (offset >= iov->iov_len) {
offset -= iov->iov_len;
niov--;
iov++;
LASSERT(niov > 0);
}
sg = tx->tx_frags;
do {
LASSERT(niov > 0);
vaddr = ((unsigned long)iov->iov_base) + offset;
page_offset = vaddr & (PAGE_SIZE - 1);
page = kiblnd_kvaddr_to_page(vaddr);
if (!page) {
CERROR("Can't find page\n");
return -EFAULT;
}
fragnob = min((int)(iov->iov_len - offset), nob);
fragnob = min(fragnob, (int)PAGE_SIZE - page_offset);
sg_set_page(sg, page, fragnob, page_offset);
sg = sg_next(sg);
if (!sg) {
CERROR("lacking enough sg entries to map tx\n");
return -EFAULT;
}
if (offset + fragnob < iov->iov_len) {
offset += fragnob;
} else {
offset = 0;
iov++;
niov--;
}
nob -= fragnob;
} while (nob > 0);
return kiblnd_map_tx(ni, tx, rd, sg - tx->tx_frags);
}
static int
kiblnd_setup_rd_kiov(lnet_ni_t *ni, struct kib_tx *tx, struct kib_rdma_desc *rd,
int nkiov, const lnet_kiov_t *kiov, int offset, int nob)
{
struct kib_net *net = ni->ni_data;
struct scatterlist *sg;
int fragnob;
CDEBUG(D_NET, "niov %d offset %d nob %d\n", nkiov, offset, nob);
LASSERT(nob > 0);
LASSERT(nkiov > 0);
LASSERT(net);
while (offset >= kiov->bv_len) {
offset -= kiov->bv_len;
nkiov--;
kiov++;
LASSERT(nkiov > 0);
}
sg = tx->tx_frags;
do {
LASSERT(nkiov > 0);
fragnob = min((int)(kiov->bv_len - offset), nob);
sg_set_page(sg, kiov->bv_page, fragnob,
kiov->bv_offset + offset);
sg = sg_next(sg);
if (!sg) {
CERROR("lacking enough sg entries to map tx\n");
return -EFAULT;
}
offset = 0;
kiov++;
nkiov--;
nob -= fragnob;
} while (nob > 0);
return kiblnd_map_tx(ni, tx, rd, sg - tx->tx_frags);
}
static int
kiblnd_post_tx_locked(struct kib_conn *conn, struct kib_tx *tx, int credit)
__must_hold(&conn->ibc_lock
static void
kiblnd_check_sends_locked(struct kib_conn *conn)
{
int ver = conn->ibc_version;
lnet_ni_t *ni = conn->ibc_peer->ibp_ni;
struct kib_tx *tx;
if (conn->ibc_state < IBLND_CONN_ESTABLISHED) {
CDEBUG(D_NET, "%s too soon\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
return;
}
LASSERT(conn->ibc_nsends_posted <= kiblnd_concurrent_sends(ver, ni));
LASSERT(!IBLND_OOB_CAPABLE(ver) ||
conn->ibc_noops_posted <= IBLND_OOB_MSGS(ver));
LASSERT(conn->ibc_reserved_credits >= 0);
while (conn->ibc_reserved_credits > 0 &&
!list_empty(&conn->ibc_tx_queue_rsrvd)) {
tx = list_entry(conn->ibc_tx_queue_rsrvd.next,
struct kib_tx, tx_list);
list_del(&tx->tx_list);
list_add_tail(&tx->tx_list, &conn->ibc_tx_queue);
conn->ibc_reserved_credits--;
}
if (kiblnd_need_noop(conn)) {
spin_unlock(&conn->ibc_lock);
tx = kiblnd_get_idle_tx(ni, conn->ibc_peer->ibp_nid);
if (tx)
kiblnd_init_tx_msg(ni, tx, IBLND_MSG_NOOP, 0);
spin_lock(&conn->ibc_lock);
if (tx)
kiblnd_queue_tx_locked(tx, conn);
}
for (;;) {
int credit;
if (!list_empty(&conn->ibc_tx_queue_nocred)) {
credit = 0;
tx = list_entry(conn->ibc_tx_queue_nocred.next,
struct kib_tx, tx_list);
} else if (!list_empty(&conn->ibc_tx_noops)) {
LASSERT(!IBLND_OOB_CAPABLE(ver));
credit = 1;
tx = list_entry(conn->ibc_tx_noops.next,
struct kib_tx, tx_list);
} else if (!list_empty(&conn->ibc_tx_queue)) {
credit = 1;
tx = list_entry(conn->ibc_tx_queue.next,
struct kib_tx, tx_list);
} else {
break;
}
if (kiblnd_post_tx_locked(conn, tx, credit))
break;
}
}
static void
kiblnd_tx_complete(struct kib_tx *tx, int status)
{
int failed = (status != IB_WC_SUCCESS);
struct kib_conn *conn = tx->tx_conn;
int idle;
LASSERT(tx->tx_sending > 0);
if (failed) {
if (conn->ibc_state == IBLND_CONN_ESTABLISHED)
CNETERR("Tx -> %s cookie %#llx sending %d waiting %d: failed %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
tx->tx_cookie, tx->tx_sending, tx->tx_waiting,
status);
kiblnd_close_conn(conn, -EIO);
} else {
kiblnd_peer_alive(conn->ibc_peer);
}
spin_lock(&conn->ibc_lock);
tx->tx_sending--;
conn->ibc_nsends_posted--;
if (tx->tx_msg->ibm_type == IBLND_MSG_NOOP)
conn->ibc_noops_posted--;
if (failed) {
tx->tx_waiting = 0;
tx->tx_status = -EIO;
}
idle = !tx->tx_sending &&
!tx->tx_waiting &&
!tx->tx_queued;
if (idle)
list_del(&tx->tx_list);
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
if (idle)
kiblnd_tx_done(conn->ibc_peer->ibp_ni, tx);
}
static void
kiblnd_init_tx_msg(lnet_ni_t *ni, struct kib_tx *tx, int type, int body_nob)
{
struct kib_hca_dev *hdev = tx->tx_pool->tpo_hdev;
struct ib_sge *sge = &tx->tx_sge[tx->tx_nwrq];
struct ib_rdma_wr *wrq = &tx->tx_wrq[tx->tx_nwrq];
int nob = offsetof(struct kib_msg, ibm_u) + body_nob;
struct ib_mr *mr = hdev->ibh_mrs;
LASSERT(tx->tx_nwrq >= 0);
LASSERT(tx->tx_nwrq < IBLND_MAX_RDMA_FRAGS + 1);
LASSERT(nob <= IBLND_MSG_SIZE);
LASSERT(mr);
kiblnd_init_msg(tx->tx_msg, type, body_nob);
sge->lkey = mr->lkey;
sge->addr = tx->tx_msgaddr;
sge->length = nob;
memset(wrq, 0, sizeof(*wrq));
wrq->wr.next = NULL;
wrq->wr.wr_id = kiblnd_ptr2wreqid(tx, IBLND_WID_TX);
wrq->wr.sg_list = sge;
wrq->wr.num_sge = 1;
wrq->wr.opcode = IB_WR_SEND;
wrq->wr.send_flags = IB_SEND_SIGNALED;
tx->tx_nwrq++;
}
static int
kiblnd_init_rdma(struct kib_conn *conn, struct kib_tx *tx, int type,
int resid, struct kib_rdma_desc *dstrd, __u64 dstcookie)
{
struct kib_msg *ibmsg = tx->tx_msg;
struct kib_rdma_desc *srcrd = tx->tx_rd;
struct ib_sge *sge = &tx->tx_sge[0];
struct ib_rdma_wr *wrq, *next;
int rc = resid;
int srcidx = 0;
int dstidx = 0;
int wrknob;
LASSERT(!in_interrupt());
LASSERT(!tx->tx_nwrq);
LASSERT(type == IBLND_MSG_GET_DONE ||
type == IBLND_MSG_PUT_DONE);
if (kiblnd_rd_size(srcrd) > conn->ibc_max_frags << PAGE_SHIFT) {
CERROR("RDMA is too large for peer %s (%d), src size: %d dst size: %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
conn->ibc_max_frags << PAGE_SHIFT,
kiblnd_rd_size(srcrd), kiblnd_rd_size(dstrd));
rc = -EMSGSIZE;
goto too_big;
}
while (resid > 0) {
if (srcidx >= srcrd->rd_nfrags) {
CERROR("Src buffer exhausted: %d frags\n", srcidx);
rc = -EPROTO;
break;
}
if (dstidx == dstrd->rd_nfrags) {
CERROR("Dst buffer exhausted: %d frags\n", dstidx);
rc = -EPROTO;
break;
}
if (tx->tx_nwrq >= IBLND_MAX_RDMA_FRAGS) {
CERROR("RDMA has too many fragments for peer %s (%d), src idx/frags: %d/%d dst idx/frags: %d/%d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
IBLND_MAX_RDMA_FRAGS,
srcidx, srcrd->rd_nfrags,
dstidx, dstrd->rd_nfrags);
rc = -EMSGSIZE;
break;
}
wrknob = min(min(kiblnd_rd_frag_size(srcrd, srcidx),
kiblnd_rd_frag_size(dstrd, dstidx)),
(__u32)resid);
sge = &tx->tx_sge[tx->tx_nwrq];
sge->addr = kiblnd_rd_frag_addr(srcrd, srcidx);
sge->lkey = kiblnd_rd_frag_key(srcrd, srcidx);
sge->length = wrknob;
wrq = &tx->tx_wrq[tx->tx_nwrq];
next = wrq + 1;
wrq->wr.next = &next->wr;
wrq->wr.wr_id = kiblnd_ptr2wreqid(tx, IBLND_WID_RDMA);
wrq->wr.sg_list = sge;
wrq->wr.num_sge = 1;
wrq->wr.opcode = IB_WR_RDMA_WRITE;
wrq->wr.send_flags = 0;
wrq->remote_addr = kiblnd_rd_frag_addr(dstrd, dstidx);
wrq->rkey = kiblnd_rd_frag_key(dstrd, dstidx);
srcidx = kiblnd_rd_consume_frag(srcrd, srcidx, wrknob);
dstidx = kiblnd_rd_consume_frag(dstrd, dstidx, wrknob);
resid -= wrknob;
tx->tx_nwrq++;
wrq++;
sge++;
}
too_big:
if (rc < 0)
tx->tx_nwrq = 0;
ibmsg->ibm_u.completion.ibcm_status = rc;
ibmsg->ibm_u.completion.ibcm_cookie = dstcookie;
kiblnd_init_tx_msg(conn->ibc_peer->ibp_ni, tx,
type, sizeof(struct kib_completion_msg));
return rc;
}
static void
kiblnd_queue_tx_locked(struct kib_tx *tx, struct kib_conn *conn)
{
struct list_head *q;
LASSERT(tx->tx_nwrq > 0);
LASSERT(!tx->tx_queued);
LASSERT(conn->ibc_state >= IBLND_CONN_ESTABLISHED);
tx->tx_queued = 1;
tx->tx_deadline = jiffies +
msecs_to_jiffies(*kiblnd_tunables.kib_timeout *
MSEC_PER_SEC);
if (!tx->tx_conn) {
kiblnd_conn_addref(conn);
tx->tx_conn = conn;
LASSERT(tx->tx_msg->ibm_type != IBLND_MSG_PUT_DONE);
} else {
LASSERT(tx->tx_conn == conn);
LASSERT(tx->tx_msg->ibm_type == IBLND_MSG_PUT_DONE);
}
switch (tx->tx_msg->ibm_type) {
default:
LBUG();
case IBLND_MSG_PUT_REQ:
case IBLND_MSG_GET_REQ:
q = &conn->ibc_tx_queue_rsrvd;
break;
case IBLND_MSG_PUT_NAK:
case IBLND_MSG_PUT_ACK:
case IBLND_MSG_PUT_DONE:
case IBLND_MSG_GET_DONE:
q = &conn->ibc_tx_queue_nocred;
break;
case IBLND_MSG_NOOP:
if (IBLND_OOB_CAPABLE(conn->ibc_version))
q = &conn->ibc_tx_queue_nocred;
else
q = &conn->ibc_tx_noops;
break;
case IBLND_MSG_IMMEDIATE:
q = &conn->ibc_tx_queue;
break;
}
list_add_tail(&tx->tx_list, q);
}
static void
kiblnd_queue_tx(struct kib_tx *tx, struct kib_conn *conn)
{
spin_lock(&conn->ibc_lock);
kiblnd_queue_tx_locked(tx, conn);
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
}
static int kiblnd_resolve_addr(struct rdma_cm_id *cmid,
struct sockaddr_in *srcaddr,
struct sockaddr_in *dstaddr,
int timeout_ms)
{
unsigned short port;
int rc;
rc = rdma_set_reuseaddr(cmid, 1);
if (rc) {
CERROR("Unable to set reuse on cmid: %d\n", rc);
return rc;
}
for (port = PROT_SOCK - 1; port > 0; port--) {
srcaddr->sin_port = htons(port);
rc = rdma_resolve_addr(cmid,
(struct sockaddr *)srcaddr,
(struct sockaddr *)dstaddr,
timeout_ms);
if (!rc) {
CDEBUG(D_NET, "bound to port %hu\n", port);
return 0;
} else if (rc == -EADDRINUSE || rc == -EADDRNOTAVAIL) {
CDEBUG(D_NET, "bind to port %hu failed: %d\n",
port, rc);
} else {
return rc;
}
}
CERROR("Failed to bind to a free privileged port\n");
return rc;
}
static void
kiblnd_connect_peer(struct kib_peer *peer)
{
struct rdma_cm_id *cmid;
struct kib_dev *dev;
struct kib_net *net = peer->ibp_ni->ni_data;
struct sockaddr_in srcaddr;
struct sockaddr_in dstaddr;
int rc;
LASSERT(net);
LASSERT(peer->ibp_connecting > 0);
LASSERT(!peer->ibp_reconnecting);
cmid = kiblnd_rdma_create_id(kiblnd_cm_callback, peer, RDMA_PS_TCP,
IB_QPT_RC);
if (IS_ERR(cmid)) {
CERROR("Can't create CMID for %s: %ld\n",
libcfs_nid2str(peer->ibp_nid), PTR_ERR(cmid));
rc = PTR_ERR(cmid);
goto failed;
}
dev = net->ibn_dev;
memset(&srcaddr, 0, sizeof(srcaddr));
srcaddr.sin_family = AF_INET;
srcaddr.sin_addr.s_addr = htonl(dev->ibd_ifip);
memset(&dstaddr, 0, sizeof(dstaddr));
dstaddr.sin_family = AF_INET;
dstaddr.sin_port = htons(*kiblnd_tunables.kib_service);
dstaddr.sin_addr.s_addr = htonl(LNET_NIDADDR(peer->ibp_nid));
kiblnd_peer_addref(peer);
if (*kiblnd_tunables.kib_use_priv_port) {
rc = kiblnd_resolve_addr(cmid, &srcaddr, &dstaddr,
*kiblnd_tunables.kib_timeout * 1000);
} else {
rc = rdma_resolve_addr(cmid,
(struct sockaddr *)&srcaddr,
(struct sockaddr *)&dstaddr,
*kiblnd_tunables.kib_timeout * 1000);
}
if (rc) {
CERROR("Can't resolve addr for %s: %d\n",
libcfs_nid2str(peer->ibp_nid), rc);
goto failed2;
}
LASSERT(cmid->device);
CDEBUG(D_NET, "%s: connection bound to %s:%pI4h:%s\n",
libcfs_nid2str(peer->ibp_nid), dev->ibd_ifname,
&dev->ibd_ifip, cmid->device->name);
return;
failed2:
kiblnd_peer_connect_failed(peer, 1, rc);
kiblnd_peer_decref(peer);
rdma_destroy_id(cmid);
return;
failed:
kiblnd_peer_connect_failed(peer, 1, rc);
}
bool
kiblnd_reconnect_peer(struct kib_peer *peer)
{
rwlock_t *glock = &kiblnd_data.kib_global_lock;
char *reason = NULL;
struct list_head txs;
unsigned long flags;
INIT_LIST_HEAD(&txs);
write_lock_irqsave(glock, flags);
if (!peer->ibp_reconnecting) {
if (peer->ibp_accepting)
reason = "accepting";
else if (peer->ibp_connecting)
reason = "connecting";
else if (!list_empty(&peer->ibp_conns))
reason = "connected";
else
reason = "closed";
goto no_reconnect;
}
LASSERT(!peer->ibp_accepting && !peer->ibp_connecting &&
list_empty(&peer->ibp_conns));
peer->ibp_reconnecting = 0;
if (!kiblnd_peer_active(peer)) {
list_splice_init(&peer->ibp_tx_queue, &txs);
reason = "unlinked";
goto no_reconnect;
}
peer->ibp_connecting++;
peer->ibp_reconnected++;
write_unlock_irqrestore(glock, flags);
kiblnd_connect_peer(peer);
return true;
no_reconnect:
write_unlock_irqrestore(glock, flags);
CWARN("Abort reconnection of %s: %s\n",
libcfs_nid2str(peer->ibp_nid), reason);
kiblnd_txlist_done(peer->ibp_ni, &txs, -ECONNABORTED);
return false;
}
void
kiblnd_launch_tx(lnet_ni_t *ni, struct kib_tx *tx, lnet_nid_t nid)
{
struct kib_peer *peer;
struct kib_peer *peer2;
struct kib_conn *conn;
rwlock_t *g_lock = &kiblnd_data.kib_global_lock;
unsigned long flags;
int rc;
LASSERT(!tx || !tx->tx_conn);
LASSERT(!tx || tx->tx_nwrq > 0);
read_lock_irqsave(g_lock, flags);
peer = kiblnd_find_peer_locked(nid);
if (peer && !list_empty(&peer->ibp_conns)) {
conn = kiblnd_get_conn_locked(peer);
kiblnd_conn_addref(conn);
read_unlock_irqrestore(g_lock, flags);
if (tx)
kiblnd_queue_tx(tx, conn);
kiblnd_conn_decref(conn);
return;
}
read_unlock(g_lock);
write_lock(g_lock);
peer = kiblnd_find_peer_locked(nid);
if (peer) {
if (list_empty(&peer->ibp_conns)) {
LASSERT(kiblnd_peer_connecting(peer));
if (tx)
list_add_tail(&tx->tx_list,
&peer->ibp_tx_queue);
write_unlock_irqrestore(g_lock, flags);
} else {
conn = kiblnd_get_conn_locked(peer);
kiblnd_conn_addref(conn);
write_unlock_irqrestore(g_lock, flags);
if (tx)
kiblnd_queue_tx(tx, conn);
kiblnd_conn_decref(conn);
}
return;
}
write_unlock_irqrestore(g_lock, flags);
rc = kiblnd_create_peer(ni, &peer, nid);
if (rc) {
CERROR("Can't create peer %s\n", libcfs_nid2str(nid));
if (tx) {
tx->tx_status = -EHOSTUNREACH;
tx->tx_waiting = 0;
kiblnd_tx_done(ni, tx);
}
return;
}
write_lock_irqsave(g_lock, flags);
peer2 = kiblnd_find_peer_locked(nid);
if (peer2) {
if (list_empty(&peer2->ibp_conns)) {
LASSERT(kiblnd_peer_connecting(peer2));
if (tx)
list_add_tail(&tx->tx_list,
&peer2->ibp_tx_queue);
write_unlock_irqrestore(g_lock, flags);
} else {
conn = kiblnd_get_conn_locked(peer2);
kiblnd_conn_addref(conn);
write_unlock_irqrestore(g_lock, flags);
if (tx)
kiblnd_queue_tx(tx, conn);
kiblnd_conn_decref(conn);
}
kiblnd_peer_decref(peer);
return;
}
LASSERT(!peer->ibp_connecting);
peer->ibp_connecting = 1;
LASSERT(!((struct kib_net *)ni->ni_data)->ibn_shutdown);
if (tx)
list_add_tail(&tx->tx_list, &peer->ibp_tx_queue);
kiblnd_peer_addref(peer);
list_add_tail(&peer->ibp_list, kiblnd_nid2peerlist(nid));
write_unlock_irqrestore(g_lock, flags);
kiblnd_connect_peer(peer);
kiblnd_peer_decref(peer);
}
int
kiblnd_send(lnet_ni_t *ni, void *private, lnet_msg_t *lntmsg)
{
lnet_hdr_t *hdr = &lntmsg->msg_hdr;
int type = lntmsg->msg_type;
lnet_process_id_t target = lntmsg->msg_target;
int target_is_router = lntmsg->msg_target_is_router;
int routing = lntmsg->msg_routing;
unsigned int payload_niov = lntmsg->msg_niov;
struct kvec *payload_iov = lntmsg->msg_iov;
lnet_kiov_t *payload_kiov = lntmsg->msg_kiov;
unsigned int payload_offset = lntmsg->msg_offset;
unsigned int payload_nob = lntmsg->msg_len;
struct iov_iter from;
struct kib_msg *ibmsg;
struct kib_rdma_desc *rd;
struct kib_tx *tx;
int nob;
int rc;
CDEBUG(D_NET, "sending %d bytes in %d frags to %s\n",
payload_nob, payload_niov, libcfs_id2str(target));
LASSERT(!payload_nob || payload_niov > 0);
LASSERT(payload_niov <= LNET_MAX_IOV);
LASSERT(!in_interrupt());
LASSERT(!(payload_kiov && payload_iov));
if (payload_kiov)
iov_iter_bvec(&from, ITER_BVEC | WRITE,
payload_kiov, payload_niov,
payload_nob + payload_offset);
else
iov_iter_kvec(&from, ITER_KVEC | WRITE,
payload_iov, payload_niov,
payload_nob + payload_offset);
iov_iter_advance(&from, payload_offset);
switch (type) {
default:
LBUG();
return -EIO;
case LNET_MSG_ACK:
LASSERT(!payload_nob);
break;
case LNET_MSG_GET:
if (routing || target_is_router)
break;
nob = offsetof(struct kib_msg, ibm_u.immediate.ibim_payload[lntmsg->msg_md->md_length]);
if (nob <= IBLND_MSG_SIZE)
break;
tx = kiblnd_get_idle_tx(ni, target.nid);
if (!tx) {
CERROR("Can't allocate txd for GET to %s\n",
libcfs_nid2str(target.nid));
return -ENOMEM;
}
ibmsg = tx->tx_msg;
rd = &ibmsg->ibm_u.get.ibgm_rd;
if (!(lntmsg->msg_md->md_options & LNET_MD_KIOV))
rc = kiblnd_setup_rd_iov(ni, tx, rd,
lntmsg->msg_md->md_niov,
lntmsg->msg_md->md_iov.iov,
0, lntmsg->msg_md->md_length);
else
rc = kiblnd_setup_rd_kiov(ni, tx, rd,
lntmsg->msg_md->md_niov,
lntmsg->msg_md->md_iov.kiov,
0, lntmsg->msg_md->md_length);
if (rc) {
CERROR("Can't setup GET sink for %s: %d\n",
libcfs_nid2str(target.nid), rc);
kiblnd_tx_done(ni, tx);
return -EIO;
}
nob = offsetof(struct kib_get_msg, ibgm_rd.rd_frags[rd->rd_nfrags]);
ibmsg->ibm_u.get.ibgm_cookie = tx->tx_cookie;
ibmsg->ibm_u.get.ibgm_hdr = *hdr;
kiblnd_init_tx_msg(ni, tx, IBLND_MSG_GET_REQ, nob);
tx->tx_lntmsg[1] = lnet_create_reply_msg(ni, lntmsg);
if (!tx->tx_lntmsg[1]) {
CERROR("Can't create reply for GET -> %s\n",
libcfs_nid2str(target.nid));
kiblnd_tx_done(ni, tx);
return -EIO;
}
tx->tx_lntmsg[0] = lntmsg;
tx->tx_waiting = 1;
kiblnd_launch_tx(ni, tx, target.nid);
return 0;
case LNET_MSG_REPLY:
case LNET_MSG_PUT:
nob = offsetof(struct kib_msg, ibm_u.immediate.ibim_payload[payload_nob]);
if (nob <= IBLND_MSG_SIZE)
break;
tx = kiblnd_get_idle_tx(ni, target.nid);
if (!tx) {
CERROR("Can't allocate %s txd for %s\n",
type == LNET_MSG_PUT ? "PUT" : "REPLY",
libcfs_nid2str(target.nid));
return -ENOMEM;
}
if (!payload_kiov)
rc = kiblnd_setup_rd_iov(ni, tx, tx->tx_rd,
payload_niov, payload_iov,
payload_offset, payload_nob);
else
rc = kiblnd_setup_rd_kiov(ni, tx, tx->tx_rd,
payload_niov, payload_kiov,
payload_offset, payload_nob);
if (rc) {
CERROR("Can't setup PUT src for %s: %d\n",
libcfs_nid2str(target.nid), rc);
kiblnd_tx_done(ni, tx);
return -EIO;
}
ibmsg = tx->tx_msg;
ibmsg->ibm_u.putreq.ibprm_hdr = *hdr;
ibmsg->ibm_u.putreq.ibprm_cookie = tx->tx_cookie;
kiblnd_init_tx_msg(ni, tx, IBLND_MSG_PUT_REQ, sizeof(struct kib_putreq_msg));
tx->tx_lntmsg[0] = lntmsg;
tx->tx_waiting = 1;
kiblnd_launch_tx(ni, tx, target.nid);
return 0;
}
LASSERT(offsetof(struct kib_msg, ibm_u.immediate.ibim_payload[payload_nob])
<= IBLND_MSG_SIZE);
tx = kiblnd_get_idle_tx(ni, target.nid);
if (!tx) {
CERROR("Can't send %d to %s: tx descs exhausted\n",
type, libcfs_nid2str(target.nid));
return -ENOMEM;
}
ibmsg = tx->tx_msg;
ibmsg->ibm_u.immediate.ibim_hdr = *hdr;
copy_from_iter(&ibmsg->ibm_u.immediate.ibim_payload, IBLND_MSG_SIZE,
&from);
nob = offsetof(struct kib_immediate_msg, ibim_payload[payload_nob]);
kiblnd_init_tx_msg(ni, tx, IBLND_MSG_IMMEDIATE, nob);
tx->tx_lntmsg[0] = lntmsg;
kiblnd_launch_tx(ni, tx, target.nid);
return 0;
}
static void
kiblnd_reply(lnet_ni_t *ni, struct kib_rx *rx, lnet_msg_t *lntmsg)
{
lnet_process_id_t target = lntmsg->msg_target;
unsigned int niov = lntmsg->msg_niov;
struct kvec *iov = lntmsg->msg_iov;
lnet_kiov_t *kiov = lntmsg->msg_kiov;
unsigned int offset = lntmsg->msg_offset;
unsigned int nob = lntmsg->msg_len;
struct kib_tx *tx;
int rc;
tx = kiblnd_get_idle_tx(ni, rx->rx_conn->ibc_peer->ibp_nid);
if (!tx) {
CERROR("Can't get tx for REPLY to %s\n",
libcfs_nid2str(target.nid));
goto failed_0;
}
if (!nob)
rc = 0;
else if (!kiov)
rc = kiblnd_setup_rd_iov(ni, tx, tx->tx_rd,
niov, iov, offset, nob);
else
rc = kiblnd_setup_rd_kiov(ni, tx, tx->tx_rd,
niov, kiov, offset, nob);
if (rc) {
CERROR("Can't setup GET src for %s: %d\n",
libcfs_nid2str(target.nid), rc);
goto failed_1;
}
rc = kiblnd_init_rdma(rx->rx_conn, tx,
IBLND_MSG_GET_DONE, nob,
&rx->rx_msg->ibm_u.get.ibgm_rd,
rx->rx_msg->ibm_u.get.ibgm_cookie);
if (rc < 0) {
CERROR("Can't setup rdma for GET from %s: %d\n",
libcfs_nid2str(target.nid), rc);
goto failed_1;
}
if (!nob) {
lnet_finalize(ni, lntmsg, 0);
} else {
tx->tx_lntmsg[0] = lntmsg;
}
kiblnd_queue_tx(tx, rx->rx_conn);
return;
failed_1:
kiblnd_tx_done(ni, tx);
failed_0:
lnet_finalize(ni, lntmsg, -EIO);
}
int
kiblnd_recv(lnet_ni_t *ni, void *private, lnet_msg_t *lntmsg, int delayed,
struct iov_iter *to, unsigned int rlen)
{
struct kib_rx *rx = private;
struct kib_msg *rxmsg = rx->rx_msg;
struct kib_conn *conn = rx->rx_conn;
struct kib_tx *tx;
int nob;
int post_credit = IBLND_POSTRX_PEER_CREDIT;
int rc = 0;
LASSERT(iov_iter_count(to) <= rlen);
LASSERT(!in_interrupt());
switch (rxmsg->ibm_type) {
default:
LBUG();
case IBLND_MSG_IMMEDIATE:
nob = offsetof(struct kib_msg, ibm_u.immediate.ibim_payload[rlen]);
if (nob > rx->rx_nob) {
CERROR("Immediate message from %s too big: %d(%d)\n",
libcfs_nid2str(rxmsg->ibm_u.immediate.ibim_hdr.src_nid),
nob, rx->rx_nob);
rc = -EPROTO;
break;
}
copy_to_iter(&rxmsg->ibm_u.immediate.ibim_payload,
IBLND_MSG_SIZE, to);
lnet_finalize(ni, lntmsg, 0);
break;
case IBLND_MSG_PUT_REQ: {
struct kib_msg *txmsg;
struct kib_rdma_desc *rd;
if (!iov_iter_count(to)) {
lnet_finalize(ni, lntmsg, 0);
kiblnd_send_completion(rx->rx_conn, IBLND_MSG_PUT_NAK, 0,
rxmsg->ibm_u.putreq.ibprm_cookie);
break;
}
tx = kiblnd_get_idle_tx(ni, conn->ibc_peer->ibp_nid);
if (!tx) {
CERROR("Can't allocate tx for %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
rc = -ENOMEM;
break;
}
txmsg = tx->tx_msg;
rd = &txmsg->ibm_u.putack.ibpam_rd;
if (!(to->type & ITER_BVEC))
rc = kiblnd_setup_rd_iov(ni, tx, rd,
to->nr_segs, to->kvec,
to->iov_offset,
iov_iter_count(to));
else
rc = kiblnd_setup_rd_kiov(ni, tx, rd,
to->nr_segs, to->bvec,
to->iov_offset,
iov_iter_count(to));
if (rc) {
CERROR("Can't setup PUT sink for %s: %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), rc);
kiblnd_tx_done(ni, tx);
kiblnd_send_completion(rx->rx_conn, IBLND_MSG_PUT_NAK, rc,
rxmsg->ibm_u.putreq.ibprm_cookie);
break;
}
nob = offsetof(struct kib_putack_msg, ibpam_rd.rd_frags[rd->rd_nfrags]);
txmsg->ibm_u.putack.ibpam_src_cookie = rxmsg->ibm_u.putreq.ibprm_cookie;
txmsg->ibm_u.putack.ibpam_dst_cookie = tx->tx_cookie;
kiblnd_init_tx_msg(ni, tx, IBLND_MSG_PUT_ACK, nob);
tx->tx_lntmsg[0] = lntmsg;
tx->tx_waiting = 1;
kiblnd_queue_tx(tx, conn);
post_credit = IBLND_POSTRX_NO_CREDIT;
break;
}
case IBLND_MSG_GET_REQ:
if (lntmsg) {
kiblnd_reply(ni, rx, lntmsg);
} else {
kiblnd_send_completion(rx->rx_conn, IBLND_MSG_GET_DONE,
-ENODATA,
rxmsg->ibm_u.get.ibgm_cookie);
}
break;
}
kiblnd_post_rx(rx, post_credit);
return rc;
}
int
kiblnd_thread_start(int (*fn)(void *arg), void *arg, char *name)
{
struct task_struct *task = kthread_run(fn, arg, "%s", name);
if (IS_ERR(task))
return PTR_ERR(task);
atomic_inc(&kiblnd_data.kib_nthreads);
return 0;
}
static void
kiblnd_thread_fini(void)
{
atomic_dec(&kiblnd_data.kib_nthreads);
}
static void
kiblnd_peer_alive(struct kib_peer *peer)
{
peer->ibp_last_alive = cfs_time_current();
mb();
}
static void
kiblnd_peer_notify(struct kib_peer *peer)
{
int error = 0;
unsigned long last_alive = 0;
unsigned long flags;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (kiblnd_peer_idle(peer) && peer->ibp_error) {
error = peer->ibp_error;
peer->ibp_error = 0;
last_alive = peer->ibp_last_alive;
}
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
if (error)
lnet_notify(peer->ibp_ni,
peer->ibp_nid, 0, last_alive);
}
void
kiblnd_close_conn_locked(struct kib_conn *conn, int error)
{
struct kib_peer *peer = conn->ibc_peer;
struct kib_dev *dev;
unsigned long flags;
LASSERT(error || conn->ibc_state >= IBLND_CONN_ESTABLISHED);
if (error && !conn->ibc_comms_error)
conn->ibc_comms_error = error;
if (conn->ibc_state != IBLND_CONN_ESTABLISHED)
return;
if (!error &&
list_empty(&conn->ibc_tx_noops) &&
list_empty(&conn->ibc_tx_queue) &&
list_empty(&conn->ibc_tx_queue_rsrvd) &&
list_empty(&conn->ibc_tx_queue_nocred) &&
list_empty(&conn->ibc_active_txs)) {
CDEBUG(D_NET, "closing conn to %s\n",
libcfs_nid2str(peer->ibp_nid));
} else {
CNETERR("Closing conn to %s: error %d%s%s%s%s%s\n",
libcfs_nid2str(peer->ibp_nid), error,
list_empty(&conn->ibc_tx_queue) ? "" : "(sending)",
list_empty(&conn->ibc_tx_noops) ? "" : "(sending_noops)",
list_empty(&conn->ibc_tx_queue_rsrvd) ? "" : "(sending_rsrvd)",
list_empty(&conn->ibc_tx_queue_nocred) ? "" : "(sending_nocred)",
list_empty(&conn->ibc_active_txs) ? "" : "(waiting)");
}
dev = ((struct kib_net *)peer->ibp_ni->ni_data)->ibn_dev;
list_del(&conn->ibc_list);
if (list_empty(&peer->ibp_conns) &&
kiblnd_peer_active(peer)) {
kiblnd_unlink_peer_locked(peer);
peer->ibp_error = conn->ibc_comms_error;
}
kiblnd_set_conn_state(conn, IBLND_CONN_CLOSING);
if (error &&
kiblnd_dev_can_failover(dev)) {
list_add_tail(&dev->ibd_fail_list,
&kiblnd_data.kib_failed_devs);
wake_up(&kiblnd_data.kib_failover_waitq);
}
spin_lock_irqsave(&kiblnd_data.kib_connd_lock, flags);
list_add_tail(&conn->ibc_list, &kiblnd_data.kib_connd_conns);
wake_up(&kiblnd_data.kib_connd_waitq);
spin_unlock_irqrestore(&kiblnd_data.kib_connd_lock, flags);
}
void
kiblnd_close_conn(struct kib_conn *conn, int error)
{
unsigned long flags;
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
kiblnd_close_conn_locked(conn, error);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
}
static void
kiblnd_handle_early_rxs(struct kib_conn *conn)
{
unsigned long flags;
struct kib_rx *rx;
struct kib_rx *tmp;
LASSERT(!in_interrupt());
LASSERT(conn->ibc_state >= IBLND_CONN_ESTABLISHED);
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
list_for_each_entry_safe(rx, tmp, &conn->ibc_early_rxs, rx_list) {
list_del(&rx->rx_list);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
kiblnd_handle_rx(rx);
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
}
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
}
static void
kiblnd_abort_txs(struct kib_conn *conn, struct list_head *txs)
{
LIST_HEAD(zombies);
struct list_head *tmp;
struct list_head *nxt;
struct kib_tx *tx;
spin_lock(&conn->ibc_lock);
list_for_each_safe(tmp, nxt, txs) {
tx = list_entry(tmp, struct kib_tx, tx_list);
if (txs == &conn->ibc_active_txs) {
LASSERT(!tx->tx_queued);
LASSERT(tx->tx_waiting || tx->tx_sending);
} else {
LASSERT(tx->tx_queued);
}
tx->tx_status = -ECONNABORTED;
tx->tx_waiting = 0;
if (!tx->tx_sending) {
tx->tx_queued = 0;
list_del(&tx->tx_list);
list_add(&tx->tx_list, &zombies);
}
}
spin_unlock(&conn->ibc_lock);
kiblnd_txlist_done(conn->ibc_peer->ibp_ni, &zombies, -ECONNABORTED);
}
static void
kiblnd_finalise_conn(struct kib_conn *conn)
{
LASSERT(!in_interrupt());
LASSERT(conn->ibc_state > IBLND_CONN_INIT);
kiblnd_set_conn_state(conn, IBLND_CONN_DISCONNECTED);
kiblnd_abort_receives(conn);
kiblnd_abort_txs(conn, &conn->ibc_tx_noops);
kiblnd_abort_txs(conn, &conn->ibc_tx_queue);
kiblnd_abort_txs(conn, &conn->ibc_tx_queue_rsrvd);
kiblnd_abort_txs(conn, &conn->ibc_tx_queue_nocred);
kiblnd_abort_txs(conn, &conn->ibc_active_txs);
kiblnd_handle_early_rxs(conn);
}
static void
kiblnd_peer_connect_failed(struct kib_peer *peer, int active, int error)
{
LIST_HEAD(zombies);
unsigned long flags;
LASSERT(error);
LASSERT(!in_interrupt());
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (active) {
LASSERT(peer->ibp_connecting > 0);
peer->ibp_connecting--;
} else {
LASSERT(peer->ibp_accepting > 0);
peer->ibp_accepting--;
}
if (kiblnd_peer_connecting(peer)) {
write_unlock_irqrestore(&kiblnd_data.kib_global_lock,
flags);
return;
}
peer->ibp_reconnected = 0;
if (list_empty(&peer->ibp_conns)) {
list_add(&zombies, &peer->ibp_tx_queue);
list_del_init(&peer->ibp_tx_queue);
if (kiblnd_peer_active(peer))
kiblnd_unlink_peer_locked(peer);
peer->ibp_error = error;
} else {
LASSERT(list_empty(&peer->ibp_tx_queue));
}
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
kiblnd_peer_notify(peer);
if (list_empty(&zombies))
return;
CNETERR("Deleting messages for %s: connection failed\n",
libcfs_nid2str(peer->ibp_nid));
kiblnd_txlist_done(peer->ibp_ni, &zombies, -EHOSTUNREACH);
}
static void
kiblnd_connreq_done(struct kib_conn *conn, int status)
{
struct kib_peer *peer = conn->ibc_peer;
struct kib_tx *tx;
struct kib_tx *tmp;
struct list_head txs;
unsigned long flags;
int active;
active = (conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT);
CDEBUG(D_NET, "%s: active(%d), version(%x), status(%d)\n",
libcfs_nid2str(peer->ibp_nid), active,
conn->ibc_version, status);
LASSERT(!in_interrupt());
LASSERT((conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT &&
peer->ibp_connecting > 0) ||
(conn->ibc_state == IBLND_CONN_PASSIVE_WAIT &&
peer->ibp_accepting > 0));
LIBCFS_FREE(conn->ibc_connvars, sizeof(*conn->ibc_connvars));
conn->ibc_connvars = NULL;
if (status) {
kiblnd_peer_connect_failed(peer, active, status);
kiblnd_finalise_conn(conn);
return;
}
write_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
conn->ibc_last_send = jiffies;
kiblnd_set_conn_state(conn, IBLND_CONN_ESTABLISHED);
kiblnd_peer_alive(peer);
kiblnd_conn_addref(conn);
list_add(&conn->ibc_list, &peer->ibp_conns);
peer->ibp_reconnected = 0;
if (active)
peer->ibp_connecting--;
else
peer->ibp_accepting--;
if (!peer->ibp_version) {
peer->ibp_version = conn->ibc_version;
peer->ibp_incarnation = conn->ibc_incarnation;
}
if (peer->ibp_version != conn->ibc_version ||
peer->ibp_incarnation != conn->ibc_incarnation) {
kiblnd_close_stale_conns_locked(peer, conn->ibc_version,
conn->ibc_incarnation);
peer->ibp_version = conn->ibc_version;
peer->ibp_incarnation = conn->ibc_incarnation;
}
list_add(&txs, &peer->ibp_tx_queue);
list_del_init(&peer->ibp_tx_queue);
if (!kiblnd_peer_active(peer) ||
conn->ibc_comms_error) {
lnet_ni_t *ni = peer->ibp_ni;
kiblnd_close_conn_locked(conn, -ECONNABORTED);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
kiblnd_txlist_done(ni, &txs, -ECONNABORTED);
return;
}
kiblnd_conn_addref(conn);
write_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
spin_lock(&conn->ibc_lock);
list_for_each_entry_safe(tx, tmp, &txs, tx_list) {
list_del(&tx->tx_list);
kiblnd_queue_tx_locked(tx, conn);
}
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
kiblnd_handle_early_rxs(conn);
kiblnd_conn_decref(conn);
}
static void
kiblnd_reject(struct rdma_cm_id *cmid, struct kib_rej *rej)
{
int rc;
rc = rdma_reject(cmid, rej, sizeof(*rej));
if (rc)
CWARN("Error %d sending reject\n", rc);
}
static int
kiblnd_passive_connect(struct rdma_cm_id *cmid, void *priv, int priv_nob)
{
rwlock_t *g_lock = &kiblnd_data.kib_global_lock;
struct kib_msg *reqmsg = priv;
struct kib_msg *ackmsg;
struct kib_dev *ibdev;
struct kib_peer *peer;
struct kib_peer *peer2;
struct kib_conn *conn;
lnet_ni_t *ni = NULL;
struct kib_net *net = NULL;
lnet_nid_t nid;
struct rdma_conn_param cp;
struct kib_rej rej;
int version = IBLND_MSG_VERSION;
unsigned long flags;
int max_frags;
int rc;
struct sockaddr_in *peer_addr;
LASSERT(!in_interrupt());
ibdev = (struct kib_dev *)cmid->context;
LASSERT(ibdev);
memset(&rej, 0, sizeof(rej));
rej.ibr_magic = IBLND_MSG_MAGIC;
rej.ibr_why = IBLND_REJECT_FATAL;
rej.ibr_cp.ibcp_max_msg_size = IBLND_MSG_SIZE;
peer_addr = (struct sockaddr_in *)&cmid->route.addr.dst_addr;
if (*kiblnd_tunables.kib_require_priv_port &&
ntohs(peer_addr->sin_port) >= PROT_SOCK) {
__u32 ip = ntohl(peer_addr->sin_addr.s_addr);
CERROR("Peer's port (%pI4h:%hu) is not privileged\n",
&ip, ntohs(peer_addr->sin_port));
goto failed;
}
if (priv_nob < offsetof(struct kib_msg, ibm_type)) {
CERROR("Short connection request\n");
goto failed;
}
if (reqmsg->ibm_magic == LNET_PROTO_MAGIC ||
reqmsg->ibm_magic == __swab32(LNET_PROTO_MAGIC))
goto failed;
if (reqmsg->ibm_magic == IBLND_MSG_MAGIC &&
reqmsg->ibm_version != IBLND_MSG_VERSION &&
reqmsg->ibm_version != IBLND_MSG_VERSION_1)
goto failed;
if (reqmsg->ibm_magic == __swab32(IBLND_MSG_MAGIC) &&
reqmsg->ibm_version != __swab16(IBLND_MSG_VERSION) &&
reqmsg->ibm_version != __swab16(IBLND_MSG_VERSION_1))
goto failed;
rc = kiblnd_unpack_msg(reqmsg, priv_nob);
if (rc) {
CERROR("Can't parse connection request: %d\n", rc);
goto failed;
}
nid = reqmsg->ibm_srcnid;
ni = lnet_net2ni(LNET_NIDNET(reqmsg->ibm_dstnid));
if (ni) {
net = (struct kib_net *)ni->ni_data;
rej.ibr_incarnation = net->ibn_incarnation;
}
if (!ni ||
ni->ni_nid != reqmsg->ibm_dstnid ||
net->ibn_dev != ibdev) {
CERROR("Can't accept conn from %s on %s (%s:%d:%pI4h): bad dst nid %s\n",
libcfs_nid2str(nid),
!ni ? "NA" : libcfs_nid2str(ni->ni_nid),
ibdev->ibd_ifname, ibdev->ibd_nnets,
&ibdev->ibd_ifip,
libcfs_nid2str(reqmsg->ibm_dstnid));
goto failed;
}
if (reqmsg->ibm_dststamp &&
reqmsg->ibm_dststamp != net->ibn_incarnation) {
CWARN("Stale connection request\n");
rej.ibr_why = IBLND_REJECT_CONN_STALE;
goto failed;
}
version = reqmsg->ibm_version;
if (reqmsg->ibm_type != IBLND_MSG_CONNREQ) {
CERROR("Unexpected connreq msg type: %x from %s\n",
reqmsg->ibm_type, libcfs_nid2str(nid));
goto failed;
}
if (reqmsg->ibm_u.connparams.ibcp_queue_depth >
kiblnd_msg_queue_size(version, ni)) {
CERROR("Can't accept conn from %s, queue depth too large: %d (<=%d wanted)\n",
libcfs_nid2str(nid),
reqmsg->ibm_u.connparams.ibcp_queue_depth,
kiblnd_msg_queue_size(version, ni));
if (version == IBLND_MSG_VERSION)
rej.ibr_why = IBLND_REJECT_MSG_QUEUE_SIZE;
goto failed;
}
max_frags = reqmsg->ibm_u.connparams.ibcp_max_frags >> IBLND_FRAG_SHIFT;
if (max_frags > kiblnd_rdma_frags(version, ni)) {
CWARN("Can't accept conn from %s (version %x): max message size %d is too large (%d wanted)\n",
libcfs_nid2str(nid), version, max_frags,
kiblnd_rdma_frags(version, ni));
if (version >= IBLND_MSG_VERSION)
rej.ibr_why = IBLND_REJECT_RDMA_FRAGS;
goto failed;
} else if (max_frags < kiblnd_rdma_frags(version, ni) &&
!net->ibn_fmr_ps) {
CWARN("Can't accept conn from %s (version %x): max message size %d incompatible without FMR pool (%d wanted)\n",
libcfs_nid2str(nid), version, max_frags,
kiblnd_rdma_frags(version, ni));
if (version == IBLND_MSG_VERSION)
rej.ibr_why = IBLND_REJECT_RDMA_FRAGS;
goto failed;
}
if (reqmsg->ibm_u.connparams.ibcp_max_msg_size > IBLND_MSG_SIZE) {
CERROR("Can't accept %s: message size %d too big (%d max)\n",
libcfs_nid2str(nid),
reqmsg->ibm_u.connparams.ibcp_max_msg_size,
IBLND_MSG_SIZE);
goto failed;
}
rc = kiblnd_create_peer(ni, &peer, nid);
if (rc) {
CERROR("Can't create peer for %s\n", libcfs_nid2str(nid));
rej.ibr_why = IBLND_REJECT_NO_RESOURCES;
goto failed;
}
peer->ibp_max_frags = max_frags;
peer->ibp_queue_depth = reqmsg->ibm_u.connparams.ibcp_queue_depth;
write_lock_irqsave(g_lock, flags);
peer2 = kiblnd_find_peer_locked(nid);
if (peer2) {
if (!peer2->ibp_version) {
peer2->ibp_version = version;
peer2->ibp_incarnation = reqmsg->ibm_srcstamp;
}
if (peer2->ibp_incarnation != reqmsg->ibm_srcstamp ||
peer2->ibp_version != version) {
kiblnd_close_peer_conns_locked(peer2, -ESTALE);
if (kiblnd_peer_active(peer2)) {
peer2->ibp_incarnation = reqmsg->ibm_srcstamp;
peer2->ibp_version = version;
}
write_unlock_irqrestore(g_lock, flags);
CWARN("Conn stale %s version %x/%x incarnation %llu/%llu\n",
libcfs_nid2str(nid), peer2->ibp_version, version,
peer2->ibp_incarnation, reqmsg->ibm_srcstamp);
kiblnd_peer_decref(peer);
rej.ibr_why = IBLND_REJECT_CONN_STALE;
goto failed;
}
if (peer2->ibp_connecting &&
nid < ni->ni_nid && peer2->ibp_races <
MAX_CONN_RACES_BEFORE_ABORT) {
peer2->ibp_races++;
write_unlock_irqrestore(g_lock, flags);
CDEBUG(D_NET, "Conn race %s\n",
libcfs_nid2str(peer2->ibp_nid));
kiblnd_peer_decref(peer);
rej.ibr_why = IBLND_REJECT_CONN_RACE;
goto failed;
}
if (peer2->ibp_races >= MAX_CONN_RACES_BEFORE_ABORT)
CNETERR("Conn race %s: unresolved after %d attempts, letting lower NID win\n",
libcfs_nid2str(peer2->ibp_nid),
MAX_CONN_RACES_BEFORE_ABORT);
peer2->ibp_reconnecting = 0;
peer2->ibp_races = 0;
peer2->ibp_accepting++;
kiblnd_peer_addref(peer2);
peer2->ibp_max_frags = peer->ibp_max_frags;
peer2->ibp_queue_depth = peer->ibp_queue_depth;
write_unlock_irqrestore(g_lock, flags);
kiblnd_peer_decref(peer);
peer = peer2;
} else {
LASSERT(!peer->ibp_accepting);
LASSERT(!peer->ibp_version &&
!peer->ibp_incarnation);
peer->ibp_accepting = 1;
peer->ibp_version = version;
peer->ibp_incarnation = reqmsg->ibm_srcstamp;
LASSERT(!net->ibn_shutdown);
kiblnd_peer_addref(peer);
list_add_tail(&peer->ibp_list, kiblnd_nid2peerlist(nid));
write_unlock_irqrestore(g_lock, flags);
}
conn = kiblnd_create_conn(peer, cmid, IBLND_CONN_PASSIVE_WAIT,
version);
if (!conn) {
kiblnd_peer_connect_failed(peer, 0, -ENOMEM);
kiblnd_peer_decref(peer);
rej.ibr_why = IBLND_REJECT_NO_RESOURCES;
goto failed;
}
conn->ibc_incarnation = reqmsg->ibm_srcstamp;
conn->ibc_credits = conn->ibc_queue_depth;
conn->ibc_reserved_credits = conn->ibc_queue_depth;
LASSERT(conn->ibc_credits + conn->ibc_reserved_credits +
IBLND_OOB_MSGS(version) <= IBLND_RX_MSGS(conn));
ackmsg = &conn->ibc_connvars->cv_msg;
memset(ackmsg, 0, sizeof(*ackmsg));
kiblnd_init_msg(ackmsg, IBLND_MSG_CONNACK,
sizeof(ackmsg->ibm_u.connparams));
ackmsg->ibm_u.connparams.ibcp_queue_depth = conn->ibc_queue_depth;
ackmsg->ibm_u.connparams.ibcp_max_frags = conn->ibc_max_frags << IBLND_FRAG_SHIFT;
ackmsg->ibm_u.connparams.ibcp_max_msg_size = IBLND_MSG_SIZE;
kiblnd_pack_msg(ni, ackmsg, version, 0, nid, reqmsg->ibm_srcstamp);
memset(&cp, 0, sizeof(cp));
cp.private_data = ackmsg;
cp.private_data_len = ackmsg->ibm_nob;
cp.responder_resources = 0;
cp.initiator_depth = 0;
cp.flow_control = 1;
cp.retry_count = *kiblnd_tunables.kib_retry_count;
cp.rnr_retry_count = *kiblnd_tunables.kib_rnr_retry_count;
CDEBUG(D_NET, "Accept %s\n", libcfs_nid2str(nid));
rc = rdma_accept(cmid, &cp);
if (rc) {
CERROR("Can't accept %s: %d\n", libcfs_nid2str(nid), rc);
rej.ibr_version = version;
rej.ibr_why = IBLND_REJECT_FATAL;
kiblnd_reject(cmid, &rej);
kiblnd_connreq_done(conn, rc);
kiblnd_conn_decref(conn);
}
lnet_ni_decref(ni);
return 0;
failed:
if (ni) {
rej.ibr_cp.ibcp_queue_depth = kiblnd_msg_queue_size(version, ni);
rej.ibr_cp.ibcp_max_frags = kiblnd_rdma_frags(version, ni);
lnet_ni_decref(ni);
}
rej.ibr_version = version;
kiblnd_reject(cmid, &rej);
return -ECONNREFUSED;
}
static void
kiblnd_check_reconnect(struct kib_conn *conn, int version,
__u64 incarnation, int why, struct kib_connparams *cp)
{
rwlock_t *glock = &kiblnd_data.kib_global_lock;
struct kib_peer *peer = conn->ibc_peer;
char *reason;
int msg_size = IBLND_MSG_SIZE;
int frag_num = -1;
int queue_dep = -1;
bool reconnect;
unsigned long flags;
LASSERT(conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT);
LASSERT(peer->ibp_connecting > 0);
LASSERT(!peer->ibp_reconnecting);
if (cp) {
msg_size = cp->ibcp_max_msg_size;
frag_num = cp->ibcp_max_frags << IBLND_FRAG_SHIFT;
queue_dep = cp->ibcp_queue_depth;
}
write_lock_irqsave(glock, flags);
reconnect = (!list_empty(&peer->ibp_tx_queue) ||
peer->ibp_version != version) &&
peer->ibp_connecting == 1 &&
!peer->ibp_accepting;
if (!reconnect) {
reason = "no need";
goto out;
}
switch (why) {
default:
reason = "Unknown";
break;
case IBLND_REJECT_RDMA_FRAGS: {
struct lnet_ioctl_config_lnd_tunables *tunables;
if (!cp) {
reason = "can't negotiate max frags";
goto out;
}
tunables = peer->ibp_ni->ni_lnd_tunables;
if (!tunables->lt_tun_u.lt_o2ib.lnd_map_on_demand) {
reason = "map_on_demand must be enabled";
goto out;
}
if (conn->ibc_max_frags <= frag_num) {
reason = "unsupported max frags";
goto out;
}
peer->ibp_max_frags = frag_num;
reason = "rdma fragments";
break;
}
case IBLND_REJECT_MSG_QUEUE_SIZE:
if (!cp) {
reason = "can't negotiate queue depth";
goto out;
}
if (conn->ibc_queue_depth <= queue_dep) {
reason = "unsupported queue depth";
goto out;
}
peer->ibp_queue_depth = queue_dep;
reason = "queue depth";
break;
case IBLND_REJECT_CONN_STALE:
reason = "stale";
break;
case IBLND_REJECT_CONN_RACE:
reason = "conn race";
break;
case IBLND_REJECT_CONN_UNCOMPAT:
reason = "version negotiation";
break;
}
conn->ibc_reconnect = 1;
peer->ibp_reconnecting = 1;
peer->ibp_version = version;
if (incarnation)
peer->ibp_incarnation = incarnation;
out:
write_unlock_irqrestore(glock, flags);
CNETERR("%s: %s (%s), %x, %x, msg_size: %d, queue_depth: %d/%d, max_frags: %d/%d\n",
libcfs_nid2str(peer->ibp_nid),
reconnect ? "reconnect" : "don't reconnect",
reason, IBLND_MSG_VERSION, version, msg_size,
conn->ibc_queue_depth, queue_dep,
conn->ibc_max_frags, frag_num);
}
static void
kiblnd_rejected(struct kib_conn *conn, int reason, void *priv, int priv_nob)
{
struct kib_peer *peer = conn->ibc_peer;
LASSERT(!in_interrupt());
LASSERT(conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT);
switch (reason) {
case IB_CM_REJ_STALE_CONN:
kiblnd_check_reconnect(conn, IBLND_MSG_VERSION, 0,
IBLND_REJECT_CONN_STALE, NULL);
break;
case IB_CM_REJ_INVALID_SERVICE_ID:
CNETERR("%s rejected: no listener at %d\n",
libcfs_nid2str(peer->ibp_nid),
*kiblnd_tunables.kib_service);
break;
case IB_CM_REJ_CONSUMER_DEFINED:
if (priv_nob >= offsetof(struct kib_rej, ibr_padding)) {
struct kib_rej *rej = priv;
struct kib_connparams *cp = NULL;
int flip = 0;
__u64 incarnation = -1;
if (rej->ibr_magic == __swab32(IBLND_MSG_MAGIC) ||
rej->ibr_magic == __swab32(LNET_PROTO_MAGIC)) {
__swab32s(&rej->ibr_magic);
__swab16s(&rej->ibr_version);
flip = 1;
}
if (priv_nob >= sizeof(struct kib_rej) &&
rej->ibr_version > IBLND_MSG_VERSION_1) {
cp = &rej->ibr_cp;
if (flip) {
__swab64s(&rej->ibr_incarnation);
__swab16s(&cp->ibcp_queue_depth);
__swab16s(&cp->ibcp_max_frags);
__swab32s(&cp->ibcp_max_msg_size);
}
incarnation = rej->ibr_incarnation;
}
if (rej->ibr_magic != IBLND_MSG_MAGIC &&
rej->ibr_magic != LNET_PROTO_MAGIC) {
CERROR("%s rejected: consumer defined fatal error\n",
libcfs_nid2str(peer->ibp_nid));
break;
}
if (rej->ibr_version != IBLND_MSG_VERSION &&
rej->ibr_version != IBLND_MSG_VERSION_1) {
CERROR("%s rejected: o2iblnd version %x error\n",
libcfs_nid2str(peer->ibp_nid),
rej->ibr_version);
break;
}
if (rej->ibr_why == IBLND_REJECT_FATAL &&
rej->ibr_version == IBLND_MSG_VERSION_1) {
CDEBUG(D_NET, "rejected by old version peer %s: %x\n",
libcfs_nid2str(peer->ibp_nid), rej->ibr_version);
if (conn->ibc_version != IBLND_MSG_VERSION_1)
rej->ibr_why = IBLND_REJECT_CONN_UNCOMPAT;
}
switch (rej->ibr_why) {
case IBLND_REJECT_CONN_RACE:
case IBLND_REJECT_CONN_STALE:
case IBLND_REJECT_CONN_UNCOMPAT:
case IBLND_REJECT_MSG_QUEUE_SIZE:
case IBLND_REJECT_RDMA_FRAGS:
kiblnd_check_reconnect(conn, rej->ibr_version,
incarnation,
rej->ibr_why, cp);
break;
case IBLND_REJECT_NO_RESOURCES:
CERROR("%s rejected: o2iblnd no resources\n",
libcfs_nid2str(peer->ibp_nid));
break;
case IBLND_REJECT_FATAL:
CERROR("%s rejected: o2iblnd fatal error\n",
libcfs_nid2str(peer->ibp_nid));
break;
default:
CERROR("%s rejected: o2iblnd reason %d\n",
libcfs_nid2str(peer->ibp_nid),
rej->ibr_why);
break;
}
break;
}
default:
CNETERR("%s rejected: reason %d, size %d\n",
libcfs_nid2str(peer->ibp_nid), reason, priv_nob);
break;
}
kiblnd_connreq_done(conn, -ECONNREFUSED);
}
static void
kiblnd_check_connreply(struct kib_conn *conn, void *priv, int priv_nob)
{
struct kib_peer *peer = conn->ibc_peer;
lnet_ni_t *ni = peer->ibp_ni;
struct kib_net *net = ni->ni_data;
struct kib_msg *msg = priv;
int ver = conn->ibc_version;
int rc = kiblnd_unpack_msg(msg, priv_nob);
unsigned long flags;
LASSERT(net);
if (rc) {
CERROR("Can't unpack connack from %s: %d\n",
libcfs_nid2str(peer->ibp_nid), rc);
goto failed;
}
if (msg->ibm_type != IBLND_MSG_CONNACK) {
CERROR("Unexpected message %d from %s\n",
msg->ibm_type, libcfs_nid2str(peer->ibp_nid));
rc = -EPROTO;
goto failed;
}
if (ver != msg->ibm_version) {
CERROR("%s replied version %x is different with requested version %x\n",
libcfs_nid2str(peer->ibp_nid), msg->ibm_version, ver);
rc = -EPROTO;
goto failed;
}
if (msg->ibm_u.connparams.ibcp_queue_depth >
conn->ibc_queue_depth) {
CERROR("%s has incompatible queue depth %d (<=%d wanted)\n",
libcfs_nid2str(peer->ibp_nid),
msg->ibm_u.connparams.ibcp_queue_depth,
conn->ibc_queue_depth);
rc = -EPROTO;
goto failed;
}
if ((msg->ibm_u.connparams.ibcp_max_frags >> IBLND_FRAG_SHIFT) >
conn->ibc_max_frags) {
CERROR("%s has incompatible max_frags %d (<=%d wanted)\n",
libcfs_nid2str(peer->ibp_nid),
msg->ibm_u.connparams.ibcp_max_frags >> IBLND_FRAG_SHIFT,
conn->ibc_max_frags);
rc = -EPROTO;
goto failed;
}
if (msg->ibm_u.connparams.ibcp_max_msg_size > IBLND_MSG_SIZE) {
CERROR("%s max message size %d too big (%d max)\n",
libcfs_nid2str(peer->ibp_nid),
msg->ibm_u.connparams.ibcp_max_msg_size,
IBLND_MSG_SIZE);
rc = -EPROTO;
goto failed;
}
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
if (msg->ibm_dstnid == ni->ni_nid &&
msg->ibm_dststamp == net->ibn_incarnation)
rc = 0;
else
rc = -ESTALE;
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
if (rc) {
CERROR("Bad connection reply from %s, rc = %d, version: %x max_frags: %d\n",
libcfs_nid2str(peer->ibp_nid), rc,
msg->ibm_version, msg->ibm_u.connparams.ibcp_max_frags);
goto failed;
}
conn->ibc_incarnation = msg->ibm_srcstamp;
conn->ibc_credits = msg->ibm_u.connparams.ibcp_queue_depth;
conn->ibc_reserved_credits = msg->ibm_u.connparams.ibcp_queue_depth;
conn->ibc_queue_depth = msg->ibm_u.connparams.ibcp_queue_depth;
conn->ibc_max_frags = msg->ibm_u.connparams.ibcp_max_frags >> IBLND_FRAG_SHIFT;
LASSERT(conn->ibc_credits + conn->ibc_reserved_credits +
IBLND_OOB_MSGS(ver) <= IBLND_RX_MSGS(conn));
kiblnd_connreq_done(conn, 0);
return;
failed:
LASSERT(rc);
conn->ibc_comms_error = rc;
kiblnd_connreq_done(conn, 0);
}
static int
kiblnd_active_connect(struct rdma_cm_id *cmid)
{
struct kib_peer *peer = (struct kib_peer *)cmid->context;
struct kib_conn *conn;
struct kib_msg *msg;
struct rdma_conn_param cp;
int version;
__u64 incarnation;
unsigned long flags;
int rc;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
incarnation = peer->ibp_incarnation;
version = !peer->ibp_version ? IBLND_MSG_VERSION :
peer->ibp_version;
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
conn = kiblnd_create_conn(peer, cmid, IBLND_CONN_ACTIVE_CONNECT,
version);
if (!conn) {
kiblnd_peer_connect_failed(peer, 1, -ENOMEM);
kiblnd_peer_decref(peer);
return -ENOMEM;
}
msg = &conn->ibc_connvars->cv_msg;
memset(msg, 0, sizeof(*msg));
kiblnd_init_msg(msg, IBLND_MSG_CONNREQ, sizeof(msg->ibm_u.connparams));
msg->ibm_u.connparams.ibcp_queue_depth = conn->ibc_queue_depth;
msg->ibm_u.connparams.ibcp_max_frags = conn->ibc_max_frags << IBLND_FRAG_SHIFT;
msg->ibm_u.connparams.ibcp_max_msg_size = IBLND_MSG_SIZE;
kiblnd_pack_msg(peer->ibp_ni, msg, version,
0, peer->ibp_nid, incarnation);
memset(&cp, 0, sizeof(cp));
cp.private_data = msg;
cp.private_data_len = msg->ibm_nob;
cp.responder_resources = 0;
cp.initiator_depth = 0;
cp.flow_control = 1;
cp.retry_count = *kiblnd_tunables.kib_retry_count;
cp.rnr_retry_count = *kiblnd_tunables.kib_rnr_retry_count;
LASSERT(cmid->context == (void *)conn);
LASSERT(conn->ibc_cmid == cmid);
rc = rdma_connect(cmid, &cp);
if (rc) {
CERROR("Can't connect to %s: %d\n",
libcfs_nid2str(peer->ibp_nid), rc);
kiblnd_connreq_done(conn, rc);
kiblnd_conn_decref(conn);
}
return 0;
}
int
kiblnd_cm_callback(struct rdma_cm_id *cmid, struct rdma_cm_event *event)
{
struct kib_peer *peer;
struct kib_conn *conn;
int rc;
switch (event->event) {
default:
CERROR("Unexpected event: %d, status: %d\n",
event->event, event->status);
LBUG();
case RDMA_CM_EVENT_CONNECT_REQUEST:
rc = kiblnd_passive_connect(cmid,
(void *)KIBLND_CONN_PARAM(event),
KIBLND_CONN_PARAM_LEN(event));
CDEBUG(D_NET, "connreq: %d\n", rc);
return rc;
case RDMA_CM_EVENT_ADDR_ERROR:
peer = (struct kib_peer *)cmid->context;
CNETERR("%s: ADDR ERROR %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
kiblnd_peer_connect_failed(peer, 1, -EHOSTUNREACH);
kiblnd_peer_decref(peer);
return -EHOSTUNREACH;
case RDMA_CM_EVENT_ADDR_RESOLVED:
peer = (struct kib_peer *)cmid->context;
CDEBUG(D_NET, "%s Addr resolved: %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
if (event->status) {
CNETERR("Can't resolve address for %s: %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
rc = event->status;
} else {
rc = rdma_resolve_route(
cmid, *kiblnd_tunables.kib_timeout * 1000);
if (!rc)
return 0;
CERROR("Can't resolve route for %s: %d\n",
libcfs_nid2str(peer->ibp_nid), rc);
}
kiblnd_peer_connect_failed(peer, 1, rc);
kiblnd_peer_decref(peer);
return rc;
case RDMA_CM_EVENT_ROUTE_ERROR:
peer = (struct kib_peer *)cmid->context;
CNETERR("%s: ROUTE ERROR %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
kiblnd_peer_connect_failed(peer, 1, -EHOSTUNREACH);
kiblnd_peer_decref(peer);
return -EHOSTUNREACH;
case RDMA_CM_EVENT_ROUTE_RESOLVED:
peer = (struct kib_peer *)cmid->context;
CDEBUG(D_NET, "%s Route resolved: %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
if (!event->status)
return kiblnd_active_connect(cmid);
CNETERR("Can't resolve route for %s: %d\n",
libcfs_nid2str(peer->ibp_nid), event->status);
kiblnd_peer_connect_failed(peer, 1, event->status);
kiblnd_peer_decref(peer);
return event->status;
case RDMA_CM_EVENT_UNREACHABLE:
conn = (struct kib_conn *)cmid->context;
LASSERT(conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT ||
conn->ibc_state == IBLND_CONN_PASSIVE_WAIT);
CNETERR("%s: UNREACHABLE %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), event->status);
kiblnd_connreq_done(conn, -ENETDOWN);
kiblnd_conn_decref(conn);
return 0;
case RDMA_CM_EVENT_CONNECT_ERROR:
conn = (struct kib_conn *)cmid->context;
LASSERT(conn->ibc_state == IBLND_CONN_ACTIVE_CONNECT ||
conn->ibc_state == IBLND_CONN_PASSIVE_WAIT);
CNETERR("%s: CONNECT ERROR %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), event->status);
kiblnd_connreq_done(conn, -ENOTCONN);
kiblnd_conn_decref(conn);
return 0;
case RDMA_CM_EVENT_REJECTED:
conn = (struct kib_conn *)cmid->context;
switch (conn->ibc_state) {
default:
LBUG();
case IBLND_CONN_PASSIVE_WAIT:
CERROR("%s: REJECTED %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
event->status);
kiblnd_connreq_done(conn, -ECONNRESET);
break;
case IBLND_CONN_ACTIVE_CONNECT:
kiblnd_rejected(conn, event->status,
(void *)KIBLND_CONN_PARAM(event),
KIBLND_CONN_PARAM_LEN(event));
break;
}
kiblnd_conn_decref(conn);
return 0;
case RDMA_CM_EVENT_ESTABLISHED:
conn = (struct kib_conn *)cmid->context;
switch (conn->ibc_state) {
default:
LBUG();
case IBLND_CONN_PASSIVE_WAIT:
CDEBUG(D_NET, "ESTABLISHED (passive): %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
kiblnd_connreq_done(conn, 0);
break;
case IBLND_CONN_ACTIVE_CONNECT:
CDEBUG(D_NET, "ESTABLISHED(active): %s\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
kiblnd_check_connreply(conn,
(void *)KIBLND_CONN_PARAM(event),
KIBLND_CONN_PARAM_LEN(event));
break;
}
return 0;
case RDMA_CM_EVENT_TIMEWAIT_EXIT:
CDEBUG(D_NET, "Ignore TIMEWAIT_EXIT event\n");
return 0;
case RDMA_CM_EVENT_DISCONNECTED:
conn = (struct kib_conn *)cmid->context;
if (conn->ibc_state < IBLND_CONN_ESTABLISHED) {
CERROR("%s DISCONNECTED\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
kiblnd_connreq_done(conn, -ECONNRESET);
} else {
kiblnd_close_conn(conn, 0);
}
kiblnd_conn_decref(conn);
cmid->context = NULL;
return 0;
case RDMA_CM_EVENT_DEVICE_REMOVAL:
LCONSOLE_ERROR_MSG(0x131,
"Received notification of device removal\n"
"Please shutdown LNET to allow this to proceed\n");
return 0;
case RDMA_CM_EVENT_ADDR_CHANGE:
LCONSOLE_INFO("Physical link changed (eg hca/port)\n");
return 0;
}
}
static int
kiblnd_check_txs_locked(struct kib_conn *conn, struct list_head *txs)
{
struct kib_tx *tx;
struct list_head *ttmp;
list_for_each(ttmp, txs) {
tx = list_entry(ttmp, struct kib_tx, tx_list);
if (txs != &conn->ibc_active_txs) {
LASSERT(tx->tx_queued);
} else {
LASSERT(!tx->tx_queued);
LASSERT(tx->tx_waiting || tx->tx_sending);
}
if (cfs_time_aftereq(jiffies, tx->tx_deadline)) {
CERROR("Timed out tx: %s, %lu seconds\n",
kiblnd_queue2str(conn, txs),
cfs_duration_sec(jiffies - tx->tx_deadline));
return 1;
}
}
return 0;
}
static int
kiblnd_conn_timed_out_locked(struct kib_conn *conn)
{
return kiblnd_check_txs_locked(conn, &conn->ibc_tx_queue) ||
kiblnd_check_txs_locked(conn, &conn->ibc_tx_noops) ||
kiblnd_check_txs_locked(conn, &conn->ibc_tx_queue_rsrvd) ||
kiblnd_check_txs_locked(conn, &conn->ibc_tx_queue_nocred) ||
kiblnd_check_txs_locked(conn, &conn->ibc_active_txs);
}
static void
kiblnd_check_conns(int idx)
{
LIST_HEAD(closes);
LIST_HEAD(checksends);
struct list_head *peers = &kiblnd_data.kib_peers[idx];
struct list_head *ptmp;
struct kib_peer *peer;
struct kib_conn *conn;
struct kib_conn *temp;
struct kib_conn *tmp;
struct list_head *ctmp;
unsigned long flags;
read_lock_irqsave(&kiblnd_data.kib_global_lock, flags);
list_for_each(ptmp, peers) {
peer = list_entry(ptmp, struct kib_peer, ibp_list);
list_for_each(ctmp, &peer->ibp_conns) {
int timedout;
int sendnoop;
conn = list_entry(ctmp, struct kib_conn, ibc_list);
LASSERT(conn->ibc_state == IBLND_CONN_ESTABLISHED);
spin_lock(&conn->ibc_lock);
sendnoop = kiblnd_need_noop(conn);
timedout = kiblnd_conn_timed_out_locked(conn);
if (!sendnoop && !timedout) {
spin_unlock(&conn->ibc_lock);
continue;
}
if (timedout) {
CERROR("Timed out RDMA with %s (%lu): c: %u, oc: %u, rc: %u\n",
libcfs_nid2str(peer->ibp_nid),
cfs_duration_sec(cfs_time_current() -
peer->ibp_last_alive),
conn->ibc_credits,
conn->ibc_outstanding_credits,
conn->ibc_reserved_credits);
list_add(&conn->ibc_connd_list, &closes);
} else {
list_add(&conn->ibc_connd_list, &checksends);
}
kiblnd_conn_addref(conn);
spin_unlock(&conn->ibc_lock);
}
}
read_unlock_irqrestore(&kiblnd_data.kib_global_lock, flags);
list_for_each_entry_safe(conn, tmp, &closes, ibc_connd_list) {
list_del(&conn->ibc_connd_list);
kiblnd_close_conn(conn, -ETIMEDOUT);
kiblnd_conn_decref(conn);
}
list_for_each_entry_safe(conn, temp, &checksends, ibc_connd_list) {
list_del(&conn->ibc_connd_list);
spin_lock(&conn->ibc_lock);
kiblnd_check_sends_locked(conn);
spin_unlock(&conn->ibc_lock);
kiblnd_conn_decref(conn);
}
}
static void
kiblnd_disconnect_conn(struct kib_conn *conn)
{
LASSERT(!in_interrupt());
LASSERT(current == kiblnd_data.kib_connd);
LASSERT(conn->ibc_state == IBLND_CONN_CLOSING);
rdma_disconnect(conn->ibc_cmid);
kiblnd_finalise_conn(conn);
kiblnd_peer_notify(conn->ibc_peer);
}
int
kiblnd_connd(void *arg)
{
spinlock_t *lock= &kiblnd_data.kib_connd_lock;
wait_queue_t wait;
unsigned long flags;
struct kib_conn *conn;
int timeout;
int i;
int dropped_lock;
int peer_index = 0;
unsigned long deadline = jiffies;
cfs_block_allsigs();
init_waitqueue_entry(&wait, current);
kiblnd_data.kib_connd = current;
spin_lock_irqsave(lock, flags);
while (!kiblnd_data.kib_shutdown) {
int reconn = 0;
dropped_lock = 0;
if (!list_empty(&kiblnd_data.kib_connd_zombies)) {
struct kib_peer *peer = NULL;
conn = list_entry(kiblnd_data.kib_connd_zombies.next,
struct kib_conn, ibc_list);
list_del(&conn->ibc_list);
if (conn->ibc_reconnect) {
peer = conn->ibc_peer;
kiblnd_peer_addref(peer);
}
spin_unlock_irqrestore(lock, flags);
dropped_lock = 1;
kiblnd_destroy_conn(conn, !peer);
spin_lock_irqsave(lock, flags);
if (!peer)
continue;
conn->ibc_peer = peer;
if (peer->ibp_reconnected < KIB_RECONN_HIGH_RACE)
list_add_tail(&conn->ibc_list,
&kiblnd_data.kib_reconn_list);
else
list_add_tail(&conn->ibc_list,
&kiblnd_data.kib_reconn_wait);
}
if (!list_empty(&kiblnd_data.kib_connd_conns)) {
conn = list_entry(kiblnd_data.kib_connd_conns.next,
struct kib_conn, ibc_list);
list_del(&conn->ibc_list);
spin_unlock_irqrestore(lock, flags);
dropped_lock = 1;
kiblnd_disconnect_conn(conn);
kiblnd_conn_decref(conn);
spin_lock_irqsave(lock, flags);
}
while (reconn < KIB_RECONN_BREAK) {
if (kiblnd_data.kib_reconn_sec !=
ktime_get_real_seconds()) {
kiblnd_data.kib_reconn_sec = ktime_get_real_seconds();
list_splice_init(&kiblnd_data.kib_reconn_wait,
&kiblnd_data.kib_reconn_list);
}
if (list_empty(&kiblnd_data.kib_reconn_list))
break;
conn = list_entry(kiblnd_data.kib_reconn_list.next,
struct kib_conn, ibc_list);
list_del(&conn->ibc_list);
spin_unlock_irqrestore(lock, flags);
dropped_lock = 1;
reconn += kiblnd_reconnect_peer(conn->ibc_peer);
kiblnd_peer_decref(conn->ibc_peer);
LIBCFS_FREE(conn, sizeof(*conn));
spin_lock_irqsave(lock, flags);
}
timeout = (int)(deadline - jiffies);
if (timeout <= 0) {
const int n = 4;
const int p = 1;
int chunk = kiblnd_data.kib_peer_hash_size;
spin_unlock_irqrestore(lock, flags);
dropped_lock = 1;
if (*kiblnd_tunables.kib_timeout > n * p)
chunk = (chunk * n * p) /
*kiblnd_tunables.kib_timeout;
if (!chunk)
chunk = 1;
for (i = 0; i < chunk; i++) {
kiblnd_check_conns(peer_index);
peer_index = (peer_index + 1) %
kiblnd_data.kib_peer_hash_size;
}
deadline += msecs_to_jiffies(p * MSEC_PER_SEC);
spin_lock_irqsave(lock, flags);
}
if (dropped_lock)
continue;
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&kiblnd_data.kib_connd_waitq, &wait);
spin_unlock_irqrestore(lock, flags);
schedule_timeout(timeout);
remove_wait_queue(&kiblnd_data.kib_connd_waitq, &wait);
spin_lock_irqsave(lock, flags);
}
spin_unlock_irqrestore(lock, flags);
kiblnd_thread_fini();
return 0;
}
void
kiblnd_qp_event(struct ib_event *event, void *arg)
{
struct kib_conn *conn = arg;
switch (event->event) {
case IB_EVENT_COMM_EST:
CDEBUG(D_NET, "%s established\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid));
rdma_notify(conn->ibc_cmid, IB_EVENT_COMM_EST);
return;
default:
CERROR("%s: Async QP event type %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), event->event);
return;
}
}
static void
kiblnd_complete(struct ib_wc *wc)
{
switch (kiblnd_wreqid2type(wc->wr_id)) {
default:
LBUG();
case IBLND_WID_MR:
if (wc->status != IB_WC_SUCCESS &&
wc->status != IB_WC_WR_FLUSH_ERR)
CNETERR("FastReg failed: %d\n", wc->status);
break;
case IBLND_WID_RDMA:
CNETERR("RDMA (tx: %p) failed: %d\n",
kiblnd_wreqid2ptr(wc->wr_id), wc->status);
return;
case IBLND_WID_TX:
kiblnd_tx_complete(kiblnd_wreqid2ptr(wc->wr_id), wc->status);
return;
case IBLND_WID_RX:
kiblnd_rx_complete(kiblnd_wreqid2ptr(wc->wr_id), wc->status,
wc->byte_len);
return;
}
}
void
kiblnd_cq_completion(struct ib_cq *cq, void *arg)
{
struct kib_conn *conn = arg;
struct kib_sched_info *sched = conn->ibc_sched;
unsigned long flags;
LASSERT(cq == conn->ibc_cq);
spin_lock_irqsave(&sched->ibs_lock, flags);
conn->ibc_ready = 1;
if (!conn->ibc_scheduled &&
(conn->ibc_nrx > 0 ||
conn->ibc_nsends_posted > 0)) {
kiblnd_conn_addref(conn);
conn->ibc_scheduled = 1;
list_add_tail(&conn->ibc_sched_list, &sched->ibs_conns);
if (waitqueue_active(&sched->ibs_waitq))
wake_up(&sched->ibs_waitq);
}
spin_unlock_irqrestore(&sched->ibs_lock, flags);
}
void
kiblnd_cq_event(struct ib_event *event, void *arg)
{
struct kib_conn *conn = arg;
CERROR("%s: async CQ event type %d\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), event->event);
}
int
kiblnd_scheduler(void *arg)
{
long id = (long)arg;
struct kib_sched_info *sched;
struct kib_conn *conn;
wait_queue_t wait;
unsigned long flags;
struct ib_wc wc;
int did_something;
int busy_loops = 0;
int rc;
cfs_block_allsigs();
init_waitqueue_entry(&wait, current);
sched = kiblnd_data.kib_scheds[KIB_THREAD_CPT(id)];
rc = cfs_cpt_bind(lnet_cpt_table(), sched->ibs_cpt);
if (rc) {
CWARN("Failed to bind on CPT %d, please verify whether all CPUs are healthy and reload modules if necessary, otherwise your system might under risk of low performance\n",
sched->ibs_cpt);
}
spin_lock_irqsave(&sched->ibs_lock, flags);
while (!kiblnd_data.kib_shutdown) {
if (busy_loops++ >= IBLND_RESCHED) {
spin_unlock_irqrestore(&sched->ibs_lock, flags);
cond_resched();
busy_loops = 0;
spin_lock_irqsave(&sched->ibs_lock, flags);
}
did_something = 0;
if (!list_empty(&sched->ibs_conns)) {
conn = list_entry(sched->ibs_conns.next, struct kib_conn,
ibc_sched_list);
LASSERT(conn->ibc_scheduled);
list_del(&conn->ibc_sched_list);
conn->ibc_ready = 0;
spin_unlock_irqrestore(&sched->ibs_lock, flags);
wc.wr_id = IBLND_WID_INVAL;
rc = ib_poll_cq(conn->ibc_cq, 1, &wc);
if (!rc) {
rc = ib_req_notify_cq(conn->ibc_cq,
IB_CQ_NEXT_COMP);
if (rc < 0) {
CWARN("%s: ib_req_notify_cq failed: %d, closing connection\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid), rc);
kiblnd_close_conn(conn, -EIO);
kiblnd_conn_decref(conn);
spin_lock_irqsave(&sched->ibs_lock,
flags);
continue;
}
rc = ib_poll_cq(conn->ibc_cq, 1, &wc);
}
if (unlikely(rc > 0 && wc.wr_id == IBLND_WID_INVAL)) {
LCONSOLE_ERROR("ib_poll_cq (rc: %d) returned invalid wr_id, opcode %d, status: %d, vendor_err: %d, conn: %s status: %d\nplease upgrade firmware and OFED or contact vendor.\n",
rc, wc.opcode, wc.status,
wc.vendor_err,
libcfs_nid2str(conn->ibc_peer->ibp_nid),
conn->ibc_state);
rc = -EINVAL;
}
if (rc < 0) {
CWARN("%s: ib_poll_cq failed: %d, closing connection\n",
libcfs_nid2str(conn->ibc_peer->ibp_nid),
rc);
kiblnd_close_conn(conn, -EIO);
kiblnd_conn_decref(conn);
spin_lock_irqsave(&sched->ibs_lock, flags);
continue;
}
spin_lock_irqsave(&sched->ibs_lock, flags);
if (rc || conn->ibc_ready) {
kiblnd_conn_addref(conn);
list_add_tail(&conn->ibc_sched_list,
&sched->ibs_conns);
if (waitqueue_active(&sched->ibs_waitq))
wake_up(&sched->ibs_waitq);
} else {
conn->ibc_scheduled = 0;
}
if (rc) {
spin_unlock_irqrestore(&sched->ibs_lock, flags);
kiblnd_complete(&wc);
spin_lock_irqsave(&sched->ibs_lock, flags);
}
kiblnd_conn_decref(conn);
did_something = 1;
}
if (did_something)
continue;
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue_exclusive(&sched->ibs_waitq, &wait);
spin_unlock_irqrestore(&sched->ibs_lock, flags);
schedule();
busy_loops = 0;
remove_wait_queue(&sched->ibs_waitq, &wait);
spin_lock_irqsave(&sched->ibs_lock, flags);
}
spin_unlock_irqrestore(&sched->ibs_lock, flags);
kiblnd_thread_fini();
return 0;
}
int
kiblnd_failover_thread(void *arg)
{
rwlock_t *glock = &kiblnd_data.kib_global_lock;
struct kib_dev *dev;
wait_queue_t wait;
unsigned long flags;
int rc;
LASSERT(*kiblnd_tunables.kib_dev_failover);
cfs_block_allsigs();
init_waitqueue_entry(&wait, current);
write_lock_irqsave(glock, flags);
while (!kiblnd_data.kib_shutdown) {
int do_failover = 0;
int long_sleep;
list_for_each_entry(dev, &kiblnd_data.kib_failed_devs,
ibd_fail_list) {
if (time_before(cfs_time_current(),
dev->ibd_next_failover))
continue;
do_failover = 1;
break;
}
if (do_failover) {
list_del_init(&dev->ibd_fail_list);
dev->ibd_failover = 1;
write_unlock_irqrestore(glock, flags);
rc = kiblnd_dev_failover(dev);
write_lock_irqsave(glock, flags);
LASSERT(dev->ibd_failover);
dev->ibd_failover = 0;
if (rc >= 0) {
dev->ibd_next_failover = cfs_time_shift(3);
continue;
}
dev->ibd_next_failover =
cfs_time_shift(min(dev->ibd_failed_failover, 10));
if (kiblnd_dev_can_failover(dev)) {
list_add_tail(&dev->ibd_fail_list,
&kiblnd_data.kib_failed_devs);
}
continue;
}
long_sleep = list_empty(&kiblnd_data.kib_failed_devs);
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&kiblnd_data.kib_failover_waitq, &wait);
write_unlock_irqrestore(glock, flags);
rc = schedule_timeout(long_sleep ? cfs_time_seconds(10) :
cfs_time_seconds(1));
remove_wait_queue(&kiblnd_data.kib_failover_waitq, &wait);
write_lock_irqsave(glock, flags);
if (!long_sleep || rc)
continue;
list_for_each_entry(dev, &kiblnd_data.kib_devs, ibd_list) {
if (kiblnd_dev_can_failover(dev)) {
list_add_tail(&dev->ibd_fail_list,
&kiblnd_data.kib_failed_devs);
}
}
}
write_unlock_irqrestore(glock, flags);
kiblnd_thread_fini();
return 0;
}
