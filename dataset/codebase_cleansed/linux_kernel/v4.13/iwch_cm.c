static void start_ep_timer(struct iwch_ep *ep)
{
pr_debug("%s ep %p\n", __func__, ep);
if (timer_pending(&ep->timer)) {
pr_debug("%s stopped / restarted timer ep %p\n", __func__, ep);
del_timer_sync(&ep->timer);
} else
get_ep(&ep->com);
ep->timer.expires = jiffies + ep_timeout_secs * HZ;
ep->timer.data = (unsigned long)ep;
ep->timer.function = ep_timeout;
add_timer(&ep->timer);
}
static void stop_ep_timer(struct iwch_ep *ep)
{
pr_debug("%s ep %p\n", __func__, ep);
if (!timer_pending(&ep->timer)) {
WARN(1, "%s timer stopped when its not running! ep %p state %u\n",
__func__, ep, ep->com.state);
return;
}
del_timer_sync(&ep->timer);
put_ep(&ep->com);
}
static int iwch_l2t_send(struct t3cdev *tdev, struct sk_buff *skb, struct l2t_entry *l2e)
{
int error = 0;
struct cxio_rdev *rdev;
rdev = (struct cxio_rdev *)tdev->ulp;
if (cxio_fatal_error(rdev)) {
kfree_skb(skb);
return -EIO;
}
error = l2t_send(tdev, skb, l2e);
if (error < 0)
kfree_skb(skb);
return error < 0 ? error : 0;
}
int iwch_cxgb3_ofld_send(struct t3cdev *tdev, struct sk_buff *skb)
{
int error = 0;
struct cxio_rdev *rdev;
rdev = (struct cxio_rdev *)tdev->ulp;
if (cxio_fatal_error(rdev)) {
kfree_skb(skb);
return -EIO;
}
error = cxgb3_ofld_send(tdev, skb);
if (error < 0)
kfree_skb(skb);
return error < 0 ? error : 0;
}
static void release_tid(struct t3cdev *tdev, u32 hwtid, struct sk_buff *skb)
{
struct cpl_tid_release *req;
skb = get_skb(skb, sizeof *req, GFP_KERNEL);
if (!skb)
return;
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_TID_RELEASE, hwtid));
skb->priority = CPL_PRIORITY_SETUP;
iwch_cxgb3_ofld_send(tdev, skb);
return;
}
int iwch_quiesce_tid(struct iwch_ep *ep)
{
struct cpl_set_tcb_field *req;
struct sk_buff *skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
req->wr.wr_lo = htonl(V_WR_TID(ep->hwtid));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_SET_TCB_FIELD, ep->hwtid));
req->reply = 0;
req->cpu_idx = 0;
req->word = htons(W_TCB_RX_QUIESCE);
req->mask = cpu_to_be64(1ULL << S_TCB_RX_QUIESCE);
req->val = cpu_to_be64(1 << S_TCB_RX_QUIESCE);
skb->priority = CPL_PRIORITY_DATA;
return iwch_cxgb3_ofld_send(ep->com.tdev, skb);
}
int iwch_resume_tid(struct iwch_ep *ep)
{
struct cpl_set_tcb_field *req;
struct sk_buff *skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
req->wr.wr_lo = htonl(V_WR_TID(ep->hwtid));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_SET_TCB_FIELD, ep->hwtid));
req->reply = 0;
req->cpu_idx = 0;
req->word = htons(W_TCB_RX_QUIESCE);
req->mask = cpu_to_be64(1ULL << S_TCB_RX_QUIESCE);
req->val = 0;
skb->priority = CPL_PRIORITY_DATA;
return iwch_cxgb3_ofld_send(ep->com.tdev, skb);
}
static void set_emss(struct iwch_ep *ep, u16 opt)
{
pr_debug("%s ep %p opt %u\n", __func__, ep, opt);
ep->emss = T3C_DATA(ep->com.tdev)->mtus[G_TCPOPT_MSS(opt)] - 40;
if (G_TCPOPT_TSTAMP(opt))
ep->emss -= 12;
if (ep->emss < 128)
ep->emss = 128;
pr_debug("emss=%d\n", ep->emss);
}
static enum iwch_ep_state state_read(struct iwch_ep_common *epc)
{
unsigned long flags;
enum iwch_ep_state state;
spin_lock_irqsave(&epc->lock, flags);
state = epc->state;
spin_unlock_irqrestore(&epc->lock, flags);
return state;
}
static void __state_set(struct iwch_ep_common *epc, enum iwch_ep_state new)
{
epc->state = new;
}
static void state_set(struct iwch_ep_common *epc, enum iwch_ep_state new)
{
unsigned long flags;
spin_lock_irqsave(&epc->lock, flags);
pr_debug("%s - %s -> %s\n", __func__, states[epc->state], states[new]);
__state_set(epc, new);
spin_unlock_irqrestore(&epc->lock, flags);
return;
}
static void *alloc_ep(int size, gfp_t gfp)
{
struct iwch_ep_common *epc;
epc = kzalloc(size, gfp);
if (epc) {
kref_init(&epc->kref);
spin_lock_init(&epc->lock);
init_waitqueue_head(&epc->waitq);
}
pr_debug("%s alloc ep %p\n", __func__, epc);
return epc;
}
void __free_ep(struct kref *kref)
{
struct iwch_ep *ep;
ep = container_of(container_of(kref, struct iwch_ep_common, kref),
struct iwch_ep, com);
pr_debug("%s ep %p state %s\n",
__func__, ep, states[state_read(&ep->com)]);
if (test_bit(RELEASE_RESOURCES, &ep->com.flags)) {
cxgb3_remove_tid(ep->com.tdev, (void *)ep, ep->hwtid);
dst_release(ep->dst);
l2t_release(ep->com.tdev, ep->l2t);
}
kfree(ep);
}
static void release_ep_resources(struct iwch_ep *ep)
{
pr_debug("%s ep %p tid %d\n", __func__, ep, ep->hwtid);
set_bit(RELEASE_RESOURCES, &ep->com.flags);
put_ep(&ep->com);
}
static int status2errno(int status)
{
switch (status) {
case CPL_ERR_NONE:
return 0;
case CPL_ERR_CONN_RESET:
return -ECONNRESET;
case CPL_ERR_ARP_MISS:
return -EHOSTUNREACH;
case CPL_ERR_CONN_TIMEDOUT:
return -ETIMEDOUT;
case CPL_ERR_TCAM_FULL:
return -ENOMEM;
case CPL_ERR_CONN_EXIST:
return -EADDRINUSE;
default:
return -EIO;
}
}
static struct sk_buff *get_skb(struct sk_buff *skb, int len, gfp_t gfp)
{
if (skb && !skb_is_nonlinear(skb) && !skb_cloned(skb)) {
skb_trim(skb, 0);
skb_get(skb);
} else {
skb = alloc_skb(len, gfp);
}
return skb;
}
static struct rtable *find_route(struct t3cdev *dev, __be32 local_ip,
__be32 peer_ip, __be16 local_port,
__be16 peer_port, u8 tos)
{
struct rtable *rt;
struct flowi4 fl4;
rt = ip_route_output_ports(&init_net, &fl4, NULL, peer_ip, local_ip,
peer_port, local_port, IPPROTO_TCP,
tos, 0);
if (IS_ERR(rt))
return NULL;
return rt;
}
static unsigned int find_best_mtu(const struct t3c_data *d, unsigned short mtu)
{
int i = 0;
while (i < d->nmtus - 1 && d->mtus[i + 1] <= mtu)
++i;
return i;
}
static void arp_failure_discard(struct t3cdev *dev, struct sk_buff *skb)
{
pr_debug("%s t3cdev %p\n", __func__, dev);
kfree_skb(skb);
}
static void act_open_req_arp_failure(struct t3cdev *dev, struct sk_buff *skb)
{
pr_err("ARP failure during connect\n");
kfree_skb(skb);
}
static void abort_arp_failure(struct t3cdev *dev, struct sk_buff *skb)
{
struct cpl_abort_req *req = cplhdr(skb);
pr_debug("%s t3cdev %p\n", __func__, dev);
req->cmd = CPL_ABORT_NO_RST;
iwch_cxgb3_ofld_send(dev, skb);
}
static int send_halfclose(struct iwch_ep *ep, gfp_t gfp)
{
struct cpl_close_con_req *req;
struct sk_buff *skb;
pr_debug("%s ep %p\n", __func__, ep);
skb = get_skb(NULL, sizeof(*req), gfp);
if (!skb) {
pr_err("%s - failed to alloc skb\n", __func__);
return -ENOMEM;
}
skb->priority = CPL_PRIORITY_DATA;
set_arp_failure_handler(skb, arp_failure_discard);
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_CLOSE_CON));
req->wr.wr_lo = htonl(V_WR_TID(ep->hwtid));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_CLOSE_CON_REQ, ep->hwtid));
return iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
}
static int send_abort(struct iwch_ep *ep, struct sk_buff *skb, gfp_t gfp)
{
struct cpl_abort_req *req;
pr_debug("%s ep %p\n", __func__, ep);
skb = get_skb(skb, sizeof(*req), gfp);
if (!skb) {
pr_err("%s - failed to alloc skb\n", __func__);
return -ENOMEM;
}
skb->priority = CPL_PRIORITY_DATA;
set_arp_failure_handler(skb, abort_arp_failure);
req = skb_put_zero(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_HOST_ABORT_CON_REQ));
req->wr.wr_lo = htonl(V_WR_TID(ep->hwtid));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_ABORT_REQ, ep->hwtid));
req->cmd = CPL_ABORT_SEND_RST;
return iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
}
static int send_connect(struct iwch_ep *ep)
{
struct cpl_act_open_req *req;
struct sk_buff *skb;
u32 opt0h, opt0l, opt2;
unsigned int mtu_idx;
int wscale;
pr_debug("%s ep %p\n", __func__, ep);
skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("%s - failed to alloc skb\n", __func__);
return -ENOMEM;
}
mtu_idx = find_best_mtu(T3C_DATA(ep->com.tdev), dst_mtu(ep->dst));
wscale = compute_wscale(rcv_win);
opt0h = V_NAGLE(0) |
V_NO_CONG(nocong) |
V_KEEP_ALIVE(1) |
F_TCAM_BYPASS |
V_WND_SCALE(wscale) |
V_MSS_IDX(mtu_idx) |
V_L2T_IDX(ep->l2t->idx) | V_TX_CHANNEL(ep->l2t->smt_idx);
opt0l = V_TOS((ep->tos >> 2) & M_TOS) | V_RCV_BUFSIZ(rcv_win>>10);
opt2 = F_RX_COALESCE_VALID | V_RX_COALESCE(0) | V_FLAVORS_VALID(1) |
V_CONG_CONTROL_FLAVOR(cong_flavor);
skb->priority = CPL_PRIORITY_SETUP;
set_arp_failure_handler(skb, act_open_req_arp_failure);
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_ACT_OPEN_REQ, ep->atid));
req->local_port = ep->com.local_addr.sin_port;
req->peer_port = ep->com.remote_addr.sin_port;
req->local_ip = ep->com.local_addr.sin_addr.s_addr;
req->peer_ip = ep->com.remote_addr.sin_addr.s_addr;
req->opt0h = htonl(opt0h);
req->opt0l = htonl(opt0l);
req->params = 0;
req->opt2 = htonl(opt2);
return iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
}
static void send_mpa_req(struct iwch_ep *ep, struct sk_buff *skb)
{
int mpalen;
struct tx_data_wr *req;
struct mpa_message *mpa;
int len;
pr_debug("%s ep %p pd_len %d\n", __func__, ep, ep->plen);
BUG_ON(skb_cloned(skb));
mpalen = sizeof(*mpa) + ep->plen;
if (skb->data + mpalen + sizeof(*req) > skb_end_pointer(skb)) {
kfree_skb(skb);
skb=alloc_skb(mpalen + sizeof(*req), GFP_KERNEL);
if (!skb) {
connect_reply_upcall(ep, -ENOMEM);
return;
}
}
skb_trim(skb, 0);
skb_reserve(skb, sizeof(*req));
skb_put(skb, mpalen);
skb->priority = CPL_PRIORITY_DATA;
mpa = (struct mpa_message *) skb->data;
memset(mpa, 0, sizeof(*mpa));
memcpy(mpa->key, MPA_KEY_REQ, sizeof(mpa->key));
mpa->flags = (crc_enabled ? MPA_CRC : 0) |
(markers_enabled ? MPA_MARKERS : 0);
mpa->private_data_size = htons(ep->plen);
mpa->revision = mpa_rev;
if (ep->plen)
memcpy(mpa->private_data, ep->mpa_pkt + sizeof(*mpa), ep->plen);
skb_get(skb);
set_arp_failure_handler(skb, arp_failure_discard);
skb_reset_transport_header(skb);
len = skb->len;
req = skb_push(skb, sizeof(*req));
req->wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_TX_DATA)|F_WR_COMPL);
req->wr_lo = htonl(V_WR_TID(ep->hwtid));
req->len = htonl(len);
req->param = htonl(V_TX_PORT(ep->l2t->smt_idx) |
V_TX_SNDBUF(snd_win>>15));
req->flags = htonl(F_TX_INIT);
req->sndseq = htonl(ep->snd_seq);
BUG_ON(ep->mpa_skb);
ep->mpa_skb = skb;
iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
start_ep_timer(ep);
state_set(&ep->com, MPA_REQ_SENT);
return;
}
static int send_mpa_reject(struct iwch_ep *ep, const void *pdata, u8 plen)
{
int mpalen;
struct tx_data_wr *req;
struct mpa_message *mpa;
struct sk_buff *skb;
pr_debug("%s ep %p plen %d\n", __func__, ep, plen);
mpalen = sizeof(*mpa) + plen;
skb = get_skb(NULL, mpalen + sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("%s - cannot alloc skb!\n", __func__);
return -ENOMEM;
}
skb_reserve(skb, sizeof(*req));
mpa = skb_put(skb, mpalen);
memset(mpa, 0, sizeof(*mpa));
memcpy(mpa->key, MPA_KEY_REP, sizeof(mpa->key));
mpa->flags = MPA_REJECT;
mpa->revision = mpa_rev;
mpa->private_data_size = htons(plen);
if (plen)
memcpy(mpa->private_data, pdata, plen);
skb_get(skb);
skb->priority = CPL_PRIORITY_DATA;
set_arp_failure_handler(skb, arp_failure_discard);
skb_reset_transport_header(skb);
req = skb_push(skb, sizeof(*req));
req->wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_TX_DATA)|F_WR_COMPL);
req->wr_lo = htonl(V_WR_TID(ep->hwtid));
req->len = htonl(mpalen);
req->param = htonl(V_TX_PORT(ep->l2t->smt_idx) |
V_TX_SNDBUF(snd_win>>15));
req->flags = htonl(F_TX_INIT);
req->sndseq = htonl(ep->snd_seq);
BUG_ON(ep->mpa_skb);
ep->mpa_skb = skb;
return iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
}
static int send_mpa_reply(struct iwch_ep *ep, const void *pdata, u8 plen)
{
int mpalen;
struct tx_data_wr *req;
struct mpa_message *mpa;
int len;
struct sk_buff *skb;
pr_debug("%s ep %p plen %d\n", __func__, ep, plen);
mpalen = sizeof(*mpa) + plen;
skb = get_skb(NULL, mpalen + sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("%s - cannot alloc skb!\n", __func__);
return -ENOMEM;
}
skb->priority = CPL_PRIORITY_DATA;
skb_reserve(skb, sizeof(*req));
mpa = skb_put(skb, mpalen);
memset(mpa, 0, sizeof(*mpa));
memcpy(mpa->key, MPA_KEY_REP, sizeof(mpa->key));
mpa->flags = (ep->mpa_attr.crc_enabled ? MPA_CRC : 0) |
(markers_enabled ? MPA_MARKERS : 0);
mpa->revision = mpa_rev;
mpa->private_data_size = htons(plen);
if (plen)
memcpy(mpa->private_data, pdata, plen);
skb_get(skb);
set_arp_failure_handler(skb, arp_failure_discard);
skb_reset_transport_header(skb);
len = skb->len;
req = skb_push(skb, sizeof(*req));
req->wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_TX_DATA)|F_WR_COMPL);
req->wr_lo = htonl(V_WR_TID(ep->hwtid));
req->len = htonl(len);
req->param = htonl(V_TX_PORT(ep->l2t->smt_idx) |
V_TX_SNDBUF(snd_win>>15));
req->flags = htonl(F_TX_INIT);
req->sndseq = htonl(ep->snd_seq);
ep->mpa_skb = skb;
state_set(&ep->com, MPA_REP_SENT);
return iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
}
static int act_establish(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct cpl_act_establish *req = cplhdr(skb);
unsigned int tid = GET_TID(req);
pr_debug("%s ep %p tid %d\n", __func__, ep, tid);
dst_confirm(ep->dst);
ep->hwtid = tid;
cxgb3_insert_tid(ep->com.tdev, &t3c_client, ep, tid);
ep->snd_seq = ntohl(req->snd_isn);
ep->rcv_seq = ntohl(req->rcv_isn);
set_emss(ep, ntohs(req->tcp_opt));
cxgb3_free_atid(ep->com.tdev, ep->atid);
send_mpa_req(ep, skb);
return 0;
}
static void abort_connection(struct iwch_ep *ep, struct sk_buff *skb, gfp_t gfp)
{
pr_debug("%s ep %p\n", __FILE__, ep);
state_set(&ep->com, ABORTING);
send_abort(ep, skb, gfp);
}
static void close_complete_upcall(struct iwch_ep *ep)
{
struct iw_cm_event event;
pr_debug("%s ep %p\n", __func__, ep);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_CLOSE;
if (ep->com.cm_id) {
pr_debug("close complete delivered ep %p cm_id %p tid %d\n",
ep, ep->com.cm_id, ep->hwtid);
ep->com.cm_id->event_handler(ep->com.cm_id, &event);
ep->com.cm_id->rem_ref(ep->com.cm_id);
ep->com.cm_id = NULL;
ep->com.qp = NULL;
}
}
static void peer_close_upcall(struct iwch_ep *ep)
{
struct iw_cm_event event;
pr_debug("%s ep %p\n", __func__, ep);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_DISCONNECT;
if (ep->com.cm_id) {
pr_debug("peer close delivered ep %p cm_id %p tid %d\n",
ep, ep->com.cm_id, ep->hwtid);
ep->com.cm_id->event_handler(ep->com.cm_id, &event);
}
}
static void peer_abort_upcall(struct iwch_ep *ep)
{
struct iw_cm_event event;
pr_debug("%s ep %p\n", __func__, ep);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_CLOSE;
event.status = -ECONNRESET;
if (ep->com.cm_id) {
pr_debug("abort delivered ep %p cm_id %p tid %d\n", ep,
ep->com.cm_id, ep->hwtid);
ep->com.cm_id->event_handler(ep->com.cm_id, &event);
ep->com.cm_id->rem_ref(ep->com.cm_id);
ep->com.cm_id = NULL;
ep->com.qp = NULL;
}
}
static void connect_reply_upcall(struct iwch_ep *ep, int status)
{
struct iw_cm_event event;
pr_debug("%s ep %p status %d\n", __func__, ep, status);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_CONNECT_REPLY;
event.status = status;
memcpy(&event.local_addr, &ep->com.local_addr,
sizeof(ep->com.local_addr));
memcpy(&event.remote_addr, &ep->com.remote_addr,
sizeof(ep->com.remote_addr));
if ((status == 0) || (status == -ECONNREFUSED)) {
event.private_data_len = ep->plen;
event.private_data = ep->mpa_pkt + sizeof(struct mpa_message);
}
if (ep->com.cm_id) {
pr_debug("%s ep %p tid %d status %d\n", __func__, ep,
ep->hwtid, status);
ep->com.cm_id->event_handler(ep->com.cm_id, &event);
}
if (status < 0) {
ep->com.cm_id->rem_ref(ep->com.cm_id);
ep->com.cm_id = NULL;
ep->com.qp = NULL;
}
}
static void connect_request_upcall(struct iwch_ep *ep)
{
struct iw_cm_event event;
pr_debug("%s ep %p tid %d\n", __func__, ep, ep->hwtid);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_CONNECT_REQUEST;
memcpy(&event.local_addr, &ep->com.local_addr,
sizeof(ep->com.local_addr));
memcpy(&event.remote_addr, &ep->com.remote_addr,
sizeof(ep->com.local_addr));
event.private_data_len = ep->plen;
event.private_data = ep->mpa_pkt + sizeof(struct mpa_message);
event.provider_data = ep;
event.ird = event.ord = 8;
if (state_read(&ep->parent_ep->com) != DEAD) {
get_ep(&ep->com);
ep->parent_ep->com.cm_id->event_handler(
ep->parent_ep->com.cm_id,
&event);
}
put_ep(&ep->parent_ep->com);
ep->parent_ep = NULL;
}
static void established_upcall(struct iwch_ep *ep)
{
struct iw_cm_event event;
pr_debug("%s ep %p\n", __func__, ep);
memset(&event, 0, sizeof(event));
event.event = IW_CM_EVENT_ESTABLISHED;
event.ird = event.ord = 8;
if (ep->com.cm_id) {
pr_debug("%s ep %p tid %d\n", __func__, ep, ep->hwtid);
ep->com.cm_id->event_handler(ep->com.cm_id, &event);
}
}
static int update_rx_credits(struct iwch_ep *ep, u32 credits)
{
struct cpl_rx_data_ack *req;
struct sk_buff *skb;
pr_debug("%s ep %p credits %u\n", __func__, ep, credits);
skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("update_rx_credits - cannot alloc skb!\n");
return 0;
}
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_RX_DATA_ACK, ep->hwtid));
req->credit_dack = htonl(V_RX_CREDITS(credits) | V_RX_FORCE_ACK(1));
skb->priority = CPL_PRIORITY_ACK;
iwch_cxgb3_ofld_send(ep->com.tdev, skb);
return credits;
}
static void process_mpa_reply(struct iwch_ep *ep, struct sk_buff *skb)
{
struct mpa_message *mpa;
u16 plen;
struct iwch_qp_attributes attrs;
enum iwch_qp_attr_mask mask;
int err;
pr_debug("%s ep %p\n", __func__, ep);
stop_ep_timer(ep);
if (state_read(&ep->com) != MPA_REQ_SENT)
return;
if (ep->mpa_pkt_len + skb->len > sizeof(ep->mpa_pkt)) {
err = -EINVAL;
goto err;
}
skb_copy_from_linear_data(skb, &(ep->mpa_pkt[ep->mpa_pkt_len]),
skb->len);
ep->mpa_pkt_len += skb->len;
if (ep->mpa_pkt_len < sizeof(*mpa))
return;
mpa = (struct mpa_message *) ep->mpa_pkt;
if (mpa->revision != mpa_rev) {
err = -EPROTO;
goto err;
}
if (memcmp(mpa->key, MPA_KEY_REP, sizeof(mpa->key))) {
err = -EPROTO;
goto err;
}
plen = ntohs(mpa->private_data_size);
if (plen > MPA_MAX_PRIVATE_DATA) {
err = -EPROTO;
goto err;
}
if (ep->mpa_pkt_len > (sizeof(*mpa) + plen)) {
err = -EPROTO;
goto err;
}
ep->plen = (u8) plen;
if (ep->mpa_pkt_len < (sizeof(*mpa) + plen))
return;
if (mpa->flags & MPA_REJECT) {
err = -ECONNREFUSED;
goto err;
}
state_set(&ep->com, FPDU_MODE);
ep->mpa_attr.initiator = 1;
ep->mpa_attr.crc_enabled = (mpa->flags & MPA_CRC) | crc_enabled ? 1 : 0;
ep->mpa_attr.recv_marker_enabled = markers_enabled;
ep->mpa_attr.xmit_marker_enabled = mpa->flags & MPA_MARKERS ? 1 : 0;
ep->mpa_attr.version = mpa_rev;
pr_debug("%s - crc_enabled=%d, recv_marker_enabled=%d, xmit_marker_enabled=%d, version=%d\n",
__func__,
ep->mpa_attr.crc_enabled, ep->mpa_attr.recv_marker_enabled,
ep->mpa_attr.xmit_marker_enabled, ep->mpa_attr.version);
attrs.mpa_attr = ep->mpa_attr;
attrs.max_ird = ep->ird;
attrs.max_ord = ep->ord;
attrs.llp_stream_handle = ep;
attrs.next_state = IWCH_QP_STATE_RTS;
mask = IWCH_QP_ATTR_NEXT_STATE |
IWCH_QP_ATTR_LLP_STREAM_HANDLE | IWCH_QP_ATTR_MPA_ATTR |
IWCH_QP_ATTR_MAX_IRD | IWCH_QP_ATTR_MAX_ORD;
err = iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp, mask, &attrs, 1);
if (err)
goto err;
if (peer2peer && iwch_rqes_posted(ep->com.qp) == 0) {
iwch_post_zb_read(ep);
}
goto out;
err:
abort_connection(ep, skb, GFP_KERNEL);
out:
connect_reply_upcall(ep, err);
return;
}
static void process_mpa_request(struct iwch_ep *ep, struct sk_buff *skb)
{
struct mpa_message *mpa;
u16 plen;
pr_debug("%s ep %p\n", __func__, ep);
stop_ep_timer(ep);
if (state_read(&ep->com) != MPA_REQ_WAIT)
return;
if (ep->mpa_pkt_len + skb->len > sizeof(ep->mpa_pkt)) {
abort_connection(ep, skb, GFP_KERNEL);
return;
}
pr_debug("%s enter (%s line %u)\n", __func__, __FILE__, __LINE__);
skb_copy_from_linear_data(skb, &(ep->mpa_pkt[ep->mpa_pkt_len]),
skb->len);
ep->mpa_pkt_len += skb->len;
if (ep->mpa_pkt_len < sizeof(*mpa))
return;
pr_debug("%s enter (%s line %u)\n", __func__, __FILE__, __LINE__);
mpa = (struct mpa_message *) ep->mpa_pkt;
if (mpa->revision != mpa_rev) {
abort_connection(ep, skb, GFP_KERNEL);
return;
}
if (memcmp(mpa->key, MPA_KEY_REQ, sizeof(mpa->key))) {
abort_connection(ep, skb, GFP_KERNEL);
return;
}
plen = ntohs(mpa->private_data_size);
if (plen > MPA_MAX_PRIVATE_DATA) {
abort_connection(ep, skb, GFP_KERNEL);
return;
}
if (ep->mpa_pkt_len > (sizeof(*mpa) + plen)) {
abort_connection(ep, skb, GFP_KERNEL);
return;
}
ep->plen = (u8) plen;
if (ep->mpa_pkt_len < (sizeof(*mpa) + plen))
return;
ep->mpa_attr.initiator = 0;
ep->mpa_attr.crc_enabled = (mpa->flags & MPA_CRC) | crc_enabled ? 1 : 0;
ep->mpa_attr.recv_marker_enabled = markers_enabled;
ep->mpa_attr.xmit_marker_enabled = mpa->flags & MPA_MARKERS ? 1 : 0;
ep->mpa_attr.version = mpa_rev;
pr_debug("%s - crc_enabled=%d, recv_marker_enabled=%d, xmit_marker_enabled=%d, version=%d\n",
__func__,
ep->mpa_attr.crc_enabled, ep->mpa_attr.recv_marker_enabled,
ep->mpa_attr.xmit_marker_enabled, ep->mpa_attr.version);
state_set(&ep->com, MPA_REQ_RCVD);
connect_request_upcall(ep);
return;
}
static int rx_data(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct cpl_rx_data *hdr = cplhdr(skb);
unsigned int dlen = ntohs(hdr->len);
pr_debug("%s ep %p dlen %u\n", __func__, ep, dlen);
skb_pull(skb, sizeof(*hdr));
skb_trim(skb, dlen);
ep->rcv_seq += dlen;
BUG_ON(ep->rcv_seq != (ntohl(hdr->seq) + dlen));
switch (state_read(&ep->com)) {
case MPA_REQ_SENT:
process_mpa_reply(ep, skb);
break;
case MPA_REQ_WAIT:
process_mpa_request(ep, skb);
break;
case MPA_REP_SENT:
break;
default:
pr_err("%s Unexpected streaming data. ep %p state %d tid %d\n",
__func__, ep, state_read(&ep->com), ep->hwtid);
break;
}
update_rx_credits(ep, dlen);
return CPL_RET_BUF_DONE;
}
static int tx_ack(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct cpl_wr_ack *hdr = cplhdr(skb);
unsigned int credits = ntohs(hdr->credits);
unsigned long flags;
int post_zb = 0;
pr_debug("%s ep %p credits %u\n", __func__, ep, credits);
if (credits == 0) {
pr_debug("%s 0 credit ack ep %p state %u\n",
__func__, ep, state_read(&ep->com));
return CPL_RET_BUF_DONE;
}
spin_lock_irqsave(&ep->com.lock, flags);
BUG_ON(credits != 1);
dst_confirm(ep->dst);
if (!ep->mpa_skb) {
pr_debug("%s rdma_init wr_ack ep %p state %u\n",
__func__, ep, ep->com.state);
if (ep->mpa_attr.initiator) {
pr_debug("%s initiator ep %p state %u\n",
__func__, ep, ep->com.state);
if (peer2peer && ep->com.state == FPDU_MODE)
post_zb = 1;
} else {
pr_debug("%s responder ep %p state %u\n",
__func__, ep, ep->com.state);
if (ep->com.state == MPA_REQ_RCVD) {
ep->com.rpl_done = 1;
wake_up(&ep->com.waitq);
}
}
} else {
pr_debug("%s lsm ack ep %p state %u freeing skb\n",
__func__, ep, ep->com.state);
kfree_skb(ep->mpa_skb);
ep->mpa_skb = NULL;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (post_zb)
iwch_post_zb_read(ep);
return CPL_RET_BUF_DONE;
}
static int abort_rpl(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
unsigned long flags;
int release = 0;
pr_debug("%s ep %p\n", __func__, ep);
BUG_ON(!ep);
if (!test_and_set_bit(ABORT_REQ_IN_PROGRESS, &ep->com.flags)) {
return CPL_RET_BUF_DONE;
}
spin_lock_irqsave(&ep->com.lock, flags);
switch (ep->com.state) {
case ABORTING:
close_complete_upcall(ep);
__state_set(&ep->com, DEAD);
release = 1;
break;
default:
pr_err("%s ep %p state %d\n", __func__, ep, ep->com.state);
break;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (release)
release_ep_resources(ep);
return CPL_RET_BUF_DONE;
}
static inline int act_open_has_tid(int status)
{
return status != CPL_ERR_TCAM_FULL && status != CPL_ERR_CONN_EXIST &&
status != CPL_ERR_ARP_MISS;
}
static int act_open_rpl(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct cpl_act_open_rpl *rpl = cplhdr(skb);
pr_debug("%s ep %p status %u errno %d\n", __func__, ep, rpl->status,
status2errno(rpl->status));
connect_reply_upcall(ep, status2errno(rpl->status));
state_set(&ep->com, DEAD);
if (ep->com.tdev->type != T3A && act_open_has_tid(rpl->status))
release_tid(ep->com.tdev, GET_TID(rpl), NULL);
cxgb3_free_atid(ep->com.tdev, ep->atid);
dst_release(ep->dst);
l2t_release(ep->com.tdev, ep->l2t);
put_ep(&ep->com);
return CPL_RET_BUF_DONE;
}
static int listen_start(struct iwch_listen_ep *ep)
{
struct sk_buff *skb;
struct cpl_pass_open_req *req;
pr_debug("%s ep %p\n", __func__, ep);
skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("t3c_listen_start failed to alloc skb!\n");
return -ENOMEM;
}
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_PASS_OPEN_REQ, ep->stid));
req->local_port = ep->com.local_addr.sin_port;
req->local_ip = ep->com.local_addr.sin_addr.s_addr;
req->peer_port = 0;
req->peer_ip = 0;
req->peer_netmask = 0;
req->opt0h = htonl(F_DELACK | F_TCAM_BYPASS);
req->opt0l = htonl(V_RCV_BUFSIZ(rcv_win>>10));
req->opt1 = htonl(V_CONN_POLICY(CPL_CONN_POLICY_ASK));
skb->priority = 1;
return iwch_cxgb3_ofld_send(ep->com.tdev, skb);
}
static int pass_open_rpl(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_listen_ep *ep = ctx;
struct cpl_pass_open_rpl *rpl = cplhdr(skb);
pr_debug("%s ep %p status %d error %d\n", __func__, ep,
rpl->status, status2errno(rpl->status));
ep->com.rpl_err = status2errno(rpl->status);
ep->com.rpl_done = 1;
wake_up(&ep->com.waitq);
return CPL_RET_BUF_DONE;
}
static int listen_stop(struct iwch_listen_ep *ep)
{
struct sk_buff *skb;
struct cpl_close_listserv_req *req;
pr_debug("%s ep %p\n", __func__, ep);
skb = get_skb(NULL, sizeof(*req), GFP_KERNEL);
if (!skb) {
pr_err("%s - failed to alloc skb\n", __func__);
return -ENOMEM;
}
req = skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
req->cpu_idx = 0;
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_CLOSE_LISTSRV_REQ, ep->stid));
skb->priority = 1;
return iwch_cxgb3_ofld_send(ep->com.tdev, skb);
}
static int close_listsrv_rpl(struct t3cdev *tdev, struct sk_buff *skb,
void *ctx)
{
struct iwch_listen_ep *ep = ctx;
struct cpl_close_listserv_rpl *rpl = cplhdr(skb);
pr_debug("%s ep %p\n", __func__, ep);
ep->com.rpl_err = status2errno(rpl->status);
ep->com.rpl_done = 1;
wake_up(&ep->com.waitq);
return CPL_RET_BUF_DONE;
}
static void accept_cr(struct iwch_ep *ep, __be32 peer_ip, struct sk_buff *skb)
{
struct cpl_pass_accept_rpl *rpl;
unsigned int mtu_idx;
u32 opt0h, opt0l, opt2;
int wscale;
pr_debug("%s ep %p\n", __func__, ep);
BUG_ON(skb_cloned(skb));
skb_trim(skb, sizeof(*rpl));
skb_get(skb);
mtu_idx = find_best_mtu(T3C_DATA(ep->com.tdev), dst_mtu(ep->dst));
wscale = compute_wscale(rcv_win);
opt0h = V_NAGLE(0) |
V_NO_CONG(nocong) |
V_KEEP_ALIVE(1) |
F_TCAM_BYPASS |
V_WND_SCALE(wscale) |
V_MSS_IDX(mtu_idx) |
V_L2T_IDX(ep->l2t->idx) | V_TX_CHANNEL(ep->l2t->smt_idx);
opt0l = V_TOS((ep->tos >> 2) & M_TOS) | V_RCV_BUFSIZ(rcv_win>>10);
opt2 = F_RX_COALESCE_VALID | V_RX_COALESCE(0) | V_FLAVORS_VALID(1) |
V_CONG_CONTROL_FLAVOR(cong_flavor);
rpl = cplhdr(skb);
rpl->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(rpl) = htonl(MK_OPCODE_TID(CPL_PASS_ACCEPT_RPL, ep->hwtid));
rpl->peer_ip = peer_ip;
rpl->opt0h = htonl(opt0h);
rpl->opt0l_status = htonl(opt0l | CPL_PASS_OPEN_ACCEPT);
rpl->opt2 = htonl(opt2);
rpl->rsvd = rpl->opt2;
skb->priority = CPL_PRIORITY_SETUP;
iwch_l2t_send(ep->com.tdev, skb, ep->l2t);
return;
}
static void reject_cr(struct t3cdev *tdev, u32 hwtid, __be32 peer_ip,
struct sk_buff *skb)
{
pr_debug("%s t3cdev %p tid %u peer_ip %x\n", __func__, tdev, hwtid,
peer_ip);
BUG_ON(skb_cloned(skb));
skb_trim(skb, sizeof(struct cpl_tid_release));
skb_get(skb);
if (tdev->type != T3A)
release_tid(tdev, hwtid, skb);
else {
struct cpl_pass_accept_rpl *rpl;
rpl = cplhdr(skb);
skb->priority = CPL_PRIORITY_SETUP;
rpl->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(rpl) = htonl(MK_OPCODE_TID(CPL_PASS_ACCEPT_RPL,
hwtid));
rpl->peer_ip = peer_ip;
rpl->opt0h = htonl(F_TCAM_BYPASS);
rpl->opt0l_status = htonl(CPL_PASS_OPEN_REJECT);
rpl->opt2 = 0;
rpl->rsvd = rpl->opt2;
iwch_cxgb3_ofld_send(tdev, skb);
}
}
static int pass_accept_req(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *child_ep, *parent_ep = ctx;
struct cpl_pass_accept_req *req = cplhdr(skb);
unsigned int hwtid = GET_TID(req);
struct dst_entry *dst;
struct l2t_entry *l2t;
struct rtable *rt;
struct iff_mac tim;
pr_debug("%s parent ep %p tid %u\n", __func__, parent_ep, hwtid);
if (state_read(&parent_ep->com) != LISTEN) {
pr_err("%s - listening ep not in LISTEN\n", __func__);
goto reject;
}
tim.mac_addr = req->dst_mac;
tim.vlan_tag = ntohs(req->vlan_tag);
if (tdev->ctl(tdev, GET_IFF_FROM_MAC, &tim) < 0 || !tim.dev) {
pr_err("%s bad dst mac %pM\n", __func__, req->dst_mac);
goto reject;
}
rt = find_route(tdev,
req->local_ip,
req->peer_ip,
req->local_port,
req->peer_port, G_PASS_OPEN_TOS(ntohl(req->tos_tid)));
if (!rt) {
pr_err("%s - failed to find dst entry!\n", __func__);
goto reject;
}
dst = &rt->dst;
l2t = t3_l2t_get(tdev, dst, NULL, &req->peer_ip);
if (!l2t) {
pr_err("%s - failed to allocate l2t entry!\n", __func__);
dst_release(dst);
goto reject;
}
child_ep = alloc_ep(sizeof(*child_ep), GFP_KERNEL);
if (!child_ep) {
pr_err("%s - failed to allocate ep entry!\n", __func__);
l2t_release(tdev, l2t);
dst_release(dst);
goto reject;
}
state_set(&child_ep->com, CONNECTING);
child_ep->com.tdev = tdev;
child_ep->com.cm_id = NULL;
child_ep->com.local_addr.sin_family = AF_INET;
child_ep->com.local_addr.sin_port = req->local_port;
child_ep->com.local_addr.sin_addr.s_addr = req->local_ip;
child_ep->com.remote_addr.sin_family = AF_INET;
child_ep->com.remote_addr.sin_port = req->peer_port;
child_ep->com.remote_addr.sin_addr.s_addr = req->peer_ip;
get_ep(&parent_ep->com);
child_ep->parent_ep = parent_ep;
child_ep->tos = G_PASS_OPEN_TOS(ntohl(req->tos_tid));
child_ep->l2t = l2t;
child_ep->dst = dst;
child_ep->hwtid = hwtid;
init_timer(&child_ep->timer);
cxgb3_insert_tid(tdev, &t3c_client, child_ep, hwtid);
accept_cr(child_ep, req->peer_ip, skb);
goto out;
reject:
reject_cr(tdev, hwtid, req->peer_ip, skb);
out:
return CPL_RET_BUF_DONE;
}
static int pass_establish(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct cpl_pass_establish *req = cplhdr(skb);
pr_debug("%s ep %p\n", __func__, ep);
ep->snd_seq = ntohl(req->snd_isn);
ep->rcv_seq = ntohl(req->rcv_isn);
set_emss(ep, ntohs(req->tcp_opt));
dst_confirm(ep->dst);
state_set(&ep->com, MPA_REQ_WAIT);
start_ep_timer(ep);
return CPL_RET_BUF_DONE;
}
static int peer_close(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct iwch_qp_attributes attrs;
unsigned long flags;
int disconnect = 1;
int release = 0;
pr_debug("%s ep %p\n", __func__, ep);
dst_confirm(ep->dst);
spin_lock_irqsave(&ep->com.lock, flags);
switch (ep->com.state) {
case MPA_REQ_WAIT:
__state_set(&ep->com, CLOSING);
break;
case MPA_REQ_SENT:
__state_set(&ep->com, CLOSING);
connect_reply_upcall(ep, -ECONNRESET);
break;
case MPA_REQ_RCVD:
__state_set(&ep->com, CLOSING);
ep->com.rpl_done = 1;
ep->com.rpl_err = -ECONNRESET;
pr_debug("waking up ep %p\n", ep);
wake_up(&ep->com.waitq);
break;
case MPA_REP_SENT:
__state_set(&ep->com, CLOSING);
ep->com.rpl_done = 1;
ep->com.rpl_err = -ECONNRESET;
pr_debug("waking up ep %p\n", ep);
wake_up(&ep->com.waitq);
break;
case FPDU_MODE:
start_ep_timer(ep);
__state_set(&ep->com, CLOSING);
attrs.next_state = IWCH_QP_STATE_CLOSING;
iwch_modify_qp(ep->com.qp->rhp, ep->com.qp,
IWCH_QP_ATTR_NEXT_STATE, &attrs, 1);
peer_close_upcall(ep);
break;
case ABORTING:
disconnect = 0;
break;
case CLOSING:
__state_set(&ep->com, MORIBUND);
disconnect = 0;
break;
case MORIBUND:
stop_ep_timer(ep);
if (ep->com.cm_id && ep->com.qp) {
attrs.next_state = IWCH_QP_STATE_IDLE;
iwch_modify_qp(ep->com.qp->rhp, ep->com.qp,
IWCH_QP_ATTR_NEXT_STATE, &attrs, 1);
}
close_complete_upcall(ep);
__state_set(&ep->com, DEAD);
release = 1;
disconnect = 0;
break;
case DEAD:
disconnect = 0;
break;
default:
BUG_ON(1);
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (disconnect)
iwch_ep_disconnect(ep, 0, GFP_KERNEL);
if (release)
release_ep_resources(ep);
return CPL_RET_BUF_DONE;
}
static int is_neg_adv_abort(unsigned int status)
{
return status == CPL_ERR_RTX_NEG_ADVICE ||
status == CPL_ERR_PERSIST_NEG_ADVICE;
}
static int peer_abort(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct cpl_abort_req_rss *req = cplhdr(skb);
struct iwch_ep *ep = ctx;
struct cpl_abort_rpl *rpl;
struct sk_buff *rpl_skb;
struct iwch_qp_attributes attrs;
int ret;
int release = 0;
unsigned long flags;
if (is_neg_adv_abort(req->status)) {
pr_debug("%s neg_adv_abort ep %p tid %d\n", __func__, ep,
ep->hwtid);
t3_l2t_send_event(ep->com.tdev, ep->l2t);
return CPL_RET_BUF_DONE;
}
if (!test_and_set_bit(PEER_ABORT_IN_PROGRESS, &ep->com.flags)) {
return CPL_RET_BUF_DONE;
}
spin_lock_irqsave(&ep->com.lock, flags);
pr_debug("%s ep %p state %u\n", __func__, ep, ep->com.state);
switch (ep->com.state) {
case CONNECTING:
break;
case MPA_REQ_WAIT:
stop_ep_timer(ep);
break;
case MPA_REQ_SENT:
stop_ep_timer(ep);
connect_reply_upcall(ep, -ECONNRESET);
break;
case MPA_REP_SENT:
ep->com.rpl_done = 1;
ep->com.rpl_err = -ECONNRESET;
pr_debug("waking up ep %p\n", ep);
wake_up(&ep->com.waitq);
break;
case MPA_REQ_RCVD:
ep->com.rpl_done = 1;
ep->com.rpl_err = -ECONNRESET;
pr_debug("waking up ep %p\n", ep);
wake_up(&ep->com.waitq);
break;
case MORIBUND:
case CLOSING:
stop_ep_timer(ep);
case FPDU_MODE:
if (ep->com.cm_id && ep->com.qp) {
attrs.next_state = IWCH_QP_STATE_ERROR;
ret = iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp, IWCH_QP_ATTR_NEXT_STATE,
&attrs, 1);
if (ret)
pr_err("%s - qp <- error failed!\n", __func__);
}
peer_abort_upcall(ep);
break;
case ABORTING:
break;
case DEAD:
pr_debug("%s PEER_ABORT IN DEAD STATE!!!!\n", __func__);
spin_unlock_irqrestore(&ep->com.lock, flags);
return CPL_RET_BUF_DONE;
default:
BUG_ON(1);
break;
}
dst_confirm(ep->dst);
if (ep->com.state != ABORTING) {
__state_set(&ep->com, DEAD);
release = 1;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
rpl_skb = get_skb(skb, sizeof(*rpl), GFP_KERNEL);
if (!rpl_skb) {
pr_err("%s - cannot allocate skb!\n", __func__);
release = 1;
goto out;
}
rpl_skb->priority = CPL_PRIORITY_DATA;
rpl = skb_put(rpl_skb, sizeof(*rpl));
rpl->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_OFLD_HOST_ABORT_CON_RPL));
rpl->wr.wr_lo = htonl(V_WR_TID(ep->hwtid));
OPCODE_TID(rpl) = htonl(MK_OPCODE_TID(CPL_ABORT_RPL, ep->hwtid));
rpl->cmd = CPL_ABORT_NO_RST;
iwch_cxgb3_ofld_send(ep->com.tdev, rpl_skb);
out:
if (release)
release_ep_resources(ep);
return CPL_RET_BUF_DONE;
}
static int close_con_rpl(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
struct iwch_qp_attributes attrs;
unsigned long flags;
int release = 0;
pr_debug("%s ep %p\n", __func__, ep);
BUG_ON(!ep);
spin_lock_irqsave(&ep->com.lock, flags);
switch (ep->com.state) {
case CLOSING:
__state_set(&ep->com, MORIBUND);
break;
case MORIBUND:
stop_ep_timer(ep);
if ((ep->com.cm_id) && (ep->com.qp)) {
attrs.next_state = IWCH_QP_STATE_IDLE;
iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp,
IWCH_QP_ATTR_NEXT_STATE,
&attrs, 1);
}
close_complete_upcall(ep);
__state_set(&ep->com, DEAD);
release = 1;
break;
case ABORTING:
case DEAD:
break;
default:
BUG_ON(1);
break;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (release)
release_ep_resources(ep);
return CPL_RET_BUF_DONE;
}
static int terminate(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep *ep = ctx;
if (state_read(&ep->com) != FPDU_MODE)
return CPL_RET_BUF_DONE;
pr_debug("%s ep %p\n", __func__, ep);
skb_pull(skb, sizeof(struct cpl_rdma_terminate));
pr_debug("%s saving %d bytes of term msg\n", __func__, skb->len);
skb_copy_from_linear_data(skb, ep->com.qp->attr.terminate_buffer,
skb->len);
ep->com.qp->attr.terminate_msg_len = skb->len;
ep->com.qp->attr.is_terminate_local = 0;
return CPL_RET_BUF_DONE;
}
static int ec_status(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct cpl_rdma_ec_status *rep = cplhdr(skb);
struct iwch_ep *ep = ctx;
pr_debug("%s ep %p tid %u status %d\n", __func__, ep, ep->hwtid,
rep->status);
if (rep->status) {
struct iwch_qp_attributes attrs;
pr_err("%s BAD CLOSE - Aborting tid %u\n",
__func__, ep->hwtid);
stop_ep_timer(ep);
attrs.next_state = IWCH_QP_STATE_ERROR;
iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp, IWCH_QP_ATTR_NEXT_STATE,
&attrs, 1);
abort_connection(ep, NULL, GFP_KERNEL);
}
return CPL_RET_BUF_DONE;
}
static void ep_timeout(unsigned long arg)
{
struct iwch_ep *ep = (struct iwch_ep *)arg;
struct iwch_qp_attributes attrs;
unsigned long flags;
int abort = 1;
spin_lock_irqsave(&ep->com.lock, flags);
pr_debug("%s ep %p tid %u state %d\n", __func__, ep, ep->hwtid,
ep->com.state);
switch (ep->com.state) {
case MPA_REQ_SENT:
__state_set(&ep->com, ABORTING);
connect_reply_upcall(ep, -ETIMEDOUT);
break;
case MPA_REQ_WAIT:
__state_set(&ep->com, ABORTING);
break;
case CLOSING:
case MORIBUND:
if (ep->com.cm_id && ep->com.qp) {
attrs.next_state = IWCH_QP_STATE_ERROR;
iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp, IWCH_QP_ATTR_NEXT_STATE,
&attrs, 1);
}
__state_set(&ep->com, ABORTING);
break;
default:
WARN(1, "%s unexpected state ep %p state %u\n",
__func__, ep, ep->com.state);
abort = 0;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (abort)
abort_connection(ep, NULL, GFP_ATOMIC);
put_ep(&ep->com);
}
int iwch_reject_cr(struct iw_cm_id *cm_id, const void *pdata, u8 pdata_len)
{
int err;
struct iwch_ep *ep = to_ep(cm_id);
pr_debug("%s ep %p tid %u\n", __func__, ep, ep->hwtid);
if (state_read(&ep->com) == DEAD) {
put_ep(&ep->com);
return -ECONNRESET;
}
BUG_ON(state_read(&ep->com) != MPA_REQ_RCVD);
if (mpa_rev == 0)
abort_connection(ep, NULL, GFP_KERNEL);
else {
err = send_mpa_reject(ep, pdata, pdata_len);
err = iwch_ep_disconnect(ep, 0, GFP_KERNEL);
}
put_ep(&ep->com);
return 0;
}
int iwch_accept_cr(struct iw_cm_id *cm_id, struct iw_cm_conn_param *conn_param)
{
int err;
struct iwch_qp_attributes attrs;
enum iwch_qp_attr_mask mask;
struct iwch_ep *ep = to_ep(cm_id);
struct iwch_dev *h = to_iwch_dev(cm_id->device);
struct iwch_qp *qp = get_qhp(h, conn_param->qpn);
pr_debug("%s ep %p tid %u\n", __func__, ep, ep->hwtid);
if (state_read(&ep->com) == DEAD) {
err = -ECONNRESET;
goto err;
}
BUG_ON(state_read(&ep->com) != MPA_REQ_RCVD);
BUG_ON(!qp);
if ((conn_param->ord > qp->rhp->attr.max_rdma_read_qp_depth) ||
(conn_param->ird > qp->rhp->attr.max_rdma_reads_per_qp)) {
abort_connection(ep, NULL, GFP_KERNEL);
err = -EINVAL;
goto err;
}
cm_id->add_ref(cm_id);
ep->com.cm_id = cm_id;
ep->com.qp = qp;
ep->ird = conn_param->ird;
ep->ord = conn_param->ord;
if (peer2peer && ep->ird == 0)
ep->ird = 1;
pr_debug("%s %d ird %d ord %d\n", __func__, __LINE__, ep->ird, ep->ord);
attrs.mpa_attr = ep->mpa_attr;
attrs.max_ird = ep->ird;
attrs.max_ord = ep->ord;
attrs.llp_stream_handle = ep;
attrs.next_state = IWCH_QP_STATE_RTS;
mask = IWCH_QP_ATTR_NEXT_STATE |
IWCH_QP_ATTR_LLP_STREAM_HANDLE |
IWCH_QP_ATTR_MPA_ATTR |
IWCH_QP_ATTR_MAX_IRD |
IWCH_QP_ATTR_MAX_ORD;
err = iwch_modify_qp(ep->com.qp->rhp,
ep->com.qp, mask, &attrs, 1);
if (err)
goto err1;
if (iwch_rqes_posted(qp)) {
wait_event(ep->com.waitq, ep->com.rpl_done);
err = ep->com.rpl_err;
if (err)
goto err1;
}
err = send_mpa_reply(ep, conn_param->private_data,
conn_param->private_data_len);
if (err)
goto err1;
state_set(&ep->com, FPDU_MODE);
established_upcall(ep);
put_ep(&ep->com);
return 0;
err1:
ep->com.cm_id = NULL;
ep->com.qp = NULL;
cm_id->rem_ref(cm_id);
err:
put_ep(&ep->com);
return err;
}
static int is_loopback_dst(struct iw_cm_id *cm_id)
{
struct net_device *dev;
struct sockaddr_in *raddr = (struct sockaddr_in *)&cm_id->m_remote_addr;
dev = ip_dev_find(&init_net, raddr->sin_addr.s_addr);
if (!dev)
return 0;
dev_put(dev);
return 1;
}
int iwch_connect(struct iw_cm_id *cm_id, struct iw_cm_conn_param *conn_param)
{
struct iwch_dev *h = to_iwch_dev(cm_id->device);
struct iwch_ep *ep;
struct rtable *rt;
int err = 0;
struct sockaddr_in *laddr = (struct sockaddr_in *)&cm_id->m_local_addr;
struct sockaddr_in *raddr = (struct sockaddr_in *)&cm_id->m_remote_addr;
if (cm_id->m_remote_addr.ss_family != PF_INET) {
err = -ENOSYS;
goto out;
}
if (is_loopback_dst(cm_id)) {
err = -ENOSYS;
goto out;
}
ep = alloc_ep(sizeof(*ep), GFP_KERNEL);
if (!ep) {
pr_err("%s - cannot alloc ep\n", __func__);
err = -ENOMEM;
goto out;
}
init_timer(&ep->timer);
ep->plen = conn_param->private_data_len;
if (ep->plen)
memcpy(ep->mpa_pkt + sizeof(struct mpa_message),
conn_param->private_data, ep->plen);
ep->ird = conn_param->ird;
ep->ord = conn_param->ord;
if (peer2peer && ep->ord == 0)
ep->ord = 1;
ep->com.tdev = h->rdev.t3cdev_p;
cm_id->add_ref(cm_id);
ep->com.cm_id = cm_id;
ep->com.qp = get_qhp(h, conn_param->qpn);
BUG_ON(!ep->com.qp);
pr_debug("%s qpn 0x%x qp %p cm_id %p\n", __func__, conn_param->qpn,
ep->com.qp, cm_id);
ep->atid = cxgb3_alloc_atid(h->rdev.t3cdev_p, &t3c_client, ep);
if (ep->atid == -1) {
pr_err("%s - cannot alloc atid\n", __func__);
err = -ENOMEM;
goto fail2;
}
rt = find_route(h->rdev.t3cdev_p, laddr->sin_addr.s_addr,
raddr->sin_addr.s_addr, laddr->sin_port,
raddr->sin_port, IPTOS_LOWDELAY);
if (!rt) {
pr_err("%s - cannot find route\n", __func__);
err = -EHOSTUNREACH;
goto fail3;
}
ep->dst = &rt->dst;
ep->l2t = t3_l2t_get(ep->com.tdev, ep->dst, NULL,
&raddr->sin_addr.s_addr);
if (!ep->l2t) {
pr_err("%s - cannot alloc l2e\n", __func__);
err = -ENOMEM;
goto fail4;
}
state_set(&ep->com, CONNECTING);
ep->tos = IPTOS_LOWDELAY;
memcpy(&ep->com.local_addr, &cm_id->m_local_addr,
sizeof(ep->com.local_addr));
memcpy(&ep->com.remote_addr, &cm_id->m_remote_addr,
sizeof(ep->com.remote_addr));
err = send_connect(ep);
if (!err)
goto out;
l2t_release(h->rdev.t3cdev_p, ep->l2t);
fail4:
dst_release(ep->dst);
fail3:
cxgb3_free_atid(ep->com.tdev, ep->atid);
fail2:
cm_id->rem_ref(cm_id);
put_ep(&ep->com);
out:
return err;
}
int iwch_create_listen(struct iw_cm_id *cm_id, int backlog)
{
int err = 0;
struct iwch_dev *h = to_iwch_dev(cm_id->device);
struct iwch_listen_ep *ep;
might_sleep();
if (cm_id->m_local_addr.ss_family != PF_INET) {
err = -ENOSYS;
goto fail1;
}
ep = alloc_ep(sizeof(*ep), GFP_KERNEL);
if (!ep) {
pr_err("%s - cannot alloc ep\n", __func__);
err = -ENOMEM;
goto fail1;
}
pr_debug("%s ep %p\n", __func__, ep);
ep->com.tdev = h->rdev.t3cdev_p;
cm_id->add_ref(cm_id);
ep->com.cm_id = cm_id;
ep->backlog = backlog;
memcpy(&ep->com.local_addr, &cm_id->m_local_addr,
sizeof(ep->com.local_addr));
ep->stid = cxgb3_alloc_stid(h->rdev.t3cdev_p, &t3c_client, ep);
if (ep->stid == -1) {
pr_err("%s - cannot alloc atid\n", __func__);
err = -ENOMEM;
goto fail2;
}
state_set(&ep->com, LISTEN);
err = listen_start(ep);
if (err)
goto fail3;
wait_event(ep->com.waitq, ep->com.rpl_done);
err = ep->com.rpl_err;
if (!err) {
cm_id->provider_data = ep;
goto out;
}
fail3:
cxgb3_free_stid(ep->com.tdev, ep->stid);
fail2:
cm_id->rem_ref(cm_id);
put_ep(&ep->com);
fail1:
out:
return err;
}
int iwch_destroy_listen(struct iw_cm_id *cm_id)
{
int err;
struct iwch_listen_ep *ep = to_listen_ep(cm_id);
pr_debug("%s ep %p\n", __func__, ep);
might_sleep();
state_set(&ep->com, DEAD);
ep->com.rpl_done = 0;
ep->com.rpl_err = 0;
err = listen_stop(ep);
if (err)
goto done;
wait_event(ep->com.waitq, ep->com.rpl_done);
cxgb3_free_stid(ep->com.tdev, ep->stid);
done:
err = ep->com.rpl_err;
cm_id->rem_ref(cm_id);
put_ep(&ep->com);
return err;
}
int iwch_ep_disconnect(struct iwch_ep *ep, int abrupt, gfp_t gfp)
{
int ret=0;
unsigned long flags;
int close = 0;
int fatal = 0;
struct t3cdev *tdev;
struct cxio_rdev *rdev;
spin_lock_irqsave(&ep->com.lock, flags);
pr_debug("%s ep %p state %s, abrupt %d\n", __func__, ep,
states[ep->com.state], abrupt);
tdev = (struct t3cdev *)ep->com.tdev;
rdev = (struct cxio_rdev *)tdev->ulp;
if (cxio_fatal_error(rdev)) {
fatal = 1;
close_complete_upcall(ep);
ep->com.state = DEAD;
}
switch (ep->com.state) {
case MPA_REQ_WAIT:
case MPA_REQ_SENT:
case MPA_REQ_RCVD:
case MPA_REP_SENT:
case FPDU_MODE:
close = 1;
if (abrupt)
ep->com.state = ABORTING;
else {
ep->com.state = CLOSING;
start_ep_timer(ep);
}
set_bit(CLOSE_SENT, &ep->com.flags);
break;
case CLOSING:
if (!test_and_set_bit(CLOSE_SENT, &ep->com.flags)) {
close = 1;
if (abrupt) {
stop_ep_timer(ep);
ep->com.state = ABORTING;
} else
ep->com.state = MORIBUND;
}
break;
case MORIBUND:
case ABORTING:
case DEAD:
pr_debug("%s ignoring disconnect ep %p state %u\n",
__func__, ep, ep->com.state);
break;
default:
BUG();
break;
}
spin_unlock_irqrestore(&ep->com.lock, flags);
if (close) {
if (abrupt)
ret = send_abort(ep, NULL, gfp);
else
ret = send_halfclose(ep, gfp);
if (ret)
fatal = 1;
}
if (fatal)
release_ep_resources(ep);
return ret;
}
int iwch_ep_redirect(void *ctx, struct dst_entry *old, struct dst_entry *new,
struct l2t_entry *l2t)
{
struct iwch_ep *ep = ctx;
if (ep->dst != old)
return 0;
pr_debug("%s ep %p redirect to dst %p l2t %p\n", __func__, ep, new,
l2t);
dst_hold(new);
l2t_release(ep->com.tdev, ep->l2t);
ep->l2t = l2t;
dst_release(old);
ep->dst = new;
return 1;
}
static void process_work(struct work_struct *work)
{
struct sk_buff *skb = NULL;
void *ep;
struct t3cdev *tdev;
int ret;
while ((skb = skb_dequeue(&rxq))) {
ep = *((void **) (skb->cb));
tdev = *((struct t3cdev **) (skb->cb + sizeof(void *)));
ret = work_handlers[G_OPCODE(ntohl((__force __be32)skb->csum))](tdev, skb, ep);
if (ret & CPL_RET_BUF_DONE)
kfree_skb(skb);
put_ep((struct iwch_ep_common *)ep);
}
}
static int sched(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct iwch_ep_common *epc = ctx;
get_ep(epc);
*((void **) skb->cb) = ctx;
*((struct t3cdev **) (skb->cb + sizeof(void *))) = tdev;
skb_queue_tail(&rxq, skb);
queue_work(workq, &skb_work);
return 0;
}
static int set_tcb_rpl(struct t3cdev *tdev, struct sk_buff *skb, void *ctx)
{
struct cpl_set_tcb_rpl *rpl = cplhdr(skb);
if (rpl->status != CPL_ERR_NONE) {
pr_err("Unexpected SET_TCB_RPL status %u for tid %u\n",
rpl->status, GET_TID(rpl));
}
return CPL_RET_BUF_DONE;
}
int __init iwch_cm_init(void)
{
skb_queue_head_init(&rxq);
workq = alloc_ordered_workqueue("iw_cxgb3", WQ_MEM_RECLAIM);
if (!workq)
return -ENOMEM;
return 0;
}
void __exit iwch_cm_term(void)
{
flush_workqueue(workq);
destroy_workqueue(workq);
}
