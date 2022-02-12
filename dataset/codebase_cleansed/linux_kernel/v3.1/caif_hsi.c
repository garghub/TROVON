static void cfhsi_inactivity_tout(unsigned long arg)
{
struct cfhsi *cfhsi = (struct cfhsi *)arg;
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
if (!test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_down_work);
}
static void cfhsi_abort_tx(struct cfhsi *cfhsi)
{
struct sk_buff *skb;
for (;;) {
spin_lock_bh(&cfhsi->lock);
skb = skb_dequeue(&cfhsi->qhead);
if (!skb)
break;
cfhsi->ndev->stats.tx_errors++;
cfhsi->ndev->stats.tx_dropped++;
spin_unlock_bh(&cfhsi->lock);
kfree_skb(skb);
}
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
if (!test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
mod_timer(&cfhsi->timer, jiffies + CFHSI_INACTIVITY_TOUT);
spin_unlock_bh(&cfhsi->lock);
}
static int cfhsi_flush_fifo(struct cfhsi *cfhsi)
{
char buffer[32];
size_t fifo_occupancy;
int ret;
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
ret = cfhsi->dev->cfhsi_wake_up(cfhsi->dev);
if (ret) {
dev_warn(&cfhsi->ndev->dev,
"%s: can't wake up HSI interface: %d.\n",
__func__, ret);
return ret;
}
do {
ret = cfhsi->dev->cfhsi_fifo_occupancy(cfhsi->dev,
&fifo_occupancy);
if (ret) {
dev_warn(&cfhsi->ndev->dev,
"%s: can't get FIFO occupancy: %d.\n",
__func__, ret);
break;
} else if (!fifo_occupancy)
break;
fifo_occupancy = min(sizeof(buffer), fifo_occupancy);
set_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits);
ret = cfhsi->dev->cfhsi_rx(buffer, fifo_occupancy,
cfhsi->dev);
if (ret) {
clear_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits);
dev_warn(&cfhsi->ndev->dev,
"%s: can't read data: %d.\n",
__func__, ret);
break;
}
ret = 5 * HZ;
wait_event_interruptible_timeout(cfhsi->flush_fifo_wait,
!test_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits), ret);
if (ret < 0) {
dev_warn(&cfhsi->ndev->dev,
"%s: can't wait for flush complete: %d.\n",
__func__, ret);
break;
} else if (!ret) {
ret = -ETIMEDOUT;
dev_warn(&cfhsi->ndev->dev,
"%s: timeout waiting for flush complete.\n",
__func__);
break;
}
} while (1);
cfhsi->dev->cfhsi_wake_down(cfhsi->dev);
return ret;
}
static int cfhsi_tx_frm(struct cfhsi_desc *desc, struct cfhsi *cfhsi)
{
int nfrms = 0;
int pld_len = 0;
struct sk_buff *skb;
u8 *pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
skb = skb_dequeue(&cfhsi->qhead);
if (!skb)
return 0;
if (skb->len < CFHSI_MAX_EMB_FRM_SZ) {
struct caif_payload_info *info;
int hpad = 0;
int tpad = 0;
info = (struct caif_payload_info *)&skb->cb;
hpad = 1 + PAD_POW2((info->hdr_len + 1), hsi_head_align);
tpad = PAD_POW2((skb->len + hpad), hsi_tail_align);
if ((skb->len + hpad + tpad) <= CFHSI_MAX_EMB_FRM_SZ) {
u8 *pemb = desc->emb_frm;
desc->offset = CFHSI_DESC_SHORT_SZ;
*pemb = (u8)(hpad - 1);
pemb += hpad;
cfhsi->ndev->stats.tx_packets++;
cfhsi->ndev->stats.tx_bytes += skb->len;
skb_copy_bits(skb, 0, pemb, skb->len);
consume_skb(skb);
skb = NULL;
}
} else
desc->offset = 0;
pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
while (nfrms < CFHSI_MAX_PKTS) {
struct caif_payload_info *info;
int hpad = 0;
int tpad = 0;
if (!skb)
skb = skb_dequeue(&cfhsi->qhead);
if (!skb)
break;
info = (struct caif_payload_info *)&skb->cb;
hpad = 1 + PAD_POW2((info->hdr_len + 1), hsi_head_align);
tpad = PAD_POW2((skb->len + hpad), hsi_tail_align);
desc->cffrm_len[nfrms] = hpad + skb->len + tpad;
*pfrm = (u8)(hpad - 1);
pfrm += hpad;
cfhsi->ndev->stats.tx_packets++;
cfhsi->ndev->stats.tx_bytes += skb->len;
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
skb = skb_peek(&cfhsi->qhead);
if (skb)
desc->header |= CFHSI_PIGGY_DESC;
else
desc->header &= ~CFHSI_PIGGY_DESC;
return CFHSI_DESC_SZ + pld_len;
}
static void cfhsi_tx_done_work(struct work_struct *work)
{
struct cfhsi *cfhsi = NULL;
struct cfhsi_desc *desc = NULL;
int len = 0;
int res;
cfhsi = container_of(work, struct cfhsi, tx_done_work);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
desc = (struct cfhsi_desc *)cfhsi->tx_buf;
do {
spin_lock_bh(&cfhsi->lock);
if (cfhsi->flow_off_sent &&
cfhsi->qhead.qlen <= cfhsi->q_low_mark &&
cfhsi->cfdev.flowctrl) {
cfhsi->flow_off_sent = 0;
cfhsi->cfdev.flowctrl(cfhsi->ndev, ON);
}
spin_unlock_bh(&cfhsi->lock);
len = cfhsi_tx_frm(desc, cfhsi);
if (!len) {
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
mod_timer(&cfhsi->timer,
jiffies + CFHSI_INACTIVITY_TOUT);
break;
}
res = cfhsi->dev->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->dev);
if (WARN_ON(res < 0)) {
dev_err(&cfhsi->ndev->dev, "%s: TX error %d.\n",
__func__, res);
}
} while (res < 0);
}
static void cfhsi_tx_done_cb(struct cfhsi_drv *drv)
{
struct cfhsi *cfhsi;
cfhsi = container_of(drv, struct cfhsi, drv);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
queue_work(cfhsi->wq, &cfhsi->tx_done_work);
}
static int cfhsi_rx_desc(struct cfhsi_desc *desc, struct cfhsi *cfhsi)
{
int xfer_sz = 0;
int nfrms = 0;
u16 *plen = NULL;
u8 *pfrm = NULL;
if ((desc->header & ~CFHSI_PIGGY_DESC) ||
(desc->offset > CFHSI_MAX_EMB_FRM_SZ)) {
dev_err(&cfhsi->ndev->dev, "%s: Invalid descriptor.\n",
__func__);
return 0;
}
if (desc->offset) {
struct sk_buff *skb;
u8 *dst = NULL;
int len = 0, retries = 0;
pfrm = ((u8 *)desc) + desc->offset;
pfrm += *pfrm + 1;
len = *pfrm;
len |= ((*(pfrm+1)) << 8) & 0xFF00;
len += 2;
skb = alloc_skb(len + 1, GFP_KERNEL);
while (!skb) {
retries++;
schedule_timeout(1);
skb = alloc_skb(len + 1, GFP_KERNEL);
if (skb) {
printk(KERN_WARNING "%s: slept for %u "
"before getting memory\n",
__func__, retries);
break;
}
if (retries > HZ) {
printk(KERN_ERR "%s: slept for 1HZ and "
"did not get memory\n",
__func__);
cfhsi->ndev->stats.rx_dropped++;
goto drop_frame;
}
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
drop_frame:
plen = desc->cffrm_len;
while (nfrms < CFHSI_MAX_PKTS && *plen) {
xfer_sz += *plen;
plen++;
nfrms++;
}
if (desc->header & CFHSI_PIGGY_DESC)
xfer_sz += CFHSI_DESC_SZ;
if (xfer_sz % 4) {
dev_err(&cfhsi->ndev->dev,
"%s: Invalid payload len: %d, ignored.\n",
__func__, xfer_sz);
xfer_sz = 0;
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
dev_err(&cfhsi->ndev->dev, "%s: Invalid descriptor.\n",
__func__);
return -EINVAL;
}
pfrm = desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ;
plen = desc->cffrm_len;
while (nfrms < CFHSI_MAX_PKTS && *plen) {
struct sk_buff *skb;
u8 *dst = NULL;
u8 *pcffrm = NULL;
int len = 0, retries = 0;
if (WARN_ON(desc->cffrm_len[nfrms] > CFHSI_MAX_PAYLOAD_SZ)) {
dev_err(&cfhsi->ndev->dev, "%s: Invalid payload.\n",
__func__);
return -EINVAL;
}
pcffrm = pfrm + *pfrm + 1;
len = *pcffrm;
len |= ((*(pcffrm + 1)) << 8) & 0xFF00;
len += 2;
skb = alloc_skb(len + 1, GFP_KERNEL);
while (!skb) {
retries++;
schedule_timeout(1);
skb = alloc_skb(len + 1, GFP_KERNEL);
if (skb) {
printk(KERN_WARNING "%s: slept for %u "
"before getting memory\n",
__func__, retries);
break;
}
if (retries > HZ) {
printk(KERN_ERR "%s: slept for 1HZ "
"and did not get memory\n",
__func__);
cfhsi->ndev->stats.rx_dropped++;
goto drop_frame;
}
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
drop_frame:
pfrm += *plen;
rx_sz += *plen;
plen++;
nfrms++;
}
return rx_sz;
}
static void cfhsi_rx_done_work(struct work_struct *work)
{
int res;
int desc_pld_len = 0;
struct cfhsi *cfhsi = NULL;
struct cfhsi_desc *desc = NULL;
cfhsi = container_of(work, struct cfhsi, rx_done_work);
desc = (struct cfhsi_desc *)cfhsi->rx_buf;
dev_dbg(&cfhsi->ndev->dev, "%s: Kick timer if pending.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
mod_timer_pending(&cfhsi->timer, jiffies + CFHSI_INACTIVITY_TOUT);
if (cfhsi->rx_state == CFHSI_RX_STATE_DESC) {
desc_pld_len = cfhsi_rx_desc(desc, cfhsi);
} else {
int pld_len;
pld_len = cfhsi_rx_pld(desc, cfhsi);
if ((pld_len > 0) && (desc->header & CFHSI_PIGGY_DESC)) {
struct cfhsi_desc *piggy_desc;
piggy_desc = (struct cfhsi_desc *)
(desc->emb_frm + CFHSI_MAX_EMB_FRM_SZ +
pld_len);
desc_pld_len = cfhsi_rx_desc(piggy_desc, cfhsi);
memcpy((u8 *)desc, (u8 *)piggy_desc,
CFHSI_DESC_SHORT_SZ);
}
}
if (desc_pld_len) {
cfhsi->rx_state = CFHSI_RX_STATE_PAYLOAD;
cfhsi->rx_ptr = cfhsi->rx_buf + CFHSI_DESC_SZ;
cfhsi->rx_len = desc_pld_len;
} else {
cfhsi->rx_state = CFHSI_RX_STATE_DESC;
cfhsi->rx_ptr = cfhsi->rx_buf;
cfhsi->rx_len = CFHSI_DESC_SZ;
}
clear_bit(CFHSI_PENDING_RX, &cfhsi->bits);
if (test_bit(CFHSI_AWAKE, &cfhsi->bits)) {
dev_dbg(&cfhsi->ndev->dev, "%s: Start RX.\n",
__func__);
res = cfhsi->dev->cfhsi_rx(cfhsi->rx_ptr, cfhsi->rx_len,
cfhsi->dev);
if (WARN_ON(res < 0)) {
dev_err(&cfhsi->ndev->dev, "%s: RX error %d.\n",
__func__, res);
cfhsi->ndev->stats.rx_errors++;
cfhsi->ndev->stats.rx_dropped++;
}
}
}
static void cfhsi_rx_done_cb(struct cfhsi_drv *drv)
{
struct cfhsi *cfhsi;
cfhsi = container_of(drv, struct cfhsi, drv);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
set_bit(CFHSI_PENDING_RX, &cfhsi->bits);
if (test_and_clear_bit(CFHSI_FLUSH_FIFO, &cfhsi->bits))
wake_up_interruptible(&cfhsi->flush_fifo_wait);
else
queue_work(cfhsi->wq, &cfhsi->rx_done_work);
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
return;
}
cfhsi->dev->cfhsi_wake_up(cfhsi->dev);
dev_dbg(&cfhsi->ndev->dev, "%s: Start waiting.\n",
__func__);
ret = CFHSI_WAKEUP_TOUT;
wait_event_interruptible_timeout(cfhsi->wake_up_wait,
test_bit(CFHSI_WAKE_UP_ACK,
&cfhsi->bits), ret);
if (unlikely(ret < 0)) {
dev_info(&cfhsi->ndev->dev, "%s: Signalled: %ld.\n",
__func__, ret);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
cfhsi->dev->cfhsi_wake_down(cfhsi->dev);
return;
} else if (!ret) {
dev_err(&cfhsi->ndev->dev, "%s: Timeout.\n",
__func__);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
cfhsi->dev->cfhsi_wake_down(cfhsi->dev);
return;
}
dev_dbg(&cfhsi->ndev->dev, "%s: Woken.\n",
__func__);
set_bit(CFHSI_AWAKE, &cfhsi->bits);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
if (!test_bit(CFHSI_PENDING_RX, &cfhsi->bits)) {
dev_dbg(&cfhsi->ndev->dev, "%s: Start RX.\n",
__func__);
res = cfhsi->dev->cfhsi_rx(cfhsi->rx_ptr,
cfhsi->rx_len, cfhsi->dev);
if (WARN_ON(res < 0)) {
dev_err(&cfhsi->ndev->dev, "%s: RX error %d.\n",
__func__, res);
}
}
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
spin_lock_bh(&cfhsi->lock);
if (!skb_peek(&cfhsi->qhead)) {
dev_dbg(&cfhsi->ndev->dev, "%s: Peer wake, start timer.\n",
__func__);
mod_timer(&cfhsi->timer,
jiffies + CFHSI_INACTIVITY_TOUT);
spin_unlock_bh(&cfhsi->lock);
return;
}
dev_dbg(&cfhsi->ndev->dev, "%s: Host wake.\n",
__func__);
spin_unlock_bh(&cfhsi->lock);
len = cfhsi_tx_frm((struct cfhsi_desc *)cfhsi->tx_buf, cfhsi);
if (likely(len > 0)) {
res = cfhsi->dev->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->dev);
if (WARN_ON(res < 0)) {
dev_err(&cfhsi->ndev->dev, "%s: TX error %d.\n",
__func__, res);
cfhsi_abort_tx(cfhsi);
}
} else {
dev_err(&cfhsi->ndev->dev,
"%s: Failed to create HSI frame: %d.\n",
__func__, len);
}
}
static void cfhsi_wake_down(struct work_struct *work)
{
long ret;
struct cfhsi *cfhsi = NULL;
size_t fifo_occupancy;
cfhsi = container_of(work, struct cfhsi, wake_down_work);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
if (WARN_ON(cfhsi->dev->cfhsi_fifo_occupancy(cfhsi->dev,
&fifo_occupancy)))
fifo_occupancy = 0;
if (fifo_occupancy) {
dev_dbg(&cfhsi->ndev->dev,
"%s: %u words in RX FIFO, restart timer.\n",
__func__, (unsigned) fifo_occupancy);
spin_lock_bh(&cfhsi->lock);
mod_timer(&cfhsi->timer,
jiffies + CFHSI_INACTIVITY_TOUT);
spin_unlock_bh(&cfhsi->lock);
return;
}
cfhsi->dev->cfhsi_rx_cancel(cfhsi->dev);
cfhsi->dev->cfhsi_wake_down(cfhsi->dev);
ret = CFHSI_WAKEUP_TOUT;
ret = wait_event_interruptible_timeout(cfhsi->wake_down_wait,
test_bit(CFHSI_WAKE_DOWN_ACK,
&cfhsi->bits),
ret);
if (ret < 0) {
dev_info(&cfhsi->ndev->dev, "%s: Signalled: %ld.\n",
__func__, ret);
return;
} else if (!ret) {
dev_err(&cfhsi->ndev->dev, "%s: Timeout.\n",
__func__);
}
clear_bit(CFHSI_WAKE_DOWN_ACK, &cfhsi->bits);
clear_bit(CFHSI_AWAKE, &cfhsi->bits);
if (WARN_ON(cfhsi->dev->cfhsi_fifo_occupancy(cfhsi->dev,
&fifo_occupancy)))
fifo_occupancy = 0;
if (fifo_occupancy) {
dev_dbg(&cfhsi->ndev->dev,
"%s: %u words in RX FIFO, wakeup forced.\n",
__func__, (unsigned) fifo_occupancy);
if (!test_and_set_bit(CFHSI_WAKE_UP, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_up_work);
} else
dev_dbg(&cfhsi->ndev->dev, "%s: Done.\n",
__func__);
}
static void cfhsi_wake_up_cb(struct cfhsi_drv *drv)
{
struct cfhsi *cfhsi = NULL;
cfhsi = container_of(drv, struct cfhsi, drv);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
set_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
wake_up_interruptible(&cfhsi->wake_up_wait);
if (test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))
return;
if (!test_and_set_bit(CFHSI_WAKE_UP, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_up_work);
}
static void cfhsi_wake_down_cb(struct cfhsi_drv *drv)
{
struct cfhsi *cfhsi = NULL;
cfhsi = container_of(drv, struct cfhsi, drv);
dev_dbg(&cfhsi->ndev->dev, "%s.\n",
__func__);
set_bit(CFHSI_WAKE_DOWN_ACK, &cfhsi->bits);
wake_up_interruptible(&cfhsi->wake_down_wait);
}
static int cfhsi_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct cfhsi *cfhsi = NULL;
int start_xfer = 0;
int timer_active;
if (!dev)
return -EINVAL;
cfhsi = netdev_priv(dev);
spin_lock_bh(&cfhsi->lock);
skb_queue_tail(&cfhsi->qhead, skb);
if (WARN_ON(test_bit(CFHSI_SHUTDOWN, &cfhsi->bits))) {
spin_unlock_bh(&cfhsi->lock);
cfhsi_abort_tx(cfhsi);
return -EINVAL;
}
if (!cfhsi->flow_off_sent &&
cfhsi->qhead.qlen > cfhsi->q_high_mark &&
cfhsi->cfdev.flowctrl) {
cfhsi->flow_off_sent = 1;
cfhsi->cfdev.flowctrl(cfhsi->ndev, OFF);
}
if (cfhsi->tx_state == CFHSI_TX_STATE_IDLE) {
cfhsi->tx_state = CFHSI_TX_STATE_XFER;
start_xfer = 1;
}
spin_unlock_bh(&cfhsi->lock);
if (!start_xfer)
return 0;
#ifdef CONFIG_SMP
timer_active = del_timer_sync(&cfhsi->timer);
#else
timer_active = del_timer(&cfhsi->timer);
#endif
if (timer_active) {
struct cfhsi_desc *desc = (struct cfhsi_desc *)cfhsi->tx_buf;
int len;
int res;
len = cfhsi_tx_frm(desc, cfhsi);
BUG_ON(!len);
res = cfhsi->dev->cfhsi_tx(cfhsi->tx_buf, len, cfhsi->dev);
if (WARN_ON(res < 0)) {
dev_err(&cfhsi->ndev->dev, "%s: TX error %d.\n",
__func__, res);
cfhsi_abort_tx(cfhsi);
}
} else {
if (!test_and_set_bit(CFHSI_WAKE_UP, &cfhsi->bits))
queue_work(cfhsi->wq, &cfhsi->wake_up_work);
}
return 0;
}
static int cfhsi_open(struct net_device *dev)
{
netif_wake_queue(dev);
return 0;
}
static int cfhsi_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static void cfhsi_setup(struct net_device *dev)
{
struct cfhsi *cfhsi = netdev_priv(dev);
dev->features = 0;
dev->netdev_ops = &cfhsi_ops;
dev->type = ARPHRD_CAIF;
dev->flags = IFF_POINTOPOINT | IFF_NOARP;
dev->mtu = CFHSI_MAX_PAYLOAD_SZ;
dev->tx_queue_len = 0;
dev->destructor = free_netdev;
skb_queue_head_init(&cfhsi->qhead);
cfhsi->cfdev.link_select = CAIF_LINK_HIGH_BANDW;
cfhsi->cfdev.use_frag = false;
cfhsi->cfdev.use_stx = false;
cfhsi->cfdev.use_fcs = false;
cfhsi->ndev = dev;
}
int cfhsi_probe(struct platform_device *pdev)
{
struct cfhsi *cfhsi = NULL;
struct net_device *ndev;
struct cfhsi_dev *dev;
int res;
ndev = alloc_netdev(sizeof(struct cfhsi), "cfhsi%d", cfhsi_setup);
if (!ndev) {
dev_err(&pdev->dev, "%s: alloc_netdev failed.\n",
__func__);
return -ENODEV;
}
cfhsi = netdev_priv(ndev);
cfhsi->ndev = ndev;
cfhsi->pdev = pdev;
cfhsi->tx_state = CFHSI_TX_STATE_IDLE;
cfhsi->rx_state = CFHSI_RX_STATE_DESC;
cfhsi->flow_off_sent = 0;
cfhsi->q_low_mark = LOW_WATER_MARK;
cfhsi->q_high_mark = HIGH_WATER_MARK;
dev = (struct cfhsi_dev *)pdev->dev.platform_data;
cfhsi->dev = dev;
dev->drv = &cfhsi->drv;
cfhsi->tx_buf = kzalloc(CFHSI_BUF_SZ_TX, GFP_KERNEL);
if (!cfhsi->tx_buf) {
dev_err(&ndev->dev, "%s: Failed to allocate TX buffer.\n",
__func__);
res = -ENODEV;
goto err_alloc_tx;
}
cfhsi->rx_buf = kzalloc(CFHSI_BUF_SZ_RX, GFP_KERNEL);
if (!cfhsi->rx_buf) {
dev_err(&ndev->dev, "%s: Failed to allocate RX buffer.\n",
__func__);
res = -ENODEV;
goto err_alloc_rx;
}
cfhsi->rx_ptr = cfhsi->rx_buf;
cfhsi->rx_len = CFHSI_DESC_SZ;
spin_lock_init(&cfhsi->lock);
cfhsi->drv.tx_done_cb = cfhsi_tx_done_cb;
cfhsi->drv.rx_done_cb = cfhsi_rx_done_cb;
INIT_WORK(&cfhsi->wake_up_work, cfhsi_wake_up);
INIT_WORK(&cfhsi->wake_down_work, cfhsi_wake_down);
INIT_WORK(&cfhsi->rx_done_work, cfhsi_rx_done_work);
INIT_WORK(&cfhsi->tx_done_work, cfhsi_tx_done_work);
clear_bit(CFHSI_WAKE_UP_ACK, &cfhsi->bits);
clear_bit(CFHSI_WAKE_DOWN_ACK, &cfhsi->bits);
clear_bit(CFHSI_WAKE_UP, &cfhsi->bits);
clear_bit(CFHSI_AWAKE, &cfhsi->bits);
clear_bit(CFHSI_PENDING_RX, &cfhsi->bits);
cfhsi->wq = create_singlethread_workqueue(pdev->name);
if (!cfhsi->wq) {
dev_err(&ndev->dev, "%s: Failed to create work queue.\n",
__func__);
res = -ENODEV;
goto err_create_wq;
}
init_waitqueue_head(&cfhsi->wake_up_wait);
init_waitqueue_head(&cfhsi->wake_down_wait);
init_waitqueue_head(&cfhsi->flush_fifo_wait);
init_timer(&cfhsi->timer);
cfhsi->timer.data = (unsigned long)cfhsi;
cfhsi->timer.function = cfhsi_inactivity_tout;
spin_lock(&cfhsi_list_lock);
list_add_tail(&cfhsi->list, &cfhsi_list);
spin_unlock(&cfhsi_list_lock);
res = cfhsi->dev->cfhsi_up(cfhsi->dev);
if (res) {
dev_err(&cfhsi->ndev->dev,
"%s: can't activate HSI interface: %d.\n",
__func__, res);
goto err_activate;
}
res = cfhsi_flush_fifo(cfhsi);
if (res) {
dev_err(&ndev->dev, "%s: Can't flush FIFO: %d.\n",
__func__, res);
goto err_net_reg;
}
cfhsi->drv.wake_up_cb = cfhsi_wake_up_cb;
cfhsi->drv.wake_down_cb = cfhsi_wake_down_cb;
res = register_netdev(ndev);
if (res) {
dev_err(&ndev->dev, "%s: Registration error: %d.\n",
__func__, res);
goto err_net_reg;
}
netif_stop_queue(ndev);
return res;
err_net_reg:
cfhsi->dev->cfhsi_down(cfhsi->dev);
err_activate:
destroy_workqueue(cfhsi->wq);
err_create_wq:
kfree(cfhsi->rx_buf);
err_alloc_rx:
kfree(cfhsi->tx_buf);
err_alloc_tx:
free_netdev(ndev);
return res;
}
static void cfhsi_shutdown(struct cfhsi *cfhsi, bool remove_platform_dev)
{
u8 *tx_buf, *rx_buf;
netif_tx_stop_all_queues(cfhsi->ndev);
set_bit(CFHSI_SHUTDOWN, &cfhsi->bits);
if (remove_platform_dev) {
flush_workqueue(cfhsi->wq);
platform_device_unregister(cfhsi->pdev);
}
flush_workqueue(cfhsi->wq);
#ifdef CONFIG_SMP
del_timer_sync(&cfhsi->timer);
#else
del_timer(&cfhsi->timer);
#endif
cfhsi->dev->cfhsi_rx_cancel(cfhsi->dev);
destroy_workqueue(cfhsi->wq);
tx_buf = cfhsi->tx_buf;
rx_buf = cfhsi->rx_buf;
cfhsi_abort_tx(cfhsi);
cfhsi->dev->cfhsi_down(cfhsi->dev);
unregister_netdev(cfhsi->ndev);
kfree(tx_buf);
kfree(rx_buf);
}
int cfhsi_remove(struct platform_device *pdev)
{
struct list_head *list_node;
struct list_head *n;
struct cfhsi *cfhsi = NULL;
struct cfhsi_dev *dev;
dev = (struct cfhsi_dev *)pdev->dev.platform_data;
spin_lock(&cfhsi_list_lock);
list_for_each_safe(list_node, n, &cfhsi_list) {
cfhsi = list_entry(list_node, struct cfhsi, list);
if (cfhsi->dev == dev) {
list_del(list_node);
spin_unlock(&cfhsi_list_lock);
cfhsi_shutdown(cfhsi, false);
return 0;
}
}
spin_unlock(&cfhsi_list_lock);
return -ENODEV;
}
static void __exit cfhsi_exit_module(void)
{
struct list_head *list_node;
struct list_head *n;
struct cfhsi *cfhsi = NULL;
spin_lock(&cfhsi_list_lock);
list_for_each_safe(list_node, n, &cfhsi_list) {
cfhsi = list_entry(list_node, struct cfhsi, list);
list_del(list_node);
spin_unlock(&cfhsi_list_lock);
cfhsi_shutdown(cfhsi, true);
spin_lock(&cfhsi_list_lock);
}
spin_unlock(&cfhsi_list_lock);
platform_driver_unregister(&cfhsi_plat_drv);
}
static int __init cfhsi_init_module(void)
{
int result;
spin_lock_init(&cfhsi_list_lock);
result = platform_driver_register(&cfhsi_plat_drv);
if (result) {
printk(KERN_ERR "Could not register platform HSI driver: %d.\n",
result);
goto err_dev_register;
}
return result;
err_dev_register:
return result;
}
