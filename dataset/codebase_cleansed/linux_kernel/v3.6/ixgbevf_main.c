static inline void ixgbevf_release_rx_desc(struct ixgbe_hw *hw,
struct ixgbevf_ring *rx_ring,
u32 val)
{
wmb();
IXGBE_WRITE_REG(hw, IXGBE_VFRDT(rx_ring->reg_idx), val);
}
static void ixgbevf_set_ivar(struct ixgbevf_adapter *adapter, s8 direction,
u8 queue, u8 msix_vector)
{
u32 ivar, index;
struct ixgbe_hw *hw = &adapter->hw;
if (direction == -1) {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
ivar = IXGBE_READ_REG(hw, IXGBE_VTIVAR_MISC);
ivar &= ~0xFF;
ivar |= msix_vector;
IXGBE_WRITE_REG(hw, IXGBE_VTIVAR_MISC, ivar);
} else {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
index = ((16 * (queue & 1)) + (8 * direction));
ivar = IXGBE_READ_REG(hw, IXGBE_VTIVAR(queue >> 1));
ivar &= ~(0xFF << index);
ivar |= (msix_vector << index);
IXGBE_WRITE_REG(hw, IXGBE_VTIVAR(queue >> 1), ivar);
}
}
static void ixgbevf_unmap_and_free_tx_resource(struct ixgbevf_ring *tx_ring,
struct ixgbevf_tx_buffer
*tx_buffer_info)
{
if (tx_buffer_info->dma) {
if (tx_buffer_info->mapped_as_page)
dma_unmap_page(tx_ring->dev,
tx_buffer_info->dma,
tx_buffer_info->length,
DMA_TO_DEVICE);
else
dma_unmap_single(tx_ring->dev,
tx_buffer_info->dma,
tx_buffer_info->length,
DMA_TO_DEVICE);
tx_buffer_info->dma = 0;
}
if (tx_buffer_info->skb) {
dev_kfree_skb_any(tx_buffer_info->skb);
tx_buffer_info->skb = NULL;
}
tx_buffer_info->time_stamp = 0;
}
static bool ixgbevf_clean_tx_irq(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring *tx_ring)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
union ixgbe_adv_tx_desc *tx_desc, *eop_desc;
struct ixgbevf_tx_buffer *tx_buffer_info;
unsigned int i, eop, count = 0;
unsigned int total_bytes = 0, total_packets = 0;
if (test_bit(__IXGBEVF_DOWN, &adapter->state))
return true;
i = tx_ring->next_to_clean;
eop = tx_ring->tx_buffer_info[i].next_to_watch;
eop_desc = IXGBEVF_TX_DESC(tx_ring, eop);
while ((eop_desc->wb.status & cpu_to_le32(IXGBE_TXD_STAT_DD)) &&
(count < tx_ring->count)) {
bool cleaned = false;
rmb();
if (unlikely(eop != tx_ring->tx_buffer_info[i].next_to_watch))
goto cont_loop;
for ( ; !cleaned; count++) {
struct sk_buff *skb;
tx_desc = IXGBEVF_TX_DESC(tx_ring, i);
tx_buffer_info = &tx_ring->tx_buffer_info[i];
cleaned = (i == eop);
skb = tx_buffer_info->skb;
if (cleaned && skb) {
unsigned int segs, bytecount;
segs = skb_shinfo(skb)->gso_segs ?: 1;
bytecount = ((segs - 1) * skb_headlen(skb)) +
skb->len;
total_packets += segs;
total_bytes += bytecount;
}
ixgbevf_unmap_and_free_tx_resource(tx_ring,
tx_buffer_info);
tx_desc->wb.status = 0;
i++;
if (i == tx_ring->count)
i = 0;
}
cont_loop:
eop = tx_ring->tx_buffer_info[i].next_to_watch;
eop_desc = IXGBEVF_TX_DESC(tx_ring, eop);
}
tx_ring->next_to_clean = i;
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(count && netif_carrier_ok(tx_ring->netdev) &&
(IXGBE_DESC_UNUSED(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!test_bit(__IXGBEVF_DOWN, &adapter->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++adapter->restart_queue;
}
}
u64_stats_update_begin(&tx_ring->syncp);
tx_ring->total_bytes += total_bytes;
tx_ring->total_packets += total_packets;
u64_stats_update_end(&tx_ring->syncp);
return count < tx_ring->count;
}
static void ixgbevf_receive_skb(struct ixgbevf_q_vector *q_vector,
struct sk_buff *skb, u8 status,
struct ixgbevf_ring *ring,
union ixgbe_adv_rx_desc *rx_desc)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
bool is_vlan = (status & IXGBE_RXD_STAT_VP);
u16 tag = le16_to_cpu(rx_desc->wb.upper.vlan);
if (is_vlan && test_bit(tag & VLAN_VID_MASK, adapter->active_vlans))
__vlan_hwaccel_put_tag(skb, tag);
napi_gro_receive(&q_vector->napi, skb);
}
static inline void ixgbevf_rx_checksum(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *ring,
u32 status_err, struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if ((status_err & IXGBE_RXD_STAT_IPCS) &&
(status_err & IXGBE_RXDADV_ERR_IPE)) {
adapter->hw_csum_rx_error++;
return;
}
if (!(status_err & IXGBE_RXD_STAT_L4CS))
return;
if (status_err & IXGBE_RXDADV_ERR_TCPE) {
adapter->hw_csum_rx_error++;
return;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
adapter->hw_csum_rx_good++;
}
static void ixgbevf_alloc_rx_buffers(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *rx_ring,
int cleaned_count)
{
struct pci_dev *pdev = adapter->pdev;
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbevf_rx_buffer *bi;
struct sk_buff *skb;
unsigned int i = rx_ring->next_to_use;
bi = &rx_ring->rx_buffer_info[i];
while (cleaned_count--) {
rx_desc = IXGBEVF_RX_DESC(rx_ring, i);
skb = bi->skb;
if (!skb) {
skb = netdev_alloc_skb_ip_align(rx_ring->netdev,
rx_ring->rx_buf_len);
if (!skb) {
adapter->alloc_rx_buff_failed++;
goto no_buffers;
}
bi->skb = skb;
}
if (!bi->dma) {
bi->dma = dma_map_single(&pdev->dev, skb->data,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
}
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma);
i++;
if (i == rx_ring->count)
i = 0;
bi = &rx_ring->rx_buffer_info[i];
}
no_buffers:
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
ixgbevf_release_rx_desc(&adapter->hw, rx_ring, i);
}
}
static inline void ixgbevf_irq_enable_queues(struct ixgbevf_adapter *adapter,
u32 qmask)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, qmask);
}
static bool ixgbevf_clean_rx_irq(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring *rx_ring,
int budget)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct pci_dev *pdev = adapter->pdev;
union ixgbe_adv_rx_desc *rx_desc, *next_rxd;
struct ixgbevf_rx_buffer *rx_buffer_info, *next_buffer;
struct sk_buff *skb;
unsigned int i;
u32 len, staterr;
int cleaned_count = 0;
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
i = rx_ring->next_to_clean;
rx_desc = IXGBEVF_RX_DESC(rx_ring, i);
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
rx_buffer_info = &rx_ring->rx_buffer_info[i];
while (staterr & IXGBE_RXD_STAT_DD) {
if (!budget)
break;
budget--;
rmb();
len = le16_to_cpu(rx_desc->wb.upper.length);
skb = rx_buffer_info->skb;
prefetch(skb->data - NET_IP_ALIGN);
rx_buffer_info->skb = NULL;
if (rx_buffer_info->dma) {
dma_unmap_single(&pdev->dev, rx_buffer_info->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
rx_buffer_info->dma = 0;
skb_put(skb, len);
}
i++;
if (i == rx_ring->count)
i = 0;
next_rxd = IXGBEVF_RX_DESC(rx_ring, i);
prefetch(next_rxd);
cleaned_count++;
next_buffer = &rx_ring->rx_buffer_info[i];
if (!(staterr & IXGBE_RXD_STAT_EOP)) {
skb->next = next_buffer->skb;
skb->next->prev = skb;
adapter->non_eop_descs++;
goto next_desc;
}
if (unlikely(staterr & IXGBE_RXDADV_ERR_FRAME_ERR_MASK)) {
dev_kfree_skb_irq(skb);
goto next_desc;
}
ixgbevf_rx_checksum(adapter, rx_ring, staterr, skb);
total_rx_bytes += skb->len;
total_rx_packets++;
if (staterr & IXGBE_RXD_STAT_LB) {
u32 header_fixup_len = skb_headlen(skb);
if (header_fixup_len < 14)
skb_push(skb, header_fixup_len);
}
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
ixgbevf_receive_skb(q_vector, skb, staterr, rx_ring, rx_desc);
next_desc:
rx_desc->wb.upper.status_error = 0;
if (cleaned_count >= IXGBEVF_RX_BUFFER_WRITE) {
ixgbevf_alloc_rx_buffers(adapter, rx_ring,
cleaned_count);
cleaned_count = 0;
}
rx_desc = next_rxd;
rx_buffer_info = &rx_ring->rx_buffer_info[i];
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
}
rx_ring->next_to_clean = i;
cleaned_count = IXGBE_DESC_UNUSED(rx_ring);
if (cleaned_count)
ixgbevf_alloc_rx_buffers(adapter, rx_ring, cleaned_count);
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->total_packets += total_rx_packets;
rx_ring->total_bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
return !!budget;
}
static int ixgbevf_poll(struct napi_struct *napi, int budget)
{
struct ixgbevf_q_vector *q_vector =
container_of(napi, struct ixgbevf_q_vector, napi);
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbevf_ring *ring;
int per_ring_budget;
bool clean_complete = true;
ixgbevf_for_each_ring(ring, q_vector->tx)
clean_complete &= ixgbevf_clean_tx_irq(q_vector, ring);
if (q_vector->rx.count > 1)
per_ring_budget = max(budget/q_vector->rx.count, 1);
else
per_ring_budget = budget;
ixgbevf_for_each_ring(ring, q_vector->rx)
clean_complete &= ixgbevf_clean_rx_irq(q_vector, ring,
per_ring_budget);
if (!clean_complete)
return budget;
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbevf_set_itr(q_vector);
if (!test_bit(__IXGBEVF_DOWN, &adapter->state))
ixgbevf_irq_enable_queues(adapter,
1 << q_vector->v_idx);
return 0;
}
static void ixgbevf_write_eitr(struct ixgbevf_q_vector *q_vector)
{
struct ixgbevf_adapter *adapter = q_vector->adapter;
struct ixgbe_hw *hw = &adapter->hw;
int v_idx = q_vector->v_idx;
u32 itr_reg = q_vector->itr & IXGBE_MAX_EITR;
itr_reg |= IXGBE_EITR_CNT_WDIS;
IXGBE_WRITE_REG(hw, IXGBE_VTEITR(v_idx), itr_reg);
}
static void ixgbevf_configure_msix(struct ixgbevf_adapter *adapter)
{
struct ixgbevf_q_vector *q_vector;
int q_vectors, v_idx;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
adapter->eims_enable_mask = 0;
for (v_idx = 0; v_idx < q_vectors; v_idx++) {
struct ixgbevf_ring *ring;
q_vector = adapter->q_vector[v_idx];
ixgbevf_for_each_ring(ring, q_vector->rx)
ixgbevf_set_ivar(adapter, 0, ring->reg_idx, v_idx);
ixgbevf_for_each_ring(ring, q_vector->tx)
ixgbevf_set_ivar(adapter, 1, ring->reg_idx, v_idx);
if (q_vector->tx.ring && !q_vector->rx.ring) {
if (adapter->tx_itr_setting == 1)
q_vector->itr = IXGBE_10K_ITR;
else
q_vector->itr = adapter->tx_itr_setting;
} else {
if (adapter->rx_itr_setting == 1)
q_vector->itr = IXGBE_20K_ITR;
else
q_vector->itr = adapter->rx_itr_setting;
}
adapter->eims_enable_mask |= 1 << v_idx;
ixgbevf_write_eitr(q_vector);
}
ixgbevf_set_ivar(adapter, -1, 1, v_idx);
adapter->eims_other = 1 << v_idx;
adapter->eims_enable_mask |= adapter->eims_other;
}
static void ixgbevf_update_itr(struct ixgbevf_q_vector *q_vector,
struct ixgbevf_ring_container *ring_container)
{
int bytes = ring_container->total_bytes;
int packets = ring_container->total_packets;
u32 timepassed_us;
u64 bytes_perint;
u8 itr_setting = ring_container->itr;
if (packets == 0)
return;
timepassed_us = q_vector->itr >> 2;
bytes_perint = bytes / timepassed_us;
switch (itr_setting) {
case lowest_latency:
if (bytes_perint > 10)
itr_setting = low_latency;
break;
case low_latency:
if (bytes_perint > 20)
itr_setting = bulk_latency;
else if (bytes_perint <= 10)
itr_setting = lowest_latency;
break;
case bulk_latency:
if (bytes_perint <= 20)
itr_setting = low_latency;
break;
}
ring_container->total_bytes = 0;
ring_container->total_packets = 0;
ring_container->itr = itr_setting;
}
static void ixgbevf_set_itr(struct ixgbevf_q_vector *q_vector)
{
u32 new_itr = q_vector->itr;
u8 current_itr;
ixgbevf_update_itr(q_vector, &q_vector->tx);
ixgbevf_update_itr(q_vector, &q_vector->rx);
current_itr = max(q_vector->rx.itr, q_vector->tx.itr);
switch (current_itr) {
case lowest_latency:
new_itr = IXGBE_100K_ITR;
break;
case low_latency:
new_itr = IXGBE_20K_ITR;
break;
case bulk_latency:
default:
new_itr = IXGBE_8K_ITR;
break;
}
if (new_itr != q_vector->itr) {
new_itr = (10 * new_itr * q_vector->itr) /
((9 * new_itr) + q_vector->itr);
q_vector->itr = new_itr;
ixgbevf_write_eitr(q_vector);
}
}
static irqreturn_t ixgbevf_msix_mbx(int irq, void *data)
{
struct ixgbevf_adapter *adapter = data;
struct ixgbe_hw *hw = &adapter->hw;
u32 msg;
bool got_ack = false;
if (!hw->mbx.ops.check_for_ack(hw))
got_ack = true;
if (!hw->mbx.ops.check_for_msg(hw)) {
hw->mbx.ops.read(hw, &msg, 1);
if ((msg & IXGBE_MBVFICR_VFREQ_MASK) == IXGBE_PF_CONTROL_MSG)
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + 1));
if (msg & IXGBE_VT_MSGTYPE_NACK)
pr_warn("Last Request of type %2.2x to PF Nacked\n",
msg & 0xFF);
hw->mbx.v2p_mailbox |= IXGBE_VFMAILBOX_PFSTS;
}
if (got_ack)
hw->mbx.v2p_mailbox |= IXGBE_VFMAILBOX_PFACK;
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, adapter->eims_other);
return IRQ_HANDLED;
}
static irqreturn_t ixgbevf_msix_clean_rings(int irq, void *data)
{
struct ixgbevf_q_vector *q_vector = data;
if (q_vector->rx.ring || q_vector->tx.ring)
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static inline void map_vector_to_rxq(struct ixgbevf_adapter *a, int v_idx,
int r_idx)
{
struct ixgbevf_q_vector *q_vector = a->q_vector[v_idx];
a->rx_ring[r_idx].next = q_vector->rx.ring;
q_vector->rx.ring = &a->rx_ring[r_idx];
q_vector->rx.count++;
}
static inline void map_vector_to_txq(struct ixgbevf_adapter *a, int v_idx,
int t_idx)
{
struct ixgbevf_q_vector *q_vector = a->q_vector[v_idx];
a->tx_ring[t_idx].next = q_vector->tx.ring;
q_vector->tx.ring = &a->tx_ring[t_idx];
q_vector->tx.count++;
}
static int ixgbevf_map_rings_to_vectors(struct ixgbevf_adapter *adapter)
{
int q_vectors;
int v_start = 0;
int rxr_idx = 0, txr_idx = 0;
int rxr_remaining = adapter->num_rx_queues;
int txr_remaining = adapter->num_tx_queues;
int i, j;
int rqpv, tqpv;
int err = 0;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
if (q_vectors == adapter->num_rx_queues + adapter->num_tx_queues) {
for (; rxr_idx < rxr_remaining; v_start++, rxr_idx++)
map_vector_to_rxq(adapter, v_start, rxr_idx);
for (; txr_idx < txr_remaining; v_start++, txr_idx++)
map_vector_to_txq(adapter, v_start, txr_idx);
goto out;
}
for (i = v_start; i < q_vectors; i++) {
rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - i);
for (j = 0; j < rqpv; j++) {
map_vector_to_rxq(adapter, i, rxr_idx);
rxr_idx++;
rxr_remaining--;
}
}
for (i = v_start; i < q_vectors; i++) {
tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - i);
for (j = 0; j < tqpv; j++) {
map_vector_to_txq(adapter, i, txr_idx);
txr_idx++;
txr_remaining--;
}
}
out:
return err;
}
static int ixgbevf_request_msix_irqs(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
int vector, err;
int ri = 0, ti = 0;
for (vector = 0; vector < q_vectors; vector++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[vector];
struct msix_entry *entry = &adapter->msix_entries[vector];
if (q_vector->tx.ring && q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "TxRx", ri++);
ti++;
} else if (q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "rx", ri++);
} else if (q_vector->tx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "tx", ti++);
} else {
continue;
}
err = request_irq(entry->vector, &ixgbevf_msix_clean_rings, 0,
q_vector->name, q_vector);
if (err) {
hw_dbg(&adapter->hw,
"request_irq failed for MSIX interrupt "
"Error: %d\n", err);
goto free_queue_irqs;
}
}
err = request_irq(adapter->msix_entries[vector].vector,
&ixgbevf_msix_mbx, 0, netdev->name, adapter);
if (err) {
hw_dbg(&adapter->hw,
"request_irq for msix_mbx failed: %d\n", err);
goto free_queue_irqs;
}
return 0;
free_queue_irqs:
while (vector) {
vector--;
free_irq(adapter->msix_entries[vector].vector,
adapter->q_vector[vector]);
}
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
return err;
}
static inline void ixgbevf_reset_q_vectors(struct ixgbevf_adapter *adapter)
{
int i, q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (i = 0; i < q_vectors; i++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[i];
q_vector->rx.ring = NULL;
q_vector->tx.ring = NULL;
q_vector->rx.count = 0;
q_vector->tx.count = 0;
}
}
static int ixgbevf_request_irq(struct ixgbevf_adapter *adapter)
{
int err = 0;
err = ixgbevf_request_msix_irqs(adapter);
if (err)
hw_dbg(&adapter->hw,
"request_irq failed, Error %d\n", err);
return err;
}
static void ixgbevf_free_irq(struct ixgbevf_adapter *adapter)
{
int i, q_vectors;
q_vectors = adapter->num_msix_vectors;
i = q_vectors - 1;
free_irq(adapter->msix_entries[i].vector, adapter);
i--;
for (; i >= 0; i--) {
if (!adapter->q_vector[i]->rx.ring &&
!adapter->q_vector[i]->tx.ring)
continue;
free_irq(adapter->msix_entries[i].vector,
adapter->q_vector[i]);
}
ixgbevf_reset_q_vectors(adapter);
}
static inline void ixgbevf_irq_disable(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
IXGBE_WRITE_REG(hw, IXGBE_VTEIAM, 0);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMC, ~0);
IXGBE_WRITE_REG(hw, IXGBE_VTEIAC, 0);
IXGBE_WRITE_FLUSH(hw);
for (i = 0; i < adapter->num_msix_vectors; i++)
synchronize_irq(adapter->msix_entries[i].vector);
}
static inline void ixgbevf_irq_enable(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VTEIAM, adapter->eims_enable_mask);
IXGBE_WRITE_REG(hw, IXGBE_VTEIAC, adapter->eims_enable_mask);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMS, adapter->eims_enable_mask);
}
static void ixgbevf_configure_tx(struct ixgbevf_adapter *adapter)
{
u64 tdba;
struct ixgbe_hw *hw = &adapter->hw;
u32 i, j, tdlen, txctrl;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbevf_ring *ring = &adapter->tx_ring[i];
j = ring->reg_idx;
tdba = ring->dma;
tdlen = ring->count * sizeof(union ixgbe_adv_tx_desc);
IXGBE_WRITE_REG(hw, IXGBE_VFTDBAL(j),
(tdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_VFTDBAH(j), (tdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_VFTDLEN(j), tdlen);
IXGBE_WRITE_REG(hw, IXGBE_VFTDH(j), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFTDT(j), 0);
adapter->tx_ring[i].head = IXGBE_VFTDH(j);
adapter->tx_ring[i].tail = IXGBE_VFTDT(j);
txctrl = IXGBE_READ_REG(hw, IXGBE_VFDCA_TXCTRL(j));
txctrl &= ~IXGBE_DCA_TXCTRL_TX_WB_RO_EN;
IXGBE_WRITE_REG(hw, IXGBE_VFDCA_TXCTRL(j), txctrl);
}
}
static void ixgbevf_configure_srrctl(struct ixgbevf_adapter *adapter, int index)
{
struct ixgbevf_ring *rx_ring;
struct ixgbe_hw *hw = &adapter->hw;
u32 srrctl;
rx_ring = &adapter->rx_ring[index];
srrctl = IXGBE_SRRCTL_DROP_EN;
srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF;
if (rx_ring->rx_buf_len == MAXIMUM_ETHERNET_VLAN_SIZE)
srrctl |= IXGBEVF_RXBUFFER_2048 >>
IXGBE_SRRCTL_BSIZEPKT_SHIFT;
else
srrctl |= rx_ring->rx_buf_len >>
IXGBE_SRRCTL_BSIZEPKT_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_VFSRRCTL(index), srrctl);
}
static void ixgbevf_configure_rx(struct ixgbevf_adapter *adapter)
{
u64 rdba;
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int max_frame = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
int i, j;
u32 rdlen;
int rx_buf_len;
IXGBE_WRITE_REG(hw, IXGBE_VFPSRTYPE, 0);
if (netdev->mtu <= ETH_DATA_LEN)
rx_buf_len = MAXIMUM_ETHERNET_VLAN_SIZE;
else
rx_buf_len = ALIGN(max_frame, 1024);
rdlen = adapter->rx_ring[0].count * sizeof(union ixgbe_adv_rx_desc);
for (i = 0; i < adapter->num_rx_queues; i++) {
rdba = adapter->rx_ring[i].dma;
j = adapter->rx_ring[i].reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_VFRDBAL(j),
(rdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_VFRDBAH(j), (rdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_VFRDLEN(j), rdlen);
IXGBE_WRITE_REG(hw, IXGBE_VFRDH(j), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFRDT(j), 0);
adapter->rx_ring[i].head = IXGBE_VFRDH(j);
adapter->rx_ring[i].tail = IXGBE_VFRDT(j);
adapter->rx_ring[i].rx_buf_len = rx_buf_len;
ixgbevf_configure_srrctl(adapter, j);
}
}
static int ixgbevf_vlan_rx_add_vid(struct net_device *netdev, u16 vid)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.set_vfta)
hw->mac.ops.set_vfta(hw, vid, 0, true);
spin_unlock(&adapter->mbx_lock);
set_bit(vid, adapter->active_vlans);
return 0;
}
static int ixgbevf_vlan_rx_kill_vid(struct net_device *netdev, u16 vid)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.set_vfta)
hw->mac.ops.set_vfta(hw, vid, 0, false);
spin_unlock(&adapter->mbx_lock);
clear_bit(vid, adapter->active_vlans);
return 0;
}
static void ixgbevf_restore_vlan(struct ixgbevf_adapter *adapter)
{
u16 vid;
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
ixgbevf_vlan_rx_add_vid(adapter->netdev, vid);
}
static int ixgbevf_write_uc_addr_list(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int count = 0;
if ((netdev_uc_count(netdev)) > 10) {
pr_err("Too many unicast filters - No Space\n");
return -ENOSPC;
}
if (!netdev_uc_empty(netdev)) {
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, netdev) {
hw->mac.ops.set_uc_addr(hw, ++count, ha->addr);
udelay(200);
}
} else {
hw->mac.ops.set_uc_addr(hw, 0, NULL);
}
return count;
}
static void ixgbevf_set_rx_mode(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.update_mc_addr_list)
hw->mac.ops.update_mc_addr_list(hw, netdev);
ixgbevf_write_uc_addr_list(netdev);
spin_unlock(&adapter->mbx_lock);
}
static void ixgbevf_napi_enable_all(struct ixgbevf_adapter *adapter)
{
int q_idx;
struct ixgbevf_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
napi_enable(&q_vector->napi);
}
}
static void ixgbevf_napi_disable_all(struct ixgbevf_adapter *adapter)
{
int q_idx;
struct ixgbevf_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
napi_disable(&q_vector->napi);
}
}
static void ixgbevf_configure(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int i;
ixgbevf_set_rx_mode(netdev);
ixgbevf_restore_vlan(adapter);
ixgbevf_configure_tx(adapter);
ixgbevf_configure_rx(adapter);
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbevf_ring *ring = &adapter->rx_ring[i];
ixgbevf_alloc_rx_buffers(adapter, ring,
IXGBE_DESC_UNUSED(ring));
}
}
static inline void ixgbevf_rx_desc_queue_enable(struct ixgbevf_adapter *adapter,
int rxr)
{
struct ixgbe_hw *hw = &adapter->hw;
int j = adapter->rx_ring[rxr].reg_idx;
int k;
for (k = 0; k < IXGBE_MAX_RX_DESC_POLL; k++) {
if (IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(j)) & IXGBE_RXDCTL_ENABLE)
break;
else
msleep(1);
}
if (k >= IXGBE_MAX_RX_DESC_POLL) {
hw_dbg(hw, "RXDCTL.ENABLE on Rx queue %d "
"not set within the polling period\n", rxr);
}
ixgbevf_release_rx_desc(&adapter->hw, &adapter->rx_ring[rxr],
(adapter->rx_ring[rxr].count - 1));
}
static void ixgbevf_save_reset_stats(struct ixgbevf_adapter *adapter)
{
if (adapter->stats.vfgprc || adapter->stats.vfgptc) {
adapter->stats.saved_reset_vfgprc += adapter->stats.vfgprc -
adapter->stats.base_vfgprc;
adapter->stats.saved_reset_vfgptc += adapter->stats.vfgptc -
adapter->stats.base_vfgptc;
adapter->stats.saved_reset_vfgorc += adapter->stats.vfgorc -
adapter->stats.base_vfgorc;
adapter->stats.saved_reset_vfgotc += adapter->stats.vfgotc -
adapter->stats.base_vfgotc;
adapter->stats.saved_reset_vfmprc += adapter->stats.vfmprc -
adapter->stats.base_vfmprc;
}
}
static void ixgbevf_init_last_counter_stats(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
adapter->stats.last_vfgprc = IXGBE_READ_REG(hw, IXGBE_VFGPRC);
adapter->stats.last_vfgorc = IXGBE_READ_REG(hw, IXGBE_VFGORC_LSB);
adapter->stats.last_vfgorc |=
(((u64)(IXGBE_READ_REG(hw, IXGBE_VFGORC_MSB))) << 32);
adapter->stats.last_vfgptc = IXGBE_READ_REG(hw, IXGBE_VFGPTC);
adapter->stats.last_vfgotc = IXGBE_READ_REG(hw, IXGBE_VFGOTC_LSB);
adapter->stats.last_vfgotc |=
(((u64)(IXGBE_READ_REG(hw, IXGBE_VFGOTC_MSB))) << 32);
adapter->stats.last_vfmprc = IXGBE_READ_REG(hw, IXGBE_VFMPRC);
adapter->stats.base_vfgprc = adapter->stats.last_vfgprc;
adapter->stats.base_vfgorc = adapter->stats.last_vfgorc;
adapter->stats.base_vfgptc = adapter->stats.last_vfgptc;
adapter->stats.base_vfgotc = adapter->stats.last_vfgotc;
adapter->stats.base_vfmprc = adapter->stats.last_vfmprc;
}
static void ixgbevf_up_complete(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
int i, j = 0;
int num_rx_rings = adapter->num_rx_queues;
u32 txdctl, rxdctl;
u32 msg[2];
for (i = 0; i < adapter->num_tx_queues; i++) {
j = adapter->tx_ring[i].reg_idx;
txdctl = IXGBE_READ_REG(hw, IXGBE_VFTXDCTL(j));
txdctl |= (8 << 16);
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(j), txdctl);
}
for (i = 0; i < adapter->num_tx_queues; i++) {
j = adapter->tx_ring[i].reg_idx;
txdctl = IXGBE_READ_REG(hw, IXGBE_VFTXDCTL(j));
txdctl |= IXGBE_TXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(j), txdctl);
}
for (i = 0; i < num_rx_rings; i++) {
j = adapter->rx_ring[i].reg_idx;
rxdctl = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(j));
rxdctl |= IXGBE_RXDCTL_ENABLE | IXGBE_RXDCTL_VME;
if (hw->mac.type == ixgbe_mac_X540_vf) {
rxdctl &= ~IXGBE_RXDCTL_RLPMLMASK;
rxdctl |= ((netdev->mtu + ETH_HLEN + ETH_FCS_LEN) |
IXGBE_RXDCTL_RLPML_EN);
}
IXGBE_WRITE_REG(hw, IXGBE_VFRXDCTL(j), rxdctl);
ixgbevf_rx_desc_queue_enable(adapter, i);
}
ixgbevf_configure_msix(adapter);
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.set_rar) {
if (is_valid_ether_addr(hw->mac.addr))
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, 0);
else
hw->mac.ops.set_rar(hw, 0, hw->mac.perm_addr, 0);
}
msg[0] = IXGBE_VF_SET_LPE;
msg[1] = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
hw->mbx.ops.write_posted(hw, msg, 2);
spin_unlock(&adapter->mbx_lock);
clear_bit(__IXGBEVF_DOWN, &adapter->state);
ixgbevf_napi_enable_all(adapter);
netif_tx_start_all_queues(netdev);
ixgbevf_save_reset_stats(adapter);
ixgbevf_init_last_counter_stats(adapter);
mod_timer(&adapter->watchdog_timer, jiffies);
}
void ixgbevf_up(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
ixgbevf_configure(adapter);
ixgbevf_up_complete(adapter);
IXGBE_READ_REG(hw, IXGBE_VTEICR);
ixgbevf_irq_enable(adapter);
}
static void ixgbevf_clean_rx_ring(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *rx_ring)
{
struct pci_dev *pdev = adapter->pdev;
unsigned long size;
unsigned int i;
if (!rx_ring->rx_buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
struct ixgbevf_rx_buffer *rx_buffer_info;
rx_buffer_info = &rx_ring->rx_buffer_info[i];
if (rx_buffer_info->dma) {
dma_unmap_single(&pdev->dev, rx_buffer_info->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
rx_buffer_info->dma = 0;
}
if (rx_buffer_info->skb) {
struct sk_buff *skb = rx_buffer_info->skb;
rx_buffer_info->skb = NULL;
do {
struct sk_buff *this = skb;
skb = skb->prev;
dev_kfree_skb(this);
} while (skb);
}
}
size = sizeof(struct ixgbevf_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
if (rx_ring->head)
writel(0, adapter->hw.hw_addr + rx_ring->head);
if (rx_ring->tail)
writel(0, adapter->hw.hw_addr + rx_ring->tail);
}
static void ixgbevf_clean_tx_ring(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *tx_ring)
{
struct ixgbevf_tx_buffer *tx_buffer_info;
unsigned long size;
unsigned int i;
if (!tx_ring->tx_buffer_info)
return;
for (i = 0; i < tx_ring->count; i++) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
ixgbevf_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
}
size = sizeof(struct ixgbevf_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_buffer_info, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
if (tx_ring->head)
writel(0, adapter->hw.hw_addr + tx_ring->head);
if (tx_ring->tail)
writel(0, adapter->hw.hw_addr + tx_ring->tail);
}
static void ixgbevf_clean_all_rx_rings(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbevf_clean_rx_ring(adapter, &adapter->rx_ring[i]);
}
static void ixgbevf_clean_all_tx_rings(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
ixgbevf_clean_tx_ring(adapter, &adapter->tx_ring[i]);
}
void ixgbevf_down(struct ixgbevf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 txdctl;
int i, j;
set_bit(__IXGBEVF_DOWN, &adapter->state);
netif_tx_disable(netdev);
msleep(10);
netif_tx_stop_all_queues(netdev);
ixgbevf_irq_disable(adapter);
ixgbevf_napi_disable_all(adapter);
del_timer_sync(&adapter->watchdog_timer);
while (adapter->flags & IXGBE_FLAG_IN_WATCHDOG_TASK)
msleep(1);
for (i = 0; i < adapter->num_tx_queues; i++) {
j = adapter->tx_ring[i].reg_idx;
txdctl = IXGBE_READ_REG(hw, IXGBE_VFTXDCTL(j));
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(j),
(txdctl & ~IXGBE_TXDCTL_ENABLE));
}
netif_carrier_off(netdev);
if (!pci_channel_offline(adapter->pdev))
ixgbevf_reset(adapter);
ixgbevf_clean_all_tx_rings(adapter);
ixgbevf_clean_all_rx_rings(adapter);
}
void ixgbevf_reinit_locked(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
WARN_ON(in_interrupt());
while (test_and_set_bit(__IXGBEVF_RESETTING, &adapter->state))
msleep(1);
if (!hw->mac.ops.reset_hw(hw)) {
ixgbevf_down(adapter);
ixgbevf_up(adapter);
}
clear_bit(__IXGBEVF_RESETTING, &adapter->state);
}
void ixgbevf_reset(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.reset_hw(hw))
hw_dbg(hw, "PF still resetting\n");
else
hw->mac.ops.init_hw(hw);
spin_unlock(&adapter->mbx_lock);
if (is_valid_ether_addr(adapter->hw.mac.addr)) {
memcpy(netdev->dev_addr, adapter->hw.mac.addr,
netdev->addr_len);
memcpy(netdev->perm_addr, adapter->hw.mac.addr,
netdev->addr_len);
}
}
static void ixgbevf_acquire_msix_vectors(struct ixgbevf_adapter *adapter,
int vectors)
{
int err, vector_threshold;
vector_threshold = MIN_MSIX_COUNT;
while (vectors >= vector_threshold) {
err = pci_enable_msix(adapter->pdev, adapter->msix_entries,
vectors);
if (!err)
break;
else if (err < 0)
vectors = 0;
else
vectors = err;
}
if (vectors < vector_threshold) {
hw_dbg(&adapter->hw,
"Unable to allocate MSI-X interrupts\n");
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
} else {
adapter->num_msix_vectors = vectors;
}
}
static void ixgbevf_set_num_queues(struct ixgbevf_adapter *adapter)
{
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
}
static int ixgbevf_alloc_queues(struct ixgbevf_adapter *adapter)
{
int i;
adapter->tx_ring = kcalloc(adapter->num_tx_queues,
sizeof(struct ixgbevf_ring), GFP_KERNEL);
if (!adapter->tx_ring)
goto err_tx_ring_allocation;
adapter->rx_ring = kcalloc(adapter->num_rx_queues,
sizeof(struct ixgbevf_ring), GFP_KERNEL);
if (!adapter->rx_ring)
goto err_rx_ring_allocation;
for (i = 0; i < adapter->num_tx_queues; i++) {
adapter->tx_ring[i].count = adapter->tx_ring_count;
adapter->tx_ring[i].queue_index = i;
adapter->tx_ring[i].reg_idx = i;
adapter->tx_ring[i].dev = &adapter->pdev->dev;
adapter->tx_ring[i].netdev = adapter->netdev;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
adapter->rx_ring[i].count = adapter->rx_ring_count;
adapter->rx_ring[i].queue_index = i;
adapter->rx_ring[i].reg_idx = i;
adapter->rx_ring[i].dev = &adapter->pdev->dev;
adapter->rx_ring[i].netdev = adapter->netdev;
}
return 0;
err_rx_ring_allocation:
kfree(adapter->tx_ring);
err_tx_ring_allocation:
return -ENOMEM;
}
static int ixgbevf_set_interrupt_capability(struct ixgbevf_adapter *adapter)
{
int err = 0;
int vector, v_budget;
v_budget = max(adapter->num_rx_queues, adapter->num_tx_queues);
v_budget = min_t(int, v_budget, num_online_cpus());
v_budget += NON_Q_VECTORS;
adapter->msix_entries = kcalloc(v_budget,
sizeof(struct msix_entry), GFP_KERNEL);
if (!adapter->msix_entries) {
err = -ENOMEM;
goto out;
}
for (vector = 0; vector < v_budget; vector++)
adapter->msix_entries[vector].entry = vector;
ixgbevf_acquire_msix_vectors(adapter, v_budget);
out:
return err;
}
static int ixgbevf_alloc_q_vectors(struct ixgbevf_adapter *adapter)
{
int q_idx, num_q_vectors;
struct ixgbevf_q_vector *q_vector;
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
q_vector = kzalloc(sizeof(struct ixgbevf_q_vector), GFP_KERNEL);
if (!q_vector)
goto err_out;
q_vector->adapter = adapter;
q_vector->v_idx = q_idx;
netif_napi_add(adapter->netdev, &q_vector->napi,
ixgbevf_poll, 64);
adapter->q_vector[q_idx] = q_vector;
}
return 0;
err_out:
while (q_idx) {
q_idx--;
q_vector = adapter->q_vector[q_idx];
netif_napi_del(&q_vector->napi);
kfree(q_vector);
adapter->q_vector[q_idx] = NULL;
}
return -ENOMEM;
}
static void ixgbevf_free_q_vectors(struct ixgbevf_adapter *adapter)
{
int q_idx, num_q_vectors;
int napi_vectors;
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
napi_vectors = adapter->num_rx_queues;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
struct ixgbevf_q_vector *q_vector = adapter->q_vector[q_idx];
adapter->q_vector[q_idx] = NULL;
if (q_idx < napi_vectors)
netif_napi_del(&q_vector->napi);
kfree(q_vector);
}
}
static void ixgbevf_reset_interrupt_capability(struct ixgbevf_adapter *adapter)
{
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
}
static int ixgbevf_init_interrupt_scheme(struct ixgbevf_adapter *adapter)
{
int err;
ixgbevf_set_num_queues(adapter);
err = ixgbevf_set_interrupt_capability(adapter);
if (err) {
hw_dbg(&adapter->hw,
"Unable to setup interrupt capabilities\n");
goto err_set_interrupt;
}
err = ixgbevf_alloc_q_vectors(adapter);
if (err) {
hw_dbg(&adapter->hw, "Unable to allocate memory for queue "
"vectors\n");
goto err_alloc_q_vectors;
}
err = ixgbevf_alloc_queues(adapter);
if (err) {
pr_err("Unable to allocate memory for queues\n");
goto err_alloc_queues;
}
hw_dbg(&adapter->hw, "Multiqueue %s: Rx Queue count = %u, "
"Tx Queue count = %u\n",
(adapter->num_rx_queues > 1) ? "Enabled" :
"Disabled", adapter->num_rx_queues, adapter->num_tx_queues);
set_bit(__IXGBEVF_DOWN, &adapter->state);
return 0;
err_alloc_queues:
ixgbevf_free_q_vectors(adapter);
err_alloc_q_vectors:
ixgbevf_reset_interrupt_capability(adapter);
err_set_interrupt:
return err;
}
static int __devinit ixgbevf_sw_init(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
int err;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
hw->mbx.ops.init_params(hw);
hw->mac.max_tx_queues = MAX_TX_QUEUES;
hw->mac.max_rx_queues = MAX_RX_QUEUES;
err = hw->mac.ops.reset_hw(hw);
if (err) {
dev_info(&pdev->dev,
"PF still in reset state, assigning new address\n");
eth_hw_addr_random(adapter->netdev);
memcpy(adapter->hw.mac.addr, adapter->netdev->dev_addr,
adapter->netdev->addr_len);
} else {
err = hw->mac.ops.init_hw(hw);
if (err) {
pr_err("init_shared_code failed: %d\n", err);
goto out;
}
memcpy(adapter->netdev->dev_addr, adapter->hw.mac.addr,
adapter->netdev->addr_len);
}
spin_lock_init(&adapter->mbx_lock);
adapter->rx_itr_setting = 1;
adapter->tx_itr_setting = 1;
adapter->tx_ring_count = IXGBEVF_DEFAULT_TXD;
adapter->rx_ring_count = IXGBEVF_DEFAULT_RXD;
set_bit(__IXGBEVF_DOWN, &adapter->state);
return 0;
out:
return err;
}
void ixgbevf_update_stats(struct ixgbevf_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
UPDATE_VF_COUNTER_32bit(IXGBE_VFGPRC, adapter->stats.last_vfgprc,
adapter->stats.vfgprc);
UPDATE_VF_COUNTER_32bit(IXGBE_VFGPTC, adapter->stats.last_vfgptc,
adapter->stats.vfgptc);
UPDATE_VF_COUNTER_36bit(IXGBE_VFGORC_LSB, IXGBE_VFGORC_MSB,
adapter->stats.last_vfgorc,
adapter->stats.vfgorc);
UPDATE_VF_COUNTER_36bit(IXGBE_VFGOTC_LSB, IXGBE_VFGOTC_MSB,
adapter->stats.last_vfgotc,
adapter->stats.vfgotc);
UPDATE_VF_COUNTER_32bit(IXGBE_VFMPRC, adapter->stats.last_vfmprc,
adapter->stats.vfmprc);
}
static void ixgbevf_watchdog(unsigned long data)
{
struct ixgbevf_adapter *adapter = (struct ixgbevf_adapter *)data;
struct ixgbe_hw *hw = &adapter->hw;
u32 eics = 0;
int i;
if (test_bit(__IXGBEVF_DOWN, &adapter->state))
goto watchdog_short_circuit;
for (i = 0; i < adapter->num_msix_vectors - NON_Q_VECTORS; i++) {
struct ixgbevf_q_vector *qv = adapter->q_vector[i];
if (qv->rx.ring || qv->tx.ring)
eics |= 1 << i;
}
IXGBE_WRITE_REG(hw, IXGBE_VTEICS, eics);
watchdog_short_circuit:
schedule_work(&adapter->watchdog_task);
}
static void ixgbevf_tx_timeout(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
schedule_work(&adapter->reset_task);
}
static void ixgbevf_reset_task(struct work_struct *work)
{
struct ixgbevf_adapter *adapter;
adapter = container_of(work, struct ixgbevf_adapter, reset_task);
if (test_bit(__IXGBEVF_DOWN, &adapter->state) ||
test_bit(__IXGBEVF_RESETTING, &adapter->state))
return;
adapter->tx_timeout_count++;
ixgbevf_reinit_locked(adapter);
}
static void ixgbevf_watchdog_task(struct work_struct *work)
{
struct ixgbevf_adapter *adapter = container_of(work,
struct ixgbevf_adapter,
watchdog_task);
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = adapter->link_speed;
bool link_up = adapter->link_up;
adapter->flags |= IXGBE_FLAG_IN_WATCHDOG_TASK;
if (hw->mac.ops.check_link) {
s32 need_reset;
spin_lock(&adapter->mbx_lock);
need_reset = hw->mac.ops.check_link(hw, &link_speed,
&link_up, false);
spin_unlock(&adapter->mbx_lock);
if (need_reset) {
adapter->link_up = link_up;
adapter->link_speed = link_speed;
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
schedule_work(&adapter->reset_task);
goto pf_has_reset;
}
} else {
link_speed = IXGBE_LINK_SPEED_10GB_FULL;
link_up = true;
}
adapter->link_up = link_up;
adapter->link_speed = link_speed;
if (link_up) {
if (!netif_carrier_ok(netdev)) {
hw_dbg(&adapter->hw, "NIC Link is Up, %u Gbps\n",
(link_speed == IXGBE_LINK_SPEED_10GB_FULL) ?
10 : 1);
netif_carrier_on(netdev);
netif_tx_wake_all_queues(netdev);
}
} else {
adapter->link_up = false;
adapter->link_speed = 0;
if (netif_carrier_ok(netdev)) {
hw_dbg(&adapter->hw, "NIC Link is Down\n");
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
}
}
ixgbevf_update_stats(adapter);
pf_has_reset:
if (!test_bit(__IXGBEVF_DOWN, &adapter->state))
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + (2 * HZ)));
adapter->flags &= ~IXGBE_FLAG_IN_WATCHDOG_TASK;
}
void ixgbevf_free_tx_resources(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *tx_ring)
{
struct pci_dev *pdev = adapter->pdev;
ixgbevf_clean_tx_ring(adapter, tx_ring);
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
dma_free_coherent(&pdev->dev, tx_ring->size, tx_ring->desc,
tx_ring->dma);
tx_ring->desc = NULL;
}
static void ixgbevf_free_all_tx_resources(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
if (adapter->tx_ring[i].desc)
ixgbevf_free_tx_resources(adapter,
&adapter->tx_ring[i]);
}
int ixgbevf_setup_tx_resources(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *tx_ring)
{
struct pci_dev *pdev = adapter->pdev;
int size;
size = sizeof(struct ixgbevf_tx_buffer) * tx_ring->count;
tx_ring->tx_buffer_info = vzalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union ixgbe_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(&pdev->dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
return 0;
err:
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
hw_dbg(&adapter->hw, "Unable to allocate memory for the transmit "
"descriptor ring\n");
return -ENOMEM;
}
static int ixgbevf_setup_all_tx_resources(struct ixgbevf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
err = ixgbevf_setup_tx_resources(adapter, &adapter->tx_ring[i]);
if (!err)
continue;
hw_dbg(&adapter->hw,
"Allocation for Tx Queue %u failed\n", i);
break;
}
return err;
}
int ixgbevf_setup_rx_resources(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *rx_ring)
{
struct pci_dev *pdev = adapter->pdev;
int size;
size = sizeof(struct ixgbevf_rx_buffer) * rx_ring->count;
rx_ring->rx_buffer_info = vzalloc(size);
if (!rx_ring->rx_buffer_info)
goto alloc_failed;
rx_ring->size = rx_ring->count * sizeof(union ixgbe_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(&pdev->dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc) {
hw_dbg(&adapter->hw,
"Unable to allocate memory for "
"the receive descriptor ring\n");
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
goto alloc_failed;
}
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
return 0;
alloc_failed:
return -ENOMEM;
}
static int ixgbevf_setup_all_rx_resources(struct ixgbevf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = ixgbevf_setup_rx_resources(adapter, &adapter->rx_ring[i]);
if (!err)
continue;
hw_dbg(&adapter->hw,
"Allocation for Rx Queue %u failed\n", i);
break;
}
return err;
}
void ixgbevf_free_rx_resources(struct ixgbevf_adapter *adapter,
struct ixgbevf_ring *rx_ring)
{
struct pci_dev *pdev = adapter->pdev;
ixgbevf_clean_rx_ring(adapter, rx_ring);
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
dma_free_coherent(&pdev->dev, rx_ring->size, rx_ring->desc,
rx_ring->dma);
rx_ring->desc = NULL;
}
static void ixgbevf_free_all_rx_resources(struct ixgbevf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rx_ring[i].desc)
ixgbevf_free_rx_resources(adapter,
&adapter->rx_ring[i]);
}
static int ixgbevf_open(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int err;
if (test_bit(__IXGBEVF_TESTING, &adapter->state))
return -EBUSY;
if (hw->adapter_stopped) {
ixgbevf_reset(adapter);
if (hw->adapter_stopped) {
err = IXGBE_ERR_MBX;
pr_err("Unable to start - perhaps the PF Driver isn't "
"up yet\n");
goto err_setup_reset;
}
}
err = ixgbevf_setup_all_tx_resources(adapter);
if (err)
goto err_setup_tx;
err = ixgbevf_setup_all_rx_resources(adapter);
if (err)
goto err_setup_rx;
ixgbevf_configure(adapter);
ixgbevf_map_rings_to_vectors(adapter);
ixgbevf_up_complete(adapter);
IXGBE_READ_REG(hw, IXGBE_VTEICR);
err = ixgbevf_request_irq(adapter);
if (err)
goto err_req_irq;
ixgbevf_irq_enable(adapter);
return 0;
err_req_irq:
ixgbevf_down(adapter);
ixgbevf_free_irq(adapter);
err_setup_rx:
ixgbevf_free_all_rx_resources(adapter);
err_setup_tx:
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_reset(adapter);
err_setup_reset:
return err;
}
static int ixgbevf_close(struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
ixgbevf_down(adapter);
ixgbevf_free_irq(adapter);
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_free_all_rx_resources(adapter);
return 0;
}
static void ixgbevf_tx_ctxtdesc(struct ixgbevf_ring *tx_ring,
u32 vlan_macip_lens, u32 type_tucmd,
u32 mss_l4len_idx)
{
struct ixgbe_adv_tx_context_desc *context_desc;
u16 i = tx_ring->next_to_use;
context_desc = IXGBEVF_TX_CTXTDESC(tx_ring, i);
i++;
tx_ring->next_to_use = (i < tx_ring->count) ? i : 0;
type_tucmd |= IXGBE_TXD_CMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT;
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = 0;
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
}
static int ixgbevf_tso(struct ixgbevf_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags, u8 *hdr_len)
{
u32 vlan_macip_lens, type_tucmd;
u32 mss_l4len_idx, l4len;
if (!skb_is_gso(skb))
return 0;
if (skb_header_cloned(skb)) {
int err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (err)
return err;
}
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_TCP;
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(iph->saddr,
iph->daddr, 0,
IPPROTO_TCP,
0);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
} else if (skb_is_gso_v6(skb)) {
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
}
l4len = tcp_hdrlen(skb);
*hdr_len += l4len;
*hdr_len = skb_transport_offset(skb) + l4len;
mss_l4len_idx = l4len << IXGBE_ADVTXD_L4LEN_SHIFT;
mss_l4len_idx |= skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT;
mss_l4len_idx |= 1 << IXGBE_ADVTXD_IDX_SHIFT;
vlan_macip_lens = skb_network_header_len(skb);
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbevf_tx_ctxtdesc(tx_ring, vlan_macip_lens,
type_tucmd, mss_l4len_idx);
return 1;
}
static bool ixgbevf_tx_csum(struct ixgbevf_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags)
{
u32 vlan_macip_lens = 0;
u32 mss_l4len_idx = 0;
u32 type_tucmd = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
u8 l4_hdr = 0;
switch (skb->protocol) {
case __constant_htons(ETH_P_IP):
vlan_macip_lens |= skb_network_header_len(skb);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
l4_hdr = ip_hdr(skb)->protocol;
break;
case __constant_htons(ETH_P_IPV6):
vlan_macip_lens |= skb_network_header_len(skb);
l4_hdr = ipv6_hdr(skb)->nexthdr;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but proto=%x!\n",
skb->protocol);
}
break;
}
switch (l4_hdr) {
case IPPROTO_TCP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
mss_l4len_idx = tcp_hdrlen(skb) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_SCTP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_SCTP;
mss_l4len_idx = sizeof(struct sctphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_UDP:
mss_l4len_idx = sizeof(struct udphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but l4 proto=%x!\n",
l4_hdr);
}
break;
}
}
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbevf_tx_ctxtdesc(tx_ring, vlan_macip_lens,
type_tucmd, mss_l4len_idx);
return (skb->ip_summed == CHECKSUM_PARTIAL);
}
static int ixgbevf_tx_map(struct ixgbevf_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags,
unsigned int first)
{
struct ixgbevf_tx_buffer *tx_buffer_info;
unsigned int len;
unsigned int total = skb->len;
unsigned int offset = 0, size;
int count = 0;
unsigned int nr_frags = skb_shinfo(skb)->nr_frags;
unsigned int f;
int i;
i = tx_ring->next_to_use;
len = min(skb_headlen(skb), total);
while (len) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
size = min(len, (unsigned int)IXGBE_MAX_DATA_PER_TXD);
tx_buffer_info->length = size;
tx_buffer_info->mapped_as_page = false;
tx_buffer_info->dma = dma_map_single(tx_ring->dev,
skb->data + offset,
size, DMA_TO_DEVICE);
if (dma_mapping_error(tx_ring->dev, tx_buffer_info->dma))
goto dma_error;
tx_buffer_info->next_to_watch = i;
len -= size;
total -= size;
offset += size;
count++;
i++;
if (i == tx_ring->count)
i = 0;
}
for (f = 0; f < nr_frags; f++) {
const struct skb_frag_struct *frag;
frag = &skb_shinfo(skb)->frags[f];
len = min((unsigned int)skb_frag_size(frag), total);
offset = 0;
while (len) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
size = min(len, (unsigned int)IXGBE_MAX_DATA_PER_TXD);
tx_buffer_info->length = size;
tx_buffer_info->dma =
skb_frag_dma_map(tx_ring->dev, frag,
offset, size, DMA_TO_DEVICE);
tx_buffer_info->mapped_as_page = true;
if (dma_mapping_error(tx_ring->dev,
tx_buffer_info->dma))
goto dma_error;
tx_buffer_info->next_to_watch = i;
len -= size;
total -= size;
offset += size;
count++;
i++;
if (i == tx_ring->count)
i = 0;
}
if (total == 0)
break;
}
if (i == 0)
i = tx_ring->count - 1;
else
i = i - 1;
tx_ring->tx_buffer_info[i].skb = skb;
tx_ring->tx_buffer_info[first].next_to_watch = i;
tx_ring->tx_buffer_info[first].time_stamp = jiffies;
return count;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
tx_buffer_info->dma = 0;
tx_buffer_info->next_to_watch = 0;
count--;
while (count >= 0) {
count--;
i--;
if (i < 0)
i += tx_ring->count;
tx_buffer_info = &tx_ring->tx_buffer_info[i];
ixgbevf_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
}
return count;
}
static void ixgbevf_tx_queue(struct ixgbevf_ring *tx_ring, int tx_flags,
int count, u32 paylen, u8 hdr_len)
{
union ixgbe_adv_tx_desc *tx_desc = NULL;
struct ixgbevf_tx_buffer *tx_buffer_info;
u32 olinfo_status = 0, cmd_type_len = 0;
unsigned int i;
u32 txd_cmd = IXGBE_TXD_CMD_EOP | IXGBE_TXD_CMD_RS | IXGBE_TXD_CMD_IFCS;
cmd_type_len |= IXGBE_ADVTXD_DTYP_DATA;
cmd_type_len |= IXGBE_ADVTXD_DCMD_IFCS | IXGBE_ADVTXD_DCMD_DEXT;
if (tx_flags & IXGBE_TX_FLAGS_VLAN)
cmd_type_len |= IXGBE_ADVTXD_DCMD_VLE;
if (tx_flags & IXGBE_TX_FLAGS_CSUM)
olinfo_status |= IXGBE_ADVTXD_POPTS_TXSM;
if (tx_flags & IXGBE_TX_FLAGS_TSO) {
cmd_type_len |= IXGBE_ADVTXD_DCMD_TSE;
olinfo_status |= (1 << IXGBE_ADVTXD_IDX_SHIFT);
if (tx_flags & IXGBE_TX_FLAGS_IPV4)
olinfo_status |= IXGBE_ADVTXD_POPTS_IXSM;
}
olinfo_status |= IXGBE_ADVTXD_CC;
olinfo_status |= ((paylen - hdr_len) << IXGBE_ADVTXD_PAYLEN_SHIFT);
i = tx_ring->next_to_use;
while (count--) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
tx_desc = IXGBEVF_TX_DESC(tx_ring, i);
tx_desc->read.buffer_addr = cpu_to_le64(tx_buffer_info->dma);
tx_desc->read.cmd_type_len =
cpu_to_le32(cmd_type_len | tx_buffer_info->length);
tx_desc->read.olinfo_status = cpu_to_le32(olinfo_status);
i++;
if (i == tx_ring->count)
i = 0;
}
tx_desc->read.cmd_type_len |= cpu_to_le32(txd_cmd);
tx_ring->next_to_use = i;
}
static int __ixgbevf_maybe_stop_tx(struct ixgbevf_ring *tx_ring, int size)
{
struct ixgbevf_adapter *adapter = netdev_priv(tx_ring->netdev);
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(IXGBE_DESC_UNUSED(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++adapter->restart_queue;
return 0;
}
static int ixgbevf_maybe_stop_tx(struct ixgbevf_ring *tx_ring, int size)
{
if (likely(IXGBE_DESC_UNUSED(tx_ring) >= size))
return 0;
return __ixgbevf_maybe_stop_tx(tx_ring, size);
}
static int ixgbevf_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbevf_ring *tx_ring;
unsigned int first;
unsigned int tx_flags = 0;
u8 hdr_len = 0;
int r_idx = 0, tso;
u16 count = TXD_USE_COUNT(skb_headlen(skb));
#if PAGE_SIZE > IXGBE_MAX_DATA_PER_TXD
unsigned short f;
#endif
tx_ring = &adapter->tx_ring[r_idx];
#if PAGE_SIZE > IXGBE_MAX_DATA_PER_TXD
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
#else
count += skb_shinfo(skb)->nr_frags;
#endif
if (ixgbevf_maybe_stop_tx(tx_ring, count + 3)) {
adapter->tx_busy++;
return NETDEV_TX_BUSY;
}
if (vlan_tx_tag_present(skb)) {
tx_flags |= vlan_tx_tag_get(skb);
tx_flags <<= IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_VLAN;
}
first = tx_ring->next_to_use;
if (skb->protocol == htons(ETH_P_IP))
tx_flags |= IXGBE_TX_FLAGS_IPV4;
tso = ixgbevf_tso(tx_ring, skb, tx_flags, &hdr_len);
if (tso < 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (tso)
tx_flags |= IXGBE_TX_FLAGS_TSO | IXGBE_TX_FLAGS_CSUM;
else if (ixgbevf_tx_csum(tx_ring, skb, tx_flags))
tx_flags |= IXGBE_TX_FLAGS_CSUM;
ixgbevf_tx_queue(tx_ring, tx_flags,
ixgbevf_tx_map(tx_ring, skb, tx_flags, first),
skb->len, hdr_len);
wmb();
writel(tx_ring->next_to_use, adapter->hw.hw_addr + tx_ring->tail);
ixgbevf_maybe_stop_tx(tx_ring, DESC_NEEDED);
return NETDEV_TX_OK;
}
static int ixgbevf_set_mac(struct net_device *netdev, void *p)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(hw->mac.addr, addr->sa_data, netdev->addr_len);
spin_lock(&adapter->mbx_lock);
if (hw->mac.ops.set_rar)
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, 0);
spin_unlock(&adapter->mbx_lock);
return 0;
}
static int ixgbevf_change_mtu(struct net_device *netdev, int new_mtu)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
int max_possible_frame = MAXIMUM_ETHERNET_VLAN_SIZE;
u32 msg[2];
if (adapter->hw.mac.type == ixgbe_mac_X540_vf)
max_possible_frame = IXGBE_MAX_JUMBO_FRAME_SIZE;
if ((new_mtu < 68) || (max_frame > max_possible_frame))
return -EINVAL;
hw_dbg(&adapter->hw, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
if (!netif_running(netdev)) {
msg[0] = IXGBE_VF_SET_LPE;
msg[1] = max_frame;
hw->mbx.ops.write_posted(hw, msg, 2);
}
if (netif_running(netdev))
ixgbevf_reinit_locked(adapter);
return 0;
}
static void ixgbevf_shutdown(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
netif_device_detach(netdev);
if (netif_running(netdev)) {
ixgbevf_down(adapter);
ixgbevf_free_irq(adapter);
ixgbevf_free_all_tx_resources(adapter);
ixgbevf_free_all_rx_resources(adapter);
}
pci_save_state(pdev);
pci_disable_device(pdev);
}
static struct rtnl_link_stats64 *ixgbevf_get_stats(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
unsigned int start;
u64 bytes, packets;
const struct ixgbevf_ring *ring;
int i;
ixgbevf_update_stats(adapter);
stats->multicast = adapter->stats.vfmprc - adapter->stats.base_vfmprc;
for (i = 0; i < adapter->num_rx_queues; i++) {
ring = &adapter->rx_ring[i];
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
bytes = ring->total_bytes;
packets = ring->total_packets;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
stats->rx_bytes += bytes;
stats->rx_packets += packets;
}
for (i = 0; i < adapter->num_tx_queues; i++) {
ring = &adapter->tx_ring[i];
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
bytes = ring->total_bytes;
packets = ring->total_packets;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
stats->tx_bytes += bytes;
stats->tx_packets += packets;
}
return stats;
}
static void ixgbevf_assign_netdev_ops(struct net_device *dev)
{
dev->netdev_ops = &ixgbe_netdev_ops;
ixgbevf_set_ethtool_ops(dev);
dev->watchdog_timeo = 5 * HZ;
}
static int __devinit ixgbevf_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *netdev;
struct ixgbevf_adapter *adapter = NULL;
struct ixgbe_hw *hw = NULL;
const struct ixgbevf_info *ii = ixgbevf_info_tbl[ent->driver_data];
static int cards_found;
int err, pci_using_dac;
err = pci_enable_device(pdev);
if (err)
return err;
if (!dma_set_mask(&pdev->dev, DMA_BIT_MASK(64)) &&
!dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
} else {
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
err = dma_set_coherent_mask(&pdev->dev,
DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No usable DMA "
"configuration, aborting\n");
goto err_dma;
}
}
pci_using_dac = 0;
}
err = pci_request_regions(pdev, ixgbevf_driver_name);
if (err) {
dev_err(&pdev->dev, "pci_request_regions failed 0x%x\n", err);
goto err_pci_reg;
}
pci_set_master(pdev);
netdev = alloc_etherdev_mq(sizeof(struct ixgbevf_adapter),
MAX_TX_QUEUES);
if (!netdev) {
err = -ENOMEM;
goto err_alloc_etherdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
pci_save_state(pdev);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
}
ixgbevf_assign_netdev_ops(netdev);
adapter->bd_number = cards_found;
memcpy(&hw->mac.ops, ii->mac_ops, sizeof(hw->mac.ops));
hw->mac.type = ii->mac;
memcpy(&hw->mbx.ops, &ixgbevf_mbx_ops,
sizeof(struct ixgbe_mbx_operations));
err = ixgbevf_sw_init(adapter);
if (err)
goto err_sw_init;
memcpy(netdev->perm_addr, adapter->hw.mac.addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->dev_addr)) {
pr_err("invalid MAC address\n");
err = -EIO;
goto err_sw_init;
}
netdev->hw_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXCSUM;
netdev->features = netdev->hw_features |
NETIF_F_HW_VLAN_TX |
NETIF_F_HW_VLAN_RX |
NETIF_F_HW_VLAN_FILTER;
netdev->vlan_features |= NETIF_F_TSO;
netdev->vlan_features |= NETIF_F_TSO6;
netdev->vlan_features |= NETIF_F_IP_CSUM;
netdev->vlan_features |= NETIF_F_IPV6_CSUM;
netdev->vlan_features |= NETIF_F_SG;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->priv_flags |= IFF_UNICAST_FLT;
init_timer(&adapter->watchdog_timer);
adapter->watchdog_timer.function = ixgbevf_watchdog;
adapter->watchdog_timer.data = (unsigned long)adapter;
INIT_WORK(&adapter->reset_task, ixgbevf_reset_task);
INIT_WORK(&adapter->watchdog_task, ixgbevf_watchdog_task);
err = ixgbevf_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
if (hw->mac.ops.get_bus_info)
hw->mac.ops.get_bus_info(hw);
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
netif_carrier_off(netdev);
ixgbevf_init_last_counter_stats(adapter);
hw_dbg(hw, "%pM\n", netdev->dev_addr);
hw_dbg(hw, "MAC: %d\n", hw->mac.type);
hw_dbg(hw, "Intel(R) 82599 Virtual Function\n");
cards_found++;
return 0;
err_register:
err_sw_init:
ixgbevf_reset_interrupt_capability(adapter);
iounmap(hw->hw_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void __devexit ixgbevf_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
set_bit(__IXGBEVF_DOWN, &adapter->state);
del_timer_sync(&adapter->watchdog_timer);
cancel_work_sync(&adapter->reset_task);
cancel_work_sync(&adapter->watchdog_task);
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
ixgbevf_reset_interrupt_capability(adapter);
iounmap(adapter->hw.hw_addr);
pci_release_regions(pdev);
hw_dbg(&adapter->hw, "Remove complete\n");
kfree(adapter->tx_ring);
kfree(adapter->rx_ring);
free_netdev(netdev);
pci_disable_device(pdev);
}
static pci_ers_result_t ixgbevf_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev))
ixgbevf_down(adapter);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t ixgbevf_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
if (pci_enable_device_mem(pdev)) {
dev_err(&pdev->dev,
"Cannot re-enable PCI device after reset.\n");
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
ixgbevf_reset(adapter);
return PCI_ERS_RESULT_RECOVERED;
}
static void ixgbevf_io_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct ixgbevf_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev))
ixgbevf_up(adapter);
netif_device_attach(netdev);
}
static int __init ixgbevf_init_module(void)
{
int ret;
pr_info("%s - version %s\n", ixgbevf_driver_string,
ixgbevf_driver_version);
pr_info("%s\n", ixgbevf_copyright);
ret = pci_register_driver(&ixgbevf_driver);
return ret;
}
static void __exit ixgbevf_exit_module(void)
{
pci_unregister_driver(&ixgbevf_driver);
}
char *ixgbevf_get_hw_dev_name(struct ixgbe_hw *hw)
{
struct ixgbevf_adapter *adapter = hw->back;
return adapter->netdev->name;
}
