int
lnet_fail_nid(lnet_nid_t nid, unsigned int threshold)
{
lnet_test_peer_t *tp;
struct list_head *el;
struct list_head *next;
struct list_head cull;
LASSERT(the_lnet.ln_init);
if (threshold != 0) {
LIBCFS_ALLOC(tp, sizeof(*tp));
if (tp == NULL)
return -ENOMEM;
tp->tp_nid = nid;
tp->tp_threshold = threshold;
lnet_net_lock(0);
list_add_tail(&tp->tp_list, &the_lnet.ln_test_peers);
lnet_net_unlock(0);
return 0;
}
INIT_LIST_HEAD(&cull);
lnet_net_lock(0);
list_for_each_safe(el, next, &the_lnet.ln_test_peers) {
tp = list_entry(el, lnet_test_peer_t, tp_list);
if (tp->tp_threshold == 0 ||
nid == LNET_NID_ANY ||
tp->tp_nid == nid) {
list_del(&tp->tp_list);
list_add(&tp->tp_list, &cull);
}
}
lnet_net_unlock(0);
while (!list_empty(&cull)) {
tp = list_entry(cull.next, lnet_test_peer_t, tp_list);
list_del(&tp->tp_list);
LIBCFS_FREE(tp, sizeof(*tp));
}
return 0;
}
static int
fail_peer(lnet_nid_t nid, int outgoing)
{
lnet_test_peer_t *tp;
struct list_head *el;
struct list_head *next;
struct list_head cull;
int fail = 0;
INIT_LIST_HEAD(&cull);
lnet_net_lock(0);
list_for_each_safe(el, next, &the_lnet.ln_test_peers) {
tp = list_entry(el, lnet_test_peer_t, tp_list);
if (tp->tp_threshold == 0) {
if (outgoing) {
list_del(&tp->tp_list);
list_add(&tp->tp_list, &cull);
}
continue;
}
if (tp->tp_nid == LNET_NID_ANY ||
nid == tp->tp_nid) {
fail = 1;
if (tp->tp_threshold != LNET_MD_THRESH_INF) {
tp->tp_threshold--;
if (outgoing &&
tp->tp_threshold == 0) {
list_del(&tp->tp_list);
list_add(&tp->tp_list, &cull);
}
}
break;
}
}
lnet_net_unlock(0);
while (!list_empty(&cull)) {
tp = list_entry(cull.next, lnet_test_peer_t, tp_list);
list_del(&tp->tp_list);
LIBCFS_FREE(tp, sizeof(*tp));
}
return fail;
}
unsigned int
lnet_iov_nob(unsigned int niov, struct kvec *iov)
{
unsigned int nob = 0;
while (niov-- > 0)
nob += (iov++)->iov_len;
return nob;
}
void
lnet_copy_iov2iov(unsigned int ndiov, struct kvec *diov, unsigned int doffset,
unsigned int nsiov, struct kvec *siov, unsigned int soffset,
unsigned int nob)
{
unsigned int this_nob;
if (nob == 0)
return;
LASSERT(ndiov > 0);
while (doffset >= diov->iov_len) {
doffset -= diov->iov_len;
diov++;
ndiov--;
LASSERT(ndiov > 0);
}
LASSERT(nsiov > 0);
while (soffset >= siov->iov_len) {
soffset -= siov->iov_len;
siov++;
nsiov--;
LASSERT(nsiov > 0);
}
do {
LASSERT(ndiov > 0);
LASSERT(nsiov > 0);
this_nob = min(diov->iov_len - doffset,
siov->iov_len - soffset);
this_nob = min(this_nob, nob);
memcpy((char *)diov->iov_base + doffset,
(char *)siov->iov_base + soffset, this_nob);
nob -= this_nob;
if (diov->iov_len > doffset + this_nob) {
doffset += this_nob;
} else {
diov++;
ndiov--;
doffset = 0;
}
if (siov->iov_len > soffset + this_nob) {
soffset += this_nob;
} else {
siov++;
nsiov--;
soffset = 0;
}
} while (nob > 0);
}
int
lnet_extract_iov(int dst_niov, struct kvec *dst,
int src_niov, struct kvec *src,
unsigned int offset, unsigned int len)
{
unsigned int frag_len;
unsigned int niov;
if (len == 0)
return 0;
LASSERT(src_niov > 0);
while (offset >= src->iov_len) {
offset -= src->iov_len;
src_niov--;
src++;
LASSERT(src_niov > 0);
}
niov = 1;
for (;;) {
LASSERT(src_niov > 0);
LASSERT((int)niov <= dst_niov);
frag_len = src->iov_len - offset;
dst->iov_base = ((char *)src->iov_base) + offset;
if (len <= frag_len) {
dst->iov_len = len;
return niov;
}
dst->iov_len = frag_len;
len -= frag_len;
dst++;
src++;
niov++;
src_niov--;
offset = 0;
}
}
unsigned int
lnet_kiov_nob(unsigned int niov, lnet_kiov_t *kiov)
{
unsigned int nob = 0;
while (niov-- > 0)
nob += (kiov++)->kiov_len;
return nob;
}
void
lnet_copy_kiov2kiov(unsigned int ndiov, lnet_kiov_t *diov, unsigned int doffset,
unsigned int nsiov, lnet_kiov_t *siov, unsigned int soffset,
unsigned int nob)
{
unsigned int this_nob;
char *daddr = NULL;
char *saddr = NULL;
if (nob == 0)
return;
LASSERT(!in_interrupt());
LASSERT(ndiov > 0);
while (doffset >= diov->kiov_len) {
doffset -= diov->kiov_len;
diov++;
ndiov--;
LASSERT(ndiov > 0);
}
LASSERT(nsiov > 0);
while (soffset >= siov->kiov_len) {
soffset -= siov->kiov_len;
siov++;
nsiov--;
LASSERT(nsiov > 0);
}
do {
LASSERT(ndiov > 0);
LASSERT(nsiov > 0);
this_nob = min(diov->kiov_len - doffset,
siov->kiov_len - soffset);
this_nob = min(this_nob, nob);
if (daddr == NULL)
daddr = ((char *)kmap(diov->kiov_page)) +
diov->kiov_offset + doffset;
if (saddr == NULL)
saddr = ((char *)kmap(siov->kiov_page)) +
siov->kiov_offset + soffset;
memcpy(daddr, saddr, this_nob);
nob -= this_nob;
if (diov->kiov_len > doffset + this_nob) {
daddr += this_nob;
doffset += this_nob;
} else {
kunmap(diov->kiov_page);
daddr = NULL;
diov++;
ndiov--;
doffset = 0;
}
if (siov->kiov_len > soffset + this_nob) {
saddr += this_nob;
soffset += this_nob;
} else {
kunmap(siov->kiov_page);
saddr = NULL;
siov++;
nsiov--;
soffset = 0;
}
} while (nob > 0);
if (daddr != NULL)
kunmap(diov->kiov_page);
if (saddr != NULL)
kunmap(siov->kiov_page);
}
void
lnet_copy_kiov2iov(unsigned int niov, struct kvec *iov, unsigned int iovoffset,
unsigned int nkiov, lnet_kiov_t *kiov,
unsigned int kiovoffset, unsigned int nob)
{
unsigned int this_nob;
char *addr = NULL;
if (nob == 0)
return;
LASSERT(!in_interrupt());
LASSERT(niov > 0);
while (iovoffset >= iov->iov_len) {
iovoffset -= iov->iov_len;
iov++;
niov--;
LASSERT(niov > 0);
}
LASSERT(nkiov > 0);
while (kiovoffset >= kiov->kiov_len) {
kiovoffset -= kiov->kiov_len;
kiov++;
nkiov--;
LASSERT(nkiov > 0);
}
do {
LASSERT(niov > 0);
LASSERT(nkiov > 0);
this_nob = min(iov->iov_len - iovoffset,
(__kernel_size_t) kiov->kiov_len - kiovoffset);
this_nob = min(this_nob, nob);
if (addr == NULL)
addr = ((char *)kmap(kiov->kiov_page)) +
kiov->kiov_offset + kiovoffset;
memcpy((char *)iov->iov_base + iovoffset, addr, this_nob);
nob -= this_nob;
if (iov->iov_len > iovoffset + this_nob) {
iovoffset += this_nob;
} else {
iov++;
niov--;
iovoffset = 0;
}
if (kiov->kiov_len > kiovoffset + this_nob) {
addr += this_nob;
kiovoffset += this_nob;
} else {
kunmap(kiov->kiov_page);
addr = NULL;
kiov++;
nkiov--;
kiovoffset = 0;
}
} while (nob > 0);
if (addr != NULL)
kunmap(kiov->kiov_page);
}
void
lnet_copy_iov2kiov(unsigned int nkiov, lnet_kiov_t *kiov,
unsigned int kiovoffset, unsigned int niov,
struct kvec *iov, unsigned int iovoffset,
unsigned int nob)
{
unsigned int this_nob;
char *addr = NULL;
if (nob == 0)
return;
LASSERT(!in_interrupt());
LASSERT(nkiov > 0);
while (kiovoffset >= kiov->kiov_len) {
kiovoffset -= kiov->kiov_len;
kiov++;
nkiov--;
LASSERT(nkiov > 0);
}
LASSERT(niov > 0);
while (iovoffset >= iov->iov_len) {
iovoffset -= iov->iov_len;
iov++;
niov--;
LASSERT(niov > 0);
}
do {
LASSERT(nkiov > 0);
LASSERT(niov > 0);
this_nob = min((__kernel_size_t) kiov->kiov_len - kiovoffset,
iov->iov_len - iovoffset);
this_nob = min(this_nob, nob);
if (addr == NULL)
addr = ((char *)kmap(kiov->kiov_page)) +
kiov->kiov_offset + kiovoffset;
memcpy(addr, (char *)iov->iov_base + iovoffset, this_nob);
nob -= this_nob;
if (kiov->kiov_len > kiovoffset + this_nob) {
addr += this_nob;
kiovoffset += this_nob;
} else {
kunmap(kiov->kiov_page);
addr = NULL;
kiov++;
nkiov--;
kiovoffset = 0;
}
if (iov->iov_len > iovoffset + this_nob) {
iovoffset += this_nob;
} else {
iov++;
niov--;
iovoffset = 0;
}
} while (nob > 0);
if (addr != NULL)
kunmap(kiov->kiov_page);
}
int
lnet_extract_kiov(int dst_niov, lnet_kiov_t *dst,
int src_niov, lnet_kiov_t *src,
unsigned int offset, unsigned int len)
{
unsigned int frag_len;
unsigned int niov;
if (len == 0)
return 0;
LASSERT(src_niov > 0);
while (offset >= src->kiov_len) {
offset -= src->kiov_len;
src_niov--;
src++;
LASSERT(src_niov > 0);
}
niov = 1;
for (;;) {
LASSERT(src_niov > 0);
LASSERT((int)niov <= dst_niov);
frag_len = src->kiov_len - offset;
dst->kiov_page = src->kiov_page;
dst->kiov_offset = src->kiov_offset + offset;
if (len <= frag_len) {
dst->kiov_len = len;
LASSERT(dst->kiov_offset + dst->kiov_len
<= PAGE_CACHE_SIZE);
return niov;
}
dst->kiov_len = frag_len;
LASSERT(dst->kiov_offset + dst->kiov_len <= PAGE_CACHE_SIZE);
len -= frag_len;
dst++;
src++;
niov++;
src_niov--;
offset = 0;
}
}
static void
lnet_ni_recv(lnet_ni_t *ni, void *private, lnet_msg_t *msg, int delayed,
unsigned int offset, unsigned int mlen, unsigned int rlen)
{
unsigned int niov = 0;
struct kvec *iov = NULL;
lnet_kiov_t *kiov = NULL;
int rc;
LASSERT(!in_interrupt());
LASSERT(mlen == 0 || msg != NULL);
if (msg != NULL) {
LASSERT(msg->msg_receiving);
LASSERT(!msg->msg_sending);
LASSERT(rlen == msg->msg_len);
LASSERT(mlen <= msg->msg_len);
LASSERT(msg->msg_offset == offset);
LASSERT(msg->msg_wanted == mlen);
msg->msg_receiving = 0;
if (mlen != 0) {
niov = msg->msg_niov;
iov = msg->msg_iov;
kiov = msg->msg_kiov;
LASSERT(niov > 0);
LASSERT((iov == NULL) != (kiov == NULL));
}
}
rc = (ni->ni_lnd->lnd_recv)(ni, private, msg, delayed,
niov, iov, kiov, offset, mlen, rlen);
if (rc < 0)
lnet_finalize(ni, msg, rc);
}
static void
lnet_setpayloadbuffer(lnet_msg_t *msg)
{
lnet_libmd_t *md = msg->msg_md;
LASSERT(msg->msg_len > 0);
LASSERT(!msg->msg_routing);
LASSERT(md != NULL);
LASSERT(msg->msg_niov == 0);
LASSERT(msg->msg_iov == NULL);
LASSERT(msg->msg_kiov == NULL);
msg->msg_niov = md->md_niov;
if ((md->md_options & LNET_MD_KIOV) != 0)
msg->msg_kiov = md->md_iov.kiov;
else
msg->msg_iov = md->md_iov.iov;
}
void
lnet_prep_send(lnet_msg_t *msg, int type, lnet_process_id_t target,
unsigned int offset, unsigned int len)
{
msg->msg_type = type;
msg->msg_target = target;
msg->msg_len = len;
msg->msg_offset = offset;
if (len != 0)
lnet_setpayloadbuffer(msg);
memset(&msg->msg_hdr, 0, sizeof(msg->msg_hdr));
msg->msg_hdr.type = cpu_to_le32(type);
msg->msg_hdr.dest_nid = cpu_to_le64(target.nid);
msg->msg_hdr.dest_pid = cpu_to_le32(target.pid);
msg->msg_hdr.src_pid = cpu_to_le32(the_lnet.ln_pid);
msg->msg_hdr.payload_length = cpu_to_le32(len);
}
static void
lnet_ni_send(lnet_ni_t *ni, lnet_msg_t *msg)
{
void *priv = msg->msg_private;
int rc;
LASSERT(!in_interrupt());
LASSERT(LNET_NETTYP(LNET_NIDNET(ni->ni_nid)) == LOLND ||
(msg->msg_txcredit && msg->msg_peertxcredit));
rc = (ni->ni_lnd->lnd_send)(ni, priv, msg);
if (rc < 0)
lnet_finalize(ni, msg, rc);
}
static int
lnet_ni_eager_recv(lnet_ni_t *ni, lnet_msg_t *msg)
{
int rc;
LASSERT(!msg->msg_sending);
LASSERT(msg->msg_receiving);
LASSERT(!msg->msg_rx_ready_delay);
LASSERT(ni->ni_lnd->lnd_eager_recv != NULL);
msg->msg_rx_ready_delay = 1;
rc = (ni->ni_lnd->lnd_eager_recv)(ni, msg->msg_private, msg,
&msg->msg_private);
if (rc != 0) {
CERROR("recv from %s / send to %s aborted: eager_recv failed %d\n",
libcfs_nid2str(msg->msg_rxpeer->lp_nid),
libcfs_id2str(msg->msg_target), rc);
LASSERT(rc < 0);
}
return rc;
}
static void
lnet_ni_query_locked(lnet_ni_t *ni, lnet_peer_t *lp)
{
unsigned long last_alive = 0;
LASSERT(lnet_peer_aliveness_enabled(lp));
LASSERT(ni->ni_lnd->lnd_query != NULL);
lnet_net_unlock(lp->lp_cpt);
(ni->ni_lnd->lnd_query)(ni, lp->lp_nid, &last_alive);
lnet_net_lock(lp->lp_cpt);
lp->lp_last_query = cfs_time_current();
if (last_alive != 0)
lp->lp_last_alive = last_alive;
}
static inline int
lnet_peer_is_alive(lnet_peer_t *lp, unsigned long now)
{
int alive;
unsigned long deadline;
LASSERT(lnet_peer_aliveness_enabled(lp));
if (!lp->lp_alive && lp->lp_alive_count > 0 &&
cfs_time_aftereq(lp->lp_timestamp, lp->lp_last_alive))
return 0;
deadline = cfs_time_add(lp->lp_last_alive,
cfs_time_seconds(lp->lp_ni->ni_peertimeout));
alive = cfs_time_after(deadline, now);
if (alive && !lp->lp_alive &&
!(lnet_isrouter(lp) && lp->lp_alive_count == 0))
lnet_notify_locked(lp, 0, 1, lp->lp_last_alive);
return alive;
}
static int
lnet_peer_alive_locked(lnet_peer_t *lp)
{
unsigned long now = cfs_time_current();
if (!lnet_peer_aliveness_enabled(lp))
return -ENODEV;
if (lnet_peer_is_alive(lp, now))
return 1;
if (lp->lp_last_query != 0) {
static const int lnet_queryinterval = 1;
unsigned long next_query =
cfs_time_add(lp->lp_last_query,
cfs_time_seconds(lnet_queryinterval));
if (time_before(now, next_query)) {
if (lp->lp_alive)
CWARN("Unexpected aliveness of peer %s: %d < %d (%d/%d)\n",
libcfs_nid2str(lp->lp_nid),
(int)now, (int)next_query,
lnet_queryinterval,
lp->lp_ni->ni_peertimeout);
return 0;
}
}
lnet_ni_query_locked(lp->lp_ni, lp);
if (lnet_peer_is_alive(lp, now))
return 1;
lnet_notify_locked(lp, 0, 0, lp->lp_last_alive);
return 0;
}
static int
lnet_post_send_locked(lnet_msg_t *msg, int do_send)
{
lnet_peer_t *lp = msg->msg_txpeer;
lnet_ni_t *ni = lp->lp_ni;
int cpt = msg->msg_tx_cpt;
struct lnet_tx_queue *tq = ni->ni_tx_queues[cpt];
LASSERT(!do_send || msg->msg_tx_delayed);
LASSERT(!msg->msg_receiving);
LASSERT(msg->msg_tx_committed);
if ((msg->msg_target.pid & LNET_PID_USERFLAG) == 0 &&
lnet_peer_alive_locked(lp) == 0) {
the_lnet.ln_counters[cpt]->drop_count++;
the_lnet.ln_counters[cpt]->drop_length += msg->msg_len;
lnet_net_unlock(cpt);
CNETERR("Dropping message for %s: peer not alive\n",
libcfs_id2str(msg->msg_target));
if (do_send)
lnet_finalize(ni, msg, -EHOSTUNREACH);
lnet_net_lock(cpt);
return EHOSTUNREACH;
}
if (msg->msg_md != NULL &&
(msg->msg_md->md_flags & LNET_MD_FLAG_ABORTED) != 0) {
lnet_net_unlock(cpt);
CNETERR("Aborting message for %s: LNetM[DE]Unlink() already called on the MD/ME.\n",
libcfs_id2str(msg->msg_target));
if (do_send)
lnet_finalize(ni, msg, -ECANCELED);
lnet_net_lock(cpt);
return ECANCELED;
}
if (!msg->msg_peertxcredit) {
LASSERT((lp->lp_txcredits < 0) ==
!list_empty(&lp->lp_txq));
msg->msg_peertxcredit = 1;
lp->lp_txqnob += msg->msg_len + sizeof(lnet_hdr_t);
lp->lp_txcredits--;
if (lp->lp_txcredits < lp->lp_mintxcredits)
lp->lp_mintxcredits = lp->lp_txcredits;
if (lp->lp_txcredits < 0) {
msg->msg_tx_delayed = 1;
list_add_tail(&msg->msg_list, &lp->lp_txq);
return EAGAIN;
}
}
if (!msg->msg_txcredit) {
LASSERT((tq->tq_credits < 0) ==
!list_empty(&tq->tq_delayed));
msg->msg_txcredit = 1;
tq->tq_credits--;
if (tq->tq_credits < tq->tq_credits_min)
tq->tq_credits_min = tq->tq_credits;
if (tq->tq_credits < 0) {
msg->msg_tx_delayed = 1;
list_add_tail(&msg->msg_list, &tq->tq_delayed);
return EAGAIN;
}
}
if (do_send) {
lnet_net_unlock(cpt);
lnet_ni_send(ni, msg);
lnet_net_lock(cpt);
}
return 0;
}
static lnet_rtrbufpool_t *
lnet_msg2bufpool(lnet_msg_t *msg)
{
lnet_rtrbufpool_t *rbp;
int cpt;
LASSERT(msg->msg_rx_committed);
cpt = msg->msg_rx_cpt;
rbp = &the_lnet.ln_rtrpools[cpt][0];
LASSERT(msg->msg_len <= LNET_MTU);
while (msg->msg_len > (unsigned int)rbp->rbp_npages * PAGE_CACHE_SIZE) {
rbp++;
LASSERT(rbp < &the_lnet.ln_rtrpools[cpt][LNET_NRBPOOLS]);
}
return rbp;
}
static int
lnet_post_routed_recv_locked(lnet_msg_t *msg, int do_recv)
{
lnet_peer_t *lp = msg->msg_rxpeer;
lnet_rtrbufpool_t *rbp;
lnet_rtrbuf_t *rb;
LASSERT(msg->msg_iov == NULL);
LASSERT(msg->msg_kiov == NULL);
LASSERT(msg->msg_niov == 0);
LASSERT(msg->msg_routing);
LASSERT(msg->msg_receiving);
LASSERT(!msg->msg_sending);
LASSERT(!do_recv || msg->msg_rx_delayed);
if (!msg->msg_peerrtrcredit) {
LASSERT((lp->lp_rtrcredits < 0) ==
!list_empty(&lp->lp_rtrq));
msg->msg_peerrtrcredit = 1;
lp->lp_rtrcredits--;
if (lp->lp_rtrcredits < lp->lp_minrtrcredits)
lp->lp_minrtrcredits = lp->lp_rtrcredits;
if (lp->lp_rtrcredits < 0) {
LASSERT(msg->msg_rx_ready_delay);
msg->msg_rx_delayed = 1;
list_add_tail(&msg->msg_list, &lp->lp_rtrq);
return EAGAIN;
}
}
rbp = lnet_msg2bufpool(msg);
if (!msg->msg_rtrcredit) {
LASSERT((rbp->rbp_credits < 0) ==
!list_empty(&rbp->rbp_msgs));
msg->msg_rtrcredit = 1;
rbp->rbp_credits--;
if (rbp->rbp_credits < rbp->rbp_mincredits)
rbp->rbp_mincredits = rbp->rbp_credits;
if (rbp->rbp_credits < 0) {
LASSERT(msg->msg_rx_ready_delay);
msg->msg_rx_delayed = 1;
list_add_tail(&msg->msg_list, &rbp->rbp_msgs);
return EAGAIN;
}
}
LASSERT(!list_empty(&rbp->rbp_bufs));
rb = list_entry(rbp->rbp_bufs.next, lnet_rtrbuf_t, rb_list);
list_del(&rb->rb_list);
msg->msg_niov = rbp->rbp_npages;
msg->msg_kiov = &rb->rb_kiov[0];
if (do_recv) {
int cpt = msg->msg_rx_cpt;
lnet_net_unlock(cpt);
lnet_ni_recv(lp->lp_ni, msg->msg_private, msg, 1,
0, msg->msg_len, msg->msg_len);
lnet_net_lock(cpt);
}
return 0;
}
void
lnet_return_tx_credits_locked(lnet_msg_t *msg)
{
lnet_peer_t *txpeer = msg->msg_txpeer;
lnet_msg_t *msg2;
if (msg->msg_txcredit) {
struct lnet_ni *ni = txpeer->lp_ni;
struct lnet_tx_queue *tq = ni->ni_tx_queues[msg->msg_tx_cpt];
msg->msg_txcredit = 0;
LASSERT((tq->tq_credits < 0) ==
!list_empty(&tq->tq_delayed));
tq->tq_credits++;
if (tq->tq_credits <= 0) {
msg2 = list_entry(tq->tq_delayed.next,
lnet_msg_t, msg_list);
list_del(&msg2->msg_list);
LASSERT(msg2->msg_txpeer->lp_ni == ni);
LASSERT(msg2->msg_tx_delayed);
(void) lnet_post_send_locked(msg2, 1);
}
}
if (msg->msg_peertxcredit) {
msg->msg_peertxcredit = 0;
LASSERT((txpeer->lp_txcredits < 0) ==
!list_empty(&txpeer->lp_txq));
txpeer->lp_txqnob -= msg->msg_len + sizeof(lnet_hdr_t);
LASSERT(txpeer->lp_txqnob >= 0);
txpeer->lp_txcredits++;
if (txpeer->lp_txcredits <= 0) {
msg2 = list_entry(txpeer->lp_txq.next,
lnet_msg_t, msg_list);
list_del(&msg2->msg_list);
LASSERT(msg2->msg_txpeer == txpeer);
LASSERT(msg2->msg_tx_delayed);
(void) lnet_post_send_locked(msg2, 1);
}
}
if (txpeer != NULL) {
msg->msg_txpeer = NULL;
lnet_peer_decref_locked(txpeer);
}
}
void
lnet_return_rx_credits_locked(lnet_msg_t *msg)
{
lnet_peer_t *rxpeer = msg->msg_rxpeer;
lnet_msg_t *msg2;
if (msg->msg_rtrcredit) {
lnet_rtrbuf_t *rb;
lnet_rtrbufpool_t *rbp;
LASSERT(msg->msg_kiov != NULL);
rb = list_entry(msg->msg_kiov, lnet_rtrbuf_t, rb_kiov[0]);
rbp = rb->rb_pool;
LASSERT(rbp == lnet_msg2bufpool(msg));
msg->msg_kiov = NULL;
msg->msg_rtrcredit = 0;
LASSERT((rbp->rbp_credits < 0) ==
!list_empty(&rbp->rbp_msgs));
LASSERT((rbp->rbp_credits > 0) ==
!list_empty(&rbp->rbp_bufs));
list_add(&rb->rb_list, &rbp->rbp_bufs);
rbp->rbp_credits++;
if (rbp->rbp_credits <= 0) {
msg2 = list_entry(rbp->rbp_msgs.next,
lnet_msg_t, msg_list);
list_del(&msg2->msg_list);
(void) lnet_post_routed_recv_locked(msg2, 1);
}
}
if (msg->msg_peerrtrcredit) {
msg->msg_peerrtrcredit = 0;
LASSERT((rxpeer->lp_rtrcredits < 0) ==
!list_empty(&rxpeer->lp_rtrq));
rxpeer->lp_rtrcredits++;
if (rxpeer->lp_rtrcredits <= 0) {
msg2 = list_entry(rxpeer->lp_rtrq.next,
lnet_msg_t, msg_list);
list_del(&msg2->msg_list);
(void) lnet_post_routed_recv_locked(msg2, 1);
}
}
if (rxpeer != NULL) {
msg->msg_rxpeer = NULL;
lnet_peer_decref_locked(rxpeer);
}
}
static int
lnet_compare_routes(lnet_route_t *r1, lnet_route_t *r2)
{
lnet_peer_t *p1 = r1->lr_gateway;
lnet_peer_t *p2 = r2->lr_gateway;
if (r1->lr_priority < r2->lr_priority)
return 1;
if (r1->lr_priority > r2->lr_priority)
return -1;
if (r1->lr_hops < r2->lr_hops)
return 1;
if (r1->lr_hops > r2->lr_hops)
return -1;
if (p1->lp_txqnob < p2->lp_txqnob)
return 1;
if (p1->lp_txqnob > p2->lp_txqnob)
return -1;
if (p1->lp_txcredits > p2->lp_txcredits)
return 1;
if (p1->lp_txcredits < p2->lp_txcredits)
return -1;
if (r1->lr_seq - r2->lr_seq <= 0)
return 1;
return -1;
}
static lnet_peer_t *
lnet_find_route_locked(lnet_ni_t *ni, lnet_nid_t target, lnet_nid_t rtr_nid)
{
lnet_remotenet_t *rnet;
lnet_route_t *rtr;
lnet_route_t *rtr_best;
lnet_route_t *rtr_last;
struct lnet_peer *lp_best;
struct lnet_peer *lp;
int rc;
rnet = lnet_find_net_locked(LNET_NIDNET(target));
if (rnet == NULL)
return NULL;
lp_best = NULL;
rtr_best = rtr_last = NULL;
list_for_each_entry(rtr, &rnet->lrn_routes, lr_list) {
lp = rtr->lr_gateway;
if (!lp->lp_alive ||
((lp->lp_ping_feats & LNET_PING_FEAT_NI_STATUS) != 0 &&
rtr->lr_downis != 0))
continue;
if (ni != NULL && lp->lp_ni != ni)
continue;
if (lp->lp_nid == rtr_nid)
return lp;
if (lp_best == NULL) {
rtr_best = rtr_last = rtr;
lp_best = lp;
continue;
}
if (rtr_last->lr_seq - rtr->lr_seq < 0)
rtr_last = rtr;
rc = lnet_compare_routes(rtr, rtr_best);
if (rc < 0)
continue;
rtr_best = rtr;
lp_best = lp;
}
if (rtr_best != NULL)
rtr_best->lr_seq = rtr_last->lr_seq + 1;
return lp_best;
}
int
lnet_send(lnet_nid_t src_nid, lnet_msg_t *msg, lnet_nid_t rtr_nid)
{
lnet_nid_t dst_nid = msg->msg_target.nid;
struct lnet_ni *src_ni;
struct lnet_ni *local_ni;
struct lnet_peer *lp;
int cpt;
int cpt2;
int rc;
LASSERT(msg->msg_txpeer == NULL);
LASSERT(!msg->msg_sending);
LASSERT(!msg->msg_target_is_router);
LASSERT(!msg->msg_receiving);
msg->msg_sending = 1;
LASSERT(!msg->msg_tx_committed);
cpt = lnet_cpt_of_nid(rtr_nid == LNET_NID_ANY ? dst_nid : rtr_nid);
again:
lnet_net_lock(cpt);
if (the_lnet.ln_shutdown) {
lnet_net_unlock(cpt);
return -ESHUTDOWN;
}
if (src_nid == LNET_NID_ANY) {
src_ni = NULL;
} else {
src_ni = lnet_nid2ni_locked(src_nid, cpt);
if (src_ni == NULL) {
lnet_net_unlock(cpt);
LCONSOLE_WARN("Can't send to %s: src %s is not a local nid\n",
libcfs_nid2str(dst_nid),
libcfs_nid2str(src_nid));
return -EINVAL;
}
LASSERT(!msg->msg_routing);
}
local_ni = lnet_net2ni_locked(LNET_NIDNET(dst_nid), cpt);
if (local_ni != NULL) {
if (src_ni == NULL) {
src_ni = local_ni;
src_nid = src_ni->ni_nid;
} else if (src_ni == local_ni) {
lnet_ni_decref_locked(local_ni, cpt);
} else {
lnet_ni_decref_locked(local_ni, cpt);
lnet_ni_decref_locked(src_ni, cpt);
lnet_net_unlock(cpt);
LCONSOLE_WARN("No route to %s via from %s\n",
libcfs_nid2str(dst_nid),
libcfs_nid2str(src_nid));
return -EINVAL;
}
LASSERT(src_nid != LNET_NID_ANY);
lnet_msg_commit(msg, cpt);
if (!msg->msg_routing)
msg->msg_hdr.src_nid = cpu_to_le64(src_nid);
if (src_ni == the_lnet.ln_loni) {
lnet_net_unlock(cpt);
lnet_ni_send(src_ni, msg);
lnet_net_lock(cpt);
lnet_ni_decref_locked(src_ni, cpt);
lnet_net_unlock(cpt);
return 0;
}
rc = lnet_nid2peer_locked(&lp, dst_nid, cpt);
lnet_ni_decref_locked(src_ni, cpt);
if (rc != 0) {
lnet_net_unlock(cpt);
LCONSOLE_WARN("Error %d finding peer %s\n", rc,
libcfs_nid2str(dst_nid));
return rc;
}
LASSERT(lp->lp_ni == src_ni);
} else {
lp = lnet_find_route_locked(src_ni, dst_nid, rtr_nid);
if (lp == NULL) {
if (src_ni != NULL)
lnet_ni_decref_locked(src_ni, cpt);
lnet_net_unlock(cpt);
LCONSOLE_WARN("No route to %s via %s (all routers down)\n",
libcfs_id2str(msg->msg_target),
libcfs_nid2str(src_nid));
return -EHOSTUNREACH;
}
if (rtr_nid != lp->lp_nid) {
cpt2 = lnet_cpt_of_nid_locked(lp->lp_nid);
if (cpt2 != cpt) {
if (src_ni != NULL)
lnet_ni_decref_locked(src_ni, cpt);
lnet_net_unlock(cpt);
rtr_nid = lp->lp_nid;
cpt = cpt2;
goto again;
}
}
CDEBUG(D_NET, "Best route to %s via %s for %s %d\n",
libcfs_nid2str(dst_nid), libcfs_nid2str(lp->lp_nid),
lnet_msgtyp2str(msg->msg_type), msg->msg_len);
if (src_ni == NULL) {
src_ni = lp->lp_ni;
src_nid = src_ni->ni_nid;
} else {
LASSERT(src_ni == lp->lp_ni);
lnet_ni_decref_locked(src_ni, cpt);
}
lnet_peer_addref_locked(lp);
LASSERT(src_nid != LNET_NID_ANY);
lnet_msg_commit(msg, cpt);
if (!msg->msg_routing) {
msg->msg_hdr.src_nid = cpu_to_le64(src_nid);
}
msg->msg_target_is_router = 1;
msg->msg_target.nid = lp->lp_nid;
msg->msg_target.pid = LUSTRE_SRV_LNET_PID;
}
LASSERT(!msg->msg_peertxcredit);
LASSERT(!msg->msg_txcredit);
LASSERT(msg->msg_txpeer == NULL);
msg->msg_txpeer = lp;
rc = lnet_post_send_locked(msg, 0);
lnet_net_unlock(cpt);
if (rc == EHOSTUNREACH || rc == ECANCELED)
return -rc;
if (rc == 0)
lnet_ni_send(src_ni, msg);
return 0;
}
static void
lnet_drop_message(lnet_ni_t *ni, int cpt, void *private, unsigned int nob)
{
lnet_net_lock(cpt);
the_lnet.ln_counters[cpt]->drop_count++;
the_lnet.ln_counters[cpt]->drop_length += nob;
lnet_net_unlock(cpt);
lnet_ni_recv(ni, private, NULL, 0, 0, 0, nob);
}
static void
lnet_recv_put(lnet_ni_t *ni, lnet_msg_t *msg)
{
lnet_hdr_t *hdr = &msg->msg_hdr;
if (msg->msg_wanted != 0)
lnet_setpayloadbuffer(msg);
lnet_build_msg_event(msg, LNET_EVENT_PUT);
msg->msg_ack = (!lnet_is_wire_handle_none(&hdr->msg.put.ack_wmd) &&
(msg->msg_md->md_options & LNET_MD_ACK_DISABLE) == 0);
lnet_ni_recv(ni, msg->msg_private, msg, msg->msg_rx_delayed,
msg->msg_offset, msg->msg_wanted, hdr->payload_length);
}
static int
lnet_parse_put(lnet_ni_t *ni, lnet_msg_t *msg)
{
lnet_hdr_t *hdr = &msg->msg_hdr;
struct lnet_match_info info;
int rc;
hdr->msg.put.match_bits = le64_to_cpu(hdr->msg.put.match_bits);
hdr->msg.put.ptl_index = le32_to_cpu(hdr->msg.put.ptl_index);
hdr->msg.put.offset = le32_to_cpu(hdr->msg.put.offset);
info.mi_id.nid = hdr->src_nid;
info.mi_id.pid = hdr->src_pid;
info.mi_opc = LNET_MD_OP_PUT;
info.mi_portal = hdr->msg.put.ptl_index;
info.mi_rlength = hdr->payload_length;
info.mi_roffset = hdr->msg.put.offset;
info.mi_mbits = hdr->msg.put.match_bits;
msg->msg_rx_ready_delay = ni->ni_lnd->lnd_eager_recv == NULL;
again:
rc = lnet_ptl_match_md(&info, msg);
switch (rc) {
default:
LBUG();
case LNET_MATCHMD_OK:
lnet_recv_put(ni, msg);
return 0;
case LNET_MATCHMD_NONE:
if (msg->msg_rx_delayed)
return 0;
rc = lnet_ni_eager_recv(ni, msg);
if (rc == 0)
goto again;
case LNET_MATCHMD_DROP:
CNETERR("Dropping PUT from %s portal %d match %llu offset %d length %d: %d\n",
libcfs_id2str(info.mi_id), info.mi_portal,
info.mi_mbits, info.mi_roffset, info.mi_rlength, rc);
return ENOENT;
}
}
static int
lnet_parse_get(lnet_ni_t *ni, lnet_msg_t *msg, int rdma_get)
{
struct lnet_match_info info;
lnet_hdr_t *hdr = &msg->msg_hdr;
lnet_handle_wire_t reply_wmd;
int rc;
hdr->msg.get.match_bits = le64_to_cpu(hdr->msg.get.match_bits);
hdr->msg.get.ptl_index = le32_to_cpu(hdr->msg.get.ptl_index);
hdr->msg.get.sink_length = le32_to_cpu(hdr->msg.get.sink_length);
hdr->msg.get.src_offset = le32_to_cpu(hdr->msg.get.src_offset);
info.mi_id.nid = hdr->src_nid;
info.mi_id.pid = hdr->src_pid;
info.mi_opc = LNET_MD_OP_GET;
info.mi_portal = hdr->msg.get.ptl_index;
info.mi_rlength = hdr->msg.get.sink_length;
info.mi_roffset = hdr->msg.get.src_offset;
info.mi_mbits = hdr->msg.get.match_bits;
rc = lnet_ptl_match_md(&info, msg);
if (rc == LNET_MATCHMD_DROP) {
CNETERR("Dropping GET from %s portal %d match %llu offset %d length %d\n",
libcfs_id2str(info.mi_id), info.mi_portal,
info.mi_mbits, info.mi_roffset, info.mi_rlength);
return ENOENT;
}
LASSERT(rc == LNET_MATCHMD_OK);
lnet_build_msg_event(msg, LNET_EVENT_GET);
reply_wmd = hdr->msg.get.return_wmd;
lnet_prep_send(msg, LNET_MSG_REPLY, info.mi_id,
msg->msg_offset, msg->msg_wanted);
msg->msg_hdr.msg.reply.dst_wmd = reply_wmd;
if (rdma_get) {
lnet_ni_recv(ni, msg->msg_private, msg, 0,
msg->msg_offset, msg->msg_len, msg->msg_len);
return 0;
}
lnet_ni_recv(ni, msg->msg_private, NULL, 0, 0, 0, 0);
msg->msg_receiving = 0;
rc = lnet_send(ni->ni_nid, msg, LNET_NID_ANY);
if (rc < 0) {
CERROR("%s: Unable to send REPLY for GET from %s: %d\n",
libcfs_nid2str(ni->ni_nid),
libcfs_id2str(info.mi_id), rc);
lnet_finalize(ni, msg, rc);
}
return 0;
}
static int
lnet_parse_reply(lnet_ni_t *ni, lnet_msg_t *msg)
{
void *private = msg->msg_private;
lnet_hdr_t *hdr = &msg->msg_hdr;
lnet_process_id_t src = {0};
lnet_libmd_t *md;
int rlength;
int mlength;
int cpt;
cpt = lnet_cpt_of_cookie(hdr->msg.reply.dst_wmd.wh_object_cookie);
lnet_res_lock(cpt);
src.nid = hdr->src_nid;
src.pid = hdr->src_pid;
md = lnet_wire_handle2md(&hdr->msg.reply.dst_wmd);
if (md == NULL || md->md_threshold == 0 || md->md_me != NULL) {
CNETERR("%s: Dropping REPLY from %s for %s MD %#llx.%#llx\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(src),
(md == NULL) ? "invalid" : "inactive",
hdr->msg.reply.dst_wmd.wh_interface_cookie,
hdr->msg.reply.dst_wmd.wh_object_cookie);
if (md != NULL && md->md_me != NULL)
CERROR("REPLY MD also attached to portal %d\n",
md->md_me->me_portal);
lnet_res_unlock(cpt);
return ENOENT;
}
LASSERT(md->md_offset == 0);
rlength = hdr->payload_length;
mlength = min_t(uint, rlength, md->md_length);
if (mlength < rlength &&
(md->md_options & LNET_MD_TRUNCATE) == 0) {
CNETERR("%s: Dropping REPLY from %s length %d for MD %#llx would overflow (%d)\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(src),
rlength, hdr->msg.reply.dst_wmd.wh_object_cookie,
mlength);
lnet_res_unlock(cpt);
return ENOENT;
}
CDEBUG(D_NET, "%s: Reply from %s of length %d/%d into md %#llx\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(src),
mlength, rlength, hdr->msg.reply.dst_wmd.wh_object_cookie);
lnet_msg_attach_md(msg, md, 0, mlength);
if (mlength != 0)
lnet_setpayloadbuffer(msg);
lnet_res_unlock(cpt);
lnet_build_msg_event(msg, LNET_EVENT_REPLY);
lnet_ni_recv(ni, private, msg, 0, 0, mlength, rlength);
return 0;
}
static int
lnet_parse_ack(lnet_ni_t *ni, lnet_msg_t *msg)
{
lnet_hdr_t *hdr = &msg->msg_hdr;
lnet_process_id_t src = {0};
lnet_libmd_t *md;
int cpt;
src.nid = hdr->src_nid;
src.pid = hdr->src_pid;
hdr->msg.ack.match_bits = le64_to_cpu(hdr->msg.ack.match_bits);
hdr->msg.ack.mlength = le32_to_cpu(hdr->msg.ack.mlength);
cpt = lnet_cpt_of_cookie(hdr->msg.ack.dst_wmd.wh_object_cookie);
lnet_res_lock(cpt);
md = lnet_wire_handle2md(&hdr->msg.ack.dst_wmd);
if (md == NULL || md->md_threshold == 0 || md->md_me != NULL) {
CDEBUG(D_NET,
"%s: Dropping ACK from %s to %s MD %#llx.%#llx\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(src),
(md == NULL) ? "invalid" : "inactive",
hdr->msg.ack.dst_wmd.wh_interface_cookie,
hdr->msg.ack.dst_wmd.wh_object_cookie);
if (md != NULL && md->md_me != NULL)
CERROR("Source MD also attached to portal %d\n",
md->md_me->me_portal);
lnet_res_unlock(cpt);
return ENOENT;
}
CDEBUG(D_NET, "%s: ACK from %s into md %#llx\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(src),
hdr->msg.ack.dst_wmd.wh_object_cookie);
lnet_msg_attach_md(msg, md, 0, 0);
lnet_res_unlock(cpt);
lnet_build_msg_event(msg, LNET_EVENT_ACK);
lnet_ni_recv(ni, msg->msg_private, msg, 0, 0, 0, msg->msg_len);
return 0;
}
static int
lnet_parse_forward_locked(lnet_ni_t *ni, lnet_msg_t *msg)
{
int rc = 0;
if (msg->msg_rxpeer->lp_rtrcredits <= 0 ||
lnet_msg2bufpool(msg)->rbp_credits <= 0) {
if (ni->ni_lnd->lnd_eager_recv == NULL) {
msg->msg_rx_ready_delay = 1;
} else {
lnet_net_unlock(msg->msg_rx_cpt);
rc = lnet_ni_eager_recv(ni, msg);
lnet_net_lock(msg->msg_rx_cpt);
}
}
if (rc == 0)
rc = lnet_post_routed_recv_locked(msg, 0);
return rc;
}
char *
lnet_msgtyp2str(int type)
{
switch (type) {
case LNET_MSG_ACK:
return "ACK";
case LNET_MSG_PUT:
return "PUT";
case LNET_MSG_GET:
return "GET";
case LNET_MSG_REPLY:
return "REPLY";
case LNET_MSG_HELLO:
return "HELLO";
default:
return "<UNKNOWN>";
}
}
void
lnet_print_hdr(lnet_hdr_t *hdr)
{
lnet_process_id_t src = {0};
lnet_process_id_t dst = {0};
char *type_str = lnet_msgtyp2str(hdr->type);
src.nid = hdr->src_nid;
src.pid = hdr->src_pid;
dst.nid = hdr->dest_nid;
dst.pid = hdr->dest_pid;
CWARN("P3 Header at %p of type %s\n", hdr, type_str);
CWARN(" From %s\n", libcfs_id2str(src));
CWARN(" To %s\n", libcfs_id2str(dst));
switch (hdr->type) {
default:
break;
case LNET_MSG_PUT:
CWARN(" Ptl index %d, ack md %#llx.%#llx, match bits %llu\n",
hdr->msg.put.ptl_index,
hdr->msg.put.ack_wmd.wh_interface_cookie,
hdr->msg.put.ack_wmd.wh_object_cookie,
hdr->msg.put.match_bits);
CWARN(" Length %d, offset %d, hdr data %#llx\n",
hdr->payload_length, hdr->msg.put.offset,
hdr->msg.put.hdr_data);
break;
case LNET_MSG_GET:
CWARN(" Ptl index %d, return md %#llx.%#llx, match bits %llu\n",
hdr->msg.get.ptl_index,
hdr->msg.get.return_wmd.wh_interface_cookie,
hdr->msg.get.return_wmd.wh_object_cookie,
hdr->msg.get.match_bits);
CWARN(" Length %d, src offset %d\n",
hdr->msg.get.sink_length,
hdr->msg.get.src_offset);
break;
case LNET_MSG_ACK:
CWARN(" dst md %#llx.%#llx, manipulated length %d\n",
hdr->msg.ack.dst_wmd.wh_interface_cookie,
hdr->msg.ack.dst_wmd.wh_object_cookie,
hdr->msg.ack.mlength);
break;
case LNET_MSG_REPLY:
CWARN(" dst md %#llx.%#llx, length %d\n",
hdr->msg.reply.dst_wmd.wh_interface_cookie,
hdr->msg.reply.dst_wmd.wh_object_cookie,
hdr->payload_length);
}
}
int
lnet_parse(lnet_ni_t *ni, lnet_hdr_t *hdr, lnet_nid_t from_nid,
void *private, int rdma_req)
{
int rc = 0;
int cpt;
int for_me;
struct lnet_msg *msg;
lnet_pid_t dest_pid;
lnet_nid_t dest_nid;
lnet_nid_t src_nid;
__u32 payload_length;
__u32 type;
LASSERT(!in_interrupt());
type = le32_to_cpu(hdr->type);
src_nid = le64_to_cpu(hdr->src_nid);
dest_nid = le64_to_cpu(hdr->dest_nid);
dest_pid = le32_to_cpu(hdr->dest_pid);
payload_length = le32_to_cpu(hdr->payload_length);
for_me = (ni->ni_nid == dest_nid);
cpt = lnet_cpt_of_nid(from_nid);
switch (type) {
case LNET_MSG_ACK:
case LNET_MSG_GET:
if (payload_length > 0) {
CERROR("%s, src %s: bad %s payload %d (0 expected)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
lnet_msgtyp2str(type), payload_length);
return -EPROTO;
}
break;
case LNET_MSG_PUT:
case LNET_MSG_REPLY:
if (payload_length >
(__u32)(for_me ? LNET_MAX_PAYLOAD : LNET_MTU)) {
CERROR("%s, src %s: bad %s payload %d (%d max expected)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
lnet_msgtyp2str(type),
payload_length,
for_me ? LNET_MAX_PAYLOAD : LNET_MTU);
return -EPROTO;
}
break;
default:
CERROR("%s, src %s: Bad message type 0x%x\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid), type);
return -EPROTO;
}
if (the_lnet.ln_routing &&
ni->ni_last_alive != ktime_get_real_seconds()) {
lnet_ni_lock(ni);
ni->ni_last_alive = ktime_get_real_seconds();
if (ni->ni_status != NULL &&
ni->ni_status->ns_status == LNET_NI_STATUS_DOWN)
ni->ni_status->ns_status = LNET_NI_STATUS_UP;
lnet_ni_unlock(ni);
}
if (!for_me) {
if (LNET_NIDNET(dest_nid) == LNET_NIDNET(ni->ni_nid)) {
CERROR("%s, src %s: Bad dest nid %s (should have been sent direct)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
libcfs_nid2str(dest_nid));
return -EPROTO;
}
if (lnet_islocalnid(dest_nid)) {
CERROR("%s, src %s: Bad dest nid %s (it's my nid but on a different network)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
libcfs_nid2str(dest_nid));
return -EPROTO;
}
if (rdma_req && type == LNET_MSG_GET) {
CERROR("%s, src %s: Bad optimized GET for %s (final destination must be me)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
libcfs_nid2str(dest_nid));
return -EPROTO;
}
if (!the_lnet.ln_routing) {
CERROR("%s, src %s: Dropping message for %s (routing not enabled)\n",
libcfs_nid2str(from_nid),
libcfs_nid2str(src_nid),
libcfs_nid2str(dest_nid));
goto drop;
}
}
if (!list_empty(&the_lnet.ln_test_peers) &&
fail_peer(src_nid, 0)) {
CERROR("%s, src %s: Dropping %s to simulate failure\n",
libcfs_nid2str(from_nid), libcfs_nid2str(src_nid),
lnet_msgtyp2str(type));
goto drop;
}
msg = lnet_msg_alloc();
if (msg == NULL) {
CERROR("%s, src %s: Dropping %s (out of memory)\n",
libcfs_nid2str(from_nid), libcfs_nid2str(src_nid),
lnet_msgtyp2str(type));
goto drop;
}
msg->msg_type = type;
msg->msg_private = private;
msg->msg_receiving = 1;
msg->msg_len = msg->msg_wanted = payload_length;
msg->msg_offset = 0;
msg->msg_hdr = *hdr;
msg->msg_from = from_nid;
if (!for_me) {
msg->msg_target.pid = dest_pid;
msg->msg_target.nid = dest_nid;
msg->msg_routing = 1;
} else {
msg->msg_hdr.type = type;
msg->msg_hdr.src_nid = src_nid;
msg->msg_hdr.src_pid = le32_to_cpu(msg->msg_hdr.src_pid);
msg->msg_hdr.dest_nid = dest_nid;
msg->msg_hdr.dest_pid = dest_pid;
msg->msg_hdr.payload_length = payload_length;
}
lnet_net_lock(cpt);
rc = lnet_nid2peer_locked(&msg->msg_rxpeer, from_nid, cpt);
if (rc != 0) {
lnet_net_unlock(cpt);
CERROR("%s, src %s: Dropping %s (error %d looking up sender)\n",
libcfs_nid2str(from_nid), libcfs_nid2str(src_nid),
lnet_msgtyp2str(type), rc);
lnet_msg_free(msg);
goto drop;
}
if (lnet_isrouter(msg->msg_rxpeer)) {
lnet_peer_set_alive(msg->msg_rxpeer);
if (avoid_asym_router_failure &&
LNET_NIDNET(src_nid) != LNET_NIDNET(from_nid)) {
lnet_router_ni_update_locked(msg->msg_rxpeer,
LNET_NIDNET(src_nid));
}
}
lnet_msg_commit(msg, cpt);
if (!for_me) {
rc = lnet_parse_forward_locked(ni, msg);
lnet_net_unlock(cpt);
if (rc < 0)
goto free_drop;
if (rc == 0) {
lnet_ni_recv(ni, msg->msg_private, msg, 0,
0, payload_length, payload_length);
}
return 0;
}
lnet_net_unlock(cpt);
switch (type) {
case LNET_MSG_ACK:
rc = lnet_parse_ack(ni, msg);
break;
case LNET_MSG_PUT:
rc = lnet_parse_put(ni, msg);
break;
case LNET_MSG_GET:
rc = lnet_parse_get(ni, msg, rdma_req);
break;
case LNET_MSG_REPLY:
rc = lnet_parse_reply(ni, msg);
break;
default:
LASSERT(0);
rc = -EPROTO;
goto free_drop;
}
if (rc == 0)
return 0;
LASSERT(rc == ENOENT);
free_drop:
LASSERT(msg->msg_md == NULL);
lnet_finalize(ni, msg, rc);
drop:
lnet_drop_message(ni, cpt, private, payload_length);
return 0;
}
void
lnet_drop_delayed_msg_list(struct list_head *head, char *reason)
{
while (!list_empty(head)) {
lnet_process_id_t id = {0};
lnet_msg_t *msg;
msg = list_entry(head->next, lnet_msg_t, msg_list);
list_del(&msg->msg_list);
id.nid = msg->msg_hdr.src_nid;
id.pid = msg->msg_hdr.src_pid;
LASSERT(msg->msg_md == NULL);
LASSERT(msg->msg_rx_delayed);
LASSERT(msg->msg_rxpeer != NULL);
LASSERT(msg->msg_hdr.type == LNET_MSG_PUT);
CWARN("Dropping delayed PUT from %s portal %d match %llu offset %d length %d: %s\n",
libcfs_id2str(id),
msg->msg_hdr.msg.put.ptl_index,
msg->msg_hdr.msg.put.match_bits,
msg->msg_hdr.msg.put.offset,
msg->msg_hdr.payload_length, reason);
lnet_drop_message(msg->msg_rxpeer->lp_ni,
msg->msg_rxpeer->lp_cpt,
msg->msg_private, msg->msg_len);
lnet_finalize(msg->msg_rxpeer->lp_ni, msg, -ENOENT);
}
}
void
lnet_recv_delayed_msg_list(struct list_head *head)
{
while (!list_empty(head)) {
lnet_msg_t *msg;
lnet_process_id_t id;
msg = list_entry(head->next, lnet_msg_t, msg_list);
list_del(&msg->msg_list);
id.nid = msg->msg_hdr.src_nid;
id.pid = msg->msg_hdr.src_pid;
LASSERT(msg->msg_rx_delayed);
LASSERT(msg->msg_md != NULL);
LASSERT(msg->msg_rxpeer != NULL);
LASSERT(msg->msg_hdr.type == LNET_MSG_PUT);
CDEBUG(D_NET, "Resuming delayed PUT from %s portal %d match %llu offset %d length %d.\n",
libcfs_id2str(id), msg->msg_hdr.msg.put.ptl_index,
msg->msg_hdr.msg.put.match_bits,
msg->msg_hdr.msg.put.offset,
msg->msg_hdr.payload_length);
lnet_recv_put(msg->msg_rxpeer->lp_ni, msg);
}
}
int
LNetPut(lnet_nid_t self, lnet_handle_md_t mdh, lnet_ack_req_t ack,
lnet_process_id_t target, unsigned int portal,
__u64 match_bits, unsigned int offset,
__u64 hdr_data)
{
struct lnet_msg *msg;
struct lnet_libmd *md;
int cpt;
int rc;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
if (!list_empty(&the_lnet.ln_test_peers) &&
fail_peer(target.nid, 1)) {
CERROR("Dropping PUT to %s: simulated failure\n",
libcfs_id2str(target));
return -EIO;
}
msg = lnet_msg_alloc();
if (msg == NULL) {
CERROR("Dropping PUT to %s: ENOMEM on lnet_msg_t\n",
libcfs_id2str(target));
return -ENOMEM;
}
msg->msg_vmflush = !!memory_pressure_get();
cpt = lnet_cpt_of_cookie(mdh.cookie);
lnet_res_lock(cpt);
md = lnet_handle2md(&mdh);
if (md == NULL || md->md_threshold == 0 || md->md_me != NULL) {
CERROR("Dropping PUT (%llu:%d:%s): MD (%d) invalid\n",
match_bits, portal, libcfs_id2str(target),
md == NULL ? -1 : md->md_threshold);
if (md != NULL && md->md_me != NULL)
CERROR("Source MD also attached to portal %d\n",
md->md_me->me_portal);
lnet_res_unlock(cpt);
lnet_msg_free(msg);
return -ENOENT;
}
CDEBUG(D_NET, "LNetPut -> %s\n", libcfs_id2str(target));
lnet_msg_attach_md(msg, md, 0, 0);
lnet_prep_send(msg, LNET_MSG_PUT, target, 0, md->md_length);
msg->msg_hdr.msg.put.match_bits = cpu_to_le64(match_bits);
msg->msg_hdr.msg.put.ptl_index = cpu_to_le32(portal);
msg->msg_hdr.msg.put.offset = cpu_to_le32(offset);
msg->msg_hdr.msg.put.hdr_data = hdr_data;
if (ack == LNET_ACK_REQ) {
msg->msg_hdr.msg.put.ack_wmd.wh_interface_cookie =
the_lnet.ln_interface_cookie;
msg->msg_hdr.msg.put.ack_wmd.wh_object_cookie =
md->md_lh.lh_cookie;
} else {
msg->msg_hdr.msg.put.ack_wmd.wh_interface_cookie =
LNET_WIRE_HANDLE_COOKIE_NONE;
msg->msg_hdr.msg.put.ack_wmd.wh_object_cookie =
LNET_WIRE_HANDLE_COOKIE_NONE;
}
lnet_res_unlock(cpt);
lnet_build_msg_event(msg, LNET_EVENT_SEND);
rc = lnet_send(self, msg, LNET_NID_ANY);
if (rc != 0) {
CNETERR("Error sending PUT to %s: %d\n",
libcfs_id2str(target), rc);
lnet_finalize(NULL, msg, rc);
}
return 0;
}
lnet_msg_t *
lnet_create_reply_msg(lnet_ni_t *ni, lnet_msg_t *getmsg)
{
struct lnet_msg *msg = lnet_msg_alloc();
struct lnet_libmd *getmd = getmsg->msg_md;
lnet_process_id_t peer_id = getmsg->msg_target;
int cpt;
LASSERT(!getmsg->msg_target_is_router);
LASSERT(!getmsg->msg_routing);
cpt = lnet_cpt_of_cookie(getmd->md_lh.lh_cookie);
lnet_res_lock(cpt);
LASSERT(getmd->md_refcount > 0);
if (msg == NULL) {
CERROR("%s: Dropping REPLY from %s: can't allocate msg\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(peer_id));
goto drop;
}
if (getmd->md_threshold == 0) {
CERROR("%s: Dropping REPLY from %s for inactive MD %p\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(peer_id),
getmd);
lnet_res_unlock(cpt);
goto drop;
}
LASSERT(getmd->md_offset == 0);
CDEBUG(D_NET, "%s: Reply from %s md %p\n",
libcfs_nid2str(ni->ni_nid), libcfs_id2str(peer_id), getmd);
msg->msg_from = peer_id.nid;
msg->msg_type = LNET_MSG_GET;
msg->msg_hdr.src_nid = peer_id.nid;
msg->msg_hdr.payload_length = getmd->md_length;
msg->msg_receiving = 1;
lnet_msg_attach_md(msg, getmd, getmd->md_offset, getmd->md_length);
lnet_res_unlock(cpt);
cpt = lnet_cpt_of_nid(peer_id.nid);
lnet_net_lock(cpt);
lnet_msg_commit(msg, cpt);
lnet_net_unlock(cpt);
lnet_build_msg_event(msg, LNET_EVENT_REPLY);
return msg;
drop:
cpt = lnet_cpt_of_nid(peer_id.nid);
lnet_net_lock(cpt);
the_lnet.ln_counters[cpt]->drop_count++;
the_lnet.ln_counters[cpt]->drop_length += getmd->md_length;
lnet_net_unlock(cpt);
if (msg != NULL)
lnet_msg_free(msg);
return NULL;
}
void
lnet_set_reply_msg_len(lnet_ni_t *ni, lnet_msg_t *reply, unsigned int len)
{
LASSERT(reply != NULL);
LASSERT(reply->msg_type == LNET_MSG_GET);
LASSERT(reply->msg_ev.type == LNET_EVENT_REPLY);
LASSERT(len <= reply->msg_ev.mlength);
reply->msg_ev.mlength = len;
}
int
LNetGet(lnet_nid_t self, lnet_handle_md_t mdh,
lnet_process_id_t target, unsigned int portal,
__u64 match_bits, unsigned int offset)
{
struct lnet_msg *msg;
struct lnet_libmd *md;
int cpt;
int rc;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
if (!list_empty(&the_lnet.ln_test_peers) &&
fail_peer(target.nid, 1)) {
CERROR("Dropping GET to %s: simulated failure\n",
libcfs_id2str(target));
return -EIO;
}
msg = lnet_msg_alloc();
if (msg == NULL) {
CERROR("Dropping GET to %s: ENOMEM on lnet_msg_t\n",
libcfs_id2str(target));
return -ENOMEM;
}
cpt = lnet_cpt_of_cookie(mdh.cookie);
lnet_res_lock(cpt);
md = lnet_handle2md(&mdh);
if (md == NULL || md->md_threshold == 0 || md->md_me != NULL) {
CERROR("Dropping GET (%llu:%d:%s): MD (%d) invalid\n",
match_bits, portal, libcfs_id2str(target),
md == NULL ? -1 : md->md_threshold);
if (md != NULL && md->md_me != NULL)
CERROR("REPLY MD also attached to portal %d\n",
md->md_me->me_portal);
lnet_res_unlock(cpt);
lnet_msg_free(msg);
return -ENOENT;
}
CDEBUG(D_NET, "LNetGet -> %s\n", libcfs_id2str(target));
lnet_msg_attach_md(msg, md, 0, 0);
lnet_prep_send(msg, LNET_MSG_GET, target, 0, 0);
msg->msg_hdr.msg.get.match_bits = cpu_to_le64(match_bits);
msg->msg_hdr.msg.get.ptl_index = cpu_to_le32(portal);
msg->msg_hdr.msg.get.src_offset = cpu_to_le32(offset);
msg->msg_hdr.msg.get.sink_length = cpu_to_le32(md->md_length);
msg->msg_hdr.msg.get.return_wmd.wh_interface_cookie =
the_lnet.ln_interface_cookie;
msg->msg_hdr.msg.get.return_wmd.wh_object_cookie =
md->md_lh.lh_cookie;
lnet_res_unlock(cpt);
lnet_build_msg_event(msg, LNET_EVENT_SEND);
rc = lnet_send(self, msg, LNET_NID_ANY);
if (rc < 0) {
CNETERR("Error sending GET to %s: %d\n",
libcfs_id2str(target), rc);
lnet_finalize(NULL, msg, rc);
}
return 0;
}
int
LNetDist(lnet_nid_t dstnid, lnet_nid_t *srcnidp, __u32 *orderp)
{
struct list_head *e;
struct lnet_ni *ni;
lnet_remotenet_t *rnet;
__u32 dstnet = LNET_NIDNET(dstnid);
int hops;
int cpt;
__u32 order = 2;
struct list_head *rn_list;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
cpt = lnet_net_lock_current();
list_for_each(e, &the_lnet.ln_nis) {
ni = list_entry(e, lnet_ni_t, ni_list);
if (ni->ni_nid == dstnid) {
if (srcnidp != NULL)
*srcnidp = dstnid;
if (orderp != NULL) {
if (LNET_NETTYP(LNET_NIDNET(dstnid)) == LOLND)
*orderp = 0;
else
*orderp = 1;
}
lnet_net_unlock(cpt);
return local_nid_dist_zero ? 0 : 1;
}
if (LNET_NIDNET(ni->ni_nid) == dstnet) {
if (srcnidp != NULL)
*srcnidp = ni->ni_nid;
if (orderp != NULL)
*orderp = order;
lnet_net_unlock(cpt);
return 1;
}
order++;
}
rn_list = lnet_net2rnethash(dstnet);
list_for_each(e, rn_list) {
rnet = list_entry(e, lnet_remotenet_t, lrn_list);
if (rnet->lrn_net == dstnet) {
lnet_route_t *route;
lnet_route_t *shortest = NULL;
LASSERT(!list_empty(&rnet->lrn_routes));
list_for_each_entry(route, &rnet->lrn_routes,
lr_list) {
if (shortest == NULL ||
route->lr_hops < shortest->lr_hops)
shortest = route;
}
LASSERT(shortest != NULL);
hops = shortest->lr_hops;
if (srcnidp != NULL)
*srcnidp = shortest->lr_gateway->lp_ni->ni_nid;
if (orderp != NULL)
*orderp = order;
lnet_net_unlock(cpt);
return hops + 1;
}
order++;
}
lnet_net_unlock(cpt);
return -EHOSTUNREACH;
}
