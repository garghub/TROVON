static int ftgmac100_reset_mac(struct ftgmac100 *priv, u32 maccr)
{
struct net_device *netdev = priv->netdev;
int i;
iowrite32(maccr, priv->base + FTGMAC100_OFFSET_MACCR);
iowrite32(maccr | FTGMAC100_MACCR_SW_RST,
priv->base + FTGMAC100_OFFSET_MACCR);
for (i = 0; i < 200; i++) {
unsigned int maccr;
maccr = ioread32(priv->base + FTGMAC100_OFFSET_MACCR);
if (!(maccr & FTGMAC100_MACCR_SW_RST))
return 0;
udelay(1);
}
netdev_err(netdev, "Hardware reset failed\n");
return -EIO;
}
static int ftgmac100_reset_and_config_mac(struct ftgmac100 *priv)
{
u32 maccr = 0;
switch (priv->cur_speed) {
case SPEED_10:
case 0:
break;
case SPEED_100:
maccr |= FTGMAC100_MACCR_FAST_MODE;
break;
case SPEED_1000:
maccr |= FTGMAC100_MACCR_GIGA_MODE;
break;
default:
netdev_err(priv->netdev, "Unknown speed %d !\n",
priv->cur_speed);
break;
}
priv->rx_pointer = 0;
priv->tx_clean_pointer = 0;
priv->tx_pointer = 0;
if (ftgmac100_reset_mac(priv, maccr))
return -EIO;
usleep_range(10, 1000);
return ftgmac100_reset_mac(priv, maccr);
}
static void ftgmac100_write_mac_addr(struct ftgmac100 *priv, const u8 *mac)
{
unsigned int maddr = mac[0] << 8 | mac[1];
unsigned int laddr = mac[2] << 24 | mac[3] << 16 | mac[4] << 8 | mac[5];
iowrite32(maddr, priv->base + FTGMAC100_OFFSET_MAC_MADR);
iowrite32(laddr, priv->base + FTGMAC100_OFFSET_MAC_LADR);
}
static void ftgmac100_initial_mac(struct ftgmac100 *priv)
{
u8 mac[ETH_ALEN];
unsigned int m;
unsigned int l;
void *addr;
addr = device_get_mac_address(priv->dev, mac, ETH_ALEN);
if (addr) {
ether_addr_copy(priv->netdev->dev_addr, mac);
dev_info(priv->dev, "Read MAC address %pM from device tree\n",
mac);
return;
}
m = ioread32(priv->base + FTGMAC100_OFFSET_MAC_MADR);
l = ioread32(priv->base + FTGMAC100_OFFSET_MAC_LADR);
mac[0] = (m >> 8) & 0xff;
mac[1] = m & 0xff;
mac[2] = (l >> 24) & 0xff;
mac[3] = (l >> 16) & 0xff;
mac[4] = (l >> 8) & 0xff;
mac[5] = l & 0xff;
if (is_valid_ether_addr(mac)) {
ether_addr_copy(priv->netdev->dev_addr, mac);
dev_info(priv->dev, "Read MAC address %pM from chip\n", mac);
} else {
eth_hw_addr_random(priv->netdev);
dev_info(priv->dev, "Generated random MAC address %pM\n",
priv->netdev->dev_addr);
}
}
static int ftgmac100_set_mac_addr(struct net_device *dev, void *p)
{
int ret;
ret = eth_prepare_mac_addr_change(dev, p);
if (ret < 0)
return ret;
eth_commit_mac_addr_change(dev, p);
ftgmac100_write_mac_addr(netdev_priv(dev), dev->dev_addr);
return 0;
}
static void ftgmac100_config_pause(struct ftgmac100 *priv)
{
u32 fcr = FTGMAC100_FCR_PAUSE_TIME(16);
if (priv->rx_pause)
fcr |= FTGMAC100_FCR_FC_EN;
if (priv->tx_pause)
fcr |= FTGMAC100_FCR_FCTHR_EN;
iowrite32(fcr, priv->base + FTGMAC100_OFFSET_FCR);
}
static void ftgmac100_init_hw(struct ftgmac100 *priv)
{
u32 reg, rfifo_sz, tfifo_sz;
reg = ioread32(priv->base + FTGMAC100_OFFSET_ISR);
iowrite32(reg, priv->base + FTGMAC100_OFFSET_ISR);
iowrite32(priv->rxdes_dma, priv->base + FTGMAC100_OFFSET_RXR_BADR);
iowrite32(priv->txdes_dma, priv->base + FTGMAC100_OFFSET_NPTXR_BADR);
iowrite32(FTGMAC100_RBSR_SIZE(RX_BUF_SIZE),
priv->base + FTGMAC100_OFFSET_RBSR);
iowrite32(FTGMAC100_APTC_RXPOLL_CNT(1),
priv->base + FTGMAC100_OFFSET_APTC);
ftgmac100_write_mac_addr(priv, priv->netdev->dev_addr);
iowrite32(priv->maht0, priv->base + FTGMAC100_OFFSET_MAHT0);
iowrite32(priv->maht1, priv->base + FTGMAC100_OFFSET_MAHT1);
iowrite32(FTGMAC100_DBLAC_RXDES_SIZE(2) |
FTGMAC100_DBLAC_TXDES_SIZE(2) |
FTGMAC100_DBLAC_RXBURST_SIZE(3) |
FTGMAC100_DBLAC_TXBURST_SIZE(3) |
FTGMAC100_DBLAC_RX_THR_EN |
FTGMAC100_DBLAC_RXFIFO_HTHR(6) |
FTGMAC100_DBLAC_RXFIFO_LTHR(2),
priv->base + FTGMAC100_OFFSET_DBLAC);
iowrite32(FTGMAC100_ITC_RXINT_THR(1) |
FTGMAC100_ITC_TXINT_THR(1),
priv->base + FTGMAC100_OFFSET_ITC);
reg = ioread32(priv->base + FTGMAC100_OFFSET_FEAR);
rfifo_sz = reg & 0x00000007;
tfifo_sz = (reg >> 3) & 0x00000007;
reg = ioread32(priv->base + FTGMAC100_OFFSET_TPAFCR);
reg &= ~0x3f000000;
reg |= (tfifo_sz << 27);
reg |= (rfifo_sz << 24);
iowrite32(reg, priv->base + FTGMAC100_OFFSET_TPAFCR);
}
static void ftgmac100_start_hw(struct ftgmac100 *priv)
{
u32 maccr = ioread32(priv->base + FTGMAC100_OFFSET_MACCR);
maccr &= (FTGMAC100_MACCR_FAST_MODE | FTGMAC100_MACCR_GIGA_MODE);
maccr |= FTGMAC100_MACCR_TXDMA_EN |
FTGMAC100_MACCR_RXDMA_EN |
FTGMAC100_MACCR_TXMAC_EN |
FTGMAC100_MACCR_RXMAC_EN |
FTGMAC100_MACCR_CRC_APD |
FTGMAC100_MACCR_PHY_LINK_LEVEL |
FTGMAC100_MACCR_RX_RUNT |
FTGMAC100_MACCR_RX_BROADPKT;
if (priv->cur_duplex == DUPLEX_FULL)
maccr |= FTGMAC100_MACCR_FULLDUP;
if (priv->netdev->flags & IFF_PROMISC)
maccr |= FTGMAC100_MACCR_RX_ALL;
if (priv->netdev->flags & IFF_ALLMULTI)
maccr |= FTGMAC100_MACCR_RX_MULTIPKT;
else if (netdev_mc_count(priv->netdev))
maccr |= FTGMAC100_MACCR_HT_MULTI_EN;
if (priv->netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
maccr |= FTGMAC100_MACCR_RM_VLAN;
iowrite32(maccr, priv->base + FTGMAC100_OFFSET_MACCR);
}
static void ftgmac100_stop_hw(struct ftgmac100 *priv)
{
iowrite32(0, priv->base + FTGMAC100_OFFSET_MACCR);
}
static void ftgmac100_calc_mc_hash(struct ftgmac100 *priv)
{
struct netdev_hw_addr *ha;
priv->maht1 = 0;
priv->maht0 = 0;
netdev_for_each_mc_addr(ha, priv->netdev) {
u32 crc_val = ether_crc_le(ETH_ALEN, ha->addr);
crc_val = (~(crc_val >> 2)) & 0x3f;
if (crc_val >= 32)
priv->maht1 |= 1ul << (crc_val - 32);
else
priv->maht0 |= 1ul << (crc_val);
}
}
static void ftgmac100_set_rx_mode(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
ftgmac100_calc_mc_hash(priv);
if (!netif_running(netdev))
return;
iowrite32(priv->maht0, priv->base + FTGMAC100_OFFSET_MAHT0);
iowrite32(priv->maht1, priv->base + FTGMAC100_OFFSET_MAHT1);
ftgmac100_start_hw(priv);
}
static int ftgmac100_alloc_rx_buf(struct ftgmac100 *priv, unsigned int entry,
struct ftgmac100_rxdes *rxdes, gfp_t gfp)
{
struct net_device *netdev = priv->netdev;
struct sk_buff *skb;
dma_addr_t map;
int err = 0;
skb = netdev_alloc_skb_ip_align(netdev, RX_BUF_SIZE);
if (unlikely(!skb)) {
if (net_ratelimit())
netdev_warn(netdev, "failed to allocate rx skb\n");
err = -ENOMEM;
map = priv->rx_scratch_dma;
} else {
map = dma_map_single(priv->dev, skb->data, RX_BUF_SIZE,
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(priv->dev, map))) {
if (net_ratelimit())
netdev_err(netdev, "failed to map rx page\n");
dev_kfree_skb_any(skb);
map = priv->rx_scratch_dma;
skb = NULL;
err = -ENOMEM;
}
}
priv->rx_skbs[entry] = skb;
rxdes->rxdes3 = cpu_to_le32(map);
dma_wmb();
if (entry == (priv->rx_q_entries - 1))
rxdes->rxdes0 = cpu_to_le32(priv->rxdes0_edorr_mask);
else
rxdes->rxdes0 = 0;
return err;
}
static unsigned int ftgmac100_next_rx_pointer(struct ftgmac100 *priv,
unsigned int pointer)
{
return (pointer + 1) & (priv->rx_q_entries - 1);
}
static void ftgmac100_rx_packet_error(struct ftgmac100 *priv, u32 status)
{
struct net_device *netdev = priv->netdev;
if (status & FTGMAC100_RXDES0_RX_ERR)
netdev->stats.rx_errors++;
if (status & FTGMAC100_RXDES0_CRC_ERR)
netdev->stats.rx_crc_errors++;
if (status & (FTGMAC100_RXDES0_FTL |
FTGMAC100_RXDES0_RUNT |
FTGMAC100_RXDES0_RX_ODD_NB))
netdev->stats.rx_length_errors++;
}
static bool ftgmac100_rx_packet(struct ftgmac100 *priv, int *processed)
{
struct net_device *netdev = priv->netdev;
struct ftgmac100_rxdes *rxdes;
struct sk_buff *skb;
unsigned int pointer, size;
u32 status, csum_vlan;
dma_addr_t map;
pointer = priv->rx_pointer;
rxdes = &priv->rxdes[pointer];
status = le32_to_cpu(rxdes->rxdes0);
if (!(status & FTGMAC100_RXDES0_RXPKT_RDY))
return false;
dma_rmb();
if (unlikely(!(status & FTGMAC100_RXDES0_FRS) ||
!(status & FTGMAC100_RXDES0_LRS)))
goto drop;
size = status & FTGMAC100_RXDES0_VDBC;
csum_vlan = le32_to_cpu(rxdes->rxdes1);
if (unlikely(status & RXDES0_ANY_ERROR)) {
if ((status & FTGMAC100_RXDES0_RUNT) &&
(csum_vlan & FTGMAC100_RXDES1_VLANTAG_AVAIL) &&
(size >= 60))
status &= ~FTGMAC100_RXDES0_RUNT;
if (status & RXDES0_ANY_ERROR) {
ftgmac100_rx_packet_error(priv, status);
goto drop;
}
}
skb = priv->rx_skbs[pointer];
if (!unlikely(skb)) {
ftgmac100_alloc_rx_buf(priv, pointer, rxdes, GFP_ATOMIC);
goto drop;
}
if (unlikely(status & FTGMAC100_RXDES0_MULTICAST))
netdev->stats.multicast++;
if (netdev->features & NETIF_F_RXCSUM) {
u32 err_bits = FTGMAC100_RXDES1_TCP_CHKSUM_ERR |
FTGMAC100_RXDES1_UDP_CHKSUM_ERR |
FTGMAC100_RXDES1_IP_CHKSUM_ERR;
if ((csum_vlan & err_bits) ||
!(csum_vlan & FTGMAC100_RXDES1_PROT_MASK))
skb->ip_summed = CHECKSUM_NONE;
else
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
skb_put(skb, size);
if ((netdev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
(csum_vlan & FTGMAC100_RXDES1_VLANTAG_AVAIL))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
csum_vlan & 0xffff);
map = le32_to_cpu(rxdes->rxdes3);
#if defined(CONFIG_ARM) && !defined(CONFIG_ARM_DMA_USE_IOMMU)
dma_unmap_single(priv->dev, map, size, DMA_FROM_DEVICE);
#else
dma_unmap_single(priv->dev, map, RX_BUF_SIZE, DMA_FROM_DEVICE);
#endif
ftgmac100_alloc_rx_buf(priv, pointer, rxdes, GFP_ATOMIC);
priv->rx_pointer = ftgmac100_next_rx_pointer(priv, pointer);
skb->protocol = eth_type_trans(skb, netdev);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += size;
if (skb->ip_summed == CHECKSUM_NONE)
netif_receive_skb(skb);
else
napi_gro_receive(&priv->napi, skb);
(*processed)++;
return true;
drop:
rxdes->rxdes0 = cpu_to_le32(status & priv->rxdes0_edorr_mask);
priv->rx_pointer = ftgmac100_next_rx_pointer(priv, pointer);
netdev->stats.rx_dropped++;
return true;
}
static u32 ftgmac100_base_tx_ctlstat(struct ftgmac100 *priv,
unsigned int index)
{
if (index == (priv->tx_q_entries - 1))
return priv->txdes0_edotr_mask;
else
return 0;
}
static unsigned int ftgmac100_next_tx_pointer(struct ftgmac100 *priv,
unsigned int pointer)
{
return (pointer + 1) & (priv->tx_q_entries - 1);
}
static u32 ftgmac100_tx_buf_avail(struct ftgmac100 *priv)
{
return (priv->tx_clean_pointer - priv->tx_pointer - 1) &
(priv->tx_q_entries - 1);
}
static bool ftgmac100_tx_buf_cleanable(struct ftgmac100 *priv)
{
return priv->tx_pointer != priv->tx_clean_pointer;
}
static void ftgmac100_free_tx_packet(struct ftgmac100 *priv,
unsigned int pointer,
struct sk_buff *skb,
struct ftgmac100_txdes *txdes,
u32 ctl_stat)
{
dma_addr_t map = le32_to_cpu(txdes->txdes3);
size_t len;
if (ctl_stat & FTGMAC100_TXDES0_FTS) {
len = skb_headlen(skb);
dma_unmap_single(priv->dev, map, len, DMA_TO_DEVICE);
} else {
len = FTGMAC100_TXDES0_TXBUF_SIZE(ctl_stat);
dma_unmap_page(priv->dev, map, len, DMA_TO_DEVICE);
}
if (ctl_stat & FTGMAC100_TXDES0_LTS)
dev_kfree_skb(skb);
priv->tx_skbs[pointer] = NULL;
}
static bool ftgmac100_tx_complete_packet(struct ftgmac100 *priv)
{
struct net_device *netdev = priv->netdev;
struct ftgmac100_txdes *txdes;
struct sk_buff *skb;
unsigned int pointer;
u32 ctl_stat;
pointer = priv->tx_clean_pointer;
txdes = &priv->txdes[pointer];
ctl_stat = le32_to_cpu(txdes->txdes0);
if (ctl_stat & FTGMAC100_TXDES0_TXDMA_OWN)
return false;
skb = priv->tx_skbs[pointer];
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += skb->len;
ftgmac100_free_tx_packet(priv, pointer, skb, txdes, ctl_stat);
txdes->txdes0 = cpu_to_le32(ctl_stat & priv->txdes0_edotr_mask);
priv->tx_clean_pointer = ftgmac100_next_tx_pointer(priv, pointer);
return true;
}
static void ftgmac100_tx_complete(struct ftgmac100 *priv)
{
struct net_device *netdev = priv->netdev;
while (ftgmac100_tx_buf_cleanable(priv) &&
ftgmac100_tx_complete_packet(priv))
;
smp_mb();
if (unlikely(netif_queue_stopped(netdev) &&
ftgmac100_tx_buf_avail(priv) >= TX_THRESHOLD)) {
struct netdev_queue *txq;
txq = netdev_get_tx_queue(netdev, 0);
__netif_tx_lock(txq, smp_processor_id());
if (netif_queue_stopped(netdev) &&
ftgmac100_tx_buf_avail(priv) >= TX_THRESHOLD)
netif_wake_queue(netdev);
__netif_tx_unlock(txq);
}
}
static bool ftgmac100_prep_tx_csum(struct sk_buff *skb, u32 *csum_vlan)
{
if (skb->protocol == cpu_to_be16(ETH_P_IP)) {
u8 ip_proto = ip_hdr(skb)->protocol;
*csum_vlan |= FTGMAC100_TXDES1_IP_CHKSUM;
switch(ip_proto) {
case IPPROTO_TCP:
*csum_vlan |= FTGMAC100_TXDES1_TCP_CHKSUM;
return true;
case IPPROTO_UDP:
*csum_vlan |= FTGMAC100_TXDES1_UDP_CHKSUM;
return true;
case IPPROTO_IP:
return true;
}
}
return skb_checksum_help(skb) == 0;
}
static int ftgmac100_hard_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
struct ftgmac100_txdes *txdes, *first;
unsigned int pointer, nfrags, len, i, j;
u32 f_ctl_stat, ctl_stat, csum_vlan;
dma_addr_t map;
if (eth_skb_pad(skb)) {
netdev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
if (unlikely(skb->len > MAX_PKT_SIZE)) {
if (net_ratelimit())
netdev_dbg(netdev, "tx packet too big\n");
goto drop;
}
nfrags = skb_shinfo(skb)->nr_frags;
len = skb_headlen(skb);
map = dma_map_single(priv->dev, skb->data, len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->dev, map)) {
if (net_ratelimit())
netdev_err(netdev, "map tx packet head failed\n");
goto drop;
}
pointer = priv->tx_pointer;
txdes = first = &priv->txdes[pointer];
priv->tx_skbs[pointer] = skb;
f_ctl_stat = ftgmac100_base_tx_ctlstat(priv, pointer);
f_ctl_stat |= FTGMAC100_TXDES0_TXDMA_OWN;
f_ctl_stat |= FTGMAC100_TXDES0_TXBUF_SIZE(len);
f_ctl_stat |= FTGMAC100_TXDES0_FTS;
if (nfrags == 0)
f_ctl_stat |= FTGMAC100_TXDES0_LTS;
txdes->txdes3 = cpu_to_le32(map);
csum_vlan = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL &&
!ftgmac100_prep_tx_csum(skb, &csum_vlan))
goto drop;
if (skb_vlan_tag_present(skb)) {
csum_vlan |= FTGMAC100_TXDES1_INS_VLANTAG;
csum_vlan |= skb_vlan_tag_get(skb) & 0xffff;
}
txdes->txdes1 = cpu_to_le32(csum_vlan);
pointer = ftgmac100_next_tx_pointer(priv, pointer);
for (i = 0; i < nfrags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
len = frag->size;
map = skb_frag_dma_map(priv->dev, frag, 0, len,
DMA_TO_DEVICE);
if (dma_mapping_error(priv->dev, map))
goto dma_err;
priv->tx_skbs[pointer] = skb;
txdes = &priv->txdes[pointer];
ctl_stat = ftgmac100_base_tx_ctlstat(priv, pointer);
ctl_stat |= FTGMAC100_TXDES0_TXDMA_OWN;
ctl_stat |= FTGMAC100_TXDES0_TXBUF_SIZE(len);
if (i == (nfrags - 1))
ctl_stat |= FTGMAC100_TXDES0_LTS;
txdes->txdes0 = cpu_to_le32(ctl_stat);
txdes->txdes1 = 0;
txdes->txdes3 = cpu_to_le32(map);
pointer = ftgmac100_next_tx_pointer(priv, pointer);
}
dma_wmb();
first->txdes0 = cpu_to_le32(f_ctl_stat);
priv->tx_pointer = pointer;
if (unlikely(ftgmac100_tx_buf_avail(priv) < TX_THRESHOLD)) {
netif_stop_queue(netdev);
smp_mb();
if (ftgmac100_tx_buf_avail(priv) >= TX_THRESHOLD)
netif_wake_queue(netdev);
}
iowrite32(1, priv->base + FTGMAC100_OFFSET_NPTXPD);
return NETDEV_TX_OK;
dma_err:
if (net_ratelimit())
netdev_err(netdev, "map tx fragment failed\n");
pointer = priv->tx_pointer;
ftgmac100_free_tx_packet(priv, pointer, skb, first, f_ctl_stat);
first->txdes0 = cpu_to_le32(f_ctl_stat & priv->txdes0_edotr_mask);
for (j = 0; j < i; j++) {
pointer = ftgmac100_next_tx_pointer(priv, pointer);
txdes = &priv->txdes[pointer];
ctl_stat = le32_to_cpu(txdes->txdes0);
ftgmac100_free_tx_packet(priv, pointer, skb, txdes, ctl_stat);
txdes->txdes0 = cpu_to_le32(ctl_stat & priv->txdes0_edotr_mask);
}
drop:
dev_kfree_skb_any(skb);
netdev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static void ftgmac100_free_buffers(struct ftgmac100 *priv)
{
int i;
for (i = 0; i < priv->rx_q_entries; i++) {
struct ftgmac100_rxdes *rxdes = &priv->rxdes[i];
struct sk_buff *skb = priv->rx_skbs[i];
dma_addr_t map = le32_to_cpu(rxdes->rxdes3);
if (!skb)
continue;
priv->rx_skbs[i] = NULL;
dma_unmap_single(priv->dev, map, RX_BUF_SIZE, DMA_FROM_DEVICE);
dev_kfree_skb_any(skb);
}
for (i = 0; i < priv->tx_q_entries; i++) {
struct ftgmac100_txdes *txdes = &priv->txdes[i];
struct sk_buff *skb = priv->tx_skbs[i];
if (!skb)
continue;
ftgmac100_free_tx_packet(priv, i, skb, txdes,
le32_to_cpu(txdes->txdes0));
}
}
static void ftgmac100_free_rings(struct ftgmac100 *priv)
{
kfree(priv->rx_skbs);
kfree(priv->tx_skbs);
if (priv->rxdes)
dma_free_coherent(priv->dev, MAX_RX_QUEUE_ENTRIES *
sizeof(struct ftgmac100_rxdes),
priv->rxdes, priv->rxdes_dma);
priv->rxdes = NULL;
if (priv->txdes)
dma_free_coherent(priv->dev, MAX_TX_QUEUE_ENTRIES *
sizeof(struct ftgmac100_txdes),
priv->txdes, priv->txdes_dma);
priv->txdes = NULL;
if (priv->rx_scratch)
dma_free_coherent(priv->dev, RX_BUF_SIZE,
priv->rx_scratch, priv->rx_scratch_dma);
}
static int ftgmac100_alloc_rings(struct ftgmac100 *priv)
{
priv->rx_skbs = kcalloc(MAX_RX_QUEUE_ENTRIES, sizeof(void *),
GFP_KERNEL);
if (!priv->rx_skbs)
return -ENOMEM;
priv->tx_skbs = kcalloc(MAX_TX_QUEUE_ENTRIES, sizeof(void *),
GFP_KERNEL);
if (!priv->tx_skbs)
return -ENOMEM;
priv->rxdes = dma_zalloc_coherent(priv->dev,
MAX_RX_QUEUE_ENTRIES *
sizeof(struct ftgmac100_rxdes),
&priv->rxdes_dma, GFP_KERNEL);
if (!priv->rxdes)
return -ENOMEM;
priv->txdes = dma_zalloc_coherent(priv->dev,
MAX_TX_QUEUE_ENTRIES *
sizeof(struct ftgmac100_txdes),
&priv->txdes_dma, GFP_KERNEL);
if (!priv->txdes)
return -ENOMEM;
priv->rx_scratch = dma_alloc_coherent(priv->dev,
RX_BUF_SIZE,
&priv->rx_scratch_dma,
GFP_KERNEL);
if (!priv->rx_scratch)
return -ENOMEM;
return 0;
}
static void ftgmac100_init_rings(struct ftgmac100 *priv)
{
struct ftgmac100_rxdes *rxdes = NULL;
struct ftgmac100_txdes *txdes = NULL;
int i;
priv->rx_q_entries = priv->new_rx_q_entries;
priv->tx_q_entries = priv->new_tx_q_entries;
if (WARN_ON(priv->rx_q_entries < MIN_RX_QUEUE_ENTRIES))
return;
for (i = 0; i < priv->rx_q_entries; i++) {
rxdes = &priv->rxdes[i];
rxdes->rxdes0 = 0;
rxdes->rxdes3 = cpu_to_le32(priv->rx_scratch_dma);
}
rxdes->rxdes0 |= cpu_to_le32(priv->rxdes0_edorr_mask);
if (WARN_ON(priv->tx_q_entries < MIN_RX_QUEUE_ENTRIES))
return;
for (i = 0; i < priv->tx_q_entries; i++) {
txdes = &priv->txdes[i];
txdes->txdes0 = 0;
}
txdes->txdes0 |= cpu_to_le32(priv->txdes0_edotr_mask);
}
static int ftgmac100_alloc_rx_buffers(struct ftgmac100 *priv)
{
int i;
for (i = 0; i < priv->rx_q_entries; i++) {
struct ftgmac100_rxdes *rxdes = &priv->rxdes[i];
if (ftgmac100_alloc_rx_buf(priv, i, rxdes, GFP_KERNEL))
return -ENOMEM;
}
return 0;
}
static void ftgmac100_adjust_link(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
struct phy_device *phydev = netdev->phydev;
bool tx_pause, rx_pause;
int new_speed;
if (!phydev->link)
new_speed = 0;
else
new_speed = phydev->speed;
if (priv->aneg_pause) {
rx_pause = tx_pause = phydev->pause;
if (phydev->asym_pause)
tx_pause = !rx_pause;
} else {
rx_pause = priv->rx_pause;
tx_pause = priv->tx_pause;
}
if (phydev->speed == priv->cur_speed &&
phydev->duplex == priv->cur_duplex &&
rx_pause == priv->rx_pause &&
tx_pause == priv->tx_pause)
return;
if (new_speed || priv->cur_speed)
phy_print_status(phydev);
priv->cur_speed = new_speed;
priv->cur_duplex = phydev->duplex;
priv->rx_pause = rx_pause;
priv->tx_pause = tx_pause;
if (!new_speed)
return;
iowrite32(0, priv->base + FTGMAC100_OFFSET_IER);
schedule_work(&priv->reset_task);
}
static int ftgmac100_mii_probe(struct ftgmac100 *priv, phy_interface_t intf)
{
struct net_device *netdev = priv->netdev;
struct phy_device *phydev;
phydev = phy_find_first(priv->mii_bus);
if (!phydev) {
netdev_info(netdev, "%s: no PHY found\n", netdev->name);
return -ENODEV;
}
phydev = phy_connect(netdev, phydev_name(phydev),
&ftgmac100_adjust_link, intf);
if (IS_ERR(phydev)) {
netdev_err(netdev, "%s: Could not attach to PHY\n", netdev->name);
return PTR_ERR(phydev);
}
phydev->supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
phydev->advertising = phydev->supported;
phy_attached_info(phydev);
return 0;
}
static int ftgmac100_mdiobus_read(struct mii_bus *bus, int phy_addr, int regnum)
{
struct net_device *netdev = bus->priv;
struct ftgmac100 *priv = netdev_priv(netdev);
unsigned int phycr;
int i;
phycr = ioread32(priv->base + FTGMAC100_OFFSET_PHYCR);
phycr &= FTGMAC100_PHYCR_MDC_CYCTHR_MASK;
phycr |= FTGMAC100_PHYCR_PHYAD(phy_addr) |
FTGMAC100_PHYCR_REGAD(regnum) |
FTGMAC100_PHYCR_MIIRD;
iowrite32(phycr, priv->base + FTGMAC100_OFFSET_PHYCR);
for (i = 0; i < 10; i++) {
phycr = ioread32(priv->base + FTGMAC100_OFFSET_PHYCR);
if ((phycr & FTGMAC100_PHYCR_MIIRD) == 0) {
int data;
data = ioread32(priv->base + FTGMAC100_OFFSET_PHYDATA);
return FTGMAC100_PHYDATA_MIIRDATA(data);
}
udelay(100);
}
netdev_err(netdev, "mdio read timed out\n");
return -EIO;
}
static int ftgmac100_mdiobus_write(struct mii_bus *bus, int phy_addr,
int regnum, u16 value)
{
struct net_device *netdev = bus->priv;
struct ftgmac100 *priv = netdev_priv(netdev);
unsigned int phycr;
int data;
int i;
phycr = ioread32(priv->base + FTGMAC100_OFFSET_PHYCR);
phycr &= FTGMAC100_PHYCR_MDC_CYCTHR_MASK;
phycr |= FTGMAC100_PHYCR_PHYAD(phy_addr) |
FTGMAC100_PHYCR_REGAD(regnum) |
FTGMAC100_PHYCR_MIIWR;
data = FTGMAC100_PHYDATA_MIIWDATA(value);
iowrite32(data, priv->base + FTGMAC100_OFFSET_PHYDATA);
iowrite32(phycr, priv->base + FTGMAC100_OFFSET_PHYCR);
for (i = 0; i < 10; i++) {
phycr = ioread32(priv->base + FTGMAC100_OFFSET_PHYCR);
if ((phycr & FTGMAC100_PHYCR_MIIWR) == 0)
return 0;
udelay(100);
}
netdev_err(netdev, "mdio write timed out\n");
return -EIO;
}
static void ftgmac100_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, dev_name(&netdev->dev), sizeof(info->bus_info));
}
static void ftgmac100_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ering)
{
struct ftgmac100 *priv = netdev_priv(netdev);
memset(ering, 0, sizeof(*ering));
ering->rx_max_pending = MAX_RX_QUEUE_ENTRIES;
ering->tx_max_pending = MAX_TX_QUEUE_ENTRIES;
ering->rx_pending = priv->rx_q_entries;
ering->tx_pending = priv->tx_q_entries;
}
static int ftgmac100_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ering)
{
struct ftgmac100 *priv = netdev_priv(netdev);
if (ering->rx_pending > MAX_RX_QUEUE_ENTRIES ||
ering->tx_pending > MAX_TX_QUEUE_ENTRIES ||
ering->rx_pending < MIN_RX_QUEUE_ENTRIES ||
ering->tx_pending < MIN_TX_QUEUE_ENTRIES ||
!is_power_of_2(ering->rx_pending) ||
!is_power_of_2(ering->tx_pending))
return -EINVAL;
priv->new_rx_q_entries = ering->rx_pending;
priv->new_tx_q_entries = ering->tx_pending;
if (netif_running(netdev))
schedule_work(&priv->reset_task);
return 0;
}
static void ftgmac100_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ftgmac100 *priv = netdev_priv(netdev);
pause->autoneg = priv->aneg_pause;
pause->tx_pause = priv->tx_pause;
pause->rx_pause = priv->rx_pause;
}
static int ftgmac100_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ftgmac100 *priv = netdev_priv(netdev);
struct phy_device *phydev = netdev->phydev;
priv->aneg_pause = pause->autoneg;
priv->tx_pause = pause->tx_pause;
priv->rx_pause = pause->rx_pause;
if (phydev) {
phydev->advertising &= ~ADVERTISED_Pause;
phydev->advertising &= ~ADVERTISED_Asym_Pause;
if (pause->rx_pause) {
phydev->advertising |= ADVERTISED_Pause;
phydev->advertising |= ADVERTISED_Asym_Pause;
}
if (pause->tx_pause)
phydev->advertising ^= ADVERTISED_Asym_Pause;
}
if (netif_running(netdev)) {
if (phydev && priv->aneg_pause)
phy_start_aneg(phydev);
else
ftgmac100_config_pause(priv);
}
return 0;
}
static irqreturn_t ftgmac100_interrupt(int irq, void *dev_id)
{
struct net_device *netdev = dev_id;
struct ftgmac100 *priv = netdev_priv(netdev);
unsigned int status, new_mask = FTGMAC100_INT_BAD;
status = ioread32(priv->base + FTGMAC100_OFFSET_ISR);
iowrite32(status, priv->base + FTGMAC100_OFFSET_ISR);
if (unlikely(status & FTGMAC100_INT_BAD)) {
if (status & FTGMAC100_INT_NO_RXBUF)
netdev->stats.rx_over_errors++;
if (status & FTGMAC100_INT_RPKT_LOST)
netdev->stats.rx_fifo_errors++;
if (status & FTGMAC100_INT_XPKT_LOST)
netdev->stats.tx_fifo_errors++;
if (status & FTGMAC100_INT_AHB_ERR) {
if (net_ratelimit())
netdev_warn(netdev,
"AHB bus error ! Resetting chip.\n");
iowrite32(0, priv->base + FTGMAC100_OFFSET_IER);
schedule_work(&priv->reset_task);
return IRQ_HANDLED;
}
priv->need_mac_restart = true;
new_mask &= ~status;
}
iowrite32(new_mask, priv->base + FTGMAC100_OFFSET_IER);
napi_schedule_irqoff(&priv->napi);
return IRQ_HANDLED;
}
static bool ftgmac100_check_rx(struct ftgmac100 *priv)
{
struct ftgmac100_rxdes *rxdes = &priv->rxdes[priv->rx_pointer];
return !!(rxdes->rxdes0 & cpu_to_le32(FTGMAC100_RXDES0_RXPKT_RDY));
}
static int ftgmac100_poll(struct napi_struct *napi, int budget)
{
struct ftgmac100 *priv = container_of(napi, struct ftgmac100, napi);
int work_done = 0;
bool more;
if (ftgmac100_tx_buf_cleanable(priv))
ftgmac100_tx_complete(priv);
do {
more = ftgmac100_rx_packet(priv, &work_done);
} while (more && work_done < budget);
if (unlikely(priv->need_mac_restart)) {
ftgmac100_start_hw(priv);
iowrite32(FTGMAC100_INT_BAD,
priv->base + FTGMAC100_OFFSET_IER);
}
if (ftgmac100_tx_buf_cleanable(priv))
work_done = budget;
if (work_done < budget) {
iowrite32(FTGMAC100_INT_RXTX,
priv->base + FTGMAC100_OFFSET_ISR);
ioread32(priv->base + FTGMAC100_OFFSET_ISR);
if (ftgmac100_check_rx(priv) ||
ftgmac100_tx_buf_cleanable(priv))
return budget;
napi_complete(napi);
iowrite32(FTGMAC100_INT_ALL,
priv->base + FTGMAC100_OFFSET_IER);
}
return work_done;
}
static int ftgmac100_init_all(struct ftgmac100 *priv, bool ignore_alloc_err)
{
int err = 0;
ftgmac100_init_rings(priv);
err = ftgmac100_alloc_rx_buffers(priv);
if (err && !ignore_alloc_err)
return err;
ftgmac100_init_hw(priv);
ftgmac100_config_pause(priv);
ftgmac100_start_hw(priv);
napi_enable(&priv->napi);
netif_start_queue(priv->netdev);
iowrite32(FTGMAC100_INT_ALL, priv->base + FTGMAC100_OFFSET_IER);
return err;
}
static void ftgmac100_reset_task(struct work_struct *work)
{
struct ftgmac100 *priv = container_of(work, struct ftgmac100,
reset_task);
struct net_device *netdev = priv->netdev;
int err;
netdev_dbg(netdev, "Resetting NIC...\n");
rtnl_lock();
if (netdev->phydev)
mutex_lock(&netdev->phydev->lock);
if (priv->mii_bus)
mutex_lock(&priv->mii_bus->mdio_lock);
if (!netif_running(netdev))
goto bail;
netif_trans_update(netdev);
napi_disable(&priv->napi);
netif_tx_disable(netdev);
ftgmac100_stop_hw(priv);
err = ftgmac100_reset_and_config_mac(priv);
if (err) {
netdev_err(netdev, "attempting to continue...\n");
}
ftgmac100_free_buffers(priv);
ftgmac100_init_all(priv, true);
netdev_dbg(netdev, "Reset done !\n");
bail:
if (priv->mii_bus)
mutex_unlock(&priv->mii_bus->mdio_lock);
if (netdev->phydev)
mutex_unlock(&netdev->phydev->lock);
rtnl_unlock();
}
static int ftgmac100_open(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
int err;
err = ftgmac100_alloc_rings(priv);
if (err) {
netdev_err(netdev, "Failed to allocate descriptors\n");
return err;
}
if (priv->use_ncsi) {
priv->cur_duplex = DUPLEX_FULL;
priv->cur_speed = SPEED_100;
} else {
priv->cur_duplex = 0;
priv->cur_speed = 0;
}
err = ftgmac100_reset_and_config_mac(priv);
if (err)
goto err_hw;
netif_napi_add(netdev, &priv->napi, ftgmac100_poll, 64);
err = request_irq(netdev->irq, ftgmac100_interrupt, 0, netdev->name, netdev);
if (err) {
netdev_err(netdev, "failed to request irq %d\n", netdev->irq);
goto err_irq;
}
err = ftgmac100_init_all(priv, false);
if (err) {
netdev_err(netdev, "Failed to allocate packet buffers\n");
goto err_alloc;
}
if (netdev->phydev) {
phy_start(netdev->phydev);
} else if (priv->use_ncsi) {
netif_carrier_on(netdev);
err = ncsi_start_dev(priv->ndev);
if (err)
goto err_ncsi;
}
return 0;
err_ncsi:
napi_disable(&priv->napi);
netif_stop_queue(netdev);
err_alloc:
ftgmac100_free_buffers(priv);
free_irq(netdev->irq, netdev);
err_irq:
netif_napi_del(&priv->napi);
err_hw:
iowrite32(0, priv->base + FTGMAC100_OFFSET_IER);
ftgmac100_free_rings(priv);
return err;
}
static int ftgmac100_stop(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
iowrite32(0, priv->base + FTGMAC100_OFFSET_IER);
netif_stop_queue(netdev);
napi_disable(&priv->napi);
netif_napi_del(&priv->napi);
if (netdev->phydev)
phy_stop(netdev->phydev);
else if (priv->use_ncsi)
ncsi_stop_dev(priv->ndev);
ftgmac100_stop_hw(priv);
free_irq(netdev->irq, netdev);
ftgmac100_free_buffers(priv);
ftgmac100_free_rings(priv);
return 0;
}
static int ftgmac100_do_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
if (!netdev->phydev)
return -ENXIO;
return phy_mii_ioctl(netdev->phydev, ifr, cmd);
}
static void ftgmac100_tx_timeout(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
iowrite32(0, priv->base + FTGMAC100_OFFSET_IER);
schedule_work(&priv->reset_task);
}
static int ftgmac100_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct ftgmac100 *priv = netdev_priv(netdev);
netdev_features_t changed = netdev->features ^ features;
if (!netif_running(netdev))
return 0;
if (changed & NETIF_F_HW_VLAN_CTAG_RX) {
u32 maccr;
maccr = ioread32(priv->base + FTGMAC100_OFFSET_MACCR);
if (priv->netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
maccr |= FTGMAC100_MACCR_RM_VLAN;
else
maccr &= ~FTGMAC100_MACCR_RM_VLAN;
iowrite32(maccr, priv->base + FTGMAC100_OFFSET_MACCR);
}
return 0;
}
static void ftgmac100_poll_controller(struct net_device *netdev)
{
unsigned long flags;
local_irq_save(flags);
ftgmac100_interrupt(netdev->irq, netdev);
local_irq_restore(flags);
}
static int ftgmac100_setup_mdio(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
struct platform_device *pdev = to_platform_device(priv->dev);
int phy_intf = PHY_INTERFACE_MODE_RGMII;
struct device_node *np = pdev->dev.of_node;
int i, err = 0;
u32 reg;
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus)
return -EIO;
if (priv->is_aspeed) {
reg = ioread32(priv->base + FTGMAC100_OFFSET_REVR);
reg &= ~FTGMAC100_REVR_NEW_MDIO_INTERFACE;
iowrite32(reg, priv->base + FTGMAC100_OFFSET_REVR);
};
if (np) {
phy_intf = of_get_phy_mode(np);
if (phy_intf < 0)
phy_intf = PHY_INTERFACE_MODE_RGMII;
if (priv->is_aspeed &&
phy_intf != PHY_INTERFACE_MODE_RMII &&
phy_intf != PHY_INTERFACE_MODE_RGMII &&
phy_intf != PHY_INTERFACE_MODE_RGMII_ID &&
phy_intf != PHY_INTERFACE_MODE_RGMII_RXID &&
phy_intf != PHY_INTERFACE_MODE_RGMII_TXID) {
netdev_warn(netdev,
"Unsupported PHY mode %s !\n",
phy_modes(phy_intf));
}
}
priv->mii_bus->name = "ftgmac100_mdio";
snprintf(priv->mii_bus->id, MII_BUS_ID_SIZE, "%s-%d",
pdev->name, pdev->id);
priv->mii_bus->parent = priv->dev;
priv->mii_bus->priv = priv->netdev;
priv->mii_bus->read = ftgmac100_mdiobus_read;
priv->mii_bus->write = ftgmac100_mdiobus_write;
for (i = 0; i < PHY_MAX_ADDR; i++)
priv->mii_bus->irq[i] = PHY_POLL;
err = mdiobus_register(priv->mii_bus);
if (err) {
dev_err(priv->dev, "Cannot register MDIO bus!\n");
goto err_register_mdiobus;
}
err = ftgmac100_mii_probe(priv, phy_intf);
if (err) {
dev_err(priv->dev, "MII Probe failed!\n");
goto err_mii_probe;
}
return 0;
err_mii_probe:
mdiobus_unregister(priv->mii_bus);
err_register_mdiobus:
mdiobus_free(priv->mii_bus);
return err;
}
static void ftgmac100_destroy_mdio(struct net_device *netdev)
{
struct ftgmac100 *priv = netdev_priv(netdev);
if (!netdev->phydev)
return;
phy_disconnect(netdev->phydev);
mdiobus_unregister(priv->mii_bus);
mdiobus_free(priv->mii_bus);
}
static void ftgmac100_ncsi_handler(struct ncsi_dev *nd)
{
if (unlikely(nd->state != ncsi_dev_state_functional))
return;
netdev_info(nd->dev, "NCSI interface %s\n",
nd->link_up ? "up" : "down");
}
static int ftgmac100_probe(struct platform_device *pdev)
{
struct resource *res;
int irq;
struct net_device *netdev;
struct ftgmac100 *priv;
struct device_node *np;
int err = 0;
if (!pdev)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
netdev = alloc_etherdev(sizeof(*priv));
if (!netdev) {
err = -ENOMEM;
goto err_alloc_etherdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
netdev->ethtool_ops = &ftgmac100_ethtool_ops;
netdev->netdev_ops = &ftgmac100_netdev_ops;
netdev->watchdog_timeo = 5 * HZ;
platform_set_drvdata(pdev, netdev);
priv = netdev_priv(netdev);
priv->netdev = netdev;
priv->dev = &pdev->dev;
INIT_WORK(&priv->reset_task, ftgmac100_reset_task);
priv->res = request_mem_region(res->start, resource_size(res),
dev_name(&pdev->dev));
if (!priv->res) {
dev_err(&pdev->dev, "Could not reserve memory region\n");
err = -ENOMEM;
goto err_req_mem;
}
priv->base = ioremap(res->start, resource_size(res));
if (!priv->base) {
dev_err(&pdev->dev, "Failed to ioremap ethernet registers\n");
err = -EIO;
goto err_ioremap;
}
netdev->irq = irq;
priv->tx_pause = true;
priv->rx_pause = true;
priv->aneg_pause = true;
ftgmac100_initial_mac(priv);
np = pdev->dev.of_node;
if (np && (of_device_is_compatible(np, "aspeed,ast2400-mac") ||
of_device_is_compatible(np, "aspeed,ast2500-mac"))) {
priv->rxdes0_edorr_mask = BIT(30);
priv->txdes0_edotr_mask = BIT(30);
priv->is_aspeed = true;
} else {
priv->rxdes0_edorr_mask = BIT(15);
priv->txdes0_edotr_mask = BIT(15);
}
if (np && of_get_property(np, "use-ncsi", NULL)) {
if (!IS_ENABLED(CONFIG_NET_NCSI)) {
dev_err(&pdev->dev, "NCSI stack not enabled\n");
goto err_ncsi_dev;
}
dev_info(&pdev->dev, "Using NCSI interface\n");
priv->use_ncsi = true;
priv->ndev = ncsi_register_dev(netdev, ftgmac100_ncsi_handler);
if (!priv->ndev)
goto err_ncsi_dev;
} else {
priv->use_ncsi = false;
err = ftgmac100_setup_mdio(netdev);
if (err)
goto err_setup_mdio;
}
priv->rx_q_entries = priv->new_rx_q_entries = DEF_RX_QUEUE_ENTRIES;
priv->tx_q_entries = priv->new_tx_q_entries = DEF_TX_QUEUE_ENTRIES;
netdev->hw_features = NETIF_F_RXCSUM | NETIF_F_HW_CSUM |
NETIF_F_GRO | NETIF_F_SG | NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
if (np && (of_device_is_compatible(np, "aspeed,ast2400-mac")))
netdev->hw_features &= ~NETIF_F_HW_CSUM;
if (np && of_get_property(np, "no-hw-checksum", NULL))
netdev->hw_features &= ~(NETIF_F_HW_CSUM | NETIF_F_RXCSUM);
netdev->features |= netdev->hw_features;
err = register_netdev(netdev);
if (err) {
dev_err(&pdev->dev, "Failed to register netdev\n");
goto err_register_netdev;
}
netdev_info(netdev, "irq %d, mapped at %p\n", netdev->irq, priv->base);
return 0;
err_ncsi_dev:
err_register_netdev:
ftgmac100_destroy_mdio(netdev);
err_setup_mdio:
iounmap(priv->base);
err_ioremap:
release_resource(priv->res);
err_req_mem:
free_netdev(netdev);
err_alloc_etherdev:
return err;
}
static int ftgmac100_remove(struct platform_device *pdev)
{
struct net_device *netdev;
struct ftgmac100 *priv;
netdev = platform_get_drvdata(pdev);
priv = netdev_priv(netdev);
unregister_netdev(netdev);
cancel_work_sync(&priv->reset_task);
ftgmac100_destroy_mdio(netdev);
iounmap(priv->base);
release_resource(priv->res);
netif_napi_del(&priv->napi);
free_netdev(netdev);
return 0;
}
