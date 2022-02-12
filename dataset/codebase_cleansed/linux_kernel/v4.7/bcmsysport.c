static inline void dma_desc_set_addr(struct bcm_sysport_priv *priv,
void __iomem *d,
dma_addr_t addr)
{
#ifdef CONFIG_PHYS_ADDR_T_64BIT
__raw_writel(upper_32_bits(addr) & DESC_ADDR_HI_MASK,
d + DESC_ADDR_HI_STATUS_LEN);
#endif
__raw_writel(lower_32_bits(addr), d + DESC_ADDR_LO);
}
static inline void tdma_port_write_desc_addr(struct bcm_sysport_priv *priv,
struct dma_desc *desc,
unsigned int port)
{
tdma_writel(priv, desc->addr_status_len, TDMA_WRITE_PORT_HI(port));
tdma_writel(priv, desc->addr_lo, TDMA_WRITE_PORT_LO(port));
}
static int bcm_sysport_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
return phy_ethtool_sset(priv->phydev, cmd);
}
static int bcm_sysport_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
return phy_ethtool_gset(priv->phydev, cmd);
}
static int bcm_sysport_set_rx_csum(struct net_device *dev,
netdev_features_t wanted)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
u32 reg;
priv->rx_chk_en = !!(wanted & NETIF_F_RXCSUM);
reg = rxchk_readl(priv, RXCHK_CONTROL);
if (priv->rx_chk_en)
reg |= RXCHK_EN;
else
reg &= ~RXCHK_EN;
if (priv->rx_chk_en && priv->crc_fwd)
reg |= RXCHK_SKIP_FCS;
else
reg &= ~RXCHK_SKIP_FCS;
if (netdev_uses_dsa(dev))
reg |= RXCHK_BRCM_TAG_EN;
else
reg &= ~RXCHK_BRCM_TAG_EN;
rxchk_writel(priv, reg, RXCHK_CONTROL);
return 0;
}
static int bcm_sysport_set_tx_csum(struct net_device *dev,
netdev_features_t wanted)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
u32 reg;
priv->tsb_en = !!(wanted & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM));
reg = tdma_readl(priv, TDMA_CONTROL);
if (priv->tsb_en)
reg |= TSB_EN;
else
reg &= ~TSB_EN;
tdma_writel(priv, reg, TDMA_CONTROL);
return 0;
}
static int bcm_sysport_set_features(struct net_device *dev,
netdev_features_t features)
{
netdev_features_t changed = features ^ dev->features;
netdev_features_t wanted = dev->wanted_features;
int ret = 0;
if (changed & NETIF_F_RXCSUM)
ret = bcm_sysport_set_rx_csum(dev, wanted);
if (changed & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM))
ret = bcm_sysport_set_tx_csum(dev, wanted);
return ret;
}
static void bcm_sysport_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->version, "0.1", sizeof(info->version));
strlcpy(info->bus_info, "platform", sizeof(info->bus_info));
}
static u32 bcm_sysport_get_msglvl(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
return priv->msg_enable;
}
static void bcm_sysport_set_msglvl(struct net_device *dev, u32 enable)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
priv->msg_enable = enable;
}
static int bcm_sysport_get_sset_count(struct net_device *dev, int string_set)
{
switch (string_set) {
case ETH_SS_STATS:
return BCM_SYSPORT_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void bcm_sysport_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < BCM_SYSPORT_STATS_LEN; i++) {
memcpy(data + i * ETH_GSTRING_LEN,
bcm_sysport_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
}
break;
default:
break;
}
}
static void bcm_sysport_update_mib_counters(struct bcm_sysport_priv *priv)
{
int i, j = 0;
for (i = 0; i < BCM_SYSPORT_STATS_LEN; i++) {
const struct bcm_sysport_stats *s;
u8 offset = 0;
u32 val = 0;
char *p;
s = &bcm_sysport_gstrings_stats[i];
switch (s->type) {
case BCM_SYSPORT_STAT_NETDEV:
case BCM_SYSPORT_STAT_SOFT:
continue;
case BCM_SYSPORT_STAT_MIB_RX:
case BCM_SYSPORT_STAT_MIB_TX:
case BCM_SYSPORT_STAT_RUNT:
if (s->type != BCM_SYSPORT_STAT_MIB_RX)
offset = UMAC_MIB_STAT_OFFSET;
val = umac_readl(priv, UMAC_MIB_START + j + offset);
break;
case BCM_SYSPORT_STAT_RXCHK:
val = rxchk_readl(priv, s->reg_offset);
if (val == ~0)
rxchk_writel(priv, 0, s->reg_offset);
break;
case BCM_SYSPORT_STAT_RBUF:
val = rbuf_readl(priv, s->reg_offset);
if (val == ~0)
rbuf_writel(priv, 0, s->reg_offset);
break;
}
j += s->stat_sizeof;
p = (char *)priv + s->stat_offset;
*(u32 *)p = val;
}
netif_dbg(priv, hw, priv->netdev, "updated MIB counters\n");
}
static void bcm_sysport_get_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
int i;
if (netif_running(dev))
bcm_sysport_update_mib_counters(priv);
for (i = 0; i < BCM_SYSPORT_STATS_LEN; i++) {
const struct bcm_sysport_stats *s;
char *p;
s = &bcm_sysport_gstrings_stats[i];
if (s->type == BCM_SYSPORT_STAT_NETDEV)
p = (char *)&dev->stats;
else
p = (char *)priv;
p += s->stat_offset;
data[i] = *(unsigned long *)p;
}
}
static void bcm_sysport_get_wol(struct net_device *dev,
struct ethtool_wolinfo *wol)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
u32 reg;
wol->supported = WAKE_MAGIC | WAKE_MAGICSECURE;
wol->wolopts = priv->wolopts;
if (!(priv->wolopts & WAKE_MAGICSECURE))
return;
reg = umac_readl(priv, UMAC_PSW_MS);
put_unaligned_be16(reg, &wol->sopass[0]);
reg = umac_readl(priv, UMAC_PSW_LS);
put_unaligned_be32(reg, &wol->sopass[2]);
}
static int bcm_sysport_set_wol(struct net_device *dev,
struct ethtool_wolinfo *wol)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
u32 supported = WAKE_MAGIC | WAKE_MAGICSECURE;
if (!device_can_wakeup(kdev))
return -ENOTSUPP;
if (wol->wolopts & ~supported)
return -EINVAL;
if (wol->wolopts & WAKE_MAGICSECURE) {
umac_writel(priv, get_unaligned_be16(&wol->sopass[0]),
UMAC_PSW_MS);
umac_writel(priv, get_unaligned_be32(&wol->sopass[2]),
UMAC_PSW_LS);
}
if (wol->wolopts) {
device_set_wakeup_enable(kdev, 1);
if (priv->wol_irq_disabled)
enable_irq_wake(priv->wol_irq);
priv->wol_irq_disabled = 0;
} else {
device_set_wakeup_enable(kdev, 0);
if (!priv->wol_irq_disabled)
disable_irq_wake(priv->wol_irq);
priv->wol_irq_disabled = 1;
}
priv->wolopts = wol->wolopts;
return 0;
}
static int bcm_sysport_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
u32 reg;
reg = tdma_readl(priv, TDMA_DESC_RING_INTR_CONTROL(0));
ec->tx_coalesce_usecs = (reg >> RING_TIMEOUT_SHIFT) * 8192 / 1000;
ec->tx_max_coalesced_frames = reg & RING_INTR_THRESH_MASK;
reg = rdma_readl(priv, RDMA_MBDONE_INTR);
ec->rx_coalesce_usecs = (reg >> RDMA_TIMEOUT_SHIFT) * 8192 / 1000;
ec->rx_max_coalesced_frames = reg & RDMA_INTR_THRESH_MASK;
return 0;
}
static int bcm_sysport_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
unsigned int i;
u32 reg;
if (ec->tx_max_coalesced_frames > RING_INTR_THRESH_MASK ||
ec->tx_coalesce_usecs > (RING_TIMEOUT_MASK * 8) + 1 ||
ec->rx_max_coalesced_frames > RDMA_INTR_THRESH_MASK ||
ec->rx_coalesce_usecs > (RDMA_TIMEOUT_MASK * 8) + 1)
return -EINVAL;
if ((ec->tx_coalesce_usecs == 0 && ec->tx_max_coalesced_frames == 0) ||
(ec->rx_coalesce_usecs == 0 && ec->rx_max_coalesced_frames == 0))
return -EINVAL;
for (i = 0; i < dev->num_tx_queues; i++) {
reg = tdma_readl(priv, TDMA_DESC_RING_INTR_CONTROL(i));
reg &= ~(RING_INTR_THRESH_MASK |
RING_TIMEOUT_MASK << RING_TIMEOUT_SHIFT);
reg |= ec->tx_max_coalesced_frames;
reg |= DIV_ROUND_UP(ec->tx_coalesce_usecs * 1000, 8192) <<
RING_TIMEOUT_SHIFT;
tdma_writel(priv, reg, TDMA_DESC_RING_INTR_CONTROL(i));
}
reg = rdma_readl(priv, RDMA_MBDONE_INTR);
reg &= ~(RDMA_INTR_THRESH_MASK |
RDMA_TIMEOUT_MASK << RDMA_TIMEOUT_SHIFT);
reg |= ec->rx_max_coalesced_frames;
reg |= DIV_ROUND_UP(ec->rx_coalesce_usecs * 1000, 8192) <<
RDMA_TIMEOUT_SHIFT;
rdma_writel(priv, reg, RDMA_MBDONE_INTR);
return 0;
}
static void bcm_sysport_free_cb(struct bcm_sysport_cb *cb)
{
dev_kfree_skb_any(cb->skb);
cb->skb = NULL;
dma_unmap_addr_set(cb, dma_addr, 0);
}
static struct sk_buff *bcm_sysport_rx_refill(struct bcm_sysport_priv *priv,
struct bcm_sysport_cb *cb)
{
struct device *kdev = &priv->pdev->dev;
struct net_device *ndev = priv->netdev;
struct sk_buff *skb, *rx_skb;
dma_addr_t mapping;
skb = netdev_alloc_skb(priv->netdev, RX_BUF_LENGTH);
if (!skb) {
priv->mib.alloc_rx_buff_failed++;
netif_err(priv, rx_err, ndev, "SKB alloc failed\n");
return NULL;
}
mapping = dma_map_single(kdev, skb->data,
RX_BUF_LENGTH, DMA_FROM_DEVICE);
if (dma_mapping_error(kdev, mapping)) {
priv->mib.rx_dma_failed++;
dev_kfree_skb_any(skb);
netif_err(priv, rx_err, ndev, "DMA mapping failure\n");
return NULL;
}
rx_skb = cb->skb;
if (likely(rx_skb))
dma_unmap_single(kdev, dma_unmap_addr(cb, dma_addr),
RX_BUF_LENGTH, DMA_FROM_DEVICE);
cb->skb = skb;
dma_unmap_addr_set(cb, dma_addr, mapping);
dma_desc_set_addr(priv, cb->bd_addr, mapping);
netif_dbg(priv, rx_status, ndev, "RX refill\n");
return rx_skb;
}
static int bcm_sysport_alloc_rx_bufs(struct bcm_sysport_priv *priv)
{
struct bcm_sysport_cb *cb;
struct sk_buff *skb;
unsigned int i;
for (i = 0; i < priv->num_rx_bds; i++) {
cb = &priv->rx_cbs[i];
skb = bcm_sysport_rx_refill(priv, cb);
if (skb)
dev_kfree_skb(skb);
if (!cb->skb)
return -ENOMEM;
}
return 0;
}
static unsigned int bcm_sysport_desc_rx(struct bcm_sysport_priv *priv,
unsigned int budget)
{
struct net_device *ndev = priv->netdev;
unsigned int processed = 0, to_process;
struct bcm_sysport_cb *cb;
struct sk_buff *skb;
unsigned int p_index;
u16 len, status;
struct bcm_rsb *rsb;
p_index = rdma_readl(priv, RDMA_PROD_INDEX);
p_index &= RDMA_PROD_INDEX_MASK;
if (p_index < priv->rx_c_index)
to_process = (RDMA_CONS_INDEX_MASK + 1) -
priv->rx_c_index + p_index;
else
to_process = p_index - priv->rx_c_index;
netif_dbg(priv, rx_status, ndev,
"p_index=%d rx_c_index=%d to_process=%d\n",
p_index, priv->rx_c_index, to_process);
while ((processed < to_process) && (processed < budget)) {
cb = &priv->rx_cbs[priv->rx_read_ptr];
skb = bcm_sysport_rx_refill(priv, cb);
if (unlikely(!skb)) {
netif_err(priv, rx_err, ndev, "out of memory!\n");
ndev->stats.rx_dropped++;
ndev->stats.rx_errors++;
goto next;
}
rsb = (struct bcm_rsb *)skb->data;
len = (rsb->rx_status_len >> DESC_LEN_SHIFT) & DESC_LEN_MASK;
status = (rsb->rx_status_len >> DESC_STATUS_SHIFT) &
DESC_STATUS_MASK;
netif_dbg(priv, rx_status, ndev,
"p=%d, c=%d, rd_ptr=%d, len=%d, flag=0x%04x\n",
p_index, priv->rx_c_index, priv->rx_read_ptr,
len, status);
if (unlikely(len > RX_BUF_LENGTH)) {
netif_err(priv, rx_status, ndev, "oversized packet\n");
ndev->stats.rx_length_errors++;
ndev->stats.rx_errors++;
dev_kfree_skb_any(skb);
goto next;
}
if (unlikely(!(status & DESC_EOP) || !(status & DESC_SOP))) {
netif_err(priv, rx_status, ndev, "fragmented packet!\n");
ndev->stats.rx_dropped++;
ndev->stats.rx_errors++;
dev_kfree_skb_any(skb);
goto next;
}
if (unlikely(status & (RX_STATUS_ERR | RX_STATUS_OVFLOW))) {
netif_err(priv, rx_err, ndev, "error packet\n");
if (status & RX_STATUS_OVFLOW)
ndev->stats.rx_over_errors++;
ndev->stats.rx_dropped++;
ndev->stats.rx_errors++;
dev_kfree_skb_any(skb);
goto next;
}
skb_put(skb, len);
if (likely(status & DESC_L4_CSUM))
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb_pull(skb, sizeof(*rsb) + 2);
len -= (sizeof(*rsb) + 2);
if (priv->crc_fwd) {
skb_trim(skb, len - ETH_FCS_LEN);
len -= ETH_FCS_LEN;
}
skb->protocol = eth_type_trans(skb, ndev);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += len;
napi_gro_receive(&priv->napi, skb);
next:
processed++;
priv->rx_read_ptr++;
if (priv->rx_read_ptr == priv->num_rx_bds)
priv->rx_read_ptr = 0;
}
return processed;
}
static void bcm_sysport_tx_reclaim_one(struct bcm_sysport_priv *priv,
struct bcm_sysport_cb *cb,
unsigned int *bytes_compl,
unsigned int *pkts_compl)
{
struct device *kdev = &priv->pdev->dev;
struct net_device *ndev = priv->netdev;
if (cb->skb) {
ndev->stats.tx_bytes += cb->skb->len;
*bytes_compl += cb->skb->len;
dma_unmap_single(kdev, dma_unmap_addr(cb, dma_addr),
dma_unmap_len(cb, dma_len),
DMA_TO_DEVICE);
ndev->stats.tx_packets++;
(*pkts_compl)++;
bcm_sysport_free_cb(cb);
} else if (dma_unmap_addr(cb, dma_addr)) {
ndev->stats.tx_bytes += dma_unmap_len(cb, dma_len);
dma_unmap_page(kdev, dma_unmap_addr(cb, dma_addr),
dma_unmap_len(cb, dma_len), DMA_TO_DEVICE);
dma_unmap_addr_set(cb, dma_addr, 0);
}
}
static unsigned int __bcm_sysport_tx_reclaim(struct bcm_sysport_priv *priv,
struct bcm_sysport_tx_ring *ring)
{
struct net_device *ndev = priv->netdev;
unsigned int c_index, last_c_index, last_tx_cn, num_tx_cbs;
unsigned int pkts_compl = 0, bytes_compl = 0;
struct bcm_sysport_cb *cb;
struct netdev_queue *txq;
u32 hw_ind;
txq = netdev_get_tx_queue(ndev, ring->index);
hw_ind = tdma_readl(priv, TDMA_DESC_RING_PROD_CONS_INDEX(ring->index));
c_index = (hw_ind >> RING_CONS_INDEX_SHIFT) & RING_CONS_INDEX_MASK;
ring->p_index = (hw_ind & RING_PROD_INDEX_MASK);
last_c_index = ring->c_index;
num_tx_cbs = ring->size;
c_index &= (num_tx_cbs - 1);
if (c_index >= last_c_index)
last_tx_cn = c_index - last_c_index;
else
last_tx_cn = num_tx_cbs - last_c_index + c_index;
netif_dbg(priv, tx_done, ndev,
"ring=%d c_index=%d last_tx_cn=%d last_c_index=%d\n",
ring->index, c_index, last_tx_cn, last_c_index);
while (last_tx_cn-- > 0) {
cb = ring->cbs + last_c_index;
bcm_sysport_tx_reclaim_one(priv, cb, &bytes_compl, &pkts_compl);
ring->desc_count++;
last_c_index++;
last_c_index &= (num_tx_cbs - 1);
}
ring->c_index = c_index;
if (netif_tx_queue_stopped(txq) && pkts_compl)
netif_tx_wake_queue(txq);
netif_dbg(priv, tx_done, ndev,
"ring=%d c_index=%d pkts_compl=%d, bytes_compl=%d\n",
ring->index, ring->c_index, pkts_compl, bytes_compl);
return pkts_compl;
}
static unsigned int bcm_sysport_tx_reclaim(struct bcm_sysport_priv *priv,
struct bcm_sysport_tx_ring *ring)
{
unsigned int released;
unsigned long flags;
spin_lock_irqsave(&ring->lock, flags);
released = __bcm_sysport_tx_reclaim(priv, ring);
spin_unlock_irqrestore(&ring->lock, flags);
return released;
}
static int bcm_sysport_tx_poll(struct napi_struct *napi, int budget)
{
struct bcm_sysport_tx_ring *ring =
container_of(napi, struct bcm_sysport_tx_ring, napi);
unsigned int work_done = 0;
work_done = bcm_sysport_tx_reclaim(ring->priv, ring);
if (work_done == 0) {
napi_complete(napi);
intrl2_1_mask_clear(ring->priv, BIT(ring->index));
return 0;
}
return budget;
}
static void bcm_sysport_tx_reclaim_all(struct bcm_sysport_priv *priv)
{
unsigned int q;
for (q = 0; q < priv->netdev->num_tx_queues; q++)
bcm_sysport_tx_reclaim(priv, &priv->tx_rings[q]);
}
static int bcm_sysport_poll(struct napi_struct *napi, int budget)
{
struct bcm_sysport_priv *priv =
container_of(napi, struct bcm_sysport_priv, napi);
unsigned int work_done = 0;
work_done = bcm_sysport_desc_rx(priv, budget);
priv->rx_c_index += work_done;
priv->rx_c_index &= RDMA_CONS_INDEX_MASK;
rdma_writel(priv, priv->rx_c_index, RDMA_CONS_INDEX);
if (work_done < budget) {
napi_complete_done(napi, work_done);
intrl2_0_mask_clear(priv, INTRL2_0_RDMA_MBDONE);
}
return work_done;
}
static void bcm_sysport_resume_from_wol(struct bcm_sysport_priv *priv)
{
u32 reg;
intrl2_0_mask_set(priv, INTRL2_0_MPD);
reg = umac_readl(priv, UMAC_MPD_CTRL);
reg &= ~MPD_EN;
umac_writel(priv, reg, UMAC_MPD_CTRL);
netif_dbg(priv, wol, priv->netdev, "resumed from WOL\n");
}
static irqreturn_t bcm_sysport_rx_isr(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct bcm_sysport_priv *priv = netdev_priv(dev);
priv->irq0_stat = intrl2_0_readl(priv, INTRL2_CPU_STATUS) &
~intrl2_0_readl(priv, INTRL2_CPU_MASK_STATUS);
intrl2_0_writel(priv, priv->irq0_stat, INTRL2_CPU_CLEAR);
if (unlikely(priv->irq0_stat == 0)) {
netdev_warn(priv->netdev, "spurious RX interrupt\n");
return IRQ_NONE;
}
if (priv->irq0_stat & INTRL2_0_RDMA_MBDONE) {
if (likely(napi_schedule_prep(&priv->napi))) {
intrl2_0_mask_set(priv, INTRL2_0_RDMA_MBDONE);
__napi_schedule_irqoff(&priv->napi);
}
}
if (priv->irq0_stat & INTRL2_0_TX_RING_FULL)
bcm_sysport_tx_reclaim_all(priv);
if (priv->irq0_stat & INTRL2_0_MPD) {
netdev_info(priv->netdev, "Wake-on-LAN interrupt!\n");
bcm_sysport_resume_from_wol(priv);
}
return IRQ_HANDLED;
}
static irqreturn_t bcm_sysport_tx_isr(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct bcm_sysport_priv *priv = netdev_priv(dev);
struct bcm_sysport_tx_ring *txr;
unsigned int ring;
priv->irq1_stat = intrl2_1_readl(priv, INTRL2_CPU_STATUS) &
~intrl2_1_readl(priv, INTRL2_CPU_MASK_STATUS);
intrl2_1_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
if (unlikely(priv->irq1_stat == 0)) {
netdev_warn(priv->netdev, "spurious TX interrupt\n");
return IRQ_NONE;
}
for (ring = 0; ring < dev->num_tx_queues; ring++) {
if (!(priv->irq1_stat & BIT(ring)))
continue;
txr = &priv->tx_rings[ring];
if (likely(napi_schedule_prep(&txr->napi))) {
intrl2_1_mask_set(priv, BIT(ring));
__napi_schedule_irqoff(&txr->napi);
}
}
return IRQ_HANDLED;
}
static irqreturn_t bcm_sysport_wol_isr(int irq, void *dev_id)
{
struct bcm_sysport_priv *priv = dev_id;
pm_wakeup_event(&priv->pdev->dev, 0);
return IRQ_HANDLED;
}
static void bcm_sysport_poll_controller(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
disable_irq(priv->irq0);
bcm_sysport_rx_isr(priv->irq0, priv);
enable_irq(priv->irq0);
disable_irq(priv->irq1);
bcm_sysport_tx_isr(priv->irq1, priv);
enable_irq(priv->irq1);
}
static struct sk_buff *bcm_sysport_insert_tsb(struct sk_buff *skb,
struct net_device *dev)
{
struct sk_buff *nskb;
struct bcm_tsb *tsb;
u32 csum_info;
u8 ip_proto;
u16 csum_start;
u16 ip_ver;
if (unlikely(skb_headroom(skb) < sizeof(*tsb))) {
nskb = skb_realloc_headroom(skb, sizeof(*tsb));
dev_kfree_skb(skb);
if (!nskb) {
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
return NULL;
}
skb = nskb;
}
tsb = (struct bcm_tsb *)skb_push(skb, sizeof(*tsb));
memset(tsb, 0, sizeof(*tsb));
if (skb->ip_summed == CHECKSUM_PARTIAL) {
ip_ver = htons(skb->protocol);
switch (ip_ver) {
case ETH_P_IP:
ip_proto = ip_hdr(skb)->protocol;
break;
case ETH_P_IPV6:
ip_proto = ipv6_hdr(skb)->nexthdr;
break;
default:
return skb;
}
csum_start = skb_checksum_start_offset(skb) - sizeof(*tsb);
csum_info = (csum_start + skb->csum_offset) & L4_CSUM_PTR_MASK;
csum_info |= (csum_start << L4_PTR_SHIFT);
if (ip_proto == IPPROTO_TCP || ip_proto == IPPROTO_UDP) {
csum_info |= L4_LENGTH_VALID;
if (ip_proto == IPPROTO_UDP && ip_ver == ETH_P_IP)
csum_info |= L4_UDP;
} else {
csum_info = 0;
}
tsb->l4_ptr_dest_map = csum_info;
}
return skb;
}
static netdev_tx_t bcm_sysport_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
struct bcm_sysport_tx_ring *ring;
struct bcm_sysport_cb *cb;
struct netdev_queue *txq;
struct dma_desc *desc;
unsigned int skb_len;
unsigned long flags;
dma_addr_t mapping;
u32 len_status;
u16 queue;
int ret;
queue = skb_get_queue_mapping(skb);
txq = netdev_get_tx_queue(dev, queue);
ring = &priv->tx_rings[queue];
spin_lock_irqsave(&ring->lock, flags);
if (unlikely(ring->desc_count == 0)) {
netif_tx_stop_queue(txq);
netdev_err(dev, "queue %d awake and ring full!\n", queue);
ret = NETDEV_TX_BUSY;
goto out;
}
if (priv->tsb_en) {
skb = bcm_sysport_insert_tsb(skb, dev);
if (!skb) {
ret = NETDEV_TX_OK;
goto out;
}
}
if (skb_padto(skb, ETH_ZLEN + ENET_BRCM_TAG_LEN)) {
ret = NETDEV_TX_OK;
goto out;
}
skb_len = skb->len < ETH_ZLEN + ENET_BRCM_TAG_LEN ?
ETH_ZLEN + ENET_BRCM_TAG_LEN : skb->len;
mapping = dma_map_single(kdev, skb->data, skb_len, DMA_TO_DEVICE);
if (dma_mapping_error(kdev, mapping)) {
priv->mib.tx_dma_failed++;
netif_err(priv, tx_err, dev, "DMA map failed at %p (len=%d)\n",
skb->data, skb_len);
ret = NETDEV_TX_OK;
goto out;
}
cb = &ring->cbs[ring->curr_desc];
cb->skb = skb;
dma_unmap_addr_set(cb, dma_addr, mapping);
dma_unmap_len_set(cb, dma_len, skb_len);
desc = ring->desc_cpu;
desc->addr_lo = lower_32_bits(mapping);
len_status = upper_32_bits(mapping) & DESC_ADDR_HI_MASK;
len_status |= (skb_len << DESC_LEN_SHIFT);
len_status |= (DESC_SOP | DESC_EOP | TX_STATUS_APP_CRC) <<
DESC_STATUS_SHIFT;
if (skb->ip_summed == CHECKSUM_PARTIAL)
len_status |= (DESC_L4_CSUM << DESC_STATUS_SHIFT);
ring->curr_desc++;
if (ring->curr_desc == ring->size)
ring->curr_desc = 0;
ring->desc_count--;
wmb();
desc->addr_status_len = len_status;
wmb();
tdma_port_write_desc_addr(priv, desc, ring->index);
if (ring->desc_count == 0)
netif_tx_stop_queue(txq);
netif_dbg(priv, tx_queued, dev, "ring=%d desc_count=%d, curr_desc=%d\n",
ring->index, ring->desc_count, ring->curr_desc);
ret = NETDEV_TX_OK;
out:
spin_unlock_irqrestore(&ring->lock, flags);
return ret;
}
static void bcm_sysport_tx_timeout(struct net_device *dev)
{
netdev_warn(dev, "transmit timeout!\n");
netif_trans_update(dev);
dev->stats.tx_errors++;
netif_tx_wake_all_queues(dev);
}
static void bcm_sysport_adj_link(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
unsigned int changed = 0;
u32 cmd_bits = 0, reg;
if (priv->old_link != phydev->link) {
changed = 1;
priv->old_link = phydev->link;
}
if (priv->old_duplex != phydev->duplex) {
changed = 1;
priv->old_duplex = phydev->duplex;
}
switch (phydev->speed) {
case SPEED_2500:
cmd_bits = CMD_SPEED_2500;
break;
case SPEED_1000:
cmd_bits = CMD_SPEED_1000;
break;
case SPEED_100:
cmd_bits = CMD_SPEED_100;
break;
case SPEED_10:
cmd_bits = CMD_SPEED_10;
break;
default:
break;
}
cmd_bits <<= CMD_SPEED_SHIFT;
if (phydev->duplex == DUPLEX_HALF)
cmd_bits |= CMD_HD_EN;
if (priv->old_pause != phydev->pause) {
changed = 1;
priv->old_pause = phydev->pause;
}
if (!phydev->pause)
cmd_bits |= CMD_RX_PAUSE_IGNORE | CMD_TX_PAUSE_IGNORE;
if (!changed)
return;
if (phydev->link) {
reg = umac_readl(priv, UMAC_CMD);
reg &= ~((CMD_SPEED_MASK << CMD_SPEED_SHIFT) |
CMD_HD_EN | CMD_RX_PAUSE_IGNORE |
CMD_TX_PAUSE_IGNORE);
reg |= cmd_bits;
umac_writel(priv, reg, UMAC_CMD);
}
phy_print_status(priv->phydev);
}
static int bcm_sysport_init_tx_ring(struct bcm_sysport_priv *priv,
unsigned int index)
{
struct bcm_sysport_tx_ring *ring = &priv->tx_rings[index];
struct device *kdev = &priv->pdev->dev;
size_t size;
void *p;
u32 reg;
size = 256;
p = dma_zalloc_coherent(kdev, sizeof(struct dma_desc), &ring->desc_dma,
GFP_KERNEL);
if (!p) {
netif_err(priv, hw, priv->netdev, "DMA alloc failed\n");
return -ENOMEM;
}
ring->cbs = kcalloc(size, sizeof(struct bcm_sysport_cb), GFP_KERNEL);
if (!ring->cbs) {
netif_err(priv, hw, priv->netdev, "CB allocation failed\n");
return -ENOMEM;
}
spin_lock_init(&ring->lock);
ring->priv = priv;
netif_tx_napi_add(priv->netdev, &ring->napi, bcm_sysport_tx_poll, 64);
ring->index = index;
ring->size = size;
ring->alloc_size = ring->size;
ring->desc_cpu = p;
ring->desc_count = ring->size;
ring->curr_desc = 0;
tdma_writel(priv, RING_EN, TDMA_DESC_RING_HEAD_TAIL_PTR(index));
tdma_writel(priv, 0, TDMA_DESC_RING_COUNT(index));
tdma_writel(priv, 1, TDMA_DESC_RING_INTR_CONTROL(index));
tdma_writel(priv, 0, TDMA_DESC_RING_PROD_CONS_INDEX(index));
tdma_writel(priv, RING_IGNORE_STATUS, TDMA_DESC_RING_MAPPING(index));
tdma_writel(priv, 0, TDMA_DESC_RING_PCP_DEI_VID(index));
tdma_writel(priv, ring->size |
1 << RING_HYST_THRESH_SHIFT,
TDMA_DESC_RING_MAX_HYST(index));
reg = tdma_readl(priv, TDMA_TIER1_ARB_0_QUEUE_EN);
reg |= (1 << index);
tdma_writel(priv, reg, TDMA_TIER1_ARB_0_QUEUE_EN);
napi_enable(&ring->napi);
netif_dbg(priv, hw, priv->netdev,
"TDMA cfg, size=%d, desc_cpu=%p\n",
ring->size, ring->desc_cpu);
return 0;
}
static void bcm_sysport_fini_tx_ring(struct bcm_sysport_priv *priv,
unsigned int index)
{
struct bcm_sysport_tx_ring *ring = &priv->tx_rings[index];
struct device *kdev = &priv->pdev->dev;
u32 reg;
reg = tdma_readl(priv, TDMA_STATUS);
if (!(reg & TDMA_DISABLED))
netdev_warn(priv->netdev, "TDMA not stopped!\n");
if (!ring->cbs)
return;
napi_disable(&ring->napi);
netif_napi_del(&ring->napi);
bcm_sysport_tx_reclaim(priv, ring);
kfree(ring->cbs);
ring->cbs = NULL;
if (ring->desc_dma) {
dma_free_coherent(kdev, sizeof(struct dma_desc),
ring->desc_cpu, ring->desc_dma);
ring->desc_dma = 0;
}
ring->size = 0;
ring->alloc_size = 0;
netif_dbg(priv, hw, priv->netdev, "TDMA fini done\n");
}
static inline int rdma_enable_set(struct bcm_sysport_priv *priv,
unsigned int enable)
{
unsigned int timeout = 1000;
u32 reg;
reg = rdma_readl(priv, RDMA_CONTROL);
if (enable)
reg |= RDMA_EN;
else
reg &= ~RDMA_EN;
rdma_writel(priv, reg, RDMA_CONTROL);
do {
reg = rdma_readl(priv, RDMA_STATUS);
if (!!(reg & RDMA_DISABLED) == !enable)
return 0;
usleep_range(1000, 2000);
} while (timeout-- > 0);
netdev_err(priv->netdev, "timeout waiting for RDMA to finish\n");
return -ETIMEDOUT;
}
static inline int tdma_enable_set(struct bcm_sysport_priv *priv,
unsigned int enable)
{
unsigned int timeout = 1000;
u32 reg;
reg = tdma_readl(priv, TDMA_CONTROL);
if (enable)
reg |= TDMA_EN;
else
reg &= ~TDMA_EN;
tdma_writel(priv, reg, TDMA_CONTROL);
do {
reg = tdma_readl(priv, TDMA_STATUS);
if (!!(reg & TDMA_DISABLED) == !enable)
return 0;
usleep_range(1000, 2000);
} while (timeout-- > 0);
netdev_err(priv->netdev, "timeout waiting for TDMA to finish\n");
return -ETIMEDOUT;
}
static int bcm_sysport_init_rx_ring(struct bcm_sysport_priv *priv)
{
struct bcm_sysport_cb *cb;
u32 reg;
int ret;
int i;
priv->num_rx_bds = NUM_RX_DESC;
priv->rx_bds = priv->base + SYS_PORT_RDMA_OFFSET;
priv->rx_c_index = 0;
priv->rx_read_ptr = 0;
priv->rx_cbs = kcalloc(priv->num_rx_bds, sizeof(struct bcm_sysport_cb),
GFP_KERNEL);
if (!priv->rx_cbs) {
netif_err(priv, hw, priv->netdev, "CB allocation failed\n");
return -ENOMEM;
}
for (i = 0; i < priv->num_rx_bds; i++) {
cb = priv->rx_cbs + i;
cb->bd_addr = priv->rx_bds + i * DESC_SIZE;
}
ret = bcm_sysport_alloc_rx_bufs(priv);
if (ret) {
netif_err(priv, hw, priv->netdev, "SKB allocation failed\n");
return ret;
}
reg = rdma_readl(priv, RDMA_STATUS);
if (!(reg & RDMA_DISABLED))
rdma_enable_set(priv, 0);
rdma_writel(priv, 0, RDMA_WRITE_PTR_LO);
rdma_writel(priv, 0, RDMA_WRITE_PTR_HI);
rdma_writel(priv, 0, RDMA_PROD_INDEX);
rdma_writel(priv, 0, RDMA_CONS_INDEX);
rdma_writel(priv, priv->num_rx_bds << RDMA_RING_SIZE_SHIFT |
RX_BUF_LENGTH, RDMA_RING_BUF_SIZE);
rdma_writel(priv, 0, RDMA_START_ADDR_HI);
rdma_writel(priv, 0, RDMA_START_ADDR_LO);
rdma_writel(priv, 0, RDMA_END_ADDR_HI);
rdma_writel(priv, NUM_HW_RX_DESC_WORDS - 1, RDMA_END_ADDR_LO);
rdma_writel(priv, 1, RDMA_MBDONE_INTR);
netif_dbg(priv, hw, priv->netdev,
"RDMA cfg, num_rx_bds=%d, rx_bds=%p\n",
priv->num_rx_bds, priv->rx_bds);
return 0;
}
static void bcm_sysport_fini_rx_ring(struct bcm_sysport_priv *priv)
{
struct bcm_sysport_cb *cb;
unsigned int i;
u32 reg;
reg = rdma_readl(priv, RDMA_STATUS);
if (!(reg & RDMA_DISABLED))
netdev_warn(priv->netdev, "RDMA not stopped!\n");
for (i = 0; i < priv->num_rx_bds; i++) {
cb = &priv->rx_cbs[i];
if (dma_unmap_addr(cb, dma_addr))
dma_unmap_single(&priv->pdev->dev,
dma_unmap_addr(cb, dma_addr),
RX_BUF_LENGTH, DMA_FROM_DEVICE);
bcm_sysport_free_cb(cb);
}
kfree(priv->rx_cbs);
priv->rx_cbs = NULL;
netif_dbg(priv, hw, priv->netdev, "RDMA fini done\n");
}
static void bcm_sysport_set_rx_mode(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
u32 reg;
reg = umac_readl(priv, UMAC_CMD);
if (dev->flags & IFF_PROMISC)
reg |= CMD_PROMISC;
else
reg &= ~CMD_PROMISC;
umac_writel(priv, reg, UMAC_CMD);
if (dev->flags & IFF_ALLMULTI)
return;
}
static inline void umac_enable_set(struct bcm_sysport_priv *priv,
u32 mask, unsigned int enable)
{
u32 reg;
reg = umac_readl(priv, UMAC_CMD);
if (enable)
reg |= mask;
else
reg &= ~mask;
umac_writel(priv, reg, UMAC_CMD);
if (enable == 0)
usleep_range(1000, 2000);
}
static inline void umac_reset(struct bcm_sysport_priv *priv)
{
u32 reg;
reg = umac_readl(priv, UMAC_CMD);
reg |= CMD_SW_RESET;
umac_writel(priv, reg, UMAC_CMD);
udelay(10);
reg = umac_readl(priv, UMAC_CMD);
reg &= ~CMD_SW_RESET;
umac_writel(priv, reg, UMAC_CMD);
}
static void umac_set_hw_addr(struct bcm_sysport_priv *priv,
unsigned char *addr)
{
umac_writel(priv, (addr[0] << 24) | (addr[1] << 16) |
(addr[2] << 8) | addr[3], UMAC_MAC0);
umac_writel(priv, (addr[4] << 8) | addr[5], UMAC_MAC1);
}
static void topctrl_flush(struct bcm_sysport_priv *priv)
{
topctrl_writel(priv, RX_FLUSH, RX_FLUSH_CNTL);
topctrl_writel(priv, TX_FLUSH, TX_FLUSH_CNTL);
mdelay(1);
topctrl_writel(priv, 0, RX_FLUSH_CNTL);
topctrl_writel(priv, 0, TX_FLUSH_CNTL);
}
static int bcm_sysport_change_mac(struct net_device *dev, void *p)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EINVAL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
if (!netif_running(dev))
return 0;
umac_set_hw_addr(priv, dev->dev_addr);
return 0;
}
static void bcm_sysport_netif_start(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
napi_enable(&priv->napi);
intrl2_0_mask_clear(priv, INTRL2_0_RDMA_MBDONE | INTRL2_0_TX_RING_FULL);
phy_start(priv->phydev);
intrl2_1_mask_clear(priv, 0xffffffff);
netif_tx_start_all_queues(dev);
}
static void rbuf_init(struct bcm_sysport_priv *priv)
{
u32 reg;
reg = rbuf_readl(priv, RBUF_CONTROL);
reg |= RBUF_4B_ALGN | RBUF_RSB_EN;
rbuf_writel(priv, reg, RBUF_CONTROL);
}
static int bcm_sysport_open(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
unsigned int i;
int ret;
umac_reset(priv);
topctrl_flush(priv);
umac_enable_set(priv, CMD_RX_EN | CMD_TX_EN, 0);
rbuf_init(priv);
umac_writel(priv, UMAC_MAX_MTU_SIZE, UMAC_MAX_FRAME_LEN);
umac_set_hw_addr(priv, dev->dev_addr);
priv->crc_fwd = !!(umac_readl(priv, UMAC_CMD) & CMD_CRC_FWD);
priv->phydev = of_phy_connect(dev, priv->phy_dn, bcm_sysport_adj_link,
0, priv->phy_interface);
if (!priv->phydev) {
netdev_err(dev, "could not attach to PHY\n");
return -ENODEV;
}
priv->old_duplex = -1;
priv->old_link = -1;
priv->old_pause = -1;
intrl2_0_writel(priv, 0xffffffff, INTRL2_CPU_MASK_SET);
intrl2_0_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
intrl2_0_writel(priv, 0, INTRL2_CPU_MASK_CLEAR);
intrl2_1_writel(priv, 0xffffffff, INTRL2_CPU_MASK_SET);
intrl2_1_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
intrl2_1_writel(priv, 0, INTRL2_CPU_MASK_CLEAR);
ret = request_irq(priv->irq0, bcm_sysport_rx_isr, 0, dev->name, dev);
if (ret) {
netdev_err(dev, "failed to request RX interrupt\n");
goto out_phy_disconnect;
}
ret = request_irq(priv->irq1, bcm_sysport_tx_isr, 0, dev->name, dev);
if (ret) {
netdev_err(dev, "failed to request TX interrupt\n");
goto out_free_irq0;
}
for (i = 0; i < dev->num_tx_queues; i++) {
ret = bcm_sysport_init_tx_ring(priv, i);
if (ret) {
netdev_err(dev, "failed to initialize TX ring %d\n",
i);
goto out_free_tx_ring;
}
}
tdma_writel(priv, TDMA_LL_RAM_INIT_BUSY, TDMA_STATUS);
ret = bcm_sysport_init_rx_ring(priv);
if (ret) {
netdev_err(dev, "failed to initialize RX ring\n");
goto out_free_rx_ring;
}
ret = rdma_enable_set(priv, 1);
if (ret)
goto out_free_rx_ring;
ret = tdma_enable_set(priv, 1);
if (ret)
goto out_clear_rx_int;
umac_enable_set(priv, CMD_RX_EN | CMD_TX_EN, 1);
bcm_sysport_netif_start(dev);
return 0;
out_clear_rx_int:
intrl2_0_mask_set(priv, INTRL2_0_RDMA_MBDONE | INTRL2_0_TX_RING_FULL);
out_free_rx_ring:
bcm_sysport_fini_rx_ring(priv);
out_free_tx_ring:
for (i = 0; i < dev->num_tx_queues; i++)
bcm_sysport_fini_tx_ring(priv, i);
free_irq(priv->irq1, dev);
out_free_irq0:
free_irq(priv->irq0, dev);
out_phy_disconnect:
phy_disconnect(priv->phydev);
return ret;
}
static void bcm_sysport_netif_stop(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
netif_tx_stop_all_queues(dev);
napi_disable(&priv->napi);
phy_stop(priv->phydev);
intrl2_0_mask_set(priv, 0xffffffff);
intrl2_0_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
intrl2_1_mask_set(priv, 0xffffffff);
intrl2_1_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
}
static int bcm_sysport_stop(struct net_device *dev)
{
struct bcm_sysport_priv *priv = netdev_priv(dev);
unsigned int i;
int ret;
bcm_sysport_netif_stop(dev);
umac_enable_set(priv, CMD_RX_EN, 0);
ret = tdma_enable_set(priv, 0);
if (ret) {
netdev_err(dev, "timeout disabling RDMA\n");
return ret;
}
usleep_range(2000, 3000);
ret = rdma_enable_set(priv, 0);
if (ret) {
netdev_err(dev, "timeout disabling TDMA\n");
return ret;
}
umac_enable_set(priv, CMD_TX_EN, 0);
for (i = 0; i < dev->num_tx_queues; i++)
bcm_sysport_fini_tx_ring(priv, i);
bcm_sysport_fini_rx_ring(priv);
free_irq(priv->irq0, dev);
free_irq(priv->irq1, dev);
phy_disconnect(priv->phydev);
return 0;
}
static int bcm_sysport_probe(struct platform_device *pdev)
{
struct bcm_sysport_priv *priv;
struct device_node *dn;
struct net_device *dev;
const void *macaddr;
struct resource *r;
u32 txq, rxq;
int ret;
dn = pdev->dev.of_node;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (of_property_read_u32(dn, "systemport,num-txq", &txq))
txq = TDMA_NUM_RINGS;
if (of_property_read_u32(dn, "systemport,num-rxq", &rxq))
rxq = 1;
dev = alloc_etherdev_mqs(sizeof(*priv), txq, rxq);
if (!dev)
return -ENOMEM;
priv = netdev_priv(dev);
priv->irq0 = platform_get_irq(pdev, 0);
priv->irq1 = platform_get_irq(pdev, 1);
priv->wol_irq = platform_get_irq(pdev, 2);
if (priv->irq0 <= 0 || priv->irq1 <= 0) {
dev_err(&pdev->dev, "invalid interrupts\n");
ret = -EINVAL;
goto err;
}
priv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto err;
}
priv->netdev = dev;
priv->pdev = pdev;
priv->phy_interface = of_get_phy_mode(dn);
if (priv->phy_interface < 0)
priv->phy_interface = PHY_INTERFACE_MODE_GMII;
if (of_phy_is_fixed_link(dn)) {
ret = of_phy_register_fixed_link(dn);
if (ret) {
dev_err(&pdev->dev, "failed to register fixed PHY\n");
goto err;
}
priv->phy_dn = dn;
}
macaddr = of_get_mac_address(dn);
if (!macaddr || !is_valid_ether_addr(macaddr)) {
dev_warn(&pdev->dev, "using random Ethernet MAC\n");
eth_hw_addr_random(dev);
} else {
ether_addr_copy(dev->dev_addr, macaddr);
}
SET_NETDEV_DEV(dev, &pdev->dev);
dev_set_drvdata(&pdev->dev, dev);
dev->ethtool_ops = &bcm_sysport_ethtool_ops;
dev->netdev_ops = &bcm_sysport_netdev_ops;
netif_napi_add(dev, &priv->napi, bcm_sysport_poll, 64);
dev->hw_features |= NETIF_F_RXCSUM | NETIF_F_HIGHDMA |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
priv->wol_irq_disabled = 1;
ret = devm_request_irq(&pdev->dev, priv->wol_irq,
bcm_sysport_wol_isr, 0, dev->name, priv);
if (!ret)
device_set_wakeup_capable(&pdev->dev, 1);
BUILD_BUG_ON(sizeof(struct bcm_tsb) != 8);
dev->needed_headroom += sizeof(struct bcm_tsb);
netif_carrier_off(dev);
ret = register_netdev(dev);
if (ret) {
dev_err(&pdev->dev, "failed to register net_device\n");
goto err;
}
priv->rev = topctrl_readl(priv, REV_CNTL) & REV_MASK;
dev_info(&pdev->dev,
"Broadcom SYSTEMPORT" REV_FMT
" at 0x%p (irqs: %d, %d, TXQs: %d, RXQs: %d)\n",
(priv->rev >> 8) & 0xff, priv->rev & 0xff,
priv->base, priv->irq0, priv->irq1, txq, rxq);
return 0;
err:
free_netdev(dev);
return ret;
}
static int bcm_sysport_remove(struct platform_device *pdev)
{
struct net_device *dev = dev_get_drvdata(&pdev->dev);
unregister_netdev(dev);
free_netdev(dev);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
static int bcm_sysport_suspend_to_wol(struct bcm_sysport_priv *priv)
{
struct net_device *ndev = priv->netdev;
unsigned int timeout = 1000;
u32 reg;
reg = umac_readl(priv, UMAC_MPD_CTRL);
reg |= MPD_EN;
reg &= ~PSW_EN;
if (priv->wolopts & WAKE_MAGICSECURE)
reg |= PSW_EN;
umac_writel(priv, reg, UMAC_MPD_CTRL);
do {
reg = rbuf_readl(priv, RBUF_STATUS);
if (reg & RBUF_WOL_MODE)
break;
udelay(10);
} while (timeout-- > 0);
if (!timeout) {
reg = umac_readl(priv, UMAC_MPD_CTRL);
reg &= ~MPD_EN;
umac_writel(priv, reg, UMAC_MPD_CTRL);
netif_err(priv, wol, ndev, "failed to enter WOL mode\n");
return -ETIMEDOUT;
}
umac_enable_set(priv, CMD_RX_EN, 1);
intrl2_0_mask_clear(priv, INTRL2_0_MPD);
netif_dbg(priv, wol, ndev, "entered WOL mode\n");
return 0;
}
static int bcm_sysport_suspend(struct device *d)
{
struct net_device *dev = dev_get_drvdata(d);
struct bcm_sysport_priv *priv = netdev_priv(dev);
unsigned int i;
int ret = 0;
u32 reg;
if (!netif_running(dev))
return 0;
bcm_sysport_netif_stop(dev);
phy_suspend(priv->phydev);
netif_device_detach(dev);
umac_enable_set(priv, CMD_RX_EN, 0);
ret = rdma_enable_set(priv, 0);
if (ret) {
netdev_err(dev, "RDMA timeout!\n");
return ret;
}
if (priv->rx_chk_en) {
reg = rxchk_readl(priv, RXCHK_CONTROL);
reg &= ~RXCHK_EN;
rxchk_writel(priv, reg, RXCHK_CONTROL);
}
if (!priv->wolopts)
topctrl_writel(priv, RX_FLUSH, RX_FLUSH_CNTL);
ret = tdma_enable_set(priv, 0);
if (ret) {
netdev_err(dev, "TDMA timeout!\n");
return ret;
}
usleep_range(2000, 3000);
umac_enable_set(priv, CMD_TX_EN, 0);
topctrl_writel(priv, TX_FLUSH, TX_FLUSH_CNTL);
for (i = 0; i < dev->num_tx_queues; i++)
bcm_sysport_fini_tx_ring(priv, i);
bcm_sysport_fini_rx_ring(priv);
if (device_may_wakeup(d) && priv->wolopts)
ret = bcm_sysport_suspend_to_wol(priv);
return ret;
}
static int bcm_sysport_resume(struct device *d)
{
struct net_device *dev = dev_get_drvdata(d);
struct bcm_sysport_priv *priv = netdev_priv(dev);
unsigned int i;
u32 reg;
int ret;
if (!netif_running(dev))
return 0;
umac_reset(priv);
bcm_sysport_resume_from_wol(priv);
for (i = 0; i < dev->num_tx_queues; i++) {
ret = bcm_sysport_init_tx_ring(priv, i);
if (ret) {
netdev_err(dev, "failed to initialize TX ring %d\n",
i);
goto out_free_tx_rings;
}
}
tdma_writel(priv, TDMA_LL_RAM_INIT_BUSY, TDMA_STATUS);
ret = bcm_sysport_init_rx_ring(priv);
if (ret) {
netdev_err(dev, "failed to initialize RX ring\n");
goto out_free_rx_ring;
}
netif_device_attach(dev);
topctrl_writel(priv, 0, RX_FLUSH_CNTL);
ret = rdma_enable_set(priv, 1);
if (ret) {
netdev_err(dev, "failed to enable RDMA\n");
goto out_free_rx_ring;
}
if (priv->rx_chk_en) {
reg = rxchk_readl(priv, RXCHK_CONTROL);
reg |= RXCHK_EN;
rxchk_writel(priv, reg, RXCHK_CONTROL);
}
rbuf_init(priv);
umac_writel(priv, UMAC_MAX_MTU_SIZE, UMAC_MAX_FRAME_LEN);
umac_set_hw_addr(priv, dev->dev_addr);
umac_enable_set(priv, CMD_RX_EN, 1);
topctrl_writel(priv, 0, TX_FLUSH_CNTL);
umac_enable_set(priv, CMD_TX_EN, 1);
ret = tdma_enable_set(priv, 1);
if (ret) {
netdev_err(dev, "TDMA timeout!\n");
goto out_free_rx_ring;
}
phy_resume(priv->phydev);
bcm_sysport_netif_start(dev);
return 0;
out_free_rx_ring:
bcm_sysport_fini_rx_ring(priv);
out_free_tx_rings:
for (i = 0; i < dev->num_tx_queues; i++)
bcm_sysport_fini_tx_ring(priv, i);
return ret;
}
