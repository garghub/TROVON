static void cfhsi_inactivity_tout(unsigned long arg)
{
struct cfhsi *cfhsi = (struct cfhsi *)arg;
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
if (!test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_down_work);
}
static void cfhsi_update_aggregation_stats(struct cfhsi *cfhsi,
const struct sk_buff *skb,
int direction)
{
struct caif_payload_info *info;
int hpad, tpad, len;
info = (struct caif_payload_info *)&skb->cb;
hpad = 1 + PAD_POW2((info->hdr_len + 1), cfhsi->cfg.head_align);
tpad = PAD_POW2((skb->len + hpad), cfhsi->cfg.tail_align);
len = skb->len + hpad + tpad;
if (direction > 0)
cfhsi->aggregation_len += len;
else if (direction < 0)
cfhsi->aggregation_len -= len;
}
static bool cfhsi_can_send_aggregate(struct cfhsi *cfhsi)
{
int i;
if (cfhsi->cfg.aggregation_timeout == 0)
return true;
for (i = 0; i < CFHSI_PRIO_BEBK; ++i) {
if (cfhsi->qhead[i].qlen)
return true;
}
if (cfhsi->qhead[CFHSI_PRIO_BEBK].qlen >= CFHSI_MAX_PKTS)
return true;
return false;
}
static struct sk_buff *cfhsi_dequeue(struct cfhsi *cfhsi)
{
struct sk_buff *skb;
int i;
for (i = 0; i < CFHSI_PRIO_LAST; ++i) {
skb = skb_dequeue(&cfhsi->qhead[i]);
if (skb)
break;
}
return skb;
}
static int cfhsi_tx_queue_len(struct cfhsi *cfhsi)
{
int i, len = 0;
for (i = 0; i < CFHSI_PRIO_LAST; ++i)
len += skb_queue_len(&cfhsi->qhead[i]);
return len;
}
static void cfhsi_abort_tx(struct cfhsi *cfhsi)
{
struct sk_buff *skb;
for (;;) {
spin_lock_bh(&cfhsi->lock);
skb = cfhsi_dequeue(cfhsi);
if (!skb)
break;
cfhsi->ndev->stats.tx_errors++;
cfhsi->ndev->stats.tx_dropped++;
cfhsi_update_aggregation_stats(cfhsi, skb, -1);
spin_unlock_bh(&cfhsi->lock);
kfree_skb(skb);
}
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
if (!test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
mod_timer(&cfhsi->inactivity_timer,
jiffies + cfhsi->cfg.inactivity_timeout);
spin_unlock_bh(&cfhsi->lock);
}
static int cfhsi_flush_fifo(struct cfhsi *cfhsi)
{
char buffer[32];
size_t fifo_occupancy;
int ret;
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
do {
ret = cfhsi->ops->cfhsi_fifo_occupancy(cfhsi->ops,
&fifo_occupancy);
if (ret) {
netdev_warn(cfhsi->ndev,
"%s: can't get FIFO occupancy: %d.\n",
__func__, ret);
break;
} else if (!fifo_occupancy)
break;
fifo_occupancy = min(sizeof(buffer), fifo_occupancy);
set_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits);
ret = cfhsi->ops->cfhsi_rx(buffer, fifo_occupancy,
cfhsi->ops);
if (ret) {
clear_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits);
netdev_warn(cfhsi->ndev,
"%s: can't read data: %d.\n",
__func__, ret);
break;
}
ret = 5 * HZ;
ret = wait_event_interruptible_timeout(cfhsi->flush_fifo_wait,
!test_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits), ret);
if (ret < 0) {
netdev_warn(cfhsi->ndev,
"%s: can't wait for flush complete: %d.\n",
__func__, ret);
break;
} else if (!ret) {
ret = -ETIMEDOUT;
netdev_warn(cfhsi->ndev,
"%s: timeout waiting for flush complete.\n",
__func__);
break;
}
} while (1);
return ret;
}
static int cfhsi_tx_frm(struct cfhsi_desc *desc, struct cfhsi *cfhsi)
{
int nfrms = 0;
int pld_len = 0;
struct sk_buff *skb;
u8 *pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
skb = cfhsi_dequeue(cfhsi);
if (!skb)
return 0;
desc->offset = 0;
if (skb->len < CFHSI_MAX_EMB_FRM_SZ) {
struct caif_payload_info *info;
int hpad;
int tpad;
info = (struct caif_payload_info *)&skb->cb;
hpad = 1 + PAD_POW2((info->hdr_len + 1), cfhsi->cfg.head_align);
tpad = PAD_POW2((skb->len + hpad), cfhsi->cfg.tail_align);
if ((skb->len + hpad + tpad) <= CFHSI_MAX_EMB_FRM_SZ) {
u8 *pemb = desc->emb_frm;
desc->offset = CFHSI_DESC_SHORT_SZ;
*pemb = (u8)(hpad - 1);
pemb += hpad;
spin_lock_bh(&cfhsi->lock);
cfhsi->ndev->stats.tx_packets++;
cfhsi->ndev->stats.tx_bytes += skb->len;
cfhsi_update_aggregation_stats(cfhsi, skb, -1);
spin_unlock_bh(&cfhsi->lock);
skb_copy_bits(skb, 0, pemb, skb->len);
consume_skb(skb);
skb = NULL;
}
}
pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
while (nfrms < CFHSI_MAX_PKTS) {
struct caif_payload_info *info;
int hpad;
int tpad;
if (!skb)
skb = cfhsi_dequeue(cfhsi);
if (!skb)
break;
info = (struct caif_payload_info *)&skb->cb;
hpad = 1 + PAD_POW2((info->hdr_len + 1), cfhsi->cfg.head_align);
tpad = PAD_POW2((skb->len + hpad), cfhsi->cfg.tail_align);
desc->cffrm_len[nfrms] = hpad + skb->len + tpad;
*pfrm = (u8)(hpad - 1);
pfrm += hpad;
spin_lock_bh(&cfhsi->lock);
cfhsi->ndev->stats.tx_packets++;
cfhsi->ndev->stats.tx_bytes += skb->len;
cfhsi_update_aggregation_stats(cfhsi, skb, -1);
spin_unlock_bh(&cfhsi->lock);
skb_copy_bits(skb, 0, pfrm, skb->len);
pld_len += desc->cffrm_len[nfrms];
pfrm += skb->len + tpad;
consume_skb(skb);
skb = NULL;
nfrms++;
}
while (nfrms < CFHSI_MAX_PKTS) {
desc->cffrm_len[nfrms] = 0x0000;
nfrms++;
}
if (cfhsi_can_send_aggregate(cfhsi))
desc->header |= CFHSI_PIGGY_DESC;
else
desc->header &= ~CFHSI_PIGGY_DESC;
return CFHSI_DESC_SZ + pld_len;
}
static void cfhsi_start_tx(struct cfhsi *cfhsi)
{
struct cfhsi_desc *desc = (struct cfhsi_desc *)cfhsi->tx_buf;
int len, res;
netdev_dbg(cfhsi->ndev, "%s.\n", __func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
do {
len = cfhsi_tx_frm(desc, cfhsi);
if (!len) {
spin_lock_bh(&cfhsi->lock);
if (unlikely(cfhsi_tx_queue_len(cfhsi))) {
spin_unlock_bh(&cfhsi->lock);
res = -EAGAIN;
continue;
}
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
mod_timer(&cfhsi->inactivity_timer,
jiffies + cfhsi->cfg.inactivity_timeout);
spin_unlock_bh(&cfhsi->lock);
break;
}
res = cfhsi->ops->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->ops);
if (WARN_ON(res < 0))
netdev_err(cfhsi->ndev, "%s: TX error %d.\n",
__func__, res);
} while (res < 0);
}
static void cfhsi_tx_done(struct cfhsi *cfhsi)
{
netdev_dbg(cfhsi->ndev, "%s.\n", __func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
spin_lock_bh(&cfhsi->lock);
if (cfhsi->flow_off_sent &&
cfhsi_tx_queue_len(cfhsi) <= cfhsi->cfg.q_low_mark &&
cfhsi->cfdev.flowctrl) {
cfhsi->flow_off_sent = 0;
cfhsi->cfdev.flowctrl(cfhsi->ndev, ON);
}
if (cfhsi_can_send_aggregate(cfhsi)) {
spin_unlock_bh(&cfhsi->lock);
cfhsi_start_tx(cfhsi);
} else {
mod_timer(&cfhsi->aggregation_timer,
jiffies + cfhsi->cfg.aggregation_timeout);
spin_unlock_bh(&cfhsi->lock);
}
return;
}
static void cfhsi_tx_done_cb(struct cfhsi_cb_ops *cb_ops)
{
struct cfhsi *cfhsi;
cfhsi = container_of(cb_ops, struct cfhsi, cb_ops);
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
cfhsi_tx_done(cfhsi);
}
static int cfhsi_rx_desc(struct cfhsi_desc *desc, struct cfhsi *cfhsi)
{
int xfer_sz = 0;
int nfrms = 0;
u16 *plen = NULL;
u8 *pfrm = NULL;
if ((desc->header & ~CFHSI_PIGGY_DESC) ||
(desc->offset > CFHSI_MAX_EMB_FRM_SZ)) {
netdev_err(cfhsi->ndev, "%s: Invalid descriptor.\n",
__func__);
return -EPROTO;
}
if (desc->offset) {
struct sk_buff *skb;
u8 *dst = NULL;
int len = 0;
pfrm = ((u8 *)desc) + desc->offset;
pfrm += *pfrm + 1;
len = *pfrm;
len |= ((*(pfrm+1)) << 8) & 0xFF00;
len += 2;
if (unlikely(len > CFHSI_MAX_CAIF_FRAME_SZ)) {
netdev_err(cfhsi->ndev, "%s: Invalid length.\n",
__func__);
return -EPROTO;
}
skb = alloc_skb(len + 1, GFP_ATOMIC);
if (!skb) {
netdev_err(cfhsi->ndev, "%s: Out of memory !\n",
__func__);
return -ENOMEM;
}
caif_assert(skb != NULL);
dst = skb_put(skb, len);
memcpy(dst, pfrm, len);
skb->protocol = htons(ETH_P_CAIF);
skb_reset_mac_header(skb);
skb->dev = cfhsi->ndev;
if (in_interrupt())
netif_rx(skb);
else
netif_rx_ni(skb);
cfhsi->ndev->stats.rx_packets++;
cfhsi->ndev->stats.rx_bytes += len;
}
plen = desc->cffrm_len;
while (nfrms < CFHSI_MAX_PKTS && *plen) {
xfer_sz += *plen;
plen++;
nfrms++;
}
if (desc->header & CFHSI_PIGGY_DESC)
xfer_sz += CFHSI_DESC_SZ;
if ((xfer_sz % 4) || (xfer_sz > (CFHSI_BUF_SZ_RX - CFHSI_DESC_SZ))) {
netdev_err(cfhsi->ndev,
"%s: Invalid payload len: %d, ignored.\n",
__func__, xfer_sz);
return -EPROTO;
}
return xfer_sz;
}
static int cfhsi_rx_desc_len(struct cfhsi_desc *desc)
{
int xfer_sz = 0;
int nfrms = 0;
u16 *plen;
if ((desc->header & ~CFHSI_PIGGY_DESC) ||
(desc->offset > CFHSI_MAX_EMB_FRM_SZ)) {
pr_err("Invalid descriptor. %x %x\n", desc->header,
desc->offset);
return -EPROTO;
}
plen = desc->cffrm_len;
while (nfrms < CFHSI_MAX_PKTS && *plen) {
xfer_sz += *plen;
plen++;
nfrms++;
}
if (xfer_sz % 4) {
pr_err("Invalid payload len: %d, ignored.\n", xfer_sz);
return -EPROTO;
}
return xfer_sz;
}
static int cfhsi_rx_pld(struct cfhsi_desc *desc, struct cfhsi *cfhsi)
{
int rx_sz = 0;
int nfrms = 0;
u16 *plen = NULL;
u8 *pfrm = NULL;
if (WARN_ON((desc->header & ~CFHSI_PIGGY_DESC) ||
(desc->offset > CFHSI_MAX_EMB_FRM_SZ))) {
netdev_err(cfhsi->ndev, "%s: Invalid descriptor.\n",
__func__);
return -EPROTO;
}
pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
plen = desc->cffrm_len;
while (nfrms < cfhsi->rx_state.nfrms) {
pfrm += *plen;
rx_sz += *plen;
plen++;
nfrms++;
}
while (nfrms < CFHSI_MAX_PKTS && *plen) {
struct sk_buff *skb;
u8 *dst = NULL;
u8 *pcffrm = NULL;
int len;
pcffrm = pfrm + *pfrm + 1;
len = *pcffrm;
len |= ((*(pcffrm + 1)) << 8) & 0xFF00;
len += 2;
if (unlikely(len > CFHSI_MAX_CAIF_FRAME_SZ)) {
netdev_err(cfhsi->ndev, "%s: Invalid length.\n",
__func__);
return -EPROTO;
}
skb = alloc_skb(len + 1, GFP_ATOMIC);
if (!skb) {
netdev_err(cfhsi->ndev, "%s: Out of memory !\n",
__func__);
cfhsi->rx_state.nfrms = nfrms;
return -ENOMEM;
}
caif_assert(skb != NULL);
dst = skb_put(skb, len);
memcpy(dst, pcffrm, len);
skb->protocol = htons(ETH_P_CAIF);
skb_reset_mac_header(skb);
skb->dev = cfhsi->ndev;
if (in_interrupt())
netif_rx(skb);
else
netif_rx_ni(skb);
cfhsi->ndev->stats.rx_packets++;
cfhsi->ndev->stats.rx_bytes += len;
pfrm += *plen;
rx_sz += *plen;
plen++;
nfrms++;
}
return rx_sz;
}
static void cfhsi_rx_done(struct cfhsi *cfhsi)
{
int res;
int desc_pld_len = 0, rx_len, rx_state;
struct cfhsi_desc *desc = NULL;
u8 *rx_ptr, *rx_buf;
struct cfhsi_desc *piggy_desc = NULL;
desc = (struct cfhsi_desc *)cfhsi->rx_buf;
netdev_dbg(cfhsi->ndev, "%s\n", __func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
spin_lock_bh(&cfhsi->lock);
mod_timer_pending(&cfhsi->inactivity_timer,
jiffies + cfhsi->cfg.inactivity_timeout);
spin_unlock_bh(&cfhsi->lock);
if (cfhsi->rx_state.state == CFHSI_RX_STATE_DESC) {
desc_pld_len = cfhsi_rx_desc_len(desc);
if (desc_pld_len < 0)
goto out_of_sync;
rx_buf = cfhsi->rx_buf;
rx_len = desc_pld_len;
if (desc_pld_len > 0 && (desc->header & CFHSI_PIGGY_DESC))
rx_len += CFHSI_DESC_SZ;
if (desc_pld_len == 0)
rx_buf = cfhsi->rx_flip_buf;
} else {
rx_buf = cfhsi->rx_flip_buf;
rx_len = CFHSI_DESC_SZ;
if (cfhsi->rx_state.pld_len > 0 &&
(desc->header & CFHSI_PIGGY_DESC)) {
piggy_desc = (struct cfhsi_desc *)
(desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ +
cfhsi->rx_state.pld_len);
cfhsi->rx_state.piggy_desc = true;
desc_pld_len = cfhsi_rx_desc_len(piggy_desc);
if (desc_pld_len < 0)
goto out_of_sync;
if (desc_pld_len > 0) {
rx_len = desc_pld_len;
if (piggy_desc->header & CFHSI_PIGGY_DESC)
rx_len += CFHSI_DESC_SZ;
}
memcpy(rx_buf, (u8 *)piggy_desc,
CFHSI_DESC_SHORT_SZ);
}
}
if (desc_pld_len) {
rx_state = CFHSI_RX_STATE_PAYLOAD;
rx_ptr = rx_buf + CFHSI_DESC_SZ;
} else {
rx_state = CFHSI_RX_STATE_DESC;
rx_ptr = rx_buf;
rx_len = CFHSI_DESC_SZ;
}
if (test_bit(CFHSI_AWAKE, &cfhsi->bits)) {
netdev_dbg(cfhsi->ndev, "%s: Start RX.\n",
__func__);
res = cfhsi->ops->cfhsi_rx(rx_ptr, rx_len,
cfhsi->ops);
if (WARN_ON(res < 0)) {
netdev_err(cfhsi->ndev, "%s: RX error %d.\n",
__func__, res);
cfhsi->ndev->stats.rx_errors++;
cfhsi->ndev->stats.rx_dropped++;
}
}
if (cfhsi->rx_state.state == CFHSI_RX_STATE_DESC) {
if (cfhsi_rx_desc(desc, cfhsi) < 0)
goto out_of_sync;
} else {
if (cfhsi_rx_pld(desc, cfhsi) < 0)
goto out_of_sync;
if (piggy_desc) {
if (cfhsi_rx_desc(piggy_desc, cfhsi) < 0)
goto out_of_sync;
piggy_desc->offset = 0;
}
}
memset(&cfhsi->rx_state, 0, sizeof(cfhsi->rx_state));
cfhsi->rx_state.state = rx_state;
cfhsi->rx_ptr = rx_ptr;
cfhsi->rx_len = rx_len;
cfhsi->rx_state.pld_len = desc_pld_len;
cfhsi->rx_state.piggy_desc = desc->header & CFHSI_PIGGY_DESC;
if (rx_buf != cfhsi->rx_buf)
swap(cfhsi->rx_buf, cfhsi->rx_flip_buf);
return;
out_of_sync:
netdev_err(cfhsi->ndev, "%s: Out of sync.\n", __func__);
print_hex_dump_bytes("--> ", DUMP_PREFIX_NONE,
cfhsi->rx_buf, CFHSI_DESC_SZ);
schedule_work(&cfhsi->out_of_sync_work);
}
static void cfhsi_rx_slowpath(unsigned long arg)
{
struct cfhsi *cfhsi = (struct cfhsi *)arg;
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
cfhsi_rx_done(cfhsi);
}
static void cfhsi_rx_done_cb(struct cfhsi_cb_ops *cb_ops)
{
struct cfhsi *cfhsi;
cfhsi = container_of(cb_ops, struct cfhsi, cb_ops);
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
if (test_and_clear_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits))
wake_up_interruptible(&cfhsi->flush_fifo_wait);
else
cfhsi_rx_done(cfhsi);
}
static void cfhsi_wake_up(struct work_struct *work)
{
struct cfhsi *cfhsi = NULL;
int res;
int len;
long ret;
cfhsi = container_of(work, struct cfhsi, wake_up_work);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
if (unlikely(test_bit(CFHSI_AWAKE, &cfhsi->bits))) {
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
return;
}
cfhsi->ops->cfhsi_wake_up(cfhsi->ops);
netdev_dbg(cfhsi->ndev, "%s: Start waiting.\n",
__func__);
ret = CFHSI_WAKE_TOUT;
ret = wait_event_interruptible_timeout(cfhsi->wake_up_wait,
test_and_clear_bit(CFHSI_WAKE_UP_ACK,
&cfhsi->bits), ret);
if (unlikely(ret < 0)) {
netdev_err(cfhsi->ndev, "%s: Signalled: %ld.\n",
__func__, ret);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
cfhsi->ops->cfhsi_wake_down(cfhsi->ops);
return;
} else if (!ret) {
bool ca_wake = false;
size_t fifo_occupancy = 0;
netdev_dbg(cfhsi->ndev, "%s: Timeout.\n",
__func__);
WARN_ON(cfhsi->ops->cfhsi_fifo_occupancy(cfhsi->ops,
&fifo_occupancy));
netdev_dbg(cfhsi->ndev, "%s: Bytes in FIFO: %u.\n",
__func__, (unsigned) fifo_occupancy);
WARN_ON(cfhsi->ops->cfhsi_get_peer_wake(cfhsi->ops,
&ca_wake));
if (ca_wake) {
netdev_err(cfhsi->ndev, "%s: CA Wake missed !.\n",
__func__);
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
goto wake_ack;
}
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
cfhsi->ops->cfhsi_wake_down(cfhsi->ops);
return;
}
wake_ack:
netdev_dbg(cfhsi->ndev, "%s: Woken.\n",
__func__);
set_bit(CFHSI_AWAKE, &cfhsi->bits);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
netdev_dbg(cfhsi->ndev, "%s: Start RX.\n", __func__);
res = cfhsi->ops->cfhsi_rx(cfhsi->rx_ptr, cfhsi->rx_len, cfhsi->ops);
if (WARN_ON(res < 0))
netdev_err(cfhsi->ndev, "%s: RX err %d.\n", __func__, res);
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
spin_lock_bh(&cfhsi->lock);
if (!cfhsi_tx_queue_len(cfhsi)) {
netdev_dbg(cfhsi->ndev, "%s: Peer wake, start timer.\n",
__func__);
mod_timer(&cfhsi->inactivity_timer,
jiffies + cfhsi->cfg.inactivity_timeout);
spin_unlock_bh(&cfhsi->lock);
return;
}
netdev_dbg(cfhsi->ndev, "%s: Host wake.\n",
__func__);
spin_unlock_bh(&cfhsi->lock);
len = cfhsi_tx_frm((struct cfhsi_desc *)cfhsi->tx_buf, cfhsi);
if (likely(len > 0)) {
res = cfhsi->ops->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->ops);
if (WARN_ON(res < 0)) {
netdev_err(cfhsi->ndev, "%s: TX error %d.\n",
__func__, res);
cfhsi_abort_tx(cfhsi);
}
} else {
netdev_err(cfhsi->ndev,
"%s: Failed to create HSI frame: %d.\n",
__func__, len);
}
}
static void cfhsi_wake_down(struct work_struct *work)
{
long ret;
struct cfhsi *cfhsi = NULL;
size_t fifo_occupancy = 0;
int retry = CFHSI_WAKE_TOUT;
cfhsi = container_of(work, struct cfhsi, wake_down_work);
netdev_dbg(cfhsi->ndev, "%s.\n", __func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
cfhsi->ops->cfhsi_wake_down(cfhsi->ops);
ret = CFHSI_WAKE_TOUT;
ret = wait_event_interruptible_timeout(cfhsi->wake_down_wait,
test_and_clear_bit(CFHSI_WAKE_DOWN_ACK,
&cfhsi->bits), ret);
if (ret < 0) {
netdev_err(cfhsi->ndev, "%s: Signalled: %ld.\n",
__func__, ret);
return;
} else if (!ret) {
bool ca_wake = true;
netdev_err(cfhsi->ndev, "%s: Timeout.\n", __func__);
WARN_ON(cfhsi->ops->cfhsi_get_peer_wake(cfhsi->ops,
&ca_wake));
if (!ca_wake)
netdev_err(cfhsi->ndev, "%s: CA Wake missed !.\n",
__func__);
}
while (retry) {
WARN_ON(cfhsi->ops->cfhsi_fifo_occupancy(cfhsi->ops,
&fifo_occupancy));
if (!fifo_occupancy)
break;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(1);
retry--;
}
if (!retry)
netdev_err(cfhsi->ndev, "%s: FIFO Timeout.\n", __func__);
clear_bit(CFHSI_AWAKE, &cfhsi->bits);
cfhsi->ops->cfhsi_rx_cancel(cfhsi->ops);
}
static void cfhsi_out_of_sync(struct work_struct *work)
{
struct cfhsi *cfhsi = NULL;
cfhsi = container_of(work, struct cfhsi, out_of_sync_work);
rtnl_lock();
dev_close(cfhsi->ndev);
rtnl_unlock();
}
static void cfhsi_wake_up_cb(struct cfhsi_cb_ops *cb_ops)
{
struct cfhsi *cfhsi = NULL;
cfhsi = container_of(cb_ops, struct cfhsi, cb_ops);
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
set_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
wake_up_interruptible(&cfhsi->wake_up_wait);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
if (!test_and_set_bit(CFHSI_WAKE_UP, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_up_work);
}
static void cfhsi_wake_down_cb(struct cfhsi_cb_ops *cb_ops)
{
struct cfhsi *cfhsi = NULL;
cfhsi = container_of(cb_ops, struct cfhsi, cb_ops);
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
set_bit(CFHSI_WAKE_DOWN_ACK, &cfhsi->bits);
wake_up_interruptible(&cfhsi->wake_down_wait);
}
static void cfhsi_aggregation_tout(unsigned long arg)
{
struct cfhsi *cfhsi = (struct cfhsi *)arg;
netdev_dbg(cfhsi->ndev, "%s.\n",
__func__);
cfhsi_start_tx(cfhsi);
}
static int cfhsi_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct cfhsi *cfhsi = NULL;
int start_xfer = 0;
int timer_active;
int prio;
if (!dev)
return -EINVAL;
cfhsi = netdev_priv(dev);
switch (skb->priority) {
case TC_PRIO_BESTEFFORT:
case TC_PRIO_FILLER:
case TC_PRIO_BULK:
prio = CFHSI_PRIO_BEBK;
break;
case TC_PRIO_INTERACTIVE_BULK:
prio = CFHSI_PRIO_VI;
break;
case TC_PRIO_INTERACTIVE:
prio = CFHSI_PRIO_VO;
break;
case TC_PRIO_CONTROL:
default:
prio = CFHSI_PRIO_CTL;
break;
}
spin_lock_bh(&cfhsi->lock);
cfhsi_update_aggregation_stats(cfhsi, skb, 1);
skb_queue_tail(&cfhsi->qhead[prio], skb);
if (WARN_ON(test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))) {
spin_unlock_bh(&cfhsi->lock);
cfhsi_abort_tx(cfhsi);
return -EINVAL;
}
if (!cfhsi->flow_off_sent &&
cfhsi_tx_queue_len(cfhsi) > cfhsi->cfg.q_high_mark &&
cfhsi->cfdev.flowctrl) {
cfhsi->flow_off_sent = 1;
cfhsi->cfdev.flowctrl(cfhsi->ndev, OFF);
}
if (cfhsi->tx_state == CFHSI_TX_STATE_IDLE) {
cfhsi->tx_state = CFHSI_TX_STATE_XFER;
start_xfer = 1;
}
if (!start_xfer) {
bool aggregate_ready =
cfhsi_can_send_aggregate(cfhsi) &&
del_timer(&cfhsi->aggregation_timer) > 0;
spin_unlock_bh(&cfhsi->lock);
if (aggregate_ready)
cfhsi_start_tx(cfhsi);
return 0;
}
timer_active = del_timer_sync(&cfhsi->inactivity_timer);
spin_unlock_bh(&cfhsi->lock);
if (timer_active) {
struct cfhsi_desc *desc = (struct cfhsi_desc *)cfhsi->tx_buf;
int len;
int res;
len = cfhsi_tx_frm(desc, cfhsi);
WARN_ON(!len);
res = cfhsi->ops->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->ops);
if (WARN_ON(res < 0)) {
netdev_err(cfhsi->ndev, "%s: TX error %d.\n",
__func__, res);
cfhsi_abort_tx(cfhsi);
}
} else {
if (!test_and_set_bit(CFHSI_WAKE_UP, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_up_work);
}
return 0;
}
static void cfhsi_setup(struct net_device *dev)
{
int i;
struct cfhsi *cfhsi = netdev_priv(dev);
dev->features = 0;
dev->type = ARPHRD_CAIF;
dev->flags = IFF_POINTOPOINT | IFF_NOARP;
dev->mtu = CFHSI_MAX_CAIF_FRAME_SZ;
dev->priv_flags |= IFF_NO_QUEUE;
dev->destructor = free_netdev;
dev->netdev_ops = &cfhsi_netdevops;
for (i = 0; i < CFHSI_PRIO_LAST; ++i)
skb_queue_head_init(&cfhsi->qhead[i]);
cfhsi->cfdev.link_select = CAIF_LINK_HIGH_BANDW;
cfhsi->cfdev.use_frag = false;
cfhsi->cfdev.use_stx = false;
cfhsi->cfdev.use_fcs = false;
cfhsi->ndev = dev;
cfhsi->cfg = hsi_default_config;
}
static int cfhsi_open(struct net_device *ndev)
{
struct cfhsi *cfhsi = netdev_priv(ndev);
int res;
clear_bit(CFHSI_SHUTDOWN, &cfhsi->bits);
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
cfhsi->rx_state.state = CFHSI_RX_STATE_DESC;
cfhsi->flow_off_sent = 0;
cfhsi->tx_buf = kzalloc(CFHSI_BUF_SZ_TX, GFP_KERNEL);
if (!cfhsi->tx_buf) {
res = -ENODEV;
goto err_alloc_tx;
}
cfhsi->rx_buf = kzalloc(CFHSI_BUF_SZ_RX, GFP_KERNEL);
if (!cfhsi->rx_buf) {
res = -ENODEV;
goto err_alloc_rx;
}
cfhsi->rx_flip_buf = kzalloc(CFHSI_BUF_SZ_RX, GFP_KERNEL);
if (!cfhsi->rx_flip_buf) {
res = -ENODEV;
goto err_alloc_rx_flip;
}
cfhsi->cfg.aggregation_timeout = hsi_default_config.aggregation_timeout;
cfhsi->rx_ptr = cfhsi->rx_buf;
cfhsi->rx_len = CFHSI_DESC_SZ;
spin_lock_init(&cfhsi->lock);
cfhsi->cb_ops.tx_done_cb = cfhsi_tx_done_cb;
cfhsi->cb_ops.rx_done_cb = cfhsi_rx_done_cb;
cfhsi->cb_ops.wake_up_cb = cfhsi_wake_up_cb;
cfhsi->cb_ops.wake_down_cb = cfhsi_wake_down_cb;
INIT_WORK(&cfhsi->wake_up_work, cfhsi_wake_up);
INIT_WORK(&cfhsi->wake_down_work, cfhsi_wake_down);
INIT_WORK(&cfhsi->out_of_sync_work, cfhsi_out_of_sync);
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
clear_bit(CFHSI_WAKE_DOWN_ACK, &cfhsi->bits);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
clear_bit(CFHSI_AWAKE, &cfhsi->bits);
cfhsi->wq = create_singlethread_workqueue(cfhsi->ndev->name);
if (!cfhsi->wq) {
netdev_err(cfhsi->ndev, "%s: Failed to create work queue.\n",
__func__);
res = -ENODEV;
goto err_create_wq;
}
init_waitqueue_head(&cfhsi->wake_up_wait);
init_waitqueue_head(&cfhsi->wake_down_wait);
init_waitqueue_head(&cfhsi->flush_fifo_wait);
init_timer(&cfhsi->inactivity_timer);
cfhsi->inactivity_timer.data = (unsigned long)cfhsi;
cfhsi->inactivity_timer.function = cfhsi_inactivity_tout;
init_timer(&cfhsi->rx_slowpath_timer);
cfhsi->rx_slowpath_timer.data = (unsigned long)cfhsi;
cfhsi->rx_slowpath_timer.function = cfhsi_rx_slowpath;
init_timer(&cfhsi->aggregation_timer);
cfhsi->aggregation_timer.data = (unsigned long)cfhsi;
cfhsi->aggregation_timer.function = cfhsi_aggregation_tout;
res = cfhsi->ops->cfhsi_up(cfhsi->ops);
if (res) {
netdev_err(cfhsi->ndev,
"%s: can't activate HSI interface: %d.\n",
__func__, res);
goto err_activate;
}
res = cfhsi_flush_fifo(cfhsi);
if (res) {
netdev_err(cfhsi->ndev, "%s: Can't flush FIFO: %d.\n",
__func__, res);
goto err_net_reg;
}
return res;
err_net_reg:
cfhsi->ops->cfhsi_down(cfhsi->ops);
err_activate:
destroy_workqueue(cfhsi->wq);
err_create_wq:
kfree(cfhsi->rx_flip_buf);
err_alloc_rx_flip:
kfree(cfhsi->rx_buf);
err_alloc_rx:
kfree(cfhsi->tx_buf);
err_alloc_tx:
return res;
}
static int cfhsi_close(struct net_device *ndev)
{
struct cfhsi *cfhsi = netdev_priv(ndev);
u8 *tx_buf, *rx_buf, *flip_buf;
set_bit(CFHSI_SHUTDOWN, &cfhsi->bits);
flush_workqueue(cfhsi->wq);
del_timer_sync(&cfhsi->inactivity_timer);
del_timer_sync(&cfhsi->rx_slowpath_timer);
del_timer_sync(&cfhsi->aggregation_timer);
cfhsi->ops->cfhsi_rx_cancel(cfhsi->ops);
destroy_workqueue(cfhsi->wq);
tx_buf = cfhsi->tx_buf;
rx_buf = cfhsi->rx_buf;
flip_buf = cfhsi->rx_flip_buf;
cfhsi_abort_tx(cfhsi);
cfhsi->ops->cfhsi_down(cfhsi->ops);
kfree(tx_buf);
kfree(rx_buf);
kfree(flip_buf);
return 0;
}
static void cfhsi_uninit(struct net_device *dev)
{
struct cfhsi *cfhsi = netdev_priv(dev);
ASSERT_RTNL();
symbol_put(cfhsi_get_device);
list_del(&cfhsi->list);
}
static void cfhsi_netlink_parms(struct nlattr *data[], struct cfhsi *cfhsi)
{
int i;
if (!data) {
pr_debug("no params data found\n");
return;
}
i = __IFLA_CAIF_HSI_INACTIVITY_TOUT;
if (data[i]) {
u32 inactivity_timeout = nla_get_u32(data[i]);
cfhsi->cfg.inactivity_timeout = inactivity_timeout * HZ / 1000;
if (cfhsi->cfg.inactivity_timeout == 0)
cfhsi->cfg.inactivity_timeout = 1;
else if (cfhsi->cfg.inactivity_timeout > NEXT_TIMER_MAX_DELTA)
cfhsi->cfg.inactivity_timeout = NEXT_TIMER_MAX_DELTA;
}
i = __IFLA_CAIF_HSI_AGGREGATION_TOUT;
if (data[i])
cfhsi->cfg.aggregation_timeout = nla_get_u32(data[i]);
i = __IFLA_CAIF_HSI_HEAD_ALIGN;
if (data[i])
cfhsi->cfg.head_align = nla_get_u32(data[i]);
i = __IFLA_CAIF_HSI_TAIL_ALIGN;
if (data[i])
cfhsi->cfg.tail_align = nla_get_u32(data[i]);
i = __IFLA_CAIF_HSI_QHIGH_WATERMARK;
if (data[i])
cfhsi->cfg.q_high_mark = nla_get_u32(data[i]);
i = __IFLA_CAIF_HSI_QLOW_WATERMARK;
if (data[i])
cfhsi->cfg.q_low_mark = nla_get_u32(data[i]);
}
static int caif_hsi_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
cfhsi_netlink_parms(data, netdev_priv(dev));
netdev_state_change(dev);
return 0;
}
static size_t caif_hsi_get_size(const struct net_device *dev)
{
int i;
size_t s = 0;
for (i = __IFLA_CAIF_HSI_UNSPEC + 1; i < __IFLA_CAIF_HSI_MAX; i++)
s += nla_total_size(caif_hsi_policy[i].len);
return s;
}
static int caif_hsi_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct cfhsi *cfhsi = netdev_priv(dev);
if (nla_put_u32(skb, __IFLA_CAIF_HSI_INACTIVITY_TOUT,
cfhsi->cfg.inactivity_timeout) ||
nla_put_u32(skb, __IFLA_CAIF_HSI_AGGREGATION_TOUT,
cfhsi->cfg.aggregation_timeout) ||
nla_put_u32(skb, __IFLA_CAIF_HSI_HEAD_ALIGN,
cfhsi->cfg.head_align) ||
nla_put_u32(skb, __IFLA_CAIF_HSI_TAIL_ALIGN,
cfhsi->cfg.tail_align) ||
nla_put_u32(skb, __IFLA_CAIF_HSI_QHIGH_WATERMARK,
cfhsi->cfg.q_high_mark) ||
nla_put_u32(skb, __IFLA_CAIF_HSI_QLOW_WATERMARK,
cfhsi->cfg.q_low_mark))
return -EMSGSIZE;
return 0;
}
static int caif_hsi_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct cfhsi *cfhsi = NULL;
struct cfhsi_ops *(*get_ops)(void);
ASSERT_RTNL();
cfhsi = netdev_priv(dev);
cfhsi_netlink_parms(data, cfhsi);
get_ops = symbol_get(cfhsi_get_ops);
if (!get_ops) {
pr_err("%s: failed to get the cfhsi_ops\n", __func__);
return -ENODEV;
}
cfhsi->ops = (*get_ops)();
if (!cfhsi->ops) {
pr_err("%s: failed to get the cfhsi_ops\n", __func__);
goto err;
}
cfhsi->ops->cb_ops = &cfhsi->cb_ops;
if (register_netdevice(dev)) {
pr_warn("%s: caif_hsi device registration failed\n", __func__);
goto err;
}
list_add_tail(&cfhsi->list, &cfhsi_list);
return 0;
err:
symbol_put(cfhsi_get_ops);
return -ENODEV;
}
static void __exit cfhsi_exit_module(void)
{
struct list_head *list_node;
struct list_head *n;
struct cfhsi *cfhsi;
rtnl_link_unregister(&caif_hsi_link_ops);
rtnl_lock();
list_for_each_safe(list_node, n, &cfhsi_list) {
cfhsi = list_entry(list_node, struct cfhsi, list);
unregister_netdev(cfhsi->ndev);
}
rtnl_unlock();
}
static int __init cfhsi_init_module(void)
{
return rtnl_link_register(&caif_hsi_link_ops);
}
