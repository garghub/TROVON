static void
bnad_cq_cmpl_init(struct bnad *bnad, struct bna_ccb *ccb)
{
struct bna_cq_entry *cmpl, *next_cmpl;
unsigned int wi_range, wis = 0, ccb_prod = 0;
int i;
BNA_CQ_QPGE_PTR_GET(ccb_prod, ccb->sw_qpt, cmpl,
wi_range);
for (i = 0; i < ccb->q_depth; i++) {
wis++;
if (likely(--wi_range))
next_cmpl = cmpl + 1;
else {
BNA_QE_INDX_ADD(ccb_prod, wis, ccb->q_depth);
wis = 0;
BNA_CQ_QPGE_PTR_GET(ccb_prod, ccb->sw_qpt,
next_cmpl, wi_range);
}
cmpl->valid = 0;
cmpl = next_cmpl;
}
}
static void
bnad_free_all_txbufs(struct bnad *bnad,
struct bna_tcb *tcb)
{
u32 unmap_cons;
struct bnad_unmap_q *unmap_q = tcb->unmap_q;
struct bnad_skb_unmap *unmap_array;
struct sk_buff *skb = NULL;
int i;
unmap_array = unmap_q->unmap_array;
unmap_cons = 0;
while (unmap_cons < unmap_q->q_depth) {
skb = unmap_array[unmap_cons].skb;
if (!skb) {
unmap_cons++;
continue;
}
unmap_array[unmap_cons].skb = NULL;
dma_unmap_single(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr), skb_headlen(skb),
DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_array[unmap_cons], dma_addr, 0);
if (++unmap_cons >= unmap_q->q_depth)
break;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
dma_unmap_page(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr),
skb_shinfo(skb)->frags[i].size,
DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_array[unmap_cons], dma_addr,
0);
if (++unmap_cons >= unmap_q->q_depth)
break;
}
dev_kfree_skb_any(skb);
}
}
static u32
bnad_free_txbufs(struct bnad *bnad,
struct bna_tcb *tcb)
{
u32 sent_packets = 0, sent_bytes = 0;
u16 wis, unmap_cons, updated_hw_cons;
struct bnad_unmap_q *unmap_q = tcb->unmap_q;
struct bnad_skb_unmap *unmap_array;
struct sk_buff *skb;
int i;
if (!test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags))
return 0;
updated_hw_cons = *(tcb->hw_consumer_index);
wis = BNA_Q_INDEX_CHANGE(tcb->consumer_index,
updated_hw_cons, tcb->q_depth);
BUG_ON(!(wis <= BNA_QE_IN_USE_CNT(tcb, tcb->q_depth)));
unmap_array = unmap_q->unmap_array;
unmap_cons = unmap_q->consumer_index;
prefetch(&unmap_array[unmap_cons + 1]);
while (wis) {
skb = unmap_array[unmap_cons].skb;
unmap_array[unmap_cons].skb = NULL;
sent_packets++;
sent_bytes += skb->len;
wis -= BNA_TXQ_WI_NEEDED(1 + skb_shinfo(skb)->nr_frags);
dma_unmap_single(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr), skb_headlen(skb),
DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_array[unmap_cons], dma_addr, 0);
BNA_QE_INDX_ADD(unmap_cons, 1, unmap_q->q_depth);
prefetch(&unmap_array[unmap_cons + 1]);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
prefetch(&unmap_array[unmap_cons + 1]);
dma_unmap_page(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr),
skb_shinfo(skb)->frags[i].size,
DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_array[unmap_cons], dma_addr,
0);
BNA_QE_INDX_ADD(unmap_cons, 1, unmap_q->q_depth);
}
dev_kfree_skb_any(skb);
}
tcb->consumer_index = updated_hw_cons;
unmap_q->consumer_index = unmap_cons;
tcb->txq->tx_packets += sent_packets;
tcb->txq->tx_bytes += sent_bytes;
return sent_packets;
}
static void
bnad_tx_free_tasklet(unsigned long bnad_ptr)
{
struct bnad *bnad = (struct bnad *)bnad_ptr;
struct bna_tcb *tcb;
u32 acked = 0;
int i, j;
for (i = 0; i < bnad->num_tx; i++) {
for (j = 0; j < bnad->num_txq_per_tx; j++) {
tcb = bnad->tx_info[i].tcb[j];
if (!tcb)
continue;
if (((u16) (*tcb->hw_consumer_index) !=
tcb->consumer_index) &&
(!test_and_set_bit(BNAD_TXQ_FREE_SENT,
&tcb->flags))) {
acked = bnad_free_txbufs(bnad, tcb);
if (likely(test_bit(BNAD_TXQ_TX_STARTED,
&tcb->flags)))
bna_ib_ack(tcb->i_dbell, acked);
smp_mb__before_clear_bit();
clear_bit(BNAD_TXQ_FREE_SENT, &tcb->flags);
}
if (unlikely(!test_bit(BNAD_TXQ_TX_STARTED,
&tcb->flags)))
continue;
if (netif_queue_stopped(bnad->netdev)) {
if (acked && netif_carrier_ok(bnad->netdev) &&
BNA_QE_FREE_CNT(tcb, tcb->q_depth) >=
BNAD_NETIF_WAKE_THRESHOLD) {
netif_wake_queue(bnad->netdev);
BNAD_UPDATE_CTR(bnad,
netif_queue_wakeup);
}
}
}
}
}
static u32
bnad_tx(struct bnad *bnad, struct bna_tcb *tcb)
{
struct net_device *netdev = bnad->netdev;
u32 sent = 0;
if (test_and_set_bit(BNAD_TXQ_FREE_SENT, &tcb->flags))
return 0;
sent = bnad_free_txbufs(bnad, tcb);
if (sent) {
if (netif_queue_stopped(netdev) &&
netif_carrier_ok(netdev) &&
BNA_QE_FREE_CNT(tcb, tcb->q_depth) >=
BNAD_NETIF_WAKE_THRESHOLD) {
if (test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags)) {
netif_wake_queue(netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_wakeup);
}
}
}
if (likely(test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags)))
bna_ib_ack(tcb->i_dbell, sent);
smp_mb__before_clear_bit();
clear_bit(BNAD_TXQ_FREE_SENT, &tcb->flags);
return sent;
}
static irqreturn_t
bnad_msix_tx(int irq, void *data)
{
struct bna_tcb *tcb = (struct bna_tcb *)data;
struct bnad *bnad = tcb->bnad;
bnad_tx(bnad, tcb);
return IRQ_HANDLED;
}
static void
bnad_reset_rcb(struct bnad *bnad, struct bna_rcb *rcb)
{
struct bnad_unmap_q *unmap_q = rcb->unmap_q;
rcb->producer_index = 0;
rcb->consumer_index = 0;
unmap_q->producer_index = 0;
unmap_q->consumer_index = 0;
}
static void
bnad_free_all_rxbufs(struct bnad *bnad, struct bna_rcb *rcb)
{
struct bnad_unmap_q *unmap_q;
struct bnad_skb_unmap *unmap_array;
struct sk_buff *skb;
int unmap_cons;
unmap_q = rcb->unmap_q;
unmap_array = unmap_q->unmap_array;
for (unmap_cons = 0; unmap_cons < unmap_q->q_depth; unmap_cons++) {
skb = unmap_array[unmap_cons].skb;
if (!skb)
continue;
unmap_array[unmap_cons].skb = NULL;
dma_unmap_single(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr),
rcb->rxq->buffer_size,
DMA_FROM_DEVICE);
dev_kfree_skb(skb);
}
bnad_reset_rcb(bnad, rcb);
}
static void
bnad_alloc_n_post_rxbufs(struct bnad *bnad, struct bna_rcb *rcb)
{
u16 to_alloc, alloced, unmap_prod, wi_range;
struct bnad_unmap_q *unmap_q = rcb->unmap_q;
struct bnad_skb_unmap *unmap_array;
struct bna_rxq_entry *rxent;
struct sk_buff *skb;
dma_addr_t dma_addr;
alloced = 0;
to_alloc =
BNA_QE_FREE_CNT(unmap_q, unmap_q->q_depth);
unmap_array = unmap_q->unmap_array;
unmap_prod = unmap_q->producer_index;
BNA_RXQ_QPGE_PTR_GET(unmap_prod, rcb->sw_qpt, rxent, wi_range);
while (to_alloc--) {
if (!wi_range) {
BNA_RXQ_QPGE_PTR_GET(unmap_prod, rcb->sw_qpt, rxent,
wi_range);
}
skb = netdev_alloc_skb_ip_align(bnad->netdev,
rcb->rxq->buffer_size);
if (unlikely(!skb)) {
BNAD_UPDATE_CTR(bnad, rxbuf_alloc_failed);
goto finishing;
}
unmap_array[unmap_prod].skb = skb;
dma_addr = dma_map_single(&bnad->pcidev->dev, skb->data,
rcb->rxq->buffer_size,
DMA_FROM_DEVICE);
dma_unmap_addr_set(&unmap_array[unmap_prod], dma_addr,
dma_addr);
BNA_SET_DMA_ADDR(dma_addr, &rxent->host_addr);
BNA_QE_INDX_ADD(unmap_prod, 1, unmap_q->q_depth);
rxent++;
wi_range--;
alloced++;
}
finishing:
if (likely(alloced)) {
unmap_q->producer_index = unmap_prod;
rcb->producer_index = unmap_prod;
smp_mb();
if (likely(test_bit(BNAD_RXQ_STARTED, &rcb->flags)))
bna_rxq_prod_indx_doorbell(rcb);
}
}
static inline void
bnad_refill_rxq(struct bnad *bnad, struct bna_rcb *rcb)
{
struct bnad_unmap_q *unmap_q = rcb->unmap_q;
if (!test_and_set_bit(BNAD_RXQ_REFILL, &rcb->flags)) {
if (BNA_QE_FREE_CNT(unmap_q, unmap_q->q_depth)
>> BNAD_RXQ_REFILL_THRESHOLD_SHIFT)
bnad_alloc_n_post_rxbufs(bnad, rcb);
smp_mb__before_clear_bit();
clear_bit(BNAD_RXQ_REFILL, &rcb->flags);
}
}
static u32
bnad_poll_cq(struct bnad *bnad, struct bna_ccb *ccb, int budget)
{
struct bna_cq_entry *cmpl, *next_cmpl;
struct bna_rcb *rcb = NULL;
unsigned int wi_range, packets = 0, wis = 0;
struct bnad_unmap_q *unmap_q;
struct bnad_skb_unmap *unmap_array;
struct sk_buff *skb;
u32 flags, unmap_cons;
u32 qid0 = ccb->rcb[0]->rxq->rxq_id;
struct bna_pkt_rate *pkt_rt = &ccb->pkt_rate;
if (!test_bit(BNAD_RXQ_STARTED, &ccb->rcb[0]->flags))
return 0;
prefetch(bnad->netdev);
BNA_CQ_QPGE_PTR_GET(ccb->producer_index, ccb->sw_qpt, cmpl,
wi_range);
BUG_ON(!(wi_range <= ccb->q_depth));
while (cmpl->valid && packets < budget) {
packets++;
BNA_UPDATE_PKT_CNT(pkt_rt, ntohs(cmpl->length));
if (qid0 == cmpl->rxq_id)
rcb = ccb->rcb[0];
else
rcb = ccb->rcb[1];
unmap_q = rcb->unmap_q;
unmap_array = unmap_q->unmap_array;
unmap_cons = unmap_q->consumer_index;
skb = unmap_array[unmap_cons].skb;
BUG_ON(!(skb));
unmap_array[unmap_cons].skb = NULL;
dma_unmap_single(&bnad->pcidev->dev,
dma_unmap_addr(&unmap_array[unmap_cons],
dma_addr),
rcb->rxq->buffer_size,
DMA_FROM_DEVICE);
BNA_QE_INDX_ADD(unmap_q->consumer_index, 1, unmap_q->q_depth);
BNA_QE_INDX_ADD(rcb->consumer_index, 1, rcb->q_depth);
wis++;
if (likely(--wi_range))
next_cmpl = cmpl + 1;
else {
BNA_QE_INDX_ADD(ccb->producer_index, wis, ccb->q_depth);
wis = 0;
BNA_CQ_QPGE_PTR_GET(ccb->producer_index, ccb->sw_qpt,
next_cmpl, wi_range);
BUG_ON(!(wi_range <= ccb->q_depth));
}
prefetch(next_cmpl);
flags = ntohl(cmpl->flags);
if (unlikely
(flags &
(BNA_CQ_EF_MAC_ERROR | BNA_CQ_EF_FCS_ERROR |
BNA_CQ_EF_TOO_LONG))) {
dev_kfree_skb_any(skb);
rcb->rxq->rx_packets_with_error++;
goto next;
}
skb_put(skb, ntohs(cmpl->length));
if (likely
((bnad->netdev->features & NETIF_F_RXCSUM) &&
(((flags & BNA_CQ_EF_IPV4) &&
(flags & BNA_CQ_EF_L3_CKSUM_OK)) ||
(flags & BNA_CQ_EF_IPV6)) &&
(flags & (BNA_CQ_EF_TCP | BNA_CQ_EF_UDP)) &&
(flags & BNA_CQ_EF_L4_CKSUM_OK)))
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb_checksum_none_assert(skb);
rcb->rxq->rx_packets++;
rcb->rxq->rx_bytes += skb->len;
skb->protocol = eth_type_trans(skb, bnad->netdev);
if (flags & BNA_CQ_EF_VLAN)
__vlan_hwaccel_put_tag(skb, ntohs(cmpl->vlan_tag));
if (skb->ip_summed == CHECKSUM_UNNECESSARY) {
struct bnad_rx_ctrl *rx_ctrl;
rx_ctrl = (struct bnad_rx_ctrl *) ccb->ctrl;
napi_gro_receive(&rx_ctrl->napi, skb);
} else {
netif_receive_skb(skb);
}
next:
cmpl->valid = 0;
cmpl = next_cmpl;
}
BNA_QE_INDX_ADD(ccb->producer_index, wis, ccb->q_depth);
if (likely(ccb)) {
if (likely(test_bit(BNAD_RXQ_STARTED, &ccb->rcb[0]->flags)))
bna_ib_ack(ccb->i_dbell, packets);
bnad_refill_rxq(bnad, ccb->rcb[0]);
if (ccb->rcb[1])
bnad_refill_rxq(bnad, ccb->rcb[1]);
} else {
if (likely(test_bit(BNAD_RXQ_STARTED, &ccb->rcb[0]->flags)))
bna_ib_ack(ccb->i_dbell, 0);
}
return packets;
}
static void
bnad_disable_rx_irq(struct bnad *bnad, struct bna_ccb *ccb)
{
if (unlikely(!test_bit(BNAD_RXQ_STARTED, &ccb->rcb[0]->flags)))
return;
bna_ib_coalescing_timer_set(ccb->i_dbell, 0);
bna_ib_ack(ccb->i_dbell, 0);
}
static void
bnad_enable_rx_irq(struct bnad *bnad, struct bna_ccb *ccb)
{
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_enable_rx_irq_unsafe(ccb);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_netif_rx_schedule_poll(struct bnad *bnad, struct bna_ccb *ccb)
{
struct bnad_rx_ctrl *rx_ctrl = (struct bnad_rx_ctrl *)(ccb->ctrl);
struct napi_struct *napi = &rx_ctrl->napi;
if (likely(napi_schedule_prep(napi))) {
bnad_disable_rx_irq(bnad, ccb);
__napi_schedule(napi);
}
BNAD_UPDATE_CTR(bnad, netif_rx_schedule);
}
static irqreturn_t
bnad_msix_rx(int irq, void *data)
{
struct bna_ccb *ccb = (struct bna_ccb *)data;
struct bnad *bnad = ccb->bnad;
bnad_netif_rx_schedule_poll(bnad, ccb);
return IRQ_HANDLED;
}
static irqreturn_t
bnad_msix_mbox_handler(int irq, void *data)
{
u32 intr_status;
unsigned long flags;
struct bnad *bnad = (struct bnad *)data;
if (unlikely(test_bit(BNAD_RF_MBOX_IRQ_DISABLED, &bnad->run_flags)))
return IRQ_HANDLED;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_intr_status_get(&bnad->bna, intr_status);
if (BNA_IS_MBOX_ERR_INTR(intr_status))
bna_mbox_handler(&bnad->bna, intr_status);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t
bnad_isr(int irq, void *data)
{
int i, j;
u32 intr_status;
unsigned long flags;
struct bnad *bnad = (struct bnad *)data;
struct bnad_rx_info *rx_info;
struct bnad_rx_ctrl *rx_ctrl;
if (unlikely(test_bit(BNAD_RF_MBOX_IRQ_DISABLED, &bnad->run_flags)))
return IRQ_NONE;
bna_intr_status_get(&bnad->bna, intr_status);
if (unlikely(!intr_status))
return IRQ_NONE;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (BNA_IS_MBOX_ERR_INTR(intr_status))
bna_mbox_handler(&bnad->bna, intr_status);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (!BNA_IS_INTX_DATA_INTR(intr_status))
return IRQ_HANDLED;
for (i = 0; i < bnad->num_tx; i++) {
for (j = 0; j < bnad->num_txq_per_tx; j++)
bnad_tx(bnad, bnad->tx_info[i].tcb[j]);
}
for (i = 0; i < bnad->num_rx; i++) {
rx_info = &bnad->rx_info[i];
if (!rx_info->rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
rx_ctrl = &rx_info->rx_ctrl[j];
if (rx_ctrl->ccb)
bnad_netif_rx_schedule_poll(bnad,
rx_ctrl->ccb);
}
}
return IRQ_HANDLED;
}
static void
bnad_enable_mbox_irq(struct bnad *bnad)
{
clear_bit(BNAD_RF_MBOX_IRQ_DISABLED, &bnad->run_flags);
BNAD_UPDATE_CTR(bnad, mbox_intr_enabled);
}
static void
bnad_disable_mbox_irq(struct bnad *bnad)
{
set_bit(BNAD_RF_MBOX_IRQ_DISABLED, &bnad->run_flags);
BNAD_UPDATE_CTR(bnad, mbox_intr_disabled);
}
static void
bnad_set_netdev_perm_addr(struct bnad *bnad)
{
struct net_device *netdev = bnad->netdev;
memcpy(netdev->perm_addr, &bnad->perm_addr, netdev->addr_len);
if (is_zero_ether_addr(netdev->dev_addr))
memcpy(netdev->dev_addr, &bnad->perm_addr, netdev->addr_len);
}
void
bnad_cb_device_enable_mbox_intr(struct bnad *bnad)
{
bnad_enable_mbox_irq(bnad);
}
void
bnad_cb_device_disable_mbox_intr(struct bnad *bnad)
{
bnad_disable_mbox_irq(bnad);
}
void
bnad_cb_device_enabled(struct bnad *bnad, enum bna_cb_status status)
{
complete(&bnad->bnad_completions.ioc_comp);
bnad->bnad_completions.ioc_comp_status = status;
}
void
bnad_cb_device_disabled(struct bnad *bnad, enum bna_cb_status status)
{
complete(&bnad->bnad_completions.ioc_comp);
bnad->bnad_completions.ioc_comp_status = status;
}
static void
bnad_cb_port_disabled(void *arg, enum bna_cb_status status)
{
struct bnad *bnad = (struct bnad *)arg;
complete(&bnad->bnad_completions.port_comp);
netif_carrier_off(bnad->netdev);
}
void
bnad_cb_port_link_status(struct bnad *bnad,
enum bna_link_status link_status)
{
bool link_up = 0;
link_up = (link_status == BNA_LINK_UP) || (link_status == BNA_CEE_UP);
if (link_status == BNA_CEE_UP) {
set_bit(BNAD_RF_CEE_RUNNING, &bnad->run_flags);
BNAD_UPDATE_CTR(bnad, cee_up);
} else
clear_bit(BNAD_RF_CEE_RUNNING, &bnad->run_flags);
if (link_up) {
if (!netif_carrier_ok(bnad->netdev)) {
struct bna_tcb *tcb = bnad->tx_info[0].tcb[0];
if (!tcb)
return;
pr_warn("bna: %s link up\n",
bnad->netdev->name);
netif_carrier_on(bnad->netdev);
BNAD_UPDATE_CTR(bnad, link_toggle);
if (test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags)) {
pr_info("bna: %s TX_STARTED\n",
bnad->netdev->name);
netif_wake_queue(bnad->netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_wakeup);
} else {
netif_stop_queue(bnad->netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_stop);
}
}
} else {
if (netif_carrier_ok(bnad->netdev)) {
pr_warn("bna: %s link down\n",
bnad->netdev->name);
netif_carrier_off(bnad->netdev);
BNAD_UPDATE_CTR(bnad, link_toggle);
}
}
}
static void
bnad_cb_tx_disabled(void *arg, struct bna_tx *tx,
enum bna_cb_status status)
{
struct bnad *bnad = (struct bnad *)arg;
complete(&bnad->bnad_completions.tx_comp);
}
static void
bnad_cb_tcb_setup(struct bnad *bnad, struct bna_tcb *tcb)
{
struct bnad_tx_info *tx_info =
(struct bnad_tx_info *)tcb->txq->tx->priv;
struct bnad_unmap_q *unmap_q = tcb->unmap_q;
tx_info->tcb[tcb->id] = tcb;
unmap_q->producer_index = 0;
unmap_q->consumer_index = 0;
unmap_q->q_depth = BNAD_TX_UNMAPQ_DEPTH;
}
static void
bnad_cb_tcb_destroy(struct bnad *bnad, struct bna_tcb *tcb)
{
struct bnad_tx_info *tx_info =
(struct bnad_tx_info *)tcb->txq->tx->priv;
struct bnad_unmap_q *unmap_q = tcb->unmap_q;
while (test_and_set_bit(BNAD_TXQ_FREE_SENT, &tcb->flags))
cpu_relax();
bnad_free_all_txbufs(bnad, tcb);
unmap_q->producer_index = 0;
unmap_q->consumer_index = 0;
smp_mb__before_clear_bit();
clear_bit(BNAD_TXQ_FREE_SENT, &tcb->flags);
tx_info->tcb[tcb->id] = NULL;
}
static void
bnad_cb_rcb_setup(struct bnad *bnad, struct bna_rcb *rcb)
{
struct bnad_unmap_q *unmap_q = rcb->unmap_q;
unmap_q->producer_index = 0;
unmap_q->consumer_index = 0;
unmap_q->q_depth = BNAD_RX_UNMAPQ_DEPTH;
}
static void
bnad_cb_rcb_destroy(struct bnad *bnad, struct bna_rcb *rcb)
{
bnad_free_all_rxbufs(bnad, rcb);
}
static void
bnad_cb_ccb_setup(struct bnad *bnad, struct bna_ccb *ccb)
{
struct bnad_rx_info *rx_info =
(struct bnad_rx_info *)ccb->cq->rx->priv;
rx_info->rx_ctrl[ccb->id].ccb = ccb;
ccb->ctrl = &rx_info->rx_ctrl[ccb->id];
}
static void
bnad_cb_ccb_destroy(struct bnad *bnad, struct bna_ccb *ccb)
{
struct bnad_rx_info *rx_info =
(struct bnad_rx_info *)ccb->cq->rx->priv;
rx_info->rx_ctrl[ccb->id].ccb = NULL;
}
static void
bnad_cb_tx_stall(struct bnad *bnad, struct bna_tcb *tcb)
{
struct bnad_tx_info *tx_info =
(struct bnad_tx_info *)tcb->txq->tx->priv;
if (tx_info != &bnad->tx_info[0])
return;
clear_bit(BNAD_TXQ_TX_STARTED, &tcb->flags);
netif_stop_queue(bnad->netdev);
pr_info("bna: %s TX_STOPPED\n", bnad->netdev->name);
}
static void
bnad_cb_tx_resume(struct bnad *bnad, struct bna_tcb *tcb)
{
struct bnad_unmap_q *unmap_q = tcb->unmap_q;
if (test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags))
return;
clear_bit(BNAD_RF_TX_SHUTDOWN_DELAYED, &bnad->run_flags);
while (test_and_set_bit(BNAD_TXQ_FREE_SENT, &tcb->flags))
cpu_relax();
bnad_free_all_txbufs(bnad, tcb);
unmap_q->producer_index = 0;
unmap_q->consumer_index = 0;
smp_mb__before_clear_bit();
clear_bit(BNAD_TXQ_FREE_SENT, &tcb->flags);
if (is_zero_ether_addr(&bnad->perm_addr.mac[0])) {
bna_port_mac_get(&bnad->bna.port, &bnad->perm_addr);
bnad_set_netdev_perm_addr(bnad);
}
set_bit(BNAD_TXQ_TX_STARTED, &tcb->flags);
if (netif_carrier_ok(bnad->netdev)) {
pr_info("bna: %s TX_STARTED\n", bnad->netdev->name);
netif_wake_queue(bnad->netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_wakeup);
}
}
static void
bnad_cb_tx_cleanup(struct bnad *bnad, struct bna_tcb *tcb)
{
if (!test_and_set_bit(BNAD_RF_TX_SHUTDOWN_DELAYED, &bnad->run_flags))
mdelay(BNAD_TXRX_SYNC_MDELAY);
}
static void
bnad_cb_rx_cleanup(struct bnad *bnad,
struct bna_ccb *ccb)
{
clear_bit(BNAD_RXQ_STARTED, &ccb->rcb[0]->flags);
if (ccb->rcb[1])
clear_bit(BNAD_RXQ_STARTED, &ccb->rcb[1]->flags);
if (!test_and_set_bit(BNAD_RF_RX_SHUTDOWN_DELAYED, &bnad->run_flags))
mdelay(BNAD_TXRX_SYNC_MDELAY);
}
static void
bnad_cb_rx_post(struct bnad *bnad, struct bna_rcb *rcb)
{
struct bnad_unmap_q *unmap_q = rcb->unmap_q;
clear_bit(BNAD_RF_RX_SHUTDOWN_DELAYED, &bnad->run_flags);
if (rcb == rcb->cq->ccb->rcb[0])
bnad_cq_cmpl_init(bnad, rcb->cq->ccb);
bnad_free_all_rxbufs(bnad, rcb);
set_bit(BNAD_RXQ_STARTED, &rcb->flags);
if (!test_and_set_bit(BNAD_RXQ_REFILL, &rcb->flags)) {
if (BNA_QE_FREE_CNT(unmap_q, unmap_q->q_depth)
>> BNAD_RXQ_REFILL_THRESHOLD_SHIFT)
bnad_alloc_n_post_rxbufs(bnad, rcb);
smp_mb__before_clear_bit();
clear_bit(BNAD_RXQ_REFILL, &rcb->flags);
}
}
static void
bnad_cb_rx_disabled(void *arg, struct bna_rx *rx,
enum bna_cb_status status)
{
struct bnad *bnad = (struct bnad *)arg;
complete(&bnad->bnad_completions.rx_comp);
}
static void
bnad_cb_rx_mcast_add(struct bnad *bnad, struct bna_rx *rx,
enum bna_cb_status status)
{
bnad->bnad_completions.mcast_comp_status = status;
complete(&bnad->bnad_completions.mcast_comp);
}
void
bnad_cb_stats_get(struct bnad *bnad, enum bna_cb_status status,
struct bna_stats *stats)
{
if (status == BNA_CB_SUCCESS)
BNAD_UPDATE_CTR(bnad, hw_stats_updates);
if (!netif_running(bnad->netdev) ||
!test_bit(BNAD_RF_STATS_TIMER_RUNNING, &bnad->run_flags))
return;
mod_timer(&bnad->stats_timer,
jiffies + msecs_to_jiffies(BNAD_STATS_TIMER_FREQ));
}
static void
bnad_mem_free(struct bnad *bnad,
struct bna_mem_info *mem_info)
{
int i;
dma_addr_t dma_pa;
if (mem_info->mdl == NULL)
return;
for (i = 0; i < mem_info->num; i++) {
if (mem_info->mdl[i].kva != NULL) {
if (mem_info->mem_type == BNA_MEM_T_DMA) {
BNA_GET_DMA_ADDR(&(mem_info->mdl[i].dma),
dma_pa);
dma_free_coherent(&bnad->pcidev->dev,
mem_info->mdl[i].len,
mem_info->mdl[i].kva, dma_pa);
} else
kfree(mem_info->mdl[i].kva);
}
}
kfree(mem_info->mdl);
mem_info->mdl = NULL;
}
static int
bnad_mem_alloc(struct bnad *bnad,
struct bna_mem_info *mem_info)
{
int i;
dma_addr_t dma_pa;
if ((mem_info->num == 0) || (mem_info->len == 0)) {
mem_info->mdl = NULL;
return 0;
}
mem_info->mdl = kcalloc(mem_info->num, sizeof(struct bna_mem_descr),
GFP_KERNEL);
if (mem_info->mdl == NULL)
return -ENOMEM;
if (mem_info->mem_type == BNA_MEM_T_DMA) {
for (i = 0; i < mem_info->num; i++) {
mem_info->mdl[i].len = mem_info->len;
mem_info->mdl[i].kva =
dma_alloc_coherent(&bnad->pcidev->dev,
mem_info->len, &dma_pa,
GFP_KERNEL);
if (mem_info->mdl[i].kva == NULL)
goto err_return;
BNA_SET_DMA_ADDR(dma_pa,
&(mem_info->mdl[i].dma));
}
} else {
for (i = 0; i < mem_info->num; i++) {
mem_info->mdl[i].len = mem_info->len;
mem_info->mdl[i].kva = kzalloc(mem_info->len,
GFP_KERNEL);
if (mem_info->mdl[i].kva == NULL)
goto err_return;
}
}
return 0;
err_return:
bnad_mem_free(bnad, mem_info);
return -ENOMEM;
}
static void
bnad_mbox_irq_free(struct bnad *bnad,
struct bna_intr_info *intr_info)
{
int irq;
unsigned long flags;
if (intr_info->idl == NULL)
return;
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_disable_mbox_irq(bnad);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
irq = BNAD_GET_MBOX_IRQ(bnad);
free_irq(irq, bnad);
kfree(intr_info->idl);
}
static int
bnad_mbox_irq_alloc(struct bnad *bnad,
struct bna_intr_info *intr_info)
{
int err = 0;
unsigned long irq_flags, flags;
u32 irq;
irq_handler_t irq_handler;
intr_info->idl = kzalloc(sizeof(*(intr_info->idl)), GFP_KERNEL);
if (!intr_info->idl)
return -ENOMEM;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (bnad->cfg_flags & BNAD_CF_MSIX) {
irq_handler = (irq_handler_t)bnad_msix_mbox_handler;
irq = bnad->msix_table[BNAD_MAILBOX_MSIX_INDEX].vector;
irq_flags = 0;
intr_info->intr_type = BNA_INTR_T_MSIX;
intr_info->idl[0].vector = BNAD_MAILBOX_MSIX_INDEX;
} else {
irq_handler = (irq_handler_t)bnad_isr;
irq = bnad->pcidev->irq;
irq_flags = IRQF_SHARED;
intr_info->intr_type = BNA_INTR_T_INTX;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
sprintf(bnad->mbox_irq_name, "%s", BNAD_NAME);
set_bit(BNAD_RF_MBOX_IRQ_DISABLED, &bnad->run_flags);
BNAD_UPDATE_CTR(bnad, mbox_intr_disabled);
err = request_irq(irq, irq_handler, irq_flags,
bnad->mbox_irq_name, bnad);
if (err) {
kfree(intr_info->idl);
intr_info->idl = NULL;
}
return err;
}
static void
bnad_txrx_irq_free(struct bnad *bnad, struct bna_intr_info *intr_info)
{
kfree(intr_info->idl);
intr_info->idl = NULL;
}
static int
bnad_txrx_irq_alloc(struct bnad *bnad, enum bnad_intr_source src,
uint txrx_id, struct bna_intr_info *intr_info)
{
int i, vector_start = 0;
u32 cfg_flags;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
cfg_flags = bnad->cfg_flags;
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (cfg_flags & BNAD_CF_MSIX) {
intr_info->intr_type = BNA_INTR_T_MSIX;
intr_info->idl = kcalloc(intr_info->num,
sizeof(struct bna_intr_descr),
GFP_KERNEL);
if (!intr_info->idl)
return -ENOMEM;
switch (src) {
case BNAD_INTR_TX:
vector_start = BNAD_MAILBOX_MSIX_VECTORS + txrx_id;
break;
case BNAD_INTR_RX:
vector_start = BNAD_MAILBOX_MSIX_VECTORS +
(bnad->num_tx * bnad->num_txq_per_tx) +
txrx_id;
break;
default:
BUG();
}
for (i = 0; i < intr_info->num; i++)
intr_info->idl[i].vector = vector_start + i;
} else {
intr_info->intr_type = BNA_INTR_T_INTX;
intr_info->num = 1;
intr_info->idl = kcalloc(intr_info->num,
sizeof(struct bna_intr_descr),
GFP_KERNEL);
if (!intr_info->idl)
return -ENOMEM;
switch (src) {
case BNAD_INTR_TX:
intr_info->idl[0].vector = BNAD_INTX_TX_IB_BITMASK;
break;
case BNAD_INTR_RX:
intr_info->idl[0].vector = BNAD_INTX_RX_IB_BITMASK;
break;
}
}
return 0;
}
static void
bnad_tx_msix_unregister(struct bnad *bnad, struct bnad_tx_info *tx_info,
int num_txqs)
{
int i;
int vector_num;
for (i = 0; i < num_txqs; i++) {
if (tx_info->tcb[i] == NULL)
continue;
vector_num = tx_info->tcb[i]->intr_vector;
free_irq(bnad->msix_table[vector_num].vector, tx_info->tcb[i]);
}
}
static int
bnad_tx_msix_register(struct bnad *bnad, struct bnad_tx_info *tx_info,
uint tx_id, int num_txqs)
{
int i;
int err;
int vector_num;
for (i = 0; i < num_txqs; i++) {
vector_num = tx_info->tcb[i]->intr_vector;
sprintf(tx_info->tcb[i]->name, "%s TXQ %d", bnad->netdev->name,
tx_id + tx_info->tcb[i]->id);
err = request_irq(bnad->msix_table[vector_num].vector,
(irq_handler_t)bnad_msix_tx, 0,
tx_info->tcb[i]->name,
tx_info->tcb[i]);
if (err)
goto err_return;
}
return 0;
err_return:
if (i > 0)
bnad_tx_msix_unregister(bnad, tx_info, (i - 1));
return -1;
}
static void
bnad_rx_msix_unregister(struct bnad *bnad, struct bnad_rx_info *rx_info,
int num_rxps)
{
int i;
int vector_num;
for (i = 0; i < num_rxps; i++) {
if (rx_info->rx_ctrl[i].ccb == NULL)
continue;
vector_num = rx_info->rx_ctrl[i].ccb->intr_vector;
free_irq(bnad->msix_table[vector_num].vector,
rx_info->rx_ctrl[i].ccb);
}
}
static int
bnad_rx_msix_register(struct bnad *bnad, struct bnad_rx_info *rx_info,
uint rx_id, int num_rxps)
{
int i;
int err;
int vector_num;
for (i = 0; i < num_rxps; i++) {
vector_num = rx_info->rx_ctrl[i].ccb->intr_vector;
sprintf(rx_info->rx_ctrl[i].ccb->name, "%s CQ %d",
bnad->netdev->name,
rx_id + rx_info->rx_ctrl[i].ccb->id);
err = request_irq(bnad->msix_table[vector_num].vector,
(irq_handler_t)bnad_msix_rx, 0,
rx_info->rx_ctrl[i].ccb->name,
rx_info->rx_ctrl[i].ccb);
if (err)
goto err_return;
}
return 0;
err_return:
if (i > 0)
bnad_rx_msix_unregister(bnad, rx_info, (i - 1));
return -1;
}
static void
bnad_tx_res_free(struct bnad *bnad, struct bna_res_info *res_info)
{
int i;
for (i = 0; i < BNA_TX_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
bnad_mem_free(bnad, &res_info[i].res_u.mem_info);
else if (res_info[i].res_type == BNA_RES_T_INTR)
bnad_txrx_irq_free(bnad, &res_info[i].res_u.intr_info);
}
}
static int
bnad_tx_res_alloc(struct bnad *bnad, struct bna_res_info *res_info,
uint tx_id)
{
int i, err = 0;
for (i = 0; i < BNA_TX_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
err = bnad_mem_alloc(bnad,
&res_info[i].res_u.mem_info);
else if (res_info[i].res_type == BNA_RES_T_INTR)
err = bnad_txrx_irq_alloc(bnad, BNAD_INTR_TX, tx_id,
&res_info[i].res_u.intr_info);
if (err)
goto err_return;
}
return 0;
err_return:
bnad_tx_res_free(bnad, res_info);
return err;
}
static void
bnad_rx_res_free(struct bnad *bnad, struct bna_res_info *res_info)
{
int i;
for (i = 0; i < BNA_RX_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
bnad_mem_free(bnad, &res_info[i].res_u.mem_info);
else if (res_info[i].res_type == BNA_RES_T_INTR)
bnad_txrx_irq_free(bnad, &res_info[i].res_u.intr_info);
}
}
static int
bnad_rx_res_alloc(struct bnad *bnad, struct bna_res_info *res_info,
uint rx_id)
{
int i, err = 0;
for (i = 0; i < BNA_RX_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
err = bnad_mem_alloc(bnad,
&res_info[i].res_u.mem_info);
else if (res_info[i].res_type == BNA_RES_T_INTR)
err = bnad_txrx_irq_alloc(bnad, BNAD_INTR_RX, rx_id,
&res_info[i].res_u.intr_info);
if (err)
goto err_return;
}
return 0;
err_return:
bnad_rx_res_free(bnad, res_info);
return err;
}
static void
bnad_ioc_timeout(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bfa_nw_ioc_timeout((void *) &bnad->bna.device.ioc);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_ioc_hb_check(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bfa_nw_ioc_hb_check((void *) &bnad->bna.device.ioc);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_iocpf_timeout(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bfa_nw_iocpf_timeout((void *) &bnad->bna.device.ioc);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_iocpf_sem_timeout(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bfa_nw_iocpf_sem_timeout((void *) &bnad->bna.device.ioc);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_dim_timeout(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
struct bnad_rx_info *rx_info;
struct bnad_rx_ctrl *rx_ctrl;
int i, j;
unsigned long flags;
if (!netif_carrier_ok(bnad->netdev))
return;
spin_lock_irqsave(&bnad->bna_lock, flags);
for (i = 0; i < bnad->num_rx; i++) {
rx_info = &bnad->rx_info[i];
if (!rx_info->rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
rx_ctrl = &rx_info->rx_ctrl[j];
if (!rx_ctrl->ccb)
continue;
bna_rx_dim_update(rx_ctrl->ccb);
}
}
if (test_bit(BNAD_RF_DIM_TIMER_RUNNING, &bnad->run_flags))
mod_timer(&bnad->dim_timer,
jiffies + msecs_to_jiffies(BNAD_DIM_TIMER_FREQ));
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_stats_timeout(unsigned long data)
{
struct bnad *bnad = (struct bnad *)data;
unsigned long flags;
if (!netif_running(bnad->netdev) ||
!test_bit(BNAD_RF_STATS_TIMER_RUNNING, &bnad->run_flags))
return;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_stats_get(&bnad->bna);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
void
bnad_dim_timer_start(struct bnad *bnad)
{
if (bnad->cfg_flags & BNAD_CF_DIM_ENABLED &&
!test_bit(BNAD_RF_DIM_TIMER_RUNNING, &bnad->run_flags)) {
setup_timer(&bnad->dim_timer, bnad_dim_timeout,
(unsigned long)bnad);
set_bit(BNAD_RF_DIM_TIMER_RUNNING, &bnad->run_flags);
mod_timer(&bnad->dim_timer,
jiffies + msecs_to_jiffies(BNAD_DIM_TIMER_FREQ));
}
}
static void
bnad_stats_timer_start(struct bnad *bnad)
{
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (!test_and_set_bit(BNAD_RF_STATS_TIMER_RUNNING, &bnad->run_flags)) {
setup_timer(&bnad->stats_timer, bnad_stats_timeout,
(unsigned long)bnad);
mod_timer(&bnad->stats_timer,
jiffies + msecs_to_jiffies(BNAD_STATS_TIMER_FREQ));
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_stats_timer_stop(struct bnad *bnad)
{
int to_del = 0;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (test_and_clear_bit(BNAD_RF_STATS_TIMER_RUNNING, &bnad->run_flags))
to_del = 1;
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (to_del)
del_timer_sync(&bnad->stats_timer);
}
static void
bnad_netdev_mc_list_get(struct net_device *netdev, u8 *mc_list)
{
int i = 1;
struct netdev_hw_addr *mc_addr;
netdev_for_each_mc_addr(mc_addr, netdev) {
memcpy(&mc_list[i * ETH_ALEN], &mc_addr->addr[0],
ETH_ALEN);
i++;
}
}
static int
bnad_napi_poll_rx(struct napi_struct *napi, int budget)
{
struct bnad_rx_ctrl *rx_ctrl =
container_of(napi, struct bnad_rx_ctrl, napi);
struct bna_ccb *ccb;
struct bnad *bnad;
int rcvd = 0;
ccb = rx_ctrl->ccb;
bnad = ccb->bnad;
if (!netif_carrier_ok(bnad->netdev))
goto poll_exit;
rcvd = bnad_poll_cq(bnad, ccb, budget);
if (rcvd == budget)
return rcvd;
poll_exit:
napi_complete((napi));
BNAD_UPDATE_CTR(bnad, netif_rx_complete);
bnad_enable_rx_irq(bnad, ccb);
return rcvd;
}
static void
bnad_napi_enable(struct bnad *bnad, u32 rx_id)
{
struct bnad_rx_ctrl *rx_ctrl;
int i;
for (i = 0; i < bnad->num_rxp_per_rx; i++) {
rx_ctrl = &bnad->rx_info[rx_id].rx_ctrl[i];
netif_napi_add(bnad->netdev, &rx_ctrl->napi,
bnad_napi_poll_rx, 64);
napi_enable(&rx_ctrl->napi);
}
}
static void
bnad_napi_disable(struct bnad *bnad, u32 rx_id)
{
int i;
for (i = 0; i < bnad->num_rxp_per_rx; i++) {
napi_disable(&bnad->rx_info[rx_id].rx_ctrl[i].napi);
netif_napi_del(&bnad->rx_info[rx_id].rx_ctrl[i].napi);
}
}
void
bnad_cleanup_tx(struct bnad *bnad, uint tx_id)
{
struct bnad_tx_info *tx_info = &bnad->tx_info[tx_id];
struct bna_res_info *res_info = &bnad->tx_res_info[tx_id].res_info[0];
unsigned long flags;
if (!tx_info->tx)
return;
init_completion(&bnad->bnad_completions.tx_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_tx_disable(tx_info->tx, BNA_HARD_CLEANUP, bnad_cb_tx_disabled);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&bnad->bnad_completions.tx_comp);
if (tx_info->tcb[0]->intr_type == BNA_INTR_T_MSIX)
bnad_tx_msix_unregister(bnad, tx_info,
bnad->num_txq_per_tx);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_tx_destroy(tx_info->tx);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
tx_info->tx = NULL;
if (0 == tx_id)
tasklet_kill(&bnad->tx_free_tasklet);
bnad_tx_res_free(bnad, res_info);
}
int
bnad_setup_tx(struct bnad *bnad, uint tx_id)
{
int err;
struct bnad_tx_info *tx_info = &bnad->tx_info[tx_id];
struct bna_res_info *res_info = &bnad->tx_res_info[tx_id].res_info[0];
struct bna_intr_info *intr_info =
&res_info[BNA_TX_RES_INTR_T_TXCMPL].res_u.intr_info;
struct bna_tx_config *tx_config = &bnad->tx_config[tx_id];
struct bna_tx_event_cbfn tx_cbfn;
struct bna_tx *tx;
unsigned long flags;
tx_config->num_txq = bnad->num_txq_per_tx;
tx_config->txq_depth = bnad->txq_depth;
tx_config->tx_type = BNA_TX_T_REGULAR;
tx_cbfn.tcb_setup_cbfn = bnad_cb_tcb_setup;
tx_cbfn.tcb_destroy_cbfn = bnad_cb_tcb_destroy;
tx_cbfn.tx_stall_cbfn = bnad_cb_tx_stall;
tx_cbfn.tx_resume_cbfn = bnad_cb_tx_resume;
tx_cbfn.tx_cleanup_cbfn = bnad_cb_tx_cleanup;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_tx_res_req(bnad->num_txq_per_tx,
bnad->txq_depth, res_info);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
BNAD_FILL_UNMAPQ_MEM_REQ(
&res_info[BNA_TX_RES_MEM_T_UNMAPQ],
bnad->num_txq_per_tx,
BNAD_TX_UNMAPQ_DEPTH);
err = bnad_tx_res_alloc(bnad, res_info, tx_id);
if (err)
return err;
spin_lock_irqsave(&bnad->bna_lock, flags);
tx = bna_tx_create(&bnad->bna, bnad, tx_config, &tx_cbfn, res_info,
tx_info);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (!tx)
goto err_return;
tx_info->tx = tx;
if (intr_info->intr_type == BNA_INTR_T_MSIX) {
err = bnad_tx_msix_register(bnad, tx_info,
tx_id, bnad->num_txq_per_tx);
if (err)
goto err_return;
}
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_tx_enable(tx);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return 0;
err_return:
bnad_tx_res_free(bnad, res_info);
return err;
}
static void
bnad_init_rx_config(struct bnad *bnad, struct bna_rx_config *rx_config)
{
rx_config->rx_type = BNA_RX_T_REGULAR;
rx_config->num_paths = bnad->num_rxp_per_rx;
if (bnad->num_rxp_per_rx > 1) {
rx_config->rss_status = BNA_STATUS_T_ENABLED;
rx_config->rss_config.hash_type =
(BFI_RSS_T_V4_TCP |
BFI_RSS_T_V6_TCP |
BFI_RSS_T_V4_IP |
BFI_RSS_T_V6_IP);
rx_config->rss_config.hash_mask =
bnad->num_rxp_per_rx - 1;
get_random_bytes(rx_config->rss_config.toeplitz_hash_key,
sizeof(rx_config->rss_config.toeplitz_hash_key));
} else {
rx_config->rss_status = BNA_STATUS_T_DISABLED;
memset(&rx_config->rss_config, 0,
sizeof(rx_config->rss_config));
}
rx_config->rxp_type = BNA_RXP_SLR;
rx_config->q_depth = bnad->rxq_depth;
rx_config->small_buff_size = BFI_SMALL_RXBUF_SIZE;
rx_config->vlan_strip_status = BNA_STATUS_T_ENABLED;
}
void
bnad_cleanup_rx(struct bnad *bnad, uint rx_id)
{
struct bnad_rx_info *rx_info = &bnad->rx_info[rx_id];
struct bna_rx_config *rx_config = &bnad->rx_config[rx_id];
struct bna_res_info *res_info = &bnad->rx_res_info[rx_id].res_info[0];
unsigned long flags;
int dim_timer_del = 0;
if (!rx_info->rx)
return;
if (0 == rx_id) {
spin_lock_irqsave(&bnad->bna_lock, flags);
dim_timer_del = bnad_dim_timer_running(bnad);
if (dim_timer_del)
clear_bit(BNAD_RF_DIM_TIMER_RUNNING, &bnad->run_flags);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (dim_timer_del)
del_timer_sync(&bnad->dim_timer);
}
bnad_napi_disable(bnad, rx_id);
init_completion(&bnad->bnad_completions.rx_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_rx_disable(rx_info->rx, BNA_HARD_CLEANUP, bnad_cb_rx_disabled);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&bnad->bnad_completions.rx_comp);
if (rx_info->rx_ctrl[0].ccb->intr_type == BNA_INTR_T_MSIX)
bnad_rx_msix_unregister(bnad, rx_info, rx_config->num_paths);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_rx_destroy(rx_info->rx);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
rx_info->rx = NULL;
bnad_rx_res_free(bnad, res_info);
}
int
bnad_setup_rx(struct bnad *bnad, uint rx_id)
{
int err;
struct bnad_rx_info *rx_info = &bnad->rx_info[rx_id];
struct bna_res_info *res_info = &bnad->rx_res_info[rx_id].res_info[0];
struct bna_intr_info *intr_info =
&res_info[BNA_RX_RES_T_INTR].res_u.intr_info;
struct bna_rx_config *rx_config = &bnad->rx_config[rx_id];
struct bna_rx_event_cbfn rx_cbfn;
struct bna_rx *rx;
unsigned long flags;
bnad_init_rx_config(bnad, rx_config);
rx_cbfn.rcb_setup_cbfn = bnad_cb_rcb_setup;
rx_cbfn.rcb_destroy_cbfn = bnad_cb_rcb_destroy;
rx_cbfn.ccb_setup_cbfn = bnad_cb_ccb_setup;
rx_cbfn.ccb_destroy_cbfn = bnad_cb_ccb_destroy;
rx_cbfn.rx_cleanup_cbfn = bnad_cb_rx_cleanup;
rx_cbfn.rx_post_cbfn = bnad_cb_rx_post;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_rx_res_req(rx_config, res_info);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
BNAD_FILL_UNMAPQ_MEM_REQ(
&res_info[BNA_RX_RES_MEM_T_UNMAPQ],
rx_config->num_paths +
((rx_config->rxp_type == BNA_RXP_SINGLE) ? 0 :
rx_config->num_paths), BNAD_RX_UNMAPQ_DEPTH);
err = bnad_rx_res_alloc(bnad, res_info, rx_id);
if (err)
return err;
spin_lock_irqsave(&bnad->bna_lock, flags);
rx = bna_rx_create(&bnad->bna, bnad, rx_config, &rx_cbfn, res_info,
rx_info);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (!rx)
goto err_return;
rx_info->rx = rx;
if (intr_info->intr_type == BNA_INTR_T_MSIX) {
err = bnad_rx_msix_register(bnad, rx_info, rx_id,
rx_config->num_paths);
if (err)
goto err_return;
}
bnad_napi_enable(bnad, rx_id);
spin_lock_irqsave(&bnad->bna_lock, flags);
if (0 == rx_id) {
if (bnad->cfg_flags & BNAD_CF_DIM_ENABLED)
bna_rx_dim_reconfig(&bnad->bna, bna_napi_dim_vector);
bna_rx_vlanfilter_enable(rx);
bnad_dim_timer_start(bnad);
}
bna_rx_enable(rx);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return 0;
err_return:
bnad_cleanup_rx(bnad, rx_id);
return err;
}
void
bnad_tx_coalescing_timeo_set(struct bnad *bnad)
{
struct bnad_tx_info *tx_info;
tx_info = &bnad->tx_info[0];
if (!tx_info->tx)
return;
bna_tx_coalescing_timeo_set(tx_info->tx, bnad->tx_coalescing_timeo);
}
void
bnad_rx_coalescing_timeo_set(struct bnad *bnad)
{
struct bnad_rx_info *rx_info;
int i;
for (i = 0; i < bnad->num_rx; i++) {
rx_info = &bnad->rx_info[i];
if (!rx_info->rx)
continue;
bna_rx_coalescing_timeo_set(rx_info->rx,
bnad->rx_coalescing_timeo);
}
}
static int
bnad_mac_addr_set_locked(struct bnad *bnad, u8 *mac_addr)
{
int ret;
if (!is_valid_ether_addr(mac_addr))
return -EADDRNOTAVAIL;
if (!bnad->rx_info[0].rx)
return 0;
ret = bna_rx_ucast_set(bnad->rx_info[0].rx, mac_addr, NULL);
if (ret != BNA_CB_SUCCESS)
return -EADDRNOTAVAIL;
return 0;
}
static int
bnad_enable_default_bcast(struct bnad *bnad)
{
struct bnad_rx_info *rx_info = &bnad->rx_info[0];
int ret;
unsigned long flags;
init_completion(&bnad->bnad_completions.mcast_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
ret = bna_rx_mcast_add(rx_info->rx, (u8 *)bnad_bcast_addr,
bnad_cb_rx_mcast_add);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (ret == BNA_CB_SUCCESS)
wait_for_completion(&bnad->bnad_completions.mcast_comp);
else
return -ENODEV;
if (bnad->bnad_completions.mcast_comp_status != BNA_CB_SUCCESS)
return -ENODEV;
return 0;
}
static void
bnad_restore_vlans(struct bnad *bnad, u32 rx_id)
{
u16 vid;
unsigned long flags;
BUG_ON(!(VLAN_N_VID == (BFI_MAX_VLAN + 1)));
for_each_set_bit(vid, bnad->active_vlans, VLAN_N_VID) {
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_rx_vlan_add(bnad->rx_info[rx_id].rx, vid);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
}
void
bnad_netdev_qstats_fill(struct bnad *bnad, struct rtnl_link_stats64 *stats)
{
int i, j;
for (i = 0; i < bnad->num_rx; i++) {
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
if (bnad->rx_info[i].rx_ctrl[j].ccb) {
stats->rx_packets += bnad->rx_info[i].
rx_ctrl[j].ccb->rcb[0]->rxq->rx_packets;
stats->rx_bytes += bnad->rx_info[i].
rx_ctrl[j].ccb->rcb[0]->rxq->rx_bytes;
if (bnad->rx_info[i].rx_ctrl[j].ccb->rcb[1] &&
bnad->rx_info[i].rx_ctrl[j].ccb->
rcb[1]->rxq) {
stats->rx_packets +=
bnad->rx_info[i].rx_ctrl[j].
ccb->rcb[1]->rxq->rx_packets;
stats->rx_bytes +=
bnad->rx_info[i].rx_ctrl[j].
ccb->rcb[1]->rxq->rx_bytes;
}
}
}
}
for (i = 0; i < bnad->num_tx; i++) {
for (j = 0; j < bnad->num_txq_per_tx; j++) {
if (bnad->tx_info[i].tcb[j]) {
stats->tx_packets +=
bnad->tx_info[i].tcb[j]->txq->tx_packets;
stats->tx_bytes +=
bnad->tx_info[i].tcb[j]->txq->tx_bytes;
}
}
}
}
void
bnad_netdev_hwstats_fill(struct bnad *bnad, struct rtnl_link_stats64 *stats)
{
struct bfi_ll_stats_mac *mac_stats;
u64 bmap;
int i;
mac_stats = &bnad->stats.bna_stats->hw_stats->mac_stats;
stats->rx_errors =
mac_stats->rx_fcs_error + mac_stats->rx_alignment_error +
mac_stats->rx_frame_length_error + mac_stats->rx_code_error +
mac_stats->rx_undersize;
stats->tx_errors = mac_stats->tx_fcs_error +
mac_stats->tx_undersize;
stats->rx_dropped = mac_stats->rx_drop;
stats->tx_dropped = mac_stats->tx_drop;
stats->multicast = mac_stats->rx_multicast;
stats->collisions = mac_stats->tx_total_collision;
stats->rx_length_errors = mac_stats->rx_frame_length_error;
stats->rx_crc_errors = mac_stats->rx_fcs_error;
stats->rx_frame_errors = mac_stats->rx_alignment_error;
bmap = (u64)bnad->stats.bna_stats->rxf_bmap[0] |
((u64)bnad->stats.bna_stats->rxf_bmap[1] << 32);
for (i = 0; bmap && (i < BFI_LL_RXF_ID_MAX); i++) {
if (bmap & 1) {
stats->rx_fifo_errors +=
bnad->stats.bna_stats->
hw_stats->rxf_stats[i].frame_drops;
break;
}
bmap >>= 1;
}
}
static void
bnad_mbox_irq_sync(struct bnad *bnad)
{
u32 irq;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (bnad->cfg_flags & BNAD_CF_MSIX)
irq = bnad->msix_table[BNAD_MAILBOX_MSIX_INDEX].vector;
else
irq = bnad->pcidev->irq;
spin_unlock_irqrestore(&bnad->bna_lock, flags);
synchronize_irq(irq);
}
static int
bnad_tso_prepare(struct bnad *bnad, struct sk_buff *skb)
{
int err;
BUG_ON(!(skb_shinfo(skb)->gso_type == SKB_GSO_TCPV4 ||
skb_shinfo(skb)->gso_type == SKB_GSO_TCPV6));
if (skb_header_cloned(skb)) {
err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (err) {
BNAD_UPDATE_CTR(bnad, tso_err);
return err;
}
}
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check =
~csum_tcpudp_magic(iph->saddr, iph->daddr, 0,
IPPROTO_TCP, 0);
BNAD_UPDATE_CTR(bnad, tso4);
} else {
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
BUG_ON(!(skb->protocol == htons(ETH_P_IPV6)));
ipv6h->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6h->saddr, &ipv6h->daddr, 0,
IPPROTO_TCP, 0);
BNAD_UPDATE_CTR(bnad, tso6);
}
return 0;
}
static void
bnad_q_num_init(struct bnad *bnad)
{
int rxps;
rxps = min((uint)num_online_cpus(),
(uint)(BNAD_MAX_RXS * BNAD_MAX_RXPS_PER_RX));
if (!(bnad->cfg_flags & BNAD_CF_MSIX))
rxps = 1;
bnad->num_rx = 1;
bnad->num_tx = 1;
bnad->num_rxp_per_rx = rxps;
bnad->num_txq_per_tx = BNAD_TXQ_NUM;
}
static void
bnad_q_num_adjust(struct bnad *bnad, int msix_vectors)
{
bnad->num_txq_per_tx = 1;
if ((msix_vectors >= (bnad->num_tx * bnad->num_txq_per_tx) +
bnad_rxqs_per_cq + BNAD_MAILBOX_MSIX_VECTORS) &&
(bnad->cfg_flags & BNAD_CF_MSIX)) {
bnad->num_rxp_per_rx = msix_vectors -
(bnad->num_tx * bnad->num_txq_per_tx) -
BNAD_MAILBOX_MSIX_VECTORS;
} else
bnad->num_rxp_per_rx = 1;
}
static void
bnad_device_disable(struct bnad *bnad)
{
unsigned long flags;
init_completion(&bnad->bnad_completions.ioc_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_device_disable(&bnad->bna.device, BNA_HARD_CLEANUP);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&bnad->bnad_completions.ioc_comp);
}
static int
bnad_device_enable(struct bnad *bnad)
{
int err = 0;
unsigned long flags;
init_completion(&bnad->bnad_completions.ioc_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_device_enable(&bnad->bna.device);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&bnad->bnad_completions.ioc_comp);
if (bnad->bnad_completions.ioc_comp_status)
err = bnad->bnad_completions.ioc_comp_status;
return err;
}
static void
bnad_res_free(struct bnad *bnad)
{
int i;
struct bna_res_info *res_info = &bnad->res_info[0];
for (i = 0; i < BNA_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
bnad_mem_free(bnad, &res_info[i].res_u.mem_info);
else
bnad_mbox_irq_free(bnad, &res_info[i].res_u.intr_info);
}
}
static int
bnad_res_alloc(struct bnad *bnad)
{
int i, err;
struct bna_res_info *res_info = &bnad->res_info[0];
for (i = 0; i < BNA_RES_T_MAX; i++) {
if (res_info[i].res_type == BNA_RES_T_MEM)
err = bnad_mem_alloc(bnad, &res_info[i].res_u.mem_info);
else
err = bnad_mbox_irq_alloc(bnad,
&res_info[i].res_u.intr_info);
if (err)
goto err_return;
}
return 0;
err_return:
bnad_res_free(bnad);
return err;
}
static void
bnad_enable_msix(struct bnad *bnad)
{
int i, ret;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
if (!(bnad->cfg_flags & BNAD_CF_MSIX)) {
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (bnad->msix_table)
return;
bnad->msix_table =
kcalloc(bnad->msix_num, sizeof(struct msix_entry), GFP_KERNEL);
if (!bnad->msix_table)
goto intx_mode;
for (i = 0; i < bnad->msix_num; i++)
bnad->msix_table[i].entry = i;
ret = pci_enable_msix(bnad->pcidev, bnad->msix_table, bnad->msix_num);
if (ret > 0) {
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_q_num_adjust(bnad, ret);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad->msix_num = (bnad->num_tx * bnad->num_txq_per_tx)
+ (bnad->num_rx
* bnad->num_rxp_per_rx) +
BNAD_MAILBOX_MSIX_VECTORS;
ret = pci_enable_msix(bnad->pcidev, bnad->msix_table,
bnad->msix_num);
if (ret)
goto intx_mode;
} else if (ret < 0)
goto intx_mode;
return;
intx_mode:
kfree(bnad->msix_table);
bnad->msix_table = NULL;
bnad->msix_num = 0;
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad->cfg_flags &= ~BNAD_CF_MSIX;
bnad_q_num_init(bnad);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static void
bnad_disable_msix(struct bnad *bnad)
{
u32 cfg_flags;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
cfg_flags = bnad->cfg_flags;
if (bnad->cfg_flags & BNAD_CF_MSIX)
bnad->cfg_flags &= ~BNAD_CF_MSIX;
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (cfg_flags & BNAD_CF_MSIX) {
pci_disable_msix(bnad->pcidev);
kfree(bnad->msix_table);
bnad->msix_table = NULL;
}
}
static int
bnad_open(struct net_device *netdev)
{
int err;
struct bnad *bnad = netdev_priv(netdev);
struct bna_pause_config pause_config;
int mtu;
unsigned long flags;
mutex_lock(&bnad->conf_mutex);
err = bnad_setup_tx(bnad, 0);
if (err)
goto err_return;
err = bnad_setup_rx(bnad, 0);
if (err)
goto cleanup_tx;
pause_config.tx_pause = 0;
pause_config.rx_pause = 0;
mtu = ETH_HLEN + bnad->netdev->mtu + ETH_FCS_LEN;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_port_mtu_set(&bnad->bna.port, mtu, NULL);
bna_port_pause_config(&bnad->bna.port, &pause_config, NULL);
bna_port_enable(&bnad->bna.port);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad_enable_default_bcast(bnad);
bnad_restore_vlans(bnad, 0);
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_mac_addr_set_locked(bnad, netdev->dev_addr);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad_stats_timer_start(bnad);
mutex_unlock(&bnad->conf_mutex);
return 0;
cleanup_tx:
bnad_cleanup_tx(bnad, 0);
err_return:
mutex_unlock(&bnad->conf_mutex);
return err;
}
static int
bnad_stop(struct net_device *netdev)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
mutex_lock(&bnad->conf_mutex);
bnad_stats_timer_stop(bnad);
init_completion(&bnad->bnad_completions.port_comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_port_disable(&bnad->bna.port, BNA_HARD_CLEANUP,
bnad_cb_port_disabled);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&bnad->bnad_completions.port_comp);
bnad_cleanup_tx(bnad, 0);
bnad_cleanup_rx(bnad, 0);
bnad_mbox_irq_sync(bnad);
mutex_unlock(&bnad->conf_mutex);
return 0;
}
static netdev_tx_t
bnad_start_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct bnad *bnad = netdev_priv(netdev);
u16 txq_prod, vlan_tag = 0;
u32 unmap_prod, wis, wis_used, wi_range;
u32 vectors, vect_id, i, acked;
u32 tx_id;
int err;
struct bnad_tx_info *tx_info;
struct bna_tcb *tcb;
struct bnad_unmap_q *unmap_q;
dma_addr_t dma_addr;
struct bna_txq_entry *txqent;
bna_txq_wi_ctrl_flag_t flags;
if (unlikely
(skb->len <= ETH_HLEN || skb->len > BFI_TX_MAX_DATA_PER_PKT)) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
tx_id = 0;
tx_info = &bnad->tx_info[tx_id];
tcb = tx_info->tcb[tx_id];
unmap_q = tcb->unmap_q;
if (unlikely(!test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags))) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
vectors = 1 + skb_shinfo(skb)->nr_frags;
if (vectors > BFI_TX_MAX_VECTORS_PER_PKT) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
wis = BNA_TXQ_WI_NEEDED(vectors);
acked = 0;
if (unlikely
(wis > BNA_QE_FREE_CNT(tcb, tcb->q_depth) ||
vectors > BNA_QE_FREE_CNT(unmap_q, unmap_q->q_depth))) {
if ((u16) (*tcb->hw_consumer_index) !=
tcb->consumer_index &&
!test_and_set_bit(BNAD_TXQ_FREE_SENT, &tcb->flags)) {
acked = bnad_free_txbufs(bnad, tcb);
if (likely(test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags)))
bna_ib_ack(tcb->i_dbell, acked);
smp_mb__before_clear_bit();
clear_bit(BNAD_TXQ_FREE_SENT, &tcb->flags);
} else {
netif_stop_queue(netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_stop);
}
smp_mb();
if (likely
(wis > BNA_QE_FREE_CNT(tcb, tcb->q_depth) ||
vectors > BNA_QE_FREE_CNT(unmap_q, unmap_q->q_depth))) {
BNAD_UPDATE_CTR(bnad, netif_queue_stop);
return NETDEV_TX_BUSY;
} else {
netif_wake_queue(netdev);
BNAD_UPDATE_CTR(bnad, netif_queue_wakeup);
}
}
unmap_prod = unmap_q->producer_index;
wis_used = 1;
vect_id = 0;
flags = 0;
txq_prod = tcb->producer_index;
BNA_TXQ_QPGE_PTR_GET(txq_prod, tcb->sw_qpt, txqent, wi_range);
BUG_ON(!(wi_range <= tcb->q_depth));
txqent->hdr.wi.reserved = 0;
txqent->hdr.wi.num_vectors = vectors;
txqent->hdr.wi.opcode =
htons((skb_is_gso(skb) ? BNA_TXQ_WI_SEND_LSO :
BNA_TXQ_WI_SEND));
if (vlan_tx_tag_present(skb)) {
vlan_tag = (u16) vlan_tx_tag_get(skb);
flags |= (BNA_TXQ_WI_CF_INS_PRIO | BNA_TXQ_WI_CF_INS_VLAN);
}
if (test_bit(BNAD_RF_CEE_RUNNING, &bnad->run_flags)) {
vlan_tag =
(tcb->priority & 0x7) << 13 | (vlan_tag & 0x1fff);
flags |= (BNA_TXQ_WI_CF_INS_PRIO | BNA_TXQ_WI_CF_INS_VLAN);
}
txqent->hdr.wi.vlan_tag = htons(vlan_tag);
if (skb_is_gso(skb)) {
err = bnad_tso_prepare(bnad, skb);
if (err) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
txqent->hdr.wi.lso_mss = htons(skb_is_gso(skb));
flags |= (BNA_TXQ_WI_CF_IP_CKSUM | BNA_TXQ_WI_CF_TCP_CKSUM);
txqent->hdr.wi.l4_hdr_size_n_offset =
htons(BNA_TXQ_WI_L4_HDR_N_OFFSET
(tcp_hdrlen(skb) >> 2,
skb_transport_offset(skb)));
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
u8 proto = 0;
txqent->hdr.wi.lso_mss = 0;
if (skb->protocol == htons(ETH_P_IP))
proto = ip_hdr(skb)->protocol;
else if (skb->protocol == htons(ETH_P_IPV6)) {
proto = ipv6_hdr(skb)->nexthdr;
}
if (proto == IPPROTO_TCP) {
flags |= BNA_TXQ_WI_CF_TCP_CKSUM;
txqent->hdr.wi.l4_hdr_size_n_offset =
htons(BNA_TXQ_WI_L4_HDR_N_OFFSET
(0, skb_transport_offset(skb)));
BNAD_UPDATE_CTR(bnad, tcpcsum_offload);
BUG_ON(!(skb_headlen(skb) >=
skb_transport_offset(skb) + tcp_hdrlen(skb)));
} else if (proto == IPPROTO_UDP) {
flags |= BNA_TXQ_WI_CF_UDP_CKSUM;
txqent->hdr.wi.l4_hdr_size_n_offset =
htons(BNA_TXQ_WI_L4_HDR_N_OFFSET
(0, skb_transport_offset(skb)));
BNAD_UPDATE_CTR(bnad, udpcsum_offload);
BUG_ON(!(skb_headlen(skb) >=
skb_transport_offset(skb) +
sizeof(struct udphdr)));
} else {
err = skb_checksum_help(skb);
BNAD_UPDATE_CTR(bnad, csum_help);
if (err) {
dev_kfree_skb(skb);
BNAD_UPDATE_CTR(bnad, csum_help_err);
return NETDEV_TX_OK;
}
}
} else {
txqent->hdr.wi.lso_mss = 0;
txqent->hdr.wi.l4_hdr_size_n_offset = 0;
}
txqent->hdr.wi.flags = htons(flags);
txqent->hdr.wi.frame_length = htonl(skb->len);
unmap_q->unmap_array[unmap_prod].skb = skb;
BUG_ON(!(skb_headlen(skb) <= BFI_TX_MAX_DATA_PER_VECTOR));
txqent->vector[vect_id].length = htons(skb_headlen(skb));
dma_addr = dma_map_single(&bnad->pcidev->dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_q->unmap_array[unmap_prod], dma_addr,
dma_addr);
BNA_SET_DMA_ADDR(dma_addr, &txqent->vector[vect_id].host_addr);
BNA_QE_INDX_ADD(unmap_prod, 1, unmap_q->q_depth);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[i];
u32 size = frag->size;
if (++vect_id == BFI_TX_MAX_VECTORS_PER_WI) {
vect_id = 0;
if (--wi_range)
txqent++;
else {
BNA_QE_INDX_ADD(txq_prod, wis_used,
tcb->q_depth);
wis_used = 0;
BNA_TXQ_QPGE_PTR_GET(txq_prod, tcb->sw_qpt,
txqent, wi_range);
BUG_ON(!(wi_range <= tcb->q_depth));
}
wis_used++;
txqent->hdr.wi_ext.opcode = htons(BNA_TXQ_WI_EXTENSION);
}
BUG_ON(!(size <= BFI_TX_MAX_DATA_PER_VECTOR));
txqent->vector[vect_id].length = htons(size);
dma_addr = dma_map_page(&bnad->pcidev->dev, frag->page,
frag->page_offset, size, DMA_TO_DEVICE);
dma_unmap_addr_set(&unmap_q->unmap_array[unmap_prod], dma_addr,
dma_addr);
BNA_SET_DMA_ADDR(dma_addr, &txqent->vector[vect_id].host_addr);
BNA_QE_INDX_ADD(unmap_prod, 1, unmap_q->q_depth);
}
unmap_q->producer_index = unmap_prod;
BNA_QE_INDX_ADD(txq_prod, wis_used, tcb->q_depth);
tcb->producer_index = txq_prod;
smp_mb();
if (unlikely(!test_bit(BNAD_TXQ_TX_STARTED, &tcb->flags)))
return NETDEV_TX_OK;
bna_txq_prod_indx_doorbell(tcb);
if ((u16) (*tcb->hw_consumer_index) != tcb->consumer_index)
tasklet_schedule(&bnad->tx_free_tasklet);
return NETDEV_TX_OK;
}
static struct rtnl_link_stats64 *
bnad_get_stats64(struct net_device *netdev, struct rtnl_link_stats64 *stats)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_netdev_qstats_fill(bnad, stats);
bnad_netdev_hwstats_fill(bnad, stats);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return stats;
}
static void
bnad_set_rx_mode(struct net_device *netdev)
{
struct bnad *bnad = netdev_priv(netdev);
u32 new_mask, valid_mask;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
new_mask = valid_mask = 0;
if (netdev->flags & IFF_PROMISC) {
if (!(bnad->cfg_flags & BNAD_CF_PROMISC)) {
new_mask = BNAD_RXMODE_PROMISC_DEFAULT;
valid_mask = BNAD_RXMODE_PROMISC_DEFAULT;
bnad->cfg_flags |= BNAD_CF_PROMISC;
}
} else {
if (bnad->cfg_flags & BNAD_CF_PROMISC) {
new_mask = ~BNAD_RXMODE_PROMISC_DEFAULT;
valid_mask = BNAD_RXMODE_PROMISC_DEFAULT;
bnad->cfg_flags &= ~BNAD_CF_PROMISC;
}
}
if (netdev->flags & IFF_ALLMULTI) {
if (!(bnad->cfg_flags & BNAD_CF_ALLMULTI)) {
new_mask |= BNA_RXMODE_ALLMULTI;
valid_mask |= BNA_RXMODE_ALLMULTI;
bnad->cfg_flags |= BNAD_CF_ALLMULTI;
}
} else {
if (bnad->cfg_flags & BNAD_CF_ALLMULTI) {
new_mask &= ~BNA_RXMODE_ALLMULTI;
valid_mask |= BNA_RXMODE_ALLMULTI;
bnad->cfg_flags &= ~BNAD_CF_ALLMULTI;
}
}
bna_rx_mode_set(bnad->rx_info[0].rx, new_mask, valid_mask, NULL);
if (!netdev_mc_empty(netdev)) {
u8 *mcaddr_list;
int mc_count = netdev_mc_count(netdev);
mcaddr_list =
kzalloc((mc_count + 1) * ETH_ALEN,
GFP_ATOMIC);
if (!mcaddr_list)
goto unlock;
memcpy(&mcaddr_list[0], &bnad_bcast_addr[0], ETH_ALEN);
bnad_netdev_mc_list_get(netdev, mcaddr_list);
bna_rx_mcast_listset(bnad->rx_info[0].rx, mc_count + 1,
mcaddr_list, NULL);
kfree(mcaddr_list);
}
unlock:
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
static int
bnad_set_mac_address(struct net_device *netdev, void *mac_addr)
{
int err;
struct bnad *bnad = netdev_priv(netdev);
struct sockaddr *sa = (struct sockaddr *)mac_addr;
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
err = bnad_mac_addr_set_locked(bnad, sa->sa_data);
if (!err)
memcpy(netdev->dev_addr, sa->sa_data, netdev->addr_len);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
return err;
}
static int
bnad_change_mtu(struct net_device *netdev, int new_mtu)
{
int mtu, err = 0;
unsigned long flags;
struct bnad *bnad = netdev_priv(netdev);
if (new_mtu + ETH_HLEN < ETH_ZLEN || new_mtu > BNAD_JUMBO_MTU)
return -EINVAL;
mutex_lock(&bnad->conf_mutex);
netdev->mtu = new_mtu;
mtu = ETH_HLEN + new_mtu + ETH_FCS_LEN;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_port_mtu_set(&bnad->bna.port, mtu, NULL);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
return err;
}
static void
bnad_vlan_rx_add_vid(struct net_device *netdev,
unsigned short vid)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
if (!bnad->rx_info[0].rx)
return;
mutex_lock(&bnad->conf_mutex);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_rx_vlan_add(bnad->rx_info[0].rx, vid);
set_bit(vid, bnad->active_vlans);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
}
static void
bnad_vlan_rx_kill_vid(struct net_device *netdev,
unsigned short vid)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
if (!bnad->rx_info[0].rx)
return;
mutex_lock(&bnad->conf_mutex);
spin_lock_irqsave(&bnad->bna_lock, flags);
clear_bit(vid, bnad->active_vlans);
bna_rx_vlan_del(bnad->rx_info[0].rx, vid);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
}
static void
bnad_netpoll(struct net_device *netdev)
{
struct bnad *bnad = netdev_priv(netdev);
struct bnad_rx_info *rx_info;
struct bnad_rx_ctrl *rx_ctrl;
u32 curr_mask;
int i, j;
if (!(bnad->cfg_flags & BNAD_CF_MSIX)) {
bna_intx_disable(&bnad->bna, curr_mask);
bnad_isr(bnad->pcidev->irq, netdev);
bna_intx_enable(&bnad->bna, curr_mask);
} else {
for (i = 0; i < bnad->num_rx; i++) {
rx_info = &bnad->rx_info[i];
if (!rx_info->rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
rx_ctrl = &rx_info->rx_ctrl[j];
if (rx_ctrl->ccb) {
bnad_disable_rx_irq(bnad,
rx_ctrl->ccb);
bnad_netif_rx_schedule_poll(bnad,
rx_ctrl->ccb);
}
}
}
}
}
static void
bnad_netdev_init(struct bnad *bnad, bool using_dac)
{
struct net_device *netdev = bnad->netdev;
netdev->hw_features = NETIF_F_SG | NETIF_F_RXCSUM |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_TSO | NETIF_F_TSO6 | NETIF_F_HW_VLAN_TX;
netdev->vlan_features = NETIF_F_SG | NETIF_F_HIGHDMA |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_TSO | NETIF_F_TSO6;
netdev->features |= netdev->hw_features |
NETIF_F_HW_VLAN_RX | NETIF_F_HW_VLAN_FILTER;
if (using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->mem_start = bnad->mmio_start;
netdev->mem_end = bnad->mmio_start + bnad->mmio_len - 1;
netdev->netdev_ops = &bnad_netdev_ops;
bnad_set_ethtool_ops(netdev);
}
static int
bnad_init(struct bnad *bnad,
struct pci_dev *pdev, struct net_device *netdev)
{
unsigned long flags;
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
bnad->netdev = netdev;
bnad->pcidev = pdev;
bnad->mmio_start = pci_resource_start(pdev, 0);
bnad->mmio_len = pci_resource_len(pdev, 0);
bnad->bar0 = ioremap_nocache(bnad->mmio_start, bnad->mmio_len);
if (!bnad->bar0) {
dev_err(&pdev->dev, "ioremap for bar0 failed\n");
pci_set_drvdata(pdev, NULL);
return -ENOMEM;
}
pr_info("bar0 mapped to %p, len %llu\n", bnad->bar0,
(unsigned long long) bnad->mmio_len);
spin_lock_irqsave(&bnad->bna_lock, flags);
if (!bnad_msix_disable)
bnad->cfg_flags = BNAD_CF_MSIX;
bnad->cfg_flags |= BNAD_CF_DIM_ENABLED;
bnad_q_num_init(bnad);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad->msix_num = (bnad->num_tx * bnad->num_txq_per_tx) +
(bnad->num_rx * bnad->num_rxp_per_rx) +
BNAD_MAILBOX_MSIX_VECTORS;
bnad->txq_depth = BNAD_TXQ_DEPTH;
bnad->rxq_depth = BNAD_RXQ_DEPTH;
bnad->tx_coalescing_timeo = BFI_TX_COALESCING_TIMEO;
bnad->rx_coalescing_timeo = BFI_RX_COALESCING_TIMEO;
tasklet_init(&bnad->tx_free_tasklet, bnad_tx_free_tasklet,
(unsigned long)bnad);
return 0;
}
static void
bnad_uninit(struct bnad *bnad)
{
if (bnad->bar0)
iounmap(bnad->bar0);
pci_set_drvdata(bnad->pcidev, NULL);
}
static void
bnad_lock_init(struct bnad *bnad)
{
spin_lock_init(&bnad->bna_lock);
mutex_init(&bnad->conf_mutex);
}
static void
bnad_lock_uninit(struct bnad *bnad)
{
mutex_destroy(&bnad->conf_mutex);
}
static int
bnad_pci_init(struct bnad *bnad,
struct pci_dev *pdev, bool *using_dac)
{
int err;
err = pci_enable_device(pdev);
if (err)
return err;
err = pci_request_regions(pdev, BNAD_NAME);
if (err)
goto disable_device;
if (!dma_set_mask(&pdev->dev, DMA_BIT_MASK(64)) &&
!dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64))) {
*using_dac = 1;
} else {
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
err = dma_set_coherent_mask(&pdev->dev,
DMA_BIT_MASK(32));
if (err)
goto release_regions;
}
*using_dac = 0;
}
pci_set_master(pdev);
return 0;
release_regions:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
return err;
}
static void
bnad_pci_uninit(struct pci_dev *pdev)
{
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __devinit
bnad_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *pcidev_id)
{
bool using_dac = false;
int err;
struct bnad *bnad;
struct bna *bna;
struct net_device *netdev;
struct bfa_pcidev pcidev_info;
unsigned long flags;
pr_info("bnad_pci_probe : (0x%p, 0x%p) PCI Func : (%d)\n",
pdev, pcidev_id, PCI_FUNC(pdev->devfn));
mutex_lock(&bnad_fwimg_mutex);
if (!cna_get_firmware_buf(pdev)) {
mutex_unlock(&bnad_fwimg_mutex);
pr_warn("Failed to load Firmware Image!\n");
return -ENODEV;
}
mutex_unlock(&bnad_fwimg_mutex);
netdev = alloc_etherdev(sizeof(struct bnad));
if (!netdev) {
dev_err(&pdev->dev, "alloc_etherdev failed\n");
err = -ENOMEM;
return err;
}
bnad = netdev_priv(netdev);
err = bnad_pci_init(bnad, pdev, &using_dac);
if (err)
goto free_netdev;
bnad_lock_init(bnad);
err = bnad_init(bnad, pdev, netdev);
if (err)
goto pci_uninit;
bnad_netdev_init(bnad, using_dac);
netif_carrier_off(netdev);
bnad_enable_msix(bnad);
bna_res_req(&bnad->res_info[0]);
err = bnad_res_alloc(bnad);
if (err)
goto free_netdev;
bna = &bnad->bna;
pcidev_info.pci_slot = PCI_SLOT(bnad->pcidev->devfn);
pcidev_info.pci_func = PCI_FUNC(bnad->pcidev->devfn);
pcidev_info.device_id = bnad->pcidev->device;
pcidev_info.pci_bar_kva = bnad->bar0;
mutex_lock(&bnad->conf_mutex);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_init(bna, bnad, &pcidev_info, &bnad->res_info[0]);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad->stats.bna_stats = &bna->stats;
setup_timer(&bnad->bna.device.ioc.ioc_timer, bnad_ioc_timeout,
((unsigned long)bnad));
setup_timer(&bnad->bna.device.ioc.hb_timer, bnad_ioc_hb_check,
((unsigned long)bnad));
setup_timer(&bnad->bna.device.ioc.iocpf_timer, bnad_iocpf_timeout,
((unsigned long)bnad));
setup_timer(&bnad->bna.device.ioc.sem_timer, bnad_iocpf_sem_timeout,
((unsigned long)bnad));
mod_timer(&bnad->bna.device.ioc.iocpf_timer,
jiffies + msecs_to_jiffies(BNA_IOC_TIMER_FREQ));
err = bnad_device_enable(bnad);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_port_mac_get(&bna->port, &bnad->perm_addr);
bnad_set_netdev_perm_addr(bnad);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
err = register_netdev(netdev);
if (err) {
pr_err("BNA : Registering with netdev failed\n");
goto disable_device;
}
return 0;
disable_device:
mutex_lock(&bnad->conf_mutex);
bnad_device_disable(bnad);
del_timer_sync(&bnad->bna.device.ioc.ioc_timer);
del_timer_sync(&bnad->bna.device.ioc.sem_timer);
del_timer_sync(&bnad->bna.device.ioc.hb_timer);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_uninit(bna);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
bnad_res_free(bnad);
bnad_disable_msix(bnad);
pci_uninit:
bnad_pci_uninit(pdev);
bnad_lock_uninit(bnad);
bnad_uninit(bnad);
free_netdev:
free_netdev(netdev);
return err;
}
static void __devexit
bnad_pci_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct bnad *bnad;
struct bna *bna;
unsigned long flags;
if (!netdev)
return;
pr_info("%s bnad_pci_remove\n", netdev->name);
bnad = netdev_priv(netdev);
bna = &bnad->bna;
unregister_netdev(netdev);
mutex_lock(&bnad->conf_mutex);
bnad_device_disable(bnad);
del_timer_sync(&bnad->bna.device.ioc.ioc_timer);
del_timer_sync(&bnad->bna.device.ioc.sem_timer);
del_timer_sync(&bnad->bna.device.ioc.hb_timer);
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_uninit(bna);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
bnad_res_free(bnad);
bnad_disable_msix(bnad);
bnad_pci_uninit(pdev);
bnad_lock_uninit(bnad);
bnad_uninit(bnad);
free_netdev(netdev);
}
static int __init
bnad_module_init(void)
{
int err;
pr_info("Brocade 10G Ethernet driver - version: %s\n",
BNAD_VERSION);
bfa_nw_ioc_auto_recover(bnad_ioc_auto_recover);
err = pci_register_driver(&bnad_pci_driver);
if (err < 0) {
pr_err("bna : PCI registration failed in module init "
"(%d)\n", err);
return err;
}
return 0;
}
static void __exit
bnad_module_exit(void)
{
pci_unregister_driver(&bnad_pci_driver);
if (bfi_fw)
release_firmware(bfi_fw);
}
