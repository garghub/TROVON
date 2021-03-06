void
islpci_eth_cleanup_transmit(islpci_private *priv,
isl38xx_control_block *control_block)
{
struct sk_buff *skb;
u32 index;
while (priv->free_data_tx !=
le32_to_cpu(control_block->
device_curr_frag[ISL38XX_CB_TX_DATA_LQ])) {
index = priv->free_data_tx % ISL38XX_CB_TX_QSIZE;
if (priv->pci_map_tx_address[index]) {
skb = priv->data_low_tx[index];
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"cleanup skb %p skb->data %p skb->len %u truesize %u\n ",
skb, skb->data, skb->len, skb->truesize);
#endif
pci_unmap_single(priv->pdev,
priv->pci_map_tx_address[index],
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
skb = NULL;
}
priv->free_data_tx++;
}
}
netdev_tx_t
islpci_eth_transmit(struct sk_buff *skb, struct net_device *ndev)
{
islpci_private *priv = netdev_priv(ndev);
isl38xx_control_block *cb = priv->control_block;
u32 index;
dma_addr_t pci_map_address;
int frame_size;
isl38xx_fragment *fragment;
int offset;
struct sk_buff *newskb;
int newskb_offset;
unsigned long flags;
unsigned char wds_mac[6];
u32 curr_frag;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_FUNCTION_CALLS, "islpci_eth_transmit\n");
#endif
spin_lock_irqsave(&priv->slock, flags);
curr_frag = le32_to_cpu(cb->driver_curr_frag[ISL38XX_CB_TX_DATA_LQ]);
if (unlikely(curr_frag - priv->free_data_tx >= ISL38XX_CB_TX_QSIZE)) {
printk(KERN_ERR "%s: transmit device queue full when awake\n",
ndev->name);
netif_stop_queue(ndev);
isl38xx_w32_flush(priv->device_base, ISL38XX_DEV_INT_UPDATE,
ISL38XX_DEV_INT_REG);
udelay(ISL38XX_WRITEIO_DELAY);
goto drop_free;
}
if (likely(((long) skb->data & 0x03) | init_wds)) {
offset = (4 - (long) skb->data) & 0x03;
offset += init_wds ? 6 : 0;
if (!skb_cloned(skb) && (skb_tailroom(skb) >= offset)) {
unsigned char *src = skb->data;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "skb offset %i wds %i\n", offset,
init_wds);
#endif
skb_reserve(skb, (4 - (long) skb->data) & 0x03);
if (init_wds) {
skb_put(skb, 6);
#ifdef ISLPCI_ETH_DEBUG
printk("islpci_eth_transmit:wds_mac\n");
#endif
memmove(skb->data + 6, src, skb->len);
skb_copy_to_linear_data(skb, wds_mac, 6);
} else {
memmove(skb->data, src, skb->len);
}
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "memmove %p %p %i\n", skb->data,
src, skb->len);
#endif
} else {
newskb =
dev_alloc_skb(init_wds ? skb->len + 6 : skb->len);
if (unlikely(newskb == NULL)) {
printk(KERN_ERR "%s: Cannot allocate skb\n",
ndev->name);
goto drop_free;
}
newskb_offset = (4 - (long) newskb->data) & 0x03;
if (newskb_offset)
skb_reserve(newskb, newskb_offset);
skb_put(newskb, init_wds ? skb->len + 6 : skb->len);
if (init_wds) {
skb_copy_from_linear_data(skb,
newskb->data + 6,
skb->len);
skb_copy_to_linear_data(newskb, wds_mac, 6);
#ifdef ISLPCI_ETH_DEBUG
printk("islpci_eth_transmit:wds_mac\n");
#endif
} else
skb_copy_from_linear_data(skb, newskb->data,
skb->len);
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "memcpy %p %p %i wds %i\n",
newskb->data, skb->data, skb->len, init_wds);
#endif
newskb->dev = skb->dev;
dev_kfree_skb_irq(skb);
skb = newskb;
}
}
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_BUFFER_CONTENTS, "\ntx %p ", skb->data);
display_buffer((char *) skb->data, skb->len);
#endif
pci_map_address = pci_map_single(priv->pdev,
(void *) skb->data, skb->len,
PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(priv->pdev, pci_map_address)) {
printk(KERN_WARNING "%s: cannot map buffer to PCI\n",
ndev->name);
goto drop_free;
}
index = curr_frag % ISL38XX_CB_TX_QSIZE;
fragment = &cb->tx_data_low[index];
priv->pci_map_tx_address[index] = pci_map_address;
priv->data_low_tx[index] = skb;
frame_size = skb->len;
fragment->size = cpu_to_le16(frame_size);
fragment->flags = cpu_to_le16(0);
fragment->address = cpu_to_le32(pci_map_address);
curr_frag++;
wmb();
cb->driver_curr_frag[ISL38XX_CB_TX_DATA_LQ] = cpu_to_le32(curr_frag);
if (curr_frag - priv->free_data_tx + ISL38XX_MIN_QTHRESHOLD
> ISL38XX_CB_TX_QSIZE) {
netif_stop_queue(ndev);
priv->data_low_tx_full = 1;
}
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += skb->len;
islpci_trigger(priv);
spin_unlock_irqrestore(&priv->slock, flags);
return NETDEV_TX_OK;
drop_free:
ndev->stats.tx_dropped++;
spin_unlock_irqrestore(&priv->slock, flags);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static inline int
islpci_monitor_rx(islpci_private *priv, struct sk_buff **skb)
{
struct rfmon_header *hdr = (struct rfmon_header *) (*skb)->data;
if (hdr->flags & 0x01)
return -1;
if (priv->ndev->type == ARPHRD_IEEE80211_PRISM) {
struct avs_80211_1_header *avs;
u32 clock = le32_to_cpu(hdr->clock);
u8 rate = hdr->rate;
u16 freq = le16_to_cpu(hdr->freq);
u8 rssi = hdr->rssi;
skb_pull(*skb, sizeof (struct rfmon_header));
if (skb_headroom(*skb) < sizeof (struct avs_80211_1_header)) {
struct sk_buff *newskb = skb_copy_expand(*skb,
sizeof (struct
avs_80211_1_header),
0, GFP_ATOMIC);
if (newskb) {
dev_kfree_skb_irq(*skb);
*skb = newskb;
} else
return -1;
}
avs =
(struct avs_80211_1_header *) skb_push(*skb,
sizeof (struct
avs_80211_1_header));
avs->version = cpu_to_be32(P80211CAPTURE_VERSION);
avs->length = cpu_to_be32(sizeof (struct avs_80211_1_header));
avs->mactime = cpu_to_be64(clock);
avs->hosttime = cpu_to_be64(jiffies);
avs->phytype = cpu_to_be32(6);
avs->channel = cpu_to_be32(channel_of_freq(freq));
avs->datarate = cpu_to_be32(rate * 5);
avs->antenna = cpu_to_be32(0);
avs->priority = cpu_to_be32(0);
avs->ssi_type = cpu_to_be32(3);
avs->ssi_signal = cpu_to_be32(rssi & 0x7f);
avs->ssi_noise = cpu_to_be32(priv->local_iwstatistics.qual.noise);
avs->preamble = cpu_to_be32(0);
avs->encoding = cpu_to_be32(0);
} else
skb_pull(*skb, sizeof (struct rfmon_header));
(*skb)->protocol = htons(ETH_P_802_2);
skb_reset_mac_header(*skb);
(*skb)->pkt_type = PACKET_OTHERHOST;
return 0;
}
int
islpci_eth_receive(islpci_private *priv)
{
struct net_device *ndev = priv->ndev;
isl38xx_control_block *control_block = priv->control_block;
struct sk_buff *skb;
u16 size;
u32 index, offset;
unsigned char *src;
int discard = 0;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_FUNCTION_CALLS, "islpci_eth_receive\n");
#endif
index = priv->free_data_rx % ISL38XX_CB_RX_QSIZE;
size = le16_to_cpu(control_block->rx_data_low[index].size);
skb = priv->data_low_rx[index];
offset = ((unsigned long)
le32_to_cpu(control_block->rx_data_low[index].address) -
(unsigned long) skb->data) & 3;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"frq->addr %x skb->data %p skb->len %u offset %u truesize %u\n ",
control_block->rx_data_low[priv->free_data_rx].address, skb->data,
skb->len, offset, skb->truesize);
#endif
pci_unmap_single(priv->pdev,
priv->pci_map_rx_address[index],
MAX_FRAGMENT_SIZE_RX + 2, PCI_DMA_FROMDEVICE);
skb_put(skb, size);
if (offset) {
skb_pull(skb, 2);
skb_put(skb, 2);
}
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_BUFFER_CONTENTS, "\nrx %p ", skb->data);
display_buffer((char *) skb->data, skb->len);
#endif
if (init_wds) {
src = skb->data + 6;
memmove(skb->data, src, skb->len - 6);
skb_trim(skb, skb->len - 6);
}
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "Fragment size %i in skb at %p\n", size, skb);
DEBUG(SHOW_TRACING, "Skb data at %p, length %i\n", skb->data, skb->len);
DEBUG(SHOW_BUFFER_CONTENTS, "\nrx %p ", skb->data);
display_buffer((char *) skb->data, skb->len);
#endif
if (unlikely(priv->iw_mode == IW_MODE_MONITOR)) {
skb->dev = ndev;
discard = islpci_monitor_rx(priv, &skb);
} else {
if (unlikely(skb->data[2 * ETH_ALEN] == 0)) {
struct iw_quality wstats;
struct rx_annex_header *annex =
(struct rx_annex_header *) skb->data;
wstats.level = annex->rfmon.rssi;
wstats.noise = priv->local_iwstatistics.qual.noise;
wstats.qual = wstats.level - wstats.noise;
wstats.updated = 0x07;
wireless_spy_update(ndev, annex->addr2, &wstats);
skb_copy_from_linear_data(skb,
(skb->data +
sizeof(struct rfmon_header)),
2 * ETH_ALEN);
skb_pull(skb, sizeof (struct rfmon_header));
}
skb->protocol = eth_type_trans(skb, ndev);
}
skb->ip_summed = CHECKSUM_NONE;
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += size;
#ifdef ISLPCI_ETH_DEBUG
printk
("islpci_eth_receive:netif_rx %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X\n",
skb->data[0], skb->data[1], skb->data[2], skb->data[3],
skb->data[4], skb->data[5]);
#endif
if (unlikely(discard)) {
dev_kfree_skb_irq(skb);
skb = NULL;
} else
netif_rx(skb);
priv->free_data_rx++;
while (index =
le32_to_cpu(control_block->
driver_curr_frag[ISL38XX_CB_RX_DATA_LQ]),
index - priv->free_data_rx < ISL38XX_CB_RX_QSIZE) {
skb = dev_alloc_skb(MAX_FRAGMENT_SIZE_RX + 2);
if (unlikely(skb == NULL)) {
DEBUG(SHOW_ERROR_MESSAGES, "Error allocating skb\n");
break;
}
skb_reserve(skb, (4 - (long) skb->data) & 0x03);
index = index % ISL38XX_CB_RX_QSIZE;
priv->data_low_rx[index] = skb;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"new alloc skb %p skb->data %p skb->len %u index %u truesize %u\n ",
skb, skb->data, skb->len, index, skb->truesize);
#endif
priv->pci_map_rx_address[index] =
pci_map_single(priv->pdev, (void *) skb->data,
MAX_FRAGMENT_SIZE_RX + 2,
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(priv->pdev,
priv->pci_map_rx_address[index])) {
DEBUG(SHOW_ERROR_MESSAGES,
"Error mapping DMA address\n");
dev_kfree_skb_irq(skb);
skb = NULL;
break;
}
control_block->rx_data_low[index].address =
cpu_to_le32((u32)priv->pci_map_rx_address[index]);
wmb();
le32_add_cpu(&control_block->
driver_curr_frag[ISL38XX_CB_RX_DATA_LQ], 1);
}
islpci_trigger(priv);
return 0;
}
void
islpci_do_reset_and_wake(struct work_struct *work)
{
islpci_private *priv = container_of(work, islpci_private, reset_task);
islpci_reset(priv, 1);
priv->reset_task_pending = 0;
smp_wmb();
netif_wake_queue(priv->ndev);
}
void
islpci_eth_tx_timeout(struct net_device *ndev)
{
islpci_private *priv = netdev_priv(ndev);
ndev->stats.tx_errors++;
if (!priv->reset_task_pending) {
printk(KERN_WARNING
"%s: tx_timeout, scheduling reset", ndev->name);
netif_stop_queue(ndev);
priv->reset_task_pending = 1;
schedule_work(&priv->reset_task);
} else {
printk(KERN_WARNING
"%s: tx_timeout, waiting for reset", ndev->name);
}
}
